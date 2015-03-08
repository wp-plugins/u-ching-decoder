<?php // u_ching_date_calc.inc

// TRANSLATE by finding out the current user's language selection, and choosing the correct file

// What language are you using?
$ucd_locale = get_locale();

// Setlocale
if ($ucd_locale == "es_ES"){setlocale(LC_ALL, 'es_ES');}
elseif ($ucd_locale == "nl_NL"){setlocale(LC_ALL, 'nl_NL');}
else {$ucd_locale = "en_EN"; setlocale(LC_ALL, 'en_EN');}

// To avoid database query, we simply load the output of the u-ching table into an array
if ($ucd_locale != ""){
// Check to see if the language file exists
	$filename = dirname(__FILE__) . "/u_ching_lookup_".$ucd_locale.".txt";
    	if (file_exists($filename)) {
     $lines = file($filename); // read into array $lines[]
//  	$uching_buffer .= "The file $filename exists<hr>";
} else {
// Open the English Version
     $lines = file(dirname(__FILE__).'/u_ching_lookup_en_EN.txt'); // read into array $lines[]
//  	$uching_buffer .= "The file $filename does not exist<hr>";
	}
}


// Start working with the date //  KIN and CHAPTER LOOKUPS

// Is this a post?
$this_pg_type_post = get_post_type(get_the_ID());
	
	
// Get requested day
if (isset($_GET['dcode_day'])){
	$dcode_yr = $_GET['dcode_yr'];
	$dcode_mo = $_GET['dcode_mo'];
	$dcode_day = $_GET['dcode_day'];
}


elseif (($this_pg_type_post == "post")||($this_pg_type_post == "event")){
		$this_post_date = get_the_date("Y-n-j");
		$this_post_date_pcs = explode("-", $this_post_date);
		$dcode_yr  = $this_post_date_pcs[0]; // Y	A full numeric representation of a year, 4 digits
		$dcode_mo  = $this_post_date_pcs[1];  // n	Numeric representation of a month, with NO leading zeros
		$dcode_day = $this_post_date_pcs[2];  // j	Day of the month, 2 digits with leading NO zeros
}

// Requests for $dcode_kin
elseif (isset($_GET['dcode_kin'])){

	$start_kin_id = $_GET['dcode_kin'];
	$next_date_array = ucd_kin_to_next_gb($start_kin_id); // 	return array($next_gb_date_mysql, $days_to_gb);
	$this_new_date = $next_date_array[0];

     $this_date_pcs = explode('-',$this_new_date);

	$dcode_yr = $this_date_pcs[0];
	$dcode_mo = $this_date_pcs[1];
	$dcode_day = $this_date_pcs[2];

// Correct the gets
	$_GET['dcode_yr'] = $dcode_yr;
	$_GET['dcode_mo'] = $dcode_mo;
	$_GET['dcode_day'] = $dcode_day;
}      


// Requests for $dcode_chapter ================================================================
elseif (isset($_GET['dcode_chapter'])){
    
	$find_chapter = $_GET['dcode_chapter'];
	$inc = 0;
	foreach ($lines as $uching_line){
		$uching_line_array[$inc] = explode("|", $uching_line);
     
		$this_line_chapter = $uching_line_array[$inc][0];
		if ($find_chapter == $this_line_chapter){
     
			// Put the second field in an array 
			$kin_opt_pieces = explode(",", $uching_line_array[$inc][1]);
     
			// Get today's kin?
     				
			$today_dcode_yr = date('Y');
			$today_dcode_mo = date('m');
			$today_dcode_day = date('d');
     
			$today_mysql_date = "$today_dcode_yr-$today_dcode_mo-$today_dcode_day";
     
     		// Get the kin number for the day
    			$this_day_kin_num = ucd_date_mysql_to_kin($today_mysql_date, "AD");
     
    			// Only four kin to choose from:
    			$kin_op_one 	= $kin_opt_pieces[0];
    			$kin_op_two 	= $kin_opt_pieces[1];
    			$kin_op_three 	= $kin_opt_pieces[2];
    			$kin_op_four 	= $kin_opt_pieces[3];
     
    			if ($kin_op_one > $this_day_kin_num){
    				$this_found_kin = $kin_op_one;
    			} elseif ($kin_op_two > $this_day_kin_num){
    				$this_found_kin = $kin_op_two;
    			} elseif ($kin_op_three > $this_day_kin_num){
    				$this_found_kin = $kin_op_three;
    			} elseif ($kin_op_two > $this_day_kin_num){
    				$this_found_kin = $kin_op_four;
    			} else {
    				$this_found_kin = $kin_op_one;
    			}
    
			break;
         	}
		$inc ++;
	}

// Assign the kin we're looking up
	$start_kin_id = $this_found_kin;

    	$next_date_array = ucd_kin_to_next_gb($start_kin_id); // 	return array($next_gb_date_mysql, $days_to_gb);
    	$this_new_date = $next_date_array[0];
    
	$this_date_pcs = explode('-',$this_new_date);
     
	$dcode_yr = $this_date_pcs[0];
     $dcode_mo = $this_date_pcs[1];
     $dcode_day = $this_date_pcs[2];
     
     // Correct the gets
     $_GET['dcode_yr'] = $dcode_yr;
     $_GET['dcode_mo'] = $dcode_mo;
     $_GET['dcode_day'] = $dcode_day;
}

 else {
// Get today's date
	$dcode_yr = date('Y'); // Y	A full numeric representation of a year, 4 digits
	$dcode_mo = date('m'); // m	Numeric representation of a month, with leading zeros
	$dcode_day = date('d'); // d	Day of the month, 2 digits with leading zeros
}

