static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 . V_6 ;
struct V_7 * V_7 ;
V_7 = F_2 ( V_2 , & V_8 ) ;
if ( F_3 ( V_7 ) )
return F_4 ( V_7 ) ;
return F_5 ( V_4 , NULL , NULL , & V_2 -> V_5 ) ;
}
static void F_6 ( struct V_1 * V_2 )
{
F_7 ( & V_2 -> V_5 ) ;
}
