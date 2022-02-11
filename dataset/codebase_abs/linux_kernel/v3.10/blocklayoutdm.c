static void F_1 ( struct V_1 * V_1 , T_1 V_2 )
{
struct V_3 V_3 ;
struct V_4 * V_5 = & V_3 . V_5 ;
struct V_6 V_7 ;
struct V_8 V_9 = {
. type = V_10 ,
. V_11 = sizeof( V_7 ) ,
} ;
T_2 * V_12 ;
F_2 ( V_13 , V_14 ) ;
struct V_15 * V_16 = F_3 ( V_1 , V_17 ) ;
F_4 ( L_1 , V_18 ) ;
V_3 . V_19 = & V_16 -> V_19 ;
memset ( V_5 , 0 , sizeof( * V_5 ) ) ;
V_5 -> V_20 = sizeof( V_9 ) + V_9 . V_11 ;
V_5 -> V_21 = F_5 ( V_5 -> V_20 , V_22 ) ;
if ( ! V_5 -> V_21 )
goto V_23;
memset ( & V_7 , 0 , sizeof( V_7 ) ) ;
V_7 . V_24 = F_6 ( V_2 ) ;
V_7 . V_25 = F_7 ( V_2 ) ;
memcpy ( V_5 -> V_21 , & V_9 , sizeof( V_9 ) ) ;
V_12 = ( T_2 * ) V_5 -> V_21 ;
memcpy ( & V_12 [ sizeof( V_9 ) ] , & V_7 , sizeof( V_7 ) ) ;
F_8 ( & V_16 -> V_19 , & V_13 ) ;
if ( F_9 ( V_16 -> V_26 , V_5 ) < 0 ) {
F_10 ( & V_16 -> V_19 , & V_13 ) ;
goto V_23;
}
F_11 ( V_27 ) ;
F_12 () ;
F_13 ( V_28 ) ;
F_10 ( & V_16 -> V_19 , & V_13 ) ;
V_23:
F_14 ( V_5 -> V_21 ) ;
}
static void F_15 ( struct V_29 * V_30 )
{
F_4 ( L_2 , V_18 ) ;
F_16 ( V_30 -> V_31 ) ;
F_1 ( V_30 -> V_1 , V_30 -> V_31 -> V_32 ) ;
}
void F_17 ( struct V_29 * V_30 )
{
if ( V_30 ) {
if ( V_30 -> V_31 ) {
F_4 ( L_3 ,
V_18 ,
F_6 ( V_30 -> V_31 -> V_32 ) ,
F_7 ( V_30 -> V_31 -> V_32 ) ) ;
F_15 ( V_30 ) ;
}
F_14 ( V_30 ) ;
}
}
