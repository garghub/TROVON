const struct V_1 * F_1 ( T_1 V_2 )
{
#ifdef F_2
const char * V_3 = L_1 ;
#endif
F_3 ( V_4 ) ;
if ( ! ( V_2 & 0xFF00 ) ) {
return ( & V_5
[ V_6 [ ( V_7 ) V_2 ] ] ) ;
}
if ( ( ( V_2 & 0xFF00 ) == V_8 ) &&
( ( ( V_7 ) V_2 ) <= V_9 ) ) {
return ( & V_5
[ V_10 [ ( V_7 ) V_2 ] ] ) ;
}
#if V_11 V_12 && V_11 F_2
#include "asldefine.h"
switch ( V_2 ) {
case V_13 :
V_3 = L_2 ;
break;
case V_14 :
V_3 = L_3 ;
break;
case V_15 :
V_3 = L_4 ;
break;
case V_16 :
V_3 = L_5 ;
break;
case V_17 :
V_3 = L_6 ;
break;
case V_18 :
V_3 = L_7 ;
break;
case V_19 :
V_3 = L_8 ;
break;
case V_20 :
V_3 = L_9 ;
break;
case V_21 :
V_3 = L_10 ;
break;
default:
break;
}
#endif
F_4 ( ( V_22 , L_11 , V_3 , V_2 ) ) ;
return ( & V_5 [ V_23 ] ) ;
}
char * F_5 ( T_1 V_2 )
{
#if V_11 ( V_24 ) || V_11 ( F_2 )
const struct V_1 * V_25 ;
V_25 = F_1 ( V_2 ) ;
return ( V_25 -> V_26 ) ;
#else
return ( L_12 ) ;
#endif
}
V_7 F_6 ( T_2 V_27 )
{
if ( V_27 <= V_28 ) {
return ( V_29 [ V_27 ] ) ;
}
return ( 0 ) ;
}
