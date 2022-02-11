int F_1 ( struct V_1 * V_2 , T_1 * V_3 )
{
struct V_4 V_5 ;
struct V_6 V_7 ;
int V_8 ;
memset ( & V_5 , 0 , sizeof( V_5 ) ) ;
memset ( & V_7 , 0 , sizeof( V_7 ) ) ;
V_5 . V_9 . V_10 = F_2 ( V_11 ) ;
V_8 = F_3 ( V_2 , & V_5 , sizeof( V_5 ) , & V_7 , sizeof( V_7 ) ) ;
if ( V_8 )
return V_8 ;
if ( V_7 . V_9 . V_12 )
return F_4 ( & V_7 . V_9 ) ;
* V_3 = F_5 ( V_7 . V_3 ) & 0xffffff ;
return V_8 ;
}
int F_6 ( struct V_1 * V_2 , T_1 V_3 )
{
struct V_13 V_5 ;
struct V_14 V_7 ;
int V_8 ;
memset ( & V_5 , 0 , sizeof( V_5 ) ) ;
memset ( & V_7 , 0 , sizeof( V_7 ) ) ;
V_5 . V_9 . V_10 = F_2 ( V_15 ) ;
V_5 . V_3 = F_7 ( V_3 ) ;
V_8 = F_3 ( V_2 , & V_5 , sizeof( V_5 ) , & V_7 , sizeof( V_7 ) ) ;
if ( V_8 )
return V_8 ;
if ( V_7 . V_9 . V_12 )
return F_4 ( & V_7 . V_9 ) ;
return V_8 ;
}
