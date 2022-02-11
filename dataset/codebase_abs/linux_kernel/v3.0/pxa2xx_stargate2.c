static int F_1 ( struct V_1 * V_2 )
{
V_2 -> V_3 . V_4 = F_2 ( V_5 ) ;
return F_3 ( V_2 , V_6 , F_4 ( V_6 ) ) ;
}
static void F_5 ( struct V_1 * V_2 )
{
F_6 ( V_2 , V_6 , F_4 ( V_6 ) ) ;
}
static void F_7 ( struct V_1 * V_2 ,
struct V_7 * V_8 )
{
V_8 -> V_9 = ! F_8 ( V_10 ) ;
V_8 -> V_11 = ! ! F_8 ( V_5 ) ;
V_8 -> V_12 = 0 ;
V_8 -> V_13 = 0 ;
V_8 -> V_14 = 1 ;
V_8 -> V_15 = 0 ;
V_8 -> V_16 = 0 ;
}
static int F_9 ( struct V_1 * V_2 ,
const T_1 * V_8 )
{
switch ( V_8 -> V_17 ) {
case 0 :
F_10 ( V_18 , 1 ) ;
break;
case 33 :
case 50 :
F_10 ( V_18 , 0 ) ;
F_11 ( 100 ) ;
break;
default:
F_12 ( L_1 ,
V_19 , V_8 -> V_17 ) ;
return - 1 ;
}
F_10 ( V_20 , ! ! ( V_8 -> V_21 & V_22 ) ) ;
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
int V_23 ;
if ( ! F_18 () )
return - V_24 ;
V_25 = F_19 ( L_2 , - 1 ) ;
if ( ! V_25 )
return - V_26 ;
V_23 = F_20 ( V_27 , L_3 ) ;
if ( V_23 )
goto V_28;
V_23 = F_20 ( V_18 , L_4 ) ;
if ( V_23 )
goto V_29;
V_23 = F_20 ( V_20 , L_5 ) ;
if ( V_23 )
goto V_30;
F_21 ( V_27 , 0 ) ;
F_21 ( V_18 , 1 ) ;
F_21 ( V_20 , 1 ) ;
V_23 = F_22 ( V_25 ,
& V_31 ,
sizeof( V_31 ) ) ;
if ( V_23 )
goto V_32;
V_23 = F_23 ( V_25 ) ;
if ( V_23 )
goto V_32;
return 0 ;
V_32:
F_24 ( V_20 ) ;
V_30:
F_24 ( V_18 ) ;
V_29:
F_24 ( V_27 ) ;
V_28:
F_25 ( V_25 ) ;
return V_23 ;
}
static void T_3 F_26 ( void )
{
F_27 ( V_25 ) ;
F_24 ( V_27 ) ;
F_24 ( V_18 ) ;
F_24 ( V_20 ) ;
}
