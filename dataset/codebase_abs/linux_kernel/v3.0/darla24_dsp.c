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
V_2 -> V_11 = TRUE ;
V_2 -> V_12 = V_13 |
V_14 ;
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
T_2 V_15 , V_16 ;
V_15 = F_9 ( V_2 -> V_17 -> V_18 ) ;
V_16 = V_13 ;
if ( V_15 & V_19 )
V_16 |= V_14 ;
return V_16 ;
}
static int F_10 ( struct V_1 * V_2 )
{
return 0 ;
}
static int F_11 ( struct V_1 * V_2 , T_2 V_20 )
{
T_3 clock ;
switch ( V_20 ) {
case 96000 :
clock = V_21 ;
break;
case 88200 :
clock = V_22 ;
break;
case 48000 :
clock = V_23 ;
break;
case 44100 :
clock = V_24 ;
break;
case 32000 :
clock = V_25 ;
break;
case 22050 :
clock = V_26 ;
break;
case 16000 :
clock = V_27 ;
break;
case 11025 :
clock = V_28 ;
break;
case 8000 :
clock = V_29 ;
break;
default:
F_12 ( ( L_4 ,
V_20 ) ) ;
return - V_30 ;
}
if ( F_13 ( V_2 ) )
return - V_31 ;
F_12 ( ( L_5 , V_20 , clock ) ) ;
V_2 -> V_32 = V_20 ;
if ( V_2 -> V_33 == V_34 )
clock = V_35 ;
V_2 -> V_17 -> V_32 = F_14 ( V_20 ) ;
V_2 -> V_17 -> V_36 = clock ;
F_15 ( V_2 ) ;
return F_16 ( V_2 , V_37 ) ;
}
static int F_17 ( struct V_1 * V_2 , T_1 clock )
{
if ( F_3 ( clock != V_38 &&
clock != V_34 ) )
return - V_30 ;
V_2 -> V_33 = clock ;
return F_11 ( V_2 , V_2 -> V_32 ) ;
}
