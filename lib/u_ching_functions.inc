<?php // functions.inc
/* FUNCTIONS IN THIS FILE

ucd_date_mysql_to_kin ($mysql_date, $dcode_bcad)
ucd_date_is_leapday
ucd_date_mysql_to_short
ucd_truncate
ucd_date_mysql_to_very_short
ucd_kin_to_next_gb
ucd_count_days
ucd_is_leapyear - advanced method for checking leap year
ucd_date_moon_array - creates array of moon illumination of any day/time
ucd_castle_num_to_name($castle_number)
ucd_get_wp_posts($this_mysql_date) // an awesome little func that gets the posts on a given date

ucd_tone_num_to_name_ ($tone_num) // In DIFF LANGS
ucd_earth_fam_num_to_name_ ($ucd_earth_family) // IN DIFF LANGS

*/


// Here's the main decoder
function ucd_date_mysql_to_kin($mysql_date, $dcode_bcad){

	error_reporting(0);

	$mysql_date_pcs = explode('-',$mysql_date);
	$birth_yr = $mysql_date_pcs[0];
	$birth_mo = $mysql_date_pcs[1];
	$birth_day = $mysql_date_pcs[2];

	if (($birth_yr <> "")&&($birth_mo <> "")&&($birth_day <> "")){

		if ((preg_match("/^[0-9]{1,2}/", $birth_mo))&&($birth_mo < 13)) {
		    $input_good .= "Your birth month is PROPERLY formatted.<br>";
		} else {
			$input_error .= "Your birth month is NOT formatted properly.<br>";
		}
	
		if ((preg_match("/^[0-9]{1,2}/", $birth_day))&&($birth_day < 32)) {
		    $input_good .= "Your birth day is PROPERLY formatted.<br>";
		} else {
			$input_error .= "Your birth day is NOT formatted properly.<br>";
		}
	
		if (isset($input_error)){
			$yr_mo_day_code = "Error: $input_error";
	
		} else {
	
//	 		echo "You Entered the dates: $birth_mo/$birth_day/$birth_yr<p>$input_good <BR> $input_error";
	
			if (($birth_yr - 2013) % 52 == 0){$yr_code = 217;}
			elseif (($birth_yr - 2012) % 52 == 0){$yr_code = 112;}
			elseif (($birth_yr - 2011) % 52 == 0){$yr_code = 7;}
			elseif (($birth_yr - 2010) % 52 == 0){$yr_code = 162;}
			elseif (($birth_yr - 2009) % 52 == 0){$yr_code = 57;}
			elseif (($birth_yr - 2008) % 52 == 0){$yr_code = 212;}
			elseif (($birth_yr - 2007) % 52 == 0){$yr_code = 107;}
			elseif (($birth_yr - 2006) % 52 == 0){$yr_code = 2;}
			elseif (($birth_yr - 2005) % 52 == 0){$yr_code = 157;}
			elseif (($birth_yr - 2004) % 52 == 0){$yr_code = 52;}
			elseif (($birth_yr - 2003) % 52 == 0){$yr_code = 207;}
			elseif (($birth_yr - 2002) % 52 == 0){$yr_code = 102;}
			elseif (($birth_yr - 2001) % 52 == 0){$yr_code = 257;}
			elseif (($birth_yr - 2000) % 52 == 0){$yr_code = 152;}
			elseif (($birth_yr - 1999) % 52 == 0){$yr_code = 47;}
			elseif (($birth_yr - 1998) % 52 == 0){$yr_code = 202;}
			elseif (($birth_yr - 1997) % 52 == 0){$yr_code = 97;}
			elseif (($birth_yr - 1996) % 52 == 0){$yr_code = 252;}
			elseif (($birth_yr - 1995) % 52 == 0){$yr_code = 147;}
			elseif (($birth_yr - 1994) % 52 == 0){$yr_code = 42;}
			elseif (($birth_yr - 1993) % 52 == 0){$yr_code = 197;}
			elseif (($birth_yr - 1992) % 52 == 0){$yr_code = 92;}
			elseif (($birth_yr - 1991) % 52 == 0){$yr_code = 247;}
			elseif (($birth_yr - 1990) % 52 == 0){$yr_code = 142;}
			elseif (($birth_yr - 1989) % 52 == 0){$yr_code = 37;}
			elseif (($birth_yr - 1988) % 52 == 0){$yr_code = 192;}
			elseif (($birth_yr - 1987) % 52 == 0){$yr_code = 87;}
			elseif (($birth_yr - 1986) % 52 == 0){$yr_code = 242;}
			elseif (($birth_yr - 1985) % 52 == 0){$yr_code = 137;}
			elseif (($birth_yr - 1984) % 52 == 0){$yr_code = 32;}
			elseif (($birth_yr - 1983) % 52 == 0){$yr_code = 187;}
			elseif (($birth_yr - 1982) % 52 == 0){$yr_code = 82;}
			elseif (($birth_yr - 1981) % 52 == 0){$yr_code = 237;}
			elseif (($birth_yr - 1980) % 52 == 0){$yr_code = 132;}
			elseif (($birth_yr - 1979) % 52 == 0){$yr_code = 27;}
			elseif (($birth_yr - 1978) % 52 == 0){$yr_code = 182;}
			elseif (($birth_yr - 1977) % 52 == 0){$yr_code = 77;}
			elseif (($birth_yr - 1976) % 52 == 0){$yr_code = 232;}
			elseif (($birth_yr - 1975) % 52 == 0){$yr_code = 127;}
			elseif (($birth_yr - 1974) % 52 == 0){$yr_code = 22;}
			elseif (($birth_yr - 1973) % 52 == 0){$yr_code = 177;}
			elseif (($birth_yr - 1972) % 52 == 0){$yr_code = 72;}
			elseif (($birth_yr - 1971) % 52 == 0){$yr_code = 227;}
			elseif (($birth_yr - 1970) % 52 == 0){$yr_code = 122;}
			elseif (($birth_yr - 1969) % 52 == 0){$yr_code = 17;}
			elseif (($birth_yr - 1968) % 52 == 0){$yr_code = 172;}
			elseif (($birth_yr - 1967) % 52 == 0){$yr_code = 67;}
			elseif (($birth_yr - 1966) % 52 == 0){$yr_code = 222;}
			elseif (($birth_yr - 1965) % 52 == 0){$yr_code = 117;}
			elseif (($birth_yr - 1964) % 52 == 0){$yr_code = 12;}
			elseif (($birth_yr - 1963) % 52 == 0){$yr_code = 167;}
			elseif (($birth_yr - 1962) % 52 == 0){$yr_code = 62;}
			
			if (($birth_mo === "01")||($birth_mo === "1")){$mo_code = 0;}
			if (($birth_mo === "02")||($birth_mo === "2")){$mo_code = 31;}
			if (($birth_mo === "03")||($birth_mo === "3")){$mo_code = 59;}
			if (($birth_mo === "04")||($birth_mo === "4")){$mo_code = 90;}
			if (($birth_mo === "05")||($birth_mo === "5")){$mo_code = 120;}
			if (($birth_mo === "06")||($birth_mo === "6")){$mo_code = 151;}
			if (($birth_mo === "07")||($birth_mo === "7")){$mo_code = 181;}
			if (($birth_mo === "08")||($birth_mo === "8")){$mo_code = 212;}
			if (($birth_mo === "09")||($birth_mo === "9")){$mo_code = 243;}
			if (($birth_mo === "10")||($birth_mo === "10")){$mo_code = 13;}
			if (($birth_mo === "11")||($birth_mo === "11")){$mo_code = 44;}
			if (($birth_mo === "12")||($birth_mo === "12")){$mo_code = 74;}
			
		// Equation to figure kin is: (yr_code + mo_code + birth_day) (if over 260, subtract 260)
			$yr_mo_day_code = ($yr_code + $mo_code + $birth_day);
			if ($yr_mo_day_code > 260){$yr_mo_day_code = ($yr_mo_day_code - 260); $exc_260 = "- 260";}
			if ($yr_mo_day_code > 260){$yr_mo_day_code = ($yr_mo_day_code - 260);}
	
		} // END if no input error
	} // END if input


// Finally, we check to see if it's leap day -- NOT DAY OUT OF TIME but GAD or 0.0.hunab ku

	if (ucd_date_is_leapday($mysql_date)){
		// Adjust back one kin for Leap Day
			$yr_mo_day_code = ($yr_mo_day_code - 1); if ($yr_mo_day_code < 1){$yr_mo_day_code = ($yr_mo_day_code + 260);}
	}

	$kin_ID = $yr_mo_day_code;
	return $kin_ID;
} // END of function ucd_date_mysql_to_kin


