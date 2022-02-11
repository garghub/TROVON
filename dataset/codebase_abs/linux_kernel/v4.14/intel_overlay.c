static void F_1 ( struct V_1 * V_2 ,
bool V_3 )
{
struct V_4 * V_5 = V_2 -> V_6 . V_5 ;
T_1 V_7 ;
if ( V_3 )
F_2 ( V_8 , 0 ) ;
else
F_2 ( V_8 , V_9 ) ;
F_3 ( V_5 -> V_10 ,
F_4 ( 0 , 0 ) , V_11 , & V_7 ) ;
if ( V_3 )
V_7 &= ~ V_12 ;
else
V_7 |= V_12 ;
F_5 ( V_5 -> V_10 ,
F_4 ( 0 , 0 ) , V_11 , V_7 ) ;
}
static struct V_13 T_2 *
F_6 ( struct V_14 * V_15 )
{
struct V_1 * V_2 = V_15 -> V_16 ;
struct V_13 T_2 * V_17 ;
if ( F_7 ( V_2 ) )
V_17 = (struct V_13 T_2 * ) V_15 -> V_18 -> V_19 -> V_20 ;
else
V_17 = F_8 ( & V_2 -> V_21 . V_22 ,
V_15 -> V_23 ,
V_24 ) ;
return V_17 ;
}
static void F_9 ( struct V_14 * V_15 ,
struct V_13 T_2 * V_17 )
{
if ( ! F_7 ( V_15 -> V_16 ) )
F_10 ( V_17 ) ;
}
static void F_11 ( struct V_14 * V_15 ,
struct V_25 * V_26 ,
T_3 V_27 )
{
F_12 ( F_13 ( & V_15 -> V_28 ,
& V_15 -> V_16 -> V_6 . V_29 ) ) ;
F_14 ( & V_15 -> V_28 , V_27 ,
& V_15 -> V_16 -> V_6 . V_29 ) ;
F_15 ( & V_15 -> V_28 , V_26 ) ;
F_16 ( V_26 ) ;
}
static int F_17 ( struct V_14 * V_15 ,
struct V_25 * V_26 ,
T_3 V_27 )
{
F_11 ( V_15 , V_26 , V_27 ) ;
return F_18 ( & V_15 -> V_28 ,
& V_15 -> V_16 -> V_6 . V_29 ) ;
}
static struct V_25 * F_19 ( struct V_14 * V_15 )
{
struct V_1 * V_2 = V_15 -> V_16 ;
struct V_30 * V_31 = V_2 -> V_31 [ V_32 ] ;
return F_20 ( V_31 , V_2 -> V_33 ) ;
}
static int F_21 ( struct V_14 * V_15 )
{
struct V_1 * V_2 = V_15 -> V_16 ;
struct V_25 * V_26 ;
T_4 * V_34 ;
F_22 ( V_15 -> V_35 ) ;
V_26 = F_19 ( V_15 ) ;
if ( F_23 ( V_26 ) )
return F_24 ( V_26 ) ;
V_34 = F_25 ( V_26 , 4 ) ;
if ( F_23 ( V_34 ) ) {
F_16 ( V_26 ) ;
return F_24 ( V_34 ) ;
}
V_15 -> V_35 = true ;
if ( F_26 ( V_2 ) )
F_1 ( V_2 , false ) ;
* V_34 ++ = V_36 | V_37 ;
* V_34 ++ = V_15 -> V_23 | V_38 ;
* V_34 ++ = V_39 | V_40 ;
* V_34 ++ = V_41 ;
F_27 ( V_26 , V_34 ) ;
return F_17 ( V_15 , V_26 , NULL ) ;
}
static void F_28 ( struct V_14 * V_15 ,
struct V_42 * V_43 )
{
enum V_44 V_44 = V_15 -> V_45 -> V_44 ;
F_22 ( V_15 -> V_46 ) ;
F_29 ( V_15 -> V_43 ? V_15 -> V_43 -> V_47 : NULL ,
V_43 ? V_43 -> V_47 : NULL ,
F_30 ( V_44 ) ) ;
F_31 ( V_15 -> V_16 ,
F_30 ( V_44 ) ) ;
V_15 -> V_46 = V_15 -> V_43 ;
if ( V_43 )
V_15 -> V_43 = F_32 ( V_43 ) ;
else
V_15 -> V_43 = NULL ;
}
static int F_33 ( struct V_14 * V_15 ,
struct V_42 * V_43 ,
bool V_48 )
{
struct V_1 * V_2 = V_15 -> V_16 ;
struct V_25 * V_26 ;
T_4 V_23 = V_15 -> V_23 ;
T_4 V_49 , * V_34 ;
F_22 ( ! V_15 -> V_35 ) ;
if ( V_48 )
V_23 |= V_38 ;
V_49 = F_34 ( V_50 ) ;
if ( V_49 & ( 1 << 17 ) )
F_35 ( L_1 , V_49 ) ;
V_26 = F_19 ( V_15 ) ;
if ( F_23 ( V_26 ) )
return F_24 ( V_26 ) ;
V_34 = F_25 ( V_26 , 2 ) ;
if ( F_23 ( V_34 ) ) {
F_16 ( V_26 ) ;
return F_24 ( V_34 ) ;
}
* V_34 ++ = V_36 | V_51 ;
* V_34 ++ = V_23 ;
F_27 ( V_26 , V_34 ) ;
F_28 ( V_15 , V_43 ) ;
F_11 ( V_15 , V_26 , NULL ) ;
return 0 ;
}
static void F_36 ( struct V_14 * V_15 )
{
struct V_42 * V_43 ;
V_43 = F_37 ( & V_15 -> V_46 ) ;
if ( F_22 ( ! V_43 ) )
return;
F_38 ( V_15 -> V_16 ,
F_30 ( V_15 -> V_45 -> V_44 ) ) ;
F_39 ( V_43 ) ;
F_40 ( V_43 ) ;
}
static void F_41 ( struct V_52 * V_35 ,
struct V_25 * V_26 )
{
struct V_14 * V_15 =
F_42 ( V_35 , F_43 ( * V_15 ) , V_28 ) ;
F_36 ( V_15 ) ;
}
static void F_44 ( struct V_52 * V_35 ,
struct V_25 * V_26 )
{
struct V_14 * V_15 =
F_42 ( V_35 , F_43 ( * V_15 ) , V_28 ) ;
struct V_1 * V_2 = V_15 -> V_16 ;
F_36 ( V_15 ) ;
V_15 -> V_45 -> V_15 = NULL ;
V_15 -> V_45 = NULL ;
V_15 -> V_35 = false ;
if ( F_26 ( V_2 ) )
F_1 ( V_2 , true ) ;
}
static int F_45 ( struct V_14 * V_15 )
{
struct V_25 * V_26 ;
T_4 * V_34 , V_23 = V_15 -> V_23 ;
F_22 ( ! V_15 -> V_35 ) ;
V_23 |= V_38 ;
V_26 = F_19 ( V_15 ) ;
if ( F_23 ( V_26 ) )
return F_24 ( V_26 ) ;
V_34 = F_25 ( V_26 , 6 ) ;
if ( F_23 ( V_34 ) ) {
F_16 ( V_26 ) ;
return F_24 ( V_34 ) ;
}
* V_34 ++ = V_36 | V_51 ;
* V_34 ++ = V_23 ;
* V_34 ++ = V_39 | V_40 ;
* V_34 ++ = V_36 | V_53 ;
* V_34 ++ = V_23 ;
* V_34 ++ = V_39 | V_40 ;
F_27 ( V_26 , V_34 ) ;
F_28 ( V_15 , NULL ) ;
return F_17 ( V_15 , V_26 ,
F_44 ) ;
}
static int F_46 ( struct V_14 * V_15 )
{
return F_18 ( & V_15 -> V_28 ,
& V_15 -> V_16 -> V_6 . V_29 ) ;
}
static int F_47 ( struct V_14 * V_15 )
{
struct V_1 * V_2 = V_15 -> V_16 ;
T_4 * V_34 ;
int V_54 ;
F_48 ( & V_2 -> V_6 . V_29 ) ;
if ( ! V_15 -> V_46 )
return 0 ;
if ( F_34 ( V_55 ) & V_56 ) {
struct V_25 * V_26 ;
V_26 = F_19 ( V_15 ) ;
if ( F_23 ( V_26 ) )
return F_24 ( V_26 ) ;
V_34 = F_25 ( V_26 , 2 ) ;
if ( F_23 ( V_34 ) ) {
F_16 ( V_26 ) ;
return F_24 ( V_34 ) ;
}
* V_34 ++ = V_39 | V_40 ;
* V_34 ++ = V_41 ;
F_27 ( V_26 , V_34 ) ;
V_54 = F_17 ( V_15 , V_26 ,
F_41 ) ;
if ( V_54 )
return V_54 ;
} else
F_41 ( & V_15 -> V_28 , NULL ) ;
return 0 ;
}
void F_49 ( struct V_1 * V_2 )
{
struct V_14 * V_15 = V_2 -> V_15 ;
if ( ! V_15 )
return;
F_47 ( V_15 ) ;
V_15 -> V_57 = 0 ;
V_15 -> V_58 = 0 ;
V_15 -> V_45 = NULL ;
V_15 -> V_35 = false ;
}
static int F_50 ( T_4 V_59 )
{
switch ( V_59 & V_60 ) {
case V_61 :
return 4 ;
case V_62 :
default:
return - V_63 ;
}
}
static int F_51 ( T_4 V_59 , short V_64 )
{
switch ( V_59 & V_60 ) {
case V_61 :
return V_64 << 1 ;
default:
return - V_63 ;
}
}
static int F_52 ( T_4 V_59 )
{
switch ( V_59 & V_60 ) {
case V_61 :
case V_65 :
return 2 ;
case V_62 :
case V_66 :
return 4 ;
default:
return - V_63 ;
}
}
static int F_53 ( T_4 V_59 )
{
switch ( V_59 & V_60 ) {
case V_65 :
case V_66 :
return 2 ;
case V_61 :
case V_62 :
return 1 ;
default:
return - V_63 ;
}
}
static T_4 F_54 ( struct V_1 * V_2 , T_4 V_67 , T_4 V_64 )
{
T_4 V_68 ;
if ( F_55 ( V_2 ) )
V_68 = F_56 ( ( V_67 & 31 ) + V_64 , 32 ) ;
else
V_68 = F_56 ( ( V_67 & 63 ) + V_64 , 64 ) ;
if ( V_68 == 0 )
return 0 ;
return ( V_68 - 32 ) >> 3 ;
}
static void F_57 ( struct V_13 T_2 * V_17 )
{
F_58 ( V_17 -> V_69 , V_70 , sizeof( V_70 ) ) ;
F_58 ( V_17 -> V_71 , V_72 ,
sizeof( V_72 ) ) ;
}
static bool F_59 ( struct V_14 * V_15 ,
struct V_13 T_2 * V_17 ,
struct V_73 * V_74 )
{
T_4 V_75 , V_76 , V_77 , V_78 ;
#define F_60 12
#define F_61 0xfff
bool V_79 = false ;
int V_80 = F_52 ( V_74 -> V_59 ) ;
int V_81 = F_53 ( V_74 -> V_59 ) ;
if ( V_74 -> V_82 > 1 )
V_75 = ( ( V_74 -> V_83 - 1 ) << F_60 )
/ ( V_74 -> V_82 ) ;
else
V_75 = 1 << F_60 ;
if ( V_74 -> V_84 > 1 )
V_76 = ( ( V_74 -> V_85 - 1 ) << F_60 )
/ ( V_74 -> V_84 ) ;
else
V_76 = 1 << F_60 ;
V_77 = V_75 / V_80 ;
V_78 = V_76 / V_81 ;
V_75 = V_77 * V_80 ;
V_76 = V_78 * V_81 ;
if ( V_75 != V_15 -> V_57 || V_76 != V_15 -> V_58 )
V_79 = true ;
V_15 -> V_57 = V_75 ;
V_15 -> V_58 = V_76 ;
F_62 ( ( ( V_76 & F_61 ) << 20 ) |
( ( V_75 >> F_60 ) << 16 ) |
( ( V_75 & F_61 ) << 3 ) ,
& V_17 -> V_86 ) ;
F_62 ( ( ( V_78 & F_61 ) << 20 ) |
( ( V_77 >> F_60 ) << 16 ) |
( ( V_77 & F_61 ) << 3 ) ,
& V_17 -> V_87 ) ;
F_62 ( ( ( ( V_76 >> F_60 ) << 16 ) |
( ( V_78 >> F_60 ) << 0 ) ) ,
& V_17 -> V_88 ) ;
if ( V_79 )
F_57 ( V_17 ) ;
return V_79 ;
}
static void F_63 ( struct V_14 * V_15 ,
struct V_13 T_2 * V_17 )
{
const struct V_89 * V_90 =
F_64 ( V_15 -> V_45 -> V_91 . V_92 -> V_90 ) ;
T_4 V_93 = V_15 -> V_94 ;
T_4 V_59 = 0 ;
T_4 V_95 = 0 ;
if ( V_15 -> V_96 )
V_95 |= V_97 ;
if ( V_90 -> V_91 . V_98 )
V_59 = V_90 -> V_91 . V_99 -> V_59 -> V_59 ;
switch ( V_59 ) {
case V_100 :
V_93 = 0 ;
V_95 |= V_101 ;
break;
case V_102 :
V_93 = F_65 ( V_93 ) ;
V_95 |= V_103 ;
break;
case V_104 :
V_93 = F_66 ( V_93 ) ;
V_95 |= V_105 ;
break;
default:
V_95 |= V_106 ;
break;
}
F_62 ( V_93 , & V_17 -> V_107 ) ;
F_62 ( V_95 , & V_17 -> V_108 ) ;
}
static T_4 F_67 ( struct V_73 * V_74 )
{
T_4 V_109 = V_110 | V_111 | V_112 ;
if ( V_74 -> V_59 & V_113 ) {
switch ( V_74 -> V_59 & V_60 ) {
case V_61 :
V_109 |= V_114 ;
break;
case V_65 :
V_109 |= V_115 ;
break;
case V_62 :
case V_66 :
V_109 |= V_116 ;
break;
}
} else {
switch ( V_74 -> V_59 & V_60 ) {
case V_61 :
V_109 |= V_117 ;
break;
case V_62 :
V_109 |= V_118 ;
break;
}
switch ( V_74 -> V_59 & V_119 ) {
case V_120 :
break;
case V_121 :
V_109 |= V_122 ;
break;
case V_123 :
V_109 |= V_124 ;
break;
case V_125 :
V_109 |= V_126 ;
break;
}
}
return V_109 ;
}
static int F_68 ( struct V_14 * V_15 ,
struct V_127 * V_128 ,
struct V_73 * V_74 )
{
int V_54 , V_129 ;
struct V_13 T_2 * V_17 ;
bool V_79 = false ;
struct V_1 * V_2 = V_15 -> V_16 ;
T_4 V_130 , V_131 , V_132 , V_133 ;
enum V_44 V_44 = V_15 -> V_45 -> V_44 ;
struct V_42 * V_43 ;
F_48 ( & V_2 -> V_6 . V_29 ) ;
F_22 ( ! F_69 ( & V_2 -> V_6 . V_134 . V_135 ) ) ;
V_54 = F_47 ( V_15 ) ;
if ( V_54 != 0 )
return V_54 ;
F_70 ( & V_2 -> V_136 . V_137 ) ;
V_43 = F_71 ( V_128 , 0 , NULL ) ;
if ( F_23 ( V_43 ) ) {
V_54 = F_24 ( V_43 ) ;
goto V_138;
}
V_54 = F_72 ( V_43 ) ;
if ( V_54 )
goto V_139;
if ( ! V_15 -> V_35 ) {
T_4 V_140 ;
V_17 = F_6 ( V_15 ) ;
if ( ! V_17 ) {
V_54 = - V_141 ;
goto V_139;
}
V_140 = V_142 ;
if ( F_73 ( V_2 ) )
V_140 |= V_143 ;
V_140 |= V_44 == 0 ?
V_144 : V_145 ;
F_62 ( V_140 , & V_17 -> V_146 ) ;
F_9 ( V_15 , V_17 ) ;
V_54 = F_21 ( V_15 ) ;
if ( V_54 != 0 )
goto V_139;
}
V_17 = F_6 ( V_15 ) ;
if ( ! V_17 ) {
V_54 = - V_141 ;
goto V_139;
}
F_62 ( ( V_74 -> V_147 << 16 ) | V_74 -> V_148 , & V_17 -> V_149 ) ;
F_62 ( ( V_74 -> V_84 << 16 ) | V_74 -> V_82 , & V_17 -> V_150 ) ;
if ( V_74 -> V_59 & V_151 )
V_129 = F_51 ( V_74 -> V_59 , V_74 -> V_152 ) ;
else
V_129 = V_74 -> V_152 ;
V_130 = V_74 -> V_152 ;
V_131 = F_54 ( V_2 , V_74 -> V_153 , V_129 ) ;
V_132 = V_74 -> V_154 ;
F_62 ( F_74 ( V_43 ) + V_74 -> V_153 , & V_17 -> V_155 ) ;
V_133 = V_74 -> V_156 ;
if ( V_74 -> V_59 & V_113 ) {
int V_80 = F_52 ( V_74 -> V_59 ) ;
int V_81 = F_53 ( V_74 -> V_59 ) ;
T_4 V_157 , V_158 ;
V_130 |= ( V_74 -> V_152 / V_80 ) << 16 ;
V_157 = F_54 ( V_2 , V_74 -> V_159 ,
V_74 -> V_152 / V_80 ) ;
V_158 = F_54 ( V_2 , V_74 -> V_160 ,
V_74 -> V_152 / V_80 ) ;
V_131 |= F_75 ( T_4 , V_157 , V_158 ) << 16 ;
V_132 |= ( V_74 -> V_154 / V_81 ) << 16 ;
F_62 ( F_74 ( V_43 ) + V_74 -> V_159 ,
& V_17 -> V_161 ) ;
F_62 ( F_74 ( V_43 ) + V_74 -> V_160 ,
& V_17 -> V_162 ) ;
V_133 |= V_74 -> V_163 << 16 ;
}
F_62 ( V_130 , & V_17 -> V_164 ) ;
F_62 ( V_131 , & V_17 -> V_165 ) ;
F_62 ( V_132 , & V_17 -> V_166 ) ;
F_62 ( V_133 , & V_17 -> V_167 ) ;
V_79 = F_59 ( V_15 , V_17 , V_74 ) ;
F_63 ( V_15 , V_17 ) ;
F_62 ( F_67 ( V_74 ) , & V_17 -> V_168 ) ;
F_9 ( V_15 , V_17 ) ;
V_54 = F_33 ( V_15 , V_43 , V_79 ) ;
if ( V_54 )
goto V_139;
return 0 ;
V_139:
F_39 ( V_43 ) ;
V_138:
F_76 ( & V_2 -> V_136 . V_137 ) ;
return V_54 ;
}
int F_77 ( struct V_14 * V_15 )
{
struct V_1 * V_2 = V_15 -> V_16 ;
struct V_13 T_2 * V_17 ;
int V_54 ;
F_48 ( & V_2 -> V_6 . V_29 ) ;
F_22 ( ! F_69 ( & V_2 -> V_6 . V_134 . V_135 ) ) ;
V_54 = F_46 ( V_15 ) ;
if ( V_54 != 0 )
return V_54 ;
if ( ! V_15 -> V_35 )
return 0 ;
V_54 = F_47 ( V_15 ) ;
if ( V_54 != 0 )
return V_54 ;
V_17 = F_6 ( V_15 ) ;
F_62 ( 0 , & V_17 -> V_168 ) ;
F_9 ( V_15 , V_17 ) ;
return F_45 ( V_15 ) ;
}
static int F_78 ( struct V_14 * V_15 ,
struct V_169 * V_45 )
{
if ( ! V_45 -> V_35 )
return - V_63 ;
if ( V_45 -> V_170 -> V_171 )
return - V_63 ;
return 0 ;
}
static void F_79 ( struct V_14 * V_15 )
{
struct V_1 * V_2 = V_15 -> V_16 ;
T_4 V_172 = F_34 ( V_173 ) ;
T_4 V_174 ;
if ( F_80 ( V_2 ) >= 4 ) {
V_174 = F_34 ( V_175 ) >> V_176 ;
} else {
if ( V_172 & V_177 )
V_174 = F_34 ( V_178 ) ;
else
V_174 = F_34 ( V_175 ) ;
V_174 >>= V_179 ;
}
V_15 -> V_180 = V_174 ;
}
static int F_81 ( struct V_14 * V_15 ,
struct V_181 * V_182 )
{
const struct V_183 * V_184 =
V_15 -> V_45 -> V_170 ;
if ( V_182 -> V_148 < V_184 -> V_185 &&
V_182 -> V_148 + V_182 -> V_186 <= V_184 -> V_185 &&
V_182 -> V_147 < V_184 -> V_187 &&
V_182 -> V_147 + V_182 -> V_188 <= V_184 -> V_187 )
return 0 ;
else
return - V_63 ;
}
static int F_82 ( struct V_73 * V_182 )
{
T_4 V_49 ;
V_49 = ( ( V_182 -> V_85 << 16 ) / V_182 -> V_84 ) >> 16 ;
if ( V_49 > 7 )
return - V_63 ;
V_49 = ( ( V_182 -> V_83 << 16 ) / V_182 -> V_82 ) >> 16 ;
if ( V_49 > 7 )
return - V_63 ;
return 0 ;
}
static int F_83 ( struct V_1 * V_2 ,
struct V_181 * V_182 ,
struct V_127 * V_128 )
{
int V_80 = F_52 ( V_182 -> V_95 ) ;
int V_81 = F_53 ( V_182 -> V_95 ) ;
T_4 V_189 ;
int V_190 ;
T_4 V_49 ;
if ( F_84 ( V_2 ) || F_26 ( V_2 ) ) {
if ( V_182 -> V_191 > V_192 ||
V_182 -> V_193 > V_194 )
return - V_63 ;
} else {
if ( V_182 -> V_191 > V_195 ||
V_182 -> V_193 > V_196 )
return - V_63 ;
}
if ( V_182 -> V_191 < V_197 * 4 ||
V_182 -> V_193 < V_198 * 4 )
return - V_63 ;
switch ( V_182 -> V_95 & V_199 ) {
case V_200 :
return - V_63 ;
case V_151 :
if ( V_81 != 1 )
return - V_63 ;
V_190 = F_50 ( V_182 -> V_95 ) ;
if ( V_190 < 0 )
return V_190 ;
V_182 -> V_163 = 0 ;
V_182 -> V_159 = 0 ;
V_182 -> V_160 = 0 ;
if ( V_182 -> V_153 % V_190 )
return - V_63 ;
break;
case V_113 :
if ( V_81 < 0 || V_80 < 0 )
return - V_63 ;
break;
default:
return - V_63 ;
}
if ( V_182 -> V_193 % V_80 )
return - V_63 ;
if ( F_26 ( V_2 ) || F_84 ( V_2 ) )
V_189 = 255 ;
else
V_189 = 63 ;
if ( V_182 -> V_156 & V_189 || V_182 -> V_163 & V_189 )
return - V_63 ;
if ( F_73 ( V_2 ) && V_182 -> V_156 < 512 )
return - V_63 ;
V_49 = ( V_182 -> V_95 & V_199 ) == V_113 ?
4096 : 8192 ;
if ( V_182 -> V_156 > V_49 || V_182 -> V_163 > 2 * 1024 )
return - V_63 ;
switch ( V_182 -> V_95 & V_199 ) {
case V_200 :
case V_151 :
if ( F_51 ( V_182 -> V_95 , V_182 -> V_193 ) > V_182 -> V_156 )
return - V_63 ;
V_49 = V_182 -> V_156 * V_182 -> V_191 ;
if ( V_182 -> V_153 + V_49 > V_128 -> V_91 . V_201 )
return - V_63 ;
break;
case V_113 :
if ( V_182 -> V_193 > V_182 -> V_156 )
return - V_63 ;
if ( V_182 -> V_193 / V_80 > V_182 -> V_163 )
return - V_63 ;
V_49 = V_182 -> V_156 * V_182 -> V_191 ;
if ( V_182 -> V_153 + V_49 > V_128 -> V_91 . V_201 )
return - V_63 ;
V_49 = V_182 -> V_163 * ( V_182 -> V_191 / V_81 ) ;
if ( V_182 -> V_159 + V_49 > V_128 -> V_91 . V_201 ||
V_182 -> V_160 + V_49 > V_128 -> V_91 . V_201 )
return - V_63 ;
break;
}
return 0 ;
}
int F_85 ( struct V_202 * V_203 , void * V_204 ,
struct V_205 * V_206 )
{
struct V_181 * V_207 = V_204 ;
struct V_1 * V_2 = F_86 ( V_203 ) ;
struct V_14 * V_15 ;
struct V_208 * V_209 ;
struct V_169 * V_45 ;
struct V_127 * V_128 ;
struct V_73 * V_74 ;
int V_54 ;
V_15 = V_2 -> V_15 ;
if ( ! V_15 ) {
F_35 ( L_2 ) ;
return - V_210 ;
}
if ( ! ( V_207 -> V_95 & V_211 ) ) {
F_87 ( V_203 ) ;
F_88 ( & V_203 -> V_29 ) ;
V_54 = F_77 ( V_15 ) ;
F_89 ( & V_203 -> V_29 ) ;
F_90 ( V_203 ) ;
return V_54 ;
}
V_74 = F_91 ( sizeof( * V_74 ) , V_212 ) ;
if ( ! V_74 )
return - V_141 ;
V_209 = F_92 ( V_203 , V_207 -> V_213 ) ;
if ( ! V_209 ) {
V_54 = - V_214 ;
goto V_215;
}
V_45 = F_93 ( V_209 ) ;
V_128 = F_94 ( V_206 , V_207 -> V_216 ) ;
if ( ! V_128 ) {
V_54 = - V_214 ;
goto V_215;
}
F_87 ( V_203 ) ;
F_88 ( & V_203 -> V_29 ) ;
if ( F_95 ( V_128 ) ) {
F_96 ( L_3 ) ;
V_54 = - V_63 ;
goto V_217;
}
V_54 = F_46 ( V_15 ) ;
if ( V_54 != 0 )
goto V_217;
if ( V_15 -> V_45 != V_45 ) {
V_54 = F_77 ( V_15 ) ;
if ( V_54 != 0 )
goto V_217;
V_54 = F_78 ( V_15 , V_45 ) ;
if ( V_54 != 0 )
goto V_217;
V_15 -> V_45 = V_45 ;
V_45 -> V_15 = V_15 ;
if ( V_45 -> V_170 -> V_185 > 1024 &&
V_45 -> V_170 -> V_218 . V_219 & V_220 ) {
V_15 -> V_221 = true ;
F_79 ( V_15 ) ;
} else
V_15 -> V_221 = false ;
}
V_54 = F_81 ( V_15 , V_207 ) ;
if ( V_54 != 0 )
goto V_217;
if ( V_15 -> V_221 ) {
V_74 -> V_147 = ( ( ( ( T_4 ) V_207 -> V_147 ) << 12 ) /
V_15 -> V_180 ) ;
V_74 -> V_84 = ( ( ( ( T_4 ) V_207 -> V_188 ) << 12 ) /
V_15 -> V_180 ) + 1 ;
} else {
V_74 -> V_147 = V_207 -> V_147 ;
V_74 -> V_84 = V_207 -> V_188 ;
}
V_74 -> V_148 = V_207 -> V_148 ;
V_74 -> V_82 = V_207 -> V_186 ;
V_74 -> V_152 = V_207 -> V_193 ;
V_74 -> V_154 = V_207 -> V_191 ;
V_74 -> V_83 = V_207 -> V_222 ;
V_74 -> V_85 = V_207 -> V_223 ;
if ( V_74 -> V_85 > V_74 -> V_154 ||
V_74 -> V_83 > V_74 -> V_152 ) {
V_54 = - V_63 ;
goto V_217;
}
V_54 = F_83 ( V_2 , V_207 , V_128 ) ;
if ( V_54 != 0 )
goto V_217;
V_74 -> V_59 = V_207 -> V_95 & ~ V_224 ;
V_74 -> V_156 = V_207 -> V_156 ;
V_74 -> V_163 = V_207 -> V_163 ;
V_74 -> V_153 = V_207 -> V_153 ;
V_74 -> V_159 = V_207 -> V_159 ;
V_74 -> V_160 = V_207 -> V_160 ;
V_54 = F_82 ( V_74 ) ;
if ( V_54 != 0 )
goto V_217;
V_54 = F_68 ( V_15 , V_128 , V_74 ) ;
if ( V_54 != 0 )
goto V_217;
F_89 ( & V_203 -> V_29 ) ;
F_90 ( V_203 ) ;
F_97 ( V_128 ) ;
F_98 ( V_74 ) ;
return 0 ;
V_217:
F_89 ( & V_203 -> V_29 ) ;
F_90 ( V_203 ) ;
F_97 ( V_128 ) ;
V_215:
F_98 ( V_74 ) ;
return V_54 ;
}
static void F_99 ( struct V_14 * V_15 ,
struct V_13 T_2 * V_17 )
{
F_62 ( ( V_15 -> V_225 << 18 ) | ( V_15 -> V_226 & 0xff ) ,
& V_17 -> V_227 ) ;
F_62 ( V_15 -> V_228 , & V_17 -> V_229 ) ;
}
static bool F_100 ( T_4 V_230 , T_4 V_231 )
{
int V_232 ;
if ( V_230 & 0xff000000 || V_231 & 0xff000000 )
return false ;
for ( V_232 = 0 ; V_232 < 3 ; V_232 ++ ) {
if ( ( ( V_230 >> V_232 * 8 ) & 0xff ) >= ( ( V_231 >> V_232 * 8 ) & 0xff ) )
return false ;
}
return true ;
}
static bool F_101 ( T_4 V_233 )
{
int V_232 ;
for ( V_232 = 0 ; V_232 < 3 ; V_232 ++ ) {
if ( ( ( V_233 >> V_232 * 8 ) & 0xff ) == 0x80 )
return false ;
}
return true ;
}
static int F_102 ( struct V_234 * V_235 )
{
if ( ! F_100 ( 0 , V_235 -> V_236 ) ||
! F_100 ( V_235 -> V_236 , V_235 -> V_230 ) ||
! F_100 ( V_235 -> V_230 , V_235 -> V_231 ) ||
! F_100 ( V_235 -> V_231 , V_235 -> V_237 ) ||
! F_100 ( V_235 -> V_237 , V_235 -> V_238 ) ||
! F_100 ( V_235 -> V_238 , V_235 -> V_233 ) ||
! F_100 ( V_235 -> V_233 , 0x00ffffff ) )
return - V_63 ;
if ( ! F_101 ( V_235 -> V_233 ) )
return - V_63 ;
return 0 ;
}
int F_103 ( struct V_202 * V_203 , void * V_204 ,
struct V_205 * V_206 )
{
struct V_234 * V_235 = V_204 ;
struct V_1 * V_2 = F_86 ( V_203 ) ;
struct V_14 * V_15 ;
struct V_13 T_2 * V_17 ;
int V_54 ;
V_15 = V_2 -> V_15 ;
if ( ! V_15 ) {
F_35 ( L_2 ) ;
return - V_210 ;
}
F_87 ( V_203 ) ;
F_88 ( & V_203 -> V_29 ) ;
V_54 = - V_63 ;
if ( ! ( V_235 -> V_95 & V_239 ) ) {
V_235 -> V_94 = V_15 -> V_94 ;
V_235 -> V_226 = V_15 -> V_226 ;
V_235 -> V_225 = V_15 -> V_225 ;
V_235 -> V_228 = V_15 -> V_228 ;
if ( ! F_55 ( V_2 ) ) {
V_235 -> V_236 = F_34 ( V_240 ) ;
V_235 -> V_230 = F_34 ( V_241 ) ;
V_235 -> V_231 = F_34 ( V_242 ) ;
V_235 -> V_237 = F_34 ( V_243 ) ;
V_235 -> V_238 = F_34 ( V_244 ) ;
V_235 -> V_233 = F_34 ( V_245 ) ;
}
} else {
if ( V_235 -> V_226 < - 128 || V_235 -> V_226 > 127 )
goto V_217;
if ( V_235 -> V_225 > 255 )
goto V_217;
if ( V_235 -> V_228 > 1023 )
goto V_217;
V_15 -> V_94 = V_235 -> V_94 ;
V_15 -> V_226 = V_235 -> V_226 ;
V_15 -> V_225 = V_235 -> V_225 ;
V_15 -> V_228 = V_235 -> V_228 ;
V_17 = F_6 ( V_15 ) ;
if ( ! V_17 ) {
V_54 = - V_141 ;
goto V_217;
}
F_99 ( V_15 , V_17 ) ;
F_9 ( V_15 , V_17 ) ;
if ( V_235 -> V_95 & V_246 ) {
if ( F_55 ( V_2 ) )
goto V_217;
if ( V_15 -> V_35 ) {
V_54 = - V_247 ;
goto V_217;
}
V_54 = F_102 ( V_235 ) ;
if ( V_54 )
goto V_217;
F_2 ( V_240 , V_235 -> V_236 ) ;
F_2 ( V_241 , V_235 -> V_230 ) ;
F_2 ( V_242 , V_235 -> V_231 ) ;
F_2 ( V_243 , V_235 -> V_237 ) ;
F_2 ( V_244 , V_235 -> V_238 ) ;
F_2 ( V_245 , V_235 -> V_233 ) ;
}
}
V_15 -> V_96 = ( V_235 -> V_95 & V_248 ) == 0 ;
V_54 = 0 ;
V_217:
F_89 ( & V_203 -> V_29 ) ;
F_90 ( V_203 ) ;
return V_54 ;
}
void F_104 ( struct V_1 * V_2 )
{
struct V_14 * V_15 ;
struct V_127 * V_18 ;
struct V_13 T_2 * V_17 ;
struct V_42 * V_43 = NULL ;
int V_54 ;
if ( ! F_105 ( V_2 ) )
return;
V_15 = F_106 ( sizeof( * V_15 ) , V_212 ) ;
if ( ! V_15 )
return;
F_88 ( & V_2 -> V_6 . V_29 ) ;
if ( F_22 ( V_2 -> V_15 ) )
goto V_215;
V_15 -> V_16 = V_2 ;
V_18 = NULL ;
if ( ! F_7 ( V_2 ) )
V_18 = F_107 ( V_2 , V_24 ) ;
if ( V_18 == NULL )
V_18 = F_108 ( V_2 , V_24 ) ;
if ( F_23 ( V_18 ) )
goto V_215;
V_15 -> V_18 = V_18 ;
if ( F_7 ( V_2 ) ) {
V_54 = F_109 ( V_18 , V_24 ) ;
if ( V_54 ) {
F_110 ( L_4 ) ;
goto V_249;
}
V_15 -> V_23 = V_18 -> V_19 -> V_250 ;
} else {
V_43 = F_111 ( V_18 , NULL ,
0 , V_24 , V_251 ) ;
if ( F_23 ( V_43 ) ) {
F_110 ( L_5 ) ;
V_54 = F_24 ( V_43 ) ;
goto V_249;
}
V_15 -> V_23 = F_74 ( V_43 ) ;
V_54 = F_112 ( V_18 , true ) ;
if ( V_54 ) {
F_110 ( L_6 ) ;
goto V_252;
}
}
V_15 -> V_94 = 0x0101fe ;
V_15 -> V_96 = true ;
V_15 -> V_226 = - 19 ;
V_15 -> V_225 = 75 ;
V_15 -> V_228 = 146 ;
F_113 ( & V_15 -> V_28 , NULL ) ;
V_17 = F_6 ( V_15 ) ;
if ( ! V_17 )
goto V_252;
F_114 ( V_17 , 0 , sizeof( struct V_13 ) ) ;
F_57 ( V_17 ) ;
F_99 ( V_15 , V_17 ) ;
F_9 ( V_15 , V_17 ) ;
V_2 -> V_15 = V_15 ;
F_89 ( & V_2 -> V_6 . V_29 ) ;
F_115 ( L_7 ) ;
return;
V_252:
if ( V_43 )
F_116 ( V_43 ) ;
V_249:
F_97 ( V_18 ) ;
V_215:
F_89 ( & V_2 -> V_6 . V_29 ) ;
F_98 ( V_15 ) ;
return;
}
void F_117 ( struct V_1 * V_2 )
{
if ( ! V_2 -> V_15 )
return;
F_22 ( V_2 -> V_15 -> V_35 ) ;
F_97 ( V_2 -> V_15 -> V_18 ) ;
F_98 ( V_2 -> V_15 ) ;
}
static struct V_13 T_2 *
F_118 ( struct V_14 * V_15 )
{
struct V_1 * V_2 = V_15 -> V_16 ;
struct V_13 T_2 * V_17 ;
if ( F_7 ( V_2 ) )
V_17 = (struct V_13 T_2 * )
V_15 -> V_18 -> V_19 -> V_20 ;
else
V_17 = F_119 ( & V_2 -> V_21 . V_22 ,
V_15 -> V_23 ) ;
return V_17 ;
}
static void F_120 ( struct V_14 * V_15 ,
struct V_13 T_2 * V_17 )
{
if ( ! F_7 ( V_15 -> V_16 ) )
F_121 ( V_17 ) ;
}
struct V_253 *
F_122 ( struct V_1 * V_2 )
{
struct V_14 * V_15 = V_2 -> V_15 ;
struct V_253 * error ;
struct V_13 T_2 * V_17 ;
if ( ! V_15 || ! V_15 -> V_35 )
return NULL ;
error = F_91 ( sizeof( * error ) , V_254 ) ;
if ( error == NULL )
return NULL ;
error -> V_255 = F_34 ( V_50 ) ;
error -> V_256 = F_34 ( V_55 ) ;
error -> V_91 = V_15 -> V_23 ;
V_17 = F_118 ( V_15 ) ;
if ( ! V_17 )
goto V_257;
F_123 ( & error -> V_17 , V_17 , sizeof( struct V_13 ) ) ;
F_120 ( V_15 , V_17 ) ;
return error ;
V_257:
F_98 ( error ) ;
return NULL ;
}
void
F_124 ( struct V_258 * V_259 ,
struct V_253 * error )
{
F_125 ( V_259 , L_8 ,
error -> V_255 , error -> V_256 ) ;
F_125 ( V_259 , L_9 ,
error -> V_91 ) ;
#define F_126 ( T_5 ) i915_error_printf(m, " " #x ": 0x%08x\n", error->regs.x)
F_126 ( V_155 ) ;
F_126 ( V_260 ) ;
F_126 ( V_161 ) ;
F_126 ( V_162 ) ;
F_126 ( V_261 ) ;
F_126 ( V_262 ) ;
F_126 ( V_167 ) ;
F_126 ( V_263 ) ;
F_126 ( V_264 ) ;
F_126 ( V_265 ) ;
F_126 ( V_266 ) ;
F_126 ( V_149 ) ;
F_126 ( V_150 ) ;
F_126 ( V_164 ) ;
F_126 ( V_165 ) ;
F_126 ( V_166 ) ;
F_126 ( V_86 ) ;
F_126 ( V_87 ) ;
F_126 ( V_227 ) ;
F_126 ( V_229 ) ;
F_126 ( V_107 ) ;
F_126 ( V_108 ) ;
F_126 ( V_267 ) ;
F_126 ( V_268 ) ;
F_126 ( V_269 ) ;
F_126 ( V_146 ) ;
F_126 ( V_168 ) ;
F_126 ( V_270 ) ;
F_126 ( V_271 ) ;
F_126 ( V_272 ) ;
F_126 ( V_273 ) ;
F_126 ( V_274 ) ;
F_126 ( V_275 ) ;
F_126 ( V_276 ) ;
F_126 ( V_277 ) ;
F_126 ( V_278 ) ;
F_126 ( V_279 ) ;
F_126 ( V_280 ) ;
F_126 ( V_281 ) ;
F_126 ( V_282 ) ;
F_126 ( V_88 ) ;
#undef F_126
}
