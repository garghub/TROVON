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
V_14 -> V_17 -> V_19 . V_20 = V_16 . V_20 ;
V_14 -> V_17 -> V_19 . V_21 = V_16 . V_22 / V_23 ;
V_14 -> V_17 -> V_24 = V_25 ;
F_6 ( & V_14 -> V_17 -> V_26 ) ;
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
V_14 -> V_18 = F_11 (
V_14 -> V_31 . V_32 ,
struct V_33 ,
V_34 ) ;
F_12 ( & V_14 -> V_18 -> V_34 ) ;
F_10 ( & V_12 -> V_30 ) ;
V_14 -> V_18 -> V_24 = V_35 ;
V_29 = F_13 ( V_14 -> V_18 ) ;
V_28 -> V_36 . V_37 ( V_28 ,
V_14 -> V_38 . V_39 ,
V_29 ,
V_12 -> V_40 ) ;
}
static T_1 F_14 ( int V_41 , void * V_42 )
{
struct V_1 * V_2 = (struct V_1 * ) V_42 ;
struct V_13 * V_14 ;
static unsigned V_43 ;
unsigned V_44 = 0 ;
int V_45 ;
int V_46 ;
if ( ( NULL == V_42 ) || ( NULL == V_2 -> V_47 [ 0 ] ) )
return V_48 ;
if ( F_1 ( V_2 ) )
V_44 |= V_49 ;
else
V_44 |= V_50 ;
if ( V_44 == ( V_43 & ~ V_51 ) ) {
V_44 |= V_51 ;
} else if ( V_44 == V_49 ) {
V_44 |= V_51 ;
}
V_43 = V_44 ;
for ( V_46 = 0 ; V_46 < V_52 ; V_46 ++ ) {
V_14 = V_2 -> V_47 [ V_46 ] ;
if ( ! V_14 -> V_53 )
continue;
if ( V_14 -> V_54 ) {
V_14 -> V_54 = 0 ;
continue;
}
if ( ( V_55 == V_14 -> V_56 . V_57 ) &&
( V_44 & V_51 ) ) {
F_4 ( V_2 , V_14 ) ;
F_7 ( V_2 , V_14 ) ;
} else {
V_14 -> V_58 ^= 1 ;
if ( V_44 & V_50 )
V_45 = 0 ;
else
V_45 = 1 ;
if ( V_45 != V_14 -> V_58 ) {
V_14 -> V_58 = V_45 ;
continue;
}
if ( 0 == V_45 )
F_4 ( V_2 , V_14 ) ;
else
F_7 ( V_2 , V_14 ) ;
}
}
return V_48 ;
}
static int F_15 ( struct V_59 * V_60 ,
struct V_33 * V_61 ,
enum V_62 V_57 )
{
struct V_63 * V_64 = V_60 -> V_65 ;
struct V_13 * V_14 = V_64 -> V_14 ;
struct V_3 * V_4 = V_64 -> V_2 -> V_4 ;
unsigned long V_29 ;
int V_5 ;
F_16 ( 1 , V_66 , & V_4 -> V_11 ,
L_2 ) ;
if ( V_67 == V_61 -> V_24 ) {
V_61 -> V_68 = V_14 -> V_56 . V_68 ;
V_61 -> V_69 = V_14 -> V_56 . V_69 ;
V_61 -> V_70 = V_14 -> V_56 . V_71 ;
V_61 -> V_57 = V_57 ;
V_5 = F_17 ( V_60 , V_61 , NULL ) ;
if ( V_5 < 0 ) {
F_3 ( & V_4 -> V_11 , L_3 ) ;
return - V_72 ;
}
V_29 = F_13 ( V_61 ) ;
if ( V_60 -> V_73 ) {
if ( ! F_18 ( V_29 , 8 ) ) {
F_3 ( & V_4 -> V_11 ,
L_4 ) ;
return - V_72 ;
}
}
V_61 -> V_24 = V_74 ;
}
return 0 ;
}
static int F_19 ( struct V_59 * V_60 ,
unsigned int * V_75 ,
unsigned int * V_70 )
{
struct V_63 * V_64 = V_60 -> V_65 ;
struct V_13 * V_14 = V_64 -> V_14 ;
struct V_3 * V_4 = V_64 -> V_2 -> V_4 ;
F_16 ( 1 , V_66 , & V_4 -> V_11 , L_5 ) ;
* V_70 = V_14 -> V_56 . V_71 ;
if ( * V_75 < V_76 )
* V_75 = V_14 -> V_77 = V_76 ;
return 0 ;
}
static void F_20 ( struct V_59 * V_60 ,
struct V_33 * V_61 )
{
struct V_63 * V_64 = V_60 -> V_65 ;
struct V_13 * V_14 = V_64 -> V_14 ;
struct V_1 * V_78 = V_64 -> V_2 ;
struct V_3 * V_4 = V_64 -> V_2 -> V_4 ;
unsigned long V_79 ;
F_16 ( 1 , V_66 , & V_4 -> V_11 ,
L_6 ) ;
F_21 ( & V_78 -> V_30 , V_79 ) ;
F_22 ( & V_61 -> V_34 , & V_14 -> V_31 ) ;
F_23 ( & V_78 -> V_30 , V_79 ) ;
V_61 -> V_24 = V_80 ;
}
static void F_24 ( struct V_59 * V_60 ,
struct V_33 * V_61 )
{
struct V_63 * V_64 = V_60 -> V_65 ;
struct V_13 * V_14 = V_64 -> V_14 ;
struct V_3 * V_4 = V_64 -> V_2 -> V_4 ;
F_16 ( 1 , V_66 , & V_4 -> V_11 ,
L_7 ) ;
if ( V_81 != V_14 -> V_82 )
F_25 ( V_60 , V_61 ) ;
V_61 -> V_24 = V_67 ;
}
static
struct V_13 *
F_26 ( struct V_1 * V_2 ,
struct V_13 * V_14 )
{
enum V_83 V_84 , V_85 ;
V_84 = V_14 -> V_86 ;
V_85 = ( V_84 == V_87 ) ?
V_88 : V_87 ;
return V_2 -> V_47 [ V_85 ] ;
}
static int F_27 ( struct V_1 * V_2 ,
struct V_13 * V_14 )
{
struct V_89 * V_90 = & V_14 -> V_38 . V_91 ;
struct V_27 * V_28 = V_2 -> V_28 ;
struct V_3 * V_4 = V_2 -> V_4 ;
unsigned long V_29 ;
int V_5 ;
V_29 = F_13 ( V_14 -> V_17 ) ;
V_28 -> V_36 . V_37 ( V_28 ,
V_14 -> V_38 . V_39 ,
V_29 ,
V_2 -> V_40 ) ;
V_5 = V_28 -> V_36 . V_92 ( V_28 ,
V_14 -> V_38 . V_39 , 0 ) ;
if ( V_5 < 0 ) {
F_3 ( & V_4 -> V_11 ,
L_8 ) ;
return - 1 ;
}
V_14 -> V_38 . V_93 = 1 ;
if ( V_90 -> V_94 == V_95 ) {
struct V_13 * V_96 =
F_26 ( V_2 , V_14 ) ;
V_5 = V_28 -> V_36 . V_92 ( V_28 ,
V_96 -> V_38 . V_39 , 1 ) ;
if ( V_5 < 0 ) {
F_3 ( & V_4 -> V_11 ,
L_9 ) ;
return - 1 ;
}
V_96 -> V_38 . V_93 = 1 ;
}
return 0 ;
}
static void
F_28 ( struct V_1 * V_2 ,
struct V_13 * V_14 ,
int V_97 , int V_98 )
{
struct V_99 * V_38 = & V_14 -> V_38 ;
struct V_100 * V_94 = & V_14 -> V_56 ;
struct V_89 * V_90 = & V_14 -> V_38 . V_91 ;
struct V_3 * V_4 = V_2 -> V_4 ;
int V_101 ;
int V_102 = 0 ;
int V_103 = 0 ;
int V_104 ;
int V_105 ;
T_2 V_106 = V_4 -> V_107 . V_108 ;
V_90 -> V_109 = V_94 -> V_68 ;
V_90 -> V_110 = V_94 -> V_69 ;
V_38 -> V_111 = V_112 ;
V_38 -> V_113 = V_112 ;
V_38 -> V_102 = V_114 ;
V_38 -> V_103 = V_115 ;
if ( V_94 -> V_68 < V_97 ) {
V_104 = V_4 -> V_107 . V_116 / V_94 -> V_68 ;
if ( V_104 < 2 )
V_104 = 1 ;
else if ( V_104 >= 4 )
V_104 = 4 ;
else
V_104 = 2 ;
V_90 -> V_109 *= V_104 ;
if ( V_90 -> V_109 < V_97 ) {
if ( ( V_106 & V_117 ) ||
( V_106 & V_118 ) ) {
V_101 = ( V_90 -> V_109 *
V_119 ) /
V_120 ;
if ( V_101 <= V_97 ) {
V_102 = 1 ;
V_90 -> V_109 = V_101 ;
}
}
}
if ( V_104 == 2 )
V_38 -> V_111 = V_121 ;
else if ( V_104 == 4 )
V_38 -> V_111 = V_122 ;
if ( V_102 )
V_38 -> V_102 = V_123 ;
} else {
V_90 -> V_109 = V_97 ;
}
if ( V_94 -> V_69 < V_98 ) {
V_105 = V_98 / V_94 -> V_69 ;
if ( V_105 < 2 )
V_105 = 1 ;
else if ( V_105 >= 4 )
V_105 = 4 ;
else
V_105 = 2 ;
V_90 -> V_110 *= V_105 ;
if ( V_90 -> V_110 < V_98 ) {
if ( ( V_106 & V_118 ) ) {
V_101 = ( V_90 -> V_110 *
V_124 ) /
V_125 ;
if ( V_101 <= V_98 ) {
V_103 = 1 ;
V_90 -> V_110 = V_101 ;
}
}
}
if ( V_105 == 2 )
V_38 -> V_113 = V_121 ;
else if ( V_105 == 4 )
V_38 -> V_113 = V_122 ;
if ( V_103 )
V_38 -> V_102 = V_126 ;
} else {
V_90 -> V_110 = V_98 ;
}
F_16 ( 1 , V_66 , & V_4 -> V_11 ,
L_10 ,
V_90 -> V_109 , V_90 -> V_110 ) ;
}
static void F_29 ( struct V_1 * V_2 ,
struct V_13 * V_14 ,
int V_127 , int V_128 )
{
struct V_89 * V_90 = & V_14 -> V_38 . V_91 ;
struct V_3 * V_4 = V_2 -> V_4 ;
V_90 -> V_129 = F_30 ( ( unsigned int ) V_128 ,
V_4 -> V_107 . V_116 - V_90 -> V_109 ) ;
V_90 -> V_130 = F_30 ( ( unsigned int ) V_127 ,
V_4 -> V_107 . V_131 - V_90 -> V_110 ) ;
F_16 ( 1 , V_66 , & V_4 -> V_11 ,
L_11 ,
V_90 -> V_129 , V_90 -> V_130 ) ;
}
static void F_31 ( struct V_1 * V_2 ,
struct V_132 * V_133 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
if ( ( V_133 -> V_68 == 0 ) ||
( ( V_133 -> V_68 + V_133 -> V_128 ) > V_4 -> V_107 . V_116 ) )
V_133 -> V_68 = V_4 -> V_107 . V_116 - V_133 -> V_128 ;
if ( ( V_133 -> V_69 == 0 ) || ( ( V_133 -> V_69 + V_133 -> V_127 ) >
V_4 -> V_107 . V_131 ) )
V_133 -> V_69 = V_4 -> V_107 . V_131 - V_133 -> V_127 ;
if ( V_4 -> V_107 . V_134 )
V_133 -> V_69 &= ( ~ 0x01 ) ;
}
static int F_32 ( struct V_1 * V_2 ,
struct V_100 * V_94 , int V_135 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
int V_136 = 1 ;
int V_137 = 32 ;
int V_138 ;
int V_139 ;
int V_140 ;
if ( ( V_94 -> V_141 != V_142 ) &&
( V_94 -> V_141 != V_143 ) )
V_94 -> V_141 = V_142 ;
if ( ( V_94 -> V_57 != V_144 ) &&
( V_94 -> V_57 != V_55 ) ) {
if ( V_4 -> V_107 . V_134 )
V_94 -> V_57 = V_144 ;
else
V_94 -> V_57 = V_55 ;
}
if ( V_94 -> V_57 == V_144 )
V_136 = 2 ;
if ( V_94 -> V_141 == V_143 )
V_140 = 1 ;
else
V_140 = 2 ;
V_139 = V_4 -> V_107 . V_116 ;
V_138 = V_4 -> V_107 . V_131 ;
V_137 /= V_140 ;
if ( ! V_94 -> V_68 || ( V_94 -> V_68 < V_137 ) ||
( V_94 -> V_68 > V_139 ) ) {
V_94 -> V_68 = V_4 -> V_107 . V_116 ;
}
if ( ! V_94 -> V_69 || ( V_94 -> V_69 < V_136 ) ||
( V_94 -> V_69 > V_138 ) ) {
V_94 -> V_69 = V_4 -> V_107 . V_131 ;
}
if ( V_94 -> V_145 < ( V_94 -> V_68 * V_140 ) )
V_94 -> V_145 = V_94 -> V_68 * V_140 ;
V_94 -> V_145 = ( ( V_94 -> V_68 * V_140 + 31 ) & ~ 31 ) ;
if ( V_94 -> V_141 == V_143 )
V_94 -> V_71 = V_94 -> V_145 * V_94 -> V_69 +
( V_94 -> V_145 * V_94 -> V_69 >> 1 ) ;
else
V_94 -> V_71 = V_94 -> V_145 * V_94 -> V_69 ;
return 0 ;
}
static int F_33 ( struct V_146 * V_146 , void * V_147 ,
enum V_148 * V_149 )
{
struct V_63 * V_64 = V_146 -> V_150 ;
struct V_13 * V_14 = V_64 -> V_14 ;
* V_149 = F_34 ( & V_14 -> V_151 ) ;
return 0 ;
}
static int F_35 ( struct V_146 * V_146 , void * V_147 ,
enum V_148 V_149 )
{
struct V_63 * V_64 = V_146 -> V_150 ;
struct V_13 * V_14 = V_64 -> V_14 ;
int V_5 ;
V_5 = F_36 ( & V_14 -> V_151 , & V_64 -> V_151 , V_149 ) ;
return V_5 ;
}
static int F_37 ( struct V_146 * V_146 , void * V_147 ,
struct V_152 * V_153 )
{
struct V_63 * V_64 = V_146 -> V_150 ;
struct V_3 * V_4 = V_64 -> V_2 -> V_4 ;
V_153 -> V_154 = V_155 ;
V_153 -> V_156 = V_157 | V_158 ;
F_38 ( V_153 -> V_159 , V_160 , sizeof( V_153 -> V_159 ) ) ;
F_38 ( V_153 -> V_161 , L_12 , sizeof( V_153 -> V_161 ) ) ;
F_38 ( V_153 -> V_162 , V_4 -> V_90 -> V_163 , sizeof( V_153 -> V_162 ) ) ;
return 0 ;
}
static int F_39 ( struct V_146 * V_146 , void * V_147 ,
const struct V_164 * V_165 )
{
struct V_63 * V_64 = V_146 -> V_150 ;
struct V_13 * V_14 = V_64 -> V_14 ;
struct V_1 * V_2 = V_64 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_89 * V_90 = & V_14 -> V_38 . V_91 ;
struct V_27 * V_28 = V_2 -> V_28 ;
struct V_132 V_166 = V_165 -> V_133 ;
int V_5 ;
F_16 ( 1 , V_66 , & V_4 -> V_11 ,
L_13 , V_14 -> V_86 ) ;
if ( V_165 -> type != V_167 ) {
F_3 ( & V_4 -> V_11 , L_14 ) ;
return - V_72 ;
}
if ( V_166 . V_127 < 0 )
V_166 . V_127 = 0 ;
if ( V_166 . V_128 < 0 )
V_166 . V_128 = 0 ;
F_31 ( V_2 , & V_166 ) ;
V_28 -> V_36 . V_168 ( V_28 ,
V_14 -> V_38 . V_39 , V_90 ) ;
F_28 ( V_2 , V_14 ,
V_166 . V_68 ,
V_166 . V_69 ) ;
F_29 ( V_2 , V_14 , V_166 . V_127 ,
V_166 . V_128 ) ;
V_5 = V_28 -> V_36 . V_169 ( V_28 ,
V_14 -> V_38 . V_39 , V_90 ) ;
if ( V_5 < 0 ) {
F_3 ( & V_4 -> V_11 ,
L_15 ) ;
return - V_72 ;
}
V_28 -> V_36 . V_170 ( V_28 ,
V_14 -> V_38 . V_39 ,
V_14 -> V_38 . V_111 ,
V_14 -> V_38 . V_113 ) ;
V_5 = V_28 -> V_36 . V_171 ( V_28 ,
V_14 -> V_38 . V_102 ,
V_14 -> V_38 . V_103 ) ;
if ( V_5 < 0 ) {
F_3 ( & V_4 -> V_11 ,
L_16 ) ;
return - V_72 ;
}
if ( ( V_14 -> V_38 . V_111 != V_112 ) ||
( V_14 -> V_38 . V_113 != V_112 ) ||
( V_14 -> V_38 . V_102 != V_114 ) ||
( V_14 -> V_38 . V_103 != V_115 ) )
V_28 -> V_36 . V_172 ( V_28 , 1 ) ;
else
V_28 -> V_36 . V_172 ( V_28 , 0 ) ;
return 0 ;
}
static int F_40 ( struct V_146 * V_146 , void * V_147 ,
struct V_164 * V_165 )
{
struct V_63 * V_64 = V_146 -> V_150 ;
struct V_13 * V_14 = V_64 -> V_14 ;
struct V_89 * V_90 = & V_14 -> V_38 . V_91 ;
struct V_3 * V_4 = V_64 -> V_2 -> V_4 ;
struct V_27 * V_28 = V_64 -> V_2 -> V_28 ;
struct V_132 * V_166 = & V_165 -> V_133 ;
int V_5 ;
F_16 ( 1 , V_66 , & V_4 -> V_11 ,
L_17 ,
V_14 -> V_86 ) ;
if ( V_165 -> type != V_167 ) {
F_3 ( & V_4 -> V_11 , L_14 ) ;
V_5 = - V_72 ;
}
V_28 -> V_36 . V_168 ( V_28 ,
V_14 -> V_38 . V_39 , V_90 ) ;
V_166 -> V_127 = V_90 -> V_130 ;
V_166 -> V_128 = V_90 -> V_129 ;
V_166 -> V_68 = V_90 -> V_109 ;
V_166 -> V_69 = V_90 -> V_110 ;
return 0 ;
}
static int F_41 ( struct V_146 * V_146 , void * V_147 ,
struct V_173 * V_174 )
{
struct V_63 * V_64 = V_146 -> V_150 ;
struct V_3 * V_4 = V_64 -> V_2 -> V_4 ;
F_16 ( 1 , V_66 , & V_4 -> V_11 , L_18 ) ;
V_174 -> type = V_167 ;
V_174 -> V_175 . V_128 = 0 ;
V_174 -> V_175 . V_127 = 0 ;
V_174 -> V_175 . V_68 = V_4 -> V_107 . V_116 ;
V_174 -> V_175 . V_69 = V_4 -> V_107 . V_131 ;
V_174 -> V_176 = V_4 -> V_107 . V_177 ;
V_174 -> V_178 = V_174 -> V_175 ;
return 0 ;
}
static int F_42 ( struct V_146 * V_146 , void * V_147 ,
struct V_179 * V_180 )
{
struct V_63 * V_64 = V_146 -> V_150 ;
struct V_13 * V_14 = V_64 -> V_14 ;
struct V_3 * V_4 = V_64 -> V_2 -> V_4 ;
F_16 ( 1 , V_66 , & V_4 -> V_11 ,
L_19 ,
V_14 -> V_86 ) ;
if ( V_167 != V_180 -> type ) {
F_3 ( & V_4 -> V_11 , L_20 ) ;
return - V_72 ;
}
V_180 -> V_180 . V_181 = V_14 -> V_56 ;
return 0 ;
}
static int F_43 ( struct V_146 * V_146 , void * V_147 ,
struct V_182 * V_180 )
{
struct V_63 * V_64 = V_146 -> V_150 ;
struct V_13 * V_14 = V_64 -> V_14 ;
struct V_3 * V_4 = V_64 -> V_2 -> V_4 ;
unsigned int V_183 = 0 ;
F_16 ( 1 , V_66 , & V_4 -> V_11 ,
L_21 ,
V_14 -> V_86 ) ;
if ( V_180 -> V_183 > 1 ) {
F_3 ( & V_4 -> V_11 , L_22 ) ;
return - V_72 ;
}
V_183 = V_180 -> V_183 ;
memset ( V_180 , 0 , sizeof( * V_180 ) ) ;
V_180 -> V_183 = V_183 ;
V_180 -> type = V_167 ;
if ( V_183 == 0 ) {
strcpy ( V_180 -> V_184 , L_23 ) ;
V_180 -> V_141 = V_142 ;
} else {
strcpy ( V_180 -> V_184 , L_24 ) ;
V_180 -> V_141 = V_143 ;
}
return 0 ;
}
static int F_44 ( struct V_146 * V_146 , void * V_147 ,
struct V_179 * V_180 )
{
struct V_63 * V_64 = V_146 -> V_150 ;
struct V_13 * V_14 = V_64 -> V_14 ;
struct V_1 * V_2 = V_64 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_89 * V_90 = & V_14 -> V_38 . V_91 ;
struct V_100 * V_94 = & V_180 -> V_180 . V_181 ;
struct V_27 * V_28 = V_2 -> V_28 ;
int V_5 ;
F_16 ( 1 , V_66 , & V_4 -> V_11 ,
L_25 ,
V_14 -> V_86 ) ;
if ( V_14 -> V_53 ) {
F_3 ( & V_4 -> V_11 , L_26 ) ;
return - V_185 ;
}
if ( V_167 != V_180 -> type ) {
F_16 ( 1 , V_66 , & V_4 -> V_11 , L_20 ) ;
return - V_72 ;
}
V_5 = F_32 ( V_2 , V_94 , 1 ) ;
if ( V_5 )
return V_5 ;
V_14 -> V_56 = * V_94 ;
V_28 -> V_36 . V_168 ( V_28 ,
V_14 -> V_38 . V_39 , V_90 ) ;
V_90 -> V_109 = V_94 -> V_68 ;
V_90 -> V_110 = V_94 -> V_69 ;
V_90 -> V_186 = V_94 -> V_145 ;
V_90 -> V_130 = 0 ;
V_90 -> V_129 = 0 ;
V_90 -> V_134 = V_4 -> V_107 . V_134 ;
if ( V_142 == V_94 -> V_141 )
V_90 -> V_94 = V_187 ;
if ( V_143 == V_94 -> V_141 ) {
struct V_13 * V_96 ;
V_90 -> V_94 = V_95 ;
V_96 = F_26 ( V_2 ,
V_14 ) ;
V_96 -> V_38 . V_91 . V_94 = V_95 ;
}
V_5 = V_28 -> V_36 . V_169 ( V_28 ,
V_14 -> V_38 . V_39 , V_90 ) ;
if ( V_5 < 0 ) {
F_3 ( & V_4 -> V_11 ,
L_27 ) ;
return - V_72 ;
}
V_28 -> V_36 . V_168 ( V_28 ,
V_14 -> V_38 . V_39 , V_90 ) ;
return 0 ;
}
static int F_45 ( struct V_146 * V_146 , void * V_147 ,
struct V_179 * V_180 )
{
struct V_63 * V_64 = V_146 -> V_150 ;
struct V_1 * V_2 = V_64 -> V_2 ;
struct V_3 * V_4 = V_64 -> V_2 -> V_4 ;
struct V_100 * V_94 = & V_180 -> V_180 . V_181 ;
F_16 ( 1 , V_66 , & V_4 -> V_11 , L_28 ) ;
if ( V_167 != V_180 -> type ) {
F_3 ( & V_4 -> V_11 , L_20 ) ;
return - V_72 ;
}
return F_32 ( V_2 , V_94 , 0 ) ;
}
static int F_46 ( struct V_146 * V_146 , void * V_147 ,
T_2 * V_108 )
{
struct V_63 * V_64 = V_147 ;
struct V_13 * V_14 = V_64 -> V_14 ;
struct V_3 * V_4 = V_64 -> V_2 -> V_4 ;
int V_5 ;
F_16 ( 1 , V_66 , & V_4 -> V_11 , L_29 ) ;
if ( V_14 -> V_53 ) {
F_3 ( & V_4 -> V_11 , L_26 ) ;
return - V_185 ;
}
if ( NULL != V_4 -> V_36 . V_188 ) {
V_5 = V_4 -> V_36 . V_188 ( V_4 , V_108 ) ;
if ( V_5 ) {
F_3 ( & V_4 -> V_11 ,
L_30 ) ;
return - V_72 ;
}
} else {
return - V_72 ;
}
return 0 ;
}
static int F_47 ( struct V_146 * V_146 , void * V_147 ,
T_2 * V_108 )
{
struct V_63 * V_64 = V_147 ;
struct V_3 * V_4 = V_64 -> V_2 -> V_4 ;
F_16 ( 1 , V_66 , & V_4 -> V_11 , L_31 ) ;
if ( V_4 -> V_107 . V_189 & V_190 ) {
* V_108 = V_4 -> V_107 . V_108 ;
return 0 ;
}
return - V_72 ;
}
static int F_48 ( struct V_146 * V_146 , void * V_147 ,
struct V_191 * V_192 )
{
struct V_63 * V_64 = V_147 ;
struct V_3 * V_4 = V_64 -> V_2 -> V_4 ;
int V_5 ;
F_16 ( 1 , V_66 , & V_4 -> V_11 , L_32 ) ;
if ( NULL == V_4 -> V_36 . V_193 )
return - V_72 ;
V_5 = V_4 -> V_36 . V_193 ( V_4 , V_192 ) ;
if ( V_5 ) {
F_16 ( 1 , V_66 , & V_4 -> V_11 ,
L_33 ) ;
return - V_72 ;
}
return 0 ;
}
static int F_49 ( struct V_146 * V_146 , void * V_147 ,
unsigned int V_46 )
{
struct V_63 * V_64 = V_147 ;
struct V_13 * V_14 = V_64 -> V_14 ;
struct V_3 * V_4 = V_64 -> V_2 -> V_4 ;
int V_5 ;
F_16 ( 1 , V_66 , & V_4 -> V_11 , L_34 ) ;
if ( V_14 -> V_53 ) {
F_3 ( & V_4 -> V_11 , L_26 ) ;
return - V_185 ;
}
if ( NULL == V_4 -> V_36 . V_194 )
return - V_72 ;
V_5 = V_4 -> V_36 . V_194 ( V_4 , V_46 ) ;
if ( V_5 ) {
F_3 ( & V_4 -> V_11 ,
L_35 ) ;
return - V_72 ;
}
return 0 ;
}
static int F_50 ( struct V_146 * V_146 , void * V_147 ,
unsigned int * V_46 )
{
struct V_63 * V_64 = V_147 ;
struct V_3 * V_4 = V_64 -> V_2 -> V_4 ;
F_16 ( 1 , V_66 , & V_4 -> V_11 , L_36 ) ;
* V_46 = V_4 -> V_195 ;
return 0 ;
}
static int
F_51 ( struct V_146 * V_146 , void * V_147 ,
struct V_196 * V_197 )
{
struct V_63 * V_64 = V_147 ;
struct V_3 * V_4 = V_64 -> V_2 -> V_4 ;
int V_5 ;
F_16 ( 1 , V_66 , & V_4 -> V_11 , L_37 ) ;
if ( NULL == V_4 -> V_36 . V_198 )
return - V_72 ;
V_5 = V_4 -> V_36 . V_198 ( V_4 , V_197 ) ;
if ( V_5 ) {
F_3 ( & V_4 -> V_11 ,
L_38 ) ;
return - V_72 ;
}
return 0 ;
}
static int
F_52 ( struct V_146 * V_146 , void * V_147 ,
struct V_199 * V_197 )
{
struct V_63 * V_64 = V_147 ;
struct V_13 * V_14 = V_64 -> V_14 ;
struct V_3 * V_4 = V_64 -> V_2 -> V_4 ;
int V_5 ;
F_16 ( 1 , V_66 , & V_4 -> V_11 , L_39 ) ;
if ( V_14 -> V_53 ) {
F_3 ( & V_4 -> V_11 , L_26 ) ;
return - V_185 ;
}
if ( ! V_4 -> V_36 . V_200 )
return - V_72 ;
V_5 = V_4 -> V_36 . V_200 ( V_4 , V_197 ) ;
if ( V_5 ) {
F_3 ( & V_4 -> V_11 ,
L_40 ) ;
return - V_72 ;
}
V_14 -> V_201 . V_202 = 0 ;
return 0 ;
}
static int
F_53 ( struct V_146 * V_146 , void * V_147 ,
struct V_199 * V_203 )
{
struct V_63 * V_64 = V_147 ;
struct V_3 * V_4 = V_64 -> V_2 -> V_4 ;
F_16 ( 1 , V_66 , & V_4 -> V_11 , L_41 ) ;
if ( V_4 -> V_107 . V_189 &
V_204 ) {
* V_203 = V_4 -> V_107 . V_203 ;
} else {
return - V_72 ;
}
return 0 ;
}
static int F_54 ( struct V_146 * V_146 , void * V_147 ,
enum V_205 V_206 )
{
struct V_63 * V_64 = V_146 -> V_150 ;
struct V_13 * V_14 = V_64 -> V_14 ;
struct V_3 * V_4 = V_64 -> V_2 -> V_4 ;
struct V_27 * V_28 = V_64 -> V_2 -> V_28 ;
int V_5 ;
F_16 ( 1 , V_66 , & V_4 -> V_11 ,
L_42 ,
V_14 -> V_86 ) ;
if ( V_167 != V_206 ) {
F_3 ( & V_4 -> V_11 , L_43 ) ;
return - V_72 ;
}
if ( ! V_64 -> V_207 ) {
F_3 ( & V_4 -> V_11 , L_44 ) ;
return - V_208 ;
}
if ( ! V_14 -> V_53 ) {
F_3 ( & V_4 -> V_11 , L_45
L_46 , V_14 -> V_86 ) ;
return - V_72 ;
}
V_28 -> V_36 . V_209 ( V_28 ,
V_14 -> V_38 . V_39 ) ;
V_14 -> V_53 = 0 ;
V_5 = F_55 ( & V_14 -> V_210 ) ;
return V_5 ;
}
static int F_56 ( struct V_146 * V_146 , void * V_147 ,
enum V_205 V_206 )
{
struct V_63 * V_64 = V_146 -> V_150 ;
struct V_13 * V_14 = V_64 -> V_14 ;
struct V_1 * V_2 = V_64 -> V_2 ;
struct V_3 * V_4 = V_64 -> V_2 -> V_4 ;
struct V_27 * V_28 = V_2 -> V_28 ;
int V_5 ;
V_28 -> V_36 . V_209 ( V_28 ,
V_14 -> V_38 . V_39 ) ;
F_16 ( 1 , V_66 , & V_4 -> V_11 , L_47 ,
V_14 -> V_86 ) ;
if ( V_167 != V_206 ) {
F_3 ( & V_4 -> V_11 , L_43 ) ;
return - V_72 ;
}
if ( ! V_64 -> V_207 ) {
F_3 ( & V_4 -> V_11 , L_44 ) ;
return - V_208 ;
}
if ( V_14 -> V_53 ) {
F_3 ( & V_4 -> V_11 , L_48 ) ;
return - V_185 ;
}
V_5 = F_57 ( & V_14 -> V_210 ) ;
if ( V_5 ) {
F_3 ( & V_4 -> V_11 ,
L_49 ) ;
return V_5 ;
}
if ( F_9 ( & V_14 -> V_31 ) ) {
F_3 ( & V_4 -> V_11 , L_50 ) ;
goto V_211;
}
V_14 -> V_18 = V_14 -> V_17 = F_11 ( V_14 -> V_31 . V_32 ,
struct V_33 , V_34 ) ;
F_12 ( & V_14 -> V_17 -> V_34 ) ;
V_14 -> V_17 -> V_24 = V_35 ;
V_14 -> V_58 = 0 ;
V_5 = F_27 ( V_2 , V_14 ) ;
if ( V_5 < 0 )
goto V_211;
V_14 -> V_53 = 1 ;
V_14 -> V_54 = 1 ;
return V_5 ;
V_211:
V_5 = F_55 ( & V_14 -> V_210 ) ;
return V_5 ;
}
static int F_58 ( struct V_146 * V_146 , void * V_147 ,
struct V_212 * V_213 )
{
struct V_63 * V_64 = V_146 -> V_150 ;
struct V_13 * V_14 = V_64 -> V_14 ;
struct V_3 * V_4 = V_64 -> V_2 -> V_4 ;
int V_5 ;
F_16 ( 1 , V_66 , & V_4 -> V_11 ,
L_51 ,
V_14 -> V_86 ) ;
if ( V_167 != V_213 -> type ) {
F_3 ( & V_4 -> V_11 , L_43 ) ;
return - V_72 ;
}
if ( ! V_64 -> V_207 ) {
F_3 ( & V_4 -> V_11 , L_44 ) ;
return - V_208 ;
}
if ( V_146 -> V_214 & V_215 )
V_5 = F_59 ( & V_14 -> V_210 , V_213 , 1 ) ;
else
V_5 = F_59 ( & V_14 -> V_210 , V_213 , 0 ) ;
return V_5 ;
}
static int F_60 ( struct V_146 * V_146 , void * V_147 ,
struct V_212 * V_149 )
{
struct V_63 * V_64 = V_146 -> V_150 ;
struct V_13 * V_14 = V_64 -> V_14 ;
struct V_3 * V_4 = V_64 -> V_2 -> V_4 ;
F_16 ( 1 , V_66 , & V_4 -> V_11 ,
L_52 ,
V_14 -> V_86 ) ;
if ( V_167 != V_149 -> type ) {
F_3 ( & V_4 -> V_11 , L_43 ) ;
return - V_72 ;
}
if ( ! V_64 -> V_207 ) {
F_3 ( & V_4 -> V_11 , L_44 ) ;
return - V_208 ;
}
return F_61 ( & V_14 -> V_210 , V_149 ) ;
}
static int F_62 ( struct V_146 * V_146 , void * V_147 ,
struct V_212 * V_213 )
{
struct V_63 * V_64 = V_146 -> V_150 ;
struct V_13 * V_14 = V_64 -> V_14 ;
struct V_3 * V_4 = V_64 -> V_2 -> V_4 ;
int V_5 ;
F_16 ( 1 , V_66 , & V_4 -> V_11 ,
L_53 ,
V_14 -> V_86 ) ;
if ( V_167 != V_213 -> type ) {
F_3 ( & V_4 -> V_11 , L_43 ) ;
return - V_72 ;
}
V_5 = F_63 ( & V_14 -> V_210 , V_213 ) ;
return V_5 ;
}
static int F_64 ( struct V_146 * V_146 , void * V_147 ,
struct V_216 * V_217 )
{
struct V_63 * V_64 = V_146 -> V_150 ;
struct V_13 * V_14 = V_64 -> V_14 ;
struct V_3 * V_4 = V_64 -> V_2 -> V_4 ;
int V_5 ;
F_16 ( 1 , V_66 , & V_4 -> V_11 , L_54 ) ;
if ( V_167 != V_217 -> type ) {
F_3 ( & V_4 -> V_11 , L_43 ) ;
return - V_72 ;
}
if ( 0 != V_14 -> V_218 ) {
F_3 ( & V_4 -> V_11 , L_55 ) ;
return - V_185 ;
}
F_65 ( & V_14 -> V_210 ,
& V_219 ,
V_4 -> V_220 ,
& V_14 -> V_221 ,
V_167 ,
V_14 -> V_56 . V_57 ,
sizeof( struct V_33 ) ,
V_64 , NULL ) ;
V_64 -> V_207 = 1 ;
V_14 -> V_218 = 1 ;
V_14 -> V_82 = V_217 -> V_82 ;
F_66 ( & V_14 -> V_31 ) ;
V_5 = F_67 ( & V_14 -> V_210 , V_217 ) ;
return V_5 ;
}
static int F_68 ( struct V_146 * V_222 , struct V_223 * V_224 )
{
struct V_63 * V_64 = V_222 -> V_150 ;
struct V_13 * V_14 = V_64 -> V_14 ;
struct V_3 * V_4 = V_64 -> V_2 -> V_4 ;
int V_5 ;
F_16 ( 1 , V_66 , & V_4 -> V_11 , L_56 ) ;
if ( F_69 ( & V_14 -> V_225 ) )
return - V_226 ;
V_5 = F_70 ( & V_14 -> V_210 , V_224 ) ;
F_71 ( & V_14 -> V_225 ) ;
return V_5 ;
}
static unsigned int F_72 ( struct V_146 * V_222 , T_3 * V_227 )
{
struct V_63 * V_64 = V_222 -> V_150 ;
struct V_13 * V_14 = V_64 -> V_14 ;
struct V_3 * V_4 = V_64 -> V_2 -> V_4 ;
unsigned int V_228 = 0 ;
F_16 ( 1 , V_66 , & V_4 -> V_11 , L_57 ) ;
if ( V_14 -> V_53 ) {
F_73 ( & V_14 -> V_225 ) ;
V_228 = F_74 ( V_222 , & V_14 -> V_210 , V_227 ) ;
F_71 ( & V_14 -> V_225 ) ;
}
return V_228 ;
}
static int F_75 ( struct V_146 * V_146 )
{
struct V_63 * V_64 = NULL ;
struct V_13 * V_14 = F_76 ( V_146 ) ;
struct V_1 * V_2 = V_14 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_27 * V_28 = V_2 -> V_28 ;
int V_228 ;
V_64 = F_77 ( sizeof( struct V_63 ) , V_229 ) ;
if ( V_64 == NULL ) {
F_3 ( & V_4 -> V_11 ,
L_58 ) ;
return - V_230 ;
}
F_16 ( 1 , V_66 , & V_4 -> V_11 ,
L_59 ,
V_14 -> V_86 ) ;
V_146 -> V_150 = V_64 ;
V_64 -> V_14 = V_14 ;
V_64 -> V_2 = V_2 ;
if ( ! V_14 -> V_231 ) {
if ( F_69 ( & V_14 -> V_225 ) )
return - V_226 ;
V_228 = V_28 -> V_36 . V_232 ( V_28 ,
V_14 -> V_38 . V_39 ) ;
F_71 ( & V_14 -> V_225 ) ;
if ( V_228 < 0 ) {
F_3 ( & V_4 -> V_11 ,
L_60 ) ;
F_78 ( V_64 ) ;
return - V_72 ;
}
}
V_14 -> V_231 ++ ;
V_64 -> V_207 = 0 ;
V_64 -> V_151 = V_233 ;
F_79 ( & V_14 -> V_151 , & V_64 -> V_151 ) ;
F_16 ( 1 , V_66 , & V_4 -> V_11 ,
L_61 ) ;
return 0 ;
}
static int F_80 ( struct V_146 * V_146 )
{
struct V_63 * V_64 = V_146 -> V_150 ;
struct V_13 * V_14 = V_64 -> V_14 ;
struct V_89 * V_90 = & V_14 -> V_38 . V_91 ;
struct V_1 * V_2 = V_64 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_27 * V_28 = V_2 -> V_28 ;
F_16 ( 1 , V_66 , & V_4 -> V_11 , L_62 ) ;
F_73 ( & V_14 -> V_225 ) ;
if ( V_64 -> V_207 ) {
V_14 -> V_218 = 0 ;
V_28 -> V_36 . V_209 ( V_28 ,
V_14 -> V_38 . V_39 ) ;
V_14 -> V_53 = 0 ;
F_81 ( & V_14 -> V_210 ) ;
F_82 ( & V_14 -> V_210 ) ;
}
V_14 -> V_231 -- ;
if ( ! V_14 -> V_231 ) {
if ( V_90 -> V_94 == V_95 ) {
struct V_13 * V_96 ;
V_96 =
F_26 ( V_2 , V_14 ) ;
V_28 -> V_36 . V_209 ( V_28 ,
V_96 -> V_38 . V_39 ) ;
V_28 -> V_36 . V_234 ( V_28 ,
V_96 -> V_38 . V_39 ) ;
}
V_28 -> V_36 . V_209 ( V_28 ,
V_14 -> V_38 . V_39 ) ;
V_28 -> V_36 . V_234 ( V_28 ,
V_14 -> V_38 . V_39 ) ;
}
F_83 ( & V_14 -> V_151 , V_64 -> V_151 ) ;
V_146 -> V_150 = NULL ;
F_71 ( & V_14 -> V_225 ) ;
F_78 ( V_64 ) ;
V_2 -> V_40 = 0 ;
return 0 ;
}
static int F_84 ( struct V_146 * V_146 , void * V_147 ,
struct V_235 * V_236 )
{
struct V_237 * V_238 = & V_236 -> V_238 ;
struct V_63 * V_64 = V_146 -> V_150 ;
struct V_3 * V_4 = V_64 -> V_2 -> V_4 ;
if ( V_238 -> type >= 2 ) {
F_2 ( V_4 -> V_7 ,
V_8 ,
V_239 ,
V_236 ) ;
}
return 0 ;
}
static int F_85 ( struct V_146 * V_146 , void * V_147 ,
struct V_235 * V_236 )
{
return 0 ;
}
static int F_86 ( struct V_240 * V_47 , void * V_241 )
{
struct V_242 * V_220 = F_87 ( V_47 ) ;
struct V_1 * V_243 = V_241 ;
if ( strcmp ( L_63 , V_220 -> V_244 ) == 0 )
V_243 -> V_4 = F_88 ( V_220 ) ;
if ( strcmp ( L_64 , V_220 -> V_244 ) == 0 )
V_243 -> V_28 = F_88 ( V_220 ) ;
return 0 ;
}
static T_4 int F_89 ( int V_46 , struct V_1 * V_2 ,
struct V_242 * V_220 )
{
struct V_13 * V_245 = NULL ;
struct V_246 * V_247 = NULL ;
V_2 -> V_47 [ V_46 ] =
F_90 ( sizeof( struct V_13 ) , V_229 ) ;
if ( ! V_2 -> V_47 [ V_46 ] ) {
F_91 ( V_248 L_65 ) ;
return - V_230 ;
}
F_92 ( & V_2 -> V_47 [ V_46 ] -> V_221 ) ;
F_93 ( & V_2 -> V_47 [ V_46 ] -> V_225 ) ;
V_245 = V_2 -> V_47 [ V_46 ] ;
V_247 = & V_245 -> V_201 ;
V_247 -> V_249 = V_250 ;
V_247 -> V_251 = & V_252 ;
V_247 -> V_253 = & V_254 ;
V_247 -> V_255 = - 1 ;
V_247 -> V_11 = & V_2 -> V_4 -> V_11 ;
V_247 -> V_256 = & V_245 -> V_225 ;
V_247 -> V_257 = V_258 ;
if ( V_2 -> V_4 -> V_107 . V_189 &
V_190 ) {
V_247 -> V_259 = ( V_117 | V_118 ) ;
V_247 -> V_202 =
V_2 -> V_4 -> V_107 . V_108 ;
} else
V_247 -> V_202 = 0 ;
snprintf ( V_247 -> V_244 , sizeof( V_247 -> V_244 ) ,
L_66 ,
( V_155 >> 16 ) & 0xff ,
( V_155 >> 8 ) & 0xff ,
( V_155 ) & 0xff ) ;
V_245 -> V_86 = V_46 ;
V_245 -> V_38 . V_39 =
( ( V_46 == V_87 ) ? V_260 : V_261 ) ;
F_94 ( & V_245 -> V_151 ) ;
return 0 ;
}
static T_4 int F_95 ( struct V_13 * V_245 ,
struct V_1 * V_2 ,
struct V_242 * V_220 ) {
int V_228 ;
F_96 ( & V_2 -> V_4 -> V_11 ,
L_67 ) ;
F_96 ( & V_2 -> V_4 -> V_11 ,
L_68 ,
( int ) V_245 ,
( int ) & V_245 -> V_201 ) ;
V_228 = F_97 ( & V_245 -> V_201 ,
V_262 ,
- 1 ) ;
if ( V_228 )
return - V_263 ;
V_245 -> V_2 = V_2 ;
F_98 ( V_220 , V_2 ) ;
F_99 ( & V_245 -> V_201 ,
V_245 ) ;
return 0 ;
}
static T_4 int F_100 ( struct V_242 * V_220 )
{
struct V_13 * V_245 ;
struct V_1 * V_2 ;
struct V_264 * V_265 = NULL ;
int V_266 ;
int V_46 ;
int V_228 ;
int V_41 ;
F_91 ( V_267 L_69 ) ;
V_2 = F_90 ( sizeof( struct V_1 ) , V_229 ) ;
if ( ! V_2 ) {
F_91 ( V_248 L_65 ) ;
return - V_230 ;
}
F_92 ( & V_2 -> V_30 ) ;
V_228 = F_101 ( & V_268 , NULL , V_2 ,
F_86 ) ;
if ( V_228 < 0 )
return V_228 ;
if ( NULL != V_2 -> V_4 -> V_36 . V_269 ) {
V_228 = V_2 -> V_4 -> V_36 . V_269 ( & V_220 -> V_47 ,
V_2 -> V_4 ) ;
if ( V_228 ) {
F_3 ( & V_2 -> V_4 -> V_11 ,
L_70 ) ;
V_228 = - V_230 ;
goto V_270;
}
}
for ( V_46 = 0 ; V_46 < V_52 ; V_46 ++ ) {
if ( F_89 ( V_46 , V_2 , V_220 ) ) {
V_228 = - V_263 ;
goto V_270;
}
}
V_265 = F_102 ( V_220 , V_271 , 0 ) ;
if ( ! V_265 ) {
F_3 ( & V_2 -> V_4 -> V_11 ,
L_71 ) ;
V_228 = - V_263 ;
goto V_270;
}
V_41 = V_265 -> V_272 ;
if ( F_103 ( V_41 , F_14 , V_273 , V_160 ,
V_2 ) ) {
F_3 ( & V_2 -> V_4 -> V_11 ,
L_72 ) ;
V_228 = - V_263 ;
goto V_270;
}
for ( V_46 = 0 ; V_46 < V_52 ; V_46 ++ ) {
if ( F_95 ( V_2 -> V_47 [ V_46 ] , V_2 , V_220 ) ) {
V_228 = - V_263 ;
goto V_274;
}
}
F_91 ( V_267 L_73 ) ;
return 0 ;
V_274:
F_104 ( V_265 -> V_272 , V_2 ) ;
V_270:
for ( V_266 = 0 ; V_266 < V_52 ; V_266 ++ ) {
V_245 = V_2 -> V_47 [ V_266 ] ;
if ( V_245 ) {
F_105 (
& V_245 -> V_201 ) ;
F_78 ( V_2 -> V_47 [ V_266 ] ) ;
}
}
F_78 ( V_2 ) ;
return V_228 ;
}
static int F_106 ( struct V_242 * V_220 )
{
struct V_13 * V_245 ;
struct V_1 * V_2 = F_88 ( V_220 ) ;
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_264 * V_265 ;
int V_46 ;
F_16 ( 1 , V_66 , & V_4 -> V_11 , L_74 ) ;
V_265 = F_102 ( V_220 , V_271 , 0 ) ;
F_104 ( V_265 -> V_272 , V_2 ) ;
if ( NULL != V_4 -> V_36 . V_275 )
V_4 -> V_36 . V_275 ( & V_220 -> V_47 , V_4 ) ;
for ( V_46 = 0 ; V_46 < V_52 ; V_46 ++ ) {
V_245 = V_2 -> V_47 [ V_46 ] ;
F_105 ( & V_245 -> V_201 ) ;
}
for ( V_46 = 0 ; V_46 < V_52 ; V_46 ++ ) {
F_78 ( V_2 -> V_47 [ V_46 ] ) ;
V_2 -> V_47 [ V_46 ] = NULL ;
}
return 0 ;
}
