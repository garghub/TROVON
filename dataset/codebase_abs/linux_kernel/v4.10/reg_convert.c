int F_1 ( T_1 const * V_1 , T_1 * V_2 )
{
int V_3 = F_2 ( V_1 ) ;
* ( long long * ) & ( V_2 -> V_4 ) = * ( const long long * ) & ( V_1 -> V_4 ) ;
F_3 ( V_2 , F_4 ( V_1 ) ) ;
if ( F_5 ( V_2 ) == V_5 ) {
if ( V_2 -> V_6 & 0x80000000 ) {
F_6 ( V_2 , 1 ) ;
} else {
F_6 ( V_2 , 1 ) ;
F_7 ( V_2 ) ;
}
}
if ( ! ( V_2 -> V_6 & 0x80000000 ) ) {
F_8 ( V_7 | 0x180 ) ;
}
return V_3 ;
}
