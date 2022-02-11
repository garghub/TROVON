int F_1 ( struct V_1 * V_2 , union V_3 * V_4 , T_1 V_5 )
{
struct V_6 V_7 ;
struct V_8 V_9 ;
int V_10 ;
memset ( & V_7 , 0 , sizeof( V_7 ) ) ;
memset ( & V_9 , 0 , sizeof( V_9 ) ) ;
V_7 . V_11 . V_12 = F_2 ( V_13 ) ;
memcpy ( V_7 . V_14 , V_4 , sizeof( * V_4 ) ) ;
V_7 . V_5 = F_3 ( V_5 ) ;
V_10 = F_4 ( V_2 , & V_7 , sizeof( V_7 ) , & V_9 , sizeof( V_9 ) ) ;
if ( V_10 )
return V_10 ;
if ( V_9 . V_11 . V_15 )
V_10 = F_5 ( & V_9 . V_11 ) ;
return V_10 ;
}
int F_6 ( struct V_1 * V_2 , union V_3 * V_4 , T_1 V_5 )
{
struct V_16 V_7 ;
struct V_17 V_9 ;
int V_10 ;
memset ( & V_7 , 0 , sizeof( V_7 ) ) ;
memset ( & V_9 , 0 , sizeof( V_9 ) ) ;
V_7 . V_11 . V_12 = F_2 ( V_18 ) ;
memcpy ( V_7 . V_14 , V_4 , sizeof( * V_4 ) ) ;
V_7 . V_5 = F_3 ( V_5 ) ;
V_10 = F_4 ( V_2 , & V_7 , sizeof( V_7 ) , & V_9 , sizeof( V_9 ) ) ;
if ( V_10 )
return V_10 ;
if ( V_9 . V_11 . V_15 )
V_10 = F_5 ( & V_9 . V_11 ) ;
return V_10 ;
}
