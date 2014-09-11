<?xml version="1.0" encoding="utf-8"?>
<!DOCTYPE eagle SYSTEM "eagle.dtd">
<eagle version="7.1.0">
<drawing>
<settings>
<setting alwaysvectorfont="no"/>
<setting verticaltext="up"/>
</settings>
<grid distance="0.1" unitdist="inch" unit="inch" style="lines" multiple="1" display="no" altdistance="0.01" altunitdist="inch" altunit="inch"/>
<layers>
<layer number="1" name="Top" color="4" fill="1" visible="no" active="no"/>
<layer number="16" name="Bottom" color="1" fill="1" visible="no" active="no"/>
<layer number="17" name="Pads" color="2" fill="1" visible="no" active="no"/>
<layer number="18" name="Vias" color="2" fill="1" visible="no" active="no"/>
<layer number="19" name="Unrouted" color="6" fill="1" visible="no" active="no"/>
<layer number="20" name="Dimension" color="15" fill="1" visible="no" active="no"/>
<layer number="21" name="tPlace" color="7" fill="1" visible="no" active="no"/>
<layer number="22" name="bPlace" color="7" fill="1" visible="no" active="no"/>
<layer number="23" name="tOrigins" color="15" fill="1" visible="no" active="no"/>
<layer number="24" name="bOrigins" color="15" fill="1" visible="no" active="no"/>
<layer number="25" name="tNames" color="7" fill="1" visible="no" active="no"/>
<layer number="26" name="bNames" color="7" fill="1" visible="no" active="no"/>
<layer number="27" name="tValues" color="7" fill="1" visible="no" active="no"/>
<layer number="28" name="bValues" color="7" fill="1" visible="no" active="no"/>
<layer number="29" name="tStop" color="7" fill="3" visible="no" active="no"/>
<layer number="30" name="bStop" color="7" fill="6" visible="no" active="no"/>
<layer number="31" name="tCream" color="7" fill="4" visible="no" active="no"/>
<layer number="32" name="bCream" color="7" fill="5" visible="no" active="no"/>
<layer number="33" name="tFinish" color="6" fill="3" visible="no" active="no"/>
<layer number="34" name="bFinish" color="6" fill="6" visible="no" active="no"/>
<layer number="35" name="tGlue" color="7" fill="4" visible="no" active="no"/>
<layer number="36" name="bGlue" color="7" fill="5" visible="no" active="no"/>
<layer number="37" name="tTest" color="7" fill="1" visible="no" active="no"/>
<layer number="38" name="bTest" color="7" fill="1" visible="no" active="no"/>
<layer number="39" name="tKeepout" color="4" fill="11" visible="no" active="no"/>
<layer number="40" name="bKeepout" color="1" fill="11" visible="no" active="no"/>
<layer number="41" name="tRestrict" color="4" fill="10" visible="no" active="no"/>
<layer number="42" name="bRestrict" color="1" fill="10" visible="no" active="no"/>
<layer number="43" name="vRestrict" color="2" fill="10" visible="no" active="no"/>
<layer number="44" name="Drills" color="7" fill="1" visible="no" active="no"/>
<layer number="45" name="Holes" color="7" fill="1" visible="no" active="no"/>
<layer number="46" name="Milling" color="3" fill="1" visible="no" active="no"/>
<layer number="47" name="Measures" color="7" fill="1" visible="no" active="no"/>
<layer number="48" name="Document" color="7" fill="1" visible="no" active="no"/>
<layer number="49" name="Reference" color="7" fill="1" visible="no" active="no"/>
<layer number="50" name="dxf" color="7" fill="1" visible="no" active="no"/>
<layer number="51" name="tDocu" color="7" fill="1" visible="no" active="no"/>
<layer number="52" name="bDocu" color="7" fill="1" visible="no" active="no"/>
<layer number="53" name="tGND_GNDA" color="7" fill="9" visible="no" active="no"/>
<layer number="54" name="bGND_GNDA" color="1" fill="9" visible="no" active="no"/>
<layer number="56" name="wert" color="7" fill="1" visible="no" active="no"/>
<layer number="90" name="Modules" color="5" fill="1" visible="yes" active="yes"/>
<layer number="91" name="Nets" color="2" fill="1" visible="yes" active="yes"/>
<layer number="92" name="Busses" color="1" fill="1" visible="yes" active="yes"/>
<layer number="93" name="Pins" color="2" fill="1" visible="yes" active="yes"/>
<layer number="94" name="Symbols" color="4" fill="1" visible="yes" active="yes"/>
<layer number="95" name="Names" color="7" fill="1" visible="yes" active="yes"/>
<layer number="96" name="Values" color="7" fill="1" visible="yes" active="yes"/>
<layer number="97" name="Info" color="7" fill="1" visible="yes" active="yes"/>
<layer number="98" name="Guide" color="6" fill="1" visible="yes" active="yes"/>
<layer number="100" name="Muster" color="7" fill="1" visible="no" active="no"/>
<layer number="101" name="Patch_Top" color="12" fill="4" visible="yes" active="yes"/>
<layer number="102" name="Vscore" color="7" fill="1" visible="yes" active="yes"/>
<layer number="104" name="Name" color="7" fill="1" visible="yes" active="yes"/>
<layer number="116" name="Patch_BOT" color="9" fill="4" visible="yes" active="yes"/>
<layer number="121" name="_tsilk" color="7" fill="1" visible="yes" active="yes"/>
<layer number="122" name="_bsilk" color="7" fill="1" visible="yes" active="yes"/>
<layer number="151" name="HeatSink" color="7" fill="1" visible="yes" active="yes"/>
<layer number="200" name="200bmp" color="1" fill="10" visible="no" active="no"/>
<layer number="201" name="201bmp" color="2" fill="1" visible="no" active="no"/>
<layer number="202" name="202bmp" color="3" fill="1" visible="no" active="no"/>
<layer number="250" name="Descript" color="3" fill="1" visible="no" active="no"/>
<layer number="251" name="SMDround" color="12" fill="11" visible="no" active="no"/>
<layer number="254" name="cooling" color="7" fill="1" visible="yes" active="yes"/>
</layers>
<schematic xreflabel="%F%N/%S.%C%R" xrefpart="/%S.%C%R">
<libraries>
<library name="MyPOW">
<packages>
</packages>
<symbols>
<symbol name="COM">
<wire x1="-1.524" y1="0" x2="1.524" y2="0" width="0.254" layer="94"/>
<wire x1="-1.016" y1="-0.508" x2="1.016" y2="-0.508" width="0.254" layer="94"/>
<wire x1="-0.508" y1="-1.016" x2="0.508" y2="-1.016" width="0.254" layer="94"/>
<wire x1="-0.127" y1="-1.524" x2="0.127" y2="-1.524" width="0.254" layer="94"/>
<pin name="COM" x="0" y="2.54" visible="off" length="short" direction="sup" rot="R270"/>
</symbol>
</symbols>
<devicesets>
<deviceset name="COM">
<gates>
<gate name="G$1" symbol="COM" x="0" y="-2.54"/>
</gates>
<devices>
<device name="">
<technologies>
<technology name=""/>
</technologies>
</device>
</devices>
</deviceset>
</devicesets>
</library>
<library name="MyCON2">
<packages>
<package name="HEAD15-NOSS">
<wire x1="-1.27" y1="-1.27" x2="-1.27" y2="1.27" width="0.127" layer="51"/>
<wire x1="-1.27" y1="1.27" x2="36.83" y2="1.27" width="0.127" layer="51"/>
<wire x1="36.83" y1="1.27" x2="36.83" y2="-1.27" width="0.127" layer="51"/>
<wire x1="36.83" y1="-1.27" x2="-1.27" y2="-1.27" width="0.127" layer="51"/>
<pad name="1" x="0" y="0" drill="0.9144" diameter="1.778" shape="square"/>
<pad name="2" x="2.54" y="0" drill="0.9144" diameter="1.778"/>
<pad name="3" x="5.08" y="0" drill="0.9144" diameter="1.778"/>
<pad name="4" x="7.62" y="0" drill="0.9144" diameter="1.778"/>
<pad name="5" x="10.16" y="0" drill="0.9144" diameter="1.778"/>
<pad name="6" x="12.7" y="0" drill="0.9144" diameter="1.778"/>
<pad name="7" x="15.24" y="0" drill="0.9144" diameter="1.778"/>
<pad name="8" x="17.78" y="0" drill="0.9144" diameter="1.778"/>
<pad name="9" x="20.32" y="0" drill="0.9144" diameter="1.778"/>
<pad name="10" x="22.86" y="0" drill="0.9144" diameter="1.778"/>
<pad name="11" x="25.4" y="0" drill="0.9144" diameter="1.778"/>
<pad name="12" x="27.94" y="0" drill="0.9144" diameter="1.778"/>
<pad name="13" x="30.48" y="0" drill="0.9144" diameter="1.778"/>
<pad name="14" x="33.02" y="0" drill="0.9144" diameter="1.778"/>
<pad name="15" x="35.56" y="0" drill="0.9144" diameter="1.778"/>
<text x="-1.27" y="1.651" size="0.6096" layer="25">&gt;NAME</text>
<text x="-1.2446" y="-2.1082" size="0.6096" layer="27">&gt;VALUE</text>
</package>
<package name="HEAD15-NOSS-1">
<wire x1="-1.27" y1="-1.27" x2="-1.27" y2="1.27" width="0.127" layer="51"/>
<wire x1="-1.27" y1="1.27" x2="36.83" y2="1.27" width="0.127" layer="51"/>
<wire x1="36.83" y1="1.27" x2="36.83" y2="-1.27" width="0.127" layer="51"/>
<wire x1="36.83" y1="-1.27" x2="-1.27" y2="-1.27" width="0.127" layer="51"/>
<pad name="1" x="0" y="0" drill="0.9144" diameter="1.778"/>
<pad name="2" x="2.54" y="0" drill="0.9144" diameter="1.778"/>
<pad name="3" x="5.08" y="0" drill="0.9144" diameter="1.778"/>
<pad name="4" x="7.62" y="0" drill="0.9144" diameter="1.778"/>
<pad name="5" x="10.16" y="0" drill="0.9144" diameter="1.778"/>
<pad name="6" x="12.7" y="0" drill="0.9144" diameter="1.778"/>
<pad name="7" x="15.24" y="0" drill="0.9144" diameter="1.778"/>
<pad name="8" x="17.78" y="0" drill="0.9144" diameter="1.778"/>
<pad name="9" x="20.32" y="0" drill="0.9144" diameter="1.778"/>
<pad name="10" x="22.86" y="0" drill="0.9144" diameter="1.778"/>
<pad name="11" x="25.4" y="0" drill="0.9144" diameter="1.778"/>
<pad name="12" x="27.94" y="0" drill="0.9144" diameter="1.778"/>
<pad name="13" x="30.48" y="0" drill="0.9144" diameter="1.778"/>
<pad name="14" x="33.02" y="0" drill="0.9144" diameter="1.778"/>
<pad name="15" x="35.56" y="0" drill="0.9144" diameter="1.778"/>
<text x="-1.27" y="1.5748" size="0.6096" layer="25">&gt;NAME</text>
<text x="-1.2954" y="-2.1082" size="0.6096" layer="27">&gt;VALUE</text>
</package>
</packages>
<symbols>
<symbol name="HEAD15-NOSS">
<wire x1="-2.54" y1="-20.32" x2="5.08" y2="-20.32" width="0.254" layer="94"/>
<wire x1="5.08" y1="-20.32" x2="5.08" y2="20.32" width="0.254" layer="94"/>
<wire x1="5.08" y1="20.32" x2="-2.54" y2="20.32" width="0.254" layer="94"/>
<wire x1="-2.54" y1="20.32" x2="-2.54" y2="-20.32" width="0.254" layer="94"/>
<text x="-2.54" y="-22.86" size="1.27" layer="96">&gt;VALUE</text>
<text x="-2.54" y="21.336" size="1.27" layer="95">&gt;NAME</text>
<pin name="1" x="10.16" y="17.78" visible="pin" length="middle" direction="pas" rot="R180"/>
<pin name="2" x="10.16" y="15.24" visible="pin" length="middle" direction="pas" rot="R180"/>
<pin name="3" x="10.16" y="12.7" visible="pin" length="middle" direction="pas" rot="R180"/>
<pin name="4" x="10.16" y="10.16" visible="pin" length="middle" direction="pas" rot="R180"/>
<pin name="5" x="10.16" y="7.62" visible="pin" length="middle" direction="pas" rot="R180"/>
<pin name="6" x="10.16" y="5.08" visible="pin" length="middle" direction="pas" rot="R180"/>
<pin name="7" x="10.16" y="2.54" visible="pin" length="middle" direction="pas" rot="R180"/>
<pin name="8" x="10.16" y="0" visible="pin" length="middle" direction="pas" rot="R180"/>
<pin name="9" x="10.16" y="-2.54" visible="pin" length="middle" direction="pas" rot="R180"/>
<pin name="10" x="10.16" y="-5.08" visible="pin" length="middle" direction="pas" rot="R180"/>
<pin name="11" x="10.16" y="-7.62" visible="pin" length="middle" direction="pas" rot="R180"/>
<pin name="12" x="10.16" y="-10.16" visible="pin" length="middle" direction="pas" rot="R180"/>
<pin name="13" x="10.16" y="-12.7" visible="pin" length="middle" direction="pas" rot="R180"/>
<pin name="14" x="10.16" y="-15.24" visible="pin" length="middle" direction="pas" rot="R180"/>
<pin name="15" x="10.16" y="-17.78" visible="pin" length="middle" direction="pas" rot="R180"/>
</symbol>
</symbols>
<devicesets>
<deviceset name="HEAD15-NOSS" prefix="J">
<gates>
<gate name="G$1" symbol="HEAD15-NOSS" x="0" y="0"/>
</gates>
<devices>
<device name="" package="HEAD15-NOSS">
<connects>
<connect gate="G$1" pin="1" pad="1"/>
<connect gate="G$1" pin="10" pad="10"/>
<connect gate="G$1" pin="11" pad="11"/>
<connect gate="G$1" pin="12" pad="12"/>
<connect gate="G$1" pin="13" pad="13"/>
<connect gate="G$1" pin="14" pad="14"/>
<connect gate="G$1" pin="15" pad="15"/>
<connect gate="G$1" pin="2" pad="2"/>
<connect gate="G$1" pin="3" pad="3"/>
<connect gate="G$1" pin="4" pad="4"/>
<connect gate="G$1" pin="5" pad="5"/>
<connect gate="G$1" pin="6" pad="6"/>
<connect gate="G$1" pin="7" pad="7"/>
<connect gate="G$1" pin="8" pad="8"/>
<connect gate="G$1" pin="9" pad="9"/>
</connects>
<technologies>
<technology name=""/>
</technologies>
</device>
</devices>
</deviceset>
<deviceset name="HEAD15-NOSS-1" prefix="J">
<gates>
<gate name="G$1" symbol="HEAD15-NOSS" x="0" y="0"/>
</gates>
<devices>
<device name="" package="HEAD15-NOSS-1">
<connects>
<connect gate="G$1" pin="1" pad="1"/>
<connect gate="G$1" pin="10" pad="10"/>
<connect gate="G$1" pin="11" pad="11"/>
<connect gate="G$1" pin="12" pad="12"/>
<connect gate="G$1" pin="13" pad="13"/>
<connect gate="G$1" pin="14" pad="14"/>
<connect gate="G$1" pin="15" pad="15"/>
<connect gate="G$1" pin="2" pad="2"/>
<connect gate="G$1" pin="3" pad="3"/>
<connect gate="G$1" pin="4" pad="4"/>
<connect gate="G$1" pin="5" pad="5"/>
<connect gate="G$1" pin="6" pad="6"/>
<connect gate="G$1" pin="7" pad="7"/>
<connect gate="G$1" pin="8" pad="8"/>
<connect gate="G$1" pin="9" pad="9"/>
</connects>
<technologies>
<technology name=""/>
</technologies>
</device>
</devices>
</deviceset>
</devicesets>
</library>
<library name="docu-dummy">
<description>Dummy symbols</description>
<packages>
</packages>
<symbols>
<symbol name="POTI">
<wire x1="-0.762" y1="-3.81" x2="0" y2="-3.81" width="0.254" layer="94"/>
<wire x1="0.762" y1="3.81" x2="0" y2="3.81" width="0.254" layer="94"/>
<wire x1="-0.762" y1="3.81" x2="-0.762" y2="-3.81" width="0.254" layer="94"/>
<wire x1="0.762" y1="-3.81" x2="0.762" y2="3.81" width="0.254" layer="94"/>
<wire x1="2.54" y1="0" x2="1.651" y2="0" width="0.1524" layer="94"/>
<wire x1="1.651" y1="0" x2="-2.54" y2="2.54" width="0.1524" layer="94"/>
<wire x1="-2.54" y1="2.54" x2="-1.778" y2="1.524" width="0.1524" layer="94"/>
<wire x1="-1.778" y1="1.524" x2="-1.27" y2="2.286" width="0.1524" layer="94"/>
<wire x1="-2.54" y1="2.54" x2="-1.27" y2="2.286" width="0.1524" layer="94"/>
<wire x1="0" y1="3.81" x2="0" y2="5.08" width="0.1524" layer="94"/>
<wire x1="0" y1="3.81" x2="-0.762" y2="3.81" width="0.254" layer="94"/>
<wire x1="0" y1="-5.08" x2="0" y2="-3.81" width="0.1524" layer="94"/>
<wire x1="0" y1="-3.81" x2="0.762" y2="-3.81" width="0.254" layer="94"/>
</symbol>
</symbols>
<devicesets>
<deviceset name="POT" prefix="P">
<description>&lt;b&gt;POTENTIOMENTER&lt;/b&gt;</description>
<gates>
<gate name="G$1" symbol="POTI" x="0" y="0"/>
</gates>
<devices>
<device name="">
<technologies>
<technology name=""/>
</technologies>
</device>
</devices>
</deviceset>
</devicesets>
</library>
</libraries>
<attributes>
</attributes>
<variantdefs>
</variantdefs>
<classes>
<class number="0" name="default" width="0" drill="0">
</class>
</classes>
<parts>
<part name="J1" library="MyCON2" deviceset="HEAD15-NOSS" device=""/>
<part name="J2" library="MyCON2" deviceset="HEAD15-NOSS-1" device=""/>
<part name="P1" library="docu-dummy" deviceset="POT" device=""/>
<part name="P2" library="docu-dummy" deviceset="POT" device=""/>
<part name="P3" library="docu-dummy" deviceset="POT" device=""/>
<part name="U$4" library="MyPOW" deviceset="COM" device=""/>
<part name="U$1" library="MyPOW" deviceset="COM" device=""/>
</parts>
<sheets>
<sheet>
<plain>
<wire x1="35.56" y1="96.52" x2="55.88" y2="96.52" width="0.3048" layer="94"/>
<wire x1="35.56" y1="137.16" x2="40.64" y2="137.16" width="0.3048" layer="94"/>
<wire x1="40.64" y1="137.16" x2="50.8" y2="137.16" width="0.3048" layer="94"/>
<wire x1="50.8" y1="137.16" x2="55.88" y2="137.16" width="0.3048" layer="94"/>
<wire x1="50.8" y1="137.16" x2="40.64" y2="137.16" width="0.3048" layer="94" curve="-180"/>
<rectangle x1="7.62" y1="91.44" x2="83.82" y2="142.24" layer="97"/>
</plain>
<instances>
<instance part="J1" gate="G$1" x="33.02" y="116.84" rot="MR0"/>
<instance part="J2" gate="G$1" x="58.42" y="116.84"/>
<instance part="P1" gate="G$1" x="116.84" y="116.84"/>
<instance part="P2" gate="G$1" x="127" y="116.84"/>
<instance part="P3" gate="G$1" x="137.16" y="116.84"/>
<instance part="U$4" gate="G$1" x="71.12" y="137.16" rot="R180"/>
<instance part="U$1" gate="G$1" x="10.16" y="129.54" rot="R180"/>
</instances>
<busses>
</busses>
<nets>
<net name="D5" class="0">
<segment>
<wire x1="7.62" y1="116.84" x2="22.86" y2="116.84" width="0.1524" layer="91"/>
<label x="10.16" y="116.84" size="1.778" layer="95"/>
<pinref part="J1" gate="G$1" pin="8"/>
</segment>
</net>
<net name="D4" class="0">
<segment>
<wire x1="7.62" y1="119.38" x2="22.86" y2="119.38" width="0.1524" layer="91"/>
<label x="10.16" y="119.38" size="1.778" layer="95"/>
<pinref part="J1" gate="G$1" pin="7"/>
</segment>
</net>
<net name="D3" class="0">
<segment>
<wire x1="7.62" y1="121.92" x2="22.86" y2="121.92" width="0.1524" layer="91"/>
<label x="10.16" y="121.92" size="1.778" layer="95"/>
<pinref part="J1" gate="G$1" pin="6"/>
</segment>
</net>
<net name="D2" class="0">
<segment>
<wire x1="7.62" y1="124.46" x2="22.86" y2="124.46" width="0.1524" layer="91"/>
<label x="10.16" y="124.46" size="1.778" layer="95"/>
<pinref part="J1" gate="G$1" pin="5"/>
</segment>
</net>
<net name="RESET" class="0">
<segment>
<wire x1="68.58" y1="129.54" x2="83.82" y2="129.54" width="0.1524" layer="91"/>
<label x="71.12" y="129.54" size="1.778" layer="95"/>
<pinref part="J2" gate="G$1" pin="3"/>
</segment>
</net>
<net name="D1/TX" class="0">
<segment>
<wire x1="7.62" y1="134.62" x2="22.86" y2="134.62" width="0.1524" layer="91"/>
<label x="10.16" y="134.62" size="1.778" layer="95"/>
<pinref part="J1" gate="G$1" pin="1"/>
</segment>
</net>
<net name="D6" class="0">
<segment>
<wire x1="7.62" y1="114.3" x2="22.86" y2="114.3" width="0.1524" layer="91"/>
<label x="10.16" y="114.3" size="1.778" layer="95"/>
<pinref part="J1" gate="G$1" pin="9"/>
</segment>
</net>
<net name="D7" class="0">
<segment>
<wire x1="22.86" y1="111.76" x2="7.62" y2="111.76" width="0.1524" layer="91"/>
<label x="10.16" y="111.76" size="1.778" layer="95"/>
<pinref part="J1" gate="G$1" pin="10"/>
</segment>
</net>
<net name="D8" class="0">
<segment>
<wire x1="7.62" y1="109.22" x2="22.86" y2="109.22" width="0.1524" layer="91"/>
<label x="10.16" y="109.22" size="1.778" layer="95"/>
<pinref part="J1" gate="G$1" pin="11"/>
</segment>
</net>
<net name="D9" class="0">
<segment>
<wire x1="7.62" y1="106.68" x2="22.86" y2="106.68" width="0.1524" layer="91"/>
<label x="10.16" y="106.68" size="1.778" layer="95"/>
<pinref part="J1" gate="G$1" pin="12"/>
</segment>
</net>
<net name="D10" class="0">
<segment>
<wire x1="7.62" y1="104.14" x2="22.86" y2="104.14" width="0.1524" layer="91"/>
<label x="10.16" y="104.14" size="1.778" layer="95"/>
<pinref part="J1" gate="G$1" pin="13"/>
</segment>
</net>
<net name="D11/MOSI" class="0">
<segment>
<wire x1="7.62" y1="101.6" x2="22.86" y2="101.6" width="0.1524" layer="91"/>
<label x="10.16" y="101.6" size="1.778" layer="95"/>
<pinref part="J1" gate="G$1" pin="14"/>
</segment>
</net>
<net name="D12/MISO" class="0">
<segment>
<wire x1="7.62" y1="99.06" x2="22.86" y2="99.06" width="0.1524" layer="91"/>
<label x="10.16" y="99.06" size="1.778" layer="95"/>
<pinref part="J1" gate="G$1" pin="15"/>
</segment>
</net>
<net name="A3" class="0">
<segment>
<wire x1="68.58" y1="114.3" x2="83.82" y2="114.3" width="0.1524" layer="91"/>
<label x="71.12" y="114.3" size="1.778" layer="95"/>
<pinref part="J2" gate="G$1" pin="9"/>
</segment>
</net>
<net name="A4" class="0">
<segment>
<wire x1="68.58" y1="116.84" x2="83.82" y2="116.84" width="0.1524" layer="91"/>
<label x="71.12" y="116.84" size="1.778" layer="95"/>
<pinref part="J2" gate="G$1" pin="8"/>
</segment>
</net>
<net name="A5" class="0">
<segment>
<wire x1="68.58" y1="119.38" x2="83.82" y2="119.38" width="0.1524" layer="91"/>
<label x="71.12" y="119.38" size="1.778" layer="95"/>
<pinref part="J2" gate="G$1" pin="7"/>
</segment>
</net>
<net name="A6" class="0">
<segment>
<wire x1="68.58" y1="121.92" x2="83.82" y2="121.92" width="0.1524" layer="91"/>
<label x="71.12" y="121.92" size="1.778" layer="95"/>
<pinref part="J2" gate="G$1" pin="6"/>
</segment>
</net>
<net name="A7" class="0">
<segment>
<wire x1="68.58" y1="124.46" x2="83.82" y2="124.46" width="0.1524" layer="91"/>
<label x="71.12" y="124.46" size="1.778" layer="95"/>
<pinref part="J2" gate="G$1" pin="5"/>
</segment>
</net>
<net name="AREF" class="0">
<segment>
<wire x1="68.58" y1="104.14" x2="83.82" y2="104.14" width="0.1524" layer="91"/>
<label x="71.12" y="104.14" size="1.778" layer="95"/>
<pinref part="J2" gate="G$1" pin="13"/>
</segment>
</net>
<net name="D13/SCK" class="0">
<segment>
<wire x1="68.58" y1="99.06" x2="83.82" y2="99.06" width="0.1524" layer="91"/>
<label x="71.12" y="99.06" size="1.778" layer="95"/>
<pinref part="J2" gate="G$1" pin="15"/>
</segment>
</net>
<net name="COM" class="0">
<segment>
<pinref part="U$4" gate="G$1" pin="COM"/>
<wire x1="68.58" y1="134.62" x2="71.12" y2="134.62" width="0.1524" layer="91"/>
<pinref part="J2" gate="G$1" pin="1"/>
</segment>
</net>
<net name="D0/RX" class="0">
<segment>
<wire x1="7.62" y1="132.08" x2="22.86" y2="132.08" width="0.1524" layer="91"/>
<label x="10.16" y="132.08" size="1.778" layer="95"/>
<pinref part="J1" gate="G$1" pin="2"/>
</segment>
</net>
<net name="3V3" class="0">
<segment>
<pinref part="J2" gate="G$1" pin="14"/>
<wire x1="68.58" y1="101.6" x2="83.82" y2="101.6" width="0.1524" layer="91"/>
<label x="71.12" y="101.6" size="1.778" layer="95"/>
</segment>
</net>
<net name="VIN" class="0">
<segment>
<wire x1="68.58" y1="132.08" x2="83.82" y2="132.08" width="0.1524" layer="91"/>
<pinref part="J2" gate="G$1" pin="2"/>
<label x="71.12" y="132.08" size="1.778" layer="95"/>
</segment>
</net>
<net name="RES" class="0">
<segment>
<pinref part="J1" gate="G$1" pin="3"/>
<wire x1="22.86" y1="129.54" x2="12.7" y2="129.54" width="0.1524" layer="91"/>
<label x="15.24" y="129.54" size="1.778" layer="95"/>
</segment>
</net>
<net name="N$1" class="0">
<segment>
<wire x1="7.62" y1="127" x2="10.16" y2="127" width="0.1524" layer="91"/>
<pinref part="J1" gate="G$1" pin="4"/>
<pinref part="U$1" gate="G$1" pin="COM"/>
<wire x1="10.16" y1="127" x2="22.86" y2="127" width="0.1524" layer="91"/>
<junction x="10.16" y="127"/>
</segment>
</net>
<net name="B$1" class="0">
<segment>
<label x="71.12" y="106.68" size="1.778" layer="95"/>
<pinref part="J2" gate="G$1" pin="12"/>
<wire x1="83.82" y1="106.68" x2="68.58" y2="106.68" width="0.1524" layer="91"/>
</segment>
<segment>
<label x="71.12" y="109.22" size="1.778" layer="95"/>
<pinref part="J2" gate="G$1" pin="11"/>
<wire x1="68.58" y1="109.22" x2="83.82" y2="109.22" width="0.1524" layer="91"/>
</segment>
<segment>
<label x="71.12" y="111.76" size="1.778" layer="95"/>
<pinref part="J2" gate="G$1" pin="10"/>
<wire x1="83.82" y1="111.76" x2="68.58" y2="111.76" width="0.1524" layer="91"/>
</segment>
</net>
</nets>
</sheet>
</sheets>
</schematic>
</drawing>
</eagle>
