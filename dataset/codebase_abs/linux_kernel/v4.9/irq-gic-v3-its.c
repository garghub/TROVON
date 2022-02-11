static struct V_1 * F_1 ( struct V_2 * V_3 ,
T_1 V_4 )
{
struct V_5 * V_6 = V_3 -> V_6 ;
return V_6 -> V_7 + V_3 -> V_8 . V_9 [ V_4 ] ;
}
static void F_2 ( struct V_10 * V_11 , T_2 V_12 )
{
V_11 -> V_13 [ 0 ] &= ~ 0xffUL ;
V_11 -> V_13 [ 0 ] |= V_12 ;
}
static void F_3 ( struct V_10 * V_11 , T_1 V_14 )
{
V_11 -> V_13 [ 0 ] &= F_4 ( 32 ) - 1 ;
V_11 -> V_13 [ 0 ] |= ( ( V_15 ) V_14 ) << 32 ;
}
static void F_5 ( struct V_10 * V_11 , T_1 V_16 )
{
V_11 -> V_13 [ 1 ] &= ~ 0xffffffffUL ;
V_11 -> V_13 [ 1 ] |= V_16 ;
}
static void F_6 ( struct V_10 * V_11 , T_1 V_17 )
{
V_11 -> V_13 [ 1 ] &= 0xffffffffUL ;
V_11 -> V_13 [ 1 ] |= ( ( V_15 ) V_17 ) << 32 ;
}
static void F_7 ( struct V_10 * V_11 , T_2 V_18 )
{
V_11 -> V_13 [ 1 ] &= ~ 0x1fUL ;
V_11 -> V_13 [ 1 ] |= V_18 & 0x1f ;
}
static void F_8 ( struct V_10 * V_11 , V_15 V_19 )
{
V_11 -> V_13 [ 2 ] &= ~ 0xffffffffffffUL ;
V_11 -> V_13 [ 2 ] |= V_19 & 0xffffffffff00UL ;
}
static void F_9 ( struct V_10 * V_11 , int V_20 )
{
V_11 -> V_13 [ 2 ] &= ~ ( 1UL << 63 ) ;
V_11 -> V_13 [ 2 ] |= ( ( V_15 ) ! ! V_20 ) << 63 ;
}
static void F_10 ( struct V_10 * V_11 , V_15 V_21 )
{
V_11 -> V_13 [ 2 ] &= ~ ( 0xffffffffUL << 16 ) ;
V_11 -> V_13 [ 2 ] |= ( V_21 & ( 0xffffffffUL << 16 ) ) ;
}
static void F_11 ( struct V_10 * V_11 , T_3 V_22 )
{
V_11 -> V_13 [ 2 ] &= ~ 0xffffUL ;
V_11 -> V_13 [ 2 ] |= V_22 ;
}
static inline void F_12 ( struct V_10 * V_11 )
{
V_11 -> V_13 [ 0 ] = F_13 ( V_11 -> V_13 [ 0 ] ) ;
V_11 -> V_13 [ 1 ] = F_13 ( V_11 -> V_13 [ 1 ] ) ;
V_11 -> V_13 [ 2 ] = F_13 ( V_11 -> V_13 [ 2 ] ) ;
V_11 -> V_13 [ 3 ] = F_13 ( V_11 -> V_13 [ 3 ] ) ;
}
static struct V_1 * F_14 ( struct V_10 * V_11 ,
struct V_23 * V_24 )
{
unsigned long V_19 ;
T_2 V_18 = F_15 ( V_24 -> V_25 . V_26 -> V_27 ) ;
V_19 = F_16 ( V_24 -> V_25 . V_26 -> V_28 ) ;
V_19 = F_17 ( V_19 , V_29 ) ;
F_2 ( V_11 , V_30 ) ;
F_3 ( V_11 , V_24 -> V_25 . V_26 -> V_31 ) ;
F_7 ( V_11 , V_18 - 1 ) ;
F_8 ( V_11 , V_19 ) ;
F_9 ( V_11 , V_24 -> V_25 . V_20 ) ;
F_12 ( V_11 ) ;
return NULL ;
}
static struct V_1 * F_18 ( struct V_10 * V_11 ,
struct V_23 * V_24 )
{
F_2 ( V_11 , V_32 ) ;
F_11 ( V_11 , V_24 -> V_33 . V_22 -> V_34 ) ;
F_10 ( V_11 , V_24 -> V_33 . V_22 -> V_35 ) ;
F_9 ( V_11 , V_24 -> V_33 . V_20 ) ;
F_12 ( V_11 ) ;
return V_24 -> V_33 . V_22 ;
}
static struct V_1 * F_19 ( struct V_10 * V_11 ,
struct V_23 * V_24 )
{
struct V_1 * V_22 ;
V_22 = F_1 ( V_24 -> V_36 . V_26 ,
V_24 -> V_36 . V_37 ) ;
F_2 ( V_11 , V_38 ) ;
F_3 ( V_11 , V_24 -> V_36 . V_26 -> V_31 ) ;
F_5 ( V_11 , V_24 -> V_36 . V_37 ) ;
F_6 ( V_11 , V_24 -> V_36 . V_17 ) ;
F_11 ( V_11 , V_22 -> V_34 ) ;
F_12 ( V_11 ) ;
return V_22 ;
}
static struct V_1 * F_20 ( struct V_10 * V_11 ,
struct V_23 * V_24 )
{
struct V_1 * V_22 ;
V_22 = F_1 ( V_24 -> V_39 . V_26 ,
V_24 -> V_39 . V_37 ) ;
F_2 ( V_11 , V_40 ) ;
F_3 ( V_11 , V_24 -> V_39 . V_26 -> V_31 ) ;
F_5 ( V_11 , V_24 -> V_39 . V_37 ) ;
F_11 ( V_11 , V_24 -> V_39 . V_22 -> V_34 ) ;
F_12 ( V_11 ) ;
return V_22 ;
}
static struct V_1 * F_21 ( struct V_10 * V_11 ,
struct V_23 * V_24 )
{
struct V_1 * V_22 ;
V_22 = F_1 ( V_24 -> V_41 . V_26 ,
V_24 -> V_41 . V_37 ) ;
F_2 ( V_11 , V_42 ) ;
F_3 ( V_11 , V_24 -> V_41 . V_26 -> V_31 ) ;
F_5 ( V_11 , V_24 -> V_41 . V_37 ) ;
F_12 ( V_11 ) ;
return V_22 ;
}
static struct V_1 * F_22 ( struct V_10 * V_11 ,
struct V_23 * V_24 )
{
struct V_1 * V_22 ;
V_22 = F_1 ( V_24 -> V_43 . V_26 ,
V_24 -> V_43 . V_37 ) ;
F_2 ( V_11 , V_44 ) ;
F_3 ( V_11 , V_24 -> V_43 . V_26 -> V_31 ) ;
F_5 ( V_11 , V_24 -> V_43 . V_37 ) ;
F_12 ( V_11 ) ;
return V_22 ;
}
static struct V_1 * F_23 ( struct V_10 * V_11 ,
struct V_23 * V_24 )
{
F_2 ( V_11 , V_45 ) ;
F_11 ( V_11 , V_24 -> V_33 . V_22 -> V_34 ) ;
F_12 ( V_11 ) ;
return NULL ;
}
static V_15 F_24 ( struct V_5 * V_6 ,
struct V_10 * V_46 )
{
return ( V_46 - V_6 -> V_47 ) * sizeof( * V_46 ) ;
}
static int F_25 ( struct V_5 * V_6 )
{
int V_48 ;
int V_49 ;
V_48 = V_6 -> V_50 - V_6 -> V_47 ;
V_49 = F_26 ( V_6 -> V_51 + V_52 ) / sizeof( struct V_10 ) ;
if ( ( ( V_48 + 1 ) % V_53 ) == V_49 )
return 1 ;
return 0 ;
}
static struct V_10 * F_27 ( struct V_5 * V_6 )
{
struct V_10 * V_11 ;
T_1 V_54 = 1000000 ;
while ( F_25 ( V_6 ) ) {
V_54 -- ;
if ( ! V_54 ) {
F_28 ( L_1 ) ;
return NULL ;
}
F_29 () ;
F_30 ( 1 ) ;
}
V_11 = V_6 -> V_50 ++ ;
if ( V_6 -> V_50 == ( V_6 -> V_47 + V_53 ) )
V_6 -> V_50 = V_6 -> V_47 ;
return V_11 ;
}
static struct V_10 * F_31 ( struct V_5 * V_6 )
{
V_15 V_55 = F_24 ( V_6 , V_6 -> V_50 ) ;
F_32 ( V_55 , V_6 -> V_51 + V_56 ) ;
return V_6 -> V_50 ;
}
static void F_33 ( struct V_5 * V_6 , struct V_10 * V_11 )
{
if ( V_6 -> V_57 & V_58 )
F_34 ( V_11 , sizeof( * V_11 ) ) ;
else
F_35 ( V_59 ) ;
}
static void F_36 ( struct V_5 * V_6 ,
struct V_10 * V_60 ,
struct V_10 * V_61 )
{
V_15 V_62 , V_63 , V_64 ;
T_1 V_54 = 1000000 ;
V_63 = F_24 ( V_6 , V_60 ) ;
V_64 = F_24 ( V_6 , V_61 ) ;
while ( 1 ) {
V_62 = F_26 ( V_6 -> V_51 + V_52 ) ;
if ( V_62 >= V_64 || V_62 < V_63 )
break;
V_54 -- ;
if ( ! V_54 ) {
F_28 ( L_2 ) ;
return;
}
F_29 () ;
F_30 ( 1 ) ;
}
}
static void F_37 ( struct V_5 * V_6 ,
T_4 V_65 ,
struct V_23 * V_24 )
{
struct V_10 * V_11 , * V_66 , * V_67 ;
struct V_1 * V_68 ;
unsigned long V_57 ;
F_38 ( & V_6 -> V_69 , V_57 ) ;
V_11 = F_27 ( V_6 ) ;
if ( ! V_11 ) {
F_28 ( L_3 ) ;
F_39 ( & V_6 -> V_69 , V_57 ) ;
return;
}
V_68 = V_65 ( V_11 , V_24 ) ;
F_33 ( V_6 , V_11 ) ;
if ( V_68 ) {
V_66 = F_27 ( V_6 ) ;
if ( ! V_66 ) {
F_28 ( L_4 ) ;
goto V_70;
}
F_2 ( V_66 , V_71 ) ;
F_10 ( V_66 , V_68 -> V_35 ) ;
F_12 ( V_66 ) ;
F_33 ( V_6 , V_66 ) ;
}
V_70:
V_67 = F_31 ( V_6 ) ;
F_39 ( & V_6 -> V_69 , V_57 ) ;
F_36 ( V_6 , V_11 , V_67 ) ;
}
static void F_40 ( struct V_2 * V_26 , T_1 V_37 )
{
struct V_23 V_24 ;
V_24 . V_43 . V_26 = V_26 ;
V_24 . V_43 . V_37 = V_37 ;
F_37 ( V_26 -> V_6 , F_22 , & V_24 ) ;
}
static void F_41 ( struct V_2 * V_26 , int V_20 )
{
struct V_23 V_24 ;
V_24 . V_25 . V_26 = V_26 ;
V_24 . V_25 . V_20 = ! ! V_20 ;
F_37 ( V_26 -> V_6 , F_14 , & V_24 ) ;
}
static void F_42 ( struct V_5 * V_6 , struct V_1 * V_22 ,
int V_20 )
{
struct V_23 V_24 ;
V_24 . V_33 . V_22 = V_22 ;
V_24 . V_33 . V_20 = ! ! V_20 ;
F_37 ( V_6 , F_18 , & V_24 ) ;
}
static void F_43 ( struct V_2 * V_26 , T_1 V_72 , T_1 V_16 )
{
struct V_23 V_24 ;
V_24 . V_36 . V_26 = V_26 ;
V_24 . V_36 . V_17 = V_72 ;
V_24 . V_36 . V_37 = V_16 ;
F_37 ( V_26 -> V_6 , F_19 , & V_24 ) ;
}
static void F_44 ( struct V_2 * V_26 ,
struct V_1 * V_22 , T_1 V_16 )
{
struct V_23 V_24 ;
V_24 . V_39 . V_26 = V_26 ;
V_24 . V_39 . V_22 = V_22 ;
V_24 . V_39 . V_37 = V_16 ;
F_37 ( V_26 -> V_6 , F_20 , & V_24 ) ;
}
static void F_45 ( struct V_2 * V_26 , T_1 V_16 )
{
struct V_23 V_24 ;
V_24 . V_41 . V_26 = V_26 ;
V_24 . V_41 . V_37 = V_16 ;
F_37 ( V_26 -> V_6 , F_21 , & V_24 ) ;
}
static void F_46 ( struct V_5 * V_6 , struct V_1 * V_22 )
{
struct V_23 V_24 ;
V_24 . V_73 . V_22 = V_22 ;
F_37 ( V_6 , F_23 , & V_24 ) ;
}
static inline T_1 F_47 ( struct V_74 * V_75 )
{
struct V_2 * V_3 = F_48 ( V_75 ) ;
return V_75 -> V_76 - V_3 -> V_8 . V_77 ;
}
static void F_49 ( struct V_74 * V_75 , bool V_78 )
{
struct V_2 * V_3 = F_48 ( V_75 ) ;
T_5 V_76 = V_75 -> V_76 ;
T_1 V_16 = F_47 ( V_75 ) ;
T_2 * V_79 = F_50 ( V_80 -> V_81 ) + V_76 - 8192 ;
if ( V_78 )
* V_79 |= V_82 ;
else
* V_79 &= ~ V_82 ;
if ( V_80 -> V_57 & V_83 )
F_34 ( V_79 , sizeof( * V_79 ) ) ;
else
F_35 ( V_59 ) ;
F_40 ( V_3 , V_16 ) ;
}
static void F_51 ( struct V_74 * V_75 )
{
F_49 ( V_75 , false ) ;
}
static void F_52 ( struct V_74 * V_75 )
{
F_49 ( V_75 , true ) ;
}
static int F_53 ( struct V_74 * V_75 , const struct V_84 * V_85 ,
bool V_86 )
{
unsigned int V_87 ;
const struct V_84 * V_88 = V_89 ;
struct V_2 * V_3 = F_48 ( V_75 ) ;
struct V_1 * V_90 ;
T_1 V_16 = F_47 ( V_75 ) ;
if ( V_3 -> V_6 -> V_57 & V_91 ) {
if ( V_3 -> V_6 -> V_92 >= 0 ) {
V_88 = F_54 ( V_3 -> V_6 -> V_92 ) ;
if ( ! F_55 ( V_85 , V_88 ) )
return - V_93 ;
}
}
V_87 = F_56 ( V_85 , V_88 ) ;
if ( V_87 >= V_94 )
return - V_93 ;
V_90 = & V_3 -> V_6 -> V_7 [ V_87 ] ;
F_44 ( V_3 , V_90 , V_16 ) ;
V_3 -> V_8 . V_9 [ V_16 ] = V_87 ;
return V_95 ;
}
static void F_57 ( struct V_74 * V_75 , struct V_96 * V_97 )
{
struct V_2 * V_3 = F_48 ( V_75 ) ;
struct V_5 * V_6 ;
V_15 V_98 ;
V_6 = V_3 -> V_6 ;
V_98 = V_6 -> V_99 + V_100 ;
V_97 -> V_101 = V_98 & ( ( 1UL << 32 ) - 1 ) ;
V_97 -> V_102 = V_98 >> 32 ;
V_97 -> V_103 = F_47 ( V_75 ) ;
F_58 ( V_75 -> V_104 , V_97 ) ;
}
static int F_59 ( int V_105 )
{
return ( V_105 - 8192 ) >> V_106 ;
}
static int F_60 ( int V_107 )
{
return ( V_107 << V_106 ) + 8192 ;
}
static int T_6 F_61 ( T_1 V_108 )
{
V_109 = F_59 ( 1UL << V_108 ) ;
V_110 = F_62 ( F_63 ( V_109 ) * sizeof( long ) ,
V_111 ) ;
if ( ! V_110 ) {
V_109 = 0 ;
return - V_112 ;
}
F_64 ( L_5 , ( int ) V_109 ) ;
return 0 ;
}
static unsigned long * F_65 ( int V_113 , int * V_51 , int * V_114 )
{
unsigned long * V_115 = NULL ;
int V_116 ;
int V_117 ;
int V_118 ;
V_117 = F_66 ( V_113 , V_119 ) ;
F_67 ( & V_120 ) ;
do {
V_116 = F_68 ( V_110 , V_109 ,
0 , V_117 , 0 ) ;
if ( V_116 < V_109 )
break;
V_117 -- ;
} while ( V_117 > 0 );
if ( ! V_117 )
goto V_121;
V_115 = F_62 ( F_63 ( V_117 * V_119 ) * sizeof ( long ) ,
V_122 ) ;
if ( ! V_115 )
goto V_121;
for ( V_118 = 0 ; V_118 < V_117 ; V_118 ++ )
F_69 ( V_116 + V_118 , V_110 ) ;
* V_51 = F_60 ( V_116 ) ;
* V_114 = V_117 * V_119 ;
V_121:
F_70 ( & V_120 ) ;
if ( ! V_115 )
* V_51 = * V_114 = 0 ;
return V_115 ;
}
static void F_71 ( struct V_123 * V_124 )
{
int V_51 = V_124 -> V_77 ;
int V_114 = V_124 -> V_125 ;
int V_105 ;
F_67 ( & V_120 ) ;
for ( V_105 = V_51 ; V_105 < ( V_51 + V_114 ) ; V_105 += V_119 ) {
int V_107 = F_59 ( V_105 ) ;
F_72 ( V_107 > V_109 ) ;
if ( F_73 ( V_107 , V_110 ) ) {
F_74 ( V_107 , V_110 ) ;
} else {
F_75 ( L_6 , V_107 ) ;
}
}
F_70 ( & V_120 ) ;
F_76 ( V_124 -> V_126 ) ;
F_76 ( V_124 -> V_9 ) ;
}
static int T_6 F_77 ( void )
{
T_7 V_127 ;
V_80 -> V_81 = F_78 ( V_128 ,
F_79 ( V_129 ) ) ;
if ( ! V_80 -> V_81 ) {
F_75 ( L_7 ) ;
return - V_112 ;
}
V_127 = F_80 ( V_80 -> V_81 ) ;
F_64 ( L_8 , & V_127 ) ;
memset ( F_50 ( V_80 -> V_81 ) ,
V_130 | V_131 ,
V_129 ) ;
F_34 ( F_50 ( V_80 -> V_81 ) , V_129 ) ;
return 0 ;
}
static V_15 F_81 ( struct V_5 * V_6 , struct V_132 * V_133 )
{
T_1 V_134 = V_133 - V_6 -> V_135 ;
return F_82 ( V_6 -> V_51 + V_136 + ( V_134 << 3 ) ) ;
}
static void F_83 ( struct V_5 * V_6 , struct V_132 * V_133 ,
V_15 V_137 )
{
T_1 V_134 = V_133 - V_6 -> V_135 ;
F_84 ( V_137 , V_6 -> V_51 + V_136 + ( V_134 << 3 ) ) ;
V_133 -> V_137 = F_81 ( V_6 , V_133 ) ;
}
static int F_85 ( struct V_5 * V_6 , struct V_132 * V_133 ,
V_15 V_138 , V_15 V_139 , T_1 V_140 , T_1 V_141 ,
bool V_142 )
{
V_15 V_137 = F_81 ( V_6 , V_133 ) ;
V_15 V_143 = F_86 ( V_137 ) ;
V_15 type = F_87 ( V_137 ) ;
T_1 F_78 ;
void * V_51 ;
V_15 V_144 ;
V_145:
F_78 = ( F_88 ( V_141 ) / V_140 ) ;
if ( F_78 > V_146 ) {
F_89 ( L_9 ,
& V_6 -> V_99 , V_147 [ type ] ,
F_78 , V_146 ) ;
F_78 = V_146 ;
V_141 = F_79 ( V_146 * V_140 ) ;
}
V_51 = ( void * ) F_90 ( V_111 | V_148 , V_141 ) ;
if ( ! V_51 )
return - V_112 ;
V_149:
V_137 = ( F_16 ( V_51 ) |
( type << V_150 ) |
( ( V_143 - 1 ) << V_151 ) |
( ( F_78 - 1 ) << V_152 ) |
V_138 |
V_139 |
V_153 ) ;
V_137 |= V_142 ? V_154 : 0x0 ;
switch ( V_140 ) {
case V_155 :
V_137 |= V_156 ;
break;
case V_157 :
V_137 |= V_158 ;
break;
case V_159 :
V_137 |= V_160 ;
break;
}
F_83 ( V_6 , V_133 , V_137 ) ;
V_144 = V_133 -> V_137 ;
if ( ( V_137 ^ V_144 ) & V_161 ) {
V_139 = V_144 & V_161 ;
if ( ! V_139 ) {
V_138 = V_162 ;
F_34 ( V_51 , F_88 ( V_141 ) ) ;
}
goto V_149;
}
if ( ( V_137 ^ V_144 ) & V_163 ) {
F_91 ( ( unsigned long ) V_51 , V_141 ) ;
V_133 -> V_51 = NULL ;
switch ( V_140 ) {
case V_157 :
V_140 = V_155 ;
goto V_145;
case V_159 :
V_140 = V_157 ;
goto V_145;
}
}
if ( V_137 != V_144 ) {
F_75 ( L_10 ,
& V_6 -> V_99 , V_147 [ type ] ,
( unsigned long ) V_137 , ( unsigned long ) V_144 ) ;
F_91 ( ( unsigned long ) V_51 , V_141 ) ;
return - V_164 ;
}
V_133 -> V_141 = V_141 ;
V_133 -> V_51 = V_51 ;
V_133 -> V_140 = V_140 ;
V_144 = V_142 ? V_165 : V_143 ;
F_64 ( L_11 ,
& V_6 -> V_99 , ( int ) ( F_88 ( V_141 ) / V_144 ) ,
V_147 [ type ] ,
( unsigned long ) F_16 ( V_51 ) ,
V_142 ? L_12 : L_13 , ( int ) V_143 ,
V_140 / V_166 , ( int ) V_139 >> V_167 ) ;
return 0 ;
}
static bool F_92 ( struct V_5 * V_6 , struct V_132 * V_133 ,
T_1 V_140 , T_1 * V_141 )
{
V_15 V_143 = F_86 ( F_81 ( V_6 , V_133 ) ) ;
V_15 V_137 = V_168 | V_169 ;
T_1 V_170 = V_6 -> V_171 ;
T_1 V_172 = * V_141 ;
bool V_142 = false ;
if ( ( V_143 << V_170 ) > ( V_140 * 2 ) ) {
F_83 ( V_6 , V_133 , V_137 | V_154 ) ;
V_142 = ! ! ( V_133 -> V_137 & V_154 ) ;
if ( V_142 ) {
V_170 -= F_15 ( V_140 / V_143 ) ;
V_143 = V_165 ;
}
}
V_172 = F_93 ( T_1 , F_79 ( V_143 << V_170 ) , V_172 ) ;
if ( V_172 >= V_173 ) {
V_172 = V_173 - 1 ;
V_170 = F_15 ( F_88 ( V_172 ) / V_143 ) ;
F_89 ( L_14 ,
& V_6 -> V_99 , V_6 -> V_171 , V_170 ) ;
}
* V_141 = V_172 ;
return V_142 ;
}
static void F_94 ( struct V_5 * V_6 )
{
int V_118 ;
for ( V_118 = 0 ; V_118 < V_174 ; V_118 ++ ) {
if ( V_6 -> V_135 [ V_118 ] . V_51 ) {
F_91 ( ( unsigned long ) V_6 -> V_135 [ V_118 ] . V_51 ,
V_6 -> V_135 [ V_118 ] . V_141 ) ;
V_6 -> V_135 [ V_118 ] . V_51 = NULL ;
}
}
}
static int F_95 ( struct V_5 * V_6 )
{
V_15 V_175 = F_96 ( V_6 -> V_51 + V_176 ) ;
T_1 V_170 = F_97 ( V_175 ) ;
V_15 V_139 = V_168 ;
V_15 V_138 = V_169 ;
T_1 V_140 = V_159 ;
int V_177 , V_118 ;
if ( V_6 -> V_57 & V_178 ) {
V_138 = V_179 ;
V_170 = 0x14 ;
}
V_6 -> V_171 = V_170 ;
for ( V_118 = 0 ; V_118 < V_174 ; V_118 ++ ) {
struct V_132 * V_133 = V_6 -> V_135 + V_118 ;
V_15 V_137 = F_81 ( V_6 , V_133 ) ;
V_15 type = F_87 ( V_137 ) ;
T_1 V_141 = F_79 ( V_140 ) ;
bool V_142 = false ;
if ( type == V_180 )
continue;
if ( type == V_181 )
V_142 = F_92 ( V_6 , V_133 , V_140 , & V_141 ) ;
V_177 = F_85 ( V_6 , V_133 , V_138 , V_139 , V_140 , V_141 , V_142 ) ;
if ( V_177 < 0 ) {
F_94 ( V_6 ) ;
return V_177 ;
}
V_140 = V_133 -> V_140 ;
V_138 = V_133 -> V_137 & V_182 ;
V_139 = V_133 -> V_137 & V_161 ;
}
return 0 ;
}
static int F_98 ( struct V_5 * V_6 )
{
V_6 -> V_7 = F_62 ( V_94 * sizeof( * V_6 -> V_7 ) ,
V_111 ) ;
if ( ! V_6 -> V_7 )
return - V_112 ;
return 0 ;
}
static void F_99 ( void )
{
void T_8 * V_183 = F_100 () ;
struct V_184 * V_185 ;
V_15 V_137 , V_144 ;
V_185 = F_101 () -> V_185 ;
if ( ! V_185 ) {
T_7 V_127 ;
V_185 = F_78 ( V_128 | V_148 ,
F_79 ( F_102 ( V_186 , V_159 ) ) ) ;
if ( ! V_185 ) {
F_75 ( L_15 ,
F_103 () ) ;
return;
}
F_34 ( F_50 ( V_185 ) , V_186 ) ;
V_127 = F_80 ( V_185 ) ;
F_64 ( L_16 ,
F_103 () , & V_127 ) ;
F_101 () -> V_185 = V_185 ;
}
V_137 = F_26 ( V_183 + V_187 ) ;
V_137 &= ~ V_188 ;
F_32 ( V_137 , V_183 + V_187 ) ;
F_35 ( V_189 ) ;
V_137 = ( F_80 ( V_80 -> V_81 ) |
V_190 |
V_191 |
( ( V_192 - 1 ) & V_193 ) ) ;
F_84 ( V_137 , V_183 + V_194 ) ;
V_144 = F_82 ( V_183 + V_194 ) ;
if ( ( V_144 ^ V_137 ) & V_195 ) {
if ( ! ( V_144 & V_195 ) ) {
V_137 &= ~ ( V_195 |
V_196 ) ;
V_137 |= V_197 ;
F_84 ( V_137 , V_183 + V_194 ) ;
}
F_104 ( L_17 ) ;
V_80 -> V_57 |= V_83 ;
}
V_137 = ( F_80 ( V_185 ) |
V_198 |
V_199 ) ;
F_84 ( V_137 , V_183 + V_200 ) ;
V_144 = F_82 ( V_183 + V_200 ) ;
if ( ! ( V_144 & V_201 ) ) {
V_137 &= ~ ( V_201 |
V_202 ) ;
V_137 |= V_203 ;
F_84 ( V_137 , V_183 + V_200 ) ;
}
V_137 = F_26 ( V_183 + V_187 ) ;
V_137 |= V_188 ;
F_32 ( V_137 , V_183 + V_187 ) ;
F_35 ( V_189 ) ;
}
static void F_105 ( void )
{
struct V_5 * V_6 ;
int V_87 ;
F_67 ( & V_204 ) ;
V_87 = F_103 () ;
F_106 (its, &its_nodes, entry) {
V_15 V_205 ;
if ( V_6 -> V_57 & V_91 ) {
struct V_206 * V_207 ;
V_207 = F_107 ( V_87 , NULL ) ;
if ( V_6 -> V_92 != V_208 &&
V_6 -> V_92 != F_108 ( V_207 ) )
continue;
}
if ( F_96 ( V_6 -> V_51 + V_176 ) & V_209 ) {
V_205 = F_101 () -> V_99 ;
} else {
V_205 = F_96 ( F_100 () + V_210 ) ;
V_205 = F_109 ( V_205 ) << 16 ;
}
V_6 -> V_7 [ V_87 ] . V_35 = V_205 ;
V_6 -> V_7 [ V_87 ] . V_34 = V_87 ;
F_42 ( V_6 , & V_6 -> V_7 [ V_87 ] , 1 ) ;
F_46 ( V_6 , & V_6 -> V_7 [ V_87 ] ) ;
}
F_70 ( & V_204 ) ;
}
static struct V_2 * F_110 ( struct V_5 * V_6 , T_1 V_211 )
{
struct V_2 * V_3 = NULL , * V_144 ;
unsigned long V_57 ;
F_38 ( & V_6 -> V_69 , V_57 ) ;
F_106 (tmp, &its->its_device_list, entry) {
if ( V_144 -> V_31 == V_211 ) {
V_3 = V_144 ;
break;
}
}
F_39 ( & V_6 -> V_69 , V_57 ) ;
return V_3 ;
}
static struct V_132 * F_111 ( struct V_5 * V_6 , T_1 type )
{
int V_118 ;
for ( V_118 = 0 ; V_118 < V_174 ; V_118 ++ ) {
if ( F_87 ( V_6 -> V_135 [ V_118 ] . V_137 ) == type )
return & V_6 -> V_135 [ V_118 ] ;
}
return NULL ;
}
static bool F_112 ( struct V_5 * V_6 , T_1 V_211 )
{
struct V_132 * V_133 ;
struct V_184 * V_184 ;
T_1 V_143 , V_134 ;
T_9 * V_212 ;
V_133 = F_111 ( V_6 , V_181 ) ;
if ( ! V_133 )
return ( F_15 ( V_211 ) < V_6 -> V_171 ) ;
V_143 = F_86 ( V_133 -> V_137 ) ;
if ( ! ( V_133 -> V_137 & V_154 ) )
return ( V_211 < ( F_88 ( V_133 -> V_141 ) / V_143 ) ) ;
V_134 = V_211 >> F_15 ( V_133 -> V_140 / V_143 ) ;
if ( V_134 >= ( F_88 ( V_133 -> V_141 ) / V_165 ) )
return false ;
V_212 = V_133 -> V_51 ;
if ( ! V_212 [ V_134 ] ) {
V_184 = F_78 ( V_111 | V_148 , F_79 ( V_133 -> V_140 ) ) ;
if ( ! V_184 )
return false ;
if ( ! ( V_133 -> V_137 & V_161 ) )
F_34 ( F_50 ( V_184 ) , V_133 -> V_140 ) ;
V_212 [ V_134 ] = F_13 ( F_80 ( V_184 ) | V_153 ) ;
if ( ! ( V_133 -> V_137 & V_161 ) )
F_34 ( V_212 + V_134 , V_165 ) ;
F_35 ( V_189 ) ;
}
return true ;
}
static struct V_2 * F_113 ( struct V_5 * V_6 , T_1 V_211 ,
int V_213 )
{
struct V_2 * V_26 ;
unsigned long * V_126 ;
unsigned long V_57 ;
T_3 * V_9 = NULL ;
void * V_28 ;
int V_77 ;
int V_125 ;
int V_27 ;
int V_214 ;
if ( ! F_112 ( V_6 , V_211 ) )
return NULL ;
V_26 = F_62 ( sizeof( * V_26 ) , V_111 ) ;
V_27 = F_102 ( 2UL , F_114 ( V_213 ) ) ;
V_214 = V_27 * V_6 -> V_215 ;
V_214 = F_102 ( V_214 , V_29 ) + V_29 - 1 ;
V_28 = F_62 ( V_214 , V_111 ) ;
V_126 = F_65 ( V_213 , & V_77 , & V_125 ) ;
if ( V_126 )
V_9 = F_62 ( sizeof( * V_9 ) * V_125 , V_111 ) ;
if ( ! V_26 || ! V_28 || ! V_126 || ! V_9 ) {
F_76 ( V_26 ) ;
F_76 ( V_28 ) ;
F_76 ( V_126 ) ;
F_76 ( V_9 ) ;
return NULL ;
}
F_34 ( V_28 , V_214 ) ;
V_26 -> V_6 = V_6 ;
V_26 -> V_28 = V_28 ;
V_26 -> V_27 = V_27 ;
V_26 -> V_8 . V_126 = V_126 ;
V_26 -> V_8 . V_9 = V_9 ;
V_26 -> V_8 . V_77 = V_77 ;
V_26 -> V_8 . V_125 = V_125 ;
V_26 -> V_31 = V_211 ;
F_115 ( & V_26 -> V_216 ) ;
F_38 ( & V_6 -> V_69 , V_57 ) ;
F_116 ( & V_26 -> V_216 , & V_6 -> V_217 ) ;
F_39 ( & V_6 -> V_69 , V_57 ) ;
F_41 ( V_26 , 1 ) ;
return V_26 ;
}
static void F_117 ( struct V_2 * V_3 )
{
unsigned long V_57 ;
F_38 ( & V_3 -> V_6 -> V_69 , V_57 ) ;
F_118 ( & V_3 -> V_216 ) ;
F_39 ( & V_3 -> V_6 -> V_69 , V_57 ) ;
F_76 ( V_3 -> V_28 ) ;
F_76 ( V_3 ) ;
}
static int F_119 ( struct V_2 * V_26 , T_5 * V_76 )
{
int V_134 ;
V_134 = F_120 ( V_26 -> V_8 . V_126 ,
V_26 -> V_8 . V_125 ) ;
if ( V_134 == V_26 -> V_8 . V_125 )
return - V_218 ;
* V_76 = V_26 -> V_8 . V_77 + V_134 ;
F_69 ( V_134 , V_26 -> V_8 . V_126 ) ;
return 0 ;
}
static int F_121 ( struct V_219 * V_220 , struct V_221 * V_26 ,
int V_222 , T_10 * V_223 )
{
struct V_5 * V_6 ;
struct V_2 * V_3 ;
struct V_224 * V_225 ;
T_1 V_211 ;
V_211 = V_223 -> V_226 [ 0 ] . V_227 ;
V_225 = F_122 ( V_220 ) ;
V_6 = V_225 -> V_103 ;
V_3 = F_110 ( V_6 , V_211 ) ;
if ( V_3 ) {
F_123 ( L_18 , V_211 ) ;
goto V_121;
}
V_3 = F_113 ( V_6 , V_211 , V_222 ) ;
if ( ! V_3 )
return - V_112 ;
F_123 ( L_19 , V_222 , F_15 ( V_222 ) ) ;
V_121:
V_223 -> V_226 [ 0 ] . V_46 = V_3 ;
return 0 ;
}
static int F_124 ( struct V_219 * V_220 ,
unsigned int V_228 ,
T_5 V_76 )
{
struct V_229 V_230 ;
if ( F_125 ( V_220 -> V_231 ) ) {
V_230 . V_232 = V_220 -> V_231 -> V_232 ;
V_230 . V_233 = 3 ;
V_230 . V_234 [ 0 ] = V_235 ;
V_230 . V_234 [ 1 ] = V_76 ;
V_230 . V_234 [ 2 ] = V_236 ;
} else if ( F_126 ( V_220 -> V_231 -> V_232 ) ) {
V_230 . V_232 = V_220 -> V_231 -> V_232 ;
V_230 . V_233 = 2 ;
V_230 . V_234 [ 0 ] = V_76 ;
V_230 . V_234 [ 1 ] = V_236 ;
} else {
return - V_93 ;
}
return F_127 ( V_220 , V_228 , 1 , & V_230 ) ;
}
static int F_128 ( struct V_219 * V_220 , unsigned int V_228 ,
unsigned int V_113 , void * args )
{
T_10 * V_223 = args ;
struct V_2 * V_3 = V_223 -> V_226 [ 0 ] . V_46 ;
T_5 V_76 ;
int V_177 ;
int V_118 ;
for ( V_118 = 0 ; V_118 < V_113 ; V_118 ++ ) {
V_177 = F_119 ( V_3 , & V_76 ) ;
if ( V_177 )
return V_177 ;
V_177 = F_124 ( V_220 , V_228 + V_118 , V_76 ) ;
if ( V_177 )
return V_177 ;
F_129 ( V_220 , V_228 + V_118 ,
V_76 , & V_237 , V_3 ) ;
F_123 ( L_20 ,
( int ) ( V_76 - V_3 -> V_8 . V_77 ) ,
( int ) V_76 , V_228 + V_118 ) ;
}
return 0 ;
}
static void F_130 ( struct V_219 * V_220 ,
struct V_74 * V_75 )
{
struct V_2 * V_3 = F_48 ( V_75 ) ;
T_1 V_4 = F_47 ( V_75 ) ;
const struct V_84 * V_88 = V_89 ;
if ( V_3 -> V_6 -> V_92 >= 0 )
V_88 = F_54 ( V_3 -> V_6 -> V_92 ) ;
V_3 -> V_8 . V_9 [ V_4 ] = F_131 ( V_88 ) ;
F_43 ( V_3 , V_75 -> V_76 , V_4 ) ;
}
static void F_132 ( struct V_219 * V_220 ,
struct V_74 * V_75 )
{
struct V_2 * V_3 = F_48 ( V_75 ) ;
T_1 V_4 = F_47 ( V_75 ) ;
F_45 ( V_3 , V_4 ) ;
}
static void F_133 ( struct V_219 * V_220 , unsigned int V_228 ,
unsigned int V_113 )
{
struct V_74 * V_75 = F_134 ( V_220 , V_228 ) ;
struct V_2 * V_3 = F_48 ( V_75 ) ;
int V_118 ;
for ( V_118 = 0 ; V_118 < V_113 ; V_118 ++ ) {
struct V_74 * V_103 = F_134 ( V_220 ,
V_228 + V_118 ) ;
T_1 V_4 = F_47 ( V_103 ) ;
F_74 ( V_4 , V_3 -> V_8 . V_126 ) ;
F_135 ( V_103 ) ;
}
if ( F_136 ( V_3 -> V_8 . V_126 ,
V_3 -> V_8 . V_125 ) ) {
F_71 ( & V_3 -> V_8 ) ;
F_41 ( V_3 , 0 ) ;
F_117 ( V_3 ) ;
}
F_137 ( V_220 , V_228 , V_113 ) ;
}
static int F_138 ( void T_8 * V_51 )
{
T_1 V_54 = 1000000 ;
T_1 V_137 ;
V_137 = F_26 ( V_51 + V_238 ) ;
if ( ( V_137 & V_239 ) && ! ( V_137 & V_240 ) )
return 0 ;
V_137 &= ~ V_240 ;
F_32 ( V_137 , V_51 + V_238 ) ;
while ( 1 ) {
V_137 = F_26 ( V_51 + V_238 ) ;
if ( V_137 & V_239 )
return 0 ;
V_54 -- ;
if ( ! V_54 )
return - V_241 ;
F_29 () ;
F_30 ( 1 ) ;
}
}
static void T_11 F_139 ( void * V_103 )
{
struct V_5 * V_6 = V_103 ;
V_6 -> V_57 |= V_178 ;
}
static void T_11 F_140 ( void * V_103 )
{
struct V_5 * V_6 = V_103 ;
V_6 -> V_57 |= V_91 ;
}
static void F_141 ( struct V_5 * V_6 )
{
T_1 V_242 = F_26 ( V_6 -> V_51 + V_243 ) ;
F_142 ( V_242 , V_244 , V_6 ) ;
}
static int F_143 ( struct V_245 * V_246 , struct V_5 * V_6 )
{
struct V_219 * V_247 ;
struct V_224 * V_223 ;
V_223 = F_62 ( sizeof( * V_223 ) , V_111 ) ;
if ( ! V_223 )
return - V_112 ;
V_247 = F_144 ( V_246 , & V_248 , V_6 ) ;
if ( ! V_247 ) {
F_76 ( V_223 ) ;
return - V_112 ;
}
V_247 -> V_231 = V_249 ;
V_247 -> V_250 = V_251 ;
V_223 -> V_252 = & V_253 ;
V_223 -> V_103 = V_6 ;
V_247 -> V_254 = V_223 ;
return 0 ;
}
static int T_6 F_145 ( struct V_255 * V_256 ,
struct V_245 * V_246 , int V_92 )
{
struct V_5 * V_6 ;
void T_8 * V_257 ;
T_1 V_137 ;
V_15 V_133 , V_144 ;
int V_177 ;
V_257 = F_146 ( V_256 -> V_258 , F_147 ( V_256 ) ) ;
if ( ! V_257 ) {
F_89 ( L_21 , & V_256 -> V_258 ) ;
return - V_112 ;
}
V_137 = F_26 ( V_257 + V_259 ) & V_260 ;
if ( V_137 != 0x30 && V_137 != 0x40 ) {
F_89 ( L_22 , & V_256 -> V_258 ) ;
V_177 = - V_261 ;
goto V_262;
}
V_177 = F_138 ( V_257 ) ;
if ( V_177 ) {
F_89 ( L_23 , & V_256 -> V_258 ) ;
goto V_262;
}
F_64 ( L_24 , V_256 ) ;
V_6 = F_62 ( sizeof( * V_6 ) , V_111 ) ;
if ( ! V_6 ) {
V_177 = - V_112 ;
goto V_262;
}
F_148 ( & V_6 -> V_69 ) ;
F_115 ( & V_6 -> V_216 ) ;
F_115 ( & V_6 -> V_217 ) ;
V_6 -> V_51 = V_257 ;
V_6 -> V_99 = V_256 -> V_258 ;
V_6 -> V_215 = ( ( F_96 ( V_257 + V_176 ) >> 4 ) & 0xf ) + 1 ;
V_6 -> V_92 = V_92 ;
V_6 -> V_47 = F_62 ( V_263 , V_111 ) ;
if ( ! V_6 -> V_47 ) {
V_177 = - V_112 ;
goto V_264;
}
V_6 -> V_50 = V_6 -> V_47 ;
F_141 ( V_6 ) ;
V_177 = F_95 ( V_6 ) ;
if ( V_177 )
goto V_265;
V_177 = F_98 ( V_6 ) ;
if ( V_177 )
goto V_266;
V_133 = ( F_16 ( V_6 -> V_47 ) |
V_267 |
V_268 |
( V_263 / V_155 - 1 ) |
V_269 ) ;
F_84 ( V_133 , V_6 -> V_51 + V_270 ) ;
V_144 = F_82 ( V_6 -> V_51 + V_270 ) ;
if ( ( V_144 ^ V_133 ) & V_271 ) {
if ( ! ( V_144 & V_271 ) ) {
V_133 &= ~ ( V_271 |
V_272 ) ;
V_133 |= V_273 ;
F_84 ( V_133 , V_6 -> V_51 + V_270 ) ;
}
F_64 ( L_25 ) ;
V_6 -> V_57 |= V_58 ;
}
F_84 ( 0 , V_6 -> V_51 + V_56 ) ;
F_32 ( V_240 , V_6 -> V_51 + V_238 ) ;
V_177 = F_143 ( V_246 , V_6 ) ;
if ( V_177 )
goto V_266;
F_67 ( & V_204 ) ;
F_116 ( & V_6 -> V_216 , & V_274 ) ;
F_70 ( & V_204 ) ;
return 0 ;
V_266:
F_94 ( V_6 ) ;
V_265:
F_76 ( V_6 -> V_47 ) ;
V_264:
F_76 ( V_6 ) ;
V_262:
F_149 ( V_257 ) ;
F_75 ( L_26 , & V_256 -> V_258 , V_177 ) ;
return V_177 ;
}
static bool F_150 ( void )
{
return ! ! ( F_96 ( F_100 () + V_210 ) & V_275 ) ;
}
int F_151 ( void )
{
if ( ! F_152 ( & V_274 ) ) {
if ( ! F_150 () ) {
F_64 ( L_27 , F_103 () ) ;
return - V_164 ;
}
F_99 () ;
F_105 () ;
}
return 0 ;
}
static int T_6 F_153 ( struct V_206 * V_276 )
{
struct V_206 * V_277 ;
struct V_255 V_256 ;
for ( V_277 = F_154 ( V_276 , V_278 ) ; V_277 ;
V_277 = F_154 ( V_277 , V_278 ) ) {
if ( ! F_155 ( V_277 , L_28 ) ) {
F_89 ( L_29 ,
V_277 -> V_279 ) ;
continue;
}
if ( F_156 ( V_277 , 0 , & V_256 ) ) {
F_89 ( L_30 , V_277 -> V_279 ) ;
continue;
}
F_145 ( & V_256 , & V_277 -> V_232 , F_108 ( V_277 ) ) ;
}
return 0 ;
}
static int T_6 F_157 ( struct V_280 * V_281 ,
const unsigned long V_282 )
{
struct V_283 * V_284 ;
struct V_245 * V_285 ;
struct V_255 V_256 ;
int V_177 ;
V_284 = (struct V_283 * ) V_281 ;
memset ( & V_256 , 0 , sizeof( V_256 ) ) ;
V_256 . V_258 = V_284 -> V_286 ;
V_256 . V_282 = V_284 -> V_286 + V_287 - 1 ;
V_256 . V_57 = V_288 ;
V_285 = F_158 ( ( void * ) V_284 -> V_286 ) ;
if ( ! V_285 ) {
F_75 ( L_31 ,
& V_256 . V_258 ) ;
return - V_112 ;
}
V_177 = F_159 ( V_284 -> V_289 , V_285 ) ;
if ( V_177 ) {
F_75 ( L_32 ,
& V_256 . V_258 , V_284 -> V_289 ) ;
goto V_290;
}
V_177 = F_145 ( & V_256 , V_285 , V_208 ) ;
if ( ! V_177 )
return 0 ;
F_160 ( V_284 -> V_289 ) ;
V_290:
F_161 ( V_285 ) ;
return V_177 ;
}
static void T_6 F_162 ( void )
{
F_163 ( V_291 ,
F_157 , 0 ) ;
}
static void T_6 F_162 ( void ) { }
int T_6 F_164 ( struct V_245 * V_246 , struct V_292 * V_292 ,
struct V_219 * V_293 )
{
struct V_206 * V_294 ;
V_249 = V_293 ;
V_294 = F_165 ( V_246 ) ;
if ( V_294 )
F_153 ( V_294 ) ;
else
F_162 () ;
if ( F_152 ( & V_274 ) ) {
F_89 ( L_33 ) ;
return - V_164 ;
}
V_80 = V_292 ;
F_77 () ;
F_61 ( V_292 -> V_108 ) ;
return 0 ;
}
