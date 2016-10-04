	function sendInfo(r,g,b,s){
		vals = 'r='+r+'&g='+g+'&b='+b+'&s='+s;
		$.get('/apply',vals);		
	}

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
	  slide: refreshSwatch,
	  change: refreshSwatch
	});
	$( "#red" ).slider( "value", 0 );
	$( "#green" ).slider( "value", 0 );
	$( "#blue" ).slider( "value", 0 );
 
	$("#b1").click( function (){
		$("#pane1").show();
		$("#pane2").hide();
		$("#pane3").hide();
		$("#pane4").hide();
		$("[role='presentation']").removeClass("active");
		$(".presentation").removeClass("active");
		$("#b1").addClass("active");
	});
 
	$("#b2").click( function (){
		$("#pane1").hide();
		$("#pane2").show();
		$("#pane3").hide();
		$("#pane4").hide();
		$("[role='presentation']").removeClass("active");
		$("#b2").addClass("active");
	});
 
	$("#b3").click( function (){
		$("#pane1").hide();
		$("#pane2").hide();
		$("#pane3").show();
		$("#pane4").hide();
		$("[role='presentation']").removeClass("active");
		$("#b3").addClass("active");
        $(".full-spectrum").trigger("click");
        $(".pane > .full-spectrum").hide();
	});
 
	$("#b4").click( function (){
		$("#pane1").hide();
		$("#pane2").hide();
		$("#pane3").hide();
		$("#pane4").show();
		$("[role='presentation']").removeClass("active");
		$("#b4").addClass("active");
	});

  } );
