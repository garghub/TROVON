int F_1 ( struct V_1 * V_1 )
{
F_2 ( & V_2 ) ;
F_3 ( & V_1 -> V_3 , & V_4 ) ;
F_4 ( & V_2 ) ;
return 0 ;
}
void F_5 ( struct V_1 * V_1 )
{
F_2 ( & V_2 ) ;
F_6 ( & V_1 -> V_3 ) ;
F_4 ( & V_2 ) ;
}
int F_7 ( struct V_5 * V_5 )
{
struct V_1 * V_1 ;
F_8 (edac_mce, &edac_mce_list, list) {
if ( V_1 -> V_6 ( V_1 -> V_7 , V_5 ) )
return 1 ;
}
return 0 ;
}
