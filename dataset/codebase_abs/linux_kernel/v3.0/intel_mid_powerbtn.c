static T_1 F_1 ( int V_1 , void * V_2 )
{
struct V_3 * V_4 = V_2 ;
int V_5 ;
T_2 V_6 ;
V_5 = F_2 ( V_7 , & V_6 ) ;
if ( V_5 < 0 ) {
F_3 ( V_4 -> V_8 . V_9 , L_1
L_2 , V_5 ) ;
} else {
F_4 ( V_4 , V_10 , V_11 ,
! ( V_6 & V_12 ) ) ;
F_5 ( V_4 ) ;
}
return V_13 ;
}
static int T_3 F_6 ( struct V_14 * V_15 )
{
struct V_3 * V_4 ;
int V_1 = F_7 ( V_15 , 0 ) ;
int error ;
if ( V_1 < 0 )
return - V_16 ;
V_4 = F_8 () ;
if ( ! V_4 ) {
F_3 ( & V_15 -> V_8 , L_3 ) ;
return - V_17 ;
}
V_4 -> V_18 = V_15 -> V_18 ;
V_4 -> V_19 = L_4 ;
V_4 -> V_20 . V_21 = V_22 ;
V_4 -> V_8 . V_9 = & V_15 -> V_8 ;
F_9 ( V_4 , V_10 , V_11 ) ;
error = F_10 ( V_1 , NULL , F_1 , 0 ,
V_23 , V_4 ) ;
if ( error ) {
F_3 ( & V_15 -> V_8 , L_5
L_6 , V_1 ) ;
goto V_24;
}
error = F_11 ( V_4 ) ;
if ( error ) {
F_3 ( & V_15 -> V_8 , L_7
L_8 , error ) ;
goto V_25;
}
F_12 ( V_15 , V_4 ) ;
return 0 ;
V_25:
F_13 ( V_1 , V_4 ) ;
V_24:
F_14 ( V_4 ) ;
return error ;
}
static int T_4 F_15 ( struct V_14 * V_15 )
{
struct V_3 * V_4 = F_16 ( V_15 ) ;
int V_1 = F_7 ( V_15 , 0 ) ;
F_13 ( V_1 , V_4 ) ;
F_17 ( V_4 ) ;
F_12 ( V_15 , NULL ) ;
return 0 ;
}
static int T_5 F_18 ( void )
{
return F_19 ( & V_26 ) ;
}
static void T_6 F_20 ( void )
{
F_21 ( & V_26 ) ;
}
