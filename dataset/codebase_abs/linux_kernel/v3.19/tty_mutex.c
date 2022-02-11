void T_1 F_1 ( struct V_1 * V_2 )
{
if ( V_2 -> V_3 != V_4 ) {
F_2 ( L_1 , V_2 ) ;
F_3 ( 1 ) ;
return;
}
F_4 ( V_2 ) ;
F_5 ( & V_2 -> V_5 ) ;
}
void T_1 F_6 ( struct V_1 * V_2 )
{
if ( V_2 -> V_3 != V_4 ) {
F_2 ( L_2 , V_2 ) ;
F_3 ( 1 ) ;
return;
}
F_7 ( & V_2 -> V_5 ) ;
F_8 ( V_2 ) ;
}
void T_1 F_9 ( struct V_1 * V_2 )
{
if ( V_2 && V_2 != V_2 -> V_6 ) {
F_3 ( ! F_10 ( & V_2 -> V_6 -> V_5 ) ||
! V_2 -> V_7 -> type == V_8 ||
! V_2 -> V_7 -> type == V_9 ) ;
F_1 ( V_2 ) ;
}
}
void T_1 F_11 ( struct V_1 * V_2 )
{
if ( V_2 && V_2 != V_2 -> V_6 )
F_6 ( V_2 ) ;
}
void F_12 ( struct V_1 * V_2 )
{
F_13 ( & V_2 -> V_5 , V_10 ) ;
}
