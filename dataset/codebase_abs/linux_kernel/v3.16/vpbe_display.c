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
int V_5 ;
V_14 -> V_18 = V_14 -> V_17 = F_11 ( V_14 -> V_31 . V_32 ,
struct V_33 , V_34 ) ;
F_12 ( & V_14 -> V_17 -> V_34 ) ;
V_14 -> V_17 -> V_19 . V_35 = V_36 ;
V_14 -> V_59 = 0 ;
V_5 = F_38 ( V_62 -> V_2 , V_14 ) ;
if ( V_5 < 0 ) {
struct V_33 * V_80 , * V_86 ;
F_6 ( & V_14 -> V_17 -> V_19 , V_87 ) ;
F_39 (buf, tmp, &layer->dma_queue, list) {
F_12 ( & V_80 -> V_34 ) ;
F_6 ( & V_80 -> V_19 , V_87 ) ;
}
return V_5 ;
}
V_14 -> V_54 = 1 ;
V_14 -> V_55 = 1 ;
return V_5 ;
}
static void F_40 ( struct V_63 * V_70 )
{
struct V_61 * V_62 = F_16 ( V_70 ) ;
struct V_13 * V_14 = V_62 -> V_14 ;
struct V_1 * V_81 = V_62 -> V_2 ;
unsigned long V_82 ;
if ( ! F_41 ( V_70 ) )
return;
F_26 ( & V_81 -> V_30 , V_82 ) ;
if ( V_14 -> V_17 == V_14 -> V_18 ) {
F_6 ( & V_14 -> V_17 -> V_19 , V_88 ) ;
} else {
if ( V_14 -> V_17 != NULL )
F_6 ( & V_14 -> V_17 -> V_19 ,
V_88 ) ;
if ( V_14 -> V_18 != NULL )
F_6 ( & V_14 -> V_18 -> V_19 ,
V_88 ) ;
}
while ( ! F_9 ( & V_14 -> V_31 ) ) {
V_14 -> V_18 = F_11 ( V_14 -> V_31 . V_32 ,
struct V_33 , V_34 ) ;
F_12 ( & V_14 -> V_18 -> V_34 ) ;
F_6 ( & V_14 -> V_18 -> V_19 , V_88 ) ;
}
F_28 ( & V_81 -> V_30 , V_82 ) ;
}
static
struct V_13 *
F_42 ( struct V_1 * V_2 ,
struct V_13 * V_14 )
{
enum V_89 V_90 , V_91 ;
V_90 = V_14 -> V_92 ;
V_91 = ( V_90 == V_93 ) ?
V_94 : V_93 ;
return V_2 -> V_48 [ V_91 ] ;
}
static int F_38 ( struct V_1 * V_2 ,
struct V_13 * V_14 )
{
struct V_95 * V_96 = & V_14 -> V_39 . V_97 ;
struct V_27 * V_28 = V_2 -> V_28 ;
struct V_3 * V_4 = V_2 -> V_4 ;
unsigned long V_29 ;
int V_5 ;
V_29 = F_13 ( & V_14 -> V_17 -> V_19 , 0 ) ;
V_28 -> V_37 . V_38 ( V_28 ,
V_14 -> V_39 . V_40 ,
V_29 ,
V_2 -> V_41 ) ;
V_5 = V_28 -> V_37 . V_98 ( V_28 ,
V_14 -> V_39 . V_40 , 0 ) ;
if ( V_5 < 0 ) {
F_3 ( & V_4 -> V_11 ,
L_7 ) ;
return - 1 ;
}
V_14 -> V_39 . V_99 = 1 ;
if ( V_96 -> V_100 == V_101 ) {
struct V_13 * V_102 =
F_42 ( V_2 , V_14 ) ;
V_5 = V_28 -> V_37 . V_98 ( V_28 ,
V_102 -> V_39 . V_40 , 1 ) ;
if ( V_5 < 0 ) {
F_3 ( & V_4 -> V_11 ,
L_8 ) ;
return - 1 ;
}
V_102 -> V_39 . V_99 = 1 ;
}
return 0 ;
}
static void
F_43 ( struct V_1 * V_2 ,
struct V_13 * V_14 ,
int V_103 , int V_104 )
{
struct V_105 * V_39 = & V_14 -> V_39 ;
struct V_106 * V_100 = & V_14 -> V_57 ;
struct V_95 * V_96 = & V_14 -> V_39 . V_97 ;
struct V_3 * V_4 = V_2 -> V_4 ;
int V_107 ;
int V_108 = 0 ;
int V_109 = 0 ;
int V_110 ;
int V_111 ;
T_2 V_112 = V_4 -> V_113 . V_114 ;
V_96 -> V_115 = V_100 -> V_116 ;
V_96 -> V_117 = V_100 -> V_118 ;
V_39 -> V_119 = V_120 ;
V_39 -> V_121 = V_120 ;
V_39 -> V_108 = V_122 ;
V_39 -> V_109 = V_123 ;
if ( V_100 -> V_116 < V_103 ) {
V_110 = V_4 -> V_113 . V_124 / V_100 -> V_116 ;
if ( V_110 < 2 )
V_110 = 1 ;
else if ( V_110 >= 4 )
V_110 = 4 ;
else
V_110 = 2 ;
V_96 -> V_115 *= V_110 ;
if ( V_96 -> V_115 < V_103 ) {
if ( ( V_112 & V_125 ) ||
( V_112 & V_126 ) ) {
V_107 = ( V_96 -> V_115 *
V_127 ) /
V_128 ;
if ( V_107 <= V_103 ) {
V_108 = 1 ;
V_96 -> V_115 = V_107 ;
}
}
}
if ( V_110 == 2 )
V_39 -> V_119 = V_129 ;
else if ( V_110 == 4 )
V_39 -> V_119 = V_130 ;
if ( V_108 )
V_39 -> V_108 = V_131 ;
} else {
V_96 -> V_115 = V_103 ;
}
if ( V_100 -> V_118 < V_104 ) {
V_111 = V_104 / V_100 -> V_118 ;
if ( V_111 < 2 )
V_111 = 1 ;
else if ( V_111 >= 4 )
V_111 = 4 ;
else
V_111 = 2 ;
V_96 -> V_117 *= V_111 ;
if ( V_96 -> V_117 < V_104 ) {
if ( ( V_112 & V_126 ) ) {
V_107 = ( V_96 -> V_117 *
V_132 ) /
V_133 ;
if ( V_107 <= V_104 ) {
V_109 = 1 ;
V_96 -> V_117 = V_107 ;
}
}
}
if ( V_111 == 2 )
V_39 -> V_121 = V_129 ;
else if ( V_111 == 4 )
V_39 -> V_121 = V_130 ;
if ( V_109 )
V_39 -> V_108 = V_134 ;
} else {
V_96 -> V_117 = V_104 ;
}
F_17 ( 1 , V_65 , & V_4 -> V_11 ,
L_9 ,
V_96 -> V_115 , V_96 -> V_117 ) ;
}
static void F_44 ( struct V_1 * V_2 ,
struct V_13 * V_14 ,
int V_135 , int V_136 )
{
struct V_95 * V_96 = & V_14 -> V_39 . V_97 ;
struct V_3 * V_4 = V_2 -> V_4 ;
V_96 -> V_137 = F_45 ( ( unsigned int ) V_136 ,
V_4 -> V_113 . V_124 - V_96 -> V_115 ) ;
V_96 -> V_138 = F_45 ( ( unsigned int ) V_135 ,
V_4 -> V_113 . V_139 - V_96 -> V_117 ) ;
F_17 ( 1 , V_65 , & V_4 -> V_11 ,
L_10 ,
V_96 -> V_137 , V_96 -> V_138 ) ;
}
static void F_46 ( struct V_1 * V_2 ,
struct V_140 * V_141 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
if ( ( V_141 -> V_116 == 0 ) ||
( ( V_141 -> V_116 + V_141 -> V_136 ) > V_4 -> V_113 . V_124 ) )
V_141 -> V_116 = V_4 -> V_113 . V_124 - V_141 -> V_136 ;
if ( ( V_141 -> V_118 == 0 ) || ( ( V_141 -> V_118 + V_141 -> V_135 ) >
V_4 -> V_113 . V_139 ) )
V_141 -> V_118 = V_4 -> V_113 . V_139 - V_141 -> V_135 ;
if ( V_4 -> V_113 . V_142 )
V_141 -> V_118 &= ( ~ 0x01 ) ;
}
static int F_47 ( struct V_1 * V_2 ,
struct V_106 * V_100 , int V_143 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
int V_144 = 1 ;
int V_145 = 32 ;
int V_146 ;
int V_147 ;
int V_148 ;
if ( ( V_100 -> V_149 != V_150 ) &&
( V_100 -> V_149 != V_151 ) )
V_100 -> V_149 = V_150 ;
if ( ( V_100 -> V_58 != V_152 ) &&
( V_100 -> V_58 != V_56 ) ) {
if ( V_4 -> V_113 . V_142 )
V_100 -> V_58 = V_152 ;
else
V_100 -> V_58 = V_56 ;
}
if ( V_100 -> V_58 == V_152 )
V_144 = 2 ;
if ( V_100 -> V_149 == V_151 )
V_148 = 1 ;
else
V_148 = 2 ;
V_147 = V_4 -> V_113 . V_124 ;
V_146 = V_4 -> V_113 . V_139 ;
V_145 /= V_148 ;
if ( ! V_100 -> V_116 || ( V_100 -> V_116 < V_145 ) ||
( V_100 -> V_116 > V_147 ) ) {
V_100 -> V_116 = V_4 -> V_113 . V_124 ;
}
if ( ! V_100 -> V_118 || ( V_100 -> V_118 < V_144 ) ||
( V_100 -> V_118 > V_146 ) ) {
V_100 -> V_118 = V_4 -> V_113 . V_139 ;
}
if ( V_100 -> V_153 < ( V_100 -> V_116 * V_148 ) )
V_100 -> V_153 = V_100 -> V_116 * V_148 ;
V_100 -> V_153 = ( ( V_100 -> V_116 * V_148 + 31 ) & ~ 31 ) ;
if ( V_100 -> V_149 == V_151 )
V_100 -> V_67 = V_100 -> V_153 * V_100 -> V_118 +
( V_100 -> V_153 * V_100 -> V_118 >> 1 ) ;
else
V_100 -> V_67 = V_100 -> V_153 * V_100 -> V_118 ;
return 0 ;
}
static int F_48 ( struct V_154 * V_154 , void * V_155 ,
struct V_156 * V_157 )
{
struct V_61 * V_62 = V_154 -> V_158 ;
struct V_3 * V_4 = V_62 -> V_2 -> V_4 ;
V_157 -> V_159 = V_160 ;
V_157 -> V_161 = V_162 | V_163 ;
V_157 -> V_164 = V_157 -> V_161 | V_165 ;
snprintf ( V_157 -> V_166 , sizeof( V_157 -> V_166 ) , L_11 ,
F_49 ( V_4 -> V_167 ) ) ;
snprintf ( V_157 -> V_168 , sizeof( V_157 -> V_168 ) , L_12 ,
F_49 ( V_4 -> V_167 ) ) ;
F_50 ( V_157 -> V_169 , V_4 -> V_96 -> V_170 , sizeof( V_157 -> V_169 ) ) ;
return 0 ;
}
static int F_51 ( struct V_154 * V_154 , void * V_155 ,
const struct V_171 * V_172 )
{
struct V_61 * V_62 = V_154 -> V_158 ;
struct V_13 * V_14 = V_62 -> V_14 ;
struct V_1 * V_2 = V_62 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_95 * V_96 = & V_14 -> V_39 . V_97 ;
struct V_27 * V_28 = V_2 -> V_28 ;
struct V_140 V_173 = V_172 -> V_141 ;
int V_5 ;
F_17 ( 1 , V_65 , & V_4 -> V_11 ,
L_13 , V_14 -> V_92 ) ;
if ( V_172 -> type != V_174 ) {
F_3 ( & V_4 -> V_11 , L_14 ) ;
return - V_68 ;
}
if ( V_173 . V_135 < 0 )
V_173 . V_135 = 0 ;
if ( V_173 . V_136 < 0 )
V_173 . V_136 = 0 ;
F_46 ( V_2 , & V_173 ) ;
V_28 -> V_37 . V_175 ( V_28 ,
V_14 -> V_39 . V_40 , V_96 ) ;
F_43 ( V_2 , V_14 ,
V_173 . V_116 ,
V_173 . V_118 ) ;
F_44 ( V_2 , V_14 , V_173 . V_135 ,
V_173 . V_136 ) ;
V_5 = V_28 -> V_37 . V_176 ( V_28 ,
V_14 -> V_39 . V_40 , V_96 ) ;
if ( V_5 < 0 ) {
F_3 ( & V_4 -> V_11 ,
L_15 ) ;
return - V_68 ;
}
V_28 -> V_37 . V_177 ( V_28 ,
V_14 -> V_39 . V_40 ,
V_14 -> V_39 . V_119 ,
V_14 -> V_39 . V_121 ) ;
V_5 = V_28 -> V_37 . V_178 ( V_28 ,
V_14 -> V_39 . V_108 ,
V_14 -> V_39 . V_109 ) ;
if ( V_5 < 0 ) {
F_3 ( & V_4 -> V_11 ,
L_16 ) ;
return - V_68 ;
}
if ( ( V_14 -> V_39 . V_119 != V_120 ) ||
( V_14 -> V_39 . V_121 != V_120 ) ||
( V_14 -> V_39 . V_108 != V_122 ) ||
( V_14 -> V_39 . V_109 != V_123 ) )
V_28 -> V_37 . V_179 ( V_28 , 1 ) ;
else
V_28 -> V_37 . V_179 ( V_28 , 0 ) ;
return 0 ;
}
static int F_52 ( struct V_154 * V_154 , void * V_155 ,
struct V_171 * V_172 )
{
struct V_61 * V_62 = V_154 -> V_158 ;
struct V_13 * V_14 = V_62 -> V_14 ;
struct V_95 * V_96 = & V_14 -> V_39 . V_97 ;
struct V_3 * V_4 = V_62 -> V_2 -> V_4 ;
struct V_27 * V_28 = V_62 -> V_2 -> V_28 ;
struct V_140 * V_173 = & V_172 -> V_141 ;
F_17 ( 1 , V_65 , & V_4 -> V_11 ,
L_17 ,
V_14 -> V_92 ) ;
if ( V_172 -> type != V_174 ) {
F_3 ( & V_4 -> V_11 , L_14 ) ;
return - V_68 ;
}
V_28 -> V_37 . V_175 ( V_28 ,
V_14 -> V_39 . V_40 , V_96 ) ;
V_173 -> V_135 = V_96 -> V_138 ;
V_173 -> V_136 = V_96 -> V_137 ;
V_173 -> V_116 = V_96 -> V_115 ;
V_173 -> V_118 = V_96 -> V_117 ;
return 0 ;
}
static int F_53 ( struct V_154 * V_154 , void * V_155 ,
struct V_180 * V_181 )
{
struct V_61 * V_62 = V_154 -> V_158 ;
struct V_3 * V_4 = V_62 -> V_2 -> V_4 ;
F_17 ( 1 , V_65 , & V_4 -> V_11 , L_18 ) ;
V_181 -> type = V_174 ;
V_181 -> V_182 . V_136 = 0 ;
V_181 -> V_182 . V_135 = 0 ;
V_181 -> V_182 . V_116 = V_4 -> V_113 . V_124 ;
V_181 -> V_182 . V_118 = V_4 -> V_113 . V_139 ;
V_181 -> V_183 = V_4 -> V_113 . V_184 ;
V_181 -> V_185 = V_181 -> V_182 ;
return 0 ;
}
static int F_54 ( struct V_154 * V_154 , void * V_155 ,
struct V_71 * V_72 )
{
struct V_61 * V_62 = V_154 -> V_158 ;
struct V_13 * V_14 = V_62 -> V_14 ;
struct V_3 * V_4 = V_62 -> V_2 -> V_4 ;
F_17 ( 1 , V_65 , & V_4 -> V_11 ,
L_19 ,
V_14 -> V_92 ) ;
if ( V_174 != V_72 -> type ) {
F_3 ( & V_4 -> V_11 , L_20 ) ;
return - V_68 ;
}
V_72 -> V_72 . V_186 = V_14 -> V_57 ;
return 0 ;
}
static int F_55 ( struct V_154 * V_154 , void * V_155 ,
struct V_187 * V_72 )
{
struct V_61 * V_62 = V_154 -> V_158 ;
struct V_13 * V_14 = V_62 -> V_14 ;
struct V_3 * V_4 = V_62 -> V_2 -> V_4 ;
unsigned int V_188 = 0 ;
F_17 ( 1 , V_65 , & V_4 -> V_11 ,
L_21 ,
V_14 -> V_92 ) ;
if ( V_72 -> V_188 > 1 ) {
F_3 ( & V_4 -> V_11 , L_22 ) ;
return - V_68 ;
}
V_188 = V_72 -> V_188 ;
memset ( V_72 , 0 , sizeof( * V_72 ) ) ;
V_72 -> V_188 = V_188 ;
V_72 -> type = V_174 ;
if ( V_188 == 0 ) {
strcpy ( V_72 -> V_189 , L_23 ) ;
V_72 -> V_149 = V_150 ;
} else {
strcpy ( V_72 -> V_189 , L_24 ) ;
V_72 -> V_149 = V_151 ;
}
return 0 ;
}
static int F_56 ( struct V_154 * V_154 , void * V_155 ,
struct V_71 * V_72 )
{
struct V_61 * V_62 = V_154 -> V_158 ;
struct V_13 * V_14 = V_62 -> V_14 ;
struct V_1 * V_2 = V_62 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_95 * V_96 = & V_14 -> V_39 . V_97 ;
struct V_106 * V_100 = & V_72 -> V_72 . V_186 ;
struct V_27 * V_28 = V_2 -> V_28 ;
int V_5 ;
F_17 ( 1 , V_65 , & V_4 -> V_11 ,
L_25 ,
V_14 -> V_92 ) ;
if ( V_14 -> V_54 ) {
F_3 ( & V_4 -> V_11 , L_26 ) ;
return - V_190 ;
}
if ( V_174 != V_72 -> type ) {
F_17 ( 1 , V_65 , & V_4 -> V_11 , L_20 ) ;
return - V_68 ;
}
V_5 = F_47 ( V_2 , V_100 , 1 ) ;
if ( V_5 )
return V_5 ;
V_14 -> V_57 = * V_100 ;
if ( V_100 -> V_149 == V_151 ) {
struct V_13 * V_102 ;
V_102 = F_42 ( V_2 , V_14 ) ;
V_5 = V_28 -> V_37 . V_191 ( V_28 ,
V_102 -> V_39 . V_40 ) ;
if ( V_5 < 0 ) {
F_3 ( & V_4 -> V_11 ,
L_27 ) ;
return - V_190 ;
}
}
V_28 -> V_37 . V_175 ( V_28 ,
V_14 -> V_39 . V_40 , V_96 ) ;
V_96 -> V_115 = V_100 -> V_116 ;
V_96 -> V_117 = V_100 -> V_118 ;
V_96 -> V_192 = V_100 -> V_153 ;
V_96 -> V_138 = 0 ;
V_96 -> V_137 = 0 ;
V_96 -> V_142 = V_4 -> V_113 . V_142 ;
if ( V_150 == V_100 -> V_149 )
V_96 -> V_100 = V_193 ;
if ( V_151 == V_100 -> V_149 ) {
struct V_13 * V_102 ;
V_96 -> V_100 = V_101 ;
V_102 = F_42 ( V_2 ,
V_14 ) ;
V_102 -> V_39 . V_97 . V_100 = V_101 ;
}
V_5 = V_28 -> V_37 . V_176 ( V_28 ,
V_14 -> V_39 . V_40 , V_96 ) ;
if ( V_5 < 0 ) {
F_3 ( & V_4 -> V_11 ,
L_28 ) ;
return - V_68 ;
}
V_28 -> V_37 . V_175 ( V_28 ,
V_14 -> V_39 . V_40 , V_96 ) ;
return 0 ;
}
static int F_57 ( struct V_154 * V_154 , void * V_155 ,
struct V_71 * V_72 )
{
struct V_61 * V_62 = V_154 -> V_158 ;
struct V_1 * V_2 = V_62 -> V_2 ;
struct V_3 * V_4 = V_62 -> V_2 -> V_4 ;
struct V_106 * V_100 = & V_72 -> V_72 . V_186 ;
F_17 ( 1 , V_65 , & V_4 -> V_11 , L_29 ) ;
if ( V_174 != V_72 -> type ) {
F_3 ( & V_4 -> V_11 , L_20 ) ;
return - V_68 ;
}
return F_47 ( V_2 , V_100 , 0 ) ;
}
static int F_58 ( struct V_154 * V_154 , void * V_155 ,
T_2 V_114 )
{
struct V_61 * V_62 = V_155 ;
struct V_13 * V_14 = V_62 -> V_14 ;
struct V_3 * V_4 = V_62 -> V_2 -> V_4 ;
int V_5 ;
F_17 ( 1 , V_65 , & V_4 -> V_11 , L_30 ) ;
if ( V_14 -> V_54 ) {
F_3 ( & V_4 -> V_11 , L_26 ) ;
return - V_190 ;
}
if ( NULL != V_4 -> V_37 . V_194 ) {
V_5 = V_4 -> V_37 . V_194 ( V_4 , V_114 ) ;
if ( V_5 ) {
F_3 ( & V_4 -> V_11 ,
L_31 ) ;
return - V_68 ;
}
} else {
return - V_68 ;
}
return 0 ;
}
static int F_59 ( struct V_154 * V_154 , void * V_155 ,
T_2 * V_114 )
{
struct V_61 * V_62 = V_155 ;
struct V_3 * V_4 = V_62 -> V_2 -> V_4 ;
F_17 ( 1 , V_65 , & V_4 -> V_11 , L_32 ) ;
if ( V_4 -> V_113 . V_195 & V_196 ) {
* V_114 = V_4 -> V_113 . V_114 ;
return 0 ;
}
return - V_68 ;
}
static int F_60 ( struct V_154 * V_154 , void * V_155 ,
struct V_197 * V_198 )
{
struct V_61 * V_62 = V_155 ;
struct V_3 * V_4 = V_62 -> V_2 -> V_4 ;
int V_5 ;
F_17 ( 1 , V_65 , & V_4 -> V_11 , L_33 ) ;
if ( NULL == V_4 -> V_37 . V_199 )
return - V_68 ;
V_5 = V_4 -> V_37 . V_199 ( V_4 , V_198 ) ;
if ( V_5 ) {
F_17 ( 1 , V_65 , & V_4 -> V_11 ,
L_34 ) ;
return - V_68 ;
}
return 0 ;
}
static int F_61 ( struct V_154 * V_154 , void * V_155 ,
unsigned int V_47 )
{
struct V_61 * V_62 = V_155 ;
struct V_13 * V_14 = V_62 -> V_14 ;
struct V_3 * V_4 = V_62 -> V_2 -> V_4 ;
int V_5 ;
F_17 ( 1 , V_65 , & V_4 -> V_11 , L_35 ) ;
if ( V_14 -> V_54 ) {
F_3 ( & V_4 -> V_11 , L_26 ) ;
return - V_190 ;
}
if ( NULL == V_4 -> V_37 . V_200 )
return - V_68 ;
V_5 = V_4 -> V_37 . V_200 ( V_4 , V_47 ) ;
if ( V_5 ) {
F_3 ( & V_4 -> V_11 ,
L_36 ) ;
return - V_68 ;
}
return 0 ;
}
static int F_62 ( struct V_154 * V_154 , void * V_155 ,
unsigned int * V_47 )
{
struct V_61 * V_62 = V_155 ;
struct V_3 * V_4 = V_62 -> V_2 -> V_4 ;
F_17 ( 1 , V_65 , & V_4 -> V_11 , L_37 ) ;
* V_47 = V_4 -> V_201 ;
return 0 ;
}
static int
F_63 ( struct V_154 * V_154 , void * V_155 ,
struct V_202 * V_203 )
{
struct V_61 * V_62 = V_155 ;
struct V_3 * V_4 = V_62 -> V_2 -> V_4 ;
int V_5 ;
F_17 ( 1 , V_65 , & V_4 -> V_11 , L_38 ) ;
if ( NULL == V_4 -> V_37 . V_204 )
return - V_68 ;
V_5 = V_4 -> V_37 . V_204 ( V_4 , V_203 ) ;
if ( V_5 ) {
F_3 ( & V_4 -> V_11 ,
L_39 ) ;
return - V_68 ;
}
return 0 ;
}
static int
F_64 ( struct V_154 * V_154 , void * V_155 ,
struct V_205 * V_203 )
{
struct V_61 * V_62 = V_155 ;
struct V_13 * V_14 = V_62 -> V_14 ;
struct V_3 * V_4 = V_62 -> V_2 -> V_4 ;
int V_5 ;
F_17 ( 1 , V_65 , & V_4 -> V_11 , L_40 ) ;
if ( V_14 -> V_54 ) {
F_3 ( & V_4 -> V_11 , L_26 ) ;
return - V_190 ;
}
if ( ! V_4 -> V_37 . V_206 )
return - V_68 ;
V_5 = V_4 -> V_37 . V_206 ( V_4 , V_203 ) ;
if ( V_5 ) {
F_3 ( & V_4 -> V_11 ,
L_41 ) ;
return - V_68 ;
}
return 0 ;
}
static int
F_65 ( struct V_154 * V_154 , void * V_155 ,
struct V_205 * V_207 )
{
struct V_61 * V_62 = V_155 ;
struct V_3 * V_4 = V_62 -> V_2 -> V_4 ;
F_17 ( 1 , V_65 , & V_4 -> V_11 , L_42 ) ;
if ( V_4 -> V_113 . V_195 &
V_208 ) {
* V_207 = V_4 -> V_113 . V_207 ;
} else {
return - V_68 ;
}
return 0 ;
}
static int F_66 ( struct V_154 * V_154 , void * V_155 ,
enum V_209 V_210 )
{
struct V_61 * V_62 = V_154 -> V_158 ;
struct V_13 * V_14 = V_62 -> V_14 ;
struct V_3 * V_4 = V_62 -> V_2 -> V_4 ;
struct V_27 * V_28 = V_62 -> V_2 -> V_28 ;
int V_5 ;
F_17 ( 1 , V_65 , & V_4 -> V_11 ,
L_43 ,
V_14 -> V_92 ) ;
if ( V_174 != V_210 ) {
F_3 ( & V_4 -> V_11 , L_44 ) ;
return - V_68 ;
}
if ( ! V_62 -> V_211 ) {
F_3 ( & V_4 -> V_11 , L_45 ) ;
return - V_212 ;
}
if ( ! V_14 -> V_54 ) {
F_3 ( & V_4 -> V_11 , L_46
L_47 , V_14 -> V_92 ) ;
return - V_68 ;
}
V_28 -> V_37 . V_213 ( V_28 ,
V_14 -> V_39 . V_40 ) ;
V_14 -> V_54 = 0 ;
V_5 = F_67 ( & V_14 -> V_214 , V_210 ) ;
return V_5 ;
}
static int F_68 ( struct V_154 * V_154 , void * V_155 ,
enum V_209 V_210 )
{
struct V_61 * V_62 = V_154 -> V_158 ;
struct V_13 * V_14 = V_62 -> V_14 ;
struct V_1 * V_2 = V_62 -> V_2 ;
struct V_3 * V_4 = V_62 -> V_2 -> V_4 ;
struct V_27 * V_28 = V_2 -> V_28 ;
int V_5 ;
V_28 -> V_37 . V_213 ( V_28 ,
V_14 -> V_39 . V_40 ) ;
F_17 ( 1 , V_65 , & V_4 -> V_11 , L_48 ,
V_14 -> V_92 ) ;
if ( V_174 != V_210 ) {
F_3 ( & V_4 -> V_11 , L_44 ) ;
return - V_68 ;
}
if ( ! V_62 -> V_211 ) {
F_3 ( & V_4 -> V_11 , L_45 ) ;
return - V_212 ;
}
if ( V_14 -> V_54 ) {
F_3 ( & V_4 -> V_11 , L_49 ) ;
return - V_190 ;
}
V_5 = F_69 ( & V_14 -> V_214 , V_210 ) ;
if ( V_5 ) {
F_3 ( & V_4 -> V_11 ,
L_50 ) ;
return V_5 ;
}
return V_5 ;
}
static int F_70 ( struct V_154 * V_154 , void * V_155 ,
struct V_215 * V_80 )
{
struct V_61 * V_62 = V_154 -> V_158 ;
struct V_13 * V_14 = V_62 -> V_14 ;
struct V_3 * V_4 = V_62 -> V_2 -> V_4 ;
int V_5 ;
F_17 ( 1 , V_65 , & V_4 -> V_11 ,
L_51 ,
V_14 -> V_92 ) ;
if ( V_174 != V_80 -> type ) {
F_3 ( & V_4 -> V_11 , L_44 ) ;
return - V_68 ;
}
if ( ! V_62 -> V_211 ) {
F_3 ( & V_4 -> V_11 , L_45 ) ;
return - V_212 ;
}
if ( V_154 -> V_216 & V_217 )
V_5 = F_71 ( & V_14 -> V_214 , V_80 , 1 ) ;
else
V_5 = F_71 ( & V_14 -> V_214 , V_80 , 0 ) ;
return V_5 ;
}
static int F_72 ( struct V_154 * V_154 , void * V_155 ,
struct V_215 * V_218 )
{
struct V_61 * V_62 = V_154 -> V_158 ;
struct V_13 * V_14 = V_62 -> V_14 ;
struct V_3 * V_4 = V_62 -> V_2 -> V_4 ;
F_17 ( 1 , V_65 , & V_4 -> V_11 ,
L_52 ,
V_14 -> V_92 ) ;
if ( V_174 != V_218 -> type ) {
F_3 ( & V_4 -> V_11 , L_44 ) ;
return - V_68 ;
}
if ( ! V_62 -> V_211 ) {
F_3 ( & V_4 -> V_11 , L_45 ) ;
return - V_212 ;
}
return F_73 ( & V_14 -> V_214 , V_218 ) ;
}
static int F_74 ( struct V_154 * V_154 , void * V_155 ,
struct V_215 * V_80 )
{
struct V_61 * V_62 = V_154 -> V_158 ;
struct V_13 * V_14 = V_62 -> V_14 ;
struct V_3 * V_4 = V_62 -> V_2 -> V_4 ;
F_17 ( 1 , V_65 , & V_4 -> V_11 ,
L_53 ,
V_14 -> V_92 ) ;
if ( V_174 != V_80 -> type ) {
F_3 ( & V_4 -> V_11 , L_44 ) ;
return - V_68 ;
}
return F_75 ( & V_14 -> V_214 , V_80 ) ;
}
static int F_76 ( struct V_154 * V_154 , void * V_155 ,
struct V_219 * V_220 )
{
struct V_61 * V_62 = V_154 -> V_158 ;
struct V_13 * V_14 = V_62 -> V_14 ;
struct V_3 * V_4 = V_62 -> V_2 -> V_4 ;
struct V_63 * V_64 ;
int V_5 ;
F_17 ( 1 , V_65 , & V_4 -> V_11 , L_54 ) ;
if ( V_174 != V_220 -> type ) {
F_3 ( & V_4 -> V_11 , L_44 ) ;
return - V_68 ;
}
if ( 0 != V_14 -> V_221 ) {
F_3 ( & V_4 -> V_11 , L_55 ) ;
return - V_190 ;
}
V_14 -> V_79 = F_77 ( V_4 -> V_167 ) ;
if ( F_78 ( V_14 -> V_79 ) ) {
F_3 ( & V_4 -> V_11 , L_56 ) ;
return F_79 ( V_14 -> V_79 ) ;
}
V_64 = & V_14 -> V_214 ;
memset ( V_64 , 0 , sizeof( * V_64 ) ) ;
V_64 -> type = V_174 ;
V_64 -> V_222 = V_223 | V_224 ;
V_64 -> V_225 = V_62 ;
V_64 -> V_37 = & V_226 ;
V_64 -> V_227 = & V_228 ;
V_64 -> V_229 = sizeof( struct V_33 ) ;
V_64 -> V_230 = V_231 ;
V_64 -> V_232 = 1 ;
V_5 = F_80 ( V_64 ) ;
if ( V_5 ) {
F_3 ( & V_4 -> V_11 , L_57 ) ;
F_81 ( V_14 -> V_79 ) ;
return V_5 ;
}
V_62 -> V_211 = 1 ;
V_14 -> V_221 = 1 ;
V_14 -> V_233 = V_220 -> V_233 ;
F_36 ( & V_14 -> V_31 ) ;
return F_82 ( V_64 , V_220 ) ;
}
static int F_83 ( struct V_154 * V_234 , struct V_235 * V_236 )
{
struct V_61 * V_62 = V_234 -> V_158 ;
struct V_13 * V_14 = V_62 -> V_14 ;
struct V_3 * V_4 = V_62 -> V_2 -> V_4 ;
int V_5 ;
F_17 ( 1 , V_65 , & V_4 -> V_11 , L_58 ) ;
if ( F_84 ( & V_14 -> V_84 ) )
return - V_237 ;
V_5 = F_85 ( & V_14 -> V_214 , V_236 ) ;
F_32 ( & V_14 -> V_84 ) ;
return V_5 ;
}
static unsigned int F_86 ( struct V_154 * V_234 , T_3 * V_238 )
{
struct V_61 * V_62 = V_234 -> V_158 ;
struct V_13 * V_14 = V_62 -> V_14 ;
struct V_3 * V_4 = V_62 -> V_2 -> V_4 ;
unsigned int V_239 = 0 ;
F_17 ( 1 , V_65 , & V_4 -> V_11 , L_59 ) ;
if ( V_14 -> V_54 ) {
F_34 ( & V_14 -> V_84 ) ;
V_239 = F_87 ( & V_14 -> V_214 , V_234 , V_238 ) ;
F_32 ( & V_14 -> V_84 ) ;
}
return V_239 ;
}
static int F_88 ( struct V_154 * V_154 )
{
struct V_61 * V_62 = NULL ;
struct V_13 * V_14 = F_89 ( V_154 ) ;
struct V_240 * V_241 = F_90 ( V_154 ) ;
struct V_1 * V_2 = V_14 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_27 * V_28 = V_2 -> V_28 ;
int V_239 ;
V_62 = F_91 ( sizeof( struct V_61 ) , V_242 ) ;
if ( V_62 == NULL ) {
F_3 ( & V_4 -> V_11 ,
L_60 ) ;
return - V_243 ;
}
F_92 ( & V_62 -> V_62 , V_241 ) ;
F_17 ( 1 , V_65 , & V_4 -> V_11 ,
L_61 ,
V_14 -> V_92 ) ;
V_154 -> V_158 = V_62 ;
V_62 -> V_14 = V_14 ;
V_62 -> V_2 = V_2 ;
if ( ! V_14 -> V_244 ) {
if ( F_84 ( & V_14 -> V_84 ) )
return - V_237 ;
V_239 = V_28 -> V_37 . V_191 ( V_28 ,
V_14 -> V_39 . V_40 ) ;
F_32 ( & V_14 -> V_84 ) ;
if ( V_239 < 0 ) {
F_3 ( & V_4 -> V_11 ,
L_27 ) ;
F_93 ( V_62 ) ;
return - V_68 ;
}
}
V_14 -> V_244 ++ ;
V_62 -> V_211 = 0 ;
F_94 ( & V_62 -> V_62 ) ;
F_17 ( 1 , V_65 , & V_4 -> V_11 ,
L_62 ) ;
return 0 ;
}
static int F_95 ( struct V_154 * V_154 )
{
struct V_61 * V_62 = V_154 -> V_158 ;
struct V_13 * V_14 = V_62 -> V_14 ;
struct V_95 * V_96 = & V_14 -> V_39 . V_97 ;
struct V_1 * V_2 = V_62 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_27 * V_28 = V_2 -> V_28 ;
F_17 ( 1 , V_65 , & V_4 -> V_11 , L_63 ) ;
F_34 ( & V_14 -> V_84 ) ;
if ( V_62 -> V_211 ) {
V_14 -> V_221 = 0 ;
V_28 -> V_37 . V_213 ( V_28 ,
V_14 -> V_39 . V_40 ) ;
V_14 -> V_54 = 0 ;
F_96 ( & V_14 -> V_214 ) ;
F_81 ( & V_14 -> V_214 ) ;
}
V_14 -> V_244 -- ;
if ( ! V_14 -> V_244 ) {
if ( V_96 -> V_100 == V_101 ) {
struct V_13 * V_102 ;
V_102 =
F_42 ( V_2 , V_14 ) ;
V_28 -> V_37 . V_213 ( V_28 ,
V_102 -> V_39 . V_40 ) ;
V_28 -> V_37 . V_245 ( V_28 ,
V_102 -> V_39 . V_40 ) ;
}
V_28 -> V_37 . V_213 ( V_28 ,
V_14 -> V_39 . V_40 ) ;
V_28 -> V_37 . V_245 ( V_28 ,
V_14 -> V_39 . V_40 ) ;
}
F_97 ( & V_62 -> V_62 ) ;
F_98 ( & V_62 -> V_62 ) ;
V_154 -> V_158 = NULL ;
F_32 ( & V_14 -> V_84 ) ;
F_93 ( V_62 ) ;
V_2 -> V_41 = 0 ;
return 0 ;
}
static int F_99 ( struct V_246 * V_48 , void * V_247 )
{
struct V_248 * V_167 = F_100 ( V_48 ) ;
struct V_1 * V_249 = V_247 ;
if ( strcmp ( L_64 , V_167 -> V_250 ) == 0 )
V_249 -> V_4 = F_101 ( V_167 ) ;
if ( strstr ( V_167 -> V_250 , L_65 ) != NULL )
V_249 -> V_28 = F_101 ( V_167 ) ;
return 0 ;
}
static int F_102 ( int V_47 , struct V_1 * V_2 ,
struct V_248 * V_167 )
{
struct V_13 * V_251 = NULL ;
struct V_240 * V_252 = NULL ;
V_2 -> V_48 [ V_47 ] =
F_103 ( sizeof( struct V_13 ) , V_242 ) ;
if ( ! V_2 -> V_48 [ V_47 ] ) {
F_104 ( V_253 L_66 ) ;
return - V_243 ;
}
F_105 ( & V_2 -> V_48 [ V_47 ] -> V_83 ) ;
F_106 ( & V_2 -> V_48 [ V_47 ] -> V_84 ) ;
V_251 = V_2 -> V_48 [ V_47 ] ;
V_252 = & V_251 -> V_254 ;
V_252 -> V_255 = V_256 ;
V_252 -> V_257 = & V_258 ;
V_252 -> V_259 = & V_260 ;
V_252 -> V_261 = - 1 ;
V_252 -> V_11 = & V_2 -> V_4 -> V_11 ;
V_252 -> V_262 = & V_251 -> V_84 ;
V_252 -> V_263 = V_264 ;
if ( V_2 -> V_4 -> V_113 . V_195 &
V_196 )
V_252 -> V_265 = ( V_125 | V_126 ) ;
snprintf ( V_252 -> V_250 , sizeof( V_252 -> V_250 ) ,
L_67 ,
( V_160 >> 16 ) & 0xff ,
( V_160 >> 8 ) & 0xff ,
( V_160 ) & 0xff ) ;
V_251 -> V_92 = V_47 ;
V_251 -> V_39 . V_40 =
( ( V_47 == V_93 ) ? V_266 : V_267 ) ;
return 0 ;
}
static int F_107 ( struct V_13 * V_251 ,
struct V_1 * V_2 ,
struct V_248 * V_167 )
{
int V_239 ;
F_108 ( & V_2 -> V_4 -> V_11 ,
L_68 ) ;
F_108 ( & V_2 -> V_4 -> V_11 ,
L_69 ,
( int ) V_251 ,
( int ) & V_251 -> V_254 ) ;
V_239 = F_109 ( & V_251 -> V_254 ,
V_268 ,
- 1 ) ;
if ( V_239 )
return - V_269 ;
V_251 -> V_2 = V_2 ;
F_110 ( V_167 , V_2 ) ;
F_111 ( V_270 , & V_251 -> V_254 . V_82 ) ;
F_112 ( & V_251 -> V_254 ,
V_251 ) ;
return 0 ;
}
static int F_113 ( struct V_248 * V_167 )
{
struct V_13 * V_251 ;
struct V_1 * V_2 ;
struct V_271 * V_272 = NULL ;
int V_273 ;
int V_47 ;
int V_239 ;
int V_42 ;
F_104 ( V_274 L_70 ) ;
V_2 = F_114 ( & V_167 -> V_48 , sizeof( struct V_1 ) ,
V_242 ) ;
if ( ! V_2 )
return - V_243 ;
F_105 ( & V_2 -> V_30 ) ;
V_239 = F_115 ( & V_275 , NULL , V_2 ,
F_99 ) ;
if ( V_239 < 0 )
return V_239 ;
if ( NULL != V_2 -> V_4 -> V_37 . V_276 ) {
V_239 = V_2 -> V_4 -> V_37 . V_276 ( & V_167 -> V_48 ,
V_2 -> V_4 ) ;
if ( V_239 ) {
F_3 ( & V_2 -> V_4 -> V_11 ,
L_71 ) ;
V_239 = - V_243 ;
goto V_277;
}
}
for ( V_47 = 0 ; V_47 < V_53 ; V_47 ++ ) {
if ( F_102 ( V_47 , V_2 , V_167 ) ) {
V_239 = - V_269 ;
goto V_277;
}
}
V_272 = F_116 ( V_167 , V_278 , 0 ) ;
if ( ! V_272 ) {
F_3 ( & V_2 -> V_4 -> V_11 ,
L_72 ) ;
V_239 = - V_269 ;
goto V_277;
}
V_42 = V_272 -> V_279 ;
V_239 = F_117 ( & V_167 -> V_48 , V_42 , F_14 , 0 ,
V_280 , V_2 ) ;
if ( V_239 ) {
F_3 ( & V_2 -> V_4 -> V_11 ,
L_73 ) ;
goto V_277;
}
for ( V_47 = 0 ; V_47 < V_53 ; V_47 ++ ) {
if ( F_107 ( V_2 -> V_48 [ V_47 ] , V_2 , V_167 ) ) {
V_239 = - V_269 ;
goto V_277;
}
}
F_104 ( V_274 L_74 ) ;
return 0 ;
V_277:
for ( V_273 = 0 ; V_273 < V_53 ; V_273 ++ ) {
V_251 = V_2 -> V_48 [ V_273 ] ;
if ( V_251 ) {
F_118 (
& V_251 -> V_254 ) ;
F_93 ( V_2 -> V_48 [ V_273 ] ) ;
}
}
return V_239 ;
}
static int F_119 ( struct V_248 * V_167 )
{
struct V_13 * V_251 ;
struct V_1 * V_2 = F_101 ( V_167 ) ;
struct V_3 * V_4 = V_2 -> V_4 ;
int V_47 ;
F_17 ( 1 , V_65 , & V_4 -> V_11 , L_75 ) ;
if ( NULL != V_4 -> V_37 . V_281 )
V_4 -> V_37 . V_281 ( & V_167 -> V_48 , V_4 ) ;
for ( V_47 = 0 ; V_47 < V_53 ; V_47 ++ ) {
V_251 = V_2 -> V_48 [ V_47 ] ;
F_118 ( & V_251 -> V_254 ) ;
}
for ( V_47 = 0 ; V_47 < V_53 ; V_47 ++ ) {
F_93 ( V_2 -> V_48 [ V_47 ] ) ;
V_2 -> V_48 [ V_47 ] = NULL ;
}
return 0 ;
}
