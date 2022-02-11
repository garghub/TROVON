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
if ( memcmp ( V_6 , V_7 , sizeof ( struct V_8 ) ) == 0 ) {
return TRUE ;
}
return FALSE ;
}
static void
F_3 ( int type , T_1 V_9 )
{
T_4 * V_10 ;
V_10 = F_4 ( F_5 () , T_4 ) ;
V_10 -> V_11 = type ;
V_10 -> V_9 . V_12 = V_9 ;
F_6 ( V_13 , ( V_14 ) V_10 ) ;
}
static int
F_7 ( char * * V_15 , int * V_16 , T_5 * V_17 )
{
int V_2 ;
int V_18 ;
if ( V_17 == NULL || V_15 == NULL )
return - 1 ;
if ( * V_15 == NULL ) {
if ( * V_16 == 0 )
* V_16 = V_19 ;
* V_15 = ( char * ) F_8 ( F_5 () , * V_16 ) ;
}
F_9 ( * V_15 ) ;
F_9 ( * V_16 > 0 ) ;
if ( feof ( V_17 ) )
return - 1 ;
V_2 = 0 ;
while ( ( V_18 = getc ( V_17 ) ) != V_20 && V_18 != '\r' && V_18 != '\n' ) {
if ( V_2 + 1 >= * V_16 ) {
* V_15 = ( char * ) F_10 ( F_5 () , * V_15 , * V_16 += V_19 ) ;
}
( * V_15 ) [ V_2 ++ ] = V_18 ;
}
if ( V_2 == 0 && V_18 == V_20 )
return - 1 ;
( * V_15 ) [ V_2 ] = '\0' ;
return V_2 ;
}
static void
F_11 ( T_6 V_21 , const T_7 V_22 , const char * V_23 )
{
T_8 * V_24 ;
int * V_1 ;
V_1 = ( int * ) F_4 ( F_5 () , int ) ;
* V_1 = V_22 ;
V_24 = ( T_8 * ) F_12 ( V_25 , & V_22 ) ;
if ( V_24 == NULL ) {
V_24 = F_13 ( F_5 () , T_8 ) ;
F_14 ( V_25 , V_1 , V_24 ) ;
}
else {
F_15 ( F_5 () , V_1 ) ;
}
switch( V_21 ) {
case V_26 :
F_15 ( F_5 () , V_24 -> V_27 ) ;
V_24 -> V_27 = F_16 ( F_5 () , V_23 ) ;
break;
case V_28 :
F_15 ( F_5 () , V_24 -> V_29 ) ;
V_24 -> V_29 = F_16 ( F_5 () , V_23 ) ;
break;
case V_30 :
F_15 ( F_5 () , V_24 -> V_31 ) ;
V_24 -> V_31 = F_16 ( F_5 () , V_23 ) ;
break;
case V_32 :
F_15 ( F_5 () , V_24 -> V_33 ) ;
V_24 -> V_33 = F_16 ( F_5 () , V_23 ) ;
break;
default:
return;
}
V_34 = TRUE ;
}
static void
F_17 ( char * line )
{
T_9 * V_35 ;
T_9 * V_36 ;
T_9 * V_22 ;
T_6 V_21 ;
T_10 * V_37 = NULL ;
T_1 V_38 = V_39 ;
if ( ( V_35 = strchr ( line , '#' ) ) )
* V_35 = '\0' ;
if ( ( V_35 = strtok ( line , L_1 ) ) == NULL )
return;
V_36 = V_35 ;
if ( ( V_35 = strtok ( NULL , L_1 ) ) == NULL )
return;
V_22 = V_35 ;
if ( strtok ( V_35 , L_2 ) == NULL )
return;
if ( ( V_35 = strtok ( NULL , L_2 ) ) == NULL )
return;
if ( strcmp ( V_35 , L_3 ) == 0 ) {
V_38 = V_40 ;
V_21 = V_26 ;
}
else if ( strcmp ( V_35 , L_4 ) == 0 ) {
V_38 = V_39 ;
V_21 = V_28 ;
}
else if ( strcmp ( V_35 , L_5 ) == 0 ) {
V_38 = V_41 ;
V_21 = V_30 ;
}
else if ( strcmp ( V_35 , L_6 ) == 0 ) {
V_38 = V_42 ;
V_21 = V_32 ;
} else {
return;
}
if ( V_43 != F_18 ( & V_37 , V_22 , V_38 ) ) {
return;
}
V_44 = V_36 ;
V_45 = V_21 ;
F_19 ( V_37 , V_46 ) ;
F_20 ( V_37 ) ;
V_45 = V_47 ;
}
static void
V_46 ( const T_1 V_22 )
{
if ( V_22 ) {
F_11 ( V_45 , V_22 , V_44 ) ;
}
}
static void
F_21 ( const char * V_48 )
{
T_5 * V_49 ;
static int V_16 = 0 ;
static char * V_15 = NULL ;
V_49 = F_22 ( V_48 , L_7 ) ;
if ( V_49 == NULL )
return;
while ( F_7 ( & V_15 , & V_16 , V_49 ) >= 0 ) {
F_17 ( V_15 ) ;
}
fclose ( V_49 ) ;
}
static T_9 *
F_23 ( T_11 * V_50 , T_7 V_22 )
{
T_9 * V_51 = ( T_9 * ) F_8 ( V_50 , V_52 ) ;
F_24 ( V_22 , V_51 , V_52 ) ;
return V_51 ;
}
static const T_9 *
F_25 ( T_6 V_21 , T_7 V_22 , T_8 * * V_53 )
{
T_8 * V_24 ;
V_24 = ( T_8 * ) F_12 ( V_25 , & V_22 ) ;
if ( V_53 != NULL )
* V_53 = V_24 ;
if ( V_24 == NULL )
return NULL ;
switch ( V_21 ) {
case V_28 :
return V_24 -> V_29 ;
case V_26 :
return V_24 -> V_27 ;
case V_30 :
return V_24 -> V_31 ;
case V_32 :
return V_24 -> V_33 ;
default:
break;
}
return NULL ;
}
const T_9 *
F_26 ( T_6 V_21 , T_7 V_22 )
{
return F_25 ( V_21 , V_22 , NULL ) ;
}
const T_9 *
F_27 ( T_6 V_21 , T_7 V_22 )
{
T_8 * V_24 = NULL ;
const char * V_54 ;
T_7 * V_1 ;
V_54 = F_25 ( V_21 , V_22 , & V_24 ) ;
if ( V_54 != NULL )
return V_54 ;
if ( V_24 == NULL ) {
V_1 = ( T_7 * ) F_4 ( F_5 () , T_7 ) ;
* V_1 = V_22 ;
V_24 = F_13 ( F_5 () , T_8 ) ;
F_14 ( V_25 , V_1 , V_24 ) ;
}
if ( V_24 -> V_55 == NULL ) {
V_24 -> V_55 = F_28 ( F_5 () , L_8 , V_22 ) ;
}
return V_24 -> V_55 ;
}
static void
F_29 ( V_14 V_56 )
{
T_8 * V_57 = ( T_8 * ) V_56 ;
F_15 ( F_5 () , V_57 -> V_29 ) ;
F_15 ( F_5 () , V_57 -> V_27 ) ;
F_15 ( F_5 () , V_57 -> V_31 ) ;
F_15 ( F_5 () , V_57 -> V_33 ) ;
F_15 ( F_5 () , V_57 -> V_55 ) ;
F_15 ( F_5 () , V_57 ) ;
}
static void
F_30 ( void )
{
F_9 ( V_25 == NULL ) ;
V_25 = F_31 ( V_58 , V_59 , NULL , F_29 ) ;
if ( V_60 == NULL ) {
V_60 = F_32 ( V_61 ) ;
}
F_21 ( V_60 ) ;
if ( V_62 == NULL ) {
V_62 = F_33 ( V_61 , FALSE ) ;
}
F_21 ( V_62 ) ;
}
static void
F_34 ( void )
{
if ( V_25 ) {
F_35 ( V_25 ) ;
V_25 = NULL ;
}
}
static void
F_36 ( const T_7 V_9 , T_12 * volatile V_63 )
{
T_13 V_64 ;
if ( V_63 -> V_65 & V_66 )
return;
V_63 -> V_65 |= V_66 ;
V_64 = F_37 ( V_9 ) ;
if ( 0 != V_64 . V_67 ) {
T_1 V_68 ;
T_9 V_69 [ V_70 ] ;
T_9 * V_71 ;
T_14 V_5 ;
V_68 = V_9 & ( ~ ( T_1 ) V_64 . V_67 ) ;
F_38 ( ( V_72 * ) & V_68 , V_69 , V_70 ) ;
V_71 = V_69 ;
V_5 = V_64 . V_73 / 8 ;
while( * ( V_71 ) != '\0' && V_5 > 0 ) {
if ( * ( ++ V_71 ) == '.' ) {
-- V_5 ;
}
}
F_39 ( V_63 -> V_54 , V_52 , L_9 , V_64 . V_54 , V_71 ) ;
} else {
F_38 ( ( const V_72 * ) & V_9 , V_63 -> V_54 , V_52 ) ;
}
}
static void
F_40 ( T_15 * volatile V_63 )
{
if ( V_63 -> V_65 & V_66 )
return;
V_63 -> V_65 |= V_66 ;
F_41 ( V_63 -> V_54 , V_63 -> V_74 , V_52 ) ;
}
static void
F_42 (
void * V_75 ,
int V_76 ,
#if ( ( V_77 < 1 ) \
|| ( 1 == V_77 && V_78 < 5 ) )
struct V_79 * T_16
#else
int T_17 V_80 ,
struct V_79 * T_16
#endif
) {
T_4 * V_81 = ( T_4 * ) V_75 ;
char * * V_3 ;
if ( ! V_81 ) return;
V_82 -- ;
if ( V_76 == V_83 ) {
for ( V_3 = T_16 -> V_84 ; * V_3 != NULL ; V_3 ++ ) {
switch( V_81 -> V_11 ) {
case V_85 :
F_43 ( V_81 -> V_9 . V_12 , T_16 -> V_86 ) ;
break;
case V_87 :
F_44 ( & V_81 -> V_9 . V_74 , T_16 -> V_86 ) ;
break;
default:
break;
}
}
}
F_15 ( F_5 () , V_81 ) ;
}
static T_12 *
F_45 ( const T_7 V_9 )
{
T_12 * V_63 = F_4 ( F_5 () , T_12 ) ;
V_63 -> V_9 = V_9 ;
V_63 -> V_65 = 0 ;
V_63 -> V_54 [ 0 ] = '\0' ;
F_38 ( ( const V_72 * ) & V_9 , V_63 -> V_88 , sizeof( V_63 -> V_88 ) ) ;
return V_63 ;
}
static T_12 *
F_46 ( const T_7 V_9 )
{
T_12 * volatile V_63 ;
V_63 = ( T_12 * ) F_12 ( V_89 , F_47 ( V_9 ) ) ;
if ( V_63 == NULL ) {
V_63 = F_45 ( V_9 ) ;
F_14 ( V_89 , F_47 ( V_9 ) , V_63 ) ;
} else if ( ( V_63 -> V_65 & V_90 ) != V_66 ) {
return V_63 ;
}
F_36 ( V_9 , V_63 ) ;
if ( ! V_91 . V_92 )
return V_63 ;
if ( V_91 . V_93 ) {
V_63 -> V_65 |= V_94 ;
#ifdef F_48
if ( V_95 && V_96 > 0 ) {
F_3 ( V_85 , V_9 ) ;
}
#endif
}
return V_63 ;
}
static T_15 *
F_49 ( const struct V_8 * V_9 )
{
T_15 * V_63 = F_4 ( F_5 () , T_15 ) ;
memcpy ( V_63 -> V_9 , V_9 -> V_97 , sizeof V_63 -> V_9 ) ;
V_63 -> V_65 = 0 ;
V_63 -> V_54 [ 0 ] = '\0' ;
F_50 ( V_9 , V_63 -> V_74 , sizeof( V_63 -> V_74 ) ) ;
return V_63 ;
}
static T_15 *
F_51 ( const struct V_8 * V_9 )
{
T_15 * volatile V_63 ;
#ifdef F_48
T_4 * V_81 ;
#endif
V_63 = ( T_15 * ) F_12 ( V_98 , V_9 ) ;
if ( V_63 == NULL ) {
struct V_8 * V_99 ;
V_99 = F_4 ( F_5 () , struct V_8 ) ;
V_63 = F_49 ( V_9 ) ;
memcpy ( V_99 , V_9 , 16 ) ;
F_14 ( V_98 , V_99 , V_63 ) ;
} else if ( ( V_63 -> V_65 & V_90 ) != V_66 ) {
return V_63 ;
}
F_40 ( V_63 ) ;
if ( ! V_91 . V_92 )
return V_63 ;
if ( V_91 . V_93 ) {
V_63 -> V_65 |= V_94 ;
#ifdef F_48
if ( V_95 && V_96 > 0 ) {
V_81 = F_4 ( F_5 () , T_4 ) ;
V_81 -> V_11 = V_87 ;
memcpy ( & V_81 -> V_9 . V_74 , V_9 , sizeof( V_81 -> V_9 . V_74 ) ) ;
F_6 ( V_13 , ( V_14 ) V_81 ) ;
}
#endif
}
return V_63 ;
}
static T_3
F_52 ( const char * V_35 , T_18 * V_100 , unsigned int * V_67 ,
const T_3 V_101 )
{
int V_5 ;
unsigned long V_102 ;
char * V_3 ;
char V_103 = '\0' ;
for ( V_5 = 0 ; V_5 < 6 ; V_5 ++ ) {
if ( ! F_53 ( * V_35 ) )
return FALSE ;
V_102 = strtoul ( V_35 , & V_3 , 16 ) ;
if ( V_3 == V_35 )
return FALSE ;
if ( V_102 > 0xFF )
return FALSE ;
V_100 -> V_9 [ V_5 ] = ( V_72 ) V_102 ;
V_35 = V_3 ;
if ( * V_35 == '/' ) {
if ( ! V_101 ) {
return FALSE ;
}
V_35 ++ ;
if ( ! F_54 ( * V_35 ) )
return FALSE ;
V_102 = strtoul ( V_35 , & V_3 , 10 ) ;
if ( V_3 == V_35 )
return FALSE ;
V_35 = V_3 ;
if ( * V_35 != '\0' && ! F_55 ( * V_35 ) )
return FALSE ;
if ( V_102 == 0 || V_102 >= 48 )
return FALSE ;
* V_67 = ( int ) V_102 ;
for ( V_5 = 0 ; V_102 >= 8 ; V_5 ++ , V_102 -= 8 )
;
V_100 -> V_9 [ V_5 ] &= ( 0xFF << ( 8 - V_102 ) ) ;
V_5 ++ ;
for (; V_5 < 6 ; V_5 ++ )
V_100 -> V_9 [ V_5 ] = 0 ;
return TRUE ;
}
if ( * V_35 == '\0' ) {
if ( V_5 == 2 ) {
if ( ! V_101 ) {
return FALSE ;
}
* V_67 = 0 ;
return TRUE ;
}
if ( V_5 == 5 ) {
if ( V_101 )
* V_67 = 48 ;
return TRUE ;
}
return FALSE ;
} else {
if ( V_103 == '\0' ) {
if ( * V_35 != ':' && * V_35 != '-' && * V_35 != '.' )
return FALSE ;
V_103 = * V_35 ;
} else {
if ( * V_35 != V_103 )
return FALSE ;
}
}
V_35 ++ ;
}
return TRUE ;
}
static int
F_56 ( char * line , T_18 * V_100 , unsigned int * V_67 ,
const T_3 V_101 )
{
T_9 * V_35 ;
if ( ( V_35 = strchr ( line , '#' ) ) )
* V_35 = '\0' ;
if ( ( V_35 = strtok ( line , L_1 ) ) == NULL )
return - 1 ;
if ( ! F_52 ( V_35 , V_100 , V_67 , V_101 ) )
return - 1 ;
if ( ( V_35 = strtok ( NULL , L_1 ) ) == NULL )
return - 1 ;
F_41 ( V_100 -> V_54 , V_35 , V_52 ) ;
return 0 ;
}
static void
F_57 ( char * V_48 )
{
if ( V_104 )
rewind ( V_104 ) ;
else
V_104 = F_22 ( V_48 , L_7 ) ;
}
static void
F_58 ( void )
{
if ( V_104 ) {
fclose ( V_104 ) ;
V_104 = NULL ;
}
}
static T_18 *
F_59 ( unsigned int * V_67 , const T_3 V_101 )
{
static T_18 V_100 ;
static int V_16 = 0 ;
static char * V_15 = NULL ;
if ( V_104 == NULL )
return NULL ;
while ( F_7 ( & V_15 , & V_16 , V_104 ) >= 0 ) {
if ( F_56 ( V_15 , & V_100 , V_67 , V_101 ) == 0 ) {
return & V_100 ;
}
}
return NULL ;
}
static T_18 *
F_60 ( const V_72 * V_9 )
{
T_18 * V_100 ;
F_57 ( V_105 ) ;
while ( ( ( V_100 = F_59 ( NULL , FALSE ) ) != NULL ) && memcmp ( V_9 , V_100 -> V_9 , 6 ) != 0 )
;
if ( V_100 == NULL ) {
F_58 () ;
F_57 ( V_106 ) ;
while ( ( ( V_100 = F_59 ( NULL , FALSE ) ) != NULL ) && memcmp ( V_9 , V_100 -> V_9 , 6 ) != 0 )
;
F_58 () ;
}
return V_100 ;
}
static T_19 * F_61 ( const V_72 * V_9 , char * V_54 )
{
int * V_107 ;
T_19 * V_108 ;
char * V_109 ;
V_107 = ( int * ) F_4 ( F_5 () , int ) ;
* V_107 = ( int ) ( ( V_9 [ 0 ] << 16 ) + ( V_9 [ 1 ] << 8 ) + V_9 [ 2 ] ) ;
V_108 = F_4 ( F_5 () , T_19 ) ;
memcpy ( V_108 -> V_9 , V_9 , 3 ) ;
V_108 -> V_76 = ( V_54 != NULL ) ? V_110 : V_111 ;
if ( V_54 != NULL ) {
F_41 ( V_108 -> V_112 , V_54 , V_52 ) ;
V_108 -> V_76 = V_110 ;
}
else {
V_108 -> V_76 = V_111 ;
V_108 -> V_112 [ 0 ] = '\0' ;
}
V_109 = F_62 ( V_108 -> V_113 , V_9 , sizeof( V_108 -> V_9 ) , ':' ) ;
* V_109 = '\0' ;
F_14 ( V_114 , V_107 , V_108 ) ;
return V_108 ;
}
static void
F_63 ( const V_72 * V_9 , unsigned int V_67 , T_9 * V_54 )
{
V_72 * V_115 ;
if ( V_67 >= 48 ) {
F_64 ( V_9 , V_54 ) ;
return;
}
if ( V_67 == 0 ) {
F_61 ( V_9 , V_54 ) ;
return;
}
V_115 = ( V_72 * ) F_8 ( F_5 () , 6 ) ;
memcpy ( V_115 , V_9 , 6 ) ;
F_14 ( V_116 , V_115 , F_16 ( F_5 () , V_54 ) ) ;
}
static T_19 *
F_65 ( const V_72 * V_9 )
{
T_20 V_107 = 0 ;
V_72 V_117 ;
T_19 * V_108 ;
V_107 = V_9 [ 0 ] ;
V_107 = V_107 << 8 ;
V_117 = V_9 [ 1 ] ;
V_107 = V_107 | V_117 ;
V_107 = V_107 << 8 ;
V_117 = V_9 [ 2 ] ;
V_107 = V_107 | V_117 ;
V_108 = ( T_19 * ) F_12 ( V_114 , & V_107 ) ;
if ( V_108 != NULL ) {
return V_108 ;
}
if ( ( V_107 & 0x00010000 ) != 0 ) {
V_107 &= 0x00FEFFFF ;
V_108 = ( T_19 * ) F_12 ( V_114 , & V_107 ) ;
if ( V_108 != NULL ) {
return V_108 ;
}
}
return F_61 ( V_9 , NULL ) ;
}
static T_9 *
F_66 ( const V_72 * V_9 , const unsigned int V_67 )
{
V_72 V_118 [ 6 ] ;
T_7 V_102 ;
T_21 V_5 ;
T_9 * V_54 ;
if ( V_116 == NULL ) {
return NULL ;
}
for ( V_5 = 0 , V_102 = V_67 ; V_102 >= 8 ; V_5 ++ , V_102 -= 8 )
V_118 [ V_5 ] = V_9 [ V_5 ] ;
V_118 [ V_5 ] = V_9 [ V_5 ] & ( 0xFF << ( 8 - V_102 ) ) ;
V_5 ++ ;
for (; V_5 < 6 ; V_5 ++ )
V_118 [ V_5 ] = 0 ;
V_54 = ( T_9 * ) F_12 ( V_116 , V_118 ) ;
return V_54 ;
}
T_7 F_67 ( T_22 * V_119 )
{
return V_119 -> V_76 ;
}
char * F_68 ( T_22 * V_119 )
{
return V_119 -> V_113 ;
}
char * F_69 ( T_22 * V_119 )
{
return V_119 -> V_112 ;
}
static T_7
F_70 ( T_2 V_1 )
{
return F_71 ( ( const V_72 * ) V_1 , 6 ) ;
}
static T_3
F_72 ( T_2 V_120 , T_2 V_121 )
{
return ( memcmp ( V_120 , V_121 , 6 ) == 0 ) ;
}
static void
F_73 ( void )
{
T_18 * V_100 ;
char * V_122 ;
T_7 V_67 = 0 ;
V_116 = F_74 ( F_70 , F_72 ) ;
V_114 = F_74 ( V_58 , V_59 ) ;
V_123 = F_74 ( F_70 , F_72 ) ;
if ( V_106 == NULL ) {
V_106 = F_28 ( F_5 () , L_10 V_124 L_10 ,
F_75 () , V_125 ) ;
}
if ( V_105 == NULL )
V_105 = F_33 ( V_125 , FALSE ) ;
V_122 = F_32 ( V_126 ) ;
F_57 ( V_122 ) ;
while ( ( V_100 = F_59 ( & V_67 , TRUE ) ) ) {
F_63 ( V_100 -> V_9 , V_67 , V_100 -> V_54 ) ;
}
F_58 () ;
F_20 ( V_122 ) ;
}
static void
F_76 ( void )
{
if ( V_114 ) {
F_35 ( V_114 ) ;
V_114 = NULL ;
}
if ( V_116 ) {
F_35 ( V_116 ) ;
V_116 = NULL ;
}
if ( V_123 ) {
F_35 ( V_123 ) ;
V_123 = NULL ;
}
}
static T_22 *
F_77 ( T_22 * V_63 ) {
T_18 * V_100 ;
T_19 * V_108 ;
const V_72 * V_9 = V_63 -> V_9 ;
if ( ( V_100 = F_60 ( V_9 ) ) != NULL ) {
F_41 ( V_63 -> V_112 , V_100 -> V_54 , V_52 ) ;
V_63 -> V_76 = V_110 ;
return V_63 ;
} else {
T_7 V_67 ;
T_9 * V_54 ;
T_23 V_127 ;
V_67 = 7 ;
for (; ; ) {
if ( ( V_54 = F_66 ( V_9 , V_67 + 40 ) ) != NULL ) {
F_39 ( V_63 -> V_112 , V_52 , L_11 ,
V_54 , V_9 [ 5 ] & ( 0xFF >> V_67 ) ) ;
V_63 -> V_76 = V_128 ;
return V_63 ;
}
if ( V_67 == 0 )
break;
V_67 -- ;
}
V_67 = 7 ;
for (; ; ) {
if ( ( V_54 = F_66 ( V_9 , V_67 + 32 ) ) != NULL ) {
F_39 ( V_63 -> V_112 , V_52 , L_12 ,
V_54 , V_9 [ 4 ] & ( 0xFF >> V_67 ) , V_9 [ 5 ] ) ;
V_63 -> V_76 = V_128 ;
return V_63 ;
}
if ( V_67 == 0 )
break;
V_67 -- ;
}
V_67 = 7 ;
for (; ; ) {
if ( ( V_54 = F_66 ( V_9 , V_67 + 24 ) ) != NULL ) {
F_39 ( V_63 -> V_112 , V_52 , L_13 ,
V_54 , V_9 [ 3 ] & ( 0xFF >> V_67 ) , V_9 [ 4 ] , V_9 [ 5 ] ) ;
V_63 -> V_76 = V_128 ;
return V_63 ;
}
if ( V_67 == 0 )
break;
V_67 -- ;
}
V_108 = F_65 ( V_9 ) ;
if ( ( V_108 != NULL ) && ( V_108 -> V_76 != V_111 ) ) {
F_39 ( V_63 -> V_112 , V_52 , L_13 ,
V_108 -> V_112 , V_9 [ 3 ] , V_9 [ 4 ] , V_9 [ 5 ] ) ;
V_63 -> V_76 = V_128 ;
return V_63 ;
}
V_67 = 7 ;
for (; ; ) {
if ( ( V_54 = F_66 ( V_9 , V_67 + 16 ) ) != NULL ) {
F_39 ( V_63 -> V_112 , V_52 , L_14 ,
V_54 , V_9 [ 2 ] & ( 0xFF >> V_67 ) , V_9 [ 3 ] , V_9 [ 4 ] ,
V_9 [ 5 ] ) ;
V_63 -> V_76 = V_128 ;
return V_63 ;
}
if ( V_67 == 0 )
break;
V_67 -- ;
}
V_67 = 7 ;
for (; ; ) {
if ( ( V_54 = F_66 ( V_9 , V_67 + 8 ) ) != NULL ) {
F_39 ( V_63 -> V_112 , V_52 , L_15 ,
V_54 , V_9 [ 1 ] & ( 0xFF >> V_67 ) , V_9 [ 2 ] , V_9 [ 3 ] ,
V_9 [ 4 ] , V_9 [ 5 ] ) ;
V_63 -> V_76 = V_128 ;
return V_63 ;
}
if ( V_67 == 0 )
break;
V_67 -- ;
}
for ( V_67 = 7 ; V_67 > 0 ; V_67 -- ) {
if ( ( V_54 = F_66 ( V_9 , V_67 ) ) != NULL ) {
F_39 ( V_63 -> V_112 , V_52 , L_16 ,
V_54 , V_9 [ 0 ] & ( 0xFF >> V_67 ) , V_9 [ 1 ] , V_9 [ 2 ] ,
V_9 [ 3 ] , V_9 [ 4 ] , V_9 [ 5 ] ) ;
V_63 -> V_76 = V_128 ;
return V_63 ;
}
}
F_78 ( & V_127 , V_129 , 6 , V_9 ) ;
F_79 ( & V_127 , V_63 -> V_112 , V_52 ) ;
V_63 -> V_76 = V_128 ;
return V_63 ;
}
F_80 () ;
}
static T_22 *
F_81 ( const V_72 * V_9 , const T_3 V_130 )
{
T_22 * V_63 ;
char * V_109 ;
V_63 = F_4 ( F_5 () , T_22 ) ;
memcpy ( V_63 -> V_9 , V_9 , sizeof( V_63 -> V_9 ) ) ;
V_63 -> V_76 = V_111 ;
V_109 = F_62 ( V_63 -> V_113 , V_9 , sizeof( V_63 -> V_9 ) , ':' ) ;
* V_109 = '\0' ;
V_63 -> V_112 [ 0 ] = '\0' ;
if ( V_130 )
F_77 ( V_63 ) ;
F_14 ( V_123 , V_63 -> V_9 , V_63 ) ;
return V_63 ;
}
static T_22 *
F_64 ( const V_72 * V_9 , const T_9 * V_54 )
{
T_22 * V_63 ;
V_63 = ( T_22 * ) F_12 ( V_123 , V_9 ) ;
if ( V_63 == NULL ) {
V_63 = F_81 ( V_9 , FALSE ) ;
}
if ( strcmp ( V_63 -> V_112 , V_54 ) != 0 ) {
F_41 ( V_63 -> V_112 , V_54 , V_52 ) ;
V_63 -> V_76 = V_110 ;
V_34 = TRUE ;
}
return V_63 ;
}
static T_22 *
F_82 ( const V_72 * V_9 , const T_3 V_130 )
{
T_22 * V_63 ;
V_63 = ( T_22 * ) F_12 ( V_123 , V_9 ) ;
if ( V_63 == NULL ) {
V_63 = F_81 ( V_9 , V_130 ) ;
} else {
if ( V_130 && ( V_63 -> V_76 == V_111 ) ) {
F_77 ( V_63 ) ;
}
}
return V_63 ;
}
static V_72 *
F_83 ( const T_9 * V_54 V_80 )
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
F_84 ( char * line , T_24 * V_131 )
{
T_9 * V_35 ;
T_1 V_120 , V_132 , V_133 , V_134 , V_135 ;
T_3 V_136 = FALSE ;
if ( ( V_35 = strchr ( line , '#' ) ) )
* V_35 = '\0' ;
if ( ( V_35 = strtok ( line , L_17 ) ) == NULL )
return - 1 ;
if ( sscanf ( V_35 , L_18 , & V_132 , & V_133 , & V_134 , & V_135 ) != 4 ) {
if ( sscanf ( V_35 , L_19 , & V_132 , & V_133 , & V_134 , & V_135 ) != 4 ) {
if ( sscanf ( V_35 , L_20 , & V_132 , & V_133 , & V_134 , & V_135 ) != 4 ) {
if ( sscanf ( V_35 , L_21 , & V_120 ) == 1 ) {
V_136 = TRUE ;
}
else {
return - 1 ;
}
}
}
}
if ( ( V_35 = strtok ( NULL , L_17 ) ) == NULL )
return - 1 ;
if ( V_136 ) {
V_131 -> V_9 = V_120 ;
}
else {
V_131 -> V_9 = ( V_132 << 24 ) | ( V_133 << 16 ) | ( V_134 << 8 ) | V_135 ;
}
F_41 ( V_131 -> V_54 , V_35 , V_52 ) ;
return 0 ;
}
static void
F_85 ( char * V_48 )
{
if ( V_137 )
rewind ( V_137 ) ;
else
V_137 = F_22 ( V_48 , L_7 ) ;
}
static void
F_86 ( void )
{
if ( V_137 ) {
fclose ( V_137 ) ;
V_137 = NULL ;
}
}
static T_24 *
F_87 ( void )
{
static T_24 V_131 ;
static int V_16 = 0 ;
static char * V_15 = NULL ;
if ( V_137 == NULL )
return NULL ;
while ( F_7 ( & V_15 , & V_16 , V_137 ) >= 0 ) {
if ( F_84 ( V_15 , & V_131 ) == 0 ) {
return & V_131 ;
}
}
return NULL ;
}
static T_24 *
F_88 ( T_1 V_9 )
{
T_24 * V_131 ;
F_85 ( V_138 ) ;
while ( ( ( V_131 = F_87 () ) != NULL ) && ( V_9 != V_131 -> V_9 ) ) ;
if ( V_131 == NULL ) {
F_86 () ;
F_85 ( V_139 ) ;
while ( ( ( V_131 = F_87 () ) != NULL ) && ( V_9 != V_131 -> V_9 ) )
;
F_86 () ;
}
return V_131 ;
}
static void
F_89 ( void )
{
if ( V_138 == NULL ) {
V_138 = F_28 ( F_5 () , L_10 V_124 L_10 ,
F_75 () , V_140 ) ;
}
if ( V_139 == NULL )
V_139 = F_33 ( V_140 , FALSE ) ;
}
static void
F_90 ( void )
{
if ( V_141 ) {
F_35 ( V_141 ) ;
V_141 = NULL ;
}
}
static T_9 *
F_91 ( T_11 * V_50 , const T_7 V_9 )
{
T_25 * V_63 ;
T_24 * V_131 ;
V_63 = ( T_25 * ) F_12 ( V_141 , & V_9 ) ;
if ( V_63 == NULL ) {
int * V_1 ;
V_1 = ( int * ) F_4 ( F_5 () , int ) ;
* V_1 = V_9 ;
V_63 = F_4 ( F_5 () , T_25 ) ;
F_14 ( V_141 , V_1 , V_63 ) ;
} else {
return F_16 ( V_50 , V_63 -> V_54 ) ;
}
V_63 -> V_9 = V_9 ;
if ( ( V_131 = F_88 ( V_9 ) ) == NULL ) {
F_39 ( V_63 -> V_54 , V_52 , L_22 , V_9 ) ;
} else {
F_41 ( V_63 -> V_54 , V_131 -> V_54 , V_52 ) ;
}
return F_16 ( V_50 , V_63 -> V_54 ) ;
}
static T_7
F_92 ( const T_9 * V_54 V_80 , T_3 * V_142 )
{
* V_142 = FALSE ;
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
static int
F_93 ( char * line , T_26 * V_143 )
{
T_9 * V_35 ;
T_27 V_144 ;
if ( ( V_35 = strchr ( line , '#' ) ) )
* V_35 = '\0' ;
if ( ( V_35 = strtok ( line , L_17 ) ) == NULL )
return - 1 ;
if ( sscanf ( V_35 , L_23 V_145 , & V_144 ) == 1 ) {
V_143 -> V_144 = V_144 ;
}
else {
return - 1 ;
}
if ( ( V_35 = strtok ( NULL , L_24 ) ) == NULL )
return - 1 ;
F_41 ( V_143 -> V_54 , V_35 , V_146 ) ;
return 0 ;
}
static void
F_94 ( char * V_48 )
{
if ( V_147 )
rewind ( V_147 ) ;
else
V_147 = F_22 ( V_48 , L_7 ) ;
}
static void
F_95 ( void )
{
if ( V_147 ) {
fclose ( V_147 ) ;
V_147 = NULL ;
}
}
static T_26 *
F_96 ( void )
{
static T_26 V_143 ;
static int V_16 = 0 ;
static char * V_15 = NULL ;
if ( V_147 == NULL )
return NULL ;
while ( F_7 ( & V_15 , & V_16 , V_147 ) >= 0 ) {
if ( F_93 ( V_15 , & V_143 ) == 0 ) {
return & V_143 ;
}
}
return NULL ;
}
static T_26 *
F_97 ( T_27 V_144 )
{
T_26 * V_143 ;
F_94 ( V_148 ) ;
while ( ( ( V_143 = F_96 () ) != NULL ) && ( V_144 != V_143 -> V_144 ) ) ;
if ( V_143 == NULL ) {
F_95 () ;
}
return V_143 ;
}
static void
F_98 ( void )
{
F_9 ( V_149 == NULL ) ;
V_149 = F_31 ( V_58 , V_59 , F_20 , F_20 ) ;
if ( V_148 == NULL )
V_148 = F_33 ( V_150 , FALSE ) ;
}
static void
F_99 ( void )
{
if ( V_149 ) {
F_35 ( V_149 ) ;
V_149 = NULL ;
}
}
static const T_9 *
F_100 ( const T_7 V_144 )
{
T_28 * V_63 ;
T_26 * V_143 ;
V_63 = ( T_28 * ) F_12 ( V_149 , & V_144 ) ;
if ( V_63 == NULL ) {
int * V_1 ;
V_1 = ( int * ) F_4 ( F_5 () , int ) ;
* V_1 = V_144 ;
V_63 = F_4 ( F_5 () , T_28 ) ;
F_14 ( V_149 , V_1 , V_63 ) ;
} else {
return V_63 -> V_54 ;
}
V_63 -> V_144 = V_144 ;
if ( ( V_143 = F_97 ( V_144 ) ) == NULL ) {
F_39 ( V_63 -> V_54 , V_146 , L_25 , V_144 ) ;
} else {
F_41 ( V_63 -> V_54 , V_143 -> V_54 , V_146 ) ;
}
return V_63 -> V_54 ;
}
static T_3
F_101 ( const char * V_151 , T_3 V_152 )
{
T_5 * V_153 ;
char * line = NULL ;
int V_16 = 0 ;
T_9 * V_35 ;
union {
T_1 V_154 ;
struct V_8 V_155 ;
} V_68 ;
T_3 V_156 , V_157 = FALSE ;
if ( ( V_153 = F_22 ( V_151 , L_7 ) ) == NULL )
return FALSE ;
while ( F_7 ( & line , & V_16 , V_153 ) >= 0 ) {
if ( ( V_35 = strchr ( line , '#' ) ) )
* V_35 = '\0' ;
if ( ( V_35 = strtok ( line , L_1 ) ) == NULL )
continue;
if ( F_102 ( V_35 , & V_68 . V_155 ) ) {
V_156 = TRUE ;
} else if ( F_103 ( V_35 , & V_68 . V_154 ) ) {
V_156 = FALSE ;
} else {
continue;
}
if ( ( V_35 = strtok ( NULL , L_1 ) ) == NULL )
continue;
V_157 = TRUE ;
if ( V_152 ) {
if ( V_156 ) {
F_44 ( & V_68 . V_155 , V_35 ) ;
} else {
F_43 ( V_68 . V_154 , V_35 ) ;
}
}
}
F_15 ( F_5 () , line ) ;
fclose ( V_153 ) ;
return V_157 ? TRUE : FALSE ;
}
T_3
F_104 ( const char * V_158 )
{
T_3 V_159 = FALSE ;
T_7 V_5 ;
if ( ! V_158 )
return FALSE ;
if ( ! V_160 )
V_160 = F_105 () ;
for ( V_5 = 0 ; V_5 < V_160 -> V_2 ; V_5 ++ ) {
if ( strcmp ( V_158 , ( const char * ) F_106 ( V_160 , V_5 ) ) == 0 )
V_159 = TRUE ;
}
if ( ! V_159 ) {
F_107 ( V_160 , F_16 ( F_5 () , V_158 ) ) ;
return F_101 ( V_158 , FALSE ) ;
}
return TRUE ;
}
T_3
F_108 ( const char * V_9 , const char * V_54 )
{
union {
T_1 V_154 ;
struct V_8 V_155 ;
} V_68 ;
T_3 V_156 ;
T_29 * V_161 ;
T_30 * V_162 ;
if ( F_102 ( V_9 , & V_68 . V_155 ) ) {
V_156 = TRUE ;
} else if ( F_103 ( V_9 , & V_68 . V_154 ) ) {
V_156 = FALSE ;
} else {
return FALSE ;
}
if ( V_156 ) {
V_162 = F_4 ( F_5 () , T_30 ) ;
memcpy ( & ( V_162 -> V_155 ) , & V_68 . V_155 , 16 ) ;
F_41 ( V_162 -> V_54 , V_54 , V_52 ) ;
F_109 ( V_163 , V_162 ) ;
} else {
V_161 = F_4 ( F_5 () , T_29 ) ;
V_161 -> V_68 = V_68 . V_154 ;
F_41 ( V_161 -> V_54 , V_54 , V_52 ) ;
F_109 ( V_164 , V_161 ) ;
}
return TRUE ;
}
static void
F_110 ( V_14 V_1 V_80 , V_14 V_165 , V_14 V_166 )
{
T_31 * V_167 = ( T_31 * ) V_166 ;
T_12 * V_168 = ( T_12 * ) V_165 ;
if ( ( V_168 -> V_65 & V_169 ) == V_170 ) {
V_167 -> V_171 = F_111 ( V_167 -> V_171 , V_168 ) ;
}
}
static void
F_112 ( V_14 V_1 V_80 , V_14 V_165 , V_14 V_166 )
{
T_31 * V_167 = ( T_31 * ) V_166 ;
T_15 * V_172 = ( T_15 * ) V_165 ;
if ( ( V_172 -> V_65 & V_169 ) == V_170 ) {
V_167 -> V_173 = F_111 ( V_167 -> V_173 , V_172 ) ;
}
}
T_31 *
F_113 ( void ) {
if ( V_89 ) {
F_114 ( V_89 , F_110 , & V_174 ) ;
}
if ( V_98 ) {
F_114 ( V_98 , F_112 , & V_174 ) ;
}
return & V_174 ;
}
static T_3
F_115 ( const char * V_175 )
{
T_5 * V_153 ;
char * line = NULL ;
int V_16 = 0 ;
T_9 * V_35 , * V_176 ;
T_1 V_68 ;
int V_73 ;
if ( ( V_153 = F_22 ( V_175 , L_7 ) ) == NULL )
return FALSE ;
while ( F_7 ( & line , & V_16 , V_153 ) >= 0 ) {
if ( ( V_35 = strchr ( line , '#' ) ) )
* V_35 = '\0' ;
if ( ( V_35 = strtok ( line , L_1 ) ) == NULL )
continue;
V_176 = strchr ( V_35 , '/' ) ;
if ( NULL == V_176 ) {
continue;
}
* V_176 = '\0' ;
++ V_176 ;
if ( ! F_116 ( V_35 , & V_68 ) ) {
continue;
}
V_73 = atoi ( V_176 ) ;
if ( 0 >= V_73 || V_73 > 32 ) {
continue;
}
if ( ( V_35 = strtok ( NULL , L_1 ) ) == NULL )
continue;
F_117 ( V_68 , ( T_1 ) V_73 , V_35 ) ;
}
F_15 ( F_5 () , line ) ;
fclose ( V_153 ) ;
return TRUE ;
}
static T_13
F_37 ( const T_1 V_9 )
{
T_13 V_64 ;
T_1 V_5 ;
V_5 = V_177 ;
while( V_178 && V_5 > 0 ) {
T_1 V_118 ;
T_32 * V_179 ;
-- V_5 ;
F_9 ( V_5 < V_177 ) ;
V_179 = & V_180 [ V_5 ] ;
if ( NULL != V_179 -> V_181 ) {
T_33 * V_63 ;
T_1 V_182 ;
V_118 = V_9 & V_179 -> V_67 ;
V_182 = F_118 ( V_118 ) ;
V_63 = V_179 -> V_181 [ V_182 ] ;
while( V_63 != NULL && V_63 -> V_9 != V_118 ) {
V_63 = V_63 -> V_183 ;
}
if ( NULL != V_63 ) {
V_64 . V_67 = V_179 -> V_67 ;
V_64 . V_73 = V_5 + 1 ;
V_64 . V_54 = V_63 -> V_54 ;
return V_64 ;
}
}
}
V_64 . V_67 = 0 ;
V_64 . V_73 = 0 ;
V_64 . V_54 = NULL ;
return V_64 ;
}
static void
F_117 ( T_1 V_184 , const T_1 V_73 , const T_9 * V_54 )
{
T_32 * V_185 ;
T_33 * V_63 ;
T_14 V_182 ;
F_9 ( V_73 > 0 && V_73 <= 32 ) ;
V_185 = & V_180 [ V_73 - 1 ] ;
V_184 &= V_185 -> V_67 ;
V_182 = F_118 ( V_184 ) ;
if ( NULL == V_185 -> V_181 ) {
V_185 -> V_181 = ( T_33 * * ) F_119 ( F_5 () , sizeof( T_33 * ) * V_186 ) ;
}
if ( NULL != ( V_63 = V_185 -> V_181 [ V_182 ] ) ) {
T_33 * V_187 ;
while ( V_63 -> V_183 ) {
if ( V_63 -> V_9 == V_184 ) {
return;
} else {
V_63 = V_63 -> V_183 ;
}
}
V_187 = F_4 ( F_5 () , T_33 ) ;
V_63 -> V_183 = V_187 ;
V_63 = V_187 ;
} else {
V_63 = V_185 -> V_181 [ V_182 ] = F_4 ( F_5 () , T_33 ) ;
}
V_63 -> V_183 = NULL ;
V_63 -> V_9 = V_184 ;
V_63 -> V_65 &= ~ V_66 ;
F_41 ( V_63 -> V_54 , V_54 , V_52 ) ;
V_178 = TRUE ;
}
static void
F_120 ( void )
{
T_9 * V_175 ;
T_1 V_5 ;
for( V_5 = 0 ; V_5 < V_177 ; ++ V_5 ) {
T_1 V_188 = V_5 + 1 ;
V_180 [ V_5 ] . V_181 = NULL ;
V_180 [ V_5 ] . V_73 = V_188 ;
V_180 [ V_5 ] . V_67 = F_121 ( F_122 ( V_188 ) ) ;
}
V_175 = F_33 ( V_189 , FALSE ) ;
if ( ! F_115 ( V_175 ) && V_190 != V_191 ) {
F_123 ( V_175 , V_190 , FALSE ) ;
}
F_20 ( V_175 ) ;
V_175 = F_32 ( V_189 ) ;
if ( ! F_115 ( V_175 ) && V_190 != V_191 ) {
F_123 ( V_175 , V_190 , FALSE ) ;
}
F_20 ( V_175 ) ;
}
void
F_124 ( T_34 * V_192 )
{
F_125 ( V_192 , L_26 ,
L_27 ,
L_28 ,
& V_91 . V_193 ) ;
F_125 ( V_192 , L_29 ,
L_30 ,
L_31 ,
& V_91 . V_194 ) ;
F_125 ( V_192 , L_32 ,
L_33 ,
L_34
L_35
L_36
L_37 ,
& V_91 . V_92 ) ;
F_125 ( V_192 , L_38 ,
L_39 ,
L_40 ,
& V_91 . V_195 ) ;
#ifdef F_48
F_125 ( V_192 , L_41 ,
L_42 ,
L_43
L_44
L_45
L_46 ,
& V_91 . V_93 ) ;
F_126 ( V_192 , L_47 ) ;
F_127 ( V_192 , L_48 ,
L_49 ,
L_50
L_51
L_52
L_53 ,
10 ,
& V_96 ) ;
#else
F_128 ( V_192 , L_41 ,
L_54 ,
L_55
L_56 ) ;
#endif
F_125 ( V_192 , L_57 ,
L_58 ,
L_59
L_60 ,
& V_91 . V_196 ) ;
F_125 ( V_192 , L_61 ,
L_62 ,
L_63
L_64
L_65
L_66
L_67 ,
& V_91 . V_197 ) ;
}
void
F_129 ( void ) {
V_91 . V_193 = FALSE ;
V_91 . V_92 = FALSE ;
V_91 . V_194 = FALSE ;
V_91 . V_195 = FALSE ;
V_91 . V_93 = FALSE ;
V_91 . V_197 = FALSE ;
}
T_3
F_130 ( void ) {
T_4 * V_81 ;
struct V_198 V_199 = { 0 , 0 } ;
int V_200 ;
T_35 V_201 , V_202 ;
T_3 V_203 = V_34 ;
T_36 * V_204 ;
V_34 = FALSE ;
if ( ! V_95 )
return V_203 ;
V_204 = F_131 ( V_13 ) ;
while ( V_204 != NULL && V_82 <= V_96 ) {
V_81 = ( T_4 * ) F_132 ( V_204 ) ;
F_133 ( V_13 , V_204 ) ;
if ( V_81 -> V_11 == V_85 ) {
F_134 ( V_205 , & V_81 -> V_9 . V_12 , sizeof( T_1 ) , V_85 ,
F_42 , V_81 ) ;
V_82 ++ ;
} else if ( V_81 -> V_11 == V_87 ) {
F_134 ( V_205 , & V_81 -> V_9 . V_74 , sizeof( struct V_8 ) ,
V_87 , F_42 , V_81 ) ;
V_82 ++ ;
}
V_204 = F_131 ( V_13 ) ;
}
F_135 ( & V_201 ) ;
F_135 ( & V_202 ) ;
V_200 = F_136 ( V_205 , & V_201 , & V_202 ) ;
if ( V_200 > 0 ) {
if ( F_137 ( V_200 , & V_201 , & V_202 , NULL , & V_199 ) == - 1 ) {
fprintf ( V_206 , L_68 , F_138 ( V_190 ) ) ;
return V_203 ;
}
F_139 ( V_205 , & V_201 , & V_202 ) ;
}
return V_203 ;
}
static void
F_140 ( void ) {
V_13 = NULL ;
if ( V_95 ) {
F_141 ( V_205 ) ;
F_141 ( V_207 ) ;
}
#ifdef F_142
F_143 () ;
#endif
V_95 = FALSE ;
}
T_3
F_130 ( void ) {
T_3 V_203 = V_34 ;
V_34 = FALSE ;
return V_203 ;
}
static void
F_140 ( void ) {
}
const T_9 *
F_144 ( const T_7 V_9 )
{
T_12 * V_63 = F_46 ( V_9 ) ;
if ( ! V_91 . V_92 )
return V_63 -> V_88 ;
V_63 -> V_65 |= V_170 ;
return V_63 -> V_54 ;
}
const T_9 *
F_145 ( const struct V_8 * V_9 )
{
T_15 * V_63 = F_51 ( V_9 ) ;
if ( ! V_91 . V_92 )
return V_63 -> V_74 ;
V_63 -> V_65 |= V_170 ;
return V_63 -> V_54 ;
}
void
F_43 ( const T_7 V_9 , const T_9 * V_54 )
{
T_12 * V_63 ;
if ( ! V_54 || V_54 [ 0 ] == '\0' )
return;
V_63 = ( T_12 * ) F_12 ( V_89 , F_47 ( V_9 ) ) ;
if ( ! V_63 ) {
V_63 = F_45 ( V_9 ) ;
F_14 ( V_89 , F_47 ( V_9 ) , V_63 ) ;
}
if ( F_146 ( V_63 -> V_54 , V_54 ) ) {
F_41 ( V_63 -> V_54 , V_54 , V_52 ) ;
V_34 = TRUE ;
}
V_63 -> V_65 |= V_94 | V_208 ;
}
void
F_44 ( const struct V_8 * V_209 , const T_9 * V_54 )
{
T_15 * V_63 ;
if ( ! V_54 || V_54 [ 0 ] == '\0' )
return;
V_63 = ( T_15 * ) F_12 ( V_98 , V_209 ) ;
if ( ! V_63 ) {
struct V_8 * V_99 ;
V_99 = F_4 ( F_5 () , struct V_8 ) ;
V_63 = F_49 ( V_209 ) ;
memcpy ( V_99 , V_209 , 16 ) ;
F_14 ( V_98 , V_99 , V_63 ) ;
}
if ( F_146 ( V_63 -> V_54 , V_54 ) ) {
F_41 ( V_63 -> V_54 , V_54 , V_52 ) ;
V_34 = TRUE ;
}
V_63 -> V_65 |= V_94 | V_208 ;
}
static void
F_147 ( V_14 V_56 , V_14 V_166 V_80 )
{
T_29 * V_161 = ( T_29 * ) V_56 ;
F_43 ( V_161 -> V_68 , V_161 -> V_54 ) ;
}
static void
F_148 ( V_14 V_56 , V_14 V_166 V_80 )
{
T_30 * V_162 = ( T_30 * ) V_56 ;
F_44 ( & ( V_162 -> V_155 ) , V_162 -> V_54 ) ;
}
static void
F_149 ( void )
{
if ( V_164 ) {
F_150 ( V_164 , F_147 , NULL ) ;
}
if ( V_163 ) {
F_150 ( V_163 , F_148 , NULL ) ;
}
}
void
F_151 ( void )
{
char * V_151 ;
T_7 V_5 ;
F_9 ( V_141 == NULL ) ;
V_141 = F_74 ( V_58 , V_59 ) ;
F_9 ( V_89 == NULL ) ;
V_89 = F_74 ( V_210 , V_211 ) ;
F_9 ( V_98 == NULL ) ;
V_98 = F_74 ( F_1 , F_2 ) ;
#ifdef F_48
F_9 ( V_13 == NULL ) ;
V_13 = F_152 ( F_5 () ) ;
#endif
if ( V_164 == NULL )
V_164 = F_152 ( F_5 () ) ;
if ( V_163 == NULL )
V_163 = F_152 ( F_5 () ) ;
if ( ! V_91 . V_196 ) {
V_151 = F_32 ( V_212 ) ;
if ( ! F_101 ( V_151 , TRUE ) && V_190 != V_191 ) {
F_123 ( V_151 , V_190 , FALSE ) ;
}
F_20 ( V_151 ) ;
}
V_151 = F_33 ( V_212 , TRUE ) ;
if ( ! F_101 ( V_151 , TRUE ) && V_190 != V_191 ) {
F_123 ( V_151 , V_190 , FALSE ) ;
}
F_20 ( V_151 ) ;
#ifdef F_48
#ifdef F_142
if ( F_153 ( V_213 ) == V_83 ) {
#endif
if ( F_154 ( & V_205 ) == V_83 && F_154 ( & V_207 ) == V_83 ) {
V_95 = TRUE ;
}
#ifdef F_142
}
#endif
#else
#endif
if ( V_160 && ! V_91 . V_196 ) {
for ( V_5 = 0 ; V_5 < V_160 -> V_2 ; V_5 ++ ) {
F_101 ( ( const char * ) F_106 ( V_160 , V_5 ) , TRUE ) ;
}
}
F_120 () ;
F_149 () ;
}
void
F_155 ( void )
{
T_1 V_5 , V_214 ;
T_33 * V_185 , * V_215 ;
F_140 () ;
if ( V_141 ) {
F_35 ( V_141 ) ;
V_141 = NULL ;
}
if ( V_89 ) {
F_35 ( V_89 ) ;
V_89 = NULL ;
}
if ( V_98 ) {
F_35 ( V_98 ) ;
V_98 = NULL ;
}
for( V_5 = 0 ; V_5 < V_177 ; ++ V_5 ) {
if ( V_180 [ V_5 ] . V_181 != NULL ) {
for ( V_214 = 0 ; V_214 < V_186 ; V_214 ++ ) {
for ( V_185 = V_180 [ V_5 ] . V_181 [ V_214 ] ;
V_185 != NULL ; V_185 = V_215 ) {
V_215 = V_185 -> V_183 ;
F_15 ( F_5 () , V_185 ) ;
}
}
F_15 ( F_5 () , V_180 [ V_5 ] . V_181 ) ;
V_180 [ V_5 ] . V_181 = NULL ;
}
}
V_178 = FALSE ;
V_34 = FALSE ;
}
static void
F_156 ( V_14 V_56 , V_14 V_166 V_80 )
{
T_29 * V_161 = ( T_29 * ) V_56 ;
F_20 ( V_161 ) ;
}
static void
F_157 ( V_14 V_56 , V_14 V_166 V_80 )
{
T_30 * V_162 = ( T_30 * ) V_56 ;
F_20 ( V_162 ) ;
}
void
F_158 ( void )
{
if ( V_164 ) {
F_150 ( V_164 , F_156 , NULL ) ;
V_164 = NULL ;
}
if ( V_163 ) {
F_150 ( V_163 , F_157 , NULL ) ;
V_163 = NULL ;
}
}
T_9 *
F_159 ( T_11 * V_50 , T_7 V_22 )
{
if ( ! V_91 . V_194 ) {
return F_23 ( V_50 , V_22 ) ;
}
return F_16 ( V_50 , F_27 ( V_28 , V_22 ) ) ;
}
T_9 *
F_160 ( T_11 * V_50 , T_7 V_22 )
{
if ( ! V_91 . V_194 ) {
return F_23 ( V_50 , V_22 ) ;
}
return F_16 ( V_50 , F_27 ( V_32 , V_22 ) ) ;
}
T_9 *
F_161 ( T_11 * V_50 , T_7 V_22 )
{
if ( ! V_91 . V_194 ) {
return F_23 ( V_50 , V_22 ) ;
}
return F_16 ( V_50 , F_27 ( V_26 , V_22 ) ) ;
}
T_9 *
F_162 ( T_11 * V_50 , T_7 V_22 )
{
if ( ! V_91 . V_194 ) {
return F_23 ( V_50 , V_22 ) ;
}
return F_16 ( V_50 , F_27 ( V_30 , V_22 ) ) ;
}
T_9 *
F_163 ( T_11 * V_216 , T_6 V_21 , T_7 V_22 )
{
const T_9 * V_217 ;
if ( ! V_91 . V_194 || ( V_21 == V_47 ) ) {
return F_28 ( V_216 , L_8 , V_22 ) ;
}
V_217 = F_27 ( V_21 , V_22 ) ;
F_9 ( V_217 ) ;
return F_28 ( V_216 , L_69 , V_217 , V_22 ) ;
}
int
F_164 ( T_9 * V_15 , T_37 V_218 , T_6 V_21 , T_7 V_22 )
{
const T_9 * V_217 ;
if ( ! V_91 . V_194 || ( V_21 == V_47 ) ) {
return F_39 ( V_15 , V_218 , L_8 , V_22 ) ;
}
V_217 = F_27 ( V_21 , V_22 ) ;
F_9 ( V_217 ) ;
return F_39 ( V_15 , V_218 , L_69 , V_217 , V_22 ) ;
}
const T_9 *
F_165 ( const V_72 * V_9 )
{
T_22 * V_63 ;
T_3 V_130 = V_91 . V_193 ;
V_63 = F_82 ( V_9 , V_130 ) ;
return V_130 ? V_63 -> V_112 : V_63 -> V_113 ;
}
const T_9 *
F_166 ( T_38 * V_219 , T_21 V_220 )
{
return F_165 ( F_167 ( V_219 , V_220 , 6 ) ) ;
}
const T_9 *
F_168 ( const V_72 * V_9 )
{
T_22 * V_63 ;
if ( ! V_91 . V_193 )
return NULL ;
V_63 = F_82 ( V_9 , TRUE ) ;
F_9 ( V_63 != NULL ) ;
if ( V_63 -> V_76 == V_110 ) {
return V_63 -> V_112 ;
}
else {
return NULL ;
}
}
V_72 *
F_169 ( const T_9 * V_54 )
{
return F_83 ( V_54 ) ;
}
void
F_170 ( const T_7 V_88 , const V_72 * V_100 )
{
T_12 * V_63 ;
if ( ! V_91 . V_92 )
return;
V_63 = F_46 ( V_88 ) ;
if ( V_63 -> V_65 & V_208 ) {
F_64 ( V_100 , V_63 -> V_54 ) ;
}
}
T_9 *
F_171 ( T_11 * V_50 , const T_1 V_221 , const char V_222 )
{
T_9 * V_15 = ( T_9 * ) F_8 ( V_50 , 12 ) ;
* F_172 ( V_15 , V_221 , V_222 ) = '\0' ;
return V_15 ;
}
T_9 *
F_173 ( T_11 * V_50 , const T_1 V_9 )
{
if ( ! V_91 . V_92 ) {
return F_171 ( V_50 , V_9 , '\0' ) ;
}
return F_91 ( V_50 , V_9 ) ;
}
T_1
F_174 ( const T_9 * V_54 , T_3 * V_223 )
{
T_1 V_9 ;
T_3 V_142 ;
V_9 = F_92 ( V_54 , & V_142 ) ;
* V_223 = V_142 ;
return V_9 ;
}
T_9 *
F_175 ( T_11 * V_50 , const T_27 V_144 )
{
if ( ! V_91 . V_197 ) {
return NULL ;
}
return F_16 ( V_50 , F_100 ( V_144 ) ) ;
}
const T_9 *
F_176 ( const V_72 * V_9 )
{
T_19 * V_108 ;
V_108 = F_65 ( V_9 ) ;
if ( V_91 . V_193 && V_108 -> V_76 != V_111 )
return V_108 -> V_112 ;
return V_108 -> V_113 ;
}
const T_9 *
F_177 ( const T_7 V_224 )
{
V_72 V_9 [ 3 ] ;
V_9 [ 0 ] = ( V_224 >> 16 ) & 0xFF ;
V_9 [ 1 ] = ( V_224 >> 8 ) & 0xFF ;
V_9 [ 2 ] = ( V_224 >> 0 ) & 0xFF ;
return F_176 ( V_9 ) ;
}
const T_9 *
F_178 ( T_38 * V_219 , T_21 V_220 )
{
return F_176 ( F_167 ( V_219 , V_220 , 3 ) ) ;
}
const T_9 *
F_179 ( const V_72 * V_9 )
{
T_19 * V_108 ;
int V_107 ;
V_72 V_117 ;
V_107 = V_9 [ 0 ] ;
V_107 = V_107 << 8 ;
V_117 = V_9 [ 1 ] ;
V_107 = V_107 | V_117 ;
V_107 = V_107 << 8 ;
V_117 = V_9 [ 2 ] ;
V_107 = V_107 | V_117 ;
V_108 = ( T_19 * ) F_12 ( V_114 , & V_107 ) ;
if ( ( V_108 == NULL ) || ( V_108 -> V_76 != V_111 ) ) {
return NULL ;
}
return V_108 -> V_112 ;
}
const T_9 *
F_180 ( const T_7 V_107 )
{
T_19 * V_108 ;
V_108 = ( T_19 * ) F_12 ( V_114 , & V_107 ) ;
if ( ( V_108 == NULL ) || ( V_108 -> V_76 != V_111 ) ) {
return NULL ;
}
return V_108 -> V_112 ;
}
const T_9 *
F_181 ( T_38 * V_219 , T_21 V_220 )
{
return F_179 ( F_167 ( V_219 , V_220 , 3 ) ) ;
}
char * F_182 ( T_19 * V_225 )
{
return V_225 -> V_112 ;
}
T_9 *
F_183 ( T_11 * V_50 , const T_39 V_226 )
{
V_72 * V_9 = ( V_72 * ) F_8 ( NULL , 8 ) ;
T_19 * V_108 ;
T_9 * V_227 ;
* ( T_39 * ) ( void * ) ( V_9 ) = F_184 ( & ( V_226 ) ) ;
V_108 = F_65 ( V_9 ) ;
if ( ! V_91 . V_193 || ( V_108 -> V_76 == V_111 ) ) {
V_227 = F_28 ( V_50 , L_70 , V_9 [ 0 ] , V_9 [ 1 ] , V_9 [ 2 ] , V_9 [ 3 ] , V_9 [ 4 ] , V_9 [ 5 ] , V_9 [ 6 ] , V_9 [ 7 ] ) ;
} else {
V_227 = F_28 ( V_50 , L_15 , V_108 -> V_112 , V_9 [ 3 ] , V_9 [ 4 ] , V_9 [ 5 ] , V_9 [ 6 ] , V_9 [ 7 ] ) ;
}
F_15 ( NULL , V_9 ) ;
return V_227 ;
}
static void
F_185 (
void * V_75 ,
int V_76 ,
#if ( ( V_77 < 1 ) \
|| ( 1 == V_77 && V_78 < 5 ) )
struct V_79 * T_40
#else
int T_17 V_80 ,
struct V_79 * T_40
#endif
) {
T_41 * V_228 = ( T_41 * ) V_75 ;
if ( V_76 == V_83 && T_40 && V_228 && T_40 -> V_229 == V_228 -> V_230 ) {
memcpy ( V_228 -> V_209 , T_40 -> V_231 , T_40 -> V_229 ) ;
V_228 -> V_232 = T_40 -> V_229 ;
}
}
T_3
F_186 ( const char * V_233 , T_1 * V_209 )
{
struct V_234 V_235 ;
#ifdef F_48
struct V_198 V_199 = { 0 , V_236 } , * V_237 ;
int V_200 ;
T_35 V_201 , V_202 ;
T_41 V_238 ;
#endif
if ( ! F_187 ( V_233 , & V_235 ) ) {
if ( ! V_91 . V_92 ||
! V_91 . V_93 ) {
return FALSE ;
}
#ifdef F_48
if ( ! V_95 || V_96 < 1 ) {
return FALSE ;
}
V_238 . V_230 = ( int ) sizeof ( struct V_234 ) ;
V_238 . V_232 = 0 ;
V_238 . V_209 = V_209 ;
F_188 ( V_207 , V_233 , V_85 , F_185 , & V_238 ) ;
F_135 ( & V_201 ) ;
F_135 ( & V_202 ) ;
V_200 = F_136 ( V_207 , & V_201 , & V_202 ) ;
if ( V_200 > 0 ) {
V_237 = F_189 ( V_207 , & V_199 , & V_199 ) ;
if ( F_137 ( V_200 , & V_201 , & V_202 , NULL , V_237 ) == - 1 ) {
fprintf ( V_206 , L_68 , F_138 ( V_190 ) ) ;
return FALSE ;
}
F_139 ( V_207 , & V_201 , & V_202 ) ;
}
F_190 ( V_207 ) ;
if ( V_238 . V_230 == V_238 . V_232 ) {
return TRUE ;
}
return FALSE ;
#endif
} else {
unsigned int V_132 , V_133 , V_134 , V_135 ;
if ( sscanf ( V_233 , L_71 , & V_132 , & V_133 , & V_134 , & V_135 ) != 4 )
return FALSE ;
}
* V_209 = V_235 . V_239 ;
return TRUE ;
}
T_3
F_191 ( const char * V_233 , struct V_8 * V_209 )
{
#ifdef F_48
struct V_198 V_199 = { 0 , V_236 } , * V_237 ;
int V_200 ;
T_35 V_201 , V_202 ;
T_41 V_238 ;
#endif
if ( F_192 ( V_233 , V_209 ) )
return TRUE ;
if ( ! V_91 . V_92 ||
! V_91 . V_93 ) {
return FALSE ;
}
#ifdef F_48
if ( ! V_95 || V_96 < 1 ) {
return FALSE ;
}
V_238 . V_230 = ( int ) sizeof ( struct V_8 ) ;
V_238 . V_232 = 0 ;
V_238 . V_209 = V_209 ;
F_188 ( V_207 , V_233 , V_87 , F_185 , & V_238 ) ;
F_135 ( & V_201 ) ;
F_135 ( & V_202 ) ;
V_200 = F_136 ( V_207 , & V_201 , & V_202 ) ;
if ( V_200 > 0 ) {
V_237 = F_189 ( V_207 , & V_199 , & V_199 ) ;
if ( F_137 ( V_200 , & V_201 , & V_202 , NULL , V_237 ) == - 1 ) {
fprintf ( V_206 , L_68 , F_138 ( V_190 ) ) ;
return FALSE ;
}
F_139 ( V_207 , & V_201 , & V_202 ) ;
}
F_190 ( V_207 ) ;
if ( V_238 . V_230 == V_238 . V_232 ) {
return TRUE ;
}
#endif
return FALSE ;
}
T_42 *
F_193 ( void )
{
return V_114 ;
}
T_42 *
F_194 ( void )
{
return V_116 ;
}
T_42 *
F_195 ( void )
{
return V_123 ;
}
T_42 *
F_196 ( void )
{
return V_25 ;
}
T_42 *
F_197 ( void )
{
return V_141 ;
}
T_42 *
F_198 ( void )
{
return V_149 ;
}
T_42 *
F_199 ( void )
{
return V_89 ;
}
T_42 *
F_200 ( void )
{
return V_98 ;
}
void
F_201 ( void )
{
F_30 () ;
F_73 () ;
F_89 () ;
F_98 () ;
}
void
F_202 ( void )
{
F_34 () ;
F_76 () ;
F_90 () ;
F_99 () ;
}
T_3
F_116 ( const char * V_240 , void * V_241 )
{
return F_103 ( V_240 , ( T_1 * ) V_241 ) ;
}
T_3
F_192 ( const char * V_240 , void * V_241 )
{
return F_102 ( V_240 , (struct V_8 * ) V_241 ) ;
}
