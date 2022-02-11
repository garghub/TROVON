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
* V_6 = V_2 + 1 + ( int ) sizeof( void * ) ;
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
static T_8
F_11 ( const T_7 * V_28 )
{
T_8 V_29 = 0 ;
T_6 * V_30 ;
for ( V_30 = V_28 -> V_31 ; V_30 ; V_30 = V_30 -> V_19 )
V_29 += ( V_30 -> V_32 - V_30 -> V_33 ) ;
for ( V_30 = V_28 -> V_18 ; V_30 ; V_30 = V_30 -> V_19 )
V_29 += ( V_30 -> V_32 - V_30 -> V_33 ) ;
return V_29 ;
}
static T_8
F_12 ( void )
{
return F_11 ( & V_17 ) ;
}
static void
F_13 ( void )
{
static const T_9 V_34 = { L_2 , F_12 , NULL } ;
V_17 . V_18 = NULL ;
V_17 . V_31 = NULL ;
V_17 . V_35 = NULL ;
V_17 . V_24 = ( getenv ( L_3 ) == NULL ) ;
V_17 . V_23 = V_17 . V_24 && ( getenv ( L_4 ) == NULL ) ;
V_17 . V_36 = ( getenv ( L_5 ) != NULL ) ;
#ifdef F_14
V_16 = ( getenv ( L_6 ) != NULL ) ;
#endif
F_10 ( & V_17 ) ;
F_15 ( & V_34 ) ;
}
static T_8
F_16 ( void )
{
return F_11 ( & V_37 ) ;
}
static void
F_17 ( void )
{
static const T_9 V_38 = { L_7 , F_16 , NULL } ;
V_37 . V_18 = NULL ;
V_37 . V_31 = NULL ;
V_37 . V_35 = NULL ;
V_37 . V_24 = ( getenv ( L_8 ) == NULL ) ;
V_37 . V_23 = V_37 . V_24 && ( getenv ( L_9 ) != NULL ) ;
V_37 . V_36 = ( getenv ( L_10 ) != NULL ) ;
F_10 ( & V_37 ) ;
F_15 ( & V_38 ) ;
}
void
F_18 ( void )
{
F_13 () ;
F_17 () ;
if ( getenv ( L_11 ) )
V_39 = TRUE ;
#if F_19 ( V_40 )
F_20 ( & V_41 ) ;
V_42 = V_41 . V_43 ;
V_44 . V_45 = sizeof( V_46 ) ;
F_21 ( & V_44 ) ;
#elif F_19 ( V_47 )
V_42 = F_22 ( V_48 ) ;
if ( V_42 == - 1 )
fprintf ( V_49 , L_12 ) ;
#ifdef F_23
V_50 = F_24 ( L_13 , V_51 ) ;
F_25 ( V_50 != - 1 ) ;
#endif
#endif
}
static void
F_26 ( void )
{
T_10 V_52 = 0 ;
T_10 V_53 = 0 ;
T_10 V_29 = 0 ;
T_10 V_54 = 0 ;
T_10 V_55 = 0 ;
T_10 V_56 ;
T_10 V_2 ;
T_6 * V_30 ;
T_10 V_57 , V_58 ;
T_11 V_59 = TRUE ;
fprintf ( V_49 , L_14 ) ;
fprintf ( V_49 , L_15 ,
V_17 . V_24 ? L_16 : L_17 ,
V_17 . V_23 ? L_18 : L_19 ,
V_39 ? L_18 : L_19 ) ;
if ( ! ( V_17 . V_18 || ! V_17 . V_31 ) ) {
fprintf ( V_49 , L_20 ) ;
V_59 = FALSE ;
}
if ( V_17 . V_24 && V_59 ) {
for ( V_30 = V_17 . V_31 ; V_30 ; V_30 = V_30 -> V_19 ) {
V_52 ++ ;
V_29 += ( V_30 -> V_32 - V_30 -> V_33 ) ;
V_54 += V_30 -> V_32 ;
}
if ( V_52 > 0 ) {
fprintf ( V_49 , L_21 ) ;
fprintf ( V_49 , L_22 ) ;
fprintf ( V_49 , L_23 , V_60 ) ;
fprintf ( V_49 , L_24 , V_52 ) ;
fprintf ( V_49 , L_25 ) ;
fprintf ( V_49 , L_26 ,
V_54 , V_60 * V_52 ) ;
fprintf ( V_49 , L_25 ) ;
V_57 = V_54
+ sizeof( T_6 ) * V_52 ;
fprintf ( V_49 , L_27 ,
V_57 ) ;
} else{
fprintf ( V_49 , L_28 ) ;
}
V_52 = 0 ;
V_53 = 0 ;
V_29 = 0 ;
V_54 = 0 ;
V_55 = 0 ;
}
fprintf ( V_49 , L_29 ) ;
fprintf ( V_49 , L_30 ,
V_61 ) ;
fprintf ( V_49 , L_31 ,
V_37 . V_24 ? L_16 : L_17 ,
V_37 . V_23 ? L_18 : L_19 ) ;
if ( ! ( V_37 . V_18 || ! V_37 . V_31 ) ) {
fprintf ( V_49 , L_20 ) ;
return;
}
if ( ! V_37 . V_24 )
return;
for ( V_30 = V_37 . V_31 ; V_30 ; V_30 = V_30 -> V_19 ) {
V_52 ++ ;
V_29 += ( V_30 -> V_32 - V_30 -> V_33 ) ;
V_54 += V_30 -> V_32 ;
if ( V_37 . V_23 ) {
void * V_7 = V_30 -> V_21 ;
int V_6 ;
while ( V_7 != NULL ) {
V_7 = F_4 ( V_37 . V_1 , ( T_1 * ) V_7 , & V_6 ) ;
if ( V_7 == ( void * ) - 1 )
F_8 ( L_32 ) ;
V_55 += V_6 ;
}
}
}
if ( V_52 == 0 ) {
fprintf ( V_49 , L_28 ) ;
return;
}
fprintf ( V_49 , L_21 ) ;
fprintf ( V_49 , L_33 ) ;
fprintf ( V_49 , L_34 ) ;
fprintf ( V_49 , L_35 ,
sizeof( T_6 ) ) ;
fprintf ( V_49 , L_36 , V_52 ) ;
fprintf ( V_49 , L_25 ) ;
V_56 = sizeof( T_6 ) * V_52 ;
fprintf ( V_49 , L_37 , V_56 ) ;
fprintf ( V_49 , L_22 ) ;
fprintf ( V_49 , L_23 ,
V_60 ) ;
fprintf ( V_49 , L_24 , V_52 ) ;
fprintf ( V_49 , L_25 ) ;
fprintf ( V_49 , L_38 ,
V_54 , V_60 * V_52 ) ;
fprintf ( V_49 , L_25 ) ;
V_57 = ( V_60 * V_52 )
+ V_56 ;
fprintf ( V_49 , L_39 ,
V_57 ) ;
for ( V_2 = 0 ; V_2 < V_62 ; V_2 ++ )
V_53 += V_63 [ V_2 ] ;
fprintf ( V_49 , L_40 ) ;
fprintf ( V_49 , L_41 ,
V_53 ) ;
fprintf ( V_49 , L_42 ,
V_29 ) ;
fprintf ( V_49 , L_43 ,
V_55 ) ;
fprintf ( V_49 , L_44 ,
V_54 - V_29 ) ;
fprintf ( V_49 , L_45 ,
V_57 - V_29 ) ;
fprintf ( V_49 , L_46 ) ;
fprintf ( V_49 , L_47 ,
( float ) V_29 / ( float ) V_53 ) ;
fprintf ( V_49 , L_48 ,
( float ) ( V_29 - V_55 ) / ( float ) V_53 ) ;
fprintf ( V_49 , L_49 ,
( V_54 - V_29 ) / ( float ) V_53 ) ;
V_58 = ( V_54 - V_29 )
+ ( sizeof( T_6 ) ) ;
fprintf ( V_49 , L_50 ,
V_58 ) ;
fprintf ( V_49 , L_51 ,
100 * ( float ) V_58 / ( float ) V_57 ) ;
fprintf ( V_49 , L_52 ) ;
for ( V_2 = 0 ; V_2 < ( V_62 - 1 ) ; V_2 ++ )
fprintf ( V_49 , L_53 , 32 << V_2 , V_63 [ V_2 ] ) ;
fprintf ( V_49 , L_54 , 32 << V_2 , V_63 [ V_2 ] ) ;
}
static T_11
F_27 ( const T_6 * V_64 , const void * V_7 )
{
const T_5 * V_65 = ( T_5 * ) V_7 ;
const T_6 * V_30 ;
for ( V_30 = V_64 ; V_30 ; V_30 = V_30 -> V_19 ) {
if ( V_65 >= ( V_30 -> V_66 + V_30 -> V_67 ) && V_65 < ( V_30 -> V_66 + V_30 -> V_68 ) )
return TRUE ;
}
return FALSE ;
}
static T_11
F_28 ( const T_7 * V_69 , const void * V_7 )
{
return F_27 ( V_69 -> V_18 , V_7 ) || F_27 ( V_69 -> V_31 , V_7 ) ;
}
T_11
F_29 ( const void * V_7 )
{
if ( V_17 . V_36 )
return F_28 ( & V_17 , V_7 ) ;
else
return FALSE ;
}
T_11
F_30 ( const void * V_7 )
{
if ( V_37 . V_36 )
return F_28 ( & V_37 , V_7 ) ;
else
return FALSE ;
}
static void
F_31 ( char * V_66 , T_3 V_70 , T_11 V_71 )
{
T_10 V_72 ;
T_3 V_73 ;
if ( ! V_39 )
return;
if ( V_71 )
V_72 = 0xBADDCAFE ;
else
V_72 = 0xDEADBEEF ;
for ( V_73 = 0 ; V_73 + sizeof( T_10 ) <= V_70 ; V_73 += sizeof( T_10 ) )
* ( T_10 * ) ( void * ) ( V_66 + V_73 ) = V_72 ;
if ( V_73 < V_70 ) {
* ( T_1 * ) ( V_66 + V_73 ) = V_72 >> 24 ;
V_73 ++ ;
if ( V_73 < V_70 ) {
* ( T_1 * ) ( V_66 + V_73 ) = ( V_72 >> 16 ) & 0xFF ;
V_73 ++ ;
if ( V_73 < V_70 ) {
* ( T_1 * ) ( V_66 + V_73 ) = ( V_72 >> 8 ) & 0xFF ;
}
}
}
}
static T_6 *
F_32 ( T_3 V_70 )
{
T_6 * V_15 ;
V_15 = F_33 ( T_6 , 1 ) ;
V_15 -> V_19 = NULL ;
V_15 -> V_21 = NULL ;
#if F_19 ( V_40 )
V_15 -> V_66 = ( char * ) F_34 ( NULL , V_70 ,
V_74 | V_75 , V_76 ) ;
if ( V_15 -> V_66 == NULL ) {
F_35 ( V_15 ) ;
if ( getenv ( L_55 ) )
abort () ;
else
F_36 ( V_77 ) ;
}
#elif F_19 ( V_47 )
V_15 -> V_66 = ( char * ) F_37 ( NULL , V_70 ,
V_78 | V_79 , V_80 , V_81 , 0 ) ;
if ( V_15 -> V_66 == V_82 ) {
F_35 ( V_15 ) ;
if ( getenv ( L_55 ) )
abort () ;
else
F_36 ( V_77 ) ;
}
#else
V_15 -> V_66 = F_38 ( V_70 ) ;
#endif
#ifdef F_39
V_61 ++ ;
#endif
V_15 -> V_33 = V_15 -> V_32 = ( unsigned int ) V_70 ;
V_15 -> V_68 = V_15 -> V_67 = 0 ;
return V_15 ;
}
static T_6 *
F_40 ( T_3 V_70 )
{
#if F_19 ( V_40 )
BOOL V_83 ;
char * V_84 , * V_85 , * V_86 ;
T_12 V_87 ;
#elif F_19 ( V_47 )
int V_83 ;
char * V_84 , * V_85 , * V_86 ;
#endif
T_6 * V_15 ;
V_15 = F_32 ( V_70 ) ;
#if F_19 ( V_40 )
V_84 = V_15 -> V_66 + V_70 ;
V_85 = ( char * ) ( ( ( ( V_88 ) V_15 -> V_66 + V_42 - 1 ) / V_42 ) * V_42 ) ;
V_86 = ( char * ) ( ( ( ( V_88 ) V_84 - ( 1 * V_42 ) ) / V_42 ) * V_42 ) ;
V_83 = F_41 ( V_85 , V_42 , V_89 , & V_87 ) ;
F_25 ( V_83 != 0 || V_44 . V_90 == V_91 ) ;
V_83 = F_41 ( V_86 , V_42 , V_89 , & V_87 ) ;
F_25 ( V_83 != 0 || V_44 . V_90 == V_91 ) ;
V_15 -> V_32 = ( unsigned int ) ( V_86 - V_85 - V_42 ) ;
V_15 -> V_67 = ( unsigned int ) ( V_85 - V_15 -> V_66 ) + V_42 ;
#elif F_19 ( V_47 )
V_84 = V_15 -> V_66 + V_70 ;
V_85 = ( char * ) ( ( ( ( V_88 ) V_15 -> V_66 + V_42 - 1 ) / V_42 ) * V_42 ) ;
V_86 = ( char * ) ( ( ( ( V_88 ) V_84 - ( 1 * V_42 ) ) / V_42 ) * V_42 ) ;
V_83 = F_42 ( V_85 , V_42 , V_92 ) ;
F_25 ( V_83 != - 1 ) ;
V_83 = F_42 ( V_86 , V_42 , V_92 ) ;
F_25 ( V_83 != - 1 ) ;
V_15 -> V_32 = ( unsigned int ) ( V_86 - V_85 - V_42 ) ;
V_15 -> V_67 = ( unsigned int ) ( ( V_85 - V_15 -> V_66 ) + V_42 ) ;
#else
V_15 -> V_32 = V_70 ;
V_15 -> V_67 = 0 ;
#endif
V_15 -> V_33 = V_15 -> V_32 ;
V_15 -> V_68 = V_15 -> V_67 ;
return V_15 ;
}
static void *
V_26 ( T_3 V_70 , T_7 * V_22 )
{
void * V_66 ;
T_3 V_93 = V_70 ;
T_11 V_94 = V_22 -> V_23 ;
T_1 V_10 ;
T_6 * V_18 ;
if ( V_94 ) {
V_93 += sizeof( void * ) ;
V_10 = F_5 ( V_93 ) ;
} else
V_10 = ( V_95 - ( V_93 & ( V_95 - 1 ) ) ) & ( V_95 - 1 ) ;
V_93 += V_10 ;
#ifdef F_39
if ( V_22 == & V_37 ) {
if ( V_93 < 32 )
V_63 [ 0 ] ++ ;
else if ( V_93 < 64 )
V_63 [ 1 ] ++ ;
else if ( V_93 < 128 )
V_63 [ 2 ] ++ ;
else if ( V_93 < 256 )
V_63 [ 3 ] ++ ;
else if ( V_93 < 512 )
V_63 [ 4 ] ++ ;
else if ( V_93 < 1024 )
V_63 [ 5 ] ++ ;
else if ( V_93 < 2048 )
V_63 [ 6 ] ++ ;
else if ( V_93 < 4096 )
V_63 [ 7 ] ++ ;
else if ( V_93 < 8192 )
V_63 [ 8 ] ++ ;
else if ( V_93 < 16384 )
V_63 [ 8 ] ++ ;
else
V_63 [ ( V_62 - 1 ) ] ++ ;
}
#endif
F_43 ( V_70 < ( V_60 >> 2 ) ) ;
if ( ! V_22 -> V_18 )
V_22 -> V_18 = F_40 ( V_60 ) ;
if( V_93 > V_22 -> V_18 -> V_33 ) {
T_6 * V_15 ;
V_15 = V_22 -> V_18 ;
V_22 -> V_18 = V_22 -> V_18 -> V_19 ;
V_15 -> V_19 = V_22 -> V_31 ;
V_22 -> V_31 = V_15 ;
if ( ! V_22 -> V_18 )
V_22 -> V_18 = F_40 ( V_60 ) ;
}
V_18 = V_22 -> V_18 ;
V_66 = V_18 -> V_66 + V_18 -> V_68 ;
V_18 -> V_33 -= ( unsigned int ) V_93 ;
V_18 -> V_68 += ( unsigned int ) V_93 ;
if ( V_94 ) {
char * V_65 = ( char * ) V_66 + V_70 ;
memcpy ( V_65 , V_22 -> V_1 , V_10 - 1 ) ;
V_65 [ V_10 - 1 ] = '\0' ;
memcpy ( V_65 + V_10 , & V_18 -> V_21 , sizeof( void * ) ) ;
V_18 -> V_21 = V_65 ;
}
return V_66 ;
}
static void *
V_27 ( T_3 V_70 , T_7 * V_22 )
{
T_6 * V_15 ;
V_15 = F_33 ( T_6 , 1 ) ;
V_15 -> V_19 = V_22 -> V_31 ;
V_15 -> V_66 = ( char * ) F_38 ( V_70 ) ;
V_15 -> V_21 = NULL ;
V_22 -> V_31 = V_15 ;
V_15 -> V_33 = V_15 -> V_67 = 0 ;
V_15 -> V_68 = V_15 -> V_32 = ( unsigned int ) V_70 ;
return V_15 -> V_66 ;
}
static void *
F_44 ( T_3 V_70 , T_7 * V_22 )
{
void * V_66 ;
#if 0
if (mem == &ep_packet_mem) {
return wmem_alloc(wmem_packet_scope(), size);
}
else if (mem == &se_packet_mem) {
return wmem_alloc(wmem_file_scope(), size);
}
#endif
V_66 = V_22 -> V_25 ( V_70 , V_22 ) ;
F_31 ( ( char * ) V_66 , V_70 , TRUE ) ;
return V_66 ;
}
void *
F_45 ( T_3 V_70 )
{
return F_44 ( V_70 , & V_17 ) ;
}
void *
F_46 ( T_3 V_70 )
{
return F_44 ( V_70 , & V_37 ) ;
}
void *
F_47 ( T_3 V_70 )
{
return memset ( F_45 ( V_70 ) , '\0' , V_70 ) ;
}
void *
F_48 ( T_3 V_70 )
{
return memset ( F_46 ( V_70 ) , '\0' , V_70 ) ;
}
static T_5 *
F_49 ( const T_5 * V_96 , void * F_50 ( T_3 ) )
{
T_10 V_6 ;
T_5 * V_97 ;
if( ! V_96 )
V_96 = L_56 ;
V_6 = ( T_10 ) strlen ( V_96 ) ;
V_97 = ( T_5 * ) memcpy ( F_50 ( V_6 + 1 ) , V_96 , V_6 + 1 ) ;
return V_97 ;
}
T_5 *
F_51 ( const T_5 * V_96 )
{
return F_49 ( V_96 , F_45 ) ;
}
T_5 *
F_52 ( const T_5 * V_96 )
{
return F_49 ( V_96 , F_46 ) ;
}
static T_5 *
F_53 ( const T_5 * V_96 , T_3 V_6 , void * F_50 ( T_3 ) )
{
T_5 * V_97 = ( T_5 * ) F_50 ( V_6 + 1 ) ;
T_10 V_2 ;
for ( V_2 = 0 ; ( V_2 < V_6 ) && V_96 [ V_2 ] ; V_2 ++ )
V_97 [ V_2 ] = V_96 [ V_2 ] ;
V_97 [ V_2 ] = '\0' ;
return V_97 ;
}
T_5 *
F_54 ( const T_5 * V_96 , T_3 V_6 )
{
return F_53 ( V_96 , V_6 , F_45 ) ;
}
T_5 *
F_55 ( const T_5 * V_96 , T_3 V_6 )
{
return F_53 ( V_96 , V_6 , F_46 ) ;
}
void *
F_56 ( const void * V_96 , T_3 V_6 )
{
return memcpy ( F_45 ( V_6 ) , V_96 , V_6 ) ;
}
void *
F_57 ( const void * V_96 , T_3 V_6 )
{
return memcpy ( F_46 ( V_6 ) , V_96 , V_6 ) ;
}
static T_5 *
F_58 ( const T_5 * V_11 , T_4 V_12 , void * F_50 ( T_3 ) )
{
T_4 V_98 ;
T_8 V_6 ;
T_5 * V_97 ;
F_59 ( V_98 , V_12 ) ;
V_6 = F_60 ( V_11 , V_12 ) ;
V_97 = ( T_5 * ) F_50 ( V_6 + 1 ) ;
F_7 ( V_97 , ( V_99 ) V_6 , V_11 , V_98 ) ;
va_end ( V_98 ) ;
return V_97 ;
}
T_5 *
F_61 ( const T_5 * V_11 , T_4 V_12 )
{
return F_58 ( V_11 , V_12 , F_45 ) ;
}
T_5 *
F_62 ( const T_5 * V_11 , T_4 V_12 )
{
return F_58 ( V_11 , V_12 , F_46 ) ;
}
T_5 *
F_63 ( const T_5 * V_11 , ... )
{
T_4 V_12 ;
T_5 * V_97 ;
va_start ( V_12 , V_11 ) ;
V_97 = F_61 ( V_11 , V_12 ) ;
va_end ( V_12 ) ;
return V_97 ;
}
T_5 *
F_64 ( const T_5 * V_11 , ... )
{
T_4 V_12 ;
T_5 * V_97 ;
va_start ( V_12 , V_11 ) ;
V_97 = F_62 ( V_11 , V_12 ) ;
va_end ( V_12 ) ;
return V_97 ;
}
T_5 * *
F_65 ( const T_5 * string , const T_5 * V_100 , int V_101 )
{
T_5 * V_102 ;
T_5 * V_103 ;
T_10 V_104 ;
T_10 V_105 ;
T_10 V_106 ;
T_10 V_2 ;
T_5 * * V_107 ;
enum { V_108 , V_109 , V_110 } V_111 ;
T_10 V_112 = 0 ;
if ( ! string
|| ! V_100
|| ! V_100 [ 0 ] )
return NULL ;
V_103 = V_102 = F_51 ( string ) ;
V_105 = ( T_10 ) strlen ( V_102 ) ;
V_106 = ( T_10 ) strlen ( V_100 ) ;
if ( V_101 < 1 ) V_101 = V_113 ;
V_104 = 1 ;
while ( V_104 <= ( T_10 ) V_101 && ( V_103 = strstr ( V_103 , V_100 ) ) ) {
V_104 ++ ;
for( V_2 = 0 ; V_2 < V_106 ; V_2 ++ )
V_103 [ V_2 ] = '\0' ;
V_103 += V_106 ;
}
V_107 = F_66 ( T_5 * , V_104 + 1 ) ;
V_111 = V_108 ;
for ( V_2 = 0 ; V_2 < V_105 ; V_2 ++ ) {
switch( V_111 ) {
case V_108 :
switch( V_102 [ V_2 ] ) {
case '\0' :
V_111 = V_109 ;
continue;
default:
V_107 [ V_112 ] = & ( V_102 [ V_2 ] ) ;
V_112 ++ ;
V_111 = V_110 ;
continue;
}
case V_110 :
switch( V_102 [ V_2 ] ) {
case '\0' :
V_111 = V_109 ;
default:
continue;
}
case V_109 :
switch( V_102 [ V_2 ] ) {
default:
V_107 [ V_112 ] = & ( V_102 [ V_2 ] ) ;
V_112 ++ ;
V_111 = V_110 ;
case '\0' :
continue;
}
}
}
V_107 [ V_112 ] = NULL ;
return V_107 ;
}
T_5 *
F_67 ( const T_5 * V_114 , ... )
{
T_8 V_115 ;
T_4 args ;
T_5 * V_103 ;
T_5 * V_116 ;
T_5 * V_7 ;
if ( ! V_114 )
return NULL ;
V_115 = 1 + strlen ( V_114 ) ;
va_start ( args , V_114 ) ;
V_103 = va_arg ( args , T_5 * ) ;
while ( V_103 ) {
V_115 += strlen ( V_103 ) ;
V_103 = va_arg ( args , T_5 * ) ;
}
va_end ( args ) ;
V_116 = ( T_5 * ) F_45 ( V_115 ) ;
V_7 = V_116 ;
V_7 = F_68 ( V_7 , V_114 ) ;
va_start ( args , V_114 ) ;
V_103 = va_arg ( args , T_5 * ) ;
while ( V_103 ) {
V_7 = F_68 ( V_7 , V_103 ) ;
V_103 = va_arg ( args , T_5 * ) ;
}
va_end ( args ) ;
return V_116 ;
}
static void
F_69 ( T_7 * V_22 )
{
T_11 V_117 = V_22 -> V_24 ;
T_6 * V_15 ;
T_13 * V_118 ;
while( V_22 -> V_31 ) {
V_15 = V_22 -> V_31 ;
V_22 -> V_31 = V_22 -> V_31 -> V_19 ;
V_15 -> V_19 = V_22 -> V_18 ;
V_22 -> V_18 = V_15 ;
}
V_15 = V_22 -> V_18 ;
while ( V_15 != NULL ) {
if ( V_117 ) {
while ( V_15 -> V_21 != NULL ) {
V_15 -> V_21 = F_4 ( V_22 -> V_1 , ( T_1 * ) V_15 -> V_21 , NULL ) ;
if ( V_15 -> V_21 == ( void * ) - 1 )
F_8 ( L_32 ) ;
}
F_31 ( ( V_15 -> V_66 + V_15 -> V_67 ) ,
( V_15 -> V_68 - V_15 -> V_67 ) ,
FALSE ) ;
V_15 -> V_33 = V_15 -> V_32 ;
V_15 -> V_68 = V_15 -> V_67 ;
V_15 = V_15 -> V_19 ;
} else {
T_6 * V_19 = V_15 -> V_19 ;
F_31 ( V_15 -> V_66 , V_15 -> V_32 , FALSE ) ;
F_35 ( V_15 -> V_66 ) ;
F_35 ( V_15 ) ;
V_15 = V_19 ;
}
}
if ( ! V_117 ) {
V_22 -> V_18 = NULL ;
}
for( V_118 = V_22 -> V_35 ; V_118 ; V_118 = V_118 -> V_19 ) {
V_118 -> V_119 = NULL ;
}
}
void
F_70 ( void )
{
F_69 ( & V_17 ) ;
}
void
F_71 ( void )
{
#ifdef F_39
F_26 () ;
#endif
F_69 ( & V_37 ) ;
}
T_14
F_72 ( void ) {
T_14 V_103 = F_73 ( struct V_120 * ) ;
* V_103 = F_74 ( struct V_120 ) ;
return V_103 ;
}
void *
F_75 ( T_14 V_121 , void * V_122 )
{
struct V_120 * V_123 ;
struct V_120 * V_124 = ( * V_121 ) ;
if ( V_124 -> V_125 ) {
V_123 = V_124 -> V_125 ;
} else {
V_123 = F_73 ( struct V_120 ) ;
V_124 -> V_125 = V_123 ;
V_123 -> V_126 = V_124 ;
V_123 -> V_125 = NULL ;
}
V_123 -> V_127 = V_122 ;
( * V_121 ) = V_123 ;
return V_122 ;
}
void *
F_76 ( T_14 V_121 )
{
if ( ( * V_121 ) -> V_126 ) {
( * V_121 ) = ( * V_121 ) -> V_126 ;
return ( * V_121 ) -> V_125 -> V_127 ;
} else {
return NULL ;
}
}
T_13 *
F_77 ( int type , const char * V_128 )
{
T_13 * V_118 ;
V_118 = ( T_13 * ) F_38 ( sizeof( T_13 ) ) ;
V_118 -> V_19 = V_37 . V_35 ;
V_118 -> type = type ;
V_118 -> V_119 = NULL ;
V_118 -> V_128 = V_128 ;
V_118 -> malloc = F_46 ;
V_37 . V_35 = V_118 ;
return V_118 ;
}
void *
F_78 ( T_13 * V_129 , T_15 V_130 )
{
T_16 * V_131 ;
V_131 = V_129 -> V_119 ;
while( V_131 ) {
if( V_130 == V_131 -> V_132 ) {
return V_131 -> V_122 ;
}
if( V_130 < V_131 -> V_132 ) {
V_131 = V_131 -> V_133 ;
continue;
}
if( V_130 > V_131 -> V_132 ) {
V_131 = V_131 -> V_134 ;
continue;
}
}
return NULL ;
}
void *
F_79 ( T_13 * V_129 , T_15 V_130 )
{
T_16 * V_131 ;
V_131 = V_129 -> V_119 ;
if( ! V_131 ) {
return NULL ;
}
while( V_131 ) {
if( V_130 == V_131 -> V_132 ) {
return V_131 -> V_122 ;
}
if( V_130 < V_131 -> V_132 ) {
if( V_131 -> V_133 ) {
V_131 = V_131 -> V_133 ;
continue;
} else {
break;
}
}
if( V_130 > V_131 -> V_132 ) {
if( V_131 -> V_134 ) {
V_131 = V_131 -> V_134 ;
continue;
} else {
break;
}
}
}
if( ! V_131 ) {
return NULL ;
}
if( ! V_131 -> V_135 ) {
if( V_130 > V_131 -> V_132 ) {
return V_131 -> V_122 ;
} else {
return NULL ;
}
}
if( V_131 -> V_135 -> V_133 == V_131 ) {
if( V_130 > V_131 -> V_132 ) {
return V_131 -> V_122 ;
} else {
while( V_131 ) {
if( V_130 > V_131 -> V_132 ) {
return V_131 -> V_122 ;
}
V_131 = V_131 -> V_135 ;
}
return NULL ;
}
} else {
if( V_131 -> V_132 < V_130 ) {
return V_131 -> V_122 ;
} else {
return V_131 -> V_135 -> V_122 ;
}
}
}
static inline T_16 *
F_80 ( T_16 * V_131 )
{
return V_131 -> V_135 ;
}
static inline T_16 *
F_81 ( T_16 * V_131 )
{
T_16 * V_135 ;
V_135 = F_80 ( V_131 ) ;
if( V_135 ) {
return V_135 -> V_135 ;
}
return NULL ;
}
static inline T_16 *
F_82 ( T_16 * V_131 )
{
T_16 * V_135 , * V_136 ;
V_135 = F_80 ( V_131 ) ;
if( ! V_135 ) {
return NULL ;
}
V_136 = F_80 ( V_135 ) ;
if( ! V_136 ) {
return NULL ;
}
if( V_135 == V_136 -> V_133 ) {
return V_136 -> V_134 ;
}
return V_136 -> V_133 ;
}
static inline void
F_83 ( T_13 * V_129 , T_16 * V_131 )
{
if( V_131 -> V_135 ) {
if( V_131 -> V_135 -> V_133 == V_131 ) {
V_131 -> V_135 -> V_133 = V_131 -> V_134 ;
} else {
V_131 -> V_135 -> V_134 = V_131 -> V_134 ;
}
} else {
V_129 -> V_119 = V_131 -> V_134 ;
}
V_131 -> V_134 -> V_135 = V_131 -> V_135 ;
V_131 -> V_135 = V_131 -> V_134 ;
V_131 -> V_134 = V_131 -> V_134 -> V_133 ;
if( V_131 -> V_134 ) {
V_131 -> V_134 -> V_135 = V_131 ;
}
V_131 -> V_135 -> V_133 = V_131 ;
}
static inline void
F_84 ( T_13 * V_129 , T_16 * V_131 )
{
if( V_131 -> V_135 ) {
if( V_131 -> V_135 -> V_133 == V_131 ) {
V_131 -> V_135 -> V_133 = V_131 -> V_133 ;
} else {
V_131 -> V_135 -> V_134 = V_131 -> V_133 ;
}
} else {
V_129 -> V_119 = V_131 -> V_133 ;
}
V_131 -> V_133 -> V_135 = V_131 -> V_135 ;
V_131 -> V_135 = V_131 -> V_133 ;
V_131 -> V_133 = V_131 -> V_133 -> V_134 ;
if( V_131 -> V_133 ) {
V_131 -> V_133 -> V_135 = V_131 ;
}
V_131 -> V_135 -> V_134 = V_131 ;
}
static inline void
F_85 ( T_13 * V_129 , T_16 * V_131 )
{
T_16 * V_136 ;
T_16 * V_135 ;
V_135 = F_80 ( V_131 ) ;
V_136 = F_80 ( V_135 ) ;
V_135 -> V_137 . V_138 = V_139 ;
V_136 -> V_137 . V_138 = V_140 ;
if( ( V_131 == V_135 -> V_133 ) && ( V_135 == V_136 -> V_133 ) ) {
F_84 ( V_129 , V_136 ) ;
} else {
F_83 ( V_129 , V_136 ) ;
}
}
static inline void
F_86 ( T_13 * V_129 , T_16 * V_131 )
{
T_16 * V_136 ;
T_16 * V_135 ;
V_135 = F_80 ( V_131 ) ;
V_136 = F_80 ( V_135 ) ;
if( ! V_136 ) {
return;
}
if( ( V_131 == V_135 -> V_134 ) && ( V_135 == V_136 -> V_133 ) ) {
F_83 ( V_129 , V_135 ) ;
V_131 = V_131 -> V_133 ;
} else if( ( V_131 == V_135 -> V_133 ) && ( V_135 == V_136 -> V_134 ) ) {
F_84 ( V_129 , V_135 ) ;
V_131 = V_131 -> V_134 ;
}
F_85 ( V_129 , V_131 ) ;
}
static inline void
F_87 ( T_13 * V_129 , T_16 * V_131 )
{
T_16 * V_136 ;
T_16 * V_135 ;
T_16 * V_141 ;
V_141 = F_82 ( V_131 ) ;
if( V_141 && ( V_141 -> V_137 . V_138 == V_140 ) ) {
V_135 = F_80 ( V_131 ) ;
V_135 -> V_137 . V_138 = V_139 ;
V_141 -> V_137 . V_138 = V_139 ;
V_136 = F_81 ( V_131 ) ;
V_136 -> V_137 . V_138 = V_140 ;
F_88 ( V_129 , V_136 ) ;
} else {
F_86 ( V_129 , V_131 ) ;
}
}
static inline void
F_89 ( T_13 * V_129 , T_16 * V_131 )
{
T_16 * V_135 ;
V_135 = F_80 ( V_131 ) ;
if( V_135 -> V_137 . V_138 == V_139 ) {
return;
}
F_87 ( V_129 , V_131 ) ;
}
static inline void
F_88 ( T_13 * V_129 , T_16 * V_131 )
{
T_16 * V_135 ;
V_135 = F_80 ( V_131 ) ;
if( ! V_135 ) {
V_131 -> V_137 . V_138 = V_139 ;
return;
}
F_89 ( V_129 , V_131 ) ;
}
void
F_90 ( T_13 * V_129 , T_15 V_130 , void * V_122 )
{
T_16 * V_131 ;
V_131 = V_129 -> V_119 ;
if( ! V_131 ) {
V_131 = ( T_16 * ) V_129 -> malloc ( sizeof( T_16 ) ) ;
switch( V_129 -> type ) {
case V_142 :
V_131 -> V_137 . V_138 = V_139 ;
break;
}
V_131 -> V_135 = NULL ;
V_131 -> V_133 = NULL ;
V_131 -> V_134 = NULL ;
V_131 -> V_132 = V_130 ;
V_131 -> V_122 = V_122 ;
V_131 -> V_137 . V_143 = V_144 ;
V_129 -> V_119 = V_131 ;
return;
}
while( 1 ) {
if( V_130 == V_131 -> V_132 ) {
V_131 -> V_122 = V_122 ;
return;
}
if( V_130 < V_131 -> V_132 ) {
if( ! V_131 -> V_133 ) {
T_16 * V_145 ;
V_145 = ( T_16 * ) V_129 -> malloc ( sizeof( T_16 ) ) ;
V_131 -> V_133 = V_145 ;
V_145 -> V_135 = V_131 ;
V_145 -> V_133 = NULL ;
V_145 -> V_134 = NULL ;
V_145 -> V_132 = V_130 ;
V_145 -> V_122 = V_122 ;
V_145 -> V_137 . V_143 = V_144 ;
V_131 = V_145 ;
break;
}
V_131 = V_131 -> V_133 ;
continue;
}
if( V_130 > V_131 -> V_132 ) {
if( ! V_131 -> V_134 ) {
T_16 * V_145 ;
V_145 = ( T_16 * ) V_129 -> malloc ( sizeof( T_16 ) ) ;
V_131 -> V_134 = V_145 ;
V_145 -> V_135 = V_131 ;
V_145 -> V_133 = NULL ;
V_145 -> V_134 = NULL ;
V_145 -> V_132 = V_130 ;
V_145 -> V_122 = V_122 ;
V_145 -> V_137 . V_143 = V_144 ;
V_131 = V_145 ;
break;
}
V_131 = V_131 -> V_134 ;
continue;
}
}
switch( V_129 -> type ) {
case V_142 :
V_131 -> V_137 . V_138 = V_140 ;
F_88 ( V_129 , V_131 ) ;
break;
}
}
static void *
F_91 ( T_13 * V_129 , T_15 V_130 , void * (* F_92)( void * ) , void * V_146 , int V_143 )
{
T_16 * V_131 ;
V_131 = V_129 -> V_119 ;
if( ! V_131 ) {
V_131 = ( T_16 * ) V_129 -> malloc ( sizeof( T_16 ) ) ;
switch( V_129 -> type ) {
case V_142 :
V_131 -> V_137 . V_138 = V_139 ;
break;
}
V_131 -> V_135 = NULL ;
V_131 -> V_133 = NULL ;
V_131 -> V_134 = NULL ;
V_131 -> V_132 = V_130 ;
V_131 -> V_122 = F_92 ( V_146 ) ;
V_131 -> V_137 . V_143 = V_143 ;
V_129 -> V_119 = V_131 ;
return V_131 -> V_122 ;
}
while( 1 ) {
if( V_130 == V_131 -> V_132 ) {
return V_131 -> V_122 ;
}
if( V_130 < V_131 -> V_132 ) {
if( ! V_131 -> V_133 ) {
T_16 * V_145 ;
V_145 = ( T_16 * ) V_129 -> malloc ( sizeof( T_16 ) ) ;
V_131 -> V_133 = V_145 ;
V_145 -> V_135 = V_131 ;
V_145 -> V_133 = NULL ;
V_145 -> V_134 = NULL ;
V_145 -> V_132 = V_130 ;
V_145 -> V_122 = F_92 ( V_146 ) ;
V_145 -> V_137 . V_143 = V_143 ;
V_131 = V_145 ;
break;
}
V_131 = V_131 -> V_133 ;
continue;
}
if( V_130 > V_131 -> V_132 ) {
if( ! V_131 -> V_134 ) {
T_16 * V_145 ;
V_145 = ( T_16 * ) V_129 -> malloc ( sizeof( T_16 ) ) ;
V_131 -> V_134 = V_145 ;
V_145 -> V_135 = V_131 ;
V_145 -> V_133 = NULL ;
V_145 -> V_134 = NULL ;
V_145 -> V_132 = V_130 ;
V_145 -> V_122 = F_92 ( V_146 ) ;
V_145 -> V_137 . V_143 = V_143 ;
V_131 = V_145 ;
break;
}
V_131 = V_131 -> V_134 ;
continue;
}
}
switch( V_129 -> type ) {
case V_142 :
V_131 -> V_137 . V_138 = V_140 ;
F_88 ( V_129 , V_131 ) ;
break;
}
return V_131 -> V_122 ;
}
static T_13 *
F_93 ( T_13 * V_147 , const char * V_128 )
{
T_13 * V_118 ;
V_118 = ( T_13 * ) V_147 -> malloc ( sizeof( T_13 ) ) ;
V_118 -> V_19 = NULL ;
V_118 -> type = V_147 -> type ;
V_118 -> V_119 = NULL ;
V_118 -> V_128 = V_128 ;
V_118 -> malloc = V_147 -> malloc ;
return V_118 ;
}
static void *
F_94 ( void * V_148 )
{
T_13 * V_129 = ( T_13 * ) V_148 ;
return F_93 ( V_129 , L_57 ) ;
}
void
F_95 ( T_13 * V_129 , T_17 * V_130 , void * V_122 )
{
T_13 * V_149 = NULL ;
T_17 * V_150 ;
T_15 V_2 , V_151 = 0 ;
if( ! V_129 || ! V_130 ) return;
for ( V_150 = V_130 ; V_150 -> V_152 > 0 ; V_150 ++ ) {
if( V_150 -> V_152 > 100 ) {
F_96 () ;
}
for ( V_2 = 0 ; V_2 < V_150 -> V_152 ; V_2 ++ ) {
if ( ! V_149 ) {
V_149 = V_129 ;
} else {
V_149 = ( T_13 * ) F_91 ( V_149 , V_151 , F_94 , V_129 , V_153 ) ;
}
V_151 = V_150 -> V_130 [ V_2 ] ;
}
}
if( ! V_149 ) {
F_96 () ;
}
F_90 ( V_149 , V_151 , V_122 ) ;
}
void *
F_97 ( T_13 * V_129 , T_17 * V_130 )
{
T_13 * V_154 = NULL ;
T_17 * V_150 ;
T_15 V_2 , V_155 = 0 ;
if( ! V_129 || ! V_130 ) return NULL ;
for ( V_150 = V_130 ; V_150 -> V_152 > 0 ; V_150 ++ ) {
if( V_150 -> V_152 > 100 ) {
F_96 () ;
}
for ( V_2 = 0 ; V_2 < V_150 -> V_152 ; V_2 ++ ) {
if ( ! V_154 ) {
V_154 = V_129 ;
} else {
V_154 = ( T_13 * ) F_78 ( V_154 , V_155 ) ;
if ( ! V_154 ) {
return NULL ;
}
}
V_155 = V_150 -> V_130 [ V_2 ] ;
}
}
if( ! V_154 ) {
F_96 () ;
}
return F_78 ( V_154 , V_155 ) ;
}
void *
F_98 ( T_13 * V_129 , T_17 * V_130 )
{
T_13 * V_154 = NULL ;
T_17 * V_150 ;
T_15 V_2 , V_155 = 0 ;
if( ! V_129 || ! V_130 ) return NULL ;
for ( V_150 = V_130 ; V_150 -> V_152 > 0 ; V_150 ++ ) {
if( V_150 -> V_152 > 100 ) {
F_96 () ;
}
for ( V_2 = 0 ; V_2 < V_150 -> V_152 ; V_2 ++ ) {
if ( ! V_154 ) {
V_154 = V_129 ;
} else {
V_154 = ( T_13 * ) F_79 ( V_154 , V_155 ) ;
if ( ! V_154 ) {
return NULL ;
}
}
V_155 = V_150 -> V_130 [ V_2 ] ;
}
}
if( ! V_154 ) {
F_96 () ;
}
return F_79 ( V_154 , V_155 ) ;
}
void
F_99 ( T_13 * V_129 , const T_5 * V_156 , void * V_157 , T_15 V_158 )
{
T_17 V_130 [ 2 ] ;
T_15 * V_159 = NULL ;
T_15 V_6 = ( T_15 ) strlen ( V_156 ) ;
T_15 V_160 = ( V_6 + 3 ) / 4 + 1 ;
T_15 V_2 ;
T_15 V_161 ;
V_159 = ( T_15 * ) F_38 ( V_160 * sizeof ( T_15 ) ) ;
V_161 = 0 ;
for ( V_2 = 0 ; V_2 < V_6 ; V_2 ++ ) {
unsigned char V_162 ;
V_162 = ( unsigned char ) V_156 [ V_2 ] ;
if ( V_158 & V_163 ) {
if( isupper ( V_162 ) ) {
V_162 = tolower ( V_162 ) ;
}
}
V_161 <<= 8 ;
V_161 |= V_162 ;
if ( V_2 % 4 == 3 ) {
V_159 [ V_2 / 4 ] = V_161 ;
V_161 = 0 ;
}
}
if ( V_2 % 4 != 0 ) {
while ( V_2 % 4 != 0 ) {
V_2 ++ ;
V_161 <<= 8 ;
}
V_159 [ V_2 / 4 - 1 ] = V_161 ;
}
V_159 [ V_160 - 1 ] = 0x00000001 ;
V_130 [ 0 ] . V_152 = V_160 ;
V_130 [ 0 ] . V_130 = V_159 ;
V_130 [ 1 ] . V_152 = 0 ;
V_130 [ 1 ] . V_130 = NULL ;
F_95 ( V_129 , V_130 , V_157 ) ;
F_35 ( V_159 ) ;
}
void *
F_100 ( T_13 * V_129 , const T_5 * V_156 , T_15 V_158 )
{
T_17 V_130 [ 2 ] ;
T_15 * V_159 = NULL ;
T_15 V_6 = ( T_10 ) strlen ( V_156 ) ;
T_15 V_160 = ( V_6 + 3 ) / 4 + 1 ;
T_15 V_2 ;
T_15 V_161 ;
void * V_83 ;
V_159 = ( T_15 * ) F_38 ( V_160 * sizeof ( T_15 ) ) ;
V_161 = 0 ;
for ( V_2 = 0 ; V_2 < V_6 ; V_2 ++ ) {
unsigned char V_162 ;
V_162 = ( unsigned char ) V_156 [ V_2 ] ;
if ( V_158 & V_163 ) {
if( isupper ( V_162 ) ) {
V_162 = tolower ( V_162 ) ;
}
}
V_161 <<= 8 ;
V_161 |= V_162 ;
if ( V_2 % 4 == 3 ) {
V_159 [ V_2 / 4 ] = V_161 ;
V_161 = 0 ;
}
}
if ( V_2 % 4 != 0 ) {
while ( V_2 % 4 != 0 ) {
V_2 ++ ;
V_161 <<= 8 ;
}
V_159 [ V_2 / 4 - 1 ] = V_161 ;
}
V_159 [ V_160 - 1 ] = 0x00000001 ;
V_130 [ 0 ] . V_152 = V_160 ;
V_130 [ 0 ] . V_130 = V_159 ;
V_130 [ 1 ] . V_152 = 0 ;
V_130 [ 1 ] . V_130 = NULL ;
V_83 = F_97 ( V_129 , V_130 ) ;
F_35 ( V_159 ) ;
return V_83 ;
}
static T_11
F_101 ( T_16 * V_131 , T_18 V_164 , void * V_165 )
{
T_11 V_166 = FALSE ;
if ( ! V_131 )
return FALSE ;
if( V_131 -> V_133 ) {
V_166 = F_101 ( V_131 -> V_133 , V_164 , V_165 ) ;
if ( V_166 ) {
return TRUE ;
}
}
if ( V_131 -> V_137 . V_143 == V_153 ) {
V_166 = F_102 ( ( T_13 * ) V_131 -> V_122 , V_164 , V_165 ) ;
} else {
V_166 = V_164 ( V_131 -> V_122 , V_165 ) ;
}
if ( V_166 ) {
return TRUE ;
}
if( V_131 -> V_134 ) {
V_166 = F_101 ( V_131 -> V_134 , V_164 , V_165 ) ;
if ( V_166 ) {
return TRUE ;
}
}
return FALSE ;
}
T_11
F_102 ( T_13 * V_167 , T_18 V_164 , void * V_165 )
{
if ( ! V_167 )
return FALSE ;
if( ! V_167 -> V_119 )
return FALSE ;
return F_101 ( V_167 -> V_119 , V_164 , V_165 ) ;
}
static void
F_103 ( const char * V_168 , T_16 * V_131 , T_15 V_169 )
{
T_15 V_2 ;
if ( ! V_131 )
return;
for( V_2 = 0 ; V_2 < V_169 ; V_2 ++ ) {
printf ( L_58 ) ;
}
printf ( L_59 , V_168 ,
( void * ) V_131 , ( void * ) ( V_131 -> V_135 ) , ( void * ) ( V_131 -> V_133 ) , ( void * ) ( V_131 -> V_134 ) ,
( V_131 -> V_137 . V_138 ) ? L_60 : L_61 , ( V_131 -> V_132 ) , ( V_131 -> V_137 . V_143 ) ? L_62 : L_63 , V_131 -> V_122 ) ;
if( V_131 -> V_133 )
F_103 ( L_64 , V_131 -> V_133 , V_169 + 1 ) ;
if( V_131 -> V_134 )
F_103 ( L_65 , V_131 -> V_134 , V_169 + 1 ) ;
if ( V_131 -> V_137 . V_143 )
F_104 ( ( T_13 * ) V_131 -> V_122 , V_169 + 1 ) ;
}
static void
F_104 ( T_13 * V_167 , T_15 V_169 )
{
T_15 V_2 ;
if ( ! V_167 )
return;
for( V_2 = 0 ; V_2 < V_169 ; V_2 ++ ) {
printf ( L_58 ) ;
}
printf ( L_66 , ( void * ) V_167 , ( V_167 -> type == 1 ) ? L_67 : L_68 , V_167 -> V_128 , ( void * ) ( V_167 -> V_119 ) ) ;
if( V_167 -> V_119 )
F_103 ( L_69 , V_167 -> V_119 , V_169 ) ;
}
void
F_105 ( T_13 * V_167 )
{
F_104 ( V_167 , 0 ) ;
}
static T_8
F_106 ( T_8 V_170 , T_8 V_171 , T_8 V_172 )
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
F_107 ( T_19 * V_175 , T_8 V_171 )
{
T_8 V_176 ;
T_5 * V_177 ;
if ( ! V_175 || ( V_171 <= V_175 -> V_178 ) || ( V_175 -> V_178 >= V_175 -> V_172 ) ) {
return;
}
V_176 = F_106 ( V_175 -> V_178 , V_171 , V_175 -> V_172 ) ;
V_177 = ( T_5 * ) F_45 ( V_176 ) ;
F_9 ( V_177 , V_175 -> V_179 , V_176 ) ;
V_175 -> V_178 = V_176 ;
V_175 -> V_179 = V_177 ;
}
T_19 *
F_108 ( T_8 V_178 , T_8 V_172 )
{
T_19 * V_175 ;
V_175 = F_73 ( T_19 ) ;
if ( ( V_172 == 0 ) || ( V_172 > V_173 ) )
V_172 = V_173 ;
if ( V_178 == 0 )
V_178 = 1 ;
else if ( V_178 > V_172 )
V_178 = V_172 ;
V_175 -> V_179 = ( char * ) F_45 ( V_178 ) ;
V_175 -> V_179 [ 0 ] = '\0' ;
V_175 -> V_6 = 0 ;
V_175 -> V_178 = V_178 ;
V_175 -> V_172 = V_172 ;
return V_175 ;
}
T_19 *
F_109 ( const T_5 * V_180 )
{
T_19 * V_175 ;
V_175 = F_108 ( F_106 ( 0 , V_180 ? strlen ( V_180 ) + 1 : 0 , 0 ) , 0 ) ;
if ( V_180 ) {
T_8 V_181 ;
V_181 = F_9 ( V_175 -> V_179 , V_180 , V_175 -> V_178 ) ;
V_175 -> V_6 = F_110 ( V_181 , V_175 -> V_178 - 1 ) ;
}
return V_175 ;
}
T_19 *
F_111 ( const T_5 * V_180 )
{
T_19 * V_175 ;
T_8 V_181 ;
V_175 = F_108 ( V_174 , V_182 ) ;
if ( ! V_180 )
return V_175 ;
V_181 = F_9 ( V_175 -> V_179 , V_180 , V_175 -> V_178 ) ;
if ( V_181 < V_175 -> V_178 ) {
V_175 -> V_6 += V_181 ;
} else {
V_175 = F_108 ( V_181 + 1 , V_182 ) ;
V_181 = F_9 ( V_175 -> V_179 , V_180 , V_175 -> V_178 ) ;
V_175 -> V_6 = F_110 ( V_181 , V_175 -> V_178 - 1 ) ;
}
return V_175 ;
}
T_19 *
F_112 ( T_19 * V_175 , const T_5 * V_179 )
{
T_8 V_183 , V_181 ;
if ( ! V_175 || ! V_179 || V_179 [ 0 ] == '\0' ) {
return V_175 ;
}
V_183 = V_175 -> V_178 - V_175 -> V_6 ;
V_181 = F_9 ( & V_175 -> V_179 [ V_175 -> V_6 ] , V_179 , V_183 ) ;
if ( V_181 < V_183 ) {
V_175 -> V_6 += V_181 ;
} else {
V_175 -> V_179 [ V_175 -> V_6 ] = '\0' ;
F_107 ( V_175 , V_175 -> V_6 + V_181 + 1 ) ;
V_183 = V_175 -> V_178 - V_175 -> V_6 ;
V_181 = F_9 ( & V_175 -> V_179 [ V_175 -> V_6 ] , V_179 , V_183 ) ;
V_175 -> V_6 += F_110 ( V_183 - 1 , V_181 ) ;
}
return V_175 ;
}
void
F_113 ( T_19 * V_175 , const T_5 * V_184 , T_4 V_12 )
{
T_4 V_98 ;
T_8 V_183 , V_181 ;
F_59 ( V_98 , V_12 ) ;
V_183 = V_175 -> V_178 - V_175 -> V_6 ;
V_181 = F_7 ( & V_175 -> V_179 [ V_175 -> V_6 ] , ( V_99 ) V_183 , V_184 , V_12 ) ;
if ( V_181 < V_183 ) {
V_175 -> V_6 += V_181 ;
} else {
V_175 -> V_179 [ V_175 -> V_6 ] = '\0' ;
F_107 ( V_175 , V_175 -> V_6 + V_181 + 1 ) ;
V_183 = V_175 -> V_178 - V_175 -> V_6 ;
V_181 = F_7 ( & V_175 -> V_179 [ V_175 -> V_6 ] , ( V_99 ) V_183 , V_184 , V_98 ) ;
V_175 -> V_6 += F_110 ( V_183 - 1 , V_181 ) ;
}
va_end ( V_98 ) ;
}
void
F_114 ( T_19 * V_175 , const T_5 * V_184 , ... )
{
T_4 V_12 ;
va_start ( V_12 , V_184 ) ;
F_113 ( V_175 , V_184 , V_12 ) ;
va_end ( V_12 ) ;
}
void
F_115 ( T_19 * V_175 , const T_5 * V_184 , ... )
{
T_4 V_12 ;
if ( ! V_175 ) {
return;
}
V_175 -> V_6 = 0 ;
va_start ( V_12 , V_184 ) ;
F_113 ( V_175 , V_184 , V_12 ) ;
va_end ( V_12 ) ;
}
T_19 *
F_116 ( T_19 * V_175 , const T_5 V_185 )
{
if ( ! V_175 ) {
return V_175 ;
}
if ( V_175 -> V_178 < V_175 -> V_6 + 1 + 1 ) {
F_107 ( V_175 , V_175 -> V_6 + 1 + 1 ) ;
}
if ( V_175 -> V_178 >= V_175 -> V_6 + 1 + 1 ) {
V_175 -> V_179 [ V_175 -> V_6 ] = V_185 ;
V_175 -> V_6 ++ ;
V_175 -> V_179 [ V_175 -> V_6 ] = '\0' ;
}
return V_175 ;
}
T_19 *
F_117 ( T_19 * V_175 , const T_20 V_185 )
{
T_5 V_66 [ 6 ] ;
T_21 V_186 ;
if ( ! V_175 ) {
return V_175 ;
}
V_186 = F_118 ( V_185 , V_66 ) ;
if ( V_175 -> V_178 < V_175 -> V_6 + V_186 + 1 ) {
F_107 ( V_175 , V_175 -> V_6 + V_186 + 1 ) ;
}
if ( V_175 -> V_178 >= V_175 -> V_6 + V_186 + 1 ) {
memcpy ( & V_175 -> V_179 [ V_175 -> V_6 ] , V_66 , V_186 ) ;
V_175 -> V_6 += V_186 ;
V_175 -> V_179 [ V_175 -> V_6 ] = '\0' ;
}
return V_175 ;
}
T_19 *
F_119 ( T_19 * V_175 , T_8 V_6 )
{
if ( ! V_175 || V_6 >= V_175 -> V_6 ) {
return V_175 ;
}
V_175 -> V_179 [ V_6 ] = '\0' ;
V_175 -> V_6 = V_6 ;
return V_175 ;
}
