static int F_1 ( struct V_1 * V_2 )
{
if ( V_2 -> V_3 == 0 ) {
V_2 -> V_4 [ V_5 ] . V_6 = V_7 ;
V_2 -> V_4 [ V_5 ] . V_8 = L_1 ;
V_2 -> V_4 [ V_9 ] . V_6 = V_10 ;
V_2 -> V_4 [ V_9 ] . V_8 = L_2 ;
} else {
V_2 -> V_4 [ V_5 ] . V_6 = V_11 ;
V_2 -> V_4 [ V_5 ] . V_8 = L_3 ;
V_2 -> V_4 [ V_9 ] . V_6 = V_12 ;
V_2 -> V_4 [ V_9 ] . V_8 = L_4 ;
}
return 0 ;
}
static void F_2 ( struct V_1 * V_2 ,
struct V_13 * V_14 )
{
V_14 -> V_15 = 1 ;
V_14 -> V_16 = 0 ;
}
static int F_3 ( struct V_1 * V_2 ,
const T_1 * V_14 )
{
if ( V_14 -> V_17 & V_18 ) {
if ( V_2 -> V_3 == 0 )
F_4 ( V_19 , 1 ) ;
else
F_4 ( V_20 , 1 ) ;
} else {
if ( V_2 -> V_3 == 0 )
F_4 ( V_19 , 0 ) ;
else
F_4 ( V_20 , 0 ) ;
}
switch ( V_14 -> V_21 ) {
case 0 :
if ( V_2 -> V_3 == 0 )
F_4 ( V_22 , 0 ) ;
else
F_4 ( V_23 , 1 ) ;
break;
case 50 :
case 33 :
if ( V_2 -> V_3 == 0 )
F_4 ( V_22 , 1 ) ;
else
F_4 ( V_23 , 0 ) ;
break;
default:
F_5 ( V_24 L_5 , V_14 -> V_21 ) ;
}
return 0 ;
}
static int T_2 F_6 ( void )
{
int V_25 ;
if ( ! F_7 () )
return - V_26 ;
V_27 = F_8 ( L_6 , - 1 ) ;
if ( ! V_27 )
return - V_28 ;
V_25 = F_9 ( V_27 , & V_29 ,
sizeof( V_29 ) ) ;
if ( ! V_25 )
V_25 = F_10 ( V_27 ) ;
if ( V_25 )
F_11 ( V_27 ) ;
return V_25 ;
}
static void T_3 F_12 ( void )
{
F_13 ( V_27 ) ;
}
