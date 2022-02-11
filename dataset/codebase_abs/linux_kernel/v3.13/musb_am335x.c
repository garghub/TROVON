static int F_1 ( struct V_1 * V_2 )
{
int V_3 ;
F_2 ( & V_2 -> V_4 ) ;
V_3 = F_3 ( V_2 -> V_4 . V_5 , NULL , NULL , & V_2 -> V_4 ) ;
if ( V_3 )
goto V_6;
return 0 ;
V_6:
F_4 ( & V_2 -> V_4 ) ;
return V_3 ;
}
static int F_5 ( struct V_7 * V_4 , void * V_8 )
{
struct V_1 * V_2 = F_6 ( V_4 ) ;
F_7 ( V_2 ) ;
return 0 ;
}
static int F_8 ( struct V_1 * V_2 )
{
F_9 ( & V_2 -> V_4 , NULL , F_5 ) ;
F_4 ( & V_2 -> V_4 ) ;
return 0 ;
}
