static struct V_1 * F_1 ( const struct V_2 * V_3 ,
const struct V_4 * V_5 )
{
struct V_1 * V_6 ;
V_6 = F_2 ( V_5 , struct V_1 , V_7 ) ;
F_3 ( V_6 == F_4 ( V_3 ) ) ;
return V_6 ;
}
static bool F_5 ( const struct V_2 * V_3 , struct V_8 * V_9 ,
struct V_10 * V_10 )
{
struct V_11 * V_12 = F_6 ( V_10 ) ;
struct V_1 * V_6 = F_4 ( V_3 ) ;
bool V_13 = true ;
switch ( V_9 -> V_14 ) {
case V_15 :
case V_16 :
if ( F_7 ( V_12 ) != V_6 -> V_17 ) {
V_9 -> V_18 = 1 ;
V_9 -> V_19 = 0 ;
V_13 = false ;
}
case V_20 :
default:
break;
}
return V_13 ;
}
static void F_8 ( struct V_21 * V_22 )
{
struct V_10 * V_10 = F_9 ( V_22 ) ;
F_10 ( V_10 ) ;
F_11 ( V_22 ) ;
}
static void F_12 ( struct V_21 * V_22 )
{
struct V_10 * V_10 = F_9 ( V_22 ) ;
F_13 ( V_22 ) ;
F_14 ( V_10 ) ;
}
static int F_15 ( const struct V_2 * V_3 , struct V_21 * V_22 ,
struct V_8 * V_9 , T_1 V_23 , T_2 V_24 ,
int * V_25 )
{
struct V_26 * V_27 = F_16 ( V_3 ) ;
struct V_10 * V_10 = F_9 ( V_22 ) ;
T_1 V_28 = V_23 + V_24 - 1 ;
T_1 V_29 ;
int V_30 ;
F_8 ( V_22 ) ;
V_30 = F_17 ( V_3 , V_22 , V_27 ) ;
if ( V_30 == 0 ) {
V_29 = V_27 -> V_31 ;
if ( V_28 > V_29 ) {
F_12 ( V_22 ) ;
V_30 = F_18 ( V_3 , V_9 , V_10 , V_22 , 0 ) ;
if ( V_30 == 0 && V_25 ) {
T_1 V_32 = F_19 ( V_10 ) ;
T_1 V_33 = V_23 >> V_34 ;
T_1 V_35 = ( V_32 - 1 ) >> V_34 ;
if ( ( V_32 == 0 && V_33 != 0 ) ||
V_35 < V_33 )
* V_25 = 1 ;
}
return V_30 ;
}
if ( F_19 ( V_10 ) < V_29 ) {
F_20 ( V_10 , V_29 ) ;
F_21 ( V_36 , V_37 L_1 ,
F_22 ( F_23 ( & V_22 -> V_38 ) ) ,
( V_39 ) F_19 ( V_10 ) ) ;
}
}
F_12 ( V_22 ) ;
return V_30 ;
}
static int F_24 ( const struct V_2 * V_3 , struct V_8 * V_9 ,
T_3 V_40 , enum V_41 V_42 ,
T_4 V_23 , T_4 V_43 )
{
struct V_1 * V_6 = F_4 ( V_3 ) ;
struct V_44 * V_45 = & V_6 -> V_46 . V_47 ;
struct V_21 * V_22 = V_9 -> V_48 ;
F_25 ( V_3 , V_22 , F_26 ( V_22 ) ) ;
F_21 ( V_36 , L_2 , V_42 , V_23 , V_43 ) ;
memset ( & V_6 -> V_46 , 0 , sizeof( V_6 -> V_46 ) ) ;
if ( V_6 -> V_49 && ( V_6 -> V_49 -> V_50 & V_51 ) ) {
V_45 -> V_52 = V_53 ;
V_45 -> V_54 = V_6 -> V_49 -> V_55 . V_56 ;
} else {
V_45 -> V_52 = V_42 ;
}
V_45 -> V_57 = V_22 ;
V_45 -> V_58 = V_23 ;
V_45 -> V_59 = V_43 ;
V_45 -> V_60 = V_40 ;
F_27 ( V_3 , V_9 , & V_6 -> V_46 ) ;
return 0 ;
}
static int F_28 ( const struct V_2 * V_3 , struct V_8 * V_9 ,
T_3 V_40 , enum V_41 V_42 ,
T_1 V_23 , T_1 V_43 )
{
struct V_21 * V_22 = V_9 -> V_48 ;
return F_24 ( V_3 , V_9 , V_40 , V_42 ,
F_29 ( V_22 , V_23 ) , F_29 ( V_22 , V_43 ) ) ;
}
static int F_30 ( const struct V_2 * V_3 ,
const struct V_4 * V_61 )
{
struct V_1 * V_6 = F_1 ( V_3 , V_61 ) ;
F_31 ( & V_6 -> V_62 . V_63 . V_64 ) ;
V_6 -> V_62 . V_63 . V_65 = 0 ;
V_6 -> V_62 . V_63 . V_66 = 0 ;
V_6 -> V_62 . V_63 . V_67 = V_68 ;
return 0 ;
}
static void F_32 ( const struct V_2 * V_3 ,
const struct V_4 * V_61 )
{
struct V_1 * V_6 = F_1 ( V_3 , V_61 ) ;
F_3 ( V_6 -> V_62 . V_63 . V_64 . V_69 == 0 ) ;
}
static int F_33 ( const struct V_2 * V_3 ,
const struct V_4 * V_61 )
{
struct V_1 * V_6 = F_1 ( V_3 , V_61 ) ;
struct V_10 * V_10 = F_9 ( V_61 -> V_70 ) ;
F_3 ( V_10 == F_34 ( V_6 -> V_49 -> V_71 ) ) ;
V_6 -> V_62 . V_72 . V_73 = V_10 -> V_74 . V_75 ;
return 0 ;
}
static void F_35 ( const struct V_2 * V_3 , const struct V_4 * V_61 )
{
struct V_8 * V_9 = V_61 -> V_76 ;
struct V_21 * V_22 = V_9 -> V_48 ;
struct V_1 * V_6 = F_1 ( V_3 , V_61 ) ;
struct V_10 * V_10 = F_9 ( V_22 ) ;
F_25 ( V_3 , V_22 , F_26 ( V_22 ) ) ;
F_21 ( V_36 , V_37
L_3 ,
F_22 ( F_23 ( & V_22 -> V_38 ) ) ,
V_9 -> V_77 , V_9 -> V_78 ,
V_6 -> V_17 , V_9 -> V_79 ) ;
if ( V_9 -> V_79 == 1 ) {
int V_13 ;
V_13 = F_36 ( V_10 , 0 , V_80 ) ;
if ( V_13 == 0 ) {
V_9 -> V_79 = 0 ;
V_9 -> V_18 = 1 ;
V_9 -> V_78 = 1 ;
} else {
V_9 -> V_79 = 1 ;
V_9 -> V_18 = 0 ;
V_9 -> V_78 = 0 ;
V_9 -> V_81 = V_13 ;
}
}
if ( ! V_9 -> V_77 && V_9 -> V_78 ) {
T_3 V_82 = 0 ;
F_37 ( V_10 , & V_82 ) ;
V_9 -> V_18 = V_6 -> V_17 != V_82 ;
if ( V_9 -> V_18 ) {
F_21 ( V_36 ,
V_37 L_4 ,
F_22 ( F_23 ( & V_22 -> V_38 ) ) ,
V_6 -> V_17 , V_82 ) ;
F_6 ( F_9 ( V_22 ) ) -> V_83 &=
~ V_84 ;
}
}
}
static void F_38 ( const struct V_2 * V_3 ,
const struct V_4 * V_61 )
{
struct V_8 * V_9 = V_61 -> V_76 ;
struct V_85 * V_86 = V_9 -> V_62 . V_87 . V_88 ;
F_25 ( V_3 , V_9 -> V_48 , F_26 ( V_9 -> V_48 ) ) ;
if ( V_86 ) {
F_39 ( & V_86 -> V_89 , L_5 , V_9 ) ;
F_40 ( V_3 , V_86 ) ;
V_9 -> V_62 . V_87 . V_88 = NULL ;
}
F_35 ( V_3 , V_61 ) ;
}
static enum V_41 F_41 ( struct V_90 * V_91 )
{
if ( ( V_91 -> V_92 & V_93 ) && ( V_91 -> V_92 & V_94 ) )
return V_95 ;
return V_96 ;
}
static int F_42 ( const struct V_2 * V_3 ,
struct V_1 * V_6 , struct V_8 * V_9 )
{
struct V_97 * V_98 = F_43 ( V_3 ) ;
struct V_99 * V_100 = V_101 -> V_100 ;
struct V_90 * V_91 ;
struct V_44 * V_45 = & V_98 -> V_102 ;
T_5 V_103 ;
unsigned long V_104 ;
T_6 V_24 ;
int V_30 = 0 ;
struct V_105 V_106 ;
struct V_107 V_108 ;
F_3 ( V_9 -> V_14 == V_15 || V_9 -> V_14 == V_16 ) ;
if ( ! V_6 -> V_109 )
return 0 ;
if ( ! V_100 )
return 0 ;
F_44 (iov, i, *vio->vui_iter) {
V_104 = ( unsigned long ) V_108 . V_110 ;
V_24 = V_108 . V_111 ;
if ( V_24 == 0 )
continue;
V_24 += V_104 & ( ~ V_112 ) ;
V_104 &= V_112 ;
F_45 ( & V_100 -> V_113 ) ;
while ( ( V_91 = F_46 ( V_100 , V_104 , V_24 ) ) != NULL ) {
struct V_10 * V_10 = F_34 ( V_91 -> V_114 ) ;
int V_115 = V_116 ;
if ( F_47 ( V_91 -> V_114 ) ) {
V_30 = - V_117 ;
break;
}
F_48 ( & V_103 , V_91 , V_104 , V_24 ) ;
V_45 -> V_52 = F_41 ( V_91 ) ;
V_45 -> V_57 = F_6 ( V_10 ) -> V_118 ;
V_45 -> V_58 = F_29 ( V_45 -> V_57 ,
V_103 . V_119 . V_23 ) ;
V_45 -> V_59 = F_29 ( V_45 -> V_57 ,
V_103 . V_119 . V_43 ) ;
V_45 -> V_60 = V_115 ;
V_30 = F_49 ( V_3 , V_9 , V_45 ) ;
F_21 ( V_36 , L_6 ,
V_45 -> V_52 , V_45 -> V_58 ,
V_45 -> V_59 ) ;
if ( V_30 < 0 )
break;
if ( V_91 -> V_120 - V_104 >= V_24 )
break;
V_24 -= V_91 -> V_120 - V_104 ;
V_104 = V_91 -> V_120 ;
}
F_50 ( & V_100 -> V_113 ) ;
if ( V_30 < 0 )
break;
}
return V_30 ;
}
static void F_51 ( const struct V_2 * V_3 ,
const struct V_4 * V_61 ,
T_2 V_121 )
{
struct V_21 * V_22 = V_61 -> V_76 -> V_48 ;
struct V_1 * V_6 = F_1 ( V_3 , V_61 ) ;
F_25 ( V_3 , V_22 , F_26 ( V_22 ) ) ;
F_52 ( V_6 -> V_109 , V_6 -> V_122 -= V_121 ) ;
}
static void F_53 ( const struct V_2 * V_3 ,
struct V_1 * V_6 , struct V_8 * V_9 )
{
T_2 V_32 = V_9 -> V_62 . V_123 . V_124 ;
if ( ! V_6 -> V_109 )
return;
F_54 ( V_6 -> V_109 , V_32 ) ;
}
static int F_55 ( const struct V_2 * V_3 , struct V_8 * V_9 ,
enum V_41 V_42 , T_1 V_23 , T_1 V_43 )
{
struct V_1 * V_6 = F_4 ( V_3 ) ;
int V_30 ;
int V_125 = 0 ;
F_3 ( V_9 -> V_14 == V_15 || V_9 -> V_14 == V_16 ) ;
F_53 ( V_3 , V_6 , V_9 ) ;
if ( V_9 -> V_62 . V_123 . V_126 )
V_125 |= V_127 ;
V_30 = F_42 ( V_3 , V_6 , V_9 ) ;
if ( V_30 == 0 )
V_30 = F_28 ( V_3 , V_9 , V_125 , V_42 , V_23 , V_43 ) ;
return V_30 ;
}
static int F_56 ( const struct V_2 * V_3 ,
const struct V_4 * V_61 )
{
struct V_8 * V_9 = V_61 -> V_76 ;
struct V_128 * V_129 = & V_9 -> V_62 . V_130 . V_129 ;
int V_30 ;
V_30 = F_55 ( V_3 , V_9 , V_96 , V_129 -> V_131 ,
V_129 -> V_131 + V_129 -> V_124 - 1 ) ;
return V_30 ;
}
static int F_57 ( const struct V_2 * V_3 ,
const struct V_4 * V_61 )
{
struct V_8 * V_9 = V_61 -> V_76 ;
struct V_1 * V_6 = F_1 ( V_3 , V_61 ) ;
return F_24 ( V_3 ,
V_9 , 0 ,
F_41 ( V_6 -> V_62 . V_72 . V_132 ) ,
V_9 -> V_62 . V_87 . V_133 ,
V_9 -> V_62 . V_87 . V_133 ) ;
}
static int F_58 ( const struct V_2 * V_3 ,
const struct V_4 * V_61 )
{
struct V_8 * V_9 = V_61 -> V_76 ;
T_1 V_23 ;
T_1 V_43 ;
if ( V_9 -> V_62 . V_134 . V_135 ) {
V_23 = 0 ;
V_43 = V_80 ;
} else {
V_23 = V_9 -> V_62 . V_134 . V_136 . V_131 ;
V_43 = V_23 + V_9 -> V_62 . V_134 . V_136 . V_124 - 1 ;
}
return F_55 ( V_3 , V_9 , V_95 , V_23 , V_43 ) ;
}
static int F_59 ( const struct V_2 * V_3 ,
const struct V_4 * V_61 )
{
return 0 ;
}
static int F_60 ( const struct V_2 * V_3 ,
const struct V_4 * V_61 )
{
struct V_8 * V_9 = V_61 -> V_76 ;
V_39 V_137 ;
T_3 V_40 = 0 ;
if ( F_61 ( V_9 ) ) {
V_137 = V_9 -> V_62 . V_138 . V_139 . V_140 ;
if ( V_137 == 0 )
V_40 = V_141 ;
} else {
if ( ( V_9 -> V_62 . V_138 . V_139 . V_142 >=
V_9 -> V_62 . V_138 . V_139 . V_143 ) ||
( V_9 -> V_62 . V_138 . V_139 . V_144 >=
V_9 -> V_62 . V_138 . V_139 . V_143 ) )
return 0 ;
V_137 = 0 ;
}
return F_28 ( V_3 , V_9 , V_40 , V_95 ,
V_137 , V_80 ) ;
}
static int F_62 ( struct V_10 * V_10 , T_2 V_32 )
{
int V_30 ;
F_10 ( V_10 ) ;
V_30 = F_63 ( V_10 , V_32 ) ;
if ( V_30 < 0 ) {
F_14 ( V_10 ) ;
return V_30 ;
}
F_64 ( V_10 , V_32 ) ;
F_14 ( V_10 ) ;
return V_30 ;
}
static int F_65 ( const struct V_2 * V_3 ,
const struct V_4 * V_61 ,
struct V_10 * V_10 , T_1 V_32 )
{
F_66 ( V_10 ) ;
return 0 ;
}
static int F_67 ( const struct V_2 * V_3 ,
const struct V_4 * V_61 )
{
struct V_8 * V_9 = V_61 -> V_76 ;
struct V_21 * V_22 = V_9 -> V_48 ;
struct V_26 * V_27 = F_16 ( V_3 ) ;
int V_30 ;
unsigned V_145 = V_146 ;
F_11 ( V_22 ) ;
V_27 -> V_147 = V_9 -> V_62 . V_138 . V_139 . V_143 ;
if ( V_9 -> V_62 . V_138 . V_148 & V_149 ) {
V_27 -> V_150 = V_9 -> V_62 . V_138 . V_139 . V_144 ;
V_145 |= V_151 ;
}
if ( V_9 -> V_62 . V_138 . V_148 & V_152 ) {
V_27 -> V_153 = V_9 -> V_62 . V_138 . V_139 . V_142 ;
V_145 |= V_154 ;
}
V_30 = F_68 ( V_3 , V_22 , V_27 , V_145 ) ;
F_13 ( V_22 ) ;
return V_30 ;
}
static int F_69 ( const struct V_2 * V_3 ,
const struct V_4 * V_61 )
{
struct V_8 * V_9 = V_61 -> V_76 ;
struct V_10 * V_10 = F_9 ( V_9 -> V_48 ) ;
int V_30 = 0 ;
F_70 ( V_10 ) ;
if ( F_61 ( V_9 ) )
V_30 = F_65 ( V_3 , V_61 , V_10 ,
V_9 -> V_62 . V_138 . V_139 . V_140 ) ;
if ( V_30 == 0 )
V_30 = F_67 ( V_3 , V_61 ) ;
return V_30 ;
}
static void F_71 ( const struct V_2 * V_3 ,
const struct V_4 * V_61 )
{
struct V_8 * V_9 = V_61 -> V_76 ;
struct V_10 * V_10 = F_9 ( V_9 -> V_48 ) ;
if ( F_61 ( V_9 ) )
F_62 ( V_10 , V_9 -> V_62 . V_138 . V_139 . V_140 ) ;
F_72 ( V_10 ) ;
}
static void F_73 ( const struct V_2 * V_3 ,
const struct V_4 * V_61 )
{
F_35 ( V_3 , V_61 ) ;
}
static int F_74 ( const struct V_2 * V_3 ,
const struct V_4 * V_61 )
{
struct V_1 * V_6 = F_1 ( V_3 , V_61 ) ;
struct V_8 * V_9 = V_61 -> V_76 ;
struct V_21 * V_22 = V_9 -> V_48 ;
struct V_10 * V_10 = F_9 ( V_22 ) ;
struct V_155 * V_155 = V_6 -> V_49 -> V_71 ;
int V_30 ;
T_1 V_28 = V_9 -> V_62 . V_130 . V_129 . V_131 ;
long V_156 = V_9 -> V_62 . V_130 . V_129 . V_124 ;
long V_157 = V_6 -> V_122 ;
int V_25 = 0 ;
F_25 ( V_3 , V_22 , F_26 ( V_22 ) ) ;
F_21 ( V_36 , L_7 , V_28 , V_28 + V_156 ) ;
if ( ! F_5 ( V_3 , V_9 , V_10 ) )
return 0 ;
V_30 = F_15 ( V_3 , V_22 , V_9 , V_28 , V_157 , & V_25 ) ;
if ( V_30 != 0 )
return V_30 ;
else if ( V_25 != 0 )
goto V_158;
F_75 ( V_159 , V_3 , & V_22 -> V_38 ,
L_8 ,
V_10 -> V_160 , V_156 , V_28 , F_19 ( V_10 ) ) ;
V_6 -> V_49 -> V_71 -> V_161 . V_162 = 0 ;
if ( ! V_6 -> V_163 ) {
V_6 -> V_163 = true ;
V_6 -> V_164 = F_29 ( V_22 , V_28 ) ;
V_6 -> V_165 = F_29 ( V_22 , V_157 + V_68 - 1 ) ;
F_76 ( V_155 ) ;
}
F_77 ( V_155 ) ;
F_3 ( V_6 -> V_166 -> V_167 == V_28 ) ;
V_30 = F_78 ( V_6 -> V_166 , V_6 -> V_109 ) ;
V_158:
if ( V_30 >= 0 ) {
if ( V_30 < V_156 )
V_9 -> V_19 = 0 ;
V_9 -> V_168 += V_30 ;
F_79 ( F_80 ( V_10 ) , V_101 -> V_169 ,
V_6 -> V_49 , V_28 , V_30 , V_170 ) ;
V_30 = 0 ;
}
return V_30 ;
}
static int F_81 ( const struct V_2 * V_3 , struct V_8 * V_9 ,
struct V_171 * V_172 , int V_173 , int V_174 )
{
struct V_175 * V_176 = & V_9 -> V_177 ;
struct V_85 * V_86 ;
unsigned int V_178 = 0 ;
int V_13 = 0 ;
if ( V_172 -> V_69 == 0 )
return 0 ;
if ( V_173 > 0 || V_174 != V_68 ) {
V_86 = F_82 ( V_172 ) ;
if ( V_172 -> V_69 == 1 ) {
F_83 ( V_3 , V_86 , V_173 , V_174 ) ;
} else {
if ( V_173 > 0 )
F_83 ( V_3 , V_86 , V_173 , V_68 ) ;
if ( V_174 != V_68 ) {
V_86 = F_84 ( V_172 ) ;
F_83 ( V_3 , V_86 , 0 , V_174 ) ;
}
}
}
F_85 ( V_176 ) ;
F_86 ( V_172 , & V_176 -> V_179 ) ;
V_13 = F_87 ( V_3 , V_9 , V_180 , V_176 , 0 ) ;
F_86 ( & V_176 -> V_179 , V_172 ) ;
F_86 ( & V_176 -> V_181 , V_172 ) ;
F_88 ( V_3 , V_176 ) ;
if ( V_13 == 0 ) {
V_178 = V_172 -> V_69 << V_34 ;
V_178 -= V_173 + V_68 - V_174 ;
while ( V_172 -> V_69 > 0 ) {
V_86 = F_82 ( V_172 ) ;
F_89 ( V_3 , V_172 , V_86 ) ;
F_83 ( V_3 , V_86 , 0 , V_68 ) ;
F_90 ( F_91 ( V_86 ) ) ;
F_92 ( V_3 , V_9 , V_86 ) ;
F_39 ( & V_86 -> V_89 , L_9 , V_9 ) ;
F_40 ( V_3 , V_86 ) ;
}
}
return V_178 > 0 ? V_178 : V_13 ;
}
static void F_93 ( const struct V_2 * V_3 , struct V_8 * V_9 ,
struct V_85 * V_86 )
{
struct V_182 * V_183 ;
struct V_86 * V_184 = V_86 -> V_185 ;
struct V_21 * V_186 = F_94 ( V_9 ) -> V_48 ;
F_90 ( V_184 ) ;
F_95 ( V_184 ) ;
V_183 = F_96 ( F_97 ( V_186 , V_86 ) ) ;
F_98 ( F_99 ( V_186 ) , V_183 ) ;
F_92 ( V_3 , V_9 , V_86 ) ;
F_39 ( & V_86 -> V_89 , L_9 , F_94 ( V_9 ) ) ;
F_40 ( V_3 , V_86 ) ;
}
static bool F_100 ( struct V_21 * V_22 ,
struct V_171 * V_172 )
{
struct V_85 * V_86 ;
T_4 V_187 = V_188 ;
F_101 (page, plist) {
struct V_182 * V_183 = F_97 ( V_22 , V_86 ) ;
if ( V_187 == V_188 ) {
V_187 = F_102 ( V_183 ) ;
continue;
}
++ V_187 ;
if ( V_187 == F_102 ( V_183 ) )
continue;
return false ;
}
return true ;
}
int F_103 ( const struct V_2 * V_3 , struct V_8 * V_9 )
{
struct V_21 * V_22 = V_9 -> V_48 ;
struct V_10 * V_10 = F_9 ( V_22 ) ;
struct V_1 * V_6 = F_4 ( V_3 ) ;
struct V_171 * V_176 = & V_6 -> V_62 . V_63 . V_64 ;
struct V_85 * V_86 ;
int V_13 = 0 ;
int V_178 = 0 ;
unsigned int V_189 = V_6 -> V_62 . V_63 . V_64 . V_69 ;
if ( V_189 == 0 )
return 0 ;
F_21 ( V_36 , L_10 ,
V_189 , V_6 -> V_62 . V_63 . V_66 , V_6 -> V_62 . V_63 . V_67 ) ;
F_3 ( F_100 ( V_22 , V_176 ) ) ;
V_13 = F_104 ( V_3 , V_9 , V_176 ,
V_6 -> V_62 . V_63 . V_66 , V_6 -> V_62 . V_63 . V_67 ,
F_93 ) ;
V_189 -= V_176 -> V_69 ;
if ( V_189 > 0 ) {
V_178 = V_189 << V_34 ;
V_178 -= V_6 -> V_62 . V_63 . V_66 ;
if ( V_176 -> V_69 == 0 )
V_178 -= V_68 - V_6 -> V_62 . V_63 . V_67 ;
F_105 ( V_178 > 0 , L_11 , V_178 , V_189 ) ;
V_6 -> V_62 . V_63 . V_65 += V_178 ;
F_21 ( V_36 , L_12 ,
V_189 , V_178 , V_6 -> V_62 . V_63 . V_65 ) ;
V_6 -> V_62 . V_63 . V_66 = 0 ;
}
F_3 ( F_100 ( V_22 , V_176 ) ) ;
F_3 ( F_106 ( V_13 == 0 , V_176 -> V_69 == 0 ) ) ;
if ( V_13 == - V_190 && ! F_107 ( V_9 ) ) {
V_13 = F_81 ( V_3 , V_9 , V_176 ,
V_6 -> V_62 . V_63 . V_66 ,
V_6 -> V_62 . V_63 . V_67 ) ;
if ( V_13 > 0 ) {
V_6 -> V_62 . V_63 . V_65 += V_13 ;
V_13 = 0 ;
}
}
F_108 ( V_3 , V_10 ) ;
while ( V_176 -> V_69 > 0 ) {
V_86 = F_82 ( V_176 ) ;
F_89 ( V_3 , V_176 , V_86 ) ;
if ( ! F_109 ( F_91 ( V_86 ) ) )
F_110 ( V_3 , V_9 , V_86 ) ;
F_92 ( V_3 , V_9 , V_86 ) ;
F_39 ( & V_86 -> V_89 , L_9 , V_9 ) ;
F_40 ( V_3 , V_86 ) ;
}
F_111 ( V_3 , V_176 ) ;
return V_13 ;
}
static int F_112 ( const struct V_2 * V_3 ,
const struct V_4 * V_61 )
{
struct V_1 * V_6 = F_1 ( V_3 , V_61 ) ;
struct V_8 * V_9 = V_61 -> V_76 ;
struct V_21 * V_22 = V_9 -> V_48 ;
struct V_10 * V_10 = F_9 ( V_22 ) ;
T_6 V_30 = 0 ;
T_1 V_28 = V_9 -> V_62 . V_134 . V_136 . V_131 ;
T_2 V_156 = V_9 -> V_62 . V_134 . V_136 . V_124 ;
if ( ! F_5 ( V_3 , V_9 , V_10 ) )
return 0 ;
if ( F_113 ( V_9 ) ) {
F_108 ( V_3 , V_10 ) ;
V_28 = F_19 ( V_10 ) ;
V_9 -> V_62 . V_134 . V_136 . V_131 = V_28 ;
V_6 -> V_166 -> V_167 = V_28 ;
} else {
F_3 ( V_6 -> V_166 -> V_167 == V_28 ) ;
}
F_21 ( V_36 , L_13 , V_28 , V_28 + ( long long ) V_156 ) ;
if ( ! V_6 -> V_109 ) {
V_30 = 0 ;
} else {
bool V_191 = ! F_114 ( V_10 ) ;
if ( V_191 )
F_70 ( V_10 ) ;
V_30 = F_115 ( V_6 -> V_166 ,
V_6 -> V_109 ) ;
if ( V_191 )
F_72 ( V_10 ) ;
if ( V_30 > 0 || V_30 == - V_192 )
V_30 = F_116 ( V_6 -> V_166 , V_30 ) ;
}
if ( V_30 > 0 ) {
V_30 = F_103 ( V_3 , V_9 ) ;
if ( V_6 -> V_62 . V_63 . V_65 > 0 ) {
V_30 = V_6 -> V_62 . V_63 . V_65 ;
V_9 -> V_168 += V_30 ;
F_21 ( V_36 , L_14 ,
V_9 -> V_168 , V_30 ) ;
}
}
if ( V_30 > 0 ) {
struct V_11 * V_12 = F_6 ( V_10 ) ;
F_117 ( & V_12 -> V_193 ) ;
V_12 -> V_83 |= V_194 ;
F_118 ( & V_12 -> V_193 ) ;
if ( V_30 < V_156 )
V_9 -> V_19 = 0 ;
F_79 ( F_80 ( V_10 ) , V_101 -> V_169 ,
V_6 -> V_49 , V_28 , V_30 , V_195 ) ;
V_30 = 0 ;
}
return V_30 ;
}
static int F_119 ( struct V_196 * V_197 )
{
struct V_198 * V_199 = V_197 -> V_200 ;
V_197 -> V_201 = F_120 ( V_197 -> V_132 , V_199 ) ;
V_197 -> V_202 = 1 ;
if ( V_199 -> V_86 ) {
F_21 ( V_203 ,
L_15 ,
V_199 -> V_86 , V_199 -> V_86 -> V_204 , V_199 -> V_86 -> V_187 ,
( long ) V_199 -> V_86 -> V_115 , F_121 ( V_199 -> V_86 ) ,
F_122 ( V_199 -> V_86 ) , V_199 -> V_205 ) ;
if ( F_123 ( ! ( V_197 -> V_201 & V_206 ) ) ) {
F_124 ( V_199 -> V_86 ) ;
V_197 -> V_201 |= V_206 ;
}
V_197 -> V_207 = V_199 -> V_86 ;
return 0 ;
}
if ( V_197 -> V_201 & ( V_208 | V_209 ) ) {
F_21 ( V_203 , L_16 , V_199 -> V_205 ) ;
return - V_210 ;
}
if ( V_197 -> V_201 & V_211 ) {
F_21 ( V_203 , L_17 , V_199 -> V_205 ) ;
return - V_212 ;
}
if ( V_197 -> V_201 & V_213 )
return - V_214 ;
F_125 ( L_18 , V_197 -> V_201 ) ;
return - V_117 ;
}
static void F_126 ( const struct V_2 * V_3 , struct V_8 * V_9 ,
struct V_85 * V_86 )
{
struct V_182 * V_183 ;
struct V_21 * V_186 = F_94 ( V_9 ) -> V_48 ;
F_95 ( V_86 -> V_185 ) ;
V_183 = F_96 ( F_97 ( V_186 , V_86 ) ) ;
F_98 ( F_99 ( V_186 ) , V_183 ) ;
}
static int F_127 ( const struct V_2 * V_3 ,
const struct V_4 * V_61 )
{
struct V_1 * V_6 = F_1 ( V_3 , V_61 ) ;
struct V_8 * V_9 = V_61 -> V_76 ;
struct V_21 * V_22 = V_9 -> V_48 ;
struct V_10 * V_10 = F_9 ( V_22 ) ;
struct V_215 * V_216 = & V_9 -> V_62 . V_87 ;
struct V_196 * V_197 = & V_6 -> V_62 . V_72 ;
T_1 V_217 ;
int V_30 = 0 ;
struct V_86 * V_184 = NULL ;
struct V_85 * V_86 ;
T_1 V_32 ;
T_4 V_218 ;
if ( V_216 -> V_219 &&
V_10 -> V_74 . V_75 != V_6 -> V_62 . V_72 . V_73 )
F_128 ( L_19 V_37
L_20 ,
F_22 ( F_23 ( & V_22 -> V_38 ) ) ) ;
V_217 = F_129 ( V_22 , V_216 -> V_133 + 1 ) - 1 ;
F_3 ( F_29 ( V_22 , V_217 ) == V_216 -> V_133 ) ;
V_30 = F_15 ( V_3 , V_22 , V_9 , 0 , V_217 + 1 , NULL ) ;
if ( V_30 != 0 )
return V_30 ;
if ( V_216 -> V_220 ) {
F_3 ( V_197 -> V_207 ) ;
F_124 ( V_197 -> V_207 ) ;
} else {
V_30 = F_119 ( V_197 ) ;
if ( V_30 != 0 )
return V_30 ;
}
V_184 = V_197 -> V_207 ;
F_3 ( F_130 ( V_184 ) ) ;
if ( F_131 ( V_221 ) )
F_132 ( V_184 ) ;
V_32 = F_19 ( V_10 ) ;
if ( F_123 ( ( V_184 -> V_204 != V_10 -> V_222 ) ||
( F_133 ( V_184 ) > V_32 ) ) ) {
F_21 ( V_203 , L_21 ) ;
V_30 = 1 ;
goto V_158;
}
V_218 = F_29 ( V_22 , V_32 - 1 ) ;
if ( V_216 -> V_220 ) {
if ( V_218 < V_216 -> V_133 ) {
F_21 ( V_203 ,
L_22 ,
V_184 -> V_204 , V_216 -> V_133 , V_218 ) ;
V_30 = - V_223 ;
goto V_158;
}
}
V_86 = F_134 ( V_3 , V_22 , V_216 -> V_133 , V_184 , V_224 ) ;
if ( F_135 ( V_86 ) ) {
V_30 = F_136 ( V_86 ) ;
goto V_158;
}
if ( V_216 -> V_220 ) {
F_137 ( V_184 ) ;
if ( ! F_109 ( V_184 ) ) {
struct V_171 * V_172 = & V_9 -> V_177 . V_179 ;
struct V_182 * V_183 = F_97 ( V_22 , V_86 ) ;
int V_174 = V_68 ;
F_138 ( V_3 , V_9 , V_86 ) ;
F_31 ( V_172 ) ;
F_139 ( V_172 , V_86 ) ;
if ( V_218 == F_102 ( V_183 ) )
V_174 = V_32 & ~ V_112 ;
V_30 = F_104 ( V_3 , V_9 , V_172 , 0 , V_174 ,
F_126 ) ;
F_3 ( F_140 ( V_86 , V_9 ) ) ;
F_111 ( V_3 , V_172 ) ;
V_184 = NULL ;
if ( V_30 < 0 ) {
F_110 ( V_3 , V_9 , V_86 ) ;
F_92 ( V_3 , V_9 , V_86 ) ;
F_40 ( V_3 , V_86 ) ;
if ( V_30 == - V_190 )
V_30 = - V_225 ;
goto V_158;
} else {
F_92 ( V_3 , V_9 , V_86 ) ;
}
}
}
F_3 ( ! V_216 -> V_220 || V_216 -> V_133 <= V_218 ) ;
if ( V_216 -> V_133 == V_218 )
V_216 -> V_226 = V_32 - F_129 ( V_22 , V_216 -> V_133 ) ;
else
V_216 -> V_226 = F_141 ( V_22 ) ;
F_142 ( & V_86 -> V_89 , L_5 , V_9 ) ;
V_216 -> V_88 = V_86 ;
V_158:
if ( V_184 )
F_143 ( V_184 ) ;
V_197 -> V_201 &= ~ V_206 ;
return V_30 ;
}
static int F_144 ( const struct V_2 * V_3 ,
const struct V_4 * V_61 )
{
return 0 ;
}
static int F_145 ( const struct V_2 * V_3 ,
const struct V_4 * V_61 ,
const struct V_227 * V_5 )
{
struct V_8 * V_9 = V_61 -> V_76 ;
struct V_182 * V_183 = F_96 ( V_5 ) ;
struct V_85 * V_86 = V_5 -> V_228 ;
struct V_10 * V_10 = F_9 ( V_5 -> V_229 ) ;
struct V_230 * V_231 = F_80 ( V_10 ) ;
struct V_232 * V_233 = F_1 ( V_3 , V_61 ) -> V_49 ;
struct V_234 * V_235 = & V_233 -> V_236 ;
struct V_175 * V_176 = & V_9 -> V_177 ;
if ( V_231 -> V_237 . V_238 &&
V_231 -> V_237 . V_239 )
F_146 ( V_231 , V_10 , V_235 , F_102 ( V_183 ) ,
V_183 -> V_240 ) ;
if ( V_183 -> V_240 ) {
V_183 -> V_241 = 1 ;
F_147 ( V_3 , V_86 , 1 ) ;
}
F_139 ( & V_176 -> V_179 , V_86 ) ;
if ( V_231 -> V_237 . V_238 &&
V_231 -> V_237 . V_239 )
F_148 ( V_3 , V_9 , & V_176 -> V_179 , V_235 ,
V_183 -> V_240 ) ;
return 0 ;
}
static void F_149 ( const struct V_2 * V_3 , const struct V_4 * V_61 )
{
F_25 ( V_3 , V_61 -> V_76 -> V_48 ,
F_26 ( V_61 -> V_76 -> V_48 ) ) ;
}
int F_150 ( const struct V_2 * V_3 , struct V_21 * V_22 ,
struct V_8 * V_9 )
{
struct V_1 * V_6 = F_4 ( V_3 ) ;
struct V_10 * V_10 = F_9 ( V_22 ) ;
int V_30 ;
F_25 ( V_3 , V_22 , F_26 ( V_22 ) ) ;
F_21 ( V_36 , V_37
L_3 ,
F_22 ( F_23 ( & V_22 -> V_38 ) ) ,
V_9 -> V_77 , V_9 -> V_78 ,
V_6 -> V_17 , V_9 -> V_79 ) ;
F_151 ( V_6 , V_7 ) ;
F_152 ( V_9 , & V_6 -> V_7 , V_22 , & V_242 ) ;
V_6 -> V_163 = false ;
V_30 = 0 ;
if ( V_9 -> V_14 == V_15 || V_9 -> V_14 == V_16 ) {
T_2 V_24 ;
struct V_11 * V_12 = F_6 ( V_10 ) ;
V_24 = V_9 -> V_62 . V_123 . V_124 ;
if ( V_24 == 0 )
V_30 = 1 ;
else
V_6 -> V_122 = V_24 ;
F_153 ( V_12 -> V_243 ) ;
} else if ( V_9 -> V_14 == V_244 ) {
if ( ! F_61 ( V_9 ) )
V_9 -> V_245 = V_246 ;
}
if ( V_9 -> V_14 == V_247 && ! V_9 -> V_78 )
V_9 -> V_77 = 1 ;
if ( V_30 == 0 && ! V_9 -> V_77 ) {
V_30 = F_37 ( V_10 , & V_6 -> V_17 ) ;
if ( V_30 == - V_248 )
V_30 = 0 ;
if ( V_30 < 0 )
F_125 ( L_23 V_37 L_24 ,
F_154 ( V_10 -> V_249 , NULL , 0 ) ,
F_22 ( F_23 ( & V_22 -> V_38 ) ) , V_30 ) ;
}
return V_30 ;
}
