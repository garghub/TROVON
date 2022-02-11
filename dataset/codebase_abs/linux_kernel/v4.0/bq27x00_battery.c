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
if ( F_2 ( V_2 ) ) {
if ( V_2 -> V_5 == V_6 )
V_29 = F_1 ( V_2 , V_30 , false ) ;
else
V_29 = F_1 ( V_2 , V_31 , false ) ;
} else
V_29 = F_1 ( V_2 , V_32 , true ) ;
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
int V_33 ;
V_33 = F_1 ( V_2 , V_34 , false ) ;
if ( V_33 < 0 ) {
F_4 ( V_2 -> V_16 , L_4 ) ;
return V_33 ;
}
if ( V_2 -> V_5 == V_10 )
V_33 *= 1000 ;
else
V_33 = V_33 * 29200 / V_18 ;
return V_33 ;
}
static int F_10 ( struct V_1 * V_2 )
{
int V_35 ;
V_35 = F_1 ( V_2 , V_36 , false ) ;
if ( V_35 < 0 ) {
F_11 ( V_2 -> V_16 , L_5 ) ;
return V_35 ;
}
if ( ! F_2 ( V_2 ) )
V_35 = 5 * V_35 / 2 ;
return V_35 ;
}
static int F_12 ( struct V_1 * V_2 )
{
int V_37 ;
V_37 = F_1 ( V_2 , V_38 , false ) ;
if ( V_37 < 0 )
F_11 ( V_2 -> V_16 , L_6 ) ;
return V_37 ;
}
static int F_13 ( struct V_1 * V_2 , T_1 V_3 )
{
int V_39 ;
V_39 = F_1 ( V_2 , V_3 , false ) ;
if ( V_39 < 0 ) {
F_4 ( V_2 -> V_16 , L_7 ,
V_3 , V_39 ) ;
return V_39 ;
}
if ( V_39 == 65535 )
return - V_26 ;
return V_39 * 60 ;
}
static int F_14 ( struct V_1 * V_2 , T_1 V_3 )
{
int V_39 ;
V_39 = F_1 ( V_2 , V_3 , false ) ;
if ( V_39 < 0 ) {
F_11 ( V_2 -> V_16 , L_8 ,
V_3 , V_39 ) ;
return V_39 ;
}
if ( V_2 -> V_5 == V_10 )
return V_39 ;
else
return ( V_39 * V_40 ) / V_18 ;
}
static int F_15 ( struct V_1 * V_2 )
{
int V_39 ;
V_39 = F_1 ( V_2 , V_24 , false ) ;
if ( V_39 < 0 ) {
F_11 ( V_2 -> V_16 , L_9 , V_39 ) ;
return V_39 ;
}
if ( ( V_2 -> V_5 == V_10 ) ) {
if ( V_39 & V_41 )
V_39 = V_42 ;
else if ( V_39 & V_43 )
V_39 = V_44 ;
else
V_39 = V_45 ;
return V_39 ;
} else {
if ( V_39 & V_46 )
V_39 = V_42 ;
else
V_39 = V_45 ;
return V_39 ;
}
return - 1 ;
}
static void F_16 ( struct V_1 * V_2 )
{
struct V_47 V_48 = { 0 , } ;
bool V_20 = V_2 -> V_5 == V_10 ;
bool V_49 = V_2 -> V_5 == V_6 ;
bool V_21 = V_2 -> V_5 == V_11 ;
bool V_23 = ! ( V_20 || V_21 ) ;
V_48 . V_19 = F_1 ( V_2 , V_24 , V_23 ) ;
if ( ( V_48 . V_19 & 0xff ) == 0xff )
V_48 . V_19 = - 1 ;
if ( V_48 . V_19 >= 0 ) {
if ( ! V_20 && ! V_49 && ! V_21
&& ( V_48 . V_19 & V_25 ) ) {
F_17 ( V_2 -> V_16 , L_10 ) ;
V_48 . V_50 = - V_26 ;
V_48 . V_51 = - V_26 ;
V_48 . V_52 = - V_26 ;
V_48 . V_53 = - V_26 ;
V_48 . V_54 = - V_26 ;
V_48 . V_55 = - V_26 ;
V_48 . V_56 = - V_26 ;
} else {
V_48 . V_50 = F_3 ( V_2 ) ;
if ( V_21 )
V_48 . V_52 =
F_13 ( V_2 ,
V_57 ) ;
else if ( ! V_49 ) {
V_48 . V_51 = F_9 ( V_2 ) ;
V_48 . V_52 =
F_13 ( V_2 ,
V_57 ) ;
V_48 . V_53 =
F_13 ( V_2 ,
V_58 ) ;
V_48 . V_54 =
F_13 ( V_2 ,
V_59 ) ;
}
V_48 . V_55 = F_7 ( V_2 ) ;
V_48 . V_56 = F_15 ( V_2 ) ;
}
V_48 . V_60 = F_10 ( V_2 ) ;
if ( ! V_49 )
V_48 . V_61 = F_12 ( V_2 ) ;
if ( V_21 )
V_48 . V_62 =
F_14 ( V_2 ,
V_63 ) ;
else
V_48 . V_62 =
F_14 ( V_2 ,
V_64 ) ;
if ( V_2 -> V_65 <= 0 )
V_2 -> V_65 = F_8 ( V_2 ) ;
}
if ( V_2 -> V_48 . V_50 != V_48 . V_50 )
F_18 ( & V_2 -> V_66 ) ;
if ( memcmp ( & V_2 -> V_48 , & V_48 , sizeof( V_48 ) ) != 0 )
V_2 -> V_48 = V_48 ;
V_2 -> V_67 = V_68 ;
}
static void F_19 ( struct V_69 * V_70 )
{
struct V_1 * V_2 =
F_20 ( V_70 , struct V_1 , V_70 . V_70 ) ;
F_16 ( V_2 ) ;
if ( V_71 > 0 ) {
F_21 ( & V_2 -> V_70 . V_72 , V_71 * V_73 / 4 ) ;
F_22 ( & V_2 -> V_70 , V_71 * V_73 ) ;
}
}
static int F_23 ( struct V_1 * V_2 ,
union V_74 * V_75 )
{
int V_76 ;
int V_19 ;
V_76 = F_1 ( V_2 , V_77 , false ) ;
if ( V_76 < 0 ) {
F_11 ( V_2 -> V_16 , L_11 ) ;
return V_76 ;
}
if ( F_2 ( V_2 ) ) {
V_75 -> V_78 = ( int ) ( ( V_79 ) V_76 ) * 1000 ;
} else {
V_19 = F_1 ( V_2 , V_24 , false ) ;
if ( V_19 & V_80 ) {
F_4 ( V_2 -> V_16 , L_12 ) ;
V_76 = - V_76 ;
}
V_75 -> V_78 = V_76 * 3570 / V_18 ;
}
return 0 ;
}
static int F_24 ( struct V_1 * V_2 ,
union V_74 * V_75 )
{
int V_81 ;
if ( F_2 ( V_2 ) ) {
if ( V_2 -> V_48 . V_19 & V_82 )
V_81 = V_83 ;
else if ( V_2 -> V_48 . V_19 & V_84 )
V_81 = V_85 ;
else
V_81 = V_86 ;
} else {
if ( V_2 -> V_48 . V_19 & V_87 )
V_81 = V_83 ;
else if ( V_2 -> V_48 . V_19 & V_80 )
V_81 = V_86 ;
else if ( F_25 ( & V_2 -> V_66 ) )
V_81 = V_88 ;
else
V_81 = V_85 ;
}
V_75 -> V_78 = V_81 ;
return 0 ;
}
static int F_26 ( struct V_1 * V_2 ,
union V_74 * V_75 )
{
int V_89 ;
if ( F_2 ( V_2 ) ) {
if ( V_2 -> V_48 . V_19 & V_82 )
V_89 = V_90 ;
else if ( V_2 -> V_48 . V_19 & V_91 )
V_89 = V_92 ;
else if ( V_2 -> V_48 . V_19 & V_41 )
V_89 = V_93 ;
else
V_89 = V_94 ;
} else {
if ( V_2 -> V_48 . V_19 & V_87 )
V_89 = V_90 ;
else if ( V_2 -> V_48 . V_19 & V_46 )
V_89 = V_92 ;
else if ( V_2 -> V_48 . V_19 & V_95 )
V_89 = V_93 ;
else
V_89 = V_94 ;
}
V_75 -> V_78 = V_89 ;
return 0 ;
}
static int F_27 ( struct V_1 * V_2 ,
union V_74 * V_75 )
{
int V_96 ;
V_96 = F_1 ( V_2 , V_97 , false ) ;
if ( V_96 < 0 ) {
F_11 ( V_2 -> V_16 , L_13 ) ;
return V_96 ;
}
V_75 -> V_78 = V_96 * 1000 ;
return 0 ;
}
static int F_28 ( int V_98 ,
union V_74 * V_75 )
{
if ( V_98 < 0 )
return V_98 ;
V_75 -> V_78 = V_98 ;
return 0 ;
}
static int F_29 ( struct V_99 * V_100 ,
enum V_101 V_102 ,
union V_74 * V_75 )
{
int V_103 = 0 ;
struct V_1 * V_2 = F_30 ( V_100 ) ;
F_31 ( & V_2 -> V_104 ) ;
if ( F_32 ( V_2 -> V_67 + 5 * V_73 ) ) {
F_33 ( & V_2 -> V_70 ) ;
F_19 ( & V_2 -> V_70 . V_70 ) ;
}
F_34 ( & V_2 -> V_104 ) ;
if ( V_102 != V_105 && V_2 -> V_48 . V_19 < 0 )
return - V_106 ;
switch ( V_102 ) {
case V_107 :
V_103 = F_24 ( V_2 , V_75 ) ;
break;
case V_108 :
V_103 = F_27 ( V_2 , V_75 ) ;
break;
case V_105 :
V_75 -> V_78 = V_2 -> V_48 . V_19 < 0 ? 0 : 1 ;
break;
case V_109 :
V_103 = F_23 ( V_2 , V_75 ) ;
break;
case V_110 :
V_103 = F_28 ( V_2 -> V_48 . V_50 , V_75 ) ;
break;
case V_111 :
V_103 = F_26 ( V_2 , V_75 ) ;
break;
case V_112 :
V_103 = F_28 ( V_2 -> V_48 . V_60 , V_75 ) ;
if ( V_103 == 0 )
V_75 -> V_78 -= 2731 ;
break;
case V_113 :
V_103 = F_28 ( V_2 -> V_48 . V_52 , V_75 ) ;
break;
case V_114 :
V_103 = F_28 ( V_2 -> V_48 . V_53 , V_75 ) ;
break;
case V_115 :
V_103 = F_28 ( V_2 -> V_48 . V_54 , V_75 ) ;
break;
case V_116 :
V_75 -> V_78 = V_117 ;
break;
case V_118 :
V_103 = F_28 ( F_6 ( V_2 ) , V_75 ) ;
break;
case V_119 :
V_103 = F_28 ( V_2 -> V_48 . V_55 , V_75 ) ;
break;
case V_120 :
V_103 = F_28 ( V_2 -> V_65 , V_75 ) ;
break;
case V_121 :
V_103 = F_28 ( V_2 -> V_48 . V_61 , V_75 ) ;
break;
case V_122 :
V_103 = F_28 ( V_2 -> V_48 . V_51 , V_75 ) ;
break;
case V_123 :
V_103 = F_28 ( V_2 -> V_48 . V_62 , V_75 ) ;
break;
case V_124 :
V_103 = F_28 ( V_2 -> V_48 . V_56 , V_75 ) ;
break;
default:
return - V_125 ;
}
return V_103 ;
}
static void F_35 ( struct V_99 * V_100 )
{
struct V_1 * V_2 = F_30 ( V_100 ) ;
F_33 ( & V_2 -> V_70 ) ;
F_22 ( & V_2 -> V_70 , 0 ) ;
}
static int F_36 ( struct V_1 * V_2 )
{
int V_103 ;
V_2 -> V_66 . type = V_126 ;
if ( V_2 -> V_5 == V_6 ) {
V_2 -> V_66 . V_127 = V_128 ;
V_2 -> V_66 . V_129 = F_37 ( V_128 ) ;
} else if ( V_2 -> V_5 == V_11 ) {
V_2 -> V_66 . V_127 = V_130 ;
V_2 -> V_66 . V_129 = F_37 ( V_130 ) ;
} else {
V_2 -> V_66 . V_127 = V_131 ;
V_2 -> V_66 . V_129 = F_37 ( V_131 ) ;
}
V_2 -> V_66 . V_132 = F_29 ;
V_2 -> V_66 . V_133 = F_35 ;
F_38 ( & V_2 -> V_70 , F_19 ) ;
F_39 ( & V_2 -> V_104 ) ;
V_103 = F_40 ( V_2 -> V_16 , & V_2 -> V_66 ) ;
if ( V_103 ) {
F_11 ( V_2 -> V_16 , L_14 , V_103 ) ;
return V_103 ;
}
F_17 ( V_2 -> V_16 , L_15 , V_134 ) ;
F_16 ( V_2 ) ;
return 0 ;
}
static void F_41 ( struct V_1 * V_2 )
{
V_71 = 0 ;
F_33 ( & V_2 -> V_70 ) ;
F_42 ( & V_2 -> V_66 ) ;
F_43 ( & V_2 -> V_104 ) ;
}
static int F_44 ( struct V_1 * V_2 , T_1 V_3 , bool V_4 )
{
struct V_135 * V_136 = F_45 ( V_2 -> V_16 ) ;
struct V_137 V_138 [ 2 ] ;
unsigned char V_139 [ 2 ] ;
int V_103 ;
if ( ! V_136 -> V_140 )
return - V_106 ;
V_138 [ 0 ] . V_141 = V_136 -> V_141 ;
V_138 [ 0 ] . V_19 = 0 ;
V_138 [ 0 ] . V_142 = & V_3 ;
V_138 [ 0 ] . V_143 = sizeof( V_3 ) ;
V_138 [ 1 ] . V_141 = V_136 -> V_141 ;
V_138 [ 1 ] . V_19 = V_144 ;
V_138 [ 1 ] . V_142 = V_139 ;
if ( V_4 )
V_138 [ 1 ] . V_143 = 1 ;
else
V_138 [ 1 ] . V_143 = 2 ;
V_103 = F_46 ( V_136 -> V_140 , V_138 , F_37 ( V_138 ) ) ;
if ( V_103 < 0 )
return V_103 ;
if ( ! V_4 )
V_103 = F_47 ( V_139 ) ;
else
V_103 = V_139 [ 0 ] ;
return V_103 ;
}
static int F_48 ( struct V_135 * V_136 ,
const struct V_145 * V_146 )
{
char * V_147 ;
struct V_1 * V_2 ;
int V_148 ;
int V_149 = 0 ;
F_31 ( & V_150 ) ;
V_148 = F_49 ( & V_151 , V_136 , 0 , 0 , V_152 ) ;
F_34 ( & V_150 ) ;
if ( V_148 < 0 )
return V_148 ;
V_147 = F_50 ( V_152 , L_16 , V_146 -> V_147 , V_148 ) ;
if ( ! V_147 ) {
F_11 ( & V_136 -> V_16 , L_17 ) ;
V_149 = - V_153 ;
goto V_154;
}
V_2 = F_51 ( & V_136 -> V_16 , sizeof( * V_2 ) , V_152 ) ;
if ( ! V_2 ) {
F_11 ( & V_136 -> V_16 , L_18 ) ;
V_149 = - V_153 ;
goto V_155;
}
V_2 -> V_146 = V_148 ;
V_2 -> V_16 = & V_136 -> V_16 ;
V_2 -> V_5 = V_146 -> V_156 ;
V_2 -> V_66 . V_147 = V_147 ;
V_2 -> V_7 . V_8 = & F_44 ;
V_149 = F_36 ( V_2 ) ;
if ( V_149 )
goto V_155;
F_52 ( V_136 , V_2 ) ;
return 0 ;
V_155:
F_53 ( V_147 ) ;
V_154:
F_31 ( & V_150 ) ;
F_54 ( & V_151 , V_148 ) ;
F_34 ( & V_150 ) ;
return V_149 ;
}
static int F_55 ( struct V_135 * V_136 )
{
struct V_1 * V_2 = F_56 ( V_136 ) ;
F_41 ( V_2 ) ;
F_53 ( V_2 -> V_66 . V_147 ) ;
F_31 ( & V_150 ) ;
F_54 ( & V_151 , V_2 -> V_146 ) ;
F_34 ( & V_150 ) ;
return 0 ;
}
static inline int F_57 ( void )
{
int V_103 = F_58 ( & V_157 ) ;
if ( V_103 )
F_59 ( V_158 L_19 ) ;
return V_103 ;
}
static inline void F_60 ( void )
{
F_61 ( & V_157 ) ;
}
static inline int F_57 ( void ) { return 0 ; }
static inline void F_60 ( void ) {}
static int F_62 ( struct V_1 * V_2 , T_1 V_3 ,
bool V_4 )
{
struct V_159 * V_16 = V_2 -> V_16 ;
struct V_160 * V_161 = V_16 -> V_162 ;
unsigned int V_163 = 3 ;
int V_164 , V_165 ;
int V_35 ;
if ( ! V_4 ) {
V_164 = V_161 -> V_8 ( V_16 , V_3 + 1 ) ;
do {
V_35 = V_164 ;
if ( V_164 < 0 )
return V_164 ;
V_165 = V_161 -> V_8 ( V_16 , V_3 ) ;
if ( V_165 < 0 )
return V_165 ;
V_164 = V_161 -> V_8 ( V_16 , V_3 + 1 ) ;
} while ( V_35 != V_164 && -- V_163 );
if ( V_163 == 0 )
return - V_166 ;
return ( V_164 << 8 ) | V_165 ;
}
return V_161 -> V_8 ( V_16 , V_3 ) ;
}
static int F_63 ( struct V_167 * V_168 )
{
struct V_1 * V_2 ;
struct V_160 * V_161 = V_168 -> V_16 . V_162 ;
if ( ! V_161 ) {
F_11 ( & V_168 -> V_16 , L_20 ) ;
return - V_125 ;
}
if ( ! V_161 -> V_8 ) {
F_11 ( & V_168 -> V_16 , L_21 ) ;
return - V_125 ;
}
V_2 = F_51 ( & V_168 -> V_16 , sizeof( * V_2 ) , V_152 ) ;
if ( ! V_2 ) {
F_11 ( & V_168 -> V_16 , L_18 ) ;
return - V_153 ;
}
F_64 ( V_168 , V_2 ) ;
V_2 -> V_16 = & V_168 -> V_16 ;
V_2 -> V_5 = V_169 ;
V_2 -> V_66 . V_147 = V_161 -> V_147 ? : F_65 ( & V_168 -> V_16 ) ;
V_2 -> V_7 . V_8 = & F_62 ;
return F_36 ( V_2 ) ;
}
static int F_66 ( struct V_167 * V_168 )
{
struct V_1 * V_2 = F_67 ( V_168 ) ;
F_41 ( V_2 ) ;
return 0 ;
}
static inline int F_68 ( void )
{
int V_103 = F_69 ( & V_170 ) ;
if ( V_103 )
F_59 ( V_158 L_22 ) ;
return V_103 ;
}
static inline void F_70 ( void )
{
F_71 ( & V_170 ) ;
}
static inline int F_68 ( void ) { return 0 ; }
static inline void F_70 ( void ) {}
static int T_2 F_72 ( void )
{
int V_103 ;
V_103 = F_57 () ;
if ( V_103 )
return V_103 ;
V_103 = F_68 () ;
if ( V_103 )
F_60 () ;
return V_103 ;
}
static void T_3 F_73 ( void )
{
F_70 () ;
F_60 () ;
}
