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
struct V_35 * V_36 = V_94 -> V_60 -> V_36 ;
void T_1 * V_98 = V_36 -> V_46 . V_98 ;
unsigned int V_99 = V_96 >> 1 ;
if ( V_97 == V_100 )
F_13 ( V_98 , V_95 , V_99 ) ;
else
F_14 ( V_98 , V_95 , V_99 ) ;
if ( F_36 ( V_96 & 0x01 ) ) {
unsigned char V_101 [ 2 ] = { } ;
V_95 += V_96 - 1 ;
if ( V_97 == V_100 ) {
F_13 ( V_98 , V_101 , 1 ) ;
* V_95 = V_101 [ 0 ] ;
} else {
V_101 [ 0 ] = * V_95 ;
F_14 ( V_98 , V_101 , 1 ) ;
}
V_99 ++ ;
}
return V_99 << 1 ;
}
static void F_37 ( struct V_102 * V_103 )
{
int V_43 ;
struct V_35 * V_36 ;
if ( V_103 == NULL || V_103 -> V_104 == V_105 )
return;
V_36 = V_103 -> V_36 ;
for ( V_43 = 0 ; ( V_36 -> V_106 -> V_107 ( V_36 ) & V_108 ) &&
V_43 < 65536 ; V_43 += 2 )
F_5 ( V_36 -> V_46 . V_98 ) ;
if ( V_43 )
F_38 ( V_36 , L_10 , V_43 ) ;
}
static int F_39 ( struct V_59 * V_60 , unsigned int V_109 ,
T_3 * V_8 )
{
if ( V_109 > V_110 )
return - V_111 ;
* V_8 = F_5 ( V_60 -> V_36 -> V_46 . V_112 + ( V_109 << 2 ) ) ;
return 0 ;
}
static int F_40 ( struct V_59 * V_60 , unsigned int V_109 ,
T_3 V_8 )
{
if ( V_109 > V_110 )
return - V_111 ;
F_2 ( V_8 , V_60 -> V_36 -> V_46 . V_112 + ( V_109 << 2 ) ) ;
return 0 ;
}
static void F_41 ( struct V_102 * V_103 )
{
struct V_35 * V_36 = V_103 -> V_36 ;
struct V_113 * V_114 = V_36 -> V_115 ;
struct V_116 * V_117 ;
unsigned int V_118 ;
F_42 (qc->sg, sg, qc->n_elem, si) {
T_3 V_119 , V_120 ;
V_119 = ( T_3 ) F_43 ( V_117 ) ;
V_120 = F_44 ( V_117 ) ;
V_114 [ V_118 ] . V_119 = F_45 ( V_119 ) ;
V_114 [ V_118 ] . V_121 = F_45 ( V_120 ) ;
F_32 ( L_11 , V_118 , V_119 , V_120 ) ;
}
V_114 [ V_118 - 1 ] . V_119 |= F_45 ( V_122 ) ;
}
static void F_46 ( struct V_102 * V_103 )
{
if ( ! ( V_103 -> V_74 & V_123 ) )
return;
F_41 ( V_103 ) ;
}
static void F_47 ( struct V_102 * V_103 )
{
struct V_35 * V_36 = V_103 -> V_36 ;
unsigned int V_97 = V_103 -> V_72 . V_74 & V_124 ;
struct V_1 * V_2 = V_36 -> V_37 -> V_38 ;
void T_1 * V_3 = V_2 -> V_3 ;
T_3 V_125 ;
F_48 () ;
F_2 ( V_36 -> V_126 , V_3 + V_127 ) ;
V_125 = F_5 ( V_3 + V_128 ) ;
V_125 &= ~ ( V_129 | V_130 ) ;
if ( V_125 & V_131 ) {
V_125 &= ~ V_131 ;
V_125 |= V_130 ;
}
if ( ! V_97 )
V_125 |= V_129 ;
F_2 ( V_125 , V_3 + V_128 ) ;
V_36 -> V_106 -> V_132 ( V_36 , & V_103 -> V_72 ) ;
}
static void F_49 ( struct V_102 * V_103 )
{
struct V_35 * V_36 = V_103 -> V_36 ;
struct V_1 * V_2 = V_36 -> V_37 -> V_38 ;
void T_1 * V_3 = V_2 -> V_3 ;
T_3 V_125 ;
V_125 = F_5 ( V_3 + V_128 ) ;
V_125 &= ~ V_130 ;
V_125 |= V_131 ;
F_2 ( V_125 , V_3 + V_128 ) ;
}
static void F_50 ( struct V_102 * V_103 )
{
struct V_35 * V_36 = V_103 -> V_36 ;
struct V_1 * V_2 = V_36 -> V_37 -> V_38 ;
void T_1 * V_3 = V_2 -> V_3 ;
T_3 V_125 ;
V_125 = F_5 ( V_3 + V_128 ) ;
if ( V_125 & V_131 ) {
V_125 &= ~ V_131 ;
V_125 |= V_130 ;
F_2 ( V_125 , V_3 + V_128 ) ;
}
F_51 ( V_36 ) ;
}
static T_4 F_52 ( struct V_35 * V_36 )
{
struct V_1 * V_2 = V_36 -> V_37 -> V_38 ;
T_4 V_133 = 0 ;
T_3 V_134 ;
V_134 = F_5 ( V_2 -> V_3 + V_135 ) ;
if ( V_134 & V_136 )
V_133 |= V_137 ;
if ( V_134 & V_138 )
V_133 |= V_139 ;
return V_133 ;
}
static void F_53 ( struct V_35 * V_36 )
{
struct V_1 * V_2 = V_36 -> V_37 -> V_38 ;
struct V_140 * V_141 = & V_36 -> V_60 . V_142 ;
int V_143 = 0 ;
T_3 V_144 ;
V_144 = F_5 ( V_2 -> V_3 + V_145 ) ;
if ( ! V_144 )
return;
F_25 ( L_12 , V_144 ) ;
F_54 ( V_141 ) ;
if ( V_144 & ( V_146 | V_147 ) ) {
F_55 ( V_141 ) ;
F_56 ( V_141 , L_13 , L_14 ) ;
V_143 = V_144 & V_148 ? 0 : 1 ;
}
if ( V_143 )
F_57 ( V_36 ) ;
else
F_58 ( V_36 ) ;
}
static void F_59 ( struct V_35 * V_36 )
{
struct V_102 * V_103 ;
int V_149 = 0 ;
V_103 = F_60 ( V_36 , V_36 -> V_60 . V_150 ) ;
if ( V_103 )
V_149 |= F_61 ( V_36 , V_103 ) ;
if ( ! V_149 )
F_15 ( V_36 ) ;
}
static T_5 F_62 ( int V_151 , void * V_152 )
{
struct V_153 * V_37 = V_152 ;
struct V_1 * V_2 = V_37 -> V_38 ;
void T_1 * V_3 = V_2 -> V_3 ;
unsigned int V_149 = 0 ;
struct V_35 * V_36 ;
T_3 V_154 ;
unsigned long V_74 ;
F_63 ( & V_37 -> V_155 , V_74 ) ;
V_154 = F_5 ( V_3 + V_41 ) ;
V_154 &= V_40 ;
if ( ! V_154 )
goto V_156;
F_2 ( ~ V_154 & 0x7ff , V_3 + V_41 ) ;
V_36 = V_37 -> V_157 [ 0 ] ;
if ( V_154 & V_158 )
F_59 ( V_36 ) ;
if ( V_154 & V_159 )
F_53 ( V_36 ) ;
V_149 = 1 ;
V_156:
F_64 ( & V_37 -> V_155 , V_74 ) ;
return F_65 ( V_149 ) ;
}
static void F_66 ( struct V_153 * V_37 )
{
struct V_35 * V_36 = V_37 -> V_157 [ 0 ] ;
struct V_54 * V_46 = & V_36 -> V_46 ;
struct V_1 * V_2 = V_37 -> V_38 ;
void T_1 * V_3 = V_2 -> V_3 ;
V_36 -> V_106 = & V_160 ;
V_36 -> V_161 = V_162 ;
V_36 -> V_163 = V_164 ;
V_36 -> V_74 |= V_165 ;
if ( V_2 -> type == V_166 )
V_36 -> V_74 |= V_167 ;
V_46 -> V_168 = V_3 + V_169 ;
V_46 -> V_50 = V_3 + V_170 ;
V_46 -> V_112 = V_3 + V_171 ;
V_46 -> V_48 = V_46 -> V_50 ;
V_46 -> V_98 = V_46 -> V_168 + ( V_172 << 2 ) ;
V_46 -> V_90 = V_46 -> V_168 + ( V_173 << 2 ) ;
V_46 -> V_78 = V_46 -> V_168 + ( V_174 << 2 ) ;
V_46 -> V_57 = V_46 -> V_168 + ( V_175 << 2 ) ;
V_46 -> V_58 = V_46 -> V_168 + ( V_176 << 2 ) ;
V_46 -> V_82 = V_46 -> V_168 + ( V_177 << 2 ) ;
V_46 -> V_84 = V_46 -> V_168 + ( V_178 << 2 ) ;
V_46 -> V_53 = V_46 -> V_168 + ( V_179 << 2 ) ;
V_46 -> V_47 = V_46 -> V_168 + ( V_180 << 2 ) ;
V_46 -> V_92 = V_46 -> V_168 + ( V_181 << 2 ) ;
}
static void F_67 ( struct V_153 * V_37 )
{
struct V_1 * V_2 = V_37 -> V_38 ;
void T_1 * V_3 = V_2 -> V_3 ;
T_3 V_8 ;
switch ( V_2 -> type ) {
case V_182 :
F_7 ( V_2 ) ;
break;
case V_183 :
case V_166 :
F_8 ( V_2 ) ;
break;
default:
F_68 ( V_37 -> V_94 , L_15 ) ;
break;
}
V_8 = F_5 ( V_3 + V_128 ) ;
V_8 |= V_184 ;
F_2 ( V_8 , V_3 + V_128 ) ;
V_8 = F_5 ( V_3 + V_128 ) ;
V_8 |= V_185 ;
V_8 |= V_186 ;
V_8 |= V_187 ;
F_2 ( V_8 , V_3 + V_128 ) ;
V_8 = F_5 ( V_3 + V_128 ) ;
V_8 &= ~ V_184 ;
F_2 ( V_8 , V_3 + V_128 ) ;
F_2 ( 0 , V_3 + V_41 ) ;
F_2 ( 0x7ff , V_3 + V_39 ) ;
F_2 ( V_188 , V_3 + V_189 ) ;
}
static int F_69 ( struct V_190 * V_191 )
{
const struct V_192 * V_193 ;
struct V_153 * V_37 ;
struct V_1 * V_2 ;
struct V_194 * V_195 ;
int V_151 ;
int V_196 = 0 ;
V_151 = F_70 ( V_191 , 0 ) ;
if ( V_151 <= 0 )
return - V_111 ;
V_2 = F_71 ( & V_191 -> V_94 , sizeof( struct V_1 ) ,
V_197 ) ;
if ( ! V_2 )
return - V_198 ;
V_193 = F_72 ( V_199 , & V_191 -> V_94 ) ;
if ( V_193 )
V_2 -> type = (enum V_200 ) V_193 -> V_45 ;
else
V_2 -> type = F_73 ( V_191 ) -> V_201 ;
V_2 -> V_202 = F_74 ( & V_191 -> V_94 , NULL ) ;
if ( F_75 ( V_2 -> V_202 ) ) {
F_76 ( & V_191 -> V_94 , L_16 ) ;
return F_77 ( V_2 -> V_202 ) ;
}
F_78 ( V_2 -> V_202 ) ;
V_37 = F_79 ( & V_191 -> V_94 , 1 ) ;
if ( ! V_37 ) {
F_76 ( & V_191 -> V_94 , L_17 ) ;
V_196 = - V_198 ;
goto V_203;
}
V_37 -> V_38 = V_2 ;
V_195 = F_80 ( V_191 , V_204 , 0 ) ;
V_2 -> V_3 = F_81 ( & V_191 -> V_94 , V_195 ) ;
if ( F_75 ( V_2 -> V_3 ) ) {
V_196 = F_77 ( V_2 -> V_3 ) ;
goto V_203;
}
F_66 ( V_37 ) ;
F_67 ( V_37 ) ;
V_196 = F_82 ( V_37 , V_151 , F_62 , 0 ,
& V_205 ) ;
if ( ! V_196 )
return 0 ;
V_203:
F_83 ( V_2 -> V_202 ) ;
return V_196 ;
}
static int F_84 ( struct V_190 * V_191 )
{
struct V_153 * V_37 = F_85 ( V_191 ) ;
struct V_1 * V_2 = V_37 -> V_38 ;
void T_1 * V_3 = V_2 -> V_3 ;
F_86 ( V_37 ) ;
F_2 ( 0 , V_3 + V_189 ) ;
F_2 ( 0 , V_3 + V_41 ) ;
F_2 ( 0x7ff , V_3 + V_39 ) ;
F_83 ( V_2 -> V_202 ) ;
return 0 ;
}
static int F_87 ( struct V_51 * V_94 )
{
struct V_153 * V_37 = F_88 ( V_94 ) ;
struct V_1 * V_2 = V_37 -> V_38 ;
void T_1 * V_3 = V_2 -> V_3 ;
int V_196 ;
V_196 = F_89 ( V_37 , V_206 ) ;
if ( ! V_196 ) {
F_2 ( 0 , V_3 + V_189 ) ;
F_2 ( 0x7ff , V_3 + V_39 ) ;
F_83 ( V_2 -> V_202 ) ;
}
return V_196 ;
}
static int F_90 ( struct V_51 * V_94 )
{
struct V_153 * V_37 = F_88 ( V_94 ) ;
struct V_1 * V_2 = V_37 -> V_38 ;
void T_1 * V_3 = V_2 -> V_3 ;
F_78 ( V_2 -> V_202 ) ;
F_2 ( 0 , V_3 + V_41 ) ;
F_2 ( 0x7ff , V_3 + V_39 ) ;
F_2 ( V_188 , V_3 + V_189 ) ;
F_91 ( V_37 ) ;
return 0 ;
}
static int F_92 ( struct V_51 * V_94 )
{
struct V_153 * V_37 = F_88 ( V_94 ) ;
struct V_1 * V_2 = V_37 -> V_38 ;
F_78 ( V_2 -> V_202 ) ;
F_66 ( V_37 ) ;
F_67 ( V_37 ) ;
F_91 ( V_37 ) ;
return 0 ;
}
