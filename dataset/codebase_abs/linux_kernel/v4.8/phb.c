bool F_1 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_5 * V_6 ;
V_6 = F_2 ( V_2 ) ;
if ( ! V_6 )
return false ;
V_2 -> V_2 . V_7 . V_8 = V_6 ;
return ( V_9 -> V_10 ( V_4 ) == 0 ) ;
}
void F_3 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_4 ( V_2 ) ;
if ( V_6 ) {
if ( V_6 -> V_11 == V_12 ) {
F_5 ( & V_2 -> V_2 , L_1 ) ;
return;
}
V_2 -> V_2 . V_7 . V_8 = NULL ;
F_6 ( V_6 ) ;
}
}
