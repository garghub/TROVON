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
int V_5 = V_6 ;
if( V_4 == NULL )
{
F_4 ( V_7 , V_8 ) ;
goto V_9;
}
#ifdef F_5
if ( V_2 -> V_5 & V_10 )
V_5 |= F_5 ;
#endif
V_3 = F_6 ( V_4 , V_5 ) ;
if( V_3 == NULL )
{
F_4 ( V_7 , V_11 ) ;
F_7 ( 4 , L_1 , V_4 , L_2 , F_8 () ) ;
goto V_9;
}
if( ! F_9 ( V_2 -> V_12 , ( char * ) V_3 ) )
{
F_4 ( V_7 , V_13 ) ;
goto V_9;
}
V_2 -> V_14 = V_4 ;
return ( 1 ) ;
V_9:
if( V_4 != NULL )
F_10 ( V_4 ) ;
if( V_3 != NULL )
F_11 ( V_3 ) ;
return ( 0 ) ;
}
static int F_12 ( T_2 * V_2 )
{
void * V_3 ;
if( V_2 == NULL )
{
F_4 ( V_15 , V_16 ) ;
return ( 0 ) ;
}
if( F_13 ( V_2 -> V_12 ) < 1 )
return ( 1 ) ;
V_3 = ( void * ) F_14 ( V_2 -> V_12 ) ;
if( V_3 == NULL )
{
F_4 ( V_15 , V_17 ) ;
F_9 ( V_2 -> V_12 , ( char * ) V_3 ) ;
return ( 0 ) ;
}
F_11 ( V_3 ) ;
return ( 1 ) ;
}
static void * F_15 ( T_2 * V_2 , const char * V_18 )
{
void * V_3 , * V_19 ;
if( ( V_2 == NULL ) || ( V_18 == NULL ) )
{
F_4 ( V_20 , V_16 ) ;
return ( NULL ) ;
}
if( F_13 ( V_2 -> V_12 ) < 1 )
{
F_4 ( V_20 , V_13 ) ;
return ( NULL ) ;
}
V_3 = ( void * ) F_16 ( V_2 -> V_12 , F_13 ( V_2 -> V_12 ) - 1 ) ;
if( V_3 == NULL )
{
F_4 ( V_20 , V_17 ) ;
return ( NULL ) ;
}
V_19 = F_17 ( V_3 , V_18 ) ;
if( V_19 == NULL )
{
F_4 ( V_20 , V_21 ) ;
F_7 ( 4 , L_3 , V_18 , L_2 , F_8 () ) ;
return ( NULL ) ;
}
return ( V_19 ) ;
}
static T_3 F_18 ( T_2 * V_2 , const char * V_18 )
{
void * V_3 ;
T_3 V_19 , * V_22 = & V_19 ;
if( ( V_2 == NULL ) || ( V_18 == NULL ) )
{
F_4 ( V_23 , V_16 ) ;
return ( NULL ) ;
}
if( F_13 ( V_2 -> V_12 ) < 1 )
{
F_4 ( V_23 , V_13 ) ;
return ( NULL ) ;
}
V_3 = ( void * ) F_16 ( V_2 -> V_12 , F_13 ( V_2 -> V_12 ) - 1 ) ;
if( V_3 == NULL )
{
F_4 ( V_23 , V_17 ) ;
return ( NULL ) ;
}
* ( void * * ) ( V_22 ) = F_17 ( V_3 , V_18 ) ;
if( V_19 == NULL )
{
F_4 ( V_23 , V_21 ) ;
F_7 ( 4 , L_3 , V_18 , L_2 , F_8 () ) ;
return ( NULL ) ;
}
return ( V_19 ) ;
}
static char * F_19 ( T_2 * V_2 , const char * V_24 ,
const char * V_25 )
{
char * V_26 ;
if( ! V_24 && ! V_25 )
{
F_4 ( V_27 ,
V_16 ) ;
return ( NULL ) ;
}
if ( ! V_25 || V_24 [ 0 ] == '/' )
{
V_26 = F_20 ( strlen ( V_24 ) + 1 ) ;
if( ! V_26 )
{
F_4 ( V_27 ,
V_28 ) ;
return ( NULL ) ;
}
strcpy ( V_26 , V_24 ) ;
}
else if ( ! V_24 )
{
V_26 = F_20 ( strlen ( V_25 ) + 1 ) ;
if( ! V_26 )
{
F_4 ( V_27 ,
V_28 ) ;
return ( NULL ) ;
}
strcpy ( V_26 , V_25 ) ;
}
else
{
int V_29 , V_30 ;
V_29 = ( V_25 ? strlen ( V_25 ) : 0 ) ;
V_30 = V_29 + ( V_24 ? strlen ( V_24 ) : 0 ) ;
if( V_25 && V_25 [ V_29 - 1 ] == '/' )
{
V_29 -- ;
V_30 -- ;
}
V_26 = F_20 ( V_30 + 2 ) ;
if( ! V_26 )
{
F_4 ( V_27 ,
V_28 ) ;
return ( NULL ) ;
}
strcpy ( V_26 , V_25 ) ;
V_26 [ V_29 ] = '/' ;
strcpy ( & V_26 [ V_29 + 1 ] , V_24 ) ;
}
return ( V_26 ) ;
}
static char * F_21 ( T_2 * V_2 , const char * V_4 )
{
char * V_31 ;
int V_30 , V_32 , V_33 ;
V_30 = strlen ( V_4 ) ;
V_32 = V_30 + 1 ;
V_33 = ( strstr ( V_4 , L_4 ) == NULL ) ;
if( V_33 )
{
V_32 += 3 ;
if ( ( F_22 ( V_2 ) & V_34 ) == 0 )
V_32 += 3 ;
}
V_31 = F_20 ( V_32 ) ;
if( V_31 == NULL )
{
F_4 ( V_35 ,
V_36 ) ;
return ( NULL ) ;
}
if( V_33 )
{
if ( ( F_22 ( V_2 ) & V_34 ) == 0 )
sprintf ( V_31 , L_5 , V_4 ) ;
else
sprintf ( V_31 , L_6 , V_4 ) ;
}
else
sprintf ( V_31 , L_7 , V_4 ) ;
return ( V_31 ) ;
}
