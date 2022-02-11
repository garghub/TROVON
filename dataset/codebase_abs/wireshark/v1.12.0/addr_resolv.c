static T_1
F_1 ( T_2 V_1 )
{
int V_2 = 16 ;
const unsigned char * V_3 = ( const unsigned char * ) V_1 ;
T_1 V_4 = 0 ;
int V_5 ;
for ( V_5 = 0 ; V_5 < V_2 ; V_5 ++ ) {
V_4 += V_3 [ V_5 ] ;
V_4 += ( V_4 << 10 ) ;
V_4 ^= ( V_4 >> 6 ) ;
}
V_4 += ( V_4 << 3 ) ;
V_4 ^= ( V_4 >> 11 ) ;
V_4 += ( V_4 << 15 ) ;
return V_4 ;
}
static T_3
F_2 ( T_2 V_6 , T_2 V_7 )
{
if( memcmp ( V_6 , V_7 , sizeof ( struct V_8 ) ) == 0 ) {
return TRUE ;
}
return FALSE ;
}
static void
F_3 ( int type , T_1 V_9 )
{
T_4 * V_10 ;
V_10 = F_4 ( T_4 , 1 ) ;
#ifdef F_5
V_10 -> V_11 = type ;
V_10 -> V_9 . V_12 = V_9 ;
#else
V_10 -> type = type ;
V_10 -> V_13 = V_9 ;
V_10 -> V_14 = FALSE ;
#endif
V_15 = F_6 ( V_15 , ( V_16 ) V_10 ) ;
}
static int
F_7 ( char * * V_17 , int * V_18 , T_5 * V_19 )
{
int V_2 ;
int V_20 ;
if ( V_19 == NULL || V_17 == NULL )
return - 1 ;
if ( * V_17 == NULL ) {
if ( * V_18 == 0 )
* V_18 = V_21 ;
* V_17 = ( char * ) F_8 ( * V_18 ) ;
}
F_9 ( * V_17 ) ;
F_9 ( * V_18 > 0 ) ;
if ( feof ( V_19 ) )
return - 1 ;
V_2 = 0 ;
while ( ( V_20 = getc ( V_19 ) ) != V_22 && V_20 != '\r' && V_20 != '\n' ) {
if ( V_2 + 1 >= * V_18 ) {
* V_17 = ( char * ) F_10 ( * V_17 , * V_18 += V_21 ) ;
}
( * V_17 ) [ V_2 ++ ] = V_20 ;
}
if ( V_2 == 0 && V_20 == V_22 )
return - 1 ;
( * V_17 ) [ V_2 ] = '\0' ;
return V_2 ;
}
static void
F_11 ( T_6 V_23 , const T_7 V_24 , const char * V_25 )
{
T_8 * V_26 ;
int * V_1 ;
V_1 = ( int * ) F_4 ( int , 1 ) ;
* V_1 = V_24 ;
V_26 = ( T_8 * ) F_12 ( V_27 , & V_24 ) ;
if ( V_26 == NULL ) {
V_26 = F_13 ( T_8 , 1 ) ;
F_14 ( V_27 , V_1 , V_26 ) ;
}
else {
F_15 ( V_1 ) ;
}
switch( V_23 ) {
case V_28 :
F_15 ( V_26 -> V_29 ) ;
V_26 -> V_29 = F_16 ( V_25 ) ;
break;
case V_30 :
F_15 ( V_26 -> V_31 ) ;
V_26 -> V_31 = F_16 ( V_25 ) ;
break;
case V_32 :
F_15 ( V_26 -> V_33 ) ;
V_26 -> V_33 = F_16 ( V_25 ) ;
break;
case V_34 :
F_15 ( V_26 -> V_35 ) ;
V_26 -> V_35 = F_16 ( V_25 ) ;
break;
default:
return;
}
V_36 = TRUE ;
}
static void
F_17 ( char * line )
{
T_9 * V_37 ;
T_9 * V_38 ;
T_9 * V_24 ;
T_6 V_23 ;
T_10 * V_39 = NULL ;
T_1 V_40 = V_41 ;
if ( ( V_37 = strchr ( line , '#' ) ) )
* V_37 = '\0' ;
if ( ( V_37 = strtok ( line , L_1 ) ) == NULL )
return;
V_38 = V_37 ;
if ( ( V_37 = strtok ( NULL , L_1 ) ) == NULL )
return;
V_24 = V_37 ;
if ( strtok ( V_37 , L_2 ) == NULL )
return;
if ( ( V_37 = strtok ( NULL , L_2 ) ) == NULL )
return;
if( strcmp ( V_37 , L_3 ) == 0 ) {
V_40 = V_42 ;
V_23 = V_28 ;
}
else if( strcmp ( V_37 , L_4 ) == 0 ) {
V_40 = V_41 ;
V_23 = V_30 ;
}
else if( strcmp ( V_37 , L_5 ) == 0 ) {
V_40 = V_43 ;
V_23 = V_32 ;
}
else if( strcmp ( V_37 , L_6 ) == 0 ) {
V_40 = V_44 ;
V_23 = V_34 ;
} else {
return;
}
if( V_45 != F_18 ( & V_39 , V_24 , V_40 ) ) {
return;
}
V_46 = V_38 ;
V_47 = V_23 ;
F_19 ( V_39 , V_48 ) ;
F_15 ( V_39 ) ;
V_47 = V_49 ;
}
static void
V_48 ( const T_1 V_24 )
{
if ( V_24 ) {
F_11 ( V_47 , V_24 , V_46 ) ;
}
}
static void
F_20 ( const char * V_50 )
{
T_5 * V_51 ;
static int V_18 = 0 ;
static char * V_17 = NULL ;
V_51 = F_21 ( V_50 , L_7 ) ;
if ( V_51 == NULL )
return;
while ( F_7 ( & V_17 , & V_18 , V_51 ) >= 0 ) {
F_17 ( V_17 ) ;
}
fclose ( V_51 ) ;
}
static T_9 *
F_22 ( T_7 V_24 )
{
T_9 * V_52 = ( T_9 * ) F_23 ( V_53 ) ;
F_24 ( V_24 , V_52 , V_53 ) ;
return V_52 ;
}
static T_9
* F_25 ( const T_7 V_24 , const T_6 V_23 )
{
T_8 * V_26 ;
T_9 * V_54 ;
V_26 = ( T_8 * ) F_12 ( V_27 , & V_24 ) ;
if( V_26 ) {
switch( V_23 ) {
case V_30 :
if( V_26 -> V_31 ) {
return V_26 -> V_31 ;
}
break;
case V_28 :
if( V_26 -> V_29 ) {
return V_26 -> V_29 ;
}
break;
case V_32 :
if( V_26 -> V_33 ) {
return V_26 -> V_33 ;
}
break;
case V_34 :
if( V_26 -> V_35 ) {
return V_26 -> V_35 ;
}
break;
default:
return NULL ;
}
}
V_54 = ( T_9 * ) F_8 ( 16 ) ;
F_24 ( V_24 , V_54 , 16 ) ;
if( V_26 == NULL ) {
int * V_1 ;
V_1 = ( int * ) F_4 ( int , 1 ) ;
* V_1 = V_24 ;
V_26 = F_13 ( T_8 , 1 ) ;
F_14 ( V_27 , V_1 , V_26 ) ;
}
switch( V_23 ) {
case V_30 :
V_26 -> V_31 = V_54 ;
break;
case V_28 :
V_26 -> V_29 = V_54 ;
break;
case V_32 :
V_26 -> V_33 = V_54 ;
break;
case V_34 :
V_26 -> V_35 = V_54 ;
break;
default:
return NULL ;
}
return V_54 ;
}
static void
F_26 ( V_16 V_55 )
{
T_8 * V_56 = ( T_8 * ) V_55 ;
F_15 ( V_56 -> V_31 ) ;
F_15 ( V_56 -> V_29 ) ;
F_15 ( V_56 -> V_33 ) ;
F_15 ( V_56 -> V_35 ) ;
F_15 ( V_56 ) ;
}
static void
F_27 ( void )
{
#ifdef F_28
char * V_57 ;
char * V_58 ;
static char V_59 [] = L_8 ;
#endif
F_9 ( V_27 == NULL ) ;
V_27 = F_29 ( V_60 , V_61 , F_15 , F_26 ) ;
#ifdef F_28
V_58 = F_30 ( L_9 ) ;
if ( V_58 != NULL ) {
V_57 = F_31 ( V_58 , V_59 , NULL ) ;
F_20 ( V_57 ) ;
F_15 ( V_57 ) ;
}
#else
F_20 ( L_10 ) ;
#endif
if ( V_62 == NULL )
V_62 = F_32 ( V_63 , FALSE ) ;
F_20 ( V_62 ) ;
if ( V_64 == NULL ) {
V_64 = F_33 ( V_63 ) ;
}
F_20 ( V_64 ) ;
}
static void
F_34 ( void )
{
if( V_27 ) {
F_35 ( V_27 ) ;
V_27 = NULL ;
}
}
static void
F_36 ( const T_7 V_9 , T_11 * volatile V_65 )
{
T_12 V_66 ;
if ( ( V_65 -> V_67 & V_68 ) == V_68 )
return;
V_65 -> V_67 = V_65 -> V_67 | V_68 ;
V_66 = F_37 ( V_9 ) ;
if( 0 != V_66 . V_69 ) {
T_1 V_70 ;
T_9 V_71 [ V_72 ] ;
T_9 * V_73 ;
T_13 V_5 ;
V_70 = V_9 & ( ~ ( T_1 ) V_66 . V_69 ) ;
F_38 ( ( V_74 * ) & V_70 , V_71 , V_72 ) ;
V_73 = V_71 ;
V_5 = V_66 . V_75 / 8 ;
while( * ( V_73 ) != '\0' && V_5 > 0 ) {
if( * ( ++ V_73 ) == '.' ) {
-- V_5 ;
}
}
F_39 ( V_65 -> V_54 , V_53 , L_11 , V_66 . V_54 , V_73 ) ;
} else {
F_38 ( ( const V_74 * ) & V_9 , V_65 -> V_54 , V_53 ) ;
}
}
static void
F_40 (
void * V_76 ,
int V_77 ,
#if ( ( V_78 < 1 ) \
|| ( 1 == V_78 && V_79 < 5 ) )
struct V_80 * T_14
#else
int T_15 V_81 ,
struct V_80 * T_14
#endif
) {
T_4 * V_82 = ( T_4 * ) V_76 ;
char * * V_3 ;
if ( ! V_82 ) return;
V_83 -- ;
if ( V_77 == V_84 ) {
for ( V_3 = T_14 -> V_85 ; * V_3 != NULL ; V_3 ++ ) {
switch( V_82 -> V_11 ) {
case V_86 :
F_41 ( V_82 -> V_9 . V_12 , T_14 -> V_87 ) ;
break;
case V_88 :
F_42 ( & V_82 -> V_9 . V_89 , T_14 -> V_87 ) ;
break;
default:
break;
}
}
}
F_15 ( V_82 ) ;
}
static T_11 *
F_43 ( const T_7 V_9 )
{
T_11 * V_65 = F_4 ( T_11 , 1 ) ;
V_65 -> V_9 = V_9 ;
V_65 -> V_67 = 0 ;
F_38 ( ( const V_74 * ) & V_9 , V_65 -> V_90 , sizeof( V_65 -> V_90 ) ) ;
return V_65 ;
}
static T_11 *
F_44 ( const T_7 V_9 , T_3 * V_91 )
{
T_11 * volatile V_65 ;
* V_91 = TRUE ;
V_65 = ( T_11 * ) F_12 ( V_92 , F_45 ( V_9 ) ) ;
if( V_65 == NULL ) {
V_65 = F_43 ( V_9 ) ;
F_14 ( V_92 , F_45 ( V_9 ) , V_65 ) ;
} else{
if ( ( V_65 -> V_67 & V_93 ) == V_68 ) {
goto V_94;
}
if ( ( V_65 -> V_67 & V_68 ) == V_68 ) {
* V_91 = FALSE ;
}
return V_65 ;
}
V_94:
if ( V_95 . V_96 && V_95 . V_97 ) {
V_65 -> V_67 = V_65 -> V_67 | V_98 ;
#ifdef F_46
if ( V_95 . V_99 &&
V_100 > 0 &&
V_101 ) {
F_3 ( V_86 , V_9 ) ;
F_36 ( V_9 , V_65 ) ;
return V_65 ;
}
#endif
}
* V_91 = FALSE ;
F_36 ( V_9 , V_65 ) ;
return V_65 ;
}
static T_16 *
F_47 ( const struct V_8 * V_9 )
{
T_16 * V_65 = F_4 ( T_16 , 1 ) ;
V_65 -> V_9 = * V_9 ;
V_65 -> V_67 = 0 ;
F_48 ( V_9 , V_65 -> V_89 ) ;
return V_65 ;
}
static T_16 *
F_49 ( const struct V_8 * V_9 , T_3 * V_91 )
{
T_16 * volatile V_65 ;
#ifdef F_50
#ifdef F_5
T_4 * V_82 ;
#endif
#endif
* V_91 = TRUE ;
V_65 = ( T_16 * ) F_12 ( V_102 , V_9 ) ;
if( V_65 == NULL ) {
struct V_8 * V_103 ;
V_103 = F_4 ( struct V_8 , 1 ) ;
V_65 = F_47 ( V_9 ) ;
memcpy ( V_103 , V_9 , 16 ) ;
F_14 ( V_102 , V_103 , V_65 ) ;
} else{
if ( ( V_65 -> V_67 & V_93 ) == V_68 ) {
goto V_94;
}
if ( ( V_65 -> V_67 & V_68 ) == V_68 ) {
* V_91 = FALSE ;
}
return V_65 ;
}
V_94:
if ( V_95 . V_96 &&
V_95 . V_97 ) {
V_65 -> V_67 = V_65 -> V_67 | V_98 ;
#ifdef F_50
#ifdef F_5
if ( ( V_95 . V_99 ) &&
V_100 > 0 &&
V_101 ) {
V_82 = F_4 ( T_4 , 1 ) ;
V_82 -> V_11 = V_88 ;
memcpy ( & V_82 -> V_9 . V_89 , V_9 , sizeof( V_82 -> V_9 . V_89 ) ) ;
V_15 = F_6 ( V_15 , ( V_16 ) V_82 ) ;
if ( ( V_65 -> V_67 & V_68 ) == 0 ) {
F_51 ( V_65 -> V_54 , V_65 -> V_89 , V_53 ) ;
F_48 ( V_9 , V_65 -> V_54 ) ;
V_65 -> V_67 = V_65 -> V_67 | V_68 ;
}
return V_65 ;
}
#endif
#endif
}
if ( ( V_65 -> V_67 & V_68 ) == 0 ) {
V_65 -> V_67 = V_65 -> V_67 | V_68 ;
F_51 ( V_65 -> V_54 , V_65 -> V_89 , V_53 ) ;
}
* V_91 = FALSE ;
return V_65 ;
}
static const T_9 *
F_52 ( const T_17 * V_9 )
{
switch ( V_9 -> type ) {
case V_104 :
return F_53 ( ( const V_74 * ) V_9 -> V_55 ) ;
case V_105 : {
T_1 V_13 ;
memcpy ( & V_13 , V_9 -> V_55 , sizeof V_13 ) ;
return F_54 ( V_13 ) ;
}
case V_106 : {
struct V_8 V_107 ;
memcpy ( & V_107 . V_108 , V_9 -> V_55 , sizeof V_107 . V_108 ) ;
return F_55 ( & V_107 ) ;
}
case V_109 :
return ( const T_9 * ) V_9 -> V_55 ;
default:
return NULL ;
}
}
static T_3
F_56 ( const char * V_37 , T_18 * V_110 , unsigned int * V_69 ,
const T_3 V_111 )
{
int V_5 ;
unsigned long V_112 ;
char * V_3 ;
char V_113 = '\0' ;
for ( V_5 = 0 ; V_5 < 6 ; V_5 ++ ) {
if ( ! isxdigit ( ( unsigned char ) * V_37 ) )
return FALSE ;
V_112 = strtoul ( V_37 , & V_3 , 16 ) ;
if ( V_3 == V_37 )
return FALSE ;
if ( V_112 > 0xFF )
return FALSE ;
V_110 -> V_9 [ V_5 ] = ( V_74 ) V_112 ;
V_37 = V_3 ;
if ( * V_37 == '/' ) {
if ( ! V_111 ) {
return FALSE ;
}
V_37 ++ ;
if ( ! isdigit ( ( unsigned char ) * V_37 ) )
return FALSE ;
V_112 = strtoul ( V_37 , & V_3 , 10 ) ;
if ( V_3 == V_37 )
return FALSE ;
V_37 = V_3 ;
if ( * V_37 != '\0' && ! isspace ( ( unsigned char ) * V_37 ) )
return FALSE ;
if ( V_112 == 0 || V_112 >= 48 )
return FALSE ;
* V_69 = ( int ) V_112 ;
for ( V_5 = 0 ; V_112 >= 8 ; V_5 ++ , V_112 -= 8 )
;
V_110 -> V_9 [ V_5 ] &= ( 0xFF << ( 8 - V_112 ) ) ;
V_5 ++ ;
for (; V_5 < 6 ; V_5 ++ )
V_110 -> V_9 [ V_5 ] = 0 ;
return TRUE ;
}
if ( * V_37 == '\0' ) {
if ( V_5 == 2 ) {
if ( ! V_111 ) {
return FALSE ;
}
* V_69 = 0 ;
return TRUE ;
}
if ( V_5 == 5 ) {
if ( V_111 )
* V_69 = 48 ;
return TRUE ;
}
return FALSE ;
} else {
if ( V_113 == '\0' ) {
if ( * V_37 != ':' && * V_37 != '-' && * V_37 != '.' )
return FALSE ;
V_113 = * V_37 ;
} else {
if ( * V_37 != V_113 )
return FALSE ;
}
}
V_37 ++ ;
}
return TRUE ;
}
static int
F_57 ( char * line , T_18 * V_110 , unsigned int * V_69 ,
const T_3 V_111 )
{
T_9 * V_37 ;
if ( ( V_37 = strchr ( line , '#' ) ) )
* V_37 = '\0' ;
if ( ( V_37 = strtok ( line , L_1 ) ) == NULL )
return - 1 ;
if ( ! F_56 ( V_37 , V_110 , V_69 , V_111 ) )
return - 1 ;
if ( ( V_37 = strtok ( NULL , L_1 ) ) == NULL )
return - 1 ;
F_51 ( V_110 -> V_54 , V_37 , V_53 ) ;
return 0 ;
}
static void
F_58 ( char * V_50 )
{
if ( V_114 )
rewind ( V_114 ) ;
else
V_114 = F_21 ( V_50 , L_7 ) ;
}
static void
F_59 ( void )
{
if ( V_114 ) {
fclose ( V_114 ) ;
V_114 = NULL ;
}
}
static T_18 *
F_60 ( unsigned int * V_69 , const T_3 V_111 )
{
static T_18 V_110 ;
static int V_18 = 0 ;
static char * V_17 = NULL ;
if ( V_114 == NULL )
return NULL ;
while ( F_7 ( & V_17 , & V_18 , V_114 ) >= 0 ) {
if ( F_57 ( V_17 , & V_110 , V_69 , V_111 ) == 0 ) {
return & V_110 ;
}
}
return NULL ;
}
static T_18 *
F_61 ( const V_74 * V_9 )
{
T_18 * V_110 ;
F_58 ( V_115 ) ;
while ( ( ( V_110 = F_60 ( NULL , FALSE ) ) != NULL ) && memcmp ( V_9 , V_110 -> V_9 , 6 ) != 0 )
;
if ( V_110 == NULL ) {
F_59 () ;
F_58 ( V_116 ) ;
while ( ( ( V_110 = F_60 ( NULL , FALSE ) ) != NULL ) && memcmp ( V_9 , V_110 -> V_9 , 6 ) != 0 )
;
F_59 () ;
}
return V_110 ;
}
static void
F_62 ( const V_74 * V_9 , unsigned int V_69 , T_9 * V_54 )
{
V_74 * V_117 ;
int * V_118 ;
if ( V_69 >= 48 ) {
F_63 ( V_9 , V_54 ) ;
return;
}
if ( V_69 == 0 ) {
V_118 = ( int * ) F_4 ( int , 1 ) ;
* V_118 = ( int ) ( ( V_9 [ 2 ] << 16 ) + ( V_9 [ 1 ] << 8 ) + V_9 [ 0 ] ) ;
F_14 ( V_119 , V_118 , F_16 ( V_54 ) ) ;
return;
}
V_117 = ( V_74 * ) F_8 ( 6 ) ;
memcpy ( V_117 , V_9 , 6 ) ;
F_14 ( V_120 , V_117 , F_16 ( V_54 ) ) ;
}
static T_9 *
F_64 ( const V_74 * V_9 )
{
T_19 V_118 = 0 ;
V_74 V_121 ;
T_9 * V_54 ;
V_118 = V_9 [ 0 ] ;
V_118 = V_118 << 8 ;
V_121 = V_9 [ 1 ] ;
V_118 = V_118 | V_121 ;
V_118 = V_118 << 8 ;
V_121 = V_9 [ 2 ] ;
V_118 = V_118 | V_121 ;
V_54 = ( T_9 * ) F_12 ( V_119 , & V_118 ) ;
if( V_54 != NULL ) {
return V_54 ;
}
if( ( V_118 & 0x00010000 ) != 0 ) {
V_118 &= 0x00FEFFFF ;
V_54 = ( T_9 * ) F_12 ( V_119 , & V_118 ) ;
if( V_54 != NULL ) {
return V_54 ;
}
}
return NULL ;
}
static T_9 *
F_65 ( const V_74 * V_9 , const unsigned int V_69 )
{
V_74 V_122 [ 6 ] ;
T_7 V_112 ;
T_20 V_5 ;
T_9 * V_54 ;
if( V_120 == NULL ) {
return NULL ;
}
for ( V_5 = 0 , V_112 = V_69 ; V_112 >= 8 ; V_5 ++ , V_112 -= 8 )
V_122 [ V_5 ] = V_9 [ V_5 ] ;
V_122 [ V_5 ] = V_9 [ V_5 ] & ( 0xFF << ( 8 - V_112 ) ) ;
V_5 ++ ;
for (; V_5 < 6 ; V_5 ++ )
V_122 [ V_5 ] = 0 ;
V_54 = ( T_9 * ) F_12 ( V_120 , V_122 ) ;
return V_54 ;
}
static T_7
F_66 ( T_2 V_1 )
{
return F_67 ( ( const V_74 * ) V_1 , 6 ) ;
}
static T_3
F_68 ( T_2 V_123 , T_2 V_124 )
{
return ( memcmp ( V_123 , V_124 , 6 ) == 0 ) ;
}
static void
F_69 ( void )
{
T_18 * V_110 ;
char * V_125 ;
T_7 V_69 ;
V_120 = F_29 ( F_66 , F_68 , F_15 , F_15 ) ;
V_119 = F_29 ( V_60 , V_61 , F_15 , F_15 ) ;
V_126 = F_29 ( F_66 , F_68 , NULL , F_15 ) ;
if ( V_116 == NULL ) {
V_116 = F_70 ( L_12 V_127 L_12 ,
F_71 () , V_128 ) ;
}
if ( V_115 == NULL )
V_115 = F_32 ( V_128 , FALSE ) ;
V_125 = F_33 ( V_129 ) ;
F_58 ( V_125 ) ;
while ( ( V_110 = F_60 ( & V_69 , TRUE ) ) ) {
F_62 ( V_110 -> V_9 , V_69 , V_110 -> V_54 ) ;
}
F_59 () ;
F_15 ( V_125 ) ;
}
static void
F_72 ( void )
{
if( V_119 ) {
F_35 ( V_119 ) ;
V_119 = NULL ;
}
if( V_120 ) {
F_35 ( V_120 ) ;
V_120 = NULL ;
}
if( V_126 ) {
F_35 ( V_126 ) ;
V_126 = NULL ;
}
}
static T_21 *
F_73 ( T_21 * V_65 ) {
T_18 * V_110 ;
const V_74 * V_9 = V_65 -> V_9 ;
if ( ( V_110 = F_61 ( V_9 ) ) != NULL ) {
F_51 ( V_65 -> V_130 , V_110 -> V_54 , V_53 ) ;
V_65 -> V_77 = V_131 ;
return V_65 ;
} else {
T_7 V_69 ;
T_9 * V_54 ;
V_69 = 7 ;
for (; ; ) {
if ( ( V_54 = F_65 ( V_9 , V_69 + 40 ) ) != NULL ) {
F_39 ( V_65 -> V_130 , V_53 , L_13 ,
V_54 , V_9 [ 5 ] & ( 0xFF >> V_69 ) ) ;
V_65 -> V_77 = V_132 ;
return V_65 ;
}
if ( V_69 == 0 )
break;
V_69 -- ;
}
V_69 = 7 ;
for (; ; ) {
if ( ( V_54 = F_65 ( V_9 , V_69 + 32 ) ) != NULL ) {
F_39 ( V_65 -> V_130 , V_53 , L_14 ,
V_54 , V_9 [ 4 ] & ( 0xFF >> V_69 ) , V_9 [ 5 ] ) ;
V_65 -> V_77 = V_132 ;
return V_65 ;
}
if ( V_69 == 0 )
break;
V_69 -- ;
}
V_69 = 7 ;
for (; ; ) {
if ( ( V_54 = F_65 ( V_9 , V_69 + 24 ) ) != NULL ) {
F_39 ( V_65 -> V_130 , V_53 , L_15 ,
V_54 , V_9 [ 3 ] & ( 0xFF >> V_69 ) , V_9 [ 4 ] , V_9 [ 5 ] ) ;
V_65 -> V_77 = V_132 ;
return V_65 ;
}
if ( V_69 == 0 )
break;
V_69 -- ;
}
if ( ( V_54 = F_64 ( V_9 ) ) != NULL ) {
F_39 ( V_65 -> V_130 , V_53 , L_15 ,
V_54 , V_9 [ 3 ] , V_9 [ 4 ] , V_9 [ 5 ] ) ;
V_65 -> V_77 = V_132 ;
return V_65 ;
}
V_69 = 7 ;
for (; ; ) {
if ( ( V_54 = F_65 ( V_9 , V_69 + 16 ) ) != NULL ) {
F_39 ( V_65 -> V_130 , V_53 , L_16 ,
V_54 , V_9 [ 2 ] & ( 0xFF >> V_69 ) , V_9 [ 3 ] , V_9 [ 4 ] ,
V_9 [ 5 ] ) ;
V_65 -> V_77 = V_132 ;
return V_65 ;
}
if ( V_69 == 0 )
break;
V_69 -- ;
}
V_69 = 7 ;
for (; ; ) {
if ( ( V_54 = F_65 ( V_9 , V_69 + 8 ) ) != NULL ) {
F_39 ( V_65 -> V_130 , V_53 , L_17 ,
V_54 , V_9 [ 1 ] & ( 0xFF >> V_69 ) , V_9 [ 2 ] , V_9 [ 3 ] ,
V_9 [ 4 ] , V_9 [ 5 ] ) ;
V_65 -> V_77 = V_132 ;
return V_65 ;
}
if ( V_69 == 0 )
break;
V_69 -- ;
}
for ( V_69 = 7 ; V_69 > 0 ; V_69 -- ) {
if ( ( V_54 = F_65 ( V_9 , V_69 ) ) != NULL ) {
F_39 ( V_65 -> V_130 , V_53 , L_18 ,
V_54 , V_9 [ 0 ] & ( 0xFF >> V_69 ) , V_9 [ 1 ] , V_9 [ 2 ] ,
V_9 [ 3 ] , V_9 [ 4 ] , V_9 [ 5 ] ) ;
V_65 -> V_77 = V_132 ;
return V_65 ;
}
}
F_39 ( V_65 -> V_130 , V_53 , L_12 , F_74 ( V_9 ) ) ;
V_65 -> V_77 = V_132 ;
return V_65 ;
}
F_75 () ;
}
static T_21 *
F_76 ( const V_74 * V_9 , const T_3 V_133 )
{
T_21 * V_65 ;
char * V_134 ;
V_65 = F_4 ( T_21 , 1 ) ;
memcpy ( V_65 -> V_9 , V_9 , sizeof( V_65 -> V_9 ) ) ;
V_65 -> V_77 = V_135 ;
V_134 = F_77 ( V_65 -> V_136 , V_9 , sizeof( V_65 -> V_9 ) , ':' ) ;
* V_134 = '\0' ;
V_65 -> V_130 [ 0 ] = '\0' ;
if ( V_133 )
F_73 ( V_65 ) ;
F_14 ( V_126 , V_65 -> V_9 , V_65 ) ;
return V_65 ;
}
static T_21 *
F_63 ( const V_74 * V_9 , const T_9 * V_54 )
{
T_21 * V_65 ;
V_65 = ( T_21 * ) F_12 ( V_126 , V_9 ) ;
if( V_65 == NULL ) {
V_65 = F_76 ( V_9 , FALSE ) ;
}
F_51 ( V_65 -> V_130 , V_54 , V_53 ) ;
V_65 -> V_77 = V_131 ;
V_36 = TRUE ;
return V_65 ;
}
static T_21 *
F_78 ( const V_74 * V_9 , const T_3 V_133 )
{
T_21 * V_65 ;
V_65 = ( T_21 * ) F_12 ( V_126 , V_9 ) ;
if( V_65 == NULL ) {
V_65 = F_76 ( V_9 , V_133 ) ;
} else {
if ( V_133 && ( V_65 -> V_77 == V_135 ) ) {
F_73 ( V_65 ) ;
}
}
return V_65 ;
}
static V_74 *
F_79 ( const T_9 * V_54 V_81 )
{
#if 0
ether_t *eth;
hashether_t *tp;
hashether_t **table = eth_table;
gint i;
for (i = 0; i < HASHETHSIZE; i++) {
tp = table[i];
while (tp) {
if (strcmp(tp->resolved_name, name) == 0)
return tp->addr;
tp = tp->next;
}
}
if ((eth = get_ethbyname(name)) == NULL)
return NULL;
tp = add_eth_name(eth->addr, name);
return tp->addr;
#endif
return NULL ;
}
static int
F_80 ( char * line , T_22 * V_137 )
{
T_9 * V_37 ;
T_1 V_123 , V_138 , V_139 , V_140 , V_141 ;
T_3 V_142 = FALSE ;
if ( ( V_37 = strchr ( line , '#' ) ) )
* V_37 = '\0' ;
if ( ( V_37 = strtok ( line , L_19 ) ) == NULL )
return - 1 ;
if ( sscanf ( V_37 , L_20 , & V_138 , & V_139 , & V_140 , & V_141 ) != 4 ) {
if ( sscanf ( V_37 , L_21 , & V_138 , & V_139 , & V_140 , & V_141 ) != 4 ) {
if ( sscanf ( V_37 , L_22 , & V_138 , & V_139 , & V_140 , & V_141 ) != 4 ) {
if ( sscanf ( V_37 , L_23 , & V_123 ) == 1 ) {
V_142 = TRUE ;
}
else {
return - 1 ;
}
}
}
}
if ( ( V_37 = strtok ( NULL , L_19 ) ) == NULL )
return - 1 ;
if ( V_142 ) {
V_137 -> V_9 = V_123 ;
}
else {
V_137 -> V_9 = ( V_138 << 24 ) | ( V_139 << 16 ) | ( V_140 << 8 ) | V_141 ;
}
F_51 ( V_137 -> V_54 , V_37 , V_53 ) ;
return 0 ;
}
static void
F_81 ( char * V_50 )
{
if ( V_143 )
rewind ( V_143 ) ;
else
V_143 = F_21 ( V_50 , L_7 ) ;
}
static void
F_82 ( void )
{
if ( V_143 ) {
fclose ( V_143 ) ;
V_143 = NULL ;
}
}
static T_22 *
F_83 ( void )
{
static T_22 V_137 ;
static int V_18 = 0 ;
static char * V_17 = NULL ;
if ( V_143 == NULL )
return NULL ;
while ( F_7 ( & V_17 , & V_18 , V_143 ) >= 0 ) {
if ( F_80 ( V_17 , & V_137 ) == 0 ) {
return & V_137 ;
}
}
return NULL ;
}
static T_22 *
F_84 ( T_1 V_9 )
{
T_22 * V_137 ;
F_81 ( V_144 ) ;
while ( ( ( V_137 = F_83 () ) != NULL ) && ( V_9 != V_137 -> V_9 ) ) ;
if ( V_137 == NULL ) {
F_82 () ;
F_81 ( V_145 ) ;
while ( ( ( V_137 = F_83 () ) != NULL ) && ( V_9 != V_137 -> V_9 ) )
;
F_82 () ;
}
return V_137 ;
}
static void
F_85 ( void )
{
if ( V_144 == NULL ) {
V_144 = F_70 ( L_12 V_127 L_12 ,
F_71 () , V_146 ) ;
}
if ( V_145 == NULL )
V_145 = F_32 ( V_146 , FALSE ) ;
}
static void
F_86 ( void )
{
if( V_147 ) {
F_35 ( V_147 ) ;
V_147 = NULL ;
}
}
static T_9 *
F_87 ( const T_7 V_9 )
{
T_23 * V_65 ;
T_22 * V_137 ;
V_65 = ( T_23 * ) F_12 ( V_147 , & V_9 ) ;
if( V_65 == NULL ) {
int * V_1 ;
V_1 = ( int * ) F_4 ( int , 1 ) ;
* V_1 = V_9 ;
V_65 = F_4 ( T_23 , 1 ) ;
F_14 ( V_147 , V_1 , V_65 ) ;
} else{
return V_65 -> V_54 ;
}
V_65 -> V_9 = V_9 ;
if ( ( V_137 = F_84 ( V_9 ) ) == NULL ) {
F_39 ( V_65 -> V_54 , V_53 , L_24 , V_9 ) ;
} else {
F_51 ( V_65 -> V_54 , V_137 -> V_54 , V_53 ) ;
}
return ( V_65 -> V_54 ) ;
}
static T_7
F_88 ( const T_9 * V_54 V_81 , T_3 * V_148 )
{
* V_148 = FALSE ;
return 0 ;
#if 0
ipxnet_t *ipxnet;
hashipxnet_t *tp;
hashipxnet_t **table = ipxnet_table;
int i;
for (i = 0; i < HASHIPXNETSIZE; i++) {
tp = table[i];
while (tp) {
if (strcmp(tp->name, name) == 0) {
*success = TRUE;
return tp->addr;
}
tp = tp->next;
}
}
if ((ipxnet = get_ipxnetbyname(name)) == NULL) {
*success = FALSE;
return 0;
}
tp = add_ipxnet_name(ipxnet->addr, name);
*success = TRUE;
return tp->addr;
#endif
}
static T_3
F_89 ( const char * V_57 )
{
T_5 * V_149 ;
char * line = NULL ;
int V_18 = 0 ;
T_9 * V_37 ;
T_1 V_70 [ 4 ] ;
struct V_8 V_107 ;
T_3 V_150 ;
int V_151 ;
if ( ( V_149 = F_21 ( V_57 , L_7 ) ) == NULL )
return FALSE ;
while ( F_7 ( & line , & V_18 , V_149 ) >= 0 ) {
if ( ( V_37 = strchr ( line , '#' ) ) )
* V_37 = '\0' ;
if ( ( V_37 = strtok ( line , L_1 ) ) == NULL )
continue;
V_151 = F_90 ( V_88 , V_37 , & V_70 ) ;
if ( V_151 < 0 )
continue;
if ( V_151 > 0 ) {
V_150 = TRUE ;
} else {
if ( ! F_91 ( V_37 , & V_70 ) )
continue;
V_150 = FALSE ;
}
if ( ( V_37 = strtok ( NULL , L_1 ) ) == NULL )
continue;
if ( V_150 ) {
memcpy ( & V_107 , V_70 , sizeof V_107 ) ;
F_42 ( & V_107 , V_37 ) ;
} else
F_41 ( V_70 [ 0 ] , V_37 ) ;
while ( ( V_37 = strtok ( NULL , L_1 ) ) != NULL ) {
if ( V_150 ) {
memcpy ( & V_107 , V_70 , sizeof V_107 ) ;
F_42 ( & V_107 , V_37 ) ;
} else
F_41 ( V_70 [ 0 ] , V_37 ) ;
}
}
F_15 ( line ) ;
fclose ( V_149 ) ;
return TRUE ;
}
T_3
F_92 ( const char * V_152 )
{
T_3 V_91 = FALSE ;
T_7 V_5 ;
if ( ! V_152 )
return FALSE ;
if ( ! V_153 )
V_153 = F_93 () ;
for ( V_5 = 0 ; V_5 < V_153 -> V_2 ; V_5 ++ ) {
if ( strcmp ( V_152 , ( const char * ) F_94 ( V_153 , V_5 ) ) == 0 )
V_91 = TRUE ;
}
if ( ! V_91 ) {
F_95 ( V_153 , F_16 ( V_152 ) ) ;
return F_89 ( V_152 ) ;
}
return TRUE ;
}
T_3
F_96 ( const char * V_9 , const char * V_54 )
{
T_1 V_70 [ 4 ] ;
struct V_8 V_107 ;
T_3 V_150 ;
int V_151 ;
T_24 * V_154 ;
T_25 * V_155 ;
V_151 = F_90 ( V_88 , V_9 , & V_107 ) ;
if ( V_151 < 0 )
return FALSE ;
if ( V_151 > 0 ) {
V_150 = TRUE ;
} else {
if ( ! F_91 ( V_9 , & V_70 ) )
return FALSE ;
V_150 = FALSE ;
}
if ( V_150 ) {
V_155 = F_4 ( T_25 , 1 ) ;
memcpy ( & ( V_155 -> V_107 ) , & V_107 , 16 ) ;
F_51 ( V_155 -> V_54 , V_54 , V_53 ) ;
V_156 = F_97 ( V_156 , V_155 ) ;
} else {
V_154 = F_4 ( T_24 , 1 ) ;
V_154 -> V_70 = V_70 [ 0 ] ;
F_51 ( V_154 -> V_54 , V_54 , V_53 ) ;
V_157 = F_97 ( V_157 , V_154 ) ;
}
return TRUE ;
}
static void
F_98 ( V_16 V_1 V_81 , V_16 V_158 , V_16 V_159 )
{
T_26 * V_160 = ( T_26 * ) V_159 ;
T_11 * V_161 = ( T_11 * ) V_158 ;
if( ( V_161 -> V_67 & V_162 ) == V_163 ) {
V_160 -> V_164 = F_99 ( V_160 -> V_164 , V_161 ) ;
}
}
static void
F_100 ( V_16 V_1 V_81 , V_16 V_158 , V_16 V_159 )
{
T_26 * V_160 = ( T_26 * ) V_159 ;
T_16 * V_165 = ( T_16 * ) V_158 ;
if( ( V_165 -> V_67 & V_162 ) == V_163 ) {
V_160 -> V_166 = F_99 ( V_160 -> V_166 , V_165 ) ;
}
}
T_26 *
F_101 ( void ) {
if( V_92 ) {
F_102 ( V_92 , F_98 , & V_167 ) ;
}
if( V_102 ) {
F_102 ( V_102 , F_100 , & V_167 ) ;
}
return & V_167 ;
}
static T_3
F_103 ( const char * V_168 )
{
T_5 * V_149 ;
char * line = NULL ;
int V_18 = 0 ;
T_9 * V_37 , * V_169 ;
T_1 V_70 ;
int V_75 ;
if ( ( V_149 = F_21 ( V_168 , L_7 ) ) == NULL )
return FALSE ;
while ( F_7 ( & line , & V_18 , V_149 ) >= 0 ) {
if ( ( V_37 = strchr ( line , '#' ) ) )
* V_37 = '\0' ;
if ( ( V_37 = strtok ( line , L_1 ) ) == NULL )
continue;
V_169 = strchr ( V_37 , '/' ) ;
if( NULL == V_169 ) {
continue;
}
* V_169 = '\0' ;
++ V_169 ;
if ( ! F_91 ( V_37 , & V_70 ) ) {
continue;
}
V_75 = atoi ( V_169 ) ;
if( 0 >= V_75 || V_75 > 31 ) {
continue;
}
if ( ( V_37 = strtok ( NULL , L_1 ) ) == NULL )
continue;
F_104 ( V_70 , ( T_1 ) V_75 , V_37 ) ;
}
F_15 ( line ) ;
fclose ( V_149 ) ;
return TRUE ;
}
static T_12
F_37 ( const T_1 V_9 )
{
T_12 V_66 ;
T_1 V_5 ;
V_5 = V_170 ;
while( V_171 && V_5 > 0 ) {
T_1 V_122 ;
T_27 * V_172 ;
-- V_5 ;
F_9 ( V_5 < V_170 ) ;
V_172 = & V_173 [ V_5 ] ;
if( NULL != V_172 -> V_174 ) {
T_28 * V_65 ;
T_1 V_175 ;
V_122 = V_9 & V_172 -> V_69 ;
V_175 = F_105 ( V_122 ) ;
V_65 = V_172 -> V_174 [ V_175 ] ;
while( V_65 != NULL && V_65 -> V_9 != V_122 ) {
V_65 = V_65 -> V_176 ;
}
if( NULL != V_65 ) {
V_66 . V_69 = V_172 -> V_69 ;
V_66 . V_75 = V_5 + 1 ;
V_66 . V_54 = V_65 -> V_54 ;
return V_66 ;
}
}
}
V_66 . V_69 = 0 ;
V_66 . V_75 = 0 ;
V_66 . V_54 = NULL ;
return V_66 ;
}
static void
F_104 ( T_1 V_177 , const T_1 V_75 , const T_9 * V_54 )
{
T_27 * V_178 ;
T_28 * V_65 ;
T_13 V_175 ;
F_9 ( V_75 > 0 && V_75 <= 32 ) ;
V_178 = & V_173 [ V_75 - 1 ] ;
V_177 &= V_178 -> V_69 ;
V_175 = F_105 ( V_177 ) ;
if( NULL == V_178 -> V_174 ) {
V_178 -> V_174 = ( T_28 * * ) F_106 ( sizeof( T_28 * ) * V_179 ) ;
}
if( NULL != ( V_65 = V_178 -> V_174 [ V_175 ] ) ) {
if( V_65 -> V_9 == V_177 ) {
return;
} else {
T_28 * V_180 = F_107 ( T_28 ) ;
V_65 -> V_176 = V_180 ;
V_65 = V_180 ;
}
} else {
V_65 = V_178 -> V_174 [ V_175 ] = F_107 ( T_28 ) ;
}
V_65 -> V_176 = NULL ;
V_65 -> V_9 = V_177 ;
V_65 -> V_67 = V_65 -> V_67 & 0xfe ;
F_51 ( V_65 -> V_54 , V_54 , V_53 ) ;
V_171 = TRUE ;
}
static void
F_108 ( void )
{
T_9 * V_168 ;
T_1 V_5 ;
for( V_5 = 0 ; V_5 < V_170 ; ++ V_5 ) {
T_1 V_181 = V_5 + 1 ;
V_173 [ V_5 ] . V_174 = NULL ;
V_173 [ V_5 ] . V_75 = V_181 ;
V_173 [ V_5 ] . V_69 = F_109 ( F_110 ( V_181 ) ) ;
}
V_168 = F_32 ( V_182 , FALSE ) ;
if ( ! F_103 ( V_168 ) && V_183 != V_184 ) {
F_111 ( V_168 , V_183 , FALSE ) ;
}
F_15 ( V_168 ) ;
V_168 = F_33 ( V_182 ) ;
if ( ! F_103 ( V_168 ) && V_183 != V_184 ) {
F_111 ( V_168 , V_183 , FALSE ) ;
}
F_15 ( V_168 ) ;
}
void
F_112 ( T_29 * V_185 )
{
F_113 ( V_185 , L_25 ,
L_26 ,
L_27 ,
& V_95 . V_186 ) ;
F_113 ( V_185 , L_28 ,
L_29 ,
L_30 ,
& V_95 . V_187 ) ;
F_113 ( V_185 , L_31 ,
L_32 ,
L_33
L_34
L_35
L_36 ,
& V_95 . V_96 ) ;
F_113 ( V_185 , L_37 ,
L_38 ,
L_39
L_40
L_41
L_42 ,
& V_95 . V_97 ) ;
#if F_114 ( F_5 ) || F_114 ( V_188 )
F_113 ( V_185 , L_43 ,
L_44 ,
L_45
L_46
L_47 ,
& V_95 . V_99 ) ;
F_115 ( V_185 , L_48 ,
L_49 ,
L_50
L_51
L_52
L_53 ,
10 ,
& V_100 ) ;
#else
F_116 ( V_185 , L_43 ,
L_54 ,
L_55
L_56 ) ;
#endif
F_113 ( V_185 , L_57 ,
L_58 ,
L_59
L_60 ,
& V_95 . V_189 ) ;
}
T_3
F_117 ( void ) {
T_4 * V_82 ;
struct V_190 V_191 = { 0 , 0 } ;
int V_192 ;
T_30 V_193 , V_194 ;
T_3 V_195 = V_36 ;
V_36 = FALSE ;
if ( ! V_101 )
return V_195 ;
V_15 = F_118 ( V_15 ) ;
while ( V_15 != NULL && V_83 <= V_100 ) {
V_82 = ( T_4 * ) V_15 -> V_55 ;
V_15 = F_119 ( V_15 , ( void * ) V_82 ) ;
if ( V_82 -> V_11 == V_86 ) {
F_120 ( V_196 , & V_82 -> V_9 . V_12 , sizeof( T_1 ) , V_86 ,
F_40 , V_82 ) ;
V_83 ++ ;
} else if ( V_82 -> V_11 == V_88 ) {
F_120 ( V_196 , & V_82 -> V_9 . V_89 , sizeof( struct V_8 ) ,
V_88 , F_40 , V_82 ) ;
V_83 ++ ;
}
}
F_121 ( & V_193 ) ;
F_121 ( & V_194 ) ;
V_192 = F_122 ( V_196 , & V_193 , & V_194 ) ;
if ( V_192 > 0 ) {
if ( F_123 ( V_192 , & V_193 , & V_194 , NULL , & V_191 ) == - 1 ) {
fprintf ( V_197 , L_61 , strerror ( V_183 ) ) ;
return V_195 ;
}
F_124 ( V_196 , & V_193 , & V_194 ) ;
}
return V_195 ;
}
static void
F_125 ( void ) {
T_31 * V_198 ;
V_198 = F_118 ( V_15 ) ;
while ( V_198 ) {
F_15 ( V_198 -> V_55 ) ;
V_198 = F_126 ( V_198 ) ;
}
F_127 ( V_15 ) ;
V_15 = NULL ;
if ( V_101 ) {
F_128 ( V_196 ) ;
F_128 ( V_199 ) ;
}
#ifdef F_129
F_130 () ;
#endif
V_101 = FALSE ;
}
T_3
F_117 ( void ) {
T_4 * V_200 ;
T_31 * V_198 ;
char V_201 [] = L_62 ;
V_74 * V_202 ;
T_32 * V_203 ;
int V_151 ;
T_3 V_204 ;
T_3 V_195 = V_36 ;
V_36 = FALSE ;
V_15 = F_118 ( V_15 ) ;
V_198 = V_15 ;
while ( V_198 && V_83 <= V_100 ) {
V_200 = ( T_4 * ) V_198 -> V_55 ;
if ( ! V_200 -> V_14 && V_200 -> type == V_86 ) {
V_202 = ( V_74 * ) & V_200 -> V_13 ;
F_39 ( V_201 , sizeof V_201 , L_63 , V_202 [ 3 ] ,
V_202 [ 2 ] , V_202 [ 1 ] , V_202 [ 0 ] ) ;
F_131 ( V_205 , V_201 , V_206 , V_207 , NULL , & V_200 -> V_208 ) ;
V_200 -> V_14 = TRUE ;
V_83 ++ ;
}
V_198 = V_198 -> V_176 ;
}
V_198 = V_15 ;
while ( V_198 ) {
V_204 = FALSE ;
V_200 = ( T_4 * ) V_198 -> V_55 ;
if ( V_200 -> V_14 ) {
V_151 = F_132 ( V_205 , & V_200 -> V_208 , & V_203 , NULL ) ;
if ( V_151 == 0 ) {
if ( V_203 -> V_77 == V_209 ) {
F_41 ( V_200 -> V_13 , * V_203 -> V_210 . V_211 ) ;
}
V_204 = TRUE ;
}
}
V_198 = V_198 -> V_176 ;
if ( V_204 ) {
V_15 = F_119 ( V_15 , ( void * ) V_200 ) ;
F_15 ( V_200 ) ;
V_83 -- ;
}
}
return V_195 ;
}
static void
F_125 ( void ) {
void * V_212 ;
V_15 = F_118 ( V_15 ) ;
while ( V_15 ) {
V_212 = V_15 -> V_55 ;
V_15 = F_119 ( V_15 , V_212 ) ;
F_15 ( V_212 ) ;
}
if ( V_101 )
F_133 ( V_205 ) ;
V_101 = FALSE ;
}
T_3
F_117 ( void ) {
T_3 V_195 = V_36 ;
V_36 = FALSE ;
return V_195 ;
}
static void
F_125 ( void ) {
}
const T_9 *
F_54 ( const T_7 V_9 )
{
T_3 V_91 ;
T_11 * V_65 = F_44 ( V_9 , & V_91 ) ;
if ( ! V_95 . V_96 )
return V_65 -> V_90 ;
V_65 -> V_67 = V_65 -> V_67 | V_163 ;
return V_65 -> V_54 ;
}
const T_9 *
F_55 ( const struct V_8 * V_9 )
{
T_3 V_91 ;
T_16 * V_65 = F_49 ( V_9 , & V_91 ) ;
if ( ! V_95 . V_96 )
return V_65 -> V_89 ;
V_65 -> V_67 = V_65 -> V_67 | V_163 ;
return V_65 -> V_54 ;
}
void
F_41 ( const T_7 V_9 , const T_9 * V_54 )
{
T_11 * V_65 ;
if ( V_54 [ 0 ] == '\0' )
return;
V_65 = ( T_11 * ) F_12 ( V_92 , F_45 ( V_9 ) ) ;
if( V_65 ) {
F_51 ( V_65 -> V_54 , V_54 , V_53 ) ;
} else{
V_65 = F_43 ( V_9 ) ;
F_51 ( V_65 -> V_54 , V_54 , V_53 ) ;
F_14 ( V_92 , F_45 ( V_9 ) , V_65 ) ;
}
F_51 ( V_65 -> V_54 , V_54 , V_53 ) ;
V_65 -> V_67 = V_65 -> V_67 | V_98 ;
V_36 = TRUE ;
}
void
F_42 ( const struct V_8 * V_213 , const T_9 * V_54 )
{
T_16 * V_65 ;
if ( V_54 [ 0 ] == '\0' )
return;
V_65 = ( T_16 * ) F_12 ( V_102 , V_213 ) ;
if( V_65 ) {
F_51 ( V_65 -> V_54 , V_54 , V_53 ) ;
} else{
struct V_8 * V_103 ;
V_103 = F_4 ( struct V_8 , 1 ) ;
V_65 = F_47 ( V_213 ) ;
memcpy ( V_103 , V_213 , 16 ) ;
F_51 ( V_65 -> V_54 , V_54 , V_53 ) ;
F_14 ( V_102 , V_103 , V_65 ) ;
}
F_51 ( V_65 -> V_54 , V_54 , V_53 ) ;
V_65 -> V_67 = V_65 -> V_67 | V_98 ;
V_36 = TRUE ;
}
static void
F_134 ( V_16 V_55 , V_16 V_159 V_81 )
{
T_24 * V_154 = ( T_24 * ) V_55 ;
F_41 ( V_154 -> V_70 , V_154 -> V_54 ) ;
}
static void
F_135 ( V_16 V_55 , V_16 V_159 V_81 )
{
T_25 * V_155 = ( T_25 * ) V_55 ;
F_42 ( & ( V_155 -> V_107 ) , V_155 -> V_54 ) ;
}
static void
F_136 ( void )
{
if( V_157 ) {
F_137 ( V_157 , F_134 , NULL ) ;
}
if( V_156 ) {
F_137 ( V_156 , F_135 , NULL ) ;
}
}
void
F_138 ( void )
{
char * V_57 ;
T_7 V_5 ;
#ifdef V_188
#ifdef F_28
char * V_58 ;
static char V_59 [] = L_64 ;
static char V_214 [] = L_65 ;
#endif
#endif
F_9 ( V_147 == NULL ) ;
V_147 = F_29 ( V_60 , V_61 , F_15 , F_15 ) ;
F_9 ( V_92 == NULL ) ;
V_92 = F_29 ( V_215 , V_216 , NULL , F_15 ) ;
F_9 ( V_102 == NULL ) ;
V_102 = F_29 ( F_1 , F_2 , F_15 , F_15 ) ;
if( ! V_95 . V_189 ) {
V_57 = F_33 ( V_217 ) ;
if ( ! F_89 ( V_57 ) && V_183 != V_184 ) {
F_111 ( V_57 , V_183 , FALSE ) ;
}
F_15 ( V_57 ) ;
}
V_57 = F_32 ( V_217 , TRUE ) ;
if ( ! F_89 ( V_57 ) && V_183 != V_184 ) {
F_111 ( V_57 , V_183 , FALSE ) ;
}
F_15 ( V_57 ) ;
#ifdef F_5
#ifdef F_129
if ( F_139 ( V_218 ) == V_84 ) {
#endif
if ( F_140 ( & V_196 ) == V_84 && F_140 ( & V_199 ) == V_84 ) {
V_101 = TRUE ;
}
#ifdef F_129
}
#endif
#else
#ifdef V_188
#ifdef F_28
V_58 = F_30 ( L_9 ) ;
if ( V_58 != NULL ) {
if( ! V_95 . V_189 ) {
V_57 = F_31 ( V_58 , V_59 , NULL ) ;
if ( ! F_89 ( V_57 ) ) {
F_15 ( V_57 ) ;
V_57 = F_31 ( V_58 , V_214 , NULL ) ;
F_89 ( V_57 ) ;
}
F_15 ( V_57 ) ;
}
}
#else
if( ! V_95 . V_189 ) {
F_89 ( L_66 ) ;
}
#endif
if ( F_141 ( & V_205 , V_219 , 0 ) != 0 ) {
return;
}
V_101 = TRUE ;
V_83 = 0 ;
#endif
#endif
if( V_153 && ! V_95 . V_189 ) {
for ( V_5 = 0 ; V_5 < V_153 -> V_2 ; V_5 ++ ) {
F_89 ( ( const char * ) F_94 ( V_153 , V_5 ) ) ;
}
}
F_108 () ;
F_136 () ;
}
void
F_142 ( void )
{
F_125 () ;
if( V_147 ) {
F_35 ( V_147 ) ;
V_147 = NULL ;
}
if( V_92 ) {
F_35 ( V_92 ) ;
V_92 = NULL ;
}
if( V_102 ) {
F_35 ( V_102 ) ;
V_102 = NULL ;
}
memset ( V_173 , 0 , sizeof( V_173 ) ) ;
V_171 = FALSE ;
V_36 = FALSE ;
}
static void
F_143 ( V_16 V_55 , V_16 V_159 V_81 )
{
T_24 * V_154 = ( T_24 * ) V_55 ;
F_15 ( V_154 ) ;
}
static void
F_144 ( V_16 V_55 , V_16 V_159 V_81 )
{
T_25 * V_155 = ( T_25 * ) V_55 ;
F_15 ( V_155 ) ;
}
void
F_145 ( void )
{
if( V_157 ) {
F_137 ( V_157 , F_143 , NULL ) ;
F_146 ( V_157 ) ;
V_157 = NULL ;
}
if( V_156 ) {
F_137 ( V_156 , F_144 , NULL ) ;
F_146 ( V_156 ) ;
V_156 = NULL ;
}
}
T_9 *
F_147 ( T_7 V_24 )
{
if ( ! V_95 . V_187 ) {
return F_22 ( V_24 ) ;
}
return F_25 ( V_24 , V_30 ) ;
}
T_9 *
F_148 ( T_7 V_24 )
{
if ( ! V_95 . V_187 ) {
return F_22 ( V_24 ) ;
}
return F_25 ( V_24 , V_34 ) ;
}
T_9 *
F_149 ( T_7 V_24 )
{
if ( ! V_95 . V_187 ) {
return F_22 ( V_24 ) ;
}
return F_25 ( V_24 , V_28 ) ;
}
T_9 *
F_150 ( T_7 V_24 )
{
if ( ! V_95 . V_187 ) {
return F_22 ( V_24 ) ;
}
return F_25 ( V_24 , V_32 ) ;
}
const T_9 *
F_151 ( const T_17 * V_9 )
{
const T_9 * V_220 ;
V_220 = F_52 ( V_9 ) ;
if ( V_220 != NULL )
return V_220 ;
if ( V_9 -> type == V_221 ) {
return L_67 ;
}
return F_152 ( V_9 ) ;
}
const T_9 *
F_153 ( const T_17 * V_9 )
{
T_1 V_13 ;
struct V_8 V_107 ;
switch ( V_9 -> type ) {
case V_104 :
return F_53 ( ( const V_74 * ) V_9 -> V_55 ) ;
case V_105 :
memcpy ( & V_13 , V_9 -> V_55 , sizeof V_13 ) ;
return F_54 ( V_13 ) ;
case V_106 :
memcpy ( & V_107 . V_108 , V_9 -> V_55 , sizeof V_107 . V_108 ) ;
return F_55 ( & V_107 ) ;
default:
return NULL ;
}
}
void
F_154 ( const T_17 * V_9 , T_9 * V_17 , T_13 V_18 )
{
const T_9 * V_220 = F_151 ( V_9 ) ;
F_51 ( V_17 , V_220 , V_18 ) ;
}
T_9 *
F_53 ( const V_74 * V_9 )
{
T_21 * V_65 ;
T_3 V_133 = V_95 . V_186 ;
V_65 = F_78 ( V_9 , V_133 ) ;
return V_133 ? V_65 -> V_130 : V_65 -> V_136 ;
}
T_9 *
F_155 ( const V_74 * V_9 )
{
T_21 * V_65 ;
if ( ! V_95 . V_186 )
return NULL ;
V_65 = F_78 ( V_9 , TRUE ) ;
F_9 ( V_65 != NULL ) ;
if ( V_65 -> V_77 == V_131 ) {
return V_65 -> V_130 ;
}
else {
return NULL ;
}
}
V_74 *
F_156 ( const T_9 * V_54 )
{
return F_79 ( V_54 ) ;
}
void
F_157 ( const T_7 V_90 , const V_74 * V_110 )
{
T_3 V_91 ;
T_11 * V_65 ;
if ( ! V_95 . V_96 )
return;
V_65 = F_44 ( V_90 , & V_91 ) ;
if ( V_91 ) {
F_63 ( V_110 , V_65 -> V_54 ) ;
}
}
const T_9 *
F_158 ( const T_1 V_9 )
{
if ( ! V_95 . V_96 ) {
return F_159 ( V_9 , '\0' ) ;
}
return F_87 ( V_9 ) ;
}
T_1
F_160 ( const T_9 * V_54 , T_3 * V_222 )
{
T_1 V_9 ;
T_3 V_148 ;
V_9 = F_88 ( V_54 , & V_148 ) ;
* V_222 = V_148 ;
return V_9 ;
}
const T_9 *
F_161 ( const V_74 * V_9 )
{
T_9 * V_198 ;
int V_118 ;
V_74 V_121 ;
V_118 = V_9 [ 0 ] ;
V_118 = V_118 << 8 ;
V_121 = V_9 [ 1 ] ;
V_118 = V_118 | V_121 ;
V_118 = V_118 << 8 ;
V_121 = V_9 [ 2 ] ;
V_118 = V_118 | V_121 ;
if ( ! V_95 . V_186 || ( ( V_198 = ( T_9 * ) F_12 ( V_119 , & V_118 ) ) == NULL ) ) {
V_198 = F_162 ( L_68 , V_9 [ 0 ] , V_9 [ 1 ] , V_9 [ 2 ] ) ;
return V_198 ;
}
return V_198 ;
}
const T_9 *
F_163 ( const T_7 V_223 )
{
V_74 V_9 [ 3 ] ;
V_9 [ 0 ] = ( V_223 >> 16 ) & 0xFF ;
V_9 [ 1 ] = ( V_223 >> 8 ) & 0xFF ;
V_9 [ 2 ] = ( V_223 >> 0 ) & 0xFF ;
return F_161 ( V_9 ) ;
}
const T_9 *
F_164 ( T_33 * V_224 , T_20 V_225 )
{
return F_161 ( F_165 ( V_224 , V_225 , 3 ) ) ;
}
const T_9 *
F_166 ( const V_74 * V_9 )
{
T_9 * V_198 ;
int V_118 ;
V_74 V_121 ;
V_118 = V_9 [ 0 ] ;
V_118 = V_118 << 8 ;
V_121 = V_9 [ 1 ] ;
V_118 = V_118 | V_121 ;
V_118 = V_118 << 8 ;
V_121 = V_9 [ 2 ] ;
V_118 = V_118 | V_121 ;
if ( ( V_198 = ( T_9 * ) F_12 ( V_119 , & V_118 ) ) == NULL ) {
return NULL ;
}
return V_198 ;
}
const T_9 *
F_167 ( const T_7 V_118 )
{
T_9 * V_198 ;
if ( ( V_198 = ( T_9 * ) F_12 ( V_119 , & V_118 ) ) == NULL ) {
return NULL ;
}
return V_198 ;
}
const T_9 *
F_168 ( T_33 * V_224 , T_20 V_225 )
{
return F_166 ( F_165 ( V_224 , V_225 , 3 ) ) ;
}
const T_9 *
F_169 ( const T_34 V_226 )
{
T_9 * V_198 , * V_54 ;
V_74 * V_9 = ( V_74 * ) F_23 ( 8 ) ;
* ( T_34 * ) ( void * ) ( V_9 ) = F_170 ( & ( V_226 ) ) ;
if ( ! V_95 . V_186 || ( ( V_54 = F_64 ( V_9 ) ) == NULL ) ) {
V_198 = F_162 ( L_69 , V_9 [ 0 ] , V_9 [ 1 ] , V_9 [ 2 ] , V_9 [ 3 ] , V_9 [ 4 ] , V_9 [ 5 ] , V_9 [ 6 ] , V_9 [ 7 ] ) ;
return V_198 ;
}
V_198 = F_162 ( L_17 , V_54 , V_9 [ 3 ] , V_9 [ 4 ] , V_9 [ 5 ] , V_9 [ 6 ] , V_9 [ 7 ] ) ;
return V_198 ;
}
const T_9 *
F_171 ( const T_34 V_226 )
{
T_9 * V_198 , * V_54 ;
V_74 * V_9 = ( V_74 * ) F_23 ( 8 ) ;
* ( T_34 * ) ( void * ) ( V_9 ) = F_170 ( & ( V_226 ) ) ;
if ( ( V_54 = F_64 ( V_9 ) ) == NULL ) {
return NULL ;
}
V_198 = F_162 ( L_17 , V_54 , V_9 [ 3 ] , V_9 [ 4 ] , V_9 [ 5 ] , V_9 [ 6 ] , V_9 [ 7 ] ) ;
return V_198 ;
}
static void
F_172 (
void * V_76 ,
int V_77 ,
#if ( ( V_78 < 1 ) \
|| ( 1 == V_78 && V_79 < 5 ) )
struct V_80 * T_35
#else
int T_15 V_81 ,
struct V_80 * T_35
#endif
) {
T_36 * V_227 = ( T_36 * ) V_76 ;
if ( V_77 == V_84 && T_35 && V_227 && T_35 -> V_228 == V_227 -> V_229 ) {
memcpy ( V_227 -> V_213 , T_35 -> V_230 , T_35 -> V_228 ) ;
V_227 -> V_231 = T_35 -> V_228 ;
}
}
T_3
F_173 ( const char * V_232 , T_1 * V_213 )
{
struct V_233 V_234 ;
#ifdef F_5
struct V_190 V_191 = { 0 , V_235 } , * V_236 ;
int V_192 ;
T_30 V_193 , V_194 ;
T_36 V_237 ;
#else
struct V_80 * T_35 ;
#endif
if ( ! F_174 ( V_232 , & V_234 ) ) {
if ( ! V_95 . V_96 ||
! V_95 . V_97 ) {
return FALSE ;
}
#ifdef F_5
if ( ! ( V_95 . V_99 ) ||
V_100 < 1 ||
! V_101 ) {
return FALSE ;
}
V_237 . V_229 = ( int ) sizeof ( struct V_233 ) ;
V_237 . V_231 = 0 ;
V_237 . V_213 = V_213 ;
F_175 ( V_199 , V_232 , V_86 , F_172 , & V_237 ) ;
F_121 ( & V_193 ) ;
F_121 ( & V_194 ) ;
V_192 = F_122 ( V_199 , & V_193 , & V_194 ) ;
if ( V_192 > 0 ) {
V_236 = F_176 ( V_199 , & V_191 , & V_191 ) ;
if ( F_123 ( V_192 , & V_193 , & V_194 , NULL , V_236 ) == - 1 ) {
fprintf ( V_197 , L_61 , strerror ( V_183 ) ) ;
return FALSE ;
}
F_124 ( V_199 , & V_193 , & V_194 ) ;
}
F_177 ( V_199 ) ;
if ( V_237 . V_229 == V_237 . V_231 ) {
return TRUE ;
}
return FALSE ;
#else
T_35 = F_178 ( V_232 ) ;
if ( T_35 == NULL ) {
return FALSE ;
} else if ( T_35 -> V_228 <= ( int ) sizeof ( struct V_233 ) ) {
memcpy ( & V_234 , T_35 -> V_230 , T_35 -> V_228 ) ;
} else {
return FALSE ;
}
#endif
} else {
unsigned int V_138 , V_139 , V_140 , V_141 ;
if ( sscanf ( V_232 , L_70 , & V_138 , & V_139 , & V_140 , & V_141 ) != 4 )
return FALSE ;
}
* V_213 = V_234 . V_238 ;
return TRUE ;
}
T_3
F_179 ( const char * V_232 , struct V_8 * V_213 )
{
#ifdef F_5
struct V_190 V_191 = { 0 , V_235 } , * V_236 ;
int V_192 ;
T_30 V_193 , V_194 ;
T_36 V_237 ;
#elif F_114 ( V_239 )
struct V_80 * T_35 ;
#endif
if ( F_180 ( V_232 , V_213 ) )
return TRUE ;
if ( ! V_95 . V_96 ||
! V_95 . V_97 ) {
return FALSE ;
}
#ifdef F_5
if ( ! ( V_95 . V_99 ) ||
V_100 < 1 ||
! V_101 ) {
return FALSE ;
}
V_237 . V_229 = ( int ) sizeof ( struct V_8 ) ;
V_237 . V_231 = 0 ;
V_237 . V_213 = V_213 ;
F_175 ( V_199 , V_232 , V_88 , F_172 , & V_237 ) ;
F_121 ( & V_193 ) ;
F_121 ( & V_194 ) ;
V_192 = F_122 ( V_199 , & V_193 , & V_194 ) ;
if ( V_192 > 0 ) {
V_236 = F_176 ( V_199 , & V_191 , & V_191 ) ;
if ( F_123 ( V_192 , & V_193 , & V_194 , NULL , V_236 ) == - 1 ) {
fprintf ( V_197 , L_61 , strerror ( V_183 ) ) ;
return FALSE ;
}
F_124 ( V_199 , & V_193 , & V_194 ) ;
}
F_177 ( V_199 ) ;
if ( V_237 . V_229 == V_237 . V_231 ) {
return TRUE ;
}
#elif F_114 ( V_239 )
T_35 = F_181 ( V_232 , V_88 ) ;
if ( T_35 != NULL && T_35 -> V_228 == sizeof( struct V_8 ) ) {
memcpy ( V_213 , T_35 -> V_230 , T_35 -> V_228 ) ;
return TRUE ;
}
#endif
return FALSE ;
}
const char * F_182 ( const char * V_232
#ifndef V_239
V_81
#endif
)
{
#ifdef V_239
struct V_80 * V_4 ;
return ( V_4 = F_181 ( V_232 , V_88 ) ) && V_4 -> V_240 == V_88 ? L_71 : L_72 ;
#else
return L_72 ;
#endif
}
T_37 *
F_183 ( void )
{
return V_119 ;
}
T_37 *
F_184 ( void )
{
return V_120 ;
}
T_37 *
F_185 ( void )
{
return V_126 ;
}
T_37 *
F_186 ( void )
{
return V_27 ;
}
T_37 *
F_187 ( void )
{
return V_147 ;
}
T_37 *
F_188 ( void )
{
return V_92 ;
}
T_37 *
F_189 ( void )
{
return V_102 ;
}
void
F_190 ( void )
{
F_27 () ;
F_69 () ;
F_85 () ;
}
void
F_191 ( void )
{
F_34 () ;
F_72 () ;
F_86 () ;
}
T_3
F_91 ( const char * V_211 , void * V_241 )
{
return F_90 ( V_86 , V_211 , V_241 ) > 0 ;
}
T_3
F_180 ( const char * V_211 , void * V_241 )
{
return F_90 ( V_88 , V_211 , V_241 ) > 0 ;
}
