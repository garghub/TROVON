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
V_2 -> V_16 = V_17 |
V_18 ;
if ( ( V_5 = F_5 ( V_2 ) ) < 0 )
return V_5 ;
V_2 -> V_8 = FALSE ;
F_2 ( ( L_3 ) ) ;
return V_5 ;
}
static int F_6 ( struct V_1 * V_2 )
{
V_2 -> V_19 = FALSE ;
return F_7 ( V_2 ) ;
}
static T_2 F_8 ( const struct V_1 * V_2 )
{
T_2 V_20 , V_21 ;
V_20 = F_9 ( V_2 -> V_22 -> V_23 ) ;
V_21 = V_17 ;
if ( V_20 & V_24 )
V_21 |= V_18 ;
return V_21 ;
}
static int F_10 ( struct V_1 * V_2 )
{
return 0 ;
}
static int F_11 ( struct V_1 * V_2 , T_2 V_25 )
{
T_3 V_13 , V_11 ;
if ( F_12 ( V_2 ) )
return - V_26 ;
switch ( V_25 ) {
case 44100 :
V_13 = V_27 ;
V_11 = V_28 ;
break;
case 48000 :
V_13 = V_29 ;
V_11 = V_30 ;
break;
default:
V_13 = V_31 ;
V_11 = V_32 ;
break;
}
if ( V_2 -> V_13 == V_13 )
V_13 = V_31 ;
if ( V_11 == V_2 -> V_11 )
V_11 = V_32 ;
V_2 -> V_22 -> V_33 = F_13 ( V_25 ) ;
V_2 -> V_22 -> V_34 = V_13 ;
V_2 -> V_22 -> V_35 = V_11 ;
V_2 -> V_22 -> V_36 = 3 ;
if ( V_13 != V_31 )
V_2 -> V_13 = V_13 ;
if ( V_11 != V_32 )
V_2 -> V_11 = V_11 ;
V_2 -> V_33 = V_25 ;
F_14 ( V_2 ) ;
return F_15 ( V_2 , V_37 ) ;
}
static int F_16 ( struct V_1 * V_2 , T_1 clock )
{
F_17 ( ( L_4 ) ) ;
switch ( clock ) {
case V_38 :
V_2 -> V_13 = V_14 ;
V_2 -> V_11 = V_12 ;
F_11 ( V_2 , V_2 -> V_33 ) ;
V_2 -> V_39 = clock ;
F_17 ( ( L_5 ) ) ;
break;
case V_40 :
V_2 -> V_22 -> V_34 = V_41 ;
V_2 -> V_22 -> V_35 = V_32 ;
F_14 ( V_2 ) ;
F_15 ( V_2 , V_37 ) ;
V_2 -> V_13 = V_41 ;
F_17 ( ( L_6 ) ) ;
V_2 -> V_39 = clock ;
break;
default:
return - V_42 ;
}
return 0 ;
}
static int F_18 ( struct V_1 * V_2 , T_1 V_43 , int V_44 )
{
if ( F_3 ( V_43 >= F_19 ( V_2 ) ) )
return - V_42 ;
if ( F_12 ( V_2 ) )
return - V_26 ;
V_2 -> V_45 [ V_43 ] = V_44 ;
V_44 += V_46 ;
V_2 -> V_22 -> V_47 [ V_43 ] = V_44 ;
return 0 ;
}
static int F_20 ( struct V_1 * V_2 )
{
if ( F_12 ( V_2 ) )
return - V_26 ;
F_14 ( V_2 ) ;
return F_15 ( V_2 , V_48 ) ;
}
static int F_21 ( struct V_1 * V_2 , char V_49 )
{
F_17 ( ( L_7 , V_49 ) ) ;
if ( V_49 )
V_2 -> V_22 -> V_50 |=
F_13 ( V_51 ) ;
else
V_2 -> V_22 -> V_50 &=
~ F_13 ( V_51 ) ;
V_2 -> V_19 = V_49 ;
return F_20 ( V_2 ) ;
}
