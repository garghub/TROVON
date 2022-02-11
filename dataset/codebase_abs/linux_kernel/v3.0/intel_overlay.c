static struct V_1 *
F_1 ( struct V_2 * V_3 )
{
T_1 * V_4 = V_3 -> V_5 -> V_6 ;
struct V_1 * V_7 ;
if ( F_2 ( V_3 -> V_5 ) )
V_7 = V_3 -> V_8 -> V_9 -> V_10 -> V_11 ;
else
V_7 = F_3 ( V_4 -> V_12 . V_13 ,
V_3 -> V_8 -> V_14 ) ;
return V_7 ;
}
static void F_4 ( struct V_2 * V_3 ,
struct V_1 * V_7 )
{
if ( ! F_2 ( V_3 -> V_5 ) )
F_5 ( V_7 ) ;
}
static int F_6 ( struct V_2 * V_3 ,
struct V_15 * V_16 ,
void (* F_7)( struct V_2 * ) )
{
struct V_17 * V_5 = V_3 -> V_5 ;
T_1 * V_4 = V_5 -> V_6 ;
int V_18 ;
F_8 ( V_3 -> V_19 ) ;
V_18 = F_9 ( F_10 ( V_4 ) , NULL , V_16 ) ;
if ( V_18 ) {
F_11 ( V_16 ) ;
return V_18 ;
}
V_3 -> V_19 = V_16 -> V_20 ;
V_3 -> V_21 = F_7 ;
V_18 = F_12 ( F_10 ( V_4 ) , V_3 -> V_19 ) ;
if ( V_18 )
return V_18 ;
V_3 -> V_19 = 0 ;
return 0 ;
}
static int
F_13 ( struct V_17 * V_5 )
{
T_1 * V_4 = V_5 -> V_6 ;
struct V_22 * V_23 ;
struct V_24 * V_25 ;
struct V_26 V_27 = {
F_14 ( L_1 , DRM_MODE_TYPE_DRIVER, 25175 , 640 , 656 ,
752 , 800 , 0 , 480 , 489 , 492 , 525 , 0 ,
DRM_MODE_FLAG_NHSYNC | DRM_MODE_FLAG_NVSYNC)
} , * V_28 ;
V_23 = F_15 ( V_4 -> V_29 [ 0 ] ) ;
if ( V_23 -> V_30 == V_31 )
return 0 ;
if ( F_16 ( V_32 ) & V_33 )
return 0 ;
V_25 = V_23 -> V_34 . V_35 ;
if ( V_25 -> V_36 == NULL )
return 0 ;
F_17 ( L_2 ) ;
V_28 = F_18 ( V_5 , & V_27 ) ;
F_19 ( V_28 , V_37 ) ;
if( ! F_20 ( & V_23 -> V_34 , V_28 ,
V_23 -> V_34 . V_38 , V_23 -> V_34 . V_39 ,
V_23 -> V_34 . V_40 ) )
return 0 ;
V_25 -> V_36 ( & V_23 -> V_34 , V_31 ) ;
return 1 ;
}
static void
F_21 ( struct V_17 * V_5 )
{
T_1 * V_4 = V_5 -> V_6 ;
struct V_41 * V_23 = V_4 -> V_29 [ 0 ] ;
struct V_24 * V_25 = V_23 -> V_35 ;
V_25 -> V_36 ( V_23 , V_42 ) ;
}
static int F_22 ( struct V_2 * V_3 )
{
struct V_17 * V_5 = V_3 -> V_5 ;
struct V_43 * V_4 = V_5 -> V_6 ;
struct V_15 * V_16 ;
int V_44 = 0 ;
int V_18 ;
F_8 ( V_3 -> V_45 ) ;
V_3 -> V_45 = 1 ;
if ( F_23 ( V_5 ) ) {
V_44 = F_13 ( V_5 ) ;
if ( V_44 < 0 )
return V_44 ;
}
V_16 = F_24 ( sizeof( * V_16 ) , V_46 ) ;
if ( V_16 == NULL ) {
V_18 = - V_47 ;
goto V_48;
}
V_18 = F_25 ( 4 ) ;
if ( V_18 ) {
F_11 ( V_16 ) ;
goto V_48;
}
F_26 ( V_49 | V_50 ) ;
F_26 ( V_3 -> V_51 | V_52 ) ;
F_26 ( V_53 | V_54 ) ;
F_26 ( V_55 ) ;
F_27 () ;
V_18 = F_6 ( V_3 , V_16 , NULL ) ;
V_48:
if ( V_44 )
F_21 ( V_5 ) ;
return V_18 ;
}
static int F_28 ( struct V_2 * V_3 ,
bool V_56 )
{
struct V_17 * V_5 = V_3 -> V_5 ;
T_1 * V_4 = V_5 -> V_6 ;
struct V_15 * V_16 ;
T_2 V_51 = V_3 -> V_51 ;
T_2 V_57 ;
int V_18 ;
F_8 ( ! V_3 -> V_45 ) ;
V_16 = F_24 ( sizeof( * V_16 ) , V_46 ) ;
if ( V_16 == NULL )
return - V_47 ;
if ( V_56 )
V_51 |= V_52 ;
V_57 = F_16 ( V_58 ) ;
if ( V_57 & ( 1 << 17 ) )
F_29 ( L_3 , V_57 ) ;
V_18 = F_25 ( 2 ) ;
if ( V_18 ) {
F_11 ( V_16 ) ;
return V_18 ;
}
F_26 ( V_49 | V_59 ) ;
F_26 ( V_51 ) ;
F_27 () ;
V_18 = F_9 ( F_10 ( V_4 ) , NULL , V_16 ) ;
if ( V_18 ) {
F_11 ( V_16 ) ;
return V_18 ;
}
V_3 -> V_19 = V_16 -> V_20 ;
return 0 ;
}
static void F_30 ( struct V_2 * V_3 )
{
struct V_60 * V_61 = V_3 -> V_62 ;
F_31 ( V_61 ) ;
F_32 ( & V_61 -> V_34 ) ;
V_3 -> V_62 = NULL ;
}
static void F_33 ( struct V_2 * V_3 )
{
struct V_60 * V_61 = V_3 -> V_63 ;
F_8 ( ! V_3 -> V_63 ) ;
F_31 ( V_61 ) ;
F_32 ( & V_61 -> V_34 ) ;
V_3 -> V_63 = NULL ;
V_3 -> V_23 -> V_3 = NULL ;
V_3 -> V_23 = NULL ;
V_3 -> V_45 = 0 ;
}
static int F_34 ( struct V_2 * V_3 )
{
struct V_17 * V_5 = V_3 -> V_5 ;
struct V_43 * V_4 = V_5 -> V_6 ;
T_2 V_51 = V_3 -> V_51 ;
struct V_15 * V_16 ;
int V_18 ;
F_8 ( ! V_3 -> V_45 ) ;
V_16 = F_24 ( sizeof( * V_16 ) , V_46 ) ;
if ( V_16 == NULL )
return - V_47 ;
V_51 |= V_52 ;
V_18 = F_25 ( 6 ) ;
if ( V_18 ) {
F_11 ( V_16 ) ;
return V_18 ;
}
F_26 ( V_49 | V_59 ) ;
F_26 ( V_51 ) ;
F_26 ( V_53 | V_54 ) ;
F_26 ( V_49 | V_64 ) ;
F_26 ( V_51 ) ;
F_26 ( V_53 | V_54 ) ;
F_27 () ;
return F_6 ( V_3 , V_16 ,
F_33 ) ;
}
static int F_35 ( struct V_2 * V_3 )
{
struct V_17 * V_5 = V_3 -> V_5 ;
T_1 * V_4 = V_5 -> V_6 ;
int V_18 ;
if ( V_3 -> V_19 == 0 )
return 0 ;
V_18 = F_12 ( F_10 ( V_4 ) , V_3 -> V_19 ) ;
if ( V_18 )
return V_18 ;
if ( V_3 -> V_21 )
V_3 -> V_21 ( V_3 ) ;
V_3 -> V_19 = 0 ;
return 0 ;
}
static int F_36 ( struct V_2 * V_3 )
{
struct V_17 * V_5 = V_3 -> V_5 ;
T_1 * V_4 = V_5 -> V_6 ;
int V_18 ;
if ( ! V_3 -> V_62 )
return 0 ;
if ( F_16 ( V_65 ) & V_66 ) {
struct V_15 * V_16 ;
V_16 = F_24 ( sizeof( * V_16 ) , V_46 ) ;
if ( V_16 == NULL )
return - V_47 ;
V_18 = F_25 ( 2 ) ;
if ( V_18 ) {
F_11 ( V_16 ) ;
return V_18 ;
}
F_26 ( V_53 | V_54 ) ;
F_26 ( V_55 ) ;
F_27 () ;
V_18 = F_6 ( V_3 , V_16 ,
F_30 ) ;
if ( V_18 )
return V_18 ;
}
F_30 ( V_3 ) ;
return 0 ;
}
static int F_37 ( T_2 V_67 )
{
switch ( V_67 & V_68 ) {
case V_69 :
return 4 ;
case V_70 :
default:
return - V_71 ;
}
}
static int F_38 ( T_2 V_67 , short V_72 )
{
switch ( V_67 & V_68 ) {
case V_69 :
return V_72 << 1 ;
default:
return - V_71 ;
}
}
static int F_39 ( T_2 V_67 )
{
switch ( V_67 & V_68 ) {
case V_69 :
case V_73 :
return 2 ;
case V_70 :
case V_74 :
return 4 ;
default:
return - V_71 ;
}
}
static int F_40 ( T_2 V_67 )
{
switch ( V_67 & V_68 ) {
case V_73 :
case V_74 :
return 2 ;
case V_69 :
case V_70 :
return 1 ;
default:
return - V_71 ;
}
}
static T_2 F_41 ( struct V_17 * V_5 , T_2 V_75 , T_2 V_72 )
{
T_2 V_76 , V_77 , V_18 ;
if ( F_42 ( V_5 ) ) {
V_76 = 0x1f ;
V_77 = 5 ;
} else {
V_76 = 0x3f ;
V_77 = 6 ;
}
V_18 = ( ( V_75 + V_72 + V_76 ) >> V_77 ) - ( V_75 >> V_77 ) ;
if ( ! F_42 ( V_5 ) )
V_18 <<= 1 ;
V_18 -= 1 ;
return V_18 << 2 ;
}
static void F_43 ( struct V_1 * V_7 )
{
memcpy ( V_7 -> V_78 , V_79 , sizeof( V_79 ) ) ;
memcpy ( V_7 -> V_80 , V_81 , sizeof( V_81 ) ) ;
}
static bool F_44 ( struct V_2 * V_3 ,
struct V_1 * V_7 ,
struct V_82 * V_83 )
{
T_2 V_84 , V_85 , V_86 , V_87 ;
#define F_45 12
#define F_46 0xfff
bool V_88 = false ;
int V_89 = F_39 ( V_83 -> V_67 ) ;
int V_90 = F_40 ( V_83 -> V_67 ) ;
if ( V_83 -> V_91 > 1 )
V_84 = ( ( V_83 -> V_92 - 1 ) << F_45 )
/ ( V_83 -> V_91 ) ;
else
V_84 = 1 << F_45 ;
if ( V_83 -> V_93 > 1 )
V_85 = ( ( V_83 -> V_94 - 1 ) << F_45 )
/ ( V_83 -> V_93 ) ;
else
V_85 = 1 << F_45 ;
V_86 = V_84 / V_89 ;
V_87 = V_85 / V_90 ;
V_84 = V_86 * V_89 ;
V_85 = V_87 * V_90 ;
if ( V_84 != V_3 -> V_95 || V_85 != V_3 -> V_96 )
V_88 = true ;
V_3 -> V_95 = V_84 ;
V_3 -> V_96 = V_85 ;
V_7 -> V_97 = ( ( ( V_85 & F_46 ) << 20 ) |
( ( V_84 >> F_45 ) << 16 ) |
( ( V_84 & F_46 ) << 3 ) ) ;
V_7 -> V_98 = ( ( ( V_87 & F_46 ) << 20 ) |
( ( V_86 >> F_45 ) << 16 ) |
( ( V_86 & F_46 ) << 3 ) ) ;
V_7 -> V_99 = ( ( ( ( V_85 >> F_45 ) << 16 ) |
( ( V_87 >> F_45 ) << 0 ) ) ) ;
if ( V_88 )
F_43 ( V_7 ) ;
return V_88 ;
}
static void F_47 ( struct V_2 * V_3 ,
struct V_1 * V_7 )
{
T_2 V_100 = V_3 -> V_101 ;
switch ( V_3 -> V_23 -> V_34 . V_40 -> V_102 ) {
case 8 :
V_7 -> V_103 = 0 ;
V_7 -> V_104 = V_105 | V_106 ;
break;
case 16 :
if ( V_3 -> V_23 -> V_34 . V_40 -> V_107 == 15 ) {
V_7 -> V_103 = F_48 ( V_100 ) ;
V_7 -> V_104 = V_108 | V_106 ;
} else {
V_7 -> V_103 = F_49 ( V_100 ) ;
V_7 -> V_104 = V_109 | V_106 ;
}
break;
case 24 :
case 32 :
V_7 -> V_103 = V_100 ;
V_7 -> V_104 = V_110 | V_106 ;
break;
}
}
static T_2 F_50 ( struct V_82 * V_83 )
{
T_2 V_111 = V_112 | V_113 | V_114 ;
if ( V_83 -> V_67 & V_115 ) {
switch ( V_83 -> V_67 & V_68 ) {
case V_69 :
V_111 |= V_116 ;
break;
case V_73 :
V_111 |= V_117 ;
break;
case V_70 :
case V_74 :
V_111 |= V_118 ;
break;
}
} else {
switch ( V_83 -> V_67 & V_68 ) {
case V_69 :
V_111 |= V_119 ;
break;
case V_70 :
V_111 |= V_120 ;
break;
}
switch ( V_83 -> V_67 & V_121 ) {
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
static int F_51 ( struct V_2 * V_3 ,
struct V_60 * V_129 ,
struct V_82 * V_83 )
{
int V_18 , V_130 ;
struct V_1 * V_7 ;
bool V_88 = false ;
struct V_17 * V_5 = V_3 -> V_5 ;
F_8 ( ! F_52 ( & V_5 -> V_131 ) ) ;
F_8 ( ! F_52 ( & V_5 -> V_132 . V_133 ) ) ;
F_8 ( ! V_3 ) ;
V_18 = F_36 ( V_3 ) ;
if ( V_18 != 0 )
return V_18 ;
V_18 = F_53 ( V_129 , V_134 , true ) ;
if ( V_18 != 0 )
return V_18 ;
V_18 = F_54 ( V_129 , 0 ) ;
if ( V_18 != 0 )
goto V_135;
V_18 = F_55 ( V_129 ) ;
if ( V_18 )
goto V_135;
if ( ! V_3 -> V_45 ) {
V_7 = F_1 ( V_3 ) ;
if ( ! V_7 ) {
V_18 = - V_47 ;
goto V_135;
}
V_7 -> V_136 = V_137 ;
if ( F_56 ( V_3 -> V_5 ) )
V_7 -> V_136 |= V_138 ;
V_7 -> V_136 |= V_3 -> V_23 -> V_139 == 0 ?
V_140 : V_141 ;
F_4 ( V_3 , V_7 ) ;
V_18 = F_22 ( V_3 ) ;
if ( V_18 != 0 )
goto V_135;
}
V_7 = F_1 ( V_3 ) ;
if ( ! V_7 ) {
V_18 = - V_47 ;
goto V_135;
}
V_7 -> V_142 = ( V_83 -> V_143 << 16 ) | V_83 -> V_144 ;
V_7 -> V_145 = ( V_83 -> V_93 << 16 ) | V_83 -> V_91 ;
if ( V_83 -> V_67 & V_146 )
V_130 = F_38 ( V_83 -> V_67 , V_83 -> V_147 ) ;
else
V_130 = V_83 -> V_147 ;
V_7 -> V_148 = V_83 -> V_147 ;
V_7 -> V_149 = F_41 ( V_3 -> V_5 ,
V_83 -> V_150 , V_130 ) ;
V_7 -> V_151 = V_83 -> V_152 ;
V_7 -> V_153 = V_129 -> V_14 + V_83 -> V_150 ;
V_7 -> V_154 = V_83 -> V_155 ;
if ( V_83 -> V_67 & V_115 ) {
int V_89 = F_39 ( V_83 -> V_67 ) ;
int V_90 = F_40 ( V_83 -> V_67 ) ;
T_2 V_156 , V_157 ;
V_7 -> V_148 |= ( V_83 -> V_147 / V_89 ) << 16 ;
V_156 = F_41 ( V_3 -> V_5 , V_83 -> V_158 ,
V_83 -> V_147 / V_89 ) ;
V_157 = F_41 ( V_3 -> V_5 , V_83 -> V_159 ,
V_83 -> V_147 / V_89 ) ;
V_7 -> V_149 |= F_57 ( T_2 , V_156 , V_157 ) << 16 ;
V_7 -> V_151 |= ( V_83 -> V_152 / V_90 ) << 16 ;
V_7 -> V_160 = V_129 -> V_14 + V_83 -> V_158 ;
V_7 -> V_161 = V_129 -> V_14 + V_83 -> V_159 ;
V_7 -> V_154 |= V_83 -> V_162 << 16 ;
}
V_88 = F_44 ( V_3 , V_7 , V_83 ) ;
F_47 ( V_3 , V_7 ) ;
V_7 -> V_163 = F_50 ( V_83 ) ;
F_4 ( V_3 , V_7 ) ;
V_18 = F_28 ( V_3 , V_88 ) ;
if ( V_18 )
goto V_135;
V_3 -> V_62 = V_3 -> V_63 ;
V_3 -> V_63 = V_129 ;
return 0 ;
V_135:
F_31 ( V_129 ) ;
return V_18 ;
}
int F_58 ( struct V_2 * V_3 )
{
struct V_1 * V_7 ;
struct V_17 * V_5 = V_3 -> V_5 ;
int V_18 ;
F_8 ( ! F_52 ( & V_5 -> V_131 ) ) ;
F_8 ( ! F_52 ( & V_5 -> V_132 . V_133 ) ) ;
V_18 = F_35 ( V_3 ) ;
if ( V_18 != 0 )
return V_18 ;
if ( ! V_3 -> V_45 )
return 0 ;
V_18 = F_36 ( V_3 ) ;
if ( V_18 != 0 )
return V_18 ;
V_7 = F_1 ( V_3 ) ;
V_7 -> V_163 = 0 ;
F_4 ( V_3 , V_7 ) ;
V_18 = F_34 ( V_3 ) ;
if ( V_18 != 0 )
return V_18 ;
F_33 ( V_3 ) ;
return 0 ;
}
static int F_59 ( struct V_2 * V_3 ,
struct V_22 * V_23 )
{
T_1 * V_4 = V_3 -> V_5 -> V_6 ;
if ( ! V_23 -> V_45 )
return - V_71 ;
if ( F_60 ( V_3 -> V_5 ) -> V_164 < 4 &&
( F_16 ( F_61 ( V_23 -> V_139 ) ) & ( V_165 | V_33 ) ) != V_33 )
return - V_71 ;
return 0 ;
}
static void F_62 ( struct V_2 * V_3 )
{
struct V_17 * V_5 = V_3 -> V_5 ;
T_1 * V_4 = V_5 -> V_6 ;
T_2 V_166 = F_16 ( V_167 ) ;
T_2 V_168 ;
if ( F_60 ( V_5 ) -> V_164 >= 4 ) {
V_168 = F_16 ( V_169 ) >> V_170 ;
} else {
if ( V_166 & V_171 )
V_168 = F_16 ( V_172 ) ;
else
V_168 = F_16 ( V_169 ) ;
V_168 >>= V_173 ;
}
V_3 -> V_174 = V_168 ;
}
static int F_63 ( struct V_2 * V_3 ,
struct V_175 * V_176 )
{
struct V_26 * V_28 = & V_3 -> V_23 -> V_34 . V_28 ;
if ( V_176 -> V_144 < V_28 -> V_177 &&
V_176 -> V_144 + V_176 -> V_178 <= V_28 -> V_177 &&
V_176 -> V_143 < V_28 -> V_179 &&
V_176 -> V_143 + V_176 -> V_180 <= V_28 -> V_179 )
return 0 ;
else
return - V_71 ;
}
static int F_64 ( struct V_82 * V_176 )
{
T_2 V_57 ;
V_57 = ( ( V_176 -> V_94 << 16 ) / V_176 -> V_93 ) >> 16 ;
if ( V_57 > 7 )
return - V_71 ;
V_57 = ( ( V_176 -> V_92 << 16 ) / V_176 -> V_91 ) >> 16 ;
if ( V_57 > 7 )
return - V_71 ;
return 0 ;
}
static int F_65 ( struct V_17 * V_5 ,
struct V_175 * V_176 ,
struct V_60 * V_129 )
{
int V_89 = F_39 ( V_176 -> V_181 ) ;
int V_90 = F_40 ( V_176 -> V_181 ) ;
T_2 V_182 ;
int V_107 ;
T_2 V_57 ;
if ( F_66 ( V_5 ) || F_23 ( V_5 ) ) {
if ( V_176 -> V_183 > V_184 ||
V_176 -> V_185 > V_186 )
return - V_71 ;
} else {
if ( V_176 -> V_183 > V_187 ||
V_176 -> V_185 > V_188 )
return - V_71 ;
}
if ( V_176 -> V_183 < V_189 * 4 ||
V_176 -> V_185 < V_190 * 4 )
return - V_71 ;
switch ( V_176 -> V_181 & V_191 ) {
case V_192 :
return - V_71 ;
case V_146 :
if ( V_90 != 1 )
return - V_71 ;
V_107 = F_37 ( V_176 -> V_181 ) ;
if ( V_107 < 0 )
return V_107 ;
V_176 -> V_162 = 0 ;
V_176 -> V_158 = 0 ;
V_176 -> V_159 = 0 ;
if ( V_176 -> V_150 % V_107 )
return - V_71 ;
break;
case V_115 :
if ( V_90 < 0 || V_89 < 0 )
return - V_71 ;
break;
default:
return - V_71 ;
}
if ( V_176 -> V_185 % V_89 )
return - V_71 ;
if ( F_23 ( V_5 ) || F_66 ( V_5 ) )
V_182 = 255 ;
else
V_182 = 63 ;
if ( V_176 -> V_155 & V_182 || V_176 -> V_162 & V_182 )
return - V_71 ;
if ( F_56 ( V_5 ) && V_176 -> V_155 < 512 )
return - V_71 ;
V_57 = ( V_176 -> V_181 & V_191 ) == V_115 ?
4096 : 8192 ;
if ( V_176 -> V_155 > V_57 || V_176 -> V_162 > 2 * 1024 )
return - V_71 ;
switch ( V_176 -> V_181 & V_191 ) {
case V_192 :
case V_146 :
if ( F_38 ( V_176 -> V_181 , V_176 -> V_185 ) > V_176 -> V_155 )
return - V_71 ;
V_57 = V_176 -> V_155 * V_176 -> V_183 ;
if ( V_176 -> V_150 + V_57 > V_129 -> V_34 . V_193 )
return - V_71 ;
break;
case V_115 :
if ( V_176 -> V_185 > V_176 -> V_155 )
return - V_71 ;
if ( V_176 -> V_185 / V_89 > V_176 -> V_162 )
return - V_71 ;
V_57 = V_176 -> V_155 * V_176 -> V_183 ;
if ( V_176 -> V_150 + V_57 > V_129 -> V_34 . V_193 )
return - V_71 ;
V_57 = V_176 -> V_162 * ( V_176 -> V_183 / V_90 ) ;
if ( V_176 -> V_158 + V_57 > V_129 -> V_34 . V_193 ||
V_176 -> V_159 + V_57 > V_129 -> V_34 . V_193 )
return - V_71 ;
break;
}
return 0 ;
}
static int F_67 ( struct V_17 * V_5 )
{
struct V_43 * V_4 = V_5 -> V_6 ;
T_2 V_166 ;
if ( F_23 ( V_5 ) )
return - 1 ;
V_166 = F_16 ( V_167 ) ;
if ( ( V_166 & V_194 ) == 0 )
return - 1 ;
if ( F_56 ( V_5 ) )
return ( V_166 >> 29 ) & 0x3 ;
return 1 ;
}
int F_68 ( struct V_17 * V_5 , void * V_195 ,
struct V_196 * V_197 )
{
struct V_175 * V_198 = V_195 ;
T_1 * V_4 = V_5 -> V_6 ;
struct V_2 * V_3 ;
struct V_199 * V_200 ;
struct V_22 * V_23 ;
struct V_60 * V_129 ;
struct V_82 * V_83 ;
int V_18 ;
if ( ! V_4 ) {
F_69 ( L_4 ) ;
return - V_71 ;
}
V_3 = V_4 -> V_3 ;
if ( ! V_3 ) {
F_29 ( L_5 ) ;
return - V_201 ;
}
if ( ! ( V_198 -> V_181 & V_202 ) ) {
F_70 ( & V_5 -> V_132 . V_133 ) ;
F_70 ( & V_5 -> V_131 ) ;
V_18 = F_58 ( V_3 ) ;
F_71 ( & V_5 -> V_131 ) ;
F_71 ( & V_5 -> V_132 . V_133 ) ;
return V_18 ;
}
V_83 = F_72 ( sizeof( struct V_82 ) , V_46 ) ;
if ( ! V_83 )
return - V_47 ;
V_200 = F_73 ( V_5 , V_198 -> V_203 ,
V_204 ) ;
if ( ! V_200 ) {
V_18 = - V_205 ;
goto V_206;
}
V_23 = F_15 ( F_74 ( V_200 ) ) ;
V_129 = F_75 ( F_76 ( V_5 , V_197 ,
V_198 -> V_207 ) ) ;
if ( & V_129 -> V_34 == NULL ) {
V_18 = - V_205 ;
goto V_206;
}
F_70 ( & V_5 -> V_132 . V_133 ) ;
F_70 ( & V_5 -> V_131 ) ;
if ( V_129 -> V_208 ) {
F_69 ( L_6 ) ;
V_18 = - V_71 ;
goto V_209;
}
V_18 = F_35 ( V_3 ) ;
if ( V_18 != 0 )
goto V_209;
if ( V_3 -> V_23 != V_23 ) {
struct V_26 * V_28 = & V_23 -> V_34 . V_28 ;
V_18 = F_58 ( V_3 ) ;
if ( V_18 != 0 )
goto V_209;
V_18 = F_59 ( V_3 , V_23 ) ;
if ( V_18 != 0 )
goto V_209;
V_3 -> V_23 = V_23 ;
V_23 -> V_3 = V_3 ;
if ( V_28 -> V_210 > 1024 &&
F_67 ( V_5 ) == V_23 -> V_139 ) {
V_3 -> V_211 = 1 ;
F_62 ( V_3 ) ;
} else
V_3 -> V_211 = 0 ;
}
V_18 = F_63 ( V_3 , V_198 ) ;
if ( V_18 != 0 )
goto V_209;
if ( V_3 -> V_211 ) {
V_83 -> V_143 = ( ( ( ( T_2 ) V_198 -> V_143 ) << 12 ) /
V_3 -> V_174 ) ;
V_83 -> V_93 = ( ( ( ( T_2 ) V_198 -> V_180 ) << 12 ) /
V_3 -> V_174 ) + 1 ;
} else {
V_83 -> V_143 = V_198 -> V_143 ;
V_83 -> V_93 = V_198 -> V_180 ;
}
V_83 -> V_144 = V_198 -> V_144 ;
V_83 -> V_91 = V_198 -> V_178 ;
V_83 -> V_147 = V_198 -> V_185 ;
V_83 -> V_152 = V_198 -> V_183 ;
V_83 -> V_92 = V_198 -> V_212 ;
V_83 -> V_94 = V_198 -> V_213 ;
if ( V_83 -> V_94 > V_83 -> V_152 ||
V_83 -> V_92 > V_83 -> V_147 ) {
V_18 = - V_71 ;
goto V_209;
}
V_18 = F_65 ( V_5 , V_198 , V_129 ) ;
if ( V_18 != 0 )
goto V_209;
V_83 -> V_67 = V_198 -> V_181 & ~ V_214 ;
V_83 -> V_155 = V_198 -> V_155 ;
V_83 -> V_162 = V_198 -> V_162 ;
V_83 -> V_150 = V_198 -> V_150 ;
V_83 -> V_158 = V_198 -> V_158 ;
V_83 -> V_159 = V_198 -> V_159 ;
V_18 = F_64 ( V_83 ) ;
if ( V_18 != 0 )
goto V_209;
V_18 = F_51 ( V_3 , V_129 , V_83 ) ;
if ( V_18 != 0 )
goto V_209;
F_71 ( & V_5 -> V_131 ) ;
F_71 ( & V_5 -> V_132 . V_133 ) ;
F_11 ( V_83 ) ;
return 0 ;
V_209:
F_71 ( & V_5 -> V_131 ) ;
F_71 ( & V_5 -> V_132 . V_133 ) ;
F_77 ( & V_129 -> V_34 ) ;
V_206:
F_11 ( V_83 ) ;
return V_18 ;
}
static void F_78 ( struct V_2 * V_3 ,
struct V_1 * V_7 )
{
V_7 -> V_215 = ( V_3 -> V_216 << 18 ) | ( V_3 -> V_217 & 0xff ) ;
V_7 -> V_218 = V_3 -> V_219 ;
}
static bool F_79 ( T_2 V_220 , T_2 V_221 )
{
int V_222 ;
if ( V_220 & 0xff000000 || V_221 & 0xff000000 )
return false ;
for ( V_222 = 0 ; V_222 < 3 ; V_222 ++ ) {
if ( ( ( V_220 >> V_222 * 8 ) & 0xff ) >= ( ( V_221 >> V_222 * 8 ) & 0xff ) )
return false ;
}
return true ;
}
static bool F_80 ( T_2 V_223 )
{
int V_222 ;
for ( V_222 = 0 ; V_222 < 3 ; V_222 ++ ) {
if ( ( ( V_223 >> V_222 * 8 ) & 0xff ) == 0x80 )
return false ;
}
return true ;
}
static int F_81 ( struct V_224 * V_225 )
{
if ( ! F_79 ( 0 , V_225 -> V_226 ) ||
! F_79 ( V_225 -> V_226 , V_225 -> V_220 ) ||
! F_79 ( V_225 -> V_220 , V_225 -> V_221 ) ||
! F_79 ( V_225 -> V_221 , V_225 -> V_227 ) ||
! F_79 ( V_225 -> V_227 , V_225 -> V_228 ) ||
! F_79 ( V_225 -> V_228 , V_225 -> V_223 ) ||
! F_79 ( V_225 -> V_223 , 0x00ffffff ) )
return - V_71 ;
if ( ! F_80 ( V_225 -> V_223 ) )
return - V_71 ;
return 0 ;
}
int F_82 ( struct V_17 * V_5 , void * V_195 ,
struct V_196 * V_197 )
{
struct V_224 * V_225 = V_195 ;
T_1 * V_4 = V_5 -> V_6 ;
struct V_2 * V_3 ;
struct V_1 * V_7 ;
int V_18 ;
if ( ! V_4 ) {
F_69 ( L_4 ) ;
return - V_71 ;
}
V_3 = V_4 -> V_3 ;
if ( ! V_3 ) {
F_29 ( L_5 ) ;
return - V_201 ;
}
F_70 ( & V_5 -> V_132 . V_133 ) ;
F_70 ( & V_5 -> V_131 ) ;
V_18 = - V_71 ;
if ( ! ( V_225 -> V_181 & V_229 ) ) {
V_225 -> V_101 = V_3 -> V_101 ;
V_225 -> V_217 = V_3 -> V_217 ;
V_225 -> V_216 = V_3 -> V_216 ;
V_225 -> V_219 = V_3 -> V_219 ;
if ( ! F_42 ( V_5 ) ) {
V_225 -> V_226 = F_16 ( V_230 ) ;
V_225 -> V_220 = F_16 ( V_231 ) ;
V_225 -> V_221 = F_16 ( V_232 ) ;
V_225 -> V_227 = F_16 ( V_233 ) ;
V_225 -> V_228 = F_16 ( V_234 ) ;
V_225 -> V_223 = F_16 ( V_235 ) ;
}
} else {
if ( V_225 -> V_217 < - 128 || V_225 -> V_217 > 127 )
goto V_209;
if ( V_225 -> V_216 > 255 )
goto V_209;
if ( V_225 -> V_219 > 1023 )
goto V_209;
V_3 -> V_101 = V_225 -> V_101 ;
V_3 -> V_217 = V_225 -> V_217 ;
V_3 -> V_216 = V_225 -> V_216 ;
V_3 -> V_219 = V_225 -> V_219 ;
V_7 = F_1 ( V_3 ) ;
if ( ! V_7 ) {
V_18 = - V_47 ;
goto V_209;
}
F_78 ( V_3 , V_7 ) ;
F_4 ( V_3 , V_7 ) ;
if ( V_225 -> V_181 & V_236 ) {
if ( F_42 ( V_5 ) )
goto V_209;
if ( V_3 -> V_45 ) {
V_18 = - V_237 ;
goto V_209;
}
V_18 = F_81 ( V_225 ) ;
if ( V_18 )
goto V_209;
F_83 ( V_230 , V_225 -> V_226 ) ;
F_83 ( V_231 , V_225 -> V_220 ) ;
F_83 ( V_232 , V_225 -> V_221 ) ;
F_83 ( V_233 , V_225 -> V_227 ) ;
F_83 ( V_234 , V_225 -> V_228 ) ;
F_83 ( V_235 , V_225 -> V_223 ) ;
}
}
V_18 = 0 ;
V_209:
F_71 ( & V_5 -> V_131 ) ;
F_71 ( & V_5 -> V_132 . V_133 ) ;
return V_18 ;
}
void F_84 ( struct V_17 * V_5 )
{
T_1 * V_4 = V_5 -> V_6 ;
struct V_2 * V_3 ;
struct V_60 * V_8 ;
struct V_1 * V_7 ;
int V_18 ;
if ( ! F_85 ( V_5 ) )
return;
V_3 = F_24 ( sizeof( struct V_2 ) , V_46 ) ;
if ( ! V_3 )
return;
F_70 ( & V_5 -> V_131 ) ;
if ( F_86 ( V_4 -> V_3 ) )
goto V_206;
V_3 -> V_5 = V_5 ;
V_8 = F_87 ( V_5 , V_134 ) ;
if ( ! V_8 )
goto V_206;
V_3 -> V_8 = V_8 ;
if ( F_2 ( V_5 ) ) {
V_18 = F_88 ( V_5 , V_8 ,
V_238 ,
V_134 ) ;
if ( V_18 ) {
F_69 ( L_7 ) ;
goto V_239;
}
V_3 -> V_51 = V_8 -> V_9 -> V_10 -> V_240 ;
} else {
V_18 = F_53 ( V_8 , V_134 , true ) ;
if ( V_18 ) {
F_69 ( L_8 ) ;
goto V_239;
}
V_3 -> V_51 = V_8 -> V_14 ;
V_18 = F_54 ( V_8 , true ) ;
if ( V_18 ) {
F_69 ( L_9 ) ;
goto V_241;
}
}
V_3 -> V_101 = 0x0101fe ;
V_3 -> V_217 = - 19 ;
V_3 -> V_216 = 75 ;
V_3 -> V_219 = 146 ;
V_7 = F_1 ( V_3 ) ;
if ( ! V_7 )
goto V_241;
memset ( V_7 , 0 , sizeof( struct V_1 ) ) ;
F_43 ( V_7 ) ;
F_78 ( V_3 , V_7 ) ;
F_4 ( V_3 , V_7 ) ;
V_4 -> V_3 = V_3 ;
F_71 ( & V_5 -> V_131 ) ;
F_89 ( L_10 ) ;
return;
V_241:
if ( ! F_2 ( V_5 ) )
F_31 ( V_8 ) ;
V_239:
F_32 ( & V_8 -> V_34 ) ;
V_206:
F_71 ( & V_5 -> V_131 ) ;
F_11 ( V_3 ) ;
return;
}
void F_90 ( struct V_17 * V_5 )
{
T_1 * V_4 = V_5 -> V_6 ;
if ( ! V_4 -> V_3 )
return;
F_8 ( V_4 -> V_3 -> V_45 ) ;
F_77 ( & V_4 -> V_3 -> V_8 -> V_34 ) ;
F_11 ( V_4 -> V_3 ) ;
}
static struct V_1 *
F_91 ( struct V_2 * V_3 )
{
T_1 * V_4 = V_3 -> V_5 -> V_6 ;
struct V_1 * V_7 ;
if ( F_2 ( V_3 -> V_5 ) )
V_7 = V_3 -> V_8 -> V_9 -> V_10 -> V_11 ;
else
V_7 = F_92 ( V_4 -> V_12 . V_13 ,
V_3 -> V_8 -> V_14 ) ;
return V_7 ;
}
static void F_93 ( struct V_2 * V_3 ,
struct V_1 * V_7 )
{
if ( ! F_2 ( V_3 -> V_5 ) )
F_94 ( V_7 ) ;
}
struct V_242 *
F_95 ( struct V_17 * V_5 )
{
T_1 * V_4 = V_5 -> V_6 ;
struct V_2 * V_3 = V_4 -> V_3 ;
struct V_242 * error ;
struct V_1 T_3 * V_7 ;
if ( ! V_3 || ! V_3 -> V_45 )
return NULL ;
error = F_72 ( sizeof( * error ) , V_243 ) ;
if ( error == NULL )
return NULL ;
error -> V_244 = F_16 ( V_58 ) ;
error -> V_245 = F_16 ( V_65 ) ;
if ( F_2 ( V_3 -> V_5 ) )
error -> V_34 = ( long ) V_3 -> V_8 -> V_9 -> V_10 -> V_11 ;
else
error -> V_34 = ( long ) V_3 -> V_8 -> V_14 ;
V_7 = F_91 ( V_3 ) ;
if ( ! V_7 )
goto V_246;
F_96 ( & error -> V_7 , V_7 , sizeof( struct V_1 ) ) ;
F_93 ( V_3 , V_7 ) ;
return error ;
V_246:
F_11 ( error ) ;
return NULL ;
}
void
F_97 ( struct V_247 * V_248 , struct V_242 * error )
{
F_98 ( V_248 , L_11 ,
error -> V_244 , error -> V_245 ) ;
F_98 ( V_248 , L_12 ,
error -> V_34 ) ;
#define F_99 ( V_38 ) seq_printf(m, " " #x ": 0x%08x\n", error->regs.x)
F_99 ( V_153 ) ;
F_99 ( V_249 ) ;
F_99 ( V_160 ) ;
F_99 ( V_161 ) ;
F_99 ( V_250 ) ;
F_99 ( V_251 ) ;
F_99 ( V_154 ) ;
F_99 ( V_252 ) ;
F_99 ( V_253 ) ;
F_99 ( V_254 ) ;
F_99 ( V_255 ) ;
F_99 ( V_142 ) ;
F_99 ( V_145 ) ;
F_99 ( V_148 ) ;
F_99 ( V_149 ) ;
F_99 ( V_151 ) ;
F_99 ( V_97 ) ;
F_99 ( V_98 ) ;
F_99 ( V_215 ) ;
F_99 ( V_218 ) ;
F_99 ( V_103 ) ;
F_99 ( V_104 ) ;
F_99 ( V_256 ) ;
F_99 ( V_257 ) ;
F_99 ( V_258 ) ;
F_99 ( V_136 ) ;
F_99 ( V_163 ) ;
F_99 ( V_259 ) ;
F_99 ( V_260 ) ;
F_99 ( V_261 ) ;
F_99 ( V_262 ) ;
F_99 ( V_263 ) ;
F_99 ( V_264 ) ;
F_99 ( V_265 ) ;
F_99 ( V_266 ) ;
F_99 ( V_267 ) ;
F_99 ( V_268 ) ;
F_99 ( V_269 ) ;
F_99 ( V_270 ) ;
F_99 ( V_271 ) ;
F_99 ( V_99 ) ;
#undef F_99
}
