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
struct V_34 * V_35 ;
int V_36 ;
F_22 ( V_15 -> V_37 ) ;
F_22 ( F_23 ( V_2 ) && ! ( V_2 -> V_38 & V_39 ) ) ;
V_26 = F_19 ( V_15 ) ;
if ( F_24 ( V_26 ) )
return F_25 ( V_26 ) ;
V_36 = F_26 ( V_26 , 4 ) ;
if ( V_36 ) {
F_27 ( V_26 ) ;
return V_36 ;
}
V_15 -> V_37 = true ;
if ( F_23 ( V_2 ) )
F_1 ( V_2 , false ) ;
V_35 = V_26 -> V_35 ;
F_28 ( V_35 , V_40 | V_41 ) ;
F_28 ( V_35 , V_15 -> V_23 | V_42 ) ;
F_28 ( V_35 , V_43 | V_44 ) ;
F_28 ( V_35 , V_45 ) ;
F_29 ( V_35 ) ;
return F_17 ( V_15 , V_26 , NULL ) ;
}
static void F_30 ( struct V_14 * V_15 ,
struct V_46 * V_47 )
{
enum V_48 V_48 = V_15 -> V_49 -> V_48 ;
F_22 ( V_15 -> V_50 ) ;
F_31 ( V_15 -> V_47 ? V_15 -> V_47 -> V_51 : NULL ,
V_47 ? V_47 -> V_51 : NULL ,
F_32 ( V_48 ) ) ;
F_33 ( V_15 -> V_16 ,
F_32 ( V_48 ) ) ;
V_15 -> V_50 = V_15 -> V_47 ;
if ( V_47 )
V_15 -> V_47 = F_34 ( V_47 ) ;
else
V_15 -> V_47 = NULL ;
}
static int F_35 ( struct V_14 * V_15 ,
struct V_46 * V_47 ,
bool V_52 )
{
struct V_1 * V_2 = V_15 -> V_16 ;
struct V_25 * V_26 ;
struct V_34 * V_35 ;
T_4 V_23 = V_15 -> V_23 ;
T_4 V_53 ;
int V_36 ;
F_22 ( ! V_15 -> V_37 ) ;
if ( V_52 )
V_23 |= V_42 ;
V_53 = F_36 ( V_54 ) ;
if ( V_53 & ( 1 << 17 ) )
F_37 ( L_1 , V_53 ) ;
V_26 = F_19 ( V_15 ) ;
if ( F_24 ( V_26 ) )
return F_25 ( V_26 ) ;
V_36 = F_26 ( V_26 , 2 ) ;
if ( V_36 ) {
F_27 ( V_26 ) ;
return V_36 ;
}
V_35 = V_26 -> V_35 ;
F_28 ( V_35 , V_40 | V_55 ) ;
F_28 ( V_35 , V_23 ) ;
F_29 ( V_35 ) ;
F_30 ( V_15 , V_47 ) ;
F_11 ( V_15 , V_26 , NULL ) ;
return 0 ;
}
static void F_38 ( struct V_14 * V_15 )
{
struct V_46 * V_47 ;
V_47 = F_39 ( & V_15 -> V_50 ) ;
if ( F_22 ( ! V_47 ) )
return;
F_40 ( V_15 -> V_16 ,
F_32 ( V_15 -> V_49 -> V_48 ) ) ;
F_41 ( V_47 ) ;
F_42 ( V_47 ) ;
}
static void F_43 ( struct V_56 * V_37 ,
struct V_25 * V_26 )
{
struct V_14 * V_15 =
F_44 ( V_37 , F_45 ( * V_15 ) , V_28 ) ;
F_38 ( V_15 ) ;
}
static void F_46 ( struct V_56 * V_37 ,
struct V_25 * V_26 )
{
struct V_14 * V_15 =
F_44 ( V_37 , F_45 ( * V_15 ) , V_28 ) ;
struct V_1 * V_2 = V_15 -> V_16 ;
F_38 ( V_15 ) ;
V_15 -> V_49 -> V_15 = NULL ;
V_15 -> V_49 = NULL ;
V_15 -> V_37 = false ;
if ( F_23 ( V_2 ) )
F_1 ( V_2 , true ) ;
}
static int F_47 ( struct V_14 * V_15 )
{
struct V_25 * V_26 ;
struct V_34 * V_35 ;
T_4 V_23 = V_15 -> V_23 ;
int V_36 ;
F_22 ( ! V_15 -> V_37 ) ;
V_23 |= V_42 ;
V_26 = F_19 ( V_15 ) ;
if ( F_24 ( V_26 ) )
return F_25 ( V_26 ) ;
V_36 = F_26 ( V_26 , 6 ) ;
if ( V_36 ) {
F_27 ( V_26 ) ;
return V_36 ;
}
V_35 = V_26 -> V_35 ;
F_28 ( V_35 , V_40 | V_55 ) ;
F_28 ( V_35 , V_23 ) ;
F_28 ( V_35 , V_43 | V_44 ) ;
F_28 ( V_35 , V_40 | V_57 ) ;
F_28 ( V_35 , V_23 ) ;
F_28 ( V_35 , V_43 | V_44 ) ;
F_29 ( V_35 ) ;
F_30 ( V_15 , NULL ) ;
return F_17 ( V_15 , V_26 ,
F_46 ) ;
}
static int F_48 ( struct V_14 * V_15 )
{
return F_18 ( & V_15 -> V_28 ,
& V_15 -> V_16 -> V_6 . V_29 ) ;
}
static int F_49 ( struct V_14 * V_15 )
{
struct V_1 * V_2 = V_15 -> V_16 ;
int V_36 ;
F_50 ( & V_2 -> V_6 . V_29 ) ;
if ( ! V_15 -> V_50 )
return 0 ;
if ( F_36 ( V_58 ) & V_59 ) {
struct V_25 * V_26 ;
struct V_34 * V_35 ;
V_26 = F_19 ( V_15 ) ;
if ( F_24 ( V_26 ) )
return F_25 ( V_26 ) ;
V_36 = F_26 ( V_26 , 2 ) ;
if ( V_36 ) {
F_27 ( V_26 ) ;
return V_36 ;
}
V_35 = V_26 -> V_35 ;
F_28 ( V_35 ,
V_43 | V_44 ) ;
F_28 ( V_35 , V_45 ) ;
F_29 ( V_35 ) ;
V_36 = F_17 ( V_15 , V_26 ,
F_43 ) ;
if ( V_36 )
return V_36 ;
} else
F_43 ( & V_15 -> V_28 , NULL ) ;
return 0 ;
}
void F_51 ( struct V_1 * V_2 )
{
struct V_14 * V_15 = V_2 -> V_15 ;
if ( ! V_15 )
return;
F_49 ( V_15 ) ;
V_15 -> V_60 = 0 ;
V_15 -> V_61 = 0 ;
V_15 -> V_49 = NULL ;
V_15 -> V_37 = false ;
}
static int F_52 ( T_4 V_62 )
{
switch ( V_62 & V_63 ) {
case V_64 :
return 4 ;
case V_65 :
default:
return - V_66 ;
}
}
static int F_53 ( T_4 V_62 , short V_67 )
{
switch ( V_62 & V_63 ) {
case V_64 :
return V_67 << 1 ;
default:
return - V_66 ;
}
}
static int F_54 ( T_4 V_62 )
{
switch ( V_62 & V_63 ) {
case V_64 :
case V_68 :
return 2 ;
case V_65 :
case V_69 :
return 4 ;
default:
return - V_66 ;
}
}
static int F_55 ( T_4 V_62 )
{
switch ( V_62 & V_63 ) {
case V_68 :
case V_69 :
return 2 ;
case V_64 :
case V_65 :
return 1 ;
default:
return - V_66 ;
}
}
static T_4 F_56 ( struct V_1 * V_2 , T_4 V_70 , T_4 V_67 )
{
T_4 V_71 ;
if ( F_57 ( V_2 ) )
V_71 = F_58 ( ( V_70 & 31 ) + V_67 , 32 ) ;
else
V_71 = F_58 ( ( V_70 & 63 ) + V_67 , 64 ) ;
if ( V_71 == 0 )
return 0 ;
return ( V_71 - 32 ) >> 3 ;
}
static void F_59 ( struct V_13 T_2 * V_17 )
{
F_60 ( V_17 -> V_72 , V_73 , sizeof( V_73 ) ) ;
F_60 ( V_17 -> V_74 , V_75 ,
sizeof( V_75 ) ) ;
}
static bool F_61 ( struct V_14 * V_15 ,
struct V_13 T_2 * V_17 ,
struct V_76 * V_77 )
{
T_4 V_78 , V_79 , V_80 , V_81 ;
#define F_62 12
#define F_63 0xfff
bool V_82 = false ;
int V_83 = F_54 ( V_77 -> V_62 ) ;
int V_84 = F_55 ( V_77 -> V_62 ) ;
if ( V_77 -> V_85 > 1 )
V_78 = ( ( V_77 -> V_86 - 1 ) << F_62 )
/ ( V_77 -> V_85 ) ;
else
V_78 = 1 << F_62 ;
if ( V_77 -> V_87 > 1 )
V_79 = ( ( V_77 -> V_88 - 1 ) << F_62 )
/ ( V_77 -> V_87 ) ;
else
V_79 = 1 << F_62 ;
V_80 = V_78 / V_83 ;
V_81 = V_79 / V_84 ;
V_78 = V_80 * V_83 ;
V_79 = V_81 * V_84 ;
if ( V_78 != V_15 -> V_60 || V_79 != V_15 -> V_61 )
V_82 = true ;
V_15 -> V_60 = V_78 ;
V_15 -> V_61 = V_79 ;
F_64 ( ( ( V_79 & F_63 ) << 20 ) |
( ( V_78 >> F_62 ) << 16 ) |
( ( V_78 & F_63 ) << 3 ) ,
& V_17 -> V_89 ) ;
F_64 ( ( ( V_81 & F_63 ) << 20 ) |
( ( V_80 >> F_62 ) << 16 ) |
( ( V_80 & F_63 ) << 3 ) ,
& V_17 -> V_90 ) ;
F_64 ( ( ( ( V_79 >> F_62 ) << 16 ) |
( ( V_81 >> F_62 ) << 0 ) ) ,
& V_17 -> V_91 ) ;
if ( V_82 )
F_59 ( V_17 ) ;
return V_82 ;
}
static void F_65 ( struct V_14 * V_15 ,
struct V_13 T_2 * V_17 )
{
const struct V_92 * V_93 =
F_66 ( V_15 -> V_49 -> V_94 . V_95 -> V_93 ) ;
T_4 V_96 = V_15 -> V_97 ;
T_4 V_62 = 0 ;
T_4 V_98 = 0 ;
if ( V_15 -> V_99 )
V_98 |= V_100 ;
if ( V_93 -> V_94 . V_101 )
V_62 = V_93 -> V_94 . V_102 -> V_62 -> V_62 ;
switch ( V_62 ) {
case V_103 :
V_96 = 0 ;
V_98 |= V_104 ;
break;
case V_105 :
V_96 = F_67 ( V_96 ) ;
V_98 |= V_106 ;
break;
case V_107 :
V_96 = F_68 ( V_96 ) ;
V_98 |= V_108 ;
break;
default:
V_98 |= V_109 ;
break;
}
F_64 ( V_96 , & V_17 -> V_110 ) ;
F_64 ( V_98 , & V_17 -> V_111 ) ;
}
static T_4 F_69 ( struct V_76 * V_77 )
{
T_4 V_112 = V_113 | V_114 | V_115 ;
if ( V_77 -> V_62 & V_116 ) {
switch ( V_77 -> V_62 & V_63 ) {
case V_64 :
V_112 |= V_117 ;
break;
case V_68 :
V_112 |= V_118 ;
break;
case V_65 :
case V_69 :
V_112 |= V_119 ;
break;
}
} else {
switch ( V_77 -> V_62 & V_63 ) {
case V_64 :
V_112 |= V_120 ;
break;
case V_65 :
V_112 |= V_121 ;
break;
}
switch ( V_77 -> V_62 & V_122 ) {
case V_123 :
break;
case V_124 :
V_112 |= V_125 ;
break;
case V_126 :
V_112 |= V_127 ;
break;
case V_128 :
V_112 |= V_129 ;
break;
}
}
return V_112 ;
}
static int F_70 ( struct V_14 * V_15 ,
struct V_130 * V_131 ,
struct V_76 * V_77 )
{
int V_36 , V_132 ;
struct V_13 T_2 * V_17 ;
bool V_82 = false ;
struct V_1 * V_2 = V_15 -> V_16 ;
T_4 V_133 , V_134 , V_135 , V_136 ;
enum V_48 V_48 = V_15 -> V_49 -> V_48 ;
struct V_46 * V_47 ;
F_50 ( & V_2 -> V_6 . V_29 ) ;
F_22 ( ! F_71 ( & V_2 -> V_6 . V_137 . V_138 ) ) ;
V_36 = F_49 ( V_15 ) ;
if ( V_36 != 0 )
return V_36 ;
V_47 = F_72 ( V_131 , 0 , NULL ) ;
if ( F_24 ( V_47 ) )
return F_25 ( V_47 ) ;
V_36 = F_73 ( V_47 ) ;
if ( V_36 )
goto V_139;
if ( ! V_15 -> V_37 ) {
T_4 V_140 ;
V_17 = F_6 ( V_15 ) ;
if ( ! V_17 ) {
V_36 = - V_141 ;
goto V_139;
}
V_140 = V_142 ;
if ( F_74 ( V_2 ) )
V_140 |= V_143 ;
V_140 |= V_48 == 0 ?
V_144 : V_145 ;
F_64 ( V_140 , & V_17 -> V_146 ) ;
F_9 ( V_15 , V_17 ) ;
V_36 = F_21 ( V_15 ) ;
if ( V_36 != 0 )
goto V_139;
}
V_17 = F_6 ( V_15 ) ;
if ( ! V_17 ) {
V_36 = - V_141 ;
goto V_139;
}
F_64 ( ( V_77 -> V_147 << 16 ) | V_77 -> V_148 , & V_17 -> V_149 ) ;
F_64 ( ( V_77 -> V_87 << 16 ) | V_77 -> V_85 , & V_17 -> V_150 ) ;
if ( V_77 -> V_62 & V_151 )
V_132 = F_53 ( V_77 -> V_62 , V_77 -> V_152 ) ;
else
V_132 = V_77 -> V_152 ;
V_133 = V_77 -> V_152 ;
V_134 = F_56 ( V_2 , V_77 -> V_153 , V_132 ) ;
V_135 = V_77 -> V_154 ;
F_64 ( F_75 ( V_47 ) + V_77 -> V_153 , & V_17 -> V_155 ) ;
V_136 = V_77 -> V_156 ;
if ( V_77 -> V_62 & V_116 ) {
int V_83 = F_54 ( V_77 -> V_62 ) ;
int V_84 = F_55 ( V_77 -> V_62 ) ;
T_4 V_157 , V_158 ;
V_133 |= ( V_77 -> V_152 / V_83 ) << 16 ;
V_157 = F_56 ( V_2 , V_77 -> V_159 ,
V_77 -> V_152 / V_83 ) ;
V_158 = F_56 ( V_2 , V_77 -> V_160 ,
V_77 -> V_152 / V_83 ) ;
V_134 |= F_76 ( T_4 , V_157 , V_158 ) << 16 ;
V_135 |= ( V_77 -> V_154 / V_84 ) << 16 ;
F_64 ( F_75 ( V_47 ) + V_77 -> V_159 ,
& V_17 -> V_161 ) ;
F_64 ( F_75 ( V_47 ) + V_77 -> V_160 ,
& V_17 -> V_162 ) ;
V_136 |= V_77 -> V_163 << 16 ;
}
F_64 ( V_133 , & V_17 -> V_164 ) ;
F_64 ( V_134 , & V_17 -> V_165 ) ;
F_64 ( V_135 , & V_17 -> V_166 ) ;
F_64 ( V_136 , & V_17 -> V_167 ) ;
V_82 = F_61 ( V_15 , V_17 , V_77 ) ;
F_65 ( V_15 , V_17 ) ;
F_64 ( F_69 ( V_77 ) , & V_17 -> V_168 ) ;
F_9 ( V_15 , V_17 ) ;
V_36 = F_35 ( V_15 , V_47 , V_82 ) ;
if ( V_36 )
goto V_139;
return 0 ;
V_139:
F_41 ( V_47 ) ;
return V_36 ;
}
int F_77 ( struct V_14 * V_15 )
{
struct V_1 * V_2 = V_15 -> V_16 ;
struct V_13 T_2 * V_17 ;
int V_36 ;
F_50 ( & V_2 -> V_6 . V_29 ) ;
F_22 ( ! F_71 ( & V_2 -> V_6 . V_137 . V_138 ) ) ;
V_36 = F_48 ( V_15 ) ;
if ( V_36 != 0 )
return V_36 ;
if ( ! V_15 -> V_37 )
return 0 ;
V_36 = F_49 ( V_15 ) ;
if ( V_36 != 0 )
return V_36 ;
V_17 = F_6 ( V_15 ) ;
F_64 ( 0 , & V_17 -> V_168 ) ;
F_9 ( V_15 , V_17 ) ;
return F_47 ( V_15 ) ;
}
static int F_78 ( struct V_14 * V_15 ,
struct V_169 * V_49 )
{
if ( ! V_49 -> V_37 )
return - V_66 ;
if ( V_49 -> V_170 -> V_171 )
return - V_66 ;
return 0 ;
}
static void F_79 ( struct V_14 * V_15 )
{
struct V_1 * V_2 = V_15 -> V_16 ;
T_4 V_172 = F_36 ( V_173 ) ;
T_4 V_174 ;
if ( F_80 ( V_2 ) >= 4 ) {
V_174 = F_36 ( V_175 ) >> V_176 ;
} else {
if ( V_172 & V_177 )
V_174 = F_36 ( V_178 ) ;
else
V_174 = F_36 ( V_175 ) ;
V_174 >>= V_179 ;
}
V_15 -> V_180 = V_174 ;
}
static int F_81 ( struct V_14 * V_15 ,
struct V_181 * V_182 )
{
const struct V_183 * V_184 =
V_15 -> V_49 -> V_170 ;
if ( V_182 -> V_148 < V_184 -> V_185 &&
V_182 -> V_148 + V_182 -> V_186 <= V_184 -> V_185 &&
V_182 -> V_147 < V_184 -> V_187 &&
V_182 -> V_147 + V_182 -> V_188 <= V_184 -> V_187 )
return 0 ;
else
return - V_66 ;
}
static int F_82 ( struct V_76 * V_182 )
{
T_4 V_53 ;
V_53 = ( ( V_182 -> V_88 << 16 ) / V_182 -> V_87 ) >> 16 ;
if ( V_53 > 7 )
return - V_66 ;
V_53 = ( ( V_182 -> V_86 << 16 ) / V_182 -> V_85 ) >> 16 ;
if ( V_53 > 7 )
return - V_66 ;
return 0 ;
}
static int F_83 ( struct V_1 * V_2 ,
struct V_181 * V_182 ,
struct V_130 * V_131 )
{
int V_83 = F_54 ( V_182 -> V_98 ) ;
int V_84 = F_55 ( V_182 -> V_98 ) ;
T_4 V_189 ;
int V_190 ;
T_4 V_53 ;
if ( F_84 ( V_2 ) || F_23 ( V_2 ) ) {
if ( V_182 -> V_191 > V_192 ||
V_182 -> V_193 > V_194 )
return - V_66 ;
} else {
if ( V_182 -> V_191 > V_195 ||
V_182 -> V_193 > V_196 )
return - V_66 ;
}
if ( V_182 -> V_191 < V_197 * 4 ||
V_182 -> V_193 < V_198 * 4 )
return - V_66 ;
switch ( V_182 -> V_98 & V_199 ) {
case V_200 :
return - V_66 ;
case V_151 :
if ( V_84 != 1 )
return - V_66 ;
V_190 = F_52 ( V_182 -> V_98 ) ;
if ( V_190 < 0 )
return V_190 ;
V_182 -> V_163 = 0 ;
V_182 -> V_159 = 0 ;
V_182 -> V_160 = 0 ;
if ( V_182 -> V_153 % V_190 )
return - V_66 ;
break;
case V_116 :
if ( V_84 < 0 || V_83 < 0 )
return - V_66 ;
break;
default:
return - V_66 ;
}
if ( V_182 -> V_193 % V_83 )
return - V_66 ;
if ( F_23 ( V_2 ) || F_84 ( V_2 ) )
V_189 = 255 ;
else
V_189 = 63 ;
if ( V_182 -> V_156 & V_189 || V_182 -> V_163 & V_189 )
return - V_66 ;
if ( F_74 ( V_2 ) && V_182 -> V_156 < 512 )
return - V_66 ;
V_53 = ( V_182 -> V_98 & V_199 ) == V_116 ?
4096 : 8192 ;
if ( V_182 -> V_156 > V_53 || V_182 -> V_163 > 2 * 1024 )
return - V_66 ;
switch ( V_182 -> V_98 & V_199 ) {
case V_200 :
case V_151 :
if ( F_53 ( V_182 -> V_98 , V_182 -> V_193 ) > V_182 -> V_156 )
return - V_66 ;
V_53 = V_182 -> V_156 * V_182 -> V_191 ;
if ( V_182 -> V_153 + V_53 > V_131 -> V_94 . V_201 )
return - V_66 ;
break;
case V_116 :
if ( V_182 -> V_193 > V_182 -> V_156 )
return - V_66 ;
if ( V_182 -> V_193 / V_83 > V_182 -> V_163 )
return - V_66 ;
V_53 = V_182 -> V_156 * V_182 -> V_191 ;
if ( V_182 -> V_153 + V_53 > V_131 -> V_94 . V_201 )
return - V_66 ;
V_53 = V_182 -> V_163 * ( V_182 -> V_191 / V_84 ) ;
if ( V_182 -> V_159 + V_53 > V_131 -> V_94 . V_201 ||
V_182 -> V_160 + V_53 > V_131 -> V_94 . V_201 )
return - V_66 ;
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
struct V_169 * V_49 ;
struct V_130 * V_131 ;
struct V_76 * V_77 ;
int V_36 ;
V_15 = V_2 -> V_15 ;
if ( ! V_15 ) {
F_37 ( L_2 ) ;
return - V_210 ;
}
if ( ! ( V_207 -> V_98 & V_211 ) ) {
F_87 ( V_203 ) ;
F_88 ( & V_203 -> V_29 ) ;
V_36 = F_77 ( V_15 ) ;
F_89 ( & V_203 -> V_29 ) ;
F_90 ( V_203 ) ;
return V_36 ;
}
V_77 = F_91 ( sizeof( * V_77 ) , V_212 ) ;
if ( ! V_77 )
return - V_141 ;
V_209 = F_92 ( V_203 , V_207 -> V_213 ) ;
if ( ! V_209 ) {
V_36 = - V_214 ;
goto V_215;
}
V_49 = F_93 ( V_209 ) ;
V_131 = F_94 ( V_206 , V_207 -> V_216 ) ;
if ( ! V_131 ) {
V_36 = - V_214 ;
goto V_215;
}
F_87 ( V_203 ) ;
F_88 ( & V_203 -> V_29 ) ;
if ( F_95 ( V_131 ) ) {
F_96 ( L_3 ) ;
V_36 = - V_66 ;
goto V_217;
}
V_36 = F_48 ( V_15 ) ;
if ( V_36 != 0 )
goto V_217;
if ( V_15 -> V_49 != V_49 ) {
V_36 = F_77 ( V_15 ) ;
if ( V_36 != 0 )
goto V_217;
V_36 = F_78 ( V_15 , V_49 ) ;
if ( V_36 != 0 )
goto V_217;
V_15 -> V_49 = V_49 ;
V_49 -> V_15 = V_15 ;
if ( V_49 -> V_170 -> V_185 > 1024 &&
V_49 -> V_170 -> V_218 . V_219 & V_220 ) {
V_15 -> V_221 = true ;
F_79 ( V_15 ) ;
} else
V_15 -> V_221 = false ;
}
V_36 = F_81 ( V_15 , V_207 ) ;
if ( V_36 != 0 )
goto V_217;
if ( V_15 -> V_221 ) {
V_77 -> V_147 = ( ( ( ( T_4 ) V_207 -> V_147 ) << 12 ) /
V_15 -> V_180 ) ;
V_77 -> V_87 = ( ( ( ( T_4 ) V_207 -> V_188 ) << 12 ) /
V_15 -> V_180 ) + 1 ;
} else {
V_77 -> V_147 = V_207 -> V_147 ;
V_77 -> V_87 = V_207 -> V_188 ;
}
V_77 -> V_148 = V_207 -> V_148 ;
V_77 -> V_85 = V_207 -> V_186 ;
V_77 -> V_152 = V_207 -> V_193 ;
V_77 -> V_154 = V_207 -> V_191 ;
V_77 -> V_86 = V_207 -> V_222 ;
V_77 -> V_88 = V_207 -> V_223 ;
if ( V_77 -> V_88 > V_77 -> V_154 ||
V_77 -> V_86 > V_77 -> V_152 ) {
V_36 = - V_66 ;
goto V_217;
}
V_36 = F_83 ( V_2 , V_207 , V_131 ) ;
if ( V_36 != 0 )
goto V_217;
V_77 -> V_62 = V_207 -> V_98 & ~ V_224 ;
V_77 -> V_156 = V_207 -> V_156 ;
V_77 -> V_163 = V_207 -> V_163 ;
V_77 -> V_153 = V_207 -> V_153 ;
V_77 -> V_159 = V_207 -> V_159 ;
V_77 -> V_160 = V_207 -> V_160 ;
V_36 = F_82 ( V_77 ) ;
if ( V_36 != 0 )
goto V_217;
V_36 = F_70 ( V_15 , V_131 , V_77 ) ;
if ( V_36 != 0 )
goto V_217;
F_89 ( & V_203 -> V_29 ) ;
F_90 ( V_203 ) ;
F_97 ( V_131 ) ;
F_98 ( V_77 ) ;
return 0 ;
V_217:
F_89 ( & V_203 -> V_29 ) ;
F_90 ( V_203 ) ;
F_97 ( V_131 ) ;
V_215:
F_98 ( V_77 ) ;
return V_36 ;
}
static void F_99 ( struct V_14 * V_15 ,
struct V_13 T_2 * V_17 )
{
F_64 ( ( V_15 -> V_225 << 18 ) | ( V_15 -> V_226 & 0xff ) ,
& V_17 -> V_227 ) ;
F_64 ( V_15 -> V_228 , & V_17 -> V_229 ) ;
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
return - V_66 ;
if ( ! F_101 ( V_235 -> V_233 ) )
return - V_66 ;
return 0 ;
}
int F_103 ( struct V_202 * V_203 , void * V_204 ,
struct V_205 * V_206 )
{
struct V_234 * V_235 = V_204 ;
struct V_1 * V_2 = F_86 ( V_203 ) ;
struct V_14 * V_15 ;
struct V_13 T_2 * V_17 ;
int V_36 ;
V_15 = V_2 -> V_15 ;
if ( ! V_15 ) {
F_37 ( L_2 ) ;
return - V_210 ;
}
F_87 ( V_203 ) ;
F_88 ( & V_203 -> V_29 ) ;
V_36 = - V_66 ;
if ( ! ( V_235 -> V_98 & V_239 ) ) {
V_235 -> V_97 = V_15 -> V_97 ;
V_235 -> V_226 = V_15 -> V_226 ;
V_235 -> V_225 = V_15 -> V_225 ;
V_235 -> V_228 = V_15 -> V_228 ;
if ( ! F_57 ( V_2 ) ) {
V_235 -> V_236 = F_36 ( V_240 ) ;
V_235 -> V_230 = F_36 ( V_241 ) ;
V_235 -> V_231 = F_36 ( V_242 ) ;
V_235 -> V_237 = F_36 ( V_243 ) ;
V_235 -> V_238 = F_36 ( V_244 ) ;
V_235 -> V_233 = F_36 ( V_245 ) ;
}
} else {
if ( V_235 -> V_226 < - 128 || V_235 -> V_226 > 127 )
goto V_217;
if ( V_235 -> V_225 > 255 )
goto V_217;
if ( V_235 -> V_228 > 1023 )
goto V_217;
V_15 -> V_97 = V_235 -> V_97 ;
V_15 -> V_226 = V_235 -> V_226 ;
V_15 -> V_225 = V_235 -> V_225 ;
V_15 -> V_228 = V_235 -> V_228 ;
V_17 = F_6 ( V_15 ) ;
if ( ! V_17 ) {
V_36 = - V_141 ;
goto V_217;
}
F_99 ( V_15 , V_17 ) ;
F_9 ( V_15 , V_17 ) ;
if ( V_235 -> V_98 & V_246 ) {
if ( F_57 ( V_2 ) )
goto V_217;
if ( V_15 -> V_37 ) {
V_36 = - V_247 ;
goto V_217;
}
V_36 = F_102 ( V_235 ) ;
if ( V_36 )
goto V_217;
F_2 ( V_240 , V_235 -> V_236 ) ;
F_2 ( V_241 , V_235 -> V_230 ) ;
F_2 ( V_242 , V_235 -> V_231 ) ;
F_2 ( V_243 , V_235 -> V_237 ) ;
F_2 ( V_244 , V_235 -> V_238 ) ;
F_2 ( V_245 , V_235 -> V_233 ) ;
}
}
V_15 -> V_99 = ( V_235 -> V_98 & V_248 ) == 0 ;
V_36 = 0 ;
V_217:
F_89 ( & V_203 -> V_29 ) ;
F_90 ( V_203 ) ;
return V_36 ;
}
void F_104 ( struct V_1 * V_2 )
{
struct V_14 * V_15 ;
struct V_130 * V_18 ;
struct V_13 T_2 * V_17 ;
struct V_46 * V_47 = NULL ;
int V_36 ;
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
if ( F_24 ( V_18 ) )
goto V_215;
V_15 -> V_18 = V_18 ;
if ( F_7 ( V_2 ) ) {
V_36 = F_109 ( V_18 , V_24 ) ;
if ( V_36 ) {
F_110 ( L_4 ) ;
goto V_249;
}
V_15 -> V_23 = V_18 -> V_19 -> V_250 ;
} else {
V_47 = F_111 ( V_18 , NULL ,
0 , V_24 , V_251 ) ;
if ( F_24 ( V_47 ) ) {
F_110 ( L_5 ) ;
V_36 = F_25 ( V_47 ) ;
goto V_249;
}
V_15 -> V_23 = F_75 ( V_47 ) ;
V_36 = F_112 ( V_18 , true ) ;
if ( V_36 ) {
F_110 ( L_6 ) ;
goto V_252;
}
}
V_15 -> V_97 = 0x0101fe ;
V_15 -> V_99 = true ;
V_15 -> V_226 = - 19 ;
V_15 -> V_225 = 75 ;
V_15 -> V_228 = 146 ;
F_113 ( & V_15 -> V_28 , NULL ) ;
V_17 = F_6 ( V_15 ) ;
if ( ! V_17 )
goto V_252;
F_114 ( V_17 , 0 , sizeof( struct V_13 ) ) ;
F_59 ( V_17 ) ;
F_99 ( V_15 , V_17 ) ;
F_9 ( V_15 , V_17 ) ;
V_2 -> V_15 = V_15 ;
F_89 ( & V_2 -> V_6 . V_29 ) ;
F_115 ( L_7 ) ;
return;
V_252:
if ( V_47 )
F_116 ( V_47 ) ;
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
F_22 ( V_2 -> V_15 -> V_37 ) ;
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
if ( ! V_15 || ! V_15 -> V_37 )
return NULL ;
error = F_91 ( sizeof( * error ) , V_254 ) ;
if ( error == NULL )
return NULL ;
error -> V_255 = F_36 ( V_54 ) ;
error -> V_256 = F_36 ( V_58 ) ;
error -> V_94 = V_15 -> V_23 ;
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
error -> V_94 ) ;
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
F_126 ( V_89 ) ;
F_126 ( V_90 ) ;
F_126 ( V_227 ) ;
F_126 ( V_229 ) ;
F_126 ( V_110 ) ;
F_126 ( V_111 ) ;
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
F_126 ( V_91 ) ;
#undef F_126
}
