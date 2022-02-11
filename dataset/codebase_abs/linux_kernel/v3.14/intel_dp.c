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
static enum V_20
F_11 ( struct V_8 * V_9 ,
struct V_21 * V_22 )
{
struct V_1 * V_1 = F_4 ( V_9 ) ;
struct V_23 * V_23 = F_12 ( V_9 ) ;
struct V_21 * V_24 = V_23 -> V_25 . V_24 ;
int V_26 = V_22 -> clock ;
int V_27 , V_28 , V_19 , V_18 ;
if ( F_1 ( V_1 ) && V_24 ) {
if ( V_22 -> V_29 > V_24 -> V_29 )
return V_30 ;
if ( V_22 -> V_31 > V_24 -> V_31 )
return V_30 ;
V_26 = V_24 -> clock ;
}
V_18 = F_13 ( F_7 ( V_1 ) ) ;
V_19 = F_14 ( V_1 -> V_11 ) ;
V_27 = F_10 ( V_18 , V_19 ) ;
V_28 = F_9 ( V_26 , 18 ) ;
if ( V_28 > V_27 )
return V_32 ;
if ( V_22 -> clock < 10000 )
return V_33 ;
if ( V_22 -> V_34 & V_35 )
return V_36 ;
return V_37 ;
}
static T_1
F_15 ( T_2 * V_38 , int V_39 )
{
int V_40 ;
T_1 V_41 = 0 ;
if ( V_39 > 4 )
V_39 = 4 ;
for ( V_40 = 0 ; V_40 < V_39 ; V_40 ++ )
V_41 |= ( ( T_1 ) V_38 [ V_40 ] ) << ( ( 3 - V_40 ) * 8 ) ;
return V_41 ;
}
static void
F_16 ( T_1 V_38 , T_2 * V_42 , int V_43 )
{
int V_40 ;
if ( V_43 > 4 )
V_43 = 4 ;
for ( V_40 = 0 ; V_40 < V_43 ; V_40 ++ )
V_42 [ V_40 ] = V_38 >> ( ( 3 - V_40 ) * 8 ) ;
}
static int
F_17 ( struct V_6 * V_7 )
{
struct V_44 * V_45 = V_7 -> V_46 ;
T_1 V_47 ;
if ( F_18 ( V_7 ) )
return 200 ;
V_47 = F_19 ( V_48 ) ;
switch ( V_47 & V_49 ) {
case V_50 :
return 100 ;
case V_51 :
return 133 ;
case V_52 :
return 166 ;
case V_53 :
return 200 ;
case V_54 :
return 266 ;
case V_55 :
return 333 ;
case V_56 :
case V_57 :
return 400 ;
default:
return 133 ;
}
}
static enum V_58
F_20 ( struct V_1 * V_1 )
{
struct V_2 * V_3 = F_2 ( V_1 ) ;
struct V_59 * V_60 = V_3 -> V_4 . V_4 . V_60 ;
struct V_6 * V_7 = V_3 -> V_4 . V_4 . V_7 ;
struct V_44 * V_45 = V_7 -> V_46 ;
enum V_61 V_61 = V_3 -> V_61 ;
enum V_58 V_58 ;
if ( V_60 )
return F_21 ( V_60 ) -> V_58 ;
for ( V_58 = V_62 ; V_58 <= V_63 ; V_58 ++ ) {
T_3 V_64 = F_19 ( F_22 ( V_58 ) ) &
V_65 ;
if ( V_64 == V_66 && V_61 == V_67 )
return V_58 ;
if ( V_64 == V_68 && V_61 == V_69 )
return V_58 ;
}
return V_62 ;
}
static T_3 F_23 ( struct V_1 * V_1 )
{
struct V_6 * V_7 = F_3 ( V_1 ) ;
if ( F_24 ( V_7 ) )
return V_70 ;
else
return F_25 ( F_20 ( V_1 ) ) ;
}
static T_3 F_26 ( struct V_1 * V_1 )
{
struct V_6 * V_7 = F_3 ( V_1 ) ;
if ( F_24 ( V_7 ) )
return V_71 ;
else
return F_27 ( F_20 ( V_1 ) ) ;
}
static bool F_28 ( struct V_1 * V_1 )
{
struct V_6 * V_7 = F_3 ( V_1 ) ;
struct V_44 * V_45 = V_7 -> V_46 ;
return ( F_19 ( F_26 ( V_1 ) ) & V_72 ) != 0 ;
}
static bool F_29 ( struct V_1 * V_1 )
{
struct V_6 * V_7 = F_3 ( V_1 ) ;
struct V_44 * V_45 = V_7 -> V_46 ;
return ( F_19 ( F_23 ( V_1 ) ) & V_73 ) != 0 ;
}
static void
F_30 ( struct V_1 * V_1 )
{
struct V_6 * V_7 = F_3 ( V_1 ) ;
struct V_44 * V_45 = V_7 -> V_46 ;
if ( ! F_1 ( V_1 ) )
return;
if ( ! F_28 ( V_1 ) && ! F_29 ( V_1 ) ) {
F_8 ( 1 , L_2 ) ;
F_31 ( L_3 ,
F_19 ( F_26 ( V_1 ) ) ,
F_19 ( F_23 ( V_1 ) ) ) ;
}
}
static T_1
F_32 ( struct V_1 * V_1 , bool V_74 )
{
struct V_2 * V_3 = F_2 ( V_1 ) ;
struct V_6 * V_7 = V_3 -> V_4 . V_4 . V_7 ;
struct V_44 * V_45 = V_7 -> V_46 ;
T_1 V_75 = V_1 -> V_76 ;
T_1 V_77 ;
bool V_78 ;
#define F_33 (((status = I915_READ_NOTRACE(ch_ctl)) & DP_AUX_CH_CTL_SEND_BUSY) == 0)
if ( V_74 )
V_78 = F_34 ( V_45 -> V_79 , F_33 ,
F_35 ( 10 ) ) ;
else
V_78 = F_36 ( F_33 , 10 ) == 0 ;
if ( ! V_78 )
F_37 ( L_4 ,
V_74 ) ;
#undef F_33
return V_77 ;
}
static T_1 F_38 ( struct V_1 * V_1 ,
int V_80 )
{
struct V_2 * V_3 = F_2 ( V_1 ) ;
struct V_6 * V_7 = V_3 -> V_4 . V_4 . V_7 ;
struct V_44 * V_45 = V_7 -> V_46 ;
if ( F_18 ( V_7 ) ) {
return V_80 ? 0 : 100 ;
} else if ( V_3 -> V_61 == V_81 ) {
if ( V_80 )
return 0 ;
if ( F_39 ( V_7 ) )
return F_40 ( F_41 ( V_45 ) , 2000 ) ;
else if ( F_42 ( V_7 ) || F_43 ( V_7 ) )
return 200 ;
else
return 225 ;
} else if ( V_45 -> V_82 == V_83 ) {
switch ( V_80 ) {
case 0 : return 63 ;
case 1 : return 72 ;
default: return 0 ;
}
} else if ( F_24 ( V_7 ) ) {
return V_80 ? 0 : F_44 ( F_45 ( V_7 ) , 2 ) ;
} else {
return V_80 ? 0 : F_17 ( V_7 ) / 2 ;
}
}
static int
F_46 ( struct V_1 * V_1 ,
T_2 * V_84 , int V_85 ,
T_2 * V_86 , int V_87 )
{
struct V_2 * V_3 = F_2 ( V_1 ) ;
struct V_6 * V_7 = V_3 -> V_4 . V_4 . V_7 ;
struct V_44 * V_45 = V_7 -> V_46 ;
T_1 V_75 = V_1 -> V_76 ;
T_1 V_88 = V_75 + 4 ;
T_1 V_89 ;
int V_40 , V_90 , V_91 ;
T_1 V_77 ;
int V_92 , V_93 , clock = 0 ;
bool V_74 = F_47 ( V_7 ) ;
T_1 V_94 ;
F_48 ( & V_45 -> V_95 , 0 ) ;
F_30 ( V_1 ) ;
if ( F_42 ( V_7 ) )
V_93 = 3 ;
else
V_93 = 5 ;
if ( F_49 ( V_7 ) && V_75 == V_96 )
V_94 = V_97 ;
else
V_94 = V_98 ;
F_50 ( V_45 ) ;
for ( V_92 = 0 ; V_92 < 3 ; V_92 ++ ) {
V_77 = F_51 ( V_75 ) ;
if ( ( V_77 & V_99 ) == 0 )
break;
F_52 ( 1 ) ;
}
if ( V_92 == 3 ) {
F_8 ( 1 , L_5 ,
F_19 ( V_75 ) ) ;
V_90 = - V_100 ;
goto V_101;
}
if ( F_53 ( V_85 > 20 || V_87 > 20 ) ) {
V_90 = - V_102 ;
goto V_101;
}
while ( ( V_89 = F_38 ( V_1 , clock ++ ) ) ) {
for ( V_92 = 0 ; V_92 < 5 ; V_92 ++ ) {
for ( V_40 = 0 ; V_40 < V_85 ; V_40 += 4 )
F_54 ( V_88 + V_40 ,
F_15 ( V_84 + V_40 , V_85 - V_40 ) ) ;
F_54 ( V_75 ,
V_99 |
( V_74 ? V_103 : 0 ) |
V_94 |
( V_85 << V_104 ) |
( V_93 << V_105 ) |
( V_89 << V_106 ) |
V_107 |
V_108 |
V_109 ) ;
V_77 = F_32 ( V_1 , V_74 ) ;
F_54 ( V_75 ,
V_77 |
V_107 |
V_108 |
V_109 ) ;
if ( V_77 & ( V_108 |
V_109 ) )
continue;
if ( V_77 & V_107 )
break;
}
if ( V_77 & V_107 )
break;
}
if ( ( V_77 & V_107 ) == 0 ) {
F_37 ( L_6 , V_77 ) ;
V_90 = - V_100 ;
goto V_101;
}
if ( V_77 & V_109 ) {
F_37 ( L_7 , V_77 ) ;
V_90 = - V_110 ;
goto V_101;
}
if ( V_77 & V_108 ) {
F_31 ( L_8 , V_77 ) ;
V_90 = - V_111 ;
goto V_101;
}
V_91 = ( ( V_77 & V_112 ) >>
V_104 ) ;
if ( V_91 > V_87 )
V_91 = V_87 ;
for ( V_40 = 0 ; V_40 < V_91 ; V_40 += 4 )
F_16 ( F_19 ( V_88 + V_40 ) ,
V_86 + V_40 , V_91 - V_40 ) ;
V_90 = V_91 ;
V_101:
F_48 ( & V_45 -> V_95 , V_113 ) ;
F_55 ( V_45 ) ;
return V_90 ;
}
static int
F_56 ( struct V_1 * V_1 ,
T_4 V_114 , T_2 * V_84 , int V_85 )
{
int V_90 ;
T_2 V_115 [ 20 ] ;
int V_116 ;
T_2 V_117 ;
int V_118 ;
if ( F_53 ( V_85 > 16 ) )
return - V_102 ;
F_30 ( V_1 ) ;
V_115 [ 0 ] = V_119 << 4 ;
V_115 [ 1 ] = V_114 >> 8 ;
V_115 [ 2 ] = V_114 & 0xff ;
V_115 [ 3 ] = V_85 - 1 ;
memcpy ( & V_115 [ 4 ] , V_84 , V_85 ) ;
V_116 = V_85 + 4 ;
for ( V_118 = 0 ; V_118 < 7 ; V_118 ++ ) {
V_90 = F_46 ( V_1 , V_115 , V_116 , & V_117 , 1 ) ;
if ( V_90 < 0 )
return V_90 ;
V_117 >>= 4 ;
if ( ( V_117 & V_120 ) == V_121 )
return V_85 ;
else if ( ( V_117 & V_120 ) == V_122 )
F_57 ( 400 , 500 ) ;
else
return - V_110 ;
}
F_37 ( L_9 ) ;
return - V_110 ;
}
static int
F_58 ( struct V_1 * V_1 ,
T_4 V_114 , T_2 V_123 )
{
return F_56 ( V_1 , V_114 , & V_123 , 1 ) ;
}
static int
F_59 ( struct V_1 * V_1 ,
T_4 V_114 , T_2 * V_86 , int V_91 )
{
T_2 V_115 [ 4 ] ;
int V_116 ;
T_2 V_124 [ 20 ] ;
int V_125 ;
T_2 V_117 ;
int V_90 ;
int V_118 ;
if ( F_53 ( V_91 > 19 ) )
return - V_102 ;
F_30 ( V_1 ) ;
V_115 [ 0 ] = V_126 << 4 ;
V_115 [ 1 ] = V_114 >> 8 ;
V_115 [ 2 ] = V_114 & 0xff ;
V_115 [ 3 ] = V_91 - 1 ;
V_116 = 4 ;
V_125 = V_91 + 1 ;
for ( V_118 = 0 ; V_118 < 7 ; V_118 ++ ) {
V_90 = F_46 ( V_1 , V_115 , V_116 ,
V_124 , V_125 ) ;
if ( V_90 == 0 )
return - V_127 ;
if ( V_90 < 0 )
return V_90 ;
V_117 = V_124 [ 0 ] >> 4 ;
if ( ( V_117 & V_120 ) == V_121 ) {
memcpy ( V_86 , V_124 + 1 , V_90 - 1 ) ;
return V_90 - 1 ;
}
else if ( ( V_117 & V_120 ) == V_122 )
F_57 ( 400 , 500 ) ;
else
return - V_110 ;
}
F_37 ( L_9 ) ;
return - V_110 ;
}
static int
F_60 ( struct V_128 * V_129 , int V_22 ,
T_2 V_130 , T_2 * V_131 )
{
struct V_132 * V_133 = V_129 -> V_133 ;
struct V_1 * V_1 = F_61 ( V_129 ,
struct V_1 ,
V_129 ) ;
T_4 V_114 = V_133 -> V_114 ;
T_2 V_115 [ 5 ] ;
T_2 V_124 [ 2 ] ;
unsigned V_118 ;
int V_116 ;
int V_125 ;
int V_90 ;
F_62 ( V_1 ) ;
F_30 ( V_1 ) ;
if ( V_22 & V_134 )
V_115 [ 0 ] = V_135 << 4 ;
else
V_115 [ 0 ] = V_136 << 4 ;
if ( ! ( V_22 & V_137 ) )
V_115 [ 0 ] |= V_138 << 4 ;
V_115 [ 1 ] = V_114 >> 8 ;
V_115 [ 2 ] = V_114 ;
switch ( V_22 ) {
case V_139 :
V_115 [ 3 ] = 0 ;
V_115 [ 4 ] = V_130 ;
V_116 = 5 ;
V_125 = 1 ;
break;
case V_134 :
V_115 [ 3 ] = 0 ;
V_116 = 4 ;
V_125 = 2 ;
break;
default:
V_116 = 3 ;
V_125 = 1 ;
break;
}
for ( V_118 = 0 ; V_118 < 7 ; V_118 ++ ) {
V_90 = F_46 ( V_1 ,
V_115 , V_116 ,
V_124 , V_125 ) ;
if ( V_90 < 0 ) {
F_31 ( L_10 , V_90 ) ;
goto V_101;
}
switch ( ( V_124 [ 0 ] >> 4 ) & V_120 ) {
case V_121 :
break;
case V_140 :
F_31 ( L_11 ) ;
V_90 = - V_141 ;
goto V_101;
case V_122 :
if ( V_1 -> V_11 [ V_142 ] &
V_143 )
F_57 ( 500 , 600 ) ;
else
F_57 ( 300 , 400 ) ;
continue;
default:
F_37 ( L_12 ,
V_124 [ 0 ] ) ;
V_90 = - V_141 ;
goto V_101;
}
switch ( ( V_124 [ 0 ] >> 4 ) & V_144 ) {
case V_145 :
if ( V_22 == V_134 ) {
* V_131 = V_124 [ 1 ] ;
}
V_90 = V_125 - 1 ;
goto V_101;
case V_146 :
F_31 ( L_13 ) ;
V_90 = - V_141 ;
goto V_101;
case V_147 :
F_31 ( L_14 ) ;
F_63 ( 100 ) ;
break;
default:
F_37 ( L_15 , V_124 [ 0 ] ) ;
V_90 = - V_141 ;
goto V_101;
}
}
F_37 ( L_9 ) ;
V_90 = - V_141 ;
V_101:
F_64 ( V_1 , false ) ;
return V_90 ;
}
static int
F_65 ( struct V_1 * V_1 ,
struct V_23 * V_23 , const char * V_148 )
{
int V_90 ;
F_31 ( L_16 , V_148 ) ;
V_1 -> V_149 . V_150 = false ;
V_1 -> V_149 . V_114 = 0 ;
V_1 -> V_149 . V_151 = F_60 ;
memset ( & V_1 -> V_129 , '\0' , sizeof( V_1 -> V_129 ) ) ;
V_1 -> V_129 . V_152 = V_153 ;
V_1 -> V_129 . V_154 = V_155 ;
strncpy ( V_1 -> V_129 . V_148 , V_148 , sizeof( V_1 -> V_129 . V_148 ) - 1 ) ;
V_1 -> V_129 . V_148 [ sizeof( V_1 -> V_129 . V_148 ) - 1 ] = '\0' ;
V_1 -> V_129 . V_133 = & V_1 -> V_149 ;
V_1 -> V_129 . V_7 . V_156 = V_23 -> V_4 . V_157 ;
V_90 = F_66 ( & V_1 -> V_129 ) ;
return V_90 ;
}
static void
F_67 ( struct V_158 * V_159 ,
struct V_160 * V_161 , int V_162 )
{
struct V_6 * V_7 = V_159 -> V_4 . V_7 ;
const struct V_163 * V_164 = NULL ;
int V_40 , V_165 = 0 ;
if ( F_68 ( V_7 ) ) {
V_164 = V_166 ;
V_165 = F_69 ( V_166 ) ;
} else if ( F_70 ( V_7 ) ) {
} else if ( F_24 ( V_7 ) ) {
V_164 = V_167 ;
V_165 = F_69 ( V_167 ) ;
} else if ( F_18 ( V_7 ) ) {
V_164 = V_168 ;
V_165 = F_69 ( V_168 ) ;
}
if ( V_164 && V_165 ) {
for ( V_40 = 0 ; V_40 < V_165 ; V_40 ++ ) {
if ( V_162 == V_164 [ V_40 ] . V_162 ) {
V_161 -> V_169 = V_164 [ V_40 ] . V_169 ;
V_161 -> V_170 = true ;
break;
}
}
}
}
bool
F_71 ( struct V_158 * V_159 ,
struct V_160 * V_161 )
{
struct V_6 * V_7 = V_159 -> V_4 . V_7 ;
struct V_44 * V_45 = V_7 -> V_46 ;
struct V_21 * V_171 = & V_161 -> V_171 ;
struct V_1 * V_1 = F_5 ( & V_159 -> V_4 ) ;
enum V_61 V_61 = F_2 ( V_1 ) -> V_61 ;
struct V_172 * V_172 = V_159 -> V_173 ;
struct V_23 * V_23 = V_1 -> V_174 ;
int V_175 , clock ;
int V_176 = F_14 ( V_1 -> V_11 ) ;
int V_177 = F_7 ( V_1 ) == V_14 ? 1 : 0 ;
int V_17 , V_28 ;
static int V_178 [ 2 ] = { V_13 , V_14 } ;
int V_179 , V_180 ;
if ( F_24 ( V_7 ) && ! F_39 ( V_7 ) && V_61 != V_81 )
V_161 -> V_181 = true ;
V_161 -> V_182 = true ;
if ( F_1 ( V_1 ) && V_23 -> V_25 . V_24 ) {
F_72 ( V_23 -> V_25 . V_24 ,
V_171 ) ;
if ( ! F_24 ( V_7 ) )
F_73 ( V_172 , V_161 ,
V_23 -> V_25 . V_183 ) ;
else
F_74 ( V_172 , V_161 ,
V_23 -> V_25 . V_183 ) ;
}
if ( V_171 -> V_34 & V_35 )
return false ;
F_31 ( L_17
L_18 ,
V_176 , V_178 [ V_177 ] ,
V_171 -> V_184 ) ;
V_17 = V_161 -> V_185 ;
if ( F_1 ( V_1 ) && V_45 -> V_186 . V_187 &&
V_45 -> V_186 . V_187 < V_17 ) {
F_31 ( L_19 ,
V_45 -> V_186 . V_187 ) ;
V_17 = V_45 -> V_186 . V_187 ;
}
for (; V_17 >= 6 * 3 ; V_17 -= 2 * 3 ) {
V_28 = F_9 ( V_171 -> V_184 ,
V_17 ) ;
for ( clock = 0 ; clock <= V_177 ; clock ++ ) {
for ( V_175 = 1 ; V_175 <= V_176 ; V_175 <<= 1 ) {
V_180 = F_13 ( V_178 [ clock ] ) ;
V_179 = F_10 ( V_180 ,
V_175 ) ;
if ( V_28 <= V_179 ) {
goto V_188;
}
}
}
}
return false ;
V_188:
if ( V_1 -> V_189 ) {
if ( V_17 != 18 && F_75 ( V_171 ) > 1 )
V_1 -> V_190 = V_191 ;
else
V_1 -> V_190 = 0 ;
}
if ( V_1 -> V_190 )
V_161 -> V_192 = true ;
V_1 -> V_162 = V_178 [ clock ] ;
V_1 -> V_175 = V_175 ;
V_161 -> V_185 = V_17 ;
V_161 -> V_193 = F_13 ( V_1 -> V_162 ) ;
F_31 ( L_20 ,
V_1 -> V_162 , V_1 -> V_175 ,
V_161 -> V_193 , V_17 ) ;
F_31 ( L_21 ,
V_28 , V_179 ) ;
F_76 ( V_17 , V_175 ,
V_171 -> V_184 ,
V_161 -> V_193 ,
& V_161 -> V_194 ) ;
F_67 ( V_159 , V_161 , V_1 -> V_162 ) ;
return true ;
}
static void F_77 ( struct V_1 * V_1 )
{
struct V_2 * V_195 = F_2 ( V_1 ) ;
struct V_172 * V_60 = F_21 ( V_195 -> V_4 . V_4 . V_60 ) ;
struct V_6 * V_7 = V_60 -> V_4 . V_7 ;
struct V_44 * V_45 = V_7 -> V_46 ;
T_3 V_196 ;
F_31 ( L_22 , V_60 -> V_197 . V_193 ) ;
V_196 = F_19 ( V_198 ) ;
V_196 &= ~ V_199 ;
if ( V_60 -> V_197 . V_193 == 162000 ) {
F_31 ( L_23 ) ;
V_196 |= V_200 ;
V_1 -> V_201 |= V_200 ;
} else {
V_196 |= V_202 ;
V_1 -> V_201 |= V_202 ;
}
F_54 ( V_198 , V_196 ) ;
F_78 ( V_198 ) ;
F_63 ( 500 ) ;
}
static void F_79 ( struct V_158 * V_159 )
{
struct V_6 * V_7 = V_159 -> V_4 . V_7 ;
struct V_44 * V_45 = V_7 -> V_46 ;
struct V_1 * V_1 = F_5 ( & V_159 -> V_4 ) ;
enum V_61 V_61 = F_2 ( V_1 ) -> V_61 ;
struct V_172 * V_60 = F_21 ( V_159 -> V_4 . V_60 ) ;
struct V_21 * V_171 = & V_60 -> V_197 . V_171 ;
V_1 -> V_201 = F_19 ( V_1 -> V_203 ) & V_204 ;
V_1 -> V_201 |= V_205 | V_206 ;
V_1 -> V_201 |= F_80 ( V_1 -> V_175 ) ;
if ( V_1 -> V_207 ) {
F_81 ( L_24 ,
F_82 ( V_60 -> V_58 ) ) ;
V_1 -> V_201 |= V_208 ;
F_83 ( & V_159 -> V_4 , V_171 ) ;
}
if ( V_61 == V_81 && F_43 ( V_7 ) && ! F_18 ( V_7 ) ) {
if ( V_171 -> V_34 & V_209 )
V_1 -> V_201 |= V_210 ;
if ( V_171 -> V_34 & V_211 )
V_1 -> V_201 |= V_212 ;
V_1 -> V_201 |= V_213 ;
if ( F_84 ( V_1 -> V_11 ) )
V_1 -> V_201 |= V_214 ;
V_1 -> V_201 |= V_60 -> V_58 << 29 ;
} else if ( ! F_85 ( V_7 ) || V_61 == V_81 ) {
if ( ! F_24 ( V_7 ) && ! F_18 ( V_7 ) )
V_1 -> V_201 |= V_1 -> V_190 ;
if ( V_171 -> V_34 & V_209 )
V_1 -> V_201 |= V_210 ;
if ( V_171 -> V_34 & V_211 )
V_1 -> V_201 |= V_212 ;
V_1 -> V_201 |= V_215 ;
if ( F_84 ( V_1 -> V_11 ) )
V_1 -> V_201 |= V_214 ;
if ( V_60 -> V_58 == 1 )
V_1 -> V_201 |= V_216 ;
} else {
V_1 -> V_201 |= V_213 ;
}
if ( V_61 == V_81 && ! F_18 ( V_7 ) )
F_77 ( V_1 ) ;
}
static void F_86 ( struct V_1 * V_1 ,
T_3 V_217 ,
T_3 V_218 )
{
struct V_6 * V_7 = F_3 ( V_1 ) ;
struct V_44 * V_45 = V_7 -> V_46 ;
T_3 V_219 , V_220 ;
V_219 = F_26 ( V_1 ) ;
V_220 = F_23 ( V_1 ) ;
F_31 ( L_25 ,
V_217 , V_218 ,
F_19 ( V_219 ) ,
F_19 ( V_220 ) ) ;
if ( F_87 ( ( F_19 ( V_219 ) & V_217 ) == V_218 , 5000 , 10 ) ) {
F_37 ( L_26 ,
F_19 ( V_219 ) ,
F_19 ( V_220 ) ) ;
}
F_31 ( L_27 ) ;
}
static void F_88 ( struct V_1 * V_1 )
{
F_31 ( L_28 ) ;
F_86 ( V_1 , V_221 , V_222 ) ;
}
static void F_89 ( struct V_1 * V_1 )
{
F_31 ( L_29 ) ;
F_86 ( V_1 , V_223 , V_224 ) ;
}
static void F_90 ( struct V_1 * V_1 )
{
F_31 ( L_30 ) ;
F_86 ( V_1 , V_225 , V_226 ) ;
}
static T_3 F_91 ( struct V_1 * V_1 )
{
struct V_6 * V_7 = F_3 ( V_1 ) ;
struct V_44 * V_45 = V_7 -> V_46 ;
T_3 V_227 ;
V_227 = F_19 ( F_23 ( V_1 ) ) ;
V_227 &= ~ V_228 ;
V_227 |= V_229 ;
return V_227 ;
}
void F_62 ( struct V_1 * V_1 )
{
struct V_6 * V_7 = F_3 ( V_1 ) ;
struct V_44 * V_45 = V_7 -> V_46 ;
T_3 V_230 ;
T_3 V_219 , V_220 ;
if ( ! F_1 ( V_1 ) )
return;
F_8 ( V_1 -> V_231 ,
L_31 ) ;
V_1 -> V_231 = true ;
if ( F_29 ( V_1 ) )
return;
F_92 ( V_45 ) ;
F_31 ( L_32 ) ;
if ( ! F_28 ( V_1 ) )
F_90 ( V_1 ) ;
V_230 = F_91 ( V_1 ) ;
V_230 |= V_73 ;
V_219 = F_26 ( V_1 ) ;
V_220 = F_23 ( V_1 ) ;
F_54 ( V_220 , V_230 ) ;
F_78 ( V_220 ) ;
F_31 ( L_33 ,
F_19 ( V_219 ) , F_19 ( V_220 ) ) ;
if ( ! F_28 ( V_1 ) ) {
F_31 ( L_34 ) ;
F_52 ( V_1 -> V_232 ) ;
}
}
static void F_93 ( struct V_1 * V_1 )
{
struct V_6 * V_7 = F_3 ( V_1 ) ;
struct V_44 * V_45 = V_7 -> V_46 ;
T_3 V_230 ;
T_3 V_219 , V_220 ;
F_53 ( ! F_94 ( & V_7 -> V_233 . V_234 ) ) ;
if ( ! V_1 -> V_231 && F_29 ( V_1 ) ) {
F_31 ( L_35 ) ;
V_230 = F_91 ( V_1 ) ;
V_230 &= ~ V_73 ;
V_220 = F_23 ( V_1 ) ;
V_219 = F_26 ( V_1 ) ;
F_54 ( V_220 , V_230 ) ;
F_78 ( V_220 ) ;
F_31 ( L_33 ,
F_19 ( V_219 ) , F_19 ( V_220 ) ) ;
if ( ( V_230 & V_235 ) == 0 )
F_52 ( V_1 -> V_236 ) ;
F_95 ( V_45 ) ;
}
}
static void F_96 ( struct V_237 * V_238 )
{
struct V_1 * V_1 = F_61 ( F_97 ( V_238 ) ,
struct V_1 , V_239 ) ;
struct V_6 * V_7 = F_3 ( V_1 ) ;
F_98 ( & V_7 -> V_233 . V_234 ) ;
F_93 ( V_1 ) ;
F_99 ( & V_7 -> V_233 . V_234 ) ;
}
void F_64 ( struct V_1 * V_1 , bool V_240 )
{
if ( ! F_1 ( V_1 ) )
return;
F_8 ( ! V_1 -> V_231 , L_36 ) ;
V_1 -> V_231 = false ;
if ( V_240 ) {
F_93 ( V_1 ) ;
} else {
F_100 ( & V_1 -> V_239 ,
F_101 ( V_1 -> V_236 * 5 ) ) ;
}
}
void F_102 ( struct V_1 * V_1 )
{
struct V_6 * V_7 = F_3 ( V_1 ) ;
struct V_44 * V_45 = V_7 -> V_46 ;
T_3 V_230 ;
T_3 V_220 ;
if ( ! F_1 ( V_1 ) )
return;
F_31 ( L_37 ) ;
if ( F_28 ( V_1 ) ) {
F_31 ( L_38 ) ;
return;
}
F_90 ( V_1 ) ;
V_220 = F_23 ( V_1 ) ;
V_230 = F_91 ( V_1 ) ;
if ( F_103 ( V_7 ) ) {
V_230 &= ~ V_241 ;
F_54 ( V_220 , V_230 ) ;
F_78 ( V_220 ) ;
}
V_230 |= V_235 ;
if ( ! F_103 ( V_7 ) )
V_230 |= V_241 ;
F_54 ( V_220 , V_230 ) ;
F_78 ( V_220 ) ;
F_88 ( V_1 ) ;
if ( F_103 ( V_7 ) ) {
V_230 |= V_241 ;
F_54 ( V_220 , V_230 ) ;
F_78 ( V_220 ) ;
}
}
void F_104 ( struct V_1 * V_1 )
{
struct V_6 * V_7 = F_3 ( V_1 ) ;
struct V_44 * V_45 = V_7 -> V_46 ;
T_3 V_230 ;
T_3 V_220 ;
if ( ! F_1 ( V_1 ) )
return;
F_31 ( L_39 ) ;
F_8 ( ! V_1 -> V_231 , L_40 ) ;
V_230 = F_91 ( V_1 ) ;
V_230 &= ~ ( V_235 | V_73 | V_241 | V_242 ) ;
V_220 = F_23 ( V_1 ) ;
F_54 ( V_220 , V_230 ) ;
F_78 ( V_220 ) ;
V_1 -> V_231 = false ;
F_89 ( V_1 ) ;
F_95 ( V_45 ) ;
}
void F_105 ( struct V_1 * V_1 )
{
struct V_2 * V_3 = F_2 ( V_1 ) ;
struct V_6 * V_7 = V_3 -> V_4 . V_4 . V_7 ;
struct V_44 * V_45 = V_7 -> V_46 ;
T_3 V_230 ;
T_3 V_220 ;
if ( ! F_1 ( V_1 ) )
return;
F_31 ( L_41 ) ;
F_52 ( V_1 -> V_243 ) ;
V_230 = F_91 ( V_1 ) ;
V_230 |= V_242 ;
V_220 = F_23 ( V_1 ) ;
F_54 ( V_220 , V_230 ) ;
F_78 ( V_220 ) ;
F_106 ( V_1 -> V_174 ) ;
}
void F_107 ( struct V_1 * V_1 )
{
struct V_6 * V_7 = F_3 ( V_1 ) ;
struct V_44 * V_45 = V_7 -> V_46 ;
T_3 V_230 ;
T_3 V_220 ;
if ( ! F_1 ( V_1 ) )
return;
F_108 ( V_1 -> V_174 ) ;
F_31 ( L_41 ) ;
V_230 = F_91 ( V_1 ) ;
V_230 &= ~ V_242 ;
V_220 = F_23 ( V_1 ) ;
F_54 ( V_220 , V_230 ) ;
F_78 ( V_220 ) ;
F_52 ( V_1 -> V_244 ) ;
}
static void F_109 ( struct V_1 * V_1 )
{
struct V_2 * V_3 = F_2 ( V_1 ) ;
struct V_59 * V_60 = V_3 -> V_4 . V_4 . V_60 ;
struct V_6 * V_7 = V_60 -> V_7 ;
struct V_44 * V_45 = V_7 -> V_46 ;
T_3 V_196 ;
F_110 ( V_45 ,
F_21 ( V_60 ) -> V_58 ) ;
F_31 ( L_41 ) ;
V_196 = F_19 ( V_198 ) ;
F_8 ( V_196 & V_245 , L_42 ) ;
F_8 ( V_196 & V_246 , L_43 ) ;
V_1 -> V_201 &= ~ ( V_246 | V_208 ) ;
V_1 -> V_201 |= V_245 ;
F_54 ( V_198 , V_1 -> V_201 ) ;
F_78 ( V_198 ) ;
F_63 ( 200 ) ;
}
static void F_111 ( struct V_1 * V_1 )
{
struct V_2 * V_3 = F_2 ( V_1 ) ;
struct V_59 * V_60 = V_3 -> V_4 . V_4 . V_60 ;
struct V_6 * V_7 = V_60 -> V_7 ;
struct V_44 * V_45 = V_7 -> V_46 ;
T_3 V_196 ;
F_110 ( V_45 ,
F_21 ( V_60 ) -> V_58 ) ;
V_196 = F_19 ( V_198 ) ;
F_8 ( ( V_196 & V_245 ) == 0 ,
L_44 ) ;
F_8 ( V_196 & V_246 , L_43 ) ;
V_196 &= ~ V_245 ;
F_54 ( V_198 , V_196 ) ;
F_78 ( V_198 ) ;
F_63 ( 200 ) ;
}
void F_112 ( struct V_1 * V_1 , int V_22 )
{
int V_90 , V_40 ;
if ( V_1 -> V_11 [ V_247 ] < 0x11 )
return;
if ( V_22 != V_248 ) {
V_90 = F_58 ( V_1 , V_249 ,
V_250 ) ;
if ( V_90 != 1 )
F_81 ( L_45 ) ;
} else {
for ( V_40 = 0 ; V_40 < 3 ; V_40 ++ ) {
V_90 = F_58 ( V_1 ,
V_249 ,
V_251 ) ;
if ( V_90 == 1 )
break;
F_52 ( 1 ) ;
}
}
}
static bool F_113 ( struct V_158 * V_159 ,
enum V_58 * V_58 )
{
struct V_1 * V_1 = F_5 ( & V_159 -> V_4 ) ;
enum V_61 V_61 = F_2 ( V_1 ) -> V_61 ;
struct V_6 * V_7 = V_159 -> V_4 . V_7 ;
struct V_44 * V_45 = V_7 -> V_46 ;
T_3 V_252 = F_19 ( V_1 -> V_203 ) ;
if ( ! ( V_252 & V_246 ) )
return false ;
if ( V_61 == V_81 && F_43 ( V_7 ) && ! F_18 ( V_7 ) ) {
* V_58 = F_114 ( V_252 ) ;
} else if ( ! F_85 ( V_7 ) || V_61 == V_81 ) {
* V_58 = F_115 ( V_252 ) ;
} else {
T_3 V_253 ;
T_3 V_254 ;
int V_40 ;
switch ( V_1 -> V_203 ) {
case V_255 :
V_253 = V_256 ;
break;
case V_257 :
V_253 = V_258 ;
break;
case V_259 :
V_253 = V_260 ;
break;
default:
return true ;
}
F_116 (i) {
V_254 = F_19 ( F_117 ( V_40 ) ) ;
if ( ( V_254 & V_261 ) == V_253 ) {
* V_58 = V_40 ;
return true ;
}
}
F_31 ( L_46 ,
V_1 -> V_203 ) ;
}
return true ;
}
static void F_118 ( struct V_158 * V_159 ,
struct V_160 * V_161 )
{
struct V_1 * V_1 = F_5 ( & V_159 -> V_4 ) ;
T_3 V_252 , V_34 = 0 ;
struct V_6 * V_7 = V_159 -> V_4 . V_7 ;
struct V_44 * V_45 = V_7 -> V_46 ;
enum V_61 V_61 = F_2 ( V_1 ) -> V_61 ;
struct V_172 * V_60 = F_21 ( V_159 -> V_4 . V_60 ) ;
int V_262 ;
if ( ( V_61 == V_81 ) || ! F_85 ( V_7 ) ) {
V_252 = F_19 ( V_1 -> V_203 ) ;
if ( V_252 & V_210 )
V_34 |= V_209 ;
else
V_34 |= V_263 ;
if ( V_252 & V_212 )
V_34 |= V_211 ;
else
V_34 |= V_264 ;
} else {
V_252 = F_19 ( F_117 ( V_60 -> V_58 ) ) ;
if ( V_252 & V_265 )
V_34 |= V_209 ;
else
V_34 |= V_263 ;
if ( V_252 & V_266 )
V_34 |= V_211 ;
else
V_34 |= V_264 ;
}
V_161 -> V_171 . V_34 |= V_34 ;
V_161 -> V_182 = true ;
F_119 ( V_60 , V_161 ) ;
if ( V_61 == V_81 ) {
if ( ( F_19 ( V_198 ) & V_199 ) == V_200 )
V_161 -> V_193 = 162000 ;
else
V_161 -> V_193 = 270000 ;
}
V_262 = F_120 ( V_161 -> V_193 ,
& V_161 -> V_194 ) ;
if ( F_24 ( V_45 -> V_7 ) && V_61 != V_81 )
F_121 ( V_161 , V_262 ) ;
V_161 -> V_171 . V_184 = V_262 ;
if ( F_1 ( V_1 ) && V_45 -> V_186 . V_187 &&
V_161 -> V_185 > V_45 -> V_186 . V_187 ) {
F_31 ( L_47 ,
V_161 -> V_185 , V_45 -> V_186 . V_187 ) ;
V_45 -> V_186 . V_187 = V_161 -> V_185 ;
}
}
static bool F_122 ( struct V_6 * V_7 )
{
struct V_44 * V_45 = V_7 -> V_46 ;
return V_45 -> V_267 . V_268 ;
}
static bool F_123 ( struct V_6 * V_7 )
{
struct V_44 * V_45 = V_7 -> V_46 ;
if ( ! F_124 ( V_7 ) )
return false ;
return F_19 ( F_125 ( V_7 ) ) & V_269 ;
}
static void F_126 ( struct V_1 * V_1 ,
struct V_270 * V_271 )
{
struct V_2 * V_195 = F_2 ( V_1 ) ;
struct V_6 * V_7 = V_195 -> V_4 . V_4 . V_7 ;
struct V_44 * V_45 = V_7 -> V_46 ;
struct V_172 * V_60 = F_21 ( V_195 -> V_4 . V_4 . V_60 ) ;
T_3 V_272 = F_127 ( V_60 -> V_197 . V_273 ) ;
T_3 V_274 = F_128 ( V_60 -> V_197 . V_273 ) ;
T_1 * V_275 = ( T_1 * ) V_271 ;
unsigned int V_40 ;
F_54 ( V_272 , 0 ) ;
F_78 ( V_272 ) ;
for ( V_40 = 0 ; V_40 < V_276 ; V_40 += 4 ) {
if ( V_40 < sizeof( struct V_270 ) )
F_54 ( V_274 + V_40 , * V_275 ++ ) ;
else
F_54 ( V_274 + V_40 , 0 ) ;
}
F_54 ( V_272 , V_277 ) ;
F_78 ( V_272 ) ;
}
static void F_129 ( struct V_1 * V_1 )
{
struct V_6 * V_7 = F_3 ( V_1 ) ;
struct V_44 * V_45 = V_7 -> V_46 ;
struct V_270 V_278 ;
if ( V_1 -> V_279 )
return;
memset ( & V_278 , 0 , sizeof( V_278 ) ) ;
V_278 . V_280 . V_281 = 0 ;
V_278 . V_280 . V_282 = 0x7 ;
V_278 . V_280 . V_283 = 0x2 ;
V_278 . V_280 . V_284 = 0x8 ;
F_126 ( V_1 , & V_278 ) ;
F_54 ( F_130 ( V_7 ) , V_285 |
V_286 | V_287 ) ;
V_1 -> V_279 = true ;
}
static void F_131 ( struct V_1 * V_1 )
{
struct V_6 * V_7 = F_3 ( V_1 ) ;
struct V_44 * V_45 = V_7 -> V_46 ;
T_1 V_89 = F_38 ( V_1 , 0 ) ;
int V_93 = 0x3 ;
int V_288 = 5 ;
if ( V_1 -> V_289 [ 1 ] & V_290 )
F_58 ( V_1 , V_291 ,
V_292 &
~ V_293 ) ;
else
F_58 ( V_1 , V_291 ,
V_292 |
V_293 ) ;
F_54 ( F_132 ( V_7 ) , V_294 ) ;
F_54 ( F_133 ( V_7 ) , V_295 ) ;
F_54 ( F_134 ( V_7 ) ,
V_98 |
( V_288 << V_104 ) |
( V_93 << V_105 ) |
( V_89 << V_106 ) ) ;
}
static void F_135 ( struct V_1 * V_1 )
{
struct V_6 * V_7 = F_3 ( V_1 ) ;
struct V_44 * V_45 = V_7 -> V_46 ;
T_1 V_296 = 0x1f ;
T_1 V_297 = 1 ;
T_1 V_298 = 0x0 ;
const T_1 V_299 = V_300 ;
if ( V_1 -> V_289 [ 1 ] & V_290 ) {
V_298 |= V_301 ;
V_298 |= V_302 ;
V_298 |= V_303 ;
V_298 |= V_304 ;
} else
V_298 |= V_305 ;
F_54 ( F_125 ( V_7 ) , V_298 |
( F_49 ( V_7 ) ? 0 : V_299 ) |
V_296 << V_306 |
V_297 << V_307 |
V_269 ) ;
}
static bool F_136 ( struct V_1 * V_1 )
{
struct V_2 * V_195 = F_2 ( V_1 ) ;
struct V_6 * V_7 = V_195 -> V_4 . V_4 . V_7 ;
struct V_44 * V_45 = V_7 -> V_46 ;
struct V_59 * V_60 = V_195 -> V_4 . V_4 . V_60 ;
struct V_172 * V_172 = F_21 ( V_60 ) ;
struct V_308 * V_309 = F_137 ( V_60 -> V_310 ) -> V_309 ;
struct V_158 * V_158 = & F_2 ( V_1 ) -> V_4 ;
V_45 -> V_267 . V_311 = false ;
if ( ! F_124 ( V_7 ) ) {
F_31 ( L_48 ) ;
return false ;
}
if ( ( V_158 -> type != V_5 ) ||
( V_195 -> V_61 != V_81 ) ) {
F_31 ( L_49 ) ;
return false ;
}
if ( ! V_312 ) {
F_31 ( L_50 ) ;
return false ;
}
V_60 = V_195 -> V_4 . V_4 . V_60 ;
if ( V_60 == NULL ) {
F_31 ( L_51 ) ;
return false ;
}
V_172 = F_21 ( V_60 ) ;
if ( ! F_138 ( V_60 ) ) {
F_31 ( L_51 ) ;
return false ;
}
V_309 = F_137 ( V_60 -> V_310 ) -> V_309 ;
if ( V_309 -> V_313 != V_314 ||
V_309 -> V_315 == V_316 ) {
F_31 ( L_52 ) ;
return false ;
}
if ( F_19 ( F_139 ( V_172 -> V_58 ) ) & V_317 ) {
F_31 ( L_53 ) ;
return false ;
}
if ( F_19 ( F_140 ( V_172 -> V_197 . V_273 ) ) &
V_318 ) {
F_31 ( L_54 ) ;
return false ;
}
if ( V_172 -> V_197 . V_171 . V_34 & V_319 ) {
F_31 ( L_55 ) ;
return false ;
}
V_45 -> V_267 . V_311 = true ;
return true ;
}
static void F_141 ( struct V_1 * V_1 )
{
struct V_6 * V_7 = F_3 ( V_1 ) ;
if ( ! F_136 ( V_1 ) ||
F_123 ( V_7 ) )
return;
F_129 ( V_1 ) ;
F_131 ( V_1 ) ;
F_135 ( V_1 ) ;
}
void F_142 ( struct V_1 * V_1 )
{
struct V_6 * V_7 = F_3 ( V_1 ) ;
if ( F_136 ( V_1 ) &&
! F_123 ( V_7 ) )
F_141 ( V_1 ) ;
}
void F_143 ( struct V_1 * V_1 )
{
struct V_6 * V_7 = F_3 ( V_1 ) ;
struct V_44 * V_45 = V_7 -> V_46 ;
if ( ! F_123 ( V_7 ) )
return;
F_54 ( F_125 ( V_7 ) ,
F_19 ( F_125 ( V_7 ) ) & ~ V_269 ) ;
if ( F_87 ( ( F_19 ( F_144 ( V_7 ) ) &
V_320 ) == 0 , 2000 , 10 ) )
F_37 ( L_56 ) ;
}
void F_145 ( struct V_6 * V_7 )
{
struct V_158 * V_159 ;
struct V_1 * V_1 = NULL ;
F_146 (encoder, &dev->mode_config.encoder_list, base.head)
if ( V_159 -> type == V_5 ) {
V_1 = F_5 ( & V_159 -> V_4 ) ;
if ( ! F_122 ( V_7 ) )
return;
if ( ! F_136 ( V_1 ) )
F_143 ( V_1 ) ;
else
if ( ! F_123 ( V_7 ) )
F_141 ( V_1 ) ;
}
}
static void F_147 ( struct V_158 * V_159 )
{
struct V_1 * V_1 = F_5 ( & V_159 -> V_4 ) ;
enum V_61 V_61 = F_2 ( V_1 ) -> V_61 ;
struct V_6 * V_7 = V_159 -> V_4 . V_7 ;
F_62 ( V_1 ) ;
F_107 ( V_1 ) ;
F_112 ( V_1 , V_321 ) ;
F_104 ( V_1 ) ;
if ( ! ( V_61 == V_81 || F_18 ( V_7 ) ) )
F_148 ( V_1 ) ;
}
static void F_149 ( struct V_158 * V_159 )
{
struct V_1 * V_1 = F_5 ( & V_159 -> V_4 ) ;
enum V_61 V_61 = F_2 ( V_1 ) -> V_61 ;
struct V_6 * V_7 = V_159 -> V_4 . V_7 ;
if ( V_61 == V_81 || F_18 ( V_7 ) ) {
F_148 ( V_1 ) ;
if ( ! F_18 ( V_7 ) )
F_111 ( V_1 ) ;
}
}
static void F_150 ( struct V_158 * V_159 )
{
struct V_1 * V_1 = F_5 ( & V_159 -> V_4 ) ;
struct V_6 * V_7 = V_159 -> V_4 . V_7 ;
struct V_44 * V_45 = V_7 -> V_46 ;
T_1 V_322 = F_19 ( V_1 -> V_203 ) ;
if ( F_53 ( V_322 & V_246 ) )
return;
F_62 ( V_1 ) ;
F_112 ( V_1 , V_248 ) ;
F_151 ( V_1 ) ;
F_102 ( V_1 ) ;
F_64 ( V_1 , true ) ;
F_152 ( V_1 ) ;
F_153 ( V_1 ) ;
}
static void F_154 ( struct V_158 * V_159 )
{
struct V_1 * V_1 = F_5 ( & V_159 -> V_4 ) ;
F_150 ( V_159 ) ;
F_105 ( V_1 ) ;
}
static void F_155 ( struct V_158 * V_159 )
{
struct V_1 * V_1 = F_5 ( & V_159 -> V_4 ) ;
F_105 ( V_1 ) ;
}
static void F_156 ( struct V_158 * V_159 )
{
struct V_1 * V_1 = F_5 ( & V_159 -> V_4 ) ;
struct V_2 * V_323 = F_2 ( V_1 ) ;
if ( V_323 -> V_61 == V_81 )
F_109 ( V_1 ) ;
}
static void F_157 ( struct V_158 * V_159 )
{
struct V_1 * V_1 = F_5 ( & V_159 -> V_4 ) ;
struct V_2 * V_323 = F_2 ( V_1 ) ;
struct V_6 * V_7 = V_159 -> V_4 . V_7 ;
struct V_44 * V_45 = V_7 -> V_46 ;
struct V_172 * V_172 = F_21 ( V_159 -> V_4 . V_60 ) ;
enum V_324 V_61 = F_158 ( V_323 ) ;
int V_58 = V_172 -> V_58 ;
struct V_325 V_326 ;
T_3 V_298 ;
F_98 ( & V_45 -> V_327 ) ;
V_298 = F_159 ( V_45 , V_58 , F_160 ( V_61 ) ) ;
V_298 = 0 ;
if ( V_58 )
V_298 |= ( 1 << 21 ) ;
else
V_298 &= ~ ( 1 << 21 ) ;
V_298 |= 0x001000c4 ;
F_161 ( V_45 , V_58 , F_162 ( V_61 ) , V_298 ) ;
F_161 ( V_45 , V_58 , F_163 ( V_61 ) , 0x00760018 ) ;
F_161 ( V_45 , V_58 , F_164 ( V_61 ) , 0x00400888 ) ;
F_99 ( & V_45 -> V_327 ) ;
if ( F_1 ( V_1 ) ) {
F_165 ( V_7 , V_1 , & V_326 ) ;
F_166 ( V_7 , V_1 ,
& V_326 ) ;
}
F_150 ( V_159 ) ;
F_167 ( V_45 , V_323 ) ;
}
static void F_168 ( struct V_158 * V_159 )
{
struct V_2 * V_323 = F_169 ( & V_159 -> V_4 ) ;
struct V_6 * V_7 = V_159 -> V_4 . V_7 ;
struct V_44 * V_45 = V_7 -> V_46 ;
struct V_172 * V_172 =
F_21 ( V_159 -> V_4 . V_60 ) ;
enum V_324 V_61 = F_158 ( V_323 ) ;
int V_58 = V_172 -> V_58 ;
F_98 ( & V_45 -> V_327 ) ;
F_161 ( V_45 , V_58 , F_170 ( V_61 ) ,
V_328 |
V_329 ) ;
F_161 ( V_45 , V_58 , F_171 ( V_61 ) ,
V_330 |
V_331 |
( 1 << V_332 ) |
V_333 ) ;
F_161 ( V_45 , V_58 , F_172 ( V_61 ) , 0x00750f00 ) ;
F_161 ( V_45 , V_58 , F_173 ( V_61 ) , 0x00001500 ) ;
F_161 ( V_45 , V_58 , F_174 ( V_61 ) , 0x40400000 ) ;
F_99 ( & V_45 -> V_327 ) ;
}
static bool
F_175 ( struct V_1 * V_1 , T_4 V_114 ,
T_2 * V_86 , int V_91 )
{
int V_90 , V_40 ;
for ( V_40 = 0 ; V_40 < 3 ; V_40 ++ ) {
V_90 = F_59 ( V_1 , V_114 , V_86 ,
V_91 ) ;
if ( V_90 == V_91 )
return true ;
F_52 ( 1 ) ;
}
return false ;
}
static bool
F_176 ( struct V_1 * V_1 , T_2 V_334 [ V_335 ] )
{
return F_175 ( V_1 ,
V_336 ,
V_334 ,
V_335 ) ;
}
static T_2
F_177 ( struct V_1 * V_1 )
{
struct V_6 * V_7 = F_3 ( V_1 ) ;
enum V_61 V_61 = F_2 ( V_1 ) -> V_61 ;
if ( F_18 ( V_7 ) || F_49 ( V_7 ) )
return V_337 ;
else if ( F_43 ( V_7 ) && V_61 == V_81 )
return V_338 ;
else if ( F_85 ( V_7 ) && V_61 != V_81 )
return V_337 ;
else
return V_338 ;
}
static T_2
F_178 ( struct V_1 * V_1 , T_2 V_339 )
{
struct V_6 * V_7 = F_3 ( V_1 ) ;
enum V_61 V_61 = F_2 ( V_1 ) -> V_61 ;
if ( F_49 ( V_7 ) ) {
switch ( V_339 & V_340 ) {
case V_341 :
case V_342 :
return V_343 ;
case V_338 :
return V_344 ;
case V_337 :
default:
return V_345 ;
}
} else if ( F_70 ( V_7 ) ) {
switch ( V_339 & V_340 ) {
case V_341 :
return V_346 ;
case V_342 :
return V_343 ;
case V_338 :
return V_344 ;
case V_337 :
default:
return V_345 ;
}
} else if ( F_18 ( V_7 ) ) {
switch ( V_339 & V_340 ) {
case V_341 :
return V_346 ;
case V_342 :
return V_343 ;
case V_338 :
return V_344 ;
case V_337 :
default:
return V_345 ;
}
} else if ( F_43 ( V_7 ) && V_61 == V_81 ) {
switch ( V_339 & V_340 ) {
case V_341 :
return V_343 ;
case V_342 :
case V_338 :
return V_344 ;
default:
return V_345 ;
}
} else {
switch ( V_339 & V_340 ) {
case V_341 :
return V_343 ;
case V_342 :
return V_343 ;
case V_338 :
return V_344 ;
case V_337 :
default:
return V_345 ;
}
}
}
static T_1 F_179 ( struct V_1 * V_1 )
{
struct V_6 * V_7 = F_3 ( V_1 ) ;
struct V_44 * V_45 = V_7 -> V_46 ;
struct V_2 * V_323 = F_2 ( V_1 ) ;
struct V_172 * V_172 =
F_21 ( V_323 -> V_4 . V_4 . V_60 ) ;
unsigned long V_347 , V_348 ,
V_349 ;
T_2 V_350 = V_1 -> V_350 [ 0 ] ;
enum V_324 V_61 = F_158 ( V_323 ) ;
int V_58 = V_172 -> V_58 ;
switch ( V_350 & V_351 ) {
case V_345 :
V_348 = 0x0004000 ;
switch ( V_350 & V_340 ) {
case V_341 :
V_347 = 0x2B405555 ;
V_349 = 0x552AB83A ;
break;
case V_342 :
V_347 = 0x2B404040 ;
V_349 = 0x5548B83A ;
break;
case V_338 :
V_347 = 0x2B245555 ;
V_349 = 0x5560B83A ;
break;
case V_337 :
V_347 = 0x2B405555 ;
V_349 = 0x5598DA3A ;
break;
default:
return 0 ;
}
break;
case V_344 :
V_348 = 0x0002000 ;
switch ( V_350 & V_340 ) {
case V_341 :
V_347 = 0x2B404040 ;
V_349 = 0x5552B83A ;
break;
case V_342 :
V_347 = 0x2B404848 ;
V_349 = 0x5580B83A ;
break;
case V_338 :
V_347 = 0x2B404040 ;
V_349 = 0x55ADDA3A ;
break;
default:
return 0 ;
}
break;
case V_343 :
V_348 = 0x0000000 ;
switch ( V_350 & V_340 ) {
case V_341 :
V_347 = 0x2B305555 ;
V_349 = 0x5570B83A ;
break;
case V_342 :
V_347 = 0x2B2B4040 ;
V_349 = 0x55ADDA3A ;
break;
default:
return 0 ;
}
break;
case V_346 :
V_348 = 0x0006000 ;
switch ( V_350 & V_340 ) {
case V_341 :
V_347 = 0x1B405555 ;
V_349 = 0x55ADDA3A ;
break;
default:
return 0 ;
}
break;
default:
return 0 ;
}
F_98 ( & V_45 -> V_327 ) ;
F_161 ( V_45 , V_58 , F_180 ( V_61 ) , 0x00000000 ) ;
F_161 ( V_45 , V_58 , F_181 ( V_61 ) , V_347 ) ;
F_161 ( V_45 , V_58 , F_182 ( V_61 ) ,
V_349 ) ;
F_161 ( V_45 , V_58 , F_183 ( V_61 ) , 0x0C782040 ) ;
F_161 ( V_45 , V_58 , F_184 ( V_61 ) , 0x00030000 ) ;
F_161 ( V_45 , V_58 , F_185 ( V_61 ) , V_348 ) ;
F_161 ( V_45 , V_58 , F_180 ( V_61 ) , 0x80000000 ) ;
F_99 ( & V_45 -> V_327 ) ;
return 0 ;
}
static void
F_186 ( struct V_1 * V_1 ,
const T_2 V_334 [ V_335 ] )
{
T_2 V_41 = 0 ;
T_2 V_352 = 0 ;
int V_353 ;
T_2 V_354 ;
T_2 V_355 ;
for ( V_353 = 0 ; V_353 < V_1 -> V_175 ; V_353 ++ ) {
T_2 V_356 = F_187 ( V_334 , V_353 ) ;
T_2 V_357 = F_188 ( V_334 , V_353 ) ;
if ( V_356 > V_41 )
V_41 = V_356 ;
if ( V_357 > V_352 )
V_352 = V_357 ;
}
V_354 = F_177 ( V_1 ) ;
if ( V_41 >= V_354 )
V_41 = V_354 | V_358 ;
V_355 = F_178 ( V_1 , V_41 ) ;
if ( V_352 >= V_355 )
V_352 = V_355 | V_359 ;
for ( V_353 = 0 ; V_353 < 4 ; V_353 ++ )
V_1 -> V_350 [ V_353 ] = V_41 | V_352 ;
}
static T_1
F_189 ( T_2 V_350 )
{
T_1 V_360 = 0 ;
switch ( V_350 & V_340 ) {
case V_341 :
default:
V_360 |= V_205 ;
break;
case V_342 :
V_360 |= V_361 ;
break;
case V_338 :
V_360 |= V_362 ;
break;
case V_337 :
V_360 |= V_363 ;
break;
}
switch ( V_350 & V_351 ) {
case V_345 :
default:
V_360 |= V_206 ;
break;
case V_344 :
V_360 |= V_364 ;
break;
case V_343 :
V_360 |= V_365 ;
break;
case V_346 :
V_360 |= V_366 ;
break;
}
return V_360 ;
}
static T_1
F_190 ( T_2 V_350 )
{
int V_360 = V_350 & ( V_340 |
V_351 ) ;
switch ( V_360 ) {
case V_341 | V_345 :
case V_342 | V_345 :
return V_367 ;
case V_341 | V_344 :
return V_368 ;
case V_341 | V_343 :
case V_342 | V_343 :
return V_369 ;
case V_342 | V_344 :
case V_338 | V_344 :
return V_370 ;
case V_338 | V_345 :
case V_337 | V_345 :
return V_371 ;
default:
F_31 ( L_57
L_58 , V_360 ) ;
return V_367 ;
}
}
static T_1
F_191 ( T_2 V_350 )
{
int V_360 = V_350 & ( V_340 |
V_351 ) ;
switch ( V_360 ) {
case V_341 | V_345 :
return V_372 ;
case V_341 | V_344 :
return V_373 ;
case V_341 | V_343 :
return V_374 ;
case V_342 | V_345 :
return V_375 ;
case V_342 | V_344 :
return V_376 ;
case V_338 | V_345 :
return V_377 ;
case V_338 | V_344 :
return V_378 ;
default:
F_31 ( L_57
L_58 , V_360 ) ;
return V_379 ;
}
}
static T_1
F_192 ( T_2 V_350 )
{
int V_360 = V_350 & ( V_340 |
V_351 ) ;
switch ( V_360 ) {
case V_341 | V_345 :
return V_380 ;
case V_341 | V_344 :
return V_381 ;
case V_341 | V_343 :
return V_382 ;
case V_341 | V_346 :
return V_383 ;
case V_342 | V_345 :
return V_384 ;
case V_342 | V_344 :
return V_385 ;
case V_342 | V_343 :
return V_386 ;
case V_338 | V_345 :
return V_387 ;
case V_338 | V_344 :
return V_388 ;
default:
F_31 ( L_57
L_58 , V_360 ) ;
return V_380 ;
}
}
static T_1
F_193 ( T_2 V_350 )
{
int V_360 = V_350 & ( V_340 |
V_351 ) ;
switch ( V_360 ) {
case V_341 | V_345 :
return V_389 ;
case V_341 | V_344 :
return V_390 ;
case V_341 | V_343 :
return V_391 ;
case V_342 | V_345 :
return V_392 ;
case V_342 | V_344 :
return V_393 ;
case V_342 | V_343 :
return V_394 ;
case V_338 | V_345 :
return V_395 ;
case V_338 | V_344 :
return V_396 ;
case V_337 | V_345 :
return V_397 ;
default:
F_31 ( L_57
L_58 , V_360 ) ;
return V_389 ;
}
}
static void
F_194 ( struct V_1 * V_1 , T_1 * V_201 )
{
struct V_2 * V_3 = F_2 ( V_1 ) ;
enum V_61 V_61 = V_3 -> V_61 ;
struct V_6 * V_7 = V_3 -> V_4 . V_4 . V_7 ;
T_1 V_360 , V_217 ;
T_2 V_350 = V_1 -> V_350 [ 0 ] ;
if ( F_49 ( V_7 ) ) {
V_360 = F_193 ( V_350 ) ;
V_217 = V_398 ;
} else if ( F_70 ( V_7 ) ) {
V_360 = F_192 ( V_350 ) ;
V_217 = V_398 ;
} else if ( F_18 ( V_7 ) ) {
V_360 = F_179 ( V_1 ) ;
V_217 = 0 ;
} else if ( F_43 ( V_7 ) && V_61 == V_81 ) {
V_360 = F_191 ( V_350 ) ;
V_217 = V_399 ;
} else if ( F_42 ( V_7 ) && V_61 == V_81 ) {
V_360 = F_190 ( V_350 ) ;
V_217 = V_400 ;
} else {
V_360 = F_189 ( V_350 ) ;
V_217 = V_401 | V_402 ;
}
F_31 ( L_59 , V_360 ) ;
* V_201 = ( * V_201 & ~ V_217 ) | V_360 ;
}
static bool
F_195 ( struct V_1 * V_1 ,
T_1 * V_201 ,
T_2 V_403 )
{
struct V_2 * V_3 = F_2 ( V_1 ) ;
struct V_6 * V_7 = V_3 -> V_4 . V_4 . V_7 ;
struct V_44 * V_45 = V_7 -> V_46 ;
enum V_61 V_61 = V_3 -> V_61 ;
T_2 V_404 [ sizeof( V_1 -> V_350 ) + 1 ] ;
int V_90 , V_405 ;
if ( F_39 ( V_7 ) ) {
T_1 V_406 = F_19 ( F_196 ( V_61 ) ) ;
if ( V_403 & V_407 )
V_406 |= V_408 ;
else
V_406 &= ~ V_408 ;
V_406 &= ~ V_409 ;
switch ( V_403 & V_410 ) {
case V_411 :
V_406 |= V_412 ;
break;
case V_413 :
V_406 |= V_414 ;
break;
case V_415 :
V_406 |= V_416 ;
break;
case V_417 :
V_406 |= V_418 ;
break;
}
F_54 ( F_196 ( V_61 ) , V_406 ) ;
} else if ( F_85 ( V_7 ) && ( F_43 ( V_7 ) || V_61 != V_81 ) ) {
* V_201 &= ~ V_419 ;
switch ( V_403 & V_410 ) {
case V_411 :
* V_201 |= V_213 ;
break;
case V_413 :
* V_201 |= V_420 ;
break;
case V_415 :
* V_201 |= V_421 ;
break;
case V_417 :
F_37 ( L_60 ) ;
* V_201 |= V_421 ;
break;
}
} else {
* V_201 &= ~ V_422 ;
switch ( V_403 & V_410 ) {
case V_411 :
* V_201 |= V_215 ;
break;
case V_413 :
* V_201 |= V_423 ;
break;
case V_415 :
* V_201 |= V_424 ;
break;
case V_417 :
F_37 ( L_60 ) ;
* V_201 |= V_424 ;
break;
}
}
F_54 ( V_1 -> V_203 , * V_201 ) ;
F_78 ( V_1 -> V_203 ) ;
V_404 [ 0 ] = V_403 ;
if ( ( V_403 & V_410 ) ==
V_411 ) {
V_405 = 1 ;
} else {
memcpy ( V_404 + 1 , V_1 -> V_350 , V_1 -> V_175 ) ;
V_405 = V_1 -> V_175 + 1 ;
}
V_90 = F_56 ( V_1 , V_425 ,
V_404 , V_405 ) ;
return V_90 == V_405 ;
}
static bool
F_197 ( struct V_1 * V_1 , T_1 * V_201 ,
T_2 V_403 )
{
memset ( V_1 -> V_350 , 0 , sizeof( V_1 -> V_350 ) ) ;
F_194 ( V_1 , V_201 ) ;
return F_195 ( V_1 , V_201 , V_403 ) ;
}
static bool
F_198 ( struct V_1 * V_1 , T_1 * V_201 ,
const T_2 V_334 [ V_335 ] )
{
struct V_2 * V_3 = F_2 ( V_1 ) ;
struct V_6 * V_7 = V_3 -> V_4 . V_4 . V_7 ;
struct V_44 * V_45 = V_7 -> V_46 ;
int V_90 ;
F_186 ( V_1 , V_334 ) ;
F_194 ( V_1 , V_201 ) ;
F_54 ( V_1 -> V_203 , * V_201 ) ;
F_78 ( V_1 -> V_203 ) ;
V_90 = F_56 ( V_1 , V_426 ,
V_1 -> V_350 ,
V_1 -> V_175 ) ;
return V_90 == V_1 -> V_175 ;
}
static void F_199 ( struct V_1 * V_1 )
{
struct V_2 * V_3 = F_2 ( V_1 ) ;
struct V_6 * V_7 = V_3 -> V_4 . V_4 . V_7 ;
struct V_44 * V_45 = V_7 -> V_46 ;
enum V_61 V_61 = V_3 -> V_61 ;
T_1 V_298 ;
if ( ! F_39 ( V_7 ) )
return;
V_298 = F_19 ( F_196 ( V_61 ) ) ;
V_298 &= ~ V_409 ;
V_298 |= V_427 ;
F_54 ( F_196 ( V_61 ) , V_298 ) ;
if ( V_61 == V_81 )
return;
if ( F_200 ( ( F_19 ( F_201 ( V_61 ) ) & V_428 ) ,
1 ) )
F_37 ( L_61 ) ;
}
void
F_151 ( struct V_1 * V_1 )
{
struct V_429 * V_159 = & F_2 ( V_1 ) -> V_4 . V_4 ;
struct V_6 * V_7 = V_159 -> V_7 ;
int V_40 ;
T_2 V_430 ;
int V_431 , V_432 ;
T_1 V_201 = V_1 -> V_201 ;
T_2 V_433 [ 2 ] ;
if ( F_39 ( V_7 ) )
F_202 ( V_159 ) ;
V_433 [ 0 ] = V_1 -> V_162 ;
V_433 [ 1 ] = V_1 -> V_175 ;
if ( F_84 ( V_1 -> V_11 ) )
V_433 [ 1 ] |= V_434 ;
F_56 ( V_1 , V_435 , V_433 , 2 ) ;
V_433 [ 0 ] = 0 ;
V_433 [ 1 ] = V_436 ;
F_56 ( V_1 , V_437 , V_433 , 2 ) ;
V_201 |= V_246 ;
if ( ! F_197 ( V_1 , & V_201 ,
V_413 |
V_407 ) ) {
F_37 ( L_62 ) ;
return;
}
V_430 = 0xff ;
V_431 = 0 ;
V_432 = 0 ;
for (; ; ) {
T_2 V_334 [ V_335 ] ;
F_203 ( V_1 -> V_11 ) ;
if ( ! F_176 ( V_1 , V_334 ) ) {
F_37 ( L_63 ) ;
break;
}
if ( F_204 ( V_334 , V_1 -> V_175 ) ) {
F_31 ( L_64 ) ;
break;
}
for ( V_40 = 0 ; V_40 < V_1 -> V_175 ; V_40 ++ )
if ( ( V_1 -> V_350 [ V_40 ] & V_358 ) == 0 )
break;
if ( V_40 == V_1 -> V_175 ) {
++ V_432 ;
if ( V_432 == 5 ) {
F_37 ( L_65 ) ;
break;
}
F_197 ( V_1 , & V_201 ,
V_413 |
V_407 ) ;
V_431 = 0 ;
continue;
}
if ( ( V_1 -> V_350 [ 0 ] & V_340 ) == V_430 ) {
++ V_431 ;
if ( V_431 == 5 ) {
F_37 ( L_66 ) ;
break;
}
} else
V_431 = 0 ;
V_430 = V_1 -> V_350 [ 0 ] & V_340 ;
if ( ! F_198 ( V_1 , & V_201 , V_334 ) ) {
F_37 ( L_67 ) ;
break;
}
}
V_1 -> V_201 = V_201 ;
}
void
F_152 ( struct V_1 * V_1 )
{
bool V_438 = false ;
int V_439 , V_440 ;
T_1 V_201 = V_1 -> V_201 ;
if ( ! F_195 ( V_1 , & V_201 ,
V_415 |
V_407 ) ) {
F_37 ( L_68 ) ;
return;
}
V_439 = 0 ;
V_440 = 0 ;
V_438 = false ;
for (; ; ) {
T_2 V_334 [ V_335 ] ;
if ( V_440 > 5 ) {
F_37 ( L_69 ) ;
break;
}
F_205 ( V_1 -> V_11 ) ;
if ( ! F_176 ( V_1 , V_334 ) ) {
F_37 ( L_63 ) ;
break;
}
if ( ! F_204 ( V_334 , V_1 -> V_175 ) ) {
F_151 ( V_1 ) ;
F_195 ( V_1 , & V_201 ,
V_415 |
V_407 ) ;
V_440 ++ ;
continue;
}
if ( F_206 ( V_334 , V_1 -> V_175 ) ) {
V_438 = true ;
break;
}
if ( V_439 > 5 ) {
F_148 ( V_1 ) ;
F_151 ( V_1 ) ;
F_195 ( V_1 , & V_201 ,
V_415 |
V_407 ) ;
V_439 = 0 ;
V_440 ++ ;
continue;
}
if ( ! F_198 ( V_1 , & V_201 , V_334 ) ) {
F_37 ( L_67 ) ;
break;
}
++ V_439 ;
}
F_199 ( V_1 ) ;
V_1 -> V_201 = V_201 ;
if ( V_438 )
F_31 ( L_70 ) ;
}
void F_153 ( struct V_1 * V_1 )
{
F_195 ( V_1 , & V_1 -> V_201 ,
V_411 ) ;
}
static void
F_148 ( struct V_1 * V_1 )
{
struct V_2 * V_3 = F_2 ( V_1 ) ;
enum V_61 V_61 = V_3 -> V_61 ;
struct V_6 * V_7 = V_3 -> V_4 . V_4 . V_7 ;
struct V_44 * V_45 = V_7 -> V_46 ;
struct V_172 * V_172 =
F_21 ( V_3 -> V_4 . V_4 . V_60 ) ;
T_1 V_201 = V_1 -> V_201 ;
if ( F_39 ( V_7 ) )
return;
if ( F_53 ( ( F_19 ( V_1 -> V_203 ) & V_246 ) == 0 ) )
return;
F_31 ( L_41 ) ;
if ( F_85 ( V_7 ) && ( F_43 ( V_7 ) || V_61 != V_81 ) ) {
V_201 &= ~ V_419 ;
F_54 ( V_1 -> V_203 , V_201 | V_441 ) ;
} else {
V_201 &= ~ V_422 ;
F_54 ( V_1 -> V_203 , V_201 | V_442 ) ;
}
F_78 ( V_1 -> V_203 ) ;
F_207 ( V_7 , V_172 -> V_58 ) ;
if ( F_208 ( V_7 ) &&
F_19 ( V_1 -> V_203 ) & V_216 ) {
struct V_59 * V_60 = V_3 -> V_4 . V_4 . V_60 ;
V_201 &= ~ V_216 ;
F_54 ( V_1 -> V_203 , V_201 ) ;
if ( F_53 ( V_60 == NULL ) ) {
F_78 ( V_1 -> V_203 ) ;
F_52 ( 50 ) ;
} else
F_207 ( V_7 , V_172 -> V_58 ) ;
}
V_201 &= ~ V_208 ;
F_54 ( V_1 -> V_203 , V_201 & ~ V_246 ) ;
F_78 ( V_1 -> V_203 ) ;
F_52 ( V_1 -> V_443 ) ;
}
static bool
F_209 ( struct V_1 * V_1 )
{
struct V_2 * V_195 = F_2 ( V_1 ) ;
struct V_6 * V_7 = V_195 -> V_4 . V_4 . V_7 ;
struct V_44 * V_45 = V_7 -> V_46 ;
char V_444 [ sizeof( V_1 -> V_11 ) * 3 ] ;
if ( F_175 ( V_1 , 0x000 , V_1 -> V_11 ,
sizeof( V_1 -> V_11 ) ) == 0 )
return false ;
F_210 ( V_1 -> V_11 , sizeof( V_1 -> V_11 ) ,
32 , 1 , V_444 , sizeof( V_444 ) , false ) ;
F_31 ( L_71 , V_444 ) ;
if ( V_1 -> V_11 [ V_247 ] == 0 )
return false ;
memset ( V_1 -> V_289 , 0 , sizeof( V_1 -> V_289 ) ) ;
if ( F_1 ( V_1 ) ) {
F_175 ( V_1 , V_445 ,
V_1 -> V_289 ,
sizeof( V_1 -> V_289 ) ) ;
if ( V_1 -> V_289 [ 0 ] & V_446 ) {
V_45 -> V_267 . V_268 = true ;
F_31 ( L_72 ) ;
}
}
if ( ! ( V_1 -> V_11 [ V_142 ] &
V_143 ) )
return true ;
if ( V_1 -> V_11 [ V_247 ] == 0x10 )
return true ;
if ( F_175 ( V_1 , V_447 ,
V_1 -> V_448 ,
V_449 ) == 0 )
return false ;
return true ;
}
static void
F_211 ( struct V_1 * V_1 )
{
T_5 V_404 [ 3 ] ;
if ( ! ( V_1 -> V_11 [ V_450 ] & V_451 ) )
return;
F_62 ( V_1 ) ;
if ( F_175 ( V_1 , V_452 , V_404 , 3 ) )
F_31 ( L_73 ,
V_404 [ 0 ] , V_404 [ 1 ] , V_404 [ 2 ] ) ;
if ( F_175 ( V_1 , V_453 , V_404 , 3 ) )
F_31 ( L_74 ,
V_404 [ 0 ] , V_404 [ 1 ] , V_404 [ 2 ] ) ;
F_64 ( V_1 , false ) ;
}
static bool
F_212 ( struct V_1 * V_1 , T_5 * V_454 )
{
int V_90 ;
V_90 = F_175 ( V_1 ,
V_455 ,
V_454 , 1 ) ;
if ( ! V_90 )
return false ;
return true ;
}
static void
F_213 ( struct V_1 * V_1 )
{
F_58 ( V_1 , V_456 , V_457 ) ;
}
void
F_214 ( struct V_1 * V_1 )
{
struct V_158 * V_158 = & F_2 ( V_1 ) -> V_4 ;
T_5 V_454 ;
T_5 V_334 [ V_335 ] ;
if ( ! V_158 -> V_458 )
return;
if ( F_53 ( ! V_158 -> V_4 . V_60 ) )
return;
if ( ! F_176 ( V_1 , V_334 ) ) {
return;
}
if ( ! F_209 ( V_1 ) ) {
return;
}
if ( V_1 -> V_11 [ V_247 ] >= 0x11 &&
F_212 ( V_1 , & V_454 ) ) {
F_58 ( V_1 ,
V_455 ,
V_454 ) ;
if ( V_454 & V_459 )
F_213 ( V_1 ) ;
if ( V_454 & ( V_460 | V_461 ) )
F_81 ( L_75 ) ;
}
if ( ! F_206 ( V_334 , V_1 -> V_175 ) ) {
F_31 ( L_76 ,
F_215 ( & V_158 -> V_4 ) ) ;
F_151 ( V_1 ) ;
F_152 ( V_1 ) ;
F_153 ( V_1 ) ;
}
}
static enum V_462
F_216 ( struct V_1 * V_1 )
{
T_2 * V_11 = V_1 -> V_11 ;
T_2 type ;
if ( ! F_209 ( V_1 ) )
return V_463 ;
if ( ! ( V_11 [ V_142 ] & V_143 ) )
return V_464 ;
if ( V_1 -> V_11 [ V_247 ] >= 0x11 &&
V_1 -> V_448 [ 0 ] & V_465 ) {
T_2 V_466 ;
if ( ! F_175 ( V_1 , V_467 ,
& V_466 , 1 ) )
return V_468 ;
return F_217 ( V_466 ) ? V_464
: V_463 ;
}
if ( F_218 ( & V_1 -> V_129 ) )
return V_464 ;
if ( V_1 -> V_11 [ V_247 ] >= 0x11 ) {
type = V_1 -> V_448 [ 0 ] & V_469 ;
if ( type == V_470 ||
type == V_471 )
return V_468 ;
} else {
type = V_1 -> V_11 [ V_142 ] &
V_472 ;
if ( type == V_473 ||
type == V_474 )
return V_468 ;
}
F_31 ( L_77 ) ;
return V_463 ;
}
static enum V_462
F_219 ( struct V_1 * V_1 )
{
struct V_6 * V_7 = F_3 ( V_1 ) ;
struct V_44 * V_45 = V_7 -> V_46 ;
struct V_2 * V_3 = F_2 ( V_1 ) ;
enum V_462 V_77 ;
if ( F_1 ( V_1 ) ) {
V_77 = F_220 ( V_7 ) ;
if ( V_77 == V_468 )
V_77 = V_464 ;
return V_77 ;
}
if ( ! F_221 ( V_45 , V_3 ) )
return V_463 ;
return F_216 ( V_1 ) ;
}
static enum V_462
F_222 ( struct V_1 * V_1 )
{
struct V_6 * V_7 = F_3 ( V_1 ) ;
struct V_44 * V_45 = V_7 -> V_46 ;
struct V_2 * V_3 = F_2 ( V_1 ) ;
T_1 V_475 ;
if ( F_1 ( V_1 ) ) {
enum V_462 V_77 ;
V_77 = F_220 ( V_7 ) ;
if ( V_77 == V_468 )
V_77 = V_464 ;
return V_77 ;
}
if ( F_18 ( V_7 ) ) {
switch ( V_3 -> V_61 ) {
case V_67 :
V_475 = V_476 ;
break;
case V_69 :
V_475 = V_477 ;
break;
case V_478 :
V_475 = V_479 ;
break;
default:
return V_468 ;
}
} else {
switch ( V_3 -> V_61 ) {
case V_67 :
V_475 = V_480 ;
break;
case V_69 :
V_475 = V_481 ;
break;
case V_478 :
V_475 = V_482 ;
break;
default:
return V_468 ;
}
}
if ( ( F_19 ( V_483 ) & V_475 ) == 0 )
return V_463 ;
return F_216 ( V_1 ) ;
}
static struct V_484 *
F_223 ( struct V_8 * V_9 , struct V_128 * V_129 )
{
struct V_23 * V_23 = F_12 ( V_9 ) ;
if ( V_23 -> V_484 ) {
if ( F_224 ( V_23 -> V_484 ) )
return NULL ;
return F_225 ( V_23 -> V_484 ) ;
}
return F_226 ( V_9 , V_129 ) ;
}
static int
F_227 ( struct V_8 * V_9 , struct V_128 * V_129 )
{
struct V_23 * V_23 = F_12 ( V_9 ) ;
if ( V_23 -> V_484 ) {
if ( F_224 ( V_23 -> V_484 ) )
return 0 ;
return F_228 ( V_9 ,
V_23 -> V_484 ) ;
}
return F_229 ( V_9 , V_129 ) ;
}
static enum V_462
F_230 ( struct V_8 * V_9 , bool V_485 )
{
struct V_1 * V_1 = F_4 ( V_9 ) ;
struct V_2 * V_3 = F_2 ( V_1 ) ;
struct V_158 * V_158 = & V_3 -> V_4 ;
struct V_6 * V_7 = V_9 -> V_7 ;
struct V_44 * V_45 = V_7 -> V_46 ;
enum V_462 V_77 ;
struct V_484 * V_484 = NULL ;
F_92 ( V_45 ) ;
F_31 ( L_78 ,
V_9 -> V_4 . V_486 , F_231 ( V_9 ) ) ;
V_1 -> V_207 = false ;
if ( F_24 ( V_7 ) )
V_77 = F_219 ( V_1 ) ;
else
V_77 = F_222 ( V_1 ) ;
if ( V_77 != V_464 )
goto V_101;
F_211 ( V_1 ) ;
if ( V_1 -> V_487 != V_488 ) {
V_1 -> V_207 = ( V_1 -> V_487 == V_489 ) ;
} else {
V_484 = F_223 ( V_9 , & V_1 -> V_129 ) ;
if ( V_484 ) {
V_1 -> V_207 = F_232 ( V_484 ) ;
F_233 ( V_484 ) ;
}
}
if ( V_158 -> type != V_5 )
V_158 -> type = V_490 ;
V_77 = V_464 ;
V_101:
F_95 ( V_45 ) ;
return V_77 ;
}
static int F_234 ( struct V_8 * V_9 )
{
struct V_1 * V_1 = F_4 ( V_9 ) ;
struct V_23 * V_23 = F_12 ( V_9 ) ;
struct V_6 * V_7 = V_9 -> V_7 ;
int V_90 ;
V_90 = F_227 ( V_9 , & V_1 -> V_129 ) ;
if ( V_90 )
return V_90 ;
if ( F_1 ( V_1 ) && V_23 -> V_25 . V_24 ) {
struct V_21 * V_22 ;
V_22 = F_235 ( V_7 ,
V_23 -> V_25 . V_24 ) ;
if ( V_22 ) {
F_236 ( V_9 , V_22 ) ;
return 1 ;
}
}
return 0 ;
}
static bool
F_237 ( struct V_8 * V_9 )
{
struct V_1 * V_1 = F_4 ( V_9 ) ;
struct V_484 * V_484 ;
bool V_207 = false ;
V_484 = F_223 ( V_9 , & V_1 -> V_129 ) ;
if ( V_484 ) {
V_207 = F_232 ( V_484 ) ;
F_233 ( V_484 ) ;
}
return V_207 ;
}
static int
F_238 ( struct V_8 * V_9 ,
struct V_491 * V_492 ,
T_6 V_298 )
{
struct V_44 * V_45 = V_9 -> V_7 -> V_46 ;
struct V_23 * V_23 = F_12 ( V_9 ) ;
struct V_158 * V_158 = F_6 ( V_9 ) ;
struct V_1 * V_1 = F_5 ( & V_158 -> V_4 ) ;
int V_90 ;
V_90 = F_239 ( & V_9 -> V_4 , V_492 , V_298 ) ;
if ( V_90 )
return V_90 ;
if ( V_492 == V_45 -> V_493 ) {
int V_40 = V_298 ;
bool V_207 ;
if ( V_40 == V_1 -> V_487 )
return 0 ;
V_1 -> V_487 = V_40 ;
if ( V_40 == V_488 )
V_207 = F_237 ( V_9 ) ;
else
V_207 = ( V_40 == V_489 ) ;
if ( V_207 == V_1 -> V_207 )
return 0 ;
V_1 -> V_207 = V_207 ;
goto V_78;
}
if ( V_492 == V_45 -> V_494 ) {
bool V_495 = V_1 -> V_189 ;
T_1 V_496 = V_1 -> V_190 ;
switch ( V_298 ) {
case V_497 :
V_1 -> V_189 = true ;
break;
case V_498 :
V_1 -> V_189 = false ;
V_1 -> V_190 = 0 ;
break;
case V_499 :
V_1 -> V_189 = false ;
V_1 -> V_190 = V_191 ;
break;
default:
return - V_500 ;
}
if ( V_495 == V_1 -> V_189 &&
V_496 == V_1 -> V_190 )
return 0 ;
goto V_78;
}
if ( F_1 ( V_1 ) &&
V_492 == V_9 -> V_7 -> V_233 . V_501 ) {
if ( V_298 == V_502 ) {
F_31 ( L_79 ) ;
return - V_500 ;
}
if ( V_23 -> V_25 . V_183 == V_298 ) {
return 0 ;
}
V_23 -> V_25 . V_183 = V_298 ;
goto V_78;
}
return - V_500 ;
V_78:
if ( V_158 -> V_4 . V_60 )
F_240 ( V_158 -> V_4 . V_60 ) ;
return 0 ;
}
static void
F_241 ( struct V_8 * V_9 )
{
struct V_23 * V_23 = F_12 ( V_9 ) ;
if ( ! F_242 ( V_23 -> V_484 ) )
F_233 ( V_23 -> V_484 ) ;
if ( V_9 -> V_503 == V_504 )
F_243 ( & V_23 -> V_25 ) ;
F_244 ( V_9 ) ;
F_233 ( V_9 ) ;
}
void F_245 ( struct V_429 * V_159 )
{
struct V_2 * V_3 = F_169 ( V_159 ) ;
struct V_1 * V_1 = & V_3 -> V_505 ;
struct V_6 * V_7 = F_3 ( V_1 ) ;
F_246 ( & V_1 -> V_129 ) ;
F_247 ( V_159 ) ;
if ( F_1 ( V_1 ) ) {
F_248 ( & V_1 -> V_239 ) ;
F_98 ( & V_7 -> V_233 . V_234 ) ;
F_93 ( V_1 ) ;
F_99 ( & V_7 -> V_233 . V_234 ) ;
}
F_233 ( V_3 ) ;
}
static void
F_249 ( struct V_158 * V_158 )
{
struct V_1 * V_1 = F_5 ( & V_158 -> V_4 ) ;
F_214 ( V_1 ) ;
}
int
F_250 ( struct V_59 * V_60 )
{
struct V_6 * V_7 = V_60 -> V_7 ;
struct V_158 * V_158 ;
struct V_1 * V_1 ;
F_251 (dev, crtc, intel_encoder) {
V_1 = F_5 ( & V_158 -> V_4 ) ;
if ( V_158 -> type == V_490 ||
V_158 -> type == V_5 )
return V_1 -> V_203 ;
}
return - 1 ;
}
bool F_252 ( struct V_6 * V_7 , enum V_61 V_61 )
{
struct V_44 * V_45 = V_7 -> V_46 ;
union V_506 * V_507 ;
int V_40 ;
static const short V_508 [] = {
[ V_67 ] = V_509 ,
[ V_69 ] = V_510 ,
[ V_478 ] = V_511 ,
} ;
if ( V_61 == V_81 )
return true ;
if ( ! V_45 -> V_186 . V_512 )
return false ;
for ( V_40 = 0 ; V_40 < V_45 -> V_186 . V_512 ; V_40 ++ ) {
V_507 = V_45 -> V_186 . V_513 + V_40 ;
if ( V_507 -> V_514 . V_515 == V_508 [ V_61 ] &&
( V_507 -> V_514 . V_516 & V_517 ) ==
( V_518 & V_517 ) )
return true ;
}
return false ;
}
static void
F_253 ( struct V_1 * V_1 , struct V_8 * V_9 )
{
struct V_23 * V_23 = F_12 ( V_9 ) ;
F_254 ( V_9 ) ;
F_255 ( V_9 ) ;
V_1 -> V_189 = true ;
if ( F_1 ( V_1 ) ) {
F_256 ( V_9 -> V_7 ) ;
F_257 (
& V_9 -> V_4 ,
V_9 -> V_7 -> V_233 . V_501 ,
V_519 ) ;
V_23 -> V_25 . V_183 = V_519 ;
}
}
static void
F_165 ( struct V_6 * V_7 ,
struct V_1 * V_1 ,
struct V_325 * V_101 )
{
struct V_44 * V_45 = V_7 -> V_46 ;
struct V_325 V_520 , V_186 , V_521 , V_522 ;
T_3 V_523 , V_524 , V_525 , V_230 ;
int V_220 , V_526 , V_527 , V_528 ;
if ( F_24 ( V_7 ) ) {
V_220 = V_70 ;
V_526 = V_529 ;
V_527 = V_530 ;
V_528 = V_531 ;
} else {
enum V_58 V_58 = F_20 ( V_1 ) ;
V_220 = F_25 ( V_58 ) ;
V_526 = F_22 ( V_58 ) ;
V_527 = F_258 ( V_58 ) ;
V_528 = F_259 ( V_58 ) ;
}
V_230 = F_91 ( V_1 ) ;
F_54 ( V_220 , V_230 ) ;
V_523 = F_19 ( V_526 ) ;
V_524 = F_19 ( V_527 ) ;
V_525 = F_19 ( V_528 ) ;
V_520 . V_532 = ( V_523 & V_533 ) >>
V_534 ;
V_520 . V_535 = ( V_523 & V_536 ) >>
V_537 ;
V_520 . V_538 = ( V_524 & V_539 ) >>
V_540 ;
V_520 . V_541 = ( V_524 & V_542 ) >>
V_543 ;
V_520 . V_544 = ( ( V_525 & V_545 ) >>
V_546 ) * 1000 ;
F_31 ( L_80 ,
V_520 . V_532 , V_520 . V_535 , V_520 . V_538 , V_520 . V_541 , V_520 . V_544 ) ;
V_186 = V_45 -> V_186 . V_547 ;
V_521 . V_532 = 210 * 10 ;
V_521 . V_535 = 50 * 10 ;
V_521 . V_538 = 50 * 10 ;
V_521 . V_541 = 500 * 10 ;
V_521 . V_544 = ( 510 + 100 ) * 10 ;
F_31 ( L_81 ,
V_186 . V_532 , V_186 . V_535 , V_186 . V_538 , V_186 . V_541 , V_186 . V_544 ) ;
#define F_260 ( T_7 ) final.field = (max(cur.field, vbt.field) == 0 ? \
spec.field : \
max(cur.field, vbt.field))
F_260 ( V_532 ) ;
F_260 ( V_535 ) ;
F_260 ( V_538 ) ;
F_260 ( V_541 ) ;
F_260 ( V_544 ) ;
#undef F_260
#define F_261 ( T_7 ) (DIV_ROUND_UP(final.field, 10))
V_1 -> V_232 = F_261 ( V_532 ) ;
V_1 -> V_243 = F_261 ( V_535 ) ;
V_1 -> V_244 = F_261 ( V_538 ) ;
V_1 -> V_443 = F_261 ( V_541 ) ;
V_1 -> V_236 = F_261 ( V_544 ) ;
#undef F_261
F_31 ( L_82 ,
V_1 -> V_232 , V_1 -> V_443 ,
V_1 -> V_236 ) ;
F_31 ( L_83 ,
V_1 -> V_243 , V_1 -> V_244 ) ;
if ( V_101 )
* V_101 = V_522 ;
}
static void
F_166 ( struct V_6 * V_7 ,
struct V_1 * V_1 ,
struct V_325 * V_548 )
{
struct V_44 * V_45 = V_7 -> V_46 ;
T_3 V_523 , V_524 , V_525 , V_64 = 0 ;
int div = F_24 ( V_7 ) ? F_45 ( V_7 ) : F_17 ( V_7 ) ;
int V_526 , V_527 , V_528 ;
if ( F_24 ( V_7 ) ) {
V_526 = V_529 ;
V_527 = V_530 ;
V_528 = V_531 ;
} else {
enum V_58 V_58 = F_20 ( V_1 ) ;
V_526 = F_22 ( V_58 ) ;
V_527 = F_258 ( V_58 ) ;
V_528 = F_259 ( V_58 ) ;
}
V_523 = ( V_548 -> V_532 << V_534 ) |
( V_548 -> V_535 << V_537 ) ;
V_524 = ( V_548 -> V_538 << V_540 ) |
( V_548 -> V_541 << V_543 ) ;
V_525 = ( ( 100 * div ) / 2 - 1 ) << V_549 ;
V_525 |= ( F_44 ( V_548 -> V_544 , 1000 )
<< V_546 ) ;
if ( F_18 ( V_7 ) ) {
if ( F_2 ( V_1 ) -> V_61 == V_67 )
V_64 = V_66 ;
else
V_64 = V_68 ;
} else if ( F_208 ( V_7 ) || F_85 ( V_7 ) ) {
if ( F_2 ( V_1 ) -> V_61 == V_81 )
V_64 = V_550 ;
else
V_64 = V_551 ;
}
V_523 |= V_64 ;
F_54 ( V_526 , V_523 ) ;
F_54 ( V_527 , V_524 ) ;
F_54 ( V_528 , V_525 ) ;
F_31 ( L_84 ,
F_19 ( V_526 ) ,
F_19 ( V_527 ) ,
F_19 ( V_528 ) ) ;
}
static bool F_262 ( struct V_1 * V_1 ,
struct V_23 * V_23 )
{
struct V_8 * V_9 = & V_23 -> V_4 ;
struct V_2 * V_3 = F_2 ( V_1 ) ;
struct V_6 * V_7 = V_3 -> V_4 . V_4 . V_7 ;
struct V_44 * V_45 = V_7 -> V_46 ;
struct V_21 * V_24 = NULL ;
struct V_325 V_326 = { 0 } ;
bool V_552 ;
struct V_21 * V_553 ;
struct V_484 * V_484 ;
if ( ! F_1 ( V_1 ) )
return true ;
F_165 ( V_7 , V_1 , & V_326 ) ;
F_62 ( V_1 ) ;
V_552 = F_209 ( V_1 ) ;
F_64 ( V_1 , false ) ;
if ( V_552 ) {
if ( V_1 -> V_11 [ V_247 ] >= 0x11 )
V_45 -> V_554 =
V_1 -> V_11 [ V_555 ] &
V_556 ;
} else {
F_263 ( L_85 ) ;
return false ;
}
F_166 ( V_7 , V_1 ,
& V_326 ) ;
V_484 = F_226 ( V_9 , & V_1 -> V_129 ) ;
if ( V_484 ) {
if ( F_264 ( V_9 , V_484 ) ) {
F_265 ( V_9 ,
V_484 ) ;
F_266 ( V_9 , V_484 ) ;
} else {
F_233 ( V_484 ) ;
V_484 = F_267 ( - V_500 ) ;
}
} else {
V_484 = F_267 ( - V_557 ) ;
}
V_23 -> V_484 = V_484 ;
F_146 (scan, &connector->probed_modes, head) {
if ( ( V_553 -> type & V_558 ) ) {
V_24 = F_235 ( V_7 , V_553 ) ;
break;
}
}
if ( ! V_24 && V_45 -> V_186 . V_559 ) {
V_24 = F_235 ( V_7 ,
V_45 -> V_186 . V_559 ) ;
if ( V_24 )
V_24 -> type |= V_558 ;
}
F_268 ( & V_23 -> V_25 , V_24 ) ;
F_269 ( V_9 ) ;
return true ;
}
bool
F_270 ( struct V_2 * V_3 ,
struct V_23 * V_23 )
{
struct V_8 * V_9 = & V_23 -> V_4 ;
struct V_1 * V_1 = & V_3 -> V_505 ;
struct V_158 * V_158 = & V_3 -> V_4 ;
struct V_6 * V_7 = V_158 -> V_4 . V_7 ;
struct V_44 * V_45 = V_7 -> V_46 ;
enum V_61 V_61 = V_3 -> V_61 ;
const char * V_148 = NULL ;
int type , error ;
V_1 -> V_201 = F_19 ( V_1 -> V_203 ) ;
V_1 -> V_174 = V_23 ;
if ( F_252 ( V_7 , V_61 ) )
type = V_504 ;
else
type = V_560 ;
if ( type == V_504 )
V_158 -> type = V_5 ;
F_31 ( L_86 ,
type == V_504 ? L_87 : L_88 ,
F_271 ( V_61 ) ) ;
F_272 ( V_7 , V_9 , & V_561 , type ) ;
F_273 ( V_9 , & V_562 ) ;
V_9 -> V_563 = true ;
V_9 -> V_564 = 0 ;
F_274 ( & V_1 -> V_239 ,
F_96 ) ;
F_275 ( V_23 , V_158 ) ;
F_276 ( V_9 ) ;
if ( F_39 ( V_7 ) )
V_23 -> V_565 = V_566 ;
else
V_23 -> V_565 = V_567 ;
V_1 -> V_76 = V_1 -> V_203 + 0x10 ;
if ( F_39 ( V_7 ) ) {
switch ( V_3 -> V_61 ) {
case V_81 :
V_1 -> V_76 = V_96 ;
break;
case V_67 :
V_1 -> V_76 = V_568 ;
break;
case V_69 :
V_1 -> V_76 = V_569 ;
break;
case V_478 :
V_1 -> V_76 = V_570 ;
break;
default:
F_277 () ;
}
}
switch ( V_61 ) {
case V_81 :
V_158 -> V_571 = V_572 ;
V_148 = L_89 ;
break;
case V_67 :
V_158 -> V_571 = V_573 ;
V_148 = L_90 ;
break;
case V_69 :
V_158 -> V_571 = V_574 ;
V_148 = L_91 ;
break;
case V_478 :
V_158 -> V_571 = V_575 ;
V_148 = L_92 ;
break;
default:
F_277 () ;
}
error = F_65 ( V_1 , V_23 , V_148 ) ;
F_8 ( error , L_93 ,
error , F_271 ( V_61 ) ) ;
V_1 -> V_279 = false ;
if ( ! F_262 ( V_1 , V_23 ) ) {
F_246 ( & V_1 -> V_129 ) ;
if ( F_1 ( V_1 ) ) {
F_248 ( & V_1 -> V_239 ) ;
F_98 ( & V_7 -> V_233 . V_234 ) ;
F_93 ( V_1 ) ;
F_99 ( & V_7 -> V_233 . V_234 ) ;
}
F_278 ( V_9 ) ;
F_244 ( V_9 ) ;
return false ;
}
F_253 ( V_1 , V_9 ) ;
if ( F_68 ( V_7 ) && ! F_279 ( V_7 ) ) {
T_3 V_406 = F_19 ( V_576 ) ;
F_54 ( V_576 , ( V_406 & ~ 0xf ) | 0xd ) ;
}
return true ;
}
void
F_280 ( struct V_6 * V_7 , int V_203 , enum V_61 V_61 )
{
struct V_2 * V_3 ;
struct V_158 * V_158 ;
struct V_429 * V_159 ;
struct V_23 * V_23 ;
V_3 = F_281 ( sizeof( * V_3 ) , V_577 ) ;
if ( ! V_3 )
return;
V_23 = F_281 ( sizeof( * V_23 ) , V_577 ) ;
if ( ! V_23 ) {
F_233 ( V_3 ) ;
return;
}
V_158 = & V_3 -> V_4 ;
V_159 = & V_158 -> V_4 ;
F_282 ( V_7 , & V_158 -> V_4 , & V_578 ,
V_579 ) ;
V_158 -> V_580 = F_71 ;
V_158 -> V_581 = F_79 ;
V_158 -> V_582 = F_147 ;
V_158 -> V_583 = F_149 ;
V_158 -> V_565 = F_113 ;
V_158 -> V_584 = F_118 ;
if ( F_18 ( V_7 ) ) {
V_158 -> V_585 = F_168 ;
V_158 -> V_586 = F_157 ;
V_158 -> V_587 = F_155 ;
} else {
V_158 -> V_586 = F_156 ;
V_158 -> V_587 = F_154 ;
}
V_3 -> V_61 = V_61 ;
V_3 -> V_505 . V_203 = V_203 ;
V_158 -> type = V_490 ;
V_158 -> V_588 = ( 1 << 0 ) | ( 1 << 1 ) | ( 1 << 2 ) ;
V_158 -> V_589 = false ;
V_158 -> V_590 = F_249 ;
if ( ! F_270 ( V_3 , V_23 ) ) {
F_247 ( V_159 ) ;
F_233 ( V_3 ) ;
F_233 ( V_23 ) ;
}
}
