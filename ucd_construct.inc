<?php // This is the main output file

function start_uching() {
// Engage Output Buffer 
	ob_start();

// THe otherwise hard-coded words are nationalized using an internal method  // Include static text translation file
     include(dirname(__FILE__).'/lib/ucd_trans_static.inc');

// Using ADOdb Date Time Library -- and only calling once in case the decoder is on the page twice
     if (function_exists('adodb_date_test_date')){} else {include(dirname(__FILE__).'/lib/adodb-time.inc.php');}
// Get Functions
     if (function_exists('ucd_date_mysql_to_kin')){} else {include(dirname(__FILE__).'/lib/u_ching_functions.inc');}
// Do Date Calculations, get the Chapter and all the data from the delimited data file
     include(dirname(__FILE__).'/lib/u_ching_date_calc.inc');
// Set defaults
	$decode_table_background_color = "#".get_option('decode_table_background_color');
	if ($decode_table_background_color == "#"){$decode_table_background_color = "#eee";}
	$permit_credits = get_option('permit_credits');
	if (empty($permit_credits)){$permit_credits = "NO";} // oops! -- forgot to correct this -- default to NO ADS on install!
// Do we have any posts on this day? // returns an array: $thisday_posts_array
     $thisday_posts_array = ucd_get_wp_posts($this_mysql_date);
// Set max number of posts to show per day
	$show_num_posts = get_option('show_num_posts');
	if ($show_num_posts == ""){$show_num_posts = 5;}
	$this_day_posts_num = count($thisday_posts_array);
// Loop through posts
     if ($this_day_posts_num > 0) {
      	$post_list .= "<div class=\"post_list\">Posts (".count($thisday_posts_array).")";
		$countr = 0;
          foreach ($thisday_posts_array as $thisday_post_item){
			if ($countr >= $show_num_posts){
				break;
			}
          	$this_id[] 		= $thisday_post_item->ID;
          	$this_title 		= $thisday_post_item->post_title;
          	$this_date 		= $thisday_post_item->post_date;
          	$this_url 		= $thisday_post_item->guid;
			$post_list .= "<br><a href=\"$this_url\">$this_title</a></br>";
			$countr++;
          }
		$post_list .= "</div>";
	} // FINISHED looping through posts

// --------------- Start Wrapper for CONTENT ---------------------------- //
?>
     <div class="content_wrapper" id="ucd_content_wrapper">

<!-- --------------- TAB TITLES -------------- -->
         <ul id="tabs">
           <li><a href="#tabone"><?php echo $tr_txt_hexagram; ?></a></li>
           <li><a href="#tabtwo"><?php echo $tr_txt_decode; ?></a></li>
           <li><a href="#tabthree"><i class="china_chars_tab">&#26131;</i></a></li>
<?php
          if ($this_day_posts_num > 0){
     		echo "<li><a href=\"#tabfour\">($this_day_posts_num)</a></li>\n";
     	} 
?>
	    </ul>
<!-- --------- BEGIN: TAB CONTENTS ---------- -->
	<div class="tabContent" id="tabone">

<?php 
// Tab 1 - Front Tab on Entering
	include(dirname(__FILE__).'/lib/ucd_hexagrams.inc');
	echo "$uching_content_one\n";
?>
	</div>

    <div class="tabContent" id="tabtwo">

<?php
// Tab 2 -  Form to De-Code a DATE
     echo "<form method=\"GET\" action=\"\" id=\"u_ching_plug_form\">\n";
     echo "<table id=decode_table ";
	echo " style=\"background-color: $decode_table_background_color; border: 0; padding: 0 0 0 0; margin-top: 13px;\">\n";
	echo "<tr>";
	include(dirname(__FILE__).'/lib/u_ching_decode_date_form.inc');
	echo "</tr>\n";
	echo "</table>\n";
	echo "</form>";

// Tab 2 -  Form to De-Code a KIN
     echo "<form method=\"GET\" action=\"\" id=\"u_ching_plug_form\">\n";
     echo "<table id=decode_table ";
	echo " style=\"background-color: $decode_table_background_color; border: 0; padding: 0 0 0 0; margin-top: 13px;\">\n";
	echo "<tr>";
	include(dirname(__FILE__).'/lib/u_ching_decode_kin_form.inc');
	echo "</tr>\n";
	echo "</table>\n";
	echo "</form>";

// Tab 2 -  Form to De-Code a CHAPTER
     echo "<form method=\"GET\" action=\"\" id=\"u_ching_plug_form\">\n";
     echo "<table id=decode_table ";
	echo " style=\"background-color: $decode_table_background_color; border: 0; padding: 0 0 0 0; margin-top: 13px;\">\n";
	echo "<tr>";
	include(dirname(__FILE__).'/lib/u_ching_decode_chapter_form.inc');
	echo "</tr>\n";
	echo "</table>\n";
	echo "</form>";

?>
      <div><p><?php echo $uching_content_two; ?></p></div>
    </div>

<!-- Tab 3 -  Chinese Content -->
    <div class="tabContent" id="tabthree">
      <h2><?php echo "$tr_txt_iching_ch $ucd_i_ching_chapter"; ?></h2>

<?php
	echo $uching_content_three;
?>

    </div>

<!-- Tab 4 -  Posts if any -->
<?php
     if ($this_day_posts_num > 0){
     	echo "<div class=\"tabContent\" id=\"tabfour\">\n";
     	echo "<h2>This day posts</h2>\n";
     	echo "$post_list\n";
	echo "</div>\n";
	}


     if ($permit_credits === "YES"){
     	echo "<div class=ucd_ads id=\"credits_id\">";
     	echo "<a target=\"_BLANK\" href=\"http://lawoftime.org/\" title=\"Foundation for the Law of Time\">FLT</a>";
     	echo " ";
     	echo "<a target=\"_BLANK\" href=\"http://spacestationplaza.com/\" title=\"Space Station Plaza\">SSP</a>";
     	echo " ";
     	echo "<a target=\"_BLANK\" href=\"http://www.u-ching.com/\" title=\"uChing Network\">uCHING</a>";
     	echo "</div>";
     }

// End main containers - ucd_content_wrapper
	echo "</div>";

// Clear all 
	echo "<div style=clear:both;></div>";

// --  END Tabbed Content -- //

// ASSIGN Output
	$uching_content = "<div class=\"entire_ucd_div\" id=\"uching_div_wrapper\" style=\"display:none;\">".ob_get_contents()."</div>";


// End Output Buffer
	$some_ucd_valuefornull = ob_end_clean();
// RETURN OUTPUT ======================================
	return $uching_content;
} // END function: start_uching() -- this entire script

?>