static int F_1 ( struct V_1 * V_2 )
{
V_2 -> V_3 . V_4 = F_2 ( V_5 ) ;
V_6 [ 0 ] . V_7 = F_2 ( V_8 ) ;
return F_3 ( V_2 , V_6 , F_4 ( V_6 ) ) ;
}
static void F_5 ( struct V_1 * V_2 )
{
F_6 ( V_2 , V_6 , F_4 ( V_6 ) ) ;
}
static void F_7 ( struct V_1 * V_2 ,
struct V_9 * V_10 )
{
V_10 -> V_11 = ! F_8 ( V_8 ) ;
V_10 -> V_12 = ! ! F_8 ( V_5 ) ;
V_10 -> V_13 = 0 ;
V_10 -> V_14 = 0 ;
V_10 -> V_15 = 1 ;
V_10 -> V_16 = 0 ;
V_10 -> V_17 = 0 ;
}
static int F_9 ( struct V_1 * V_2 ,
const T_1 * V_10 )
{
switch ( V_10 -> V_18 ) {
case 0 :
F_10 ( V_19 , 1 ) ;
break;
case 33 :
case 50 :
F_10 ( V_19 , 0 ) ;
F_11 ( 100 ) ;
break;
default:
F_12 ( L_1 ,
V_20 , V_10 -> V_18 ) ;
return - 1 ;
}
F_10 ( V_21 , ! ! ( V_10 -> V_22 & V_23 ) ) ;
return 0 ;
}
static void F_13 ( struct V_1 * V_2 )
{
F_14 ( V_2 , V_6 , F_4 ( V_6 ) ) ;
}
static void F_15 ( struct V_1 * V_2 )
{
F_16 ( V_2 , V_6 , F_4 ( V_6 ) ) ;
}
static int T_2 F_17 ( void )
{
int V_24 ;
if ( ! F_18 () )
return - V_25 ;
V_26 = F_19 ( L_2 , - 1 ) ;
if ( ! V_26 )
return - V_27 ;
V_24 = F_20 ( V_28 , F_4 ( V_28 ) ) ;
if ( V_24 )
goto V_29;
V_24 = F_21 ( V_26 ,
& V_30 ,
sizeof( V_30 ) ) ;
if ( V_24 )
goto V_31;
V_24 = F_22 ( V_26 ) ;
if ( V_24 )
goto V_31;
return 0 ;
V_31:
F_23 ( V_28 , F_4 ( V_28 ) ) ;
V_29:
F_24 ( V_26 ) ;
return V_24 ;
}
static void T_3 F_25 ( void )
{
F_26 ( V_26 ) ;
F_23 ( V_28 , F_4 ( V_28 ) ) ;
}
