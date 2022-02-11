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
T_1 V_4 ;
const T_1 * V_5 ;
unsigned long V_6 ;
int V_7 ;
V_7 = F_3 () ;
V_6 = 0x03000000 | ( ( unsigned long ) V_3 [ 0 ] << 16L ) |
( ( unsigned long ) V_3 [ 1 ] << 8L ) | ( unsigned long ) V_3 [ 2 ] ;
V_4 . V_6 = V_6 ;
V_5 = F_10 ( V_3 ) ;
#ifndef F_4
if ( V_5 == NULL )
V_5 = F_11 ( V_3 ) ;
#endif
return ( V_5 ) ;
}
int F_12 ( const T_1 * V_4 , unsigned char * V_3 )
{
long V_8 ;
if ( V_3 != NULL )
{
V_8 = V_4 -> V_6 ;
V_3 [ 0 ] = ( ( unsigned char ) ( V_8 >> 16L ) ) & 0xFF ;
V_3 [ 1 ] = ( ( unsigned char ) ( V_8 >> 8L ) ) & 0xFF ;
V_3 [ 2 ] = ( ( unsigned char ) ( V_8 ) ) & 0xFF ;
}
return ( 3 ) ;
}
int F_13 ( T_2 * V_9 , void * V_10 , int V_11 )
{
int V_7 ;
F_14 () ;
if ( F_15 ( V_9 ) && ( ! V_9 -> V_12 ) )
{
V_7 = V_9 -> V_13 ( V_9 ) ;
if ( V_7 < 0 ) return ( V_7 ) ;
if ( V_7 == 0 )
{
F_16 ( V_14 , V_15 ) ;
return ( - 1 ) ;
}
return ( F_17 ( V_9 , V_10 , V_11 ) ) ;
}
else
{
F_18 ( V_9 ) ;
return ( - 1 ) ;
}
}
int F_19 ( T_2 * V_9 , void * V_10 , int V_11 )
{
int V_7 ;
F_14 () ;
if ( F_15 ( V_9 ) && ( ! V_9 -> V_12 ) )
{
V_7 = V_9 -> V_13 ( V_9 ) ;
if ( V_7 < 0 ) return ( V_7 ) ;
if ( V_7 == 0 )
{
F_16 ( V_16 , V_15 ) ;
return ( - 1 ) ;
}
return ( F_20 ( V_9 , V_10 , V_11 ) ) ;
}
else
{
F_18 ( V_9 ) ;
return ( - 1 ) ;
}
}
int F_21 ( T_2 * V_9 , const void * V_10 , int V_11 )
{
int V_7 ;
F_14 () ;
if ( F_15 ( V_9 ) && ( ! V_9 -> V_12 ) )
{
V_7 = V_9 -> V_13 ( V_9 ) ;
if ( V_7 < 0 ) return ( V_7 ) ;
if ( V_7 == 0 )
{
F_16 ( V_17 , V_15 ) ;
return ( - 1 ) ;
}
return ( F_22 ( V_9 , V_10 , V_11 ) ) ;
}
else
{
F_18 ( V_9 ) ;
return ( - 1 ) ;
}
}
