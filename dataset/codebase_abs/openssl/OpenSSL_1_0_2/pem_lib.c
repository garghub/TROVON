int F_1 ( char * V_1 , int V_2 , int V_3 , void * V_4 )
{
#ifdef F_2
F_3 ( V_5 , V_6 ) ;
return ( - 1 ) ;
#else
int V_7 , V_8 ;
const char * V_9 ;
if ( V_4 ) {
V_7 = strlen ( V_4 ) ;
V_7 = ( V_7 > V_2 ) ? V_2 : V_7 ;
memcpy ( V_1 , V_4 , V_7 ) ;
return ( V_7 ) ;
}
V_9 = F_4 () ;
if ( V_9 == NULL )
V_9 = L_1 ;
for (; ; ) {
V_7 = F_5 ( V_1 , V_10 , V_2 , V_9 , V_3 ) ;
if ( V_7 != 0 ) {
F_3 ( V_5 , V_11 ) ;
memset ( V_1 , 0 , ( unsigned int ) V_2 ) ;
return ( - 1 ) ;
}
V_8 = strlen ( V_1 ) ;
if ( V_8 < V_10 ) {
fprintf ( V_12 ,
L_2 ,
V_10 ) ;
} else
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
F_7 ( V_1 , L_7 , V_17 ) ;
F_7 ( V_1 , V_13 , V_17 ) ;
F_7 ( V_1 , L_8 , V_17 ) ;
}
void F_8 ( char * V_1 , const char * type , int V_18 , char * V_13 )
{
static const unsigned char V_19 [ 17 ] = L_9 ;
long V_7 ;
int V_8 ;
F_7 ( V_1 , L_10 , V_17 ) ;
F_7 ( V_1 , type , V_17 ) ;
F_7 ( V_1 , L_11 , V_17 ) ;
V_8 = strlen ( V_1 ) ;
if ( V_8 + ( V_18 * 2 ) + 1 > V_17 )
return;
for ( V_7 = 0 ; V_7 < V_18 ; V_7 ++ ) {
V_1 [ V_8 + V_7 * 2 ] = V_19 [ ( V_13 [ V_7 ] >> 4 ) & 0x0f ] ;
V_1 [ V_8 + V_7 * 2 + 1 ] = V_19 [ ( V_13 [ V_7 ] ) & 0x0f ] ;
}
V_1 [ V_8 + V_7 * 2 ] = '\n' ;
V_1 [ V_8 + V_7 * 2 + 1 ] = '\0' ;
}
void * F_9 ( T_1 * V_20 , const char * V_21 , T_2 * V_22 , void * * V_23 ,
T_3 * V_24 , void * V_25 )
{
T_4 * V_26 ;
void * V_27 ;
if ( ( V_26 = F_10 ( F_11 () ) ) == NULL ) {
F_3 ( V_28 , V_29 ) ;
return ( 0 ) ;
}
F_12 ( V_26 , V_22 , V_30 ) ;
V_27 = F_13 ( V_20 , V_21 , V_26 , V_23 , V_24 , V_25 ) ;
F_14 ( V_26 ) ;
return ( V_27 ) ;
}
static int F_15 ( const char * V_31 , const char * V_21 )
{
if ( ! strcmp ( V_31 , V_21 ) )
return 1 ;
if ( ! strcmp ( V_21 , V_32 ) ) {
int V_33 ;
const T_5 * V_34 ;
if ( ! strcmp ( V_31 , V_35 ) )
return 1 ;
if ( ! strcmp ( V_31 , V_36 ) )
return 1 ;
V_33 = F_16 ( V_31 , L_12 ) ;
if ( V_33 > 0 ) {
V_34 = F_17 ( NULL , V_31 , V_33 ) ;
if ( V_34 && V_34 -> V_37 )
return 1 ;
}
return 0 ;
}
if ( ! strcmp ( V_21 , V_38 ) ) {
int V_33 ;
const T_5 * V_34 ;
V_33 = F_16 ( V_31 , L_13 ) ;
if ( V_33 > 0 ) {
T_6 * V_39 ;
V_34 = F_17 ( & V_39 , V_31 , V_33 ) ;
if ( V_34 ) {
int V_40 ;
if ( V_34 -> V_41 )
V_40 = 1 ;
else
V_40 = 0 ;
#ifndef F_18
if ( V_39 )
F_19 ( V_39 ) ;
#endif
return V_40 ;
}
}
return 0 ;
}
if ( ! strcmp ( V_31 , V_42 ) &&
! strcmp ( V_21 , V_43 ) )
return 1 ;
if ( ! strcmp ( V_31 , V_44 ) && ! strcmp ( V_21 , V_45 ) )
return 1 ;
if ( ! strcmp ( V_31 , V_46 ) &&
! strcmp ( V_21 , V_47 ) )
return 1 ;
if ( ! strcmp ( V_31 , V_45 ) &&
! strcmp ( V_21 , V_48 ) )
return 1 ;
if ( ! strcmp ( V_31 , V_44 ) &&
! strcmp ( V_21 , V_48 ) )
return 1 ;
if ( ! strcmp ( V_31 , V_45 ) && ! strcmp ( V_21 , V_49 ) )
return 1 ;
if ( ! strcmp ( V_31 , V_50 ) &&
! strcmp ( V_21 , V_49 ) )
return 1 ;
#ifndef F_20
if ( ! strcmp ( V_31 , V_45 ) && ! strcmp ( V_21 , V_51 ) )
return 1 ;
if ( ! strcmp ( V_31 , V_49 ) && ! strcmp ( V_21 , V_51 ) )
return 1 ;
#endif
return 0 ;
}
int F_21 ( unsigned char * * V_52 , long * V_53 , char * * V_54 ,
const char * V_21 , T_4 * V_55 , T_3 * V_24 ,
void * V_25 )
{
T_7 V_56 ;
char * V_31 = NULL , * V_57 = NULL ;
unsigned char * V_58 = NULL ;
long V_18 ;
int V_27 = 0 ;
for (; ; ) {
if ( ! F_22 ( V_55 , & V_31 , & V_57 , & V_58 , & V_18 ) ) {
if ( F_23 ( F_24 () ) == V_59 )
F_25 ( 2 , L_14 , V_21 ) ;
return 0 ;
}
if ( F_15 ( V_31 , V_21 ) )
break;
F_26 ( V_31 ) ;
F_26 ( V_57 ) ;
F_26 ( V_58 ) ;
}
if ( ! F_27 ( V_57 , & V_56 ) )
goto V_60;
if ( ! F_28 ( & V_56 , V_58 , & V_18 , V_24 , V_25 ) )
goto V_60;
* V_52 = V_58 ;
* V_53 = V_18 ;
if ( V_54 )
* V_54 = V_31 ;
V_27 = 1 ;
V_60:
if ( ! V_27 || ! V_54 )
F_26 ( V_31 ) ;
F_26 ( V_57 ) ;
if ( ! V_27 )
F_26 ( V_58 ) ;
return V_27 ;
}
int F_29 ( T_8 * V_61 , const char * V_21 , T_2 * V_22 ,
void * V_23 , const T_9 * V_62 , unsigned char * V_63 ,
int V_64 , T_3 * V_65 , void * V_25 )
{
T_4 * V_26 ;
int V_27 ;
if ( ( V_26 = F_10 ( F_11 () ) ) == NULL ) {
F_3 ( V_66 , V_29 ) ;
return ( 0 ) ;
}
F_12 ( V_26 , V_22 , V_30 ) ;
V_27 = F_30 ( V_61 , V_21 , V_26 , V_23 , V_62 , V_63 , V_64 , V_65 , V_25 ) ;
F_14 ( V_26 ) ;
return ( V_27 ) ;
}
int F_30 ( T_8 * V_61 , const char * V_21 , T_4 * V_55 ,
void * V_23 , const T_9 * V_62 , unsigned char * V_63 ,
int V_64 , T_3 * V_65 , void * V_25 )
{
T_10 V_67 ;
int V_68 = 0 , V_7 , V_8 , V_27 = 0 ;
unsigned char * V_69 , * V_58 = NULL ;
const char * V_70 = NULL ;
char V_1 [ V_17 ] ;
unsigned char V_4 [ V_71 ] ;
unsigned char V_72 [ V_73 ] ;
if ( V_62 != NULL ) {
V_70 = F_31 ( F_32 ( V_62 ) ) ;
if ( V_70 == NULL ) {
F_3 ( V_74 , V_75 ) ;
goto V_60;
}
}
if ( ( V_68 = V_61 ( V_23 , NULL ) ) < 0 ) {
F_3 ( V_74 , V_76 ) ;
V_68 = 0 ;
goto V_60;
}
V_58 = ( unsigned char * ) F_33 ( ( unsigned int ) V_68 + 20 ) ;
if ( V_58 == NULL ) {
F_3 ( V_74 , V_77 ) ;
goto V_60;
}
V_69 = V_58 ;
V_7 = V_61 ( V_23 , & V_69 ) ;
if ( V_62 != NULL ) {
if ( V_63 == NULL ) {
if ( V_65 == NULL )
V_64 = F_1 ( V_1 , V_17 , 1 , V_25 ) ;
else
V_64 = (* V_65) ( V_1 , V_17 , 1 , V_25 ) ;
if ( V_64 <= 0 ) {
F_3 ( V_74 , V_78 ) ;
goto V_60;
}
#ifdef F_34
F_35 ( V_1 , V_1 , V_64 ) ;
#endif
V_63 = ( unsigned char * ) V_1 ;
}
F_36 ( V_58 , V_7 , 0 ) ;
F_37 ( V_62 -> V_79 <= ( int ) sizeof( V_72 ) ) ;
if ( F_38 ( V_72 , V_62 -> V_79 ) < 0 )
goto V_60;
if ( ! F_39 ( V_62 , F_40 () , V_72 , V_63 , V_64 , 1 , V_4 , NULL ) )
goto V_60;
if ( V_63 == ( unsigned char * ) V_1 )
F_41 ( V_1 , V_17 ) ;
F_37 ( strlen ( V_70 ) + 23 + 2 * V_62 -> V_79 + 13 <=
sizeof V_1 ) ;
V_1 [ 0 ] = '\0' ;
F_6 ( V_1 , V_14 ) ;
F_8 ( V_1 , V_70 , V_62 -> V_79 , ( char * ) V_72 ) ;
F_42 ( & V_67 ) ;
V_27 = 1 ;
if ( ! F_43 ( & V_67 , V_62 , NULL , V_4 , V_72 )
|| ! F_44 ( & V_67 , V_58 , & V_8 , V_58 , V_7 )
|| ! F_45 ( & V_67 , & ( V_58 [ V_8 ] ) , & V_7 ) )
V_27 = 0 ;
F_46 ( & V_67 ) ;
if ( V_27 == 0 )
goto V_60;
V_7 += V_8 ;
} else {
V_27 = 1 ;
V_1 [ 0 ] = '\0' ;
}
V_7 = F_47 ( V_55 , V_21 , V_1 , V_58 , V_7 ) ;
if ( V_7 <= 0 )
V_27 = 0 ;
V_60:
F_41 ( V_4 , sizeof( V_4 ) ) ;
F_41 ( V_72 , sizeof( V_72 ) ) ;
F_41 ( ( char * ) & V_67 , sizeof( V_67 ) ) ;
F_41 ( V_1 , V_17 ) ;
if ( V_58 != NULL ) {
F_41 ( V_58 , ( unsigned int ) V_68 ) ;
F_26 ( V_58 ) ;
}
return ( V_27 ) ;
}
int F_28 ( T_7 * V_56 , unsigned char * V_58 , long * V_53 ,
T_3 * V_65 , void * V_25 )
{
int V_7 = 0 , V_8 , V_80 , V_64 ;
long V_18 ;
T_10 V_67 ;
unsigned char V_4 [ V_71 ] ;
char V_1 [ V_17 ] ;
V_18 = * V_53 ;
if ( V_56 -> V_56 == NULL )
return ( 1 ) ;
if ( V_65 == NULL )
V_64 = F_1 ( V_1 , V_17 , 0 , V_25 ) ;
else
V_64 = V_65 ( V_1 , V_17 , 0 , V_25 ) ;
if ( V_64 <= 0 ) {
F_3 ( V_81 , V_82 ) ;
return ( 0 ) ;
}
#ifdef F_34
F_35 ( V_1 , V_1 , V_64 ) ;
#endif
if ( ! F_39 ( V_56 -> V_56 , F_40 () , & ( V_56 -> V_72 [ 0 ] ) ,
( unsigned char * ) V_1 , V_64 , 1 , V_4 , NULL ) )
return 0 ;
V_8 = ( int ) V_18 ;
F_42 ( & V_67 ) ;
V_80 = F_48 ( & V_67 , V_56 -> V_56 , NULL , V_4 , & ( V_56 -> V_72 [ 0 ] ) ) ;
if ( V_80 )
V_80 = F_49 ( & V_67 , V_58 , & V_7 , V_58 , V_8 ) ;
if ( V_80 )
V_80 = F_50 ( & V_67 , & ( V_58 [ V_7 ] ) , & V_8 ) ;
F_46 ( & V_67 ) ;
F_41 ( ( char * ) V_1 , sizeof( V_1 ) ) ;
F_41 ( ( char * ) V_4 , sizeof( V_4 ) ) ;
if ( V_80 )
V_8 += V_7 ;
else {
F_3 ( V_81 , V_83 ) ;
return ( 0 ) ;
}
* V_53 = V_8 ;
return ( 1 ) ;
}
int F_27 ( char * V_57 , T_7 * V_56 )
{
const T_9 * V_62 = NULL ;
char * V_69 , V_84 ;
char * * V_85 = & V_57 ;
V_56 -> V_56 = NULL ;
if ( ( V_57 == NULL ) || ( * V_57 == '\0' ) || ( * V_57 == '\n' ) )
return ( 1 ) ;
if ( strncmp ( V_57 , L_15 , 11 ) != 0 ) {
F_3 ( V_86 , V_87 ) ;
return ( 0 ) ;
}
V_57 += 11 ;
if ( * V_57 != '4' )
return ( 0 ) ;
V_57 ++ ;
if ( * V_57 != ',' )
return ( 0 ) ;
V_57 ++ ;
if ( strncmp ( V_57 , L_3 , 9 ) != 0 ) {
F_3 ( V_86 , V_88 ) ;
return ( 0 ) ;
}
for (; ( * V_57 != '\n' ) && ( * V_57 != '\0' ) ; V_57 ++ ) ;
if ( * V_57 == '\0' ) {
F_3 ( V_86 , V_89 ) ;
return ( 0 ) ;
}
V_57 ++ ;
if ( strncmp ( V_57 , L_10 , 10 ) != 0 ) {
F_3 ( V_86 , V_90 ) ;
return ( 0 ) ;
}
V_57 += 10 ;
V_69 = V_57 ;
for (; ; ) {
V_84 = * V_57 ;
#ifndef F_34
if ( ! ( ( ( V_84 >= 'A' ) && ( V_84 <= 'Z' ) ) || ( V_84 == '-' ) ||
( ( V_84 >= '0' ) && ( V_84 <= '9' ) ) ) )
break;
#else
if ( ! ( isupper ( V_84 ) || ( V_84 == '-' ) || isdigit ( V_84 ) ) )
break;
#endif
V_57 ++ ;
}
* V_57 = '\0' ;
V_56 -> V_56 = V_62 = F_51 ( V_69 ) ;
* V_57 = V_84 ;
V_57 ++ ;
if ( V_62 == NULL ) {
F_3 ( V_86 , V_91 ) ;
return ( 0 ) ;
}
if ( ! F_52 ( V_85 , & ( V_56 -> V_72 [ 0 ] ) , V_62 -> V_79 ) )
return ( 0 ) ;
return ( 1 ) ;
}
static int F_52 ( char * * V_92 , unsigned char * V_93 , int V_2 )
{
int V_94 , V_7 ;
char * V_95 ;
V_95 = * V_92 ;
for ( V_7 = 0 ; V_7 < V_2 ; V_7 ++ )
V_93 [ V_7 ] = 0 ;
V_2 *= 2 ;
for ( V_7 = 0 ; V_7 < V_2 ; V_7 ++ ) {
if ( ( * V_95 >= '0' ) && ( * V_95 <= '9' ) )
V_94 = * V_95 - '0' ;
else if ( ( * V_95 >= 'A' ) && ( * V_95 <= 'F' ) )
V_94 = * V_95 - 'A' + 10 ;
else if ( ( * V_95 >= 'a' ) && ( * V_95 <= 'f' ) )
V_94 = * V_95 - 'a' + 10 ;
else {
F_3 ( V_96 , V_97 ) ;
return ( 0 ) ;
}
V_95 ++ ;
V_93 [ V_7 / 2 ] |= V_94 << ( long ) ( ( ! ( V_7 & 1 ) ) * 4 ) ;
}
* V_92 = V_95 ;
return ( 1 ) ;
}
int F_53 ( T_2 * V_22 , const char * V_21 , const char * V_57 ,
const unsigned char * V_58 , long V_18 )
{
T_4 * V_26 ;
int V_27 ;
if ( ( V_26 = F_10 ( F_11 () ) ) == NULL ) {
F_3 ( V_98 , V_29 ) ;
return ( 0 ) ;
}
F_12 ( V_26 , V_22 , V_30 ) ;
V_27 = F_47 ( V_26 , V_21 , V_57 , V_58 , V_18 ) ;
F_14 ( V_26 ) ;
return ( V_27 ) ;
}
int F_47 ( T_4 * V_55 , const char * V_21 , const char * V_57 ,
const unsigned char * V_58 , long V_18 )
{
int V_99 , V_100 , V_7 , V_8 , V_101 ;
unsigned char * V_1 = NULL ;
T_11 V_67 ;
int V_102 = V_29 ;
F_54 ( & V_67 ) ;
V_99 = strlen ( V_21 ) ;
if ( ( F_55 ( V_55 , L_16 , 11 ) != 11 ) ||
( F_55 ( V_55 , V_21 , V_99 ) != V_99 ) ||
( F_55 ( V_55 , L_17 , 6 ) != 6 ) )
goto V_60;
V_7 = strlen ( V_57 ) ;
if ( V_7 > 0 ) {
if ( ( F_55 ( V_55 , V_57 , V_7 ) != V_7 ) || ( F_55 ( V_55 , L_8 , 1 ) != 1 ) )
goto V_60;
}
V_1 = F_33 ( V_17 * 8 ) ;
if ( V_1 == NULL ) {
V_102 = V_77 ;
goto V_60;
}
V_7 = V_8 = 0 ;
while ( V_18 > 0 ) {
V_100 = ( int ) ( ( V_18 > ( V_17 * 5 ) ) ? ( V_17 * 5 ) : V_18 ) ;
F_56 ( & V_67 , V_1 , & V_101 , & ( V_58 [ V_8 ] ) , V_100 ) ;
if ( ( V_101 ) && ( F_55 ( V_55 , ( char * ) V_1 , V_101 ) != V_101 ) )
goto V_60;
V_7 += V_101 ;
V_18 -= V_100 ;
V_8 += V_100 ;
}
F_57 ( & V_67 , V_1 , & V_101 ) ;
if ( ( V_101 > 0 ) && ( F_55 ( V_55 , ( char * ) V_1 , V_101 ) != V_101 ) )
goto V_60;
F_41 ( V_1 , V_17 * 8 ) ;
F_26 ( V_1 ) ;
V_1 = NULL ;
if ( ( F_55 ( V_55 , L_18 , 9 ) != 9 ) ||
( F_55 ( V_55 , V_21 , V_99 ) != V_99 ) ||
( F_55 ( V_55 , L_17 , 6 ) != 6 ) )
goto V_60;
return ( V_7 + V_101 ) ;
V_60:
if ( V_1 ) {
F_41 ( V_1 , V_17 * 8 ) ;
F_26 ( V_1 ) ;
}
F_3 ( V_103 , V_102 ) ;
return ( 0 ) ;
}
int F_58 ( T_2 * V_22 , char * * V_21 , char * * V_57 , unsigned char * * V_58 ,
long * V_18 )
{
T_4 * V_26 ;
int V_27 ;
if ( ( V_26 = F_10 ( F_11 () ) ) == NULL ) {
F_3 ( V_104 , V_29 ) ;
return ( 0 ) ;
}
F_12 ( V_26 , V_22 , V_30 ) ;
V_27 = F_22 ( V_26 , V_21 , V_57 , V_58 , V_18 ) ;
F_14 ( V_26 ) ;
return ( V_27 ) ;
}
int F_22 ( T_4 * V_55 , char * * V_21 , char * * V_57 , unsigned char * * V_58 ,
long * V_18 )
{
T_11 V_67 ;
int V_105 = 0 , V_7 , V_106 , V_107 = 0 , V_108 = 0 , V_109 = 0 ;
char V_1 [ 256 ] ;
T_12 * V_110 ;
T_12 * V_111 ;
T_12 * V_112 , * V_113 ;
V_110 = F_59 () ;
V_111 = F_59 () ;
V_112 = F_59 () ;
if ( ( V_110 == NULL ) || ( V_111 == NULL ) || ( V_112 == NULL ) ) {
F_60 ( V_110 ) ;
F_60 ( V_111 ) ;
F_60 ( V_112 ) ;
F_3 ( V_114 , V_77 ) ;
return ( 0 ) ;
}
V_1 [ 254 ] = '\0' ;
for (; ; ) {
V_7 = F_61 ( V_55 , V_1 , 254 ) ;
if ( V_7 <= 0 ) {
F_3 ( V_114 , V_59 ) ;
goto V_60;
}
while ( ( V_7 >= 0 ) && ( V_1 [ V_7 ] <= ' ' ) )
V_7 -- ;
V_1 [ ++ V_7 ] = '\n' ;
V_1 [ ++ V_7 ] = '\0' ;
if ( strncmp ( V_1 , L_16 , 11 ) == 0 ) {
V_7 = strlen ( & ( V_1 [ 11 ] ) ) ;
if ( strncmp ( & ( V_1 [ 11 + V_7 - 6 ] ) , L_17 , 6 ) != 0 )
continue;
if ( ! F_62 ( V_110 , V_7 + 9 ) ) {
F_3 ( V_114 , V_77 ) ;
goto V_60;
}
memcpy ( V_110 -> V_58 , & ( V_1 [ 11 ] ) , V_7 - 6 ) ;
V_110 -> V_58 [ V_7 - 6 ] = '\0' ;
break;
}
}
V_108 = 0 ;
if ( ! F_62 ( V_111 , 256 ) ) {
F_3 ( V_114 , V_77 ) ;
goto V_60;
}
V_111 -> V_58 [ 0 ] = '\0' ;
for (; ; ) {
V_7 = F_61 ( V_55 , V_1 , 254 ) ;
if ( V_7 <= 0 )
break;
while ( ( V_7 >= 0 ) && ( V_1 [ V_7 ] <= ' ' ) )
V_7 -- ;
V_1 [ ++ V_7 ] = '\n' ;
V_1 [ ++ V_7 ] = '\0' ;
if ( V_1 [ 0 ] == '\n' )
break;
if ( ! F_62 ( V_111 , V_108 + V_7 + 9 ) ) {
F_3 ( V_114 , V_77 ) ;
goto V_60;
}
if ( strncmp ( V_1 , L_18 , 9 ) == 0 ) {
V_109 = 1 ;
break;
}
memcpy ( & ( V_111 -> V_58 [ V_108 ] ) , V_1 , V_7 ) ;
V_111 -> V_58 [ V_108 + V_7 ] = '\0' ;
V_108 += V_7 ;
}
V_107 = 0 ;
if ( ! F_62 ( V_112 , 1024 ) ) {
F_3 ( V_114 , V_77 ) ;
goto V_60;
}
V_112 -> V_58 [ 0 ] = '\0' ;
if ( ! V_109 ) {
for (; ; ) {
V_7 = F_61 ( V_55 , V_1 , 254 ) ;
if ( V_7 <= 0 )
break;
while ( ( V_7 >= 0 ) && ( V_1 [ V_7 ] <= ' ' ) )
V_7 -- ;
V_1 [ ++ V_7 ] = '\n' ;
V_1 [ ++ V_7 ] = '\0' ;
if ( V_7 != 65 )
V_105 = 1 ;
if ( strncmp ( V_1 , L_18 , 9 ) == 0 )
break;
if ( V_7 > 65 )
break;
if ( ! F_63 ( V_112 , V_7 + V_107 + 9 ) ) {
F_3 ( V_114 , V_77 ) ;
goto V_60;
}
memcpy ( & ( V_112 -> V_58 [ V_107 ] ) , V_1 , V_7 ) ;
V_112 -> V_58 [ V_107 + V_7 ] = '\0' ;
V_107 += V_7 ;
if ( V_105 ) {
V_1 [ 0 ] = '\0' ;
V_7 = F_61 ( V_55 , V_1 , 254 ) ;
if ( V_7 <= 0 )
break;
while ( ( V_7 >= 0 ) && ( V_1 [ V_7 ] <= ' ' ) )
V_7 -- ;
V_1 [ ++ V_7 ] = '\n' ;
V_1 [ ++ V_7 ] = '\0' ;
break;
}
}
} else {
V_113 = V_111 ;
V_111 = V_112 ;
V_112 = V_113 ;
V_107 = V_108 ;
}
V_7 = strlen ( V_110 -> V_58 ) ;
if ( ( strncmp ( V_1 , L_18 , 9 ) != 0 ) ||
( strncmp ( V_110 -> V_58 , & ( V_1 [ 9 ] ) , V_7 ) != 0 ) ||
( strncmp ( & ( V_1 [ 9 + V_7 ] ) , L_17 , 6 ) != 0 ) ) {
F_3 ( V_114 , V_115 ) ;
goto V_60;
}
F_64 ( & V_67 ) ;
V_7 = F_65 ( & V_67 ,
( unsigned char * ) V_112 -> V_58 , & V_107 ,
( unsigned char * ) V_112 -> V_58 , V_107 ) ;
if ( V_7 < 0 ) {
F_3 ( V_114 , V_116 ) ;
goto V_60;
}
V_7 = F_66 ( & V_67 , ( unsigned char * ) & ( V_112 -> V_58 [ V_107 ] ) , & V_106 ) ;
if ( V_7 < 0 ) {
F_3 ( V_114 , V_116 ) ;
goto V_60;
}
V_107 += V_106 ;
if ( V_107 == 0 )
goto V_60;
* V_21 = V_110 -> V_58 ;
* V_57 = V_111 -> V_58 ;
* V_58 = ( unsigned char * ) V_112 -> V_58 ;
* V_18 = V_107 ;
F_26 ( V_110 ) ;
F_26 ( V_111 ) ;
F_26 ( V_112 ) ;
return ( 1 ) ;
V_60:
F_60 ( V_110 ) ;
F_60 ( V_111 ) ;
F_60 ( V_112 ) ;
return ( 0 ) ;
}
int F_16 ( const char * V_117 , const char * V_118 )
{
int V_119 = strlen ( V_117 ) ;
int V_120 = strlen ( V_118 ) ;
const char * V_69 ;
if ( V_120 + 1 >= V_119 )
return 0 ;
V_69 = V_117 + V_119 - V_120 ;
if ( strcmp ( V_69 , V_118 ) )
return 0 ;
V_69 -- ;
if ( * V_69 != ' ' )
return 0 ;
return V_69 - V_117 ;
}
