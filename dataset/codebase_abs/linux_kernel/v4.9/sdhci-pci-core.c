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
V_10 -> V_11 -> V_21 -> V_12 |= V_42 | V_38 |
V_79 ;
return 0 ;
}
static int F_42 ( struct V_9 * V_10 )
{
V_10 -> V_11 -> V_21 -> V_12 |= V_79 ;
V_10 -> V_86 = NULL ;
V_10 -> V_87 = 0 ;
V_10 -> V_88 = true ;
if ( V_10 -> V_2 -> V_3 -> V_81 == V_89 ||
V_10 -> V_2 -> V_3 -> V_81 == V_90 ||
V_10 -> V_2 -> V_3 -> V_81 == V_91 ) {
V_10 -> V_11 -> V_92 . V_93 = F_35 ;
V_10 -> V_11 -> V_21 -> V_12 |= V_94 ;
}
return 0 ;
}
static void F_43 ( struct V_26 * V_11 , unsigned char V_95 ,
unsigned short V_96 )
{
int V_97 ;
T_2 V_43 ;
F_44 ( V_11 , V_95 , V_96 ) ;
if ( V_95 == V_98 )
return;
for ( V_97 = 0 ; V_97 < V_99 ; V_97 ++ ) {
V_43 = F_24 ( V_11 , V_44 ) ;
if ( V_43 & V_100 )
break;
F_26 ( V_101 ) ;
V_43 |= V_100 ;
F_25 ( V_11 , V_43 , V_44 ) ;
}
}
static int F_45 ( struct V_9 * V_10 )
{
unsigned int V_102 = F_46 ( V_10 -> V_2 -> V_3 -> V_103 ) ;
switch ( V_102 ) {
case V_104 :
case V_105 :
V_10 -> V_11 -> V_21 -> V_12 |= V_38 |
V_22 |
V_77 ;
break;
case V_106 :
V_10 -> V_11 -> V_107 |= V_108 ;
break;
case V_109 :
V_10 -> V_11 -> V_21 -> V_12 |= V_38 |
V_42 ;
break;
default:
return - V_110 ;
}
return 0 ;
}
static int F_47 ( struct V_1 * V_2 , int V_111 )
{
T_2 V_112 ;
int V_72 ;
V_72 = F_48 ( V_2 -> V_3 , 0xAE , & V_112 ) ;
if ( V_72 )
return V_72 ;
if ( V_111 )
V_112 |= 0x47 ;
else
V_112 &= ~ 0x47 ;
return F_49 ( V_2 -> V_3 , 0xAE , V_112 ) ;
}
static int F_50 ( struct V_1 * V_2 )
{
int V_72 ;
T_4 V_113 = 0 ;
if ( V_2 -> V_3 -> V_114 == 0 ) {
V_2 -> V_7 |= V_115 |
V_116 |
V_117 |
V_118 |
V_119 ;
}
if ( V_2 -> V_3 -> V_81 == V_120 )
V_113 = V_121 ;
else if ( V_2 -> V_3 -> V_81 == V_122 )
V_113 = V_123 ;
if ( V_113 ) {
struct V_124 * V_125 ;
V_125 = NULL ;
while ( ( V_125 = F_51 ( V_126 ,
V_113 , V_125 ) ) != NULL ) {
if ( ( F_52 ( V_2 -> V_3 -> V_103 ) ==
F_52 ( V_125 -> V_103 ) ) &&
( V_2 -> V_3 -> V_127 == V_125 -> V_127 ) )
break;
}
if ( V_125 ) {
F_53 ( V_125 ) ;
F_54 ( & V_2 -> V_3 -> V_33 , L_3
L_4 ) ;
return - V_110 ;
}
}
V_72 = F_47 ( V_2 , 1 ) ;
if ( V_72 ) {
F_55 ( & V_2 -> V_3 -> V_33 , L_5 ) ;
return V_72 ;
}
if ( V_2 -> V_3 -> V_81 == V_122 ||
V_2 -> V_3 -> V_81 == V_123 )
V_2 -> V_7 |= V_128 ;
return 0 ;
}
static void F_56 ( struct V_26 * V_11 , int V_111 )
{
T_2 V_112 ;
V_112 = F_57 ( V_11 -> V_129 + 0xC0 ) ;
if ( V_111 )
V_112 |= 0x01 ;
else
V_112 &= ~ 0x01 ;
F_58 ( V_112 , V_11 -> V_129 + 0xC0 ) ;
}
static int F_59 ( struct V_9 * V_10 )
{
if ( V_10 -> V_2 -> V_3 -> V_114 == 0 ) {
T_4 V_130 ;
V_130 = F_60 ( V_10 -> V_11 -> V_129 + V_131 ) ;
V_130 = ( V_130 & V_132 ) >>
V_133 ;
if ( V_130 < 0xAC )
V_10 -> V_11 -> V_7 |= V_134 ;
}
if ( V_10 -> V_2 -> V_3 -> V_81 == V_123 ) {
V_10 -> V_11 -> V_135 = V_136 | V_137 |
V_138 | V_139 |
V_140 ;
V_10 -> V_11 -> V_141 = V_136 | V_137 |
V_138 | V_139 ;
}
if ( V_10 -> V_2 -> V_3 -> V_81 == V_121 ||
V_10 -> V_2 -> V_3 -> V_81 == V_123 )
F_56 ( V_10 -> V_11 , 1 ) ;
V_10 -> V_11 -> V_21 -> V_12 |= V_142 ;
return 0 ;
}
static void F_61 ( struct V_9 * V_10 , int V_143 )
{
if ( V_143 )
return;
if ( V_10 -> V_2 -> V_3 -> V_81 == V_121 ||
V_10 -> V_2 -> V_3 -> V_81 == V_123 )
F_56 ( V_10 -> V_11 , 0 ) ;
}
static int F_62 ( struct V_1 * V_2 )
{
int V_54 ;
if ( V_2 -> V_3 -> V_81 == V_121 ||
V_2 -> V_3 -> V_81 == V_123 ) {
for ( V_54 = 0 ; V_54 < V_2 -> V_23 ; V_54 ++ )
F_56 ( V_2 -> V_144 [ V_54 ] -> V_11 , 0 ) ;
}
return 0 ;
}
static int F_63 ( struct V_1 * V_2 )
{
int V_72 , V_54 ;
if ( V_2 -> V_3 -> V_81 == V_121 ||
V_2 -> V_3 -> V_81 == V_123 ) {
for ( V_54 = 0 ; V_54 < V_2 -> V_23 ; V_54 ++ )
F_56 ( V_2 -> V_144 [ V_54 ] -> V_11 , 1 ) ;
}
V_72 = F_47 ( V_2 , 1 ) ;
if ( V_72 ) {
F_55 ( & V_2 -> V_3 -> V_33 , L_5 ) ;
return V_72 ;
}
return 0 ;
}
static int F_64 ( struct V_1 * V_2 )
{
if ( ( V_2 -> V_3 -> V_145 & 0x0000FF ) == V_146 ) {
V_2 -> V_3 -> V_145 &= ~ 0x0000FF ;
V_2 -> V_3 -> V_145 |= V_147 ;
}
return 0 ;
}
static int F_65 ( struct V_9 * V_10 )
{
int V_148 , V_149 ;
T_2 V_150 = F_57 ( V_10 -> V_11 -> V_129 + V_151 ) ;
T_2 V_152 = F_57 ( V_10 -> V_11 -> V_129 + V_153 ) ;
F_54 ( & V_10 -> V_2 -> V_3 -> V_33 , L_6
L_7 ,
V_150 >> 4 , V_150 & 0xf ,
V_152 >> 4 , V_152 & 0xf ) ;
if ( V_152 >= 0x20 )
V_10 -> V_11 -> V_7 |= V_154 ;
F_58 ( V_155 , V_10 -> V_11 -> V_129 + V_156 ) ;
F_58 ( V_157 , V_10 -> V_11 -> V_129 + V_158 ) ;
F_26 ( 50 ) ;
V_148 = 10 ;
do {
V_149 = F_66 ( V_10 -> V_11 -> V_129 + V_159 ) ;
if ( V_149 & V_160 )
break;
F_26 ( 100 ) ;
} while ( -- V_148 );
if ( ! V_148 ) {
F_55 ( & V_10 -> V_2 -> V_3 -> V_33 ,
L_8 ) ;
F_58 ( 0 , V_10 -> V_11 -> V_129 + V_158 ) ;
return - V_110 ;
}
return 0 ;
}
static int F_67 ( struct V_1 * V_2 )
{
if ( V_2 -> V_3 -> V_114 == 0x10 )
V_2 -> V_7 |= V_161 ;
return 0 ;
}
static int F_68 ( struct V_9 * V_10 )
{
V_10 -> V_11 -> V_21 -> V_39 |= V_162 ;
return 0 ;
}
static int F_69 ( struct V_1 * V_2 )
{
struct V_124 * V_163 ;
enum V_164 V_165 ;
V_163 = F_51 ( V_166 ,
V_167 , NULL ) ;
if ( V_163 ) {
V_165 = V_168 ;
} else {
V_163 = F_51 ( V_166 ,
V_169 , NULL ) ;
if ( V_163 ) {
if ( V_163 -> V_114 < 0x51 )
V_165 = V_170 ;
else
V_165 = V_171 ;
} else {
V_165 = V_172 ;
}
}
if ( ( V_165 == V_168 ) || ( V_165 == V_170 ) ) {
V_2 -> V_107 |= V_173 ;
V_2 -> V_107 |= V_174 ;
}
return 0 ;
}
static int F_70 ( struct V_26 * V_11 )
{
struct V_9 * V_10 ;
struct V_124 * V_3 ;
V_10 = F_71 ( V_11 ) ;
V_3 = V_10 -> V_2 -> V_3 ;
if ( ( ( V_3 -> V_145 & 0xFFFF00 ) == ( V_175 << 8 ) ) &&
( ( V_3 -> V_145 & 0x0000FF ) != V_147 ) &&
( V_11 -> V_71 & V_176 ) ) {
F_18 ( & V_3 -> V_33 , L_9
L_10 ) ;
}
F_72 ( V_3 ) ;
return 0 ;
}
static void F_73 ( struct V_26 * V_11 , int V_177 )
{
T_2 V_178 ;
V_178 = F_24 ( V_11 , V_179 ) ;
switch ( V_177 ) {
case V_180 :
V_178 |= V_181 ;
V_178 &= ~ V_182 ;
break;
case V_183 :
V_178 |= V_182 ;
V_178 &= ~ V_181 ;
break;
default:
V_178 &= ~ ( V_181 | V_182 ) ;
break;
}
F_25 ( V_11 , V_178 , V_179 ) ;
}
static void F_74 ( struct V_26 * V_11 )
{
struct V_9 * V_10 = F_71 ( V_11 ) ;
int V_184 = V_10 -> V_184 ;
if ( ! F_12 ( V_184 ) )
return;
F_75 ( V_184 , 0 ) ;
F_26 ( 10 ) ;
F_75 ( V_184 , 1 ) ;
F_27 ( 300 , 1000 ) ;
}
static void F_76 ( struct V_26 * V_11 )
{
struct V_9 * V_10 = F_71 ( V_11 ) ;
if ( V_10 -> V_80 )
V_10 -> V_80 ( V_11 ) ;
}
static int F_77 ( struct V_26 * V_11 ,
struct V_45 * V_46 ,
unsigned int V_47 , int V_48 ,
int V_49 , int * V_50 )
{
struct V_9 * V_10 = F_71 ( V_11 ) ;
if ( ! V_10 -> V_85 )
return 0 ;
return V_10 -> V_85 ( V_11 , V_46 , V_47 , V_48 ,
V_49 , V_50 ) ;
}
static int F_78 ( struct V_81 * V_33 )
{
struct V_124 * V_3 = F_79 ( V_33 ) ;
struct V_1 * V_2 ;
struct V_9 * V_10 ;
T_5 V_185 ;
T_5 V_186 = 0 ;
int V_54 , V_72 ;
V_2 = F_80 ( V_3 ) ;
if ( ! V_2 )
return 0 ;
for ( V_54 = 0 ; V_54 < V_2 -> V_23 ; V_54 ++ ) {
V_10 = V_2 -> V_144 [ V_54 ] ;
if ( ! V_10 )
continue;
V_72 = F_81 ( V_10 -> V_11 ) ;
if ( V_72 )
goto V_187;
V_185 = V_10 -> V_11 -> V_21 -> V_186 ;
if ( V_185 & V_188 )
F_82 ( V_10 -> V_11 ) ;
V_186 |= V_185 ;
}
if ( V_2 -> V_189 && V_2 -> V_189 -> V_190 ) {
V_72 = V_2 -> V_189 -> V_190 ( V_2 ) ;
if ( V_72 )
goto V_187;
}
if ( V_186 & V_191 ) {
if ( V_186 & V_188 )
F_83 ( V_33 , true ) ;
else
F_83 ( V_33 , false ) ;
} else
F_83 ( V_33 , false ) ;
return 0 ;
V_187:
while ( -- V_54 >= 0 )
F_84 ( V_2 -> V_144 [ V_54 ] -> V_11 ) ;
return V_72 ;
}
static int F_85 ( struct V_81 * V_33 )
{
struct V_124 * V_3 = F_79 ( V_33 ) ;
struct V_1 * V_2 ;
struct V_9 * V_10 ;
int V_54 , V_72 ;
V_2 = F_80 ( V_3 ) ;
if ( ! V_2 )
return 0 ;
if ( V_2 -> V_189 && V_2 -> V_189 -> V_192 ) {
V_72 = V_2 -> V_189 -> V_192 ( V_2 ) ;
if ( V_72 )
return V_72 ;
}
for ( V_54 = 0 ; V_54 < V_2 -> V_23 ; V_54 ++ ) {
V_10 = V_2 -> V_144 [ V_54 ] ;
if ( ! V_10 )
continue;
V_72 = F_84 ( V_10 -> V_11 ) ;
if ( V_72 )
return V_72 ;
}
return 0 ;
}
static int F_86 ( struct V_81 * V_33 )
{
struct V_124 * V_3 = F_79 ( V_33 ) ;
struct V_1 * V_2 ;
struct V_9 * V_10 ;
int V_54 , V_72 ;
V_2 = F_80 ( V_3 ) ;
if ( ! V_2 )
return 0 ;
for ( V_54 = 0 ; V_54 < V_2 -> V_23 ; V_54 ++ ) {
V_10 = V_2 -> V_144 [ V_54 ] ;
if ( ! V_10 )
continue;
V_72 = F_87 ( V_10 -> V_11 ) ;
if ( V_72 )
goto V_193;
}
if ( V_2 -> V_189 && V_2 -> V_189 -> V_190 ) {
V_72 = V_2 -> V_189 -> V_190 ( V_2 ) ;
if ( V_72 )
goto V_193;
}
return 0 ;
V_193:
while ( -- V_54 >= 0 )
F_88 ( V_2 -> V_144 [ V_54 ] -> V_11 ) ;
return V_72 ;
}
static int F_89 ( struct V_81 * V_33 )
{
struct V_124 * V_3 = F_79 ( V_33 ) ;
struct V_1 * V_2 ;
struct V_9 * V_10 ;
int V_54 , V_72 ;
V_2 = F_80 ( V_3 ) ;
if ( ! V_2 )
return 0 ;
if ( V_2 -> V_189 && V_2 -> V_189 -> V_192 ) {
V_72 = V_2 -> V_189 -> V_192 ( V_2 ) ;
if ( V_72 )
return V_72 ;
}
for ( V_54 = 0 ; V_54 < V_2 -> V_23 ; V_54 ++ ) {
V_10 = V_2 -> V_144 [ V_54 ] ;
if ( ! V_10 )
continue;
V_72 = F_88 ( V_10 -> V_11 ) ;
if ( V_72 )
return V_72 ;
}
return 0 ;
}
static struct V_9 * F_90 (
struct V_124 * V_3 , struct V_1 * V_2 , int V_194 ,
int V_195 )
{
struct V_9 * V_10 ;
struct V_26 * V_11 ;
int V_72 , V_196 = V_194 + V_195 ;
if ( ! ( F_91 ( V_3 , V_196 ) & V_197 ) ) {
F_55 ( & V_3 -> V_33 , L_11 , V_196 ) ;
return F_92 ( - V_110 ) ;
}
if ( F_93 ( V_3 , V_196 ) < 0x100 ) {
F_55 ( & V_3 -> V_33 , L_12
L_13 ) ;
}
if ( ( V_3 -> V_145 & 0x0000FF ) == V_146 ) {
F_55 ( & V_3 -> V_33 , L_14 ) ;
return F_92 ( - V_110 ) ;
}
if ( ( V_3 -> V_145 & 0x0000FF ) > V_146 ) {
F_55 ( & V_3 -> V_33 , L_15 ) ;
return F_92 ( - V_110 ) ;
}
V_11 = F_94 ( & V_3 -> V_33 , sizeof( struct V_9 ) ) ;
if ( F_95 ( V_11 ) ) {
F_55 ( & V_3 -> V_33 , L_16 ) ;
return F_96 ( V_11 ) ;
}
V_10 = F_71 ( V_11 ) ;
V_10 -> V_2 = V_2 ;
V_10 -> V_11 = V_11 ;
V_10 -> V_184 = - V_31 ;
V_10 -> V_30 = - V_31 ;
V_10 -> V_87 = - 1 ;
if ( * V_198 )
V_10 -> V_199 = V_198 ( V_3 , V_195 ) ;
if ( V_10 -> V_199 ) {
if ( V_10 -> V_199 -> V_200 ) {
V_72 = V_10 -> V_199 -> V_200 ( V_10 -> V_199 ) ;
if ( V_72 ) {
F_55 ( & V_3 -> V_33 , L_17 ) ;
goto free;
}
}
V_10 -> V_184 = V_10 -> V_199 -> V_184 ;
V_10 -> V_30 = V_10 -> V_199 -> V_30 ;
}
V_11 -> V_201 = L_18 ;
V_11 -> V_202 = V_2 -> V_189 && V_2 -> V_189 -> V_202 ?
V_2 -> V_189 -> V_202 :
& V_203 ;
V_11 -> V_7 = V_2 -> V_7 ;
V_11 -> V_107 = V_2 -> V_107 ;
V_11 -> V_24 = V_3 -> V_24 ;
V_72 = F_97 ( V_3 , F_98 ( V_196 ) , F_99 ( V_11 -> V_21 ) ) ;
if ( V_72 ) {
F_55 ( & V_3 -> V_33 , L_19 ) ;
goto V_204;
}
V_11 -> V_129 = F_100 ( V_3 ) [ V_196 ] ;
if ( V_2 -> V_189 && V_2 -> V_189 -> V_205 ) {
V_72 = V_2 -> V_189 -> V_205 ( V_10 ) ;
if ( V_72 )
goto V_204;
}
if ( F_12 ( V_10 -> V_184 ) ) {
if ( ! F_13 ( & V_3 -> V_33 , V_10 -> V_184 , L_20 ) ) {
F_101 ( V_10 -> V_184 , 1 ) ;
V_10 -> V_11 -> V_21 -> V_12 |= V_76 ;
V_10 -> V_80 = F_74 ;
} else {
F_18 ( & V_3 -> V_33 , L_21 ) ;
V_10 -> V_184 = - V_31 ;
}
}
V_11 -> V_21 -> V_206 = V_191 | V_188 ;
V_11 -> V_21 -> V_195 = V_195 ;
V_11 -> V_21 -> V_39 |= V_207 ;
if ( V_10 -> V_87 >= 0 &&
F_102 ( V_11 -> V_21 , V_10 -> V_86 , V_10 -> V_87 ,
V_10 -> V_88 , 0 , NULL ) ) {
F_18 ( & V_3 -> V_33 , L_22 ) ;
V_10 -> V_87 = - 1 ;
}
V_72 = F_103 ( V_11 ) ;
if ( V_72 )
goto remove;
F_11 ( V_10 ) ;
if ( V_2 -> V_189 && V_2 -> V_189 -> V_208 &&
! F_12 ( V_10 -> V_30 ) && V_10 -> V_87 < 0 )
V_2 -> V_209 = false ;
return V_10 ;
remove:
if ( V_2 -> V_189 && V_2 -> V_189 -> V_210 )
V_2 -> V_189 -> V_210 ( V_10 , 0 ) ;
V_204:
if ( V_10 -> V_199 && V_10 -> V_199 -> V_204 )
V_10 -> V_199 -> V_204 ( V_10 -> V_199 ) ;
free:
F_104 ( V_11 ) ;
return F_92 ( V_72 ) ;
}
static void F_105 ( struct V_9 * V_10 )
{
int V_143 ;
T_3 V_112 ;
F_19 ( V_10 ) ;
V_143 = 0 ;
V_112 = F_60 ( V_10 -> V_11 -> V_129 + V_67 ) ;
if ( V_112 == ( T_3 ) - 1 )
V_143 = 1 ;
F_106 ( V_10 -> V_11 , V_143 ) ;
if ( V_10 -> V_2 -> V_189 && V_10 -> V_2 -> V_189 -> V_210 )
V_10 -> V_2 -> V_189 -> V_210 ( V_10 , V_143 ) ;
if ( V_10 -> V_199 && V_10 -> V_199 -> V_204 )
V_10 -> V_199 -> V_204 ( V_10 -> V_199 ) ;
F_104 ( V_10 -> V_11 ) ;
}
static void F_107 ( struct V_81 * V_33 )
{
F_108 ( V_33 , 1 ) ;
F_109 ( V_33 , 50 ) ;
F_110 ( V_33 ) ;
F_111 ( V_33 ) ;
F_112 ( V_33 ) ;
}
static void F_113 ( struct V_81 * V_33 )
{
F_114 ( V_33 ) ;
F_115 ( V_33 ) ;
}
static int F_116 ( struct V_124 * V_3 ,
const struct V_211 * V_212 )
{
struct V_1 * V_2 ;
struct V_9 * V_10 ;
T_2 V_144 , V_194 ;
int V_72 , V_54 ;
F_117 ( V_3 == NULL ) ;
F_117 ( V_212 == NULL ) ;
F_54 ( & V_3 -> V_33 , L_23 ,
( int ) V_3 -> V_213 , ( int ) V_3 -> V_81 , ( int ) V_3 -> V_114 ) ;
V_72 = F_48 ( V_3 , V_214 , & V_144 ) ;
if ( V_72 )
return V_72 ;
V_144 = F_118 ( V_144 ) + 1 ;
F_119 ( & V_3 -> V_33 , L_24 , V_144 ) ;
if ( V_144 == 0 )
return - V_110 ;
F_117 ( V_144 > V_215 ) ;
V_72 = F_48 ( V_3 , V_214 , & V_194 ) ;
if ( V_72 )
return V_72 ;
V_194 &= V_216 ;
if ( V_194 > 5 ) {
F_55 ( & V_3 -> V_33 , L_25 ) ;
return - V_110 ;
}
V_72 = F_120 ( V_3 ) ;
if ( V_72 )
return V_72 ;
V_2 = F_121 ( & V_3 -> V_33 , sizeof( * V_2 ) , V_217 ) ;
if ( ! V_2 )
return - V_218 ;
V_2 -> V_3 = V_3 ;
V_2 -> V_189 = ( const struct V_219 * ) V_212 -> V_220 ;
if ( V_2 -> V_189 ) {
V_2 -> V_7 = V_2 -> V_189 -> V_7 ;
V_2 -> V_107 = V_2 -> V_189 -> V_107 ;
V_2 -> V_209 = V_2 -> V_189 -> V_209 ;
}
V_2 -> V_23 = V_144 ;
F_122 ( V_3 , V_2 ) ;
if ( V_2 -> V_189 && V_2 -> V_189 -> V_221 ) {
V_72 = V_2 -> V_189 -> V_221 ( V_2 ) ;
if ( V_72 )
return V_72 ;
}
V_144 = V_2 -> V_23 ;
for ( V_54 = 0 ; V_54 < V_144 ; V_54 ++ ) {
V_10 = F_90 ( V_3 , V_2 , V_194 , V_54 ) ;
if ( F_95 ( V_10 ) ) {
for ( V_54 -- ; V_54 >= 0 ; V_54 -- )
F_105 ( V_2 -> V_144 [ V_54 ] ) ;
return F_123 ( V_10 ) ;
}
V_2 -> V_144 [ V_54 ] = V_10 ;
}
if ( V_2 -> V_209 )
F_107 ( & V_3 -> V_33 ) ;
return 0 ;
}
static void F_124 ( struct V_124 * V_3 )
{
int V_54 ;
struct V_1 * V_2 = F_80 ( V_3 ) ;
if ( V_2 -> V_209 )
F_113 ( & V_3 -> V_33 ) ;
for ( V_54 = 0 ; V_54 < V_2 -> V_23 ; V_54 ++ )
F_105 ( V_2 -> V_144 [ V_54 ] ) ;
}
