void F_1 ( void T_1 * V_1 , const void * V_2 , T_2 V_3 )
{
#ifdef F_2
T_3 T_1 * V_4 = V_1 ;
const T_3 * V_5 = V_2 ;
const T_3 * V_6 = V_5 + ( V_3 >> 1 ) ;
while ( V_5 < V_6 )
F_3 ( * V_5 ++ , V_4 ++ ) ;
if ( V_3 & 1 )
F_4 ( * ( const V_7 * ) V_5 , V_4 ) ;
#else
V_7 T_1 * V_4 = V_1 ;
const V_7 * V_5 = V_2 ;
const V_7 * V_6 = V_5 + V_3 ;
while ( V_5 < V_6 )
F_4 ( * V_5 ++ , V_4 ++ ) ;
#endif
}
