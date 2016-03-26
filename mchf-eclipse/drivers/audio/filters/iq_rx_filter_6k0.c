/************************************************************************************
**                                                                                 **
**                               mcHF QRP Transceiver                              **
**                             K Atanassov - M0NKA 2014                            **
**                                                                                 **
**---------------------------------------------------------------------------------**
**                                                                                 **
**  File name:                                                                     **
**  Description:                                                                   **
**  Last Modified:                                                                 **
**  Licence:		CC BY-NC-SA 3.0                                                **
************************************************************************************/

#include "filters.h"

/*
 	 * Hilbert 0 Degree, "Phase-added" bandpass filter
     * Kaiser Window FIR Filter, Beta = 5.75, Raised Cosine = 0.91
     * Fc = 2.26 kHz (0.094)
     * BW = 7.25 kHz (0.302)
     * 89 Taps
     *
     * 20140926 by KA7OEI using Iowa Hills Hilbert Filter Designer
     *
     * This filter used in the "6 kHz" RX filter position of the mcHF
*/

const float i_rx_6k_coeffs[I_NUM_TAPS] =
{
		-0.000022682373717438,
		0.000038238204564056,
		0.000106103474329490,
		0.000112588277224745,
		-0.000001044056524999,
		-0.000220094982327220,
		-0.000424274911375459,
		-0.000434788035699723,
		-0.000139453017934211,
		0.000375971408919194,
		0.000801147757062312,
		0.000749955332343770,
		0.000038057970465913,
		-0.001083544085482150,
		-0.001944999287130160,
		-0.001808699680722850,
		-0.000405941583674816,
		0.001688437310558100,
		0.003186391338558470,
		0.002794418308157900,
		0.000158741803918238,
		-0.003576377418073650,
		-0.006125801172151690,
		-0.005350680308136920,
		-0.000819334976691253,
		0.005395383587742980,
		0.009458815112605070,
		0.007953102693187210,
		0.000355148270524342,
		-0.009820167110937010,
		-0.016337096498702600,
		-0.013745297780700800,
		-0.001267420288973250,
		0.015418941709472400,
		0.026187850069946600,
		0.021884307313133900,
		0.000547853915223056,
		-0.029198332931040700,
		-0.050220164915604400,
		-0.044280778159989200,
		-0.001564103360239580,
		0.072560909705731900,
		0.157505034279737000,
		0.224922981969257000,
		0.250563014502060000,
		0.224922981969261000,
		0.157505034279743000,
		0.072560909705738800,
		-0.001564103360234500,
		-0.044280778159987100,
		-0.050220164915605100,
		-0.029198332931042900,
		0.000547853915220766,
		0.021884307313132800,
		0.026187850069946800,
		0.015418941709473600,
		-0.001267420288971990,
		-0.013745297780700100,
		-0.016337096498702700,
		-0.009820167110937610,
		0.000355148270523721,
		0.007953102693186970,
		0.009458815112605290,
		0.005395383587743470,
		-0.000819334976690837,
		-0.005350680308136820,
		-0.006125801172151940,
		-0.003576377418074090,
		0.000158741803917861,
		0.002794418308157760,
		0.003186391338558600,
		0.001688437310558400,
		-0.000405941583674517,
		-0.001808699680722680,
		-0.001944999287130150,
		-0.001083544085482270,
		0.000038057970465767,
		0.000749955332343670,
		0.000801147757062286,
		0.000375971408919226,
		-0.000139453017934159,
		-0.000434788035699684,
		-0.000424274911375447,
		-0.000220094982327228,
		-0.000001044056525015,
		0.000112588277224733,
		0.000106103474329485,
		0.000038238204564058,
		-0.000022682373717435
};

/*
 	 * Hilbert -90 Degree, "Phase-added" bandpass filter
     * Kaiser Window FIR Filter, Beta = 5.75, Raised Cosine = 0.91
     * Fc = 2.26 kHz (0.094)
     * BW = 7.25 kHz (0.302)
     * 89 Taps
     *
     * 2015024 by KA7OEI using Iowa Hills Hilbert Filter Designer
     *
     * This filter used in the "6 kHz" RX filter position of the mcHF
*/

