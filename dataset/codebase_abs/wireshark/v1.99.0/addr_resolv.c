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
* V_118 = ( int ) ( ( V_9 [ 0 ] << 16 ) + ( V_9 [ 1 ] << 8 ) + V_9 [ 2 ] ) ;
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
F_89 ( const char * V_57 , T_3 V_149 )
{
T_5 * V_150 ;
char * line = NULL ;
int V_18 = 0 ;
T_9 * V_37 ;
T_1 V_70 [ 4 ] ;
struct V_8 V_107 ;
T_3 V_151 , V_152 = FALSE ;
int V_153 ;
if ( ( V_150 = F_21 ( V_57 , L_7 ) ) == NULL )
return FALSE ;
while ( F_7 ( & line , & V_18 , V_150 ) >= 0 ) {
if ( ( V_37 = strchr ( line , '#' ) ) )
* V_37 = '\0' ;
if ( ( V_37 = strtok ( line , L_1 ) ) == NULL )
continue;
V_153 = F_90 ( V_88 , V_37 , & V_70 ) ;
if ( V_153 < 0 )
continue;
if ( V_153 > 0 ) {
V_151 = TRUE ;
} else {
if ( ! F_91 ( V_37 , & V_70 ) )
continue;
V_151 = FALSE ;
}
if ( ( V_37 = strtok ( NULL , L_1 ) ) == NULL )
continue;
V_152 = TRUE ;
if ( V_149 ) {
if ( V_151 ) {
memcpy ( & V_107 , V_70 , sizeof V_107 ) ;
F_42 ( & V_107 , V_37 ) ;
} else
F_41 ( V_70 [ 0 ] , V_37 ) ;
while ( ( V_37 = strtok ( NULL , L_1 ) ) != NULL ) {
if ( V_151 ) {
memcpy ( & V_107 , V_70 , sizeof V_107 ) ;
F_42 ( & V_107 , V_37 ) ;
} else
F_41 ( V_70 [ 0 ] , V_37 ) ;
}
}
}
F_15 ( line ) ;
fclose ( V_150 ) ;
return V_152 ? TRUE : FALSE ;
}
T_3
F_92 ( const char * V_154 )
{
T_3 V_91 = FALSE ;
T_7 V_5 ;
if ( ! V_154 )
return FALSE ;
if ( ! V_155 )
V_155 = F_93 () ;
for ( V_5 = 0 ; V_5 < V_155 -> V_2 ; V_5 ++ ) {
if ( strcmp ( V_154 , ( const char * ) F_94 ( V_155 , V_5 ) ) == 0 )
V_91 = TRUE ;
}
if ( ! V_91 ) {
F_95 ( V_155 , F_16 ( V_154 ) ) ;
return F_89 ( V_154 , FALSE ) ;
}
return TRUE ;
}
T_3
F_96 ( const char * V_9 , const char * V_54 )
{
T_1 V_70 [ 4 ] ;
struct V_8 V_107 ;
T_3 V_151 ;
int V_153 ;
T_24 * V_156 ;
T_25 * V_157 ;
V_153 = F_90 ( V_88 , V_9 , & V_107 ) ;
if ( V_153 < 0 )
return FALSE ;
if ( V_153 > 0 ) {
V_151 = TRUE ;
} else {
if ( ! F_91 ( V_9 , & V_70 ) )
return FALSE ;
V_151 = FALSE ;
}
if ( V_151 ) {
V_157 = F_4 ( T_25 , 1 ) ;
memcpy ( & ( V_157 -> V_107 ) , & V_107 , 16 ) ;
F_51 ( V_157 -> V_54 , V_54 , V_53 ) ;
V_158 = F_97 ( V_158 , V_157 ) ;
} else {
V_156 = F_4 ( T_24 , 1 ) ;
V_156 -> V_70 = V_70 [ 0 ] ;
F_51 ( V_156 -> V_54 , V_54 , V_53 ) ;
V_159 = F_97 ( V_159 , V_156 ) ;
}
return TRUE ;
}
static void
F_98 ( V_16 V_1 V_81 , V_16 V_160 , V_16 V_161 )
{
T_26 * V_162 = ( T_26 * ) V_161 ;
T_11 * V_163 = ( T_11 * ) V_160 ;
if( ( V_163 -> V_67 & V_164 ) == V_165 ) {
V_162 -> V_166 = F_99 ( V_162 -> V_166 , V_163 ) ;
}
}
static void
F_100 ( V_16 V_1 V_81 , V_16 V_160 , V_16 V_161 )
{
T_26 * V_162 = ( T_26 * ) V_161 ;
T_16 * V_167 = ( T_16 * ) V_160 ;
if( ( V_167 -> V_67 & V_164 ) == V_165 ) {
V_162 -> V_168 = F_99 ( V_162 -> V_168 , V_167 ) ;
}
}
T_26 *
F_101 ( void ) {
if( V_92 ) {
F_102 ( V_92 , F_98 , & V_169 ) ;
}
if( V_102 ) {
F_102 ( V_102 , F_100 , & V_169 ) ;
}
return & V_169 ;
}
static T_3
F_103 ( const char * V_170 )
{
T_5 * V_150 ;
char * line = NULL ;
int V_18 = 0 ;
T_9 * V_37 , * V_171 ;
T_1 V_70 ;
int V_75 ;
if ( ( V_150 = F_21 ( V_170 , L_7 ) ) == NULL )
return FALSE ;
while ( F_7 ( & line , & V_18 , V_150 ) >= 0 ) {
if ( ( V_37 = strchr ( line , '#' ) ) )
* V_37 = '\0' ;
if ( ( V_37 = strtok ( line , L_1 ) ) == NULL )
continue;
V_171 = strchr ( V_37 , '/' ) ;
if( NULL == V_171 ) {
continue;
}
* V_171 = '\0' ;
++ V_171 ;
if ( ! F_91 ( V_37 , & V_70 ) ) {
continue;
}
V_75 = atoi ( V_171 ) ;
if( 0 >= V_75 || V_75 > 31 ) {
continue;
}
if ( ( V_37 = strtok ( NULL , L_1 ) ) == NULL )
continue;
F_104 ( V_70 , ( T_1 ) V_75 , V_37 ) ;
}
F_15 ( line ) ;
fclose ( V_150 ) ;
return TRUE ;
}
static T_12
F_37 ( const T_1 V_9 )
{
T_12 V_66 ;
T_1 V_5 ;
V_5 = V_172 ;
while( V_173 && V_5 > 0 ) {
T_1 V_122 ;
T_27 * V_174 ;
-- V_5 ;
F_9 ( V_5 < V_172 ) ;
V_174 = & V_175 [ V_5 ] ;
if( NULL != V_174 -> V_176 ) {
T_28 * V_65 ;
T_1 V_177 ;
V_122 = V_9 & V_174 -> V_69 ;
V_177 = F_105 ( V_122 ) ;
V_65 = V_174 -> V_176 [ V_177 ] ;
while( V_65 != NULL && V_65 -> V_9 != V_122 ) {
V_65 = V_65 -> V_178 ;
}
if( NULL != V_65 ) {
V_66 . V_69 = V_174 -> V_69 ;
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
F_104 ( T_1 V_179 , const T_1 V_75 , const T_9 * V_54 )
{
T_27 * V_180 ;
T_28 * V_65 ;
T_13 V_177 ;
F_9 ( V_75 > 0 && V_75 <= 32 ) ;
V_180 = & V_175 [ V_75 - 1 ] ;
V_179 &= V_180 -> V_69 ;
V_177 = F_105 ( V_179 ) ;
if( NULL == V_180 -> V_176 ) {
V_180 -> V_176 = ( T_28 * * ) F_106 ( sizeof( T_28 * ) * V_181 ) ;
}
if( NULL != ( V_65 = V_180 -> V_176 [ V_177 ] ) ) {
if( V_65 -> V_9 == V_179 ) {
return;
} else {
T_28 * V_182 = F_107 ( T_28 ) ;
V_65 -> V_178 = V_182 ;
V_65 = V_182 ;
}
} else {
V_65 = V_180 -> V_176 [ V_177 ] = F_107 ( T_28 ) ;
}
V_65 -> V_178 = NULL ;
V_65 -> V_9 = V_179 ;
V_65 -> V_67 = V_65 -> V_67 & 0xfe ;
F_51 ( V_65 -> V_54 , V_54 , V_53 ) ;
V_173 = TRUE ;
}
static void
F_108 ( void )
{
T_9 * V_170 ;
T_1 V_5 ;
for( V_5 = 0 ; V_5 < V_172 ; ++ V_5 ) {
T_1 V_183 = V_5 + 1 ;
V_175 [ V_5 ] . V_176 = NULL ;
V_175 [ V_5 ] . V_75 = V_183 ;
V_175 [ V_5 ] . V_69 = F_109 ( F_110 ( V_183 ) ) ;
}
V_170 = F_32 ( V_184 , FALSE ) ;
if ( ! F_103 ( V_170 ) && V_185 != V_186 ) {
F_111 ( V_170 , V_185 , FALSE ) ;
}
F_15 ( V_170 ) ;
V_170 = F_33 ( V_184 ) ;
if ( ! F_103 ( V_170 ) && V_185 != V_186 ) {
F_111 ( V_170 , V_185 , FALSE ) ;
}
F_15 ( V_170 ) ;
}
void
F_112 ( T_29 * V_187 )
{
F_113 ( V_187 , L_25 ,
L_26 ,
L_27 ,
& V_95 . V_188 ) ;
F_113 ( V_187 , L_28 ,
L_29 ,
L_30 ,
& V_95 . V_189 ) ;
F_113 ( V_187 , L_31 ,
L_32 ,
L_33
L_34
L_35
L_36 ,
& V_95 . V_96 ) ;
F_113 ( V_187 , L_37 ,
L_38 ,
L_39
L_40
L_41
L_42 ,
& V_95 . V_97 ) ;
#if F_114 ( F_5 ) || F_114 ( V_190 )
F_113 ( V_187 , L_43 ,
L_44 ,
L_45
L_46
L_47 ,
& V_95 . V_99 ) ;
F_115 ( V_187 , L_48 ,
L_49 ,
L_50
L_51
L_52
L_53 ,
10 ,
& V_100 ) ;
#else
F_116 ( V_187 , L_43 ,
L_54 ,
L_55
L_56 ) ;
#endif
F_113 ( V_187 , L_57 ,
L_58 ,
L_59
L_60 ,
& V_95 . V_191 ) ;
}
T_3
F_117 ( void ) {
T_4 * V_82 ;
struct V_192 V_193 = { 0 , 0 } ;
int V_194 ;
T_30 V_195 , V_196 ;
T_3 V_197 = V_36 ;
V_36 = FALSE ;
if ( ! V_101 )
return V_197 ;
V_15 = F_118 ( V_15 ) ;
while ( V_15 != NULL && V_83 <= V_100 ) {
V_82 = ( T_4 * ) V_15 -> V_55 ;
V_15 = F_119 ( V_15 , ( void * ) V_82 ) ;
if ( V_82 -> V_11 == V_86 ) {
F_120 ( V_198 , & V_82 -> V_9 . V_12 , sizeof( T_1 ) , V_86 ,
F_40 , V_82 ) ;
V_83 ++ ;
} else if ( V_82 -> V_11 == V_88 ) {
F_120 ( V_198 , & V_82 -> V_9 . V_89 , sizeof( struct V_8 ) ,
V_88 , F_40 , V_82 ) ;
V_83 ++ ;
}
}
F_121 ( & V_195 ) ;
F_121 ( & V_196 ) ;
V_194 = F_122 ( V_198 , & V_195 , & V_196 ) ;
if ( V_194 > 0 ) {
if ( F_123 ( V_194 , & V_195 , & V_196 , NULL , & V_193 ) == - 1 ) {
fprintf ( V_199 , L_61 , F_124 ( V_185 ) ) ;
return V_197 ;
}
F_125 ( V_198 , & V_195 , & V_196 ) ;
}
return V_197 ;
}
static void
F_126 ( void ) {
T_31 * V_200 ;
V_200 = F_118 ( V_15 ) ;
while ( V_200 ) {
F_15 ( V_200 -> V_55 ) ;
V_200 = F_127 ( V_200 ) ;
}
F_128 ( V_15 ) ;
V_15 = NULL ;
if ( V_101 ) {
F_129 ( V_198 ) ;
F_129 ( V_201 ) ;
}
#ifdef F_130
F_131 () ;
#endif
V_101 = FALSE ;
}
T_3
F_117 ( void ) {
T_4 * V_202 ;
T_31 * V_200 ;
char V_203 [] = L_62 ;
V_74 * V_204 ;
T_32 * V_205 ;
int V_153 ;
T_3 V_206 ;
T_3 V_197 = V_36 ;
V_36 = FALSE ;
V_15 = F_118 ( V_15 ) ;
V_200 = V_15 ;
while ( V_200 && V_83 <= V_100 ) {
V_202 = ( T_4 * ) V_200 -> V_55 ;
if ( ! V_202 -> V_14 && V_202 -> type == V_86 ) {
V_204 = ( V_74 * ) & V_202 -> V_13 ;
F_39 ( V_203 , sizeof V_203 , L_63 , V_204 [ 3 ] ,
V_204 [ 2 ] , V_204 [ 1 ] , V_204 [ 0 ] ) ;
F_132 ( V_207 , V_203 , V_208 , V_209 , NULL , & V_202 -> V_210 ) ;
V_202 -> V_14 = TRUE ;
V_83 ++ ;
}
V_200 = V_200 -> V_178 ;
}
V_200 = V_15 ;
while ( V_200 ) {
V_206 = FALSE ;
V_202 = ( T_4 * ) V_200 -> V_55 ;
if ( V_202 -> V_14 ) {
V_153 = F_133 ( V_207 , & V_202 -> V_210 , & V_205 , NULL ) ;
if ( V_153 == 0 ) {
if ( V_205 -> V_77 == V_211 ) {
F_41 ( V_202 -> V_13 , * V_205 -> V_212 . V_213 ) ;
}
V_206 = TRUE ;
}
}
V_200 = V_200 -> V_178 ;
if ( V_206 ) {
V_15 = F_119 ( V_15 , ( void * ) V_202 ) ;
F_15 ( V_202 ) ;
V_83 -- ;
}
}
return V_197 ;
}
static void
F_126 ( void ) {
void * V_214 ;
V_15 = F_118 ( V_15 ) ;
while ( V_15 ) {
V_214 = V_15 -> V_55 ;
V_15 = F_119 ( V_15 , V_214 ) ;
F_15 ( V_214 ) ;
}
if ( V_101 )
F_134 ( V_207 ) ;
V_101 = FALSE ;
}
T_3
F_117 ( void ) {
T_3 V_197 = V_36 ;
V_36 = FALSE ;
return V_197 ;
}
static void
F_126 ( void ) {
}
const T_9 *
F_54 ( const T_7 V_9 )
{
T_3 V_91 ;
T_11 * V_65 = F_44 ( V_9 , & V_91 ) ;
if ( ! V_95 . V_96 )
return V_65 -> V_90 ;
V_65 -> V_67 = V_65 -> V_67 | V_165 ;
return V_65 -> V_54 ;
}
const T_9 *
F_55 ( const struct V_8 * V_9 )
{
T_3 V_91 ;
T_16 * V_65 = F_49 ( V_9 , & V_91 ) ;
if ( ! V_95 . V_96 )
return V_65 -> V_89 ;
V_65 -> V_67 = V_65 -> V_67 | V_165 ;
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
F_42 ( const struct V_8 * V_215 , const T_9 * V_54 )
{
T_16 * V_65 ;
if ( V_54 [ 0 ] == '\0' )
return;
V_65 = ( T_16 * ) F_12 ( V_102 , V_215 ) ;
if( V_65 ) {
F_51 ( V_65 -> V_54 , V_54 , V_53 ) ;
} else{
struct V_8 * V_103 ;
V_103 = F_4 ( struct V_8 , 1 ) ;
V_65 = F_47 ( V_215 ) ;
memcpy ( V_103 , V_215 , 16 ) ;
F_51 ( V_65 -> V_54 , V_54 , V_53 ) ;
F_14 ( V_102 , V_103 , V_65 ) ;
}
F_51 ( V_65 -> V_54 , V_54 , V_53 ) ;
V_65 -> V_67 = V_65 -> V_67 | V_98 ;
V_36 = TRUE ;
}
static void
F_135 ( V_16 V_55 , V_16 V_161 V_81 )
{
T_24 * V_156 = ( T_24 * ) V_55 ;
F_41 ( V_156 -> V_70 , V_156 -> V_54 ) ;
}
static void
F_136 ( V_16 V_55 , V_16 V_161 V_81 )
{
T_25 * V_157 = ( T_25 * ) V_55 ;
F_42 ( & ( V_157 -> V_107 ) , V_157 -> V_54 ) ;
}
static void
F_137 ( void )
{
if( V_159 ) {
F_138 ( V_159 , F_135 , NULL ) ;
}
if( V_158 ) {
F_138 ( V_158 , F_136 , NULL ) ;
}
}
void
F_139 ( void )
{
char * V_57 ;
T_7 V_5 ;
#ifdef V_190
#ifdef F_28
char * V_58 ;
static char V_59 [] = L_64 ;
static char V_216 [] = L_65 ;
#endif
#endif
F_9 ( V_147 == NULL ) ;
V_147 = F_29 ( V_60 , V_61 , F_15 , F_15 ) ;
F_9 ( V_92 == NULL ) ;
V_92 = F_29 ( V_217 , V_218 , NULL , F_15 ) ;
F_9 ( V_102 == NULL ) ;
V_102 = F_29 ( F_1 , F_2 , F_15 , F_15 ) ;
if( ! V_95 . V_191 ) {
V_57 = F_33 ( V_219 ) ;
if ( ! F_89 ( V_57 , TRUE ) && V_185 != V_186 ) {
F_111 ( V_57 , V_185 , FALSE ) ;
}
F_15 ( V_57 ) ;
}
V_57 = F_32 ( V_219 , TRUE ) ;
if ( ! F_89 ( V_57 , TRUE ) && V_185 != V_186 ) {
F_111 ( V_57 , V_185 , FALSE ) ;
}
F_15 ( V_57 ) ;
#ifdef F_5
if ( V_95 . V_99 ) {
#ifdef F_130
if ( F_140 ( V_220 ) == V_84 ) {
#endif
if ( F_141 ( & V_198 ) == V_84 && F_141 ( & V_201 ) == V_84 ) {
V_101 = TRUE ;
}
#ifdef F_130
}
#endif
}
#else
#ifdef V_190
#ifdef F_28
V_58 = F_30 ( L_9 ) ;
if ( V_58 != NULL ) {
if( ! V_95 . V_191 ) {
V_57 = F_31 ( V_58 , V_59 , NULL ) ;
if ( ! F_89 ( V_57 , TRUE ) ) {
F_15 ( V_57 ) ;
V_57 = F_31 ( V_58 , V_216 , NULL ) ;
F_89 ( V_57 , TRUE ) ;
}
F_15 ( V_57 ) ;
}
}
#else
if( ! V_95 . V_191 ) {
F_89 ( L_66 , TRUE ) ;
}
#endif
if ( V_95 . V_99 ) {
if ( F_142 ( & V_207 , V_221 , 0 ) != 0 ) {
return;
}
V_101 = TRUE ;
V_83 = 0 ;
}
#endif
#endif
if( V_155 && ! V_95 . V_191 ) {
for ( V_5 = 0 ; V_5 < V_155 -> V_2 ; V_5 ++ ) {
F_89 ( ( const char * ) F_94 ( V_155 , V_5 ) , TRUE ) ;
}
}
F_108 () ;
F_137 () ;
}
void
F_143 ( void )
{
F_126 () ;
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
memset ( V_175 , 0 , sizeof( V_175 ) ) ;
V_173 = FALSE ;
V_36 = FALSE ;
}
static void
F_144 ( V_16 V_55 , V_16 V_161 V_81 )
{
T_24 * V_156 = ( T_24 * ) V_55 ;
F_15 ( V_156 ) ;
}
static void
F_145 ( V_16 V_55 , V_16 V_161 V_81 )
{
T_25 * V_157 = ( T_25 * ) V_55 ;
F_15 ( V_157 ) ;
}
void
F_146 ( void )
{
if( V_159 ) {
F_138 ( V_159 , F_144 , NULL ) ;
F_147 ( V_159 ) ;
V_159 = NULL ;
}
if( V_158 ) {
F_138 ( V_158 , F_145 , NULL ) ;
F_147 ( V_158 ) ;
V_158 = NULL ;
}
}
T_9 *
F_148 ( T_7 V_24 )
{
if ( ! V_95 . V_189 ) {
return F_22 ( V_24 ) ;
}
return F_25 ( V_24 , V_30 ) ;
}
T_9 *
F_149 ( T_7 V_24 )
{
if ( ! V_95 . V_189 ) {
return F_22 ( V_24 ) ;
}
return F_25 ( V_24 , V_34 ) ;
}
T_9 *
F_150 ( T_7 V_24 )
{
if ( ! V_95 . V_189 ) {
return F_22 ( V_24 ) ;
}
return F_25 ( V_24 , V_28 ) ;
}
T_9 *
F_151 ( T_7 V_24 )
{
if ( ! V_95 . V_189 ) {
return F_22 ( V_24 ) ;
}
return F_25 ( V_24 , V_32 ) ;
}
const T_9 *
F_152 ( const T_17 * V_9 )
{
const T_9 * V_222 ;
V_222 = F_52 ( V_9 ) ;
if ( V_222 != NULL )
return V_222 ;
if ( V_9 -> type == V_223 ) {
return L_67 ;
}
return F_153 ( V_9 ) ;
}
const T_9 *
F_154 ( const T_17 * V_9 )
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
F_155 ( const T_17 * V_9 , T_9 * V_17 , T_13 V_18 )
{
const T_9 * V_222 = F_152 ( V_9 ) ;
F_51 ( V_17 , V_222 , V_18 ) ;
}
T_9 *
F_53 ( const V_74 * V_9 )
{
T_21 * V_65 ;
T_3 V_133 = V_95 . V_188 ;
V_65 = F_78 ( V_9 , V_133 ) ;
return V_133 ? V_65 -> V_130 : V_65 -> V_136 ;
}
T_9 *
F_156 ( const V_74 * V_9 )
{
T_21 * V_65 ;
if ( ! V_95 . V_188 )
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
F_157 ( const T_9 * V_54 )
{
return F_79 ( V_54 ) ;
}
void
F_158 ( const T_7 V_90 , const V_74 * V_110 )
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
F_159 ( const T_1 V_9 )
{
if ( ! V_95 . V_96 ) {
return F_160 ( V_9 , '\0' ) ;
}
return F_87 ( V_9 ) ;
}
T_1
F_161 ( const T_9 * V_54 , T_3 * V_224 )
{
T_1 V_9 ;
T_3 V_148 ;
V_9 = F_88 ( V_54 , & V_148 ) ;
* V_224 = V_148 ;
return V_9 ;
}
const T_9 *
F_162 ( const V_74 * V_9 )
{
T_9 * V_200 ;
int V_118 ;
V_74 V_121 ;
V_118 = V_9 [ 0 ] ;
V_118 = V_118 << 8 ;
V_121 = V_9 [ 1 ] ;
V_118 = V_118 | V_121 ;
V_118 = V_118 << 8 ;
V_121 = V_9 [ 2 ] ;
V_118 = V_118 | V_121 ;
if ( ! V_95 . V_188 || ( ( V_200 = ( T_9 * ) F_12 ( V_119 , & V_118 ) ) == NULL ) ) {
V_200 = F_163 ( L_68 , V_9 [ 0 ] , V_9 [ 1 ] , V_9 [ 2 ] ) ;
return V_200 ;
}
return V_200 ;
}
const T_9 *
F_164 ( const T_7 V_225 )
{
V_74 V_9 [ 3 ] ;
V_9 [ 0 ] = ( V_225 >> 16 ) & 0xFF ;
V_9 [ 1 ] = ( V_225 >> 8 ) & 0xFF ;
V_9 [ 2 ] = ( V_225 >> 0 ) & 0xFF ;
return F_162 ( V_9 ) ;
}
const T_9 *
F_165 ( T_33 * V_226 , T_20 V_227 )
{
return F_162 ( F_166 ( V_226 , V_227 , 3 ) ) ;
}
const T_9 *
F_167 ( const V_74 * V_9 )
{
T_9 * V_200 ;
int V_118 ;
V_74 V_121 ;
V_118 = V_9 [ 0 ] ;
V_118 = V_118 << 8 ;
V_121 = V_9 [ 1 ] ;
V_118 = V_118 | V_121 ;
V_118 = V_118 << 8 ;
V_121 = V_9 [ 2 ] ;
V_118 = V_118 | V_121 ;
if ( ( V_200 = ( T_9 * ) F_12 ( V_119 , & V_118 ) ) == NULL ) {
return NULL ;
}
return V_200 ;
}
const T_9 *
F_168 ( const T_7 V_118 )
{
T_9 * V_200 ;
if ( ( V_200 = ( T_9 * ) F_12 ( V_119 , & V_118 ) ) == NULL ) {
return NULL ;
}
return V_200 ;
}
const T_9 *
F_169 ( T_33 * V_226 , T_20 V_227 )
{
return F_167 ( F_166 ( V_226 , V_227 , 3 ) ) ;
}
const T_9 *
F_170 ( const T_34 V_228 )
{
T_9 * V_200 , * V_54 ;
V_74 * V_9 = ( V_74 * ) F_23 ( 8 ) ;
* ( T_34 * ) ( void * ) ( V_9 ) = F_171 ( & ( V_228 ) ) ;
if ( ! V_95 . V_188 || ( ( V_54 = F_64 ( V_9 ) ) == NULL ) ) {
V_200 = F_163 ( L_69 , V_9 [ 0 ] , V_9 [ 1 ] , V_9 [ 2 ] , V_9 [ 3 ] , V_9 [ 4 ] , V_9 [ 5 ] , V_9 [ 6 ] , V_9 [ 7 ] ) ;
return V_200 ;
}
V_200 = F_163 ( L_17 , V_54 , V_9 [ 3 ] , V_9 [ 4 ] , V_9 [ 5 ] , V_9 [ 6 ] , V_9 [ 7 ] ) ;
return V_200 ;
}
const T_9 *
F_172 ( const T_34 V_228 )
{
T_9 * V_200 , * V_54 ;
V_74 * V_9 = ( V_74 * ) F_23 ( 8 ) ;
* ( T_34 * ) ( void * ) ( V_9 ) = F_171 ( & ( V_228 ) ) ;
if ( ( V_54 = F_64 ( V_9 ) ) == NULL ) {
return NULL ;
}
V_200 = F_163 ( L_17 , V_54 , V_9 [ 3 ] , V_9 [ 4 ] , V_9 [ 5 ] , V_9 [ 6 ] , V_9 [ 7 ] ) ;
return V_200 ;
}
static void
F_173 (
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
T_36 * V_229 = ( T_36 * ) V_76 ;
if ( V_77 == V_84 && T_35 && V_229 && T_35 -> V_230 == V_229 -> V_231 ) {
memcpy ( V_229 -> V_215 , T_35 -> V_232 , T_35 -> V_230 ) ;
V_229 -> V_233 = T_35 -> V_230 ;
}
}
T_3
F_174 ( const char * V_234 , T_1 * V_215 )
{
struct V_235 V_236 ;
#ifdef F_5
struct V_192 V_193 = { 0 , V_237 } , * V_238 ;
int V_194 ;
T_30 V_195 , V_196 ;
T_36 V_239 ;
#else
struct V_80 * T_35 ;
#endif
if ( ! F_175 ( V_234 , & V_236 ) ) {
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
V_239 . V_231 = ( int ) sizeof ( struct V_235 ) ;
V_239 . V_233 = 0 ;
V_239 . V_215 = V_215 ;
F_176 ( V_201 , V_234 , V_86 , F_173 , & V_239 ) ;
F_121 ( & V_195 ) ;
F_121 ( & V_196 ) ;
V_194 = F_122 ( V_201 , & V_195 , & V_196 ) ;
if ( V_194 > 0 ) {
V_238 = F_177 ( V_201 , & V_193 , & V_193 ) ;
if ( F_123 ( V_194 , & V_195 , & V_196 , NULL , V_238 ) == - 1 ) {
fprintf ( V_199 , L_61 , F_124 ( V_185 ) ) ;
return FALSE ;
}
F_125 ( V_201 , & V_195 , & V_196 ) ;
}
F_178 ( V_201 ) ;
if ( V_239 . V_231 == V_239 . V_233 ) {
return TRUE ;
}
return FALSE ;
#else
T_35 = F_179 ( V_234 ) ;
if ( T_35 == NULL ) {
return FALSE ;
} else if ( T_35 -> V_230 <= ( int ) sizeof ( struct V_235 ) ) {
memcpy ( & V_236 , T_35 -> V_232 , T_35 -> V_230 ) ;
} else {
return FALSE ;
}
#endif
} else {
unsigned int V_138 , V_139 , V_140 , V_141 ;
if ( sscanf ( V_234 , L_70 , & V_138 , & V_139 , & V_140 , & V_141 ) != 4 )
return FALSE ;
}
* V_215 = V_236 . V_240 ;
return TRUE ;
}
T_3
F_180 ( const char * V_234 , struct V_8 * V_215 )
{
#ifdef F_5
struct V_192 V_193 = { 0 , V_237 } , * V_238 ;
int V_194 ;
T_30 V_195 , V_196 ;
T_36 V_239 ;
#elif F_114 ( V_241 )
struct V_80 * T_35 ;
#endif
if ( F_181 ( V_234 , V_215 ) )
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
V_239 . V_231 = ( int ) sizeof ( struct V_8 ) ;
V_239 . V_233 = 0 ;
V_239 . V_215 = V_215 ;
F_176 ( V_201 , V_234 , V_88 , F_173 , & V_239 ) ;
F_121 ( & V_195 ) ;
F_121 ( & V_196 ) ;
V_194 = F_122 ( V_201 , & V_195 , & V_196 ) ;
if ( V_194 > 0 ) {
V_238 = F_177 ( V_201 , & V_193 , & V_193 ) ;
if ( F_123 ( V_194 , & V_195 , & V_196 , NULL , V_238 ) == - 1 ) {
fprintf ( V_199 , L_61 , F_124 ( V_185 ) ) ;
return FALSE ;
}
F_125 ( V_201 , & V_195 , & V_196 ) ;
}
F_178 ( V_201 ) ;
if ( V_239 . V_231 == V_239 . V_233 ) {
return TRUE ;
}
#elif F_114 ( V_241 )
T_35 = F_182 ( V_234 , V_88 ) ;
if ( T_35 != NULL && T_35 -> V_230 == sizeof( struct V_8 ) ) {
memcpy ( V_215 , T_35 -> V_232 , T_35 -> V_230 ) ;
return TRUE ;
}
#endif
return FALSE ;
}
const char * F_183 ( const char * V_234
#ifndef V_241
V_81
#endif
)
{
#ifdef V_241
struct V_80 * V_4 ;
return ( V_4 = F_182 ( V_234 , V_88 ) ) && V_4 -> V_242 == V_88 ? L_71 : L_72 ;
#else
return L_72 ;
#endif
}
T_37 *
F_184 ( void )
{
return V_119 ;
}
T_37 *
F_185 ( void )
{
return V_120 ;
}
T_37 *
F_186 ( void )
{
return V_126 ;
}
T_37 *
F_187 ( void )
{
return V_27 ;
}
T_37 *
F_188 ( void )
{
return V_147 ;
}
T_37 *
F_189 ( void )
{
return V_92 ;
}
T_37 *
F_190 ( void )
{
return V_102 ;
}
void
F_191 ( void )
{
F_27 () ;
F_69 () ;
F_85 () ;
}
void
F_192 ( void )
{
F_34 () ;
F_72 () ;
F_86 () ;
}
T_3
F_91 ( const char * V_213 , void * V_243 )
{
return F_90 ( V_86 , V_213 , V_243 ) > 0 ;
}
T_3
F_181 ( const char * V_213 , void * V_243 )
{
return F_90 ( V_88 , V_213 , V_243 ) > 0 ;
}
