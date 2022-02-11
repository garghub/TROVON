static T_1
F_1 ( T_2 V_1 ,
T_2 V_2 )
{
return * ( ( const V_3 * ) V_1 ) == * ( ( const V_3 * ) V_2 ) ;
}
static T_3
F_2 ( T_2 V_4 )
{
return ( T_3 ) * ( const V_3 * ) V_4 ;
}
static T_4
F_3 ( T_2 V_5 )
{
int V_6 = 16 ;
const unsigned char * V_7 = ( const unsigned char * ) V_5 ;
T_4 V_8 = 0 ;
int V_9 ;
for ( V_9 = 0 ; V_9 < V_6 ; V_9 ++ ) {
V_8 += V_7 [ V_9 ] ;
V_8 += ( V_8 << 10 ) ;
V_8 ^= ( V_8 >> 6 ) ;
}
V_8 += ( V_8 << 3 ) ;
V_8 ^= ( V_8 >> 11 ) ;
V_8 += ( V_8 << 15 ) ;
return V_8 ;
}
static T_1
F_4 ( T_2 V_1 , T_2 V_2 )
{
if( memcmp ( V_1 , V_2 , sizeof ( struct V_10 ) ) == 0 ) {
return TRUE ;
}
return FALSE ;
}
static void
F_5 ( int type , T_4 V_11 )
{
T_5 * V_12 ;
V_12 = F_6 ( T_5 , 1 ) ;
#ifdef F_7
V_12 -> V_13 = type ;
V_12 -> V_11 . V_14 = V_11 ;
#else
V_12 -> type = type ;
V_12 -> V_15 = V_11 ;
V_12 -> V_16 = FALSE ;
#endif
V_17 = F_8 ( V_17 , ( V_18 ) V_12 ) ;
}
static int
F_9 ( char * * V_19 , int * V_20 , T_6 * V_21 )
{
int V_6 ;
int V_22 ;
if ( V_21 == NULL || V_19 == NULL )
return - 1 ;
if ( * V_19 == NULL ) {
if ( * V_20 == 0 )
* V_20 = V_23 ;
* V_19 = ( char * ) F_10 ( * V_20 ) ;
}
F_11 ( * V_19 ) ;
F_11 ( * V_20 > 0 ) ;
if ( feof ( V_21 ) )
return - 1 ;
V_6 = 0 ;
while ( ( V_22 = getc ( V_21 ) ) != V_24 && V_22 != '\r' && V_22 != '\n' ) {
if ( V_6 + 1 >= * V_20 ) {
* V_19 = ( char * ) F_12 ( * V_19 , * V_20 += V_23 ) ;
}
( * V_19 ) [ V_6 ++ ] = V_22 ;
}
if ( V_6 == 0 && V_22 == V_24 )
return - 1 ;
( * V_19 ) [ V_6 ] = '\0' ;
return V_6 ;
}
static void
F_13 ( T_7 V_25 , const T_3 V_26 , const char * V_27 )
{
T_8 * V_28 ;
int * V_5 ;
V_5 = ( int * ) F_6 ( int , 1 ) ;
* V_5 = V_26 ;
V_28 = ( T_8 * ) F_14 ( V_29 , & V_26 ) ;
if ( V_28 == NULL ) {
V_28 = F_15 ( T_8 , 1 ) ;
F_16 ( V_29 , V_5 , V_28 ) ;
}
else {
F_17 ( V_5 ) ;
}
switch( V_25 ) {
case V_30 :
F_17 ( V_28 -> V_31 ) ;
V_28 -> V_31 = F_18 ( V_27 ) ;
break;
case V_32 :
F_17 ( V_28 -> V_33 ) ;
V_28 -> V_33 = F_18 ( V_27 ) ;
break;
case V_34 :
F_17 ( V_28 -> V_35 ) ;
V_28 -> V_35 = F_18 ( V_27 ) ;
break;
case V_36 :
F_17 ( V_28 -> V_37 ) ;
V_28 -> V_37 = F_18 ( V_27 ) ;
break;
default:
return;
}
V_38 = TRUE ;
}
static void
F_19 ( char * line )
{
T_9 * V_39 ;
T_9 * V_40 ;
T_9 * V_26 ;
T_7 V_25 ;
T_10 * V_41 = NULL ;
T_4 V_42 = V_43 ;
if ( ( V_39 = strchr ( line , '#' ) ) )
* V_39 = '\0' ;
if ( ( V_39 = strtok ( line , L_1 ) ) == NULL )
return;
V_40 = V_39 ;
if ( ( V_39 = strtok ( NULL , L_1 ) ) == NULL )
return;
V_26 = V_39 ;
if ( strtok ( V_39 , L_2 ) == NULL )
return;
if ( ( V_39 = strtok ( NULL , L_2 ) ) == NULL )
return;
if( strcmp ( V_39 , L_3 ) == 0 ) {
V_42 = V_44 ;
V_25 = V_30 ;
}
else if( strcmp ( V_39 , L_4 ) == 0 ) {
V_42 = V_43 ;
V_25 = V_32 ;
}
else if( strcmp ( V_39 , L_5 ) == 0 ) {
V_42 = V_45 ;
V_25 = V_34 ;
}
else if( strcmp ( V_39 , L_6 ) == 0 ) {
V_42 = V_46 ;
V_25 = V_36 ;
} else {
return;
}
if( V_47 != F_20 ( & V_41 , V_26 , V_42 ) ) {
return;
}
V_48 = V_40 ;
V_49 = V_25 ;
F_21 ( V_41 , V_50 ) ;
F_17 ( V_41 ) ;
V_49 = V_51 ;
}
static void
V_50 ( const T_4 V_26 )
{
if ( V_26 ) {
F_13 ( V_49 , V_26 , V_48 ) ;
}
}
static void
F_22 ( const char * V_52 )
{
T_6 * V_53 ;
static int V_20 = 0 ;
static char * V_19 = NULL ;
V_53 = F_23 ( V_52 , L_7 ) ;
if ( V_53 == NULL )
return;
while ( F_9 ( & V_19 , & V_20 , V_53 ) >= 0 ) {
F_19 ( V_19 ) ;
}
fclose ( V_53 ) ;
}
static T_9 *
F_24 ( T_3 V_26 )
{
T_9 * V_54 = ( T_9 * ) F_25 ( V_55 ) ;
F_26 ( V_26 , V_54 , V_55 ) ;
return V_54 ;
}
static T_9
* F_27 ( const T_3 V_26 , const T_7 V_25 )
{
T_8 * V_28 ;
T_9 * V_56 ;
V_28 = ( T_8 * ) F_14 ( V_29 , & V_26 ) ;
if( V_28 ) {
switch( V_25 ) {
case V_32 :
if( V_28 -> V_33 ) {
return V_28 -> V_33 ;
}
break;
case V_30 :
if( V_28 -> V_31 ) {
return V_28 -> V_31 ;
}
break;
case V_34 :
if( V_28 -> V_35 ) {
return V_28 -> V_35 ;
}
break;
case V_36 :
if( V_28 -> V_37 ) {
return V_28 -> V_37 ;
}
break;
default:
return NULL ;
}
}
V_56 = ( T_9 * ) F_10 ( 16 ) ;
F_26 ( V_26 , V_56 , 16 ) ;
if( V_28 == NULL ) {
int * V_5 ;
V_5 = ( int * ) F_6 ( int , 1 ) ;
* V_5 = V_26 ;
V_28 = F_15 ( T_8 , 1 ) ;
F_16 ( V_29 , V_5 , V_28 ) ;
}
switch( V_25 ) {
case V_32 :
V_28 -> V_33 = V_56 ;
break;
case V_30 :
V_28 -> V_31 = V_56 ;
break;
case V_34 :
V_28 -> V_35 = V_56 ;
break;
case V_36 :
V_28 -> V_37 = V_56 ;
break;
default:
return NULL ;
}
return V_56 ;
}
static void
F_28 ( V_18 V_57 )
{
T_8 * V_58 = ( T_8 * ) V_57 ;
F_17 ( V_58 -> V_33 ) ;
F_17 ( V_58 -> V_31 ) ;
F_17 ( V_58 -> V_35 ) ;
F_17 ( V_58 -> V_37 ) ;
F_17 ( V_58 ) ;
}
static void
F_29 ( void )
{
#ifdef F_30
char * V_59 ;
char * V_60 ;
static char V_61 [] = L_8 ;
#endif
F_11 ( V_29 == NULL ) ;
V_29 = F_31 ( V_62 , V_63 , F_17 , F_28 ) ;
#ifdef F_30
V_60 = F_32 ( L_9 ) ;
if ( V_60 != NULL ) {
V_59 = F_33 ( V_60 , V_61 , NULL ) ;
F_22 ( V_59 ) ;
F_17 ( V_59 ) ;
}
#else
F_22 ( L_10 ) ;
#endif
if ( V_64 == NULL )
V_64 = F_34 ( V_65 , FALSE ) ;
F_22 ( V_64 ) ;
if ( V_66 == NULL ) {
V_66 = F_35 ( V_65 ) ;
}
F_22 ( V_66 ) ;
}
static void
F_36 ( void )
{
if( V_29 ) {
F_37 ( V_29 ) ;
V_29 = NULL ;
}
}
static void
F_38 ( const T_3 V_11 , T_11 * volatile V_67 )
{
T_12 V_68 ;
if ( ( V_67 -> V_69 & V_70 ) == V_70 )
return;
V_67 -> V_69 = V_67 -> V_69 | V_70 ;
V_68 = F_39 ( V_11 ) ;
if( 0 != V_68 . V_71 ) {
T_4 V_72 ;
T_9 V_73 [ V_74 ] ;
T_9 * V_75 ;
T_13 V_9 ;
V_72 = V_11 & ( ~ ( T_4 ) V_68 . V_71 ) ;
F_40 ( ( V_76 * ) & V_72 , V_73 , V_74 ) ;
V_75 = V_73 ;
V_9 = V_68 . V_77 / 8 ;
while( * ( V_75 ) != '\0' && V_9 > 0 ) {
if( * ( ++ V_75 ) == '.' ) {
-- V_9 ;
}
}
F_41 ( V_67 -> V_56 , V_55 , L_11 , V_68 . V_56 , V_75 ) ;
} else {
F_40 ( ( const V_76 * ) & V_11 , V_67 -> V_56 , V_55 ) ;
}
}
static void
F_42 (
void * V_78 ,
int V_79 ,
#if ( ( V_80 < 1 ) \
|| ( 1 == V_80 && V_81 < 5 ) )
struct V_82 * T_14
#else
int T_15 V_83 ,
struct V_82 * T_14
#endif
) {
T_5 * V_84 = ( T_5 * ) V_78 ;
char * * V_7 ;
if ( ! V_84 ) return;
V_85 -- ;
if ( V_79 == V_86 ) {
for ( V_7 = T_14 -> V_87 ; * V_7 != NULL ; V_7 ++ ) {
switch( V_84 -> V_13 ) {
case V_88 :
F_43 ( V_84 -> V_11 . V_14 , T_14 -> V_89 ) ;
break;
case V_90 :
F_44 ( & V_84 -> V_11 . V_91 , T_14 -> V_89 ) ;
break;
default:
break;
}
}
}
F_17 ( V_84 ) ;
}
static T_11 *
F_45 ( const T_3 V_11 )
{
T_11 * V_67 = F_6 ( T_11 , 1 ) ;
V_67 -> V_11 = V_11 ;
V_67 -> V_69 = 0 ;
F_40 ( ( const V_76 * ) & V_11 , V_67 -> V_92 , sizeof( V_67 -> V_92 ) ) ;
return V_67 ;
}
static T_11 *
F_46 ( const T_3 V_11 , T_1 * V_93 )
{
T_11 * volatile V_67 ;
* V_93 = TRUE ;
V_67 = ( T_11 * ) F_14 ( V_94 , & V_11 ) ;
if( V_67 == NULL ) {
int * V_5 ;
V_5 = ( int * ) F_6 ( int , 1 ) ;
* V_5 = V_11 ;
V_67 = F_45 ( V_11 ) ;
F_16 ( V_94 , V_5 , V_67 ) ;
} else{
if ( ( V_67 -> V_69 & V_95 ) == V_70 ) {
goto V_96;
}
if ( ( V_67 -> V_69 & V_70 ) == V_70 ) {
* V_93 = FALSE ;
}
return V_67 ;
}
V_96:
if ( V_97 . V_98 && V_97 . V_99 ) {
V_67 -> V_69 = V_67 -> V_69 | V_100 ;
#ifdef F_47
if ( V_97 . V_101 &&
V_102 > 0 &&
V_103 ) {
F_5 ( V_88 , V_11 ) ;
F_38 ( V_11 , V_67 ) ;
return V_67 ;
}
#endif
}
* V_93 = FALSE ;
F_38 ( V_11 , V_67 ) ;
return V_67 ;
}
static T_16 *
F_48 ( const struct V_10 * V_11 )
{
T_16 * V_67 = F_6 ( T_16 , 1 ) ;
V_67 -> V_11 = * V_11 ;
V_67 -> V_69 = 0 ;
F_49 ( V_11 , V_67 -> V_91 ) ;
return V_67 ;
}
static T_16 *
F_50 ( const struct V_10 * V_11 , T_1 * V_93 )
{
T_16 * volatile V_67 ;
#ifdef F_51
#ifdef F_7
T_5 * V_84 ;
#endif
#endif
* V_93 = TRUE ;
V_67 = ( T_16 * ) F_14 ( V_104 , V_11 ) ;
if( V_67 == NULL ) {
struct V_10 * V_105 ;
V_105 = F_6 ( struct V_10 , 1 ) ;
V_67 = F_48 ( V_11 ) ;
memcpy ( V_105 , V_11 , 16 ) ;
F_16 ( V_104 , V_105 , V_67 ) ;
} else{
if ( ( V_67 -> V_69 & V_95 ) == V_70 ) {
goto V_96;
}
if ( ( V_67 -> V_69 & V_70 ) == V_70 ) {
* V_93 = FALSE ;
}
return V_67 ;
}
V_96:
if ( V_97 . V_98 &&
V_97 . V_99 ) {
V_67 -> V_69 = V_67 -> V_69 | V_100 ;
#ifdef F_51
#ifdef F_7
if ( ( V_97 . V_101 ) &&
V_102 > 0 &&
V_103 ) {
V_84 = F_6 ( T_5 , 1 ) ;
V_84 -> V_13 = V_90 ;
memcpy ( & V_84 -> V_11 . V_91 , V_11 , sizeof( V_84 -> V_11 . V_91 ) ) ;
V_17 = F_8 ( V_17 , ( V_18 ) V_84 ) ;
if ( ( V_67 -> V_69 & V_70 ) == 0 ) {
F_52 ( V_67 -> V_56 , V_67 -> V_91 , V_55 ) ;
F_49 ( V_11 , V_67 -> V_56 ) ;
V_67 -> V_69 = V_67 -> V_69 | V_70 ;
}
return V_67 ;
}
#endif
#endif
}
if ( ( V_67 -> V_69 & V_70 ) == 0 ) {
V_67 -> V_69 = V_67 -> V_69 | V_70 ;
F_52 ( V_67 -> V_56 , V_67 -> V_91 , V_55 ) ;
}
* V_93 = FALSE ;
return V_67 ;
}
static const T_9 *
F_53 ( const T_17 * V_11 )
{
switch ( V_11 -> type ) {
case V_106 :
return F_54 ( ( const V_76 * ) V_11 -> V_57 ) ;
case V_107 : {
T_4 V_15 ;
memcpy ( & V_15 , V_11 -> V_57 , sizeof V_15 ) ;
return F_55 ( V_15 ) ;
}
case V_108 : {
struct V_10 V_109 ;
memcpy ( & V_109 . V_110 , V_11 -> V_57 , sizeof V_109 . V_110 ) ;
return F_56 ( & V_109 ) ;
}
case V_111 :
return ( const T_9 * ) V_11 -> V_57 ;
default:
return NULL ;
}
}
static const T_9 *
F_57 ( const T_17 * V_11 )
{
switch ( V_11 -> type ) {
case V_106 :
return F_54 ( ( const V_76 * ) V_11 -> V_57 ) ;
case V_107 : {
T_4 V_15 ;
memcpy ( & V_15 , V_11 -> V_57 , sizeof V_15 ) ;
return F_55 ( V_15 ) ;
}
case V_108 : {
struct V_10 V_109 ;
memcpy ( & V_109 . V_110 , V_11 -> V_57 , sizeof V_109 . V_110 ) ;
return F_56 ( & V_109 ) ;
}
case V_111 :
return F_58 ( ( const T_9 * ) V_11 -> V_57 ) ;
default:
return NULL ;
}
}
static T_1
F_59 ( const char * V_39 , T_18 * V_112 , unsigned int * V_71 ,
const T_1 V_113 )
{
int V_9 ;
unsigned long V_114 ;
char * V_7 ;
char V_115 = '\0' ;
for ( V_9 = 0 ; V_9 < 6 ; V_9 ++ ) {
if ( ! isxdigit ( ( unsigned char ) * V_39 ) )
return FALSE ;
V_114 = strtoul ( V_39 , & V_7 , 16 ) ;
if ( V_7 == V_39 )
return FALSE ;
if ( V_114 > 0xFF )
return FALSE ;
V_112 -> V_11 [ V_9 ] = ( V_76 ) V_114 ;
V_39 = V_7 ;
if ( * V_39 == '/' ) {
if ( ! V_113 ) {
return FALSE ;
}
V_39 ++ ;
if ( ! isdigit ( ( unsigned char ) * V_39 ) )
return FALSE ;
V_114 = strtoul ( V_39 , & V_7 , 10 ) ;
if ( V_7 == V_39 )
return FALSE ;
V_39 = V_7 ;
if ( * V_39 != '\0' && ! isspace ( ( unsigned char ) * V_39 ) )
return FALSE ;
if ( V_114 == 0 || V_114 >= 48 )
return FALSE ;
* V_71 = ( int ) V_114 ;
for ( V_9 = 0 ; V_114 >= 8 ; V_9 ++ , V_114 -= 8 )
;
V_112 -> V_11 [ V_9 ] &= ( 0xFF << ( 8 - V_114 ) ) ;
V_9 ++ ;
for (; V_9 < 6 ; V_9 ++ )
V_112 -> V_11 [ V_9 ] = 0 ;
return TRUE ;
}
if ( * V_39 == '\0' ) {
if ( V_9 == 2 ) {
if ( ! V_113 ) {
return FALSE ;
}
* V_71 = 0 ;
return TRUE ;
}
if ( V_9 == 5 ) {
if ( V_113 )
* V_71 = 48 ;
return TRUE ;
}
return FALSE ;
} else {
if ( V_115 == '\0' ) {
if ( * V_39 != ':' && * V_39 != '-' && * V_39 != '.' )
return FALSE ;
V_115 = * V_39 ;
} else {
if ( * V_39 != V_115 )
return FALSE ;
}
}
V_39 ++ ;
}
return TRUE ;
}
static int
F_60 ( char * line , T_18 * V_112 , unsigned int * V_71 ,
const T_1 V_113 )
{
T_9 * V_39 ;
if ( ( V_39 = strchr ( line , '#' ) ) )
* V_39 = '\0' ;
if ( ( V_39 = strtok ( line , L_1 ) ) == NULL )
return - 1 ;
if ( ! F_59 ( V_39 , V_112 , V_71 , V_113 ) )
return - 1 ;
if ( ( V_39 = strtok ( NULL , L_1 ) ) == NULL )
return - 1 ;
F_52 ( V_112 -> V_56 , V_39 , V_55 ) ;
return 0 ;
}
static void
F_61 ( char * V_52 )
{
if ( V_116 )
rewind ( V_116 ) ;
else
V_116 = F_23 ( V_52 , L_7 ) ;
}
static void
F_62 ( void )
{
if ( V_116 ) {
fclose ( V_116 ) ;
V_116 = NULL ;
}
}
static T_18 *
F_63 ( unsigned int * V_71 , const T_1 V_113 )
{
static T_18 V_112 ;
static int V_20 = 0 ;
static char * V_19 = NULL ;
if ( V_116 == NULL )
return NULL ;
while ( F_9 ( & V_19 , & V_20 , V_116 ) >= 0 ) {
if ( F_60 ( V_19 , & V_112 , V_71 , V_113 ) == 0 ) {
return & V_112 ;
}
}
return NULL ;
}
static T_18 *
F_64 ( const V_76 * V_11 )
{
T_18 * V_112 ;
F_61 ( V_117 ) ;
while ( ( ( V_112 = F_63 ( NULL , FALSE ) ) != NULL ) && memcmp ( V_11 , V_112 -> V_11 , 6 ) != 0 )
;
if ( V_112 == NULL ) {
F_62 () ;
F_61 ( V_118 ) ;
while ( ( ( V_112 = F_63 ( NULL , FALSE ) ) != NULL ) && memcmp ( V_11 , V_112 -> V_11 , 6 ) != 0 )
;
F_62 () ;
}
return V_112 ;
}
static void
F_65 ( const V_76 * V_11 , unsigned int V_71 , T_9 * V_56 )
{
V_76 V_119 ;
V_3 V_120 , * V_121 ;
int V_122 , * V_123 ;
if ( V_71 >= 48 ) {
F_66 ( V_11 , V_56 ) ;
return;
}
V_120 = V_11 [ 0 ] ;
V_120 = V_120 << 8 ;
V_119 = V_11 [ 1 ] ;
V_120 = V_120 | V_119 ;
V_120 = V_120 << 8 ;
V_119 = V_11 [ 2 ] ;
V_120 = V_120 | V_119 ;
V_120 = V_120 << 8 ;
V_119 = V_11 [ 3 ] ;
V_120 = V_120 | V_119 ;
V_120 = V_120 << 8 ;
V_119 = V_11 [ 4 ] ;
V_120 = V_120 | V_119 ;
V_120 = V_120 << 8 ;
V_119 = V_11 [ 5 ] ;
V_120 = V_120 | V_119 ;
if ( V_71 == 0 ) {
V_123 = ( int * ) F_6 ( int , 1 ) ;
V_122 = ( int ) ( V_120 >> 24 ) & 0xffffff ;
* V_123 = V_122 ;
F_16 ( V_124 , V_123 , F_18 ( V_56 ) ) ;
return;
}
V_121 = ( V_3 * ) F_6 ( V_3 , 1 ) ;
* V_121 = V_120 ;
F_16 ( V_125 , V_121 , F_18 ( V_56 ) ) ;
}
T_9 *
F_67 ( const V_76 * V_11 )
{
T_19 V_123 = 0 ;
V_76 V_119 ;
T_9 * V_56 ;
V_123 = V_11 [ 0 ] ;
V_123 = V_123 << 8 ;
V_119 = V_11 [ 1 ] ;
V_123 = V_123 | V_119 ;
V_123 = V_123 << 8 ;
V_119 = V_11 [ 2 ] ;
V_123 = V_123 | V_119 ;
V_56 = ( T_9 * ) F_14 ( V_124 , & V_123 ) ;
if( V_56 != NULL ) {
return V_56 ;
}
if( ( V_123 & 0x00010000 ) != 0 ) {
V_123 &= 0x00FEFFFF ;
V_56 = ( T_9 * ) F_14 ( V_124 , & V_123 ) ;
if( V_56 != NULL ) {
return V_56 ;
}
}
return NULL ;
}
static T_9 *
F_68 ( const V_76 * V_11 , const unsigned int V_71 )
{
V_76 V_126 [ 6 ] ;
T_3 V_114 ;
T_20 V_9 ;
V_3 V_120 ;
V_76 V_119 ;
T_9 * V_56 ;
if( V_125 == NULL ) {
return NULL ;
}
for ( V_9 = 0 , V_114 = V_71 ; V_114 >= 8 ; V_9 ++ , V_114 -= 8 )
V_126 [ V_9 ] = V_11 [ V_9 ] ;
V_126 [ V_9 ] = V_11 [ V_9 ] & ( 0xFF << ( 8 - V_114 ) ) ;
V_9 ++ ;
for (; V_9 < 6 ; V_9 ++ )
V_126 [ V_9 ] = 0 ;
V_120 = V_126 [ 0 ] ;
V_120 = V_120 << 8 ;
V_119 = V_126 [ 1 ] ;
V_120 = V_120 | V_119 ;
V_120 = V_120 << 8 ;
V_119 = V_126 [ 2 ] ;
V_120 = V_120 | V_119 ;
V_120 = V_120 << 8 ;
V_119 = V_126 [ 3 ] ;
V_120 = V_120 | V_119 ;
V_120 = V_120 << 8 ;
V_119 = V_126 [ 4 ] ;
V_120 = V_120 | V_119 ;
V_120 = V_120 << 8 ;
V_119 = V_126 [ 5 ] ;
V_120 = V_120 | V_119 ;
V_56 = ( T_9 * ) F_14 ( V_125 , & V_120 ) ;
return V_56 ;
}
static void
F_69 ( void )
{
T_18 * V_112 ;
char * V_127 ;
T_3 V_71 ;
V_125 = F_31 ( F_2 , F_1 , F_17 , F_17 ) ;
V_124 = F_31 ( V_62 , V_63 , F_17 , F_17 ) ;
V_128 = F_31 ( F_2 , F_1 , F_17 , F_17 ) ;
if ( V_118 == NULL ) {
V_118 = F_70 ( L_12 V_129 L_12 ,
F_71 () , V_130 ) ;
}
if ( V_117 == NULL )
V_117 = F_34 ( V_130 , FALSE ) ;
V_127 = F_35 ( V_131 ) ;
F_61 ( V_127 ) ;
while ( ( V_112 = F_63 ( & V_71 , TRUE ) ) ) {
F_65 ( V_112 -> V_11 , V_71 , V_112 -> V_56 ) ;
}
F_62 () ;
F_17 ( V_127 ) ;
}
static void
F_72 ( void )
{
if( V_124 ) {
F_37 ( V_124 ) ;
V_124 = NULL ;
}
if( V_125 ) {
F_37 ( V_125 ) ;
V_125 = NULL ;
}
if( V_128 ) {
F_37 ( V_128 ) ;
V_128 = NULL ;
}
}
static T_21 *
F_73 ( T_21 * V_67 ) {
T_18 * V_112 ;
const V_76 * V_11 = V_67 -> V_11 ;
if ( ( V_112 = F_64 ( V_11 ) ) != NULL ) {
F_52 ( V_67 -> V_132 , V_112 -> V_56 , V_55 ) ;
V_67 -> V_79 = V_133 ;
return V_67 ;
} else {
T_3 V_71 ;
T_9 * V_56 ;
V_71 = 7 ;
for (; ; ) {
if ( ( V_56 = F_68 ( V_11 , V_71 + 40 ) ) != NULL ) {
F_41 ( V_67 -> V_132 , V_55 , L_13 ,
V_56 , V_11 [ 5 ] & ( 0xFF >> V_71 ) ) ;
V_67 -> V_79 = V_134 ;
return V_67 ;
}
if ( V_71 == 0 )
break;
V_71 -- ;
}
V_71 = 7 ;
for (; ; ) {
if ( ( V_56 = F_68 ( V_11 , V_71 + 32 ) ) != NULL ) {
F_41 ( V_67 -> V_132 , V_55 , L_14 ,
V_56 , V_11 [ 4 ] & ( 0xFF >> V_71 ) , V_11 [ 5 ] ) ;
V_67 -> V_79 = V_134 ;
return V_67 ;
}
if ( V_71 == 0 )
break;
V_71 -- ;
}
V_71 = 7 ;
for (; ; ) {
if ( ( V_56 = F_68 ( V_11 , V_71 + 24 ) ) != NULL ) {
F_41 ( V_67 -> V_132 , V_55 , L_15 ,
V_56 , V_11 [ 3 ] & ( 0xFF >> V_71 ) , V_11 [ 4 ] , V_11 [ 5 ] ) ;
V_67 -> V_79 = V_134 ;
return V_67 ;
}
if ( V_71 == 0 )
break;
V_71 -- ;
}
if ( ( V_56 = F_67 ( V_11 ) ) != NULL ) {
F_41 ( V_67 -> V_132 , V_55 , L_15 ,
V_56 , V_11 [ 3 ] , V_11 [ 4 ] , V_11 [ 5 ] ) ;
V_67 -> V_79 = V_134 ;
return V_67 ;
}
V_71 = 7 ;
for (; ; ) {
if ( ( V_56 = F_68 ( V_11 , V_71 + 16 ) ) != NULL ) {
F_41 ( V_67 -> V_132 , V_55 , L_16 ,
V_56 , V_11 [ 2 ] & ( 0xFF >> V_71 ) , V_11 [ 3 ] , V_11 [ 4 ] ,
V_11 [ 5 ] ) ;
V_67 -> V_79 = V_134 ;
return V_67 ;
}
if ( V_71 == 0 )
break;
V_71 -- ;
}
V_71 = 7 ;
for (; ; ) {
if ( ( V_56 = F_68 ( V_11 , V_71 + 8 ) ) != NULL ) {
F_41 ( V_67 -> V_132 , V_55 , L_17 ,
V_56 , V_11 [ 1 ] & ( 0xFF >> V_71 ) , V_11 [ 2 ] , V_11 [ 3 ] ,
V_11 [ 4 ] , V_11 [ 5 ] ) ;
V_67 -> V_79 = V_134 ;
return V_67 ;
}
if ( V_71 == 0 )
break;
V_71 -- ;
}
for ( V_71 = 7 ; V_71 > 0 ; V_71 -- ) {
if ( ( V_56 = F_68 ( V_11 , V_71 ) ) != NULL ) {
F_41 ( V_67 -> V_132 , V_55 , L_18 ,
V_56 , V_11 [ 0 ] & ( 0xFF >> V_71 ) , V_11 [ 1 ] , V_11 [ 2 ] ,
V_11 [ 3 ] , V_11 [ 4 ] , V_11 [ 5 ] ) ;
V_67 -> V_79 = V_134 ;
return V_67 ;
}
}
F_41 ( V_67 -> V_132 , V_55 , L_12 , F_74 ( V_11 ) ) ;
V_67 -> V_79 = V_134 ;
return V_67 ;
}
F_75 () ;
}
static V_3
F_76 ( const V_76 * V_11 )
{
V_76 V_119 ;
V_3 V_120 ;
V_120 = V_11 [ 0 ] ;
V_120 = V_120 << 8 ;
V_119 = V_11 [ 1 ] ;
V_120 = V_120 | V_119 ;
V_120 = V_120 << 8 ;
V_119 = V_11 [ 2 ] ;
V_120 = V_120 | V_119 ;
V_120 = V_120 << 8 ;
V_119 = V_11 [ 3 ] ;
V_120 = V_120 | V_119 ;
V_120 = V_120 << 8 ;
V_119 = V_11 [ 4 ] ;
V_120 = V_120 | V_119 ;
V_120 = V_120 << 8 ;
V_119 = V_11 [ 5 ] ;
V_120 = V_120 | V_119 ;
return V_120 ;
}
static T_21 *
F_77 ( const V_76 * V_11 , const T_1 V_135 )
{
T_21 * V_67 ;
V_3 V_120 , * V_5 ;
V_120 = F_76 ( V_11 ) ;
V_5 = ( V_3 * ) F_6 ( V_3 , 1 ) ;
* V_5 = V_120 ;
V_67 = F_6 ( T_21 , 1 ) ;
memcpy ( V_67 -> V_11 , V_11 , sizeof( V_67 -> V_11 ) ) ;
V_67 -> V_79 = V_136 ;
F_52 ( V_67 -> V_137 , F_78 ( V_11 , sizeof( V_67 -> V_11 ) , ':' ) , sizeof( V_67 -> V_137 ) ) ;
V_67 -> V_132 [ 0 ] = '\0' ;
if ( V_135 )
F_73 ( V_67 ) ;
F_16 ( V_128 , V_5 , V_67 ) ;
return V_67 ;
}
static T_21 *
F_66 ( const V_76 * V_11 , const T_9 * V_56 )
{
T_21 * V_67 ;
V_3 V_120 ;
V_120 = F_76 ( V_11 ) ;
V_67 = ( T_21 * ) F_14 ( V_128 , & V_120 ) ;
if( V_67 == NULL ) {
V_67 = F_77 ( V_11 , FALSE ) ;
}
F_52 ( V_67 -> V_132 , V_56 , V_55 ) ;
V_67 -> V_79 = V_133 ;
V_38 = TRUE ;
return V_67 ;
}
static T_21 *
F_79 ( const V_76 * V_11 , const T_1 V_135 )
{
T_21 * V_67 ;
V_3 V_120 ;
V_120 = F_76 ( V_11 ) ;
V_67 = ( T_21 * ) F_14 ( V_128 , & V_120 ) ;
if( V_67 == NULL ) {
V_67 = F_77 ( V_11 , V_135 ) ;
} else {
if ( V_135 && ( V_67 -> V_79 == V_136 ) ) {
F_73 ( V_67 ) ;
}
}
return V_67 ;
}
static V_76 *
F_80 ( const T_9 * V_56 V_83 )
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
F_81 ( char * line , T_22 * V_138 )
{
T_9 * V_39 ;
T_4 V_139 , V_140 , V_141 , V_142 , V_143 ;
T_1 V_144 = FALSE ;
if ( ( V_39 = strchr ( line , '#' ) ) )
* V_39 = '\0' ;
if ( ( V_39 = strtok ( line , L_19 ) ) == NULL )
return - 1 ;
if ( sscanf ( V_39 , L_20 , & V_140 , & V_141 , & V_142 , & V_143 ) != 4 ) {
if ( sscanf ( V_39 , L_21 , & V_140 , & V_141 , & V_142 , & V_143 ) != 4 ) {
if ( sscanf ( V_39 , L_22 , & V_140 , & V_141 , & V_142 , & V_143 ) != 4 ) {
if ( sscanf ( V_39 , L_23 , & V_139 ) == 1 ) {
V_144 = TRUE ;
}
else {
return - 1 ;
}
}
}
}
if ( ( V_39 = strtok ( NULL , L_19 ) ) == NULL )
return - 1 ;
if ( V_144 ) {
V_138 -> V_11 = V_139 ;
}
else {
V_138 -> V_11 = ( V_140 << 24 ) | ( V_141 << 16 ) | ( V_142 << 8 ) | V_143 ;
}
F_52 ( V_138 -> V_56 , V_39 , V_55 ) ;
return 0 ;
}
static void
F_82 ( char * V_52 )
{
if ( V_145 )
rewind ( V_145 ) ;
else
V_145 = F_23 ( V_52 , L_7 ) ;
}
static void
F_83 ( void )
{
if ( V_145 ) {
fclose ( V_145 ) ;
V_145 = NULL ;
}
}
static T_22 *
F_84 ( void )
{
static T_22 V_138 ;
static int V_20 = 0 ;
static char * V_19 = NULL ;
if ( V_145 == NULL )
return NULL ;
while ( F_9 ( & V_19 , & V_20 , V_145 ) >= 0 ) {
if ( F_81 ( V_19 , & V_138 ) == 0 ) {
return & V_138 ;
}
}
return NULL ;
}
static T_22 *
F_85 ( T_4 V_11 )
{
T_22 * V_138 ;
F_82 ( V_146 ) ;
while ( ( ( V_138 = F_84 () ) != NULL ) && ( V_11 != V_138 -> V_11 ) ) ;
if ( V_138 == NULL ) {
F_83 () ;
F_82 ( V_147 ) ;
while ( ( ( V_138 = F_84 () ) != NULL ) && ( V_11 != V_138 -> V_11 ) )
;
F_83 () ;
}
return V_138 ;
}
static void
F_86 ( void )
{
if ( V_146 == NULL ) {
V_146 = F_70 ( L_12 V_129 L_12 ,
F_71 () , V_148 ) ;
}
if ( V_147 == NULL )
V_147 = F_34 ( V_148 , FALSE ) ;
}
static void
F_87 ( void )
{
if( V_149 ) {
F_37 ( V_149 ) ;
V_149 = NULL ;
}
}
static T_9 *
F_88 ( const T_3 V_11 )
{
T_23 * V_67 ;
T_22 * V_138 ;
V_67 = ( T_23 * ) F_14 ( V_149 , & V_11 ) ;
if( V_67 == NULL ) {
int * V_5 ;
V_5 = ( int * ) F_6 ( int , 1 ) ;
* V_5 = V_11 ;
V_67 = F_6 ( T_23 , 1 ) ;
F_16 ( V_149 , V_5 , V_67 ) ;
} else{
return V_67 -> V_56 ;
}
V_67 -> V_11 = V_11 ;
if ( ( V_138 = F_85 ( V_11 ) ) == NULL ) {
F_41 ( V_67 -> V_56 , V_55 , L_24 , V_11 ) ;
} else {
F_52 ( V_67 -> V_56 , V_138 -> V_56 , V_55 ) ;
}
return ( V_67 -> V_56 ) ;
}
static T_3
F_89 ( const T_9 * V_56 V_83 , T_1 * V_150 )
{
* V_150 = FALSE ;
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
static T_1
F_90 ( const char * V_59 )
{
T_6 * V_151 ;
char * line = NULL ;
int V_20 = 0 ;
T_9 * V_39 ;
T_4 V_72 [ 4 ] ;
struct V_10 V_109 ;
T_1 V_152 ;
int V_153 ;
if ( ( V_151 = F_23 ( V_59 , L_7 ) ) == NULL )
return FALSE ;
while ( F_9 ( & line , & V_20 , V_151 ) >= 0 ) {
if ( ( V_39 = strchr ( line , '#' ) ) )
* V_39 = '\0' ;
if ( ( V_39 = strtok ( line , L_1 ) ) == NULL )
continue;
V_153 = F_91 ( V_90 , V_39 , & V_72 ) ;
if ( V_153 < 0 )
continue;
if ( V_153 > 0 ) {
V_152 = TRUE ;
} else {
if ( F_91 ( V_88 , V_39 , & V_72 ) <= 0 )
continue;
V_152 = FALSE ;
}
if ( ( V_39 = strtok ( NULL , L_1 ) ) == NULL )
continue;
if ( V_152 ) {
memcpy ( & V_109 , V_72 , sizeof V_109 ) ;
F_44 ( & V_109 , V_39 ) ;
} else
F_43 ( V_72 [ 0 ] , V_39 ) ;
while ( ( V_39 = strtok ( NULL , L_1 ) ) != NULL ) {
if ( V_152 ) {
memcpy ( & V_109 , V_72 , sizeof V_109 ) ;
F_44 ( & V_109 , V_39 ) ;
} else
F_43 ( V_72 [ 0 ] , V_39 ) ;
}
}
F_17 ( line ) ;
fclose ( V_151 ) ;
return TRUE ;
}
T_1
F_92 ( const char * V_154 )
{
T_1 V_93 = FALSE ;
T_3 V_9 ;
if ( ! V_154 )
return FALSE ;
if ( ! V_155 )
V_155 = F_93 () ;
for ( V_9 = 0 ; V_9 < V_155 -> V_6 ; V_9 ++ ) {
if ( strcmp ( V_154 , ( const char * ) F_94 ( V_155 , V_9 ) ) == 0 )
V_93 = TRUE ;
}
if ( ! V_93 ) {
F_95 ( V_155 , F_18 ( V_154 ) ) ;
return F_90 ( V_154 ) ;
}
return TRUE ;
}
T_1
F_96 ( const char * V_11 , const char * V_56 )
{
T_4 V_72 [ 4 ] ;
struct V_10 V_109 ;
T_1 V_152 ;
int V_153 ;
V_153 = F_91 ( V_90 , V_11 , & V_109 ) ;
if ( V_153 < 0 )
return FALSE ;
if ( V_153 > 0 ) {
V_152 = TRUE ;
} else {
if ( F_91 ( V_88 , V_11 , & V_72 ) <= 0 )
return FALSE ;
V_152 = FALSE ;
}
if ( V_152 ) {
F_44 ( & V_109 , V_56 ) ;
} else {
F_43 ( V_72 [ 0 ] , V_56 ) ;
}
return TRUE ;
}
static void
F_97 ( V_18 V_5 V_83 , V_18 V_156 , V_18 V_157 )
{
T_24 * V_158 = ( T_24 * ) V_157 ;
T_11 * V_159 = ( T_11 * ) V_156 ;
if( ( V_159 -> V_69 & V_160 ) == V_161 ) {
V_158 -> V_162 = F_98 ( V_158 -> V_162 , V_159 ) ;
}
}
static void
F_99 ( V_18 V_5 V_83 , V_18 V_156 , V_18 V_157 )
{
T_24 * V_158 = ( T_24 * ) V_157 ;
T_16 * V_163 = ( T_16 * ) V_156 ;
if( ( V_163 -> V_69 & V_160 ) == V_161 ) {
V_158 -> V_164 = F_98 ( V_158 -> V_164 , V_163 ) ;
}
}
T_24 *
F_100 ( void ) {
if( V_94 ) {
F_101 ( V_94 , F_97 , & V_165 ) ;
}
if( V_104 ) {
F_101 ( V_104 , F_99 , & V_165 ) ;
}
return & V_165 ;
}
static T_1
F_102 ( const char * V_166 )
{
T_6 * V_151 ;
char * line = NULL ;
int V_20 = 0 ;
T_9 * V_39 , * V_167 ;
T_4 V_72 ;
int V_77 ;
if ( ( V_151 = F_23 ( V_166 , L_7 ) ) == NULL )
return FALSE ;
while ( F_9 ( & line , & V_20 , V_151 ) >= 0 ) {
if ( ( V_39 = strchr ( line , '#' ) ) )
* V_39 = '\0' ;
if ( ( V_39 = strtok ( line , L_1 ) ) == NULL )
continue;
V_167 = strchr ( V_39 , '/' ) ;
if( NULL == V_167 ) {
continue;
}
* V_167 = '\0' ;
++ V_167 ;
if ( F_91 ( V_88 , V_39 , & V_72 ) <= 0 ) {
continue;
}
V_77 = atoi ( V_167 ) ;
if( 0 >= V_77 || V_77 > 31 ) {
continue;
}
if ( ( V_39 = strtok ( NULL , L_1 ) ) == NULL )
continue;
F_103 ( V_72 , ( T_4 ) V_77 , V_39 ) ;
}
F_17 ( line ) ;
fclose ( V_151 ) ;
return TRUE ;
}
static T_12
F_39 ( const T_4 V_11 )
{
T_12 V_68 ;
T_4 V_9 ;
V_9 = V_168 ;
while( V_169 && V_9 > 0 ) {
T_4 V_126 ;
T_25 * V_170 ;
-- V_9 ;
F_11 ( V_9 < V_168 ) ;
V_170 = & V_171 [ V_9 ] ;
if( NULL != V_170 -> V_172 ) {
T_26 * V_67 ;
T_4 V_173 ;
V_126 = V_11 & V_170 -> V_71 ;
V_173 = F_104 ( V_126 ) ;
V_67 = V_170 -> V_172 [ V_173 ] ;
while( V_67 != NULL && V_67 -> V_11 != V_126 ) {
V_67 = V_67 -> V_174 ;
}
if( NULL != V_67 ) {
V_68 . V_71 = V_170 -> V_71 ;
V_68 . V_77 = V_9 + 1 ;
V_68 . V_56 = V_67 -> V_56 ;
return V_68 ;
}
}
}
V_68 . V_71 = 0 ;
V_68 . V_77 = 0 ;
V_68 . V_56 = NULL ;
return V_68 ;
}
static void
F_103 ( T_4 V_175 , const T_4 V_77 , const T_9 * V_56 )
{
T_25 * V_176 ;
T_26 * V_67 ;
T_13 V_173 ;
F_11 ( V_77 > 0 && V_77 <= 32 ) ;
V_176 = & V_171 [ V_77 - 1 ] ;
V_175 &= V_176 -> V_71 ;
V_173 = F_104 ( V_175 ) ;
if( NULL == V_176 -> V_172 ) {
V_176 -> V_172 = ( T_26 * * ) F_105 ( sizeof( T_26 * ) * V_177 ) ;
}
if( NULL != ( V_67 = V_176 -> V_172 [ V_173 ] ) ) {
if( V_67 -> V_11 == V_175 ) {
return;
} else {
T_26 * V_178 = F_106 ( T_26 ) ;
V_67 -> V_174 = V_178 ;
V_67 = V_178 ;
}
} else {
V_67 = V_176 -> V_172 [ V_173 ] = F_106 ( T_26 ) ;
}
V_67 -> V_174 = NULL ;
V_67 -> V_11 = V_175 ;
V_67 -> V_69 = V_67 -> V_69 & 0xfe ;
F_52 ( V_67 -> V_56 , V_56 , V_55 ) ;
V_169 = TRUE ;
}
static void
F_107 ( void )
{
T_9 * V_166 ;
T_4 V_9 ;
for( V_9 = 0 ; V_9 < V_168 ; ++ V_9 ) {
T_4 V_179 = V_9 + 1 ;
V_171 [ V_9 ] . V_172 = NULL ;
V_171 [ V_9 ] . V_77 = V_179 ;
V_171 [ V_9 ] . V_71 = F_108 ( F_109 ( V_179 ) ) ;
}
V_166 = F_34 ( V_180 , FALSE ) ;
if ( ! F_102 ( V_166 ) && V_181 != V_182 ) {
F_110 ( V_166 , V_181 , FALSE ) ;
}
F_17 ( V_166 ) ;
V_166 = F_35 ( V_180 ) ;
if ( ! F_102 ( V_166 ) && V_181 != V_182 ) {
F_110 ( V_166 , V_181 , FALSE ) ;
}
F_17 ( V_166 ) ;
}
void
F_111 ( T_27 * V_183 )
{
F_112 ( V_183 , L_25 ,
L_26 ,
L_27 ,
& V_97 . V_184 ) ;
F_112 ( V_183 , L_28 ,
L_29 ,
L_30 ,
& V_97 . V_185 ) ;
F_112 ( V_183 , L_31 ,
L_32 ,
L_33
L_34
L_35
L_36 ,
& V_97 . V_98 ) ;
F_112 ( V_183 , L_37 ,
L_38 ,
L_39
L_40
L_41
L_42 ,
& V_97 . V_99 ) ;
#if F_113 ( F_7 ) || F_113 ( V_186 )
F_112 ( V_183 , L_43 ,
L_44 ,
L_45
L_46
L_47 ,
& V_97 . V_101 ) ;
F_114 ( V_183 , L_48 ,
L_49 ,
L_50
L_51
L_52
L_53 ,
10 ,
& V_102 ) ;
#else
F_115 ( V_183 , L_43 ,
L_54 ,
L_55
L_56 ) ;
#endif
F_112 ( V_183 , L_57 ,
L_58 ,
L_59
L_60 ,
& V_97 . V_187 ) ;
}
T_1
F_116 ( void ) {
T_5 * V_84 ;
struct V_188 V_189 = { 0 , 0 } ;
int V_190 ;
T_28 V_191 , V_192 ;
T_1 V_193 = V_38 ;
V_38 = FALSE ;
if ( ! V_103 )
return V_193 ;
V_17 = F_117 ( V_17 ) ;
while ( V_17 != NULL && V_85 <= V_102 ) {
V_84 = ( T_5 * ) V_17 -> V_57 ;
V_17 = F_118 ( V_17 , ( void * ) V_84 ) ;
if ( V_84 -> V_13 == V_88 ) {
F_119 ( V_194 , & V_84 -> V_11 . V_14 , sizeof( T_4 ) , V_88 ,
F_42 , V_84 ) ;
V_85 ++ ;
} else if ( V_84 -> V_13 == V_90 ) {
F_119 ( V_194 , & V_84 -> V_11 . V_91 , sizeof( struct V_10 ) ,
V_90 , F_42 , V_84 ) ;
V_85 ++ ;
}
}
F_120 ( & V_191 ) ;
F_120 ( & V_192 ) ;
V_190 = F_121 ( V_194 , & V_191 , & V_192 ) ;
if ( V_190 > 0 ) {
if ( F_122 ( V_190 , & V_191 , & V_192 , NULL , & V_189 ) == - 1 ) {
fprintf ( V_195 , L_61 , strerror ( V_181 ) ) ;
return V_193 ;
}
F_123 ( V_194 , & V_191 , & V_192 ) ;
}
return V_193 ;
}
static void
F_124 ( void ) {
T_29 * V_196 ;
V_196 = F_117 ( V_17 ) ;
while ( V_196 ) {
F_17 ( V_196 -> V_57 ) ;
V_196 = F_125 ( V_196 ) ;
}
F_126 ( V_17 ) ;
V_17 = NULL ;
if ( V_103 ) {
F_127 ( V_194 ) ;
F_127 ( V_197 ) ;
}
#ifdef F_128
F_129 () ;
#endif
V_103 = FALSE ;
}
T_1
F_116 ( void ) {
T_5 * V_198 ;
T_29 * V_196 ;
char V_199 [] = L_62 ;
V_76 * V_200 ;
T_30 * V_201 ;
int V_153 ;
T_1 V_202 ;
T_1 V_193 = V_38 ;
V_38 = FALSE ;
V_17 = F_117 ( V_17 ) ;
V_196 = V_17 ;
while ( V_196 && V_85 <= V_102 ) {
V_198 = ( T_5 * ) V_196 -> V_57 ;
if ( ! V_198 -> V_16 && V_198 -> type == V_88 ) {
V_200 = ( V_76 * ) & V_198 -> V_15 ;
F_41 ( V_199 , sizeof V_199 , L_63 , V_200 [ 3 ] ,
V_200 [ 2 ] , V_200 [ 1 ] , V_200 [ 0 ] ) ;
F_130 ( V_203 , V_199 , V_204 , V_205 , NULL , & V_198 -> V_206 ) ;
V_198 -> V_16 = TRUE ;
V_85 ++ ;
}
V_196 = V_196 -> V_174 ;
}
V_196 = V_17 ;
while ( V_196 ) {
V_202 = FALSE ;
V_198 = ( T_5 * ) V_196 -> V_57 ;
if ( V_198 -> V_16 ) {
V_153 = F_131 ( V_203 , & V_198 -> V_206 , & V_201 , NULL ) ;
if ( V_153 == 0 ) {
if ( V_201 -> V_79 == V_207 ) {
F_43 ( V_198 -> V_15 , * V_201 -> V_208 . V_209 ) ;
}
V_202 = TRUE ;
}
}
V_196 = V_196 -> V_174 ;
if ( V_202 ) {
V_17 = F_118 ( V_17 , ( void * ) V_198 ) ;
F_17 ( V_198 ) ;
V_85 -- ;
}
}
return V_193 ;
}
static void
F_124 ( void ) {
void * V_210 ;
V_17 = F_117 ( V_17 ) ;
while ( V_17 ) {
V_210 = V_17 -> V_57 ;
V_17 = F_118 ( V_17 , V_210 ) ;
F_17 ( V_210 ) ;
}
if ( V_103 )
F_132 ( V_203 ) ;
V_103 = FALSE ;
}
T_1
F_116 ( void ) {
T_1 V_193 = V_38 ;
V_38 = FALSE ;
return V_193 ;
}
static void
F_124 ( void ) {
}
const T_9 *
F_55 ( const T_3 V_11 )
{
T_1 V_93 ;
T_11 * V_67 = F_46 ( V_11 , & V_93 ) ;
if ( ! V_97 . V_98 )
return V_67 -> V_92 ;
V_67 -> V_69 = V_67 -> V_69 | V_161 ;
return V_67 -> V_56 ;
}
const T_9 *
F_56 ( const struct V_10 * V_11 )
{
T_1 V_93 ;
T_16 * V_67 = F_50 ( V_11 , & V_93 ) ;
if ( ! V_97 . V_98 )
return V_67 -> V_91 ;
V_67 -> V_69 = V_67 -> V_69 | V_161 ;
return V_67 -> V_56 ;
}
void
F_43 ( const T_3 V_11 , const T_9 * V_56 )
{
T_11 * V_67 ;
if ( V_56 [ 0 ] == '\0' )
return;
V_67 = ( T_11 * ) F_14 ( V_94 , & V_11 ) ;
if( V_67 ) {
F_52 ( V_67 -> V_56 , V_56 , V_55 ) ;
} else{
int * V_5 ;
V_5 = ( int * ) F_6 ( int , 1 ) ;
* V_5 = V_11 ;
V_67 = F_45 ( V_11 ) ;
F_52 ( V_67 -> V_56 , V_56 , V_55 ) ;
F_16 ( V_94 , V_5 , V_67 ) ;
}
F_52 ( V_67 -> V_56 , V_56 , V_55 ) ;
V_67 -> V_69 = V_67 -> V_69 | V_100 ;
V_38 = TRUE ;
}
void
F_44 ( const struct V_10 * V_211 , const T_9 * V_56 )
{
T_16 * V_67 ;
if ( V_56 [ 0 ] == '\0' )
return;
V_67 = ( T_16 * ) F_14 ( V_104 , V_211 ) ;
if( V_67 ) {
F_52 ( V_67 -> V_56 , V_56 , V_55 ) ;
} else{
struct V_10 * V_105 ;
V_105 = F_6 ( struct V_10 , 1 ) ;
V_67 = F_48 ( V_211 ) ;
memcpy ( V_105 , V_211 , 16 ) ;
F_52 ( V_67 -> V_56 , V_56 , V_55 ) ;
F_16 ( V_104 , V_105 , V_67 ) ;
}
F_52 ( V_67 -> V_56 , V_56 , V_55 ) ;
V_67 -> V_69 = V_67 -> V_69 | V_100 ;
V_38 = TRUE ;
}
void
F_133 ( void )
{
char * V_59 ;
T_3 V_9 ;
#ifdef V_186
#ifdef F_30
char * V_60 ;
static char V_61 [] = L_64 ;
static char V_212 [] = L_65 ;
#endif
#endif
F_11 ( V_149 == NULL ) ;
V_149 = F_31 ( V_62 , V_63 , F_17 , F_17 ) ;
F_11 ( V_94 == NULL ) ;
V_94 = F_31 ( V_62 , V_63 , F_17 , F_17 ) ;
F_11 ( V_104 == NULL ) ;
V_104 = F_31 ( F_3 , F_4 , F_17 , F_17 ) ;
if( ! V_97 . V_187 ) {
V_59 = F_35 ( V_213 ) ;
if ( ! F_90 ( V_59 ) && V_181 != V_182 ) {
F_110 ( V_59 , V_181 , FALSE ) ;
}
F_17 ( V_59 ) ;
}
V_59 = F_34 ( V_213 , TRUE ) ;
if ( ! F_90 ( V_59 ) && V_181 != V_182 ) {
F_110 ( V_59 , V_181 , FALSE ) ;
}
F_17 ( V_59 ) ;
#ifdef F_7
#ifdef F_128
if ( F_134 ( V_214 ) == V_86 ) {
#endif
if ( F_135 ( & V_194 ) == V_86 && F_135 ( & V_197 ) == V_86 ) {
V_103 = TRUE ;
}
#ifdef F_128
}
#endif
#else
#ifdef V_186
#ifdef F_30
V_60 = F_32 ( L_9 ) ;
if ( V_60 != NULL ) {
if( ! V_97 . V_187 ) {
V_59 = F_33 ( V_60 , V_61 , NULL ) ;
if ( ! F_90 ( V_59 ) ) {
F_17 ( V_59 ) ;
V_59 = F_33 ( V_60 , V_212 , NULL ) ;
F_90 ( V_59 ) ;
}
F_17 ( V_59 ) ;
}
}
#else
if( ! V_97 . V_187 ) {
F_90 ( L_66 ) ;
}
#endif
if ( F_136 ( & V_203 , V_215 , 0 ) != 0 ) {
return;
}
V_103 = TRUE ;
V_85 = 0 ;
#endif
#endif
if( V_155 && ! V_97 . V_187 ) {
for ( V_9 = 0 ; V_9 < V_155 -> V_6 ; V_9 ++ ) {
F_90 ( ( const char * ) F_94 ( V_155 , V_9 ) ) ;
}
}
F_107 () ;
}
void
F_137 ( void )
{
F_124 () ;
if( V_149 ) {
F_37 ( V_149 ) ;
V_149 = NULL ;
}
if( V_94 ) {
F_37 ( V_94 ) ;
V_94 = NULL ;
}
if( V_104 ) {
F_37 ( V_104 ) ;
V_104 = NULL ;
}
memset ( V_171 , 0 , sizeof( V_171 ) ) ;
V_169 = FALSE ;
V_38 = FALSE ;
}
T_9 *
F_138 ( T_3 V_26 )
{
if ( ! V_97 . V_185 ) {
return F_24 ( V_26 ) ;
}
return F_27 ( V_26 , V_32 ) ;
}
T_9 *
F_139 ( T_3 V_26 )
{
if ( ! V_97 . V_185 ) {
return F_24 ( V_26 ) ;
}
return F_27 ( V_26 , V_36 ) ;
}
T_9 *
F_140 ( T_3 V_26 )
{
if ( ! V_97 . V_185 ) {
return F_24 ( V_26 ) ;
}
return F_27 ( V_26 , V_30 ) ;
}
T_9 *
F_141 ( T_3 V_26 )
{
if ( ! V_97 . V_185 ) {
return F_24 ( V_26 ) ;
}
return F_27 ( V_26 , V_34 ) ;
}
const T_9 *
F_142 ( const T_17 * V_11 )
{
const T_9 * V_216 ;
V_216 = F_53 ( V_11 ) ;
if ( V_216 != NULL )
return V_216 ;
if ( V_11 -> type == V_217 ) {
return L_67 ;
}
return F_143 ( V_11 ) ;
}
const T_9 *
F_144 ( const T_17 * V_11 )
{
const T_9 * V_216 ;
V_216 = F_57 ( V_11 ) ;
if ( V_216 != NULL )
return V_216 ;
if ( V_11 -> type == V_217 ) {
return L_67 ;
}
return F_145 ( V_11 ) ;
}
void
F_146 ( const T_17 * V_11 , T_9 * V_19 , T_13 V_20 )
{
const T_9 * V_216 = F_142 ( V_11 ) ;
F_52 ( V_19 , V_216 , V_20 ) ;
}
T_9 *
F_54 ( const V_76 * V_11 )
{
T_21 * V_67 ;
T_1 V_135 = V_97 . V_184 ;
V_67 = F_79 ( V_11 , V_135 ) ;
return V_135 ? V_67 -> V_132 : V_67 -> V_137 ;
}
T_9 *
F_147 ( const V_76 * V_11 )
{
T_21 * V_67 ;
if ( ! V_97 . V_184 )
return NULL ;
V_67 = F_79 ( V_11 , TRUE ) ;
F_11 ( V_67 != NULL ) ;
if ( V_67 -> V_79 == V_133 ) {
return V_67 -> V_132 ;
}
else {
return NULL ;
}
}
V_76 *
F_148 ( const T_9 * V_56 )
{
return F_80 ( V_56 ) ;
}
void
F_149 ( const T_3 V_92 , const V_76 * V_112 )
{
T_1 V_93 ;
T_11 * V_67 ;
if ( ! V_97 . V_98 )
return;
V_67 = F_46 ( V_92 , & V_93 ) ;
if ( V_93 ) {
F_66 ( V_112 , V_67 -> V_56 ) ;
}
}
const T_9 *
F_150 ( const T_4 V_11 )
{
if ( ! V_97 . V_98 ) {
return F_151 ( V_11 , '\0' ) ;
}
return F_88 ( V_11 ) ;
}
T_4
F_152 ( const T_9 * V_56 , T_1 * V_218 )
{
T_4 V_11 ;
T_1 V_150 ;
V_11 = F_89 ( V_56 , & V_150 ) ;
* V_218 = V_150 ;
return V_11 ;
}
const T_9 *
F_153 ( const V_76 * V_11 )
{
T_9 * V_196 ;
int V_123 ;
V_76 V_119 ;
V_123 = V_11 [ 0 ] ;
V_123 = V_123 << 8 ;
V_119 = V_11 [ 1 ] ;
V_123 = V_123 | V_119 ;
V_123 = V_123 << 8 ;
V_119 = V_11 [ 2 ] ;
V_123 = V_123 | V_119 ;
if ( ! V_97 . V_184 || ( ( V_196 = ( T_9 * ) F_14 ( V_124 , & V_123 ) ) == NULL ) ) {
V_196 = F_154 ( L_68 , V_11 [ 0 ] , V_11 [ 1 ] , V_11 [ 2 ] ) ;
return V_196 ;
}
return V_196 ;
}
const T_9 *
F_155 ( const T_3 V_219 )
{
V_76 V_11 [ 3 ] ;
V_11 [ 0 ] = ( V_219 >> 16 ) & 0xFF ;
V_11 [ 1 ] = ( V_219 >> 8 ) & 0xFF ;
V_11 [ 2 ] = ( V_219 >> 0 ) & 0xFF ;
return F_153 ( V_11 ) ;
}
const T_9 *
F_156 ( T_31 * V_220 , T_20 V_221 )
{
return F_153 ( F_157 ( V_220 , V_221 , 3 ) ) ;
}
const T_9 *
F_158 ( const V_76 * V_11 )
{
T_9 * V_196 ;
int V_123 ;
V_76 V_119 ;
V_123 = V_11 [ 0 ] ;
V_123 = V_123 << 8 ;
V_119 = V_11 [ 1 ] ;
V_123 = V_123 | V_119 ;
V_123 = V_123 << 8 ;
V_119 = V_11 [ 2 ] ;
V_123 = V_123 | V_119 ;
if ( ( V_196 = ( T_9 * ) F_14 ( V_124 , & V_123 ) ) == NULL ) {
return NULL ;
}
return V_196 ;
}
const T_9 *
F_159 ( const T_3 V_123 )
{
T_9 * V_196 ;
if ( ( V_196 = ( T_9 * ) F_14 ( V_124 , & V_123 ) ) == NULL ) {
return NULL ;
}
return V_196 ;
}
const T_9 *
F_160 ( T_31 * V_220 , T_20 V_221 )
{
return F_158 ( F_157 ( V_220 , V_221 , 3 ) ) ;
}
const T_9 *
F_161 ( const T_32 V_222 )
{
T_9 * V_196 , * V_56 ;
V_76 * V_11 = ( V_76 * ) F_25 ( 8 ) ;
* ( T_32 * ) ( void * ) ( V_11 ) = F_162 ( & ( V_222 ) ) ;
if ( ! V_97 . V_184 || ( ( V_56 = F_67 ( V_11 ) ) == NULL ) ) {
V_196 = F_154 ( L_69 , V_11 [ 0 ] , V_11 [ 1 ] , V_11 [ 2 ] , V_11 [ 3 ] , V_11 [ 4 ] , V_11 [ 5 ] , V_11 [ 6 ] , V_11 [ 7 ] ) ;
return V_196 ;
}
V_196 = F_154 ( L_17 , V_56 , V_11 [ 3 ] , V_11 [ 4 ] , V_11 [ 5 ] , V_11 [ 6 ] , V_11 [ 7 ] ) ;
return V_196 ;
}
const T_9 *
F_163 ( const T_32 V_222 )
{
T_9 * V_196 , * V_56 ;
V_76 * V_11 = ( V_76 * ) F_25 ( 8 ) ;
* ( T_32 * ) ( void * ) ( V_11 ) = F_162 ( & ( V_222 ) ) ;
if ( ( V_56 = F_67 ( V_11 ) ) == NULL ) {
return NULL ;
}
V_196 = F_154 ( L_17 , V_56 , V_11 [ 3 ] , V_11 [ 4 ] , V_11 [ 5 ] , V_11 [ 6 ] , V_11 [ 7 ] ) ;
return V_196 ;
}
static void
F_164 (
void * V_78 ,
int V_79 ,
#if ( ( V_80 < 1 ) \
|| ( 1 == V_80 && V_81 < 5 ) )
struct V_82 * T_33
#else
int T_15 V_83 ,
struct V_82 * T_33
#endif
) {
T_34 * V_223 = ( T_34 * ) V_78 ;
if ( V_79 == V_86 && T_33 && V_223 && T_33 -> V_224 == V_223 -> V_225 ) {
memcpy ( V_223 -> V_211 , T_33 -> V_226 , T_33 -> V_224 ) ;
V_223 -> V_227 = T_33 -> V_224 ;
}
}
T_1
F_165 ( const char * V_228 , T_4 * V_211 )
{
struct V_229 V_230 ;
#ifdef F_7
struct V_188 V_189 = { 0 , V_231 } , * V_232 ;
int V_190 ;
T_28 V_191 , V_192 ;
T_34 V_233 ;
#else
struct V_82 * T_33 ;
#endif
if ( ! F_166 ( V_228 , & V_230 ) ) {
if ( ! V_97 . V_98 ||
! V_97 . V_99 ) {
return FALSE ;
}
#ifdef F_7
if ( ! ( V_97 . V_101 ) ||
V_102 < 1 ||
! V_103 ) {
return FALSE ;
}
V_233 . V_225 = ( int ) sizeof ( struct V_229 ) ;
V_233 . V_227 = 0 ;
V_233 . V_211 = V_211 ;
F_167 ( V_197 , V_228 , V_88 , F_164 , & V_233 ) ;
F_120 ( & V_191 ) ;
F_120 ( & V_192 ) ;
V_190 = F_121 ( V_197 , & V_191 , & V_192 ) ;
if ( V_190 > 0 ) {
V_232 = F_168 ( V_197 , & V_189 , & V_189 ) ;
if ( F_122 ( V_190 , & V_191 , & V_192 , NULL , V_232 ) == - 1 ) {
fprintf ( V_195 , L_61 , strerror ( V_181 ) ) ;
return FALSE ;
}
F_123 ( V_197 , & V_191 , & V_192 ) ;
}
F_169 ( V_197 ) ;
if ( V_233 . V_225 == V_233 . V_227 ) {
return TRUE ;
}
return FALSE ;
#else
T_33 = F_170 ( V_228 ) ;
if ( T_33 == NULL ) {
return FALSE ;
} else if ( T_33 -> V_224 <= ( int ) sizeof ( struct V_229 ) ) {
memcpy ( & V_230 , T_33 -> V_226 , T_33 -> V_224 ) ;
} else {
return FALSE ;
}
#endif
} else {
unsigned int V_140 , V_141 , V_142 , V_143 ;
if ( sscanf ( V_228 , L_70 , & V_140 , & V_141 , & V_142 , & V_143 ) != 4 )
return FALSE ;
}
* V_211 = V_230 . V_234 ;
return TRUE ;
}
T_1
F_171 ( const char * V_228 , struct V_10 * V_211 )
{
#ifdef F_7
struct V_188 V_189 = { 0 , V_231 } , * V_232 ;
int V_190 ;
T_28 V_191 , V_192 ;
T_34 V_233 ;
#elif F_113 ( V_235 )
struct V_82 * T_33 ;
#endif
if ( F_91 ( V_90 , V_228 , V_211 ) > 0 )
return TRUE ;
if ( ! V_97 . V_98 ||
! V_97 . V_99 ) {
return FALSE ;
}
#ifdef F_7
if ( ! ( V_97 . V_101 ) ||
V_102 < 1 ||
! V_103 ) {
return FALSE ;
}
V_233 . V_225 = ( int ) sizeof ( struct V_10 ) ;
V_233 . V_227 = 0 ;
V_233 . V_211 = V_211 ;
F_167 ( V_197 , V_228 , V_90 , F_164 , & V_233 ) ;
F_120 ( & V_191 ) ;
F_120 ( & V_192 ) ;
V_190 = F_121 ( V_197 , & V_191 , & V_192 ) ;
if ( V_190 > 0 ) {
V_232 = F_168 ( V_197 , & V_189 , & V_189 ) ;
if ( F_122 ( V_190 , & V_191 , & V_192 , NULL , V_232 ) == - 1 ) {
fprintf ( V_195 , L_61 , strerror ( V_181 ) ) ;
return FALSE ;
}
F_123 ( V_197 , & V_191 , & V_192 ) ;
}
F_169 ( V_197 ) ;
if ( V_233 . V_225 == V_233 . V_227 ) {
return TRUE ;
}
#elif F_113 ( V_235 )
T_33 = F_172 ( V_228 , V_90 ) ;
if ( T_33 != NULL && T_33 -> V_224 == sizeof( struct V_10 ) ) {
memcpy ( V_211 , T_33 -> V_226 , T_33 -> V_224 ) ;
return TRUE ;
}
#endif
return FALSE ;
}
const char * F_173 ( const char * V_228
#ifndef V_235
V_83
#endif
)
{
#ifdef V_235
struct V_82 * V_8 ;
return ( V_8 = F_172 ( V_228 , V_90 ) ) && V_8 -> V_236 == V_90 ? L_71 : L_72 ;
#else
return L_72 ;
#endif
}
T_35 *
F_174 ( void )
{
return V_124 ;
}
T_35 *
F_175 ( void )
{
return V_125 ;
}
T_35 *
F_176 ( void )
{
return V_128 ;
}
T_35 *
F_177 ( void )
{
return V_29 ;
}
T_35 *
F_178 ( void )
{
return V_149 ;
}
T_35 *
F_179 ( void )
{
return V_94 ;
}
T_35 *
F_180 ( void )
{
return V_104 ;
}
void
F_181 ( void )
{
F_29 () ;
F_69 () ;
F_86 () ;
}
void
F_182 ( void )
{
F_36 () ;
F_72 () ;
F_87 () ;
}
