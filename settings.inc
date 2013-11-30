<?php

function ucd_admin_options_menu() {
	//create new top-level menu
	add_options_page('uChing Decoder', 'uChing Decoder', 'administrator', __FILE__, 'uching_settings_page');
	add_action( 'admin_init', 'uching_register_mysettings' );
}

function uching_register_mysettings() {
	//register our settings
	register_setting( 'ucd-settings-group', 'decode_table_background_color' );
	register_setting( 'ucd-settings-group', 'show_num_posts' ); // NEW
	register_setting( 'ucd-settings-group', 'permit_credits' );
	register_setting( 'ucd-settings-group', 'last_save_time' );
}

// Don't add anymore functions:

function uching_settings_page() {
?>
<div class="wrap">
<h2>u-Ching Decoder Settings</h2>


<?php


if ($_GET["settings-updated"] === "true"){
	$table_bg = "#AEA";
} else {
	$table_bg = "";
}

$curr_date = date("D F j, Y g:i:s a  ");
$save_time_mess = get_option('last_save_time');

echo "<table bgcolor=$table_bg>\n";
if ($_GET["settings-updated"] === "true"){
	echo "<tr><th colspan=2><h2>Settings Saved!</h2></th><tr>\n";
}
echo "<tr><td>Current Date:</td><td>$curr_date</td></tr>\n";
echo "<tr><td>Last Save:</td><td>$save_time_mess</td></tr>\n";
echo "</table>\n";
?>

<hr>

</P>

<form method="post" action="options.php">
    <?php settings_fields( 'ucd-settings-group' ); ?>

    <table class="form-table" width="100%">

	   <tr>
	   <th scope="row" style="width: 400px;"><b>Decoder Table Background Color:</b>
<br> (default: eee) A hex value is either 3 or 6 characters.  For instance FF0000 is the same as F00 or another way to say red.  Each digit can be 0-8 or A-F.  000 is black.  FFF is white.  Each place stands for RED, GREEN, and BLUE.  So blue is 00F.  Grey is any value of the same number/letter.  For instance, ddd is a darker grey than eee.</th>
	   <td valign=top>
#<input size=8 maxlength=6 type="text" name="decode_table_background_color" value="<?php echo get_option('decode_table_background_color'); ?>" /> -- hex value
		</td>
	   </tr>


	   <tr>
	   <th scope="row"><b>Maximum Number of Posts shown in Day Popup</b></th>
	   <td valign=top>
<input size=8 maxlength=2 type="text" name="show_num_posts" value="<?php echo get_option('show_num_posts'); ?>" />(Default is 5)
		</td>
	   </tr>


		<?php $permit_credits = get_option('permit_credits'); ?>
		<?php if (!isset($permit_credits)){$permit_credits = "YES";} ?>

	   <tr>
	   <th scope="row"><b>Show Credits</b></th>
	   	<td>
		<input type=radio name="permit_credits" value="YES" <?php if ($permit_credits === "YES"){echo " CHECKED";} ?> /> Yes
		<input type=radio name="permit_credits" value="NO" <?php if ($permit_credits === "NO"){echo " CHECKED";} ?> /> No
		</td>
	   </tr>

    </table>
    
    <p class="submit">
	<input type="hidden" name="last_save_time" value="<?php echo $curr_date; ?>" />
<br>
    <input type="submit" class="button-primary" value="<?php _e('Save Changes') ?>" />
    </p>

</form>

<P>

<hr>
<h2>What do you want in this plugin?</h2>
We're wondering what OTHER settings or FEATURES you might like.
<br><br>
With the next version, we hope to have:
<ul>
<li>- Translate: English to Dutch and Spanish - it will sense user's language and switch on its own</li>
<li>- List most recent activity (BuddyPress)</li>
<li>- List users born on this chapter (BuddyPress-friendly)</li>

</ul>
Please rate this plugin, and share know how it looks in YOUR copy of WordPress.
<br><br>If you like this plugin, you might also like the <a href="http://wordpress.org/plugins/cosmic-history-quotes/" target="_blank">Cosmic History Quotes WP Plugin</a> and The <a href="http://wordpress.org/plugins/u-ching-decoder/" target="_blank">u-Ching Decoder</a>.

<hr>


	<h2>Inspiration and Support</h2>
	<li><a class=credits href="http://lawoftime.org/" title="Foundation for the Law of Time">Foundation for the Law of Time (FLT)</a></li>
	<li><a class=credits href="http://planetartnetwork.info/" title="Planet Art Network">Planet Art Network (PAN)</a></li>
	<li><a class=credits href="http://spacestationplaza.com/" title="Space Station Plaza Galactic Portal">Space Station Plaza (SSP)</a></li>
	<li><a class=credits href="http://anthonyfogleman.com/blog/wordpress-plugins/" title="Plugin author: Anthony Fogleman (Anka) Kin 139 Solar Storm">Plugins by Anka (kin 139)</a></li>
	<li><a class=credits href="http://www.wetvantijd.nl" title="Dutch translation: Juryt Abma Kin-243 Solar Night">Developed for the Dutch Law of Time website</a></li>
	<li><a class=credits href="http://u-ching.com" title="uCHING - Juryt Abma Kin-243 Solar Night">Developed also for u-Ching.com</a></li>

</div>
<?php } ?>