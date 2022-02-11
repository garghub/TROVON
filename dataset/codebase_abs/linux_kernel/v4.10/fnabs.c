int
F_1 ( T_1 * V_1 , T_1 * V_2 )
{
V_1 [ 0 ] = V_2 [ 0 ] | 0x80000000 ;
V_1 [ 1 ] = V_2 [ 1 ] ;
#ifdef F_2
F_3 ( L_1 , V_3 , V_1 , V_2 ) ;
F_4 ( V_1 ) ;
F_3 ( L_2 ) ;
#endif
return 0 ;
}
