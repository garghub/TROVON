static int T_1 F_1 ( void )
{
volatile T_2 * V_1 = & V_2 -> V_3 ;
int V_4 ;
int V_5 ;
#ifdef F_2
V_1 = F_3 ( 0xff700000 + 0x5000 , sizeof( T_2 ) ) ;
#else
V_1 = & V_2 -> V_3 ;
#endif
V_4 = 1 ;
if ( ( V_1 -> V_6 & 0x00001800 ) == 0x00001800 )
V_4 = 0 ;
F_4 ( V_7 [ 0 ] , V_1 -> V_6 , V_1 -> V_8 ) ;
F_4 ( V_7 [ 1 ] , V_1 -> V_9 , V_1 -> V_10 ) ;
F_4 ( V_7 [ 2 ] , V_1 -> V_11 , V_1 -> V_12 ) ;
#ifdef F_2
F_5 ( ( void * ) V_1 ) ;
#endif
for ( V_5 = 0 ; V_5 < 3 ; V_5 ++ ) {
T_3 V_13 [ 3 ] = { 0 , 6 , 1 } ;
int V_14 ;
struct V_15 * V_16 ;
F_6 ( V_17 L_1 ,
V_7 [ V_5 ] . V_18 ,
( V_7 [ V_5 ] . V_19 >> 20 ) ,
V_13 [ V_5 ] ) ;
if ( ! V_7 [ V_5 ] . V_20 ) {
F_6 ( L_2 ) ;
continue;
}
F_6 ( L_3 , V_7 [ V_5 ] . V_20 ) ;
V_7 [ V_5 ] . V_21 = F_3 ( V_7 [ V_5 ] . V_20 ,
V_7 [ V_5 ] . V_19 ) ;
if ( ! V_7 [ V_5 ] . V_21 ) {
F_6 ( L_4 ) ;
continue;
}
F_7 ( & V_7 [ V_5 ] ) ;
V_22 [ V_5 ] = F_8 ( L_5 , & V_7 [ V_5 ] ) ;
if ( ! V_22 [ V_5 ] )
continue;
V_22 [ V_5 ] -> V_23 = V_24 ;
if ( V_5 == 2 ) {
V_16 = NULL ;
V_14 = 0 ;
} else if ( V_5 == V_4 ) {
V_16 = V_25 ;
V_14 = F_9 ( V_25 ) ;
} else {
V_16 = V_26 ;
V_14 = F_9 ( V_26 ) ;
}
F_10 ( V_22 [ V_5 ] , V_27 , 0 ,
V_16 , V_14 ) ;
}
return 0 ;
}
static void T_4 F_11 ( void )
{
int V_5 ;
for ( V_5 = 0 ; V_5 < 3 ; V_5 ++ ) {
if ( ! V_22 [ V_5 ] )
continue;
F_12 ( V_22 [ V_5 ] ) ;
F_13 ( V_22 [ V_5 ] ) ;
F_5 ( ( void * ) V_7 [ V_5 ] . V_21 ) ;
V_7 [ V_5 ] . V_21 = 0 ;
}
}
