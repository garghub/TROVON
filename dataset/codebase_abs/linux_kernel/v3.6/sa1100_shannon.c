static int F_1 ( struct V_1 * V_2 )
{
V_3 &= ~ ( F_2 ( V_4 ) |
F_2 ( V_5 ) |
F_2 ( V_6 ) |
F_2 ( V_7 ) ) ;
if ( V_2 -> V_8 == 0 ) {
V_2 -> V_9 [ V_10 ] . V_11 = V_4 ;
V_2 -> V_9 [ V_10 ] . V_12 = L_1 ;
V_2 -> V_9 [ V_13 ] . V_11 = V_6 ;
V_2 -> V_9 [ V_13 ] . V_12 = L_2 ;
} else {
V_2 -> V_9 [ V_10 ] . V_11 = V_5 ;
V_2 -> V_9 [ V_10 ] . V_12 = L_3 ;
V_2 -> V_9 [ V_13 ] . V_11 = V_7 ;
V_2 -> V_9 [ V_13 ] . V_12 = L_4 ;
}
return 0 ;
}
static void
F_3 ( struct V_1 * V_2 ,
struct V_14 * V_15 )
{
switch ( V_2 -> V_8 ) {
case 0 :
V_15 -> V_16 = 1 ;
V_15 -> V_17 = 1 ;
V_15 -> V_18 = 1 ;
V_15 -> V_19 = 0 ;
break;
case 1 :
V_15 -> V_16 = 1 ;
V_15 -> V_17 = 1 ;
V_15 -> V_18 = 1 ;
V_15 -> V_19 = 0 ;
break;
}
}
static int
F_4 ( struct V_1 * V_2 ,
const T_1 * V_15 )
{
switch ( V_15 -> V_20 ) {
case 0 :
F_5 ( V_21 L_5 , V_22 ) ;
break;
case 50 :
F_5 ( V_21 L_6 , V_22 ) ;
case 33 :
break;
default:
F_5 ( V_23 L_7 ,
V_22 , V_15 -> V_20 ) ;
return - 1 ;
}
F_5 ( V_21 L_8 , V_22 ) ;
return 0 ;
}
int T_2 F_6 ( struct V_24 * V_25 )
{
int V_26 = - V_27 ;
if ( F_7 () )
V_26 = F_8 ( V_25 , & V_28 , 0 , 2 ) ;
return V_26 ;
}
