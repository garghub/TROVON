static struct V_1 * F_1 ( struct V_1 * V_2 ,
T_1 V_3 )
{
struct V_1 * V_4 = F_2 ( - V_5 ) ;
T_2 V_6 = V_2 -> V_7 ;
T_1 V_8 ;
T_2 V_9 = V_2 -> V_9 ;
T_3 V_10 ;
unsigned int V_11 ;
F_3 ( V_2 ) ;
V_11 = F_4 ( V_2 ) - F_5 ( V_2 ) ;
if ( F_6 ( ! F_7 ( V_2 , V_11 ) ) )
goto V_12;
V_10 = V_2 -> V_13 ;
V_2 -> V_13 = V_2 -> V_14 ;
F_8 ( V_2 , V_11 ) ;
V_2 -> V_9 = 0 ;
F_9 ( V_2 ) ;
V_8 = V_2 -> V_15 -> V_8 & V_3 ;
V_4 = F_10 ( V_2 , V_8 ) ;
if ( F_11 ( V_4 ) ) {
F_12 ( V_2 , V_10 , V_11 , V_6 ,
V_9 ) ;
goto V_12;
}
V_2 = V_4 ;
V_11 += V_9 ;
do {
V_2 -> V_9 = V_9 ;
V_2 -> V_13 = V_10 ;
F_13 ( V_2 ) ;
F_14 ( V_2 , V_11 ) ;
F_9 ( V_2 ) ;
F_15 ( V_2 , V_9 ) ;
} while ( ( V_2 = V_2 -> V_16 ) );
V_12:
return V_4 ;
}
static int T_4 F_16 ( void )
{
F_17 ( L_1 ) ;
F_18 ( & V_17 ) ;
F_18 ( & V_18 ) ;
return 0 ;
}
static void T_5 F_19 ( void )
{
F_20 ( & V_17 ) ;
F_20 ( & V_18 ) ;
}
