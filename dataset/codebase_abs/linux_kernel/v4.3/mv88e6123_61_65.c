static char * F_1 ( struct V_1 * V_2 , int V_3 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
int V_6 ;
if ( V_5 == NULL )
return NULL ;
V_6 = F_3 ( V_5 , V_3 , F_4 ( 0 ) , V_7 ) ;
if ( V_6 >= 0 ) {
if ( V_6 == V_8 )
return L_1 ;
if ( V_6 == V_9 )
return L_2 ;
if ( ( V_6 & 0xfff0 ) == V_10 )
return L_3 ;
if ( V_6 == V_11 )
return L_4 ;
if ( V_6 == V_12 )
return L_5 ;
if ( ( V_6 & 0xfff0 ) == V_13 )
return L_6 ;
if ( V_6 == V_14 )
return L_7 ;
if ( V_6 == V_15 )
return L_8 ;
if ( ( V_6 & 0xfff0 ) == V_16 )
return L_9 ;
}
return NULL ;
}
static int F_5 ( struct V_17 * V_18 )
{
T_1 V_19 = F_6 ( V_18 ) ;
int V_6 ;
T_1 V_20 ;
V_6 = F_7 ( V_18 ) ;
if ( V_6 )
return V_6 ;
F_8 ( V_21 , V_22 , 0x0000 ) ;
V_20 = V_19 << V_23 |
V_19 << V_24 |
V_19 << V_25 ;
F_8 ( V_21 , V_26 , V_20 ) ;
F_8 ( V_21 , V_27 , V_18 -> V_28 & 0x1f ) ;
return 0 ;
}
static int F_9 ( struct V_17 * V_18 )
{
struct V_29 * V_30 = F_10 ( V_18 ) ;
int V_6 ;
V_6 = F_11 ( V_18 ) ;
if ( V_6 < 0 )
return V_6 ;
switch ( V_30 -> V_31 ) {
case V_10 :
V_30 -> V_32 = 3 ;
break;
case V_13 :
case V_16 :
V_30 -> V_32 = 6 ;
break;
default:
return - V_33 ;
}
V_6 = F_12 ( V_18 , false ) ;
if ( V_6 < 0 )
return V_6 ;
V_6 = F_5 ( V_18 ) ;
if ( V_6 < 0 )
return V_6 ;
return F_13 ( V_18 ) ;
}
