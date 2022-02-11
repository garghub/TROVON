void F_1 ( const struct V_1 * V_2 , int V_3 )
{
struct V_4 * V_5 ;
struct V_6 * V_7 ;
V_5 = F_2 ( V_2 -> V_8 , V_3 ) ;
if ( V_5 == NULL )
return;
V_7 = F_3 ( V_2 -> V_7 , V_9 ) ;
if ( V_7 == NULL )
return;
if ( F_4 ( V_7 ) )
F_5 ( V_7 , V_7 -> V_10 ) ;
V_7 -> V_5 = V_5 ;
F_6 ( V_7 ) ;
}
