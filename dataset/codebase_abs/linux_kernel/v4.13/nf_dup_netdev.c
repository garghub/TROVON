static void F_1 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
if ( F_2 ( V_2 ) )
F_3 ( V_2 , V_2 -> V_5 ) ;
V_2 -> V_4 = V_4 ;
F_4 ( V_2 ) ;
}
void F_5 ( const struct V_6 * V_7 , int V_8 )
{
struct V_3 * V_4 ;
V_4 = F_6 ( F_7 ( V_7 ) , V_8 ) ;
if ( ! V_4 ) {
F_8 ( V_7 -> V_2 ) ;
return;
}
F_1 ( V_7 -> V_2 , V_4 ) ;
}
void F_9 ( const struct V_6 * V_7 , int V_8 )
{
struct V_3 * V_4 ;
struct V_1 * V_2 ;
V_4 = F_6 ( F_7 ( V_7 ) , V_8 ) ;
if ( V_4 == NULL )
return;
V_2 = F_10 ( V_7 -> V_2 , V_9 ) ;
if ( V_2 )
F_1 ( V_2 , V_4 ) ;
}
