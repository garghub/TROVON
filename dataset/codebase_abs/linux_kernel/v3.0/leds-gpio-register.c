struct V_1 * T_1 F_1 (
int V_2 , const struct V_3 * V_4 )
{
struct V_1 * V_5 ;
struct V_3 V_6 = * V_4 ;
V_6 . V_7 = F_2 ( V_4 -> V_7 ,
V_4 -> V_8 * sizeof( * V_4 -> V_7 ) , V_9 ) ;
if ( ! V_6 . V_7 )
return F_3 ( - V_10 ) ;
V_5 = F_4 ( NULL , L_1 , V_2 ,
NULL , 0 , & V_6 , sizeof( V_6 ) ) ;
if ( F_5 ( V_5 ) )
F_6 ( V_6 . V_7 ) ;
return V_5 ;
}
