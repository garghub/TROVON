const T_1 * F_1 ( void )
{
return ( & V_1 ) ;
}
static int F_2 ( T_2 * V_2 )
{
T_3 * V_3 ;
V_3 = F_3 () ;
if ( V_3 == NULL )
return ( 0 ) ;
F_4 ( V_2 , 1 ) ;
F_5 ( V_2 , V_3 ) ;
return 1 ;
}
static int F_6 ( T_2 * V_4 )
{
if ( V_4 == NULL )
return ( 0 ) ;
F_7 ( F_8 ( V_4 ) ) ;
F_5 ( V_4 , NULL ) ;
F_4 ( V_4 , 0 ) ;
return 1 ;
}
static int F_9 ( T_2 * V_5 , char * V_6 , int V_7 )
{
int V_8 = 0 ;
T_3 * V_3 ;
T_2 * V_9 ;
if ( V_6 == NULL )
return ( 0 ) ;
V_3 = F_8 ( V_5 ) ;
V_9 = F_10 ( V_5 ) ;
if ( ( V_3 == NULL ) || ( V_9 == NULL ) )
return ( 0 ) ;
V_8 = F_11 ( V_9 , V_6 , V_7 ) ;
if ( F_12 ( V_5 ) ) {
if ( V_8 > 0 ) {
if ( F_13 ( V_3 , ( unsigned char * ) V_6 ,
( unsigned int ) V_8 ) <= 0 )
return ( - 1 ) ;
}
}
F_14 ( V_5 ) ;
F_15 ( V_5 ) ;
return ( V_8 ) ;
}
static int F_16 ( T_2 * V_5 , const char * V_10 , int V_11 )
{
int V_8 = 0 ;
T_3 * V_3 ;
T_2 * V_9 ;
if ( ( V_10 == NULL ) || ( V_11 <= 0 ) )
return 0 ;
V_3 = F_8 ( V_5 ) ;
V_9 = F_10 ( V_5 ) ;
if ( ( V_3 != NULL ) && ( V_9 != NULL ) )
V_8 = F_17 ( V_9 , V_10 , V_11 ) ;
if ( F_12 ( V_5 ) ) {
if ( V_8 > 0 ) {
if ( ! F_13 ( V_3 , ( const unsigned char * ) V_10 ,
( unsigned int ) V_8 ) ) {
F_14 ( V_5 ) ;
return 0 ;
}
}
}
if ( V_9 != NULL ) {
F_14 ( V_5 ) ;
F_15 ( V_5 ) ;
}
return V_8 ;
}
static long F_18 ( T_2 * V_5 , int V_12 , long V_13 , void * V_14 )
{
T_3 * V_3 , * V_15 , * * V_16 ;
const T_4 * * V_17 ;
T_4 * V_18 ;
long V_8 = 1 ;
T_2 * V_19 , * V_9 ;
V_3 = F_8 ( V_5 ) ;
V_9 = F_10 ( V_5 ) ;
switch ( V_12 ) {
case V_20 :
if ( F_12 ( V_5 ) )
V_8 = F_19 ( V_3 , V_3 -> V_21 , NULL ) ;
else
V_8 = 0 ;
if ( V_8 > 0 )
V_8 = F_20 ( V_9 , V_12 , V_13 , V_14 ) ;
break;
case V_22 :
if ( F_12 ( V_5 ) ) {
V_17 = V_14 ;
* V_17 = V_3 -> V_21 ;
} else
V_8 = 0 ;
break;
case V_23 :
V_16 = V_14 ;
* V_16 = V_3 ;
F_4 ( V_5 , 1 ) ;
break;
case V_24 :
if ( F_12 ( V_5 ) )
F_5 ( V_5 , V_14 ) ;
else
V_8 = 0 ;
break;
case V_25 :
F_14 ( V_5 ) ;
V_8 = F_20 ( V_9 , V_12 , V_13 , V_14 ) ;
F_15 ( V_5 ) ;
break;
case V_26 :
V_18 = V_14 ;
V_8 = F_19 ( V_3 , V_18 , NULL ) ;
if ( V_8 > 0 )
F_4 ( V_5 , 1 ) ;
break;
case V_27 :
V_19 = V_14 ;
V_15 = F_8 ( V_19 ) ;
if ( ! F_21 ( V_15 , V_3 ) )
return 0 ;
F_4 ( V_5 , 1 ) ;
break;
default:
V_8 = F_20 ( V_9 , V_12 , V_13 , V_14 ) ;
break;
}
return ( V_8 ) ;
}
static long F_22 ( T_2 * V_5 , int V_12 , T_5 * V_28 )
{
long V_8 = 1 ;
T_2 * V_9 ;
V_9 = F_10 ( V_5 ) ;
if ( V_9 == NULL )
return 0 ;
switch ( V_12 ) {
default:
V_8 = F_23 ( V_9 , V_12 , V_28 ) ;
break;
}
return ( V_8 ) ;
}
static int F_24 ( T_2 * V_29 , char * V_30 , int V_31 )
{
T_3 * V_3 ;
unsigned int V_8 ;
V_3 = F_8 ( V_29 ) ;
if ( V_31 < V_3 -> V_21 -> V_32 )
return 0 ;
if ( F_25 ( V_3 , ( unsigned char * ) V_30 , & V_8 ) <= 0 )
return - 1 ;
return ( ( int ) V_8 ) ;
}
