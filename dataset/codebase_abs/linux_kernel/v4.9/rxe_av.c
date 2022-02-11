int F_1 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_5 * V_6 ;
if ( V_4 -> V_7 != 1 ) {
F_2 ( L_1 , V_4 -> V_7 ) ;
return - V_8 ;
}
V_6 = & V_2 -> V_6 ;
if ( V_4 -> V_9 & V_10 ) {
if ( V_4 -> V_11 . V_12 > V_6 -> V_4 . V_13 ) {
F_2 ( L_2 ,
V_4 -> V_11 . V_12 ) ;
return - V_8 ;
}
}
return 0 ;
}
int F_3 ( struct V_1 * V_2 , T_1 V_7 ,
struct V_14 * V_15 , struct V_3 * V_4 )
{
memset ( V_15 , 0 , sizeof( * V_15 ) ) ;
memcpy ( & V_15 -> V_11 , & V_4 -> V_11 , sizeof( V_4 -> V_11 ) ) ;
V_15 -> V_7 = V_7 ;
return 0 ;
}
int F_4 ( struct V_1 * V_2 , struct V_14 * V_15 ,
struct V_3 * V_4 )
{
memcpy ( & V_4 -> V_11 , & V_15 -> V_11 , sizeof( V_15 -> V_11 ) ) ;
V_4 -> V_7 = V_15 -> V_7 ;
return 0 ;
}
int F_5 ( struct V_1 * V_2 ,
struct V_14 * V_15 ,
struct V_3 * V_4 ,
struct V_16 * V_17 ,
union V_18 * V_19 )
{
F_6 ( & V_15 -> V_20 . V_21 , V_19 ) ;
F_6 ( & V_15 -> V_22 . V_21 , & V_4 -> V_11 . V_23 ) ;
V_15 -> V_24 = F_7 ( V_17 -> V_25 , V_19 ) ;
return 0 ;
}
struct V_14 * F_8 ( struct V_26 * V_27 )
{
if ( ! V_27 || ! V_27 -> V_28 )
return NULL ;
if ( F_9 ( V_27 -> V_28 ) == V_29 || F_9 ( V_27 -> V_28 ) == V_30 )
return & V_27 -> V_28 -> V_31 ;
return ( V_27 -> V_32 ) ? & V_27 -> V_32 -> V_15 : NULL ;
}