// Format for MySQL, store in scalar and array
$this_mysql_date = $dcode_yr."-".$dcode_mo."-".$dcode_day;
$this_date_pcs = explode('-',$this_mysql_date);

// Assign to AD
$dcode_bcad = "AD";

// Adjust the dates if an impossible date was requested
if (($dcode_mo == 2)  && ($dcode_day > 28)) {$dcode_day = 1;$dcode_mo = 3;}
if (($dcode_mo == 4)  && ($dcode_day > 30)) {$dcode_day = 1;$dcode_mo = 5;}
if (($dcode_mo == 6)  && ($dcode_day > 30)) {$dcode_day = 1;$dcode_mo = 7;}
if (($dcode_mo == 9)  && ($dcode_day > 30)) {$dcode_day = 1;$dcode_mo = 10;}
if (($dcode_mo == 11) && ($dcode_day > 30)) {$dcode_day = 1;$dcode_mo = 12;}

// Day Out of Time, we set a flag
if (($dcode_mo == 7) && ($dcode_day == 25)) {$day_out_of_time_flag = "YES";}
// Leap Day, we set a flag
if (($dcode_mo == 2) && ($dcode_day == 29)) {$leap_day_flag = "YES";}


// Get the kin number for the day
$this_day_kin_num = ucd_date_mysql_to_kin($this_mysql_date, "AD");
// Change some calculations if it is LEAP YEAR, AND ON OR AFTER 2-28
if ($this_day_kin_num > 260){$this_day_kin_num = $this_day_kin_num - 260;} // Do it once
if ($this_day_kin_num > 260){$this_day_kin_num = $this_day_kin_num - 260;} // Do it again

// Get Greg date 
// Use adodb for a special timestamp
// adodb_mktime($hr, $min, $sec[, $month, $day, $year])
	$this_date_adodb_timestamp = adodb_mktime(0, 0, 0, $this_date_pcs[1], $this_date_pcs[2], $this_date_pcs[0]);
	//** FUNCTION adodb_mktime($hr, $min, $sec[, $month, $day, $year])
	$this_nice_date = adodb_date("D M j, Y", $this_date_adodb_timestamp);


// Translate the dates within a range // Uses locale() above
     if (($this_date_pcs[0] >= 1902)&&($this_date_pcs[0] <= 2037)){
     	$this_nice_translated_date = utf8_encode(strftime("%e %B %Y", strtotime("$dcode_mo/$dcode_day/$dcode_yr")));
	} else {
		$this_nice_translated_date = $this_nice_date;
	}



// Find the Chapter
// Read the data file into an array
$inc = 0;
foreach ($lines as $uching_line){
	$uching_line_array[$inc] = explode("|", $uching_line);
// Put the second field in an array
	$kin_opt_pieces = explode(",", $uching_line_array[$inc][1]);
// Test if kin is in new array
	if (in_array($this_day_kin_num, $kin_opt_pieces)) {
	    $found_chapter = $inc;
		break;
	}
    	$inc ++;
}

// CREATE next and last day for links 

