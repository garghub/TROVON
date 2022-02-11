void T_1 F_1 ( void )
{
F_2 ( V_1 , F_3 ( V_1 ) ) ;
F_4 () ;
F_2 ( V_2 , F_3 ( V_2 ) ) ;
V_3 = F_5 ( V_4 ) ;
}
static T_2 F_6 ( int V_5 , void * V_6 , T_3 V_7 )
{
T_2 V_8 = V_7 ( V_5 , V_6 ) ;
int V_9 = ! F_7 () ;
if ( V_8 == V_10 && F_8 ( V_9 ) )
F_9 ( V_5 , F_10 ( V_9 ) ) ;
return V_8 ;
}
static void T_1 F_11 ( struct V_11 * V_12 )
{
struct V_13 V_14 = {
. V_15 = true ,
} ;
F_12 ( V_12 , F_13 ( V_16 ) ,
V_17 , & V_14 ) ;
}
static const char * F_14 ( void )
{
void T_4 * V_18 = F_5 ( V_19 ) ;
return F_15 ( V_20 , L_1 ,
F_16 ( ( V_21 * ) V_18 + 1 ) ,
F_16 ( ( V_21 * ) V_18 + 1 ) , F_16 ( ( V_21 * ) V_18 + 2 ) ,
F_16 ( ( V_21 * ) V_18 + 3 ) , F_16 ( ( V_21 * ) V_18 + 4 ) ) ;
}
static struct V_11 * T_1 F_17 ( void )
{
const char * V_22 = F_14 () ;
return F_18 ( V_22 ) ;
}
struct V_11 * T_1 F_19 ( void )
{
struct V_11 * V_12 ;
int V_23 ;
V_12 = F_17 () ;
F_20 ( V_12 ) ;
F_11 ( V_12 ) ;
F_21 ( V_12 , V_24 , V_25 ) ;
F_22 ( V_12 ,
L_2 , - 1 , NULL , 0 ) ;
for ( V_23 = 0 ; V_23 < F_3 ( V_26 ) ; V_23 ++ )
V_26 [ V_23 ] -> V_6 . V_12 = V_12 ;
F_23 ( V_26 , F_3 ( V_26 ) ) ;
return V_12 ;
}
