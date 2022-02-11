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
static int
F_10 ( struct V_1 * V_1 )
{
int V_12 = V_1 -> V_13 [ V_14 ] ;
switch ( V_12 ) {
case V_15 :
case V_16 :
break;
default:
V_12 = V_15 ;
break;
}
return V_12 ;
}
static int
F_11 ( int V_17 , int V_18 )
{
return ( V_17 * V_18 + 9 ) / 10 ;
}
static int
F_12 ( int V_19 , int V_20 )
{
return ( V_19 * V_20 * 8 ) / 10 ;
}
static int
F_13 ( struct V_8 * V_9 ,
struct V_21 * V_22 )
{
struct V_1 * V_1 = F_6 ( V_9 ) ;
struct V_23 * V_23 = F_14 ( V_9 ) ;
struct V_21 * V_24 = V_23 -> V_25 . V_24 ;
int V_26 = V_22 -> clock ;
int V_27 , V_28 , V_20 , V_19 ;
if ( F_1 ( V_1 ) && V_24 ) {
if ( V_22 -> V_29 > V_24 -> V_29 )
return V_30 ;
if ( V_22 -> V_31 > V_24 -> V_31 )
return V_30 ;
V_26 = V_24 -> clock ;
}
V_19 = F_15 ( F_10 ( V_1 ) ) ;
V_20 = F_16 ( V_1 -> V_13 ) ;
V_27 = F_12 ( V_19 , V_20 ) ;
V_28 = F_11 ( V_26 , 18 ) ;
if ( V_28 > V_27 )
return V_32 ;
if ( V_22 -> clock < 10000 )
return V_33 ;
if ( V_22 -> V_34 & V_35 )
return V_36 ;
return V_37 ;
}
static T_1
F_17 ( T_2 * V_38 , int V_39 )
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
F_18 ( T_1 V_38 , T_2 * V_42 , int V_43 )
{
int V_40 ;
if ( V_43 > 4 )
V_43 = 4 ;
for ( V_40 = 0 ; V_40 < V_43 ; V_40 ++ )
V_42 [ V_40 ] = V_38 >> ( ( 3 - V_40 ) * 8 ) ;
}
static int
F_19 ( struct V_6 * V_7 )
{
struct V_44 * V_45 = V_7 -> V_46 ;
T_1 V_47 ;
if ( F_20 ( V_7 ) )
return 200 ;
V_47 = F_21 ( V_48 ) ;
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
static bool F_22 ( struct V_1 * V_1 )
{
struct V_6 * V_7 = F_5 ( V_1 ) ;
struct V_44 * V_45 = V_7 -> V_46 ;
T_3 V_58 ;
V_58 = F_20 ( V_7 ) ? V_59 : V_60 ;
return ( F_21 ( V_58 ) & V_61 ) != 0 ;
}
static bool F_23 ( struct V_1 * V_1 )
{
struct V_6 * V_7 = F_5 ( V_1 ) ;
struct V_44 * V_45 = V_7 -> V_46 ;
T_3 V_62 ;
V_62 = F_20 ( V_7 ) ? V_63 : V_64 ;
return ( F_21 ( V_62 ) & V_65 ) != 0 ;
}
static void
F_24 ( struct V_1 * V_1 )
{
struct V_6 * V_7 = F_5 ( V_1 ) ;
struct V_44 * V_45 = V_7 -> V_46 ;
T_3 V_58 , V_62 ;
if ( ! F_1 ( V_1 ) )
return;
V_58 = F_20 ( V_7 ) ? V_59 : V_60 ;
V_62 = F_20 ( V_7 ) ? V_63 : V_64 ;
if ( ! F_22 ( V_1 ) && ! F_23 ( V_1 ) ) {
F_25 ( 1 , L_1 ) ;
F_26 ( L_2 ,
F_21 ( V_58 ) ,
F_21 ( V_62 ) ) ;
}
}
static T_1
F_27 ( struct V_1 * V_1 , bool V_66 )
{
struct V_2 * V_3 = F_2 ( V_1 ) ;
struct V_6 * V_7 = V_3 -> V_4 . V_4 . V_7 ;
struct V_44 * V_45 = V_7 -> V_46 ;
T_1 V_67 = V_1 -> V_68 ;
T_1 V_69 ;
bool V_70 ;
#define F_28 (((status = I915_READ_NOTRACE(ch_ctl)) & DP_AUX_CH_CTL_SEND_BUSY) == 0)
if ( V_66 )
V_70 = F_29 ( V_45 -> V_71 , F_28 ,
F_30 ( 10 ) ) ;
else
V_70 = F_31 ( F_28 , 10 ) == 0 ;
if ( ! V_70 )
F_32 ( L_3 ,
V_66 ) ;
#undef F_28
return V_69 ;
}
static int
F_33 ( struct V_1 * V_1 ,
T_2 * V_72 , int V_73 ,
T_2 * V_74 , int V_75 )
{
struct V_2 * V_3 = F_2 ( V_1 ) ;
struct V_6 * V_7 = V_3 -> V_4 . V_4 . V_7 ;
struct V_44 * V_45 = V_7 -> V_46 ;
T_1 V_67 = V_1 -> V_68 ;
T_1 V_76 = V_67 + 4 ;
int V_40 , V_77 , V_78 ;
T_1 V_69 ;
T_1 V_79 ;
int V_80 , V_81 ;
bool V_66 = F_34 ( V_7 ) -> V_82 >= 5 && ! F_20 ( V_7 ) ;
F_35 ( & V_45 -> V_83 , 0 ) ;
F_24 ( V_1 ) ;
if ( F_4 ( V_1 ) ) {
if ( F_36 ( V_7 ) )
V_79 = F_37 ( V_45 ) >> 1 ;
else if ( F_20 ( V_7 ) )
V_79 = 100 ;
else if ( F_38 ( V_7 ) || F_39 ( V_7 ) )
V_79 = 200 ;
else
V_79 = 225 ;
} else if ( V_45 -> V_84 == V_85 ) {
V_79 = 74 ;
} else if ( F_40 ( V_7 ) ) {
V_79 = F_41 ( F_42 ( V_7 ) , 2 ) ;
} else {
V_79 = F_19 ( V_7 ) / 2 ;
}
if ( F_38 ( V_7 ) )
V_81 = 3 ;
else
V_81 = 5 ;
for ( V_80 = 0 ; V_80 < 3 ; V_80 ++ ) {
V_69 = F_43 ( V_67 ) ;
if ( ( V_69 & V_86 ) == 0 )
break;
F_44 ( 1 ) ;
}
if ( V_80 == 3 ) {
F_25 ( 1 , L_4 ,
F_21 ( V_67 ) ) ;
V_77 = - V_87 ;
goto V_88;
}
for ( V_80 = 0 ; V_80 < 5 ; V_80 ++ ) {
for ( V_40 = 0 ; V_40 < V_73 ; V_40 += 4 )
F_45 ( V_76 + V_40 ,
F_17 ( V_72 + V_40 , V_73 - V_40 ) ) ;
F_45 ( V_67 ,
V_86 |
( V_66 ? V_89 : 0 ) |
V_90 |
( V_73 << V_91 ) |
( V_81 << V_92 ) |
( V_79 << V_93 ) |
V_94 |
V_95 |
V_96 ) ;
V_69 = F_27 ( V_1 , V_66 ) ;
F_45 ( V_67 ,
V_69 |
V_94 |
V_95 |
V_96 ) ;
if ( V_69 & ( V_95 |
V_96 ) )
continue;
if ( V_69 & V_94 )
break;
}
if ( ( V_69 & V_94 ) == 0 ) {
F_32 ( L_5 , V_69 ) ;
V_77 = - V_87 ;
goto V_88;
}
if ( V_69 & V_96 ) {
F_32 ( L_6 , V_69 ) ;
V_77 = - V_97 ;
goto V_88;
}
if ( V_69 & V_95 ) {
F_26 ( L_7 , V_69 ) ;
V_77 = - V_98 ;
goto V_88;
}
V_78 = ( ( V_69 & V_99 ) >>
V_91 ) ;
if ( V_78 > V_75 )
V_78 = V_75 ;
for ( V_40 = 0 ; V_40 < V_78 ; V_40 += 4 )
F_18 ( F_21 ( V_76 + V_40 ) ,
V_74 + V_40 , V_78 - V_40 ) ;
V_77 = V_78 ;
V_88:
F_35 ( & V_45 -> V_83 , V_100 ) ;
return V_77 ;
}
static int
F_46 ( struct V_1 * V_1 ,
T_4 V_101 , T_2 * V_72 , int V_73 )
{
int V_77 ;
T_2 V_102 [ 20 ] ;
int V_103 ;
T_2 V_104 ;
F_24 ( V_1 ) ;
if ( V_73 > 16 )
return - 1 ;
V_102 [ 0 ] = V_105 << 4 ;
V_102 [ 1 ] = V_101 >> 8 ;
V_102 [ 2 ] = V_101 & 0xff ;
V_102 [ 3 ] = V_73 - 1 ;
memcpy ( & V_102 [ 4 ] , V_72 , V_73 ) ;
V_103 = V_73 + 4 ;
for (; ; ) {
V_77 = F_33 ( V_1 , V_102 , V_103 , & V_104 , 1 ) ;
if ( V_77 < 0 )
return V_77 ;
if ( ( V_104 & V_106 ) == V_107 )
break;
else if ( ( V_104 & V_106 ) == V_108 )
F_47 ( 100 ) ;
else
return - V_97 ;
}
return V_73 ;
}
static int
F_48 ( struct V_1 * V_1 ,
T_4 V_101 , T_2 V_109 )
{
return F_46 ( V_1 , V_101 , & V_109 , 1 ) ;
}
static int
F_49 ( struct V_1 * V_1 ,
T_4 V_101 , T_2 * V_74 , int V_78 )
{
T_2 V_102 [ 4 ] ;
int V_103 ;
T_2 V_110 [ 20 ] ;
int V_111 ;
T_2 V_104 ;
int V_77 ;
F_24 ( V_1 ) ;
V_102 [ 0 ] = V_112 << 4 ;
V_102 [ 1 ] = V_101 >> 8 ;
V_102 [ 2 ] = V_101 & 0xff ;
V_102 [ 3 ] = V_78 - 1 ;
V_103 = 4 ;
V_111 = V_78 + 1 ;
for (; ; ) {
V_77 = F_33 ( V_1 , V_102 , V_103 ,
V_110 , V_111 ) ;
if ( V_77 == 0 )
return - V_113 ;
if ( V_77 < 0 )
return V_77 ;
V_104 = V_110 [ 0 ] ;
if ( ( V_104 & V_106 ) == V_107 ) {
memcpy ( V_74 , V_110 + 1 , V_77 - 1 ) ;
return V_77 - 1 ;
}
else if ( ( V_104 & V_106 ) == V_108 )
F_47 ( 100 ) ;
else
return - V_97 ;
}
}
static int
F_50 ( struct V_114 * V_115 , int V_22 ,
T_2 V_116 , T_2 * V_117 )
{
struct V_118 * V_119 = V_115 -> V_119 ;
struct V_1 * V_1 = F_51 ( V_115 ,
struct V_1 ,
V_115 ) ;
T_4 V_101 = V_119 -> V_101 ;
T_2 V_102 [ 5 ] ;
T_2 V_110 [ 2 ] ;
unsigned V_120 ;
int V_103 ;
int V_111 ;
int V_77 ;
F_24 ( V_1 ) ;
if ( V_22 & V_121 )
V_102 [ 0 ] = V_122 << 4 ;
else
V_102 [ 0 ] = V_123 << 4 ;
if ( ! ( V_22 & V_124 ) )
V_102 [ 0 ] |= V_125 << 4 ;
V_102 [ 1 ] = V_101 >> 8 ;
V_102 [ 2 ] = V_101 ;
switch ( V_22 ) {
case V_126 :
V_102 [ 3 ] = 0 ;
V_102 [ 4 ] = V_116 ;
V_103 = 5 ;
V_111 = 1 ;
break;
case V_121 :
V_102 [ 3 ] = 0 ;
V_103 = 4 ;
V_111 = 2 ;
break;
default:
V_103 = 3 ;
V_111 = 1 ;
break;
}
for ( V_120 = 0 ; V_120 < 5 ; V_120 ++ ) {
V_77 = F_33 ( V_1 ,
V_102 , V_103 ,
V_110 , V_111 ) ;
if ( V_77 < 0 ) {
F_26 ( L_8 , V_77 ) ;
return V_77 ;
}
switch ( V_110 [ 0 ] & V_106 ) {
case V_107 :
break;
case V_127 :
F_26 ( L_9 ) ;
return - V_128 ;
case V_108 :
F_47 ( 100 ) ;
continue;
default:
F_32 ( L_10 ,
V_110 [ 0 ] ) ;
return - V_128 ;
}
switch ( V_110 [ 0 ] & V_129 ) {
case V_130 :
if ( V_22 == V_121 ) {
* V_117 = V_110 [ 1 ] ;
}
return V_111 - 1 ;
case V_131 :
F_26 ( L_11 ) ;
return - V_128 ;
case V_132 :
F_26 ( L_12 ) ;
F_47 ( 100 ) ;
break;
default:
F_32 ( L_13 , V_110 [ 0 ] ) ;
return - V_128 ;
}
}
F_32 ( L_14 ) ;
return - V_128 ;
}
static int
F_52 ( struct V_1 * V_1 ,
struct V_23 * V_23 , const char * V_133 )
{
int V_77 ;
F_26 ( L_15 , V_133 ) ;
V_1 -> V_134 . V_135 = false ;
V_1 -> V_134 . V_101 = 0 ;
V_1 -> V_134 . V_136 = F_50 ;
memset ( & V_1 -> V_115 , '\0' , sizeof( V_1 -> V_115 ) ) ;
V_1 -> V_115 . V_137 = V_138 ;
V_1 -> V_115 . V_139 = V_140 ;
strncpy ( V_1 -> V_115 . V_133 , V_133 , sizeof( V_1 -> V_115 . V_133 ) - 1 ) ;
V_1 -> V_115 . V_133 [ sizeof( V_1 -> V_115 . V_133 ) - 1 ] = '\0' ;
V_1 -> V_115 . V_119 = & V_1 -> V_134 ;
V_1 -> V_115 . V_7 . V_141 = & V_23 -> V_4 . V_142 ;
F_53 ( V_1 ) ;
V_77 = F_54 ( & V_1 -> V_115 ) ;
F_55 ( V_1 , false ) ;
return V_77 ;
}
bool
F_56 ( struct V_143 * V_11 ,
struct V_144 * V_145 )
{
struct V_6 * V_7 = V_11 -> V_4 . V_7 ;
struct V_44 * V_45 = V_7 -> V_46 ;
struct V_21 * V_146 = & V_145 -> V_146 ;
struct V_21 * V_22 = & V_145 -> V_147 ;
struct V_1 * V_1 = F_7 ( & V_11 -> V_4 ) ;
struct V_23 * V_23 = V_1 -> V_148 ;
int V_149 , clock ;
int V_150 = F_16 ( V_1 -> V_13 ) ;
int V_151 = F_10 ( V_1 ) == V_16 ? 1 : 0 ;
int V_18 , V_28 ;
static int V_152 [ 2 ] = { V_15 , V_16 } ;
int V_26 , V_153 , V_154 ;
if ( F_40 ( V_7 ) && ! F_36 ( V_7 ) && ! F_4 ( V_1 ) )
V_145 -> V_155 = true ;
V_145 -> V_156 = true ;
if ( F_1 ( V_1 ) && V_23 -> V_25 . V_24 ) {
F_57 ( V_23 -> V_25 . V_24 ,
V_146 ) ;
F_58 ( V_7 ,
V_23 -> V_25 . V_157 ,
V_22 , V_146 ) ;
}
V_26 = V_146 -> clock ;
if ( V_146 -> V_34 & V_35 )
return false ;
F_26 ( L_16
L_17 ,
V_150 , V_152 [ V_151 ] , V_146 -> clock ) ;
V_18 = F_59 ( int , 8 * 3 , V_145 -> V_158 ) ;
if ( F_1 ( V_1 ) && V_45 -> V_159 . V_18 )
V_18 = F_59 ( int , V_18 , V_45 -> V_159 . V_18 ) ;
for (; V_18 >= 6 * 3 ; V_18 -= 2 * 3 ) {
V_28 = F_11 ( V_26 , V_18 ) ;
for ( clock = 0 ; clock <= V_151 ; clock ++ ) {
for ( V_149 = 1 ; V_149 <= V_150 ; V_149 <<= 1 ) {
V_154 = F_15 ( V_152 [ clock ] ) ;
V_153 = F_12 ( V_154 ,
V_149 ) ;
if ( V_28 <= V_153 ) {
goto V_160;
}
}
}
}
return false ;
V_160:
if ( V_1 -> V_161 ) {
if ( V_18 != 18 && F_60 ( V_146 ) > 1 )
V_1 -> V_162 = V_163 ;
else
V_1 -> V_162 = 0 ;
}
if ( V_1 -> V_162 )
V_145 -> V_164 = true ;
V_1 -> V_165 = V_152 [ clock ] ;
V_1 -> V_149 = V_149 ;
V_146 -> clock = F_15 ( V_1 -> V_165 ) ;
V_145 -> V_158 = V_18 ;
V_145 -> V_166 = V_26 ;
F_26 ( L_18 ,
V_1 -> V_165 , V_1 -> V_149 ,
V_146 -> clock , V_18 ) ;
F_26 ( L_19 ,
V_28 , V_153 ) ;
F_61 ( V_18 , V_149 ,
V_26 , V_146 -> clock ,
& V_145 -> V_167 ) ;
return true ;
}
void F_62 ( struct V_1 * V_1 )
{
memset ( V_1 -> V_168 , 0 , V_169 ) ;
V_1 -> V_168 [ 0 ] = V_1 -> V_165 ;
V_1 -> V_168 [ 1 ] = V_1 -> V_149 ;
V_1 -> V_168 [ 8 ] = V_170 ;
if ( V_1 -> V_13 [ V_171 ] >= 0x11 &&
( V_1 -> V_13 [ V_172 ] & V_173 ) ) {
V_1 -> V_168 [ 1 ] |= V_174 ;
}
}
static void F_63 ( struct V_175 * V_176 , int clock )
{
struct V_6 * V_7 = V_176 -> V_7 ;
struct V_44 * V_45 = V_7 -> V_46 ;
T_3 V_177 ;
F_26 ( L_20 , clock ) ;
V_177 = F_21 ( V_178 ) ;
V_177 &= ~ V_179 ;
if ( clock < 200000 ) {
F_26 ( L_21 ) ;
V_177 |= V_180 ;
} else {
V_177 |= V_181 ;
}
F_45 ( V_178 , V_177 ) ;
F_64 ( V_178 ) ;
F_47 ( 500 ) ;
}
static void
F_65 ( struct V_10 * V_11 , struct V_21 * V_22 ,
struct V_21 * V_146 )
{
struct V_6 * V_7 = V_11 -> V_7 ;
struct V_44 * V_45 = V_7 -> V_46 ;
struct V_1 * V_1 = F_7 ( V_11 ) ;
struct V_175 * V_176 = V_11 -> V_176 ;
struct V_182 * V_182 = F_66 ( V_176 ) ;
V_1 -> V_183 = F_21 ( V_1 -> V_184 ) & V_185 ;
V_1 -> V_183 |= V_186 | V_187 ;
switch ( V_1 -> V_149 ) {
case 1 :
V_1 -> V_183 |= V_188 ;
break;
case 2 :
V_1 -> V_183 |= V_189 ;
break;
case 4 :
V_1 -> V_183 |= V_190 ;
break;
}
if ( V_1 -> V_191 ) {
F_67 ( L_22 ,
F_68 ( V_182 -> V_192 ) ) ;
V_1 -> V_183 |= V_193 ;
F_69 ( V_11 , V_146 ) ;
}
F_62 ( V_1 ) ;
if ( F_4 ( V_1 ) && F_39 ( V_7 ) && ! F_20 ( V_7 ) ) {
if ( V_146 -> V_34 & V_194 )
V_1 -> V_183 |= V_195 ;
if ( V_146 -> V_34 & V_196 )
V_1 -> V_183 |= V_197 ;
V_1 -> V_183 |= V_198 ;
if ( V_1 -> V_168 [ 1 ] & V_174 )
V_1 -> V_183 |= V_199 ;
V_1 -> V_183 |= V_182 -> V_192 << 29 ;
if ( V_146 -> clock < 200000 )
V_1 -> V_183 |= V_180 ;
else
V_1 -> V_183 |= V_181 ;
} else if ( ! F_70 ( V_7 ) || F_4 ( V_1 ) ) {
if ( ! F_40 ( V_7 ) && ! F_20 ( V_7 ) )
V_1 -> V_183 |= V_1 -> V_162 ;
if ( V_146 -> V_34 & V_194 )
V_1 -> V_183 |= V_195 ;
if ( V_146 -> V_34 & V_196 )
V_1 -> V_183 |= V_197 ;
V_1 -> V_183 |= V_200 ;
if ( V_1 -> V_168 [ 1 ] & V_174 )
V_1 -> V_183 |= V_199 ;
if ( V_182 -> V_192 == 1 )
V_1 -> V_183 |= V_201 ;
if ( F_4 ( V_1 ) && ! F_20 ( V_7 ) ) {
if ( V_146 -> clock < 200000 )
V_1 -> V_183 |= V_180 ;
else
V_1 -> V_183 |= V_181 ;
}
} else {
V_1 -> V_183 |= V_198 ;
}
if ( F_4 ( V_1 ) && ! F_20 ( V_7 ) )
F_63 ( V_176 , V_146 -> clock ) ;
}
static void F_71 ( struct V_1 * V_1 ,
T_3 V_202 ,
T_3 V_203 )
{
struct V_6 * V_7 = F_5 ( V_1 ) ;
struct V_44 * V_45 = V_7 -> V_46 ;
T_3 V_58 , V_62 ;
V_58 = F_20 ( V_7 ) ? V_59 : V_60 ;
V_62 = F_20 ( V_7 ) ? V_63 : V_64 ;
F_26 ( L_23 ,
V_202 , V_203 ,
F_21 ( V_58 ) ,
F_21 ( V_62 ) ) ;
if ( F_72 ( ( F_21 ( V_58 ) & V_202 ) == V_203 , 5000 , 10 ) ) {
F_32 ( L_24 ,
F_21 ( V_58 ) ,
F_21 ( V_62 ) ) ;
}
}
static void F_73 ( struct V_1 * V_1 )
{
F_26 ( L_25 ) ;
F_71 ( V_1 , V_204 , V_205 ) ;
}
static void F_74 ( struct V_1 * V_1 )
{
F_26 ( L_26 ) ;
F_71 ( V_1 , V_206 , V_207 ) ;
}
static void F_75 ( struct V_1 * V_1 )
{
F_26 ( L_27 ) ;
F_71 ( V_1 , V_208 , V_209 ) ;
}
static T_3 F_76 ( struct V_1 * V_1 )
{
struct V_6 * V_7 = F_5 ( V_1 ) ;
struct V_44 * V_45 = V_7 -> V_46 ;
T_3 V_210 ;
T_3 V_62 ;
V_62 = F_20 ( V_7 ) ? V_63 : V_64 ;
V_210 = F_21 ( V_62 ) ;
V_210 &= ~ V_211 ;
V_210 |= V_212 ;
return V_210 ;
}
void F_53 ( struct V_1 * V_1 )
{
struct V_6 * V_7 = F_5 ( V_1 ) ;
struct V_44 * V_45 = V_7 -> V_46 ;
T_3 V_213 ;
T_3 V_58 , V_62 ;
if ( ! F_1 ( V_1 ) )
return;
F_26 ( L_28 ) ;
F_25 ( V_1 -> V_214 ,
L_29 ) ;
V_1 -> V_214 = true ;
if ( F_23 ( V_1 ) ) {
F_26 ( L_30 ) ;
return;
}
if ( ! F_22 ( V_1 ) )
F_75 ( V_1 ) ;
V_213 = F_76 ( V_1 ) ;
V_213 |= V_65 ;
V_58 = F_20 ( V_7 ) ? V_59 : V_60 ;
V_62 = F_20 ( V_7 ) ? V_63 : V_64 ;
F_45 ( V_62 , V_213 ) ;
F_64 ( V_62 ) ;
F_26 ( L_31 ,
F_21 ( V_58 ) , F_21 ( V_62 ) ) ;
if ( ! F_22 ( V_1 ) ) {
F_26 ( L_32 ) ;
F_44 ( V_1 -> V_215 ) ;
}
}
static void F_77 ( struct V_1 * V_1 )
{
struct V_6 * V_7 = F_5 ( V_1 ) ;
struct V_44 * V_45 = V_7 -> V_46 ;
T_3 V_213 ;
T_3 V_58 , V_62 ;
F_78 ( ! F_79 ( & V_7 -> V_216 . V_217 ) ) ;
if ( ! V_1 -> V_214 && F_23 ( V_1 ) ) {
V_213 = F_76 ( V_1 ) ;
V_213 &= ~ V_65 ;
V_58 = F_20 ( V_7 ) ? V_59 : V_60 ;
V_62 = F_20 ( V_7 ) ? V_63 : V_64 ;
F_45 ( V_62 , V_213 ) ;
F_64 ( V_62 ) ;
F_26 ( L_31 ,
F_21 ( V_58 ) , F_21 ( V_62 ) ) ;
F_44 ( V_1 -> V_218 ) ;
}
}
static void F_80 ( struct V_219 * V_220 )
{
struct V_1 * V_1 = F_51 ( F_81 ( V_220 ) ,
struct V_1 , V_221 ) ;
struct V_6 * V_7 = F_5 ( V_1 ) ;
F_82 ( & V_7 -> V_216 . V_217 ) ;
F_77 ( V_1 ) ;
F_83 ( & V_7 -> V_216 . V_217 ) ;
}
void F_55 ( struct V_1 * V_1 , bool V_222 )
{
if ( ! F_1 ( V_1 ) )
return;
F_26 ( L_33 , V_1 -> V_214 ) ;
F_25 ( ! V_1 -> V_214 , L_34 ) ;
V_1 -> V_214 = false ;
if ( V_222 ) {
F_77 ( V_1 ) ;
} else {
F_84 ( & V_1 -> V_221 ,
F_85 ( V_1 -> V_223 * 5 ) ) ;
}
}
void F_86 ( struct V_1 * V_1 )
{
struct V_6 * V_7 = F_5 ( V_1 ) ;
struct V_44 * V_45 = V_7 -> V_46 ;
T_3 V_213 ;
T_3 V_62 ;
if ( ! F_1 ( V_1 ) )
return;
F_26 ( L_35 ) ;
if ( F_22 ( V_1 ) ) {
F_26 ( L_36 ) ;
return;
}
F_75 ( V_1 ) ;
V_213 = F_76 ( V_1 ) ;
if ( F_87 ( V_7 ) ) {
V_213 &= ~ V_224 ;
F_45 ( V_64 , V_213 ) ;
F_64 ( V_64 ) ;
}
V_213 |= V_225 ;
if ( ! F_87 ( V_7 ) )
V_213 |= V_224 ;
V_62 = F_20 ( V_7 ) ? V_63 : V_64 ;
F_45 ( V_62 , V_213 ) ;
F_64 ( V_62 ) ;
F_73 ( V_1 ) ;
if ( F_87 ( V_7 ) ) {
V_213 |= V_224 ;
F_45 ( V_64 , V_213 ) ;
F_64 ( V_64 ) ;
}
}
void F_88 ( struct V_1 * V_1 )
{
struct V_6 * V_7 = F_5 ( V_1 ) ;
struct V_44 * V_45 = V_7 -> V_46 ;
T_3 V_213 ;
T_3 V_62 ;
if ( ! F_1 ( V_1 ) )
return;
F_26 ( L_37 ) ;
F_25 ( ! V_1 -> V_214 , L_38 ) ;
V_213 = F_76 ( V_1 ) ;
V_213 &= ~ ( V_225 | V_65 | V_224 | V_226 ) ;
V_62 = F_20 ( V_7 ) ? V_63 : V_64 ;
F_45 ( V_62 , V_213 ) ;
F_64 ( V_62 ) ;
V_1 -> V_214 = false ;
F_74 ( V_1 ) ;
}
void F_89 ( struct V_1 * V_1 )
{
struct V_2 * V_3 = F_2 ( V_1 ) ;
struct V_6 * V_7 = V_3 -> V_4 . V_4 . V_7 ;
struct V_44 * V_45 = V_7 -> V_46 ;
int V_192 = F_66 ( V_3 -> V_4 . V_4 . V_176 ) -> V_192 ;
T_3 V_213 ;
T_3 V_62 ;
if ( ! F_1 ( V_1 ) )
return;
F_26 ( L_39 ) ;
F_44 ( V_1 -> V_227 ) ;
V_213 = F_76 ( V_1 ) ;
V_213 |= V_226 ;
V_62 = F_20 ( V_7 ) ? V_63 : V_64 ;
F_45 ( V_62 , V_213 ) ;
F_64 ( V_62 ) ;
F_90 ( V_7 , V_192 ) ;
}
void F_91 ( struct V_1 * V_1 )
{
struct V_6 * V_7 = F_5 ( V_1 ) ;
struct V_44 * V_45 = V_7 -> V_46 ;
T_3 V_213 ;
T_3 V_62 ;
if ( ! F_1 ( V_1 ) )
return;
F_92 ( V_7 ) ;
F_26 ( L_39 ) ;
V_213 = F_76 ( V_1 ) ;
V_213 &= ~ V_226 ;
V_62 = F_20 ( V_7 ) ? V_63 : V_64 ;
F_45 ( V_62 , V_213 ) ;
F_64 ( V_62 ) ;
F_44 ( V_1 -> V_228 ) ;
}
static void F_93 ( struct V_1 * V_1 )
{
struct V_2 * V_3 = F_2 ( V_1 ) ;
struct V_175 * V_176 = V_3 -> V_4 . V_4 . V_176 ;
struct V_6 * V_7 = V_176 -> V_7 ;
struct V_44 * V_45 = V_7 -> V_46 ;
T_3 V_177 ;
F_94 ( V_45 ,
F_66 ( V_176 ) -> V_192 ) ;
F_26 ( L_39 ) ;
V_177 = F_21 ( V_178 ) ;
F_25 ( V_177 & V_229 , L_40 ) ;
F_25 ( V_177 & V_230 , L_41 ) ;
V_1 -> V_183 &= ~ ( V_230 | V_193 ) ;
V_1 -> V_183 |= V_229 ;
F_45 ( V_178 , V_1 -> V_183 ) ;
F_64 ( V_178 ) ;
F_47 ( 200 ) ;
}
static void F_95 ( struct V_1 * V_1 )
{
struct V_2 * V_3 = F_2 ( V_1 ) ;
struct V_175 * V_176 = V_3 -> V_4 . V_4 . V_176 ;
struct V_6 * V_7 = V_176 -> V_7 ;
struct V_44 * V_45 = V_7 -> V_46 ;
T_3 V_177 ;
F_94 ( V_45 ,
F_66 ( V_176 ) -> V_192 ) ;
V_177 = F_21 ( V_178 ) ;
F_25 ( ( V_177 & V_229 ) == 0 ,
L_42 ) ;
F_25 ( V_177 & V_230 , L_41 ) ;
V_177 &= ~ V_229 ;
F_45 ( V_178 , V_177 ) ;
F_64 ( V_178 ) ;
F_47 ( 200 ) ;
}
void F_96 ( struct V_1 * V_1 , int V_22 )
{
int V_77 , V_40 ;
if ( V_1 -> V_13 [ V_171 ] < 0x11 )
return;
if ( V_22 != V_231 ) {
V_77 = F_48 ( V_1 , V_232 ,
V_233 ) ;
if ( V_77 != 1 )
F_67 ( L_43 ) ;
} else {
for ( V_40 = 0 ; V_40 < 3 ; V_40 ++ ) {
V_77 = F_48 ( V_1 ,
V_232 ,
V_234 ) ;
if ( V_77 == 1 )
break;
F_44 ( 1 ) ;
}
}
}
static bool F_97 ( struct V_143 * V_11 ,
enum V_192 * V_192 )
{
struct V_1 * V_1 = F_7 ( & V_11 -> V_4 ) ;
struct V_6 * V_7 = V_11 -> V_4 . V_7 ;
struct V_44 * V_45 = V_7 -> V_46 ;
T_3 V_235 = F_21 ( V_1 -> V_184 ) ;
if ( ! ( V_235 & V_230 ) )
return false ;
if ( F_4 ( V_1 ) && F_39 ( V_7 ) && ! F_20 ( V_7 ) ) {
* V_192 = F_98 ( V_235 ) ;
} else if ( ! F_70 ( V_7 ) || F_4 ( V_1 ) ) {
* V_192 = F_99 ( V_235 ) ;
} else {
T_3 V_236 ;
T_3 V_237 ;
int V_40 ;
switch ( V_1 -> V_184 ) {
case V_238 :
V_236 = V_239 ;
break;
case V_240 :
V_236 = V_241 ;
break;
case V_242 :
V_236 = V_243 ;
break;
default:
return true ;
}
F_100 (i) {
V_237 = F_21 ( F_101 ( V_40 ) ) ;
if ( ( V_237 & V_244 ) == V_236 ) {
* V_192 = V_40 ;
return true ;
}
}
F_26 ( L_44 ,
V_1 -> V_184 ) ;
}
return true ;
}
static void F_102 ( struct V_143 * V_11 )
{
struct V_1 * V_1 = F_7 ( & V_11 -> V_4 ) ;
F_53 ( V_1 ) ;
F_91 ( V_1 ) ;
F_96 ( V_1 , V_231 ) ;
F_88 ( V_1 ) ;
if ( ! F_4 ( V_1 ) )
F_103 ( V_1 ) ;
}
static void F_104 ( struct V_143 * V_11 )
{
struct V_1 * V_1 = F_7 ( & V_11 -> V_4 ) ;
struct V_6 * V_7 = V_11 -> V_4 . V_7 ;
if ( F_4 ( V_1 ) ) {
F_103 ( V_1 ) ;
if ( ! F_20 ( V_7 ) )
F_95 ( V_1 ) ;
}
}
static void F_105 ( struct V_143 * V_11 )
{
struct V_1 * V_1 = F_7 ( & V_11 -> V_4 ) ;
struct V_6 * V_7 = V_11 -> V_4 . V_7 ;
struct V_44 * V_45 = V_7 -> V_46 ;
T_1 V_245 = F_21 ( V_1 -> V_184 ) ;
if ( F_78 ( V_245 & V_230 ) )
return;
F_53 ( V_1 ) ;
F_96 ( V_1 , V_231 ) ;
F_106 ( V_1 ) ;
F_86 ( V_1 ) ;
F_55 ( V_1 , true ) ;
F_107 ( V_1 ) ;
F_108 ( V_1 ) ;
F_89 ( V_1 ) ;
}
static void F_109 ( struct V_143 * V_11 )
{
struct V_1 * V_1 = F_7 ( & V_11 -> V_4 ) ;
struct V_6 * V_7 = V_11 -> V_4 . V_7 ;
if ( F_4 ( V_1 ) && ! F_20 ( V_7 ) )
F_93 ( V_1 ) ;
}
static bool
F_110 ( struct V_1 * V_1 , T_4 V_101 ,
T_2 * V_74 , int V_78 )
{
int V_77 , V_40 ;
for ( V_40 = 0 ; V_40 < 3 ; V_40 ++ ) {
V_77 = F_49 ( V_1 , V_101 , V_74 ,
V_78 ) ;
if ( V_77 == V_78 )
return true ;
F_44 ( 1 ) ;
}
return false ;
}
static bool
F_111 ( struct V_1 * V_1 , T_2 V_246 [ V_247 ] )
{
return F_110 ( V_1 ,
V_248 ,
V_246 ,
V_247 ) ;
}
static T_2
F_112 ( struct V_1 * V_1 )
{
struct V_6 * V_7 = F_5 ( V_1 ) ;
if ( F_39 ( V_7 ) && F_4 ( V_1 ) )
return V_249 ;
else if ( F_70 ( V_7 ) && ! F_4 ( V_1 ) )
return V_250 ;
else
return V_249 ;
}
static T_2
F_113 ( struct V_1 * V_1 , T_2 V_251 )
{
struct V_6 * V_7 = F_5 ( V_1 ) ;
if ( F_36 ( V_7 ) ) {
switch ( V_251 & V_252 ) {
case V_253 :
return V_254 ;
case V_255 :
return V_256 ;
case V_249 :
return V_257 ;
case V_250 :
default:
return V_258 ;
}
} else if ( F_39 ( V_7 ) && F_4 ( V_1 ) && ! F_20 ( V_7 ) ) {
switch ( V_251 & V_252 ) {
case V_253 :
return V_256 ;
case V_255 :
case V_249 :
return V_257 ;
default:
return V_258 ;
}
} else {
switch ( V_251 & V_252 ) {
case V_253 :
return V_256 ;
case V_255 :
return V_256 ;
case V_249 :
return V_257 ;
case V_250 :
default:
return V_258 ;
}
}
}
static void
F_114 ( struct V_1 * V_1 , T_2 V_246 [ V_247 ] )
{
T_2 V_41 = 0 ;
T_2 V_259 = 0 ;
int V_260 ;
T_2 V_261 ;
T_2 V_262 ;
for ( V_260 = 0 ; V_260 < V_1 -> V_149 ; V_260 ++ ) {
T_2 V_263 = F_115 ( V_246 , V_260 ) ;
T_2 V_264 = F_116 ( V_246 , V_260 ) ;
if ( V_263 > V_41 )
V_41 = V_263 ;
if ( V_264 > V_259 )
V_259 = V_264 ;
}
V_261 = F_112 ( V_1 ) ;
if ( V_41 >= V_261 )
V_41 = V_261 | V_265 ;
V_262 = F_113 ( V_1 , V_41 ) ;
if ( V_259 >= V_262 )
V_259 = V_262 | V_266 ;
for ( V_260 = 0 ; V_260 < 4 ; V_260 ++ )
V_1 -> V_267 [ V_260 ] = V_41 | V_259 ;
}
static T_1
F_117 ( T_2 V_267 )
{
T_1 V_268 = 0 ;
switch ( V_267 & V_252 ) {
case V_253 :
default:
V_268 |= V_186 ;
break;
case V_255 :
V_268 |= V_269 ;
break;
case V_249 :
V_268 |= V_270 ;
break;
case V_250 :
V_268 |= V_271 ;
break;
}
switch ( V_267 & V_272 ) {
case V_258 :
default:
V_268 |= V_187 ;
break;
case V_257 :
V_268 |= V_273 ;
break;
case V_256 :
V_268 |= V_274 ;
break;
case V_254 :
V_268 |= V_275 ;
break;
}
return V_268 ;
}
static T_1
F_118 ( T_2 V_267 )
{
int V_268 = V_267 & ( V_252 |
V_272 ) ;
switch ( V_268 ) {
case V_253 | V_258 :
case V_255 | V_258 :
return V_276 ;
case V_253 | V_257 :
return V_277 ;
case V_253 | V_256 :
case V_255 | V_256 :
return V_278 ;
case V_255 | V_257 :
case V_249 | V_257 :
return V_279 ;
case V_249 | V_258 :
case V_250 | V_258 :
return V_280 ;
default:
F_26 ( L_45
L_46 , V_268 ) ;
return V_276 ;
}
}
static T_1
F_119 ( T_2 V_267 )
{
int V_268 = V_267 & ( V_252 |
V_272 ) ;
switch ( V_268 ) {
case V_253 | V_258 :
return V_281 ;
case V_253 | V_257 :
return V_282 ;
case V_253 | V_256 :
return V_283 ;
case V_255 | V_258 :
return V_284 ;
case V_255 | V_257 :
return V_285 ;
case V_249 | V_258 :
return V_286 ;
case V_249 | V_257 :
return V_287 ;
default:
F_26 ( L_45
L_46 , V_268 ) ;
return V_288 ;
}
}
static T_1
F_120 ( T_2 V_267 )
{
int V_268 = V_267 & ( V_252 |
V_272 ) ;
switch ( V_268 ) {
case V_253 | V_258 :
return V_289 ;
case V_253 | V_257 :
return V_290 ;
case V_253 | V_256 :
return V_291 ;
case V_253 | V_254 :
return V_292 ;
case V_255 | V_258 :
return V_293 ;
case V_255 | V_257 :
return V_294 ;
case V_255 | V_256 :
return V_295 ;
case V_249 | V_258 :
return V_296 ;
case V_249 | V_257 :
return V_297 ;
default:
F_26 ( L_45
L_46 , V_268 ) ;
return V_289 ;
}
}
static void
F_121 ( struct V_1 * V_1 , T_1 * V_183 )
{
struct V_2 * V_3 = F_2 ( V_1 ) ;
struct V_6 * V_7 = V_3 -> V_4 . V_4 . V_7 ;
T_1 V_268 , V_202 ;
T_2 V_267 = V_1 -> V_267 [ 0 ] ;
if ( F_36 ( V_7 ) ) {
V_268 = F_120 ( V_267 ) ;
V_202 = V_298 ;
} else if ( F_39 ( V_7 ) && F_4 ( V_1 ) && ! F_20 ( V_7 ) ) {
V_268 = F_119 ( V_267 ) ;
V_202 = V_299 ;
} else if ( F_38 ( V_7 ) && F_4 ( V_1 ) ) {
V_268 = F_118 ( V_267 ) ;
V_202 = V_300 ;
} else {
V_268 = F_117 ( V_267 ) ;
V_202 = V_301 | V_302 ;
}
F_26 ( L_47 , V_268 ) ;
* V_183 = ( * V_183 & ~ V_202 ) | V_268 ;
}
static bool
F_122 ( struct V_1 * V_1 ,
T_1 V_303 ,
T_2 V_304 )
{
struct V_2 * V_3 = F_2 ( V_1 ) ;
struct V_6 * V_7 = V_3 -> V_4 . V_4 . V_7 ;
struct V_44 * V_45 = V_7 -> V_46 ;
enum V_305 V_305 = V_3 -> V_305 ;
int V_77 ;
if ( F_36 ( V_7 ) ) {
T_1 V_306 = F_21 ( F_123 ( V_305 ) ) ;
if ( V_304 & V_307 )
V_306 |= V_308 ;
else
V_306 &= ~ V_308 ;
V_306 &= ~ V_309 ;
switch ( V_304 & V_310 ) {
case V_311 :
V_306 |= V_312 ;
break;
case V_313 :
V_306 |= V_314 ;
break;
case V_315 :
V_306 |= V_316 ;
break;
case V_317 :
V_306 |= V_318 ;
break;
}
F_45 ( F_123 ( V_305 ) , V_306 ) ;
} else if ( F_70 ( V_7 ) &&
( F_39 ( V_7 ) || ! F_4 ( V_1 ) ) ) {
V_303 &= ~ V_319 ;
switch ( V_304 & V_310 ) {
case V_311 :
V_303 |= V_198 ;
break;
case V_313 :
V_303 |= V_320 ;
break;
case V_315 :
V_303 |= V_321 ;
break;
case V_317 :
F_32 ( L_48 ) ;
V_303 |= V_321 ;
break;
}
} else {
V_303 &= ~ V_322 ;
switch ( V_304 & V_310 ) {
case V_311 :
V_303 |= V_200 ;
break;
case V_313 :
V_303 |= V_323 ;
break;
case V_315 :
V_303 |= V_324 ;
break;
case V_317 :
F_32 ( L_48 ) ;
V_303 |= V_324 ;
break;
}
}
F_45 ( V_1 -> V_184 , V_303 ) ;
F_64 ( V_1 -> V_184 ) ;
F_48 ( V_1 ,
V_325 ,
V_304 ) ;
if ( ( V_304 & V_310 ) !=
V_311 ) {
V_77 = F_46 ( V_1 ,
V_326 ,
V_1 -> V_267 ,
V_1 -> V_149 ) ;
if ( V_77 != V_1 -> V_149 )
return false ;
}
return true ;
}
static void F_124 ( struct V_1 * V_1 )
{
struct V_2 * V_3 = F_2 ( V_1 ) ;
struct V_6 * V_7 = V_3 -> V_4 . V_4 . V_7 ;
struct V_44 * V_45 = V_7 -> V_46 ;
enum V_305 V_305 = V_3 -> V_305 ;
T_1 V_327 ;
if ( ! F_36 ( V_7 ) )
return;
V_327 = F_21 ( F_123 ( V_305 ) ) ;
V_327 &= ~ V_309 ;
V_327 |= V_328 ;
F_45 ( F_123 ( V_305 ) , V_327 ) ;
if ( V_305 == V_329 )
return;
if ( F_125 ( ( F_21 ( F_126 ( V_305 ) ) & V_330 ) ,
1 ) )
F_32 ( L_49 ) ;
}
void
F_106 ( struct V_1 * V_1 )
{
struct V_10 * V_11 = & F_2 ( V_1 ) -> V_4 . V_4 ;
struct V_6 * V_7 = V_11 -> V_7 ;
int V_40 ;
T_2 V_331 ;
bool V_332 = false ;
int V_333 , V_334 ;
T_1 V_183 = V_1 -> V_183 ;
if ( F_36 ( V_7 ) )
F_127 ( V_11 ) ;
F_46 ( V_1 , V_335 ,
V_1 -> V_168 ,
V_169 ) ;
V_183 |= V_230 ;
memset ( V_1 -> V_267 , 0 , 4 ) ;
V_331 = 0xff ;
V_333 = 0 ;
V_334 = 0 ;
V_332 = false ;
for (; ; ) {
T_2 V_246 [ V_247 ] ;
F_121 ( V_1 , & V_183 ) ;
if ( ! F_122 ( V_1 , V_183 ,
V_313 |
V_307 ) )
break;
F_128 ( V_1 -> V_13 ) ;
if ( ! F_111 ( V_1 , V_246 ) ) {
F_32 ( L_50 ) ;
break;
}
if ( F_129 ( V_246 , V_1 -> V_149 ) ) {
F_26 ( L_51 ) ;
V_332 = true ;
break;
}
for ( V_40 = 0 ; V_40 < V_1 -> V_149 ; V_40 ++ )
if ( ( V_1 -> V_267 [ V_40 ] & V_265 ) == 0 )
break;
if ( V_40 == V_1 -> V_149 ) {
++ V_334 ;
if ( V_334 == 5 ) {
F_26 ( L_52 ) ;
break;
}
memset ( V_1 -> V_267 , 0 , 4 ) ;
V_333 = 0 ;
continue;
}
if ( ( V_1 -> V_267 [ 0 ] & V_252 ) == V_331 ) {
++ V_333 ;
if ( V_333 == 5 ) {
F_26 ( L_53 ) ;
break;
}
} else
V_333 = 0 ;
V_331 = V_1 -> V_267 [ 0 ] & V_252 ;
F_114 ( V_1 , V_246 ) ;
}
V_1 -> V_183 = V_183 ;
}
void
F_107 ( struct V_1 * V_1 )
{
bool V_336 = false ;
int V_337 , V_338 ;
T_1 V_183 = V_1 -> V_183 ;
V_337 = 0 ;
V_338 = 0 ;
V_336 = false ;
for (; ; ) {
T_2 V_246 [ V_247 ] ;
if ( V_338 > 5 ) {
F_32 ( L_54 ) ;
F_103 ( V_1 ) ;
break;
}
F_121 ( V_1 , & V_183 ) ;
if ( ! F_122 ( V_1 , V_183 ,
V_315 |
V_307 ) )
break;
F_130 ( V_1 -> V_13 ) ;
if ( ! F_111 ( V_1 , V_246 ) )
break;
if ( ! F_129 ( V_246 , V_1 -> V_149 ) ) {
F_106 ( V_1 ) ;
V_338 ++ ;
continue;
}
if ( F_131 ( V_246 , V_1 -> V_149 ) ) {
V_336 = true ;
break;
}
if ( V_337 > 5 ) {
F_103 ( V_1 ) ;
F_106 ( V_1 ) ;
V_337 = 0 ;
V_338 ++ ;
continue;
}
F_114 ( V_1 , V_246 ) ;
++ V_337 ;
}
F_124 ( V_1 ) ;
V_1 -> V_183 = V_183 ;
if ( V_336 )
F_26 ( L_55 ) ;
}
void F_108 ( struct V_1 * V_1 )
{
F_122 ( V_1 , V_1 -> V_183 ,
V_311 ) ;
}
static void
F_103 ( struct V_1 * V_1 )
{
struct V_2 * V_3 = F_2 ( V_1 ) ;
struct V_6 * V_7 = V_3 -> V_4 . V_4 . V_7 ;
struct V_44 * V_45 = V_7 -> V_46 ;
struct V_182 * V_182 =
F_66 ( V_3 -> V_4 . V_4 . V_176 ) ;
T_1 V_183 = V_1 -> V_183 ;
if ( F_36 ( V_7 ) )
return;
if ( F_78 ( ( F_21 ( V_1 -> V_184 ) & V_230 ) == 0 ) )
return;
F_26 ( L_39 ) ;
if ( F_70 ( V_7 ) && ( F_39 ( V_7 ) || ! F_4 ( V_1 ) ) ) {
V_183 &= ~ V_319 ;
F_45 ( V_1 -> V_184 , V_183 | V_339 ) ;
} else {
V_183 &= ~ V_322 ;
F_45 ( V_1 -> V_184 , V_183 | V_340 ) ;
}
F_64 ( V_1 -> V_184 ) ;
F_132 ( V_7 , V_182 -> V_192 ) ;
if ( F_133 ( V_7 ) &&
F_21 ( V_1 -> V_184 ) & V_201 ) {
struct V_175 * V_176 = V_3 -> V_4 . V_4 . V_176 ;
V_183 &= ~ V_201 ;
F_45 ( V_1 -> V_184 , V_183 ) ;
if ( F_78 ( V_176 == NULL ) ) {
F_64 ( V_1 -> V_184 ) ;
F_44 ( 50 ) ;
} else
F_132 ( V_7 , V_182 -> V_192 ) ;
}
V_183 &= ~ V_193 ;
F_45 ( V_1 -> V_184 , V_183 & ~ V_230 ) ;
F_64 ( V_1 -> V_184 ) ;
F_44 ( V_1 -> V_218 ) ;
}
static bool
F_134 ( struct V_1 * V_1 )
{
char V_341 [ sizeof( V_1 -> V_13 ) * 3 ] ;
if ( F_110 ( V_1 , 0x000 , V_1 -> V_13 ,
sizeof( V_1 -> V_13 ) ) == 0 )
return false ;
F_135 ( V_1 -> V_13 , sizeof( V_1 -> V_13 ) ,
32 , 1 , V_341 , sizeof( V_341 ) , false ) ;
F_26 ( L_56 , V_341 ) ;
if ( V_1 -> V_13 [ V_171 ] == 0 )
return false ;
if ( ! ( V_1 -> V_13 [ V_342 ] &
V_343 ) )
return true ;
if ( V_1 -> V_13 [ V_171 ] == 0x10 )
return true ;
if ( F_110 ( V_1 , V_344 ,
V_1 -> V_345 ,
V_346 ) == 0 )
return false ;
return true ;
}
static void
F_136 ( struct V_1 * V_1 )
{
T_5 V_347 [ 3 ] ;
if ( ! ( V_1 -> V_13 [ V_348 ] & V_349 ) )
return;
F_53 ( V_1 ) ;
if ( F_110 ( V_1 , V_350 , V_347 , 3 ) )
F_26 ( L_57 ,
V_347 [ 0 ] , V_347 [ 1 ] , V_347 [ 2 ] ) ;
if ( F_110 ( V_1 , V_351 , V_347 , 3 ) )
F_26 ( L_58 ,
V_347 [ 0 ] , V_347 [ 1 ] , V_347 [ 2 ] ) ;
F_55 ( V_1 , false ) ;
}
static bool
F_137 ( struct V_1 * V_1 , T_5 * V_352 )
{
int V_77 ;
V_77 = F_110 ( V_1 ,
V_353 ,
V_352 , 1 ) ;
if ( ! V_77 )
return false ;
return true ;
}
static void
F_138 ( struct V_1 * V_1 )
{
F_48 ( V_1 , V_354 , V_355 ) ;
}
void
F_139 ( struct V_1 * V_1 )
{
struct V_143 * V_143 = & F_2 ( V_1 ) -> V_4 ;
T_5 V_352 ;
T_5 V_246 [ V_247 ] ;
if ( ! V_143 -> V_356 )
return;
if ( F_78 ( ! V_143 -> V_4 . V_176 ) )
return;
if ( ! F_111 ( V_1 , V_246 ) ) {
F_103 ( V_1 ) ;
return;
}
if ( ! F_134 ( V_1 ) ) {
F_103 ( V_1 ) ;
return;
}
if ( V_1 -> V_13 [ V_171 ] >= 0x11 &&
F_137 ( V_1 , & V_352 ) ) {
F_48 ( V_1 ,
V_353 ,
V_352 ) ;
if ( V_352 & V_357 )
F_138 ( V_1 ) ;
if ( V_352 & ( V_358 | V_359 ) )
F_67 ( L_59 ) ;
}
if ( ! F_131 ( V_246 , V_1 -> V_149 ) ) {
F_26 ( L_60 ,
F_140 ( & V_143 -> V_4 ) ) ;
F_106 ( V_1 ) ;
F_107 ( V_1 ) ;
F_108 ( V_1 ) ;
}
}
static enum V_360
F_141 ( struct V_1 * V_1 )
{
T_2 * V_13 = V_1 -> V_13 ;
bool V_361 ;
T_2 type ;
if ( ! F_134 ( V_1 ) )
return V_362 ;
if ( ! ( V_13 [ V_342 ] & V_343 ) )
return V_363 ;
V_361 = ! ! ( V_1 -> V_345 [ 0 ] & V_364 ) ;
if ( V_361 ) {
T_2 V_365 ;
if ( ! F_110 ( V_1 , V_366 ,
& V_365 , 1 ) )
return V_367 ;
return F_142 ( V_365 ) ? V_363
: V_362 ;
}
if ( F_143 ( & V_1 -> V_115 ) )
return V_363 ;
type = V_1 -> V_345 [ 0 ] & V_368 ;
if ( type == V_369 || type == V_370 )
return V_367 ;
F_26 ( L_61 ) ;
return V_362 ;
}
static enum V_360
F_144 ( struct V_1 * V_1 )
{
struct V_6 * V_7 = F_5 ( V_1 ) ;
struct V_44 * V_45 = V_7 -> V_46 ;
struct V_2 * V_3 = F_2 ( V_1 ) ;
enum V_360 V_69 ;
if ( F_1 ( V_1 ) ) {
V_69 = F_145 ( V_7 ) ;
if ( V_69 == V_367 )
V_69 = V_363 ;
return V_69 ;
}
if ( ! F_146 ( V_45 , V_3 ) )
return V_362 ;
return F_141 ( V_1 ) ;
}
static enum V_360
F_147 ( struct V_1 * V_1 )
{
struct V_6 * V_7 = F_5 ( V_1 ) ;
struct V_44 * V_45 = V_7 -> V_46 ;
struct V_2 * V_3 = F_2 ( V_1 ) ;
T_1 V_371 ;
if ( F_1 ( V_1 ) ) {
enum V_360 V_69 ;
V_69 = F_145 ( V_7 ) ;
if ( V_69 == V_367 )
V_69 = V_363 ;
return V_69 ;
}
switch ( V_3 -> V_305 ) {
case V_372 :
V_371 = V_373 ;
break;
case V_374 :
V_371 = V_375 ;
break;
case V_376 :
V_371 = V_377 ;
break;
default:
return V_367 ;
}
if ( ( F_21 ( V_378 ) & V_371 ) == 0 )
return V_362 ;
return F_141 ( V_1 ) ;
}
static struct V_379 *
F_148 ( struct V_8 * V_9 , struct V_114 * V_115 )
{
struct V_23 * V_23 = F_14 ( V_9 ) ;
if ( V_23 -> V_379 ) {
struct V_379 * V_379 ;
int V_380 ;
if ( F_149 ( V_23 -> V_379 ) )
return NULL ;
V_380 = ( V_23 -> V_379 -> V_381 + 1 ) * V_382 ;
V_379 = F_150 ( V_380 , V_383 ) ;
if ( ! V_379 )
return NULL ;
memcpy ( V_379 , V_23 -> V_379 , V_380 ) ;
return V_379 ;
}
return F_151 ( V_9 , V_115 ) ;
}
static int
F_152 ( struct V_8 * V_9 , struct V_114 * V_115 )
{
struct V_23 * V_23 = F_14 ( V_9 ) ;
if ( V_23 -> V_379 ) {
if ( F_149 ( V_23 -> V_379 ) )
return 0 ;
return F_153 ( V_9 ,
V_23 -> V_379 ) ;
}
return F_154 ( V_9 , V_115 ) ;
}
static enum V_360
F_155 ( struct V_8 * V_9 , bool V_384 )
{
struct V_1 * V_1 = F_6 ( V_9 ) ;
struct V_2 * V_3 = F_2 ( V_1 ) ;
struct V_143 * V_143 = & V_3 -> V_4 ;
struct V_6 * V_7 = V_9 -> V_7 ;
enum V_360 V_69 ;
struct V_379 * V_379 = NULL ;
V_1 -> V_191 = false ;
if ( F_40 ( V_7 ) )
V_69 = F_144 ( V_1 ) ;
else
V_69 = F_147 ( V_1 ) ;
if ( V_69 != V_363 )
return V_69 ;
F_136 ( V_1 ) ;
if ( V_1 -> V_385 != V_386 ) {
V_1 -> V_191 = ( V_1 -> V_385 == V_387 ) ;
} else {
V_379 = F_148 ( V_9 , & V_1 -> V_115 ) ;
if ( V_379 ) {
V_1 -> V_191 = F_156 ( V_379 ) ;
F_157 ( V_379 ) ;
}
}
if ( V_143 -> type != V_5 )
V_143 -> type = V_388 ;
return V_363 ;
}
static int F_158 ( struct V_8 * V_9 )
{
struct V_1 * V_1 = F_6 ( V_9 ) ;
struct V_23 * V_23 = F_14 ( V_9 ) ;
struct V_6 * V_7 = V_9 -> V_7 ;
int V_77 ;
V_77 = F_152 ( V_9 , & V_1 -> V_115 ) ;
if ( V_77 )
return V_77 ;
if ( F_1 ( V_1 ) && V_23 -> V_25 . V_24 ) {
struct V_21 * V_22 ;
V_22 = F_159 ( V_7 ,
V_23 -> V_25 . V_24 ) ;
if ( V_22 ) {
F_160 ( V_9 , V_22 ) ;
return 1 ;
}
}
return 0 ;
}
static bool
F_161 ( struct V_8 * V_9 )
{
struct V_1 * V_1 = F_6 ( V_9 ) ;
struct V_379 * V_379 ;
bool V_191 = false ;
V_379 = F_148 ( V_9 , & V_1 -> V_115 ) ;
if ( V_379 ) {
V_191 = F_156 ( V_379 ) ;
F_157 ( V_379 ) ;
}
return V_191 ;
}
static int
F_162 ( struct V_8 * V_9 ,
struct V_389 * V_390 ,
T_6 V_327 )
{
struct V_44 * V_45 = V_9 -> V_7 -> V_46 ;
struct V_23 * V_23 = F_14 ( V_9 ) ;
struct V_143 * V_143 = F_8 ( V_9 ) ;
struct V_1 * V_1 = F_7 ( & V_143 -> V_4 ) ;
int V_77 ;
V_77 = F_163 ( & V_9 -> V_4 , V_390 , V_327 ) ;
if ( V_77 )
return V_77 ;
if ( V_390 == V_45 -> V_391 ) {
int V_40 = V_327 ;
bool V_191 ;
if ( V_40 == V_1 -> V_385 )
return 0 ;
V_1 -> V_385 = V_40 ;
if ( V_40 == V_386 )
V_191 = F_161 ( V_9 ) ;
else
V_191 = ( V_40 == V_387 ) ;
if ( V_191 == V_1 -> V_191 )
return 0 ;
V_1 -> V_191 = V_191 ;
goto V_70;
}
if ( V_390 == V_45 -> V_392 ) {
bool V_393 = V_1 -> V_161 ;
T_1 V_394 = V_1 -> V_162 ;
switch ( V_327 ) {
case V_395 :
V_1 -> V_161 = true ;
break;
case V_396 :
V_1 -> V_161 = false ;
V_1 -> V_162 = 0 ;
break;
case V_397 :
V_1 -> V_161 = false ;
V_1 -> V_162 = V_163 ;
break;
default:
return - V_398 ;
}
if ( V_393 == V_1 -> V_161 &&
V_394 == V_1 -> V_162 )
return 0 ;
goto V_70;
}
if ( F_1 ( V_1 ) &&
V_390 == V_9 -> V_7 -> V_216 . V_399 ) {
if ( V_327 == V_400 ) {
F_26 ( L_62 ) ;
return - V_398 ;
}
if ( V_23 -> V_25 . V_157 == V_327 ) {
return 0 ;
}
V_23 -> V_25 . V_157 = V_327 ;
goto V_70;
}
return - V_398 ;
V_70:
if ( V_143 -> V_4 . V_176 )
F_164 ( V_143 -> V_4 . V_176 ) ;
return 0 ;
}
static void
F_165 ( struct V_8 * V_9 )
{
struct V_1 * V_1 = F_6 ( V_9 ) ;
struct V_23 * V_23 = F_14 ( V_9 ) ;
if ( ! F_166 ( V_23 -> V_379 ) )
F_157 ( V_23 -> V_379 ) ;
if ( F_1 ( V_1 ) )
F_167 ( & V_23 -> V_25 ) ;
F_168 ( V_9 ) ;
F_169 ( V_9 ) ;
F_157 ( V_9 ) ;
}
void F_170 ( struct V_10 * V_11 )
{
struct V_2 * V_3 = F_171 ( V_11 ) ;
struct V_1 * V_1 = & V_3 -> V_401 ;
struct V_6 * V_7 = F_5 ( V_1 ) ;
F_172 ( & V_1 -> V_115 ) ;
F_173 ( V_11 ) ;
if ( F_1 ( V_1 ) ) {
F_174 ( & V_1 -> V_221 ) ;
F_82 ( & V_7 -> V_216 . V_217 ) ;
F_77 ( V_1 ) ;
F_83 ( & V_7 -> V_216 . V_217 ) ;
}
F_157 ( V_3 ) ;
}
static void
F_175 ( struct V_143 * V_143 )
{
struct V_1 * V_1 = F_7 ( & V_143 -> V_4 ) ;
F_139 ( V_1 ) ;
}
int
F_176 ( struct V_175 * V_176 )
{
struct V_6 * V_7 = V_176 -> V_7 ;
struct V_143 * V_143 ;
struct V_1 * V_1 ;
F_177 (dev, crtc, intel_encoder) {
V_1 = F_7 ( & V_143 -> V_4 ) ;
if ( V_143 -> type == V_388 ||
V_143 -> type == V_5 )
return V_1 -> V_184 ;
}
return - 1 ;
}
bool F_178 ( struct V_6 * V_7 )
{
struct V_44 * V_45 = V_7 -> V_46 ;
struct V_402 * V_403 ;
int V_40 ;
if ( ! V_45 -> V_404 )
return false ;
for ( V_40 = 0 ; V_40 < V_45 -> V_404 ; V_40 ++ ) {
V_403 = V_45 -> V_405 + V_40 ;
if ( V_403 -> V_406 == V_407 &&
V_403 -> V_408 == V_409 )
return true ;
}
return false ;
}
static void
F_179 ( struct V_1 * V_1 , struct V_8 * V_9 )
{
struct V_23 * V_23 = F_14 ( V_9 ) ;
F_180 ( V_9 ) ;
F_181 ( V_9 ) ;
V_1 -> V_161 = true ;
if ( F_1 ( V_1 ) ) {
F_182 ( V_9 -> V_7 ) ;
F_183 (
& V_9 -> V_4 ,
V_9 -> V_7 -> V_216 . V_399 ,
V_410 ) ;
V_23 -> V_25 . V_157 = V_410 ;
}
}
static void
F_184 ( struct V_6 * V_7 ,
struct V_1 * V_1 ,
struct V_411 * V_88 )
{
struct V_44 * V_45 = V_7 -> V_46 ;
struct V_411 V_412 , V_413 , V_414 , V_415 ;
T_3 V_416 , V_417 , V_418 , V_213 ;
int V_419 , V_420 , V_421 , V_422 ;
if ( F_40 ( V_7 ) ) {
V_419 = V_64 ;
V_420 = V_423 ;
V_421 = V_424 ;
V_422 = V_425 ;
} else {
V_419 = V_63 ;
V_420 = V_426 ;
V_421 = V_427 ;
V_422 = V_428 ;
}
V_213 = F_76 ( V_1 ) ;
F_45 ( V_419 , V_213 ) ;
V_416 = F_21 ( V_420 ) ;
V_417 = F_21 ( V_421 ) ;
V_418 = F_21 ( V_422 ) ;
V_412 . V_429 = ( V_416 & V_430 ) >>
V_431 ;
V_412 . V_432 = ( V_416 & V_433 ) >>
V_434 ;
V_412 . V_435 = ( V_417 & V_436 ) >>
V_437 ;
V_412 . V_438 = ( V_417 & V_439 ) >>
V_440 ;
V_412 . V_441 = ( ( V_418 & V_442 ) >>
V_443 ) * 1000 ;
F_26 ( L_63 ,
V_412 . V_429 , V_412 . V_432 , V_412 . V_435 , V_412 . V_438 , V_412 . V_441 ) ;
V_413 = V_45 -> V_159 . V_444 ;
V_414 . V_429 = 210 * 10 ;
V_414 . V_432 = 50 * 10 ;
V_414 . V_435 = 50 * 10 ;
V_414 . V_438 = 500 * 10 ;
V_414 . V_441 = ( 510 + 100 ) * 10 ;
F_26 ( L_64 ,
V_413 . V_429 , V_413 . V_432 , V_413 . V_435 , V_413 . V_438 , V_413 . V_441 ) ;
#define F_185 ( T_7 ) final.field = (max(cur.field, vbt.field) == 0 ? \
spec.field : \
max(cur.field, vbt.field))
F_185 ( V_429 ) ;
F_185 ( V_432 ) ;
F_185 ( V_435 ) ;
F_185 ( V_438 ) ;
F_185 ( V_441 ) ;
#undef F_185
#define F_186 ( T_7 ) (DIV_ROUND_UP(final.field, 10))
V_1 -> V_215 = F_186 ( V_429 ) ;
V_1 -> V_227 = F_186 ( V_432 ) ;
V_1 -> V_228 = F_186 ( V_435 ) ;
V_1 -> V_218 = F_186 ( V_438 ) ;
V_1 -> V_223 = F_186 ( V_441 ) ;
#undef F_186
F_26 ( L_65 ,
V_1 -> V_215 , V_1 -> V_218 ,
V_1 -> V_223 ) ;
F_26 ( L_66 ,
V_1 -> V_227 , V_1 -> V_228 ) ;
if ( V_88 )
* V_88 = V_415 ;
}
static void
F_187 ( struct V_6 * V_7 ,
struct V_1 * V_1 ,
struct V_411 * V_445 )
{
struct V_44 * V_45 = V_7 -> V_46 ;
T_3 V_416 , V_417 , V_418 , V_446 = 0 ;
int div = F_40 ( V_7 ) ? F_42 ( V_7 ) : F_19 ( V_7 ) ;
int V_420 , V_421 , V_422 ;
if ( F_40 ( V_7 ) ) {
V_420 = V_423 ;
V_421 = V_424 ;
V_422 = V_425 ;
} else {
V_420 = V_426 ;
V_421 = V_427 ;
V_422 = V_428 ;
}
if ( F_20 ( V_7 ) )
V_446 = F_21 ( V_420 ) & 0xc0000000 ;
V_416 = ( V_445 -> V_429 << V_431 ) |
( V_445 -> V_432 << V_434 ) ;
V_417 = ( V_445 -> V_435 << V_437 ) |
( V_445 -> V_438 << V_440 ) ;
V_418 = ( ( 100 * div ) / 2 - 1 ) << V_447 ;
V_418 |= ( F_41 ( V_445 -> V_441 , 1000 )
<< V_443 ) ;
if ( F_133 ( V_7 ) || F_70 ( V_7 ) ) {
if ( F_4 ( V_1 ) )
V_446 = V_448 ;
else
V_446 = V_449 ;
}
V_416 |= V_446 ;
F_45 ( V_420 , V_416 ) ;
F_45 ( V_421 , V_417 ) ;
F_45 ( V_422 , V_418 ) ;
F_26 ( L_67 ,
F_21 ( V_420 ) ,
F_21 ( V_421 ) ,
F_21 ( V_422 ) ) ;
}
void
F_188 ( struct V_2 * V_3 ,
struct V_23 * V_23 )
{
struct V_8 * V_9 = & V_23 -> V_4 ;
struct V_1 * V_1 = & V_3 -> V_401 ;
struct V_143 * V_143 = & V_3 -> V_4 ;
struct V_6 * V_7 = V_143 -> V_4 . V_7 ;
struct V_44 * V_45 = V_7 -> V_46 ;
struct V_21 * V_24 = NULL ;
struct V_411 V_450 = { 0 } ;
enum V_305 V_305 = V_3 -> V_305 ;
const char * V_133 = NULL ;
int type ;
V_1 -> V_183 = F_21 ( V_1 -> V_184 ) ;
V_1 -> V_148 = V_23 ;
if ( F_40 ( V_7 ) && V_305 == V_376 )
if ( F_178 ( V_7 ) )
V_1 -> F_3 = true ;
if ( F_20 ( V_7 ) && V_305 == V_374 ) {
type = V_451 ;
V_143 -> type = V_5 ;
} else if ( V_305 == V_329 || F_3 ( V_1 ) ) {
type = V_451 ;
V_143 -> type = V_5 ;
} else {
type = V_452 ;
}
F_189 ( V_7 , V_9 , & V_453 , type ) ;
F_190 ( V_9 , & V_454 ) ;
V_9 -> V_455 = true ;
V_9 -> V_456 = 0 ;
F_191 ( & V_1 -> V_221 ,
F_80 ) ;
F_192 ( V_23 , V_143 ) ;
F_193 ( V_9 ) ;
if ( F_36 ( V_7 ) )
V_23 -> V_457 = V_458 ;
else
V_23 -> V_457 = V_459 ;
V_1 -> V_68 = V_1 -> V_184 + 0x10 ;
if ( F_36 ( V_7 ) ) {
switch ( V_3 -> V_305 ) {
case V_329 :
V_1 -> V_68 = V_460 ;
break;
case V_372 :
V_1 -> V_68 = V_461 ;
break;
case V_374 :
V_1 -> V_68 = V_462 ;
break;
case V_376 :
V_1 -> V_68 = V_463 ;
break;
default:
F_194 () ;
}
}
switch ( V_305 ) {
case V_329 :
V_143 -> V_464 = V_465 ;
V_133 = L_68 ;
break;
case V_372 :
V_143 -> V_464 = V_466 ;
V_133 = L_69 ;
break;
case V_374 :
V_143 -> V_464 = V_467 ;
V_133 = L_70 ;
break;
case V_376 :
V_143 -> V_464 = V_468 ;
V_133 = L_71 ;
break;
default:
F_194 () ;
}
if ( F_1 ( V_1 ) )
F_184 ( V_7 , V_1 , & V_450 ) ;
F_52 ( V_1 , V_23 , V_133 ) ;
if ( F_1 ( V_1 ) ) {
bool V_77 ;
struct V_21 * V_469 ;
struct V_379 * V_379 ;
F_53 ( V_1 ) ;
V_77 = F_134 ( V_1 ) ;
F_55 ( V_1 , false ) ;
if ( V_77 ) {
if ( V_1 -> V_13 [ V_171 ] >= 0x11 )
V_45 -> V_470 =
V_1 -> V_13 [ V_471 ] &
V_472 ;
} else {
F_195 ( L_72 ) ;
F_170 ( & V_143 -> V_4 ) ;
F_165 ( V_9 ) ;
return;
}
F_187 ( V_7 , V_1 ,
& V_450 ) ;
F_53 ( V_1 ) ;
V_379 = F_151 ( V_9 , & V_1 -> V_115 ) ;
if ( V_379 ) {
if ( F_196 ( V_9 , V_379 ) ) {
F_197 ( V_9 , V_379 ) ;
F_198 ( V_9 , V_379 ) ;
} else {
F_157 ( V_379 ) ;
V_379 = F_199 ( - V_398 ) ;
}
} else {
V_379 = F_199 ( - V_473 ) ;
}
V_23 -> V_379 = V_379 ;
F_200 (scan, &connector->probed_modes, head) {
if ( ( V_469 -> type & V_474 ) ) {
V_24 = F_159 ( V_7 , V_469 ) ;
break;
}
}
if ( ! V_24 && V_45 -> V_475 ) {
V_24 = F_159 ( V_7 , V_45 -> V_475 ) ;
if ( V_24 )
V_24 -> type |= V_474 ;
}
F_55 ( V_1 , false ) ;
}
if ( F_1 ( V_1 ) ) {
F_201 ( & V_23 -> V_25 , V_24 ) ;
F_202 ( V_9 ) ;
}
F_179 ( V_1 , V_9 ) ;
if ( F_203 ( V_7 ) && ! F_204 ( V_7 ) ) {
T_3 V_306 = F_21 ( V_476 ) ;
F_45 ( V_476 , ( V_306 & ~ 0xf ) | 0xd ) ;
}
}
void
F_205 ( struct V_6 * V_7 , int V_184 , enum V_305 V_305 )
{
struct V_2 * V_3 ;
struct V_143 * V_143 ;
struct V_10 * V_11 ;
struct V_23 * V_23 ;
V_3 = F_206 ( sizeof( struct V_2 ) , V_383 ) ;
if ( ! V_3 )
return;
V_23 = F_206 ( sizeof( struct V_23 ) , V_383 ) ;
if ( ! V_23 ) {
F_157 ( V_3 ) ;
return;
}
V_143 = & V_3 -> V_4 ;
V_11 = & V_143 -> V_4 ;
F_207 ( V_7 , & V_143 -> V_4 , & V_477 ,
V_478 ) ;
F_208 ( & V_143 -> V_4 , & V_479 ) ;
V_143 -> V_480 = F_56 ;
V_143 -> V_481 = F_105 ;
V_143 -> V_482 = F_109 ;
V_143 -> V_483 = F_102 ;
V_143 -> V_484 = F_104 ;
V_143 -> V_457 = F_97 ;
V_3 -> V_305 = V_305 ;
V_3 -> V_401 . V_184 = V_184 ;
V_143 -> type = V_388 ;
V_143 -> V_485 = ( 1 << 0 ) | ( 1 << 1 ) | ( 1 << 2 ) ;
V_143 -> V_486 = false ;
V_143 -> V_487 = F_175 ;
F_188 ( V_3 , V_23 ) ;
}
