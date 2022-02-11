long F_1 ( void )
{
return ( 300 ) ;
}
int F_2 ( void )
{
return ( F_3 ()
#ifndef F_4
+ F_5 ()
#endif
) ;
}
const T_1 * F_6 ( unsigned int V_1 )
{
unsigned int V_2 = F_3 () ;
if ( V_1 < V_2 )
return ( F_7 ( V_1 ) ) ;
else
#ifndef F_4
return ( F_8 ( V_1 - V_2 ) ) ;
#else
return ( NULL ) ;
#endif
}
const T_1 * F_9 ( const unsigned char * V_3 )
{
const T_1 * V_4 ;
V_4 = F_10 ( V_3 ) ;
#ifndef F_4
if ( V_4 == NULL )
V_4 = F_11 ( V_3 ) ;
#endif
return ( V_4 ) ;
}
int F_12 ( const T_1 * V_5 , unsigned char * V_3 )
{
long V_6 ;
if ( V_5 -> V_7 == V_8 ||
V_5 -> V_7 == V_9 ||
V_5 -> V_7 == V_10 ||
V_5 -> V_11 == V_12 || V_5 -> V_11 == V_13 )
return 0 ;
if ( V_3 != NULL ) {
V_6 = V_5 -> V_14 ;
V_3 [ 0 ] = ( ( unsigned char ) ( V_6 >> 16L ) ) & 0xFF ;
V_3 [ 1 ] = ( ( unsigned char ) ( V_6 >> 8L ) ) & 0xFF ;
V_3 [ 2 ] = ( ( unsigned char ) ( V_6 ) ) & 0xFF ;
}
return ( 3 ) ;
}
int F_13 ( T_2 * V_15 , void * V_16 , int V_17 )
{
int V_18 ;
F_14 () ;
if ( F_15 ( V_15 ) && ( ! V_15 -> V_19 ) ) {
V_18 = V_15 -> V_20 ( V_15 ) ;
if ( V_18 < 0 )
return ( V_18 ) ;
if ( V_18 == 0 ) {
F_16 ( V_21 , V_22 ) ;
return ( - 1 ) ;
}
return ( F_17 ( V_15 , V_16 , V_17 ) ) ;
} else {
F_18 ( V_15 ) ;
return ( - 1 ) ;
}
}
int F_19 ( T_2 * V_15 , void * V_16 , int V_17 )
{
int V_18 ;
F_14 () ;
if ( F_15 ( V_15 ) && ( ! V_15 -> V_19 ) ) {
V_18 = V_15 -> V_20 ( V_15 ) ;
if ( V_18 < 0 )
return ( V_18 ) ;
if ( V_18 == 0 ) {
F_16 ( V_23 , V_22 ) ;
return ( - 1 ) ;
}
return ( F_20 ( V_15 , V_16 , V_17 ) ) ;
} else {
F_18 ( V_15 ) ;
return ( - 1 ) ;
}
}
int F_21 ( T_2 * V_15 , const void * V_16 , int V_17 )
{
int V_18 ;
F_14 () ;
if ( F_15 ( V_15 ) && ( ! V_15 -> V_19 ) ) {
V_18 = V_15 -> V_20 ( V_15 ) ;
if ( V_18 < 0 )
return ( V_18 ) ;
if ( V_18 == 0 ) {
F_16 ( V_24 , V_22 ) ;
return ( - 1 ) ;
}
return ( F_22 ( V_15 , V_16 , V_17 ) ) ;
} else {
F_18 ( V_15 ) ;
return ( - 1 ) ;
}
}
