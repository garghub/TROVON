int F_1 ( struct V_1 * V_2 , T_1 * V_3 )
{
struct V_4 * V_5 = & V_2 -> V_5 ;
struct V_6 * V_7 = F_2 ( V_2 ) ;
T_2 * V_8 ;
struct V_9 * V_10 ;
void * V_11 ;
T_3 V_12 ;
T_4 V_13 ;
int V_14 , V_15 ;
int V_16 , V_17 , V_18 ;
V_16 = F_3 ( V_5 , F_4 ( 32 ) ) ;
if ( V_16 < 0 )
return V_16 ;
( void ) F_5 ( V_5 -> V_19 , L_1 ,
& V_20 ) ;
V_21 = 2 * V_20 ;
V_14 = F_6 ( V_22 * V_23 ) ;
V_15 = F_6 ( V_21 * V_24 ) ;
V_11 = F_7 ( V_5 , V_14 + V_15 ,
& V_12 , V_25 ) ;
if ( ! V_11 ) {
F_8 ( V_5 , L_2 ) ;
return - V_26 ;
}
F_9 ( ( ( unsigned long ) V_11 & ( V_27 - 1 ) ) != 0 ) ;
V_8 = F_10 ( V_11 , V_14 ) ;
if ( ! V_8 )
return - V_28 ;
V_8 -> V_29 [ V_30 ] =
( int ) V_12 + V_14 ;
V_8 -> V_29 [ V_31 ] =
V_24 ;
V_32 = ( char * ) V_11 + V_14 ;
V_14 += V_15 ;
V_33 = V_32 ;
for ( V_18 = 0 ; V_18 < ( V_24 - 1 ) ; V_18 ++ ) {
* ( char * * ) & V_32 [ V_18 * V_21 ] =
& V_32 [ ( V_18 + 1 ) * V_21 ] ;
}
* ( char * * ) & V_32 [ V_18 * V_21 ] = NULL ;
F_11 ( & V_34 , V_24 ) ;
if ( F_12 ( V_3 , V_8 , 0 ) != V_35 )
return - V_28 ;
V_10 = F_13 ( V_2 , V_36 , 0 ) ;
V_37 = F_14 ( & V_2 -> V_5 , V_10 ) ;
if ( F_15 ( V_37 ) )
return F_16 ( V_37 ) ;
V_17 = F_17 ( V_2 , 0 ) ;
if ( V_17 <= 0 ) {
F_8 ( V_5 , L_3 ) ;
return V_17 ;
}
V_16 = F_18 ( V_5 , V_17 , V_38 , V_39 ,
L_4 , V_3 ) ;
if ( V_16 ) {
F_8 ( V_5 , L_5 , V_17 ) ;
return V_16 ;
}
V_13 = V_12 ;
V_16 = F_19 ( V_7 , V_40 ,
& V_13 , sizeof( V_13 ) ) ;
if ( V_16 || V_13 ) {
F_8 ( V_5 , L_6 ) ;
return V_16 ? : - V_41 ;
}
V_42 = V_5 ;
F_20 ( V_43 ,
L_7 ,
V_8 , & V_12 ) ;
F_21 () ;
return 0 ;
}
T_5
F_22 ( T_1 * V_3 )
{
T_5 V_44 = V_35 ;
V_3 -> V_45 = F_23 ( sizeof( V_46 ) , V_25 ) ;
( ( V_46 * ) V_3 -> V_45 ) -> V_47 = 1 ;
V_44 = F_24 ( V_3 , & ( ( V_46 * ) V_3 -> V_45 ) -> V_48 ) ;
if( V_44 != V_35 )
{
( ( V_46 * ) V_3 -> V_45 ) -> V_47 = 0 ;
}
return V_44 ;
}
T_6 *
F_25 ( T_1 * V_3 )
{
if( ! ( ( V_46 * ) V_3 -> V_45 ) -> V_47 )
{
F_26 () ;
}
return & ( ( V_46 * ) V_3 -> V_45 ) -> V_48 ;
}
void
F_27 ( T_7 * V_49 )
{
F_28 () ;
V_49 -> V_50 = 1 ;
F_29 ( V_51 ) ;
if ( V_49 -> V_52 )
F_30 ( 0 , V_37 + V_53 ) ;
}
T_5
F_31 ( T_8 * V_54 , T_9 V_55 ,
void * V_56 , int V_57 , int V_58 )
{
struct V_59 * V_60 ;
F_9 ( V_55 != V_61 ) ;
V_60 = F_32 ( ( char V_62 * ) V_56 , V_57 ,
( V_58 == V_63 )
? V_64
: V_65 ,
V_66 ) ;
if ( ! V_60 )
return V_67 ;
V_54 -> V_68 = V_55 ;
V_54 -> V_69 = ( void * ) ( unsigned long ) V_60 -> V_70 ;
V_54 -> V_71 = V_60 ;
return V_35 ;
}
void
F_33 ( T_8 * V_54 )
{
if ( V_54 && V_54 -> V_71 && V_54 -> V_72 )
F_34 ( (struct V_59 * ) V_54 -> V_71 ,
V_54 -> V_72 ) ;
}
void
F_35 ( T_8 * V_54 )
{
F_26 () ;
}
void
F_36 ( void * V_73 )
{
char V_74 [ 80 ] ;
int V_75 ;
V_75 = snprintf ( V_74 , sizeof( V_74 ) ,
L_8 ) ;
F_37 ( V_73 , V_74 , V_75 + 1 ) ;
}
T_5
F_38 ( T_1 * V_3 )
{
return V_67 ;
}
T_5
F_39 ( T_1 * V_3 )
{
return V_35 ;
}
void
F_40 ( T_1 * V_3 )
{
}
void
F_41 ( T_1 * V_3 )
{
}
int
F_42 ( T_1 * V_3 )
{
return 1 ;
}
int
F_43 ( void )
{
return 0 ;
}
void
F_44 ( T_1 * V_3 )
{
F_20 ( V_43 , L_9 ) ;
}
void
F_45 ( T_1 * V_3 )
{
( void ) V_3 ;
}
static T_10
V_38 ( int V_17 , void * V_76 )
{
T_1 * V_3 = V_76 ;
T_10 V_77 = V_78 ;
unsigned int V_44 ;
V_44 = F_46 ( V_37 + V_79 ) ;
if ( V_44 & 0x4 ) {
F_47 ( V_3 ) ;
V_77 = V_80 ;
}
return V_77 ;
}
static void
F_48 ( struct V_59 * V_60 )
{
if ( V_60 -> V_81 ) {
F_49 ( V_42 , V_60 -> V_82 ,
V_60 -> V_83 , V_60 -> V_84 ) ;
}
if ( V_60 -> V_85 ) {
unsigned int V_18 ;
for ( V_18 = 0 ; V_18 < V_60 -> V_83 ; V_18 ++ )
F_50 ( V_60 -> V_86 [ V_18 ] ) ;
}
F_51 ( V_42 , V_60 -> V_87 ,
V_60 -> V_88 , V_60 -> V_70 ) ;
}
static struct V_59 *
F_32 ( char V_62 * V_74 , T_11 V_89 , unsigned short type ,
struct V_90 * V_91 )
{
T_12 * V_88 ;
struct V_59 * V_60 ;
struct V_92 * * V_86 ;
T_4 * V_93 ;
unsigned int V_83 , V_56 , V_18 , V_94 ;
int V_95 ;
T_11 V_96 ;
struct V_82 * V_82 , * V_97 ;
int V_98 ;
T_3 V_70 ;
V_56 = ( ( unsigned int ) ( unsigned long ) V_74 & ( V_27 - 1 ) ) ;
V_83 = ( V_89 + V_56 + V_27 - 1 ) / V_27 ;
V_96 = sizeof( T_12 ) +
( V_83 * sizeof( T_4 ) ) +
( V_83 * sizeof( V_86 [ 0 ] ) +
( V_83 * sizeof( struct V_82 ) ) ) +
sizeof( struct V_59 ) ;
V_88 = F_52 ( V_42 ,
V_96 ,
& V_70 ,
V_25 ) ;
F_53 ( V_43 , L_10 ,
V_88 ) ;
if ( ! V_88 )
return NULL ;
V_93 = V_88 -> V_93 ;
V_86 = (struct V_92 * * ) ( V_93 + V_83 ) ;
V_82 = (struct V_82 * ) ( V_86 + V_83 ) ;
V_60 = (struct V_59 * )
( V_82 + V_83 ) ;
V_88 -> V_99 = V_89 ;
V_88 -> type = type ;
V_88 -> V_56 = V_56 ;
V_60 -> V_88 = V_88 ;
V_60 -> V_87 = V_96 ;
V_60 -> V_70 = V_70 ;
V_60 -> V_84 = ( type == V_65 ) ?
V_100 : V_101 ;
V_60 -> V_83 = V_83 ;
V_60 -> V_85 = 0 ;
V_60 -> V_86 = V_86 ;
V_60 -> V_82 = V_82 ;
V_60 -> V_81 = 0 ;
if ( F_54 ( V_74 ) ) {
unsigned long V_99 = V_89 ;
unsigned int V_102 = V_56 ;
for ( V_95 = 0 ; V_95 < V_83 ;
V_95 ++ ) {
struct V_92 * V_103 = F_55 ( V_74 + ( V_95 *
V_27 ) ) ;
T_11 V_104 = V_27 - V_102 ;
if ( V_104 > V_99 )
V_104 = V_99 ;
V_86 [ V_95 ] = V_103 ;
V_99 -= V_104 ;
V_102 = 0 ;
}
} else {
F_56 ( & V_91 -> V_105 -> V_106 ) ;
V_95 = F_57 (
( unsigned long ) V_74 & ~ ( V_27 - 1 ) ,
V_83 ,
( type == V_64 ) ? V_107 : 0 ,
V_86 ,
NULL ) ;
F_58 ( & V_91 -> V_105 -> V_106 ) ;
if ( V_95 != V_83 ) {
F_20 ( V_43 ,
L_11 ,
V_95 ,
V_83 ) ;
while ( V_95 > 0 )
{
V_95 -- ;
F_50 ( V_86 [ V_95 ] ) ;
}
F_48 ( V_60 ) ;
return NULL ;
}
V_60 -> V_85 = 1 ;
}
F_59 ( V_82 , V_83 ) ;
for ( V_18 = 0 ; V_18 < V_83 ; V_18 ++ )
F_60 ( V_82 + V_18 , V_86 [ V_18 ] , V_27 , 0 ) ;
V_98 = F_61 ( V_42 ,
V_82 ,
V_83 ,
V_60 -> V_84 ) ;
if ( V_98 == 0 ) {
F_48 ( V_60 ) ;
return NULL ;
}
V_60 -> V_81 = 1 ;
V_94 = 0 ;
F_62 (scatterlist, sg, dma_buffers, i) {
T_4 V_75 = F_63 ( V_97 ) ;
T_4 V_108 = F_64 ( V_97 ) ;
F_9 ( V_75 == 0 ) ;
F_9 ( V_75 & ~ V_109 ) ;
F_9 ( V_108 & ~ V_109 ) ;
if ( V_94 > 0 &&
( ( V_93 [ V_94 - 1 ] & V_109 ) |
( ( V_93 [ V_94 - 1 ] & ~ V_109 ) + 1 ) << V_110 )
== V_108 ) {
V_93 [ V_94 - 1 ] += ( V_75 >> V_110 ) ;
} else {
V_93 [ V_94 ++ ] = V_108 | ( ( V_75 >> V_110 ) - 1 ) ;
}
}
if ( ( type == V_64 ) &&
( ( V_88 -> V_56 & ( V_20 - 1 ) ) ||
( ( V_88 -> V_56 + V_88 -> V_99 ) &
( V_20 - 1 ) ) ) ) {
char * V_111 ;
if ( F_65 ( & V_34 ) != 0 ) {
F_48 ( V_60 ) ;
return NULL ;
}
F_9 ( V_33 == NULL ) ;
F_66 ( & V_112 ) ;
V_111 = V_33 ;
F_9 ( V_111 == NULL ) ;
V_33 = * ( char * * ) V_33 ;
F_67 ( & V_112 ) ;
V_88 -> type = V_113 +
( V_111 - V_32 ) / V_21 ;
}
return V_60 ;
}
static void
F_34 ( struct V_59 * V_60 ,
int V_72 )
{
unsigned int V_18 ;
T_12 * V_88 = V_60 -> V_88 ;
struct V_92 * * V_86 = V_60 -> V_86 ;
unsigned int V_83 = V_60 -> V_83 ;
F_53 ( V_43 , L_12 ,
V_60 -> V_88 , V_72 ) ;
F_49 ( V_42 , V_60 -> V_82 ,
V_60 -> V_83 , V_60 -> V_84 ) ;
V_60 -> V_81 = 0 ;
if ( V_88 -> type >= V_113 ) {
char * V_111 = V_32 +
( V_88 -> type - V_113 ) *
V_21 ;
int V_114 , V_115 ;
V_114 = ( V_20 - V_88 -> V_56 ) &
( V_20 - 1 ) ;
V_115 = ( V_88 -> V_56 + V_72 ) &
( V_20 - 1 ) ;
if ( ( V_72 >= 0 ) && ( V_114 != 0 ) ) {
if ( V_114 > V_72 )
V_114 = V_72 ;
memcpy ( ( char * ) F_68 ( V_86 [ 0 ] ) +
V_88 -> V_56 ,
V_111 ,
V_114 ) ;
}
if ( ( V_72 >= 0 ) && ( V_114 < V_72 ) &&
( V_115 != 0 ) ) {
memcpy ( ( char * ) F_68 ( V_86 [ V_83 - 1 ] ) +
( ( V_88 -> V_56 + V_72 ) &
( V_27 - 1 ) & ~ ( V_20 - 1 ) ) ,
V_111 + V_20 ,
V_115 ) ;
}
F_66 ( & V_112 ) ;
* ( char * * ) V_111 = V_33 ;
V_33 = V_111 ;
F_67 ( & V_112 ) ;
F_67 ( & V_34 ) ;
}
if ( V_88 -> type != V_65 &&
V_60 -> V_85 ) {
for ( V_18 = 0 ; V_18 < V_83 ; V_18 ++ )
F_69 ( V_86 [ V_18 ] ) ;
}
F_48 ( V_60 ) ;
}
