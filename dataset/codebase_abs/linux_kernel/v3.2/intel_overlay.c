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
if ( ! F_20 ( & V_23 -> V_34 , V_28 ,
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
V_18 = F_53 ( V_129 , 0 , NULL ) ;
if ( V_18 != 0 )
return V_18 ;
V_18 = F_54 ( V_129 ) ;
if ( V_18 )
goto V_134;
if ( ! V_3 -> V_45 ) {
V_7 = F_1 ( V_3 ) ;
if ( ! V_7 ) {
V_18 = - V_47 ;
goto V_134;
}
V_7 -> V_135 = V_136 ;
if ( F_55 ( V_3 -> V_5 ) )
V_7 -> V_135 |= V_137 ;
V_7 -> V_135 |= V_3 -> V_23 -> V_138 == 0 ?
V_139 : V_140 ;
F_4 ( V_3 , V_7 ) ;
V_18 = F_22 ( V_3 ) ;
if ( V_18 != 0 )
goto V_134;
}
V_7 = F_1 ( V_3 ) ;
if ( ! V_7 ) {
V_18 = - V_47 ;
goto V_134;
}
V_7 -> V_141 = ( V_83 -> V_142 << 16 ) | V_83 -> V_143 ;
V_7 -> V_144 = ( V_83 -> V_93 << 16 ) | V_83 -> V_91 ;
if ( V_83 -> V_67 & V_145 )
V_130 = F_38 ( V_83 -> V_67 , V_83 -> V_146 ) ;
else
V_130 = V_83 -> V_146 ;
V_7 -> V_147 = V_83 -> V_146 ;
V_7 -> V_148 = F_41 ( V_3 -> V_5 ,
V_83 -> V_149 , V_130 ) ;
V_7 -> V_150 = V_83 -> V_151 ;
V_7 -> V_152 = V_129 -> V_14 + V_83 -> V_149 ;
V_7 -> V_153 = V_83 -> V_154 ;
if ( V_83 -> V_67 & V_115 ) {
int V_89 = F_39 ( V_83 -> V_67 ) ;
int V_90 = F_40 ( V_83 -> V_67 ) ;
T_2 V_155 , V_156 ;
V_7 -> V_147 |= ( V_83 -> V_146 / V_89 ) << 16 ;
V_155 = F_41 ( V_3 -> V_5 , V_83 -> V_157 ,
V_83 -> V_146 / V_89 ) ;
V_156 = F_41 ( V_3 -> V_5 , V_83 -> V_158 ,
V_83 -> V_146 / V_89 ) ;
V_7 -> V_148 |= F_56 ( T_2 , V_155 , V_156 ) << 16 ;
V_7 -> V_150 |= ( V_83 -> V_151 / V_90 ) << 16 ;
V_7 -> V_159 = V_129 -> V_14 + V_83 -> V_157 ;
V_7 -> V_160 = V_129 -> V_14 + V_83 -> V_158 ;
V_7 -> V_153 |= V_83 -> V_161 << 16 ;
}
V_88 = F_44 ( V_3 , V_7 , V_83 ) ;
F_47 ( V_3 , V_7 ) ;
V_7 -> V_162 = F_50 ( V_83 ) ;
F_4 ( V_3 , V_7 ) ;
V_18 = F_28 ( V_3 , V_88 ) ;
if ( V_18 )
goto V_134;
V_3 -> V_62 = V_3 -> V_63 ;
V_3 -> V_63 = V_129 ;
return 0 ;
V_134:
F_31 ( V_129 ) ;
return V_18 ;
}
int F_57 ( struct V_2 * V_3 )
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
V_7 -> V_162 = 0 ;
F_4 ( V_3 , V_7 ) ;
V_18 = F_34 ( V_3 ) ;
if ( V_18 != 0 )
return V_18 ;
F_33 ( V_3 ) ;
return 0 ;
}
static int F_58 ( struct V_2 * V_3 ,
struct V_22 * V_23 )
{
T_1 * V_4 = V_3 -> V_5 -> V_6 ;
if ( ! V_23 -> V_45 )
return - V_71 ;
if ( F_59 ( V_3 -> V_5 ) -> V_163 < 4 &&
( F_16 ( F_60 ( V_23 -> V_138 ) ) & ( V_164 | V_33 ) ) != V_33 )
return - V_71 ;
return 0 ;
}
static void F_61 ( struct V_2 * V_3 )
{
struct V_17 * V_5 = V_3 -> V_5 ;
T_1 * V_4 = V_5 -> V_6 ;
T_2 V_165 = F_16 ( V_166 ) ;
T_2 V_167 ;
if ( F_59 ( V_5 ) -> V_163 >= 4 ) {
V_167 = F_16 ( V_168 ) >> V_169 ;
} else {
if ( V_165 & V_170 )
V_167 = F_16 ( V_171 ) ;
else
V_167 = F_16 ( V_168 ) ;
V_167 >>= V_172 ;
}
V_3 -> V_173 = V_167 ;
}
static int F_62 ( struct V_2 * V_3 ,
struct V_174 * V_175 )
{
struct V_26 * V_28 = & V_3 -> V_23 -> V_34 . V_28 ;
if ( V_175 -> V_143 < V_28 -> V_176 &&
V_175 -> V_143 + V_175 -> V_177 <= V_28 -> V_176 &&
V_175 -> V_142 < V_28 -> V_178 &&
V_175 -> V_142 + V_175 -> V_179 <= V_28 -> V_178 )
return 0 ;
else
return - V_71 ;
}
static int F_63 ( struct V_82 * V_175 )
{
T_2 V_57 ;
V_57 = ( ( V_175 -> V_94 << 16 ) / V_175 -> V_93 ) >> 16 ;
if ( V_57 > 7 )
return - V_71 ;
V_57 = ( ( V_175 -> V_92 << 16 ) / V_175 -> V_91 ) >> 16 ;
if ( V_57 > 7 )
return - V_71 ;
return 0 ;
}
static int F_64 ( struct V_17 * V_5 ,
struct V_174 * V_175 ,
struct V_60 * V_129 )
{
int V_89 = F_39 ( V_175 -> V_180 ) ;
int V_90 = F_40 ( V_175 -> V_180 ) ;
T_2 V_181 ;
int V_107 ;
T_2 V_57 ;
if ( F_65 ( V_5 ) || F_23 ( V_5 ) ) {
if ( V_175 -> V_182 > V_183 ||
V_175 -> V_184 > V_185 )
return - V_71 ;
} else {
if ( V_175 -> V_182 > V_186 ||
V_175 -> V_184 > V_187 )
return - V_71 ;
}
if ( V_175 -> V_182 < V_188 * 4 ||
V_175 -> V_184 < V_189 * 4 )
return - V_71 ;
switch ( V_175 -> V_180 & V_190 ) {
case V_191 :
return - V_71 ;
case V_145 :
if ( V_90 != 1 )
return - V_71 ;
V_107 = F_37 ( V_175 -> V_180 ) ;
if ( V_107 < 0 )
return V_107 ;
V_175 -> V_161 = 0 ;
V_175 -> V_157 = 0 ;
V_175 -> V_158 = 0 ;
if ( V_175 -> V_149 % V_107 )
return - V_71 ;
break;
case V_115 :
if ( V_90 < 0 || V_89 < 0 )
return - V_71 ;
break;
default:
return - V_71 ;
}
if ( V_175 -> V_184 % V_89 )
return - V_71 ;
if ( F_23 ( V_5 ) || F_65 ( V_5 ) )
V_181 = 255 ;
else
V_181 = 63 ;
if ( V_175 -> V_154 & V_181 || V_175 -> V_161 & V_181 )
return - V_71 ;
if ( F_55 ( V_5 ) && V_175 -> V_154 < 512 )
return - V_71 ;
V_57 = ( V_175 -> V_180 & V_190 ) == V_115 ?
4096 : 8192 ;
if ( V_175 -> V_154 > V_57 || V_175 -> V_161 > 2 * 1024 )
return - V_71 ;
switch ( V_175 -> V_180 & V_190 ) {
case V_191 :
case V_145 :
if ( F_38 ( V_175 -> V_180 , V_175 -> V_184 ) > V_175 -> V_154 )
return - V_71 ;
V_57 = V_175 -> V_154 * V_175 -> V_182 ;
if ( V_175 -> V_149 + V_57 > V_129 -> V_34 . V_192 )
return - V_71 ;
break;
case V_115 :
if ( V_175 -> V_184 > V_175 -> V_154 )
return - V_71 ;
if ( V_175 -> V_184 / V_89 > V_175 -> V_161 )
return - V_71 ;
V_57 = V_175 -> V_154 * V_175 -> V_182 ;
if ( V_175 -> V_149 + V_57 > V_129 -> V_34 . V_192 )
return - V_71 ;
V_57 = V_175 -> V_161 * ( V_175 -> V_182 / V_90 ) ;
if ( V_175 -> V_157 + V_57 > V_129 -> V_34 . V_192 ||
V_175 -> V_158 + V_57 > V_129 -> V_34 . V_192 )
return - V_71 ;
break;
}
return 0 ;
}
static int F_66 ( struct V_17 * V_5 )
{
struct V_43 * V_4 = V_5 -> V_6 ;
T_2 V_165 ;
if ( F_23 ( V_5 ) )
return - 1 ;
V_165 = F_16 ( V_166 ) ;
if ( ( V_165 & V_193 ) == 0 )
return - 1 ;
if ( F_55 ( V_5 ) )
return ( V_165 >> 29 ) & 0x3 ;
return 1 ;
}
int F_67 ( struct V_17 * V_5 , void * V_194 ,
struct V_195 * V_196 )
{
struct V_174 * V_197 = V_194 ;
T_1 * V_4 = V_5 -> V_6 ;
struct V_2 * V_3 ;
struct V_198 * V_199 ;
struct V_22 * V_23 ;
struct V_60 * V_129 ;
struct V_82 * V_83 ;
int V_18 ;
if ( ! V_4 ) {
F_68 ( L_4 ) ;
return - V_71 ;
}
V_3 = V_4 -> V_3 ;
if ( ! V_3 ) {
F_29 ( L_5 ) ;
return - V_200 ;
}
if ( ! ( V_197 -> V_180 & V_201 ) ) {
F_69 ( & V_5 -> V_132 . V_133 ) ;
F_69 ( & V_5 -> V_131 ) ;
V_18 = F_57 ( V_3 ) ;
F_70 ( & V_5 -> V_131 ) ;
F_70 ( & V_5 -> V_132 . V_133 ) ;
return V_18 ;
}
V_83 = F_71 ( sizeof( struct V_82 ) , V_46 ) ;
if ( ! V_83 )
return - V_47 ;
V_199 = F_72 ( V_5 , V_197 -> V_202 ,
V_203 ) ;
if ( ! V_199 ) {
V_18 = - V_204 ;
goto V_205;
}
V_23 = F_15 ( F_73 ( V_199 ) ) ;
V_129 = F_74 ( F_75 ( V_5 , V_196 ,
V_197 -> V_206 ) ) ;
if ( & V_129 -> V_34 == NULL ) {
V_18 = - V_204 ;
goto V_205;
}
F_69 ( & V_5 -> V_132 . V_133 ) ;
F_69 ( & V_5 -> V_131 ) ;
if ( V_129 -> V_207 ) {
F_68 ( L_6 ) ;
V_18 = - V_71 ;
goto V_208;
}
V_18 = F_35 ( V_3 ) ;
if ( V_18 != 0 )
goto V_208;
if ( V_3 -> V_23 != V_23 ) {
struct V_26 * V_28 = & V_23 -> V_34 . V_28 ;
V_18 = F_57 ( V_3 ) ;
if ( V_18 != 0 )
goto V_208;
V_18 = F_58 ( V_3 , V_23 ) ;
if ( V_18 != 0 )
goto V_208;
V_3 -> V_23 = V_23 ;
V_23 -> V_3 = V_3 ;
if ( V_28 -> V_209 > 1024 &&
F_66 ( V_5 ) == V_23 -> V_138 ) {
V_3 -> V_210 = 1 ;
F_61 ( V_3 ) ;
} else
V_3 -> V_210 = 0 ;
}
V_18 = F_62 ( V_3 , V_197 ) ;
if ( V_18 != 0 )
goto V_208;
if ( V_3 -> V_210 ) {
V_83 -> V_142 = ( ( ( ( T_2 ) V_197 -> V_142 ) << 12 ) /
V_3 -> V_173 ) ;
V_83 -> V_93 = ( ( ( ( T_2 ) V_197 -> V_179 ) << 12 ) /
V_3 -> V_173 ) + 1 ;
} else {
V_83 -> V_142 = V_197 -> V_142 ;
V_83 -> V_93 = V_197 -> V_179 ;
}
V_83 -> V_143 = V_197 -> V_143 ;
V_83 -> V_91 = V_197 -> V_177 ;
V_83 -> V_146 = V_197 -> V_184 ;
V_83 -> V_151 = V_197 -> V_182 ;
V_83 -> V_92 = V_197 -> V_211 ;
V_83 -> V_94 = V_197 -> V_212 ;
if ( V_83 -> V_94 > V_83 -> V_151 ||
V_83 -> V_92 > V_83 -> V_146 ) {
V_18 = - V_71 ;
goto V_208;
}
V_18 = F_64 ( V_5 , V_197 , V_129 ) ;
if ( V_18 != 0 )
goto V_208;
V_83 -> V_67 = V_197 -> V_180 & ~ V_213 ;
V_83 -> V_154 = V_197 -> V_154 ;
V_83 -> V_161 = V_197 -> V_161 ;
V_83 -> V_149 = V_197 -> V_149 ;
V_83 -> V_157 = V_197 -> V_157 ;
V_83 -> V_158 = V_197 -> V_158 ;
V_18 = F_63 ( V_83 ) ;
if ( V_18 != 0 )
goto V_208;
V_18 = F_51 ( V_3 , V_129 , V_83 ) ;
if ( V_18 != 0 )
goto V_208;
F_70 ( & V_5 -> V_131 ) ;
F_70 ( & V_5 -> V_132 . V_133 ) ;
F_11 ( V_83 ) ;
return 0 ;
V_208:
F_70 ( & V_5 -> V_131 ) ;
F_70 ( & V_5 -> V_132 . V_133 ) ;
F_76 ( & V_129 -> V_34 ) ;
V_205:
F_11 ( V_83 ) ;
return V_18 ;
}
static void F_77 ( struct V_2 * V_3 ,
struct V_1 * V_7 )
{
V_7 -> V_214 = ( V_3 -> V_215 << 18 ) | ( V_3 -> V_216 & 0xff ) ;
V_7 -> V_217 = V_3 -> V_218 ;
}
static bool F_78 ( T_2 V_219 , T_2 V_220 )
{
int V_221 ;
if ( V_219 & 0xff000000 || V_220 & 0xff000000 )
return false ;
for ( V_221 = 0 ; V_221 < 3 ; V_221 ++ ) {
if ( ( ( V_219 >> V_221 * 8 ) & 0xff ) >= ( ( V_220 >> V_221 * 8 ) & 0xff ) )
return false ;
}
return true ;
}
static bool F_79 ( T_2 V_222 )
{
int V_221 ;
for ( V_221 = 0 ; V_221 < 3 ; V_221 ++ ) {
if ( ( ( V_222 >> V_221 * 8 ) & 0xff ) == 0x80 )
return false ;
}
return true ;
}
static int F_80 ( struct V_223 * V_224 )
{
if ( ! F_78 ( 0 , V_224 -> V_225 ) ||
! F_78 ( V_224 -> V_225 , V_224 -> V_219 ) ||
! F_78 ( V_224 -> V_219 , V_224 -> V_220 ) ||
! F_78 ( V_224 -> V_220 , V_224 -> V_226 ) ||
! F_78 ( V_224 -> V_226 , V_224 -> V_227 ) ||
! F_78 ( V_224 -> V_227 , V_224 -> V_222 ) ||
! F_78 ( V_224 -> V_222 , 0x00ffffff ) )
return - V_71 ;
if ( ! F_79 ( V_224 -> V_222 ) )
return - V_71 ;
return 0 ;
}
int F_81 ( struct V_17 * V_5 , void * V_194 ,
struct V_195 * V_196 )
{
struct V_223 * V_224 = V_194 ;
T_1 * V_4 = V_5 -> V_6 ;
struct V_2 * V_3 ;
struct V_1 * V_7 ;
int V_18 ;
if ( ! V_4 ) {
F_68 ( L_4 ) ;
return - V_71 ;
}
V_3 = V_4 -> V_3 ;
if ( ! V_3 ) {
F_29 ( L_5 ) ;
return - V_200 ;
}
F_69 ( & V_5 -> V_132 . V_133 ) ;
F_69 ( & V_5 -> V_131 ) ;
V_18 = - V_71 ;
if ( ! ( V_224 -> V_180 & V_228 ) ) {
V_224 -> V_101 = V_3 -> V_101 ;
V_224 -> V_216 = V_3 -> V_216 ;
V_224 -> V_215 = V_3 -> V_215 ;
V_224 -> V_218 = V_3 -> V_218 ;
if ( ! F_42 ( V_5 ) ) {
V_224 -> V_225 = F_16 ( V_229 ) ;
V_224 -> V_219 = F_16 ( V_230 ) ;
V_224 -> V_220 = F_16 ( V_231 ) ;
V_224 -> V_226 = F_16 ( V_232 ) ;
V_224 -> V_227 = F_16 ( V_233 ) ;
V_224 -> V_222 = F_16 ( V_234 ) ;
}
} else {
if ( V_224 -> V_216 < - 128 || V_224 -> V_216 > 127 )
goto V_208;
if ( V_224 -> V_215 > 255 )
goto V_208;
if ( V_224 -> V_218 > 1023 )
goto V_208;
V_3 -> V_101 = V_224 -> V_101 ;
V_3 -> V_216 = V_224 -> V_216 ;
V_3 -> V_215 = V_224 -> V_215 ;
V_3 -> V_218 = V_224 -> V_218 ;
V_7 = F_1 ( V_3 ) ;
if ( ! V_7 ) {
V_18 = - V_47 ;
goto V_208;
}
F_77 ( V_3 , V_7 ) ;
F_4 ( V_3 , V_7 ) ;
if ( V_224 -> V_180 & V_235 ) {
if ( F_42 ( V_5 ) )
goto V_208;
if ( V_3 -> V_45 ) {
V_18 = - V_236 ;
goto V_208;
}
V_18 = F_80 ( V_224 ) ;
if ( V_18 )
goto V_208;
F_82 ( V_229 , V_224 -> V_225 ) ;
F_82 ( V_230 , V_224 -> V_219 ) ;
F_82 ( V_231 , V_224 -> V_220 ) ;
F_82 ( V_232 , V_224 -> V_226 ) ;
F_82 ( V_233 , V_224 -> V_227 ) ;
F_82 ( V_234 , V_224 -> V_222 ) ;
}
}
V_18 = 0 ;
V_208:
F_70 ( & V_5 -> V_131 ) ;
F_70 ( & V_5 -> V_132 . V_133 ) ;
return V_18 ;
}
void F_83 ( struct V_17 * V_5 )
{
T_1 * V_4 = V_5 -> V_6 ;
struct V_2 * V_3 ;
struct V_60 * V_8 ;
struct V_1 * V_7 ;
int V_18 ;
if ( ! F_84 ( V_5 ) )
return;
V_3 = F_24 ( sizeof( struct V_2 ) , V_46 ) ;
if ( ! V_3 )
return;
F_69 ( & V_5 -> V_131 ) ;
if ( F_85 ( V_4 -> V_3 ) )
goto V_205;
V_3 -> V_5 = V_5 ;
V_8 = F_86 ( V_5 , V_237 ) ;
if ( ! V_8 )
goto V_205;
V_3 -> V_8 = V_8 ;
if ( F_2 ( V_5 ) ) {
V_18 = F_87 ( V_5 , V_8 ,
V_238 ,
V_237 ) ;
if ( V_18 ) {
F_68 ( L_7 ) ;
goto V_239;
}
V_3 -> V_51 = V_8 -> V_9 -> V_10 -> V_240 ;
} else {
V_18 = F_88 ( V_8 , V_237 , true ) ;
if ( V_18 ) {
F_68 ( L_8 ) ;
goto V_239;
}
V_3 -> V_51 = V_8 -> V_14 ;
V_18 = F_89 ( V_8 , true ) ;
if ( V_18 ) {
F_68 ( L_9 ) ;
goto V_241;
}
}
V_3 -> V_101 = 0x0101fe ;
V_3 -> V_216 = - 19 ;
V_3 -> V_215 = 75 ;
V_3 -> V_218 = 146 ;
V_7 = F_1 ( V_3 ) ;
if ( ! V_7 )
goto V_241;
memset ( V_7 , 0 , sizeof( struct V_1 ) ) ;
F_43 ( V_7 ) ;
F_77 ( V_3 , V_7 ) ;
F_4 ( V_3 , V_7 ) ;
V_4 -> V_3 = V_3 ;
F_70 ( & V_5 -> V_131 ) ;
F_90 ( L_10 ) ;
return;
V_241:
if ( ! F_2 ( V_5 ) )
F_31 ( V_8 ) ;
V_239:
F_32 ( & V_8 -> V_34 ) ;
V_205:
F_70 ( & V_5 -> V_131 ) ;
F_11 ( V_3 ) ;
return;
}
void F_91 ( struct V_17 * V_5 )
{
T_1 * V_4 = V_5 -> V_6 ;
if ( ! V_4 -> V_3 )
return;
F_8 ( V_4 -> V_3 -> V_45 ) ;
F_76 ( & V_4 -> V_3 -> V_8 -> V_34 ) ;
F_11 ( V_4 -> V_3 ) ;
}
static struct V_1 *
F_92 ( struct V_2 * V_3 )
{
T_1 * V_4 = V_3 -> V_5 -> V_6 ;
struct V_1 * V_7 ;
if ( F_2 ( V_3 -> V_5 ) )
V_7 = V_3 -> V_8 -> V_9 -> V_10 -> V_11 ;
else
V_7 = F_93 ( V_4 -> V_12 . V_13 ,
V_3 -> V_8 -> V_14 ) ;
return V_7 ;
}
static void F_94 ( struct V_2 * V_3 ,
struct V_1 * V_7 )
{
if ( ! F_2 ( V_3 -> V_5 ) )
F_95 ( V_7 ) ;
}
struct V_242 *
F_96 ( struct V_17 * V_5 )
{
T_1 * V_4 = V_5 -> V_6 ;
struct V_2 * V_3 = V_4 -> V_3 ;
struct V_242 * error ;
struct V_1 T_3 * V_7 ;
if ( ! V_3 || ! V_3 -> V_45 )
return NULL ;
error = F_71 ( sizeof( * error ) , V_243 ) ;
if ( error == NULL )
return NULL ;
error -> V_244 = F_16 ( V_58 ) ;
error -> V_245 = F_16 ( V_65 ) ;
if ( F_2 ( V_3 -> V_5 ) )
error -> V_34 = ( long ) V_3 -> V_8 -> V_9 -> V_10 -> V_11 ;
else
error -> V_34 = ( long ) V_3 -> V_8 -> V_14 ;
V_7 = F_92 ( V_3 ) ;
if ( ! V_7 )
goto V_246;
F_97 ( & error -> V_7 , V_7 , sizeof( struct V_1 ) ) ;
F_94 ( V_3 , V_7 ) ;
return error ;
V_246:
F_11 ( error ) ;
return NULL ;
}
void
F_98 ( struct V_247 * V_248 , struct V_242 * error )
{
F_99 ( V_248 , L_11 ,
error -> V_244 , error -> V_245 ) ;
F_99 ( V_248 , L_12 ,
error -> V_34 ) ;
#define F_100 ( V_38 ) seq_printf(m, " " #x ": 0x%08x\n", error->regs.x)
F_100 ( V_152 ) ;
F_100 ( V_249 ) ;
F_100 ( V_159 ) ;
F_100 ( V_160 ) ;
F_100 ( V_250 ) ;
F_100 ( V_251 ) ;
F_100 ( V_153 ) ;
F_100 ( V_252 ) ;
F_100 ( V_253 ) ;
F_100 ( V_254 ) ;
F_100 ( V_255 ) ;
F_100 ( V_141 ) ;
F_100 ( V_144 ) ;
F_100 ( V_147 ) ;
F_100 ( V_148 ) ;
F_100 ( V_150 ) ;
F_100 ( V_97 ) ;
F_100 ( V_98 ) ;
F_100 ( V_214 ) ;
F_100 ( V_217 ) ;
F_100 ( V_103 ) ;
F_100 ( V_104 ) ;
F_100 ( V_256 ) ;
F_100 ( V_257 ) ;
F_100 ( V_258 ) ;
F_100 ( V_135 ) ;
F_100 ( V_162 ) ;
F_100 ( V_259 ) ;
F_100 ( V_260 ) ;
F_100 ( V_261 ) ;
F_100 ( V_262 ) ;
F_100 ( V_263 ) ;
F_100 ( V_264 ) ;
F_100 ( V_265 ) ;
F_100 ( V_266 ) ;
F_100 ( V_267 ) ;
F_100 ( V_268 ) ;
F_100 ( V_269 ) ;
F_100 ( V_270 ) ;
F_100 ( V_271 ) ;
F_100 ( V_99 ) ;
#undef F_100
}
