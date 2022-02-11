static void F_1 ( void T_1 * V_1 )
{
F_2 ( V_2 | V_3 | V_4 |
V_5 , V_1 + V_6 ) ;
F_2 ( 0 , V_1 + V_7 ) ;
F_2 ( 0 , V_1 + V_8 ) ;
F_2 ( 0 , V_1 + V_9 ) ;
F_2 ( 0 , V_1 + V_10 ) ;
F_2 ( 0 , V_1 + V_11 ) ;
F_2 ( 0 , V_1 + V_12 ) ;
F_2 ( 0 , V_1 + V_13 ) ;
F_2 ( 0 , V_1 + V_14 ) ;
F_2 ( 0 , V_1 + V_15 ) ;
F_2 ( 0 , V_1 + V_16 ) ;
}
static bool F_3 ( void T_1 * V_1 )
{
return ! ! ( F_4 ( V_1 + V_6 ) & V_17 ) ;
}
static int F_5 ( int V_18 )
{
int V_19 ;
if ( V_18 == 0 )
V_19 = 3 ;
else if ( V_18 < 3 )
V_19 = 2 ;
else
V_19 = 1 ;
return V_19 << V_20 ;
}
static void F_6 ( void T_1 * V_1 , int V_18 )
{
F_2 ( V_21 | V_22 |
F_5 ( V_18 ) |
( V_18 << V_23 ) , V_1 + V_7 ) ;
}
static void F_7 ( unsigned long V_24 )
{
__asm__ volatile (
"0:\n"
"mov r0, r0\n"
"subs %0, %1, #1\n"
"bge 0b\n"
: "=r" (count)
: "0" (count)
);
}
static unsigned long F_8 ( void T_1 * V_1 ,
unsigned long V_25 )
{
unsigned long V_26 = ( 1250 + 35 ) / 25 - V_25 ;
unsigned long V_27 = V_26 ;
while ( ! F_3 ( V_1 ) && V_27 -- )
F_7 ( 1 ) ;
return V_26 - V_27 ;
}
static void F_9 ( void T_1 * V_1 , unsigned long V_28 ,
unsigned long V_29 )
{
F_2 ( V_5 | V_4 | V_28 , V_1 + V_6 ) ;
F_7 ( V_29 ) ;
}
static void F_10 ( void T_1 * V_1 , unsigned long V_28 ,
bool V_30 , unsigned long V_31 , unsigned long V_25 ,
unsigned long V_32 )
{
F_7 ( V_25 ) ;
if ( V_30 )
V_25 += F_8 ( V_1 , V_25 ) ;
F_2 ( V_5 | V_4 | V_28 , V_1 + V_6 ) ;
if ( V_31 > V_25 && V_31 - V_25 > V_32 )
F_7 ( V_31 - V_25 ) ;
else
F_7 ( V_32 ) ;
}
static T_2 F_11 ( struct V_33 * V_34 ,
unsigned long V_28 ,
bool V_35 )
{
void T_1 * V_1 = V_34 -> V_36 ;
const struct V_37 * V_38 = & V_34 -> V_38 ;
unsigned long V_31 = V_35 ? V_38 -> V_39 : V_38 -> V_40 ;
unsigned long V_25 = V_35 ? V_38 -> V_41 : V_38 -> V_42 ;
unsigned long V_32 = V_35 ? V_38 -> V_43 : V_38 -> V_44 ;
F_9 ( V_1 , V_28 , V_38 -> V_45 ) ;
F_2 ( V_5 | V_28 , V_1 + V_6 ) ;
F_10 ( V_1 , V_28 , V_34 -> V_30 , V_31 , V_25 , V_32 ) ;
return F_4 ( V_1 + V_11 ) ;
}
static T_2 F_12 ( struct V_33 * V_34 ,
unsigned long V_28 )
{
return F_11 ( V_34 , V_28 , true ) ;
}
static T_2 F_13 ( struct V_33 * V_34 ,
unsigned long V_28 )
{
return F_11 ( V_34 , V_28 , false ) ;
}
static void F_14 ( struct V_33 * V_34 ,
T_2 V_46 , unsigned long V_28 ,
bool V_35 )
{
void T_1 * V_1 = V_34 -> V_36 ;
const struct V_37 * V_38 = & V_34 -> V_38 ;
unsigned long V_31 = V_35 ? V_38 -> V_39 : V_38 -> V_40 ;
unsigned long V_25 = V_35 ? V_38 -> V_41 : V_38 -> V_42 ;
unsigned long V_32 = V_35 ? V_38 -> V_43 : V_38 -> V_44 ;
F_9 ( V_1 , V_28 , V_38 -> V_45 ) ;
F_2 ( V_46 , V_1 + V_10 ) ;
F_2 ( V_4 | V_28 , V_1 + V_6 ) ;
F_10 ( V_1 , V_28 , V_34 -> V_30 , V_31 , V_25 , V_32 ) ;
}
static void F_15 ( struct V_33 * V_34 ,
T_2 V_46 , unsigned long V_28 )
{
F_14 ( V_34 , V_46 , V_28 , true ) ;
}
static void F_16 ( struct V_33 * V_34 ,
T_2 V_46 , unsigned long V_28 )
{
F_14 ( V_34 , V_46 , V_28 , false ) ;
}
static void F_17 ( struct V_47 * V_48 ,
struct V_49 * V_50 )
{
struct V_33 * V_34 = V_48 -> V_51 -> V_52 ;
struct V_49 * V_53 = F_18 ( V_50 ) ;
unsigned long V_54 = 1000000 / ( 200 / 5 ) ;
F_19 ( V_50 , V_50 -> V_18 , & V_34 -> V_38 , V_54 , 0 ) ;
if ( V_53 && V_53 -> V_18 ) {
struct V_37 V_38 ;
F_19 ( V_53 , V_53 -> V_18 , & V_38 , V_54 , 0 ) ;
F_20 ( & V_38 , & V_34 -> V_38 , & V_34 -> V_38 ,
V_55 | V_56 ) ;
}
V_34 -> V_30 = F_21 ( V_50 ) ;
F_6 ( V_34 -> V_36 ,
V_50 -> V_18 - V_57 ) ;
}
static T_3 F_22 ( struct V_47 * V_48 )
{
struct V_33 * V_34 = V_48 -> V_51 -> V_52 ;
return F_12 ( V_34 , V_58 ) ;
}
static T_3 F_23 ( struct V_47 * V_48 )
{
struct V_33 * V_34 = V_48 -> V_51 -> V_52 ;
return F_12 ( V_34 , V_59 ) ;
}
static void F_24 ( struct V_47 * V_48 ,
const struct V_60 * V_61 )
{
struct V_33 * V_34 = V_48 -> V_51 -> V_52 ;
unsigned int V_62 = V_61 -> V_63 & V_64 ;
if ( V_61 -> V_65 != V_48 -> V_66 ) {
F_15 ( V_34 , V_61 -> V_65 , V_67 ) ;
V_48 -> V_66 = V_61 -> V_65 ;
F_25 ( V_48 ) ;
}
if ( V_62 && ( V_61 -> V_63 & V_68 ) ) {
F_15 ( V_34 , V_61 -> V_69 ,
V_70 ) ;
F_15 ( V_34 , V_61 -> V_71 ,
V_72 ) ;
F_15 ( V_34 , V_61 -> V_73 ,
V_74 ) ;
F_15 ( V_34 , V_61 -> V_75 ,
V_76 ) ;
F_15 ( V_34 , V_61 -> V_77 ,
V_78 ) ;
}
if ( V_62 ) {
F_15 ( V_34 , V_61 -> V_79 ,
V_70 ) ;
F_15 ( V_34 , V_61 -> V_80 , V_72 ) ;
F_15 ( V_34 , V_61 -> V_81 , V_74 ) ;
F_15 ( V_34 , V_61 -> V_82 , V_76 ) ;
F_15 ( V_34 , V_61 -> V_83 , V_78 ) ;
}
if ( V_61 -> V_63 & V_84 )
F_15 ( V_34 , V_61 -> V_85 ,
V_86 ) ;
F_25 ( V_48 ) ;
}
static void F_26 ( struct V_47 * V_48 , struct V_60 * V_61 )
{
struct V_33 * V_34 = V_48 -> V_51 -> V_52 ;
V_61 -> V_87 = F_22 ( V_48 ) ;
V_61 -> V_79 = F_12 ( V_34 , V_70 ) ;
V_61 -> V_80 = F_12 ( V_34 , V_72 ) ;
V_61 -> V_81 = F_12 ( V_34 , V_74 ) ;
V_61 -> V_82 = F_12 ( V_34 , V_76 ) ;
V_61 -> V_83 = F_12 ( V_34 , V_78 ) ;
V_61 -> V_85 = F_12 ( V_34 , V_86 ) ;
if ( V_61 -> V_63 & V_68 ) {
F_15 ( V_34 , V_61 -> V_65 | V_88 ,
V_67 ) ;
V_61 -> V_69 = F_12 ( V_34 ,
V_70 ) ;
V_61 -> V_71 = F_12 ( V_34 ,
V_72 ) ;
V_61 -> V_73 = F_12 ( V_34 ,
V_74 ) ;
V_61 -> V_75 = F_12 ( V_34 ,
V_76 ) ;
V_61 -> V_77 = F_12 ( V_34 ,
V_78 ) ;
F_15 ( V_34 , V_61 -> V_65 , V_67 ) ;
V_48 -> V_66 = V_61 -> V_65 ;
}
}
static void F_27 ( struct V_47 * V_48 ,
const struct V_60 * V_61 )
{
struct V_33 * V_34 = V_48 -> V_51 -> V_52 ;
F_15 ( V_34 , V_61 -> V_87 ,
V_89 ) ;
F_28 ( V_48 ) ;
}
static void F_29 ( struct V_47 * V_48 , unsigned int V_85 )
{
struct V_33 * V_34 = V_48 -> V_51 -> V_52 ;
T_3 V_90 = V_91 ;
if ( V_85 != 0 )
V_90 |= V_92 ;
F_15 ( V_34 , V_90 , V_86 ) ;
F_28 ( V_48 ) ;
}
static void F_30 ( struct V_47 * V_48 , T_3 V_65 )
{
struct V_33 * V_34 = V_48 -> V_51 -> V_52 ;
F_15 ( V_34 , V_65 , V_67 ) ;
}
static unsigned int F_31 ( struct V_49 * V_50 ,
unsigned char * V_93 ,
unsigned int V_94 , int V_95 )
{
struct V_47 * V_48 = V_50 -> V_96 -> V_48 ;
struct V_33 * V_34 = V_48 -> V_51 -> V_52 ;
T_2 * V_97 = ( T_2 * ) V_93 ;
unsigned int V_98 = V_94 >> 1 ;
while ( V_98 -- )
if ( V_95 == V_99 )
* V_97 ++ = F_32 (
F_13 (
V_34 , V_100 ) ) ;
else
F_16 ( V_34 , F_33 ( * V_97 ++ ) ,
V_100 ) ;
if ( F_34 ( V_94 & 0x01 ) ) {
unsigned char V_101 [ 2 ] = { } ;
V_93 += V_94 - 1 ;
if ( V_95 == V_99 ) {
* V_101 = F_32 (
F_13 (
V_34 , V_100 ) ) ;
* V_93 = V_101 [ 0 ] ;
} else {
V_101 [ 0 ] = * V_93 ;
F_16 ( V_34 , F_33 ( * V_101 ) ,
V_100 ) ;
}
V_98 ++ ;
}
return V_98 << 1 ;
}
static bool F_35 ( struct V_47 * V_48 ,
unsigned int V_85 )
{
struct V_33 * V_34 = V_48 -> V_51 -> V_52 ;
T_3 V_80 , V_81 ;
V_48 -> V_102 -> V_103 ( V_48 , V_85 ) ;
F_15 ( V_34 , 0x55 , V_72 ) ;
F_15 ( V_34 , 0xaa , V_74 ) ;
F_15 ( V_34 , 0xaa , V_72 ) ;
F_15 ( V_34 , 0x55 , V_74 ) ;
F_15 ( V_34 , 0x55 , V_72 ) ;
F_15 ( V_34 , 0xaa , V_74 ) ;
V_80 = F_12 ( V_34 , V_72 ) ;
V_81 = F_12 ( V_34 , V_74 ) ;
if ( ( V_80 == 0x55 ) && ( V_81 == 0xaa ) )
return true ;
return false ;
}
static int F_36 ( struct V_104 * V_96 ,
unsigned int V_105 ,
unsigned long V_106 )
{
struct V_47 * V_48 = V_96 -> V_48 ;
struct V_33 * V_34 = V_48 -> V_51 -> V_52 ;
unsigned int V_107 = V_105 & ( 1 << 0 ) ;
unsigned int V_108 = V_105 & ( 1 << 1 ) ;
int V_109 , V_110 = 0 ;
F_37 ( V_48 , V_111 ) ;
V_109 = F_38 ( V_96 , V_106 ) ;
if ( V_109 )
return V_109 ;
if ( V_108 ) {
int V_112 ;
V_48 -> V_102 -> V_103 ( V_48 , 1 ) ;
for ( V_112 = 0 ; V_112 < 2 ; V_112 ++ ) {
T_3 V_80 , V_81 ;
V_80 = F_12 ( V_34 ,
V_72 ) ;
V_81 = F_12 ( V_34 ,
V_74 ) ;
if ( V_80 == 1 && V_81 == 1 )
break;
F_39 ( 50 ) ;
}
V_109 = F_38 ( V_96 , V_106 ) ;
if ( V_109 ) {
if ( V_109 != - V_113 )
return V_109 ;
V_110 = V_109 ;
}
}
V_48 -> V_102 -> V_103 ( V_48 , 0 ) ;
if ( V_108 )
V_48 -> V_102 -> V_103 ( V_48 , 1 ) ;
if ( V_107 )
V_48 -> V_102 -> V_103 ( V_48 , 0 ) ;
return V_110 ;
}
static int F_40 ( struct V_47 * V_48 , unsigned int V_105 ,
unsigned long V_106 )
{
struct V_33 * V_34 = V_48 -> V_51 -> V_52 ;
F_15 ( V_34 , V_48 -> V_65 , V_67 ) ;
F_41 ( 20 ) ;
F_15 ( V_34 , V_48 -> V_65 | V_114 , V_67 ) ;
F_41 ( 20 ) ;
F_15 ( V_34 , V_48 -> V_65 , V_67 ) ;
V_48 -> V_66 = V_48 -> V_65 ;
return F_36 ( & V_48 -> V_96 , V_105 , V_106 ) ;
}
static void F_42 ( struct V_33 * V_34 )
{
if ( V_34 -> V_115 ) {
F_43 ( V_34 -> V_115 ) ;
V_34 -> V_115 = NULL ;
}
if ( V_34 -> V_116 ) {
F_43 ( V_34 -> V_116 ) ;
V_34 -> V_116 = NULL ;
}
}
static bool F_44 ( struct V_117 * V_118 , void * V_119 )
{
if ( F_45 ( V_118 ) )
return false ;
V_118 -> V_120 = V_119 ;
return true ;
}
static void F_46 ( struct V_33 * V_34 )
{
const struct V_121 * V_122 = V_34 -> V_122 ;
T_4 V_123 ;
struct V_124 V_125 ;
F_47 ( V_123 ) ;
F_48 ( V_126 , V_123 ) ;
V_34 -> V_127 . V_128 = V_129 ;
V_34 -> V_127 . V_130 = V_131 ;
V_34 -> V_127 . V_132 = L_1 ;
V_34 -> V_115 = F_49 ( V_123 ,
F_44 , & V_34 -> V_127 ) ;
if ( ! V_34 -> V_115 )
return;
V_34 -> V_133 . V_128 = V_129 ;
V_34 -> V_133 . V_130 = V_134 ;
V_34 -> V_133 . V_132 = L_2 ;
V_34 -> V_116 = F_49 ( V_123 ,
F_44 , & V_34 -> V_133 ) ;
if ( ! V_34 -> V_116 ) {
F_43 ( V_34 -> V_115 ) ;
return;
}
memset ( & V_125 , 0 , sizeof( V_125 ) ) ;
V_125 . V_130 = V_131 ;
V_125 . V_135 = V_34 -> V_136 ;
V_125 . V_137 = V_138 ;
if ( F_50 ( V_34 -> V_115 , & V_125 ) ) {
F_51 ( & V_122 -> V_139 , L_3 ) ;
F_42 ( V_34 ) ;
return;
}
memset ( & V_125 , 0 , sizeof( V_125 ) ) ;
V_125 . V_130 = V_134 ;
V_125 . V_140 = V_34 -> V_141 ;
V_125 . V_142 = V_138 ;
if ( F_50 ( V_34 -> V_116 , & V_125 ) ) {
F_51 ( & V_122 -> V_139 , L_4 ) ;
F_42 ( V_34 ) ;
}
}
static void F_52 ( struct V_143 * V_144 )
{
struct V_145 * V_146 ;
struct V_33 * V_34 = V_144 -> V_48 -> V_51 -> V_52 ;
void T_1 * V_1 = V_34 -> V_36 ;
struct V_49 * V_50 = V_144 -> V_139 ;
T_5 V_147 = V_144 -> V_148 == V_134 ? V_149 : 0 ;
struct V_117 * V_150 = V_144 -> V_148 == V_134
? V_34 -> V_116 : V_34 -> V_115 ;
V_146 = V_150 -> V_85 -> V_151 ( V_150 , V_144 -> V_152 ,
V_144 -> V_153 , V_144 -> V_148 , V_154 , NULL ) ;
if ( ! V_146 ) {
F_51 ( V_144 -> V_48 -> V_139 , L_5 ) ;
return;
}
V_146 -> V_155 = NULL ;
V_146 -> V_156 = NULL ;
if ( F_53 ( V_146 ) < 0 ) {
F_51 ( V_144 -> V_48 -> V_139 , L_6 ) ;
return;
}
F_54 ( V_150 ) ;
F_2 ( V_147 , V_1 + V_9 ) ;
F_4 ( V_1 + V_9 ) ;
F_2 ( V_147 | V_157 , V_1 + V_9 ) ;
F_2 ( V_21 | V_158 |
( ( V_50 -> V_159 - V_160 ) << V_23 ) ,
V_1 + V_7 ) ;
}
static void F_55 ( struct V_143 * V_144 )
{
struct V_33 * V_34 = V_144 -> V_48 -> V_51 -> V_52 ;
void T_1 * V_1 = V_34 -> V_36 ;
F_56 ( V_34 -> V_115 ) ;
F_56 ( V_34 -> V_116 ) ;
F_2 ( 0 , V_1 + V_9 ) ;
F_2 ( F_4 ( V_1 + V_6 ) | V_5 | V_4 |
V_2 | V_3 , V_1 + V_6 ) ;
F_6 ( V_34 -> V_36 ,
V_144 -> V_139 -> V_18 - V_57 ) ;
F_57 ( V_144 -> V_48 ) ;
}
static void F_58 ( struct V_143 * V_144 )
{
V_144 -> V_48 -> V_102 -> V_161 ( V_144 -> V_48 , & V_144 -> V_61 ) ;
}
static T_3 F_59 ( struct V_47 * V_48 )
{
struct V_33 * V_34 = V_48 -> V_51 -> V_52 ;
T_5 V_19 = F_4 ( V_34 -> V_36 + V_162 ) ;
if ( V_19 & V_163 || V_19 & V_164 ||
V_19 & V_165 || V_19 & V_166 )
return V_167 ;
if ( F_4 ( V_34 -> V_36 + V_6 ) & V_168 )
return V_169 ;
if ( V_19 & V_170 || V_19 & V_171 )
return V_172 ;
return 0 ;
}
static int F_60 ( struct V_104 * V_173 , unsigned int * V_174 ,
unsigned long V_106 )
{
struct V_47 * V_48 = V_173 -> V_48 ;
unsigned int V_175 = V_48 -> V_63 & V_176 ;
unsigned int V_105 = 0 ;
int V_109 ;
T_3 V_177 ;
if ( F_35 ( V_48 , 0 ) )
V_105 |= ( 1 << 0 ) ;
if ( V_175 && F_35 ( V_48 , 1 ) )
V_105 |= ( 1 << 1 ) ;
V_48 -> V_102 -> V_103 ( V_173 -> V_48 , 0 ) ;
V_109 = F_40 ( V_48 , V_105 , V_106 ) ;
if ( V_109 && ( V_109 != - V_113 || F_61 ( V_173 ) ) ) {
F_62 ( V_173 , V_178 , L_7 ,
V_109 ) ;
return V_109 ;
}
V_174 [ 0 ] = F_63 ( & V_173 -> V_85 [ 0 ] , V_105 & ( 1 << 0 ) ,
& V_177 ) ;
if ( V_175 && V_177 != 0x81 )
V_174 [ 1 ] = F_63 ( & V_173 -> V_85 [ 1 ] ,
V_105 & ( 1 << 1 ) , & V_177 ) ;
return 0 ;
}
static void F_64 ( struct V_143 * V_144 )
{
int V_24 ;
struct V_47 * V_48 ;
struct V_33 * V_34 ;
if ( V_144 == NULL || V_144 -> V_148 == V_134 )
return;
V_48 = V_144 -> V_48 ;
V_34 = V_48 -> V_51 -> V_52 ;
for ( V_24 = 0 ; ( V_48 -> V_102 -> V_179 ( V_48 ) & V_180 )
&& V_24 < 65536 ; V_24 += 2 )
F_12 ( V_34 , V_100 ) ;
if ( V_24 )
F_65 ( V_48 , V_181 ,
L_8 , V_24 ) ;
}
static int F_66 ( struct V_47 * V_48 )
{
struct V_33 * V_34 = V_48 -> V_51 -> V_52 ;
V_34 -> V_38 = * F_67 ( V_57 ) ;
return 0 ;
}
static int T_6 F_68 ( struct V_121 * V_122 )
{
struct V_33 * V_34 ;
struct V_182 * V_51 ;
struct V_47 * V_48 ;
unsigned int V_183 ;
struct V_184 * V_185 ;
void T_1 * V_36 ;
int V_177 ;
V_177 = F_69 ( V_122 ) ;
if ( V_177 )
return V_177 ;
V_183 = F_70 ( V_122 , 0 ) ;
if ( V_183 < 0 ) {
V_177 = - V_186 ;
goto V_187;
}
V_185 = F_71 ( V_122 , V_188 , 0 ) ;
if ( ! V_185 ) {
V_177 = - V_186 ;
goto V_187;
}
V_36 = F_72 ( & V_122 -> V_139 , V_185 ) ;
if ( ! V_36 ) {
V_177 = - V_186 ;
goto V_187;
}
V_34 = F_73 ( & V_122 -> V_139 , sizeof( * V_34 ) , V_189 ) ;
if ( ! V_34 ) {
V_177 = - V_186 ;
goto V_187;
}
F_74 ( V_122 , V_34 ) ;
V_34 -> V_122 = V_122 ;
V_34 -> V_36 = V_36 ;
V_34 -> V_136 = V_185 -> V_26 + V_15 ;
V_34 -> V_141 = V_185 -> V_26 + V_14 ;
F_46 ( V_34 ) ;
V_51 = F_75 ( & V_122 -> V_139 , 1 ) ;
if ( ! V_51 ) {
V_177 = - V_186 ;
goto V_190;
}
F_1 ( V_36 ) ;
V_51 -> V_52 = V_34 ;
V_48 = V_51 -> V_191 [ 0 ] ;
V_48 -> V_139 = & V_122 -> V_139 ;
V_48 -> V_102 = & V_192 ;
V_48 -> V_63 |= V_176 ;
V_48 -> V_193 = V_194 ;
if ( V_34 -> V_115 && V_34 -> V_116 ) {
int V_195 = F_76 () ;
if ( V_195 == V_196 )
V_48 -> V_197 = V_198 ;
else if ( V_195 == V_199 )
V_48 -> V_197 = V_200 ;
else
V_48 -> V_197 = V_201 ;
}
F_6 ( V_36 , 0 ) ;
F_77 ( & V_122 -> V_139 , L_9 V_202 L_10 ) ;
V_177 = F_78 ( V_51 , V_183 , V_203 , 0 ,
& V_204 ) ;
if ( V_177 == 0 )
return 0 ;
V_190:
F_42 ( V_34 ) ;
V_187:
F_79 ( V_122 ) ;
return V_177 ;
}
static int T_7 F_80 ( struct V_121 * V_122 )
{
struct V_182 * V_51 = F_81 ( V_122 ) ;
struct V_33 * V_34 = V_51 -> V_52 ;
F_82 ( V_51 ) ;
F_42 ( V_34 ) ;
F_1 ( V_34 -> V_36 ) ;
F_79 ( V_122 ) ;
return 0 ;
}
