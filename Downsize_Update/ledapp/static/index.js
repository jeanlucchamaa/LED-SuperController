  $( function() {
	function hexFromRGB(r, g, b) {
	  var hex = [
		r.toString( 16 ),
		g.toString( 16 ),
		b.toString( 16 )
	  ];
	  $.each( hex, function( nr, val ) {
		if ( val.length === 1 ) {
		  hex[ nr ] = "0" + val;
		}
	  });
	  return hex.join( "" ).toUpperCase();
	}
	function sendInfo(r,g,b,s){
		vals = 'r='+r+'&g='+g+'&b='+b+'&s='+s;
		$.get('/apply',vals);		
	}

	$('#swatch').bind('click', function(){
		red = $( "#red" ).slider( "value" );
		green = $( "#green" ).slider( "value" );
		blue = $( "#blue" ).slider( "value" );

	});
		function refreshSwatch() {
	  var red = $( "#red" ).slider( "value" ),
		green = $( "#green" ).slider( "value" ),
		blue = $( "#blue" ).slider( "value" );
		sendInfo(red,green,blue,1);
		hex = hexFromRGB( red, green, blue );
	  $( "#swatch" ).css( "background-color", "#" + hex );

	}
 
	$( "#red, #green, #blue" ).slider({
	  orientation: "horizontal",
	  range: "min",
	  max: 255,
	  value: 127,
	  //slide: refreshSwatch,
	  change: refreshSwatch
	});
	$( "#red" ).slider( "value", 0 );
	$( "#green" ).slider( "value", 0 );
	$( "#blue" ).slider( "value", 0 );
  } );
