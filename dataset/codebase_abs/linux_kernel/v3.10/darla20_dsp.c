static int F_1 ( struct V_1 * V_2 , T_1 V_3 , T_1 V_4 )
{
int V_5 ;
F_2 ( ( L_1 ) ) ;
if ( F_3 ( ( V_4 & 0xfff0 ) != V_6 ) )
return - V_7 ;
if ( ( V_5 = F_4 ( V_2 ) ) ) {
F_2 ( ( L_2 ) ) ;
return V_5 ;
}
V_2 -> V_3 = V_3 ;
V_2 -> V_4 = V_4 ;
V_2 -> V_8 = TRUE ;
V_2 -> V_9 = V_10 ;
V_2 -> V_11 = V_12 ;
V_2 -> V_13 = V_14 ;
V_2 -> V_15 = TRUE ;
V_2 -> V_16 = V_17 ;
if ( ( V_5 = F_5 ( V_2 ) ) < 0 )
return V_5 ;
V_2 -> V_8 = FALSE ;
F_2 ( ( L_3 ) ) ;
return V_5 ;
}
static int F_6 ( struct V_1 * V_2 )
{
return F_7 ( V_2 ) ;
}
static T_2 F_8 ( const struct V_1 * V_2 )
{
return V_17 ;
}
static int F_9 ( struct V_1 * V_2 )
{
return 0 ;
}
static int F_10 ( struct V_1 * V_2 , T_2 V_18 )
{
T_3 V_13 , V_11 ;
if ( F_11 ( V_2 ) )
return - V_19 ;
switch ( V_18 ) {
case 44100 :
V_13 = V_20 ;
V_11 = V_21 ;
break;
case 48000 :
V_13 = V_22 ;
V_11 = V_23 ;
break;
default:
V_13 = V_24 ;
V_11 = V_25 ;
break;
}
if ( V_2 -> V_13 == V_13 )
V_13 = V_24 ;
if ( V_11 == V_2 -> V_11 )
V_11 = V_25 ;
V_2 -> V_26 -> V_27 = F_12 ( V_18 ) ;
V_2 -> V_26 -> V_28 = V_13 ;
V_2 -> V_26 -> V_29 = V_11 ;
V_2 -> V_26 -> V_30 = 3 ;
if ( V_13 != V_24 )
V_2 -> V_13 = V_13 ;
if ( V_11 != V_25 )
V_2 -> V_11 = V_11 ;
V_2 -> V_27 = V_18 ;
F_13 ( V_2 ) ;
return F_14 ( V_2 , V_31 ) ;
}
