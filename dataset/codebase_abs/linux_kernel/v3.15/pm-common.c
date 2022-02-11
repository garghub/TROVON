void F_1 ( struct V_1 * V_2 , int V_3 )
{
for (; V_3 > 0 ; V_3 -- , V_2 ++ ) {
V_2 -> V_4 = F_2 ( V_2 -> V_5 ) ;
F_3 ( L_1 , V_2 -> V_5 , V_2 -> V_4 ) ;
}
}
void F_4 ( const struct V_1 * V_2 , int V_3 )
{
for (; V_3 > 0 ; V_3 -- , V_2 ++ ) {
F_5 ( L_2 ,
V_2 -> V_5 , V_2 -> V_4 , F_2 ( V_2 -> V_5 ) ) ;
F_6 ( V_2 -> V_4 , V_2 -> V_5 ) ;
}
}
void F_7 ( const struct V_1 * V_2 , int V_3 )
{
for (; V_3 > 0 ; V_3 -- , V_2 ++ )
F_6 ( V_2 -> V_4 , V_2 -> V_5 ) ;
}
