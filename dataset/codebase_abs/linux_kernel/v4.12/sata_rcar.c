static void F_1 ( struct V_1 * V_2 )
{
void T_1 * V_3 = V_2 -> V_3 ;
F_2 ( 0 , V_3 + V_4 ) ;
F_2 ( V_5 , V_3 + V_6 ) ;
F_3 ( 10 ) ;
F_2 ( 0 , V_3 + V_6 ) ;
}
static void F_4 ( struct V_1 * V_2 , T_2 V_7 ,
T_3 V_8 , int V_9 )
{
void T_1 * V_3 = V_2 -> V_3 ;
int V_10 ;
F_2 ( 0 , V_3 + V_6 ) ;
F_2 ( V_11 , V_3 + V_12 ) ;
F_2 ( V_8 , V_3 + V_13 ) ;
if ( V_9 )
V_7 |= V_14 ;
F_2 ( V_15 | V_7 , V_3 + V_4 ) ;
for ( V_10 = 0 ; V_10 < 100 ; V_10 ++ ) {
V_8 = F_5 ( V_3 + V_16 ) ;
if ( V_8 & V_17 )
break;
}
if ( V_10 >= 100 )
F_6 ( L_1 , V_18 ) ;
F_2 ( 0 , V_3 + V_4 ) ;
}
static void F_7 ( struct V_1 * V_2 )
{
F_1 ( V_2 ) ;
F_4 ( V_2 , V_19 , 0x00200188 , 0 ) ;
F_4 ( V_2 , V_19 , 0x00200188 , 1 ) ;
F_4 ( V_2 , V_20 , 0x0000A061 , 0 ) ;
F_4 ( V_2 , V_21 , 0x20000000 , 0 ) ;
F_4 ( V_2 , V_21 , 0x20000000 , 1 ) ;
F_4 ( V_2 , V_22 , 0x28E80000 , 0 ) ;
}
static void F_8 ( struct V_1 * V_2 )
{
void T_1 * V_3 = V_2 -> V_3 ;
F_2 ( V_23 , V_3 + V_24 ) ;
F_2 ( V_25 , V_3 + V_26 ) ;
F_2 ( V_27 , V_3 + V_28 ) ;
F_2 ( V_29 , V_3 + V_30 ) ;
F_2 ( V_31 | V_32 |
V_33 , V_3 + V_34 ) ;
}
static void F_9 ( struct V_35 * V_36 )
{
struct V_1 * V_2 = V_36 -> V_37 -> V_38 ;
F_2 ( 0x7ff , V_2 -> V_3 + V_39 ) ;
F_10 ( V_36 ) ;
}
static void F_11 ( struct V_35 * V_36 )
{
struct V_1 * V_2 = V_36 -> V_37 -> V_38 ;
void T_1 * V_3 = V_2 -> V_3 ;
F_2 ( ~ ( T_3 ) V_40 , V_3 + V_41 ) ;
F_12 ( V_36 ) ;
F_2 ( 0x7ff & ~ V_40 , V_3 + V_39 ) ;
}
static void F_13 ( void T_1 * V_7 , void * V_42 , int V_43 )
{
T_2 * V_44 = V_42 ;
while ( V_43 -- ) {
T_2 V_45 = F_5 ( V_7 ) ;
* V_44 ++ = V_45 ;
}
}
static void F_14 ( void T_1 * V_7 , void * V_42 , int V_43 )
{
const T_2 * V_44 = V_42 ;
while ( V_43 -- )
F_2 ( * V_44 ++ , V_7 ) ;
}
static T_4 F_15 ( struct V_35 * V_36 )
{
return F_5 ( V_36 -> V_46 . V_47 ) ;
}
static T_4 F_16 ( struct V_35 * V_36 )
{
return F_5 ( V_36 -> V_46 . V_48 ) ;
}
static void F_17 ( struct V_35 * V_36 , T_4 V_49 )
{
F_2 ( V_49 , V_36 -> V_46 . V_50 ) ;
}
static void F_18 ( struct V_35 * V_36 , unsigned int V_51 )
{
F_2 ( V_52 , V_36 -> V_46 . V_53 ) ;
F_19 ( V_36 ) ;
}
static unsigned int F_20 ( struct V_35 * V_36 ,
unsigned int V_51 )
{
struct V_54 * V_46 = & V_36 -> V_46 ;
T_4 V_55 , V_56 ;
F_18 ( V_36 , V_51 ) ;
F_2 ( 0x55 , V_46 -> V_57 ) ;
F_2 ( 0xaa , V_46 -> V_58 ) ;
F_2 ( 0xaa , V_46 -> V_57 ) ;
F_2 ( 0x55 , V_46 -> V_58 ) ;
F_2 ( 0x55 , V_46 -> V_57 ) ;
F_2 ( 0xaa , V_46 -> V_58 ) ;
V_55 = F_5 ( V_46 -> V_57 ) ;
V_56 = F_5 ( V_46 -> V_58 ) ;
if ( V_55 == 0x55 && V_56 == 0xaa )
return 1 ;
return 0 ;
}
static int F_21 ( struct V_59 * V_60 ,
unsigned long V_61 )
{
struct V_35 * V_36 = V_60 -> V_36 ;
F_22 ( V_36 , V_62 ) ;
return F_23 ( V_60 , V_61 ) ;
}
static int F_24 ( struct V_35 * V_36 , unsigned long V_61 )
{
struct V_54 * V_46 = & V_36 -> V_46 ;
F_25 ( L_2 , V_36 -> V_63 ) ;
F_2 ( V_36 -> V_49 , V_46 -> V_50 ) ;
F_3 ( 20 ) ;
F_2 ( V_36 -> V_49 | V_64 , V_46 -> V_50 ) ;
F_3 ( 20 ) ;
F_2 ( V_36 -> V_49 , V_46 -> V_50 ) ;
V_36 -> V_65 = V_36 -> V_49 ;
return F_21 ( & V_36 -> V_60 , V_61 ) ;
}
static int F_26 ( struct V_59 * V_60 , unsigned int * V_66 ,
unsigned long V_61 )
{
struct V_35 * V_36 = V_60 -> V_36 ;
unsigned int V_67 = 0 ;
int V_68 ;
T_4 V_69 ;
if ( F_20 ( V_36 , 0 ) )
V_67 |= 1 << 0 ;
F_25 ( L_3 , V_67 ) ;
V_68 = F_24 ( V_36 , V_61 ) ;
if ( V_68 && ( V_68 != - V_70 || F_27 ( V_60 ) ) ) {
F_28 ( V_60 , L_4 , V_68 ) ;
return V_68 ;
}
V_66 [ 0 ] = F_29 ( & V_60 -> V_51 [ 0 ] , V_67 , & V_69 ) ;
F_25 ( L_5 , V_66 [ 0 ] ) ;
return 0 ;
}
static void F_30 ( struct V_35 * V_36 ,
const struct V_71 * V_72 )
{
struct V_54 * V_46 = & V_36 -> V_46 ;
unsigned int V_73 = V_72 -> V_74 & V_75 ;
if ( V_72 -> V_49 != V_36 -> V_65 ) {
F_2 ( V_72 -> V_49 , V_46 -> V_50 ) ;
V_36 -> V_65 = V_72 -> V_49 ;
F_31 ( V_36 ) ;
}
if ( V_73 && ( V_72 -> V_74 & V_76 ) ) {
F_2 ( V_72 -> V_77 , V_46 -> V_78 ) ;
F_2 ( V_72 -> V_79 , V_46 -> V_57 ) ;
F_2 ( V_72 -> V_80 , V_46 -> V_58 ) ;
F_2 ( V_72 -> V_81 , V_46 -> V_82 ) ;
F_2 ( V_72 -> V_83 , V_46 -> V_84 ) ;
F_32 ( L_6 ,
V_72 -> V_77 ,
V_72 -> V_79 ,
V_72 -> V_80 ,
V_72 -> V_81 ,
V_72 -> V_83 ) ;
}
if ( V_73 ) {
F_2 ( V_72 -> V_85 , V_46 -> V_78 ) ;
F_2 ( V_72 -> V_55 , V_46 -> V_57 ) ;
F_2 ( V_72 -> V_56 , V_46 -> V_58 ) ;
F_2 ( V_72 -> V_86 , V_46 -> V_82 ) ;
F_2 ( V_72 -> V_87 , V_46 -> V_84 ) ;
F_32 ( L_7 ,
V_72 -> V_85 ,
V_72 -> V_55 ,
V_72 -> V_56 ,
V_72 -> V_86 ,
V_72 -> V_87 ) ;
}
if ( V_72 -> V_74 & V_88 ) {
F_2 ( V_72 -> V_51 , V_46 -> V_53 ) ;
F_32 ( L_8 , V_72 -> V_51 ) ;
}
F_31 ( V_36 ) ;
}
static void F_33 ( struct V_35 * V_36 , struct V_71 * V_72 )
{
struct V_54 * V_46 = & V_36 -> V_46 ;
V_72 -> V_89 = F_15 ( V_36 ) ;
V_72 -> V_85 = F_5 ( V_46 -> V_90 ) ;
V_72 -> V_55 = F_5 ( V_46 -> V_57 ) ;
V_72 -> V_56 = F_5 ( V_46 -> V_58 ) ;
V_72 -> V_86 = F_5 ( V_46 -> V_82 ) ;
V_72 -> V_87 = F_5 ( V_46 -> V_84 ) ;
V_72 -> V_51 = F_5 ( V_46 -> V_53 ) ;
if ( V_72 -> V_74 & V_76 ) {
F_2 ( V_72 -> V_49 | V_91 , V_46 -> V_50 ) ;
V_72 -> V_77 = F_5 ( V_46 -> V_90 ) ;
V_72 -> V_79 = F_5 ( V_46 -> V_57 ) ;
V_72 -> V_80 = F_5 ( V_46 -> V_58 ) ;
V_72 -> V_81 = F_5 ( V_46 -> V_82 ) ;
V_72 -> V_83 = F_5 ( V_46 -> V_84 ) ;
F_2 ( V_72 -> V_49 , V_46 -> V_50 ) ;
V_36 -> V_65 = V_72 -> V_49 ;
}
}
static void F_34 ( struct V_35 * V_36 ,
const struct V_71 * V_72 )
{
F_25 ( L_9 , V_36 -> V_63 , V_72 -> V_89 ) ;
F_2 ( V_72 -> V_89 , V_36 -> V_46 . V_92 ) ;
F_19 ( V_36 ) ;
}
static unsigned int F_35 ( struct V_93 * V_94 ,
unsigned char * V_95 ,
unsigned int V_96 , int V_97 )
{
struct V_35 * V_36 = V_94 -> V_98 -> V_60 -> V_36 ;
void T_1 * V_99 = V_36 -> V_46 . V_99 ;
unsigned int V_100 = V_96 >> 1 ;
if ( V_97 == V_101 )
F_13 ( V_99 , V_95 , V_100 ) ;
else
F_14 ( V_99 , V_95 , V_100 ) ;
if ( F_36 ( V_96 & 0x01 ) ) {
unsigned char V_102 [ 2 ] = { } ;
V_95 += V_96 - 1 ;
if ( V_97 == V_101 ) {
F_13 ( V_99 , V_102 , 1 ) ;
* V_95 = V_102 [ 0 ] ;
} else {
V_102 [ 0 ] = * V_95 ;
F_14 ( V_99 , V_102 , 1 ) ;
}
V_100 ++ ;
}
return V_100 << 1 ;
}
static void F_37 ( struct V_93 * V_94 )
{
int V_43 ;
struct V_35 * V_36 ;
if ( V_94 == NULL || V_94 -> V_103 == V_104 )
return;
V_36 = V_94 -> V_36 ;
for ( V_43 = 0 ; ( V_36 -> V_105 -> V_106 ( V_36 ) & V_107 ) &&
V_43 < 65536 ; V_43 += 2 )
F_5 ( V_36 -> V_46 . V_99 ) ;
if ( V_43 )
F_38 ( V_36 , L_10 , V_43 ) ;
}
static int F_39 ( struct V_59 * V_60 , unsigned int V_108 ,
T_3 * V_8 )
{
if ( V_108 > V_109 )
return - V_110 ;
* V_8 = F_5 ( V_60 -> V_36 -> V_46 . V_111 + ( V_108 << 2 ) ) ;
return 0 ;
}
static int F_40 ( struct V_59 * V_60 , unsigned int V_108 ,
T_3 V_8 )
{
if ( V_108 > V_109 )
return - V_110 ;
F_2 ( V_8 , V_60 -> V_36 -> V_46 . V_111 + ( V_108 << 2 ) ) ;
return 0 ;
}
static void F_41 ( struct V_93 * V_94 )
{
struct V_35 * V_36 = V_94 -> V_36 ;
struct V_112 * V_113 = V_36 -> V_114 ;
struct V_115 * V_116 ;
unsigned int V_117 ;
F_42 (qc->sg, sg, qc->n_elem, si) {
T_3 V_118 , V_119 ;
V_118 = ( T_3 ) F_43 ( V_116 ) ;
V_119 = F_44 ( V_116 ) ;
V_113 [ V_117 ] . V_118 = F_45 ( V_118 ) ;
V_113 [ V_117 ] . V_120 = F_45 ( V_119 ) ;
F_32 ( L_11 , V_117 , V_118 , V_119 ) ;
}
V_113 [ V_117 - 1 ] . V_118 |= F_45 ( V_121 ) ;
}
static void F_46 ( struct V_93 * V_94 )
{
if ( ! ( V_94 -> V_74 & V_122 ) )
return;
F_41 ( V_94 ) ;
}
static void F_47 ( struct V_93 * V_94 )
{
struct V_35 * V_36 = V_94 -> V_36 ;
unsigned int V_97 = V_94 -> V_72 . V_74 & V_123 ;
struct V_1 * V_2 = V_36 -> V_37 -> V_38 ;
void T_1 * V_3 = V_2 -> V_3 ;
T_3 V_124 ;
F_48 () ;
F_2 ( V_36 -> V_125 , V_3 + V_126 ) ;
V_124 = F_5 ( V_3 + V_127 ) ;
V_124 &= ~ ( V_128 | V_129 ) ;
if ( V_124 & V_130 ) {
V_124 &= ~ V_130 ;
V_124 |= V_129 ;
}
if ( ! V_97 )
V_124 |= V_128 ;
F_2 ( V_124 , V_3 + V_127 ) ;
V_36 -> V_105 -> V_131 ( V_36 , & V_94 -> V_72 ) ;
}
static void F_49 ( struct V_93 * V_94 )
{
struct V_35 * V_36 = V_94 -> V_36 ;
struct V_1 * V_2 = V_36 -> V_37 -> V_38 ;
void T_1 * V_3 = V_2 -> V_3 ;
T_3 V_124 ;
V_124 = F_5 ( V_3 + V_127 ) ;
V_124 &= ~ V_129 ;
V_124 |= V_130 ;
F_2 ( V_124 , V_3 + V_127 ) ;
}
static void F_50 ( struct V_93 * V_94 )
{
struct V_35 * V_36 = V_94 -> V_36 ;
struct V_1 * V_2 = V_36 -> V_37 -> V_38 ;
void T_1 * V_3 = V_2 -> V_3 ;
T_3 V_124 ;
V_124 = F_5 ( V_3 + V_127 ) ;
if ( V_124 & V_130 ) {
V_124 &= ~ V_130 ;
V_124 |= V_129 ;
F_2 ( V_124 , V_3 + V_127 ) ;
}
F_51 ( V_36 ) ;
}
static T_4 F_52 ( struct V_35 * V_36 )
{
struct V_1 * V_2 = V_36 -> V_37 -> V_38 ;
T_4 V_132 = 0 ;
T_3 V_133 ;
V_133 = F_5 ( V_2 -> V_3 + V_134 ) ;
if ( V_133 & V_135 )
V_132 |= V_136 ;
if ( V_133 & V_137 )
V_132 |= V_138 ;
return V_132 ;
}
static void F_53 ( struct V_35 * V_36 )
{
struct V_1 * V_2 = V_36 -> V_37 -> V_38 ;
struct V_139 * V_140 = & V_36 -> V_60 . V_141 ;
int V_142 = 0 ;
T_3 V_143 ;
V_143 = F_5 ( V_2 -> V_3 + V_144 ) ;
if ( ! V_143 )
return;
F_25 ( L_12 , V_143 ) ;
F_54 ( V_140 ) ;
if ( V_143 & ( V_145 | V_146 ) ) {
F_55 ( V_140 ) ;
F_56 ( V_140 , L_13 , L_14 ) ;
V_142 = V_143 & V_147 ? 0 : 1 ;
}
if ( V_142 )
F_57 ( V_36 ) ;
else
F_58 ( V_36 ) ;
}
static void F_59 ( struct V_35 * V_36 )
{
struct V_93 * V_94 ;
int V_148 = 0 ;
V_94 = F_60 ( V_36 , V_36 -> V_60 . V_149 ) ;
if ( V_94 )
V_148 |= F_61 ( V_36 , V_94 ) ;
if ( ! V_148 )
F_15 ( V_36 ) ;
}
static T_5 F_62 ( int V_150 , void * V_151 )
{
struct V_152 * V_37 = V_151 ;
struct V_1 * V_2 = V_37 -> V_38 ;
void T_1 * V_3 = V_2 -> V_3 ;
unsigned int V_148 = 0 ;
struct V_35 * V_36 ;
T_3 V_153 ;
unsigned long V_74 ;
F_63 ( & V_37 -> V_154 , V_74 ) ;
V_153 = F_5 ( V_3 + V_41 ) ;
V_153 &= V_40 ;
if ( ! V_153 )
goto V_155;
F_2 ( ~ V_153 & 0x7ff , V_3 + V_41 ) ;
V_36 = V_37 -> V_156 [ 0 ] ;
if ( V_153 & V_157 )
F_59 ( V_36 ) ;
if ( V_153 & V_158 )
F_53 ( V_36 ) ;
V_148 = 1 ;
V_155:
F_64 ( & V_37 -> V_154 , V_74 ) ;
return F_65 ( V_148 ) ;
}
static void F_66 ( struct V_152 * V_37 )
{
struct V_35 * V_36 = V_37 -> V_156 [ 0 ] ;
struct V_54 * V_46 = & V_36 -> V_46 ;
struct V_1 * V_2 = V_37 -> V_38 ;
void T_1 * V_3 = V_2 -> V_3 ;
V_36 -> V_105 = & V_159 ;
V_36 -> V_160 = V_161 ;
V_36 -> V_162 = V_163 ;
V_36 -> V_74 |= V_164 ;
if ( V_2 -> type == V_165 )
V_36 -> V_74 |= V_166 ;
V_46 -> V_167 = V_3 + V_168 ;
V_46 -> V_50 = V_3 + V_169 ;
V_46 -> V_111 = V_3 + V_170 ;
V_46 -> V_48 = V_46 -> V_50 ;
V_46 -> V_99 = V_46 -> V_167 + ( V_171 << 2 ) ;
V_46 -> V_90 = V_46 -> V_167 + ( V_172 << 2 ) ;
V_46 -> V_78 = V_46 -> V_167 + ( V_173 << 2 ) ;
V_46 -> V_57 = V_46 -> V_167 + ( V_174 << 2 ) ;
V_46 -> V_58 = V_46 -> V_167 + ( V_175 << 2 ) ;
V_46 -> V_82 = V_46 -> V_167 + ( V_176 << 2 ) ;
V_46 -> V_84 = V_46 -> V_167 + ( V_177 << 2 ) ;
V_46 -> V_53 = V_46 -> V_167 + ( V_178 << 2 ) ;
V_46 -> V_47 = V_46 -> V_167 + ( V_179 << 2 ) ;
V_46 -> V_92 = V_46 -> V_167 + ( V_180 << 2 ) ;
}
static void F_67 ( struct V_152 * V_37 )
{
struct V_1 * V_2 = V_37 -> V_38 ;
void T_1 * V_3 = V_2 -> V_3 ;
T_3 V_8 ;
switch ( V_2 -> type ) {
case V_181 :
F_7 ( V_2 ) ;
break;
case V_182 :
case V_165 :
F_8 ( V_2 ) ;
break;
default:
F_68 ( V_37 -> V_98 , L_15 ) ;
break;
}
V_8 = F_5 ( V_3 + V_127 ) ;
V_8 |= V_183 ;
F_2 ( V_8 , V_3 + V_127 ) ;
V_8 = F_5 ( V_3 + V_127 ) ;
V_8 |= V_184 ;
V_8 |= V_185 ;
V_8 |= V_186 ;
F_2 ( V_8 , V_3 + V_127 ) ;
V_8 = F_5 ( V_3 + V_127 ) ;
V_8 &= ~ V_183 ;
F_2 ( V_8 , V_3 + V_127 ) ;
F_2 ( 0 , V_3 + V_41 ) ;
F_2 ( 0x7ff , V_3 + V_39 ) ;
F_2 ( V_187 , V_3 + V_188 ) ;
}
static int F_69 ( struct V_189 * V_190 )
{
const struct V_191 * V_192 ;
struct V_152 * V_37 ;
struct V_1 * V_2 ;
struct V_193 * V_194 ;
int V_150 ;
int V_195 = 0 ;
V_150 = F_70 ( V_190 , 0 ) ;
if ( V_150 <= 0 )
return - V_110 ;
V_2 = F_71 ( & V_190 -> V_98 , sizeof( struct V_1 ) ,
V_196 ) ;
if ( ! V_2 )
return - V_197 ;
V_192 = F_72 ( V_198 , & V_190 -> V_98 ) ;
if ( ! V_192 )
return - V_70 ;
V_2 -> type = (enum V_199 ) V_192 -> V_45 ;
V_2 -> V_200 = F_73 ( & V_190 -> V_98 , NULL ) ;
if ( F_74 ( V_2 -> V_200 ) ) {
F_75 ( & V_190 -> V_98 , L_16 ) ;
return F_76 ( V_2 -> V_200 ) ;
}
V_195 = F_77 ( V_2 -> V_200 ) ;
if ( V_195 )
return V_195 ;
V_37 = F_78 ( & V_190 -> V_98 , 1 ) ;
if ( ! V_37 ) {
F_75 ( & V_190 -> V_98 , L_17 ) ;
V_195 = - V_197 ;
goto V_201;
}
V_37 -> V_38 = V_2 ;
V_194 = F_79 ( V_190 , V_202 , 0 ) ;
V_2 -> V_3 = F_80 ( & V_190 -> V_98 , V_194 ) ;
if ( F_74 ( V_2 -> V_3 ) ) {
V_195 = F_76 ( V_2 -> V_3 ) ;
goto V_201;
}
F_66 ( V_37 ) ;
F_67 ( V_37 ) ;
V_195 = F_81 ( V_37 , V_150 , F_62 , 0 ,
& V_203 ) ;
if ( ! V_195 )
return 0 ;
V_201:
F_82 ( V_2 -> V_200 ) ;
return V_195 ;
}
static int F_83 ( struct V_189 * V_190 )
{
struct V_152 * V_37 = F_84 ( V_190 ) ;
struct V_1 * V_2 = V_37 -> V_38 ;
void T_1 * V_3 = V_2 -> V_3 ;
F_85 ( V_37 ) ;
F_2 ( 0 , V_3 + V_188 ) ;
F_2 ( 0 , V_3 + V_41 ) ;
F_2 ( 0x7ff , V_3 + V_39 ) ;
F_82 ( V_2 -> V_200 ) ;
return 0 ;
}
static int F_86 ( struct V_51 * V_98 )
{
struct V_152 * V_37 = F_87 ( V_98 ) ;
struct V_1 * V_2 = V_37 -> V_38 ;
void T_1 * V_3 = V_2 -> V_3 ;
int V_195 ;
V_195 = F_88 ( V_37 , V_204 ) ;
if ( ! V_195 ) {
F_2 ( 0 , V_3 + V_188 ) ;
F_2 ( 0x7ff , V_3 + V_39 ) ;
F_82 ( V_2 -> V_200 ) ;
}
return V_195 ;
}
static int F_89 ( struct V_51 * V_98 )
{
struct V_152 * V_37 = F_87 ( V_98 ) ;
struct V_1 * V_2 = V_37 -> V_38 ;
void T_1 * V_3 = V_2 -> V_3 ;
int V_195 ;
V_195 = F_77 ( V_2 -> V_200 ) ;
if ( V_195 )
return V_195 ;
F_2 ( 0 , V_3 + V_41 ) ;
F_2 ( 0x7ff , V_3 + V_39 ) ;
F_2 ( V_187 , V_3 + V_188 ) ;
F_90 ( V_37 ) ;
return 0 ;
}
static int F_91 ( struct V_51 * V_98 )
{
struct V_152 * V_37 = F_87 ( V_98 ) ;
struct V_1 * V_2 = V_37 -> V_38 ;
int V_195 ;
V_195 = F_77 ( V_2 -> V_200 ) ;
if ( V_195 )
return V_195 ;
F_66 ( V_37 ) ;
F_67 ( V_37 ) ;
F_90 ( V_37 ) ;
return 0 ;
}
