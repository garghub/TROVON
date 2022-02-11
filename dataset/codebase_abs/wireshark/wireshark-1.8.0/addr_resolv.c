static void
F_1 ( int type , T_1 V_1 )
{
T_2 * V_2 ;
V_2 = F_2 ( sizeof( T_2 ) ) ;
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
* V_9 = F_2 ( * V_10 ) ;
}
F_6 ( * V_9 ) ;
F_6 ( * V_10 > 0 ) ;
if ( feof ( V_11 ) )
return - 1 ;
V_12 = 0 ;
while ( ( V_13 = getc ( V_11 ) ) != V_15 && V_13 != '\r' && V_13 != '\n' ) {
if ( V_12 + 1 >= * V_10 ) {
* V_9 = F_7 ( * V_9 , * V_10 += V_14 ) ;
}
( * V_9 ) [ V_12 ++ ] = V_13 ;
}
if ( V_12 == 0 && V_13 == V_15 )
return - 1 ;
( * V_9 ) [ V_12 ] = '\0' ;
return V_12 ;
}
static void
F_8 ( T_4 * * V_16 , const T_5 V_17 , const char * V_18 )
{
int V_19 ;
T_4 * V_20 ;
V_19 = F_9 ( V_17 ) ;
V_20 = V_16 [ V_19 ] ;
if( V_20 == NULL ) {
V_20 = V_16 [ V_19 ] = ( T_4 * ) F_2 ( sizeof( T_4 ) ) ;
} else {
while( 1 ) {
if( V_20 -> V_17 == V_17 ) {
return;
}
if ( V_20 -> V_21 == NULL ) {
V_20 -> V_21 = ( T_4 * ) F_2 ( sizeof( T_4 ) ) ;
V_20 = V_20 -> V_21 ;
break;
}
V_20 = V_20 -> V_21 ;
}
}
V_20 -> V_17 = V_17 ;
V_20 -> V_21 = NULL ;
F_10 ( V_20 -> V_22 , V_18 , V_23 ) ;
V_24 = TRUE ;
}
static void
F_11 ( char * line )
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
if( V_38 != F_12 ( & V_27 , V_17 , V_28 ) ) {
return;
}
V_39 = V_26 ;
F_13 ( V_27 , V_40 ) ;
F_14 ( V_27 ) ;
}
static void
V_40 ( const T_1 V_17 )
{
if ( V_17 ) {
F_8 ( V_31 , V_17 , V_39 ) ;
}
}
static void
F_15 ( const char * V_41 )
{
T_3 * V_42 ;
static int V_10 = 0 ;
static char * V_9 = NULL ;
V_42 = F_16 ( V_41 , L_7 ) ;
if ( V_42 == NULL )
return;
while ( F_5 ( & V_9 , & V_10 , V_42 ) >= 0 ) {
F_11 ( V_9 ) ;
}
fclose ( V_42 ) ;
}
static void
F_17 ( void )
{
if ( V_43 == NULL )
V_43 = F_18 ( V_44 , FALSE , FALSE ) ;
F_15 ( V_43 ) ;
if ( V_45 == NULL ) {
V_45 = F_19 ( V_44 ) ;
}
F_15 ( V_45 ) ;
}
static T_6
* F_20 ( const T_5 V_17 , const T_8 V_46 )
{
int V_19 ;
T_4 * V_20 ;
T_4 * * V_47 ;
const char * V_48 = NULL ;
struct V_49 * V_50 ;
if ( ! V_51 ) {
F_17 () ;
V_51 = 1 ;
}
switch( V_46 ) {
case V_52 :
V_47 = V_33 ;
V_48 = L_4 ;
break;
case V_53 :
V_47 = V_32 ;
V_48 = L_3 ;
break;
case V_54 :
V_47 = V_35 ;
V_48 = L_5 ;
break;
case V_55 :
V_47 = V_37 ;
V_48 = L_8 ;
break;
default:
return NULL ;
}
V_19 = F_9 ( V_17 ) ;
V_20 = V_47 [ V_19 ] ;
if( V_20 == NULL ) {
V_20 = V_47 [ V_19 ] = ( T_4 * ) F_2 ( sizeof( T_4 ) ) ;
} else {
while( 1 ) {
if( V_20 -> V_17 == V_17 ) {
return V_20 -> V_22 ;
}
if ( V_20 -> V_21 == NULL ) {
V_20 -> V_21 = ( T_4 * ) F_2 ( sizeof( T_4 ) ) ;
V_20 = V_20 -> V_21 ;
break;
}
V_20 = V_20 -> V_21 ;
}
}
V_20 -> V_17 = V_17 ;
V_20 -> V_21 = NULL ;
if ( ! ( V_56 & V_57 ) ||
( V_50 = F_21 ( F_22 ( V_17 ) , V_48 ) ) == NULL ) {
F_23 ( V_17 , V_20 -> V_22 , V_23 ) ;
} else {
F_10 ( V_20 -> V_22 , V_50 -> V_58 , V_23 ) ;
}
return ( V_20 -> V_22 ) ;
}
static void
F_24 ( const T_5 V_1 , T_9 * volatile V_20 )
{
T_10 V_59 ;
if ( V_20 -> V_60 )
return;
V_20 -> V_60 = TRUE ;
V_59 = F_25 ( V_1 ) ;
if( 0 != V_59 . V_61 ) {
T_1 V_62 ;
T_6 V_63 [ V_64 ] ;
T_6 * V_65 ;
T_11 V_66 ;
V_62 = V_1 & ( ~ ( T_1 ) V_59 . V_61 ) ;
F_26 ( ( V_67 * ) & V_62 , V_63 , V_64 ) ;
V_65 = V_63 ;
V_66 = V_59 . V_68 / 8 ;
while( * ( V_65 ) != '\0' && V_66 > 0 ) {
if( * ( ++ V_65 ) == '.' ) {
-- V_66 ;
}
}
F_27 ( V_20 -> V_22 , V_23 , L_9 , V_59 . V_22 , V_65 ) ;
} else {
F_26 ( ( const V_67 * ) & V_1 , V_20 -> V_22 , V_23 ) ;
}
}
static T_9 *
F_28 ( const T_5 V_1 )
{
T_9 * V_20 = F_2 ( sizeof( T_9 ) ) ;
V_20 -> V_1 = V_1 ;
V_20 -> V_21 = NULL ;
V_20 -> V_69 = FALSE ;
V_20 -> V_60 = FALSE ;
F_26 ( ( const V_67 * ) & V_1 , V_20 -> V_70 , sizeof( V_20 -> V_70 ) ) ;
return V_20 ;
}
static T_9 *
F_29 ( const T_5 V_1 , const T_12 V_69 , T_12 * V_71 )
{
int V_19 ;
T_9 * volatile V_20 ;
struct V_72 * V_73 ;
* V_71 = TRUE ;
V_19 = F_30 ( V_1 ) ;
V_20 = V_74 [ V_19 ] ;
if( V_20 == NULL ) {
V_20 = V_74 [ V_19 ] = F_28 ( V_1 ) ;
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
V_20 -> V_21 = F_28 ( V_1 ) ;
V_20 = V_20 -> V_21 ;
break;
}
V_20 = V_20 -> V_21 ;
}
}
if ( V_69 ) {
V_20 -> V_69 = TRUE ;
#ifdef F_31
if ( ( V_56 & V_75 ) &&
V_76 . V_77 > 0 &&
V_78 ) {
F_1 ( V_79 , V_1 ) ;
F_24 ( V_1 , V_20 ) ;
return V_20 ;
}
#endif
if ( V_1 != 0 && ( V_56 & V_80 ) ) {
V_73 = F_32 ( ( char * ) & V_1 , 4 , V_79 ) ;
if ( V_73 != NULL ) {
F_10 ( V_20 -> V_22 , V_73 -> V_81 , V_23 ) ;
V_20 -> V_60 = FALSE ;
return V_20 ;
}
}
}
* V_71 = FALSE ;
F_24 ( V_1 , V_20 ) ;
return V_20 ;
}
static T_6 *
F_33 ( const T_5 V_1 , T_12 * V_71 )
{
T_9 * V_20 ;
V_20 = F_29 ( V_1 , TRUE , V_71 ) ;
return V_20 -> V_22 ;
}
static T_13 *
F_34 ( const struct V_82 * V_1 )
{
T_13 * V_20 = F_2 ( sizeof( T_13 ) ) ;
V_20 -> V_1 = * V_1 ;
V_20 -> V_21 = NULL ;
V_20 -> V_69 = FALSE ;
V_20 -> V_60 = FALSE ;
F_35 ( V_1 , V_20 -> V_83 ) ;
return V_20 ;
}
static T_13 *
F_36 ( const struct V_82 * V_1 , const T_12 V_69 , T_12 * V_71 )
{
int V_19 ;
T_13 * volatile V_20 ;
#ifdef F_37
#ifdef F_3
T_2 * V_84 ;
#endif
struct V_72 * V_73 ;
#endif
* V_71 = TRUE ;
V_19 = F_38 ( * V_1 ) ;
V_20 = V_85 [ V_19 ] ;
if( V_20 == NULL ) {
V_20 = V_85 [ V_19 ] = F_34 ( V_1 ) ;
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
V_20 -> V_21 = F_34 ( V_1 ) ;
V_20 = V_20 -> V_21 ;
break;
}
V_20 = V_20 -> V_21 ;
}
}
if ( V_69 ) {
V_20 -> V_69 = TRUE ;
#ifdef F_37
#ifdef F_3
if ( ( V_56 & V_75 ) &&
V_76 . V_77 > 0 &&
V_78 ) {
V_84 = F_2 ( sizeof( T_2 ) ) ;
V_84 -> V_3 = V_86 ;
memcpy ( & V_84 -> V_1 . V_83 , V_1 , sizeof( V_84 -> V_1 . V_83 ) ) ;
V_7 = F_4 ( V_7 , ( V_8 ) V_84 ) ;
if ( ! V_20 -> V_60 ) {
F_10 ( V_20 -> V_22 , V_20 -> V_83 , V_23 ) ;
F_35 ( V_1 , V_20 -> V_22 ) ;
V_20 -> V_60 = TRUE ;
}
return V_20 ;
}
#endif
V_73 = F_32 ( ( char * ) V_1 , sizeof( * V_1 ) , V_86 ) ;
if ( V_73 != NULL ) {
F_10 ( V_20 -> V_22 , V_73 -> V_81 , V_23 ) ;
V_20 -> V_60 = FALSE ;
return V_20 ;
}
#endif
}
if ( ! V_20 -> V_60 ) {
V_20 -> V_60 = TRUE ;
F_10 ( V_20 -> V_22 , V_20 -> V_83 , V_23 ) ;
}
* V_71 = FALSE ;
return V_20 ;
}
static const T_6 *
F_39 ( const T_14 * V_1 )
{
switch ( V_1 -> type ) {
case V_87 :
return F_40 ( V_1 -> V_88 ) ;
case V_89 : {
T_1 V_5 ;
memcpy ( & V_5 , V_1 -> V_88 , sizeof V_5 ) ;
return F_41 ( V_5 ) ;
}
case V_90 : {
struct V_82 V_91 ;
memcpy ( & V_91 . V_92 , V_1 -> V_88 , sizeof V_91 . V_92 ) ;
return F_42 ( & V_91 ) ;
}
case V_93 :
return V_1 -> V_88 ;
default:
return NULL ;
}
}
static const T_6 *
F_43 ( const T_14 * V_1 )
{
switch ( V_1 -> type ) {
case V_87 :
return F_40 ( V_1 -> V_88 ) ;
case V_89 : {
T_1 V_5 ;
memcpy ( & V_5 , V_1 -> V_88 , sizeof V_5 ) ;
return F_41 ( V_5 ) ;
}
case V_90 : {
struct V_82 V_91 ;
memcpy ( & V_91 . V_92 , V_1 -> V_88 , sizeof V_91 . V_92 ) ;
return F_42 ( & V_91 ) ;
}
case V_93 :
return F_44 ( V_1 -> V_88 ) ;
default:
return NULL ;
}
}
static T_12
F_45 ( const char * V_25 , T_15 * V_94 , unsigned int * V_61 ,
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
* V_61 = V_96 ;
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
F_46 ( char * line , T_15 * V_94 , unsigned int * V_61 ,
const T_12 V_95 )
{
T_6 * V_25 ;
if ( ( V_25 = strchr ( line , '#' ) ) )
* V_25 = '\0' ;
if ( ( V_25 = strtok ( line , L_1 ) ) == NULL )
return - 1 ;
if ( ! F_45 ( V_25 , V_94 , V_61 , V_95 ) )
return - 1 ;
if ( ( V_25 = strtok ( NULL , L_1 ) ) == NULL )
return - 1 ;
F_10 ( V_94 -> V_22 , V_25 , V_23 ) ;
return 0 ;
}
static void
F_47 ( char * V_41 )
{
if ( V_99 )
rewind ( V_99 ) ;
else
V_99 = F_16 ( V_41 , L_7 ) ;
}
static void
F_48 ( void )
{
if ( V_99 ) {
fclose ( V_99 ) ;
V_99 = NULL ;
}
}
static T_15 *
F_49 ( unsigned int * V_61 , const T_12 V_95 )
{
static T_15 V_94 ;
static int V_10 = 0 ;
static char * V_9 = NULL ;
if ( V_99 == NULL )
return NULL ;
while ( F_5 ( & V_9 , & V_10 , V_99 ) >= 0 ) {
if ( F_46 ( V_9 , & V_94 , V_61 , V_95 ) == 0 ) {
return & V_94 ;
}
}
return NULL ;
}
static T_15 *
F_50 ( const T_6 * V_22 )
{
T_15 * V_94 ;
F_47 ( V_100 ) ;
while ( ( ( V_94 = F_49 ( NULL , FALSE ) ) != NULL ) && strncmp ( V_22 , V_94 -> V_22 , V_23 ) != 0 )
;
if ( V_94 == NULL ) {
F_48 () ;
F_47 ( V_101 ) ;
while ( ( ( V_94 = F_49 ( NULL , FALSE ) ) != NULL ) && strncmp ( V_22 , V_94 -> V_22 , V_23 ) != 0 )
;
F_48 () ;
}
return V_94 ;
}
static T_15 *
F_51 ( const V_67 * V_1 )
{
T_15 * V_94 ;
F_47 ( V_100 ) ;
while ( ( ( V_94 = F_49 ( NULL , FALSE ) ) != NULL ) && memcmp ( V_1 , V_94 -> V_1 , 6 ) != 0 )
;
if ( V_94 == NULL ) {
F_48 () ;
F_47 ( V_101 ) ;
while ( ( ( V_94 = F_49 ( NULL , FALSE ) ) != NULL ) && memcmp ( V_1 , V_94 -> V_1 , 6 ) != 0 )
;
F_48 () ;
}
return V_94 ;
}
static int
F_52 ( const V_67 * V_1 , unsigned int V_61 )
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
F_53 ( const V_67 * V_1 , T_6 * V_22 )
{
T_16 * V_103 ;
V_103 = ( T_16 * ) F_2 ( sizeof( T_16 ) ) ;
memcpy ( V_103 -> V_1 , V_1 , sizeof( V_103 -> V_1 ) ) ;
V_103 -> V_22 = F_54 ( V_22 ) ;
V_103 -> V_21 = NULL ;
return V_103 ;
}
static T_17 *
F_55 ( const V_67 * V_1 , T_6 * V_22 )
{
T_17 * V_104 ;
V_104 = ( T_17 * ) F_2 ( sizeof( T_17 ) ) ;
memcpy ( V_104 -> V_1 , V_1 , sizeof( V_104 -> V_1 ) ) ;
F_10 ( V_104 -> V_22 , V_22 , V_23 ) ;
V_104 -> V_21 = NULL ;
return V_104 ;
}
static void
F_56 ( const V_67 * V_1 , unsigned int V_61 , T_6 * V_22 )
{
T_18 V_19 ;
T_16 * V_103 ;
T_17 * ( * V_105 ) [ V_102 ] , * V_104 ;
if ( V_61 >= 48 ) {
F_57 ( V_1 , V_22 ) ;
return;
}
if ( V_61 == 0 ) {
V_19 = F_58 ( V_1 ) ;
V_103 = V_106 [ V_19 ] ;
if( V_103 == NULL ) {
V_106 [ V_19 ] = F_53 ( V_1 , V_22 ) ;
return;
} else {
while( TRUE ) {
if ( V_103 -> V_21 == NULL ) {
V_103 -> V_21 = F_53 ( V_1 , V_22 ) ;
return;
}
V_103 = V_103 -> V_21 ;
}
}
}
V_105 = V_107 [ V_61 ] ;
if ( V_105 == NULL )
V_105 = V_107 [ V_61 ] = F_59 ( sizeof * V_107 [ V_61 ] ) ;
V_19 = F_52 ( V_1 , V_61 ) ;
V_104 = ( * V_105 ) [ V_19 ] ;
if( V_104 == NULL ) {
( * V_105 ) [ V_19 ] = F_55 ( V_1 , V_22 ) ;
return;
} else {
while( TRUE ) {
if ( memcmp ( V_104 -> V_1 , V_1 , sizeof( V_104 -> V_1 ) ) == 0 ) {
return;
}
if ( V_104 -> V_21 == NULL ) {
V_104 -> V_21 = F_55 ( V_1 , V_22 ) ;
return;
}
V_104 = V_104 -> V_21 ;
}
}
}
static T_16 *
F_60 ( const V_67 * V_1 )
{
T_18 V_19 ;
T_16 * V_103 ;
V_67 V_108 [ 3 ] ;
V_19 = F_58 ( V_1 ) ;
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
F_61 ( const V_67 * V_1 , const unsigned int V_61 )
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
V_19 = F_52 ( V_109 , V_61 ) ;
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
F_62 ( void )
{
T_15 * V_94 ;
char * V_110 ;
T_5 V_61 ;
if ( V_101 == NULL ) {
V_101 = F_63 ( L_10 V_111 L_10 ,
F_64 () , V_112 ) ;
}
if ( V_100 == NULL )
V_100 = F_18 ( V_112 , FALSE , FALSE ) ;
V_110 = F_19 ( V_113 ) ;
F_47 ( V_110 ) ;
while ( ( V_94 = F_49 ( & V_61 , TRUE ) ) ) {
F_56 ( V_94 -> V_1 , V_61 , V_94 -> V_22 ) ;
}
F_48 () ;
F_14 ( V_110 ) ;
}
static T_19 *
F_65 ( T_19 * V_20 ) {
T_15 * V_94 ;
const V_67 * V_1 = V_20 -> V_1 ;
if ( ( V_94 = F_51 ( V_1 ) ) != NULL ) {
F_10 ( V_20 -> V_114 , V_94 -> V_22 , V_23 ) ;
V_20 -> V_115 = V_116 ;
return V_20 ;
} else {
T_17 * V_104 ;
T_16 * V_103 ;
T_5 V_61 ;
V_61 = 7 ;
for (; ; ) {
if ( ( V_104 = F_61 ( V_1 , V_61 + 40 ) ) != NULL ) {
F_27 ( V_20 -> V_114 , V_23 , L_11 ,
V_104 -> V_22 , V_1 [ 5 ] & ( 0xFF >> V_61 ) ) ;
V_20 -> V_115 = V_117 ;
return V_20 ;
}
if ( V_61 == 0 )
break;
V_61 -- ;
}
V_61 = 7 ;
for (; ; ) {
if ( ( V_104 = F_61 ( V_1 , V_61 + 32 ) ) != NULL ) {
F_27 ( V_20 -> V_114 , V_23 , L_12 ,
V_104 -> V_22 , V_1 [ 4 ] & ( 0xFF >> V_61 ) , V_1 [ 5 ] ) ;
V_20 -> V_115 = V_117 ;
return V_20 ;
}
if ( V_61 == 0 )
break;
V_61 -- ;
}
V_61 = 7 ;
for (; ; ) {
if ( ( V_104 = F_61 ( V_1 , V_61 + 24 ) ) != NULL ) {
F_27 ( V_20 -> V_114 , V_23 , L_13 ,
V_104 -> V_22 , V_1 [ 3 ] & ( 0xFF >> V_61 ) , V_1 [ 4 ] , V_1 [ 5 ] ) ;
V_20 -> V_115 = V_117 ;
return V_20 ;
}
if ( V_61 == 0 )
break;
V_61 -- ;
}
if ( ( V_103 = F_60 ( V_1 ) ) != NULL ) {
F_27 ( V_20 -> V_114 , V_23 , L_13 ,
V_103 -> V_22 , V_1 [ 3 ] , V_1 [ 4 ] , V_1 [ 5 ] ) ;
V_20 -> V_115 = V_117 ;
return V_20 ;
}
V_61 = 7 ;
for (; ; ) {
if ( ( V_104 = F_61 ( V_1 , V_61 + 16 ) ) != NULL ) {
F_27 ( V_20 -> V_114 , V_23 , L_14 ,
V_104 -> V_22 , V_1 [ 2 ] & ( 0xFF >> V_61 ) , V_1 [ 3 ] , V_1 [ 4 ] ,
V_1 [ 5 ] ) ;
V_20 -> V_115 = V_117 ;
return V_20 ;
}
if ( V_61 == 0 )
break;
V_61 -- ;
}
V_61 = 7 ;
for (; ; ) {
if ( ( V_104 = F_61 ( V_1 , V_61 + 8 ) ) != NULL ) {
F_27 ( V_20 -> V_114 , V_23 , L_15 ,
V_104 -> V_22 , V_1 [ 1 ] & ( 0xFF >> V_61 ) , V_1 [ 2 ] , V_1 [ 3 ] ,
V_1 [ 4 ] , V_1 [ 5 ] ) ;
V_20 -> V_115 = V_117 ;
return V_20 ;
}
if ( V_61 == 0 )
break;
V_61 -- ;
}
for ( V_61 = 7 ; V_61 > 0 ; V_61 -- ) {
if ( ( V_104 = F_61 ( V_1 , V_61 ) ) != NULL ) {
F_27 ( V_20 -> V_114 , V_23 , L_16 ,
V_104 -> V_22 , V_1 [ 0 ] & ( 0xFF >> V_61 ) , V_1 [ 1 ] , V_1 [ 2 ] ,
V_1 [ 3 ] , V_1 [ 4 ] , V_1 [ 5 ] ) ;
V_20 -> V_115 = V_117 ;
return V_20 ;
}
}
F_27 ( V_20 -> V_114 , V_23 , L_10 , F_66 ( V_1 ) ) ;
V_20 -> V_115 = V_117 ;
return V_20 ;
}
F_67 () ;
}
static T_19 *
F_68 ( const V_67 * V_1 , const T_12 V_69 ) {
T_19 * V_20 ;
V_20 = ( T_19 * ) F_2 ( sizeof( T_19 ) ) ;
memcpy ( V_20 -> V_1 , V_1 , sizeof( V_20 -> V_1 ) ) ;
V_20 -> V_115 = V_118 ;
F_10 ( V_20 -> V_119 , F_69 ( V_1 , sizeof( V_20 -> V_1 ) , ':' ) , sizeof( V_20 -> V_119 ) ) ;
V_20 -> V_114 [ 0 ] = '\0' ;
V_20 -> V_21 = NULL ;
if ( V_69 )
F_65 ( V_20 ) ;
return V_20 ;
}
static T_19 *
F_57 ( const V_67 * V_1 , const T_6 * V_22 )
{
T_18 V_19 ;
T_19 * V_20 ;
V_19 = F_70 ( V_1 ) ;
V_20 = V_120 [ V_19 ] ;
if( V_20 == NULL ) {
V_20 = V_120 [ V_19 ] = F_68 ( V_1 , FALSE ) ;
} else {
while( TRUE ) {
if ( memcmp ( V_20 -> V_1 , V_1 , sizeof( V_20 -> V_1 ) ) == 0 ) {
if ( V_20 -> V_115 == V_116 )
return V_20 ;
break;
}
if ( V_20 -> V_21 == NULL ) {
V_20 = V_20 -> V_21 = F_68 ( V_1 , FALSE ) ;
break;
}
V_20 = V_20 -> V_21 ;
}
}
F_10 ( V_20 -> V_114 , V_22 , V_23 ) ;
V_20 -> V_115 = V_116 ;
V_24 = TRUE ;
return V_20 ;
}
static T_19 *
F_71 ( const V_67 * V_1 , const T_12 V_69 ) {
T_18 V_19 ;
T_19 * V_20 ;
V_19 = F_70 ( V_1 ) ;
V_20 = V_120 [ V_19 ] ;
if( V_20 == NULL ) {
V_20 = V_120 [ V_19 ] = F_68 ( V_1 , V_69 ) ;
return V_20 ;
} else {
while( TRUE ) {
if ( memcmp ( V_20 -> V_1 , V_1 , sizeof( V_20 -> V_1 ) ) == 0 ) {
if ( V_69 && ( V_20 -> V_115 == V_118 ) )
F_65 ( V_20 ) ;
return V_20 ;
}
if ( V_20 -> V_21 == NULL ) {
V_20 -> V_21 = F_68 ( V_1 , V_69 ) ;
return V_20 -> V_21 ;
}
V_20 = V_20 -> V_21 ;
}
}
}
static V_67 *
F_72 ( const T_6 * V_22 )
{
T_15 * V_94 ;
T_19 * V_20 ;
T_19 * * V_47 = V_120 ;
T_18 V_66 ;
for ( V_66 = 0 ; V_66 < V_102 ; V_66 ++ ) {
V_20 = V_47 [ V_66 ] ;
while ( V_20 ) {
if ( strcmp ( V_20 -> V_114 , V_22 ) == 0 )
return V_20 -> V_1 ;
V_20 = V_20 -> V_21 ;
}
}
if ( ( V_94 = F_50 ( V_22 ) ) == NULL )
return NULL ;
V_20 = F_57 ( V_94 -> V_1 , V_22 ) ;
return V_20 -> V_1 ;
}
static int
F_73 ( char * line , T_20 * V_121 )
{
T_6 * V_25 ;
T_1 V_122 , V_123 , V_124 , V_125 , V_126 ;
T_12 V_127 = FALSE ;
if ( ( V_25 = strchr ( line , '#' ) ) )
* V_25 = '\0' ;
if ( ( V_25 = strtok ( line , L_17 ) ) == NULL )
return - 1 ;
if ( sscanf ( V_25 , L_18 , & V_123 , & V_124 , & V_125 , & V_126 ) != 4 ) {
if ( sscanf ( V_25 , L_19 , & V_123 , & V_124 , & V_125 , & V_126 ) != 4 ) {
if ( sscanf ( V_25 , L_20 , & V_123 , & V_124 , & V_125 , & V_126 ) != 4 ) {
if ( sscanf ( V_25 , L_21 , & V_122 ) == 1 ) {
V_127 = TRUE ;
}
else {
return - 1 ;
}
}
}
}
if ( ( V_25 = strtok ( NULL , L_17 ) ) == NULL )
return - 1 ;
if ( V_127 ) {
V_121 -> V_1 = V_122 ;
}
else {
V_121 -> V_1 = ( V_123 << 24 ) | ( V_124 << 16 ) | ( V_125 << 8 ) | V_126 ;
}
F_10 ( V_121 -> V_22 , V_25 , V_23 ) ;
return 0 ;
}
static void
F_74 ( char * V_41 )
{
if ( V_128 )
rewind ( V_128 ) ;
else
V_128 = F_16 ( V_41 , L_7 ) ;
}
static void
F_75 ( void )
{
if ( V_128 ) {
fclose ( V_128 ) ;
V_128 = NULL ;
}
}
static T_20 *
F_76 ( void )
{
static T_20 V_121 ;
static int V_10 = 0 ;
static char * V_9 = NULL ;
if ( V_128 == NULL )
return NULL ;
while ( F_5 ( & V_9 , & V_10 , V_128 ) >= 0 ) {
if ( F_73 ( V_9 , & V_121 ) == 0 ) {
return & V_121 ;
}
}
return NULL ;
}
static T_20 *
F_77 ( const T_6 * V_22 )
{
T_20 * V_121 ;
F_74 ( V_129 ) ;
while ( ( ( V_121 = F_76 () ) != NULL ) && strncmp ( V_22 , V_121 -> V_22 , V_23 ) != 0 )
;
if ( V_121 == NULL ) {
F_75 () ;
F_74 ( V_130 ) ;
while ( ( ( V_121 = F_76 () ) != NULL ) && strncmp ( V_22 , V_121 -> V_22 , V_23 ) != 0 )
;
F_75 () ;
}
return V_121 ;
}
static T_20 *
F_78 ( T_1 V_1 )
{
T_20 * V_121 ;
F_74 ( V_129 ) ;
while ( ( ( V_121 = F_76 () ) != NULL ) && ( V_1 != V_121 -> V_1 ) ) ;
if ( V_121 == NULL ) {
F_75 () ;
F_74 ( V_130 ) ;
while ( ( ( V_121 = F_76 () ) != NULL ) && ( V_1 != V_121 -> V_1 ) )
;
F_75 () ;
}
return V_121 ;
}
static void
F_79 ( void )
{
if ( V_129 == NULL ) {
V_129 = F_63 ( L_10 V_111 L_10 ,
F_64 () , V_131 ) ;
}
if ( V_130 == NULL )
V_130 = F_18 ( V_131 , FALSE , FALSE ) ;
}
static T_21 *
F_80 ( T_5 V_1 , const T_6 * V_22 )
{
int V_19 ;
T_21 * V_20 ;
V_19 = F_81 ( V_1 ) ;
V_20 = V_132 [ V_19 ] ;
if( V_20 == NULL ) {
V_20 = V_132 [ V_19 ] = ( T_21 * ) F_2 ( sizeof( T_21 ) ) ;
} else {
while( 1 ) {
if ( V_20 -> V_21 == NULL ) {
V_20 -> V_21 = ( T_21 * ) F_2 ( sizeof( T_21 ) ) ;
V_20 = V_20 -> V_21 ;
break;
}
V_20 = V_20 -> V_21 ;
}
}
V_20 -> V_1 = V_1 ;
F_10 ( V_20 -> V_22 , V_22 , V_23 ) ;
V_20 -> V_21 = NULL ;
V_24 = TRUE ;
return V_20 ;
}
static T_6 *
F_82 ( const T_5 V_1 )
{
int V_19 ;
T_21 * V_20 ;
T_20 * V_121 ;
V_19 = F_81 ( V_1 ) ;
V_20 = V_132 [ V_19 ] ;
if( V_20 == NULL ) {
V_20 = V_132 [ V_19 ] = ( T_21 * ) F_2 ( sizeof( T_21 ) ) ;
} else {
while( 1 ) {
if ( V_20 -> V_1 == V_1 ) {
return V_20 -> V_22 ;
}
if ( V_20 -> V_21 == NULL ) {
V_20 -> V_21 = ( T_21 * ) F_2 ( sizeof( T_21 ) ) ;
V_20 = V_20 -> V_21 ;
break;
}
V_20 = V_20 -> V_21 ;
}
}
V_20 -> V_1 = V_1 ;
V_20 -> V_21 = NULL ;
if ( ( V_121 = F_78 ( V_1 ) ) == NULL ) {
F_27 ( V_20 -> V_22 , V_23 , L_22 , V_1 ) ;
} else {
F_10 ( V_20 -> V_22 , V_121 -> V_22 , V_23 ) ;
}
return ( V_20 -> V_22 ) ;
}
static T_5
F_83 ( const T_6 * V_22 , T_12 * V_133 )
{
T_20 * V_121 ;
T_21 * V_20 ;
T_21 * * V_47 = V_132 ;
int V_66 ;
for ( V_66 = 0 ; V_66 < V_134 ; V_66 ++ ) {
V_20 = V_47 [ V_66 ] ;
while ( V_20 ) {
if ( strcmp ( V_20 -> V_22 , V_22 ) == 0 ) {
* V_133 = TRUE ;
return V_20 -> V_1 ;
}
V_20 = V_20 -> V_21 ;
}
}
if ( ( V_121 = F_77 ( V_22 ) ) == NULL ) {
* V_133 = FALSE ;
return 0 ;
}
V_20 = F_80 ( V_121 -> V_1 , V_22 ) ;
* V_133 = TRUE ;
return V_20 -> V_1 ;
}
T_12
F_84 ( const char * V_135 )
{
T_3 * V_136 ;
char * line = NULL ;
int V_10 = 0 ;
T_6 * V_25 ;
T_1 V_62 [ 4 ] ;
struct V_82 V_91 ;
T_12 V_137 ;
int V_138 ;
if ( ( V_136 = F_16 ( V_135 , L_7 ) ) == NULL )
return FALSE ;
while ( F_5 ( & line , & V_10 , V_136 ) >= 0 ) {
if ( ( V_25 = strchr ( line , '#' ) ) )
* V_25 = '\0' ;
if ( ( V_25 = strtok ( line , L_1 ) ) == NULL )
continue;
V_138 = F_85 ( V_86 , V_25 , & V_62 ) ;
if ( V_138 == - 1 )
continue;
if ( V_138 == 1 ) {
V_137 = TRUE ;
} else {
if ( F_85 ( V_79 , V_25 , & V_62 ) != 1 )
continue;
V_137 = FALSE ;
}
if ( ( V_25 = strtok ( NULL , L_1 ) ) == NULL )
continue;
if ( V_137 ) {
memcpy ( & V_91 , V_62 , sizeof V_91 ) ;
F_86 ( & V_91 , V_25 ) ;
} else
F_87 ( V_62 [ 0 ] , V_25 ) ;
while ( ( V_25 = strtok ( NULL , L_1 ) ) != NULL ) {
if ( V_137 ) {
memcpy ( & V_91 , V_62 , sizeof V_91 ) ;
F_86 ( & V_91 , V_25 ) ;
} else
F_87 ( V_62 [ 0 ] , V_25 ) ;
}
}
F_14 ( line ) ;
fclose ( V_136 ) ;
return TRUE ;
}
T_12
F_88 ( const char * V_1 , const char * V_22 )
{
T_1 V_62 [ 4 ] ;
struct V_82 V_91 ;
T_12 V_137 ;
int V_138 ;
V_138 = F_85 ( V_86 , V_1 , & V_91 ) ;
if ( V_138 == - 1 )
return FALSE ;
if ( V_138 == 1 ) {
V_137 = TRUE ;
} else {
if ( F_85 ( V_79 , V_1 , & V_62 ) != 1 )
return FALSE ;
V_137 = FALSE ;
}
if ( V_137 ) {
F_86 ( & V_91 , V_22 ) ;
} else {
F_87 ( V_62 [ 0 ] , V_22 ) ;
}
return TRUE ;
}
struct V_139 *
F_89 ( void ) {
return V_140 ;
}
static T_12
F_90 ( const char * V_141 )
{
T_3 * V_136 ;
char * line = NULL ;
int V_10 = 0 ;
T_6 * V_25 , * V_142 ;
T_1 V_62 ;
int V_68 ;
if ( ( V_136 = F_16 ( V_141 , L_7 ) ) == NULL )
return FALSE ;
while ( F_5 ( & line , & V_10 , V_136 ) >= 0 ) {
if ( ( V_25 = strchr ( line , '#' ) ) )
* V_25 = '\0' ;
if ( ( V_25 = strtok ( line , L_1 ) ) == NULL )
continue;
V_142 = strchr ( V_25 , '/' ) ;
if( NULL == V_142 ) {
continue;
}
* V_142 = '\0' ;
++ V_142 ;
if ( F_85 ( V_79 , V_25 , & V_62 ) != 1 ) {
continue;
}
V_68 = atoi ( V_142 ) ;
if( 0 >= V_68 || V_68 > 31 ) {
continue;
}
if ( ( V_25 = strtok ( NULL , L_1 ) ) == NULL )
continue;
F_91 ( V_62 , ( T_1 ) V_68 , V_25 ) ;
}
F_14 ( line ) ;
fclose ( V_136 ) ;
return TRUE ;
}
static T_10
F_25 ( const T_1 V_1 )
{
T_10 V_59 ;
T_1 V_66 ;
V_66 = V_143 ;
while( V_144 && V_66 > 0 ) {
T_1 V_109 ;
T_22 * V_145 ;
-- V_66 ;
F_6 ( V_66 < V_143 ) ;
V_145 = & V_146 [ V_66 ] ;
if( NULL != V_145 -> V_147 ) {
T_9 * V_20 ;
T_1 V_19 ;
V_109 = V_1 & V_145 -> V_61 ;
V_19 = F_30 ( V_109 ) ;
V_20 = V_145 -> V_147 [ V_19 ] ;
while( V_20 != NULL && V_20 -> V_1 != V_109 ) {
V_20 = V_20 -> V_21 ;
}
if( NULL != V_20 ) {
V_59 . V_61 = V_145 -> V_61 ;
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
F_91 ( T_1 V_148 , const T_1 V_68 , const T_6 * V_22 )
{
T_22 * V_149 ;
T_9 * V_20 ;
T_11 V_19 ;
F_6 ( V_68 > 0 && V_68 <= 32 ) ;
V_149 = & V_146 [ V_68 - 1 ] ;
V_148 &= V_149 -> V_61 ;
V_19 = F_30 ( V_148 ) ;
if( NULL == V_149 -> V_147 ) {
V_149 -> V_147 = F_92 ( T_9 * , V_150 ) ;
}
if( NULL != ( V_20 = V_149 -> V_147 [ V_19 ] ) ) {
if( V_20 -> V_1 == V_148 ) {
return;
} else {
T_9 * V_151 = F_93 ( T_9 , 1 ) ;
V_20 -> V_21 = V_151 ;
V_20 = V_151 ;
}
} else {
V_20 = V_149 -> V_147 [ V_19 ] = F_93 ( T_9 , 1 ) ;
}
V_20 -> V_21 = NULL ;
V_20 -> V_1 = V_148 ;
V_20 -> V_60 = FALSE ;
F_10 ( V_20 -> V_22 , V_22 , V_23 ) ;
V_144 = TRUE ;
}
static T_1
F_94 ( const T_1 V_68 ) {
static T_1 V_152 [ V_143 ] ;
static T_12 V_153 = FALSE ;
if( ! V_153 ) {
memset ( V_152 , 0 , sizeof( V_152 ) ) ;
V_153 = TRUE ;
F_85 ( V_79 , L_23 , & V_152 [ 0 ] ) ;
F_85 ( V_79 , L_24 , & V_152 [ 1 ] ) ;
F_85 ( V_79 , L_25 , & V_152 [ 2 ] ) ;
F_85 ( V_79 , L_26 , & V_152 [ 3 ] ) ;
F_85 ( V_79 , L_27 , & V_152 [ 4 ] ) ;
F_85 ( V_79 , L_28 , & V_152 [ 5 ] ) ;
F_85 ( V_79 , L_29 , & V_152 [ 6 ] ) ;
F_85 ( V_79 , L_30 , & V_152 [ 7 ] ) ;
F_85 ( V_79 , L_31 , & V_152 [ 8 ] ) ;
F_85 ( V_79 , L_32 , & V_152 [ 9 ] ) ;
F_85 ( V_79 , L_33 , & V_152 [ 10 ] ) ;
F_85 ( V_79 , L_34 , & V_152 [ 11 ] ) ;
F_85 ( V_79 , L_35 , & V_152 [ 12 ] ) ;
F_85 ( V_79 , L_36 , & V_152 [ 13 ] ) ;
F_85 ( V_79 , L_37 , & V_152 [ 14 ] ) ;
F_85 ( V_79 , L_38 , & V_152 [ 15 ] ) ;
F_85 ( V_79 , L_39 , & V_152 [ 16 ] ) ;
F_85 ( V_79 , L_40 , & V_152 [ 17 ] ) ;
F_85 ( V_79 , L_41 , & V_152 [ 18 ] ) ;
F_85 ( V_79 , L_42 , & V_152 [ 19 ] ) ;
F_85 ( V_79 , L_43 , & V_152 [ 20 ] ) ;
F_85 ( V_79 , L_44 , & V_152 [ 21 ] ) ;
F_85 ( V_79 , L_45 , & V_152 [ 22 ] ) ;
F_85 ( V_79 , L_46 , & V_152 [ 23 ] ) ;
F_85 ( V_79 , L_47 , & V_152 [ 24 ] ) ;
F_85 ( V_79 , L_48 , & V_152 [ 25 ] ) ;
F_85 ( V_79 , L_49 , & V_152 [ 26 ] ) ;
F_85 ( V_79 , L_50 , & V_152 [ 27 ] ) ;
F_85 ( V_79 , L_51 , & V_152 [ 28 ] ) ;
F_85 ( V_79 , L_52 , & V_152 [ 29 ] ) ;
F_85 ( V_79 , L_53 , & V_152 [ 30 ] ) ;
F_85 ( V_79 , L_54 , & V_152 [ 31 ] ) ;
}
if( V_68 == 0 || V_68 > V_143 ) {
F_67 () ;
return 0 ;
} else {
return V_152 [ V_68 - 1 ] ;
}
}
static void
F_95 ( void )
{
T_6 * V_141 ;
T_1 V_66 ;
for( V_66 = 0 ; V_66 < V_143 ; ++ V_66 ) {
T_1 V_154 = V_66 + 1 ;
V_146 [ V_66 ] . V_147 = NULL ;
V_146 [ V_66 ] . V_68 = V_154 ;
V_146 [ V_66 ] . V_61 = F_94 ( V_154 ) ;
}
V_141 = F_18 ( V_155 , FALSE , FALSE ) ;
if ( ! F_90 ( V_141 ) && V_156 != V_157 ) {
F_96 ( V_141 , V_156 , FALSE ) ;
}
F_14 ( V_141 ) ;
V_141 = F_19 ( V_155 ) ;
if ( ! F_90 ( V_141 ) && V_156 != V_157 ) {
F_96 ( V_141 , V_156 , FALSE ) ;
}
F_14 ( V_141 ) ;
}
void
F_97 ( void ) {
char * V_135 ;
struct V_139 * V_158 ;
#ifdef F_98
#ifdef F_99
char * V_159 ;
static char V_160 [] = L_55 ;
static char V_161 [] = L_56 ;
#endif
#endif
if ( ! V_140 ) {
V_158 = F_59 ( sizeof( struct V_139 ) ) ;
V_140 = V_162 = V_158 ;
}
V_135 = F_18 ( V_163 , FALSE , FALSE ) ;
if ( ! F_84 ( V_135 ) && V_156 != V_157 ) {
F_96 ( V_135 , V_156 , FALSE ) ;
}
F_14 ( V_135 ) ;
V_135 = F_19 ( V_163 ) ;
if ( ! F_84 ( V_135 ) && V_156 != V_157 ) {
F_96 ( V_135 , V_156 , FALSE ) ;
}
F_14 ( V_135 ) ;
#ifdef F_3
#ifdef F_100
if ( F_101 ( V_164 ) == V_165 ) {
#endif
if ( F_102 ( & V_166 ) == V_165 && F_102 ( & V_167 ) == V_165 ) {
V_78 = TRUE ;
}
#ifdef F_100
}
#endif
#else
#ifdef F_98
#ifdef F_99
V_159 = F_103 ( L_57 ) ;
if ( V_159 != NULL ) {
V_135 = F_104 ( V_159 , V_160 , NULL ) ;
if ( ! F_84 ( V_135 ) ) {
F_14 ( V_135 ) ;
V_135 = F_104 ( V_159 , V_161 , NULL ) ;
F_84 ( V_135 ) ;
}
F_14 ( V_135 ) ;
}
#else
F_84 ( L_58 ) ;
#endif
if ( F_105 ( & V_168 , 0 , 0 ) != 0 ) {
return;
}
V_78 = TRUE ;
V_169 = 0 ;
#endif
#endif
F_95 () ;
}
T_12
F_106 ( V_8 V_88 V_170 ) {
T_2 * V_84 ;
struct V_171 V_172 = { 0 , 0 } ;
int V_173 ;
T_23 V_174 , V_175 ;
T_12 V_176 = V_24 ;
V_24 = FALSE ;
if ( ! V_78 )
return V_176 ;
V_7 = F_107 ( V_7 ) ;
while ( V_7 != NULL && V_169 <= V_76 . V_77 ) {
V_84 = ( T_2 * ) V_7 -> V_88 ;
V_7 = F_108 ( V_7 , ( void * ) V_84 ) ;
if ( V_84 -> V_3 == V_79 ) {
F_109 ( V_166 , & V_84 -> V_1 . V_4 , sizeof( T_1 ) , V_79 ,
V_177 , V_84 ) ;
V_169 ++ ;
} else if ( V_84 -> V_3 == V_86 ) {
F_109 ( V_166 , & V_84 -> V_1 . V_83 , sizeof( struct V_82 ) ,
V_86 , V_177 , V_84 ) ;
V_169 ++ ;
}
}
F_110 ( & V_174 ) ;
F_110 ( & V_175 ) ;
V_173 = F_111 ( V_166 , & V_174 , & V_175 ) ;
if ( V_173 > 0 ) {
F_112 ( V_173 , & V_174 , & V_175 , NULL , & V_172 ) ;
F_113 ( V_166 , & V_174 , & V_175 ) ;
}
return V_176 ;
}
void
F_114 ( void ) {
T_24 * V_178 ;
V_178 = F_107 ( V_7 ) ;
while ( V_178 ) {
F_14 ( V_178 -> V_88 ) ;
V_178 = F_115 ( V_178 ) ;
}
F_116 ( V_7 ) ;
if ( V_78 ) {
F_117 ( V_166 ) ;
F_117 ( V_167 ) ;
}
#ifdef F_100
F_118 () ;
#endif
V_78 = FALSE ;
}
T_12
F_106 ( V_8 V_88 V_170 ) {
T_2 * V_179 ;
T_24 * V_178 ;
char V_180 [] = L_59 ;
V_67 * V_181 ;
T_25 * V_182 ;
int V_138 ;
T_12 V_183 ;
T_12 V_176 = V_24 ;
V_24 = FALSE ;
V_7 = F_107 ( V_7 ) ;
V_178 = V_7 ;
while ( V_178 && V_169 <= V_76 . V_77 ) {
V_179 = ( T_2 * ) V_178 -> V_88 ;
if ( ! V_179 -> V_6 && V_179 -> type == V_79 ) {
V_181 = ( V_67 * ) & V_179 -> V_5 ;
F_27 ( V_180 , sizeof V_180 , L_60 , V_181 [ 3 ] ,
V_181 [ 2 ] , V_181 [ 1 ] , V_181 [ 0 ] ) ;
F_119 ( V_168 , V_180 , V_184 , 0 , NULL , & V_179 -> V_185 ) ;
V_179 -> V_6 = TRUE ;
V_169 ++ ;
}
V_178 = V_178 -> V_21 ;
}
V_178 = V_7 ;
while ( V_178 ) {
V_183 = FALSE ;
V_179 = ( T_2 * ) V_178 -> V_88 ;
if ( V_179 -> V_6 ) {
V_138 = F_120 ( V_168 , & V_179 -> V_185 , & V_182 , NULL ) ;
if ( V_138 == 0 ) {
if ( V_182 -> V_115 == V_186 ) {
F_87 ( V_179 -> V_5 , * V_182 -> V_187 . V_188 ) ;
}
V_183 = TRUE ;
}
}
V_178 = V_178 -> V_21 ;
if ( V_183 ) {
V_7 = F_108 ( V_7 , ( void * ) V_179 ) ;
F_14 ( V_179 ) ;
V_169 -- ;
}
}
return V_176 ;
}
void
F_114 ( void ) {
void * V_189 ;
V_7 = F_107 ( V_7 ) ;
while ( V_7 ) {
V_189 = V_7 -> V_88 ;
V_7 = F_108 ( V_7 , V_189 ) ;
F_14 ( V_189 ) ;
}
if ( V_78 )
F_121 ( V_168 ) ;
V_78 = FALSE ;
}
T_12
F_106 ( V_8 V_88 V_170 ) {
T_12 V_176 = V_24 ;
V_24 = FALSE ;
return V_176 ;
}
void
F_114 ( void ) {
}
const T_6 *
F_41 ( const T_5 V_1 )
{
T_12 V_71 ;
T_12 V_69 = V_56 & V_80 ;
T_9 * V_20 = F_29 ( V_1 , V_69 , & V_71 ) ;
if ( ! V_69 )
return V_20 -> V_70 ;
return V_20 -> V_22 ;
}
const T_6 *
F_42 ( const struct V_82 * V_1 )
{
T_12 V_71 ;
T_12 V_69 = V_56 & V_80 ;
T_13 * V_20 = F_36 ( V_1 , V_69 , & V_71 ) ;
if ( ! V_69 )
return V_20 -> V_83 ;
return V_20 -> V_22 ;
}
void
F_87 ( const T_5 V_1 , const T_6 * V_22 )
{
int V_19 ;
T_9 * V_20 ;
struct V_139 * V_158 ;
struct V_190 * V_191 ;
V_19 = F_30 ( V_1 ) ;
V_20 = V_74 [ V_19 ] ;
if( V_20 == NULL ) {
V_20 = V_74 [ V_19 ] = F_28 ( V_1 ) ;
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
V_20 -> V_21 = F_28 ( V_1 ) ;
V_20 = V_20 -> V_21 ;
break;
}
V_20 = V_20 -> V_21 ;
}
}
F_10 ( V_20 -> V_22 , V_22 , V_23 ) ;
V_20 -> V_69 = TRUE ;
V_24 = TRUE ;
if ( ! V_140 ) {
V_158 = F_59 ( sizeof( struct V_139 ) ) ;
V_140 = V_162 = V_158 ;
}
V_191 = F_59 ( sizeof( struct V_190 ) ) ;
V_191 -> V_192 = V_79 ;
V_191 -> V_193 . V_194 = V_1 ;
V_158 = F_59 ( sizeof( struct V_139 ) ) ;
V_158 -> V_195 = V_79 ;
V_158 -> V_196 = sizeof( struct V_190 ) ;
V_158 -> V_197 = ( char * ) V_20 -> V_22 ;
V_158 -> V_198 = (struct V_199 * ) V_191 ;
V_162 -> V_200 = V_158 ;
V_162 = V_158 ;
}
void
F_86 ( const struct V_82 * V_201 , const T_6 * V_22 )
{
int V_19 ;
T_13 * V_20 ;
struct V_139 * V_158 ;
struct V_202 * V_203 ;
V_19 = F_38 ( * V_201 ) ;
V_20 = V_85 [ V_19 ] ;
if( V_20 == NULL ) {
V_20 = V_85 [ V_19 ] = F_34 ( V_201 ) ;
} else {
while( 1 ) {
if ( memcmp ( & V_20 -> V_1 , V_201 , sizeof ( struct V_82 ) ) == 0 ) {
if ( ! V_20 -> V_60 ) {
return;
} else {
break;
}
}
if ( V_20 -> V_21 == NULL ) {
V_20 -> V_21 = F_34 ( V_201 ) ;
V_20 = V_20 -> V_21 ;
break;
}
V_20 = V_20 -> V_21 ;
}
}
F_10 ( V_20 -> V_22 , V_22 , V_23 ) ;
V_20 -> V_69 = TRUE ;
V_24 = TRUE ;
if ( ! V_140 ) {
V_158 = F_59 ( sizeof( struct V_139 ) ) ;
V_140 = V_162 = V_158 ;
}
V_203 = F_59 ( sizeof( struct V_202 ) ) ;
V_203 -> V_204 = V_79 ;
memcpy ( V_203 -> V_205 . V_206 , V_201 , 16 ) ;
V_158 = F_59 ( sizeof( struct V_139 ) ) ;
V_158 -> V_195 = V_86 ;
V_158 -> V_196 = sizeof( struct V_190 ) ;
V_158 -> V_197 = ( char * ) V_20 -> V_22 ;
V_158 -> V_198 = (struct V_199 * ) V_203 ;
V_162 -> V_200 = V_158 ;
V_162 = V_158 ;
}
static T_6 *
F_122 ( T_5 V_17 )
{
T_6 * V_207 = F_123 ( V_23 ) ;
F_23 ( V_17 , V_207 , V_23 ) ;
return V_207 ;
}
T_6 *
F_124 ( T_5 V_17 )
{
if ( ! ( V_56 & V_57 ) ) {
return F_122 ( V_17 ) ;
}
return F_20 ( V_17 , V_52 ) ;
}
T_6 *
F_125 ( T_5 V_17 )
{
if ( ! ( V_56 & V_57 ) ) {
return F_122 ( V_17 ) ;
}
return F_20 ( V_17 , V_55 ) ;
}
T_6 *
F_126 ( T_5 V_17 )
{
if ( ! ( V_56 & V_57 ) ) {
return F_122 ( V_17 ) ;
}
return F_20 ( V_17 , V_53 ) ;
}
T_6 *
F_127 ( T_5 V_17 )
{
if ( ! ( V_56 & V_57 ) ) {
return F_122 ( V_17 ) ;
}
return F_20 ( V_17 , V_54 ) ;
}
const T_6 *
F_128 ( const T_14 * V_1 )
{
const T_6 * V_208 ;
V_208 = F_39 ( V_1 ) ;
if ( V_208 != NULL )
return V_208 ;
if ( V_1 -> type == V_209 ) {
return L_61 ;
}
return F_129 ( V_1 ) ;
}
const T_6 *
F_130 ( const T_14 * V_1 )
{
const T_6 * V_208 ;
V_208 = F_43 ( V_1 ) ;
if ( V_208 != NULL )
return V_208 ;
if ( V_1 -> type == V_209 ) {
return L_61 ;
}
return F_131 ( V_1 ) ;
}
void
F_132 ( const T_14 * V_1 , T_6 * V_9 , T_11 V_10 )
{
const T_6 * V_208 = F_128 ( V_1 ) ;
F_10 ( V_9 , V_208 , V_10 ) ;
}
T_6 *
F_40 ( const V_67 * V_1 )
{
T_19 * V_20 ;
T_12 V_69 = ( V_56 & V_210 ) != 0 ;
if ( V_69 && ! V_211 ) {
F_62 () ;
V_211 = TRUE ;
}
V_20 = F_71 ( V_1 , V_69 ) ;
return V_69 ? V_20 -> V_114 : V_20 -> V_119 ;
}
T_6 *
F_133 ( const V_67 * V_1 )
{
T_19 * V_20 ;
if ( ! ( V_56 & V_210 ) )
return NULL ;
if ( ! V_211 ) {
F_62 () ;
V_211 = TRUE ;
}
V_20 = F_71 ( V_1 , TRUE ) ;
F_6 ( V_20 != NULL ) ;
if ( V_20 -> V_115 == V_116 ) {
return V_20 -> V_114 ;
}
else {
return NULL ;
}
}
V_67 *
F_134 ( const T_6 * V_22 )
{
if ( ! V_211 ) {
F_62 () ;
V_211 = TRUE ;
}
return F_72 ( V_22 ) ;
}
void
F_135 ( const T_5 V_70 , const V_67 * V_94 )
{
T_6 * V_212 ;
T_12 V_71 ;
if ( ! ( V_56 & V_80 ) )
return;
if ( ( V_212 = F_33 ( V_70 , & V_71 ) ) == NULL )
return;
if ( V_71 )
F_57 ( V_94 , V_212 ) ;
}
const T_6 *
F_136 ( const T_1 V_1 )
{
if ( ! ( V_56 & V_80 ) ) {
return F_137 ( V_1 , '\0' ) ;
}
if ( ! V_213 ) {
F_79 () ;
V_213 = 1 ;
}
return F_82 ( V_1 ) ;
}
T_1
F_138 ( const T_6 * V_22 , T_12 * V_214 )
{
T_1 V_1 ;
T_12 V_133 ;
if ( ! V_213 ) {
F_79 () ;
V_213 = 1 ;
}
V_1 = F_83 ( V_22 , & V_133 ) ;
* V_214 = V_133 ;
return V_1 ;
}
const T_6 *
F_139 ( const V_67 * V_1 )
{
T_6 * V_178 ;
T_16 * V_103 ;
if ( ( V_56 & V_210 ) && ! V_211 ) {
F_62 () ;
V_211 = TRUE ;
}
if ( ! ( V_56 & V_210 ) || ( ( V_103 = F_60 ( V_1 ) ) == NULL ) ) {
V_178 = F_140 ( L_62 , V_1 [ 0 ] , V_1 [ 1 ] , V_1 [ 2 ] ) ;
return V_178 ;
}
return V_103 -> V_22 ;
}
const T_6 *
F_141 ( const T_5 V_215 )
{
V_67 V_1 [ 3 ] ;
V_1 [ 0 ] = ( V_215 >> 16 ) & 0xFF ;
V_1 [ 1 ] = ( V_215 >> 8 ) & 0xFF ;
V_1 [ 2 ] = ( V_215 >> 0 ) & 0xFF ;
return F_139 ( V_1 ) ;
}
const T_6 *
F_142 ( T_26 * V_216 , T_18 V_217 )
{
return F_139 ( F_143 ( V_216 , V_217 , 3 ) ) ;
}
const T_6 *
F_144 ( const V_67 * V_1 )
{
T_16 * V_103 ;
if ( ! V_211 ) {
F_62 () ;
V_211 = TRUE ;
}
if ( ( V_103 = F_60 ( V_1 ) ) == NULL ) {
return NULL ;
}
return V_103 -> V_22 ;
}
const T_6 *
F_145 ( const T_5 V_215 )
{
V_67 V_1 [ 3 ] ;
V_1 [ 0 ] = ( V_215 >> 16 ) & 0xFF ;
V_1 [ 1 ] = ( V_215 >> 8 ) & 0xFF ;
V_1 [ 2 ] = ( V_215 >> 0 ) & 0xFF ;
return F_144 ( V_1 ) ;
}
const T_6 *
F_146 ( T_26 * V_216 , T_18 V_217 )
{
return F_144 ( F_143 ( V_216 , V_217 , 3 ) ) ;
}
const T_6 *
F_147 ( const T_27 V_218 )
{
T_6 * V_178 ;
T_16 * V_103 ;
V_67 * V_1 = F_123 ( 8 ) ;
* ( T_27 * ) ( void * ) ( V_1 ) = F_148 ( & ( V_218 ) ) ;
if ( ( V_56 & V_210 ) && ! V_211 ) {
F_62 () ;
V_211 = TRUE ;
}
if ( ! ( V_56 & V_210 ) || ( ( V_103 = F_60 ( V_1 ) ) == NULL ) ) {
V_178 = F_140 ( L_63 , V_1 [ 0 ] , V_1 [ 1 ] , V_1 [ 2 ] , V_1 [ 3 ] , V_1 [ 4 ] , V_1 [ 5 ] , V_1 [ 6 ] , V_1 [ 7 ] ) ;
return V_178 ;
}
V_178 = F_140 ( L_15 , V_103 -> V_22 , V_1 [ 3 ] , V_1 [ 4 ] , V_1 [ 5 ] , V_1 [ 6 ] , V_1 [ 7 ] ) ;
return V_178 ;
}
const T_6 *
F_149 ( const T_27 V_218 )
{
T_6 * V_178 ;
T_16 * V_103 ;
V_67 * V_1 = F_123 ( 8 ) ;
* ( T_27 * ) ( void * ) ( V_1 ) = F_148 ( & ( V_218 ) ) ;
if ( ! V_211 ) {
F_62 () ;
V_211 = TRUE ;
}
if ( ( V_103 = F_60 ( V_1 ) ) == NULL ) {
return NULL ;
}
V_178 = F_140 ( L_15 , V_103 -> V_22 , V_1 [ 3 ] , V_1 [ 4 ] , V_1 [ 5 ] , V_1 [ 6 ] , V_1 [ 7 ] ) ;
return V_178 ;
}
T_12
F_150 ( const char * V_212 , T_1 * V_201 )
{
struct V_219 V_220 ;
#ifdef F_3
struct V_171 V_172 = { 0 , V_221 } , * V_222 ;
int V_173 ;
T_23 V_174 , V_175 ;
T_28 V_223 ;
#else
struct V_72 * V_224 ;
#endif
if ( ! F_151 ( V_212 , & V_220 ) ) {
if ( ! ( V_56 & V_80 ) ) {
return FALSE ;
}
#ifdef F_3
if ( ! ( V_56 & V_75 ) ||
V_76 . V_77 < 1 ||
! V_78 ) {
return FALSE ;
}
V_223 . V_225 = ( int ) sizeof ( struct V_219 ) ;
V_223 . V_226 = 0 ;
V_223 . V_201 = V_201 ;
F_152 ( V_167 , V_212 , V_79 , V_227 , & V_223 ) ;
F_110 ( & V_174 ) ;
F_110 ( & V_175 ) ;
V_173 = F_111 ( V_167 , & V_174 , & V_175 ) ;
if ( V_173 > 0 ) {
V_222 = F_153 ( V_167 , & V_172 , & V_172 ) ;
F_112 ( V_173 , & V_174 , & V_175 , NULL , V_222 ) ;
F_113 ( V_167 , & V_174 , & V_175 ) ;
}
F_154 ( V_167 ) ;
if ( V_223 . V_225 == V_223 . V_226 ) {
return TRUE ;
}
return FALSE ;
#else
V_224 = F_155 ( V_212 ) ;
if ( V_224 == NULL ) {
return FALSE ;
} else if ( V_224 -> V_228 <= ( int ) sizeof ( struct V_219 ) ) {
memcpy ( & V_220 , V_224 -> V_229 , V_224 -> V_228 ) ;
} else {
return FALSE ;
}
#endif
} else {
unsigned int V_123 , V_124 , V_125 , V_126 ;
if ( sscanf ( V_212 , L_64 , & V_123 , & V_124 , & V_125 , & V_126 ) != 4 )
return FALSE ;
}
* V_201 = V_220 . V_194 ;
return TRUE ;
}
T_12
F_156 ( const char * V_212 , struct V_82 * V_201 )
{
#ifdef F_3
struct V_171 V_172 = { 0 , V_221 } , * V_222 ;
int V_173 ;
T_23 V_174 , V_175 ;
T_28 V_223 ;
#elif F_157 ( V_230 )
struct V_72 * V_224 ;
#endif
if ( F_85 ( V_86 , V_212 , V_201 ) == 1 )
return TRUE ;
if ( ! ( V_56 & V_80 ) ) {
return FALSE ;
}
#ifdef F_3
if ( ! ( V_56 & V_75 ) ||
V_76 . V_77 < 1 ||
! V_78 ) {
return FALSE ;
}
V_223 . V_225 = ( int ) sizeof ( struct V_82 ) ;
V_223 . V_226 = 0 ;
V_223 . V_201 = V_201 ;
F_152 ( V_167 , V_212 , V_86 , V_227 , & V_223 ) ;
F_110 ( & V_174 ) ;
F_110 ( & V_175 ) ;
V_173 = F_111 ( V_167 , & V_174 , & V_175 ) ;
if ( V_173 > 0 ) {
V_222 = F_153 ( V_167 , & V_172 , & V_172 ) ;
F_112 ( V_173 , & V_174 , & V_175 , NULL , V_222 ) ;
F_113 ( V_167 , & V_174 , & V_175 ) ;
}
F_154 ( V_167 ) ;
if ( V_223 . V_225 == V_223 . V_226 ) {
return TRUE ;
}
#elif F_157 ( V_230 )
V_224 = F_158 ( V_212 , V_86 ) ;
if ( V_224 != NULL && V_224 -> V_228 == sizeof( struct V_82 ) ) {
memcpy ( V_201 , V_224 -> V_229 , V_224 -> V_228 ) ;
return TRUE ;
}
#endif
return FALSE ;
}
const char * F_159 ( const char * V_212
#ifndef V_230
V_170
#endif
)
{
#ifdef V_230
struct V_72 * V_231 ;
return ( V_231 = F_158 ( V_212 , V_86 ) ) && V_231 -> V_232 == V_86 ? L_65 : L_66 ;
#else
return L_66 ;
#endif
}
