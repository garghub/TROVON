static int F_1 ( struct V_1 * V_2 )
{
int V_3 ;
struct V_4 * V_5 = V_2 -> V_6 . V_7 ;
F_2 ( & V_2 -> V_6 ) ;
F_3 ( & V_2 -> V_6 ) ;
V_3 = F_4 ( V_5 , NULL , NULL , & V_2 -> V_6 ) ;
if ( V_3 )
F_5 ( & V_2 -> V_6 , L_1 ) ;
return V_3 ;
}
static int F_6 ( struct V_1 * V_2 )
{
F_7 ( & V_2 -> V_6 ) ;
F_8 ( & V_2 -> V_6 ) ;
return 0 ;
}
static int F_9 ( struct V_8 * V_6 )
{
F_7 ( V_6 ) ;
return 0 ;
}
static int F_10 ( struct V_8 * V_6 )
{
F_3 ( V_6 ) ;
return 0 ;
}
