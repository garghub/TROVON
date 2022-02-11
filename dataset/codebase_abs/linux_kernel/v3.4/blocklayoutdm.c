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
V_5 -> V_20 = F_5 ( 1 + sizeof( V_7 ) , V_21 ) ;
if ( ! V_5 -> V_20 )
goto V_22;
memset ( & V_7 , 0 , sizeof( V_7 ) ) ;
V_7 . V_23 = F_6 ( V_2 ) ;
V_7 . V_24 = F_7 ( V_2 ) ;
memcpy ( V_5 -> V_20 , & V_9 , sizeof( V_9 ) ) ;
V_12 = ( T_2 * ) V_5 -> V_20 ;
memcpy ( & V_12 [ sizeof( V_9 ) ] , & V_7 , sizeof( V_7 ) ) ;
V_5 -> V_25 = sizeof( V_9 ) + V_9 . V_11 ;
F_8 ( & V_16 -> V_19 , & V_13 ) ;
if ( F_9 ( V_16 -> V_26 , V_5 ) < 0 ) {
F_10 ( & V_16 -> V_19 , & V_13 ) ;
goto V_22;
}
F_11 ( V_27 ) ;
F_12 () ;
F_13 ( V_28 ) ;
F_10 ( & V_16 -> V_19 , & V_13 ) ;
V_22:
F_14 ( V_5 -> V_20 ) ;
}
static void F_15 ( struct V_29 * V_30 )
{
int V_31 ;
F_4 ( L_2 , V_18 ) ;
V_31 = F_16 ( V_30 -> V_32 ) ;
if ( V_31 )
F_17 ( V_33 L_3 ,
V_18 , V_31 ) ;
F_1 ( V_30 -> V_1 , V_30 -> V_32 -> V_34 ) ;
}
void F_18 ( struct V_29 * V_30 )
{
if ( V_30 ) {
if ( V_30 -> V_32 ) {
F_4 ( L_4 ,
V_18 ,
F_6 ( V_30 -> V_32 -> V_34 ) ,
F_7 ( V_30 -> V_32 -> V_34 ) ) ;
F_15 ( V_30 ) ;
}
F_14 ( V_30 ) ;
}
}
