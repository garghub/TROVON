T_1 * F_1 ( const T_2 * V_1 , const char * V_2 )
{
T_1 * V_3 , V_4 ;
if ( ( V_1 == NULL ) || ( V_2 == NULL ) ) return ( NULL ) ;
V_4 . V_5 = NULL ;
V_4 . V_2 = ( char * ) V_2 ;
V_3 = ( T_1 * ) F_2 ( V_1 -> V_6 , & V_4 ) ;
return ( V_3 ) ;
}
int F_3 ( T_2 * V_1 , T_1 * V_2 , T_1 * V_7 )
{
T_1 * V_3 = NULL ;
F_4 ( T_1 ) * V_8 ;
V_8 = ( F_4 ( T_1 ) * ) V_2 -> V_7 ;
V_7 -> V_2 = V_2 -> V_2 ;
if ( ! F_5 ( V_8 , V_7 ) )
{
return 0 ;
}
V_3 = ( T_1 * ) F_6 ( V_1 -> V_6 , V_7 ) ;
if ( V_3 != NULL )
{
F_7 ( V_8 , V_3 ) ;
F_8 ( V_3 -> V_5 ) ;
F_8 ( V_3 -> V_7 ) ;
F_8 ( V_3 ) ;
}
return 1 ;
}
char * F_9 ( const T_2 * V_1 , const char * V_2 , const char * V_5 )
{
T_1 * V_3 , V_4 ;
char * V_9 ;
if ( V_5 == NULL ) return ( NULL ) ;
if ( V_1 != NULL )
{
if ( V_2 != NULL )
{
V_4 . V_5 = ( char * ) V_5 ;
V_4 . V_2 = ( char * ) V_2 ;
V_3 = ( T_1 * ) F_2 ( V_1 -> V_6 , & V_4 ) ;
if ( V_3 != NULL ) return ( V_3 -> V_7 ) ;
if ( strcmp ( V_2 , L_1 ) == 0 )
{
V_9 = Getenv ( V_5 ) ;
if ( V_9 != NULL ) return ( V_9 ) ;
}
}
V_4 . V_2 = L_2 ;
V_4 . V_5 = ( char * ) V_5 ;
V_3 = ( T_1 * ) F_2 ( V_1 -> V_6 , & V_4 ) ;
if ( V_3 != NULL )
return ( V_3 -> V_7 ) ;
else
return ( NULL ) ;
}
else
return ( Getenv ( V_5 ) ) ;
}
int F_10 ( T_2 * V_1 )
{
if ( V_1 == NULL )
{
return 0 ;
}
if ( V_1 -> V_6 == NULL )
if ( ( V_1 -> V_6 = F_11 ( V_10 , V_11 ) ) == NULL )
{
return 0 ;
}
return 1 ;
}
void F_12 ( T_2 * V_1 )
{
if ( V_1 == NULL || V_1 -> V_6 == NULL ) return;
V_1 -> V_6 -> V_12 = 0 ;
F_13 ( V_1 -> V_6 , F_14 ( V_13 ) ,
V_1 -> V_6 ) ;
F_13 ( V_1 -> V_6 , F_14 ( V_14 ) ,
V_1 -> V_6 ) ;
F_15 ( V_1 -> V_6 ) ;
}
static void V_13 ( T_1 * V_15 , T_3 * V_1 )
{
if ( V_15 -> V_5 != NULL )
{
V_15 = ( T_1 * ) F_16 ( V_1 , V_15 ) ;
}
}
static void V_14 ( T_1 * V_15 , T_3 * V_1 )
{
T_1 * V_4 ;
T_4 * V_16 ;
int V_17 ;
if ( V_15 -> V_5 != NULL ) return;
V_16 = ( T_4 * ) V_15 -> V_7 ;
for ( V_17 = F_17 ( V_16 ) - 1 ; V_17 >= 0 ; V_17 -- )
{
V_4 = ( T_1 * ) F_18 ( V_16 , V_17 ) ;
F_8 ( V_4 -> V_7 ) ;
F_8 ( V_4 -> V_5 ) ;
F_8 ( V_4 ) ;
}
if ( V_16 != NULL ) F_19 ( V_16 ) ;
F_8 ( V_15 -> V_2 ) ;
F_8 ( V_15 ) ;
}
static unsigned long V_10 ( const void * V_18 )
{
T_1 * V_3 = ( T_1 * ) V_18 ;
return ( ( F_20 ( V_3 -> V_2 ) << 2 ) ^ F_20 ( V_3 -> V_5 ) ) ;
}
static int V_11 ( const void * V_19 , const void * V_20 )
{
int V_17 ;
T_1 * V_15 = ( T_1 * ) V_19 ;
T_1 * V_21 = ( T_1 * ) V_20 ;
if ( V_15 -> V_2 != V_21 -> V_2 )
{
V_17 = strcmp ( V_15 -> V_2 , V_21 -> V_2 ) ;
if ( V_17 ) return ( V_17 ) ;
}
if ( ( V_15 -> V_5 != NULL ) && ( V_21 -> V_5 != NULL ) )
{
V_17 = strcmp ( V_15 -> V_5 , V_21 -> V_5 ) ;
return ( V_17 ) ;
}
else if ( V_15 -> V_5 == V_21 -> V_5 )
return ( 0 ) ;
else
return ( ( V_15 -> V_5 == NULL ) ? - 1 : 1 ) ;
}
T_1 * F_21 ( T_2 * V_1 , const char * V_2 )
{
T_4 * V_16 = NULL ;
int V_22 = 0 , V_17 ;
T_1 * V_3 = NULL , * V_4 ;
if ( ( V_16 = F_22 () ) == NULL )
goto V_23;
if ( ( V_3 = ( T_1 * ) F_23 ( sizeof( T_1 ) ) ) == NULL )
goto V_23;
V_17 = strlen ( V_2 ) + 1 ;
if ( ( V_3 -> V_2 = ( char * ) F_23 ( V_17 ) ) == NULL )
goto V_23;
memcpy ( V_3 -> V_2 , V_2 , V_17 ) ;
V_3 -> V_5 = NULL ;
V_3 -> V_7 = ( char * ) V_16 ;
V_4 = ( T_1 * ) F_6 ( V_1 -> V_6 , V_3 ) ;
assert ( V_4 == NULL ) ;
V_22 = 1 ;
V_23:
if ( ! V_22 )
{
if ( V_16 != NULL ) F_19 ( V_16 ) ;
if ( V_3 != NULL ) F_8 ( V_3 ) ;
V_3 = NULL ;
}
return ( V_3 ) ;
}
