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
if ( ! F_11 ( V_1 ) || ! V_20 )
return;
F_12 ( V_49 ) ;
F_13 ( V_50 , V_20 ) ;
}
static int F_14 ( enum V_51 V_51 )
{
return ! ! ( V_20 & ( 1UL << V_51 ) ) ;
}
static void T_2 F_15 ( void )
{
T_3 V_52 , V_53 , V_54 , V_55 , V_56 ;
unsigned int V_57 = F_16 ( struct V_58 ,
V_59 ) ;
for ( V_56 = V_60 ; V_56 < V_61 ; V_56 ++ ) {
if ( ! F_14 ( V_56 ) )
continue;
F_17 ( V_62 , V_56 , & V_52 , & V_53 , & V_54 , & V_55 ) ;
V_45 [ V_56 ] = V_53 ;
V_47 [ V_56 ] = V_52 ;
F_18 ( V_57 > V_45 [ V_56 ] ,
L_1 , V_57 ) ;
V_57 = V_45 [ V_56 ] ;
F_19 ( V_63 L_2 , V_56 , V_53 , V_56 , V_52 ) ;
}
}
static void T_2 F_20 ( T_1 V_64 )
{
const char * V_18 ;
if ( F_3 ( V_64 , & V_18 ) )
F_21 ( L_3 , V_64 , V_18 ) ;
}
static void T_2 F_22 ( void )
{
F_20 ( V_34 ) ;
F_20 ( V_42 ) ;
F_20 ( V_65 ) ;
F_20 ( V_66 ) ;
F_20 ( V_67 ) ;
F_20 ( V_68 ) ;
F_20 ( V_69 ) ;
F_20 ( V_70 ) ;
F_20 ( V_71 ) ;
}
static void T_2 F_23 ( void )
{
unsigned int V_72 [ sizeof( V_20 ) * 8 ] ;
int V_56 ;
V_73 [ 0 ] = 0 ;
V_73 [ 1 ] = F_16 ( struct V_26 , V_43 ) ;
if ( ! F_11 ( V_4 ) ) {
for ( V_56 = V_60 ; V_56 < V_61 ; V_56 ++ ) {
if ( F_14 ( V_56 ) ) {
V_73 [ V_56 ] = V_45 [ V_56 ] ;
V_72 [ V_56 ] = V_47 [ V_56 ] ;
}
}
return;
}
V_73 [ V_60 ] =
V_74 + V_75 ;
for ( V_56 = V_60 ; V_56 < V_61 ; V_56 ++ ) {
if ( F_14 ( V_56 ) )
V_72 [ V_56 ] = V_47 [ V_56 ] ;
else
V_72 [ V_56 ] = 0 ;
if ( V_56 > V_60 )
V_73 [ V_56 ] = V_73 [ V_56 - 1 ]
+ V_72 [ V_56 - 1 ] ;
}
}
static void T_2 F_24 ( void )
{
static int T_4 V_76 = 1 ;
F_25 ( ! T_4 ) ;
T_4 = 0 ;
if ( ! F_11 ( V_1 ) )
return;
F_15 () ;
F_22 () ;
if ( F_11 ( V_4 ) ) {
V_48 . V_32 . V_33 . V_77 = ( T_1 ) 1 << 63 | V_20 ;
V_48 . V_32 . V_33 . V_31 = V_20 ;
}
F_26 ( & V_48 . V_32 ) ;
F_27 ( & V_48 . V_32 ) ;
}
static int F_28 ( int V_78 )
{
return 0 ;
}
static int F_29 ( int V_78 )
{
T_3 V_52 , V_53 , V_54 , V_55 ;
F_30 ( V_78 ) ;
F_17 ( V_62 , V_78 , & V_52 , & V_53 , & V_54 , & V_55 ) ;
return ! ! ( V_54 & 2 ) ;
}
static int F_31 ( int V_78 )
{
T_3 V_52 , V_53 , V_54 , V_55 ;
F_30 ( V_78 ) ;
F_17 ( V_62 , V_78 , & V_52 , & V_53 , & V_54 , & V_55 ) ;
return V_53 ;
}
static int F_32 ( int V_78 )
{
T_3 V_52 , V_53 , V_54 , V_55 ;
F_30 ( V_78 ) ;
F_17 ( V_62 , V_78 , & V_52 , & V_53 , & V_54 , & V_55 ) ;
return V_52 ;
}
static int F_33 ( void )
{
return F_11 ( V_4 ) ;
}
static void F_34 ( void )
{
int V_56 ;
T_3 V_52 , V_53 , V_54 , V_55 ;
static int V_79 = 1 ;
if ( ! V_79 )
return;
V_79 = 0 ;
for ( V_56 = 0 ; V_56 < V_61 + 10 ; V_56 ++ ) {
F_17 ( V_62 , V_56 , & V_52 , & V_53 , & V_54 , & V_55 ) ;
F_35 ( L_4 ,
V_62 , V_56 , V_52 , V_53 , V_54 , V_55 ) ;
}
}
static void F_36 ( int V_80 )
{
int V_81 = F_32 ( V_80 ) ;
F_37 ( V_81 , V_80 , V_82 , struct V_83 ) ;
F_37 ( V_81 , V_80 , V_84 , struct V_85 ) ;
F_37 ( V_81 , V_80 , V_86 , struct V_87 ) ;
F_37 ( V_81 , V_80 , V_88 , struct V_89 ) ;
F_37 ( V_81 , V_80 , V_90 , struct V_91 ) ;
F_37 ( V_81 , V_80 , V_92 , struct V_93 ) ;
F_37 ( V_81 , V_80 , V_94 , struct V_95 ) ;
if ( ( V_80 < V_82 ) ||
( V_80 >= V_61 ) ||
( V_80 == V_96 ) ) {
F_18 ( 1 , L_5 , V_80 ) ;
F_38 ( 1 ) ;
}
}
static void F_39 ( void )
{
int V_97 = V_74 + V_75 ;
int V_56 ;
for ( V_56 = V_60 ; V_56 < V_61 ; V_56 ++ ) {
if ( ! F_14 ( V_56 ) )
continue;
F_36 ( V_56 ) ;
if ( ! F_33 () )
F_38 ( F_28 ( V_56 ) ) ;
if ( F_29 ( V_56 ) )
V_97 = F_40 ( V_97 , 64 ) ;
if ( ! F_33 () )
V_97 = F_31 ( V_56 ) ;
V_97 += F_32 ( V_56 ) ;
}
F_38 ( V_97 != V_98 ) ;
}
static unsigned int T_2 F_41 ( void )
{
unsigned int V_52 , V_53 , V_54 , V_55 ;
unsigned int V_99 ;
if ( ! F_11 ( V_4 ) ) {
F_17 ( V_62 , 0 , & V_52 , & V_53 , & V_54 , & V_55 ) ;
V_99 = V_53 ;
} else {
F_17 ( V_62 , 1 , & V_52 , & V_53 , & V_54 , & V_55 ) ;
V_99 = V_53 ;
}
return V_99 ;
}
static bool F_42 ( unsigned int V_100 )
{
if ( V_100 <= sizeof( union V_101 ) )
return true ;
F_35 ( L_6 ,
sizeof( union V_101 ) , V_100 ) ;
return false ;
}
static int F_43 ( void )
{
unsigned int V_102 = F_41 () ;
if ( ! F_42 ( V_102 ) )
return - V_103 ;
V_98 = V_102 ;
F_39 () ;
return 0 ;
}
static void F_44 ( void )
{
V_20 = 0 ;
F_45 ( V_49 ) ;
F_1 () ;
}
void T_2 F_46 ( void )
{
unsigned int V_52 , V_53 , V_54 , V_55 ;
static int T_4 V_76 = 1 ;
int V_104 ;
F_25 ( ! T_4 ) ;
T_4 = 0 ;
if ( ! F_11 ( V_1 ) ) {
F_21 ( L_7 ) ;
return;
}
if ( V_105 . V_106 < V_62 ) {
F_25 ( 1 ) ;
return;
}
F_17 ( V_62 , 0 , & V_52 , & V_53 , & V_54 , & V_55 ) ;
V_20 = V_52 + ( ( T_1 ) V_55 << 32 ) ;
if ( ( V_20 & V_107 ) != V_107 ) {
F_47 ( L_8 , V_20 ) ;
F_48 () ;
}
V_20 &= F_49 () ;
F_10 () ;
V_104 = F_43 () ;
if ( V_104 ) {
F_44 () ;
return;
}
F_50 ( V_98 , V_20 ) ;
F_51 () ;
F_24 () ;
F_23 () ;
F_21 ( L_9 ,
V_20 ,
V_98 ,
F_11 ( V_4 ) ? L_10 : L_11 ) ;
}
void F_52 ( void )
{
if ( F_11 ( V_1 ) )
F_13 ( V_50 , V_20 ) ;
}
void * F_53 ( struct V_58 * V_32 , int V_108 )
{
int V_109 = F_5 ( V_108 ) - 1 ;
return ( void * ) V_32 + V_73 [ V_109 ] ;
}
void * F_54 ( struct V_58 * V_32 , int V_110 )
{
if ( ! F_11 ( V_1 ) )
return NULL ;
F_18 ( ! ( V_20 & V_110 ) ,
L_12 ) ;
if ( ! ( V_32 -> V_33 . V_31 & V_110 ) )
return NULL ;
return F_53 ( V_32 , V_110 ) ;
}
const void * F_55 ( int V_111 )
{
struct V_25 * V_25 = & V_112 -> V_113 . V_25 ;
if ( ! V_25 -> V_114 )
return NULL ;
F_56 ( V_25 ) ;
return F_54 ( & V_25 -> V_28 . V_32 , V_111 ) ;
}
static void F_57 ( struct V_58 * V_32 ,
int V_108 )
{
V_32 -> V_33 . V_31 |= V_108 ;
}
static void F_58 ( int V_108 ,
void * V_115 , T_5 V_116 )
{
struct V_58 * V_32 = & V_112 -> V_113 . V_25 . V_28 . V_32 ;
struct V_25 * V_25 = & V_112 -> V_113 . V_25 ;
void * V_117 ;
if ( ! F_11 ( V_1 ) ) {
F_18 ( 1 , L_13 , V_118 ) ;
return;
}
F_59 () ;
if ( V_32 -> V_33 . V_77 & V_108 ) {
F_60 ( 1 ) ;
goto V_119;
}
V_117 = F_53 ( & V_25 -> V_28 . V_32 , V_108 ) ;
F_18 ( V_115 == V_117 , L_14 ) ;
memcpy ( V_117 , V_115 , V_116 ) ;
F_57 ( V_32 , V_108 ) ;
V_119:
F_61 () ;
}
int F_62 ( struct V_120 * V_121 , int V_122 ,
unsigned long V_123 )
{
struct V_58 * V_32 = & V_121 -> V_113 . V_25 . V_28 . V_32 ;
struct V_95 * V_124 ;
struct V_95 V_125 ;
int V_126 = ( V_122 * V_127 ) ;
T_3 V_128 = 0 ;
if ( ! F_11 ( V_129 ) )
return - V_103 ;
if ( V_123 & V_130 )
V_128 |= V_131 ;
if ( V_123 & V_132 )
V_128 |= V_133 ;
V_128 <<= V_126 ;
V_124 = F_54 ( V_32 , V_71 ) ;
if ( ! V_124 )
V_125 . V_134 = 0 ;
else
V_125 . V_134 = V_124 -> V_134 ;
V_125 . V_134 &= ~ ( ( V_131 | V_133 ) << V_126 ) ;
V_125 . V_134 |= V_128 ;
V_125 . V_135 = 0 ;
F_58 ( V_71 , & V_125 ,
sizeof( V_125 ) ) ;
return 0 ;
}
