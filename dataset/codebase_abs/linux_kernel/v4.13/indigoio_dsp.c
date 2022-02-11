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
V_2 -> V_14 = V_15 ;
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
return V_15 ;
}
static int F_9 ( struct V_1 * V_2 )
{
return 0 ;
}
static int F_10 ( struct V_1 * V_2 , T_2 V_16 )
{
if ( F_11 ( V_2 ) )
return - V_17 ;
V_2 -> V_18 = V_16 ;
V_2 -> V_19 -> V_18 = F_12 ( V_16 ) ;
F_13 ( V_2 ) ;
return F_14 ( V_2 , V_20 ) ;
}
static int F_15 ( struct V_1 * V_2 , T_1 V_21 , T_1 V_22 ,
int V_23 )
{
int V_24 ;
if ( F_2 ( V_22 >= F_16 ( V_2 ) ||
V_21 >= F_17 ( V_2 ) ) )
return - V_25 ;
if ( F_11 ( V_2 ) )
return - V_17 ;
V_2 -> V_26 [ V_21 ] [ V_22 ] = V_23 ;
V_24 = V_21 * F_16 ( V_2 ) + V_22 ;
V_2 -> V_19 -> V_27 [ V_24 ] = V_23 ;
F_18 ( V_2 -> V_8 -> V_9 ,
L_2 , V_22 , V_21 , V_23 ) ;
return 0 ;
}
static int F_19 ( struct V_1 * V_2 )
{
if ( F_11 ( V_2 ) )
return - V_17 ;
F_13 ( V_2 ) ;
return F_14 ( V_2 , V_28 ) ;
}
