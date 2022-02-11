static inline int F_1 ( struct V_1 * V_2 , T_1 V_3 ,
bool V_4 )
{
if ( V_2 -> V_5 == V_6 )
return V_2 -> V_7 . V_8 ( V_2 , V_3 - V_9 , V_4 ) ;
return V_2 -> V_7 . V_8 ( V_2 , V_3 , V_4 ) ;
}
static bool F_2 ( struct V_1 * V_2 )
{
if ( V_2 -> V_5 == V_6 || V_2 -> V_5 == V_10 )
return true ;
return false ;
}
static int F_3 ( struct V_1 * V_2 )
{
int V_11 ;
if ( V_2 -> V_5 == V_10 )
V_11 = F_1 ( V_2 , V_12 , false ) ;
else if ( V_2 -> V_5 == V_6 )
V_11 = F_1 ( V_2 , V_13 , false ) ;
else
V_11 = F_1 ( V_2 , V_14 , true ) ;
if ( V_11 < 0 )
F_4 ( V_2 -> V_15 , L_1 ) ;
return V_11 ;
}
static int F_5 ( struct V_1 * V_2 , T_1 V_3 )
{
int V_16 ;
V_16 = F_1 ( V_2 , V_3 , false ) ;
if ( V_16 < 0 ) {
F_4 ( V_2 -> V_15 , L_2 ,
V_3 , V_16 ) ;
return V_16 ;
}
if ( F_2 ( V_2 ) )
V_16 *= 1000 ;
else
V_16 = V_16 * 3570 / V_17 ;
return V_16 ;
}
static inline int F_6 ( struct V_1 * V_2 )
{
return F_5 ( V_2 , V_18 ) ;
}
static inline int F_7 ( struct V_1 * V_2 )
{
return F_5 ( V_2 , V_19 ) ;
}
static int F_8 ( struct V_1 * V_2 )
{
int V_20 ;
if ( F_2 ( V_2 ) )
V_20 = F_1 ( V_2 , V_21 , false ) ;
else
V_20 = F_1 ( V_2 , V_22 , true ) ;
if ( V_20 < 0 ) {
F_4 ( V_2 -> V_15 , L_3 ) ;
return V_20 ;
}
if ( F_2 ( V_2 ) )
V_20 *= 1000 ;
else
V_20 = V_20 * 256 * 3570 / V_17 ;
return V_20 ;
}
static int F_9 ( struct V_1 * V_2 )
{
int V_23 ;
V_23 = F_1 ( V_2 , V_24 , false ) ;
if ( V_23 < 0 ) {
F_4 ( V_2 -> V_15 , L_4 ) ;
return V_23 ;
}
if ( V_2 -> V_5 == V_10 )
V_23 *= 1000 ;
else
V_23 = V_23 * 29200 / V_17 ;
return V_23 ;
}
static int F_10 ( struct V_1 * V_2 )
{
int V_25 ;
V_25 = F_1 ( V_2 , V_26 , false ) ;
if ( V_25 < 0 ) {
F_11 ( V_2 -> V_15 , L_5 ) ;
return V_25 ;
}
if ( F_2 ( V_2 ) )
V_25 -= 2731 ;
else
V_25 = ( ( V_25 * 5 ) - 5463 ) / 2 ;
return V_25 ;
}
static int F_12 ( struct V_1 * V_2 )
{
int V_27 ;
V_27 = F_1 ( V_2 , V_28 , false ) ;
if ( V_27 < 0 )
F_11 ( V_2 -> V_15 , L_6 ) ;
return V_27 ;
}
static int F_13 ( struct V_1 * V_2 , T_1 V_3 )
{
int V_29 ;
V_29 = F_1 ( V_2 , V_3 , false ) ;
if ( V_29 < 0 ) {
F_4 ( V_2 -> V_15 , L_7 ,
V_3 , V_29 ) ;
return V_29 ;
}
if ( V_29 == 65535 )
return - V_30 ;
return V_29 * 60 ;
}
static int F_14 ( struct V_1 * V_2 , T_1 V_3 )
{
int V_29 ;
V_29 = F_1 ( V_2 , V_3 , false ) ;
if ( V_29 < 0 ) {
F_11 ( V_2 -> V_15 , L_8 ,
V_3 , V_29 ) ;
return V_29 ;
}
if ( V_2 -> V_5 == V_10 )
return V_29 ;
else
return ( V_29 * V_31 ) / V_17 ;
}
static int F_15 ( struct V_1 * V_2 )
{
int V_29 ;
V_29 = F_1 ( V_2 , V_32 , false ) ;
if ( V_29 < 0 ) {
F_11 ( V_2 -> V_15 , L_9 , V_29 ) ;
return V_29 ;
}
if ( ( V_2 -> V_5 == V_10 ) ) {
if ( V_29 & V_33 )
V_29 = V_34 ;
else if ( V_29 & V_35 )
V_29 = V_36 ;
else
V_29 = V_37 ;
return V_29 ;
} else {
if ( V_29 & V_38 )
V_29 = V_34 ;
else
V_29 = V_37 ;
return V_29 ;
}
return - 1 ;
}
static void F_16 ( struct V_1 * V_2 )
{
struct V_39 V_40 = { 0 , } ;
bool V_41 = V_2 -> V_5 == V_10 ;
bool V_42 = V_2 -> V_5 == V_6 ;
V_40 . V_43 = F_1 ( V_2 , V_32 , ! V_41 ) ;
if ( V_40 . V_43 >= 0 ) {
if ( ! V_41 && ! V_42
&& ( V_40 . V_43 & V_44 ) ) {
F_17 ( V_2 -> V_15 , L_10 ) ;
V_40 . V_45 = - V_30 ;
V_40 . V_46 = - V_30 ;
V_40 . V_47 = - V_30 ;
V_40 . V_48 = - V_30 ;
V_40 . V_49 = - V_30 ;
V_40 . V_50 = - V_30 ;
V_40 . V_51 = - V_30 ;
} else {
V_40 . V_45 = F_3 ( V_2 ) ;
if ( ! V_42 ) {
V_40 . V_46 = F_9 ( V_2 ) ;
V_40 . V_47 =
F_13 ( V_2 ,
V_52 ) ;
V_40 . V_48 =
F_13 ( V_2 ,
V_53 ) ;
V_40 . V_49 =
F_13 ( V_2 ,
V_54 ) ;
}
V_40 . V_50 = F_7 ( V_2 ) ;
V_40 . V_51 = F_15 ( V_2 ) ;
}
V_40 . V_55 = F_10 ( V_2 ) ;
if ( ! V_42 )
V_40 . V_56 = F_12 ( V_2 ) ;
V_40 . V_56 = F_12 ( V_2 ) ;
V_40 . V_57 =
F_14 ( V_2 , V_58 ) ;
if ( V_2 -> V_59 <= 0 )
V_2 -> V_59 = F_8 ( V_2 ) ;
}
if ( memcmp ( & V_2 -> V_40 , & V_40 , sizeof( V_40 ) ) != 0 ) {
V_2 -> V_40 = V_40 ;
F_18 ( & V_2 -> V_60 ) ;
}
V_2 -> V_61 = V_62 ;
}
static void F_19 ( struct V_63 * V_64 )
{
struct V_1 * V_2 =
F_20 ( V_64 , struct V_1 , V_64 . V_64 ) ;
F_16 ( V_2 ) ;
if ( V_65 > 0 ) {
F_21 ( & V_2 -> V_64 . V_66 , V_65 * V_67 / 4 ) ;
F_22 ( & V_2 -> V_64 , V_65 * V_67 ) ;
}
}
static int F_23 ( struct V_1 * V_2 ,
union V_68 * V_69 )
{
int V_70 ;
int V_43 ;
V_70 = F_1 ( V_2 , V_71 , false ) ;
if ( V_70 < 0 ) {
F_11 ( V_2 -> V_15 , L_11 ) ;
return V_70 ;
}
if ( F_2 ( V_2 ) ) {
V_69 -> V_72 = ( int ) ( ( V_73 ) V_70 ) * 1000 ;
} else {
V_43 = F_1 ( V_2 , V_32 , false ) ;
if ( V_43 & V_74 ) {
F_4 ( V_2 -> V_15 , L_12 ) ;
V_70 = - V_70 ;
}
V_69 -> V_72 = V_70 * 3570 / V_17 ;
}
return 0 ;
}
static int F_24 ( struct V_1 * V_2 ,
union V_68 * V_69 )
{
int V_75 ;
if ( F_2 ( V_2 ) ) {
if ( V_2 -> V_40 . V_43 & V_76 )
V_75 = V_77 ;
else if ( V_2 -> V_40 . V_43 & V_78 )
V_75 = V_79 ;
else
V_75 = V_80 ;
} else {
if ( V_2 -> V_40 . V_43 & V_81 )
V_75 = V_77 ;
else if ( V_2 -> V_40 . V_43 & V_74 )
V_75 = V_80 ;
else if ( F_25 ( & V_2 -> V_60 ) )
V_75 = V_82 ;
else
V_75 = V_79 ;
}
V_69 -> V_72 = V_75 ;
return 0 ;
}
static int F_26 ( struct V_1 * V_2 ,
union V_68 * V_69 )
{
int V_83 ;
if ( F_2 ( V_2 ) ) {
if ( V_2 -> V_40 . V_43 & V_76 )
V_83 = V_84 ;
else if ( V_2 -> V_40 . V_43 & V_85 )
V_83 = V_86 ;
else if ( V_2 -> V_40 . V_43 & V_33 )
V_83 = V_87 ;
else
V_83 = V_88 ;
} else {
if ( V_2 -> V_40 . V_43 & V_81 )
V_83 = V_84 ;
else if ( V_2 -> V_40 . V_43 & V_38 )
V_83 = V_86 ;
else if ( V_2 -> V_40 . V_43 & V_89 )
V_83 = V_87 ;
else
V_83 = V_88 ;
}
V_69 -> V_72 = V_83 ;
return 0 ;
}
static int F_27 ( struct V_1 * V_2 ,
union V_68 * V_69 )
{
int V_90 ;
V_90 = F_1 ( V_2 , V_91 , false ) ;
if ( V_90 < 0 ) {
F_11 ( V_2 -> V_15 , L_13 ) ;
return V_90 ;
}
V_69 -> V_72 = V_90 * 1000 ;
return 0 ;
}
static int F_28 ( int V_92 ,
union V_68 * V_69 )
{
if ( V_92 < 0 )
return V_92 ;
V_69 -> V_72 = V_92 ;
return 0 ;
}
static int F_29 ( struct V_93 * V_94 ,
enum V_95 V_96 ,
union V_68 * V_69 )
{
int V_97 = 0 ;
struct V_1 * V_2 = F_30 ( V_94 ) ;
F_31 ( & V_2 -> V_98 ) ;
if ( F_32 ( V_2 -> V_61 + 5 * V_67 ) ) {
F_33 ( & V_2 -> V_64 ) ;
F_19 ( & V_2 -> V_64 . V_64 ) ;
}
F_34 ( & V_2 -> V_98 ) ;
if ( V_96 != V_99 && V_2 -> V_40 . V_43 < 0 )
return - V_100 ;
switch ( V_96 ) {
case V_101 :
V_97 = F_24 ( V_2 , V_69 ) ;
break;
case V_102 :
V_97 = F_27 ( V_2 , V_69 ) ;
break;
case V_99 :
V_69 -> V_72 = V_2 -> V_40 . V_43 < 0 ? 0 : 1 ;
break;
case V_103 :
V_97 = F_23 ( V_2 , V_69 ) ;
break;
case V_104 :
V_97 = F_28 ( V_2 -> V_40 . V_45 , V_69 ) ;
break;
case V_105 :
V_97 = F_26 ( V_2 , V_69 ) ;
break;
case V_106 :
V_97 = F_28 ( V_2 -> V_40 . V_55 , V_69 ) ;
break;
case V_107 :
V_97 = F_28 ( V_2 -> V_40 . V_47 , V_69 ) ;
break;
case V_108 :
V_97 = F_28 ( V_2 -> V_40 . V_48 , V_69 ) ;
break;
case V_109 :
V_97 = F_28 ( V_2 -> V_40 . V_49 , V_69 ) ;
break;
case V_110 :
V_69 -> V_72 = V_111 ;
break;
case V_112 :
V_97 = F_28 ( F_6 ( V_2 ) , V_69 ) ;
break;
case V_113 :
V_97 = F_28 ( V_2 -> V_40 . V_50 , V_69 ) ;
break;
case V_114 :
V_97 = F_28 ( V_2 -> V_59 , V_69 ) ;
break;
case V_115 :
V_97 = F_28 ( V_2 -> V_40 . V_56 , V_69 ) ;
break;
case V_116 :
V_97 = F_28 ( V_2 -> V_40 . V_46 , V_69 ) ;
break;
case V_117 :
V_97 = F_28 ( V_2 -> V_40 . V_57 , V_69 ) ;
break;
case V_118 :
V_97 = F_28 ( V_2 -> V_40 . V_51 , V_69 ) ;
break;
default:
return - V_119 ;
}
return V_97 ;
}
static void F_35 ( struct V_93 * V_94 )
{
struct V_1 * V_2 = F_30 ( V_94 ) ;
F_33 ( & V_2 -> V_64 ) ;
F_22 ( & V_2 -> V_64 , 0 ) ;
}
static int F_36 ( struct V_1 * V_2 )
{
int V_97 ;
V_2 -> V_60 . type = V_120 ;
V_2 -> V_5 = V_6 ;
if ( V_2 -> V_5 == V_6 ) {
V_2 -> V_60 . V_121 = V_122 ;
V_2 -> V_60 . V_123 = F_37 ( V_122 ) ;
} else {
V_2 -> V_60 . V_121 = V_124 ;
V_2 -> V_60 . V_123 = F_37 ( V_124 ) ;
}
V_2 -> V_60 . V_125 = F_29 ;
V_2 -> V_60 . V_126 = F_35 ;
F_38 ( & V_2 -> V_64 , F_19 ) ;
F_39 ( & V_2 -> V_98 ) ;
V_97 = F_40 ( V_2 -> V_15 , & V_2 -> V_60 ) ;
if ( V_97 ) {
F_11 ( V_2 -> V_15 , L_14 , V_97 ) ;
return V_97 ;
}
F_17 ( V_2 -> V_15 , L_15 , V_127 ) ;
F_16 ( V_2 ) ;
return 0 ;
}
static void F_41 ( struct V_1 * V_2 )
{
V_65 = 0 ;
F_33 ( & V_2 -> V_64 ) ;
F_42 ( & V_2 -> V_60 ) ;
F_43 ( & V_2 -> V_98 ) ;
}
static int F_44 ( struct V_1 * V_2 , T_1 V_3 , bool V_4 )
{
struct V_128 * V_129 = F_45 ( V_2 -> V_15 ) ;
struct V_130 V_131 [ 2 ] ;
unsigned char V_132 [ 2 ] ;
int V_97 ;
if ( ! V_129 -> V_133 )
return - V_100 ;
V_131 [ 0 ] . V_134 = V_129 -> V_134 ;
V_131 [ 0 ] . V_43 = 0 ;
V_131 [ 0 ] . V_135 = & V_3 ;
V_131 [ 0 ] . V_136 = sizeof( V_3 ) ;
V_131 [ 1 ] . V_134 = V_129 -> V_134 ;
V_131 [ 1 ] . V_43 = V_137 ;
V_131 [ 1 ] . V_135 = V_132 ;
if ( V_4 )
V_131 [ 1 ] . V_136 = 1 ;
else
V_131 [ 1 ] . V_136 = 2 ;
V_97 = F_46 ( V_129 -> V_133 , V_131 , F_37 ( V_131 ) ) ;
if ( V_97 < 0 )
return V_97 ;
if ( ! V_4 )
V_97 = F_47 ( V_132 ) ;
else
V_97 = V_132 [ 0 ] ;
return V_97 ;
}
static int F_48 ( struct V_128 * V_129 ,
const struct V_138 * V_139 )
{
char * V_140 ;
struct V_1 * V_2 ;
int V_141 ;
int V_142 = 0 ;
V_142 = F_49 ( & V_143 , V_144 ) ;
if ( V_142 == 0 )
return - V_145 ;
F_31 ( & V_146 ) ;
V_142 = F_50 ( & V_143 , V_129 , & V_141 ) ;
F_34 ( & V_146 ) ;
if ( V_142 < 0 )
return V_142 ;
V_140 = F_51 ( V_144 , L_16 , V_139 -> V_140 , V_141 ) ;
if ( ! V_140 ) {
F_11 ( & V_129 -> V_15 , L_17 ) ;
V_142 = - V_145 ;
goto V_147;
}
V_2 = F_52 ( sizeof( * V_2 ) , V_144 ) ;
if ( ! V_2 ) {
F_11 ( & V_129 -> V_15 , L_18 ) ;
V_142 = - V_145 ;
goto V_148;
}
V_2 -> V_139 = V_141 ;
V_2 -> V_15 = & V_129 -> V_15 ;
V_2 -> V_5 = V_139 -> V_149 ;
V_2 -> V_60 . V_140 = V_140 ;
V_2 -> V_7 . V_8 = & F_44 ;
if ( F_36 ( V_2 ) )
goto V_150;
F_53 ( V_129 , V_2 ) ;
return 0 ;
V_150:
F_54 ( V_2 ) ;
V_148:
F_54 ( V_140 ) ;
V_147:
F_31 ( & V_146 ) ;
F_55 ( & V_143 , V_141 ) ;
F_34 ( & V_146 ) ;
return V_142 ;
}
static int F_56 ( struct V_128 * V_129 )
{
struct V_1 * V_2 = F_57 ( V_129 ) ;
F_41 ( V_2 ) ;
F_54 ( V_2 -> V_60 . V_140 ) ;
F_31 ( & V_146 ) ;
F_55 ( & V_143 , V_2 -> V_139 ) ;
F_34 ( & V_146 ) ;
F_54 ( V_2 ) ;
return 0 ;
}
static inline int F_58 ( void )
{
int V_97 = F_59 ( & V_151 ) ;
if ( V_97 )
F_60 ( V_152 L_19 ) ;
return V_97 ;
}
static inline void F_61 ( void )
{
F_62 ( & V_151 ) ;
}
static inline int F_58 ( void ) { return 0 ; }
static inline void F_61 ( void ) {}
static int F_63 ( struct V_1 * V_2 , T_1 V_3 ,
bool V_4 )
{
struct V_153 * V_15 = V_2 -> V_15 ;
struct V_154 * V_155 = V_15 -> V_156 ;
unsigned int V_157 = 3 ;
int V_158 , V_159 ;
int V_25 ;
if ( ! V_4 ) {
V_158 = V_155 -> V_8 ( V_15 , V_3 + 1 ) ;
do {
V_25 = V_158 ;
if ( V_158 < 0 )
return V_158 ;
V_159 = V_155 -> V_8 ( V_15 , V_3 ) ;
if ( V_159 < 0 )
return V_159 ;
V_158 = V_155 -> V_8 ( V_15 , V_3 + 1 ) ;
} while ( V_25 != V_158 && -- V_157 );
if ( V_157 == 0 )
return - V_160 ;
return ( V_158 << 8 ) | V_159 ;
}
return V_155 -> V_8 ( V_15 , V_3 ) ;
}
static int T_2 F_64 ( struct V_161 * V_162 )
{
struct V_1 * V_2 ;
struct V_154 * V_155 = V_162 -> V_15 . V_156 ;
int V_97 ;
if ( ! V_155 ) {
F_11 ( & V_162 -> V_15 , L_20 ) ;
return - V_119 ;
}
if ( ! V_155 -> V_8 ) {
F_11 ( & V_162 -> V_15 , L_21 ) ;
return - V_119 ;
}
V_2 = F_52 ( sizeof( * V_2 ) , V_144 ) ;
if ( ! V_2 ) {
F_11 ( & V_162 -> V_15 , L_18 ) ;
return - V_145 ;
}
F_65 ( V_162 , V_2 ) ;
V_2 -> V_15 = & V_162 -> V_15 ;
V_2 -> V_5 = V_163 ;
V_2 -> V_60 . V_140 = V_155 -> V_140 ? : F_66 ( & V_162 -> V_15 ) ;
V_2 -> V_7 . V_8 = & F_63 ;
V_97 = F_36 ( V_2 ) ;
if ( V_97 )
goto V_164;
return 0 ;
V_164:
F_65 ( V_162 , NULL ) ;
F_54 ( V_2 ) ;
return V_97 ;
}
static int T_3 F_67 ( struct V_161 * V_162 )
{
struct V_1 * V_2 = F_68 ( V_162 ) ;
F_41 ( V_2 ) ;
F_65 ( V_162 , NULL ) ;
F_54 ( V_2 ) ;
return 0 ;
}
static inline int F_69 ( void )
{
int V_97 = F_70 ( & V_165 ) ;
if ( V_97 )
F_60 ( V_152 L_22 ) ;
return V_97 ;
}
static inline void F_71 ( void )
{
F_72 ( & V_165 ) ;
}
static inline int F_69 ( void ) { return 0 ; }
static inline void F_71 ( void ) {}
static int T_4 F_73 ( void )
{
int V_97 ;
V_97 = F_58 () ;
if ( V_97 )
return V_97 ;
V_97 = F_69 () ;
if ( V_97 )
F_61 () ;
return V_97 ;
}
static void T_5 F_74 ( void )
{
F_71 () ;
F_61 () ;
}
