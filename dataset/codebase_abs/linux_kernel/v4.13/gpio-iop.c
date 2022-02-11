static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 ;
struct V_5 * V_6 ;
void T_1 * V_7 ;
int V_8 ;
V_6 = F_2 ( & V_2 -> V_9 , sizeof( * V_6 ) , V_10 ) ;
if ( ! V_6 )
return - V_11 ;
V_4 = F_3 ( V_2 , V_12 , 0 ) ;
V_7 = F_4 ( & V_2 -> V_9 , V_4 ) ;
if ( F_5 ( V_7 ) )
return F_6 ( V_7 ) ;
V_8 = F_7 ( V_6 , & V_2 -> V_9 , 1 , V_7 + V_13 ,
V_7 + V_14 , NULL , NULL , V_7 + V_15 , 0 ) ;
if ( V_8 )
return V_8 ;
V_6 -> V_7 = 0 ;
V_6 -> V_16 = V_17 ;
return F_8 ( & V_2 -> V_9 , V_6 , NULL ) ;
}
static int T_2 F_9 ( void )
{
return F_10 ( & V_18 ) ;
}
