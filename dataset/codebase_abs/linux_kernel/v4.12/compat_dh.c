long F_1 ( struct V_1 T_1 * V_2 ,
char T_1 * V_3 , T_2 V_4 ,
struct V_5 T_1 * V_6 )
{
struct V_7 V_8 ;
struct V_5 V_9 ;
if ( ! V_6 )
return F_2 ( V_2 , V_3 , V_4 , NULL ) ;
if ( F_3 ( & V_9 , V_6 , sizeof( V_9 ) ) != 0 )
return - V_10 ;
V_8 . V_11 = F_4 ( V_9 . V_11 ) ;
V_8 . V_12 = F_4 ( V_9 . V_12 ) ;
V_8 . V_13 = V_9 . V_13 ;
return F_2 ( V_2 , V_3 , V_4 , & V_8 ) ;
}
