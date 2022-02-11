T_1 * F_1 ( T_1 * V_1 , const char * V_2 , long * line )
{
T_1 * V_3 ;
T_2 * V_4 = NULL ;
#ifdef F_2
V_4 = fopen ( V_2 , L_1 ) ;
#else
V_4 = fopen ( V_2 , L_2 ) ;
#endif
if ( V_4 == NULL )
{
F_3 ( V_5 , F_4 () ) ;
F_5 ( F_6 ( V_2 ) ,
V_6 | V_7 ) ;
F_7 ( V_8 , V_9 ) ;
return NULL ;
}
V_3 = F_8 ( V_1 , V_4 , line ) ;
fclose ( V_4 ) ;
return V_3 ;
}
T_1 * F_8 ( T_1 * V_1 , T_2 * V_4 , long * line )
{
T_3 * V_10 ;
T_1 * V_3 ;
if( ! ( V_10 = F_9 ( V_4 , V_11 ) ) ) {
F_7 ( V_12 , V_13 ) ;
return NULL ;
}
V_3 = F_10 ( V_1 , V_10 , line ) ;
F_11 ( V_10 ) ;
return V_3 ;
}
T_1 * F_10 ( T_1 * V_1 , T_3 * V_4 , long * line )
{
T_1 * V_14 = NULL ;
#define F_12 512
char V_10 [ 16 ] ;
int V_15 = 0 , V_16 , V_17 ;
T_4 * V_18 = NULL ;
char * V_19 , * V_20 , * V_21 ;
int V_22 , V_23 ;
long V_24 = 0 ;
T_5 * V_25 = NULL , * V_26 , * V_27 ;
T_5 * V_28 = NULL ;
char * V_29 = NULL , * V_30 ;
F_13 ( T_5 ) * V_31 = NULL , * V_32 ;
char * V_33 , * V_34 , * V_35 ;
if ( ( V_18 = F_14 () ) == NULL )
{
F_7 ( V_36 , V_13 ) ;
goto V_37;
}
V_29 = ( char * ) Malloc ( 10 ) ;
if ( V_29 == NULL )
{
F_7 ( V_36 , V_38 ) ;
goto V_37;
}
strcpy ( V_29 , L_3 ) ;
if ( V_1 == NULL )
{
if ( ( V_14 = F_15 ( V_39 , V_40 ) ) == NULL )
{
F_7 ( V_36 , V_38 ) ;
goto V_37;
}
}
else
V_14 = V_1 ;
V_28 = F_16 ( V_14 , V_29 ) ;
if ( V_28 == NULL )
{
F_7 ( V_36 ,
V_41 ) ;
goto V_37;
}
V_31 = ( F_13 ( T_5 ) * ) V_28 -> V_42 ;
V_15 = 0 ;
for (; ; )
{
V_22 = 0 ;
if ( ! F_17 ( V_18 , V_15 + F_12 ) )
{
F_7 ( V_36 , V_13 ) ;
goto V_37;
}
V_20 = & ( V_18 -> V_43 [ V_15 ] ) ;
* V_20 = '\0' ;
F_18 ( V_4 , V_20 , F_12 - 1 ) ;
V_20 [ F_12 - 1 ] = '\0' ;
V_17 = V_16 = strlen ( V_20 ) ;
if ( V_16 == 0 ) break;
while ( V_16 > 0 )
{
if ( ( V_20 [ V_16 - 1 ] != '\r' ) && ( V_20 [ V_16 - 1 ] != '\n' ) )
break;
else
V_16 -- ;
}
if ( V_16 == V_17 )
V_22 = 1 ;
else
{
V_20 [ V_16 ] = '\0' ;
V_24 ++ ;
}
V_15 += V_16 ;
V_25 = NULL ;
if ( V_15 >= 1 )
{
V_20 = & ( V_18 -> V_43 [ V_15 - 1 ] ) ;
if ( F_19 ( V_20 [ 0 ] ) &&
( ( V_15 <= 1 ) || ! F_19 ( V_20 [ - 1 ] ) ) )
{
V_15 -- ;
V_22 = 1 ;
}
}
if ( V_22 ) continue;
V_15 = 0 ;
V_30 = V_18 -> V_43 ;
F_20 ( V_30 ) ;
V_23 = strlen ( V_30 ) ;
V_19 = F_21 ( V_30 ) ;
if ( F_22 ( * V_19 ) ) continue;
if ( * V_19 == '[' )
{
char * V_44 ;
V_19 ++ ;
V_33 = F_21 ( V_19 ) ;
V_44 = V_33 ;
V_22:
V_21 = F_23 ( V_44 ) ;
V_20 = F_21 ( V_21 ) ;
if ( * V_20 != ']' )
{
if ( * V_20 != '\0' )
{
V_44 = V_20 ;
goto V_22;
}
F_7 ( V_36 ,
V_45 ) ;
goto V_37;
}
* V_21 = '\0' ;
if ( ! F_24 ( V_14 , NULL , & V_29 , V_33 ) ) goto V_37;
if ( ( V_28 = F_25 ( V_14 , V_29 ) ) == NULL )
V_28 = F_16 ( V_14 , V_29 ) ;
if ( V_28 == NULL )
{
F_7 ( V_36 ,
V_41 ) ;
goto V_37;
}
V_31 = ( F_13 ( T_5 ) * ) V_28 -> V_42 ;
continue;
}
else
{
V_35 = V_19 ;
V_34 = NULL ;
V_21 = F_23 ( V_19 ) ;
if ( ( V_21 [ 0 ] == ':' ) && ( V_21 [ 1 ] == ':' ) )
{
* V_21 = '\0' ;
V_21 += 2 ;
V_34 = V_35 ;
V_35 = V_21 ;
V_21 = F_23 ( V_21 ) ;
}
V_20 = F_21 ( V_21 ) ;
if ( * V_20 != '=' )
{
F_7 ( V_36 ,
V_46 ) ;
goto V_37;
}
* V_21 = '\0' ;
V_20 ++ ;
V_33 = F_21 ( V_20 ) ;
while ( ! F_22 ( * V_20 ) )
V_20 ++ ;
V_20 -- ;
while ( ( V_20 != V_33 ) && ( F_26 ( * V_20 ) ) )
V_20 -- ;
V_20 ++ ;
* V_20 = '\0' ;
if ( ! ( V_25 = ( T_5 * ) Malloc ( sizeof( T_5 ) ) ) )
{
F_7 ( V_36 ,
V_38 ) ;
goto V_37;
}
if ( V_34 == NULL ) V_34 = V_29 ;
V_25 -> V_47 = ( char * ) Malloc ( strlen ( V_35 ) + 1 ) ;
V_25 -> V_42 = NULL ;
if ( V_25 -> V_47 == NULL )
{
F_7 ( V_36 ,
V_38 ) ;
goto V_37;
}
strcpy ( V_25 -> V_47 , V_35 ) ;
if ( ! F_24 ( V_14 , V_34 , & ( V_25 -> V_42 ) , V_33 ) ) goto V_37;
if ( strcmp ( V_34 , V_29 ) != 0 )
{
if ( ( V_27 = F_25 ( V_14 , V_34 ) )
== NULL )
V_27 = F_16 ( V_14 , V_34 ) ;
if ( V_27 == NULL )
{
F_7 ( V_36 ,
V_41 ) ;
goto V_37;
}
V_32 = ( F_13 ( T_5 ) * ) V_27 -> V_42 ;
}
else
{
V_27 = V_28 ;
V_32 = V_31 ;
}
V_25 -> V_29 = V_27 -> V_29 ;
if ( ! F_27 ( V_32 , V_25 ) )
{
F_7 ( V_36 ,
V_38 ) ;
goto V_37;
}
V_26 = ( T_5 * ) F_28 ( V_14 , ( char * ) V_25 ) ;
if ( V_26 != NULL )
{
F_29 ( V_32 , V_26 ) ;
Free ( V_26 -> V_47 ) ;
Free ( V_26 -> V_42 ) ;
Free ( V_26 ) ;
}
V_25 = NULL ;
}
}
if ( V_18 != NULL ) F_30 ( V_18 ) ;
if ( V_29 != NULL ) Free ( V_29 ) ;
return ( V_14 ) ;
V_37:
if ( V_18 != NULL ) F_30 ( V_18 ) ;
if ( V_29 != NULL ) Free ( V_29 ) ;
if ( line != NULL ) * line = V_24 ;
sprintf ( V_10 , L_4 , V_24 ) ;
F_31 ( 2 , L_5 , V_10 ) ;
if ( ( V_1 != V_14 ) && ( V_14 != NULL ) ) F_32 ( V_14 ) ;
if ( V_25 != NULL )
{
if ( V_25 -> V_47 != NULL ) Free ( V_25 -> V_47 ) ;
if ( V_25 -> V_42 != NULL ) Free ( V_25 -> V_42 ) ;
if ( V_25 != NULL ) Free ( V_25 ) ;
}
return ( NULL ) ;
}
char * F_33 ( T_1 * V_48 , char * V_29 , char * V_47 )
{
T_5 * V_25 , V_26 ;
char * V_20 ;
if ( V_47 == NULL ) return ( NULL ) ;
if ( V_48 != NULL )
{
if ( V_29 != NULL )
{
V_26 . V_47 = V_47 ;
V_26 . V_29 = V_29 ;
V_25 = ( T_5 * ) F_34 ( V_48 , ( char * ) & V_26 ) ;
if ( V_25 != NULL ) return ( V_25 -> V_42 ) ;
if ( strcmp ( V_29 , L_6 ) == 0 )
{
V_20 = Getenv ( V_47 ) ;
if ( V_20 != NULL ) return ( V_20 ) ;
}
}
V_26 . V_29 = L_3 ;
V_26 . V_47 = V_47 ;
V_25 = ( T_5 * ) F_34 ( V_48 , ( char * ) & V_26 ) ;
if ( V_25 != NULL )
return ( V_25 -> V_42 ) ;
else
return ( NULL ) ;
}
else
return ( Getenv ( V_47 ) ) ;
}
static T_5 * F_25 ( T_1 * V_48 , char * V_29 )
{
T_5 * V_25 , V_26 ;
if ( ( V_48 == NULL ) || ( V_29 == NULL ) ) return ( NULL ) ;
V_26 . V_47 = NULL ;
V_26 . V_29 = V_29 ;
V_25 = ( T_5 * ) F_34 ( V_48 , ( char * ) & V_26 ) ;
return ( V_25 ) ;
}
long F_35 ( T_1 * V_48 , char * V_29 , char * V_47 )
{
char * V_49 ;
long V_14 = 0 ;
V_49 = F_33 ( V_48 , V_29 , V_47 ) ;
if ( V_49 == NULL ) return ( 0 ) ;
for (; ; )
{
if ( F_36 ( * V_49 ) )
V_14 = V_14 * 10 + ( * V_49 - '0' ) ;
else
return ( V_14 ) ;
V_49 ++ ;
}
}
void F_32 ( T_1 * V_48 )
{
if ( V_48 == NULL ) return;
V_48 -> V_50 = 0 ;
F_37 ( V_48 , ( void ( * ) () ) V_51 , ( char * ) V_48 ) ;
F_37 ( V_48 , ( void ( * ) () ) V_52 , ( char * ) V_48 ) ;
F_38 ( V_48 ) ;
}
static void V_51 ( T_5 * V_53 , T_1 * V_48 )
{
if ( V_53 -> V_47 != NULL )
{
V_53 = ( T_5 * ) F_39 ( V_48 , ( char * ) V_53 ) ;
}
}
static void V_52 ( T_5 * V_53 , T_1 * V_48 )
{
T_5 * V_26 ;
T_6 * V_54 ;
int V_16 ;
if ( V_53 -> V_47 != NULL ) return;
V_54 = ( T_6 * ) V_53 -> V_42 ;
for ( V_16 = F_40 ( V_54 ) - 1 ; V_16 >= 0 ; V_16 -- )
{
V_26 = ( T_5 * ) F_41 ( V_54 , V_16 ) ;
Free ( V_26 -> V_42 ) ;
Free ( V_26 -> V_47 ) ;
Free ( V_26 ) ;
}
if ( V_54 != NULL ) F_42 ( V_54 ) ;
Free ( V_53 -> V_29 ) ;
Free ( V_53 ) ;
}
static void F_20 ( char * V_20 )
{
char * V_55 ;
V_55 = V_20 ;
for (; ; )
{
if ( F_43 ( * V_20 ) )
{
* V_20 = '\0' ;
return;
}
if ( F_44 ( * V_20 ) )
{
V_20 = F_45 ( V_20 ) ;
continue;
}
if ( F_19 ( * V_20 ) )
{
V_20 = F_46 ( V_20 ) ;
continue;
}
if ( F_22 ( * V_20 ) )
return;
else
V_20 ++ ;
}
}
static int F_24 ( T_1 * V_48 , char * V_29 , char * * V_56 , char * V_57 )
{
int V_58 , V_59 , V_60 = 0 , V_55 = 0 , V_61 = 0 ;
char * V_19 , * V_62 , * V_63 , * V_20 , * V_64 , * V_65 , * V_66 , V_25 ;
T_4 * V_30 ;
if ( ( V_30 = F_14 () ) == NULL ) return ( 0 ) ;
V_61 = strlen ( V_57 ) + 1 ;
if ( ! F_17 ( V_30 , V_61 ) ) goto V_37;
for (; ; )
{
if ( F_44 ( * V_57 ) )
{
V_58 = * V_57 ;
V_57 ++ ;
while ( ( * V_57 != '\0' ) && ( * V_57 != V_58 ) )
{
if ( * V_57 == '\\' )
{
V_57 ++ ;
if ( * V_57 == '\0' ) break;
}
V_30 -> V_43 [ V_55 ++ ] = * ( V_57 ++ ) ;
}
}
else if ( * V_57 == '\\' )
{
V_57 ++ ;
V_25 = * ( V_57 ++ ) ;
if ( V_25 == '\0' ) break;
else if ( V_25 == 'r' ) V_25 = '\r' ;
else if ( V_25 == 'n' ) V_25 = '\n' ;
else if ( V_25 == 'b' ) V_25 = '\b' ;
else if ( V_25 == 't' ) V_25 = '\t' ;
V_30 -> V_43 [ V_55 ++ ] = V_25 ;
}
else if ( * V_57 == '\0' )
break;
else if ( * V_57 == '$' )
{
V_64 = NULL ;
V_19 = & ( V_57 [ 1 ] ) ;
if ( * V_19 == '{' )
V_58 = '}' ;
else if ( * V_19 == '(' )
V_58 = ')' ;
else V_58 = 0 ;
if ( V_58 ) V_19 ++ ;
V_66 = V_29 ;
V_62 = V_65 = V_19 ;
while ( F_47 ( * V_62 ) )
V_62 ++ ;
if ( ( V_62 [ 0 ] == ':' ) && ( V_62 [ 1 ] == ':' ) )
{
V_66 = V_65 ;
V_64 = V_62 ;
V_60 = * V_62 ;
* V_64 = '\0' ;
V_62 += 2 ;
V_65 = V_62 ;
while ( F_47 ( * V_62 ) )
V_62 ++ ;
}
V_59 = * V_62 ;
* V_62 = '\0' ;
V_63 = V_62 ;
if ( V_58 )
{
if ( V_59 != V_58 )
{
F_7 ( V_67 , V_68 ) ;
goto V_37;
}
V_62 ++ ;
}
V_20 = F_33 ( V_48 , V_66 , V_65 ) ;
if ( V_64 != NULL ) * V_64 = V_60 ;
* V_63 = V_59 ;
if ( V_20 == NULL )
{
F_7 ( V_67 , V_69 ) ;
goto V_37;
}
F_17 ( V_30 , ( strlen ( V_20 ) + V_61 - ( V_62 - V_57 ) ) ) ;
while ( * V_20 )
V_30 -> V_43 [ V_55 ++ ] = * ( V_20 ++ ) ;
V_57 = V_62 ;
}
else
V_30 -> V_43 [ V_55 ++ ] = * ( V_57 ++ ) ;
}
V_30 -> V_43 [ V_55 ] = '\0' ;
if ( * V_56 != NULL ) Free ( * V_56 ) ;
* V_56 = V_30 -> V_43 ;
Free ( V_30 ) ;
return ( 1 ) ;
V_37:
if ( V_30 != NULL ) F_30 ( V_30 ) ;
return ( 0 ) ;
}
static char * F_21 ( char * V_20 )
{
while ( F_26 ( * V_20 ) && ( ! F_22 ( * V_20 ) ) )
V_20 ++ ;
return ( V_20 ) ;
}
static char * F_23 ( char * V_20 )
{
for (; ; )
{
if ( F_19 ( * V_20 ) )
{
V_20 = F_46 ( V_20 ) ;
continue;
}
if ( ! F_48 ( * V_20 ) )
return ( V_20 ) ;
V_20 ++ ;
}
}
static unsigned long V_39 ( T_5 * V_25 )
{
return ( ( F_49 ( V_25 -> V_29 ) << 2 ) ^ F_49 ( V_25 -> V_47 ) ) ;
}
static int V_40 ( T_5 * V_53 , T_5 * V_70 )
{
int V_16 ;
if ( V_53 -> V_29 != V_70 -> V_29 )
{
V_16 = strcmp ( V_53 -> V_29 , V_70 -> V_29 ) ;
if ( V_16 ) return ( V_16 ) ;
}
if ( ( V_53 -> V_47 != NULL ) && ( V_70 -> V_47 != NULL ) )
{
V_16 = strcmp ( V_53 -> V_47 , V_70 -> V_47 ) ;
return ( V_16 ) ;
}
else if ( V_53 -> V_47 == V_70 -> V_47 )
return ( 0 ) ;
else
return ( ( V_53 -> V_47 == NULL ) ? - 1 : 1 ) ;
}
static char * F_45 ( char * V_20 )
{
int V_58 = * V_20 ;
V_20 ++ ;
while ( ! ( F_22 ( * V_20 ) ) && ( * V_20 != V_58 ) )
{
if ( F_19 ( * V_20 ) )
{
V_20 ++ ;
if ( F_22 ( * V_20 ) ) return ( V_20 ) ;
}
V_20 ++ ;
}
if ( * V_20 == V_58 ) V_20 ++ ;
return ( V_20 ) ;
}
static T_5 * F_16 ( T_1 * V_48 , char * V_29 )
{
T_6 * V_54 = NULL ;
int V_71 = 0 , V_16 ;
T_5 * V_25 = NULL , * V_26 ;
if ( ( V_54 = F_50 () ) == NULL )
goto V_37;
if ( ( V_25 = ( T_5 * ) Malloc ( sizeof( T_5 ) ) ) == NULL )
goto V_37;
V_16 = strlen ( V_29 ) + 1 ;
if ( ( V_25 -> V_29 = ( char * ) Malloc ( V_16 ) ) == NULL )
goto V_37;
memcpy ( V_25 -> V_29 , V_29 , V_16 ) ;
V_25 -> V_47 = NULL ;
V_25 -> V_42 = ( char * ) V_54 ;
V_26 = ( T_5 * ) F_28 ( V_48 , ( char * ) V_25 ) ;
if ( V_26 != NULL )
{
#if ! F_51 ( V_72 ) && ! F_51 ( V_73 )
fprintf ( V_74 , L_7 ) ;
#endif
abort () ;
}
V_71 = 1 ;
V_37:
if ( ! V_71 )
{
if ( V_54 != NULL ) F_42 ( V_54 ) ;
if ( V_25 != NULL ) Free ( V_25 ) ;
V_25 = NULL ;
}
return ( V_25 ) ;
}
