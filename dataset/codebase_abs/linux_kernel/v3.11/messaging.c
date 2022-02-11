void F_1 ( void )
{
T_1 * V_1 = & F_2 ( V_2 ) ;
int V_3 = F_3 ( V_1 ) ;
if ( V_3 != V_4 )
F_4 ( L_1 , V_3 ) ;
F_5 ( V_5 ) ;
}
void F_6 ( struct V_6 * V_7 , int V_8 )
{
int V_9 [ V_10 / sizeof( int ) ] ;
T_2 V_11 ;
int V_12 = 0 ;
struct V_6 * V_13 = F_7 ( V_7 ) ;
F_8 () ;
#ifdef F_9
{
long V_14 = V_15 - ( long ) F_10 () ;
if ( F_11 ( V_14 < ( sizeof( struct V_16 ) + V_17 ) ) ) {
F_12 ( L_2
L_3 ,
V_14 - sizeof( struct V_16 ) ) ;
F_13 () ;
}
}
#endif
while ( 1 ) {
V_11 = F_14 ( F_2 ( V_2 ) ,
( V_18 ) V_9 ,
sizeof( V_9 ) ) ;
if ( V_11 . V_19 == 0 )
break;
if ( V_11 . V_19 < 0 )
F_4 ( L_4 , V_11 . V_19 ) ;
++ V_12 ;
if ( V_11 . V_20 == V_21 ) {
int V_22 ;
F_15 ( V_11 . V_19 != sizeof( int ) ) ;
V_22 = V_9 [ 0 ] ;
#ifdef F_16
F_17 ( V_9 [ 0 ] ) ;
#else
F_4 ( L_5 , V_22 ) ;
#endif
} else if ( V_11 . V_20 == V_23 ) {
T_3 * V_24 = ( T_3 * ) V_9 ;
struct V_25 * V_26 =
(struct V_25 * ) V_24 -> V_27 ;
V_26 -> V_28 ( V_26 , V_24 -> V_29 ) ;
F_2 ( V_30 ) . V_31 ++ ;
}
}
if ( V_12 == 0 )
F_4 ( L_6 ) ;
F_18 () ;
F_7 ( V_13 ) ;
}
