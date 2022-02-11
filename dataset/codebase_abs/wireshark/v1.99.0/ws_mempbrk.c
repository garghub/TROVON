const T_1 *
F_1 ( const T_1 * V_1 , T_2 V_2 , const T_1 * V_3 )
{
T_3 V_4 [ 256 ] = { 0 } ;
const T_1 * V_5 ;
while ( * V_3 )
V_4 [ * V_3 ++ ] = 1 ;
V_5 = V_1 + V_2 ;
while ( V_1 < V_5 ) {
if ( V_4 [ * V_1 ] )
return V_1 ;
V_1 ++ ;
}
return NULL ;
}
T_4 const T_1 *
F_2 ( const T_1 * V_1 , T_2 V_2 , const T_1 * V_3 )
{
#ifdef F_3
static int V_6 = - 1 ;
#endif
if ( * V_3 == 0 )
return NULL ;
#ifdef F_3
if G_UNLIKELY( V_6 < 0 )
V_6 = F_4 () ;
if ( V_2 >= 16 && V_6 )
return F_5 ( V_1 , V_2 , V_3 ) ;
#endif
return F_1 ( V_1 , V_2 , V_3 ) ;
}
