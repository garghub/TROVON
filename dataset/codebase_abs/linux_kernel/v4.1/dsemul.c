int F_1 ( struct V_1 * V_2 , T_1 V_3 , unsigned long V_4 )
{
extern T_2 void V_5 ( void ) ;
struct V_6 T_3 * V_7 ;
int V_8 ;
if ( ( F_2 ( V_2 -> V_9 ) && ( ( V_3 >> 16 ) == V_10 ) ) ||
( V_3 == 0 ) ) {
V_2 -> V_9 = V_4 ;
F_3 ( V_2 ) ;
return 0 ;
}
F_4 ( L_1 , V_2 -> V_9 , V_4 ) ;
V_7 = (struct V_6 T_3 * )
( ( V_2 -> V_2 [ 29 ] - sizeof( struct V_6 ) ) & ~ 0x7 ) ;
if ( F_5 ( ! F_6 ( V_11 , V_7 , sizeof( struct V_6 ) ) ) )
return V_12 ;
if ( F_2 ( V_2 -> V_9 ) ) {
V_8 = F_7 ( V_3 >> 16 , ( V_13 T_3 * ) ( & V_7 -> V_14 ) ) ;
V_8 |= F_7 ( V_3 & 0xffff , ( V_13 T_3 * ) ( ( long ) ( & V_7 -> V_14 ) + 2 ) ) ;
V_8 |= F_7 ( V_15 >> 16 , ( V_13 T_3 * ) ( & V_7 -> V_16 ) ) ;
V_8 |= F_7 ( V_15 & 0xffff , ( V_13 T_3 * ) ( ( long ) ( & V_7 -> V_16 ) + 2 ) ) ;
} else {
V_8 = F_7 ( V_3 , & V_7 -> V_14 ) ;
V_8 |= F_7 ( ( T_1 ) V_15 , & V_7 -> V_16 ) ;
}
V_8 |= F_7 ( ( T_1 ) V_17 , & V_7 -> V_18 ) ;
V_8 |= F_7 ( V_4 , & V_7 -> V_19 ) ;
if ( F_5 ( V_8 ) ) {
F_8 ( V_20 ) ;
return V_12 ;
}
V_2 -> V_9 = ( ( unsigned long ) & V_7 -> V_14 ) |
F_2 ( V_2 -> V_9 ) ;
F_9 ( ( unsigned long ) & V_7 -> V_14 ) ;
return 0 ;
}
int F_10 ( struct V_1 * V_21 )
{
struct V_6 T_3 * V_7 ;
unsigned long V_19 ;
T_4 V_22 , V_18 ;
int V_8 = 0 ;
V_13 V_23 [ 2 ] ;
V_7 = (struct V_6 T_3 * )
( F_11 ( V_21 -> V_9 ) - sizeof( T_1 ) ) ;
if ( ! F_6 ( V_24 , V_7 , sizeof( struct V_6 ) ) )
return 0 ;
if ( F_2 ( V_21 -> V_9 ) ) {
V_8 = F_12 ( V_23 [ 0 ] , ( V_13 T_3 * ) ( & V_7 -> V_16 ) ) ;
V_8 |= F_12 ( V_23 [ 1 ] , ( V_13 T_3 * ) ( ( long ) ( & V_7 -> V_16 ) + 2 ) ) ;
V_22 = ( V_23 [ 0 ] << 16 ) | V_23 [ 1 ] ;
} else {
V_8 = F_12 ( V_22 , & V_7 -> V_16 ) ;
}
V_8 |= F_12 ( V_18 , & V_7 -> V_18 ) ;
if ( F_5 ( V_8 || ( V_22 != V_15 ) || ( V_18 != V_17 ) ) ) {
F_8 ( V_20 ) ;
return 0 ;
}
F_4 ( L_2 ) ;
if ( F_12 ( V_19 , & V_7 -> V_19 ) ) {
F_13 ( V_12 , V_25 ) ;
return 0 ;
}
V_21 -> V_9 = V_19 ;
F_8 ( V_26 ) ;
return 1 ;
}