// Check to see if this date is a Leap Day
function ucd_date_is_leapday($mysql_date){
// Find out if the day is a leap day
	$msdate_pcs = explode("-", $mysql_date);
	$answer = adodb_date('L', strtotime("$msdate_pcs[0]-1-1"));
	if($answer){
		if ((($msdate_pcs[1] === "02")||($msdate_pcs[1] === "2"))&&($msdate_pcs[2] === "29")){
			if (ucd_is_leapyear($msdate_pcs[0])){
				$leap_day = "TRUE";
			}
		}
	}
	return $leap_day;
}



// Date MySQL to SHORT DATE
function ucd_date_mysql_to_short($mysql_date){
	$mysql_date_pcs = explode('-',$mysql_date);
	$year = $mysql_date_pcs[0];
	$month = $mysql_date_pcs[1];
	$day = $mysql_date_pcs[2];

	switch ($month){
		case "01":  $month = "1"; break;
		case "02":  $month = "2"; break;
		case "03":  $month = "3"; break;
		case "04":  $month = "4"; break;
		case "05":  $month = "5"; break;
		case "06":  $month = "6"; break;
		case "07":  $month = "7"; break;
		case "08":  $month = "8"; break;
		case "09":  $month = "9"; break;
		case "10":  $month = "10"; break;
		case "11":  $month = "11"; break;
		case "12":  $month = "12"; break;
    }

	switch ($day){
		case "01":  $day = "1"; break;
		case "02":  $day = "2"; break;
		case "03":  $day = "3"; break;
		case "04":  $day = "4"; break;
		case "05":  $day = "5"; break;
		case "06":  $day = "6"; break;
		case "07":  $day = "7"; break;
		case "08":  $day = "8"; break;
		case "09":  $day = "9"; break;
    }

	$date_full = "$month/$day/$year";
	return $date_full;
}


