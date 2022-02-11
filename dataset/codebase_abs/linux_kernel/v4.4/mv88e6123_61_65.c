static char * F_1 ( struct V_1 * V_2 , int V_3 )
{
return F_2 ( V_2 , V_3 , V_4 ,
F_3 ( V_4 ) ) ;
}
static int F_4 ( struct V_5 * V_6 )
{
T_1 V_7 = F_5 ( V_6 ) ;
int V_8 ;
T_1 V_9 ;
V_8 = F_6 ( V_6 ) ;
if ( V_8 )
return V_8 ;
F_7 ( V_10 , V_11 , 0x0000 ) ;
V_9 = V_7 << V_12 |
V_7 << V_13 |
V_7 << V_14 ;
F_7 ( V_10 , V_15 , V_9 ) ;
F_7 ( V_10 , V_16 , V_6 -> V_17 & 0x1f ) ;
return 0 ;
}
static int F_8 ( struct V_5 * V_6 )
{
struct V_18 * V_19 = F_9 ( V_6 ) ;
int V_8 ;
V_8 = F_10 ( V_6 ) ;
if ( V_8 < 0 )
return V_8 ;
switch ( V_19 -> V_20 ) {
case V_21 :
V_19 -> V_22 = 3 ;
break;
case V_23 :
case V_24 :
V_19 -> V_22 = 6 ;
break;
default:
return - V_25 ;
}
V_8 = F_11 ( V_6 , false ) ;
if ( V_8 < 0 )
return V_8 ;
V_8 = F_4 ( V_6 ) ;
if ( V_8 < 0 )
return V_8 ;
return F_12 ( V_6 ) ;
}
