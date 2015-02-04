<?php
/*
Plugin Name: u-Ching Decoder
Plugin URI: http://anthonyfogleman.com/blog/u-ching-decoder-wp-plugin/
Description: The u-Ching is a new application for the Dreamspell. With this tool you are able to decode the ancient 64 hexagrams of the I Ching into their corresponding number frequency, not known before. This re-orders all the chapters of the I into U. In this ancient new knowledge we continue our study of the Genetic Code in Time. Every hexagram (or codon) is related with one of 64 UR Runes, we learned about in the Law of Time. The u-Ching became available as a gift from the People of O.M.A. around Galactic Synchronization in 2013. This Wordpress plugin works as a widget you can drop in a sidebar. It is responsive and resizes to certain proportions with theme, for example on mobile devices.
Version: 1.1.57
Author: Juryt Abma and Anthony R. Fogleman
Author URI: http://anthonyfogleman.com
License: GPLv2
*/

/*  Copyright 2013  Anthony R. Fogleman  ( circle@uptimehosting.com )

    This program is free software; you can redistribute it and/or modify
    it under the terms of the GNU General Public License, version 2, as
    published by the Free Software Foundation.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program; if not, write to the Free Software
    Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
*/

/**
 * Proper way to enqueue scripts and styles
*/

/*  Add Custom Styles */
function ucd_add_styles(){
// This is the decoder's css file - we NEED IT
	wp_register_style( 'u-ching-decoder-style', plugins_url('/css/u-ching-decoder.css', __FILE__), false, '1.0.0', 'all');
	wp_register_script( 'ucd-simple-tabs', plugins_url('/js/ucd_tabs.js', __FILE__), false, '1.0.0', 'all');
	wp_register_script( 'ucd-show-after-load', plugins_url('/js/load_toshow.js', __FILE__), false, '1.0.0', 'all');
}
add_action('init', 'ucd_add_styles');

/*  Enqueue scripts and styles  */
function ucd_load_scripts(){
	wp_enqueue_style( 'u-ching-decoder-style' );
	wp_enqueue_script( 'ucd-simple-tabs' );
	wp_enqueue_script( 'ucd-show-after-load' );
}
add_action('wp_enqueue_scripts', 'ucd_load_scripts');
// -- done registering style and scripts

// Include dashboard widget for the sidebar decoder
include('ucd_dashboard_widget.php');

// This code creates the ability to use shortcodes in the sidebar
add_filter('widget_text', 'do_shortcode');

// Include decoder program function
include('ucd_construct.inc');

// Make a shortcode for full-page use
add_shortcode('u-ching-display', 'start_uching');

// Include wp menu and settings
include('settings.inc');

// create custom plugin settings
add_action('admin_menu', 'ucd_admin_options_menu');

// To get admin menu "Settings" | Deactivate | Edit
function ucd_admin_settings_link( $links ) {
	$settings_link = '<a href="options-general.php?page=u-ching-decoder/settings.inc">Settings</a>';
  	array_push( $links, $settings_link );
  	return $links;
}
$plugin = plugin_basename( __FILE__ );
add_filter( "plugin_action_links_$plugin", 'ucd_admin_settings_link' );
?>