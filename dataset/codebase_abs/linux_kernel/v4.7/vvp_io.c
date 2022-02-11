struct V_1 * F_1 ( const struct V_2 * V_3 ,
const struct V_4 * V_5 )
{
struct V_1 * V_6 ;
V_6 = F_2 ( V_5 , struct V_1 , V_7 ) ;
F_3 ( V_6 == F_4 ( V_3 ) ) ;
return V_6 ;
}
static int F_5 ( const struct V_2 * V_3 , const struct V_8 * V_9 )
{
struct V_1 * V_6 = F_4 ( V_3 ) ;
F_3 ( V_9 -> V_10 == V_11 || V_9 -> V_10 == V_12 ) ;
return V_6 -> V_13 == V_14 ;
}
static bool F_6 ( const struct V_2 * V_3 , struct V_8 * V_9 ,
struct V_15 * V_15 )
{
struct V_16 * V_17 = F_7 ( V_15 ) ;
struct V_1 * V_6 = F_4 ( V_3 ) ;
bool V_18 = true ;
switch ( V_9 -> V_10 ) {
case V_11 :
case V_12 :
if ( F_8 ( V_17 ) != V_6 -> V_19 ) {
V_9 -> V_20 = 1 ;
V_9 -> V_21 = 0 ;
V_18 = false ;
}
case V_22 :
default:
break;
}
return V_18 ;
}
static void F_9 ( struct V_23 * V_24 )
{
struct V_15 * V_15 = F_10 ( V_24 ) ;
F_11 ( V_15 ) ;
F_12 ( V_24 ) ;
}
static void F_13 ( struct V_23 * V_24 )
{
struct V_15 * V_15 = F_10 ( V_24 ) ;
F_14 ( V_24 ) ;
F_15 ( V_15 ) ;
}
static int F_16 ( const struct V_2 * V_3 , struct V_23 * V_24 ,
struct V_8 * V_9 , T_1 V_25 , T_2 V_26 ,
int * V_27 )
{
struct V_28 * V_29 = F_17 ( V_3 ) ;
struct V_15 * V_15 = F_10 ( V_24 ) ;
T_1 V_30 = V_25 + V_26 - 1 ;
T_1 V_31 ;
int V_32 ;
F_9 ( V_24 ) ;
V_32 = F_18 ( V_3 , V_24 , V_29 ) ;
if ( V_32 == 0 ) {
V_31 = V_29 -> V_33 ;
if ( V_30 > V_31 ) {
F_13 ( V_24 ) ;
V_32 = F_19 ( V_3 , V_9 , V_15 , V_24 , 0 ) ;
if ( V_32 == 0 && V_27 ) {
T_1 V_34 = F_20 ( V_15 ) ;
T_1 V_35 = V_25 >> V_36 ;
T_1 V_37 = ( V_34 - 1 ) >> V_36 ;
if ( ( V_34 == 0 && V_35 != 0 ) ||
V_37 < V_35 )
* V_27 = 1 ;
}
return V_32 ;
}
if ( F_20 ( V_15 ) < V_31 ) {
F_21 ( V_15 , V_31 ) ;
F_22 ( V_38 , V_39 L_1 ,
F_23 ( F_24 ( & V_24 -> V_40 ) ) ,
( V_41 ) F_20 ( V_15 ) ) ;
}
}
F_13 ( V_24 ) ;
return V_32 ;
}
static int F_25 ( const struct V_2 * V_3 , struct V_8 * V_9 ,
T_3 V_42 , enum V_43 V_44 ,
T_4 V_25 , T_4 V_45 )
{
struct V_1 * V_6 = F_4 ( V_3 ) ;
struct V_46 * V_47 = & V_6 -> V_48 . V_49 ;
struct V_23 * V_24 = V_9 -> V_50 ;
F_26 ( V_3 , V_24 , F_27 ( V_24 ) ) ;
F_22 ( V_38 , L_2 , V_44 , V_25 , V_45 ) ;
memset ( & V_6 -> V_48 , 0 , sizeof( V_6 -> V_48 ) ) ;
if ( V_6 -> V_51 && ( V_6 -> V_51 -> V_52 & V_53 ) ) {
V_47 -> V_54 = V_55 ;
V_47 -> V_56 = V_6 -> V_51 -> V_57 . V_58 ;
} else {
V_47 -> V_54 = V_44 ;
}
V_47 -> V_59 = V_24 ;
V_47 -> V_60 = V_25 ;
V_47 -> V_61 = V_45 ;
V_47 -> V_62 = V_42 ;
F_28 ( V_3 , V_9 , & V_6 -> V_48 ) ;
return 0 ;
}
static int F_29 ( const struct V_2 * V_3 , struct V_8 * V_9 ,
T_3 V_42 , enum V_43 V_44 ,
T_1 V_25 , T_1 V_45 )
{
struct V_23 * V_24 = V_9 -> V_50 ;
return F_25 ( V_3 , V_9 , V_42 , V_44 ,
F_30 ( V_24 , V_25 ) , F_30 ( V_24 , V_45 ) ) ;
}
static int F_31 ( const struct V_2 * V_3 ,
const struct V_4 * V_63 )
{
struct V_1 * V_6 = F_1 ( V_3 , V_63 ) ;
F_32 ( & V_6 -> V_64 . V_65 . V_66 ) ;
V_6 -> V_64 . V_65 . V_67 = 0 ;
V_6 -> V_64 . V_65 . V_68 = 0 ;
V_6 -> V_64 . V_65 . V_69 = V_70 ;
return 0 ;
}
static void F_33 ( const struct V_2 * V_3 ,
const struct V_4 * V_63 )
{
struct V_1 * V_6 = F_1 ( V_3 , V_63 ) ;
F_3 ( V_6 -> V_64 . V_65 . V_66 . V_71 == 0 ) ;
}
static int F_34 ( const struct V_2 * V_3 ,
const struct V_4 * V_63 )
{
struct V_1 * V_6 = F_1 ( V_3 , V_63 ) ;
struct V_15 * V_15 = F_10 ( V_63 -> V_72 ) ;
F_3 ( V_15 == F_35 ( V_6 -> V_51 -> V_73 ) ) ;
V_6 -> V_64 . V_74 . V_75 = V_15 -> V_76 . V_77 ;
return 0 ;
}
static void F_36 ( const struct V_2 * V_3 , const struct V_4 * V_63 )
{
struct V_8 * V_9 = V_63 -> V_78 ;
struct V_23 * V_24 = V_9 -> V_50 ;
struct V_1 * V_6 = F_1 ( V_3 , V_63 ) ;
struct V_15 * V_15 = F_10 ( V_24 ) ;
F_26 ( V_3 , V_24 , F_27 ( V_24 ) ) ;
F_22 ( V_38 , V_39
L_3 ,
F_23 ( F_24 ( & V_24 -> V_40 ) ) ,
V_9 -> V_79 , V_9 -> V_80 ,
V_6 -> V_19 , V_9 -> V_81 ) ;
if ( V_9 -> V_81 == 1 ) {
int V_18 ;
V_18 = F_37 ( V_15 , 0 , V_82 ) ;
if ( V_18 == 0 ) {
V_9 -> V_81 = 0 ;
V_9 -> V_20 = 1 ;
V_9 -> V_80 = 1 ;
} else {
V_9 -> V_81 = 1 ;
V_9 -> V_20 = 0 ;
V_9 -> V_80 = 0 ;
V_9 -> V_83 = V_18 ;
}
}
if ( ! V_9 -> V_79 && V_9 -> V_80 ) {
T_3 V_84 = 0 ;
F_38 ( V_15 , & V_84 ) ;
V_9 -> V_20 = V_6 -> V_19 != V_84 ;
if ( V_9 -> V_20 ) {
F_22 ( V_38 ,
V_39 L_4 ,
F_23 ( F_24 ( & V_24 -> V_40 ) ) ,
V_6 -> V_19 , V_84 ) ;
F_7 ( F_10 ( V_24 ) ) -> V_85 &=
~ V_86 ;
}
}
}
static void F_39 ( const struct V_2 * V_3 ,
const struct V_4 * V_63 )
{
struct V_8 * V_9 = V_63 -> V_78 ;
struct V_87 * V_88 = V_9 -> V_64 . V_89 . V_90 ;
F_26 ( V_3 , V_9 -> V_50 , F_27 ( V_9 -> V_50 ) ) ;
if ( V_88 ) {
F_40 ( & V_88 -> V_91 , L_5 , V_9 ) ;
F_41 ( V_3 , V_88 ) ;
V_9 -> V_64 . V_89 . V_90 = NULL ;
}
F_36 ( V_3 , V_63 ) ;
}
static enum V_43 F_42 ( struct V_92 * V_93 )
{
if ( ( V_93 -> V_94 & V_95 ) && ( V_93 -> V_94 & V_96 ) )
return V_97 ;
return V_98 ;
}
static int F_43 ( const struct V_2 * V_3 ,
struct V_1 * V_6 , struct V_8 * V_9 )
{
struct V_99 * V_100 = F_44 ( V_3 ) ;
struct V_101 * V_102 = V_103 -> V_102 ;
struct V_92 * V_93 ;
struct V_46 * V_47 = & V_100 -> V_104 ;
T_5 V_105 ;
unsigned long V_106 ;
T_6 V_26 ;
int V_32 = 0 ;
struct V_107 V_108 ;
struct V_109 V_110 ;
F_3 ( V_9 -> V_10 == V_11 || V_9 -> V_10 == V_12 ) ;
if ( ! F_5 ( V_3 , V_9 ) )
return 0 ;
if ( ! V_6 -> V_111 )
return 0 ;
if ( ! V_102 )
return 0 ;
F_45 (iov, i, *vio->vui_iter) {
V_106 = ( unsigned long ) V_110 . V_112 ;
V_26 = V_110 . V_113 ;
if ( V_26 == 0 )
continue;
V_26 += V_106 & ( ~ V_114 ) ;
V_106 &= V_114 ;
F_46 ( & V_102 -> V_115 ) ;
while ( ( V_93 = F_47 ( V_102 , V_106 , V_26 ) ) != NULL ) {
struct V_15 * V_15 = F_35 ( V_93 -> V_116 ) ;
int V_117 = V_118 ;
if ( F_48 ( V_93 -> V_116 ) ) {
V_32 = - V_119 ;
break;
}
F_49 ( & V_105 , V_93 , V_106 , V_26 ) ;
V_47 -> V_54 = F_42 ( V_93 ) ;
V_47 -> V_59 = F_7 ( V_15 ) -> V_120 ;
V_47 -> V_60 = F_30 ( V_47 -> V_59 ,
V_105 . V_121 . V_25 ) ;
V_47 -> V_61 = F_30 ( V_47 -> V_59 ,
V_105 . V_121 . V_45 ) ;
V_47 -> V_62 = V_117 ;
V_32 = F_50 ( V_3 , V_9 , V_47 ) ;
F_22 ( V_38 , L_6 ,
V_47 -> V_54 , V_47 -> V_60 ,
V_47 -> V_61 ) ;
if ( V_32 < 0 )
break;
if ( V_93 -> V_122 - V_106 >= V_26 )
break;
V_26 -= V_93 -> V_122 - V_106 ;
V_106 = V_93 -> V_122 ;
}
F_51 ( & V_102 -> V_115 ) ;
if ( V_32 < 0 )
break;
}
return V_32 ;
}
static void F_52 ( const struct V_2 * V_3 ,
const struct V_4 * V_63 ,
T_2 V_123 )
{
struct V_1 * V_6 = F_1 ( V_3 , V_63 ) ;
struct V_8 * V_9 = V_63 -> V_78 ;
struct V_23 * V_24 = V_63 -> V_78 -> V_50 ;
F_26 ( V_3 , V_24 , F_27 ( V_24 ) ) ;
if ( ! F_5 ( V_3 , V_9 ) )
return;
F_53 ( V_6 -> V_111 , V_6 -> V_124 -= V_123 ) ;
}
static void F_54 ( const struct V_2 * V_3 ,
struct V_1 * V_6 , struct V_8 * V_9 )
{
T_2 V_34 = V_9 -> V_64 . V_125 . V_126 ;
if ( ! F_5 ( V_3 , V_9 ) || ! V_6 -> V_111 )
return;
F_55 ( V_6 -> V_111 , V_34 ) ;
}
static int F_56 ( const struct V_2 * V_3 , struct V_8 * V_9 ,
enum V_43 V_44 , T_1 V_25 , T_1 V_45 )
{
struct V_1 * V_6 = F_4 ( V_3 ) ;
int V_32 ;
int V_127 = 0 ;
F_3 ( V_9 -> V_10 == V_11 || V_9 -> V_10 == V_12 ) ;
F_54 ( V_3 , V_6 , V_9 ) ;
if ( V_9 -> V_64 . V_125 . V_128 )
V_127 |= V_129 ;
V_32 = F_43 ( V_3 , V_6 , V_9 ) ;
if ( V_32 == 0 )
V_32 = F_29 ( V_3 , V_9 , V_127 , V_44 , V_25 , V_45 ) ;
return V_32 ;
}
static int F_57 ( const struct V_2 * V_3 ,
const struct V_4 * V_63 )
{
struct V_8 * V_9 = V_63 -> V_78 ;
struct V_130 * V_131 = & V_9 -> V_64 . V_132 . V_131 ;
int V_32 ;
V_32 = F_56 ( V_3 , V_9 , V_98 , V_131 -> V_133 ,
V_131 -> V_133 + V_131 -> V_126 - 1 ) ;
return V_32 ;
}
static int F_58 ( const struct V_2 * V_3 ,
const struct V_4 * V_63 )
{
struct V_8 * V_9 = V_63 -> V_78 ;
struct V_1 * V_6 = F_1 ( V_3 , V_63 ) ;
return F_25 ( V_3 ,
V_9 , 0 ,
F_42 ( V_6 -> V_64 . V_74 . V_134 ) ,
V_9 -> V_64 . V_89 . V_135 ,
V_9 -> V_64 . V_89 . V_135 ) ;
}
static int F_59 ( const struct V_2 * V_3 ,
const struct V_4 * V_63 )
{
struct V_8 * V_9 = V_63 -> V_78 ;
T_1 V_25 ;
T_1 V_45 ;
if ( V_9 -> V_64 . V_136 . V_137 ) {
V_25 = 0 ;
V_45 = V_82 ;
} else {
V_25 = V_9 -> V_64 . V_136 . V_138 . V_133 ;
V_45 = V_25 + V_9 -> V_64 . V_136 . V_138 . V_126 - 1 ;
}
return F_56 ( V_3 , V_9 , V_97 , V_25 , V_45 ) ;
}
static int F_60 ( const struct V_2 * V_3 ,
const struct V_4 * V_63 )
{
return 0 ;
}
static int F_61 ( const struct V_2 * V_3 ,
const struct V_4 * V_63 )
{
struct V_8 * V_9 = V_63 -> V_78 ;
V_41 V_139 ;
T_3 V_42 = 0 ;
if ( F_62 ( V_9 ) ) {
V_139 = V_9 -> V_64 . V_140 . V_141 . V_142 ;
if ( V_139 == 0 )
V_42 = V_143 ;
} else {
if ( ( V_9 -> V_64 . V_140 . V_141 . V_144 >=
V_9 -> V_64 . V_140 . V_141 . V_145 ) ||
( V_9 -> V_64 . V_140 . V_141 . V_146 >=
V_9 -> V_64 . V_140 . V_141 . V_145 ) )
return 0 ;
V_139 = 0 ;
}
return F_29 ( V_3 , V_9 , V_42 , V_97 ,
V_139 , V_82 ) ;
}
static int F_63 ( struct V_15 * V_15 , T_2 V_34 )
{
int V_32 ;
F_11 ( V_15 ) ;
V_32 = F_64 ( V_15 , V_34 ) ;
if ( V_32 < 0 ) {
F_15 ( V_15 ) ;
return V_32 ;
}
F_65 ( V_15 , V_34 ) ;
F_15 ( V_15 ) ;
return V_32 ;
}
static int F_66 ( const struct V_2 * V_3 ,
const struct V_4 * V_63 ,
struct V_15 * V_15 , T_1 V_34 )
{
F_67 ( V_15 ) ;
return 0 ;
}
static int F_68 ( const struct V_2 * V_3 ,
const struct V_4 * V_63 )
{
struct V_8 * V_9 = V_63 -> V_78 ;
struct V_23 * V_24 = V_9 -> V_50 ;
struct V_28 * V_29 = F_17 ( V_3 ) ;
int V_32 ;
unsigned V_147 = V_148 ;
F_12 ( V_24 ) ;
V_29 -> V_149 = V_9 -> V_64 . V_140 . V_141 . V_145 ;
if ( V_9 -> V_64 . V_140 . V_150 & V_151 ) {
V_29 -> V_152 = V_9 -> V_64 . V_140 . V_141 . V_146 ;
V_147 |= V_153 ;
}
if ( V_9 -> V_64 . V_140 . V_150 & V_154 ) {
V_29 -> V_155 = V_9 -> V_64 . V_140 . V_141 . V_144 ;
V_147 |= V_156 ;
}
V_32 = F_69 ( V_3 , V_24 , V_29 , V_147 ) ;
F_14 ( V_24 ) ;
return V_32 ;
}
static int F_70 ( const struct V_2 * V_3 ,
const struct V_4 * V_63 )
{
struct V_8 * V_9 = V_63 -> V_78 ;
struct V_15 * V_15 = F_10 ( V_9 -> V_50 ) ;
int V_32 = 0 ;
F_71 ( V_15 ) ;
if ( F_62 ( V_9 ) )
V_32 = F_66 ( V_3 , V_63 , V_15 ,
V_9 -> V_64 . V_140 . V_141 . V_142 ) ;
if ( V_32 == 0 )
V_32 = F_68 ( V_3 , V_63 ) ;
return V_32 ;
}
static void F_72 ( const struct V_2 * V_3 ,
const struct V_4 * V_63 )
{
struct V_8 * V_9 = V_63 -> V_78 ;
struct V_15 * V_15 = F_10 ( V_9 -> V_50 ) ;
if ( F_62 ( V_9 ) )
F_63 ( V_15 , V_9 -> V_64 . V_140 . V_141 . V_142 ) ;
F_73 ( V_15 ) ;
}
static void F_74 ( const struct V_2 * V_3 ,
const struct V_4 * V_63 )
{
F_36 ( V_3 , V_63 ) ;
}
static int F_75 ( const struct V_2 * V_3 ,
const struct V_4 * V_63 )
{
struct V_1 * V_6 = F_1 ( V_3 , V_63 ) ;
struct V_8 * V_9 = V_63 -> V_78 ;
struct V_23 * V_24 = V_9 -> V_50 ;
struct V_15 * V_15 = F_10 ( V_24 ) ;
struct V_157 * V_157 = V_6 -> V_51 -> V_73 ;
int V_32 ;
T_1 V_30 = V_9 -> V_64 . V_132 . V_131 . V_133 ;
long V_158 = V_9 -> V_64 . V_132 . V_131 . V_126 ;
long V_159 = V_6 -> V_124 ;
int V_27 = 0 ;
F_26 ( V_3 , V_24 , F_27 ( V_24 ) ) ;
F_22 ( V_38 , L_7 , V_30 , V_30 + V_158 ) ;
if ( ! F_6 ( V_3 , V_9 , V_15 ) )
return 0 ;
V_32 = F_16 ( V_3 , V_24 , V_9 , V_30 , V_159 , & V_27 ) ;
if ( V_32 != 0 )
return V_32 ;
else if ( V_27 != 0 )
goto V_160;
F_76 ( V_161 , V_3 , & V_24 -> V_40 ,
L_8 ,
V_15 -> V_162 , V_158 , V_30 , F_20 ( V_15 ) ) ;
V_6 -> V_51 -> V_73 -> V_163 . V_164 = 0 ;
if ( ! V_6 -> V_165 ) {
V_6 -> V_165 = true ;
V_6 -> V_166 = F_30 ( V_24 , V_30 ) ;
V_6 -> V_167 = F_30 ( V_24 , V_159 + V_70 - 1 ) ;
F_77 ( V_157 ) ;
}
F_78 ( V_157 ) ;
switch ( V_6 -> V_13 ) {
case V_14 :
F_3 ( V_6 -> V_168 -> V_169 == V_30 ) ;
V_32 = F_79 ( V_6 -> V_168 , V_6 -> V_111 ) ;
break;
case V_170 :
V_32 = F_80 ( V_157 , & V_30 ,
V_6 -> V_64 . V_171 . V_172 , V_158 ,
V_6 -> V_64 . V_171 . V_173 ) ;
V_9 -> V_21 = 0 ;
break;
default:
F_81 ( L_9 , V_6 -> V_13 ) ;
F_82 () ;
}
V_160:
if ( V_32 >= 0 ) {
if ( V_32 < V_158 )
V_9 -> V_21 = 0 ;
V_9 -> V_174 += V_32 ;
F_83 ( F_84 ( V_15 ) , V_103 -> V_175 ,
V_6 -> V_51 , V_30 , V_32 , V_176 ) ;
V_32 = 0 ;
}
return V_32 ;
}
static int F_85 ( const struct V_2 * V_3 , struct V_8 * V_9 ,
struct V_177 * V_178 , int V_179 , int V_180 )
{
struct V_181 * V_182 = & V_9 -> V_183 ;
struct V_87 * V_88 ;
unsigned int V_184 = 0 ;
int V_18 = 0 ;
if ( V_178 -> V_71 == 0 )
return 0 ;
if ( V_179 > 0 || V_180 != V_70 ) {
V_88 = F_86 ( V_178 ) ;
if ( V_178 -> V_71 == 1 ) {
F_87 ( V_3 , V_88 , V_179 , V_180 ) ;
} else {
if ( V_179 > 0 )
F_87 ( V_3 , V_88 , V_179 , V_70 ) ;
if ( V_180 != V_70 ) {
V_88 = F_88 ( V_178 ) ;
F_87 ( V_3 , V_88 , 0 , V_180 ) ;
}
}
}
F_89 ( V_182 ) ;
F_90 ( V_178 , & V_182 -> V_185 ) ;
V_18 = F_91 ( V_3 , V_9 , V_186 , V_182 , 0 ) ;
F_90 ( & V_182 -> V_185 , V_178 ) ;
F_90 ( & V_182 -> V_187 , V_178 ) ;
F_92 ( V_3 , V_182 ) ;
if ( V_18 == 0 ) {
V_184 = V_178 -> V_71 << V_36 ;
V_184 -= V_179 + V_70 - V_180 ;
while ( V_178 -> V_71 > 0 ) {
V_88 = F_86 ( V_178 ) ;
F_93 ( V_3 , V_178 , V_88 ) ;
F_87 ( V_3 , V_88 , 0 , V_70 ) ;
F_94 ( F_95 ( V_88 ) ) ;
F_96 ( V_3 , V_9 , V_88 ) ;
F_40 ( & V_88 -> V_91 , L_10 , V_9 ) ;
F_41 ( V_3 , V_88 ) ;
}
}
return V_184 > 0 ? V_184 : V_18 ;
}
static void F_97 ( const struct V_2 * V_3 , struct V_8 * V_9 ,
struct V_87 * V_88 )
{
struct V_188 * V_189 ;
struct V_88 * V_190 = V_88 -> V_191 ;
struct V_23 * V_192 = F_98 ( V_9 ) -> V_50 ;
F_94 ( V_190 ) ;
F_99 ( V_190 ) ;
V_189 = F_100 ( F_101 ( V_192 , V_88 ) ) ;
F_102 ( F_103 ( V_192 ) , V_189 ) ;
F_96 ( V_3 , V_9 , V_88 ) ;
F_40 ( & V_88 -> V_91 , L_10 , V_9 ) ;
F_41 ( V_3 , V_88 ) ;
}
static bool F_104 ( struct V_23 * V_24 ,
struct V_177 * V_178 )
{
struct V_87 * V_88 ;
T_4 V_193 = V_194 ;
F_105 (page, plist) {
struct V_188 * V_189 = F_101 ( V_24 , V_88 ) ;
if ( V_193 == V_194 ) {
V_193 = F_106 ( V_189 ) ;
continue;
}
++ V_193 ;
if ( V_193 == F_106 ( V_189 ) )
continue;
return false ;
}
return true ;
}
int F_107 ( const struct V_2 * V_3 , struct V_8 * V_9 )
{
struct V_23 * V_24 = V_9 -> V_50 ;
struct V_15 * V_15 = F_10 ( V_24 ) ;
struct V_1 * V_6 = F_4 ( V_3 ) ;
struct V_177 * V_182 = & V_6 -> V_64 . V_65 . V_66 ;
struct V_87 * V_88 ;
int V_18 = 0 ;
int V_184 = 0 ;
unsigned int V_195 = V_6 -> V_64 . V_65 . V_66 . V_71 ;
if ( V_195 == 0 )
return 0 ;
F_22 ( V_38 , L_11 ,
V_195 , V_6 -> V_64 . V_65 . V_68 , V_6 -> V_64 . V_65 . V_69 ) ;
F_3 ( F_104 ( V_24 , V_182 ) ) ;
V_18 = F_108 ( V_3 , V_9 , V_182 ,
V_6 -> V_64 . V_65 . V_68 , V_6 -> V_64 . V_65 . V_69 ,
F_97 ) ;
V_195 -= V_182 -> V_71 ;
if ( V_195 > 0 ) {
V_184 = V_195 << V_36 ;
V_184 -= V_6 -> V_64 . V_65 . V_68 ;
if ( V_182 -> V_71 == 0 )
V_184 -= V_70 - V_6 -> V_64 . V_65 . V_69 ;
F_109 ( V_184 > 0 , L_12 , V_184 , V_195 ) ;
V_6 -> V_64 . V_65 . V_67 += V_184 ;
F_22 ( V_38 , L_13 ,
V_195 , V_184 , V_6 -> V_64 . V_65 . V_67 ) ;
V_6 -> V_64 . V_65 . V_68 = 0 ;
}
F_3 ( F_104 ( V_24 , V_182 ) ) ;
F_3 ( F_110 ( V_18 == 0 , V_182 -> V_71 == 0 ) ) ;
if ( V_18 == - V_196 && ! F_111 ( V_9 ) ) {
V_18 = F_85 ( V_3 , V_9 , V_182 ,
V_6 -> V_64 . V_65 . V_68 ,
V_6 -> V_64 . V_65 . V_69 ) ;
if ( V_18 > 0 ) {
V_6 -> V_64 . V_65 . V_67 += V_18 ;
V_18 = 0 ;
}
}
F_112 ( V_3 , V_15 ) ;
while ( V_182 -> V_71 > 0 ) {
V_88 = F_86 ( V_182 ) ;
F_93 ( V_3 , V_182 , V_88 ) ;
if ( ! F_113 ( F_95 ( V_88 ) ) )
F_114 ( V_3 , V_9 , V_88 ) ;
F_96 ( V_3 , V_9 , V_88 ) ;
F_40 ( & V_88 -> V_91 , L_10 , V_9 ) ;
F_41 ( V_3 , V_88 ) ;
}
F_115 ( V_3 , V_182 ) ;
return V_18 ;
}
static int F_116 ( const struct V_2 * V_3 ,
const struct V_4 * V_63 )
{
struct V_1 * V_6 = F_1 ( V_3 , V_63 ) ;
struct V_8 * V_9 = V_63 -> V_78 ;
struct V_23 * V_24 = V_9 -> V_50 ;
struct V_15 * V_15 = F_10 ( V_24 ) ;
T_6 V_32 = 0 ;
T_1 V_30 = V_9 -> V_64 . V_136 . V_138 . V_133 ;
T_2 V_158 = V_9 -> V_64 . V_136 . V_138 . V_126 ;
if ( ! F_6 ( V_3 , V_9 , V_15 ) )
return 0 ;
if ( F_117 ( V_9 ) ) {
F_112 ( V_3 , V_15 ) ;
V_30 = V_9 -> V_64 . V_136 . V_138 . V_133 = F_20 ( V_15 ) ;
V_6 -> V_168 -> V_169 = V_30 ;
} else {
F_3 ( V_6 -> V_168 -> V_169 == V_30 ) ;
}
F_22 ( V_38 , L_14 , V_30 , V_30 + ( long long ) V_158 ) ;
if ( ! V_6 -> V_111 )
V_32 = 0 ;
else
V_32 = F_118 ( V_6 -> V_168 , V_6 -> V_111 ) ;
if ( V_32 > 0 ) {
V_32 = F_107 ( V_3 , V_9 ) ;
if ( V_6 -> V_64 . V_65 . V_67 > 0 ) {
V_32 = V_6 -> V_64 . V_65 . V_67 ;
V_9 -> V_174 += V_32 ;
F_22 ( V_38 , L_15 ,
V_9 -> V_174 , V_32 ) ;
}
}
if ( V_32 > 0 ) {
struct V_16 * V_17 = F_7 ( V_15 ) ;
F_119 ( & V_17 -> V_197 ) ;
V_17 -> V_85 |= V_198 ;
F_120 ( & V_17 -> V_197 ) ;
if ( V_32 < V_158 )
V_9 -> V_21 = 0 ;
F_83 ( F_84 ( V_15 ) , V_103 -> V_175 ,
V_6 -> V_51 , V_30 , V_32 , V_199 ) ;
V_32 = 0 ;
}
return V_32 ;
}
static int F_121 ( struct V_200 * V_201 )
{
struct V_202 * V_203 = V_201 -> V_204 ;
V_201 -> V_205 = F_122 ( V_201 -> V_134 , V_203 ) ;
V_201 -> V_206 = 1 ;
if ( V_203 -> V_88 ) {
F_22 ( V_207 ,
L_16 ,
V_203 -> V_88 , V_203 -> V_88 -> V_208 , V_203 -> V_88 -> V_193 ,
( long ) V_203 -> V_88 -> V_117 , F_123 ( V_203 -> V_88 ) ,
F_124 ( V_203 -> V_88 ) , V_203 -> V_209 ) ;
if ( F_125 ( ! ( V_201 -> V_205 & V_210 ) ) ) {
F_126 ( V_203 -> V_88 ) ;
V_201 -> V_205 |= V_210 ;
}
V_201 -> V_211 = V_203 -> V_88 ;
return 0 ;
}
if ( V_201 -> V_205 & ( V_212 | V_213 ) ) {
F_22 ( V_207 , L_17 , V_203 -> V_209 ) ;
return - V_214 ;
}
if ( V_201 -> V_205 & V_215 ) {
F_22 ( V_207 , L_18 , V_203 -> V_209 ) ;
return - V_216 ;
}
if ( V_201 -> V_205 & V_217 )
return - V_218 ;
F_81 ( L_19 , V_201 -> V_205 ) ;
return - V_119 ;
}
static void F_127 ( const struct V_2 * V_3 , struct V_8 * V_9 ,
struct V_87 * V_88 )
{
struct V_188 * V_189 ;
struct V_23 * V_192 = F_98 ( V_9 ) -> V_50 ;
F_99 ( V_88 -> V_191 ) ;
V_189 = F_100 ( F_101 ( V_192 , V_88 ) ) ;
F_102 ( F_103 ( V_192 ) , V_189 ) ;
}
static int F_128 ( const struct V_2 * V_3 ,
const struct V_4 * V_63 )
{
struct V_1 * V_6 = F_1 ( V_3 , V_63 ) ;
struct V_8 * V_9 = V_63 -> V_78 ;
struct V_23 * V_24 = V_9 -> V_50 ;
struct V_15 * V_15 = F_10 ( V_24 ) ;
struct V_219 * V_220 = & V_9 -> V_64 . V_89 ;
struct V_200 * V_201 = & V_6 -> V_64 . V_74 ;
T_1 V_221 ;
int V_32 = 0 ;
struct V_88 * V_190 = NULL ;
struct V_87 * V_88 ;
T_1 V_34 ;
T_4 V_222 ;
if ( V_220 -> V_223 &&
V_15 -> V_76 . V_77 != V_6 -> V_64 . V_74 . V_75 )
F_129 ( L_20 V_39
L_21 ,
F_23 ( F_24 ( & V_24 -> V_40 ) ) ) ;
V_221 = F_130 ( V_24 , V_220 -> V_135 + 1 ) - 1 ;
F_3 ( F_30 ( V_24 , V_221 ) == V_220 -> V_135 ) ;
V_32 = F_16 ( V_3 , V_24 , V_9 , 0 , V_221 + 1 , NULL ) ;
if ( V_32 != 0 )
return V_32 ;
if ( V_220 -> V_224 ) {
F_3 ( V_201 -> V_211 ) ;
F_126 ( V_201 -> V_211 ) ;
} else {
V_32 = F_121 ( V_201 ) ;
if ( V_32 != 0 )
return V_32 ;
}
V_190 = V_201 -> V_211 ;
F_3 ( F_131 ( V_190 ) ) ;
if ( F_132 ( V_225 ) )
F_133 ( V_190 ) ;
V_34 = F_20 ( V_15 ) ;
if ( F_125 ( ( V_190 -> V_208 != V_15 -> V_226 ) ||
( F_134 ( V_190 ) > V_34 ) ) ) {
F_22 ( V_207 , L_22 ) ;
V_32 = 1 ;
goto V_160;
}
V_222 = F_30 ( V_24 , V_34 - 1 ) ;
if ( V_220 -> V_224 ) {
if ( V_222 < V_220 -> V_135 ) {
F_22 ( V_207 ,
L_23 ,
V_190 -> V_208 , V_220 -> V_135 , V_222 ) ;
V_32 = - V_227 ;
goto V_160;
}
}
V_88 = F_135 ( V_3 , V_24 , V_220 -> V_135 , V_190 , V_228 ) ;
if ( F_136 ( V_88 ) ) {
V_32 = F_137 ( V_88 ) ;
goto V_160;
}
if ( V_220 -> V_224 ) {
F_138 ( V_190 ) ;
if ( ! F_113 ( V_190 ) ) {
struct V_177 * V_178 = & V_9 -> V_183 . V_185 ;
struct V_188 * V_189 = F_101 ( V_24 , V_88 ) ;
int V_180 = V_70 ;
F_139 ( V_3 , V_9 , V_88 ) ;
F_32 ( V_178 ) ;
F_140 ( V_178 , V_88 ) ;
if ( V_222 == F_106 ( V_189 ) )
V_180 = V_34 & ~ V_114 ;
V_32 = F_108 ( V_3 , V_9 , V_178 , 0 , V_180 ,
F_127 ) ;
F_3 ( F_141 ( V_88 , V_9 ) ) ;
F_115 ( V_3 , V_178 ) ;
V_190 = NULL ;
if ( V_32 < 0 ) {
F_114 ( V_3 , V_9 , V_88 ) ;
F_96 ( V_3 , V_9 , V_88 ) ;
F_41 ( V_3 , V_88 ) ;
if ( V_32 == - V_196 )
V_32 = - V_229 ;
goto V_160;
} else {
F_96 ( V_3 , V_9 , V_88 ) ;
}
}
}
F_3 ( ! V_220 -> V_224 || V_220 -> V_135 <= V_222 ) ;
if ( V_220 -> V_135 == V_222 )
V_220 -> V_230 = V_34 - F_130 ( V_24 , V_220 -> V_135 ) ;
else
V_220 -> V_230 = F_142 ( V_24 ) ;
F_143 ( & V_88 -> V_91 , L_5 , V_9 ) ;
V_220 -> V_90 = V_88 ;
V_160:
if ( V_190 )
F_144 ( V_190 ) ;
V_201 -> V_205 &= ~ V_210 ;
return V_32 ;
}
static int F_145 ( const struct V_2 * V_3 ,
const struct V_4 * V_63 )
{
return 0 ;
}
static int F_146 ( const struct V_2 * V_3 ,
const struct V_4 * V_63 ,
const struct V_231 * V_5 )
{
struct V_8 * V_9 = V_63 -> V_78 ;
struct V_188 * V_189 = F_100 ( V_5 ) ;
struct V_87 * V_88 = V_5 -> V_232 ;
struct V_15 * V_15 = F_10 ( V_5 -> V_233 ) ;
struct V_234 * V_235 = F_84 ( V_15 ) ;
struct V_236 * V_237 = F_1 ( V_3 , V_63 ) -> V_51 ;
struct V_238 * V_239 = & V_237 -> V_240 ;
struct V_181 * V_182 = & V_9 -> V_183 ;
if ( V_235 -> V_241 . V_242 &&
V_235 -> V_241 . V_243 )
F_147 ( V_235 , V_15 , V_239 , F_106 ( V_189 ) ,
V_189 -> V_244 ) ;
if ( V_189 -> V_244 ) {
V_189 -> V_245 = 1 ;
F_148 ( V_3 , V_88 , 1 ) ;
}
F_140 ( & V_182 -> V_185 , V_88 ) ;
if ( V_235 -> V_241 . V_242 &&
V_235 -> V_241 . V_243 )
F_149 ( V_3 , V_9 , & V_182 -> V_185 , V_239 ,
V_189 -> V_244 ) ;
return 0 ;
}
void F_150 ( const struct V_2 * V_3 , const struct V_4 * V_63 )
{
F_26 ( V_3 , V_63 -> V_78 -> V_50 ,
F_27 ( V_63 -> V_78 -> V_50 ) ) ;
}
int F_151 ( const struct V_2 * V_3 , struct V_23 * V_24 ,
struct V_8 * V_9 )
{
struct V_1 * V_6 = F_4 ( V_3 ) ;
struct V_15 * V_15 = F_10 ( V_24 ) ;
int V_32 ;
F_26 ( V_3 , V_24 , F_27 ( V_24 ) ) ;
F_22 ( V_38 , V_39
L_3 ,
F_23 ( F_24 ( & V_24 -> V_40 ) ) ,
V_9 -> V_79 , V_9 -> V_80 ,
V_6 -> V_19 , V_9 -> V_81 ) ;
F_152 ( V_6 , V_7 ) ;
F_153 ( V_9 , & V_6 -> V_7 , V_24 , & V_246 ) ;
V_6 -> V_165 = false ;
V_32 = 0 ;
if ( V_9 -> V_10 == V_11 || V_9 -> V_10 == V_12 ) {
T_2 V_26 ;
struct V_16 * V_17 = F_7 ( V_15 ) ;
V_26 = V_9 -> V_64 . V_125 . V_126 ;
if ( V_26 == 0 )
V_32 = 1 ;
else
V_6 -> V_124 = V_26 ;
F_154 ( V_17 -> V_247 ) ;
} else if ( V_9 -> V_10 == V_248 ) {
if ( ! F_62 ( V_9 ) )
V_9 -> V_249 = V_250 ;
}
if ( V_9 -> V_10 == V_251 && ! V_9 -> V_80 )
V_9 -> V_79 = 1 ;
if ( V_32 == 0 && ! V_9 -> V_79 ) {
V_32 = F_38 ( V_15 , & V_6 -> V_19 ) ;
if ( V_32 == - V_252 )
V_32 = 0 ;
if ( V_32 < 0 )
F_81 ( L_24 V_39 L_25 ,
F_155 ( V_15 -> V_253 , NULL , 0 ) ,
F_23 ( F_24 ( & V_24 -> V_40 ) ) , V_32 ) ;
}
return V_32 ;
}
