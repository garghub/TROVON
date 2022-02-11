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
V_18 = F_12 ( F_10 ( V_4 ) , V_3 -> V_19 ,
true ) ;
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
F_19 ( V_28 , 0 ) ;
if ( ! F_20 ( & V_23 -> V_34 , V_28 ,
V_23 -> V_34 . V_37 , V_23 -> V_34 . V_38 ,
V_23 -> V_34 . V_39 ) )
return 0 ;
V_25 -> V_36 ( & V_23 -> V_34 , V_31 ) ;
return 1 ;
}
static void
F_21 ( struct V_17 * V_5 )
{
T_1 * V_4 = V_5 -> V_6 ;
struct V_40 * V_23 = V_4 -> V_29 [ 0 ] ;
struct V_24 * V_25 = V_23 -> V_35 ;
V_25 -> V_36 ( V_23 , V_41 ) ;
}
static int F_22 ( struct V_2 * V_3 )
{
struct V_17 * V_5 = V_3 -> V_5 ;
struct V_42 * V_4 = V_5 -> V_6 ;
struct V_15 * V_16 ;
int V_43 = 0 ;
int V_18 ;
F_8 ( V_3 -> V_44 ) ;
V_3 -> V_44 = 1 ;
if ( F_23 ( V_5 ) ) {
V_43 = F_13 ( V_5 ) ;
if ( V_43 < 0 )
return V_43 ;
}
V_16 = F_24 ( sizeof( * V_16 ) , V_45 ) ;
if ( V_16 == NULL ) {
V_18 = - V_46 ;
goto V_47;
}
V_18 = F_25 ( 4 ) ;
if ( V_18 ) {
F_11 ( V_16 ) ;
goto V_47;
}
F_26 ( V_48 | V_49 ) ;
F_26 ( V_3 -> V_50 | V_51 ) ;
F_26 ( V_52 | V_53 ) ;
F_26 ( V_54 ) ;
F_27 () ;
V_18 = F_6 ( V_3 , V_16 , NULL ) ;
V_47:
if ( V_43 )
F_21 ( V_5 ) ;
return V_18 ;
}
static int F_28 ( struct V_2 * V_3 ,
bool V_55 )
{
struct V_17 * V_5 = V_3 -> V_5 ;
T_1 * V_4 = V_5 -> V_6 ;
struct V_15 * V_16 ;
T_2 V_50 = V_3 -> V_50 ;
T_2 V_56 ;
int V_18 ;
F_8 ( ! V_3 -> V_44 ) ;
V_16 = F_24 ( sizeof( * V_16 ) , V_45 ) ;
if ( V_16 == NULL )
return - V_46 ;
if ( V_55 )
V_50 |= V_51 ;
V_56 = F_16 ( V_57 ) ;
if ( V_56 & ( 1 << 17 ) )
F_29 ( L_3 , V_56 ) ;
V_18 = F_25 ( 2 ) ;
if ( V_18 ) {
F_11 ( V_16 ) ;
return V_18 ;
}
F_26 ( V_48 | V_58 ) ;
F_26 ( V_50 ) ;
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
struct V_59 * V_60 = V_3 -> V_61 ;
F_31 ( V_60 ) ;
F_32 ( & V_60 -> V_34 ) ;
V_3 -> V_61 = NULL ;
}
static void F_33 ( struct V_2 * V_3 )
{
struct V_59 * V_60 = V_3 -> V_62 ;
F_8 ( ! V_3 -> V_62 ) ;
F_31 ( V_60 ) ;
F_32 ( & V_60 -> V_34 ) ;
V_3 -> V_62 = NULL ;
V_3 -> V_23 -> V_3 = NULL ;
V_3 -> V_23 = NULL ;
V_3 -> V_44 = 0 ;
}
static int F_34 ( struct V_2 * V_3 )
{
struct V_17 * V_5 = V_3 -> V_5 ;
struct V_42 * V_4 = V_5 -> V_6 ;
T_2 V_50 = V_3 -> V_50 ;
struct V_15 * V_16 ;
int V_18 ;
F_8 ( ! V_3 -> V_44 ) ;
V_16 = F_24 ( sizeof( * V_16 ) , V_45 ) ;
if ( V_16 == NULL )
return - V_46 ;
V_50 |= V_51 ;
V_18 = F_25 ( 6 ) ;
if ( V_18 ) {
F_11 ( V_16 ) ;
return V_18 ;
}
F_26 ( V_48 | V_58 ) ;
F_26 ( V_50 ) ;
F_26 ( V_52 | V_53 ) ;
F_26 ( V_48 | V_63 ) ;
F_26 ( V_50 ) ;
F_26 ( V_52 | V_53 ) ;
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
V_18 = F_12 ( F_10 ( V_4 ) , V_3 -> V_19 ,
true ) ;
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
if ( ! V_3 -> V_61 )
return 0 ;
if ( F_16 ( V_64 ) & V_65 ) {
struct V_15 * V_16 ;
V_16 = F_24 ( sizeof( * V_16 ) , V_45 ) ;
if ( V_16 == NULL )
return - V_46 ;
V_18 = F_25 ( 2 ) ;
if ( V_18 ) {
F_11 ( V_16 ) ;
return V_18 ;
}
F_26 ( V_52 | V_53 ) ;
F_26 ( V_54 ) ;
F_27 () ;
V_18 = F_6 ( V_3 , V_16 ,
F_30 ) ;
if ( V_18 )
return V_18 ;
}
F_30 ( V_3 ) ;
return 0 ;
}
static int F_37 ( T_2 V_66 )
{
switch ( V_66 & V_67 ) {
case V_68 :
return 4 ;
case V_69 :
default:
return - V_70 ;
}
}
static int F_38 ( T_2 V_66 , short V_71 )
{
switch ( V_66 & V_67 ) {
case V_68 :
return V_71 << 1 ;
default:
return - V_70 ;
}
}
static int F_39 ( T_2 V_66 )
{
switch ( V_66 & V_67 ) {
case V_68 :
case V_72 :
return 2 ;
case V_69 :
case V_73 :
return 4 ;
default:
return - V_70 ;
}
}
static int F_40 ( T_2 V_66 )
{
switch ( V_66 & V_67 ) {
case V_72 :
case V_73 :
return 2 ;
case V_68 :
case V_69 :
return 1 ;
default:
return - V_70 ;
}
}
static T_2 F_41 ( struct V_17 * V_5 , T_2 V_74 , T_2 V_71 )
{
T_2 V_75 , V_76 , V_18 ;
if ( F_42 ( V_5 ) ) {
V_75 = 0x1f ;
V_76 = 5 ;
} else {
V_75 = 0x3f ;
V_76 = 6 ;
}
V_18 = ( ( V_74 + V_71 + V_75 ) >> V_76 ) - ( V_74 >> V_76 ) ;
if ( ! F_42 ( V_5 ) )
V_18 <<= 1 ;
V_18 -= 1 ;
return V_18 << 2 ;
}
static void F_43 ( struct V_1 * V_7 )
{
memcpy ( V_7 -> V_77 , V_78 , sizeof( V_78 ) ) ;
memcpy ( V_7 -> V_79 , V_80 , sizeof( V_80 ) ) ;
}
static bool F_44 ( struct V_2 * V_3 ,
struct V_1 * V_7 ,
struct V_81 * V_82 )
{
T_2 V_83 , V_84 , V_85 , V_86 ;
#define F_45 12
#define F_46 0xfff
bool V_87 = false ;
int V_88 = F_39 ( V_82 -> V_66 ) ;
int V_89 = F_40 ( V_82 -> V_66 ) ;
if ( V_82 -> V_90 > 1 )
V_83 = ( ( V_82 -> V_91 - 1 ) << F_45 )
/ ( V_82 -> V_90 ) ;
else
V_83 = 1 << F_45 ;
if ( V_82 -> V_92 > 1 )
V_84 = ( ( V_82 -> V_93 - 1 ) << F_45 )
/ ( V_82 -> V_92 ) ;
else
V_84 = 1 << F_45 ;
V_85 = V_83 / V_88 ;
V_86 = V_84 / V_89 ;
V_83 = V_85 * V_88 ;
V_84 = V_86 * V_89 ;
if ( V_83 != V_3 -> V_94 || V_84 != V_3 -> V_95 )
V_87 = true ;
V_3 -> V_94 = V_83 ;
V_3 -> V_95 = V_84 ;
V_7 -> V_96 = ( ( ( V_84 & F_46 ) << 20 ) |
( ( V_83 >> F_45 ) << 16 ) |
( ( V_83 & F_46 ) << 3 ) ) ;
V_7 -> V_97 = ( ( ( V_86 & F_46 ) << 20 ) |
( ( V_85 >> F_45 ) << 16 ) |
( ( V_85 & F_46 ) << 3 ) ) ;
V_7 -> V_98 = ( ( ( ( V_84 >> F_45 ) << 16 ) |
( ( V_86 >> F_45 ) << 0 ) ) ) ;
if ( V_87 )
F_43 ( V_7 ) ;
return V_87 ;
}
static void F_47 ( struct V_2 * V_3 ,
struct V_1 * V_7 )
{
T_2 V_99 = V_3 -> V_100 ;
switch ( V_3 -> V_23 -> V_34 . V_39 -> V_101 ) {
case 8 :
V_7 -> V_102 = 0 ;
V_7 -> V_103 = V_104 | V_105 ;
break;
case 16 :
if ( V_3 -> V_23 -> V_34 . V_39 -> V_106 == 15 ) {
V_7 -> V_102 = F_48 ( V_99 ) ;
V_7 -> V_103 = V_107 | V_105 ;
} else {
V_7 -> V_102 = F_49 ( V_99 ) ;
V_7 -> V_103 = V_108 | V_105 ;
}
break;
case 24 :
case 32 :
V_7 -> V_102 = V_99 ;
V_7 -> V_103 = V_109 | V_105 ;
break;
}
}
static T_2 F_50 ( struct V_81 * V_82 )
{
T_2 V_110 = V_111 | V_112 | V_113 ;
if ( V_82 -> V_66 & V_114 ) {
switch ( V_82 -> V_66 & V_67 ) {
case V_68 :
V_110 |= V_115 ;
break;
case V_72 :
V_110 |= V_116 ;
break;
case V_69 :
case V_73 :
V_110 |= V_117 ;
break;
}
} else {
switch ( V_82 -> V_66 & V_67 ) {
case V_68 :
V_110 |= V_118 ;
break;
case V_69 :
V_110 |= V_119 ;
break;
}
switch ( V_82 -> V_66 & V_120 ) {
case V_121 :
break;
case V_122 :
V_110 |= V_123 ;
break;
case V_124 :
V_110 |= V_125 ;
break;
case V_126 :
V_110 |= V_127 ;
break;
}
}
return V_110 ;
}
static int F_51 ( struct V_2 * V_3 ,
struct V_59 * V_128 ,
struct V_81 * V_82 )
{
int V_18 , V_129 ;
struct V_1 * V_7 ;
bool V_87 = false ;
struct V_17 * V_5 = V_3 -> V_5 ;
F_8 ( ! F_52 ( & V_5 -> V_130 ) ) ;
F_8 ( ! F_52 ( & V_5 -> V_131 . V_132 ) ) ;
F_8 ( ! V_3 ) ;
V_18 = F_36 ( V_3 ) ;
if ( V_18 != 0 )
return V_18 ;
V_18 = F_53 ( V_128 , 0 , NULL ) ;
if ( V_18 != 0 )
return V_18 ;
V_18 = F_54 ( V_128 ) ;
if ( V_18 )
goto V_133;
if ( ! V_3 -> V_44 ) {
V_7 = F_1 ( V_3 ) ;
if ( ! V_7 ) {
V_18 = - V_46 ;
goto V_133;
}
V_7 -> V_134 = V_135 ;
if ( F_55 ( V_3 -> V_5 ) )
V_7 -> V_134 |= V_136 ;
V_7 -> V_134 |= V_3 -> V_23 -> V_137 == 0 ?
V_138 : V_139 ;
F_4 ( V_3 , V_7 ) ;
V_18 = F_22 ( V_3 ) ;
if ( V_18 != 0 )
goto V_133;
}
V_7 = F_1 ( V_3 ) ;
if ( ! V_7 ) {
V_18 = - V_46 ;
goto V_133;
}
V_7 -> V_140 = ( V_82 -> V_141 << 16 ) | V_82 -> V_142 ;
V_7 -> V_143 = ( V_82 -> V_92 << 16 ) | V_82 -> V_90 ;
if ( V_82 -> V_66 & V_144 )
V_129 = F_38 ( V_82 -> V_66 , V_82 -> V_145 ) ;
else
V_129 = V_82 -> V_145 ;
V_7 -> V_146 = V_82 -> V_145 ;
V_7 -> V_147 = F_41 ( V_3 -> V_5 ,
V_82 -> V_148 , V_129 ) ;
V_7 -> V_149 = V_82 -> V_150 ;
V_7 -> V_151 = V_128 -> V_14 + V_82 -> V_148 ;
V_7 -> V_152 = V_82 -> V_153 ;
if ( V_82 -> V_66 & V_114 ) {
int V_88 = F_39 ( V_82 -> V_66 ) ;
int V_89 = F_40 ( V_82 -> V_66 ) ;
T_2 V_154 , V_155 ;
V_7 -> V_146 |= ( V_82 -> V_145 / V_88 ) << 16 ;
V_154 = F_41 ( V_3 -> V_5 , V_82 -> V_156 ,
V_82 -> V_145 / V_88 ) ;
V_155 = F_41 ( V_3 -> V_5 , V_82 -> V_157 ,
V_82 -> V_145 / V_88 ) ;
V_7 -> V_147 |= F_56 ( T_2 , V_154 , V_155 ) << 16 ;
V_7 -> V_149 |= ( V_82 -> V_150 / V_89 ) << 16 ;
V_7 -> V_158 = V_128 -> V_14 + V_82 -> V_156 ;
V_7 -> V_159 = V_128 -> V_14 + V_82 -> V_157 ;
V_7 -> V_152 |= V_82 -> V_160 << 16 ;
}
V_87 = F_44 ( V_3 , V_7 , V_82 ) ;
F_47 ( V_3 , V_7 ) ;
V_7 -> V_161 = F_50 ( V_82 ) ;
F_4 ( V_3 , V_7 ) ;
V_18 = F_28 ( V_3 , V_87 ) ;
if ( V_18 )
goto V_133;
V_3 -> V_61 = V_3 -> V_62 ;
V_3 -> V_62 = V_128 ;
return 0 ;
V_133:
F_31 ( V_128 ) ;
return V_18 ;
}
int F_57 ( struct V_2 * V_3 )
{
struct V_1 * V_7 ;
struct V_17 * V_5 = V_3 -> V_5 ;
int V_18 ;
F_8 ( ! F_52 ( & V_5 -> V_130 ) ) ;
F_8 ( ! F_52 ( & V_5 -> V_131 . V_132 ) ) ;
V_18 = F_35 ( V_3 ) ;
if ( V_18 != 0 )
return V_18 ;
if ( ! V_3 -> V_44 )
return 0 ;
V_18 = F_36 ( V_3 ) ;
if ( V_18 != 0 )
return V_18 ;
V_7 = F_1 ( V_3 ) ;
V_7 -> V_161 = 0 ;
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
if ( ! V_23 -> V_44 )
return - V_70 ;
if ( F_59 ( V_3 -> V_5 ) -> V_162 < 4 &&
( F_16 ( F_60 ( V_23 -> V_137 ) ) & ( V_163 | V_33 ) ) != V_33 )
return - V_70 ;
return 0 ;
}
static void F_61 ( struct V_2 * V_3 )
{
struct V_17 * V_5 = V_3 -> V_5 ;
T_1 * V_4 = V_5 -> V_6 ;
T_2 V_164 = F_16 ( V_165 ) ;
T_2 V_166 ;
if ( F_59 ( V_5 ) -> V_162 >= 4 ) {
V_166 = F_16 ( V_167 ) >> V_168 ;
} else {
if ( V_164 & V_169 )
V_166 = F_16 ( V_170 ) ;
else
V_166 = F_16 ( V_167 ) ;
V_166 >>= V_171 ;
}
V_3 -> V_172 = V_166 ;
}
static int F_62 ( struct V_2 * V_3 ,
struct V_173 * V_174 )
{
struct V_26 * V_28 = & V_3 -> V_23 -> V_34 . V_28 ;
if ( V_174 -> V_142 < V_28 -> V_175 &&
V_174 -> V_142 + V_174 -> V_176 <= V_28 -> V_175 &&
V_174 -> V_141 < V_28 -> V_177 &&
V_174 -> V_141 + V_174 -> V_178 <= V_28 -> V_177 )
return 0 ;
else
return - V_70 ;
}
static int F_63 ( struct V_81 * V_174 )
{
T_2 V_56 ;
V_56 = ( ( V_174 -> V_93 << 16 ) / V_174 -> V_92 ) >> 16 ;
if ( V_56 > 7 )
return - V_70 ;
V_56 = ( ( V_174 -> V_91 << 16 ) / V_174 -> V_90 ) >> 16 ;
if ( V_56 > 7 )
return - V_70 ;
return 0 ;
}
static int F_64 ( struct V_17 * V_5 ,
struct V_173 * V_174 ,
struct V_59 * V_128 )
{
int V_88 = F_39 ( V_174 -> V_179 ) ;
int V_89 = F_40 ( V_174 -> V_179 ) ;
T_2 V_180 ;
int V_106 ;
T_2 V_56 ;
if ( F_65 ( V_5 ) || F_23 ( V_5 ) ) {
if ( V_174 -> V_181 > V_182 ||
V_174 -> V_183 > V_184 )
return - V_70 ;
} else {
if ( V_174 -> V_181 > V_185 ||
V_174 -> V_183 > V_186 )
return - V_70 ;
}
if ( V_174 -> V_181 < V_187 * 4 ||
V_174 -> V_183 < V_188 * 4 )
return - V_70 ;
switch ( V_174 -> V_179 & V_189 ) {
case V_190 :
return - V_70 ;
case V_144 :
if ( V_89 != 1 )
return - V_70 ;
V_106 = F_37 ( V_174 -> V_179 ) ;
if ( V_106 < 0 )
return V_106 ;
V_174 -> V_160 = 0 ;
V_174 -> V_156 = 0 ;
V_174 -> V_157 = 0 ;
if ( V_174 -> V_148 % V_106 )
return - V_70 ;
break;
case V_114 :
if ( V_89 < 0 || V_88 < 0 )
return - V_70 ;
break;
default:
return - V_70 ;
}
if ( V_174 -> V_183 % V_88 )
return - V_70 ;
if ( F_23 ( V_5 ) || F_65 ( V_5 ) )
V_180 = 255 ;
else
V_180 = 63 ;
if ( V_174 -> V_153 & V_180 || V_174 -> V_160 & V_180 )
return - V_70 ;
if ( F_55 ( V_5 ) && V_174 -> V_153 < 512 )
return - V_70 ;
V_56 = ( V_174 -> V_179 & V_189 ) == V_114 ?
4096 : 8192 ;
if ( V_174 -> V_153 > V_56 || V_174 -> V_160 > 2 * 1024 )
return - V_70 ;
switch ( V_174 -> V_179 & V_189 ) {
case V_190 :
case V_144 :
if ( F_38 ( V_174 -> V_179 , V_174 -> V_183 ) > V_174 -> V_153 )
return - V_70 ;
V_56 = V_174 -> V_153 * V_174 -> V_181 ;
if ( V_174 -> V_148 + V_56 > V_128 -> V_34 . V_191 )
return - V_70 ;
break;
case V_114 :
if ( V_174 -> V_183 > V_174 -> V_153 )
return - V_70 ;
if ( V_174 -> V_183 / V_88 > V_174 -> V_160 )
return - V_70 ;
V_56 = V_174 -> V_153 * V_174 -> V_181 ;
if ( V_174 -> V_148 + V_56 > V_128 -> V_34 . V_191 )
return - V_70 ;
V_56 = V_174 -> V_160 * ( V_174 -> V_181 / V_89 ) ;
if ( V_174 -> V_156 + V_56 > V_128 -> V_34 . V_191 ||
V_174 -> V_157 + V_56 > V_128 -> V_34 . V_191 )
return - V_70 ;
break;
}
return 0 ;
}
static int F_66 ( struct V_17 * V_5 )
{
struct V_42 * V_4 = V_5 -> V_6 ;
T_2 V_164 ;
if ( F_23 ( V_5 ) )
return - 1 ;
V_164 = F_16 ( V_165 ) ;
if ( ( V_164 & V_192 ) == 0 )
return - 1 ;
if ( F_55 ( V_5 ) )
return ( V_164 >> 29 ) & 0x3 ;
return 1 ;
}
int F_67 ( struct V_17 * V_5 , void * V_193 ,
struct V_194 * V_195 )
{
struct V_173 * V_196 = V_193 ;
T_1 * V_4 = V_5 -> V_6 ;
struct V_2 * V_3 ;
struct V_197 * V_198 ;
struct V_22 * V_23 ;
struct V_59 * V_128 ;
struct V_81 * V_82 ;
int V_18 ;
if ( ! V_4 ) {
F_68 ( L_4 ) ;
return - V_70 ;
}
V_3 = V_4 -> V_3 ;
if ( ! V_3 ) {
F_29 ( L_5 ) ;
return - V_199 ;
}
if ( ! ( V_196 -> V_179 & V_200 ) ) {
F_69 ( & V_5 -> V_131 . V_132 ) ;
F_69 ( & V_5 -> V_130 ) ;
V_18 = F_57 ( V_3 ) ;
F_70 ( & V_5 -> V_130 ) ;
F_70 ( & V_5 -> V_131 . V_132 ) ;
return V_18 ;
}
V_82 = F_71 ( sizeof( struct V_81 ) , V_45 ) ;
if ( ! V_82 )
return - V_46 ;
V_198 = F_72 ( V_5 , V_196 -> V_201 ,
V_202 ) ;
if ( ! V_198 ) {
V_18 = - V_203 ;
goto V_204;
}
V_23 = F_15 ( F_73 ( V_198 ) ) ;
V_128 = F_74 ( F_75 ( V_5 , V_195 ,
V_196 -> V_205 ) ) ;
if ( & V_128 -> V_34 == NULL ) {
V_18 = - V_203 ;
goto V_204;
}
F_69 ( & V_5 -> V_131 . V_132 ) ;
F_69 ( & V_5 -> V_130 ) ;
if ( V_128 -> V_206 ) {
F_68 ( L_6 ) ;
V_18 = - V_70 ;
goto V_207;
}
V_18 = F_35 ( V_3 ) ;
if ( V_18 != 0 )
goto V_207;
if ( V_3 -> V_23 != V_23 ) {
struct V_26 * V_28 = & V_23 -> V_34 . V_28 ;
V_18 = F_57 ( V_3 ) ;
if ( V_18 != 0 )
goto V_207;
V_18 = F_58 ( V_3 , V_23 ) ;
if ( V_18 != 0 )
goto V_207;
V_3 -> V_23 = V_23 ;
V_23 -> V_3 = V_3 ;
if ( V_28 -> V_175 > 1024 &&
F_66 ( V_5 ) == V_23 -> V_137 ) {
V_3 -> V_208 = 1 ;
F_61 ( V_3 ) ;
} else
V_3 -> V_208 = 0 ;
}
V_18 = F_62 ( V_3 , V_196 ) ;
if ( V_18 != 0 )
goto V_207;
if ( V_3 -> V_208 ) {
V_82 -> V_141 = ( ( ( ( T_2 ) V_196 -> V_141 ) << 12 ) /
V_3 -> V_172 ) ;
V_82 -> V_92 = ( ( ( ( T_2 ) V_196 -> V_178 ) << 12 ) /
V_3 -> V_172 ) + 1 ;
} else {
V_82 -> V_141 = V_196 -> V_141 ;
V_82 -> V_92 = V_196 -> V_178 ;
}
V_82 -> V_142 = V_196 -> V_142 ;
V_82 -> V_90 = V_196 -> V_176 ;
V_82 -> V_145 = V_196 -> V_183 ;
V_82 -> V_150 = V_196 -> V_181 ;
V_82 -> V_91 = V_196 -> V_209 ;
V_82 -> V_93 = V_196 -> V_210 ;
if ( V_82 -> V_93 > V_82 -> V_150 ||
V_82 -> V_91 > V_82 -> V_145 ) {
V_18 = - V_70 ;
goto V_207;
}
V_18 = F_64 ( V_5 , V_196 , V_128 ) ;
if ( V_18 != 0 )
goto V_207;
V_82 -> V_66 = V_196 -> V_179 & ~ V_211 ;
V_82 -> V_153 = V_196 -> V_153 ;
V_82 -> V_160 = V_196 -> V_160 ;
V_82 -> V_148 = V_196 -> V_148 ;
V_82 -> V_156 = V_196 -> V_156 ;
V_82 -> V_157 = V_196 -> V_157 ;
V_18 = F_63 ( V_82 ) ;
if ( V_18 != 0 )
goto V_207;
V_18 = F_51 ( V_3 , V_128 , V_82 ) ;
if ( V_18 != 0 )
goto V_207;
F_70 ( & V_5 -> V_130 ) ;
F_70 ( & V_5 -> V_131 . V_132 ) ;
F_11 ( V_82 ) ;
return 0 ;
V_207:
F_70 ( & V_5 -> V_130 ) ;
F_70 ( & V_5 -> V_131 . V_132 ) ;
F_76 ( & V_128 -> V_34 ) ;
V_204:
F_11 ( V_82 ) ;
return V_18 ;
}
static void F_77 ( struct V_2 * V_3 ,
struct V_1 * V_7 )
{
V_7 -> V_212 = ( V_3 -> V_213 << 18 ) | ( V_3 -> V_214 & 0xff ) ;
V_7 -> V_215 = V_3 -> V_216 ;
}
static bool F_78 ( T_2 V_217 , T_2 V_218 )
{
int V_219 ;
if ( V_217 & 0xff000000 || V_218 & 0xff000000 )
return false ;
for ( V_219 = 0 ; V_219 < 3 ; V_219 ++ ) {
if ( ( ( V_217 >> V_219 * 8 ) & 0xff ) >= ( ( V_218 >> V_219 * 8 ) & 0xff ) )
return false ;
}
return true ;
}
static bool F_79 ( T_2 V_220 )
{
int V_219 ;
for ( V_219 = 0 ; V_219 < 3 ; V_219 ++ ) {
if ( ( ( V_220 >> V_219 * 8 ) & 0xff ) == 0x80 )
return false ;
}
return true ;
}
static int F_80 ( struct V_221 * V_222 )
{
if ( ! F_78 ( 0 , V_222 -> V_223 ) ||
! F_78 ( V_222 -> V_223 , V_222 -> V_217 ) ||
! F_78 ( V_222 -> V_217 , V_222 -> V_218 ) ||
! F_78 ( V_222 -> V_218 , V_222 -> V_224 ) ||
! F_78 ( V_222 -> V_224 , V_222 -> V_225 ) ||
! F_78 ( V_222 -> V_225 , V_222 -> V_220 ) ||
! F_78 ( V_222 -> V_220 , 0x00ffffff ) )
return - V_70 ;
if ( ! F_79 ( V_222 -> V_220 ) )
return - V_70 ;
return 0 ;
}
int F_81 ( struct V_17 * V_5 , void * V_193 ,
struct V_194 * V_195 )
{
struct V_221 * V_222 = V_193 ;
T_1 * V_4 = V_5 -> V_6 ;
struct V_2 * V_3 ;
struct V_1 * V_7 ;
int V_18 ;
if ( ! V_4 ) {
F_68 ( L_4 ) ;
return - V_70 ;
}
V_3 = V_4 -> V_3 ;
if ( ! V_3 ) {
F_29 ( L_5 ) ;
return - V_199 ;
}
F_69 ( & V_5 -> V_131 . V_132 ) ;
F_69 ( & V_5 -> V_130 ) ;
V_18 = - V_70 ;
if ( ! ( V_222 -> V_179 & V_226 ) ) {
V_222 -> V_100 = V_3 -> V_100 ;
V_222 -> V_214 = V_3 -> V_214 ;
V_222 -> V_213 = V_3 -> V_213 ;
V_222 -> V_216 = V_3 -> V_216 ;
if ( ! F_42 ( V_5 ) ) {
V_222 -> V_223 = F_16 ( V_227 ) ;
V_222 -> V_217 = F_16 ( V_228 ) ;
V_222 -> V_218 = F_16 ( V_229 ) ;
V_222 -> V_224 = F_16 ( V_230 ) ;
V_222 -> V_225 = F_16 ( V_231 ) ;
V_222 -> V_220 = F_16 ( V_232 ) ;
}
} else {
if ( V_222 -> V_214 < - 128 || V_222 -> V_214 > 127 )
goto V_207;
if ( V_222 -> V_213 > 255 )
goto V_207;
if ( V_222 -> V_216 > 1023 )
goto V_207;
V_3 -> V_100 = V_222 -> V_100 ;
V_3 -> V_214 = V_222 -> V_214 ;
V_3 -> V_213 = V_222 -> V_213 ;
V_3 -> V_216 = V_222 -> V_216 ;
V_7 = F_1 ( V_3 ) ;
if ( ! V_7 ) {
V_18 = - V_46 ;
goto V_207;
}
F_77 ( V_3 , V_7 ) ;
F_4 ( V_3 , V_7 ) ;
if ( V_222 -> V_179 & V_233 ) {
if ( F_42 ( V_5 ) )
goto V_207;
if ( V_3 -> V_44 ) {
V_18 = - V_234 ;
goto V_207;
}
V_18 = F_80 ( V_222 ) ;
if ( V_18 )
goto V_207;
F_82 ( V_227 , V_222 -> V_223 ) ;
F_82 ( V_228 , V_222 -> V_217 ) ;
F_82 ( V_229 , V_222 -> V_218 ) ;
F_82 ( V_230 , V_222 -> V_224 ) ;
F_82 ( V_231 , V_222 -> V_225 ) ;
F_82 ( V_232 , V_222 -> V_220 ) ;
}
}
V_18 = 0 ;
V_207:
F_70 ( & V_5 -> V_130 ) ;
F_70 ( & V_5 -> V_131 . V_132 ) ;
return V_18 ;
}
void F_83 ( struct V_17 * V_5 )
{
T_1 * V_4 = V_5 -> V_6 ;
struct V_2 * V_3 ;
struct V_59 * V_8 ;
struct V_1 * V_7 ;
int V_18 ;
if ( ! F_84 ( V_5 ) )
return;
V_3 = F_24 ( sizeof( struct V_2 ) , V_45 ) ;
if ( ! V_3 )
return;
F_69 ( & V_5 -> V_130 ) ;
if ( F_85 ( V_4 -> V_3 ) )
goto V_204;
V_3 -> V_5 = V_5 ;
V_8 = F_86 ( V_5 , V_235 ) ;
if ( ! V_8 )
goto V_204;
V_3 -> V_8 = V_8 ;
if ( F_2 ( V_5 ) ) {
V_18 = F_87 ( V_5 , V_8 ,
V_236 ,
V_235 ) ;
if ( V_18 ) {
F_68 ( L_7 ) ;
goto V_237;
}
V_3 -> V_50 = V_8 -> V_9 -> V_10 -> V_238 ;
} else {
V_18 = F_88 ( V_8 , V_235 , true ) ;
if ( V_18 ) {
F_68 ( L_8 ) ;
goto V_237;
}
V_3 -> V_50 = V_8 -> V_14 ;
V_18 = F_89 ( V_8 , true ) ;
if ( V_18 ) {
F_68 ( L_9 ) ;
goto V_239;
}
}
V_3 -> V_100 = 0x0101fe ;
V_3 -> V_214 = - 19 ;
V_3 -> V_213 = 75 ;
V_3 -> V_216 = 146 ;
V_7 = F_1 ( V_3 ) ;
if ( ! V_7 )
goto V_239;
memset ( V_7 , 0 , sizeof( struct V_1 ) ) ;
F_43 ( V_7 ) ;
F_77 ( V_3 , V_7 ) ;
F_4 ( V_3 , V_7 ) ;
V_4 -> V_3 = V_3 ;
F_70 ( & V_5 -> V_130 ) ;
F_90 ( L_10 ) ;
return;
V_239:
if ( ! F_2 ( V_5 ) )
F_31 ( V_8 ) ;
V_237:
F_32 ( & V_8 -> V_34 ) ;
V_204:
F_70 ( & V_5 -> V_130 ) ;
F_11 ( V_3 ) ;
return;
}
void F_91 ( struct V_17 * V_5 )
{
T_1 * V_4 = V_5 -> V_6 ;
if ( ! V_4 -> V_3 )
return;
F_8 ( V_4 -> V_3 -> V_44 ) ;
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
struct V_240 *
F_96 ( struct V_17 * V_5 )
{
T_1 * V_4 = V_5 -> V_6 ;
struct V_2 * V_3 = V_4 -> V_3 ;
struct V_240 * error ;
struct V_1 T_3 * V_7 ;
if ( ! V_3 || ! V_3 -> V_44 )
return NULL ;
error = F_71 ( sizeof( * error ) , V_241 ) ;
if ( error == NULL )
return NULL ;
error -> V_242 = F_16 ( V_57 ) ;
error -> V_243 = F_16 ( V_64 ) ;
if ( F_2 ( V_3 -> V_5 ) )
error -> V_34 = ( long ) V_3 -> V_8 -> V_9 -> V_10 -> V_11 ;
else
error -> V_34 = ( long ) V_3 -> V_8 -> V_14 ;
V_7 = F_92 ( V_3 ) ;
if ( ! V_7 )
goto V_244;
F_97 ( & error -> V_7 , V_7 , sizeof( struct V_1 ) ) ;
F_94 ( V_3 , V_7 ) ;
return error ;
V_244:
F_11 ( error ) ;
return NULL ;
}
void
F_98 ( struct V_245 * V_246 , struct V_240 * error )
{
F_99 ( V_246 , L_11 ,
error -> V_242 , error -> V_243 ) ;
F_99 ( V_246 , L_12 ,
error -> V_34 ) ;
#define F_100 ( V_37 ) seq_printf(m, " " #x ": 0x%08x\n", error->regs.x)
F_100 ( V_151 ) ;
F_100 ( V_247 ) ;
F_100 ( V_158 ) ;
F_100 ( V_159 ) ;
F_100 ( V_248 ) ;
F_100 ( V_249 ) ;
F_100 ( V_152 ) ;
F_100 ( V_250 ) ;
F_100 ( V_251 ) ;
F_100 ( V_252 ) ;
F_100 ( V_253 ) ;
F_100 ( V_140 ) ;
F_100 ( V_143 ) ;
F_100 ( V_146 ) ;
F_100 ( V_147 ) ;
F_100 ( V_149 ) ;
F_100 ( V_96 ) ;
F_100 ( V_97 ) ;
F_100 ( V_212 ) ;
F_100 ( V_215 ) ;
F_100 ( V_102 ) ;
F_100 ( V_103 ) ;
F_100 ( V_254 ) ;
F_100 ( V_255 ) ;
F_100 ( V_256 ) ;
F_100 ( V_134 ) ;
F_100 ( V_161 ) ;
F_100 ( V_257 ) ;
F_100 ( V_258 ) ;
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
F_100 ( V_98 ) ;
#undef F_100
}
