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
V_2 -> V_18 = V_19 |
V_20 ;
if ( ( V_5 = F_5 ( V_2 ) ) < 0 )
return V_5 ;
V_2 -> V_10 = FALSE ;
return V_5 ;
}
static int F_6 ( struct V_1 * V_2 )
{
V_2 -> V_21 = FALSE ;
return F_7 ( V_2 ) ;
}
static T_2 F_8 ( const struct V_1 * V_2 )
{
T_2 V_22 , V_23 ;
V_22 = F_9 ( V_2 -> V_24 -> V_25 ) ;
V_23 = V_19 ;
if ( V_22 & V_26 )
V_23 |= V_20 ;
return V_23 ;
}
static int F_10 ( struct V_1 * V_2 )
{
return 0 ;
}
static int F_11 ( struct V_1 * V_2 , T_2 V_27 )
{
T_3 V_15 , V_13 ;
if ( F_12 ( V_2 ) )
return - V_28 ;
switch ( V_27 ) {
case 44100 :
V_15 = V_29 ;
V_13 = V_30 ;
break;
case 48000 :
V_15 = V_31 ;
V_13 = V_32 ;
break;
default:
V_15 = V_33 ;
V_13 = V_34 ;
break;
}
if ( V_2 -> V_15 == V_15 )
V_15 = V_33 ;
if ( V_13 == V_2 -> V_13 )
V_13 = V_34 ;
V_2 -> V_24 -> V_35 = F_13 ( V_27 ) ;
V_2 -> V_24 -> V_36 = V_15 ;
V_2 -> V_24 -> V_37 = V_13 ;
V_2 -> V_24 -> V_38 = 3 ;
if ( V_15 != V_33 )
V_2 -> V_15 = V_15 ;
if ( V_13 != V_34 )
V_2 -> V_13 = V_13 ;
V_2 -> V_35 = V_27 ;
F_14 ( V_2 ) ;
return F_15 ( V_2 , V_39 ) ;
}
static int F_16 ( struct V_1 * V_2 , T_1 clock )
{
switch ( clock ) {
case V_40 :
V_2 -> V_15 = V_16 ;
V_2 -> V_13 = V_14 ;
F_11 ( V_2 , V_2 -> V_35 ) ;
V_2 -> V_41 = clock ;
break;
case V_42 :
V_2 -> V_24 -> V_36 = V_43 ;
V_2 -> V_24 -> V_37 = V_34 ;
F_14 ( V_2 ) ;
F_15 ( V_2 , V_39 ) ;
V_2 -> V_15 = V_43 ;
V_2 -> V_41 = clock ;
break;
default:
return - V_44 ;
}
return 0 ;
}
static int F_17 ( struct V_1 * V_2 , T_1 V_45 , int V_46 )
{
if ( F_2 ( V_45 >= F_18 ( V_2 ) ) )
return - V_44 ;
if ( F_12 ( V_2 ) )
return - V_28 ;
V_2 -> V_47 [ V_45 ] = V_46 ;
V_46 += V_48 ;
V_2 -> V_24 -> V_49 [ V_45 ] = V_46 ;
return 0 ;
}
static int F_19 ( struct V_1 * V_2 )
{
if ( F_12 ( V_2 ) )
return - V_28 ;
F_14 ( V_2 ) ;
return F_15 ( V_2 , V_50 ) ;
}
static int F_20 ( struct V_1 * V_2 , char V_51 )
{
if ( V_51 )
V_2 -> V_24 -> V_52 |=
F_13 ( V_53 ) ;
else
V_2 -> V_24 -> V_52 &=
~ F_13 ( V_53 ) ;
V_2 -> V_21 = V_51 ;
return F_19 ( V_2 ) ;
}
