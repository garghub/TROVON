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
void * V_4 ;
char V_5 [ V_6 ] ;
int V_7 ;
V_7 = strlen ( V_3 ) ;
if( ( V_2 -> V_8 & V_9 ) &&
( V_7 + 6 < V_6 ) &&
( strstr ( V_3 , L_1 ) == NULL ) )
{
sprintf ( V_5 , L_2 , V_3 ) ;
V_4 = F_3 ( V_5 , V_10 ) ;
}
else
{
V_4 = F_3 ( V_3 , V_10 ) ;
}
if( V_4 == NULL )
{
F_4 ( V_11 , V_12 ) ;
return ( 0 ) ;
}
if( ! F_5 ( V_2 -> V_13 , ( char * ) V_4 ) )
{
F_4 ( V_11 , V_14 ) ;
F_6 ( V_4 ) ;
return ( 0 ) ;
}
return ( 1 ) ;
}
static int F_7 ( T_2 * V_2 )
{
void * V_4 ;
if( V_2 == NULL )
{
F_4 ( V_15 , V_16 ) ;
return ( 0 ) ;
}
if( F_8 ( V_2 -> V_13 ) < 1 )
return ( 1 ) ;
V_4 = ( void * ) F_9 ( V_2 -> V_13 ) ;
if( V_4 == NULL )
{
F_4 ( V_15 , V_17 ) ;
F_5 ( V_2 -> V_13 , ( char * ) V_4 ) ;
return ( 0 ) ;
}
F_6 ( V_4 ) ;
return ( 1 ) ;
}
static void * F_10 ( T_2 * V_2 , const char * V_18 )
{
void * V_4 , * V_19 ;
if( ( V_2 == NULL ) || ( V_18 == NULL ) )
{
F_4 ( V_20 , V_16 ) ;
return ( NULL ) ;
}
if( F_8 ( V_2 -> V_13 ) < 1 )
{
F_4 ( V_20 , V_14 ) ;
return ( NULL ) ;
}
V_4 = ( void * ) F_11 ( V_2 -> V_13 , F_8 ( V_2 -> V_13 ) - 1 ) ;
if( V_4 == NULL )
{
F_4 ( V_20 , V_17 ) ;
return ( NULL ) ;
}
V_19 = F_12 ( V_4 , V_18 ) ;
if( V_19 == NULL )
{
F_4 ( V_20 , V_21 ) ;
return ( NULL ) ;
}
return ( V_19 ) ;
}
static T_3 F_13 ( T_2 * V_2 , const char * V_18 )
{
void * V_4 ;
T_3 V_19 ;
if( ( V_2 == NULL ) || ( V_18 == NULL ) )
{
F_4 ( V_22 , V_16 ) ;
return ( NULL ) ;
}
if( F_8 ( V_2 -> V_13 ) < 1 )
{
F_4 ( V_22 , V_14 ) ;
return ( NULL ) ;
}
V_4 = ( void * ) F_11 ( V_2 -> V_13 , F_8 ( V_2 -> V_13 ) - 1 ) ;
if( V_4 == NULL )
{
F_4 ( V_22 , V_17 ) ;
return ( NULL ) ;
}
V_19 = ( T_3 ) F_12 ( V_4 , V_18 ) ;
if( V_19 == NULL )
{
F_4 ( V_22 , V_21 ) ;
return ( NULL ) ;
}
return ( V_19 ) ;
}
static long F_14 ( T_2 * V_2 , int V_23 , long V_24 , void * V_25 )
{
if( V_2 == NULL )
{
F_4 ( V_26 , V_16 ) ;
return ( - 1 ) ;
}
switch( V_23 )
{
case V_27 :
return V_2 -> V_8 ;
case V_28 :
V_2 -> V_8 = ( int ) V_24 ;
return ( 0 ) ;
case V_29 :
V_2 -> V_8 |= ( int ) V_24 ;
return ( 0 ) ;
default:
break;
}
F_4 ( V_26 , V_30 ) ;
return ( - 1 ) ;
}
