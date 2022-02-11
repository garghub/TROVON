static int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_5 * V_6 ;
int V_7 ;
F_2 ( L_1 ) ;
V_6 = F_3 ( V_4 , & V_2 -> V_6 ) ;
if ( F_4 ( V_6 ) )
return F_5 ( V_6 ) ;
V_6 -> V_8 = V_2 ;
V_7 = F_6 ( V_6 , 0 ) ;
if ( V_7 )
goto V_9;
return 0 ;
V_9:
F_7 ( V_6 ) ;
return V_7 ;
}
int F_8 ( struct V_3 * V_4 , struct V_1 * V_1 )
{
F_2 ( L_1 ) ;
return F_1 ( V_1 , V_4 ) ;
}
