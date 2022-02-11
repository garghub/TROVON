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
V_17 . V_24 = ( getenv ( L_3 ) == NULL ) ;
V_17 . V_23 = V_17 . V_24 && ( getenv ( L_4 ) == NULL ) ;
V_17 . V_35 = ( getenv ( L_5 ) != NULL ) ;
#ifdef F_14
V_16 = ( getenv ( L_6 ) != NULL ) ;
#endif
F_10 ( & V_17 ) ;
F_15 ( & V_34 ) ;
}
static T_8
F_16 ( void )
{
return F_11 ( & V_36 ) ;
}
static void
F_17 ( void )
{
static const T_9 V_37 = { L_7 , F_16 , NULL } ;
V_36 . V_18 = NULL ;
V_36 . V_31 = NULL ;
V_36 . V_24 = ( getenv ( L_8 ) == NULL ) ;
V_36 . V_23 = V_36 . V_24 && ( getenv ( L_9 ) != NULL ) ;
V_36 . V_35 = ( getenv ( L_10 ) != NULL ) ;
F_10 ( & V_36 ) ;
F_15 ( & V_37 ) ;
}
void
F_18 ( void )
{
F_13 () ;
F_17 () ;
if ( getenv ( L_11 ) )
V_38 = TRUE ;
#if F_19 ( V_39 )
F_20 ( & V_40 ) ;
V_41 = V_40 . V_42 ;
#if ( V_43 >= 1800 )
{
T_10 V_44 ;
T_11 V_45 = 0 ;
int V_46 = V_47 ;
F_21 ( & V_44 , sizeof( T_10 ) ) ;
V_44 . V_48 = sizeof( T_10 ) ;
V_44 . V_49 = V_50 ;
F_22 ( V_45 , V_51 , V_46 ) ;
V_52 = F_23 ( & V_44 , V_51 , V_45 ) ;
}
#else
{
T_12 V_53 ;
F_21 ( & V_53 , sizeof( T_12 ) ) ;
V_53 . V_48 = sizeof( T_12 ) ;
F_24 ( & V_53 ) ;
V_52 = ( V_53 . V_49 == V_50 ) ;
}
#endif
#elif F_19 ( V_54 )
V_41 = F_25 ( V_55 ) ;
if ( V_41 == - 1 )
fprintf ( V_56 , L_12 ) ;
#ifdef F_26
V_57 = F_27 ( L_13 , V_58 ) ;
F_28 ( V_57 != - 1 ) ;
#endif
#endif
}
static void
F_29 ( void )
{
T_13 V_59 = 0 ;
T_13 V_60 = 0 ;
T_13 V_29 = 0 ;
T_13 V_61 = 0 ;
T_13 V_62 = 0 ;
T_13 V_63 ;
T_13 V_2 ;
T_6 * V_30 ;
T_13 V_64 , V_65 ;
T_14 V_66 = TRUE ;
fprintf ( V_56 , L_14 ) ;
fprintf ( V_56 , L_15 ,
V_17 . V_24 ? L_16 : L_17 ,
V_17 . V_23 ? L_18 : L_19 ,
V_38 ? L_18 : L_19 ) ;
if ( ! ( V_17 . V_18 || ! V_17 . V_31 ) ) {
fprintf ( V_56 , L_20 ) ;
V_66 = FALSE ;
}
if ( V_17 . V_24 && V_66 ) {
for ( V_30 = V_17 . V_31 ; V_30 ; V_30 = V_30 -> V_19 ) {
V_59 ++ ;
V_29 += ( V_30 -> V_32 - V_30 -> V_33 ) ;
V_61 += V_30 -> V_32 ;
}
if ( V_59 > 0 ) {
fprintf ( V_56 , L_21 ) ;
fprintf ( V_56 , L_22 ) ;
fprintf ( V_56 , L_23 , V_67 ) ;
fprintf ( V_56 , L_24 , V_59 ) ;
fprintf ( V_56 , L_25 ) ;
fprintf ( V_56 , L_26 ,
V_61 , V_67 * V_59 ) ;
fprintf ( V_56 , L_25 ) ;
V_64 = V_61
+ sizeof( T_6 ) * V_59 ;
fprintf ( V_56 , L_27 ,
V_64 ) ;
} else{
fprintf ( V_56 , L_28 ) ;
}
V_59 = 0 ;
V_60 = 0 ;
V_29 = 0 ;
V_61 = 0 ;
V_62 = 0 ;
}
fprintf ( V_56 , L_29 ) ;
fprintf ( V_56 , L_30 ,
V_68 ) ;
fprintf ( V_56 , L_31 ,
V_36 . V_24 ? L_16 : L_17 ,
V_36 . V_23 ? L_18 : L_19 ) ;
if ( ! ( V_36 . V_18 || ! V_36 . V_31 ) ) {
fprintf ( V_56 , L_20 ) ;
return;
}
if ( ! V_36 . V_24 )
return;
for ( V_30 = V_36 . V_31 ; V_30 ; V_30 = V_30 -> V_19 ) {
V_59 ++ ;
V_29 += ( V_30 -> V_32 - V_30 -> V_33 ) ;
V_61 += V_30 -> V_32 ;
if ( V_36 . V_23 ) {
void * V_7 = V_30 -> V_21 ;
int V_6 ;
while ( V_7 != NULL ) {
V_7 = F_4 ( V_36 . V_1 , ( T_1 * ) V_7 , & V_6 ) ;
if ( V_7 == ( void * ) - 1 )
F_8 ( L_32 ) ;
V_62 += V_6 ;
}
}
}
if ( V_59 == 0 ) {
fprintf ( V_56 , L_28 ) ;
return;
}
fprintf ( V_56 , L_21 ) ;
fprintf ( V_56 , L_33 ) ;
fprintf ( V_56 , L_34 ) ;
fprintf ( V_56 , L_35 ,
sizeof( T_6 ) ) ;
fprintf ( V_56 , L_36 , V_59 ) ;
fprintf ( V_56 , L_25 ) ;
V_63 = sizeof( T_6 ) * V_59 ;
fprintf ( V_56 , L_37 , V_63 ) ;
fprintf ( V_56 , L_22 ) ;
fprintf ( V_56 , L_23 ,
V_67 ) ;
fprintf ( V_56 , L_24 , V_59 ) ;
fprintf ( V_56 , L_25 ) ;
fprintf ( V_56 , L_38 ,
V_61 , V_67 * V_59 ) ;
fprintf ( V_56 , L_25 ) ;
V_64 = ( V_67 * V_59 )
+ V_63 ;
fprintf ( V_56 , L_39 ,
V_64 ) ;
for ( V_2 = 0 ; V_2 < V_69 ; V_2 ++ )
V_60 += V_70 [ V_2 ] ;
fprintf ( V_56 , L_40 ) ;
fprintf ( V_56 , L_41 ,
V_60 ) ;
fprintf ( V_56 , L_42 ,
V_29 ) ;
fprintf ( V_56 , L_43 ,
V_62 ) ;
fprintf ( V_56 , L_44 ,
V_61 - V_29 ) ;
fprintf ( V_56 , L_45 ,
V_64 - V_29 ) ;
fprintf ( V_56 , L_46 ) ;
fprintf ( V_56 , L_47 ,
( float ) V_29 / ( float ) V_60 ) ;
fprintf ( V_56 , L_48 ,
( float ) ( V_29 - V_62 ) / ( float ) V_60 ) ;
fprintf ( V_56 , L_49 ,
( V_61 - V_29 ) / ( float ) V_60 ) ;
V_65 = ( V_61 - V_29 )
+ ( sizeof( T_6 ) ) ;
fprintf ( V_56 , L_50 ,
V_65 ) ;
fprintf ( V_56 , L_51 ,
100 * ( float ) V_65 / ( float ) V_64 ) ;
fprintf ( V_56 , L_52 ) ;
for ( V_2 = 0 ; V_2 < ( V_69 - 1 ) ; V_2 ++ )
fprintf ( V_56 , L_53 , 32 << V_2 , V_70 [ V_2 ] ) ;
fprintf ( V_56 , L_54 , 32 << V_2 , V_70 [ V_2 ] ) ;
}
static T_14
F_30 ( const T_6 * V_71 , const void * V_7 )
{
const T_5 * V_72 = ( const T_5 * ) V_7 ;
const T_6 * V_30 ;
for ( V_30 = V_71 ; V_30 ; V_30 = V_30 -> V_19 ) {
if ( V_72 >= ( V_30 -> V_73 + V_30 -> V_74 ) && V_72 < ( V_30 -> V_73 + V_30 -> V_75 ) )
return TRUE ;
}
return FALSE ;
}
static T_14
F_31 ( const T_7 * V_76 , const void * V_7 )
{
return F_30 ( V_76 -> V_18 , V_7 ) || F_30 ( V_76 -> V_31 , V_7 ) ;
}
T_14
F_32 ( const void * V_7 )
{
if ( V_17 . V_35 )
return F_31 ( & V_17 , V_7 ) ;
else
return FALSE ;
}
static void
F_33 ( char * V_73 , T_3 V_77 , T_14 V_78 )
{
T_13 V_79 ;
T_3 V_80 ;
if ( ! V_38 )
return;
if ( V_78 )
V_79 = 0xBADDCAFE ;
else
V_79 = 0xDEADBEEF ;
for ( V_80 = 0 ; V_80 + sizeof( T_13 ) <= V_77 ; V_80 += sizeof( T_13 ) )
* ( T_13 * ) ( void * ) ( V_73 + V_80 ) = V_79 ;
if ( V_80 < V_77 ) {
* ( T_1 * ) ( V_73 + V_80 ) = V_79 >> 24 ;
V_80 ++ ;
if ( V_80 < V_77 ) {
* ( T_1 * ) ( V_73 + V_80 ) = ( V_79 >> 16 ) & 0xFF ;
V_80 ++ ;
if ( V_80 < V_77 ) {
* ( T_1 * ) ( V_73 + V_80 ) = ( V_79 >> 8 ) & 0xFF ;
}
}
}
}
static T_6 *
F_34 ( T_3 V_77 )
{
T_6 * V_15 ;
V_15 = F_35 ( T_6 , 1 ) ;
V_15 -> V_19 = NULL ;
V_15 -> V_21 = NULL ;
#if F_19 ( V_39 )
V_15 -> V_73 = ( char * ) F_36 ( NULL , V_77 ,
V_81 | V_82 , V_83 ) ;
if ( V_15 -> V_73 == NULL ) {
F_37 ( V_15 ) ;
if ( getenv ( L_55 ) )
abort () ;
else
F_38 ( V_84 ) ;
}
#elif F_19 ( V_54 )
V_15 -> V_73 = ( char * ) F_39 ( NULL , V_77 ,
V_85 | V_86 , V_87 , V_88 , 0 ) ;
if ( V_15 -> V_73 == V_89 ) {
F_37 ( V_15 ) ;
if ( getenv ( L_55 ) )
abort () ;
else
F_38 ( V_84 ) ;
}
#else
V_15 -> V_73 = F_40 ( V_77 ) ;
#endif
#ifdef F_41
V_68 ++ ;
#endif
V_15 -> V_33 = V_15 -> V_32 = ( unsigned int ) V_77 ;
V_15 -> V_75 = V_15 -> V_74 = 0 ;
return V_15 ;
}
static T_6 *
F_42 ( T_3 V_77 )
{
#if F_19 ( V_39 )
BOOL V_90 ;
char * V_91 , * V_92 , * V_93 ;
T_15 V_94 ;
#elif F_19 ( V_54 )
int V_90 ;
char * V_91 , * V_92 , * V_93 ;
#endif
T_6 * V_15 ;
V_15 = F_34 ( V_77 ) ;
#if F_19 ( V_39 )
V_91 = V_15 -> V_73 + V_77 ;
V_92 = ( char * ) ( ( ( ( V_95 ) V_15 -> V_73 + V_41 - 1 ) / V_41 ) * V_41 ) ;
V_93 = ( char * ) ( ( ( ( V_95 ) V_91 - ( 1 * V_41 ) ) / V_41 ) * V_41 ) ;
V_90 = F_43 ( V_92 , V_41 , V_96 , & V_94 ) ;
F_28 ( V_90 != 0 || V_52 ) ;
V_90 = F_43 ( V_93 , V_41 , V_96 , & V_94 ) ;
F_28 ( V_90 != 0 || V_52 ) ;
V_15 -> V_32 = ( unsigned int ) ( V_93 - V_92 - V_41 ) ;
V_15 -> V_74 = ( unsigned int ) ( V_92 - V_15 -> V_73 ) + V_41 ;
#elif F_19 ( V_54 )
V_91 = V_15 -> V_73 + V_77 ;
V_92 = ( char * ) ( ( ( ( V_95 ) V_15 -> V_73 + V_41 - 1 ) / V_41 ) * V_41 ) ;
V_93 = ( char * ) ( ( ( ( V_95 ) V_91 - ( 1 * V_41 ) ) / V_41 ) * V_41 ) ;
V_90 = F_44 ( V_92 , V_41 , V_97 ) ;
F_28 ( V_90 != - 1 ) ;
V_90 = F_44 ( V_93 , V_41 , V_97 ) ;
F_28 ( V_90 != - 1 ) ;
V_15 -> V_32 = ( unsigned int ) ( V_93 - V_92 - V_41 ) ;
V_15 -> V_74 = ( unsigned int ) ( ( V_92 - V_15 -> V_73 ) + V_41 ) ;
#else
V_15 -> V_32 = V_77 ;
V_15 -> V_74 = 0 ;
#endif
V_15 -> V_33 = V_15 -> V_32 ;
V_15 -> V_75 = V_15 -> V_74 ;
return V_15 ;
}
static void *
V_26 ( T_3 V_77 , T_7 * V_22 )
{
void * V_73 ;
T_3 V_98 = V_77 ;
T_14 V_99 = V_22 -> V_23 ;
T_1 V_10 ;
T_6 * V_18 ;
if ( V_99 ) {
V_98 += sizeof( void * ) ;
V_10 = F_5 ( V_98 ) ;
} else
V_10 = ( V_100 - ( V_98 & ( V_100 - 1 ) ) ) & ( V_100 - 1 ) ;
V_98 += V_10 ;
#ifdef F_41
if ( V_22 == & V_36 ) {
if ( V_98 < 32 )
V_70 [ 0 ] ++ ;
else if ( V_98 < 64 )
V_70 [ 1 ] ++ ;
else if ( V_98 < 128 )
V_70 [ 2 ] ++ ;
else if ( V_98 < 256 )
V_70 [ 3 ] ++ ;
else if ( V_98 < 512 )
V_70 [ 4 ] ++ ;
else if ( V_98 < 1024 )
V_70 [ 5 ] ++ ;
else if ( V_98 < 2048 )
V_70 [ 6 ] ++ ;
else if ( V_98 < 4096 )
V_70 [ 7 ] ++ ;
else if ( V_98 < 8192 )
V_70 [ 8 ] ++ ;
else if ( V_98 < 16384 )
V_70 [ 8 ] ++ ;
else
V_70 [ ( V_69 - 1 ) ] ++ ;
}
#endif
F_45 ( V_77 < ( V_67 >> 2 ) ) ;
if ( ! V_22 -> V_18 )
V_22 -> V_18 = F_42 ( V_67 ) ;
if( V_98 > V_22 -> V_18 -> V_33 ) {
T_6 * V_15 ;
V_15 = V_22 -> V_18 ;
V_22 -> V_18 = V_22 -> V_18 -> V_19 ;
V_15 -> V_19 = V_22 -> V_31 ;
V_22 -> V_31 = V_15 ;
if ( ! V_22 -> V_18 )
V_22 -> V_18 = F_42 ( V_67 ) ;
}
V_18 = V_22 -> V_18 ;
V_73 = V_18 -> V_73 + V_18 -> V_75 ;
V_18 -> V_33 -= ( unsigned int ) V_98 ;
V_18 -> V_75 += ( unsigned int ) V_98 ;
if ( V_99 ) {
char * V_72 = ( char * ) V_73 + V_77 ;
memcpy ( V_72 , V_22 -> V_1 , V_10 - 1 ) ;
V_72 [ V_10 - 1 ] = '\0' ;
memcpy ( V_72 + V_10 , & V_18 -> V_21 , sizeof( void * ) ) ;
V_18 -> V_21 = V_72 ;
}
return V_73 ;
}
static void *
V_27 ( T_3 V_77 , T_7 * V_22 )
{
T_6 * V_15 ;
V_15 = F_35 ( T_6 , 1 ) ;
V_15 -> V_19 = V_22 -> V_31 ;
V_15 -> V_73 = ( char * ) F_40 ( V_77 ) ;
V_15 -> V_21 = NULL ;
V_22 -> V_31 = V_15 ;
V_15 -> V_33 = V_15 -> V_74 = 0 ;
V_15 -> V_75 = V_15 -> V_32 = ( unsigned int ) V_77 ;
return V_15 -> V_73 ;
}
static void *
F_46 ( T_3 V_77 , T_7 * V_22 )
{
void * V_73 ;
#if 0
if (mem == &ep_packet_mem) {
return wmem_alloc(wmem_packet_scope(), size);
}
else if (mem == &se_packet_mem) {
return wmem_alloc(wmem_file_scope(), size);
}
#endif
V_73 = V_22 -> V_25 ( V_77 , V_22 ) ;
F_33 ( ( char * ) V_73 , V_77 , TRUE ) ;
return V_73 ;
}
void *
F_47 ( T_3 V_77 )
{
return F_46 ( V_77 , & V_17 ) ;
}
void *
F_48 ( T_3 V_77 )
{
return F_46 ( V_77 , & V_36 ) ;
}
void *
F_49 ( T_3 V_77 )
{
return memset ( F_47 ( V_77 ) , '\0' , V_77 ) ;
}
void *
F_50 ( T_3 V_77 )
{
return memset ( F_48 ( V_77 ) , '\0' , V_77 ) ;
}
static T_5 *
F_51 ( const T_5 * V_101 , void * F_52 ( T_3 ) )
{
T_13 V_6 ;
T_5 * V_102 ;
if( ! V_101 )
V_101 = L_56 ;
V_6 = ( T_13 ) strlen ( V_101 ) ;
V_102 = ( T_5 * ) memcpy ( F_52 ( V_6 + 1 ) , V_101 , V_6 + 1 ) ;
return V_102 ;
}
T_5 *
F_53 ( const T_5 * V_101 )
{
return F_51 ( V_101 , F_47 ) ;
}
static T_5 *
F_54 ( const T_5 * V_101 , T_3 V_6 , void * F_52 ( T_3 ) )
{
T_5 * V_102 = ( T_5 * ) F_52 ( V_6 + 1 ) ;
T_13 V_2 ;
for ( V_2 = 0 ; ( V_2 < V_6 ) && V_101 [ V_2 ] ; V_2 ++ )
V_102 [ V_2 ] = V_101 [ V_2 ] ;
V_102 [ V_2 ] = '\0' ;
return V_102 ;
}
T_5 *
F_55 ( const T_5 * V_101 , T_3 V_6 )
{
return F_54 ( V_101 , V_6 , F_47 ) ;
}
void *
F_56 ( const void * V_101 , T_3 V_6 )
{
return memcpy ( F_47 ( V_6 ) , V_101 , V_6 ) ;
}
static T_5 *
F_57 ( const T_5 * V_11 , T_4 V_12 , void * F_52 ( T_3 ) )
{
T_4 V_103 ;
T_8 V_6 ;
T_5 * V_102 ;
F_58 ( V_103 , V_12 ) ;
V_6 = F_59 ( V_11 , V_12 ) ;
V_102 = ( T_5 * ) F_52 ( V_6 + 1 ) ;
F_7 ( V_102 , ( V_104 ) V_6 , V_11 , V_103 ) ;
va_end ( V_103 ) ;
return V_102 ;
}
T_5 *
F_60 ( const T_5 * V_11 , T_4 V_12 )
{
return F_57 ( V_11 , V_12 , F_47 ) ;
}
T_5 *
F_61 ( const T_5 * V_11 , ... )
{
T_4 V_12 ;
T_5 * V_102 ;
va_start ( V_12 , V_11 ) ;
V_102 = F_60 ( V_11 , V_12 ) ;
va_end ( V_12 ) ;
return V_102 ;
}
T_5 * *
F_62 ( const T_5 * string , const T_5 * V_105 , int V_106 )
{
T_5 * V_107 ;
T_5 * V_108 ;
T_13 V_109 ;
T_13 V_110 ;
T_13 V_111 ;
T_13 V_2 ;
T_5 * * V_112 ;
enum { V_113 , V_114 , V_115 } V_116 ;
T_13 V_117 = 0 ;
if ( ! string
|| ! V_105
|| ! V_105 [ 0 ] )
return NULL ;
V_108 = V_107 = F_53 ( string ) ;
V_110 = ( T_13 ) strlen ( V_107 ) ;
V_111 = ( T_13 ) strlen ( V_105 ) ;
if ( V_106 < 1 ) V_106 = V_118 ;
V_109 = 1 ;
while ( V_109 <= ( T_13 ) V_106 && ( V_108 = strstr ( V_108 , V_105 ) ) ) {
V_109 ++ ;
for( V_2 = 0 ; V_2 < V_111 ; V_2 ++ )
V_108 [ V_2 ] = '\0' ;
V_108 += V_111 ;
}
V_112 = F_63 ( T_5 * , V_109 + 1 ) ;
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
F_64 ( const T_5 * V_119 , ... )
{
T_8 V_120 ;
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
V_121 = ( T_5 * ) F_47 ( V_120 ) ;
V_7 = V_121 ;
V_7 = F_65 ( V_7 , V_119 ) ;
va_start ( args , V_119 ) ;
V_108 = va_arg ( args , T_5 * ) ;
while ( V_108 ) {
V_7 = F_65 ( V_7 , V_108 ) ;
V_108 = va_arg ( args , T_5 * ) ;
}
va_end ( args ) ;
return V_121 ;
}
static void
F_66 ( T_7 * V_22 )
{
T_14 V_122 = V_22 -> V_24 ;
T_6 * V_15 ;
while( V_22 -> V_31 ) {
V_15 = V_22 -> V_31 ;
V_22 -> V_31 = V_22 -> V_31 -> V_19 ;
V_15 -> V_19 = V_22 -> V_18 ;
V_22 -> V_18 = V_15 ;
}
V_15 = V_22 -> V_18 ;
while ( V_15 != NULL ) {
if ( V_122 ) {
while ( V_15 -> V_21 != NULL ) {
V_15 -> V_21 = F_4 ( V_22 -> V_1 , ( T_1 * ) V_15 -> V_21 , NULL ) ;
if ( V_15 -> V_21 == ( void * ) - 1 )
F_8 ( L_32 ) ;
}
F_33 ( ( V_15 -> V_73 + V_15 -> V_74 ) ,
( V_15 -> V_75 - V_15 -> V_74 ) ,
FALSE ) ;
V_15 -> V_33 = V_15 -> V_32 ;
V_15 -> V_75 = V_15 -> V_74 ;
V_15 = V_15 -> V_19 ;
} else {
T_6 * V_19 = V_15 -> V_19 ;
F_33 ( V_15 -> V_73 , V_15 -> V_32 , FALSE ) ;
F_37 ( V_15 -> V_73 ) ;
F_37 ( V_15 ) ;
V_15 = V_19 ;
}
}
if ( ! V_122 ) {
V_22 -> V_18 = NULL ;
}
}
void
F_67 ( void )
{
F_66 ( & V_17 ) ;
}
void
F_68 ( void )
{
#ifdef F_41
F_29 () ;
#endif
F_66 ( & V_36 ) ;
}
static T_8
F_69 ( T_8 V_123 , T_8 V_124 , T_8 V_125 )
{
if ( V_125 < 1 || V_125 > V_126 ) {
V_125 = V_126 ;
}
if ( V_123 < 1 ) {
V_123 = V_127 ;
}
while ( V_123 < V_124 ) {
V_123 *= 2 ;
}
return V_123 < V_125 ? V_123 : V_125 ;
}
static void
F_70 ( T_16 * V_128 , T_8 V_124 )
{
T_8 V_129 ;
T_5 * V_130 ;
if ( ! V_128 || ( V_124 <= V_128 -> V_131 ) || ( V_128 -> V_131 >= V_128 -> V_125 ) ) {
return;
}
V_129 = F_69 ( V_128 -> V_131 , V_124 , V_128 -> V_125 ) ;
V_130 = ( T_5 * ) F_47 ( V_129 ) ;
F_9 ( V_130 , V_128 -> V_132 , V_129 ) ;
V_128 -> V_131 = V_129 ;
V_128 -> V_132 = V_130 ;
}
static T_16 *
F_71 ( T_8 V_131 , T_8 V_125 )
{
T_16 * V_128 ;
V_128 = F_72 ( T_16 ) ;
if ( ( V_125 == 0 ) || ( V_125 > V_126 ) )
V_125 = V_126 ;
if ( V_131 == 0 )
V_131 = 1 ;
else if ( V_131 > V_125 )
V_131 = V_125 ;
V_128 -> V_132 = ( char * ) F_47 ( V_131 ) ;
V_128 -> V_132 [ 0 ] = '\0' ;
V_128 -> V_6 = 0 ;
V_128 -> V_131 = V_131 ;
V_128 -> V_125 = V_125 ;
return V_128 ;
}
T_16 *
F_73 ( const T_5 * V_133 )
{
T_16 * V_128 ;
V_128 = F_71 ( F_69 ( 0 , V_133 ? strlen ( V_133 ) + 1 : 0 , 0 ) , 0 ) ;
if ( V_133 ) {
T_8 V_134 ;
V_134 = F_9 ( V_128 -> V_132 , V_133 , V_128 -> V_131 ) ;
V_128 -> V_6 = F_74 ( V_134 , V_128 -> V_131 - 1 ) ;
}
return V_128 ;
}
static void
F_75 ( T_16 * V_128 , const T_5 * V_135 , T_4 V_12 )
{
T_4 V_103 ;
T_8 V_136 , V_134 ;
F_58 ( V_103 , V_12 ) ;
V_136 = V_128 -> V_131 - V_128 -> V_6 ;
V_134 = F_7 ( & V_128 -> V_132 [ V_128 -> V_6 ] , ( V_104 ) V_136 , V_135 , V_12 ) ;
if ( V_134 < V_136 ) {
V_128 -> V_6 += V_134 ;
} else {
V_128 -> V_132 [ V_128 -> V_6 ] = '\0' ;
F_70 ( V_128 , V_128 -> V_6 + V_134 + 1 ) ;
V_136 = V_128 -> V_131 - V_128 -> V_6 ;
V_134 = F_7 ( & V_128 -> V_132 [ V_128 -> V_6 ] , ( V_104 ) V_136 , V_135 , V_103 ) ;
V_128 -> V_6 += F_74 ( V_136 - 1 , V_134 ) ;
}
va_end ( V_103 ) ;
}
void
F_76 ( T_16 * V_128 , const T_5 * V_135 , ... )
{
T_4 V_12 ;
va_start ( V_12 , V_135 ) ;
F_75 ( V_128 , V_135 , V_12 ) ;
va_end ( V_12 ) ;
}
void
F_77 ( T_16 * V_128 , const T_5 * V_135 , ... )
{
T_4 V_12 ;
if ( ! V_128 ) {
return;
}
V_128 -> V_6 = 0 ;
va_start ( V_12 , V_135 ) ;
F_75 ( V_128 , V_135 , V_12 ) ;
va_end ( V_12 ) ;
}
