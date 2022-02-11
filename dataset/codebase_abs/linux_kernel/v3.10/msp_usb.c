static int T_1 F_1 ( void )
{
char * V_1 ;
char V_2 [ 32 ] ;
struct V_3 * V_4 [ V_5 ] ;
unsigned int V_6 ;
snprintf ( ( char * ) & V_2 [ 0 ] , sizeof( V_2 ) , L_1 ) ;
V_6 = 1 ;
V_1 = F_2 ( ( char * ) & V_2 [ 0 ] ) ;
if ( V_1 ) {
if ( ! strcmp ( V_1 , L_2 ) )
V_6 = 0 ;
}
if ( V_6 ) {
#if F_3 ( V_7 )
V_4 [ 0 ] = & V_8 . V_9 ;
F_4 ( L_3 , V_4 [ 0 ] -> V_10 ) ;
#ifdef F_5
V_4 [ 1 ] = & V_11 . V_9 ;
F_4 ( L_3 , V_4 [ 1 ] -> V_10 ) ;
#endif
#else
F_4 ( L_4 , __FILE__ ) ;
#endif
} else {
#if F_3 ( V_12 )
V_4 [ 0 ] = & V_13 . V_9 ;
F_4 ( L_5
, V_4 [ 0 ] -> V_10 ) ;
#ifdef F_5
V_4 [ 1 ] = & V_14 . V_9 ;
F_4 ( L_5
, V_4 [ 1 ] -> V_10 ) ;
#endif
#else
F_4 ( L_6 , __FILE__ ) ;
#endif
}
F_6 ( V_4 , F_7 ( V_4 ) ) ;
return 0 ;
}
