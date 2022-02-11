T_1 * F_1 ( void )
{
return ( & V_1 ) ;
}
static int F_2 ( T_2 * V_2 )
{
T_3 * V_3 ;
V_3 = F_3 () ;
if ( V_3 == NULL ) return ( 0 ) ;
V_2 -> V_4 = 0 ;
V_2 -> V_5 = ( char * ) V_3 ;
V_2 -> V_6 = 0 ;
return ( 1 ) ;
}
static int F_4 ( T_2 * V_7 )
{
if ( V_7 == NULL ) return ( 0 ) ;
F_5 ( V_7 -> V_5 ) ;
V_7 -> V_5 = NULL ;
V_7 -> V_4 = 0 ;
V_7 -> V_6 = 0 ;
return ( 1 ) ;
}
static int F_6 ( T_2 * V_8 , char * V_9 , int V_10 )
{
int V_11 = 0 ;
T_3 * V_3 ;
if ( V_9 == NULL ) return ( 0 ) ;
V_3 = V_8 -> V_5 ;
if ( ( V_3 == NULL ) || ( V_8 -> V_12 == NULL ) ) return ( 0 ) ;
V_11 = F_7 ( V_8 -> V_12 , V_9 , V_10 ) ;
if ( V_8 -> V_4 )
{
if ( V_11 > 0 )
{
if ( F_8 ( V_3 , ( unsigned char * ) V_9 ,
( unsigned int ) V_11 ) <= 0 ) return ( - 1 ) ;
}
}
F_9 ( V_8 ) ;
F_10 ( V_8 ) ;
return ( V_11 ) ;
}
static int F_11 ( T_2 * V_8 , const char * V_13 , int V_14 )
{
int V_11 = 0 ;
T_3 * V_3 ;
if ( ( V_13 == NULL ) || ( V_14 <= 0 ) ) return ( 0 ) ;
V_3 = V_8 -> V_5 ;
if ( ( V_3 != NULL ) && ( V_8 -> V_12 != NULL ) )
V_11 = F_12 ( V_8 -> V_12 , V_13 , V_14 ) ;
if ( V_8 -> V_4 )
{
if ( V_11 > 0 )
{
F_8 ( V_3 , ( const unsigned char * ) V_13 ,
( unsigned int ) V_11 ) ;
}
}
if( V_8 -> V_12 != NULL )
{
F_9 ( V_8 ) ;
F_10 ( V_8 ) ;
}
return ( V_11 ) ;
}
static long F_13 ( T_2 * V_8 , int V_15 , long V_16 , void * V_5 )
{
T_3 * V_3 , * V_17 , * * V_18 ;
const T_4 * * V_19 ;
T_4 * V_20 ;
long V_11 = 1 ;
T_2 * V_21 ;
V_3 = V_8 -> V_5 ;
switch ( V_15 )
{
case V_22 :
if ( V_8 -> V_4 )
V_11 = F_14 ( V_3 , V_3 -> V_23 , NULL ) ;
else
V_11 = 0 ;
if ( V_11 > 0 )
V_11 = F_15 ( V_8 -> V_12 , V_15 , V_16 , V_5 ) ;
break;
case V_24 :
if ( V_8 -> V_4 )
{
V_19 = V_5 ;
* V_19 = V_3 -> V_23 ;
}
else
V_11 = 0 ;
break;
case V_25 :
V_18 = V_5 ;
* V_18 = V_3 ;
V_8 -> V_4 = 1 ;
break;
case V_26 :
if ( V_8 -> V_4 )
V_8 -> V_5 = V_5 ;
else
V_11 = 0 ;
break;
case V_27 :
F_9 ( V_8 ) ;
V_11 = F_15 ( V_8 -> V_12 , V_15 , V_16 , V_5 ) ;
F_10 ( V_8 ) ;
break;
case V_28 :
V_20 = V_5 ;
V_11 = F_14 ( V_3 , V_20 , NULL ) ;
if ( V_11 > 0 )
V_8 -> V_4 = 1 ;
break;
case V_29 :
V_21 = V_5 ;
V_17 = V_21 -> V_5 ;
F_16 ( V_17 , V_3 ) ;
V_8 -> V_4 = 1 ;
break;
default:
V_11 = F_15 ( V_8 -> V_12 , V_15 , V_16 , V_5 ) ;
break;
}
return ( V_11 ) ;
}
static long F_17 ( T_2 * V_8 , int V_15 , T_5 * V_30 )
{
long V_11 = 1 ;
if ( V_8 -> V_12 == NULL ) return ( 0 ) ;
switch ( V_15 )
{
default:
V_11 = F_18 ( V_8 -> V_12 , V_15 , V_30 ) ;
break;
}
return ( V_11 ) ;
}
static int F_19 ( T_2 * V_31 , char * V_32 , int V_33 )
{
T_3 * V_3 ;
unsigned int V_11 ;
V_3 = V_31 -> V_5 ;
if ( V_33 < V_3 -> V_23 -> V_34 )
return ( 0 ) ;
if ( F_20 ( V_3 , ( unsigned char * ) V_32 , & V_11 ) <= 0 )
return - 1 ;
return ( ( int ) V_11 ) ;
}
