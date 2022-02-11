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
int V_18 ;
bool V_19 = V_2 -> V_5 == V_10 ;
bool V_20 = F_2 ( V_2 ) ;
V_18 = F_1 ( V_2 , V_21 , ! V_19 ) ;
if ( V_18 >= 0 && ! V_20 && ( V_18 & V_22 ) )
return - V_23 ;
return F_5 ( V_2 , V_24 ) ;
}
static inline int F_7 ( struct V_1 * V_2 )
{
return F_5 ( V_2 , V_25 ) ;
}
static int F_8 ( struct V_1 * V_2 )
{
int V_26 ;
if ( F_2 ( V_2 ) )
V_26 = F_1 ( V_2 , V_27 , false ) ;
else
V_26 = F_1 ( V_2 , V_28 , true ) ;
if ( V_26 < 0 ) {
F_4 ( V_2 -> V_15 , L_3 ) ;
return V_26 ;
}
if ( F_2 ( V_2 ) )
V_26 *= 1000 ;
else
V_26 = V_26 * 256 * 3570 / V_17 ;
return V_26 ;
}
static int F_9 ( struct V_1 * V_2 )
{
int V_29 ;
V_29 = F_1 ( V_2 , V_30 , false ) ;
if ( V_29 < 0 ) {
F_4 ( V_2 -> V_15 , L_4 ) ;
return V_29 ;
}
if ( V_2 -> V_5 == V_10 )
V_29 *= 1000 ;
else
V_29 = V_29 * 29200 / V_17 ;
return V_29 ;
}
static int F_10 ( struct V_1 * V_2 )
{
int V_31 ;
V_31 = F_1 ( V_2 , V_32 , false ) ;
if ( V_31 < 0 ) {
F_11 ( V_2 -> V_15 , L_5 ) ;
return V_31 ;
}
if ( ! F_2 ( V_2 ) )
V_31 = 5 * V_31 / 2 ;
return V_31 ;
}
static int F_12 ( struct V_1 * V_2 )
{
int V_33 ;
V_33 = F_1 ( V_2 , V_34 , false ) ;
if ( V_33 < 0 )
F_11 ( V_2 -> V_15 , L_6 ) ;
return V_33 ;
}
static int F_13 ( struct V_1 * V_2 , T_1 V_3 )
{
int V_35 ;
V_35 = F_1 ( V_2 , V_3 , false ) ;
if ( V_35 < 0 ) {
F_4 ( V_2 -> V_15 , L_7 ,
V_3 , V_35 ) ;
return V_35 ;
}
if ( V_35 == 65535 )
return - V_23 ;
return V_35 * 60 ;
}
static int F_14 ( struct V_1 * V_2 , T_1 V_3 )
{
int V_35 ;
V_35 = F_1 ( V_2 , V_3 , false ) ;
if ( V_35 < 0 ) {
F_11 ( V_2 -> V_15 , L_8 ,
V_3 , V_35 ) ;
return V_35 ;
}
if ( V_2 -> V_5 == V_10 )
return V_35 ;
else
return ( V_35 * V_36 ) / V_17 ;
}
static int F_15 ( struct V_1 * V_2 )
{
int V_35 ;
V_35 = F_1 ( V_2 , V_21 , false ) ;
if ( V_35 < 0 ) {
F_11 ( V_2 -> V_15 , L_9 , V_35 ) ;
return V_35 ;
}
if ( ( V_2 -> V_5 == V_10 ) ) {
if ( V_35 & V_37 )
V_35 = V_38 ;
else if ( V_35 & V_39 )
V_35 = V_40 ;
else
V_35 = V_41 ;
return V_35 ;
} else {
if ( V_35 & V_42 )
V_35 = V_38 ;
else
V_35 = V_41 ;
return V_35 ;
}
return - 1 ;
}
static void F_16 ( struct V_1 * V_2 )
{
struct V_43 V_44 = { 0 , } ;
bool V_19 = V_2 -> V_5 == V_10 ;
bool V_45 = V_2 -> V_5 == V_6 ;
V_44 . V_18 = F_1 ( V_2 , V_21 , ! V_19 ) ;
if ( V_44 . V_18 >= 0 ) {
if ( ! V_19 && ! V_45
&& ( V_44 . V_18 & V_22 ) ) {
F_17 ( V_2 -> V_15 , L_10 ) ;
V_44 . V_46 = - V_23 ;
V_44 . V_47 = - V_23 ;
V_44 . V_48 = - V_23 ;
V_44 . V_49 = - V_23 ;
V_44 . V_50 = - V_23 ;
V_44 . V_51 = - V_23 ;
V_44 . V_52 = - V_23 ;
} else {
V_44 . V_46 = F_3 ( V_2 ) ;
if ( ! V_45 ) {
V_44 . V_47 = F_9 ( V_2 ) ;
V_44 . V_48 =
F_13 ( V_2 ,
V_53 ) ;
V_44 . V_49 =
F_13 ( V_2 ,
V_54 ) ;
V_44 . V_50 =
F_13 ( V_2 ,
V_55 ) ;
}
V_44 . V_51 = F_7 ( V_2 ) ;
V_44 . V_52 = F_15 ( V_2 ) ;
}
V_44 . V_56 = F_10 ( V_2 ) ;
if ( ! V_45 )
V_44 . V_57 = F_12 ( V_2 ) ;
V_44 . V_58 =
F_14 ( V_2 , V_59 ) ;
if ( V_2 -> V_60 <= 0 )
V_2 -> V_60 = F_8 ( V_2 ) ;
}
if ( memcmp ( & V_2 -> V_44 , & V_44 , sizeof( V_44 ) ) != 0 ) {
V_2 -> V_44 = V_44 ;
F_18 ( & V_2 -> V_61 ) ;
}
V_2 -> V_62 = V_63 ;
}
static void F_19 ( struct V_64 * V_65 )
{
struct V_1 * V_2 =
F_20 ( V_65 , struct V_1 , V_65 . V_65 ) ;
F_16 ( V_2 ) ;
if ( V_66 > 0 ) {
F_21 ( & V_2 -> V_65 . V_67 , V_66 * V_68 / 4 ) ;
F_22 ( & V_2 -> V_65 , V_66 * V_68 ) ;
}
}
static int F_23 ( struct V_1 * V_2 ,
union V_69 * V_70 )
{
int V_71 ;
int V_18 ;
V_71 = F_1 ( V_2 , V_72 , false ) ;
if ( V_71 < 0 ) {
F_11 ( V_2 -> V_15 , L_11 ) ;
return V_71 ;
}
if ( F_2 ( V_2 ) ) {
V_70 -> V_73 = ( int ) ( ( V_74 ) V_71 ) * 1000 ;
} else {
V_18 = F_1 ( V_2 , V_21 , false ) ;
if ( V_18 & V_75 ) {
F_4 ( V_2 -> V_15 , L_12 ) ;
V_71 = - V_71 ;
}
V_70 -> V_73 = V_71 * 3570 / V_17 ;
}
return 0 ;
}
static int F_24 ( struct V_1 * V_2 ,
union V_69 * V_70 )
{
int V_76 ;
if ( F_2 ( V_2 ) ) {
if ( V_2 -> V_44 . V_18 & V_77 )
V_76 = V_78 ;
else if ( V_2 -> V_44 . V_18 & V_79 )
V_76 = V_80 ;
else
V_76 = V_81 ;
} else {
if ( V_2 -> V_44 . V_18 & V_82 )
V_76 = V_78 ;
else if ( V_2 -> V_44 . V_18 & V_75 )
V_76 = V_81 ;
else if ( F_25 ( & V_2 -> V_61 ) )
V_76 = V_83 ;
else
V_76 = V_80 ;
}
V_70 -> V_73 = V_76 ;
return 0 ;
}
static int F_26 ( struct V_1 * V_2 ,
union V_69 * V_70 )
{
int V_84 ;
if ( F_2 ( V_2 ) ) {
if ( V_2 -> V_44 . V_18 & V_77 )
V_84 = V_85 ;
else if ( V_2 -> V_44 . V_18 & V_86 )
V_84 = V_87 ;
else if ( V_2 -> V_44 . V_18 & V_37 )
V_84 = V_88 ;
else
V_84 = V_89 ;
} else {
if ( V_2 -> V_44 . V_18 & V_82 )
V_84 = V_85 ;
else if ( V_2 -> V_44 . V_18 & V_42 )
V_84 = V_87 ;
else if ( V_2 -> V_44 . V_18 & V_90 )
V_84 = V_88 ;
else
V_84 = V_89 ;
}
V_70 -> V_73 = V_84 ;
return 0 ;
}
static int F_27 ( struct V_1 * V_2 ,
union V_69 * V_70 )
{
int V_91 ;
V_91 = F_1 ( V_2 , V_92 , false ) ;
if ( V_91 < 0 ) {
F_11 ( V_2 -> V_15 , L_13 ) ;
return V_91 ;
}
V_70 -> V_73 = V_91 * 1000 ;
return 0 ;
}
static int F_28 ( int V_93 ,
union V_69 * V_70 )
{
if ( V_93 < 0 )
return V_93 ;
V_70 -> V_73 = V_93 ;
return 0 ;
}
static int F_29 ( struct V_94 * V_95 ,
enum V_96 V_97 ,
union V_69 * V_70 )
{
int V_98 = 0 ;
struct V_1 * V_2 = F_30 ( V_95 ) ;
F_31 ( & V_2 -> V_99 ) ;
if ( F_32 ( V_2 -> V_62 + 5 * V_68 ) ) {
F_33 ( & V_2 -> V_65 ) ;
F_19 ( & V_2 -> V_65 . V_65 ) ;
}
F_34 ( & V_2 -> V_99 ) ;
if ( V_97 != V_100 && V_2 -> V_44 . V_18 < 0 )
return - V_101 ;
switch ( V_97 ) {
case V_102 :
V_98 = F_24 ( V_2 , V_70 ) ;
break;
case V_103 :
V_98 = F_27 ( V_2 , V_70 ) ;
break;
case V_100 :
V_70 -> V_73 = V_2 -> V_44 . V_18 < 0 ? 0 : 1 ;
break;
case V_104 :
V_98 = F_23 ( V_2 , V_70 ) ;
break;
case V_105 :
V_98 = F_28 ( V_2 -> V_44 . V_46 , V_70 ) ;
break;
case V_106 :
V_98 = F_26 ( V_2 , V_70 ) ;
break;
case V_107 :
V_98 = F_28 ( V_2 -> V_44 . V_56 , V_70 ) ;
if ( V_98 == 0 )
V_70 -> V_73 -= 2731 ;
break;
case V_108 :
V_98 = F_28 ( V_2 -> V_44 . V_48 , V_70 ) ;
break;
case V_109 :
V_98 = F_28 ( V_2 -> V_44 . V_49 , V_70 ) ;
break;
case V_110 :
V_98 = F_28 ( V_2 -> V_44 . V_50 , V_70 ) ;
break;
case V_111 :
V_70 -> V_73 = V_112 ;
break;
case V_113 :
V_98 = F_28 ( F_6 ( V_2 ) , V_70 ) ;
break;
case V_114 :
V_98 = F_28 ( V_2 -> V_44 . V_51 , V_70 ) ;
break;
case V_115 :
V_98 = F_28 ( V_2 -> V_60 , V_70 ) ;
break;
case V_116 :
V_98 = F_28 ( V_2 -> V_44 . V_57 , V_70 ) ;
break;
case V_117 :
V_98 = F_28 ( V_2 -> V_44 . V_47 , V_70 ) ;
break;
case V_118 :
V_98 = F_28 ( V_2 -> V_44 . V_58 , V_70 ) ;
break;
case V_119 :
V_98 = F_28 ( V_2 -> V_44 . V_52 , V_70 ) ;
break;
default:
return - V_120 ;
}
return V_98 ;
}
static void F_35 ( struct V_94 * V_95 )
{
struct V_1 * V_2 = F_30 ( V_95 ) ;
F_33 ( & V_2 -> V_65 ) ;
F_22 ( & V_2 -> V_65 , 0 ) ;
}
static int F_36 ( struct V_1 * V_2 )
{
int V_98 ;
V_2 -> V_61 . type = V_121 ;
if ( V_2 -> V_5 == V_6 ) {
V_2 -> V_61 . V_122 = V_123 ;
V_2 -> V_61 . V_124 = F_37 ( V_123 ) ;
} else {
V_2 -> V_61 . V_122 = V_125 ;
V_2 -> V_61 . V_124 = F_37 ( V_125 ) ;
}
V_2 -> V_61 . V_126 = F_29 ;
V_2 -> V_61 . V_127 = F_35 ;
F_38 ( & V_2 -> V_65 , F_19 ) ;
F_39 ( & V_2 -> V_99 ) ;
V_98 = F_40 ( V_2 -> V_15 , & V_2 -> V_61 ) ;
if ( V_98 ) {
F_11 ( V_2 -> V_15 , L_14 , V_98 ) ;
return V_98 ;
}
F_17 ( V_2 -> V_15 , L_15 , V_128 ) ;
F_16 ( V_2 ) ;
return 0 ;
}
static void F_41 ( struct V_1 * V_2 )
{
V_66 = 0 ;
F_33 ( & V_2 -> V_65 ) ;
F_42 ( & V_2 -> V_61 ) ;
F_43 ( & V_2 -> V_99 ) ;
}
static int F_44 ( struct V_1 * V_2 , T_1 V_3 , bool V_4 )
{
struct V_129 * V_130 = F_45 ( V_2 -> V_15 ) ;
struct V_131 V_132 [ 2 ] ;
unsigned char V_133 [ 2 ] ;
int V_98 ;
if ( ! V_130 -> V_134 )
return - V_101 ;
V_132 [ 0 ] . V_135 = V_130 -> V_135 ;
V_132 [ 0 ] . V_18 = 0 ;
V_132 [ 0 ] . V_136 = & V_3 ;
V_132 [ 0 ] . V_137 = sizeof( V_3 ) ;
V_132 [ 1 ] . V_135 = V_130 -> V_135 ;
V_132 [ 1 ] . V_18 = V_138 ;
V_132 [ 1 ] . V_136 = V_133 ;
if ( V_4 )
V_132 [ 1 ] . V_137 = 1 ;
else
V_132 [ 1 ] . V_137 = 2 ;
V_98 = F_46 ( V_130 -> V_134 , V_132 , F_37 ( V_132 ) ) ;
if ( V_98 < 0 )
return V_98 ;
if ( ! V_4 )
V_98 = F_47 ( V_133 ) ;
else
V_98 = V_133 [ 0 ] ;
return V_98 ;
}
static int F_48 ( struct V_129 * V_130 ,
const struct V_139 * V_140 )
{
char * V_141 ;
struct V_1 * V_2 ;
int V_142 ;
int V_143 = 0 ;
F_31 ( & V_144 ) ;
V_142 = F_49 ( & V_145 , V_130 , 0 , 0 , V_146 ) ;
F_34 ( & V_144 ) ;
if ( V_142 < 0 )
return V_142 ;
V_141 = F_50 ( V_146 , L_16 , V_140 -> V_141 , V_142 ) ;
if ( ! V_141 ) {
F_11 ( & V_130 -> V_15 , L_17 ) ;
V_143 = - V_147 ;
goto V_148;
}
V_2 = F_51 ( sizeof( * V_2 ) , V_146 ) ;
if ( ! V_2 ) {
F_11 ( & V_130 -> V_15 , L_18 ) ;
V_143 = - V_147 ;
goto V_149;
}
V_2 -> V_140 = V_142 ;
V_2 -> V_15 = & V_130 -> V_15 ;
V_2 -> V_5 = V_140 -> V_150 ;
V_2 -> V_61 . V_141 = V_141 ;
V_2 -> V_7 . V_8 = & F_44 ;
V_143 = F_36 ( V_2 ) ;
if ( V_143 )
goto V_151;
F_52 ( V_130 , V_2 ) ;
return 0 ;
V_151:
F_53 ( V_2 ) ;
V_149:
F_53 ( V_141 ) ;
V_148:
F_31 ( & V_144 ) ;
F_54 ( & V_145 , V_142 ) ;
F_34 ( & V_144 ) ;
return V_143 ;
}
static int F_55 ( struct V_129 * V_130 )
{
struct V_1 * V_2 = F_56 ( V_130 ) ;
F_41 ( V_2 ) ;
F_53 ( V_2 -> V_61 . V_141 ) ;
F_31 ( & V_144 ) ;
F_54 ( & V_145 , V_2 -> V_140 ) ;
F_34 ( & V_144 ) ;
F_53 ( V_2 ) ;
return 0 ;
}
static inline int F_57 ( void )
{
int V_98 = F_58 ( & V_152 ) ;
if ( V_98 )
F_59 ( V_153 L_19 ) ;
return V_98 ;
}
static inline void F_60 ( void )
{
F_61 ( & V_152 ) ;
}
static inline int F_57 ( void ) { return 0 ; }
static inline void F_60 ( void ) {}
static int F_62 ( struct V_1 * V_2 , T_1 V_3 ,
bool V_4 )
{
struct V_154 * V_15 = V_2 -> V_15 ;
struct V_155 * V_156 = V_15 -> V_157 ;
unsigned int V_158 = 3 ;
int V_159 , V_160 ;
int V_31 ;
if ( ! V_4 ) {
V_159 = V_156 -> V_8 ( V_15 , V_3 + 1 ) ;
do {
V_31 = V_159 ;
if ( V_159 < 0 )
return V_159 ;
V_160 = V_156 -> V_8 ( V_15 , V_3 ) ;
if ( V_160 < 0 )
return V_160 ;
V_159 = V_156 -> V_8 ( V_15 , V_3 + 1 ) ;
} while ( V_31 != V_159 && -- V_158 );
if ( V_158 == 0 )
return - V_161 ;
return ( V_159 << 8 ) | V_160 ;
}
return V_156 -> V_8 ( V_15 , V_3 ) ;
}
static int F_63 ( struct V_162 * V_163 )
{
struct V_1 * V_2 ;
struct V_155 * V_156 = V_163 -> V_15 . V_157 ;
int V_98 ;
if ( ! V_156 ) {
F_11 ( & V_163 -> V_15 , L_20 ) ;
return - V_120 ;
}
if ( ! V_156 -> V_8 ) {
F_11 ( & V_163 -> V_15 , L_21 ) ;
return - V_120 ;
}
V_2 = F_51 ( sizeof( * V_2 ) , V_146 ) ;
if ( ! V_2 ) {
F_11 ( & V_163 -> V_15 , L_18 ) ;
return - V_147 ;
}
F_64 ( V_163 , V_2 ) ;
V_2 -> V_15 = & V_163 -> V_15 ;
V_2 -> V_5 = V_164 ;
V_2 -> V_61 . V_141 = V_156 -> V_141 ? : F_65 ( & V_163 -> V_15 ) ;
V_2 -> V_7 . V_8 = & F_62 ;
V_98 = F_36 ( V_2 ) ;
if ( V_98 )
goto V_165;
return 0 ;
V_165:
F_64 ( V_163 , NULL ) ;
F_53 ( V_2 ) ;
return V_98 ;
}
static int F_66 ( struct V_162 * V_163 )
{
struct V_1 * V_2 = F_67 ( V_163 ) ;
F_41 ( V_2 ) ;
F_64 ( V_163 , NULL ) ;
F_53 ( V_2 ) ;
return 0 ;
}
static inline int F_68 ( void )
{
int V_98 = F_69 ( & V_166 ) ;
if ( V_98 )
F_59 ( V_153 L_22 ) ;
return V_98 ;
}
static inline void F_70 ( void )
{
F_71 ( & V_166 ) ;
}
static inline int F_68 ( void ) { return 0 ; }
static inline void F_70 ( void ) {}
static int T_2 F_72 ( void )
{
int V_98 ;
V_98 = F_57 () ;
if ( V_98 )
return V_98 ;
V_98 = F_68 () ;
if ( V_98 )
F_60 () ;
return V_98 ;
}
static void T_3 F_73 ( void )
{
F_70 () ;
F_60 () ;
}
