int
F_1 ( struct V_1 * V_2 )
{
extern void V_3 ( unsigned long V_4 , int V_5 ) ;
struct V_6 V_7 ;
unsigned int V_8 , V_9 ;
int V_10 ;
T_1 V_11 [ 36 ] ;
memcpy ( V_11 , V_2 -> V_12 , sizeof V_2 -> V_12 ) ;
V_11 [ 32 ] = 0 ;
memcpy ( & V_8 , V_11 , sizeof( V_8 ) ) ;
if ( V_13 ) {
F_2 ( V_14 L_1 ) ;
V_3 ( V_8 , 32 ) ;
F_2 ( V_14 L_2 ) ;
}
V_10 = F_3 ( V_11 , 0x666 ) ;
memcpy ( & V_9 , V_11 , sizeof( V_9 ) ) ;
if ( V_13 ) {
F_2 ( V_14 L_3 ,
V_10 >> 24 , V_10 & 0xffffff ) ;
V_3 ( V_9 , 32 ) ;
F_2 ( V_14 L_2 ) ;
}
memcpy ( V_2 -> V_12 , V_11 , sizeof V_2 -> V_12 ) ;
if ( V_10 != 0 ) {
V_7 . V_15 = V_10 >> 24 ;
V_7 . V_16 = 0 ;
V_7 . V_17 = V_10 & 0xffffff ;
V_7 . V_18 = ( void V_19 * ) V_2 -> V_20 [ 0 ] ;
F_4 ( V_7 . V_15 , & V_7 , V_21 ) ;
return - 1 ;
}
return V_10 ? - 1 : 0 ;
}
