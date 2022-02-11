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
V_16 = F_5 ( V_5 -> V_19 , L_1 ,
& V_20 ) ;
if ( V_16 ) {
F_6 ( V_5 , L_2 ) ;
return - V_21 ;
}
V_22 = 2 * V_20 ;
V_14 = F_7 ( V_23 * V_24 ) ;
V_15 = F_7 ( V_22 * V_25 ) ;
V_11 = F_8 ( V_5 , V_14 + V_15 ,
& V_12 , V_26 ) ;
if ( ! V_11 ) {
F_6 ( V_5 , L_3 ) ;
return - V_27 ;
}
F_9 ( ( ( unsigned long ) V_11 & ( V_28 - 1 ) ) != 0 ) ;
V_8 = F_10 ( V_11 , V_14 ) ;
if ( ! V_8 )
return - V_29 ;
V_8 -> V_30 [ V_31 ] =
( int ) V_12 + V_14 ;
V_8 -> V_30 [ V_32 ] =
V_25 ;
V_33 = ( char * ) V_11 + V_14 ;
V_14 += V_15 ;
V_34 = V_33 ;
for ( V_18 = 0 ; V_18 < ( V_25 - 1 ) ; V_18 ++ ) {
* ( char * * ) & V_33 [ V_18 * V_22 ] =
& V_33 [ ( V_18 + 1 ) * V_22 ] ;
}
* ( char * * ) & V_33 [ V_18 * V_22 ] = NULL ;
F_11 ( & V_35 , V_25 ) ;
if ( F_12 ( V_3 , V_8 , 0 ) != V_36 )
return - V_29 ;
V_10 = F_13 ( V_2 , V_37 , 0 ) ;
V_38 = F_14 ( & V_2 -> V_5 , V_10 ) ;
if ( F_15 ( V_38 ) )
return F_16 ( V_38 ) ;
V_17 = F_17 ( V_2 , 0 ) ;
if ( V_17 <= 0 ) {
F_6 ( V_5 , L_4 ) ;
return V_17 ;
}
V_16 = F_18 ( V_5 , V_17 , V_39 , V_40 ,
L_5 , V_3 ) ;
if ( V_16 ) {
F_6 ( V_5 , L_6 , V_17 ) ;
return V_16 ;
}
V_13 = V_12 ;
V_16 = F_19 ( V_7 , V_41 ,
& V_13 , sizeof( V_13 ) ) ;
if ( V_16 || V_13 ) {
F_6 ( V_5 , L_7 ) ;
return V_16 ? : - V_42 ;
}
V_43 = V_5 ;
F_20 ( V_44 ,
L_8 ,
V_8 , & V_12 ) ;
F_21 () ;
return 0 ;
}
T_5
F_22 ( T_1 * V_3 )
{
T_5 V_45 = V_36 ;
V_3 -> V_46 = F_23 ( sizeof( V_47 ) , V_26 ) ;
( ( V_47 * ) V_3 -> V_46 ) -> V_48 = 1 ;
V_45 = F_24 ( V_3 , & ( ( V_47 * ) V_3 -> V_46 ) -> V_49 ) ;
if ( V_45 != V_36 )
{
( ( V_47 * ) V_3 -> V_46 ) -> V_48 = 0 ;
}
return V_45 ;
}
T_6 *
F_25 ( T_1 * V_3 )
{
if ( ! ( ( V_47 * ) V_3 -> V_46 ) -> V_48 )
{
F_26 () ;
}
return & ( ( V_47 * ) V_3 -> V_46 ) -> V_49 ;
}
void
F_27 ( T_7 * V_50 )
{
F_28 () ;
V_50 -> V_51 = 1 ;
F_29 ( V_52 ) ;
if ( V_50 -> V_53 )
F_30 ( 0 , V_38 + V_54 ) ;
}
T_5
F_31 ( T_8 * V_55 , T_9 V_56 ,
void * V_57 , int V_58 , int V_59 )
{
struct V_60 * V_61 ;
F_9 ( V_56 != V_62 ) ;
V_61 = F_32 ( ( char V_63 * ) V_57 , V_58 ,
( V_59 == V_64 )
? V_65
: V_66 ,
V_67 ) ;
if ( ! V_61 )
return V_68 ;
V_55 -> V_69 = V_56 ;
V_55 -> V_70 = ( void * ) ( unsigned long ) V_61 -> V_71 ;
V_55 -> V_72 = V_61 ;
return V_36 ;
}
void
F_33 ( T_8 * V_55 )
{
if ( V_55 && V_55 -> V_72 && V_55 -> V_73 )
F_34 ( (struct V_60 * ) V_55 -> V_72 ,
V_55 -> V_73 ) ;
}
void
F_35 ( T_8 * V_55 )
{
F_26 () ;
}
void
F_36 ( void * V_74 )
{
char V_75 [ 80 ] ;
int V_76 ;
V_76 = snprintf ( V_75 , sizeof( V_75 ) ,
L_9 ) ;
F_37 ( V_74 , V_75 , V_76 + 1 ) ;
}
T_5
F_38 ( T_1 * V_3 )
{
return V_68 ;
}
T_5
F_39 ( T_1 * V_3 )
{
return V_36 ;
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
F_20 ( V_44 , L_10 ) ;
}
void
F_45 ( T_1 * V_3 )
{
( void ) V_3 ;
}
static T_10
V_39 ( int V_17 , void * V_77 )
{
T_1 * V_3 = V_77 ;
T_10 V_78 = V_79 ;
unsigned int V_45 ;
V_45 = F_46 ( V_38 + V_80 ) ;
if ( V_45 & 0x4 ) {
F_47 ( V_3 ) ;
V_78 = V_81 ;
}
return V_78 ;
}
static void
F_48 ( struct V_60 * V_61 )
{
if ( V_61 -> V_82 ) {
F_49 ( V_43 , V_61 -> V_83 ,
V_61 -> V_84 , V_61 -> V_85 ) ;
}
if ( V_61 -> V_86 ) {
unsigned int V_18 ;
for ( V_18 = 0 ; V_18 < V_61 -> V_84 ; V_18 ++ )
F_50 ( V_61 -> V_87 [ V_18 ] ) ;
}
F_51 ( V_43 , V_61 -> V_88 ,
V_61 -> V_89 , V_61 -> V_71 ) ;
}
static struct V_60 *
F_32 ( char V_63 * V_75 , T_11 V_90 , unsigned short type ,
struct V_91 * V_92 )
{
T_12 * V_89 ;
struct V_60 * V_61 ;
struct V_93 * * V_87 ;
T_4 * V_94 ;
unsigned int V_84 , V_57 , V_18 , V_95 ;
int V_96 ;
T_11 V_97 ;
struct V_83 * V_83 , * V_98 ;
int V_99 ;
T_3 V_71 ;
V_57 = ( ( unsigned int ) ( unsigned long ) V_75 & ( V_28 - 1 ) ) ;
V_84 = ( V_90 + V_57 + V_28 - 1 ) / V_28 ;
V_97 = sizeof( T_12 ) +
( V_84 * sizeof( T_4 ) ) +
( V_84 * sizeof( V_87 [ 0 ] ) +
( V_84 * sizeof( struct V_83 ) ) ) +
sizeof( struct V_60 ) ;
V_89 = F_52 ( V_43 ,
V_97 ,
& V_71 ,
V_26 ) ;
F_53 ( V_44 , L_11 ,
V_89 ) ;
if ( ! V_89 )
return NULL ;
V_94 = V_89 -> V_94 ;
V_87 = (struct V_93 * * ) ( V_94 + V_84 ) ;
V_83 = (struct V_83 * ) ( V_87 + V_84 ) ;
V_61 = (struct V_60 * )
( V_83 + V_84 ) ;
V_89 -> V_100 = V_90 ;
V_89 -> type = type ;
V_89 -> V_57 = V_57 ;
V_61 -> V_89 = V_89 ;
V_61 -> V_88 = V_97 ;
V_61 -> V_71 = V_71 ;
V_61 -> V_85 = ( type == V_66 ) ?
V_101 : V_102 ;
V_61 -> V_84 = V_84 ;
V_61 -> V_86 = 0 ;
V_61 -> V_87 = V_87 ;
V_61 -> V_83 = V_83 ;
V_61 -> V_82 = 0 ;
if ( F_54 ( V_75 ) ) {
unsigned long V_100 = V_90 ;
unsigned int V_103 = V_57 ;
for ( V_96 = 0 ; V_96 < V_84 ;
V_96 ++ ) {
struct V_93 * V_104 = F_55 ( V_75 + ( V_96 *
V_28 ) ) ;
T_11 V_105 = V_28 - V_103 ;
if ( V_105 > V_100 )
V_105 = V_100 ;
V_87 [ V_96 ] = V_104 ;
V_100 -= V_105 ;
V_103 = 0 ;
}
} else {
F_56 ( & V_92 -> V_106 -> V_107 ) ;
V_96 = F_57 (
( unsigned long ) V_75 & ~ ( V_28 - 1 ) ,
V_84 ,
( type == V_65 ) ? V_108 : 0 ,
V_87 ,
NULL ) ;
F_58 ( & V_92 -> V_106 -> V_107 ) ;
if ( V_96 != V_84 ) {
F_20 ( V_44 ,
L_12 ,
V_96 ,
V_84 ) ;
while ( V_96 > 0 )
{
V_96 -- ;
F_50 ( V_87 [ V_96 ] ) ;
}
F_48 ( V_61 ) ;
return NULL ;
}
V_61 -> V_86 = 1 ;
}
F_59 ( V_83 , V_84 ) ;
for ( V_18 = 0 ; V_18 < V_84 ; V_18 ++ )
F_60 ( V_83 + V_18 , V_87 [ V_18 ] , V_28 , 0 ) ;
V_99 = F_61 ( V_43 ,
V_83 ,
V_84 ,
V_61 -> V_85 ) ;
if ( V_99 == 0 ) {
F_48 ( V_61 ) ;
return NULL ;
}
V_61 -> V_82 = 1 ;
V_95 = 0 ;
F_62 (scatterlist, sg, dma_buffers, i) {
T_4 V_76 = F_63 ( V_98 ) ;
T_4 V_109 = F_64 ( V_98 ) ;
F_9 ( V_76 == 0 ) ;
F_9 ( V_76 & ~ V_110 ) ;
F_9 ( V_109 & ~ V_110 ) ;
if ( V_95 > 0 &&
( ( V_94 [ V_95 - 1 ] & V_110 ) |
( ( V_94 [ V_95 - 1 ] & ~ V_110 ) + 1 ) << V_111 )
== V_109 ) {
V_94 [ V_95 - 1 ] += ( V_76 >> V_111 ) ;
} else {
V_94 [ V_95 ++ ] = V_109 | ( ( V_76 >> V_111 ) - 1 ) ;
}
}
if ( ( type == V_65 ) &&
( ( V_89 -> V_57 & ( V_20 - 1 ) ) ||
( ( V_89 -> V_57 + V_89 -> V_100 ) &
( V_20 - 1 ) ) ) ) {
char * V_112 ;
if ( F_65 ( & V_35 ) != 0 ) {
F_48 ( V_61 ) ;
return NULL ;
}
F_9 ( V_34 == NULL ) ;
F_66 ( & V_113 ) ;
V_112 = V_34 ;
F_9 ( V_112 == NULL ) ;
V_34 = * ( char * * ) V_34 ;
F_67 ( & V_113 ) ;
V_89 -> type = V_114 +
( V_112 - V_33 ) / V_22 ;
}
return V_61 ;
}
static void
F_34 ( struct V_60 * V_61 ,
int V_73 )
{
unsigned int V_18 ;
T_12 * V_89 = V_61 -> V_89 ;
struct V_93 * * V_87 = V_61 -> V_87 ;
unsigned int V_84 = V_61 -> V_84 ;
F_53 ( V_44 , L_13 ,
V_61 -> V_89 , V_73 ) ;
F_49 ( V_43 , V_61 -> V_83 ,
V_61 -> V_84 , V_61 -> V_85 ) ;
V_61 -> V_82 = 0 ;
if ( V_89 -> type >= V_114 ) {
char * V_112 = V_33 +
( V_89 -> type - V_114 ) *
V_22 ;
int V_115 , V_116 ;
V_115 = ( V_20 - V_89 -> V_57 ) &
( V_20 - 1 ) ;
V_116 = ( V_89 -> V_57 + V_73 ) &
( V_20 - 1 ) ;
if ( ( V_73 >= 0 ) && ( V_115 != 0 ) ) {
if ( V_115 > V_73 )
V_115 = V_73 ;
memcpy ( ( char * ) F_68 ( V_87 [ 0 ] ) +
V_89 -> V_57 ,
V_112 ,
V_115 ) ;
}
if ( ( V_73 >= 0 ) && ( V_115 < V_73 ) &&
( V_116 != 0 ) ) {
memcpy ( ( char * ) F_68 ( V_87 [ V_84 - 1 ] ) +
( ( V_89 -> V_57 + V_73 ) &
( V_28 - 1 ) & ~ ( V_20 - 1 ) ) ,
V_112 + V_20 ,
V_116 ) ;
}
F_66 ( & V_113 ) ;
* ( char * * ) V_112 = V_34 ;
V_34 = V_112 ;
F_67 ( & V_113 ) ;
F_67 ( & V_35 ) ;
}
if ( V_89 -> type != V_66 &&
V_61 -> V_86 ) {
for ( V_18 = 0 ; V_18 < V_84 ; V_18 ++ )
F_69 ( V_87 [ V_18 ] ) ;
}
F_48 ( V_61 ) ;
}
