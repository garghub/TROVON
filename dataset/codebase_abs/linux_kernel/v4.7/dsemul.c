int F_1 ( struct V_1 * V_2 , T_1 V_3 , unsigned long V_4 )
{
int V_5 = F_2 ( V_2 -> V_6 ) ;
T_1 V_7 ;
struct V_8 T_2 * V_9 ;
int V_10 ;
if ( V_3 == 0 )
return - 1 ;
if ( V_5 ) {
union T_1 V_11 = { . V_12 = V_3 } ;
if ( ( V_3 >> 16 ) == V_13 )
return - 1 ;
if ( V_11 . V_14 . V_15 == V_16 ) {
unsigned int V_17 ;
T_3 V_18 ;
V_17 = ( ( ( V_11 . V_14 . V_17 + 0xe ) & 0xf ) + 2 ) ;
V_18 = V_2 -> V_6 & ~ 3 ;
V_18 += V_11 . V_14 . V_19 << 2 ;
V_2 -> V_2 [ V_17 ] = ( long ) V_18 ;
return - 1 ;
}
}
F_3 ( L_1 , V_2 -> V_6 , V_4 ) ;
V_7 = F_4 ( V_5 ) ;
V_9 = (struct V_8 T_2 * )
( ( V_2 -> V_2 [ 29 ] - sizeof( struct V_8 ) ) & ~ 0x7 ) ;
if ( F_5 ( ! F_6 ( V_20 , V_9 , sizeof( struct V_8 ) ) ) )
return V_21 ;
if ( V_5 ) {
V_10 = F_7 ( V_3 >> 16 ,
( V_22 T_2 * ) ( & V_9 -> V_23 ) ) ;
V_10 |= F_7 ( V_3 & 0xffff ,
( V_22 T_2 * ) ( ( long ) ( & V_9 -> V_23 ) + 2 ) ) ;
V_10 |= F_7 ( V_7 >> 16 ,
( V_22 T_2 * ) ( & V_9 -> V_24 ) ) ;
V_10 |= F_7 ( V_7 & 0xffff ,
( V_22 T_2 * ) ( ( long ) ( & V_9 -> V_24 ) + 2 ) ) ;
} else {
V_10 = F_7 ( V_3 , & V_9 -> V_23 ) ;
V_10 |= F_7 ( V_7 , & V_9 -> V_24 ) ;
}
V_10 |= F_7 ( ( T_1 ) V_25 , & V_9 -> V_26 ) ;
V_10 |= F_7 ( V_4 , & V_9 -> V_27 ) ;
if ( F_5 ( V_10 ) ) {
F_8 ( V_28 ) ;
return V_21 ;
}
V_2 -> V_6 = ( unsigned long ) & V_9 -> V_23 | V_5 ;
F_9 ( ( unsigned long ) & V_9 -> V_23 ) ;
return 0 ;
}
int F_10 ( struct V_1 * V_29 )
{
int V_5 = F_2 ( V_29 -> V_6 ) ;
struct V_8 T_2 * V_9 ;
unsigned long V_27 ;
T_4 V_11 , V_26 ;
int V_10 = 0 ;
V_22 V_30 [ 2 ] ;
V_9 = (struct V_8 T_2 * )
( F_11 ( V_29 -> V_6 ) - sizeof( T_1 ) ) ;
if ( ! F_6 ( V_31 , V_9 , sizeof( struct V_8 ) ) )
return 0 ;
if ( V_5 ) {
V_10 = F_12 ( V_30 [ 0 ] ,
( V_22 T_2 * ) ( & V_9 -> V_24 ) ) ;
V_10 |= F_12 ( V_30 [ 1 ] ,
( V_22 T_2 * ) ( ( long ) ( & V_9 -> V_24 ) + 2 ) ) ;
V_11 = ( V_30 [ 0 ] << 16 ) | V_30 [ 1 ] ;
} else {
V_10 = F_12 ( V_11 , & V_9 -> V_24 ) ;
}
V_10 |= F_12 ( V_26 , & V_9 -> V_26 ) ;
if ( F_5 ( V_10 ||
V_11 != F_4 ( V_5 ) || V_26 != V_25 ) ) {
F_8 ( V_28 ) ;
return 0 ;
}
F_3 ( L_2 ) ;
if ( F_12 ( V_27 , & V_9 -> V_27 ) ) {
F_13 ( V_21 , V_32 ) ;
return 0 ;
}
V_29 -> V_6 = V_27 ;
F_8 ( V_33 ) ;
return 1 ;
}
