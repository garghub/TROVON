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
struct V_11 * V_12 = F_3 ( V_7 , struct V_11 , V_7 ) ;
struct V_1 * V_2 = F_4 ( V_12 ) ;
return sprintf ( V_10 , L_1 , V_2 -> V_13 . V_14 ) ;
}
static T_1 F_5 ( struct V_6 * V_7 ,
struct V_8 * V_9 ,
const char * V_10 , T_2 V_15 )
{
struct V_11 * V_12 = F_3 ( V_7 , struct V_11 , V_7 ) ;
struct V_1 * V_2 = F_4 ( V_12 ) ;
unsigned long V_16 ;
if ( F_6 ( V_10 , 0 , & V_16 ) )
return - V_17 ;
V_2 -> V_13 . V_14 = V_16 ;
if ( V_2 -> V_18 < 0 )
V_2 -> V_13 . V_14 &= ~ V_19 ;
return V_15 ;
}
static void F_7 ( struct V_11 * V_12 ,
struct V_20 * V_21 , struct V_22 * V_23 )
{
struct V_1 * V_2 = F_4 ( V_12 ) ;
switch ( V_23 -> V_24 ) {
case V_25 :
if ( V_23 -> V_26 >= V_21 -> V_27 ) {
F_8 ( & V_12 -> V_7 , L_2 ) ;
break;
}
V_2 -> V_28 = V_21 -> V_29 -> V_30 ;
V_2 -> V_31 = V_23 -> V_26 ;
break;
case V_32 :
V_2 -> V_33 = V_21 -> V_29 -> V_30 ;
V_2 -> V_34 = V_21 -> V_35 [ 0 ] ;
if ( ! V_2 -> V_34 &&
V_21 -> V_36 <= V_37 )
V_2 -> V_34 = V_21 -> V_36 ;
if ( V_2 -> V_13 . V_34 )
V_2 -> V_34 = V_2 -> V_13 . V_34 ;
break;
case V_38 :
if ( V_23 -> V_26 >= V_21 -> V_27 ) {
F_8 ( & V_12 -> V_7 , L_3 ) ;
break;
}
if ( V_21 -> V_35 [ V_23 -> V_26 ] == V_39 )
V_2 -> V_40 = true ;
break;
}
}
static void F_9 ( struct V_41 * V_42 , unsigned int V_43 ,
struct V_20 * V_21 , int V_44 )
{
int V_45 = V_21 -> V_46 ;
int V_47 = V_21 -> V_36 ;
int V_48 = V_44 ? ( V_47 - V_45 ) / V_44 : 0 ;
F_10 ( V_42 , V_43 , V_45 , V_47 , V_48 , 0 ) ;
F_11 ( V_42 , V_43 , F_12 ( V_21 , V_43 ) ) ;
}
static void F_13 ( struct V_22 * V_23 , struct V_1 * V_2 ,
struct V_49 * V_50 )
{
struct V_51 * V_52 = V_2 -> V_53 ;
if ( V_52 -> V_54 >= V_55 )
return;
V_52 -> V_56 [ V_52 -> V_54 ++ ] = V_23 -> V_24 ;
}
static int F_14 ( struct V_11 * V_12 , struct V_49 * V_50 ,
struct V_20 * V_21 , struct V_22 * V_23 ,
unsigned long * * V_57 , int * V_58 )
{
struct V_1 * V_2 = F_4 ( V_12 ) ;
struct V_59 * V_60 = & V_2 -> V_13 ;
int V_43 ;
struct V_22 * V_61 = NULL ;
if ( V_21 -> V_62 == V_63 )
V_2 -> V_64 |= V_65 ;
if ( V_21 -> V_62 == V_66 ||
( V_23 -> V_24 & V_67 ) == V_68 ) {
V_2 -> V_64 |= V_69 ;
V_2 -> V_70 = V_71 ;
}
if ( ( V_23 -> V_24 & V_67 ) == V_68 )
V_2 -> V_72 ++ ;
if ( V_23 -> V_26 )
V_61 = & V_21 -> V_23 [ V_23 -> V_26 - 1 ] ;
switch ( V_23 -> V_24 & V_67 ) {
case V_73 :
switch ( V_23 -> V_24 ) {
case V_74 :
if ( V_61 && ( V_61 -> V_24 == V_23 -> V_24 ) ) {
F_15 ( V_50 , V_23 , V_57 , V_58 ,
V_75 , V_76 ) ;
F_9 ( V_50 -> V_42 , V_76 , V_21 ,
V_60 -> V_77 ) ;
} else {
F_15 ( V_50 , V_23 , V_57 , V_58 ,
V_75 , V_78 ) ;
F_9 ( V_50 -> V_42 , V_78 , V_21 ,
V_60 -> V_77 ) ;
}
F_13 ( V_23 , V_2 , V_50 ) ;
return 1 ;
case V_79 :
if ( V_61 && ( V_61 -> V_24 == V_23 -> V_24 ) ) {
F_15 ( V_50 , V_23 , V_57 , V_58 ,
V_75 , V_80 ) ;
F_9 ( V_50 -> V_42 , V_80 , V_21 ,
V_60 -> V_77 ) ;
} else {
F_15 ( V_50 , V_23 , V_57 , V_58 ,
V_75 , V_81 ) ;
F_9 ( V_50 -> V_42 , V_81 , V_21 ,
V_60 -> V_77 ) ;
}
F_13 ( V_23 , V_2 , V_50 ) ;
return 1 ;
}
return 0 ;
case V_82 :
switch ( V_23 -> V_24 ) {
case V_83 :
if ( V_60 -> V_14 & V_84 ) {
F_15 ( V_50 , V_23 , V_57 , V_58 ,
V_75 , V_85 ) ;
F_10 ( V_50 -> V_42 ,
V_85 , 0 , 1 , 0 , 0 ) ;
}
F_13 ( V_23 , V_2 , V_50 ) ;
return 1 ;
case V_86 :
F_13 ( V_23 , V_2 , V_50 ) ;
return 1 ;
case V_87 :
F_15 ( V_50 , V_23 , V_57 , V_58 , V_88 , V_89 ) ;
F_16 ( V_50 -> V_42 , V_88 , V_89 ) ;
F_13 ( V_23 , V_2 , V_50 ) ;
return 1 ;
case V_90 :
F_13 ( V_23 , V_2 , V_50 ) ;
V_2 -> V_91 ++ ;
V_2 -> V_92 = V_21 -> V_29 -> V_30 ;
return 1 ;
case V_93 :
F_15 ( V_50 , V_23 , V_57 , V_58 ,
V_75 , V_94 ) ;
if ( ! ( V_60 -> V_14 & V_95 ) )
F_9 ( V_50 -> V_42 , V_94 , V_21 ,
V_60 -> V_96 ) ;
F_13 ( V_23 , V_2 , V_50 ) ;
return 1 ;
case V_97 :
F_15 ( V_50 , V_23 , V_57 , V_58 ,
V_75 , V_98 ) ;
if ( ! ( V_60 -> V_14 & V_95 ) ) {
F_9 ( V_50 -> V_42 , V_98 , V_21 ,
V_60 -> V_99 ) ;
F_10 ( V_50 -> V_42 ,
V_100 , 0 , 1 , 0 , 0 ) ;
}
F_13 ( V_23 , V_2 , V_50 ) ;
return 1 ;
case V_101 :
F_15 ( V_50 , V_23 , V_57 , V_58 ,
V_75 , V_102 ) ;
F_9 ( V_50 -> V_42 , V_102 , V_21 ,
V_60 -> V_103 ) ;
F_13 ( V_23 , V_2 , V_50 ) ;
return 1 ;
case V_104 :
if ( V_21 -> V_105 >= V_21 -> V_29 -> V_106 ||
V_23 -> V_26 >= V_21 -> V_27 )
return 1 ;
V_2 -> V_18 = V_21 -> V_105 ;
V_2 -> V_107 = V_23 -> V_26 ;
return 1 ;
case V_32 :
return - 1 ;
case V_108 :
return - 1 ;
}
return 0 ;
case V_68 :
V_43 = V_109 + ( ( V_23 -> V_24 - 1 ) & V_110 ) ;
F_15 ( V_50 , V_23 , V_57 , V_58 , V_88 , V_43 ) ;
F_16 ( V_50 -> V_42 , V_88 , V_43 ) ;
return 1 ;
case 0xff000000 :
return - 1 ;
}
return 0 ;
}
static int F_17 ( struct V_11 * V_12 , struct V_49 * V_50 ,
struct V_20 * V_21 , struct V_22 * V_23 ,
unsigned long * * V_57 , int * V_58 )
{
if ( V_23 -> type == V_88 || V_23 -> type == V_75 )
F_18 ( V_23 -> type , V_50 -> V_42 -> V_111 ) ;
return - 1 ;
}
static int F_19 ( struct V_1 * V_2 , struct V_41 * V_42 )
{
T_3 V_14 = V_2 -> V_13 . V_14 ;
if ( V_14 & V_112 )
return V_2 -> V_3 . V_4 ;
if ( V_14 & V_113 )
return F_1 ( V_2 ) ;
if ( V_14 & V_114 )
return V_2 -> V_5 ;
if ( V_14 & V_115 )
return V_2 -> V_3 . V_4 - 1 ;
return F_20 ( V_42 , V_2 -> V_3 . V_4 ) ;
}
static void F_21 ( struct V_1 * V_2 , struct V_41 * V_42 )
{
if ( ( V_2 -> V_13 . V_14 & V_19 ) &&
V_2 -> V_5 >= V_2 -> V_116 )
return;
if ( V_2 -> V_117 || ( V_2 -> V_13 . V_14 & V_118 ) ) {
int V_119 = F_19 ( V_2 , V_42 ) ;
struct V_120 * V_121 = & V_2 -> V_3 ;
struct V_122 * V_123 = V_42 -> V_123 ;
if ( V_119 < 0 || V_119 >= V_2 -> V_34 )
return;
if ( ( V_2 -> V_13 . V_14 & V_124 ) && V_123 ) {
struct V_125 * V_126 = & V_123 -> V_127 [ V_119 ] ;
if ( F_22 ( V_126 ) &&
F_23 ( V_123 , V_126 ) )
return;
}
V_125 ( V_42 , V_119 ) ;
F_24 ( V_42 , V_128 ,
V_121 -> V_129 || V_121 -> V_130 ) ;
if ( V_121 -> V_129 || V_121 -> V_130 ) {
int V_131 = ( V_121 -> V_132 > V_121 -> V_133 ) ;
int V_134 = V_58 ( V_121 -> V_132 , V_121 -> V_133 ) >> 1 ;
int V_135 = F_25 ( V_121 -> V_132 , V_121 -> V_133 ) >> 1 ;
F_26 ( V_42 , V_75 , V_78 , V_121 -> V_136 ) ;
F_26 ( V_42 , V_75 , V_81 , V_121 -> V_137 ) ;
F_26 ( V_42 , V_75 , V_76 , V_121 -> V_138 ) ;
F_26 ( V_42 , V_75 , V_80 , V_121 -> V_139 ) ;
F_26 ( V_42 , V_75 , V_85 ,
! V_121 -> V_129 ) ;
F_26 ( V_42 , V_75 , V_100 , V_131 ) ;
F_26 ( V_42 , V_75 , V_102 , V_121 -> V_140 ) ;
F_26 ( V_42 , V_75 , V_94 , V_134 ) ;
F_26 ( V_42 , V_75 , V_98 , V_135 ) ;
}
}
V_2 -> V_5 ++ ;
}
static void F_27 ( struct V_1 * V_2 , struct V_41 * V_42 )
{
F_28 ( V_42 ) ;
F_29 ( V_42 ) ;
V_2 -> V_5 = 0 ;
}
static int F_30 ( struct V_11 * V_24 , struct V_20 * V_21 ,
struct V_22 * V_23 , T_3 V_35 )
{
if ( V_24 -> V_141 & V_142 && V_24 -> V_143 )
V_24 -> V_143 ( V_24 , V_21 , V_23 , V_35 ) ;
return 1 ;
}
static void F_31 ( struct V_11 * V_24 , struct V_20 * V_21 ,
struct V_22 * V_23 , T_3 V_35 )
{
struct V_1 * V_2 = F_4 ( V_24 ) ;
T_3 V_14 = V_2 -> V_13 . V_14 ;
struct V_41 * V_42 = V_21 -> V_144 -> V_42 ;
if ( V_24 -> V_141 & V_145 ) {
switch ( V_23 -> V_24 ) {
case V_83 :
if ( V_14 & V_146 )
V_2 -> V_117 = V_35 ;
if ( V_14 & V_84 )
V_2 -> V_3 . V_130 = V_35 ;
break;
case V_87 :
if ( V_14 & V_147 )
V_2 -> V_117 = V_35 ;
V_2 -> V_3 . V_129 = V_35 ;
break;
case V_86 :
if ( V_14 & V_148 )
V_2 -> V_117 = V_35 ;
break;
case V_90 :
V_2 -> V_3 . V_4 = V_35 ;
break;
case V_101 :
V_2 -> V_3 . V_140 = V_35 ;
break;
case V_74 :
if ( V_23 -> V_43 == V_76 )
V_2 -> V_3 . V_138 = V_35 ;
else
V_2 -> V_3 . V_136 = V_35 ;
break;
case V_79 :
if ( V_23 -> V_43 == V_80 )
V_2 -> V_3 . V_139 = V_35 ;
else
V_2 -> V_3 . V_137 = V_35 ;
break;
case V_93 :
V_2 -> V_3 . V_132 = V_35 ;
break;
case V_97 :
V_2 -> V_3 . V_133 = V_35 ;
break;
case V_104 :
break;
case V_108 :
break;
default:
if ( V_23 -> type )
F_26 ( V_42 , V_23 -> type , V_23 -> V_43 ,
V_35 ) ;
return;
}
if ( V_23 -> V_26 + 1 == V_21 -> V_27 ) {
if ( V_23 -> V_24 == V_2 -> V_149 )
F_21 ( V_2 , V_21 -> V_144 -> V_42 ) ;
}
}
}
static void F_32 ( struct V_11 * V_24 , struct V_150 * V_29 )
{
struct V_1 * V_2 = F_4 ( V_24 ) ;
struct V_20 * V_21 ;
unsigned V_15 ;
int V_151 , V_152 ;
if ( V_2 -> V_18 >= 0 ) {
struct V_20 * V_21 = V_29 -> V_21 [ V_2 -> V_18 ] ;
int V_35 = V_21 -> V_35 [ V_2 -> V_107 ] ;
if ( V_35 )
V_2 -> V_116 = V_35 ;
}
for ( V_151 = 0 ; V_151 < V_29 -> V_106 ; V_151 ++ ) {
V_21 = V_29 -> V_21 [ V_151 ] ;
V_15 = V_21 -> V_27 ;
if ( ! ( V_153 & V_21 -> V_154 ) )
continue;
for ( V_152 = 0 ; V_152 < V_15 ; V_152 ++ )
F_31 ( V_24 , V_21 , & V_21 -> V_23 [ V_152 ] ,
V_21 -> V_35 [ V_152 ] ) ;
}
if ( V_2 -> V_5 >= V_2 -> V_116 )
F_27 ( V_2 , V_29 -> V_21 [ 0 ] -> V_144 -> V_42 ) ;
}
static void F_33 ( struct V_11 * V_12 ,
struct V_49 * V_50 )
{
struct V_1 * V_2 = F_4 ( V_12 ) ;
struct V_59 * V_60 = & V_2 -> V_13 ;
struct V_41 * V_42 = V_50 -> V_42 ;
if ( ! V_2 -> V_34 )
V_2 -> V_34 = V_155 ;
F_34 ( V_2 ) ;
if ( V_2 -> V_156 )
F_35 ( V_2 ) ;
if ( V_60 -> V_157 )
V_2 -> V_64 |= V_69 ;
if ( V_60 -> V_14 & V_147 )
V_2 -> V_64 |= V_158 ;
if ( ( V_2 -> V_64 & V_69 ) && ( V_2 -> V_72 == 1 ) )
V_2 -> V_40 = true ;
if ( V_2 -> V_40 )
F_36 ( V_159 , V_42 -> V_160 ) ;
F_37 ( V_42 , V_2 -> V_34 , V_2 -> V_64 ) ;
V_2 -> V_64 = 0 ;
}
static int F_38 ( struct V_11 * V_12 , struct V_49 * V_50 ,
struct V_20 * V_21 , struct V_22 * V_23 ,
unsigned long * * V_57 , int * V_58 )
{
struct V_1 * V_2 = F_4 ( V_12 ) ;
if ( ! V_2 -> V_13 . V_161 &&
V_21 -> V_62 != V_63 &&
V_21 -> V_62 != V_162 &&
V_21 -> V_62 != V_66 )
return - 1 ;
if ( V_21 -> V_163 == V_164 )
return 0 ;
if ( V_21 -> V_62 == V_63 ||
V_21 -> V_62 == V_66 )
return F_14 ( V_12 , V_50 , V_21 , V_23 , V_57 , V_58 ) ;
return 0 ;
}
static int F_39 ( struct V_11 * V_12 , struct V_49 * V_50 ,
struct V_20 * V_21 , struct V_22 * V_23 ,
unsigned long * * V_57 , int * V_58 )
{
if ( V_21 -> V_163 == V_164 )
return 0 ;
if ( V_21 -> V_62 == V_63 ||
V_21 -> V_62 == V_66 )
return F_17 ( V_12 , V_50 , V_21 , V_23 , V_57 , V_58 ) ;
return 0 ;
}
static int F_40 ( struct V_11 * V_24 , struct V_20 * V_21 ,
struct V_22 * V_23 , T_3 V_35 )
{
struct V_1 * V_2 = F_4 ( V_24 ) ;
if ( V_21 -> V_29 -> V_30 == V_2 -> V_92 )
return F_30 ( V_24 , V_21 , V_23 , V_35 ) ;
return 0 ;
}
static void F_41 ( struct V_11 * V_24 , struct V_150 * V_29 )
{
struct V_1 * V_2 = F_4 ( V_24 ) ;
struct V_20 * V_21 = V_29 -> V_21 [ 0 ] ;
if ( ! ( V_24 -> V_141 & V_145 ) )
return;
if ( V_29 -> V_30 == V_2 -> V_92 )
return F_32 ( V_24 , V_29 ) ;
if ( V_21 && V_21 -> V_144 && V_21 -> V_144 -> V_42 )
F_29 ( V_21 -> V_144 -> V_42 ) ;
}
static void F_42 ( struct V_11 * V_12 )
{
struct V_1 * V_2 = F_4 ( V_12 ) ;
struct V_150 * V_151 ;
struct V_165 * V_166 ;
struct V_59 * V_60 = & V_2 -> V_13 ;
char * V_10 ;
int V_167 ;
if ( V_2 -> V_28 < 0 )
return;
V_166 = & ( V_12 -> V_168 [ V_169 ] ) ;
V_151 = V_166 -> V_170 [ V_2 -> V_28 ] ;
if ( V_151 ) {
if ( V_60 -> V_14 & V_171 ) {
V_167 = F_43 ( V_151 ) ;
V_10 = F_44 ( V_151 , V_172 ) ;
if ( ! V_10 ) {
F_45 ( V_12 , L_4 ) ;
return;
}
F_46 ( V_12 , V_151 -> V_30 , V_10 , V_167 ,
V_169 ,
V_173 ) ;
F_47 ( V_10 ) ;
}
V_151 -> V_21 [ 0 ] -> V_35 [ V_2 -> V_31 ] = V_2 -> V_70 ;
F_48 ( V_12 , V_151 , V_174 ) ;
}
}
static void F_49 ( struct V_11 * V_12 )
{
struct V_1 * V_2 = F_4 ( V_12 ) ;
struct V_150 * V_151 ;
struct V_165 * V_166 ;
int V_175 , V_58 ;
if ( V_2 -> V_33 < 0 )
return;
if ( ! V_2 -> V_13 . V_34 )
return;
V_166 = & V_12 -> V_168 [ V_169 ] ;
V_151 = V_166 -> V_170 [ V_2 -> V_33 ] ;
if ( V_151 ) {
V_58 = V_2 -> V_13 . V_34 ;
V_175 = V_151 -> V_21 [ 0 ] -> V_36 ;
V_58 = F_25 ( V_175 , V_58 ) ;
if ( V_151 -> V_21 [ 0 ] -> V_35 [ 0 ] != V_58 ) {
V_151 -> V_21 [ 0 ] -> V_35 [ 0 ] = V_58 ;
F_48 ( V_12 , V_151 , V_174 ) ;
}
}
}
static void F_35 ( struct V_1 * V_2 )
{
T_3 V_14 = V_2 -> V_13 . V_14 ;
if ( V_2 -> V_91 == 1 ) {
V_14 |= V_118 ;
V_14 &= ~ V_147 ;
V_14 &= ~ V_146 ;
V_14 &= ~ V_148 ;
V_14 &= ~ V_19 ;
}
V_2 -> V_13 . V_14 = V_14 ;
}
static void F_34 ( struct V_1 * V_2 )
{
struct V_51 * V_52 = V_2 -> V_53 ;
struct V_59 * V_60 = & V_2 -> V_13 ;
if ( V_2 -> V_91 > 0 ) {
int V_176 = V_52 -> V_54 / V_2 -> V_91 ;
V_2 -> V_149 = V_52 -> V_56 [ V_176 - 1 ] ;
}
if ( V_2 -> V_18 < 0 )
V_60 -> V_14 &= ~ V_19 ;
}
static void F_50 ( struct V_11 * V_12 , struct V_49 * V_50 )
{
struct V_1 * V_2 = F_4 ( V_12 ) ;
char * V_177 ;
const char * V_178 = NULL ;
struct V_20 * V_21 = V_50 -> V_29 -> V_21 [ 0 ] ;
if ( V_50 -> V_29 -> V_30 == V_2 -> V_92 )
F_33 ( V_12 , V_50 ) ;
if ( V_50 -> V_29 -> V_21 [ 0 ] -> V_163 == V_164 ) {
V_178 = L_5 ;
F_36 ( V_179 , V_50 -> V_42 -> V_180 ) ;
} else {
switch ( V_21 -> V_62 ) {
case V_181 :
V_178 = L_6 ;
break;
case V_182 :
V_178 = L_7 ;
break;
case V_183 :
V_178 = L_8 ;
break;
case V_164 :
V_178 = L_5 ;
F_36 ( V_179 , V_50 -> V_42 -> V_180 ) ;
break;
case V_63 :
break;
case V_184 :
V_178 = L_9 ;
break;
case V_185 :
V_178 = L_10 ;
break;
default:
V_178 = L_11 ;
break;
}
}
if ( V_178 ) {
V_177 = F_51 ( & V_50 -> V_42 -> V_7 ,
strlen ( V_12 -> V_177 ) + strlen ( V_178 ) + 2 ,
V_172 ) ;
if ( V_177 ) {
sprintf ( V_177 , L_12 , V_12 -> V_177 , V_178 ) ;
V_50 -> V_42 -> V_177 = V_177 ;
}
}
}
static int F_52 ( struct V_11 * V_12 , const struct V_186 * V_30 )
{
int V_187 , V_188 ;
struct V_1 * V_2 ;
struct V_59 * V_13 = V_189 ;
for ( V_188 = 0 ; V_189 [ V_188 ] . V_177 ; V_188 ++ ) {
if ( V_30 -> V_190 == V_189 [ V_188 ] . V_177 ) {
V_13 = & ( V_189 [ V_188 ] ) ;
break;
}
}
V_12 -> V_14 |= V_191 ;
V_12 -> V_14 |= V_192 ;
V_12 -> V_14 |= V_193 ;
if ( V_30 -> V_194 == V_195 )
V_12 -> V_14 |= V_196 ;
V_2 = F_51 ( & V_12 -> V_7 , sizeof( struct V_1 ) , V_172 ) ;
if ( ! V_2 ) {
F_8 ( & V_12 -> V_7 , L_13 ) ;
return - V_197 ;
}
V_2 -> V_13 = * V_13 ;
V_2 -> V_28 = - 1 ;
V_2 -> V_33 = - 1 ;
V_2 -> V_70 = V_198 ;
V_2 -> V_18 = - 1 ;
V_2 -> V_92 = - 1 ;
F_53 ( V_12 , V_2 ) ;
V_2 -> V_53 = F_51 ( & V_12 -> V_7 , sizeof( struct V_51 ) ,
V_172 ) ;
if ( ! V_2 -> V_53 ) {
F_8 ( & V_12 -> V_7 , L_14 ) ;
return - V_197 ;
}
if ( V_30 -> V_199 == V_200 && V_30 -> V_201 == V_200 )
V_2 -> V_156 = true ;
V_187 = F_54 ( V_12 ) ;
if ( V_187 != 0 )
return V_187 ;
V_187 = F_55 ( V_12 , V_202 ) ;
if ( V_187 )
return V_187 ;
V_187 = F_56 ( & V_12 -> V_7 . V_203 , & V_204 ) ;
F_49 ( V_12 ) ;
F_42 ( V_12 ) ;
F_57 ( & V_12 -> V_7 , V_2 -> V_53 ) ;
V_2 -> V_53 = NULL ;
return 0 ;
}
static int F_58 ( struct V_11 * V_12 )
{
F_49 ( V_12 ) ;
F_42 ( V_12 ) ;
return 0 ;
}
static int F_59 ( struct V_11 * V_12 )
{
F_60 ( V_12 , 0 , 0 , V_205 ) ;
return 0 ;
}
static void F_61 ( struct V_11 * V_12 )
{
F_62 ( & V_12 -> V_7 . V_203 , & V_204 ) ;
F_63 ( V_12 ) ;
}
