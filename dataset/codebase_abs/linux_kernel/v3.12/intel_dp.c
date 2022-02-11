static bool F_1 ( struct V_1 * V_1 )
{
struct V_2 * V_3 = F_2 ( V_1 ) ;
return V_3 -> V_4 . type == V_5 ;
}
static struct V_6 * F_3 ( struct V_1 * V_1 )
{
struct V_2 * V_3 = F_2 ( V_1 ) ;
return V_3 -> V_4 . V_4 . V_7 ;
}
static struct V_1 * F_4 ( struct V_8 * V_9 )
{
return F_5 ( & F_6 ( V_9 ) -> V_4 ) ;
}
static int
F_7 ( struct V_1 * V_1 )
{
int V_10 = V_1 -> V_11 [ V_12 ] ;
switch ( V_10 ) {
case V_13 :
case V_14 :
break;
case V_15 :
V_10 = V_14 ;
break;
default:
F_8 ( 1 , L_1 ,
V_10 ) ;
V_10 = V_13 ;
break;
}
return V_10 ;
}
static int
F_9 ( int V_16 , int V_17 )
{
return ( V_16 * V_17 + 9 ) / 10 ;
}
static int
F_10 ( int V_18 , int V_19 )
{
return ( V_18 * V_19 * 8 ) / 10 ;
}
static int
F_11 ( struct V_8 * V_9 ,
struct V_20 * V_21 )
{
struct V_1 * V_1 = F_4 ( V_9 ) ;
struct V_22 * V_22 = F_12 ( V_9 ) ;
struct V_20 * V_23 = V_22 -> V_24 . V_23 ;
int V_25 = V_21 -> clock ;
int V_26 , V_27 , V_19 , V_18 ;
if ( F_1 ( V_1 ) && V_23 ) {
if ( V_21 -> V_28 > V_23 -> V_28 )
return V_29 ;
if ( V_21 -> V_30 > V_23 -> V_30 )
return V_29 ;
V_25 = V_23 -> clock ;
}
V_18 = F_13 ( F_7 ( V_1 ) ) ;
V_19 = F_14 ( V_1 -> V_11 ) ;
V_26 = F_10 ( V_18 , V_19 ) ;
V_27 = F_9 ( V_25 , 18 ) ;
if ( V_27 > V_26 )
return V_31 ;
if ( V_21 -> clock < 10000 )
return V_32 ;
if ( V_21 -> V_33 & V_34 )
return V_35 ;
return V_36 ;
}
static T_1
F_15 ( T_2 * V_37 , int V_38 )
{
int V_39 ;
T_1 V_40 = 0 ;
if ( V_38 > 4 )
V_38 = 4 ;
for ( V_39 = 0 ; V_39 < V_38 ; V_39 ++ )
V_40 |= ( ( T_1 ) V_37 [ V_39 ] ) << ( ( 3 - V_39 ) * 8 ) ;
return V_40 ;
}
static void
F_16 ( T_1 V_37 , T_2 * V_41 , int V_42 )
{
int V_39 ;
if ( V_42 > 4 )
V_42 = 4 ;
for ( V_39 = 0 ; V_39 < V_42 ; V_39 ++ )
V_41 [ V_39 ] = V_37 >> ( ( 3 - V_39 ) * 8 ) ;
}
static int
F_17 ( struct V_6 * V_7 )
{
struct V_43 * V_44 = V_7 -> V_45 ;
T_1 V_46 ;
if ( F_18 ( V_7 ) )
return 200 ;
V_46 = F_19 ( V_47 ) ;
switch ( V_46 & V_48 ) {
case V_49 :
return 100 ;
case V_50 :
return 133 ;
case V_51 :
return 166 ;
case V_52 :
return 200 ;
case V_53 :
return 266 ;
case V_54 :
return 333 ;
case V_55 :
case V_56 :
return 400 ;
default:
return 133 ;
}
}
static bool F_20 ( struct V_1 * V_1 )
{
struct V_6 * V_7 = F_3 ( V_1 ) ;
struct V_43 * V_44 = V_7 -> V_45 ;
T_3 V_57 ;
V_57 = F_18 ( V_7 ) ? V_58 : V_59 ;
return ( F_19 ( V_57 ) & V_60 ) != 0 ;
}
static bool F_21 ( struct V_1 * V_1 )
{
struct V_6 * V_7 = F_3 ( V_1 ) ;
struct V_43 * V_44 = V_7 -> V_45 ;
T_3 V_61 ;
V_61 = F_18 ( V_7 ) ? V_62 : V_63 ;
return ( F_19 ( V_61 ) & V_64 ) != 0 ;
}
static void
F_22 ( struct V_1 * V_1 )
{
struct V_6 * V_7 = F_3 ( V_1 ) ;
struct V_43 * V_44 = V_7 -> V_45 ;
T_3 V_57 , V_61 ;
if ( ! F_1 ( V_1 ) )
return;
V_57 = F_18 ( V_7 ) ? V_58 : V_59 ;
V_61 = F_18 ( V_7 ) ? V_62 : V_63 ;
if ( ! F_20 ( V_1 ) && ! F_21 ( V_1 ) ) {
F_8 ( 1 , L_2 ) ;
F_23 ( L_3 ,
F_19 ( V_57 ) ,
F_19 ( V_61 ) ) ;
}
}
static T_1
F_24 ( struct V_1 * V_1 , bool V_65 )
{
struct V_2 * V_3 = F_2 ( V_1 ) ;
struct V_6 * V_7 = V_3 -> V_4 . V_4 . V_7 ;
struct V_43 * V_44 = V_7 -> V_45 ;
T_1 V_66 = V_1 -> V_67 ;
T_1 V_68 ;
bool V_69 ;
#define F_25 (((status = I915_READ_NOTRACE(ch_ctl)) & DP_AUX_CH_CTL_SEND_BUSY) == 0)
if ( V_65 )
V_69 = F_26 ( V_44 -> V_70 , F_25 ,
F_27 ( 10 ) ) ;
else
V_69 = F_28 ( F_25 , 10 ) == 0 ;
if ( ! V_69 )
F_29 ( L_4 ,
V_65 ) ;
#undef F_25
return V_68 ;
}
static T_1 F_30 ( struct V_1 * V_1 ,
int V_71 )
{
struct V_2 * V_3 = F_2 ( V_1 ) ;
struct V_6 * V_7 = V_3 -> V_4 . V_4 . V_7 ;
struct V_43 * V_44 = V_7 -> V_45 ;
if ( F_18 ( V_7 ) ) {
return V_71 ? 0 : 100 ;
} else if ( V_3 -> V_72 == V_73 ) {
if ( V_71 )
return 0 ;
if ( F_31 ( V_7 ) )
return F_32 ( F_33 ( V_44 ) , 2000 ) ;
else if ( F_34 ( V_7 ) || F_35 ( V_7 ) )
return 200 ;
else
return 225 ;
} else if ( V_44 -> V_74 == V_75 ) {
switch ( V_71 ) {
case 0 : return 63 ;
case 1 : return 72 ;
default: return 0 ;
}
} else if ( F_36 ( V_7 ) ) {
return V_71 ? 0 : F_37 ( F_38 ( V_7 ) , 2 ) ;
} else {
return V_71 ? 0 : F_17 ( V_7 ) / 2 ;
}
}
static int
F_39 ( struct V_1 * V_1 ,
T_2 * V_76 , int V_77 ,
T_2 * V_78 , int V_79 )
{
struct V_2 * V_3 = F_2 ( V_1 ) ;
struct V_6 * V_7 = V_3 -> V_4 . V_4 . V_7 ;
struct V_43 * V_44 = V_7 -> V_45 ;
T_1 V_66 = V_1 -> V_67 ;
T_1 V_80 = V_66 + 4 ;
T_1 V_81 ;
int V_39 , V_82 , V_83 ;
T_1 V_68 ;
int V_84 , V_85 , clock = 0 ;
bool V_65 = F_40 ( V_7 ) -> V_86 >= 5 && ! F_18 ( V_7 ) ;
F_41 ( & V_44 -> V_87 , 0 ) ;
F_22 ( V_1 ) ;
if ( F_34 ( V_7 ) )
V_85 = 3 ;
else
V_85 = 5 ;
F_42 ( V_44 ) ;
for ( V_84 = 0 ; V_84 < 3 ; V_84 ++ ) {
V_68 = F_43 ( V_66 ) ;
if ( ( V_68 & V_88 ) == 0 )
break;
F_44 ( 1 ) ;
}
if ( V_84 == 3 ) {
F_8 ( 1 , L_5 ,
F_19 ( V_66 ) ) ;
V_82 = - V_89 ;
goto V_90;
}
while ( ( V_81 = F_30 ( V_1 , clock ++ ) ) ) {
for ( V_84 = 0 ; V_84 < 5 ; V_84 ++ ) {
for ( V_39 = 0 ; V_39 < V_77 ; V_39 += 4 )
F_45 ( V_80 + V_39 ,
F_15 ( V_76 + V_39 , V_77 - V_39 ) ) ;
F_45 ( V_66 ,
V_88 |
( V_65 ? V_91 : 0 ) |
V_92 |
( V_77 << V_93 ) |
( V_85 << V_94 ) |
( V_81 << V_95 ) |
V_96 |
V_97 |
V_98 ) ;
V_68 = F_24 ( V_1 , V_65 ) ;
F_45 ( V_66 ,
V_68 |
V_96 |
V_97 |
V_98 ) ;
if ( V_68 & ( V_97 |
V_98 ) )
continue;
if ( V_68 & V_96 )
break;
}
if ( V_68 & V_96 )
break;
}
if ( ( V_68 & V_96 ) == 0 ) {
F_29 ( L_6 , V_68 ) ;
V_82 = - V_89 ;
goto V_90;
}
if ( V_68 & V_98 ) {
F_29 ( L_7 , V_68 ) ;
V_82 = - V_99 ;
goto V_90;
}
if ( V_68 & V_97 ) {
F_23 ( L_8 , V_68 ) ;
V_82 = - V_100 ;
goto V_90;
}
V_83 = ( ( V_68 & V_101 ) >>
V_93 ) ;
if ( V_83 > V_79 )
V_83 = V_79 ;
for ( V_39 = 0 ; V_39 < V_83 ; V_39 += 4 )
F_16 ( F_19 ( V_80 + V_39 ) ,
V_78 + V_39 , V_83 - V_39 ) ;
V_82 = V_83 ;
V_90:
F_41 ( & V_44 -> V_87 , V_102 ) ;
F_46 ( V_44 ) ;
return V_82 ;
}
static int
F_47 ( struct V_1 * V_1 ,
T_4 V_103 , T_2 * V_76 , int V_77 )
{
int V_82 ;
T_2 V_104 [ 20 ] ;
int V_105 ;
T_2 V_106 ;
F_22 ( V_1 ) ;
if ( V_77 > 16 )
return - 1 ;
V_104 [ 0 ] = V_107 << 4 ;
V_104 [ 1 ] = V_103 >> 8 ;
V_104 [ 2 ] = V_103 & 0xff ;
V_104 [ 3 ] = V_77 - 1 ;
memcpy ( & V_104 [ 4 ] , V_76 , V_77 ) ;
V_105 = V_77 + 4 ;
for (; ; ) {
V_82 = F_39 ( V_1 , V_104 , V_105 , & V_106 , 1 ) ;
if ( V_82 < 0 )
return V_82 ;
if ( ( V_106 & V_108 ) == V_109 )
break;
else if ( ( V_106 & V_108 ) == V_110 )
F_48 ( 100 ) ;
else
return - V_99 ;
}
return V_77 ;
}
static int
F_49 ( struct V_1 * V_1 ,
T_4 V_103 , T_2 V_111 )
{
return F_47 ( V_1 , V_103 , & V_111 , 1 ) ;
}
static int
F_50 ( struct V_1 * V_1 ,
T_4 V_103 , T_2 * V_78 , int V_83 )
{
T_2 V_104 [ 4 ] ;
int V_105 ;
T_2 V_112 [ 20 ] ;
int V_113 ;
T_2 V_106 ;
int V_82 ;
F_22 ( V_1 ) ;
V_104 [ 0 ] = V_114 << 4 ;
V_104 [ 1 ] = V_103 >> 8 ;
V_104 [ 2 ] = V_103 & 0xff ;
V_104 [ 3 ] = V_83 - 1 ;
V_105 = 4 ;
V_113 = V_83 + 1 ;
for (; ; ) {
V_82 = F_39 ( V_1 , V_104 , V_105 ,
V_112 , V_113 ) ;
if ( V_82 == 0 )
return - V_115 ;
if ( V_82 < 0 )
return V_82 ;
V_106 = V_112 [ 0 ] ;
if ( ( V_106 & V_108 ) == V_109 ) {
memcpy ( V_78 , V_112 + 1 , V_82 - 1 ) ;
return V_82 - 1 ;
}
else if ( ( V_106 & V_108 ) == V_110 )
F_48 ( 100 ) ;
else
return - V_99 ;
}
}
static int
F_51 ( struct V_116 * V_117 , int V_21 ,
T_2 V_118 , T_2 * V_119 )
{
struct V_120 * V_121 = V_117 -> V_121 ;
struct V_1 * V_1 = F_52 ( V_117 ,
struct V_1 ,
V_117 ) ;
T_4 V_103 = V_121 -> V_103 ;
T_2 V_104 [ 5 ] ;
T_2 V_112 [ 2 ] ;
unsigned V_122 ;
int V_105 ;
int V_113 ;
int V_82 ;
F_22 ( V_1 ) ;
if ( V_21 & V_123 )
V_104 [ 0 ] = V_124 << 4 ;
else
V_104 [ 0 ] = V_125 << 4 ;
if ( ! ( V_21 & V_126 ) )
V_104 [ 0 ] |= V_127 << 4 ;
V_104 [ 1 ] = V_103 >> 8 ;
V_104 [ 2 ] = V_103 ;
switch ( V_21 ) {
case V_128 :
V_104 [ 3 ] = 0 ;
V_104 [ 4 ] = V_118 ;
V_105 = 5 ;
V_113 = 1 ;
break;
case V_123 :
V_104 [ 3 ] = 0 ;
V_105 = 4 ;
V_113 = 2 ;
break;
default:
V_105 = 3 ;
V_113 = 1 ;
break;
}
for ( V_122 = 0 ; V_122 < 5 ; V_122 ++ ) {
V_82 = F_39 ( V_1 ,
V_104 , V_105 ,
V_112 , V_113 ) ;
if ( V_82 < 0 ) {
F_23 ( L_9 , V_82 ) ;
return V_82 ;
}
switch ( V_112 [ 0 ] & V_108 ) {
case V_109 :
break;
case V_129 :
F_23 ( L_10 ) ;
return - V_130 ;
case V_110 :
if ( V_1 -> V_11 [ V_131 ] &
V_132 )
F_53 ( 500 , 600 ) ;
else
F_53 ( 300 , 400 ) ;
continue;
default:
F_29 ( L_11 ,
V_112 [ 0 ] ) ;
return - V_130 ;
}
switch ( V_112 [ 0 ] & V_133 ) {
case V_134 :
if ( V_21 == V_123 ) {
* V_119 = V_112 [ 1 ] ;
}
return V_113 - 1 ;
case V_135 :
F_23 ( L_12 ) ;
return - V_130 ;
case V_136 :
F_23 ( L_13 ) ;
F_48 ( 100 ) ;
break;
default:
F_29 ( L_14 , V_112 [ 0 ] ) ;
return - V_130 ;
}
}
F_29 ( L_15 ) ;
return - V_130 ;
}
static int
F_54 ( struct V_1 * V_1 ,
struct V_22 * V_22 , const char * V_137 )
{
int V_82 ;
F_23 ( L_16 , V_137 ) ;
V_1 -> V_138 . V_139 = false ;
V_1 -> V_138 . V_103 = 0 ;
V_1 -> V_138 . V_140 = F_51 ;
memset ( & V_1 -> V_117 , '\0' , sizeof( V_1 -> V_117 ) ) ;
V_1 -> V_117 . V_141 = V_142 ;
V_1 -> V_117 . V_143 = V_144 ;
strncpy ( V_1 -> V_117 . V_137 , V_137 , sizeof( V_1 -> V_117 . V_137 ) - 1 ) ;
V_1 -> V_117 . V_137 [ sizeof( V_1 -> V_117 . V_137 ) - 1 ] = '\0' ;
V_1 -> V_117 . V_121 = & V_1 -> V_138 ;
V_1 -> V_117 . V_7 . V_145 = & V_22 -> V_4 . V_146 ;
F_55 ( V_1 ) ;
V_82 = F_56 ( & V_1 -> V_117 ) ;
F_57 ( V_1 , false ) ;
return V_82 ;
}
static void
F_58 ( struct V_147 * V_148 ,
struct V_149 * V_150 , int V_151 )
{
struct V_6 * V_7 = V_148 -> V_4 . V_7 ;
if ( F_59 ( V_7 ) ) {
if ( V_151 == V_13 ) {
V_150 -> V_152 . V_153 = 2 ;
V_150 -> V_152 . V_154 = 10 ;
V_150 -> V_152 . V_155 = 2 ;
V_150 -> V_152 . V_156 = 23 ;
V_150 -> V_152 . V_157 = 8 ;
} else {
V_150 -> V_152 . V_153 = 1 ;
V_150 -> V_152 . V_154 = 10 ;
V_150 -> V_152 . V_155 = 1 ;
V_150 -> V_152 . V_156 = 14 ;
V_150 -> V_152 . V_157 = 2 ;
}
V_150 -> V_158 = true ;
} else if ( F_60 ( V_7 ) ) {
} else if ( F_36 ( V_7 ) ) {
if ( V_151 == V_13 ) {
V_150 -> V_152 . V_155 = 1 ;
V_150 -> V_152 . V_153 = 2 ;
V_150 -> V_152 . V_154 = 10 ;
V_150 -> V_152 . V_156 = 12 ;
V_150 -> V_152 . V_157 = 9 ;
} else {
V_150 -> V_152 . V_155 = 2 ;
V_150 -> V_152 . V_153 = 1 ;
V_150 -> V_152 . V_154 = 10 ;
V_150 -> V_152 . V_156 = 14 ;
V_150 -> V_152 . V_157 = 8 ;
}
V_150 -> V_158 = true ;
} else if ( F_18 ( V_7 ) ) {
}
}
bool
F_61 ( struct V_147 * V_148 ,
struct V_149 * V_150 )
{
struct V_6 * V_7 = V_148 -> V_4 . V_7 ;
struct V_43 * V_44 = V_7 -> V_45 ;
struct V_20 * V_159 = & V_150 -> V_159 ;
struct V_1 * V_1 = F_5 ( & V_148 -> V_4 ) ;
enum V_72 V_72 = F_2 ( V_1 ) -> V_72 ;
struct V_160 * V_160 = V_148 -> V_161 ;
struct V_22 * V_22 = V_1 -> V_162 ;
int V_163 , clock ;
int V_164 = F_14 ( V_1 -> V_11 ) ;
int V_165 = F_7 ( V_1 ) == V_14 ? 1 : 0 ;
int V_17 , V_27 ;
static int V_166 [ 2 ] = { V_13 , V_14 } ;
int V_167 , V_168 ;
if ( F_36 ( V_7 ) && ! F_31 ( V_7 ) && V_72 != V_73 )
V_150 -> V_169 = true ;
V_150 -> V_170 = true ;
if ( F_1 ( V_1 ) && V_22 -> V_24 . V_23 ) {
F_62 ( V_22 -> V_24 . V_23 ,
V_159 ) ;
if ( ! F_36 ( V_7 ) )
F_63 ( V_160 , V_150 ,
V_22 -> V_24 . V_171 ) ;
else
F_64 ( V_160 , V_150 ,
V_22 -> V_24 . V_171 ) ;
}
if ( V_159 -> V_33 & V_34 )
return false ;
F_23 ( L_17
L_18 ,
V_164 , V_166 [ V_165 ] , V_159 -> clock ) ;
V_17 = V_150 -> V_172 ;
if ( F_1 ( V_1 ) && V_44 -> V_173 . V_174 ) {
F_23 ( L_19 ,
V_44 -> V_173 . V_174 ) ;
V_17 = F_65 ( int , V_17 , V_44 -> V_173 . V_174 ) ;
}
for (; V_17 >= 6 * 3 ; V_17 -= 2 * 3 ) {
V_27 = F_9 ( V_159 -> clock , V_17 ) ;
for ( clock = 0 ; clock <= V_165 ; clock ++ ) {
for ( V_163 = 1 ; V_163 <= V_164 ; V_163 <<= 1 ) {
V_168 = F_13 ( V_166 [ clock ] ) ;
V_167 = F_10 ( V_168 ,
V_163 ) ;
if ( V_27 <= V_167 ) {
goto V_175;
}
}
}
}
return false ;
V_175:
if ( V_1 -> V_176 ) {
if ( V_17 != 18 && F_66 ( V_159 ) > 1 )
V_1 -> V_177 = V_178 ;
else
V_1 -> V_177 = 0 ;
}
if ( V_1 -> V_177 )
V_150 -> V_179 = true ;
V_1 -> V_151 = V_166 [ clock ] ;
V_1 -> V_163 = V_163 ;
V_150 -> V_172 = V_17 ;
V_150 -> V_180 = F_13 ( V_1 -> V_151 ) ;
F_23 ( L_20 ,
V_1 -> V_151 , V_1 -> V_163 ,
V_150 -> V_180 , V_17 ) ;
F_23 ( L_21 ,
V_27 , V_167 ) ;
F_67 ( V_17 , V_163 ,
V_159 -> clock , V_150 -> V_180 ,
& V_150 -> V_181 ) ;
F_58 ( V_148 , V_150 , V_1 -> V_151 ) ;
return true ;
}
void F_68 ( struct V_1 * V_1 )
{
memset ( V_1 -> V_182 , 0 , V_183 ) ;
V_1 -> V_182 [ 0 ] = V_1 -> V_151 ;
V_1 -> V_182 [ 1 ] = V_1 -> V_163 ;
V_1 -> V_182 [ 8 ] = V_184 ;
if ( V_1 -> V_11 [ V_185 ] >= 0x11 &&
( V_1 -> V_11 [ V_186 ] & V_187 ) ) {
V_1 -> V_182 [ 1 ] |= V_188 ;
}
}
static void F_69 ( struct V_1 * V_1 )
{
struct V_2 * V_189 = F_2 ( V_1 ) ;
struct V_160 * V_190 = F_70 ( V_189 -> V_4 . V_4 . V_190 ) ;
struct V_6 * V_7 = V_190 -> V_4 . V_7 ;
struct V_43 * V_44 = V_7 -> V_45 ;
T_3 V_191 ;
F_23 ( L_22 , V_190 -> V_192 . V_180 ) ;
V_191 = F_19 ( V_193 ) ;
V_191 &= ~ V_194 ;
if ( V_190 -> V_192 . V_180 == 162000 ) {
F_23 ( L_23 ) ;
V_191 |= V_195 ;
V_1 -> V_196 |= V_195 ;
} else {
V_191 |= V_197 ;
V_1 -> V_196 |= V_197 ;
}
F_45 ( V_193 , V_191 ) ;
F_71 ( V_193 ) ;
F_48 ( 500 ) ;
}
static void F_72 ( struct V_147 * V_148 )
{
struct V_6 * V_7 = V_148 -> V_4 . V_7 ;
struct V_43 * V_44 = V_7 -> V_45 ;
struct V_1 * V_1 = F_5 ( & V_148 -> V_4 ) ;
enum V_72 V_72 = F_2 ( V_1 ) -> V_72 ;
struct V_160 * V_190 = F_70 ( V_148 -> V_4 . V_190 ) ;
struct V_20 * V_159 = & V_190 -> V_192 . V_159 ;
V_1 -> V_196 = F_19 ( V_1 -> V_198 ) & V_199 ;
V_1 -> V_196 |= V_200 | V_201 ;
V_1 -> V_196 |= F_73 ( V_1 -> V_163 ) ;
if ( V_1 -> V_202 ) {
F_74 ( L_24 ,
F_75 ( V_190 -> V_203 ) ) ;
V_1 -> V_196 |= V_204 ;
F_76 ( & V_148 -> V_4 , V_159 ) ;
}
F_68 ( V_1 ) ;
if ( V_72 == V_73 && F_35 ( V_7 ) && ! F_18 ( V_7 ) ) {
if ( V_159 -> V_33 & V_205 )
V_1 -> V_196 |= V_206 ;
if ( V_159 -> V_33 & V_207 )
V_1 -> V_196 |= V_208 ;
V_1 -> V_196 |= V_209 ;
if ( V_1 -> V_182 [ 1 ] & V_188 )
V_1 -> V_196 |= V_210 ;
V_1 -> V_196 |= V_190 -> V_203 << 29 ;
} else if ( ! F_77 ( V_7 ) || V_72 == V_73 ) {
if ( ! F_36 ( V_7 ) && ! F_18 ( V_7 ) )
V_1 -> V_196 |= V_1 -> V_177 ;
if ( V_159 -> V_33 & V_205 )
V_1 -> V_196 |= V_206 ;
if ( V_159 -> V_33 & V_207 )
V_1 -> V_196 |= V_208 ;
V_1 -> V_196 |= V_211 ;
if ( V_1 -> V_182 [ 1 ] & V_188 )
V_1 -> V_196 |= V_210 ;
if ( V_190 -> V_203 == 1 )
V_1 -> V_196 |= V_212 ;
} else {
V_1 -> V_196 |= V_209 ;
}
if ( V_72 == V_73 && ! F_18 ( V_7 ) )
F_69 ( V_1 ) ;
}
static void F_78 ( struct V_1 * V_1 ,
T_3 V_213 ,
T_3 V_214 )
{
struct V_6 * V_7 = F_3 ( V_1 ) ;
struct V_43 * V_44 = V_7 -> V_45 ;
T_3 V_57 , V_61 ;
V_57 = F_18 ( V_7 ) ? V_58 : V_59 ;
V_61 = F_18 ( V_7 ) ? V_62 : V_63 ;
F_23 ( L_25 ,
V_213 , V_214 ,
F_19 ( V_57 ) ,
F_19 ( V_61 ) ) ;
if ( F_79 ( ( F_19 ( V_57 ) & V_213 ) == V_214 , 5000 , 10 ) ) {
F_29 ( L_26 ,
F_19 ( V_57 ) ,
F_19 ( V_61 ) ) ;
}
}
static void F_80 ( struct V_1 * V_1 )
{
F_23 ( L_27 ) ;
F_78 ( V_1 , V_215 , V_216 ) ;
}
static void F_81 ( struct V_1 * V_1 )
{
F_23 ( L_28 ) ;
F_78 ( V_1 , V_217 , V_218 ) ;
}
static void F_82 ( struct V_1 * V_1 )
{
F_23 ( L_29 ) ;
F_78 ( V_1 , V_219 , V_220 ) ;
}
static T_3 F_83 ( struct V_1 * V_1 )
{
struct V_6 * V_7 = F_3 ( V_1 ) ;
struct V_43 * V_44 = V_7 -> V_45 ;
T_3 V_221 ;
T_3 V_61 ;
V_61 = F_18 ( V_7 ) ? V_62 : V_63 ;
V_221 = F_19 ( V_61 ) ;
V_221 &= ~ V_222 ;
V_221 |= V_223 ;
return V_221 ;
}
void F_55 ( struct V_1 * V_1 )
{
struct V_6 * V_7 = F_3 ( V_1 ) ;
struct V_43 * V_44 = V_7 -> V_45 ;
T_3 V_224 ;
T_3 V_57 , V_61 ;
if ( ! F_1 ( V_1 ) )
return;
F_23 ( L_30 ) ;
F_8 ( V_1 -> V_225 ,
L_31 ) ;
V_1 -> V_225 = true ;
if ( F_21 ( V_1 ) ) {
F_23 ( L_32 ) ;
return;
}
if ( ! F_20 ( V_1 ) )
F_82 ( V_1 ) ;
V_224 = F_83 ( V_1 ) ;
V_224 |= V_64 ;
V_57 = F_18 ( V_7 ) ? V_58 : V_59 ;
V_61 = F_18 ( V_7 ) ? V_62 : V_63 ;
F_45 ( V_61 , V_224 ) ;
F_71 ( V_61 ) ;
F_23 ( L_33 ,
F_19 ( V_57 ) , F_19 ( V_61 ) ) ;
if ( ! F_20 ( V_1 ) ) {
F_23 ( L_34 ) ;
F_44 ( V_1 -> V_226 ) ;
}
}
static void F_84 ( struct V_1 * V_1 )
{
struct V_6 * V_7 = F_3 ( V_1 ) ;
struct V_43 * V_44 = V_7 -> V_45 ;
T_3 V_224 ;
T_3 V_57 , V_61 ;
F_85 ( ! F_86 ( & V_7 -> V_227 . V_228 ) ) ;
if ( ! V_1 -> V_225 && F_21 ( V_1 ) ) {
V_224 = F_83 ( V_1 ) ;
V_224 &= ~ V_64 ;
V_57 = F_18 ( V_7 ) ? V_58 : V_59 ;
V_61 = F_18 ( V_7 ) ? V_62 : V_63 ;
F_45 ( V_61 , V_224 ) ;
F_71 ( V_61 ) ;
F_23 ( L_33 ,
F_19 ( V_57 ) , F_19 ( V_61 ) ) ;
F_44 ( V_1 -> V_229 ) ;
}
}
static void F_87 ( struct V_230 * V_231 )
{
struct V_1 * V_1 = F_52 ( F_88 ( V_231 ) ,
struct V_1 , V_232 ) ;
struct V_6 * V_7 = F_3 ( V_1 ) ;
F_89 ( & V_7 -> V_227 . V_228 ) ;
F_84 ( V_1 ) ;
F_90 ( & V_7 -> V_227 . V_228 ) ;
}
void F_57 ( struct V_1 * V_1 , bool V_233 )
{
if ( ! F_1 ( V_1 ) )
return;
F_23 ( L_35 , V_1 -> V_225 ) ;
F_8 ( ! V_1 -> V_225 , L_36 ) ;
V_1 -> V_225 = false ;
if ( V_233 ) {
F_84 ( V_1 ) ;
} else {
F_91 ( & V_1 -> V_232 ,
F_92 ( V_1 -> V_234 * 5 ) ) ;
}
}
void F_93 ( struct V_1 * V_1 )
{
struct V_6 * V_7 = F_3 ( V_1 ) ;
struct V_43 * V_44 = V_7 -> V_45 ;
T_3 V_224 ;
T_3 V_61 ;
if ( ! F_1 ( V_1 ) )
return;
F_23 ( L_37 ) ;
if ( F_20 ( V_1 ) ) {
F_23 ( L_38 ) ;
return;
}
F_82 ( V_1 ) ;
V_224 = F_83 ( V_1 ) ;
if ( F_94 ( V_7 ) ) {
V_224 &= ~ V_235 ;
F_45 ( V_63 , V_224 ) ;
F_71 ( V_63 ) ;
}
V_224 |= V_236 ;
if ( ! F_94 ( V_7 ) )
V_224 |= V_235 ;
V_61 = F_18 ( V_7 ) ? V_62 : V_63 ;
F_45 ( V_61 , V_224 ) ;
F_71 ( V_61 ) ;
F_80 ( V_1 ) ;
if ( F_94 ( V_7 ) ) {
V_224 |= V_235 ;
F_45 ( V_63 , V_224 ) ;
F_71 ( V_63 ) ;
}
}
void F_95 ( struct V_1 * V_1 )
{
struct V_6 * V_7 = F_3 ( V_1 ) ;
struct V_43 * V_44 = V_7 -> V_45 ;
T_3 V_224 ;
T_3 V_61 ;
if ( ! F_1 ( V_1 ) )
return;
F_23 ( L_39 ) ;
F_8 ( ! V_1 -> V_225 , L_40 ) ;
V_224 = F_83 ( V_1 ) ;
V_224 &= ~ ( V_236 | V_64 | V_235 | V_237 ) ;
V_61 = F_18 ( V_7 ) ? V_62 : V_63 ;
F_45 ( V_61 , V_224 ) ;
F_71 ( V_61 ) ;
V_1 -> V_225 = false ;
F_81 ( V_1 ) ;
}
void F_96 ( struct V_1 * V_1 )
{
struct V_2 * V_3 = F_2 ( V_1 ) ;
struct V_6 * V_7 = V_3 -> V_4 . V_4 . V_7 ;
struct V_43 * V_44 = V_7 -> V_45 ;
int V_203 = F_70 ( V_3 -> V_4 . V_4 . V_190 ) -> V_203 ;
T_3 V_224 ;
T_3 V_61 ;
if ( ! F_1 ( V_1 ) )
return;
F_23 ( L_41 ) ;
F_44 ( V_1 -> V_238 ) ;
V_224 = F_83 ( V_1 ) ;
V_224 |= V_237 ;
V_61 = F_18 ( V_7 ) ? V_62 : V_63 ;
F_45 ( V_61 , V_224 ) ;
F_71 ( V_61 ) ;
F_97 ( V_7 , V_203 ) ;
}
void F_98 ( struct V_1 * V_1 )
{
struct V_6 * V_7 = F_3 ( V_1 ) ;
struct V_43 * V_44 = V_7 -> V_45 ;
T_3 V_224 ;
T_3 V_61 ;
if ( ! F_1 ( V_1 ) )
return;
F_99 ( V_7 ) ;
F_23 ( L_41 ) ;
V_224 = F_83 ( V_1 ) ;
V_224 &= ~ V_237 ;
V_61 = F_18 ( V_7 ) ? V_62 : V_63 ;
F_45 ( V_61 , V_224 ) ;
F_71 ( V_61 ) ;
F_44 ( V_1 -> V_239 ) ;
}
static void F_100 ( struct V_1 * V_1 )
{
struct V_2 * V_3 = F_2 ( V_1 ) ;
struct V_240 * V_190 = V_3 -> V_4 . V_4 . V_190 ;
struct V_6 * V_7 = V_190 -> V_7 ;
struct V_43 * V_44 = V_7 -> V_45 ;
T_3 V_191 ;
F_101 ( V_44 ,
F_70 ( V_190 ) -> V_203 ) ;
F_23 ( L_41 ) ;
V_191 = F_19 ( V_193 ) ;
F_8 ( V_191 & V_241 , L_42 ) ;
F_8 ( V_191 & V_242 , L_43 ) ;
V_1 -> V_196 &= ~ ( V_242 | V_204 ) ;
V_1 -> V_196 |= V_241 ;
F_45 ( V_193 , V_1 -> V_196 ) ;
F_71 ( V_193 ) ;
F_48 ( 200 ) ;
}
static void F_102 ( struct V_1 * V_1 )
{
struct V_2 * V_3 = F_2 ( V_1 ) ;
struct V_240 * V_190 = V_3 -> V_4 . V_4 . V_190 ;
struct V_6 * V_7 = V_190 -> V_7 ;
struct V_43 * V_44 = V_7 -> V_45 ;
T_3 V_191 ;
F_101 ( V_44 ,
F_70 ( V_190 ) -> V_203 ) ;
V_191 = F_19 ( V_193 ) ;
F_8 ( ( V_191 & V_241 ) == 0 ,
L_44 ) ;
F_8 ( V_191 & V_242 , L_43 ) ;
V_191 &= ~ V_241 ;
F_45 ( V_193 , V_191 ) ;
F_71 ( V_193 ) ;
F_48 ( 200 ) ;
}
void F_103 ( struct V_1 * V_1 , int V_21 )
{
int V_82 , V_39 ;
if ( V_1 -> V_11 [ V_185 ] < 0x11 )
return;
if ( V_21 != V_243 ) {
V_82 = F_49 ( V_1 , V_244 ,
V_245 ) ;
if ( V_82 != 1 )
F_74 ( L_45 ) ;
} else {
for ( V_39 = 0 ; V_39 < 3 ; V_39 ++ ) {
V_82 = F_49 ( V_1 ,
V_244 ,
V_246 ) ;
if ( V_82 == 1 )
break;
F_44 ( 1 ) ;
}
}
}
static bool F_104 ( struct V_147 * V_148 ,
enum V_203 * V_203 )
{
struct V_1 * V_1 = F_5 ( & V_148 -> V_4 ) ;
enum V_72 V_72 = F_2 ( V_1 ) -> V_72 ;
struct V_6 * V_7 = V_148 -> V_4 . V_7 ;
struct V_43 * V_44 = V_7 -> V_45 ;
T_3 V_247 = F_19 ( V_1 -> V_198 ) ;
if ( ! ( V_247 & V_242 ) )
return false ;
if ( V_72 == V_73 && F_35 ( V_7 ) && ! F_18 ( V_7 ) ) {
* V_203 = F_105 ( V_247 ) ;
} else if ( ! F_77 ( V_7 ) || V_72 == V_73 ) {
* V_203 = F_106 ( V_247 ) ;
} else {
T_3 V_248 ;
T_3 V_249 ;
int V_39 ;
switch ( V_1 -> V_198 ) {
case V_250 :
V_248 = V_251 ;
break;
case V_252 :
V_248 = V_253 ;
break;
case V_254 :
V_248 = V_255 ;
break;
default:
return true ;
}
F_107 (i) {
V_249 = F_19 ( F_108 ( V_39 ) ) ;
if ( ( V_249 & V_256 ) == V_248 ) {
* V_203 = V_39 ;
return true ;
}
}
F_23 ( L_46 ,
V_1 -> V_198 ) ;
}
return true ;
}
static void F_109 ( struct V_147 * V_148 ,
struct V_149 * V_150 )
{
struct V_1 * V_1 = F_5 ( & V_148 -> V_4 ) ;
T_3 V_247 , V_33 = 0 ;
struct V_6 * V_7 = V_148 -> V_4 . V_7 ;
struct V_43 * V_44 = V_7 -> V_45 ;
enum V_72 V_72 = F_2 ( V_1 ) -> V_72 ;
struct V_160 * V_190 = F_70 ( V_148 -> V_4 . V_190 ) ;
if ( ( V_72 == V_73 ) || ! F_77 ( V_7 ) ) {
V_247 = F_19 ( V_1 -> V_198 ) ;
if ( V_247 & V_206 )
V_33 |= V_205 ;
else
V_33 |= V_257 ;
if ( V_247 & V_208 )
V_33 |= V_207 ;
else
V_33 |= V_258 ;
} else {
V_247 = F_19 ( F_108 ( V_190 -> V_203 ) ) ;
if ( V_247 & V_259 )
V_33 |= V_205 ;
else
V_33 |= V_257 ;
if ( V_247 & V_260 )
V_33 |= V_207 ;
else
V_33 |= V_258 ;
}
V_150 -> V_159 . V_33 |= V_33 ;
if ( F_2 ( V_1 ) -> V_72 == V_73 ) {
if ( ( F_19 ( V_193 ) & V_194 ) == V_195 )
V_150 -> V_180 = 162000 ;
else
V_150 -> V_180 = 270000 ;
}
if ( F_1 ( V_1 ) && V_44 -> V_173 . V_174 &&
V_150 -> V_172 > V_44 -> V_173 . V_174 ) {
F_23 ( L_47 ,
V_150 -> V_172 , V_44 -> V_173 . V_174 ) ;
V_44 -> V_173 . V_174 = V_150 -> V_172 ;
}
}
static bool F_110 ( struct V_1 * V_1 )
{
return F_1 ( V_1 ) &&
V_1 -> V_261 [ 0 ] & V_262 ;
}
static bool F_111 ( struct V_6 * V_7 )
{
struct V_43 * V_44 = V_7 -> V_45 ;
if ( ! F_60 ( V_7 ) )
return false ;
return F_19 ( V_263 ) & V_264 ;
}
static void F_112 ( struct V_1 * V_1 ,
struct V_265 * V_266 )
{
struct V_2 * V_189 = F_2 ( V_1 ) ;
struct V_6 * V_7 = V_189 -> V_4 . V_4 . V_7 ;
struct V_43 * V_44 = V_7 -> V_45 ;
struct V_160 * V_190 = F_70 ( V_189 -> V_4 . V_4 . V_190 ) ;
T_3 V_267 = F_113 ( V_190 -> V_192 . V_268 ) ;
T_3 V_269 = F_114 ( V_190 -> V_192 . V_268 ) ;
T_1 * V_270 = ( T_1 * ) V_266 ;
unsigned int V_39 ;
F_45 ( V_267 , 0 ) ;
F_71 ( V_267 ) ;
for ( V_39 = 0 ; V_39 < V_271 ; V_39 += 4 ) {
if ( V_39 < sizeof( struct V_265 ) )
F_45 ( V_269 + V_39 , * V_270 ++ ) ;
else
F_45 ( V_269 + V_39 , 0 ) ;
}
F_45 ( V_267 , V_272 ) ;
F_71 ( V_267 ) ;
}
static void F_115 ( struct V_1 * V_1 )
{
struct V_6 * V_7 = F_3 ( V_1 ) ;
struct V_43 * V_44 = V_7 -> V_45 ;
struct V_265 V_273 ;
if ( V_1 -> V_274 )
return;
memset ( & V_273 , 0 , sizeof( V_273 ) ) ;
V_273 . V_275 . V_276 = 0 ;
V_273 . V_275 . V_277 = 0x7 ;
V_273 . V_275 . V_278 = 0x2 ;
V_273 . V_275 . V_279 = 0x8 ;
F_112 ( V_1 , & V_273 ) ;
F_45 ( V_280 , V_281 |
V_282 | V_283 ) ;
V_1 -> V_274 = true ;
}
static void F_116 ( struct V_1 * V_1 )
{
struct V_6 * V_7 = F_3 ( V_1 ) ;
struct V_43 * V_44 = V_7 -> V_45 ;
T_1 V_81 = F_30 ( V_1 , 0 ) ;
int V_85 = 0x3 ;
int V_284 = 5 ;
if ( V_1 -> V_261 [ 1 ] & V_285 )
F_49 ( V_1 , V_286 ,
V_287 &
~ V_288 ) ;
else
F_49 ( V_1 , V_286 ,
V_287 |
V_288 ) ;
F_45 ( V_289 , V_290 ) ;
F_45 ( V_291 , V_292 ) ;
F_45 ( V_293 ,
V_92 |
( V_284 << V_93 ) |
( V_85 << V_94 ) |
( V_81 << V_95 ) ) ;
}
static void F_117 ( struct V_1 * V_1 )
{
struct V_6 * V_7 = F_3 ( V_1 ) ;
struct V_43 * V_44 = V_7 -> V_45 ;
T_1 V_294 = 0x1f ;
T_1 V_295 = 1 ;
T_1 V_296 = 0x0 ;
if ( V_1 -> V_261 [ 1 ] & V_285 ) {
V_296 |= V_297 ;
V_296 |= V_298 ;
V_296 |= V_299 ;
V_296 |= V_300 ;
} else
V_296 |= V_301 ;
F_45 ( V_263 , V_296 |
V_302 |
V_294 << V_303 |
V_295 << V_304 |
V_264 ) ;
}
static bool F_118 ( struct V_1 * V_1 )
{
struct V_2 * V_189 = F_2 ( V_1 ) ;
struct V_6 * V_7 = V_189 -> V_4 . V_4 . V_7 ;
struct V_43 * V_44 = V_7 -> V_45 ;
struct V_240 * V_190 = V_189 -> V_4 . V_4 . V_190 ;
struct V_160 * V_160 = F_70 ( V_190 ) ;
struct V_305 * V_306 = F_119 ( V_190 -> V_307 ) -> V_306 ;
struct V_147 * V_147 = & F_2 ( V_1 ) -> V_4 ;
if ( ! F_60 ( V_7 ) ) {
F_23 ( L_48 ) ;
V_44 -> V_308 = V_309 ;
return false ;
}
if ( ( V_147 -> type != V_5 ) ||
( V_189 -> V_72 != V_73 ) ) {
F_23 ( L_49 ) ;
V_44 -> V_308 = V_310 ;
return false ;
}
if ( ! F_110 ( V_1 ) ) {
F_23 ( L_50 ) ;
V_44 -> V_308 = V_311 ;
return false ;
}
if ( ! V_312 ) {
F_23 ( L_51 ) ;
V_44 -> V_308 = V_313 ;
return false ;
}
V_190 = V_189 -> V_4 . V_4 . V_190 ;
if ( V_190 == NULL ) {
F_23 ( L_52 ) ;
V_44 -> V_308 = V_314 ;
return false ;
}
V_160 = F_70 ( V_190 ) ;
if ( ! V_160 -> V_315 || ! V_190 -> V_307 || ! V_190 -> V_21 . clock ) {
F_23 ( L_52 ) ;
V_44 -> V_308 = V_314 ;
return false ;
}
V_306 = F_119 ( V_190 -> V_307 ) -> V_306 ;
if ( V_306 -> V_316 != V_317 ||
V_306 -> V_318 == V_319 ) {
F_23 ( L_53 ) ;
V_44 -> V_308 = V_320 ;
return false ;
}
if ( F_19 ( F_120 ( V_160 -> V_203 ) ) & V_321 ) {
F_23 ( L_54 ) ;
V_44 -> V_308 = V_322 ;
return false ;
}
if ( F_19 ( F_121 ( V_160 -> V_192 . V_268 ) ) &
V_323 ) {
F_23 ( L_55 ) ;
V_44 -> V_308 = V_324 ;
return false ;
}
if ( V_190 -> V_21 . V_33 & V_325 ) {
F_23 ( L_56 ) ;
V_44 -> V_308 = V_326 ;
return false ;
}
return true ;
}
static void F_122 ( struct V_1 * V_1 )
{
struct V_6 * V_7 = F_3 ( V_1 ) ;
if ( ! F_118 ( V_1 ) ||
F_111 ( V_7 ) )
return;
F_115 ( V_1 ) ;
F_116 ( V_1 ) ;
F_117 ( V_1 ) ;
}
void F_123 ( struct V_1 * V_1 )
{
struct V_6 * V_7 = F_3 ( V_1 ) ;
if ( F_118 ( V_1 ) &&
! F_111 ( V_7 ) )
F_122 ( V_1 ) ;
}
void F_124 ( struct V_1 * V_1 )
{
struct V_6 * V_7 = F_3 ( V_1 ) ;
struct V_43 * V_44 = V_7 -> V_45 ;
if ( ! F_111 ( V_7 ) )
return;
F_45 ( V_263 , F_19 ( V_263 ) & ~ V_264 ) ;
if ( F_79 ( ( F_19 ( V_327 ) &
V_328 ) == 0 , 2000 , 10 ) )
F_29 ( L_57 ) ;
}
void F_125 ( struct V_6 * V_7 )
{
struct V_147 * V_148 ;
struct V_1 * V_1 = NULL ;
F_126 (encoder, &dev->mode_config.encoder_list, base.head)
if ( V_148 -> type == V_5 ) {
V_1 = F_5 ( & V_148 -> V_4 ) ;
if ( ! F_110 ( V_1 ) )
return;
if ( ! F_118 ( V_1 ) )
F_124 ( V_1 ) ;
else
if ( ! F_111 ( V_7 ) )
F_122 ( V_1 ) ;
}
}
static void F_127 ( struct V_147 * V_148 )
{
struct V_1 * V_1 = F_5 ( & V_148 -> V_4 ) ;
enum V_72 V_72 = F_2 ( V_1 ) -> V_72 ;
struct V_6 * V_7 = V_148 -> V_4 . V_7 ;
F_55 ( V_1 ) ;
F_98 ( V_1 ) ;
F_103 ( V_1 , V_243 ) ;
F_95 ( V_1 ) ;
if ( ! ( V_72 == V_73 || F_18 ( V_7 ) ) )
F_128 ( V_1 ) ;
}
static void F_129 ( struct V_147 * V_148 )
{
struct V_1 * V_1 = F_5 ( & V_148 -> V_4 ) ;
enum V_72 V_72 = F_2 ( V_1 ) -> V_72 ;
struct V_6 * V_7 = V_148 -> V_4 . V_7 ;
if ( V_72 == V_73 || F_18 ( V_7 ) ) {
F_128 ( V_1 ) ;
if ( ! F_18 ( V_7 ) )
F_102 ( V_1 ) ;
}
}
static void F_130 ( struct V_147 * V_148 )
{
struct V_1 * V_1 = F_5 ( & V_148 -> V_4 ) ;
struct V_6 * V_7 = V_148 -> V_4 . V_7 ;
struct V_43 * V_44 = V_7 -> V_45 ;
T_1 V_329 = F_19 ( V_1 -> V_198 ) ;
if ( F_85 ( V_329 & V_242 ) )
return;
F_55 ( V_1 ) ;
F_103 ( V_1 , V_243 ) ;
F_131 ( V_1 ) ;
F_93 ( V_1 ) ;
F_57 ( V_1 , true ) ;
F_132 ( V_1 ) ;
F_133 ( V_1 ) ;
F_96 ( V_1 ) ;
}
static void F_134 ( struct V_147 * V_148 )
{
}
static void F_135 ( struct V_147 * V_148 )
{
struct V_1 * V_1 = F_5 ( & V_148 -> V_4 ) ;
struct V_2 * V_330 = F_2 ( V_1 ) ;
if ( V_330 -> V_72 == V_73 )
F_100 ( V_1 ) ;
}
static void F_136 ( struct V_147 * V_148 )
{
struct V_1 * V_1 = F_5 ( & V_148 -> V_4 ) ;
struct V_2 * V_330 = F_2 ( V_1 ) ;
struct V_6 * V_7 = V_148 -> V_4 . V_7 ;
struct V_43 * V_44 = V_7 -> V_45 ;
struct V_160 * V_160 = F_70 ( V_148 -> V_4 . V_190 ) ;
int V_72 = F_137 ( V_330 ) ;
int V_203 = V_160 -> V_203 ;
T_3 V_296 ;
F_89 ( & V_44 -> V_331 ) ;
V_296 = F_138 ( V_44 , F_139 ( V_72 ) ) ;
V_296 = 0 ;
if ( V_203 )
V_296 |= ( 1 << 21 ) ;
else
V_296 &= ~ ( 1 << 21 ) ;
V_296 |= 0x001000c4 ;
F_140 ( V_44 , F_141 ( V_72 ) , V_296 ) ;
F_140 ( V_44 , F_142 ( V_72 ) , 0x00760018 ) ;
F_140 ( V_44 , F_143 ( V_72 ) , 0x00400888 ) ;
F_90 ( & V_44 -> V_331 ) ;
F_130 ( V_148 ) ;
F_144 ( V_44 , V_72 ) ;
}
static void F_145 ( struct V_147 * V_148 )
{
struct V_2 * V_330 = F_146 ( & V_148 -> V_4 ) ;
struct V_6 * V_7 = V_148 -> V_4 . V_7 ;
struct V_43 * V_44 = V_7 -> V_45 ;
int V_72 = F_137 ( V_330 ) ;
if ( ! F_18 ( V_7 ) )
return;
F_89 ( & V_44 -> V_331 ) ;
F_140 ( V_44 , F_147 ( V_72 ) ,
V_332 |
V_333 ) ;
F_140 ( V_44 , F_148 ( V_72 ) ,
V_334 |
V_335 |
( 1 << V_336 ) |
V_337 ) ;
F_140 ( V_44 , F_149 ( V_72 ) , 0x00750f00 ) ;
F_140 ( V_44 , F_150 ( V_72 ) , 0x00001500 ) ;
F_140 ( V_44 , F_151 ( V_72 ) , 0x40400000 ) ;
F_90 ( & V_44 -> V_331 ) ;
}
static bool
F_152 ( struct V_1 * V_1 , T_4 V_103 ,
T_2 * V_78 , int V_83 )
{
int V_82 , V_39 ;
for ( V_39 = 0 ; V_39 < 3 ; V_39 ++ ) {
V_82 = F_50 ( V_1 , V_103 , V_78 ,
V_83 ) ;
if ( V_82 == V_83 )
return true ;
F_44 ( 1 ) ;
}
return false ;
}
static bool
F_153 ( struct V_1 * V_1 , T_2 V_338 [ V_339 ] )
{
return F_152 ( V_1 ,
V_340 ,
V_338 ,
V_339 ) ;
}
static T_2
F_154 ( struct V_1 * V_1 )
{
struct V_6 * V_7 = F_3 ( V_1 ) ;
enum V_72 V_72 = F_2 ( V_1 ) -> V_72 ;
if ( F_18 ( V_7 ) )
return V_341 ;
else if ( F_35 ( V_7 ) && V_72 == V_73 )
return V_342 ;
else if ( F_77 ( V_7 ) && V_72 != V_73 )
return V_341 ;
else
return V_342 ;
}
static T_2
F_155 ( struct V_1 * V_1 , T_2 V_343 )
{
struct V_6 * V_7 = F_3 ( V_1 ) ;
enum V_72 V_72 = F_2 ( V_1 ) -> V_72 ;
if ( F_31 ( V_7 ) ) {
switch ( V_343 & V_344 ) {
case V_345 :
return V_346 ;
case V_347 :
return V_348 ;
case V_342 :
return V_349 ;
case V_341 :
default:
return V_350 ;
}
} else if ( F_18 ( V_7 ) ) {
switch ( V_343 & V_344 ) {
case V_345 :
return V_346 ;
case V_347 :
return V_348 ;
case V_342 :
return V_349 ;
case V_341 :
default:
return V_350 ;
}
} else if ( F_35 ( V_7 ) && V_72 == V_73 ) {
switch ( V_343 & V_344 ) {
case V_345 :
return V_348 ;
case V_347 :
case V_342 :
return V_349 ;
default:
return V_350 ;
}
} else {
switch ( V_343 & V_344 ) {
case V_345 :
return V_348 ;
case V_347 :
return V_348 ;
case V_342 :
return V_349 ;
case V_341 :
default:
return V_350 ;
}
}
}
static T_1 F_156 ( struct V_1 * V_1 )
{
struct V_6 * V_7 = F_3 ( V_1 ) ;
struct V_43 * V_44 = V_7 -> V_45 ;
struct V_2 * V_330 = F_2 ( V_1 ) ;
unsigned long V_351 , V_352 ,
V_353 ;
T_2 V_354 = V_1 -> V_354 [ 0 ] ;
int V_72 = F_137 ( V_330 ) ;
switch ( V_354 & V_355 ) {
case V_350 :
V_352 = 0x0004000 ;
switch ( V_354 & V_344 ) {
case V_345 :
V_351 = 0x2B405555 ;
V_353 = 0x552AB83A ;
break;
case V_347 :
V_351 = 0x2B404040 ;
V_353 = 0x5548B83A ;
break;
case V_342 :
V_351 = 0x2B245555 ;
V_353 = 0x5560B83A ;
break;
case V_341 :
V_351 = 0x2B405555 ;
V_353 = 0x5598DA3A ;
break;
default:
return 0 ;
}
break;
case V_349 :
V_352 = 0x0002000 ;
switch ( V_354 & V_344 ) {
case V_345 :
V_351 = 0x2B404040 ;
V_353 = 0x5552B83A ;
break;
case V_347 :
V_351 = 0x2B404848 ;
V_353 = 0x5580B83A ;
break;
case V_342 :
V_351 = 0x2B404040 ;
V_353 = 0x55ADDA3A ;
break;
default:
return 0 ;
}
break;
case V_348 :
V_352 = 0x0000000 ;
switch ( V_354 & V_344 ) {
case V_345 :
V_351 = 0x2B305555 ;
V_353 = 0x5570B83A ;
break;
case V_347 :
V_351 = 0x2B2B4040 ;
V_353 = 0x55ADDA3A ;
break;
default:
return 0 ;
}
break;
case V_346 :
V_352 = 0x0006000 ;
switch ( V_354 & V_344 ) {
case V_345 :
V_351 = 0x1B405555 ;
V_353 = 0x55ADDA3A ;
break;
default:
return 0 ;
}
break;
default:
return 0 ;
}
F_89 ( & V_44 -> V_331 ) ;
F_140 ( V_44 , F_157 ( V_72 ) , 0x00000000 ) ;
F_140 ( V_44 , F_158 ( V_72 ) , V_351 ) ;
F_140 ( V_44 , F_159 ( V_72 ) ,
V_353 ) ;
F_140 ( V_44 , F_160 ( V_72 ) , 0x0C782040 ) ;
F_140 ( V_44 , F_161 ( V_72 ) , 0x00030000 ) ;
F_140 ( V_44 , F_162 ( V_72 ) , V_352 ) ;
F_140 ( V_44 , F_157 ( V_72 ) , 0x80000000 ) ;
F_90 ( & V_44 -> V_331 ) ;
return 0 ;
}
static void
F_163 ( struct V_1 * V_1 , T_2 V_338 [ V_339 ] )
{
T_2 V_40 = 0 ;
T_2 V_356 = 0 ;
int V_357 ;
T_2 V_358 ;
T_2 V_359 ;
for ( V_357 = 0 ; V_357 < V_1 -> V_163 ; V_357 ++ ) {
T_2 V_360 = F_164 ( V_338 , V_357 ) ;
T_2 V_361 = F_165 ( V_338 , V_357 ) ;
if ( V_360 > V_40 )
V_40 = V_360 ;
if ( V_361 > V_356 )
V_356 = V_361 ;
}
V_358 = F_154 ( V_1 ) ;
if ( V_40 >= V_358 )
V_40 = V_358 | V_362 ;
V_359 = F_155 ( V_1 , V_40 ) ;
if ( V_356 >= V_359 )
V_356 = V_359 | V_363 ;
for ( V_357 = 0 ; V_357 < 4 ; V_357 ++ )
V_1 -> V_354 [ V_357 ] = V_40 | V_356 ;
}
static T_1
F_166 ( T_2 V_354 )
{
T_1 V_364 = 0 ;
switch ( V_354 & V_344 ) {
case V_345 :
default:
V_364 |= V_200 ;
break;
case V_347 :
V_364 |= V_365 ;
break;
case V_342 :
V_364 |= V_366 ;
break;
case V_341 :
V_364 |= V_367 ;
break;
}
switch ( V_354 & V_355 ) {
case V_350 :
default:
V_364 |= V_201 ;
break;
case V_349 :
V_364 |= V_368 ;
break;
case V_348 :
V_364 |= V_369 ;
break;
case V_346 :
V_364 |= V_370 ;
break;
}
return V_364 ;
}
static T_1
F_167 ( T_2 V_354 )
{
int V_364 = V_354 & ( V_344 |
V_355 ) ;
switch ( V_364 ) {
case V_345 | V_350 :
case V_347 | V_350 :
return V_371 ;
case V_345 | V_349 :
return V_372 ;
case V_345 | V_348 :
case V_347 | V_348 :
return V_373 ;
case V_347 | V_349 :
case V_342 | V_349 :
return V_374 ;
case V_342 | V_350 :
case V_341 | V_350 :
return V_375 ;
default:
F_23 ( L_58
L_59 , V_364 ) ;
return V_371 ;
}
}
static T_1
F_168 ( T_2 V_354 )
{
int V_364 = V_354 & ( V_344 |
V_355 ) ;
switch ( V_364 ) {
case V_345 | V_350 :
return V_376 ;
case V_345 | V_349 :
return V_377 ;
case V_345 | V_348 :
return V_378 ;
case V_347 | V_350 :
return V_379 ;
case V_347 | V_349 :
return V_380 ;
case V_342 | V_350 :
return V_381 ;
case V_342 | V_349 :
return V_382 ;
default:
F_23 ( L_58
L_59 , V_364 ) ;
return V_383 ;
}
}
static T_1
F_169 ( T_2 V_354 )
{
int V_364 = V_354 & ( V_344 |
V_355 ) ;
switch ( V_364 ) {
case V_345 | V_350 :
return V_384 ;
case V_345 | V_349 :
return V_385 ;
case V_345 | V_348 :
return V_386 ;
case V_345 | V_346 :
return V_387 ;
case V_347 | V_350 :
return V_388 ;
case V_347 | V_349 :
return V_389 ;
case V_347 | V_348 :
return V_390 ;
case V_342 | V_350 :
return V_391 ;
case V_342 | V_349 :
return V_392 ;
default:
F_23 ( L_58
L_59 , V_364 ) ;
return V_384 ;
}
}
static void
F_170 ( struct V_1 * V_1 , T_1 * V_196 )
{
struct V_2 * V_3 = F_2 ( V_1 ) ;
enum V_72 V_72 = V_3 -> V_72 ;
struct V_6 * V_7 = V_3 -> V_4 . V_4 . V_7 ;
T_1 V_364 , V_213 ;
T_2 V_354 = V_1 -> V_354 [ 0 ] ;
if ( F_31 ( V_7 ) ) {
V_364 = F_169 ( V_354 ) ;
V_213 = V_393 ;
} else if ( F_18 ( V_7 ) ) {
V_364 = F_156 ( V_1 ) ;
V_213 = 0 ;
} else if ( F_35 ( V_7 ) && V_72 == V_73 ) {
V_364 = F_168 ( V_354 ) ;
V_213 = V_394 ;
} else if ( F_34 ( V_7 ) && V_72 == V_73 ) {
V_364 = F_167 ( V_354 ) ;
V_213 = V_395 ;
} else {
V_364 = F_166 ( V_354 ) ;
V_213 = V_396 | V_397 ;
}
F_23 ( L_60 , V_364 ) ;
* V_196 = ( * V_196 & ~ V_213 ) | V_364 ;
}
static bool
F_171 ( struct V_1 * V_1 ,
T_1 V_398 ,
T_2 V_399 )
{
struct V_2 * V_3 = F_2 ( V_1 ) ;
struct V_6 * V_7 = V_3 -> V_4 . V_4 . V_7 ;
struct V_43 * V_44 = V_7 -> V_45 ;
enum V_72 V_72 = V_3 -> V_72 ;
int V_82 ;
if ( F_31 ( V_7 ) ) {
T_1 V_400 = F_19 ( F_172 ( V_72 ) ) ;
if ( V_399 & V_401 )
V_400 |= V_402 ;
else
V_400 &= ~ V_402 ;
V_400 &= ~ V_403 ;
switch ( V_399 & V_404 ) {
case V_405 :
V_400 |= V_406 ;
break;
case V_407 :
V_400 |= V_408 ;
break;
case V_409 :
V_400 |= V_410 ;
break;
case V_411 :
V_400 |= V_412 ;
break;
}
F_45 ( F_172 ( V_72 ) , V_400 ) ;
} else if ( F_77 ( V_7 ) && ( F_35 ( V_7 ) || V_72 != V_73 ) ) {
V_398 &= ~ V_413 ;
switch ( V_399 & V_404 ) {
case V_405 :
V_398 |= V_209 ;
break;
case V_407 :
V_398 |= V_414 ;
break;
case V_409 :
V_398 |= V_415 ;
break;
case V_411 :
F_29 ( L_61 ) ;
V_398 |= V_415 ;
break;
}
} else {
V_398 &= ~ V_416 ;
switch ( V_399 & V_404 ) {
case V_405 :
V_398 |= V_211 ;
break;
case V_407 :
V_398 |= V_417 ;
break;
case V_409 :
V_398 |= V_418 ;
break;
case V_411 :
F_29 ( L_61 ) ;
V_398 |= V_418 ;
break;
}
}
F_45 ( V_1 -> V_198 , V_398 ) ;
F_71 ( V_1 -> V_198 ) ;
F_49 ( V_1 ,
V_419 ,
V_399 ) ;
if ( ( V_399 & V_404 ) !=
V_405 ) {
V_82 = F_47 ( V_1 ,
V_420 ,
V_1 -> V_354 ,
V_1 -> V_163 ) ;
if ( V_82 != V_1 -> V_163 )
return false ;
}
return true ;
}
static void F_173 ( struct V_1 * V_1 )
{
struct V_2 * V_3 = F_2 ( V_1 ) ;
struct V_6 * V_7 = V_3 -> V_4 . V_4 . V_7 ;
struct V_43 * V_44 = V_7 -> V_45 ;
enum V_72 V_72 = V_3 -> V_72 ;
T_1 V_296 ;
if ( ! F_31 ( V_7 ) )
return;
V_296 = F_19 ( F_172 ( V_72 ) ) ;
V_296 &= ~ V_403 ;
V_296 |= V_421 ;
F_45 ( F_172 ( V_72 ) , V_296 ) ;
if ( V_72 == V_73 )
return;
if ( F_174 ( ( F_19 ( F_175 ( V_72 ) ) & V_422 ) ,
1 ) )
F_29 ( L_62 ) ;
}
void
F_131 ( struct V_1 * V_1 )
{
struct V_423 * V_148 = & F_2 ( V_1 ) -> V_4 . V_4 ;
struct V_6 * V_7 = V_148 -> V_7 ;
int V_39 ;
T_2 V_424 ;
int V_425 , V_426 ;
T_1 V_196 = V_1 -> V_196 ;
if ( F_31 ( V_7 ) )
F_176 ( V_148 ) ;
F_47 ( V_1 , V_427 ,
V_1 -> V_182 ,
V_183 ) ;
V_196 |= V_242 ;
memset ( V_1 -> V_354 , 0 , 4 ) ;
V_424 = 0xff ;
V_425 = 0 ;
V_426 = 0 ;
for (; ; ) {
T_2 V_338 [ V_339 ] ;
F_170 ( V_1 , & V_196 ) ;
if ( ! F_171 ( V_1 , V_196 ,
V_407 |
V_401 ) )
break;
F_177 ( V_1 -> V_11 ) ;
if ( ! F_153 ( V_1 , V_338 ) ) {
F_29 ( L_63 ) ;
break;
}
if ( F_178 ( V_338 , V_1 -> V_163 ) ) {
F_23 ( L_64 ) ;
break;
}
for ( V_39 = 0 ; V_39 < V_1 -> V_163 ; V_39 ++ )
if ( ( V_1 -> V_354 [ V_39 ] & V_362 ) == 0 )
break;
if ( V_39 == V_1 -> V_163 ) {
++ V_426 ;
if ( V_426 == 5 ) {
F_23 ( L_65 ) ;
break;
}
memset ( V_1 -> V_354 , 0 , 4 ) ;
V_425 = 0 ;
continue;
}
if ( ( V_1 -> V_354 [ 0 ] & V_344 ) == V_424 ) {
++ V_425 ;
if ( V_425 == 5 ) {
F_23 ( L_66 ) ;
break;
}
} else
V_425 = 0 ;
V_424 = V_1 -> V_354 [ 0 ] & V_344 ;
F_163 ( V_1 , V_338 ) ;
}
V_1 -> V_196 = V_196 ;
}
void
F_132 ( struct V_1 * V_1 )
{
bool V_428 = false ;
int V_429 , V_430 ;
T_1 V_196 = V_1 -> V_196 ;
V_429 = 0 ;
V_430 = 0 ;
V_428 = false ;
for (; ; ) {
T_2 V_338 [ V_339 ] ;
if ( V_430 > 5 ) {
F_29 ( L_67 ) ;
F_128 ( V_1 ) ;
break;
}
F_170 ( V_1 , & V_196 ) ;
if ( ! F_171 ( V_1 , V_196 ,
V_409 |
V_401 ) )
break;
F_179 ( V_1 -> V_11 ) ;
if ( ! F_153 ( V_1 , V_338 ) )
break;
if ( ! F_178 ( V_338 , V_1 -> V_163 ) ) {
F_131 ( V_1 ) ;
V_430 ++ ;
continue;
}
if ( F_180 ( V_338 , V_1 -> V_163 ) ) {
V_428 = true ;
break;
}
if ( V_429 > 5 ) {
F_128 ( V_1 ) ;
F_131 ( V_1 ) ;
V_429 = 0 ;
V_430 ++ ;
continue;
}
F_163 ( V_1 , V_338 ) ;
++ V_429 ;
}
F_173 ( V_1 ) ;
V_1 -> V_196 = V_196 ;
if ( V_428 )
F_23 ( L_68 ) ;
}
void F_133 ( struct V_1 * V_1 )
{
F_171 ( V_1 , V_1 -> V_196 ,
V_405 ) ;
}
static void
F_128 ( struct V_1 * V_1 )
{
struct V_2 * V_3 = F_2 ( V_1 ) ;
enum V_72 V_72 = V_3 -> V_72 ;
struct V_6 * V_7 = V_3 -> V_4 . V_4 . V_7 ;
struct V_43 * V_44 = V_7 -> V_45 ;
struct V_160 * V_160 =
F_70 ( V_3 -> V_4 . V_4 . V_190 ) ;
T_1 V_196 = V_1 -> V_196 ;
if ( F_31 ( V_7 ) )
return;
if ( F_85 ( ( F_19 ( V_1 -> V_198 ) & V_242 ) == 0 ) )
return;
F_23 ( L_41 ) ;
if ( F_77 ( V_7 ) && ( F_35 ( V_7 ) || V_72 != V_73 ) ) {
V_196 &= ~ V_413 ;
F_45 ( V_1 -> V_198 , V_196 | V_431 ) ;
} else {
V_196 &= ~ V_416 ;
F_45 ( V_1 -> V_198 , V_196 | V_432 ) ;
}
F_71 ( V_1 -> V_198 ) ;
F_181 ( V_7 , V_160 -> V_203 ) ;
if ( F_182 ( V_7 ) &&
F_19 ( V_1 -> V_198 ) & V_212 ) {
struct V_240 * V_190 = V_3 -> V_4 . V_4 . V_190 ;
V_196 &= ~ V_212 ;
F_45 ( V_1 -> V_198 , V_196 ) ;
if ( F_85 ( V_190 == NULL ) ) {
F_71 ( V_1 -> V_198 ) ;
F_44 ( 50 ) ;
} else
F_181 ( V_7 , V_160 -> V_203 ) ;
}
V_196 &= ~ V_204 ;
F_45 ( V_1 -> V_198 , V_196 & ~ V_242 ) ;
F_71 ( V_1 -> V_198 ) ;
F_44 ( V_1 -> V_229 ) ;
}
static bool
F_183 ( struct V_1 * V_1 )
{
char V_433 [ sizeof( V_1 -> V_11 ) * 3 ] ;
if ( F_152 ( V_1 , 0x000 , V_1 -> V_11 ,
sizeof( V_1 -> V_11 ) ) == 0 )
return false ;
F_184 ( V_1 -> V_11 , sizeof( V_1 -> V_11 ) ,
32 , 1 , V_433 , sizeof( V_433 ) , false ) ;
F_23 ( L_69 , V_433 ) ;
if ( V_1 -> V_11 [ V_185 ] == 0 )
return false ;
memset ( V_1 -> V_261 , 0 , sizeof( V_1 -> V_261 ) ) ;
F_152 ( V_1 , V_434 ,
V_1 -> V_261 ,
sizeof( V_1 -> V_261 ) ) ;
if ( F_110 ( V_1 ) )
F_23 ( L_70 ) ;
if ( ! ( V_1 -> V_11 [ V_131 ] &
V_132 ) )
return true ;
if ( V_1 -> V_11 [ V_185 ] == 0x10 )
return true ;
if ( F_152 ( V_1 , V_435 ,
V_1 -> V_436 ,
V_437 ) == 0 )
return false ;
return true ;
}
static void
F_185 ( struct V_1 * V_1 )
{
T_5 V_438 [ 3 ] ;
if ( ! ( V_1 -> V_11 [ V_439 ] & V_440 ) )
return;
F_55 ( V_1 ) ;
if ( F_152 ( V_1 , V_441 , V_438 , 3 ) )
F_23 ( L_71 ,
V_438 [ 0 ] , V_438 [ 1 ] , V_438 [ 2 ] ) ;
if ( F_152 ( V_1 , V_442 , V_438 , 3 ) )
F_23 ( L_72 ,
V_438 [ 0 ] , V_438 [ 1 ] , V_438 [ 2 ] ) ;
F_57 ( V_1 , false ) ;
}
static bool
F_186 ( struct V_1 * V_1 , T_5 * V_443 )
{
int V_82 ;
V_82 = F_152 ( V_1 ,
V_444 ,
V_443 , 1 ) ;
if ( ! V_82 )
return false ;
return true ;
}
static void
F_187 ( struct V_1 * V_1 )
{
F_49 ( V_1 , V_445 , V_446 ) ;
}
void
F_188 ( struct V_1 * V_1 )
{
struct V_147 * V_147 = & F_2 ( V_1 ) -> V_4 ;
T_5 V_443 ;
T_5 V_338 [ V_339 ] ;
if ( ! V_147 -> V_447 )
return;
if ( F_85 ( ! V_147 -> V_4 . V_190 ) )
return;
if ( ! F_153 ( V_1 , V_338 ) ) {
F_128 ( V_1 ) ;
return;
}
if ( ! F_183 ( V_1 ) ) {
F_128 ( V_1 ) ;
return;
}
if ( V_1 -> V_11 [ V_185 ] >= 0x11 &&
F_186 ( V_1 , & V_443 ) ) {
F_49 ( V_1 ,
V_444 ,
V_443 ) ;
if ( V_443 & V_448 )
F_187 ( V_1 ) ;
if ( V_443 & ( V_449 | V_450 ) )
F_74 ( L_73 ) ;
}
if ( ! F_180 ( V_338 , V_1 -> V_163 ) ) {
F_23 ( L_74 ,
F_189 ( & V_147 -> V_4 ) ) ;
F_131 ( V_1 ) ;
F_132 ( V_1 ) ;
F_133 ( V_1 ) ;
}
}
static enum V_451
F_190 ( struct V_1 * V_1 )
{
T_2 * V_11 = V_1 -> V_11 ;
bool V_452 ;
T_2 type ;
if ( ! F_183 ( V_1 ) )
return V_453 ;
if ( ! ( V_11 [ V_131 ] & V_132 ) )
return V_454 ;
V_452 = ! ! ( V_1 -> V_436 [ 0 ] & V_455 ) ;
if ( V_452 ) {
T_2 V_456 ;
if ( ! F_152 ( V_1 , V_457 ,
& V_456 , 1 ) )
return V_458 ;
return F_191 ( V_456 ) ? V_454
: V_453 ;
}
if ( F_192 ( & V_1 -> V_117 ) )
return V_454 ;
type = V_1 -> V_436 [ 0 ] & V_459 ;
if ( type == V_460 || type == V_461 )
return V_458 ;
F_23 ( L_75 ) ;
return V_453 ;
}
static enum V_451
F_193 ( struct V_1 * V_1 )
{
struct V_6 * V_7 = F_3 ( V_1 ) ;
struct V_43 * V_44 = V_7 -> V_45 ;
struct V_2 * V_3 = F_2 ( V_1 ) ;
enum V_451 V_68 ;
if ( F_1 ( V_1 ) ) {
V_68 = F_194 ( V_7 ) ;
if ( V_68 == V_458 )
V_68 = V_454 ;
return V_68 ;
}
if ( ! F_195 ( V_44 , V_3 ) )
return V_453 ;
return F_190 ( V_1 ) ;
}
static enum V_451
F_196 ( struct V_1 * V_1 )
{
struct V_6 * V_7 = F_3 ( V_1 ) ;
struct V_43 * V_44 = V_7 -> V_45 ;
struct V_2 * V_3 = F_2 ( V_1 ) ;
T_1 V_462 ;
if ( F_1 ( V_1 ) ) {
enum V_451 V_68 ;
V_68 = F_194 ( V_7 ) ;
if ( V_68 == V_458 )
V_68 = V_454 ;
return V_68 ;
}
switch ( V_3 -> V_72 ) {
case V_463 :
V_462 = V_464 ;
break;
case V_465 :
V_462 = V_466 ;
break;
case V_467 :
V_462 = V_468 ;
break;
default:
return V_458 ;
}
if ( ( F_19 ( V_469 ) & V_462 ) == 0 )
return V_453 ;
return F_190 ( V_1 ) ;
}
static struct V_470 *
F_197 ( struct V_8 * V_9 , struct V_116 * V_117 )
{
struct V_22 * V_22 = F_12 ( V_9 ) ;
if ( V_22 -> V_470 ) {
struct V_470 * V_470 ;
int V_471 ;
if ( F_198 ( V_22 -> V_470 ) )
return NULL ;
V_471 = ( V_22 -> V_470 -> V_472 + 1 ) * V_473 ;
V_470 = F_199 ( V_22 -> V_470 , V_471 , V_474 ) ;
if ( ! V_470 )
return NULL ;
return V_470 ;
}
return F_200 ( V_9 , V_117 ) ;
}
static int
F_201 ( struct V_8 * V_9 , struct V_116 * V_117 )
{
struct V_22 * V_22 = F_12 ( V_9 ) ;
if ( V_22 -> V_470 ) {
if ( F_198 ( V_22 -> V_470 ) )
return 0 ;
return F_202 ( V_9 ,
V_22 -> V_470 ) ;
}
return F_203 ( V_9 , V_117 ) ;
}
static enum V_451
F_204 ( struct V_8 * V_9 , bool V_475 )
{
struct V_1 * V_1 = F_4 ( V_9 ) ;
struct V_2 * V_3 = F_2 ( V_1 ) ;
struct V_147 * V_147 = & V_3 -> V_4 ;
struct V_6 * V_7 = V_9 -> V_7 ;
enum V_451 V_68 ;
struct V_470 * V_470 = NULL ;
F_23 ( L_76 ,
V_9 -> V_4 . V_476 , F_205 ( V_9 ) ) ;
V_1 -> V_202 = false ;
if ( F_36 ( V_7 ) )
V_68 = F_193 ( V_1 ) ;
else
V_68 = F_196 ( V_1 ) ;
if ( V_68 != V_454 )
return V_68 ;
F_185 ( V_1 ) ;
if ( V_1 -> V_477 != V_478 ) {
V_1 -> V_202 = ( V_1 -> V_477 == V_479 ) ;
} else {
V_470 = F_197 ( V_9 , & V_1 -> V_117 ) ;
if ( V_470 ) {
V_1 -> V_202 = F_206 ( V_470 ) ;
F_207 ( V_470 ) ;
}
}
if ( V_147 -> type != V_5 )
V_147 -> type = V_480 ;
return V_454 ;
}
static int F_208 ( struct V_8 * V_9 )
{
struct V_1 * V_1 = F_4 ( V_9 ) ;
struct V_22 * V_22 = F_12 ( V_9 ) ;
struct V_6 * V_7 = V_9 -> V_7 ;
int V_82 ;
V_82 = F_201 ( V_9 , & V_1 -> V_117 ) ;
if ( V_82 )
return V_82 ;
if ( F_1 ( V_1 ) && V_22 -> V_24 . V_23 ) {
struct V_20 * V_21 ;
V_21 = F_209 ( V_7 ,
V_22 -> V_24 . V_23 ) ;
if ( V_21 ) {
F_210 ( V_9 , V_21 ) ;
return 1 ;
}
}
return 0 ;
}
static bool
F_211 ( struct V_8 * V_9 )
{
struct V_1 * V_1 = F_4 ( V_9 ) ;
struct V_470 * V_470 ;
bool V_202 = false ;
V_470 = F_197 ( V_9 , & V_1 -> V_117 ) ;
if ( V_470 ) {
V_202 = F_206 ( V_470 ) ;
F_207 ( V_470 ) ;
}
return V_202 ;
}
static int
F_212 ( struct V_8 * V_9 ,
struct V_481 * V_482 ,
T_6 V_296 )
{
struct V_43 * V_44 = V_9 -> V_7 -> V_45 ;
struct V_22 * V_22 = F_12 ( V_9 ) ;
struct V_147 * V_147 = F_6 ( V_9 ) ;
struct V_1 * V_1 = F_5 ( & V_147 -> V_4 ) ;
int V_82 ;
V_82 = F_213 ( & V_9 -> V_4 , V_482 , V_296 ) ;
if ( V_82 )
return V_82 ;
if ( V_482 == V_44 -> V_483 ) {
int V_39 = V_296 ;
bool V_202 ;
if ( V_39 == V_1 -> V_477 )
return 0 ;
V_1 -> V_477 = V_39 ;
if ( V_39 == V_478 )
V_202 = F_211 ( V_9 ) ;
else
V_202 = ( V_39 == V_479 ) ;
if ( V_202 == V_1 -> V_202 )
return 0 ;
V_1 -> V_202 = V_202 ;
goto V_69;
}
if ( V_482 == V_44 -> V_484 ) {
bool V_485 = V_1 -> V_176 ;
T_1 V_486 = V_1 -> V_177 ;
switch ( V_296 ) {
case V_487 :
V_1 -> V_176 = true ;
break;
case V_488 :
V_1 -> V_176 = false ;
V_1 -> V_177 = 0 ;
break;
case V_489 :
V_1 -> V_176 = false ;
V_1 -> V_177 = V_178 ;
break;
default:
return - V_490 ;
}
if ( V_485 == V_1 -> V_176 &&
V_486 == V_1 -> V_177 )
return 0 ;
goto V_69;
}
if ( F_1 ( V_1 ) &&
V_482 == V_9 -> V_7 -> V_227 . V_491 ) {
if ( V_296 == V_492 ) {
F_23 ( L_77 ) ;
return - V_490 ;
}
if ( V_22 -> V_24 . V_171 == V_296 ) {
return 0 ;
}
V_22 -> V_24 . V_171 = V_296 ;
goto V_69;
}
return - V_490 ;
V_69:
if ( V_147 -> V_4 . V_190 )
F_214 ( V_147 -> V_4 . V_190 ) ;
return 0 ;
}
static void
F_215 ( struct V_8 * V_9 )
{
struct V_22 * V_22 = F_12 ( V_9 ) ;
if ( ! F_216 ( V_22 -> V_470 ) )
F_207 ( V_22 -> V_470 ) ;
if ( V_9 -> V_493 == V_494 )
F_217 ( & V_22 -> V_24 ) ;
F_218 ( V_9 ) ;
F_219 ( V_9 ) ;
F_207 ( V_9 ) ;
}
void F_220 ( struct V_423 * V_148 )
{
struct V_2 * V_3 = F_146 ( V_148 ) ;
struct V_1 * V_1 = & V_3 -> V_495 ;
struct V_6 * V_7 = F_3 ( V_1 ) ;
F_221 ( & V_1 -> V_117 ) ;
F_222 ( V_148 ) ;
if ( F_1 ( V_1 ) ) {
F_223 ( & V_1 -> V_232 ) ;
F_89 ( & V_7 -> V_227 . V_228 ) ;
F_84 ( V_1 ) ;
F_90 ( & V_7 -> V_227 . V_228 ) ;
}
F_207 ( V_3 ) ;
}
static void
F_224 ( struct V_147 * V_147 )
{
struct V_1 * V_1 = F_5 ( & V_147 -> V_4 ) ;
F_188 ( V_1 ) ;
}
int
F_225 ( struct V_240 * V_190 )
{
struct V_6 * V_7 = V_190 -> V_7 ;
struct V_147 * V_147 ;
struct V_1 * V_1 ;
F_226 (dev, crtc, intel_encoder) {
V_1 = F_5 ( & V_147 -> V_4 ) ;
if ( V_147 -> type == V_480 ||
V_147 -> type == V_5 )
return V_1 -> V_198 ;
}
return - 1 ;
}
bool F_227 ( struct V_6 * V_7 )
{
struct V_43 * V_44 = V_7 -> V_45 ;
struct V_496 * V_497 ;
int V_39 ;
if ( ! V_44 -> V_173 . V_498 )
return false ;
for ( V_39 = 0 ; V_39 < V_44 -> V_173 . V_498 ; V_39 ++ ) {
V_497 = V_44 -> V_173 . V_499 + V_39 ;
if ( V_497 -> V_500 == V_501 &&
V_497 -> V_502 == V_503 )
return true ;
}
return false ;
}
static void
F_228 ( struct V_1 * V_1 , struct V_8 * V_9 )
{
struct V_22 * V_22 = F_12 ( V_9 ) ;
F_229 ( V_9 ) ;
F_230 ( V_9 ) ;
V_1 -> V_176 = true ;
if ( F_1 ( V_1 ) ) {
F_231 ( V_9 -> V_7 ) ;
F_232 (
& V_9 -> V_4 ,
V_9 -> V_7 -> V_227 . V_491 ,
V_504 ) ;
V_22 -> V_24 . V_171 = V_504 ;
}
}
static void
F_233 ( struct V_6 * V_7 ,
struct V_1 * V_1 ,
struct V_505 * V_90 )
{
struct V_43 * V_44 = V_7 -> V_45 ;
struct V_505 V_506 , V_173 , V_507 , V_508 ;
T_3 V_509 , V_510 , V_511 , V_224 ;
int V_512 , V_513 , V_514 , V_515 ;
if ( F_36 ( V_7 ) ) {
V_512 = V_63 ;
V_513 = V_516 ;
V_514 = V_517 ;
V_515 = V_518 ;
} else {
V_512 = V_62 ;
V_513 = V_519 ;
V_514 = V_520 ;
V_515 = V_521 ;
}
V_224 = F_83 ( V_1 ) ;
F_45 ( V_512 , V_224 ) ;
V_509 = F_19 ( V_513 ) ;
V_510 = F_19 ( V_514 ) ;
V_511 = F_19 ( V_515 ) ;
V_506 . V_522 = ( V_509 & V_523 ) >>
V_524 ;
V_506 . V_525 = ( V_509 & V_526 ) >>
V_527 ;
V_506 . V_528 = ( V_510 & V_529 ) >>
V_530 ;
V_506 . V_531 = ( V_510 & V_532 ) >>
V_533 ;
V_506 . V_534 = ( ( V_511 & V_535 ) >>
V_536 ) * 1000 ;
F_23 ( L_78 ,
V_506 . V_522 , V_506 . V_525 , V_506 . V_528 , V_506 . V_531 , V_506 . V_534 ) ;
V_173 = V_44 -> V_173 . V_537 ;
V_507 . V_522 = 210 * 10 ;
V_507 . V_525 = 50 * 10 ;
V_507 . V_528 = 50 * 10 ;
V_507 . V_531 = 500 * 10 ;
V_507 . V_534 = ( 510 + 100 ) * 10 ;
F_23 ( L_79 ,
V_173 . V_522 , V_173 . V_525 , V_173 . V_528 , V_173 . V_531 , V_173 . V_534 ) ;
#define F_234 ( T_7 ) final.field = (max(cur.field, vbt.field) == 0 ? \
spec.field : \
max(cur.field, vbt.field))
F_234 ( V_522 ) ;
F_234 ( V_525 ) ;
F_234 ( V_528 ) ;
F_234 ( V_531 ) ;
F_234 ( V_534 ) ;
#undef F_234
#define F_235 ( T_7 ) (DIV_ROUND_UP(final.field, 10))
V_1 -> V_226 = F_235 ( V_522 ) ;
V_1 -> V_238 = F_235 ( V_525 ) ;
V_1 -> V_239 = F_235 ( V_528 ) ;
V_1 -> V_229 = F_235 ( V_531 ) ;
V_1 -> V_234 = F_235 ( V_534 ) ;
#undef F_235
F_23 ( L_80 ,
V_1 -> V_226 , V_1 -> V_229 ,
V_1 -> V_234 ) ;
F_23 ( L_81 ,
V_1 -> V_238 , V_1 -> V_239 ) ;
if ( V_90 )
* V_90 = V_508 ;
}
static void
F_236 ( struct V_6 * V_7 ,
struct V_1 * V_1 ,
struct V_505 * V_538 )
{
struct V_43 * V_44 = V_7 -> V_45 ;
T_3 V_509 , V_510 , V_511 , V_539 = 0 ;
int div = F_36 ( V_7 ) ? F_38 ( V_7 ) : F_17 ( V_7 ) ;
int V_513 , V_514 , V_515 ;
if ( F_36 ( V_7 ) ) {
V_513 = V_516 ;
V_514 = V_517 ;
V_515 = V_518 ;
} else {
V_513 = V_519 ;
V_514 = V_520 ;
V_515 = V_521 ;
}
V_509 = ( V_538 -> V_522 << V_524 ) |
( V_538 -> V_525 << V_527 ) ;
V_510 = ( V_538 -> V_528 << V_530 ) |
( V_538 -> V_531 << V_533 ) ;
V_511 = ( ( 100 * div ) / 2 - 1 ) << V_540 ;
V_511 |= ( F_37 ( V_538 -> V_534 , 1000 )
<< V_536 ) ;
if ( F_18 ( V_7 ) ) {
V_539 = F_19 ( V_513 ) & 0xc0000000 ;
} else if ( F_182 ( V_7 ) || F_77 ( V_7 ) ) {
if ( F_2 ( V_1 ) -> V_72 == V_73 )
V_539 = V_541 ;
else
V_539 = V_542 ;
}
V_509 |= V_539 ;
F_45 ( V_513 , V_509 ) ;
F_45 ( V_514 , V_510 ) ;
F_45 ( V_515 , V_511 ) ;
F_23 ( L_82 ,
F_19 ( V_513 ) ,
F_19 ( V_514 ) ,
F_19 ( V_515 ) ) ;
}
static bool F_237 ( struct V_1 * V_1 ,
struct V_22 * V_22 )
{
struct V_8 * V_9 = & V_22 -> V_4 ;
struct V_2 * V_3 = F_2 ( V_1 ) ;
struct V_6 * V_7 = V_3 -> V_4 . V_4 . V_7 ;
struct V_43 * V_44 = V_7 -> V_45 ;
struct V_20 * V_23 = NULL ;
struct V_505 V_543 = { 0 } ;
bool V_544 ;
struct V_20 * V_545 ;
struct V_470 * V_470 ;
if ( ! F_1 ( V_1 ) )
return true ;
F_233 ( V_7 , V_1 , & V_543 ) ;
F_55 ( V_1 ) ;
V_544 = F_183 ( V_1 ) ;
F_57 ( V_1 , false ) ;
if ( V_544 ) {
if ( V_1 -> V_11 [ V_185 ] >= 0x11 )
V_44 -> V_546 =
V_1 -> V_11 [ V_547 ] &
V_548 ;
} else {
F_238 ( L_83 ) ;
return false ;
}
F_236 ( V_7 , V_1 ,
& V_543 ) ;
F_55 ( V_1 ) ;
V_470 = F_200 ( V_9 , & V_1 -> V_117 ) ;
if ( V_470 ) {
if ( F_239 ( V_9 , V_470 ) ) {
F_240 ( V_9 ,
V_470 ) ;
F_241 ( V_9 , V_470 ) ;
} else {
F_207 ( V_470 ) ;
V_470 = F_242 ( - V_490 ) ;
}
} else {
V_470 = F_242 ( - V_549 ) ;
}
V_22 -> V_470 = V_470 ;
F_126 (scan, &connector->probed_modes, head) {
if ( ( V_545 -> type & V_550 ) ) {
V_23 = F_209 ( V_7 , V_545 ) ;
break;
}
}
if ( ! V_23 && V_44 -> V_173 . V_551 ) {
V_23 = F_209 ( V_7 ,
V_44 -> V_173 . V_551 ) ;
if ( V_23 )
V_23 -> type |= V_550 ;
}
F_57 ( V_1 , false ) ;
F_243 ( & V_22 -> V_24 , V_23 ) ;
F_244 ( V_9 ) ;
return true ;
}
bool
F_245 ( struct V_2 * V_3 ,
struct V_22 * V_22 )
{
struct V_8 * V_9 = & V_22 -> V_4 ;
struct V_1 * V_1 = & V_3 -> V_495 ;
struct V_147 * V_147 = & V_3 -> V_4 ;
struct V_6 * V_7 = V_147 -> V_4 . V_7 ;
struct V_43 * V_44 = V_7 -> V_45 ;
enum V_72 V_72 = V_3 -> V_72 ;
const char * V_137 = NULL ;
int type , error ;
V_1 -> V_196 = F_19 ( V_1 -> V_198 ) ;
V_1 -> V_162 = V_22 ;
type = V_552 ;
switch ( V_72 ) {
case V_73 :
type = V_494 ;
break;
case V_465 :
if ( F_18 ( V_7 ) )
type = V_494 ;
break;
case V_467 :
if ( F_36 ( V_7 ) && F_227 ( V_7 ) )
type = V_494 ;
break;
default:
break;
}
if ( type == V_494 )
V_147 -> type = V_5 ;
F_23 ( L_84 ,
type == V_494 ? L_85 : L_86 ,
F_246 ( V_72 ) ) ;
F_247 ( V_7 , V_9 , & V_553 , type ) ;
F_248 ( V_9 , & V_554 ) ;
V_9 -> V_555 = true ;
V_9 -> V_556 = 0 ;
F_249 ( & V_1 -> V_232 ,
F_87 ) ;
F_250 ( V_22 , V_147 ) ;
F_251 ( V_9 ) ;
if ( F_31 ( V_7 ) )
V_22 -> V_557 = V_558 ;
else
V_22 -> V_557 = V_559 ;
V_1 -> V_67 = V_1 -> V_198 + 0x10 ;
if ( F_31 ( V_7 ) ) {
switch ( V_3 -> V_72 ) {
case V_73 :
V_1 -> V_67 = V_560 ;
break;
case V_463 :
V_1 -> V_67 = V_561 ;
break;
case V_465 :
V_1 -> V_67 = V_562 ;
break;
case V_467 :
V_1 -> V_67 = V_563 ;
break;
default:
F_252 () ;
}
}
switch ( V_72 ) {
case V_73 :
V_147 -> V_564 = V_565 ;
V_137 = L_87 ;
break;
case V_463 :
V_147 -> V_564 = V_566 ;
V_137 = L_88 ;
break;
case V_465 :
V_147 -> V_564 = V_567 ;
V_137 = L_89 ;
break;
case V_467 :
V_147 -> V_564 = V_568 ;
V_137 = L_90 ;
break;
default:
F_252 () ;
}
error = F_54 ( V_1 , V_22 , V_137 ) ;
F_8 ( error , L_91 ,
error , F_246 ( V_72 ) ) ;
V_1 -> V_274 = false ;
if ( ! F_237 ( V_1 , V_22 ) ) {
F_221 ( & V_1 -> V_117 ) ;
if ( F_1 ( V_1 ) ) {
F_223 ( & V_1 -> V_232 ) ;
F_89 ( & V_7 -> V_227 . V_228 ) ;
F_84 ( V_1 ) ;
F_90 ( & V_7 -> V_227 . V_228 ) ;
}
F_218 ( V_9 ) ;
F_219 ( V_9 ) ;
return false ;
}
F_228 ( V_1 , V_9 ) ;
if ( F_59 ( V_7 ) && ! F_253 ( V_7 ) ) {
T_3 V_400 = F_19 ( V_569 ) ;
F_45 ( V_569 , ( V_400 & ~ 0xf ) | 0xd ) ;
}
return true ;
}
void
F_254 ( struct V_6 * V_7 , int V_198 , enum V_72 V_72 )
{
struct V_2 * V_3 ;
struct V_147 * V_147 ;
struct V_423 * V_148 ;
struct V_22 * V_22 ;
V_3 = F_255 ( sizeof( struct V_2 ) , V_474 ) ;
if ( ! V_3 )
return;
V_22 = F_255 ( sizeof( struct V_22 ) , V_474 ) ;
if ( ! V_22 ) {
F_207 ( V_3 ) ;
return;
}
V_147 = & V_3 -> V_4 ;
V_148 = & V_147 -> V_4 ;
F_256 ( V_7 , & V_147 -> V_4 , & V_570 ,
V_571 ) ;
V_147 -> V_572 = F_61 ;
V_147 -> V_573 = F_72 ;
V_147 -> V_574 = F_127 ;
V_147 -> V_575 = F_129 ;
V_147 -> V_557 = F_104 ;
V_147 -> V_576 = F_109 ;
if ( F_18 ( V_7 ) ) {
V_147 -> V_577 = F_145 ;
V_147 -> V_578 = F_136 ;
V_147 -> V_579 = F_134 ;
} else {
V_147 -> V_578 = F_135 ;
V_147 -> V_579 = F_130 ;
}
V_3 -> V_72 = V_72 ;
V_3 -> V_495 . V_198 = V_198 ;
V_147 -> type = V_480 ;
V_147 -> V_580 = ( 1 << 0 ) | ( 1 << 1 ) | ( 1 << 2 ) ;
V_147 -> V_581 = false ;
V_147 -> V_582 = F_224 ;
if ( ! F_245 ( V_3 , V_22 ) ) {
F_222 ( V_148 ) ;
F_207 ( V_3 ) ;
F_207 ( V_22 ) ;
}
}
