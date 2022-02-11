void T_1 F_1 ( struct V_1 * V_2 )
{
struct V_1 * V_3 ;
V_3 = F_2 ( V_2 , sizeof( * V_3 ) , V_4 ) ;
if ( V_3 ) {
V_5 . V_6 . V_7 = V_3 ;
V_3 -> V_8 = F_2 ( V_2 -> V_8 ,
sizeof( struct V_9 ) * V_3 -> V_10 ,
V_4 ) ;
if ( ! V_3 -> V_8 )
F_3 ( V_11 L_1 ) ;
} else {
F_3 ( V_11 L_2 ) ;
}
}
void T_1 F_4 ( struct V_12 * V_13 )
{
memcpy ( & V_14 , V_13 , sizeof( struct V_12 ) ) ;
V_15 . V_6 . V_7 = & V_14 ;
}
void T_1 F_5 ( struct V_16 * V_2 )
{
struct V_16 * V_3 ;
V_3 = F_6 ( sizeof( * V_3 ) , V_4 ) ;
if ( V_3 ) {
memcpy ( V_3 , V_2 , sizeof( * V_3 ) ) ;
V_17 . V_6 . V_7 = V_3 ;
} else {
F_3 ( V_11 L_3 ) ;
}
}
void T_1 F_7 ( struct V_18 * V_2 )
{
struct V_18 * V_3 ;
V_3 = F_6 ( sizeof( * V_3 ) , V_4 ) ;
if ( V_3 ) {
memcpy ( V_3 , V_2 , sizeof( * V_3 ) ) ;
V_19 . V_6 . V_7 = V_3 ;
} else {
F_3 ( V_11 L_3 ) ;
}
}
void T_1 F_8 ( struct V_20 * V_21 )
{
struct V_20 * V_3 ;
V_3 = F_2 ( V_21 , sizeof( struct V_20 ) , V_4 ) ;
if ( ! V_3 )
F_3 ( V_11 L_4 , V_22 ) ;
V_23 . V_6 . V_7 = V_3 ;
}
