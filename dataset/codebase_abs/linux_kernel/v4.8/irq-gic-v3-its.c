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
}
static int F_58 ( int V_104 )
{
return ( V_104 - 8192 ) >> V_105 ;
}
static int F_59 ( int V_106 )
{
return ( V_106 << V_105 ) + 8192 ;
}
static int T_6 F_60 ( T_1 V_107 )
{
V_108 = F_58 ( 1UL << V_107 ) ;
V_109 = F_61 ( F_62 ( V_108 ) * sizeof( long ) ,
V_110 ) ;
if ( ! V_109 ) {
V_108 = 0 ;
return - V_111 ;
}
F_63 ( L_5 , ( int ) V_108 ) ;
return 0 ;
}
static unsigned long * F_64 ( int V_112 , int * V_51 , int * V_113 )
{
unsigned long * V_114 = NULL ;
int V_115 ;
int V_116 ;
int V_117 ;
V_116 = F_65 ( V_112 , V_118 ) ;
F_66 ( & V_119 ) ;
do {
V_115 = F_67 ( V_109 , V_108 ,
0 , V_116 , 0 ) ;
if ( V_115 < V_108 )
break;
V_116 -- ;
} while ( V_116 > 0 );
if ( ! V_116 )
goto V_120;
V_114 = F_61 ( F_62 ( V_116 * V_118 ) * sizeof ( long ) ,
V_121 ) ;
if ( ! V_114 )
goto V_120;
for ( V_117 = 0 ; V_117 < V_116 ; V_117 ++ )
F_68 ( V_115 + V_117 , V_109 ) ;
* V_51 = F_59 ( V_115 ) ;
* V_113 = V_116 * V_118 ;
V_120:
F_69 ( & V_119 ) ;
if ( ! V_114 )
* V_51 = * V_113 = 0 ;
return V_114 ;
}
static void F_70 ( struct V_122 * V_123 )
{
int V_51 = V_123 -> V_77 ;
int V_113 = V_123 -> V_124 ;
int V_104 ;
F_66 ( & V_119 ) ;
for ( V_104 = V_51 ; V_104 < ( V_51 + V_113 ) ; V_104 += V_118 ) {
int V_106 = F_58 ( V_104 ) ;
F_71 ( V_106 > V_108 ) ;
if ( F_72 ( V_106 , V_109 ) ) {
F_73 ( V_106 , V_109 ) ;
} else {
F_74 ( L_6 , V_106 ) ;
}
}
F_69 ( & V_119 ) ;
F_75 ( V_123 -> V_125 ) ;
F_75 ( V_123 -> V_9 ) ;
}
static int T_6 F_76 ( void )
{
T_7 V_126 ;
V_80 -> V_81 = F_77 ( V_127 ,
F_78 ( V_128 ) ) ;
if ( ! V_80 -> V_81 ) {
F_74 ( L_7 ) ;
return - V_111 ;
}
V_126 = F_79 ( V_80 -> V_81 ) ;
F_63 ( L_8 , & V_126 ) ;
memset ( F_50 ( V_80 -> V_81 ) ,
V_129 | V_130 ,
V_128 ) ;
F_34 ( F_50 ( V_80 -> V_81 ) , V_128 ) ;
return 0 ;
}
static V_15 F_80 ( struct V_5 * V_6 , struct V_131 * V_132 )
{
T_1 V_133 = V_132 - V_6 -> V_134 ;
return F_81 ( V_6 -> V_51 + V_135 + ( V_133 << 3 ) ) ;
}
static void F_82 ( struct V_5 * V_6 , struct V_131 * V_132 ,
V_15 V_136 )
{
T_1 V_133 = V_132 - V_6 -> V_134 ;
F_83 ( V_136 , V_6 -> V_51 + V_135 + ( V_133 << 3 ) ) ;
V_132 -> V_136 = F_80 ( V_6 , V_132 ) ;
}
static int F_84 ( struct V_5 * V_6 , struct V_131 * V_132 ,
V_15 V_137 , V_15 V_138 , T_1 V_139 , T_1 V_140 ,
bool V_141 )
{
V_15 V_136 = F_80 ( V_6 , V_132 ) ;
V_15 V_142 = F_85 ( V_136 ) ;
V_15 type = F_86 ( V_136 ) ;
T_1 F_77 ;
void * V_51 ;
V_15 V_143 ;
V_144:
F_77 = ( F_87 ( V_140 ) / V_139 ) ;
if ( F_77 > V_145 ) {
F_88 ( L_9 ,
& V_6 -> V_99 , V_146 [ type ] ,
F_77 , V_145 ) ;
F_77 = V_145 ;
V_140 = F_78 ( V_145 * V_139 ) ;
}
V_51 = ( void * ) F_89 ( V_110 | V_147 , V_140 ) ;
if ( ! V_51 )
return - V_111 ;
V_148:
V_136 = ( F_16 ( V_51 ) |
( type << V_149 ) |
( ( V_142 - 1 ) << V_150 ) |
( ( F_77 - 1 ) << V_151 ) |
V_137 |
V_138 |
V_152 ) ;
V_136 |= V_141 ? V_153 : 0x0 ;
switch ( V_139 ) {
case V_154 :
V_136 |= V_155 ;
break;
case V_156 :
V_136 |= V_157 ;
break;
case V_158 :
V_136 |= V_159 ;
break;
}
F_82 ( V_6 , V_132 , V_136 ) ;
V_143 = V_132 -> V_136 ;
if ( ( V_136 ^ V_143 ) & V_160 ) {
V_138 = V_143 & V_160 ;
if ( ! V_138 ) {
V_137 = V_161 ;
F_34 ( V_51 , F_87 ( V_140 ) ) ;
}
goto V_148;
}
if ( ( V_136 ^ V_143 ) & V_162 ) {
F_90 ( ( unsigned long ) V_51 , V_140 ) ;
V_132 -> V_51 = NULL ;
switch ( V_139 ) {
case V_156 :
V_139 = V_154 ;
goto V_144;
case V_158 :
V_139 = V_156 ;
goto V_144;
}
}
if ( V_136 != V_143 ) {
F_74 ( L_10 ,
& V_6 -> V_99 , V_146 [ type ] ,
( unsigned long ) V_136 , ( unsigned long ) V_143 ) ;
F_90 ( ( unsigned long ) V_51 , V_140 ) ;
return - V_163 ;
}
V_132 -> V_140 = V_140 ;
V_132 -> V_51 = V_51 ;
V_132 -> V_139 = V_139 ;
V_143 = V_141 ? V_164 : V_142 ;
F_63 ( L_11 ,
& V_6 -> V_99 , ( int ) ( F_87 ( V_140 ) / V_143 ) ,
V_146 [ type ] ,
( unsigned long ) F_16 ( V_51 ) ,
V_141 ? L_12 : L_13 , ( int ) V_142 ,
V_139 / V_165 , ( int ) V_138 >> V_166 ) ;
return 0 ;
}
static bool F_91 ( struct V_5 * V_6 , struct V_131 * V_132 ,
T_1 V_139 , T_1 * V_140 )
{
V_15 V_142 = F_85 ( F_80 ( V_6 , V_132 ) ) ;
V_15 V_136 = V_167 | V_168 ;
T_1 V_169 = V_6 -> V_170 ;
T_1 V_171 = * V_140 ;
bool V_141 = false ;
if ( ( V_142 << V_169 ) > ( V_139 * 2 ) ) {
F_82 ( V_6 , V_132 , V_136 | V_153 ) ;
V_141 = ! ! ( V_132 -> V_136 & V_153 ) ;
if ( V_141 ) {
V_169 -= F_15 ( V_139 / V_142 ) ;
V_142 = V_164 ;
}
}
V_171 = F_92 ( T_1 , F_78 ( V_142 << V_169 ) , V_171 ) ;
if ( V_171 >= V_172 ) {
V_171 = V_172 - 1 ;
V_169 = F_15 ( F_87 ( V_171 ) / V_142 ) ;
F_88 ( L_14 ,
& V_6 -> V_99 , V_6 -> V_170 , V_169 ) ;
}
* V_140 = V_171 ;
return V_141 ;
}
static void F_93 ( struct V_5 * V_6 )
{
int V_117 ;
for ( V_117 = 0 ; V_117 < V_173 ; V_117 ++ ) {
if ( V_6 -> V_134 [ V_117 ] . V_51 ) {
F_90 ( ( unsigned long ) V_6 -> V_134 [ V_117 ] . V_51 ,
V_6 -> V_134 [ V_117 ] . V_140 ) ;
V_6 -> V_134 [ V_117 ] . V_51 = NULL ;
}
}
}
static int F_94 ( struct V_5 * V_6 )
{
V_15 V_174 = F_81 ( V_6 -> V_51 + V_175 ) ;
T_1 V_169 = F_95 ( V_174 ) ;
V_15 V_138 = V_167 ;
V_15 V_137 = V_168 ;
T_1 V_139 = V_158 ;
int V_176 , V_117 ;
if ( V_6 -> V_57 & V_177 ) {
V_137 = V_178 ;
V_169 = 0x14 ;
}
V_6 -> V_170 = V_169 ;
for ( V_117 = 0 ; V_117 < V_173 ; V_117 ++ ) {
struct V_131 * V_132 = V_6 -> V_134 + V_117 ;
V_15 V_136 = F_80 ( V_6 , V_132 ) ;
V_15 type = F_86 ( V_136 ) ;
T_1 V_140 = F_78 ( V_139 ) ;
bool V_141 = false ;
if ( type == V_179 )
continue;
if ( type == V_180 )
V_141 = F_91 ( V_6 , V_132 , V_139 , & V_140 ) ;
V_176 = F_84 ( V_6 , V_132 , V_137 , V_138 , V_139 , V_140 , V_141 ) ;
if ( V_176 < 0 ) {
F_93 ( V_6 ) ;
return V_176 ;
}
V_139 = V_132 -> V_139 ;
V_137 = V_132 -> V_136 & V_181 ;
V_138 = V_132 -> V_136 & V_160 ;
}
return 0 ;
}
static int F_96 ( struct V_5 * V_6 )
{
V_6 -> V_7 = F_61 ( V_94 * sizeof( * V_6 -> V_7 ) ,
V_110 ) ;
if ( ! V_6 -> V_7 )
return - V_111 ;
return 0 ;
}
static void F_97 ( void )
{
void T_8 * V_182 = F_98 () ;
struct V_183 * V_184 ;
V_15 V_136 , V_143 ;
V_184 = F_99 () -> V_184 ;
if ( ! V_184 ) {
T_7 V_126 ;
V_184 = F_77 ( V_127 | V_147 ,
F_78 ( F_100 ( V_185 , V_158 ) ) ) ;
if ( ! V_184 ) {
F_74 ( L_15 ,
F_101 () ) ;
return;
}
F_34 ( F_50 ( V_184 ) , V_185 ) ;
V_126 = F_79 ( V_184 ) ;
F_63 ( L_16 ,
F_101 () , & V_126 ) ;
F_99 () -> V_184 = V_184 ;
}
V_136 = F_26 ( V_182 + V_186 ) ;
V_136 &= ~ V_187 ;
F_32 ( V_136 , V_182 + V_186 ) ;
F_35 ( V_188 ) ;
V_136 = ( F_79 ( V_80 -> V_81 ) |
V_189 |
V_190 |
( ( V_191 - 1 ) & V_192 ) ) ;
F_83 ( V_136 , V_182 + V_193 ) ;
V_143 = F_81 ( V_182 + V_193 ) ;
if ( ( V_143 ^ V_136 ) & V_194 ) {
if ( ! ( V_143 & V_194 ) ) {
V_136 &= ~ ( V_194 |
V_195 ) ;
V_136 |= V_196 ;
F_83 ( V_136 , V_182 + V_193 ) ;
}
F_102 ( L_17 ) ;
V_80 -> V_57 |= V_83 ;
}
V_136 = ( F_79 ( V_184 ) |
V_197 |
V_198 ) ;
F_83 ( V_136 , V_182 + V_199 ) ;
V_143 = F_81 ( V_182 + V_199 ) ;
if ( ! ( V_143 & V_200 ) ) {
V_136 &= ~ ( V_200 |
V_201 ) ;
V_136 |= V_202 ;
F_83 ( V_136 , V_182 + V_199 ) ;
}
V_136 = F_26 ( V_182 + V_186 ) ;
V_136 |= V_187 ;
F_32 ( V_136 , V_182 + V_186 ) ;
F_35 ( V_188 ) ;
}
static void F_103 ( void )
{
struct V_5 * V_6 ;
int V_87 ;
F_66 ( & V_203 ) ;
V_87 = F_101 () ;
F_104 (its, &its_nodes, entry) {
V_15 V_204 ;
if ( V_6 -> V_57 & V_91 ) {
struct V_205 * V_206 ;
V_206 = F_105 ( V_87 , NULL ) ;
if ( V_6 -> V_92 != V_207 &&
V_6 -> V_92 != F_106 ( V_206 ) )
continue;
}
if ( F_81 ( V_6 -> V_51 + V_175 ) & V_208 ) {
V_204 = F_99 () -> V_99 ;
} else {
V_204 = F_81 ( F_98 () + V_209 ) ;
V_204 = F_107 ( V_204 ) << 16 ;
}
V_6 -> V_7 [ V_87 ] . V_35 = V_204 ;
V_6 -> V_7 [ V_87 ] . V_34 = V_87 ;
F_42 ( V_6 , & V_6 -> V_7 [ V_87 ] , 1 ) ;
F_46 ( V_6 , & V_6 -> V_7 [ V_87 ] ) ;
}
F_69 ( & V_203 ) ;
}
static struct V_2 * F_108 ( struct V_5 * V_6 , T_1 V_210 )
{
struct V_2 * V_3 = NULL , * V_143 ;
unsigned long V_57 ;
F_38 ( & V_6 -> V_69 , V_57 ) ;
F_104 (tmp, &its->its_device_list, entry) {
if ( V_143 -> V_31 == V_210 ) {
V_3 = V_143 ;
break;
}
}
F_39 ( & V_6 -> V_69 , V_57 ) ;
return V_3 ;
}
static struct V_131 * F_109 ( struct V_5 * V_6 , T_1 type )
{
int V_117 ;
for ( V_117 = 0 ; V_117 < V_173 ; V_117 ++ ) {
if ( F_86 ( V_6 -> V_134 [ V_117 ] . V_136 ) == type )
return & V_6 -> V_134 [ V_117 ] ;
}
return NULL ;
}
static bool F_110 ( struct V_5 * V_6 , T_1 V_210 )
{
struct V_131 * V_132 ;
struct V_183 * V_183 ;
T_1 V_142 , V_133 ;
T_9 * V_211 ;
V_132 = F_109 ( V_6 , V_180 ) ;
if ( ! V_132 )
return ( F_15 ( V_210 ) < V_6 -> V_170 ) ;
V_142 = F_85 ( V_132 -> V_136 ) ;
if ( ! ( V_132 -> V_136 & V_153 ) )
return ( V_210 < ( F_87 ( V_132 -> V_140 ) / V_142 ) ) ;
V_133 = V_210 >> F_15 ( V_132 -> V_139 / V_142 ) ;
if ( V_133 >= ( F_87 ( V_132 -> V_140 ) / V_164 ) )
return false ;
V_211 = V_132 -> V_51 ;
if ( ! V_211 [ V_133 ] ) {
V_183 = F_77 ( V_110 | V_147 , F_78 ( V_132 -> V_139 ) ) ;
if ( ! V_183 )
return false ;
if ( ! ( V_132 -> V_136 & V_160 ) )
F_34 ( F_50 ( V_183 ) , V_132 -> V_139 ) ;
V_211 [ V_133 ] = F_13 ( F_79 ( V_183 ) | V_152 ) ;
if ( ! ( V_132 -> V_136 & V_160 ) )
F_34 ( V_211 + V_133 , V_164 ) ;
F_35 ( V_188 ) ;
}
return true ;
}
static struct V_2 * F_111 ( struct V_5 * V_6 , T_1 V_210 ,
int V_212 )
{
struct V_2 * V_26 ;
unsigned long * V_125 ;
unsigned long V_57 ;
T_3 * V_9 = NULL ;
void * V_28 ;
int V_77 ;
int V_124 ;
int V_27 ;
int V_213 ;
if ( ! F_110 ( V_6 , V_210 ) )
return NULL ;
V_26 = F_61 ( sizeof( * V_26 ) , V_110 ) ;
V_27 = F_100 ( 2UL , F_112 ( V_212 ) ) ;
V_213 = V_27 * V_6 -> V_214 ;
V_213 = F_100 ( V_213 , V_29 ) + V_29 - 1 ;
V_28 = F_61 ( V_213 , V_110 ) ;
V_125 = F_64 ( V_212 , & V_77 , & V_124 ) ;
if ( V_125 )
V_9 = F_61 ( sizeof( * V_9 ) * V_124 , V_110 ) ;
if ( ! V_26 || ! V_28 || ! V_125 || ! V_9 ) {
F_75 ( V_26 ) ;
F_75 ( V_28 ) ;
F_75 ( V_125 ) ;
F_75 ( V_9 ) ;
return NULL ;
}
F_34 ( V_28 , V_213 ) ;
V_26 -> V_6 = V_6 ;
V_26 -> V_28 = V_28 ;
V_26 -> V_27 = V_27 ;
V_26 -> V_8 . V_125 = V_125 ;
V_26 -> V_8 . V_9 = V_9 ;
V_26 -> V_8 . V_77 = V_77 ;
V_26 -> V_8 . V_124 = V_124 ;
V_26 -> V_31 = V_210 ;
F_113 ( & V_26 -> V_215 ) ;
F_38 ( & V_6 -> V_69 , V_57 ) ;
F_114 ( & V_26 -> V_215 , & V_6 -> V_216 ) ;
F_39 ( & V_6 -> V_69 , V_57 ) ;
F_41 ( V_26 , 1 ) ;
return V_26 ;
}
static void F_115 ( struct V_2 * V_3 )
{
unsigned long V_57 ;
F_38 ( & V_3 -> V_6 -> V_69 , V_57 ) ;
F_116 ( & V_3 -> V_215 ) ;
F_39 ( & V_3 -> V_6 -> V_69 , V_57 ) ;
F_75 ( V_3 -> V_28 ) ;
F_75 ( V_3 ) ;
}
static int F_117 ( struct V_2 * V_26 , T_5 * V_76 )
{
int V_133 ;
V_133 = F_118 ( V_26 -> V_8 . V_125 ,
V_26 -> V_8 . V_124 ) ;
if ( V_133 == V_26 -> V_8 . V_124 )
return - V_217 ;
* V_76 = V_26 -> V_8 . V_77 + V_133 ;
F_68 ( V_133 , V_26 -> V_8 . V_125 ) ;
return 0 ;
}
static int F_119 ( struct V_218 * V_219 , struct V_220 * V_26 ,
int V_221 , T_10 * V_222 )
{
struct V_5 * V_6 ;
struct V_2 * V_3 ;
struct V_223 * V_224 ;
T_1 V_210 ;
V_210 = V_222 -> V_225 [ 0 ] . V_226 ;
V_224 = F_120 ( V_219 ) ;
V_6 = V_224 -> V_103 ;
V_3 = F_108 ( V_6 , V_210 ) ;
if ( V_3 ) {
F_121 ( L_18 , V_210 ) ;
goto V_120;
}
V_3 = F_111 ( V_6 , V_210 , V_221 ) ;
if ( ! V_3 )
return - V_111 ;
F_121 ( L_19 , V_221 , F_15 ( V_221 ) ) ;
V_120:
V_222 -> V_225 [ 0 ] . V_46 = V_3 ;
return 0 ;
}
static int F_122 ( struct V_218 * V_219 ,
unsigned int V_227 ,
T_5 V_76 )
{
struct V_228 V_229 ;
if ( F_123 ( V_219 -> V_230 ) ) {
V_229 . V_231 = V_219 -> V_230 -> V_231 ;
V_229 . V_232 = 3 ;
V_229 . V_233 [ 0 ] = V_234 ;
V_229 . V_233 [ 1 ] = V_76 ;
V_229 . V_233 [ 2 ] = V_235 ;
} else {
return - V_93 ;
}
return F_124 ( V_219 , V_227 , 1 , & V_229 ) ;
}
static int F_125 ( struct V_218 * V_219 , unsigned int V_227 ,
unsigned int V_112 , void * args )
{
T_10 * V_222 = args ;
struct V_2 * V_3 = V_222 -> V_225 [ 0 ] . V_46 ;
T_5 V_76 ;
int V_176 ;
int V_117 ;
for ( V_117 = 0 ; V_117 < V_112 ; V_117 ++ ) {
V_176 = F_117 ( V_3 , & V_76 ) ;
if ( V_176 )
return V_176 ;
V_176 = F_122 ( V_219 , V_227 + V_117 , V_76 ) ;
if ( V_176 )
return V_176 ;
F_126 ( V_219 , V_227 + V_117 ,
V_76 , & V_236 , V_3 ) ;
F_121 ( L_20 ,
( int ) ( V_76 - V_3 -> V_8 . V_77 ) ,
( int ) V_76 , V_227 + V_117 ) ;
}
return 0 ;
}
static void F_127 ( struct V_218 * V_219 ,
struct V_74 * V_75 )
{
struct V_2 * V_3 = F_48 ( V_75 ) ;
T_1 V_4 = F_47 ( V_75 ) ;
const struct V_84 * V_88 = V_89 ;
if ( V_3 -> V_6 -> V_92 >= 0 )
V_88 = F_54 ( V_3 -> V_6 -> V_92 ) ;
V_3 -> V_8 . V_9 [ V_4 ] = F_128 ( V_88 ) ;
F_43 ( V_3 , V_75 -> V_76 , V_4 ) ;
}
static void F_129 ( struct V_218 * V_219 ,
struct V_74 * V_75 )
{
struct V_2 * V_3 = F_48 ( V_75 ) ;
T_1 V_4 = F_47 ( V_75 ) ;
F_45 ( V_3 , V_4 ) ;
}
static void F_130 ( struct V_218 * V_219 , unsigned int V_227 ,
unsigned int V_112 )
{
struct V_74 * V_75 = F_131 ( V_219 , V_227 ) ;
struct V_2 * V_3 = F_48 ( V_75 ) ;
int V_117 ;
for ( V_117 = 0 ; V_117 < V_112 ; V_117 ++ ) {
struct V_74 * V_103 = F_131 ( V_219 ,
V_227 + V_117 ) ;
T_1 V_4 = F_47 ( V_103 ) ;
F_73 ( V_4 , V_3 -> V_8 . V_125 ) ;
F_132 ( V_103 ) ;
}
if ( F_133 ( V_3 -> V_8 . V_125 ,
V_3 -> V_8 . V_124 ) ) {
F_70 ( & V_3 -> V_8 ) ;
F_41 ( V_3 , 0 ) ;
F_115 ( V_3 ) ;
}
F_134 ( V_219 , V_227 , V_112 ) ;
}
static int F_135 ( void T_8 * V_51 )
{
T_1 V_54 = 1000000 ;
T_1 V_136 ;
V_136 = F_26 ( V_51 + V_237 ) ;
if ( ( V_136 & V_238 ) && ! ( V_136 & V_239 ) )
return 0 ;
V_136 &= ~ V_239 ;
F_32 ( V_136 , V_51 + V_237 ) ;
while ( 1 ) {
V_136 = F_26 ( V_51 + V_237 ) ;
if ( V_136 & V_238 )
return 0 ;
V_54 -- ;
if ( ! V_54 )
return - V_240 ;
F_29 () ;
F_30 ( 1 ) ;
}
}
static void T_11 F_136 ( void * V_103 )
{
struct V_5 * V_6 = V_103 ;
V_6 -> V_57 |= V_177 ;
}
static void T_11 F_137 ( void * V_103 )
{
struct V_5 * V_6 = V_103 ;
V_6 -> V_57 |= V_91 ;
}
static void F_138 ( struct V_5 * V_6 )
{
T_1 V_241 = F_26 ( V_6 -> V_51 + V_242 ) ;
F_139 ( V_241 , V_243 , V_6 ) ;
}
static int T_6 F_140 ( struct V_205 * V_244 ,
struct V_218 * V_230 )
{
struct V_245 V_246 ;
struct V_5 * V_6 ;
void T_8 * V_247 ;
struct V_218 * V_248 ;
T_1 V_136 ;
V_15 V_132 , V_143 ;
int V_176 ;
V_176 = F_141 ( V_244 , 0 , & V_246 ) ;
if ( V_176 ) {
F_88 ( L_21 , V_244 -> V_249 ) ;
return - V_163 ;
}
V_247 = F_142 ( V_246 . V_250 , F_143 ( & V_246 ) ) ;
if ( ! V_247 ) {
F_88 ( L_22 , V_244 -> V_249 ) ;
return - V_111 ;
}
V_136 = F_26 ( V_247 + V_251 ) & V_252 ;
if ( V_136 != 0x30 && V_136 != 0x40 ) {
F_88 ( L_23 , V_244 -> V_249 ) ;
V_176 = - V_253 ;
goto V_254;
}
V_176 = F_135 ( V_247 ) ;
if ( V_176 ) {
F_88 ( L_24 ,
V_244 -> V_249 ) ;
goto V_254;
}
F_63 ( L_25 , V_244 -> V_249 ) ;
V_6 = F_61 ( sizeof( * V_6 ) , V_110 ) ;
if ( ! V_6 ) {
V_176 = - V_111 ;
goto V_254;
}
F_144 ( & V_6 -> V_69 ) ;
F_113 ( & V_6 -> V_215 ) ;
F_113 ( & V_6 -> V_216 ) ;
V_6 -> V_51 = V_247 ;
V_6 -> V_99 = V_246 . V_250 ;
V_6 -> V_214 = ( ( F_26 ( V_247 + V_175 ) >> 4 ) & 0xf ) + 1 ;
V_6 -> V_92 = F_106 ( V_244 ) ;
V_6 -> V_47 = F_61 ( V_255 , V_110 ) ;
if ( ! V_6 -> V_47 ) {
V_176 = - V_111 ;
goto V_256;
}
V_6 -> V_50 = V_6 -> V_47 ;
F_138 ( V_6 ) ;
V_176 = F_94 ( V_6 ) ;
if ( V_176 )
goto V_257;
V_176 = F_96 ( V_6 ) ;
if ( V_176 )
goto V_258;
V_132 = ( F_16 ( V_6 -> V_47 ) |
V_259 |
V_260 |
( V_255 / V_154 - 1 ) |
V_261 ) ;
F_83 ( V_132 , V_6 -> V_51 + V_262 ) ;
V_143 = F_81 ( V_6 -> V_51 + V_262 ) ;
if ( ( V_143 ^ V_132 ) & V_263 ) {
if ( ! ( V_143 & V_263 ) ) {
V_132 &= ~ ( V_263 |
V_264 ) ;
V_132 |= V_265 ;
F_83 ( V_132 , V_6 -> V_51 + V_262 ) ;
}
F_63 ( L_26 ) ;
V_6 -> V_57 |= V_58 ;
}
F_83 ( 0 , V_6 -> V_51 + V_56 ) ;
F_32 ( V_239 , V_6 -> V_51 + V_237 ) ;
if ( F_145 ( V_244 , L_27 ) ) {
struct V_223 * V_222 ;
V_222 = F_61 ( sizeof( * V_222 ) , V_110 ) ;
if ( ! V_222 ) {
V_176 = - V_111 ;
goto V_258;
}
V_248 = F_146 ( V_244 , & V_266 , V_6 ) ;
if ( ! V_248 ) {
V_176 = - V_111 ;
F_75 ( V_222 ) ;
goto V_258;
}
V_248 -> V_230 = V_230 ;
V_248 -> V_267 = V_268 ;
V_222 -> V_269 = & V_270 ;
V_222 -> V_103 = V_6 ;
V_248 -> V_271 = V_222 ;
}
F_66 ( & V_203 ) ;
F_114 ( & V_6 -> V_215 , & V_272 ) ;
F_69 ( & V_203 ) ;
return 0 ;
V_258:
F_93 ( V_6 ) ;
V_257:
F_75 ( V_6 -> V_47 ) ;
V_256:
F_75 ( V_6 ) ;
V_254:
F_147 ( V_247 ) ;
F_74 ( L_28 , V_244 -> V_249 , V_176 ) ;
return V_176 ;
}
static bool F_148 ( void )
{
return ! ! ( F_26 ( F_98 () + V_209 ) & V_273 ) ;
}
int F_149 ( void )
{
if ( ! F_150 ( & V_272 ) ) {
if ( ! F_148 () ) {
F_63 ( L_29 , F_101 () ) ;
return - V_163 ;
}
F_97 () ;
F_103 () ;
}
return 0 ;
}
int T_6 F_151 ( struct V_205 * V_244 , struct V_274 * V_274 ,
struct V_218 * V_275 )
{
struct V_205 * V_276 ;
for ( V_276 = F_152 ( V_244 , V_277 ) ; V_276 ;
V_276 = F_152 ( V_276 , V_277 ) ) {
F_140 ( V_276 , V_275 ) ;
}
if ( F_150 ( & V_272 ) ) {
F_88 ( L_30 ) ;
return - V_163 ;
}
V_80 = V_274 ;
F_76 () ;
F_60 ( V_274 -> V_107 ) ;
return 0 ;
}
