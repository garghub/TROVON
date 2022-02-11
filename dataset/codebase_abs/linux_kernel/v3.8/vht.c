void F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_5 * V_6 ,
struct V_7 * V_8 )
{
if ( F_2 ( ! V_8 ) )
return;
memset ( V_8 , 0 , sizeof( * V_8 ) ) ;
if ( ! V_6 || ! V_4 -> V_8 . V_9 )
return;
V_8 -> V_9 = true ;
V_8 -> V_10 = F_3 ( V_6 -> V_11 ) ;
memcpy ( & V_8 -> V_12 , & V_6 -> V_13 ,
sizeof( struct V_14 ) ) ;
}
