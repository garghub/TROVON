static int F_1 ( int V_1 )
{
if ( V_1 & F_2 ( 14 ) )
return - ( 0x4000 - ( V_1 & 0x3FFF ) ) << 2 ;
else
return ( V_1 & 0x3FFF ) << 2 ;
}
static int F_3 ( struct V_2 * V_3 , T_1 V_4 , int * V_5 )
{
int V_6 ;
V_6 = F_4 ( V_3 , V_4 ) ;
if ( F_5 ( V_6 < 0 ) )
return V_6 ;
switch ( V_4 ) {
case V_7 :
V_6 = ( V_6 & 0x1FFF ) << 3 ;
* V_5 = ( V_6 * 1000 ) >> 7 ;
break;
case V_8 :
case V_9 :
* V_5 = F_1 ( V_6 ) * 1942 / ( 4 * 100 ) ;
break;
case V_10 :
* V_5 = ( F_1 ( V_6 ) * 30518 /
( 4 * 100 * 1000 ) ) + 2500 ;
break;
default:
return - V_11 ;
}
return 0 ;
}
static T_2 F_6 ( struct V_12 * V_13 ,
struct V_14 * V_15 , char * V_16 )
{
struct V_17 * V_18 = F_7 ( V_15 ) ;
int V_19 ;
int V_20 ;
V_20 = F_3 ( F_8 ( V_13 ) , V_18 -> V_21 , & V_19 ) ;
if ( F_5 ( V_20 < 0 ) )
return V_20 ;
return snprintf ( V_16 , V_22 , L_1 , V_19 ) ;
}
static int F_9 ( struct V_2 * V_3 ,
const struct V_23 * V_24 )
{
int V_20 ;
struct V_12 * V_25 ;
if ( ! F_10 ( V_3 -> V_26 , V_27 |
V_28 ) )
return - V_29 ;
V_20 = F_11 ( V_3 , V_30 ,
V_31 |
V_32 ) ;
if ( V_20 < 0 ) {
F_12 ( & V_3 -> V_13 , L_2 ) ;
return V_20 ;
}
V_20 = F_11 ( V_3 , V_33 , 1 ) ;
if ( V_20 < 0 ) {
F_12 ( & V_3 -> V_13 , L_3 ) ;
return V_20 ;
}
V_25 = F_13 ( & V_3 -> V_13 ,
V_3 -> V_34 ,
V_3 ,
V_35 ) ;
return F_14 ( V_25 ) ;
}
