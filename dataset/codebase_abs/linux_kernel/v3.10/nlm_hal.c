void F_1 ( int V_1 )
{
struct V_2 * V_3 ;
V_3 = F_2 ( V_1 ) ;
V_3 -> V_4 = F_3 ( V_1 ) ;
V_3 -> V_5 = F_4 ( V_1 ) ;
V_3 -> V_6 = F_5 () & ( ~ ( ( 1 << 12 ) - 1 ) ) ;
F_6 ( & V_3 -> V_7 ) ;
}
int F_7 ( int V_8 )
{
T_1 V_9 ;
int V_10 , V_11 ;
switch ( V_8 ) {
case V_12 :
V_10 = F_8 ( 0 ) ;
break;
case V_13 :
V_10 = F_9 ( 0 ) ;
break;
case V_14 :
V_10 = F_10 ( 0 ) ;
break;
case V_15 :
V_10 = F_11 ( 0 ) ;
break;
case V_16 :
V_10 = F_12 ( 0 ) ;
break;
case V_17 :
V_10 = F_13 ( 0 ) ;
break;
case V_18 :
V_10 = F_14 ( 0 ) ;
break;
case V_19 :
V_10 = F_15 ( 0 ) ;
break;
case V_20 :
V_10 = F_16 ( 0 ) ;
break;
case V_21 :
V_10 = F_17 ( 0 ) ;
break;
case V_22 :
V_10 = F_18 ( 0 ) ;
break;
default:
V_10 = 0 ;
break;
}
if ( V_10 != 0 ) {
V_9 = F_19 ( V_10 ) ;
V_11 = F_20 ( V_9 , V_23 ) & 0xffff ;
if ( V_8 == V_22 )
V_11 = V_11 + 1 ;
} else if ( V_8 >= V_24 && V_8 <= V_25 ) {
V_11 = F_21 ( V_8 - V_24 ) ;
} else {
V_11 = - 1 ;
}
return V_11 ;
}
unsigned int F_22 ( int V_1 , int V_26 )
{
unsigned int V_27 , V_28 , V_29 , V_30 ;
unsigned int V_31 , V_32 , V_33 ;
T_1 V_34 , V_4 ;
V_4 = F_2 ( V_1 ) -> V_4 ;
V_31 = F_23 ( V_4 , V_35 ) ;
V_32 = F_23 ( V_4 , V_36 ) ;
V_27 = ( ( V_31 >> 10 ) & 0x7f ) + 1 ;
V_28 = ( ( V_31 >> 8 ) & 0x3 ) + 1 ;
V_30 = ( ( V_31 >> 30 ) & 0x3 ) + 1 ;
V_29 = ( ( V_32 >> ( V_26 * 4 ) ) & 0xf ) + 1 ;
V_34 = 800000000ULL * V_27 ;
V_33 = 3 * V_28 * V_30 * V_29 ;
F_24 ( V_34 , V_33 ) ;
return ( unsigned int ) V_34 ;
}
unsigned int F_25 ( void )
{
return F_22 ( 0 , 0 ) ;
}
