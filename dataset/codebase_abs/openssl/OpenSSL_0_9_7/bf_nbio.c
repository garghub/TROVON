T_1 * F_1 ( void )
{
return ( & V_1 ) ;
}
static int F_2 ( T_2 * V_2 )
{
T_3 * V_3 ;
if ( ! ( V_3 = ( T_3 * ) F_3 ( sizeof( T_3 ) ) ) ) return ( 0 ) ;
V_3 -> V_4 = - 1 ;
V_3 -> V_5 = - 1 ;
V_2 -> V_6 = ( char * ) V_3 ;
V_2 -> V_7 = 1 ;
V_2 -> V_8 = 0 ;
return ( 1 ) ;
}
static int F_4 ( T_2 * V_9 )
{
if ( V_9 == NULL ) return ( 0 ) ;
if ( V_9 -> V_6 != NULL )
F_5 ( V_9 -> V_6 ) ;
V_9 -> V_6 = NULL ;
V_9 -> V_7 = 0 ;
V_9 -> V_8 = 0 ;
return ( 1 ) ;
}
static int F_6 ( T_2 * V_10 , char * V_11 , int V_12 )
{
T_3 * V_3 ;
int V_13 = 0 ;
#if 0
int num;
unsigned char n;
#endif
if ( V_11 == NULL ) return ( 0 ) ;
if ( V_10 -> V_14 == NULL ) return ( 0 ) ;
V_3 = ( T_3 * ) V_10 -> V_6 ;
F_7 ( V_10 ) ;
#if 0
RAND_pseudo_bytes(&n,1);
num=(n&0x07);
if (outl > num) outl=num;
if (num == 0)
{
ret= -1;
BIO_set_retry_read(b);
}
else
#endif
{
V_13 = F_8 ( V_10 -> V_14 , V_11 , V_12 ) ;
if ( V_13 < 0 )
F_9 ( V_10 ) ;
}
return ( V_13 ) ;
}
static int F_10 ( T_2 * V_10 , const char * V_15 , int V_16 )
{
T_3 * V_3 ;
int V_13 = 0 ;
int V_17 ;
unsigned char V_18 ;
if ( ( V_15 == NULL ) || ( V_16 <= 0 ) ) return ( 0 ) ;
if ( V_10 -> V_14 == NULL ) return ( 0 ) ;
V_3 = ( T_3 * ) V_10 -> V_6 ;
F_7 ( V_10 ) ;
#if 1
if ( V_3 -> V_5 > 0 )
{
V_17 = V_3 -> V_5 ;
V_3 -> V_5 = 0 ;
}
else
{
F_11 ( & V_18 , 1 ) ;
V_17 = ( V_18 & 7 ) ;
}
if ( V_16 > V_17 ) V_16 = V_17 ;
if ( V_17 == 0 )
{
V_13 = - 1 ;
F_12 ( V_10 ) ;
}
else
#endif
{
V_13 = F_13 ( V_10 -> V_14 , V_15 , V_16 ) ;
if ( V_13 < 0 )
{
F_9 ( V_10 ) ;
V_3 -> V_5 = V_16 ;
}
}
return ( V_13 ) ;
}
static long F_14 ( T_2 * V_10 , int V_19 , long V_17 , void * V_6 )
{
long V_13 ;
if ( V_10 -> V_14 == NULL ) return ( 0 ) ;
switch ( V_19 )
{
case V_20 :
F_7 ( V_10 ) ;
V_13 = F_15 ( V_10 -> V_14 , V_19 , V_17 , V_6 ) ;
F_9 ( V_10 ) ;
break;
case V_21 :
V_13 = 0L ;
break;
default:
V_13 = F_15 ( V_10 -> V_14 , V_19 , V_17 , V_6 ) ;
break;
}
return ( V_13 ) ;
}
static long F_16 ( T_2 * V_10 , int V_19 , T_4 * V_22 )
{
long V_13 = 1 ;
if ( V_10 -> V_14 == NULL ) return ( 0 ) ;
switch ( V_19 )
{
default:
V_13 = F_17 ( V_10 -> V_14 , V_19 , V_22 ) ;
break;
}
return ( V_13 ) ;
}
static int F_18 ( T_2 * V_23 , char * V_24 , int V_25 )
{
if ( V_23 -> V_14 == NULL ) return ( 0 ) ;
return ( F_19 ( V_23 -> V_14 , V_24 , V_25 ) ) ;
}
static int F_20 ( T_2 * V_23 , const char * V_26 )
{
if ( V_23 -> V_14 == NULL ) return ( 0 ) ;
return ( F_21 ( V_23 -> V_14 , V_26 ) ) ;
}
