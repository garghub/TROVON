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
V_2 -> V_10 = true ;
V_2 -> V_11 = V_12 ;
V_2 -> V_13 = true ;
V_2 -> V_14 = V_15 |
V_16 ;
if ( ( V_5 = F_5 ( V_2 ) ) < 0 )
return V_5 ;
V_2 -> V_10 = false ;
return V_5 ;
}
static int F_6 ( struct V_1 * V_2 )
{
return F_7 ( V_2 ) ;
}
static T_2 F_8 ( const struct V_1 * V_2 )
{
T_2 V_17 , V_18 ;
V_17 = F_9 ( V_2 -> V_19 -> V_20 ) ;
V_18 = V_15 ;
if ( V_17 & V_21 )
V_18 |= V_16 ;
return V_18 ;
}
static int F_10 ( struct V_1 * V_2 )
{
return 0 ;
}
static int F_11 ( struct V_1 * V_2 , T_2 V_22 )
{
T_3 clock ;
switch ( V_22 ) {
case 96000 :
clock = V_23 ;
break;
case 88200 :
clock = V_24 ;
break;
case 48000 :
clock = V_25 ;
break;
case 44100 :
clock = V_26 ;
break;
case 32000 :
clock = V_27 ;
break;
case 22050 :
clock = V_28 ;
break;
case 16000 :
clock = V_29 ;
break;
case 11025 :
clock = V_30 ;
break;
case 8000 :
clock = V_31 ;
break;
default:
F_4 ( V_2 -> V_8 -> V_9 ,
L_2 ,
V_22 ) ;
return - V_32 ;
}
if ( F_12 ( V_2 ) )
return - V_33 ;
F_13 ( V_2 -> V_8 -> V_9 ,
L_3 , V_22 , clock ) ;
V_2 -> V_34 = V_22 ;
if ( V_2 -> V_35 == V_36 )
clock = V_37 ;
V_2 -> V_19 -> V_34 = F_14 ( V_22 ) ;
V_2 -> V_19 -> V_38 = clock ;
F_15 ( V_2 ) ;
return F_16 ( V_2 , V_39 ) ;
}
static int F_17 ( struct V_1 * V_2 , T_1 clock )
{
if ( F_2 ( clock != V_40 &&
clock != V_36 ) )
return - V_32 ;
V_2 -> V_35 = clock ;
return F_11 ( V_2 , V_2 -> V_34 ) ;
}
