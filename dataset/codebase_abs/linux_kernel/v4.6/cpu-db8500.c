static void T_1 F_1 ( void )
{
F_2 () ;
F_3 () ;
}
static T_2 F_4 ( int V_1 , void * V_2 , T_3 V_3 )
{
T_2 V_4 = V_3 ( V_1 , V_2 ) ;
int V_5 = ! F_5 () ;
if ( V_4 == V_6 && F_6 ( V_5 ) )
F_7 ( V_1 , F_8 ( V_5 ) ) ;
return V_4 ;
}
static const char * F_9 ( void )
{
void T_4 * V_7 ;
const char * V_8 ;
V_7 = F_10 ( V_9 , 0x20 ) ;
if ( ! V_7 )
return NULL ;
F_11 ( V_7 , 0x14 ) ;
V_8 = F_12 ( V_10 , L_1 ,
F_13 ( ( V_11 * ) V_7 + 0 ) ,
F_13 ( ( V_11 * ) V_7 + 1 ) , F_13 ( ( V_11 * ) V_7 + 2 ) ,
F_13 ( ( V_11 * ) V_7 + 3 ) , F_13 ( ( V_11 * ) V_7 + 4 ) ) ;
F_14 ( V_7 ) ;
return V_8 ;
}
static struct V_12 * T_1 F_15 ( void )
{
const char * V_13 = F_9 () ;
return F_16 ( V_13 ) ;
}
static void T_1 F_17 ( void )
{
struct V_12 * V_14 = F_15 () ;
if ( F_18 ( L_2 ) )
F_19 ( NULL , V_15 ,
V_16 , V_14 ) ;
else
F_19 ( NULL , V_15 ,
V_17 , V_14 ) ;
}
