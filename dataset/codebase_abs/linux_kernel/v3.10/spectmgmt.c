static void F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
const T_1 * V_5 , const T_1 * V_6 ,
T_1 V_7 )
{
struct V_8 * V_9 = V_2 -> V_9 ;
struct V_10 * V_11 ;
struct V_12 * V_13 ;
V_11 = F_2 ( sizeof( * V_13 ) + V_9 -> V_14 . V_15 +
sizeof( struct V_3 ) ) ;
if ( ! V_11 )
return;
F_3 ( V_11 , V_9 -> V_14 . V_15 ) ;
V_13 = (struct V_12 * ) F_4 ( V_11 , 24 ) ;
memset ( V_13 , 0 , 24 ) ;
memcpy ( V_13 -> V_5 , V_5 , V_16 ) ;
memcpy ( V_13 -> V_17 , V_2 -> V_18 . V_19 , V_16 ) ;
memcpy ( V_13 -> V_6 , V_6 , V_16 ) ;
V_13 -> V_20 = F_5 ( V_21 |
V_22 ) ;
F_4 ( V_11 , 1 + sizeof( V_13 -> V_23 . V_24 . V_23 . V_25 ) ) ;
V_13 -> V_23 . V_24 . V_26 = V_27 ;
V_13 -> V_23 . V_24 . V_23 . V_25 . V_28 =
V_29 ;
V_13 -> V_23 . V_24 . V_23 . V_25 . V_7 = V_7 ;
V_13 -> V_23 . V_24 . V_23 . V_25 . V_30 = V_31 ;
V_13 -> V_23 . V_24 . V_23 . V_25 . V_32 =
sizeof( struct V_3 ) ;
memset ( & V_13 -> V_23 . V_24 . V_23 . V_25 . V_33 , 0 ,
sizeof( struct V_3 ) ) ;
V_13 -> V_23 . V_24 . V_23 . V_25 . V_33 . V_34 = V_4 -> V_34 ;
V_13 -> V_23 . V_24 . V_23 . V_25 . V_33 . V_35 |=
V_36 ;
V_13 -> V_23 . V_24 . V_23 . V_25 . V_33 . type = V_4 -> type ;
F_6 ( V_2 , V_11 ) ;
}
void F_7 ( struct V_1 * V_2 ,
struct V_12 * V_37 ,
T_2 V_38 )
{
F_1 ( V_2 ,
& V_37 -> V_23 . V_24 . V_23 . V_25 . V_33 ,
V_37 -> V_17 , V_37 -> V_6 ,
V_37 -> V_23 . V_24 . V_23 . V_25 . V_7 ) ;
}
