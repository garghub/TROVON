static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
int V_5 ;
int V_6 ;
V_5 = F_2 ( V_4 -> V_7 ,
V_8 ,
V_9 ,
V_10 ,
& V_6 ) ;
if ( V_5 < 0 ) {
F_3 ( & V_4 -> V_11 ,
L_1 ) ;
}
return V_6 ;
}
static void F_4 ( struct V_1 * V_12 ,
struct V_13 * V_14 )
{
struct V_15 V_16 ;
if ( V_14 -> V_17 == V_14 -> V_18 )
return;
F_5 ( & V_16 ) ;
V_14 -> V_17 -> V_19 . V_20 . V_21 . V_22 =
V_16 . V_22 ;
V_14 -> V_17 -> V_19 . V_20 . V_21 . V_23 =
V_16 . V_24 / V_25 ;
F_6 ( & V_14 -> V_17 -> V_19 , V_26 ) ;
V_14 -> V_17 = V_14 -> V_18 ;
}
static void F_7 ( struct V_1 * V_12 ,
struct V_13 * V_14 )
{
struct V_27 * V_28 = V_12 -> V_28 ;
unsigned long V_29 ;
F_8 ( & V_12 -> V_30 ) ;
if ( F_9 ( & V_14 -> V_31 ) ||
( V_14 -> V_17 != V_14 -> V_18 ) ) {
F_10 ( & V_12 -> V_30 ) ;
return;
}
V_14 -> V_18 = F_11 ( V_14 -> V_31 . V_32 ,
struct V_33 , V_34 ) ;
F_12 ( & V_14 -> V_18 -> V_34 ) ;
F_10 ( & V_12 -> V_30 ) ;
V_14 -> V_18 -> V_19 . V_35 = V_36 ;
V_29 = F_13 ( & V_14 -> V_18 -> V_19 , 0 ) ;
V_28 -> V_37 . V_38 ( V_28 ,
V_14 -> V_39 . V_40 ,
V_29 ,
V_12 -> V_41 ) ;
}
static T_1 F_14 ( int V_42 , void * V_43 )
{
struct V_1 * V_2 = (struct V_1 * ) V_43 ;
struct V_13 * V_14 ;
static unsigned V_44 ;
unsigned V_45 = 0 ;
int V_46 ;
int V_47 ;
if ( ( NULL == V_43 ) || ( NULL == V_2 -> V_48 [ 0 ] ) )
return V_49 ;
if ( F_1 ( V_2 ) )
V_45 |= V_50 ;
else
V_45 |= V_51 ;
if ( V_45 == ( V_44 & ~ V_52 ) ) {
V_45 |= V_52 ;
} else if ( V_45 == V_50 ) {
V_45 |= V_52 ;
}
V_44 = V_45 ;
for ( V_47 = 0 ; V_47 < V_53 ; V_47 ++ ) {
V_14 = V_2 -> V_48 [ V_47 ] ;
if ( ! V_14 -> V_54 )
continue;
if ( V_14 -> V_55 ) {
V_14 -> V_55 = 0 ;
continue;
}
if ( ( V_56 == V_14 -> V_57 . V_58 ) &&
( V_45 & V_52 ) ) {
F_4 ( V_2 , V_14 ) ;
F_7 ( V_2 , V_14 ) ;
} else {
V_14 -> V_59 ^= 1 ;
if ( V_45 & V_51 )
V_46 = 0 ;
else
V_46 = 1 ;
if ( V_46 != V_14 -> V_59 ) {
V_14 -> V_59 = V_46 ;
continue;
}
if ( 0 == V_46 )
F_4 ( V_2 , V_14 ) ;
else
F_7 ( V_2 , V_14 ) ;
}
}
return V_49 ;
}
static int F_15 ( struct V_60 * V_19 )
{
struct V_61 * V_62 = F_16 ( V_19 -> V_63 ) ;
struct V_63 * V_64 = V_19 -> V_63 ;
struct V_13 * V_14 = V_62 -> V_14 ;
struct V_3 * V_4 = V_62 -> V_2 -> V_4 ;
unsigned long V_29 ;
F_17 ( 1 , V_65 , & V_4 -> V_11 ,
L_2 ) ;
if ( V_19 -> V_35 != V_36 &&
V_19 -> V_35 != V_66 ) {
F_18 ( V_19 , 0 , V_14 -> V_57 . V_67 ) ;
if ( F_19 ( V_19 , 0 ) &&
F_20 ( V_19 , 0 ) > F_21 ( V_19 , 0 ) )
return - V_68 ;
V_29 = F_13 ( V_19 , 0 ) ;
if ( V_64 -> V_69 ) {
if ( ! F_22 ( V_29 , 8 ) ) {
F_3 ( & V_4 -> V_11 ,
L_3 ) ;
return - V_68 ;
}
}
}
return 0 ;
}
static int
F_23 ( struct V_63 * V_70 , const struct V_71 * V_72 ,
unsigned int * V_73 , unsigned int * V_74 ,
unsigned int V_75 [] , void * V_76 [] )
{
struct V_61 * V_62 = F_16 ( V_70 ) ;
struct V_13 * V_14 = V_62 -> V_14 ;
struct V_3 * V_4 = V_62 -> V_2 -> V_4 ;
F_17 ( 1 , V_65 , & V_4 -> V_11 , L_4 ) ;
if ( * V_73 < V_77 )
* V_73 = V_14 -> V_78 = V_77 ;
* V_74 = 1 ;
V_75 [ 0 ] = V_14 -> V_57 . V_67 ;
V_76 [ 0 ] = V_14 -> V_79 ;
return 0 ;
}
static void F_24 ( struct V_60 * V_19 )
{
struct V_61 * V_62 = F_16 ( V_19 -> V_63 ) ;
struct V_33 * V_80 = F_25 ( V_19 ,
struct V_33 , V_19 ) ;
struct V_13 * V_14 = V_62 -> V_14 ;
struct V_1 * V_81 = V_62 -> V_2 ;
struct V_3 * V_4 = V_62 -> V_2 -> V_4 ;
unsigned long V_82 ;
F_17 ( 1 , V_65 , & V_4 -> V_11 ,
L_5 ) ;
F_26 ( & V_81 -> V_30 , V_82 ) ;
F_27 ( & V_80 -> V_34 , & V_14 -> V_31 ) ;
F_28 ( & V_81 -> V_30 , V_82 ) ;
}
static void F_29 ( struct V_60 * V_19 )
{
struct V_61 * V_62 = F_16 ( V_19 -> V_63 ) ;
struct V_13 * V_14 = V_62 -> V_14 ;
struct V_3 * V_4 = V_62 -> V_2 -> V_4 ;
struct V_33 * V_80 = F_25 ( V_19 ,
struct V_33 , V_19 ) ;
unsigned long V_82 ;
F_17 ( 1 , V_65 , & V_4 -> V_11 ,
L_6 ) ;
F_26 ( & V_14 -> V_83 , V_82 ) ;
if ( V_19 -> V_35 == V_36 )
F_30 ( & V_80 -> V_34 ) ;
F_28 ( & V_14 -> V_83 , V_82 ) ;
}
static void F_31 ( struct V_63 * V_70 )
{
struct V_61 * V_62 = F_16 ( V_70 ) ;
struct V_13 * V_14 = V_62 -> V_14 ;
F_32 ( & V_14 -> V_84 ) ;
}
static void F_33 ( struct V_63 * V_70 )
{
struct V_61 * V_62 = F_16 ( V_70 ) ;
struct V_13 * V_14 = V_62 -> V_14 ;
F_34 ( & V_14 -> V_84 ) ;
}
static int F_35 ( struct V_60 * V_19 )
{
struct V_33 * V_80 = F_25 ( V_19 ,
struct V_33 , V_19 ) ;
F_36 ( & V_80 -> V_34 ) ;
return 0 ;
}
static int F_37 ( struct V_63 * V_70 , unsigned int V_85 )
{
struct V_61 * V_62 = F_16 ( V_70 ) ;
struct V_13 * V_14 = V_62 -> V_14 ;
struct V_3 * V_4 = V_62 -> V_2 -> V_4 ;
int V_5 ;
if ( F_9 ( & V_14 -> V_31 ) ) {
F_3 ( & V_4 -> V_11 , L_7 ) ;
return - V_68 ;
}
V_14 -> V_18 = V_14 -> V_17 = F_11 ( V_14 -> V_31 . V_32 ,
struct V_33 , V_34 ) ;
F_12 ( & V_14 -> V_17 -> V_34 ) ;
V_14 -> V_17 -> V_19 . V_35 = V_36 ;
V_14 -> V_59 = 0 ;
V_5 = F_38 ( V_62 -> V_2 , V_14 ) ;
if ( V_5 < 0 )
return V_5 ;
V_14 -> V_54 = 1 ;
V_14 -> V_55 = 1 ;
return V_5 ;
}
static int F_39 ( struct V_63 * V_70 )
{
struct V_61 * V_62 = F_16 ( V_70 ) ;
struct V_13 * V_14 = V_62 -> V_14 ;
if ( ! F_40 ( V_70 ) )
return 0 ;
while ( ! F_9 ( & V_14 -> V_31 ) ) {
V_14 -> V_18 = F_11 ( V_14 -> V_31 . V_32 ,
struct V_33 , V_34 ) ;
F_12 ( & V_14 -> V_18 -> V_34 ) ;
F_6 ( & V_14 -> V_18 -> V_19 , V_86 ) ;
}
return 0 ;
}
static
struct V_13 *
F_41 ( struct V_1 * V_2 ,
struct V_13 * V_14 )
{
enum V_87 V_88 , V_89 ;
V_88 = V_14 -> V_90 ;
V_89 = ( V_88 == V_91 ) ?
V_92 : V_91 ;
return V_2 -> V_48 [ V_89 ] ;
}
static int F_38 ( struct V_1 * V_2 ,
struct V_13 * V_14 )
{
struct V_93 * V_94 = & V_14 -> V_39 . V_95 ;
struct V_27 * V_28 = V_2 -> V_28 ;
struct V_3 * V_4 = V_2 -> V_4 ;
unsigned long V_29 ;
int V_5 ;
V_29 = F_13 ( & V_14 -> V_17 -> V_19 , 0 ) ;
V_28 -> V_37 . V_38 ( V_28 ,
V_14 -> V_39 . V_40 ,
V_29 ,
V_2 -> V_41 ) ;
V_5 = V_28 -> V_37 . V_96 ( V_28 ,
V_14 -> V_39 . V_40 , 0 ) ;
if ( V_5 < 0 ) {
F_3 ( & V_4 -> V_11 ,
L_8 ) ;
return - 1 ;
}
V_14 -> V_39 . V_97 = 1 ;
if ( V_94 -> V_98 == V_99 ) {
struct V_13 * V_100 =
F_41 ( V_2 , V_14 ) ;
V_5 = V_28 -> V_37 . V_96 ( V_28 ,
V_100 -> V_39 . V_40 , 1 ) ;
if ( V_5 < 0 ) {
F_3 ( & V_4 -> V_11 ,
L_9 ) ;
return - 1 ;
}
V_100 -> V_39 . V_97 = 1 ;
}
return 0 ;
}
static void
F_42 ( struct V_1 * V_2 ,
struct V_13 * V_14 ,
int V_101 , int V_102 )
{
struct V_103 * V_39 = & V_14 -> V_39 ;
struct V_104 * V_98 = & V_14 -> V_57 ;
struct V_93 * V_94 = & V_14 -> V_39 . V_95 ;
struct V_3 * V_4 = V_2 -> V_4 ;
int V_105 ;
int V_106 = 0 ;
int V_107 = 0 ;
int V_108 ;
int V_109 ;
T_2 V_110 = V_4 -> V_111 . V_112 ;
V_94 -> V_113 = V_98 -> V_114 ;
V_94 -> V_115 = V_98 -> V_116 ;
V_39 -> V_117 = V_118 ;
V_39 -> V_119 = V_118 ;
V_39 -> V_106 = V_120 ;
V_39 -> V_107 = V_121 ;
if ( V_98 -> V_114 < V_101 ) {
V_108 = V_4 -> V_111 . V_122 / V_98 -> V_114 ;
if ( V_108 < 2 )
V_108 = 1 ;
else if ( V_108 >= 4 )
V_108 = 4 ;
else
V_108 = 2 ;
V_94 -> V_113 *= V_108 ;
if ( V_94 -> V_113 < V_101 ) {
if ( ( V_110 & V_123 ) ||
( V_110 & V_124 ) ) {
V_105 = ( V_94 -> V_113 *
V_125 ) /
V_126 ;
if ( V_105 <= V_101 ) {
V_106 = 1 ;
V_94 -> V_113 = V_105 ;
}
}
}
if ( V_108 == 2 )
V_39 -> V_117 = V_127 ;
else if ( V_108 == 4 )
V_39 -> V_117 = V_128 ;
if ( V_106 )
V_39 -> V_106 = V_129 ;
} else {
V_94 -> V_113 = V_101 ;
}
if ( V_98 -> V_116 < V_102 ) {
V_109 = V_102 / V_98 -> V_116 ;
if ( V_109 < 2 )
V_109 = 1 ;
else if ( V_109 >= 4 )
V_109 = 4 ;
else
V_109 = 2 ;
V_94 -> V_115 *= V_109 ;
if ( V_94 -> V_115 < V_102 ) {
if ( ( V_110 & V_124 ) ) {
V_105 = ( V_94 -> V_115 *
V_130 ) /
V_131 ;
if ( V_105 <= V_102 ) {
V_107 = 1 ;
V_94 -> V_115 = V_105 ;
}
}
}
if ( V_109 == 2 )
V_39 -> V_119 = V_127 ;
else if ( V_109 == 4 )
V_39 -> V_119 = V_128 ;
if ( V_107 )
V_39 -> V_106 = V_132 ;
} else {
V_94 -> V_115 = V_102 ;
}
F_17 ( 1 , V_65 , & V_4 -> V_11 ,
L_10 ,
V_94 -> V_113 , V_94 -> V_115 ) ;
}
static void F_43 ( struct V_1 * V_2 ,
struct V_13 * V_14 ,
int V_133 , int V_134 )
{
struct V_93 * V_94 = & V_14 -> V_39 . V_95 ;
struct V_3 * V_4 = V_2 -> V_4 ;
V_94 -> V_135 = F_44 ( ( unsigned int ) V_134 ,
V_4 -> V_111 . V_122 - V_94 -> V_113 ) ;
V_94 -> V_136 = F_44 ( ( unsigned int ) V_133 ,
V_4 -> V_111 . V_137 - V_94 -> V_115 ) ;
F_17 ( 1 , V_65 , & V_4 -> V_11 ,
L_11 ,
V_94 -> V_135 , V_94 -> V_136 ) ;
}
static void F_45 ( struct V_1 * V_2 ,
struct V_138 * V_139 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
if ( ( V_139 -> V_114 == 0 ) ||
( ( V_139 -> V_114 + V_139 -> V_134 ) > V_4 -> V_111 . V_122 ) )
V_139 -> V_114 = V_4 -> V_111 . V_122 - V_139 -> V_134 ;
if ( ( V_139 -> V_116 == 0 ) || ( ( V_139 -> V_116 + V_139 -> V_133 ) >
V_4 -> V_111 . V_137 ) )
V_139 -> V_116 = V_4 -> V_111 . V_137 - V_139 -> V_133 ;
if ( V_4 -> V_111 . V_140 )
V_139 -> V_116 &= ( ~ 0x01 ) ;
}
static int F_46 ( struct V_1 * V_2 ,
struct V_104 * V_98 , int V_141 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
int V_142 = 1 ;
int V_143 = 32 ;
int V_144 ;
int V_145 ;
int V_146 ;
if ( ( V_98 -> V_147 != V_148 ) &&
( V_98 -> V_147 != V_149 ) )
V_98 -> V_147 = V_148 ;
if ( ( V_98 -> V_58 != V_150 ) &&
( V_98 -> V_58 != V_56 ) ) {
if ( V_4 -> V_111 . V_140 )
V_98 -> V_58 = V_150 ;
else
V_98 -> V_58 = V_56 ;
}
if ( V_98 -> V_58 == V_150 )
V_142 = 2 ;
if ( V_98 -> V_147 == V_149 )
V_146 = 1 ;
else
V_146 = 2 ;
V_145 = V_4 -> V_111 . V_122 ;
V_144 = V_4 -> V_111 . V_137 ;
V_143 /= V_146 ;
if ( ! V_98 -> V_114 || ( V_98 -> V_114 < V_143 ) ||
( V_98 -> V_114 > V_145 ) ) {
V_98 -> V_114 = V_4 -> V_111 . V_122 ;
}
if ( ! V_98 -> V_116 || ( V_98 -> V_116 < V_142 ) ||
( V_98 -> V_116 > V_144 ) ) {
V_98 -> V_116 = V_4 -> V_111 . V_137 ;
}
if ( V_98 -> V_151 < ( V_98 -> V_114 * V_146 ) )
V_98 -> V_151 = V_98 -> V_114 * V_146 ;
V_98 -> V_151 = ( ( V_98 -> V_114 * V_146 + 31 ) & ~ 31 ) ;
if ( V_98 -> V_147 == V_149 )
V_98 -> V_67 = V_98 -> V_151 * V_98 -> V_116 +
( V_98 -> V_151 * V_98 -> V_116 >> 1 ) ;
else
V_98 -> V_67 = V_98 -> V_151 * V_98 -> V_116 ;
return 0 ;
}
static int F_47 ( struct V_152 * V_152 , void * V_153 ,
enum V_154 * V_155 )
{
struct V_61 * V_62 = V_152 -> V_156 ;
struct V_13 * V_14 = V_62 -> V_14 ;
* V_155 = F_48 ( & V_14 -> V_157 ) ;
return 0 ;
}
static int F_49 ( struct V_152 * V_152 , void * V_153 ,
enum V_154 V_155 )
{
struct V_61 * V_62 = V_152 -> V_156 ;
struct V_13 * V_14 = V_62 -> V_14 ;
int V_5 ;
V_5 = F_50 ( & V_14 -> V_157 , & V_62 -> V_157 , V_155 ) ;
return V_5 ;
}
static int F_51 ( struct V_152 * V_152 , void * V_153 ,
struct V_158 * V_159 )
{
struct V_61 * V_62 = V_152 -> V_156 ;
struct V_3 * V_4 = V_62 -> V_2 -> V_4 ;
V_159 -> V_160 = V_161 ;
V_159 -> V_162 = V_163 | V_164 ;
V_159 -> V_165 = V_159 -> V_162 | V_166 ;
snprintf ( V_159 -> V_167 , sizeof( V_159 -> V_167 ) , L_12 ,
F_52 ( V_4 -> V_168 ) ) ;
snprintf ( V_159 -> V_169 , sizeof( V_159 -> V_169 ) , L_13 ,
F_52 ( V_4 -> V_168 ) ) ;
F_53 ( V_159 -> V_170 , V_4 -> V_94 -> V_171 , sizeof( V_159 -> V_170 ) ) ;
return 0 ;
}
static int F_54 ( struct V_152 * V_152 , void * V_153 ,
const struct V_172 * V_173 )
{
struct V_61 * V_62 = V_152 -> V_156 ;
struct V_13 * V_14 = V_62 -> V_14 ;
struct V_1 * V_2 = V_62 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_93 * V_94 = & V_14 -> V_39 . V_95 ;
struct V_27 * V_28 = V_2 -> V_28 ;
struct V_138 V_174 = V_173 -> V_139 ;
int V_5 ;
F_17 ( 1 , V_65 , & V_4 -> V_11 ,
L_14 , V_14 -> V_90 ) ;
if ( V_173 -> type != V_175 ) {
F_3 ( & V_4 -> V_11 , L_15 ) ;
return - V_68 ;
}
if ( V_174 . V_133 < 0 )
V_174 . V_133 = 0 ;
if ( V_174 . V_134 < 0 )
V_174 . V_134 = 0 ;
F_45 ( V_2 , & V_174 ) ;
V_28 -> V_37 . V_176 ( V_28 ,
V_14 -> V_39 . V_40 , V_94 ) ;
F_42 ( V_2 , V_14 ,
V_174 . V_114 ,
V_174 . V_116 ) ;
F_43 ( V_2 , V_14 , V_174 . V_133 ,
V_174 . V_134 ) ;
V_5 = V_28 -> V_37 . V_177 ( V_28 ,
V_14 -> V_39 . V_40 , V_94 ) ;
if ( V_5 < 0 ) {
F_3 ( & V_4 -> V_11 ,
L_16 ) ;
return - V_68 ;
}
V_28 -> V_37 . V_178 ( V_28 ,
V_14 -> V_39 . V_40 ,
V_14 -> V_39 . V_117 ,
V_14 -> V_39 . V_119 ) ;
V_5 = V_28 -> V_37 . V_179 ( V_28 ,
V_14 -> V_39 . V_106 ,
V_14 -> V_39 . V_107 ) ;
if ( V_5 < 0 ) {
F_3 ( & V_4 -> V_11 ,
L_17 ) ;
return - V_68 ;
}
if ( ( V_14 -> V_39 . V_117 != V_118 ) ||
( V_14 -> V_39 . V_119 != V_118 ) ||
( V_14 -> V_39 . V_106 != V_120 ) ||
( V_14 -> V_39 . V_107 != V_121 ) )
V_28 -> V_37 . V_180 ( V_28 , 1 ) ;
else
V_28 -> V_37 . V_180 ( V_28 , 0 ) ;
return 0 ;
}
static int F_55 ( struct V_152 * V_152 , void * V_153 ,
struct V_172 * V_173 )
{
struct V_61 * V_62 = V_152 -> V_156 ;
struct V_13 * V_14 = V_62 -> V_14 ;
struct V_93 * V_94 = & V_14 -> V_39 . V_95 ;
struct V_3 * V_4 = V_62 -> V_2 -> V_4 ;
struct V_27 * V_28 = V_62 -> V_2 -> V_28 ;
struct V_138 * V_174 = & V_173 -> V_139 ;
F_17 ( 1 , V_65 , & V_4 -> V_11 ,
L_18 ,
V_14 -> V_90 ) ;
if ( V_173 -> type != V_175 ) {
F_3 ( & V_4 -> V_11 , L_15 ) ;
return - V_68 ;
}
V_28 -> V_37 . V_176 ( V_28 ,
V_14 -> V_39 . V_40 , V_94 ) ;
V_174 -> V_133 = V_94 -> V_136 ;
V_174 -> V_134 = V_94 -> V_135 ;
V_174 -> V_114 = V_94 -> V_113 ;
V_174 -> V_116 = V_94 -> V_115 ;
return 0 ;
}
static int F_56 ( struct V_152 * V_152 , void * V_153 ,
struct V_181 * V_182 )
{
struct V_61 * V_62 = V_152 -> V_156 ;
struct V_3 * V_4 = V_62 -> V_2 -> V_4 ;
F_17 ( 1 , V_65 , & V_4 -> V_11 , L_19 ) ;
V_182 -> type = V_175 ;
V_182 -> V_183 . V_134 = 0 ;
V_182 -> V_183 . V_133 = 0 ;
V_182 -> V_183 . V_114 = V_4 -> V_111 . V_122 ;
V_182 -> V_183 . V_116 = V_4 -> V_111 . V_137 ;
V_182 -> V_184 = V_4 -> V_111 . V_185 ;
V_182 -> V_186 = V_182 -> V_183 ;
return 0 ;
}
static int F_57 ( struct V_152 * V_152 , void * V_153 ,
struct V_71 * V_72 )
{
struct V_61 * V_62 = V_152 -> V_156 ;
struct V_13 * V_14 = V_62 -> V_14 ;
struct V_3 * V_4 = V_62 -> V_2 -> V_4 ;
F_17 ( 1 , V_65 , & V_4 -> V_11 ,
L_20 ,
V_14 -> V_90 ) ;
if ( V_175 != V_72 -> type ) {
F_3 ( & V_4 -> V_11 , L_21 ) ;
return - V_68 ;
}
V_72 -> V_72 . V_187 = V_14 -> V_57 ;
return 0 ;
}
static int F_58 ( struct V_152 * V_152 , void * V_153 ,
struct V_188 * V_72 )
{
struct V_61 * V_62 = V_152 -> V_156 ;
struct V_13 * V_14 = V_62 -> V_14 ;
struct V_3 * V_4 = V_62 -> V_2 -> V_4 ;
unsigned int V_189 = 0 ;
F_17 ( 1 , V_65 , & V_4 -> V_11 ,
L_22 ,
V_14 -> V_90 ) ;
if ( V_72 -> V_189 > 1 ) {
F_3 ( & V_4 -> V_11 , L_23 ) ;
return - V_68 ;
}
V_189 = V_72 -> V_189 ;
memset ( V_72 , 0 , sizeof( * V_72 ) ) ;
V_72 -> V_189 = V_189 ;
V_72 -> type = V_175 ;
if ( V_189 == 0 ) {
strcpy ( V_72 -> V_190 , L_24 ) ;
V_72 -> V_147 = V_148 ;
} else {
strcpy ( V_72 -> V_190 , L_25 ) ;
V_72 -> V_147 = V_149 ;
}
return 0 ;
}
static int F_59 ( struct V_152 * V_152 , void * V_153 ,
struct V_71 * V_72 )
{
struct V_61 * V_62 = V_152 -> V_156 ;
struct V_13 * V_14 = V_62 -> V_14 ;
struct V_1 * V_2 = V_62 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_93 * V_94 = & V_14 -> V_39 . V_95 ;
struct V_104 * V_98 = & V_72 -> V_72 . V_187 ;
struct V_27 * V_28 = V_2 -> V_28 ;
int V_5 ;
F_17 ( 1 , V_65 , & V_4 -> V_11 ,
L_26 ,
V_14 -> V_90 ) ;
if ( V_14 -> V_54 ) {
F_3 ( & V_4 -> V_11 , L_27 ) ;
return - V_191 ;
}
if ( V_175 != V_72 -> type ) {
F_17 ( 1 , V_65 , & V_4 -> V_11 , L_21 ) ;
return - V_68 ;
}
V_5 = F_46 ( V_2 , V_98 , 1 ) ;
if ( V_5 )
return V_5 ;
V_14 -> V_57 = * V_98 ;
if ( V_98 -> V_147 == V_149 ) {
struct V_13 * V_100 ;
V_100 = F_41 ( V_2 , V_14 ) ;
V_5 = V_28 -> V_37 . V_192 ( V_28 ,
V_100 -> V_39 . V_40 ) ;
if ( V_5 < 0 ) {
F_3 ( & V_4 -> V_11 ,
L_28 ) ;
return - V_191 ;
}
}
V_28 -> V_37 . V_176 ( V_28 ,
V_14 -> V_39 . V_40 , V_94 ) ;
V_94 -> V_113 = V_98 -> V_114 ;
V_94 -> V_115 = V_98 -> V_116 ;
V_94 -> V_193 = V_98 -> V_151 ;
V_94 -> V_136 = 0 ;
V_94 -> V_135 = 0 ;
V_94 -> V_140 = V_4 -> V_111 . V_140 ;
if ( V_148 == V_98 -> V_147 )
V_94 -> V_98 = V_194 ;
if ( V_149 == V_98 -> V_147 ) {
struct V_13 * V_100 ;
V_94 -> V_98 = V_99 ;
V_100 = F_41 ( V_2 ,
V_14 ) ;
V_100 -> V_39 . V_95 . V_98 = V_99 ;
}
V_5 = V_28 -> V_37 . V_177 ( V_28 ,
V_14 -> V_39 . V_40 , V_94 ) ;
if ( V_5 < 0 ) {
F_3 ( & V_4 -> V_11 ,
L_29 ) ;
return - V_68 ;
}
V_28 -> V_37 . V_176 ( V_28 ,
V_14 -> V_39 . V_40 , V_94 ) ;
return 0 ;
}
static int F_60 ( struct V_152 * V_152 , void * V_153 ,
struct V_71 * V_72 )
{
struct V_61 * V_62 = V_152 -> V_156 ;
struct V_1 * V_2 = V_62 -> V_2 ;
struct V_3 * V_4 = V_62 -> V_2 -> V_4 ;
struct V_104 * V_98 = & V_72 -> V_72 . V_187 ;
F_17 ( 1 , V_65 , & V_4 -> V_11 , L_30 ) ;
if ( V_175 != V_72 -> type ) {
F_3 ( & V_4 -> V_11 , L_21 ) ;
return - V_68 ;
}
return F_46 ( V_2 , V_98 , 0 ) ;
}
static int F_61 ( struct V_152 * V_152 , void * V_153 ,
T_2 V_112 )
{
struct V_61 * V_62 = V_153 ;
struct V_13 * V_14 = V_62 -> V_14 ;
struct V_3 * V_4 = V_62 -> V_2 -> V_4 ;
int V_5 ;
F_17 ( 1 , V_65 , & V_4 -> V_11 , L_31 ) ;
if ( V_14 -> V_54 ) {
F_3 ( & V_4 -> V_11 , L_27 ) ;
return - V_191 ;
}
if ( NULL != V_4 -> V_37 . V_195 ) {
V_5 = V_4 -> V_37 . V_195 ( V_4 , V_112 ) ;
if ( V_5 ) {
F_3 ( & V_4 -> V_11 ,
L_32 ) ;
return - V_68 ;
}
} else {
return - V_68 ;
}
return 0 ;
}
static int F_62 ( struct V_152 * V_152 , void * V_153 ,
T_2 * V_112 )
{
struct V_61 * V_62 = V_153 ;
struct V_3 * V_4 = V_62 -> V_2 -> V_4 ;
F_17 ( 1 , V_65 , & V_4 -> V_11 , L_33 ) ;
if ( V_4 -> V_111 . V_196 & V_197 ) {
* V_112 = V_4 -> V_111 . V_112 ;
return 0 ;
}
return - V_68 ;
}
static int F_63 ( struct V_152 * V_152 , void * V_153 ,
struct V_198 * V_199 )
{
struct V_61 * V_62 = V_153 ;
struct V_3 * V_4 = V_62 -> V_2 -> V_4 ;
int V_5 ;
F_17 ( 1 , V_65 , & V_4 -> V_11 , L_34 ) ;
if ( NULL == V_4 -> V_37 . V_200 )
return - V_68 ;
V_5 = V_4 -> V_37 . V_200 ( V_4 , V_199 ) ;
if ( V_5 ) {
F_17 ( 1 , V_65 , & V_4 -> V_11 ,
L_35 ) ;
return - V_68 ;
}
return 0 ;
}
static int F_64 ( struct V_152 * V_152 , void * V_153 ,
unsigned int V_47 )
{
struct V_61 * V_62 = V_153 ;
struct V_13 * V_14 = V_62 -> V_14 ;
struct V_3 * V_4 = V_62 -> V_2 -> V_4 ;
int V_5 ;
F_17 ( 1 , V_65 , & V_4 -> V_11 , L_36 ) ;
if ( V_14 -> V_54 ) {
F_3 ( & V_4 -> V_11 , L_27 ) ;
return - V_191 ;
}
if ( NULL == V_4 -> V_37 . V_201 )
return - V_68 ;
V_5 = V_4 -> V_37 . V_201 ( V_4 , V_47 ) ;
if ( V_5 ) {
F_3 ( & V_4 -> V_11 ,
L_37 ) ;
return - V_68 ;
}
return 0 ;
}
static int F_65 ( struct V_152 * V_152 , void * V_153 ,
unsigned int * V_47 )
{
struct V_61 * V_62 = V_153 ;
struct V_3 * V_4 = V_62 -> V_2 -> V_4 ;
F_17 ( 1 , V_65 , & V_4 -> V_11 , L_38 ) ;
* V_47 = V_4 -> V_202 ;
return 0 ;
}
static int
F_66 ( struct V_152 * V_152 , void * V_153 ,
struct V_203 * V_204 )
{
struct V_61 * V_62 = V_153 ;
struct V_3 * V_4 = V_62 -> V_2 -> V_4 ;
int V_5 ;
F_17 ( 1 , V_65 , & V_4 -> V_11 , L_39 ) ;
if ( NULL == V_4 -> V_37 . V_205 )
return - V_68 ;
V_5 = V_4 -> V_37 . V_205 ( V_4 , V_204 ) ;
if ( V_5 ) {
F_3 ( & V_4 -> V_11 ,
L_40 ) ;
return - V_68 ;
}
return 0 ;
}
static int
F_67 ( struct V_152 * V_152 , void * V_153 ,
struct V_206 * V_204 )
{
struct V_61 * V_62 = V_153 ;
struct V_13 * V_14 = V_62 -> V_14 ;
struct V_3 * V_4 = V_62 -> V_2 -> V_4 ;
int V_5 ;
F_17 ( 1 , V_65 , & V_4 -> V_11 , L_41 ) ;
if ( V_14 -> V_54 ) {
F_3 ( & V_4 -> V_11 , L_27 ) ;
return - V_191 ;
}
if ( ! V_4 -> V_37 . V_207 )
return - V_68 ;
V_5 = V_4 -> V_37 . V_207 ( V_4 , V_204 ) ;
if ( V_5 ) {
F_3 ( & V_4 -> V_11 ,
L_42 ) ;
return - V_68 ;
}
return 0 ;
}
static int
F_68 ( struct V_152 * V_152 , void * V_153 ,
struct V_206 * V_208 )
{
struct V_61 * V_62 = V_153 ;
struct V_3 * V_4 = V_62 -> V_2 -> V_4 ;
F_17 ( 1 , V_65 , & V_4 -> V_11 , L_43 ) ;
if ( V_4 -> V_111 . V_196 &
V_209 ) {
* V_208 = V_4 -> V_111 . V_208 ;
} else {
return - V_68 ;
}
return 0 ;
}
static int F_69 ( struct V_152 * V_152 , void * V_153 ,
enum V_210 V_211 )
{
struct V_61 * V_62 = V_152 -> V_156 ;
struct V_13 * V_14 = V_62 -> V_14 ;
struct V_3 * V_4 = V_62 -> V_2 -> V_4 ;
struct V_27 * V_28 = V_62 -> V_2 -> V_28 ;
int V_5 ;
F_17 ( 1 , V_65 , & V_4 -> V_11 ,
L_44 ,
V_14 -> V_90 ) ;
if ( V_175 != V_211 ) {
F_3 ( & V_4 -> V_11 , L_45 ) ;
return - V_68 ;
}
if ( ! V_62 -> V_212 ) {
F_3 ( & V_4 -> V_11 , L_46 ) ;
return - V_213 ;
}
if ( ! V_14 -> V_54 ) {
F_3 ( & V_4 -> V_11 , L_47
L_48 , V_14 -> V_90 ) ;
return - V_68 ;
}
V_28 -> V_37 . V_214 ( V_28 ,
V_14 -> V_39 . V_40 ) ;
V_14 -> V_54 = 0 ;
V_5 = F_70 ( & V_14 -> V_215 , V_211 ) ;
return V_5 ;
}
static int F_71 ( struct V_152 * V_152 , void * V_153 ,
enum V_210 V_211 )
{
struct V_61 * V_62 = V_152 -> V_156 ;
struct V_13 * V_14 = V_62 -> V_14 ;
struct V_1 * V_2 = V_62 -> V_2 ;
struct V_3 * V_4 = V_62 -> V_2 -> V_4 ;
struct V_27 * V_28 = V_2 -> V_28 ;
int V_5 ;
V_28 -> V_37 . V_214 ( V_28 ,
V_14 -> V_39 . V_40 ) ;
F_17 ( 1 , V_65 , & V_4 -> V_11 , L_49 ,
V_14 -> V_90 ) ;
if ( V_175 != V_211 ) {
F_3 ( & V_4 -> V_11 , L_45 ) ;
return - V_68 ;
}
if ( ! V_62 -> V_212 ) {
F_3 ( & V_4 -> V_11 , L_46 ) ;
return - V_213 ;
}
if ( V_14 -> V_54 ) {
F_3 ( & V_4 -> V_11 , L_50 ) ;
return - V_191 ;
}
V_5 = F_72 ( & V_14 -> V_215 , V_211 ) ;
if ( V_5 ) {
F_3 ( & V_4 -> V_11 ,
L_51 ) ;
return V_5 ;
}
return V_5 ;
}
static int F_73 ( struct V_152 * V_152 , void * V_153 ,
struct V_216 * V_80 )
{
struct V_61 * V_62 = V_152 -> V_156 ;
struct V_13 * V_14 = V_62 -> V_14 ;
struct V_3 * V_4 = V_62 -> V_2 -> V_4 ;
int V_5 ;
F_17 ( 1 , V_65 , & V_4 -> V_11 ,
L_52 ,
V_14 -> V_90 ) ;
if ( V_175 != V_80 -> type ) {
F_3 ( & V_4 -> V_11 , L_45 ) ;
return - V_68 ;
}
if ( ! V_62 -> V_212 ) {
F_3 ( & V_4 -> V_11 , L_46 ) ;
return - V_213 ;
}
if ( V_152 -> V_217 & V_218 )
V_5 = F_74 ( & V_14 -> V_215 , V_80 , 1 ) ;
else
V_5 = F_74 ( & V_14 -> V_215 , V_80 , 0 ) ;
return V_5 ;
}
static int F_75 ( struct V_152 * V_152 , void * V_153 ,
struct V_216 * V_155 )
{
struct V_61 * V_62 = V_152 -> V_156 ;
struct V_13 * V_14 = V_62 -> V_14 ;
struct V_3 * V_4 = V_62 -> V_2 -> V_4 ;
F_17 ( 1 , V_65 , & V_4 -> V_11 ,
L_53 ,
V_14 -> V_90 ) ;
if ( V_175 != V_155 -> type ) {
F_3 ( & V_4 -> V_11 , L_45 ) ;
return - V_68 ;
}
if ( ! V_62 -> V_212 ) {
F_3 ( & V_4 -> V_11 , L_46 ) ;
return - V_213 ;
}
return F_76 ( & V_14 -> V_215 , V_155 ) ;
}
static int F_77 ( struct V_152 * V_152 , void * V_153 ,
struct V_216 * V_80 )
{
struct V_61 * V_62 = V_152 -> V_156 ;
struct V_13 * V_14 = V_62 -> V_14 ;
struct V_3 * V_4 = V_62 -> V_2 -> V_4 ;
F_17 ( 1 , V_65 , & V_4 -> V_11 ,
L_54 ,
V_14 -> V_90 ) ;
if ( V_175 != V_80 -> type ) {
F_3 ( & V_4 -> V_11 , L_45 ) ;
return - V_68 ;
}
return F_78 ( & V_14 -> V_215 , V_80 ) ;
}
static int F_79 ( struct V_152 * V_152 , void * V_153 ,
struct V_219 * V_220 )
{
struct V_61 * V_62 = V_152 -> V_156 ;
struct V_13 * V_14 = V_62 -> V_14 ;
struct V_3 * V_4 = V_62 -> V_2 -> V_4 ;
struct V_63 * V_64 ;
int V_5 ;
F_17 ( 1 , V_65 , & V_4 -> V_11 , L_55 ) ;
if ( V_175 != V_220 -> type ) {
F_3 ( & V_4 -> V_11 , L_45 ) ;
return - V_68 ;
}
if ( 0 != V_14 -> V_221 ) {
F_3 ( & V_4 -> V_11 , L_56 ) ;
return - V_191 ;
}
V_14 -> V_79 = F_80 ( V_4 -> V_168 ) ;
if ( F_81 ( V_14 -> V_79 ) ) {
F_3 ( & V_4 -> V_11 , L_57 ) ;
return F_82 ( V_14 -> V_79 ) ;
}
V_64 = & V_14 -> V_215 ;
memset ( V_64 , 0 , sizeof( * V_64 ) ) ;
V_64 -> type = V_175 ;
V_64 -> V_222 = V_223 | V_224 ;
V_64 -> V_225 = V_62 ;
V_64 -> V_37 = & V_226 ;
V_64 -> V_227 = & V_228 ;
V_64 -> V_229 = sizeof( struct V_33 ) ;
V_64 -> V_230 = V_231 ;
V_5 = F_83 ( V_64 ) ;
if ( V_5 ) {
F_3 ( & V_4 -> V_11 , L_58 ) ;
F_84 ( V_14 -> V_79 ) ;
return V_5 ;
}
V_62 -> V_212 = 1 ;
V_14 -> V_221 = 1 ;
V_14 -> V_232 = V_220 -> V_232 ;
F_36 ( & V_14 -> V_31 ) ;
return F_85 ( V_64 , V_220 ) ;
}
static int F_86 ( struct V_152 * V_233 , struct V_234 * V_235 )
{
struct V_61 * V_62 = V_233 -> V_156 ;
struct V_13 * V_14 = V_62 -> V_14 ;
struct V_3 * V_4 = V_62 -> V_2 -> V_4 ;
int V_5 ;
F_17 ( 1 , V_65 , & V_4 -> V_11 , L_59 ) ;
if ( F_87 ( & V_14 -> V_84 ) )
return - V_236 ;
V_5 = F_88 ( & V_14 -> V_215 , V_235 ) ;
F_32 ( & V_14 -> V_84 ) ;
return V_5 ;
}
static unsigned int F_89 ( struct V_152 * V_233 , T_3 * V_237 )
{
struct V_61 * V_62 = V_233 -> V_156 ;
struct V_13 * V_14 = V_62 -> V_14 ;
struct V_3 * V_4 = V_62 -> V_2 -> V_4 ;
unsigned int V_238 = 0 ;
F_17 ( 1 , V_65 , & V_4 -> V_11 , L_60 ) ;
if ( V_14 -> V_54 ) {
F_34 ( & V_14 -> V_84 ) ;
V_238 = F_90 ( & V_14 -> V_215 , V_233 , V_237 ) ;
F_32 ( & V_14 -> V_84 ) ;
}
return V_238 ;
}
static int F_91 ( struct V_152 * V_152 )
{
struct V_61 * V_62 = NULL ;
struct V_13 * V_14 = F_92 ( V_152 ) ;
struct V_1 * V_2 = V_14 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_27 * V_28 = V_2 -> V_28 ;
int V_238 ;
V_62 = F_93 ( sizeof( struct V_61 ) , V_239 ) ;
if ( V_62 == NULL ) {
F_3 ( & V_4 -> V_11 ,
L_61 ) ;
return - V_240 ;
}
F_17 ( 1 , V_65 , & V_4 -> V_11 ,
L_62 ,
V_14 -> V_90 ) ;
V_152 -> V_156 = V_62 ;
V_62 -> V_14 = V_14 ;
V_62 -> V_2 = V_2 ;
if ( ! V_14 -> V_241 ) {
if ( F_87 ( & V_14 -> V_84 ) )
return - V_236 ;
V_238 = V_28 -> V_37 . V_192 ( V_28 ,
V_14 -> V_39 . V_40 ) ;
F_32 ( & V_14 -> V_84 ) ;
if ( V_238 < 0 ) {
F_3 ( & V_4 -> V_11 ,
L_28 ) ;
F_94 ( V_62 ) ;
return - V_68 ;
}
}
V_14 -> V_241 ++ ;
V_62 -> V_212 = 0 ;
V_62 -> V_157 = V_242 ;
F_95 ( & V_14 -> V_157 , & V_62 -> V_157 ) ;
F_17 ( 1 , V_65 , & V_4 -> V_11 ,
L_63 ) ;
return 0 ;
}
static int F_96 ( struct V_152 * V_152 )
{
struct V_61 * V_62 = V_152 -> V_156 ;
struct V_13 * V_14 = V_62 -> V_14 ;
struct V_93 * V_94 = & V_14 -> V_39 . V_95 ;
struct V_1 * V_2 = V_62 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_27 * V_28 = V_2 -> V_28 ;
F_17 ( 1 , V_65 , & V_4 -> V_11 , L_64 ) ;
F_34 ( & V_14 -> V_84 ) ;
if ( V_62 -> V_212 ) {
V_14 -> V_221 = 0 ;
V_28 -> V_37 . V_214 ( V_28 ,
V_14 -> V_39 . V_40 ) ;
V_14 -> V_54 = 0 ;
F_97 ( & V_14 -> V_215 ) ;
F_84 ( & V_14 -> V_215 ) ;
}
V_14 -> V_241 -- ;
if ( ! V_14 -> V_241 ) {
if ( V_94 -> V_98 == V_99 ) {
struct V_13 * V_100 ;
V_100 =
F_41 ( V_2 , V_14 ) ;
V_28 -> V_37 . V_214 ( V_28 ,
V_100 -> V_39 . V_40 ) ;
V_28 -> V_37 . V_243 ( V_28 ,
V_100 -> V_39 . V_40 ) ;
}
V_28 -> V_37 . V_214 ( V_28 ,
V_14 -> V_39 . V_40 ) ;
V_28 -> V_37 . V_243 ( V_28 ,
V_14 -> V_39 . V_40 ) ;
}
F_98 ( & V_14 -> V_157 , V_62 -> V_157 ) ;
V_152 -> V_156 = NULL ;
F_32 ( & V_14 -> V_84 ) ;
F_94 ( V_62 ) ;
V_2 -> V_41 = 0 ;
return 0 ;
}
static int F_99 ( struct V_244 * V_48 , void * V_245 )
{
struct V_246 * V_168 = F_100 ( V_48 ) ;
struct V_1 * V_247 = V_245 ;
if ( strcmp ( L_65 , V_168 -> V_248 ) == 0 )
V_247 -> V_4 = F_101 ( V_168 ) ;
if ( strstr ( V_168 -> V_248 , L_66 ) != NULL )
V_247 -> V_28 = F_101 ( V_168 ) ;
return 0 ;
}
static int F_102 ( int V_47 , struct V_1 * V_2 ,
struct V_246 * V_168 )
{
struct V_13 * V_249 = NULL ;
struct V_250 * V_251 = NULL ;
V_2 -> V_48 [ V_47 ] =
F_103 ( sizeof( struct V_13 ) , V_239 ) ;
if ( ! V_2 -> V_48 [ V_47 ] ) {
F_104 ( V_252 L_67 ) ;
return - V_240 ;
}
F_105 ( & V_2 -> V_48 [ V_47 ] -> V_83 ) ;
F_106 ( & V_2 -> V_48 [ V_47 ] -> V_84 ) ;
V_249 = V_2 -> V_48 [ V_47 ] ;
V_251 = & V_249 -> V_253 ;
V_251 -> V_254 = V_255 ;
V_251 -> V_256 = & V_257 ;
V_251 -> V_258 = & V_259 ;
V_251 -> V_260 = - 1 ;
V_251 -> V_11 = & V_2 -> V_4 -> V_11 ;
V_251 -> V_261 = & V_249 -> V_84 ;
V_251 -> V_262 = V_263 ;
if ( V_2 -> V_4 -> V_111 . V_196 &
V_197 )
V_251 -> V_264 = ( V_123 | V_124 ) ;
snprintf ( V_251 -> V_248 , sizeof( V_251 -> V_248 ) ,
L_68 ,
( V_161 >> 16 ) & 0xff ,
( V_161 >> 8 ) & 0xff ,
( V_161 ) & 0xff ) ;
V_249 -> V_90 = V_47 ;
V_249 -> V_39 . V_40 =
( ( V_47 == V_91 ) ? V_265 : V_266 ) ;
F_107 ( & V_249 -> V_157 ) ;
return 0 ;
}
static int F_108 ( struct V_13 * V_249 ,
struct V_1 * V_2 ,
struct V_246 * V_168 )
{
int V_238 ;
F_109 ( & V_2 -> V_4 -> V_11 ,
L_69 ) ;
F_109 ( & V_2 -> V_4 -> V_11 ,
L_70 ,
( int ) V_249 ,
( int ) & V_249 -> V_253 ) ;
V_238 = F_110 ( & V_249 -> V_253 ,
V_267 ,
- 1 ) ;
if ( V_238 )
return - V_268 ;
V_249 -> V_2 = V_2 ;
F_111 ( V_168 , V_2 ) ;
F_112 ( & V_249 -> V_253 ,
V_249 ) ;
return 0 ;
}
static int F_113 ( struct V_246 * V_168 )
{
struct V_13 * V_249 ;
struct V_1 * V_2 ;
struct V_269 * V_270 = NULL ;
int V_271 ;
int V_47 ;
int V_238 ;
int V_42 ;
F_104 ( V_272 L_71 ) ;
V_2 = F_103 ( sizeof( struct V_1 ) , V_239 ) ;
if ( ! V_2 ) {
F_104 ( V_252 L_67 ) ;
return - V_240 ;
}
F_105 ( & V_2 -> V_30 ) ;
V_238 = F_114 ( & V_273 , NULL , V_2 ,
F_99 ) ;
if ( V_238 < 0 )
return V_238 ;
if ( NULL != V_2 -> V_4 -> V_37 . V_274 ) {
V_238 = V_2 -> V_4 -> V_37 . V_274 ( & V_168 -> V_48 ,
V_2 -> V_4 ) ;
if ( V_238 ) {
F_3 ( & V_2 -> V_4 -> V_11 ,
L_72 ) ;
V_238 = - V_240 ;
goto V_275;
}
}
for ( V_47 = 0 ; V_47 < V_53 ; V_47 ++ ) {
if ( F_102 ( V_47 , V_2 , V_168 ) ) {
V_238 = - V_268 ;
goto V_275;
}
}
V_270 = F_115 ( V_168 , V_276 , 0 ) ;
if ( ! V_270 ) {
F_3 ( & V_2 -> V_4 -> V_11 ,
L_73 ) ;
V_238 = - V_268 ;
goto V_275;
}
V_42 = V_270 -> V_277 ;
if ( F_116 ( V_42 , F_14 , V_278 , V_279 ,
V_2 ) ) {
F_3 ( & V_2 -> V_4 -> V_11 ,
L_74 ) ;
V_238 = - V_268 ;
goto V_275;
}
for ( V_47 = 0 ; V_47 < V_53 ; V_47 ++ ) {
if ( F_108 ( V_2 -> V_48 [ V_47 ] , V_2 , V_168 ) ) {
V_238 = - V_268 ;
goto V_280;
}
}
F_104 ( V_272 L_75 ) ;
return 0 ;
V_280:
F_117 ( V_270 -> V_277 , V_2 ) ;
V_275:
for ( V_271 = 0 ; V_271 < V_53 ; V_271 ++ ) {
V_249 = V_2 -> V_48 [ V_271 ] ;
if ( V_249 ) {
F_118 (
& V_249 -> V_253 ) ;
F_94 ( V_2 -> V_48 [ V_271 ] ) ;
}
}
F_94 ( V_2 ) ;
return V_238 ;
}
static int F_119 ( struct V_246 * V_168 )
{
struct V_13 * V_249 ;
struct V_1 * V_2 = F_101 ( V_168 ) ;
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_269 * V_270 ;
int V_47 ;
F_17 ( 1 , V_65 , & V_4 -> V_11 , L_76 ) ;
V_270 = F_115 ( V_168 , V_276 , 0 ) ;
F_117 ( V_270 -> V_277 , V_2 ) ;
if ( NULL != V_4 -> V_37 . V_281 )
V_4 -> V_37 . V_281 ( & V_168 -> V_48 , V_4 ) ;
for ( V_47 = 0 ; V_47 < V_53 ; V_47 ++ ) {
V_249 = V_2 -> V_48 [ V_47 ] ;
F_118 ( & V_249 -> V_253 ) ;
}
for ( V_47 = 0 ; V_47 < V_53 ; V_47 ++ ) {
F_94 ( V_2 -> V_48 [ V_47 ] ) ;
V_2 -> V_48 [ V_47 ] = NULL ;
}
return 0 ;
}
