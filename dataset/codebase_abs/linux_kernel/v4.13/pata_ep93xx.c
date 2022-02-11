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
static unsigned int F_31 ( struct V_93 * V_94 ,
unsigned char * V_95 ,
unsigned int V_96 , int V_97 )
{
struct V_47 * V_48 = V_94 -> V_98 -> V_99 -> V_48 ;
struct V_33 * V_34 = V_48 -> V_51 -> V_52 ;
T_2 * V_100 = ( T_2 * ) V_95 ;
unsigned int V_101 = V_96 >> 1 ;
while ( V_101 -- )
if ( V_97 == V_102 )
* V_100 ++ = F_32 (
F_13 (
V_34 , V_103 ) ) ;
else
F_16 ( V_34 , F_33 ( * V_100 ++ ) ,
V_103 ) ;
if ( F_34 ( V_96 & 0x01 ) ) {
unsigned char V_104 [ 2 ] = { } ;
V_95 += V_96 - 1 ;
if ( V_97 == V_102 ) {
* V_104 = F_32 (
F_13 (
V_34 , V_103 ) ) ;
* V_95 = V_104 [ 0 ] ;
} else {
V_104 [ 0 ] = * V_95 ;
F_16 ( V_34 , F_33 ( * V_104 ) ,
V_103 ) ;
}
V_101 ++ ;
}
return V_101 << 1 ;
}
static bool F_35 ( struct V_47 * V_48 ,
unsigned int V_85 )
{
struct V_33 * V_34 = V_48 -> V_51 -> V_52 ;
T_3 V_80 , V_81 ;
V_48 -> V_105 -> V_106 ( V_48 , V_85 ) ;
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
static int F_36 ( struct V_107 * V_99 ,
unsigned int V_108 ,
unsigned long V_109 )
{
struct V_47 * V_48 = V_99 -> V_48 ;
struct V_33 * V_34 = V_48 -> V_51 -> V_52 ;
unsigned int V_110 = V_108 & ( 1 << 0 ) ;
unsigned int V_111 = V_108 & ( 1 << 1 ) ;
int V_112 , V_113 = 0 ;
F_37 ( V_48 , V_114 ) ;
V_112 = F_38 ( V_99 , V_109 ) ;
if ( V_112 )
return V_112 ;
if ( V_111 ) {
int V_115 ;
V_48 -> V_105 -> V_106 ( V_48 , 1 ) ;
for ( V_115 = 0 ; V_115 < 2 ; V_115 ++ ) {
T_3 V_80 , V_81 ;
V_80 = F_12 ( V_34 ,
V_72 ) ;
V_81 = F_12 ( V_34 ,
V_74 ) ;
if ( V_80 == 1 && V_81 == 1 )
break;
F_39 ( 50 ) ;
}
V_112 = F_38 ( V_99 , V_109 ) ;
if ( V_112 ) {
if ( V_112 != - V_116 )
return V_112 ;
V_113 = V_112 ;
}
}
V_48 -> V_105 -> V_106 ( V_48 , 0 ) ;
if ( V_111 )
V_48 -> V_105 -> V_106 ( V_48 , 1 ) ;
if ( V_110 )
V_48 -> V_105 -> V_106 ( V_48 , 0 ) ;
return V_113 ;
}
static int F_40 ( struct V_47 * V_48 , unsigned int V_108 ,
unsigned long V_109 )
{
struct V_33 * V_34 = V_48 -> V_51 -> V_52 ;
F_15 ( V_34 , V_48 -> V_65 , V_67 ) ;
F_41 ( 20 ) ;
F_15 ( V_34 , V_48 -> V_65 | V_117 , V_67 ) ;
F_41 ( 20 ) ;
F_15 ( V_34 , V_48 -> V_65 , V_67 ) ;
V_48 -> V_66 = V_48 -> V_65 ;
return F_36 ( & V_48 -> V_99 , V_108 , V_109 ) ;
}
static void F_42 ( struct V_33 * V_34 )
{
if ( V_34 -> V_118 ) {
F_43 ( V_34 -> V_118 ) ;
V_34 -> V_118 = NULL ;
}
if ( V_34 -> V_119 ) {
F_43 ( V_34 -> V_119 ) ;
V_34 -> V_119 = NULL ;
}
}
static bool F_44 ( struct V_120 * V_121 , void * V_122 )
{
if ( F_45 ( V_121 ) )
return false ;
V_121 -> V_123 = V_122 ;
return true ;
}
static void F_46 ( struct V_33 * V_34 )
{
const struct V_124 * V_125 = V_34 -> V_125 ;
T_4 V_126 ;
struct V_127 V_128 ;
F_47 ( V_126 ) ;
F_48 ( V_129 , V_126 ) ;
V_34 -> V_130 . V_131 = V_132 ;
V_34 -> V_130 . V_133 = V_134 ;
V_34 -> V_130 . V_135 = L_1 ;
V_34 -> V_118 = F_49 ( V_126 ,
F_44 , & V_34 -> V_130 ) ;
if ( ! V_34 -> V_118 )
return;
V_34 -> V_136 . V_131 = V_132 ;
V_34 -> V_136 . V_133 = V_137 ;
V_34 -> V_136 . V_135 = L_2 ;
V_34 -> V_119 = F_49 ( V_126 ,
F_44 , & V_34 -> V_136 ) ;
if ( ! V_34 -> V_119 ) {
F_43 ( V_34 -> V_118 ) ;
return;
}
memset ( & V_128 , 0 , sizeof( V_128 ) ) ;
V_128 . V_133 = V_134 ;
V_128 . V_138 = V_34 -> V_139 ;
V_128 . V_140 = V_141 ;
if ( F_50 ( V_34 -> V_118 , & V_128 ) ) {
F_51 ( & V_125 -> V_98 , L_3 ) ;
F_42 ( V_34 ) ;
return;
}
memset ( & V_128 , 0 , sizeof( V_128 ) ) ;
V_128 . V_133 = V_137 ;
V_128 . V_142 = V_34 -> V_143 ;
V_128 . V_144 = V_141 ;
if ( F_50 ( V_34 -> V_119 , & V_128 ) ) {
F_51 ( & V_125 -> V_98 , L_4 ) ;
F_42 ( V_34 ) ;
}
}
static void F_52 ( struct V_93 * V_94 )
{
struct V_145 * V_146 ;
struct V_33 * V_34 = V_94 -> V_48 -> V_51 -> V_52 ;
void T_1 * V_1 = V_34 -> V_36 ;
struct V_49 * V_50 = V_94 -> V_98 ;
T_5 V_147 = V_94 -> V_148 == V_137 ? V_149 : 0 ;
struct V_120 * V_150 = V_94 -> V_148 == V_137
? V_34 -> V_119 : V_34 -> V_118 ;
V_146 = F_53 ( V_150 , V_94 -> V_151 , V_94 -> V_152 , V_94 -> V_148 ,
V_153 ) ;
if ( ! V_146 ) {
F_51 ( V_94 -> V_48 -> V_98 , L_5 ) ;
return;
}
V_146 -> V_154 = NULL ;
V_146 -> V_155 = NULL ;
if ( F_54 ( V_146 ) < 0 ) {
F_51 ( V_94 -> V_48 -> V_98 , L_6 ) ;
return;
}
F_55 ( V_150 ) ;
F_2 ( V_147 , V_1 + V_9 ) ;
F_4 ( V_1 + V_9 ) ;
F_2 ( V_147 | V_156 , V_1 + V_9 ) ;
F_2 ( V_21 | V_157 |
( ( V_50 -> V_158 - V_159 ) << V_23 ) ,
V_1 + V_7 ) ;
}
static void F_56 ( struct V_93 * V_94 )
{
struct V_33 * V_34 = V_94 -> V_48 -> V_51 -> V_52 ;
void T_1 * V_1 = V_34 -> V_36 ;
F_57 ( V_34 -> V_118 ) ;
F_57 ( V_34 -> V_119 ) ;
F_2 ( 0 , V_1 + V_9 ) ;
F_2 ( F_4 ( V_1 + V_6 ) | V_5 | V_4 |
V_2 | V_3 , V_1 + V_6 ) ;
F_6 ( V_34 -> V_36 ,
V_94 -> V_98 -> V_18 - V_57 ) ;
F_58 ( V_94 -> V_48 ) ;
}
static void F_59 ( struct V_93 * V_94 )
{
V_94 -> V_48 -> V_105 -> V_160 ( V_94 -> V_48 , & V_94 -> V_61 ) ;
}
static T_3 F_60 ( struct V_47 * V_48 )
{
struct V_33 * V_34 = V_48 -> V_51 -> V_52 ;
T_5 V_19 = F_4 ( V_34 -> V_36 + V_161 ) ;
if ( V_19 & V_162 || V_19 & V_163 ||
V_19 & V_164 || V_19 & V_165 )
return V_166 ;
if ( F_4 ( V_34 -> V_36 + V_6 ) & V_167 )
return V_168 ;
if ( V_19 & V_169 || V_19 & V_170 )
return V_171 ;
return 0 ;
}
static int F_61 ( struct V_107 * V_172 , unsigned int * V_173 ,
unsigned long V_109 )
{
struct V_47 * V_48 = V_172 -> V_48 ;
unsigned int V_174 = V_48 -> V_63 & V_175 ;
unsigned int V_108 = 0 ;
int V_112 ;
T_3 V_176 ;
if ( F_35 ( V_48 , 0 ) )
V_108 |= ( 1 << 0 ) ;
if ( V_174 && F_35 ( V_48 , 1 ) )
V_108 |= ( 1 << 1 ) ;
V_48 -> V_105 -> V_106 ( V_172 -> V_48 , 0 ) ;
V_112 = F_40 ( V_48 , V_108 , V_109 ) ;
if ( V_112 && ( V_112 != - V_116 || F_62 ( V_172 ) ) ) {
F_63 ( V_172 , L_7 , V_112 ) ;
return V_112 ;
}
V_173 [ 0 ] = F_64 ( & V_172 -> V_85 [ 0 ] , V_108 & ( 1 << 0 ) ,
& V_176 ) ;
if ( V_174 && V_176 != 0x81 )
V_173 [ 1 ] = F_64 ( & V_172 -> V_85 [ 1 ] ,
V_108 & ( 1 << 1 ) , & V_176 ) ;
return 0 ;
}
static void F_65 ( struct V_93 * V_94 )
{
int V_24 ;
struct V_47 * V_48 ;
struct V_33 * V_34 ;
if ( V_94 == NULL || V_94 -> V_148 == V_137 )
return;
V_48 = V_94 -> V_48 ;
V_34 = V_48 -> V_51 -> V_52 ;
for ( V_24 = 0 ; ( V_48 -> V_105 -> V_177 ( V_48 ) & V_178 )
&& V_24 < 65536 ; V_24 += 2 )
F_12 ( V_34 , V_103 ) ;
if ( V_24 )
F_66 ( V_48 , L_8 , V_24 ) ;
}
static int F_67 ( struct V_47 * V_48 )
{
struct V_33 * V_34 = V_48 -> V_51 -> V_52 ;
V_34 -> V_38 = * F_68 ( V_57 ) ;
return 0 ;
}
static int F_69 ( struct V_124 * V_125 )
{
struct V_33 * V_34 ;
struct V_179 * V_51 ;
struct V_47 * V_48 ;
int V_180 ;
struct V_181 * V_182 ;
void T_1 * V_36 ;
int V_176 ;
V_176 = F_70 ( V_125 ) ;
if ( V_176 )
return V_176 ;
V_180 = F_71 ( V_125 , 0 ) ;
if ( V_180 < 0 ) {
V_176 = - V_183 ;
goto V_184;
}
V_182 = F_72 ( V_125 , V_185 , 0 ) ;
V_36 = F_73 ( & V_125 -> V_98 , V_182 ) ;
if ( F_74 ( V_36 ) ) {
V_176 = F_75 ( V_36 ) ;
goto V_184;
}
V_34 = F_76 ( & V_125 -> V_98 , sizeof( * V_34 ) , V_186 ) ;
if ( ! V_34 ) {
V_176 = - V_183 ;
goto V_184;
}
V_34 -> V_125 = V_125 ;
V_34 -> V_36 = V_36 ;
V_34 -> V_139 = V_182 -> V_26 + V_15 ;
V_34 -> V_143 = V_182 -> V_26 + V_14 ;
F_46 ( V_34 ) ;
V_51 = F_77 ( & V_125 -> V_98 , 1 ) ;
if ( ! V_51 ) {
V_176 = - V_183 ;
goto V_187;
}
F_1 ( V_36 ) ;
V_51 -> V_52 = V_34 ;
V_48 = V_51 -> V_188 [ 0 ] ;
V_48 -> V_98 = & V_125 -> V_98 ;
V_48 -> V_105 = & V_189 ;
V_48 -> V_63 |= V_175 ;
V_48 -> V_190 = V_191 ;
if ( V_34 -> V_118 && V_34 -> V_119 ) {
int V_192 = F_78 () ;
if ( V_192 == V_193 )
V_48 -> V_194 = V_195 ;
else if ( V_192 == V_196 )
V_48 -> V_194 = V_197 ;
else
V_48 -> V_194 = V_198 ;
}
F_6 ( V_36 , 0 ) ;
F_79 ( & V_125 -> V_98 , L_9 V_199 L_10 ) ;
V_176 = F_80 ( V_51 , V_180 , V_200 , 0 ,
& V_201 ) ;
if ( V_176 == 0 )
return 0 ;
V_187:
F_42 ( V_34 ) ;
V_184:
F_81 ( V_125 ) ;
return V_176 ;
}
static int F_82 ( struct V_124 * V_125 )
{
struct V_179 * V_51 = F_83 ( V_125 ) ;
struct V_33 * V_34 = V_51 -> V_52 ;
F_84 ( V_51 ) ;
F_42 ( V_34 ) ;
F_1 ( V_34 -> V_36 ) ;
F_81 ( V_125 ) ;
return 0 ;
}
