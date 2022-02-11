static int F_1 ( struct V_1 * V_2 )
{
int V_3 ;
V_3 = F_2 ( V_4 , V_5 , L_1 ) ;
if ( V_3 )
return V_3 ;
V_2 -> V_6 [ V_7 ] . V_8 = V_9 ;
V_2 -> V_6 [ V_7 ] . V_10 = L_2 ;
V_2 -> V_6 [ V_11 ] . V_8 = V_12 ;
V_2 -> V_6 [ V_11 ] . V_10 = L_3 ;
V_2 -> V_6 [ V_13 ] . V_8 = V_14 ;
V_2 -> V_6 [ V_13 ] . V_10 = L_4 ;
V_2 -> V_6 [ V_15 ] . V_8 = V_16 ;
V_2 -> V_6 [ V_15 ] . V_10 = L_5 ;
return 0 ;
}
static void F_3 ( struct V_1 * V_2 )
{
F_4 ( V_4 ) ;
}
static void
F_5 ( struct V_1 * V_2 , struct V_17 * V_18 )
{
V_18 -> V_19 = 1 ;
V_18 -> V_20 = 0 ;
}
static int
F_6 ( struct V_1 * V_2 ,
const T_1 * V_18 )
{
switch ( V_18 -> V_21 ) {
case 0 :
case 50 :
case 33 :
break;
default:
F_7 ( V_22 L_6 ,
V_23 , V_18 -> V_21 ) ;
return - 1 ;
}
F_8 ( V_4 , ! ! ( V_18 -> V_24 & V_25 ) ) ;
return 0 ;
}
int F_9 ( struct V_26 * V_27 )
{
int V_3 = - V_28 ;
if ( F_10 () )
V_3 = F_11 ( V_27 , & V_29 , V_30 , 1 ) ;
return V_3 ;
}
