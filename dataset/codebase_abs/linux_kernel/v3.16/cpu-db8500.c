void T_1 F_1 ( void )
{
F_2 ( V_1 , F_3 ( V_1 ) ) ;
F_4 () ;
F_2 ( V_2 , F_3 ( V_2 ) ) ;
if ( F_5 () )
F_2 ( V_3 , F_3 ( V_3 ) ) ;
else
F_2 ( V_4 , F_3 ( V_4 ) ) ;
}
static T_2 F_6 ( int V_5 , void * V_6 , T_3 V_7 )
{
T_2 V_8 = V_7 ( V_5 , V_6 ) ;
int V_9 = ! F_7 () ;
if ( V_8 == V_10 && F_8 ( V_9 ) )
F_9 ( V_5 , F_10 ( V_9 ) ) ;
return V_8 ;
}
static const char * F_11 ( void )
{
void T_4 * V_11 = F_12 ( V_12 ) ;
F_13 ( V_11 , 0x14 ) ;
return F_14 ( V_13 , L_1 ,
F_15 ( ( V_14 * ) V_11 + 0 ) ,
F_15 ( ( V_14 * ) V_11 + 1 ) , F_15 ( ( V_14 * ) V_11 + 2 ) ,
F_15 ( ( V_14 * ) V_11 + 3 ) , F_15 ( ( V_14 * ) V_11 + 4 ) ) ;
}
static struct V_15 * T_1 F_16 ( void )
{
const char * V_16 = F_11 () ;
return F_17 ( V_16 ) ;
}
static void T_1 F_18 ( void )
{
struct V_15 * V_17 = F_16 () ;
if ( F_19 ( L_2 ) )
F_20 ( NULL , V_18 ,
V_19 , V_17 ) ;
else
F_20 ( NULL , V_18 ,
V_20 , V_17 ) ;
}
