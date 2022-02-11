static int F_1 ( T_1 * V_1 , const T_2 * V_2 )
{
int V_3 ;
const char * V_4 ;
F_2 ( V_5 ) * V_6 ;
V_5 * V_7 ;
V_4 = F_3 ( V_1 ) ;
if ( ( V_6 = F_4 ( V_2 , V_4 ) ) == NULL ) {
F_5 ( V_8 , V_9 ) ;
return 0 ;
}
for ( V_3 = 0 ; V_3 < F_6 ( V_6 ) ; V_3 ++ ) {
V_7 = F_7 ( V_6 , V_3 ) ;
if ( strcmp ( V_7 -> V_10 , L_1 ) == 0 ) {
int V_11 ;
if ( ! F_8 ( V_7 , & V_11 ) ) {
F_5 ( V_8 , V_12 ) ;
return 0 ;
}
if ( V_11 > 0 ) {
#ifdef F_9
if ( ! F_10 () && ! F_11 ( 1 ) ) {
F_5 ( V_8 ,
V_13 ) ;
return 0 ;
}
#else
F_5 ( V_8 , V_14 ) ;
return 0 ;
#endif
}
} else {
F_5 ( V_8 , V_15 ) ;
F_12 ( 4 , L_2 , V_7 -> V_10 ,
L_3 , V_7 -> V_16 ) ;
}
}
return 1 ;
}
void F_13 ( void )
{
F_14 ( L_4 , F_1 , 0 ) ;
}
