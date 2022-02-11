static char * F_1 ( struct V_1 * V_2 , int V_3 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
int V_6 ;
if ( V_5 == NULL )
return NULL ;
V_6 = F_3 ( V_5 , V_3 , F_4 ( 0 ) , V_7 ) ;
if ( V_6 >= 0 ) {
if ( ( V_6 & 0xfff0 ) == V_8 )
return L_1 ;
if ( ( V_6 & 0xfff0 ) == V_9 )
return L_2 ;
if ( ( V_6 & 0xfff0 ) == V_10 )
return L_3 ;
if ( ( V_6 & 0xfff0 ) == V_11 )
return L_4 ;
}
return NULL ;
}
static int F_5 ( struct V_12 * V_13 )
{
T_1 V_14 = F_6 ( V_13 ) ;
int V_6 ;
T_1 V_15 ;
V_6 = F_7 ( V_13 ) ;
if ( V_6 )
return V_6 ;
F_8 ( V_16 , V_17 ,
V_18 | V_19 ) ;
V_15 = V_14 << V_20 |
V_14 << V_21 |
V_14 << V_22 |
V_14 << V_23 ;
F_8 ( V_16 , V_24 , V_15 ) ;
F_8 ( V_16 , V_25 , V_13 -> V_26 & 0x1f ) ;
return 0 ;
}
static int F_9 ( struct V_12 * V_13 )
{
struct V_27 * V_28 = F_10 ( V_13 ) ;
int V_6 ;
V_6 = F_11 ( V_13 ) ;
if ( V_6 < 0 )
return V_6 ;
V_28 -> V_29 = 7 ;
V_6 = F_12 ( V_13 , true ) ;
if ( V_6 < 0 )
return V_6 ;
V_6 = F_5 ( V_13 ) ;
if ( V_6 < 0 )
return V_6 ;
return F_13 ( V_13 ) ;
}
