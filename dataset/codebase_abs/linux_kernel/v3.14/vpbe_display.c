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
return - V_86 ;
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
F_6 ( & V_14 -> V_18 -> V_19 , V_87 ) ;
}
return 0 ;
}
static
struct V_13 *
F_41 ( struct V_1 * V_2 ,
struct V_13 * V_14 )
{
enum V_88 V_89 , V_90 ;
V_89 = V_14 -> V_91 ;
V_90 = ( V_89 == V_92 ) ?
V_93 : V_92 ;
return V_2 -> V_48 [ V_90 ] ;
}
static int F_38 ( struct V_1 * V_2 ,
struct V_13 * V_14 )
{
struct V_94 * V_95 = & V_14 -> V_39 . V_96 ;
struct V_27 * V_28 = V_2 -> V_28 ;
struct V_3 * V_4 = V_2 -> V_4 ;
unsigned long V_29 ;
int V_5 ;
V_29 = F_13 ( & V_14 -> V_17 -> V_19 , 0 ) ;
V_28 -> V_37 . V_38 ( V_28 ,
V_14 -> V_39 . V_40 ,
V_29 ,
V_2 -> V_41 ) ;
V_5 = V_28 -> V_37 . V_97 ( V_28 ,
V_14 -> V_39 . V_40 , 0 ) ;
if ( V_5 < 0 ) {
F_3 ( & V_4 -> V_11 ,
L_8 ) ;
return - 1 ;
}
V_14 -> V_39 . V_98 = 1 ;
if ( V_95 -> V_99 == V_100 ) {
struct V_13 * V_101 =
F_41 ( V_2 , V_14 ) ;
V_5 = V_28 -> V_37 . V_97 ( V_28 ,
V_101 -> V_39 . V_40 , 1 ) ;
if ( V_5 < 0 ) {
F_3 ( & V_4 -> V_11 ,
L_9 ) ;
return - 1 ;
}
V_101 -> V_39 . V_98 = 1 ;
}
return 0 ;
}
static void
F_42 ( struct V_1 * V_2 ,
struct V_13 * V_14 ,
int V_102 , int V_103 )
{
struct V_104 * V_39 = & V_14 -> V_39 ;
struct V_105 * V_99 = & V_14 -> V_57 ;
struct V_94 * V_95 = & V_14 -> V_39 . V_96 ;
struct V_3 * V_4 = V_2 -> V_4 ;
int V_106 ;
int V_107 = 0 ;
int V_108 = 0 ;
int V_109 ;
int V_110 ;
T_2 V_111 = V_4 -> V_112 . V_113 ;
V_95 -> V_114 = V_99 -> V_115 ;
V_95 -> V_116 = V_99 -> V_117 ;
V_39 -> V_118 = V_119 ;
V_39 -> V_120 = V_119 ;
V_39 -> V_107 = V_121 ;
V_39 -> V_108 = V_122 ;
if ( V_99 -> V_115 < V_102 ) {
V_109 = V_4 -> V_112 . V_123 / V_99 -> V_115 ;
if ( V_109 < 2 )
V_109 = 1 ;
else if ( V_109 >= 4 )
V_109 = 4 ;
else
V_109 = 2 ;
V_95 -> V_114 *= V_109 ;
if ( V_95 -> V_114 < V_102 ) {
if ( ( V_111 & V_124 ) ||
( V_111 & V_125 ) ) {
V_106 = ( V_95 -> V_114 *
V_126 ) /
V_127 ;
if ( V_106 <= V_102 ) {
V_107 = 1 ;
V_95 -> V_114 = V_106 ;
}
}
}
if ( V_109 == 2 )
V_39 -> V_118 = V_128 ;
else if ( V_109 == 4 )
V_39 -> V_118 = V_129 ;
if ( V_107 )
V_39 -> V_107 = V_130 ;
} else {
V_95 -> V_114 = V_102 ;
}
if ( V_99 -> V_117 < V_103 ) {
V_110 = V_103 / V_99 -> V_117 ;
if ( V_110 < 2 )
V_110 = 1 ;
else if ( V_110 >= 4 )
V_110 = 4 ;
else
V_110 = 2 ;
V_95 -> V_116 *= V_110 ;
if ( V_95 -> V_116 < V_103 ) {
if ( ( V_111 & V_125 ) ) {
V_106 = ( V_95 -> V_116 *
V_131 ) /
V_132 ;
if ( V_106 <= V_103 ) {
V_108 = 1 ;
V_95 -> V_116 = V_106 ;
}
}
}
if ( V_110 == 2 )
V_39 -> V_120 = V_128 ;
else if ( V_110 == 4 )
V_39 -> V_120 = V_129 ;
if ( V_108 )
V_39 -> V_107 = V_133 ;
} else {
V_95 -> V_116 = V_103 ;
}
F_17 ( 1 , V_65 , & V_4 -> V_11 ,
L_10 ,
V_95 -> V_114 , V_95 -> V_116 ) ;
}
static void F_43 ( struct V_1 * V_2 ,
struct V_13 * V_14 ,
int V_134 , int V_135 )
{
struct V_94 * V_95 = & V_14 -> V_39 . V_96 ;
struct V_3 * V_4 = V_2 -> V_4 ;
V_95 -> V_136 = F_44 ( ( unsigned int ) V_135 ,
V_4 -> V_112 . V_123 - V_95 -> V_114 ) ;
V_95 -> V_137 = F_44 ( ( unsigned int ) V_134 ,
V_4 -> V_112 . V_138 - V_95 -> V_116 ) ;
F_17 ( 1 , V_65 , & V_4 -> V_11 ,
L_11 ,
V_95 -> V_136 , V_95 -> V_137 ) ;
}
static void F_45 ( struct V_1 * V_2 ,
struct V_139 * V_140 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
if ( ( V_140 -> V_115 == 0 ) ||
( ( V_140 -> V_115 + V_140 -> V_135 ) > V_4 -> V_112 . V_123 ) )
V_140 -> V_115 = V_4 -> V_112 . V_123 - V_140 -> V_135 ;
if ( ( V_140 -> V_117 == 0 ) || ( ( V_140 -> V_117 + V_140 -> V_134 ) >
V_4 -> V_112 . V_138 ) )
V_140 -> V_117 = V_4 -> V_112 . V_138 - V_140 -> V_134 ;
if ( V_4 -> V_112 . V_141 )
V_140 -> V_117 &= ( ~ 0x01 ) ;
}
static int F_46 ( struct V_1 * V_2 ,
struct V_105 * V_99 , int V_142 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
int V_143 = 1 ;
int V_144 = 32 ;
int V_145 ;
int V_146 ;
int V_147 ;
if ( ( V_99 -> V_148 != V_149 ) &&
( V_99 -> V_148 != V_150 ) )
V_99 -> V_148 = V_149 ;
if ( ( V_99 -> V_58 != V_151 ) &&
( V_99 -> V_58 != V_56 ) ) {
if ( V_4 -> V_112 . V_141 )
V_99 -> V_58 = V_151 ;
else
V_99 -> V_58 = V_56 ;
}
if ( V_99 -> V_58 == V_151 )
V_143 = 2 ;
if ( V_99 -> V_148 == V_150 )
V_147 = 1 ;
else
V_147 = 2 ;
V_146 = V_4 -> V_112 . V_123 ;
V_145 = V_4 -> V_112 . V_138 ;
V_144 /= V_147 ;
if ( ! V_99 -> V_115 || ( V_99 -> V_115 < V_144 ) ||
( V_99 -> V_115 > V_146 ) ) {
V_99 -> V_115 = V_4 -> V_112 . V_123 ;
}
if ( ! V_99 -> V_117 || ( V_99 -> V_117 < V_143 ) ||
( V_99 -> V_117 > V_145 ) ) {
V_99 -> V_117 = V_4 -> V_112 . V_138 ;
}
if ( V_99 -> V_152 < ( V_99 -> V_115 * V_147 ) )
V_99 -> V_152 = V_99 -> V_115 * V_147 ;
V_99 -> V_152 = ( ( V_99 -> V_115 * V_147 + 31 ) & ~ 31 ) ;
if ( V_99 -> V_148 == V_150 )
V_99 -> V_67 = V_99 -> V_152 * V_99 -> V_117 +
( V_99 -> V_152 * V_99 -> V_117 >> 1 ) ;
else
V_99 -> V_67 = V_99 -> V_152 * V_99 -> V_117 ;
return 0 ;
}
static int F_47 ( struct V_153 * V_153 , void * V_154 ,
enum V_155 * V_156 )
{
struct V_61 * V_62 = V_153 -> V_157 ;
struct V_13 * V_14 = V_62 -> V_14 ;
* V_156 = F_48 ( & V_14 -> V_158 ) ;
return 0 ;
}
static int F_49 ( struct V_153 * V_153 , void * V_154 ,
enum V_155 V_156 )
{
struct V_61 * V_62 = V_153 -> V_157 ;
struct V_13 * V_14 = V_62 -> V_14 ;
int V_5 ;
V_5 = F_50 ( & V_14 -> V_158 , & V_62 -> V_158 , V_156 ) ;
return V_5 ;
}
static int F_51 ( struct V_153 * V_153 , void * V_154 ,
struct V_159 * V_160 )
{
struct V_61 * V_62 = V_153 -> V_157 ;
struct V_3 * V_4 = V_62 -> V_2 -> V_4 ;
V_160 -> V_161 = V_162 ;
V_160 -> V_163 = V_164 | V_165 ;
V_160 -> V_166 = V_160 -> V_163 | V_167 ;
snprintf ( V_160 -> V_168 , sizeof( V_160 -> V_168 ) , L_12 ,
F_52 ( V_4 -> V_169 ) ) ;
snprintf ( V_160 -> V_170 , sizeof( V_160 -> V_170 ) , L_13 ,
F_52 ( V_4 -> V_169 ) ) ;
F_53 ( V_160 -> V_171 , V_4 -> V_95 -> V_172 , sizeof( V_160 -> V_171 ) ) ;
return 0 ;
}
static int F_54 ( struct V_153 * V_153 , void * V_154 ,
const struct V_173 * V_174 )
{
struct V_61 * V_62 = V_153 -> V_157 ;
struct V_13 * V_14 = V_62 -> V_14 ;
struct V_1 * V_2 = V_62 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_94 * V_95 = & V_14 -> V_39 . V_96 ;
struct V_27 * V_28 = V_2 -> V_28 ;
struct V_139 V_175 = V_174 -> V_140 ;
int V_5 ;
F_17 ( 1 , V_65 , & V_4 -> V_11 ,
L_14 , V_14 -> V_91 ) ;
if ( V_174 -> type != V_176 ) {
F_3 ( & V_4 -> V_11 , L_15 ) ;
return - V_68 ;
}
if ( V_175 . V_134 < 0 )
V_175 . V_134 = 0 ;
if ( V_175 . V_135 < 0 )
V_175 . V_135 = 0 ;
F_45 ( V_2 , & V_175 ) ;
V_28 -> V_37 . V_177 ( V_28 ,
V_14 -> V_39 . V_40 , V_95 ) ;
F_42 ( V_2 , V_14 ,
V_175 . V_115 ,
V_175 . V_117 ) ;
F_43 ( V_2 , V_14 , V_175 . V_134 ,
V_175 . V_135 ) ;
V_5 = V_28 -> V_37 . V_178 ( V_28 ,
V_14 -> V_39 . V_40 , V_95 ) ;
if ( V_5 < 0 ) {
F_3 ( & V_4 -> V_11 ,
L_16 ) ;
return - V_68 ;
}
V_28 -> V_37 . V_179 ( V_28 ,
V_14 -> V_39 . V_40 ,
V_14 -> V_39 . V_118 ,
V_14 -> V_39 . V_120 ) ;
V_5 = V_28 -> V_37 . V_180 ( V_28 ,
V_14 -> V_39 . V_107 ,
V_14 -> V_39 . V_108 ) ;
if ( V_5 < 0 ) {
F_3 ( & V_4 -> V_11 ,
L_17 ) ;
return - V_68 ;
}
if ( ( V_14 -> V_39 . V_118 != V_119 ) ||
( V_14 -> V_39 . V_120 != V_119 ) ||
( V_14 -> V_39 . V_107 != V_121 ) ||
( V_14 -> V_39 . V_108 != V_122 ) )
V_28 -> V_37 . V_181 ( V_28 , 1 ) ;
else
V_28 -> V_37 . V_181 ( V_28 , 0 ) ;
return 0 ;
}
static int F_55 ( struct V_153 * V_153 , void * V_154 ,
struct V_173 * V_174 )
{
struct V_61 * V_62 = V_153 -> V_157 ;
struct V_13 * V_14 = V_62 -> V_14 ;
struct V_94 * V_95 = & V_14 -> V_39 . V_96 ;
struct V_3 * V_4 = V_62 -> V_2 -> V_4 ;
struct V_27 * V_28 = V_62 -> V_2 -> V_28 ;
struct V_139 * V_175 = & V_174 -> V_140 ;
F_17 ( 1 , V_65 , & V_4 -> V_11 ,
L_18 ,
V_14 -> V_91 ) ;
if ( V_174 -> type != V_176 ) {
F_3 ( & V_4 -> V_11 , L_15 ) ;
return - V_68 ;
}
V_28 -> V_37 . V_177 ( V_28 ,
V_14 -> V_39 . V_40 , V_95 ) ;
V_175 -> V_134 = V_95 -> V_137 ;
V_175 -> V_135 = V_95 -> V_136 ;
V_175 -> V_115 = V_95 -> V_114 ;
V_175 -> V_117 = V_95 -> V_116 ;
return 0 ;
}
static int F_56 ( struct V_153 * V_153 , void * V_154 ,
struct V_182 * V_183 )
{
struct V_61 * V_62 = V_153 -> V_157 ;
struct V_3 * V_4 = V_62 -> V_2 -> V_4 ;
F_17 ( 1 , V_65 , & V_4 -> V_11 , L_19 ) ;
V_183 -> type = V_176 ;
V_183 -> V_184 . V_135 = 0 ;
V_183 -> V_184 . V_134 = 0 ;
V_183 -> V_184 . V_115 = V_4 -> V_112 . V_123 ;
V_183 -> V_184 . V_117 = V_4 -> V_112 . V_138 ;
V_183 -> V_185 = V_4 -> V_112 . V_186 ;
V_183 -> V_187 = V_183 -> V_184 ;
return 0 ;
}
static int F_57 ( struct V_153 * V_153 , void * V_154 ,
struct V_71 * V_72 )
{
struct V_61 * V_62 = V_153 -> V_157 ;
struct V_13 * V_14 = V_62 -> V_14 ;
struct V_3 * V_4 = V_62 -> V_2 -> V_4 ;
F_17 ( 1 , V_65 , & V_4 -> V_11 ,
L_20 ,
V_14 -> V_91 ) ;
if ( V_176 != V_72 -> type ) {
F_3 ( & V_4 -> V_11 , L_21 ) ;
return - V_68 ;
}
V_72 -> V_72 . V_188 = V_14 -> V_57 ;
return 0 ;
}
static int F_58 ( struct V_153 * V_153 , void * V_154 ,
struct V_189 * V_72 )
{
struct V_61 * V_62 = V_153 -> V_157 ;
struct V_13 * V_14 = V_62 -> V_14 ;
struct V_3 * V_4 = V_62 -> V_2 -> V_4 ;
unsigned int V_190 = 0 ;
F_17 ( 1 , V_65 , & V_4 -> V_11 ,
L_22 ,
V_14 -> V_91 ) ;
if ( V_72 -> V_190 > 1 ) {
F_3 ( & V_4 -> V_11 , L_23 ) ;
return - V_68 ;
}
V_190 = V_72 -> V_190 ;
memset ( V_72 , 0 , sizeof( * V_72 ) ) ;
V_72 -> V_190 = V_190 ;
V_72 -> type = V_176 ;
if ( V_190 == 0 ) {
strcpy ( V_72 -> V_191 , L_24 ) ;
V_72 -> V_148 = V_149 ;
} else {
strcpy ( V_72 -> V_191 , L_25 ) ;
V_72 -> V_148 = V_150 ;
}
return 0 ;
}
static int F_59 ( struct V_153 * V_153 , void * V_154 ,
struct V_71 * V_72 )
{
struct V_61 * V_62 = V_153 -> V_157 ;
struct V_13 * V_14 = V_62 -> V_14 ;
struct V_1 * V_2 = V_62 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_94 * V_95 = & V_14 -> V_39 . V_96 ;
struct V_105 * V_99 = & V_72 -> V_72 . V_188 ;
struct V_27 * V_28 = V_2 -> V_28 ;
int V_5 ;
F_17 ( 1 , V_65 , & V_4 -> V_11 ,
L_26 ,
V_14 -> V_91 ) ;
if ( V_14 -> V_54 ) {
F_3 ( & V_4 -> V_11 , L_27 ) ;
return - V_192 ;
}
if ( V_176 != V_72 -> type ) {
F_17 ( 1 , V_65 , & V_4 -> V_11 , L_21 ) ;
return - V_68 ;
}
V_5 = F_46 ( V_2 , V_99 , 1 ) ;
if ( V_5 )
return V_5 ;
V_14 -> V_57 = * V_99 ;
if ( V_99 -> V_148 == V_150 ) {
struct V_13 * V_101 ;
V_101 = F_41 ( V_2 , V_14 ) ;
V_5 = V_28 -> V_37 . V_193 ( V_28 ,
V_101 -> V_39 . V_40 ) ;
if ( V_5 < 0 ) {
F_3 ( & V_4 -> V_11 ,
L_28 ) ;
return - V_192 ;
}
}
V_28 -> V_37 . V_177 ( V_28 ,
V_14 -> V_39 . V_40 , V_95 ) ;
V_95 -> V_114 = V_99 -> V_115 ;
V_95 -> V_116 = V_99 -> V_117 ;
V_95 -> V_194 = V_99 -> V_152 ;
V_95 -> V_137 = 0 ;
V_95 -> V_136 = 0 ;
V_95 -> V_141 = V_4 -> V_112 . V_141 ;
if ( V_149 == V_99 -> V_148 )
V_95 -> V_99 = V_195 ;
if ( V_150 == V_99 -> V_148 ) {
struct V_13 * V_101 ;
V_95 -> V_99 = V_100 ;
V_101 = F_41 ( V_2 ,
V_14 ) ;
V_101 -> V_39 . V_96 . V_99 = V_100 ;
}
V_5 = V_28 -> V_37 . V_178 ( V_28 ,
V_14 -> V_39 . V_40 , V_95 ) ;
if ( V_5 < 0 ) {
F_3 ( & V_4 -> V_11 ,
L_29 ) ;
return - V_68 ;
}
V_28 -> V_37 . V_177 ( V_28 ,
V_14 -> V_39 . V_40 , V_95 ) ;
return 0 ;
}
static int F_60 ( struct V_153 * V_153 , void * V_154 ,
struct V_71 * V_72 )
{
struct V_61 * V_62 = V_153 -> V_157 ;
struct V_1 * V_2 = V_62 -> V_2 ;
struct V_3 * V_4 = V_62 -> V_2 -> V_4 ;
struct V_105 * V_99 = & V_72 -> V_72 . V_188 ;
F_17 ( 1 , V_65 , & V_4 -> V_11 , L_30 ) ;
if ( V_176 != V_72 -> type ) {
F_3 ( & V_4 -> V_11 , L_21 ) ;
return - V_68 ;
}
return F_46 ( V_2 , V_99 , 0 ) ;
}
static int F_61 ( struct V_153 * V_153 , void * V_154 ,
T_2 V_113 )
{
struct V_61 * V_62 = V_154 ;
struct V_13 * V_14 = V_62 -> V_14 ;
struct V_3 * V_4 = V_62 -> V_2 -> V_4 ;
int V_5 ;
F_17 ( 1 , V_65 , & V_4 -> V_11 , L_31 ) ;
if ( V_14 -> V_54 ) {
F_3 ( & V_4 -> V_11 , L_27 ) ;
return - V_192 ;
}
if ( NULL != V_4 -> V_37 . V_196 ) {
V_5 = V_4 -> V_37 . V_196 ( V_4 , V_113 ) ;
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
static int F_62 ( struct V_153 * V_153 , void * V_154 ,
T_2 * V_113 )
{
struct V_61 * V_62 = V_154 ;
struct V_3 * V_4 = V_62 -> V_2 -> V_4 ;
F_17 ( 1 , V_65 , & V_4 -> V_11 , L_33 ) ;
if ( V_4 -> V_112 . V_197 & V_198 ) {
* V_113 = V_4 -> V_112 . V_113 ;
return 0 ;
}
return - V_68 ;
}
static int F_63 ( struct V_153 * V_153 , void * V_154 ,
struct V_199 * V_200 )
{
struct V_61 * V_62 = V_154 ;
struct V_3 * V_4 = V_62 -> V_2 -> V_4 ;
int V_5 ;
F_17 ( 1 , V_65 , & V_4 -> V_11 , L_34 ) ;
if ( NULL == V_4 -> V_37 . V_201 )
return - V_68 ;
V_5 = V_4 -> V_37 . V_201 ( V_4 , V_200 ) ;
if ( V_5 ) {
F_17 ( 1 , V_65 , & V_4 -> V_11 ,
L_35 ) ;
return - V_68 ;
}
return 0 ;
}
static int F_64 ( struct V_153 * V_153 , void * V_154 ,
unsigned int V_47 )
{
struct V_61 * V_62 = V_154 ;
struct V_13 * V_14 = V_62 -> V_14 ;
struct V_3 * V_4 = V_62 -> V_2 -> V_4 ;
int V_5 ;
F_17 ( 1 , V_65 , & V_4 -> V_11 , L_36 ) ;
if ( V_14 -> V_54 ) {
F_3 ( & V_4 -> V_11 , L_27 ) ;
return - V_192 ;
}
if ( NULL == V_4 -> V_37 . V_202 )
return - V_68 ;
V_5 = V_4 -> V_37 . V_202 ( V_4 , V_47 ) ;
if ( V_5 ) {
F_3 ( & V_4 -> V_11 ,
L_37 ) ;
return - V_68 ;
}
return 0 ;
}
static int F_65 ( struct V_153 * V_153 , void * V_154 ,
unsigned int * V_47 )
{
struct V_61 * V_62 = V_154 ;
struct V_3 * V_4 = V_62 -> V_2 -> V_4 ;
F_17 ( 1 , V_65 , & V_4 -> V_11 , L_38 ) ;
* V_47 = V_4 -> V_203 ;
return 0 ;
}
static int
F_66 ( struct V_153 * V_153 , void * V_154 ,
struct V_204 * V_205 )
{
struct V_61 * V_62 = V_154 ;
struct V_3 * V_4 = V_62 -> V_2 -> V_4 ;
int V_5 ;
F_17 ( 1 , V_65 , & V_4 -> V_11 , L_39 ) ;
if ( NULL == V_4 -> V_37 . V_206 )
return - V_68 ;
V_5 = V_4 -> V_37 . V_206 ( V_4 , V_205 ) ;
if ( V_5 ) {
F_3 ( & V_4 -> V_11 ,
L_40 ) ;
return - V_68 ;
}
return 0 ;
}
static int
F_67 ( struct V_153 * V_153 , void * V_154 ,
struct V_207 * V_205 )
{
struct V_61 * V_62 = V_154 ;
struct V_13 * V_14 = V_62 -> V_14 ;
struct V_3 * V_4 = V_62 -> V_2 -> V_4 ;
int V_5 ;
F_17 ( 1 , V_65 , & V_4 -> V_11 , L_41 ) ;
if ( V_14 -> V_54 ) {
F_3 ( & V_4 -> V_11 , L_27 ) ;
return - V_192 ;
}
if ( ! V_4 -> V_37 . V_208 )
return - V_68 ;
V_5 = V_4 -> V_37 . V_208 ( V_4 , V_205 ) ;
if ( V_5 ) {
F_3 ( & V_4 -> V_11 ,
L_42 ) ;
return - V_68 ;
}
return 0 ;
}
static int
F_68 ( struct V_153 * V_153 , void * V_154 ,
struct V_207 * V_209 )
{
struct V_61 * V_62 = V_154 ;
struct V_3 * V_4 = V_62 -> V_2 -> V_4 ;
F_17 ( 1 , V_65 , & V_4 -> V_11 , L_43 ) ;
if ( V_4 -> V_112 . V_197 &
V_210 ) {
* V_209 = V_4 -> V_112 . V_209 ;
} else {
return - V_68 ;
}
return 0 ;
}
static int F_69 ( struct V_153 * V_153 , void * V_154 ,
enum V_211 V_212 )
{
struct V_61 * V_62 = V_153 -> V_157 ;
struct V_13 * V_14 = V_62 -> V_14 ;
struct V_3 * V_4 = V_62 -> V_2 -> V_4 ;
struct V_27 * V_28 = V_62 -> V_2 -> V_28 ;
int V_5 ;
F_17 ( 1 , V_65 , & V_4 -> V_11 ,
L_44 ,
V_14 -> V_91 ) ;
if ( V_176 != V_212 ) {
F_3 ( & V_4 -> V_11 , L_45 ) ;
return - V_68 ;
}
if ( ! V_62 -> V_213 ) {
F_3 ( & V_4 -> V_11 , L_46 ) ;
return - V_214 ;
}
if ( ! V_14 -> V_54 ) {
F_3 ( & V_4 -> V_11 , L_47
L_48 , V_14 -> V_91 ) ;
return - V_68 ;
}
V_28 -> V_37 . V_215 ( V_28 ,
V_14 -> V_39 . V_40 ) ;
V_14 -> V_54 = 0 ;
V_5 = F_70 ( & V_14 -> V_216 , V_212 ) ;
return V_5 ;
}
static int F_71 ( struct V_153 * V_153 , void * V_154 ,
enum V_211 V_212 )
{
struct V_61 * V_62 = V_153 -> V_157 ;
struct V_13 * V_14 = V_62 -> V_14 ;
struct V_1 * V_2 = V_62 -> V_2 ;
struct V_3 * V_4 = V_62 -> V_2 -> V_4 ;
struct V_27 * V_28 = V_2 -> V_28 ;
int V_5 ;
V_28 -> V_37 . V_215 ( V_28 ,
V_14 -> V_39 . V_40 ) ;
F_17 ( 1 , V_65 , & V_4 -> V_11 , L_49 ,
V_14 -> V_91 ) ;
if ( V_176 != V_212 ) {
F_3 ( & V_4 -> V_11 , L_45 ) ;
return - V_68 ;
}
if ( ! V_62 -> V_213 ) {
F_3 ( & V_4 -> V_11 , L_46 ) ;
return - V_214 ;
}
if ( V_14 -> V_54 ) {
F_3 ( & V_4 -> V_11 , L_50 ) ;
return - V_192 ;
}
V_5 = F_72 ( & V_14 -> V_216 , V_212 ) ;
if ( V_5 ) {
F_3 ( & V_4 -> V_11 ,
L_51 ) ;
return V_5 ;
}
return V_5 ;
}
static int F_73 ( struct V_153 * V_153 , void * V_154 ,
struct V_217 * V_80 )
{
struct V_61 * V_62 = V_153 -> V_157 ;
struct V_13 * V_14 = V_62 -> V_14 ;
struct V_3 * V_4 = V_62 -> V_2 -> V_4 ;
int V_5 ;
F_17 ( 1 , V_65 , & V_4 -> V_11 ,
L_52 ,
V_14 -> V_91 ) ;
if ( V_176 != V_80 -> type ) {
F_3 ( & V_4 -> V_11 , L_45 ) ;
return - V_68 ;
}
if ( ! V_62 -> V_213 ) {
F_3 ( & V_4 -> V_11 , L_46 ) ;
return - V_214 ;
}
if ( V_153 -> V_218 & V_219 )
V_5 = F_74 ( & V_14 -> V_216 , V_80 , 1 ) ;
else
V_5 = F_74 ( & V_14 -> V_216 , V_80 , 0 ) ;
return V_5 ;
}
static int F_75 ( struct V_153 * V_153 , void * V_154 ,
struct V_217 * V_156 )
{
struct V_61 * V_62 = V_153 -> V_157 ;
struct V_13 * V_14 = V_62 -> V_14 ;
struct V_3 * V_4 = V_62 -> V_2 -> V_4 ;
F_17 ( 1 , V_65 , & V_4 -> V_11 ,
L_53 ,
V_14 -> V_91 ) ;
if ( V_176 != V_156 -> type ) {
F_3 ( & V_4 -> V_11 , L_45 ) ;
return - V_68 ;
}
if ( ! V_62 -> V_213 ) {
F_3 ( & V_4 -> V_11 , L_46 ) ;
return - V_214 ;
}
return F_76 ( & V_14 -> V_216 , V_156 ) ;
}
static int F_77 ( struct V_153 * V_153 , void * V_154 ,
struct V_217 * V_80 )
{
struct V_61 * V_62 = V_153 -> V_157 ;
struct V_13 * V_14 = V_62 -> V_14 ;
struct V_3 * V_4 = V_62 -> V_2 -> V_4 ;
F_17 ( 1 , V_65 , & V_4 -> V_11 ,
L_54 ,
V_14 -> V_91 ) ;
if ( V_176 != V_80 -> type ) {
F_3 ( & V_4 -> V_11 , L_45 ) ;
return - V_68 ;
}
return F_78 ( & V_14 -> V_216 , V_80 ) ;
}
static int F_79 ( struct V_153 * V_153 , void * V_154 ,
struct V_220 * V_221 )
{
struct V_61 * V_62 = V_153 -> V_157 ;
struct V_13 * V_14 = V_62 -> V_14 ;
struct V_3 * V_4 = V_62 -> V_2 -> V_4 ;
struct V_63 * V_64 ;
int V_5 ;
F_17 ( 1 , V_65 , & V_4 -> V_11 , L_55 ) ;
if ( V_176 != V_221 -> type ) {
F_3 ( & V_4 -> V_11 , L_45 ) ;
return - V_68 ;
}
if ( 0 != V_14 -> V_222 ) {
F_3 ( & V_4 -> V_11 , L_56 ) ;
return - V_192 ;
}
V_14 -> V_79 = F_80 ( V_4 -> V_169 ) ;
if ( F_81 ( V_14 -> V_79 ) ) {
F_3 ( & V_4 -> V_11 , L_57 ) ;
return F_82 ( V_14 -> V_79 ) ;
}
V_64 = & V_14 -> V_216 ;
memset ( V_64 , 0 , sizeof( * V_64 ) ) ;
V_64 -> type = V_176 ;
V_64 -> V_223 = V_224 | V_225 ;
V_64 -> V_226 = V_62 ;
V_64 -> V_37 = & V_227 ;
V_64 -> V_228 = & V_229 ;
V_64 -> V_230 = sizeof( struct V_33 ) ;
V_64 -> V_231 = V_232 ;
V_5 = F_83 ( V_64 ) ;
if ( V_5 ) {
F_3 ( & V_4 -> V_11 , L_58 ) ;
F_84 ( V_14 -> V_79 ) ;
return V_5 ;
}
V_62 -> V_213 = 1 ;
V_14 -> V_222 = 1 ;
V_14 -> V_233 = V_221 -> V_233 ;
F_36 ( & V_14 -> V_31 ) ;
return F_85 ( V_64 , V_221 ) ;
}
static int F_86 ( struct V_153 * V_234 , struct V_235 * V_236 )
{
struct V_61 * V_62 = V_234 -> V_157 ;
struct V_13 * V_14 = V_62 -> V_14 ;
struct V_3 * V_4 = V_62 -> V_2 -> V_4 ;
int V_5 ;
F_17 ( 1 , V_65 , & V_4 -> V_11 , L_59 ) ;
if ( F_87 ( & V_14 -> V_84 ) )
return - V_237 ;
V_5 = F_88 ( & V_14 -> V_216 , V_236 ) ;
F_32 ( & V_14 -> V_84 ) ;
return V_5 ;
}
static unsigned int F_89 ( struct V_153 * V_234 , T_3 * V_238 )
{
struct V_61 * V_62 = V_234 -> V_157 ;
struct V_13 * V_14 = V_62 -> V_14 ;
struct V_3 * V_4 = V_62 -> V_2 -> V_4 ;
unsigned int V_239 = 0 ;
F_17 ( 1 , V_65 , & V_4 -> V_11 , L_60 ) ;
if ( V_14 -> V_54 ) {
F_34 ( & V_14 -> V_84 ) ;
V_239 = F_90 ( & V_14 -> V_216 , V_234 , V_238 ) ;
F_32 ( & V_14 -> V_84 ) ;
}
return V_239 ;
}
static int F_91 ( struct V_153 * V_153 )
{
struct V_61 * V_62 = NULL ;
struct V_13 * V_14 = F_92 ( V_153 ) ;
struct V_1 * V_2 = V_14 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_27 * V_28 = V_2 -> V_28 ;
int V_239 ;
V_62 = F_93 ( sizeof( struct V_61 ) , V_240 ) ;
if ( V_62 == NULL ) {
F_3 ( & V_4 -> V_11 ,
L_61 ) ;
return - V_241 ;
}
F_17 ( 1 , V_65 , & V_4 -> V_11 ,
L_62 ,
V_14 -> V_91 ) ;
V_153 -> V_157 = V_62 ;
V_62 -> V_14 = V_14 ;
V_62 -> V_2 = V_2 ;
if ( ! V_14 -> V_242 ) {
if ( F_87 ( & V_14 -> V_84 ) )
return - V_237 ;
V_239 = V_28 -> V_37 . V_193 ( V_28 ,
V_14 -> V_39 . V_40 ) ;
F_32 ( & V_14 -> V_84 ) ;
if ( V_239 < 0 ) {
F_3 ( & V_4 -> V_11 ,
L_28 ) ;
F_94 ( V_62 ) ;
return - V_68 ;
}
}
V_14 -> V_242 ++ ;
V_62 -> V_213 = 0 ;
V_62 -> V_158 = V_243 ;
F_95 ( & V_14 -> V_158 , & V_62 -> V_158 ) ;
F_17 ( 1 , V_65 , & V_4 -> V_11 ,
L_63 ) ;
return 0 ;
}
static int F_96 ( struct V_153 * V_153 )
{
struct V_61 * V_62 = V_153 -> V_157 ;
struct V_13 * V_14 = V_62 -> V_14 ;
struct V_94 * V_95 = & V_14 -> V_39 . V_96 ;
struct V_1 * V_2 = V_62 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_27 * V_28 = V_2 -> V_28 ;
F_17 ( 1 , V_65 , & V_4 -> V_11 , L_64 ) ;
F_34 ( & V_14 -> V_84 ) ;
if ( V_62 -> V_213 ) {
V_14 -> V_222 = 0 ;
V_28 -> V_37 . V_215 ( V_28 ,
V_14 -> V_39 . V_40 ) ;
V_14 -> V_54 = 0 ;
F_97 ( & V_14 -> V_216 ) ;
F_84 ( & V_14 -> V_216 ) ;
}
V_14 -> V_242 -- ;
if ( ! V_14 -> V_242 ) {
if ( V_95 -> V_99 == V_100 ) {
struct V_13 * V_101 ;
V_101 =
F_41 ( V_2 , V_14 ) ;
V_28 -> V_37 . V_215 ( V_28 ,
V_101 -> V_39 . V_40 ) ;
V_28 -> V_37 . V_244 ( V_28 ,
V_101 -> V_39 . V_40 ) ;
}
V_28 -> V_37 . V_215 ( V_28 ,
V_14 -> V_39 . V_40 ) ;
V_28 -> V_37 . V_244 ( V_28 ,
V_14 -> V_39 . V_40 ) ;
}
F_98 ( & V_14 -> V_158 , V_62 -> V_158 ) ;
V_153 -> V_157 = NULL ;
F_32 ( & V_14 -> V_84 ) ;
F_94 ( V_62 ) ;
V_2 -> V_41 = 0 ;
return 0 ;
}
static int F_99 ( struct V_245 * V_48 , void * V_246 )
{
struct V_247 * V_169 = F_100 ( V_48 ) ;
struct V_1 * V_248 = V_246 ;
if ( strcmp ( L_65 , V_169 -> V_249 ) == 0 )
V_248 -> V_4 = F_101 ( V_169 ) ;
if ( strstr ( V_169 -> V_249 , L_66 ) != NULL )
V_248 -> V_28 = F_101 ( V_169 ) ;
return 0 ;
}
static int F_102 ( int V_47 , struct V_1 * V_2 ,
struct V_247 * V_169 )
{
struct V_13 * V_250 = NULL ;
struct V_251 * V_252 = NULL ;
V_2 -> V_48 [ V_47 ] =
F_103 ( sizeof( struct V_13 ) , V_240 ) ;
if ( ! V_2 -> V_48 [ V_47 ] ) {
F_104 ( V_253 L_67 ) ;
return - V_241 ;
}
F_105 ( & V_2 -> V_48 [ V_47 ] -> V_83 ) ;
F_106 ( & V_2 -> V_48 [ V_47 ] -> V_84 ) ;
V_250 = V_2 -> V_48 [ V_47 ] ;
V_252 = & V_250 -> V_254 ;
V_252 -> V_255 = V_256 ;
V_252 -> V_257 = & V_258 ;
V_252 -> V_259 = & V_260 ;
V_252 -> V_261 = - 1 ;
V_252 -> V_11 = & V_2 -> V_4 -> V_11 ;
V_252 -> V_262 = & V_250 -> V_84 ;
V_252 -> V_263 = V_264 ;
if ( V_2 -> V_4 -> V_112 . V_197 &
V_198 )
V_252 -> V_265 = ( V_124 | V_125 ) ;
snprintf ( V_252 -> V_249 , sizeof( V_252 -> V_249 ) ,
L_68 ,
( V_162 >> 16 ) & 0xff ,
( V_162 >> 8 ) & 0xff ,
( V_162 ) & 0xff ) ;
V_250 -> V_91 = V_47 ;
V_250 -> V_39 . V_40 =
( ( V_47 == V_92 ) ? V_266 : V_267 ) ;
F_107 ( & V_250 -> V_158 ) ;
return 0 ;
}
static int F_108 ( struct V_13 * V_250 ,
struct V_1 * V_2 ,
struct V_247 * V_169 )
{
int V_239 ;
F_109 ( & V_2 -> V_4 -> V_11 ,
L_69 ) ;
F_109 ( & V_2 -> V_4 -> V_11 ,
L_70 ,
( int ) V_250 ,
( int ) & V_250 -> V_254 ) ;
V_239 = F_110 ( & V_250 -> V_254 ,
V_268 ,
- 1 ) ;
if ( V_239 )
return - V_269 ;
V_250 -> V_2 = V_2 ;
F_111 ( V_169 , V_2 ) ;
F_112 ( & V_250 -> V_254 ,
V_250 ) ;
return 0 ;
}
static int F_113 ( struct V_247 * V_169 )
{
struct V_13 * V_250 ;
struct V_1 * V_2 ;
struct V_270 * V_271 = NULL ;
int V_272 ;
int V_47 ;
int V_239 ;
int V_42 ;
F_104 ( V_273 L_71 ) ;
V_2 = F_114 ( & V_169 -> V_48 , sizeof( struct V_1 ) ,
V_240 ) ;
if ( ! V_2 )
return - V_241 ;
F_105 ( & V_2 -> V_30 ) ;
V_239 = F_115 ( & V_274 , NULL , V_2 ,
F_99 ) ;
if ( V_239 < 0 )
return V_239 ;
if ( NULL != V_2 -> V_4 -> V_37 . V_275 ) {
V_239 = V_2 -> V_4 -> V_37 . V_275 ( & V_169 -> V_48 ,
V_2 -> V_4 ) ;
if ( V_239 ) {
F_3 ( & V_2 -> V_4 -> V_11 ,
L_72 ) ;
V_239 = - V_241 ;
goto V_276;
}
}
for ( V_47 = 0 ; V_47 < V_53 ; V_47 ++ ) {
if ( F_102 ( V_47 , V_2 , V_169 ) ) {
V_239 = - V_269 ;
goto V_276;
}
}
V_271 = F_116 ( V_169 , V_277 , 0 ) ;
if ( ! V_271 ) {
F_3 ( & V_2 -> V_4 -> V_11 ,
L_73 ) ;
V_239 = - V_269 ;
goto V_276;
}
V_42 = V_271 -> V_278 ;
V_239 = F_117 ( & V_169 -> V_48 , V_42 , F_14 , 0 ,
V_279 , V_2 ) ;
if ( V_239 ) {
F_3 ( & V_2 -> V_4 -> V_11 ,
L_74 ) ;
goto V_276;
}
for ( V_47 = 0 ; V_47 < V_53 ; V_47 ++ ) {
if ( F_108 ( V_2 -> V_48 [ V_47 ] , V_2 , V_169 ) ) {
V_239 = - V_269 ;
goto V_276;
}
}
F_104 ( V_273 L_75 ) ;
return 0 ;
V_276:
for ( V_272 = 0 ; V_272 < V_53 ; V_272 ++ ) {
V_250 = V_2 -> V_48 [ V_272 ] ;
if ( V_250 ) {
F_118 (
& V_250 -> V_254 ) ;
F_94 ( V_2 -> V_48 [ V_272 ] ) ;
}
}
return V_239 ;
}
static int F_119 ( struct V_247 * V_169 )
{
struct V_13 * V_250 ;
struct V_1 * V_2 = F_101 ( V_169 ) ;
struct V_3 * V_4 = V_2 -> V_4 ;
int V_47 ;
F_17 ( 1 , V_65 , & V_4 -> V_11 , L_76 ) ;
if ( NULL != V_4 -> V_37 . V_280 )
V_4 -> V_37 . V_280 ( & V_169 -> V_48 , V_4 ) ;
for ( V_47 = 0 ; V_47 < V_53 ; V_47 ++ ) {
V_250 = V_2 -> V_48 [ V_47 ] ;
F_118 ( & V_250 -> V_254 ) ;
}
for ( V_47 = 0 ; V_47 < V_53 ; V_47 ++ ) {
F_94 ( V_2 -> V_48 [ V_47 ] ) ;
V_2 -> V_48 [ V_47 ] = NULL ;
}
return 0 ;
}
