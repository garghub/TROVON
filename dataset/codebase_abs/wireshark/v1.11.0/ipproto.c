const char * F_1 ( const int V_1 ) {
const char * V_2 ;
if ( ( V_2 = F_2 ( V_1 , & V_3 ) ) != NULL )
return V_2 ;
V_2 = L_1 ;
#ifdef F_3
if ( V_4 . V_5 || V_4 . V_6 ||
V_4 . V_7 || V_4 . V_8 ) {
static char V_9 [ 128 ] ;
struct V_10 * V_11 ;
V_11 = F_4 ( V_1 ) ;
if ( V_11 ) {
F_5 ( V_9 , V_11 -> V_12 , sizeof( V_9 ) ) ;
V_2 = V_9 ;
}
}
#endif
return V_2 ;
}
