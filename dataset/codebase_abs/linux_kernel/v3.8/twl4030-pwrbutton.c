static T_1 F_1 ( int V_1 , void * V_2 )
{
struct V_3 * V_4 = V_2 ;
int V_5 ;
T_2 V_6 ;
V_5 = F_2 ( V_7 , & V_6 , V_8 ) ;
if ( ! V_5 ) {
F_3 ( V_4 -> V_9 . V_10 , 0 ) ;
F_4 ( V_4 , V_11 , V_6 & V_12 ) ;
F_5 ( V_4 ) ;
} else {
F_6 ( V_4 -> V_9 . V_10 , L_1
L_2 , V_5 ) ;
}
return V_13 ;
}
static int T_3 F_7 ( struct V_14 * V_15 )
{
struct V_3 * V_4 ;
int V_1 = F_8 ( V_15 , 0 ) ;
int V_5 ;
V_4 = F_9 () ;
if ( ! V_4 ) {
F_10 ( & V_15 -> V_9 , L_3 ) ;
return - V_16 ;
}
V_4 -> V_17 [ 0 ] = F_11 ( V_18 ) ;
V_4 -> V_19 [ F_12 ( V_11 ) ] = F_11 ( V_11 ) ;
V_4 -> V_20 = L_4 ;
V_4 -> V_21 = L_5 ;
V_4 -> V_9 . V_10 = & V_15 -> V_9 ;
V_5 = F_13 ( V_1 , NULL , F_1 ,
V_22 | V_23 ,
L_4 , V_4 ) ;
if ( V_5 < 0 ) {
F_10 ( & V_15 -> V_9 , L_6 , V_5 ) ;
goto V_24;
}
V_5 = F_14 ( V_4 ) ;
if ( V_5 ) {
F_10 ( & V_15 -> V_9 , L_7 , V_5 ) ;
goto V_25;
}
F_15 ( V_15 , V_4 ) ;
return 0 ;
V_25:
V_25 ( V_1 , V_4 ) ;
V_24:
F_16 ( V_4 ) ;
return V_5 ;
}
static int T_4 F_17 ( struct V_14 * V_15 )
{
struct V_3 * V_4 = F_18 ( V_15 ) ;
int V_1 = F_8 ( V_15 , 0 ) ;
V_25 ( V_1 , V_4 ) ;
F_19 ( V_4 ) ;
return 0 ;
}
static int T_3 F_20 ( void )
{
return F_21 ( & V_26 ,
F_7 ) ;
}
static void T_4 F_22 ( void )
{
F_23 ( & V_26 ) ;
}
