int F_1 ( struct V_1 * V_2 , T_1 V_3 , unsigned long V_4 )
{
struct V_5 T_2 * V_6 ;
int V_7 ;
if ( ( F_2 ( V_2 -> V_8 ) && ( ( V_3 >> 16 ) == V_9 ) ) ||
( V_3 == 0 ) ) {
V_2 -> V_8 = V_4 ;
F_3 ( V_2 ) ;
return 0 ;
}
F_4 ( L_1 , V_2 -> V_8 , V_4 ) ;
V_6 = (struct V_5 T_2 * )
( ( V_2 -> V_2 [ 29 ] - sizeof( struct V_5 ) ) & ~ 0x7 ) ;
if ( F_5 ( ! F_6 ( V_10 , V_6 , sizeof( struct V_5 ) ) ) )
return V_11 ;
if ( F_2 ( V_2 -> V_8 ) ) {
V_7 = F_7 ( V_3 >> 16 , ( V_12 T_2 * ) ( & V_6 -> V_13 ) ) ;
V_7 |= F_7 ( V_3 & 0xffff , ( V_12 T_2 * ) ( ( long ) ( & V_6 -> V_13 ) + 2 ) ) ;
V_7 |= F_7 ( V_14 >> 16 , ( V_12 T_2 * ) ( & V_6 -> V_15 ) ) ;
V_7 |= F_7 ( V_14 & 0xffff , ( V_12 T_2 * ) ( ( long ) ( & V_6 -> V_15 ) + 2 ) ) ;
} else {
V_7 = F_7 ( V_3 , & V_6 -> V_13 ) ;
V_7 |= F_7 ( ( T_1 ) V_14 , & V_6 -> V_15 ) ;
}
V_7 |= F_7 ( ( T_1 ) V_16 , & V_6 -> V_17 ) ;
V_7 |= F_7 ( V_4 , & V_6 -> V_18 ) ;
if ( F_5 ( V_7 ) ) {
F_8 ( V_19 ) ;
return V_11 ;
}
V_2 -> V_8 = ( ( unsigned long ) & V_6 -> V_13 ) |
F_2 ( V_2 -> V_8 ) ;
F_9 ( ( unsigned long ) & V_6 -> V_13 ) ;
return 0 ;
}
int F_10 ( struct V_1 * V_20 )
{
struct V_5 T_2 * V_6 ;
unsigned long V_18 ;
T_3 V_21 , V_17 ;
int V_7 = 0 ;
V_12 V_22 [ 2 ] ;
V_6 = (struct V_5 T_2 * )
( F_11 ( V_20 -> V_8 ) - sizeof( T_1 ) ) ;
if ( ! F_6 ( V_23 , V_6 , sizeof( struct V_5 ) ) )
return 0 ;
if ( F_2 ( V_20 -> V_8 ) ) {
V_7 = F_12 ( V_22 [ 0 ] , ( V_12 T_2 * ) ( & V_6 -> V_15 ) ) ;
V_7 |= F_12 ( V_22 [ 1 ] , ( V_12 T_2 * ) ( ( long ) ( & V_6 -> V_15 ) + 2 ) ) ;
V_21 = ( V_22 [ 0 ] << 16 ) | V_22 [ 1 ] ;
} else {
V_7 = F_12 ( V_21 , & V_6 -> V_15 ) ;
}
V_7 |= F_12 ( V_17 , & V_6 -> V_17 ) ;
if ( F_5 ( V_7 || ( V_21 != V_14 ) || ( V_17 != V_16 ) ) ) {
F_8 ( V_19 ) ;
return 0 ;
}
F_4 ( L_2 ) ;
if ( F_12 ( V_18 , & V_6 -> V_18 ) ) {
F_13 ( V_11 , V_24 ) ;
return 0 ;
}
V_20 -> V_8 = V_18 ;
F_8 ( V_25 ) ;
return 1 ;
}
