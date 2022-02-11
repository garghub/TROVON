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
F_6 ( V_15 L_1 ,
V_7 [ V_5 ] . V_16 ,
( V_7 [ V_5 ] . V_17 >> 20 ) ,
V_13 [ V_5 ] ) ;
if ( ! V_7 [ V_5 ] . V_18 ) {
F_6 ( L_2 ) ;
continue;
}
F_6 ( L_3 , V_7 [ V_5 ] . V_18 ) ;
V_7 [ V_5 ] . V_19 = F_3 ( V_7 [ V_5 ] . V_18 , V_7 [ V_5 ] . V_17 ) ;
if ( ! V_7 [ V_5 ] . V_19 ) {
F_6 ( L_4 ) ;
continue;
}
F_7 ( & V_7 [ V_5 ] ) ;
V_20 [ V_5 ] = F_8 ( L_5 , & V_7 [ V_5 ] ) ;
if ( ! V_20 [ V_5 ] )
continue;
V_20 [ V_5 ] -> V_21 = V_22 ;
V_14 = F_9 ( V_20 [ V_5 ] , V_23 ,
& V_24 [ V_5 ] , 0 ) ;
if ( V_14 > 0 ) {
F_10 ( V_20 [ V_5 ] , V_24 [ V_5 ] ,
V_14 ) ;
continue;
}
if ( V_5 == 2 ) {
F_10 ( V_20 [ V_5 ] , NULL , 0 ) ;
} else if ( V_5 == V_4 ) {
F_10 ( V_20 [ V_5 ] , V_25 ,
F_11 ( V_25 ) ) ;
} else {
F_10 ( V_20 [ V_5 ] , V_26 ,
F_11 ( V_26 ) ) ;
}
}
return 0 ;
}
static void T_4 F_12 ( void )
{
int V_5 ;
for ( V_5 = 0 ; V_5 < 3 ; V_5 ++ ) {
if ( ! V_20 [ V_5 ] )
continue;
if ( V_5 < 2 || V_24 [ V_5 ] )
F_13 ( V_20 [ V_5 ] ) ;
else
F_13 ( V_20 [ V_5 ] ) ;
F_14 ( V_24 [ V_5 ] ) ;
F_15 ( V_20 [ V_5 ] ) ;
F_5 ( ( void * ) V_7 [ V_5 ] . V_19 ) ;
V_7 [ V_5 ] . V_19 = 0 ;
}
}
