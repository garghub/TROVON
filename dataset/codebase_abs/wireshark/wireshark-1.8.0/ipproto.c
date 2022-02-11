const char * F_1 ( const int V_1 ) {
const char * V_2 ;
if ( ( V_2 = F_2 ( V_1 , & V_3 ) ) != NULL )
return V_2 ;
V_2 = L_1 ;
#ifdef F_3
if ( V_4 != 0 ) {
static char V_5 [ 128 ] ;
struct V_6 * V_7 ;
V_7 = F_4 ( V_1 ) ;
if ( V_7 ) {
F_5 ( V_5 , V_7 -> V_8 , sizeof( V_5 ) ) ;
V_2 = V_5 ;
}
}
#endif
return V_2 ;
}
