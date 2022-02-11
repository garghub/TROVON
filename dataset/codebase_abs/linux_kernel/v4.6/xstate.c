void F_1 ( void )
{
F_2 ( V_1 ) ;
F_2 ( V_2 ) ;
F_2 ( V_3 ) ;
F_2 ( V_4 ) ;
F_2 ( V_5 ) ;
F_2 ( V_6 ) ;
F_2 ( V_7 ) ;
F_2 ( V_8 ) ;
F_2 ( V_9 ) ;
F_2 ( V_10 ) ;
F_2 ( V_11 ) ;
F_2 ( V_12 ) ;
F_2 ( V_13 ) ;
F_2 ( V_14 ) ;
F_2 ( V_15 ) ;
F_2 ( V_16 ) ;
}
int F_3 ( T_1 V_17 , const char * * V_18 )
{
T_1 V_19 = V_17 & ~ V_20 ;
if ( F_4 ( V_18 ) ) {
long V_21 , V_22 ;
T_1 V_23 ;
if ( V_19 )
V_23 = V_19 ;
else
V_23 = V_17 ;
V_21 = F_5 ( V_23 ) - 1 ;
V_22 = F_6 ( V_24 ) - 1 ;
V_21 = F_7 ( V_21 , V_22 ) ;
* V_18 = V_24 [ V_21 ] ;
}
if ( V_19 )
return 0 ;
return 1 ;
}
void F_8 ( struct V_25 * V_25 )
{
struct V_26 * V_27 = & V_25 -> V_28 . V_29 ;
int V_30 ;
T_1 V_31 ;
if ( ! F_9 () )
return;
V_31 = V_25 -> V_28 . V_32 . V_33 . V_31 ;
if ( ( V_31 & V_20 ) == V_20 )
return;
if ( ! ( V_31 & V_34 ) ) {
V_27 -> V_35 = 0x37f ;
V_27 -> V_36 = 0 ;
V_27 -> V_37 = 0 ;
V_27 -> V_38 = 0 ;
V_27 -> V_39 = 0 ;
V_27 -> V_40 = 0 ;
memset ( & V_27 -> V_41 [ 0 ] , 0 , 128 ) ;
}
if ( ! ( V_31 & V_42 ) )
memset ( & V_27 -> V_43 [ 0 ] , 0 , 256 ) ;
V_30 = 0x2 ;
V_31 = ( V_20 & ~ V_31 ) >> 2 ;
while ( V_31 ) {
if ( V_31 & 0x1 ) {
int V_44 = V_45 [ V_30 ] ;
int V_46 = V_47 [ V_30 ] ;
memcpy ( ( void * ) V_27 + V_44 ,
( void * ) & V_48 . V_32 + V_44 ,
V_46 ) ;
}
V_31 >>= 1 ;
V_30 ++ ;
}
}
void F_10 ( void )
{
if ( ! V_49 || ! V_20 )
return;
F_11 ( V_50 ) ;
F_12 ( V_51 , V_20 ) ;
}
static int F_13 ( enum V_52 V_52 )
{
return ! ! ( V_20 & ( 1UL << V_52 ) ) ;
}
static void T_2 F_14 ( void )
{
T_3 V_53 , V_54 , V_55 , V_56 , V_57 ;
unsigned int V_58 = F_15 ( struct V_59 ,
V_60 ) ;
for ( V_57 = V_61 ; V_57 < V_62 ; V_57 ++ ) {
if ( ! F_13 ( V_57 ) )
continue;
F_16 ( V_63 , V_57 , & V_53 , & V_54 , & V_55 , & V_56 ) ;
V_45 [ V_57 ] = V_54 ;
V_47 [ V_57 ] = V_53 ;
F_17 ( V_58 > V_45 [ V_57 ] ,
L_1 , V_58 ) ;
V_58 = V_45 [ V_57 ] ;
F_18 ( V_64 L_2 , V_57 , V_54 , V_57 , V_53 ) ;
}
}
static void T_2 F_19 ( T_1 V_65 )
{
const char * V_18 ;
if ( F_3 ( V_65 , & V_18 ) )
F_20 ( L_3 , V_65 , V_18 ) ;
}
static void T_2 F_21 ( void )
{
F_19 ( V_34 ) ;
F_19 ( V_42 ) ;
F_19 ( V_66 ) ;
F_19 ( V_67 ) ;
F_19 ( V_68 ) ;
F_19 ( V_69 ) ;
F_19 ( V_70 ) ;
F_19 ( V_71 ) ;
F_19 ( V_72 ) ;
}
static void T_2 F_22 ( void )
{
unsigned int V_73 [ sizeof( V_20 ) * 8 ] ;
int V_57 ;
V_74 [ 0 ] = 0 ;
V_74 [ 1 ] = F_15 ( struct V_26 , V_43 ) ;
if ( ! V_75 ) {
for ( V_57 = V_61 ; V_57 < V_62 ; V_57 ++ ) {
if ( F_13 ( V_57 ) ) {
V_74 [ V_57 ] = V_45 [ V_57 ] ;
V_73 [ V_57 ] = V_47 [ V_57 ] ;
}
}
return;
}
V_74 [ V_61 ] =
V_76 + V_77 ;
for ( V_57 = V_61 ; V_57 < V_62 ; V_57 ++ ) {
if ( F_13 ( V_57 ) )
V_73 [ V_57 ] = V_47 [ V_57 ] ;
else
V_73 [ V_57 ] = 0 ;
if ( V_57 > V_61 )
V_74 [ V_57 ] = V_74 [ V_57 - 1 ]
+ V_73 [ V_57 - 1 ] ;
}
}
static void T_2 F_23 ( void )
{
static int T_4 V_78 = 1 ;
F_24 ( ! T_4 ) ;
T_4 = 0 ;
if ( ! V_49 )
return;
F_14 () ;
F_21 () ;
if ( V_75 ) {
V_48 . V_32 . V_33 . V_79 = ( T_1 ) 1 << 63 | V_20 ;
V_48 . V_32 . V_33 . V_31 = V_20 ;
}
F_25 ( & V_48 . V_32 ) ;
F_26 ( & V_48 . V_32 ) ;
}
static int F_27 ( int V_80 )
{
return 0 ;
}
static int F_28 ( int V_80 )
{
T_3 V_53 , V_54 , V_55 , V_56 ;
F_29 ( V_80 ) ;
F_16 ( V_63 , V_80 , & V_53 , & V_54 , & V_55 , & V_56 ) ;
return ! ! ( V_55 & 2 ) ;
}
static int F_30 ( int V_80 )
{
T_3 V_53 , V_54 , V_55 , V_56 ;
F_29 ( V_80 ) ;
F_16 ( V_63 , V_80 , & V_53 , & V_54 , & V_55 , & V_56 ) ;
return V_54 ;
}
static int F_31 ( int V_80 )
{
T_3 V_53 , V_54 , V_55 , V_56 ;
F_29 ( V_80 ) ;
F_16 ( V_63 , V_80 , & V_53 , & V_54 , & V_55 , & V_56 ) ;
return V_53 ;
}
static int F_32 ( void )
{
return V_75 ;
}
static void F_33 ( void )
{
int V_57 ;
T_3 V_53 , V_54 , V_55 , V_56 ;
static int V_81 = 1 ;
if ( ! V_81 )
return;
V_81 = 0 ;
for ( V_57 = 0 ; V_57 < V_62 + 10 ; V_57 ++ ) {
F_16 ( V_63 , V_57 , & V_53 , & V_54 , & V_55 , & V_56 ) ;
F_34 ( L_4 ,
V_63 , V_57 , V_53 , V_54 , V_55 , V_56 ) ;
}
}
static void F_35 ( int V_82 )
{
int V_83 = F_31 ( V_82 ) ;
F_36 ( V_83 , V_82 , V_84 , struct V_85 ) ;
F_36 ( V_83 , V_82 , V_86 , struct V_87 ) ;
F_36 ( V_83 , V_82 , V_88 , struct V_89 ) ;
F_36 ( V_83 , V_82 , V_90 , struct V_91 ) ;
F_36 ( V_83 , V_82 , V_92 , struct V_93 ) ;
F_36 ( V_83 , V_82 , V_94 , struct V_95 ) ;
F_36 ( V_83 , V_82 , V_96 , struct V_97 ) ;
if ( ( V_82 < V_84 ) ||
( V_82 >= V_62 ) ||
( V_82 == V_98 ) ) {
F_17 ( 1 , L_5 , V_82 ) ;
F_37 ( 1 ) ;
}
}
static void F_38 ( void )
{
int V_99 = V_76 + V_77 ;
int V_57 ;
for ( V_57 = V_61 ; V_57 < V_62 ; V_57 ++ ) {
if ( ! F_13 ( V_57 ) )
continue;
F_35 ( V_57 ) ;
if ( ! F_32 () )
F_37 ( F_27 ( V_57 ) ) ;
if ( F_28 ( V_57 ) )
V_99 = F_39 ( V_99 , 64 ) ;
if ( ! F_32 () )
V_99 = F_30 ( V_57 ) ;
V_99 += F_31 ( V_57 ) ;
}
F_37 ( V_99 != V_100 ) ;
}
static unsigned int T_2 F_40 ( void )
{
unsigned int V_53 , V_54 , V_55 , V_56 ;
unsigned int V_101 ;
if ( ! V_75 ) {
F_16 ( V_63 , 0 , & V_53 , & V_54 , & V_55 , & V_56 ) ;
V_101 = V_54 ;
} else {
F_16 ( V_63 , 1 , & V_53 , & V_54 , & V_55 , & V_56 ) ;
V_101 = V_54 ;
}
return V_101 ;
}
static bool F_41 ( unsigned int V_102 )
{
if ( V_102 <= sizeof( union V_103 ) )
return true ;
F_34 ( L_6 ,
sizeof( union V_103 ) , V_102 ) ;
return false ;
}
static int F_42 ( void )
{
unsigned int V_104 = F_40 () ;
if ( ! F_41 ( V_104 ) )
return - V_105 ;
V_100 = V_104 ;
F_38 () ;
return 0 ;
}
static void F_43 ( void )
{
V_20 = 0 ;
F_44 ( V_50 ) ;
F_1 () ;
}
void T_2 F_45 ( void )
{
unsigned int V_53 , V_54 , V_55 , V_56 ;
static int T_4 V_78 = 1 ;
int V_106 ;
F_24 ( ! T_4 ) ;
T_4 = 0 ;
if ( ! V_49 ) {
F_20 ( L_7 ) ;
return;
}
if ( V_107 . V_108 < V_63 ) {
F_24 ( 1 ) ;
return;
}
F_16 ( V_63 , 0 , & V_53 , & V_54 , & V_55 , & V_56 ) ;
V_20 = V_53 + ( ( T_1 ) V_56 << 32 ) ;
if ( ( V_20 & V_109 ) != V_109 ) {
F_46 ( L_8 , V_20 ) ;
F_47 () ;
}
V_20 &= F_48 () ;
F_10 () ;
V_106 = F_42 () ;
if ( V_106 ) {
F_43 () ;
return;
}
F_49 ( V_100 , V_20 ) ;
F_50 () ;
F_23 () ;
F_22 () ;
F_20 ( L_9 ,
V_20 ,
V_100 ,
V_75 ? L_10 : L_11 ) ;
}
void F_51 ( void )
{
if ( V_49 )
F_12 ( V_51 , V_20 ) ;
}
void * F_52 ( struct V_59 * V_32 , int V_110 )
{
int V_111 = F_5 ( V_110 ) - 1 ;
return ( void * ) V_32 + V_74 [ V_111 ] ;
}
void * F_53 ( struct V_59 * V_32 , int V_112 )
{
if ( ! F_54 ( V_1 ) )
return NULL ;
F_17 ( ! ( V_20 & V_112 ) ,
L_12 ) ;
if ( ! ( V_32 -> V_33 . V_31 & V_112 ) )
return NULL ;
return F_52 ( V_32 , V_112 ) ;
}
const void * F_55 ( int V_113 )
{
struct V_25 * V_25 = & V_114 -> V_115 . V_25 ;
if ( ! V_25 -> V_116 )
return NULL ;
F_56 ( V_25 ) ;
return F_53 ( & V_25 -> V_28 . V_32 , V_113 ) ;
}
static void F_57 ( struct V_59 * V_32 ,
int V_110 )
{
V_32 -> V_33 . V_31 |= V_110 ;
}
static void F_58 ( int V_110 ,
void * V_117 , T_5 V_118 )
{
struct V_59 * V_32 = & V_114 -> V_115 . V_25 . V_28 . V_32 ;
struct V_25 * V_25 = & V_114 -> V_115 . V_25 ;
void * V_119 ;
if ( ! F_54 ( V_1 ) ) {
F_17 ( 1 , L_13 , V_120 ) ;
return;
}
F_59 () ;
if ( V_32 -> V_33 . V_79 & V_110 ) {
F_60 ( 1 ) ;
goto V_121;
}
V_119 = F_52 ( & V_25 -> V_28 . V_32 , V_110 ) ;
F_17 ( V_117 == V_119 , L_14 ) ;
memcpy ( V_119 , V_117 , V_118 ) ;
F_57 ( V_32 , V_110 ) ;
V_121:
F_61 () ;
}
int F_62 ( struct V_122 * V_123 , int V_124 ,
unsigned long V_125 )
{
struct V_59 * V_32 = & V_123 -> V_115 . V_25 . V_28 . V_32 ;
struct V_97 * V_126 ;
struct V_97 V_127 ;
int V_128 = ( V_124 * V_129 ) ;
T_3 V_130 = 0 ;
if ( ! F_54 ( V_131 ) )
return - V_105 ;
if ( V_125 & V_132 )
V_130 |= V_133 ;
if ( V_125 & V_134 )
V_130 |= V_135 ;
V_130 <<= V_128 ;
V_126 = F_53 ( V_32 , V_72 ) ;
if ( ! V_126 )
V_127 . V_136 = 0 ;
else
V_127 . V_136 = V_126 -> V_136 ;
V_127 . V_136 &= ~ ( ( V_133 | V_135 ) << V_128 ) ;
V_127 . V_136 |= V_130 ;
V_127 . V_137 = 0 ;
F_58 ( V_72 , & V_127 ,
sizeof( V_127 ) ) ;
return 0 ;
}
