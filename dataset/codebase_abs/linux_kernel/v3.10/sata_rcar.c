static void F_1 ( struct V_1 * V_2 )
{
F_2 ( 0 , V_2 -> V_3 + V_4 ) ;
F_2 ( V_5 , V_2 -> V_3 + V_6 ) ;
F_3 ( 10 ) ;
F_2 ( 0 , V_2 -> V_3 + V_6 ) ;
}
static void F_4 ( struct V_1 * V_2 , T_1 V_7 , T_2 V_8 ,
int V_9 )
{
int V_10 ;
F_2 ( 0 , V_2 -> V_3 + V_6 ) ;
F_2 ( V_11 , V_2 -> V_3 + V_12 ) ;
F_2 ( V_8 , V_2 -> V_3 + V_13 ) ;
if ( V_9 )
V_7 |= V_14 ;
F_2 ( V_15 | V_7 , V_2 -> V_3 + V_4 ) ;
for ( V_10 = 0 ; V_10 < 100 ; V_10 ++ ) {
V_8 = F_5 ( V_2 -> V_3 + V_16 ) ;
if ( V_8 & V_17 )
break;
}
if ( V_10 >= 100 )
F_6 ( L_1 , V_18 ) ;
F_2 ( 0 , V_2 -> V_3 + V_4 ) ;
}
static void F_7 ( struct V_19 * V_20 )
{
struct V_1 * V_2 = V_20 -> V_21 -> V_22 ;
F_2 ( 0x7ff , V_2 -> V_3 + V_23 ) ;
F_8 ( V_20 ) ;
}
static void F_9 ( struct V_19 * V_20 )
{
struct V_1 * V_2 = V_20 -> V_21 -> V_22 ;
F_2 ( ~ V_24 , V_2 -> V_3 + V_25 ) ;
F_10 ( V_20 ) ;
F_2 ( 0x7ff & ~ V_24 , V_2 -> V_3 + V_23 ) ;
}
static void F_11 ( void T_3 * V_7 , void * V_26 , int V_27 )
{
T_1 * V_28 = V_26 ;
while ( V_27 -- ) {
T_1 V_29 = F_5 ( V_7 ) ;
* V_28 ++ = V_29 ;
}
}
static void F_12 ( void T_3 * V_7 , void * V_26 , int V_27 )
{
const T_1 * V_28 = V_26 ;
while ( V_27 -- )
F_2 ( * V_28 ++ , V_7 ) ;
}
static T_4 F_13 ( struct V_19 * V_20 )
{
return F_5 ( V_20 -> V_30 . V_31 ) ;
}
static T_4 F_14 ( struct V_19 * V_20 )
{
return F_5 ( V_20 -> V_30 . V_32 ) ;
}
static void F_15 ( struct V_19 * V_20 , T_4 V_33 )
{
F_2 ( V_33 , V_20 -> V_30 . V_34 ) ;
}
static void F_16 ( struct V_19 * V_20 , unsigned int V_35 )
{
F_2 ( V_36 , V_20 -> V_30 . V_37 ) ;
F_17 ( V_20 ) ;
}
static unsigned int F_18 ( struct V_19 * V_20 ,
unsigned int V_35 )
{
struct V_38 * V_30 = & V_20 -> V_30 ;
T_4 V_39 , V_40 ;
F_16 ( V_20 , V_35 ) ;
F_2 ( 0x55 , V_30 -> V_41 ) ;
F_2 ( 0xaa , V_30 -> V_42 ) ;
F_2 ( 0xaa , V_30 -> V_41 ) ;
F_2 ( 0x55 , V_30 -> V_42 ) ;
F_2 ( 0x55 , V_30 -> V_41 ) ;
F_2 ( 0xaa , V_30 -> V_42 ) ;
V_39 = F_5 ( V_30 -> V_41 ) ;
V_40 = F_5 ( V_30 -> V_42 ) ;
if ( V_39 == 0x55 && V_40 == 0xaa )
return 1 ;
return 0 ;
}
static int F_19 ( struct V_43 * V_44 ,
unsigned long V_45 )
{
struct V_19 * V_20 = V_44 -> V_20 ;
F_20 ( V_20 , V_46 ) ;
return F_21 ( V_44 , V_45 ) ;
}
static int F_22 ( struct V_19 * V_20 , unsigned long V_45 )
{
struct V_38 * V_30 = & V_20 -> V_30 ;
F_23 ( L_2 , V_20 -> V_47 ) ;
F_2 ( V_20 -> V_33 , V_30 -> V_34 ) ;
F_3 ( 20 ) ;
F_2 ( V_20 -> V_33 | V_48 , V_30 -> V_34 ) ;
F_3 ( 20 ) ;
F_2 ( V_20 -> V_33 , V_30 -> V_34 ) ;
V_20 -> V_49 = V_20 -> V_33 ;
return F_19 ( & V_20 -> V_44 , V_45 ) ;
}
static int F_24 ( struct V_43 * V_44 , unsigned int * V_50 ,
unsigned long V_45 )
{
struct V_19 * V_20 = V_44 -> V_20 ;
unsigned int V_51 = 0 ;
int V_52 ;
T_4 V_53 ;
if ( F_18 ( V_20 , 0 ) )
V_51 |= 1 << 0 ;
F_23 ( L_3 , V_51 ) ;
V_52 = F_22 ( V_20 , V_45 ) ;
if ( V_52 && ( V_52 != - V_54 || F_25 ( V_44 ) ) ) {
F_26 ( V_44 , L_4 , V_52 ) ;
return V_52 ;
}
V_50 [ 0 ] = F_27 ( & V_44 -> V_35 [ 0 ] , V_51 , & V_53 ) ;
F_23 ( L_5 , V_50 [ 0 ] ) ;
return 0 ;
}
static void F_28 ( struct V_19 * V_20 ,
const struct V_55 * V_56 )
{
struct V_38 * V_30 = & V_20 -> V_30 ;
unsigned int V_57 = V_56 -> V_58 & V_59 ;
if ( V_56 -> V_33 != V_20 -> V_49 ) {
F_2 ( V_56 -> V_33 , V_30 -> V_34 ) ;
V_20 -> V_49 = V_56 -> V_33 ;
F_29 ( V_20 ) ;
}
if ( V_57 && ( V_56 -> V_58 & V_60 ) ) {
F_2 ( V_56 -> V_61 , V_30 -> V_62 ) ;
F_2 ( V_56 -> V_63 , V_30 -> V_41 ) ;
F_2 ( V_56 -> V_64 , V_30 -> V_42 ) ;
F_2 ( V_56 -> V_65 , V_30 -> V_66 ) ;
F_2 ( V_56 -> V_67 , V_30 -> V_68 ) ;
F_30 ( L_6 ,
V_56 -> V_61 ,
V_56 -> V_63 ,
V_56 -> V_64 ,
V_56 -> V_65 ,
V_56 -> V_67 ) ;
}
if ( V_57 ) {
F_2 ( V_56 -> V_69 , V_30 -> V_62 ) ;
F_2 ( V_56 -> V_39 , V_30 -> V_41 ) ;
F_2 ( V_56 -> V_40 , V_30 -> V_42 ) ;
F_2 ( V_56 -> V_70 , V_30 -> V_66 ) ;
F_2 ( V_56 -> V_71 , V_30 -> V_68 ) ;
F_30 ( L_7 ,
V_56 -> V_69 ,
V_56 -> V_39 ,
V_56 -> V_40 ,
V_56 -> V_70 ,
V_56 -> V_71 ) ;
}
if ( V_56 -> V_58 & V_72 ) {
F_2 ( V_56 -> V_35 , V_30 -> V_37 ) ;
F_30 ( L_8 , V_56 -> V_35 ) ;
}
F_29 ( V_20 ) ;
}
static void F_31 ( struct V_19 * V_20 , struct V_55 * V_56 )
{
struct V_38 * V_30 = & V_20 -> V_30 ;
V_56 -> V_73 = F_13 ( V_20 ) ;
V_56 -> V_69 = F_5 ( V_30 -> V_74 ) ;
V_56 -> V_39 = F_5 ( V_30 -> V_41 ) ;
V_56 -> V_40 = F_5 ( V_30 -> V_42 ) ;
V_56 -> V_70 = F_5 ( V_30 -> V_66 ) ;
V_56 -> V_71 = F_5 ( V_30 -> V_68 ) ;
V_56 -> V_35 = F_5 ( V_30 -> V_37 ) ;
if ( V_56 -> V_58 & V_60 ) {
F_2 ( V_56 -> V_33 | V_75 , V_30 -> V_34 ) ;
V_56 -> V_61 = F_5 ( V_30 -> V_74 ) ;
V_56 -> V_63 = F_5 ( V_30 -> V_41 ) ;
V_56 -> V_64 = F_5 ( V_30 -> V_42 ) ;
V_56 -> V_65 = F_5 ( V_30 -> V_66 ) ;
V_56 -> V_67 = F_5 ( V_30 -> V_68 ) ;
F_2 ( V_56 -> V_33 , V_30 -> V_34 ) ;
V_20 -> V_49 = V_56 -> V_33 ;
}
}
static void F_32 ( struct V_19 * V_20 ,
const struct V_55 * V_56 )
{
F_23 ( L_9 , V_20 -> V_47 , V_56 -> V_73 ) ;
F_2 ( V_56 -> V_73 , V_20 -> V_30 . V_76 ) ;
F_17 ( V_20 ) ;
}
static unsigned int F_33 ( struct V_77 * V_78 ,
unsigned char * V_79 ,
unsigned int V_80 , int V_81 )
{
struct V_19 * V_20 = V_78 -> V_44 -> V_20 ;
void T_3 * V_82 = V_20 -> V_30 . V_82 ;
unsigned int V_83 = V_80 >> 1 ;
if ( V_81 == V_84 )
F_11 ( V_82 , V_79 , V_83 ) ;
else
F_12 ( V_82 , V_79 , V_83 ) ;
if ( F_34 ( V_80 & 0x01 ) ) {
unsigned char V_85 [ 2 ] = { } ;
V_79 += V_80 - 1 ;
if ( V_81 == V_84 ) {
F_11 ( V_82 , V_85 , 1 ) ;
* V_79 = V_85 [ 0 ] ;
} else {
V_85 [ 0 ] = * V_79 ;
F_12 ( V_82 , V_85 , 1 ) ;
}
V_83 ++ ;
}
return V_83 << 1 ;
}
static void F_35 ( struct V_86 * V_87 )
{
int V_27 ;
struct V_19 * V_20 ;
if ( V_87 == NULL || V_87 -> V_88 == V_89 )
return;
V_20 = V_87 -> V_20 ;
for ( V_27 = 0 ; ( V_20 -> V_90 -> V_91 ( V_20 ) & V_92 ) &&
V_27 < 65536 ; V_27 += 2 )
F_5 ( V_20 -> V_30 . V_82 ) ;
if ( V_27 )
F_36 ( V_20 , L_10 , V_27 ) ;
}
static int F_37 ( struct V_43 * V_44 , unsigned int V_93 ,
T_2 * V_8 )
{
if ( V_93 > V_94 )
return - V_95 ;
* V_8 = F_5 ( V_44 -> V_20 -> V_30 . V_96 + ( V_93 << 2 ) ) ;
return 0 ;
}
static int F_38 ( struct V_43 * V_44 , unsigned int V_93 ,
T_2 V_8 )
{
if ( V_93 > V_94 )
return - V_95 ;
F_2 ( V_8 , V_44 -> V_20 -> V_30 . V_96 + ( V_93 << 2 ) ) ;
return 0 ;
}
static void F_39 ( struct V_86 * V_87 )
{
struct V_19 * V_20 = V_87 -> V_20 ;
struct V_97 * V_98 = V_20 -> V_99 ;
struct V_100 * V_101 ;
unsigned int V_102 , V_103 ;
V_103 = 0 ;
F_40 (qc->sg, sg, qc->n_elem, si) {
T_2 V_104 , V_105 , V_106 ;
V_104 = ( T_2 ) F_41 ( V_101 ) ;
V_105 = F_42 ( V_101 ) ;
while ( V_105 ) {
V_106 = V_105 ;
if ( V_106 > 0x1ffffffe )
V_106 = 0x1ffffffe ;
V_98 [ V_103 ] . V_104 = F_43 ( V_104 ) ;
V_98 [ V_103 ] . V_107 = F_43 ( V_106 ) ;
F_30 ( L_11 , V_103 , V_104 , V_106 ) ;
V_103 ++ ;
V_105 -= V_106 ;
V_104 += V_106 ;
}
}
V_98 [ V_103 - 1 ] . V_104 |= F_43 ( V_108 ) ;
}
static void F_44 ( struct V_86 * V_87 )
{
if ( ! ( V_87 -> V_58 & V_109 ) )
return;
F_39 ( V_87 ) ;
}
static void F_45 ( struct V_86 * V_87 )
{
struct V_19 * V_20 = V_87 -> V_20 ;
unsigned int V_81 = V_87 -> V_56 . V_58 & V_110 ;
T_2 V_111 ;
struct V_1 * V_2 = V_20 -> V_21 -> V_22 ;
F_46 () ;
F_2 ( V_20 -> V_112 , V_2 -> V_3 + V_113 ) ;
V_111 = F_5 ( V_2 -> V_3 + V_114 ) ;
V_111 &= ~ ( V_115 | V_116 ) ;
if ( V_111 & V_117 ) {
V_111 &= ~ V_117 ;
V_111 |= V_116 ;
}
if ( ! V_81 )
V_111 |= V_115 ;
F_2 ( V_111 , V_2 -> V_3 + V_114 ) ;
V_20 -> V_90 -> V_118 ( V_20 , & V_87 -> V_56 ) ;
}
static void F_47 ( struct V_86 * V_87 )
{
struct V_19 * V_20 = V_87 -> V_20 ;
T_2 V_111 ;
struct V_1 * V_2 = V_20 -> V_21 -> V_22 ;
V_111 = F_5 ( V_2 -> V_3 + V_114 ) ;
V_111 &= ~ V_116 ;
V_111 |= V_117 ;
F_2 ( V_111 , V_2 -> V_3 + V_114 ) ;
}
static void F_48 ( struct V_86 * V_87 )
{
struct V_19 * V_20 = V_87 -> V_20 ;
struct V_1 * V_2 = V_20 -> V_21 -> V_22 ;
T_2 V_111 ;
V_111 = F_5 ( V_2 -> V_3 + V_114 ) ;
if ( V_111 & V_117 ) {
V_111 &= ~ V_117 ;
V_111 |= V_116 ;
F_2 ( V_111 , V_2 -> V_3 + V_114 ) ;
}
F_49 ( V_20 ) ;
}
static T_4 F_50 ( struct V_19 * V_20 )
{
struct V_1 * V_2 = V_20 -> V_21 -> V_22 ;
T_2 V_119 ;
T_4 V_120 = 0 ;
V_119 = F_5 ( V_2 -> V_3 + V_121 ) ;
if ( V_119 & V_122 )
V_120 |= V_123 ;
if ( V_119 & V_124 )
V_120 |= V_125 ;
return V_120 ;
}
static void F_51 ( struct V_19 * V_20 )
{
struct V_1 * V_2 = V_20 -> V_21 -> V_22 ;
struct V_126 * V_127 = & V_20 -> V_44 . V_128 ;
int V_129 = 0 ;
T_2 V_130 ;
V_130 = F_5 ( V_2 -> V_3 + V_131 ) ;
if ( ! V_130 )
return;
F_23 ( L_12 , V_130 ) ;
F_52 ( V_127 ) ;
if ( V_130 & ( V_132 | V_133 ) ) {
F_53 ( V_127 ) ;
F_54 ( V_127 , L_13 , L_14 ) ;
V_129 = V_130 & V_134 ? 0 : 1 ;
}
if ( V_129 )
F_55 ( V_20 ) ;
else
F_56 ( V_20 ) ;
}
static void F_57 ( struct V_19 * V_20 )
{
struct V_86 * V_87 ;
int V_135 = 0 ;
V_87 = F_58 ( V_20 , V_20 -> V_44 . V_136 ) ;
if ( V_87 )
V_135 |= F_59 ( V_20 , V_87 ) ;
if ( ! V_135 )
F_13 ( V_20 ) ;
}
static T_5 F_60 ( int V_137 , void * V_138 )
{
struct V_139 * V_21 = V_138 ;
struct V_1 * V_2 = V_21 -> V_22 ;
struct V_19 * V_20 ;
unsigned int V_135 = 0 ;
T_2 V_140 ;
unsigned long V_58 ;
F_61 ( & V_21 -> V_141 , V_58 ) ;
V_140 = F_5 ( V_2 -> V_3 + V_25 ) ;
V_140 &= V_24 ;
if ( ! V_140 )
goto V_142;
F_2 ( ~ V_140 & 0x7ff , V_2 -> V_3 + V_25 ) ;
V_20 = V_21 -> V_143 [ 0 ] ;
if ( V_140 & V_144 )
F_57 ( V_20 ) ;
if ( V_140 & V_145 )
F_51 ( V_20 ) ;
V_135 = 1 ;
V_142:
F_62 ( & V_21 -> V_141 , V_58 ) ;
return F_63 ( V_135 ) ;
}
static void F_64 ( struct V_139 * V_21 )
{
struct V_19 * V_20 = V_21 -> V_143 [ 0 ] ;
struct V_38 * V_30 = & V_20 -> V_30 ;
struct V_1 * V_2 = V_21 -> V_22 ;
V_20 -> V_90 = & V_146 ;
V_20 -> V_147 = V_148 ;
V_20 -> V_149 = V_150 ;
V_20 -> V_58 |= V_151 ;
V_30 -> V_152 = V_2 -> V_3 + V_153 ;
V_30 -> V_34 = V_2 -> V_3 + V_154 ;
V_30 -> V_96 = V_2 -> V_3 + V_155 ;
V_30 -> V_32 = V_30 -> V_34 ;
V_30 -> V_82 = V_30 -> V_152 + ( V_156 << 2 ) ;
V_30 -> V_74 = V_30 -> V_152 + ( V_157 << 2 ) ;
V_30 -> V_62 = V_30 -> V_152 + ( V_158 << 2 ) ;
V_30 -> V_41 = V_30 -> V_152 + ( V_159 << 2 ) ;
V_30 -> V_42 = V_30 -> V_152 + ( V_160 << 2 ) ;
V_30 -> V_66 = V_30 -> V_152 + ( V_161 << 2 ) ;
V_30 -> V_68 = V_30 -> V_152 + ( V_162 << 2 ) ;
V_30 -> V_37 = V_30 -> V_152 + ( V_163 << 2 ) ;
V_30 -> V_31 = V_30 -> V_152 + ( V_164 << 2 ) ;
V_30 -> V_76 = V_30 -> V_152 + ( V_165 << 2 ) ;
}
static void F_65 ( struct V_139 * V_21 )
{
struct V_1 * V_2 = V_21 -> V_22 ;
T_2 V_8 ;
F_1 ( V_2 ) ;
F_4 ( V_2 , V_166 , 0x00200188 , 0 ) ;
F_4 ( V_2 , V_166 , 0x00200188 , 1 ) ;
F_4 ( V_2 , V_167 , 0x0000A061 , 0 ) ;
F_4 ( V_2 , V_168 , 0x20000000 , 0 ) ;
F_4 ( V_2 , V_168 , 0x20000000 , 1 ) ;
F_4 ( V_2 , V_169 , 0x28E80000 , 0 ) ;
V_8 = F_5 ( V_2 -> V_3 + V_114 ) ;
V_8 |= V_170 ;
F_2 ( V_8 , V_2 -> V_3 + V_114 ) ;
V_8 = F_5 ( V_2 -> V_3 + V_114 ) ;
V_8 |= V_171 ;
V_8 |= V_172 ;
V_8 |= V_173 ;
F_2 ( V_8 , V_2 -> V_3 + V_114 ) ;
V_8 = F_5 ( V_2 -> V_3 + V_114 ) ;
V_8 &= ~ V_170 ;
F_2 ( V_8 , V_2 -> V_3 + V_114 ) ;
F_2 ( 0 , V_2 -> V_3 + V_25 ) ;
F_2 ( 0x7ff , V_2 -> V_3 + V_23 ) ;
F_2 ( V_174 , V_2 -> V_3 + V_175 ) ;
}
static int F_66 ( struct V_176 * V_177 )
{
struct V_139 * V_21 ;
struct V_1 * V_2 ;
struct V_178 * V_179 ;
int V_137 ;
int V_180 = 0 ;
V_179 = F_67 ( V_177 , V_181 , 0 ) ;
if ( V_179 == NULL )
return - V_95 ;
V_137 = F_68 ( V_177 , 0 ) ;
if ( V_137 <= 0 )
return - V_95 ;
V_2 = F_69 ( & V_177 -> V_78 , sizeof( struct V_1 ) ,
V_182 ) ;
if ( ! V_2 )
return - V_183 ;
V_2 -> V_184 = F_70 ( & V_177 -> V_78 , NULL ) ;
if ( F_71 ( V_2 -> V_184 ) ) {
F_72 ( & V_177 -> V_78 , L_15 ) ;
return F_73 ( V_2 -> V_184 ) ;
}
F_74 ( V_2 -> V_184 ) ;
V_21 = F_75 ( & V_177 -> V_78 , 1 ) ;
if ( ! V_21 ) {
F_72 ( & V_177 -> V_78 , L_16 ) ;
V_180 = - V_183 ;
goto V_185;
}
V_21 -> V_22 = V_2 ;
V_2 -> V_3 = F_76 ( & V_177 -> V_78 , V_179 ) ;
if ( F_71 ( V_2 -> V_3 ) ) {
V_180 = F_73 ( V_2 -> V_3 ) ;
goto V_185;
}
F_64 ( V_21 ) ;
F_65 ( V_21 ) ;
V_180 = F_77 ( V_21 , V_137 , F_60 , 0 ,
& V_186 ) ;
if ( ! V_180 )
return 0 ;
V_185:
F_78 ( V_2 -> V_184 ) ;
return V_180 ;
}
static int F_79 ( struct V_176 * V_177 )
{
struct V_139 * V_21 = F_80 ( & V_177 -> V_78 ) ;
struct V_1 * V_2 = V_21 -> V_22 ;
F_81 ( V_21 ) ;
F_2 ( 0 , V_2 -> V_3 + V_175 ) ;
F_2 ( 0 , V_2 -> V_3 + V_25 ) ;
F_2 ( 0x7ff , V_2 -> V_3 + V_23 ) ;
F_78 ( V_2 -> V_184 ) ;
return 0 ;
}
static int F_82 ( struct V_35 * V_78 )
{
struct V_139 * V_21 = F_80 ( V_78 ) ;
struct V_1 * V_2 = V_21 -> V_22 ;
int V_180 ;
V_180 = F_83 ( V_21 , V_187 ) ;
if ( ! V_180 ) {
F_2 ( 0 , V_2 -> V_3 + V_175 ) ;
F_2 ( 0x7ff , V_2 -> V_3 + V_23 ) ;
F_78 ( V_2 -> V_184 ) ;
}
return V_180 ;
}
static int F_84 ( struct V_35 * V_78 )
{
struct V_139 * V_21 = F_80 ( V_78 ) ;
struct V_1 * V_2 = V_21 -> V_22 ;
F_74 ( V_2 -> V_184 ) ;
F_2 ( 0 , V_2 -> V_3 + V_25 ) ;
F_2 ( 0x7ff , V_2 -> V_3 + V_23 ) ;
F_2 ( V_174 , V_2 -> V_3 + V_175 ) ;
F_85 ( V_21 ) ;
return 0 ;
}
