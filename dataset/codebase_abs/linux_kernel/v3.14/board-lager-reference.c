static void T_1 F_1 ( void )
{
#ifdef F_2
static const char * const V_1 [] = {
L_1 , L_2 , L_3 , L_4 ,
L_5 , L_6 , L_7 , L_8 ,
L_9 , L_10 ,
} ;
struct V_2 * V_2 ;
unsigned int V_3 ;
for ( V_3 = 0 ; V_3 < F_3 ( V_1 ) ; ++ V_3 ) {
V_2 = F_4 ( NULL , V_1 [ V_3 ] ) ;
if ( V_2 ) {
F_5 ( V_2 , NULL , L_11 , V_3 ) ;
F_6 ( V_2 ) ;
}
}
V_2 = F_4 ( NULL , L_12 ) ;
if ( V_2 ) {
F_5 ( V_2 , NULL , L_13 ) ;
F_6 ( V_2 ) ;
}
#else
F_7 () ;
#endif
F_8 () ;
F_9 ( NULL , V_4 , NULL , NULL ) ;
}
