void F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 ;
if ( V_2 -> V_5 -> V_6 )
return;
V_4 = V_2 -> V_7 -> V_3 ;
V_2 -> V_8 = V_4 -> V_9 ;
V_2 -> V_10 = ( V_2 -> V_10 + V_4 -> V_9 ) - 1 ;
}
void F_2 ( struct V_11 * V_12 , struct V_1 * V_2 )
{
if ( V_12 -> V_13 || V_12 -> V_14 )
return;
V_12 -> V_14 = 1 ;
F_3 ( & V_2 -> V_15 ) ;
V_2 -> V_10 += 1 ;
F_4 ( L_1 , V_2 -> V_10 ) ;
F_5 ( & V_2 -> V_15 ) ;
}
