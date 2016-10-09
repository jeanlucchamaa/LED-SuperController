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
    var software=1;//use software input vs hardware
    var inUse=false;// boolean determine if updateAll is already working, to avoid cyclic calls
	function updateAll(r,g,b,caller){
        if($(".ui-slider").length){ //ensure that the sliders are loaded before we manipulate them
            if(!inUse){
                inUse=true;//sets boolean
                switch(caller){
                    case 'palette':
                        //update sliders
                        $("#red").slider("value",r)
                        $("#green").slider("value",g)
                        $("#blue").slider("value",b)
                        //update lights
                        vals = 'r='+r+'&g='+g+'&b='+b+'&s='+software;
                        $.get('/apply',vals);
                        break;
                    case 'slider':
                        //change r,g,b from current slider values
                        r=$("#red").slider("value")
                        g=$("#green").slider("value")
                        b=$("#blue").slider("value")
                        var hexy=hexFromRGB(r,g,b);
                        $(".sp-input").val('#'+hexy);
                        $(".sp-input").change();
                        vals = 'r='+r+'&g='+g+'&b='+b+'&s='+software;
                        $.get('/apply',vals);
                        break;
                    case 'lights':
                        break;
                    default:
                        break;
                }
                $( "#swatch" ).css( "background-color", "#" + hexFromRGB(r,g,b) );
                inUse=false;
            }
        }
    }     
	
function slideWrapper(){
    updateAll(0,0,0,'slider');
}
           
$(function() {

	$( "#red, #green, #blue" ).slider({
	  orientation: "horizontal",
	  range: "min",
	  max: 255,
	  value: 0,
	  slide: slideWrapper,
	  change: slideWrapper
	});
 
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
        $(".full-spectrum").trigger("click");
        $('.sp-replacer').hide();
		$(window).trigger('resize');
	});
 
	$("#b3").click( function (){
		$("#pane1").hide();
		$("#pane2").hide();
		$("#pane3").show();
		$("#pane4").hide();
		$("[role='presentation']").removeClass("active");
		$("#b3").addClass("active");
	});
 
	$("#b4").click( function (){
		$("#pane1").hide();
		$("#pane2").hide();
		$("#pane3").hide();
		$("#pane4").show();
		$("[role='presentation']").removeClass("active");
		$("#b4").addClass("active");
	});

    $('#b1').trigger("click");
      $(window).resize(function(){
          var left=$(".sp-container").outerWidth();
          $('.ui-slider,#swatch').css('margin-left',left+25);
      });
  } );
