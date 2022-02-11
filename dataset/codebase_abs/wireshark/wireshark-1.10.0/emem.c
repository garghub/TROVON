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
if ( V_35 == - 1 )
fprintf ( V_42 , L_10 ) ;
#ifdef F_19
V_43 = F_20 ( L_11 , V_44 ) ;
F_21 ( V_43 != - 1 ) ;
#endif
#endif
}
static void
F_22 ()
{
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
fprintf ( V_42 , L_12 ) ;
fprintf ( V_42 , L_13 ,
V_17 . V_24 ? L_14 : L_15 ,
V_17 . V_23 ? L_16 : L_17 ,
V_32 ? L_16 : L_17 ) ;
if ( ! ( V_17 . V_18 || ! V_17 . V_28 ) ) {
fprintf ( V_42 , L_18 ) ;
V_54 = FALSE ;
}
if ( V_17 . V_24 && V_54 ) {
for ( V_51 = V_17 . V_28 ; V_51 ; V_51 = V_51 -> V_19 ) {
V_45 ++ ;
V_47 += ( V_51 -> V_55 - V_51 -> V_56 ) ;
V_48 += V_51 -> V_55 ;
}
if ( V_45 > 0 ) {
fprintf ( V_42 , L_19 ) ;
fprintf ( V_42 , L_20 ) ;
fprintf ( V_42 , L_21 , V_57 ) ;
fprintf ( V_42 , L_22 , V_45 ) ;
fprintf ( V_42 , L_23 ) ;
fprintf ( V_42 , L_24 ,
V_48 , V_57 * V_45 ) ;
fprintf ( V_42 , L_23 ) ;
V_52 = V_48
+ sizeof( T_6 ) * V_45 ;
fprintf ( V_42 , L_25 ,
V_52 ) ;
} else{
fprintf ( V_42 , L_26 ) ;
}
V_45 = 0 ;
V_46 = 0 ;
V_47 = 0 ;
V_48 = 0 ;
V_49 = 0 ;
}
fprintf ( V_42 , L_27 ) ;
fprintf ( V_42 , L_28 ,
V_58 ) ;
fprintf ( V_42 , L_29 ,
V_31 . V_24 ? L_14 : L_15 ,
V_31 . V_23 ? L_16 : L_17 ) ;
if ( ! ( V_31 . V_18 || ! V_31 . V_28 ) ) {
fprintf ( V_42 , L_18 ) ;
return;
}
if ( ! V_31 . V_24 )
return;
for ( V_51 = V_31 . V_28 ; V_51 ; V_51 = V_51 -> V_19 ) {
V_45 ++ ;
V_47 += ( V_51 -> V_55 - V_51 -> V_56 ) ;
V_48 += V_51 -> V_55 ;
if ( V_31 . V_23 ) {
void * V_7 = V_51 -> V_21 ;
int V_6 ;
while ( V_7 != NULL ) {
V_7 = F_4 ( V_31 . V_1 , V_7 , & V_6 ) ;
if ( V_7 == ( void * ) - 1 )
F_8 ( L_30 ) ;
V_49 += V_6 ;
}
}
}
if ( V_45 == 0 ) {
fprintf ( V_42 , L_26 ) ;
return;
}
fprintf ( V_42 , L_19 ) ;
fprintf ( V_42 , L_31 ) ;
fprintf ( V_42 , L_32 ) ;
fprintf ( V_42 , L_33 ,
sizeof( T_6 ) ) ;
fprintf ( V_42 , L_34 , V_45 ) ;
fprintf ( V_42 , L_23 ) ;
V_50 = sizeof( T_6 ) * V_45 ;
fprintf ( V_42 , L_35 , V_50 ) ;
fprintf ( V_42 , L_20 ) ;
fprintf ( V_42 , L_21 ,
V_57 ) ;
fprintf ( V_42 , L_22 , V_45 ) ;
fprintf ( V_42 , L_23 ) ;
fprintf ( V_42 , L_36 ,
V_48 , V_57 * V_45 ) ;
fprintf ( V_42 , L_23 ) ;
V_52 = ( V_57 * V_45 )
+ V_50 ;
fprintf ( V_42 , L_37 ,
V_52 ) ;
for ( V_2 = 0 ; V_2 < V_59 ; V_2 ++ )
V_46 += V_60 [ V_2 ] ;
fprintf ( V_42 , L_38 ) ;
fprintf ( V_42 , L_39 ,
V_46 ) ;
fprintf ( V_42 , L_40 ,
V_47 ) ;
fprintf ( V_42 , L_41 ,
V_49 ) ;
fprintf ( V_42 , L_42 ,
V_48 - V_47 ) ;
fprintf ( V_42 , L_43 ,
V_52 - V_47 ) ;
fprintf ( V_42 , L_44 ) ;
fprintf ( V_42 , L_45 ,
( float ) V_47 / ( float ) V_46 ) ;
fprintf ( V_42 , L_46 ,
( float ) ( V_47 - V_49 ) / ( float ) V_46 ) ;
fprintf ( V_42 , L_47 ,
( V_48 - V_47 ) / ( float ) V_46 ) ;
V_53 = ( V_48 - V_47 )
+ ( sizeof( T_6 ) ) ;
fprintf ( V_42 , L_48 ,
V_53 ) ;
fprintf ( V_42 , L_49 ,
100 * ( float ) V_53 / ( float ) V_52 ) ;
fprintf ( V_42 , L_50 ) ;
for ( V_2 = 0 ; V_2 < ( V_59 - 1 ) ; V_2 ++ )
fprintf ( V_42 , L_51 , 32 << V_2 , V_60 [ V_2 ] ) ;
fprintf ( V_42 , L_52 , 32 << V_2 , V_60 [ V_2 ] ) ;
}
static T_9
F_23 ( const T_6 * V_61 , const void * V_7 )
{
const T_5 * V_62 = ( T_5 * ) V_7 ;
const T_6 * V_51 ;
for ( V_51 = V_61 ; V_51 ; V_51 = V_51 -> V_19 ) {
if ( V_62 >= ( V_51 -> V_63 + V_51 -> V_64 ) && V_62 < ( V_51 -> V_63 + V_51 -> V_65 ) )
return TRUE ;
}
return FALSE ;
}
static T_9
F_24 ( const T_7 * V_66 , const void * V_7 )
{
return F_23 ( V_66 -> V_18 , V_7 ) || F_23 ( V_66 -> V_28 , V_7 ) ;
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
F_27 ( char * V_63 , T_3 V_67 , T_9 V_68 )
{
T_8 V_69 ;
T_3 V_70 ;
if ( ! V_32 )
return;
if ( V_68 )
V_69 = 0xBADDCAFE ;
else
V_69 = 0xDEADBEEF ;
for ( V_70 = 0 ; V_70 + sizeof( T_8 ) <= V_67 ; V_70 += sizeof( T_8 ) )
* ( T_8 * ) ( void * ) ( V_63 + V_70 ) = V_69 ;
if ( V_70 < V_67 ) {
* ( T_1 * ) ( V_63 + V_70 ) = V_69 >> 24 ;
V_70 ++ ;
if ( V_70 < V_67 ) {
* ( T_1 * ) ( V_63 + V_70 ) = ( V_69 >> 16 ) & 0xFF ;
V_70 ++ ;
if ( V_70 < V_67 ) {
* ( T_1 * ) ( V_63 + V_70 ) = ( V_69 >> 8 ) & 0xFF ;
}
}
}
}
static T_6 *
F_28 ( T_3 V_67 )
{
T_6 * V_15 ;
V_15 = F_29 ( T_6 , 1 ) ;
V_15 -> V_19 = NULL ;
V_15 -> V_21 = NULL ;
#if F_15 ( V_33 )
V_15 -> V_63 = ( char * ) F_30 ( NULL , V_67 ,
V_71 | V_72 , V_73 ) ;
if ( V_15 -> V_63 == NULL ) {
F_31 ( V_15 ) ;
if ( getenv ( L_53 ) )
abort () ;
else
F_32 ( V_74 ) ;
}
#elif F_15 ( V_40 )
V_15 -> V_63 = ( char * ) F_33 ( NULL , V_67 ,
V_75 | V_76 , V_77 , V_78 , 0 ) ;
if ( V_15 -> V_63 == V_79 ) {
F_31 ( V_15 ) ;
if ( getenv ( L_53 ) )
abort () ;
else
F_32 ( V_74 ) ;
}
#else
V_15 -> V_63 = F_34 ( V_67 ) ;
#endif
#ifdef F_35
V_58 ++ ;
#endif
V_15 -> V_56 = V_15 -> V_55 = ( unsigned int ) V_67 ;
V_15 -> V_65 = V_15 -> V_64 = 0 ;
return V_15 ;
}
static T_6 *
F_36 ( T_3 V_67 )
{
#if F_15 ( V_33 )
BOOL V_80 ;
char * V_81 , * V_82 , * V_83 ;
T_10 V_84 ;
#elif F_15 ( V_40 )
int V_80 ;
char * V_81 , * V_82 , * V_83 ;
#endif
T_6 * V_15 ;
V_15 = F_28 ( V_67 ) ;
#if F_15 ( V_33 )
V_81 = V_15 -> V_63 + V_67 ;
V_82 = ( char * ) ( ( ( ( V_85 ) V_15 -> V_63 + V_35 - 1 ) / V_35 ) * V_35 ) ;
V_83 = ( char * ) ( ( ( ( V_85 ) V_81 - ( 1 * V_35 ) ) / V_35 ) * V_35 ) ;
V_80 = F_37 ( V_82 , V_35 , V_86 , & V_84 ) ;
F_21 ( V_80 != 0 || V_37 . V_87 == V_88 ) ;
V_80 = F_37 ( V_83 , V_35 , V_86 , & V_84 ) ;
F_21 ( V_80 != 0 || V_37 . V_87 == V_88 ) ;
V_15 -> V_55 = ( unsigned int ) ( V_83 - V_82 - V_35 ) ;
V_15 -> V_64 = ( unsigned int ) ( V_82 - V_15 -> V_63 ) + V_35 ;
#elif F_15 ( V_40 )
V_81 = V_15 -> V_63 + V_67 ;
V_82 = ( char * ) ( ( ( ( V_85 ) V_15 -> V_63 + V_35 - 1 ) / V_35 ) * V_35 ) ;
V_83 = ( char * ) ( ( ( ( V_85 ) V_81 - ( 1 * V_35 ) ) / V_35 ) * V_35 ) ;
V_80 = F_38 ( V_82 , V_35 , V_89 ) ;
F_21 ( V_80 != - 1 ) ;
V_80 = F_38 ( V_83 , V_35 , V_89 ) ;
F_21 ( V_80 != - 1 ) ;
V_15 -> V_55 = ( unsigned int ) ( V_83 - V_82 - V_35 ) ;
V_15 -> V_64 = ( unsigned int ) ( ( V_82 - V_15 -> V_63 ) + V_35 ) ;
#else
V_15 -> V_55 = V_67 ;
V_15 -> V_64 = 0 ;
#endif
V_15 -> V_56 = V_15 -> V_55 ;
V_15 -> V_65 = V_15 -> V_64 ;
return V_15 ;
}
static void *
V_26 ( T_3 V_67 , T_7 * V_22 )
{
void * V_63 ;
T_3 V_90 = V_67 ;
T_9 V_91 = V_22 -> V_23 ;
T_1 V_10 ;
T_6 * V_18 ;
if ( V_91 ) {
V_90 += sizeof( void * ) ;
V_10 = F_5 ( V_90 ) ;
} else
V_10 = ( V_92 - ( V_90 & ( V_92 - 1 ) ) ) & ( V_92 - 1 ) ;
V_90 += V_10 ;
#ifdef F_35
if ( V_22 == & V_31 ) {
if ( V_90 < 32 )
V_60 [ 0 ] ++ ;
else if ( V_90 < 64 )
V_60 [ 1 ] ++ ;
else if ( V_90 < 128 )
V_60 [ 2 ] ++ ;
else if ( V_90 < 256 )
V_60 [ 3 ] ++ ;
else if ( V_90 < 512 )
V_60 [ 4 ] ++ ;
else if ( V_90 < 1024 )
V_60 [ 5 ] ++ ;
else if ( V_90 < 2048 )
V_60 [ 6 ] ++ ;
else if ( V_90 < 4096 )
V_60 [ 7 ] ++ ;
else if ( V_90 < 8192 )
V_60 [ 8 ] ++ ;
else if ( V_90 < 16384 )
V_60 [ 8 ] ++ ;
else
V_60 [ ( V_59 - 1 ) ] ++ ;
}
#endif
F_39 ( V_67 < ( V_57 >> 2 ) ) ;
if ( ! V_22 -> V_18 )
V_22 -> V_18 = F_36 ( V_57 ) ;
if( V_90 > V_22 -> V_18 -> V_56 ) {
T_6 * V_15 ;
V_15 = V_22 -> V_18 ;
V_22 -> V_18 = V_22 -> V_18 -> V_19 ;
V_15 -> V_19 = V_22 -> V_28 ;
V_22 -> V_28 = V_15 ;
if ( ! V_22 -> V_18 )
V_22 -> V_18 = F_36 ( V_57 ) ;
}
V_18 = V_22 -> V_18 ;
V_63 = V_18 -> V_63 + V_18 -> V_65 ;
V_18 -> V_56 -= ( unsigned int ) V_90 ;
V_18 -> V_65 += ( unsigned int ) V_90 ;
if ( V_91 ) {
char * V_62 = ( char * ) V_63 + V_67 ;
memcpy ( V_62 , V_22 -> V_1 , V_10 - 1 ) ;
V_62 [ V_10 - 1 ] = '\0' ;
memcpy ( V_62 + V_10 , & V_18 -> V_21 , sizeof( void * ) ) ;
V_18 -> V_21 = V_62 ;
}
return V_63 ;
}
static void *
V_27 ( T_3 V_67 , T_7 * V_22 )
{
T_6 * V_15 ;
V_15 = F_29 ( T_6 , 1 ) ;
V_15 -> V_19 = V_22 -> V_28 ;
V_15 -> V_63 = ( char * ) F_34 ( V_67 ) ;
V_15 -> V_21 = NULL ;
V_22 -> V_28 = V_15 ;
V_15 -> V_56 = V_15 -> V_64 = 0 ;
V_15 -> V_65 = V_15 -> V_55 = ( unsigned int ) V_67 ;
return V_15 -> V_63 ;
}
static void *
F_40 ( T_3 V_67 , T_7 * V_22 )
{
void * V_63 ;
#if 0
if (mem == &ep_packet_mem) {
return wmem_alloc(wmem_packet_scope(), size);
}
else if (mem == &se_packet_mem) {
return wmem_alloc(wmem_file_scope(), size);
}
#endif
V_63 = V_22 -> V_25 ( V_67 , V_22 ) ;
F_27 ( ( char * ) V_63 , V_67 , TRUE ) ;
return V_63 ;
}
void *
F_41 ( T_3 V_67 )
{
return F_40 ( V_67 , & V_17 ) ;
}
void *
F_42 ( T_3 V_67 )
{
return F_40 ( V_67 , & V_31 ) ;
}
void *
F_43 ( T_3 V_67 )
{
return memset ( F_41 ( V_67 ) , '\0' , V_67 ) ;
}
void *
F_44 ( T_3 V_67 )
{
return memset ( F_42 ( V_67 ) , '\0' , V_67 ) ;
}
static T_5 *
F_45 ( const T_5 * V_93 , void * F_46 ( T_3 ) )
{
T_8 V_6 ;
T_5 * V_94 ;
if( ! V_93 )
V_93 = L_54 ;
V_6 = ( T_8 ) strlen ( V_93 ) ;
V_94 = ( T_5 * ) memcpy ( F_46 ( V_6 + 1 ) , V_93 , V_6 + 1 ) ;
return V_94 ;
}
T_5 *
F_47 ( const T_5 * V_93 )
{
return F_45 ( V_93 , F_41 ) ;
}
T_5 *
F_48 ( const T_5 * V_93 )
{
return F_45 ( V_93 , F_42 ) ;
}
static T_5 *
F_49 ( const T_5 * V_93 , T_3 V_6 , void * F_46 ( T_3 ) )
{
T_5 * V_94 = ( T_5 * ) F_46 ( V_6 + 1 ) ;
T_8 V_2 ;
for ( V_2 = 0 ; ( V_2 < V_6 ) && V_93 [ V_2 ] ; V_2 ++ )
V_94 [ V_2 ] = V_93 [ V_2 ] ;
V_94 [ V_2 ] = '\0' ;
return V_94 ;
}
T_5 *
F_50 ( const T_5 * V_93 , T_3 V_6 )
{
return F_49 ( V_93 , V_6 , F_41 ) ;
}
T_5 *
F_51 ( const T_5 * V_93 , T_3 V_6 )
{
return F_49 ( V_93 , V_6 , F_42 ) ;
}
void *
F_52 ( const void * V_93 , T_3 V_6 )
{
return memcpy ( F_41 ( V_6 ) , V_93 , V_6 ) ;
}
void *
F_53 ( const void * V_93 , T_3 V_6 )
{
return memcpy ( F_42 ( V_6 ) , V_93 , V_6 ) ;
}
static T_5 *
F_54 ( const T_5 * V_11 , T_4 V_12 , void * F_46 ( T_3 ) )
{
T_4 V_95 ;
T_11 V_6 ;
T_5 * V_94 ;
F_55 ( V_95 , V_12 ) ;
V_6 = F_56 ( V_11 , V_12 ) ;
V_94 = ( T_5 * ) F_46 ( V_6 + 1 ) ;
F_7 ( V_94 , ( V_96 ) V_6 , V_11 , V_95 ) ;
va_end ( V_95 ) ;
return V_94 ;
}
T_5 *
F_57 ( const T_5 * V_11 , T_4 V_12 )
{
return F_54 ( V_11 , V_12 , F_41 ) ;
}
T_5 *
F_58 ( const T_5 * V_11 , T_4 V_12 )
{
return F_54 ( V_11 , V_12 , F_42 ) ;
}
T_5 *
F_59 ( const T_5 * V_11 , ... )
{
T_4 V_12 ;
T_5 * V_94 ;
va_start ( V_12 , V_11 ) ;
V_94 = F_57 ( V_11 , V_12 ) ;
va_end ( V_12 ) ;
return V_94 ;
}
T_5 *
F_60 ( const T_5 * V_11 , ... )
{
T_4 V_12 ;
T_5 * V_94 ;
va_start ( V_12 , V_11 ) ;
V_94 = F_58 ( V_11 , V_12 ) ;
va_end ( V_12 ) ;
return V_94 ;
}
T_5 * *
F_61 ( const T_5 * string , const T_5 * V_97 , int V_98 )
{
T_5 * V_99 ;
T_5 * V_100 ;
T_8 V_101 ;
T_8 V_102 ;
T_8 V_103 ;
T_8 V_2 ;
T_5 * * V_104 ;
enum { V_105 , V_106 , V_107 } V_108 ;
T_8 V_109 = 0 ;
if ( ! string
|| ! V_97
|| ! V_97 [ 0 ] )
return NULL ;
V_100 = V_99 = F_47 ( string ) ;
V_102 = ( T_8 ) strlen ( V_99 ) ;
V_103 = ( T_8 ) strlen ( V_97 ) ;
if ( V_98 < 1 ) V_98 = V_110 ;
V_101 = 1 ;
while ( V_101 <= ( T_8 ) V_98 && ( V_100 = strstr ( V_100 , V_97 ) ) ) {
V_101 ++ ;
for( V_2 = 0 ; V_2 < V_103 ; V_2 ++ )
V_100 [ V_2 ] = '\0' ;
V_100 += V_103 ;
}
V_104 = F_62 ( T_5 * , V_101 + 1 ) ;
V_108 = V_105 ;
for ( V_2 = 0 ; V_2 < V_102 ; V_2 ++ ) {
switch( V_108 ) {
case V_105 :
switch( V_99 [ V_2 ] ) {
case '\0' :
V_108 = V_106 ;
continue;
default:
V_104 [ V_109 ] = & ( V_99 [ V_2 ] ) ;
V_109 ++ ;
V_108 = V_107 ;
continue;
}
case V_107 :
switch( V_99 [ V_2 ] ) {
case '\0' :
V_108 = V_106 ;
default:
continue;
}
case V_106 :
switch( V_99 [ V_2 ] ) {
default:
V_104 [ V_109 ] = & ( V_99 [ V_2 ] ) ;
V_109 ++ ;
V_108 = V_107 ;
case '\0' :
continue;
}
}
}
V_104 [ V_109 ] = NULL ;
return V_104 ;
}
T_5 *
F_63 ( const T_5 * V_111 , ... )
{
T_11 V_112 ;
T_4 args ;
T_5 * V_100 ;
T_5 * V_113 ;
T_5 * V_7 ;
if ( ! V_111 )
return NULL ;
V_112 = 1 + strlen ( V_111 ) ;
va_start ( args , V_111 ) ;
V_100 = va_arg ( args , T_5 * ) ;
while ( V_100 ) {
V_112 += strlen ( V_100 ) ;
V_100 = va_arg ( args , T_5 * ) ;
}
va_end ( args ) ;
V_113 = ( T_5 * ) F_41 ( V_112 ) ;
V_7 = V_113 ;
V_7 = F_64 ( V_7 , V_111 ) ;
va_start ( args , V_111 ) ;
V_100 = va_arg ( args , T_5 * ) ;
while ( V_100 ) {
V_7 = F_64 ( V_7 , V_100 ) ;
V_100 = va_arg ( args , T_5 * ) ;
}
va_end ( args ) ;
return V_113 ;
}
static void
F_65 ( T_7 * V_22 )
{
T_9 V_114 = V_22 -> V_24 ;
T_6 * V_15 ;
T_12 * V_115 ;
while( V_22 -> V_28 ) {
V_15 = V_22 -> V_28 ;
V_22 -> V_28 = V_22 -> V_28 -> V_19 ;
V_15 -> V_19 = V_22 -> V_18 ;
V_22 -> V_18 = V_15 ;
}
V_15 = V_22 -> V_18 ;
while ( V_15 != NULL ) {
if ( V_114 ) {
while ( V_15 -> V_21 != NULL ) {
V_15 -> V_21 = F_4 ( V_22 -> V_1 , ( T_1 * ) V_15 -> V_21 , NULL ) ;
if ( V_15 -> V_21 == ( void * ) - 1 )
F_8 ( L_30 ) ;
}
F_27 ( ( V_15 -> V_63 + V_15 -> V_64 ) ,
( V_15 -> V_65 - V_15 -> V_64 ) ,
FALSE ) ;
V_15 -> V_56 = V_15 -> V_55 ;
V_15 -> V_65 = V_15 -> V_64 ;
V_15 = V_15 -> V_19 ;
} else {
T_6 * V_19 = V_15 -> V_19 ;
F_27 ( V_15 -> V_63 , V_15 -> V_55 , FALSE ) ;
F_31 ( V_15 -> V_63 ) ;
F_31 ( V_15 ) ;
V_15 = V_19 ;
}
}
if ( ! V_114 ) {
V_22 -> V_18 = NULL ;
}
for( V_115 = V_22 -> V_29 ; V_115 ; V_115 = V_115 -> V_19 ) {
V_115 -> V_116 = NULL ;
}
}
void
F_66 ( void )
{
F_65 ( & V_17 ) ;
}
void
F_67 ( void )
{
#ifdef F_35
F_22 () ;
#endif
F_65 ( & V_31 ) ;
}
T_13
F_68 ( void ) {
T_13 V_100 = F_69 ( struct V_117 * ) ;
* V_100 = F_70 ( struct V_117 ) ;
return V_100 ;
}
void *
F_71 ( T_13 V_118 , void * V_119 )
{
struct V_117 * V_120 ;
struct V_117 * V_121 = ( * V_118 ) ;
if ( V_121 -> V_122 ) {
V_120 = V_121 -> V_122 ;
} else {
V_120 = F_69 ( struct V_117 ) ;
V_121 -> V_122 = V_120 ;
V_120 -> V_123 = V_121 ;
V_120 -> V_122 = NULL ;
}
V_120 -> V_124 = V_119 ;
( * V_118 ) = V_120 ;
return V_119 ;
}
void *
F_72 ( T_13 V_118 )
{
if ( ( * V_118 ) -> V_123 ) {
( * V_118 ) = ( * V_118 ) -> V_123 ;
return ( * V_118 ) -> V_122 -> V_124 ;
} else {
return NULL ;
}
}
T_12 *
F_73 ( int type , const char * V_125 )
{
T_12 * V_115 ;
V_115 = ( T_12 * ) F_34 ( sizeof( T_12 ) ) ;
V_115 -> V_19 = V_31 . V_29 ;
V_115 -> type = type ;
V_115 -> V_116 = NULL ;
V_115 -> V_125 = V_125 ;
V_115 -> malloc = F_42 ;
V_31 . V_29 = V_115 ;
return V_115 ;
}
void *
F_74 ( T_12 * V_126 , T_14 V_127 )
{
T_15 * V_128 ;
V_128 = V_126 -> V_116 ;
while( V_128 ) {
if( V_127 == V_128 -> V_129 ) {
return V_128 -> V_119 ;
}
if( V_127 < V_128 -> V_129 ) {
V_128 = V_128 -> V_130 ;
continue;
}
if( V_127 > V_128 -> V_129 ) {
V_128 = V_128 -> V_131 ;
continue;
}
}
return NULL ;
}
void *
F_75 ( T_12 * V_126 , T_14 V_127 )
{
T_15 * V_128 ;
V_128 = V_126 -> V_116 ;
if( ! V_128 ) {
return NULL ;
}
while( V_128 ) {
if( V_127 == V_128 -> V_129 ) {
return V_128 -> V_119 ;
}
if( V_127 < V_128 -> V_129 ) {
if( V_128 -> V_130 ) {
V_128 = V_128 -> V_130 ;
continue;
} else {
break;
}
}
if( V_127 > V_128 -> V_129 ) {
if( V_128 -> V_131 ) {
V_128 = V_128 -> V_131 ;
continue;
} else {
break;
}
}
}
if( ! V_128 ) {
return NULL ;
}
if( ! V_128 -> V_132 ) {
if( V_127 > V_128 -> V_129 ) {
return V_128 -> V_119 ;
} else {
return NULL ;
}
}
if( V_128 -> V_132 -> V_130 == V_128 ) {
if( V_127 > V_128 -> V_129 ) {
return V_128 -> V_119 ;
} else {
while( V_128 ) {
if( V_127 > V_128 -> V_129 ) {
return V_128 -> V_119 ;
}
V_128 = V_128 -> V_132 ;
}
return NULL ;
}
} else {
if( V_128 -> V_129 < V_127 ) {
return V_128 -> V_119 ;
} else {
return V_128 -> V_132 -> V_119 ;
}
}
}
static inline T_15 *
F_76 ( T_15 * V_128 )
{
return V_128 -> V_132 ;
}
static inline T_15 *
F_77 ( T_15 * V_128 )
{
T_15 * V_132 ;
V_132 = F_76 ( V_128 ) ;
if( V_132 ) {
return V_132 -> V_132 ;
}
return NULL ;
}
static inline T_15 *
F_78 ( T_15 * V_128 )
{
T_15 * V_132 , * V_133 ;
V_132 = F_76 ( V_128 ) ;
if( ! V_132 ) {
return NULL ;
}
V_133 = F_76 ( V_132 ) ;
if( ! V_133 ) {
return NULL ;
}
if( V_132 == V_133 -> V_130 ) {
return V_133 -> V_131 ;
}
return V_133 -> V_130 ;
}
static inline void
F_79 ( T_12 * V_126 , T_15 * V_128 )
{
if( V_128 -> V_132 ) {
if( V_128 -> V_132 -> V_130 == V_128 ) {
V_128 -> V_132 -> V_130 = V_128 -> V_131 ;
} else {
V_128 -> V_132 -> V_131 = V_128 -> V_131 ;
}
} else {
V_126 -> V_116 = V_128 -> V_131 ;
}
V_128 -> V_131 -> V_132 = V_128 -> V_132 ;
V_128 -> V_132 = V_128 -> V_131 ;
V_128 -> V_131 = V_128 -> V_131 -> V_130 ;
if( V_128 -> V_131 ) {
V_128 -> V_131 -> V_132 = V_128 ;
}
V_128 -> V_132 -> V_130 = V_128 ;
}
static inline void
F_80 ( T_12 * V_126 , T_15 * V_128 )
{
if( V_128 -> V_132 ) {
if( V_128 -> V_132 -> V_130 == V_128 ) {
V_128 -> V_132 -> V_130 = V_128 -> V_130 ;
} else {
V_128 -> V_132 -> V_131 = V_128 -> V_130 ;
}
} else {
V_126 -> V_116 = V_128 -> V_130 ;
}
V_128 -> V_130 -> V_132 = V_128 -> V_132 ;
V_128 -> V_132 = V_128 -> V_130 ;
V_128 -> V_130 = V_128 -> V_130 -> V_131 ;
if( V_128 -> V_130 ) {
V_128 -> V_130 -> V_132 = V_128 ;
}
V_128 -> V_132 -> V_131 = V_128 ;
}
static inline void
F_81 ( T_12 * V_126 , T_15 * V_128 )
{
T_15 * V_133 ;
T_15 * V_132 ;
V_132 = F_76 ( V_128 ) ;
V_133 = F_76 ( V_132 ) ;
V_132 -> V_134 . V_135 = V_136 ;
V_133 -> V_134 . V_135 = V_137 ;
if( ( V_128 == V_132 -> V_130 ) && ( V_132 == V_133 -> V_130 ) ) {
F_80 ( V_126 , V_133 ) ;
} else {
F_79 ( V_126 , V_133 ) ;
}
}
static inline void
F_82 ( T_12 * V_126 , T_15 * V_128 )
{
T_15 * V_133 ;
T_15 * V_132 ;
V_132 = F_76 ( V_128 ) ;
V_133 = F_76 ( V_132 ) ;
if( ! V_133 ) {
return;
}
if( ( V_128 == V_132 -> V_131 ) && ( V_132 == V_133 -> V_130 ) ) {
F_79 ( V_126 , V_132 ) ;
V_128 = V_128 -> V_130 ;
} else if( ( V_128 == V_132 -> V_130 ) && ( V_132 == V_133 -> V_131 ) ) {
F_80 ( V_126 , V_132 ) ;
V_128 = V_128 -> V_131 ;
}
F_81 ( V_126 , V_128 ) ;
}
static inline void
F_83 ( T_12 * V_126 , T_15 * V_128 )
{
T_15 * V_133 ;
T_15 * V_132 ;
T_15 * V_138 ;
V_138 = F_78 ( V_128 ) ;
if( V_138 && ( V_138 -> V_134 . V_135 == V_137 ) ) {
V_132 = F_76 ( V_128 ) ;
V_132 -> V_134 . V_135 = V_136 ;
V_138 -> V_134 . V_135 = V_136 ;
V_133 = F_77 ( V_128 ) ;
V_133 -> V_134 . V_135 = V_137 ;
F_84 ( V_126 , V_133 ) ;
} else {
F_82 ( V_126 , V_128 ) ;
}
}
static inline void
F_85 ( T_12 * V_126 , T_15 * V_128 )
{
T_15 * V_132 ;
V_132 = F_76 ( V_128 ) ;
if( V_132 -> V_134 . V_135 == V_136 ) {
return;
}
F_83 ( V_126 , V_128 ) ;
}
static inline void
F_84 ( T_12 * V_126 , T_15 * V_128 )
{
T_15 * V_132 ;
V_132 = F_76 ( V_128 ) ;
if( ! V_132 ) {
V_128 -> V_134 . V_135 = V_136 ;
return;
}
F_85 ( V_126 , V_128 ) ;
}
void
F_86 ( T_12 * V_126 , T_14 V_127 , void * V_119 )
{
T_15 * V_128 ;
V_128 = V_126 -> V_116 ;
if( ! V_128 ) {
V_128 = ( T_15 * ) V_126 -> malloc ( sizeof( T_15 ) ) ;
switch( V_126 -> type ) {
case V_139 :
V_128 -> V_134 . V_135 = V_136 ;
break;
}
V_128 -> V_132 = NULL ;
V_128 -> V_130 = NULL ;
V_128 -> V_131 = NULL ;
V_128 -> V_129 = V_127 ;
V_128 -> V_119 = V_119 ;
V_128 -> V_134 . V_140 = V_141 ;
V_126 -> V_116 = V_128 ;
return;
}
while( 1 ) {
if( V_127 == V_128 -> V_129 ) {
V_128 -> V_119 = V_119 ;
return;
}
if( V_127 < V_128 -> V_129 ) {
if( ! V_128 -> V_130 ) {
T_15 * V_142 ;
V_142 = ( T_15 * ) V_126 -> malloc ( sizeof( T_15 ) ) ;
V_128 -> V_130 = V_142 ;
V_142 -> V_132 = V_128 ;
V_142 -> V_130 = NULL ;
V_142 -> V_131 = NULL ;
V_142 -> V_129 = V_127 ;
V_142 -> V_119 = V_119 ;
V_142 -> V_134 . V_140 = V_141 ;
V_128 = V_142 ;
break;
}
V_128 = V_128 -> V_130 ;
continue;
}
if( V_127 > V_128 -> V_129 ) {
if( ! V_128 -> V_131 ) {
T_15 * V_142 ;
V_142 = ( T_15 * ) V_126 -> malloc ( sizeof( T_15 ) ) ;
V_128 -> V_131 = V_142 ;
V_142 -> V_132 = V_128 ;
V_142 -> V_130 = NULL ;
V_142 -> V_131 = NULL ;
V_142 -> V_129 = V_127 ;
V_142 -> V_119 = V_119 ;
V_142 -> V_134 . V_140 = V_141 ;
V_128 = V_142 ;
break;
}
V_128 = V_128 -> V_131 ;
continue;
}
}
switch( V_126 -> type ) {
case V_139 :
V_128 -> V_134 . V_135 = V_137 ;
F_84 ( V_126 , V_128 ) ;
break;
}
}
static void *
F_87 ( T_12 * V_126 , T_14 V_127 , void * (* F_88)( void * ) , void * V_143 , int V_140 )
{
T_15 * V_128 ;
V_128 = V_126 -> V_116 ;
if( ! V_128 ) {
V_128 = ( T_15 * ) V_126 -> malloc ( sizeof( T_15 ) ) ;
switch( V_126 -> type ) {
case V_139 :
V_128 -> V_134 . V_135 = V_136 ;
break;
}
V_128 -> V_132 = NULL ;
V_128 -> V_130 = NULL ;
V_128 -> V_131 = NULL ;
V_128 -> V_129 = V_127 ;
V_128 -> V_119 = F_88 ( V_143 ) ;
V_128 -> V_134 . V_140 = V_140 ;
V_126 -> V_116 = V_128 ;
return V_128 -> V_119 ;
}
while( 1 ) {
if( V_127 == V_128 -> V_129 ) {
return V_128 -> V_119 ;
}
if( V_127 < V_128 -> V_129 ) {
if( ! V_128 -> V_130 ) {
T_15 * V_142 ;
V_142 = ( T_15 * ) V_126 -> malloc ( sizeof( T_15 ) ) ;
V_128 -> V_130 = V_142 ;
V_142 -> V_132 = V_128 ;
V_142 -> V_130 = NULL ;
V_142 -> V_131 = NULL ;
V_142 -> V_129 = V_127 ;
V_142 -> V_119 = F_88 ( V_143 ) ;
V_142 -> V_134 . V_140 = V_140 ;
V_128 = V_142 ;
break;
}
V_128 = V_128 -> V_130 ;
continue;
}
if( V_127 > V_128 -> V_129 ) {
if( ! V_128 -> V_131 ) {
T_15 * V_142 ;
V_142 = ( T_15 * ) V_126 -> malloc ( sizeof( T_15 ) ) ;
V_128 -> V_131 = V_142 ;
V_142 -> V_132 = V_128 ;
V_142 -> V_130 = NULL ;
V_142 -> V_131 = NULL ;
V_142 -> V_129 = V_127 ;
V_142 -> V_119 = F_88 ( V_143 ) ;
V_142 -> V_134 . V_140 = V_140 ;
V_128 = V_142 ;
break;
}
V_128 = V_128 -> V_131 ;
continue;
}
}
switch( V_126 -> type ) {
case V_139 :
V_128 -> V_134 . V_135 = V_137 ;
F_84 ( V_126 , V_128 ) ;
break;
}
return V_128 -> V_119 ;
}
T_12 *
F_89 ( int type , const char * V_125 )
{
T_12 * V_115 ;
V_115 = ( T_12 * ) F_42 ( sizeof( T_12 ) ) ;
V_115 -> V_19 = NULL ;
V_115 -> type = type ;
V_115 -> V_116 = NULL ;
V_115 -> V_125 = V_125 ;
V_115 -> malloc = F_42 ;
return V_115 ;
}
T_12 *
F_90 ( int type , const char * V_125 )
{
T_12 * V_115 ;
V_115 = F_29 ( T_12 , 1 ) ;
V_115 -> V_19 = NULL ;
V_115 -> type = type ;
V_115 -> V_116 = NULL ;
V_115 -> V_125 = V_125 ;
V_115 -> malloc = ( void * (*)( T_3 ) ) F_34 ;
return V_115 ;
}
static T_12 *
F_91 ( T_12 * V_144 , const char * V_125 )
{
T_12 * V_115 ;
V_115 = ( T_12 * ) V_144 -> malloc ( sizeof( T_12 ) ) ;
V_115 -> V_19 = NULL ;
V_115 -> type = V_144 -> type ;
V_115 -> V_116 = NULL ;
V_115 -> V_125 = V_125 ;
V_115 -> malloc = V_144 -> malloc ;
return V_115 ;
}
static void *
F_92 ( void * V_145 )
{
T_12 * V_126 = ( T_12 * ) V_145 ;
return F_91 ( V_126 , L_55 ) ;
}
void
F_93 ( T_12 * V_126 , T_16 * V_127 , void * V_119 )
{
T_12 * V_146 = NULL ;
T_16 * V_147 ;
T_14 V_2 , V_148 = 0 ;
if( ! V_126 || ! V_127 ) return;
for ( V_147 = V_127 ; V_147 -> V_149 > 0 ; V_147 ++ ) {
if( V_147 -> V_149 > 100 ) {
F_94 () ;
}
for ( V_2 = 0 ; V_2 < V_147 -> V_149 ; V_2 ++ ) {
if ( ! V_146 ) {
V_146 = V_126 ;
} else {
V_146 = ( T_12 * ) F_87 ( V_146 , V_148 , F_92 , V_126 , V_150 ) ;
}
V_148 = V_147 -> V_127 [ V_2 ] ;
}
}
if( ! V_146 ) {
F_94 () ;
}
F_86 ( V_146 , V_148 , V_119 ) ;
}
void *
F_95 ( T_12 * V_126 , T_16 * V_127 )
{
T_12 * V_151 = NULL ;
T_16 * V_147 ;
T_14 V_2 , V_152 = 0 ;
if( ! V_126 || ! V_127 ) return NULL ;
for ( V_147 = V_127 ; V_147 -> V_149 > 0 ; V_147 ++ ) {
if( V_147 -> V_149 > 100 ) {
F_94 () ;
}
for ( V_2 = 0 ; V_2 < V_147 -> V_149 ; V_2 ++ ) {
if ( ! V_151 ) {
V_151 = V_126 ;
} else {
V_151 = ( T_12 * ) F_74 ( V_151 , V_152 ) ;
if ( ! V_151 ) {
return NULL ;
}
}
V_152 = V_147 -> V_127 [ V_2 ] ;
}
}
if( ! V_151 ) {
F_94 () ;
}
return F_74 ( V_151 , V_152 ) ;
}
void *
F_96 ( T_12 * V_126 , T_16 * V_127 )
{
T_12 * V_151 = NULL ;
T_16 * V_147 ;
T_14 V_2 , V_152 = 0 ;
if( ! V_126 || ! V_127 ) return NULL ;
for ( V_147 = V_127 ; V_147 -> V_149 > 0 ; V_147 ++ ) {
if( V_147 -> V_149 > 100 ) {
F_94 () ;
}
for ( V_2 = 0 ; V_2 < V_147 -> V_149 ; V_2 ++ ) {
if ( ! V_151 ) {
V_151 = V_126 ;
} else {
V_151 = ( T_12 * ) F_75 ( V_151 , V_152 ) ;
if ( ! V_151 ) {
return NULL ;
}
}
V_152 = V_147 -> V_127 [ V_2 ] ;
}
}
if( ! V_151 ) {
F_94 () ;
}
return F_75 ( V_151 , V_152 ) ;
}
void
F_97 ( T_12 * V_126 , const T_5 * V_153 , void * V_154 , T_14 V_155 )
{
T_16 V_127 [ 2 ] ;
T_14 * V_156 = NULL ;
T_14 V_6 = ( T_14 ) strlen ( V_153 ) ;
T_14 V_157 = ( V_6 + 3 ) / 4 + 1 ;
T_14 V_2 ;
T_14 V_158 ;
V_156 = ( T_14 * ) F_34 ( V_157 * sizeof ( T_14 ) ) ;
V_158 = 0 ;
for ( V_2 = 0 ; V_2 < V_6 ; V_2 ++ ) {
unsigned char V_159 ;
V_159 = ( unsigned char ) V_153 [ V_2 ] ;
if ( V_155 & V_160 ) {
if( isupper ( V_159 ) ) {
V_159 = tolower ( V_159 ) ;
}
}
V_158 <<= 8 ;
V_158 |= V_159 ;
if ( V_2 % 4 == 3 ) {
V_156 [ V_2 / 4 ] = V_158 ;
V_158 = 0 ;
}
}
if ( V_2 % 4 != 0 ) {
while ( V_2 % 4 != 0 ) {
V_2 ++ ;
V_158 <<= 8 ;
}
V_156 [ V_2 / 4 - 1 ] = V_158 ;
}
V_156 [ V_157 - 1 ] = 0x00000001 ;
V_127 [ 0 ] . V_149 = V_157 ;
V_127 [ 0 ] . V_127 = V_156 ;
V_127 [ 1 ] . V_149 = 0 ;
V_127 [ 1 ] . V_127 = NULL ;
F_93 ( V_126 , V_127 , V_154 ) ;
F_31 ( V_156 ) ;
}
void *
F_98 ( T_12 * V_126 , const T_5 * V_153 , T_14 V_155 )
{
T_16 V_127 [ 2 ] ;
T_14 * V_156 = NULL ;
T_14 V_6 = ( T_8 ) strlen ( V_153 ) ;
T_14 V_157 = ( V_6 + 3 ) / 4 + 1 ;
T_14 V_2 ;
T_14 V_158 ;
void * V_80 ;
V_156 = ( T_14 * ) F_34 ( V_157 * sizeof ( T_14 ) ) ;
V_158 = 0 ;
for ( V_2 = 0 ; V_2 < V_6 ; V_2 ++ ) {
unsigned char V_159 ;
V_159 = ( unsigned char ) V_153 [ V_2 ] ;
if ( V_155 & V_160 ) {
if( isupper ( V_159 ) ) {
V_159 = tolower ( V_159 ) ;
}
}
V_158 <<= 8 ;
V_158 |= V_159 ;
if ( V_2 % 4 == 3 ) {
V_156 [ V_2 / 4 ] = V_158 ;
V_158 = 0 ;
}
}
if ( V_2 % 4 != 0 ) {
while ( V_2 % 4 != 0 ) {
V_2 ++ ;
V_158 <<= 8 ;
}
V_156 [ V_2 / 4 - 1 ] = V_158 ;
}
V_156 [ V_157 - 1 ] = 0x00000001 ;
V_127 [ 0 ] . V_149 = V_157 ;
V_127 [ 0 ] . V_127 = V_156 ;
V_127 [ 1 ] . V_149 = 0 ;
V_127 [ 1 ] . V_127 = NULL ;
V_80 = F_95 ( V_126 , V_127 ) ;
F_31 ( V_156 ) ;
return V_80 ;
}
static T_9
F_99 ( T_15 * V_128 , T_17 V_161 , void * V_162 )
{
T_9 V_163 = FALSE ;
if ( ! V_128 )
return FALSE ;
if( V_128 -> V_130 ) {
V_163 = F_99 ( V_128 -> V_130 , V_161 , V_162 ) ;
if ( V_163 ) {
return TRUE ;
}
}
if ( V_128 -> V_134 . V_140 == V_150 ) {
V_163 = F_100 ( ( T_12 * ) V_128 -> V_119 , V_161 , V_162 ) ;
} else {
V_163 = V_161 ( V_128 -> V_119 , V_162 ) ;
}
if ( V_163 ) {
return TRUE ;
}
if( V_128 -> V_131 ) {
V_163 = F_99 ( V_128 -> V_131 , V_161 , V_162 ) ;
if ( V_163 ) {
return TRUE ;
}
}
return FALSE ;
}
T_9
F_100 ( T_12 * V_164 , T_17 V_161 , void * V_162 )
{
if ( ! V_164 )
return FALSE ;
if( ! V_164 -> V_116 )
return FALSE ;
return F_99 ( V_164 -> V_116 , V_161 , V_162 ) ;
}
static void
F_101 ( const char * V_165 , T_15 * V_128 , T_14 V_166 )
{
T_14 V_2 ;
if ( ! V_128 )
return;
for( V_2 = 0 ; V_2 < V_166 ; V_2 ++ ) {
printf ( L_56 ) ;
}
printf ( L_57 , V_165 ,
( void * ) V_128 , ( void * ) ( V_128 -> V_132 ) , ( void * ) ( V_128 -> V_130 ) , ( void * ) ( V_128 -> V_131 ) ,
( V_128 -> V_134 . V_135 ) ? L_58 : L_59 , ( V_128 -> V_129 ) , ( V_128 -> V_134 . V_140 ) ? L_60 : L_61 , V_128 -> V_119 ) ;
if( V_128 -> V_130 )
F_101 ( L_62 , V_128 -> V_130 , V_166 + 1 ) ;
if( V_128 -> V_131 )
F_101 ( L_63 , V_128 -> V_131 , V_166 + 1 ) ;
if ( V_128 -> V_134 . V_140 )
F_102 ( ( T_12 * ) V_128 -> V_119 , V_166 + 1 ) ;
}
static void
F_102 ( T_12 * V_164 , T_14 V_166 )
{
T_14 V_2 ;
if ( ! V_164 )
return;
for( V_2 = 0 ; V_2 < V_166 ; V_2 ++ ) {
printf ( L_56 ) ;
}
printf ( L_64 , V_164 , ( V_164 -> type == 1 ) ? L_65 : L_66 , V_164 -> V_125 , ( void * ) ( V_164 -> V_116 ) ) ;
if( V_164 -> V_116 )
F_101 ( L_67 , V_164 -> V_116 , V_166 ) ;
}
void
F_103 ( T_12 * V_164 )
{
F_102 ( V_164 , 0 ) ;
}
static T_11
F_104 ( T_11 V_167 , T_11 V_168 , T_11 V_169 )
{
if ( V_169 < 1 || V_169 > V_170 ) {
V_169 = V_170 ;
}
if ( V_167 < 1 ) {
V_167 = V_171 ;
}
while ( V_167 < V_168 ) {
V_167 *= 2 ;
}
return V_167 < V_169 ? V_167 : V_169 ;
}
static void
F_105 ( T_18 * V_172 , T_11 V_168 )
{
T_11 V_173 ;
T_5 * V_174 ;
if ( ! V_172 || ( V_168 <= V_172 -> V_175 ) || ( V_172 -> V_175 >= V_172 -> V_169 ) ) {
return;
}
V_173 = F_104 ( V_172 -> V_175 , V_168 , V_172 -> V_169 ) ;
V_174 = ( T_5 * ) F_41 ( V_173 ) ;
F_9 ( V_174 , V_172 -> V_176 , V_173 ) ;
V_172 -> V_175 = V_173 ;
V_172 -> V_176 = V_174 ;
}
T_18 *
F_106 ( T_11 V_175 , T_11 V_169 )
{
T_18 * V_172 ;
V_172 = F_69 ( T_18 ) ;
if ( ( V_169 == 0 ) || ( V_169 > V_170 ) )
V_169 = V_170 ;
if ( V_175 == 0 )
V_175 = 1 ;
else if ( V_175 > V_169 )
V_175 = V_169 ;
V_172 -> V_176 = ( char * ) F_41 ( V_175 ) ;
V_172 -> V_176 [ 0 ] = '\0' ;
V_172 -> V_6 = 0 ;
V_172 -> V_175 = V_175 ;
V_172 -> V_169 = V_169 ;
return V_172 ;
}
T_18 *
F_107 ( const T_5 * V_177 )
{
T_18 * V_172 ;
V_172 = F_106 ( F_104 ( 0 , V_177 ? strlen ( V_177 ) + 1 : 0 , 0 ) , 0 ) ;
if ( V_177 ) {
T_11 V_178 ;
V_178 = F_9 ( V_172 -> V_176 , V_177 , V_172 -> V_175 ) ;
V_172 -> V_6 = F_108 ( V_178 , V_172 -> V_175 - 1 ) ;
}
return V_172 ;
}
T_18 *
F_109 ( const T_5 * V_177 )
{
T_18 * V_172 ;
T_11 V_178 ;
V_172 = F_106 ( V_171 , V_179 ) ;
if ( ! V_177 )
return V_172 ;
V_178 = F_9 ( V_172 -> V_176 , V_177 , V_172 -> V_175 ) ;
if ( V_178 < V_172 -> V_175 ) {
V_172 -> V_6 += V_178 ;
} else {
V_172 = F_106 ( V_178 + 1 , V_179 ) ;
V_178 = F_9 ( V_172 -> V_176 , V_177 , V_172 -> V_175 ) ;
V_172 -> V_6 = F_108 ( V_178 , V_172 -> V_175 - 1 ) ;
}
return V_172 ;
}
T_18 *
F_110 ( T_18 * V_172 , const T_5 * V_176 )
{
T_11 V_180 , V_178 ;
if ( ! V_172 || ! V_176 || V_176 [ 0 ] == '\0' ) {
return V_172 ;
}
V_180 = V_172 -> V_175 - V_172 -> V_6 ;
V_178 = F_9 ( & V_172 -> V_176 [ V_172 -> V_6 ] , V_176 , V_180 ) ;
if ( V_178 < V_180 ) {
V_172 -> V_6 += V_178 ;
} else {
V_172 -> V_176 [ V_172 -> V_6 ] = '\0' ;
F_105 ( V_172 , V_172 -> V_6 + V_178 + 1 ) ;
V_180 = V_172 -> V_175 - V_172 -> V_6 ;
V_178 = F_9 ( & V_172 -> V_176 [ V_172 -> V_6 ] , V_176 , V_180 ) ;
V_172 -> V_6 += F_108 ( V_180 - 1 , V_178 ) ;
}
return V_172 ;
}
void
F_111 ( T_18 * V_172 , const T_5 * V_181 , T_4 V_12 )
{
T_4 V_95 ;
T_11 V_180 , V_178 ;
F_55 ( V_95 , V_12 ) ;
V_180 = V_172 -> V_175 - V_172 -> V_6 ;
V_178 = F_7 ( & V_172 -> V_176 [ V_172 -> V_6 ] , ( V_96 ) V_180 , V_181 , V_12 ) ;
if ( V_178 < V_180 ) {
V_172 -> V_6 += V_178 ;
} else {
V_172 -> V_176 [ V_172 -> V_6 ] = '\0' ;
F_105 ( V_172 , V_172 -> V_6 + V_178 + 1 ) ;
V_180 = V_172 -> V_175 - V_172 -> V_6 ;
V_178 = F_7 ( & V_172 -> V_176 [ V_172 -> V_6 ] , ( V_96 ) V_180 , V_181 , V_95 ) ;
V_172 -> V_6 += F_108 ( V_180 - 1 , V_178 ) ;
}
va_end ( V_95 ) ;
}
void
F_112 ( T_18 * V_172 , const T_5 * V_181 , ... )
{
T_4 V_12 ;
va_start ( V_12 , V_181 ) ;
F_111 ( V_172 , V_181 , V_12 ) ;
va_end ( V_12 ) ;
}
void
F_113 ( T_18 * V_172 , const T_5 * V_181 , ... )
{
T_4 V_12 ;
if ( ! V_172 ) {
return;
}
V_172 -> V_6 = 0 ;
va_start ( V_12 , V_181 ) ;
F_111 ( V_172 , V_181 , V_12 ) ;
va_end ( V_12 ) ;
}
T_18 *
F_114 ( T_18 * V_172 , const T_5 V_182 )
{
if ( ! V_172 ) {
return V_172 ;
}
if ( V_172 -> V_175 < V_172 -> V_6 + 1 + 1 ) {
F_105 ( V_172 , V_172 -> V_6 + 1 + 1 ) ;
}
if ( V_172 -> V_175 >= V_172 -> V_6 + 1 + 1 ) {
V_172 -> V_176 [ V_172 -> V_6 ] = V_182 ;
V_172 -> V_6 ++ ;
V_172 -> V_176 [ V_172 -> V_6 ] = '\0' ;
}
return V_172 ;
}
T_18 *
F_115 ( T_18 * V_172 , const T_19 V_182 )
{
T_5 V_63 [ 6 ] ;
T_20 V_183 ;
if ( ! V_172 ) {
return V_172 ;
}
V_183 = F_116 ( V_182 , V_63 ) ;
if ( V_172 -> V_175 < V_172 -> V_6 + V_183 + 1 ) {
F_105 ( V_172 , V_172 -> V_6 + V_183 + 1 ) ;
}
if ( V_172 -> V_175 >= V_172 -> V_6 + V_183 + 1 ) {
memcpy ( & V_172 -> V_176 [ V_172 -> V_6 ] , V_63 , V_183 ) ;
V_172 -> V_6 += V_183 ;
V_172 -> V_176 [ V_172 -> V_6 ] = '\0' ;
}
return V_172 ;
}
T_18 *
F_117 ( T_18 * V_172 , T_11 V_6 )
{
if ( ! V_172 || V_6 >= V_172 -> V_6 ) {
return V_172 ;
}
V_172 -> V_176 [ V_6 ] = '\0' ;
V_172 -> V_6 = V_6 ;
return V_172 ;
}
