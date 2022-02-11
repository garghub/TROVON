static int F_1 ( struct V_1 * V_2 )
{
V_2 -> V_3 [ V_4 ] . V_5 = V_6 ;
V_2 -> V_3 [ V_4 ] . V_7 = L_1 ;
V_2 -> V_3 [ V_8 ] . V_5 = V_9 ;
V_2 -> V_3 [ V_8 ] . V_7 = L_2 ;
return 0 ;
}
static void F_2 ( struct V_1 * V_2 ,
struct V_10 * V_11 )
{
V_11 -> V_12 = 0 ;
V_11 -> V_13 = 0 ;
V_11 -> V_14 = 1 ;
V_11 -> V_15 = 0 ;
}
static int F_3 ( struct V_1 * V_2 ,
const T_1 * V_11 )
{
switch ( V_11 -> V_16 ) {
case 0 :
F_4 ( V_17 , 1 ) ;
break;
case 33 :
case 50 :
F_4 ( V_17 , 0 ) ;
F_5 ( 100 ) ;
break;
default:
F_6 ( L_3 ,
V_18 , V_11 -> V_16 ) ;
return - 1 ;
}
F_4 ( V_19 , ! ! ( V_11 -> V_20 & V_21 ) ) ;
return 0 ;
}
static int T_2 F_7 ( void )
{
int V_22 ;
if ( ! F_8 () )
return - V_23 ;
V_24 = F_9 ( L_4 , - 1 ) ;
if ( ! V_24 )
return - V_25 ;
V_22 = F_10 ( V_26 , F_11 ( V_26 ) ) ;
if ( V_22 )
goto V_27;
V_22 = F_12 ( V_24 ,
& V_28 ,
sizeof( V_28 ) ) ;
if ( V_22 )
goto V_29;
V_22 = F_13 ( V_24 ) ;
if ( V_22 )
goto V_29;
return 0 ;
V_29:
F_14 ( V_26 , F_11 ( V_26 ) ) ;
V_27:
F_15 ( V_24 ) ;
return V_22 ;
}
static void T_3 F_16 ( void )
{
F_17 ( V_24 ) ;
F_14 ( V_26 , F_11 ( V_26 ) ) ;
}
