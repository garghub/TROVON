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
T_3 * V_5 ;
const char * V_6 , * V_7 ;
if( V_4 == NULL )
{
F_4 ( V_8 , V_9 ) ;
goto V_10;
}
V_6 = strrchr ( V_4 , ']' ) ;
V_7 = strrchr ( V_4 , '>' ) ;
if ( V_6 == NULL ) V_6 = V_7 ;
if ( V_7 != NULL && V_7 > V_6 ) V_6 = V_7 ;
if ( V_6 == NULL ) V_6 = strrchr ( V_4 , ':' ) ;
if ( V_6 == NULL )
V_6 = V_4 ;
else
V_6 ++ ;
V_7 = strchr ( V_6 , '.' ) ;
if ( V_7 == NULL ) V_7 = strchr ( V_6 , ';' ) ;
if ( V_7 == NULL ) V_7 = V_6 + strlen ( V_6 ) ;
if ( V_7 - V_6 > V_11
|| ( V_6 - V_4 ) + strlen ( V_7 ) > V_11 )
{
F_4 ( V_12 , V_13 ) ;
goto V_10;
}
V_5 = ( T_3 * ) F_5 ( sizeof( T_3 ) ) ;
if( V_5 == NULL )
{
F_4 ( V_12 , V_14 ) ;
goto V_10;
}
strncpy ( V_5 -> V_4 , V_6 , V_7 - V_6 ) ;
V_5 -> V_4 [ V_7 - V_6 ] = '\0' ;
strncpy ( V_5 -> V_15 , V_4 , V_6 - V_4 ) ;
V_5 -> V_15 [ V_6 - V_4 ] = '\0' ;
strcat ( V_5 -> V_15 , V_7 ) ;
V_5 -> V_16 . V_17 = strlen ( V_5 -> V_4 ) ;
V_5 -> V_16 . V_18 = V_19 ;
V_5 -> V_16 . V_20 = V_21 ;
V_5 -> V_16 . V_22 = V_5 -> V_4 ;
V_5 -> V_23 . V_17 = strlen ( V_5 -> V_15 ) ;
V_5 -> V_23 . V_18 = V_19 ;
V_5 -> V_23 . V_20 = V_21 ;
V_5 -> V_23 . V_22 = V_5 -> V_15 ;
if( ! F_6 ( V_2 -> V_24 , ( char * ) V_5 ) )
{
F_4 ( V_12 , V_25 ) ;
goto V_10;
}
V_2 -> V_26 = V_4 ;
return ( 1 ) ;
V_10:
if( V_5 != NULL )
F_7 ( V_5 ) ;
if( V_4 != NULL )
F_7 ( V_4 ) ;
return ( 0 ) ;
}
static int F_8 ( T_2 * V_2 )
{
T_3 * V_5 ;
if( V_2 == NULL )
{
F_4 ( V_27 , V_28 ) ;
return ( 0 ) ;
}
if( F_9 ( V_2 -> V_24 ) < 1 )
return ( 1 ) ;
V_5 = ( T_3 * ) F_10 ( V_2 -> V_24 ) ;
if( V_5 == NULL )
{
F_4 ( V_27 , V_29 ) ;
return ( 0 ) ;
}
F_7 ( V_5 ) ;
return ( 1 ) ;
}
static int F_11 ( T_3 * V_3 ,
struct V_30 * V_31 , void * * V_32 ,
unsigned long V_33 )
{
F_12 ( V_34 ) ;
if( V_3 -> V_23 . V_17 )
return F_13 ( & V_3 -> V_16 ,
V_31 , V_32 ,
& V_3 -> V_23 , V_33 ) ;
else
return F_13 ( & V_3 -> V_16 ,
V_31 , V_32 ,
0 , V_33 ) ;
}
void F_14 ( T_2 * V_2 , const char * V_35 , void * * V_32 )
{
T_3 * V_3 ;
int V_36 ;
#if 0
int flags = (1<<4);
#else
int V_33 = 0 ;
#endif
struct V_30 V_31 ;
* V_32 = NULL ;
V_31 . V_17 = strlen ( V_35 ) ;
V_31 . V_18 = V_19 ;
V_31 . V_20 = V_21 ;
V_31 . V_22 = ( char * ) V_35 ;
if( ( V_2 == NULL ) || ( V_35 == NULL ) )
{
F_4 ( V_37 , V_28 ) ;
return;
}
if( F_9 ( V_2 -> V_24 ) < 1 )
{
F_4 ( V_37 , V_25 ) ;
return;
}
V_3 = ( T_3 * ) F_15 ( V_2 -> V_24 ,
F_9 ( V_2 -> V_24 ) - 1 ) ;
if( V_3 == NULL )
{
F_4 ( V_37 , V_29 ) ;
return;
}
if( V_2 -> V_33 & V_38 ) V_33 = 0 ;
V_36 = F_11 ( V_3 , & V_31 , V_32 , V_33 ) ;
if( ! F_16 ( V_36 ) )
{
unsigned short V_39 ;
char V_40 [ 257 ] ;
struct V_30 V_41 ;
V_41 . V_17 = sizeof( V_40 ) ;
V_41 . V_18 = V_19 ;
V_41 . V_20 = V_21 ;
V_41 . V_22 = V_40 ;
* V_32 = NULL ;
V_36 = F_17 ( V_36 , & V_39 , & V_41 , 1 , 0 ) ;
if ( ! F_16 ( V_36 ) )
F_18 ( V_36 ) ;
else
{
V_40 [ V_39 ] = '\0' ;
F_4 ( V_37 , V_42 ) ;
if ( V_3 -> V_23 . V_17 )
F_19 ( 9 ,
L_1 , V_35 ,
L_2 , V_3 -> V_4 ,
L_3 , V_3 -> V_15 , L_4 ,
L_5 , V_40 ) ;
else
F_19 ( 6 ,
L_1 , V_35 ,
L_2 , V_3 -> V_4 ,
L_5 , V_40 ) ;
}
return;
}
return;
}
static void * F_20 ( T_2 * V_2 , const char * V_35 )
{
void * V_32 = 0 ;
F_14 ( V_2 , V_35 , & V_32 ) ;
return V_32 ;
}
static T_4 F_21 ( T_2 * V_2 , const char * V_35 )
{
T_4 V_32 = 0 ;
F_14 ( V_2 , V_35 , ( void * * ) & V_32 ) ;
return V_32 ;
}
static char * F_22 ( T_2 * V_2 , const char * V_4 )
{
int V_43 = strlen ( V_4 ) ;
char * V_44 = F_5 ( V_43 + 1 ) ;
strcpy ( V_44 , V_4 ) ;
return ( V_44 ) ;
}
