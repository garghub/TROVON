static int F_1 ( struct V_1 * V_2 )
{
if ( V_2 -> V_3 -> V_4 == V_5 ||
V_2 -> V_3 -> V_4 == V_6 )
V_2 -> V_7 |= V_8 ;
return 0 ;
}
static int F_2 ( struct V_9 * V_10 )
{
V_10 -> V_11 -> V_12 =
( ( 0x21 << V_13 )
& V_14 ) |
( ( 0x21 << V_15 )
& V_16 ) |
V_17 |
V_18 |
V_19 |
V_20 ;
return 0 ;
}
static int F_3 ( struct V_1 * V_2 )
{
F_4 ( 500 ) ;
return 0 ;
}
static int F_5 ( struct V_9 * V_10 )
{
V_10 -> V_11 -> V_21 -> V_12 |= V_22 ;
return 0 ;
}
static int F_6 ( struct V_1 * V_2 )
{
V_2 -> V_23 = 1 ;
return 0 ;
}
static int F_7 ( struct V_9 * V_10 )
{
V_10 -> V_11 -> V_21 -> V_12 |= V_22 ;
return 0 ;
}
static T_1 F_8 ( int V_24 , void * V_25 )
{
struct V_9 * V_10 = V_25 ;
struct V_26 * V_11 = V_10 -> V_11 ;
F_9 ( V_11 -> V_21 , F_10 ( 200 ) ) ;
return V_27 ;
}
static void F_11 ( struct V_9 * V_10 )
{
int V_28 , V_24 , V_29 = V_10 -> V_30 ;
V_10 -> V_30 = - V_31 ;
V_10 -> V_32 = - V_31 ;
if ( ! F_12 ( V_29 ) )
return;
V_28 = F_13 ( & V_10 -> V_2 -> V_3 -> V_33 , V_29 , L_1 ) ;
if ( V_28 < 0 )
goto V_34;
V_28 = F_14 ( V_29 ) ;
if ( V_28 < 0 )
goto V_35;
V_24 = F_15 ( V_29 ) ;
if ( V_24 < 0 )
goto V_35;
V_28 = F_16 ( V_24 , F_8 , V_36 |
V_37 , L_1 , V_10 ) ;
if ( V_28 )
goto V_35;
V_10 -> V_30 = V_29 ;
V_10 -> V_32 = V_24 ;
return;
V_35:
F_17 ( & V_10 -> V_2 -> V_3 -> V_33 , V_29 ) ;
V_34:
F_18 ( & V_10 -> V_2 -> V_3 -> V_33 , L_2 ) ;
}
static void F_19 ( struct V_9 * V_10 )
{
if ( V_10 -> V_32 >= 0 )
F_20 ( V_10 -> V_32 , V_10 ) ;
}
static inline void F_11 ( struct V_9 * V_10 )
{
}
static inline void F_19 ( struct V_9 * V_10 )
{
}
static int F_21 ( struct V_9 * V_10 )
{
V_10 -> V_11 -> V_21 -> V_12 |= V_22 | V_38 ;
V_10 -> V_11 -> V_21 -> V_39 |= V_40 |
V_41 ;
return 0 ;
}
static int F_22 ( struct V_9 * V_10 )
{
V_10 -> V_11 -> V_21 -> V_12 |= V_42 | V_38 ;
return 0 ;
}
static void F_23 ( struct V_26 * V_11 )
{
T_2 V_43 ;
V_43 = F_24 ( V_11 , V_44 ) ;
V_43 |= 0x10 ;
F_25 ( V_11 , V_43 , V_44 ) ;
F_26 ( 9 ) ;
V_43 &= ~ 0x10 ;
F_25 ( V_11 , V_43 , V_44 ) ;
F_27 ( 300 , 1000 ) ;
}
static int F_28 ( struct V_26 * V_11 ,
struct V_45 * V_46 ,
unsigned int V_47 ,
int V_48 , int V_49 , int * V_50 )
{
int V_51 ;
if ( V_52 > 0 )
V_51 = V_52 & 0xf ;
else
V_51 = 0 ;
if ( ( F_29 ( V_51 ) & V_49 ) == 0 )
V_51 = 0 ;
return V_51 ;
}
static void F_30 ( struct V_26 * V_11 )
{
T_3 V_53 , V_54 , V_55 ;
T_4 V_56 ;
if ( V_52 )
return;
V_52 = - 1 ;
V_56 = F_31 ( V_11 , V_57 ) & 0x7 ;
if ( V_56 != 3 && V_56 != 5 )
return;
V_53 = F_32 ( V_11 , V_58 ) ;
if ( V_53 & 0x3 )
return;
F_33 ( V_11 , 0x007f0023 , V_59 ) ;
F_33 ( V_11 , 0 , V_60 ) ;
F_34 ( V_11 , 0x10 , V_61 ) ;
F_25 ( V_11 , 0xe , V_62 ) ;
F_34 ( V_11 , 512 , V_63 ) ;
F_34 ( V_11 , 1 , V_64 ) ;
F_33 ( V_11 , 0 , V_65 ) ;
F_34 ( V_11 , 0x83b , V_66 ) ;
for ( V_54 = 0 ; V_54 < 1000 ; V_54 ++ ) {
V_53 = F_32 ( V_11 , V_67 ) ;
if ( V_53 & 0xffff8000 )
return;
if ( V_53 & 0x20 )
break;
F_26 ( 1 ) ;
}
V_53 = F_32 ( V_11 , V_58 ) ;
if ( ! ( V_53 & 0x800 ) )
return;
for ( V_54 = 0 ; V_54 < 47 ; V_54 ++ )
V_53 = F_32 ( V_11 , V_68 ) ;
V_55 = V_53 & 0xf00 ;
if ( V_55 != 0x200 && V_55 != 0x300 )
return;
V_52 = 0x10 | ( ( V_53 >> 12 ) & 0xf ) ;
}
static int F_35 ( struct V_69 * V_21 )
{
int V_70 = F_36 ( V_21 ) ;
struct V_26 * V_11 = F_37 ( V_21 ) ;
unsigned long V_71 ;
int V_72 = 0 ;
if ( ! V_70 )
return 0 ;
F_38 ( & V_11 -> V_73 , V_71 ) ;
if ( V_11 -> V_71 & V_74 )
goto V_34;
V_72 = ! ! ( F_32 ( V_11 , V_58 ) & V_75 ) ;
V_34:
F_39 ( & V_11 -> V_73 , V_71 ) ;
return V_72 ;
}
static int F_40 ( struct V_9 * V_10 )
{
V_10 -> V_11 -> V_21 -> V_12 |= V_22 | V_38 |
V_76 | V_77 |
V_78 |
V_79 ;
V_10 -> V_11 -> V_21 -> V_39 |= V_41 ;
V_10 -> V_80 = F_23 ;
if ( V_10 -> V_2 -> V_3 -> V_81 == V_82 )
V_10 -> V_11 -> V_83 = 1000 ;
if ( V_10 -> V_2 -> V_3 -> V_81 == V_84 ) {
F_30 ( V_10 -> V_11 ) ;
V_10 -> V_85 = F_28 ;
}
return 0 ;
}
static int F_41 ( struct V_9 * V_10 )
{
T_5 V_86 ;
unsigned long long V_87 ;
V_86 = F_42 ( F_43 ( & V_10 -> V_2 -> V_3 -> V_33 ) ,
L_3 , NULL , & V_87 ) ;
if ( F_44 ( V_86 ) ) {
F_45 ( & V_10 -> V_2 -> V_3 -> V_33 ,
L_4 ) ;
return - V_31 ;
}
V_10 -> V_11 -> V_21 -> V_88 = V_87 * 1000000 ;
return 0 ;
}
static inline int F_41 ( struct V_9 * V_10 )
{
return 0 ;
}
static int F_46 ( struct V_9 * V_10 )
{
int V_28 ;
V_28 = F_41 ( V_10 ) ;
if ( V_28 )
return V_28 ;
V_10 -> V_11 -> V_21 -> V_12 |= V_42 | V_38 |
V_79 ;
return 0 ;
}
static int F_47 ( struct V_9 * V_10 )
{
V_10 -> V_11 -> V_21 -> V_12 |= V_42 | V_38 |
V_79 ;
return 0 ;
}
static int F_48 ( struct V_9 * V_10 )
{
V_10 -> V_11 -> V_21 -> V_12 |= V_79 ;
V_10 -> V_89 = NULL ;
V_10 -> V_90 = 0 ;
V_10 -> V_91 = true ;
if ( V_10 -> V_2 -> V_3 -> V_81 == V_92 ||
V_10 -> V_2 -> V_3 -> V_81 == V_93 ||
V_10 -> V_2 -> V_3 -> V_81 == V_94 ||
V_10 -> V_2 -> V_3 -> V_81 == V_95 ) {
V_10 -> V_11 -> V_96 . V_97 = F_35 ;
V_10 -> V_11 -> V_21 -> V_12 |= V_98 ;
}
return 0 ;
}
static void F_49 ( struct V_26 * V_11 , unsigned char V_99 ,
unsigned short V_100 )
{
int V_101 ;
T_2 V_43 ;
F_50 ( V_11 , V_99 , V_100 ) ;
if ( V_99 == V_102 )
return;
for ( V_101 = 0 ; V_101 < V_103 ; V_101 ++ ) {
V_43 = F_24 ( V_11 , V_44 ) ;
if ( V_43 & V_104 )
break;
F_26 ( V_105 ) ;
V_43 |= V_104 ;
F_25 ( V_11 , V_43 , V_44 ) ;
}
}
static int F_51 ( struct V_9 * V_10 )
{
unsigned int V_106 = F_52 ( V_10 -> V_2 -> V_3 -> V_107 ) ;
switch ( V_106 ) {
case V_108 :
case V_109 :
V_10 -> V_11 -> V_21 -> V_12 |= V_38 |
V_22 |
V_77 ;
break;
case V_110 :
V_10 -> V_11 -> V_111 |= V_112 ;
break;
case V_113 :
V_10 -> V_11 -> V_21 -> V_12 |= V_38 |
V_42 ;
break;
default:
return - V_114 ;
}
return 0 ;
}
static int F_53 ( struct V_1 * V_2 , int V_115 )
{
T_2 V_116 ;
int V_72 ;
V_72 = F_54 ( V_2 -> V_3 , 0xAE , & V_116 ) ;
if ( V_72 )
return V_72 ;
if ( V_115 )
V_116 |= 0x47 ;
else
V_116 &= ~ 0x47 ;
return F_55 ( V_2 -> V_3 , 0xAE , V_116 ) ;
}
static int F_56 ( struct V_1 * V_2 )
{
int V_72 ;
T_4 V_117 = 0 ;
if ( V_2 -> V_3 -> V_118 == 0 ) {
V_2 -> V_7 |= V_119 |
V_120 |
V_121 |
V_122 |
V_123 ;
}
if ( V_2 -> V_3 -> V_81 == V_124 )
V_117 = V_125 ;
else if ( V_2 -> V_3 -> V_81 == V_126 )
V_117 = V_127 ;
if ( V_117 ) {
struct V_128 * V_129 ;
V_129 = NULL ;
while ( ( V_129 = F_57 ( V_130 ,
V_117 , V_129 ) ) != NULL ) {
if ( ( F_58 ( V_2 -> V_3 -> V_107 ) ==
F_58 ( V_129 -> V_107 ) ) &&
( V_2 -> V_3 -> V_131 == V_129 -> V_131 ) )
break;
}
if ( V_129 ) {
F_59 ( V_129 ) ;
F_60 ( & V_2 -> V_3 -> V_33 , L_5
L_6 ) ;
return - V_114 ;
}
}
V_72 = F_53 ( V_2 , 1 ) ;
if ( V_72 ) {
F_45 ( & V_2 -> V_3 -> V_33 , L_7 ) ;
return V_72 ;
}
if ( V_2 -> V_3 -> V_81 == V_126 ||
V_2 -> V_3 -> V_81 == V_127 )
V_2 -> V_7 |= V_132 ;
return 0 ;
}
static void F_61 ( struct V_26 * V_11 , int V_115 )
{
T_2 V_116 ;
V_116 = F_62 ( V_11 -> V_133 + 0xC0 ) ;
if ( V_115 )
V_116 |= 0x01 ;
else
V_116 &= ~ 0x01 ;
F_63 ( V_116 , V_11 -> V_133 + 0xC0 ) ;
}
static int F_64 ( struct V_9 * V_10 )
{
if ( V_10 -> V_2 -> V_3 -> V_118 == 0 ) {
T_4 V_134 ;
V_134 = F_65 ( V_10 -> V_11 -> V_133 + V_135 ) ;
V_134 = ( V_134 & V_136 ) >>
V_137 ;
if ( V_134 < 0xAC )
V_10 -> V_11 -> V_7 |= V_138 ;
}
if ( V_10 -> V_2 -> V_3 -> V_81 == V_127 ) {
V_10 -> V_11 -> V_139 = V_140 | V_141 |
V_142 | V_143 |
V_144 ;
V_10 -> V_11 -> V_145 = V_140 | V_141 |
V_142 | V_143 ;
}
if ( V_10 -> V_2 -> V_3 -> V_81 == V_125 ||
V_10 -> V_2 -> V_3 -> V_81 == V_127 )
F_61 ( V_10 -> V_11 , 1 ) ;
V_10 -> V_11 -> V_21 -> V_12 |= V_146 ;
return 0 ;
}
static void F_66 ( struct V_9 * V_10 , int V_147 )
{
if ( V_147 )
return;
if ( V_10 -> V_2 -> V_3 -> V_81 == V_125 ||
V_10 -> V_2 -> V_3 -> V_81 == V_127 )
F_61 ( V_10 -> V_11 , 0 ) ;
}
static int F_67 ( struct V_1 * V_2 )
{
int V_54 ;
if ( V_2 -> V_3 -> V_81 == V_125 ||
V_2 -> V_3 -> V_81 == V_127 ) {
for ( V_54 = 0 ; V_54 < V_2 -> V_23 ; V_54 ++ )
F_61 ( V_2 -> V_148 [ V_54 ] -> V_11 , 0 ) ;
}
return 0 ;
}
static int F_68 ( struct V_1 * V_2 )
{
int V_72 , V_54 ;
if ( V_2 -> V_3 -> V_81 == V_125 ||
V_2 -> V_3 -> V_81 == V_127 ) {
for ( V_54 = 0 ; V_54 < V_2 -> V_23 ; V_54 ++ )
F_61 ( V_2 -> V_148 [ V_54 ] -> V_11 , 1 ) ;
}
V_72 = F_53 ( V_2 , 1 ) ;
if ( V_72 ) {
F_45 ( & V_2 -> V_3 -> V_33 , L_7 ) ;
return V_72 ;
}
return 0 ;
}
static int F_69 ( struct V_1 * V_2 )
{
if ( ( V_2 -> V_3 -> V_149 & 0x0000FF ) == V_150 ) {
V_2 -> V_3 -> V_149 &= ~ 0x0000FF ;
V_2 -> V_3 -> V_149 |= V_151 ;
}
return 0 ;
}
static int F_70 ( struct V_9 * V_10 )
{
int V_152 , V_153 ;
T_2 V_154 = F_62 ( V_10 -> V_11 -> V_133 + V_155 ) ;
T_2 V_156 = F_62 ( V_10 -> V_11 -> V_133 + V_157 ) ;
F_60 ( & V_10 -> V_2 -> V_3 -> V_33 , L_8
L_9 ,
V_154 >> 4 , V_154 & 0xf ,
V_156 >> 4 , V_156 & 0xf ) ;
if ( V_156 >= 0x20 )
V_10 -> V_11 -> V_7 |= V_158 ;
F_63 ( V_159 , V_10 -> V_11 -> V_133 + V_160 ) ;
F_63 ( V_161 , V_10 -> V_11 -> V_133 + V_162 ) ;
F_26 ( 50 ) ;
V_152 = 10 ;
do {
V_153 = F_71 ( V_10 -> V_11 -> V_133 + V_163 ) ;
if ( V_153 & V_164 )
break;
F_26 ( 100 ) ;
} while ( -- V_152 );
if ( ! V_152 ) {
F_45 ( & V_10 -> V_2 -> V_3 -> V_33 ,
L_10 ) ;
F_63 ( 0 , V_10 -> V_11 -> V_133 + V_162 ) ;
return - V_114 ;
}
return 0 ;
}
static int F_72 ( struct V_1 * V_2 )
{
if ( V_2 -> V_3 -> V_118 == 0x10 )
V_2 -> V_7 |= V_165 ;
return 0 ;
}
static int F_73 ( struct V_9 * V_10 )
{
V_10 -> V_11 -> V_21 -> V_39 |= V_166 ;
return 0 ;
}
static int F_74 ( struct V_1 * V_2 )
{
struct V_128 * V_167 ;
enum V_168 V_169 ;
V_167 = F_57 ( V_170 ,
V_171 , NULL ) ;
if ( V_167 ) {
V_169 = V_172 ;
} else {
V_167 = F_57 ( V_170 ,
V_173 , NULL ) ;
if ( V_167 ) {
if ( V_167 -> V_118 < 0x51 )
V_169 = V_174 ;
else
V_169 = V_175 ;
} else {
V_169 = V_176 ;
}
}
if ( ( V_169 == V_172 ) || ( V_169 == V_174 ) ) {
V_2 -> V_111 |= V_177 ;
V_2 -> V_111 |= V_178 ;
}
return 0 ;
}
static int F_75 ( struct V_26 * V_11 )
{
struct V_9 * V_10 ;
struct V_128 * V_3 ;
V_10 = F_76 ( V_11 ) ;
V_3 = V_10 -> V_2 -> V_3 ;
if ( ( ( V_3 -> V_149 & 0xFFFF00 ) == ( V_179 << 8 ) ) &&
( ( V_3 -> V_149 & 0x0000FF ) != V_151 ) &&
( V_11 -> V_71 & V_180 ) ) {
F_18 ( & V_3 -> V_33 , L_11
L_12 ) ;
}
F_77 ( V_3 ) ;
return 0 ;
}
static void F_78 ( struct V_26 * V_11 , int V_181 )
{
T_2 V_182 ;
V_182 = F_24 ( V_11 , V_183 ) ;
switch ( V_181 ) {
case V_184 :
V_182 |= V_185 ;
V_182 &= ~ V_186 ;
break;
case V_187 :
V_182 |= V_186 ;
V_182 &= ~ V_185 ;
break;
default:
V_182 &= ~ ( V_185 | V_186 ) ;
break;
}
F_25 ( V_11 , V_182 , V_183 ) ;
}
static void F_79 ( struct V_26 * V_11 )
{
struct V_9 * V_10 = F_76 ( V_11 ) ;
int V_188 = V_10 -> V_188 ;
if ( ! F_12 ( V_188 ) )
return;
F_80 ( V_188 , 0 ) ;
F_26 ( 10 ) ;
F_80 ( V_188 , 1 ) ;
F_27 ( 300 , 1000 ) ;
}
static void F_81 ( struct V_26 * V_11 )
{
struct V_9 * V_10 = F_76 ( V_11 ) ;
if ( V_10 -> V_80 )
V_10 -> V_80 ( V_11 ) ;
}
static int F_82 ( struct V_26 * V_11 ,
struct V_45 * V_46 ,
unsigned int V_47 , int V_48 ,
int V_49 , int * V_50 )
{
struct V_9 * V_10 = F_76 ( V_11 ) ;
if ( ! V_10 -> V_85 )
return 0 ;
return V_10 -> V_85 ( V_11 , V_46 , V_47 , V_48 ,
V_49 , V_50 ) ;
}
static int F_83 ( struct V_81 * V_33 )
{
struct V_128 * V_3 = F_84 ( V_33 ) ;
struct V_1 * V_2 ;
struct V_9 * V_10 ;
T_6 V_189 ;
T_6 V_190 = 0 ;
int V_54 , V_72 ;
V_2 = F_85 ( V_3 ) ;
if ( ! V_2 )
return 0 ;
for ( V_54 = 0 ; V_54 < V_2 -> V_23 ; V_54 ++ ) {
V_10 = V_2 -> V_148 [ V_54 ] ;
if ( ! V_10 )
continue;
V_72 = F_86 ( V_10 -> V_11 ) ;
if ( V_72 )
goto V_191;
V_189 = V_10 -> V_11 -> V_21 -> V_190 ;
if ( V_189 & V_192 )
F_87 ( V_10 -> V_11 ) ;
V_190 |= V_189 ;
}
if ( V_2 -> V_193 && V_2 -> V_193 -> V_194 ) {
V_72 = V_2 -> V_193 -> V_194 ( V_2 ) ;
if ( V_72 )
goto V_191;
}
if ( V_190 & V_195 ) {
if ( V_190 & V_192 )
F_88 ( V_33 , true ) ;
else
F_88 ( V_33 , false ) ;
} else
F_88 ( V_33 , false ) ;
return 0 ;
V_191:
while ( -- V_54 >= 0 )
F_89 ( V_2 -> V_148 [ V_54 ] -> V_11 ) ;
return V_72 ;
}
static int F_90 ( struct V_81 * V_33 )
{
struct V_128 * V_3 = F_84 ( V_33 ) ;
struct V_1 * V_2 ;
struct V_9 * V_10 ;
int V_54 , V_72 ;
V_2 = F_85 ( V_3 ) ;
if ( ! V_2 )
return 0 ;
if ( V_2 -> V_193 && V_2 -> V_193 -> V_196 ) {
V_72 = V_2 -> V_193 -> V_196 ( V_2 ) ;
if ( V_72 )
return V_72 ;
}
for ( V_54 = 0 ; V_54 < V_2 -> V_23 ; V_54 ++ ) {
V_10 = V_2 -> V_148 [ V_54 ] ;
if ( ! V_10 )
continue;
V_72 = F_89 ( V_10 -> V_11 ) ;
if ( V_72 )
return V_72 ;
}
return 0 ;
}
static int F_91 ( struct V_81 * V_33 )
{
struct V_128 * V_3 = F_84 ( V_33 ) ;
struct V_1 * V_2 ;
struct V_9 * V_10 ;
int V_54 , V_72 ;
V_2 = F_85 ( V_3 ) ;
if ( ! V_2 )
return 0 ;
for ( V_54 = 0 ; V_54 < V_2 -> V_23 ; V_54 ++ ) {
V_10 = V_2 -> V_148 [ V_54 ] ;
if ( ! V_10 )
continue;
V_72 = F_92 ( V_10 -> V_11 ) ;
if ( V_72 )
goto V_197;
}
if ( V_2 -> V_193 && V_2 -> V_193 -> V_194 ) {
V_72 = V_2 -> V_193 -> V_194 ( V_2 ) ;
if ( V_72 )
goto V_197;
}
return 0 ;
V_197:
while ( -- V_54 >= 0 )
F_93 ( V_2 -> V_148 [ V_54 ] -> V_11 ) ;
return V_72 ;
}
static int F_94 ( struct V_81 * V_33 )
{
struct V_128 * V_3 = F_84 ( V_33 ) ;
struct V_1 * V_2 ;
struct V_9 * V_10 ;
int V_54 , V_72 ;
V_2 = F_85 ( V_3 ) ;
if ( ! V_2 )
return 0 ;
if ( V_2 -> V_193 && V_2 -> V_193 -> V_196 ) {
V_72 = V_2 -> V_193 -> V_196 ( V_2 ) ;
if ( V_72 )
return V_72 ;
}
for ( V_54 = 0 ; V_54 < V_2 -> V_23 ; V_54 ++ ) {
V_10 = V_2 -> V_148 [ V_54 ] ;
if ( ! V_10 )
continue;
V_72 = F_93 ( V_10 -> V_11 ) ;
if ( V_72 )
return V_72 ;
}
return 0 ;
}
static struct V_9 * F_95 (
struct V_128 * V_3 , struct V_1 * V_2 , int V_198 ,
int V_199 )
{
struct V_9 * V_10 ;
struct V_26 * V_11 ;
int V_72 , V_200 = V_198 + V_199 ;
if ( ! ( F_96 ( V_3 , V_200 ) & V_201 ) ) {
F_45 ( & V_3 -> V_33 , L_13 , V_200 ) ;
return F_97 ( - V_114 ) ;
}
if ( F_98 ( V_3 , V_200 ) < 0x100 ) {
F_45 ( & V_3 -> V_33 , L_14
L_15 ) ;
}
if ( ( V_3 -> V_149 & 0x0000FF ) == V_150 ) {
F_45 ( & V_3 -> V_33 , L_16 ) ;
return F_97 ( - V_114 ) ;
}
if ( ( V_3 -> V_149 & 0x0000FF ) > V_150 ) {
F_45 ( & V_3 -> V_33 , L_17 ) ;
return F_97 ( - V_114 ) ;
}
V_11 = F_99 ( & V_3 -> V_33 , sizeof( struct V_9 ) ) ;
if ( F_100 ( V_11 ) ) {
F_45 ( & V_3 -> V_33 , L_18 ) ;
return F_101 ( V_11 ) ;
}
V_10 = F_76 ( V_11 ) ;
V_10 -> V_2 = V_2 ;
V_10 -> V_11 = V_11 ;
V_10 -> V_188 = - V_31 ;
V_10 -> V_30 = - V_31 ;
V_10 -> V_90 = - 1 ;
if ( * V_202 )
V_10 -> V_203 = V_202 ( V_3 , V_199 ) ;
if ( V_10 -> V_203 ) {
if ( V_10 -> V_203 -> V_204 ) {
V_72 = V_10 -> V_203 -> V_204 ( V_10 -> V_203 ) ;
if ( V_72 ) {
F_45 ( & V_3 -> V_33 , L_19 ) ;
goto free;
}
}
V_10 -> V_188 = V_10 -> V_203 -> V_188 ;
V_10 -> V_30 = V_10 -> V_203 -> V_30 ;
}
V_11 -> V_205 = L_20 ;
V_11 -> V_206 = V_2 -> V_193 && V_2 -> V_193 -> V_206 ?
V_2 -> V_193 -> V_206 :
& V_207 ;
V_11 -> V_7 = V_2 -> V_7 ;
V_11 -> V_111 = V_2 -> V_111 ;
V_11 -> V_24 = V_3 -> V_24 ;
V_72 = F_102 ( V_3 , F_103 ( V_200 ) , F_104 ( V_11 -> V_21 ) ) ;
if ( V_72 ) {
F_45 ( & V_3 -> V_33 , L_21 ) ;
goto V_208;
}
V_11 -> V_133 = F_105 ( V_3 ) [ V_200 ] ;
if ( V_2 -> V_193 && V_2 -> V_193 -> V_209 ) {
V_72 = V_2 -> V_193 -> V_209 ( V_10 ) ;
if ( V_72 )
goto V_208;
}
if ( F_12 ( V_10 -> V_188 ) ) {
if ( ! F_13 ( & V_3 -> V_33 , V_10 -> V_188 , L_22 ) ) {
F_106 ( V_10 -> V_188 , 1 ) ;
V_10 -> V_11 -> V_21 -> V_12 |= V_76 ;
V_10 -> V_80 = F_79 ;
} else {
F_18 ( & V_3 -> V_33 , L_23 ) ;
V_10 -> V_188 = - V_31 ;
}
}
V_11 -> V_21 -> V_210 = V_195 | V_192 ;
V_11 -> V_21 -> V_199 = V_199 ;
V_11 -> V_21 -> V_39 |= V_211 ;
if ( V_10 -> V_90 >= 0 ) {
V_72 = F_107 ( V_11 -> V_21 , V_10 -> V_89 , V_10 -> V_90 ,
V_10 -> V_91 , 0 , NULL ) ;
if ( V_72 == - V_212 )
goto remove;
if ( V_72 ) {
F_18 ( & V_3 -> V_33 , L_24 ) ;
V_10 -> V_90 = - 1 ;
}
}
V_72 = F_108 ( V_11 ) ;
if ( V_72 )
goto remove;
F_11 ( V_10 ) ;
if ( V_2 -> V_193 && V_2 -> V_193 -> V_213 &&
! F_12 ( V_10 -> V_30 ) && V_10 -> V_90 < 0 )
V_2 -> V_214 = false ;
return V_10 ;
remove:
if ( V_2 -> V_193 && V_2 -> V_193 -> V_215 )
V_2 -> V_193 -> V_215 ( V_10 , 0 ) ;
V_208:
if ( V_10 -> V_203 && V_10 -> V_203 -> V_208 )
V_10 -> V_203 -> V_208 ( V_10 -> V_203 ) ;
free:
F_109 ( V_11 ) ;
return F_97 ( V_72 ) ;
}
static void F_110 ( struct V_9 * V_10 )
{
int V_147 ;
T_3 V_116 ;
F_19 ( V_10 ) ;
V_147 = 0 ;
V_116 = F_65 ( V_10 -> V_11 -> V_133 + V_67 ) ;
if ( V_116 == ( T_3 ) - 1 )
V_147 = 1 ;
F_111 ( V_10 -> V_11 , V_147 ) ;
if ( V_10 -> V_2 -> V_193 && V_10 -> V_2 -> V_193 -> V_215 )
V_10 -> V_2 -> V_193 -> V_215 ( V_10 , V_147 ) ;
if ( V_10 -> V_203 && V_10 -> V_203 -> V_208 )
V_10 -> V_203 -> V_208 ( V_10 -> V_203 ) ;
F_109 ( V_10 -> V_11 ) ;
}
static void F_112 ( struct V_81 * V_33 )
{
F_113 ( V_33 , 1 ) ;
F_114 ( V_33 , 50 ) ;
F_115 ( V_33 ) ;
F_116 ( V_33 ) ;
F_117 ( V_33 ) ;
}
static void F_118 ( struct V_81 * V_33 )
{
F_119 ( V_33 ) ;
F_120 ( V_33 ) ;
}
static int F_121 ( struct V_128 * V_3 ,
const struct V_216 * V_217 )
{
struct V_1 * V_2 ;
struct V_9 * V_10 ;
T_2 V_148 , V_198 ;
int V_72 , V_54 ;
F_122 ( V_3 == NULL ) ;
F_122 ( V_217 == NULL ) ;
F_60 ( & V_3 -> V_33 , L_25 ,
( int ) V_3 -> V_218 , ( int ) V_3 -> V_81 , ( int ) V_3 -> V_118 ) ;
V_72 = F_54 ( V_3 , V_219 , & V_148 ) ;
if ( V_72 )
return V_72 ;
V_148 = F_123 ( V_148 ) + 1 ;
F_124 ( & V_3 -> V_33 , L_26 , V_148 ) ;
if ( V_148 == 0 )
return - V_114 ;
F_122 ( V_148 > V_220 ) ;
V_72 = F_54 ( V_3 , V_219 , & V_198 ) ;
if ( V_72 )
return V_72 ;
V_198 &= V_221 ;
if ( V_198 > 5 ) {
F_45 ( & V_3 -> V_33 , L_27 ) ;
return - V_114 ;
}
V_72 = F_125 ( V_3 ) ;
if ( V_72 )
return V_72 ;
V_2 = F_126 ( & V_3 -> V_33 , sizeof( * V_2 ) , V_222 ) ;
if ( ! V_2 )
return - V_223 ;
V_2 -> V_3 = V_3 ;
V_2 -> V_193 = ( const struct V_224 * ) V_217 -> V_225 ;
if ( V_2 -> V_193 ) {
V_2 -> V_7 = V_2 -> V_193 -> V_7 ;
V_2 -> V_111 = V_2 -> V_193 -> V_111 ;
V_2 -> V_214 = V_2 -> V_193 -> V_214 ;
}
V_2 -> V_23 = V_148 ;
F_127 ( V_3 , V_2 ) ;
if ( V_2 -> V_193 && V_2 -> V_193 -> V_226 ) {
V_72 = V_2 -> V_193 -> V_226 ( V_2 ) ;
if ( V_72 )
return V_72 ;
}
V_148 = V_2 -> V_23 ;
for ( V_54 = 0 ; V_54 < V_148 ; V_54 ++ ) {
V_10 = F_95 ( V_3 , V_2 , V_198 , V_54 ) ;
if ( F_100 ( V_10 ) ) {
for ( V_54 -- ; V_54 >= 0 ; V_54 -- )
F_110 ( V_2 -> V_148 [ V_54 ] ) ;
return F_128 ( V_10 ) ;
}
V_2 -> V_148 [ V_54 ] = V_10 ;
}
if ( V_2 -> V_214 )
F_112 ( & V_3 -> V_33 ) ;
return 0 ;
}
static void F_129 ( struct V_128 * V_3 )
{
int V_54 ;
struct V_1 * V_2 = F_85 ( V_3 ) ;
if ( V_2 -> V_214 )
F_118 ( & V_3 -> V_33 ) ;
for ( V_54 = 0 ; V_54 < V_2 -> V_23 ; V_54 ++ )
F_110 ( V_2 -> V_148 [ V_54 ] ) ;
}
