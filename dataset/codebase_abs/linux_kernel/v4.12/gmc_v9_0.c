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
F_13 ( V_2 ) ;
F_14 ( & V_2 -> V_41 . V_59 ) ;
for ( V_12 = 0 ; V_12 < V_60 ; ++ V_12 ) {
struct V_7 * V_8 = & V_2 -> V_21 [ V_12 ] ;
T_1 V_9 = F_10 ( V_56 ) ;
F_15 ( V_8 -> V_61 + V_57 , V_9 ) ;
for ( V_58 = 0 ; V_58 < 100 ; V_58 ++ ) {
V_9 = F_16 ( V_8 -> V_62 + V_57 ) ;
V_9 &= 1 << V_56 ;
if ( V_9 )
break;
F_17 () ;
}
if ( V_58 < 100 )
continue;
for ( V_58 = 0 ; V_58 < V_2 -> V_63 ; V_58 ++ ) {
V_9 = F_16 ( V_8 -> V_62 + V_57 ) ;
V_9 &= 1 << V_56 ;
if ( V_9 )
break;
F_18 ( 1 ) ;
}
if ( V_58 < V_2 -> V_63 )
continue;
F_19 ( L_6 ) ;
}
F_20 ( & V_2 -> V_41 . V_59 ) ;
}
static int F_21 ( struct V_1 * V_2 ,
void * V_64 ,
T_2 V_65 ,
T_4 V_31 ,
T_4 V_66 )
{
void T_5 * V_67 = ( void * ) V_64 ;
T_4 V_68 ;
V_68 = V_31 & 0x0000FFFFFFFFF000ULL ;
V_68 |= V_66 ;
F_22 ( V_68 , V_67 + ( V_65 * 8 ) ) ;
return 0 ;
}
static T_4 F_23 ( struct V_1 * V_2 ,
T_2 V_66 )
{
T_4 V_69 = 0 ;
if ( V_66 & V_70 )
V_69 |= V_71 ;
if ( V_66 & V_72 )
V_69 |= V_73 ;
if ( V_66 & V_74 )
V_69 |= V_75 ;
switch ( V_66 & V_76 ) {
case V_77 :
V_69 |= F_24 ( V_78 ) ;
break;
case V_79 :
V_69 |= F_24 ( V_78 ) ;
break;
case V_80 :
V_69 |= F_24 ( V_81 ) ;
break;
case V_82 :
V_69 |= F_24 ( V_83 ) ;
break;
case V_84 :
V_69 |= F_24 ( V_85 ) ;
break;
default:
V_69 |= F_24 ( V_78 ) ;
break;
}
if ( V_66 & V_86 )
V_69 |= V_87 ;
return V_69 ;
}
static T_3 F_25 ( struct V_1 * V_2 , T_3 V_88 )
{
return V_2 -> V_89 . V_90 + V_88 - V_2 -> V_41 . V_91 ;
}
static void F_26 ( struct V_1 * V_2 )
{
if ( V_2 -> V_92 . V_93 == NULL )
V_2 -> V_92 . V_93 = & V_94 ;
}
static int F_27 ( void * V_95 )
{
struct V_1 * V_2 = (struct V_1 * ) V_95 ;
F_26 ( V_2 ) ;
F_9 ( V_2 ) ;
return 0 ;
}
static int F_28 ( void * V_95 )
{
struct V_1 * V_2 = (struct V_1 * ) V_95 ;
unsigned V_96 [ V_60 ] = { 3 , 3 } ;
unsigned V_12 ;
for( V_12 = 0 ; V_12 < V_2 -> V_97 ; ++ V_12 ) {
struct V_98 * V_99 = V_2 -> V_100 [ V_12 ] ;
unsigned V_21 = V_99 -> V_44 -> V_21 ;
V_99 -> V_96 = V_96 [ V_21 ] ++ ;
F_29 ( V_2 -> V_35 , L_7 ,
V_99 -> V_101 , V_99 -> V_102 , V_99 -> V_96 ,
V_99 -> V_44 -> V_21 ) ;
}
for( V_12 = 0 ; V_12 < V_60 ; ++ V_12 )
F_30 ( V_96 [ V_12 ] > 17 ) ;
return F_31 ( V_2 , & V_2 -> V_41 . V_42 , 0 ) ;
}
static void F_32 ( struct V_1 * V_2 ,
struct V_103 * V_41 )
{
T_3 V_104 = 0 ;
if ( ! F_5 ( V_2 ) )
V_104 = F_33 ( V_2 ) ;
F_34 ( V_2 , & V_2 -> V_41 , V_104 ) ;
V_2 -> V_41 . V_105 = 0 ;
F_35 ( V_2 , V_41 ) ;
}
static int F_36 ( struct V_1 * V_2 )
{
T_1 V_9 ;
int V_106 , V_107 ;
V_106 = 128 ;
V_9 = F_2 ( F_37 ( V_108 , 0 , V_109 ) ) ;
V_9 &= V_110 ;
V_9 >>= V_111 ;
switch ( V_9 ) {
case 0 :
default:
V_107 = 1 ;
break;
case 1 :
V_107 = 2 ;
break;
case 2 :
V_107 = 0 ;
break;
case 3 :
V_107 = 4 ;
break;
case 4 :
V_107 = 0 ;
break;
case 5 :
V_107 = 8 ;
break;
case 6 :
V_107 = 0 ;
break;
case 7 :
V_107 = 16 ;
break;
case 8 :
V_107 = 2 ;
break;
}
V_2 -> V_41 . V_112 = V_107 * V_106 ;
V_2 -> V_41 . V_113 = F_38 ( V_2 -> V_114 , 0 ) ;
V_2 -> V_41 . V_115 = F_39 ( V_2 -> V_114 , 0 ) ;
V_2 -> V_41 . V_116 =
F_40 ( V_2 ) * 1024ULL * 1024ULL ;
V_2 -> V_41 . V_117 = V_2 -> V_41 . V_116 ;
V_2 -> V_41 . V_118 = V_2 -> V_41 . V_115 ;
if ( V_2 -> V_41 . V_118 > V_2 -> V_41 . V_117 )
V_2 -> V_41 . V_118 = V_2 -> V_41 . V_117 ;
if ( V_119 == - 1 )
V_2 -> V_41 . V_120 = F_41 ( ( V_121 << 20 ) ,
V_2 -> V_41 . V_116 ) ;
else
V_2 -> V_41 . V_120 = ( T_4 ) V_119 << 20 ;
F_32 ( V_2 , & V_2 -> V_41 ) ;
return 0 ;
}
static int F_42 ( struct V_1 * V_2 )
{
int V_122 ;
if ( V_2 -> V_92 . V_123 ) {
F_43 ( 1 , L_8 ) ;
return 0 ;
}
V_122 = F_44 ( V_2 ) ;
if ( V_122 )
return V_122 ;
V_2 -> V_92 . V_124 = V_2 -> V_92 . V_125 * 8 ;
V_2 -> V_92 . V_126 = F_24 ( V_85 ) |
V_71 ;
return F_45 ( V_2 ) ;
}
static int F_46 ( struct V_1 * V_2 )
{
V_2 -> V_89 . V_127 [ V_24 ] . V_128 = V_129 ;
V_2 -> V_89 . V_127 [ V_22 ] . V_128 = V_129 ;
if ( V_2 -> V_66 & V_130 )
V_2 -> V_89 . V_131 = 1 ;
else
V_2 -> V_89 . V_131 = 3 ;
F_47 ( V_2 ) ;
V_2 -> V_89 . V_90 = 0 ;
return 0 ;
}
static void F_48 ( struct V_1 * V_2 )
{
return;
}
static int F_49 ( void * V_95 )
{
int V_122 ;
int V_132 ;
struct V_1 * V_2 = (struct V_1 * ) V_95 ;
F_50 ( & V_2 -> V_41 . V_59 ) ;
if ( V_2 -> V_66 & V_130 ) {
V_2 -> V_41 . V_133 = V_134 ;
F_51 ( V_2 , 64 ) ;
} else {
V_2 -> V_41 . V_133 = V_135 ;
V_2 -> V_89 . V_136 = 1U << 18 ;
V_2 -> V_89 . V_137 = 9 ;
F_52 ( L_9 ,
V_2 -> V_89 . V_136 ,
V_2 -> V_89 . V_137 ) ;
}
V_122 = F_53 ( V_2 , V_138 , 0 ,
& V_2 -> V_41 . V_42 ) ;
V_122 = F_53 ( V_2 , V_139 , 0 ,
& V_2 -> V_41 . V_42 ) ;
if ( V_122 )
return V_122 ;
V_2 -> V_89 . V_140 = V_2 -> V_89 . V_136 << 18 ;
V_2 -> V_41 . V_141 = 0xffffffffffffULL ;
V_2 -> V_142 = false ;
V_132 = V_2 -> V_142 ? 32 : 44 ;
V_122 = F_54 ( V_2 -> V_114 , F_55 ( V_132 ) ) ;
if ( V_122 ) {
V_2 -> V_142 = true ;
V_132 = 32 ;
F_56 ( V_143 L_10 ) ;
}
V_122 = F_57 ( V_2 -> V_114 , F_55 ( V_132 ) ) ;
if ( V_122 ) {
F_57 ( V_2 -> V_114 , F_55 ( 32 ) ) ;
F_56 ( V_143 L_11 ) ;
}
V_122 = F_36 ( V_2 ) ;
if ( V_122 )
return V_122 ;
V_122 = F_58 ( V_2 ) ;
if ( V_122 )
return V_122 ;
V_122 = F_42 ( V_2 ) ;
if ( V_122 )
return V_122 ;
if ( ! V_2 -> V_89 . V_144 ) {
V_122 = F_46 ( V_2 ) ;
if ( V_122 ) {
F_8 ( V_2 -> V_35 , L_12 , V_122 ) ;
return V_122 ;
}
V_2 -> V_89 . V_144 = true ;
}
return V_122 ;
}
static void F_59 ( struct V_1 * V_2 )
{
F_60 ( V_2 ) ;
F_61 ( V_2 ) ;
}
static int F_62 ( void * V_95 )
{
struct V_1 * V_2 = (struct V_1 * ) V_95 ;
if ( V_2 -> V_89 . V_144 ) {
F_63 ( V_2 ) ;
F_48 ( V_2 ) ;
V_2 -> V_89 . V_144 = false ;
}
F_59 ( V_2 ) ;
F_64 ( V_2 ) ;
F_65 ( V_2 ) ;
return 0 ;
}
static void F_66 ( struct V_1 * V_2 )
{
switch ( V_2 -> V_145 ) {
case V_146 :
break;
default:
break;
}
}
static int F_67 ( struct V_1 * V_2 )
{
int V_122 ;
bool V_68 ;
T_1 V_9 ;
F_68 ( V_2 ,
V_147 ,
( const T_1 ) F_69 ( V_147 ) ) ;
if ( V_2 -> V_92 . V_123 == NULL ) {
F_8 ( V_2 -> V_35 , L_13 ) ;
return - V_148 ;
}
V_122 = F_70 ( V_2 ) ;
if ( V_122 )
return V_122 ;
F_13 ( V_2 ) ;
V_122 = F_71 ( V_2 ) ;
if ( V_122 )
return V_122 ;
V_122 = F_72 ( V_2 ) ;
if ( V_122 )
return V_122 ;
V_9 = F_2 ( F_37 ( V_149 , 0 , V_150 ) ) ;
V_9 |= V_151 ;
F_3 ( F_37 ( V_149 , 0 , V_150 ) , V_9 ) ;
V_9 = F_2 ( F_37 ( V_149 , 0 , V_152 ) ) ;
F_3 ( F_37 ( V_149 , 0 , V_152 ) , V_9 ) ;
if ( V_153 == V_154 )
V_68 = false ;
else
V_68 = true ;
F_73 ( V_2 , V_68 ) ;
F_74 ( V_2 , V_68 ) ;
F_12 ( V_2 , 0 ) ;
F_52 ( L_14 ,
( unsigned ) ( V_2 -> V_41 . V_120 >> 20 ) ,
( unsigned long long ) V_2 -> V_92 . V_155 ) ;
V_2 -> V_92 . V_156 = true ;
return 0 ;
}
static int F_75 ( void * V_95 )
{
int V_122 ;
struct V_1 * V_2 = (struct V_1 * ) V_95 ;
F_66 ( V_2 ) ;
V_122 = F_67 ( V_2 ) ;
return V_122 ;
}
static void F_76 ( struct V_1 * V_2 )
{
F_77 ( V_2 ) ;
F_78 ( V_2 ) ;
F_79 ( V_2 ) ;
}
static int F_80 ( void * V_95 )
{
struct V_1 * V_2 = (struct V_1 * ) V_95 ;
F_81 ( V_2 , & V_2 -> V_41 . V_42 , 0 ) ;
F_76 ( V_2 ) ;
return 0 ;
}
static int F_82 ( void * V_95 )
{
struct V_1 * V_2 = (struct V_1 * ) V_95 ;
F_80 ( V_2 ) ;
return 0 ;
}
static int F_83 ( void * V_95 )
{
int V_122 ;
struct V_1 * V_2 = (struct V_1 * ) V_95 ;
V_122 = F_75 ( V_2 ) ;
if ( V_122 )
return V_122 ;
F_84 ( V_2 ) ;
return 0 ;
}
static bool F_85 ( void * V_95 )
{
return true ;
}
static int F_86 ( void * V_95 )
{
return 0 ;
}
static int F_87 ( void * V_95 )
{
return 0 ;
}
static int F_88 ( void * V_95 ,
enum V_157 V_6 )
{
return 0 ;
}
static int F_89 ( void * V_95 ,
enum V_158 V_6 )
{
return 0 ;
}
