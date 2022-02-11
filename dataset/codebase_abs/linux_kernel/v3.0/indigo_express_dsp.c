static int F_1 ( struct V_1 * V_2 , T_1 V_3 )
{
T_1 clock , V_4 , V_5 ;
if ( F_2 ( V_2 ) )
return - V_6 ;
V_5 = F_3 ( V_2 -> V_7 -> V_8 ) ;
V_4 = V_5 & ~ V_9 ;
switch ( V_3 ) {
case 32000 :
clock = V_10 ;
break;
case 44100 :
clock = V_11 ;
break;
case 48000 :
clock = V_12 ;
break;
case 64000 :
clock = V_10 | V_13 ;
break;
case 88200 :
clock = V_11 | V_13 ;
break;
case 96000 :
clock = V_12 | V_13 ;
break;
default:
return - V_14 ;
}
V_4 |= clock ;
if ( V_4 != V_5 ) {
F_4 ( ( L_1 , V_3 , clock ) ) ;
V_2 -> V_7 -> V_8 = F_5 ( V_4 ) ;
V_2 -> V_15 = V_3 ;
F_6 ( V_2 ) ;
return F_7 ( V_2 , V_16 ) ;
}
return 0 ;
}
static int F_8 ( struct V_1 * V_2 , T_2 V_17 , T_2 V_18 ,
int V_19 )
{
int V_20 ;
if ( F_9 ( V_18 >= F_10 ( V_2 ) ||
V_17 >= F_11 ( V_2 ) ) )
return - V_14 ;
if ( F_2 ( V_2 ) )
return - V_6 ;
V_2 -> V_21 [ V_17 ] [ V_18 ] = V_19 ;
V_20 = V_17 * F_10 ( V_2 ) + V_18 ;
V_2 -> V_7 -> V_22 [ V_20 ] = V_19 ;
F_4 ( ( L_2 , V_18 , V_17 , V_19 ) ) ;
return 0 ;
}
static int F_12 ( struct V_1 * V_2 )
{
if ( F_2 ( V_2 ) )
return - V_6 ;
F_6 ( V_2 ) ;
return F_7 ( V_2 , V_23 ) ;
}
static T_1 F_13 ( const struct V_1 * V_2 )
{
return V_24 ;
}
static int F_14 ( struct V_1 * V_2 )
{
return 0 ;
}
