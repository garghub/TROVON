static void
F_1 ( int type , T_1 V_1 )
{
T_2 * V_2 ;
V_2 = F_2 ( T_2 , 1 ) ;
#ifdef F_3
V_2 -> V_3 = type ;
V_2 -> V_1 . V_4 = V_1 ;
#else
V_2 -> type = type ;
V_2 -> V_5 = V_1 ;
V_2 -> V_6 = FALSE ;
#endif
V_7 = F_4 ( V_7 , ( V_8 ) V_2 ) ;
}
static int
F_5 ( char * * V_9 , int * V_10 , T_3 * V_11 )
{
int V_12 ;
int V_13 ;
if ( V_11 == NULL || V_9 == NULL )
return - 1 ;
if ( * V_9 == NULL ) {
if ( * V_10 == 0 )
* V_10 = V_14 ;
* V_9 = ( char * ) F_6 ( * V_10 ) ;
}
F_7 ( * V_9 ) ;
F_7 ( * V_10 > 0 ) ;
if ( feof ( V_11 ) )
return - 1 ;
V_12 = 0 ;
while ( ( V_13 = getc ( V_11 ) ) != V_15 && V_13 != '\r' && V_13 != '\n' ) {
if ( V_12 + 1 >= * V_10 ) {
* V_9 = ( char * ) F_8 ( * V_9 , * V_10 += V_14 ) ;
}
( * V_9 ) [ V_12 ++ ] = V_13 ;
}
if ( V_12 == 0 && V_13 == V_15 )
return - 1 ;
( * V_9 ) [ V_12 ] = '\0' ;
return V_12 ;
}
static void
F_9 ( T_4 * * V_16 , const T_5 V_17 , const char * V_18 )
{
int V_19 ;
T_4 * V_20 ;
V_19 = F_10 ( V_17 ) ;
V_20 = V_16 [ V_19 ] ;
if( V_20 == NULL ) {
V_20 = V_16 [ V_19 ] = F_11 ( T_4 ) ;
} else {
while( 1 ) {
if( V_20 -> V_17 == V_17 ) {
return;
}
if ( V_20 -> V_21 == NULL ) {
V_20 -> V_21 = F_11 ( T_4 ) ;
V_20 = V_20 -> V_21 ;
break;
}
V_20 = V_20 -> V_21 ;
}
}
V_20 -> V_17 = V_17 ;
V_20 -> V_21 = NULL ;
F_12 ( V_20 -> V_22 , V_18 , V_23 ) ;
V_24 = TRUE ;
}
static void
F_13 ( char * line )
{
T_6 * V_25 ;
T_6 * V_26 ;
T_6 * V_17 ;
T_7 * V_27 = NULL ;
T_1 V_28 = V_29 ;
if ( ( V_25 = strchr ( line , '#' ) ) )
* V_25 = '\0' ;
if ( ( V_25 = strtok ( line , L_1 ) ) == NULL )
return;
V_26 = V_25 ;
if ( ( V_25 = strtok ( NULL , L_1 ) ) == NULL )
return;
V_17 = V_25 ;
if ( strtok ( V_25 , L_2 ) == NULL )
return;
if ( ( V_25 = strtok ( NULL , L_2 ) ) == NULL )
return;
if( strcmp ( V_25 , L_3 ) == 0 ) {
V_28 = V_30 ;
V_31 = V_32 ;
}
else if( strcmp ( V_25 , L_4 ) == 0 ) {
V_28 = V_29 ;
V_31 = V_33 ;
}
else if( strcmp ( V_25 , L_5 ) == 0 ) {
V_28 = V_34 ;
V_31 = V_35 ;
}
else if( strcmp ( V_25 , L_6 ) == 0 ) {
V_28 = V_36 ;
V_31 = V_37 ;
} else {
return;
}
if( V_38 != F_14 ( & V_27 , V_17 , V_28 ) ) {
return;
}
V_39 = V_26 ;
F_15 ( V_27 , V_40 ) ;
F_16 ( V_27 ) ;
}
static void
V_40 ( const T_1 V_17 )
{
if ( V_17 ) {
F_9 ( V_31 , V_17 , V_39 ) ;
}
}
static void
F_17 ( const char * V_41 )
{
T_3 * V_42 ;
static int V_10 = 0 ;
static char * V_9 = NULL ;
V_42 = F_18 ( V_41 , L_7 ) ;
if ( V_42 == NULL )
return;
while ( F_5 ( & V_9 , & V_10 , V_42 ) >= 0 ) {
F_13 ( V_9 ) ;
}
fclose ( V_42 ) ;
}
static void
F_19 ( void )
{
if ( V_43 == NULL )
V_43 = F_20 ( V_44 , FALSE ) ;
F_17 ( V_43 ) ;
if ( V_45 == NULL ) {
V_45 = F_21 ( V_44 ) ;
}
F_17 ( V_45 ) ;
V_46 = TRUE ;
}
static T_6
* F_22 ( const T_5 V_17 , const T_8 V_47 )
{
int V_19 ;
T_4 * V_20 ;
T_4 * * V_48 ;
const char * V_49 = NULL ;
struct V_50 * V_51 ;
if ( ! V_46 ) {
F_19 () ;
}
switch( V_47 ) {
case V_52 :
V_48 = V_33 ;
V_49 = L_4 ;
break;
case V_53 :
V_48 = V_32 ;
V_49 = L_3 ;
break;
case V_54 :
V_48 = V_35 ;
V_49 = L_5 ;
break;
case V_55 :
V_48 = V_37 ;
V_49 = L_8 ;
break;
default:
return NULL ;
}
V_19 = F_10 ( V_17 ) ;
V_20 = V_48 [ V_19 ] ;
if( V_20 == NULL ) {
V_20 = V_48 [ V_19 ] = F_11 ( T_4 ) ;
} else {
while( 1 ) {
if( V_20 -> V_17 == V_17 ) {
return V_20 -> V_22 ;
}
if ( V_20 -> V_21 == NULL ) {
V_20 -> V_21 = F_11 ( T_4 ) ;
V_20 = V_20 -> V_21 ;
break;
}
V_20 = V_20 -> V_21 ;
}
}
V_20 -> V_17 = V_17 ;
V_20 -> V_21 = NULL ;
if ( ( ! V_56 . V_57 ) ||
( V_51 = F_23 ( F_24 ( V_17 ) , V_49 ) ) == NULL ) {
F_25 ( V_17 , V_20 -> V_22 , V_23 ) ;
} else {
F_12 ( V_20 -> V_22 , V_51 -> V_58 , V_23 ) ;
}
return ( V_20 -> V_22 ) ;
}
static void
F_26 ( const T_5 V_1 , T_9 * volatile V_20 )
{
T_10 V_59 ;
if ( V_20 -> V_60 )
return;
V_20 -> V_60 = TRUE ;
V_59 = F_27 ( V_1 ) ;
if( 0 != V_59 . V_61 ) {
T_1 V_62 ;
T_6 V_63 [ V_64 ] ;
T_6 * V_65 ;
T_11 V_66 ;
V_62 = V_1 & ( ~ ( T_1 ) V_59 . V_61 ) ;
F_28 ( ( V_67 * ) & V_62 , V_63 , V_64 ) ;
V_65 = V_63 ;
V_66 = V_59 . V_68 / 8 ;
while( * ( V_65 ) != '\0' && V_66 > 0 ) {
if( * ( ++ V_65 ) == '.' ) {
-- V_66 ;
}
}
F_29 ( V_20 -> V_22 , V_23 , L_9 , V_59 . V_22 , V_65 ) ;
} else {
F_28 ( ( const V_67 * ) & V_1 , V_20 -> V_22 , V_23 ) ;
}
}
static T_9 *
F_30 ( const T_5 V_1 )
{
T_9 * V_20 = F_11 ( T_9 ) ;
V_20 -> V_1 = V_1 ;
V_20 -> V_21 = NULL ;
V_20 -> V_69 = FALSE ;
V_20 -> V_60 = FALSE ;
F_28 ( ( const V_67 * ) & V_1 , V_20 -> V_70 , sizeof( V_20 -> V_70 ) ) ;
return V_20 ;
}
static T_9 *
F_31 ( const T_5 V_1 , T_12 * V_71 )
{
int V_19 ;
T_9 * volatile V_20 ;
struct V_72 * V_73 ;
* V_71 = TRUE ;
V_19 = F_32 ( V_1 ) ;
V_20 = V_74 [ V_19 ] ;
if( V_20 == NULL ) {
V_20 = V_74 [ V_19 ] = F_30 ( V_1 ) ;
} else {
while( 1 ) {
if( V_20 -> V_1 == V_1 ) {
if ( V_20 -> V_60 && ! V_20 -> V_69 )
break;
if ( V_20 -> V_60 )
* V_71 = FALSE ;
return V_20 ;
}
if ( V_20 -> V_21 == NULL ) {
V_20 -> V_21 = F_30 ( V_1 ) ;
V_20 = V_20 -> V_21 ;
break;
}
V_20 = V_20 -> V_21 ;
}
}
if ( V_56 . V_75 && V_56 . V_76 ) {
V_20 -> V_69 = TRUE ;
#ifdef F_33
if ( V_56 . V_77 &&
V_78 > 0 &&
V_79 ) {
F_1 ( V_80 , V_1 ) ;
F_26 ( V_1 , V_20 ) ;
return V_20 ;
}
#endif
if ( V_1 != 0 ) {
V_73 = F_34 ( ( const char * ) & V_1 , 4 , V_80 ) ;
if ( V_73 != NULL ) {
F_12 ( V_20 -> V_22 , V_73 -> V_81 , V_23 ) ;
V_20 -> V_60 = FALSE ;
return V_20 ;
}
}
}
* V_71 = FALSE ;
F_26 ( V_1 , V_20 ) ;
return V_20 ;
}
static T_13 *
F_35 ( const struct V_82 * V_1 )
{
T_13 * V_20 = F_11 ( T_13 ) ;
V_20 -> V_1 = * V_1 ;
V_20 -> V_21 = NULL ;
V_20 -> V_69 = FALSE ;
V_20 -> V_60 = FALSE ;
F_36 ( V_1 , V_20 -> V_83 ) ;
return V_20 ;
}
static T_13 *
F_37 ( const struct V_82 * V_1 , T_12 * V_71 )
{
int V_19 ;
T_13 * volatile V_20 ;
#ifdef F_38
#ifdef F_3
T_2 * V_84 ;
#endif
struct V_72 * V_73 ;
#endif
* V_71 = TRUE ;
V_19 = F_39 ( * V_1 ) ;
V_20 = V_85 [ V_19 ] ;
if( V_20 == NULL ) {
V_20 = V_85 [ V_19 ] = F_35 ( V_1 ) ;
} else {
while( 1 ) {
if( memcmp ( & V_20 -> V_1 , V_1 , sizeof ( struct V_82 ) ) == 0 ) {
if ( V_20 -> V_60 && ! V_20 -> V_69 )
break;
if ( V_20 -> V_60 )
* V_71 = FALSE ;
return V_20 ;
}
if ( V_20 -> V_21 == NULL ) {
V_20 -> V_21 = F_35 ( V_1 ) ;
V_20 = V_20 -> V_21 ;
break;
}
V_20 = V_20 -> V_21 ;
}
}
if ( V_56 . V_75 &&
V_56 . V_76 ) {
V_20 -> V_69 = TRUE ;
#ifdef F_38
#ifdef F_3
if ( ( V_56 . V_77 ) &&
V_78 > 0 &&
V_79 ) {
V_84 = F_2 ( T_2 , 1 ) ;
V_84 -> V_3 = V_86 ;
memcpy ( & V_84 -> V_1 . V_83 , V_1 , sizeof( V_84 -> V_1 . V_83 ) ) ;
V_7 = F_4 ( V_7 , ( V_8 ) V_84 ) ;
if ( ! V_20 -> V_60 ) {
F_12 ( V_20 -> V_22 , V_20 -> V_83 , V_23 ) ;
F_36 ( V_1 , V_20 -> V_22 ) ;
V_20 -> V_60 = TRUE ;
}
return V_20 ;
}
#endif
V_73 = F_34 ( ( const char * ) V_1 , sizeof( * V_1 ) , V_86 ) ;
if ( V_73 != NULL ) {
F_12 ( V_20 -> V_22 , V_73 -> V_81 , V_23 ) ;
V_20 -> V_60 = FALSE ;
return V_20 ;
}
#endif
}
if ( ! V_20 -> V_60 ) {
V_20 -> V_60 = TRUE ;
F_12 ( V_20 -> V_22 , V_20 -> V_83 , V_23 ) ;
}
* V_71 = FALSE ;
return V_20 ;
}
static const T_6 *
F_40 ( const T_14 * V_1 )
{
switch ( V_1 -> type ) {
case V_87 :
return F_41 ( ( const V_67 * ) V_1 -> V_88 ) ;
case V_89 : {
T_1 V_5 ;
memcpy ( & V_5 , V_1 -> V_88 , sizeof V_5 ) ;
return F_42 ( V_5 ) ;
}
case V_90 : {
struct V_82 V_91 ;
memcpy ( & V_91 . V_92 , V_1 -> V_88 , sizeof V_91 . V_92 ) ;
return F_43 ( & V_91 ) ;
}
case V_93 :
return ( const T_6 * ) V_1 -> V_88 ;
default:
return NULL ;
}
}
static const T_6 *
F_44 ( const T_14 * V_1 )
{
switch ( V_1 -> type ) {
case V_87 :
return F_41 ( ( const V_67 * ) V_1 -> V_88 ) ;
case V_89 : {
T_1 V_5 ;
memcpy ( & V_5 , V_1 -> V_88 , sizeof V_5 ) ;
return F_42 ( V_5 ) ;
}
case V_90 : {
struct V_82 V_91 ;
memcpy ( & V_91 . V_92 , V_1 -> V_88 , sizeof V_91 . V_92 ) ;
return F_43 ( & V_91 ) ;
}
case V_93 :
return F_45 ( ( const T_6 * ) V_1 -> V_88 ) ;
default:
return NULL ;
}
}
static T_12
F_46 ( const char * V_25 , T_15 * V_94 , unsigned int * V_61 ,
const T_12 V_95 )
{
int V_66 ;
unsigned long V_96 ;
char * V_97 ;
char V_98 = '\0' ;
for ( V_66 = 0 ; V_66 < 6 ; V_66 ++ ) {
if ( ! isxdigit ( ( unsigned char ) * V_25 ) )
return FALSE ;
V_96 = strtoul ( V_25 , & V_97 , 16 ) ;
if ( V_97 == V_25 )
return FALSE ;
if ( V_96 > 0xFF )
return FALSE ;
V_94 -> V_1 [ V_66 ] = ( V_67 ) V_96 ;
V_25 = V_97 ;
if ( * V_25 == '/' ) {
if ( ! V_95 ) {
return FALSE ;
}
V_25 ++ ;
if ( ! isdigit ( ( unsigned char ) * V_25 ) )
return FALSE ;
V_96 = strtoul ( V_25 , & V_97 , 10 ) ;
if ( V_97 == V_25 )
return FALSE ;
V_25 = V_97 ;
if ( * V_25 != '\0' && ! isspace ( ( unsigned char ) * V_25 ) )
return FALSE ;
if ( V_96 == 0 || V_96 >= 48 )
return FALSE ;
* V_61 = ( int ) V_96 ;
for ( V_66 = 0 ; V_96 >= 8 ; V_66 ++ , V_96 -= 8 )
;
V_94 -> V_1 [ V_66 ] &= ( 0xFF << ( 8 - V_96 ) ) ;
V_66 ++ ;
for (; V_66 < 6 ; V_66 ++ )
V_94 -> V_1 [ V_66 ] = 0 ;
return TRUE ;
}
if ( * V_25 == '\0' ) {
if ( V_66 == 2 ) {
if ( ! V_95 ) {
return FALSE ;
}
* V_61 = 0 ;
return TRUE ;
}
if ( V_66 == 5 ) {
if ( V_95 )
* V_61 = 48 ;
return TRUE ;
}
return FALSE ;
} else {
if ( V_98 == '\0' ) {
if ( * V_25 != ':' && * V_25 != '-' && * V_25 != '.' )
return FALSE ;
V_98 = * V_25 ;
} else {
if ( * V_25 != V_98 )
return FALSE ;
}
}
V_25 ++ ;
}
return TRUE ;
}
static int
F_47 ( char * line , T_15 * V_94 , unsigned int * V_61 ,
const T_12 V_95 )
{
T_6 * V_25 ;
if ( ( V_25 = strchr ( line , '#' ) ) )
* V_25 = '\0' ;
if ( ( V_25 = strtok ( line , L_1 ) ) == NULL )
return - 1 ;
if ( ! F_46 ( V_25 , V_94 , V_61 , V_95 ) )
return - 1 ;
if ( ( V_25 = strtok ( NULL , L_1 ) ) == NULL )
return - 1 ;
F_12 ( V_94 -> V_22 , V_25 , V_23 ) ;
return 0 ;
}
static void
F_48 ( char * V_41 )
{
if ( V_99 )
rewind ( V_99 ) ;
else
V_99 = F_18 ( V_41 , L_7 ) ;
}
static void
F_49 ( void )
{
if ( V_99 ) {
fclose ( V_99 ) ;
V_99 = NULL ;
}
}
static T_15 *
F_50 ( unsigned int * V_61 , const T_12 V_95 )
{
static T_15 V_94 ;
static int V_10 = 0 ;
static char * V_9 = NULL ;
if ( V_99 == NULL )
return NULL ;
while ( F_5 ( & V_9 , & V_10 , V_99 ) >= 0 ) {
if ( F_47 ( V_9 , & V_94 , V_61 , V_95 ) == 0 ) {
return & V_94 ;
}
}
return NULL ;
}
static T_15 *
F_51 ( const T_6 * V_22 )
{
T_15 * V_94 ;
F_48 ( V_100 ) ;
while ( ( ( V_94 = F_50 ( NULL , FALSE ) ) != NULL ) && strncmp ( V_22 , V_94 -> V_22 , V_23 ) != 0 )
;
if ( V_94 == NULL ) {
F_49 () ;
F_48 ( V_101 ) ;
while ( ( ( V_94 = F_50 ( NULL , FALSE ) ) != NULL ) && strncmp ( V_22 , V_94 -> V_22 , V_23 ) != 0 )
;
F_49 () ;
}
return V_94 ;
}
static T_15 *
F_52 ( const V_67 * V_1 )
{
T_15 * V_94 ;
F_48 ( V_100 ) ;
while ( ( ( V_94 = F_50 ( NULL , FALSE ) ) != NULL ) && memcmp ( V_1 , V_94 -> V_1 , 6 ) != 0 )
;
if ( V_94 == NULL ) {
F_49 () ;
F_48 ( V_101 ) ;
while ( ( ( V_94 = F_50 ( NULL , FALSE ) ) != NULL ) && memcmp ( V_1 , V_94 -> V_1 , 6 ) != 0 )
;
F_49 () ;
}
return V_94 ;
}
static int
F_53 ( const V_67 * V_1 , unsigned int V_61 )
{
if ( V_61 <= 8 ) {
return ( V_1 [ 0 ] & ( 0xFF << ( 8 - V_61 ) ) ) & ( V_102 - 1 ) ;
}
V_61 -= 8 ;
if ( V_61 <= 8 ) {
return ( ( V_1 [ 0 ] << 8 ) | ( V_1 [ 1 ] & ( 0xFF << ( 8 - V_61 ) ) ) ) &
( V_102 - 1 ) ;
}
V_61 -= 8 ;
if ( V_61 <= 8 ) {
return ( ( V_1 [ 0 ] << 16 ) | ( V_1 [ 1 ] << 8 ) | ( V_1 [ 2 ] & ( 0xFF << ( 8 - V_61 ) ) ) )
& ( V_102 - 1 ) ;
}
V_61 -= 8 ;
if ( V_61 <= 8 ) {
return ( ( ( ( V_1 [ 0 ] << 8 ) | V_1 [ 1 ] ) ^
( ( V_1 [ 2 ] << 8 ) | ( V_1 [ 3 ] & ( 0xFF << ( 8 - V_61 ) ) ) ) ) ) &
( V_102 - 1 ) ;
}
V_61 -= 8 ;
if ( V_61 <= 8 ) {
return ( ( ( ( V_1 [ 1 ] << 8 ) | V_1 [ 2 ] ) ^
( ( V_1 [ 3 ] << 8 ) | ( V_1 [ 4 ] & ( 0xFF << ( 8 - V_61 ) ) ) ) ) ) &
( V_102 - 1 ) ;
}
V_61 -= 8 ;
return ( ( ( ( V_1 [ 1 ] << 8 ) | V_1 [ 2 ] ) ^
( ( V_1 [ 3 ] << 8 ) | ( V_1 [ 4 ] & ( 0xFF << ( 8 - V_61 ) ) ) ) ) ) &
( V_102 - 1 ) ;
}
static T_16 *
F_54 ( const V_67 * V_1 , T_6 * V_22 )
{
T_16 * V_103 ;
V_103 = F_11 ( T_16 ) ;
memcpy ( V_103 -> V_1 , V_1 , sizeof( V_103 -> V_1 ) ) ;
V_103 -> V_22 = F_55 ( V_22 ) ;
V_103 -> V_21 = NULL ;
return V_103 ;
}
static T_17 *
F_56 ( const V_67 * V_1 , T_6 * V_22 )
{
T_17 * V_104 ;
V_104 = F_11 ( T_17 ) ;
memcpy ( V_104 -> V_1 , V_1 , sizeof( V_104 -> V_1 ) ) ;
F_12 ( V_104 -> V_22 , V_22 , V_23 ) ;
V_104 -> V_21 = NULL ;
return V_104 ;
}
static void
F_57 ( const V_67 * V_1 , unsigned int V_61 , T_6 * V_22 )
{
T_18 V_19 ;
T_16 * V_103 ;
T_17 * ( * V_105 ) [ V_102 ] , * V_104 ;
if ( V_61 >= 48 ) {
F_58 ( V_1 , V_22 ) ;
return;
}
if ( V_61 == 0 ) {
V_19 = F_59 ( V_1 ) ;
V_103 = V_106 [ V_19 ] ;
if( V_103 == NULL ) {
V_106 [ V_19 ] = F_54 ( V_1 , V_22 ) ;
return;
} else {
while( TRUE ) {
if ( V_103 -> V_21 == NULL ) {
V_103 -> V_21 = F_54 ( V_1 , V_22 ) ;
return;
}
V_103 = V_103 -> V_21 ;
}
}
}
V_105 = V_107 [ V_61 ] ;
if ( V_105 == NULL )
V_105 = V_107 [ V_61 ] = ( T_17 * ( * ) [ V_102 ] ) F_60 ( sizeof * V_107 [ V_61 ] ) ;
V_19 = F_53 ( V_1 , V_61 ) ;
V_104 = ( * V_105 ) [ V_19 ] ;
if( V_104 == NULL ) {
( * V_105 ) [ V_19 ] = F_56 ( V_1 , V_22 ) ;
return;
} else {
while( TRUE ) {
if ( memcmp ( V_104 -> V_1 , V_1 , sizeof( V_104 -> V_1 ) ) == 0 ) {
return;
}
if ( V_104 -> V_21 == NULL ) {
V_104 -> V_21 = F_56 ( V_1 , V_22 ) ;
return;
}
V_104 = V_104 -> V_21 ;
}
}
}
static T_16 *
F_61 ( const V_67 * V_1 )
{
T_18 V_19 ;
T_16 * V_103 ;
V_67 V_108 [ 3 ] ;
V_19 = F_59 ( V_1 ) ;
V_103 = V_106 [ V_19 ] ;
while( V_103 != NULL ) {
if ( memcmp ( V_103 -> V_1 , V_1 , sizeof( V_103 -> V_1 ) ) == 0 ) {
return V_103 ;
}
V_103 = V_103 -> V_21 ;
}
memcpy ( V_108 , V_1 , 3 ) ;
V_108 [ 0 ] &= 0xFE ;
V_103 = V_106 [ V_19 ] ;
while( V_103 != NULL ) {
if ( memcmp ( V_103 -> V_1 , V_108 , sizeof( V_103 -> V_1 ) ) == 0 ) {
return V_103 ;
}
V_103 = V_103 -> V_21 ;
}
return NULL ;
}
static T_17 *
F_62 ( const V_67 * V_1 , const unsigned int V_61 )
{
T_18 V_19 ;
T_17 * ( * V_105 ) [ V_102 ] ;
T_17 * V_104 ;
V_67 V_109 [ 6 ] ;
T_5 V_96 ;
T_18 V_66 ;
V_105 = V_107 [ V_61 ] ;
if ( V_105 == NULL ) {
return NULL ;
}
for ( V_66 = 0 , V_96 = V_61 ; V_96 >= 8 ; V_66 ++ , V_96 -= 8 )
V_109 [ V_66 ] = V_1 [ V_66 ] ;
V_109 [ V_66 ] = V_1 [ V_66 ] & ( 0xFF << ( 8 - V_96 ) ) ;
V_66 ++ ;
for (; V_66 < 6 ; V_66 ++ )
V_109 [ V_66 ] = 0 ;
V_19 = F_53 ( V_109 , V_61 ) ;
V_104 = ( * V_105 ) [ V_19 ] ;
while( V_104 != NULL ) {
if ( memcmp ( V_104 -> V_1 , V_109 , sizeof( V_104 -> V_1 ) ) == 0 ) {
return V_104 ;
}
V_104 = V_104 -> V_21 ;
}
return NULL ;
}
static void
F_63 ( void )
{
T_15 * V_94 ;
char * V_110 ;
T_5 V_61 ;
if ( V_101 == NULL ) {
V_101 = F_64 ( L_10 V_111 L_10 ,
F_65 () , V_112 ) ;
}
if ( V_100 == NULL )
V_100 = F_20 ( V_112 , FALSE ) ;
V_110 = F_21 ( V_113 ) ;
F_48 ( V_110 ) ;
while ( ( V_94 = F_50 ( & V_61 , TRUE ) ) ) {
F_57 ( V_94 -> V_1 , V_61 , V_94 -> V_22 ) ;
}
F_49 () ;
F_16 ( V_110 ) ;
V_114 = TRUE ;
}
static T_19 *
F_66 ( T_19 * V_20 ) {
T_15 * V_94 ;
const V_67 * V_1 = V_20 -> V_1 ;
if ( ( V_94 = F_52 ( V_1 ) ) != NULL ) {
F_12 ( V_20 -> V_115 , V_94 -> V_22 , V_23 ) ;
V_20 -> V_116 = V_117 ;
return V_20 ;
} else {
T_17 * V_104 ;
T_16 * V_103 ;
T_5 V_61 ;
V_61 = 7 ;
for (; ; ) {
if ( ( V_104 = F_62 ( V_1 , V_61 + 40 ) ) != NULL ) {
F_29 ( V_20 -> V_115 , V_23 , L_11 ,
V_104 -> V_22 , V_1 [ 5 ] & ( 0xFF >> V_61 ) ) ;
V_20 -> V_116 = V_118 ;
return V_20 ;
}
if ( V_61 == 0 )
break;
V_61 -- ;
}
V_61 = 7 ;
for (; ; ) {
if ( ( V_104 = F_62 ( V_1 , V_61 + 32 ) ) != NULL ) {
F_29 ( V_20 -> V_115 , V_23 , L_12 ,
V_104 -> V_22 , V_1 [ 4 ] & ( 0xFF >> V_61 ) , V_1 [ 5 ] ) ;
V_20 -> V_116 = V_118 ;
return V_20 ;
}
if ( V_61 == 0 )
break;
V_61 -- ;
}
V_61 = 7 ;
for (; ; ) {
if ( ( V_104 = F_62 ( V_1 , V_61 + 24 ) ) != NULL ) {
F_29 ( V_20 -> V_115 , V_23 , L_13 ,
V_104 -> V_22 , V_1 [ 3 ] & ( 0xFF >> V_61 ) , V_1 [ 4 ] , V_1 [ 5 ] ) ;
V_20 -> V_116 = V_118 ;
return V_20 ;
}
if ( V_61 == 0 )
break;
V_61 -- ;
}
if ( ( V_103 = F_61 ( V_1 ) ) != NULL ) {
F_29 ( V_20 -> V_115 , V_23 , L_13 ,
V_103 -> V_22 , V_1 [ 3 ] , V_1 [ 4 ] , V_1 [ 5 ] ) ;
V_20 -> V_116 = V_118 ;
return V_20 ;
}
V_61 = 7 ;
for (; ; ) {
if ( ( V_104 = F_62 ( V_1 , V_61 + 16 ) ) != NULL ) {
F_29 ( V_20 -> V_115 , V_23 , L_14 ,
V_104 -> V_22 , V_1 [ 2 ] & ( 0xFF >> V_61 ) , V_1 [ 3 ] , V_1 [ 4 ] ,
V_1 [ 5 ] ) ;
V_20 -> V_116 = V_118 ;
return V_20 ;
}
if ( V_61 == 0 )
break;
V_61 -- ;
}
V_61 = 7 ;
for (; ; ) {
if ( ( V_104 = F_62 ( V_1 , V_61 + 8 ) ) != NULL ) {
F_29 ( V_20 -> V_115 , V_23 , L_15 ,
V_104 -> V_22 , V_1 [ 1 ] & ( 0xFF >> V_61 ) , V_1 [ 2 ] , V_1 [ 3 ] ,
V_1 [ 4 ] , V_1 [ 5 ] ) ;
V_20 -> V_116 = V_118 ;
return V_20 ;
}
if ( V_61 == 0 )
break;
V_61 -- ;
}
for ( V_61 = 7 ; V_61 > 0 ; V_61 -- ) {
if ( ( V_104 = F_62 ( V_1 , V_61 ) ) != NULL ) {
F_29 ( V_20 -> V_115 , V_23 , L_16 ,
V_104 -> V_22 , V_1 [ 0 ] & ( 0xFF >> V_61 ) , V_1 [ 1 ] , V_1 [ 2 ] ,
V_1 [ 3 ] , V_1 [ 4 ] , V_1 [ 5 ] ) ;
V_20 -> V_116 = V_118 ;
return V_20 ;
}
}
F_29 ( V_20 -> V_115 , V_23 , L_10 , F_67 ( V_1 ) ) ;
V_20 -> V_116 = V_118 ;
return V_20 ;
}
F_68 () ;
}
static T_19 *
F_69 ( const V_67 * V_1 , const T_12 V_69 ) {
T_19 * V_20 ;
V_20 = F_11 ( T_19 ) ;
memcpy ( V_20 -> V_1 , V_1 , sizeof( V_20 -> V_1 ) ) ;
V_20 -> V_116 = V_119 ;
F_12 ( V_20 -> V_120 , F_70 ( V_1 , sizeof( V_20 -> V_1 ) , ':' ) , sizeof( V_20 -> V_120 ) ) ;
V_20 -> V_115 [ 0 ] = '\0' ;
V_20 -> V_21 = NULL ;
if ( V_69 )
F_66 ( V_20 ) ;
return V_20 ;
}
static T_19 *
F_58 ( const V_67 * V_1 , const T_6 * V_22 )
{
T_18 V_19 ;
T_19 * V_20 ;
V_19 = F_71 ( V_1 ) ;
V_20 = V_121 [ V_19 ] ;
if( V_20 == NULL ) {
V_20 = V_121 [ V_19 ] = F_69 ( V_1 , FALSE ) ;
} else {
while( TRUE ) {
if ( memcmp ( V_20 -> V_1 , V_1 , sizeof( V_20 -> V_1 ) ) == 0 ) {
if ( V_20 -> V_116 == V_117 )
return V_20 ;
break;
}
if ( V_20 -> V_21 == NULL ) {
V_20 = V_20 -> V_21 = F_69 ( V_1 , FALSE ) ;
break;
}
V_20 = V_20 -> V_21 ;
}
}
F_12 ( V_20 -> V_115 , V_22 , V_23 ) ;
V_20 -> V_116 = V_117 ;
V_24 = TRUE ;
return V_20 ;
}
static T_19 *
F_72 ( const V_67 * V_1 , const T_12 V_69 ) {
T_18 V_19 ;
T_19 * V_20 ;
V_19 = F_71 ( V_1 ) ;
V_20 = V_121 [ V_19 ] ;
if( V_20 == NULL ) {
V_20 = V_121 [ V_19 ] = F_69 ( V_1 , V_69 ) ;
return V_20 ;
} else {
while( TRUE ) {
if ( memcmp ( V_20 -> V_1 , V_1 , sizeof( V_20 -> V_1 ) ) == 0 ) {
if ( V_69 && ( V_20 -> V_116 == V_119 ) )
F_66 ( V_20 ) ;
return V_20 ;
}
if ( V_20 -> V_21 == NULL ) {
V_20 -> V_21 = F_69 ( V_1 , V_69 ) ;
return V_20 -> V_21 ;
}
V_20 = V_20 -> V_21 ;
}
}
}
static V_67 *
F_73 ( const T_6 * V_22 )
{
T_15 * V_94 ;
T_19 * V_20 ;
T_19 * * V_48 = V_121 ;
T_18 V_66 ;
for ( V_66 = 0 ; V_66 < V_102 ; V_66 ++ ) {
V_20 = V_48 [ V_66 ] ;
while ( V_20 ) {
if ( strcmp ( V_20 -> V_115 , V_22 ) == 0 )
return V_20 -> V_1 ;
V_20 = V_20 -> V_21 ;
}
}
if ( ( V_94 = F_51 ( V_22 ) ) == NULL )
return NULL ;
V_20 = F_58 ( V_94 -> V_1 , V_22 ) ;
return V_20 -> V_1 ;
}
static int
F_74 ( char * line , T_20 * V_122 )
{
T_6 * V_25 ;
T_1 V_123 , V_124 , V_125 , V_126 , V_127 ;
T_12 V_128 = FALSE ;
if ( ( V_25 = strchr ( line , '#' ) ) )
* V_25 = '\0' ;
if ( ( V_25 = strtok ( line , L_17 ) ) == NULL )
return - 1 ;
if ( sscanf ( V_25 , L_18 , & V_124 , & V_125 , & V_126 , & V_127 ) != 4 ) {
if ( sscanf ( V_25 , L_19 , & V_124 , & V_125 , & V_126 , & V_127 ) != 4 ) {
if ( sscanf ( V_25 , L_20 , & V_124 , & V_125 , & V_126 , & V_127 ) != 4 ) {
if ( sscanf ( V_25 , L_21 , & V_123 ) == 1 ) {
V_128 = TRUE ;
}
else {
return - 1 ;
}
}
}
}
if ( ( V_25 = strtok ( NULL , L_17 ) ) == NULL )
return - 1 ;
if ( V_128 ) {
V_122 -> V_1 = V_123 ;
}
else {
V_122 -> V_1 = ( V_124 << 24 ) | ( V_125 << 16 ) | ( V_126 << 8 ) | V_127 ;
}
F_12 ( V_122 -> V_22 , V_25 , V_23 ) ;
return 0 ;
}
static void
F_75 ( char * V_41 )
{
if ( V_129 )
rewind ( V_129 ) ;
else
V_129 = F_18 ( V_41 , L_7 ) ;
}
static void
F_76 ( void )
{
if ( V_129 ) {
fclose ( V_129 ) ;
V_129 = NULL ;
}
}
static T_20 *
F_77 ( void )
{
static T_20 V_122 ;
static int V_10 = 0 ;
static char * V_9 = NULL ;
if ( V_129 == NULL )
return NULL ;
while ( F_5 ( & V_9 , & V_10 , V_129 ) >= 0 ) {
if ( F_74 ( V_9 , & V_122 ) == 0 ) {
return & V_122 ;
}
}
return NULL ;
}
static T_20 *
F_78 ( const T_6 * V_22 )
{
T_20 * V_122 ;
F_75 ( V_130 ) ;
while ( ( ( V_122 = F_77 () ) != NULL ) && strncmp ( V_22 , V_122 -> V_22 , V_23 ) != 0 )
;
if ( V_122 == NULL ) {
F_76 () ;
F_75 ( V_131 ) ;
while ( ( ( V_122 = F_77 () ) != NULL ) && strncmp ( V_22 , V_122 -> V_22 , V_23 ) != 0 )
;
F_76 () ;
}
return V_122 ;
}
static T_20 *
F_79 ( T_1 V_1 )
{
T_20 * V_122 ;
F_75 ( V_130 ) ;
while ( ( ( V_122 = F_77 () ) != NULL ) && ( V_1 != V_122 -> V_1 ) ) ;
if ( V_122 == NULL ) {
F_76 () ;
F_75 ( V_131 ) ;
while ( ( ( V_122 = F_77 () ) != NULL ) && ( V_1 != V_122 -> V_1 ) )
;
F_76 () ;
}
return V_122 ;
}
static void
F_80 ( void )
{
if ( V_130 == NULL ) {
V_130 = F_64 ( L_10 V_111 L_10 ,
F_65 () , V_132 ) ;
}
if ( V_131 == NULL )
V_131 = F_20 ( V_132 , FALSE ) ;
V_133 = TRUE ;
}
static T_21 *
F_81 ( T_5 V_1 , const T_6 * V_22 )
{
int V_19 ;
T_21 * V_20 ;
V_19 = F_82 ( V_1 ) ;
V_20 = V_134 [ V_19 ] ;
if( V_20 == NULL ) {
V_20 = V_134 [ V_19 ] = F_11 ( T_21 ) ;
} else {
while( 1 ) {
if ( V_20 -> V_21 == NULL ) {
V_20 -> V_21 = F_11 ( T_21 ) ;
V_20 = V_20 -> V_21 ;
break;
}
V_20 = V_20 -> V_21 ;
}
}
V_20 -> V_1 = V_1 ;
F_12 ( V_20 -> V_22 , V_22 , V_23 ) ;
V_20 -> V_21 = NULL ;
V_24 = TRUE ;
return V_20 ;
}
static T_6 *
F_83 ( const T_5 V_1 )
{
int V_19 ;
T_21 * V_20 ;
T_20 * V_122 ;
V_19 = F_82 ( V_1 ) ;
V_20 = V_134 [ V_19 ] ;
if( V_20 == NULL ) {
V_20 = V_134 [ V_19 ] = F_11 ( T_21 ) ;
} else {
while( 1 ) {
if ( V_20 -> V_1 == V_1 ) {
return V_20 -> V_22 ;
}
if ( V_20 -> V_21 == NULL ) {
V_20 -> V_21 = F_11 ( T_21 ) ;
V_20 = V_20 -> V_21 ;
break;
}
V_20 = V_20 -> V_21 ;
}
}
V_20 -> V_1 = V_1 ;
V_20 -> V_21 = NULL ;
if ( ( V_122 = F_79 ( V_1 ) ) == NULL ) {
F_29 ( V_20 -> V_22 , V_23 , L_22 , V_1 ) ;
} else {
F_12 ( V_20 -> V_22 , V_122 -> V_22 , V_23 ) ;
}
return ( V_20 -> V_22 ) ;
}
static T_5
F_84 ( const T_6 * V_22 , T_12 * V_135 )
{
T_20 * V_122 ;
T_21 * V_20 ;
T_21 * * V_48 = V_134 ;
int V_66 ;
for ( V_66 = 0 ; V_66 < V_136 ; V_66 ++ ) {
V_20 = V_48 [ V_66 ] ;
while ( V_20 ) {
if ( strcmp ( V_20 -> V_22 , V_22 ) == 0 ) {
* V_135 = TRUE ;
return V_20 -> V_1 ;
}
V_20 = V_20 -> V_21 ;
}
}
if ( ( V_122 = F_78 ( V_22 ) ) == NULL ) {
* V_135 = FALSE ;
return 0 ;
}
V_20 = F_81 ( V_122 -> V_1 , V_22 ) ;
* V_135 = TRUE ;
return V_20 -> V_1 ;
}
static T_12
F_85 ( const char * V_137 )
{
T_3 * V_138 ;
char * line = NULL ;
int V_10 = 0 ;
T_6 * V_25 ;
T_1 V_62 [ 4 ] ;
struct V_82 V_91 ;
T_12 V_139 ;
int V_140 ;
if ( ( V_138 = F_18 ( V_137 , L_7 ) ) == NULL )
return FALSE ;
while ( F_5 ( & line , & V_10 , V_138 ) >= 0 ) {
if ( ( V_25 = strchr ( line , '#' ) ) )
* V_25 = '\0' ;
if ( ( V_25 = strtok ( line , L_1 ) ) == NULL )
continue;
V_140 = F_86 ( V_86 , V_25 , & V_62 ) ;
if ( V_140 == - 1 )
continue;
if ( V_140 == 1 ) {
V_139 = TRUE ;
} else {
if ( F_86 ( V_80 , V_25 , & V_62 ) != 1 )
continue;
V_139 = FALSE ;
}
if ( ( V_25 = strtok ( NULL , L_1 ) ) == NULL )
continue;
if ( V_139 ) {
memcpy ( & V_91 , V_62 , sizeof V_91 ) ;
F_87 ( & V_91 , V_25 ) ;
} else
F_88 ( V_62 [ 0 ] , V_25 ) ;
while ( ( V_25 = strtok ( NULL , L_1 ) ) != NULL ) {
if ( V_139 ) {
memcpy ( & V_91 , V_62 , sizeof V_91 ) ;
F_87 ( & V_91 , V_25 ) ;
} else
F_88 ( V_62 [ 0 ] , V_25 ) ;
}
}
F_16 ( line ) ;
fclose ( V_138 ) ;
return TRUE ;
}
T_12
F_89 ( const char * V_141 )
{
T_12 V_71 = FALSE ;
T_5 V_66 ;
if ( ! V_141 )
return FALSE ;
if ( ! V_142 )
V_142 = F_90 () ;
for ( V_66 = 0 ; V_66 < V_142 -> V_12 ; V_66 ++ ) {
if ( strcmp ( V_141 , ( const char * ) F_91 ( V_142 , V_66 ) ) == 0 )
V_71 = TRUE ;
}
if ( ! V_71 ) {
F_92 ( V_142 , F_55 ( V_141 ) ) ;
if ( V_143 ) {
return F_85 ( V_141 ) ;
}
}
return TRUE ;
}
T_12
F_93 ( const char * V_1 , const char * V_22 )
{
T_1 V_62 [ 4 ] ;
struct V_82 V_91 ;
T_12 V_139 ;
int V_140 ;
V_140 = F_86 ( V_86 , V_1 , & V_91 ) ;
if ( V_140 == - 1 )
return FALSE ;
if ( V_140 == 1 ) {
V_139 = TRUE ;
} else {
if ( F_86 ( V_80 , V_1 , & V_62 ) != 1 )
return FALSE ;
V_139 = FALSE ;
}
if ( V_139 ) {
F_87 ( & V_91 , V_22 ) ;
} else {
F_88 ( V_62 [ 0 ] , V_22 ) ;
}
return TRUE ;
}
struct V_144 *
F_94 ( void ) {
return V_143 ;
}
static T_12
F_95 ( const char * V_145 )
{
T_3 * V_138 ;
char * line = NULL ;
int V_10 = 0 ;
T_6 * V_25 , * V_146 ;
T_1 V_62 ;
int V_68 ;
if ( ( V_138 = F_18 ( V_145 , L_7 ) ) == NULL )
return FALSE ;
while ( F_5 ( & line , & V_10 , V_138 ) >= 0 ) {
if ( ( V_25 = strchr ( line , '#' ) ) )
* V_25 = '\0' ;
if ( ( V_25 = strtok ( line , L_1 ) ) == NULL )
continue;
V_146 = strchr ( V_25 , '/' ) ;
if( NULL == V_146 ) {
continue;
}
* V_146 = '\0' ;
++ V_146 ;
if ( F_86 ( V_80 , V_25 , & V_62 ) != 1 ) {
continue;
}
V_68 = atoi ( V_146 ) ;
if( 0 >= V_68 || V_68 > 31 ) {
continue;
}
if ( ( V_25 = strtok ( NULL , L_1 ) ) == NULL )
continue;
F_96 ( V_62 , ( T_1 ) V_68 , V_25 ) ;
}
F_16 ( line ) ;
fclose ( V_138 ) ;
return TRUE ;
}
static T_10
F_27 ( const T_1 V_1 )
{
T_10 V_59 ;
T_1 V_66 ;
V_66 = V_147 ;
while( V_148 && V_66 > 0 ) {
T_1 V_109 ;
T_22 * V_149 ;
-- V_66 ;
F_7 ( V_66 < V_147 ) ;
V_149 = & V_150 [ V_66 ] ;
if( NULL != V_149 -> V_151 ) {
T_9 * V_20 ;
T_1 V_19 ;
V_109 = V_1 & V_149 -> V_61 ;
V_19 = F_32 ( V_109 ) ;
V_20 = V_149 -> V_151 [ V_19 ] ;
while( V_20 != NULL && V_20 -> V_1 != V_109 ) {
V_20 = V_20 -> V_21 ;
}
if( NULL != V_20 ) {
V_59 . V_61 = V_149 -> V_61 ;
V_59 . V_68 = V_66 + 1 ;
V_59 . V_22 = V_20 -> V_22 ;
return V_59 ;
}
}
}
V_59 . V_61 = 0 ;
V_59 . V_68 = 0 ;
V_59 . V_22 = NULL ;
return V_59 ;
}
static void
F_96 ( T_1 V_152 , const T_1 V_68 , const T_6 * V_22 )
{
T_22 * V_153 ;
T_9 * V_20 ;
T_11 V_19 ;
F_7 ( V_68 > 0 && V_68 <= 32 ) ;
V_153 = & V_150 [ V_68 - 1 ] ;
V_152 &= V_153 -> V_61 ;
V_19 = F_32 ( V_152 ) ;
if( NULL == V_153 -> V_151 ) {
V_153 -> V_151 = ( T_9 * * ) F_60 ( sizeof( T_9 * ) * V_154 ) ;
}
if( NULL != ( V_20 = V_153 -> V_151 [ V_19 ] ) ) {
if( V_20 -> V_1 == V_152 ) {
return;
} else {
T_9 * V_155 = F_11 ( T_9 ) ;
V_20 -> V_21 = V_155 ;
V_20 = V_155 ;
}
} else {
V_20 = V_153 -> V_151 [ V_19 ] = F_11 ( T_9 ) ;
}
V_20 -> V_21 = NULL ;
V_20 -> V_1 = V_152 ;
V_20 -> V_60 = FALSE ;
F_12 ( V_20 -> V_22 , V_22 , V_23 ) ;
V_148 = TRUE ;
}
static T_1
F_97 ( const T_1 V_68 ) {
static T_1 V_156 [ V_147 ] ;
static T_12 V_157 = FALSE ;
if( ! V_157 ) {
memset ( V_156 , 0 , sizeof( V_156 ) ) ;
V_157 = TRUE ;
F_86 ( V_80 , L_23 , & V_156 [ 0 ] ) ;
F_86 ( V_80 , L_24 , & V_156 [ 1 ] ) ;
F_86 ( V_80 , L_25 , & V_156 [ 2 ] ) ;
F_86 ( V_80 , L_26 , & V_156 [ 3 ] ) ;
F_86 ( V_80 , L_27 , & V_156 [ 4 ] ) ;
F_86 ( V_80 , L_28 , & V_156 [ 5 ] ) ;
F_86 ( V_80 , L_29 , & V_156 [ 6 ] ) ;
F_86 ( V_80 , L_30 , & V_156 [ 7 ] ) ;
F_86 ( V_80 , L_31 , & V_156 [ 8 ] ) ;
F_86 ( V_80 , L_32 , & V_156 [ 9 ] ) ;
F_86 ( V_80 , L_33 , & V_156 [ 10 ] ) ;
F_86 ( V_80 , L_34 , & V_156 [ 11 ] ) ;
F_86 ( V_80 , L_35 , & V_156 [ 12 ] ) ;
F_86 ( V_80 , L_36 , & V_156 [ 13 ] ) ;
F_86 ( V_80 , L_37 , & V_156 [ 14 ] ) ;
F_86 ( V_80 , L_38 , & V_156 [ 15 ] ) ;
F_86 ( V_80 , L_39 , & V_156 [ 16 ] ) ;
F_86 ( V_80 , L_40 , & V_156 [ 17 ] ) ;
F_86 ( V_80 , L_41 , & V_156 [ 18 ] ) ;
F_86 ( V_80 , L_42 , & V_156 [ 19 ] ) ;
F_86 ( V_80 , L_43 , & V_156 [ 20 ] ) ;
F_86 ( V_80 , L_44 , & V_156 [ 21 ] ) ;
F_86 ( V_80 , L_45 , & V_156 [ 22 ] ) ;
F_86 ( V_80 , L_46 , & V_156 [ 23 ] ) ;
F_86 ( V_80 , L_47 , & V_156 [ 24 ] ) ;
F_86 ( V_80 , L_48 , & V_156 [ 25 ] ) ;
F_86 ( V_80 , L_49 , & V_156 [ 26 ] ) ;
F_86 ( V_80 , L_50 , & V_156 [ 27 ] ) ;
F_86 ( V_80 , L_51 , & V_156 [ 28 ] ) ;
F_86 ( V_80 , L_52 , & V_156 [ 29 ] ) ;
F_86 ( V_80 , L_53 , & V_156 [ 30 ] ) ;
F_86 ( V_80 , L_54 , & V_156 [ 31 ] ) ;
}
if( V_68 == 0 || V_68 > V_147 ) {
F_68 () ;
return 0 ;
} else {
return V_156 [ V_68 - 1 ] ;
}
}
static void
F_98 ( void )
{
T_6 * V_145 ;
T_1 V_66 ;
for( V_66 = 0 ; V_66 < V_147 ; ++ V_66 ) {
T_1 V_158 = V_66 + 1 ;
V_150 [ V_66 ] . V_151 = NULL ;
V_150 [ V_66 ] . V_68 = V_158 ;
V_150 [ V_66 ] . V_61 = F_97 ( V_158 ) ;
}
V_145 = F_20 ( V_159 , FALSE ) ;
if ( ! F_95 ( V_145 ) && V_160 != V_161 ) {
F_99 ( V_145 , V_160 , FALSE ) ;
}
F_16 ( V_145 ) ;
V_145 = F_21 ( V_159 ) ;
if ( ! F_95 ( V_145 ) && V_160 != V_161 ) {
F_99 ( V_145 , V_160 , FALSE ) ;
}
F_16 ( V_145 ) ;
}
void
F_100 ( T_23 * V_162 )
{
F_101 ( V_162 , L_55 ,
L_56 ,
L_57 ,
& V_56 . V_163 ) ;
F_101 ( V_162 , L_58 ,
L_59 ,
L_60 ,
& V_56 . V_57 ) ;
F_101 ( V_162 , L_61 ,
L_62 ,
L_63
L_64
L_65
L_66 ,
& V_56 . V_75 ) ;
F_101 ( V_162 , L_67 ,
L_68 ,
L_69
L_70
L_71
L_72 ,
& V_56 . V_76 ) ;
#if F_102 ( F_3 ) || F_102 ( V_164 )
F_101 ( V_162 , L_73 ,
L_74 ,
L_75
L_76
L_77 ,
& V_56 . V_77 ) ;
F_103 ( V_162 , L_78 ,
L_79 ,
L_80
L_81
L_82
L_83 ,
10 ,
& V_78 ) ;
#else
F_104 ( V_162 , L_73 ,
L_84 ,
L_85
L_86 ) ;
#endif
F_101 ( V_162 , L_87 ,
L_88 ,
L_89
L_90 ,
& V_56 . V_165 ) ;
}
void
F_105 ( void ) {
char * V_137 ;
struct V_144 * V_166 ;
T_5 V_66 ;
#ifdef V_164
#ifdef F_106
char * V_167 ;
static char V_168 [] = L_91 ;
static char V_169 [] = L_92 ;
#endif
#endif
if ( ! V_143 ) {
V_166 = F_107 ( struct V_144 ) ;
V_143 = V_170 = V_166 ;
}
V_137 = F_20 ( V_171 , TRUE ) ;
if ( ! F_85 ( V_137 ) && V_160 != V_161 ) {
F_99 ( V_137 , V_160 , FALSE ) ;
}
F_16 ( V_137 ) ;
if( ! V_56 . V_165 ) {
V_137 = F_21 ( V_171 ) ;
if ( ! F_85 ( V_137 ) && V_160 != V_161 ) {
F_99 ( V_137 , V_160 , FALSE ) ;
}
F_16 ( V_137 ) ;
}
#ifdef F_3
#ifdef F_108
if ( F_109 ( V_172 ) == V_173 ) {
#endif
if ( F_110 ( & V_174 ) == V_173 && F_110 ( & V_175 ) == V_173 ) {
V_79 = TRUE ;
}
#ifdef F_108
}
#endif
#else
#ifdef V_164
#ifdef F_106
V_167 = F_111 ( L_93 ) ;
if ( V_167 != NULL ) {
if( ! V_56 . V_165 ) {
V_137 = F_112 ( V_167 , V_168 , NULL ) ;
if ( ! F_85 ( V_137 ) ) {
F_16 ( V_137 ) ;
V_137 = F_112 ( V_167 , V_169 , NULL ) ;
F_85 ( V_137 ) ;
}
F_16 ( V_137 ) ;
}
}
#else
if( ! V_56 . V_165 ) {
F_85 ( L_94 ) ;
}
#endif
if ( F_113 ( & V_176 , V_177 , 0 ) != 0 ) {
return;
}
V_79 = TRUE ;
V_178 = 0 ;
#endif
#endif
if( V_142 && ! V_56 . V_165 ) {
for ( V_66 = 0 ; V_66 < V_142 -> V_12 ; V_66 ++ ) {
F_85 ( ( const char * ) F_91 ( V_142 , V_66 ) ) ;
}
}
F_98 () ;
}
T_12
F_114 ( void ) {
T_2 * V_84 ;
struct V_179 V_180 = { 0 , 0 } ;
int V_181 ;
T_24 V_182 , V_183 ;
T_12 V_184 = V_24 ;
V_24 = FALSE ;
if ( ! V_79 )
return V_184 ;
V_7 = F_115 ( V_7 ) ;
while ( V_7 != NULL && V_178 <= V_78 ) {
V_84 = ( T_2 * ) V_7 -> V_88 ;
V_7 = F_116 ( V_7 , ( void * ) V_84 ) ;
if ( V_84 -> V_3 == V_80 ) {
F_117 ( V_174 , & V_84 -> V_1 . V_4 , sizeof( T_1 ) , V_80 ,
V_185 , V_84 ) ;
V_178 ++ ;
} else if ( V_84 -> V_3 == V_86 ) {
F_117 ( V_174 , & V_84 -> V_1 . V_83 , sizeof( struct V_82 ) ,
V_86 , V_185 , V_84 ) ;
V_178 ++ ;
}
}
F_118 ( & V_182 ) ;
F_118 ( & V_183 ) ;
V_181 = F_119 ( V_174 , & V_182 , & V_183 ) ;
if ( V_181 > 0 ) {
if ( F_120 ( V_181 , & V_182 , & V_183 , NULL , & V_180 ) == - 1 ) {
fprintf ( V_186 , L_95 , strerror ( V_160 ) ) ;
return V_184 ;
}
F_121 ( V_174 , & V_182 , & V_183 ) ;
}
return V_184 ;
}
static void
F_122 ( void ) {
T_25 * V_187 ;
V_187 = F_115 ( V_7 ) ;
while ( V_187 ) {
F_16 ( V_187 -> V_88 ) ;
V_187 = F_123 ( V_187 ) ;
}
F_124 ( V_7 ) ;
V_7 = NULL ;
if ( V_79 ) {
F_125 ( V_174 ) ;
F_125 ( V_175 ) ;
}
#ifdef F_108
F_126 () ;
#endif
V_79 = FALSE ;
}
T_12
F_114 ( void ) {
T_2 * V_188 ;
T_25 * V_187 ;
char V_189 [] = L_96 ;
V_67 * V_190 ;
T_26 * V_191 ;
int V_140 ;
T_12 V_192 ;
T_12 V_184 = V_24 ;
V_24 = FALSE ;
V_7 = F_115 ( V_7 ) ;
V_187 = V_7 ;
while ( V_187 && V_178 <= V_78 ) {
V_188 = ( T_2 * ) V_187 -> V_88 ;
if ( ! V_188 -> V_6 && V_188 -> type == V_80 ) {
V_190 = ( V_67 * ) & V_188 -> V_5 ;
F_29 ( V_189 , sizeof V_189 , L_97 , V_190 [ 3 ] ,
V_190 [ 2 ] , V_190 [ 1 ] , V_190 [ 0 ] ) ;
F_127 ( V_176 , V_189 , V_193 , V_194 , NULL , & V_188 -> V_195 ) ;
V_188 -> V_6 = TRUE ;
V_178 ++ ;
}
V_187 = V_187 -> V_21 ;
}
V_187 = V_7 ;
while ( V_187 ) {
V_192 = FALSE ;
V_188 = ( T_2 * ) V_187 -> V_88 ;
if ( V_188 -> V_6 ) {
V_140 = F_128 ( V_176 , & V_188 -> V_195 , & V_191 , NULL ) ;
if ( V_140 == 0 ) {
if ( V_191 -> V_116 == V_196 ) {
F_88 ( V_188 -> V_5 , * V_191 -> V_197 . V_198 ) ;
}
V_192 = TRUE ;
}
}
V_187 = V_187 -> V_21 ;
if ( V_192 ) {
V_7 = F_116 ( V_7 , ( void * ) V_188 ) ;
F_16 ( V_188 ) ;
V_178 -- ;
}
}
return V_184 ;
}
static void
F_122 ( void ) {
void * V_199 ;
V_7 = F_115 ( V_7 ) ;
while ( V_7 ) {
V_199 = V_7 -> V_88 ;
V_7 = F_116 ( V_7 , V_199 ) ;
F_16 ( V_199 ) ;
}
if ( V_79 )
F_129 ( V_176 ) ;
V_79 = FALSE ;
}
T_12
F_114 ( void ) {
T_12 V_184 = V_24 ;
V_24 = FALSE ;
return V_184 ;
}
static void
F_122 ( void ) {
}
void
F_130 ( void ) {
F_122 () ;
memset ( V_74 , 0 , sizeof( V_74 ) ) ;
memset ( V_85 , 0 , sizeof( V_85 ) ) ;
memset ( V_33 , 0 , sizeof( V_33 ) ) ;
memset ( V_32 , 0 , sizeof( V_32 ) ) ;
memset ( V_35 , 0 , sizeof( V_35 ) ) ;
memset ( V_37 , 0 , sizeof( V_37 ) ) ;
memset ( V_121 , 0 , sizeof( V_121 ) ) ;
memset ( V_106 , 0 , sizeof( V_106 ) ) ;
memset ( V_107 , 0 , sizeof( V_107 ) ) ;
memset ( V_134 , 0 , sizeof( V_134 ) ) ;
memset ( V_150 , 0 , sizeof( V_150 ) ) ;
V_143 = V_170 = NULL ;
V_148 = FALSE ;
V_114 = FALSE ;
V_133 = FALSE ;
V_46 = FALSE ;
V_24 = FALSE ;
}
const T_6 *
F_42 ( const T_5 V_1 )
{
T_12 V_71 ;
T_9 * V_20 = F_31 ( V_1 , & V_71 ) ;
if ( ! V_56 . V_75 )
return V_20 -> V_70 ;
return V_20 -> V_22 ;
}
const T_6 *
F_43 ( const struct V_82 * V_1 )
{
T_12 V_71 ;
T_13 * V_20 = F_37 ( V_1 , & V_71 ) ;
if ( ! V_56 . V_75 )
return V_20 -> V_83 ;
return V_20 -> V_22 ;
}
void
F_88 ( const T_5 V_1 , const T_6 * V_22 )
{
int V_19 ;
T_9 * V_20 ;
struct V_144 * V_166 ;
struct V_200 * V_201 ;
V_19 = F_32 ( V_1 ) ;
V_20 = V_74 [ V_19 ] ;
if( V_20 == NULL ) {
V_20 = V_74 [ V_19 ] = F_30 ( V_1 ) ;
} else {
while( 1 ) {
if ( V_20 -> V_1 == V_1 ) {
if ( ! V_20 -> V_60 ) {
return;
} else {
break;
}
}
if ( V_20 -> V_21 == NULL ) {
V_20 -> V_21 = F_30 ( V_1 ) ;
V_20 = V_20 -> V_21 ;
break;
}
V_20 = V_20 -> V_21 ;
}
}
F_12 ( V_20 -> V_22 , V_22 , V_23 ) ;
V_20 -> V_69 = TRUE ;
V_24 = TRUE ;
if ( ! V_143 ) {
V_166 = F_107 ( struct V_144 ) ;
V_143 = V_170 = V_166 ;
}
V_201 = F_107 ( struct V_200 ) ;
V_201 -> V_202 = V_80 ;
V_201 -> V_203 . V_204 = V_1 ;
V_166 = F_107 ( struct V_144 ) ;
V_166 -> V_205 = V_80 ;
V_166 -> V_206 = sizeof( struct V_200 ) ;
V_166 -> V_207 = ( char * ) V_20 -> V_22 ;
V_166 -> V_208 = (struct V_209 * ) V_201 ;
V_170 -> V_210 = V_166 ;
V_170 = V_166 ;
}
void
F_87 ( const struct V_82 * V_211 , const T_6 * V_22 )
{
int V_19 ;
T_13 * V_20 ;
struct V_144 * V_166 ;
struct V_212 * V_213 ;
V_19 = F_39 ( * V_211 ) ;
V_20 = V_85 [ V_19 ] ;
if( V_20 == NULL ) {
V_20 = V_85 [ V_19 ] = F_35 ( V_211 ) ;
} else {
while( 1 ) {
if ( memcmp ( & V_20 -> V_1 , V_211 , sizeof ( struct V_82 ) ) == 0 ) {
if ( ! V_20 -> V_60 ) {
return;
} else {
break;
}
}
if ( V_20 -> V_21 == NULL ) {
V_20 -> V_21 = F_35 ( V_211 ) ;
V_20 = V_20 -> V_21 ;
break;
}
V_20 = V_20 -> V_21 ;
}
}
F_12 ( V_20 -> V_22 , V_22 , V_23 ) ;
V_20 -> V_69 = TRUE ;
V_24 = TRUE ;
if ( ! V_143 ) {
V_166 = F_107 ( struct V_144 ) ;
V_143 = V_170 = V_166 ;
}
V_213 = F_107 ( struct V_212 ) ;
V_213 -> V_214 = V_80 ;
memcpy ( V_213 -> V_215 . V_216 , V_211 , 16 ) ;
V_166 = F_107 ( struct V_144 ) ;
V_166 -> V_205 = V_86 ;
V_166 -> V_206 = sizeof( struct V_200 ) ;
V_166 -> V_207 = ( char * ) V_20 -> V_22 ;
V_166 -> V_208 = (struct V_209 * ) V_213 ;
V_170 -> V_210 = V_166 ;
V_170 = V_166 ;
}
static T_6 *
F_131 ( T_5 V_17 )
{
T_6 * V_217 = ( T_6 * ) F_132 ( V_23 ) ;
F_25 ( V_17 , V_217 , V_23 ) ;
return V_217 ;
}
T_6 *
F_133 ( T_5 V_17 )
{
if ( ! V_56 . V_57 ) {
return F_131 ( V_17 ) ;
}
return F_22 ( V_17 , V_52 ) ;
}
T_6 *
F_134 ( T_5 V_17 )
{
if ( ! V_56 . V_57 ) {
return F_131 ( V_17 ) ;
}
return F_22 ( V_17 , V_55 ) ;
}
T_6 *
F_135 ( T_5 V_17 )
{
if ( ! V_56 . V_57 ) {
return F_131 ( V_17 ) ;
}
return F_22 ( V_17 , V_53 ) ;
}
T_6 *
F_136 ( T_5 V_17 )
{
if ( ! V_56 . V_57 ) {
return F_131 ( V_17 ) ;
}
return F_22 ( V_17 , V_54 ) ;
}
const T_6 *
F_137 ( const T_14 * V_1 )
{
const T_6 * V_218 ;
V_218 = F_40 ( V_1 ) ;
if ( V_218 != NULL )
return V_218 ;
if ( V_1 -> type == V_219 ) {
return L_98 ;
}
return F_138 ( V_1 ) ;
}
const T_6 *
F_139 ( const T_14 * V_1 )
{
const T_6 * V_218 ;
V_218 = F_44 ( V_1 ) ;
if ( V_218 != NULL )
return V_218 ;
if ( V_1 -> type == V_219 ) {
return L_98 ;
}
return F_140 ( V_1 ) ;
}
void
F_141 ( const T_14 * V_1 , T_6 * V_9 , T_11 V_10 )
{
const T_6 * V_218 = F_137 ( V_1 ) ;
F_12 ( V_9 , V_218 , V_10 ) ;
}
T_6 *
F_41 ( const V_67 * V_1 )
{
T_19 * V_20 ;
T_12 V_69 = V_56 . V_163 ;
if ( V_69 && ! V_114 ) {
F_63 () ;
}
V_20 = F_72 ( V_1 , V_69 ) ;
return V_69 ? V_20 -> V_115 : V_20 -> V_120 ;
}
T_6 *
F_142 ( const V_67 * V_1 )
{
T_19 * V_20 ;
if ( ! V_56 . V_163 )
return NULL ;
if ( ! V_114 ) {
F_63 () ;
}
V_20 = F_72 ( V_1 , TRUE ) ;
F_7 ( V_20 != NULL ) ;
if ( V_20 -> V_116 == V_117 ) {
return V_20 -> V_115 ;
}
else {
return NULL ;
}
}
V_67 *
F_143 ( const T_6 * V_22 )
{
if ( ! V_114 ) {
F_63 () ;
}
return F_73 ( V_22 ) ;
}
void
F_144 ( const T_5 V_70 , const V_67 * V_94 )
{
T_12 V_71 ;
T_9 * V_20 ;
if ( ! V_56 . V_75 )
return;
V_20 = F_31 ( V_70 , & V_71 ) ;
if ( V_71 ) {
F_58 ( V_94 , V_20 -> V_22 ) ;
}
}
const T_6 *
F_145 ( const T_1 V_1 )
{
if ( ! V_56 . V_75 ) {
return F_146 ( V_1 , '\0' ) ;
}
if ( ! V_133 ) {
F_80 () ;
}
return F_83 ( V_1 ) ;
}
T_1
F_147 ( const T_6 * V_22 , T_12 * V_220 )
{
T_1 V_1 ;
T_12 V_135 ;
if ( ! V_133 ) {
F_80 () ;
}
V_1 = F_84 ( V_22 , & V_135 ) ;
* V_220 = V_135 ;
return V_1 ;
}
const T_6 *
F_148 ( const V_67 * V_1 )
{
T_6 * V_187 ;
T_16 * V_103 ;
if ( V_56 . V_163 && ! V_114 ) {
F_63 () ;
}
if ( ! V_56 . V_163 || ( ( V_103 = F_61 ( V_1 ) ) == NULL ) ) {
V_187 = F_149 ( L_99 , V_1 [ 0 ] , V_1 [ 1 ] , V_1 [ 2 ] ) ;
return V_187 ;
}
return V_103 -> V_22 ;
}
const T_6 *
F_150 ( const T_5 V_221 )
{
V_67 V_1 [ 3 ] ;
V_1 [ 0 ] = ( V_221 >> 16 ) & 0xFF ;
V_1 [ 1 ] = ( V_221 >> 8 ) & 0xFF ;
V_1 [ 2 ] = ( V_221 >> 0 ) & 0xFF ;
return F_148 ( V_1 ) ;
}
const T_6 *
F_151 ( T_27 * V_222 , T_18 V_223 )
{
return F_148 ( F_152 ( V_222 , V_223 , 3 ) ) ;
}
const T_6 *
F_153 ( const V_67 * V_1 )
{
T_16 * V_103 ;
if ( ! V_114 ) {
F_63 () ;
}
if ( ( V_103 = F_61 ( V_1 ) ) == NULL ) {
return NULL ;
}
return V_103 -> V_22 ;
}
const T_6 *
F_154 ( const T_5 V_221 )
{
V_67 V_1 [ 3 ] ;
V_1 [ 0 ] = ( V_221 >> 16 ) & 0xFF ;
V_1 [ 1 ] = ( V_221 >> 8 ) & 0xFF ;
V_1 [ 2 ] = ( V_221 >> 0 ) & 0xFF ;
return F_153 ( V_1 ) ;
}
const T_6 *
F_155 ( T_27 * V_222 , T_18 V_223 )
{
return F_153 ( F_152 ( V_222 , V_223 , 3 ) ) ;
}
const T_6 *
F_156 ( const T_28 V_224 )
{
T_6 * V_187 ;
T_16 * V_103 ;
V_67 * V_1 = ( V_67 * ) F_132 ( 8 ) ;
* ( T_28 * ) ( void * ) ( V_1 ) = F_157 ( & ( V_224 ) ) ;
if ( V_56 . V_163 && ! V_114 ) {
F_63 () ;
}
if ( ! V_56 . V_163 || ( ( V_103 = F_61 ( V_1 ) ) == NULL ) ) {
V_187 = F_149 ( L_100 , V_1 [ 0 ] , V_1 [ 1 ] , V_1 [ 2 ] , V_1 [ 3 ] , V_1 [ 4 ] , V_1 [ 5 ] , V_1 [ 6 ] , V_1 [ 7 ] ) ;
return V_187 ;
}
V_187 = F_149 ( L_15 , V_103 -> V_22 , V_1 [ 3 ] , V_1 [ 4 ] , V_1 [ 5 ] , V_1 [ 6 ] , V_1 [ 7 ] ) ;
return V_187 ;
}
const T_6 *
F_158 ( const T_28 V_224 )
{
T_6 * V_187 ;
T_16 * V_103 ;
V_67 * V_1 = ( V_67 * ) F_132 ( 8 ) ;
* ( T_28 * ) ( void * ) ( V_1 ) = F_157 ( & ( V_224 ) ) ;
if ( ! V_114 ) {
F_63 () ;
}
if ( ( V_103 = F_61 ( V_1 ) ) == NULL ) {
return NULL ;
}
V_187 = F_149 ( L_15 , V_103 -> V_22 , V_1 [ 3 ] , V_1 [ 4 ] , V_1 [ 5 ] , V_1 [ 6 ] , V_1 [ 7 ] ) ;
return V_187 ;
}
T_12
F_159 ( const char * V_225 , T_1 * V_211 )
{
struct V_226 V_227 ;
#ifdef F_3
struct V_179 V_180 = { 0 , V_228 } , * V_229 ;
int V_181 ;
T_24 V_182 , V_183 ;
T_29 V_230 ;
#else
struct V_72 * V_231 ;
#endif
if ( ! F_160 ( V_225 , & V_227 ) ) {
if ( ! V_56 . V_75 ||
! V_56 . V_76 ) {
return FALSE ;
}
#ifdef F_3
if ( ! ( V_56 . V_77 ) ||
V_78 < 1 ||
! V_79 ) {
return FALSE ;
}
V_230 . V_232 = ( int ) sizeof ( struct V_226 ) ;
V_230 . V_233 = 0 ;
V_230 . V_211 = V_211 ;
F_161 ( V_175 , V_225 , V_80 , V_234 , & V_230 ) ;
F_118 ( & V_182 ) ;
F_118 ( & V_183 ) ;
V_181 = F_119 ( V_175 , & V_182 , & V_183 ) ;
if ( V_181 > 0 ) {
V_229 = F_162 ( V_175 , & V_180 , & V_180 ) ;
if ( F_120 ( V_181 , & V_182 , & V_183 , NULL , V_229 ) == - 1 ) {
fprintf ( V_186 , L_95 , strerror ( V_160 ) ) ;
return FALSE ;
}
F_121 ( V_175 , & V_182 , & V_183 ) ;
}
F_163 ( V_175 ) ;
if ( V_230 . V_232 == V_230 . V_233 ) {
return TRUE ;
}
return FALSE ;
#else
V_231 = F_164 ( V_225 ) ;
if ( V_231 == NULL ) {
return FALSE ;
} else if ( V_231 -> V_235 <= ( int ) sizeof ( struct V_226 ) ) {
memcpy ( & V_227 , V_231 -> V_236 , V_231 -> V_235 ) ;
} else {
return FALSE ;
}
#endif
} else {
unsigned int V_124 , V_125 , V_126 , V_127 ;
if ( sscanf ( V_225 , L_101 , & V_124 , & V_125 , & V_126 , & V_127 ) != 4 )
return FALSE ;
}
* V_211 = V_227 . V_204 ;
return TRUE ;
}
T_12
F_165 ( const char * V_225 , struct V_82 * V_211 )
{
#ifdef F_3
struct V_179 V_180 = { 0 , V_228 } , * V_229 ;
int V_181 ;
T_24 V_182 , V_183 ;
T_29 V_230 ;
#elif F_102 ( V_237 )
struct V_72 * V_231 ;
#endif
if ( F_86 ( V_86 , V_225 , V_211 ) == 1 )
return TRUE ;
if ( ! V_56 . V_75 ||
! V_56 . V_76 ) {
return FALSE ;
}
#ifdef F_3
if ( ! ( V_56 . V_77 ) ||
V_78 < 1 ||
! V_79 ) {
return FALSE ;
}
V_230 . V_232 = ( int ) sizeof ( struct V_82 ) ;
V_230 . V_233 = 0 ;
V_230 . V_211 = V_211 ;
F_161 ( V_175 , V_225 , V_86 , V_234 , & V_230 ) ;
F_118 ( & V_182 ) ;
F_118 ( & V_183 ) ;
V_181 = F_119 ( V_175 , & V_182 , & V_183 ) ;
if ( V_181 > 0 ) {
V_229 = F_162 ( V_175 , & V_180 , & V_180 ) ;
if ( F_120 ( V_181 , & V_182 , & V_183 , NULL , V_229 ) == - 1 ) {
fprintf ( V_186 , L_95 , strerror ( V_160 ) ) ;
return FALSE ;
}
F_121 ( V_175 , & V_182 , & V_183 ) ;
}
F_163 ( V_175 ) ;
if ( V_230 . V_232 == V_230 . V_233 ) {
return TRUE ;
}
#elif F_102 ( V_237 )
V_231 = F_166 ( V_225 , V_86 ) ;
if ( V_231 != NULL && V_231 -> V_235 == sizeof( struct V_82 ) ) {
memcpy ( V_211 , V_231 -> V_236 , V_231 -> V_235 ) ;
return TRUE ;
}
#endif
return FALSE ;
}
const char * F_167 ( const char * V_225
#ifndef V_237
V_238
#endif
)
{
#ifdef V_237
struct V_72 * V_239 ;
return ( V_239 = F_166 ( V_225 , V_86 ) ) && V_239 -> V_240 == V_86 ? L_102 : L_103 ;
#else
return L_103 ;
#endif
}
