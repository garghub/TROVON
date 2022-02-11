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
V_2 -> V_13 = TRUE ;
if ( ( V_4 & 0x0000f ) == V_14 )
V_2 -> V_15 = TRUE ;
V_2 -> V_16 = V_17 |
V_18 ;
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
T_2 V_19 , V_20 ;
V_19 = F_9 ( V_2 -> V_21 -> V_22 ) ;
V_20 = V_17 ;
if ( V_19 & V_23 )
V_20 |= V_18 ;
return V_20 ;
}
static int F_10 ( struct V_1 * V_2 )
{
return 0 ;
}
static int F_11 ( struct V_1 * V_2 , T_2 V_24 )
{
T_2 V_25 ;
switch ( V_24 ) {
case 96000 :
V_25 = V_26 ;
break;
case 88200 :
V_25 = V_27 ;
break;
case 48000 :
V_25 = V_28 ;
break;
case 44100 :
V_25 = V_29 ;
break;
case 32000 :
V_25 = V_30 ;
break;
default:
F_4 ( V_2 -> V_8 -> V_9 ,
L_2 , V_24 ) ;
return - V_31 ;
}
if ( V_2 -> V_32 == V_33 )
V_25 |= V_34 ;
if ( V_25 != F_9 ( V_2 -> V_21 -> V_35 ) ) {
if ( F_12 ( V_2 ) )
return - V_36 ;
V_2 -> V_21 -> V_37 = F_13 ( V_24 ) ;
V_2 -> V_21 -> V_35 = F_13 ( V_25 ) ;
V_2 -> V_37 = V_24 ;
F_14 ( V_2 ) ;
return F_15 ( V_2 , V_38 ) ;
}
return 0 ;
}
static int F_16 ( struct V_1 * V_2 , T_1 clock )
{
F_17 ( V_2 -> V_8 -> V_9 , L_3 , clock ) ;
if ( F_2 ( clock != V_39 &&
clock != V_33 ) )
return - V_31 ;
V_2 -> V_32 = clock ;
return F_11 ( V_2 , V_2 -> V_37 ) ;
}
static int F_18 ( struct V_1 * V_2 , T_1 V_40 , T_1 V_41 ,
int V_42 )
{
int V_43 ;
if ( F_2 ( V_41 >= F_19 ( V_2 ) ||
V_40 >= F_20 ( V_2 ) ) )
return - V_31 ;
if ( F_12 ( V_2 ) )
return - V_36 ;
V_2 -> V_44 [ V_40 ] [ V_41 ] = V_42 ;
V_43 = V_40 * F_19 ( V_2 ) + V_41 ;
V_2 -> V_21 -> V_45 [ V_43 ] = V_42 ;
F_17 ( V_2 -> V_8 -> V_9 ,
L_4 , V_41 , V_40 , V_42 ) ;
return 0 ;
}
static int F_21 ( struct V_1 * V_2 )
{
if ( F_12 ( V_2 ) )
return - V_36 ;
F_14 ( V_2 ) ;
return F_15 ( V_2 , V_46 ) ;
}
static int F_22 ( struct V_1 * V_2 )
{
if ( F_12 ( V_2 ) )
return - V_36 ;
F_14 ( V_2 ) ;
return F_15 ( V_2 , V_47 ) ;
}
static int F_23 ( struct V_1 * V_2 , char V_48 )
{
F_17 ( V_2 -> V_8 -> V_9 , L_5 , V_48 ) ;
if ( V_48 )
V_2 -> V_21 -> V_49 |=
F_13 ( V_50 ) ;
else
V_2 -> V_21 -> V_49 &=
~ F_13 ( V_50 ) ;
V_2 -> V_51 = V_48 ;
return F_22 ( V_2 ) ;
}
