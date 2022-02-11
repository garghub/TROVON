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
T_2 V_106 = V_4 -> V_107 . V_108 . V_109 ;
V_90 -> V_110 = V_94 -> V_68 ;
V_90 -> V_111 = V_94 -> V_69 ;
V_38 -> V_112 = V_113 ;
V_38 -> V_114 = V_113 ;
V_38 -> V_102 = V_115 ;
V_38 -> V_103 = V_116 ;
if ( V_94 -> V_68 < V_97 ) {
V_104 = V_4 -> V_107 . V_117 / V_94 -> V_68 ;
if ( V_104 < 2 )
V_104 = 1 ;
else if ( V_104 >= 4 )
V_104 = 4 ;
else
V_104 = 2 ;
V_90 -> V_110 *= V_104 ;
if ( V_90 -> V_110 < V_97 ) {
if ( ( V_106 & V_118 ) ||
( V_106 & V_119 ) ) {
V_101 = ( V_90 -> V_110 *
V_120 ) /
V_121 ;
if ( V_101 <= V_97 ) {
V_102 = 1 ;
V_90 -> V_110 = V_101 ;
}
}
}
if ( V_104 == 2 )
V_38 -> V_112 = V_122 ;
else if ( V_104 == 4 )
V_38 -> V_112 = V_123 ;
if ( V_102 )
V_38 -> V_102 = V_124 ;
} else {
V_90 -> V_110 = V_97 ;
}
if ( V_94 -> V_69 < V_98 ) {
V_105 = V_98 / V_94 -> V_69 ;
if ( V_105 < 2 )
V_105 = 1 ;
else if ( V_105 >= 4 )
V_105 = 4 ;
else
V_105 = 2 ;
V_90 -> V_111 *= V_105 ;
if ( V_90 -> V_111 < V_98 ) {
if ( ( V_106 & V_119 ) ) {
V_101 = ( V_90 -> V_111 *
V_125 ) /
V_126 ;
if ( V_101 <= V_98 ) {
V_103 = 1 ;
V_90 -> V_111 = V_101 ;
}
}
}
if ( V_105 == 2 )
V_38 -> V_114 = V_122 ;
else if ( V_105 == 4 )
V_38 -> V_114 = V_123 ;
if ( V_103 )
V_38 -> V_102 = V_127 ;
} else {
V_90 -> V_111 = V_98 ;
}
F_16 ( 1 , V_66 , & V_4 -> V_11 ,
L_10 ,
V_90 -> V_110 , V_90 -> V_111 ) ;
}
static void F_29 ( struct V_1 * V_2 ,
struct V_13 * V_14 ,
int V_128 , int V_129 )
{
struct V_89 * V_90 = & V_14 -> V_38 . V_91 ;
struct V_3 * V_4 = V_2 -> V_4 ;
V_90 -> V_130 = F_30 ( ( unsigned int ) V_129 ,
V_4 -> V_107 . V_117 - V_90 -> V_110 ) ;
V_90 -> V_131 = F_30 ( ( unsigned int ) V_128 ,
V_4 -> V_107 . V_132 - V_90 -> V_111 ) ;
F_16 ( 1 , V_66 , & V_4 -> V_11 ,
L_11 ,
V_90 -> V_130 , V_90 -> V_131 ) ;
}
static void F_31 ( struct V_1 * V_2 ,
struct V_133 * V_134 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
if ( ( V_134 -> V_68 == 0 ) ||
( ( V_134 -> V_68 + V_134 -> V_129 ) > V_4 -> V_107 . V_117 ) )
V_134 -> V_68 = V_4 -> V_107 . V_117 - V_134 -> V_129 ;
if ( ( V_134 -> V_69 == 0 ) || ( ( V_134 -> V_69 + V_134 -> V_128 ) >
V_4 -> V_107 . V_132 ) )
V_134 -> V_69 = V_4 -> V_107 . V_132 - V_134 -> V_128 ;
if ( V_4 -> V_107 . V_135 )
V_134 -> V_69 &= ( ~ 0x01 ) ;
}
static int F_32 ( struct V_1 * V_2 ,
struct V_100 * V_94 , int V_136 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
int V_137 = 1 ;
int V_138 = 32 ;
int V_139 ;
int V_140 ;
int V_141 ;
if ( ( V_94 -> V_142 != V_143 ) &&
( V_94 -> V_142 != V_144 ) )
V_94 -> V_142 = V_143 ;
if ( ( V_94 -> V_57 != V_145 ) &&
( V_94 -> V_57 != V_55 ) ) {
if ( V_4 -> V_107 . V_135 )
V_94 -> V_57 = V_145 ;
else
V_94 -> V_57 = V_55 ;
}
if ( V_94 -> V_57 == V_145 )
V_137 = 2 ;
if ( V_94 -> V_142 == V_144 )
V_141 = 1 ;
else
V_141 = 2 ;
V_140 = V_4 -> V_107 . V_117 ;
V_139 = V_4 -> V_107 . V_132 ;
V_138 /= V_141 ;
if ( ! V_94 -> V_68 || ( V_94 -> V_68 < V_138 ) ||
( V_94 -> V_68 > V_140 ) ) {
V_94 -> V_68 = V_4 -> V_107 . V_117 ;
}
if ( ! V_94 -> V_69 || ( V_94 -> V_69 < V_137 ) ||
( V_94 -> V_69 > V_139 ) ) {
V_94 -> V_69 = V_4 -> V_107 . V_132 ;
}
if ( V_94 -> V_146 < ( V_94 -> V_68 * V_141 ) )
V_94 -> V_146 = V_94 -> V_68 * V_141 ;
V_94 -> V_146 = ( ( V_94 -> V_68 * V_141 + 31 ) & ~ 31 ) ;
if ( V_94 -> V_142 == V_144 )
V_94 -> V_71 = V_94 -> V_146 * V_94 -> V_69 +
( V_94 -> V_146 * V_94 -> V_69 >> 1 ) ;
else
V_94 -> V_71 = V_94 -> V_146 * V_94 -> V_69 ;
return 0 ;
}
static int F_33 ( struct V_147 * V_147 , void * V_148 ,
enum V_149 * V_150 )
{
struct V_63 * V_64 = V_147 -> V_151 ;
struct V_13 * V_14 = V_64 -> V_14 ;
* V_150 = F_34 ( & V_14 -> V_152 ) ;
return 0 ;
}
static int F_35 ( struct V_147 * V_147 , void * V_148 ,
enum V_149 V_150 )
{
struct V_63 * V_64 = V_147 -> V_151 ;
struct V_13 * V_14 = V_64 -> V_14 ;
int V_5 ;
V_5 = F_36 ( & V_14 -> V_152 , & V_64 -> V_152 , V_150 ) ;
return V_5 ;
}
static int F_37 ( struct V_147 * V_147 , void * V_148 ,
struct V_153 * V_154 )
{
struct V_63 * V_64 = V_147 -> V_151 ;
struct V_3 * V_4 = V_64 -> V_2 -> V_4 ;
V_154 -> V_155 = V_156 ;
V_154 -> V_157 = V_158 | V_159 ;
F_38 ( V_154 -> V_160 , V_161 , sizeof( V_154 -> V_160 ) ) ;
F_38 ( V_154 -> V_162 , L_12 , sizeof( V_154 -> V_162 ) ) ;
F_38 ( V_154 -> V_163 , V_4 -> V_90 -> V_164 , sizeof( V_154 -> V_163 ) ) ;
return 0 ;
}
static int F_39 ( struct V_147 * V_147 , void * V_148 ,
struct V_165 * V_166 )
{
struct V_63 * V_64 = V_147 -> V_151 ;
struct V_13 * V_14 = V_64 -> V_14 ;
struct V_1 * V_2 = V_64 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_89 * V_90 = & V_14 -> V_38 . V_91 ;
struct V_27 * V_28 = V_2 -> V_28 ;
struct V_133 * V_167 = & V_166 -> V_134 ;
int V_5 ;
F_16 ( 1 , V_66 , & V_4 -> V_11 ,
L_13 , V_14 -> V_86 ) ;
if ( V_166 -> type != V_168 ) {
F_3 ( & V_4 -> V_11 , L_14 ) ;
return - V_72 ;
}
if ( V_167 -> V_128 < 0 )
V_167 -> V_128 = 0 ;
if ( V_167 -> V_129 < 0 )
V_167 -> V_129 = 0 ;
F_31 ( V_2 , V_167 ) ;
V_28 -> V_36 . V_169 ( V_28 ,
V_14 -> V_38 . V_39 , V_90 ) ;
F_28 ( V_2 , V_14 ,
V_167 -> V_68 ,
V_167 -> V_69 ) ;
F_29 ( V_2 , V_14 , V_167 -> V_128 ,
V_167 -> V_129 ) ;
V_5 = V_28 -> V_36 . V_170 ( V_28 ,
V_14 -> V_38 . V_39 , V_90 ) ;
if ( V_5 < 0 ) {
F_3 ( & V_4 -> V_11 ,
L_15 ) ;
return - V_72 ;
}
V_28 -> V_36 . V_171 ( V_28 ,
V_14 -> V_38 . V_39 ,
V_14 -> V_38 . V_112 ,
V_14 -> V_38 . V_114 ) ;
V_5 = V_28 -> V_36 . V_172 ( V_28 ,
V_14 -> V_38 . V_102 ,
V_14 -> V_38 . V_103 ) ;
if ( V_5 < 0 ) {
F_3 ( & V_4 -> V_11 ,
L_16 ) ;
return - V_72 ;
}
if ( ( V_14 -> V_38 . V_112 != V_113 ) ||
( V_14 -> V_38 . V_114 != V_113 ) ||
( V_14 -> V_38 . V_102 != V_115 ) ||
( V_14 -> V_38 . V_103 != V_116 ) )
V_28 -> V_36 . V_173 ( V_28 , 1 ) ;
else
V_28 -> V_36 . V_173 ( V_28 , 0 ) ;
return 0 ;
}
static int F_40 ( struct V_147 * V_147 , void * V_148 ,
struct V_165 * V_166 )
{
struct V_63 * V_64 = V_147 -> V_151 ;
struct V_13 * V_14 = V_64 -> V_14 ;
struct V_89 * V_90 = & V_14 -> V_38 . V_91 ;
struct V_3 * V_4 = V_64 -> V_2 -> V_4 ;
struct V_27 * V_28 = V_64 -> V_2 -> V_28 ;
struct V_133 * V_167 = & V_166 -> V_134 ;
int V_5 ;
F_16 ( 1 , V_66 , & V_4 -> V_11 ,
L_17 ,
V_14 -> V_86 ) ;
if ( V_166 -> type != V_168 ) {
F_3 ( & V_4 -> V_11 , L_14 ) ;
V_5 = - V_72 ;
}
V_28 -> V_36 . V_169 ( V_28 ,
V_14 -> V_38 . V_39 , V_90 ) ;
V_167 -> V_128 = V_90 -> V_131 ;
V_167 -> V_129 = V_90 -> V_130 ;
V_167 -> V_68 = V_90 -> V_110 ;
V_167 -> V_69 = V_90 -> V_111 ;
return 0 ;
}
static int F_41 ( struct V_147 * V_147 , void * V_148 ,
struct V_174 * V_175 )
{
struct V_63 * V_64 = V_147 -> V_151 ;
struct V_3 * V_4 = V_64 -> V_2 -> V_4 ;
F_16 ( 1 , V_66 , & V_4 -> V_11 , L_18 ) ;
V_175 -> type = V_168 ;
V_175 -> V_176 . V_129 = 0 ;
V_175 -> V_176 . V_128 = 0 ;
V_175 -> V_176 . V_68 = V_4 -> V_107 . V_117 ;
V_175 -> V_176 . V_69 = V_4 -> V_107 . V_132 ;
V_175 -> V_177 = V_4 -> V_107 . V_178 ;
V_175 -> V_179 = V_175 -> V_176 ;
return 0 ;
}
static int F_42 ( struct V_147 * V_147 , void * V_148 ,
struct V_180 * V_181 )
{
struct V_63 * V_64 = V_147 -> V_151 ;
struct V_13 * V_14 = V_64 -> V_14 ;
struct V_3 * V_4 = V_64 -> V_2 -> V_4 ;
F_16 ( 1 , V_66 , & V_4 -> V_11 ,
L_19 ,
V_14 -> V_86 ) ;
if ( V_168 != V_181 -> type ) {
F_3 ( & V_4 -> V_11 , L_20 ) ;
return - V_72 ;
}
V_181 -> V_181 . V_182 = V_14 -> V_56 ;
return 0 ;
}
static int F_43 ( struct V_147 * V_147 , void * V_148 ,
struct V_183 * V_181 )
{
struct V_63 * V_64 = V_147 -> V_151 ;
struct V_13 * V_14 = V_64 -> V_14 ;
struct V_3 * V_4 = V_64 -> V_2 -> V_4 ;
unsigned int V_184 = 0 ;
F_16 ( 1 , V_66 , & V_4 -> V_11 ,
L_21 ,
V_14 -> V_86 ) ;
if ( V_181 -> V_184 > 1 ) {
F_3 ( & V_4 -> V_11 , L_22 ) ;
return - V_72 ;
}
V_184 = V_181 -> V_184 ;
memset ( V_181 , 0 , sizeof( * V_181 ) ) ;
V_181 -> V_184 = V_184 ;
V_181 -> type = V_168 ;
if ( V_184 == 0 ) {
strcpy ( V_181 -> V_185 , L_23 ) ;
V_181 -> V_142 = V_143 ;
} else {
strcpy ( V_181 -> V_185 , L_24 ) ;
V_181 -> V_142 = V_144 ;
}
return 0 ;
}
static int F_44 ( struct V_147 * V_147 , void * V_148 ,
struct V_180 * V_181 )
{
struct V_63 * V_64 = V_147 -> V_151 ;
struct V_13 * V_14 = V_64 -> V_14 ;
struct V_1 * V_2 = V_64 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_89 * V_90 = & V_14 -> V_38 . V_91 ;
struct V_100 * V_94 = & V_181 -> V_181 . V_182 ;
struct V_27 * V_28 = V_2 -> V_28 ;
int V_5 ;
F_16 ( 1 , V_66 , & V_4 -> V_11 ,
L_25 ,
V_14 -> V_86 ) ;
if ( V_14 -> V_53 ) {
F_3 ( & V_4 -> V_11 , L_26 ) ;
return - V_186 ;
}
if ( V_168 != V_181 -> type ) {
F_16 ( 1 , V_66 , & V_4 -> V_11 , L_20 ) ;
return - V_72 ;
}
V_5 = F_32 ( V_2 , V_94 , 1 ) ;
if ( V_5 )
return V_5 ;
V_14 -> V_56 = * V_94 ;
V_28 -> V_36 . V_169 ( V_28 ,
V_14 -> V_38 . V_39 , V_90 ) ;
V_90 -> V_110 = V_94 -> V_68 ;
V_90 -> V_111 = V_94 -> V_69 ;
V_90 -> V_187 = V_94 -> V_146 ;
V_90 -> V_131 = 0 ;
V_90 -> V_130 = 0 ;
V_90 -> V_135 = V_4 -> V_107 . V_135 ;
if ( V_143 == V_94 -> V_142 )
V_90 -> V_94 = V_188 ;
if ( V_144 == V_94 -> V_142 ) {
struct V_13 * V_96 ;
V_90 -> V_94 = V_95 ;
V_96 = F_26 ( V_2 ,
V_14 ) ;
V_96 -> V_38 . V_91 . V_94 = V_95 ;
}
V_5 = V_28 -> V_36 . V_170 ( V_28 ,
V_14 -> V_38 . V_39 , V_90 ) ;
if ( V_5 < 0 ) {
F_3 ( & V_4 -> V_11 ,
L_27 ) ;
return - V_72 ;
}
V_28 -> V_36 . V_169 ( V_28 ,
V_14 -> V_38 . V_39 , V_90 ) ;
return 0 ;
}
static int F_45 ( struct V_147 * V_147 , void * V_148 ,
struct V_180 * V_181 )
{
struct V_63 * V_64 = V_147 -> V_151 ;
struct V_1 * V_2 = V_64 -> V_2 ;
struct V_3 * V_4 = V_64 -> V_2 -> V_4 ;
struct V_100 * V_94 = & V_181 -> V_181 . V_182 ;
F_16 ( 1 , V_66 , & V_4 -> V_11 , L_28 ) ;
if ( V_168 != V_181 -> type ) {
F_3 ( & V_4 -> V_11 , L_20 ) ;
return - V_72 ;
}
return F_32 ( V_2 , V_94 , 0 ) ;
}
static int F_46 ( struct V_147 * V_147 , void * V_148 ,
T_2 * V_109 )
{
struct V_63 * V_64 = V_148 ;
struct V_13 * V_14 = V_64 -> V_14 ;
struct V_3 * V_4 = V_64 -> V_2 -> V_4 ;
int V_5 ;
F_16 ( 1 , V_66 , & V_4 -> V_11 , L_29 ) ;
if ( V_14 -> V_53 ) {
F_3 ( & V_4 -> V_11 , L_26 ) ;
return - V_186 ;
}
if ( NULL != V_4 -> V_36 . V_189 ) {
V_5 = V_4 -> V_36 . V_189 ( V_4 , V_109 ) ;
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
static int F_47 ( struct V_147 * V_147 , void * V_148 ,
T_2 * V_109 )
{
struct V_63 * V_64 = V_148 ;
struct V_3 * V_4 = V_64 -> V_2 -> V_4 ;
F_16 ( 1 , V_66 , & V_4 -> V_11 , L_31 ) ;
if ( V_4 -> V_107 . V_190 & V_191 ) {
* V_109 = V_4 -> V_107 . V_108 . V_109 ;
return 0 ;
}
return - V_72 ;
}
static int F_48 ( struct V_147 * V_147 , void * V_148 ,
struct V_192 * V_193 )
{
struct V_63 * V_64 = V_148 ;
struct V_3 * V_4 = V_64 -> V_2 -> V_4 ;
int V_5 ;
F_16 ( 1 , V_66 , & V_4 -> V_11 , L_32 ) ;
if ( NULL == V_4 -> V_36 . V_194 )
return - V_72 ;
V_5 = V_4 -> V_36 . V_194 ( V_4 , V_193 ) ;
if ( V_5 ) {
F_16 ( 1 , V_66 , & V_4 -> V_11 ,
L_33 ) ;
return - V_72 ;
}
return 0 ;
}
static int F_49 ( struct V_147 * V_147 , void * V_148 ,
unsigned int V_46 )
{
struct V_63 * V_64 = V_148 ;
struct V_13 * V_14 = V_64 -> V_14 ;
struct V_3 * V_4 = V_64 -> V_2 -> V_4 ;
int V_5 ;
F_16 ( 1 , V_66 , & V_4 -> V_11 , L_34 ) ;
if ( V_14 -> V_53 ) {
F_3 ( & V_4 -> V_11 , L_26 ) ;
return - V_186 ;
}
if ( NULL == V_4 -> V_36 . V_195 )
return - V_72 ;
V_5 = V_4 -> V_36 . V_195 ( V_4 , V_46 ) ;
if ( V_5 ) {
F_3 ( & V_4 -> V_11 ,
L_35 ) ;
return - V_72 ;
}
return 0 ;
}
static int F_50 ( struct V_147 * V_147 , void * V_148 ,
unsigned int * V_46 )
{
struct V_63 * V_64 = V_148 ;
struct V_3 * V_4 = V_64 -> V_2 -> V_4 ;
F_16 ( 1 , V_66 , & V_4 -> V_11 , L_36 ) ;
* V_46 = V_4 -> V_196 ;
return 0 ;
}
static int
F_51 ( struct V_147 * V_147 , void * V_148 ,
struct V_197 * V_198 )
{
struct V_63 * V_64 = V_148 ;
struct V_3 * V_4 = V_64 -> V_2 -> V_4 ;
int V_5 ;
F_16 ( 1 , V_66 , & V_4 -> V_11 , L_37 ) ;
if ( NULL == V_4 -> V_36 . V_199 )
return - V_72 ;
V_5 = V_4 -> V_36 . V_199 ( V_4 , V_198 ) ;
if ( V_5 ) {
F_3 ( & V_4 -> V_11 ,
L_38 ) ;
return - V_72 ;
}
return 0 ;
}
static int
F_52 ( struct V_147 * V_147 , void * V_148 ,
struct V_200 * V_198 )
{
struct V_63 * V_64 = V_148 ;
struct V_13 * V_14 = V_64 -> V_14 ;
struct V_3 * V_4 = V_64 -> V_2 -> V_4 ;
int V_5 ;
F_16 ( 1 , V_66 , & V_4 -> V_11 , L_39 ) ;
if ( V_14 -> V_53 ) {
F_3 ( & V_4 -> V_11 , L_26 ) ;
return - V_186 ;
}
if ( NULL != V_4 -> V_36 . V_201 )
return - V_72 ;
V_5 = V_4 -> V_36 . V_201 ( V_4 , V_198 ) ;
if ( V_5 ) {
F_3 ( & V_4 -> V_11 ,
L_40 ) ;
return - V_72 ;
}
V_14 -> V_202 . V_203 = 0 ;
return 0 ;
}
static int
F_53 ( struct V_147 * V_147 , void * V_148 ,
struct V_200 * V_204 )
{
struct V_63 * V_64 = V_148 ;
struct V_3 * V_4 = V_64 -> V_2 -> V_4 ;
F_16 ( 1 , V_66 , & V_4 -> V_11 , L_41 ) ;
if ( V_4 -> V_107 . V_190 &
V_205 ) {
V_204 -> V_198 =
V_4 -> V_107 . V_108 . V_204 ;
} else {
return - V_72 ;
}
return 0 ;
}
static int F_54 ( struct V_147 * V_147 , void * V_148 ,
enum V_206 V_207 )
{
struct V_63 * V_64 = V_147 -> V_151 ;
struct V_13 * V_14 = V_64 -> V_14 ;
struct V_3 * V_4 = V_64 -> V_2 -> V_4 ;
struct V_27 * V_28 = V_64 -> V_2 -> V_28 ;
int V_5 ;
F_16 ( 1 , V_66 , & V_4 -> V_11 ,
L_42 ,
V_14 -> V_86 ) ;
if ( V_168 != V_207 ) {
F_3 ( & V_4 -> V_11 , L_43 ) ;
return - V_72 ;
}
if ( ! V_64 -> V_208 ) {
F_3 ( & V_4 -> V_11 , L_44 ) ;
return - V_209 ;
}
if ( ! V_14 -> V_53 ) {
F_3 ( & V_4 -> V_11 , L_45
L_46 , V_14 -> V_86 ) ;
return - V_72 ;
}
V_28 -> V_36 . V_210 ( V_28 ,
V_14 -> V_38 . V_39 ) ;
V_14 -> V_53 = 0 ;
V_5 = F_55 ( & V_14 -> V_211 ) ;
return V_5 ;
}
static int F_56 ( struct V_147 * V_147 , void * V_148 ,
enum V_206 V_207 )
{
struct V_63 * V_64 = V_147 -> V_151 ;
struct V_13 * V_14 = V_64 -> V_14 ;
struct V_1 * V_2 = V_64 -> V_2 ;
struct V_3 * V_4 = V_64 -> V_2 -> V_4 ;
struct V_27 * V_28 = V_2 -> V_28 ;
int V_5 ;
V_28 -> V_36 . V_210 ( V_28 ,
V_14 -> V_38 . V_39 ) ;
F_16 ( 1 , V_66 , & V_4 -> V_11 , L_47 ,
V_14 -> V_86 ) ;
if ( V_168 != V_207 ) {
F_3 ( & V_4 -> V_11 , L_43 ) ;
return - V_72 ;
}
if ( ! V_64 -> V_208 ) {
F_3 ( & V_4 -> V_11 , L_44 ) ;
return - V_209 ;
}
if ( V_14 -> V_53 ) {
F_3 ( & V_4 -> V_11 , L_48 ) ;
return - V_186 ;
}
V_5 = F_57 ( & V_14 -> V_211 ) ;
if ( V_5 ) {
F_3 ( & V_4 -> V_11 ,
L_49 ) ;
return V_5 ;
}
if ( F_9 ( & V_14 -> V_31 ) ) {
F_3 ( & V_4 -> V_11 , L_50 ) ;
goto V_212;
}
V_14 -> V_18 = V_14 -> V_17 = F_11 ( V_14 -> V_31 . V_32 ,
struct V_33 , V_34 ) ;
F_12 ( & V_14 -> V_17 -> V_34 ) ;
V_14 -> V_17 -> V_24 = V_35 ;
V_14 -> V_58 = 0 ;
V_5 = F_27 ( V_2 , V_14 ) ;
if ( V_5 < 0 )
goto V_212;
V_14 -> V_53 = 1 ;
V_14 -> V_54 = 1 ;
return V_5 ;
V_212:
V_5 = F_55 ( & V_14 -> V_211 ) ;
return V_5 ;
}
static int F_58 ( struct V_147 * V_147 , void * V_148 ,
struct V_213 * V_214 )
{
struct V_63 * V_64 = V_147 -> V_151 ;
struct V_13 * V_14 = V_64 -> V_14 ;
struct V_3 * V_4 = V_64 -> V_2 -> V_4 ;
int V_5 ;
F_16 ( 1 , V_66 , & V_4 -> V_11 ,
L_51 ,
V_14 -> V_86 ) ;
if ( V_168 != V_214 -> type ) {
F_3 ( & V_4 -> V_11 , L_43 ) ;
return - V_72 ;
}
if ( ! V_64 -> V_208 ) {
F_3 ( & V_4 -> V_11 , L_44 ) ;
return - V_209 ;
}
if ( V_147 -> V_215 & V_216 )
V_5 = F_59 ( & V_14 -> V_211 , V_214 , 1 ) ;
else
V_5 = F_59 ( & V_14 -> V_211 , V_214 , 0 ) ;
return V_5 ;
}
static int F_60 ( struct V_147 * V_147 , void * V_148 ,
struct V_213 * V_150 )
{
struct V_63 * V_64 = V_147 -> V_151 ;
struct V_13 * V_14 = V_64 -> V_14 ;
struct V_3 * V_4 = V_64 -> V_2 -> V_4 ;
F_16 ( 1 , V_66 , & V_4 -> V_11 ,
L_52 ,
V_14 -> V_86 ) ;
if ( V_168 != V_150 -> type ) {
F_3 ( & V_4 -> V_11 , L_43 ) ;
return - V_72 ;
}
if ( ! V_64 -> V_208 ) {
F_3 ( & V_4 -> V_11 , L_44 ) ;
return - V_209 ;
}
return F_61 ( & V_14 -> V_211 , V_150 ) ;
}
static int F_62 ( struct V_147 * V_147 , void * V_148 ,
struct V_213 * V_214 )
{
struct V_63 * V_64 = V_147 -> V_151 ;
struct V_13 * V_14 = V_64 -> V_14 ;
struct V_3 * V_4 = V_64 -> V_2 -> V_4 ;
int V_5 ;
F_16 ( 1 , V_66 , & V_4 -> V_11 ,
L_53 ,
V_14 -> V_86 ) ;
if ( V_168 != V_214 -> type ) {
F_3 ( & V_4 -> V_11 , L_43 ) ;
return - V_72 ;
}
V_5 = F_63 ( & V_14 -> V_211 , V_214 ) ;
return V_5 ;
}
static int F_64 ( struct V_147 * V_147 , void * V_148 ,
struct V_217 * V_218 )
{
struct V_63 * V_64 = V_147 -> V_151 ;
struct V_13 * V_14 = V_64 -> V_14 ;
struct V_3 * V_4 = V_64 -> V_2 -> V_4 ;
int V_5 ;
F_16 ( 1 , V_66 , & V_4 -> V_11 , L_54 ) ;
if ( V_168 != V_218 -> type ) {
F_3 ( & V_4 -> V_11 , L_43 ) ;
return - V_72 ;
}
if ( 0 != V_14 -> V_219 ) {
F_3 ( & V_4 -> V_11 , L_55 ) ;
return - V_186 ;
}
F_65 ( & V_14 -> V_211 ,
& V_220 ,
V_4 -> V_221 ,
& V_14 -> V_222 ,
V_168 ,
V_14 -> V_56 . V_57 ,
sizeof( struct V_33 ) ,
V_64 , NULL ) ;
V_64 -> V_208 = 1 ;
V_14 -> V_219 = 1 ;
V_14 -> V_82 = V_218 -> V_82 ;
F_66 ( & V_14 -> V_31 ) ;
V_5 = F_67 ( & V_14 -> V_211 , V_218 ) ;
return V_5 ;
}
static int F_68 ( struct V_147 * V_223 , struct V_224 * V_225 )
{
struct V_63 * V_64 = V_223 -> V_151 ;
struct V_13 * V_14 = V_64 -> V_14 ;
struct V_3 * V_4 = V_64 -> V_2 -> V_4 ;
F_16 ( 1 , V_66 , & V_4 -> V_11 , L_56 ) ;
return F_69 ( & V_14 -> V_211 , V_225 ) ;
}
static unsigned int F_70 ( struct V_147 * V_223 , T_3 * V_226 )
{
struct V_63 * V_64 = V_223 -> V_151 ;
struct V_13 * V_14 = V_64 -> V_14 ;
struct V_3 * V_4 = V_64 -> V_2 -> V_4 ;
unsigned int V_227 = 0 ;
F_16 ( 1 , V_66 , & V_4 -> V_11 , L_57 ) ;
if ( V_14 -> V_53 )
V_227 = F_71 ( V_223 , & V_14 -> V_211 , V_226 ) ;
return V_227 ;
}
static int F_72 ( struct V_147 * V_147 )
{
struct V_63 * V_64 = NULL ;
struct V_13 * V_14 = F_73 ( V_147 ) ;
struct V_1 * V_2 = V_14 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_27 * V_28 = V_2 -> V_28 ;
int V_227 ;
V_64 = F_74 ( sizeof( struct V_63 ) , V_228 ) ;
if ( V_64 == NULL ) {
F_3 ( & V_4 -> V_11 ,
L_58 ) ;
return - V_229 ;
}
F_16 ( 1 , V_66 , & V_4 -> V_11 ,
L_59 ,
V_14 -> V_86 ) ;
V_147 -> V_151 = V_64 ;
V_64 -> V_14 = V_14 ;
V_64 -> V_2 = V_2 ;
if ( ! V_14 -> V_230 ) {
V_227 = V_28 -> V_36 . V_231 ( V_28 ,
V_14 -> V_38 . V_39 ) ;
if ( V_227 < 0 ) {
F_3 ( & V_4 -> V_11 ,
L_60 ) ;
F_75 ( V_64 ) ;
return - V_72 ;
}
}
V_14 -> V_230 ++ ;
V_64 -> V_208 = 0 ;
V_64 -> V_152 = V_232 ;
F_76 ( & V_14 -> V_152 , & V_64 -> V_152 ) ;
F_16 ( 1 , V_66 , & V_4 -> V_11 ,
L_61 ) ;
return 0 ;
}
static int F_77 ( struct V_147 * V_147 )
{
struct V_63 * V_64 = V_147 -> V_151 ;
struct V_13 * V_14 = V_64 -> V_14 ;
struct V_89 * V_90 = & V_14 -> V_38 . V_91 ;
struct V_1 * V_2 = V_64 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_27 * V_28 = V_2 -> V_28 ;
F_16 ( 1 , V_66 , & V_4 -> V_11 , L_62 ) ;
if ( V_64 -> V_208 ) {
V_14 -> V_219 = 0 ;
V_28 -> V_36 . V_210 ( V_28 ,
V_14 -> V_38 . V_39 ) ;
V_14 -> V_53 = 0 ;
F_78 ( & V_14 -> V_211 ) ;
F_79 ( & V_14 -> V_211 ) ;
}
V_14 -> V_230 -- ;
if ( ! V_14 -> V_230 ) {
if ( V_90 -> V_94 == V_95 ) {
struct V_13 * V_96 ;
V_96 =
F_26 ( V_2 , V_14 ) ;
V_28 -> V_36 . V_210 ( V_28 ,
V_96 -> V_38 . V_39 ) ;
V_28 -> V_36 . V_233 ( V_28 ,
V_96 -> V_38 . V_39 ) ;
}
V_28 -> V_36 . V_210 ( V_28 ,
V_14 -> V_38 . V_39 ) ;
V_28 -> V_36 . V_233 ( V_28 ,
V_14 -> V_38 . V_39 ) ;
}
F_80 ( & V_14 -> V_152 , V_64 -> V_152 ) ;
V_147 -> V_151 = NULL ;
F_75 ( V_64 ) ;
V_2 -> V_40 = 0 ;
return 0 ;
}
static int F_81 ( struct V_147 * V_147 , void * V_148 ,
struct V_234 * V_235 )
{
struct V_236 * V_237 = & V_235 -> V_237 ;
if ( V_237 -> type >= 2 ) {
F_2 ( V_4 -> V_7 ,
V_8 ,
V_238 ,
V_235 ) ;
}
return 0 ;
}
static int F_82 ( struct V_147 * V_147 , void * V_148 ,
struct V_234 * V_235 )
{
return 0 ;
}
static int F_83 ( struct V_239 * V_47 , void * V_240 )
{
struct V_241 * V_221 = F_84 ( V_47 ) ;
struct V_1 * V_242 = V_240 ;
if ( strcmp ( L_63 , V_221 -> V_243 ) == 0 )
V_242 -> V_4 = F_85 ( V_221 ) ;
if ( strcmp ( L_64 , V_221 -> V_243 ) == 0 )
V_242 -> V_28 = F_85 ( V_221 ) ;
return 0 ;
}
static T_4 int F_86 ( int V_46 , struct V_1 * V_2 ,
struct V_241 * V_221 )
{
struct V_13 * V_244 = NULL ;
struct V_245 * V_246 = NULL ;
V_2 -> V_47 [ V_46 ] =
F_87 ( sizeof( struct V_13 ) , V_228 ) ;
if ( ! V_2 -> V_47 [ V_46 ] ) {
F_88 ( V_247 L_65 ) ;
return - V_229 ;
}
F_89 ( & V_2 -> V_47 [ V_46 ] -> V_222 ) ;
F_90 ( & V_2 -> V_47 [ V_46 ] -> V_248 ) ;
V_244 = V_2 -> V_47 [ V_46 ] ;
V_246 = & V_244 -> V_202 ;
V_246 -> V_249 = V_250 ;
V_246 -> V_251 = & V_252 ;
V_246 -> V_253 = & V_254 ;
V_246 -> V_255 = - 1 ;
V_246 -> V_11 = & V_2 -> V_4 -> V_11 ;
V_246 -> V_256 = & V_244 -> V_248 ;
if ( V_2 -> V_4 -> V_107 . V_190 &
V_191 ) {
V_246 -> V_257 = ( V_118 | V_119 ) ;
V_246 -> V_203 =
V_2 -> V_4 ->
V_107 . V_108 . V_109 ;
} else
V_246 -> V_203 = 0 ;
snprintf ( V_246 -> V_243 , sizeof( V_246 -> V_243 ) ,
L_66 ,
( V_156 >> 16 ) & 0xff ,
( V_156 >> 8 ) & 0xff ,
( V_156 ) & 0xff ) ;
V_244 -> V_86 = V_46 ;
V_244 -> V_38 . V_39 =
( ( V_46 == V_87 ) ? V_258 : V_259 ) ;
F_91 ( & V_244 -> V_152 ) ;
return 0 ;
}
static T_4 int F_92 ( struct V_13 * V_244 ,
struct V_1 * V_2 ,
struct V_241 * V_221 ) {
int V_227 ;
F_93 ( & V_2 -> V_4 -> V_11 ,
L_67 ) ;
F_93 ( & V_2 -> V_4 -> V_11 ,
L_68 ,
( int ) V_244 ,
( int ) & V_244 -> V_202 ) ;
V_227 = F_94 ( & V_244 -> V_202 ,
V_260 ,
- 1 ) ;
if ( V_227 )
return - V_261 ;
V_244 -> V_2 = V_2 ;
F_95 ( V_221 , V_2 ) ;
F_96 ( & V_244 -> V_202 ,
V_244 ) ;
return 0 ;
}
static T_4 int F_97 ( struct V_241 * V_221 )
{
struct V_13 * V_244 ;
struct V_1 * V_2 ;
struct V_262 * V_263 = NULL ;
int V_264 ;
int V_46 ;
int V_227 ;
int V_41 ;
F_88 ( V_265 L_69 ) ;
V_2 = F_87 ( sizeof( struct V_1 ) , V_228 ) ;
if ( ! V_2 ) {
F_88 ( V_247 L_65 ) ;
return - V_229 ;
}
F_89 ( & V_2 -> V_30 ) ;
V_227 = F_98 ( & V_266 , NULL , V_2 ,
F_83 ) ;
if ( V_227 < 0 )
return V_227 ;
if ( NULL != V_2 -> V_4 -> V_36 . V_267 ) {
V_227 = V_2 -> V_4 -> V_36 . V_267 ( & V_221 -> V_47 ,
V_2 -> V_4 ) ;
if ( V_227 ) {
F_3 ( & V_2 -> V_4 -> V_11 ,
L_70 ) ;
V_227 = - V_229 ;
goto V_268;
}
}
for ( V_46 = 0 ; V_46 < V_52 ; V_46 ++ ) {
if ( F_86 ( V_46 , V_2 , V_221 ) ) {
V_227 = - V_261 ;
goto V_268;
}
}
V_263 = F_99 ( V_221 , V_269 , 0 ) ;
if ( ! V_263 ) {
F_3 ( & V_2 -> V_4 -> V_11 ,
L_71 ) ;
V_227 = - V_261 ;
goto V_268;
}
V_41 = V_263 -> V_270 ;
if ( F_100 ( V_41 , F_14 , V_271 , V_161 ,
V_2 ) ) {
F_3 ( & V_2 -> V_4 -> V_11 ,
L_72 ) ;
V_227 = - V_261 ;
goto V_268;
}
for ( V_46 = 0 ; V_46 < V_52 ; V_46 ++ ) {
if ( F_92 ( V_2 -> V_47 [ V_46 ] , V_2 , V_221 ) ) {
V_227 = - V_261 ;
goto V_272;
}
}
F_88 ( V_265 L_73 ) ;
return 0 ;
V_272:
F_101 ( V_263 -> V_270 , V_2 ) ;
V_268:
for ( V_264 = 0 ; V_264 < V_52 ; V_264 ++ ) {
V_244 = V_2 -> V_47 [ V_264 ] ;
if ( V_244 ) {
F_102 (
& V_244 -> V_202 ) ;
F_75 ( V_2 -> V_47 [ V_264 ] ) ;
}
}
F_75 ( V_2 ) ;
return V_227 ;
}
static int F_103 ( struct V_241 * V_221 )
{
struct V_13 * V_244 ;
struct V_1 * V_2 = F_85 ( V_221 ) ;
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_262 * V_263 ;
int V_46 ;
F_16 ( 1 , V_66 , & V_4 -> V_11 , L_74 ) ;
V_263 = F_99 ( V_221 , V_269 , 0 ) ;
F_101 ( V_263 -> V_270 , V_2 ) ;
if ( NULL != V_4 -> V_36 . V_273 )
V_4 -> V_36 . V_273 ( & V_221 -> V_47 , V_4 ) ;
for ( V_46 = 0 ; V_46 < V_52 ; V_46 ++ ) {
V_244 = V_2 -> V_47 [ V_46 ] ;
F_102 ( & V_244 -> V_202 ) ;
}
for ( V_46 = 0 ; V_46 < V_52 ; V_46 ++ ) {
F_75 ( V_2 -> V_47 [ V_46 ] ) ;
V_2 -> V_47 [ V_46 ] = NULL ;
}
return 0 ;
}