// Date MySQL to SHORT DATE
function ucd_date_mysql_to_very_short($mysql_date){
	$mysql_date_pcs = explode('-',$mysql_date);
	$year = $mysql_date_pcs[0];
	$month = $mysql_date_pcs[1];
	$day = $mysql_date_pcs[2];

	switch ($month){
		case "01":  $month = "1"; break;
		case "02":  $month = "2"; break;
		case "03":  $month = "3"; break;
		case "04":  $month = "4"; break;
		case "05":  $month = "5"; break;
		case "06":  $month = "6"; break;
		case "07":  $month = "7"; break;
		case "08":  $month = "8"; break;
		case "09":  $month = "9"; break;
		case "10":  $month = "10"; break;
		case "11":  $month = "11"; break;
		case "12":  $month = "12"; break;
    }

	switch ($day){
		case "01":  $day = "1"; break;
		case "02":  $day = "2"; break;
		case "03":  $day = "3"; break;
		case "04":  $day = "4"; break;
		case "05":  $day = "5"; break;
		case "06":  $day = "6"; break;
		case "07":  $day = "7"; break;
		case "08":  $day = "8"; break;
		case "09":  $day = "9"; break;
    }

	$year = substr("$year", -2);    // turns 2010 to 10

	$date_full = "$month/$day/$year";
	return $date_full;
}

// ucd_truncate long names
function ucd_truncate($string, $max, $replacement){
    if (strlen($string) <= $max)
    {
        return $string;
    }
    $leave = $max - strlen ($replacement);
    return substr_replace($string, $replacement, $leave);
}


