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
static enum V_57
F_20 ( struct V_1 * V_1 )
{
struct V_2 * V_3 = F_2 ( V_1 ) ;
struct V_58 * V_59 = V_3 -> V_4 . V_4 . V_59 ;
struct V_6 * V_7 = V_3 -> V_4 . V_4 . V_7 ;
struct V_43 * V_44 = V_7 -> V_45 ;
enum V_60 V_60 = V_3 -> V_60 ;
enum V_57 V_57 ;
if ( V_59 )
return F_21 ( V_59 ) -> V_57 ;
for ( V_57 = V_61 ; V_57 <= V_62 ; V_57 ++ ) {
T_3 V_63 = F_19 ( F_22 ( V_57 ) ) &
V_64 ;
if ( V_63 == V_65 && V_60 == V_66 )
return V_57 ;
if ( V_63 == V_67 && V_60 == V_68 )
return V_57 ;
}
return V_61 ;
}
static T_3 F_23 ( struct V_1 * V_1 )
{
struct V_6 * V_7 = F_3 ( V_1 ) ;
if ( F_24 ( V_7 ) )
return V_69 ;
else
return F_25 ( F_20 ( V_1 ) ) ;
}
static T_3 F_26 ( struct V_1 * V_1 )
{
struct V_6 * V_7 = F_3 ( V_1 ) ;
if ( F_24 ( V_7 ) )
return V_70 ;
else
return F_27 ( F_20 ( V_1 ) ) ;
}
static bool F_28 ( struct V_1 * V_1 )
{
struct V_6 * V_7 = F_3 ( V_1 ) ;
struct V_43 * V_44 = V_7 -> V_45 ;
return ( F_19 ( F_26 ( V_1 ) ) & V_71 ) != 0 ;
}
static bool F_29 ( struct V_1 * V_1 )
{
struct V_6 * V_7 = F_3 ( V_1 ) ;
struct V_43 * V_44 = V_7 -> V_45 ;
return ( F_19 ( F_23 ( V_1 ) ) & V_72 ) != 0 ;
}
static void
F_30 ( struct V_1 * V_1 )
{
struct V_6 * V_7 = F_3 ( V_1 ) ;
struct V_43 * V_44 = V_7 -> V_45 ;
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
F_32 ( struct V_1 * V_1 , bool V_73 )
{
struct V_2 * V_3 = F_2 ( V_1 ) ;
struct V_6 * V_7 = V_3 -> V_4 . V_4 . V_7 ;
struct V_43 * V_44 = V_7 -> V_45 ;
T_1 V_74 = V_1 -> V_75 ;
T_1 V_76 ;
bool V_77 ;
#define F_33 (((status = I915_READ_NOTRACE(ch_ctl)) & DP_AUX_CH_CTL_SEND_BUSY) == 0)
if ( V_73 )
V_77 = F_34 ( V_44 -> V_78 , F_33 ,
F_35 ( 10 ) ) ;
else
V_77 = F_36 ( F_33 , 10 ) == 0 ;
if ( ! V_77 )
F_37 ( L_4 ,
V_73 ) ;
#undef F_33
return V_76 ;
}
static T_1 F_38 ( struct V_1 * V_1 ,
int V_79 )
{
struct V_2 * V_3 = F_2 ( V_1 ) ;
struct V_6 * V_7 = V_3 -> V_4 . V_4 . V_7 ;
struct V_43 * V_44 = V_7 -> V_45 ;
if ( F_18 ( V_7 ) ) {
return V_79 ? 0 : 100 ;
} else if ( V_3 -> V_60 == V_80 ) {
if ( V_79 )
return 0 ;
if ( F_39 ( V_7 ) )
return F_40 ( F_41 ( V_44 ) , 2000 ) ;
else if ( F_42 ( V_7 ) || F_43 ( V_7 ) )
return 200 ;
else
return 225 ;
} else if ( V_44 -> V_81 == V_82 ) {
switch ( V_79 ) {
case 0 : return 63 ;
case 1 : return 72 ;
default: return 0 ;
}
} else if ( F_24 ( V_7 ) ) {
return V_79 ? 0 : F_44 ( F_45 ( V_7 ) , 2 ) ;
} else {
return V_79 ? 0 : F_17 ( V_7 ) / 2 ;
}
}
static int
F_46 ( struct V_1 * V_1 ,
T_2 * V_83 , int V_84 ,
T_2 * V_85 , int V_86 )
{
struct V_2 * V_3 = F_2 ( V_1 ) ;
struct V_6 * V_7 = V_3 -> V_4 . V_4 . V_7 ;
struct V_43 * V_44 = V_7 -> V_45 ;
T_1 V_74 = V_1 -> V_75 ;
T_1 V_87 = V_74 + 4 ;
T_1 V_88 ;
int V_39 , V_89 , V_90 ;
T_1 V_76 ;
int V_91 , V_92 , clock = 0 ;
bool V_73 = F_47 ( V_7 ) -> V_93 >= 5 && ! F_18 ( V_7 ) ;
T_1 V_94 ;
F_48 ( & V_44 -> V_95 , 0 ) ;
F_30 ( V_1 ) ;
if ( F_42 ( V_7 ) )
V_92 = 3 ;
else
V_92 = 5 ;
if ( F_49 ( V_7 ) && V_74 == V_96 )
V_94 = V_97 ;
else
V_94 = V_98 ;
F_50 ( V_44 ) ;
for ( V_91 = 0 ; V_91 < 3 ; V_91 ++ ) {
V_76 = F_51 ( V_74 ) ;
if ( ( V_76 & V_99 ) == 0 )
break;
F_52 ( 1 ) ;
}
if ( V_91 == 3 ) {
F_8 ( 1 , L_5 ,
F_19 ( V_74 ) ) ;
V_89 = - V_100 ;
goto V_101;
}
if ( F_53 ( V_84 > 20 || V_86 > 20 ) ) {
V_89 = - V_102 ;
goto V_101;
}
while ( ( V_88 = F_38 ( V_1 , clock ++ ) ) ) {
for ( V_91 = 0 ; V_91 < 5 ; V_91 ++ ) {
for ( V_39 = 0 ; V_39 < V_84 ; V_39 += 4 )
F_54 ( V_87 + V_39 ,
F_15 ( V_83 + V_39 , V_84 - V_39 ) ) ;
F_54 ( V_74 ,
V_99 |
( V_73 ? V_103 : 0 ) |
V_94 |
( V_84 << V_104 ) |
( V_92 << V_105 ) |
( V_88 << V_106 ) |
V_107 |
V_108 |
V_109 ) ;
V_76 = F_32 ( V_1 , V_73 ) ;
F_54 ( V_74 ,
V_76 |
V_107 |
V_108 |
V_109 ) ;
if ( V_76 & ( V_108 |
V_109 ) )
continue;
if ( V_76 & V_107 )
break;
}
if ( V_76 & V_107 )
break;
}
if ( ( V_76 & V_107 ) == 0 ) {
F_37 ( L_6 , V_76 ) ;
V_89 = - V_100 ;
goto V_101;
}
if ( V_76 & V_109 ) {
F_37 ( L_7 , V_76 ) ;
V_89 = - V_110 ;
goto V_101;
}
if ( V_76 & V_108 ) {
F_31 ( L_8 , V_76 ) ;
V_89 = - V_111 ;
goto V_101;
}
V_90 = ( ( V_76 & V_112 ) >>
V_104 ) ;
if ( V_90 > V_86 )
V_90 = V_86 ;
for ( V_39 = 0 ; V_39 < V_90 ; V_39 += 4 )
F_16 ( F_19 ( V_87 + V_39 ) ,
V_85 + V_39 , V_90 - V_39 ) ;
V_89 = V_90 ;
V_101:
F_48 ( & V_44 -> V_95 , V_113 ) ;
F_55 ( V_44 ) ;
return V_89 ;
}
static int
F_56 ( struct V_1 * V_1 ,
T_4 V_114 , T_2 * V_83 , int V_84 )
{
int V_89 ;
T_2 V_115 [ 20 ] ;
int V_116 ;
T_2 V_117 ;
if ( F_53 ( V_84 > 16 ) )
return - V_102 ;
F_30 ( V_1 ) ;
V_115 [ 0 ] = V_118 << 4 ;
V_115 [ 1 ] = V_114 >> 8 ;
V_115 [ 2 ] = V_114 & 0xff ;
V_115 [ 3 ] = V_84 - 1 ;
memcpy ( & V_115 [ 4 ] , V_83 , V_84 ) ;
V_116 = V_84 + 4 ;
for (; ; ) {
V_89 = F_46 ( V_1 , V_115 , V_116 , & V_117 , 1 ) ;
if ( V_89 < 0 )
return V_89 ;
if ( ( V_117 & V_119 ) == V_120 )
break;
else if ( ( V_117 & V_119 ) == V_121 )
F_57 ( 100 ) ;
else
return - V_110 ;
}
return V_84 ;
}
static int
F_58 ( struct V_1 * V_1 ,
T_4 V_114 , T_2 V_122 )
{
return F_56 ( V_1 , V_114 , & V_122 , 1 ) ;
}
static int
F_59 ( struct V_1 * V_1 ,
T_4 V_114 , T_2 * V_85 , int V_90 )
{
T_2 V_115 [ 4 ] ;
int V_116 ;
T_2 V_123 [ 20 ] ;
int V_124 ;
T_2 V_117 ;
int V_89 ;
if ( F_53 ( V_90 > 19 ) )
return - V_102 ;
F_30 ( V_1 ) ;
V_115 [ 0 ] = V_125 << 4 ;
V_115 [ 1 ] = V_114 >> 8 ;
V_115 [ 2 ] = V_114 & 0xff ;
V_115 [ 3 ] = V_90 - 1 ;
V_116 = 4 ;
V_124 = V_90 + 1 ;
for (; ; ) {
V_89 = F_46 ( V_1 , V_115 , V_116 ,
V_123 , V_124 ) ;
if ( V_89 == 0 )
return - V_126 ;
if ( V_89 < 0 )
return V_89 ;
V_117 = V_123 [ 0 ] ;
if ( ( V_117 & V_119 ) == V_120 ) {
memcpy ( V_85 , V_123 + 1 , V_89 - 1 ) ;
return V_89 - 1 ;
}
else if ( ( V_117 & V_119 ) == V_121 )
F_57 ( 100 ) ;
else
return - V_110 ;
}
}
static int
F_60 ( struct V_127 * V_128 , int V_21 ,
T_2 V_129 , T_2 * V_130 )
{
struct V_131 * V_132 = V_128 -> V_132 ;
struct V_1 * V_1 = F_61 ( V_128 ,
struct V_1 ,
V_128 ) ;
T_4 V_114 = V_132 -> V_114 ;
T_2 V_115 [ 5 ] ;
T_2 V_123 [ 2 ] ;
unsigned V_133 ;
int V_116 ;
int V_124 ;
int V_89 ;
F_62 ( V_1 ) ;
F_30 ( V_1 ) ;
if ( V_21 & V_134 )
V_115 [ 0 ] = V_135 << 4 ;
else
V_115 [ 0 ] = V_136 << 4 ;
if ( ! ( V_21 & V_137 ) )
V_115 [ 0 ] |= V_138 << 4 ;
V_115 [ 1 ] = V_114 >> 8 ;
V_115 [ 2 ] = V_114 ;
switch ( V_21 ) {
case V_139 :
V_115 [ 3 ] = 0 ;
V_115 [ 4 ] = V_129 ;
V_116 = 5 ;
V_124 = 1 ;
break;
case V_134 :
V_115 [ 3 ] = 0 ;
V_116 = 4 ;
V_124 = 2 ;
break;
default:
V_116 = 3 ;
V_124 = 1 ;
break;
}
for ( V_133 = 0 ; V_133 < 7 ; V_133 ++ ) {
V_89 = F_46 ( V_1 ,
V_115 , V_116 ,
V_123 , V_124 ) ;
if ( V_89 < 0 ) {
F_31 ( L_9 , V_89 ) ;
goto V_101;
}
switch ( V_123 [ 0 ] & V_119 ) {
case V_120 :
break;
case V_140 :
F_31 ( L_10 ) ;
V_89 = - V_141 ;
goto V_101;
case V_121 :
if ( V_1 -> V_11 [ V_142 ] &
V_143 )
F_63 ( 500 , 600 ) ;
else
F_63 ( 300 , 400 ) ;
continue;
default:
F_37 ( L_11 ,
V_123 [ 0 ] ) ;
V_89 = - V_141 ;
goto V_101;
}
switch ( V_123 [ 0 ] & V_144 ) {
case V_145 :
if ( V_21 == V_134 ) {
* V_130 = V_123 [ 1 ] ;
}
V_89 = V_124 - 1 ;
goto V_101;
case V_146 :
F_31 ( L_12 ) ;
V_89 = - V_141 ;
goto V_101;
case V_147 :
F_31 ( L_13 ) ;
F_57 ( 100 ) ;
break;
default:
F_37 ( L_14 , V_123 [ 0 ] ) ;
V_89 = - V_141 ;
goto V_101;
}
}
F_37 ( L_15 ) ;
V_89 = - V_141 ;
V_101:
F_64 ( V_1 , false ) ;
return V_89 ;
}
static int
F_65 ( struct V_1 * V_1 ,
struct V_22 * V_22 , const char * V_148 )
{
int V_89 ;
F_31 ( L_16 , V_148 ) ;
V_1 -> V_149 . V_150 = false ;
V_1 -> V_149 . V_114 = 0 ;
V_1 -> V_149 . V_151 = F_60 ;
memset ( & V_1 -> V_128 , '\0' , sizeof( V_1 -> V_128 ) ) ;
V_1 -> V_128 . V_152 = V_153 ;
V_1 -> V_128 . V_154 = V_155 ;
strncpy ( V_1 -> V_128 . V_148 , V_148 , sizeof( V_1 -> V_128 . V_148 ) - 1 ) ;
V_1 -> V_128 . V_148 [ sizeof( V_1 -> V_128 . V_148 ) - 1 ] = '\0' ;
V_1 -> V_128 . V_132 = & V_1 -> V_149 ;
V_1 -> V_128 . V_7 . V_156 = V_22 -> V_4 . V_157 ;
V_89 = F_66 ( & V_1 -> V_128 ) ;
return V_89 ;
}
static void
F_67 ( struct V_158 * V_159 ,
struct V_160 * V_161 , int V_162 )
{
struct V_6 * V_7 = V_159 -> V_4 . V_7 ;
const struct V_163 * V_164 = NULL ;
int V_39 , V_165 = 0 ;
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
for ( V_39 = 0 ; V_39 < V_165 ; V_39 ++ ) {
if ( V_162 == V_164 [ V_39 ] . V_162 ) {
V_161 -> V_169 = V_164 [ V_39 ] . V_169 ;
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
struct V_43 * V_44 = V_7 -> V_45 ;
struct V_20 * V_171 = & V_161 -> V_171 ;
struct V_1 * V_1 = F_5 ( & V_159 -> V_4 ) ;
enum V_60 V_60 = F_2 ( V_1 ) -> V_60 ;
struct V_172 * V_172 = V_159 -> V_173 ;
struct V_22 * V_22 = V_1 -> V_174 ;
int V_175 , clock ;
int V_176 = F_14 ( V_1 -> V_11 ) ;
int V_177 = F_7 ( V_1 ) == V_14 ? 1 : 0 ;
int V_17 , V_27 ;
static int V_178 [ 2 ] = { V_13 , V_14 } ;
int V_179 , V_180 ;
if ( F_24 ( V_7 ) && ! F_39 ( V_7 ) && V_60 != V_80 )
V_161 -> V_181 = true ;
V_161 -> V_182 = true ;
if ( F_1 ( V_1 ) && V_22 -> V_24 . V_23 ) {
F_72 ( V_22 -> V_24 . V_23 ,
V_171 ) ;
if ( ! F_24 ( V_7 ) )
F_73 ( V_172 , V_161 ,
V_22 -> V_24 . V_183 ) ;
else
F_74 ( V_172 , V_161 ,
V_22 -> V_24 . V_183 ) ;
}
if ( V_171 -> V_33 & V_34 )
return false ;
F_31 ( L_17
L_18 ,
V_176 , V_178 [ V_177 ] ,
V_171 -> V_184 ) ;
V_17 = V_161 -> V_185 ;
if ( F_1 ( V_1 ) && V_44 -> V_186 . V_187 &&
V_44 -> V_186 . V_187 < V_17 ) {
F_31 ( L_19 ,
V_44 -> V_186 . V_187 ) ;
V_17 = V_44 -> V_186 . V_187 ;
}
for (; V_17 >= 6 * 3 ; V_17 -= 2 * 3 ) {
V_27 = F_9 ( V_171 -> V_184 ,
V_17 ) ;
for ( clock = 0 ; clock <= V_177 ; clock ++ ) {
for ( V_175 = 1 ; V_175 <= V_176 ; V_175 <<= 1 ) {
V_180 = F_13 ( V_178 [ clock ] ) ;
V_179 = F_10 ( V_180 ,
V_175 ) ;
if ( V_27 <= V_179 ) {
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
V_27 , V_179 ) ;
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
struct V_172 * V_59 = F_21 ( V_195 -> V_4 . V_4 . V_59 ) ;
struct V_6 * V_7 = V_59 -> V_4 . V_7 ;
struct V_43 * V_44 = V_7 -> V_45 ;
T_3 V_196 ;
F_31 ( L_22 , V_59 -> V_197 . V_193 ) ;
V_196 = F_19 ( V_198 ) ;
V_196 &= ~ V_199 ;
if ( V_59 -> V_197 . V_193 == 162000 ) {
F_31 ( L_23 ) ;
V_196 |= V_200 ;
V_1 -> V_201 |= V_200 ;
} else {
V_196 |= V_202 ;
V_1 -> V_201 |= V_202 ;
}
F_54 ( V_198 , V_196 ) ;
F_78 ( V_198 ) ;
F_57 ( 500 ) ;
}
static void F_79 ( struct V_158 * V_159 )
{
struct V_6 * V_7 = V_159 -> V_4 . V_7 ;
struct V_43 * V_44 = V_7 -> V_45 ;
struct V_1 * V_1 = F_5 ( & V_159 -> V_4 ) ;
enum V_60 V_60 = F_2 ( V_1 ) -> V_60 ;
struct V_172 * V_59 = F_21 ( V_159 -> V_4 . V_59 ) ;
struct V_20 * V_171 = & V_59 -> V_197 . V_171 ;
V_1 -> V_201 = F_19 ( V_1 -> V_203 ) & V_204 ;
V_1 -> V_201 |= V_205 | V_206 ;
V_1 -> V_201 |= F_80 ( V_1 -> V_175 ) ;
if ( V_1 -> V_207 ) {
F_81 ( L_24 ,
F_82 ( V_59 -> V_57 ) ) ;
V_1 -> V_201 |= V_208 ;
F_83 ( & V_159 -> V_4 , V_171 ) ;
}
if ( V_60 == V_80 && F_43 ( V_7 ) && ! F_18 ( V_7 ) ) {
if ( V_171 -> V_33 & V_209 )
V_1 -> V_201 |= V_210 ;
if ( V_171 -> V_33 & V_211 )
V_1 -> V_201 |= V_212 ;
V_1 -> V_201 |= V_213 ;
if ( F_84 ( V_1 -> V_11 ) )
V_1 -> V_201 |= V_214 ;
V_1 -> V_201 |= V_59 -> V_57 << 29 ;
} else if ( ! F_85 ( V_7 ) || V_60 == V_80 ) {
if ( ! F_24 ( V_7 ) && ! F_18 ( V_7 ) )
V_1 -> V_201 |= V_1 -> V_190 ;
if ( V_171 -> V_33 & V_209 )
V_1 -> V_201 |= V_210 ;
if ( V_171 -> V_33 & V_211 )
V_1 -> V_201 |= V_212 ;
V_1 -> V_201 |= V_215 ;
if ( F_84 ( V_1 -> V_11 ) )
V_1 -> V_201 |= V_214 ;
if ( V_59 -> V_57 == 1 )
V_1 -> V_201 |= V_216 ;
} else {
V_1 -> V_201 |= V_213 ;
}
if ( V_60 == V_80 && ! F_18 ( V_7 ) )
F_77 ( V_1 ) ;
}
static void F_86 ( struct V_1 * V_1 ,
T_3 V_217 ,
T_3 V_218 )
{
struct V_6 * V_7 = F_3 ( V_1 ) ;
struct V_43 * V_44 = V_7 -> V_45 ;
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
}
static void F_88 ( struct V_1 * V_1 )
{
F_31 ( L_27 ) ;
F_86 ( V_1 , V_221 , V_222 ) ;
}
static void F_89 ( struct V_1 * V_1 )
{
F_31 ( L_28 ) ;
F_86 ( V_1 , V_223 , V_224 ) ;
}
static void F_90 ( struct V_1 * V_1 )
{
F_31 ( L_29 ) ;
F_86 ( V_1 , V_225 , V_226 ) ;
}
static T_3 F_91 ( struct V_1 * V_1 )
{
struct V_6 * V_7 = F_3 ( V_1 ) ;
struct V_43 * V_44 = V_7 -> V_45 ;
T_3 V_227 ;
V_227 = F_19 ( F_23 ( V_1 ) ) ;
V_227 &= ~ V_228 ;
V_227 |= V_229 ;
return V_227 ;
}
void F_62 ( struct V_1 * V_1 )
{
struct V_6 * V_7 = F_3 ( V_1 ) ;
struct V_43 * V_44 = V_7 -> V_45 ;
T_3 V_230 ;
T_3 V_219 , V_220 ;
if ( ! F_1 ( V_1 ) )
return;
F_8 ( V_1 -> V_231 ,
L_30 ) ;
V_1 -> V_231 = true ;
if ( F_29 ( V_1 ) )
return;
F_31 ( L_31 ) ;
if ( ! F_28 ( V_1 ) )
F_90 ( V_1 ) ;
V_230 = F_91 ( V_1 ) ;
V_230 |= V_72 ;
V_219 = F_26 ( V_1 ) ;
V_220 = F_23 ( V_1 ) ;
F_54 ( V_220 , V_230 ) ;
F_78 ( V_220 ) ;
F_31 ( L_32 ,
F_19 ( V_219 ) , F_19 ( V_220 ) ) ;
if ( ! F_28 ( V_1 ) ) {
F_31 ( L_33 ) ;
F_52 ( V_1 -> V_232 ) ;
}
}
static void F_92 ( struct V_1 * V_1 )
{
struct V_6 * V_7 = F_3 ( V_1 ) ;
struct V_43 * V_44 = V_7 -> V_45 ;
T_3 V_230 ;
T_3 V_219 , V_220 ;
F_53 ( ! F_93 ( & V_7 -> V_233 . V_234 ) ) ;
if ( ! V_1 -> V_231 && F_29 ( V_1 ) ) {
F_31 ( L_34 ) ;
V_230 = F_91 ( V_1 ) ;
V_230 &= ~ V_72 ;
V_220 = F_23 ( V_1 ) ;
V_219 = F_26 ( V_1 ) ;
F_54 ( V_220 , V_230 ) ;
F_78 ( V_220 ) ;
F_31 ( L_32 ,
F_19 ( V_219 ) , F_19 ( V_220 ) ) ;
F_52 ( V_1 -> V_235 ) ;
}
}
static void F_94 ( struct V_236 * V_237 )
{
struct V_1 * V_1 = F_61 ( F_95 ( V_237 ) ,
struct V_1 , V_238 ) ;
struct V_6 * V_7 = F_3 ( V_1 ) ;
F_96 ( & V_7 -> V_233 . V_234 ) ;
F_92 ( V_1 ) ;
F_97 ( & V_7 -> V_233 . V_234 ) ;
}
void F_64 ( struct V_1 * V_1 , bool V_239 )
{
if ( ! F_1 ( V_1 ) )
return;
F_8 ( ! V_1 -> V_231 , L_35 ) ;
V_1 -> V_231 = false ;
if ( V_239 ) {
F_92 ( V_1 ) ;
} else {
F_98 ( & V_1 -> V_238 ,
F_99 ( V_1 -> V_240 * 5 ) ) ;
}
}
void F_100 ( struct V_1 * V_1 )
{
struct V_6 * V_7 = F_3 ( V_1 ) ;
struct V_43 * V_44 = V_7 -> V_45 ;
T_3 V_230 ;
T_3 V_220 ;
if ( ! F_1 ( V_1 ) )
return;
F_31 ( L_36 ) ;
if ( F_28 ( V_1 ) ) {
F_31 ( L_37 ) ;
return;
}
F_90 ( V_1 ) ;
V_220 = F_23 ( V_1 ) ;
V_230 = F_91 ( V_1 ) ;
if ( F_101 ( V_7 ) ) {
V_230 &= ~ V_241 ;
F_54 ( V_220 , V_230 ) ;
F_78 ( V_220 ) ;
}
V_230 |= V_242 ;
if ( ! F_101 ( V_7 ) )
V_230 |= V_241 ;
F_54 ( V_220 , V_230 ) ;
F_78 ( V_220 ) ;
F_88 ( V_1 ) ;
if ( F_101 ( V_7 ) ) {
V_230 |= V_241 ;
F_54 ( V_220 , V_230 ) ;
F_78 ( V_220 ) ;
}
}
void F_102 ( struct V_1 * V_1 )
{
struct V_6 * V_7 = F_3 ( V_1 ) ;
struct V_43 * V_44 = V_7 -> V_45 ;
T_3 V_230 ;
T_3 V_220 ;
if ( ! F_1 ( V_1 ) )
return;
F_31 ( L_38 ) ;
F_8 ( ! V_1 -> V_231 , L_39 ) ;
V_230 = F_91 ( V_1 ) ;
V_230 &= ~ ( V_242 | V_72 | V_241 | V_243 ) ;
V_220 = F_23 ( V_1 ) ;
F_54 ( V_220 , V_230 ) ;
F_78 ( V_220 ) ;
V_1 -> V_231 = false ;
F_89 ( V_1 ) ;
}
void F_103 ( struct V_1 * V_1 )
{
struct V_2 * V_3 = F_2 ( V_1 ) ;
struct V_6 * V_7 = V_3 -> V_4 . V_4 . V_7 ;
struct V_43 * V_44 = V_7 -> V_45 ;
T_3 V_230 ;
T_3 V_220 ;
if ( ! F_1 ( V_1 ) )
return;
F_31 ( L_40 ) ;
F_52 ( V_1 -> V_244 ) ;
V_230 = F_91 ( V_1 ) ;
V_230 |= V_243 ;
V_220 = F_23 ( V_1 ) ;
F_54 ( V_220 , V_230 ) ;
F_78 ( V_220 ) ;
F_104 ( V_1 -> V_174 ) ;
}
void F_105 ( struct V_1 * V_1 )
{
struct V_6 * V_7 = F_3 ( V_1 ) ;
struct V_43 * V_44 = V_7 -> V_45 ;
T_3 V_230 ;
T_3 V_220 ;
if ( ! F_1 ( V_1 ) )
return;
F_106 ( V_1 -> V_174 ) ;
F_31 ( L_40 ) ;
V_230 = F_91 ( V_1 ) ;
V_230 &= ~ V_243 ;
V_220 = F_23 ( V_1 ) ;
F_54 ( V_220 , V_230 ) ;
F_78 ( V_220 ) ;
F_52 ( V_1 -> V_245 ) ;
}
static void F_107 ( struct V_1 * V_1 )
{
struct V_2 * V_3 = F_2 ( V_1 ) ;
struct V_58 * V_59 = V_3 -> V_4 . V_4 . V_59 ;
struct V_6 * V_7 = V_59 -> V_7 ;
struct V_43 * V_44 = V_7 -> V_45 ;
T_3 V_196 ;
F_108 ( V_44 ,
F_21 ( V_59 ) -> V_57 ) ;
F_31 ( L_40 ) ;
V_196 = F_19 ( V_198 ) ;
F_8 ( V_196 & V_246 , L_41 ) ;
F_8 ( V_196 & V_247 , L_42 ) ;
V_1 -> V_201 &= ~ ( V_247 | V_208 ) ;
V_1 -> V_201 |= V_246 ;
F_54 ( V_198 , V_1 -> V_201 ) ;
F_78 ( V_198 ) ;
F_57 ( 200 ) ;
}
static void F_109 ( struct V_1 * V_1 )
{
struct V_2 * V_3 = F_2 ( V_1 ) ;
struct V_58 * V_59 = V_3 -> V_4 . V_4 . V_59 ;
struct V_6 * V_7 = V_59 -> V_7 ;
struct V_43 * V_44 = V_7 -> V_45 ;
T_3 V_196 ;
F_108 ( V_44 ,
F_21 ( V_59 ) -> V_57 ) ;
V_196 = F_19 ( V_198 ) ;
F_8 ( ( V_196 & V_246 ) == 0 ,
L_43 ) ;
F_8 ( V_196 & V_247 , L_42 ) ;
V_196 &= ~ V_246 ;
F_54 ( V_198 , V_196 ) ;
F_78 ( V_198 ) ;
F_57 ( 200 ) ;
}
void F_110 ( struct V_1 * V_1 , int V_21 )
{
int V_89 , V_39 ;
if ( V_1 -> V_11 [ V_248 ] < 0x11 )
return;
if ( V_21 != V_249 ) {
V_89 = F_58 ( V_1 , V_250 ,
V_251 ) ;
if ( V_89 != 1 )
F_81 ( L_44 ) ;
} else {
for ( V_39 = 0 ; V_39 < 3 ; V_39 ++ ) {
V_89 = F_58 ( V_1 ,
V_250 ,
V_252 ) ;
if ( V_89 == 1 )
break;
F_52 ( 1 ) ;
}
}
}
static bool F_111 ( struct V_158 * V_159 ,
enum V_57 * V_57 )
{
struct V_1 * V_1 = F_5 ( & V_159 -> V_4 ) ;
enum V_60 V_60 = F_2 ( V_1 ) -> V_60 ;
struct V_6 * V_7 = V_159 -> V_4 . V_7 ;
struct V_43 * V_44 = V_7 -> V_45 ;
T_3 V_253 = F_19 ( V_1 -> V_203 ) ;
if ( ! ( V_253 & V_247 ) )
return false ;
if ( V_60 == V_80 && F_43 ( V_7 ) && ! F_18 ( V_7 ) ) {
* V_57 = F_112 ( V_253 ) ;
} else if ( ! F_85 ( V_7 ) || V_60 == V_80 ) {
* V_57 = F_113 ( V_253 ) ;
} else {
T_3 V_254 ;
T_3 V_255 ;
int V_39 ;
switch ( V_1 -> V_203 ) {
case V_256 :
V_254 = V_257 ;
break;
case V_258 :
V_254 = V_259 ;
break;
case V_260 :
V_254 = V_261 ;
break;
default:
return true ;
}
F_114 (i) {
V_255 = F_19 ( F_115 ( V_39 ) ) ;
if ( ( V_255 & V_262 ) == V_254 ) {
* V_57 = V_39 ;
return true ;
}
}
F_31 ( L_45 ,
V_1 -> V_203 ) ;
}
return true ;
}
static void F_116 ( struct V_158 * V_159 ,
struct V_160 * V_161 )
{
struct V_1 * V_1 = F_5 ( & V_159 -> V_4 ) ;
T_3 V_253 , V_33 = 0 ;
struct V_6 * V_7 = V_159 -> V_4 . V_7 ;
struct V_43 * V_44 = V_7 -> V_45 ;
enum V_60 V_60 = F_2 ( V_1 ) -> V_60 ;
struct V_172 * V_59 = F_21 ( V_159 -> V_4 . V_59 ) ;
int V_263 ;
if ( ( V_60 == V_80 ) || ! F_85 ( V_7 ) ) {
V_253 = F_19 ( V_1 -> V_203 ) ;
if ( V_253 & V_210 )
V_33 |= V_209 ;
else
V_33 |= V_264 ;
if ( V_253 & V_212 )
V_33 |= V_211 ;
else
V_33 |= V_265 ;
} else {
V_253 = F_19 ( F_115 ( V_59 -> V_57 ) ) ;
if ( V_253 & V_266 )
V_33 |= V_209 ;
else
V_33 |= V_264 ;
if ( V_253 & V_267 )
V_33 |= V_211 ;
else
V_33 |= V_265 ;
}
V_161 -> V_171 . V_33 |= V_33 ;
V_161 -> V_182 = true ;
F_117 ( V_59 , V_161 ) ;
if ( V_60 == V_80 ) {
if ( ( F_19 ( V_198 ) & V_199 ) == V_200 )
V_161 -> V_193 = 162000 ;
else
V_161 -> V_193 = 270000 ;
}
V_263 = F_118 ( V_161 -> V_193 ,
& V_161 -> V_194 ) ;
if ( F_24 ( V_44 -> V_7 ) && V_60 != V_80 )
F_119 ( V_161 , V_263 ) ;
V_161 -> V_171 . V_184 = V_263 ;
if ( F_1 ( V_1 ) && V_44 -> V_186 . V_187 &&
V_161 -> V_185 > V_44 -> V_186 . V_187 ) {
F_31 ( L_46 ,
V_161 -> V_185 , V_44 -> V_186 . V_187 ) ;
V_44 -> V_186 . V_187 = V_161 -> V_185 ;
}
}
static bool F_120 ( struct V_6 * V_7 )
{
struct V_43 * V_44 = V_7 -> V_45 ;
return V_44 -> V_268 . V_269 ;
}
static bool F_121 ( struct V_6 * V_7 )
{
struct V_43 * V_44 = V_7 -> V_45 ;
if ( ! F_122 ( V_7 ) )
return false ;
return F_19 ( F_123 ( V_7 ) ) & V_270 ;
}
static void F_124 ( struct V_1 * V_1 ,
struct V_271 * V_272 )
{
struct V_2 * V_195 = F_2 ( V_1 ) ;
struct V_6 * V_7 = V_195 -> V_4 . V_4 . V_7 ;
struct V_43 * V_44 = V_7 -> V_45 ;
struct V_172 * V_59 = F_21 ( V_195 -> V_4 . V_4 . V_59 ) ;
T_3 V_273 = F_125 ( V_59 -> V_197 . V_274 ) ;
T_3 V_275 = F_126 ( V_59 -> V_197 . V_274 ) ;
T_1 * V_276 = ( T_1 * ) V_272 ;
unsigned int V_39 ;
F_54 ( V_273 , 0 ) ;
F_78 ( V_273 ) ;
for ( V_39 = 0 ; V_39 < V_277 ; V_39 += 4 ) {
if ( V_39 < sizeof( struct V_271 ) )
F_54 ( V_275 + V_39 , * V_276 ++ ) ;
else
F_54 ( V_275 + V_39 , 0 ) ;
}
F_54 ( V_273 , V_278 ) ;
F_78 ( V_273 ) ;
}
static void F_127 ( struct V_1 * V_1 )
{
struct V_6 * V_7 = F_3 ( V_1 ) ;
struct V_43 * V_44 = V_7 -> V_45 ;
struct V_271 V_279 ;
if ( V_1 -> V_280 )
return;
memset ( & V_279 , 0 , sizeof( V_279 ) ) ;
V_279 . V_281 . V_282 = 0 ;
V_279 . V_281 . V_283 = 0x7 ;
V_279 . V_281 . V_284 = 0x2 ;
V_279 . V_281 . V_285 = 0x8 ;
F_124 ( V_1 , & V_279 ) ;
F_54 ( F_128 ( V_7 ) , V_286 |
V_287 | V_288 ) ;
V_1 -> V_280 = true ;
}
static void F_129 ( struct V_1 * V_1 )
{
struct V_6 * V_7 = F_3 ( V_1 ) ;
struct V_43 * V_44 = V_7 -> V_45 ;
T_1 V_88 = F_38 ( V_1 , 0 ) ;
int V_92 = 0x3 ;
int V_289 = 5 ;
if ( V_1 -> V_290 [ 1 ] & V_291 )
F_58 ( V_1 , V_292 ,
V_293 &
~ V_294 ) ;
else
F_58 ( V_1 , V_292 ,
V_293 |
V_294 ) ;
F_54 ( F_130 ( V_7 ) , V_295 ) ;
F_54 ( F_131 ( V_7 ) , V_296 ) ;
F_54 ( F_132 ( V_7 ) ,
V_98 |
( V_289 << V_104 ) |
( V_92 << V_105 ) |
( V_88 << V_106 ) ) ;
}
static void F_133 ( struct V_1 * V_1 )
{
struct V_6 * V_7 = F_3 ( V_1 ) ;
struct V_43 * V_44 = V_7 -> V_45 ;
T_1 V_297 = 0x1f ;
T_1 V_298 = 1 ;
T_1 V_299 = 0x0 ;
const T_1 V_300 = V_301 ;
if ( V_1 -> V_290 [ 1 ] & V_291 ) {
V_299 |= V_302 ;
V_299 |= V_303 ;
V_299 |= V_304 ;
V_299 |= V_305 ;
} else
V_299 |= V_306 ;
F_54 ( F_123 ( V_7 ) , V_299 |
F_49 ( V_7 ) ? 0 : V_300 |
V_297 << V_307 |
V_298 << V_308 |
V_270 ) ;
}
static bool F_134 ( struct V_1 * V_1 )
{
struct V_2 * V_195 = F_2 ( V_1 ) ;
struct V_6 * V_7 = V_195 -> V_4 . V_4 . V_7 ;
struct V_43 * V_44 = V_7 -> V_45 ;
struct V_58 * V_59 = V_195 -> V_4 . V_4 . V_59 ;
struct V_172 * V_172 = F_21 ( V_59 ) ;
struct V_309 * V_310 = F_135 ( V_59 -> V_311 ) -> V_310 ;
struct V_158 * V_158 = & F_2 ( V_1 ) -> V_4 ;
V_44 -> V_268 . V_312 = false ;
if ( ! F_122 ( V_7 ) ) {
F_31 ( L_47 ) ;
return false ;
}
if ( ( V_158 -> type != V_5 ) ||
( V_195 -> V_60 != V_80 ) ) {
F_31 ( L_48 ) ;
return false ;
}
if ( ! V_313 ) {
F_31 ( L_49 ) ;
return false ;
}
V_59 = V_195 -> V_4 . V_4 . V_59 ;
if ( V_59 == NULL ) {
F_31 ( L_50 ) ;
return false ;
}
V_172 = F_21 ( V_59 ) ;
if ( ! F_136 ( V_59 ) ) {
F_31 ( L_50 ) ;
return false ;
}
V_310 = F_135 ( V_59 -> V_311 ) -> V_310 ;
if ( V_310 -> V_314 != V_315 ||
V_310 -> V_316 == V_317 ) {
F_31 ( L_51 ) ;
return false ;
}
if ( F_19 ( F_137 ( V_172 -> V_57 ) ) & V_318 ) {
F_31 ( L_52 ) ;
return false ;
}
if ( F_19 ( F_138 ( V_172 -> V_197 . V_274 ) ) &
V_319 ) {
F_31 ( L_53 ) ;
return false ;
}
if ( V_172 -> V_197 . V_171 . V_33 & V_320 ) {
F_31 ( L_54 ) ;
return false ;
}
V_44 -> V_268 . V_312 = true ;
return true ;
}
static void F_139 ( struct V_1 * V_1 )
{
struct V_6 * V_7 = F_3 ( V_1 ) ;
if ( ! F_134 ( V_1 ) ||
F_121 ( V_7 ) )
return;
F_127 ( V_1 ) ;
F_129 ( V_1 ) ;
F_133 ( V_1 ) ;
}
void F_140 ( struct V_1 * V_1 )
{
struct V_6 * V_7 = F_3 ( V_1 ) ;
if ( F_134 ( V_1 ) &&
! F_121 ( V_7 ) )
F_139 ( V_1 ) ;
}
void F_141 ( struct V_1 * V_1 )
{
struct V_6 * V_7 = F_3 ( V_1 ) ;
struct V_43 * V_44 = V_7 -> V_45 ;
if ( ! F_121 ( V_7 ) )
return;
F_54 ( F_123 ( V_7 ) ,
F_19 ( F_123 ( V_7 ) ) & ~ V_270 ) ;
if ( F_87 ( ( F_19 ( F_142 ( V_7 ) ) &
V_321 ) == 0 , 2000 , 10 ) )
F_37 ( L_55 ) ;
}
void F_143 ( struct V_6 * V_7 )
{
struct V_158 * V_159 ;
struct V_1 * V_1 = NULL ;
F_144 (encoder, &dev->mode_config.encoder_list, base.head)
if ( V_159 -> type == V_5 ) {
V_1 = F_5 ( & V_159 -> V_4 ) ;
if ( ! F_120 ( V_7 ) )
return;
if ( ! F_134 ( V_1 ) )
F_141 ( V_1 ) ;
else
if ( ! F_121 ( V_7 ) )
F_139 ( V_1 ) ;
}
}
static void F_145 ( struct V_158 * V_159 )
{
struct V_1 * V_1 = F_5 ( & V_159 -> V_4 ) ;
enum V_60 V_60 = F_2 ( V_1 ) -> V_60 ;
struct V_6 * V_7 = V_159 -> V_4 . V_7 ;
F_62 ( V_1 ) ;
F_105 ( V_1 ) ;
F_110 ( V_1 , V_322 ) ;
F_102 ( V_1 ) ;
if ( ! ( V_60 == V_80 || F_18 ( V_7 ) ) )
F_146 ( V_1 ) ;
}
static void F_147 ( struct V_158 * V_159 )
{
struct V_1 * V_1 = F_5 ( & V_159 -> V_4 ) ;
enum V_60 V_60 = F_2 ( V_1 ) -> V_60 ;
struct V_6 * V_7 = V_159 -> V_4 . V_7 ;
if ( V_60 == V_80 || F_18 ( V_7 ) ) {
F_146 ( V_1 ) ;
if ( ! F_18 ( V_7 ) )
F_109 ( V_1 ) ;
}
}
static void F_148 ( struct V_158 * V_159 )
{
struct V_1 * V_1 = F_5 ( & V_159 -> V_4 ) ;
struct V_6 * V_7 = V_159 -> V_4 . V_7 ;
struct V_43 * V_44 = V_7 -> V_45 ;
T_1 V_323 = F_19 ( V_1 -> V_203 ) ;
if ( F_53 ( V_323 & V_247 ) )
return;
F_62 ( V_1 ) ;
F_110 ( V_1 , V_249 ) ;
F_149 ( V_1 ) ;
F_100 ( V_1 ) ;
F_64 ( V_1 , true ) ;
F_150 ( V_1 ) ;
F_151 ( V_1 ) ;
}
static void F_152 ( struct V_158 * V_159 )
{
struct V_1 * V_1 = F_5 ( & V_159 -> V_4 ) ;
F_148 ( V_159 ) ;
F_103 ( V_1 ) ;
}
static void F_153 ( struct V_158 * V_159 )
{
struct V_1 * V_1 = F_5 ( & V_159 -> V_4 ) ;
F_103 ( V_1 ) ;
}
static void F_154 ( struct V_158 * V_159 )
{
struct V_1 * V_1 = F_5 ( & V_159 -> V_4 ) ;
struct V_2 * V_324 = F_2 ( V_1 ) ;
if ( V_324 -> V_60 == V_80 )
F_107 ( V_1 ) ;
}
static void F_155 ( struct V_158 * V_159 )
{
struct V_1 * V_1 = F_5 ( & V_159 -> V_4 ) ;
struct V_2 * V_324 = F_2 ( V_1 ) ;
struct V_6 * V_7 = V_159 -> V_4 . V_7 ;
struct V_43 * V_44 = V_7 -> V_45 ;
struct V_172 * V_172 = F_21 ( V_159 -> V_4 . V_59 ) ;
int V_60 = F_156 ( V_324 ) ;
int V_57 = V_172 -> V_57 ;
struct V_325 V_326 ;
T_3 V_299 ;
F_96 ( & V_44 -> V_327 ) ;
V_299 = F_157 ( V_44 , V_57 , F_158 ( V_60 ) ) ;
V_299 = 0 ;
if ( V_57 )
V_299 |= ( 1 << 21 ) ;
else
V_299 &= ~ ( 1 << 21 ) ;
V_299 |= 0x001000c4 ;
F_159 ( V_44 , V_57 , F_160 ( V_60 ) , V_299 ) ;
F_159 ( V_44 , V_57 , F_161 ( V_60 ) , 0x00760018 ) ;
F_159 ( V_44 , V_57 , F_162 ( V_60 ) , 0x00400888 ) ;
F_97 ( & V_44 -> V_327 ) ;
F_163 ( V_7 , V_1 , & V_326 ) ;
F_164 ( V_7 , V_1 ,
& V_326 ) ;
F_148 ( V_159 ) ;
F_165 ( V_44 , V_60 ) ;
}
static void F_166 ( struct V_158 * V_159 )
{
struct V_2 * V_324 = F_167 ( & V_159 -> V_4 ) ;
struct V_6 * V_7 = V_159 -> V_4 . V_7 ;
struct V_43 * V_44 = V_7 -> V_45 ;
struct V_172 * V_172 =
F_21 ( V_159 -> V_4 . V_59 ) ;
int V_60 = F_156 ( V_324 ) ;
int V_57 = V_172 -> V_57 ;
F_96 ( & V_44 -> V_327 ) ;
F_159 ( V_44 , V_57 , F_168 ( V_60 ) ,
V_328 |
V_329 ) ;
F_159 ( V_44 , V_57 , F_169 ( V_60 ) ,
V_330 |
V_331 |
( 1 << V_332 ) |
V_333 ) ;
F_159 ( V_44 , V_57 , F_170 ( V_60 ) , 0x00750f00 ) ;
F_159 ( V_44 , V_57 , F_171 ( V_60 ) , 0x00001500 ) ;
F_159 ( V_44 , V_57 , F_172 ( V_60 ) , 0x40400000 ) ;
F_97 ( & V_44 -> V_327 ) ;
}
static bool
F_173 ( struct V_1 * V_1 , T_4 V_114 ,
T_2 * V_85 , int V_90 )
{
int V_89 , V_39 ;
for ( V_39 = 0 ; V_39 < 3 ; V_39 ++ ) {
V_89 = F_59 ( V_1 , V_114 , V_85 ,
V_90 ) ;
if ( V_89 == V_90 )
return true ;
F_52 ( 1 ) ;
}
return false ;
}
static bool
F_174 ( struct V_1 * V_1 , T_2 V_334 [ V_335 ] )
{
return F_173 ( V_1 ,
V_336 ,
V_334 ,
V_335 ) ;
}
static T_2
F_175 ( struct V_1 * V_1 )
{
struct V_6 * V_7 = F_3 ( V_1 ) ;
enum V_60 V_60 = F_2 ( V_1 ) -> V_60 ;
if ( F_18 ( V_7 ) || F_49 ( V_7 ) )
return V_337 ;
else if ( F_43 ( V_7 ) && V_60 == V_80 )
return V_338 ;
else if ( F_85 ( V_7 ) && V_60 != V_80 )
return V_337 ;
else
return V_338 ;
}
static T_2
F_176 ( struct V_1 * V_1 , T_2 V_339 )
{
struct V_6 * V_7 = F_3 ( V_1 ) ;
enum V_60 V_60 = F_2 ( V_1 ) -> V_60 ;
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
} else if ( F_43 ( V_7 ) && V_60 == V_80 ) {
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
static T_1 F_177 ( struct V_1 * V_1 )
{
struct V_6 * V_7 = F_3 ( V_1 ) ;
struct V_43 * V_44 = V_7 -> V_45 ;
struct V_2 * V_324 = F_2 ( V_1 ) ;
struct V_172 * V_172 =
F_21 ( V_324 -> V_4 . V_4 . V_59 ) ;
unsigned long V_347 , V_348 ,
V_349 ;
T_2 V_350 = V_1 -> V_350 [ 0 ] ;
int V_60 = F_156 ( V_324 ) ;
int V_57 = V_172 -> V_57 ;
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
F_96 ( & V_44 -> V_327 ) ;
F_159 ( V_44 , V_57 , F_178 ( V_60 ) , 0x00000000 ) ;
F_159 ( V_44 , V_57 , F_179 ( V_60 ) , V_347 ) ;
F_159 ( V_44 , V_57 , F_180 ( V_60 ) ,
V_349 ) ;
F_159 ( V_44 , V_57 , F_181 ( V_60 ) , 0x0C782040 ) ;
F_159 ( V_44 , V_57 , F_182 ( V_60 ) , 0x00030000 ) ;
F_159 ( V_44 , V_57 , F_183 ( V_60 ) , V_348 ) ;
F_159 ( V_44 , V_57 , F_178 ( V_60 ) , 0x80000000 ) ;
F_97 ( & V_44 -> V_327 ) ;
return 0 ;
}
static void
F_184 ( struct V_1 * V_1 ,
const T_2 V_334 [ V_335 ] )
{
T_2 V_40 = 0 ;
T_2 V_352 = 0 ;
int V_353 ;
T_2 V_354 ;
T_2 V_355 ;
for ( V_353 = 0 ; V_353 < V_1 -> V_175 ; V_353 ++ ) {
T_2 V_356 = F_185 ( V_334 , V_353 ) ;
T_2 V_357 = F_186 ( V_334 , V_353 ) ;
if ( V_356 > V_40 )
V_40 = V_356 ;
if ( V_357 > V_352 )
V_352 = V_357 ;
}
V_354 = F_175 ( V_1 ) ;
if ( V_40 >= V_354 )
V_40 = V_354 | V_358 ;
V_355 = F_176 ( V_1 , V_40 ) ;
if ( V_352 >= V_355 )
V_352 = V_355 | V_359 ;
for ( V_353 = 0 ; V_353 < 4 ; V_353 ++ )
V_1 -> V_350 [ V_353 ] = V_40 | V_352 ;
}
static T_1
F_187 ( T_2 V_350 )
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
F_188 ( T_2 V_350 )
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
F_31 ( L_56
L_57 , V_360 ) ;
return V_367 ;
}
}
static T_1
F_189 ( T_2 V_350 )
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
F_31 ( L_56
L_57 , V_360 ) ;
return V_379 ;
}
}
static T_1
F_190 ( T_2 V_350 )
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
F_31 ( L_56
L_57 , V_360 ) ;
return V_380 ;
}
}
static T_1
F_191 ( T_2 V_350 )
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
F_31 ( L_56
L_57 , V_360 ) ;
return V_389 ;
}
}
static void
F_192 ( struct V_1 * V_1 , T_1 * V_201 )
{
struct V_2 * V_3 = F_2 ( V_1 ) ;
enum V_60 V_60 = V_3 -> V_60 ;
struct V_6 * V_7 = V_3 -> V_4 . V_4 . V_7 ;
T_1 V_360 , V_217 ;
T_2 V_350 = V_1 -> V_350 [ 0 ] ;
if ( F_49 ( V_7 ) ) {
V_360 = F_191 ( V_350 ) ;
V_217 = V_398 ;
} else if ( F_70 ( V_7 ) ) {
V_360 = F_190 ( V_350 ) ;
V_217 = V_398 ;
} else if ( F_18 ( V_7 ) ) {
V_360 = F_177 ( V_1 ) ;
V_217 = 0 ;
} else if ( F_43 ( V_7 ) && V_60 == V_80 ) {
V_360 = F_189 ( V_350 ) ;
V_217 = V_399 ;
} else if ( F_42 ( V_7 ) && V_60 == V_80 ) {
V_360 = F_188 ( V_350 ) ;
V_217 = V_400 ;
} else {
V_360 = F_187 ( V_350 ) ;
V_217 = V_401 | V_402 ;
}
F_31 ( L_58 , V_360 ) ;
* V_201 = ( * V_201 & ~ V_217 ) | V_360 ;
}
static bool
F_193 ( struct V_1 * V_1 ,
T_1 * V_201 ,
T_2 V_403 )
{
struct V_2 * V_3 = F_2 ( V_1 ) ;
struct V_6 * V_7 = V_3 -> V_4 . V_4 . V_7 ;
struct V_43 * V_44 = V_7 -> V_45 ;
enum V_60 V_60 = V_3 -> V_60 ;
T_2 V_404 [ sizeof( V_1 -> V_350 ) + 1 ] ;
int V_89 , V_405 ;
if ( F_39 ( V_7 ) ) {
T_1 V_406 = F_19 ( F_194 ( V_60 ) ) ;
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
F_54 ( F_194 ( V_60 ) , V_406 ) ;
} else if ( F_85 ( V_7 ) && ( F_43 ( V_7 ) || V_60 != V_80 ) ) {
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
F_37 ( L_59 ) ;
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
F_37 ( L_59 ) ;
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
V_89 = F_56 ( V_1 , V_425 ,
V_404 , V_405 ) ;
return V_89 == V_405 ;
}
static bool
F_195 ( struct V_1 * V_1 , T_1 * V_201 ,
T_2 V_403 )
{
memset ( V_1 -> V_350 , 0 , sizeof( V_1 -> V_350 ) ) ;
F_192 ( V_1 , V_201 ) ;
return F_193 ( V_1 , V_201 , V_403 ) ;
}
static bool
F_196 ( struct V_1 * V_1 , T_1 * V_201 ,
const T_2 V_334 [ V_335 ] )
{
struct V_2 * V_3 = F_2 ( V_1 ) ;
struct V_6 * V_7 = V_3 -> V_4 . V_4 . V_7 ;
struct V_43 * V_44 = V_7 -> V_45 ;
int V_89 ;
F_184 ( V_1 , V_334 ) ;
F_192 ( V_1 , V_201 ) ;
F_54 ( V_1 -> V_203 , * V_201 ) ;
F_78 ( V_1 -> V_203 ) ;
V_89 = F_56 ( V_1 , V_426 ,
V_1 -> V_350 ,
V_1 -> V_175 ) ;
return V_89 == V_1 -> V_175 ;
}
static void F_197 ( struct V_1 * V_1 )
{
struct V_2 * V_3 = F_2 ( V_1 ) ;
struct V_6 * V_7 = V_3 -> V_4 . V_4 . V_7 ;
struct V_43 * V_44 = V_7 -> V_45 ;
enum V_60 V_60 = V_3 -> V_60 ;
T_1 V_299 ;
if ( ! F_39 ( V_7 ) )
return;
V_299 = F_19 ( F_194 ( V_60 ) ) ;
V_299 &= ~ V_409 ;
V_299 |= V_427 ;
F_54 ( F_194 ( V_60 ) , V_299 ) ;
if ( V_60 == V_80 )
return;
if ( F_198 ( ( F_19 ( F_199 ( V_60 ) ) & V_428 ) ,
1 ) )
F_37 ( L_60 ) ;
}
void
F_149 ( struct V_1 * V_1 )
{
struct V_429 * V_159 = & F_2 ( V_1 ) -> V_4 . V_4 ;
struct V_6 * V_7 = V_159 -> V_7 ;
int V_39 ;
T_2 V_430 ;
int V_431 , V_432 ;
T_1 V_201 = V_1 -> V_201 ;
T_2 V_433 [ 2 ] ;
if ( F_39 ( V_7 ) )
F_200 ( V_159 ) ;
V_433 [ 0 ] = V_1 -> V_162 ;
V_433 [ 1 ] = V_1 -> V_175 ;
if ( F_84 ( V_1 -> V_11 ) )
V_433 [ 1 ] |= V_434 ;
F_56 ( V_1 , V_435 , V_433 , 2 ) ;
V_433 [ 0 ] = 0 ;
V_433 [ 1 ] = V_436 ;
F_56 ( V_1 , V_437 , V_433 , 2 ) ;
V_201 |= V_247 ;
if ( ! F_195 ( V_1 , & V_201 ,
V_413 |
V_407 ) ) {
F_37 ( L_61 ) ;
return;
}
V_430 = 0xff ;
V_431 = 0 ;
V_432 = 0 ;
for (; ; ) {
T_2 V_334 [ V_335 ] ;
F_201 ( V_1 -> V_11 ) ;
if ( ! F_174 ( V_1 , V_334 ) ) {
F_37 ( L_62 ) ;
break;
}
if ( F_202 ( V_334 , V_1 -> V_175 ) ) {
F_31 ( L_63 ) ;
break;
}
for ( V_39 = 0 ; V_39 < V_1 -> V_175 ; V_39 ++ )
if ( ( V_1 -> V_350 [ V_39 ] & V_358 ) == 0 )
break;
if ( V_39 == V_1 -> V_175 ) {
++ V_432 ;
if ( V_432 == 5 ) {
F_37 ( L_64 ) ;
break;
}
F_195 ( V_1 , & V_201 ,
V_413 |
V_407 ) ;
V_431 = 0 ;
continue;
}
if ( ( V_1 -> V_350 [ 0 ] & V_340 ) == V_430 ) {
++ V_431 ;
if ( V_431 == 5 ) {
F_37 ( L_65 ) ;
break;
}
} else
V_431 = 0 ;
V_430 = V_1 -> V_350 [ 0 ] & V_340 ;
if ( ! F_196 ( V_1 , & V_201 , V_334 ) ) {
F_37 ( L_66 ) ;
break;
}
}
V_1 -> V_201 = V_201 ;
}
void
F_150 ( struct V_1 * V_1 )
{
bool V_438 = false ;
int V_439 , V_440 ;
T_1 V_201 = V_1 -> V_201 ;
if ( ! F_193 ( V_1 , & V_201 ,
V_415 |
V_407 ) ) {
F_37 ( L_67 ) ;
return;
}
V_439 = 0 ;
V_440 = 0 ;
V_438 = false ;
for (; ; ) {
T_2 V_334 [ V_335 ] ;
if ( V_440 > 5 ) {
F_37 ( L_68 ) ;
F_146 ( V_1 ) ;
break;
}
F_203 ( V_1 -> V_11 ) ;
if ( ! F_174 ( V_1 , V_334 ) ) {
F_37 ( L_62 ) ;
break;
}
if ( ! F_202 ( V_334 , V_1 -> V_175 ) ) {
F_149 ( V_1 ) ;
F_193 ( V_1 , & V_201 ,
V_415 |
V_407 ) ;
V_440 ++ ;
continue;
}
if ( F_204 ( V_334 , V_1 -> V_175 ) ) {
V_438 = true ;
break;
}
if ( V_439 > 5 ) {
F_146 ( V_1 ) ;
F_149 ( V_1 ) ;
F_193 ( V_1 , & V_201 ,
V_415 |
V_407 ) ;
V_439 = 0 ;
V_440 ++ ;
continue;
}
if ( ! F_196 ( V_1 , & V_201 , V_334 ) ) {
F_37 ( L_66 ) ;
break;
}
++ V_439 ;
}
F_197 ( V_1 ) ;
V_1 -> V_201 = V_201 ;
if ( V_438 )
F_31 ( L_69 ) ;
}
void F_151 ( struct V_1 * V_1 )
{
F_193 ( V_1 , & V_1 -> V_201 ,
V_411 ) ;
}
static void
F_146 ( struct V_1 * V_1 )
{
struct V_2 * V_3 = F_2 ( V_1 ) ;
enum V_60 V_60 = V_3 -> V_60 ;
struct V_6 * V_7 = V_3 -> V_4 . V_4 . V_7 ;
struct V_43 * V_44 = V_7 -> V_45 ;
struct V_172 * V_172 =
F_21 ( V_3 -> V_4 . V_4 . V_59 ) ;
T_1 V_201 = V_1 -> V_201 ;
if ( F_39 ( V_7 ) )
return;
if ( F_53 ( ( F_19 ( V_1 -> V_203 ) & V_247 ) == 0 ) )
return;
F_31 ( L_40 ) ;
if ( F_85 ( V_7 ) && ( F_43 ( V_7 ) || V_60 != V_80 ) ) {
V_201 &= ~ V_419 ;
F_54 ( V_1 -> V_203 , V_201 | V_441 ) ;
} else {
V_201 &= ~ V_422 ;
F_54 ( V_1 -> V_203 , V_201 | V_442 ) ;
}
F_78 ( V_1 -> V_203 ) ;
F_205 ( V_7 , V_172 -> V_57 ) ;
if ( F_206 ( V_7 ) &&
F_19 ( V_1 -> V_203 ) & V_216 ) {
struct V_58 * V_59 = V_3 -> V_4 . V_4 . V_59 ;
V_201 &= ~ V_216 ;
F_54 ( V_1 -> V_203 , V_201 ) ;
if ( F_53 ( V_59 == NULL ) ) {
F_78 ( V_1 -> V_203 ) ;
F_52 ( 50 ) ;
} else
F_205 ( V_7 , V_172 -> V_57 ) ;
}
V_201 &= ~ V_208 ;
F_54 ( V_1 -> V_203 , V_201 & ~ V_247 ) ;
F_78 ( V_1 -> V_203 ) ;
F_52 ( V_1 -> V_235 ) ;
}
static bool
F_207 ( struct V_1 * V_1 )
{
struct V_2 * V_195 = F_2 ( V_1 ) ;
struct V_6 * V_7 = V_195 -> V_4 . V_4 . V_7 ;
struct V_43 * V_44 = V_7 -> V_45 ;
char V_443 [ sizeof( V_1 -> V_11 ) * 3 ] ;
if ( F_173 ( V_1 , 0x000 , V_1 -> V_11 ,
sizeof( V_1 -> V_11 ) ) == 0 )
return false ;
F_208 ( V_1 -> V_11 , sizeof( V_1 -> V_11 ) ,
32 , 1 , V_443 , sizeof( V_443 ) , false ) ;
F_31 ( L_70 , V_443 ) ;
if ( V_1 -> V_11 [ V_248 ] == 0 )
return false ;
memset ( V_1 -> V_290 , 0 , sizeof( V_1 -> V_290 ) ) ;
if ( F_1 ( V_1 ) ) {
F_173 ( V_1 , V_444 ,
V_1 -> V_290 ,
sizeof( V_1 -> V_290 ) ) ;
if ( V_1 -> V_290 [ 0 ] & V_445 ) {
V_44 -> V_268 . V_269 = true ;
F_31 ( L_71 ) ;
}
}
if ( ! ( V_1 -> V_11 [ V_142 ] &
V_143 ) )
return true ;
if ( V_1 -> V_11 [ V_248 ] == 0x10 )
return true ;
if ( F_173 ( V_1 , V_446 ,
V_1 -> V_447 ,
V_448 ) == 0 )
return false ;
return true ;
}
static void
F_209 ( struct V_1 * V_1 )
{
T_5 V_404 [ 3 ] ;
if ( ! ( V_1 -> V_11 [ V_449 ] & V_450 ) )
return;
F_62 ( V_1 ) ;
if ( F_173 ( V_1 , V_451 , V_404 , 3 ) )
F_31 ( L_72 ,
V_404 [ 0 ] , V_404 [ 1 ] , V_404 [ 2 ] ) ;
if ( F_173 ( V_1 , V_452 , V_404 , 3 ) )
F_31 ( L_73 ,
V_404 [ 0 ] , V_404 [ 1 ] , V_404 [ 2 ] ) ;
F_64 ( V_1 , false ) ;
}
static bool
F_210 ( struct V_1 * V_1 , T_5 * V_453 )
{
int V_89 ;
V_89 = F_173 ( V_1 ,
V_454 ,
V_453 , 1 ) ;
if ( ! V_89 )
return false ;
return true ;
}
static void
F_211 ( struct V_1 * V_1 )
{
F_58 ( V_1 , V_455 , V_456 ) ;
}
void
F_212 ( struct V_1 * V_1 )
{
struct V_158 * V_158 = & F_2 ( V_1 ) -> V_4 ;
T_5 V_453 ;
T_5 V_334 [ V_335 ] ;
if ( ! V_158 -> V_457 )
return;
if ( F_53 ( ! V_158 -> V_4 . V_59 ) )
return;
if ( ! F_174 ( V_1 , V_334 ) ) {
F_146 ( V_1 ) ;
return;
}
if ( ! F_207 ( V_1 ) ) {
F_146 ( V_1 ) ;
return;
}
if ( V_1 -> V_11 [ V_248 ] >= 0x11 &&
F_210 ( V_1 , & V_453 ) ) {
F_58 ( V_1 ,
V_454 ,
V_453 ) ;
if ( V_453 & V_458 )
F_211 ( V_1 ) ;
if ( V_453 & ( V_459 | V_460 ) )
F_81 ( L_74 ) ;
}
if ( ! F_204 ( V_334 , V_1 -> V_175 ) ) {
F_31 ( L_75 ,
F_213 ( & V_158 -> V_4 ) ) ;
F_149 ( V_1 ) ;
F_150 ( V_1 ) ;
F_151 ( V_1 ) ;
}
}
static enum V_461
F_214 ( struct V_1 * V_1 )
{
T_2 * V_11 = V_1 -> V_11 ;
T_2 type ;
if ( ! F_207 ( V_1 ) )
return V_462 ;
if ( ! ( V_11 [ V_142 ] & V_143 ) )
return V_463 ;
if ( V_1 -> V_11 [ V_248 ] >= 0x11 &&
V_1 -> V_447 [ 0 ] & V_464 ) {
T_2 V_465 ;
if ( ! F_173 ( V_1 , V_466 ,
& V_465 , 1 ) )
return V_467 ;
return F_215 ( V_465 ) ? V_463
: V_462 ;
}
if ( F_216 ( & V_1 -> V_128 ) )
return V_463 ;
if ( V_1 -> V_11 [ V_248 ] >= 0x11 ) {
type = V_1 -> V_447 [ 0 ] & V_468 ;
if ( type == V_469 ||
type == V_470 )
return V_467 ;
} else {
type = V_1 -> V_11 [ V_142 ] &
V_471 ;
if ( type == V_472 ||
type == V_473 )
return V_467 ;
}
F_31 ( L_76 ) ;
return V_462 ;
}
static enum V_461
F_217 ( struct V_1 * V_1 )
{
struct V_6 * V_7 = F_3 ( V_1 ) ;
struct V_43 * V_44 = V_7 -> V_45 ;
struct V_2 * V_3 = F_2 ( V_1 ) ;
enum V_461 V_76 ;
if ( F_1 ( V_1 ) ) {
V_76 = F_218 ( V_7 ) ;
if ( V_76 == V_467 )
V_76 = V_463 ;
return V_76 ;
}
if ( ! F_219 ( V_44 , V_3 ) )
return V_462 ;
return F_214 ( V_1 ) ;
}
static enum V_461
F_220 ( struct V_1 * V_1 )
{
struct V_6 * V_7 = F_3 ( V_1 ) ;
struct V_43 * V_44 = V_7 -> V_45 ;
struct V_2 * V_3 = F_2 ( V_1 ) ;
T_1 V_474 ;
if ( F_1 ( V_1 ) ) {
enum V_461 V_76 ;
V_76 = F_218 ( V_7 ) ;
if ( V_76 == V_467 )
V_76 = V_463 ;
return V_76 ;
}
switch ( V_3 -> V_60 ) {
case V_66 :
V_474 = V_475 ;
break;
case V_68 :
V_474 = V_476 ;
break;
case V_477 :
V_474 = V_478 ;
break;
default:
return V_467 ;
}
if ( ( F_19 ( V_479 ) & V_474 ) == 0 )
return V_462 ;
return F_214 ( V_1 ) ;
}
static struct V_480 *
F_221 ( struct V_8 * V_9 , struct V_127 * V_128 )
{
struct V_22 * V_22 = F_12 ( V_9 ) ;
if ( V_22 -> V_480 ) {
if ( F_222 ( V_22 -> V_480 ) )
return NULL ;
return F_223 ( V_22 -> V_480 ) ;
}
return F_224 ( V_9 , V_128 ) ;
}
static int
F_225 ( struct V_8 * V_9 , struct V_127 * V_128 )
{
struct V_22 * V_22 = F_12 ( V_9 ) ;
if ( V_22 -> V_480 ) {
if ( F_222 ( V_22 -> V_480 ) )
return 0 ;
return F_226 ( V_9 ,
V_22 -> V_480 ) ;
}
return F_227 ( V_9 , V_128 ) ;
}
static enum V_461
F_228 ( struct V_8 * V_9 , bool V_481 )
{
struct V_1 * V_1 = F_4 ( V_9 ) ;
struct V_2 * V_3 = F_2 ( V_1 ) ;
struct V_158 * V_158 = & V_3 -> V_4 ;
struct V_6 * V_7 = V_9 -> V_7 ;
enum V_461 V_76 ;
struct V_480 * V_480 = NULL ;
F_31 ( L_77 ,
V_9 -> V_4 . V_482 , F_229 ( V_9 ) ) ;
V_1 -> V_207 = false ;
if ( F_24 ( V_7 ) )
V_76 = F_217 ( V_1 ) ;
else
V_76 = F_220 ( V_1 ) ;
if ( V_76 != V_463 )
return V_76 ;
F_209 ( V_1 ) ;
if ( V_1 -> V_483 != V_484 ) {
V_1 -> V_207 = ( V_1 -> V_483 == V_485 ) ;
} else {
V_480 = F_221 ( V_9 , & V_1 -> V_128 ) ;
if ( V_480 ) {
V_1 -> V_207 = F_230 ( V_480 ) ;
F_231 ( V_480 ) ;
}
}
if ( V_158 -> type != V_5 )
V_158 -> type = V_486 ;
return V_463 ;
}
static int F_232 ( struct V_8 * V_9 )
{
struct V_1 * V_1 = F_4 ( V_9 ) ;
struct V_22 * V_22 = F_12 ( V_9 ) ;
struct V_6 * V_7 = V_9 -> V_7 ;
int V_89 ;
V_89 = F_225 ( V_9 , & V_1 -> V_128 ) ;
if ( V_89 )
return V_89 ;
if ( F_1 ( V_1 ) && V_22 -> V_24 . V_23 ) {
struct V_20 * V_21 ;
V_21 = F_233 ( V_7 ,
V_22 -> V_24 . V_23 ) ;
if ( V_21 ) {
F_234 ( V_9 , V_21 ) ;
return 1 ;
}
}
return 0 ;
}
static bool
F_235 ( struct V_8 * V_9 )
{
struct V_1 * V_1 = F_4 ( V_9 ) ;
struct V_480 * V_480 ;
bool V_207 = false ;
V_480 = F_221 ( V_9 , & V_1 -> V_128 ) ;
if ( V_480 ) {
V_207 = F_230 ( V_480 ) ;
F_231 ( V_480 ) ;
}
return V_207 ;
}
static int
F_236 ( struct V_8 * V_9 ,
struct V_487 * V_488 ,
T_6 V_299 )
{
struct V_43 * V_44 = V_9 -> V_7 -> V_45 ;
struct V_22 * V_22 = F_12 ( V_9 ) ;
struct V_158 * V_158 = F_6 ( V_9 ) ;
struct V_1 * V_1 = F_5 ( & V_158 -> V_4 ) ;
int V_89 ;
V_89 = F_237 ( & V_9 -> V_4 , V_488 , V_299 ) ;
if ( V_89 )
return V_89 ;
if ( V_488 == V_44 -> V_489 ) {
int V_39 = V_299 ;
bool V_207 ;
if ( V_39 == V_1 -> V_483 )
return 0 ;
V_1 -> V_483 = V_39 ;
if ( V_39 == V_484 )
V_207 = F_235 ( V_9 ) ;
else
V_207 = ( V_39 == V_485 ) ;
if ( V_207 == V_1 -> V_207 )
return 0 ;
V_1 -> V_207 = V_207 ;
goto V_77;
}
if ( V_488 == V_44 -> V_490 ) {
bool V_491 = V_1 -> V_189 ;
T_1 V_492 = V_1 -> V_190 ;
switch ( V_299 ) {
case V_493 :
V_1 -> V_189 = true ;
break;
case V_494 :
V_1 -> V_189 = false ;
V_1 -> V_190 = 0 ;
break;
case V_495 :
V_1 -> V_189 = false ;
V_1 -> V_190 = V_191 ;
break;
default:
return - V_496 ;
}
if ( V_491 == V_1 -> V_189 &&
V_492 == V_1 -> V_190 )
return 0 ;
goto V_77;
}
if ( F_1 ( V_1 ) &&
V_488 == V_9 -> V_7 -> V_233 . V_497 ) {
if ( V_299 == V_498 ) {
F_31 ( L_78 ) ;
return - V_496 ;
}
if ( V_22 -> V_24 . V_183 == V_299 ) {
return 0 ;
}
V_22 -> V_24 . V_183 = V_299 ;
goto V_77;
}
return - V_496 ;
V_77:
if ( V_158 -> V_4 . V_59 )
F_238 ( V_158 -> V_4 . V_59 ) ;
return 0 ;
}
static void
F_239 ( struct V_8 * V_9 )
{
struct V_22 * V_22 = F_12 ( V_9 ) ;
if ( ! F_240 ( V_22 -> V_480 ) )
F_231 ( V_22 -> V_480 ) ;
if ( V_9 -> V_499 == V_500 )
F_241 ( & V_22 -> V_24 ) ;
F_242 ( V_9 ) ;
F_231 ( V_9 ) ;
}
void F_243 ( struct V_429 * V_159 )
{
struct V_2 * V_3 = F_167 ( V_159 ) ;
struct V_1 * V_1 = & V_3 -> V_501 ;
struct V_6 * V_7 = F_3 ( V_1 ) ;
F_244 ( & V_1 -> V_128 ) ;
F_245 ( V_159 ) ;
if ( F_1 ( V_1 ) ) {
F_246 ( & V_1 -> V_238 ) ;
F_96 ( & V_7 -> V_233 . V_234 ) ;
F_92 ( V_1 ) ;
F_97 ( & V_7 -> V_233 . V_234 ) ;
}
F_231 ( V_3 ) ;
}
static void
F_247 ( struct V_158 * V_158 )
{
struct V_1 * V_1 = F_5 ( & V_158 -> V_4 ) ;
F_212 ( V_1 ) ;
}
int
F_248 ( struct V_58 * V_59 )
{
struct V_6 * V_7 = V_59 -> V_7 ;
struct V_158 * V_158 ;
struct V_1 * V_1 ;
F_249 (dev, crtc, intel_encoder) {
V_1 = F_5 ( & V_158 -> V_4 ) ;
if ( V_158 -> type == V_486 ||
V_158 -> type == V_5 )
return V_1 -> V_203 ;
}
return - 1 ;
}
bool F_250 ( struct V_6 * V_7 , enum V_60 V_60 )
{
struct V_43 * V_44 = V_7 -> V_45 ;
union V_502 * V_503 ;
int V_39 ;
static const short V_504 [] = {
[ V_66 ] = V_505 ,
[ V_68 ] = V_506 ,
[ V_477 ] = V_507 ,
} ;
if ( V_60 == V_80 )
return true ;
if ( ! V_44 -> V_186 . V_508 )
return false ;
for ( V_39 = 0 ; V_39 < V_44 -> V_186 . V_508 ; V_39 ++ ) {
V_503 = V_44 -> V_186 . V_509 + V_39 ;
if ( V_503 -> V_510 . V_511 == V_504 [ V_60 ] &&
( V_503 -> V_510 . V_512 & V_513 ) ==
( V_514 & V_513 ) )
return true ;
}
return false ;
}
static void
F_251 ( struct V_1 * V_1 , struct V_8 * V_9 )
{
struct V_22 * V_22 = F_12 ( V_9 ) ;
F_252 ( V_9 ) ;
F_253 ( V_9 ) ;
V_1 -> V_189 = true ;
if ( F_1 ( V_1 ) ) {
F_254 ( V_9 -> V_7 ) ;
F_255 (
& V_9 -> V_4 ,
V_9 -> V_7 -> V_233 . V_497 ,
V_515 ) ;
V_22 -> V_24 . V_183 = V_515 ;
}
}
static void
F_163 ( struct V_6 * V_7 ,
struct V_1 * V_1 ,
struct V_325 * V_101 )
{
struct V_43 * V_44 = V_7 -> V_45 ;
struct V_325 V_516 , V_186 , V_517 , V_518 ;
T_3 V_519 , V_520 , V_521 , V_230 ;
int V_220 , V_522 , V_523 , V_524 ;
if ( F_24 ( V_7 ) ) {
V_220 = V_69 ;
V_522 = V_525 ;
V_523 = V_526 ;
V_524 = V_527 ;
} else {
enum V_57 V_57 = F_20 ( V_1 ) ;
V_220 = F_25 ( V_57 ) ;
V_522 = F_22 ( V_57 ) ;
V_523 = F_256 ( V_57 ) ;
V_524 = F_257 ( V_57 ) ;
}
V_230 = F_91 ( V_1 ) ;
F_54 ( V_220 , V_230 ) ;
V_519 = F_19 ( V_522 ) ;
V_520 = F_19 ( V_523 ) ;
V_521 = F_19 ( V_524 ) ;
V_516 . V_528 = ( V_519 & V_529 ) >>
V_530 ;
V_516 . V_531 = ( V_519 & V_532 ) >>
V_533 ;
V_516 . V_534 = ( V_520 & V_535 ) >>
V_536 ;
V_516 . V_537 = ( V_520 & V_538 ) >>
V_539 ;
V_516 . V_540 = ( ( V_521 & V_541 ) >>
V_542 ) * 1000 ;
F_31 ( L_79 ,
V_516 . V_528 , V_516 . V_531 , V_516 . V_534 , V_516 . V_537 , V_516 . V_540 ) ;
V_186 = V_44 -> V_186 . V_543 ;
V_517 . V_528 = 210 * 10 ;
V_517 . V_531 = 50 * 10 ;
V_517 . V_534 = 50 * 10 ;
V_517 . V_537 = 500 * 10 ;
V_517 . V_540 = ( 510 + 100 ) * 10 ;
F_31 ( L_80 ,
V_186 . V_528 , V_186 . V_531 , V_186 . V_534 , V_186 . V_537 , V_186 . V_540 ) ;
#define F_258 ( T_7 ) final.field = (max(cur.field, vbt.field) == 0 ? \
spec.field : \
max(cur.field, vbt.field))
F_258 ( V_528 ) ;
F_258 ( V_531 ) ;
F_258 ( V_534 ) ;
F_258 ( V_537 ) ;
F_258 ( V_540 ) ;
#undef F_258
#define F_259 ( T_7 ) (DIV_ROUND_UP(final.field, 10))
V_1 -> V_232 = F_259 ( V_528 ) ;
V_1 -> V_244 = F_259 ( V_531 ) ;
V_1 -> V_245 = F_259 ( V_534 ) ;
V_1 -> V_235 = F_259 ( V_537 ) ;
V_1 -> V_240 = F_259 ( V_540 ) ;
#undef F_259
F_31 ( L_81 ,
V_1 -> V_232 , V_1 -> V_235 ,
V_1 -> V_240 ) ;
F_31 ( L_82 ,
V_1 -> V_244 , V_1 -> V_245 ) ;
if ( V_101 )
* V_101 = V_518 ;
}
static void
F_164 ( struct V_6 * V_7 ,
struct V_1 * V_1 ,
struct V_325 * V_544 )
{
struct V_43 * V_44 = V_7 -> V_45 ;
T_3 V_519 , V_520 , V_521 , V_63 = 0 ;
int div = F_24 ( V_7 ) ? F_45 ( V_7 ) : F_17 ( V_7 ) ;
int V_522 , V_523 , V_524 ;
if ( F_24 ( V_7 ) ) {
V_522 = V_525 ;
V_523 = V_526 ;
V_524 = V_527 ;
} else {
enum V_57 V_57 = F_20 ( V_1 ) ;
V_522 = F_22 ( V_57 ) ;
V_523 = F_256 ( V_57 ) ;
V_524 = F_257 ( V_57 ) ;
}
V_519 = ( V_544 -> V_528 << V_530 ) |
( V_544 -> V_531 << V_533 ) ;
V_520 = ( V_544 -> V_534 << V_536 ) |
( V_544 -> V_537 << V_539 ) ;
V_521 = ( ( 100 * div ) / 2 - 1 ) << V_545 ;
V_521 |= ( F_44 ( V_544 -> V_540 , 1000 )
<< V_542 ) ;
if ( F_18 ( V_7 ) ) {
if ( F_2 ( V_1 ) -> V_60 == V_66 )
V_63 = V_65 ;
else
V_63 = V_67 ;
} else if ( F_206 ( V_7 ) || F_85 ( V_7 ) ) {
if ( F_2 ( V_1 ) -> V_60 == V_80 )
V_63 = V_546 ;
else
V_63 = V_547 ;
}
V_519 |= V_63 ;
F_54 ( V_522 , V_519 ) ;
F_54 ( V_523 , V_520 ) ;
F_54 ( V_524 , V_521 ) ;
F_31 ( L_83 ,
F_19 ( V_522 ) ,
F_19 ( V_523 ) ,
F_19 ( V_524 ) ) ;
}
static bool F_260 ( struct V_1 * V_1 ,
struct V_22 * V_22 )
{
struct V_8 * V_9 = & V_22 -> V_4 ;
struct V_2 * V_3 = F_2 ( V_1 ) ;
struct V_6 * V_7 = V_3 -> V_4 . V_4 . V_7 ;
struct V_43 * V_44 = V_7 -> V_45 ;
struct V_20 * V_23 = NULL ;
struct V_325 V_326 = { 0 } ;
bool V_548 ;
struct V_20 * V_549 ;
struct V_480 * V_480 ;
if ( ! F_1 ( V_1 ) )
return true ;
F_163 ( V_7 , V_1 , & V_326 ) ;
F_62 ( V_1 ) ;
V_548 = F_207 ( V_1 ) ;
F_64 ( V_1 , false ) ;
if ( V_548 ) {
if ( V_1 -> V_11 [ V_248 ] >= 0x11 )
V_44 -> V_550 =
V_1 -> V_11 [ V_551 ] &
V_552 ;
} else {
F_261 ( L_84 ) ;
return false ;
}
F_164 ( V_7 , V_1 ,
& V_326 ) ;
V_480 = F_224 ( V_9 , & V_1 -> V_128 ) ;
if ( V_480 ) {
if ( F_262 ( V_9 , V_480 ) ) {
F_263 ( V_9 ,
V_480 ) ;
F_264 ( V_9 , V_480 ) ;
} else {
F_231 ( V_480 ) ;
V_480 = F_265 ( - V_496 ) ;
}
} else {
V_480 = F_265 ( - V_553 ) ;
}
V_22 -> V_480 = V_480 ;
F_144 (scan, &connector->probed_modes, head) {
if ( ( V_549 -> type & V_554 ) ) {
V_23 = F_233 ( V_7 , V_549 ) ;
break;
}
}
if ( ! V_23 && V_44 -> V_186 . V_555 ) {
V_23 = F_233 ( V_7 ,
V_44 -> V_186 . V_555 ) ;
if ( V_23 )
V_23 -> type |= V_554 ;
}
F_266 ( & V_22 -> V_24 , V_23 ) ;
F_267 ( V_9 ) ;
return true ;
}
bool
F_268 ( struct V_2 * V_3 ,
struct V_22 * V_22 )
{
struct V_8 * V_9 = & V_22 -> V_4 ;
struct V_1 * V_1 = & V_3 -> V_501 ;
struct V_158 * V_158 = & V_3 -> V_4 ;
struct V_6 * V_7 = V_158 -> V_4 . V_7 ;
struct V_43 * V_44 = V_7 -> V_45 ;
enum V_60 V_60 = V_3 -> V_60 ;
const char * V_148 = NULL ;
int type , error ;
V_1 -> V_201 = F_19 ( V_1 -> V_203 ) ;
V_1 -> V_174 = V_22 ;
if ( F_250 ( V_7 , V_60 ) )
type = V_500 ;
else
type = V_556 ;
if ( type == V_500 )
V_158 -> type = V_5 ;
F_31 ( L_85 ,
type == V_500 ? L_86 : L_87 ,
F_269 ( V_60 ) ) ;
F_270 ( V_7 , V_9 , & V_557 , type ) ;
F_271 ( V_9 , & V_558 ) ;
V_9 -> V_559 = true ;
V_9 -> V_560 = 0 ;
F_272 ( & V_1 -> V_238 ,
F_94 ) ;
F_273 ( V_22 , V_158 ) ;
F_274 ( V_9 ) ;
if ( F_39 ( V_7 ) )
V_22 -> V_561 = V_562 ;
else
V_22 -> V_561 = V_563 ;
V_1 -> V_75 = V_1 -> V_203 + 0x10 ;
if ( F_39 ( V_7 ) ) {
switch ( V_3 -> V_60 ) {
case V_80 :
V_1 -> V_75 = V_96 ;
break;
case V_66 :
V_1 -> V_75 = V_564 ;
break;
case V_68 :
V_1 -> V_75 = V_565 ;
break;
case V_477 :
V_1 -> V_75 = V_566 ;
break;
default:
F_275 () ;
}
}
switch ( V_60 ) {
case V_80 :
V_158 -> V_567 = V_568 ;
V_148 = L_88 ;
break;
case V_66 :
V_158 -> V_567 = V_569 ;
V_148 = L_89 ;
break;
case V_68 :
V_158 -> V_567 = V_570 ;
V_148 = L_90 ;
break;
case V_477 :
V_158 -> V_567 = V_571 ;
V_148 = L_91 ;
break;
default:
F_275 () ;
}
error = F_65 ( V_1 , V_22 , V_148 ) ;
F_8 ( error , L_92 ,
error , F_269 ( V_60 ) ) ;
V_1 -> V_280 = false ;
if ( ! F_260 ( V_1 , V_22 ) ) {
F_244 ( & V_1 -> V_128 ) ;
if ( F_1 ( V_1 ) ) {
F_246 ( & V_1 -> V_238 ) ;
F_96 ( & V_7 -> V_233 . V_234 ) ;
F_92 ( V_1 ) ;
F_97 ( & V_7 -> V_233 . V_234 ) ;
}
F_276 ( V_9 ) ;
F_242 ( V_9 ) ;
return false ;
}
F_251 ( V_1 , V_9 ) ;
if ( F_68 ( V_7 ) && ! F_277 ( V_7 ) ) {
T_3 V_406 = F_19 ( V_572 ) ;
F_54 ( V_572 , ( V_406 & ~ 0xf ) | 0xd ) ;
}
return true ;
}
void
F_278 ( struct V_6 * V_7 , int V_203 , enum V_60 V_60 )
{
struct V_2 * V_3 ;
struct V_158 * V_158 ;
struct V_429 * V_159 ;
struct V_22 * V_22 ;
V_3 = F_279 ( sizeof( * V_3 ) , V_573 ) ;
if ( ! V_3 )
return;
V_22 = F_279 ( sizeof( * V_22 ) , V_573 ) ;
if ( ! V_22 ) {
F_231 ( V_3 ) ;
return;
}
V_158 = & V_3 -> V_4 ;
V_159 = & V_158 -> V_4 ;
F_280 ( V_7 , & V_158 -> V_4 , & V_574 ,
V_575 ) ;
V_158 -> V_576 = F_71 ;
V_158 -> V_577 = F_79 ;
V_158 -> V_578 = F_145 ;
V_158 -> V_579 = F_147 ;
V_158 -> V_561 = F_111 ;
V_158 -> V_580 = F_116 ;
if ( F_18 ( V_7 ) ) {
V_158 -> V_581 = F_166 ;
V_158 -> V_582 = F_155 ;
V_158 -> V_583 = F_153 ;
} else {
V_158 -> V_582 = F_154 ;
V_158 -> V_583 = F_152 ;
}
V_3 -> V_60 = V_60 ;
V_3 -> V_501 . V_203 = V_203 ;
V_158 -> type = V_486 ;
V_158 -> V_584 = ( 1 << 0 ) | ( 1 << 1 ) | ( 1 << 2 ) ;
V_158 -> V_585 = false ;
V_158 -> V_586 = F_247 ;
if ( ! F_268 ( V_3 , V_22 ) ) {
F_245 ( V_159 ) ;
F_231 ( V_3 ) ;
F_231 ( V_22 ) ;
}
}
