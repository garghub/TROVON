static int F_1 ( struct V_1 * V_2 )
{
if ( V_2 -> V_3 . V_4 != 0 || V_2 -> V_5 == 0 )
return V_2 -> V_3 . V_4 ;
else
return - 1 ;
}
static T_1 F_2 ( struct V_6 * V_7 ,
struct V_8 * V_9 ,
char * V_10 )
{
struct V_11 * V_12 = F_3 ( V_7 ) ;
struct V_1 * V_2 = F_4 ( V_12 ) ;
return sprintf ( V_10 , L_1 , V_2 -> V_13 . V_14 ) ;
}
static T_1 F_5 ( struct V_6 * V_7 ,
struct V_8 * V_9 ,
const char * V_10 , T_2 V_15 )
{
struct V_11 * V_12 = F_3 ( V_7 ) ;
struct V_1 * V_2 = F_4 ( V_12 ) ;
unsigned long V_16 ;
if ( F_6 ( V_10 , 0 , & V_16 ) )
return - V_17 ;
V_2 -> V_13 . V_14 = V_16 ;
if ( V_2 -> V_18 < 0 )
V_2 -> V_13 . V_14 &= ~ V_19 ;
return V_15 ;
}
static void F_7 ( struct V_11 * V_12 , struct V_20 * V_21 )
{
struct V_1 * V_2 = F_4 ( V_12 ) ;
int V_22 , V_23 = F_8 ( V_21 ) ;
T_3 * V_10 ;
if ( V_2 -> V_24 & V_25 )
return;
V_10 = F_9 ( V_21 , V_26 ) ;
if ( ! V_10 )
return;
V_22 = F_10 ( V_12 , V_21 -> V_27 , V_10 , V_23 ,
V_28 , V_29 ) ;
if ( V_22 < 0 ) {
F_11 ( & V_12 -> V_7 , L_2 ,
V_21 -> V_27 ) ;
} else {
V_22 = F_12 ( V_12 , V_28 , V_10 ,
V_23 , 0 ) ;
if ( V_22 )
F_11 ( & V_12 -> V_7 , L_3 ) ;
}
F_13 ( V_10 ) ;
}
static void F_14 ( struct V_11 * V_12 ,
struct V_30 * V_31 , struct V_32 * V_33 )
{
struct V_1 * V_2 = F_4 ( V_12 ) ;
switch ( V_33 -> V_34 ) {
case V_35 :
if ( V_33 -> V_36 >= V_31 -> V_37 ) {
F_15 ( & V_12 -> V_7 , L_4 ) ;
break;
}
if ( V_2 -> V_38 < 0 ) {
V_2 -> V_38 = V_31 -> V_21 -> V_27 ;
V_2 -> V_39 = V_33 -> V_36 ;
} else {
F_16 ( & V_12 -> V_7 ,
L_5 ) ;
}
break;
case V_40 :
F_7 ( V_12 , V_31 -> V_21 ) ;
V_2 -> V_41 = V_31 -> V_21 -> V_27 ;
V_2 -> V_42 = V_31 -> V_43 [ 0 ] ;
if ( ! V_2 -> V_42 &&
V_31 -> V_44 <= V_45 )
V_2 -> V_42 = V_31 -> V_44 ;
if ( V_2 -> V_13 . V_42 )
V_2 -> V_42 = V_2 -> V_13 . V_42 ;
break;
case V_46 :
if ( V_33 -> V_36 >= V_31 -> V_37 ) {
F_15 ( & V_12 -> V_7 , L_6 ) ;
break;
}
F_7 ( V_12 , V_31 -> V_21 ) ;
if ( V_31 -> V_43 [ V_33 -> V_36 ] == V_47 )
V_2 -> V_48 = true ;
break;
case 0xff0000c5 :
if ( V_33 -> V_36 == 0 )
F_7 ( V_12 , V_31 -> V_21 ) ;
break;
}
}
static void F_17 ( struct V_49 * V_50 , unsigned int V_51 ,
struct V_30 * V_31 , int V_52 )
{
int V_53 = V_31 -> V_54 ;
int V_55 = V_31 -> V_44 ;
int V_56 = V_52 ? ( V_55 - V_53 ) / V_52 : 0 ;
F_18 ( V_50 , V_51 , V_53 , V_55 , V_56 , 0 ) ;
F_19 ( V_50 , V_51 , F_20 ( V_31 , V_51 ) ) ;
}
static void F_21 ( struct V_32 * V_33 , struct V_1 * V_2 ,
struct V_57 * V_58 )
{
struct V_59 * V_60 = V_2 -> V_61 ;
if ( V_60 -> V_62 >= V_63 )
return;
V_60 -> V_64 [ V_60 -> V_62 ++ ] = V_33 -> V_34 ;
}
static int F_22 ( struct V_11 * V_12 , struct V_57 * V_58 ,
struct V_30 * V_31 , struct V_32 * V_33 ,
unsigned long * * V_65 , int * V_66 )
{
struct V_1 * V_2 = F_4 ( V_12 ) ;
struct V_67 * V_68 = & V_2 -> V_13 ;
int V_51 ;
struct V_32 * V_69 = NULL ;
if ( V_31 -> V_70 == V_71 )
V_2 -> V_72 |= V_73 ;
if ( V_31 -> V_70 == V_74 ||
( V_33 -> V_34 & V_75 ) == V_76 ) {
V_2 -> V_72 |= V_77 ;
V_2 -> V_78 = V_79 ;
}
if ( ( V_33 -> V_34 & V_75 ) == V_76 )
V_2 -> V_80 ++ ;
if ( V_33 -> V_36 )
V_69 = & V_31 -> V_33 [ V_33 -> V_36 - 1 ] ;
switch ( V_33 -> V_34 & V_75 ) {
case V_81 :
switch ( V_33 -> V_34 ) {
case V_82 :
if ( V_69 && ( V_69 -> V_34 == V_33 -> V_34 ) ) {
F_23 ( V_58 , V_33 , V_65 , V_66 ,
V_83 , V_84 ) ;
F_17 ( V_58 -> V_50 , V_84 , V_31 ,
V_68 -> V_85 ) ;
} else {
F_23 ( V_58 , V_33 , V_65 , V_66 ,
V_83 , V_86 ) ;
F_17 ( V_58 -> V_50 , V_86 , V_31 ,
V_68 -> V_85 ) ;
}
F_21 ( V_33 , V_2 , V_58 ) ;
return 1 ;
case V_87 :
if ( V_69 && ( V_69 -> V_34 == V_33 -> V_34 ) ) {
F_23 ( V_58 , V_33 , V_65 , V_66 ,
V_83 , V_88 ) ;
F_17 ( V_58 -> V_50 , V_88 , V_31 ,
V_68 -> V_85 ) ;
} else {
F_23 ( V_58 , V_33 , V_65 , V_66 ,
V_83 , V_89 ) ;
F_17 ( V_58 -> V_50 , V_89 , V_31 ,
V_68 -> V_85 ) ;
}
F_21 ( V_33 , V_2 , V_58 ) ;
return 1 ;
}
return 0 ;
case V_90 :
switch ( V_33 -> V_34 ) {
case V_91 :
if ( V_68 -> V_14 & V_92 ) {
F_23 ( V_58 , V_33 , V_65 , V_66 ,
V_83 , V_93 ) ;
F_18 ( V_58 -> V_50 ,
V_93 , 0 , 1 , 0 , 0 ) ;
}
F_21 ( V_33 , V_2 , V_58 ) ;
return 1 ;
case V_94 :
if ( ( V_68 -> V_95 == V_96 ||
V_68 -> V_95 == V_97 ) &&
V_31 -> V_70 == V_74 )
V_68 -> V_14 |= V_98 ;
F_21 ( V_33 , V_2 , V_58 ) ;
return 1 ;
case V_99 :
F_23 ( V_58 , V_33 , V_65 , V_66 , V_100 , V_101 ) ;
F_24 ( V_58 -> V_50 , V_100 , V_101 ) ;
F_21 ( V_33 , V_2 , V_58 ) ;
return 1 ;
case V_102 :
F_21 ( V_33 , V_2 , V_58 ) ;
V_2 -> V_103 ++ ;
V_2 -> V_104 = V_31 -> V_21 -> V_27 ;
return 1 ;
case V_105 :
F_23 ( V_58 , V_33 , V_65 , V_66 ,
V_83 , V_106 ) ;
if ( ! ( V_68 -> V_14 & V_107 ) )
F_17 ( V_58 -> V_50 , V_106 , V_31 ,
V_68 -> V_108 ) ;
F_21 ( V_33 , V_2 , V_58 ) ;
return 1 ;
case V_109 :
F_23 ( V_58 , V_33 , V_65 , V_66 ,
V_83 , V_110 ) ;
if ( ! ( V_68 -> V_14 & V_107 ) ) {
F_17 ( V_58 -> V_50 , V_110 , V_31 ,
V_68 -> V_111 ) ;
F_18 ( V_58 -> V_50 ,
V_112 , 0 , 1 , 0 , 0 ) ;
}
F_21 ( V_33 , V_2 , V_58 ) ;
return 1 ;
case V_113 :
F_23 ( V_58 , V_33 , V_65 , V_66 ,
V_83 , V_114 ) ;
F_17 ( V_58 -> V_50 , V_114 , V_31 ,
V_68 -> V_115 ) ;
F_21 ( V_33 , V_2 , V_58 ) ;
return 1 ;
case V_116 :
if ( V_31 -> V_117 >= V_31 -> V_21 -> V_118 ||
V_33 -> V_36 >= V_31 -> V_37 )
return 1 ;
V_2 -> V_18 = V_31 -> V_117 ;
V_2 -> V_119 = V_33 -> V_36 ;
return 1 ;
case V_40 :
return - 1 ;
case V_120 :
return - 1 ;
}
return 0 ;
case V_76 :
V_51 = V_121 + ( ( V_33 -> V_34 - 1 ) & V_122 ) ;
if ( ( V_68 -> V_95 == V_96 ||
V_68 -> V_95 == V_97 ) &&
V_31 -> V_70 == V_74 &&
( V_33 -> V_34 & V_122 ) > 1 )
V_51 -- ;
F_23 ( V_58 , V_33 , V_65 , V_66 , V_100 , V_51 ) ;
F_24 ( V_58 -> V_50 , V_100 , V_51 ) ;
return 1 ;
case 0xff000000 :
return - 1 ;
}
return 0 ;
}
static int F_25 ( struct V_1 * V_2 , struct V_49 * V_50 )
{
T_4 V_14 = V_2 -> V_13 . V_14 ;
if ( V_14 & V_123 )
return V_2 -> V_3 . V_4 ;
if ( V_14 & V_124 )
return F_1 ( V_2 ) ;
if ( V_14 & V_125 )
return V_2 -> V_5 ;
if ( V_14 & V_126 )
return V_2 -> V_3 . V_4 - 1 ;
return F_26 ( V_50 , V_2 -> V_3 . V_4 ) ;
}
static void F_27 ( struct V_1 * V_2 , struct V_49 * V_50 )
{
if ( ( V_2 -> V_13 . V_14 & V_19 ) &&
V_2 -> V_5 >= V_2 -> V_127 )
return;
if ( V_2 -> V_128 || ( V_2 -> V_13 . V_14 & V_129 ) ) {
int V_130 ;
int V_131 = F_25 ( V_2 , V_50 ) ;
struct V_132 * V_133 = & V_2 -> V_3 ;
struct V_134 * V_135 = V_50 -> V_135 ;
if ( V_131 < 0 || V_131 >= V_2 -> V_42 )
return;
if ( ( V_2 -> V_13 . V_14 & V_136 ) && V_135 ) {
struct V_137 * V_138 = & V_135 -> V_139 [ V_131 ] ;
if ( F_28 ( V_138 ) &&
F_29 ( V_135 , V_138 ) )
return;
}
if ( ! ( V_2 -> V_13 . V_14 & V_98 ) )
V_133 -> V_140 = 1 ;
V_130 = ( V_133 -> V_141 || V_133 -> V_142 ) &&
V_133 -> V_140 ;
V_137 ( V_50 , V_131 ) ;
F_30 ( V_50 , V_143 , V_130 ) ;
if ( V_130 ) {
int V_144 = ( V_133 -> V_145 > V_133 -> V_146 ) ;
int V_147 = V_66 ( V_133 -> V_145 , V_133 -> V_146 ) ;
int V_148 = F_31 ( V_133 -> V_145 , V_133 -> V_146 ) ;
if ( V_2 -> V_13 . V_14 & V_149 ) {
V_147 = V_147 >> 1 ;
V_148 = V_148 >> 1 ;
}
F_32 ( V_50 , V_83 , V_86 , V_133 -> V_150 ) ;
F_32 ( V_50 , V_83 , V_89 , V_133 -> V_151 ) ;
F_32 ( V_50 , V_83 , V_84 , V_133 -> V_152 ) ;
F_32 ( V_50 , V_83 , V_88 , V_133 -> V_153 ) ;
F_32 ( V_50 , V_83 , V_93 ,
! V_133 -> V_141 ) ;
F_32 ( V_50 , V_83 , V_112 , V_144 ) ;
F_32 ( V_50 , V_83 , V_114 , V_133 -> V_154 ) ;
F_32 ( V_50 , V_83 , V_106 , V_147 ) ;
F_32 ( V_50 , V_83 , V_110 , V_148 ) ;
F_33 ( V_155 , & V_2 -> V_156 ) ;
}
}
V_2 -> V_5 ++ ;
}
static void F_34 ( struct V_1 * V_2 , struct V_49 * V_50 )
{
F_35 ( V_50 ) ;
F_36 ( V_50 ) ;
V_2 -> V_5 = 0 ;
if ( F_37 ( V_155 , & V_2 -> V_156 ) )
F_33 ( V_157 , & V_2 -> V_156 ) ;
else
F_38 ( V_157 , & V_2 -> V_156 ) ;
F_38 ( V_155 , & V_2 -> V_156 ) ;
}
static int F_39 ( struct V_11 * V_34 , struct V_30 * V_31 ,
struct V_32 * V_33 , T_4 V_43 )
{
if ( V_34 -> V_158 & V_159 && V_34 -> V_160 )
V_34 -> V_160 ( V_34 , V_31 , V_33 , V_43 ) ;
return 1 ;
}
static void F_40 ( struct V_11 * V_34 , struct V_30 * V_31 ,
struct V_32 * V_33 , T_4 V_43 )
{
struct V_1 * V_2 = F_4 ( V_34 ) ;
T_4 V_14 = V_2 -> V_13 . V_14 ;
struct V_49 * V_50 = V_31 -> V_161 -> V_50 ;
if ( V_34 -> V_158 & V_162 ) {
switch ( V_33 -> V_34 ) {
case V_91 :
if ( V_14 & V_163 )
V_2 -> V_128 = V_43 ;
if ( V_14 & V_92 )
V_2 -> V_3 . V_142 = V_43 ;
break;
case V_99 :
if ( V_14 & V_164 )
V_2 -> V_128 = V_43 ;
V_2 -> V_3 . V_141 = V_43 ;
break;
case V_94 :
if ( V_14 & V_98 )
V_2 -> V_3 . V_140 = V_43 ;
if ( V_14 & V_165 )
V_2 -> V_128 = V_43 ;
break;
case V_102 :
V_2 -> V_3 . V_4 = V_43 ;
break;
case V_113 :
V_2 -> V_3 . V_154 = V_43 ;
break;
case V_82 :
if ( V_33 -> V_51 == V_84 )
V_2 -> V_3 . V_152 = V_43 ;
else
V_2 -> V_3 . V_150 = V_43 ;
break;
case V_87 :
if ( V_33 -> V_51 == V_88 )
V_2 -> V_3 . V_153 = V_43 ;
else
V_2 -> V_3 . V_151 = V_43 ;
break;
case V_105 :
V_2 -> V_3 . V_145 = V_43 ;
break;
case V_109 :
V_2 -> V_3 . V_146 = V_43 ;
break;
case V_116 :
break;
case V_120 :
break;
default:
if ( V_33 -> type )
F_32 ( V_50 , V_33 -> type , V_33 -> V_51 ,
V_43 ) ;
return;
}
if ( V_33 -> V_36 + 1 == V_31 -> V_37 ) {
if ( V_33 -> V_34 == V_2 -> V_166 )
F_27 ( V_2 , V_31 -> V_161 -> V_50 ) ;
}
}
}
static void F_41 ( struct V_11 * V_34 , struct V_20 * V_21 )
{
struct V_1 * V_2 = F_4 ( V_34 ) ;
struct V_30 * V_31 ;
unsigned V_15 ;
int V_167 , V_168 ;
if ( F_42 ( V_169 , & V_2 -> V_156 ) )
return;
if ( V_2 -> V_18 >= 0 ) {
struct V_30 * V_31 = V_21 -> V_31 [ V_2 -> V_18 ] ;
int V_43 = V_31 -> V_43 [ V_2 -> V_119 ] ;
if ( V_43 )
V_2 -> V_127 = V_43 ;
}
for ( V_167 = 0 ; V_167 < V_21 -> V_118 ; V_167 ++ ) {
V_31 = V_21 -> V_31 [ V_167 ] ;
V_15 = V_31 -> V_37 ;
if ( ! ( V_170 & V_31 -> V_171 ) )
continue;
for ( V_168 = 0 ; V_168 < V_15 ; V_168 ++ )
F_40 ( V_34 , V_31 , & V_31 -> V_33 [ V_168 ] ,
V_31 -> V_43 [ V_168 ] ) ;
}
if ( V_2 -> V_5 >= V_2 -> V_127 )
F_34 ( V_2 , V_21 -> V_31 [ 0 ] -> V_161 -> V_50 ) ;
if ( V_2 -> V_13 . V_14 & V_172 ) {
if ( F_37 ( V_157 , & V_2 -> V_156 ) )
F_43 ( & V_2 -> V_173 ,
V_174 + F_44 ( 100 ) ) ;
else
F_45 ( & V_2 -> V_173 ) ;
}
F_38 ( V_169 , & V_2 -> V_156 ) ;
}
static int F_46 ( struct V_11 * V_12 ,
struct V_57 * V_58 )
{
struct V_1 * V_2 = F_4 ( V_12 ) ;
struct V_67 * V_68 = & V_2 -> V_13 ;
struct V_49 * V_50 = V_58 -> V_50 ;
int V_22 ;
if ( ! V_2 -> V_42 )
V_2 -> V_42 = V_175 ;
F_47 ( V_2 ) ;
if ( V_2 -> V_176 )
F_48 ( V_2 ) ;
if ( V_68 -> V_177 )
V_2 -> V_72 |= V_77 ;
if ( V_68 -> V_14 & V_164 )
V_2 -> V_72 |= V_178 ;
if ( ( V_2 -> V_72 & V_77 ) && ( V_2 -> V_80 == 1 ) )
V_2 -> V_48 = true ;
if ( V_2 -> V_48 )
F_49 ( V_179 , V_50 -> V_180 ) ;
V_22 = F_50 ( V_50 , V_2 -> V_42 , V_2 -> V_72 ) ;
if ( V_22 )
return V_22 ;
V_2 -> V_72 = 0 ;
return 0 ;
}
static int F_51 ( struct V_11 * V_12 , struct V_57 * V_58 ,
struct V_30 * V_31 , struct V_32 * V_33 ,
unsigned long * * V_65 , int * V_66 )
{
struct V_1 * V_2 = F_4 ( V_12 ) ;
if ( ! V_2 -> V_13 . V_181 &&
V_31 -> V_70 != V_71 &&
V_31 -> V_70 != V_182 &&
V_31 -> V_70 != V_74 &&
V_31 -> V_70 != V_183 &&
V_31 -> V_70 != V_184 &&
V_31 -> V_70 != V_185 &&
V_31 -> V_70 != V_186 &&
! ( V_31 -> V_70 == V_187 &&
V_2 -> V_13 . V_14 & V_188 ) )
return - 1 ;
if ( V_31 -> V_70 == V_187 &&
V_2 -> V_13 . V_14 & V_188 &&
( V_33 -> V_34 & V_75 ) == V_189 ) {
F_33 ( V_190 , V_58 -> V_50 -> V_191 ) ;
if ( V_31 -> V_171 & V_170 )
V_31 -> V_171 &= ~ V_170 ;
switch ( V_33 -> V_34 & V_122 ) {
case 0x10 : F_52 ( V_192 ) ; break;
case 0x20 : F_52 ( V_193 ) ; break;
case 0x35 : F_52 ( V_194 ) ; break;
case 0x6b : F_52 ( V_195 ) ; break;
case 0x6c : F_52 ( V_196 ) ; break;
default:
return - 1 ;
}
return 1 ;
}
if ( V_31 -> V_197 == V_198 )
return 0 ;
else if ( ( V_31 -> V_197 == 0 ) &&
( V_31 -> V_21 -> V_27 != V_2 -> V_104 ) &&
( V_2 -> V_104 != - 1 ) )
return 0 ;
if ( V_31 -> V_70 == V_71 ||
V_31 -> V_70 == V_74 )
return F_22 ( V_12 , V_58 , V_31 , V_33 , V_65 , V_66 ) ;
return 0 ;
}
static int F_53 ( struct V_11 * V_12 , struct V_57 * V_58 ,
struct V_30 * V_31 , struct V_32 * V_33 ,
unsigned long * * V_65 , int * V_66 )
{
if ( V_31 -> V_197 == V_198 )
return 0 ;
if ( V_31 -> V_70 == V_71 ||
V_31 -> V_70 == V_74 ) {
return - 1 ;
}
return 0 ;
}
static int F_54 ( struct V_11 * V_34 , struct V_30 * V_31 ,
struct V_32 * V_33 , T_4 V_43 )
{
struct V_1 * V_2 = F_4 ( V_34 ) ;
if ( V_31 -> V_21 -> V_27 == V_2 -> V_104 )
return F_39 ( V_34 , V_31 , V_33 , V_43 ) ;
return 0 ;
}
static void F_55 ( struct V_11 * V_34 , struct V_20 * V_21 )
{
struct V_1 * V_2 = F_4 ( V_34 ) ;
struct V_30 * V_31 = V_21 -> V_31 [ 0 ] ;
if ( ! ( V_34 -> V_158 & V_162 ) )
return;
if ( V_21 -> V_27 == V_2 -> V_104 )
return F_41 ( V_34 , V_21 ) ;
if ( V_31 && V_31 -> V_161 && V_31 -> V_161 -> V_50 )
F_36 ( V_31 -> V_161 -> V_50 ) ;
}
static void F_56 ( struct V_11 * V_12 )
{
struct V_1 * V_2 = F_4 ( V_12 ) ;
struct V_20 * V_167 ;
struct V_199 * V_200 ;
struct V_67 * V_68 = & V_2 -> V_13 ;
char * V_10 ;
int V_201 ;
if ( V_2 -> V_38 < 0 )
return;
V_200 = & ( V_12 -> V_202 [ V_28 ] ) ;
V_167 = V_200 -> V_203 [ V_2 -> V_38 ] ;
if ( V_167 ) {
if ( V_68 -> V_14 & V_204 ) {
V_201 = F_8 ( V_167 ) ;
V_10 = F_9 ( V_167 , V_26 ) ;
if ( ! V_10 ) {
F_57 ( V_12 , L_7 ) ;
return;
}
F_10 ( V_12 , V_167 -> V_27 , V_10 , V_201 ,
V_28 ,
V_29 ) ;
F_13 ( V_10 ) ;
}
V_167 -> V_31 [ 0 ] -> V_43 [ V_2 -> V_39 ] = V_2 -> V_78 ;
F_58 ( V_12 , V_167 , V_205 ) ;
}
}
static void F_59 ( struct V_11 * V_12 )
{
struct V_1 * V_2 = F_4 ( V_12 ) ;
struct V_20 * V_167 ;
struct V_199 * V_200 ;
int V_206 , V_66 ;
if ( V_2 -> V_41 < 0 )
return;
if ( ! V_2 -> V_13 . V_42 )
return;
V_200 = & V_12 -> V_202 [ V_28 ] ;
V_167 = V_200 -> V_203 [ V_2 -> V_41 ] ;
if ( V_167 ) {
V_66 = V_2 -> V_13 . V_42 ;
V_206 = V_167 -> V_31 [ 0 ] -> V_44 ;
V_66 = F_31 ( V_206 , V_66 ) ;
if ( V_167 -> V_31 [ 0 ] -> V_43 [ 0 ] != V_66 ) {
V_167 -> V_31 [ 0 ] -> V_43 [ 0 ] = V_66 ;
F_58 ( V_12 , V_167 , V_205 ) ;
}
}
}
static void F_48 ( struct V_1 * V_2 )
{
T_4 V_14 = V_2 -> V_13 . V_14 ;
if ( V_2 -> V_103 == 1 ) {
V_14 |= V_129 ;
V_14 &= ~ V_164 ;
V_14 &= ~ V_163 ;
V_14 &= ~ V_165 ;
V_14 &= ~ V_19 ;
}
V_2 -> V_13 . V_14 = V_14 ;
}
static void F_47 ( struct V_1 * V_2 )
{
struct V_59 * V_60 = V_2 -> V_61 ;
struct V_67 * V_68 = & V_2 -> V_13 ;
if ( V_2 -> V_103 > 0 ) {
int V_207 = V_60 -> V_62 / V_2 -> V_103 ;
V_2 -> V_166 = V_60 -> V_64 [ V_207 - 1 ] ;
}
if ( V_2 -> V_18 < 0 )
V_68 -> V_14 &= ~ V_19 ;
}
static int F_60 ( struct V_11 * V_12 , struct V_57 * V_58 )
{
struct V_1 * V_2 = F_4 ( V_12 ) ;
char * V_95 ;
const char * V_208 = NULL ;
struct V_30 * V_31 = V_58 -> V_21 -> V_31 [ 0 ] ;
int V_22 ;
if ( V_58 -> V_21 -> V_27 == V_2 -> V_104 ) {
V_22 = F_46 ( V_12 , V_58 ) ;
if ( V_22 )
return V_22 ;
}
if ( V_58 -> V_21 -> V_31 [ 0 ] -> V_197 == V_198 ) {
V_208 = L_8 ;
F_49 ( V_209 , V_58 -> V_50 -> V_210 ) ;
} else {
switch ( V_31 -> V_70 ) {
case V_183 :
V_208 = L_9 ;
break;
case V_211 :
V_208 = L_10 ;
break;
case V_212 :
V_208 = L_11 ;
break;
case V_198 :
V_208 = L_8 ;
F_49 ( V_209 , V_58 -> V_50 -> V_210 ) ;
break;
case V_71 :
break;
case V_74 :
V_208 = L_12 ;
break;
case V_184 :
V_208 = L_13 ;
break;
case V_185 :
V_208 = L_14 ;
break;
case V_186 :
V_208 = L_15 ;
break;
case V_187 :
V_208 = L_16 ;
break;
default:
V_208 = L_17 ;
break;
}
}
if ( V_208 ) {
V_95 = F_61 ( & V_58 -> V_50 -> V_7 ,
strlen ( V_12 -> V_95 ) + strlen ( V_208 ) + 2 ,
V_26 ) ;
if ( V_95 ) {
sprintf ( V_95 , L_18 , V_12 -> V_95 , V_208 ) ;
V_58 -> V_50 -> V_95 = V_95 ;
}
}
return 0 ;
}
static void F_62 ( struct V_30 * V_31 , unsigned int V_33 )
{
if ( V_31 -> V_33 [ 0 ] . V_34 != V_33 ||
! ( V_31 -> V_171 & V_213 ) )
return;
V_31 -> V_171 &= ~ V_213 ;
V_31 -> V_171 |= V_170 ;
}
static void F_63 ( struct V_11 * V_12 , unsigned int V_33 )
{
struct V_20 * V_21 ;
int V_214 ;
F_64 (report,
&hdev->report_enum[HID_INPUT_REPORT].report_list,
list) {
if ( ! V_21 -> V_118 )
continue;
for ( V_214 = 0 ; V_214 < V_21 -> V_118 ; V_214 ++ )
if ( V_21 -> V_31 [ V_214 ] -> V_215 >= 1 )
F_62 ( V_21 -> V_31 [ V_214 ] , V_33 ) ;
}
}
static void F_65 ( struct V_11 * V_34 )
{
struct V_57 * V_161 ;
struct V_1 * V_2 = F_4 ( V_34 ) ;
F_64 (hidinput, &hid->inputs, list) {
struct V_49 * V_49 = V_161 -> V_50 ;
struct V_134 * V_135 = V_49 -> V_135 ;
int V_214 ;
if ( V_135 ) {
for ( V_214 = 0 ; V_214 < V_135 -> V_216 ; V_214 ++ ) {
V_137 ( V_49 , V_214 ) ;
F_30 ( V_49 ,
V_143 ,
false ) ;
}
F_35 ( V_49 ) ;
F_36 ( V_49 ) ;
}
}
V_2 -> V_5 = 0 ;
}
static void F_66 ( unsigned long V_217 )
{
struct V_11 * V_12 = ( void * ) V_217 ;
struct V_1 * V_2 = F_4 ( V_12 ) ;
if ( F_42 ( V_169 , & V_2 -> V_156 ) )
return;
if ( F_37 ( V_157 , & V_2 -> V_156 ) )
F_65 ( V_12 ) ;
F_38 ( V_169 , & V_2 -> V_156 ) ;
}
static int F_67 ( struct V_11 * V_12 , const struct V_218 * V_27 )
{
int V_22 , V_214 ;
struct V_1 * V_2 ;
struct V_67 * V_13 = V_219 ;
for ( V_214 = 0 ; V_219 [ V_214 ] . V_95 ; V_214 ++ ) {
if ( V_27 -> V_220 == V_219 [ V_214 ] . V_95 ) {
V_13 = & ( V_219 [ V_214 ] ) ;
break;
}
}
V_2 = F_61 ( & V_12 -> V_7 , sizeof( struct V_1 ) , V_26 ) ;
if ( ! V_2 ) {
F_15 ( & V_12 -> V_7 , L_19 ) ;
return - V_221 ;
}
V_2 -> V_13 = * V_13 ;
V_2 -> V_38 = - 1 ;
V_2 -> V_41 = - 1 ;
V_2 -> V_78 = V_222 ;
V_2 -> V_18 = - 1 ;
V_2 -> V_104 = - 1 ;
F_68 ( V_12 , V_2 ) ;
V_2 -> V_61 = F_61 ( & V_12 -> V_7 , sizeof( struct V_59 ) ,
V_26 ) ;
if ( ! V_2 -> V_61 ) {
F_15 ( & V_12 -> V_7 , L_20 ) ;
return - V_221 ;
}
if ( V_27 -> V_223 == V_224 && V_27 -> V_225 == V_224 )
V_2 -> V_176 = true ;
V_2 -> V_24 = V_12 -> V_14 ;
V_12 -> V_14 |= V_226 ;
V_12 -> V_14 |= V_227 ;
V_12 -> V_14 |= V_228 ;
V_12 -> V_14 |= V_25 ;
F_69 ( & V_2 -> V_173 , F_66 , ( long ) V_12 ) ;
V_22 = F_70 ( V_12 ) ;
if ( V_22 != 0 )
return V_22 ;
if ( V_13 -> V_14 & V_229 )
F_63 ( V_12 , V_102 ) ;
V_22 = F_71 ( V_12 , V_230 ) ;
if ( V_22 )
return V_22 ;
V_22 = F_72 ( & V_12 -> V_7 . V_231 , & V_232 ) ;
if ( V_22 )
F_11 ( & V_12 -> V_7 , L_21 ,
V_12 -> V_95 ) ;
F_59 ( V_12 ) ;
F_56 ( V_12 ) ;
F_73 ( & V_12 -> V_7 , V_2 -> V_61 ) ;
V_2 -> V_61 = NULL ;
return 0 ;
}
static int F_74 ( struct V_11 * V_12 )
{
F_65 ( V_12 ) ;
F_59 ( V_12 ) ;
F_56 ( V_12 ) ;
return 0 ;
}
static int F_75 ( struct V_11 * V_12 )
{
F_76 ( V_12 , 0 , 0 , V_233 ) ;
return 0 ;
}
static void F_77 ( struct V_11 * V_12 )
{
struct V_1 * V_2 = F_4 ( V_12 ) ;
F_78 ( & V_2 -> V_173 ) ;
F_79 ( & V_12 -> V_7 . V_231 , & V_232 ) ;
F_80 ( V_12 ) ;
V_12 -> V_14 = V_2 -> V_24 ;
}