// The REVERSE DECODER:
function ucd_kin_to_next_gb($start_kin_id){

	// Get kin for today
	$today_mysql_date = adodb_date("Y-n-j"); // For decoding
	$today_kin = ucd_date_mysql_to_kin($today_mysql_date, AD);

	// Now that we have today's kin, we can do some math
	$days_to_gb = ($start_kin_id - $today_kin);
	if ($days_to_gb > 260){$days_to_gb = $days_to_gb - 260;}
	if ($days_to_gb < 1){$days_to_gb = $days_to_gb + 260;}

	// Convert this date to array
	$today_date_array = explode("-", $today_mysql_date);
	$dcode_yr  = 	$today_date_array[0];
	$dcode_mo  = 	$today_date_array[1];
	$dcode_day = 	$today_date_array[2];
	
	// Determine the date of the next GB
	$next_gb_date_mysql = adodb_date('Y-n-j',adodb_mktime(0, 0, 0, $dcode_mo, $dcode_day+$days_to_gb, $dcode_yr));

	// Return array
	return array($next_gb_date_mysql, $days_to_gb);
}

/*  Not every year that is divisible by 4 is a leap year. There are other conditions. Here's the complete list:

   1. Every year that is evenly divisible by four is a leap year;
   2. of those years, if it can be evenly divided by 100, it is NOT a leap year, unless
   3. the year is evenly divisible by 400. Then it is a leap year.
*/

function ucd_is_leapyear($year) {
	if ( ($year%4) != 0 )
	{     return false;     }
	
	if ( ($year%100)==0 )
	{
	     if ( ($year%400) == 0 )
	     {     return true;     }
	     else
	     {     return false;    }
	}
	else
	{     return true;     }
}







