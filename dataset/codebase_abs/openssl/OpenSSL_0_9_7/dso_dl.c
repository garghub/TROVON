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
T_3 V_3 = NULL ;
char * V_4 = F_3 ( V_2 , NULL ) ;
if( V_4 == NULL )
{
F_4 ( V_5 , V_6 ) ;
goto V_7;
}
V_3 = F_5 ( V_4 , V_8 | V_9 , NULL ) ;
if( V_3 == NULL )
{
F_4 ( V_5 , V_10 ) ;
F_6 ( 4 , L_1 , V_4 , L_2 ,
strerror ( V_11 ) ) ;
goto V_7;
}
if( ! F_7 ( V_2 -> V_12 , ( char * ) V_3 ) )
{
F_4 ( V_5 , V_13 ) ;
goto V_7;
}
V_2 -> V_14 = V_4 ;
return ( 1 ) ;
V_7:
if( V_4 != NULL )
F_8 ( V_4 ) ;
if( V_3 != NULL )
F_9 ( V_3 ) ;
return ( 0 ) ;
}
static int F_10 ( T_2 * V_2 )
{
T_3 V_3 ;
if( V_2 == NULL )
{
F_4 ( V_15 , V_16 ) ;
return ( 0 ) ;
}
if( F_11 ( V_2 -> V_12 ) < 1 )
return ( 1 ) ;
V_3 = ( T_3 ) F_12 ( V_2 -> V_12 ) ;
if( V_3 == NULL )
{
F_4 ( V_15 , V_17 ) ;
F_7 ( V_2 -> V_12 , ( char * ) V_3 ) ;
return ( 0 ) ;
}
F_9 ( V_3 ) ;
return ( 1 ) ;
}
static void * F_13 ( T_2 * V_2 , const char * V_18 )
{
T_3 V_3 ;
void * V_19 ;
if( ( V_2 == NULL ) || ( V_18 == NULL ) )
{
F_4 ( V_20 , V_16 ) ;
return ( NULL ) ;
}
if( F_11 ( V_2 -> V_12 ) < 1 )
{
F_4 ( V_20 , V_13 ) ;
return ( NULL ) ;
}
V_3 = ( T_3 ) F_14 ( V_2 -> V_12 , F_11 ( V_2 -> V_12 ) - 1 ) ;
if( V_3 == NULL )
{
F_4 ( V_20 , V_17 ) ;
return ( NULL ) ;
}
if ( F_15 ( & V_3 , V_18 , V_21 , & V_19 ) < 0 )
{
F_4 ( V_20 , V_22 ) ;
F_6 ( 4 , L_3 , V_18 , L_2 ,
strerror ( V_11 ) ) ;
return ( NULL ) ;
}
return ( V_19 ) ;
}
static T_4 F_16 ( T_2 * V_2 , const char * V_18 )
{
T_3 V_3 ;
void * V_19 ;
if( ( V_2 == NULL ) || ( V_18 == NULL ) )
{
F_4 ( V_23 , V_16 ) ;
return ( NULL ) ;
}
if( F_11 ( V_2 -> V_12 ) < 1 )
{
F_4 ( V_23 , V_13 ) ;
return ( NULL ) ;
}
V_3 = ( T_3 ) F_14 ( V_2 -> V_12 , F_11 ( V_2 -> V_12 ) - 1 ) ;
if( V_3 == NULL )
{
F_4 ( V_23 , V_17 ) ;
return ( NULL ) ;
}
if ( F_15 ( & V_3 , V_18 , V_21 , & V_19 ) < 0 )
{
F_4 ( V_23 , V_22 ) ;
F_6 ( 4 , L_3 , V_18 , L_2 ,
strerror ( V_11 ) ) ;
return ( NULL ) ;
}
return ( ( T_4 ) V_19 ) ;
}
static char * F_17 ( T_2 * V_2 , const char * V_4 )
{
char * V_24 ;
int V_25 , V_26 , V_27 ;
V_25 = strlen ( V_4 ) ;
V_26 = V_25 + 1 ;
V_27 = ( strstr ( V_4 , L_4 ) == NULL ) ;
{
V_26 += strlen ( V_28 ) ;
if ( ( F_18 ( V_2 ) & V_29 ) == 0 )
V_26 += 3 ;
}
V_24 = F_19 ( V_26 ) ;
if( V_24 == NULL )
{
F_4 ( V_30 ,
V_31 ) ;
return ( NULL ) ;
}
if( V_27 )
{
if ( ( F_18 ( V_2 ) & V_29 ) == 0 )
sprintf ( V_24 , L_5 , V_4 , V_28 ) ;
else
sprintf ( V_24 , L_6 , V_4 , V_28 ) ;
}
else
sprintf ( V_24 , L_7 , V_4 ) ;
return ( V_24 ) ;
}
