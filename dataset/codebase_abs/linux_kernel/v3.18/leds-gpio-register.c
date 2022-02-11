struct V_1 * T_1 F_1 (
int V_2 , const struct V_3 * V_4 )
{
struct V_1 * V_5 ;
struct V_3 V_6 = * V_4 ;
if ( ! V_4 -> V_7 )
return F_2 ( - V_8 ) ;
V_6 . V_9 = F_3 ( V_4 -> V_9 ,
V_4 -> V_7 * sizeof( * V_4 -> V_9 ) , V_10 ) ;
if ( ! V_6 . V_9 )
return F_2 ( - V_11 ) ;
V_5 = F_4 ( NULL , L_1 , V_2 ,
NULL , 0 , & V_6 , sizeof( V_6 ) ) ;
if ( F_5 ( V_5 ) )
F_6 ( V_6 . V_9 ) ;
return V_5 ;
}
