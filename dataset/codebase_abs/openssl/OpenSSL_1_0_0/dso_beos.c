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
T_3 V_3 ;
char * V_4 = F_3 ( V_2 , NULL ) ;
if( V_4 == NULL )
{
F_4 ( V_5 , V_6 ) ;
goto V_7;
}
V_3 = F_5 ( V_4 ) ;
if( V_3 < 1 )
{
F_4 ( V_5 , V_8 ) ;
F_6 ( 3 , L_1 , V_4 , L_2 ) ;
goto V_7;
}
if( ! F_7 ( V_2 -> V_9 , ( char * ) V_3 ) )
{
F_4 ( V_5 , V_10 ) ;
goto V_7;
}
V_2 -> V_11 = V_4 ;
return ( 1 ) ;
V_7:
if( V_4 != NULL )
F_8 ( V_4 ) ;
if( V_3 > 0 )
F_9 ( V_3 ) ;
return ( 0 ) ;
}
static int F_10 ( T_2 * V_2 )
{
T_3 V_3 ;
if( V_2 == NULL )
{
F_4 ( V_12 , V_13 ) ;
return ( 0 ) ;
}
if( F_11 ( V_2 -> V_9 ) < 1 )
return ( 1 ) ;
V_3 = ( T_3 ) F_12 ( V_2 -> V_9 ) ;
if( V_3 < 1 )
{
F_4 ( V_12 , V_14 ) ;
return ( 0 ) ;
}
if( F_9 ( V_3 ) != V_15 )
{
F_4 ( V_12 , V_16 ) ;
F_7 ( V_2 -> V_9 , ( char * ) V_3 ) ;
return ( 0 ) ;
}
return ( 1 ) ;
}
static void * F_13 ( T_2 * V_2 , const char * V_17 )
{
T_3 V_3 ;
void * V_18 ;
if( ( V_2 == NULL ) || ( V_17 == NULL ) )
{
F_4 ( V_19 , V_13 ) ;
return ( NULL ) ;
}
if( F_11 ( V_2 -> V_9 ) < 1 )
{
F_4 ( V_19 , V_10 ) ;
return ( NULL ) ;
}
V_3 = ( T_3 ) F_14 ( V_2 -> V_9 , F_11 ( V_2 -> V_9 ) - 1 ) ;
if( V_3 < 1 )
{
F_4 ( V_19 , V_14 ) ;
return ( NULL ) ;
}
if( F_15 ( V_3 , V_17 , V_20 , & V_18 ) != V_15 )
{
F_4 ( V_19 , V_21 ) ;
F_6 ( 3 , L_3 , V_17 , L_2 ) ;
return ( NULL ) ;
}
return ( V_18 ) ;
}
static T_4 F_16 ( T_2 * V_2 , const char * V_17 )
{
T_3 V_3 ;
void * V_18 ;
if( ( V_2 == NULL ) || ( V_17 == NULL ) )
{
F_4 ( V_22 , V_13 ) ;
return ( NULL ) ;
}
if( F_11 ( V_2 -> V_9 ) < 1 )
{
F_4 ( V_22 , V_10 ) ;
return ( NULL ) ;
}
V_3 = ( T_3 ) F_14 ( V_2 -> V_9 , F_11 ( V_2 -> V_9 ) - 1 ) ;
if( V_3 < 1 )
{
F_4 ( V_22 , V_14 ) ;
return ( NULL ) ;
}
if( F_15 ( V_3 , V_17 , V_23 , & V_18 ) != V_15 )
{
F_4 ( V_22 , V_21 ) ;
F_6 ( 3 , L_3 , V_17 , L_2 ) ;
return ( NULL ) ;
}
return ( ( T_4 ) V_18 ) ;
}
static char * F_17 ( T_2 * V_2 , const char * V_4 )
{
char * V_24 ;
int V_25 , V_26 , V_27 ;
V_25 = strlen ( V_4 ) ;
V_26 = V_25 + 1 ;
V_27 = ( strstr ( V_4 , L_4 ) == NULL ) ;
if( V_27 )
{
V_26 += 3 ;
if ( ( F_18 ( V_2 ) & V_28 ) == 0 )
V_26 += 3 ;
}
V_24 = F_19 ( V_26 ) ;
if( V_24 == NULL )
{
F_4 ( V_29 ,
V_30 ) ;
return ( NULL ) ;
}
if( V_27 )
{
if ( ( F_18 ( V_2 ) & V_28 ) == 0 )
sprintf ( V_24 , L_5 , V_4 ) ;
else
sprintf ( V_24 , L_6 , V_4 ) ;
}
else
sprintf ( V_24 , L_7 , V_4 ) ;
return ( V_24 ) ;
}
