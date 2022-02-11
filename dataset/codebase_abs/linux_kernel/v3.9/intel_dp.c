static bool F_1 ( struct V_1 * V_1 )
{
struct V_2 * V_3 = F_2 ( V_1 ) ;
return V_3 -> V_4 . type == V_5 ;
}
static bool F_3 ( struct V_1 * V_1 )
{
return V_1 -> F_3 ;
}
static bool F_4 ( struct V_1 * V_1 )
{
return F_1 ( V_1 ) && ! F_3 ( V_1 ) ;
}
static struct V_6 * F_5 ( struct V_1 * V_1 )
{
struct V_2 * V_3 = F_2 ( V_1 ) ;
return V_3 -> V_4 . V_4 . V_7 ;
}
static struct V_1 * F_6 ( struct V_8 * V_9 )
{
return F_7 ( & F_8 ( V_9 ) -> V_4 ) ;
}
bool F_9 ( struct V_10 * V_11 )
{
struct V_1 * V_1 ;
if ( ! V_11 )
return false ;
V_1 = F_7 ( V_11 ) ;
return F_3 ( V_1 ) ;
}
void
F_10 ( struct V_12 * V_12 ,
int * V_13 , int * V_14 )
{
struct V_1 * V_1 = F_7 ( & V_12 -> V_4 ) ;
* V_13 = V_1 -> V_15 ;
* V_14 = F_11 ( V_1 -> V_14 ) ;
}
int
F_12 ( struct V_12 * V_12 ,
struct V_16 * V_17 )
{
struct V_1 * V_1 = F_7 ( & V_12 -> V_4 ) ;
struct V_18 * V_18 = V_1 -> V_19 ;
if ( V_18 -> V_20 . V_21 )
return V_18 -> V_20 . V_21 -> clock ;
else
return V_17 -> clock ;
}
static int
F_13 ( struct V_1 * V_1 )
{
int V_22 = V_1 -> V_23 [ V_24 ] ;
switch ( V_22 ) {
case V_25 :
case V_26 :
break;
default:
V_22 = V_25 ;
break;
}
return V_22 ;
}
static int
F_14 ( int V_27 , int V_28 )
{
return ( V_27 * V_28 + 9 ) / 10 ;
}
static int
F_15 ( int V_29 , int V_30 )
{
return ( V_29 * V_30 * 8 ) / 10 ;
}
static bool
F_16 ( struct V_1 * V_1 ,
struct V_16 * V_17 ,
bool V_31 )
{
int V_29 =
F_11 ( F_13 ( V_1 ) ) ;
int V_30 = F_17 ( V_1 -> V_23 ) ;
int V_32 , V_33 ;
V_33 = F_14 ( V_17 -> clock , 24 ) ;
V_32 = F_15 ( V_29 , V_30 ) ;
if ( V_33 > V_32 ) {
V_33 = F_14 ( V_17 -> clock , 18 ) ;
if ( V_33 > V_32 )
return false ;
if ( V_31 )
V_17 -> V_34
|= V_35 ;
return true ;
}
return true ;
}
static int
F_18 ( struct V_8 * V_9 ,
struct V_16 * V_17 )
{
struct V_1 * V_1 = F_6 ( V_9 ) ;
struct V_18 * V_18 = F_19 ( V_9 ) ;
struct V_16 * V_21 = V_18 -> V_20 . V_21 ;
if ( F_1 ( V_1 ) && V_21 ) {
if ( V_17 -> V_36 > V_21 -> V_36 )
return V_37 ;
if ( V_17 -> V_38 > V_21 -> V_38 )
return V_37 ;
}
if ( ! F_16 ( V_1 , V_17 , false ) )
return V_39 ;
if ( V_17 -> clock < 10000 )
return V_40 ;
if ( V_17 -> V_41 & V_42 )
return V_43 ;
return V_44 ;
}
static T_1
F_20 ( T_2 * V_45 , int V_46 )
{
int V_47 ;
T_1 V_48 = 0 ;
if ( V_46 > 4 )
V_46 = 4 ;
for ( V_47 = 0 ; V_47 < V_46 ; V_47 ++ )
V_48 |= ( ( T_1 ) V_45 [ V_47 ] ) << ( ( 3 - V_47 ) * 8 ) ;
return V_48 ;
}
static void
F_21 ( T_1 V_45 , T_2 * V_49 , int V_50 )
{
int V_47 ;
if ( V_50 > 4 )
V_50 = 4 ;
for ( V_47 = 0 ; V_47 < V_50 ; V_47 ++ )
V_49 [ V_47 ] = V_45 >> ( ( 3 - V_47 ) * 8 ) ;
}
static int
F_22 ( struct V_6 * V_7 )
{
struct V_51 * V_52 = V_7 -> V_53 ;
T_1 V_54 ;
if ( F_23 ( V_7 ) )
return 200 ;
V_54 = F_24 ( V_55 ) ;
switch ( V_54 & V_56 ) {
case V_57 :
return 100 ;
case V_58 :
return 133 ;
case V_59 :
return 166 ;
case V_60 :
return 200 ;
case V_61 :
return 266 ;
case V_62 :
return 333 ;
case V_63 :
case V_64 :
return 400 ;
default:
return 133 ;
}
}
static bool F_25 ( struct V_1 * V_1 )
{
struct V_6 * V_7 = F_5 ( V_1 ) ;
struct V_51 * V_52 = V_7 -> V_53 ;
return ( F_24 ( V_65 ) & V_66 ) != 0 ;
}
static bool F_26 ( struct V_1 * V_1 )
{
struct V_6 * V_7 = F_5 ( V_1 ) ;
struct V_51 * V_52 = V_7 -> V_53 ;
return ( F_24 ( V_67 ) & V_68 ) != 0 ;
}
static void
F_27 ( struct V_1 * V_1 )
{
struct V_6 * V_7 = F_5 ( V_1 ) ;
struct V_51 * V_52 = V_7 -> V_53 ;
if ( ! F_1 ( V_1 ) )
return;
if ( ! F_25 ( V_1 ) && ! F_26 ( V_1 ) ) {
F_28 ( 1 , L_1 ) ;
F_29 ( L_2 ,
F_24 ( V_65 ) ,
F_24 ( V_67 ) ) ;
}
}
static T_1
F_30 ( struct V_1 * V_1 , bool V_69 )
{
struct V_2 * V_3 = F_2 ( V_1 ) ;
struct V_6 * V_7 = V_3 -> V_4 . V_4 . V_7 ;
struct V_51 * V_52 = V_7 -> V_53 ;
T_1 V_70 = V_1 -> V_71 + 0x10 ;
T_1 V_72 ;
bool V_73 ;
if ( F_31 ( V_7 ) ) {
switch ( V_3 -> V_74 ) {
case V_75 :
V_70 = V_76 ;
break;
case V_77 :
V_70 = V_78 ;
break;
case V_79 :
V_70 = V_80 ;
break;
case V_81 :
V_70 = V_82 ;
break;
default:
F_32 () ;
}
}
#define F_33 (((status = I915_READ_NOTRACE(ch_ctl)) & DP_AUX_CH_CTL_SEND_BUSY) == 0)
if ( V_69 )
V_73 = F_34 ( V_52 -> V_83 , F_33 ,
F_35 ( 10 ) ) ;
else
V_73 = F_36 ( F_33 , 10 ) == 0 ;
if ( ! V_73 )
F_37 ( L_3 ,
V_69 ) ;
#undef F_33
return V_72 ;
}
static int
F_38 ( struct V_1 * V_1 ,
T_2 * V_84 , int V_85 ,
T_2 * V_86 , int V_87 )
{
T_1 V_71 = V_1 -> V_71 ;
struct V_2 * V_3 = F_2 ( V_1 ) ;
struct V_6 * V_7 = V_3 -> V_4 . V_4 . V_7 ;
struct V_51 * V_52 = V_7 -> V_53 ;
T_1 V_70 = V_71 + 0x10 ;
T_1 V_88 = V_70 + 4 ;
int V_47 , V_89 , V_90 ;
T_1 V_72 ;
T_1 V_91 ;
int V_92 , V_93 ;
bool V_69 = F_39 ( V_7 ) -> V_94 >= 5 && ! F_23 ( V_7 ) ;
F_40 ( & V_52 -> V_95 , 0 ) ;
if ( F_31 ( V_7 ) ) {
switch ( V_3 -> V_74 ) {
case V_75 :
V_70 = V_76 ;
V_88 = V_96 ;
break;
case V_77 :
V_70 = V_78 ;
V_88 = V_97 ;
break;
case V_79 :
V_70 = V_80 ;
V_88 = V_98 ;
break;
case V_81 :
V_70 = V_82 ;
V_88 = V_99 ;
break;
default:
F_32 () ;
}
}
F_27 ( V_1 ) ;
if ( F_4 ( V_1 ) ) {
if ( F_41 ( V_7 ) )
V_91 = F_42 ( V_52 ) >> 1 ;
else if ( F_23 ( V_7 ) )
V_91 = 100 ;
else if ( F_43 ( V_7 ) || F_44 ( V_7 ) )
V_91 = 200 ;
else
V_91 = 225 ;
} else if ( F_45 ( V_7 ) )
V_91 = F_46 ( F_47 ( V_7 ) , 2 ) ;
else
V_91 = F_22 ( V_7 ) / 2 ;
if ( F_43 ( V_7 ) )
V_93 = 3 ;
else
V_93 = 5 ;
for ( V_92 = 0 ; V_92 < 3 ; V_92 ++ ) {
V_72 = F_48 ( V_70 ) ;
if ( ( V_72 & V_100 ) == 0 )
break;
F_49 ( 1 ) ;
}
if ( V_92 == 3 ) {
F_28 ( 1 , L_4 ,
F_24 ( V_70 ) ) ;
V_89 = - V_101 ;
goto V_102;
}
for ( V_92 = 0 ; V_92 < 5 ; V_92 ++ ) {
for ( V_47 = 0 ; V_47 < V_85 ; V_47 += 4 )
F_50 ( V_88 + V_47 ,
F_20 ( V_84 + V_47 , V_85 - V_47 ) ) ;
F_50 ( V_70 ,
V_100 |
( V_69 ? V_103 : 0 ) |
V_104 |
( V_85 << V_105 ) |
( V_93 << V_106 ) |
( V_91 << V_107 ) |
V_108 |
V_109 |
V_110 ) ;
V_72 = F_30 ( V_1 , V_69 ) ;
F_50 ( V_70 ,
V_72 |
V_108 |
V_109 |
V_110 ) ;
if ( V_72 & ( V_109 |
V_110 ) )
continue;
if ( V_72 & V_108 )
break;
}
if ( ( V_72 & V_108 ) == 0 ) {
F_37 ( L_5 , V_72 ) ;
V_89 = - V_101 ;
goto V_102;
}
if ( V_72 & V_110 ) {
F_37 ( L_6 , V_72 ) ;
V_89 = - V_111 ;
goto V_102;
}
if ( V_72 & V_109 ) {
F_29 ( L_7 , V_72 ) ;
V_89 = - V_112 ;
goto V_102;
}
V_90 = ( ( V_72 & V_113 ) >>
V_105 ) ;
if ( V_90 > V_87 )
V_90 = V_87 ;
for ( V_47 = 0 ; V_47 < V_90 ; V_47 += 4 )
F_21 ( F_24 ( V_88 + V_47 ) ,
V_86 + V_47 , V_90 - V_47 ) ;
V_89 = V_90 ;
V_102:
F_40 ( & V_52 -> V_95 , V_114 ) ;
return V_89 ;
}
static int
F_51 ( struct V_1 * V_1 ,
T_3 V_115 , T_2 * V_84 , int V_85 )
{
int V_89 ;
T_2 V_116 [ 20 ] ;
int V_117 ;
T_2 V_118 ;
F_27 ( V_1 ) ;
if ( V_85 > 16 )
return - 1 ;
V_116 [ 0 ] = V_119 << 4 ;
V_116 [ 1 ] = V_115 >> 8 ;
V_116 [ 2 ] = V_115 & 0xff ;
V_116 [ 3 ] = V_85 - 1 ;
memcpy ( & V_116 [ 4 ] , V_84 , V_85 ) ;
V_117 = V_85 + 4 ;
for (; ; ) {
V_89 = F_38 ( V_1 , V_116 , V_117 , & V_118 , 1 ) ;
if ( V_89 < 0 )
return V_89 ;
if ( ( V_118 & V_120 ) == V_121 )
break;
else if ( ( V_118 & V_120 ) == V_122 )
F_52 ( 100 ) ;
else
return - V_111 ;
}
return V_85 ;
}
static int
F_53 ( struct V_1 * V_1 ,
T_3 V_115 , T_2 V_123 )
{
return F_51 ( V_1 , V_115 , & V_123 , 1 ) ;
}
static int
F_54 ( struct V_1 * V_1 ,
T_3 V_115 , T_2 * V_86 , int V_90 )
{
T_2 V_116 [ 4 ] ;
int V_117 ;
T_2 V_124 [ 20 ] ;
int V_125 ;
T_2 V_118 ;
int V_89 ;
F_27 ( V_1 ) ;
V_116 [ 0 ] = V_126 << 4 ;
V_116 [ 1 ] = V_115 >> 8 ;
V_116 [ 2 ] = V_115 & 0xff ;
V_116 [ 3 ] = V_90 - 1 ;
V_117 = 4 ;
V_125 = V_90 + 1 ;
for (; ; ) {
V_89 = F_38 ( V_1 , V_116 , V_117 ,
V_124 , V_125 ) ;
if ( V_89 == 0 )
return - V_127 ;
if ( V_89 < 0 )
return V_89 ;
V_118 = V_124 [ 0 ] ;
if ( ( V_118 & V_120 ) == V_121 ) {
memcpy ( V_86 , V_124 + 1 , V_89 - 1 ) ;
return V_89 - 1 ;
}
else if ( ( V_118 & V_120 ) == V_122 )
F_52 ( 100 ) ;
else
return - V_111 ;
}
}
static int
F_55 ( struct V_128 * V_129 , int V_17 ,
T_2 V_130 , T_2 * V_131 )
{
struct V_132 * V_133 = V_129 -> V_133 ;
struct V_1 * V_1 = F_56 ( V_129 ,
struct V_1 ,
V_129 ) ;
T_3 V_115 = V_133 -> V_115 ;
T_2 V_116 [ 5 ] ;
T_2 V_124 [ 2 ] ;
unsigned V_134 ;
int V_117 ;
int V_125 ;
int V_89 ;
F_27 ( V_1 ) ;
if ( V_17 & V_135 )
V_116 [ 0 ] = V_136 << 4 ;
else
V_116 [ 0 ] = V_137 << 4 ;
if ( ! ( V_17 & V_138 ) )
V_116 [ 0 ] |= V_139 << 4 ;
V_116 [ 1 ] = V_115 >> 8 ;
V_116 [ 2 ] = V_115 ;
switch ( V_17 ) {
case V_140 :
V_116 [ 3 ] = 0 ;
V_116 [ 4 ] = V_130 ;
V_117 = 5 ;
V_125 = 1 ;
break;
case V_135 :
V_116 [ 3 ] = 0 ;
V_117 = 4 ;
V_125 = 2 ;
break;
default:
V_117 = 3 ;
V_125 = 1 ;
break;
}
for ( V_134 = 0 ; V_134 < 5 ; V_134 ++ ) {
V_89 = F_38 ( V_1 ,
V_116 , V_117 ,
V_124 , V_125 ) ;
if ( V_89 < 0 ) {
F_29 ( L_8 , V_89 ) ;
return V_89 ;
}
switch ( V_124 [ 0 ] & V_120 ) {
case V_121 :
break;
case V_141 :
F_29 ( L_9 ) ;
return - V_142 ;
case V_122 :
F_52 ( 100 ) ;
continue;
default:
F_37 ( L_10 ,
V_124 [ 0 ] ) ;
return - V_142 ;
}
switch ( V_124 [ 0 ] & V_143 ) {
case V_144 :
if ( V_17 == V_135 ) {
* V_131 = V_124 [ 1 ] ;
}
return V_125 - 1 ;
case V_145 :
F_29 ( L_11 ) ;
return - V_142 ;
case V_146 :
F_29 ( L_12 ) ;
F_52 ( 100 ) ;
break;
default:
F_37 ( L_13 , V_124 [ 0 ] ) ;
return - V_142 ;
}
}
F_37 ( L_14 ) ;
return - V_142 ;
}
static int
F_57 ( struct V_1 * V_1 ,
struct V_18 * V_18 , const char * V_147 )
{
int V_89 ;
F_29 ( L_15 , V_147 ) ;
V_1 -> V_148 . V_149 = false ;
V_1 -> V_148 . V_115 = 0 ;
V_1 -> V_148 . V_150 = F_55 ;
memset ( & V_1 -> V_129 , '\0' , sizeof( V_1 -> V_129 ) ) ;
V_1 -> V_129 . V_151 = V_152 ;
V_1 -> V_129 . V_153 = V_154 ;
strncpy ( V_1 -> V_129 . V_147 , V_147 , sizeof( V_1 -> V_129 . V_147 ) - 1 ) ;
V_1 -> V_129 . V_147 [ sizeof( V_1 -> V_129 . V_147 ) - 1 ] = '\0' ;
V_1 -> V_129 . V_133 = & V_1 -> V_148 ;
V_1 -> V_129 . V_7 . V_155 = & V_18 -> V_4 . V_156 ;
F_58 ( V_1 ) ;
V_89 = F_59 ( & V_1 -> V_129 ) ;
F_60 ( V_1 , false ) ;
return V_89 ;
}
bool
F_61 ( struct V_10 * V_11 ,
const struct V_16 * V_17 ,
struct V_16 * V_157 )
{
struct V_6 * V_7 = V_11 -> V_7 ;
struct V_1 * V_1 = F_7 ( V_11 ) ;
struct V_18 * V_18 = V_1 -> V_19 ;
int V_15 , clock ;
int V_158 = F_17 ( V_1 -> V_23 ) ;
int V_159 = F_13 ( V_1 ) == V_26 ? 1 : 0 ;
int V_28 , V_33 ;
static int V_160 [ 2 ] = { V_25 , V_26 } ;
if ( F_1 ( V_1 ) && V_18 -> V_20 . V_21 ) {
F_62 ( V_18 -> V_20 . V_21 ,
V_157 ) ;
F_63 ( V_7 ,
V_18 -> V_20 . V_161 ,
V_17 , V_157 ) ;
}
if ( V_157 -> V_41 & V_42 )
return false ;
F_29 ( L_16
L_17 ,
V_158 , V_160 [ V_159 ] , V_157 -> clock ) ;
if ( ! F_16 ( V_1 , V_157 , true ) )
return false ;
V_28 = V_157 -> V_34 & V_35 ? 18 : 24 ;
if ( V_1 -> V_162 ) {
if ( V_28 != 18 && F_64 ( V_157 ) > 1 )
V_1 -> V_163 = V_164 ;
else
V_1 -> V_163 = 0 ;
}
if ( V_1 -> V_163 )
V_157 -> V_34 |= V_165 ;
V_33 = F_14 ( V_157 -> clock , V_28 ) ;
for ( clock = 0 ; clock <= V_159 ; clock ++ ) {
for ( V_15 = 1 ; V_15 <= V_158 ; V_15 <<= 1 ) {
int V_166 =
F_11 ( V_160 [ clock ] ) ;
int V_167 = F_15 ( V_166 ,
V_15 ) ;
if ( V_33 <= V_167 ) {
V_1 -> V_14 = V_160 [ clock ] ;
V_1 -> V_15 = V_15 ;
V_157 -> clock = V_166 ;
F_29 ( L_18
L_19 ,
V_1 -> V_14 , V_1 -> V_15 ,
V_157 -> clock , V_28 ) ;
F_29 ( L_20 ,
V_33 , V_167 ) ;
return true ;
}
}
}
return false ;
}
void
F_65 ( struct V_168 * V_169 , struct V_16 * V_17 ,
struct V_16 * V_157 )
{
struct V_6 * V_7 = V_169 -> V_7 ;
struct V_12 * V_12 ;
struct V_1 * V_1 ;
struct V_51 * V_52 = V_7 -> V_53 ;
struct V_170 * V_170 = F_66 ( V_169 ) ;
int V_15 = 4 ;
struct V_171 V_172 ;
int V_173 = V_170 -> V_173 ;
enum V_174 V_175 = V_170 -> V_175 ;
int V_176 ;
F_67 (dev, crtc, intel_encoder) {
V_1 = F_7 ( & V_12 -> V_4 ) ;
if ( V_12 -> type == V_177 ||
V_12 -> type == V_5 )
{
V_15 = V_1 -> V_15 ;
break;
}
}
V_176 = V_17 -> clock ;
F_67 (dev, crtc, intel_encoder) {
if ( V_12 -> type == V_5 ) {
V_176 = F_12 ( V_12 ,
V_17 ) ;
break;
}
}
F_68 ( V_170 -> V_28 , V_15 ,
V_176 , V_157 -> clock , & V_172 ) ;
if ( F_31 ( V_7 ) ) {
F_50 ( F_69 ( V_175 ) ,
F_70 ( V_172 . V_178 ) | V_172 . V_179 ) ;
F_50 ( F_71 ( V_175 ) , V_172 . V_180 ) ;
F_50 ( F_72 ( V_175 ) , V_172 . V_181 ) ;
F_50 ( F_73 ( V_175 ) , V_172 . V_182 ) ;
} else if ( F_45 ( V_7 ) ) {
F_50 ( F_74 ( V_173 ) , F_70 ( V_172 . V_178 ) | V_172 . V_179 ) ;
F_50 ( F_75 ( V_173 ) , V_172 . V_180 ) ;
F_50 ( F_76 ( V_173 ) , V_172 . V_181 ) ;
F_50 ( F_77 ( V_173 ) , V_172 . V_182 ) ;
} else if ( F_23 ( V_7 ) ) {
F_50 ( F_69 ( V_173 ) , F_70 ( V_172 . V_178 ) | V_172 . V_179 ) ;
F_50 ( F_71 ( V_173 ) , V_172 . V_180 ) ;
F_50 ( F_72 ( V_173 ) , V_172 . V_181 ) ;
F_50 ( F_73 ( V_173 ) , V_172 . V_182 ) ;
} else {
F_50 ( F_78 ( V_173 ) ,
F_70 ( V_172 . V_178 ) | V_172 . V_179 ) ;
F_50 ( F_79 ( V_173 ) , V_172 . V_180 ) ;
F_50 ( F_80 ( V_173 ) , V_172 . V_181 ) ;
F_50 ( F_81 ( V_173 ) , V_172 . V_182 ) ;
}
}
void F_82 ( struct V_1 * V_1 )
{
memset ( V_1 -> V_183 , 0 , V_184 ) ;
V_1 -> V_183 [ 0 ] = V_1 -> V_14 ;
V_1 -> V_183 [ 1 ] = V_1 -> V_15 ;
V_1 -> V_183 [ 8 ] = V_185 ;
if ( V_1 -> V_23 [ V_186 ] >= 0x11 &&
( V_1 -> V_23 [ V_187 ] & V_188 ) ) {
V_1 -> V_183 [ 1 ] |= V_189 ;
}
}
static void F_83 ( struct V_168 * V_169 , int clock )
{
struct V_6 * V_7 = V_169 -> V_7 ;
struct V_51 * V_52 = V_7 -> V_53 ;
T_4 V_190 ;
F_29 ( L_21 , clock ) ;
V_190 = F_24 ( V_191 ) ;
V_190 &= ~ V_192 ;
if ( clock < 200000 ) {
F_29 ( L_22 ) ;
V_190 |= V_193 ;
} else {
V_190 |= V_194 ;
}
F_50 ( V_191 , V_190 ) ;
F_84 ( V_191 ) ;
F_52 ( 500 ) ;
}
static void
F_85 ( struct V_10 * V_11 , struct V_16 * V_17 ,
struct V_16 * V_157 )
{
struct V_6 * V_7 = V_11 -> V_7 ;
struct V_51 * V_52 = V_7 -> V_53 ;
struct V_1 * V_1 = F_7 ( V_11 ) ;
struct V_168 * V_169 = V_11 -> V_169 ;
struct V_170 * V_170 = F_66 ( V_169 ) ;
V_1 -> V_195 = F_24 ( V_1 -> V_71 ) & V_196 ;
V_1 -> V_195 |= V_197 | V_198 ;
switch ( V_1 -> V_15 ) {
case 1 :
V_1 -> V_195 |= V_199 ;
break;
case 2 :
V_1 -> V_195 |= V_200 ;
break;
case 4 :
V_1 -> V_195 |= V_201 ;
break;
}
if ( V_1 -> V_202 ) {
F_86 ( L_23 ,
F_87 ( V_170 -> V_173 ) ) ;
V_1 -> V_195 |= V_203 ;
F_88 ( V_11 , V_157 ) ;
}
F_82 ( V_1 ) ;
if ( F_4 ( V_1 ) && F_44 ( V_7 ) && ! F_23 ( V_7 ) ) {
if ( V_157 -> V_41 & V_204 )
V_1 -> V_195 |= V_205 ;
if ( V_157 -> V_41 & V_206 )
V_1 -> V_195 |= V_207 ;
V_1 -> V_195 |= V_208 ;
if ( V_1 -> V_183 [ 1 ] & V_189 )
V_1 -> V_195 |= V_209 ;
V_1 -> V_195 |= V_170 -> V_173 << 29 ;
if ( V_157 -> clock < 200000 )
V_1 -> V_195 |= V_193 ;
else
V_1 -> V_195 |= V_194 ;
} else if ( ! F_89 ( V_7 ) || F_4 ( V_1 ) ) {
if ( ! F_45 ( V_7 ) )
V_1 -> V_195 |= V_1 -> V_163 ;
if ( V_157 -> V_41 & V_204 )
V_1 -> V_195 |= V_205 ;
if ( V_157 -> V_41 & V_206 )
V_1 -> V_195 |= V_207 ;
V_1 -> V_195 |= V_210 ;
if ( V_1 -> V_183 [ 1 ] & V_189 )
V_1 -> V_195 |= V_209 ;
if ( V_170 -> V_173 == 1 )
V_1 -> V_195 |= V_211 ;
if ( F_4 ( V_1 ) ) {
if ( V_157 -> clock < 200000 )
V_1 -> V_195 |= V_193 ;
else
V_1 -> V_195 |= V_194 ;
}
} else {
V_1 -> V_195 |= V_208 ;
}
if ( F_4 ( V_1 ) )
F_83 ( V_169 , V_157 -> clock ) ;
}
static void F_90 ( struct V_1 * V_1 ,
T_4 V_212 ,
T_4 V_213 )
{
struct V_6 * V_7 = F_5 ( V_1 ) ;
struct V_51 * V_52 = V_7 -> V_53 ;
F_29 ( L_24 ,
V_212 , V_213 ,
F_24 ( V_65 ) ,
F_24 ( V_67 ) ) ;
if ( F_91 ( ( F_24 ( V_65 ) & V_212 ) == V_213 , 5000 , 10 ) ) {
F_37 ( L_25 ,
F_24 ( V_65 ) ,
F_24 ( V_67 ) ) ;
}
}
static void F_92 ( struct V_1 * V_1 )
{
F_29 ( L_26 ) ;
F_90 ( V_1 , V_214 , V_215 ) ;
}
static void F_93 ( struct V_1 * V_1 )
{
F_29 ( L_27 ) ;
F_90 ( V_1 , V_216 , V_217 ) ;
}
static void F_94 ( struct V_1 * V_1 )
{
F_29 ( L_28 ) ;
F_90 ( V_1 , V_218 , V_219 ) ;
}
static T_4 F_95 ( struct V_51 * V_52 )
{
T_4 V_220 = F_24 ( V_67 ) ;
V_220 &= ~ V_221 ;
V_220 |= V_222 ;
return V_220 ;
}
void F_58 ( struct V_1 * V_1 )
{
struct V_6 * V_7 = F_5 ( V_1 ) ;
struct V_51 * V_52 = V_7 -> V_53 ;
T_4 V_223 ;
if ( ! F_1 ( V_1 ) )
return;
F_29 ( L_29 ) ;
F_28 ( V_1 -> V_224 ,
L_30 ) ;
V_1 -> V_224 = true ;
if ( F_26 ( V_1 ) ) {
F_29 ( L_31 ) ;
return;
}
if ( ! F_25 ( V_1 ) )
F_94 ( V_1 ) ;
V_223 = F_95 ( V_52 ) ;
V_223 |= V_68 ;
F_50 ( V_67 , V_223 ) ;
F_84 ( V_67 ) ;
F_29 ( L_32 ,
F_24 ( V_65 ) , F_24 ( V_67 ) ) ;
if ( ! F_25 ( V_1 ) ) {
F_29 ( L_33 ) ;
F_49 ( V_1 -> V_225 ) ;
}
}
static void F_96 ( struct V_1 * V_1 )
{
struct V_6 * V_7 = F_5 ( V_1 ) ;
struct V_51 * V_52 = V_7 -> V_53 ;
T_4 V_223 ;
F_97 ( ! F_98 ( & V_7 -> V_226 . V_227 ) ) ;
if ( ! V_1 -> V_224 && F_26 ( V_1 ) ) {
V_223 = F_95 ( V_52 ) ;
V_223 &= ~ V_68 ;
F_50 ( V_67 , V_223 ) ;
F_84 ( V_67 ) ;
F_29 ( L_32 ,
F_24 ( V_65 ) , F_24 ( V_67 ) ) ;
F_49 ( V_1 -> V_228 ) ;
}
}
static void F_99 ( struct V_229 * V_230 )
{
struct V_1 * V_1 = F_56 ( F_100 ( V_230 ) ,
struct V_1 , V_231 ) ;
struct V_6 * V_7 = F_5 ( V_1 ) ;
F_101 ( & V_7 -> V_226 . V_227 ) ;
F_96 ( V_1 ) ;
F_102 ( & V_7 -> V_226 . V_227 ) ;
}
void F_60 ( struct V_1 * V_1 , bool V_232 )
{
if ( ! F_1 ( V_1 ) )
return;
F_29 ( L_34 , V_1 -> V_224 ) ;
F_28 ( ! V_1 -> V_224 , L_35 ) ;
V_1 -> V_224 = false ;
if ( V_232 ) {
F_96 ( V_1 ) ;
} else {
F_103 ( & V_1 -> V_231 ,
F_35 ( V_1 -> V_233 * 5 ) ) ;
}
}
void F_104 ( struct V_1 * V_1 )
{
struct V_6 * V_7 = F_5 ( V_1 ) ;
struct V_51 * V_52 = V_7 -> V_53 ;
T_4 V_223 ;
if ( ! F_1 ( V_1 ) )
return;
F_29 ( L_36 ) ;
if ( F_25 ( V_1 ) ) {
F_29 ( L_37 ) ;
return;
}
F_94 ( V_1 ) ;
V_223 = F_95 ( V_52 ) ;
if ( F_105 ( V_7 ) ) {
V_223 &= ~ V_234 ;
F_50 ( V_67 , V_223 ) ;
F_84 ( V_67 ) ;
}
V_223 |= V_235 ;
if ( ! F_105 ( V_7 ) )
V_223 |= V_234 ;
F_50 ( V_67 , V_223 ) ;
F_84 ( V_67 ) ;
F_92 ( V_1 ) ;
if ( F_105 ( V_7 ) ) {
V_223 |= V_234 ;
F_50 ( V_67 , V_223 ) ;
F_84 ( V_67 ) ;
}
}
void F_106 ( struct V_1 * V_1 )
{
struct V_6 * V_7 = F_5 ( V_1 ) ;
struct V_51 * V_52 = V_7 -> V_53 ;
T_4 V_223 ;
if ( ! F_1 ( V_1 ) )
return;
F_29 ( L_38 ) ;
F_28 ( ! V_1 -> V_224 , L_39 ) ;
V_223 = F_95 ( V_52 ) ;
V_223 &= ~ ( V_235 | V_68 | V_234 | V_236 ) ;
F_50 ( V_67 , V_223 ) ;
F_84 ( V_67 ) ;
V_1 -> V_224 = false ;
F_93 ( V_1 ) ;
}
void F_107 ( struct V_1 * V_1 )
{
struct V_2 * V_3 = F_2 ( V_1 ) ;
struct V_6 * V_7 = V_3 -> V_4 . V_4 . V_7 ;
struct V_51 * V_52 = V_7 -> V_53 ;
int V_173 = F_66 ( V_3 -> V_4 . V_4 . V_169 ) -> V_173 ;
T_4 V_223 ;
if ( ! F_1 ( V_1 ) )
return;
F_29 ( L_40 ) ;
F_49 ( V_1 -> V_237 ) ;
V_223 = F_95 ( V_52 ) ;
V_223 |= V_236 ;
F_50 ( V_67 , V_223 ) ;
F_84 ( V_67 ) ;
F_108 ( V_7 , V_173 ) ;
}
void F_109 ( struct V_1 * V_1 )
{
struct V_6 * V_7 = F_5 ( V_1 ) ;
struct V_51 * V_52 = V_7 -> V_53 ;
T_4 V_223 ;
if ( ! F_1 ( V_1 ) )
return;
F_110 ( V_7 ) ;
F_29 ( L_40 ) ;
V_223 = F_95 ( V_52 ) ;
V_223 &= ~ V_236 ;
F_50 ( V_67 , V_223 ) ;
F_84 ( V_67 ) ;
F_49 ( V_1 -> V_238 ) ;
}
static void F_111 ( struct V_1 * V_1 )
{
struct V_2 * V_3 = F_2 ( V_1 ) ;
struct V_168 * V_169 = V_3 -> V_4 . V_4 . V_169 ;
struct V_6 * V_7 = V_169 -> V_7 ;
struct V_51 * V_52 = V_7 -> V_53 ;
T_4 V_190 ;
F_112 ( V_52 ,
F_66 ( V_169 ) -> V_173 ) ;
F_29 ( L_40 ) ;
V_190 = F_24 ( V_191 ) ;
F_28 ( V_190 & V_239 , L_41 ) ;
F_28 ( V_190 & V_240 , L_42 ) ;
V_1 -> V_195 &= ~ ( V_240 | V_203 ) ;
V_1 -> V_195 |= V_239 ;
F_50 ( V_191 , V_1 -> V_195 ) ;
F_84 ( V_191 ) ;
F_52 ( 200 ) ;
}
static void F_113 ( struct V_1 * V_1 )
{
struct V_2 * V_3 = F_2 ( V_1 ) ;
struct V_168 * V_169 = V_3 -> V_4 . V_4 . V_169 ;
struct V_6 * V_7 = V_169 -> V_7 ;
struct V_51 * V_52 = V_7 -> V_53 ;
T_4 V_190 ;
F_112 ( V_52 ,
F_66 ( V_169 ) -> V_173 ) ;
V_190 = F_24 ( V_191 ) ;
F_28 ( ( V_190 & V_239 ) == 0 ,
L_43 ) ;
F_28 ( V_190 & V_240 , L_42 ) ;
V_190 &= ~ V_239 ;
F_50 ( V_191 , V_190 ) ;
F_84 ( V_191 ) ;
F_52 ( 200 ) ;
}
void F_114 ( struct V_1 * V_1 , int V_17 )
{
int V_89 , V_47 ;
if ( V_1 -> V_23 [ V_186 ] < 0x11 )
return;
if ( V_17 != V_241 ) {
V_89 = F_53 ( V_1 , V_242 ,
V_243 ) ;
if ( V_89 != 1 )
F_86 ( L_44 ) ;
} else {
for ( V_47 = 0 ; V_47 < 3 ; V_47 ++ ) {
V_89 = F_53 ( V_1 ,
V_242 ,
V_244 ) ;
if ( V_89 == 1 )
break;
F_49 ( 1 ) ;
}
}
}
static bool F_115 ( struct V_12 * V_11 ,
enum V_173 * V_173 )
{
struct V_1 * V_1 = F_7 ( & V_11 -> V_4 ) ;
struct V_6 * V_7 = V_11 -> V_4 . V_7 ;
struct V_51 * V_52 = V_7 -> V_53 ;
T_4 V_245 = F_24 ( V_1 -> V_71 ) ;
if ( ! ( V_245 & V_240 ) )
return false ;
if ( F_4 ( V_1 ) && F_44 ( V_7 ) ) {
* V_173 = F_116 ( V_245 ) ;
} else if ( ! F_89 ( V_7 ) || F_4 ( V_1 ) ) {
* V_173 = F_117 ( V_245 ) ;
} else {
T_4 V_246 ;
T_4 V_247 ;
int V_47 ;
switch ( V_1 -> V_71 ) {
case V_248 :
V_246 = V_249 ;
break;
case V_250 :
V_246 = V_251 ;
break;
case V_252 :
V_246 = V_253 ;
break;
default:
return true ;
}
F_118 (i) {
V_247 = F_24 ( F_119 ( V_47 ) ) ;
if ( ( V_247 & V_254 ) == V_246 ) {
* V_173 = V_47 ;
return true ;
}
}
F_29 ( L_45 ,
V_1 -> V_71 ) ;
}
return true ;
}
static void F_120 ( struct V_12 * V_11 )
{
struct V_1 * V_1 = F_7 ( & V_11 -> V_4 ) ;
F_58 ( V_1 ) ;
F_109 ( V_1 ) ;
F_114 ( V_1 , V_241 ) ;
F_106 ( V_1 ) ;
if ( ! F_4 ( V_1 ) )
F_121 ( V_1 ) ;
}
static void F_122 ( struct V_12 * V_11 )
{
struct V_1 * V_1 = F_7 ( & V_11 -> V_4 ) ;
if ( F_4 ( V_1 ) ) {
F_121 ( V_1 ) ;
F_113 ( V_1 ) ;
}
}
static void F_123 ( struct V_12 * V_11 )
{
struct V_1 * V_1 = F_7 ( & V_11 -> V_4 ) ;
struct V_6 * V_7 = V_11 -> V_4 . V_7 ;
struct V_51 * V_52 = V_7 -> V_53 ;
T_1 V_255 = F_24 ( V_1 -> V_71 ) ;
if ( F_97 ( V_255 & V_240 ) )
return;
F_58 ( V_1 ) ;
F_114 ( V_1 , V_241 ) ;
F_124 ( V_1 ) ;
F_104 ( V_1 ) ;
F_60 ( V_1 , true ) ;
F_125 ( V_1 ) ;
F_107 ( V_1 ) ;
}
static void F_126 ( struct V_12 * V_11 )
{
struct V_1 * V_1 = F_7 ( & V_11 -> V_4 ) ;
if ( F_4 ( V_1 ) )
F_111 ( V_1 ) ;
}
static bool
F_127 ( struct V_1 * V_1 , T_3 V_115 ,
T_2 * V_86 , int V_90 )
{
int V_89 , V_47 ;
for ( V_47 = 0 ; V_47 < 3 ; V_47 ++ ) {
V_89 = F_54 ( V_1 , V_115 , V_86 ,
V_90 ) ;
if ( V_89 == V_90 )
return true ;
F_49 ( 1 ) ;
}
return false ;
}
static bool
F_128 ( struct V_1 * V_1 , T_2 V_256 [ V_257 ] )
{
return F_127 ( V_1 ,
V_258 ,
V_256 ,
V_257 ) ;
}
static T_2
F_129 ( struct V_1 * V_1 )
{
struct V_6 * V_7 = F_5 ( V_1 ) ;
if ( F_44 ( V_7 ) && F_4 ( V_1 ) )
return V_259 ;
else if ( F_89 ( V_7 ) && ! F_4 ( V_1 ) )
return V_260 ;
else
return V_259 ;
}
static T_2
F_130 ( struct V_1 * V_1 , T_2 V_261 )
{
struct V_6 * V_7 = F_5 ( V_1 ) ;
if ( F_31 ( V_7 ) ) {
switch ( V_261 & V_262 ) {
case V_263 :
return V_264 ;
case V_265 :
return V_266 ;
case V_259 :
return V_267 ;
case V_260 :
default:
return V_268 ;
}
} else if ( F_44 ( V_7 ) && F_4 ( V_1 ) && ! F_23 ( V_7 ) ) {
switch ( V_261 & V_262 ) {
case V_263 :
return V_266 ;
case V_265 :
case V_259 :
return V_267 ;
default:
return V_268 ;
}
} else {
switch ( V_261 & V_262 ) {
case V_263 :
return V_266 ;
case V_265 :
return V_266 ;
case V_259 :
return V_267 ;
case V_260 :
default:
return V_268 ;
}
}
}
static void
F_131 ( struct V_1 * V_1 , T_2 V_256 [ V_257 ] )
{
T_2 V_48 = 0 ;
T_2 V_269 = 0 ;
int V_270 ;
T_2 V_271 ;
T_2 V_272 ;
for ( V_270 = 0 ; V_270 < V_1 -> V_15 ; V_270 ++ ) {
T_2 V_273 = F_132 ( V_256 , V_270 ) ;
T_2 V_274 = F_133 ( V_256 , V_270 ) ;
if ( V_273 > V_48 )
V_48 = V_273 ;
if ( V_274 > V_269 )
V_269 = V_274 ;
}
V_271 = F_129 ( V_1 ) ;
if ( V_48 >= V_271 )
V_48 = V_271 | V_275 ;
V_272 = F_130 ( V_1 , V_48 ) ;
if ( V_269 >= V_272 )
V_269 = V_272 | V_276 ;
for ( V_270 = 0 ; V_270 < 4 ; V_270 ++ )
V_1 -> V_277 [ V_270 ] = V_48 | V_269 ;
}
static T_1
F_134 ( T_2 V_277 )
{
T_1 V_278 = 0 ;
switch ( V_277 & V_262 ) {
case V_263 :
default:
V_278 |= V_197 ;
break;
case V_265 :
V_278 |= V_279 ;
break;
case V_259 :
V_278 |= V_280 ;
break;
case V_260 :
V_278 |= V_281 ;
break;
}
switch ( V_277 & V_282 ) {
case V_268 :
default:
V_278 |= V_198 ;
break;
case V_267 :
V_278 |= V_283 ;
break;
case V_266 :
V_278 |= V_284 ;
break;
case V_264 :
V_278 |= V_285 ;
break;
}
return V_278 ;
}
static T_1
F_135 ( T_2 V_277 )
{
int V_278 = V_277 & ( V_262 |
V_282 ) ;
switch ( V_278 ) {
case V_263 | V_268 :
case V_265 | V_268 :
return V_286 ;
case V_263 | V_267 :
return V_287 ;
case V_263 | V_266 :
case V_265 | V_266 :
return V_288 ;
case V_265 | V_267 :
case V_259 | V_267 :
return V_289 ;
case V_259 | V_268 :
case V_260 | V_268 :
return V_290 ;
default:
F_29 ( L_46
L_47 , V_278 ) ;
return V_286 ;
}
}
static T_1
F_136 ( T_2 V_277 )
{
int V_278 = V_277 & ( V_262 |
V_282 ) ;
switch ( V_278 ) {
case V_263 | V_268 :
return V_291 ;
case V_263 | V_267 :
return V_292 ;
case V_263 | V_266 :
return V_293 ;
case V_265 | V_268 :
return V_294 ;
case V_265 | V_267 :
return V_295 ;
case V_259 | V_268 :
return V_296 ;
case V_259 | V_267 :
return V_297 ;
default:
F_29 ( L_46
L_47 , V_278 ) ;
return V_298 ;
}
}
static T_1
F_137 ( T_2 V_277 )
{
int V_278 = V_277 & ( V_262 |
V_282 ) ;
switch ( V_278 ) {
case V_263 | V_268 :
return V_299 ;
case V_263 | V_267 :
return V_300 ;
case V_263 | V_266 :
return V_301 ;
case V_263 | V_264 :
return V_302 ;
case V_265 | V_268 :
return V_303 ;
case V_265 | V_267 :
return V_304 ;
case V_265 | V_266 :
return V_305 ;
case V_259 | V_268 :
return V_306 ;
case V_259 | V_267 :
return V_307 ;
default:
F_29 ( L_46
L_47 , V_278 ) ;
return V_299 ;
}
}
static void
F_138 ( struct V_1 * V_1 , T_1 * V_195 )
{
struct V_2 * V_3 = F_2 ( V_1 ) ;
struct V_6 * V_7 = V_3 -> V_4 . V_4 . V_7 ;
T_1 V_278 , V_212 ;
T_2 V_277 = V_1 -> V_277 [ 0 ] ;
if ( F_31 ( V_7 ) ) {
V_278 = F_137 ( V_277 ) ;
V_212 = V_308 ;
} else if ( F_44 ( V_7 ) && F_4 ( V_1 ) && ! F_23 ( V_7 ) ) {
V_278 = F_136 ( V_277 ) ;
V_212 = V_309 ;
} else if ( F_43 ( V_7 ) && F_4 ( V_1 ) ) {
V_278 = F_135 ( V_277 ) ;
V_212 = V_310 ;
} else {
V_278 = F_134 ( V_277 ) ;
V_212 = V_311 | V_312 ;
}
F_29 ( L_48 , V_278 ) ;
* V_195 = ( * V_195 & ~ V_212 ) | V_278 ;
}
static bool
F_139 ( struct V_1 * V_1 ,
T_1 V_313 ,
T_2 V_314 )
{
struct V_2 * V_3 = F_2 ( V_1 ) ;
struct V_6 * V_7 = V_3 -> V_4 . V_4 . V_7 ;
struct V_51 * V_52 = V_7 -> V_53 ;
enum V_74 V_74 = V_3 -> V_74 ;
int V_89 ;
T_1 V_315 ;
if ( F_31 ( V_7 ) ) {
V_315 = F_24 ( F_140 ( V_74 ) ) ;
if ( V_314 & V_316 )
V_315 |= V_317 ;
else
V_315 &= ~ V_317 ;
V_315 &= ~ V_318 ;
switch ( V_314 & V_319 ) {
case V_320 :
if ( V_74 != V_75 ) {
V_315 |= V_321 ;
F_50 ( F_140 ( V_74 ) , V_315 ) ;
if ( F_141 ( ( F_24 ( F_142 ( V_74 ) ) &
V_322 ) , 1 ) )
F_37 ( L_49 ) ;
V_315 &= ~ V_318 ;
}
V_315 |= V_323 ;
break;
case V_324 :
V_315 |= V_325 ;
break;
case V_326 :
V_315 |= V_327 ;
break;
case V_328 :
V_315 |= V_329 ;
break;
}
F_50 ( F_140 ( V_74 ) , V_315 ) ;
} else if ( F_89 ( V_7 ) &&
( F_44 ( V_7 ) || ! F_4 ( V_1 ) ) ) {
V_313 &= ~ V_330 ;
switch ( V_314 & V_319 ) {
case V_320 :
V_313 |= V_208 ;
break;
case V_324 :
V_313 |= V_331 ;
break;
case V_326 :
V_313 |= V_332 ;
break;
case V_328 :
F_37 ( L_50 ) ;
V_313 |= V_332 ;
break;
}
} else {
V_313 &= ~ V_333 ;
switch ( V_314 & V_319 ) {
case V_320 :
V_313 |= V_210 ;
break;
case V_324 :
V_313 |= V_334 ;
break;
case V_326 :
V_313 |= V_335 ;
break;
case V_328 :
F_37 ( L_50 ) ;
V_313 |= V_335 ;
break;
}
}
F_50 ( V_1 -> V_71 , V_313 ) ;
F_84 ( V_1 -> V_71 ) ;
F_53 ( V_1 ,
V_336 ,
V_314 ) ;
if ( ( V_314 & V_319 ) !=
V_320 ) {
V_89 = F_51 ( V_1 ,
V_337 ,
V_1 -> V_277 ,
V_1 -> V_15 ) ;
if ( V_89 != V_1 -> V_15 )
return false ;
}
return true ;
}
void
F_124 ( struct V_1 * V_1 )
{
struct V_10 * V_11 = & F_2 ( V_1 ) -> V_4 . V_4 ;
struct V_6 * V_7 = V_11 -> V_7 ;
int V_47 ;
T_2 V_338 ;
bool V_339 = false ;
int V_340 , V_341 ;
T_1 V_195 = V_1 -> V_195 ;
if ( F_41 ( V_7 ) )
F_143 ( V_11 ) ;
F_51 ( V_1 , V_342 ,
V_1 -> V_183 ,
V_184 ) ;
V_195 |= V_240 ;
memset ( V_1 -> V_277 , 0 , 4 ) ;
V_338 = 0xff ;
V_340 = 0 ;
V_341 = 0 ;
V_339 = false ;
for (; ; ) {
T_2 V_256 [ V_257 ] ;
F_138 ( V_1 , & V_195 ) ;
if ( ! F_139 ( V_1 , V_195 ,
V_324 |
V_316 ) )
break;
F_144 ( V_1 -> V_23 ) ;
if ( ! F_128 ( V_1 , V_256 ) ) {
F_37 ( L_51 ) ;
break;
}
if ( F_145 ( V_256 , V_1 -> V_15 ) ) {
F_29 ( L_52 ) ;
V_339 = true ;
break;
}
for ( V_47 = 0 ; V_47 < V_1 -> V_15 ; V_47 ++ )
if ( ( V_1 -> V_277 [ V_47 ] & V_275 ) == 0 )
break;
if ( V_47 == V_1 -> V_15 ) {
++ V_341 ;
if ( V_341 == 5 ) {
F_29 ( L_53 ) ;
break;
}
memset ( V_1 -> V_277 , 0 , 4 ) ;
V_340 = 0 ;
continue;
}
if ( ( V_1 -> V_277 [ 0 ] & V_262 ) == V_338 ) {
++ V_340 ;
if ( V_340 == 5 ) {
F_29 ( L_54 ) ;
break;
}
} else
V_340 = 0 ;
V_338 = V_1 -> V_277 [ 0 ] & V_262 ;
F_131 ( V_1 , V_256 ) ;
}
V_1 -> V_195 = V_195 ;
}
void
F_125 ( struct V_1 * V_1 )
{
bool V_343 = false ;
int V_344 , V_345 ;
T_1 V_195 = V_1 -> V_195 ;
V_344 = 0 ;
V_345 = 0 ;
V_343 = false ;
for (; ; ) {
T_2 V_256 [ V_257 ] ;
if ( V_345 > 5 ) {
F_37 ( L_55 ) ;
F_121 ( V_1 ) ;
break;
}
F_138 ( V_1 , & V_195 ) ;
if ( ! F_139 ( V_1 , V_195 ,
V_326 |
V_316 ) )
break;
F_146 ( V_1 -> V_23 ) ;
if ( ! F_128 ( V_1 , V_256 ) )
break;
if ( ! F_145 ( V_256 , V_1 -> V_15 ) ) {
F_124 ( V_1 ) ;
V_345 ++ ;
continue;
}
if ( F_147 ( V_256 , V_1 -> V_15 ) ) {
V_343 = true ;
break;
}
if ( V_344 > 5 ) {
F_121 ( V_1 ) ;
F_124 ( V_1 ) ;
V_344 = 0 ;
V_345 ++ ;
continue;
}
F_131 ( V_1 , V_256 ) ;
++ V_344 ;
}
if ( V_343 )
F_29 ( L_56 ) ;
F_139 ( V_1 , V_195 , V_320 ) ;
}
static void
F_121 ( struct V_1 * V_1 )
{
struct V_2 * V_3 = F_2 ( V_1 ) ;
struct V_6 * V_7 = V_3 -> V_4 . V_4 . V_7 ;
struct V_51 * V_52 = V_7 -> V_53 ;
struct V_170 * V_170 =
F_66 ( V_3 -> V_4 . V_4 . V_169 ) ;
T_1 V_195 = V_1 -> V_195 ;
if ( F_41 ( V_7 ) )
return;
if ( F_97 ( ( F_24 ( V_1 -> V_71 ) & V_240 ) == 0 ) )
return;
F_29 ( L_40 ) ;
if ( F_89 ( V_7 ) && ( F_44 ( V_7 ) || ! F_4 ( V_1 ) ) ) {
V_195 &= ~ V_330 ;
F_50 ( V_1 -> V_71 , V_195 | V_346 ) ;
} else {
V_195 &= ~ V_333 ;
F_50 ( V_1 -> V_71 , V_195 | V_347 ) ;
}
F_84 ( V_1 -> V_71 ) ;
F_148 ( V_7 , V_170 -> V_173 ) ;
if ( F_149 ( V_7 ) &&
F_24 ( V_1 -> V_71 ) & V_211 ) {
struct V_168 * V_169 = V_3 -> V_4 . V_4 . V_169 ;
V_195 &= ~ V_211 ;
F_50 ( V_1 -> V_71 , V_195 ) ;
if ( F_97 ( V_169 == NULL ) ) {
F_84 ( V_1 -> V_71 ) ;
F_49 ( 50 ) ;
} else
F_148 ( V_7 , V_170 -> V_173 ) ;
}
V_195 &= ~ V_203 ;
F_50 ( V_1 -> V_71 , V_195 & ~ V_240 ) ;
F_84 ( V_1 -> V_71 ) ;
F_49 ( V_1 -> V_228 ) ;
}
static bool
F_150 ( struct V_1 * V_1 )
{
char V_348 [ sizeof( V_1 -> V_23 ) * 3 ] ;
if ( F_127 ( V_1 , 0x000 , V_1 -> V_23 ,
sizeof( V_1 -> V_23 ) ) == 0 )
return false ;
F_151 ( V_1 -> V_23 , sizeof( V_1 -> V_23 ) ,
32 , 1 , V_348 , sizeof( V_348 ) , false ) ;
F_29 ( L_57 , V_348 ) ;
if ( V_1 -> V_23 [ V_186 ] == 0 )
return false ;
if ( ! ( V_1 -> V_23 [ V_349 ] &
V_350 ) )
return true ;
if ( V_1 -> V_23 [ V_186 ] == 0x10 )
return true ;
if ( F_127 ( V_1 , V_351 ,
V_1 -> V_352 ,
V_353 ) == 0 )
return false ;
return true ;
}
static void
F_152 ( struct V_1 * V_1 )
{
T_5 V_354 [ 3 ] ;
if ( ! ( V_1 -> V_23 [ V_355 ] & V_356 ) )
return;
F_58 ( V_1 ) ;
if ( F_127 ( V_1 , V_357 , V_354 , 3 ) )
F_29 ( L_58 ,
V_354 [ 0 ] , V_354 [ 1 ] , V_354 [ 2 ] ) ;
if ( F_127 ( V_1 , V_358 , V_354 , 3 ) )
F_29 ( L_59 ,
V_354 [ 0 ] , V_354 [ 1 ] , V_354 [ 2 ] ) ;
F_60 ( V_1 , false ) ;
}
static bool
F_153 ( struct V_1 * V_1 , T_5 * V_359 )
{
int V_89 ;
V_89 = F_127 ( V_1 ,
V_360 ,
V_359 , 1 ) ;
if ( ! V_89 )
return false ;
return true ;
}
static void
F_154 ( struct V_1 * V_1 )
{
F_53 ( V_1 , V_361 , V_362 ) ;
}
void
F_155 ( struct V_1 * V_1 )
{
struct V_12 * V_12 = & F_2 ( V_1 ) -> V_4 ;
T_5 V_359 ;
T_5 V_256 [ V_257 ] ;
if ( ! V_12 -> V_363 )
return;
if ( F_97 ( ! V_12 -> V_4 . V_169 ) )
return;
if ( ! F_128 ( V_1 , V_256 ) ) {
F_121 ( V_1 ) ;
return;
}
if ( ! F_150 ( V_1 ) ) {
F_121 ( V_1 ) ;
return;
}
if ( V_1 -> V_23 [ V_186 ] >= 0x11 &&
F_153 ( V_1 , & V_359 ) ) {
F_53 ( V_1 ,
V_360 ,
V_359 ) ;
if ( V_359 & V_364 )
F_154 ( V_1 ) ;
if ( V_359 & ( V_365 | V_366 ) )
F_86 ( L_60 ) ;
}
if ( ! F_147 ( V_256 , V_1 -> V_15 ) ) {
F_29 ( L_61 ,
F_156 ( & V_12 -> V_4 ) ) ;
F_124 ( V_1 ) ;
F_125 ( V_1 ) ;
}
}
static enum V_367
F_157 ( struct V_1 * V_1 )
{
T_2 * V_23 = V_1 -> V_23 ;
bool V_368 ;
T_2 type ;
if ( ! F_150 ( V_1 ) )
return V_369 ;
if ( ! ( V_23 [ V_349 ] & V_350 ) )
return V_370 ;
V_368 = ! ! ( V_1 -> V_352 [ 0 ] & V_371 ) ;
if ( V_368 ) {
T_2 V_372 ;
if ( ! F_127 ( V_1 , V_373 ,
& V_372 , 1 ) )
return V_374 ;
return F_158 ( V_372 ) ? V_370
: V_369 ;
}
if ( F_159 ( & V_1 -> V_129 ) )
return V_370 ;
type = V_1 -> V_352 [ 0 ] & V_375 ;
if ( type == V_376 || type == V_377 )
return V_374 ;
F_29 ( L_62 ) ;
return V_369 ;
}
static enum V_367
F_160 ( struct V_1 * V_1 )
{
struct V_6 * V_7 = F_5 ( V_1 ) ;
struct V_51 * V_52 = V_7 -> V_53 ;
struct V_2 * V_3 = F_2 ( V_1 ) ;
enum V_367 V_72 ;
if ( F_1 ( V_1 ) ) {
V_72 = F_161 ( V_7 ) ;
if ( V_72 == V_374 )
V_72 = V_370 ;
return V_72 ;
}
if ( ! F_162 ( V_52 , V_3 ) )
return V_369 ;
return F_157 ( V_1 ) ;
}
static enum V_367
F_163 ( struct V_1 * V_1 )
{
struct V_6 * V_7 = F_5 ( V_1 ) ;
struct V_51 * V_52 = V_7 -> V_53 ;
struct V_2 * V_3 = F_2 ( V_1 ) ;
T_1 V_378 ;
switch ( V_3 -> V_74 ) {
case V_77 :
V_378 = V_379 ;
break;
case V_79 :
V_378 = V_380 ;
break;
case V_81 :
V_378 = V_381 ;
break;
default:
return V_374 ;
}
if ( ( F_24 ( V_382 ) & V_378 ) == 0 )
return V_369 ;
return F_157 ( V_1 ) ;
}
static struct V_383 *
F_164 ( struct V_8 * V_9 , struct V_128 * V_129 )
{
struct V_18 * V_18 = F_19 ( V_9 ) ;
if ( V_18 -> V_383 ) {
struct V_383 * V_383 ;
int V_384 ;
if ( F_165 ( V_18 -> V_383 ) )
return NULL ;
V_384 = ( V_18 -> V_383 -> V_385 + 1 ) * V_386 ;
V_383 = F_166 ( V_384 , V_387 ) ;
if ( ! V_383 )
return NULL ;
memcpy ( V_383 , V_18 -> V_383 , V_384 ) ;
return V_383 ;
}
return F_167 ( V_9 , V_129 ) ;
}
static int
F_168 ( struct V_8 * V_9 , struct V_128 * V_129 )
{
struct V_18 * V_18 = F_19 ( V_9 ) ;
if ( V_18 -> V_383 ) {
if ( F_165 ( V_18 -> V_383 ) )
return 0 ;
return F_169 ( V_9 ,
V_18 -> V_383 ) ;
}
return F_170 ( V_9 , V_129 ) ;
}
static enum V_367
F_171 ( struct V_8 * V_9 , bool V_388 )
{
struct V_1 * V_1 = F_6 ( V_9 ) ;
struct V_2 * V_3 = F_2 ( V_1 ) ;
struct V_12 * V_12 = & V_3 -> V_4 ;
struct V_6 * V_7 = V_9 -> V_7 ;
enum V_367 V_72 ;
struct V_383 * V_383 = NULL ;
V_1 -> V_202 = false ;
if ( F_45 ( V_7 ) )
V_72 = F_160 ( V_1 ) ;
else
V_72 = F_163 ( V_1 ) ;
if ( V_72 != V_370 )
return V_72 ;
F_152 ( V_1 ) ;
if ( V_1 -> V_389 != V_390 ) {
V_1 -> V_202 = ( V_1 -> V_389 == V_391 ) ;
} else {
V_383 = F_164 ( V_9 , & V_1 -> V_129 ) ;
if ( V_383 ) {
V_1 -> V_202 = F_172 ( V_383 ) ;
F_173 ( V_383 ) ;
}
}
if ( V_12 -> type != V_5 )
V_12 -> type = V_177 ;
return V_370 ;
}
static int F_174 ( struct V_8 * V_9 )
{
struct V_1 * V_1 = F_6 ( V_9 ) ;
struct V_18 * V_18 = F_19 ( V_9 ) ;
struct V_6 * V_7 = V_9 -> V_7 ;
int V_89 ;
V_89 = F_168 ( V_9 , & V_1 -> V_129 ) ;
if ( V_89 )
return V_89 ;
if ( F_1 ( V_1 ) && V_18 -> V_20 . V_21 ) {
struct V_16 * V_17 ;
V_17 = F_175 ( V_7 ,
V_18 -> V_20 . V_21 ) ;
if ( V_17 ) {
F_176 ( V_9 , V_17 ) ;
return 1 ;
}
}
return 0 ;
}
static bool
F_177 ( struct V_8 * V_9 )
{
struct V_1 * V_1 = F_6 ( V_9 ) ;
struct V_383 * V_383 ;
bool V_202 = false ;
V_383 = F_164 ( V_9 , & V_1 -> V_129 ) ;
if ( V_383 ) {
V_202 = F_172 ( V_383 ) ;
F_173 ( V_383 ) ;
}
return V_202 ;
}
static int
F_178 ( struct V_8 * V_9 ,
struct V_392 * V_393 ,
T_6 V_394 )
{
struct V_51 * V_52 = V_9 -> V_7 -> V_53 ;
struct V_18 * V_18 = F_19 ( V_9 ) ;
struct V_12 * V_12 = F_8 ( V_9 ) ;
struct V_1 * V_1 = F_7 ( & V_12 -> V_4 ) ;
int V_89 ;
V_89 = F_179 ( & V_9 -> V_4 , V_393 , V_394 ) ;
if ( V_89 )
return V_89 ;
if ( V_393 == V_52 -> V_395 ) {
int V_47 = V_394 ;
bool V_202 ;
if ( V_47 == V_1 -> V_389 )
return 0 ;
V_1 -> V_389 = V_47 ;
if ( V_47 == V_390 )
V_202 = F_177 ( V_9 ) ;
else
V_202 = ( V_47 == V_391 ) ;
if ( V_202 == V_1 -> V_202 )
return 0 ;
V_1 -> V_202 = V_202 ;
goto V_73;
}
if ( V_393 == V_52 -> V_396 ) {
switch ( V_394 ) {
case V_397 :
V_1 -> V_162 = true ;
break;
case V_398 :
V_1 -> V_162 = false ;
V_1 -> V_163 = 0 ;
break;
case V_399 :
V_1 -> V_162 = false ;
V_1 -> V_163 = V_164 ;
break;
default:
return - V_400 ;
}
goto V_73;
}
if ( F_1 ( V_1 ) &&
V_393 == V_9 -> V_7 -> V_226 . V_401 ) {
if ( V_394 == V_402 ) {
F_29 ( L_63 ) ;
return - V_400 ;
}
if ( V_18 -> V_20 . V_161 == V_394 ) {
return 0 ;
}
V_18 -> V_20 . V_161 = V_394 ;
goto V_73;
}
return - V_400 ;
V_73:
if ( V_12 -> V_4 . V_169 )
F_180 ( V_12 -> V_4 . V_169 ) ;
return 0 ;
}
static void
F_181 ( struct V_8 * V_9 )
{
struct V_6 * V_7 = V_9 -> V_7 ;
struct V_1 * V_1 = F_6 ( V_9 ) ;
struct V_18 * V_18 = F_19 ( V_9 ) ;
if ( ! F_182 ( V_18 -> V_383 ) )
F_173 ( V_18 -> V_383 ) ;
if ( F_1 ( V_1 ) ) {
F_183 ( V_7 ) ;
F_184 ( & V_18 -> V_20 ) ;
}
F_185 ( V_9 ) ;
F_186 ( V_9 ) ;
F_173 ( V_9 ) ;
}
void F_187 ( struct V_10 * V_11 )
{
struct V_2 * V_3 = F_188 ( V_11 ) ;
struct V_1 * V_1 = & V_3 -> V_403 ;
struct V_6 * V_7 = F_5 ( V_1 ) ;
F_189 ( & V_1 -> V_129 ) ;
F_190 ( V_11 ) ;
if ( F_1 ( V_1 ) ) {
F_191 ( & V_1 -> V_231 ) ;
F_101 ( & V_7 -> V_226 . V_227 ) ;
F_96 ( V_1 ) ;
F_102 ( & V_7 -> V_226 . V_227 ) ;
}
F_173 ( V_3 ) ;
}
static void
F_192 ( struct V_12 * V_12 )
{
struct V_1 * V_1 = F_7 ( & V_12 -> V_4 ) ;
F_155 ( V_1 ) ;
}
int
F_193 ( struct V_168 * V_169 )
{
struct V_6 * V_7 = V_169 -> V_7 ;
struct V_12 * V_12 ;
struct V_1 * V_1 ;
F_67 (dev, crtc, intel_encoder) {
V_1 = F_7 ( & V_12 -> V_4 ) ;
if ( V_12 -> type == V_177 ||
V_12 -> type == V_5 )
return V_1 -> V_71 ;
}
return - 1 ;
}
bool F_194 ( struct V_6 * V_7 )
{
struct V_51 * V_52 = V_7 -> V_53 ;
struct V_404 * V_405 ;
int V_47 ;
if ( ! V_52 -> V_406 )
return false ;
for ( V_47 = 0 ; V_47 < V_52 -> V_406 ; V_47 ++ ) {
V_405 = V_52 -> V_407 + V_47 ;
if ( V_405 -> V_408 == V_409 &&
V_405 -> V_410 == V_411 )
return true ;
}
return false ;
}
static void
F_195 ( struct V_1 * V_1 , struct V_8 * V_9 )
{
struct V_18 * V_18 = F_19 ( V_9 ) ;
F_196 ( V_9 ) ;
F_197 ( V_9 ) ;
V_1 -> V_162 = true ;
if ( F_1 ( V_1 ) ) {
F_198 ( V_9 -> V_7 ) ;
F_199 (
& V_9 -> V_4 ,
V_9 -> V_7 -> V_226 . V_401 ,
V_412 ) ;
V_18 -> V_20 . V_161 = V_412 ;
}
}
static void
F_200 ( struct V_6 * V_7 ,
struct V_1 * V_1 ,
struct V_413 * V_102 )
{
struct V_51 * V_52 = V_7 -> V_53 ;
struct V_413 V_414 , V_415 , V_416 , V_417 ;
T_4 V_418 , V_419 , V_420 , V_223 ;
V_223 = F_95 ( V_52 ) ;
F_50 ( V_67 , V_223 ) ;
V_418 = F_24 ( V_421 ) ;
V_419 = F_24 ( V_422 ) ;
V_420 = F_24 ( V_423 ) ;
V_414 . V_424 = ( V_418 & V_425 ) >>
V_426 ;
V_414 . V_427 = ( V_418 & V_428 ) >>
V_429 ;
V_414 . V_430 = ( V_419 & V_431 ) >>
V_432 ;
V_414 . V_433 = ( V_419 & V_434 ) >>
V_435 ;
V_414 . V_436 = ( ( V_420 & V_437 ) >>
V_438 ) * 1000 ;
F_29 ( L_64 ,
V_414 . V_424 , V_414 . V_427 , V_414 . V_430 , V_414 . V_433 , V_414 . V_436 ) ;
V_415 = V_52 -> V_439 . V_440 ;
V_416 . V_424 = 210 * 10 ;
V_416 . V_427 = 50 * 10 ;
V_416 . V_430 = 50 * 10 ;
V_416 . V_433 = 500 * 10 ;
V_416 . V_436 = ( 510 + 100 ) * 10 ;
F_29 ( L_65 ,
V_415 . V_424 , V_415 . V_427 , V_415 . V_430 , V_415 . V_433 , V_415 . V_436 ) ;
#define F_201 ( T_7 ) final.field = (max(cur.field, vbt.field) == 0 ? \
spec.field : \
max(cur.field, vbt.field))
F_201 ( V_424 ) ;
F_201 ( V_427 ) ;
F_201 ( V_430 ) ;
F_201 ( V_433 ) ;
F_201 ( V_436 ) ;
#undef F_201
#define F_202 ( T_7 ) (DIV_ROUND_UP(final.field, 10))
V_1 -> V_225 = F_202 ( V_424 ) ;
V_1 -> V_237 = F_202 ( V_427 ) ;
V_1 -> V_238 = F_202 ( V_430 ) ;
V_1 -> V_228 = F_202 ( V_433 ) ;
V_1 -> V_233 = F_202 ( V_436 ) ;
#undef F_202
F_29 ( L_66 ,
V_1 -> V_225 , V_1 -> V_228 ,
V_1 -> V_233 ) ;
F_29 ( L_67 ,
V_1 -> V_237 , V_1 -> V_238 ) ;
if ( V_102 )
* V_102 = V_417 ;
}
static void
F_203 ( struct V_6 * V_7 ,
struct V_1 * V_1 ,
struct V_413 * V_441 )
{
struct V_51 * V_52 = V_7 -> V_53 ;
T_4 V_418 , V_419 , V_420 ;
V_418 = ( V_441 -> V_424 << V_426 ) |
( V_441 -> V_427 << V_429 ) ;
V_419 = ( V_441 -> V_430 << V_432 ) |
( V_441 -> V_433 << V_435 ) ;
V_420 = ( ( 100 * F_47 ( V_7 ) ) / 2 - 1 )
<< V_442 ;
V_420 |= ( F_46 ( V_441 -> V_436 , 1000 )
<< V_438 ) ;
if ( F_149 ( V_7 ) || F_89 ( V_7 ) ) {
if ( F_4 ( V_1 ) )
V_418 |= V_443 ;
else
V_418 |= V_444 ;
}
F_50 ( V_421 , V_418 ) ;
F_50 ( V_422 , V_419 ) ;
F_50 ( V_423 , V_420 ) ;
F_29 ( L_68 ,
F_24 ( V_421 ) ,
F_24 ( V_422 ) ,
F_24 ( V_423 ) ) ;
}
void
F_204 ( struct V_2 * V_3 ,
struct V_18 * V_18 )
{
struct V_8 * V_9 = & V_18 -> V_4 ;
struct V_1 * V_1 = & V_3 -> V_403 ;
struct V_12 * V_12 = & V_3 -> V_4 ;
struct V_6 * V_7 = V_12 -> V_4 . V_7 ;
struct V_51 * V_52 = V_7 -> V_53 ;
struct V_16 * V_21 = NULL ;
struct V_413 V_445 = { 0 } ;
enum V_74 V_74 = V_3 -> V_74 ;
const char * V_147 = NULL ;
int type ;
V_1 -> V_195 = F_24 ( V_1 -> V_71 ) ;
V_1 -> V_19 = V_18 ;
if ( F_45 ( V_7 ) && V_74 == V_81 )
if ( F_194 ( V_7 ) )
V_1 -> F_3 = true ;
if ( F_23 ( V_7 ) && V_74 == V_79 ) {
type = V_446 ;
V_12 -> type = V_5 ;
} else if ( V_74 == V_75 || F_3 ( V_1 ) ) {
type = V_446 ;
V_12 -> type = V_5 ;
} else {
type = V_447 ;
}
F_205 ( V_7 , V_9 , & V_448 , type ) ;
F_206 ( V_9 , & V_449 ) ;
V_9 -> V_450 = V_451 ;
V_9 -> V_452 = true ;
V_9 -> V_453 = 0 ;
F_207 ( & V_1 -> V_231 ,
F_99 ) ;
F_208 ( V_18 , V_12 ) ;
F_209 ( V_9 ) ;
if ( F_41 ( V_7 ) )
V_18 -> V_454 = V_455 ;
else
V_18 -> V_454 = V_456 ;
switch ( V_74 ) {
case V_75 :
V_147 = L_69 ;
break;
case V_77 :
V_52 -> V_457 |= V_458 ;
V_147 = L_70 ;
break;
case V_79 :
V_52 -> V_457 |= V_459 ;
V_147 = L_71 ;
break;
case V_81 :
V_52 -> V_457 |= V_460 ;
V_147 = L_72 ;
break;
default:
F_28 ( 1 , L_73 , F_210 ( V_74 ) ) ;
break;
}
if ( F_1 ( V_1 ) )
F_200 ( V_7 , V_1 , & V_445 ) ;
F_57 ( V_1 , V_18 , V_147 ) ;
if ( F_1 ( V_1 ) ) {
bool V_89 ;
struct V_16 * V_461 ;
struct V_383 * V_383 ;
F_58 ( V_1 ) ;
V_89 = F_150 ( V_1 ) ;
F_60 ( V_1 , false ) ;
if ( V_89 ) {
if ( V_1 -> V_23 [ V_186 ] >= 0x11 )
V_52 -> V_462 =
V_1 -> V_23 [ V_463 ] &
V_464 ;
} else {
F_211 ( L_74 ) ;
F_187 ( & V_12 -> V_4 ) ;
F_181 ( V_9 ) ;
return;
}
F_203 ( V_7 , V_1 ,
& V_445 ) ;
F_58 ( V_1 ) ;
V_383 = F_167 ( V_9 , & V_1 -> V_129 ) ;
if ( V_383 ) {
if ( F_212 ( V_9 , V_383 ) ) {
F_213 ( V_9 , V_383 ) ;
F_214 ( V_9 , V_383 ) ;
} else {
F_173 ( V_383 ) ;
V_383 = F_215 ( - V_400 ) ;
}
} else {
V_383 = F_215 ( - V_465 ) ;
}
V_18 -> V_383 = V_383 ;
F_216 (scan, &connector->probed_modes, head) {
if ( ( V_461 -> type & V_466 ) ) {
V_21 = F_175 ( V_7 , V_461 ) ;
break;
}
}
if ( ! V_21 && V_52 -> V_467 ) {
V_21 = F_175 ( V_7 , V_52 -> V_467 ) ;
if ( V_21 )
V_21 -> type |= V_466 ;
}
F_60 ( V_1 , false ) ;
}
if ( F_1 ( V_1 ) ) {
F_217 ( & V_18 -> V_20 , V_21 ) ;
F_218 ( V_9 ) ;
}
F_195 ( V_1 , V_9 ) ;
if ( F_219 ( V_7 ) && ! F_220 ( V_7 ) ) {
T_4 V_315 = F_24 ( V_468 ) ;
F_50 ( V_468 , ( V_315 & ~ 0xf ) | 0xd ) ;
}
}
void
F_221 ( struct V_6 * V_7 , int V_71 , enum V_74 V_74 )
{
struct V_2 * V_3 ;
struct V_12 * V_12 ;
struct V_10 * V_11 ;
struct V_18 * V_18 ;
V_3 = F_222 ( sizeof( struct V_2 ) , V_387 ) ;
if ( ! V_3 )
return;
V_18 = F_222 ( sizeof( struct V_18 ) , V_387 ) ;
if ( ! V_18 ) {
F_173 ( V_3 ) ;
return;
}
V_12 = & V_3 -> V_4 ;
V_11 = & V_12 -> V_4 ;
F_223 ( V_7 , & V_12 -> V_4 , & V_469 ,
V_470 ) ;
F_224 ( & V_12 -> V_4 , & V_471 ) ;
V_12 -> V_472 = F_123 ;
V_12 -> V_473 = F_126 ;
V_12 -> V_474 = F_120 ;
V_12 -> V_475 = F_122 ;
V_12 -> V_454 = F_115 ;
V_3 -> V_74 = V_74 ;
V_3 -> V_403 . V_71 = V_71 ;
V_12 -> type = V_177 ;
V_12 -> V_476 = ( 1 << 0 ) | ( 1 << 1 ) | ( 1 << 2 ) ;
V_12 -> V_477 = false ;
V_12 -> V_478 = F_192 ;
F_204 ( V_3 , V_18 ) ;
}
