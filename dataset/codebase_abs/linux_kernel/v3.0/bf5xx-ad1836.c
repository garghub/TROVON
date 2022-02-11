static int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
struct V_8 * V_9 = V_6 -> V_9 ;
struct V_8 * V_10 = V_6 -> V_10 ;
unsigned int V_11 [] = { 0 , 4 , 1 , 5 , 2 , 6 , 3 , 7 } ;
int V_12 = 0 ;
V_12 = F_2 ( V_9 , V_13 |
V_14 | V_15 ) ;
if ( V_12 < 0 )
return V_12 ;
V_12 = F_2 ( V_10 , V_13 |
V_14 | V_15 ) ;
if ( V_12 < 0 )
return V_12 ;
V_12 = F_3 ( V_9 , F_4 ( V_11 ) ,
V_11 , F_4 ( V_11 ) , V_11 ) ;
if ( V_12 < 0 )
return V_12 ;
return 0 ;
}
static int T_1 F_5 ( void )
{
int V_12 ;
V_16 = F_6 ( L_1 , - 1 ) ;
if ( ! V_16 )
return - V_17 ;
F_7 ( V_16 , & V_18 ) ;
V_12 = F_8 ( V_16 ) ;
if ( V_12 )
F_9 ( V_16 ) ;
return V_12 ;
}
static void T_2 F_10 ( void )
{
F_11 ( V_16 ) ;
}
