T_1 * F_1 ( void )
{
return ( & V_1 ) ;
}
static int F_2 ( T_2 * V_2 , int V_3 , const char * V_4 , long V_5 ,
char * * V_6 )
{
int V_7 = 0 ;
T_3 * V_8 ;
char * V_9 ;
V_8 = ( T_3 * ) V_2 -> V_10 ;
switch ( V_3 )
{
case V_11 :
if ( V_5 == V_12 )
{
V_7 = F_3 ( V_8 , F_4 () ,
V_13 ) ;
if ( ! V_7 )
{
F_5 ( V_14 , V_15 ) ;
}
else
{
V_9 = ( char * ) Getenv ( F_6 () ) ;
V_7 = F_3 ( V_8 , V_9 , V_13 ) ;
}
}
else
V_7 = F_3 ( V_8 , V_4 , ( int ) V_5 ) ;
break;
}
return ( V_7 ) ;
}
static int F_7 ( T_2 * V_16 )
{
T_3 * V_17 ;
if ( ( V_17 = ( T_3 * ) Malloc ( sizeof( T_3 ) ) ) == NULL )
return ( 0 ) ;
if ( ( V_17 -> V_18 = F_8 () ) == NULL )
{
Free ( V_17 ) ;
return ( 0 ) ;
}
V_17 -> V_19 = 0 ;
V_17 -> V_20 = NULL ;
V_17 -> V_21 = NULL ;
V_17 -> V_22 = 0 ;
V_16 -> V_10 = ( char * ) V_17 ;
return ( 1 ) ;
}
static void F_9 ( T_2 * V_16 )
{
T_3 * V_17 ;
int V_23 ;
V_17 = ( T_3 * ) V_16 -> V_10 ;
for ( V_23 = 0 ; V_23 < V_17 -> V_19 ; V_23 ++ )
if ( V_17 -> V_20 [ V_23 ] != NULL ) Free ( V_17 -> V_20 [ V_23 ] ) ;
if ( V_17 -> V_20 != NULL ) Free ( V_17 -> V_20 ) ;
if ( V_17 -> V_21 != NULL ) Free ( V_17 -> V_21 ) ;
if ( V_17 -> V_18 != NULL ) F_10 ( V_17 -> V_18 ) ;
Free ( V_17 ) ;
}
static int F_3 ( T_3 * V_2 , const char * V_9 , int type )
{
int V_24 , V_25 ;
int * V_26 ;
const char * V_27 , * V_28 , * V_29 ;
char * * V_30 ;
if ( V_9 == NULL || ! * V_9 )
{
F_5 ( V_31 , V_32 ) ;
return 0 ;
}
V_27 = V_9 ;
V_29 = V_27 ;
for (; ; )
{
if ( ( * V_29 == V_33 ) || ( * V_29 == '\0' ) )
{
V_28 = V_27 ;
V_27 = V_29 + 1 ;
V_25 = ( int ) ( V_29 - V_28 ) ;
if ( V_25 == 0 ) continue;
for ( V_24 = 0 ; V_24 < V_2 -> V_19 ; V_24 ++ )
if ( strncmp ( V_2 -> V_20 [ V_24 ] , V_28 , ( unsigned int ) V_25 ) == 0 )
continue;
if ( V_2 -> V_22 < ( V_2 -> V_19 + 1 ) )
{
V_2 -> V_22 += 10 ;
V_30 = ( char * * ) Malloc ( V_2 -> V_22 *
sizeof( char * ) ) ;
V_26 = ( int * ) Malloc ( V_2 -> V_22 *
sizeof( int ) ) ;
if ( ( V_30 == NULL ) || ( V_26 == NULL ) )
{
F_5 ( V_31 , V_34 ) ;
return ( 0 ) ;
}
memcpy ( V_30 , V_2 -> V_20 , ( V_2 -> V_22 - 10 ) *
sizeof( char * ) ) ;
memcpy ( V_26 , V_2 -> V_21 , ( V_2 -> V_22 - 10 ) *
sizeof( int ) ) ;
if ( V_2 -> V_20 != NULL )
Free ( V_2 -> V_20 ) ;
if ( V_2 -> V_21 != NULL )
Free ( V_2 -> V_21 ) ;
V_2 -> V_20 = V_30 ;
V_2 -> V_21 = V_26 ;
}
V_2 -> V_21 [ V_2 -> V_19 ] = type ;
V_2 -> V_20 [ V_2 -> V_19 ] = ( char * ) Malloc ( ( unsigned int ) V_25 + 1 ) ;
if ( V_2 -> V_20 [ V_2 -> V_19 ] == NULL ) return ( 0 ) ;
strncpy ( V_2 -> V_20 [ V_2 -> V_19 ] , V_28 , ( unsigned int ) V_25 ) ;
V_2 -> V_20 [ V_2 -> V_19 ] [ V_25 ] = '\0' ;
V_2 -> V_19 ++ ;
}
if ( * V_29 == '\0' ) break;
V_29 ++ ;
}
return ( 1 ) ;
}
static int F_11 ( T_2 * V_35 , int type , T_4 * V_36 ,
T_5 * V_7 )
{
T_3 * V_2 ;
union {
struct {
T_6 V_37 ;
T_7 V_38 ;
} V_39 ;
struct {
T_8 V_40 ;
T_9 V_41 ;
} V_42 ;
} V_43 ;
int V_44 = 0 ;
int V_23 , V_24 , V_45 ;
unsigned long V_46 ;
T_10 * V_47 = NULL ;
struct V_48 V_49 ;
T_5 V_50 , * V_51 ;
const char * V_52 = L_1 ;
if ( V_36 == NULL ) return ( 0 ) ;
V_50 . type = type ;
if ( type == V_53 )
{
V_43 . V_39 . V_37 . V_54 = & V_43 . V_39 . V_38 ;
V_43 . V_39 . V_38 . V_55 = V_36 ;
V_50 . V_43 . V_39 = & V_43 . V_39 . V_37 ;
V_52 = L_1 ;
}
else if ( type == V_56 )
{
V_43 . V_42 . V_40 . V_42 = & V_43 . V_42 . V_41 ;
V_43 . V_42 . V_41 . V_57 = V_36 ;
V_50 . V_43 . V_42 = & V_43 . V_42 . V_40 ;
V_52 = L_2 ;
}
else
{
F_5 ( V_58 , V_59 ) ;
goto V_60;
}
if ( ( V_47 = F_8 () ) == NULL )
{
F_5 ( V_58 , V_61 ) ;
goto V_60;
}
V_2 = ( T_3 * ) V_35 -> V_10 ;
V_46 = F_12 ( V_36 ) ;
for ( V_23 = 0 ; V_23 < V_2 -> V_19 ; V_23 ++ )
{
V_24 = strlen ( V_2 -> V_20 [ V_23 ] ) + 1 + 8 + 6 + 1 + 1 ;
if ( ! F_13 ( V_47 , V_24 ) )
{
F_5 ( V_58 , V_34 ) ;
goto V_60;
}
V_45 = 0 ;
for (; ; )
{
sprintf ( V_47 -> V_43 , L_3 , V_2 -> V_20 [ V_23 ] , V_46 ,
V_52 , V_45 ) ;
V_45 ++ ;
if ( V_48 ( V_47 -> V_43 , & V_49 ) < 0 )
break;
if ( type == V_53 )
{
if ( ( F_14 ( V_35 , V_47 -> V_43 ,
V_2 -> V_21 [ V_23 ] ) ) == 0 )
break;
}
else if ( type == V_56 )
{
if ( ( F_15 ( V_35 , V_47 -> V_43 ,
V_2 -> V_21 [ V_23 ] ) ) == 0 )
break;
}
}
F_16 ( V_62 ) ;
V_51 = ( T_5 * ) F_17 ( V_35 -> V_63 -> V_64 , & V_50 ) ;
F_18 ( V_62 ) ;
if ( V_51 != NULL )
{
V_44 = 1 ;
V_7 -> type = V_51 -> type ;
memcpy ( & V_7 -> V_43 , & V_51 -> V_43 , sizeof( V_7 -> V_43 ) ) ;
goto V_60;
}
}
V_60:
if ( V_47 != NULL ) F_10 ( V_47 ) ;
return ( V_44 ) ;
}
