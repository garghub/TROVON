T_1 * F_1 ( void )
{
return NULL ;
}
T_1 * F_1 ( void )
{
return ( & V_1 ) ;
}
static int F_2 ( T_2 * V_2 )
{
T_3 V_3 = NULL , * V_4 = NULL ;
char * V_5 = F_3 ( V_2 , NULL ) ;
if( V_5 == NULL )
{
F_4 ( V_6 , V_7 ) ;
goto V_8;
}
V_3 = F_5 ( V_5 ) ;
if( V_3 == NULL )
{
F_4 ( V_6 , V_9 ) ;
F_6 ( 3 , L_1 , V_5 , L_2 ) ;
goto V_8;
}
V_4 = ( T_3 * ) F_7 ( sizeof( T_3 ) ) ;
if( V_4 == NULL )
{
F_4 ( V_6 , V_10 ) ;
goto V_8;
}
* V_4 = V_3 ;
if( ! F_8 ( V_2 -> V_11 , ( char * ) V_4 ) )
{
F_4 ( V_6 , V_12 ) ;
goto V_8;
}
V_2 -> V_13 = V_5 ;
return ( 1 ) ;
V_8:
if( V_5 != NULL )
F_9 ( V_5 ) ;
if( V_4 != NULL )
F_9 ( V_4 ) ;
if( V_3 != NULL )
F_10 ( V_3 ) ;
return ( 0 ) ;
}
static int F_11 ( T_2 * V_2 )
{
T_3 * V_4 ;
if( V_2 == NULL )
{
F_4 ( V_14 , V_15 ) ;
return ( 0 ) ;
}
if( F_12 ( V_2 -> V_11 ) < 1 )
return ( 1 ) ;
V_4 = ( T_3 * ) F_13 ( V_2 -> V_11 ) ;
if( V_4 == NULL )
{
F_4 ( V_14 , V_16 ) ;
return ( 0 ) ;
}
if( ! F_10 ( * V_4 ) )
{
F_4 ( V_14 , V_17 ) ;
F_8 ( V_2 -> V_11 , ( char * ) V_4 ) ;
return ( 0 ) ;
}
F_9 ( V_4 ) ;
return ( 1 ) ;
}
static void * F_14 ( T_2 * V_2 , const char * V_18 )
{
T_3 * V_19 ;
void * V_20 ;
if( ( V_2 == NULL ) || ( V_18 == NULL ) )
{
F_4 ( V_21 , V_15 ) ;
return ( NULL ) ;
}
if( F_12 ( V_2 -> V_11 ) < 1 )
{
F_4 ( V_21 , V_12 ) ;
return ( NULL ) ;
}
V_19 = ( T_3 * ) F_15 ( V_2 -> V_11 , F_12 ( V_2 -> V_11 ) - 1 ) ;
if( V_19 == NULL )
{
F_4 ( V_21 , V_16 ) ;
return ( NULL ) ;
}
V_20 = F_16 ( * V_19 , V_18 ) ;
if( V_20 == NULL )
{
F_4 ( V_21 , V_22 ) ;
F_6 ( 3 , L_3 , V_18 , L_2 ) ;
return ( NULL ) ;
}
return ( V_20 ) ;
}
static T_4 F_17 ( T_2 * V_2 , const char * V_18 )
{
T_3 * V_19 ;
void * V_20 ;
if( ( V_2 == NULL ) || ( V_18 == NULL ) )
{
F_4 ( V_23 , V_15 ) ;
return ( NULL ) ;
}
if( F_12 ( V_2 -> V_11 ) < 1 )
{
F_4 ( V_23 , V_12 ) ;
return ( NULL ) ;
}
V_19 = ( T_3 * ) F_15 ( V_2 -> V_11 , F_12 ( V_2 -> V_11 ) - 1 ) ;
if( V_19 == NULL )
{
F_4 ( V_23 , V_16 ) ;
return ( NULL ) ;
}
V_20 = F_16 ( * V_19 , V_18 ) ;
if( V_20 == NULL )
{
F_4 ( V_23 , V_22 ) ;
F_6 ( 3 , L_3 , V_18 , L_2 ) ;
return ( NULL ) ;
}
return ( ( T_4 ) V_20 ) ;
}
static char * F_18 ( T_2 * V_2 , const char * V_5 )
{
char * V_24 ;
int V_25 , V_26 ;
V_25 = strlen ( V_5 ) ;
V_26 = ( ( strstr ( V_5 , L_4 ) == NULL ) &&
( strstr ( V_5 , L_5 ) == NULL ) &&
( strstr ( V_5 , L_6 ) == NULL ) ) ;
if( V_26 )
V_24 = F_7 ( V_25 + 5 ) ;
else
V_24 = F_7 ( V_25 + 1 ) ;
if( V_24 == NULL )
{
F_4 ( V_27 ,
V_28 ) ;
return ( NULL ) ;
}
if( V_26 )
sprintf ( V_24 , L_7 , V_5 ) ;
else
sprintf ( V_24 , L_8 , V_5 ) ;
return ( V_24 ) ;
}
