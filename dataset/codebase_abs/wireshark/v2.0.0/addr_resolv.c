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
if ( strcmp ( V_37 , L_3 ) == 0 ) {
V_40 = V_42 ;
V_23 = V_28 ;
}
else if ( strcmp ( V_37 , L_4 ) == 0 ) {
V_40 = V_41 ;
V_23 = V_30 ;
}
else if ( strcmp ( V_37 , L_5 ) == 0 ) {
V_40 = V_43 ;
V_23 = V_32 ;
}
else if ( strcmp ( V_37 , L_6 ) == 0 ) {
V_40 = V_44 ;
V_23 = V_34 ;
} else {
return;
}
if ( V_45 != F_18 ( & V_39 , V_24 , V_40 ) ) {
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
F_22 ( T_11 * V_52 , T_7 V_24 )
{
T_9 * V_53 = ( T_9 * ) F_23 ( V_52 , V_54 ) ;
F_24 ( V_24 , V_53 , V_54 ) ;
return V_53 ;
}
static const T_9 *
F_25 ( const T_7 V_24 , const T_6 V_23 )
{
T_8 * V_26 ;
T_9 * V_55 ;
V_26 = ( T_8 * ) F_12 ( V_27 , & V_24 ) ;
if ( V_26 ) {
switch( V_23 ) {
case V_30 :
if ( V_26 -> V_31 ) {
return V_26 -> V_31 ;
}
break;
case V_28 :
if ( V_26 -> V_29 ) {
return V_26 -> V_29 ;
}
break;
case V_32 :
if ( V_26 -> V_33 ) {
return V_26 -> V_33 ;
}
break;
case V_34 :
if ( V_26 -> V_35 ) {
return V_26 -> V_35 ;
}
break;
default:
return NULL ;
}
}
V_55 = ( T_9 * ) F_8 ( 16 ) ;
F_24 ( V_24 , V_55 , 16 ) ;
if ( V_26 == NULL ) {
int * V_1 ;
V_1 = ( int * ) F_4 ( int , 1 ) ;
* V_1 = V_24 ;
V_26 = F_13 ( T_8 , 1 ) ;
F_14 ( V_27 , V_1 , V_26 ) ;
}
switch( V_23 ) {
case V_30 :
V_26 -> V_31 = V_55 ;
break;
case V_28 :
V_26 -> V_29 = V_55 ;
break;
case V_32 :
V_26 -> V_33 = V_55 ;
break;
case V_34 :
V_26 -> V_35 = V_55 ;
break;
default:
return NULL ;
}
return V_55 ;
}
static void
F_26 ( V_16 V_56 )
{
T_8 * V_57 = ( T_8 * ) V_56 ;
F_15 ( V_57 -> V_31 ) ;
F_15 ( V_57 -> V_29 ) ;
F_15 ( V_57 -> V_33 ) ;
F_15 ( V_57 -> V_35 ) ;
F_15 ( V_57 ) ;
}
static void
F_27 ( void )
{
#ifdef F_28
char * V_58 ;
char * V_59 ;
static char V_60 [] = L_8 ;
#endif
F_9 ( V_27 == NULL ) ;
V_27 = F_29 ( V_61 , V_62 , F_15 , F_26 ) ;
#ifdef F_28
V_59 = F_30 ( L_9 ) ;
if ( V_59 != NULL ) {
V_58 = F_31 ( V_59 , V_60 , NULL ) ;
F_20 ( V_58 ) ;
F_15 ( V_58 ) ;
}
#else
F_20 ( L_10 ) ;
#endif
if ( V_63 == NULL )
V_63 = F_32 ( V_64 , FALSE ) ;
F_20 ( V_63 ) ;
if ( V_65 == NULL ) {
V_65 = F_33 ( V_64 ) ;
}
F_20 ( V_65 ) ;
}
static void
F_34 ( void )
{
if ( V_27 ) {
F_35 ( V_27 ) ;
V_27 = NULL ;
}
}
static void
F_36 ( const T_7 V_9 , T_12 * volatile V_66 )
{
T_13 V_67 ;
if ( V_66 -> V_68 & V_69 )
return;
V_66 -> V_68 |= V_69 ;
V_67 = F_37 ( V_9 ) ;
if ( 0 != V_67 . V_70 ) {
T_1 V_71 ;
T_9 V_72 [ V_73 ] ;
T_9 * V_74 ;
T_14 V_5 ;
V_71 = V_9 & ( ~ ( T_1 ) V_67 . V_70 ) ;
F_38 ( ( V_75 * ) & V_71 , V_72 , V_73 ) ;
V_74 = V_72 ;
V_5 = V_67 . V_76 / 8 ;
while( * ( V_74 ) != '\0' && V_5 > 0 ) {
if ( * ( ++ V_74 ) == '.' ) {
-- V_5 ;
}
}
F_39 ( V_66 -> V_55 , V_54 , L_11 , V_67 . V_55 , V_74 ) ;
} else {
F_38 ( ( const V_75 * ) & V_9 , V_66 -> V_55 , V_54 ) ;
}
}
static void
F_40 (
void * V_77 ,
int V_78 ,
#if ( ( V_79 < 1 ) \
|| ( 1 == V_79 && V_80 < 5 ) )
struct V_81 * T_15
#else
int T_16 V_82 ,
struct V_81 * T_15
#endif
) {
T_4 * V_83 = ( T_4 * ) V_77 ;
char * * V_3 ;
if ( ! V_83 ) return;
V_84 -- ;
if ( V_78 == V_85 ) {
for ( V_3 = T_15 -> V_86 ; * V_3 != NULL ; V_3 ++ ) {
switch( V_83 -> V_11 ) {
case V_87 :
F_41 ( V_83 -> V_9 . V_12 , T_15 -> V_88 ) ;
break;
case V_89 :
F_42 ( & V_83 -> V_9 . V_90 , T_15 -> V_88 ) ;
break;
default:
break;
}
}
}
F_15 ( V_83 ) ;
}
static T_12 *
F_43 ( const T_7 V_9 )
{
T_12 * V_66 = F_4 ( T_12 , 1 ) ;
V_66 -> V_9 = V_9 ;
V_66 -> V_68 = 0 ;
V_66 -> V_55 [ 0 ] = '\0' ;
F_38 ( ( const V_75 * ) & V_9 , V_66 -> V_91 , sizeof( V_66 -> V_91 ) ) ;
return V_66 ;
}
static T_12 *
F_44 ( const T_7 V_9 , T_3 * V_92 )
{
T_12 * volatile V_66 ;
* V_92 = TRUE ;
V_66 = ( T_12 * ) F_12 ( V_93 , F_45 ( V_9 ) ) ;
if ( V_66 == NULL ) {
V_66 = F_43 ( V_9 ) ;
F_14 ( V_93 , F_45 ( V_9 ) , V_66 ) ;
} else {
if ( ( V_66 -> V_68 & V_94 ) == V_69 ) {
goto V_95;
}
if ( V_66 -> V_68 & V_69 ) {
* V_92 = FALSE ;
}
return V_66 ;
}
V_95:
if ( V_96 . V_97 && V_96 . V_98 ) {
V_66 -> V_68 |= V_99 ;
#ifdef F_46
if ( V_96 . V_100 &&
V_101 > 0 &&
V_102 ) {
F_3 ( V_87 , V_9 ) ;
F_36 ( V_9 , V_66 ) ;
return V_66 ;
}
#elif F_47 ( V_103 )
if ( V_9 != 0 ) {
struct V_104 sin ;
memset ( & sin , 0 , sizeof( sin ) ) ;
sin . V_105 = V_87 ;
sin . V_106 . V_107 = V_9 ;
if ( F_48 ( (struct V_108 * ) & sin , sizeof( sin ) ,
V_66 -> V_55 , sizeof( V_66 -> V_55 ) ,
NULL , 0 , V_109 ) == 0 ) {
return V_66 ;
}
}
#elif F_47 ( V_110 )
if ( V_9 != 0 ) {
struct V_81 * V_111 ;
V_111 = F_49 ( ( const char * ) & V_9 , 4 , V_87 ) ;
if ( V_111 != NULL && V_111 -> V_88 [ 0 ] != '\0' ) {
F_50 ( V_66 -> V_55 , V_111 -> V_88 , V_54 ) ;
return V_66 ;
}
}
#endif
}
* V_92 = FALSE ;
F_36 ( V_9 , V_66 ) ;
return V_66 ;
}
static T_17 *
F_51 ( const struct V_8 * V_9 )
{
T_17 * V_66 = F_4 ( T_17 , 1 ) ;
V_66 -> V_9 = * V_9 ;
V_66 -> V_68 = 0 ;
V_66 -> V_55 [ 0 ] = '\0' ;
F_52 ( V_9 , V_66 -> V_90 ) ;
return V_66 ;
}
static T_17 *
F_53 ( const struct V_8 * V_9 , T_3 * V_92 )
{
T_17 * volatile V_66 ;
#ifdef F_54
#ifdef F_5
T_4 * V_83 ;
#elif F_47 ( V_103 )
struct V_112 V_113 ;
#elif F_47 ( V_110 )
struct V_81 * V_111 ;
#endif
#endif
* V_92 = TRUE ;
V_66 = ( T_17 * ) F_12 ( V_114 , V_9 ) ;
if ( V_66 == NULL ) {
struct V_8 * V_115 ;
V_115 = F_4 ( struct V_8 , 1 ) ;
V_66 = F_51 ( V_9 ) ;
memcpy ( V_115 , V_9 , 16 ) ;
F_14 ( V_114 , V_115 , V_66 ) ;
} else {
if ( ( V_66 -> V_68 & V_94 ) == V_69 ) {
goto V_95;
}
if ( V_66 -> V_68 & V_69 ) {
* V_92 = FALSE ;
}
return V_66 ;
}
V_95:
if ( V_96 . V_97 &&
V_96 . V_98 ) {
V_66 -> V_68 |= V_99 ;
#ifdef F_54
#ifdef F_5
if ( ( V_96 . V_100 ) &&
V_101 > 0 &&
V_102 ) {
V_83 = F_4 ( T_4 , 1 ) ;
V_83 -> V_11 = V_89 ;
memcpy ( & V_83 -> V_9 . V_90 , V_9 , sizeof( V_83 -> V_9 . V_90 ) ) ;
V_15 = F_6 ( V_15 , ( V_16 ) V_83 ) ;
if ( ( V_66 -> V_68 & V_69 ) == 0 ) {
F_50 ( V_66 -> V_55 , V_66 -> V_90 , V_54 ) ;
F_52 ( V_9 , V_66 -> V_55 ) ;
V_66 -> V_68 |= V_69 ;
}
return V_66 ;
}
#elif F_47 ( V_103 )
memset ( & V_113 , 0 , sizeof( V_113 ) ) ;
V_113 . V_116 = V_89 ;
memcpy ( V_113 . V_117 . V_118 , V_9 , sizeof( * V_9 ) ) ;
if ( F_48 ( (struct V_108 * ) & V_113 , sizeof( V_113 ) ,
V_66 -> V_55 , sizeof( V_66 -> V_55 ) ,
NULL , 0 , V_109 ) == 0 ) {
return V_66 ;
}
#elif F_47 ( V_110 )
V_111 = F_49 ( ( const char * ) V_9 , sizeof( * V_9 ) , V_89 ) ;
if ( V_111 != NULL && V_111 -> V_88 [ 0 ] != '\0' ) {
F_50 ( V_66 -> V_55 , V_111 -> V_88 , V_54 ) ;
return V_66 ;
}
#endif
#endif
}
if ( ( V_66 -> V_68 & V_69 ) == 0 ) {
V_66 -> V_68 |= V_69 ;
F_50 ( V_66 -> V_55 , V_66 -> V_90 , V_54 ) ;
}
* V_92 = FALSE ;
return V_66 ;
}
static T_3
F_55 ( const char * V_37 , T_18 * V_119 , unsigned int * V_70 ,
const T_3 V_120 )
{
int V_5 ;
unsigned long V_121 ;
char * V_3 ;
char V_122 = '\0' ;
for ( V_5 = 0 ; V_5 < 6 ; V_5 ++ ) {
if ( ! F_56 ( * V_37 ) )
return FALSE ;
V_121 = strtoul ( V_37 , & V_3 , 16 ) ;
if ( V_3 == V_37 )
return FALSE ;
if ( V_121 > 0xFF )
return FALSE ;
V_119 -> V_9 [ V_5 ] = ( V_75 ) V_121 ;
V_37 = V_3 ;
if ( * V_37 == '/' ) {
if ( ! V_120 ) {
return FALSE ;
}
V_37 ++ ;
if ( ! F_57 ( * V_37 ) )
return FALSE ;
V_121 = strtoul ( V_37 , & V_3 , 10 ) ;
if ( V_3 == V_37 )
return FALSE ;
V_37 = V_3 ;
if ( * V_37 != '\0' && ! F_58 ( * V_37 ) )
return FALSE ;
if ( V_121 == 0 || V_121 >= 48 )
return FALSE ;
* V_70 = ( int ) V_121 ;
for ( V_5 = 0 ; V_121 >= 8 ; V_5 ++ , V_121 -= 8 )
;
V_119 -> V_9 [ V_5 ] &= ( 0xFF << ( 8 - V_121 ) ) ;
V_5 ++ ;
for (; V_5 < 6 ; V_5 ++ )
V_119 -> V_9 [ V_5 ] = 0 ;
return TRUE ;
}
if ( * V_37 == '\0' ) {
if ( V_5 == 2 ) {
if ( ! V_120 ) {
return FALSE ;
}
* V_70 = 0 ;
return TRUE ;
}
if ( V_5 == 5 ) {
if ( V_120 )
* V_70 = 48 ;
return TRUE ;
}
return FALSE ;
} else {
if ( V_122 == '\0' ) {
if ( * V_37 != ':' && * V_37 != '-' && * V_37 != '.' )
return FALSE ;
V_122 = * V_37 ;
} else {
if ( * V_37 != V_122 )
return FALSE ;
}
}
V_37 ++ ;
}
return TRUE ;
}
static int
F_59 ( char * line , T_18 * V_119 , unsigned int * V_70 ,
const T_3 V_120 )
{
T_9 * V_37 ;
if ( ( V_37 = strchr ( line , '#' ) ) )
* V_37 = '\0' ;
if ( ( V_37 = strtok ( line , L_1 ) ) == NULL )
return - 1 ;
if ( ! F_55 ( V_37 , V_119 , V_70 , V_120 ) )
return - 1 ;
if ( ( V_37 = strtok ( NULL , L_1 ) ) == NULL )
return - 1 ;
F_50 ( V_119 -> V_55 , V_37 , V_54 ) ;
return 0 ;
}
static void
F_60 ( char * V_50 )
{
if ( V_123 )
rewind ( V_123 ) ;
else
V_123 = F_21 ( V_50 , L_7 ) ;
}
static void
F_61 ( void )
{
if ( V_123 ) {
fclose ( V_123 ) ;
V_123 = NULL ;
}
}
static T_18 *
F_62 ( unsigned int * V_70 , const T_3 V_120 )
{
static T_18 V_119 ;
static int V_18 = 0 ;
static char * V_17 = NULL ;
if ( V_123 == NULL )
return NULL ;
while ( F_7 ( & V_17 , & V_18 , V_123 ) >= 0 ) {
if ( F_59 ( V_17 , & V_119 , V_70 , V_120 ) == 0 ) {
return & V_119 ;
}
}
return NULL ;
}
static T_18 *
F_63 ( const V_75 * V_9 )
{
T_18 * V_119 ;
F_60 ( V_124 ) ;
while ( ( ( V_119 = F_62 ( NULL , FALSE ) ) != NULL ) && memcmp ( V_9 , V_119 -> V_9 , 6 ) != 0 )
;
if ( V_119 == NULL ) {
F_61 () ;
F_60 ( V_125 ) ;
while ( ( ( V_119 = F_62 ( NULL , FALSE ) ) != NULL ) && memcmp ( V_9 , V_119 -> V_9 , 6 ) != 0 )
;
F_61 () ;
}
return V_119 ;
}
static T_19 * F_64 ( const V_75 * V_9 , char * V_55 )
{
int * V_126 ;
T_19 * V_127 ;
char * V_128 ;
V_126 = ( int * ) F_4 ( int , 1 ) ;
* V_126 = ( int ) ( ( V_9 [ 0 ] << 16 ) + ( V_9 [ 1 ] << 8 ) + V_9 [ 2 ] ) ;
V_127 = F_4 ( T_19 , 1 ) ;
memcpy ( V_127 -> V_9 , V_9 , 3 ) ;
V_127 -> V_78 = ( V_55 != NULL ) ? V_129 : V_130 ;
if ( V_55 != NULL ) {
F_50 ( V_127 -> V_131 , V_55 , V_54 ) ;
V_127 -> V_78 = V_129 ;
}
else {
V_127 -> V_78 = V_130 ;
V_127 -> V_131 [ 0 ] = '\0' ;
}
V_128 = F_65 ( V_127 -> V_132 , V_9 , sizeof( V_127 -> V_9 ) , ':' ) ;
* V_128 = '\0' ;
F_14 ( V_133 , V_126 , V_127 ) ;
return V_127 ;
}
static void
F_66 ( const V_75 * V_9 , unsigned int V_70 , T_9 * V_55 )
{
V_75 * V_134 ;
if ( V_70 >= 48 ) {
F_67 ( V_9 , V_55 ) ;
return;
}
if ( V_70 == 0 ) {
F_64 ( V_9 , V_55 ) ;
return;
}
V_134 = ( V_75 * ) F_8 ( 6 ) ;
memcpy ( V_134 , V_9 , 6 ) ;
F_14 ( V_135 , V_134 , F_16 ( V_55 ) ) ;
}
static T_19 *
F_68 ( const V_75 * V_9 )
{
T_20 V_126 = 0 ;
V_75 V_136 ;
T_19 * V_127 ;
V_126 = V_9 [ 0 ] ;
V_126 = V_126 << 8 ;
V_136 = V_9 [ 1 ] ;
V_126 = V_126 | V_136 ;
V_126 = V_126 << 8 ;
V_136 = V_9 [ 2 ] ;
V_126 = V_126 | V_136 ;
V_127 = ( T_19 * ) F_12 ( V_133 , & V_126 ) ;
if ( V_127 != NULL ) {
return V_127 ;
}
if ( ( V_126 & 0x00010000 ) != 0 ) {
V_126 &= 0x00FEFFFF ;
V_127 = ( T_19 * ) F_12 ( V_133 , & V_126 ) ;
if ( V_127 != NULL ) {
return V_127 ;
}
}
return F_64 ( V_9 , NULL ) ;
}
static T_9 *
F_69 ( const V_75 * V_9 , const unsigned int V_70 )
{
V_75 V_137 [ 6 ] ;
T_7 V_121 ;
T_21 V_5 ;
T_9 * V_55 ;
if ( V_135 == NULL ) {
return NULL ;
}
for ( V_5 = 0 , V_121 = V_70 ; V_121 >= 8 ; V_5 ++ , V_121 -= 8 )
V_137 [ V_5 ] = V_9 [ V_5 ] ;
V_137 [ V_5 ] = V_9 [ V_5 ] & ( 0xFF << ( 8 - V_121 ) ) ;
V_5 ++ ;
for (; V_5 < 6 ; V_5 ++ )
V_137 [ V_5 ] = 0 ;
V_55 = ( T_9 * ) F_12 ( V_135 , V_137 ) ;
return V_55 ;
}
T_7 F_70 ( T_22 * V_138 )
{
return V_138 -> V_78 ;
}
char * F_71 ( T_22 * V_138 )
{
return V_138 -> V_132 ;
}
char * F_72 ( T_22 * V_138 )
{
return V_138 -> V_131 ;
}
static T_7
F_73 ( T_2 V_1 )
{
return F_74 ( ( const V_75 * ) V_1 , 6 ) ;
}
static T_3
F_75 ( T_2 V_139 , T_2 V_140 )
{
return ( memcmp ( V_139 , V_140 , 6 ) == 0 ) ;
}
static void
F_76 ( void )
{
T_18 * V_119 ;
char * V_141 ;
T_7 V_70 = 0 ;
V_135 = F_29 ( F_73 , F_75 , F_15 , F_15 ) ;
V_133 = F_29 ( V_61 , V_62 , F_15 , F_15 ) ;
V_142 = F_29 ( F_73 , F_75 , NULL , F_15 ) ;
if ( V_125 == NULL ) {
V_125 = F_77 ( L_12 V_143 L_12 ,
F_78 () , V_144 ) ;
}
if ( V_124 == NULL )
V_124 = F_32 ( V_144 , FALSE ) ;
V_141 = F_33 ( V_145 ) ;
F_60 ( V_141 ) ;
while ( ( V_119 = F_62 ( & V_70 , TRUE ) ) ) {
F_66 ( V_119 -> V_9 , V_70 , V_119 -> V_55 ) ;
}
F_61 () ;
F_15 ( V_141 ) ;
}
static void
F_79 ( void )
{
if ( V_133 ) {
F_35 ( V_133 ) ;
V_133 = NULL ;
}
if ( V_135 ) {
F_35 ( V_135 ) ;
V_135 = NULL ;
}
if ( V_142 ) {
F_35 ( V_142 ) ;
V_142 = NULL ;
}
}
static T_22 *
F_80 ( T_22 * V_66 ) {
T_18 * V_119 ;
T_19 * V_127 ;
const V_75 * V_9 = V_66 -> V_9 ;
if ( ( V_119 = F_63 ( V_9 ) ) != NULL ) {
F_50 ( V_66 -> V_131 , V_119 -> V_55 , V_54 ) ;
V_66 -> V_78 = V_129 ;
return V_66 ;
} else {
T_7 V_70 ;
T_9 * V_55 ;
T_23 V_146 ;
V_70 = 7 ;
for (; ; ) {
if ( ( V_55 = F_69 ( V_9 , V_70 + 40 ) ) != NULL ) {
F_39 ( V_66 -> V_131 , V_54 , L_13 ,
V_55 , V_9 [ 5 ] & ( 0xFF >> V_70 ) ) ;
V_66 -> V_78 = V_147 ;
return V_66 ;
}
if ( V_70 == 0 )
break;
V_70 -- ;
}
V_70 = 7 ;
for (; ; ) {
if ( ( V_55 = F_69 ( V_9 , V_70 + 32 ) ) != NULL ) {
F_39 ( V_66 -> V_131 , V_54 , L_14 ,
V_55 , V_9 [ 4 ] & ( 0xFF >> V_70 ) , V_9 [ 5 ] ) ;
V_66 -> V_78 = V_147 ;
return V_66 ;
}
if ( V_70 == 0 )
break;
V_70 -- ;
}
V_70 = 7 ;
for (; ; ) {
if ( ( V_55 = F_69 ( V_9 , V_70 + 24 ) ) != NULL ) {
F_39 ( V_66 -> V_131 , V_54 , L_15 ,
V_55 , V_9 [ 3 ] & ( 0xFF >> V_70 ) , V_9 [ 4 ] , V_9 [ 5 ] ) ;
V_66 -> V_78 = V_147 ;
return V_66 ;
}
if ( V_70 == 0 )
break;
V_70 -- ;
}
V_127 = F_68 ( V_9 ) ;
if ( ( V_127 != NULL ) && ( V_127 -> V_78 != V_130 ) ) {
F_39 ( V_66 -> V_131 , V_54 , L_15 ,
V_127 -> V_131 , V_9 [ 3 ] , V_9 [ 4 ] , V_9 [ 5 ] ) ;
V_66 -> V_78 = V_147 ;
return V_66 ;
}
V_70 = 7 ;
for (; ; ) {
if ( ( V_55 = F_69 ( V_9 , V_70 + 16 ) ) != NULL ) {
F_39 ( V_66 -> V_131 , V_54 , L_16 ,
V_55 , V_9 [ 2 ] & ( 0xFF >> V_70 ) , V_9 [ 3 ] , V_9 [ 4 ] ,
V_9 [ 5 ] ) ;
V_66 -> V_78 = V_147 ;
return V_66 ;
}
if ( V_70 == 0 )
break;
V_70 -- ;
}
V_70 = 7 ;
for (; ; ) {
if ( ( V_55 = F_69 ( V_9 , V_70 + 8 ) ) != NULL ) {
F_39 ( V_66 -> V_131 , V_54 , L_17 ,
V_55 , V_9 [ 1 ] & ( 0xFF >> V_70 ) , V_9 [ 2 ] , V_9 [ 3 ] ,
V_9 [ 4 ] , V_9 [ 5 ] ) ;
V_66 -> V_78 = V_147 ;
return V_66 ;
}
if ( V_70 == 0 )
break;
V_70 -- ;
}
for ( V_70 = 7 ; V_70 > 0 ; V_70 -- ) {
if ( ( V_55 = F_69 ( V_9 , V_70 ) ) != NULL ) {
F_39 ( V_66 -> V_131 , V_54 , L_18 ,
V_55 , V_9 [ 0 ] & ( 0xFF >> V_70 ) , V_9 [ 1 ] , V_9 [ 2 ] ,
V_9 [ 3 ] , V_9 [ 4 ] , V_9 [ 5 ] ) ;
V_66 -> V_78 = V_147 ;
return V_66 ;
}
}
F_81 ( & V_146 , V_148 , 6 , V_9 ) ;
F_82 ( & V_146 , V_66 -> V_131 , V_54 ) ;
V_66 -> V_78 = V_147 ;
return V_66 ;
}
F_83 () ;
}
static T_22 *
F_84 ( const V_75 * V_9 , const T_3 V_149 )
{
T_22 * V_66 ;
char * V_128 ;
V_66 = F_4 ( T_22 , 1 ) ;
memcpy ( V_66 -> V_9 , V_9 , sizeof( V_66 -> V_9 ) ) ;
V_66 -> V_78 = V_130 ;
V_128 = F_65 ( V_66 -> V_132 , V_9 , sizeof( V_66 -> V_9 ) , ':' ) ;
* V_128 = '\0' ;
V_66 -> V_131 [ 0 ] = '\0' ;
if ( V_149 )
F_80 ( V_66 ) ;
F_14 ( V_142 , V_66 -> V_9 , V_66 ) ;
return V_66 ;
}
static T_22 *
F_67 ( const V_75 * V_9 , const T_9 * V_55 )
{
T_22 * V_66 ;
V_66 = ( T_22 * ) F_12 ( V_142 , V_9 ) ;
if ( V_66 == NULL ) {
V_66 = F_84 ( V_9 , FALSE ) ;
}
F_50 ( V_66 -> V_131 , V_55 , V_54 ) ;
V_66 -> V_78 = V_129 ;
V_36 = TRUE ;
return V_66 ;
}
static T_22 *
F_85 ( const V_75 * V_9 , const T_3 V_149 )
{
T_22 * V_66 ;
V_66 = ( T_22 * ) F_12 ( V_142 , V_9 ) ;
if ( V_66 == NULL ) {
V_66 = F_84 ( V_9 , V_149 ) ;
} else {
if ( V_149 && ( V_66 -> V_78 == V_130 ) ) {
F_80 ( V_66 ) ;
}
}
return V_66 ;
}
static V_75 *
F_86 ( const T_9 * V_55 V_82 )
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
F_87 ( char * line , T_24 * V_150 )
{
T_9 * V_37 ;
T_1 V_139 , V_151 , V_152 , V_153 , V_154 ;
T_3 V_155 = FALSE ;
if ( ( V_37 = strchr ( line , '#' ) ) )
* V_37 = '\0' ;
if ( ( V_37 = strtok ( line , L_19 ) ) == NULL )
return - 1 ;
if ( sscanf ( V_37 , L_20 , & V_151 , & V_152 , & V_153 , & V_154 ) != 4 ) {
if ( sscanf ( V_37 , L_21 , & V_151 , & V_152 , & V_153 , & V_154 ) != 4 ) {
if ( sscanf ( V_37 , L_22 , & V_151 , & V_152 , & V_153 , & V_154 ) != 4 ) {
if ( sscanf ( V_37 , L_23 , & V_139 ) == 1 ) {
V_155 = TRUE ;
}
else {
return - 1 ;
}
}
}
}
if ( ( V_37 = strtok ( NULL , L_19 ) ) == NULL )
return - 1 ;
if ( V_155 ) {
V_150 -> V_9 = V_139 ;
}
else {
V_150 -> V_9 = ( V_151 << 24 ) | ( V_152 << 16 ) | ( V_153 << 8 ) | V_154 ;
}
F_50 ( V_150 -> V_55 , V_37 , V_54 ) ;
return 0 ;
}
static void
F_88 ( char * V_50 )
{
if ( V_156 )
rewind ( V_156 ) ;
else
V_156 = F_21 ( V_50 , L_7 ) ;
}
static void
F_89 ( void )
{
if ( V_156 ) {
fclose ( V_156 ) ;
V_156 = NULL ;
}
}
static T_24 *
F_90 ( void )
{
static T_24 V_150 ;
static int V_18 = 0 ;
static char * V_17 = NULL ;
if ( V_156 == NULL )
return NULL ;
while ( F_7 ( & V_17 , & V_18 , V_156 ) >= 0 ) {
if ( F_87 ( V_17 , & V_150 ) == 0 ) {
return & V_150 ;
}
}
return NULL ;
}
static T_24 *
F_91 ( T_1 V_9 )
{
T_24 * V_150 ;
F_88 ( V_157 ) ;
while ( ( ( V_150 = F_90 () ) != NULL ) && ( V_9 != V_150 -> V_9 ) ) ;
if ( V_150 == NULL ) {
F_89 () ;
F_88 ( V_158 ) ;
while ( ( ( V_150 = F_90 () ) != NULL ) && ( V_9 != V_150 -> V_9 ) )
;
F_89 () ;
}
return V_150 ;
}
static void
F_92 ( void )
{
if ( V_157 == NULL ) {
V_157 = F_77 ( L_12 V_143 L_12 ,
F_78 () , V_159 ) ;
}
if ( V_158 == NULL )
V_158 = F_32 ( V_159 , FALSE ) ;
}
static void
F_93 ( void )
{
if ( V_160 ) {
F_35 ( V_160 ) ;
V_160 = NULL ;
}
}
static T_9 *
F_94 ( T_11 * V_52 , const T_7 V_9 )
{
T_25 * V_66 ;
T_24 * V_150 ;
V_66 = ( T_25 * ) F_12 ( V_160 , & V_9 ) ;
if ( V_66 == NULL ) {
int * V_1 ;
V_1 = ( int * ) F_4 ( int , 1 ) ;
* V_1 = V_9 ;
V_66 = F_4 ( T_25 , 1 ) ;
F_14 ( V_160 , V_1 , V_66 ) ;
} else {
return F_95 ( V_52 , V_66 -> V_55 ) ;
}
V_66 -> V_9 = V_9 ;
if ( ( V_150 = F_91 ( V_9 ) ) == NULL ) {
F_39 ( V_66 -> V_55 , V_54 , L_24 , V_9 ) ;
} else {
F_50 ( V_66 -> V_55 , V_150 -> V_55 , V_54 ) ;
}
return F_95 ( V_52 , V_66 -> V_55 ) ;
}
static T_7
F_96 ( const T_9 * V_55 V_82 , T_3 * V_161 )
{
* V_161 = FALSE ;
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
F_97 ( const char * V_58 , T_3 V_162 )
{
T_5 * V_163 ;
char * line = NULL ;
int V_18 = 0 ;
T_9 * V_37 ;
T_1 V_71 [ 4 ] ;
struct V_8 V_164 ;
T_3 V_165 , V_166 = FALSE ;
int V_167 ;
if ( ( V_163 = F_21 ( V_58 , L_7 ) ) == NULL )
return FALSE ;
while ( F_7 ( & line , & V_18 , V_163 ) >= 0 ) {
if ( ( V_37 = strchr ( line , '#' ) ) )
* V_37 = '\0' ;
if ( ( V_37 = strtok ( line , L_1 ) ) == NULL )
continue;
V_167 = F_98 ( V_89 , V_37 , & V_71 ) ;
if ( V_167 < 0 )
continue;
if ( V_167 > 0 ) {
V_165 = TRUE ;
} else {
if ( ! F_99 ( V_37 , & V_71 ) )
continue;
V_165 = FALSE ;
}
if ( ( V_37 = strtok ( NULL , L_1 ) ) == NULL )
continue;
V_166 = TRUE ;
if ( V_162 ) {
if ( V_165 ) {
memcpy ( & V_164 , V_71 , sizeof V_164 ) ;
F_42 ( & V_164 , V_37 ) ;
} else
F_41 ( V_71 [ 0 ] , V_37 ) ;
#if 0
while ((cp = strtok(NULL, " \t")) != NULL) {
if (is_ipv6) {
memcpy(&ip6_addr, host_addr, sizeof ip6_addr);
add_ipv6_name(&ip6_addr, cp);
} else
add_ipv4_name(host_addr[0], cp);
}
#endif
}
}
F_15 ( line ) ;
fclose ( V_163 ) ;
return V_166 ? TRUE : FALSE ;
}
T_3
F_100 ( const char * V_168 )
{
T_3 V_92 = FALSE ;
T_7 V_5 ;
if ( ! V_168 )
return FALSE ;
if ( ! V_169 )
V_169 = F_101 () ;
for ( V_5 = 0 ; V_5 < V_169 -> V_2 ; V_5 ++ ) {
if ( strcmp ( V_168 , ( const char * ) F_102 ( V_169 , V_5 ) ) == 0 )
V_92 = TRUE ;
}
if ( ! V_92 ) {
F_103 ( V_169 , F_16 ( V_168 ) ) ;
return F_97 ( V_168 , FALSE ) ;
}
return TRUE ;
}
T_3
F_104 ( const char * V_9 , const char * V_55 )
{
T_1 V_71 [ 4 ] ;
struct V_8 V_164 ;
T_3 V_165 ;
int V_167 ;
T_26 * V_170 ;
T_27 * V_171 ;
V_167 = F_98 ( V_89 , V_9 , & V_164 ) ;
if ( V_167 < 0 )
return FALSE ;
if ( V_167 > 0 ) {
V_165 = TRUE ;
} else {
if ( ! F_99 ( V_9 , & V_71 ) )
return FALSE ;
V_165 = FALSE ;
}
if ( V_165 ) {
V_171 = F_4 ( T_27 , 1 ) ;
memcpy ( & ( V_171 -> V_164 ) , & V_164 , 16 ) ;
F_50 ( V_171 -> V_55 , V_55 , V_54 ) ;
V_172 = F_105 ( V_172 , V_171 ) ;
} else {
V_170 = F_4 ( T_26 , 1 ) ;
V_170 -> V_71 = V_71 [ 0 ] ;
F_50 ( V_170 -> V_55 , V_55 , V_54 ) ;
V_173 = F_105 ( V_173 , V_170 ) ;
}
return TRUE ;
}
static void
F_106 ( V_16 V_1 V_82 , V_16 V_174 , V_16 V_175 )
{
T_28 * V_176 = ( T_28 * ) V_175 ;
T_12 * V_177 = ( T_12 * ) V_174 ;
if ( ( V_177 -> V_68 & V_178 ) == V_179 ) {
V_176 -> V_180 = F_107 ( V_176 -> V_180 , V_177 ) ;
}
}
static void
F_108 ( V_16 V_1 V_82 , V_16 V_174 , V_16 V_175 )
{
T_28 * V_176 = ( T_28 * ) V_175 ;
T_17 * V_181 = ( T_17 * ) V_174 ;
if ( ( V_181 -> V_68 & V_178 ) == V_179 ) {
V_176 -> V_182 = F_107 ( V_176 -> V_182 , V_181 ) ;
}
}
T_28 *
F_109 ( void ) {
if ( V_93 ) {
F_110 ( V_93 , F_106 , & V_183 ) ;
}
if ( V_114 ) {
F_110 ( V_114 , F_108 , & V_183 ) ;
}
return & V_183 ;
}
static T_3
F_111 ( const char * V_184 )
{
T_5 * V_163 ;
char * line = NULL ;
int V_18 = 0 ;
T_9 * V_37 , * V_185 ;
T_1 V_71 ;
int V_76 ;
if ( ( V_163 = F_21 ( V_184 , L_7 ) ) == NULL )
return FALSE ;
while ( F_7 ( & line , & V_18 , V_163 ) >= 0 ) {
if ( ( V_37 = strchr ( line , '#' ) ) )
* V_37 = '\0' ;
if ( ( V_37 = strtok ( line , L_1 ) ) == NULL )
continue;
V_185 = strchr ( V_37 , '/' ) ;
if ( NULL == V_185 ) {
continue;
}
* V_185 = '\0' ;
++ V_185 ;
if ( ! F_99 ( V_37 , & V_71 ) ) {
continue;
}
V_76 = atoi ( V_185 ) ;
if ( 0 >= V_76 || V_76 > 32 ) {
continue;
}
if ( ( V_37 = strtok ( NULL , L_1 ) ) == NULL )
continue;
F_112 ( V_71 , ( T_1 ) V_76 , V_37 ) ;
}
F_15 ( line ) ;
fclose ( V_163 ) ;
return TRUE ;
}
static T_13
F_37 ( const T_1 V_9 )
{
T_13 V_67 ;
T_1 V_5 ;
V_5 = V_186 ;
while( V_187 && V_5 > 0 ) {
T_1 V_137 ;
T_29 * V_188 ;
-- V_5 ;
F_9 ( V_5 < V_186 ) ;
V_188 = & V_189 [ V_5 ] ;
if ( NULL != V_188 -> V_190 ) {
T_30 * V_66 ;
T_1 V_191 ;
V_137 = V_9 & V_188 -> V_70 ;
V_191 = F_113 ( V_137 ) ;
V_66 = V_188 -> V_190 [ V_191 ] ;
while( V_66 != NULL && V_66 -> V_9 != V_137 ) {
V_66 = V_66 -> V_192 ;
}
if ( NULL != V_66 ) {
V_67 . V_70 = V_188 -> V_70 ;
V_67 . V_76 = V_5 + 1 ;
V_67 . V_55 = V_66 -> V_55 ;
return V_67 ;
}
}
}
V_67 . V_70 = 0 ;
V_67 . V_76 = 0 ;
V_67 . V_55 = NULL ;
return V_67 ;
}
static void
F_112 ( T_1 V_193 , const T_1 V_76 , const T_9 * V_55 )
{
T_29 * V_194 ;
T_30 * V_66 ;
T_14 V_191 ;
F_9 ( V_76 > 0 && V_76 <= 32 ) ;
V_194 = & V_189 [ V_76 - 1 ] ;
V_193 &= V_194 -> V_70 ;
V_191 = F_113 ( V_193 ) ;
if ( NULL == V_194 -> V_190 ) {
V_194 -> V_190 = ( T_30 * * ) F_114 ( sizeof( T_30 * ) * V_195 ) ;
}
if ( NULL != ( V_66 = V_194 -> V_190 [ V_191 ] ) ) {
T_30 * V_196 ;
while ( V_66 -> V_192 ) {
if ( V_66 -> V_9 == V_193 ) {
return;
} else {
V_66 = V_66 -> V_192 ;
}
}
V_196 = F_4 ( T_30 , 1 ) ;
V_66 -> V_192 = V_196 ;
V_66 = V_196 ;
} else {
V_66 = V_194 -> V_190 [ V_191 ] = F_4 ( T_30 , 1 ) ;
}
V_66 -> V_192 = NULL ;
V_66 -> V_9 = V_193 ;
V_66 -> V_68 &= ~ V_69 ;
F_50 ( V_66 -> V_55 , V_55 , V_54 ) ;
V_187 = TRUE ;
}
static void
F_115 ( void )
{
T_9 * V_184 ;
T_1 V_5 ;
for( V_5 = 0 ; V_5 < V_186 ; ++ V_5 ) {
T_1 V_197 = V_5 + 1 ;
V_189 [ V_5 ] . V_190 = NULL ;
V_189 [ V_5 ] . V_76 = V_197 ;
V_189 [ V_5 ] . V_70 = F_116 ( F_117 ( V_197 ) ) ;
}
V_184 = F_32 ( V_198 , FALSE ) ;
if ( ! F_111 ( V_184 ) && V_199 != V_200 ) {
F_118 ( V_184 , V_199 , FALSE ) ;
}
F_15 ( V_184 ) ;
V_184 = F_33 ( V_198 ) ;
if ( ! F_111 ( V_184 ) && V_199 != V_200 ) {
F_118 ( V_184 , V_199 , FALSE ) ;
}
F_15 ( V_184 ) ;
}
static void
F_119 ( T_30 * V_194 )
{
if ( ( V_194 != NULL ) && ( V_194 -> V_192 != NULL ) ) {
F_119 ( V_194 -> V_192 ) ;
}
F_15 ( V_194 ) ;
}
void
F_120 ( T_31 * V_201 )
{
F_121 ( V_201 , L_25 ,
L_26 ,
L_27 ,
& V_96 . V_202 ) ;
F_121 ( V_201 , L_28 ,
L_29 ,
L_30 ,
& V_96 . V_203 ) ;
F_121 ( V_201 , L_31 ,
L_32 ,
L_33
L_34
L_35
L_36 ,
& V_96 . V_97 ) ;
F_121 ( V_201 , L_37 ,
L_38 ,
L_39 ,
& V_96 . V_204 ) ;
F_121 ( V_201 , L_40 ,
L_41 ,
L_42
L_43
L_44
L_45 ,
& V_96 . V_98 ) ;
#if F_47 ( F_5 ) || F_47 ( V_205 )
F_121 ( V_201 , L_46 ,
L_47 ,
L_48
L_49
L_50 ,
& V_96 . V_100 ) ;
F_122 ( V_201 , L_51 ,
L_52 ,
L_53
L_54
L_55
L_56 ,
10 ,
& V_101 ) ;
#else
F_123 ( V_201 , L_46 ,
L_57 ,
L_58
L_59 ) ;
#endif
F_121 ( V_201 , L_60 ,
L_61 ,
L_62
L_63 ,
& V_96 . V_206 ) ;
}
void
F_124 ( void ) {
V_96 . V_202 = FALSE ;
V_96 . V_97 = FALSE ;
V_96 . V_203 = FALSE ;
V_96 . V_100 = FALSE ;
V_96 . V_204 = FALSE ;
V_96 . V_98 = FALSE ;
}
T_3
F_125 ( void ) {
T_4 * V_83 ;
struct V_207 V_208 = { 0 , 0 } ;
int V_209 ;
T_32 V_210 , V_211 ;
T_3 V_212 = V_36 ;
V_36 = FALSE ;
if ( ! V_102 )
return V_212 ;
V_15 = F_126 ( V_15 ) ;
while ( V_15 != NULL && V_84 <= V_101 ) {
V_83 = ( T_4 * ) V_15 -> V_56 ;
V_15 = F_127 ( V_15 , ( void * ) V_83 ) ;
if ( V_83 -> V_11 == V_87 ) {
F_128 ( V_213 , & V_83 -> V_9 . V_12 , sizeof( T_1 ) , V_87 ,
F_40 , V_83 ) ;
V_84 ++ ;
} else if ( V_83 -> V_11 == V_89 ) {
F_128 ( V_213 , & V_83 -> V_9 . V_90 , sizeof( struct V_8 ) ,
V_89 , F_40 , V_83 ) ;
V_84 ++ ;
}
}
F_129 ( & V_210 ) ;
F_129 ( & V_211 ) ;
V_209 = F_130 ( V_213 , & V_210 , & V_211 ) ;
if ( V_209 > 0 ) {
if ( F_131 ( V_209 , & V_210 , & V_211 , NULL , & V_208 ) == - 1 ) {
fprintf ( V_214 , L_64 , F_132 ( V_199 ) ) ;
return V_212 ;
}
F_133 ( V_213 , & V_210 , & V_211 ) ;
}
return V_212 ;
}
static void
F_134 ( void ) {
T_33 * V_215 ;
V_215 = F_126 ( V_15 ) ;
while ( V_215 ) {
F_15 ( V_215 -> V_56 ) ;
V_215 = F_135 ( V_215 ) ;
}
F_136 ( V_15 ) ;
V_15 = NULL ;
if ( V_102 ) {
F_137 ( V_213 ) ;
F_137 ( V_216 ) ;
}
#ifdef F_138
F_139 () ;
#endif
V_102 = FALSE ;
}
T_3
F_125 ( void ) {
T_4 * V_217 ;
T_33 * V_215 ;
char V_218 [] = L_65 ;
V_75 * V_219 ;
T_34 * V_220 ;
int V_167 ;
T_3 V_221 ;
T_3 V_212 = V_36 ;
V_36 = FALSE ;
V_15 = F_126 ( V_15 ) ;
V_215 = V_15 ;
while ( V_215 && V_84 <= V_101 ) {
V_217 = ( T_4 * ) V_215 -> V_56 ;
if ( ! V_217 -> V_14 && V_217 -> type == V_87 ) {
V_219 = ( V_75 * ) & V_217 -> V_13 ;
F_39 ( V_218 , sizeof V_218 , L_66 , V_219 [ 3 ] ,
V_219 [ 2 ] , V_219 [ 1 ] , V_219 [ 0 ] ) ;
F_140 ( V_222 , V_218 , V_223 , V_224 , NULL , & V_217 -> V_225 ) ;
V_217 -> V_14 = TRUE ;
V_84 ++ ;
}
V_215 = V_215 -> V_192 ;
}
V_215 = V_15 ;
while ( V_215 ) {
V_221 = FALSE ;
V_217 = ( T_4 * ) V_215 -> V_56 ;
if ( V_217 -> V_14 ) {
V_167 = F_141 ( V_222 , & V_217 -> V_225 , & V_220 , NULL ) ;
if ( V_167 == 0 ) {
if ( V_220 -> V_78 == V_226 ) {
F_41 ( V_217 -> V_13 , * V_220 -> V_227 . V_228 ) ;
}
V_221 = TRUE ;
}
}
V_215 = V_215 -> V_192 ;
if ( V_221 ) {
V_15 = F_127 ( V_15 , ( void * ) V_217 ) ;
F_15 ( V_217 ) ;
V_84 -- ;
}
}
return V_212 ;
}
static void
F_134 ( void ) {
void * V_229 ;
V_15 = F_126 ( V_15 ) ;
while ( V_15 ) {
V_229 = V_15 -> V_56 ;
V_15 = F_127 ( V_15 , V_229 ) ;
F_15 ( V_229 ) ;
}
if ( V_102 )
F_142 ( V_222 ) ;
V_102 = FALSE ;
}
T_3
F_125 ( void ) {
T_3 V_212 = V_36 ;
V_36 = FALSE ;
return V_212 ;
}
static void
F_134 ( void ) {
}
const T_9 *
F_143 ( const T_7 V_9 )
{
T_3 V_92 ;
T_12 * V_66 = F_44 ( V_9 , & V_92 ) ;
if ( ! V_96 . V_97 )
return V_66 -> V_91 ;
V_66 -> V_68 |= V_179 ;
return V_66 -> V_55 ;
}
const T_9 *
F_144 ( const struct V_8 * V_9 )
{
T_3 V_92 ;
T_17 * V_66 = F_53 ( V_9 , & V_92 ) ;
if ( ! V_96 . V_97 )
return V_66 -> V_90 ;
V_66 -> V_68 |= V_179 ;
return V_66 -> V_55 ;
}
void
F_41 ( const T_7 V_9 , const T_9 * V_55 )
{
T_12 * V_66 ;
if ( ! V_55 || V_55 [ 0 ] == '\0' )
return;
V_66 = ( T_12 * ) F_12 ( V_93 , F_45 ( V_9 ) ) ;
if ( ! V_66 ) {
V_66 = F_43 ( V_9 ) ;
F_14 ( V_93 , F_45 ( V_9 ) , V_66 ) ;
}
if ( F_145 ( V_66 -> V_55 , V_55 ) ) {
F_50 ( V_66 -> V_55 , V_55 , V_54 ) ;
V_36 = TRUE ;
}
V_66 -> V_68 |= V_99 ;
}
void
F_42 ( const struct V_8 * V_230 , const T_9 * V_55 )
{
T_17 * V_66 ;
if ( ! V_55 || V_55 [ 0 ] == '\0' )
return;
V_66 = ( T_17 * ) F_12 ( V_114 , V_230 ) ;
if ( ! V_66 ) {
struct V_8 * V_115 ;
V_115 = F_4 ( struct V_8 , 1 ) ;
V_66 = F_51 ( V_230 ) ;
memcpy ( V_115 , V_230 , 16 ) ;
F_14 ( V_114 , V_115 , V_66 ) ;
}
if ( F_145 ( V_66 -> V_55 , V_55 ) ) {
F_50 ( V_66 -> V_55 , V_55 , V_54 ) ;
V_36 = TRUE ;
}
V_66 -> V_68 |= V_99 ;
}
static void
F_146 ( V_16 V_56 , V_16 V_175 V_82 )
{
T_26 * V_170 = ( T_26 * ) V_56 ;
F_41 ( V_170 -> V_71 , V_170 -> V_55 ) ;
}
static void
F_147 ( V_16 V_56 , V_16 V_175 V_82 )
{
T_27 * V_171 = ( T_27 * ) V_56 ;
F_42 ( & ( V_171 -> V_164 ) , V_171 -> V_55 ) ;
}
static void
F_148 ( void )
{
if ( V_173 ) {
F_149 ( V_173 , F_146 , NULL ) ;
}
if ( V_172 ) {
F_149 ( V_172 , F_147 , NULL ) ;
}
}
void
F_150 ( void )
{
char * V_58 ;
T_7 V_5 ;
#ifdef V_205
#ifdef F_28
char * V_59 ;
static char V_60 [] = L_67 ;
static char V_231 [] = L_68 ;
#endif
#endif
F_9 ( V_160 == NULL ) ;
V_160 = F_29 ( V_61 , V_62 , F_15 , F_15 ) ;
F_9 ( V_93 == NULL ) ;
V_93 = F_29 ( V_232 , V_233 , NULL , F_15 ) ;
F_9 ( V_114 == NULL ) ;
V_114 = F_29 ( F_1 , F_2 , F_15 , F_15 ) ;
if ( ! V_96 . V_206 ) {
V_58 = F_33 ( V_234 ) ;
if ( ! F_97 ( V_58 , TRUE ) && V_199 != V_200 ) {
F_118 ( V_58 , V_199 , FALSE ) ;
}
F_15 ( V_58 ) ;
}
V_58 = F_32 ( V_234 , TRUE ) ;
if ( ! F_97 ( V_58 , TRUE ) && V_199 != V_200 ) {
F_118 ( V_58 , V_199 , FALSE ) ;
}
F_15 ( V_58 ) ;
#ifdef F_5
if ( V_96 . V_100 ) {
#ifdef F_138
if ( F_151 ( V_235 ) == V_85 ) {
#endif
if ( F_152 ( & V_213 ) == V_85 && F_152 ( & V_216 ) == V_85 ) {
V_102 = TRUE ;
}
#ifdef F_138
}
#endif
}
#else
#ifdef V_205
#ifdef F_28
V_59 = F_30 ( L_9 ) ;
if ( V_59 != NULL ) {
if ( ! V_96 . V_206 ) {
V_58 = F_31 ( V_59 , V_60 , NULL ) ;
if ( ! F_97 ( V_58 , TRUE ) ) {
F_15 ( V_58 ) ;
V_58 = F_31 ( V_59 , V_231 , NULL ) ;
F_97 ( V_58 , TRUE ) ;
}
F_15 ( V_58 ) ;
}
}
#else
if ( ! V_96 . V_206 ) {
F_97 ( L_69 , TRUE ) ;
}
#endif
if ( V_96 . V_100 ) {
if ( F_153 ( & V_222 , V_236 , 0 ) != 0 ) {
return;
}
V_102 = TRUE ;
V_84 = 0 ;
}
#endif
#endif
if ( V_169 && ! V_96 . V_206 ) {
for ( V_5 = 0 ; V_5 < V_169 -> V_2 ; V_5 ++ ) {
F_97 ( ( const char * ) F_102 ( V_169 , V_5 ) , TRUE ) ;
}
}
F_115 () ;
F_148 () ;
}
void
F_154 ( void )
{
T_1 V_5 , V_237 ;
F_134 () ;
if ( V_160 ) {
F_35 ( V_160 ) ;
V_160 = NULL ;
}
if ( V_93 ) {
F_35 ( V_93 ) ;
V_93 = NULL ;
}
if ( V_114 ) {
F_35 ( V_114 ) ;
V_114 = NULL ;
}
for( V_5 = 0 ; V_5 < V_186 ; ++ V_5 ) {
if ( V_189 [ V_5 ] . V_190 != NULL ) {
for ( V_237 = 0 ; V_237 < V_195 ; V_237 ++ ) {
if ( V_189 [ V_5 ] . V_190 [ V_237 ] != NULL )
{
F_119 ( V_189 [ V_5 ] . V_190 [ V_237 ] ) ;
}
}
F_15 ( V_189 [ V_5 ] . V_190 ) ;
V_189 [ V_5 ] . V_190 = NULL ;
}
}
V_187 = FALSE ;
V_36 = FALSE ;
}
static void
F_155 ( V_16 V_56 , V_16 V_175 V_82 )
{
T_26 * V_170 = ( T_26 * ) V_56 ;
F_15 ( V_170 ) ;
}
static void
F_156 ( V_16 V_56 , V_16 V_175 V_82 )
{
T_27 * V_171 = ( T_27 * ) V_56 ;
F_15 ( V_171 ) ;
}
void
F_157 ( void )
{
if ( V_173 ) {
F_149 ( V_173 , F_155 , NULL ) ;
F_158 ( V_173 ) ;
V_173 = NULL ;
}
if ( V_172 ) {
F_149 ( V_172 , F_156 , NULL ) ;
F_158 ( V_172 ) ;
V_172 = NULL ;
}
}
T_9 *
F_159 ( T_11 * V_52 , T_7 V_24 )
{
if ( ! V_96 . V_203 ) {
return F_22 ( V_52 , V_24 ) ;
}
return F_95 ( V_52 , F_25 ( V_24 , V_30 ) ) ;
}
T_9 *
F_160 ( T_11 * V_52 , T_7 V_24 )
{
if ( ! V_96 . V_203 ) {
return F_22 ( V_52 , V_24 ) ;
}
return F_95 ( V_52 , F_25 ( V_24 , V_34 ) ) ;
}
T_9 *
F_161 ( T_11 * V_52 , T_7 V_24 )
{
if ( ! V_96 . V_203 ) {
return F_22 ( V_52 , V_24 ) ;
}
return F_95 ( V_52 , F_25 ( V_24 , V_28 ) ) ;
}
T_9 *
F_162 ( T_11 * V_52 , T_7 V_24 )
{
if ( ! V_96 . V_203 ) {
return F_22 ( V_52 , V_24 ) ;
}
return F_95 ( V_52 , F_25 ( V_24 , V_32 ) ) ;
}
int
F_163 ( T_9 * V_17 , T_35 V_238 , T_6 V_239 , T_36 V_240 )
{
const T_9 * V_241 ;
if ( ! V_96 . V_203 ||
( V_239 == V_49 ) ||
( ( V_241 = F_25 ( V_240 , V_239 ) ) == NULL ) ) {
return F_39 ( V_17 , V_238 , L_70 , V_240 ) ;
}
return F_39 ( V_17 , V_238 , L_71 , V_241 , V_240 ) ;
}
T_9 *
F_164 ( const V_75 * V_9 )
{
T_22 * V_66 ;
T_3 V_149 = V_96 . V_202 ;
V_66 = F_85 ( V_9 , V_149 ) ;
return V_149 ? V_66 -> V_131 : V_66 -> V_132 ;
}
T_9 *
F_165 ( T_37 * V_242 , T_21 V_243 )
{
return F_164 ( F_166 ( V_242 , V_243 , 6 ) ) ;
}
T_9 *
F_167 ( const V_75 * V_9 )
{
T_22 * V_66 ;
if ( ! V_96 . V_202 )
return NULL ;
V_66 = F_85 ( V_9 , TRUE ) ;
F_9 ( V_66 != NULL ) ;
if ( V_66 -> V_78 == V_129 ) {
return V_66 -> V_131 ;
}
else {
return NULL ;
}
}
V_75 *
F_168 ( const T_9 * V_55 )
{
return F_86 ( V_55 ) ;
}
void
F_169 ( const T_7 V_91 , const V_75 * V_119 )
{
T_3 V_92 ;
T_12 * V_66 ;
if ( ! V_96 . V_97 )
return;
V_66 = F_44 ( V_91 , & V_92 ) ;
if ( V_92 ) {
F_67 ( V_119 , V_66 -> V_55 ) ;
}
}
T_9 *
F_170 ( T_11 * V_244 , const T_1 V_245 , const char V_246 )
{
T_9 * V_17 = ( T_9 * ) F_23 ( V_244 , 12 ) ;
* F_171 ( V_17 , V_245 , V_246 ) = '\0' ;
return V_17 ;
}
const T_9 *
F_172 ( T_11 * V_52 , const T_1 V_9 )
{
if ( ! V_96 . V_97 ) {
return F_170 ( V_52 , V_9 , '\0' ) ;
}
return F_94 ( V_52 , V_9 ) ;
}
T_1
F_173 ( const T_9 * V_55 , T_3 * V_247 )
{
T_1 V_9 ;
T_3 V_161 ;
V_9 = F_96 ( V_55 , & V_161 ) ;
* V_247 = V_161 ;
return V_9 ;
}
const T_9 *
F_174 ( const V_75 * V_9 )
{
T_19 * V_127 ;
V_127 = F_68 ( V_9 ) ;
if ( V_96 . V_202 && V_127 -> V_78 != V_130 )
return V_127 -> V_131 ;
return V_127 -> V_132 ;
}
const T_9 *
F_175 ( const T_7 V_248 )
{
V_75 V_9 [ 3 ] ;
V_9 [ 0 ] = ( V_248 >> 16 ) & 0xFF ;
V_9 [ 1 ] = ( V_248 >> 8 ) & 0xFF ;
V_9 [ 2 ] = ( V_248 >> 0 ) & 0xFF ;
return F_174 ( V_9 ) ;
}
const T_9 *
F_176 ( T_37 * V_242 , T_21 V_243 )
{
return F_174 ( F_166 ( V_242 , V_243 , 3 ) ) ;
}
const T_9 *
F_177 ( const V_75 * V_9 )
{
T_19 * V_127 ;
int V_126 ;
V_75 V_136 ;
V_126 = V_9 [ 0 ] ;
V_126 = V_126 << 8 ;
V_136 = V_9 [ 1 ] ;
V_126 = V_126 | V_136 ;
V_126 = V_126 << 8 ;
V_136 = V_9 [ 2 ] ;
V_126 = V_126 | V_136 ;
V_127 = ( T_19 * ) F_12 ( V_133 , & V_126 ) ;
if ( ( V_127 == NULL ) || ( V_127 -> V_78 != V_130 ) ) {
return NULL ;
}
return V_127 -> V_131 ;
}
const T_9 *
F_178 ( const T_7 V_126 )
{
T_19 * V_127 ;
V_127 = ( T_19 * ) F_12 ( V_133 , & V_126 ) ;
if ( ( V_127 == NULL ) || ( V_127 -> V_78 != V_130 ) ) {
return NULL ;
}
return V_127 -> V_131 ;
}
const T_9 *
F_179 ( T_37 * V_242 , T_21 V_243 )
{
return F_177 ( F_166 ( V_242 , V_243 , 3 ) ) ;
}
char * F_180 ( T_19 * V_249 )
{
return V_249 -> V_131 ;
}
const T_9 *
F_181 ( T_11 * V_52 , const T_38 V_250 )
{
V_75 * V_9 = ( V_75 * ) F_23 ( NULL , 8 ) ;
T_19 * V_127 ;
const T_9 * V_167 ;
* ( T_38 * ) ( void * ) ( V_9 ) = F_182 ( & ( V_250 ) ) ;
V_127 = F_68 ( V_9 ) ;
if ( ! V_96 . V_202 || ( V_127 -> V_78 == V_130 ) ) {
V_167 = F_183 ( V_52 , L_72 , V_9 [ 0 ] , V_9 [ 1 ] , V_9 [ 2 ] , V_9 [ 3 ] , V_9 [ 4 ] , V_9 [ 5 ] , V_9 [ 6 ] , V_9 [ 7 ] ) ;
} else {
V_167 = F_183 ( V_52 , L_17 , V_127 -> V_131 , V_9 [ 3 ] , V_9 [ 4 ] , V_9 [ 5 ] , V_9 [ 6 ] , V_9 [ 7 ] ) ;
}
F_184 ( NULL , V_9 ) ;
return V_167 ;
}
static void
F_185 (
void * V_77 ,
int V_78 ,
#if ( ( V_79 < 1 ) \
|| ( 1 == V_79 && V_80 < 5 ) )
struct V_81 * T_39
#else
int T_16 V_82 ,
struct V_81 * T_39
#endif
) {
T_40 * V_251 = ( T_40 * ) V_77 ;
if ( V_78 == V_85 && T_39 && V_251 && T_39 -> V_252 == V_251 -> V_253 ) {
memcpy ( V_251 -> V_230 , T_39 -> V_254 , T_39 -> V_252 ) ;
V_251 -> V_255 = T_39 -> V_252 ;
}
}
T_3
F_186 ( const char * V_256 , T_1 * V_230 )
{
struct V_257 V_258 ;
#ifdef F_5
struct V_207 V_208 = { 0 , V_259 } , * V_260 ;
int V_209 ;
T_32 V_210 , V_211 ;
T_40 V_261 ;
#elif F_47 ( V_103 )
struct V_262 V_263 , * V_264 = NULL ;
#elif F_47 ( V_110 )
struct V_81 * T_39 ;
#endif
if ( ! F_187 ( V_256 , & V_258 ) ) {
if ( ! V_96 . V_97 ||
! V_96 . V_98 ) {
return FALSE ;
}
#ifdef F_5
if ( ! ( V_96 . V_100 ) ||
V_101 < 1 ||
! V_102 ) {
return FALSE ;
}
V_261 . V_253 = ( int ) sizeof ( struct V_257 ) ;
V_261 . V_255 = 0 ;
V_261 . V_230 = V_230 ;
F_188 ( V_216 , V_256 , V_87 , F_185 , & V_261 ) ;
F_129 ( & V_210 ) ;
F_129 ( & V_211 ) ;
V_209 = F_130 ( V_216 , & V_210 , & V_211 ) ;
if ( V_209 > 0 ) {
V_260 = F_189 ( V_216 , & V_208 , & V_208 ) ;
if ( F_131 ( V_209 , & V_210 , & V_211 , NULL , V_260 ) == - 1 ) {
fprintf ( V_214 , L_64 , F_132 ( V_199 ) ) ;
return FALSE ;
}
F_133 ( V_216 , & V_210 , & V_211 ) ;
}
F_190 ( V_216 ) ;
if ( V_261 . V_253 == V_261 . V_255 ) {
return TRUE ;
}
return FALSE ;
#elif F_47 ( V_103 )
memset ( & V_263 , 0 , sizeof( V_263 ) ) ;
V_263 . V_265 = V_87 ;
if ( F_191 ( V_256 , NULL , & V_263 , & V_264 ) == 0 ) {
if ( V_264 != NULL ) {
T_3 V_266 = FALSE ;
if ( V_264 -> V_265 == V_87 && V_264 -> V_267 == 4 ) {
memcpy ( & V_258 , V_264 -> V_268 -> V_269 , V_264 -> V_267 ) ;
V_266 = TRUE ;
}
F_192 ( V_264 ) ;
return V_266 ;
}
}
#elif F_47 ( V_110 )
T_39 = F_193 ( V_256 ) ;
if ( T_39 == NULL ) {
return FALSE ;
} else if ( T_39 -> V_252 <= ( int ) sizeof ( struct V_257 ) ) {
memcpy ( & V_258 , T_39 -> V_254 , T_39 -> V_252 ) ;
} else {
return FALSE ;
}
#endif
} else {
unsigned int V_151 , V_152 , V_153 , V_154 ;
if ( sscanf ( V_256 , L_73 , & V_151 , & V_152 , & V_153 , & V_154 ) != 4 )
return FALSE ;
}
* V_230 = V_258 . V_107 ;
return TRUE ;
}
T_3
F_194 ( const char * V_256 , struct V_8 * V_230 )
{
#ifdef F_5
struct V_207 V_208 = { 0 , V_259 } , * V_260 ;
int V_209 ;
T_32 V_210 , V_211 ;
T_40 V_261 ;
#elif F_47 ( V_103 )
struct V_262 V_263 , * V_264 = NULL ;
#elif F_47 ( V_270 )
struct V_81 * T_39 ;
#endif
if ( F_195 ( V_256 , V_230 ) )
return TRUE ;
if ( ! V_96 . V_97 ||
! V_96 . V_98 ) {
return FALSE ;
}
#ifdef F_5
if ( ! ( V_96 . V_100 ) ||
V_101 < 1 ||
! V_102 ) {
return FALSE ;
}
V_261 . V_253 = ( int ) sizeof ( struct V_8 ) ;
V_261 . V_255 = 0 ;
V_261 . V_230 = V_230 ;
F_188 ( V_216 , V_256 , V_89 , F_185 , & V_261 ) ;
F_129 ( & V_210 ) ;
F_129 ( & V_211 ) ;
V_209 = F_130 ( V_216 , & V_210 , & V_211 ) ;
if ( V_209 > 0 ) {
V_260 = F_189 ( V_216 , & V_208 , & V_208 ) ;
if ( F_131 ( V_209 , & V_210 , & V_211 , NULL , V_260 ) == - 1 ) {
fprintf ( V_214 , L_64 , F_132 ( V_199 ) ) ;
return FALSE ;
}
F_133 ( V_216 , & V_210 , & V_211 ) ;
}
F_190 ( V_216 ) ;
if ( V_261 . V_253 == V_261 . V_255 ) {
return TRUE ;
}
#elif F_47 ( V_103 )
memset ( & V_263 , 0 , sizeof( V_263 ) ) ;
V_263 . V_265 = V_89 ;
if ( F_191 ( V_256 , NULL , & V_263 , & V_264 ) == 0 ) {
if ( V_264 != NULL ) {
T_3 V_266 = FALSE ;
if ( V_264 -> V_265 == V_89 && V_264 -> V_267 == sizeof( struct V_8 ) ) {
memcpy ( V_230 , V_264 -> V_268 -> V_269 , V_264 -> V_267 ) ;
V_266 = TRUE ;
}
F_192 ( V_264 ) ;
return V_266 ;
}
}
#elif F_47 ( V_270 )
T_39 = F_196 ( V_256 , V_89 ) ;
if ( T_39 != NULL && T_39 -> V_252 == sizeof( struct V_8 ) ) {
memcpy ( V_230 , T_39 -> V_254 , T_39 -> V_252 ) ;
return TRUE ;
}
#endif
return FALSE ;
}
const char *
F_197 ( const char * V_256
#if ! F_47 ( V_103 ) || ! F_47 ( V_270 )
V_82
#endif
)
{
const char * V_271 = L_74 ;
#ifdef V_103
struct V_262 V_263 , * V_264 = NULL ;
memset ( & V_263 , 0 , sizeof( V_263 ) ) ;
V_263 . V_265 = V_272 ;
if ( F_191 ( V_256 , NULL , & V_263 , & V_264 ) == 0 ) {
if ( V_264 -> V_265 == V_89 ) {
V_271 = L_75 ;
}
F_192 ( V_264 ) ;
}
#elif F_47 ( V_270 )
struct V_81 * V_4 ;
return ( V_4 = F_196 ( V_256 , V_89 ) ) && V_4 -> V_273 == V_89 ? L_75 : L_74 ;
#endif
return V_271 ;
}
T_41 *
F_198 ( void )
{
return V_133 ;
}
T_41 *
F_199 ( void )
{
return V_135 ;
}
T_41 *
F_200 ( void )
{
return V_142 ;
}
T_41 *
F_201 ( void )
{
return V_27 ;
}
T_41 *
F_202 ( void )
{
return V_160 ;
}
T_41 *
F_203 ( void )
{
return V_93 ;
}
T_41 *
F_204 ( void )
{
return V_114 ;
}
void
F_205 ( void )
{
F_27 () ;
F_76 () ;
F_92 () ;
}
void
F_206 ( void )
{
F_34 () ;
F_79 () ;
F_93 () ;
}
T_3
F_99 ( const char * V_228 , void * V_274 )
{
return F_98 ( V_87 , V_228 , V_274 ) > 0 ;
}
T_3
F_195 ( const char * V_228 , void * V_274 )
{
return F_98 ( V_89 , V_228 , V_274 ) > 0 ;
}
