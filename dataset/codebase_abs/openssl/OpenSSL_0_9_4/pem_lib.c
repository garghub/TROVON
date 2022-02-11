static int F_1 ( char * V_1 , int V_2 , int V_3 , void * V_4 )
{
#ifdef F_2
F_3 ( V_5 , V_6 ) ;
return ( - 1 ) ;
#else
int V_7 , V_8 ;
const char * V_9 ;
V_9 = F_4 () ;
if ( V_9 == NULL )
V_9 = L_1 ;
for (; ; )
{
V_7 = F_5 ( V_1 , V_2 , V_9 , V_3 ) ;
if ( V_7 != 0 )
{
F_3 ( V_5 , V_10 ) ;
memset ( V_1 , 0 , ( unsigned int ) V_2 ) ;
return ( - 1 ) ;
}
V_8 = strlen ( V_1 ) ;
if ( V_8 < V_11 )
{
fprintf ( V_12 , L_2 , V_11 ) ;
}
else
break;
}
return ( V_8 ) ;
#endif
}
void F_6 ( char * V_1 , int type )
{
const char * V_13 ;
if ( type == V_14 )
V_13 = L_3 ;
else if ( type == V_15 )
V_13 = L_4 ;
else if ( type == V_16 )
V_13 = L_5 ;
else
V_13 = L_6 ;
strcat ( V_1 , L_7 ) ;
strcat ( V_1 , V_13 ) ;
strcat ( V_1 , L_8 ) ;
}
void F_7 ( char * V_1 , const char * type , int V_17 , char * V_13 )
{
static unsigned char V_18 [ 17 ] = L_9 ;
long V_7 ;
int V_8 ;
strcat ( V_1 , L_10 ) ;
strcat ( V_1 , type ) ;
strcat ( V_1 , L_11 ) ;
V_8 = strlen ( V_1 ) ;
for ( V_7 = 0 ; V_7 < V_17 ; V_7 ++ )
{
V_1 [ V_8 + V_7 * 2 ] = V_18 [ ( V_13 [ V_7 ] >> 4 ) & 0x0f ] ;
V_1 [ V_8 + V_7 * 2 + 1 ] = V_18 [ ( V_13 [ V_7 ] ) & 0x0f ] ;
}
V_1 [ V_8 + V_7 * 2 ] = '\n' ;
V_1 [ V_8 + V_7 * 2 + 1 ] = '\0' ;
}
char * F_8 ( char * (* F_9)() , const char * V_19 , T_1 * V_20 , char * * V_21 ,
T_2 * V_22 , void * V_23 )
{
T_3 * V_24 ;
char * V_25 ;
if ( ( V_24 = F_10 ( F_11 () ) ) == NULL )
{
F_3 ( V_26 , V_27 ) ;
return ( 0 ) ;
}
F_12 ( V_24 , V_20 , V_28 ) ;
V_25 = F_13 ( F_9 , V_19 , V_24 , V_21 , V_22 , V_23 ) ;
F_14 ( V_24 ) ;
return ( V_25 ) ;
}
char * F_13 ( char * (* F_9)() , const char * V_19 , T_3 * V_29 , char * * V_21 ,
T_2 * V_22 , void * V_23 )
{
T_4 V_30 ;
char * V_31 = NULL , * V_32 = NULL ;
unsigned char * V_33 = NULL , * V_34 = NULL ;
long V_17 ;
char * V_25 = NULL ;
for (; ; )
{
if ( ! F_15 ( V_29 , & V_31 , & V_32 , & V_34 , & V_17 ) ) return ( NULL ) ;
if ( ( strcmp ( V_31 , V_19 ) == 0 ) ||
( ( strcmp ( V_31 , V_35 ) == 0 ) &&
( strcmp ( V_19 , V_36 ) == 0 ) ) ||
( ( strcmp ( V_31 , V_37 ) == 0 ) &&
( strcmp ( V_19 , V_36 ) == 0 ) ) ||
( ( strcmp ( V_31 , V_38 ) == 0 ) &&
( strcmp ( V_19 , V_36 ) == 0 ) ) ||
( ( strcmp ( V_31 , V_39 ) == 0 ) &&
( strcmp ( V_19 , V_36 ) == 0 ) ) ||
( ( strcmp ( V_31 , V_40 ) == 0 ) &&
( strcmp ( V_19 , V_41 ) == 0 ) ) ||
( ( strcmp ( V_31 , V_42 ) == 0 ) &&
( strcmp ( V_19 , V_43 ) == 0 ) )
)
break;
Free ( V_31 ) ;
Free ( V_32 ) ;
Free ( V_34 ) ;
}
if ( ! F_16 ( V_32 , & V_30 ) ) goto V_44;
if ( ! F_17 ( & V_30 , V_34 , & V_17 , V_22 , V_23 ) ) goto V_44;
V_33 = V_34 ;
if ( strcmp ( V_19 , V_36 ) == 0 ) {
if ( strcmp ( V_31 , V_35 ) == 0 )
V_25 = F_9 ( V_45 , V_21 , & V_33 , V_17 ) ;
else if ( strcmp ( V_31 , V_37 ) == 0 )
V_25 = F_9 ( V_46 , V_21 , & V_33 , V_17 ) ;
else if ( strcmp ( V_31 , V_39 ) == 0 ) {
T_5 * V_47 ;
V_47 = F_18 (
( T_5 * * ) V_21 , & V_33 , V_17 ) ;
V_25 = ( char * ) F_19 ( V_47 ) ;
F_20 ( V_47 ) ;
} else if ( strcmp ( V_31 , V_38 ) == 0 ) {
T_5 * V_47 ;
T_6 * V_48 ;
int V_49 ;
char V_50 [ V_51 ] ;
V_48 = F_21 ( ( T_6 * * ) V_21 , & V_33 , V_17 ) ;
if( ! V_48 ) goto V_52;
if ( V_22 ) V_49 = V_22 ( V_50 , V_51 , 0 , V_23 ) ;
else V_49 = F_1 ( V_50 , V_51 , 0 , V_23 ) ;
if ( V_49 <= 0 ) {
F_3 ( V_53 ,
V_54 ) ;
goto V_44;
}
V_47 = F_22 ( V_48 , V_50 , V_49 ) ;
F_23 ( V_48 ) ;
if( ! V_47 ) goto V_52;
V_25 = ( char * ) F_19 ( V_47 ) ;
F_20 ( V_47 ) ;
}
} else V_25 = F_9 ( V_21 , & V_33 , V_17 ) ;
V_52:
if ( V_25 == NULL )
F_3 ( V_53 , V_55 ) ;
V_44:
Free ( V_31 ) ;
Free ( V_32 ) ;
Free ( V_34 ) ;
return ( V_25 ) ;
}
int F_24 ( int (* F_25)() , const char * V_19 , T_1 * V_20 , char * V_21 ,
const T_7 * V_56 , unsigned char * V_57 , int V_49 ,
T_2 * V_58 , void * V_23 )
{
T_3 * V_24 ;
int V_25 ;
if ( ( V_24 = F_10 ( F_11 () ) ) == NULL )
{
F_3 ( V_59 , V_27 ) ;
return ( 0 ) ;
}
F_12 ( V_24 , V_20 , V_28 ) ;
V_25 = F_26 ( F_25 , V_19 , V_24 , V_21 , V_56 , V_57 , V_49 , V_58 , V_23 ) ;
F_14 ( V_24 ) ;
return ( V_25 ) ;
}
int F_26 ( int (* F_25)() , const char * V_19 , T_3 * V_29 , char * V_21 ,
const T_7 * V_56 , unsigned char * V_57 , int V_49 ,
T_2 * V_58 , void * V_23 )
{
T_8 V_60 ;
int V_61 = 0 , V_7 , V_8 , V_25 = 0 ;
unsigned char * V_33 , * V_34 = NULL ;
const char * V_62 = NULL ;
char V_1 [ V_51 ] ;
unsigned char V_63 [ V_64 ] ;
unsigned char V_65 [ V_66 ] ;
if ( V_56 != NULL )
{
V_62 = F_27 ( F_28 ( V_56 ) ) ;
if ( V_62 == NULL )
{
F_3 ( V_67 , V_68 ) ;
goto V_44;
}
}
if ( ( V_61 = F_25 ( V_21 , NULL ) ) < 0 )
{
F_3 ( V_67 , V_69 ) ;
V_61 = 0 ;
goto V_44;
}
V_34 = ( unsigned char * ) Malloc ( ( unsigned int ) V_61 + 20 ) ;
if ( V_34 == NULL )
{
F_3 ( V_67 , V_69 ) ;
goto V_44;
}
V_33 = V_34 ;
V_7 = F_25 ( V_21 , & V_33 ) ;
if ( V_56 != NULL )
{
if ( V_57 == NULL )
{
if ( V_58 == NULL )
V_49 = F_1 ( V_1 , V_51 , 1 , V_23 ) ;
else
V_49 = (* V_58)( V_1 , V_51 , 1 , V_23 ) ;
if ( V_49 <= 0 )
{
F_3 ( V_67 , V_70 ) ;
goto V_44;
}
#ifdef F_29
F_30 ( V_1 , V_1 , V_49 ) ;
#endif
V_57 = ( unsigned char * ) V_1 ;
}
F_31 ( V_34 , V_7 ) ;
F_32 ( V_65 , 8 ) ;
F_33 ( V_56 , F_34 () , V_65 , V_57 , V_49 , 1 , V_63 , NULL ) ;
if ( V_57 == ( unsigned char * ) V_1 ) memset ( V_1 , 0 , V_51 ) ;
V_1 [ 0 ] = '\0' ;
F_6 ( V_1 , V_14 ) ;
F_7 ( V_1 , V_62 , 8 , ( char * ) V_65 ) ;
F_35 ( & V_60 , V_56 , V_63 , V_65 ) ;
F_36 ( & V_60 , V_34 , & V_8 , V_34 , V_7 ) ;
F_37 ( & V_60 , & ( V_34 [ V_8 ] ) , & V_7 ) ;
V_7 += V_8 ;
V_25 = 1 ;
}
else
{
V_25 = 1 ;
V_1 [ 0 ] = '\0' ;
}
V_7 = F_38 ( V_29 , V_19 , V_1 , V_34 , V_7 ) ;
if ( V_7 <= 0 ) V_25 = 0 ;
V_44:
memset ( V_63 , 0 , sizeof( V_63 ) ) ;
memset ( V_65 , 0 , sizeof( V_65 ) ) ;
memset ( ( char * ) & V_60 , 0 , sizeof( V_60 ) ) ;
memset ( V_1 , 0 , V_51 ) ;
memset ( V_34 , 0 , ( unsigned int ) V_61 ) ;
Free ( V_34 ) ;
return ( V_25 ) ;
}
int F_17 ( T_4 * V_30 , unsigned char * V_34 , long * V_71 ,
T_2 * V_58 , void * V_23 )
{
int V_7 , V_8 , V_72 , V_49 ;
long V_17 ;
T_8 V_60 ;
unsigned char V_63 [ V_64 ] ;
char V_1 [ V_51 ] ;
V_17 = * V_71 ;
if ( V_30 -> V_30 == NULL ) return ( 1 ) ;
if ( V_58 == NULL )
V_49 = F_1 ( V_1 , V_51 , 0 , V_23 ) ;
else
V_49 = V_58 ( V_1 , V_51 , 0 , V_23 ) ;
if ( V_49 <= 0 )
{
F_3 ( V_73 , V_54 ) ;
return ( 0 ) ;
}
#ifdef F_29
F_30 ( V_1 , V_1 , V_49 ) ;
#endif
F_33 ( V_30 -> V_30 , F_34 () , & ( V_30 -> V_65 [ 0 ] ) ,
( unsigned char * ) V_1 , V_49 , 1 , V_63 , NULL ) ;
V_8 = ( int ) V_17 ;
F_39 ( & V_60 , V_30 -> V_30 , V_63 , & ( V_30 -> V_65 [ 0 ] ) ) ;
F_40 ( & V_60 , V_34 , & V_7 , V_34 , V_8 ) ;
V_72 = F_41 ( & V_60 , & ( V_34 [ V_7 ] ) , & V_8 ) ;
F_42 ( & V_60 ) ;
memset ( ( char * ) V_1 , 0 , sizeof( V_1 ) ) ;
memset ( ( char * ) V_63 , 0 , sizeof( V_63 ) ) ;
V_8 += V_7 ;
if ( ! V_72 )
{
F_3 ( V_73 , V_74 ) ;
return ( 0 ) ;
}
* V_71 = V_8 ;
return ( 1 ) ;
}
int F_16 ( char * V_32 , T_4 * V_30 )
{
int V_72 ;
const T_7 * V_56 = NULL ;
char * V_33 , V_75 ;
V_30 -> V_30 = NULL ;
if ( ( V_32 == NULL ) || ( * V_32 == '\0' ) || ( * V_32 == '\n' ) )
return ( 1 ) ;
if ( strncmp ( V_32 , L_12 , 11 ) != 0 )
{ F_3 ( V_76 , V_77 ) ; return ( 0 ) ; }
V_32 += 11 ;
if ( * V_32 != '4' ) return ( 0 ) ; V_32 ++ ;
if ( * V_32 != ',' ) return ( 0 ) ; V_32 ++ ;
if ( strncmp ( V_32 , L_3 , 9 ) != 0 )
{ F_3 ( V_76 , V_78 ) ; return ( 0 ) ; }
for (; ( * V_32 != '\n' ) && ( * V_32 != '\0' ) ; V_32 ++ )
;
if ( * V_32 == '\0' )
{ F_3 ( V_76 , V_79 ) ; return ( 0 ) ; }
V_32 ++ ;
if ( strncmp ( V_32 , L_10 , 10 ) != 0 )
{ F_3 ( V_76 , V_80 ) ; return ( 0 ) ; }
V_32 += 10 ;
V_33 = V_32 ;
for (; ; )
{
V_75 = * V_32 ;
#ifndef F_29
if ( ! ( ( ( V_75 >= 'A' ) && ( V_75 <= 'Z' ) ) || ( V_75 == '-' ) ||
( ( V_75 >= '0' ) && ( V_75 <= '9' ) ) ) )
break;
#else
if ( ! ( isupper ( V_75 ) || ( V_75 == '-' ) ||
isdigit ( V_75 ) ) )
break;
#endif
V_32 ++ ;
}
* V_32 = '\0' ;
V_72 = F_43 ( V_33 ) ;
V_30 -> V_30 = V_56 = F_44 ( V_33 ) ;
* V_32 = V_75 ;
V_32 ++ ;
if ( V_56 == NULL )
{
F_3 ( V_76 , V_81 ) ;
return ( 0 ) ;
}
if ( ! F_45 ( ( unsigned char * * ) & V_32 , & ( V_30 -> V_65 [ 0 ] ) , 8 ) ) return ( 0 ) ;
return ( 1 ) ;
}
static int F_45 ( unsigned char * * V_82 , unsigned char * V_83 , int V_2 )
{
int V_84 , V_7 ;
unsigned char * V_85 ;
V_85 = * V_82 ;
for ( V_7 = 0 ; V_7 < V_2 ; V_7 ++ ) V_83 [ V_7 ] = 0 ;
V_2 *= 2 ;
for ( V_7 = 0 ; V_7 < V_2 ; V_7 ++ )
{
if ( ( * V_85 >= '0' ) && ( * V_85 <= '9' ) )
V_84 = * V_85 - '0' ;
else if ( ( * V_85 >= 'A' ) && ( * V_85 <= 'F' ) )
V_84 = * V_85 - 'A' + 10 ;
else if ( ( * V_85 >= 'a' ) && ( * V_85 <= 'f' ) )
V_84 = * V_85 - 'a' + 10 ;
else
{
F_3 ( V_86 , V_87 ) ;
return ( 0 ) ;
}
V_85 ++ ;
V_83 [ V_7 / 2 ] |= V_84 << ( long ) ( ( ! ( V_7 & 1 ) ) * 4 ) ;
}
* V_82 = V_85 ;
return ( 1 ) ;
}
int F_46 ( T_1 * V_20 , char * V_19 , char * V_32 , unsigned char * V_34 ,
long V_17 )
{
T_3 * V_24 ;
int V_25 ;
if ( ( V_24 = F_10 ( F_11 () ) ) == NULL )
{
F_3 ( V_88 , V_27 ) ;
return ( 0 ) ;
}
F_12 ( V_24 , V_20 , V_28 ) ;
V_25 = F_38 ( V_24 , V_19 , V_32 , V_34 , V_17 ) ;
F_14 ( V_24 ) ;
return ( V_25 ) ;
}
int F_38 ( T_3 * V_29 , const char * V_19 , char * V_32 , unsigned char * V_34 ,
long V_17 )
{
int V_89 , V_90 , V_7 , V_8 , V_91 ;
unsigned char * V_1 ;
T_9 V_60 ;
int V_92 = V_27 ;
F_47 ( & V_60 ) ;
V_89 = strlen ( V_19 ) ;
if ( ( F_48 ( V_29 , L_13 , 11 ) != 11 ) ||
( F_48 ( V_29 , V_19 , V_89 ) != V_89 ) ||
( F_48 ( V_29 , L_14 , 6 ) != 6 ) )
goto V_44;
V_7 = strlen ( V_32 ) ;
if ( V_7 > 0 )
{
if ( ( F_48 ( V_29 , V_32 , V_7 ) != V_7 ) ||
( F_48 ( V_29 , L_8 , 1 ) != 1 ) )
goto V_44;
}
V_1 = ( unsigned char * ) Malloc ( V_51 * 8 ) ;
if ( V_1 == NULL )
{
V_92 = V_69 ;
goto V_44;
}
V_7 = V_8 = 0 ;
while ( V_17 > 0 )
{
V_90 = ( int ) ( ( V_17 > ( V_51 * 5 ) ) ? ( V_51 * 5 ) : V_17 ) ;
F_49 ( & V_60 , V_1 , & V_91 , & ( V_34 [ V_8 ] ) , V_90 ) ;
if ( ( V_91 ) && ( F_48 ( V_29 , ( char * ) V_1 , V_91 ) != V_91 ) )
goto V_44;
V_7 += V_91 ;
V_17 -= V_90 ;
V_8 += V_90 ;
}
F_50 ( & V_60 , V_1 , & V_91 ) ;
if ( ( V_91 > 0 ) && ( F_48 ( V_29 , ( char * ) V_1 , V_91 ) != V_91 ) ) goto V_44;
Free ( V_1 ) ;
if ( ( F_48 ( V_29 , L_15 , 9 ) != 9 ) ||
( F_48 ( V_29 , V_19 , V_89 ) != V_89 ) ||
( F_48 ( V_29 , L_14 , 6 ) != 6 ) )
goto V_44;
return ( V_7 + V_91 ) ;
V_44:
F_3 ( V_93 , V_92 ) ;
return ( 0 ) ;
}
int F_51 ( T_1 * V_20 , char * * V_19 , char * * V_32 , unsigned char * * V_34 ,
long * V_17 )
{
T_3 * V_24 ;
int V_25 ;
if ( ( V_24 = F_10 ( F_11 () ) ) == NULL )
{
F_3 ( V_94 , V_27 ) ;
return ( 0 ) ;
}
F_12 ( V_24 , V_20 , V_28 ) ;
V_25 = F_15 ( V_24 , V_19 , V_32 , V_34 , V_17 ) ;
F_14 ( V_24 ) ;
return ( V_25 ) ;
}
int F_15 ( T_3 * V_29 , char * * V_19 , char * * V_32 , unsigned char * * V_34 ,
long * V_17 )
{
T_9 V_60 ;
int V_95 = 0 , V_7 , V_96 , V_97 = 0 , V_98 = 0 , V_99 = 0 ;
char V_1 [ 256 ] ;
T_10 * V_100 ;
T_10 * V_101 ;
T_10 * V_102 , * V_103 ;
V_100 = F_52 () ;
V_101 = F_52 () ;
V_102 = F_52 () ;
if ( ( V_100 == NULL ) || ( V_101 == NULL ) || ( V_102 == NULL ) )
{
F_3 ( V_104 , V_69 ) ;
return ( 0 ) ;
}
V_1 [ 254 ] = '\0' ;
for (; ; )
{
V_7 = F_53 ( V_29 , V_1 , 254 ) ;
if ( V_7 <= 0 )
{
F_3 ( V_104 , V_105 ) ;
goto V_44;
}
while ( ( V_7 >= 0 ) && ( V_1 [ V_7 ] <= ' ' ) ) V_7 -- ;
V_1 [ ++ V_7 ] = '\n' ; V_1 [ ++ V_7 ] = '\0' ;
if ( strncmp ( V_1 , L_13 , 11 ) == 0 )
{
V_7 = strlen ( & ( V_1 [ 11 ] ) ) ;
if ( strncmp ( & ( V_1 [ 11 + V_7 - 6 ] ) , L_14 , 6 ) != 0 )
continue;
if ( ! F_54 ( V_100 , V_7 + 9 ) )
{
F_3 ( V_104 , V_69 ) ;
goto V_44;
}
memcpy ( V_100 -> V_34 , & ( V_1 [ 11 ] ) , V_7 - 6 ) ;
V_100 -> V_34 [ V_7 - 6 ] = '\0' ;
break;
}
}
V_98 = 0 ;
if ( ! F_54 ( V_101 , 256 ) )
{ F_3 ( V_104 , V_69 ) ; goto V_44; }
V_101 -> V_34 [ 0 ] = '\0' ;
for (; ; )
{
V_7 = F_53 ( V_29 , V_1 , 254 ) ;
if ( V_7 <= 0 ) break;
while ( ( V_7 >= 0 ) && ( V_1 [ V_7 ] <= ' ' ) ) V_7 -- ;
V_1 [ ++ V_7 ] = '\n' ; V_1 [ ++ V_7 ] = '\0' ;
if ( V_1 [ 0 ] == '\n' ) break;
if ( ! F_54 ( V_101 , V_98 + V_7 + 9 ) )
{ F_3 ( V_104 , V_69 ) ; goto V_44; }
if ( strncmp ( V_1 , L_15 , 9 ) == 0 )
{
V_99 = 1 ;
break;
}
memcpy ( & ( V_101 -> V_34 [ V_98 ] ) , V_1 , V_7 ) ;
V_101 -> V_34 [ V_98 + V_7 ] = '\0' ;
V_98 += V_7 ;
}
V_97 = 0 ;
if ( ! F_54 ( V_102 , 1024 ) )
{ F_3 ( V_104 , V_69 ) ; goto V_44; }
V_102 -> V_34 [ 0 ] = '\0' ;
if ( ! V_99 )
{
for (; ; )
{
V_7 = F_53 ( V_29 , V_1 , 254 ) ;
if ( V_7 <= 0 ) break;
while ( ( V_7 >= 0 ) && ( V_1 [ V_7 ] <= ' ' ) ) V_7 -- ;
V_1 [ ++ V_7 ] = '\n' ; V_1 [ ++ V_7 ] = '\0' ;
if ( V_7 != 65 ) V_95 = 1 ;
if ( strncmp ( V_1 , L_15 , 9 ) == 0 )
break;
if ( V_7 > 65 ) break;
if ( ! F_54 ( V_102 , V_7 + V_97 + 9 ) )
{
F_3 ( V_104 , V_69 ) ;
goto V_44;
}
memcpy ( & ( V_102 -> V_34 [ V_97 ] ) , V_1 , V_7 ) ;
V_102 -> V_34 [ V_97 + V_7 ] = '\0' ;
V_97 += V_7 ;
if ( V_95 )
{
V_1 [ 0 ] = '\0' ;
V_7 = F_53 ( V_29 , V_1 , 254 ) ;
if ( V_7 <= 0 ) break;
while ( ( V_7 >= 0 ) && ( V_1 [ V_7 ] <= ' ' ) ) V_7 -- ;
V_1 [ ++ V_7 ] = '\n' ; V_1 [ ++ V_7 ] = '\0' ;
break;
}
}
}
else
{
V_103 = V_101 ;
V_101 = V_102 ;
V_102 = V_103 ;
V_97 = V_98 ;
}
V_7 = strlen ( V_100 -> V_34 ) ;
if ( ( strncmp ( V_1 , L_15 , 9 ) != 0 ) ||
( strncmp ( V_100 -> V_34 , & ( V_1 [ 9 ] ) , V_7 ) != 0 ) ||
( strncmp ( & ( V_1 [ 9 + V_7 ] ) , L_14 , 6 ) != 0 ) )
{
F_3 ( V_104 , V_106 ) ;
goto V_44;
}
F_55 ( & V_60 ) ;
V_7 = F_56 ( & V_60 ,
( unsigned char * ) V_102 -> V_34 , & V_97 ,
( unsigned char * ) V_102 -> V_34 , V_97 ) ;
if ( V_7 < 0 )
{
F_3 ( V_104 , V_107 ) ;
goto V_44;
}
V_7 = F_57 ( & V_60 , ( unsigned char * ) & ( V_102 -> V_34 [ V_97 ] ) , & V_96 ) ;
if ( V_7 < 0 )
{
F_3 ( V_104 , V_107 ) ;
goto V_44;
}
V_97 += V_96 ;
if ( V_97 == 0 ) goto V_44;
* V_19 = V_100 -> V_34 ;
* V_32 = V_101 -> V_34 ;
* V_34 = ( unsigned char * ) V_102 -> V_34 ;
* V_17 = V_97 ;
Free ( V_100 ) ;
Free ( V_101 ) ;
Free ( V_102 ) ;
return ( 1 ) ;
V_44:
F_58 ( V_100 ) ;
F_58 ( V_101 ) ;
F_58 ( V_102 ) ;
return ( 0 ) ;
}
int F_59 ( T_3 * V_29 , T_11 * V_21 , const T_7 * V_56 ,
char * V_57 , int V_49 ,
T_2 * V_22 , void * V_23 )
{
T_6 * V_48 ;
T_5 * V_47 ;
char V_1 [ V_51 ] ;
int V_25 ;
if( ! ( V_47 = F_60 ( V_21 ) ) ) {
F_3 ( V_108 ,
V_109 ) ;
return 0 ;
}
if( V_56 ) {
if( ! V_57 ) {
if( ! V_22 ) V_49 = F_1 ( V_1 , V_51 , 1 , V_23 ) ;
else V_49 = V_22 ( V_1 , V_51 , 1 , V_23 ) ;
if( V_49 <= 0 ) {
F_3 ( V_108 ,
V_70 ) ;
F_20 ( V_47 ) ;
return 0 ;
}
V_57 = V_1 ;
}
V_48 = F_61 ( - 1 , V_56 , V_57 , V_49 , NULL , 0 , 0 , V_47 ) ;
if( V_57 == V_1 ) memset ( V_1 , 0 , V_49 ) ;
F_20 ( V_47 ) ;
V_25 = F_62 ( V_29 , V_48 ) ;
F_23 ( V_48 ) ;
return V_25 ;
} else {
V_25 = F_63 ( V_29 , V_47 ) ;
F_20 ( V_47 ) ;
return V_25 ;
}
}
int F_64 ( T_1 * V_20 , T_11 * V_21 , const T_7 * V_56 ,
char * V_57 , int V_49 , T_2 * V_22 , void * V_23 )
{
T_3 * V_29 ;
int V_25 ;
if( ! ( V_29 = F_65 ( V_20 , V_28 ) ) ) {
F_3 ( V_110 , V_27 ) ;
return ( 0 ) ;
}
V_25 = F_59 ( V_29 , V_21 , V_56 , V_57 , V_49 , V_22 , V_23 ) ;
F_14 ( V_29 ) ;
return V_25 ;
}
