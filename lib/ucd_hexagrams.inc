<?php  // ucd_hexagrams.inc

// Assign blank values
$uching_content_one = "";
$uching_content_two = "";
$uching_content_three = "";
$uching_content_four = "";
$hexagram_pkg = "";

// Directory paths for images
$rune_img_dir = plugins_url().'/u-ching-decoder/images/runes';
$hex_img_dir = plugins_url().'/u-ching-decoder/images/hexagrams';
$full_hex_img_dir = plugins_url().'/u-ching-decoder/images/hexagram_full';
$lunar_ring_squares_dir = plugins_url().'/u-ching-decoder/images/lunar_ring_squares';
$kin_earth_fam_dir = plugins_url().'/u-ching-decoder/images/kin_earth_fam';

// Add a zero to the chapter for the image filename and assign to rune_img_nm
if ($found_chapter < 10){$rune_img_nm = "0".$found_chapter.".png";} else {$rune_img_nm = $found_chapter.".png";}
if ($found_chapter < 10){$hex_full_img_nm = "0".$found_chapter.".png";} else {$hex_full_img_nm = $found_chapter.".png";}
if ($found_chapter < 10){$lunar_ring_img_nm = "0".$found_chapter.".png";} else {$lunar_ring_img_nm = $found_chapter.".png";}
if ($found_chapter < 10){$kin_earth_fam_img_nm = "0".$found_chapter.".png";} else {$kin_earth_fam_img_nm = $found_chapter.".png";}

// Put dot's between letters of $ucd_codon_code
$ucd_codon_code = $ucd_codon_code[0].".".$ucd_codon_code[1].".".$ucd_codon_code[2];

// Split the ucd_hexagram_binary_del and get the binary nums
$bin_array = str_split($ucd_hexagram_binary_del);
$bin_row_6 = $bin_array[0];
$bin_row_5 = $bin_array[1];
$bin_row_4 = $bin_array[2];
$bin_row_3 = $bin_array[3];
$bin_row_2 = $bin_array[4];
$bin_row_1 = $bin_array[5];

// Get the inverse
if ($bin_row_6 == 0){$bin_inv_row_6 = 1;} else {$bin_inv_row_6 = 0;} 
if ($bin_row_5 == 0){$bin_inv_row_5 = 1;} else {$bin_inv_row_5 = 0;} 
if ($bin_row_4 == 0){$bin_inv_row_4 = 1;} else {$bin_inv_row_4 = 0;} 
if ($bin_row_3 == 0){$bin_inv_row_3 = 1;} else {$bin_inv_row_3 = 0;} 
if ($bin_row_2 == 0){$bin_inv_row_2 = 1;} else {$bin_inv_row_2 = 0;} 
if ($bin_row_1 == 0){$bin_inv_row_1 = 1;} else {$bin_inv_row_1 = 0;} 
// Find the black and blank spaces
if ($bin_row_1 == 1){$hex_clear_1 = " clear";} else {$hex_clear_1 = " black";}
if ($bin_row_2 == 1){$hex_clear_2 = " clear";} else {$hex_clear_2 = " black";}
if ($bin_row_3 == 1){$hex_clear_3 = " clear";} else {$hex_clear_3 = " black";}
if ($bin_row_4 == 1){$hex_clear_4 = " clear";} else {$hex_clear_4 = " black";}
if ($bin_row_5 == 1){$hex_clear_5 = " clear";} else {$hex_clear_5 = " black";}
if ($bin_row_6 == 1){$hex_clear_6 = " clear";} else {$hex_clear_6 = " black";}
// Get values for numeric
if ($bin_row_1 == 1) {$val_r1_c3 = 1;} else {$val_r1_c1 = 1;} 
if ($bin_row_2 == 1) {$val_r2_c3 = 2;} else {$val_r2_c1 = 2;} 
if ($bin_row_3 == 1) {$val_r3_c3 = 4;} else {$val_r3_c1 = 4;} 
if ($bin_row_4 == 1) {$val_r4_c3 = 8;} else {$val_r4_c1 = 8;} 
if ($bin_row_5 == 1) {$val_r5_c3 = 16;} else {$val_r5_c1 = 16;} 
if ($bin_row_6 == 1) {$val_r6_c3 = 32;} else {$val_r6_c1 = 32;} 
// Get inverse values for numeric
if ($bin_row_1 == 1) {$val_r1_c9 = 32;} else {$val_r1_c11 = 32;} 
if ($bin_row_2 == 1) {$val_r2_c9 = 16;} else {$val_r2_c11 = 16;} 
if ($bin_row_3 == 1) {$val_r3_c9 = 8;} else {$val_r3_c11 = 8;} 
if ($bin_row_4 == 1) {$val_r4_c9 = 4;} else {$val_r4_c11 = 4;} 
if ($bin_row_5 == 1) {$val_r5_c9 = 2;} else {$val_r5_c11 = 2;} 
if ($bin_row_6 == 1) {$val_r6_c9 = 1;} else {$val_r6_c11 = 1;} 


