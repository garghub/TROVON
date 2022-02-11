T_1 * F_1 ( T_1 * V_1 , const char * V_2 , long * line )
{
T_1 * V_3 ;
T_2 * V_4 = NULL ;
#ifdef F_2
V_4 = F_3 ( V_2 , L_1 ) ;
#else
V_4 = F_3 ( V_2 , L_2 ) ;
#endif
if ( V_4 == NULL )
{
F_4 ( V_5 , V_6 ) ;
return NULL ;
}
V_3 = F_5 ( V_1 , V_4 , line ) ;
F_6 ( V_4 ) ;
return V_3 ;
}
T_1 * F_7 ( T_1 * V_1 , T_3 * V_4 , long * line )
{
T_2 * V_7 ;
T_1 * V_3 ;
if( ! ( V_7 = F_8 ( V_4 , V_8 ) ) ) {
F_4 ( V_9 , V_10 ) ;
return NULL ;
}
V_3 = F_5 ( V_1 , V_7 , line ) ;
F_6 ( V_7 ) ;
return V_3 ;
}
T_1 * F_5 ( T_1 * V_1 , T_2 * V_4 , long * line )
{
T_1 * V_11 = NULL ;
#define F_9 512
char V_7 [ 16 ] ;
int V_12 = 0 , V_13 , V_14 ;
T_4 * V_15 = NULL ;
char * V_16 , * V_17 , * V_18 ;
int V_19 , V_20 ;
long V_21 = 0 ;
T_5 * V_22 = NULL , * V_23 , * V_24 ;
T_5 * V_25 = NULL ;
char * V_26 = NULL , * V_27 ;
F_10 ( T_5 ) * V_28 = NULL , * V_29 ;
char * V_30 , * V_31 , * V_32 ;
if ( ( V_15 = F_11 () ) == NULL )
{
F_4 ( V_33 , V_10 ) ;
goto V_34;
}
V_26 = ( char * ) Malloc ( 10 ) ;
if ( V_26 == NULL )
{
F_4 ( V_33 , V_35 ) ;
goto V_34;
}
strcpy ( V_26 , L_3 ) ;
if ( V_1 == NULL )
{
if ( ( V_11 = F_12 ( V_36 , V_37 ) ) == NULL )
{
F_4 ( V_33 , V_35 ) ;
goto V_34;
}
}
else
V_11 = V_1 ;
V_25 = F_13 ( V_11 , V_26 ) ;
if ( V_25 == NULL )
{
F_4 ( V_33 ,
V_38 ) ;
goto V_34;
}
V_28 = ( F_10 ( T_5 ) * ) V_25 -> V_39 ;
V_12 = 0 ;
for (; ; )
{
V_19 = 0 ;
if ( ! F_14 ( V_15 , V_12 + F_9 ) )
{
F_4 ( V_33 , V_10 ) ;
goto V_34;
}
V_17 = & ( V_15 -> V_40 [ V_12 ] ) ;
* V_17 = '\0' ;
F_15 ( V_4 , V_17 , F_9 - 1 ) ;
V_17 [ F_9 - 1 ] = '\0' ;
V_14 = V_13 = strlen ( V_17 ) ;
if ( V_13 == 0 ) break;
while ( V_13 > 0 )
{
if ( ( V_17 [ V_13 - 1 ] != '\r' ) && ( V_17 [ V_13 - 1 ] != '\n' ) )
break;
else
V_13 -- ;
}
if ( V_13 == V_14 )
V_19 = 1 ;
else
{
V_17 [ V_13 ] = '\0' ;
V_21 ++ ;
}
V_12 += V_13 ;
V_22 = NULL ;
if ( V_12 >= 1 )
{
V_17 = & ( V_15 -> V_40 [ V_12 - 1 ] ) ;
if ( F_16 ( V_17 [ 0 ] ) &&
( ( V_12 <= 1 ) || ! F_16 ( V_17 [ - 1 ] ) ) )
{
V_12 -- ;
V_19 = 1 ;
}
}
if ( V_19 ) continue;
V_12 = 0 ;
V_27 = V_15 -> V_40 ;
F_17 ( V_27 ) ;
V_20 = strlen ( V_27 ) ;
V_16 = F_18 ( V_27 ) ;
if ( F_19 ( * V_16 ) ) continue;
if ( * V_16 == '[' )
{
char * V_41 ;
V_16 ++ ;
V_30 = F_18 ( V_16 ) ;
V_41 = V_30 ;
V_19:
V_18 = F_20 ( V_41 ) ;
V_17 = F_18 ( V_18 ) ;
if ( * V_17 != ']' )
{
if ( * V_17 != '\0' )
{
V_41 = V_17 ;
goto V_19;
}
F_4 ( V_33 ,
V_42 ) ;
goto V_34;
}
* V_18 = '\0' ;
if ( ! F_21 ( V_11 , NULL , & V_26 , V_30 ) ) goto V_34;
if ( ( V_25 = F_22 ( V_11 , V_26 ) ) == NULL )
V_25 = F_13 ( V_11 , V_26 ) ;
if ( V_25 == NULL )
{
F_4 ( V_33 ,
V_38 ) ;
goto V_34;
}
V_28 = ( F_10 ( T_5 ) * ) V_25 -> V_39 ;
continue;
}
else
{
V_32 = V_16 ;
V_31 = NULL ;
V_18 = F_20 ( V_16 ) ;
if ( ( V_18 [ 0 ] == ':' ) && ( V_18 [ 1 ] == ':' ) )
{
* V_18 = '\0' ;
V_18 += 2 ;
V_31 = V_32 ;
V_32 = V_18 ;
V_18 = F_20 ( V_18 ) ;
}
V_17 = F_18 ( V_18 ) ;
if ( * V_17 != '=' )
{
F_4 ( V_33 ,
V_43 ) ;
goto V_34;
}
* V_18 = '\0' ;
V_17 ++ ;
V_30 = F_18 ( V_17 ) ;
while ( ! F_19 ( * V_17 ) )
V_17 ++ ;
V_17 -- ;
while ( ( V_17 != V_30 ) && ( F_23 ( * V_17 ) ) )
V_17 -- ;
V_17 ++ ;
* V_17 = '\0' ;
if ( ! ( V_22 = ( T_5 * ) Malloc ( sizeof( T_5 ) ) ) )
{
F_4 ( V_33 ,
V_35 ) ;
goto V_34;
}
if ( V_31 == NULL ) V_31 = V_26 ;
V_22 -> V_44 = ( char * ) Malloc ( strlen ( V_32 ) + 1 ) ;
V_22 -> V_39 = NULL ;
if ( V_22 -> V_44 == NULL )
{
F_4 ( V_33 ,
V_35 ) ;
goto V_34;
}
strcpy ( V_22 -> V_44 , V_32 ) ;
if ( ! F_21 ( V_11 , V_31 , & ( V_22 -> V_39 ) , V_30 ) ) goto V_34;
if ( strcmp ( V_31 , V_26 ) != 0 )
{
if ( ( V_24 = F_22 ( V_11 , V_31 ) )
== NULL )
V_24 = F_13 ( V_11 , V_31 ) ;
if ( V_24 == NULL )
{
F_4 ( V_33 ,
V_38 ) ;
goto V_34;
}
V_29 = ( F_10 ( T_5 ) * ) V_24 -> V_39 ;
}
else
{
V_24 = V_25 ;
V_29 = V_28 ;
}
V_22 -> V_26 = V_24 -> V_26 ;
if ( ! F_24 ( V_29 , V_22 ) )
{
F_4 ( V_33 ,
V_35 ) ;
goto V_34;
}
V_23 = ( T_5 * ) F_25 ( V_11 , V_22 ) ;
if ( V_23 != NULL )
{
F_26 ( V_29 , V_23 ) ;
Free ( V_23 -> V_44 ) ;
Free ( V_23 -> V_39 ) ;
Free ( V_23 ) ;
}
V_22 = NULL ;
}
}
if ( V_15 != NULL ) F_27 ( V_15 ) ;
if ( V_26 != NULL ) Free ( V_26 ) ;
return ( V_11 ) ;
V_34:
if ( V_15 != NULL ) F_27 ( V_15 ) ;
if ( V_26 != NULL ) Free ( V_26 ) ;
if ( line != NULL ) * line = V_21 ;
sprintf ( V_7 , L_4 , V_21 ) ;
F_28 ( 2 , L_5 , V_7 ) ;
if ( ( V_1 != V_11 ) && ( V_11 != NULL ) ) F_29 ( V_11 ) ;
if ( V_22 != NULL )
{
if ( V_22 -> V_44 != NULL ) Free ( V_22 -> V_44 ) ;
if ( V_22 -> V_39 != NULL ) Free ( V_22 -> V_39 ) ;
if ( V_22 != NULL ) Free ( V_22 ) ;
}
return ( NULL ) ;
}
char * F_30 ( T_1 * V_45 , char * V_26 , char * V_44 )
{
T_5 * V_22 , V_23 ;
char * V_17 ;
if ( V_44 == NULL ) return ( NULL ) ;
if ( V_45 != NULL )
{
if ( V_26 != NULL )
{
V_23 . V_44 = V_44 ;
V_23 . V_26 = V_26 ;
V_22 = ( T_5 * ) F_31 ( V_45 , & V_23 ) ;
if ( V_22 != NULL ) return ( V_22 -> V_39 ) ;
if ( strcmp ( V_26 , L_6 ) == 0 )
{
V_17 = Getenv ( V_44 ) ;
if ( V_17 != NULL ) return ( V_17 ) ;
}
}
V_23 . V_26 = L_3 ;
V_23 . V_44 = V_44 ;
V_22 = ( T_5 * ) F_31 ( V_45 , & V_23 ) ;
if ( V_22 != NULL )
return ( V_22 -> V_39 ) ;
else
return ( NULL ) ;
}
else
return ( Getenv ( V_44 ) ) ;
}
static T_5 * F_22 ( T_1 * V_45 , char * V_26 )
{
T_5 * V_22 , V_23 ;
if ( ( V_45 == NULL ) || ( V_26 == NULL ) ) return ( NULL ) ;
V_23 . V_44 = NULL ;
V_23 . V_26 = V_26 ;
V_22 = ( T_5 * ) F_31 ( V_45 , & V_23 ) ;
return ( V_22 ) ;
}
long F_32 ( T_1 * V_45 , char * V_26 , char * V_44 )
{
char * V_46 ;
long V_11 = 0 ;
V_46 = F_30 ( V_45 , V_26 , V_44 ) ;
if ( V_46 == NULL ) return ( 0 ) ;
for (; ; )
{
if ( F_33 ( * V_46 ) )
V_11 = V_11 * 10 + ( * V_46 - '0' ) ;
else
return ( V_11 ) ;
V_46 ++ ;
}
}
void F_29 ( T_1 * V_45 )
{
if ( V_45 == NULL ) return;
V_45 -> V_47 = 0 ;
F_34 ( V_45 , ( void ( * ) () ) V_48 , V_45 ) ;
F_34 ( V_45 , ( void ( * ) () ) V_49 , V_45 ) ;
F_35 ( V_45 ) ;
}
static void V_48 ( T_5 * V_50 , T_1 * V_45 )
{
if ( V_50 -> V_44 != NULL )
{
V_50 = ( T_5 * ) F_36 ( V_45 , V_50 ) ;
}
}
static void V_49 ( T_5 * V_50 , T_1 * V_45 )
{
T_5 * V_23 ;
T_6 * V_51 ;
int V_13 ;
if ( V_50 -> V_44 != NULL ) return;
V_51 = ( T_6 * ) V_50 -> V_39 ;
for ( V_13 = F_37 ( V_51 ) - 1 ; V_13 >= 0 ; V_13 -- )
{
V_23 = ( T_5 * ) F_38 ( V_51 , V_13 ) ;
Free ( V_23 -> V_39 ) ;
Free ( V_23 -> V_44 ) ;
Free ( V_23 ) ;
}
if ( V_51 != NULL ) F_39 ( V_51 ) ;
Free ( V_50 -> V_26 ) ;
Free ( V_50 ) ;
}
static void F_17 ( char * V_17 )
{
char * V_52 ;
V_52 = V_17 ;
for (; ; )
{
if ( F_40 ( * V_17 ) )
{
* V_17 = '\0' ;
return;
}
if ( F_41 ( * V_17 ) )
{
V_17 = F_42 ( V_17 ) ;
continue;
}
if ( F_16 ( * V_17 ) )
{
V_17 = F_43 ( V_17 ) ;
continue;
}
if ( F_19 ( * V_17 ) )
return;
else
V_17 ++ ;
}
}
static int F_21 ( T_1 * V_45 , char * V_26 , char * * V_53 , char * V_54 )
{
int V_55 , V_56 , V_57 = 0 , V_52 = 0 , V_58 = 0 ;
char * V_16 , * V_59 , * V_60 , * V_17 , * V_61 , * V_62 , * V_63 , V_22 ;
T_4 * V_27 ;
if ( ( V_27 = F_11 () ) == NULL ) return ( 0 ) ;
V_58 = strlen ( V_54 ) + 1 ;
if ( ! F_14 ( V_27 , V_58 ) ) goto V_34;
for (; ; )
{
if ( F_41 ( * V_54 ) )
{
V_55 = * V_54 ;
V_54 ++ ;
while ( ( * V_54 != '\0' ) && ( * V_54 != V_55 ) )
{
if ( * V_54 == '\\' )
{
V_54 ++ ;
if ( * V_54 == '\0' ) break;
}
V_27 -> V_40 [ V_52 ++ ] = * ( V_54 ++ ) ;
}
}
else if ( * V_54 == '\\' )
{
V_54 ++ ;
V_22 = * ( V_54 ++ ) ;
if ( V_22 == '\0' ) break;
else if ( V_22 == 'r' ) V_22 = '\r' ;
else if ( V_22 == 'n' ) V_22 = '\n' ;
else if ( V_22 == 'b' ) V_22 = '\b' ;
else if ( V_22 == 't' ) V_22 = '\t' ;
V_27 -> V_40 [ V_52 ++ ] = V_22 ;
}
else if ( * V_54 == '\0' )
break;
else if ( * V_54 == '$' )
{
V_61 = NULL ;
V_16 = & ( V_54 [ 1 ] ) ;
if ( * V_16 == '{' )
V_55 = '}' ;
else if ( * V_16 == '(' )
V_55 = ')' ;
else V_55 = 0 ;
if ( V_55 ) V_16 ++ ;
V_63 = V_26 ;
V_59 = V_62 = V_16 ;
while ( F_44 ( * V_59 ) )
V_59 ++ ;
if ( ( V_59 [ 0 ] == ':' ) && ( V_59 [ 1 ] == ':' ) )
{
V_63 = V_62 ;
V_61 = V_59 ;
V_57 = * V_59 ;
* V_61 = '\0' ;
V_59 += 2 ;
V_62 = V_59 ;
while ( F_44 ( * V_59 ) )
V_59 ++ ;
}
V_56 = * V_59 ;
* V_59 = '\0' ;
V_60 = V_59 ;
if ( V_55 )
{
if ( V_56 != V_55 )
{
F_4 ( V_64 , V_65 ) ;
goto V_34;
}
V_59 ++ ;
}
V_17 = F_30 ( V_45 , V_63 , V_62 ) ;
if ( V_61 != NULL ) * V_61 = V_57 ;
* V_60 = V_56 ;
if ( V_17 == NULL )
{
F_4 ( V_64 , V_66 ) ;
goto V_34;
}
F_14 ( V_27 , ( strlen ( V_17 ) + V_58 - ( V_59 - V_54 ) ) ) ;
while ( * V_17 )
V_27 -> V_40 [ V_52 ++ ] = * ( V_17 ++ ) ;
V_54 = V_59 ;
}
else
V_27 -> V_40 [ V_52 ++ ] = * ( V_54 ++ ) ;
}
V_27 -> V_40 [ V_52 ] = '\0' ;
if ( * V_53 != NULL ) Free ( * V_53 ) ;
* V_53 = V_27 -> V_40 ;
Free ( V_27 ) ;
return ( 1 ) ;
V_34:
if ( V_27 != NULL ) F_27 ( V_27 ) ;
return ( 0 ) ;
}
static char * F_18 ( char * V_17 )
{
while ( F_23 ( * V_17 ) && ( ! F_19 ( * V_17 ) ) )
V_17 ++ ;
return ( V_17 ) ;
}
static char * F_20 ( char * V_17 )
{
for (; ; )
{
if ( F_16 ( * V_17 ) )
{
V_17 = F_43 ( V_17 ) ;
continue;
}
if ( ! F_45 ( * V_17 ) )
return ( V_17 ) ;
V_17 ++ ;
}
}
static unsigned long V_36 ( T_5 * V_22 )
{
return ( ( F_46 ( V_22 -> V_26 ) << 2 ) ^ F_46 ( V_22 -> V_44 ) ) ;
}
static int V_37 ( T_5 * V_50 , T_5 * V_67 )
{
int V_13 ;
if ( V_50 -> V_26 != V_67 -> V_26 )
{
V_13 = strcmp ( V_50 -> V_26 , V_67 -> V_26 ) ;
if ( V_13 ) return ( V_13 ) ;
}
if ( ( V_50 -> V_44 != NULL ) && ( V_67 -> V_44 != NULL ) )
{
V_13 = strcmp ( V_50 -> V_44 , V_67 -> V_44 ) ;
return ( V_13 ) ;
}
else if ( V_50 -> V_44 == V_67 -> V_44 )
return ( 0 ) ;
else
return ( ( V_50 -> V_44 == NULL ) ? - 1 : 1 ) ;
}
static char * F_42 ( char * V_17 )
{
int V_55 = * V_17 ;
V_17 ++ ;
while ( ! ( F_19 ( * V_17 ) ) && ( * V_17 != V_55 ) )
{
if ( F_16 ( * V_17 ) )
{
V_17 ++ ;
if ( F_19 ( * V_17 ) ) return ( V_17 ) ;
}
V_17 ++ ;
}
if ( * V_17 == V_55 ) V_17 ++ ;
return ( V_17 ) ;
}
static T_5 * F_13 ( T_1 * V_45 , char * V_26 )
{
T_6 * V_51 = NULL ;
int V_68 = 0 , V_13 ;
T_5 * V_22 = NULL , * V_23 ;
if ( ( V_51 = F_47 () ) == NULL )
goto V_34;
if ( ( V_22 = ( T_5 * ) Malloc ( sizeof( T_5 ) ) ) == NULL )
goto V_34;
V_13 = strlen ( V_26 ) + 1 ;
if ( ( V_22 -> V_26 = ( char * ) Malloc ( V_13 ) ) == NULL )
goto V_34;
memcpy ( V_22 -> V_26 , V_26 , V_13 ) ;
V_22 -> V_44 = NULL ;
V_22 -> V_39 = ( char * ) V_51 ;
V_23 = ( T_5 * ) F_25 ( V_45 , V_22 ) ;
if ( V_23 != NULL )
{
#if ! F_48 ( V_69 ) && ! F_48 ( V_70 )
fprintf ( V_71 , L_7 ) ;
#endif
abort () ;
}
V_68 = 1 ;
V_34:
if ( ! V_68 )
{
if ( V_51 != NULL ) F_39 ( V_51 ) ;
if ( V_22 != NULL ) Free ( V_22 ) ;
V_22 = NULL ;
}
return ( V_22 ) ;
}
