static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_3 * V_6 = V_2 -> V_7 ;
int V_8 ;
V_8 = F_2 ( V_4 ,
V_9 |
V_10 ) ;
if ( V_8 < 0 )
return V_8 ;
V_8 = F_2 ( V_6 , V_9 |
V_11 ) ;
return V_8 ;
}
static int T_1 F_3 ( void )
{
int V_8 ;
V_12 = F_4 ( L_1 , V_13 ) ;
if ( ! V_12 )
return - V_14 ;
F_5 ( V_12 , & V_15 ) ;
V_8 = F_6 ( V_12 ) ;
if ( V_8 )
F_7 ( V_12 ) ;
return V_8 ;
}
static void T_2 F_8 ( void )
{
F_9 ( V_12 ) ;
}
