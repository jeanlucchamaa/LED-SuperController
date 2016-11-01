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
                        socket.emit('apply',r,g,b,1);
                        break;
                    case 'slider':
                        //change r,g,b from current slider values
                        r=$("#red").slider("value")
                        g=$("#green").slider("value")
                        b=$("#blue").slider("value")
                        var hexy=hexFromRGB(r,g,b);
                        $(".sp-input").val('#'+hexy);
                        $(".sp-input").change();
                        socket.emit('apply',r,g,b,1);
                        break;
                    case 'lights':
                        var hexy=hexFromRGB(r,g,b);
                        $(".sp-input").val('#'+hexy);
                        $(".sp-input").change();
                        $("#red").slider("value",r)
                        $("#green").slider("value",g)
                        $("#blue").slider("value",b)
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
    var alarmhour=0;
    var alarmminutes=0;
    $(".timepicker").timepicker({
		interval: 10,
		minTime: '4:00',
		maxTime: '7:00',
		defaultTime: '5:00',
		startTime: '5:00',
        dynamic: false,
        change: function(time) {
            alarmhour=time.getHours();
            alarmminutes=time.getMinutes();
        }
    });
	$( "#red, #green, #blue" ).slider({
	  orientation: "horizontal",
	  range: "min",
	  max: 255,
	  value: 0,
	  slide: slideWrapper,
	  change: slideWrapper
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

    $('#b2').trigger("click");
      $(window).resize(function(){
          var left=$(".sp-container").outerWidth();
          $('.ui-slider,#swatch').css('margin-left',left+25);
      });
   // clicking software button 
    $("#soft").click( function(){
        software=1;
        $("#soft").addClass('btn-primary');
        $("#soft").removeClass('btn-default');
        $('#hard').addClass('btn-default');
        $('#hard').removeClass('btn-primary');
        $('.ui-slider,.sp-container').css('pointer-events','auto');
        updateAll(0,0,0,'slider');
    });

    $("#hard").click( function(){
        software=0;
        $("#hard").addClass('btn-primary');
        $("#hard").removeClass('btn-default');
        $('#soft').addClass('btn-default');
        $('#soft').removeClass('btn-primary');
        $('.ui-slider,.sp-container').css('pointer-events','none');
        socket.emit('apply',0,0,0,software);
    } );
    socket.on('supply', function(r,g,b){
        updateAll(r,g,b,'lights');
        console.log('client',r,g,b);
    });
    var alarmButton = document.getElementById("timeButton");
    alarmButton.onclick=function(){
        console.log("bloppity doop");
        var alarm=document.getElementById("myTime");
        console.log(alarm);
        socket.emit('nappy',alarmhour,alarmminutes);
    };
});
