static int F_1 ( void * V_1 , const void * V_2 , T_1 V_3 ,
T_1 V_4 )
{
struct V_5 * V_6 = V_1 ;
const void * V_7 ;
T_1 V_8 ;
int V_9 ;
V_7 = V_6 -> V_2 ;
V_8 = V_6 -> V_10 ;
V_6 -> V_2 = V_2 ;
V_6 -> V_10 = V_3 ;
V_9 = F_2 ( V_6 ) ;
V_6 -> V_2 = V_7 ;
V_6 -> V_10 = V_8 ;
return V_9 ;
}
static int F_3 ( struct V_5 * V_6 )
{
enum V_11 V_12 = V_13 ;
if ( V_12 >= V_14 ) {
F_4 ( L_1 , V_12 ) ;
return - V_15 ;
}
return F_5 ( NULL , 0 ,
V_6 -> V_2 , V_6 -> V_10 ,
( void * ) 1UL , V_12 ,
F_1 , V_6 ) ;
}
static int T_2 F_6 ( void )
{
return F_7 ( & V_16 ) ;
}
static void T_3 F_8 ( void )
{
F_9 ( & V_16 ) ;
}