// Start a table for this Hexagram with 9 columns
$hexagram_pkg .= "<table id=\"the_hexagram_table\" class=\"hex_table_new\">\n";
$hexagram_pkg .= "<tbody>\n";

// Row 1
$hexagram_pkg .= "<tr>\n";
$hexagram_pkg .= "<td class=\"ucd_num\"><i class=\"u-norm\">$val_r1_c1</i></td>\n";
$hexagram_pkg .= "<td class=\"ucd_num\"><i class=\"u-bold\">$val_r1_c3</i></td>\n";
$hexagram_pkg .= "<td class=\"ucd_num\"><i class=\"u-norm\">$bin_row_1</i></td>\n";
$hexagram_pkg .= "<td class=\"new_hex_image\"><img img src=\"$hex_img_dir/$bin_row_1.png\" class=\"the_hex_img\"></td>\n";
$hexagram_pkg .= "<td class=\"ucd_num\"><i class=\"u-norm\">$bin_row_1</i></td>\n";
$hexagram_pkg .= "<td class=\"ucd_num\"><i class=\"u-bold\">$val_r1_c9</i></td>\n";
$hexagram_pkg .= "<td class=\"ucd_num\"><i class=\"u-norm\">$val_r1_c11</i></td>\n";
$hexagram_pkg .= "</tr>\n";

// Row 2
$hexagram_pkg .= "<tr>\n";
$hexagram_pkg .= "<td class=\"ucd_num\"><i class=\"u-norm\">$val_r2_c1</i></td>\n";
$hexagram_pkg .= "<td class=\"ucd_num\"><i class=\"u-bold\">$val_r2_c3</i></td>\n";
$hexagram_pkg .= "<td class=\"ucd_num\"><i class=\"u-norm\">$bin_row_2</i></td>\n";
$hexagram_pkg .= "<td class=\"new_hex_image\"><img img src=\"$hex_img_dir/$bin_row_2.png\" class=\"the_hex_img\"></td>\n";
$hexagram_pkg .= "<td class=\"ucd_num\"><i class=\"u-norm\">$bin_row_2</i></td>\n";
$hexagram_pkg .= "<td class=\"ucd_num\"><i class=\"u-bold\">$val_r2_c9</i></td>\n";
$hexagram_pkg .= "<td class=\"ucd_num\"><i class=\"u-norm\">$val_r2_c11</i></td>\n";
$hexagram_pkg .= "</tr>\n";

// Row 3
$hexagram_pkg .= "<tr>\n";
$hexagram_pkg .= "<td class=\"ucd_num\"><i class=\"u-norm\">$val_r3_c1</i></td>\n";
$hexagram_pkg .= "<td class=\"ucd_num\"><i class=\"u-bold\">$val_r3_c3</i></td>\n";
$hexagram_pkg .= "<td class=\"ucd_num\"><i class=\"u-norm\">$bin_row_3</i></td>\n";
$hexagram_pkg .= "<td class=\"new_hex_image\"><img img src=\"$hex_img_dir/$bin_row_3.png\" class=\"the_hex_img\"></td>\n";
$hexagram_pkg .= "<td class=\"ucd_num\"><i class=\"u-norm\">$bin_row_3</i></td>\n";
$hexagram_pkg .= "<td class=\"ucd_num\"><i class=\"u-bold\">$val_r3_c9</i></td>\n";
$hexagram_pkg .= "<td class=\"ucd_num\"><i class=\"u-norm\">$val_r3_c11</i></td>\n";
$hexagram_pkg .= "</tr>\n";

