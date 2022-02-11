static int F_1 ( struct V_1 * V_2 , void * V_3 ,
struct V_4 * V_5 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
struct V_8 * V_9 = V_3 ;
int V_10 , V_11 ;
V_11 = V_5 -> V_12 . V_13 . V_14 ;
V_10 = V_5 -> V_12 . V_13 . V_15 ;
if ( V_10 || V_11 ) {
V_10 = V_10 * 0xff / 0xffff ;
V_11 = V_11 * 0xff / 0xffff ;
V_9 -> V_16 -> V_17 [ 0 ] -> V_18 [ 0 ] = 0x51 ;
V_9 -> V_16 -> V_17 [ 0 ] -> V_18 [ 2 ] = V_10 ;
V_9 -> V_16 -> V_17 [ 0 ] -> V_18 [ 4 ] = V_11 ;
} else {
V_9 -> V_16 -> V_17 [ 0 ] -> V_18 [ 0 ] = 0xf3 ;
V_9 -> V_16 -> V_17 [ 0 ] -> V_18 [ 2 ] = 0x00 ;
V_9 -> V_16 -> V_17 [ 0 ] -> V_18 [ 4 ] = 0x00 ;
}
F_3 ( V_7 , V_9 -> V_16 , V_19 ) ;
return 0 ;
}
int F_4 ( struct V_6 * V_7 )
{
struct V_8 * V_9 ;
struct V_20 * V_16 ;
struct V_21 * V_22 = F_5 ( V_7 -> V_23 . V_24 ,
struct V_21 , V_25 ) ;
struct V_1 * V_2 = V_22 -> V_26 ;
int error ;
V_16 = F_6 ( V_7 , V_27 , 0 , 0 , 7 ) ;
if ( ! V_16 )
return - V_28 ;
V_9 = F_7 ( sizeof( struct V_8 ) , V_29 ) ;
if ( ! V_9 )
return - V_30 ;
F_8 ( V_31 , V_2 -> V_32 ) ;
error = F_9 ( V_2 , V_9 , F_1 ) ;
if ( error ) {
F_10 ( V_9 ) ;
return error ;
}
V_9 -> V_16 = V_16 ;
V_16 -> V_17 [ 0 ] -> V_18 [ 0 ] = 0xf3 ;
V_16 -> V_17 [ 0 ] -> V_18 [ 1 ] = 0x00 ;
V_16 -> V_17 [ 0 ] -> V_18 [ 2 ] = 0x00 ;
V_16 -> V_17 [ 0 ] -> V_18 [ 3 ] = 0x00 ;
V_16 -> V_17 [ 0 ] -> V_18 [ 4 ] = 0x00 ;
V_16 -> V_17 [ 0 ] -> V_18 [ 5 ] = 0x00 ;
V_16 -> V_17 [ 0 ] -> V_18 [ 6 ] = 0x00 ;
F_3 ( V_7 , V_16 , V_19 ) ;
F_11 ( V_7 , L_1 ) ;
return 0 ;
}
