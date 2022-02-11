static void F_1 ( int V_1 )
{
if ( F_2 ( V_2 , L_1 ) ) {
F_3 ( L_2 , V_3 ) ;
goto V_4;
}
if ( F_2 ( V_5 , L_3 ) ) {
F_3 ( L_4 , V_3 ) ;
goto V_6;
}
if ( F_2 ( V_7 , L_5 ) ) {
F_3 ( L_6 , V_3 ) ;
goto V_8;
}
if ( F_2 ( V_9 , L_7 ) ) {
F_3 ( L_8 , V_3 ) ;
goto V_10;
}
F_4 ( V_2 , V_1 ) ;
F_4 ( V_5 , V_1 ) ;
F_4 ( V_7 , V_1 ) ;
F_4 ( V_9 , V_1 ) ;
F_5 ( V_9 ) ;
V_10: F_5 ( V_7 ) ;
V_8: F_5 ( V_5 ) ;
V_6: F_5 ( V_2 ) ;
V_4: return;
}
static void T_1 F_6 ( void )
{
F_7 () ;
}
static int F_8 ( struct V_11 * V_12 , unsigned int V_13 )
{
F_9 ( V_14 , V_13 ) ;
return 0 ;
}
static void F_10 ( struct V_11 * V_12 , unsigned int V_15 )
{
F_9 ( V_16 , ! ( V_15 < 4000000 ) ) ;
}
static int F_11 ( struct V_11 * V_12 )
{
int V_17 = F_2 ( V_14 , L_9 ) ;
if ( V_17 )
goto V_4;
V_17 = F_4 ( V_14 , 0 ) ;
if ( V_17 )
goto V_6;
V_17 = F_2 ( V_16 , L_10 ) ;
if ( V_17 )
goto V_6;
V_17 = F_4 ( V_16 , 0 ) ;
if ( V_17 )
goto V_8;
return 0 ;
V_8: F_5 ( V_16 ) ;
V_6: F_5 ( V_14 ) ;
V_4: return V_17 ;
}
static void F_12 ( struct V_11 * V_12 )
{
F_5 ( V_14 ) ;
F_5 ( V_16 ) ;
}
static void T_1 F_13 ( void )
{
F_14 ( V_18 , F_15 ( V_18 ) ) ;
F_16 () ;
F_17 ( & V_19 ) ;
F_18 ( & V_20 ) ;
}
