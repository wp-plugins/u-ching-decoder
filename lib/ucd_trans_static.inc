<?php // ucd_trans_static.inc  // Translate static text values

     // What language are you using?
     $ucd_locale = get_locale();
     
     // Check to see if file is there...
     if ($ucd_locale == "es_ES"){

     // Spanish Values
         $tr_txt_hexagram          = "Hexagrama";                              // 1 **
          $tr_txt_decode           = "Descifrar";                         // 2 **
          $tr_txt_chapter          = "Capítulo:";                              // 3 **
          $tr_txt_days_frm         = "días de hoy";                         // 4 **
          $tr_txt_core             = "Núcleo";                              // 5 **
          $tr_txt_bmu              = "UMB";                                   // 6 **
          $tr_txt_greg             = "Fecha Gregoriana:";                    // 7 **
          $tr_txt_kinnum           = "Número Kin:";                         // 8 **
          $tr_txt_cubenum          = "Número Cubo:";                    // 9 **
          $tr_txt_iching_ch        = "Capítulo I Ching";                    // 10 **
          $tr_txt_outer            = "Exterior<br>Parando";               // 11 **
          $tr_txt_inner            = "Interior<br>Parando";                    // 12 **
          $tr_txt_cube_grp         = "Grupo Nœmero Cubo";                    // 13 *
          $tr_txt_cube_gext        = "de 20 +1";                              // 14 *
          $tr_txt_iching_ttl       = "Título I Ching:";                    // 15 *
          $tr_txt_wil_ttl          = "Título Wilhelm:";                    // 16 *
          $tr_txt_lunar_ra         = "Lunar";                              // 17 *
          $tr_txt_lunar_rb         = "Anillo";                              // 18 *
          $tr_txt_gal_seas         = "La Estación<br>Galáctico";          // 19 *
          $tr_txt_day_br           = "Día<br>";                              // 20 *
          $tr_txt_tone             = "Tono";                                   // 21 *
          $tr_txt_amino            = "Aminoácido:";                         // 22 *
          $tr_txt_of               = "de";                                   // 23 *
     	$tr_txt_moon			= "luna";							// 24 *

	} elseif ($ucd_locale == "nl_NL"){

     	$tr_txt_hexagram		= "Hexagram";               	// 1 *
     	$tr_txt_decode			= "Decodeer";               	// 2 *
     	$tr_txt_chapter        	= "Hoofdstuk:";              	// 3 *
     	$tr_txt_days_frm        	= "dagen vanaf vandaag";     	// 4 *
     	$tr_txt_core			= "Kern";                   	// 5 *
     	$tr_txt_bmu			= "BMU";                   	// 6 *
     	$tr_txt_greg			= "Gregoriaanse Datum:";     	// 7 *
     	$tr_txt_kinnum			= "Kin Getal:";           	// 8 *
     	$tr_txt_cubenum        	= "Kubus Getal:";           	// 9 *
     	$tr_txt_iching_ch        = "I Ching Hoofdstuk";       	// 10 *
     	$tr_txt_outer			= "Uiterlijk<br>Triplet";    	// 11 *
     	$tr_txt_inner			= "Innerlijk<br>Triplet";    	// 12 *
     	$tr_txt_cube_grp		= "Kubus Getal Groep";		// 13 *
     	$tr_txt_cube_gext		= "van 20 +1";				// 14 *
     	$tr_txt_iching_ttl       = "I Ching Titel:";       	// 15 *
     	$tr_txt_wil_ttl        	= "Wilhelm Titel:";       	// 16 *
     	$tr_txt_lunar_ra		= "Lunaire";				// 17 *
     	$tr_txt_lunar_rb		= "Ring";					// 18 *
     	$tr_txt_gal_seas        	= "Galactisch<br>Seizoen";   	// 19 *
     	$tr_txt_day_br			= "Dag<br>";               	// 20 *
     	$tr_txt_tone			= "Toon";                   	// 21 *
     	$tr_txt_amino			= "Aminozuur:";			// 22 *
     	$tr_txt_of			= "van";					// 23 *
     	$tr_txt_moon			= "maan";					// 24 *



	} else {

     // English Values
     	$tr_txt_hexagram		= "Hexagram";						// 1 *
     	$tr_txt_decode			= "Decode";						// 2 *
     	$tr_txt_chapter		= "Chapter:";						// 3 *
     	$tr_txt_days_frm		= "days from today";				// 4 *
     	$tr_txt_core			= "Core";							// 5 *
     	$tr_txt_bmu			= "BMU";							// 6 *
     	$tr_txt_greg			= "Gregorian Date:";				// 7 *
     	$tr_txt_kinnum			= "Kin Number:";					// 8 *
     	$tr_txt_cubenum		= "Cube Number:";					// 9 *
     	$tr_txt_iching_ch		= "I Ching Chapter";				// 10 *
     	$tr_txt_outer			= "Outer<br>Triplet";				// 11 *
     	$tr_txt_inner			= "Inner<br>Triplet";				// 12 *
     	$tr_txt_cube_grp		= "Cube Number Group";				// 13 *
     	$tr_txt_cube_gext		= "of 20 +1";						// 14 *
     	$tr_txt_iching_ttl		= "I Ching Title:";					// 15 *
     	$tr_txt_wil_ttl		= "Wilhelm Title:";					// 16 *
     	$tr_txt_lunar_ra		= "Lunar";						// 17 *
     	$tr_txt_lunar_rb		= "Ring";							// 18 *
     	$tr_txt_gal_seas		= "Galactic<br>Season";				// 19 *
     	$tr_txt_day_br			= "Day<br>";						// 20 *
     	$tr_txt_tone			= "Tone";							// 21 *
     	$tr_txt_amino			= "Amino Acid:";					// 22 *
     	$tr_txt_of			= "of";							// 23 *
     	$tr_txt_moon			= "moon";							// 24 *
}


