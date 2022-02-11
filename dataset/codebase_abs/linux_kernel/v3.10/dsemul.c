int F_1 ( struct V_1 * V_2 , T_1 V_3 , unsigned long V_4 )
{
extern T_2 void V_5 ( void ) ;
struct V_6 T_3 * V_7 ;
int V_8 ;
if ( ( F_2 ( V_2 -> V_9 ) && ( ( V_3 >> 16 ) == V_10 ) ) ||
( V_3 == 0 ) ) {
V_2 -> V_9 = V_4 ;
V_2 -> V_11 &= ~ V_12 ;
return 0 ;
}
#ifdef F_3
F_4 ( L_1 , V_2 -> V_9 , V_4 ) ;
#endif
V_7 = (struct V_6 T_3 * )
( ( V_2 -> V_2 [ 29 ] - sizeof( struct V_6 ) ) & ~ 0x7 ) ;
if ( F_5 ( ! F_6 ( V_13 , V_7 , sizeof( struct V_6 ) ) ) )
return V_14 ;
if ( F_2 ( V_2 -> V_9 ) ) {
V_8 = F_7 ( V_3 >> 16 , ( V_15 T_3 * ) ( & V_7 -> V_16 ) ) ;
V_8 |= F_7 ( V_3 & 0xffff , ( V_15 T_3 * ) ( ( long ) ( & V_7 -> V_16 ) + 2 ) ) ;
V_8 |= F_7 ( V_17 >> 16 , ( V_15 T_3 * ) ( & V_7 -> V_18 ) ) ;
V_8 |= F_7 ( V_17 & 0xffff , ( V_15 T_3 * ) ( ( long ) ( & V_7 -> V_18 ) + 2 ) ) ;
} else {
V_8 = F_7 ( V_3 , & V_7 -> V_16 ) ;
V_8 |= F_7 ( ( T_1 ) V_17 , & V_7 -> V_18 ) ;
}
V_8 |= F_7 ( ( T_1 ) V_19 , & V_7 -> V_20 ) ;
V_8 |= F_7 ( V_4 , & V_7 -> V_21 ) ;
if ( F_5 ( V_8 ) ) {
F_8 ( V_22 ) ;
return V_14 ;
}
V_2 -> V_9 = ( ( unsigned long ) & V_7 -> V_16 ) |
F_2 ( V_2 -> V_9 ) ;
F_9 ( ( unsigned long ) & V_7 -> V_18 ) ;
return V_23 ;
}
int F_10 ( struct V_1 * V_24 )
{
struct V_6 T_3 * V_7 ;
unsigned long V_21 ;
T_4 V_25 , V_20 ;
int V_8 = 0 ;
V_15 V_26 [ 2 ] ;
V_7 = (struct V_6 T_3 * )
( F_11 ( V_24 -> V_9 ) - sizeof( T_1 ) ) ;
if ( ! F_6 ( V_27 , V_7 , sizeof( struct V_6 ) ) )
return 0 ;
if ( F_2 ( V_24 -> V_9 ) ) {
V_8 = F_12 ( V_26 [ 0 ] , ( V_15 T_3 * ) ( & V_7 -> V_18 ) ) ;
V_8 |= F_12 ( V_26 [ 1 ] , ( V_15 T_3 * ) ( ( long ) ( & V_7 -> V_18 ) + 2 ) ) ;
V_25 = ( V_26 [ 0 ] << 16 ) | V_26 [ 1 ] ;
} else {
V_8 = F_12 ( V_25 , & V_7 -> V_18 ) ;
}
V_8 |= F_12 ( V_20 , & V_7 -> V_20 ) ;
if ( F_5 ( V_8 || ( V_25 != V_17 ) || ( V_20 != V_19 ) ) ) {
F_8 ( V_22 ) ;
return 0 ;
}
#ifdef F_3
F_4 ( L_2 ) ;
#endif
if ( F_12 ( V_21 , & V_7 -> V_21 ) ) {
F_13 ( V_14 , V_28 ) ;
return 0 ;
}
V_24 -> V_9 = V_21 ;
return 1 ;
}
