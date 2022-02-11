static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_3 * V_5 = V_2 -> V_5 ;
int V_6 ;
V_6 = F_2 ( V_5 , 0 , 24576000 , V_7 ) ;
if ( V_6 < 0 )
return V_6 ;
V_6 = F_3 ( V_5 , 0xFF , 0xFF , 8 , 32 ) ;
if ( V_6 < 0 )
return V_6 ;
V_6 = F_3 ( V_4 , 0xFF , 0xFF , 8 , 32 ) ;
if ( V_6 < 0 )
return V_6 ;
return 0 ;
}
static int T_1 F_4 ( void )
{
int V_6 ;
V_8 = F_5 ( L_1 , - 1 ) ;
if ( ! V_8 )
return - V_9 ;
F_6 ( V_8 , & V_10 ) ;
V_6 = F_7 ( V_8 ) ;
if ( V_6 )
F_8 ( V_8 ) ;
return V_6 ;
}
static void T_2 F_9 ( void )
{
F_10 ( V_8 ) ;
}
