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
if ( ! F_15 ( & V_14 -> V_54 ) )
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
static int F_16 ( struct V_60 * V_19 )
{
struct V_61 * V_62 = V_19 -> V_61 ;
struct V_13 * V_14 = F_17 ( V_62 ) ;
struct V_3 * V_4 = V_14 -> V_2 -> V_4 ;
unsigned long V_29 ;
F_18 ( 1 , V_63 , & V_4 -> V_11 ,
L_2 ) ;
F_19 ( V_19 , 0 , V_14 -> V_57 . V_64 ) ;
if ( F_20 ( V_19 , 0 ) > F_21 ( V_19 , 0 ) )
return - V_65 ;
V_29 = F_13 ( V_19 , 0 ) ;
if ( ! F_22 ( V_29 , 8 ) ) {
F_3 ( & V_4 -> V_11 ,
L_3 ) ;
return - V_65 ;
}
return 0 ;
}
static int
F_23 ( struct V_61 * V_66 , const struct V_67 * V_68 ,
unsigned int * V_69 , unsigned int * V_70 ,
unsigned int V_71 [] , void * V_72 [] )
{
struct V_13 * V_14 = F_17 ( V_66 ) ;
struct V_3 * V_4 = V_14 -> V_2 -> V_4 ;
F_18 ( 1 , V_63 , & V_4 -> V_11 , L_4 ) ;
if ( V_68 && V_68 -> V_68 . V_73 . V_64 < V_14 -> V_57 . V_64 )
return - V_65 ;
if ( V_66 -> V_74 + * V_69 < V_75 )
* V_69 = V_75 - V_66 -> V_74 ;
* V_70 = 1 ;
V_71 [ 0 ] = V_68 ? V_68 -> V_68 . V_73 . V_64 : V_14 -> V_57 . V_64 ;
V_72 [ 0 ] = V_14 -> V_76 ;
return 0 ;
}
static void F_24 ( struct V_60 * V_19 )
{
struct V_33 * V_77 = F_25 ( V_19 ,
struct V_33 , V_19 ) ;
struct V_13 * V_14 = F_17 ( V_19 -> V_61 ) ;
struct V_1 * V_78 = V_14 -> V_2 ;
struct V_3 * V_4 = V_14 -> V_2 -> V_4 ;
unsigned long V_79 ;
F_18 ( 1 , V_63 , & V_4 -> V_11 ,
L_5 ) ;
F_26 ( & V_78 -> V_30 , V_79 ) ;
F_27 ( & V_77 -> V_34 , & V_14 -> V_31 ) ;
F_28 ( & V_78 -> V_30 , V_79 ) ;
}
static int F_29 ( struct V_61 * V_66 , unsigned int V_80 )
{
struct V_13 * V_14 = F_17 ( V_66 ) ;
struct V_27 * V_28 = V_14 -> V_2 -> V_28 ;
int V_5 ;
V_28 -> V_37 . V_81 ( V_28 , V_14 -> V_39 . V_40 ) ;
V_14 -> V_18 = V_14 -> V_17 = F_11 ( V_14 -> V_31 . V_32 ,
struct V_33 , V_34 ) ;
F_12 ( & V_14 -> V_17 -> V_34 ) ;
V_14 -> V_17 -> V_19 . V_35 = V_36 ;
V_14 -> V_59 = 0 ;
V_5 = F_30 ( V_14 -> V_2 , V_14 ) ;
if ( V_5 < 0 ) {
struct V_33 * V_77 , * V_82 ;
F_6 ( & V_14 -> V_17 -> V_19 , V_83 ) ;
F_31 (buf, tmp, &layer->dma_queue, list) {
F_12 ( & V_77 -> V_34 ) ;
F_6 ( & V_77 -> V_19 , V_83 ) ;
}
return V_5 ;
}
V_14 -> V_55 = 1 ;
return V_5 ;
}
static void F_32 ( struct V_61 * V_66 )
{
struct V_13 * V_14 = F_17 ( V_66 ) ;
struct V_27 * V_28 = V_14 -> V_2 -> V_28 ;
struct V_1 * V_78 = V_14 -> V_2 ;
unsigned long V_79 ;
if ( ! F_33 ( V_66 ) )
return;
V_28 -> V_37 . V_81 ( V_28 , V_14 -> V_39 . V_40 ) ;
F_26 ( & V_78 -> V_30 , V_79 ) ;
if ( V_14 -> V_17 == V_14 -> V_18 ) {
F_6 ( & V_14 -> V_17 -> V_19 , V_84 ) ;
} else {
if ( V_14 -> V_17 != NULL )
F_6 ( & V_14 -> V_17 -> V_19 ,
V_84 ) ;
if ( V_14 -> V_18 != NULL )
F_6 ( & V_14 -> V_18 -> V_19 ,
V_84 ) ;
}
while ( ! F_9 ( & V_14 -> V_31 ) ) {
V_14 -> V_18 = F_11 ( V_14 -> V_31 . V_32 ,
struct V_33 , V_34 ) ;
F_12 ( & V_14 -> V_18 -> V_34 ) ;
F_6 ( & V_14 -> V_18 -> V_19 , V_84 ) ;
}
F_28 ( & V_78 -> V_30 , V_79 ) ;
}
static
struct V_13 *
F_34 ( struct V_1 * V_2 ,
struct V_13 * V_14 )
{
enum V_85 V_86 , V_87 ;
V_86 = V_14 -> V_88 ;
V_87 = ( V_86 == V_89 ) ?
V_90 : V_89 ;
return V_2 -> V_48 [ V_87 ] ;
}
static int F_30 ( struct V_1 * V_2 ,
struct V_13 * V_14 )
{
struct V_91 * V_92 = & V_14 -> V_39 . V_93 ;
struct V_27 * V_28 = V_2 -> V_28 ;
struct V_3 * V_4 = V_2 -> V_4 ;
unsigned long V_29 ;
int V_5 ;
V_29 = F_13 ( & V_14 -> V_17 -> V_19 , 0 ) ;
V_28 -> V_37 . V_38 ( V_28 ,
V_14 -> V_39 . V_40 ,
V_29 ,
V_2 -> V_41 ) ;
V_5 = V_28 -> V_37 . V_94 ( V_28 ,
V_14 -> V_39 . V_40 , 0 ) ;
if ( V_5 < 0 ) {
F_3 ( & V_4 -> V_11 ,
L_6 ) ;
return - 1 ;
}
V_14 -> V_39 . V_95 = 1 ;
if ( V_92 -> V_96 == V_97 ) {
struct V_13 * V_98 =
F_34 ( V_2 , V_14 ) ;
V_5 = V_28 -> V_37 . V_94 ( V_28 ,
V_98 -> V_39 . V_40 , 1 ) ;
if ( V_5 < 0 ) {
F_3 ( & V_4 -> V_11 ,
L_7 ) ;
return - 1 ;
}
V_98 -> V_39 . V_95 = 1 ;
}
return 0 ;
}
static void
F_35 ( struct V_1 * V_2 ,
struct V_13 * V_14 ,
int V_99 , int V_100 )
{
struct V_101 * V_39 = & V_14 -> V_39 ;
struct V_102 * V_96 = & V_14 -> V_57 ;
struct V_91 * V_92 = & V_14 -> V_39 . V_93 ;
struct V_3 * V_4 = V_2 -> V_4 ;
int V_103 ;
int V_104 = 0 ;
int V_105 = 0 ;
int V_106 ;
int V_107 ;
T_2 V_108 = V_4 -> V_109 . V_110 ;
V_92 -> V_111 = V_96 -> V_112 ;
V_92 -> V_113 = V_96 -> V_114 ;
V_39 -> V_115 = V_116 ;
V_39 -> V_117 = V_116 ;
V_39 -> V_104 = V_118 ;
V_39 -> V_105 = V_119 ;
if ( V_96 -> V_112 < V_99 ) {
V_106 = V_4 -> V_109 . V_120 / V_96 -> V_112 ;
if ( V_106 < 2 )
V_106 = 1 ;
else if ( V_106 >= 4 )
V_106 = 4 ;
else
V_106 = 2 ;
V_92 -> V_111 *= V_106 ;
if ( V_92 -> V_111 < V_99 ) {
if ( ( V_108 & V_121 ) ||
( V_108 & V_122 ) ) {
V_103 = ( V_92 -> V_111 *
V_123 ) /
V_124 ;
if ( V_103 <= V_99 ) {
V_104 = 1 ;
V_92 -> V_111 = V_103 ;
}
}
}
if ( V_106 == 2 )
V_39 -> V_115 = V_125 ;
else if ( V_106 == 4 )
V_39 -> V_115 = V_126 ;
if ( V_104 )
V_39 -> V_104 = V_127 ;
} else {
V_92 -> V_111 = V_99 ;
}
if ( V_96 -> V_114 < V_100 ) {
V_107 = V_100 / V_96 -> V_114 ;
if ( V_107 < 2 )
V_107 = 1 ;
else if ( V_107 >= 4 )
V_107 = 4 ;
else
V_107 = 2 ;
V_92 -> V_113 *= V_107 ;
if ( V_92 -> V_113 < V_100 ) {
if ( ( V_108 & V_122 ) ) {
V_103 = ( V_92 -> V_113 *
V_128 ) /
V_129 ;
if ( V_103 <= V_100 ) {
V_105 = 1 ;
V_92 -> V_113 = V_103 ;
}
}
}
if ( V_107 == 2 )
V_39 -> V_117 = V_125 ;
else if ( V_107 == 4 )
V_39 -> V_117 = V_126 ;
if ( V_105 )
V_39 -> V_104 = V_130 ;
} else {
V_92 -> V_113 = V_100 ;
}
F_18 ( 1 , V_63 , & V_4 -> V_11 ,
L_8 ,
V_92 -> V_111 , V_92 -> V_113 ) ;
}
static void F_36 ( struct V_1 * V_2 ,
struct V_13 * V_14 ,
int V_131 , int V_132 )
{
struct V_91 * V_92 = & V_14 -> V_39 . V_93 ;
struct V_3 * V_4 = V_2 -> V_4 ;
V_92 -> V_133 = F_37 ( ( unsigned int ) V_132 ,
V_4 -> V_109 . V_120 - V_92 -> V_111 ) ;
V_92 -> V_134 = F_37 ( ( unsigned int ) V_131 ,
V_4 -> V_109 . V_135 - V_92 -> V_113 ) ;
F_18 ( 1 , V_63 , & V_4 -> V_11 ,
L_9 ,
V_92 -> V_133 , V_92 -> V_134 ) ;
}
static void F_38 ( struct V_1 * V_2 ,
struct V_136 * V_137 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
if ( ( V_137 -> V_112 == 0 ) ||
( ( V_137 -> V_112 + V_137 -> V_132 ) > V_4 -> V_109 . V_120 ) )
V_137 -> V_112 = V_4 -> V_109 . V_120 - V_137 -> V_132 ;
if ( ( V_137 -> V_114 == 0 ) || ( ( V_137 -> V_114 + V_137 -> V_131 ) >
V_4 -> V_109 . V_135 ) )
V_137 -> V_114 = V_4 -> V_109 . V_135 - V_137 -> V_131 ;
if ( V_4 -> V_109 . V_138 )
V_137 -> V_114 &= ( ~ 0x01 ) ;
}
static int F_39 ( struct V_1 * V_2 ,
struct V_102 * V_96 , int V_139 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
int V_140 = 1 ;
int V_141 = 32 ;
int V_142 ;
int V_143 ;
int V_144 ;
if ( ( V_96 -> V_145 != V_146 ) &&
( V_96 -> V_145 != V_147 ) )
V_96 -> V_145 = V_146 ;
if ( ( V_96 -> V_58 != V_148 ) &&
( V_96 -> V_58 != V_56 ) ) {
if ( V_4 -> V_109 . V_138 )
V_96 -> V_58 = V_148 ;
else
V_96 -> V_58 = V_56 ;
}
if ( V_96 -> V_58 == V_148 )
V_140 = 2 ;
if ( V_96 -> V_145 == V_147 )
V_144 = 1 ;
else
V_144 = 2 ;
V_143 = V_4 -> V_109 . V_120 ;
V_142 = V_4 -> V_109 . V_135 ;
V_141 /= V_144 ;
if ( ! V_96 -> V_112 || ( V_96 -> V_112 < V_141 ) ||
( V_96 -> V_112 > V_143 ) ) {
V_96 -> V_112 = V_4 -> V_109 . V_120 ;
}
if ( ! V_96 -> V_114 || ( V_96 -> V_114 < V_140 ) ||
( V_96 -> V_114 > V_142 ) ) {
V_96 -> V_114 = V_4 -> V_109 . V_135 ;
}
if ( V_96 -> V_149 < ( V_96 -> V_112 * V_144 ) )
V_96 -> V_149 = V_96 -> V_112 * V_144 ;
V_96 -> V_149 = ( ( V_96 -> V_112 * V_144 + 31 ) & ~ 31 ) ;
if ( V_96 -> V_145 == V_147 )
V_96 -> V_64 = V_96 -> V_149 * V_96 -> V_114 +
( V_96 -> V_149 * V_96 -> V_114 >> 1 ) ;
else
V_96 -> V_64 = V_96 -> V_149 * V_96 -> V_114 ;
return 0 ;
}
static int F_40 ( struct V_150 * V_150 , void * V_151 ,
struct V_152 * V_153 )
{
struct V_13 * V_14 = F_41 ( V_150 ) ;
struct V_3 * V_4 = V_14 -> V_2 -> V_4 ;
V_153 -> V_154 = V_155 | V_156 ;
V_153 -> V_157 = V_153 -> V_154 | V_158 ;
snprintf ( V_153 -> V_159 , sizeof( V_153 -> V_159 ) , L_10 ,
F_42 ( V_4 -> V_160 ) ) ;
snprintf ( V_153 -> V_161 , sizeof( V_153 -> V_161 ) , L_11 ,
F_42 ( V_4 -> V_160 ) ) ;
F_43 ( V_153 -> V_162 , V_4 -> V_92 -> V_163 , sizeof( V_153 -> V_162 ) ) ;
return 0 ;
}
static int F_44 ( struct V_150 * V_150 , void * V_151 ,
const struct V_164 * V_165 )
{
struct V_13 * V_14 = F_41 ( V_150 ) ;
struct V_1 * V_2 = V_14 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_91 * V_92 = & V_14 -> V_39 . V_93 ;
struct V_27 * V_28 = V_2 -> V_28 ;
struct V_136 V_166 = V_165 -> V_137 ;
int V_5 ;
F_18 ( 1 , V_63 , & V_4 -> V_11 ,
L_12 , V_14 -> V_88 ) ;
if ( V_165 -> type != V_167 ) {
F_3 ( & V_4 -> V_11 , L_13 ) ;
return - V_65 ;
}
if ( V_166 . V_131 < 0 )
V_166 . V_131 = 0 ;
if ( V_166 . V_132 < 0 )
V_166 . V_132 = 0 ;
F_38 ( V_2 , & V_166 ) ;
V_28 -> V_37 . V_168 ( V_28 ,
V_14 -> V_39 . V_40 , V_92 ) ;
F_35 ( V_2 , V_14 ,
V_166 . V_112 ,
V_166 . V_114 ) ;
F_36 ( V_2 , V_14 , V_166 . V_131 ,
V_166 . V_132 ) ;
V_5 = V_28 -> V_37 . V_169 ( V_28 ,
V_14 -> V_39 . V_40 , V_92 ) ;
if ( V_5 < 0 ) {
F_3 ( & V_4 -> V_11 ,
L_14 ) ;
return - V_65 ;
}
V_28 -> V_37 . V_170 ( V_28 ,
V_14 -> V_39 . V_40 ,
V_14 -> V_39 . V_115 ,
V_14 -> V_39 . V_117 ) ;
V_5 = V_28 -> V_37 . V_171 ( V_28 ,
V_14 -> V_39 . V_104 ,
V_14 -> V_39 . V_105 ) ;
if ( V_5 < 0 ) {
F_3 ( & V_4 -> V_11 ,
L_15 ) ;
return - V_65 ;
}
if ( ( V_14 -> V_39 . V_115 != V_116 ) ||
( V_14 -> V_39 . V_117 != V_116 ) ||
( V_14 -> V_39 . V_104 != V_118 ) ||
( V_14 -> V_39 . V_105 != V_119 ) )
V_28 -> V_37 . V_172 ( V_28 , 1 ) ;
else
V_28 -> V_37 . V_172 ( V_28 , 0 ) ;
return 0 ;
}
static int F_45 ( struct V_150 * V_150 , void * V_151 ,
struct V_164 * V_165 )
{
struct V_13 * V_14 = F_41 ( V_150 ) ;
struct V_91 * V_92 = & V_14 -> V_39 . V_93 ;
struct V_3 * V_4 = V_14 -> V_2 -> V_4 ;
struct V_27 * V_28 = V_14 -> V_2 -> V_28 ;
struct V_136 * V_166 = & V_165 -> V_137 ;
F_18 ( 1 , V_63 , & V_4 -> V_11 ,
L_16 ,
V_14 -> V_88 ) ;
if ( V_165 -> type != V_167 ) {
F_3 ( & V_4 -> V_11 , L_13 ) ;
return - V_65 ;
}
V_28 -> V_37 . V_168 ( V_28 ,
V_14 -> V_39 . V_40 , V_92 ) ;
V_166 -> V_131 = V_92 -> V_134 ;
V_166 -> V_132 = V_92 -> V_133 ;
V_166 -> V_112 = V_92 -> V_111 ;
V_166 -> V_114 = V_92 -> V_113 ;
return 0 ;
}
static int F_46 ( struct V_150 * V_150 , void * V_151 ,
struct V_173 * V_174 )
{
struct V_13 * V_14 = F_41 ( V_150 ) ;
struct V_3 * V_4 = V_14 -> V_2 -> V_4 ;
F_18 ( 1 , V_63 , & V_4 -> V_11 , L_17 ) ;
V_174 -> type = V_167 ;
V_174 -> V_175 . V_132 = 0 ;
V_174 -> V_175 . V_131 = 0 ;
V_174 -> V_175 . V_112 = V_4 -> V_109 . V_120 ;
V_174 -> V_175 . V_114 = V_4 -> V_109 . V_135 ;
V_174 -> V_176 = V_4 -> V_109 . V_177 ;
V_174 -> V_178 = V_174 -> V_175 ;
return 0 ;
}
static int F_47 ( struct V_150 * V_150 , void * V_151 ,
struct V_67 * V_68 )
{
struct V_13 * V_14 = F_41 ( V_150 ) ;
struct V_3 * V_4 = V_14 -> V_2 -> V_4 ;
F_18 ( 1 , V_63 , & V_4 -> V_11 ,
L_18 ,
V_14 -> V_88 ) ;
if ( V_167 != V_68 -> type ) {
F_3 ( & V_4 -> V_11 , L_19 ) ;
return - V_65 ;
}
V_68 -> V_68 . V_73 = V_14 -> V_57 ;
return 0 ;
}
static int F_48 ( struct V_150 * V_150 , void * V_151 ,
struct V_179 * V_68 )
{
struct V_13 * V_14 = F_41 ( V_150 ) ;
struct V_3 * V_4 = V_14 -> V_2 -> V_4 ;
unsigned int V_180 = 0 ;
F_18 ( 1 , V_63 , & V_4 -> V_11 ,
L_20 ,
V_14 -> V_88 ) ;
if ( V_68 -> V_180 > 1 ) {
F_3 ( & V_4 -> V_11 , L_21 ) ;
return - V_65 ;
}
V_180 = V_68 -> V_180 ;
memset ( V_68 , 0 , sizeof( * V_68 ) ) ;
V_68 -> V_180 = V_180 ;
V_68 -> type = V_167 ;
if ( V_180 == 0 ) {
strcpy ( V_68 -> V_181 , L_22 ) ;
V_68 -> V_145 = V_146 ;
} else {
strcpy ( V_68 -> V_181 , L_23 ) ;
V_68 -> V_145 = V_147 ;
}
return 0 ;
}
static int F_49 ( struct V_150 * V_150 , void * V_151 ,
struct V_67 * V_68 )
{
struct V_13 * V_14 = F_41 ( V_150 ) ;
struct V_1 * V_2 = V_14 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_91 * V_92 = & V_14 -> V_39 . V_93 ;
struct V_102 * V_96 = & V_68 -> V_68 . V_73 ;
struct V_27 * V_28 = V_2 -> V_28 ;
int V_5 ;
F_18 ( 1 , V_63 , & V_4 -> V_11 ,
L_24 ,
V_14 -> V_88 ) ;
if ( F_50 ( & V_14 -> V_54 ) )
return - V_182 ;
if ( V_167 != V_68 -> type ) {
F_18 ( 1 , V_63 , & V_4 -> V_11 , L_19 ) ;
return - V_65 ;
}
V_5 = F_39 ( V_2 , V_96 , 1 ) ;
if ( V_5 )
return V_5 ;
V_14 -> V_57 = * V_96 ;
if ( V_96 -> V_145 == V_147 ) {
struct V_13 * V_98 ;
V_98 = F_34 ( V_2 , V_14 ) ;
V_5 = V_28 -> V_37 . V_183 ( V_28 ,
V_98 -> V_39 . V_40 ) ;
if ( V_5 < 0 ) {
F_3 ( & V_4 -> V_11 ,
L_25 ) ;
return - V_182 ;
}
}
V_28 -> V_37 . V_168 ( V_28 ,
V_14 -> V_39 . V_40 , V_92 ) ;
V_92 -> V_111 = V_96 -> V_112 ;
V_92 -> V_113 = V_96 -> V_114 ;
V_92 -> V_184 = V_96 -> V_149 ;
V_92 -> V_134 = 0 ;
V_92 -> V_133 = 0 ;
V_92 -> V_138 = V_4 -> V_109 . V_138 ;
if ( V_146 == V_96 -> V_145 )
V_92 -> V_96 = V_185 ;
if ( V_147 == V_96 -> V_145 ) {
struct V_13 * V_98 ;
V_92 -> V_96 = V_97 ;
V_98 = F_34 ( V_2 ,
V_14 ) ;
V_98 -> V_39 . V_93 . V_96 = V_97 ;
}
V_5 = V_28 -> V_37 . V_169 ( V_28 ,
V_14 -> V_39 . V_40 , V_92 ) ;
if ( V_5 < 0 ) {
F_3 ( & V_4 -> V_11 ,
L_26 ) ;
return - V_65 ;
}
V_28 -> V_37 . V_168 ( V_28 ,
V_14 -> V_39 . V_40 , V_92 ) ;
return 0 ;
}
static int F_51 ( struct V_150 * V_150 , void * V_151 ,
struct V_67 * V_68 )
{
struct V_13 * V_14 = F_41 ( V_150 ) ;
struct V_1 * V_2 = V_14 -> V_2 ;
struct V_3 * V_4 = V_14 -> V_2 -> V_4 ;
struct V_102 * V_96 = & V_68 -> V_68 . V_73 ;
F_18 ( 1 , V_63 , & V_4 -> V_11 , L_27 ) ;
if ( V_167 != V_68 -> type ) {
F_3 ( & V_4 -> V_11 , L_19 ) ;
return - V_65 ;
}
return F_39 ( V_2 , V_96 , 0 ) ;
}
static int F_52 ( struct V_150 * V_150 , void * V_151 ,
T_2 V_110 )
{
struct V_13 * V_14 = F_41 ( V_150 ) ;
struct V_3 * V_4 = V_14 -> V_2 -> V_4 ;
int V_5 ;
F_18 ( 1 , V_63 , & V_4 -> V_11 , L_28 ) ;
if ( F_50 ( & V_14 -> V_54 ) )
return - V_182 ;
if ( NULL != V_4 -> V_37 . V_186 ) {
V_5 = V_4 -> V_37 . V_186 ( V_4 , V_110 ) ;
if ( V_5 ) {
F_3 ( & V_4 -> V_11 ,
L_29 ) ;
return - V_65 ;
}
} else {
return - V_65 ;
}
return 0 ;
}
static int F_53 ( struct V_150 * V_150 , void * V_151 ,
T_2 * V_110 )
{
struct V_13 * V_14 = F_41 ( V_150 ) ;
struct V_3 * V_4 = V_14 -> V_2 -> V_4 ;
F_18 ( 1 , V_63 , & V_4 -> V_11 , L_30 ) ;
if ( V_4 -> V_109 . V_187 & V_188 ) {
* V_110 = V_4 -> V_109 . V_110 ;
return 0 ;
}
return - V_65 ;
}
static int F_54 ( struct V_150 * V_150 , void * V_151 ,
struct V_189 * V_190 )
{
struct V_13 * V_14 = F_41 ( V_150 ) ;
struct V_3 * V_4 = V_14 -> V_2 -> V_4 ;
int V_5 ;
F_18 ( 1 , V_63 , & V_4 -> V_11 , L_31 ) ;
if ( NULL == V_4 -> V_37 . V_191 )
return - V_65 ;
V_5 = V_4 -> V_37 . V_191 ( V_4 , V_190 ) ;
if ( V_5 ) {
F_18 ( 1 , V_63 , & V_4 -> V_11 ,
L_32 ) ;
return - V_65 ;
}
return 0 ;
}
static int F_55 ( struct V_150 * V_150 , void * V_151 ,
unsigned int V_47 )
{
struct V_13 * V_14 = F_41 ( V_150 ) ;
struct V_3 * V_4 = V_14 -> V_2 -> V_4 ;
int V_5 ;
F_18 ( 1 , V_63 , & V_4 -> V_11 , L_33 ) ;
if ( F_50 ( & V_14 -> V_54 ) )
return - V_182 ;
if ( NULL == V_4 -> V_37 . V_192 )
return - V_65 ;
V_5 = V_4 -> V_37 . V_192 ( V_4 , V_47 ) ;
if ( V_5 ) {
F_3 ( & V_4 -> V_11 ,
L_34 ) ;
return - V_65 ;
}
return 0 ;
}
static int F_56 ( struct V_150 * V_150 , void * V_151 ,
unsigned int * V_47 )
{
struct V_13 * V_14 = F_41 ( V_150 ) ;
struct V_3 * V_4 = V_14 -> V_2 -> V_4 ;
F_18 ( 1 , V_63 , & V_4 -> V_11 , L_35 ) ;
* V_47 = V_4 -> V_193 ;
return 0 ;
}
static int
F_57 ( struct V_150 * V_150 , void * V_151 ,
struct V_194 * V_195 )
{
struct V_13 * V_14 = F_41 ( V_150 ) ;
struct V_3 * V_4 = V_14 -> V_2 -> V_4 ;
int V_5 ;
F_18 ( 1 , V_63 , & V_4 -> V_11 , L_36 ) ;
if ( NULL == V_4 -> V_37 . V_196 )
return - V_65 ;
V_5 = V_4 -> V_37 . V_196 ( V_4 , V_195 ) ;
if ( V_5 ) {
F_3 ( & V_4 -> V_11 ,
L_37 ) ;
return - V_65 ;
}
return 0 ;
}
static int
F_58 ( struct V_150 * V_150 , void * V_151 ,
struct V_197 * V_195 )
{
struct V_13 * V_14 = F_41 ( V_150 ) ;
struct V_3 * V_4 = V_14 -> V_2 -> V_4 ;
int V_5 ;
F_18 ( 1 , V_63 , & V_4 -> V_11 , L_38 ) ;
if ( F_50 ( & V_14 -> V_54 ) )
return - V_182 ;
if ( ! V_4 -> V_37 . V_198 )
return - V_65 ;
V_5 = V_4 -> V_37 . V_198 ( V_4 , V_195 ) ;
if ( V_5 ) {
F_3 ( & V_4 -> V_11 ,
L_39 ) ;
return - V_65 ;
}
return 0 ;
}
static int
F_59 ( struct V_150 * V_150 , void * V_151 ,
struct V_197 * V_199 )
{
struct V_13 * V_14 = F_41 ( V_150 ) ;
struct V_3 * V_4 = V_14 -> V_2 -> V_4 ;
F_18 ( 1 , V_63 , & V_4 -> V_11 , L_40 ) ;
if ( V_4 -> V_109 . V_187 &
V_200 ) {
* V_199 = V_4 -> V_109 . V_199 ;
} else {
return - V_65 ;
}
return 0 ;
}
static int F_60 ( struct V_150 * V_150 )
{
struct V_13 * V_14 = F_41 ( V_150 ) ;
struct V_1 * V_2 = V_14 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_27 * V_28 = V_2 -> V_28 ;
int V_201 ;
V_201 = F_61 ( V_150 ) ;
if ( V_201 ) {
F_3 ( & V_4 -> V_11 , L_41 ) ;
return V_201 ;
}
if ( ! F_62 ( V_150 ) )
return V_201 ;
if ( ! V_14 -> V_202 ) {
if ( F_63 ( & V_14 -> V_203 ) )
return - V_204 ;
V_201 = V_28 -> V_37 . V_183 ( V_28 ,
V_14 -> V_39 . V_40 ) ;
F_64 ( & V_14 -> V_203 ) ;
if ( V_201 < 0 ) {
F_3 ( & V_4 -> V_11 ,
L_25 ) ;
F_65 ( V_150 ) ;
return - V_65 ;
}
}
V_14 -> V_202 ++ ;
F_18 ( 1 , V_63 , & V_4 -> V_11 ,
L_42 ) ;
return 0 ;
}
static int F_66 ( struct V_150 * V_150 )
{
struct V_13 * V_14 = F_41 ( V_150 ) ;
struct V_91 * V_92 = & V_14 -> V_39 . V_93 ;
struct V_1 * V_2 = V_14 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_27 * V_28 = V_2 -> V_28 ;
F_18 ( 1 , V_63 , & V_4 -> V_11 , L_43 ) ;
F_67 ( & V_14 -> V_203 ) ;
V_28 -> V_37 . V_81 ( V_28 ,
V_14 -> V_39 . V_40 ) ;
V_14 -> V_202 -- ;
if ( ! V_14 -> V_202 ) {
if ( V_92 -> V_96 == V_97 ) {
struct V_13 * V_98 ;
V_98 =
F_34 ( V_2 , V_14 ) ;
V_28 -> V_37 . V_81 ( V_28 ,
V_98 -> V_39 . V_40 ) ;
V_28 -> V_37 . V_205 ( V_28 ,
V_98 -> V_39 . V_40 ) ;
}
V_28 -> V_37 . V_81 ( V_28 ,
V_14 -> V_39 . V_40 ) ;
V_28 -> V_37 . V_205 ( V_28 ,
V_14 -> V_39 . V_40 ) ;
}
F_68 ( V_150 , NULL ) ;
F_64 ( & V_14 -> V_203 ) ;
V_2 -> V_41 = 0 ;
return 0 ;
}
static int F_69 ( struct V_206 * V_48 , void * V_207 )
{
struct V_208 * V_160 = F_70 ( V_48 ) ;
struct V_1 * V_209 = V_207 ;
if ( strcmp ( L_44 , V_160 -> V_210 ) == 0 )
V_209 -> V_4 = F_71 ( V_160 ) ;
if ( strstr ( V_160 -> V_210 , L_45 ) != NULL )
V_209 -> V_28 = F_71 ( V_160 ) ;
return 0 ;
}
static int F_72 ( int V_47 , struct V_1 * V_2 ,
struct V_208 * V_160 )
{
struct V_13 * V_211 = NULL ;
struct V_212 * V_213 = NULL ;
V_2 -> V_48 [ V_47 ] =
F_73 ( sizeof( struct V_13 ) , V_214 ) ;
if ( ! V_2 -> V_48 [ V_47 ] ) {
F_74 ( V_215 L_46 ) ;
return - V_216 ;
}
F_75 ( & V_2 -> V_48 [ V_47 ] -> V_217 ) ;
F_76 ( & V_2 -> V_48 [ V_47 ] -> V_203 ) ;
V_211 = V_2 -> V_48 [ V_47 ] ;
V_213 = & V_211 -> V_218 ;
V_213 -> V_219 = V_220 ;
V_213 -> V_221 = & V_222 ;
V_213 -> V_223 = & V_224 ;
V_213 -> V_225 = - 1 ;
V_213 -> V_11 = & V_2 -> V_4 -> V_11 ;
V_213 -> V_226 = & V_211 -> V_203 ;
V_213 -> V_227 = V_228 ;
if ( V_2 -> V_4 -> V_109 . V_187 &
V_188 )
V_213 -> V_229 = ( V_121 | V_122 ) ;
snprintf ( V_213 -> V_210 , sizeof( V_213 -> V_210 ) ,
L_47 ,
( V_230 >> 16 ) & 0xff ,
( V_230 >> 8 ) & 0xff ,
( V_230 ) & 0xff ) ;
V_211 -> V_88 = V_47 ;
V_211 -> V_39 . V_40 =
( ( V_47 == V_89 ) ? V_231 : V_232 ) ;
return 0 ;
}
static int F_77 ( struct V_13 * V_211 ,
struct V_1 * V_2 ,
struct V_208 * V_160 )
{
int V_201 ;
F_78 ( & V_2 -> V_4 -> V_11 ,
L_48 ) ;
F_78 ( & V_2 -> V_4 -> V_11 ,
L_49 ,
( int ) V_211 ,
( int ) & V_211 -> V_218 ) ;
V_211 -> V_218 . V_233 = & V_211 -> V_54 ;
V_201 = F_79 ( & V_211 -> V_218 ,
V_234 ,
- 1 ) ;
if ( V_201 )
return - V_235 ;
V_211 -> V_2 = V_2 ;
F_80 ( V_160 , V_2 ) ;
F_81 ( & V_211 -> V_218 ,
V_211 ) ;
return 0 ;
}
static int F_82 ( struct V_208 * V_160 )
{
struct V_1 * V_2 ;
struct V_236 * V_11 ;
struct V_237 * V_238 = NULL ;
struct V_61 * V_62 ;
int V_239 ;
int V_47 ;
int V_201 ;
int V_42 ;
F_74 ( V_240 L_50 ) ;
V_2 = F_83 ( & V_160 -> V_48 , sizeof( struct V_1 ) ,
V_214 ) ;
if ( ! V_2 )
return - V_216 ;
F_75 ( & V_2 -> V_30 ) ;
V_201 = F_84 ( & V_241 , NULL , V_2 ,
F_69 ) ;
if ( V_201 < 0 )
return V_201 ;
V_11 = & V_2 -> V_4 -> V_11 ;
if ( NULL != V_2 -> V_4 -> V_37 . V_242 ) {
V_201 = V_2 -> V_4 -> V_37 . V_242 ( & V_160 -> V_48 ,
V_2 -> V_4 ) ;
if ( V_201 ) {
F_3 ( V_11 , L_51 ) ;
V_201 = - V_216 ;
goto V_243;
}
}
for ( V_47 = 0 ; V_47 < V_53 ; V_47 ++ ) {
if ( F_72 ( V_47 , V_2 , V_160 ) ) {
V_201 = - V_235 ;
goto V_243;
}
}
V_238 = F_85 ( V_160 , V_244 , 0 ) ;
if ( ! V_238 ) {
F_3 ( V_11 , L_52 ) ;
V_201 = - V_235 ;
goto V_243;
}
V_42 = V_238 -> V_245 ;
V_201 = F_86 ( & V_160 -> V_48 , V_42 , F_14 , 0 ,
V_246 , V_2 ) ;
if ( V_201 ) {
F_3 ( V_11 , L_53 ) ;
goto V_243;
}
for ( V_47 = 0 ; V_47 < V_53 ; V_47 ++ ) {
V_62 = & V_2 -> V_48 [ V_47 ] -> V_54 ;
memset ( V_62 , 0 , sizeof( * V_62 ) ) ;
V_62 -> type = V_167 ;
V_62 -> V_247 = V_248 | V_249 | V_250 ;
V_62 -> V_251 = V_2 -> V_48 [ V_47 ] ;
V_62 -> V_37 = & V_252 ;
V_62 -> V_253 = & V_254 ;
V_62 -> V_255 = sizeof( struct V_33 ) ;
V_62 -> V_256 = V_257 ;
V_62 -> V_258 = 1 ;
V_62 -> V_226 = & V_2 -> V_48 [ V_47 ] -> V_203 ;
V_201 = F_87 ( V_62 ) ;
if ( V_201 ) {
F_3 ( V_11 , L_54 ) ;
goto V_243;
}
V_2 -> V_48 [ V_47 ] -> V_76 =
F_88 ( V_2 -> V_4 -> V_160 ) ;
if ( F_89 ( V_2 -> V_48 [ V_47 ] -> V_76 ) ) {
F_3 ( V_11 , L_55 ) ;
V_201 = F_90 ( V_2 -> V_48 [ V_47 ] -> V_76 ) ;
goto V_243;
}
F_91 ( & V_2 -> V_48 [ V_47 ] -> V_31 ) ;
if ( F_77 ( V_2 -> V_48 [ V_47 ] , V_2 , V_160 ) ) {
V_201 = - V_235 ;
goto V_243;
}
}
F_18 ( 1 , V_63 , V_11 ,
L_56 ) ;
return 0 ;
V_243:
for ( V_239 = 0 ; V_239 < V_53 ; V_239 ++ ) {
if ( V_2 -> V_48 [ V_239 ] != NULL ) {
F_92 ( V_2 -> V_48 [ V_239 ] -> V_76 ) ;
F_93 ( & V_2 -> V_48 [ V_239 ] -> V_218 ) ;
F_94 ( V_2 -> V_48 [ V_239 ] ) ;
}
}
return V_201 ;
}
static int F_95 ( struct V_208 * V_160 )
{
struct V_13 * V_211 ;
struct V_1 * V_2 = F_71 ( V_160 ) ;
struct V_3 * V_4 = V_2 -> V_4 ;
int V_47 ;
F_18 ( 1 , V_63 , & V_4 -> V_11 , L_57 ) ;
if ( NULL != V_4 -> V_37 . V_259 )
V_4 -> V_37 . V_259 ( & V_160 -> V_48 , V_4 ) ;
for ( V_47 = 0 ; V_47 < V_53 ; V_47 ++ ) {
V_211 = V_2 -> V_48 [ V_47 ] ;
F_92 ( V_211 -> V_76 ) ;
F_93 ( & V_211 -> V_218 ) ;
}
for ( V_47 = 0 ; V_47 < V_53 ; V_47 ++ ) {
F_94 ( V_2 -> V_48 [ V_47 ] ) ;
V_2 -> V_48 [ V_47 ] = NULL ;
}
return 0 ;
}
