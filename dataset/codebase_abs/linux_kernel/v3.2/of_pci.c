static inline int F_1 ( struct V_1 * V_2 ,
unsigned int V_3 )
{
unsigned int V_4 ;
const T_1 * V_5 = F_2 ( V_2 , L_1 , & V_4 ) ;
if ( ! V_5 || V_4 < 5 * sizeof( T_1 ) )
return 0 ;
return ( ( F_3 ( & V_5 [ 0 ] ) >> 8 ) & 0xff ) == V_3 ;
}
struct V_1 * F_4 ( struct V_1 * V_6 ,
unsigned int V_3 )
{
struct V_1 * V_2 , * V_7 ;
F_5 (parent, node) {
if ( F_1 ( V_2 , V_3 ) )
return V_2 ;
if ( ! strcmp ( V_2 -> V_8 , L_2 ) ) {
F_5 (node, node2) {
if ( F_1 ( V_7 , V_3 ) ) {
F_6 ( V_2 ) ;
return V_7 ;
}
}
}
}
return NULL ;
}
