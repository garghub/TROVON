T_1 * F_1 ( T_1 * V_1 , char * V_2 , long * line )
{
T_1 * V_3 = NULL ;
T_2 * V_4 = NULL ;
#define F_2 512
char V_5 [ 16 ] ;
int V_6 = 0 , V_7 , V_8 ;
T_3 * V_9 = NULL ;
char * V_10 , * V_11 , * V_12 ;
int V_13 , V_14 ;
long V_15 = 0 ;
T_4 * V_16 = NULL , * V_17 , * V_18 ;
T_4 * V_19 = NULL ;
char * V_20 = NULL , * V_21 ;
T_5 * V_22 = NULL , * V_23 ;
char * V_24 , * V_25 , * V_26 ;
if ( ( V_9 = F_3 () ) == NULL )
{
F_4 ( V_27 , V_28 ) ;
goto V_29;
}
#ifdef F_5
V_4 = fopen ( V_2 , L_1 ) ;
#else
V_4 = fopen ( V_2 , L_2 ) ;
#endif
if ( V_4 == NULL )
{
F_6 ( V_30 , F_7 () ) ;
F_8 ( F_9 ( V_2 ) ,
V_31 | V_32 ) ;
F_4 ( V_27 , V_33 ) ;
goto V_29;
}
V_20 = ( char * ) Malloc ( 10 ) ;
if ( V_20 == NULL )
{
F_4 ( V_27 , V_34 ) ;
goto V_29;
}
strcpy ( V_20 , L_3 ) ;
if ( V_1 == NULL )
{
if ( ( V_3 = F_10 ( V_35 , V_36 ) ) == NULL )
{
F_4 ( V_27 , V_34 ) ;
goto V_29;
}
}
else
V_3 = V_1 ;
V_19 = F_11 ( V_3 , V_20 ) ;
if ( V_19 == NULL )
{
F_4 ( V_27 , V_37 ) ;
goto V_29;
}
V_22 = ( T_5 * ) V_19 -> V_38 ;
V_6 = 0 ;
for (; ; )
{
V_13 = 0 ;
if ( ! F_12 ( V_9 , V_6 + F_2 ) )
{
F_4 ( V_27 , V_28 ) ;
goto V_29;
}
V_11 = & ( V_9 -> V_39 [ V_6 ] ) ;
* V_11 = '\0' ;
fgets ( V_11 , F_2 - 1 , V_4 ) ;
V_11 [ F_2 - 1 ] = '\0' ;
V_8 = V_7 = strlen ( V_11 ) ;
if ( V_7 == 0 ) break;
while ( V_7 > 0 )
{
if ( ( V_11 [ V_7 - 1 ] != '\r' ) && ( V_11 [ V_7 - 1 ] != '\n' ) )
break;
else
V_7 -- ;
}
if ( V_7 == V_8 )
V_13 = 1 ;
else
{
V_11 [ V_7 ] = '\0' ;
V_15 ++ ;
}
V_6 += V_7 ;
V_16 = NULL ;
if ( V_6 >= 1 )
{
V_11 = & ( V_9 -> V_39 [ V_6 - 1 ] ) ;
if ( F_13 ( V_11 [ 0 ] ) &&
( ( V_6 <= 1 ) || ! F_13 ( V_11 [ - 1 ] ) ) )
{
V_6 -- ;
V_13 = 1 ;
}
}
if ( V_13 ) continue;
V_6 = 0 ;
V_21 = V_9 -> V_39 ;
F_14 ( V_21 ) ;
V_14 = strlen ( V_21 ) ;
V_10 = F_15 ( V_21 ) ;
if ( F_16 ( * V_10 ) ) continue;
if ( * V_10 == '[' )
{
char * V_40 ;
V_10 ++ ;
V_24 = F_15 ( V_10 ) ;
V_40 = V_24 ;
V_13:
V_12 = F_17 ( V_40 ) ;
V_11 = F_15 ( V_12 ) ;
if ( * V_11 != ']' )
{
if ( * V_11 != '\0' )
{
V_40 = V_11 ;
goto V_13;
}
F_4 ( V_27 , V_41 ) ;
goto V_29;
}
* V_12 = '\0' ;
if ( ! F_18 ( V_3 , NULL , & V_20 , V_24 ) ) goto V_29;
if ( ( V_19 = F_19 ( V_3 , V_20 ) ) == NULL )
V_19 = F_11 ( V_3 , V_20 ) ;
if ( V_19 == NULL )
{
F_4 ( V_27 , V_37 ) ;
goto V_29;
}
V_22 = ( T_5 * ) V_19 -> V_38 ;
continue;
}
else
{
V_26 = V_10 ;
V_25 = NULL ;
V_12 = F_17 ( V_10 ) ;
if ( ( V_12 [ 0 ] == ':' ) && ( V_12 [ 1 ] == ':' ) )
{
* V_12 = '\0' ;
V_12 += 2 ;
V_25 = V_26 ;
V_26 = V_12 ;
V_12 = F_17 ( V_12 ) ;
}
V_11 = F_15 ( V_12 ) ;
if ( * V_11 != '=' )
{
F_4 ( V_27 , V_42 ) ;
goto V_29;
}
* V_12 = '\0' ;
V_11 ++ ;
V_24 = F_15 ( V_11 ) ;
while ( ! F_16 ( * V_11 ) )
V_11 ++ ;
V_11 -- ;
while ( ( V_11 != V_24 ) && ( F_20 ( * V_11 ) ) )
V_11 -- ;
V_11 ++ ;
* V_11 = '\0' ;
if ( ( V_16 = ( T_4 * ) Malloc ( sizeof( T_4 ) ) ) == NULL )
{
F_4 ( V_27 , V_34 ) ;
goto V_29;
}
if ( V_25 == NULL ) V_25 = V_20 ;
V_16 -> V_43 = ( char * ) Malloc ( strlen ( V_26 ) + 1 ) ;
V_16 -> V_38 = NULL ;
if ( V_16 -> V_43 == NULL )
{
F_4 ( V_27 , V_34 ) ;
goto V_29;
}
strcpy ( V_16 -> V_43 , V_26 ) ;
if ( ! F_18 ( V_3 , V_25 , & ( V_16 -> V_38 ) , V_24 ) ) goto V_29;
if ( strcmp ( V_25 , V_20 ) != 0 )
{
if ( ( V_18 = F_19 ( V_3 , V_25 ) )
== NULL )
V_18 = F_11 ( V_3 , V_25 ) ;
if ( V_18 == NULL )
{
F_4 ( V_27 , V_37 ) ;
goto V_29;
}
V_23 = ( T_5 * ) V_18 -> V_38 ;
}
else
{
V_18 = V_19 ;
V_23 = V_22 ;
}
V_16 -> V_20 = V_18 -> V_20 ;
if ( ! F_21 ( V_23 , ( char * ) V_16 ) )
{
F_4 ( V_27 , V_34 ) ;
goto V_29;
}
V_17 = ( T_4 * ) F_22 ( V_3 , ( char * ) V_16 ) ;
if ( V_17 != NULL )
{
F_23 ( V_23 , ( char * ) V_17 ) ;
Free ( V_17 -> V_43 ) ;
Free ( V_17 -> V_38 ) ;
Free ( V_17 ) ;
}
V_16 = NULL ;
}
}
if ( V_9 != NULL ) F_24 ( V_9 ) ;
if ( V_20 != NULL ) Free ( V_20 ) ;
if ( V_4 != NULL ) fclose ( V_4 ) ;
return ( V_3 ) ;
V_29:
if ( V_9 != NULL ) F_24 ( V_9 ) ;
if ( V_20 != NULL ) Free ( V_20 ) ;
if ( line != NULL ) * line = V_15 ;
sprintf ( V_5 , L_4 , V_15 ) ;
F_25 ( 2 , L_5 , V_5 ) ;
if ( V_4 != NULL ) fclose ( V_4 ) ;
if ( ( V_1 != V_3 ) && ( V_3 != NULL ) ) F_26 ( V_3 ) ;
if ( V_16 != NULL )
{
if ( V_16 -> V_43 != NULL ) Free ( V_16 -> V_43 ) ;
if ( V_16 -> V_38 != NULL ) Free ( V_16 -> V_38 ) ;
if ( V_16 != NULL ) Free ( V_16 ) ;
}
return ( NULL ) ;
}
char * F_27 ( T_1 * V_44 , char * V_20 , char * V_43 )
{
T_4 * V_16 , V_17 ;
char * V_11 ;
if ( V_43 == NULL ) return ( NULL ) ;
if ( V_44 != NULL )
{
if ( V_20 != NULL )
{
V_17 . V_43 = V_43 ;
V_17 . V_20 = V_20 ;
V_16 = ( T_4 * ) F_28 ( V_44 , ( char * ) & V_17 ) ;
if ( V_16 != NULL ) return ( V_16 -> V_38 ) ;
if ( strcmp ( V_20 , L_6 ) == 0 )
{
V_11 = Getenv ( V_43 ) ;
if ( V_11 != NULL ) return ( V_11 ) ;
}
}
V_17 . V_20 = F_9 ( L_3 ) ;
V_17 . V_43 = V_43 ;
V_16 = ( T_4 * ) F_28 ( V_44 , ( char * ) & V_17 ) ;
if ( V_16 != NULL )
return ( V_16 -> V_38 ) ;
else
return ( NULL ) ;
}
else
return ( Getenv ( V_43 ) ) ;
}
static T_4 * F_19 ( T_1 * V_44 , char * V_20 )
{
T_4 * V_16 , V_17 ;
if ( ( V_44 == NULL ) || ( V_20 == NULL ) ) return ( NULL ) ;
V_17 . V_43 = NULL ;
V_17 . V_20 = V_20 ;
V_16 = ( T_4 * ) F_28 ( V_44 , ( char * ) & V_17 ) ;
return ( V_16 ) ;
}
T_5 * F_29 ( T_1 * V_44 , char * V_20 )
{
T_4 * V_16 ;
V_16 = F_19 ( V_44 , V_20 ) ;
if ( V_16 != NULL )
return ( ( T_5 * ) V_16 -> V_38 ) ;
else
return ( NULL ) ;
}
long F_30 ( T_1 * V_44 , char * V_20 , char * V_43 )
{
char * V_45 ;
long V_3 = 0 ;
V_45 = F_27 ( V_44 , V_20 , V_43 ) ;
if ( V_45 == NULL ) return ( 0 ) ;
for (; ; )
{
if ( F_31 ( * V_45 ) )
V_3 = V_3 * 10 + ( * V_45 - '0' ) ;
else
return ( V_3 ) ;
V_45 ++ ;
}
}
void F_26 ( T_1 * V_44 )
{
if ( V_44 == NULL ) return;
V_44 -> V_46 = 0 ;
F_32 ( V_44 , ( void ( * ) () ) V_47 , ( char * ) V_44 ) ;
F_32 ( V_44 , ( void ( * ) () ) V_48 , ( char * ) V_44 ) ;
F_33 ( V_44 ) ;
}
static void V_47 ( T_4 * V_49 , T_1 * V_44 )
{
if ( V_49 -> V_43 != NULL )
{
V_49 = ( T_4 * ) F_34 ( V_44 , ( char * ) V_49 ) ;
}
}
static void V_48 ( T_4 * V_49 , T_1 * V_44 )
{
T_4 * V_17 ;
T_5 * V_50 ;
int V_7 ;
if ( V_49 -> V_43 != NULL ) return;
V_50 = ( T_5 * ) V_49 -> V_38 ;
for ( V_7 = F_35 ( V_50 ) - 1 ; V_7 >= 0 ; V_7 -- )
{
V_17 = ( T_4 * ) F_36 ( V_50 , V_7 ) ;
Free ( V_17 -> V_38 ) ;
Free ( V_17 -> V_43 ) ;
Free ( V_17 ) ;
}
if ( V_50 != NULL ) F_37 ( V_50 ) ;
Free ( V_49 -> V_20 ) ;
Free ( V_49 ) ;
}
static void F_14 ( char * V_11 )
{
char * V_51 ;
V_51 = V_11 ;
for (; ; )
{
if ( F_38 ( * V_11 ) )
{
* V_11 = '\0' ;
return;
}
if ( F_39 ( * V_11 ) )
{
V_11 = F_40 ( V_11 ) ;
continue;
}
if ( F_13 ( * V_11 ) )
{
V_11 = F_41 ( V_11 ) ;
continue;
}
if ( F_16 ( * V_11 ) )
return;
else
V_11 ++ ;
}
}
static int F_18 ( T_1 * V_44 , char * V_20 , char * * V_52 , char * V_53 )
{
int V_54 , V_55 , V_56 = 0 , V_51 = 0 , V_57 = 0 ;
char * V_10 , * V_58 , * V_59 , * V_11 , * V_60 , * V_61 , * V_62 , V_16 ;
T_3 * V_21 ;
if ( ( V_21 = F_3 () ) == NULL ) return ( 0 ) ;
V_57 = strlen ( V_53 ) + 1 ;
if ( ! F_12 ( V_21 , V_57 ) ) goto V_29;
for (; ; )
{
if ( F_39 ( * V_53 ) )
{
V_54 = * V_53 ;
V_53 ++ ;
while ( ( * V_53 != '\0' ) && ( * V_53 != V_54 ) )
{
if ( * V_53 == '\\' )
{
V_53 ++ ;
if ( * V_53 == '\0' ) break;
}
V_21 -> V_39 [ V_51 ++ ] = * ( V_53 ++ ) ;
}
}
else if ( * V_53 == '\\' )
{
V_53 ++ ;
V_16 = * ( V_53 ++ ) ;
if ( V_16 == '\0' ) break;
else if ( V_16 == 'r' ) V_16 = '\r' ;
else if ( V_16 == 'n' ) V_16 = '\n' ;
else if ( V_16 == 'b' ) V_16 = '\b' ;
else if ( V_16 == 't' ) V_16 = '\t' ;
V_21 -> V_39 [ V_51 ++ ] = V_16 ;
}
else if ( * V_53 == '\0' )
break;
else if ( * V_53 == '$' )
{
V_60 = NULL ;
V_10 = & ( V_53 [ 1 ] ) ;
if ( * V_10 == '{' )
V_54 = '}' ;
else if ( * V_10 == '(' )
V_54 = ')' ;
else V_54 = 0 ;
if ( V_54 ) V_10 ++ ;
V_62 = V_20 ;
V_58 = V_61 = V_10 ;
while ( F_42 ( * V_58 ) )
V_58 ++ ;
if ( ( V_58 [ 0 ] == ':' ) && ( V_58 [ 1 ] == ':' ) )
{
V_62 = V_61 ;
V_60 = V_58 ;
V_56 = * V_58 ;
* V_60 = '\0' ;
V_58 += 2 ;
V_61 = V_58 ;
while ( F_42 ( * V_58 ) )
V_58 ++ ;
}
V_55 = * V_58 ;
* V_58 = '\0' ;
V_59 = V_58 ;
if ( V_54 )
{
if ( V_55 != V_54 )
{
F_4 ( V_63 , V_64 ) ;
goto V_29;
}
V_58 ++ ;
}
V_11 = F_27 ( V_44 , V_62 , V_61 ) ;
if ( V_60 != NULL ) * V_60 = V_56 ;
* V_59 = V_55 ;
if ( V_11 == NULL )
{
F_4 ( V_63 , V_65 ) ;
goto V_29;
}
F_12 ( V_21 , ( strlen ( V_11 ) + V_57 - ( V_58 - V_53 ) ) ) ;
while ( * V_11 )
V_21 -> V_39 [ V_51 ++ ] = * ( V_11 ++ ) ;
V_53 = V_58 ;
}
else
V_21 -> V_39 [ V_51 ++ ] = * ( V_53 ++ ) ;
}
V_21 -> V_39 [ V_51 ] = '\0' ;
if ( * V_52 != NULL ) Free ( * V_52 ) ;
* V_52 = V_21 -> V_39 ;
Free ( V_21 ) ;
return ( 1 ) ;
V_29:
if ( V_21 != NULL ) F_24 ( V_21 ) ;
return ( 0 ) ;
}
static char * F_15 ( char * V_11 )
{
while ( F_20 ( * V_11 ) && ( ! F_16 ( * V_11 ) ) )
V_11 ++ ;
return ( V_11 ) ;
}
static char * F_17 ( char * V_11 )
{
for (; ; )
{
if ( F_13 ( * V_11 ) )
{
V_11 = F_41 ( V_11 ) ;
continue;
}
if ( ! F_43 ( * V_11 ) )
return ( V_11 ) ;
V_11 ++ ;
}
}
static unsigned long V_35 ( T_4 * V_16 )
{
return ( ( F_44 ( V_16 -> V_20 ) << 2 ) ^ F_44 ( V_16 -> V_43 ) ) ;
}
static int V_36 ( T_4 * V_49 , T_4 * V_66 )
{
int V_7 ;
if ( V_49 -> V_20 != V_66 -> V_20 )
{
V_7 = strcmp ( V_49 -> V_20 , V_66 -> V_20 ) ;
if ( V_7 ) return ( V_7 ) ;
}
if ( ( V_49 -> V_43 != NULL ) && ( V_66 -> V_43 != NULL ) )
{
V_7 = strcmp ( V_49 -> V_43 , V_66 -> V_43 ) ;
return ( V_7 ) ;
}
else if ( V_49 -> V_43 == V_66 -> V_43 )
return ( 0 ) ;
else
return ( ( V_49 -> V_43 == NULL ) ? - 1 : 1 ) ;
}
static char * F_40 ( char * V_11 )
{
int V_54 = * V_11 ;
V_11 ++ ;
while ( ! ( F_16 ( * V_11 ) ) && ( * V_11 != V_54 ) )
{
if ( F_13 ( * V_11 ) )
{
V_11 ++ ;
if ( F_16 ( * V_11 ) ) return ( V_11 ) ;
}
V_11 ++ ;
}
if ( * V_11 == V_54 ) V_11 ++ ;
return ( V_11 ) ;
}
static T_4 * F_11 ( T_1 * V_44 , char * V_20 )
{
T_5 * V_50 = NULL ;
int V_67 = 0 , V_7 ;
T_4 * V_16 = NULL , * V_17 ;
if ( ( V_50 = F_45 () ) == NULL )
goto V_29;
if ( ( V_16 = ( T_4 * ) Malloc ( sizeof( T_4 ) ) ) == NULL )
goto V_29;
V_7 = strlen ( V_20 ) + 1 ;
if ( ( V_16 -> V_20 = ( char * ) Malloc ( V_7 ) ) == NULL )
goto V_29;
memcpy ( V_16 -> V_20 , V_20 , V_7 ) ;
V_16 -> V_43 = NULL ;
V_16 -> V_38 = ( char * ) V_50 ;
V_17 = ( T_4 * ) F_22 ( V_44 , ( char * ) V_16 ) ;
if ( V_17 != NULL )
{
#if ! F_46 ( V_68 ) && ! F_46 ( V_69 )
fprintf ( V_70 , L_7 ) ;
#endif
abort () ;
}
V_67 = 1 ;
V_29:
if ( ! V_67 )
{
if ( V_50 != NULL ) F_37 ( V_50 ) ;
if ( V_16 != NULL ) Free ( V_16 ) ;
V_16 = NULL ;
}
return ( V_16 ) ;
}
