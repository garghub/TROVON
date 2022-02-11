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
if ( V_43 != F_19 ( NULL , & V_37 , V_22 , V_38 ) ) {
F_16 ( NULL , V_37 ) ;
return;
}
V_44 = V_36 ;
V_45 = V_21 ;
F_20 ( V_37 , V_46 ) ;
F_16 ( NULL , V_37 ) ;
V_45 = V_47 ;
}
static void
V_46 ( const T_1 V_22 )
{
if ( V_22 ) {
F_12 ( V_45 , V_22 , V_44 ) ;
}
}
static T_3
F_21 ( const char * V_48 )
{
T_5 * V_49 ;
static int V_16 = 0 ;
static char * V_15 = NULL ;
V_49 = F_22 ( V_48 , L_7 ) ;
if ( V_49 == NULL )
return FALSE ;
while ( F_7 ( & V_15 , & V_16 , V_49 ) >= 0 ) {
F_18 ( V_15 ) ;
}
fclose ( V_49 ) ;
return TRUE ;
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
V_24 = F_14 ( F_5 () , T_8 ) ;
F_15 ( V_25 , V_1 , V_24 ) ;
}
if ( V_24 -> V_55 == NULL ) {
V_24 -> V_55 = F_28 ( F_5 () , L_8 , V_22 ) ;
}
return V_24 -> V_55 ;
}
static void
F_29 ( void )
{
T_3 V_56 = TRUE ;
F_9 ( V_25 == NULL ) ;
V_25 = F_30 ( F_5 () , V_57 , V_58 ) ;
if ( V_59 == NULL ) {
V_59 = F_31 ( V_60 ) ;
}
F_21 ( V_59 ) ;
if ( V_61 == NULL ) {
V_61 = F_32 ( V_60 , TRUE ) ;
if ( ! F_21 ( V_61 ) ) {
F_33 ( V_61 ) ;
V_61 = F_32 ( V_60 , FALSE ) ;
} else {
V_56 = FALSE ;
}
}
if ( V_56 ) {
F_21 ( V_61 ) ;
}
}
static void
F_34 ( void )
{
V_25 = NULL ;
F_33 ( V_59 ) ;
V_59 = NULL ;
F_33 ( V_61 ) ;
V_61 = NULL ;
}
static void
F_35 ( const T_7 V_9 , T_12 * volatile V_62 )
{
T_13 V_63 ;
if ( V_62 -> V_64 & V_65 )
return;
V_62 -> V_64 |= V_65 ;
V_63 = F_36 ( V_9 ) ;
if ( 0 != V_63 . V_66 ) {
T_1 V_67 ;
T_9 V_68 [ V_69 ] ;
T_9 * V_70 ;
T_14 V_5 ;
V_67 = V_9 & ( ~ ( T_1 ) V_63 . V_66 ) ;
F_37 ( ( V_71 * ) & V_67 , V_68 , V_69 ) ;
V_70 = V_68 ;
V_5 = V_63 . V_72 / 8 ;
while( * ( V_70 ) != '\0' && V_5 > 0 ) {
if ( * ( ++ V_70 ) == '.' ) {
-- V_5 ;
}
}
F_38 ( V_62 -> V_54 , V_52 , L_9 , V_63 . V_54 , V_70 ) ;
} else {
F_37 ( ( const V_71 * ) & V_9 , V_62 -> V_54 , V_52 ) ;
}
}
static void
F_39 ( T_15 * volatile V_62 )
{
if ( V_62 -> V_64 & V_65 )
return;
V_62 -> V_64 |= V_65 ;
F_40 ( V_62 -> V_54 , V_62 -> V_73 , V_52 ) ;
}
static void
F_41 (
void * V_74 ,
int V_75 ,
#if ( ( V_76 < 1 ) \
|| ( 1 == V_76 && V_77 < 5 ) )
struct V_78 * T_16
#else
int T_17 V_79 ,
struct V_78 * T_16
#endif
) {
T_4 * V_80 = ( T_4 * ) V_74 ;
char * * V_3 ;
if ( ! V_80 ) return;
V_81 -- ;
if ( V_75 == V_82 ) {
for ( V_3 = T_16 -> V_83 ; * V_3 != NULL ; V_3 ++ ) {
switch( V_80 -> V_11 ) {
case V_84 :
F_42 ( V_80 -> V_9 . V_12 , T_16 -> V_85 ) ;
break;
case V_86 :
F_43 ( & V_80 -> V_9 . V_73 , T_16 -> V_85 ) ;
break;
default:
break;
}
}
}
F_16 ( F_5 () , V_80 ) ;
}
static T_12 *
F_44 ( const T_7 V_9 )
{
T_12 * V_62 = F_4 ( F_5 () , T_12 ) ;
V_62 -> V_9 = V_9 ;
V_62 -> V_64 = 0 ;
V_62 -> V_54 [ 0 ] = '\0' ;
F_37 ( ( const V_71 * ) & V_9 , V_62 -> V_87 , sizeof( V_62 -> V_87 ) ) ;
return V_62 ;
}
static T_12 *
F_45 ( const T_7 V_9 )
{
T_12 * volatile V_62 ;
V_62 = ( T_12 * ) F_13 ( V_88 , F_46 ( V_9 ) ) ;
if ( V_62 == NULL ) {
V_62 = F_44 ( V_9 ) ;
F_15 ( V_88 , F_46 ( V_9 ) , V_62 ) ;
} else if ( ( V_62 -> V_64 & V_89 ) != V_65 ) {
return V_62 ;
}
F_35 ( V_9 , V_62 ) ;
if ( ! V_90 . V_91 )
return V_62 ;
if ( V_90 . V_92 ) {
V_62 -> V_64 |= V_93 ;
#ifdef F_47
if ( V_94 && V_95 > 0 ) {
F_3 ( V_84 , V_9 ) ;
}
#endif
}
return V_62 ;
}
static T_15 *
F_48 ( const struct V_8 * V_9 )
{
T_15 * V_62 = F_4 ( F_5 () , T_15 ) ;
memcpy ( V_62 -> V_9 , V_9 -> V_96 , sizeof V_62 -> V_9 ) ;
V_62 -> V_64 = 0 ;
V_62 -> V_54 [ 0 ] = '\0' ;
F_49 ( V_9 , V_62 -> V_73 , sizeof( V_62 -> V_73 ) ) ;
return V_62 ;
}
static T_15 *
F_50 ( const struct V_8 * V_9 )
{
T_15 * volatile V_62 ;
#ifdef F_47
T_4 * V_80 ;
#endif
V_62 = ( T_15 * ) F_13 ( V_97 , V_9 ) ;
if ( V_62 == NULL ) {
struct V_8 * V_98 ;
V_98 = F_4 ( F_5 () , struct V_8 ) ;
V_62 = F_48 ( V_9 ) ;
memcpy ( V_98 , V_9 , 16 ) ;
F_15 ( V_97 , V_98 , V_62 ) ;
} else if ( ( V_62 -> V_64 & V_89 ) != V_65 ) {
return V_62 ;
}
F_39 ( V_62 ) ;
if ( ! V_90 . V_91 )
return V_62 ;
if ( V_90 . V_92 ) {
V_62 -> V_64 |= V_93 ;
#ifdef F_47
if ( V_94 && V_95 > 0 ) {
V_80 = F_4 ( F_5 () , T_4 ) ;
V_80 -> V_11 = V_86 ;
memcpy ( & V_80 -> V_9 . V_73 , V_9 , sizeof( V_80 -> V_9 . V_73 ) ) ;
F_6 ( V_13 , ( V_14 ) V_80 ) ;
}
#endif
}
return V_62 ;
}
static T_3
F_51 ( const char * V_35 , T_18 * V_99 , unsigned int * V_66 ,
const T_3 V_100 )
{
int V_5 ;
unsigned long V_101 ;
char * V_3 ;
char V_102 = '\0' ;
for ( V_5 = 0 ; V_5 < 6 ; V_5 ++ ) {
if ( ! F_52 ( * V_35 ) )
return FALSE ;
V_101 = strtoul ( V_35 , & V_3 , 16 ) ;
if ( V_3 == V_35 )
return FALSE ;
if ( V_101 > 0xFF )
return FALSE ;
V_99 -> V_9 [ V_5 ] = ( V_71 ) V_101 ;
V_35 = V_3 ;
if ( * V_35 == '/' ) {
if ( ! V_100 ) {
return FALSE ;
}
V_35 ++ ;
if ( ! F_53 ( * V_35 ) )
return FALSE ;
V_101 = strtoul ( V_35 , & V_3 , 10 ) ;
if ( V_3 == V_35 )
return FALSE ;
V_35 = V_3 ;
if ( * V_35 != '\0' && ! F_54 ( * V_35 ) )
return FALSE ;
if ( V_101 == 0 || V_101 >= 48 )
return FALSE ;
* V_66 = ( int ) V_101 ;
for ( V_5 = 0 ; V_101 >= 8 ; V_5 ++ , V_101 -= 8 )
;
V_99 -> V_9 [ V_5 ] &= ( 0xFF << ( 8 - V_101 ) ) ;
V_5 ++ ;
for (; V_5 < 6 ; V_5 ++ )
V_99 -> V_9 [ V_5 ] = 0 ;
return TRUE ;
}
if ( * V_35 == '\0' ) {
if ( V_5 == 2 ) {
if ( ! V_100 ) {
return FALSE ;
}
* V_66 = 0 ;
return TRUE ;
}
if ( V_5 == 5 ) {
if ( V_100 )
* V_66 = 48 ;
return TRUE ;
}
return FALSE ;
} else {
if ( V_102 == '\0' ) {
if ( * V_35 != ':' && * V_35 != '-' && * V_35 != '.' )
return FALSE ;
V_102 = * V_35 ;
} else {
if ( * V_35 != V_102 )
return FALSE ;
}
}
V_35 ++ ;
}
return TRUE ;
}
static int
F_55 ( char * line , T_18 * V_99 , unsigned int * V_66 ,
const T_3 V_100 )
{
T_9 * V_35 ;
if ( ( V_35 = strchr ( line , '#' ) ) )
* V_35 = '\0' ;
if ( ( V_35 = strtok ( line , L_1 ) ) == NULL )
return - 1 ;
if ( ! F_51 ( V_35 , V_99 , V_66 , V_100 ) )
return - 1 ;
if ( ( V_35 = strtok ( NULL , L_1 ) ) == NULL )
return - 1 ;
F_40 ( V_99 -> V_54 , V_35 , V_52 ) ;
return 0 ;
}
static void
F_56 ( char * V_48 )
{
if ( V_103 )
rewind ( V_103 ) ;
else
V_103 = F_22 ( V_48 , L_7 ) ;
}
static void
F_57 ( void )
{
if ( V_103 ) {
fclose ( V_103 ) ;
V_103 = NULL ;
}
}
static T_18 *
F_58 ( unsigned int * V_66 , const T_3 V_100 )
{
static T_18 V_99 ;
static int V_16 = 0 ;
static char * V_15 = NULL ;
if ( V_103 == NULL )
return NULL ;
while ( F_7 ( & V_15 , & V_16 , V_103 ) >= 0 ) {
if ( F_55 ( V_15 , & V_99 , V_66 , V_100 ) == 0 ) {
return & V_99 ;
}
}
return NULL ;
}
static T_18 *
F_59 ( const V_71 * V_9 )
{
T_18 * V_99 ;
F_56 ( V_104 ) ;
while ( ( ( V_99 = F_58 ( NULL , FALSE ) ) != NULL ) && memcmp ( V_9 , V_99 -> V_9 , 6 ) != 0 )
;
if ( V_99 == NULL ) {
F_57 () ;
F_56 ( V_105 ) ;
while ( ( ( V_99 = F_58 ( NULL , FALSE ) ) != NULL ) && memcmp ( V_9 , V_99 -> V_9 , 6 ) != 0 )
;
F_57 () ;
}
return V_99 ;
}
static T_19 *
F_60 ( const V_71 * V_9 , char * V_54 )
{
int * V_106 ;
T_19 * V_107 ;
char * V_108 ;
V_106 = ( int * ) F_4 ( F_5 () , int ) ;
* V_106 = ( int ) ( ( V_9 [ 0 ] << 16 ) + ( V_9 [ 1 ] << 8 ) + V_9 [ 2 ] ) ;
V_107 = F_4 ( F_5 () , T_19 ) ;
memcpy ( V_107 -> V_9 , V_9 , 3 ) ;
if ( V_54 != NULL ) {
F_40 ( V_107 -> V_109 , V_54 , V_52 ) ;
V_107 -> V_75 = V_110 ;
}
else {
V_107 -> V_75 = V_111 ;
V_107 -> V_109 [ 0 ] = '\0' ;
}
V_108 = F_61 ( V_107 -> V_112 , V_9 , sizeof( V_107 -> V_9 ) , ':' ) ;
* V_108 = '\0' ;
F_15 ( V_113 , V_106 , V_107 ) ;
return V_107 ;
}
static void
F_62 ( const V_71 * V_9 , char * V_54 )
{
V_71 * V_114 ;
V_114 = ( V_71 * ) F_8 ( F_5 () , 6 ) ;
memcpy ( V_114 , V_9 , 6 ) ;
F_15 ( V_115 , V_114 , F_17 ( F_5 () , V_54 ) ) ;
}
static void
F_63 ( const V_71 * V_9 , unsigned int V_66 , T_9 * V_54 )
{
switch ( V_66 )
{
case 0 :
F_60 ( V_9 , V_54 ) ;
break;
case 48 :
F_64 ( V_9 , V_54 ) ;
break;
default:
F_62 ( V_9 , V_54 ) ;
break;
}
}
static T_19 *
F_65 ( const V_71 * V_9 )
{
T_20 V_106 = 0 ;
V_71 V_116 ;
T_19 * V_107 ;
V_106 = V_9 [ 0 ] ;
V_106 = V_106 << 8 ;
V_116 = V_9 [ 1 ] ;
V_106 = V_106 | V_116 ;
V_106 = V_106 << 8 ;
V_116 = V_9 [ 2 ] ;
V_106 = V_106 | V_116 ;
V_107 = ( T_19 * ) F_13 ( V_113 , & V_106 ) ;
if ( V_107 != NULL ) {
return V_107 ;
}
if ( ( V_106 & 0x00010000 ) != 0 ) {
V_106 &= 0x00FEFFFF ;
V_107 = ( T_19 * ) F_13 ( V_113 , & V_106 ) ;
if ( V_107 != NULL ) {
return V_107 ;
}
}
return F_60 ( V_9 , NULL ) ;
}
static T_9 *
F_66 ( const V_71 * V_9 , const unsigned int V_66 )
{
V_71 V_117 [ 6 ] ;
T_7 V_101 ;
T_21 V_5 ;
T_9 * V_54 ;
if ( V_115 == NULL ) {
return NULL ;
}
for ( V_5 = 0 , V_101 = V_66 ; V_101 >= 8 ; V_5 ++ , V_101 -= 8 )
V_117 [ V_5 ] = V_9 [ V_5 ] ;
V_117 [ V_5 ] = V_9 [ V_5 ] & ( 0xFF << ( 8 - V_101 ) ) ;
V_5 ++ ;
for (; V_5 < 6 ; V_5 ++ )
V_117 [ V_5 ] = 0 ;
V_54 = ( T_9 * ) F_13 ( V_115 , V_117 ) ;
return V_54 ;
}
T_7 F_67 ( T_22 * V_118 )
{
return V_118 -> V_75 ;
}
char * F_68 ( T_22 * V_118 )
{
return V_118 -> V_112 ;
}
char * F_69 ( T_22 * V_118 )
{
return V_118 -> V_109 ;
}
static T_7
F_70 ( T_2 V_1 )
{
return F_71 ( ( const V_71 * ) V_1 , 6 ) ;
}
static T_3
F_72 ( T_2 V_119 , T_2 V_120 )
{
return ( memcmp ( V_119 , V_120 , 6 ) == 0 ) ;
}
static void
F_73 ( void )
{
T_18 * V_99 ;
char * V_121 ;
T_7 V_66 = 0 ;
V_115 = F_30 ( F_5 () , F_70 , F_72 ) ;
V_113 = F_30 ( F_5 () , V_57 , V_58 ) ;
V_122 = F_30 ( F_5 () , F_70 , F_72 ) ;
if ( V_105 == NULL ) {
V_105 = F_28 ( F_5 () , L_10 V_123 L_10 ,
F_74 () , V_124 ) ;
}
if ( V_104 == NULL )
V_104 = F_32 ( V_124 , FALSE ) ;
V_121 = F_31 ( V_125 ) ;
F_56 ( V_121 ) ;
while ( ( V_99 = F_58 ( & V_66 , TRUE ) ) ) {
F_63 ( V_99 -> V_9 , V_66 , V_99 -> V_54 ) ;
}
F_57 () ;
F_33 ( V_121 ) ;
}
static void
F_75 ( void )
{
F_33 ( V_104 ) ;
V_104 = NULL ;
}
static T_22 *
F_76 ( T_22 * V_62 ) {
T_18 * V_99 ;
T_19 * V_107 ;
const V_71 * V_9 = V_62 -> V_9 ;
if ( ( V_99 = F_59 ( V_9 ) ) != NULL ) {
F_40 ( V_62 -> V_109 , V_99 -> V_54 , V_52 ) ;
V_62 -> V_75 = V_110 ;
return V_62 ;
} else {
T_7 V_66 ;
T_9 * V_54 ;
T_23 V_126 ;
V_66 = 7 ;
do {
if ( ( V_54 = F_66 ( V_9 , V_66 + 40 ) ) != NULL ) {
F_38 ( V_62 -> V_109 , V_52 , L_11 ,
V_54 , V_9 [ 5 ] & ( 0xFF >> V_66 ) ) ;
V_62 -> V_75 = V_127 ;
return V_62 ;
}
} while ( V_66 -- );
V_66 = 7 ;
do {
if ( ( V_54 = F_66 ( V_9 , V_66 + 32 ) ) != NULL ) {
F_38 ( V_62 -> V_109 , V_52 , L_12 ,
V_54 , V_9 [ 4 ] & ( 0xFF >> V_66 ) , V_9 [ 5 ] ) ;
V_62 -> V_75 = V_127 ;
return V_62 ;
}
} while ( V_66 -- );
V_66 = 7 ;
do {
if ( ( V_54 = F_66 ( V_9 , V_66 + 24 ) ) != NULL ) {
F_38 ( V_62 -> V_109 , V_52 , L_13 ,
V_54 , V_9 [ 3 ] & ( 0xFF >> V_66 ) , V_9 [ 4 ] , V_9 [ 5 ] ) ;
V_62 -> V_75 = V_127 ;
return V_62 ;
}
} while ( V_66 -- );
V_107 = F_65 ( V_9 ) ;
if ( ( V_107 != NULL ) && ( V_107 -> V_75 != V_111 ) ) {
F_38 ( V_62 -> V_109 , V_52 , L_13 ,
V_107 -> V_109 , V_9 [ 3 ] , V_9 [ 4 ] , V_9 [ 5 ] ) ;
V_62 -> V_75 = V_127 ;
return V_62 ;
}
V_66 = 7 ;
do {
if ( ( V_54 = F_66 ( V_9 , V_66 + 16 ) ) != NULL ) {
F_38 ( V_62 -> V_109 , V_52 , L_14 ,
V_54 , V_9 [ 2 ] & ( 0xFF >> V_66 ) , V_9 [ 3 ] , V_9 [ 4 ] ,
V_9 [ 5 ] ) ;
V_62 -> V_75 = V_127 ;
return V_62 ;
}
} while ( V_66 -- );
V_66 = 7 ;
do {
if ( ( V_54 = F_66 ( V_9 , V_66 + 8 ) ) != NULL ) {
F_38 ( V_62 -> V_109 , V_52 , L_15 ,
V_54 , V_9 [ 1 ] & ( 0xFF >> V_66 ) , V_9 [ 2 ] , V_9 [ 3 ] ,
V_9 [ 4 ] , V_9 [ 5 ] ) ;
V_62 -> V_75 = V_127 ;
return V_62 ;
}
} while ( V_66 -- );
V_66 = 7 ;
do {
if ( ( V_54 = F_66 ( V_9 , V_66 ) ) != NULL ) {
F_38 ( V_62 -> V_109 , V_52 , L_16 ,
V_54 , V_9 [ 0 ] & ( 0xFF >> V_66 ) , V_9 [ 1 ] , V_9 [ 2 ] ,
V_9 [ 3 ] , V_9 [ 4 ] , V_9 [ 5 ] ) ;
V_62 -> V_75 = V_127 ;
return V_62 ;
}
} while ( -- V_66 );
F_77 ( & V_126 , V_128 , 6 , V_9 ) ;
F_78 ( & V_126 , V_62 -> V_109 , V_52 ) ;
V_62 -> V_75 = V_127 ;
return V_62 ;
}
F_79 () ;
}
static T_22 *
F_80 ( const V_71 * V_9 , const T_3 V_129 )
{
T_22 * V_62 ;
char * V_108 ;
V_62 = F_4 ( F_5 () , T_22 ) ;
memcpy ( V_62 -> V_9 , V_9 , sizeof( V_62 -> V_9 ) ) ;
V_62 -> V_75 = V_111 ;
V_108 = F_61 ( V_62 -> V_112 , V_9 , sizeof( V_62 -> V_9 ) , ':' ) ;
* V_108 = '\0' ;
V_62 -> V_109 [ 0 ] = '\0' ;
if ( V_129 )
F_76 ( V_62 ) ;
F_15 ( V_122 , V_62 -> V_9 , V_62 ) ;
return V_62 ;
}
static T_22 *
F_64 ( const V_71 * V_9 , const T_9 * V_54 )
{
T_22 * V_62 ;
V_62 = ( T_22 * ) F_13 ( V_122 , V_9 ) ;
if ( V_62 == NULL ) {
V_62 = F_80 ( V_9 , FALSE ) ;
}
if ( strcmp ( V_62 -> V_109 , V_54 ) != 0 ) {
F_40 ( V_62 -> V_109 , V_54 , V_52 ) ;
V_62 -> V_75 = V_110 ;
V_34 = TRUE ;
}
return V_62 ;
}
static T_22 *
F_81 ( const V_71 * V_9 , const T_3 V_129 )
{
T_22 * V_62 ;
V_62 = ( T_22 * ) F_13 ( V_122 , V_9 ) ;
if ( V_62 == NULL ) {
V_62 = F_80 ( V_9 , V_129 ) ;
} else {
if ( V_129 && ( V_62 -> V_75 == V_111 ) ) {
F_76 ( V_62 ) ;
}
}
return V_62 ;
}
static V_71 *
F_82 ( const T_9 * V_54 V_79 )
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
F_83 ( char * line , T_24 * V_130 )
{
T_9 * V_35 ;
T_1 V_119 , V_131 , V_132 , V_133 , V_134 ;
T_3 V_135 = FALSE ;
if ( ( V_35 = strchr ( line , '#' ) ) )
* V_35 = '\0' ;
if ( ( V_35 = strtok ( line , L_17 ) ) == NULL )
return - 1 ;
if ( sscanf ( V_35 , L_18 , & V_131 , & V_132 , & V_133 , & V_134 ) != 4 ) {
if ( sscanf ( V_35 , L_19 , & V_131 , & V_132 , & V_133 , & V_134 ) != 4 ) {
if ( sscanf ( V_35 , L_20 , & V_131 , & V_132 , & V_133 , & V_134 ) != 4 ) {
if ( sscanf ( V_35 , L_21 , & V_119 ) == 1 ) {
V_135 = TRUE ;
}
else {
return - 1 ;
}
}
}
}
if ( ( V_35 = strtok ( NULL , L_17 ) ) == NULL )
return - 1 ;
if ( V_135 ) {
V_130 -> V_9 = V_119 ;
}
else {
V_130 -> V_9 = ( V_131 << 24 ) | ( V_132 << 16 ) | ( V_133 << 8 ) | V_134 ;
}
F_40 ( V_130 -> V_54 , V_35 , V_52 ) ;
return 0 ;
}
static void
F_84 ( char * V_48 )
{
if ( V_136 )
rewind ( V_136 ) ;
else
V_136 = F_22 ( V_48 , L_7 ) ;
}
static void
F_85 ( void )
{
if ( V_136 ) {
fclose ( V_136 ) ;
V_136 = NULL ;
}
}
static T_24 *
F_86 ( void )
{
static T_24 V_130 ;
static int V_16 = 0 ;
static char * V_15 = NULL ;
if ( V_136 == NULL )
return NULL ;
while ( F_7 ( & V_15 , & V_16 , V_136 ) >= 0 ) {
if ( F_83 ( V_15 , & V_130 ) == 0 ) {
return & V_130 ;
}
}
return NULL ;
}
static T_24 *
F_87 ( T_1 V_9 )
{
T_24 * V_130 ;
F_84 ( V_137 ) ;
while ( ( ( V_130 = F_86 () ) != NULL ) && ( V_9 != V_130 -> V_9 ) ) ;
if ( V_130 == NULL ) {
F_85 () ;
F_84 ( V_138 ) ;
while ( ( ( V_130 = F_86 () ) != NULL ) && ( V_9 != V_130 -> V_9 ) )
;
F_85 () ;
}
return V_130 ;
}
static void
F_88 ( void )
{
if ( V_137 == NULL ) {
V_137 = F_28 ( F_5 () , L_10 V_123 L_10 ,
F_74 () , V_139 ) ;
}
if ( V_138 == NULL )
V_138 = F_32 ( V_139 , FALSE ) ;
}
static void
F_89 ( void )
{
V_140 = NULL ;
F_33 ( V_138 ) ;
V_138 = NULL ;
}
static T_9 *
F_90 ( T_11 * V_50 , const T_7 V_9 )
{
T_25 * V_62 ;
T_24 * V_130 ;
V_62 = ( T_25 * ) F_13 ( V_140 , & V_9 ) ;
if ( V_62 == NULL ) {
int * V_1 ;
V_1 = ( int * ) F_4 ( F_5 () , int ) ;
* V_1 = V_9 ;
V_62 = F_4 ( F_5 () , T_25 ) ;
F_15 ( V_140 , V_1 , V_62 ) ;
} else {
return F_17 ( V_50 , V_62 -> V_54 ) ;
}
V_62 -> V_9 = V_9 ;
if ( ( V_130 = F_87 ( V_9 ) ) == NULL ) {
F_38 ( V_62 -> V_54 , V_52 , L_22 , V_9 ) ;
} else {
F_40 ( V_62 -> V_54 , V_130 -> V_54 , V_52 ) ;
}
return F_17 ( V_50 , V_62 -> V_54 ) ;
}
static T_7
F_91 ( const T_9 * V_54 V_79 , T_3 * V_141 )
{
* V_141 = FALSE ;
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
F_92 ( char * line , T_26 * V_142 )
{
T_9 * V_35 ;
T_27 V_143 ;
if ( ( V_35 = strchr ( line , '#' ) ) )
* V_35 = '\0' ;
if ( ( V_35 = strtok ( line , L_17 ) ) == NULL )
return - 1 ;
if ( sscanf ( V_35 , L_23 V_144 , & V_143 ) == 1 ) {
V_142 -> V_143 = V_143 ;
}
else {
return - 1 ;
}
if ( ( V_35 = strtok ( NULL , L_24 ) ) == NULL )
return - 1 ;
F_40 ( V_142 -> V_54 , V_35 , V_145 ) ;
return 0 ;
}
static void
F_93 ( char * V_48 )
{
if ( V_146 )
rewind ( V_146 ) ;
else
V_146 = F_22 ( V_48 , L_7 ) ;
}
static void
F_94 ( void )
{
if ( V_146 ) {
fclose ( V_146 ) ;
V_146 = NULL ;
}
}
static T_26 *
F_95 ( void )
{
static T_26 V_142 ;
static int V_16 = 0 ;
static char * V_15 = NULL ;
if ( V_146 == NULL )
return NULL ;
while ( F_7 ( & V_15 , & V_16 , V_146 ) >= 0 ) {
if ( F_92 ( V_15 , & V_142 ) == 0 ) {
return & V_142 ;
}
}
return NULL ;
}
static T_26 *
F_96 ( T_27 V_143 )
{
T_26 * V_142 ;
F_93 ( V_147 ) ;
while ( ( ( V_142 = F_95 () ) != NULL ) && ( V_143 != V_142 -> V_143 ) ) ;
if ( V_142 == NULL ) {
F_94 () ;
}
return V_142 ;
}
static void
F_97 ( void )
{
F_9 ( V_148 == NULL ) ;
V_148 = F_30 ( F_5 () , V_57 , V_58 ) ;
if ( V_147 == NULL )
V_147 = F_32 ( V_149 , FALSE ) ;
}
static void
F_98 ( void )
{
V_148 = NULL ;
F_33 ( V_147 ) ;
V_147 = NULL ;
}
static const T_9 *
F_99 ( const T_7 V_143 )
{
T_28 * V_62 ;
T_26 * V_142 ;
V_62 = ( T_28 * ) F_13 ( V_148 , & V_143 ) ;
if ( V_62 == NULL ) {
int * V_1 ;
V_1 = ( int * ) F_4 ( F_5 () , int ) ;
* V_1 = V_143 ;
V_62 = F_4 ( F_5 () , T_28 ) ;
F_15 ( V_148 , V_1 , V_62 ) ;
} else {
return V_62 -> V_54 ;
}
V_62 -> V_143 = V_143 ;
if ( ( V_142 = F_96 ( V_143 ) ) == NULL ) {
F_38 ( V_62 -> V_54 , V_145 , L_25 , V_143 ) ;
} else {
F_40 ( V_62 -> V_54 , V_142 -> V_54 , V_145 ) ;
}
return V_62 -> V_54 ;
}
static T_3
F_100 ( const char * V_150 , T_3 V_151 )
{
T_5 * V_152 ;
char * line = NULL ;
int V_16 = 0 ;
T_9 * V_35 ;
union {
T_1 V_153 ;
struct V_8 V_154 ;
} V_67 ;
T_3 V_155 , V_156 = FALSE ;
if ( ( V_152 = F_22 ( V_150 , L_7 ) ) == NULL )
return FALSE ;
while ( F_7 ( & line , & V_16 , V_152 ) >= 0 ) {
if ( ( V_35 = strchr ( line , '#' ) ) )
* V_35 = '\0' ;
if ( ( V_35 = strtok ( line , L_1 ) ) == NULL )
continue;
if ( F_101 ( V_35 , & V_67 . V_154 ) ) {
V_155 = TRUE ;
} else if ( F_102 ( V_35 , & V_67 . V_153 ) ) {
V_155 = FALSE ;
} else {
continue;
}
if ( ( V_35 = strtok ( NULL , L_1 ) ) == NULL )
continue;
V_156 = TRUE ;
if ( V_151 ) {
if ( V_155 ) {
F_43 ( & V_67 . V_154 , V_35 ) ;
} else {
F_42 ( V_67 . V_153 , V_35 ) ;
}
}
}
F_16 ( F_5 () , line ) ;
fclose ( V_152 ) ;
return V_156 ? TRUE : FALSE ;
}
T_3
F_103 ( const char * V_157 )
{
T_3 V_158 = FALSE ;
T_7 V_5 ;
if ( ! V_157 )
return FALSE ;
if ( ! V_159 )
V_159 = F_104 () ;
for ( V_5 = 0 ; V_5 < V_159 -> V_2 ; V_5 ++ ) {
if ( strcmp ( V_157 , ( const char * ) F_105 ( V_159 , V_5 ) ) == 0 )
V_158 = TRUE ;
}
if ( ! V_158 ) {
F_106 ( V_159 , F_17 ( F_5 () , V_157 ) ) ;
return F_100 ( V_157 , FALSE ) ;
}
return TRUE ;
}
T_3
F_107 ( const char * V_9 , const char * V_54 )
{
union {
T_1 V_153 ;
struct V_8 V_154 ;
} V_67 ;
T_3 V_155 ;
T_29 * V_160 ;
T_30 * V_161 ;
if ( F_101 ( V_9 , & V_67 . V_154 ) ) {
V_155 = TRUE ;
} else if ( F_102 ( V_9 , & V_67 . V_153 ) ) {
V_155 = FALSE ;
} else {
return FALSE ;
}
if ( V_155 ) {
V_161 = F_4 ( F_5 () , T_30 ) ;
memcpy ( & ( V_161 -> V_154 ) , & V_67 . V_154 , 16 ) ;
F_40 ( V_161 -> V_54 , V_54 , V_52 ) ;
F_108 ( V_162 , V_161 ) ;
} else {
V_160 = F_4 ( F_5 () , T_29 ) ;
V_160 -> V_67 = V_67 . V_153 ;
F_40 ( V_160 -> V_54 , V_54 , V_52 ) ;
F_108 ( V_163 , V_160 ) ;
}
return TRUE ;
}
static void
F_109 ( V_14 V_1 V_79 , V_14 V_164 , V_14 V_165 )
{
T_31 * V_166 = ( T_31 * ) V_165 ;
T_12 * V_167 = ( T_12 * ) V_164 ;
if ( ( V_167 -> V_64 & V_168 ) == V_169 ) {
V_166 -> V_170 = F_110 ( V_166 -> V_170 , V_167 ) ;
}
}
static void
F_111 ( V_14 V_1 V_79 , V_14 V_164 , V_14 V_165 )
{
T_31 * V_166 = ( T_31 * ) V_165 ;
T_15 * V_171 = ( T_15 * ) V_164 ;
if ( ( V_171 -> V_64 & V_168 ) == V_169 ) {
V_166 -> V_172 = F_110 ( V_166 -> V_172 , V_171 ) ;
}
}
T_31 *
F_112 ( void )
{
if ( V_88 ) {
F_113 ( V_88 , F_109 , & V_173 ) ;
}
if ( V_97 ) {
F_113 ( V_97 , F_111 , & V_173 ) ;
}
return & V_173 ;
}
static T_3
F_114 ( const char * V_174 )
{
T_5 * V_152 ;
char * line = NULL ;
int V_16 = 0 ;
T_9 * V_35 , * V_175 ;
T_1 V_67 ;
V_71 V_72 ;
if ( ( V_152 = F_22 ( V_174 , L_7 ) ) == NULL )
return FALSE ;
while ( F_7 ( & line , & V_16 , V_152 ) >= 0 ) {
if ( ( V_35 = strchr ( line , '#' ) ) )
* V_35 = '\0' ;
if ( ( V_35 = strtok ( line , L_1 ) ) == NULL )
continue;
V_175 = strchr ( V_35 , '/' ) ;
if ( NULL == V_175 ) {
continue;
}
* V_175 = '\0' ;
++ V_175 ;
if ( ! F_115 ( V_35 , & V_67 ) ) {
continue;
}
if ( ! F_116 ( V_175 , NULL , & V_72 ) || V_72 == 0 || V_72 > 32 ) {
continue;
}
if ( ( V_35 = strtok ( NULL , L_1 ) ) == NULL )
continue;
F_117 ( V_67 , V_72 , V_35 ) ;
}
F_16 ( F_5 () , line ) ;
fclose ( V_152 ) ;
return TRUE ;
}
static T_13
F_36 ( const T_1 V_9 )
{
T_13 V_63 ;
T_1 V_5 ;
V_5 = V_176 ;
while( V_177 && V_5 > 0 ) {
T_1 V_117 ;
T_32 * V_178 ;
-- V_5 ;
F_9 ( V_5 < V_176 ) ;
V_178 = & V_179 [ V_5 ] ;
if ( NULL != V_178 -> V_180 ) {
T_33 * V_62 ;
T_1 V_181 ;
V_117 = V_9 & V_178 -> V_66 ;
V_181 = F_118 ( V_117 ) ;
V_62 = V_178 -> V_180 [ V_181 ] ;
while( V_62 != NULL && V_62 -> V_9 != V_117 ) {
V_62 = V_62 -> V_182 ;
}
if ( NULL != V_62 ) {
V_63 . V_66 = V_178 -> V_66 ;
V_63 . V_72 = V_5 + 1 ;
V_63 . V_54 = V_62 -> V_54 ;
return V_63 ;
}
}
}
V_63 . V_66 = 0 ;
V_63 . V_72 = 0 ;
V_63 . V_54 = NULL ;
return V_63 ;
}
static void
F_117 ( T_1 V_183 , const V_71 V_72 , const T_9 * V_54 )
{
T_32 * V_184 ;
T_33 * V_62 ;
T_14 V_181 ;
F_9 ( V_72 > 0 && V_72 <= 32 ) ;
V_184 = & V_179 [ V_72 - 1 ] ;
V_183 &= V_184 -> V_66 ;
V_181 = F_118 ( V_183 ) ;
if ( NULL == V_184 -> V_180 ) {
V_184 -> V_180 = ( T_33 * * ) F_119 ( F_5 () , sizeof( T_33 * ) * V_185 ) ;
}
if ( NULL != ( V_62 = V_184 -> V_180 [ V_181 ] ) ) {
T_33 * V_186 ;
while ( V_62 -> V_182 ) {
if ( V_62 -> V_9 == V_183 ) {
return;
} else {
V_62 = V_62 -> V_182 ;
}
}
V_186 = F_4 ( F_5 () , T_33 ) ;
V_62 -> V_182 = V_186 ;
V_62 = V_186 ;
} else {
V_62 = V_184 -> V_180 [ V_181 ] = F_4 ( F_5 () , T_33 ) ;
}
V_62 -> V_182 = NULL ;
V_62 -> V_9 = V_183 ;
V_62 -> V_64 &= ~ V_65 ;
F_40 ( V_62 -> V_54 , V_54 , V_52 ) ;
V_177 = TRUE ;
}
static void
F_120 ( void )
{
T_9 * V_174 ;
T_1 V_5 ;
for( V_5 = 0 ; V_5 < V_176 ; ++ V_5 ) {
T_1 V_187 = V_5 + 1 ;
V_179 [ V_5 ] . V_180 = NULL ;
V_179 [ V_5 ] . V_72 = V_187 ;
V_179 [ V_5 ] . V_66 = F_121 ( F_122 ( V_187 ) ) ;
}
V_174 = F_32 ( V_188 , TRUE ) ;
if ( ! F_114 ( V_174 ) ) {
if ( V_189 != V_190 ) {
F_123 ( V_174 , V_189 , FALSE ) ;
}
F_33 ( V_174 ) ;
V_174 = F_32 ( V_188 , FALSE ) ;
if ( ! F_114 ( V_174 ) && V_189 != V_190 ) {
F_123 ( V_174 , V_189 , FALSE ) ;
}
}
F_33 ( V_174 ) ;
V_174 = F_31 ( V_188 ) ;
if ( ! F_114 ( V_174 ) && V_189 != V_190 ) {
F_123 ( V_174 , V_189 , FALSE ) ;
}
F_33 ( V_174 ) ;
}
static T_34 *
F_124 ( const V_71 V_191 , const T_1 V_192 )
{
T_34 * V_62 = F_4 ( F_5 () , T_34 ) ;
V_62 -> V_143 = ( V_191 << 24 ) + ( V_192 & 0xffffff ) ;
V_62 -> V_193 [ 0 ] = '\0' ;
V_62 -> V_54 [ 0 ] = '\0' ;
return V_62 ;
}
static T_34 *
F_125 ( const V_71 V_191 , const T_1 V_192 )
{
T_34 * volatile V_62 ;
T_1 V_143 ;
V_143 = ( V_191 << 24 ) + ( V_192 & 0xffffff ) ;
V_62 = ( T_34 * ) F_13 ( V_194 , F_46 ( V_143 ) ) ;
if ( V_62 == NULL ) {
V_62 = F_124 ( V_191 , V_192 ) ;
F_15 ( V_194 , F_46 ( V_143 ) , V_62 ) ;
}
return V_62 ;
}
void F_126 ( const T_9 * V_193 , const V_71 V_191 , const T_1 V_192 )
{
T_34 * V_62 = F_125 ( V_191 , V_192 ) ;
F_40 ( V_62 -> V_193 , V_193 , V_52 ) ;
}
const T_9 *
F_127 ( const V_71 V_191 , const T_1 V_192 )
{
T_34 * V_62 = F_125 ( V_191 , V_192 ) ;
if ( V_62 -> V_193 [ 0 ] == '\0' )
return V_62 -> V_193 ;
if ( V_62 -> V_54 [ 0 ] == '\0' )
return V_62 -> V_193 ;
if ( ! V_90 . V_195 )
return V_62 -> V_193 ;
return V_62 -> V_54 ;
}
static void
F_128 ( const V_71 V_191 , T_1 V_192 , const T_9 * V_54 )
{
T_34 * V_62 ;
T_1 V_143 ;
if ( ! V_54 || V_54 [ 0 ] == '\0' )
return;
V_143 = ( V_191 << 24 ) + ( V_192 & 0xffffff ) ;
V_62 = ( T_34 * ) F_13 ( V_194 , F_46 ( V_143 ) ) ;
if ( ! V_62 ) {
V_62 = F_124 ( V_191 , V_192 ) ;
F_15 ( V_194 , F_46 ( V_143 ) , V_62 ) ;
}
if ( F_129 ( V_62 -> V_54 , V_54 ) ) {
F_40 ( V_62 -> V_54 , V_54 , V_52 ) ;
}
}
static T_3
F_130 ( const char * V_196 )
{
T_5 * V_152 ;
char * line = NULL ;
int V_16 = 0 ;
T_9 * V_35 ;
V_71 V_191 ;
T_1 V_192 ;
T_3 V_156 = FALSE ;
if ( ( V_152 = F_22 ( V_196 , L_7 ) ) == NULL )
return FALSE ;
while ( F_7 ( & line , & V_16 , V_152 ) >= 0 ) {
if ( ( V_35 = strchr ( line , '#' ) ) )
* V_35 = '\0' ;
if ( ( V_35 = strtok ( line , L_26 ) ) == NULL )
continue;
if ( ! F_116 ( V_35 , NULL , & V_191 ) )
continue;
if ( V_191 > 3 )
continue;
if ( ( V_35 = strtok ( NULL , L_1 ) ) == NULL )
continue;
if ( ! F_131 ( V_35 , NULL , & V_192 ) )
continue;
if ( V_192 >> 24 > 0 )
continue;
if ( ( V_35 = strtok ( NULL , L_1 ) ) == NULL )
continue;
V_156 = TRUE ;
F_128 ( V_191 , V_192 , V_35 ) ;
}
F_16 ( F_5 () , line ) ;
fclose ( V_152 ) ;
return V_156 ? TRUE : FALSE ;
}
static void
F_132 ( void )
{
char * V_196 ;
F_9 ( V_194 == NULL ) ;
V_194 = F_30 ( F_5 () , V_197 , V_198 ) ;
V_196 = F_32 ( V_199 , TRUE ) ;
if ( ! F_130 ( V_196 ) && V_189 != V_190 ) {
F_123 ( V_196 , V_189 , FALSE ) ;
}
F_33 ( V_196 ) ;
}
void
F_133 ( T_35 * V_200 )
{
F_134 ( V_200 , L_27 ,
L_28 ,
L_29
L_30 ,
& V_90 . V_201 ) ;
F_134 ( V_200 , L_31 ,
L_32 ,
L_33 ,
& V_90 . V_202 ) ;
F_134 ( V_200 , L_34 ,
L_35 ,
L_36
L_37
L_38
L_39 ,
& V_90 . V_91 ) ;
F_134 ( V_200 , L_40 ,
L_41 ,
L_42 ,
& V_90 . V_203 ) ;
#ifdef F_47
F_134 ( V_200 , L_43 ,
L_44 ,
L_45
L_46
L_47
L_48 ,
& V_90 . V_92 ) ;
F_135 ( V_200 , L_49 ) ;
F_136 ( V_200 , L_50 ,
L_51 ,
L_52
L_53
L_54
L_55 ,
10 ,
& V_95 ) ;
#else
F_137 ( V_200 , L_43 ,
L_56 ,
L_57
L_58 ) ;
#endif
F_134 ( V_200 , L_59 ,
L_60 ,
L_61
L_62 ,
& V_90 . V_204 ) ;
F_134 ( V_200 , L_63 ,
L_64 ,
L_65
L_66
L_67 ,
& V_90 . V_205 ) ;
F_134 ( V_200 , L_68 ,
L_69 ,
L_70
L_71
L_72 ,
& V_90 . V_195 ) ;
}
void
F_138 ( void ) {
V_90 . V_201 = FALSE ;
V_90 . V_91 = FALSE ;
V_90 . V_202 = FALSE ;
V_90 . V_203 = FALSE ;
V_90 . V_92 = FALSE ;
V_90 . V_205 = FALSE ;
V_90 . V_195 = FALSE ;
}
T_3
F_139 ( void ) {
T_4 * V_80 ;
struct V_206 V_207 = { 0 , 0 } ;
int V_208 ;
T_36 V_209 , V_210 ;
T_3 V_211 = V_34 ;
T_37 * V_212 ;
V_34 = FALSE ;
if ( ! V_94 )
return V_211 ;
V_212 = F_140 ( V_13 ) ;
while ( V_212 != NULL && V_81 <= V_95 ) {
V_80 = ( T_4 * ) F_141 ( V_212 ) ;
F_142 ( V_13 , V_212 ) ;
if ( V_80 -> V_11 == V_84 ) {
F_143 ( V_213 , & V_80 -> V_9 . V_12 , sizeof( T_1 ) , V_84 ,
F_41 , V_80 ) ;
V_81 ++ ;
} else if ( V_80 -> V_11 == V_86 ) {
F_143 ( V_213 , & V_80 -> V_9 . V_73 , sizeof( struct V_8 ) ,
V_86 , F_41 , V_80 ) ;
V_81 ++ ;
}
V_212 = F_140 ( V_13 ) ;
}
F_144 ( & V_209 ) ;
F_144 ( & V_210 ) ;
V_208 = F_145 ( V_213 , & V_209 , & V_210 ) ;
if ( V_208 > 0 ) {
if ( F_146 ( V_208 , & V_209 , & V_210 , NULL , & V_207 ) == - 1 ) {
fprintf ( V_214 , L_73 , F_147 ( V_189 ) ) ;
return V_211 ;
}
F_148 ( V_213 , & V_209 , & V_210 ) ;
}
return V_211 ;
}
static void
F_149 ( void ) {
V_13 = NULL ;
if ( V_94 ) {
F_150 ( V_213 ) ;
F_150 ( V_215 ) ;
}
#ifdef F_151
F_152 () ;
#endif
V_94 = FALSE ;
}
T_3
F_139 ( void ) {
T_3 V_211 = V_34 ;
V_34 = FALSE ;
return V_211 ;
}
static void
F_149 ( void ) {
}
const T_9 *
F_153 ( const T_7 V_9 )
{
T_12 * V_62 = F_45 ( V_9 ) ;
if ( ! V_90 . V_91 )
return V_62 -> V_87 ;
V_62 -> V_64 |= V_169 ;
return V_62 -> V_54 ;
}
const T_9 *
F_154 ( const struct V_8 * V_9 )
{
T_15 * V_62 = F_50 ( V_9 ) ;
if ( ! V_90 . V_91 )
return V_62 -> V_73 ;
V_62 -> V_64 |= V_169 ;
return V_62 -> V_54 ;
}
void
F_42 ( const T_7 V_9 , const T_9 * V_54 )
{
T_12 * V_62 ;
if ( ! V_54 || V_54 [ 0 ] == '\0' )
return;
V_62 = ( T_12 * ) F_13 ( V_88 , F_46 ( V_9 ) ) ;
if ( ! V_62 ) {
V_62 = F_44 ( V_9 ) ;
F_15 ( V_88 , F_46 ( V_9 ) , V_62 ) ;
}
if ( F_129 ( V_62 -> V_54 , V_54 ) ) {
F_40 ( V_62 -> V_54 , V_54 , V_52 ) ;
V_34 = TRUE ;
}
V_62 -> V_64 |= V_93 | V_216 ;
V_62 -> V_64 &= ~ V_65 ;
}
void
F_43 ( const struct V_8 * V_217 , const T_9 * V_54 )
{
T_15 * V_62 ;
if ( ! V_54 || V_54 [ 0 ] == '\0' )
return;
V_62 = ( T_15 * ) F_13 ( V_97 , V_217 ) ;
if ( ! V_62 ) {
struct V_8 * V_98 ;
V_98 = F_4 ( F_5 () , struct V_8 ) ;
V_62 = F_48 ( V_217 ) ;
memcpy ( V_98 , V_217 , 16 ) ;
F_15 ( V_97 , V_98 , V_62 ) ;
}
if ( F_129 ( V_62 -> V_54 , V_54 ) ) {
F_40 ( V_62 -> V_54 , V_54 , V_52 ) ;
V_34 = TRUE ;
}
V_62 -> V_64 |= V_93 | V_216 ;
V_62 -> V_64 &= ~ V_65 ;
}
static void
F_155 ( V_14 V_218 , V_14 V_165 V_79 )
{
T_29 * V_160 = ( T_29 * ) V_218 ;
F_42 ( V_160 -> V_67 , V_160 -> V_54 ) ;
}
static void
F_156 ( V_14 V_218 , V_14 V_165 V_79 )
{
T_30 * V_161 = ( T_30 * ) V_218 ;
F_43 ( & ( V_161 -> V_154 ) , V_161 -> V_54 ) ;
}
static void
F_157 ( void )
{
if ( V_163 ) {
F_158 ( V_163 , F_155 , NULL ) ;
}
if ( V_162 ) {
F_158 ( V_162 , F_156 , NULL ) ;
}
}
void
F_159 ( void )
{
char * V_150 ;
T_7 V_5 ;
F_9 ( V_140 == NULL ) ;
V_140 = F_30 ( F_5 () , V_57 , V_58 ) ;
F_9 ( V_88 == NULL ) ;
V_88 = F_30 ( F_5 () , V_197 , V_198 ) ;
F_9 ( V_97 == NULL ) ;
V_97 = F_30 ( F_5 () , F_1 , F_2 ) ;
#ifdef F_47
F_9 ( V_13 == NULL ) ;
V_13 = F_160 ( F_5 () ) ;
#endif
if ( V_163 == NULL )
V_163 = F_160 ( F_5 () ) ;
if ( V_162 == NULL )
V_162 = F_160 ( F_5 () ) ;
if ( ! V_90 . V_204 ) {
V_150 = F_31 ( V_219 ) ;
if ( ! F_100 ( V_150 , TRUE ) && V_189 != V_190 ) {
F_123 ( V_150 , V_189 , FALSE ) ;
}
F_33 ( V_150 ) ;
}
V_150 = F_32 ( V_219 , TRUE ) ;
if ( ! F_100 ( V_150 , TRUE ) && V_189 != V_190 ) {
F_123 ( V_150 , V_189 , FALSE ) ;
}
F_33 ( V_150 ) ;
#ifdef F_47
#ifdef F_151
if ( F_161 ( V_220 ) == V_82 ) {
#endif
if ( F_162 ( & V_213 ) == V_82 && F_162 ( & V_215 ) == V_82 ) {
V_94 = TRUE ;
}
#ifdef F_151
}
#endif
#else
#endif
if ( V_159 && ! V_90 . V_204 ) {
for ( V_5 = 0 ; V_5 < V_159 -> V_2 ; V_5 ++ ) {
F_100 ( ( const char * ) F_105 ( V_159 , V_5 ) , TRUE ) ;
}
}
F_120 () ;
F_157 () ;
F_132 () ;
}
void
F_163 ( void )
{
T_1 V_5 , V_221 ;
T_33 * V_184 , * V_222 ;
F_149 () ;
V_140 = NULL ;
V_88 = NULL ;
V_97 = NULL ;
V_194 = NULL ;
for( V_5 = 0 ; V_5 < V_176 ; ++ V_5 ) {
if ( V_179 [ V_5 ] . V_180 != NULL ) {
for ( V_221 = 0 ; V_221 < V_185 ; V_221 ++ ) {
for ( V_184 = V_179 [ V_5 ] . V_180 [ V_221 ] ;
V_184 != NULL ; V_184 = V_222 ) {
V_222 = V_184 -> V_182 ;
F_16 ( F_5 () , V_184 ) ;
}
}
F_16 ( F_5 () , V_179 [ V_5 ] . V_180 ) ;
V_179 [ V_5 ] . V_180 = NULL ;
}
}
V_177 = FALSE ;
V_34 = FALSE ;
}
void
F_164 ( void )
{
F_165 ( V_163 ) ;
V_163 = NULL ;
F_165 ( V_162 ) ;
V_162 = NULL ;
}
T_9 *
F_166 ( T_11 * V_50 , T_7 V_22 )
{
if ( ! V_90 . V_202 ) {
return F_23 ( V_50 , V_22 ) ;
}
return F_17 ( V_50 , F_27 ( V_28 , V_22 ) ) ;
}
T_9 *
F_167 ( T_11 * V_50 , T_7 V_22 )
{
if ( ! V_90 . V_202 ) {
return F_23 ( V_50 , V_22 ) ;
}
return F_17 ( V_50 , F_27 ( V_32 , V_22 ) ) ;
}
T_9 *
F_168 ( T_11 * V_50 , T_7 V_22 )
{
if ( ! V_90 . V_202 ) {
return F_23 ( V_50 , V_22 ) ;
}
return F_17 ( V_50 , F_27 ( V_26 , V_22 ) ) ;
}
T_9 *
F_169 ( T_11 * V_50 , T_7 V_22 )
{
if ( ! V_90 . V_202 ) {
return F_23 ( V_50 , V_22 ) ;
}
return F_17 ( V_50 , F_27 ( V_30 , V_22 ) ) ;
}
T_9 *
F_170 ( T_11 * V_223 , T_6 V_21 , T_7 V_22 )
{
const T_9 * V_224 ;
if ( ! V_90 . V_202 || ( V_21 == V_47 ) ) {
return F_28 ( V_223 , L_8 , V_22 ) ;
}
V_224 = F_27 ( V_21 , V_22 ) ;
F_9 ( V_224 ) ;
return F_28 ( V_223 , L_74 , V_224 , V_22 ) ;
}
int
F_171 ( T_9 * V_15 , T_38 V_225 , T_6 V_21 , T_7 V_22 )
{
const T_9 * V_224 ;
if ( ! V_90 . V_202 || ( V_21 == V_47 ) ) {
return F_38 ( V_15 , V_225 , L_8 , V_22 ) ;
}
V_224 = F_27 ( V_21 , V_22 ) ;
F_9 ( V_224 ) ;
return F_38 ( V_15 , V_225 , L_74 , V_224 , V_22 ) ;
}
const T_9 *
F_172 ( const V_71 * V_9 )
{
T_22 * V_62 ;
T_3 V_129 = V_90 . V_201 ;
V_62 = F_81 ( V_9 , V_129 ) ;
return V_129 ? V_62 -> V_109 : V_62 -> V_112 ;
}
const T_9 *
F_173 ( T_39 * V_226 , T_21 V_227 )
{
return F_172 ( F_174 ( V_226 , V_227 , 6 ) ) ;
}
const T_9 *
F_175 ( const V_71 * V_9 )
{
T_22 * V_62 ;
if ( ! V_90 . V_201 )
return NULL ;
V_62 = F_81 ( V_9 , TRUE ) ;
F_9 ( V_62 != NULL ) ;
if ( V_62 -> V_75 == V_110 ) {
return V_62 -> V_109 ;
}
else {
return NULL ;
}
}
V_71 *
F_176 ( const T_9 * V_54 )
{
return F_82 ( V_54 ) ;
}
void
F_177 ( const T_7 V_87 , const V_71 * V_99 )
{
T_12 * V_62 ;
if ( ! V_90 . V_91 )
return;
V_62 = F_45 ( V_87 ) ;
if ( V_62 -> V_64 & V_216 ) {
F_64 ( V_99 , V_62 -> V_54 ) ;
}
}
T_9 *
F_178 ( T_11 * V_50 , const T_1 V_228 , const char V_229 )
{
T_9 * V_15 = ( T_9 * ) F_8 ( V_50 , 12 ) ;
* F_179 ( V_15 , V_228 , V_229 ) = '\0' ;
return V_15 ;
}
T_9 *
F_180 ( T_11 * V_50 , const T_1 V_9 )
{
if ( ! V_90 . V_91 ) {
return F_178 ( V_50 , V_9 , '\0' ) ;
}
return F_90 ( V_50 , V_9 ) ;
}
T_1
F_181 ( const T_9 * V_54 , T_3 * V_230 )
{
T_1 V_9 ;
T_3 V_141 ;
V_9 = F_91 ( V_54 , & V_141 ) ;
* V_230 = V_141 ;
return V_9 ;
}
T_9 *
F_182 ( T_11 * V_50 , const T_27 V_143 )
{
if ( ! V_90 . V_205 ) {
return NULL ;
}
return F_17 ( V_50 , F_99 ( V_143 ) ) ;
}
const T_9 *
F_183 ( const V_71 * V_9 )
{
T_19 * V_107 ;
V_107 = F_65 ( V_9 ) ;
if ( V_90 . V_201 && V_107 -> V_75 != V_111 )
return V_107 -> V_109 ;
return V_107 -> V_112 ;
}
const T_9 *
F_184 ( const T_7 V_231 )
{
V_71 V_9 [ 3 ] ;
V_9 [ 0 ] = ( V_231 >> 16 ) & 0xFF ;
V_9 [ 1 ] = ( V_231 >> 8 ) & 0xFF ;
V_9 [ 2 ] = ( V_231 >> 0 ) & 0xFF ;
return F_183 ( V_9 ) ;
}
const T_9 *
F_185 ( T_39 * V_226 , T_21 V_227 )
{
return F_183 ( F_174 ( V_226 , V_227 , 3 ) ) ;
}
const T_9 *
F_186 ( const V_71 * V_9 )
{
T_19 * V_107 ;
int V_106 ;
V_71 V_116 ;
V_106 = V_9 [ 0 ] ;
V_106 = V_106 << 8 ;
V_116 = V_9 [ 1 ] ;
V_106 = V_106 | V_116 ;
V_106 = V_106 << 8 ;
V_116 = V_9 [ 2 ] ;
V_106 = V_106 | V_116 ;
V_107 = ( T_19 * ) F_13 ( V_113 , & V_106 ) ;
if ( ( V_107 == NULL ) || ( V_107 -> V_75 == V_111 ) ) {
return NULL ;
}
return V_107 -> V_109 ;
}
const T_9 *
F_187 ( const T_7 V_106 )
{
T_19 * V_107 ;
V_107 = ( T_19 * ) F_13 ( V_113 , & V_106 ) ;
if ( ( V_107 == NULL ) || ( V_107 -> V_75 == V_111 ) ) {
return NULL ;
}
return V_107 -> V_109 ;
}
const T_9 *
F_188 ( T_39 * V_226 , T_21 V_227 )
{
return F_186 ( F_174 ( V_226 , V_227 , 3 ) ) ;
}
char * F_189 ( T_19 * V_232 )
{
return V_232 -> V_109 ;
}
T_9 *
F_190 ( T_11 * V_50 , const T_40 V_233 )
{
V_71 * V_9 = ( V_71 * ) F_8 ( NULL , 8 ) ;
T_19 * V_107 ;
T_9 * V_234 ;
* ( T_40 * ) ( void * ) ( V_9 ) = F_191 ( & ( V_233 ) ) ;
V_107 = F_65 ( V_9 ) ;
if ( ! V_90 . V_201 || ( V_107 -> V_75 == V_111 ) ) {
V_234 = F_28 ( V_50 , L_75 , V_9 [ 0 ] , V_9 [ 1 ] , V_9 [ 2 ] , V_9 [ 3 ] , V_9 [ 4 ] , V_9 [ 5 ] , V_9 [ 6 ] , V_9 [ 7 ] ) ;
} else {
V_234 = F_28 ( V_50 , L_15 , V_107 -> V_109 , V_9 [ 3 ] , V_9 [ 4 ] , V_9 [ 5 ] , V_9 [ 6 ] , V_9 [ 7 ] ) ;
}
F_16 ( NULL , V_9 ) ;
return V_234 ;
}
static void
F_192 (
void * V_74 ,
int V_75 ,
#if ( ( V_76 < 1 ) \
|| ( 1 == V_76 && V_77 < 5 ) )
struct V_78 * T_41
#else
int T_17 V_79 ,
struct V_78 * T_41
#endif
) {
T_42 * V_235 = ( T_42 * ) V_74 ;
if ( V_75 == V_82 && T_41 && V_235 && T_41 -> V_236 == V_235 -> V_237 ) {
memcpy ( V_235 -> V_217 , T_41 -> V_238 , T_41 -> V_236 ) ;
V_235 -> V_239 = T_41 -> V_236 ;
}
}
T_3
F_193 ( const char * V_240 , T_1 * V_217 )
{
struct V_241 V_242 ;
#ifdef F_47
struct V_206 V_207 = { 0 , V_243 } , * V_244 ;
int V_208 ;
T_36 V_209 , V_210 ;
T_42 V_245 ;
#endif
if ( ! F_194 ( V_240 , & V_242 ) ) {
if ( ! V_90 . V_91 ||
! V_90 . V_92 ) {
return FALSE ;
}
#ifdef F_47
if ( ! V_94 || V_95 < 1 ) {
return FALSE ;
}
V_245 . V_237 = ( int ) sizeof ( struct V_241 ) ;
V_245 . V_239 = 0 ;
V_245 . V_217 = V_217 ;
F_195 ( V_215 , V_240 , V_84 , F_192 , & V_245 ) ;
F_144 ( & V_209 ) ;
F_144 ( & V_210 ) ;
V_208 = F_145 ( V_215 , & V_209 , & V_210 ) ;
if ( V_208 > 0 ) {
V_244 = F_196 ( V_215 , & V_207 , & V_207 ) ;
if ( F_146 ( V_208 , & V_209 , & V_210 , NULL , V_244 ) == - 1 ) {
fprintf ( V_214 , L_73 , F_147 ( V_189 ) ) ;
return FALSE ;
}
F_148 ( V_215 , & V_209 , & V_210 ) ;
}
F_197 ( V_215 ) ;
if ( V_245 . V_237 == V_245 . V_239 ) {
return TRUE ;
}
return FALSE ;
#endif
} else {
unsigned int V_131 , V_132 , V_133 , V_134 ;
if ( sscanf ( V_240 , L_76 , & V_131 , & V_132 , & V_133 , & V_134 ) != 4 )
return FALSE ;
}
* V_217 = V_242 . V_246 ;
return TRUE ;
}
T_3
F_198 ( const char * V_240 , struct V_8 * V_217 )
{
#ifdef F_47
struct V_206 V_207 = { 0 , V_243 } , * V_244 ;
int V_208 ;
T_36 V_209 , V_210 ;
T_42 V_245 ;
#endif
if ( F_199 ( V_240 , V_217 ) )
return TRUE ;
if ( ! V_90 . V_91 ||
! V_90 . V_92 ) {
return FALSE ;
}
#ifdef F_47
if ( ! V_94 || V_95 < 1 ) {
return FALSE ;
}
V_245 . V_237 = ( int ) sizeof ( struct V_8 ) ;
V_245 . V_239 = 0 ;
V_245 . V_217 = V_217 ;
F_195 ( V_215 , V_240 , V_86 , F_192 , & V_245 ) ;
F_144 ( & V_209 ) ;
F_144 ( & V_210 ) ;
V_208 = F_145 ( V_215 , & V_209 , & V_210 ) ;
if ( V_208 > 0 ) {
V_244 = F_196 ( V_215 , & V_207 , & V_207 ) ;
if ( F_146 ( V_208 , & V_209 , & V_210 , NULL , V_244 ) == - 1 ) {
fprintf ( V_214 , L_73 , F_147 ( V_189 ) ) ;
return FALSE ;
}
F_148 ( V_215 , & V_209 , & V_210 ) ;
}
F_197 ( V_215 ) ;
if ( V_245 . V_237 == V_245 . V_239 ) {
return TRUE ;
}
#endif
return FALSE ;
}
T_43 *
F_200 ( void )
{
return V_113 ;
}
T_43 *
F_201 ( void )
{
return V_115 ;
}
T_43 *
F_202 ( void )
{
return V_122 ;
}
T_43 *
F_203 ( void )
{
return V_25 ;
}
T_43 *
F_204 ( void )
{
return V_140 ;
}
T_43 *
F_205 ( void )
{
return V_148 ;
}
T_43 *
F_206 ( void )
{
return V_88 ;
}
T_43 *
F_207 ( void )
{
return V_97 ;
}
void
F_208 ( void )
{
F_29 () ;
F_73 () ;
F_88 () ;
F_97 () ;
}
void
F_209 ( void )
{
F_98 () ;
F_34 () ;
F_75 () ;
F_89 () ;
}
T_3
F_115 ( const char * V_247 , void * V_248 )
{
return F_102 ( V_247 , ( T_1 * ) V_248 ) ;
}
T_3
F_199 ( const char * V_247 , void * V_248 )
{
return F_101 ( V_247 , (struct V_8 * ) V_248 ) ;
}
