static struct V_1 * F_1 ( struct V_2 * V_3 )
{
struct V_4 * V_5 = V_3 -> V_5 ;
int V_6 ;
int V_7 ;
for ( V_6 = 0 ; V_6 < V_5 -> V_8 ; V_6 ++ ) {
struct V_1 * V_9 = V_5 -> V_10 [ V_6 ] ;
T_1 * V_11 = V_9 -> V_12 ;
V_7 = F_2 ( V_11 -> V_13 , V_14 ,
V_15 ) ;
if ( V_7 == V_14 )
return V_9 ;
}
return NULL ;
}
static int F_3 ( struct V_2 * V_3 , struct V_1 * V_9 )
{
T_1 * V_11 = V_9 -> V_12 ;
int V_7 ;
V_7 = F_2 ( V_11 -> V_13 , V_15 , V_14 ) ;
if ( V_7 != V_15 ) {
F_4 ( L_1 , V_9 -> V_16 ) ;
return - V_17 ;
}
return 0 ;
}
static int F_5 ( struct V_18 * V_19 , struct V_20 * V_21 )
{
struct V_22 * V_23 = V_19 -> V_24 ;
struct V_2 * V_3 ;
T_2 * V_25 ;
struct V_1 * V_9 ;
T_1 * V_11 ;
V_3 = V_23 -> V_26 -> V_3 ;
V_25 = V_3 -> V_12 ;
V_9 = V_25 -> V_27 ;
V_11 = V_9 -> V_12 ;
V_21 -> V_28 |= V_29 ;
V_11 -> V_30 = V_31 ;
if ( F_6 ( V_21 , V_21 -> V_32 ,
V_21 -> V_33 ,
V_21 -> V_34 - V_21 -> V_32 , V_21 -> V_35 ) )
return - V_36 ;
return 0 ;
}
static int F_7 ( struct V_1 * V_9 , struct V_22 * V_37 )
{
struct V_2 * V_3 = V_37 -> V_26 -> V_3 ;
T_1 * V_11 = V_9 -> V_12 ;
T_2 * V_25 = V_3 -> V_12 ;
const struct V_38 * V_39 ;
int V_40 = 0 ;
if ( V_11 -> V_30 == V_31 )
return - V_17 ;
V_39 = V_37 -> V_19 -> V_41 ;
V_37 -> V_19 -> V_41 = & V_42 ;
V_25 -> V_27 = V_9 ;
V_11 -> V_43 = ( void * ) F_8 ( V_37 -> V_19 , 0 , V_9 -> V_44 ,
V_45 | V_46 ,
V_47 , V_9 -> V_48 ) ;
V_25 -> V_27 = NULL ;
V_37 -> V_19 -> V_41 = V_39 ;
if ( F_9 ( V_11 -> V_43 ) ) {
F_4 ( L_2 ) ;
V_40 = F_10 ( V_11 -> V_43 ) ;
V_11 -> V_43 = NULL ;
}
return V_40 ;
}
static int F_11 ( struct V_1 * V_9 )
{
T_1 * V_11 = V_9 -> V_12 ;
int V_40 = 0 ;
if ( V_11 -> V_30 != V_31 )
return - V_17 ;
V_40 = F_12 ( ( unsigned long ) V_11 -> V_43 ,
( V_49 ) V_9 -> V_44 ) ;
V_11 -> V_30 = V_50 ;
V_11 -> V_43 = NULL ;
return V_40 ;
}
static int F_13 ( struct V_2 * V_3 , T_3 * V_51 ,
struct V_22 * V_37 )
{
struct V_1 * V_9 ;
T_1 * V_11 ;
int V_40 = 0 ;
V_9 = F_1 ( V_3 ) ;
if ( ! V_9 ) {
V_40 = - V_52 ;
F_14 ( L_3 , V_40 ) ;
return V_40 ;
}
V_40 = F_7 ( V_9 , V_37 ) ;
if ( V_40 ) {
F_3 ( V_3 , V_9 ) ;
F_4 ( L_4 , V_40 ) ;
return V_40 ;
}
V_9 -> V_37 = V_37 ;
V_11 = V_9 -> V_12 ;
V_51 -> V_53 = 1 ;
V_51 -> V_54 = V_9 -> V_16 ;
V_51 -> V_55 = V_9 -> V_44 ;
V_51 -> V_43 = V_11 -> V_43 ;
return V_40 ;
}
static int F_15 ( struct V_2 * V_3 )
{
struct V_4 * V_5 = V_3 -> V_5 ;
if ( F_16 ( V_3 , V_56 ) && V_3 -> V_57 )
F_17 ( V_3 ) ;
if ( V_3 -> V_12 ) {
int V_6 ;
T_2 * V_25 =
( T_2 * ) V_3 -> V_12 ;
if ( V_25 -> V_58 . V_59 )
F_18 ( & V_25 -> V_58 . V_60 , V_3 ) ;
if ( V_25 -> V_61 ) {
F_19 ( V_3 -> V_62 , V_63 ,
V_25 -> V_61 ,
V_25 -> V_64 ) ;
}
F_20 ( V_3 -> V_12 ) ;
V_3 -> V_12 = NULL ;
for ( V_6 = 0 ; V_6 < V_5 -> V_8 ; V_6 ++ ) {
struct V_1 * V_9 = V_5 -> V_10 [ V_6 ] ;
T_1 * V_11 = V_9 -> V_12 ;
if ( V_11 -> V_65 && V_9 -> V_44 )
F_18 ( & V_11 -> V_60 , V_3 ) ;
}
}
return 0 ;
}
static int F_21 ( struct V_2 * V_3 , int V_66 )
{
T_2 * V_25 = V_3 -> V_12 ;
T_4 * V_58 = & ( V_25 -> V_58 ) ;
int V_67 = 0 ;
unsigned long V_68 ;
unsigned int V_69 = F_22 ( V_70 + V_71 ) & V_72 ;
V_68 = V_73 + ( V_74 * 3 ) ;
while ( V_58 -> V_75 < V_66 ) {
V_58 -> V_76 = F_22 ( V_70 + V_71 ) & V_72 ;
V_58 -> V_75 = V_58 -> V_76 - ( V_58 -> V_77 + 8 ) ;
if ( V_58 -> V_75 < 0 )
V_58 -> V_75 += V_58 -> V_78 ;
if ( V_58 -> V_76 != V_69 ) {
V_68 = V_73 + ( V_74 * 3 ) ;
V_69 = V_58 -> V_76 ;
}
V_67 ++ ;
if ( F_23 ( V_68 , V_73 ) ) {
F_4 ( L_5 , V_58 -> V_75 , V_66 ) ;
F_4 ( L_6 ) ;
goto V_79;
}
F_24 ( 1 ) ;
}
V_79:
return V_67 ;
}
static void F_25 ( struct V_2 * V_3 )
{
T_2 * V_25 = V_3 -> V_12 ;
T_4 * V_58 = & ( V_25 -> V_58 ) ;
V_58 -> V_76 = F_22 ( V_70 + V_71 ) & V_72 ;
V_58 -> V_77 = F_22 ( V_70 + V_80 ) ;
V_58 -> V_75 = V_58 -> V_76 - ( V_58 -> V_77 + 8 ) ;
if ( V_58 -> V_75 < 0 )
V_58 -> V_75 += V_58 -> V_78 ;
}
static int F_26 ( struct V_2 * V_3 , T_2 * V_25 )
{
struct V_4 * V_5 = V_3 -> V_5 ;
int V_81 = 24 ;
T_5 * V_82 = ( T_5 * ) ( V_25 -> V_61 + V_81 ) ;
int V_6 ;
if ( V_5 -> V_8 > 1019 ) {
return - V_17 ;
}
for ( V_6 = 0 ; V_6 < V_5 -> V_8 ; V_6 ++ ) {
struct V_1 * V_9 = V_5 -> V_10 [ V_6 ] ;
T_1 * V_11 = V_9 -> V_12 ;
V_11 -> V_13 = V_82 ++ ;
V_11 -> V_83 = V_81 ;
V_81 += 4 ;
* V_11 -> V_13 = V_14 ;
V_11 -> V_60 . V_84 = V_9 -> V_48 ;
V_11 -> V_60 . V_85 = V_9 -> V_44 ;
V_11 -> V_60 . type = V_86 ;
V_11 -> V_60 . V_87 = 0 ;
V_11 -> V_60 . V_88 = 0 ;
F_27 ( & V_11 -> V_60 , V_3 ) ;
V_11 -> V_65 = V_11 -> V_60 . V_89 ;
}
return 0 ;
}
static int F_28 ( struct V_2 * V_3 ,
T_2 * V_25 ,
T_6 * V_90 )
{
struct V_91 * V_92 ;
memset ( V_25 , 0 , sizeof( T_2 ) ) ;
F_29 (r_list, &dev->maplist, head) {
if ( V_92 -> V_60 &&
V_92 -> V_60 -> type == V_93 &&
V_92 -> V_60 -> V_87 & V_94 ) {
V_25 -> V_95 = V_92 -> V_60 ;
break;
}
}
if ( ! V_25 -> V_95 ) {
V_3 -> V_12 = ( void * ) V_25 ;
F_15 ( V_3 ) ;
F_4 ( L_7 ) ;
return - V_17 ;
}
V_25 -> V_96 = F_30 ( V_3 , V_90 -> V_97 ) ;
if ( ! V_25 -> V_96 ) {
V_3 -> V_12 = ( void * ) V_25 ;
F_15 ( V_3 ) ;
F_4 ( L_8 ) ;
return - V_17 ;
}
V_3 -> V_98 = V_90 -> V_99 ;
V_3 -> V_100 = F_30 ( V_3 , V_90 -> V_99 ) ;
if ( ! V_3 -> V_100 ) {
V_3 -> V_12 = ( void * ) V_25 ;
F_15 ( V_3 ) ;
F_4 ( L_9 ) ;
return - V_17 ;
}
V_25 -> V_101 = ( V_102 * )
( ( V_103 * ) V_25 -> V_95 -> V_89 + V_90 -> V_104 ) ;
V_25 -> V_58 . V_105 = V_90 -> V_106 ;
V_25 -> V_58 . V_107 = V_90 -> V_108 ;
V_25 -> V_58 . V_78 = V_90 -> V_109 ;
V_25 -> V_58 . V_60 . V_84 = V_3 -> V_110 -> V_111 + V_90 -> V_106 ;
V_25 -> V_58 . V_60 . V_85 = V_90 -> V_109 ;
V_25 -> V_58 . V_60 . type = V_86 ;
V_25 -> V_58 . V_60 . V_87 = 0 ;
V_25 -> V_58 . V_60 . V_88 = 0 ;
F_27 ( & V_25 -> V_58 . V_60 , V_3 ) ;
if ( V_25 -> V_58 . V_60 . V_89 == NULL ) {
V_3 -> V_12 = ( void * ) V_25 ;
F_15 ( V_3 ) ;
F_4 ( L_10
L_11 ) ;
return - V_52 ;
}
V_25 -> V_58 . V_59 = V_25 -> V_58 . V_60 . V_89 ;
V_25 -> V_58 . V_112 = V_25 -> V_58 . V_78 - 1 ;
V_25 -> V_113 = V_90 -> V_113 ;
V_25 -> V_114 = V_90 -> V_114 ;
V_25 -> V_115 = V_90 -> V_115 ;
V_25 -> V_116 = V_90 -> V_116 ;
V_25 -> V_117 = V_90 -> V_117 ;
V_25 -> V_118 = V_90 -> V_118 ;
V_25 -> V_119 = V_90 -> V_119 ;
V_25 -> V_120 = V_90 -> V_120 ;
V_25 -> V_121 = V_90 -> V_118 | V_90 -> V_122 ;
V_25 -> V_123 = V_90 -> V_116 | V_90 -> V_122 ;
V_25 -> V_124 = V_90 -> V_117 | V_90 -> V_122 ;
V_25 -> V_61 =
F_31 ( V_3 -> V_62 , V_63 ,
& V_25 -> V_64 ) ;
if ( ! V_25 -> V_61 ) {
V_3 -> V_12 = ( void * ) V_25 ;
F_15 ( V_3 ) ;
F_4 ( L_12 ) ;
return - V_52 ;
}
memset ( V_25 -> V_61 , 0 , V_63 ) ;
F_14 ( L_13 , V_25 -> V_61 ) ;
F_32 ( 0x02080 , V_25 -> V_64 ) ;
F_14 ( L_14 ) ;
if ( F_26 ( V_3 , V_25 ) != 0 ) {
V_3 -> V_12 = ( void * ) V_25 ;
F_15 ( V_3 ) ;
F_4 ( L_15
L_16 ) ;
return - V_52 ;
}
V_3 -> V_12 = ( void * ) V_25 ;
return 0 ;
}
static int F_33 ( struct V_2 * V_3 , void * V_125 ,
struct V_22 * V_37 )
{
T_2 * V_25 ;
T_6 * V_90 = V_125 ;
int V_40 = 0 ;
switch ( V_90 -> V_126 ) {
case V_127 :
F_34 ( L_17 ) ;
V_25 = F_35 ( sizeof( T_2 ) , V_128 ) ;
if ( V_25 == NULL )
return - V_52 ;
V_40 = F_28 ( V_3 , V_25 , V_90 ) ;
break;
case V_129 :
F_34 ( L_18 ) ;
V_40 = F_15 ( V_3 ) ;
break;
default:
return - V_17 ;
}
return V_40 ;
}
static void F_36 ( struct V_2 * V_3 ,
volatile unsigned int * V_130 )
{
T_2 * V_25 = V_3 -> V_12 ;
int V_6 , V_131 = 0 ;
unsigned int V_132 ;
V_133 ;
F_37 ( V_134 ) ;
F_38 ( V_135 ) ;
F_38 ( V_130 [ V_136 ] ) ;
F_38 ( V_137 ) ;
F_38 ( V_130 [ V_138 ] ) ;
for ( V_6 = 4 ; V_6 < V_134 ; V_6 ++ ) {
V_132 = V_130 [ V_6 ] ;
if ( ( V_132 & ( 7 << 29 ) ) == ( 3 << 29 ) &&
( V_132 & ( 0x1f << 24 ) ) < ( 0x1d << 24 ) ) {
F_38 ( V_132 ) ;
V_131 ++ ;
} else
F_39 ( L_19 ) ;
}
if ( V_131 & 1 )
F_38 ( 0 ) ;
F_40 () ;
}
static void F_41 ( struct V_2 * V_3 , volatile unsigned int * V_130 )
{
T_2 * V_25 = V_3 -> V_12 ;
int V_6 , V_131 = 0 ;
unsigned int V_132 ;
V_133 ;
F_37 ( V_139 ) ;
F_38 ( V_140 ) ;
F_38 ( V_130 [ V_141 ] ) ;
F_38 ( V_130 [ V_142 ] ) ;
F_38 ( V_130 [ V_143 ] ) ;
for ( V_6 = 4 ; V_6 < V_139 ; V_6 ++ ) {
V_132 = V_130 [ V_6 ] ;
if ( ( V_132 & ( 7 << 29 ) ) == ( 3 << 29 ) &&
( V_132 & ( 0x1f << 24 ) ) < ( 0x1d << 24 ) ) {
F_38 ( V_132 ) ;
V_131 ++ ;
} else
F_39 ( L_20 ) ;
}
if ( V_131 & 1 )
F_38 ( 0 ) ;
F_40 () ;
}
static void F_42 ( struct V_2 * V_3 ,
volatile unsigned int * V_130 )
{
T_2 * V_25 = V_3 -> V_12 ;
unsigned int V_132 ;
V_133 ;
F_37 ( V_144 + 2 ) ;
V_132 = V_130 [ V_145 ] ;
if ( V_132 == V_25 -> V_121 || V_132 == V_25 -> V_123 ) {
F_38 ( V_146 ) ;
F_38 ( V_132 ) ;
} else
F_14 ( L_21 ,
V_132 , V_25 -> V_121 , V_25 -> V_123 ) ;
F_38 ( V_147 ) ;
F_38 ( V_25 -> V_124 ) ;
F_38 ( V_148 ) ;
F_38 ( V_130 [ V_149 ] ) ;
F_38 ( V_150 ) ;
F_38 ( V_130 [ V_151 ] ) ;
F_38 ( V_130 [ V_152 ] ) ;
F_38 ( V_130 [ V_153 ] ) ;
F_38 ( V_130 [ V_154 ] ) ;
F_38 ( 0 ) ;
F_40 () ;
}
static void F_43 ( struct V_2 * V_3 )
{
T_2 * V_25 = V_3 -> V_12 ;
V_102 * V_101 = V_25 -> V_101 ;
unsigned int V_155 = V_101 -> V_155 ;
F_14 ( L_22 , V_155 ) ;
if ( V_155 & V_156 ) {
F_42 ( V_3 , V_101 -> V_157 ) ;
V_101 -> V_155 &= ~ V_156 ;
}
if ( V_155 & V_158 ) {
F_36 ( V_3 , V_101 -> V_159 ) ;
V_101 -> V_155 &= ~ V_158 ;
}
if ( V_155 & V_160 ) {
F_41 ( V_3 , V_101 -> V_161 [ 0 ] ) ;
V_101 -> V_155 &= ~ V_160 ;
}
if ( V_155 & V_162 ) {
F_41 ( V_3 , V_101 -> V_161 [ 1 ] ) ;
V_101 -> V_155 &= ~ V_162 ;
}
}
static void F_44 ( struct V_2 * V_3 , int V_87 ,
unsigned int V_163 ,
unsigned int V_164 )
{
T_2 * V_25 = V_3 -> V_12 ;
V_102 * V_101 = V_25 -> V_101 ;
int V_165 = V_101 -> V_165 ;
struct V_166 * V_167 = V_101 -> V_168 ;
int V_115 = V_25 -> V_115 ;
int V_169 = 2 ;
int V_6 ;
V_133 ;
if ( V_25 -> V_170 == 1 ) {
unsigned int V_132 = V_87 ;
V_87 &= ~ ( V_171 | V_172 ) ;
if ( V_132 & V_171 )
V_87 |= V_172 ;
if ( V_132 & V_172 )
V_87 |= V_171 ;
}
F_25 ( V_3 ) ;
if ( V_165 > V_173 )
V_165 = V_173 ;
for ( V_6 = 0 ; V_6 < V_165 ; V_6 ++ , V_167 ++ ) {
unsigned int V_174 = V_167 -> V_175 ;
unsigned int V_176 = V_167 -> y1 ;
unsigned int V_177 = ( V_167 -> V_178 - V_174 ) * V_169 ;
unsigned int V_179 = V_167 -> V_180 - V_176 ;
unsigned int V_181 = V_176 * V_115 + V_174 * V_169 ;
if ( V_167 -> V_175 > V_167 -> V_178 ||
V_167 -> y1 > V_167 -> V_180 ||
V_167 -> V_178 > V_25 -> V_113 || V_167 -> V_180 > V_25 -> V_114 )
continue;
if ( V_87 & V_171 ) {
F_37 ( 6 ) ;
F_38 ( V_182 | V_183 | 0x3 ) ;
F_38 ( V_184 | ( 0xF0 << 16 ) | V_115 ) ;
F_38 ( ( V_179 << 16 ) | V_177 ) ;
F_38 ( V_181 ) ;
F_38 ( V_163 ) ;
F_38 ( 0 ) ;
F_40 () ;
}
if ( V_87 & V_172 ) {
F_37 ( 6 ) ;
F_38 ( V_182 | V_183 | 0x3 ) ;
F_38 ( V_184 | ( 0xF0 << 16 ) | V_115 ) ;
F_38 ( ( V_179 << 16 ) | V_177 ) ;
F_38 ( V_25 -> V_116 + V_181 ) ;
F_38 ( V_163 ) ;
F_38 ( 0 ) ;
F_40 () ;
}
if ( V_87 & V_185 ) {
F_37 ( 6 ) ;
F_38 ( V_182 | V_183 | 0x3 ) ;
F_38 ( V_184 | ( 0xF0 << 16 ) | V_115 ) ;
F_38 ( ( V_179 << 16 ) | V_177 ) ;
F_38 ( V_25 -> V_117 + V_181 ) ;
F_38 ( V_164 ) ;
F_38 ( 0 ) ;
F_40 () ;
}
}
}
static void F_45 ( struct V_2 * V_3 )
{
T_2 * V_25 = V_3 -> V_12 ;
V_102 * V_101 = V_25 -> V_101 ;
int V_165 = V_101 -> V_165 ;
struct V_166 * V_167 = V_101 -> V_168 ;
int V_115 = V_25 -> V_115 ;
int V_169 = 2 ;
int V_6 ;
V_133 ;
F_14 ( L_23 ) ;
F_25 ( V_3 ) ;
if ( V_165 > V_173 )
V_165 = V_173 ;
for ( V_6 = 0 ; V_6 < V_165 ; V_6 ++ , V_167 ++ ) {
unsigned int V_113 = V_167 -> V_178 - V_167 -> V_175 ;
unsigned int V_114 = V_167 -> V_180 - V_167 -> y1 ;
unsigned int V_186 = V_167 -> V_175 * V_169 + V_167 -> y1 * V_115 ;
unsigned int V_181 = V_186 ;
if ( V_167 -> V_175 > V_167 -> V_178 ||
V_167 -> y1 > V_167 -> V_180 ||
V_167 -> V_178 > V_25 -> V_113 || V_167 -> V_180 > V_25 -> V_114 )
continue;
F_37 ( 6 ) ;
F_38 ( V_182 | V_187 | 0x4 ) ;
F_38 ( V_115 | ( 0xCC << 16 ) ) ;
F_38 ( ( V_114 << 16 ) | ( V_113 * V_169 ) ) ;
if ( V_25 -> V_170 == 0 )
F_38 ( V_25 -> V_118 + V_181 ) ;
else
F_38 ( V_25 -> V_116 + V_181 ) ;
F_38 ( V_115 ) ;
if ( V_25 -> V_170 == 0 )
F_38 ( V_25 -> V_116 + V_181 ) ;
else
F_38 ( V_25 -> V_118 + V_181 ) ;
F_40 () ;
}
}
static void F_46 ( struct V_2 * V_3 ,
struct V_1 * V_9 , int V_188 , int V_7 )
{
T_2 * V_25 = V_3 -> V_12 ;
T_1 * V_11 = V_9 -> V_12 ;
V_102 * V_101 = V_25 -> V_101 ;
struct V_166 * V_189 = V_101 -> V_168 ;
int V_165 = V_101 -> V_165 ;
unsigned long V_190 = ( unsigned long ) V_9 -> V_48 ;
unsigned long V_181 = V_190 - V_3 -> V_110 -> V_111 ;
int V_6 = 0 ;
V_133 ;
F_25 ( V_3 ) ;
if ( V_165 > V_173 )
V_165 = V_173 ;
if ( V_7 > 4 * 1024 )
V_7 = 0 ;
if ( V_101 -> V_155 )
F_43 ( V_3 ) ;
if ( V_11 -> V_30 == V_31 ) {
unsigned int V_191 = ( V_101 -> V_192 & V_193 ) ;
* ( T_5 * ) V_11 -> V_65 =
( ( V_194 | V_191 | ( ( V_7 / 4 ) - 2 ) ) ) ;
if ( V_7 & 4 ) {
* ( T_5 * ) ( ( char * ) V_11 -> V_65 + V_7 ) = 0 ;
V_7 += 4 ;
}
F_11 ( V_9 ) ;
}
if ( V_7 ) {
do {
if ( V_6 < V_165 ) {
F_37 ( 4 ) ;
F_38 ( V_195 | V_196 |
V_197 ) ;
F_38 ( V_198 ) ;
F_38 ( V_189 [ V_6 ] . V_175 | ( V_189 [ V_6 ] . y1 << 16 ) ) ;
F_38 ( ( V_189 [ V_6 ] . V_178 -
1 ) | ( ( V_189 [ V_6 ] . V_180 - 1 ) << 16 ) ) ;
F_40 () ;
}
F_37 ( 4 ) ;
F_38 ( V_199 ) ;
F_38 ( V_181 | V_200 ) ;
F_38 ( V_181 + V_7 - 4 ) ;
F_38 ( 0 ) ;
F_40 () ;
} while ( ++ V_6 < V_165 );
}
if ( V_188 ) {
V_25 -> V_201 ++ ;
( void ) F_2 ( V_11 -> V_13 , V_15 ,
V_202 ) ;
F_37 ( 8 ) ;
F_38 ( V_203 ) ;
F_38 ( 20 ) ;
F_38 ( V_25 -> V_201 ) ;
F_38 ( V_203 ) ;
F_38 ( V_11 -> V_83 ) ;
F_38 ( V_14 ) ;
F_38 ( V_204 ) ;
F_38 ( 0 ) ;
F_40 () ;
}
}
static void F_47 ( struct V_2 * V_3 )
{
T_2 * V_25 = V_3 -> V_12 ;
int V_115 = V_25 -> V_115 ;
V_133 ;
F_14 ( L_24 ,
V_25 -> V_170 ,
V_25 -> V_101 -> V_205 ) ;
F_25 ( V_3 ) ;
F_37 ( 2 ) ;
F_38 ( V_206 | V_207 | V_208 ) ;
F_38 ( 0 ) ;
F_40 () ;
F_37 ( V_144 + 2 ) ;
F_38 ( V_209 | ( V_115 << 5 ) ) ;
if ( V_25 -> V_170 == 0 ) {
F_38 ( V_25 -> V_116 ) ;
V_25 -> V_170 = 1 ;
} else {
F_38 ( V_25 -> V_118 ) ;
V_25 -> V_170 = 0 ;
}
F_38 ( 0 ) ;
F_40 () ;
F_37 ( 2 ) ;
F_38 ( V_210 | V_211 ) ;
F_38 ( 0 ) ;
F_40 () ;
V_25 -> V_101 -> V_205 = V_25 -> V_170 ;
}
static void F_48 ( struct V_2 * V_3 )
{
T_2 * V_25 = V_3 -> V_12 ;
V_133 ;
F_25 ( V_3 ) ;
F_37 ( 4 ) ;
F_38 ( V_206 | V_207 | V_208 ) ;
F_38 ( V_204 ) ;
F_38 ( 0 ) ;
F_38 ( 0 ) ;
F_40 () ;
F_21 ( V_3 , V_25 -> V_58 . V_78 - 8 ) ;
}
static int F_49 ( struct V_2 * V_3 )
{
T_2 * V_25 = V_3 -> V_12 ;
struct V_4 * V_5 = V_3 -> V_5 ;
int V_6 , V_212 = 0 ;
V_133 ;
F_25 ( V_3 ) ;
F_37 ( 2 ) ;
F_38 ( V_204 ) ;
F_38 ( 0 ) ;
F_40 () ;
F_21 ( V_3 , V_25 -> V_58 . V_78 - 8 ) ;
for ( V_6 = 0 ; V_6 < V_5 -> V_8 ; V_6 ++ ) {
struct V_1 * V_9 = V_5 -> V_10 [ V_6 ] ;
T_1 * V_11 = V_9 -> V_12 ;
int V_7 = F_2 ( V_11 -> V_13 , V_202 ,
V_14 ) ;
if ( V_7 == V_202 )
F_14 ( L_25 ) ;
if ( V_7 == V_15 )
F_14 ( L_26 ) ;
}
return V_212 ;
}
void F_50 ( struct V_2 * V_3 ,
struct V_22 * V_37 )
{
struct V_4 * V_5 = V_3 -> V_5 ;
int V_6 ;
if ( ! V_5 )
return;
if ( ! V_3 -> V_12 )
return;
if ( ! V_5 -> V_10 )
return;
F_49 ( V_3 ) ;
for ( V_6 = 0 ; V_6 < V_5 -> V_8 ; V_6 ++ ) {
struct V_1 * V_9 = V_5 -> V_10 [ V_6 ] ;
T_1 * V_11 = V_9 -> V_12 ;
if ( V_9 -> V_37 == V_37 && V_11 ) {
int V_7 = F_2 ( V_11 -> V_13 , V_15 ,
V_14 ) ;
if ( V_7 == V_15 )
F_14 ( L_27 ) ;
if ( V_11 -> V_30 == V_31 )
V_11 -> V_30 = V_50 ;
}
}
}
static int F_51 ( struct V_2 * V_3 , void * V_125 ,
struct V_22 * V_37 )
{
F_52 ( V_3 , V_37 ) ;
F_49 ( V_3 ) ;
return 0 ;
}
static int F_53 ( struct V_2 * V_3 , void * V_125 ,
struct V_22 * V_37 )
{
struct V_4 * V_5 = V_3 -> V_5 ;
T_2 * V_25 = ( T_2 * ) V_3 -> V_12 ;
T_5 * V_82 = V_25 -> V_61 ;
V_102 * V_101 = ( V_102 * )
V_25 -> V_101 ;
T_7 * V_213 = V_125 ;
F_52 ( V_3 , V_37 ) ;
F_14 ( L_28 ,
V_213 -> V_16 , V_213 -> V_7 , V_213 -> V_188 ) ;
if ( V_213 -> V_16 < 0 || V_213 -> V_16 > V_5 -> V_8 )
return - V_17 ;
F_46 ( V_3 ,
V_5 -> V_10 [ V_213 -> V_16 ] ,
V_213 -> V_188 , V_213 -> V_7 ) ;
V_101 -> V_214 = V_25 -> V_201 - 1 ;
V_101 -> V_215 = ( int ) V_82 [ 5 ] ;
return 0 ;
}
static int F_54 ( struct V_2 * V_3 , void * V_125 ,
struct V_22 * V_37 )
{
T_8 * V_216 = V_125 ;
F_52 ( V_3 , V_37 ) ;
if ( ! V_3 -> V_12 )
return - V_17 ;
F_44 ( V_3 , V_216 -> V_87 ,
V_216 -> V_163 , V_216 -> V_217 ) ;
return 0 ;
}
static int F_55 ( struct V_2 * V_3 , void * V_125 ,
struct V_22 * V_37 )
{
F_14 ( L_29 ) ;
F_52 ( V_3 , V_37 ) ;
F_45 ( V_3 ) ;
return 0 ;
}
static int F_56 ( struct V_2 * V_3 , void * V_125 ,
struct V_22 * V_37 )
{
T_2 * V_25 = ( T_2 * ) V_3 -> V_12 ;
T_5 * V_82 = V_25 -> V_61 ;
V_102 * V_101 = ( V_102 * )
V_25 -> V_101 ;
V_101 -> V_215 = ( int ) V_82 [ 5 ] ;
return 0 ;
}
static int F_57 ( struct V_2 * V_3 , void * V_125 ,
struct V_22 * V_37 )
{
int V_40 = 0 ;
T_3 * V_51 = V_125 ;
T_2 * V_25 = ( T_2 * ) V_3 -> V_12 ;
T_5 * V_82 = V_25 -> V_61 ;
V_102 * V_101 = ( V_102 * )
V_25 -> V_101 ;
F_52 ( V_3 , V_37 ) ;
V_51 -> V_53 = 0 ;
V_40 = F_13 ( V_3 , V_51 , V_37 ) ;
F_14 ( L_30 ,
F_58 ( V_218 ) , V_40 , V_51 -> V_53 ) ;
V_101 -> V_215 = ( int ) V_82 [ 5 ] ;
return V_40 ;
}
static int F_59 ( struct V_2 * V_3 , void * V_125 ,
struct V_22 * V_37 )
{
return 0 ;
}
static int F_60 ( struct V_2 * V_3 , void * V_125 ,
struct V_22 * V_37 )
{
return 0 ;
}
static void F_61 ( struct V_2 * V_3 , struct V_1 * V_9 , int V_7 ,
unsigned int V_219 )
{
T_2 * V_25 = V_3 -> V_12 ;
T_1 * V_11 = V_9 -> V_12 ;
V_102 * V_101 = V_25 -> V_101 ;
unsigned long V_190 = ( unsigned long ) V_9 -> V_48 ;
unsigned long V_181 = V_190 - V_3 -> V_110 -> V_111 ;
int V_220 ;
V_133 ;
F_25 ( V_3 ) ;
V_220 = F_2 ( V_11 -> V_13 , V_15 , V_202 ) ;
if ( V_220 != V_15 )
F_14 ( L_31 ) ;
if ( V_7 > 4 * 1024 )
V_7 = 0 ;
V_101 -> V_155 = 0x7f ;
F_14 ( L_32 , V_190 , V_7 ) ;
V_25 -> V_201 ++ ;
F_14 ( L_33 , V_25 -> V_201 ) ;
F_14 ( L_34 , V_181 ) ;
F_14 ( L_35 , V_7 ) ;
F_14 ( L_36 , V_181 + V_7 - 4 ) ;
if ( V_11 -> V_30 == V_31 ) {
if ( V_7 & 4 ) {
* ( T_5 * ) ( ( char * ) V_11 -> V_43 + V_7 ) = 0 ;
V_7 += 4 ;
}
F_11 ( V_9 ) ;
}
F_37 ( 4 ) ;
F_38 ( V_199 ) ;
F_38 ( V_181 | V_200 ) ;
F_38 ( V_181 + V_7 - 4 ) ;
F_38 ( 0 ) ;
F_40 () ;
F_37 ( 8 ) ;
F_38 ( V_203 ) ;
F_38 ( V_11 -> V_83 ) ;
F_38 ( V_14 ) ;
F_38 ( 0 ) ;
F_38 ( V_203 ) ;
F_38 ( 16 ) ;
F_38 ( V_219 ) ;
F_38 ( 0 ) ;
F_40 () ;
}
static int F_62 ( struct V_2 * V_3 , void * V_125 ,
struct V_22 * V_37 )
{
struct V_4 * V_5 = V_3 -> V_5 ;
T_2 * V_25 = ( T_2 * ) V_3 -> V_12 ;
T_5 * V_82 = V_25 -> V_61 ;
V_102 * V_101 = ( V_102 * )
V_25 -> V_101 ;
T_9 * V_221 = V_125 ;
F_52 ( V_3 , V_37 ) ;
if ( V_221 -> V_16 >= V_5 -> V_8 || V_221 -> V_16 < 0 )
return - V_17 ;
F_61 ( V_3 , V_5 -> V_10 [ V_221 -> V_16 ] , V_221 -> V_7 ,
V_221 -> V_219 ) ;
V_101 -> V_214 = V_25 -> V_201 - 1 ;
V_101 -> V_215 = ( int ) V_82 [ 5 ] ;
return 0 ;
}
static int F_63 ( struct V_2 * V_3 , void * V_125 ,
struct V_22 * V_37 )
{
T_2 * V_25 = ( T_2 * ) V_3 -> V_12 ;
return ( int ) ( ( ( T_5 * ) ( V_25 -> V_61 ) ) [ 4 ] ) ;
}
static int F_64 ( struct V_2 * V_3 , void * V_125 ,
struct V_22 * V_37 )
{
T_2 * V_25 = ( T_2 * ) V_3 -> V_12 ;
T_10 * V_222 = V_125 ;
V_222 -> V_84 = V_25 -> V_119 ;
V_222 -> V_223 = V_25 -> V_120 ;
return 0 ;
}
static int F_65 ( struct V_2 * V_3 , void * V_125 ,
struct V_22 * V_37 )
{
T_2 * V_25 = ( T_2 * ) V_3 -> V_12 ;
F_52 ( V_3 , V_37 ) ;
return F_22 ( 0x30008 ) ;
}
static int F_66 ( struct V_2 * V_3 , void * V_125 ,
struct V_22 * V_37 )
{
T_2 * V_25 = ( T_2 * ) V_3 -> V_12 ;
F_52 ( V_3 , V_37 ) ;
F_32 ( 0x30000 , V_25 -> V_120 | 0x80000000 ) ;
return 0 ;
}
static void F_67 ( struct V_2 * V_3 )
{
T_2 * V_25 = V_3 -> V_12 ;
F_14 ( L_29 ) ;
V_25 -> V_224 = 1 ;
V_25 -> V_170 = 0 ;
V_25 -> V_101 -> V_205 = V_25 -> V_170 ;
}
static int F_68 ( struct V_2 * V_3 )
{
T_2 * V_25 = V_3 -> V_12 ;
F_14 ( L_29 ) ;
if ( V_25 -> V_170 != 0 )
F_47 ( V_3 ) ;
V_25 -> V_224 = 0 ;
return 0 ;
}
static int F_69 ( struct V_2 * V_3 , void * V_125 ,
struct V_22 * V_37 )
{
T_2 * V_25 = V_3 -> V_12 ;
F_14 ( L_29 ) ;
F_52 ( V_3 , V_37 ) ;
if ( ! V_25 -> V_224 )
F_67 ( V_3 ) ;
F_47 ( V_3 ) ;
return 0 ;
}
int F_70 ( struct V_2 * V_3 , unsigned long V_87 )
{
F_71 ( V_3 -> V_62 ) ;
return 0 ;
}
void F_72 ( struct V_2 * V_3 )
{
F_15 ( V_3 ) ;
}
void F_73 ( struct V_2 * V_3 , struct V_22 * V_37 )
{
if ( V_3 -> V_12 ) {
T_2 * V_25 = V_3 -> V_12 ;
if ( V_25 -> V_224 )
F_68 ( V_3 ) ;
}
if ( V_37 -> V_225 && V_37 -> V_225 -> V_226 . V_227 ) {
F_74 ( & V_37 -> V_225 -> V_226 ) ;
F_50 ( V_3 , V_37 ) ;
F_75 ( & V_37 -> V_225 -> V_226 ) ;
} else {
F_50 ( V_3 , V_37 ) ;
}
}
int F_76 ( struct V_2 * V_3 )
{
F_48 ( V_3 ) ;
return 0 ;
}
int F_77 ( struct V_2 * V_3 )
{
return 1 ;
}