// Row 4
$hexagram_pkg .= "<tr>\n";
$hexagram_pkg .= "<td class=\"ucd_num\"><i class=\"u-norm\">$val_r4_c1</i></td>\n";
$hexagram_pkg .= "<td class=\"ucd_num\"><i class=\"u-bold\">$val_r4_c3</i></td>\n";
$hexagram_pkg .= "<td class=\"ucd_num\"><i class=\"u-norm\">$bin_row_4</i></td>\n";
$hexagram_pkg .= "<td class=\"new_hex_image\"><img img src=\"$hex_img_dir/$bin_row_4.png\" class=\"the_hex_img\"></td>\n";
$hexagram_pkg .= "<td class=\"ucd_num\"><i class=\"u-norm\">$bin_row_4</i></td>\n";
$hexagram_pkg .= "<td class=\"ucd_num\"><i class=\"u-bold\">$val_r4_c9</i></td>\n";
$hexagram_pkg .= "<td class=\"ucd_num\"><i class=\"u-norm\">$val_r4_c11</i></td>\n";
$hexagram_pkg .= "</tr>\n";

// Row 5
$hexagram_pkg .= "<tr>\n";
$hexagram_pkg .= "<td class=\"ucd_num\"><i class=\"u-norm\">$val_r5_c1</i></td>\n";
$hexagram_pkg .= "<td class=\"ucd_num\"><i class=\"u-bold\">$val_r5_c3</i></td>\n";
$hexagram_pkg .= "<td class=\"ucd_num\"><i class=\"u-norm\">$bin_row_5</i></td>\n";
$hexagram_pkg .= "<td class=\"new_hex_image\"><img img src=\"$hex_img_dir/$bin_row_5.png\" class=\"the_hex_img\"></td>\n";
$hexagram_pkg .= "<td class=\"ucd_num\"><i class=\"u-norm\">$bin_row_5</i></td>\n";
$hexagram_pkg .= "<td class=\"ucd_num\"><i class=\"u-bold\">$val_r5_c9</i></td>\n";
$hexagram_pkg .= "<td class=\"ucd_num\"><i class=\"u-norm\">$val_r5_c11</i></td>\n";
$hexagram_pkg .= "</tr>\n";

// Row 6
$hexagram_pkg .= "<tr>\n";
$hexagram_pkg .= "<td class=\"ucd_num\"><i class=\"u-norm\">$val_r6_c1</i></td>\n";
$hexagram_pkg .= "<td class=\"ucd_num\"><i class=\"u-bold\">$val_r6_c3</i></td>\n";
$hexagram_pkg .= "<td class=\"ucd_num\"><i class=\"u-norm\">$bin_row_6</i></td>\n";
$hexagram_pkg .= "<td class=\"new_hex_image\"><img img src=\"$hex_img_dir/$bin_row_6.png\" class=\"the_hex_img\"></td>\n";
$hexagram_pkg .= "<td class=\"ucd_num\"><i class=\"u-norm\">$bin_row_6</i></td>\n";
$hexagram_pkg .= "<td class=\"ucd_num\"><i class=\"u-bold\">$val_r6_c9</i></td>\n";
$hexagram_pkg .= "<td class=\"ucd_num\"><i class=\"u-norm\">$val_r6_c11</i></td>\n";
$hexagram_pkg .= "</tr>\n";


// Summary Row Padder
$hexagram_pkg .= "<tr>\n";
$hexagram_pkg .= "<td class=\"summ_padder\" colspan=\"7\">&nbsp;</td>\n";
$hexagram_pkg .= "</tr>\n";


