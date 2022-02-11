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
V_2 -> V_14 = V_15 ;
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
return V_15 ;
}
static int F_9 ( struct V_1 * V_2 )
{
return 0 ;
}
static int F_10 ( struct V_1 * V_2 , T_2 V_16 )
{
T_2 V_17 ;
switch ( V_16 ) {
case 96000 :
V_17 = V_18 ;
break;
case 88200 :
V_17 = V_19 ;
break;
case 48000 :
V_17 = V_20 ;
break;
case 44100 :
V_17 = V_21 ;
break;
case 32000 :
V_17 = V_22 ;
break;
default:
F_4 ( V_2 -> V_8 -> V_9 ,
L_2 , V_16 ) ;
return - V_23 ;
}
if ( V_17 != F_11 ( V_2 -> V_24 -> V_25 ) ) {
if ( F_12 ( V_2 ) )
return - V_26 ;
V_2 -> V_24 -> V_27 = F_13 ( V_16 ) ;
V_2 -> V_24 -> V_25 = F_13 ( V_17 ) ;
V_2 -> V_27 = V_16 ;
F_14 ( V_2 ) ;
return F_15 ( V_2 , V_28 ) ;
}
return 0 ;
}
static int F_16 ( struct V_1 * V_2 , T_1 V_29 , T_1 V_30 ,
int V_31 )
{
int V_32 ;
if ( F_2 ( V_30 >= F_17 ( V_2 ) ||
V_29 >= F_18 ( V_2 ) ) )
return - V_23 ;
if ( F_12 ( V_2 ) )
return - V_26 ;
V_2 -> V_33 [ V_29 ] [ V_30 ] = V_31 ;
V_32 = V_29 * F_17 ( V_2 ) + V_30 ;
V_2 -> V_24 -> V_34 [ V_32 ] = V_31 ;
F_19 ( V_2 -> V_8 -> V_9 ,
L_3 , V_30 , V_29 , V_31 ) ;
return 0 ;
}
static int F_20 ( struct V_1 * V_2 )
{
if ( F_12 ( V_2 ) )
return - V_26 ;
F_14 ( V_2 ) ;
return F_15 ( V_2 , V_35 ) ;
}
