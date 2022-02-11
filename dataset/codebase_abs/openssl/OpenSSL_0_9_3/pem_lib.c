static int F_1 ( char * V_1 , int V_2 , int V_3 )
{
#ifdef F_2
F_3 ( V_4 , V_5 ) ;
return ( - 1 ) ;
#else
int V_6 , V_7 ;
const char * V_8 ;
V_8 = F_4 () ;
if ( V_8 == NULL )
V_8 = L_1 ;
for (; ; )
{
V_6 = F_5 ( V_1 , V_2 , V_8 , V_3 ) ;
if ( V_6 != 0 )
{
F_3 ( V_4 , V_9 ) ;
memset ( V_1 , 0 , ( unsigned int ) V_2 ) ;
return ( - 1 ) ;
}
V_7 = strlen ( V_1 ) ;
if ( V_7 < V_10 )
{
fprintf ( V_11 , L_2 , V_10 ) ;
}
else
break;
}
return ( V_7 ) ;
#endif
}
void F_6 ( char * V_1 , int type )
{
const char * V_12 ;
if ( type == V_13 )
V_12 = L_3 ;
else if ( type == V_14 )
V_12 = L_4 ;
else if ( type == V_15 )
V_12 = L_5 ;
else
V_12 = L_6 ;
strcat ( V_1 , L_7 ) ;
strcat ( V_1 , V_12 ) ;
strcat ( V_1 , L_8 ) ;
}
void F_7 ( char * V_1 , const char * type , int V_16 , char * V_12 )
{
static unsigned char V_17 [ 17 ] = L_9 ;
long V_6 ;
int V_7 ;
strcat ( V_1 , L_10 ) ;
strcat ( V_1 , type ) ;
strcat ( V_1 , L_11 ) ;
V_7 = strlen ( V_1 ) ;
for ( V_6 = 0 ; V_6 < V_16 ; V_6 ++ )
{
V_1 [ V_7 + V_6 * 2 ] = V_17 [ ( V_12 [ V_6 ] >> 4 ) & 0x0f ] ;
V_1 [ V_7 + V_6 * 2 + 1 ] = V_17 [ ( V_12 [ V_6 ] ) & 0x0f ] ;
}
V_1 [ V_7 + V_6 * 2 ] = '\n' ;
V_1 [ V_7 + V_6 * 2 + 1 ] = '\0' ;
}
char * F_8 ( char * (* F_9)() , const char * V_18 , T_1 * V_19 , char * * V_20 ,
T_2 * V_21 )
{
T_3 * V_22 ;
char * V_23 ;
if ( ( V_22 = F_10 ( F_11 () ) ) == NULL )
{
F_3 ( V_24 , V_25 ) ;
return ( 0 ) ;
}
F_12 ( V_22 , V_19 , V_26 ) ;
V_23 = F_13 ( F_9 , V_18 , V_22 , V_20 , V_21 ) ;
F_14 ( V_22 ) ;
return ( V_23 ) ;
}
char * F_13 ( char * (* F_9)() , const char * V_18 , T_3 * V_27 , char * * V_20 ,
T_2 * V_21 )
{
T_4 V_28 ;
char * V_29 = NULL , * V_30 = NULL ;
unsigned char * V_31 = NULL , * V_32 = NULL ;
long V_16 ;
char * V_23 = NULL ;
for (; ; )
{
if ( ! F_15 ( V_27 , & V_29 , & V_30 , & V_32 , & V_16 ) ) return ( NULL ) ;
if ( ( strcmp ( V_29 , V_18 ) == 0 ) ||
( ( strcmp ( V_29 , V_33 ) == 0 ) &&
( strcmp ( V_18 , V_34 ) == 0 ) ) ||
( ( strcmp ( V_29 , V_35 ) == 0 ) &&
( strcmp ( V_18 , V_34 ) == 0 ) ) ||
( ( strcmp ( V_29 , V_36 ) == 0 ) &&
( strcmp ( V_18 , V_37 ) == 0 ) ) ||
( ( strcmp ( V_29 , V_38 ) == 0 ) &&
( strcmp ( V_18 , V_39 ) == 0 ) )
)
break;
Free ( V_29 ) ;
Free ( V_30 ) ;
Free ( V_32 ) ;
}
if ( ! F_16 ( V_30 , & V_28 ) ) goto V_40;
if ( ! F_17 ( & V_28 , V_32 , & V_16 , V_21 ) ) goto V_40;
V_31 = V_32 ;
if ( strcmp ( V_18 , V_34 ) == 0 )
{
if ( strcmp ( V_29 , V_33 ) == 0 )
V_23 = F_9 ( V_41 , V_20 , & V_31 , V_16 ) ;
else if ( strcmp ( V_29 , V_35 ) == 0 )
V_23 = F_9 ( V_42 , V_20 , & V_31 , V_16 ) ;
}
else
V_23 = F_9 ( V_20 , & V_31 , V_16 ) ;
if ( V_23 == NULL )
F_3 ( V_43 , V_44 ) ;
V_40:
Free ( V_29 ) ;
Free ( V_30 ) ;
Free ( V_32 ) ;
return ( V_23 ) ;
}
int F_18 ( int (* F_19)() , const char * V_18 , T_1 * V_19 , char * V_20 ,
const T_5 * V_45 , unsigned char * V_46 , int V_47 ,
T_2 * V_48 )
{
T_3 * V_22 ;
int V_23 ;
if ( ( V_22 = F_10 ( F_11 () ) ) == NULL )
{
F_3 ( V_49 , V_25 ) ;
return ( 0 ) ;
}
F_12 ( V_22 , V_19 , V_26 ) ;
V_23 = F_20 ( F_19 , V_18 , V_22 , V_20 , V_45 , V_46 , V_47 , V_48 ) ;
F_14 ( V_22 ) ;
return ( V_23 ) ;
}
int F_20 ( int (* F_19)() , const char * V_18 , T_3 * V_27 , char * V_20 ,
const T_5 * V_45 , unsigned char * V_46 , int V_47 ,
T_2 * V_48 )
{
T_6 V_50 ;
int V_51 = 0 , V_6 , V_7 , V_23 = 0 ;
unsigned char * V_31 , * V_32 = NULL ;
const char * V_52 = NULL ;
#define F_21 1024
char V_1 [ F_21 ] ;
unsigned char V_53 [ V_54 ] ;
unsigned char V_55 [ V_56 ] ;
if ( V_45 != NULL )
{
V_52 = F_22 ( F_23 ( V_45 ) ) ;
if ( V_52 == NULL )
{
F_3 ( V_57 , V_58 ) ;
goto V_40;
}
}
if ( ( V_51 = F_19 ( V_20 , NULL ) ) < 0 )
{
F_3 ( V_57 , V_59 ) ;
V_51 = 0 ;
goto V_40;
}
V_32 = ( unsigned char * ) Malloc ( ( unsigned int ) V_51 + 20 ) ;
if ( V_32 == NULL )
{
F_3 ( V_57 , V_59 ) ;
goto V_40;
}
V_31 = V_32 ;
V_6 = F_19 ( V_20 , & V_31 ) ;
if ( V_45 != NULL )
{
if ( V_46 == NULL )
{
if ( V_48 == NULL )
V_47 = F_1 ( V_1 , F_21 , 1 ) ;
else
V_47 = (* V_48)( V_1 , F_21 , 1 ) ;
if ( V_47 <= 0 )
{
F_3 ( V_57 , V_60 ) ;
goto V_40;
}
V_46 = ( unsigned char * ) V_1 ;
}
F_24 ( V_32 , V_6 ) ;
F_25 ( V_55 , 8 ) ;
F_26 ( V_45 , F_27 () , V_55 , V_46 , V_47 , 1 , V_53 , NULL ) ;
if ( V_46 == ( unsigned char * ) V_1 ) memset ( V_1 , 0 , F_21 ) ;
V_1 [ 0 ] = '\0' ;
F_6 ( V_1 , V_13 ) ;
F_7 ( V_1 , V_52 , 8 , ( char * ) V_55 ) ;
F_28 ( & V_50 , V_45 , V_53 , V_55 ) ;
F_29 ( & V_50 , V_32 , & V_7 , V_32 , V_6 ) ;
F_30 ( & V_50 , & ( V_32 [ V_7 ] ) , & V_6 ) ;
V_6 += V_7 ;
V_23 = 1 ;
}
else
{
V_23 = 1 ;
V_1 [ 0 ] = '\0' ;
}
V_6 = F_31 ( V_27 , V_18 , V_1 , V_32 , V_6 ) ;
if ( V_6 <= 0 ) V_23 = 0 ;
V_40:
memset ( V_53 , 0 , sizeof( V_53 ) ) ;
memset ( V_55 , 0 , sizeof( V_55 ) ) ;
memset ( ( char * ) & V_50 , 0 , sizeof( V_50 ) ) ;
memset ( V_1 , 0 , F_21 ) ;
memset ( V_32 , 0 , ( unsigned int ) V_51 ) ;
Free ( V_32 ) ;
return ( V_23 ) ;
}
int F_17 ( T_4 * V_28 , unsigned char * V_32 , long * V_61 ,
T_2 * V_48 )
{
int V_6 , V_7 , V_62 , V_47 ;
long V_16 ;
T_6 V_50 ;
unsigned char V_53 [ V_54 ] ;
char V_1 [ F_21 ] ;
V_16 = * V_61 ;
if ( V_28 -> V_28 == NULL ) return ( 1 ) ;
if ( V_48 == NULL )
V_47 = F_1 ( V_1 , F_21 , 0 ) ;
else
V_47 = V_48 ( V_1 , F_21 , 0 ) ;
if ( V_47 <= 0 )
{
F_3 ( V_63 , V_64 ) ;
return ( 0 ) ;
}
F_26 ( V_28 -> V_28 , F_27 () , & ( V_28 -> V_55 [ 0 ] ) ,
( unsigned char * ) V_1 , V_47 , 1 , V_53 , NULL ) ;
V_7 = ( int ) V_16 ;
F_32 ( & V_50 , V_28 -> V_28 , V_53 , & ( V_28 -> V_55 [ 0 ] ) ) ;
F_33 ( & V_50 , V_32 , & V_6 , V_32 , V_7 ) ;
V_62 = F_34 ( & V_50 , & ( V_32 [ V_6 ] ) , & V_7 ) ;
F_35 ( & V_50 ) ;
memset ( ( char * ) V_1 , 0 , sizeof( V_1 ) ) ;
memset ( ( char * ) V_53 , 0 , sizeof( V_53 ) ) ;
V_7 += V_6 ;
if ( ! V_62 )
{
F_3 ( V_63 , V_65 ) ;
return ( 0 ) ;
}
* V_61 = V_7 ;
return ( 1 ) ;
}
int F_16 ( char * V_30 , T_4 * V_28 )
{
int V_62 ;
const T_5 * V_45 = NULL ;
char * V_31 , V_66 ;
V_28 -> V_28 = NULL ;
if ( ( V_30 == NULL ) || ( * V_30 == '\0' ) || ( * V_30 == '\n' ) )
return ( 1 ) ;
if ( strncmp ( V_30 , L_12 , 11 ) != 0 )
{ F_3 ( V_67 , V_68 ) ; return ( 0 ) ; }
V_30 += 11 ;
if ( * V_30 != '4' ) return ( 0 ) ; V_30 ++ ;
if ( * V_30 != ',' ) return ( 0 ) ; V_30 ++ ;
if ( strncmp ( V_30 , L_3 , 9 ) != 0 )
{ F_3 ( V_67 , V_69 ) ; return ( 0 ) ; }
for (; ( * V_30 != '\n' ) && ( * V_30 != '\0' ) ; V_30 ++ )
;
if ( * V_30 == '\0' )
{ F_3 ( V_67 , V_70 ) ; return ( 0 ) ; }
V_30 ++ ;
if ( strncmp ( V_30 , L_10 , 10 ) != 0 )
{ F_3 ( V_67 , V_71 ) ; return ( 0 ) ; }
V_30 += 10 ;
V_31 = V_30 ;
for (; ; )
{
V_66 = * V_30 ;
if ( ! ( ( ( V_66 >= 'A' ) && ( V_66 <= 'Z' ) ) || ( V_66 == '-' ) ||
( ( V_66 >= '0' ) && ( V_66 <= '9' ) ) ) )
break;
V_30 ++ ;
}
* V_30 = '\0' ;
V_62 = F_36 ( V_31 ) ;
V_28 -> V_28 = V_45 = F_37 ( V_31 ) ;
* V_30 = V_66 ;
V_30 ++ ;
if ( V_45 == NULL )
{
F_3 ( V_67 , V_72 ) ;
return ( 0 ) ;
}
if ( ! F_38 ( ( unsigned char * * ) & V_30 , & ( V_28 -> V_55 [ 0 ] ) , 8 ) ) return ( 0 ) ;
return ( 1 ) ;
}
static int F_38 ( unsigned char * * V_73 , unsigned char * V_74 , int V_2 )
{
int V_75 , V_6 ;
unsigned char * V_76 ;
V_76 = * V_73 ;
for ( V_6 = 0 ; V_6 < V_2 ; V_6 ++ ) V_74 [ V_6 ] = 0 ;
V_2 *= 2 ;
for ( V_6 = 0 ; V_6 < V_2 ; V_6 ++ )
{
if ( ( * V_76 >= '0' ) && ( * V_76 <= '9' ) )
V_75 = * V_76 - '0' ;
else if ( ( * V_76 >= 'A' ) && ( * V_76 <= 'F' ) )
V_75 = * V_76 - 'A' + 10 ;
else if ( ( * V_76 >= 'a' ) && ( * V_76 <= 'f' ) )
V_75 = * V_76 - 'a' + 10 ;
else
{
F_3 ( V_77 , V_78 ) ;
return ( 0 ) ;
}
V_76 ++ ;
V_74 [ V_6 / 2 ] |= V_75 << ( long ) ( ( ! ( V_6 & 1 ) ) * 4 ) ;
}
* V_73 = V_76 ;
return ( 1 ) ;
}
int F_39 ( T_1 * V_19 , char * V_18 , char * V_30 , unsigned char * V_32 ,
long V_16 )
{
T_3 * V_22 ;
int V_23 ;
if ( ( V_22 = F_10 ( F_11 () ) ) == NULL )
{
F_3 ( V_79 , V_25 ) ;
return ( 0 ) ;
}
F_12 ( V_22 , V_19 , V_26 ) ;
V_23 = F_31 ( V_22 , V_18 , V_30 , V_32 , V_16 ) ;
F_14 ( V_22 ) ;
return ( V_23 ) ;
}
int F_31 ( T_3 * V_27 , const char * V_18 , char * V_30 , unsigned char * V_32 ,
long V_16 )
{
int V_80 , V_81 , V_6 , V_7 , V_82 ;
unsigned char * V_1 ;
T_7 V_50 ;
int V_83 = V_25 ;
F_40 ( & V_50 ) ;
V_80 = strlen ( V_18 ) ;
if ( ( F_41 ( V_27 , L_13 , 11 ) != 11 ) ||
( F_41 ( V_27 , V_18 , V_80 ) != V_80 ) ||
( F_41 ( V_27 , L_14 , 6 ) != 6 ) )
goto V_40;
V_6 = strlen ( V_30 ) ;
if ( V_6 > 0 )
{
if ( ( F_41 ( V_27 , V_30 , V_6 ) != V_6 ) ||
( F_41 ( V_27 , L_8 , 1 ) != 1 ) )
goto V_40;
}
V_1 = ( unsigned char * ) Malloc ( F_21 * 8 ) ;
if ( V_1 == NULL )
{
V_83 = V_59 ;
goto V_40;
}
V_6 = V_7 = 0 ;
while ( V_16 > 0 )
{
V_81 = ( int ) ( ( V_16 > ( F_21 * 5 ) ) ? ( F_21 * 5 ) : V_16 ) ;
F_42 ( & V_50 , V_1 , & V_82 , & ( V_32 [ V_7 ] ) , V_81 ) ;
if ( ( V_82 ) && ( F_41 ( V_27 , ( char * ) V_1 , V_82 ) != V_82 ) )
goto V_40;
V_6 += V_82 ;
V_16 -= V_81 ;
V_7 += V_81 ;
}
F_43 ( & V_50 , V_1 , & V_82 ) ;
if ( ( V_82 > 0 ) && ( F_41 ( V_27 , ( char * ) V_1 , V_82 ) != V_82 ) ) goto V_40;
Free ( V_1 ) ;
if ( ( F_41 ( V_27 , L_15 , 9 ) != 9 ) ||
( F_41 ( V_27 , V_18 , V_80 ) != V_80 ) ||
( F_41 ( V_27 , L_14 , 6 ) != 6 ) )
goto V_40;
return ( V_6 + V_82 ) ;
V_40:
F_3 ( V_84 , V_83 ) ;
return ( 0 ) ;
}
int F_44 ( T_1 * V_19 , char * * V_18 , char * * V_30 , unsigned char * * V_32 ,
long * V_16 )
{
T_3 * V_22 ;
int V_23 ;
if ( ( V_22 = F_10 ( F_11 () ) ) == NULL )
{
F_3 ( V_85 , V_25 ) ;
return ( 0 ) ;
}
F_12 ( V_22 , V_19 , V_26 ) ;
V_23 = F_15 ( V_22 , V_18 , V_30 , V_32 , V_16 ) ;
F_14 ( V_22 ) ;
return ( V_23 ) ;
}
int F_15 ( T_3 * V_27 , char * * V_18 , char * * V_30 , unsigned char * * V_32 ,
long * V_16 )
{
T_7 V_50 ;
int V_86 = 0 , V_6 , V_87 , V_88 = 0 , V_89 = 0 , V_90 = 0 ;
char V_1 [ 256 ] ;
T_8 * V_91 ;
T_8 * V_92 ;
T_8 * V_93 , * V_94 ;
V_91 = F_45 () ;
V_92 = F_45 () ;
V_93 = F_45 () ;
if ( ( V_91 == NULL ) || ( V_92 == NULL ) || ( V_93 == NULL ) )
{
F_3 ( V_95 , V_59 ) ;
return ( 0 ) ;
}
V_1 [ 254 ] = '\0' ;
for (; ; )
{
V_6 = F_46 ( V_27 , V_1 , 254 ) ;
if ( V_6 <= 0 )
{
F_3 ( V_95 , V_96 ) ;
goto V_40;
}
while ( ( V_6 >= 0 ) && ( V_1 [ V_6 ] <= ' ' ) ) V_6 -- ;
V_1 [ ++ V_6 ] = '\n' ; V_1 [ ++ V_6 ] = '\0' ;
if ( strncmp ( V_1 , L_13 , 11 ) == 0 )
{
V_6 = strlen ( & ( V_1 [ 11 ] ) ) ;
if ( strncmp ( & ( V_1 [ 11 + V_6 - 6 ] ) , L_14 , 6 ) != 0 )
continue;
if ( ! F_47 ( V_91 , V_6 + 9 ) )
{
F_3 ( V_95 , V_59 ) ;
goto V_40;
}
memcpy ( V_91 -> V_32 , & ( V_1 [ 11 ] ) , V_6 - 6 ) ;
V_91 -> V_32 [ V_6 - 6 ] = '\0' ;
break;
}
}
V_89 = 0 ;
if ( ! F_47 ( V_92 , 256 ) )
{ F_3 ( V_95 , V_59 ) ; goto V_40; }
V_92 -> V_32 [ 0 ] = '\0' ;
for (; ; )
{
V_6 = F_46 ( V_27 , V_1 , 254 ) ;
if ( V_6 <= 0 ) break;
while ( ( V_6 >= 0 ) && ( V_1 [ V_6 ] <= ' ' ) ) V_6 -- ;
V_1 [ ++ V_6 ] = '\n' ; V_1 [ ++ V_6 ] = '\0' ;
if ( V_1 [ 0 ] == '\n' ) break;
if ( ! F_47 ( V_92 , V_89 + V_6 + 9 ) )
{ F_3 ( V_95 , V_59 ) ; goto V_40; }
if ( strncmp ( V_1 , L_15 , 9 ) == 0 )
{
V_90 = 1 ;
break;
}
memcpy ( & ( V_92 -> V_32 [ V_89 ] ) , V_1 , V_6 ) ;
V_92 -> V_32 [ V_89 + V_6 ] = '\0' ;
V_89 += V_6 ;
}
V_88 = 0 ;
if ( ! F_47 ( V_93 , 1024 ) )
{ F_3 ( V_95 , V_59 ) ; goto V_40; }
V_93 -> V_32 [ 0 ] = '\0' ;
if ( ! V_90 )
{
for (; ; )
{
V_6 = F_46 ( V_27 , V_1 , 254 ) ;
if ( V_6 <= 0 ) break;
while ( ( V_6 >= 0 ) && ( V_1 [ V_6 ] <= ' ' ) ) V_6 -- ;
V_1 [ ++ V_6 ] = '\n' ; V_1 [ ++ V_6 ] = '\0' ;
if ( V_6 != 65 ) V_86 = 1 ;
if ( strncmp ( V_1 , L_15 , 9 ) == 0 )
break;
if ( V_6 > 65 ) break;
if ( ! F_47 ( V_93 , V_6 + V_88 + 9 ) )
{
F_3 ( V_95 , V_59 ) ;
goto V_40;
}
memcpy ( & ( V_93 -> V_32 [ V_88 ] ) , V_1 , V_6 ) ;
V_93 -> V_32 [ V_88 + V_6 ] = '\0' ;
V_88 += V_6 ;
if ( V_86 )
{
V_1 [ 0 ] = '\0' ;
V_6 = F_46 ( V_27 , V_1 , 254 ) ;
if ( V_6 <= 0 ) break;
while ( ( V_6 >= 0 ) && ( V_1 [ V_6 ] <= ' ' ) ) V_6 -- ;
V_1 [ ++ V_6 ] = '\n' ; V_1 [ ++ V_6 ] = '\0' ;
break;
}
}
}
else
{
V_94 = V_92 ;
V_92 = V_93 ;
V_93 = V_94 ;
V_88 = V_89 ;
}
V_6 = strlen ( V_91 -> V_32 ) ;
if ( ( strncmp ( V_1 , L_15 , 9 ) != 0 ) ||
( strncmp ( V_91 -> V_32 , & ( V_1 [ 9 ] ) , V_6 ) != 0 ) ||
( strncmp ( & ( V_1 [ 9 + V_6 ] ) , L_14 , 6 ) != 0 ) )
{
F_3 ( V_95 , V_97 ) ;
goto V_40;
}
F_48 ( & V_50 ) ;
V_6 = F_49 ( & V_50 ,
( unsigned char * ) V_93 -> V_32 , & V_88 ,
( unsigned char * ) V_93 -> V_32 , V_88 ) ;
if ( V_6 < 0 )
{
F_3 ( V_95 , V_98 ) ;
goto V_40;
}
V_6 = F_50 ( & V_50 , ( unsigned char * ) & ( V_93 -> V_32 [ V_88 ] ) , & V_87 ) ;
if ( V_6 < 0 )
{
F_3 ( V_95 , V_98 ) ;
goto V_40;
}
V_88 += V_87 ;
if ( V_88 == 0 ) goto V_40;
* V_18 = V_91 -> V_32 ;
* V_30 = V_92 -> V_32 ;
* V_32 = ( unsigned char * ) V_93 -> V_32 ;
* V_16 = V_88 ;
Free ( V_91 ) ;
Free ( V_92 ) ;
Free ( V_93 ) ;
return ( 1 ) ;
V_40:
F_51 ( V_91 ) ;
F_51 ( V_92 ) ;
F_51 ( V_93 ) ;
return ( 0 ) ;
}
