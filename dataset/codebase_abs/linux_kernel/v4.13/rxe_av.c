int F_1 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_5 * V_6 ;
if ( F_2 ( V_4 ) != 1 ) {
F_3 ( L_1 , F_2 ( V_4 ) ) ;
return - V_7 ;
}
V_6 = & V_2 -> V_6 ;
if ( F_4 ( V_4 ) & V_8 ) {
T_1 V_9 = F_5 ( V_4 ) -> V_9 ;
if ( V_9 > V_6 -> V_4 . V_10 ) {
F_3 ( L_2 , V_9 ) ;
return - V_7 ;
}
}
return 0 ;
}
int F_6 ( struct V_1 * V_2 , T_1 V_11 ,
struct V_12 * V_13 , struct V_3 * V_4 )
{
memset ( V_13 , 0 , sizeof( * V_13 ) ) ;
memcpy ( & V_13 -> V_14 , F_5 ( V_4 ) ,
sizeof( * F_5 ( V_4 ) ) ) ;
V_13 -> V_11 = V_11 ;
return 0 ;
}
int F_7 ( struct V_1 * V_2 , struct V_12 * V_13 ,
struct V_3 * V_4 )
{
V_4 -> type = V_15 ;
memcpy ( F_8 ( V_4 ) , & V_13 -> V_14 , sizeof( V_13 -> V_14 ) ) ;
F_9 ( V_4 , V_8 ) ;
F_10 ( V_4 , V_13 -> V_11 ) ;
return 0 ;
}
int F_11 ( struct V_1 * V_2 ,
struct V_12 * V_13 ,
struct V_3 * V_4 ,
struct V_16 * V_17 ,
union V_18 * V_19 )
{
F_12 ( & V_13 -> V_20 . V_21 , V_19 ) ;
F_12 ( & V_13 -> V_22 . V_21 , & F_5 ( V_4 ) -> V_23 ) ;
V_13 -> V_24 = F_13 ( V_17 -> V_25 , V_19 ) ;
return 0 ;
}
struct V_12 * F_14 ( struct V_26 * V_27 )
{
if ( ! V_27 || ! V_27 -> V_28 )
return NULL ;
if ( F_15 ( V_27 -> V_28 ) == V_29 || F_15 ( V_27 -> V_28 ) == V_30 )
return & V_27 -> V_28 -> V_31 ;
return ( V_27 -> V_32 ) ? & V_27 -> V_32 -> V_13 : NULL ;
}
