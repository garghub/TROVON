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
V_2 -> V_12 = V_13 ;
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
return V_13 ;
}
static int F_9 ( struct V_1 * V_2 )
{
return 0 ;
}
static int F_10 ( struct V_1 * V_2 , T_2 V_14 )
{
T_2 V_15 ;
switch ( V_14 ) {
case 96000 :
V_15 = V_16 ;
break;
case 88200 :
V_15 = V_17 ;
break;
case 48000 :
V_15 = V_18 ;
break;
case 44100 :
V_15 = V_19 ;
break;
case 32000 :
V_15 = V_20 ;
break;
default:
F_11 ( ( L_4 , V_14 ) ) ;
return - V_21 ;
}
if ( V_15 != F_12 ( V_2 -> V_22 -> V_23 ) ) {
if ( F_13 ( V_2 ) )
return - V_24 ;
V_2 -> V_22 -> V_25 = F_14 ( V_14 ) ;
V_2 -> V_22 -> V_23 = F_14 ( V_15 ) ;
V_2 -> V_25 = V_14 ;
F_15 ( V_2 ) ;
return F_16 ( V_2 , V_26 ) ;
}
return 0 ;
}
static int F_17 ( struct V_1 * V_2 , T_1 V_27 , T_1 V_28 ,
int V_29 )
{
int V_30 ;
if ( F_3 ( V_28 >= F_18 ( V_2 ) ||
V_27 >= F_19 ( V_2 ) ) )
return - V_21 ;
if ( F_13 ( V_2 ) )
return - V_24 ;
V_2 -> V_31 [ V_27 ] [ V_28 ] = V_29 ;
V_30 = V_27 * F_18 ( V_2 ) + V_28 ;
V_2 -> V_22 -> V_32 [ V_30 ] = V_29 ;
F_11 ( ( L_5 , V_28 , V_27 , V_29 ) ) ;
return 0 ;
}
static int F_20 ( struct V_1 * V_2 )
{
if ( F_13 ( V_2 ) )
return - V_24 ;
F_15 ( V_2 ) ;
return F_16 ( V_2 , V_33 ) ;
}
