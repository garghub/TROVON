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
if ( ( V_4 & 0x0000f ) == V_12 )
V_2 -> V_13 = TRUE ;
V_2 -> V_14 = V_15 |
V_16 ;
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
T_2 V_23 ;
switch ( V_22 ) {
case 96000 :
V_23 = V_24 ;
break;
case 88200 :
V_23 = V_25 ;
break;
case 48000 :
V_23 = V_26 ;
break;
case 44100 :
V_23 = V_27 ;
break;
case 32000 :
V_23 = V_28 ;
break;
default:
F_12 ( ( L_4 , V_22 ) ) ;
return - V_29 ;
}
if ( V_2 -> V_30 == V_31 )
V_23 |= V_32 ;
if ( V_23 != F_9 ( V_2 -> V_19 -> V_33 ) ) {
if ( F_13 ( V_2 ) )
return - V_34 ;
V_2 -> V_19 -> V_35 = F_14 ( V_22 ) ;
V_2 -> V_19 -> V_33 = F_14 ( V_23 ) ;
V_2 -> V_35 = V_22 ;
F_15 ( V_2 ) ;
return F_16 ( V_2 , V_36 ) ;
}
return 0 ;
}
static int F_17 ( struct V_1 * V_2 , T_1 clock )
{
F_12 ( ( L_5 , clock ) ) ;
if ( F_3 ( clock != V_37 &&
clock != V_31 ) )
return - V_29 ;
V_2 -> V_30 = clock ;
return F_11 ( V_2 , V_2 -> V_35 ) ;
}
static int F_18 ( struct V_1 * V_2 , T_1 V_38 , T_1 V_39 ,
int V_40 )
{
int V_41 ;
if ( F_3 ( V_39 >= F_19 ( V_2 ) ||
V_38 >= F_20 ( V_2 ) ) )
return - V_29 ;
if ( F_13 ( V_2 ) )
return - V_34 ;
V_2 -> V_42 [ V_38 ] [ V_39 ] = V_40 ;
V_41 = V_38 * F_19 ( V_2 ) + V_39 ;
V_2 -> V_19 -> V_43 [ V_41 ] = V_40 ;
F_12 ( ( L_6 , V_39 , V_38 , V_40 ) ) ;
return 0 ;
}
static int F_21 ( struct V_1 * V_2 )
{
if ( F_13 ( V_2 ) )
return - V_34 ;
F_15 ( V_2 ) ;
return F_16 ( V_2 , V_44 ) ;
}
static int F_22 ( struct V_1 * V_2 )
{
if ( F_13 ( V_2 ) )
return - V_34 ;
F_15 ( V_2 ) ;
return F_16 ( V_2 , V_45 ) ;
}
static int F_23 ( struct V_1 * V_2 , char V_46 )
{
F_12 ( ( L_7 , V_46 ) ) ;
if ( V_46 )
V_2 -> V_19 -> V_47 |=
F_14 ( V_48 ) ;
else
V_2 -> V_19 -> V_47 &=
~ F_14 ( V_48 ) ;
V_2 -> V_49 = V_46 ;
return F_22 ( V_2 ) ;
}