// This is a WP custom function to get the posts on a given date
function ucd_get_wp_posts($this_mysql_date){
// Break up date for functions
	$this_mysql_date_pieces = explode("-", $this_mysql_date);

     $this_wp_year = $this_mysql_date_pieces[0];
     $this_wp_mon = $this_mysql_date_pieces[1];
     $this_wp_day = $this_mysql_date_pieces[2];

// Prepare the date string to query the db
     if (strlen($this_wp_mon) === 1){$this_wp_mon = "0".$this_wp_mon;}
     if (strlen($this_wp_day) === 1){$this_wp_day = "0".$this_wp_day;}

	$new_wp_mysql_date_today = "$this_wp_year-$this_wp_mon-$this_wp_day";

// We're going to access the database, so we need to globaliza $wpdb
	global $wpdb;

// Query the databazse using WordPress to get a list of posts on this date

// This works
     $thisday_posts_array = $wpdb->get_results("
     SELECT ID, post_title, post_date, guid 
     FROM $wpdb->posts 
     WHERE post_status = 'publish' 
     AND post_type='post' 
     AND (post_date BETWEEN '$new_wp_mysql_date_today 00:00:00' AND '$new_wp_mysql_date_today 23:59:59')
     ORDER BY post_date DESC LIMIT 0,10
     ");

// Try a join to get the name of the poster

/*
     $thisday_posts_array = $wpdb->get_results("
	SELECT post_author, display_name, ID, post_title, post_date, guid 
     FROM $wpdb->posts 
	LEFT JOIN $wpdb->users ON $wpdb->posts.post_author = $wpdb->users.ID 
     WHERE post_status = 'publish' 
     AND post_type='post' 
     AND (post_date BETWEEN '$new_wp_mysql_date_today 00:00:00' AND '$new_wp_mysql_date_today 23:59:59')
     ORDER BY post_date DESC LIMIT 0,10
     ");
*/
	return $thisday_posts_array;
// return $thisday_posts_array;
}

// Tone NAME to Tone Number
function ucd_tone_num_to_name_en($tone_num){
	switch ($tone_num){
		case 1:  $tone_name = "Magnetic";		break;
		case 2:  $tone_name = "Lunar";  		break;
		case 3:  $tone_name = "Electric";  	break;
		case 4:  $tone_name = "Self-Existing";	break;
		case 5:  $tone_name = "Overtone";  	break;
		case 6:  $tone_name = "Rhythmic";		break;
		case 7:  $tone_name = "Resonant";		break;
		case 8:  $tone_name = "Galactic";		break;
		case 9:  $tone_name = "Solar";		break;
		case 10: $tone_name = "Planetary";		break;
		case 11: $tone_name = "Spectral";		break;
		case 12: $tone_name = "Crystal";		break;
		case 13: $tone_name = "Cosmic";		break;
    }
	return $tone_name;
}


// Tone NAME to Tone Number
function ucd_tone_num_to_name_es($tone_num){
	switch ($tone_num){
        case 1:  $tone_name = "Magnética";		break;
        case 2:  $tone_name = "Lunar";			break;
        case 3:  $tone_name = "Eléctrica";		break;
        case 4:  $tone_name = "Auto-Existente";	break;
        case 5:  $tone_name = "Entonada";   		break;
        case 6:  $tone_name = "Rítmica";    		break;
        case 7:  $tone_name = "Resonante";        break;
        case 8:  $tone_name = "Galáctica";        break;
        case 9:  $tone_name = "Solar";   	     break;
        case 10: $tone_name = "Planetaria";		break;
        case 11: $tone_name = "Espectral";		break;
        case 12: $tone_name = "Cristal";		break;
        case 13: $tone_name = "Cósmica";		break;

    }
	return $tone_name;
}

// Tone NAME to Tone Number
function ucd_tone_num_to_name_nl($tone_num){
	switch ($tone_num){
        case 1:  $tone_name = "Magnetische";		break;
        case 2:  $tone_name = "Lunaire";          break;
        case 3:  $tone_name = "Elektrische";      break;
        case 4:  $tone_name = "Zelf-Bestaande";	break;
        case 5:  $tone_name = "Boventoon";		break;
        case 6:  $tone_name = "Ritmische";		break;
        case 7:  $tone_name = "Resonante";		break;
        case 8:  $tone_name = "Galactische";		break;
        case 9:  $tone_name = "Solaire";		break;
        case 10: $tone_name = "Planetaire";		break;
        case 11: $tone_name = "Spectrale";		break;
        case 12: $tone_name = "Kristallen";		break;
        case 13: $tone_name = "Kosmische";		break;
    }
	return $tone_name;
}

// Earth Family Name - EN
function ucd_earth_fam_num_to_name_en($ucd_earth_family){
	switch ($ucd_earth_family){
        case 1:  $num_suffix = "st"; $earth_fam_name = "Cardinal Family";		break;
        case 2:  $num_suffix = "nd"; $earth_fam_name = "Core Family";		break;
        case 3:  $num_suffix = "rd"; $earth_fam_name = "Signal Family";		break;
        case 4:  $num_suffix = "th"; $earth_fam_name = "Gateway Family";		break;
        case 5:  $num_suffix = "th"; $earth_fam_name = "Polar Family";		break;
    }
	return array($earth_fam_name, $num_suffix);
}

// Earth Family Name - NL
function ucd_earth_fam_num_to_name_nl($ucd_earth_family){
	switch ($ucd_earth_family){
        case 1:  $num_suffix = "e"; $earth_fam_name = "Kardinaal Familie";	break;
        case 2:  $num_suffix = "e"; $earth_fam_name = "Kern Familie";		break;
        case 3:  $num_suffix = "e"; $earth_fam_name = "Signaal Familie";		break;
        case 4:  $num_suffix = "e"; $earth_fam_name = "Poort Familie";		break;
        case 5:  $num_suffix = "e"; $earth_fam_name = "Polair Familie";		break;
    }
	return array($earth_fam_name, $num_suffix);
}

// Earth Family Name - ES
function ucd_earth_fam_num_to_name_es($ucd_earth_family){
	switch ($ucd_earth_family){
        case 1:  $num_suffix = "a"; $earth_fam_name = "Familia Cardinal";		break;
        case 2:  $num_suffix = "o"; $earth_fam_name = "Familia Núcleo";		break;
        case 3:  $num_suffix = "o"; $earth_fam_name = "Familia Señal";		break;
        case 4:  $num_suffix = "o"; $earth_fam_name = "Familia Entrada";		break;
        case 5:  $num_suffix = "o"; $earth_fam_name = "Familia Polar";		break;
    }
	return array($earth_fam_name, $num_suffix);

	// Return array
//	return array($next_gb_date_mysql, $days_to_gb);
}

?>