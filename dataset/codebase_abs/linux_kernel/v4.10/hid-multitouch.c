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
if ( V_68 -> V_95 == V_96 &&
V_31 -> V_70 == V_74 )
V_68 -> V_14 |= V_97 ;
F_21 ( V_33 , V_2 , V_58 ) ;
return 1 ;
case V_98 :
F_23 ( V_58 , V_33 , V_65 , V_66 , V_99 , V_100 ) ;
F_24 ( V_58 -> V_50 , V_99 , V_100 ) ;
F_21 ( V_33 , V_2 , V_58 ) ;
return 1 ;
case V_101 :
F_21 ( V_33 , V_2 , V_58 ) ;
V_2 -> V_102 ++ ;
V_2 -> V_103 = V_31 -> V_21 -> V_27 ;
return 1 ;
case V_104 :
F_23 ( V_58 , V_33 , V_65 , V_66 ,
V_83 , V_105 ) ;
if ( ! ( V_68 -> V_14 & V_106 ) )
F_17 ( V_58 -> V_50 , V_105 , V_31 ,
V_68 -> V_107 ) ;
F_21 ( V_33 , V_2 , V_58 ) ;
return 1 ;
case V_108 :
F_23 ( V_58 , V_33 , V_65 , V_66 ,
V_83 , V_109 ) ;
if ( ! ( V_68 -> V_14 & V_106 ) ) {
F_17 ( V_58 -> V_50 , V_109 , V_31 ,
V_68 -> V_110 ) ;
F_18 ( V_58 -> V_50 ,
V_111 , 0 , 1 , 0 , 0 ) ;
}
F_21 ( V_33 , V_2 , V_58 ) ;
return 1 ;
case V_112 :
F_23 ( V_58 , V_33 , V_65 , V_66 ,
V_83 , V_113 ) ;
F_17 ( V_58 -> V_50 , V_113 , V_31 ,
V_68 -> V_114 ) ;
F_21 ( V_33 , V_2 , V_58 ) ;
return 1 ;
case V_115 :
if ( V_31 -> V_116 >= V_31 -> V_21 -> V_117 ||
V_33 -> V_36 >= V_31 -> V_37 )
return 1 ;
V_2 -> V_18 = V_31 -> V_116 ;
V_2 -> V_118 = V_33 -> V_36 ;
return 1 ;
case V_40 :
return - 1 ;
case V_119 :
return - 1 ;
}
return 0 ;
case V_76 :
V_51 = V_120 + ( ( V_33 -> V_34 - 1 ) & V_121 ) ;
if ( V_68 -> V_95 == V_96 &&
V_31 -> V_70 == V_74 &&
( V_33 -> V_34 & V_121 ) > 1 )
V_51 -- ;
F_23 ( V_58 , V_33 , V_65 , V_66 , V_99 , V_51 ) ;
F_24 ( V_58 -> V_50 , V_99 , V_51 ) ;
return 1 ;
case 0xff000000 :
return - 1 ;
}
return 0 ;
}
static int F_25 ( struct V_11 * V_12 , struct V_57 * V_58 ,
struct V_30 * V_31 , struct V_32 * V_33 ,
unsigned long * * V_65 , int * V_66 )
{
if ( V_33 -> type == V_99 || V_33 -> type == V_83 )
F_26 ( V_33 -> type , V_58 -> V_50 -> V_122 ) ;
return - 1 ;
}
static int F_27 ( struct V_1 * V_2 , struct V_49 * V_50 )
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
return F_28 ( V_50 , V_2 -> V_3 . V_4 ) ;
}
static void F_29 ( struct V_1 * V_2 , struct V_49 * V_50 )
{
if ( ( V_2 -> V_13 . V_14 & V_19 ) &&
V_2 -> V_5 >= V_2 -> V_127 )
return;
if ( V_2 -> V_128 || ( V_2 -> V_13 . V_14 & V_129 ) ) {
int V_130 ;
int V_131 = F_27 ( V_2 , V_50 ) ;
struct V_132 * V_133 = & V_2 -> V_3 ;
struct V_134 * V_135 = V_50 -> V_135 ;
if ( V_131 < 0 || V_131 >= V_2 -> V_42 )
return;
if ( ( V_2 -> V_13 . V_14 & V_136 ) && V_135 ) {
struct V_137 * V_138 = & V_135 -> V_139 [ V_131 ] ;
if ( F_30 ( V_138 ) &&
F_31 ( V_135 , V_138 ) )
return;
}
if ( ! ( V_2 -> V_13 . V_14 & V_97 ) )
V_133 -> V_140 = 1 ;
V_130 = ( V_133 -> V_141 || V_133 -> V_142 ) &&
V_133 -> V_140 ;
V_137 ( V_50 , V_131 ) ;
F_32 ( V_50 , V_143 , V_130 ) ;
if ( V_130 ) {
int V_144 = ( V_133 -> V_145 > V_133 -> V_146 ) ;
int V_147 = V_66 ( V_133 -> V_145 , V_133 -> V_146 ) >> 1 ;
int V_148 = F_33 ( V_133 -> V_145 , V_133 -> V_146 ) >> 1 ;
F_34 ( V_50 , V_83 , V_86 , V_133 -> V_149 ) ;
F_34 ( V_50 , V_83 , V_89 , V_133 -> V_150 ) ;
F_34 ( V_50 , V_83 , V_84 , V_133 -> V_151 ) ;
F_34 ( V_50 , V_83 , V_88 , V_133 -> V_152 ) ;
F_34 ( V_50 , V_83 , V_93 ,
! V_133 -> V_141 ) ;
F_34 ( V_50 , V_83 , V_111 , V_144 ) ;
F_34 ( V_50 , V_83 , V_113 , V_133 -> V_153 ) ;
F_34 ( V_50 , V_83 , V_105 , V_147 ) ;
F_34 ( V_50 , V_83 , V_109 , V_148 ) ;
}
}
V_2 -> V_5 ++ ;
}
static void F_35 ( struct V_1 * V_2 , struct V_49 * V_50 )
{
F_36 ( V_50 ) ;
F_37 ( V_50 ) ;
V_2 -> V_5 = 0 ;
}
static int F_38 ( struct V_11 * V_34 , struct V_30 * V_31 ,
struct V_32 * V_33 , T_4 V_43 )
{
if ( V_34 -> V_154 & V_155 && V_34 -> V_156 )
V_34 -> V_156 ( V_34 , V_31 , V_33 , V_43 ) ;
return 1 ;
}
static void F_39 ( struct V_11 * V_34 , struct V_30 * V_31 ,
struct V_32 * V_33 , T_4 V_43 )
{
struct V_1 * V_2 = F_4 ( V_34 ) ;
T_4 V_14 = V_2 -> V_13 . V_14 ;
struct V_49 * V_50 = V_31 -> V_157 -> V_50 ;
if ( V_34 -> V_154 & V_158 ) {
switch ( V_33 -> V_34 ) {
case V_91 :
if ( V_14 & V_159 )
V_2 -> V_128 = V_43 ;
if ( V_14 & V_92 )
V_2 -> V_3 . V_142 = V_43 ;
break;
case V_98 :
if ( V_14 & V_160 )
V_2 -> V_128 = V_43 ;
V_2 -> V_3 . V_141 = V_43 ;
break;
case V_94 :
if ( V_14 & V_97 )
V_2 -> V_3 . V_140 = V_43 ;
if ( V_14 & V_161 )
V_2 -> V_128 = V_43 ;
break;
case V_101 :
V_2 -> V_3 . V_4 = V_43 ;
break;
case V_112 :
V_2 -> V_3 . V_153 = V_43 ;
break;
case V_82 :
if ( V_33 -> V_51 == V_84 )
V_2 -> V_3 . V_151 = V_43 ;
else
V_2 -> V_3 . V_149 = V_43 ;
break;
case V_87 :
if ( V_33 -> V_51 == V_88 )
V_2 -> V_3 . V_152 = V_43 ;
else
V_2 -> V_3 . V_150 = V_43 ;
break;
case V_104 :
V_2 -> V_3 . V_145 = V_43 ;
break;
case V_108 :
V_2 -> V_3 . V_146 = V_43 ;
break;
case V_115 :
break;
case V_119 :
break;
default:
if ( V_33 -> type )
F_34 ( V_50 , V_33 -> type , V_33 -> V_51 ,
V_43 ) ;
return;
}
if ( V_33 -> V_36 + 1 == V_31 -> V_37 ) {
if ( V_33 -> V_34 == V_2 -> V_162 )
F_29 ( V_2 , V_31 -> V_157 -> V_50 ) ;
}
}
}
static void F_40 ( struct V_11 * V_34 , struct V_20 * V_21 )
{
struct V_1 * V_2 = F_4 ( V_34 ) ;
struct V_30 * V_31 ;
unsigned V_15 ;
int V_163 , V_164 ;
if ( V_2 -> V_18 >= 0 ) {
struct V_30 * V_31 = V_21 -> V_31 [ V_2 -> V_18 ] ;
int V_43 = V_31 -> V_43 [ V_2 -> V_118 ] ;
if ( V_43 )
V_2 -> V_127 = V_43 ;
}
for ( V_163 = 0 ; V_163 < V_21 -> V_117 ; V_163 ++ ) {
V_31 = V_21 -> V_31 [ V_163 ] ;
V_15 = V_31 -> V_37 ;
if ( ! ( V_165 & V_31 -> V_166 ) )
continue;
for ( V_164 = 0 ; V_164 < V_15 ; V_164 ++ )
F_39 ( V_34 , V_31 , & V_31 -> V_33 [ V_164 ] ,
V_31 -> V_43 [ V_164 ] ) ;
}
if ( V_2 -> V_5 >= V_2 -> V_127 )
F_35 ( V_2 , V_21 -> V_31 [ 0 ] -> V_157 -> V_50 ) ;
}
static int F_41 ( struct V_11 * V_12 ,
struct V_57 * V_58 )
{
struct V_1 * V_2 = F_4 ( V_12 ) ;
struct V_67 * V_68 = & V_2 -> V_13 ;
struct V_49 * V_50 = V_58 -> V_50 ;
int V_22 ;
if ( ! V_2 -> V_42 )
V_2 -> V_42 = V_167 ;
F_42 ( V_2 ) ;
if ( V_2 -> V_168 )
F_43 ( V_2 ) ;
if ( V_68 -> V_169 )
V_2 -> V_72 |= V_77 ;
if ( V_68 -> V_14 & V_160 )
V_2 -> V_72 |= V_170 ;
if ( ( V_2 -> V_72 & V_77 ) && ( V_2 -> V_80 == 1 ) )
V_2 -> V_48 = true ;
if ( V_2 -> V_48 )
F_44 ( V_171 , V_50 -> V_172 ) ;
V_22 = F_45 ( V_50 , V_2 -> V_42 , V_2 -> V_72 ) ;
if ( V_22 )
return V_22 ;
V_2 -> V_72 = 0 ;
return 0 ;
}
static int F_46 ( struct V_11 * V_12 , struct V_57 * V_58 ,
struct V_30 * V_31 , struct V_32 * V_33 ,
unsigned long * * V_65 , int * V_66 )
{
struct V_1 * V_2 = F_4 ( V_12 ) ;
if ( ! V_2 -> V_13 . V_173 &&
V_31 -> V_70 != V_71 &&
V_31 -> V_70 != V_174 &&
V_31 -> V_70 != V_74 &&
V_31 -> V_70 != V_175 &&
V_31 -> V_70 != V_176 )
return - 1 ;
if ( V_31 -> V_177 == V_178 )
return 0 ;
else if ( ( V_31 -> V_177 == 0 ) &&
( V_31 -> V_21 -> V_27 != V_2 -> V_103 ) &&
( V_2 -> V_103 != - 1 ) )
return 0 ;
if ( V_31 -> V_70 == V_71 ||
V_31 -> V_70 == V_74 )
return F_22 ( V_12 , V_58 , V_31 , V_33 , V_65 , V_66 ) ;
return 0 ;
}
static int F_47 ( struct V_11 * V_12 , struct V_57 * V_58 ,
struct V_30 * V_31 , struct V_32 * V_33 ,
unsigned long * * V_65 , int * V_66 )
{
if ( V_31 -> V_177 == V_178 )
return 0 ;
if ( V_31 -> V_70 == V_71 ||
V_31 -> V_70 == V_74 )
return F_25 ( V_12 , V_58 , V_31 , V_33 , V_65 , V_66 ) ;
return 0 ;
}
static int F_48 ( struct V_11 * V_34 , struct V_30 * V_31 ,
struct V_32 * V_33 , T_4 V_43 )
{
struct V_1 * V_2 = F_4 ( V_34 ) ;
if ( V_31 -> V_21 -> V_27 == V_2 -> V_103 )
return F_38 ( V_34 , V_31 , V_33 , V_43 ) ;
return 0 ;
}
static void F_49 ( struct V_11 * V_34 , struct V_20 * V_21 )
{
struct V_1 * V_2 = F_4 ( V_34 ) ;
struct V_30 * V_31 = V_21 -> V_31 [ 0 ] ;
if ( ! ( V_34 -> V_154 & V_158 ) )
return;
if ( V_21 -> V_27 == V_2 -> V_103 )
return F_40 ( V_34 , V_21 ) ;
if ( V_31 && V_31 -> V_157 && V_31 -> V_157 -> V_50 )
F_37 ( V_31 -> V_157 -> V_50 ) ;
}
static void F_50 ( struct V_11 * V_12 )
{
struct V_1 * V_2 = F_4 ( V_12 ) ;
struct V_20 * V_163 ;
struct V_179 * V_180 ;
struct V_67 * V_68 = & V_2 -> V_13 ;
char * V_10 ;
int V_181 ;
if ( V_2 -> V_38 < 0 )
return;
V_180 = & ( V_12 -> V_182 [ V_28 ] ) ;
V_163 = V_180 -> V_183 [ V_2 -> V_38 ] ;
if ( V_163 ) {
if ( V_68 -> V_14 & V_184 ) {
V_181 = F_8 ( V_163 ) ;
V_10 = F_9 ( V_163 , V_26 ) ;
if ( ! V_10 ) {
F_51 ( V_12 , L_7 ) ;
return;
}
F_10 ( V_12 , V_163 -> V_27 , V_10 , V_181 ,
V_28 ,
V_29 ) ;
F_13 ( V_10 ) ;
}
V_163 -> V_31 [ 0 ] -> V_43 [ V_2 -> V_39 ] = V_2 -> V_78 ;
F_52 ( V_12 , V_163 , V_185 ) ;
}
}
static void F_53 ( struct V_11 * V_12 )
{
struct V_1 * V_2 = F_4 ( V_12 ) ;
struct V_20 * V_163 ;
struct V_179 * V_180 ;
int V_186 , V_66 ;
if ( V_2 -> V_41 < 0 )
return;
if ( ! V_2 -> V_13 . V_42 )
return;
V_180 = & V_12 -> V_182 [ V_28 ] ;
V_163 = V_180 -> V_183 [ V_2 -> V_41 ] ;
if ( V_163 ) {
V_66 = V_2 -> V_13 . V_42 ;
V_186 = V_163 -> V_31 [ 0 ] -> V_44 ;
V_66 = F_33 ( V_186 , V_66 ) ;
if ( V_163 -> V_31 [ 0 ] -> V_43 [ 0 ] != V_66 ) {
V_163 -> V_31 [ 0 ] -> V_43 [ 0 ] = V_66 ;
F_52 ( V_12 , V_163 , V_185 ) ;
}
}
}
static void F_43 ( struct V_1 * V_2 )
{
T_4 V_14 = V_2 -> V_13 . V_14 ;
if ( V_2 -> V_102 == 1 ) {
V_14 |= V_129 ;
V_14 &= ~ V_160 ;
V_14 &= ~ V_159 ;
V_14 &= ~ V_161 ;
V_14 &= ~ V_19 ;
}
V_2 -> V_13 . V_14 = V_14 ;
}
static void F_42 ( struct V_1 * V_2 )
{
struct V_59 * V_60 = V_2 -> V_61 ;
struct V_67 * V_68 = & V_2 -> V_13 ;
if ( V_2 -> V_102 > 0 ) {
int V_187 = V_60 -> V_62 / V_2 -> V_102 ;
V_2 -> V_162 = V_60 -> V_64 [ V_187 - 1 ] ;
}
if ( V_2 -> V_18 < 0 )
V_68 -> V_14 &= ~ V_19 ;
}
static int F_54 ( struct V_11 * V_12 , struct V_57 * V_58 )
{
struct V_1 * V_2 = F_4 ( V_12 ) ;
char * V_95 ;
const char * V_188 = NULL ;
struct V_30 * V_31 = V_58 -> V_21 -> V_31 [ 0 ] ;
int V_22 ;
if ( V_58 -> V_21 -> V_27 == V_2 -> V_103 ) {
V_22 = F_41 ( V_12 , V_58 ) ;
if ( V_22 )
return V_22 ;
}
if ( V_58 -> V_21 -> V_31 [ 0 ] -> V_177 == V_178 ) {
V_188 = L_8 ;
F_44 ( V_189 , V_58 -> V_50 -> V_190 ) ;
} else {
switch ( V_31 -> V_70 ) {
case V_175 :
V_188 = L_9 ;
break;
case V_191 :
V_188 = L_10 ;
break;
case V_192 :
V_188 = L_11 ;
break;
case V_178 :
V_188 = L_8 ;
F_44 ( V_189 , V_58 -> V_50 -> V_190 ) ;
break;
case V_71 :
break;
case V_74 :
V_188 = L_12 ;
break;
case V_193 :
V_188 = L_13 ;
break;
case V_176 :
V_188 = L_14 ;
break;
default:
V_188 = L_15 ;
break;
}
}
if ( V_188 ) {
V_95 = F_55 ( & V_58 -> V_50 -> V_7 ,
strlen ( V_12 -> V_95 ) + strlen ( V_188 ) + 2 ,
V_26 ) ;
if ( V_95 ) {
sprintf ( V_95 , L_16 , V_12 -> V_95 , V_188 ) ;
V_58 -> V_50 -> V_95 = V_95 ;
}
}
return 0 ;
}
static int F_56 ( struct V_11 * V_12 , const struct V_194 * V_27 )
{
int V_22 , V_195 ;
struct V_1 * V_2 ;
struct V_67 * V_13 = V_196 ;
for ( V_195 = 0 ; V_196 [ V_195 ] . V_95 ; V_195 ++ ) {
if ( V_27 -> V_197 == V_196 [ V_195 ] . V_95 ) {
V_13 = & ( V_196 [ V_195 ] ) ;
break;
}
}
V_2 = F_55 ( & V_12 -> V_7 , sizeof( struct V_1 ) , V_26 ) ;
if ( ! V_2 ) {
F_15 ( & V_12 -> V_7 , L_17 ) ;
return - V_198 ;
}
V_2 -> V_13 = * V_13 ;
V_2 -> V_38 = - 1 ;
V_2 -> V_41 = - 1 ;
V_2 -> V_78 = V_199 ;
V_2 -> V_18 = - 1 ;
V_2 -> V_103 = - 1 ;
F_57 ( V_12 , V_2 ) ;
V_2 -> V_61 = F_55 ( & V_12 -> V_7 , sizeof( struct V_59 ) ,
V_26 ) ;
if ( ! V_2 -> V_61 ) {
F_15 ( & V_12 -> V_7 , L_18 ) ;
return - V_198 ;
}
if ( V_27 -> V_200 == V_201 && V_27 -> V_202 == V_201 )
V_2 -> V_168 = true ;
V_2 -> V_24 = V_12 -> V_14 ;
V_12 -> V_14 |= V_203 ;
V_12 -> V_14 |= V_204 ;
V_12 -> V_14 |= V_205 ;
V_12 -> V_14 |= V_25 ;
V_22 = F_58 ( V_12 ) ;
if ( V_22 != 0 )
return V_22 ;
V_22 = F_59 ( V_12 , V_206 ) ;
if ( V_22 )
return V_22 ;
V_22 = F_60 ( & V_12 -> V_7 . V_207 , & V_208 ) ;
if ( V_22 )
F_11 ( & V_12 -> V_7 , L_19 ,
V_12 -> V_95 ) ;
F_53 ( V_12 ) ;
F_50 ( V_12 ) ;
F_61 ( & V_12 -> V_7 , V_2 -> V_61 ) ;
V_2 -> V_61 = NULL ;
return 0 ;
}
static void F_62 ( struct V_11 * V_34 )
{
struct V_57 * V_157 ;
F_63 (hidinput, &hid->inputs, list) {
struct V_49 * V_49 = V_157 -> V_50 ;
struct V_134 * V_135 = V_49 -> V_135 ;
int V_195 ;
if ( V_135 ) {
for ( V_195 = 0 ; V_195 < V_135 -> V_209 ; V_195 ++ ) {
V_137 ( V_49 , V_195 ) ;
F_32 ( V_49 ,
V_143 ,
false ) ;
}
F_36 ( V_49 ) ;
F_37 ( V_49 ) ;
}
}
}
static int F_64 ( struct V_11 * V_12 )
{
F_62 ( V_12 ) ;
F_53 ( V_12 ) ;
F_50 ( V_12 ) ;
return 0 ;
}
static int F_65 ( struct V_11 * V_12 )
{
F_66 ( V_12 , 0 , 0 , V_210 ) ;
return 0 ;
}
static void F_67 ( struct V_11 * V_12 )
{
struct V_1 * V_2 = F_4 ( V_12 ) ;
F_68 ( & V_12 -> V_7 . V_207 , & V_208 ) ;
F_69 ( V_12 ) ;
V_12 -> V_14 = V_2 -> V_24 ;
}
