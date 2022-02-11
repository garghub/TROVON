static T_1 F_1 ( struct V_1 * V_1 ,
unsigned char V_2 , unsigned int V_3 )
{
struct V_4 * V_4 = F_2 ( V_1 ) ;
struct V_5 * V_6 = V_4 -> V_6 ;
if ( V_4 -> V_7 == 0 ) {
if ( ( V_2 & 0xf0 ) != 0x80 )
return V_8 ;
} else {
if ( V_2 & 0x80 ) {
V_4 -> V_7 = 0 ;
return V_8 ;
}
}
V_4 -> V_2 [ V_4 -> V_7 ++ ] = V_2 ;
if ( V_4 -> V_7 == V_9 ) {
F_3 ( V_6 , V_10 ,
( V_4 -> V_2 [ 2 ] << 7 ) | V_4 -> V_2 [ 1 ] ) ;
F_3 ( V_6 , V_11 ,
( V_4 -> V_2 [ 4 ] << 7 ) | V_4 -> V_2 [ 3 ] ) ;
F_4 ( V_6 , V_12 ,
( V_4 -> V_2 [ 0 ] & 0x03 ) != 2 ) ;
F_5 ( V_6 ) ;
V_4 -> V_7 = 0 ;
}
return V_8 ;
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
static int F_13 ( struct V_1 * V_1 , struct V_13 * V_14 )
{
struct V_4 * V_4 ;
struct V_5 * V_5 ;
int V_15 ;
V_4 = F_14 ( sizeof( struct V_4 ) , V_16 ) ;
V_5 = F_15 () ;
if ( ! V_4 || ! V_5 ) {
V_15 = - V_17 ;
goto V_18;
}
V_4 -> V_1 = V_1 ;
V_4 -> V_6 = V_5 ;
snprintf ( V_4 -> V_19 , sizeof( V_4 -> V_19 ) ,
L_1 , V_1 -> V_19 ) ;
V_5 -> V_20 = L_2 ;
V_5 -> V_19 = V_4 -> V_19 ;
V_5 -> V_21 . V_22 = V_23 ;
V_5 -> V_21 . V_24 = V_25 ;
V_5 -> V_21 . V_26 = 0 ;
V_5 -> V_21 . V_27 = 0x0100 ;
V_5 -> V_28 [ 0 ] = F_16 ( V_29 ) | F_16 ( V_30 ) ;
V_5 -> V_31 [ F_17 ( V_12 ) ] = F_16 ( V_12 ) ;
F_18 ( V_5 , V_10 , 0 , 4096 , 0 , 0 ) ;
F_18 ( V_5 , V_11 , 0 , 4096 , 0 , 0 ) ;
F_10 ( V_1 , V_4 ) ;
V_15 = F_19 ( V_1 , V_14 ) ;
if ( V_15 )
goto V_32;
V_15 = F_20 ( V_4 -> V_6 ) ;
if ( V_15 )
goto V_33;
return 0 ;
V_33:
F_9 ( V_1 ) ;
V_32:
F_10 ( V_1 , NULL ) ;
V_18:
F_21 ( V_5 ) ;
F_12 ( V_4 ) ;
return V_15 ;
}
