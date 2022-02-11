static long F_1 ( void )
{
return ( 300 ) ;
}
T_1 * F_2 ( void )
{
return ( & V_1 ) ;
}
static int F_3 ( void )
{
return ( F_4 () + F_5 () ) ;
}
static T_2 * F_6 ( unsigned int V_2 )
{
unsigned int V_3 = F_4 () ;
if ( V_2 < V_3 )
return ( F_7 ( V_2 ) ) ;
else
return ( F_8 ( V_2 - V_3 ) ) ;
}
static T_2 * F_9 ( const unsigned char * V_4 )
{
T_2 V_5 , * V_6 ;
unsigned long V_7 ;
int V_8 ;
V_8 = F_4 () ;
V_7 = 0x03000000 | ( ( unsigned long ) V_4 [ 0 ] << 16L ) |
( ( unsigned long ) V_4 [ 1 ] << 8L ) | ( unsigned long ) V_4 [ 2 ] ;
V_5 . V_7 = V_7 ;
V_6 = F_10 ( V_4 ) ;
if ( V_6 == NULL )
V_6 = F_11 ( V_4 ) ;
return ( V_6 ) ;
}
static int F_12 ( const T_2 * V_5 , unsigned char * V_4 )
{
long V_9 ;
if ( V_4 != NULL )
{
V_9 = V_5 -> V_7 ;
V_4 [ 0 ] = ( ( unsigned char ) ( V_9 >> 16L ) ) & 0xFF ;
V_4 [ 1 ] = ( ( unsigned char ) ( V_9 >> 8L ) ) & 0xFF ;
V_4 [ 2 ] = ( ( unsigned char ) ( V_9 ) ) & 0xFF ;
}
return ( 3 ) ;
}
static int F_13 ( T_3 * V_10 , void * V_11 , int V_12 )
{
int V_8 ;
#if 0
if (s->shutdown & SSL_RECEIVED_SHUTDOWN)
{
s->rwstate=SSL_NOTHING;
return(0);
}
#endif
F_14 () ;
if ( F_15 ( V_10 ) && ( ! V_10 -> V_13 ) )
{
V_8 = V_10 -> V_14 ( V_10 ) ;
if ( V_8 < 0 ) return ( V_8 ) ;
if ( V_8 == 0 )
{
F_16 ( V_15 , V_16 ) ;
return ( - 1 ) ;
}
return ( F_17 ( V_10 , V_11 , V_12 ) ) ;
}
else
{
F_18 ( V_10 ) ;
return ( - 1 ) ;
}
}
static int F_19 ( T_3 * V_10 , const void * V_11 , int V_12 )
{
int V_8 ;
#if 0
if (s->shutdown & SSL_SENT_SHUTDOWN)
{
s->rwstate=SSL_NOTHING;
return(0);
}
#endif
F_14 () ;
if ( F_15 ( V_10 ) && ( ! V_10 -> V_13 ) )
{
V_8 = V_10 -> V_14 ( V_10 ) ;
if ( V_8 < 0 ) return ( V_8 ) ;
if ( V_8 == 0 )
{
F_16 ( V_17 , V_16 ) ;
return ( - 1 ) ;
}
return ( F_20 ( V_10 , V_11 , V_12 ) ) ;
}
else
{
F_18 ( V_10 ) ;
return ( - 1 ) ;
}
}
