static
struct V_1 * T_1 F_1 ( struct V_2 * V_3 ,
const struct V_4 * V_5 ,
const struct V_6 * V_7 ,
struct V_1 * * V_8 ,
void T_2 * V_9 )
{
const struct V_1 * V_10 ;
unsigned int V_11 = 1 ;
unsigned int div = 1 ;
T_3 V_12 ;
V_10 = V_8 [ V_5 -> V_10 ] ;
if ( F_2 ( V_10 ) )
return F_3 ( V_10 ) ;
switch ( V_5 -> type ) {
case V_13 :
div = V_14 -> V_15 ;
break;
case V_16 :
V_12 = F_4 ( V_9 + V_17 ) ;
V_11 = ( ( ( V_12 >> 24 ) & 0x7f ) + 1 ) * 2 ;
break;
case V_18 :
V_11 = V_14 -> V_19 ;
break;
case V_20 :
V_12 = F_4 ( V_9 + V_21 ) ;
V_11 = ( ( ( V_12 >> 24 ) & 0x7f ) + 1 ) * 2 ;
break;
case V_22 :
V_11 = V_14 -> V_23 ;
break;
case V_24 :
V_12 = F_4 ( V_9 + V_25 ) ;
V_11 = ( ( ( V_12 >> 24 ) & 0x7f ) + 1 ) * 2 ;
break;
default:
return F_5 ( - V_26 ) ;
}
return F_6 ( NULL , V_5 -> V_27 ,
F_7 ( V_10 ) , 0 , V_11 , div ) ;
}
static T_3 F_8 ( void )
{
void T_2 * V_28 = F_9 ( V_29 , 4 ) ;
T_3 V_30 ;
F_10 ( ! V_28 ) ;
V_30 = F_11 ( V_28 ) ;
F_12 ( V_28 ) ;
return V_30 ;
}
static int T_1 F_13 ( struct V_2 * V_3 )
{
T_3 V_31 = F_8 () ;
V_14 = & V_32 [ F_14 ( V_31 ) ] ;
if ( ! V_14 -> V_15 ) {
F_15 ( V_3 , L_1 , V_31 ) ;
return - V_26 ;
}
return 0 ;
}