// Encode the special Characters with // utf8_encode(}

    	$tr_txt_hexagram		= utf8_encode($tr_txt_hexagram); // encode itHexagrama";						// 1 **
    	$tr_txt_decode			= utf8_encode($tr_txt_decode); // encode itDescodificar";					// 2 **
    	$tr_txt_chapter		= utf8_encode($tr_txt_chapter); // encode itCapítulo:";						// 3 **
    	$tr_txt_days_frm		= utf8_encode($tr_txt_days_frm); // encode itDías de Hoy";					// 4 **
    	$tr_txt_core			= utf8_encode($tr_txt_core); // encode itNúcleo";						// 5 **
    	$tr_txt_bmu			= utf8_encode($tr_txt_bmu); // encode itBMU";							// 6 **
    	$tr_txt_greg			= utf8_encode($tr_txt_greg); // encode itFecha Gregoriana:";				// 7 **
    	$tr_txt_kinnum			= utf8_encode($tr_txt_kinnum); // encode itNúmero Kin:";					// 8 **
    	$tr_txt_cubenum		= utf8_encode($tr_txt_cubenum); // encode itNúmero del Cube:";				// 9 **
    	$tr_txt_iching_ch		= utf8_encode($tr_txt_iching_ch); // encode itI Ching Capítulo";				// 10 **
    	$tr_txt_outer			= utf8_encode($tr_txt_outer); // encode itTripleta<br>Exterior";			// 11 **
    	$tr_txt_inner			= utf8_encode($tr_txt_inner); // encode itTriplete<br>Interno";				// 12 **
    	$tr_txt_cube_grp		= utf8_encode($tr_txt_cube_grp); // encode itGrupo Número Cubo";				// 13 *
    	$tr_txt_cube_gext		= utf8_encode($tr_txt_cube_gext); // encode itde 20 +1";						// 14 *
    	$tr_txt_iching_ttl		= utf8_encode($tr_txt_iching_ttl); // encode itI Ching Capítulo:";				// 15 *
    	$tr_txt_wil_ttl		= utf8_encode($tr_txt_wil_ttl); // encode itWilhelm Capítulo:";				// 16 *
    	$tr_txt_lunar_ra		= utf8_encode($tr_txt_lunar_ra); // encode itLunar";						// 17 *
    	$tr_txt_lunar_rb		= utf8_encode($tr_txt_lunar_rb); // encode itAnilla";						// 18 *
    	$tr_txt_gal_seas		= utf8_encode($tr_txt_gal_seas); // encode itTemporada<br>de la<br>Galaxia";		// 19 *
    	$tr_txt_day_br			= utf8_encode($tr_txt_day_br); // encode itDia<br>";						// 20 *
    	$tr_txt_tone			= utf8_encode($tr_txt_tone); // encode itTono";							// 21 *
    	$tr_txt_amino			= utf8_encode($tr_txt_amino); // encode itAminoácido:";					// 22 *
    	$tr_txt_of			= utf8_encode($tr_txt_of); // encode itde";							// 23 *
    	$tr_txt_moon			= utf8_encode($tr_txt_moon); // encode itde";							// 24 *

?>