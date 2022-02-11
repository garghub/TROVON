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
static int
F_5 ( struct V_1 * V_2 ,
const T_1 * V_17 )
{
switch ( V_17 -> V_18 ) {
case 0 :
case 50 :
case 33 :
break;
default:
F_6 ( V_19 L_6 ,
V_20 , V_17 -> V_18 ) ;
return - 1 ;
}
F_7 ( V_4 , ! ! ( V_17 -> V_21 & V_22 ) ) ;
return 0 ;
}
int F_8 ( struct V_23 * V_24 )
{
int V_3 = - V_25 ;
if ( F_9 () )
V_3 = F_10 ( V_24 , & V_26 , V_27 , 1 ) ;
return V_3 ;
}
