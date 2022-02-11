static int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
unsigned type ,
enum V_5 V_6 )
{
struct V_7 * V_8 ;
T_1 V_9 , V_10 , V_11 , V_12 ;
V_11 = V_13 |
V_14 |
V_15 |
V_16 |
V_17 |
V_18 |
V_19 ;
switch ( V_6 ) {
case V_20 :
V_8 = & V_2 -> V_21 [ V_22 ] ;
for ( V_12 = 0 ; V_12 < 16 ; V_12 ++ ) {
V_10 = V_8 -> V_23 + V_12 ;
V_9 = F_2 ( V_10 ) ;
V_9 &= ~ V_11 ;
F_3 ( V_10 , V_9 ) ;
}
V_8 = & V_2 -> V_21 [ V_24 ] ;
for ( V_12 = 0 ; V_12 < 16 ; V_12 ++ ) {
V_10 = V_8 -> V_23 + V_12 ;
V_9 = F_2 ( V_10 ) ;
V_9 &= ~ V_11 ;
F_3 ( V_10 , V_9 ) ;
}
break;
case V_25 :
V_8 = & V_2 -> V_21 [ V_22 ] ;
for ( V_12 = 0 ; V_12 < 16 ; V_12 ++ ) {
V_10 = V_8 -> V_23 + V_12 ;
V_9 = F_2 ( V_10 ) ;
V_9 |= V_11 ;
F_3 ( V_10 , V_9 ) ;
}
V_8 = & V_2 -> V_21 [ V_24 ] ;
for ( V_12 = 0 ; V_12 < 16 ; V_12 ++ ) {
V_10 = V_8 -> V_23 + V_12 ;
V_9 = F_2 ( V_10 ) ;
V_9 |= V_11 ;
F_3 ( V_10 , V_9 ) ;
}
break;
default:
break;
}
return 0 ;
}
static int F_4 ( struct V_1 * V_2 ,
struct V_3 * V_26 ,
struct V_27 * V_28 )
{
struct V_7 * V_8 = & V_2 -> V_21 [ V_28 -> V_29 ] ;
T_2 V_30 = 0 ;
T_3 V_31 ;
V_31 = ( T_3 ) V_28 -> V_32 [ 0 ] << 12 ;
V_31 |= ( ( T_3 ) V_28 -> V_32 [ 1 ] & 0xf ) << 44 ;
if ( ! F_5 ( V_2 ) ) {
V_30 = F_2 ( V_8 -> V_33 ) ;
F_6 ( V_8 -> V_34 , 1 , ~ 1 ) ;
}
if ( F_7 () ) {
F_8 ( V_2 -> V_35 ,
L_1 ,
V_28 -> V_29 ? L_2 : L_3 ,
V_28 -> V_36 , V_28 -> V_37 , V_28 -> V_38 ,
V_28 -> V_39 ) ;
F_8 ( V_2 -> V_35 , L_4 ,
V_31 , V_28 -> V_40 ) ;
if ( ! F_5 ( V_2 ) )
F_8 ( V_2 -> V_35 ,
L_5 ,
V_30 ) ;
}
return 0 ;
}
static void F_9 ( struct V_1 * V_2 )
{
V_2 -> V_41 . V_42 . V_43 = 1 ;
V_2 -> V_41 . V_42 . V_44 = & V_45 ;
}
static T_2 F_10 ( unsigned int V_38 )
{
T_1 V_46 = 0 ;
V_46 = F_11 ( V_46 , V_47 ,
V_48 , 1 << V_38 ) ;
V_46 = F_11 ( V_46 , V_47 , V_49 , 0 ) ;
V_46 = F_11 ( V_46 , V_47 , V_50 , 1 ) ;
V_46 = F_11 ( V_46 , V_47 , V_51 , 1 ) ;
V_46 = F_11 ( V_46 , V_47 , V_52 , 1 ) ;
V_46 = F_11 ( V_46 , V_47 , V_53 , 1 ) ;
V_46 = F_11 ( V_46 , V_47 , V_54 , 1 ) ;
V_46 = F_11 ( V_46 , V_47 ,
V_55 , 0 ) ;
return V_46 ;
}
static void F_12 ( struct V_1 * V_2 ,
T_2 V_56 )
{
const unsigned V_57 = 17 ;
unsigned V_12 , V_58 ;
if ( V_2 -> V_59 & V_60 )
F_13 ( V_2 ) ;
else
F_14 ( V_2 ) ;
F_15 ( & V_2 -> V_41 . V_61 ) ;
for ( V_12 = 0 ; V_12 < V_62 ; ++ V_12 ) {
struct V_7 * V_8 = & V_2 -> V_21 [ V_12 ] ;
T_1 V_9 = F_10 ( V_56 ) ;
F_16 ( V_8 -> V_63 + V_57 , V_9 ) ;
for ( V_58 = 0 ; V_58 < 100 ; V_58 ++ ) {
V_9 = F_17 ( V_8 -> V_64 + V_57 ) ;
V_9 &= 1 << V_56 ;
if ( V_9 )
break;
F_18 () ;
}
if ( V_58 < 100 )
continue;
for ( V_58 = 0 ; V_58 < V_2 -> V_65 ; V_58 ++ ) {
V_9 = F_17 ( V_8 -> V_64 + V_57 ) ;
V_9 &= 1 << V_56 ;
if ( V_9 )
break;
F_19 ( 1 ) ;
}
if ( V_58 < V_2 -> V_65 )
continue;
F_20 ( L_6 ) ;
}
F_21 ( & V_2 -> V_41 . V_61 ) ;
}
static int F_22 ( struct V_1 * V_2 ,
void * V_66 ,
T_2 V_67 ,
T_4 V_31 ,
T_4 V_59 )
{
void T_5 * V_68 = ( void * ) V_66 ;
T_4 V_69 ;
V_69 = V_31 & 0x0000FFFFFFFFF000ULL ;
V_69 |= V_59 ;
F_23 ( V_69 , V_68 + ( V_67 * 8 ) ) ;
return 0 ;
}
static T_4 F_24 ( struct V_1 * V_2 ,
T_2 V_59 )
{
T_4 V_70 = 0 ;
if ( V_59 & V_71 )
V_70 |= V_72 ;
if ( V_59 & V_73 )
V_70 |= V_74 ;
if ( V_59 & V_75 )
V_70 |= V_76 ;
switch ( V_59 & V_77 ) {
case V_78 :
V_70 |= F_25 ( V_79 ) ;
break;
case V_80 :
V_70 |= F_25 ( V_79 ) ;
break;
case V_81 :
V_70 |= F_25 ( V_82 ) ;
break;
case V_83 :
V_70 |= F_25 ( V_84 ) ;
break;
case V_85 :
V_70 |= F_25 ( V_86 ) ;
break;
default:
V_70 |= F_25 ( V_79 ) ;
break;
}
if ( V_59 & V_87 )
V_70 |= V_88 ;
return V_70 ;
}
static T_3 F_26 ( struct V_1 * V_2 , T_3 V_31 )
{
V_31 = V_2 -> V_89 . V_90 + V_31 - V_2 -> V_41 . V_91 ;
F_27 ( V_31 & 0xFFFF00000000003FULL ) ;
return V_31 ;
}
static void F_28 ( struct V_1 * V_2 )
{
if ( V_2 -> V_92 . V_93 == NULL )
V_2 -> V_92 . V_93 = & V_94 ;
}
static int F_29 ( void * V_95 )
{
struct V_1 * V_2 = (struct V_1 * ) V_95 ;
F_28 ( V_2 ) ;
F_9 ( V_2 ) ;
return 0 ;
}
static int F_30 ( void * V_95 )
{
struct V_1 * V_2 = (struct V_1 * ) V_95 ;
unsigned V_96 [ V_62 ] = { 3 , 3 } ;
unsigned V_12 ;
for( V_12 = 0 ; V_12 < V_2 -> V_97 ; ++ V_12 ) {
struct V_98 * V_99 = V_2 -> V_100 [ V_12 ] ;
unsigned V_21 = V_99 -> V_44 -> V_21 ;
V_99 -> V_96 = V_96 [ V_21 ] ++ ;
F_31 ( V_2 -> V_35 , L_7 ,
V_99 -> V_101 , V_99 -> V_102 , V_99 -> V_96 ,
V_99 -> V_44 -> V_21 ) ;
}
for( V_12 = 0 ; V_12 < V_62 ; ++ V_12 )
F_27 ( V_96 [ V_12 ] > 17 ) ;
return F_32 ( V_2 , & V_2 -> V_41 . V_42 , 0 ) ;
}
static void F_33 ( struct V_1 * V_2 ,
struct V_103 * V_41 )
{
T_3 V_104 = 0 ;
if ( ! F_5 ( V_2 ) )
V_104 = F_34 ( V_2 ) ;
F_35 ( V_2 , & V_2 -> V_41 , V_104 ) ;
F_36 ( V_2 , V_41 ) ;
if ( V_2 -> V_59 & V_60 )
V_2 -> V_89 . V_90 = F_37 ( V_2 ) ;
else
V_2 -> V_89 . V_90 = 0 ;
}
static int F_38 ( struct V_1 * V_2 )
{
T_1 V_9 ;
int V_105 , V_106 ;
V_2 -> V_41 . V_107 = F_39 ( V_2 ) ;
if ( ! V_2 -> V_41 . V_107 ) {
V_105 = 128 ;
V_9 = F_40 ( V_108 , 0 , V_109 ) ;
V_9 &= V_110 ;
V_9 >>= V_111 ;
switch ( V_9 ) {
case 0 :
default:
V_106 = 1 ;
break;
case 1 :
V_106 = 2 ;
break;
case 2 :
V_106 = 0 ;
break;
case 3 :
V_106 = 4 ;
break;
case 4 :
V_106 = 0 ;
break;
case 5 :
V_106 = 8 ;
break;
case 6 :
V_106 = 0 ;
break;
case 7 :
V_106 = 16 ;
break;
case 8 :
V_106 = 2 ;
break;
}
V_2 -> V_41 . V_107 = V_106 * V_105 ;
}
V_2 -> V_41 . V_112 = F_41 ( V_2 -> V_113 , 0 ) ;
V_2 -> V_41 . V_114 = F_42 ( V_2 -> V_113 , 0 ) ;
V_2 -> V_41 . V_115 =
( ( V_2 -> V_59 & V_60 ) ? F_43 ( V_2 ) :
F_44 ( V_2 ) ) * 1024ULL * 1024ULL ;
V_2 -> V_41 . V_116 = V_2 -> V_41 . V_115 ;
V_2 -> V_41 . V_117 = V_2 -> V_41 . V_114 ;
if ( V_2 -> V_41 . V_117 > V_2 -> V_41 . V_116 )
V_2 -> V_41 . V_117 = V_2 -> V_41 . V_116 ;
if ( V_118 == - 1 ) {
switch ( V_2 -> V_119 ) {
case V_120 :
default:
V_2 -> V_41 . V_121 = 256ULL << 20 ;
break;
case V_122 :
V_2 -> V_41 . V_121 = 1024ULL << 20 ;
break;
}
} else {
V_2 -> V_41 . V_121 = ( T_3 ) V_118 << 20 ;
}
F_33 ( V_2 , & V_2 -> V_41 ) ;
return 0 ;
}
static int F_45 ( struct V_1 * V_2 )
{
int V_123 ;
if ( V_2 -> V_92 . V_124 ) {
F_46 ( 1 , L_8 ) ;
return 0 ;
}
V_123 = F_47 ( V_2 ) ;
if ( V_123 )
return V_123 ;
V_2 -> V_92 . V_125 = V_2 -> V_92 . V_126 * 8 ;
V_2 -> V_92 . V_127 = F_25 ( V_86 ) |
V_72 ;
return F_48 ( V_2 ) ;
}
static int F_49 ( void * V_95 )
{
int V_123 ;
int V_128 ;
struct V_1 * V_2 = (struct V_1 * ) V_95 ;
F_50 ( V_2 ) ;
F_51 ( V_2 ) ;
F_52 ( & V_2 -> V_41 . V_61 ) ;
switch ( V_2 -> V_119 ) {
case V_122 :
V_2 -> V_41 . V_129 = V_130 ;
if ( V_2 -> V_131 == 0x0 || V_2 -> V_131 == 0x1 ) {
V_2 -> V_89 . V_132 = 1U << 18 ;
V_2 -> V_89 . V_133 = 9 ;
V_2 -> V_89 . V_134 = 3 ;
F_53 ( V_2 , 9 ) ;
} else {
F_54 ( V_2 , 64 , 9 ) ;
V_2 -> V_89 . V_134 = 1 ;
}
break;
case V_120 :
V_2 -> V_41 . V_129 = V_135 ;
V_2 -> V_89 . V_132 = 1U << 18 ;
V_2 -> V_89 . V_133 = 9 ;
V_2 -> V_89 . V_134 = 3 ;
F_53 ( V_2 , 9 ) ;
break;
default:
break;
}
F_55 ( L_9 ,
V_2 -> V_89 . V_132 ,
V_2 -> V_89 . V_133 ,
V_2 -> V_89 . V_136 ) ;
V_123 = F_56 ( V_2 , V_137 , 0 ,
& V_2 -> V_41 . V_42 ) ;
V_123 = F_56 ( V_2 , V_138 , 0 ,
& V_2 -> V_41 . V_42 ) ;
if ( V_123 )
return V_123 ;
V_2 -> V_89 . V_139 = V_2 -> V_89 . V_132 << 18 ;
V_2 -> V_41 . V_140 = 0xffffffffffffULL ;
V_2 -> V_41 . V_141 = 8 * 1024 * 1024 ;
V_2 -> V_142 = false ;
V_128 = V_2 -> V_142 ? 32 : 44 ;
V_123 = F_57 ( V_2 -> V_113 , F_58 ( V_128 ) ) ;
if ( V_123 ) {
V_2 -> V_142 = true ;
V_128 = 32 ;
F_59 ( V_143 L_10 ) ;
}
V_123 = F_60 ( V_2 -> V_113 , F_58 ( V_128 ) ) ;
if ( V_123 ) {
F_60 ( V_2 -> V_113 , F_58 ( 32 ) ) ;
F_59 ( V_143 L_11 ) ;
}
V_123 = F_38 ( V_2 ) ;
if ( V_123 )
return V_123 ;
V_123 = F_61 ( V_2 ) ;
if ( V_123 )
return V_123 ;
V_123 = F_45 ( V_2 ) ;
if ( V_123 )
return V_123 ;
V_2 -> V_89 . V_144 [ V_24 ] . V_145 = V_146 ;
V_2 -> V_89 . V_144 [ V_22 ] . V_145 = V_146 ;
F_62 ( V_2 ) ;
return 0 ;
}
static void F_63 ( struct V_1 * V_2 )
{
F_64 ( V_2 ) ;
F_65 ( V_2 ) ;
}
static int F_66 ( void * V_95 )
{
struct V_1 * V_2 = (struct V_1 * ) V_95 ;
F_67 ( V_2 ) ;
F_63 ( V_2 ) ;
F_68 ( V_2 ) ;
F_69 ( V_2 ) ;
return 0 ;
}
static void F_70 ( struct V_1 * V_2 )
{
switch ( V_2 -> V_119 ) {
case V_120 :
break;
case V_122 :
break;
default:
break;
}
}
static int F_71 ( struct V_1 * V_2 )
{
int V_123 ;
bool V_69 ;
T_1 V_9 ;
F_72 ( V_2 ,
V_147 ,
( const T_1 ) F_73 ( V_147 ) ) ;
if ( V_2 -> V_92 . V_124 == NULL ) {
F_8 ( V_2 -> V_35 , L_12 ) ;
return - V_148 ;
}
V_123 = F_74 ( V_2 ) ;
if ( V_123 )
return V_123 ;
if ( V_2 -> V_59 & V_60 )
F_13 ( V_2 ) ;
else
F_14 ( V_2 ) ;
switch ( V_2 -> V_119 ) {
case V_122 :
F_75 ( V_2 ) ;
F_76 ( V_2 , true ) ;
break;
default:
break;
}
V_123 = F_77 ( V_2 ) ;
if ( V_123 )
return V_123 ;
V_123 = F_78 ( V_2 ) ;
if ( V_123 )
return V_123 ;
V_9 = F_40 ( V_149 , 0 , V_150 ) ;
V_9 |= V_151 ;
F_79 ( V_149 , 0 , V_150 , V_9 ) ;
V_9 = F_40 ( V_149 , 0 , V_152 ) ;
F_79 ( V_149 , 0 , V_152 , V_9 ) ;
if ( V_153 == V_154 )
V_69 = false ;
else
V_69 = true ;
F_80 ( V_2 , V_69 ) ;
F_81 ( V_2 , V_69 ) ;
F_12 ( V_2 , 0 ) ;
F_55 ( L_13 ,
( unsigned ) ( V_2 -> V_41 . V_121 >> 20 ) ,
( unsigned long long ) V_2 -> V_92 . V_155 ) ;
V_2 -> V_92 . V_156 = true ;
return 0 ;
}
static int F_82 ( void * V_95 )
{
int V_123 ;
struct V_1 * V_2 = (struct V_1 * ) V_95 ;
F_70 ( V_2 ) ;
if ( V_2 -> V_157 . V_158 ) {
T_1 V_9 ;
V_9 = F_40 ( V_159 , 0 , V_160 ) ;
V_9 = F_11 ( V_9 , V_161 , V_162 , 1 ) ;
F_79 ( V_159 , 0 , V_160 , V_9 ) ;
V_9 = F_40 ( V_159 , 0 , V_163 ) ;
V_9 = F_11 ( V_9 , V_164 , V_165 , 0 ) ;
F_79 ( V_159 , 0 , V_163 , V_9 ) ;
}
V_123 = F_71 ( V_2 ) ;
return V_123 ;
}
static void F_83 ( struct V_1 * V_2 )
{
F_84 ( V_2 ) ;
F_85 ( V_2 ) ;
F_86 ( V_2 ) ;
}
static int F_87 ( void * V_95 )
{
struct V_1 * V_2 = (struct V_1 * ) V_95 ;
if ( F_5 ( V_2 ) ) {
F_88 ( L_14 ) ;
return 0 ;
}
F_89 ( V_2 , & V_2 -> V_41 . V_42 , 0 ) ;
F_83 ( V_2 ) ;
return 0 ;
}
static int F_90 ( void * V_95 )
{
struct V_1 * V_2 = (struct V_1 * ) V_95 ;
F_87 ( V_2 ) ;
return 0 ;
}
static int F_91 ( void * V_95 )
{
int V_123 ;
struct V_1 * V_2 = (struct V_1 * ) V_95 ;
V_123 = F_82 ( V_2 ) ;
if ( V_123 )
return V_123 ;
F_92 ( V_2 ) ;
return 0 ;
}
static bool F_93 ( void * V_95 )
{
return true ;
}
static int F_94 ( void * V_95 )
{
return 0 ;
}
static int F_95 ( void * V_95 )
{
return 0 ;
}
static int F_96 ( void * V_95 ,
enum V_166 V_6 )
{
struct V_1 * V_2 = (struct V_1 * ) V_95 ;
return F_97 ( V_2 , V_6 ) ;
}
static void F_98 ( void * V_95 , T_1 * V_59 )
{
struct V_1 * V_2 = (struct V_1 * ) V_95 ;
F_99 ( V_2 , V_59 ) ;
}
static int F_100 ( void * V_95 ,
enum V_167 V_6 )
{
return 0 ;
}
