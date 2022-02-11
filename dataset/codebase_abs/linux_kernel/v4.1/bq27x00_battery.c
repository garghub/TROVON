static inline int F_1 ( struct V_1 * V_2 , T_1 V_3 ,
bool V_4 )
{
if ( V_2 -> V_5 == V_6 )
return V_2 -> V_7 . V_8 ( V_2 , V_3 - V_9 , V_4 ) ;
return V_2 -> V_7 . V_8 ( V_2 , V_3 , V_4 ) ;
}
static bool F_2 ( struct V_1 * V_2 )
{
if ( V_2 -> V_5 == V_6 || V_2 -> V_5 == V_10 || V_2 -> V_5 == V_11
|| V_2 -> V_5 == V_12 )
return true ;
return false ;
}
static int F_3 ( struct V_1 * V_2 )
{
int V_13 ;
if ( V_2 -> V_5 == V_10 || V_2 -> V_5 == V_11 )
V_13 = F_1 ( V_2 , V_14 , false ) ;
else if ( V_2 -> V_5 == V_12 )
V_13 = F_1 ( V_2 , V_15 , false ) ;
else if ( V_2 -> V_5 == V_6 )
V_13 = F_1 ( V_2 , V_16 , false ) ;
else
V_13 = F_1 ( V_2 , V_17 , true ) ;
if ( V_13 < 0 )
F_4 ( V_2 -> V_18 , L_1 ) ;
return V_13 ;
}
static int F_5 ( struct V_1 * V_2 , T_1 V_3 )
{
int V_19 ;
V_19 = F_1 ( V_2 , V_3 , false ) ;
if ( V_19 < 0 ) {
F_4 ( V_2 -> V_18 , L_2 ,
V_3 , V_19 ) ;
return V_19 ;
}
if ( F_2 ( V_2 ) )
V_19 *= 1000 ;
else
V_19 = V_19 * 3570 / V_20 ;
return V_19 ;
}
static inline int F_6 ( struct V_1 * V_2 )
{
int V_21 ;
bool V_22 = V_2 -> V_5 == V_10 ;
bool V_23 = V_2 -> V_5 == V_11 ;
bool V_24 = F_2 ( V_2 ) ;
bool V_25 = ! ( V_22 || V_23 ) ;
V_21 = F_1 ( V_2 , V_26 , V_25 ) ;
if ( V_21 >= 0 && ! V_24 && ( V_21 & V_27 ) )
return - V_28 ;
return F_5 ( V_2 , V_29 ) ;
}
static inline int F_7 ( struct V_1 * V_2 )
{
return F_5 ( V_2 , V_30 ) ;
}
static int F_8 ( struct V_1 * V_2 )
{
int V_31 ;
if ( F_2 ( V_2 ) ) {
if ( V_2 -> V_5 == V_6 )
V_31 = F_1 ( V_2 , V_32 , false ) ;
else if ( V_2 -> V_5 == V_12 )
V_31 = F_1 ( V_2 , V_33 , false ) ;
else
V_31 = F_1 ( V_2 , V_34 , false ) ;
} else
V_31 = F_1 ( V_2 , V_35 , true ) ;
if ( V_31 < 0 ) {
F_4 ( V_2 -> V_18 , L_3 ) ;
return V_31 ;
}
if ( F_2 ( V_2 ) )
V_31 *= 1000 ;
else
V_31 = V_31 * 256 * 3570 / V_20 ;
return V_31 ;
}
static int F_9 ( struct V_1 * V_2 )
{
int V_36 ;
V_36 = F_1 ( V_2 , V_37 , false ) ;
if ( V_36 < 0 ) {
F_4 ( V_2 -> V_18 , L_4 ) ;
return V_36 ;
}
if ( V_2 -> V_5 == V_10 )
V_36 *= 1000 ;
else
V_36 = V_36 * 29200 / V_20 ;
return V_36 ;
}
static int F_10 ( struct V_1 * V_2 )
{
int V_38 ;
V_38 = F_1 ( V_2 , V_39 , false ) ;
if ( V_38 < 0 ) {
F_11 ( V_2 -> V_18 , L_5 ) ;
return V_38 ;
}
if ( ! F_2 ( V_2 ) )
V_38 = 5 * V_38 / 2 ;
return V_38 ;
}
static int F_12 ( struct V_1 * V_2 )
{
int V_40 ;
if ( V_2 -> V_5 == V_12 )
V_40 = F_1 ( V_2 , V_41 , false ) ;
else
V_40 = F_1 ( V_2 , V_42 , false ) ;
if ( V_40 < 0 )
F_11 ( V_2 -> V_18 , L_6 ) ;
return V_40 ;
}
static int F_13 ( struct V_1 * V_2 , T_1 V_3 )
{
int V_43 ;
V_43 = F_1 ( V_2 , V_3 , false ) ;
if ( V_43 < 0 ) {
F_4 ( V_2 -> V_18 , L_7 ,
V_3 , V_43 ) ;
return V_43 ;
}
if ( V_43 == 65535 )
return - V_28 ;
return V_43 * 60 ;
}
static int F_14 ( struct V_1 * V_2 , T_1 V_3 )
{
int V_43 ;
V_43 = F_1 ( V_2 , V_3 , false ) ;
if ( V_43 < 0 ) {
F_11 ( V_2 -> V_18 , L_8 ,
V_3 , V_43 ) ;
return V_43 ;
}
if ( V_2 -> V_5 == V_10 )
return V_43 ;
else
return ( V_43 * V_44 ) / V_20 ;
}
static int F_15 ( struct V_1 * V_2 )
{
int V_43 ;
V_43 = F_1 ( V_2 , V_26 , false ) ;
if ( V_43 < 0 ) {
F_11 ( V_2 -> V_18 , L_9 , V_43 ) ;
return V_43 ;
}
if ( ( V_2 -> V_5 == V_10 ) ) {
if ( V_43 & V_45 )
V_43 = V_46 ;
else if ( V_43 & V_47 )
V_43 = V_48 ;
else
V_43 = V_49 ;
return V_43 ;
} else if ( V_2 -> V_5 == V_12 ) {
if ( V_43 & V_47 )
return V_48 ;
return V_49 ;
} else {
if ( V_43 & V_50 )
V_43 = V_46 ;
else
V_43 = V_49 ;
return V_43 ;
}
return - 1 ;
}
static void F_16 ( struct V_1 * V_2 )
{
struct V_51 V_52 = { 0 , } ;
bool V_22 = V_2 -> V_5 == V_10 ;
bool V_53 = V_2 -> V_5 == V_12 ;
bool V_54 = V_2 -> V_5 == V_6 ;
bool V_23 = V_2 -> V_5 == V_11 ;
bool V_25 = ! ( V_22 || V_23 ) ;
V_52 . V_21 = F_1 ( V_2 , V_26 , V_25 ) ;
if ( ( V_52 . V_21 & 0xff ) == 0xff )
V_52 . V_21 = - 1 ;
if ( V_52 . V_21 >= 0 ) {
if ( ! V_22 && ! V_54 && ! V_23 && ! V_53
&& ( V_52 . V_21 & V_27 ) ) {
F_17 ( V_2 -> V_18 , L_10 ) ;
V_52 . V_55 = - V_28 ;
V_52 . V_56 = - V_28 ;
V_52 . V_57 = - V_28 ;
V_52 . V_58 = - V_28 ;
V_52 . V_59 = - V_28 ;
V_52 . V_60 = - V_28 ;
V_52 . V_61 = - V_28 ;
} else {
V_52 . V_55 = F_3 ( V_2 ) ;
if ( V_23 || V_53 )
V_52 . V_57 =
F_13 ( V_2 ,
V_62 ) ;
else if ( ! V_54 ) {
V_52 . V_56 = F_9 ( V_2 ) ;
V_52 . V_57 =
F_13 ( V_2 ,
V_62 ) ;
V_52 . V_58 =
F_13 ( V_2 ,
V_63 ) ;
V_52 . V_59 =
F_13 ( V_2 ,
V_64 ) ;
}
V_52 . V_60 = F_7 ( V_2 ) ;
V_52 . V_61 = F_15 ( V_2 ) ;
}
V_52 . V_65 = F_10 ( V_2 ) ;
if ( ! V_54 )
V_52 . V_66 = F_12 ( V_2 ) ;
if ( V_23 )
V_52 . V_67 =
F_14 ( V_2 ,
V_68 ) ;
else
V_52 . V_67 =
F_14 ( V_2 ,
V_69 ) ;
if ( V_2 -> V_70 <= 0 )
V_2 -> V_70 = F_8 ( V_2 ) ;
}
if ( V_2 -> V_52 . V_55 != V_52 . V_55 )
F_18 ( V_2 -> V_71 ) ;
if ( memcmp ( & V_2 -> V_52 , & V_52 , sizeof( V_52 ) ) != 0 )
V_2 -> V_52 = V_52 ;
V_2 -> V_72 = V_73 ;
}
static void F_19 ( struct V_74 * V_75 )
{
struct V_1 * V_2 =
F_20 ( V_75 , struct V_1 , V_75 . V_75 ) ;
F_16 ( V_2 ) ;
if ( V_76 > 0 ) {
F_21 ( & V_2 -> V_75 . V_77 , V_76 * V_78 / 4 ) ;
F_22 ( & V_2 -> V_75 , V_76 * V_78 ) ;
}
}
static int F_23 ( struct V_1 * V_2 ,
union V_79 * V_80 )
{
int V_81 ;
int V_21 ;
V_81 = F_1 ( V_2 , V_82 , false ) ;
if ( V_81 < 0 ) {
F_11 ( V_2 -> V_18 , L_11 ) ;
return V_81 ;
}
if ( F_2 ( V_2 ) ) {
V_80 -> V_83 = ( int ) ( ( V_84 ) V_81 ) * 1000 ;
} else {
V_21 = F_1 ( V_2 , V_26 , false ) ;
if ( V_21 & V_85 ) {
F_4 ( V_2 -> V_18 , L_12 ) ;
V_81 = - V_81 ;
}
V_80 -> V_83 = V_81 * 3570 / V_20 ;
}
return 0 ;
}
static int F_24 ( struct V_1 * V_2 ,
union V_79 * V_80 )
{
int V_86 ;
if ( F_2 ( V_2 ) ) {
if ( V_2 -> V_52 . V_21 & V_87 )
V_86 = V_88 ;
else if ( V_2 -> V_52 . V_21 & V_89 )
V_86 = V_90 ;
else
V_86 = V_91 ;
} else {
if ( V_2 -> V_52 . V_21 & V_92 )
V_86 = V_88 ;
else if ( V_2 -> V_52 . V_21 & V_85 )
V_86 = V_91 ;
else if ( F_25 ( V_2 -> V_71 ) )
V_86 = V_93 ;
else
V_86 = V_90 ;
}
V_80 -> V_83 = V_86 ;
return 0 ;
}
static int F_26 ( struct V_1 * V_2 ,
union V_79 * V_80 )
{
int V_94 ;
if ( F_2 ( V_2 ) ) {
if ( V_2 -> V_52 . V_21 & V_87 )
V_94 = V_95 ;
else if ( V_2 -> V_52 . V_21 & V_96 )
V_94 = V_97 ;
else if ( V_2 -> V_52 . V_21 & V_45 )
V_94 = V_98 ;
else
V_94 = V_99 ;
} else {
if ( V_2 -> V_52 . V_21 & V_92 )
V_94 = V_95 ;
else if ( V_2 -> V_52 . V_21 & V_50 )
V_94 = V_97 ;
else if ( V_2 -> V_52 . V_21 & V_100 )
V_94 = V_98 ;
else
V_94 = V_99 ;
}
V_80 -> V_83 = V_94 ;
return 0 ;
}
static int F_27 ( struct V_1 * V_2 ,
union V_79 * V_80 )
{
int V_101 ;
V_101 = F_1 ( V_2 , V_102 , false ) ;
if ( V_101 < 0 ) {
F_11 ( V_2 -> V_18 , L_13 ) ;
return V_101 ;
}
V_80 -> V_83 = V_101 * 1000 ;
return 0 ;
}
static int F_28 ( int V_103 ,
union V_79 * V_80 )
{
if ( V_103 < 0 )
return V_103 ;
V_80 -> V_83 = V_103 ;
return 0 ;
}
static int F_29 ( struct V_104 * V_105 ,
enum V_106 V_107 ,
union V_79 * V_80 )
{
int V_108 = 0 ;
struct V_1 * V_2 = F_30 ( V_105 ) ;
F_31 ( & V_2 -> V_109 ) ;
if ( F_32 ( V_2 -> V_72 + 5 * V_78 ) ) {
F_33 ( & V_2 -> V_75 ) ;
F_19 ( & V_2 -> V_75 . V_75 ) ;
}
F_34 ( & V_2 -> V_109 ) ;
if ( V_107 != V_110 && V_2 -> V_52 . V_21 < 0 )
return - V_111 ;
switch ( V_107 ) {
case V_112 :
V_108 = F_24 ( V_2 , V_80 ) ;
break;
case V_113 :
V_108 = F_27 ( V_2 , V_80 ) ;
break;
case V_110 :
V_80 -> V_83 = V_2 -> V_52 . V_21 < 0 ? 0 : 1 ;
break;
case V_114 :
V_108 = F_23 ( V_2 , V_80 ) ;
break;
case V_115 :
V_108 = F_28 ( V_2 -> V_52 . V_55 , V_80 ) ;
break;
case V_116 :
V_108 = F_26 ( V_2 , V_80 ) ;
break;
case V_117 :
V_108 = F_28 ( V_2 -> V_52 . V_65 , V_80 ) ;
if ( V_108 == 0 )
V_80 -> V_83 -= 2731 ;
break;
case V_118 :
V_108 = F_28 ( V_2 -> V_52 . V_57 , V_80 ) ;
break;
case V_119 :
V_108 = F_28 ( V_2 -> V_52 . V_58 , V_80 ) ;
break;
case V_120 :
V_108 = F_28 ( V_2 -> V_52 . V_59 , V_80 ) ;
break;
case V_121 :
V_80 -> V_83 = V_122 ;
break;
case V_123 :
V_108 = F_28 ( F_6 ( V_2 ) , V_80 ) ;
break;
case V_124 :
V_108 = F_28 ( V_2 -> V_52 . V_60 , V_80 ) ;
break;
case V_125 :
V_108 = F_28 ( V_2 -> V_70 , V_80 ) ;
break;
case V_126 :
V_108 = F_28 ( V_2 -> V_52 . V_66 , V_80 ) ;
break;
case V_127 :
V_108 = F_28 ( V_2 -> V_52 . V_56 , V_80 ) ;
break;
case V_128 :
V_108 = F_28 ( V_2 -> V_52 . V_67 , V_80 ) ;
break;
case V_129 :
V_108 = F_28 ( V_2 -> V_52 . V_61 , V_80 ) ;
break;
default:
return - V_130 ;
}
return V_108 ;
}
static void F_35 ( struct V_104 * V_105 )
{
struct V_1 * V_2 = F_30 ( V_105 ) ;
F_33 ( & V_2 -> V_75 ) ;
F_22 ( & V_2 -> V_75 , 0 ) ;
}
static int F_36 ( struct V_1 * V_2 ,
const char * V_131 )
{
int V_108 ;
struct V_132 * V_133 ;
struct V_134 V_135 = { . V_136 = V_2 , } ;
V_133 = F_37 ( V_2 -> V_18 , sizeof( * V_133 ) , V_137 ) ;
if ( ! V_133 )
return - V_138 ;
V_133 -> V_131 = V_131 ;
V_133 -> type = V_139 ;
if ( V_2 -> V_5 == V_6 ) {
V_133 -> V_140 = V_141 ;
V_133 -> V_142 = F_38 ( V_141 ) ;
} else if ( V_2 -> V_5 == V_11 ) {
V_133 -> V_140 = V_143 ;
V_133 -> V_142 = F_38 ( V_143 ) ;
} else if ( V_2 -> V_5 == V_12 ) {
V_133 -> V_140 = V_144 ;
V_133 -> V_142 = F_38 ( V_144 ) ;
} else {
V_133 -> V_140 = V_145 ;
V_133 -> V_142 = F_38 ( V_145 ) ;
}
V_133 -> V_146 = F_29 ;
V_133 -> V_147 = F_35 ;
F_39 ( & V_2 -> V_75 , F_19 ) ;
F_40 ( & V_2 -> V_109 ) ;
V_2 -> V_71 = F_41 ( V_2 -> V_18 , V_133 , & V_135 ) ;
if ( F_42 ( V_2 -> V_71 ) ) {
V_108 = F_43 ( V_2 -> V_71 ) ;
F_11 ( V_2 -> V_18 , L_14 , V_108 ) ;
return V_108 ;
}
F_17 ( V_2 -> V_18 , L_15 , V_148 ) ;
F_16 ( V_2 ) ;
return 0 ;
}
static void F_44 ( struct V_1 * V_2 )
{
V_76 = 0 ;
F_33 ( & V_2 -> V_75 ) ;
F_45 ( V_2 -> V_71 ) ;
F_46 ( & V_2 -> V_109 ) ;
}
static int F_47 ( struct V_1 * V_2 , T_1 V_3 , bool V_4 )
{
struct V_149 * V_150 = F_48 ( V_2 -> V_18 ) ;
struct V_151 V_152 [ 2 ] ;
unsigned char V_153 [ 2 ] ;
int V_108 ;
if ( ! V_150 -> V_154 )
return - V_111 ;
V_152 [ 0 ] . V_155 = V_150 -> V_155 ;
V_152 [ 0 ] . V_21 = 0 ;
V_152 [ 0 ] . V_156 = & V_3 ;
V_152 [ 0 ] . V_157 = sizeof( V_3 ) ;
V_152 [ 1 ] . V_155 = V_150 -> V_155 ;
V_152 [ 1 ] . V_21 = V_158 ;
V_152 [ 1 ] . V_156 = V_153 ;
if ( V_4 )
V_152 [ 1 ] . V_157 = 1 ;
else
V_152 [ 1 ] . V_157 = 2 ;
V_108 = F_49 ( V_150 -> V_154 , V_152 , F_38 ( V_152 ) ) ;
if ( V_108 < 0 )
return V_108 ;
if ( ! V_4 )
V_108 = F_50 ( V_153 ) ;
else
V_108 = V_153 [ 0 ] ;
return V_108 ;
}
static int F_51 ( struct V_149 * V_150 ,
const struct V_159 * V_160 )
{
char * V_131 ;
struct V_1 * V_2 ;
int V_161 ;
int V_162 = 0 ;
F_31 ( & V_163 ) ;
V_161 = F_52 ( & V_164 , V_150 , 0 , 0 , V_137 ) ;
F_34 ( & V_163 ) ;
if ( V_161 < 0 )
return V_161 ;
V_131 = F_53 ( & V_150 -> V_18 , V_137 , L_16 , V_160 -> V_131 , V_161 ) ;
if ( ! V_131 ) {
F_11 ( & V_150 -> V_18 , L_17 ) ;
V_162 = - V_138 ;
goto V_165;
}
V_2 = F_37 ( & V_150 -> V_18 , sizeof( * V_2 ) , V_137 ) ;
if ( ! V_2 ) {
F_11 ( & V_150 -> V_18 , L_18 ) ;
V_162 = - V_138 ;
goto V_165;
}
V_2 -> V_160 = V_161 ;
V_2 -> V_18 = & V_150 -> V_18 ;
V_2 -> V_5 = V_160 -> V_166 ;
V_2 -> V_7 . V_8 = & F_47 ;
V_162 = F_36 ( V_2 , V_131 ) ;
if ( V_162 )
goto V_165;
F_54 ( V_150 , V_2 ) ;
return 0 ;
V_165:
F_31 ( & V_163 ) ;
F_55 ( & V_164 , V_161 ) ;
F_34 ( & V_163 ) ;
return V_162 ;
}
static int F_56 ( struct V_149 * V_150 )
{
struct V_1 * V_2 = F_57 ( V_150 ) ;
F_44 ( V_2 ) ;
F_31 ( & V_163 ) ;
F_55 ( & V_164 , V_2 -> V_160 ) ;
F_34 ( & V_163 ) ;
return 0 ;
}
static inline int F_58 ( void )
{
int V_108 = F_59 ( & V_167 ) ;
if ( V_108 )
F_60 ( V_168 L_19 ) ;
return V_108 ;
}
static inline void F_61 ( void )
{
F_62 ( & V_167 ) ;
}
static inline int F_58 ( void ) { return 0 ; }
static inline void F_61 ( void ) {}
static int F_63 ( struct V_1 * V_2 , T_1 V_3 ,
bool V_4 )
{
struct V_169 * V_18 = V_2 -> V_18 ;
struct V_170 * V_171 = V_18 -> V_172 ;
unsigned int V_173 = 3 ;
int V_174 , V_175 ;
int V_38 ;
if ( ! V_4 ) {
V_174 = V_171 -> V_8 ( V_18 , V_3 + 1 ) ;
do {
V_38 = V_174 ;
if ( V_174 < 0 )
return V_174 ;
V_175 = V_171 -> V_8 ( V_18 , V_3 ) ;
if ( V_175 < 0 )
return V_175 ;
V_174 = V_171 -> V_8 ( V_18 , V_3 + 1 ) ;
} while ( V_38 != V_174 && -- V_173 );
if ( V_173 == 0 )
return - V_176 ;
return ( V_174 << 8 ) | V_175 ;
}
return V_171 -> V_8 ( V_18 , V_3 ) ;
}
static int F_64 ( struct V_177 * V_178 )
{
struct V_1 * V_2 ;
struct V_170 * V_171 = V_178 -> V_18 . V_172 ;
const char * V_131 ;
if ( ! V_171 ) {
F_11 ( & V_178 -> V_18 , L_20 ) ;
return - V_130 ;
}
if ( ! V_171 -> V_8 ) {
F_11 ( & V_178 -> V_18 , L_21 ) ;
return - V_130 ;
}
V_2 = F_37 ( & V_178 -> V_18 , sizeof( * V_2 ) , V_137 ) ;
if ( ! V_2 ) {
F_11 ( & V_178 -> V_18 , L_18 ) ;
return - V_138 ;
}
F_65 ( V_178 , V_2 ) ;
V_2 -> V_18 = & V_178 -> V_18 ;
V_2 -> V_5 = V_179 ;
V_131 = V_171 -> V_131 ? : F_66 ( & V_178 -> V_18 ) ;
V_2 -> V_7 . V_8 = & F_63 ;
return F_36 ( V_2 , V_131 ) ;
}
static int F_67 ( struct V_177 * V_178 )
{
struct V_1 * V_2 = F_68 ( V_178 ) ;
F_44 ( V_2 ) ;
return 0 ;
}
static inline int F_69 ( void )
{
int V_108 = F_70 ( & V_180 ) ;
if ( V_108 )
F_60 ( V_168 L_22 ) ;
return V_108 ;
}
static inline void F_71 ( void )
{
F_72 ( & V_180 ) ;
}
static inline int F_69 ( void ) { return 0 ; }
static inline void F_71 ( void ) {}
static int T_2 F_73 ( void )
{
int V_108 ;
V_108 = F_58 () ;
if ( V_108 )
return V_108 ;
V_108 = F_69 () ;
if ( V_108 )
F_61 () ;
return V_108 ;
}
static void T_3 F_74 ( void )
{
F_71 () ;
F_61 () ;
}
