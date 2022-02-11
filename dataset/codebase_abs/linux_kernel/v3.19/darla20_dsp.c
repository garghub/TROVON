static int F_1 ( struct V_1 * V_2 , T_1 V_3 , T_1 V_4 )
{
int V_5 ;
if ( F_2 ( ( V_4 & 0xfff0 ) != V_6 ) )
return - V_7 ;
if ( ( V_5 = F_3 ( V_2 ) ) ) {
F_4 ( V_2 -> V_8 -> V_9 ,
L_1 ) ;
return V_5 ;
}
V_2 -> V_3 = V_3 ;
V_2 -> V_4 = V_4 ;
V_2 -> V_10 = TRUE ;
V_2 -> V_11 = V_12 ;
V_2 -> V_13 = V_14 ;
V_2 -> V_15 = V_16 ;
V_2 -> V_17 = TRUE ;
V_2 -> V_18 = V_19 ;
if ( ( V_5 = F_5 ( V_2 ) ) < 0 )
return V_5 ;
V_2 -> V_10 = FALSE ;
return V_5 ;
}
static int F_6 ( struct V_1 * V_2 )
{
return F_7 ( V_2 ) ;
}
static T_2 F_8 ( const struct V_1 * V_2 )
{
return V_19 ;
}
static int F_9 ( struct V_1 * V_2 )
{
return 0 ;
}
static int F_10 ( struct V_1 * V_2 , T_2 V_20 )
{
T_3 V_15 , V_13 ;
if ( F_11 ( V_2 ) )
return - V_21 ;
switch ( V_20 ) {
case 44100 :
V_15 = V_22 ;
V_13 = V_23 ;
break;
case 48000 :
V_15 = V_24 ;
V_13 = V_25 ;
break;
default:
V_15 = V_26 ;
V_13 = V_27 ;
break;
}
if ( V_2 -> V_15 == V_15 )
V_15 = V_26 ;
if ( V_13 == V_2 -> V_13 )
V_13 = V_27 ;
V_2 -> V_28 -> V_29 = F_12 ( V_20 ) ;
V_2 -> V_28 -> V_30 = V_15 ;
V_2 -> V_28 -> V_31 = V_13 ;
V_2 -> V_28 -> V_32 = 3 ;
if ( V_15 != V_26 )
V_2 -> V_15 = V_15 ;
if ( V_13 != V_27 )
V_2 -> V_13 = V_13 ;
V_2 -> V_29 = V_20 ;
F_13 ( V_2 ) ;
return F_14 ( V_2 , V_33 ) ;
}
