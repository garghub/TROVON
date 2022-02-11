static inline int F_1 ( struct V_1 * V_2 , T_1 V_3 ,
bool V_4 )
{
if ( V_2 -> V_5 == V_6 )
return V_2 -> V_7 . V_8 ( V_2 , V_3 - V_9 , V_4 ) ;
return V_2 -> V_7 . V_8 ( V_2 , V_3 , V_4 ) ;
}
static bool F_2 ( struct V_1 * V_2 )
{
if ( V_2 -> V_5 == V_6 || V_2 -> V_5 == V_10 || V_2 -> V_5 == V_11 )
return true ;
return false ;
}
static int F_3 ( struct V_1 * V_2 )
{
int V_12 ;
if ( V_2 -> V_5 == V_10 || V_2 -> V_5 == V_11 )
V_12 = F_1 ( V_2 , V_13 , false ) ;
else if ( V_2 -> V_5 == V_6 )
V_12 = F_1 ( V_2 , V_14 , false ) ;
else
V_12 = F_1 ( V_2 , V_15 , true ) ;
if ( V_12 < 0 )
F_4 ( V_2 -> V_16 , L_1 ) ;
return V_12 ;
}
static int F_5 ( struct V_1 * V_2 , T_1 V_3 )
{
int V_17 ;
V_17 = F_1 ( V_2 , V_3 , false ) ;
if ( V_17 < 0 ) {
F_4 ( V_2 -> V_16 , L_2 ,
V_3 , V_17 ) ;
return V_17 ;
}
if ( F_2 ( V_2 ) )
V_17 *= 1000 ;
else
V_17 = V_17 * 3570 / V_18 ;
return V_17 ;
}
static inline int F_6 ( struct V_1 * V_2 )
{
int V_19 ;
bool V_20 = V_2 -> V_5 == V_10 ;
bool V_21 = V_2 -> V_5 == V_11 ;
bool V_22 = F_2 ( V_2 ) ;
bool V_23 = ! ( V_20 || V_21 ) ;
V_19 = F_1 ( V_2 , V_24 , V_23 ) ;
if ( V_19 >= 0 && ! V_22 && ( V_19 & V_25 ) )
return - V_26 ;
return F_5 ( V_2 , V_27 ) ;
}
static inline int F_7 ( struct V_1 * V_2 )
{
return F_5 ( V_2 , V_28 ) ;
}
static int F_8 ( struct V_1 * V_2 )
{
int V_29 ;
if ( F_2 ( V_2 ) )
V_29 = F_1 ( V_2 , V_30 , false ) ;
else
V_29 = F_1 ( V_2 , V_31 , true ) ;
if ( V_29 < 0 ) {
F_4 ( V_2 -> V_16 , L_3 ) ;
return V_29 ;
}
if ( F_2 ( V_2 ) )
V_29 *= 1000 ;
else
V_29 = V_29 * 256 * 3570 / V_18 ;
return V_29 ;
}
static int F_9 ( struct V_1 * V_2 )
{
int V_32 ;
V_32 = F_1 ( V_2 , V_33 , false ) ;
if ( V_32 < 0 ) {
F_4 ( V_2 -> V_16 , L_4 ) ;
return V_32 ;
}
if ( V_2 -> V_5 == V_10 )
V_32 *= 1000 ;
else
V_32 = V_32 * 29200 / V_18 ;
return V_32 ;
}
static int F_10 ( struct V_1 * V_2 )
{
int V_34 ;
V_34 = F_1 ( V_2 , V_35 , false ) ;
if ( V_34 < 0 ) {
F_11 ( V_2 -> V_16 , L_5 ) ;
return V_34 ;
}
if ( ! F_2 ( V_2 ) )
V_34 = 5 * V_34 / 2 ;
return V_34 ;
}
static int F_12 ( struct V_1 * V_2 )
{
int V_36 ;
V_36 = F_1 ( V_2 , V_37 , false ) ;
if ( V_36 < 0 )
F_11 ( V_2 -> V_16 , L_6 ) ;
return V_36 ;
}
static int F_13 ( struct V_1 * V_2 , T_1 V_3 )
{
int V_38 ;
V_38 = F_1 ( V_2 , V_3 , false ) ;
if ( V_38 < 0 ) {
F_4 ( V_2 -> V_16 , L_7 ,
V_3 , V_38 ) ;
return V_38 ;
}
if ( V_38 == 65535 )
return - V_26 ;
return V_38 * 60 ;
}
static int F_14 ( struct V_1 * V_2 , T_1 V_3 )
{
int V_38 ;
V_38 = F_1 ( V_2 , V_3 , false ) ;
if ( V_38 < 0 ) {
F_11 ( V_2 -> V_16 , L_8 ,
V_3 , V_38 ) ;
return V_38 ;
}
if ( V_2 -> V_5 == V_10 )
return V_38 ;
else
return ( V_38 * V_39 ) / V_18 ;
}
static int F_15 ( struct V_1 * V_2 )
{
int V_38 ;
V_38 = F_1 ( V_2 , V_24 , false ) ;
if ( V_38 < 0 ) {
F_11 ( V_2 -> V_16 , L_9 , V_38 ) ;
return V_38 ;
}
if ( ( V_2 -> V_5 == V_10 ) ) {
if ( V_38 & V_40 )
V_38 = V_41 ;
else if ( V_38 & V_42 )
V_38 = V_43 ;
else
V_38 = V_44 ;
return V_38 ;
} else {
if ( V_38 & V_45 )
V_38 = V_41 ;
else
V_38 = V_44 ;
return V_38 ;
}
return - 1 ;
}
static void F_16 ( struct V_1 * V_2 )
{
struct V_46 V_47 = { 0 , } ;
bool V_20 = V_2 -> V_5 == V_10 ;
bool V_48 = V_2 -> V_5 == V_6 ;
bool V_21 = V_2 -> V_5 == V_11 ;
bool V_23 = ! ( V_20 || V_21 ) ;
V_47 . V_19 = F_1 ( V_2 , V_24 , V_23 ) ;
if ( ( V_47 . V_19 & 0xff ) == 0xff )
V_47 . V_19 = - 1 ;
if ( V_47 . V_19 >= 0 ) {
if ( ! V_20 && ! V_48 && ! V_21
&& ( V_47 . V_19 & V_25 ) ) {
F_17 ( V_2 -> V_16 , L_10 ) ;
V_47 . V_49 = - V_26 ;
V_47 . V_50 = - V_26 ;
V_47 . V_51 = - V_26 ;
V_47 . V_52 = - V_26 ;
V_47 . V_53 = - V_26 ;
V_47 . V_54 = - V_26 ;
V_47 . V_55 = - V_26 ;
} else {
V_47 . V_49 = F_3 ( V_2 ) ;
if ( V_21 )
V_47 . V_51 =
F_13 ( V_2 ,
V_56 ) ;
else if ( ! V_48 ) {
V_47 . V_50 = F_9 ( V_2 ) ;
V_47 . V_51 =
F_13 ( V_2 ,
V_56 ) ;
V_47 . V_52 =
F_13 ( V_2 ,
V_57 ) ;
V_47 . V_53 =
F_13 ( V_2 ,
V_58 ) ;
}
V_47 . V_54 = F_7 ( V_2 ) ;
V_47 . V_55 = F_15 ( V_2 ) ;
}
V_47 . V_59 = F_10 ( V_2 ) ;
if ( ! V_48 )
V_47 . V_60 = F_12 ( V_2 ) ;
if ( V_21 )
V_47 . V_61 =
F_14 ( V_2 ,
V_62 ) ;
else
V_47 . V_61 =
F_14 ( V_2 ,
V_63 ) ;
if ( V_2 -> V_64 <= 0 )
V_2 -> V_64 = F_8 ( V_2 ) ;
}
if ( memcmp ( & V_2 -> V_47 , & V_47 , sizeof( V_47 ) ) != 0 ) {
V_2 -> V_47 = V_47 ;
F_18 ( & V_2 -> V_65 ) ;
}
V_2 -> V_66 = V_67 ;
}
static void F_19 ( struct V_68 * V_69 )
{
struct V_1 * V_2 =
F_20 ( V_69 , struct V_1 , V_69 . V_69 ) ;
F_16 ( V_2 ) ;
if ( V_70 > 0 ) {
F_21 ( & V_2 -> V_69 . V_71 , V_70 * V_72 / 4 ) ;
F_22 ( & V_2 -> V_69 , V_70 * V_72 ) ;
}
}
static int F_23 ( struct V_1 * V_2 ,
union V_73 * V_74 )
{
int V_75 ;
int V_19 ;
V_75 = F_1 ( V_2 , V_76 , false ) ;
if ( V_75 < 0 ) {
F_11 ( V_2 -> V_16 , L_11 ) ;
return V_75 ;
}
if ( F_2 ( V_2 ) ) {
V_74 -> V_77 = ( int ) ( ( V_78 ) V_75 ) * 1000 ;
} else {
V_19 = F_1 ( V_2 , V_24 , false ) ;
if ( V_19 & V_79 ) {
F_4 ( V_2 -> V_16 , L_12 ) ;
V_75 = - V_75 ;
}
V_74 -> V_77 = V_75 * 3570 / V_18 ;
}
return 0 ;
}
static int F_24 ( struct V_1 * V_2 ,
union V_73 * V_74 )
{
int V_80 ;
if ( F_2 ( V_2 ) ) {
if ( V_2 -> V_47 . V_19 & V_81 )
V_80 = V_82 ;
else if ( V_2 -> V_47 . V_19 & V_83 )
V_80 = V_84 ;
else
V_80 = V_85 ;
} else {
if ( V_2 -> V_47 . V_19 & V_86 )
V_80 = V_82 ;
else if ( V_2 -> V_47 . V_19 & V_79 )
V_80 = V_85 ;
else if ( F_25 ( & V_2 -> V_65 ) )
V_80 = V_87 ;
else
V_80 = V_84 ;
}
V_74 -> V_77 = V_80 ;
return 0 ;
}
static int F_26 ( struct V_1 * V_2 ,
union V_73 * V_74 )
{
int V_88 ;
if ( F_2 ( V_2 ) ) {
if ( V_2 -> V_47 . V_19 & V_81 )
V_88 = V_89 ;
else if ( V_2 -> V_47 . V_19 & V_90 )
V_88 = V_91 ;
else if ( V_2 -> V_47 . V_19 & V_40 )
V_88 = V_92 ;
else
V_88 = V_93 ;
} else {
if ( V_2 -> V_47 . V_19 & V_86 )
V_88 = V_89 ;
else if ( V_2 -> V_47 . V_19 & V_45 )
V_88 = V_91 ;
else if ( V_2 -> V_47 . V_19 & V_94 )
V_88 = V_92 ;
else
V_88 = V_93 ;
}
V_74 -> V_77 = V_88 ;
return 0 ;
}
static int F_27 ( struct V_1 * V_2 ,
union V_73 * V_74 )
{
int V_95 ;
V_95 = F_1 ( V_2 , V_96 , false ) ;
if ( V_95 < 0 ) {
F_11 ( V_2 -> V_16 , L_13 ) ;
return V_95 ;
}
V_74 -> V_77 = V_95 * 1000 ;
return 0 ;
}
static int F_28 ( int V_97 ,
union V_73 * V_74 )
{
if ( V_97 < 0 )
return V_97 ;
V_74 -> V_77 = V_97 ;
return 0 ;
}
static int F_29 ( struct V_98 * V_99 ,
enum V_100 V_101 ,
union V_73 * V_74 )
{
int V_102 = 0 ;
struct V_1 * V_2 = F_30 ( V_99 ) ;
F_31 ( & V_2 -> V_103 ) ;
if ( F_32 ( V_2 -> V_66 + 5 * V_72 ) ) {
F_33 ( & V_2 -> V_69 ) ;
F_19 ( & V_2 -> V_69 . V_69 ) ;
}
F_34 ( & V_2 -> V_103 ) ;
if ( V_101 != V_104 && V_2 -> V_47 . V_19 < 0 )
return - V_105 ;
switch ( V_101 ) {
case V_106 :
V_102 = F_24 ( V_2 , V_74 ) ;
break;
case V_107 :
V_102 = F_27 ( V_2 , V_74 ) ;
break;
case V_104 :
V_74 -> V_77 = V_2 -> V_47 . V_19 < 0 ? 0 : 1 ;
break;
case V_108 :
V_102 = F_23 ( V_2 , V_74 ) ;
break;
case V_109 :
V_102 = F_28 ( V_2 -> V_47 . V_49 , V_74 ) ;
break;
case V_110 :
V_102 = F_26 ( V_2 , V_74 ) ;
break;
case V_111 :
V_102 = F_28 ( V_2 -> V_47 . V_59 , V_74 ) ;
if ( V_102 == 0 )
V_74 -> V_77 -= 2731 ;
break;
case V_112 :
V_102 = F_28 ( V_2 -> V_47 . V_51 , V_74 ) ;
break;
case V_113 :
V_102 = F_28 ( V_2 -> V_47 . V_52 , V_74 ) ;
break;
case V_114 :
V_102 = F_28 ( V_2 -> V_47 . V_53 , V_74 ) ;
break;
case V_115 :
V_74 -> V_77 = V_116 ;
break;
case V_117 :
V_102 = F_28 ( F_6 ( V_2 ) , V_74 ) ;
break;
case V_118 :
V_102 = F_28 ( V_2 -> V_47 . V_54 , V_74 ) ;
break;
case V_119 :
V_102 = F_28 ( V_2 -> V_64 , V_74 ) ;
break;
case V_120 :
V_102 = F_28 ( V_2 -> V_47 . V_60 , V_74 ) ;
break;
case V_121 :
V_102 = F_28 ( V_2 -> V_47 . V_50 , V_74 ) ;
break;
case V_122 :
V_102 = F_28 ( V_2 -> V_47 . V_61 , V_74 ) ;
break;
case V_123 :
V_102 = F_28 ( V_2 -> V_47 . V_55 , V_74 ) ;
break;
default:
return - V_124 ;
}
return V_102 ;
}
static void F_35 ( struct V_98 * V_99 )
{
struct V_1 * V_2 = F_30 ( V_99 ) ;
F_33 ( & V_2 -> V_69 ) ;
F_22 ( & V_2 -> V_69 , 0 ) ;
}
static int F_36 ( struct V_1 * V_2 )
{
int V_102 ;
V_2 -> V_65 . type = V_125 ;
if ( V_2 -> V_5 == V_6 ) {
V_2 -> V_65 . V_126 = V_127 ;
V_2 -> V_65 . V_128 = F_37 ( V_127 ) ;
} else if ( V_2 -> V_5 == V_11 ) {
V_2 -> V_65 . V_126 = V_129 ;
V_2 -> V_65 . V_128 = F_37 ( V_129 ) ;
} else {
V_2 -> V_65 . V_126 = V_130 ;
V_2 -> V_65 . V_128 = F_37 ( V_130 ) ;
}
V_2 -> V_65 . V_131 = F_29 ;
V_2 -> V_65 . V_132 = F_35 ;
F_38 ( & V_2 -> V_69 , F_19 ) ;
F_39 ( & V_2 -> V_103 ) ;
V_102 = F_40 ( V_2 -> V_16 , & V_2 -> V_65 ) ;
if ( V_102 ) {
F_11 ( V_2 -> V_16 , L_14 , V_102 ) ;
return V_102 ;
}
F_17 ( V_2 -> V_16 , L_15 , V_133 ) ;
F_16 ( V_2 ) ;
return 0 ;
}
static void F_41 ( struct V_1 * V_2 )
{
V_70 = 0 ;
F_33 ( & V_2 -> V_69 ) ;
F_42 ( & V_2 -> V_65 ) ;
F_43 ( & V_2 -> V_103 ) ;
}
static int F_44 ( struct V_1 * V_2 , T_1 V_3 , bool V_4 )
{
struct V_134 * V_135 = F_45 ( V_2 -> V_16 ) ;
struct V_136 V_137 [ 2 ] ;
unsigned char V_138 [ 2 ] ;
int V_102 ;
if ( ! V_135 -> V_139 )
return - V_105 ;
V_137 [ 0 ] . V_140 = V_135 -> V_140 ;
V_137 [ 0 ] . V_19 = 0 ;
V_137 [ 0 ] . V_141 = & V_3 ;
V_137 [ 0 ] . V_142 = sizeof( V_3 ) ;
V_137 [ 1 ] . V_140 = V_135 -> V_140 ;
V_137 [ 1 ] . V_19 = V_143 ;
V_137 [ 1 ] . V_141 = V_138 ;
if ( V_4 )
V_137 [ 1 ] . V_142 = 1 ;
else
V_137 [ 1 ] . V_142 = 2 ;
V_102 = F_46 ( V_135 -> V_139 , V_137 , F_37 ( V_137 ) ) ;
if ( V_102 < 0 )
return V_102 ;
if ( ! V_4 )
V_102 = F_47 ( V_138 ) ;
else
V_102 = V_138 [ 0 ] ;
return V_102 ;
}
static int F_48 ( struct V_134 * V_135 ,
const struct V_144 * V_145 )
{
char * V_146 ;
struct V_1 * V_2 ;
int V_147 ;
int V_148 = 0 ;
F_31 ( & V_149 ) ;
V_147 = F_49 ( & V_150 , V_135 , 0 , 0 , V_151 ) ;
F_34 ( & V_149 ) ;
if ( V_147 < 0 )
return V_147 ;
V_146 = F_50 ( V_151 , L_16 , V_145 -> V_146 , V_147 ) ;
if ( ! V_146 ) {
F_11 ( & V_135 -> V_16 , L_17 ) ;
V_148 = - V_152 ;
goto V_153;
}
V_2 = F_51 ( & V_135 -> V_16 , sizeof( * V_2 ) , V_151 ) ;
if ( ! V_2 ) {
F_11 ( & V_135 -> V_16 , L_18 ) ;
V_148 = - V_152 ;
goto V_154;
}
V_2 -> V_145 = V_147 ;
V_2 -> V_16 = & V_135 -> V_16 ;
V_2 -> V_5 = V_145 -> V_155 ;
V_2 -> V_65 . V_146 = V_146 ;
V_2 -> V_7 . V_8 = & F_44 ;
V_148 = F_36 ( V_2 ) ;
if ( V_148 )
goto V_154;
F_52 ( V_135 , V_2 ) ;
return 0 ;
V_154:
F_53 ( V_146 ) ;
V_153:
F_31 ( & V_149 ) ;
F_54 ( & V_150 , V_147 ) ;
F_34 ( & V_149 ) ;
return V_148 ;
}
static int F_55 ( struct V_134 * V_135 )
{
struct V_1 * V_2 = F_56 ( V_135 ) ;
F_41 ( V_2 ) ;
F_53 ( V_2 -> V_65 . V_146 ) ;
F_31 ( & V_149 ) ;
F_54 ( & V_150 , V_2 -> V_145 ) ;
F_34 ( & V_149 ) ;
return 0 ;
}
static inline int F_57 ( void )
{
int V_102 = F_58 ( & V_156 ) ;
if ( V_102 )
F_59 ( V_157 L_19 ) ;
return V_102 ;
}
static inline void F_60 ( void )
{
F_61 ( & V_156 ) ;
}
static inline int F_57 ( void ) { return 0 ; }
static inline void F_60 ( void ) {}
static int F_62 ( struct V_1 * V_2 , T_1 V_3 ,
bool V_4 )
{
struct V_158 * V_16 = V_2 -> V_16 ;
struct V_159 * V_160 = V_16 -> V_161 ;
unsigned int V_162 = 3 ;
int V_163 , V_164 ;
int V_34 ;
if ( ! V_4 ) {
V_163 = V_160 -> V_8 ( V_16 , V_3 + 1 ) ;
do {
V_34 = V_163 ;
if ( V_163 < 0 )
return V_163 ;
V_164 = V_160 -> V_8 ( V_16 , V_3 ) ;
if ( V_164 < 0 )
return V_164 ;
V_163 = V_160 -> V_8 ( V_16 , V_3 + 1 ) ;
} while ( V_34 != V_163 && -- V_162 );
if ( V_162 == 0 )
return - V_165 ;
return ( V_163 << 8 ) | V_164 ;
}
return V_160 -> V_8 ( V_16 , V_3 ) ;
}
static int F_63 ( struct V_166 * V_167 )
{
struct V_1 * V_2 ;
struct V_159 * V_160 = V_167 -> V_16 . V_161 ;
if ( ! V_160 ) {
F_11 ( & V_167 -> V_16 , L_20 ) ;
return - V_124 ;
}
if ( ! V_160 -> V_8 ) {
F_11 ( & V_167 -> V_16 , L_21 ) ;
return - V_124 ;
}
V_2 = F_51 ( & V_167 -> V_16 , sizeof( * V_2 ) , V_151 ) ;
if ( ! V_2 ) {
F_11 ( & V_167 -> V_16 , L_18 ) ;
return - V_152 ;
}
F_64 ( V_167 , V_2 ) ;
V_2 -> V_16 = & V_167 -> V_16 ;
V_2 -> V_5 = V_168 ;
V_2 -> V_65 . V_146 = V_160 -> V_146 ? : F_65 ( & V_167 -> V_16 ) ;
V_2 -> V_7 . V_8 = & F_62 ;
return F_36 ( V_2 ) ;
}
static int F_66 ( struct V_166 * V_167 )
{
struct V_1 * V_2 = F_67 ( V_167 ) ;
F_41 ( V_2 ) ;
return 0 ;
}
static inline int F_68 ( void )
{
int V_102 = F_69 ( & V_169 ) ;
if ( V_102 )
F_59 ( V_157 L_22 ) ;
return V_102 ;
}
static inline void F_70 ( void )
{
F_71 ( & V_169 ) ;
}
static inline int F_68 ( void ) { return 0 ; }
static inline void F_70 ( void ) {}
static int T_2 F_72 ( void )
{
int V_102 ;
V_102 = F_57 () ;
if ( V_102 )
return V_102 ;
V_102 = F_68 () ;
if ( V_102 )
F_60 () ;
return V_102 ;
}
static void T_3 F_73 ( void )
{
F_70 () ;
F_60 () ;
}
