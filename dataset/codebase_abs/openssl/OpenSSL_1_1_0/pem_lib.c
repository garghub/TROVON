int F_1 ( char * V_1 , int V_2 , int V_3 , void * V_4 )
{
#if F_2 ( V_5 ) || F_2 ( V_6 )
int V_7 ;
#else
int V_7 , V_8 ;
const char * V_9 ;
#endif
if ( V_4 ) {
V_7 = strlen ( V_4 ) ;
V_7 = ( V_7 > V_2 ) ? V_2 : V_7 ;
memcpy ( V_1 , V_4 , V_7 ) ;
return V_7 ;
}
#if F_2 ( V_5 ) || F_2 ( V_6 )
F_3 ( V_10 , V_11 ) ;
return - 1 ;
#else
V_9 = F_4 () ;
if ( V_9 == NULL )
V_9 = L_1 ;
for (; ; ) {
int V_12 = V_3 ? V_13 : 0 ;
V_7 = F_5 ( V_1 , V_12 , V_2 , V_9 , V_3 ) ;
if ( V_7 != 0 ) {
F_3 ( V_10 , V_14 ) ;
memset ( V_1 , 0 , ( unsigned int ) V_2 ) ;
return - 1 ;
}
V_8 = strlen ( V_1 ) ;
if ( V_12 && V_8 < V_12 ) {
fprintf ( V_15 ,
L_2 ,
V_12 ) ;
} else
break;
}
return V_8 ;
#endif
}
void F_6 ( char * V_1 , int type )
{
const char * V_16 ;
if ( type == V_17 )
V_16 = L_3 ;
else if ( type == V_18 )
V_16 = L_4 ;
else if ( type == V_19 )
V_16 = L_5 ;
else
V_16 = L_6 ;
F_7 ( V_1 , L_7 , V_20 ) ;
F_7 ( V_1 , V_16 , V_20 ) ;
F_7 ( V_1 , L_8 , V_20 ) ;
}
void F_8 ( char * V_1 , const char * type , int V_21 , char * V_16 )
{
static const unsigned char V_22 [ 17 ] = L_9 ;
long V_7 ;
int V_8 ;
F_7 ( V_1 , L_10 , V_20 ) ;
F_7 ( V_1 , type , V_20 ) ;
F_7 ( V_1 , L_11 , V_20 ) ;
V_8 = strlen ( V_1 ) ;
if ( V_8 + ( V_21 * 2 ) + 1 > V_20 )
return;
for ( V_7 = 0 ; V_7 < V_21 ; V_7 ++ ) {
V_1 [ V_8 + V_7 * 2 ] = V_22 [ ( V_16 [ V_7 ] >> 4 ) & 0x0f ] ;
V_1 [ V_8 + V_7 * 2 + 1 ] = V_22 [ ( V_16 [ V_7 ] ) & 0x0f ] ;
}
V_1 [ V_8 + V_7 * 2 ] = '\n' ;
V_1 [ V_8 + V_7 * 2 + 1 ] = '\0' ;
}
void * F_9 ( T_1 * V_23 , const char * V_24 , T_2 * V_25 , void * * V_26 ,
T_3 * V_27 , void * V_28 )
{
T_4 * V_29 ;
void * V_30 ;
if ( ( V_29 = F_10 ( F_11 () ) ) == NULL ) {
F_3 ( V_31 , V_32 ) ;
return ( 0 ) ;
}
F_12 ( V_29 , V_25 , V_33 ) ;
V_30 = F_13 ( V_23 , V_24 , V_29 , V_26 , V_27 , V_28 ) ;
F_14 ( V_29 ) ;
return ( V_30 ) ;
}
static int F_15 ( const char * V_34 , const char * V_24 )
{
if ( strcmp ( V_34 , V_24 ) == 0 )
return 1 ;
if ( strcmp ( V_24 , V_35 ) == 0 ) {
int V_36 ;
const T_5 * V_37 ;
if ( strcmp ( V_34 , V_38 ) == 0 )
return 1 ;
if ( strcmp ( V_34 , V_39 ) == 0 )
return 1 ;
V_36 = F_16 ( V_34 , L_12 ) ;
if ( V_36 > 0 ) {
V_37 = F_17 ( NULL , V_34 , V_36 ) ;
if ( V_37 && V_37 -> V_40 )
return 1 ;
}
return 0 ;
}
if ( strcmp ( V_24 , V_41 ) == 0 ) {
int V_36 ;
const T_5 * V_37 ;
V_36 = F_16 ( V_34 , L_13 ) ;
if ( V_36 > 0 ) {
T_6 * V_42 ;
V_37 = F_17 ( & V_42 , V_34 , V_36 ) ;
if ( V_37 ) {
int V_43 ;
if ( V_37 -> V_44 )
V_43 = 1 ;
else
V_43 = 0 ;
#ifndef F_18
F_19 ( V_42 ) ;
#endif
return V_43 ;
}
}
return 0 ;
}
if ( strcmp ( V_34 , V_45 ) == 0
&& strcmp ( V_24 , V_46 ) == 0 )
return 1 ;
if ( strcmp ( V_34 , V_47 ) == 0
&& strcmp ( V_24 , V_48 ) == 0 )
return 1 ;
if ( strcmp ( V_34 , V_49 ) == 0
&& strcmp ( V_24 , V_50 ) == 0 )
return 1 ;
if ( strcmp ( V_34 , V_48 ) == 0
&& strcmp ( V_24 , V_51 ) == 0 )
return 1 ;
if ( strcmp ( V_34 , V_47 ) == 0
&& strcmp ( V_24 , V_51 ) == 0 )
return 1 ;
if ( strcmp ( V_34 , V_48 ) == 0
&& strcmp ( V_24 , V_52 ) == 0 )
return 1 ;
if ( strcmp ( V_34 , V_53 ) == 0
&& strcmp ( V_24 , V_52 ) == 0 )
return 1 ;
#ifndef F_20
if ( strcmp ( V_34 , V_48 ) == 0
&& strcmp ( V_24 , V_54 ) == 0 )
return 1 ;
if ( strcmp ( V_34 , V_52 ) == 0
&& strcmp ( V_24 , V_54 ) == 0 )
return 1 ;
#endif
return 0 ;
}
int F_21 ( unsigned char * * V_55 , long * V_56 , char * * V_57 ,
const char * V_24 , T_4 * V_58 , T_3 * V_27 ,
void * V_28 )
{
T_7 V_59 ;
char * V_34 = NULL , * V_60 = NULL ;
unsigned char * V_61 = NULL ;
long V_21 ;
int V_30 = 0 ;
for (; ; ) {
if ( ! F_22 ( V_58 , & V_34 , & V_60 , & V_61 , & V_21 ) ) {
if ( F_23 ( F_24 () ) == V_62 )
F_25 ( 2 , L_14 , V_24 ) ;
return 0 ;
}
if ( F_15 ( V_34 , V_24 ) )
break;
F_26 ( V_34 ) ;
F_26 ( V_60 ) ;
F_26 ( V_61 ) ;
}
if ( ! F_27 ( V_60 , & V_59 ) )
goto V_63;
if ( ! F_28 ( & V_59 , V_61 , & V_21 , V_27 , V_28 ) )
goto V_63;
* V_55 = V_61 ;
* V_56 = V_21 ;
if ( V_57 )
* V_57 = V_34 ;
V_30 = 1 ;
V_63:
if ( ! V_30 || ! V_57 )
F_26 ( V_34 ) ;
F_26 ( V_60 ) ;
if ( ! V_30 )
F_26 ( V_61 ) ;
return V_30 ;
}
int F_29 ( T_8 * V_64 , const char * V_24 , T_2 * V_25 ,
void * V_26 , const T_9 * V_65 , unsigned char * V_66 ,
int V_67 , T_3 * V_68 , void * V_28 )
{
T_4 * V_29 ;
int V_30 ;
if ( ( V_29 = F_10 ( F_11 () ) ) == NULL ) {
F_3 ( V_69 , V_32 ) ;
return ( 0 ) ;
}
F_12 ( V_29 , V_25 , V_33 ) ;
V_30 = F_30 ( V_64 , V_24 , V_29 , V_26 , V_65 , V_66 , V_67 , V_68 , V_28 ) ;
F_14 ( V_29 ) ;
return ( V_30 ) ;
}
int F_30 ( T_8 * V_64 , const char * V_24 , T_4 * V_58 ,
void * V_26 , const T_9 * V_65 , unsigned char * V_66 ,
int V_67 , T_3 * V_68 , void * V_28 )
{
T_10 * V_70 = NULL ;
int V_71 = 0 , V_7 = 0 , V_8 = 0 , V_30 = 0 ;
unsigned char * V_72 , * V_61 = NULL ;
const char * V_73 = NULL ;
char V_1 [ V_20 ] ;
unsigned char V_4 [ V_74 ] ;
unsigned char V_75 [ V_76 ] ;
if ( V_65 != NULL ) {
V_73 = F_31 ( F_32 ( V_65 ) ) ;
if ( V_73 == NULL || F_33 ( V_65 ) == 0 ) {
F_3 ( V_77 , V_78 ) ;
goto V_63;
}
}
if ( ( V_71 = V_64 ( V_26 , NULL ) ) < 0 ) {
F_3 ( V_77 , V_79 ) ;
V_71 = 0 ;
goto V_63;
}
V_61 = F_34 ( ( unsigned int ) V_71 + 20 ) ;
if ( V_61 == NULL ) {
F_3 ( V_77 , V_80 ) ;
goto V_63;
}
V_72 = V_61 ;
V_7 = V_64 ( V_26 , & V_72 ) ;
if ( V_65 != NULL ) {
if ( V_66 == NULL ) {
if ( V_68 == NULL )
V_67 = F_1 ( V_1 , V_20 , 1 , V_28 ) ;
else
V_67 = (* V_68) ( V_1 , V_20 , 1 , V_28 ) ;
if ( V_67 <= 0 ) {
F_3 ( V_77 , V_81 ) ;
goto V_63;
}
#ifdef F_35
F_36 ( V_1 , V_1 , V_67 ) ;
#endif
V_66 = ( unsigned char * ) V_1 ;
}
F_37 ( V_61 , V_7 , 0 ) ;
F_38 ( F_33 ( V_65 ) <= ( int ) sizeof( V_75 ) ) ;
if ( F_39 ( V_75 , F_33 ( V_65 ) ) <= 0 )
goto V_63;
if ( ! F_40 ( V_65 , F_41 () , V_75 , V_66 , V_67 , 1 , V_4 , NULL ) )
goto V_63;
if ( V_66 == ( unsigned char * ) V_1 )
F_42 ( V_1 , V_20 ) ;
F_38 ( strlen ( V_73 ) + 23 + 2 * F_33 ( V_65 ) + 13
<= sizeof V_1 ) ;
V_1 [ 0 ] = '\0' ;
F_6 ( V_1 , V_17 ) ;
F_8 ( V_1 , V_73 , F_33 ( V_65 ) , ( char * ) V_75 ) ;
V_30 = 1 ;
if ( ( V_70 = F_43 () ) == NULL
|| ! F_44 ( V_70 , V_65 , NULL , V_4 , V_75 )
|| ! F_45 ( V_70 , V_61 , & V_8 , V_61 , V_7 )
|| ! F_46 ( V_70 , & ( V_61 [ V_8 ] ) , & V_7 ) )
V_30 = 0 ;
if ( V_30 == 0 )
goto V_63;
V_7 += V_8 ;
} else {
V_30 = 1 ;
V_1 [ 0 ] = '\0' ;
}
V_7 = F_47 ( V_58 , V_24 , V_1 , V_61 , V_7 ) ;
if ( V_7 <= 0 )
V_30 = 0 ;
V_63:
F_42 ( V_4 , sizeof( V_4 ) ) ;
F_42 ( V_75 , sizeof( V_75 ) ) ;
F_48 ( V_70 ) ;
F_42 ( V_1 , V_20 ) ;
F_49 ( V_61 , ( unsigned int ) V_71 ) ;
return ( V_30 ) ;
}
int F_28 ( T_7 * V_59 , unsigned char * V_61 , long * V_56 ,
T_3 * V_68 , void * V_28 )
{
int V_82 ;
int V_83 ;
long V_21 = * V_56 ;
int V_84 = ( int ) V_21 ;
T_10 * V_70 ;
unsigned char V_4 [ V_74 ] ;
char V_1 [ V_20 ] ;
#if V_85 > V_86
if ( V_21 > V_86 ) {
F_3 ( V_87 , V_88 ) ;
return 0 ;
}
#endif
if ( V_59 -> V_59 == NULL )
return 1 ;
if ( V_68 == NULL )
V_83 = F_1 ( V_1 , V_20 , 0 , V_28 ) ;
else
V_83 = V_68 ( V_1 , V_20 , 0 , V_28 ) ;
if ( V_83 <= 0 ) {
F_3 ( V_87 , V_89 ) ;
return 0 ;
}
#ifdef F_35
F_36 ( V_1 , V_1 , V_83 ) ;
#endif
if ( ! F_40 ( V_59 -> V_59 , F_41 () , & ( V_59 -> V_75 [ 0 ] ) ,
( unsigned char * ) V_1 , V_83 , 1 , V_4 , NULL ) )
return 0 ;
V_70 = F_43 () ;
if ( V_70 == NULL )
return 0 ;
V_82 = F_50 ( V_70 , V_59 -> V_59 , NULL , V_4 , & ( V_59 -> V_75 [ 0 ] ) ) ;
if ( V_82 )
V_82 = F_51 ( V_70 , V_61 , & V_84 , V_61 , V_84 ) ;
if ( V_82 ) {
* V_56 = V_84 ;
V_82 = F_52 ( V_70 , & ( V_61 [ V_84 ] ) , & V_84 ) ;
}
if ( V_82 )
* V_56 += V_84 ;
else
F_3 ( V_87 , V_90 ) ;
F_48 ( V_70 ) ;
F_42 ( ( char * ) V_1 , sizeof( V_1 ) ) ;
F_42 ( ( char * ) V_4 , sizeof( V_4 ) ) ;
return V_82 ;
}
int F_27 ( char * V_60 , T_7 * V_59 )
{
static const char V_91 [] = L_15 ;
static const char V_92 [] = L_3 ;
static const char V_93 [] = L_16 ;
const T_9 * V_65 = NULL ;
int V_94 ;
char * V_95 , V_96 ;
V_59 -> V_59 = NULL ;
if ( ( V_60 == NULL ) || ( * V_60 == '\0' ) || ( * V_60 == '\n' ) )
return 1 ;
if ( strncmp ( V_60 , V_91 , sizeof( V_91 ) - 1 ) != 0 ) {
F_3 ( V_97 , V_98 ) ;
return 0 ;
}
V_60 += sizeof( V_91 ) - 1 ;
V_60 += strspn ( V_60 , L_17 ) ;
if ( * V_60 ++ != '4' || * V_60 ++ != ',' )
return 0 ;
V_60 += strspn ( V_60 , L_17 ) ;
if ( strncmp ( V_60 , V_92 , sizeof( V_92 ) - 1 ) != 0 ||
strspn ( V_60 + sizeof( V_92 ) - 1 , L_18 ) == 0 ) {
F_3 ( V_97 , V_99 ) ;
return 0 ;
}
V_60 += sizeof( V_92 ) - 1 ;
V_60 += strspn ( V_60 , L_19 ) ;
if ( * V_60 ++ != '\n' ) {
F_3 ( V_97 , V_100 ) ;
return 0 ;
}
if ( strncmp ( V_60 , V_93 , sizeof( V_93 ) - 1 ) != 0 ) {
F_3 ( V_97 , V_101 ) ;
return 0 ;
}
V_60 += sizeof( V_93 ) - 1 ;
V_60 += strspn ( V_60 , L_17 ) ;
V_95 = V_60 ;
V_60 += strcspn ( V_60 , L_20 ) ;
V_96 = * V_60 ;
* V_60 = '\0' ;
V_59 -> V_59 = V_65 = F_53 ( V_95 ) ;
* V_60 = V_96 ;
V_60 += strspn ( V_60 , L_17 ) ;
if ( V_65 == NULL ) {
F_3 ( V_97 , V_102 ) ;
return 0 ;
}
V_94 = F_33 ( V_65 ) ;
if ( V_94 > 0 && * V_60 ++ != ',' ) {
F_3 ( V_97 , V_103 ) ;
return 0 ;
} else if ( V_94 == 0 && * V_60 == ',' ) {
F_3 ( V_97 , V_104 ) ;
return 0 ;
}
if ( ! F_54 ( & V_60 , V_59 -> V_75 , F_33 ( V_65 ) ) )
return 0 ;
return 1 ;
}
static int F_54 ( char * * V_105 , unsigned char * V_106 , int V_2 )
{
int V_107 , V_7 ;
char * V_108 ;
V_108 = * V_105 ;
for ( V_7 = 0 ; V_7 < V_2 ; V_7 ++ )
V_106 [ V_7 ] = 0 ;
V_2 *= 2 ;
for ( V_7 = 0 ; V_7 < V_2 ; V_7 ++ ) {
V_107 = F_55 ( * V_108 ) ;
if ( V_107 < 0 ) {
F_3 ( V_109 , V_110 ) ;
return ( 0 ) ;
}
V_108 ++ ;
V_106 [ V_7 / 2 ] |= V_107 << ( long ) ( ( ! ( V_7 & 1 ) ) * 4 ) ;
}
* V_105 = V_108 ;
return ( 1 ) ;
}
int F_56 ( T_2 * V_25 , const char * V_24 , const char * V_60 ,
const unsigned char * V_61 , long V_21 )
{
T_4 * V_29 ;
int V_30 ;
if ( ( V_29 = F_10 ( F_11 () ) ) == NULL ) {
F_3 ( V_111 , V_32 ) ;
return ( 0 ) ;
}
F_12 ( V_29 , V_25 , V_33 ) ;
V_30 = F_47 ( V_29 , V_24 , V_60 , V_61 , V_21 ) ;
F_14 ( V_29 ) ;
return ( V_30 ) ;
}
int F_47 ( T_4 * V_58 , const char * V_24 , const char * V_60 ,
const unsigned char * V_61 , long V_21 )
{
int V_112 , V_113 , V_7 , V_8 , V_114 ;
unsigned char * V_1 = NULL ;
T_11 * V_70 = F_57 () ;
int V_115 = V_32 ;
if ( V_70 == NULL ) {
V_115 = V_80 ;
goto V_63;
}
F_58 ( V_70 ) ;
V_112 = strlen ( V_24 ) ;
if ( ( F_59 ( V_58 , L_21 , 11 ) != 11 ) ||
( F_59 ( V_58 , V_24 , V_112 ) != V_112 ) ||
( F_59 ( V_58 , L_22 , 6 ) != 6 ) )
goto V_63;
V_7 = strlen ( V_60 ) ;
if ( V_7 > 0 ) {
if ( ( F_59 ( V_58 , V_60 , V_7 ) != V_7 ) || ( F_59 ( V_58 , L_8 , 1 ) != 1 ) )
goto V_63;
}
V_1 = F_34 ( V_20 * 8 ) ;
if ( V_1 == NULL ) {
V_115 = V_80 ;
goto V_63;
}
V_7 = V_8 = 0 ;
while ( V_21 > 0 ) {
V_113 = ( int ) ( ( V_21 > ( V_20 * 5 ) ) ? ( V_20 * 5 ) : V_21 ) ;
if ( ! F_60 ( V_70 , V_1 , & V_114 , & ( V_61 [ V_8 ] ) , V_113 ) )
goto V_63;
if ( ( V_114 ) && ( F_59 ( V_58 , ( char * ) V_1 , V_114 ) != V_114 ) )
goto V_63;
V_7 += V_114 ;
V_21 -= V_113 ;
V_8 += V_113 ;
}
F_61 ( V_70 , V_1 , & V_114 ) ;
if ( ( V_114 > 0 ) && ( F_59 ( V_58 , ( char * ) V_1 , V_114 ) != V_114 ) )
goto V_63;
if ( ( F_59 ( V_58 , L_23 , 9 ) != 9 ) ||
( F_59 ( V_58 , V_24 , V_112 ) != V_112 ) ||
( F_59 ( V_58 , L_22 , 6 ) != 6 ) )
goto V_63;
F_49 ( V_1 , V_20 * 8 ) ;
F_62 ( V_70 ) ;
return ( V_7 + V_114 ) ;
V_63:
F_49 ( V_1 , V_20 * 8 ) ;
F_62 ( V_70 ) ;
F_3 ( V_116 , V_115 ) ;
return ( 0 ) ;
}
int F_63 ( T_2 * V_25 , char * * V_24 , char * * V_60 , unsigned char * * V_61 ,
long * V_21 )
{
T_4 * V_29 ;
int V_30 ;
if ( ( V_29 = F_10 ( F_11 () ) ) == NULL ) {
F_3 ( V_117 , V_32 ) ;
return ( 0 ) ;
}
F_12 ( V_29 , V_25 , V_33 ) ;
V_30 = F_22 ( V_29 , V_24 , V_60 , V_61 , V_21 ) ;
F_14 ( V_29 ) ;
return ( V_30 ) ;
}
int F_22 ( T_4 * V_58 , char * * V_24 , char * * V_60 , unsigned char * * V_61 ,
long * V_21 )
{
T_11 * V_70 = F_57 () ;
int V_118 = 0 , V_7 , V_119 , V_120 = 0 , V_121 = 0 , V_122 = 0 ;
char V_1 [ 256 ] ;
T_12 * V_123 ;
T_12 * V_124 ;
T_12 * V_125 , * V_126 ;
if ( V_70 == NULL ) {
F_3 ( V_127 , V_80 ) ;
return ( 0 ) ;
}
V_123 = F_64 () ;
V_124 = F_64 () ;
V_125 = F_64 () ;
if ( ( V_123 == NULL ) || ( V_124 == NULL ) || ( V_125 == NULL ) ) {
goto V_63;
}
V_1 [ 254 ] = '\0' ;
for (; ; ) {
V_7 = F_65 ( V_58 , V_1 , 254 ) ;
if ( V_7 <= 0 ) {
F_3 ( V_127 , V_62 ) ;
goto V_63;
}
while ( ( V_7 >= 0 ) && ( V_1 [ V_7 ] <= ' ' ) )
V_7 -- ;
V_1 [ ++ V_7 ] = '\n' ;
V_1 [ ++ V_7 ] = '\0' ;
if ( strncmp ( V_1 , L_21 , 11 ) == 0 ) {
V_7 = strlen ( & ( V_1 [ 11 ] ) ) ;
if ( strncmp ( & ( V_1 [ 11 + V_7 - 6 ] ) , L_22 , 6 ) != 0 )
continue;
if ( ! F_66 ( V_123 , V_7 + 9 ) ) {
F_3 ( V_127 , V_80 ) ;
goto V_63;
}
memcpy ( V_123 -> V_61 , & ( V_1 [ 11 ] ) , V_7 - 6 ) ;
V_123 -> V_61 [ V_7 - 6 ] = '\0' ;
break;
}
}
V_121 = 0 ;
if ( ! F_66 ( V_124 , 256 ) ) {
F_3 ( V_127 , V_80 ) ;
goto V_63;
}
V_124 -> V_61 [ 0 ] = '\0' ;
for (; ; ) {
V_7 = F_65 ( V_58 , V_1 , 254 ) ;
if ( V_7 <= 0 )
break;
while ( ( V_7 >= 0 ) && ( V_1 [ V_7 ] <= ' ' ) )
V_7 -- ;
V_1 [ ++ V_7 ] = '\n' ;
V_1 [ ++ V_7 ] = '\0' ;
if ( V_1 [ 0 ] == '\n' )
break;
if ( ! F_66 ( V_124 , V_121 + V_7 + 9 ) ) {
F_3 ( V_127 , V_80 ) ;
goto V_63;
}
if ( strncmp ( V_1 , L_23 , 9 ) == 0 ) {
V_122 = 1 ;
break;
}
memcpy ( & ( V_124 -> V_61 [ V_121 ] ) , V_1 , V_7 ) ;
V_124 -> V_61 [ V_121 + V_7 ] = '\0' ;
V_121 += V_7 ;
}
V_120 = 0 ;
if ( ! F_66 ( V_125 , 1024 ) ) {
F_3 ( V_127 , V_80 ) ;
goto V_63;
}
V_125 -> V_61 [ 0 ] = '\0' ;
if ( ! V_122 ) {
for (; ; ) {
V_7 = F_65 ( V_58 , V_1 , 254 ) ;
if ( V_7 <= 0 )
break;
while ( ( V_7 >= 0 ) && ( V_1 [ V_7 ] <= ' ' ) )
V_7 -- ;
V_1 [ ++ V_7 ] = '\n' ;
V_1 [ ++ V_7 ] = '\0' ;
if ( V_7 != 65 )
V_118 = 1 ;
if ( strncmp ( V_1 , L_23 , 9 ) == 0 )
break;
if ( V_7 > 65 )
break;
if ( ! F_67 ( V_125 , V_7 + V_120 + 9 ) ) {
F_3 ( V_127 , V_80 ) ;
goto V_63;
}
memcpy ( & ( V_125 -> V_61 [ V_120 ] ) , V_1 , V_7 ) ;
V_125 -> V_61 [ V_120 + V_7 ] = '\0' ;
V_120 += V_7 ;
if ( V_118 ) {
V_1 [ 0 ] = '\0' ;
V_7 = F_65 ( V_58 , V_1 , 254 ) ;
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
V_126 = V_124 ;
V_124 = V_125 ;
V_125 = V_126 ;
V_120 = V_121 ;
}
V_7 = strlen ( V_123 -> V_61 ) ;
if ( ( strncmp ( V_1 , L_23 , 9 ) != 0 ) ||
( strncmp ( V_123 -> V_61 , & ( V_1 [ 9 ] ) , V_7 ) != 0 ) ||
( strncmp ( & ( V_1 [ 9 + V_7 ] ) , L_22 , 6 ) != 0 ) ) {
F_3 ( V_127 , V_128 ) ;
goto V_63;
}
F_68 ( V_70 ) ;
V_7 = F_69 ( V_70 ,
( unsigned char * ) V_125 -> V_61 , & V_120 ,
( unsigned char * ) V_125 -> V_61 , V_120 ) ;
if ( V_7 < 0 ) {
F_3 ( V_127 , V_129 ) ;
goto V_63;
}
V_7 = F_70 ( V_70 , ( unsigned char * ) & ( V_125 -> V_61 [ V_120 ] ) , & V_119 ) ;
if ( V_7 < 0 ) {
F_3 ( V_127 , V_129 ) ;
goto V_63;
}
V_120 += V_119 ;
if ( V_120 == 0 )
goto V_63;
* V_24 = V_123 -> V_61 ;
* V_60 = V_124 -> V_61 ;
* V_61 = ( unsigned char * ) V_125 -> V_61 ;
* V_21 = V_120 ;
F_26 ( V_123 ) ;
F_26 ( V_124 ) ;
F_26 ( V_125 ) ;
F_62 ( V_70 ) ;
return ( 1 ) ;
V_63:
F_71 ( V_123 ) ;
F_71 ( V_124 ) ;
F_71 ( V_125 ) ;
F_62 ( V_70 ) ;
return ( 0 ) ;
}
int F_16 ( const char * V_130 , const char * V_131 )
{
int V_132 = strlen ( V_130 ) ;
int V_133 = strlen ( V_131 ) ;
const char * V_72 ;
if ( V_133 + 1 >= V_132 )
return 0 ;
V_72 = V_130 + V_132 - V_133 ;
if ( strcmp ( V_72 , V_131 ) )
return 0 ;
V_72 -- ;
if ( * V_72 != ' ' )
return 0 ;
return V_72 - V_130 ;
}
