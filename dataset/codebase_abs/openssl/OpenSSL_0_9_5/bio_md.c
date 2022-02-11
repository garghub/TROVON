T_1 * F_1 ( void )
{
return ( & V_1 ) ;
}
static int F_2 ( T_2 * V_2 )
{
T_3 * V_3 ;
V_3 = ( T_3 * ) Malloc ( sizeof( T_3 ) ) ;
if ( V_3 == NULL ) return ( 0 ) ;
V_2 -> V_4 = 0 ;
V_2 -> V_5 = ( char * ) V_3 ;
V_2 -> V_6 = 0 ;
return ( 1 ) ;
}
static int F_3 ( T_2 * V_7 )
{
if ( V_7 == NULL ) return ( 0 ) ;
Free ( V_7 -> V_5 ) ;
V_7 -> V_5 = NULL ;
V_7 -> V_4 = 0 ;
V_7 -> V_6 = 0 ;
return ( 1 ) ;
}
static int F_4 ( T_2 * V_8 , char * V_9 , int V_10 )
{
int V_11 = 0 ;
T_3 * V_3 ;
if ( V_9 == NULL ) return ( 0 ) ;
V_3 = ( T_3 * ) V_8 -> V_5 ;
if ( ( V_3 == NULL ) || ( V_8 -> V_12 == NULL ) ) return ( 0 ) ;
V_11 = F_5 ( V_8 -> V_12 , V_9 , V_10 ) ;
if ( V_8 -> V_4 )
{
if ( V_11 > 0 )
{
F_6 ( V_3 , ( unsigned char * ) V_9 ,
( unsigned int ) V_11 ) ;
}
}
F_7 ( V_8 ) ;
F_8 ( V_8 ) ;
return ( V_11 ) ;
}
static int F_9 ( T_2 * V_8 , char * V_13 , int V_14 )
{
int V_11 = 0 ;
T_3 * V_3 ;
if ( ( V_13 == NULL ) || ( V_14 <= 0 ) ) return ( 0 ) ;
V_3 = ( T_3 * ) V_8 -> V_5 ;
if ( ( V_3 != NULL ) && ( V_8 -> V_12 != NULL ) )
V_11 = F_10 ( V_8 -> V_12 , V_13 , V_14 ) ;
if ( V_8 -> V_4 )
{
if ( V_11 > 0 )
{
F_6 ( V_3 , ( unsigned char * ) V_13 ,
( unsigned int ) V_11 ) ;
}
}
F_7 ( V_8 ) ;
F_8 ( V_8 ) ;
return ( V_11 ) ;
}
static long F_11 ( T_2 * V_8 , int V_15 , long V_16 , char * V_5 )
{
T_3 * V_3 , * V_17 , * * V_18 ;
const T_4 * * V_19 ;
T_4 * V_20 ;
long V_11 = 1 ;
T_2 * V_21 ;
V_3 = ( T_3 * ) V_8 -> V_5 ;
switch ( V_15 )
{
case V_22 :
if ( V_8 -> V_4 )
F_12 ( V_3 , V_3 -> V_23 ) ;
else
V_11 = 0 ;
V_11 = F_13 ( V_8 -> V_12 , V_15 , V_16 , V_5 ) ;
break;
case V_24 :
if ( V_8 -> V_4 )
{
V_19 = ( const T_4 * * ) V_5 ;
* V_19 = V_3 -> V_23 ;
}
else
V_11 = 0 ;
break;
case V_25 :
if ( V_8 -> V_4 )
{
V_18 = ( T_3 * * ) V_5 ;
* V_18 = V_3 ;
}
else
V_11 = 0 ;
break;
case V_26 :
F_7 ( V_8 ) ;
V_11 = F_13 ( V_8 -> V_12 , V_15 , V_16 , V_5 ) ;
F_8 ( V_8 ) ;
break;
case V_27 :
V_20 = ( T_4 * ) V_5 ;
F_12 ( V_3 , V_20 ) ;
V_8 -> V_4 = 1 ;
break;
case V_28 :
V_21 = ( T_2 * ) V_5 ;
V_17 = ( T_3 * ) V_21 -> V_5 ;
memcpy ( V_17 , V_3 , sizeof( V_3 ) ) ;
V_8 -> V_4 = 1 ;
break;
default:
V_11 = F_13 ( V_8 -> V_12 , V_15 , V_16 , V_5 ) ;
break;
}
return ( V_11 ) ;
}
static long F_14 ( T_2 * V_8 , int V_15 , void (* F_15)() )
{
long V_11 = 1 ;
if ( V_8 -> V_12 == NULL ) return ( 0 ) ;
switch ( V_15 )
{
default:
V_11 = F_16 ( V_8 -> V_12 , V_15 , F_15 ) ;
break;
}
return ( V_11 ) ;
}
static int F_17 ( T_2 * V_29 , char * V_30 , int V_31 )
{
T_3 * V_3 ;
unsigned int V_11 ;
V_3 = ( T_3 * ) V_29 -> V_5 ;
if ( V_31 < V_3 -> V_23 -> V_32 )
return ( 0 ) ;
F_18 ( V_3 , ( unsigned char * ) V_30 , & V_11 ) ;
return ( ( int ) V_11 ) ;
}