// Summary Row
$hexagram_pkg .= "<tr>\n";
$hexagram_pkg .= "<td class=\"ucd_num\"><i class=\"u-norm\">$ucd_complementary_number</i></td>\n";
$hexagram_pkg .= "<td class=\"ucd_num\"><i class=\"u-bold\">$ucd_chapter</i></td>\n";
$hexagram_pkg .= "<td class=\"ucd_num\" colspan=3><i class=\"u-bold\">$ucd_codon_code</i></td>\n";
$hexagram_pkg .= "<td class=\"ucd_num\"><i class=\"u-bold\">$ucd_inverse_number</i></td>\n";
$hexagram_pkg .= "<td class=\"ucd_num\"><i class=\"u-norm\">$ucd_fu_xi_number</i></td>\n";
$hexagram_pkg .= "</tr>\n";

// END table for this Hexagram with 9 columns
$hexagram_pkg .= "</tbody>\n";
$hexagram_pkg .= "</table>\n";



// Change title that is all UPPERCASE, to ucfirst
$ucd_u_ching_title = strtolower($ucd_u_ching_title);

// Start a table for / with 3 columns / Summary Information
$hextras_pkg .= "<table id=\"hex_summary\" class=\"hex_table_new\">";

// ROW for U-Ching Title 
$hextras_pkg .= "<tr>\n";
$hextras_pkg .= "<td class=\"ucd_uching_title\" colspan=\"3\">$ucd_u_ching_title</td>\n";
$hextras_pkg .= "</tr>\n";

// ROW for U-Ching Subtitle
$hextras_pkg .= "<tr>\n";
$hextras_pkg .= "<td class=\"ucd_u_ching_subtitle\" colspan=\"3\"><i class=ucd_ucs>$ucd_u_ching_subtitle</i></td>\n";
$hextras_pkg .= "</tr>\n";

// Rune Image
$hextras_pkg .= "<tr>\n";
$hextras_pkg .= "<td class=\"rune_img_padder\"><p class=\"core-rt\">$tr_txt_core</p><p class=\"core-rt\">$ucd_core_number</p></td>\n";
$hextras_pkg .= "<td class=\"rune_image_td\">";
$hextras_pkg .= "<img class=\"rune_img\" src=\"$rune_img_dir/$rune_img_nm\" height=\"58\" width=\"58\">\n\n";
$hextras_pkg .= "</td>\n\n";
$hextras_pkg .= "<td class=\"rune_img_padder\"><p class=\"core-lt\">$tr_txt_bmu</p><p class=\"core-lt\">$ucd_bmu_number</p></td>\n";
$hextras_pkg .= "</tr>\n";


// Centered Rune Title
$hextras_pkg .= "<tr>\n";
$hextras_pkg .= "<td class=\"ucd_rune_title\" colspan=\"3\">$ucd_rune_title</td>\n";
$hextras_pkg .= "</tr>\n";

// Rune SubTitle
$hextras_pkg .= "<tr>\n";
$hextras_pkg .= "<td class=\"ucd_rune_subtitle\" colspan=\"3\">$ucd_rune_subtitle</td>\n";
$hextras_pkg .= "</tr>\n";

// END table for this with 3 columns
$hextras_pkg .= "</table>";


// NOw, put it all inside a table... for panel #1
$uching_content_one .= "<table class=date_chooser id=\"date_info\">\n";
$uching_content_one .= "<tr>\n";
$uching_content_one .= "<td rowspan=2 class=\"prior_day_link\">$prior_day_link</td>\n";
$uching_content_one .= "<td class=date_container><i class=date_container4>$this_nice_translated_date</i></td>\n";
$uching_content_one .= "<td rowspan=2 class=\"next_day_link\">$next_day_link</td>\n";
$uching_content_one .= "</tr>\n";
$uching_content_one .= "<tr>\n";
$uching_content_one .= "<td class=\"kinfo_td\">";
$uching_content_one .= "Kin: $this_day_kin_num - $tr_txt_chapter $found_chapter";
$uching_content_one .= "</td>\n";
$uching_content_one .= "</tr>\n";


