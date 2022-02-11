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
while ( ( V_18 = F_10 ( V_17 ) ) != V_20 && V_18 != '\r' && V_18 != '\n' ) {
if ( V_2 + 1 >= * V_16 ) {
* V_15 = ( char * ) F_11 ( F_5 () , * V_15 , * V_16 += V_19 ) ;
}
( * V_15 ) [ V_2 ++ ] = V_18 ;
}
if ( V_2 == 0 && V_18 == V_20 )
return - 1 ;
( * V_15 ) [ V_2 ] = '\0' ;
return V_2 ;
}
static void
F_12 ( T_6 V_21 , const T_7 V_22 , const char * V_23 )
{
T_8 * V_24 ;
int * V_1 ;
V_1 = ( int * ) F_4 ( F_5 () , int ) ;
* V_1 = V_22 ;
V_24 = ( T_8 * ) F_13 ( V_25 , & V_22 ) ;
if ( V_24 == NULL ) {
V_24 = F_14 ( F_5 () , T_8 ) ;
F_15 ( V_25 , V_1 , V_24 ) ;
}
else {
F_16 ( F_5 () , V_1 ) ;
}
switch( V_21 ) {
case V_26 :
F_16 ( F_5 () , V_24 -> V_27 ) ;
V_24 -> V_27 = F_17 ( F_5 () , V_23 ) ;
break;
case V_28 :
F_16 ( F_5 () , V_24 -> V_29 ) ;
V_24 -> V_29 = F_17 ( F_5 () , V_23 ) ;
break;
case V_30 :
F_16 ( F_5 () , V_24 -> V_31 ) ;
V_24 -> V_31 = F_17 ( F_5 () , V_23 ) ;
break;
case V_32 :
F_16 ( F_5 () , V_24 -> V_33 ) ;
V_24 -> V_33 = F_17 ( F_5 () , V_23 ) ;
break;
default:
return;
}
V_34 = TRUE ;
}
static void
F_18 ( char * line )
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
if ( V_43 != F_19 ( & V_37 , V_22 , V_38 ) ) {
return;
}
V_44 = V_36 ;
V_45 = V_21 ;
F_20 ( V_37 , V_46 ) ;
F_21 ( V_37 ) ;
V_45 = V_47 ;
}
static void
V_46 ( const T_1 V_22 )
{
if ( V_22 ) {
F_12 ( V_45 , V_22 , V_44 ) ;
}
}
static void
F_22 ( const char * V_48 )
{
T_5 * V_49 ;
static int V_16 = 0 ;
static char * V_15 = NULL ;
V_49 = F_23 ( V_48 , L_7 ) ;
if ( V_49 == NULL )
return;
while ( F_7 ( & V_15 , & V_16 , V_49 ) >= 0 ) {
F_18 ( V_15 ) ;
}
fclose ( V_49 ) ;
}
static T_9 *
F_24 ( T_11 * V_50 , T_7 V_22 )
{
T_9 * V_51 = ( T_9 * ) F_8 ( V_50 , V_52 ) ;
F_25 ( V_22 , V_51 , V_52 ) ;
return V_51 ;
}
static const T_9 *
F_26 ( T_6 V_21 , T_7 V_22 , T_8 * * V_53 )
{
T_8 * V_24 ;
V_24 = ( T_8 * ) F_13 ( V_25 , & V_22 ) ;
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
F_27 ( T_6 V_21 , T_7 V_22 )
{
return F_26 ( V_21 , V_22 , NULL ) ;
}
const T_9 *
F_28 ( T_6 V_21 , T_7 V_22 )
{
T_8 * V_24 = NULL ;
const char * V_54 ;
T_7 * V_1 ;
V_54 = F_26 ( V_21 , V_22 , & V_24 ) ;
if ( V_54 != NULL )
return V_54 ;
if ( V_24 == NULL ) {
V_1 = ( T_7 * ) F_4 ( F_5 () , T_7 ) ;
* V_1 = V_22 ;
V_24 = F_14 ( F_5 () , T_8 ) ;
F_15 ( V_25 , V_1 , V_24 ) ;
}
if ( V_24 -> V_55 == NULL ) {
V_24 -> V_55 = F_29 ( F_5 () , L_8 , V_22 ) ;
}
return V_24 -> V_55 ;
}
static void
F_30 ( void )
{
F_9 ( V_25 == NULL ) ;
V_25 = F_31 ( F_5 () , V_56 , V_57 ) ;
if ( V_58 == NULL ) {
V_58 = F_32 ( V_59 ) ;
}
F_22 ( V_58 ) ;
if ( V_60 == NULL ) {
V_60 = F_33 ( V_59 , FALSE ) ;
}
F_22 ( V_60 ) ;
}
static void
F_34 ( void )
{
V_25 = NULL ;
}
static void
F_35 ( const T_7 V_9 , T_12 * volatile V_61 )
{
T_13 V_62 ;
if ( V_61 -> V_63 & V_64 )
return;
V_61 -> V_63 |= V_64 ;
V_62 = F_36 ( V_9 ) ;
if ( 0 != V_62 . V_65 ) {
T_1 V_66 ;
T_9 V_67 [ V_68 ] ;
T_9 * V_69 ;
T_14 V_5 ;
V_66 = V_9 & ( ~ ( T_1 ) V_62 . V_65 ) ;
F_37 ( ( V_70 * ) & V_66 , V_67 , V_68 ) ;
V_69 = V_67 ;
V_5 = V_62 . V_71 / 8 ;
while( * ( V_69 ) != '\0' && V_5 > 0 ) {
if ( * ( ++ V_69 ) == '.' ) {
-- V_5 ;
}
}
F_38 ( V_61 -> V_54 , V_52 , L_9 , V_62 . V_54 , V_69 ) ;
} else {
F_37 ( ( const V_70 * ) & V_9 , V_61 -> V_54 , V_52 ) ;
}
}
static void
F_39 ( T_15 * volatile V_61 )
{
if ( V_61 -> V_63 & V_64 )
return;
V_61 -> V_63 |= V_64 ;
F_40 ( V_61 -> V_54 , V_61 -> V_72 , V_52 ) ;
}
static void
F_41 (
void * V_73 ,
int V_74 ,
#if ( ( V_75 < 1 ) \
|| ( 1 == V_75 && V_76 < 5 ) )
struct V_77 * T_16
#else
int T_17 V_78 ,
struct V_77 * T_16
#endif
) {
T_4 * V_79 = ( T_4 * ) V_73 ;
char * * V_3 ;
if ( ! V_79 ) return;
V_80 -- ;
if ( V_74 == V_81 ) {
for ( V_3 = T_16 -> V_82 ; * V_3 != NULL ; V_3 ++ ) {
switch( V_79 -> V_11 ) {
case V_83 :
F_42 ( V_79 -> V_9 . V_12 , T_16 -> V_84 ) ;
break;
case V_85 :
F_43 ( & V_79 -> V_9 . V_72 , T_16 -> V_84 ) ;
break;
default:
break;
}
}
}
F_16 ( F_5 () , V_79 ) ;
}
static T_12 *
F_44 ( const T_7 V_9 )
{
T_12 * V_61 = F_4 ( F_5 () , T_12 ) ;
V_61 -> V_9 = V_9 ;
V_61 -> V_63 = 0 ;
V_61 -> V_54 [ 0 ] = '\0' ;
F_37 ( ( const V_70 * ) & V_9 , V_61 -> V_86 , sizeof( V_61 -> V_86 ) ) ;
return V_61 ;
}
static T_12 *
F_45 ( const T_7 V_9 )
{
T_12 * volatile V_61 ;
V_61 = ( T_12 * ) F_13 ( V_87 , F_46 ( V_9 ) ) ;
if ( V_61 == NULL ) {
V_61 = F_44 ( V_9 ) ;
F_15 ( V_87 , F_46 ( V_9 ) , V_61 ) ;
} else if ( ( V_61 -> V_63 & V_88 ) != V_64 ) {
return V_61 ;
}
F_35 ( V_9 , V_61 ) ;
if ( ! V_89 . V_90 )
return V_61 ;
if ( V_89 . V_91 ) {
V_61 -> V_63 |= V_92 ;
#ifdef F_47
if ( V_93 && V_94 > 0 ) {
F_3 ( V_83 , V_9 ) ;
}
#endif
}
return V_61 ;
}
static T_15 *
F_48 ( const struct V_8 * V_9 )
{
T_15 * V_61 = F_4 ( F_5 () , T_15 ) ;
memcpy ( V_61 -> V_9 , V_9 -> V_95 , sizeof V_61 -> V_9 ) ;
V_61 -> V_63 = 0 ;
V_61 -> V_54 [ 0 ] = '\0' ;
F_49 ( V_9 , V_61 -> V_72 , sizeof( V_61 -> V_72 ) ) ;
return V_61 ;
}
static T_15 *
F_50 ( const struct V_8 * V_9 )
{
T_15 * volatile V_61 ;
#ifdef F_47
T_4 * V_79 ;
#endif
V_61 = ( T_15 * ) F_13 ( V_96 , V_9 ) ;
if ( V_61 == NULL ) {
struct V_8 * V_97 ;
V_97 = F_4 ( F_5 () , struct V_8 ) ;
V_61 = F_48 ( V_9 ) ;
memcpy ( V_97 , V_9 , 16 ) ;
F_15 ( V_96 , V_97 , V_61 ) ;
} else if ( ( V_61 -> V_63 & V_88 ) != V_64 ) {
return V_61 ;
}
F_39 ( V_61 ) ;
if ( ! V_89 . V_90 )
return V_61 ;
if ( V_89 . V_91 ) {
V_61 -> V_63 |= V_92 ;
#ifdef F_47
if ( V_93 && V_94 > 0 ) {
V_79 = F_4 ( F_5 () , T_4 ) ;
V_79 -> V_11 = V_85 ;
memcpy ( & V_79 -> V_9 . V_72 , V_9 , sizeof( V_79 -> V_9 . V_72 ) ) ;
F_6 ( V_13 , ( V_14 ) V_79 ) ;
}
#endif
}
return V_61 ;
}
static T_3
F_51 ( const char * V_35 , T_18 * V_98 , unsigned int * V_65 ,
const T_3 V_99 )
{
int V_5 ;
unsigned long V_100 ;
char * V_3 ;
char V_101 = '\0' ;
for ( V_5 = 0 ; V_5 < 6 ; V_5 ++ ) {
if ( ! F_52 ( * V_35 ) )
return FALSE ;
V_100 = strtoul ( V_35 , & V_3 , 16 ) ;
if ( V_3 == V_35 )
return FALSE ;
if ( V_100 > 0xFF )
return FALSE ;
V_98 -> V_9 [ V_5 ] = ( V_70 ) V_100 ;
V_35 = V_3 ;
if ( * V_35 == '/' ) {
if ( ! V_99 ) {
return FALSE ;
}
V_35 ++ ;
if ( ! F_53 ( * V_35 ) )
return FALSE ;
V_100 = strtoul ( V_35 , & V_3 , 10 ) ;
if ( V_3 == V_35 )
return FALSE ;
V_35 = V_3 ;
if ( * V_35 != '\0' && ! F_54 ( * V_35 ) )
return FALSE ;
if ( V_100 == 0 || V_100 >= 48 )
return FALSE ;
* V_65 = ( int ) V_100 ;
for ( V_5 = 0 ; V_100 >= 8 ; V_5 ++ , V_100 -= 8 )
;
V_98 -> V_9 [ V_5 ] &= ( 0xFF << ( 8 - V_100 ) ) ;
V_5 ++ ;
for (; V_5 < 6 ; V_5 ++ )
V_98 -> V_9 [ V_5 ] = 0 ;
return TRUE ;
}
if ( * V_35 == '\0' ) {
if ( V_5 == 2 ) {
if ( ! V_99 ) {
return FALSE ;
}
* V_65 = 0 ;
return TRUE ;
}
if ( V_5 == 5 ) {
if ( V_99 )
* V_65 = 48 ;
return TRUE ;
}
return FALSE ;
} else {
if ( V_101 == '\0' ) {
if ( * V_35 != ':' && * V_35 != '-' && * V_35 != '.' )
return FALSE ;
V_101 = * V_35 ;
} else {
if ( * V_35 != V_101 )
return FALSE ;
}
}
V_35 ++ ;
}
return TRUE ;
}
static int
F_55 ( char * line , T_18 * V_98 , unsigned int * V_65 ,
const T_3 V_99 )
{
T_9 * V_35 ;
if ( ( V_35 = strchr ( line , '#' ) ) )
* V_35 = '\0' ;
if ( ( V_35 = strtok ( line , L_1 ) ) == NULL )
return - 1 ;
if ( ! F_51 ( V_35 , V_98 , V_65 , V_99 ) )
return - 1 ;
if ( ( V_35 = strtok ( NULL , L_1 ) ) == NULL )
return - 1 ;
F_40 ( V_98 -> V_54 , V_35 , V_52 ) ;
return 0 ;
}
static void
F_56 ( char * V_48 )
{
if ( V_102 )
rewind ( V_102 ) ;
else
V_102 = F_23 ( V_48 , L_7 ) ;
}
static void
F_57 ( void )
{
if ( V_102 ) {
fclose ( V_102 ) ;
V_102 = NULL ;
}
}
static T_18 *
F_58 ( unsigned int * V_65 , const T_3 V_99 )
{
static T_18 V_98 ;
static int V_16 = 0 ;
static char * V_15 = NULL ;
if ( V_102 == NULL )
return NULL ;
while ( F_7 ( & V_15 , & V_16 , V_102 ) >= 0 ) {
if ( F_55 ( V_15 , & V_98 , V_65 , V_99 ) == 0 ) {
return & V_98 ;
}
}
return NULL ;
}
static T_18 *
F_59 ( const V_70 * V_9 )
{
T_18 * V_98 ;
F_56 ( V_103 ) ;
while ( ( ( V_98 = F_58 ( NULL , FALSE ) ) != NULL ) && memcmp ( V_9 , V_98 -> V_9 , 6 ) != 0 )
;
if ( V_98 == NULL ) {
F_57 () ;
F_56 ( V_104 ) ;
while ( ( ( V_98 = F_58 ( NULL , FALSE ) ) != NULL ) && memcmp ( V_9 , V_98 -> V_9 , 6 ) != 0 )
;
F_57 () ;
}
return V_98 ;
}
static T_19 * F_60 ( const V_70 * V_9 , char * V_54 )
{
int * V_105 ;
T_19 * V_106 ;
char * V_107 ;
V_105 = ( int * ) F_4 ( F_5 () , int ) ;
* V_105 = ( int ) ( ( V_9 [ 0 ] << 16 ) + ( V_9 [ 1 ] << 8 ) + V_9 [ 2 ] ) ;
V_106 = F_4 ( F_5 () , T_19 ) ;
memcpy ( V_106 -> V_9 , V_9 , 3 ) ;
V_106 -> V_74 = ( V_54 != NULL ) ? V_108 : V_109 ;
if ( V_54 != NULL ) {
F_40 ( V_106 -> V_110 , V_54 , V_52 ) ;
V_106 -> V_74 = V_108 ;
}
else {
V_106 -> V_74 = V_109 ;
V_106 -> V_110 [ 0 ] = '\0' ;
}
V_107 = F_61 ( V_106 -> V_111 , V_9 , sizeof( V_106 -> V_9 ) , ':' ) ;
* V_107 = '\0' ;
F_15 ( V_112 , V_105 , V_106 ) ;
return V_106 ;
}
static void
F_62 ( const V_70 * V_9 , unsigned int V_65 , T_9 * V_54 )
{
V_70 * V_113 ;
if ( V_65 >= 48 ) {
F_63 ( V_9 , V_54 ) ;
return;
}
if ( V_65 == 0 ) {
F_60 ( V_9 , V_54 ) ;
return;
}
V_113 = ( V_70 * ) F_8 ( F_5 () , 6 ) ;
memcpy ( V_113 , V_9 , 6 ) ;
F_15 ( V_114 , V_113 , F_17 ( F_5 () , V_54 ) ) ;
}
static T_19 *
F_64 ( const V_70 * V_9 )
{
T_20 V_105 = 0 ;
V_70 V_115 ;
T_19 * V_106 ;
V_105 = V_9 [ 0 ] ;
V_105 = V_105 << 8 ;
V_115 = V_9 [ 1 ] ;
V_105 = V_105 | V_115 ;
V_105 = V_105 << 8 ;
V_115 = V_9 [ 2 ] ;
V_105 = V_105 | V_115 ;
V_106 = ( T_19 * ) F_13 ( V_112 , & V_105 ) ;
if ( V_106 != NULL ) {
return V_106 ;
}
if ( ( V_105 & 0x00010000 ) != 0 ) {
V_105 &= 0x00FEFFFF ;
V_106 = ( T_19 * ) F_13 ( V_112 , & V_105 ) ;
if ( V_106 != NULL ) {
return V_106 ;
}
}
return F_60 ( V_9 , NULL ) ;
}
static T_9 *
F_65 ( const V_70 * V_9 , const unsigned int V_65 )
{
V_70 V_116 [ 6 ] ;
T_7 V_100 ;
T_21 V_5 ;
T_9 * V_54 ;
if ( V_114 == NULL ) {
return NULL ;
}
for ( V_5 = 0 , V_100 = V_65 ; V_100 >= 8 ; V_5 ++ , V_100 -= 8 )
V_116 [ V_5 ] = V_9 [ V_5 ] ;
V_116 [ V_5 ] = V_9 [ V_5 ] & ( 0xFF << ( 8 - V_100 ) ) ;
V_5 ++ ;
for (; V_5 < 6 ; V_5 ++ )
V_116 [ V_5 ] = 0 ;
V_54 = ( T_9 * ) F_13 ( V_114 , V_116 ) ;
return V_54 ;
}
T_7 F_66 ( T_22 * V_117 )
{
return V_117 -> V_74 ;
}
char * F_67 ( T_22 * V_117 )
{
return V_117 -> V_111 ;
}
char * F_68 ( T_22 * V_117 )
{
return V_117 -> V_110 ;
}
static T_7
F_69 ( T_2 V_1 )
{
return F_70 ( ( const V_70 * ) V_1 , 6 ) ;
}
static T_3
F_71 ( T_2 V_118 , T_2 V_119 )
{
return ( memcmp ( V_118 , V_119 , 6 ) == 0 ) ;
}
static void
F_72 ( void )
{
T_18 * V_98 ;
char * V_120 ;
T_7 V_65 = 0 ;
V_114 = F_31 ( F_5 () , F_69 , F_71 ) ;
V_112 = F_31 ( F_5 () , V_56 , V_57 ) ;
V_121 = F_31 ( F_5 () , F_69 , F_71 ) ;
if ( V_104 == NULL ) {
V_104 = F_29 ( F_5 () , L_10 V_122 L_10 ,
F_73 () , V_123 ) ;
}
if ( V_103 == NULL )
V_103 = F_33 ( V_123 , FALSE ) ;
V_120 = F_32 ( V_124 ) ;
F_56 ( V_120 ) ;
while ( ( V_98 = F_58 ( & V_65 , TRUE ) ) ) {
F_62 ( V_98 -> V_9 , V_65 , V_98 -> V_54 ) ;
}
F_57 () ;
F_21 ( V_120 ) ;
}
static T_22 *
F_74 ( T_22 * V_61 ) {
T_18 * V_98 ;
T_19 * V_106 ;
const V_70 * V_9 = V_61 -> V_9 ;
if ( ( V_98 = F_59 ( V_9 ) ) != NULL ) {
F_40 ( V_61 -> V_110 , V_98 -> V_54 , V_52 ) ;
V_61 -> V_74 = V_108 ;
return V_61 ;
} else {
T_7 V_65 ;
T_9 * V_54 ;
T_23 V_125 ;
V_65 = 7 ;
for (; ; ) {
if ( ( V_54 = F_65 ( V_9 , V_65 + 40 ) ) != NULL ) {
F_38 ( V_61 -> V_110 , V_52 , L_11 ,
V_54 , V_9 [ 5 ] & ( 0xFF >> V_65 ) ) ;
V_61 -> V_74 = V_126 ;
return V_61 ;
}
if ( V_65 == 0 )
break;
V_65 -- ;
}
V_65 = 7 ;
for (; ; ) {
if ( ( V_54 = F_65 ( V_9 , V_65 + 32 ) ) != NULL ) {
F_38 ( V_61 -> V_110 , V_52 , L_12 ,
V_54 , V_9 [ 4 ] & ( 0xFF >> V_65 ) , V_9 [ 5 ] ) ;
V_61 -> V_74 = V_126 ;
return V_61 ;
}
if ( V_65 == 0 )
break;
V_65 -- ;
}
V_65 = 7 ;
for (; ; ) {
if ( ( V_54 = F_65 ( V_9 , V_65 + 24 ) ) != NULL ) {
F_38 ( V_61 -> V_110 , V_52 , L_13 ,
V_54 , V_9 [ 3 ] & ( 0xFF >> V_65 ) , V_9 [ 4 ] , V_9 [ 5 ] ) ;
V_61 -> V_74 = V_126 ;
return V_61 ;
}
if ( V_65 == 0 )
break;
V_65 -- ;
}
V_106 = F_64 ( V_9 ) ;
if ( ( V_106 != NULL ) && ( V_106 -> V_74 != V_109 ) ) {
F_38 ( V_61 -> V_110 , V_52 , L_13 ,
V_106 -> V_110 , V_9 [ 3 ] , V_9 [ 4 ] , V_9 [ 5 ] ) ;
V_61 -> V_74 = V_126 ;
return V_61 ;
}
V_65 = 7 ;
for (; ; ) {
if ( ( V_54 = F_65 ( V_9 , V_65 + 16 ) ) != NULL ) {
F_38 ( V_61 -> V_110 , V_52 , L_14 ,
V_54 , V_9 [ 2 ] & ( 0xFF >> V_65 ) , V_9 [ 3 ] , V_9 [ 4 ] ,
V_9 [ 5 ] ) ;
V_61 -> V_74 = V_126 ;
return V_61 ;
}
if ( V_65 == 0 )
break;
V_65 -- ;
}
V_65 = 7 ;
for (; ; ) {
if ( ( V_54 = F_65 ( V_9 , V_65 + 8 ) ) != NULL ) {
F_38 ( V_61 -> V_110 , V_52 , L_15 ,
V_54 , V_9 [ 1 ] & ( 0xFF >> V_65 ) , V_9 [ 2 ] , V_9 [ 3 ] ,
V_9 [ 4 ] , V_9 [ 5 ] ) ;
V_61 -> V_74 = V_126 ;
return V_61 ;
}
if ( V_65 == 0 )
break;
V_65 -- ;
}
for ( V_65 = 7 ; V_65 > 0 ; V_65 -- ) {
if ( ( V_54 = F_65 ( V_9 , V_65 ) ) != NULL ) {
F_38 ( V_61 -> V_110 , V_52 , L_16 ,
V_54 , V_9 [ 0 ] & ( 0xFF >> V_65 ) , V_9 [ 1 ] , V_9 [ 2 ] ,
V_9 [ 3 ] , V_9 [ 4 ] , V_9 [ 5 ] ) ;
V_61 -> V_74 = V_126 ;
return V_61 ;
}
}
F_75 ( & V_125 , V_127 , 6 , V_9 ) ;
F_76 ( & V_125 , V_61 -> V_110 , V_52 ) ;
V_61 -> V_74 = V_126 ;
return V_61 ;
}
F_77 () ;
}
static T_22 *
F_78 ( const V_70 * V_9 , const T_3 V_128 )
{
T_22 * V_61 ;
char * V_107 ;
V_61 = F_4 ( F_5 () , T_22 ) ;
memcpy ( V_61 -> V_9 , V_9 , sizeof( V_61 -> V_9 ) ) ;
V_61 -> V_74 = V_109 ;
V_107 = F_61 ( V_61 -> V_111 , V_9 , sizeof( V_61 -> V_9 ) , ':' ) ;
* V_107 = '\0' ;
V_61 -> V_110 [ 0 ] = '\0' ;
if ( V_128 )
F_74 ( V_61 ) ;
F_15 ( V_121 , V_61 -> V_9 , V_61 ) ;
return V_61 ;
}
static T_22 *
F_63 ( const V_70 * V_9 , const T_9 * V_54 )
{
T_22 * V_61 ;
V_61 = ( T_22 * ) F_13 ( V_121 , V_9 ) ;
if ( V_61 == NULL ) {
V_61 = F_78 ( V_9 , FALSE ) ;
}
if ( strcmp ( V_61 -> V_110 , V_54 ) != 0 ) {
F_40 ( V_61 -> V_110 , V_54 , V_52 ) ;
V_61 -> V_74 = V_108 ;
V_34 = TRUE ;
}
return V_61 ;
}
static T_22 *
F_79 ( const V_70 * V_9 , const T_3 V_128 )
{
T_22 * V_61 ;
V_61 = ( T_22 * ) F_13 ( V_121 , V_9 ) ;
if ( V_61 == NULL ) {
V_61 = F_78 ( V_9 , V_128 ) ;
} else {
if ( V_128 && ( V_61 -> V_74 == V_109 ) ) {
F_74 ( V_61 ) ;
}
}
return V_61 ;
}
static V_70 *
F_80 ( const T_9 * V_54 V_78 )
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
F_81 ( char * line , T_24 * V_129 )
{
T_9 * V_35 ;
T_1 V_118 , V_130 , V_131 , V_132 , V_133 ;
T_3 V_134 = FALSE ;
if ( ( V_35 = strchr ( line , '#' ) ) )
* V_35 = '\0' ;
if ( ( V_35 = strtok ( line , L_17 ) ) == NULL )
return - 1 ;
if ( sscanf ( V_35 , L_18 , & V_130 , & V_131 , & V_132 , & V_133 ) != 4 ) {
if ( sscanf ( V_35 , L_19 , & V_130 , & V_131 , & V_132 , & V_133 ) != 4 ) {
if ( sscanf ( V_35 , L_20 , & V_130 , & V_131 , & V_132 , & V_133 ) != 4 ) {
if ( sscanf ( V_35 , L_21 , & V_118 ) == 1 ) {
V_134 = TRUE ;
}
else {
return - 1 ;
}
}
}
}
if ( ( V_35 = strtok ( NULL , L_17 ) ) == NULL )
return - 1 ;
if ( V_134 ) {
V_129 -> V_9 = V_118 ;
}
else {
V_129 -> V_9 = ( V_130 << 24 ) | ( V_131 << 16 ) | ( V_132 << 8 ) | V_133 ;
}
F_40 ( V_129 -> V_54 , V_35 , V_52 ) ;
return 0 ;
}
static void
F_82 ( char * V_48 )
{
if ( V_135 )
rewind ( V_135 ) ;
else
V_135 = F_23 ( V_48 , L_7 ) ;
}
static void
F_83 ( void )
{
if ( V_135 ) {
fclose ( V_135 ) ;
V_135 = NULL ;
}
}
static T_24 *
F_84 ( void )
{
static T_24 V_129 ;
static int V_16 = 0 ;
static char * V_15 = NULL ;
if ( V_135 == NULL )
return NULL ;
while ( F_7 ( & V_15 , & V_16 , V_135 ) >= 0 ) {
if ( F_81 ( V_15 , & V_129 ) == 0 ) {
return & V_129 ;
}
}
return NULL ;
}
static T_24 *
F_85 ( T_1 V_9 )
{
T_24 * V_129 ;
F_82 ( V_136 ) ;
while ( ( ( V_129 = F_84 () ) != NULL ) && ( V_9 != V_129 -> V_9 ) ) ;
if ( V_129 == NULL ) {
F_83 () ;
F_82 ( V_137 ) ;
while ( ( ( V_129 = F_84 () ) != NULL ) && ( V_9 != V_129 -> V_9 ) )
;
F_83 () ;
}
return V_129 ;
}
static void
F_86 ( void )
{
if ( V_136 == NULL ) {
V_136 = F_29 ( F_5 () , L_10 V_122 L_10 ,
F_73 () , V_138 ) ;
}
if ( V_137 == NULL )
V_137 = F_33 ( V_138 , FALSE ) ;
}
static void
F_87 ( void )
{
V_139 = NULL ;
}
static T_9 *
F_88 ( T_11 * V_50 , const T_7 V_9 )
{
T_25 * V_61 ;
T_24 * V_129 ;
V_61 = ( T_25 * ) F_13 ( V_139 , & V_9 ) ;
if ( V_61 == NULL ) {
int * V_1 ;
V_1 = ( int * ) F_4 ( F_5 () , int ) ;
* V_1 = V_9 ;
V_61 = F_4 ( F_5 () , T_25 ) ;
F_15 ( V_139 , V_1 , V_61 ) ;
} else {
return F_17 ( V_50 , V_61 -> V_54 ) ;
}
V_61 -> V_9 = V_9 ;
if ( ( V_129 = F_85 ( V_9 ) ) == NULL ) {
F_38 ( V_61 -> V_54 , V_52 , L_22 , V_9 ) ;
} else {
F_40 ( V_61 -> V_54 , V_129 -> V_54 , V_52 ) ;
}
return F_17 ( V_50 , V_61 -> V_54 ) ;
}
static T_7
F_89 ( const T_9 * V_54 V_78 , T_3 * V_140 )
{
* V_140 = FALSE ;
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
F_90 ( char * line , T_26 * V_141 )
{
T_9 * V_35 ;
T_27 V_142 ;
if ( ( V_35 = strchr ( line , '#' ) ) )
* V_35 = '\0' ;
if ( ( V_35 = strtok ( line , L_17 ) ) == NULL )
return - 1 ;
if ( sscanf ( V_35 , L_23 V_143 , & V_142 ) == 1 ) {
V_141 -> V_142 = V_142 ;
}
else {
return - 1 ;
}
if ( ( V_35 = strtok ( NULL , L_24 ) ) == NULL )
return - 1 ;
F_40 ( V_141 -> V_54 , V_35 , V_144 ) ;
return 0 ;
}
static void
F_91 ( char * V_48 )
{
if ( V_145 )
rewind ( V_145 ) ;
else
V_145 = F_23 ( V_48 , L_7 ) ;
}
static void
F_92 ( void )
{
if ( V_145 ) {
fclose ( V_145 ) ;
V_145 = NULL ;
}
}
static T_26 *
F_93 ( void )
{
static T_26 V_141 ;
static int V_16 = 0 ;
static char * V_15 = NULL ;
if ( V_145 == NULL )
return NULL ;
while ( F_7 ( & V_15 , & V_16 , V_145 ) >= 0 ) {
if ( F_90 ( V_15 , & V_141 ) == 0 ) {
return & V_141 ;
}
}
return NULL ;
}
static T_26 *
F_94 ( T_27 V_142 )
{
T_26 * V_141 ;
F_91 ( V_146 ) ;
while ( ( ( V_141 = F_93 () ) != NULL ) && ( V_142 != V_141 -> V_142 ) ) ;
if ( V_141 == NULL ) {
F_92 () ;
}
return V_141 ;
}
static void
F_95 ( void )
{
F_9 ( V_147 == NULL ) ;
V_147 = F_31 ( F_5 () , V_56 , V_57 ) ;
if ( V_146 == NULL )
V_146 = F_33 ( V_148 , FALSE ) ;
}
static void
F_96 ( void )
{
V_147 = NULL ;
}
static const T_9 *
F_97 ( const T_7 V_142 )
{
T_28 * V_61 ;
T_26 * V_141 ;
V_61 = ( T_28 * ) F_13 ( V_147 , & V_142 ) ;
if ( V_61 == NULL ) {
int * V_1 ;
V_1 = ( int * ) F_4 ( F_5 () , int ) ;
* V_1 = V_142 ;
V_61 = F_4 ( F_5 () , T_28 ) ;
F_15 ( V_147 , V_1 , V_61 ) ;
} else {
return V_61 -> V_54 ;
}
V_61 -> V_142 = V_142 ;
if ( ( V_141 = F_94 ( V_142 ) ) == NULL ) {
F_38 ( V_61 -> V_54 , V_144 , L_25 , V_142 ) ;
} else {
F_40 ( V_61 -> V_54 , V_141 -> V_54 , V_144 ) ;
}
return V_61 -> V_54 ;
}
static T_3
F_98 ( const char * V_149 , T_3 V_150 )
{
T_5 * V_151 ;
char * line = NULL ;
int V_16 = 0 ;
T_9 * V_35 ;
union {
T_1 V_152 ;
struct V_8 V_153 ;
} V_66 ;
T_3 V_154 , V_155 = FALSE ;
if ( ( V_151 = F_23 ( V_149 , L_7 ) ) == NULL )
return FALSE ;
while ( F_7 ( & line , & V_16 , V_151 ) >= 0 ) {
if ( ( V_35 = strchr ( line , '#' ) ) )
* V_35 = '\0' ;
if ( ( V_35 = strtok ( line , L_1 ) ) == NULL )
continue;
if ( F_99 ( V_35 , & V_66 . V_153 ) ) {
V_154 = TRUE ;
} else if ( F_100 ( V_35 , & V_66 . V_152 ) ) {
V_154 = FALSE ;
} else {
continue;
}
if ( ( V_35 = strtok ( NULL , L_1 ) ) == NULL )
continue;
V_155 = TRUE ;
if ( V_150 ) {
if ( V_154 ) {
F_43 ( & V_66 . V_153 , V_35 ) ;
} else {
F_42 ( V_66 . V_152 , V_35 ) ;
}
}
}
F_16 ( F_5 () , line ) ;
fclose ( V_151 ) ;
return V_155 ? TRUE : FALSE ;
}
T_3
F_101 ( const char * V_156 )
{
T_3 V_157 = FALSE ;
T_7 V_5 ;
if ( ! V_156 )
return FALSE ;
if ( ! V_158 )
V_158 = F_102 () ;
for ( V_5 = 0 ; V_5 < V_158 -> V_2 ; V_5 ++ ) {
if ( strcmp ( V_156 , ( const char * ) F_103 ( V_158 , V_5 ) ) == 0 )
V_157 = TRUE ;
}
if ( ! V_157 ) {
F_104 ( V_158 , F_17 ( F_5 () , V_156 ) ) ;
return F_98 ( V_156 , FALSE ) ;
}
return TRUE ;
}
T_3
F_105 ( const char * V_9 , const char * V_54 )
{
union {
T_1 V_152 ;
struct V_8 V_153 ;
} V_66 ;
T_3 V_154 ;
T_29 * V_159 ;
T_30 * V_160 ;
if ( F_99 ( V_9 , & V_66 . V_153 ) ) {
V_154 = TRUE ;
} else if ( F_100 ( V_9 , & V_66 . V_152 ) ) {
V_154 = FALSE ;
} else {
return FALSE ;
}
if ( V_154 ) {
V_160 = F_4 ( F_5 () , T_30 ) ;
memcpy ( & ( V_160 -> V_153 ) , & V_66 . V_153 , 16 ) ;
F_40 ( V_160 -> V_54 , V_54 , V_52 ) ;
F_106 ( V_161 , V_160 ) ;
} else {
V_159 = F_4 ( F_5 () , T_29 ) ;
V_159 -> V_66 = V_66 . V_152 ;
F_40 ( V_159 -> V_54 , V_54 , V_52 ) ;
F_106 ( V_162 , V_159 ) ;
}
return TRUE ;
}
static void
F_107 ( V_14 V_1 V_78 , V_14 V_163 , V_14 V_164 )
{
T_31 * V_165 = ( T_31 * ) V_164 ;
T_12 * V_166 = ( T_12 * ) V_163 ;
if ( ( V_166 -> V_63 & V_167 ) == V_168 ) {
V_165 -> V_169 = F_108 ( V_165 -> V_169 , V_166 ) ;
}
}
static void
F_109 ( V_14 V_1 V_78 , V_14 V_163 , V_14 V_164 )
{
T_31 * V_165 = ( T_31 * ) V_164 ;
T_15 * V_170 = ( T_15 * ) V_163 ;
if ( ( V_170 -> V_63 & V_167 ) == V_168 ) {
V_165 -> V_171 = F_108 ( V_165 -> V_171 , V_170 ) ;
}
}
T_31 *
F_110 ( void )
{
if ( V_87 ) {
F_111 ( V_87 , F_107 , & V_172 ) ;
}
if ( V_96 ) {
F_111 ( V_96 , F_109 , & V_172 ) ;
}
return & V_172 ;
}
static T_3
F_112 ( const char * V_173 )
{
T_5 * V_151 ;
char * line = NULL ;
int V_16 = 0 ;
T_9 * V_35 , * V_174 ;
T_1 V_66 ;
int V_71 ;
if ( ( V_151 = F_23 ( V_173 , L_7 ) ) == NULL )
return FALSE ;
while ( F_7 ( & line , & V_16 , V_151 ) >= 0 ) {
if ( ( V_35 = strchr ( line , '#' ) ) )
* V_35 = '\0' ;
if ( ( V_35 = strtok ( line , L_1 ) ) == NULL )
continue;
V_174 = strchr ( V_35 , '/' ) ;
if ( NULL == V_174 ) {
continue;
}
* V_174 = '\0' ;
++ V_174 ;
if ( ! F_113 ( V_35 , & V_66 ) ) {
continue;
}
V_71 = atoi ( V_174 ) ;
if ( 0 >= V_71 || V_71 > 32 ) {
continue;
}
if ( ( V_35 = strtok ( NULL , L_1 ) ) == NULL )
continue;
F_114 ( V_66 , ( T_1 ) V_71 , V_35 ) ;
}
F_16 ( F_5 () , line ) ;
fclose ( V_151 ) ;
return TRUE ;
}
static T_13
F_36 ( const T_1 V_9 )
{
T_13 V_62 ;
T_1 V_5 ;
V_5 = V_175 ;
while( V_176 && V_5 > 0 ) {
T_1 V_116 ;
T_32 * V_177 ;
-- V_5 ;
F_9 ( V_5 < V_175 ) ;
V_177 = & V_178 [ V_5 ] ;
if ( NULL != V_177 -> V_179 ) {
T_33 * V_61 ;
T_1 V_180 ;
V_116 = V_9 & V_177 -> V_65 ;
V_180 = F_115 ( V_116 ) ;
V_61 = V_177 -> V_179 [ V_180 ] ;
while( V_61 != NULL && V_61 -> V_9 != V_116 ) {
V_61 = V_61 -> V_181 ;
}
if ( NULL != V_61 ) {
V_62 . V_65 = V_177 -> V_65 ;
V_62 . V_71 = V_5 + 1 ;
V_62 . V_54 = V_61 -> V_54 ;
return V_62 ;
}
}
}
V_62 . V_65 = 0 ;
V_62 . V_71 = 0 ;
V_62 . V_54 = NULL ;
return V_62 ;
}
static void
F_114 ( T_1 V_182 , const T_1 V_71 , const T_9 * V_54 )
{
T_32 * V_183 ;
T_33 * V_61 ;
T_14 V_180 ;
F_9 ( V_71 > 0 && V_71 <= 32 ) ;
V_183 = & V_178 [ V_71 - 1 ] ;
V_182 &= V_183 -> V_65 ;
V_180 = F_115 ( V_182 ) ;
if ( NULL == V_183 -> V_179 ) {
V_183 -> V_179 = ( T_33 * * ) F_116 ( F_5 () , sizeof( T_33 * ) * V_184 ) ;
}
if ( NULL != ( V_61 = V_183 -> V_179 [ V_180 ] ) ) {
T_33 * V_185 ;
while ( V_61 -> V_181 ) {
if ( V_61 -> V_9 == V_182 ) {
return;
} else {
V_61 = V_61 -> V_181 ;
}
}
V_185 = F_4 ( F_5 () , T_33 ) ;
V_61 -> V_181 = V_185 ;
V_61 = V_185 ;
} else {
V_61 = V_183 -> V_179 [ V_180 ] = F_4 ( F_5 () , T_33 ) ;
}
V_61 -> V_181 = NULL ;
V_61 -> V_9 = V_182 ;
V_61 -> V_63 &= ~ V_64 ;
F_40 ( V_61 -> V_54 , V_54 , V_52 ) ;
V_176 = TRUE ;
}
static void
F_117 ( void )
{
T_9 * V_173 ;
T_1 V_5 ;
for( V_5 = 0 ; V_5 < V_175 ; ++ V_5 ) {
T_1 V_186 = V_5 + 1 ;
V_178 [ V_5 ] . V_179 = NULL ;
V_178 [ V_5 ] . V_71 = V_186 ;
V_178 [ V_5 ] . V_65 = F_118 ( F_119 ( V_186 ) ) ;
}
V_173 = F_33 ( V_187 , FALSE ) ;
if ( ! F_112 ( V_173 ) && V_188 != V_189 ) {
F_120 ( V_173 , V_188 , FALSE ) ;
}
F_21 ( V_173 ) ;
V_173 = F_32 ( V_187 ) ;
if ( ! F_112 ( V_173 ) && V_188 != V_189 ) {
F_120 ( V_173 , V_188 , FALSE ) ;
}
F_21 ( V_173 ) ;
}
void
F_121 ( T_34 * V_190 )
{
F_122 ( V_190 , L_26 ,
L_27 ,
L_28 ,
& V_89 . V_191 ) ;
F_122 ( V_190 , L_29 ,
L_30 ,
L_31 ,
& V_89 . V_192 ) ;
F_122 ( V_190 , L_32 ,
L_33 ,
L_34
L_35
L_36
L_37 ,
& V_89 . V_90 ) ;
F_122 ( V_190 , L_38 ,
L_39 ,
L_40 ,
& V_89 . V_193 ) ;
#ifdef F_47
F_122 ( V_190 , L_41 ,
L_42 ,
L_43
L_44
L_45
L_46 ,
& V_89 . V_91 ) ;
F_123 ( V_190 , L_47 ) ;
F_124 ( V_190 , L_48 ,
L_49 ,
L_50
L_51
L_52
L_53 ,
10 ,
& V_94 ) ;
#else
F_125 ( V_190 , L_41 ,
L_54 ,
L_55
L_56 ) ;
#endif
F_122 ( V_190 , L_57 ,
L_58 ,
L_59
L_60 ,
& V_89 . V_194 ) ;
F_122 ( V_190 , L_61 ,
L_62 ,
L_63
L_64
L_65
L_66
L_67 ,
& V_89 . V_195 ) ;
}
void
F_126 ( void ) {
V_89 . V_191 = FALSE ;
V_89 . V_90 = FALSE ;
V_89 . V_192 = FALSE ;
V_89 . V_193 = FALSE ;
V_89 . V_91 = FALSE ;
V_89 . V_195 = FALSE ;
}
T_3
F_127 ( void ) {
T_4 * V_79 ;
struct V_196 V_197 = { 0 , 0 } ;
int V_198 ;
T_35 V_199 , V_200 ;
T_3 V_201 = V_34 ;
T_36 * V_202 ;
V_34 = FALSE ;
if ( ! V_93 )
return V_201 ;
V_202 = F_128 ( V_13 ) ;
while ( V_202 != NULL && V_80 <= V_94 ) {
V_79 = ( T_4 * ) F_129 ( V_202 ) ;
F_130 ( V_13 , V_202 ) ;
if ( V_79 -> V_11 == V_83 ) {
F_131 ( V_203 , & V_79 -> V_9 . V_12 , sizeof( T_1 ) , V_83 ,
F_41 , V_79 ) ;
V_80 ++ ;
} else if ( V_79 -> V_11 == V_85 ) {
F_131 ( V_203 , & V_79 -> V_9 . V_72 , sizeof( struct V_8 ) ,
V_85 , F_41 , V_79 ) ;
V_80 ++ ;
}
V_202 = F_128 ( V_13 ) ;
}
F_132 ( & V_199 ) ;
F_132 ( & V_200 ) ;
V_198 = F_133 ( V_203 , & V_199 , & V_200 ) ;
if ( V_198 > 0 ) {
if ( F_134 ( V_198 , & V_199 , & V_200 , NULL , & V_197 ) == - 1 ) {
fprintf ( V_204 , L_68 , F_135 ( V_188 ) ) ;
return V_201 ;
}
F_136 ( V_203 , & V_199 , & V_200 ) ;
}
return V_201 ;
}
static void
F_137 ( void ) {
V_13 = NULL ;
if ( V_93 ) {
F_138 ( V_203 ) ;
F_138 ( V_205 ) ;
}
#ifdef F_139
F_140 () ;
#endif
V_93 = FALSE ;
}
T_3
F_127 ( void ) {
T_3 V_201 = V_34 ;
V_34 = FALSE ;
return V_201 ;
}
static void
F_137 ( void ) {
}
const T_9 *
F_141 ( const T_7 V_9 )
{
T_12 * V_61 = F_45 ( V_9 ) ;
if ( ! V_89 . V_90 )
return V_61 -> V_86 ;
V_61 -> V_63 |= V_168 ;
return V_61 -> V_54 ;
}
const T_9 *
F_142 ( const struct V_8 * V_9 )
{
T_15 * V_61 = F_50 ( V_9 ) ;
if ( ! V_89 . V_90 )
return V_61 -> V_72 ;
V_61 -> V_63 |= V_168 ;
return V_61 -> V_54 ;
}
void
F_42 ( const T_7 V_9 , const T_9 * V_54 )
{
T_12 * V_61 ;
if ( ! V_54 || V_54 [ 0 ] == '\0' )
return;
V_61 = ( T_12 * ) F_13 ( V_87 , F_46 ( V_9 ) ) ;
if ( ! V_61 ) {
V_61 = F_44 ( V_9 ) ;
F_15 ( V_87 , F_46 ( V_9 ) , V_61 ) ;
}
if ( F_143 ( V_61 -> V_54 , V_54 ) ) {
F_40 ( V_61 -> V_54 , V_54 , V_52 ) ;
V_34 = TRUE ;
}
V_61 -> V_63 |= V_92 | V_206 ;
}
void
F_43 ( const struct V_8 * V_207 , const T_9 * V_54 )
{
T_15 * V_61 ;
if ( ! V_54 || V_54 [ 0 ] == '\0' )
return;
V_61 = ( T_15 * ) F_13 ( V_96 , V_207 ) ;
if ( ! V_61 ) {
struct V_8 * V_97 ;
V_97 = F_4 ( F_5 () , struct V_8 ) ;
V_61 = F_48 ( V_207 ) ;
memcpy ( V_97 , V_207 , 16 ) ;
F_15 ( V_96 , V_97 , V_61 ) ;
}
if ( F_143 ( V_61 -> V_54 , V_54 ) ) {
F_40 ( V_61 -> V_54 , V_54 , V_52 ) ;
V_34 = TRUE ;
}
V_61 -> V_63 |= V_92 | V_206 ;
}
static void
F_144 ( V_14 V_208 , V_14 V_164 V_78 )
{
T_29 * V_159 = ( T_29 * ) V_208 ;
F_42 ( V_159 -> V_66 , V_159 -> V_54 ) ;
}
static void
F_145 ( V_14 V_208 , V_14 V_164 V_78 )
{
T_30 * V_160 = ( T_30 * ) V_208 ;
F_43 ( & ( V_160 -> V_153 ) , V_160 -> V_54 ) ;
}
static void
F_146 ( void )
{
if ( V_162 ) {
F_147 ( V_162 , F_144 , NULL ) ;
}
if ( V_161 ) {
F_147 ( V_161 , F_145 , NULL ) ;
}
}
void
F_148 ( void )
{
char * V_149 ;
T_7 V_5 ;
F_9 ( V_139 == NULL ) ;
V_139 = F_31 ( F_5 () , V_56 , V_57 ) ;
F_9 ( V_87 == NULL ) ;
V_87 = F_31 ( F_5 () , V_209 , V_210 ) ;
F_9 ( V_96 == NULL ) ;
V_96 = F_31 ( F_5 () , F_1 , F_2 ) ;
#ifdef F_47
F_9 ( V_13 == NULL ) ;
V_13 = F_149 ( F_5 () ) ;
#endif
if ( V_162 == NULL )
V_162 = F_149 ( F_5 () ) ;
if ( V_161 == NULL )
V_161 = F_149 ( F_5 () ) ;
if ( ! V_89 . V_194 ) {
V_149 = F_32 ( V_211 ) ;
if ( ! F_98 ( V_149 , TRUE ) && V_188 != V_189 ) {
F_120 ( V_149 , V_188 , FALSE ) ;
}
F_21 ( V_149 ) ;
}
V_149 = F_33 ( V_211 , TRUE ) ;
if ( ! F_98 ( V_149 , TRUE ) && V_188 != V_189 ) {
F_120 ( V_149 , V_188 , FALSE ) ;
}
F_21 ( V_149 ) ;
#ifdef F_47
#ifdef F_139
if ( F_150 ( V_212 ) == V_81 ) {
#endif
if ( F_151 ( & V_203 ) == V_81 && F_151 ( & V_205 ) == V_81 ) {
V_93 = TRUE ;
}
#ifdef F_139
}
#endif
#else
#endif
if ( V_158 && ! V_89 . V_194 ) {
for ( V_5 = 0 ; V_5 < V_158 -> V_2 ; V_5 ++ ) {
F_98 ( ( const char * ) F_103 ( V_158 , V_5 ) , TRUE ) ;
}
}
F_117 () ;
F_146 () ;
}
void
F_152 ( void )
{
T_1 V_5 , V_213 ;
T_33 * V_183 , * V_214 ;
F_137 () ;
V_139 = NULL ;
V_87 = NULL ;
V_96 = NULL ;
for( V_5 = 0 ; V_5 < V_175 ; ++ V_5 ) {
if ( V_178 [ V_5 ] . V_179 != NULL ) {
for ( V_213 = 0 ; V_213 < V_184 ; V_213 ++ ) {
for ( V_183 = V_178 [ V_5 ] . V_179 [ V_213 ] ;
V_183 != NULL ; V_183 = V_214 ) {
V_214 = V_183 -> V_181 ;
F_16 ( F_5 () , V_183 ) ;
}
}
F_16 ( F_5 () , V_178 [ V_5 ] . V_179 ) ;
V_178 [ V_5 ] . V_179 = NULL ;
}
}
V_176 = FALSE ;
V_34 = FALSE ;
}
void
F_153 ( void )
{
F_154 ( V_162 ) ;
V_162 = NULL ;
F_154 ( V_161 ) ;
V_161 = NULL ;
}
T_9 *
F_155 ( T_11 * V_50 , T_7 V_22 )
{
if ( ! V_89 . V_192 ) {
return F_24 ( V_50 , V_22 ) ;
}
return F_17 ( V_50 , F_28 ( V_28 , V_22 ) ) ;
}
T_9 *
F_156 ( T_11 * V_50 , T_7 V_22 )
{
if ( ! V_89 . V_192 ) {
return F_24 ( V_50 , V_22 ) ;
}
return F_17 ( V_50 , F_28 ( V_32 , V_22 ) ) ;
}
T_9 *
F_157 ( T_11 * V_50 , T_7 V_22 )
{
if ( ! V_89 . V_192 ) {
return F_24 ( V_50 , V_22 ) ;
}
return F_17 ( V_50 , F_28 ( V_26 , V_22 ) ) ;
}
T_9 *
F_158 ( T_11 * V_50 , T_7 V_22 )
{
if ( ! V_89 . V_192 ) {
return F_24 ( V_50 , V_22 ) ;
}
return F_17 ( V_50 , F_28 ( V_30 , V_22 ) ) ;
}
T_9 *
F_159 ( T_11 * V_215 , T_6 V_21 , T_7 V_22 )
{
const T_9 * V_216 ;
if ( ! V_89 . V_192 || ( V_21 == V_47 ) ) {
return F_29 ( V_215 , L_8 , V_22 ) ;
}
V_216 = F_28 ( V_21 , V_22 ) ;
F_9 ( V_216 ) ;
return F_29 ( V_215 , L_69 , V_216 , V_22 ) ;
}
int
F_160 ( T_9 * V_15 , T_37 V_217 , T_6 V_21 , T_7 V_22 )
{
const T_9 * V_216 ;
if ( ! V_89 . V_192 || ( V_21 == V_47 ) ) {
return F_38 ( V_15 , V_217 , L_8 , V_22 ) ;
}
V_216 = F_28 ( V_21 , V_22 ) ;
F_9 ( V_216 ) ;
return F_38 ( V_15 , V_217 , L_69 , V_216 , V_22 ) ;
}
const T_9 *
F_161 ( const V_70 * V_9 )
{
T_22 * V_61 ;
T_3 V_128 = V_89 . V_191 ;
V_61 = F_79 ( V_9 , V_128 ) ;
return V_128 ? V_61 -> V_110 : V_61 -> V_111 ;
}
const T_9 *
F_162 ( T_38 * V_218 , T_21 V_219 )
{
return F_161 ( F_163 ( V_218 , V_219 , 6 ) ) ;
}
const T_9 *
F_164 ( const V_70 * V_9 )
{
T_22 * V_61 ;
if ( ! V_89 . V_191 )
return NULL ;
V_61 = F_79 ( V_9 , TRUE ) ;
F_9 ( V_61 != NULL ) ;
if ( V_61 -> V_74 == V_108 ) {
return V_61 -> V_110 ;
}
else {
return NULL ;
}
}
V_70 *
F_165 ( const T_9 * V_54 )
{
return F_80 ( V_54 ) ;
}
void
F_166 ( const T_7 V_86 , const V_70 * V_98 )
{
T_12 * V_61 ;
if ( ! V_89 . V_90 )
return;
V_61 = F_45 ( V_86 ) ;
if ( V_61 -> V_63 & V_206 ) {
F_63 ( V_98 , V_61 -> V_54 ) ;
}
}
T_9 *
F_167 ( T_11 * V_50 , const T_1 V_220 , const char V_221 )
{
T_9 * V_15 = ( T_9 * ) F_8 ( V_50 , 12 ) ;
* F_168 ( V_15 , V_220 , V_221 ) = '\0' ;
return V_15 ;
}
T_9 *
F_169 ( T_11 * V_50 , const T_1 V_9 )
{
if ( ! V_89 . V_90 ) {
return F_167 ( V_50 , V_9 , '\0' ) ;
}
return F_88 ( V_50 , V_9 ) ;
}
T_1
F_170 ( const T_9 * V_54 , T_3 * V_222 )
{
T_1 V_9 ;
T_3 V_140 ;
V_9 = F_89 ( V_54 , & V_140 ) ;
* V_222 = V_140 ;
return V_9 ;
}
T_9 *
F_171 ( T_11 * V_50 , const T_27 V_142 )
{
if ( ! V_89 . V_195 ) {
return NULL ;
}
return F_17 ( V_50 , F_97 ( V_142 ) ) ;
}
const T_9 *
F_172 ( const V_70 * V_9 )
{
T_19 * V_106 ;
V_106 = F_64 ( V_9 ) ;
if ( V_89 . V_191 && V_106 -> V_74 != V_109 )
return V_106 -> V_110 ;
return V_106 -> V_111 ;
}
const T_9 *
F_173 ( const T_7 V_223 )
{
V_70 V_9 [ 3 ] ;
V_9 [ 0 ] = ( V_223 >> 16 ) & 0xFF ;
V_9 [ 1 ] = ( V_223 >> 8 ) & 0xFF ;
V_9 [ 2 ] = ( V_223 >> 0 ) & 0xFF ;
return F_172 ( V_9 ) ;
}
const T_9 *
F_174 ( T_38 * V_218 , T_21 V_219 )
{
return F_172 ( F_163 ( V_218 , V_219 , 3 ) ) ;
}
const T_9 *
F_175 ( const V_70 * V_9 )
{
T_19 * V_106 ;
int V_105 ;
V_70 V_115 ;
V_105 = V_9 [ 0 ] ;
V_105 = V_105 << 8 ;
V_115 = V_9 [ 1 ] ;
V_105 = V_105 | V_115 ;
V_105 = V_105 << 8 ;
V_115 = V_9 [ 2 ] ;
V_105 = V_105 | V_115 ;
V_106 = ( T_19 * ) F_13 ( V_112 , & V_105 ) ;
if ( ( V_106 == NULL ) || ( V_106 -> V_74 != V_109 ) ) {
return NULL ;
}
return V_106 -> V_110 ;
}
const T_9 *
F_176 ( const T_7 V_105 )
{
T_19 * V_106 ;
V_106 = ( T_19 * ) F_13 ( V_112 , & V_105 ) ;
if ( ( V_106 == NULL ) || ( V_106 -> V_74 != V_109 ) ) {
return NULL ;
}
return V_106 -> V_110 ;
}
const T_9 *
F_177 ( T_38 * V_218 , T_21 V_219 )
{
return F_175 ( F_163 ( V_218 , V_219 , 3 ) ) ;
}
char * F_178 ( T_19 * V_224 )
{
return V_224 -> V_110 ;
}
T_9 *
F_179 ( T_11 * V_50 , const T_39 V_225 )
{
V_70 * V_9 = ( V_70 * ) F_8 ( NULL , 8 ) ;
T_19 * V_106 ;
T_9 * V_226 ;
* ( T_39 * ) ( void * ) ( V_9 ) = F_180 ( & ( V_225 ) ) ;
V_106 = F_64 ( V_9 ) ;
if ( ! V_89 . V_191 || ( V_106 -> V_74 == V_109 ) ) {
V_226 = F_29 ( V_50 , L_70 , V_9 [ 0 ] , V_9 [ 1 ] , V_9 [ 2 ] , V_9 [ 3 ] , V_9 [ 4 ] , V_9 [ 5 ] , V_9 [ 6 ] , V_9 [ 7 ] ) ;
} else {
V_226 = F_29 ( V_50 , L_15 , V_106 -> V_110 , V_9 [ 3 ] , V_9 [ 4 ] , V_9 [ 5 ] , V_9 [ 6 ] , V_9 [ 7 ] ) ;
}
F_16 ( NULL , V_9 ) ;
return V_226 ;
}
static void
F_181 (
void * V_73 ,
int V_74 ,
#if ( ( V_75 < 1 ) \
|| ( 1 == V_75 && V_76 < 5 ) )
struct V_77 * T_40
#else
int T_17 V_78 ,
struct V_77 * T_40
#endif
) {
T_41 * V_227 = ( T_41 * ) V_73 ;
if ( V_74 == V_81 && T_40 && V_227 && T_40 -> V_228 == V_227 -> V_229 ) {
memcpy ( V_227 -> V_207 , T_40 -> V_230 , T_40 -> V_228 ) ;
V_227 -> V_231 = T_40 -> V_228 ;
}
}
T_3
F_182 ( const char * V_232 , T_1 * V_207 )
{
struct V_233 V_234 ;
#ifdef F_47
struct V_196 V_197 = { 0 , V_235 } , * V_236 ;
int V_198 ;
T_35 V_199 , V_200 ;
T_41 V_237 ;
#endif
if ( ! F_183 ( V_232 , & V_234 ) ) {
if ( ! V_89 . V_90 ||
! V_89 . V_91 ) {
return FALSE ;
}
#ifdef F_47
if ( ! V_93 || V_94 < 1 ) {
return FALSE ;
}
V_237 . V_229 = ( int ) sizeof ( struct V_233 ) ;
V_237 . V_231 = 0 ;
V_237 . V_207 = V_207 ;
F_184 ( V_205 , V_232 , V_83 , F_181 , & V_237 ) ;
F_132 ( & V_199 ) ;
F_132 ( & V_200 ) ;
V_198 = F_133 ( V_205 , & V_199 , & V_200 ) ;
if ( V_198 > 0 ) {
V_236 = F_185 ( V_205 , & V_197 , & V_197 ) ;
if ( F_134 ( V_198 , & V_199 , & V_200 , NULL , V_236 ) == - 1 ) {
fprintf ( V_204 , L_68 , F_135 ( V_188 ) ) ;
return FALSE ;
}
F_136 ( V_205 , & V_199 , & V_200 ) ;
}
F_186 ( V_205 ) ;
if ( V_237 . V_229 == V_237 . V_231 ) {
return TRUE ;
}
return FALSE ;
#endif
} else {
unsigned int V_130 , V_131 , V_132 , V_133 ;
if ( sscanf ( V_232 , L_71 , & V_130 , & V_131 , & V_132 , & V_133 ) != 4 )
return FALSE ;
}
* V_207 = V_234 . V_238 ;
return TRUE ;
}
T_3
F_187 ( const char * V_232 , struct V_8 * V_207 )
{
#ifdef F_47
struct V_196 V_197 = { 0 , V_235 } , * V_236 ;
int V_198 ;
T_35 V_199 , V_200 ;
T_41 V_237 ;
#endif
if ( F_188 ( V_232 , V_207 ) )
return TRUE ;
if ( ! V_89 . V_90 ||
! V_89 . V_91 ) {
return FALSE ;
}
#ifdef F_47
if ( ! V_93 || V_94 < 1 ) {
return FALSE ;
}
V_237 . V_229 = ( int ) sizeof ( struct V_8 ) ;
V_237 . V_231 = 0 ;
V_237 . V_207 = V_207 ;
F_184 ( V_205 , V_232 , V_85 , F_181 , & V_237 ) ;
F_132 ( & V_199 ) ;
F_132 ( & V_200 ) ;
V_198 = F_133 ( V_205 , & V_199 , & V_200 ) ;
if ( V_198 > 0 ) {
V_236 = F_185 ( V_205 , & V_197 , & V_197 ) ;
if ( F_134 ( V_198 , & V_199 , & V_200 , NULL , V_236 ) == - 1 ) {
fprintf ( V_204 , L_68 , F_135 ( V_188 ) ) ;
return FALSE ;
}
F_136 ( V_205 , & V_199 , & V_200 ) ;
}
F_186 ( V_205 ) ;
if ( V_237 . V_229 == V_237 . V_231 ) {
return TRUE ;
}
#endif
return FALSE ;
}
T_42 *
F_189 ( void )
{
return V_112 ;
}
T_42 *
F_190 ( void )
{
return V_114 ;
}
T_42 *
F_191 ( void )
{
return V_121 ;
}
T_42 *
F_192 ( void )
{
return V_25 ;
}
T_42 *
F_193 ( void )
{
return V_139 ;
}
T_42 *
F_194 ( void )
{
return V_147 ;
}
T_42 *
F_195 ( void )
{
return V_87 ;
}
T_42 *
F_196 ( void )
{
return V_96 ;
}
void
F_197 ( void )
{
F_30 () ;
F_72 () ;
F_86 () ;
F_95 () ;
}
void
F_198 ( void )
{
F_96 () ;
F_34 () ;
F_87 () ;
}
T_3
F_113 ( const char * V_239 , void * V_240 )
{
return F_100 ( V_239 , ( T_1 * ) V_240 ) ;
}
T_3
F_188 ( const char * V_239 , void * V_240 )
{
return F_99 ( V_239 , (struct V_8 * ) V_240 ) ;
}
