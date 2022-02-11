const struct V_1 * F_1 ( const char * V_2 )
{
unsigned int V_3 ;
for ( V_3 = 0 ; V_3 < V_4 ; V_3 ++ )
if ( ! strcmp ( V_5 [ V_3 ] -> V_2 , V_2 ) )
return V_5 [ V_3 ] ;
return NULL ;
}
const struct V_1 * F_2 ( int V_6 , int V_7 , T_1 V_8 ,
T_1 V_9 )
{
int V_3 , V_10 , V_11 ;
const struct V_1 * V_12 , * V_13 ;
V_13 = NULL ;
V_11 = - 10000 ;
for( V_3 = 0 ; V_3 < V_4 ; V_3 ++ ) {
V_12 = V_5 [ V_3 ] ;
V_10 = V_12 -> V_14 ;
#if F_3 ( V_15 )
#ifdef F_4
if ( V_16 && V_12 -> V_17 == V_18 )
V_10 = 100 ;
#endif
#ifdef F_5
if ( V_19 && V_6 < 640 && V_12 -> V_17 == V_20 )
V_10 = 100 ;
#endif
#endif
if ( ( V_7 < 400 ) == ( V_12 -> V_21 <= 8 ) )
V_10 += 1000 ;
if ( ( V_8 & ( 1 << ( V_12 -> V_22 - 1 ) ) ) &&
( V_9 & ( 1 << ( V_12 -> V_21 - 1 ) ) ) )
V_10 += 1000 ;
if ( V_10 > V_11 ) {
V_11 = V_10 ;
V_13 = V_12 ;
}
}
return V_13 ;
}
