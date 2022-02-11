T_1 * F_1 ( void )
{
return NULL ;
}
T_1 * F_1 ( void )
{
return ( & V_1 ) ;
}
static int F_2 ( T_2 * V_2 , const char * V_3 )
{
T_3 V_4 , * V_5 ;
char V_6 [ V_7 ] ;
int V_8 ;
V_8 = strlen ( V_3 ) ;
if( ( V_2 -> V_9 & V_10 ) &&
( V_8 + 4 < V_7 ) &&
( strstr ( V_3 , L_1 ) == NULL ) &&
( strstr ( V_3 , L_2 ) == NULL ) &&
( strstr ( V_3 , L_3 ) == NULL ) )
{
sprintf ( V_6 , L_4 , V_3 ) ;
V_4 = F_3 ( V_6 ) ;
}
else
V_4 = F_3 ( V_3 ) ;
if( V_4 == NULL )
{
F_4 ( V_11 , V_12 ) ;
return ( 0 ) ;
}
V_5 = ( T_3 * ) F_5 ( sizeof( T_3 ) ) ;
if( V_5 == NULL )
{
F_4 ( V_11 , V_13 ) ;
F_6 ( V_4 ) ;
return ( 0 ) ;
}
* V_5 = V_4 ;
if( ! F_7 ( V_2 -> V_14 , ( char * ) V_5 ) )
{
F_4 ( V_11 , V_15 ) ;
F_6 ( V_4 ) ;
F_8 ( V_5 ) ;
return ( 0 ) ;
}
return ( 1 ) ;
}
static int F_9 ( T_2 * V_2 )
{
T_3 * V_5 ;
if( V_2 == NULL )
{
F_4 ( V_16 , V_17 ) ;
return ( 0 ) ;
}
if( F_10 ( V_2 -> V_14 ) < 1 )
return ( 1 ) ;
V_5 = ( T_3 * ) F_11 ( V_2 -> V_14 ) ;
if( V_5 == NULL )
{
F_4 ( V_16 , V_18 ) ;
return ( 0 ) ;
}
if( ! F_6 ( * V_5 ) )
{
F_4 ( V_16 , V_19 ) ;
F_7 ( V_2 -> V_14 , ( char * ) V_5 ) ;
return ( 0 ) ;
}
F_8 ( V_5 ) ;
return ( 1 ) ;
}
static void * F_12 ( T_2 * V_2 , const char * V_20 )
{
T_3 * V_21 ;
void * V_22 ;
if( ( V_2 == NULL ) || ( V_20 == NULL ) )
{
F_4 ( V_23 , V_17 ) ;
return ( NULL ) ;
}
if( F_10 ( V_2 -> V_14 ) < 1 )
{
F_4 ( V_23 , V_15 ) ;
return ( NULL ) ;
}
V_21 = ( T_3 * ) F_13 ( V_2 -> V_14 , F_10 ( V_2 -> V_14 ) - 1 ) ;
if( V_21 == NULL )
{
F_4 ( V_23 , V_18 ) ;
return ( NULL ) ;
}
V_22 = F_14 ( * V_21 , V_20 ) ;
if( V_22 == NULL )
{
F_4 ( V_23 , V_24 ) ;
return ( NULL ) ;
}
return ( V_22 ) ;
}
static T_4 F_15 ( T_2 * V_2 , const char * V_20 )
{
T_3 * V_21 ;
void * V_22 ;
if( ( V_2 == NULL ) || ( V_20 == NULL ) )
{
F_4 ( V_25 , V_17 ) ;
return ( NULL ) ;
}
if( F_10 ( V_2 -> V_14 ) < 1 )
{
F_4 ( V_25 , V_15 ) ;
return ( NULL ) ;
}
V_21 = ( T_3 * ) F_13 ( V_2 -> V_14 , F_10 ( V_2 -> V_14 ) - 1 ) ;
if( V_21 == NULL )
{
F_4 ( V_25 , V_18 ) ;
return ( NULL ) ;
}
V_22 = F_14 ( * V_21 , V_20 ) ;
if( V_22 == NULL )
{
F_4 ( V_25 , V_24 ) ;
return ( NULL ) ;
}
return ( ( T_4 ) V_22 ) ;
}
static long F_16 ( T_2 * V_2 , int V_26 , long V_27 , void * V_28 )
{
if( V_2 == NULL )
{
F_4 ( V_29 , V_17 ) ;
return ( - 1 ) ;
}
switch( V_26 )
{
case V_30 :
return V_2 -> V_9 ;
case V_31 :
V_2 -> V_9 = ( int ) V_27 ;
return ( 0 ) ;
case V_32 :
V_2 -> V_9 |= ( int ) V_27 ;
return ( 0 ) ;
default:
break;
}
F_4 ( V_29 , V_33 ) ;
return ( - 1 ) ;
}
