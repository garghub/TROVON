static int F_1 ( struct V_1 * V_2 )
{
int V_3 ;
V_3 = F_2 ( V_4 , F_3 ( V_4 ) ) ;
if ( V_3 )
goto V_5;
F_4 ( F_5 ( V_6 ) , V_7 ) ;
V_2 -> V_8 [ V_9 ] . V_10 = V_6 ;
V_2 -> V_8 [ V_9 ] . V_11 = L_1 ;
V_2 -> V_8 [ V_12 ] . V_10 = V_13 ;
V_2 -> V_8 [ V_12 ] . V_11 = L_2 ;
V_5:
return V_3 ;
}
static void F_6 ( struct V_1 * V_2 )
{
F_7 ( V_4 , F_3 ( V_4 ) ) ;
}
static void F_8 ( struct V_1 * V_2 ,
struct V_14 * V_15 )
{
V_15 -> V_16 = 1 ;
V_15 -> V_17 = 0 ;
}
static int F_9 ( struct V_1 * V_2 ,
const T_1 * V_15 )
{
switch ( V_15 -> V_18 ) {
case 0 :
F_10 ( V_19 , 0 ) ;
break;
case 33 :
F_10 ( V_19 , 1 ) ;
break;
default:
F_11 ( V_20 L_3 , V_15 -> V_18 ) ;
return - V_21 ;
}
F_10 ( V_22 , ( V_15 -> V_23 & V_24 ) != 0 ) ;
return 0 ;
}
static int T_2 F_12 ( void )
{
struct V_25 * V_26 ;
if ( ! F_13 () )
return - V_27 ;
V_26 = F_14 ( NULL , L_4 , - 1 ,
& V_28 , sizeof( V_28 ) ) ;
if ( F_15 ( V_26 ) )
return F_16 ( V_26 ) ;
V_29 = V_26 ;
return 0 ;
}
static void T_3 F_17 ( void )
{
F_18 ( V_29 ) ;
}
