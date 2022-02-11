const char * F_1 ( T_1 V_1 )
{
const struct V_2 * V_3 ;
F_2 () ;
V_3 = F_3 ( V_1 ) ;
if ( ! V_3 ) {
F_4 ( ( V_4 ,
L_1 , V_1 ) ) ;
return ( L_2 ) ;
}
return ( V_3 -> V_5 ) ;
}
const struct V_2 * F_3 ( T_1 V_1 )
{
T_2 V_6 ;
const struct V_2 * V_3 = NULL ;
F_2 () ;
V_6 = ( V_1 & ~ V_7 ) ;
switch ( V_1 & V_7 ) {
case V_8 :
if ( V_6 <= V_9 ) {
V_3 = & V_10 [ V_6 ] ;
}
break;
case V_11 :
if ( V_6 <= V_12 ) {
V_3 = & V_13 [ V_6 ] ;
}
break;
case V_14 :
if ( V_6 <= V_15 ) {
V_3 = & V_16 [ V_6 ] ;
}
break;
case V_17 :
if ( V_6 <= V_18 ) {
V_3 = & V_19 [ V_6 ] ;
}
break;
case V_20 :
if ( V_6 <= V_21 ) {
V_3 = & V_22 [ V_6 ] ;
}
break;
default:
break;
}
if ( ! V_3 || ! V_3 -> V_5 ) {
return ( NULL ) ;
}
return ( V_3 ) ;
}
