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
static void F_7 ( struct V_11 * V_12 , struct V_20 * V_21 )
{
struct V_1 * V_2 = F_4 ( V_12 ) ;
int V_22 , V_23 = F_8 ( V_21 ) ;
T_3 * V_10 ;
if ( ! ( V_12 -> V_14 & V_24 ) )
return;
if ( V_2 -> V_13 . V_25 != V_26 )
return;
V_10 = F_9 ( V_21 , V_27 ) ;
if ( ! V_10 )
return;
V_22 = F_10 ( V_12 , V_21 -> V_28 , V_10 , V_23 ,
V_29 , V_30 ) ;
if ( V_22 < 0 ) {
F_11 ( & V_12 -> V_7 , L_2 ,
V_21 -> V_28 ) ;
} else {
V_22 = F_12 ( V_12 , V_29 , V_10 ,
V_23 , 0 ) ;
if ( V_22 )
F_11 ( & V_12 -> V_7 , L_3 ) ;
}
F_13 ( V_10 ) ;
}
static void F_14 ( struct V_11 * V_12 ,
struct V_31 * V_32 , struct V_33 * V_34 )
{
struct V_1 * V_2 = F_4 ( V_12 ) ;
switch ( V_34 -> V_35 ) {
case V_36 :
if ( V_34 -> V_37 >= V_32 -> V_38 ) {
F_15 ( & V_12 -> V_7 , L_4 ) ;
break;
}
V_2 -> V_39 = V_32 -> V_21 -> V_28 ;
V_2 -> V_40 = V_34 -> V_37 ;
break;
case V_41 :
F_7 ( V_12 , V_32 -> V_21 ) ;
V_2 -> V_42 = V_32 -> V_21 -> V_28 ;
V_2 -> V_43 = V_32 -> V_44 [ 0 ] ;
if ( ! V_2 -> V_43 &&
V_32 -> V_45 <= V_46 )
V_2 -> V_43 = V_32 -> V_45 ;
if ( V_2 -> V_13 . V_43 )
V_2 -> V_43 = V_2 -> V_13 . V_43 ;
break;
case V_47 :
if ( V_34 -> V_37 >= V_32 -> V_38 ) {
F_15 ( & V_12 -> V_7 , L_5 ) ;
break;
}
F_7 ( V_12 , V_32 -> V_21 ) ;
if ( V_32 -> V_44 [ V_34 -> V_37 ] == V_48 )
V_2 -> V_49 = true ;
break;
}
}
static void F_16 ( struct V_50 * V_51 , unsigned int V_52 ,
struct V_31 * V_32 , int V_53 )
{
int V_54 = V_32 -> V_55 ;
int V_56 = V_32 -> V_45 ;
int V_57 = V_53 ? ( V_56 - V_54 ) / V_53 : 0 ;
F_17 ( V_51 , V_52 , V_54 , V_56 , V_57 , 0 ) ;
F_18 ( V_51 , V_52 , F_19 ( V_32 , V_52 ) ) ;
}
static void F_20 ( struct V_33 * V_34 , struct V_1 * V_2 ,
struct V_58 * V_59 )
{
struct V_60 * V_61 = V_2 -> V_62 ;
if ( V_61 -> V_63 >= V_64 )
return;
V_61 -> V_65 [ V_61 -> V_63 ++ ] = V_34 -> V_35 ;
}
static int F_21 ( struct V_11 * V_12 , struct V_58 * V_59 ,
struct V_31 * V_32 , struct V_33 * V_34 ,
unsigned long * * V_66 , int * V_67 )
{
struct V_1 * V_2 = F_4 ( V_12 ) ;
struct V_68 * V_69 = & V_2 -> V_13 ;
int V_52 ;
struct V_33 * V_70 = NULL ;
if ( V_32 -> V_71 == V_72 )
V_2 -> V_73 |= V_74 ;
if ( V_32 -> V_71 == V_75 ||
( V_34 -> V_35 & V_76 ) == V_77 ) {
V_2 -> V_73 |= V_78 ;
V_2 -> V_79 = V_80 ;
}
if ( ( V_34 -> V_35 & V_76 ) == V_77 )
V_2 -> V_81 ++ ;
if ( V_34 -> V_37 )
V_70 = & V_32 -> V_34 [ V_34 -> V_37 - 1 ] ;
switch ( V_34 -> V_35 & V_76 ) {
case V_82 :
switch ( V_34 -> V_35 ) {
case V_83 :
if ( V_70 && ( V_70 -> V_35 == V_34 -> V_35 ) ) {
F_22 ( V_59 , V_34 , V_66 , V_67 ,
V_84 , V_85 ) ;
F_16 ( V_59 -> V_51 , V_85 , V_32 ,
V_69 -> V_86 ) ;
} else {
F_22 ( V_59 , V_34 , V_66 , V_67 ,
V_84 , V_87 ) ;
F_16 ( V_59 -> V_51 , V_87 , V_32 ,
V_69 -> V_86 ) ;
}
F_20 ( V_34 , V_2 , V_59 ) ;
return 1 ;
case V_88 :
if ( V_70 && ( V_70 -> V_35 == V_34 -> V_35 ) ) {
F_22 ( V_59 , V_34 , V_66 , V_67 ,
V_84 , V_89 ) ;
F_16 ( V_59 -> V_51 , V_89 , V_32 ,
V_69 -> V_86 ) ;
} else {
F_22 ( V_59 , V_34 , V_66 , V_67 ,
V_84 , V_90 ) ;
F_16 ( V_59 -> V_51 , V_90 , V_32 ,
V_69 -> V_86 ) ;
}
F_20 ( V_34 , V_2 , V_59 ) ;
return 1 ;
}
return 0 ;
case V_91 :
switch ( V_34 -> V_35 ) {
case V_92 :
if ( V_69 -> V_14 & V_93 ) {
F_22 ( V_59 , V_34 , V_66 , V_67 ,
V_84 , V_94 ) ;
F_17 ( V_59 -> V_51 ,
V_94 , 0 , 1 , 0 , 0 ) ;
}
F_20 ( V_34 , V_2 , V_59 ) ;
return 1 ;
case V_95 :
F_20 ( V_34 , V_2 , V_59 ) ;
return 1 ;
case V_96 :
F_22 ( V_59 , V_34 , V_66 , V_67 , V_97 , V_98 ) ;
F_23 ( V_59 -> V_51 , V_97 , V_98 ) ;
F_20 ( V_34 , V_2 , V_59 ) ;
return 1 ;
case V_99 :
F_20 ( V_34 , V_2 , V_59 ) ;
V_2 -> V_100 ++ ;
V_2 -> V_101 = V_32 -> V_21 -> V_28 ;
return 1 ;
case V_102 :
F_22 ( V_59 , V_34 , V_66 , V_67 ,
V_84 , V_103 ) ;
if ( ! ( V_69 -> V_14 & V_104 ) )
F_16 ( V_59 -> V_51 , V_103 , V_32 ,
V_69 -> V_105 ) ;
F_20 ( V_34 , V_2 , V_59 ) ;
return 1 ;
case V_106 :
F_22 ( V_59 , V_34 , V_66 , V_67 ,
V_84 , V_107 ) ;
if ( ! ( V_69 -> V_14 & V_104 ) ) {
F_16 ( V_59 -> V_51 , V_107 , V_32 ,
V_69 -> V_108 ) ;
F_17 ( V_59 -> V_51 ,
V_109 , 0 , 1 , 0 , 0 ) ;
}
F_20 ( V_34 , V_2 , V_59 ) ;
return 1 ;
case V_110 :
F_22 ( V_59 , V_34 , V_66 , V_67 ,
V_84 , V_111 ) ;
F_16 ( V_59 -> V_51 , V_111 , V_32 ,
V_69 -> V_112 ) ;
F_20 ( V_34 , V_2 , V_59 ) ;
return 1 ;
case V_113 :
if ( V_32 -> V_114 >= V_32 -> V_21 -> V_115 ||
V_34 -> V_37 >= V_32 -> V_38 )
return 1 ;
V_2 -> V_18 = V_32 -> V_114 ;
V_2 -> V_116 = V_34 -> V_37 ;
return 1 ;
case V_41 :
return - 1 ;
case V_117 :
return - 1 ;
}
return 0 ;
case V_77 :
V_52 = V_118 + ( ( V_34 -> V_35 - 1 ) & V_119 ) ;
F_22 ( V_59 , V_34 , V_66 , V_67 , V_97 , V_52 ) ;
F_23 ( V_59 -> V_51 , V_97 , V_52 ) ;
return 1 ;
case 0xff000000 :
return - 1 ;
}
return 0 ;
}
static int F_24 ( struct V_11 * V_12 , struct V_58 * V_59 ,
struct V_31 * V_32 , struct V_33 * V_34 ,
unsigned long * * V_66 , int * V_67 )
{
if ( V_34 -> type == V_97 || V_34 -> type == V_84 )
F_25 ( V_34 -> type , V_59 -> V_51 -> V_120 ) ;
return - 1 ;
}
static int F_26 ( struct V_1 * V_2 , struct V_50 * V_51 )
{
T_4 V_14 = V_2 -> V_13 . V_14 ;
if ( V_14 & V_121 )
return V_2 -> V_3 . V_4 ;
if ( V_14 & V_122 )
return F_1 ( V_2 ) ;
if ( V_14 & V_123 )
return V_2 -> V_5 ;
if ( V_14 & V_124 )
return V_2 -> V_3 . V_4 - 1 ;
return F_27 ( V_51 , V_2 -> V_3 . V_4 ) ;
}
static void F_28 ( struct V_1 * V_2 , struct V_50 * V_51 )
{
if ( ( V_2 -> V_13 . V_14 & V_19 ) &&
V_2 -> V_5 >= V_2 -> V_125 )
return;
if ( V_2 -> V_126 || ( V_2 -> V_13 . V_14 & V_127 ) ) {
int V_128 = F_26 ( V_2 , V_51 ) ;
struct V_129 * V_130 = & V_2 -> V_3 ;
struct V_131 * V_132 = V_51 -> V_132 ;
if ( V_128 < 0 || V_128 >= V_2 -> V_43 )
return;
if ( ( V_2 -> V_13 . V_14 & V_133 ) && V_132 ) {
struct V_134 * V_135 = & V_132 -> V_136 [ V_128 ] ;
if ( F_29 ( V_135 ) &&
F_30 ( V_132 , V_135 ) )
return;
}
V_134 ( V_51 , V_128 ) ;
F_31 ( V_51 , V_137 ,
V_130 -> V_138 || V_130 -> V_139 ) ;
if ( V_130 -> V_138 || V_130 -> V_139 ) {
int V_140 = ( V_130 -> V_141 > V_130 -> V_142 ) ;
int V_143 = V_67 ( V_130 -> V_141 , V_130 -> V_142 ) >> 1 ;
int V_144 = F_32 ( V_130 -> V_141 , V_130 -> V_142 ) >> 1 ;
F_33 ( V_51 , V_84 , V_87 , V_130 -> V_145 ) ;
F_33 ( V_51 , V_84 , V_90 , V_130 -> V_146 ) ;
F_33 ( V_51 , V_84 , V_85 , V_130 -> V_147 ) ;
F_33 ( V_51 , V_84 , V_89 , V_130 -> V_148 ) ;
F_33 ( V_51 , V_84 , V_94 ,
! V_130 -> V_138 ) ;
F_33 ( V_51 , V_84 , V_109 , V_140 ) ;
F_33 ( V_51 , V_84 , V_111 , V_130 -> V_149 ) ;
F_33 ( V_51 , V_84 , V_103 , V_143 ) ;
F_33 ( V_51 , V_84 , V_107 , V_144 ) ;
}
}
V_2 -> V_5 ++ ;
}
static void F_34 ( struct V_1 * V_2 , struct V_50 * V_51 )
{
F_35 ( V_51 ) ;
F_36 ( V_51 ) ;
V_2 -> V_5 = 0 ;
}
static int F_37 ( struct V_11 * V_35 , struct V_31 * V_32 ,
struct V_33 * V_34 , T_4 V_44 )
{
if ( V_35 -> V_150 & V_151 && V_35 -> V_152 )
V_35 -> V_152 ( V_35 , V_32 , V_34 , V_44 ) ;
return 1 ;
}
static void F_38 ( struct V_11 * V_35 , struct V_31 * V_32 ,
struct V_33 * V_34 , T_4 V_44 )
{
struct V_1 * V_2 = F_4 ( V_35 ) ;
T_4 V_14 = V_2 -> V_13 . V_14 ;
struct V_50 * V_51 = V_32 -> V_153 -> V_51 ;
if ( V_35 -> V_150 & V_154 ) {
switch ( V_34 -> V_35 ) {
case V_92 :
if ( V_14 & V_155 )
V_2 -> V_126 = V_44 ;
if ( V_14 & V_93 )
V_2 -> V_3 . V_139 = V_44 ;
break;
case V_96 :
if ( V_14 & V_156 )
V_2 -> V_126 = V_44 ;
V_2 -> V_3 . V_138 = V_44 ;
break;
case V_95 :
if ( V_14 & V_157 )
V_2 -> V_126 = V_44 ;
break;
case V_99 :
V_2 -> V_3 . V_4 = V_44 ;
break;
case V_110 :
V_2 -> V_3 . V_149 = V_44 ;
break;
case V_83 :
if ( V_34 -> V_52 == V_85 )
V_2 -> V_3 . V_147 = V_44 ;
else
V_2 -> V_3 . V_145 = V_44 ;
break;
case V_88 :
if ( V_34 -> V_52 == V_89 )
V_2 -> V_3 . V_148 = V_44 ;
else
V_2 -> V_3 . V_146 = V_44 ;
break;
case V_102 :
V_2 -> V_3 . V_141 = V_44 ;
break;
case V_106 :
V_2 -> V_3 . V_142 = V_44 ;
break;
case V_113 :
break;
case V_117 :
break;
default:
if ( V_34 -> type )
F_33 ( V_51 , V_34 -> type , V_34 -> V_52 ,
V_44 ) ;
return;
}
if ( V_34 -> V_37 + 1 == V_32 -> V_38 ) {
if ( V_34 -> V_35 == V_2 -> V_158 )
F_28 ( V_2 , V_32 -> V_153 -> V_51 ) ;
}
}
}
static void F_39 ( struct V_11 * V_35 , struct V_20 * V_21 )
{
struct V_1 * V_2 = F_4 ( V_35 ) ;
struct V_31 * V_32 ;
unsigned V_15 ;
int V_159 , V_160 ;
if ( V_2 -> V_18 >= 0 ) {
struct V_31 * V_32 = V_21 -> V_32 [ V_2 -> V_18 ] ;
int V_44 = V_32 -> V_44 [ V_2 -> V_116 ] ;
if ( V_44 )
V_2 -> V_125 = V_44 ;
}
for ( V_159 = 0 ; V_159 < V_21 -> V_115 ; V_159 ++ ) {
V_32 = V_21 -> V_32 [ V_159 ] ;
V_15 = V_32 -> V_38 ;
if ( ! ( V_161 & V_32 -> V_162 ) )
continue;
for ( V_160 = 0 ; V_160 < V_15 ; V_160 ++ )
F_38 ( V_35 , V_32 , & V_32 -> V_34 [ V_160 ] ,
V_32 -> V_44 [ V_160 ] ) ;
}
if ( V_2 -> V_5 >= V_2 -> V_125 )
F_34 ( V_2 , V_21 -> V_32 [ 0 ] -> V_153 -> V_51 ) ;
}
static int F_40 ( struct V_11 * V_12 ,
struct V_58 * V_59 )
{
struct V_1 * V_2 = F_4 ( V_12 ) ;
struct V_68 * V_69 = & V_2 -> V_13 ;
struct V_50 * V_51 = V_59 -> V_51 ;
int V_22 ;
if ( ! V_2 -> V_43 )
V_2 -> V_43 = V_163 ;
F_41 ( V_2 ) ;
if ( V_2 -> V_164 )
F_42 ( V_2 ) ;
if ( V_69 -> V_165 )
V_2 -> V_73 |= V_78 ;
if ( V_69 -> V_14 & V_156 )
V_2 -> V_73 |= V_166 ;
if ( ( V_2 -> V_73 & V_78 ) && ( V_2 -> V_81 == 1 ) )
V_2 -> V_49 = true ;
if ( V_2 -> V_49 )
F_43 ( V_167 , V_51 -> V_168 ) ;
V_22 = F_44 ( V_51 , V_2 -> V_43 , V_2 -> V_73 ) ;
if ( V_22 )
return V_22 ;
V_2 -> V_73 = 0 ;
return 0 ;
}
static int F_45 ( struct V_11 * V_12 , struct V_58 * V_59 ,
struct V_31 * V_32 , struct V_33 * V_34 ,
unsigned long * * V_66 , int * V_67 )
{
struct V_1 * V_2 = F_4 ( V_12 ) ;
if ( ! V_2 -> V_13 . V_169 &&
V_32 -> V_71 != V_72 &&
V_32 -> V_71 != V_170 &&
V_32 -> V_71 != V_75 )
return - 1 ;
if ( V_32 -> V_171 == V_172 )
return 0 ;
else if ( ( V_32 -> V_171 == 0 ) &&
( V_32 -> V_21 -> V_28 != V_2 -> V_101 ) &&
( V_2 -> V_101 != - 1 ) )
return 0 ;
if ( V_32 -> V_71 == V_72 ||
V_32 -> V_71 == V_75 )
return F_21 ( V_12 , V_59 , V_32 , V_34 , V_66 , V_67 ) ;
return 0 ;
}
static int F_46 ( struct V_11 * V_12 , struct V_58 * V_59 ,
struct V_31 * V_32 , struct V_33 * V_34 ,
unsigned long * * V_66 , int * V_67 )
{
if ( V_32 -> V_171 == V_172 )
return 0 ;
if ( V_32 -> V_71 == V_72 ||
V_32 -> V_71 == V_75 )
return F_24 ( V_12 , V_59 , V_32 , V_34 , V_66 , V_67 ) ;
return 0 ;
}
static int F_47 ( struct V_11 * V_35 , struct V_31 * V_32 ,
struct V_33 * V_34 , T_4 V_44 )
{
struct V_1 * V_2 = F_4 ( V_35 ) ;
if ( V_32 -> V_21 -> V_28 == V_2 -> V_101 )
return F_37 ( V_35 , V_32 , V_34 , V_44 ) ;
return 0 ;
}
static void F_48 ( struct V_11 * V_35 , struct V_20 * V_21 )
{
struct V_1 * V_2 = F_4 ( V_35 ) ;
struct V_31 * V_32 = V_21 -> V_32 [ 0 ] ;
if ( ! ( V_35 -> V_150 & V_154 ) )
return;
if ( V_21 -> V_28 == V_2 -> V_101 )
return F_39 ( V_35 , V_21 ) ;
if ( V_32 && V_32 -> V_153 && V_32 -> V_153 -> V_51 )
F_36 ( V_32 -> V_153 -> V_51 ) ;
}
static void F_49 ( struct V_11 * V_12 )
{
struct V_1 * V_2 = F_4 ( V_12 ) ;
struct V_20 * V_159 ;
struct V_173 * V_174 ;
struct V_68 * V_69 = & V_2 -> V_13 ;
char * V_10 ;
int V_175 ;
if ( V_2 -> V_39 < 0 )
return;
V_174 = & ( V_12 -> V_176 [ V_29 ] ) ;
V_159 = V_174 -> V_177 [ V_2 -> V_39 ] ;
if ( V_159 ) {
if ( V_69 -> V_14 & V_178 ) {
V_175 = F_8 ( V_159 ) ;
V_10 = F_9 ( V_159 , V_27 ) ;
if ( ! V_10 ) {
F_50 ( V_12 , L_6 ) ;
return;
}
F_10 ( V_12 , V_159 -> V_28 , V_10 , V_175 ,
V_29 ,
V_30 ) ;
F_13 ( V_10 ) ;
}
V_159 -> V_32 [ 0 ] -> V_44 [ V_2 -> V_40 ] = V_2 -> V_79 ;
F_51 ( V_12 , V_159 , V_179 ) ;
}
}
static void F_52 ( struct V_11 * V_12 )
{
struct V_1 * V_2 = F_4 ( V_12 ) ;
struct V_20 * V_159 ;
struct V_173 * V_174 ;
int V_180 , V_67 ;
if ( V_2 -> V_42 < 0 )
return;
if ( ! V_2 -> V_13 . V_43 )
return;
V_174 = & V_12 -> V_176 [ V_29 ] ;
V_159 = V_174 -> V_177 [ V_2 -> V_42 ] ;
if ( V_159 ) {
V_67 = V_2 -> V_13 . V_43 ;
V_180 = V_159 -> V_32 [ 0 ] -> V_45 ;
V_67 = F_32 ( V_180 , V_67 ) ;
if ( V_159 -> V_32 [ 0 ] -> V_44 [ 0 ] != V_67 ) {
V_159 -> V_32 [ 0 ] -> V_44 [ 0 ] = V_67 ;
F_51 ( V_12 , V_159 , V_179 ) ;
}
}
}
static void F_42 ( struct V_1 * V_2 )
{
T_4 V_14 = V_2 -> V_13 . V_14 ;
if ( V_2 -> V_100 == 1 ) {
V_14 |= V_127 ;
V_14 &= ~ V_156 ;
V_14 &= ~ V_155 ;
V_14 &= ~ V_157 ;
V_14 &= ~ V_19 ;
}
V_2 -> V_13 . V_14 = V_14 ;
}
static void F_41 ( struct V_1 * V_2 )
{
struct V_60 * V_61 = V_2 -> V_62 ;
struct V_68 * V_69 = & V_2 -> V_13 ;
if ( V_2 -> V_100 > 0 ) {
int V_181 = V_61 -> V_63 / V_2 -> V_100 ;
V_2 -> V_158 = V_61 -> V_65 [ V_181 - 1 ] ;
}
if ( V_2 -> V_18 < 0 )
V_69 -> V_14 &= ~ V_19 ;
}
static int F_53 ( struct V_11 * V_12 , struct V_58 * V_59 )
{
struct V_1 * V_2 = F_4 ( V_12 ) ;
char * V_25 ;
const char * V_182 = NULL ;
struct V_31 * V_32 = V_59 -> V_21 -> V_32 [ 0 ] ;
int V_22 ;
if ( V_59 -> V_21 -> V_28 == V_2 -> V_101 ) {
V_22 = F_40 ( V_12 , V_59 ) ;
if ( V_22 )
return V_22 ;
}
if ( V_59 -> V_21 -> V_32 [ 0 ] -> V_171 == V_172 ) {
V_182 = L_7 ;
F_43 ( V_183 , V_59 -> V_51 -> V_184 ) ;
} else {
switch ( V_32 -> V_71 ) {
case V_185 :
V_182 = L_8 ;
break;
case V_186 :
V_182 = L_9 ;
break;
case V_187 :
V_182 = L_10 ;
break;
case V_172 :
V_182 = L_7 ;
F_43 ( V_183 , V_59 -> V_51 -> V_184 ) ;
break;
case V_72 :
break;
case V_75 :
V_182 = L_11 ;
break;
case V_188 :
V_182 = L_12 ;
break;
case V_189 :
V_182 = L_13 ;
break;
default:
V_182 = L_14 ;
break;
}
}
if ( V_182 ) {
V_25 = F_54 ( & V_59 -> V_51 -> V_7 ,
strlen ( V_12 -> V_25 ) + strlen ( V_182 ) + 2 ,
V_27 ) ;
if ( V_25 ) {
sprintf ( V_25 , L_15 , V_12 -> V_25 , V_182 ) ;
V_59 -> V_51 -> V_25 = V_25 ;
}
}
return 0 ;
}
static int F_55 ( struct V_11 * V_12 , const struct V_190 * V_28 )
{
int V_22 , V_191 ;
struct V_1 * V_2 ;
struct V_68 * V_13 = V_192 ;
for ( V_191 = 0 ; V_192 [ V_191 ] . V_25 ; V_191 ++ ) {
if ( V_28 -> V_193 == V_192 [ V_191 ] . V_25 ) {
V_13 = & ( V_192 [ V_191 ] ) ;
break;
}
}
V_12 -> V_14 |= V_194 ;
V_12 -> V_14 |= V_195 ;
V_12 -> V_14 |= V_196 ;
if ( V_28 -> V_197 == V_198 )
V_12 -> V_14 |= V_24 ;
V_2 = F_54 ( & V_12 -> V_7 , sizeof( struct V_1 ) , V_27 ) ;
if ( ! V_2 ) {
F_15 ( & V_12 -> V_7 , L_16 ) ;
return - V_199 ;
}
V_2 -> V_13 = * V_13 ;
V_2 -> V_39 = - 1 ;
V_2 -> V_42 = - 1 ;
V_2 -> V_79 = V_200 ;
V_2 -> V_18 = - 1 ;
V_2 -> V_101 = - 1 ;
F_56 ( V_12 , V_2 ) ;
V_2 -> V_62 = F_54 ( & V_12 -> V_7 , sizeof( struct V_60 ) ,
V_27 ) ;
if ( ! V_2 -> V_62 ) {
F_15 ( & V_12 -> V_7 , L_17 ) ;
return - V_199 ;
}
if ( V_28 -> V_201 == V_202 && V_28 -> V_203 == V_202 )
V_2 -> V_164 = true ;
V_22 = F_57 ( V_12 ) ;
if ( V_22 != 0 )
return V_22 ;
V_22 = F_58 ( V_12 , V_204 ) ;
if ( V_22 )
return V_22 ;
V_22 = F_59 ( & V_12 -> V_7 . V_205 , & V_206 ) ;
F_52 ( V_12 ) ;
F_49 ( V_12 ) ;
F_60 ( & V_12 -> V_7 , V_2 -> V_62 ) ;
V_2 -> V_62 = NULL ;
return 0 ;
}
static int F_61 ( struct V_11 * V_12 )
{
F_52 ( V_12 ) ;
F_49 ( V_12 ) ;
return 0 ;
}
static int F_62 ( struct V_11 * V_12 )
{
F_63 ( V_12 , 0 , 0 , V_207 ) ;
return 0 ;
}
static void F_64 ( struct V_11 * V_12 )
{
F_65 ( & V_12 -> V_7 . V_205 , & V_206 ) ;
F_66 ( V_12 ) ;
}