// Do a bit of date figuring
$today_yr = date('Y'); // Y	A full numeric representation of a year, 4 digits
$today_mo = date('m'); // m	Numeric representation of a month, with leading zeros
$today_day = date('d'); // d	Day of the month, 2 digits with leading zeros

$date_comp_one = "$today_yr-$today_mo-$today_day";
$date_comp_two = "$dcode_yr-$dcode_mo-$dcode_day";

$datetime1 = date_create($date_comp_one);
$datetime2 = date_create($date_comp_two);
$interval = date_diff($datetime1, $datetime2);
$num_days_diff = $interval->format('%R%a');

if ($num_days_diff != 0) {
	$uching_content_one .= "<tr>\n";
	$uching_content_one .= "<td colspan=3>\n";
	$uching_content_one .= "$num_days_diff $tr_txt_days_frm";
     $uching_content_one .= "</td>\n";
     $uching_content_one .= "</tr>\n";
}

$uching_content_one .= "</table>\n\n";

// Table for Hexagram with expanding sides
$uching_content_one .= "<table class=hexagram_tbl width=\"100%\">\n";
$uching_content_one .= "<tr>\n";
// $uching_content_one .= "<td style=\"width: 10%;\"></td>";
$uching_content_one .= "<td align=center>";
$uching_content_one .= $hexagram_pkg;
$uching_content_one .= "</td>\n";
// $uching_content_one .= "<td style=\"width: 10%;\"></td>";
$uching_content_one .= "</tr>\n";
$uching_content_one .= "</table>\n\n";

// Table for Hexagram Extras with expanding sides
$uching_content_one .= $hextras_pkg;




// THIRD TAB construction =============================================================================================

// Start a table for / with 3 columns / Summary Information // THIRD TAB construction ===========
$uching_content_three .= "<table id=\"third_tab_table\" class=\"hex_full_table\">";

// Third Tab Hexagram Image - three cols
$uching_content_three .= "<tr>\n";
$uching_content_three .= "<td class=\"hex_full_img_padder\">";
$uching_content_three .= "<p class=\"time_outer_rt\"><strong>$ucd_outer_triplet</strong></p><p class=\"time_outer_rt\">$tr_txt_outer</p>\n";
$uching_content_three .= "</td>\n";

$uching_content_three .= "<td class=\"new_hex_image\" rowspan=2>";
$uching_content_three .= "<img class=\"hex_full_img_full\" src=\"$full_hex_img_dir/$hex_full_img_nm\" height=\"58\" width=\"58\">\n\n";
$uching_content_three .= "</td>\n\n";

$uching_content_three .= "<td></td>\n"; // Blank cell
$uching_content_three .= "</tr>\n";

$uching_content_three .= "<tr>\n";
$uching_content_three .= "<td></td>\n"; // Blank cell
$uching_content_three .= "<td class=\"hex_full_img_padder_rt\" class=\"vertical-align: bottom;\">";
$uching_content_three .= "<p class=\"time_outer_lt\">$tr_txt_inner</p><p class=\"time_outer_lt\"><strong>$ucd_inner_triplet</strong></p>\n";
$uching_content_three .= "</td>\n";
$uching_content_three .= "</tr>\n";

// Blank Row
$uching_content_three .= "<tr>\n";
$uching_content_three .= "<td class=\"vert_spacer\" colspan=\"3\">&nbsp;</td>\n";
$uching_content_three .= "</tr>\n";

// Centered Title
$uching_content_three .= "<tr>\n";
$uching_content_three .= "<td class=\"third_tab_title\" colspan=\"3\" style=\"font-weight: 600;\">$ucd_hexagram_binary_del - $ucd_codon_code</td>\n";
$uching_content_three .= "</tr>\n";

// Blank Row
$uching_content_three .= "<tr>\n";
$uching_content_three .= "<td class=\"vert_spacer\" colspan=\"3\" style=\"line-height: 4px;\">&nbsp;</td>\n";
$uching_content_three .= "</tr>\n";

// Centered Title
$uching_content_three .= "<tr>\n";
$uching_content_three .= "<td class=\"third_tab_title\" colspan=\"3\">$tr_txt_cube_grp <strong>$ucd_group_number</strong> $tr_txt_cube_gext</td>\n";
$uching_content_three .= "</tr>\n";

