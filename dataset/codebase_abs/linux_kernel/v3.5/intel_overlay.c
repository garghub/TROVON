static struct V_1 T_1 *
F_1 ( struct V_2 * V_3 )
{
T_2 * V_4 = V_3 -> V_5 -> V_6 ;
struct V_1 T_1 * V_7 ;
if ( F_2 ( V_3 -> V_5 ) )
V_7 = (struct V_1 T_1 * ) V_3 -> V_8 -> V_9 -> V_10 -> V_11 ;
else
V_7 = F_3 ( V_4 -> V_12 . V_13 ,
V_3 -> V_8 -> V_14 ) ;
return V_7 ;
}
static void F_4 ( struct V_2 * V_3 ,
struct V_1 T_1 * V_7 )
{
if ( ! F_2 ( V_3 -> V_5 ) )
F_5 ( V_7 ) ;
}
static int F_6 ( struct V_2 * V_3 ,
struct V_15 * V_16 ,
void (* F_7)( struct V_2 * ) )
{
struct V_17 * V_5 = V_3 -> V_5 ;
T_2 * V_4 = V_5 -> V_6 ;
struct V_18 * V_19 = & V_4 -> V_19 [ V_20 ] ;
int V_21 ;
F_8 ( V_3 -> V_22 ) ;
V_21 = F_9 ( V_19 , NULL , V_16 ) ;
if ( V_21 ) {
F_10 ( V_16 ) ;
return V_21 ;
}
V_3 -> V_22 = V_16 -> V_23 ;
V_3 -> V_24 = F_7 ;
V_21 = F_11 ( V_19 , V_3 -> V_22 ) ;
if ( V_21 )
return V_21 ;
F_12 ( V_5 ) ;
V_3 -> V_22 = 0 ;
return 0 ;
}
static int
F_13 ( struct V_17 * V_5 )
{
T_2 * V_4 = V_5 -> V_6 ;
struct V_25 * V_26 ;
struct V_27 * V_28 ;
struct V_29 V_30 = {
F_14 ( L_1 , DRM_MODE_TYPE_DRIVER, 25175 , 640 , 656 ,
752 , 800 , 0 , 480 , 489 , 492 , 525 , 0 ,
DRM_MODE_FLAG_NHSYNC | DRM_MODE_FLAG_NVSYNC)
} , * V_31 ;
V_26 = F_15 ( V_4 -> V_32 [ 0 ] ) ;
if ( V_26 -> V_33 == V_34 )
return 0 ;
if ( F_16 ( V_35 ) & V_36 )
return 0 ;
V_28 = V_26 -> V_37 . V_38 ;
if ( V_28 -> V_39 == NULL )
return 0 ;
F_17 ( L_2 ) ;
V_31 = F_18 ( V_5 , & V_30 ) ;
if ( ! F_19 ( & V_26 -> V_37 , V_31 ,
V_26 -> V_37 . V_40 , V_26 -> V_37 . V_41 ,
V_26 -> V_37 . V_42 ) )
return 0 ;
V_28 -> V_39 ( & V_26 -> V_37 , V_34 ) ;
return 1 ;
}
static void
F_20 ( struct V_17 * V_5 )
{
T_2 * V_4 = V_5 -> V_6 ;
struct V_43 * V_26 = V_4 -> V_32 [ 0 ] ;
struct V_27 * V_28 = V_26 -> V_38 ;
V_28 -> V_39 ( V_26 , V_44 ) ;
}
static int F_21 ( struct V_2 * V_3 )
{
struct V_17 * V_5 = V_3 -> V_5 ;
struct V_45 * V_4 = V_5 -> V_6 ;
struct V_18 * V_19 = & V_4 -> V_19 [ V_20 ] ;
struct V_15 * V_16 ;
int V_46 = 0 ;
int V_21 ;
F_8 ( V_3 -> V_47 ) ;
V_3 -> V_47 = 1 ;
if ( F_22 ( V_5 ) ) {
V_46 = F_13 ( V_5 ) ;
if ( V_46 < 0 )
return V_46 ;
}
V_16 = F_23 ( sizeof( * V_16 ) , V_48 ) ;
if ( V_16 == NULL ) {
V_21 = - V_49 ;
goto V_50;
}
V_21 = F_24 ( V_19 , 4 ) ;
if ( V_21 ) {
F_10 ( V_16 ) ;
goto V_50;
}
F_25 ( V_19 , V_51 | V_52 ) ;
F_25 ( V_19 , V_3 -> V_53 | V_54 ) ;
F_25 ( V_19 , V_55 | V_56 ) ;
F_25 ( V_19 , V_57 ) ;
F_26 ( V_19 ) ;
V_21 = F_6 ( V_3 , V_16 , NULL ) ;
V_50:
if ( V_46 )
F_20 ( V_5 ) ;
return V_21 ;
}
static int F_27 ( struct V_2 * V_3 ,
bool V_58 )
{
struct V_17 * V_5 = V_3 -> V_5 ;
T_2 * V_4 = V_5 -> V_6 ;
struct V_18 * V_19 = & V_4 -> V_19 [ V_20 ] ;
struct V_15 * V_16 ;
T_3 V_53 = V_3 -> V_53 ;
T_3 V_59 ;
int V_21 ;
F_8 ( ! V_3 -> V_47 ) ;
V_16 = F_23 ( sizeof( * V_16 ) , V_48 ) ;
if ( V_16 == NULL )
return - V_49 ;
if ( V_58 )
V_53 |= V_54 ;
V_59 = F_16 ( V_60 ) ;
if ( V_59 & ( 1 << 17 ) )
F_28 ( L_3 , V_59 ) ;
V_21 = F_24 ( V_19 , 2 ) ;
if ( V_21 ) {
F_10 ( V_16 ) ;
return V_21 ;
}
F_25 ( V_19 , V_51 | V_61 ) ;
F_25 ( V_19 , V_53 ) ;
F_26 ( V_19 ) ;
V_21 = F_9 ( V_19 , NULL , V_16 ) ;
if ( V_21 ) {
F_10 ( V_16 ) ;
return V_21 ;
}
V_3 -> V_22 = V_16 -> V_23 ;
return 0 ;
}
static void F_29 ( struct V_2 * V_3 )
{
struct V_62 * V_63 = V_3 -> V_64 ;
F_30 ( V_63 ) ;
F_31 ( & V_63 -> V_37 ) ;
V_3 -> V_64 = NULL ;
}
static void F_32 ( struct V_2 * V_3 )
{
struct V_62 * V_63 = V_3 -> V_65 ;
F_8 ( ! V_3 -> V_65 ) ;
F_30 ( V_63 ) ;
F_31 ( & V_63 -> V_37 ) ;
V_3 -> V_65 = NULL ;
V_3 -> V_26 -> V_3 = NULL ;
V_3 -> V_26 = NULL ;
V_3 -> V_47 = 0 ;
}
static int F_33 ( struct V_2 * V_3 )
{
struct V_17 * V_5 = V_3 -> V_5 ;
struct V_45 * V_4 = V_5 -> V_6 ;
struct V_18 * V_19 = & V_4 -> V_19 [ V_20 ] ;
T_3 V_53 = V_3 -> V_53 ;
struct V_15 * V_16 ;
int V_21 ;
F_8 ( ! V_3 -> V_47 ) ;
V_16 = F_23 ( sizeof( * V_16 ) , V_48 ) ;
if ( V_16 == NULL )
return - V_49 ;
V_53 |= V_54 ;
V_21 = F_24 ( V_19 , 6 ) ;
if ( V_21 ) {
F_10 ( V_16 ) ;
return V_21 ;
}
F_25 ( V_19 , V_51 | V_61 ) ;
F_25 ( V_19 , V_53 ) ;
F_25 ( V_19 , V_55 | V_56 ) ;
F_25 ( V_19 , V_51 | V_66 ) ;
F_25 ( V_19 , V_53 ) ;
F_25 ( V_19 , V_55 | V_56 ) ;
F_26 ( V_19 ) ;
return F_6 ( V_3 , V_16 ,
F_32 ) ;
}
static int F_34 ( struct V_2 * V_3 )
{
struct V_17 * V_5 = V_3 -> V_5 ;
T_2 * V_4 = V_5 -> V_6 ;
struct V_18 * V_19 = & V_4 -> V_19 [ V_20 ] ;
int V_21 ;
if ( V_3 -> V_22 == 0 )
return 0 ;
V_21 = F_11 ( V_19 , V_3 -> V_22 ) ;
if ( V_21 )
return V_21 ;
F_12 ( V_5 ) ;
if ( V_3 -> V_24 )
V_3 -> V_24 ( V_3 ) ;
V_3 -> V_22 = 0 ;
return 0 ;
}
static int F_35 ( struct V_2 * V_3 )
{
struct V_17 * V_5 = V_3 -> V_5 ;
T_2 * V_4 = V_5 -> V_6 ;
struct V_18 * V_19 = & V_4 -> V_19 [ V_20 ] ;
int V_21 ;
if ( ! V_3 -> V_64 )
return 0 ;
if ( F_16 ( V_67 ) & V_68 ) {
struct V_15 * V_16 ;
V_16 = F_23 ( sizeof( * V_16 ) , V_48 ) ;
if ( V_16 == NULL )
return - V_49 ;
V_21 = F_24 ( V_19 , 2 ) ;
if ( V_21 ) {
F_10 ( V_16 ) ;
return V_21 ;
}
F_25 ( V_19 , V_55 | V_56 ) ;
F_25 ( V_19 , V_57 ) ;
F_26 ( V_19 ) ;
V_21 = F_6 ( V_3 , V_16 ,
F_29 ) ;
if ( V_21 )
return V_21 ;
}
F_29 ( V_3 ) ;
return 0 ;
}
static int F_36 ( T_3 V_69 )
{
switch ( V_69 & V_70 ) {
case V_71 :
return 4 ;
case V_72 :
default:
return - V_73 ;
}
}
static int F_37 ( T_3 V_69 , short V_74 )
{
switch ( V_69 & V_70 ) {
case V_71 :
return V_74 << 1 ;
default:
return - V_73 ;
}
}
static int F_38 ( T_3 V_69 )
{
switch ( V_69 & V_70 ) {
case V_71 :
case V_75 :
return 2 ;
case V_72 :
case V_76 :
return 4 ;
default:
return - V_73 ;
}
}
static int F_39 ( T_3 V_69 )
{
switch ( V_69 & V_70 ) {
case V_75 :
case V_76 :
return 2 ;
case V_71 :
case V_72 :
return 1 ;
default:
return - V_73 ;
}
}
static T_3 F_40 ( struct V_17 * V_5 , T_3 V_77 , T_3 V_74 )
{
T_3 V_78 , V_79 , V_21 ;
if ( F_41 ( V_5 ) ) {
V_78 = 0x1f ;
V_79 = 5 ;
} else {
V_78 = 0x3f ;
V_79 = 6 ;
}
V_21 = ( ( V_77 + V_74 + V_78 ) >> V_79 ) - ( V_77 >> V_79 ) ;
if ( ! F_41 ( V_5 ) )
V_21 <<= 1 ;
V_21 -= 1 ;
return V_21 << 2 ;
}
static void F_42 ( struct V_1 T_1 * V_7 )
{
F_43 ( V_7 -> V_80 , V_81 , sizeof( V_81 ) ) ;
F_43 ( V_7 -> V_82 , V_83 ,
sizeof( V_83 ) ) ;
}
static bool F_44 ( struct V_2 * V_3 ,
struct V_1 T_1 * V_7 ,
struct V_84 * V_85 )
{
T_3 V_86 , V_87 , V_88 , V_89 ;
#define F_45 12
#define F_46 0xfff
bool V_90 = false ;
int V_91 = F_38 ( V_85 -> V_69 ) ;
int V_92 = F_39 ( V_85 -> V_69 ) ;
if ( V_85 -> V_93 > 1 )
V_86 = ( ( V_85 -> V_94 - 1 ) << F_45 )
/ ( V_85 -> V_93 ) ;
else
V_86 = 1 << F_45 ;
if ( V_85 -> V_95 > 1 )
V_87 = ( ( V_85 -> V_96 - 1 ) << F_45 )
/ ( V_85 -> V_95 ) ;
else
V_87 = 1 << F_45 ;
V_88 = V_86 / V_91 ;
V_89 = V_87 / V_92 ;
V_86 = V_88 * V_91 ;
V_87 = V_89 * V_92 ;
if ( V_86 != V_3 -> V_97 || V_87 != V_3 -> V_98 )
V_90 = true ;
V_3 -> V_97 = V_86 ;
V_3 -> V_98 = V_87 ;
F_47 ( ( ( V_87 & F_46 ) << 20 ) |
( ( V_86 >> F_45 ) << 16 ) |
( ( V_86 & F_46 ) << 3 ) ,
& V_7 -> V_99 ) ;
F_47 ( ( ( V_89 & F_46 ) << 20 ) |
( ( V_88 >> F_45 ) << 16 ) |
( ( V_88 & F_46 ) << 3 ) ,
& V_7 -> V_100 ) ;
F_47 ( ( ( ( V_87 >> F_45 ) << 16 ) |
( ( V_89 >> F_45 ) << 0 ) ) ,
& V_7 -> V_101 ) ;
if ( V_90 )
F_42 ( V_7 ) ;
return V_90 ;
}
static void F_48 ( struct V_2 * V_3 ,
struct V_1 T_1 * V_7 )
{
T_3 V_102 = V_3 -> V_103 ;
switch ( V_3 -> V_26 -> V_37 . V_42 -> V_104 ) {
case 8 :
F_47 ( 0 , & V_7 -> V_105 ) ;
F_47 ( V_106 | V_107 , & V_7 -> V_108 ) ;
break;
case 16 :
if ( V_3 -> V_26 -> V_37 . V_42 -> V_109 == 15 ) {
F_47 ( F_49 ( V_102 ) , & V_7 -> V_105 ) ;
F_47 ( V_110 | V_107 ,
& V_7 -> V_108 ) ;
} else {
F_47 ( F_50 ( V_102 ) , & V_7 -> V_105 ) ;
F_47 ( V_111 | V_107 ,
& V_7 -> V_108 ) ;
}
break;
case 24 :
case 32 :
F_47 ( V_102 , & V_7 -> V_105 ) ;
F_47 ( V_112 | V_107 , & V_7 -> V_108 ) ;
break;
}
}
static T_3 F_51 ( struct V_84 * V_85 )
{
T_3 V_113 = V_114 | V_115 | V_116 ;
if ( V_85 -> V_69 & V_117 ) {
switch ( V_85 -> V_69 & V_70 ) {
case V_71 :
V_113 |= V_118 ;
break;
case V_75 :
V_113 |= V_119 ;
break;
case V_72 :
case V_76 :
V_113 |= V_120 ;
break;
}
} else {
switch ( V_85 -> V_69 & V_70 ) {
case V_71 :
V_113 |= V_121 ;
break;
case V_72 :
V_113 |= V_122 ;
break;
}
switch ( V_85 -> V_69 & V_123 ) {
case V_124 :
break;
case V_125 :
V_113 |= V_126 ;
break;
case V_127 :
V_113 |= V_128 ;
break;
case V_129 :
V_113 |= V_130 ;
break;
}
}
return V_113 ;
}
static int F_52 ( struct V_2 * V_3 ,
struct V_62 * V_131 ,
struct V_84 * V_85 )
{
int V_21 , V_132 ;
struct V_1 T_1 * V_7 ;
bool V_90 = false ;
struct V_17 * V_5 = V_3 -> V_5 ;
T_3 V_133 , V_134 , V_135 , V_136 ;
F_8 ( ! F_53 ( & V_5 -> V_137 ) ) ;
F_8 ( ! F_53 ( & V_5 -> V_138 . V_139 ) ) ;
F_8 ( ! V_3 ) ;
V_21 = F_35 ( V_3 ) ;
if ( V_21 != 0 )
return V_21 ;
V_21 = F_54 ( V_131 , 0 , NULL ) ;
if ( V_21 != 0 )
return V_21 ;
V_21 = F_55 ( V_131 ) ;
if ( V_21 )
goto V_140;
if ( ! V_3 -> V_47 ) {
T_3 V_141 ;
V_7 = F_1 ( V_3 ) ;
if ( ! V_7 ) {
V_21 = - V_49 ;
goto V_140;
}
V_141 = V_142 ;
if ( F_56 ( V_3 -> V_5 ) )
V_141 |= V_143 ;
V_141 |= V_3 -> V_26 -> V_144 == 0 ?
V_145 : V_146 ;
F_47 ( V_141 , & V_7 -> V_147 ) ;
F_4 ( V_3 , V_7 ) ;
V_21 = F_21 ( V_3 ) ;
if ( V_21 != 0 )
goto V_140;
}
V_7 = F_1 ( V_3 ) ;
if ( ! V_7 ) {
V_21 = - V_49 ;
goto V_140;
}
F_47 ( ( V_85 -> V_148 << 16 ) | V_85 -> V_149 , & V_7 -> V_150 ) ;
F_47 ( ( V_85 -> V_95 << 16 ) | V_85 -> V_93 , & V_7 -> V_151 ) ;
if ( V_85 -> V_69 & V_152 )
V_132 = F_37 ( V_85 -> V_69 , V_85 -> V_153 ) ;
else
V_132 = V_85 -> V_153 ;
V_133 = V_85 -> V_153 ;
V_134 = F_40 ( V_3 -> V_5 , V_85 -> V_154 , V_132 ) ;
V_135 = V_85 -> V_155 ;
F_47 ( V_131 -> V_14 + V_85 -> V_154 , & V_7 -> V_156 ) ;
V_136 = V_85 -> V_157 ;
if ( V_85 -> V_69 & V_117 ) {
int V_91 = F_38 ( V_85 -> V_69 ) ;
int V_92 = F_39 ( V_85 -> V_69 ) ;
T_3 V_158 , V_159 ;
V_133 |= ( V_85 -> V_153 / V_91 ) << 16 ;
V_158 = F_40 ( V_3 -> V_5 , V_85 -> V_160 ,
V_85 -> V_153 / V_91 ) ;
V_159 = F_40 ( V_3 -> V_5 , V_85 -> V_161 ,
V_85 -> V_153 / V_91 ) ;
V_134 |= F_57 ( T_3 , V_158 , V_159 ) << 16 ;
V_135 |= ( V_85 -> V_155 / V_92 ) << 16 ;
F_47 ( V_131 -> V_14 + V_85 -> V_160 , & V_7 -> V_162 ) ;
F_47 ( V_131 -> V_14 + V_85 -> V_161 , & V_7 -> V_163 ) ;
V_136 |= V_85 -> V_164 << 16 ;
}
F_47 ( V_133 , & V_7 -> V_165 ) ;
F_47 ( V_134 , & V_7 -> V_166 ) ;
F_47 ( V_135 , & V_7 -> V_167 ) ;
F_47 ( V_136 , & V_7 -> V_168 ) ;
V_90 = F_44 ( V_3 , V_7 , V_85 ) ;
F_48 ( V_3 , V_7 ) ;
F_47 ( F_51 ( V_85 ) , & V_7 -> V_169 ) ;
F_4 ( V_3 , V_7 ) ;
V_21 = F_27 ( V_3 , V_90 ) ;
if ( V_21 )
goto V_140;
V_3 -> V_64 = V_3 -> V_65 ;
V_3 -> V_65 = V_131 ;
return 0 ;
V_140:
F_30 ( V_131 ) ;
return V_21 ;
}
int F_58 ( struct V_2 * V_3 )
{
struct V_1 T_1 * V_7 ;
struct V_17 * V_5 = V_3 -> V_5 ;
int V_21 ;
F_8 ( ! F_53 ( & V_5 -> V_137 ) ) ;
F_8 ( ! F_53 ( & V_5 -> V_138 . V_139 ) ) ;
V_21 = F_34 ( V_3 ) ;
if ( V_21 != 0 )
return V_21 ;
if ( ! V_3 -> V_47 )
return 0 ;
V_21 = F_35 ( V_3 ) ;
if ( V_21 != 0 )
return V_21 ;
V_7 = F_1 ( V_3 ) ;
F_47 ( 0 , & V_7 -> V_169 ) ;
F_4 ( V_3 , V_7 ) ;
V_21 = F_33 ( V_3 ) ;
if ( V_21 != 0 )
return V_21 ;
F_32 ( V_3 ) ;
return 0 ;
}
static int F_59 ( struct V_2 * V_3 ,
struct V_25 * V_26 )
{
T_2 * V_4 = V_3 -> V_5 -> V_6 ;
if ( ! V_26 -> V_47 )
return - V_73 ;
if ( F_60 ( V_3 -> V_5 ) -> V_170 < 4 &&
( F_16 ( F_61 ( V_26 -> V_144 ) ) & ( V_171 | V_36 ) ) != V_36 )
return - V_73 ;
return 0 ;
}
static void F_62 ( struct V_2 * V_3 )
{
struct V_17 * V_5 = V_3 -> V_5 ;
T_2 * V_4 = V_5 -> V_6 ;
T_3 V_172 = F_16 ( V_173 ) ;
T_3 V_174 ;
if ( F_60 ( V_5 ) -> V_170 >= 4 ) {
V_174 = F_16 ( V_175 ) >> V_176 ;
} else {
if ( V_172 & V_177 )
V_174 = F_16 ( V_178 ) ;
else
V_174 = F_16 ( V_175 ) ;
V_174 >>= V_179 ;
}
V_3 -> V_180 = V_174 ;
}
static int F_63 ( struct V_2 * V_3 ,
struct V_181 * V_182 )
{
struct V_29 * V_31 = & V_3 -> V_26 -> V_37 . V_31 ;
if ( V_182 -> V_149 < V_31 -> V_183 &&
V_182 -> V_149 + V_182 -> V_184 <= V_31 -> V_183 &&
V_182 -> V_148 < V_31 -> V_185 &&
V_182 -> V_148 + V_182 -> V_186 <= V_31 -> V_185 )
return 0 ;
else
return - V_73 ;
}
static int F_64 ( struct V_84 * V_182 )
{
T_3 V_59 ;
V_59 = ( ( V_182 -> V_96 << 16 ) / V_182 -> V_95 ) >> 16 ;
if ( V_59 > 7 )
return - V_73 ;
V_59 = ( ( V_182 -> V_94 << 16 ) / V_182 -> V_93 ) >> 16 ;
if ( V_59 > 7 )
return - V_73 ;
return 0 ;
}
static int F_65 ( struct V_17 * V_5 ,
struct V_181 * V_182 ,
struct V_62 * V_131 )
{
int V_91 = F_38 ( V_182 -> V_187 ) ;
int V_92 = F_39 ( V_182 -> V_187 ) ;
T_3 V_188 ;
int V_109 ;
T_3 V_59 ;
if ( F_66 ( V_5 ) || F_22 ( V_5 ) ) {
if ( V_182 -> V_189 > V_190 ||
V_182 -> V_191 > V_192 )
return - V_73 ;
} else {
if ( V_182 -> V_189 > V_193 ||
V_182 -> V_191 > V_194 )
return - V_73 ;
}
if ( V_182 -> V_189 < V_195 * 4 ||
V_182 -> V_191 < V_196 * 4 )
return - V_73 ;
switch ( V_182 -> V_187 & V_197 ) {
case V_198 :
return - V_73 ;
case V_152 :
if ( V_92 != 1 )
return - V_73 ;
V_109 = F_36 ( V_182 -> V_187 ) ;
if ( V_109 < 0 )
return V_109 ;
V_182 -> V_164 = 0 ;
V_182 -> V_160 = 0 ;
V_182 -> V_161 = 0 ;
if ( V_182 -> V_154 % V_109 )
return - V_73 ;
break;
case V_117 :
if ( V_92 < 0 || V_91 < 0 )
return - V_73 ;
break;
default:
return - V_73 ;
}
if ( V_182 -> V_191 % V_91 )
return - V_73 ;
if ( F_22 ( V_5 ) || F_66 ( V_5 ) )
V_188 = 255 ;
else
V_188 = 63 ;
if ( V_182 -> V_157 & V_188 || V_182 -> V_164 & V_188 )
return - V_73 ;
if ( F_56 ( V_5 ) && V_182 -> V_157 < 512 )
return - V_73 ;
V_59 = ( V_182 -> V_187 & V_197 ) == V_117 ?
4096 : 8192 ;
if ( V_182 -> V_157 > V_59 || V_182 -> V_164 > 2 * 1024 )
return - V_73 ;
switch ( V_182 -> V_187 & V_197 ) {
case V_198 :
case V_152 :
if ( F_37 ( V_182 -> V_187 , V_182 -> V_191 ) > V_182 -> V_157 )
return - V_73 ;
V_59 = V_182 -> V_157 * V_182 -> V_189 ;
if ( V_182 -> V_154 + V_59 > V_131 -> V_37 . V_199 )
return - V_73 ;
break;
case V_117 :
if ( V_182 -> V_191 > V_182 -> V_157 )
return - V_73 ;
if ( V_182 -> V_191 / V_91 > V_182 -> V_164 )
return - V_73 ;
V_59 = V_182 -> V_157 * V_182 -> V_189 ;
if ( V_182 -> V_154 + V_59 > V_131 -> V_37 . V_199 )
return - V_73 ;
V_59 = V_182 -> V_164 * ( V_182 -> V_189 / V_92 ) ;
if ( V_182 -> V_160 + V_59 > V_131 -> V_37 . V_199 ||
V_182 -> V_161 + V_59 > V_131 -> V_37 . V_199 )
return - V_73 ;
break;
}
return 0 ;
}
static int F_67 ( struct V_17 * V_5 )
{
struct V_45 * V_4 = V_5 -> V_6 ;
T_3 V_172 ;
if ( F_22 ( V_5 ) )
return - 1 ;
V_172 = F_16 ( V_173 ) ;
if ( ( V_172 & V_200 ) == 0 )
return - 1 ;
if ( F_56 ( V_5 ) )
return ( V_172 >> 29 ) & 0x3 ;
return 1 ;
}
int F_68 ( struct V_17 * V_5 , void * V_201 ,
struct V_202 * V_203 )
{
struct V_181 * V_204 = V_201 ;
T_2 * V_4 = V_5 -> V_6 ;
struct V_2 * V_3 ;
struct V_205 * V_206 ;
struct V_25 * V_26 ;
struct V_62 * V_131 ;
struct V_84 * V_85 ;
int V_21 ;
V_3 = V_4 -> V_3 ;
if ( ! V_3 ) {
F_28 ( L_4 ) ;
return - V_207 ;
}
if ( ! ( V_204 -> V_187 & V_208 ) ) {
F_69 ( & V_5 -> V_138 . V_139 ) ;
F_69 ( & V_5 -> V_137 ) ;
V_21 = F_58 ( V_3 ) ;
F_70 ( & V_5 -> V_137 ) ;
F_70 ( & V_5 -> V_138 . V_139 ) ;
return V_21 ;
}
V_85 = F_71 ( sizeof( struct V_84 ) , V_48 ) ;
if ( ! V_85 )
return - V_49 ;
V_206 = F_72 ( V_5 , V_204 -> V_209 ,
V_210 ) ;
if ( ! V_206 ) {
V_21 = - V_211 ;
goto V_212;
}
V_26 = F_15 ( F_73 ( V_206 ) ) ;
V_131 = F_74 ( F_75 ( V_5 , V_203 ,
V_204 -> V_213 ) ) ;
if ( & V_131 -> V_37 == NULL ) {
V_21 = - V_211 ;
goto V_212;
}
F_69 ( & V_5 -> V_138 . V_139 ) ;
F_69 ( & V_5 -> V_137 ) ;
if ( V_131 -> V_214 ) {
F_76 ( L_5 ) ;
V_21 = - V_73 ;
goto V_215;
}
V_21 = F_34 ( V_3 ) ;
if ( V_21 != 0 )
goto V_215;
if ( V_3 -> V_26 != V_26 ) {
struct V_29 * V_31 = & V_26 -> V_37 . V_31 ;
V_21 = F_58 ( V_3 ) ;
if ( V_21 != 0 )
goto V_215;
V_21 = F_59 ( V_3 , V_26 ) ;
if ( V_21 != 0 )
goto V_215;
V_3 -> V_26 = V_26 ;
V_26 -> V_3 = V_3 ;
if ( V_31 -> V_183 > 1024 &&
F_67 ( V_5 ) == V_26 -> V_144 ) {
V_3 -> V_216 = 1 ;
F_62 ( V_3 ) ;
} else
V_3 -> V_216 = 0 ;
}
V_21 = F_63 ( V_3 , V_204 ) ;
if ( V_21 != 0 )
goto V_215;
if ( V_3 -> V_216 ) {
V_85 -> V_148 = ( ( ( ( T_3 ) V_204 -> V_148 ) << 12 ) /
V_3 -> V_180 ) ;
V_85 -> V_95 = ( ( ( ( T_3 ) V_204 -> V_186 ) << 12 ) /
V_3 -> V_180 ) + 1 ;
} else {
V_85 -> V_148 = V_204 -> V_148 ;
V_85 -> V_95 = V_204 -> V_186 ;
}
V_85 -> V_149 = V_204 -> V_149 ;
V_85 -> V_93 = V_204 -> V_184 ;
V_85 -> V_153 = V_204 -> V_191 ;
V_85 -> V_155 = V_204 -> V_189 ;
V_85 -> V_94 = V_204 -> V_217 ;
V_85 -> V_96 = V_204 -> V_218 ;
if ( V_85 -> V_96 > V_85 -> V_155 ||
V_85 -> V_94 > V_85 -> V_153 ) {
V_21 = - V_73 ;
goto V_215;
}
V_21 = F_65 ( V_5 , V_204 , V_131 ) ;
if ( V_21 != 0 )
goto V_215;
V_85 -> V_69 = V_204 -> V_187 & ~ V_219 ;
V_85 -> V_157 = V_204 -> V_157 ;
V_85 -> V_164 = V_204 -> V_164 ;
V_85 -> V_154 = V_204 -> V_154 ;
V_85 -> V_160 = V_204 -> V_160 ;
V_85 -> V_161 = V_204 -> V_161 ;
V_21 = F_64 ( V_85 ) ;
if ( V_21 != 0 )
goto V_215;
V_21 = F_52 ( V_3 , V_131 , V_85 ) ;
if ( V_21 != 0 )
goto V_215;
F_70 ( & V_5 -> V_137 ) ;
F_70 ( & V_5 -> V_138 . V_139 ) ;
F_10 ( V_85 ) ;
return 0 ;
V_215:
F_70 ( & V_5 -> V_137 ) ;
F_70 ( & V_5 -> V_138 . V_139 ) ;
F_77 ( & V_131 -> V_37 ) ;
V_212:
F_10 ( V_85 ) ;
return V_21 ;
}
static void F_78 ( struct V_2 * V_3 ,
struct V_1 T_1 * V_7 )
{
F_47 ( ( V_3 -> V_220 << 18 ) | ( V_3 -> V_221 & 0xff ) ,
& V_7 -> V_222 ) ;
F_47 ( V_3 -> V_223 , & V_7 -> V_224 ) ;
}
static bool F_79 ( T_3 V_225 , T_3 V_226 )
{
int V_227 ;
if ( V_225 & 0xff000000 || V_226 & 0xff000000 )
return false ;
for ( V_227 = 0 ; V_227 < 3 ; V_227 ++ ) {
if ( ( ( V_225 >> V_227 * 8 ) & 0xff ) >= ( ( V_226 >> V_227 * 8 ) & 0xff ) )
return false ;
}
return true ;
}
static bool F_80 ( T_3 V_228 )
{
int V_227 ;
for ( V_227 = 0 ; V_227 < 3 ; V_227 ++ ) {
if ( ( ( V_228 >> V_227 * 8 ) & 0xff ) == 0x80 )
return false ;
}
return true ;
}
static int F_81 ( struct V_229 * V_230 )
{
if ( ! F_79 ( 0 , V_230 -> V_231 ) ||
! F_79 ( V_230 -> V_231 , V_230 -> V_225 ) ||
! F_79 ( V_230 -> V_225 , V_230 -> V_226 ) ||
! F_79 ( V_230 -> V_226 , V_230 -> V_232 ) ||
! F_79 ( V_230 -> V_232 , V_230 -> V_233 ) ||
! F_79 ( V_230 -> V_233 , V_230 -> V_228 ) ||
! F_79 ( V_230 -> V_228 , 0x00ffffff ) )
return - V_73 ;
if ( ! F_80 ( V_230 -> V_228 ) )
return - V_73 ;
return 0 ;
}
int F_82 ( struct V_17 * V_5 , void * V_201 ,
struct V_202 * V_203 )
{
struct V_229 * V_230 = V_201 ;
T_2 * V_4 = V_5 -> V_6 ;
struct V_2 * V_3 ;
struct V_1 T_1 * V_7 ;
int V_21 ;
V_3 = V_4 -> V_3 ;
if ( ! V_3 ) {
F_28 ( L_4 ) ;
return - V_207 ;
}
F_69 ( & V_5 -> V_138 . V_139 ) ;
F_69 ( & V_5 -> V_137 ) ;
V_21 = - V_73 ;
if ( ! ( V_230 -> V_187 & V_234 ) ) {
V_230 -> V_103 = V_3 -> V_103 ;
V_230 -> V_221 = V_3 -> V_221 ;
V_230 -> V_220 = V_3 -> V_220 ;
V_230 -> V_223 = V_3 -> V_223 ;
if ( ! F_41 ( V_5 ) ) {
V_230 -> V_231 = F_16 ( V_235 ) ;
V_230 -> V_225 = F_16 ( V_236 ) ;
V_230 -> V_226 = F_16 ( V_237 ) ;
V_230 -> V_232 = F_16 ( V_238 ) ;
V_230 -> V_233 = F_16 ( V_239 ) ;
V_230 -> V_228 = F_16 ( V_240 ) ;
}
} else {
if ( V_230 -> V_221 < - 128 || V_230 -> V_221 > 127 )
goto V_215;
if ( V_230 -> V_220 > 255 )
goto V_215;
if ( V_230 -> V_223 > 1023 )
goto V_215;
V_3 -> V_103 = V_230 -> V_103 ;
V_3 -> V_221 = V_230 -> V_221 ;
V_3 -> V_220 = V_230 -> V_220 ;
V_3 -> V_223 = V_230 -> V_223 ;
V_7 = F_1 ( V_3 ) ;
if ( ! V_7 ) {
V_21 = - V_49 ;
goto V_215;
}
F_78 ( V_3 , V_7 ) ;
F_4 ( V_3 , V_7 ) ;
if ( V_230 -> V_187 & V_241 ) {
if ( F_41 ( V_5 ) )
goto V_215;
if ( V_3 -> V_47 ) {
V_21 = - V_242 ;
goto V_215;
}
V_21 = F_81 ( V_230 ) ;
if ( V_21 )
goto V_215;
F_83 ( V_235 , V_230 -> V_231 ) ;
F_83 ( V_236 , V_230 -> V_225 ) ;
F_83 ( V_237 , V_230 -> V_226 ) ;
F_83 ( V_238 , V_230 -> V_232 ) ;
F_83 ( V_239 , V_230 -> V_233 ) ;
F_83 ( V_240 , V_230 -> V_228 ) ;
}
}
V_21 = 0 ;
V_215:
F_70 ( & V_5 -> V_137 ) ;
F_70 ( & V_5 -> V_138 . V_139 ) ;
return V_21 ;
}
void F_84 ( struct V_17 * V_5 )
{
T_2 * V_4 = V_5 -> V_6 ;
struct V_2 * V_3 ;
struct V_62 * V_8 ;
struct V_1 T_1 * V_7 ;
int V_21 ;
if ( ! F_85 ( V_5 ) )
return;
V_3 = F_23 ( sizeof( struct V_2 ) , V_48 ) ;
if ( ! V_3 )
return;
F_69 ( & V_5 -> V_137 ) ;
if ( F_86 ( V_4 -> V_3 ) )
goto V_212;
V_3 -> V_5 = V_5 ;
V_8 = F_87 ( V_5 , V_243 ) ;
if ( ! V_8 )
goto V_212;
V_3 -> V_8 = V_8 ;
if ( F_2 ( V_5 ) ) {
V_21 = F_88 ( V_5 , V_8 ,
V_244 ,
V_243 ) ;
if ( V_21 ) {
F_76 ( L_6 ) ;
goto V_245;
}
V_3 -> V_53 = V_8 -> V_9 -> V_10 -> V_246 ;
} else {
V_21 = F_89 ( V_8 , V_243 , true ) ;
if ( V_21 ) {
F_76 ( L_7 ) ;
goto V_245;
}
V_3 -> V_53 = V_8 -> V_14 ;
V_21 = F_90 ( V_8 , true ) ;
if ( V_21 ) {
F_76 ( L_8 ) ;
goto V_247;
}
}
V_3 -> V_103 = 0x0101fe ;
V_3 -> V_221 = - 19 ;
V_3 -> V_220 = 75 ;
V_3 -> V_223 = 146 ;
V_7 = F_1 ( V_3 ) ;
if ( ! V_7 )
goto V_247;
F_91 ( V_7 , 0 , sizeof( struct V_1 ) ) ;
F_42 ( V_7 ) ;
F_78 ( V_3 , V_7 ) ;
F_4 ( V_3 , V_7 ) ;
V_4 -> V_3 = V_3 ;
F_70 ( & V_5 -> V_137 ) ;
F_92 ( L_9 ) ;
return;
V_247:
if ( ! F_2 ( V_5 ) )
F_30 ( V_8 ) ;
V_245:
F_31 ( & V_8 -> V_37 ) ;
V_212:
F_70 ( & V_5 -> V_137 ) ;
F_10 ( V_3 ) ;
return;
}
void F_93 ( struct V_17 * V_5 )
{
T_2 * V_4 = V_5 -> V_6 ;
if ( ! V_4 -> V_3 )
return;
F_8 ( V_4 -> V_3 -> V_47 ) ;
F_77 ( & V_4 -> V_3 -> V_8 -> V_37 ) ;
F_10 ( V_4 -> V_3 ) ;
}
static struct V_1 T_1 *
F_94 ( struct V_2 * V_3 )
{
T_2 * V_4 = V_3 -> V_5 -> V_6 ;
struct V_1 T_1 * V_7 ;
if ( F_2 ( V_3 -> V_5 ) )
V_7 = (struct V_1 T_1 * )
V_3 -> V_8 -> V_9 -> V_10 -> V_11 ;
else
V_7 = F_95 ( V_4 -> V_12 . V_13 ,
V_3 -> V_8 -> V_14 ) ;
return V_7 ;
}
static void F_96 ( struct V_2 * V_3 ,
struct V_1 T_1 * V_7 )
{
if ( ! F_2 ( V_3 -> V_5 ) )
F_97 ( V_7 ) ;
}
struct V_248 *
F_98 ( struct V_17 * V_5 )
{
T_2 * V_4 = V_5 -> V_6 ;
struct V_2 * V_3 = V_4 -> V_3 ;
struct V_248 * error ;
struct V_1 T_1 * V_7 ;
if ( ! V_3 || ! V_3 -> V_47 )
return NULL ;
error = F_71 ( sizeof( * error ) , V_249 ) ;
if ( error == NULL )
return NULL ;
error -> V_250 = F_16 ( V_60 ) ;
error -> V_251 = F_16 ( V_67 ) ;
if ( F_2 ( V_3 -> V_5 ) )
error -> V_37 = ( V_252 long ) V_3 -> V_8 -> V_9 -> V_10 -> V_11 ;
else
error -> V_37 = V_3 -> V_8 -> V_14 ;
V_7 = F_94 ( V_3 ) ;
if ( ! V_7 )
goto V_253;
F_99 ( & error -> V_7 , V_7 , sizeof( struct V_1 ) ) ;
F_96 ( V_3 , V_7 ) ;
return error ;
V_253:
F_10 ( error ) ;
return NULL ;
}
void
F_100 ( struct V_254 * V_255 , struct V_248 * error )
{
F_101 ( V_255 , L_10 ,
error -> V_250 , error -> V_251 ) ;
F_101 ( V_255 , L_11 ,
error -> V_37 ) ;
#define F_102 ( V_40 ) seq_printf(m, " " #x ": 0x%08x\n", error->regs.x)
F_102 ( V_156 ) ;
F_102 ( V_256 ) ;
F_102 ( V_162 ) ;
F_102 ( V_163 ) ;
F_102 ( V_257 ) ;
F_102 ( V_258 ) ;
F_102 ( V_168 ) ;
F_102 ( V_259 ) ;
F_102 ( V_260 ) ;
F_102 ( V_261 ) ;
F_102 ( V_262 ) ;
F_102 ( V_150 ) ;
F_102 ( V_151 ) ;
F_102 ( V_165 ) ;
F_102 ( V_166 ) ;
F_102 ( V_167 ) ;
F_102 ( V_99 ) ;
F_102 ( V_100 ) ;
F_102 ( V_222 ) ;
F_102 ( V_224 ) ;
F_102 ( V_105 ) ;
F_102 ( V_108 ) ;
F_102 ( V_263 ) ;
F_102 ( V_264 ) ;
F_102 ( V_265 ) ;
F_102 ( V_147 ) ;
F_102 ( V_169 ) ;
F_102 ( V_266 ) ;
F_102 ( V_267 ) ;
F_102 ( V_268 ) ;
F_102 ( V_269 ) ;
F_102 ( V_270 ) ;
F_102 ( V_271 ) ;
F_102 ( V_272 ) ;
F_102 ( V_273 ) ;
F_102 ( V_274 ) ;
F_102 ( V_275 ) ;
F_102 ( V_276 ) ;
F_102 ( V_277 ) ;
F_102 ( V_278 ) ;
F_102 ( V_101 ) ;
#undef F_102
}
