int
F_1 ( T_1 * V_1 , void * V_2 , T_1 * V_3 , T_1 * V_4 )
{
F_2 ( V_5 ) ;
V_6 ;
#ifdef F_3
F_4 ( L_1 , V_7 , V_1 , V_2 , V_3 , V_4 ) ;
#endif
F_5 ( V_5 , V_2 ) ;
#ifdef F_3
F_4 ( L_2 , V_8 , V_9 , V_10 , V_11 , V_12 ) ;
F_4 ( L_3 , V_3 [ 0 ] , V_3 [ 1 ] ) ;
F_4 ( L_4 , V_4 [ 0 ] , V_4 [ 1 ] ) ;
#endif
if ( V_12 == V_13 || ( V_12 != V_14 && V_8 ) ) {
V_1 [ 0 ] = V_3 [ 0 ] ;
V_1 [ 1 ] = V_3 [ 1 ] ;
} else {
V_1 [ 0 ] = V_4 [ 0 ] ;
V_1 [ 1 ] = V_4 [ 1 ] ;
}
#ifdef F_3
F_4 ( L_5 , V_1 [ 0 ] , V_1 [ 1 ] ) ;
#endif
return 0 ;
}