const float q_rx_6k_coeffs[Q_NUM_TAPS] =
{
		-0.000251931484270499,
		-0.000330908629757323,
		-0.000355443802758868,
		-0.000326647521596476,
		-0.000313056072482740,
		-0.000429999933656398,
		-0.000761888781710813,
		-0.001268763017888730,
		-0.001753908973141430,
		-0.001951950810461460,
		-0.001718905571331460,
		-0.001209709663176470,
		-0.000889821694094009,
		-0.001301280134404110,
		-0.002671986166595300,
		-0.004617141299020820,
		-0.006201300063194040,
		-0.006443887420058640,
		-0.005037296305177990,
		-0.002807028332953210,
		-0.001485414108910350,
		-0.002748574672629210,
		-0.006995936221018900,
		-0.012682276326935200,
		-0.016844647126325300,
		-0.016787345388718400,
		-0.012052658960439200,
		-0.005370615878111070,
		-0.001655153218315580,
		-0.005231374836071520,
		-0.016740015287944800,
		-0.031739396789423500,
		-0.042370369607316100,
		-0.041739570722183300,
		-0.028820366700062200,
		-0.010846846796045200,
		-0.001106937113796690,
		-0.012453220056498800,
		-0.049497158956864000,
		-0.103757451754876000,
		-0.155023969685509000,
		-0.179173770261190000,
		-0.159159400457769000,
		-0.093838603694072800,
		-0.000000000000004019,
		0.093838603694066000,
		0.159159400457765000,
		0.179173770261190000,
		0.155023969685512000,
		0.103757451754880000,
		0.049497158956867900,
		0.012453220056500900,
		0.001106937113796700,
		0.010846846796043900,
		0.028820366700060700,
		0.041739570722182600,
		0.042370369607316400,
		0.031739396789424500,
		0.016740015287945900,
		0.005231374836072130,
		0.001655153218315570,
		0.005370615878110630,
		0.012052658960438800,
		0.016787345388718200,
		0.016844647126325500,
		0.012682276326935600,
		0.006995936221019260,
		0.002748574672629360,
		0.001485414108910250,
		0.002807028332952960,
		0.005037296305177730,
		0.006443887420058500,
		0.006201300063194050,
		0.004617141299020940,
		0.002671986166595440,
		0.001301280134404200,
		0.000889821694094027,
		0.001209709663176440,
		0.001718905571331410,
		0.001951950810461430,
		0.001753908973141430,
		0.001268763017888750,
		0.000761888781710832,
		0.000429999933656409,
		0.000313056072482743,
		0.000326647521596474,
		0.000355443802758867,
		0.000330908629757325,
		0.000251931484270503
};
// -89.5 degrees
const float q_rx_6k_coeffs_minus[Q_NUM_TAPS] =
{
		-0.000252119559524393,
		-0.000330562893588455,
		-0.000354505810723617,
		-0.000325654118935668,
		-0.000313053288650705,
		-0.000431901349565525,
		-0.000765556665694554,
		-0.001272503268394990,
		-0.001755057494010780,
		-0.001948600811246920,
		-0.001711859763358530,
		-0.001203129230539380,
		-0.000889456316800921,
		-0.001310671902121530,
		-0.002688831958909410,
		-0.004632725662095390,
		-0.006204601771576450,
		-0.006428931147220710,
		-0.005009341418180730,
		-0.002782573433277790,
		-0.001483974583790400,
		-0.002779632107550740,
		-0.007049046141172680,
		-0.012728416647282000,
		-0.016851146890332900,
		-0.016739697145158900,
		-0.011969784850311300,
		-0.005301114957808450,
		-0.001651995919482920,
		-0.005316741530465360,
		-0.016881728623410900,
		-0.031857957976292400,
		-0.042379804897882500,
		-0.041603638084121000,
		-0.028591092544637400,
		-0.010655752456709900,
		-0.001102121534727870,
		-0.012707158806809600,
		-0.049932859589912200,
		-0.104139341976065000,
		-0.155031714675862000,
		-0.178534731518110000,
		-0.157780984823797000,
		-0.091875239968751500,
		0.002183209546739060,
		0.095794844803425300,
		0.160525735442180000,
		0.179799209207323000,
		0.155004457936518000,
		0.103367686049051000,
		0.049057701349178400,
		0.012198336071495000,
		0.001111668673201480,
		0.011037117828967000,
		0.029047453307975200,
		0.041872335208535800,
		0.042357718285617900,
		0.031618426492388800,
		0.016597031337877600,
		0.005145611065502340,
		0.001658184886328200,
		0.005439709153447610,
		0.012134618239594000,
		0.016833719425186700,
		0.016836868805862700,
		0.012635173385873600,
		0.006942295289479610,
		0.002717308613100630,
		0.001486740886889630,
		0.002831270171222710,
		0.005064868847109580,
		0.006458354583579070,
		0.006197527658562170,
		0.004601206481836660,
		0.002654937562958780,
		0.001291789595836720,
		0.000890119531398750,
		0.001216198275421750,
		0.001725820909500050,
		0.001955152651077570,
		0.001752627325610380,
		0.001264926464673720,
		0.000758163068209342,
		0.000428065879533683,
		0.000313035094471666,
		0.000327616130784664,
		0.000356354815602149,
		0.000331229249023390,
		0.000251724286702972
};
// -90.5 degrees
const float q_rx_6k_coeffs_plus[Q_NUM_TAPS] =
{
		-0.000251724286702971,
		-0.000331229249023393,
		-0.000356354815602158,
		-0.000327616130784674,
		-0.000313035094471670,
		-0.000428065879533675,
		-0.000758163068209321,
		-0.001264926464673700,
		-0.001752627325610380,
		-0.001955152651077590,
		-0.001725820909500100,
		-0.001216198275421790,
		-0.000890119531398752,
		-0.001291789595836650,
		-0.002654937562958660,
		-0.004601206481836540,
		-0.006197527658562120,
		-0.006458354583579150,
		-0.005064868847109760,
		-0.002831270171222870,
		-0.001486740886889640,
		-0.002717308613100390,
		-0.006942295289479190,
		-0.012635173385873200,
		-0.016836868805862600,
		-0.016833719425187000,
		-0.012134618239594600,
		-0.005439709153448130,
		-0.001658184886328270,
		-0.005145611065501760,
		-0.016597031337876600,
		-0.031618426492387800,
		-0.042357718285617600,
		-0.041872335208536500,
		-0.029047453307976600,
		-0.011037117828968300,
		-0.001111668673201590,
		-0.012198336071493100,
		-0.049057701349174600,
		-0.103367686049046000,
		-0.155004457936514000,
		-0.179799209207323000,
		-0.160525735442183000,
		-0.095794844803431900,
		-0.002183209546746930,
		0.091875239968744800,
		0.157780984823794000,
		0.178534731518110000,
		0.155031714675865000,
		0.104139341976070000,
		0.049932859589916000,
		0.012707158806811500,
		0.001102121534727800,
		0.010655752456708600,
		0.028591092544635900,
		0.041603638084120300,
		0.042379804897882800,
		0.031857957976293400,
		0.016881728623412000,
		0.005316741530465960,
		0.001651995919482860,
		0.005301114957807940,
		0.011969784850310700,
		0.016739697145158700,
		0.016851146890333000,
		0.012728416647282400,
		0.007049046141173090,
		0.002779632107550980,
		0.001483974583790400,
		0.002782573433277620,
		0.005009341418180540,
		0.006428931147220630,
		0.006204601771576490,
		0.004632725662095510,
		0.002688831958909540,
		0.001310671902121600,
		0.000889456316800921,
		0.001203129230539330,
		0.001711859763358480,
		0.001948600811246900,
		0.001755057494010780,
		0.001272503268395010,
		0.000765556665694575,
		0.000431901349565534,
		0.000313053288650701,
		0.000325654118935657,
		0.000354505810723609,
		0.000330562893588452,
		0.000252119559524394
};
