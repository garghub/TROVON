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
if ( F_11 ( V_2 ) )
return - V_15 ;
V_2 -> V_16 = V_14 ;
V_2 -> V_17 -> V_16 = F_12 ( V_14 ) ;
F_13 ( V_2 ) ;
return F_14 ( V_2 , V_18 ) ;
}
static int F_15 ( struct V_1 * V_2 , T_1 V_19 , T_1 V_20 ,
int V_21 )
{
int V_22 ;
if ( F_3 ( V_20 >= F_16 ( V_2 ) ||
V_19 >= F_17 ( V_2 ) ) )
return - V_23 ;
if ( F_11 ( V_2 ) )
return - V_15 ;
V_2 -> V_24 [ V_19 ] [ V_20 ] = V_21 ;
V_22 = V_19 * F_16 ( V_2 ) + V_20 ;
V_2 -> V_17 -> V_25 [ V_22 ] = V_21 ;
F_18 ( ( L_4 , V_20 , V_19 , V_21 ) ) ;
return 0 ;
}
static int F_19 ( struct V_1 * V_2 )
{
if ( F_11 ( V_2 ) )
return - V_15 ;
F_13 ( V_2 ) ;
return F_14 ( V_2 , V_26 ) ;
}
