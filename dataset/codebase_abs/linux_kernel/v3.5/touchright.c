static T_1 F_1 ( struct V_1 * V_1 ,
unsigned char V_2 , unsigned int V_3 )
{
struct V_4 * V_4 = F_2 ( V_1 ) ;
struct V_5 * V_6 = V_4 -> V_6 ;
V_4 -> V_2 [ V_4 -> V_7 ] = V_2 ;
if ( ( V_4 -> V_2 [ 0 ] & V_8 ) == V_9 ) {
if ( ++ V_4 -> V_7 == V_10 ) {
F_3 ( V_6 , V_11 ,
( V_4 -> V_2 [ 1 ] << 5 ) | ( V_4 -> V_2 [ 2 ] >> 1 ) ) ;
F_3 ( V_6 , V_12 ,
( V_4 -> V_2 [ 3 ] << 5 ) | ( V_4 -> V_2 [ 4 ] >> 1 ) ) ;
F_4 ( V_6 , V_13 ,
V_4 -> V_2 [ 0 ] & V_14 ) ;
F_5 ( V_6 ) ;
V_4 -> V_7 = 0 ;
}
}
return V_15 ;
}
static void F_6 ( struct V_1 * V_1 )
{
struct V_4 * V_4 = F_2 ( V_1 ) ;
F_7 ( V_4 -> V_6 ) ;
F_8 ( V_4 -> V_6 ) ;
F_9 ( V_1 ) ;
F_10 ( V_1 , NULL ) ;
F_11 ( V_4 -> V_6 ) ;
F_12 ( V_4 ) ;
}
static int F_13 ( struct V_1 * V_1 , struct V_16 * V_17 )
{
struct V_4 * V_4 ;
struct V_5 * V_5 ;
int V_18 ;
V_4 = F_14 ( sizeof( struct V_4 ) , V_19 ) ;
V_5 = F_15 () ;
if ( ! V_4 || ! V_5 ) {
V_18 = - V_20 ;
goto V_21;
}
V_4 -> V_1 = V_1 ;
V_4 -> V_6 = V_5 ;
snprintf ( V_4 -> V_22 , sizeof( V_4 -> V_22 ) , L_1 , V_1 -> V_22 ) ;
V_5 -> V_23 = L_2 ;
V_5 -> V_22 = V_4 -> V_22 ;
V_5 -> V_24 . V_25 = V_26 ;
V_5 -> V_24 . V_27 = V_28 ;
V_5 -> V_24 . V_29 = 0 ;
V_5 -> V_24 . V_30 = 0x0100 ;
V_5 -> V_6 . V_31 = & V_1 -> V_6 ;
V_5 -> V_32 [ 0 ] = F_16 ( V_33 ) | F_16 ( V_34 ) ;
V_5 -> V_35 [ F_17 ( V_13 ) ] = F_16 ( V_13 ) ;
F_18 ( V_4 -> V_6 , V_11 , V_36 , V_37 , 0 , 0 ) ;
F_18 ( V_4 -> V_6 , V_12 , V_38 , V_39 , 0 , 0 ) ;
F_10 ( V_1 , V_4 ) ;
V_18 = F_19 ( V_1 , V_17 ) ;
if ( V_18 )
goto V_40;
V_18 = F_20 ( V_4 -> V_6 ) ;
if ( V_18 )
goto V_41;
return 0 ;
V_41: F_9 ( V_1 ) ;
V_40: F_10 ( V_1 , NULL ) ;
V_21: F_21 ( V_5 ) ;
F_12 ( V_4 ) ;
return V_18 ;
}
