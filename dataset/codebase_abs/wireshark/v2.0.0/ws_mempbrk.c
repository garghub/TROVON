void
F_1 ( T_1 * V_1 , const T_2 * V_2 )
{
const T_2 * V_3 = V_2 ;
while ( * V_3 ) {
V_1 -> V_4 [ ( int ) * V_3 ] = 1 ;
V_3 ++ ;
}
#ifdef F_2
F_3 ( V_1 , V_2 ) ;
#endif
}
const T_3 *
F_4 ( const T_3 * V_5 , T_4 V_6 , const T_1 * V_1 , T_5 * V_7 )
{
const T_3 * V_8 = V_5 + V_6 ;
while ( V_5 < V_8 ) {
if ( V_1 -> V_4 [ * V_5 ] ) {
if ( V_7 )
* V_7 = * V_5 ;
return V_5 ;
}
V_5 ++ ;
}
return NULL ;
}
T_6 const T_3 *
F_5 ( const T_3 * V_5 , T_4 V_6 , const T_1 * V_1 , T_5 * V_7 )
{
#ifdef F_2
if ( V_6 >= 16 && V_1 -> V_9 )
return F_6 ( V_5 , V_6 , V_1 , V_7 ) ;
#endif
return F_4 ( V_5 , V_6 , V_1 , V_7 ) ;
}
