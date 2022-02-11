static int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
struct V_8 * V_9 = V_6 -> V_9 ;
unsigned int V_10 [] = { 0 , 4 , 1 , 5 , 2 , 6 , 3 , 7 } ;
int V_11 = 0 ;
V_11 = F_2 ( V_9 , F_3 ( V_10 ) ,
V_10 , F_3 ( V_10 ) , V_10 ) ;
if ( V_11 < 0 )
return V_11 ;
return 0 ;
}
static int T_1 F_4 ( void )
{
int V_11 ;
V_12 = F_5 ( L_1 , - 1 ) ;
if ( ! V_12 )
return - V_13 ;
F_6 ( V_12 , & V_14 ) ;
V_11 = F_7 ( V_12 ) ;
if ( V_11 )
F_8 ( V_12 ) ;
return V_11 ;
}
static void T_2 F_9 ( void )
{
F_10 ( V_12 ) ;
}
