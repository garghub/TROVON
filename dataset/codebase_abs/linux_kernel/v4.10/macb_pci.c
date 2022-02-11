static int F_1 ( struct V_1 * V_2 , const struct V_3 * V_4 )
{
int V_5 ;
struct V_6 * V_7 ;
struct V_8 V_9 ;
struct V_10 V_11 ;
struct V_12 V_13 [ 2 ] ;
V_5 = F_2 ( V_2 ) ;
if ( V_5 < 0 ) {
F_3 ( & V_2 -> V_14 , L_1 , V_5 ) ;
return V_5 ;
}
F_4 ( V_2 ) ;
memset ( V_13 , 0x00 , sizeof( struct V_12 ) * F_5 ( V_13 ) ) ;
V_13 [ 0 ] . V_15 = F_6 ( V_2 , 0 ) ;
V_13 [ 0 ] . V_16 = F_7 ( V_2 , 0 ) ;
V_13 [ 0 ] . V_17 = V_18 ;
V_13 [ 0 ] . V_19 = V_20 ;
V_13 [ 1 ] . V_15 = F_8 ( V_2 , 0 ) ;
V_13 [ 1 ] . V_17 = V_18 ;
V_13 [ 1 ] . V_19 = V_21 ;
F_9 ( & V_2 -> V_14 , L_2 ,
& V_13 [ 0 ] . V_15 ) ;
memset ( & V_11 , 0 , sizeof( V_11 ) ) ;
V_11 . V_22 = F_10 ( & V_2 -> V_14 , L_3 , NULL , 0 ,
V_23 ) ;
if ( F_11 ( V_11 . V_22 ) ) {
V_5 = F_12 ( V_11 . V_22 ) ;
goto V_24;
}
V_11 . V_25 = F_10 ( & V_2 -> V_14 , L_4 , NULL , 0 ,
V_26 ) ;
if ( F_11 ( V_11 . V_25 ) ) {
V_5 = F_12 ( V_11 . V_25 ) ;
goto V_27;
}
memset ( & V_9 , 0 , sizeof( V_9 ) ) ;
V_9 . V_28 = & V_2 -> V_14 ;
V_9 . V_29 = V_2 -> V_14 . V_29 ;
V_9 . V_17 = V_30 ;
V_9 . V_4 = V_2 -> V_31 ;
V_9 . V_13 = V_13 ;
V_9 . V_32 = F_5 ( V_13 ) ;
V_9 . V_33 = & V_11 ;
V_9 . V_34 = sizeof( V_11 ) ;
V_9 . V_35 = V_2 -> V_35 ;
V_7 = F_13 ( & V_9 ) ;
if ( F_11 ( V_7 ) ) {
V_5 = F_12 ( V_7 ) ;
goto V_36;
}
F_14 ( V_2 , V_7 ) ;
return 0 ;
V_36:
F_15 ( V_11 . V_25 ) ;
V_27:
F_15 ( V_11 . V_22 ) ;
V_24:
return V_5 ;
}
static void F_16 ( struct V_1 * V_2 )
{
struct V_6 * V_7 = F_17 ( V_2 ) ;
struct V_10 * V_11 = F_18 ( & V_7 -> V_14 ) ;
F_19 ( V_7 ) ;
F_15 ( V_11 -> V_22 ) ;
F_15 ( V_11 -> V_25 ) ;
}
