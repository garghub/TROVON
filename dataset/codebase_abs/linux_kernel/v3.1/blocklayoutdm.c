static void F_1 ( T_1 V_1 )
{
struct V_2 V_3 ;
struct V_4 V_5 ;
struct V_6 V_7 = {
. type = V_8 ,
. V_9 = sizeof( V_5 ) ,
} ;
T_2 * V_10 ;
F_2 ( V_11 , V_12 ) ;
F_3 ( L_1 , V_13 ) ;
memset ( & V_3 , 0 , sizeof( V_3 ) ) ;
V_3 . V_14 = F_4 ( 1 + sizeof( V_5 ) , V_15 ) ;
if ( ! V_3 . V_14 )
goto V_16;
memset ( & V_5 , 0 , sizeof( V_5 ) ) ;
V_5 . V_17 = F_5 ( V_1 ) ;
V_5 . V_18 = F_6 ( V_1 ) ;
memcpy ( V_3 . V_14 , & V_7 , sizeof( V_7 ) ) ;
V_10 = ( T_2 * ) V_3 . V_14 ;
memcpy ( & V_10 [ sizeof( V_7 ) ] , & V_5 , sizeof( V_5 ) ) ;
V_3 . V_19 = sizeof( V_7 ) + V_7 . V_9 ;
F_7 ( & V_20 , & V_11 ) ;
if ( F_8 ( V_21 -> V_22 , & V_3 ) < 0 ) {
F_9 ( & V_20 , & V_11 ) ;
goto V_16;
}
F_10 ( V_23 ) ;
F_11 () ;
F_12 ( V_24 ) ;
F_9 ( & V_20 , & V_11 ) ;
V_16:
F_13 ( V_3 . V_14 ) ;
}
static void F_14 ( struct V_25 * V_26 )
{
int V_27 ;
F_3 ( L_2 , V_13 ) ;
V_27 = F_15 ( V_26 -> V_28 ) ;
if ( V_27 )
F_16 ( V_29 L_3 ,
V_13 , V_27 ) ;
F_1 ( V_26 -> V_28 -> V_30 ) ;
}
void F_17 ( struct V_25 * V_26 )
{
if ( V_26 ) {
if ( V_26 -> V_28 ) {
F_3 ( L_4 ,
V_13 ,
F_5 ( V_26 -> V_28 -> V_30 ) ,
F_6 ( V_26 -> V_28 -> V_30 ) ) ;
F_14 ( V_26 ) ;
}
F_13 ( V_26 ) ;
}
}
