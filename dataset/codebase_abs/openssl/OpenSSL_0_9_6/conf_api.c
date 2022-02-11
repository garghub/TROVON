T_1 * F_1 ( T_2 * V_1 , char * V_2 )
{
T_1 * V_3 , V_4 ;
if ( ( V_1 == NULL ) || ( V_2 == NULL ) ) return ( NULL ) ;
V_4 . V_5 = NULL ;
V_4 . V_2 = V_2 ;
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
char * F_9 ( T_2 * V_1 , char * V_2 , char * V_5 )
{
T_1 * V_3 , V_4 ;
char * V_9 ;
if ( V_5 == NULL ) return ( NULL ) ;
if ( V_1 != NULL )
{
if ( V_2 != NULL )
{
V_4 . V_5 = V_5 ;
V_4 . V_2 = V_2 ;
V_3 = ( T_1 * ) F_2 ( V_1 -> V_6 , & V_4 ) ;
if ( V_3 != NULL ) return ( V_3 -> V_7 ) ;
if ( strcmp ( V_2 , L_1 ) == 0 )
{
V_9 = Getenv ( V_5 ) ;
if ( V_9 != NULL ) return ( V_9 ) ;
}
}
V_4 . V_2 = L_2 ;
V_4 . V_5 = V_5 ;
V_3 = ( T_1 * ) F_2 ( V_1 -> V_6 , & V_4 ) ;
if ( V_3 != NULL )
return ( V_3 -> V_7 ) ;
else
return ( NULL ) ;
}
else
return ( Getenv ( V_5 ) ) ;
}
long F_10 ( T_2 * V_1 , char * V_2 , char * V_5 )
{
char * V_10 ;
long V_11 = 0 ;
V_10 = F_9 ( V_1 , V_2 , V_5 ) ;
if ( V_10 == NULL ) return ( 0 ) ;
for (; ; )
{
if ( V_1 -> V_12 -> V_13 ( V_1 , * V_10 ) )
V_11 = V_11 * 10 + V_1 -> V_12 -> V_14 ( V_1 , * V_10 ) ;
else
return ( V_11 ) ;
V_10 ++ ;
}
}
int F_11 ( T_2 * V_1 )
{
if ( V_1 == NULL )
{
return 0 ;
}
if ( V_1 -> V_6 == NULL )
if ( ( V_1 -> V_6 = F_12 ( V_15 , V_16 ) ) == NULL )
{
return 0 ;
}
return 1 ;
}
void F_13 ( T_2 * V_1 )
{
if ( V_1 == NULL || V_1 -> V_6 == NULL ) return;
V_1 -> V_6 -> V_17 = 0 ;
F_14 ( V_1 -> V_6 , ( void ( * ) () ) V_18 , V_1 -> V_6 ) ;
F_14 ( V_1 -> V_6 , ( void ( * ) () ) V_19 , V_1 -> V_6 ) ;
F_15 ( V_1 -> V_6 ) ;
}
static void V_18 ( T_1 * V_20 , T_3 * V_1 )
{
if ( V_20 -> V_5 != NULL )
{
V_20 = ( T_1 * ) F_16 ( V_1 , V_20 ) ;
}
}
static void V_19 ( T_1 * V_20 , T_3 * V_1 )
{
T_1 * V_4 ;
T_4 * V_21 ;
int V_22 ;
if ( V_20 -> V_5 != NULL ) return;
V_21 = ( T_4 * ) V_20 -> V_7 ;
for ( V_22 = F_17 ( V_21 ) - 1 ; V_22 >= 0 ; V_22 -- )
{
V_4 = ( T_1 * ) F_18 ( V_21 , V_22 ) ;
F_8 ( V_4 -> V_7 ) ;
F_8 ( V_4 -> V_5 ) ;
F_8 ( V_4 ) ;
}
if ( V_21 != NULL ) F_19 ( V_21 ) ;
F_8 ( V_20 -> V_2 ) ;
F_8 ( V_20 ) ;
}
static unsigned long V_15 ( T_1 * V_3 )
{
return ( ( F_20 ( V_3 -> V_2 ) << 2 ) ^ F_20 ( V_3 -> V_5 ) ) ;
}
static int V_16 ( T_1 * V_20 , T_1 * V_23 )
{
int V_22 ;
if ( V_20 -> V_2 != V_23 -> V_2 )
{
V_22 = strcmp ( V_20 -> V_2 , V_23 -> V_2 ) ;
if ( V_22 ) return ( V_22 ) ;
}
if ( ( V_20 -> V_5 != NULL ) && ( V_23 -> V_5 != NULL ) )
{
V_22 = strcmp ( V_20 -> V_5 , V_23 -> V_5 ) ;
return ( V_22 ) ;
}
else if ( V_20 -> V_5 == V_23 -> V_5 )
return ( 0 ) ;
else
return ( ( V_20 -> V_5 == NULL ) ? - 1 : 1 ) ;
}
T_1 * F_21 ( T_2 * V_1 , char * V_2 )
{
T_4 * V_21 = NULL ;
int V_24 = 0 , V_22 ;
T_1 * V_3 = NULL , * V_4 ;
if ( ( V_21 = F_22 () ) == NULL )
goto V_25;
if ( ( V_3 = ( T_1 * ) F_23 ( sizeof( T_1 ) ) ) == NULL )
goto V_25;
V_22 = strlen ( V_2 ) + 1 ;
if ( ( V_3 -> V_2 = ( char * ) F_23 ( V_22 ) ) == NULL )
goto V_25;
memcpy ( V_3 -> V_2 , V_2 , V_22 ) ;
V_3 -> V_5 = NULL ;
V_3 -> V_7 = ( char * ) V_21 ;
V_4 = ( T_1 * ) F_6 ( V_1 -> V_6 , V_3 ) ;
assert ( V_4 == NULL ) ;
V_24 = 1 ;
V_25:
if ( ! V_24 )
{
if ( V_21 != NULL ) F_19 ( V_21 ) ;
if ( V_3 != NULL ) F_8 ( V_3 ) ;
V_3 = NULL ;
}
return ( V_3 ) ;
}
