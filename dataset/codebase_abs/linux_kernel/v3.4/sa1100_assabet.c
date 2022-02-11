static int F_1 ( struct V_1 * V_2 )
{
V_2 -> V_3 [ V_4 ] . V_5 = V_6 ;
V_2 -> V_3 [ V_4 ] . V_7 = L_1 ;
V_2 -> V_3 [ V_8 ] . V_5 = V_9 ;
V_2 -> V_3 [ V_8 ] . V_7 = L_2 ;
V_2 -> V_3 [ V_10 ] . V_5 = V_11 ;
V_2 -> V_3 [ V_10 ] . V_7 = L_3 ;
V_2 -> V_3 [ V_12 ] . V_5 = V_13 ;
V_2 -> V_3 [ V_12 ] . V_7 = L_4 ;
return 0 ;
}
static void
F_2 ( struct V_1 * V_2 , struct V_14 * V_15 )
{
V_15 -> V_16 = 1 ;
V_15 -> V_17 = 0 ;
}
static int
F_3 ( struct V_1 * V_2 , const T_1 * V_15 )
{
unsigned int V_18 ;
switch ( V_15 -> V_19 ) {
case 0 :
V_18 = 0 ;
break;
case 50 :
F_4 ( V_20 L_5 ,
V_21 ) ;
case 33 :
V_18 = V_22 ;
break;
default:
F_4 ( V_23 L_6 , V_21 ,
V_15 -> V_19 ) ;
return - 1 ;
}
if ( V_15 -> V_24 & V_25 )
V_18 |= V_26 ;
if ( ! ( V_15 -> V_24 & V_27 ) )
V_18 |= V_28 ;
F_5 ( V_26 | V_22 |
V_28 , V_18 ) ;
return 0 ;
}
static void F_6 ( struct V_1 * V_2 )
{
F_7 ( V_28 | V_26 ) ;
}
int T_2 F_8 ( struct V_29 * V_30 )
{
int V_31 = - V_32 ;
if ( F_9 () && ! F_10 () )
V_31 = F_11 ( V_30 , & V_33 , 1 , 1 ) ;
return V_31 ;
}
