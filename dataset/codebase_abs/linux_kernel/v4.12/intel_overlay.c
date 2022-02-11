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
F_22 ( F_23 ( V_2 ) && ! ( V_2 -> V_36 & V_37 ) ) ;
V_26 = F_19 ( V_15 ) ;
if ( F_24 ( V_26 ) )
return F_25 ( V_26 ) ;
V_34 = F_26 ( V_26 , 4 ) ;
if ( F_24 ( V_34 ) ) {
F_16 ( V_26 ) ;
return F_25 ( V_34 ) ;
}
V_15 -> V_35 = true ;
if ( F_23 ( V_2 ) )
F_1 ( V_2 , false ) ;
* V_34 ++ = V_38 | V_39 ;
* V_34 ++ = V_15 -> V_23 | V_40 ;
* V_34 ++ = V_41 | V_42 ;
* V_34 ++ = V_43 ;
F_27 ( V_26 , V_34 ) ;
return F_17 ( V_15 , V_26 , NULL ) ;
}
static void F_28 ( struct V_14 * V_15 ,
struct V_44 * V_45 )
{
enum V_46 V_46 = V_15 -> V_47 -> V_46 ;
F_22 ( V_15 -> V_48 ) ;
F_29 ( V_15 -> V_45 ? V_15 -> V_45 -> V_49 : NULL ,
V_45 ? V_45 -> V_49 : NULL ,
F_30 ( V_46 ) ) ;
F_31 ( V_15 -> V_16 ,
F_30 ( V_46 ) ) ;
V_15 -> V_48 = V_15 -> V_45 ;
if ( V_45 )
V_15 -> V_45 = F_32 ( V_45 ) ;
else
V_15 -> V_45 = NULL ;
}
static int F_33 ( struct V_14 * V_15 ,
struct V_44 * V_45 ,
bool V_50 )
{
struct V_1 * V_2 = V_15 -> V_16 ;
struct V_25 * V_26 ;
T_4 V_23 = V_15 -> V_23 ;
T_4 V_51 , * V_34 ;
F_22 ( ! V_15 -> V_35 ) ;
if ( V_50 )
V_23 |= V_40 ;
V_51 = F_34 ( V_52 ) ;
if ( V_51 & ( 1 << 17 ) )
F_35 ( L_1 , V_51 ) ;
V_26 = F_19 ( V_15 ) ;
if ( F_24 ( V_26 ) )
return F_25 ( V_26 ) ;
V_34 = F_26 ( V_26 , 2 ) ;
if ( F_24 ( V_34 ) ) {
F_16 ( V_26 ) ;
return F_25 ( V_34 ) ;
}
* V_34 ++ = V_38 | V_53 ;
* V_34 ++ = V_23 ;
F_27 ( V_26 , V_34 ) ;
F_28 ( V_15 , V_45 ) ;
F_11 ( V_15 , V_26 , NULL ) ;
return 0 ;
}
static void F_36 ( struct V_14 * V_15 )
{
struct V_44 * V_45 ;
V_45 = F_37 ( & V_15 -> V_48 ) ;
if ( F_22 ( ! V_45 ) )
return;
F_38 ( V_15 -> V_16 ,
F_30 ( V_15 -> V_47 -> V_46 ) ) ;
F_39 ( V_45 ) ;
F_40 ( V_45 ) ;
}
static void F_41 ( struct V_54 * V_35 ,
struct V_25 * V_26 )
{
struct V_14 * V_15 =
F_42 ( V_35 , F_43 ( * V_15 ) , V_28 ) ;
F_36 ( V_15 ) ;
}
static void F_44 ( struct V_54 * V_35 ,
struct V_25 * V_26 )
{
struct V_14 * V_15 =
F_42 ( V_35 , F_43 ( * V_15 ) , V_28 ) ;
struct V_1 * V_2 = V_15 -> V_16 ;
F_36 ( V_15 ) ;
V_15 -> V_47 -> V_15 = NULL ;
V_15 -> V_47 = NULL ;
V_15 -> V_35 = false ;
if ( F_23 ( V_2 ) )
F_1 ( V_2 , true ) ;
}
static int F_45 ( struct V_14 * V_15 )
{
struct V_25 * V_26 ;
T_4 * V_34 , V_23 = V_15 -> V_23 ;
F_22 ( ! V_15 -> V_35 ) ;
V_23 |= V_40 ;
V_26 = F_19 ( V_15 ) ;
if ( F_24 ( V_26 ) )
return F_25 ( V_26 ) ;
V_34 = F_26 ( V_26 , 6 ) ;
if ( F_24 ( V_34 ) ) {
F_16 ( V_26 ) ;
return F_25 ( V_34 ) ;
}
* V_34 ++ = V_38 | V_53 ;
* V_34 ++ = V_23 ;
* V_34 ++ = V_41 | V_42 ;
* V_34 ++ = V_38 | V_55 ;
* V_34 ++ = V_23 ;
* V_34 ++ = V_41 | V_42 ;
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
int V_56 ;
F_48 ( & V_2 -> V_6 . V_29 ) ;
if ( ! V_15 -> V_48 )
return 0 ;
if ( F_34 ( V_57 ) & V_58 ) {
struct V_25 * V_26 ;
V_26 = F_19 ( V_15 ) ;
if ( F_24 ( V_26 ) )
return F_25 ( V_26 ) ;
V_34 = F_26 ( V_26 , 2 ) ;
if ( F_24 ( V_34 ) ) {
F_16 ( V_26 ) ;
return F_25 ( V_34 ) ;
}
* V_34 ++ = V_41 | V_42 ;
* V_34 ++ = V_43 ;
F_27 ( V_26 , V_34 ) ;
V_56 = F_17 ( V_15 , V_26 ,
F_41 ) ;
if ( V_56 )
return V_56 ;
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
V_15 -> V_59 = 0 ;
V_15 -> V_60 = 0 ;
V_15 -> V_47 = NULL ;
V_15 -> V_35 = false ;
}
static int F_50 ( T_4 V_61 )
{
switch ( V_61 & V_62 ) {
case V_63 :
return 4 ;
case V_64 :
default:
return - V_65 ;
}
}
static int F_51 ( T_4 V_61 , short V_66 )
{
switch ( V_61 & V_62 ) {
case V_63 :
return V_66 << 1 ;
default:
return - V_65 ;
}
}
static int F_52 ( T_4 V_61 )
{
switch ( V_61 & V_62 ) {
case V_63 :
case V_67 :
return 2 ;
case V_64 :
case V_68 :
return 4 ;
default:
return - V_65 ;
}
}
static int F_53 ( T_4 V_61 )
{
switch ( V_61 & V_62 ) {
case V_67 :
case V_68 :
return 2 ;
case V_63 :
case V_64 :
return 1 ;
default:
return - V_65 ;
}
}
static T_4 F_54 ( struct V_1 * V_2 , T_4 V_69 , T_4 V_66 )
{
T_4 V_70 ;
if ( F_55 ( V_2 ) )
V_70 = F_56 ( ( V_69 & 31 ) + V_66 , 32 ) ;
else
V_70 = F_56 ( ( V_69 & 63 ) + V_66 , 64 ) ;
if ( V_70 == 0 )
return 0 ;
return ( V_70 - 32 ) >> 3 ;
}
static void F_57 ( struct V_13 T_2 * V_17 )
{
F_58 ( V_17 -> V_71 , V_72 , sizeof( V_72 ) ) ;
F_58 ( V_17 -> V_73 , V_74 ,
sizeof( V_74 ) ) ;
}
static bool F_59 ( struct V_14 * V_15 ,
struct V_13 T_2 * V_17 ,
struct V_75 * V_76 )
{
T_4 V_77 , V_78 , V_79 , V_80 ;
#define F_60 12
#define F_61 0xfff
bool V_81 = false ;
int V_82 = F_52 ( V_76 -> V_61 ) ;
int V_83 = F_53 ( V_76 -> V_61 ) ;
if ( V_76 -> V_84 > 1 )
V_77 = ( ( V_76 -> V_85 - 1 ) << F_60 )
/ ( V_76 -> V_84 ) ;
else
V_77 = 1 << F_60 ;
if ( V_76 -> V_86 > 1 )
V_78 = ( ( V_76 -> V_87 - 1 ) << F_60 )
/ ( V_76 -> V_86 ) ;
else
V_78 = 1 << F_60 ;
V_79 = V_77 / V_82 ;
V_80 = V_78 / V_83 ;
V_77 = V_79 * V_82 ;
V_78 = V_80 * V_83 ;
if ( V_77 != V_15 -> V_59 || V_78 != V_15 -> V_60 )
V_81 = true ;
V_15 -> V_59 = V_77 ;
V_15 -> V_60 = V_78 ;
F_62 ( ( ( V_78 & F_61 ) << 20 ) |
( ( V_77 >> F_60 ) << 16 ) |
( ( V_77 & F_61 ) << 3 ) ,
& V_17 -> V_88 ) ;
F_62 ( ( ( V_80 & F_61 ) << 20 ) |
( ( V_79 >> F_60 ) << 16 ) |
( ( V_79 & F_61 ) << 3 ) ,
& V_17 -> V_89 ) ;
F_62 ( ( ( ( V_78 >> F_60 ) << 16 ) |
( ( V_80 >> F_60 ) << 0 ) ) ,
& V_17 -> V_90 ) ;
if ( V_81 )
F_57 ( V_17 ) ;
return V_81 ;
}
static void F_63 ( struct V_14 * V_15 ,
struct V_13 T_2 * V_17 )
{
const struct V_91 * V_92 =
F_64 ( V_15 -> V_47 -> V_93 . V_94 -> V_92 ) ;
T_4 V_95 = V_15 -> V_96 ;
T_4 V_61 = 0 ;
T_4 V_97 = 0 ;
if ( V_15 -> V_98 )
V_97 |= V_99 ;
if ( V_92 -> V_93 . V_100 )
V_61 = V_92 -> V_93 . V_101 -> V_61 -> V_61 ;
switch ( V_61 ) {
case V_102 :
V_95 = 0 ;
V_97 |= V_103 ;
break;
case V_104 :
V_95 = F_65 ( V_95 ) ;
V_97 |= V_105 ;
break;
case V_106 :
V_95 = F_66 ( V_95 ) ;
V_97 |= V_107 ;
break;
default:
V_97 |= V_108 ;
break;
}
F_62 ( V_95 , & V_17 -> V_109 ) ;
F_62 ( V_97 , & V_17 -> V_110 ) ;
}
static T_4 F_67 ( struct V_75 * V_76 )
{
T_4 V_111 = V_112 | V_113 | V_114 ;
if ( V_76 -> V_61 & V_115 ) {
switch ( V_76 -> V_61 & V_62 ) {
case V_63 :
V_111 |= V_116 ;
break;
case V_67 :
V_111 |= V_117 ;
break;
case V_64 :
case V_68 :
V_111 |= V_118 ;
break;
}
} else {
switch ( V_76 -> V_61 & V_62 ) {
case V_63 :
V_111 |= V_119 ;
break;
case V_64 :
V_111 |= V_120 ;
break;
}
switch ( V_76 -> V_61 & V_121 ) {
case V_122 :
break;
case V_123 :
V_111 |= V_124 ;
break;
case V_125 :
V_111 |= V_126 ;
break;
case V_127 :
V_111 |= V_128 ;
break;
}
}
return V_111 ;
}
static int F_68 ( struct V_14 * V_15 ,
struct V_129 * V_130 ,
struct V_75 * V_76 )
{
int V_56 , V_131 ;
struct V_13 T_2 * V_17 ;
bool V_81 = false ;
struct V_1 * V_2 = V_15 -> V_16 ;
T_4 V_132 , V_133 , V_134 , V_135 ;
enum V_46 V_46 = V_15 -> V_47 -> V_46 ;
struct V_44 * V_45 ;
F_48 ( & V_2 -> V_6 . V_29 ) ;
F_22 ( ! F_69 ( & V_2 -> V_6 . V_136 . V_137 ) ) ;
V_56 = F_47 ( V_15 ) ;
if ( V_56 != 0 )
return V_56 ;
V_45 = F_70 ( V_130 , 0 , NULL ) ;
if ( F_24 ( V_45 ) )
return F_25 ( V_45 ) ;
V_56 = F_71 ( V_45 ) ;
if ( V_56 )
goto V_138;
if ( ! V_15 -> V_35 ) {
T_4 V_139 ;
V_17 = F_6 ( V_15 ) ;
if ( ! V_17 ) {
V_56 = - V_140 ;
goto V_138;
}
V_139 = V_141 ;
if ( F_72 ( V_2 ) )
V_139 |= V_142 ;
V_139 |= V_46 == 0 ?
V_143 : V_144 ;
F_62 ( V_139 , & V_17 -> V_145 ) ;
F_9 ( V_15 , V_17 ) ;
V_56 = F_21 ( V_15 ) ;
if ( V_56 != 0 )
goto V_138;
}
V_17 = F_6 ( V_15 ) ;
if ( ! V_17 ) {
V_56 = - V_140 ;
goto V_138;
}
F_62 ( ( V_76 -> V_146 << 16 ) | V_76 -> V_147 , & V_17 -> V_148 ) ;
F_62 ( ( V_76 -> V_86 << 16 ) | V_76 -> V_84 , & V_17 -> V_149 ) ;
if ( V_76 -> V_61 & V_150 )
V_131 = F_51 ( V_76 -> V_61 , V_76 -> V_151 ) ;
else
V_131 = V_76 -> V_151 ;
V_132 = V_76 -> V_151 ;
V_133 = F_54 ( V_2 , V_76 -> V_152 , V_131 ) ;
V_134 = V_76 -> V_153 ;
F_62 ( F_73 ( V_45 ) + V_76 -> V_152 , & V_17 -> V_154 ) ;
V_135 = V_76 -> V_155 ;
if ( V_76 -> V_61 & V_115 ) {
int V_82 = F_52 ( V_76 -> V_61 ) ;
int V_83 = F_53 ( V_76 -> V_61 ) ;
T_4 V_156 , V_157 ;
V_132 |= ( V_76 -> V_151 / V_82 ) << 16 ;
V_156 = F_54 ( V_2 , V_76 -> V_158 ,
V_76 -> V_151 / V_82 ) ;
V_157 = F_54 ( V_2 , V_76 -> V_159 ,
V_76 -> V_151 / V_82 ) ;
V_133 |= F_74 ( T_4 , V_156 , V_157 ) << 16 ;
V_134 |= ( V_76 -> V_153 / V_83 ) << 16 ;
F_62 ( F_73 ( V_45 ) + V_76 -> V_158 ,
& V_17 -> V_160 ) ;
F_62 ( F_73 ( V_45 ) + V_76 -> V_159 ,
& V_17 -> V_161 ) ;
V_135 |= V_76 -> V_162 << 16 ;
}
F_62 ( V_132 , & V_17 -> V_163 ) ;
F_62 ( V_133 , & V_17 -> V_164 ) ;
F_62 ( V_134 , & V_17 -> V_165 ) ;
F_62 ( V_135 , & V_17 -> V_166 ) ;
V_81 = F_59 ( V_15 , V_17 , V_76 ) ;
F_63 ( V_15 , V_17 ) ;
F_62 ( F_67 ( V_76 ) , & V_17 -> V_167 ) ;
F_9 ( V_15 , V_17 ) ;
V_56 = F_33 ( V_15 , V_45 , V_81 ) ;
if ( V_56 )
goto V_138;
return 0 ;
V_138:
F_39 ( V_45 ) ;
return V_56 ;
}
int F_75 ( struct V_14 * V_15 )
{
struct V_1 * V_2 = V_15 -> V_16 ;
struct V_13 T_2 * V_17 ;
int V_56 ;
F_48 ( & V_2 -> V_6 . V_29 ) ;
F_22 ( ! F_69 ( & V_2 -> V_6 . V_136 . V_137 ) ) ;
V_56 = F_46 ( V_15 ) ;
if ( V_56 != 0 )
return V_56 ;
if ( ! V_15 -> V_35 )
return 0 ;
V_56 = F_47 ( V_15 ) ;
if ( V_56 != 0 )
return V_56 ;
V_17 = F_6 ( V_15 ) ;
F_62 ( 0 , & V_17 -> V_167 ) ;
F_9 ( V_15 , V_17 ) ;
return F_45 ( V_15 ) ;
}
static int F_76 ( struct V_14 * V_15 ,
struct V_168 * V_47 )
{
if ( ! V_47 -> V_35 )
return - V_65 ;
if ( V_47 -> V_169 -> V_170 )
return - V_65 ;
return 0 ;
}
static void F_77 ( struct V_14 * V_15 )
{
struct V_1 * V_2 = V_15 -> V_16 ;
T_4 V_171 = F_34 ( V_172 ) ;
T_4 V_173 ;
if ( F_78 ( V_2 ) >= 4 ) {
V_173 = F_34 ( V_174 ) >> V_175 ;
} else {
if ( V_171 & V_176 )
V_173 = F_34 ( V_177 ) ;
else
V_173 = F_34 ( V_174 ) ;
V_173 >>= V_178 ;
}
V_15 -> V_179 = V_173 ;
}
static int F_79 ( struct V_14 * V_15 ,
struct V_180 * V_181 )
{
const struct V_182 * V_183 =
V_15 -> V_47 -> V_169 ;
if ( V_181 -> V_147 < V_183 -> V_184 &&
V_181 -> V_147 + V_181 -> V_185 <= V_183 -> V_184 &&
V_181 -> V_146 < V_183 -> V_186 &&
V_181 -> V_146 + V_181 -> V_187 <= V_183 -> V_186 )
return 0 ;
else
return - V_65 ;
}
static int F_80 ( struct V_75 * V_181 )
{
T_4 V_51 ;
V_51 = ( ( V_181 -> V_87 << 16 ) / V_181 -> V_86 ) >> 16 ;
if ( V_51 > 7 )
return - V_65 ;
V_51 = ( ( V_181 -> V_85 << 16 ) / V_181 -> V_84 ) >> 16 ;
if ( V_51 > 7 )
return - V_65 ;
return 0 ;
}
static int F_81 ( struct V_1 * V_2 ,
struct V_180 * V_181 ,
struct V_129 * V_130 )
{
int V_82 = F_52 ( V_181 -> V_97 ) ;
int V_83 = F_53 ( V_181 -> V_97 ) ;
T_4 V_188 ;
int V_189 ;
T_4 V_51 ;
if ( F_82 ( V_2 ) || F_23 ( V_2 ) ) {
if ( V_181 -> V_190 > V_191 ||
V_181 -> V_192 > V_193 )
return - V_65 ;
} else {
if ( V_181 -> V_190 > V_194 ||
V_181 -> V_192 > V_195 )
return - V_65 ;
}
if ( V_181 -> V_190 < V_196 * 4 ||
V_181 -> V_192 < V_197 * 4 )
return - V_65 ;
switch ( V_181 -> V_97 & V_198 ) {
case V_199 :
return - V_65 ;
case V_150 :
if ( V_83 != 1 )
return - V_65 ;
V_189 = F_50 ( V_181 -> V_97 ) ;
if ( V_189 < 0 )
return V_189 ;
V_181 -> V_162 = 0 ;
V_181 -> V_158 = 0 ;
V_181 -> V_159 = 0 ;
if ( V_181 -> V_152 % V_189 )
return - V_65 ;
break;
case V_115 :
if ( V_83 < 0 || V_82 < 0 )
return - V_65 ;
break;
default:
return - V_65 ;
}
if ( V_181 -> V_192 % V_82 )
return - V_65 ;
if ( F_23 ( V_2 ) || F_82 ( V_2 ) )
V_188 = 255 ;
else
V_188 = 63 ;
if ( V_181 -> V_155 & V_188 || V_181 -> V_162 & V_188 )
return - V_65 ;
if ( F_72 ( V_2 ) && V_181 -> V_155 < 512 )
return - V_65 ;
V_51 = ( V_181 -> V_97 & V_198 ) == V_115 ?
4096 : 8192 ;
if ( V_181 -> V_155 > V_51 || V_181 -> V_162 > 2 * 1024 )
return - V_65 ;
switch ( V_181 -> V_97 & V_198 ) {
case V_199 :
case V_150 :
if ( F_51 ( V_181 -> V_97 , V_181 -> V_192 ) > V_181 -> V_155 )
return - V_65 ;
V_51 = V_181 -> V_155 * V_181 -> V_190 ;
if ( V_181 -> V_152 + V_51 > V_130 -> V_93 . V_200 )
return - V_65 ;
break;
case V_115 :
if ( V_181 -> V_192 > V_181 -> V_155 )
return - V_65 ;
if ( V_181 -> V_192 / V_82 > V_181 -> V_162 )
return - V_65 ;
V_51 = V_181 -> V_155 * V_181 -> V_190 ;
if ( V_181 -> V_152 + V_51 > V_130 -> V_93 . V_200 )
return - V_65 ;
V_51 = V_181 -> V_162 * ( V_181 -> V_190 / V_83 ) ;
if ( V_181 -> V_158 + V_51 > V_130 -> V_93 . V_200 ||
V_181 -> V_159 + V_51 > V_130 -> V_93 . V_200 )
return - V_65 ;
break;
}
return 0 ;
}
int F_83 ( struct V_201 * V_202 , void * V_203 ,
struct V_204 * V_205 )
{
struct V_180 * V_206 = V_203 ;
struct V_1 * V_2 = F_84 ( V_202 ) ;
struct V_14 * V_15 ;
struct V_207 * V_208 ;
struct V_168 * V_47 ;
struct V_129 * V_130 ;
struct V_75 * V_76 ;
int V_56 ;
V_15 = V_2 -> V_15 ;
if ( ! V_15 ) {
F_35 ( L_2 ) ;
return - V_209 ;
}
if ( ! ( V_206 -> V_97 & V_210 ) ) {
F_85 ( V_202 ) ;
F_86 ( & V_202 -> V_29 ) ;
V_56 = F_75 ( V_15 ) ;
F_87 ( & V_202 -> V_29 ) ;
F_88 ( V_202 ) ;
return V_56 ;
}
V_76 = F_89 ( sizeof( * V_76 ) , V_211 ) ;
if ( ! V_76 )
return - V_140 ;
V_208 = F_90 ( V_202 , V_206 -> V_212 ) ;
if ( ! V_208 ) {
V_56 = - V_213 ;
goto V_214;
}
V_47 = F_91 ( V_208 ) ;
V_130 = F_92 ( V_205 , V_206 -> V_215 ) ;
if ( ! V_130 ) {
V_56 = - V_213 ;
goto V_214;
}
F_85 ( V_202 ) ;
F_86 ( & V_202 -> V_29 ) ;
if ( F_93 ( V_130 ) ) {
F_94 ( L_3 ) ;
V_56 = - V_65 ;
goto V_216;
}
V_56 = F_46 ( V_15 ) ;
if ( V_56 != 0 )
goto V_216;
if ( V_15 -> V_47 != V_47 ) {
V_56 = F_75 ( V_15 ) ;
if ( V_56 != 0 )
goto V_216;
V_56 = F_76 ( V_15 , V_47 ) ;
if ( V_56 != 0 )
goto V_216;
V_15 -> V_47 = V_47 ;
V_47 -> V_15 = V_15 ;
if ( V_47 -> V_169 -> V_184 > 1024 &&
V_47 -> V_169 -> V_217 . V_218 & V_219 ) {
V_15 -> V_220 = true ;
F_77 ( V_15 ) ;
} else
V_15 -> V_220 = false ;
}
V_56 = F_79 ( V_15 , V_206 ) ;
if ( V_56 != 0 )
goto V_216;
if ( V_15 -> V_220 ) {
V_76 -> V_146 = ( ( ( ( T_4 ) V_206 -> V_146 ) << 12 ) /
V_15 -> V_179 ) ;
V_76 -> V_86 = ( ( ( ( T_4 ) V_206 -> V_187 ) << 12 ) /
V_15 -> V_179 ) + 1 ;
} else {
V_76 -> V_146 = V_206 -> V_146 ;
V_76 -> V_86 = V_206 -> V_187 ;
}
V_76 -> V_147 = V_206 -> V_147 ;
V_76 -> V_84 = V_206 -> V_185 ;
V_76 -> V_151 = V_206 -> V_192 ;
V_76 -> V_153 = V_206 -> V_190 ;
V_76 -> V_85 = V_206 -> V_221 ;
V_76 -> V_87 = V_206 -> V_222 ;
if ( V_76 -> V_87 > V_76 -> V_153 ||
V_76 -> V_85 > V_76 -> V_151 ) {
V_56 = - V_65 ;
goto V_216;
}
V_56 = F_81 ( V_2 , V_206 , V_130 ) ;
if ( V_56 != 0 )
goto V_216;
V_76 -> V_61 = V_206 -> V_97 & ~ V_223 ;
V_76 -> V_155 = V_206 -> V_155 ;
V_76 -> V_162 = V_206 -> V_162 ;
V_76 -> V_152 = V_206 -> V_152 ;
V_76 -> V_158 = V_206 -> V_158 ;
V_76 -> V_159 = V_206 -> V_159 ;
V_56 = F_80 ( V_76 ) ;
if ( V_56 != 0 )
goto V_216;
V_56 = F_68 ( V_15 , V_130 , V_76 ) ;
if ( V_56 != 0 )
goto V_216;
F_87 ( & V_202 -> V_29 ) ;
F_88 ( V_202 ) ;
F_95 ( V_130 ) ;
F_96 ( V_76 ) ;
return 0 ;
V_216:
F_87 ( & V_202 -> V_29 ) ;
F_88 ( V_202 ) ;
F_95 ( V_130 ) ;
V_214:
F_96 ( V_76 ) ;
return V_56 ;
}
static void F_97 ( struct V_14 * V_15 ,
struct V_13 T_2 * V_17 )
{
F_62 ( ( V_15 -> V_224 << 18 ) | ( V_15 -> V_225 & 0xff ) ,
& V_17 -> V_226 ) ;
F_62 ( V_15 -> V_227 , & V_17 -> V_228 ) ;
}
static bool F_98 ( T_4 V_229 , T_4 V_230 )
{
int V_231 ;
if ( V_229 & 0xff000000 || V_230 & 0xff000000 )
return false ;
for ( V_231 = 0 ; V_231 < 3 ; V_231 ++ ) {
if ( ( ( V_229 >> V_231 * 8 ) & 0xff ) >= ( ( V_230 >> V_231 * 8 ) & 0xff ) )
return false ;
}
return true ;
}
static bool F_99 ( T_4 V_232 )
{
int V_231 ;
for ( V_231 = 0 ; V_231 < 3 ; V_231 ++ ) {
if ( ( ( V_232 >> V_231 * 8 ) & 0xff ) == 0x80 )
return false ;
}
return true ;
}
static int F_100 ( struct V_233 * V_234 )
{
if ( ! F_98 ( 0 , V_234 -> V_235 ) ||
! F_98 ( V_234 -> V_235 , V_234 -> V_229 ) ||
! F_98 ( V_234 -> V_229 , V_234 -> V_230 ) ||
! F_98 ( V_234 -> V_230 , V_234 -> V_236 ) ||
! F_98 ( V_234 -> V_236 , V_234 -> V_237 ) ||
! F_98 ( V_234 -> V_237 , V_234 -> V_232 ) ||
! F_98 ( V_234 -> V_232 , 0x00ffffff ) )
return - V_65 ;
if ( ! F_99 ( V_234 -> V_232 ) )
return - V_65 ;
return 0 ;
}
int F_101 ( struct V_201 * V_202 , void * V_203 ,
struct V_204 * V_205 )
{
struct V_233 * V_234 = V_203 ;
struct V_1 * V_2 = F_84 ( V_202 ) ;
struct V_14 * V_15 ;
struct V_13 T_2 * V_17 ;
int V_56 ;
V_15 = V_2 -> V_15 ;
if ( ! V_15 ) {
F_35 ( L_2 ) ;
return - V_209 ;
}
F_85 ( V_202 ) ;
F_86 ( & V_202 -> V_29 ) ;
V_56 = - V_65 ;
if ( ! ( V_234 -> V_97 & V_238 ) ) {
V_234 -> V_96 = V_15 -> V_96 ;
V_234 -> V_225 = V_15 -> V_225 ;
V_234 -> V_224 = V_15 -> V_224 ;
V_234 -> V_227 = V_15 -> V_227 ;
if ( ! F_55 ( V_2 ) ) {
V_234 -> V_235 = F_34 ( V_239 ) ;
V_234 -> V_229 = F_34 ( V_240 ) ;
V_234 -> V_230 = F_34 ( V_241 ) ;
V_234 -> V_236 = F_34 ( V_242 ) ;
V_234 -> V_237 = F_34 ( V_243 ) ;
V_234 -> V_232 = F_34 ( V_244 ) ;
}
} else {
if ( V_234 -> V_225 < - 128 || V_234 -> V_225 > 127 )
goto V_216;
if ( V_234 -> V_224 > 255 )
goto V_216;
if ( V_234 -> V_227 > 1023 )
goto V_216;
V_15 -> V_96 = V_234 -> V_96 ;
V_15 -> V_225 = V_234 -> V_225 ;
V_15 -> V_224 = V_234 -> V_224 ;
V_15 -> V_227 = V_234 -> V_227 ;
V_17 = F_6 ( V_15 ) ;
if ( ! V_17 ) {
V_56 = - V_140 ;
goto V_216;
}
F_97 ( V_15 , V_17 ) ;
F_9 ( V_15 , V_17 ) ;
if ( V_234 -> V_97 & V_245 ) {
if ( F_55 ( V_2 ) )
goto V_216;
if ( V_15 -> V_35 ) {
V_56 = - V_246 ;
goto V_216;
}
V_56 = F_100 ( V_234 ) ;
if ( V_56 )
goto V_216;
F_2 ( V_239 , V_234 -> V_235 ) ;
F_2 ( V_240 , V_234 -> V_229 ) ;
F_2 ( V_241 , V_234 -> V_230 ) ;
F_2 ( V_242 , V_234 -> V_236 ) ;
F_2 ( V_243 , V_234 -> V_237 ) ;
F_2 ( V_244 , V_234 -> V_232 ) ;
}
}
V_15 -> V_98 = ( V_234 -> V_97 & V_247 ) == 0 ;
V_56 = 0 ;
V_216:
F_87 ( & V_202 -> V_29 ) ;
F_88 ( V_202 ) ;
return V_56 ;
}
void F_102 ( struct V_1 * V_2 )
{
struct V_14 * V_15 ;
struct V_129 * V_18 ;
struct V_13 T_2 * V_17 ;
struct V_44 * V_45 = NULL ;
int V_56 ;
if ( ! F_103 ( V_2 ) )
return;
V_15 = F_104 ( sizeof( * V_15 ) , V_211 ) ;
if ( ! V_15 )
return;
F_86 ( & V_2 -> V_6 . V_29 ) ;
if ( F_22 ( V_2 -> V_15 ) )
goto V_214;
V_15 -> V_16 = V_2 ;
V_18 = NULL ;
if ( ! F_7 ( V_2 ) )
V_18 = F_105 ( V_2 , V_24 ) ;
if ( V_18 == NULL )
V_18 = F_106 ( V_2 , V_24 ) ;
if ( F_24 ( V_18 ) )
goto V_214;
V_15 -> V_18 = V_18 ;
if ( F_7 ( V_2 ) ) {
V_56 = F_107 ( V_18 , V_24 ) ;
if ( V_56 ) {
F_108 ( L_4 ) ;
goto V_248;
}
V_15 -> V_23 = V_18 -> V_19 -> V_249 ;
} else {
V_45 = F_109 ( V_18 , NULL ,
0 , V_24 , V_250 ) ;
if ( F_24 ( V_45 ) ) {
F_108 ( L_5 ) ;
V_56 = F_25 ( V_45 ) ;
goto V_248;
}
V_15 -> V_23 = F_73 ( V_45 ) ;
V_56 = F_110 ( V_18 , true ) ;
if ( V_56 ) {
F_108 ( L_6 ) ;
goto V_251;
}
}
V_15 -> V_96 = 0x0101fe ;
V_15 -> V_98 = true ;
V_15 -> V_225 = - 19 ;
V_15 -> V_224 = 75 ;
V_15 -> V_227 = 146 ;
F_111 ( & V_15 -> V_28 , NULL ) ;
V_17 = F_6 ( V_15 ) ;
if ( ! V_17 )
goto V_251;
F_112 ( V_17 , 0 , sizeof( struct V_13 ) ) ;
F_57 ( V_17 ) ;
F_97 ( V_15 , V_17 ) ;
F_9 ( V_15 , V_17 ) ;
V_2 -> V_15 = V_15 ;
F_87 ( & V_2 -> V_6 . V_29 ) ;
F_113 ( L_7 ) ;
return;
V_251:
if ( V_45 )
F_114 ( V_45 ) ;
V_248:
F_95 ( V_18 ) ;
V_214:
F_87 ( & V_2 -> V_6 . V_29 ) ;
F_96 ( V_15 ) ;
return;
}
void F_115 ( struct V_1 * V_2 )
{
if ( ! V_2 -> V_15 )
return;
F_22 ( V_2 -> V_15 -> V_35 ) ;
F_95 ( V_2 -> V_15 -> V_18 ) ;
F_96 ( V_2 -> V_15 ) ;
}
static struct V_13 T_2 *
F_116 ( struct V_14 * V_15 )
{
struct V_1 * V_2 = V_15 -> V_16 ;
struct V_13 T_2 * V_17 ;
if ( F_7 ( V_2 ) )
V_17 = (struct V_13 T_2 * )
V_15 -> V_18 -> V_19 -> V_20 ;
else
V_17 = F_117 ( & V_2 -> V_21 . V_22 ,
V_15 -> V_23 ) ;
return V_17 ;
}
static void F_118 ( struct V_14 * V_15 ,
struct V_13 T_2 * V_17 )
{
if ( ! F_7 ( V_15 -> V_16 ) )
F_119 ( V_17 ) ;
}
struct V_252 *
F_120 ( struct V_1 * V_2 )
{
struct V_14 * V_15 = V_2 -> V_15 ;
struct V_252 * error ;
struct V_13 T_2 * V_17 ;
if ( ! V_15 || ! V_15 -> V_35 )
return NULL ;
error = F_89 ( sizeof( * error ) , V_253 ) ;
if ( error == NULL )
return NULL ;
error -> V_254 = F_34 ( V_52 ) ;
error -> V_255 = F_34 ( V_57 ) ;
error -> V_93 = V_15 -> V_23 ;
V_17 = F_116 ( V_15 ) ;
if ( ! V_17 )
goto V_256;
F_121 ( & error -> V_17 , V_17 , sizeof( struct V_13 ) ) ;
F_118 ( V_15 , V_17 ) ;
return error ;
V_256:
F_96 ( error ) ;
return NULL ;
}
void
F_122 ( struct V_257 * V_258 ,
struct V_252 * error )
{
F_123 ( V_258 , L_8 ,
error -> V_254 , error -> V_255 ) ;
F_123 ( V_258 , L_9 ,
error -> V_93 ) ;
#define F_124 ( T_5 ) i915_error_printf(m, " " #x ": 0x%08x\n", error->regs.x)
F_124 ( V_154 ) ;
F_124 ( V_259 ) ;
F_124 ( V_160 ) ;
F_124 ( V_161 ) ;
F_124 ( V_260 ) ;
F_124 ( V_261 ) ;
F_124 ( V_166 ) ;
F_124 ( V_262 ) ;
F_124 ( V_263 ) ;
F_124 ( V_264 ) ;
F_124 ( V_265 ) ;
F_124 ( V_148 ) ;
F_124 ( V_149 ) ;
F_124 ( V_163 ) ;
F_124 ( V_164 ) ;
F_124 ( V_165 ) ;
F_124 ( V_88 ) ;
F_124 ( V_89 ) ;
F_124 ( V_226 ) ;
F_124 ( V_228 ) ;
F_124 ( V_109 ) ;
F_124 ( V_110 ) ;
F_124 ( V_266 ) ;
F_124 ( V_267 ) ;
F_124 ( V_268 ) ;
F_124 ( V_145 ) ;
F_124 ( V_167 ) ;
F_124 ( V_269 ) ;
F_124 ( V_270 ) ;
F_124 ( V_271 ) ;
F_124 ( V_272 ) ;
F_124 ( V_273 ) ;
F_124 ( V_274 ) ;
F_124 ( V_275 ) ;
F_124 ( V_276 ) ;
F_124 ( V_277 ) ;
F_124 ( V_278 ) ;
F_124 ( V_279 ) ;
F_124 ( V_280 ) ;
F_124 ( V_281 ) ;
F_124 ( V_90 ) ;
#undef F_124
}
