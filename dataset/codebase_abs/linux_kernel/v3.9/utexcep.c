const char * F_1 ( T_1 V_1 )
{
const char * V_2 = NULL ;
F_2 () ;
V_2 = F_3 ( V_1 ) ;
if ( ! V_2 ) {
F_4 ( ( V_3 ,
L_1 , V_1 ) ) ;
V_2 = L_2 ;
}
return ( F_5 ( const char , V_2 ) ) ;
}
const char * F_3 ( T_1 V_1 )
{
T_2 V_4 ;
const char * V_2 = NULL ;
F_2 () ;
V_4 = ( V_1 & ~ V_5 ) ;
switch ( V_1 & V_5 ) {
case V_6 :
if ( V_4 <= V_7 ) {
V_2 = V_8 [ V_4 ] ;
}
break;
case V_9 :
if ( V_4 <= V_10 ) {
V_2 = V_11 [ V_4 ] ;
}
break;
case V_12 :
if ( V_4 <= V_13 ) {
V_2 = V_14 [ V_4 ] ;
}
break;
case V_15 :
if ( V_4 <= V_16 ) {
V_2 = V_17 [ V_4 ] ;
}
break;
case V_18 :
if ( V_4 <= V_19 ) {
V_2 = V_20 [ V_4 ] ;
}
break;
default:
break;
}
return ( F_5 ( const char , V_2 ) ) ;
}
