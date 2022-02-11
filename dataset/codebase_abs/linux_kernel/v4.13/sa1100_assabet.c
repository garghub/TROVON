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
static int
F_2 ( struct V_1 * V_2 , const T_1 * V_14 )
{
unsigned int V_15 ;
switch ( V_14 -> V_16 ) {
case 0 :
V_15 = 0 ;
break;
case 50 :
F_3 ( V_17 L_5 ,
V_18 ) ;
case 33 :
V_15 = V_19 ;
break;
default:
F_3 ( V_20 L_6 , V_18 ,
V_14 -> V_16 ) ;
return - 1 ;
}
if ( V_14 -> V_21 & V_22 )
V_15 |= V_23 ;
if ( ! ( V_14 -> V_21 & V_24 ) )
V_15 |= V_25 ;
F_4 ( V_23 | V_19 |
V_25 , V_15 ) ;
return 0 ;
}
static void F_5 ( struct V_1 * V_2 )
{
F_6 ( V_25 | V_23 ) ;
}
int F_7 ( struct V_26 * V_27 )
{
int V_28 = - V_29 ;
if ( F_8 () && ! F_9 () )
V_28 = F_10 ( V_27 , & V_30 , 1 , 1 ) ;
return V_28 ;
}
