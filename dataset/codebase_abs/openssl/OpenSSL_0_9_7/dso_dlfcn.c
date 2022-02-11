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
void * V_3 = NULL ;
char * V_4 = F_3 ( V_2 , NULL ) ;
if( V_4 == NULL )
{
F_4 ( V_5 , V_6 ) ;
goto V_7;
}
V_3 = F_5 ( V_4 , V_8 ) ;
if( V_3 == NULL )
{
F_4 ( V_5 , V_9 ) ;
F_6 ( 4 , L_1 , V_4 , L_2 , F_7 () ) ;
goto V_7;
}
if( ! F_8 ( V_2 -> V_10 , ( char * ) V_3 ) )
{
F_4 ( V_5 , V_11 ) ;
goto V_7;
}
V_2 -> V_12 = V_4 ;
return ( 1 ) ;
V_7:
if( V_4 != NULL )
F_9 ( V_4 ) ;
if( V_3 != NULL )
F_10 ( V_3 ) ;
return ( 0 ) ;
}
static int F_11 ( T_2 * V_2 )
{
void * V_3 ;
if( V_2 == NULL )
{
F_4 ( V_13 , V_14 ) ;
return ( 0 ) ;
}
if( F_12 ( V_2 -> V_10 ) < 1 )
return ( 1 ) ;
V_3 = ( void * ) F_13 ( V_2 -> V_10 ) ;
if( V_3 == NULL )
{
F_4 ( V_13 , V_15 ) ;
F_8 ( V_2 -> V_10 , ( char * ) V_3 ) ;
return ( 0 ) ;
}
F_10 ( V_3 ) ;
return ( 1 ) ;
}
static void * F_14 ( T_2 * V_2 , const char * V_16 )
{
void * V_3 , * V_17 ;
if( ( V_2 == NULL ) || ( V_16 == NULL ) )
{
F_4 ( V_18 , V_14 ) ;
return ( NULL ) ;
}
if( F_12 ( V_2 -> V_10 ) < 1 )
{
F_4 ( V_18 , V_11 ) ;
return ( NULL ) ;
}
V_3 = ( void * ) F_15 ( V_2 -> V_10 , F_12 ( V_2 -> V_10 ) - 1 ) ;
if( V_3 == NULL )
{
F_4 ( V_18 , V_15 ) ;
return ( NULL ) ;
}
V_17 = F_16 ( V_3 , V_16 ) ;
if( V_17 == NULL )
{
F_4 ( V_18 , V_19 ) ;
F_6 ( 4 , L_3 , V_16 , L_2 , F_7 () ) ;
return ( NULL ) ;
}
return ( V_17 ) ;
}
static T_3 F_17 ( T_2 * V_2 , const char * V_16 )
{
void * V_3 ;
T_3 V_17 ;
if( ( V_2 == NULL ) || ( V_16 == NULL ) )
{
F_4 ( V_20 , V_14 ) ;
return ( NULL ) ;
}
if( F_12 ( V_2 -> V_10 ) < 1 )
{
F_4 ( V_20 , V_11 ) ;
return ( NULL ) ;
}
V_3 = ( void * ) F_15 ( V_2 -> V_10 , F_12 ( V_2 -> V_10 ) - 1 ) ;
if( V_3 == NULL )
{
F_4 ( V_20 , V_15 ) ;
return ( NULL ) ;
}
V_17 = ( T_3 ) F_16 ( V_3 , V_16 ) ;
if( V_17 == NULL )
{
F_4 ( V_20 , V_19 ) ;
F_6 ( 4 , L_3 , V_16 , L_2 , F_7 () ) ;
return ( NULL ) ;
}
return ( V_17 ) ;
}
static char * F_18 ( T_2 * V_2 , const char * V_4 )
{
char * V_21 ;
int V_22 , V_23 , V_24 ;
V_22 = strlen ( V_4 ) ;
V_23 = V_22 + 1 ;
V_24 = ( strstr ( V_4 , L_4 ) == NULL ) ;
if( V_24 )
{
V_23 += 3 ;
if ( ( F_19 ( V_2 ) & V_25 ) == 0 )
V_23 += 3 ;
}
V_21 = F_20 ( V_23 ) ;
if( V_21 == NULL )
{
F_4 ( V_26 ,
V_27 ) ;
return ( NULL ) ;
}
if( V_24 )
{
if ( ( F_19 ( V_2 ) & V_25 ) == 0 )
sprintf ( V_21 , L_5 , V_4 ) ;
else
sprintf ( V_21 , L_6 , V_4 ) ;
}
else
sprintf ( V_21 , L_7 , V_4 ) ;
return ( V_21 ) ;
}
