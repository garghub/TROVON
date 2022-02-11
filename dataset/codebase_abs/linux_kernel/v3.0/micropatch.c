void T_1 F_1 ( T_2 * V_1 )
{
volatile T_3 * V_2 ;
volatile T_2 * V_3 ;
#if F_2 ( V_4 ) || \
F_2 ( V_5 )
volatile T_4 * V_6 ;
volatile struct V_7 * V_8 ;
#ifdef V_5
volatile T_5 * V_9 ;
#endif
#endif
int V_10 ;
V_3 = V_1 ;
#ifdef F_3
V_3 -> V_11 = 0 ;
V_2 = ( T_3 * ) ( V_3 -> V_12 ) ;
for ( V_10 = 0 ; V_10 < ( sizeof( V_13 ) / 4 ) ; V_10 ++ )
* V_2 ++ = V_13 [ V_10 ] ;
V_2 = ( T_3 * ) & ( V_3 -> V_12 [ 0x0f00 ] ) ;
for ( V_10 = 0 ; V_10 < ( sizeof( V_14 ) / 4 ) ; V_10 ++ )
* V_2 ++ = V_14 [ V_10 ] ;
V_3 -> V_11 = 0x0009 ;
F_4 ( L_1 ) ;
#endif
#if F_2 ( V_4 ) || \
F_2 ( V_5 )
V_3 -> V_11 = 0 ;
V_2 = ( T_3 * ) ( V_3 -> V_12 ) ;
for ( V_10 = 0 ; V_10 < ( sizeof( V_13 ) / 4 ) ; V_10 ++ )
* V_2 ++ = V_13 [ V_10 ] ;
V_2 = ( T_3 * ) & ( V_3 -> V_12 [ 0x0f00 ] ) ;
for ( V_10 = 0 ; V_10 < ( sizeof( V_14 ) / 4 ) ; V_10 ++ )
* V_2 ++ = V_14 [ V_10 ] ;
V_6 = ( T_4 * ) & V_3 -> V_15 [ V_16 ] ;
# define F_5 0x0500
V_6 -> V_17 = F_5 ;
V_10 = ( F_5 + sizeof( T_4 ) + 31 ) & ~ 31 ;
V_8 = (struct V_7 * ) & V_3 -> V_15 [ V_18 ] ;
V_8 -> V_19 = V_10 ;
# if F_2 ( V_4 )
V_3 -> V_20 = 0x802a ;
V_3 -> V_21 = 0x8028 ;
V_3 -> V_22 = 0x802e ;
V_3 -> V_23 = 0x802c ;
V_3 -> V_11 = 1 ;
F_4 ( L_2 ) ;
# endif
# if F_2 ( V_5 )
V_2 = ( T_3 * ) & ( V_3 -> V_12 [ 0x0e00 ] ) ;
for ( V_10 = 0 ; V_10 < ( sizeof( V_24 ) / 4 ) ; V_10 ++ )
* V_2 ++ = V_24 [ V_10 ] ;
V_3 -> V_20 = 0x8080 ;
V_3 -> V_21 = 0x808a ;
V_3 -> V_22 = 0x8028 ;
V_3 -> V_23 = 0x802a ;
V_3 -> V_11 = 3 ;
V_9 = ( T_5 * ) & V_3 -> V_15 [ V_25 ] ;
V_9 -> V_26 = 0x1FC0 ;
F_4 ( L_3 ) ;
# endif
#endif
}
