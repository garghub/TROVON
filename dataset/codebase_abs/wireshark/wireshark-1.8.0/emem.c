static void
F_1 ( T_1 * V_1 )
{
int V_2 ;
static T_2 * V_3 = NULL ;
if ( V_3 == NULL ) {
V_3 = F_2 () ;
}
for ( V_2 = 0 ; V_2 < V_4 ; V_2 ++ ) {
V_1 [ V_2 ] = ( T_1 ) F_3 ( V_3 , 1 , 0x100 ) ;
}
return;
}
static void *
F_4 ( T_1 * V_5 , T_1 * V_1 , int * V_6 )
{
void * V_7 ;
int V_2 ;
for ( V_2 = 0 ; V_2 < V_8 - 1 ; V_2 ++ )
if ( V_5 [ V_2 ] != V_1 [ V_2 ] )
return ( void * ) - 1 ;
for (; V_2 < V_4 ; V_2 ++ ) {
if ( V_1 [ V_2 ] == '\0' ) {
memcpy ( & V_7 , & V_1 [ V_2 + 1 ] , sizeof( void * ) ) ;
if ( V_6 )
* V_6 = V_2 + 1 + sizeof( void * ) ;
return V_7 ;
}
if ( V_5 [ V_2 ] != V_1 [ V_2 ] )
return ( void * ) - 1 ;
}
return ( void * ) - 1 ;
}
static T_1
F_5 ( T_3 V_9 )
{
T_1 V_10 ;
V_10 = V_8 - ( V_9 % V_8 ) ;
if ( V_10 < V_8 )
V_10 += V_8 ;
return V_10 ;
}
void
F_6 ( const char * V_11 , ... )
{
T_4 V_12 ;
static T_5 V_13 [ 128 ] = {
'L' , 'a' , 'u' , 'n' , 'c' , 'h' , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 ,
0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 ,
0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 ,
0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 } ;
T_5 V_14 [ 128 ] ;
T_6 * V_15 = NULL ;
if ( ! V_16 ) return;
va_start ( V_12 , V_11 ) ;
F_7 ( V_14 , sizeof( V_14 ) , V_11 , V_12 ) ;
va_end ( V_12 ) ;
for ( V_15 = V_17 . V_18 ; V_15 != NULL ; V_15 = V_15 -> V_19 ) {
void * V_20 = V_15 -> V_21 ;
while ( V_20 != NULL ) {
V_20 = F_4 ( V_17 . V_1 , V_20 , NULL ) ;
if ( V_20 == ( void * ) - 1 )
F_8 ( L_1 , V_13 , V_14 ) ;
}
}
F_9 ( V_13 , V_14 , sizeof( V_13 ) ) ;
}
static void
F_10 ( T_7 * V_22 )
{
if ( V_22 -> V_23 )
F_1 ( V_22 -> V_1 ) ;
if ( V_22 -> V_24 )
V_22 -> V_25 = V_26 ;
else
V_22 -> V_25 = V_27 ;
}
static void
F_11 ( void )
{
V_17 . V_18 = NULL ;
V_17 . V_28 = NULL ;
V_17 . V_29 = NULL ;
V_17 . V_24 = ( getenv ( L_2 ) == NULL ) ;
V_17 . V_23 = V_17 . V_24 && ( getenv ( L_3 ) == NULL ) ;
V_17 . V_30 = ( getenv ( L_4 ) != NULL ) ;
#ifdef F_12
V_16 = ( getenv ( L_5 ) != NULL ) ;
#endif
F_10 ( & V_17 ) ;
}
static void
F_13 ( void )
{
V_31 . V_18 = NULL ;
V_31 . V_28 = NULL ;
V_31 . V_29 = NULL ;
V_31 . V_24 = ( getenv ( L_6 ) == NULL ) ;
V_31 . V_23 = V_31 . V_24 && ( getenv ( L_7 ) != NULL ) ;
V_31 . V_30 = ( getenv ( L_8 ) != NULL ) ;
F_10 ( & V_31 ) ;
}
void
F_14 ( void )
{
F_11 () ;
F_13 () ;
if ( getenv ( L_9 ) )
V_32 = TRUE ;
#if F_15 ( V_33 )
F_16 ( & V_34 ) ;
V_35 = V_34 . V_36 ;
V_37 . V_38 = sizeof( V_39 ) ;
F_17 ( & V_37 ) ;
#elif F_15 ( V_40 )
V_35 = F_18 ( V_41 ) ;
#ifdef F_19
V_42 = F_20 ( L_10 , V_43 ) ;
F_21 ( V_42 != - 1 ) ;
#endif
#endif
}
static void
F_22 ()
{
T_8 V_44 = 0 ;
T_8 V_45 = 0 ;
T_8 V_46 = 0 ;
T_8 V_47 = 0 ;
T_8 V_48 = 0 ;
T_8 V_49 = 0 ;
T_8 V_50 ;
T_8 V_2 ;
T_6 * V_51 ;
T_8 V_52 , V_53 ;
T_9 V_54 = TRUE ;
fprintf ( V_55 , L_11 ) ;
fprintf ( V_55 , L_12 ,
V_17 . V_24 ? L_13 : L_14 ,
V_17 . V_23 ? L_15 : L_16 ,
V_32 ? L_15 : L_16 ) ;
if ( ! ( V_17 . V_18 || ! V_17 . V_28 ) ) {
fprintf ( V_55 , L_17 ) ;
V_54 = FALSE ;
}
if ( V_17 . V_24 && V_54 ) {
for ( V_51 = V_17 . V_28 ; V_51 ; V_51 = V_51 -> V_19 ) {
V_44 ++ ;
V_46 += ( V_51 -> V_56 - V_51 -> V_57 ) ;
V_47 += V_51 -> V_56 ;
V_48 += V_51 -> V_57 ;
}
if ( V_44 > 0 ) {
fprintf ( V_55 , L_18 ) ;
fprintf ( V_55 , L_19 ) ;
fprintf ( V_55 , L_20 , V_58 ) ;
fprintf ( V_55 , L_21 , V_44 ) ;
fprintf ( V_55 , L_22 ) ;
fprintf ( V_55 , L_23 ,
V_47 , V_58 * V_44 ) ;
fprintf ( V_55 , L_22 ) ;
V_52 = V_47
+ sizeof( T_6 ) * V_44 ;
fprintf ( V_55 , L_24 ,
V_52 ) ;
} else{
fprintf ( V_55 , L_25 ) ;
}
V_44 = 0 ;
V_45 = 0 ;
V_46 = 0 ;
V_47 = 0 ;
V_48 = 0 ;
V_49 = 0 ;
}
fprintf ( V_55 , L_26 ) ;
fprintf ( V_55 , L_27 ,
V_59 ) ;
fprintf ( V_55 , L_28 ,
V_31 . V_24 ? L_13 : L_14 ,
V_31 . V_23 ? L_15 : L_16 ) ;
if ( ! ( V_31 . V_18 || ! V_31 . V_28 ) ) {
fprintf ( V_55 , L_17 ) ;
return;
}
if ( ! V_31 . V_24 )
return;
for ( V_51 = V_31 . V_28 ; V_51 ; V_51 = V_51 -> V_19 ) {
V_44 ++ ;
V_46 += ( V_51 -> V_56 - V_51 -> V_57 ) ;
V_47 += V_51 -> V_56 ;
V_48 += V_51 -> V_57 ;
if ( V_31 . V_23 ) {
void * V_7 = V_51 -> V_21 ;
int V_6 ;
while ( V_7 != NULL ) {
V_7 = F_4 ( V_31 . V_1 , V_7 , & V_6 ) ;
if ( V_7 == ( void * ) - 1 )
F_8 ( L_29 ) ;
V_49 += V_6 ;
}
}
}
if ( V_44 == 0 ) {
fprintf ( V_55 , L_25 ) ;
return;
}
fprintf ( V_55 , L_18 ) ;
fprintf ( V_55 , L_30 ) ;
fprintf ( V_55 , L_31 ) ;
fprintf ( V_55 , L_32 ,
sizeof( T_6 ) ) ;
fprintf ( V_55 , L_33 , V_44 ) ;
fprintf ( V_55 , L_22 ) ;
V_50 = sizeof( T_6 ) * V_44 ;
fprintf ( V_55 , L_34 , V_50 ) ;
fprintf ( V_55 , L_19 ) ;
fprintf ( V_55 , L_20 ,
V_58 ) ;
fprintf ( V_55 , L_21 , V_44 ) ;
fprintf ( V_55 , L_22 ) ;
fprintf ( V_55 , L_35 ,
V_47 , V_58 * V_44 ) ;
fprintf ( V_55 , L_22 ) ;
V_52 = ( V_58 * V_44 )
+ V_50 ;
fprintf ( V_55 , L_36 ,
V_52 ) ;
for ( V_2 = 0 ; V_2 < V_60 ; V_2 ++ )
V_45 += V_61 [ V_2 ] ;
fprintf ( V_55 , L_37 ) ;
fprintf ( V_55 , L_38 ,
V_45 ) ;
fprintf ( V_55 , L_39 ,
V_46 ) ;
fprintf ( V_55 , L_40 ,
V_49 ) ;
fprintf ( V_55 , L_41 ,
V_47 - V_46 ) ;
fprintf ( V_55 , L_42 ,
V_52 - V_46 ) ;
fprintf ( V_55 , L_43 ) ;
fprintf ( V_55 , L_44 ,
( float ) V_46 / ( float ) V_45 ) ;
fprintf ( V_55 , L_45 ,
( float ) ( V_46 - V_49 ) / ( float ) V_45 ) ;
fprintf ( V_55 , L_46 ,
( V_47 - V_46 ) / ( float ) V_45 ) ;
V_53 = ( V_47 - V_46 )
+ ( sizeof( T_6 ) ) ;
fprintf ( V_55 , L_47 ,
V_53 ) ;
fprintf ( V_55 , L_48 ,
100 * ( float ) V_53 / ( float ) V_52 ) ;
fprintf ( V_55 , L_49 ) ;
for ( V_2 = 0 ; V_2 < ( V_60 - 1 ) ; V_2 ++ )
fprintf ( V_55 , L_50 , 32 << V_2 , V_61 [ V_2 ] ) ;
fprintf ( V_55 , L_51 , 32 << V_2 , V_61 [ V_2 ] ) ;
}
static T_9
F_23 ( const T_6 * V_62 , const void * V_7 )
{
const T_5 * V_63 = V_7 ;
const T_6 * V_51 ;
for ( V_51 = V_62 ; V_51 ; V_51 = V_51 -> V_19 ) {
if ( V_63 >= ( V_51 -> V_64 + V_51 -> V_65 ) && V_63 < ( V_51 -> V_64 + V_51 -> V_66 ) )
return TRUE ;
}
return FALSE ;
}
static T_9
F_24 ( const T_7 * V_67 , const void * V_7 )
{
return F_23 ( V_67 -> V_18 , V_7 ) || F_23 ( V_67 -> V_28 , V_7 ) ;
}
T_9
F_25 ( const void * V_7 )
{
if ( V_17 . V_30 )
return F_24 ( & V_17 , V_7 ) ;
else
return FALSE ;
}
T_9
F_26 ( const void * V_7 )
{
if ( V_31 . V_30 )
return F_24 ( & V_31 , V_7 ) ;
else
return FALSE ;
}
static void
F_27 ( char * V_64 , T_3 V_68 , T_9 V_69 )
{
T_8 V_70 ;
T_8 V_71 ;
if ( ! V_32 )
return;
if ( V_69 )
V_70 = 0xBADDCAFE ;
else
V_70 = 0xDEADBEEF ;
for ( V_71 = 0 ; V_71 + sizeof( T_8 ) <= V_68 ; V_71 += sizeof( T_8 ) )
* ( T_8 * ) ( void * ) ( V_64 + V_71 ) = V_70 ;
if ( V_71 < V_68 ) {
* ( T_1 * ) ( V_64 + V_71 ) = V_70 >> 24 ;
V_71 ++ ;
if ( V_71 < V_68 ) {
* ( T_1 * ) ( V_64 + V_71 ) = ( V_70 >> 16 ) & 0xFF ;
V_71 ++ ;
if ( V_71 < V_68 ) {
* ( T_1 * ) ( V_64 + V_71 ) = ( V_70 >> 8 ) & 0xFF ;
}
}
}
}
static T_6 *
F_28 ( T_3 V_68 )
{
T_6 * V_15 ;
V_15 = F_29 ( T_6 , 1 ) ;
V_15 -> V_19 = NULL ;
V_15 -> V_21 = NULL ;
#if F_15 ( V_33 )
V_15 -> V_64 = F_30 ( NULL , V_68 ,
V_72 | V_73 , V_74 ) ;
if ( V_15 -> V_64 == NULL ) {
F_31 ( V_15 ) ;
if ( getenv ( L_52 ) )
abort () ;
else
F_32 ( V_75 ) ;
}
#elif F_15 ( V_40 )
V_15 -> V_64 = F_33 ( NULL , V_68 ,
V_76 | V_77 , V_78 , V_79 , 0 ) ;
if ( V_15 -> V_64 == V_80 ) {
F_31 ( V_15 ) ;
if ( getenv ( L_52 ) )
abort () ;
else
F_32 ( V_75 ) ;
}
#else
V_15 -> V_64 = F_34 ( V_68 ) ;
#endif
#ifdef F_35
V_59 ++ ;
#endif
V_15 -> V_57 = V_15 -> V_56 = ( unsigned int ) V_68 ;
V_15 -> V_66 = V_15 -> V_65 = 0 ;
return V_15 ;
}
static void
F_36 ( T_6 * V_15 )
{
#if F_15 ( V_33 )
F_37 ( V_15 -> V_64 , 0 , V_81 ) ;
#elif F_15 ( V_40 )
F_38 ( V_15 -> V_64 , V_15 -> V_56 ) ;
#else
F_31 ( V_15 -> V_64 ) ;
#endif
#ifdef F_35
V_59 -- ;
#endif
F_31 ( V_15 ) ;
}
static T_6 *
F_39 ( T_3 V_68 )
{
#if F_15 ( V_33 )
BOOL V_82 ;
char * V_83 , * V_84 , * V_85 ;
T_10 V_86 ;
#elif F_15 ( V_40 )
int V_82 ;
char * V_83 , * V_84 , * V_85 ;
#endif
T_6 * V_15 ;
V_15 = F_28 ( V_68 ) ;
#if F_15 ( V_33 )
V_83 = V_15 -> V_64 + V_68 ;
V_84 = ( char * ) ( ( ( ( int ) V_15 -> V_64 + V_35 - 1 ) / V_35 ) * V_35 ) ;
V_85 = ( char * ) ( ( ( ( int ) V_83 - ( 1 * V_35 ) ) / V_35 ) * V_35 ) ;
V_82 = F_40 ( V_84 , V_35 , V_87 , & V_86 ) ;
F_21 ( V_82 != 0 || V_37 . V_88 == V_89 ) ;
V_82 = F_40 ( V_85 , V_35 , V_87 , & V_86 ) ;
F_21 ( V_82 != 0 || V_37 . V_88 == V_89 ) ;
V_15 -> V_56 = ( unsigned int ) ( V_85 - V_84 - V_35 ) ;
V_15 -> V_65 = ( unsigned int ) ( V_84 - V_15 -> V_64 ) + V_35 ;
#elif F_15 ( V_40 )
V_83 = V_15 -> V_64 + V_68 ;
V_84 = ( char * ) ( ( ( ( V_90 ) V_15 -> V_64 + V_35 - 1 ) / V_35 ) * V_35 ) ;
V_85 = ( char * ) ( ( ( ( V_90 ) V_83 - ( 1 * V_35 ) ) / V_35 ) * V_35 ) ;
V_82 = F_41 ( V_84 , V_35 , V_91 ) ;
F_21 ( V_82 != - 1 ) ;
V_82 = F_41 ( V_85 , V_35 , V_91 ) ;
F_21 ( V_82 != - 1 ) ;
V_15 -> V_56 = V_85 - V_84 - V_35 ;
V_15 -> V_65 = ( V_84 - V_15 -> V_64 ) + V_35 ;
#else
V_15 -> V_56 = V_68 ;
V_15 -> V_65 = 0 ;
#endif
V_15 -> V_57 = V_15 -> V_56 ;
V_15 -> V_66 = V_15 -> V_65 ;
return V_15 ;
}
static void *
V_26 ( T_3 V_68 , T_7 * V_22 )
{
void * V_64 ;
T_3 V_92 = V_68 ;
T_9 V_93 = V_22 -> V_23 ;
T_1 V_10 ;
T_6 * V_18 ;
if ( V_93 ) {
V_92 += sizeof( void * ) ;
V_10 = F_5 ( V_92 ) ;
} else
V_10 = ( V_94 - ( V_92 & ( V_94 - 1 ) ) ) & ( V_94 - 1 ) ;
V_92 += V_10 ;
#ifdef F_35
if ( V_22 == & V_31 ) {
if ( V_92 < 32 )
V_61 [ 0 ] ++ ;
else if ( V_92 < 64 )
V_61 [ 1 ] ++ ;
else if ( V_92 < 128 )
V_61 [ 2 ] ++ ;
else if ( V_92 < 256 )
V_61 [ 3 ] ++ ;
else if ( V_92 < 512 )
V_61 [ 4 ] ++ ;
else if ( V_92 < 1024 )
V_61 [ 5 ] ++ ;
else if ( V_92 < 2048 )
V_61 [ 6 ] ++ ;
else if ( V_92 < 4096 )
V_61 [ 7 ] ++ ;
else if ( V_92 < 8192 )
V_61 [ 8 ] ++ ;
else if ( V_92 < 16384 )
V_61 [ 8 ] ++ ;
else
V_61 [ ( V_60 - 1 ) ] ++ ;
}
#endif
F_42 ( V_68 < ( V_58 >> 2 ) ) ;
if ( ! V_22 -> V_18 )
V_22 -> V_18 = F_39 ( V_58 ) ;
if( V_92 > V_22 -> V_18 -> V_57 ) {
T_6 * V_15 ;
V_15 = V_22 -> V_18 ;
V_22 -> V_18 = V_22 -> V_18 -> V_19 ;
V_15 -> V_19 = V_22 -> V_28 ;
V_22 -> V_28 = V_15 ;
if ( ! V_22 -> V_18 )
V_22 -> V_18 = F_39 ( V_58 ) ;
}
V_18 = V_22 -> V_18 ;
V_64 = V_18 -> V_64 + V_18 -> V_66 ;
V_18 -> V_57 -= ( unsigned int ) V_92 ;
V_18 -> V_66 += ( unsigned int ) V_92 ;
if ( V_93 ) {
char * V_63 = ( char * ) V_64 + V_68 ;
memcpy ( V_63 , V_22 -> V_1 , V_10 - 1 ) ;
V_63 [ V_10 - 1 ] = '\0' ;
memcpy ( V_63 + V_10 , & V_18 -> V_21 , sizeof( void * ) ) ;
V_18 -> V_21 = V_63 ;
}
return V_64 ;
}
static void *
V_27 ( T_3 V_68 , T_7 * V_22 )
{
T_6 * V_15 ;
V_15 = F_29 ( T_6 , 1 ) ;
V_15 -> V_19 = V_22 -> V_28 ;
V_15 -> V_64 = F_34 ( V_68 ) ;
V_15 -> V_21 = NULL ;
V_22 -> V_28 = V_15 ;
V_15 -> V_66 = V_15 -> V_65 = 0 ;
V_15 -> V_57 = V_15 -> V_56 = ( unsigned int ) V_68 ;
return V_15 -> V_64 ;
}
static void *
F_43 ( T_3 V_68 , T_7 * V_22 )
{
void * V_64 = V_22 -> V_25 ( V_68 , V_22 ) ;
F_27 ( V_64 , V_68 , TRUE ) ;
return V_64 ;
}
void *
F_44 ( T_3 V_68 )
{
return F_43 ( V_68 , & V_17 ) ;
}
void *
F_45 ( T_3 V_68 )
{
return F_43 ( V_68 , & V_31 ) ;
}
void *
F_46 ( struct V_95 * V_96 )
{
T_6 * V_51 ;
void * V_7 ;
if ( ( V_96 -> V_97 != NULL ) ) {
V_7 = V_96 -> V_97 ;
memcpy ( & V_96 -> V_97 , V_7 , sizeof( void * ) ) ;
return V_7 ;
}
if ( ! ( V_51 = V_96 -> V_62 ) || V_51 -> V_57 < ( T_8 ) V_96 -> V_98 ) {
T_3 V_99 = V_96 -> V_98 * V_96 -> V_100 ;
#if F_15 ( V_33 ) || F_15 ( V_40 )
V_99 = ( V_99 + ( V_35 - 1 ) ) & ~ ( V_35 - 1 ) ;
#endif
V_51 = F_28 ( V_99 ) ;
V_51 -> V_19 = V_96 -> V_62 ;
V_96 -> V_62 = V_51 ;
}
V_7 = V_51 -> V_64 + V_51 -> V_66 ;
V_51 -> V_66 += V_96 -> V_98 ;
V_51 -> V_57 -= V_96 -> V_98 ;
return V_7 ;
}
void
F_47 ( struct V_95 * V_96 , T_11 V_7 )
{
if ( V_7 != NULL ) {
memcpy ( V_7 , & ( V_96 -> V_97 ) , sizeof( void * ) ) ;
V_96 -> V_97 = V_7 ;
}
}
void *
F_48 ( T_3 V_68 )
{
return memset ( F_44 ( V_68 ) , '\0' , V_68 ) ;
}
void *
F_49 ( T_3 V_68 )
{
return memset ( F_45 ( V_68 ) , '\0' , V_68 ) ;
}
void *
F_50 ( struct V_95 * V_96 )
{
return memset ( F_46 ( V_96 ) , '\0' , V_96 -> V_98 ) ;
}
static T_5 *
F_51 ( const T_5 * V_101 , void * F_52 ( T_3 ) )
{
T_8 V_6 ;
T_5 * V_102 ;
if( ! V_101 )
return L_53 ;
V_6 = ( T_8 ) strlen ( V_101 ) ;
V_102 = memcpy ( F_52 ( V_6 + 1 ) , V_101 , V_6 + 1 ) ;
return V_102 ;
}
T_5 *
F_53 ( const T_5 * V_101 )
{
return F_51 ( V_101 , F_44 ) ;
}
T_5 *
F_54 ( const T_5 * V_101 )
{
return F_51 ( V_101 , F_45 ) ;
}
static T_5 *
F_55 ( const T_5 * V_101 , T_3 V_6 , void * F_52 ( T_3 ) )
{
T_5 * V_102 = F_52 ( V_6 + 1 ) ;
T_8 V_2 ;
for ( V_2 = 0 ; ( V_2 < V_6 ) && V_101 [ V_2 ] ; V_2 ++ )
V_102 [ V_2 ] = V_101 [ V_2 ] ;
V_102 [ V_2 ] = '\0' ;
return V_102 ;
}
T_5 *
F_56 ( const T_5 * V_101 , T_3 V_6 )
{
return F_55 ( V_101 , V_6 , F_44 ) ;
}
T_5 *
F_57 ( const T_5 * V_101 , T_3 V_6 )
{
return F_55 ( V_101 , V_6 , F_45 ) ;
}
void *
F_58 ( const void * V_101 , T_3 V_6 )
{
return memcpy ( F_44 ( V_6 ) , V_101 , V_6 ) ;
}
void *
F_59 ( const void * V_101 , T_3 V_6 )
{
return memcpy ( F_45 ( V_6 ) , V_101 , V_6 ) ;
}
static T_5 *
F_60 ( const T_5 * V_11 , T_4 V_12 , void * F_52 ( T_3 ) )
{
T_4 V_103 ;
T_12 V_6 ;
T_5 * V_102 ;
F_61 ( V_103 , V_12 ) ;
V_6 = F_62 ( V_11 , V_12 ) ;
V_102 = F_52 ( V_6 + 1 ) ;
F_7 ( V_102 , ( V_104 ) V_6 , V_11 , V_103 ) ;
va_end ( V_103 ) ;
return V_102 ;
}
T_5 *
F_63 ( const T_5 * V_11 , T_4 V_12 )
{
return F_60 ( V_11 , V_12 , F_44 ) ;
}
T_5 *
F_64 ( const T_5 * V_11 , T_4 V_12 )
{
return F_60 ( V_11 , V_12 , F_45 ) ;
}
T_5 *
F_65 ( const T_5 * V_11 , ... )
{
T_4 V_12 ;
T_5 * V_102 ;
va_start ( V_12 , V_11 ) ;
V_102 = F_63 ( V_11 , V_12 ) ;
va_end ( V_12 ) ;
return V_102 ;
}
T_5 *
F_66 ( const T_5 * V_11 , ... )
{
T_4 V_12 ;
T_5 * V_102 ;
va_start ( V_12 , V_11 ) ;
V_102 = F_64 ( V_11 , V_12 ) ;
va_end ( V_12 ) ;
return V_102 ;
}
T_5 * *
F_67 ( const T_5 * string , const T_5 * V_105 , int V_106 )
{
T_5 * V_107 ;
T_5 * V_108 ;
T_8 V_109 ;
T_8 V_110 ;
T_8 V_111 ;
T_8 V_2 ;
T_5 * * V_112 ;
enum { V_113 , V_114 , V_115 } V_116 ;
T_8 V_117 = 0 ;
if ( ! string
|| ! V_105
|| ! V_105 [ 0 ] )
return NULL ;
V_108 = V_107 = F_53 ( string ) ;
V_110 = ( T_8 ) strlen ( V_107 ) ;
V_111 = ( T_8 ) strlen ( V_105 ) ;
if ( V_106 < 1 ) V_106 = V_118 ;
V_109 = 1 ;
while ( V_109 <= ( T_8 ) V_106 && ( V_108 = strstr ( V_108 , V_105 ) ) ) {
V_109 ++ ;
for( V_2 = 0 ; V_2 < V_111 ; V_2 ++ )
V_108 [ V_2 ] = '\0' ;
V_108 += V_111 ;
}
V_112 = F_68 ( T_5 * , V_109 + 1 ) ;
V_116 = V_113 ;
for ( V_2 = 0 ; V_2 < V_110 ; V_2 ++ ) {
switch( V_116 ) {
case V_113 :
switch( V_107 [ V_2 ] ) {
case '\0' :
V_116 = V_114 ;
continue;
default:
V_112 [ V_117 ] = & ( V_107 [ V_2 ] ) ;
V_117 ++ ;
V_116 = V_115 ;
continue;
}
case V_115 :
switch( V_107 [ V_2 ] ) {
case '\0' :
V_116 = V_114 ;
default:
continue;
}
case V_114 :
switch( V_107 [ V_2 ] ) {
default:
V_112 [ V_117 ] = & ( V_107 [ V_2 ] ) ;
V_117 ++ ;
V_116 = V_115 ;
case '\0' :
continue;
}
}
}
V_112 [ V_117 ] = NULL ;
return V_112 ;
}
T_5 *
F_69 ( const T_5 * V_119 , ... )
{
T_12 V_120 ;
T_4 args ;
T_5 * V_108 ;
T_5 * V_121 ;
T_5 * V_7 ;
if ( ! V_119 )
return NULL ;
V_120 = 1 + strlen ( V_119 ) ;
va_start ( args , V_119 ) ;
V_108 = va_arg ( args , T_5 * ) ;
while ( V_108 ) {
V_120 += strlen ( V_108 ) ;
V_108 = va_arg ( args , T_5 * ) ;
}
va_end ( args ) ;
V_121 = F_44 ( V_120 ) ;
V_7 = V_121 ;
V_7 = F_70 ( V_7 , V_119 ) ;
va_start ( args , V_119 ) ;
V_108 = va_arg ( args , T_5 * ) ;
while ( V_108 ) {
V_7 = F_70 ( V_7 , V_108 ) ;
V_108 = va_arg ( args , T_5 * ) ;
}
va_end ( args ) ;
return V_121 ;
}
static void
F_71 ( T_7 * V_22 )
{
T_9 V_122 = V_22 -> V_24 ;
T_6 * V_15 ;
T_13 * V_123 ;
while( V_22 -> V_28 ) {
V_15 = V_22 -> V_28 ;
V_22 -> V_28 = V_22 -> V_28 -> V_19 ;
V_15 -> V_19 = V_22 -> V_18 ;
V_22 -> V_18 = V_15 ;
}
V_15 = V_22 -> V_18 ;
while ( V_15 != NULL ) {
if ( V_122 ) {
while ( V_15 -> V_21 != NULL ) {
V_15 -> V_21 = F_4 ( V_22 -> V_1 , V_15 -> V_21 , NULL ) ;
if ( V_15 -> V_21 == ( void * ) - 1 )
F_8 ( L_29 ) ;
}
F_27 ( ( V_15 -> V_64 + V_15 -> V_65 ) ,
( V_15 -> V_66 - V_15 -> V_65 ) ,
FALSE ) ;
V_15 -> V_57 = V_15 -> V_56 ;
V_15 -> V_66 = V_15 -> V_65 ;
V_15 = V_15 -> V_19 ;
} else {
T_6 * V_19 = V_15 -> V_19 ;
F_27 ( V_15 -> V_64 , V_15 -> V_56 , FALSE ) ;
F_31 ( V_15 -> V_64 ) ;
F_31 ( V_15 ) ;
V_15 = V_19 ;
}
}
if ( ! V_122 ) {
V_22 -> V_18 = NULL ;
}
for( V_123 = V_22 -> V_29 ; V_123 ; V_123 = V_123 -> V_19 ) {
V_123 -> V_124 = NULL ;
}
}
void
F_72 ( void )
{
F_71 ( & V_17 ) ;
}
void
F_73 ( void )
{
#ifdef F_35
F_22 () ;
#endif
F_71 ( & V_31 ) ;
}
void
F_74 ( struct V_95 * V_96 )
{
T_6 * V_62 = V_96 -> V_62 ;
V_96 -> V_62 = NULL ;
V_96 -> V_97 = NULL ;
while ( V_62 ) {
T_6 * V_51 = V_62 ;
V_62 = V_62 -> V_19 ;
F_36 ( V_51 ) ;
}
}
T_14
F_75 ( void ) {
T_14 V_108 = F_76 ( struct V_125 * ) ;
* V_108 = F_77 ( struct V_125 ) ;
return V_108 ;
}
void *
F_78 ( T_14 V_126 , void * V_127 )
{
struct V_125 * V_128 ;
struct V_125 * V_129 = ( * V_126 ) ;
if ( V_129 -> V_130 ) {
V_128 = V_129 -> V_130 ;
} else {
V_128 = F_76 ( struct V_125 ) ;
V_129 -> V_130 = V_128 ;
V_128 -> V_131 = V_129 ;
V_128 -> V_130 = NULL ;
}
V_128 -> V_132 = V_127 ;
( * V_126 ) = V_128 ;
return V_127 ;
}
void *
F_79 ( T_14 V_126 )
{
if ( ( * V_126 ) -> V_131 ) {
( * V_126 ) = ( * V_126 ) -> V_131 ;
return ( * V_126 ) -> V_130 -> V_132 ;
} else {
return NULL ;
}
}
T_13 *
F_80 ( int type , const char * V_133 )
{
T_13 * V_123 ;
V_123 = F_34 ( sizeof( T_13 ) ) ;
V_123 -> V_19 = V_31 . V_29 ;
V_123 -> type = type ;
V_123 -> V_124 = NULL ;
V_123 -> V_133 = V_133 ;
V_123 -> malloc = F_45 ;
V_31 . V_29 = V_123 ;
return V_123 ;
}
void *
F_81 ( T_13 * V_134 , T_15 V_135 )
{
T_16 * V_136 ;
V_136 = V_134 -> V_124 ;
while( V_136 ) {
if( V_135 == V_136 -> V_137 ) {
return V_136 -> V_127 ;
}
if( V_135 < V_136 -> V_137 ) {
V_136 = V_136 -> V_138 ;
continue;
}
if( V_135 > V_136 -> V_137 ) {
V_136 = V_136 -> V_139 ;
continue;
}
}
return NULL ;
}
void *
F_82 ( T_13 * V_134 , T_15 V_135 )
{
T_16 * V_136 ;
V_136 = V_134 -> V_124 ;
if( ! V_136 ) {
return NULL ;
}
while( V_136 ) {
if( V_135 == V_136 -> V_137 ) {
return V_136 -> V_127 ;
}
if( V_135 < V_136 -> V_137 ) {
if( V_136 -> V_138 ) {
V_136 = V_136 -> V_138 ;
continue;
} else {
break;
}
}
if( V_135 > V_136 -> V_137 ) {
if( V_136 -> V_139 ) {
V_136 = V_136 -> V_139 ;
continue;
} else {
break;
}
}
}
if( ! V_136 ) {
return NULL ;
}
if( ! V_136 -> V_140 ) {
if( V_135 > V_136 -> V_137 ) {
return V_136 -> V_127 ;
} else {
return NULL ;
}
}
if( V_136 -> V_140 -> V_138 == V_136 ) {
if( V_135 > V_136 -> V_137 ) {
return V_136 -> V_127 ;
} else {
while( V_136 ) {
if( V_135 > V_136 -> V_137 ) {
return V_136 -> V_127 ;
}
V_136 = V_136 -> V_140 ;
}
return NULL ;
}
} else {
if( V_136 -> V_137 < V_135 ) {
return V_136 -> V_127 ;
} else {
return V_136 -> V_140 -> V_127 ;
}
}
}
static inline T_16 *
F_83 ( T_16 * V_136 )
{
return V_136 -> V_140 ;
}
static inline T_16 *
F_84 ( T_16 * V_136 )
{
T_16 * V_140 ;
V_140 = F_83 ( V_136 ) ;
if( V_140 ) {
return V_140 -> V_140 ;
}
return NULL ;
}
static inline T_16 *
F_85 ( T_16 * V_136 )
{
T_16 * V_140 , * V_141 ;
V_140 = F_83 ( V_136 ) ;
if( ! V_140 ) {
return NULL ;
}
V_141 = F_83 ( V_140 ) ;
if( ! V_141 ) {
return NULL ;
}
if( V_140 == V_141 -> V_138 ) {
return V_141 -> V_139 ;
}
return V_141 -> V_138 ;
}
static inline void
F_86 ( T_13 * V_134 , T_16 * V_136 )
{
if( V_136 -> V_140 ) {
if( V_136 -> V_140 -> V_138 == V_136 ) {
V_136 -> V_140 -> V_138 = V_136 -> V_139 ;
} else {
V_136 -> V_140 -> V_139 = V_136 -> V_139 ;
}
} else {
V_134 -> V_124 = V_136 -> V_139 ;
}
V_136 -> V_139 -> V_140 = V_136 -> V_140 ;
V_136 -> V_140 = V_136 -> V_139 ;
V_136 -> V_139 = V_136 -> V_139 -> V_138 ;
if( V_136 -> V_139 ) {
V_136 -> V_139 -> V_140 = V_136 ;
}
V_136 -> V_140 -> V_138 = V_136 ;
}
static inline void
F_87 ( T_13 * V_134 , T_16 * V_136 )
{
if( V_136 -> V_140 ) {
if( V_136 -> V_140 -> V_138 == V_136 ) {
V_136 -> V_140 -> V_138 = V_136 -> V_138 ;
} else {
V_136 -> V_140 -> V_139 = V_136 -> V_138 ;
}
} else {
V_134 -> V_124 = V_136 -> V_138 ;
}
V_136 -> V_138 -> V_140 = V_136 -> V_140 ;
V_136 -> V_140 = V_136 -> V_138 ;
V_136 -> V_138 = V_136 -> V_138 -> V_139 ;
if( V_136 -> V_138 ) {
V_136 -> V_138 -> V_140 = V_136 ;
}
V_136 -> V_140 -> V_139 = V_136 ;
}
static inline void
F_88 ( T_13 * V_134 , T_16 * V_136 )
{
T_16 * V_141 ;
T_16 * V_140 ;
V_140 = F_83 ( V_136 ) ;
V_141 = F_83 ( V_140 ) ;
V_140 -> V_142 . V_143 = V_144 ;
V_141 -> V_142 . V_143 = V_145 ;
if( ( V_136 == V_140 -> V_138 ) && ( V_140 == V_141 -> V_138 ) ) {
F_87 ( V_134 , V_141 ) ;
} else {
F_86 ( V_134 , V_141 ) ;
}
}
static inline void
F_89 ( T_13 * V_134 , T_16 * V_136 )
{
T_16 * V_141 ;
T_16 * V_140 ;
V_140 = F_83 ( V_136 ) ;
V_141 = F_83 ( V_140 ) ;
if( ! V_141 ) {
return;
}
if( ( V_136 == V_140 -> V_139 ) && ( V_140 == V_141 -> V_138 ) ) {
F_86 ( V_134 , V_140 ) ;
V_136 = V_136 -> V_138 ;
} else if( ( V_136 == V_140 -> V_138 ) && ( V_140 == V_141 -> V_139 ) ) {
F_87 ( V_134 , V_140 ) ;
V_136 = V_136 -> V_139 ;
}
F_88 ( V_134 , V_136 ) ;
}
static inline void
F_90 ( T_13 * V_134 , T_16 * V_136 )
{
T_16 * V_141 ;
T_16 * V_140 ;
T_16 * V_146 ;
V_146 = F_85 ( V_136 ) ;
if( V_146 && ( V_146 -> V_142 . V_143 == V_145 ) ) {
V_140 = F_83 ( V_136 ) ;
V_140 -> V_142 . V_143 = V_144 ;
V_146 -> V_142 . V_143 = V_144 ;
V_141 = F_84 ( V_136 ) ;
V_141 -> V_142 . V_143 = V_145 ;
F_91 ( V_134 , V_141 ) ;
} else {
F_89 ( V_134 , V_136 ) ;
}
}
static inline void
F_92 ( T_13 * V_134 , T_16 * V_136 )
{
T_16 * V_140 ;
V_140 = F_83 ( V_136 ) ;
if( V_140 -> V_142 . V_143 == V_144 ) {
return;
}
F_90 ( V_134 , V_136 ) ;
}
static inline void
F_91 ( T_13 * V_134 , T_16 * V_136 )
{
T_16 * V_140 ;
V_140 = F_83 ( V_136 ) ;
if( ! V_140 ) {
V_136 -> V_142 . V_143 = V_144 ;
return;
}
F_92 ( V_134 , V_136 ) ;
}
void
F_93 ( T_13 * V_134 , T_15 V_135 , void * V_127 )
{
T_16 * V_136 ;
V_136 = V_134 -> V_124 ;
if( ! V_136 ) {
V_136 = V_134 -> malloc ( sizeof( T_16 ) ) ;
switch( V_134 -> type ) {
case V_147 :
V_136 -> V_142 . V_143 = V_144 ;
break;
}
V_136 -> V_140 = NULL ;
V_136 -> V_138 = NULL ;
V_136 -> V_139 = NULL ;
V_136 -> V_137 = V_135 ;
V_136 -> V_127 = V_127 ;
V_136 -> V_142 . V_148 = V_149 ;
V_134 -> V_124 = V_136 ;
return;
}
while( 1 ) {
if( V_135 == V_136 -> V_137 ) {
V_136 -> V_127 = V_127 ;
return;
}
if( V_135 < V_136 -> V_137 ) {
if( ! V_136 -> V_138 ) {
T_16 * V_150 ;
V_150 = V_134 -> malloc ( sizeof( T_16 ) ) ;
V_136 -> V_138 = V_150 ;
V_150 -> V_140 = V_136 ;
V_150 -> V_138 = NULL ;
V_150 -> V_139 = NULL ;
V_150 -> V_137 = V_135 ;
V_150 -> V_127 = V_127 ;
V_150 -> V_142 . V_148 = V_149 ;
V_136 = V_150 ;
break;
}
V_136 = V_136 -> V_138 ;
continue;
}
if( V_135 > V_136 -> V_137 ) {
if( ! V_136 -> V_139 ) {
T_16 * V_150 ;
V_150 = V_134 -> malloc ( sizeof( T_16 ) ) ;
V_136 -> V_139 = V_150 ;
V_150 -> V_140 = V_136 ;
V_150 -> V_138 = NULL ;
V_150 -> V_139 = NULL ;
V_150 -> V_137 = V_135 ;
V_150 -> V_127 = V_127 ;
V_150 -> V_142 . V_148 = V_149 ;
V_136 = V_150 ;
break;
}
V_136 = V_136 -> V_139 ;
continue;
}
}
switch( V_134 -> type ) {
case V_147 :
V_136 -> V_142 . V_143 = V_145 ;
F_91 ( V_134 , V_136 ) ;
break;
}
}
static void *
F_94 ( T_13 * V_134 , T_15 V_135 , void * (* F_95)( void * ) , void * V_151 , int V_148 )
{
T_16 * V_136 ;
V_136 = V_134 -> V_124 ;
if( ! V_136 ) {
V_136 = V_134 -> malloc ( sizeof( T_16 ) ) ;
switch( V_134 -> type ) {
case V_147 :
V_136 -> V_142 . V_143 = V_144 ;
break;
}
V_136 -> V_140 = NULL ;
V_136 -> V_138 = NULL ;
V_136 -> V_139 = NULL ;
V_136 -> V_137 = V_135 ;
V_136 -> V_127 = F_95 ( V_151 ) ;
V_136 -> V_142 . V_148 = V_148 ;
V_134 -> V_124 = V_136 ;
return V_136 -> V_127 ;
}
while( 1 ) {
if( V_135 == V_136 -> V_137 ) {
return V_136 -> V_127 ;
}
if( V_135 < V_136 -> V_137 ) {
if( ! V_136 -> V_138 ) {
T_16 * V_150 ;
V_150 = V_134 -> malloc ( sizeof( T_16 ) ) ;
V_136 -> V_138 = V_150 ;
V_150 -> V_140 = V_136 ;
V_150 -> V_138 = NULL ;
V_150 -> V_139 = NULL ;
V_150 -> V_137 = V_135 ;
V_150 -> V_127 = F_95 ( V_151 ) ;
V_150 -> V_142 . V_148 = V_148 ;
V_136 = V_150 ;
break;
}
V_136 = V_136 -> V_138 ;
continue;
}
if( V_135 > V_136 -> V_137 ) {
if( ! V_136 -> V_139 ) {
T_16 * V_150 ;
V_150 = V_134 -> malloc ( sizeof( T_16 ) ) ;
V_136 -> V_139 = V_150 ;
V_150 -> V_140 = V_136 ;
V_150 -> V_138 = NULL ;
V_150 -> V_139 = NULL ;
V_150 -> V_137 = V_135 ;
V_150 -> V_127 = F_95 ( V_151 ) ;
V_150 -> V_142 . V_148 = V_148 ;
V_136 = V_150 ;
break;
}
V_136 = V_136 -> V_139 ;
continue;
}
}
switch( V_134 -> type ) {
case V_147 :
V_136 -> V_142 . V_143 = V_145 ;
F_91 ( V_134 , V_136 ) ;
break;
}
return V_136 -> V_127 ;
}
T_13 *
F_96 ( int type , const char * V_133 )
{
T_13 * V_123 ;
V_123 = F_45 ( sizeof( T_13 ) ) ;
V_123 -> V_19 = NULL ;
V_123 -> type = type ;
V_123 -> V_124 = NULL ;
V_123 -> V_133 = V_133 ;
V_123 -> malloc = F_45 ;
return V_123 ;
}
T_13 *
F_97 ( int type , const char * V_133 )
{
T_13 * V_123 ;
V_123 = F_29 ( T_13 , 1 ) ;
V_123 -> V_19 = NULL ;
V_123 -> type = type ;
V_123 -> V_124 = NULL ;
V_123 -> V_133 = V_133 ;
V_123 -> malloc = ( void * (*)( T_3 ) ) F_34 ;
return V_123 ;
}
static T_13 *
F_98 ( T_13 * V_152 , const char * V_133 )
{
T_13 * V_123 ;
V_123 = V_152 -> malloc ( sizeof( T_13 ) ) ;
V_123 -> V_19 = NULL ;
V_123 -> type = V_152 -> type ;
V_123 -> V_124 = NULL ;
V_123 -> V_133 = V_133 ;
V_123 -> malloc = V_152 -> malloc ;
return V_123 ;
}
static void *
F_99 ( void * V_153 )
{
T_13 * V_134 = V_153 ;
return F_98 ( V_134 , L_54 ) ;
}
void
F_100 ( T_13 * V_134 , T_17 * V_135 , void * V_127 )
{
T_13 * V_154 ;
if( ( V_135 [ 0 ] . V_155 < 1 ) || ( V_135 [ 0 ] . V_155 > 100 ) ) {
F_101 () ;
}
if( ( V_135 [ 0 ] . V_155 == 1 ) && ( V_135 [ 1 ] . V_155 == 0 ) ) {
F_93 ( V_134 , * V_135 [ 0 ] . V_135 , V_127 ) ;
return;
}
V_154 = F_94 ( V_134 , * V_135 [ 0 ] . V_135 , F_99 , V_134 , V_156 ) ;
if( V_135 [ 0 ] . V_155 == 1 ) {
V_135 ++ ;
} else {
V_135 [ 0 ] . V_155 -- ;
V_135 [ 0 ] . V_135 ++ ;
}
F_100 ( V_154 , V_135 , V_127 ) ;
}
void *
F_102 ( T_13 * V_134 , T_17 * V_135 )
{
T_13 * V_154 ;
if( ! V_134 || ! V_135 ) return NULL ;
if( ( V_135 [ 0 ] . V_155 < 1 ) || ( V_135 [ 0 ] . V_155 > 100 ) ) {
F_101 () ;
}
if( ( V_135 [ 0 ] . V_155 == 1 ) && ( V_135 [ 1 ] . V_155 == 0 ) ) {
return F_81 ( V_134 , * V_135 [ 0 ] . V_135 ) ;
}
V_154 = F_81 ( V_134 , * V_135 [ 0 ] . V_135 ) ;
if( ! V_154 ) {
return NULL ;
}
if( V_135 [ 0 ] . V_155 == 1 ) {
V_135 ++ ;
} else {
V_135 [ 0 ] . V_155 -- ;
V_135 [ 0 ] . V_135 ++ ;
}
return F_102 ( V_154 , V_135 ) ;
}
void *
F_103 ( T_13 * V_134 , T_17 * V_135 )
{
T_13 * V_154 ;
if( ! V_134 || ! V_135 ) return NULL ;
if( ( V_135 [ 0 ] . V_155 < 1 ) || ( V_135 [ 0 ] . V_155 > 100 ) ) {
F_101 () ;
}
if( ( V_135 [ 0 ] . V_155 == 1 ) && ( V_135 [ 1 ] . V_155 == 0 ) ) {
return F_82 ( V_134 , * V_135 [ 0 ] . V_135 ) ;
}
V_154 = F_81 ( V_134 , * V_135 [ 0 ] . V_135 ) ;
if( ! V_154 )
return F_82 ( V_134 , * V_135 [ 0 ] . V_135 ) ;
if( V_135 [ 0 ] . V_155 == 1 ) {
V_135 ++ ;
} else {
V_135 [ 0 ] . V_155 -- ;
V_135 [ 0 ] . V_135 ++ ;
}
return F_103 ( V_154 , V_135 ) ;
}
void
F_104 ( T_13 * V_134 , const T_5 * V_157 , void * V_158 , T_15 V_159 )
{
T_17 V_135 [ 2 ] ;
T_15 * V_160 = NULL ;
T_15 V_6 = ( T_15 ) strlen ( V_157 ) ;
T_15 V_161 = ( V_6 + 3 ) / 4 + 1 ;
T_15 V_2 ;
T_15 V_162 ;
V_160 = F_34 ( V_161 * sizeof ( T_15 ) ) ;
V_162 = 0 ;
for ( V_2 = 0 ; V_2 < V_6 ; V_2 ++ ) {
unsigned char V_163 ;
V_163 = ( unsigned char ) V_157 [ V_2 ] ;
if ( V_159 & V_164 ) {
if( isupper ( V_163 ) ) {
V_163 = tolower ( V_163 ) ;
}
}
V_162 <<= 8 ;
V_162 |= V_163 ;
if ( V_2 % 4 == 3 ) {
V_160 [ V_2 / 4 ] = V_162 ;
V_162 = 0 ;
}
}
if ( V_2 % 4 != 0 ) {
while ( V_2 % 4 != 0 ) {
V_2 ++ ;
V_162 <<= 8 ;
}
V_160 [ V_2 / 4 - 1 ] = V_162 ;
}
V_160 [ V_161 - 1 ] = 0x00000001 ;
V_135 [ 0 ] . V_155 = V_161 ;
V_135 [ 0 ] . V_135 = V_160 ;
V_135 [ 1 ] . V_155 = 0 ;
V_135 [ 1 ] . V_135 = NULL ;
F_100 ( V_134 , V_135 , V_158 ) ;
F_31 ( V_160 ) ;
}
void *
F_105 ( T_13 * V_134 , const T_5 * V_157 , T_15 V_159 )
{
T_17 V_135 [ 2 ] ;
T_15 * V_160 = NULL ;
T_15 V_6 = ( T_8 ) strlen ( V_157 ) ;
T_15 V_161 = ( V_6 + 3 ) / 4 + 1 ;
T_15 V_2 ;
T_15 V_162 ;
void * V_82 ;
V_160 = F_34 ( V_161 * sizeof ( T_15 ) ) ;
V_162 = 0 ;
for ( V_2 = 0 ; V_2 < V_6 ; V_2 ++ ) {
unsigned char V_163 ;
V_163 = ( unsigned char ) V_157 [ V_2 ] ;
if ( V_159 & V_164 ) {
if( isupper ( V_163 ) ) {
V_163 = tolower ( V_163 ) ;
}
}
V_162 <<= 8 ;
V_162 |= V_163 ;
if ( V_2 % 4 == 3 ) {
V_160 [ V_2 / 4 ] = V_162 ;
V_162 = 0 ;
}
}
if ( V_2 % 4 != 0 ) {
while ( V_2 % 4 != 0 ) {
V_2 ++ ;
V_162 <<= 8 ;
}
V_160 [ V_2 / 4 - 1 ] = V_162 ;
}
V_160 [ V_161 - 1 ] = 0x00000001 ;
V_135 [ 0 ] . V_155 = V_161 ;
V_135 [ 0 ] . V_135 = V_160 ;
V_135 [ 1 ] . V_155 = 0 ;
V_135 [ 1 ] . V_135 = NULL ;
V_82 = F_102 ( V_134 , V_135 ) ;
F_31 ( V_160 ) ;
return V_82 ;
}
static T_9
F_106 ( T_16 * V_136 , T_18 V_165 , void * V_166 )
{
T_9 V_167 = FALSE ;
if ( ! V_136 )
return FALSE ;
if( V_136 -> V_138 ) {
V_167 = F_106 ( V_136 -> V_138 , V_165 , V_166 ) ;
if ( V_167 ) {
return TRUE ;
}
}
if ( V_136 -> V_142 . V_148 == V_156 ) {
V_167 = F_107 ( V_136 -> V_127 , V_165 , V_166 ) ;
} else {
V_167 = V_165 ( V_136 -> V_127 , V_166 ) ;
}
if ( V_167 ) {
return TRUE ;
}
if( V_136 -> V_139 ) {
V_167 = F_106 ( V_136 -> V_139 , V_165 , V_166 ) ;
if ( V_167 ) {
return TRUE ;
}
}
return FALSE ;
}
T_9
F_107 ( T_13 * V_168 , T_18 V_165 , void * V_166 )
{
if ( ! V_168 )
return FALSE ;
if( ! V_168 -> V_124 )
return FALSE ;
return F_106 ( V_168 -> V_124 , V_165 , V_166 ) ;
}
static void
F_108 ( T_16 * V_136 , int V_169 )
{
int V_2 ;
if ( ! V_136 )
return;
for( V_2 = 0 ; V_2 < V_169 ; V_2 ++ ) {
printf ( L_55 ) ;
}
printf ( L_56 ,
( void * ) V_136 , ( void * ) ( V_136 -> V_140 ) , ( void * ) ( V_136 -> V_138 ) , ( void * ) ( V_136 -> V_139 ) ,
( V_136 -> V_137 ) , V_136 -> V_127 ) ;
if( V_136 -> V_138 )
F_108 ( V_136 -> V_138 , V_169 + 1 ) ;
if( V_136 -> V_139 )
F_108 ( V_136 -> V_139 , V_169 + 1 ) ;
}
void
F_109 ( T_13 * V_168 )
{
if ( ! V_168 )
return;
printf ( L_57 , V_168 -> type , V_168 -> V_133 , ( void * ) ( V_168 -> V_124 ) ) ;
if( V_168 -> V_124 )
F_108 ( V_168 -> V_124 , 0 ) ;
}
static T_12
F_110 ( T_12 V_170 , T_12 V_171 , T_12 V_172 )
{
if ( V_172 < 1 || V_172 > V_173 ) {
V_172 = V_173 ;
}
if ( V_170 < 1 ) {
V_170 = V_174 ;
}
while ( V_170 < V_171 ) {
V_170 *= 2 ;
}
return V_170 < V_172 ? V_170 : V_172 ;
}
static void
F_111 ( T_19 * V_175 , T_12 V_171 )
{
T_12 V_176 ;
T_5 * V_177 ;
if ( ! V_175 || ( V_171 <= V_175 -> V_178 ) || ( V_175 -> V_178 >= V_175 -> V_172 ) ) {
return;
}
V_176 = F_110 ( V_175 -> V_178 , V_171 , V_175 -> V_172 ) ;
V_177 = F_44 ( V_176 ) ;
F_9 ( V_177 , V_175 -> V_179 , V_176 ) ;
V_175 -> V_178 = V_176 ;
V_175 -> V_179 = V_177 ;
}
T_19 *
F_112 ( T_12 V_178 , T_12 V_172 )
{
T_19 * V_175 ;
V_175 = F_44 ( sizeof( T_19 ) ) ;
if ( ( V_172 == 0 ) || ( V_172 > V_173 ) )
V_172 = V_173 ;
if ( V_178 == 0 )
V_178 = 1 ;
else if ( V_178 > V_172 )
V_178 = V_172 ;
V_175 -> V_179 = F_44 ( V_178 ) ;
V_175 -> V_179 [ 0 ] = '\0' ;
V_175 -> V_6 = 0 ;
V_175 -> V_178 = V_178 ;
V_175 -> V_172 = V_172 ;
return V_175 ;
}
T_19 *
F_113 ( const T_5 * V_180 )
{
T_19 * V_175 ;
V_175 = F_112 ( F_110 ( 0 , V_180 ? strlen ( V_180 ) + 1 : 0 , 0 ) , 0 ) ;
if ( V_180 ) {
T_12 V_181 ;
V_181 = F_9 ( V_175 -> V_179 , V_180 , V_175 -> V_178 ) ;
V_175 -> V_6 = F_114 ( V_181 , V_175 -> V_178 - 1 ) ;
}
return V_175 ;
}
T_19 *
F_115 ( const T_5 * V_180 )
{
T_19 * V_175 ;
T_12 V_181 ;
V_175 = F_112 ( V_174 , V_182 ) ;
if ( ! V_180 )
return V_175 ;
V_181 = F_9 ( V_175 -> V_179 , V_180 , V_175 -> V_178 ) ;
if ( V_181 < V_175 -> V_178 ) {
V_175 -> V_6 += V_181 ;
} else {
V_175 = F_112 ( V_181 + 1 , V_182 ) ;
V_181 = F_9 ( V_175 -> V_179 , V_180 , V_175 -> V_178 ) ;
V_175 -> V_6 = F_114 ( V_181 , V_175 -> V_178 - 1 ) ;
}
return V_175 ;
}
T_19 *
F_116 ( T_19 * V_175 , const T_5 * V_179 )
{
T_12 V_183 , V_181 ;
if ( ! V_175 || ! V_179 || V_179 [ 0 ] == '\0' ) {
return V_175 ;
}
V_183 = V_175 -> V_178 - V_175 -> V_6 ;
V_181 = F_9 ( & V_175 -> V_179 [ V_175 -> V_6 ] , V_179 , V_183 ) ;
if ( V_181 < V_183 ) {
V_175 -> V_6 += V_181 ;
} else {
V_175 -> V_179 [ V_175 -> V_6 ] = '\0' ;
F_111 ( V_175 , V_175 -> V_6 + V_181 + 1 ) ;
V_183 = V_175 -> V_178 - V_175 -> V_6 ;
V_181 = F_9 ( & V_175 -> V_179 [ V_175 -> V_6 ] , V_179 , V_183 ) ;
V_175 -> V_6 += F_114 ( V_183 - 1 , V_181 ) ;
}
return V_175 ;
}
void
F_117 ( T_19 * V_175 , const T_5 * V_184 , T_4 V_12 )
{
T_4 V_103 ;
T_12 V_183 , V_181 ;
F_61 ( V_103 , V_12 ) ;
V_183 = V_175 -> V_178 - V_175 -> V_6 ;
V_181 = F_7 ( & V_175 -> V_179 [ V_175 -> V_6 ] , ( V_104 ) V_183 , V_184 , V_12 ) ;
if ( V_181 < V_183 ) {
V_175 -> V_6 += V_181 ;
} else {
V_175 -> V_179 [ V_175 -> V_6 ] = '\0' ;
F_111 ( V_175 , V_175 -> V_6 + V_181 + 1 ) ;
V_183 = V_175 -> V_178 - V_175 -> V_6 ;
V_181 = F_7 ( & V_175 -> V_179 [ V_175 -> V_6 ] , ( V_104 ) V_183 , V_184 , V_103 ) ;
V_175 -> V_6 += F_114 ( V_183 - 1 , V_181 ) ;
}
va_end ( V_103 ) ;
}
void
F_118 ( T_19 * V_175 , const T_5 * V_184 , ... )
{
T_4 V_12 ;
va_start ( V_12 , V_184 ) ;
F_117 ( V_175 , V_184 , V_12 ) ;
va_end ( V_12 ) ;
}
void
F_119 ( T_19 * V_175 , const T_5 * V_184 , ... )
{
T_4 V_12 ;
if ( ! V_175 ) {
return;
}
V_175 -> V_6 = 0 ;
va_start ( V_12 , V_184 ) ;
F_117 ( V_175 , V_184 , V_12 ) ;
va_end ( V_12 ) ;
}
T_19 *
F_120 ( T_19 * V_175 , const T_5 V_185 )
{
if ( ! V_175 ) {
return V_175 ;
}
if ( V_175 -> V_178 < V_175 -> V_6 + 1 + 1 ) {
F_111 ( V_175 , V_175 -> V_6 + 1 + 1 ) ;
}
if ( V_175 -> V_178 >= V_175 -> V_6 + 1 + 1 ) {
V_175 -> V_179 [ V_175 -> V_6 ] = V_185 ;
V_175 -> V_6 ++ ;
V_175 -> V_179 [ V_175 -> V_6 ] = '\0' ;
}
return V_175 ;
}
T_19 *
F_121 ( T_19 * V_175 , T_12 V_6 )
{
if ( ! V_175 || V_6 >= V_175 -> V_6 ) {
return V_175 ;
}
V_175 -> V_179 [ V_6 ] = '\0' ;
V_175 -> V_6 = V_6 ;
return V_175 ;
}
