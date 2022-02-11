static int F_1 ( struct V_1 * V_2 )
{
int V_3 = 0 ;
V_3 = F_2 ( V_4 , V_5 ) ;
if ( ! V_3 )
V_3 = F_2 ( V_6 , V_5 ) ;
if ( V_3 )
F_3 ( V_7 L_1 ) ;
return V_3 ;
}
static void F_4 ( struct V_1 * V_2 )
{
int V_3 = 0 ;
V_3 = F_2 ( V_4 , V_8 ) ;
if ( ! V_3 )
F_2 ( V_6 , V_8 ) ;
if ( V_3 )
F_3 ( V_7 L_2 ) ;
}
static int F_5 ( struct V_9 * V_10 )
{
F_6 ( & V_11 ) ;
return 0 ;
}