// Blank Row
$uching_content_three .= "<tr>\n";
$uching_content_three .= "<td class=\"vert_spacer\" colspan=\"3\" style=\"line-height: 4px;\">&nbsp;</td>\n";
$uching_content_three .= "</tr>\n";

// Centered Title
$uching_content_three .= "<tr>\n";
$uching_content_three .= "<td class=\"third_tab_title\" colspan=\"3\">$tr_txt_amino <strong>$ucd_amino_acid</strong></td>\n";
$uching_content_three .= "</tr>\n";

// Start a table for / with 3 columns / Summary Information // THIRD TAB construction ===========
$uching_content_three .= "<table id=\"third_tab_table\" class=\"hex_full_table\">";

$uching_content_three .= "<tr>\n";

// First Cell
$uching_content_three .= "<td class=\"chin_nm_lt\">";
$uching_content_three .= "<p class=\"time_outer_rt\">$ucd_chinese_name_1</p>\n";
$uching_content_three .= "</td>\n";

// Cell with Chinese Char
$uching_content_three .= "<td class=\"china_char\">";
$uching_content_three .= "<div class=\"ucd_chinese_chars\"><i class=chinese_char> $ucd_chinese_characters </i></div>\n\n";
$uching_content_three .= "</td>\n\n";

// Third Cell
$uching_content_three .= "<td class=\"chin_nm_rt\">";
$uching_content_three .= "<p class=\"time_outer_lt\">$ucd_chinese_name_2</p>\n";
$uching_content_three .= "</td>\n\n";
$uching_content_three .= "</tr>\n";

// Blank Row
$uching_content_three .= "<tr>\n";
$uching_content_three .= "<td class=\"vert_spacer\" colspan=\"3\" style=\"line-height: 4px;\">&nbsp;</td>\n";
$uching_content_three .= "</tr>\n";

// Centered Title
$uching_content_three .= "<tr>\n";
$uching_content_three .= "<td class=\"third_tab_title\" colspan=\"3\">$tr_txt_iching_ttl <strong>$ucd_i_ching_title</strong></td>\n";
$uching_content_three .= "</tr>\n";

// Blank Row
$uching_content_three .= "<tr>\n";
$uching_content_three .= "<td class=\"vert_spacer\" colspan=\"3\" style=\"line-height: 4px;\">&nbsp;</td>\n";
$uching_content_three .= "</tr>\n";

// Centered Title
$uching_content_three .= "<tr>\n";
$uching_content_three .= "<td class=\"third_tab_title\" colspan=\"3\">$tr_txt_wil_ttl <strong>$ucd_i_ching_title_wilhelm</strong></td>\n";
$uching_content_three .= "</tr>\n";

// END table for this 3 columns table
$uching_content_three .= "</table>";



// Start a table for / with 3 columns / Summary Information // THIRD TAB construction ===========
$uching_content_three .= "<table id=\"third_tab_table\" class=\"hex_full_table\">";

// Third Tab Hexagram Image - three cols
$uching_content_three .= "<tr>\n";
$uching_content_three .= "<td class=\"hex_full_moon_padder\" style=\"vertical-align: middle;\">";
$uching_content_three .= "<p class=\"time_outer_rt\">$tr_txt_lunar_ra</p>\n";
$uching_content_three .= "</td>\n";

$uching_content_three .= "<td class=\"new_hex_image\">";
$uching_content_three .= "<img class=\"lunar_ring_img\" src=\"$lunar_ring_squares_dir/$lunar_ring_img_nm\" height=\"58\" width=\"58\">\n\n";
$uching_content_three .= "</td>\n\n";

$uching_content_three .= "<td class=\"hex_full_moon_padder\"  style=\"vertical-align: middle;\">";

$uching_content_three .= "<p class=\"time_outer_lt\">$tr_txt_lunar_rb</p>\n";
$uching_content_three .= "</td>\n";
$uching_content_three .= "</tr>\n";

// END table for this 3 columns table
$uching_content_three .= "</table>";