$prior_day = ($this_date_pcs[2] - 1);
$next_day = ($this_date_pcs[2] + 1);

// PRIOR // Use adodb for a special timestamp // adodb_mktime($hr, $min, $sec[, $month, $day, $year])
$this_date_adodb_timestamp = adodb_mktime(0, 0, 0, $this_date_pcs[1], $prior_day, $this_date_pcs[0]);
$prior_day_mo = adodb_date("n", $this_date_adodb_timestamp);
$prior_day_day = adodb_date("j", $this_date_adodb_timestamp);
$prior_day_yr = adodb_date("Y", $this_date_adodb_timestamp);

// NEXT // Use adodb for a special timestamp // adodb_mktime($hr, $min, $sec[, $month, $day, $year])
$this_date_adodb_timestamp = adodb_mktime(0, 0, 0, $this_date_pcs[1], $next_day, $this_date_pcs[0]);
$next_day_mo = adodb_date("n", $this_date_adodb_timestamp);
$next_day_day = adodb_date("j", $this_date_adodb_timestamp);
$next_day_yr = adodb_date("Y", $this_date_adodb_timestamp);

// Make Links
$prior_day_link = "<a href=\"?dcode_day=$prior_day_day&dcode_mo=$prior_day_mo&dcode_yr=$prior_day_yr\" title=\"Prior Day: $prior_day_day $prior_day_mo $prior_day_yr\">&lt;</a>";
$next_day_link = "<a href=\"?dcode_day=$next_day_day&dcode_mo=$next_day_mo&dcode_yr=$next_day_yr\" title=\"Next Day: $next_day_day $next_day_mo $next_day_yr\">&gt;</a>";


// Instead of using the database, we're using an array made from the file lookup.txt

$ucd_chapter				= utf8_encode($uching_line_array[$found_chapter][0]);
$ucd_kin_del				= utf8_encode($uching_line_array[$found_chapter][1]);
$ucd_inverse_number			= utf8_encode($uching_line_array[$found_chapter][2]);
$ucd_complementary_number		= utf8_encode($uching_line_array[$found_chapter][3]);
$ucd_fu_xi_number			= utf8_encode($uching_line_array[$found_chapter][4]);
$ucd_i_ching_chapter			= utf8_encode($uching_line_array[$found_chapter][5]);
$ucd_chinese_name_1			= utf8_encode($uching_line_array[$found_chapter][6]);
$ucd_chinese_name_2			= utf8_encode($uching_line_array[$found_chapter][7]);
$ucd_lunar_ring_days			= utf8_encode($uching_line_array[$found_chapter][8]);
$ucd_bmu_number				= utf8_encode($uching_line_array[$found_chapter][9]);
$ucd_wavespell_in_season		= utf8_encode($uching_line_array[$found_chapter][10]);
$ucd_earth_family			= utf8_encode($uching_line_array[$found_chapter][11]);
$ucd_galactic_tone			= utf8_encode($uching_line_array[$found_chapter][12]);
$ucd_group_number			= utf8_encode($uching_line_array[$found_chapter][13]);
$ucd_core_number			= utf8_encode($uching_line_array[$found_chapter][14]);
$ucd_codon_code				= utf8_encode($uching_line_array[$found_chapter][15]);
$ucd_amino_acid				= utf8_encode($uching_line_array[$found_chapter][16]);
$ucd_outer_triplet			= utf8_encode($uching_line_array[$found_chapter][17]);
$ucd_inner_triplet			= utf8_encode($uching_line_array[$found_chapter][18]);
$ucd_rune_title				= utf8_encode($uching_line_array[$found_chapter][19]);
$ucd_rune_subtitle			= utf8_encode($uching_line_array[$found_chapter][20]);
$ucd_u_ching_title			= utf8_encode($uching_line_array[$found_chapter][21]);
$ucd_u_ching_subtitle			= utf8_encode($uching_line_array[$found_chapter][22]);
$ucd_i_ching_title			= utf8_encode($uching_line_array[$found_chapter][23]);
$ucd_i_ching_title_wilhelm		= utf8_encode($uching_line_array[$found_chapter][24]);
$ucd_modern_interpretation		= utf8_encode($uching_line_array[$found_chapter][25]);
$ucd_chinese_characters			= utf8_encode($uching_line_array[$found_chapter][26]);
$ucd_hexagram_binary_del		= utf8_encode($uching_line_array[$found_chapter][27]);


?>