// Start a table for / with 3 columns / Summary Information // THIRD TAB construction ===========
$uching_content_three .= "<table id=\"third_tab_table\" class=\"hex_full_table\">";

// Third Tab Hexagram Image - three cols
$uching_content_three .= "<tr>\n";
$uching_content_three .= "<td class=\"hex_full_moon_padder\" style=\"vertical-align: middle;\">";
$uching_content_three .= "<p class=\"time_outer_rt\">$tr_txt_gal_seas</p>\n";
$uching_content_three .= "</td>\n";

$uching_content_three .= "<td class=\"new_hex_image\">";
$uching_content_three .= "<img class=\"lunar_ring_img\" src=\"$kin_earth_fam_dir/$kin_earth_fam_img_nm\" height=\"58\" width=\"58\">\n\n";
$uching_content_three .= "</td>\n\n";

$uching_content_three .= "<td class=\"hex_full_moon_padder\"  style=\"vertical-align: middle;\">";
$uching_content_three .= "<p class=\"time_outer_lt\">$tr_txt_day_br<strong>$ucd_inverse_number</strong></p>\n";
$uching_content_three .= "</td>\n";
$uching_content_three .= "</tr>\n";


// Blank Row
$uching_content_three .= "<tr>\n";
$uching_content_three .= "<td class=\"vert_spacer\" colspan=\"3\" style=\"line-height: 8px;\">&nbsp;</td>\n";
$uching_content_three .= "</tr>\n";

// Centered Title
$uching_content_three .= "<tr>\n";
$uching_content_three .= "<td class=\"third_tab_title\" colspan=\"3\">";
$uching_content_three .= "Wavespell <strong>$ucd_wavespell_in_season </strong> $tr_txt_of 5";
$uching_content_three .= "</td>\n";
$uching_content_three .= "</tr>\n";


// TRANSLATE - Choose the function to get the Tone Name
if ($ucd_locale == "es_ES"){
	$earth_fam_array = ucd_earth_fam_num_to_name_es($ucd_earth_family); 	// Use Spanish
	$this_tone_name = ucd_tone_num_to_name_es($ucd_galactic_tone);

} elseif ($ucd_locale == "nl_NL"){
	$earth_fam_array = ucd_earth_fam_num_to_name_nl($ucd_earth_family);  	// Use Dutch
	$this_tone_name = ucd_tone_num_to_name_nl($ucd_galactic_tone);
} else {
	$earth_fam_array = ucd_earth_fam_num_to_name_en($ucd_earth_family);  	// Use English
	$this_tone_name = ucd_tone_num_to_name_en($ucd_galactic_tone);
}



$earth_fam_name = $earth_fam_array[0];
$earth_fam_num_suf = $earth_fam_array[1];


// Blank Row
$uching_content_three .= "<tr>\n";
$uching_content_three .= "<td class=\"vert_spacer\" colspan=\"3\" style=\"line-height: 4px;\">&nbsp;</td>\n";
$uching_content_three .= "</tr>\n";

// Centered Title
$uching_content_three .= "<tr>\n";
$uching_content_three .= "<td class=\"third_tab_title\" colspan=\"3\">";
$uching_content_three .= "<strong>$ucd_earth_family$earth_fam_num_suf $earth_fam_name</strong>";
$uching_content_three .= "</td>\n";
$uching_content_three .= "</tr>\n";

// Blank Row
$uching_content_three .= "<tr>\n";
$uching_content_three .= "<td class=\"vert_spacer\" colspan=\"3\" style=\"line-height: 4px;\">&nbsp;</td>\n";
$uching_content_three .= "</tr>\n";

// Centered Title
$uching_content_three .= "<tr>\n";
$uching_content_three .= "<td class=\"third_tab_title\" colspan=\"3\">";
$uching_content_three .= "<strong>$this_tone_name</strong> $tr_txt_tone <strong>$ucd_galactic_tone</strong>";
$uching_content_three .= "</td>\n";
$uching_content_three .= "</tr>\n";

// END table for this 3 columns table
$uching_content_three .= "</table>";



?>