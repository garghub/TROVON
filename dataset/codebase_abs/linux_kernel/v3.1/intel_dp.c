static bool F_1 ( struct V_1 * V_1 )
{
return V_1 -> V_2 . type == V_3 ;
}
static bool F_2 ( struct V_1 * V_1 )
{
return V_1 -> F_2 ;
}
static struct V_1 * F_3 ( struct V_4 * V_5 )
{
return F_4 ( V_5 , struct V_1 , V_2 . V_2 ) ;
}
static struct V_1 * F_5 ( struct V_6 * V_7 )
{
return F_4 ( F_6 ( V_7 ) ,
struct V_1 , V_2 ) ;
}
bool F_7 ( struct V_4 * V_5 )
{
struct V_1 * V_1 ;
if ( ! V_5 )
return false ;
V_1 = F_3 ( V_5 ) ;
return F_2 ( V_1 ) ;
}
void
F_8 ( struct V_8 * V_8 ,
int * V_9 , int * V_10 )
{
struct V_1 * V_1 = F_4 ( V_8 , struct V_1 , V_2 ) ;
* V_9 = V_1 -> V_11 ;
if ( V_1 -> V_10 == V_12 )
* V_10 = 162000 ;
else if ( V_1 -> V_10 == V_13 )
* V_10 = 270000 ;
}
static int
F_9 ( struct V_1 * V_1 )
{
int V_14 = 4 ;
if ( V_1 -> V_15 [ V_16 ] >= 0x11 ) {
V_14 = V_1 -> V_15 [ V_17 ] & 0x1f ;
switch ( V_14 ) {
case 1 : case 2 : case 4 :
break;
default:
V_14 = 4 ;
}
}
return V_14 ;
}
static int
F_10 ( struct V_1 * V_1 )
{
int V_18 = V_1 -> V_15 [ V_19 ] ;
switch ( V_18 ) {
case V_12 :
case V_13 :
break;
default:
V_18 = V_12 ;
break;
}
return V_18 ;
}
static int
F_11 ( T_1 V_10 )
{
if ( V_10 == V_13 )
return 270000 ;
else
return 162000 ;
}
static int
F_12 ( struct V_20 * V_21 , struct V_1 * V_1 , int V_22 )
{
struct V_23 * V_24 = V_1 -> V_2 . V_2 . V_24 ;
struct V_25 * V_25 = F_13 ( V_24 ) ;
int V_26 = 24 ;
if ( V_25 )
V_26 = V_25 -> V_26 ;
return ( V_22 * V_26 + 7 ) / 8 ;
}
static int
F_14 ( int V_27 , int V_28 )
{
return ( V_27 * V_28 * 8 ) / 10 ;
}
static int
F_15 ( struct V_6 * V_7 ,
struct V_29 * V_30 )
{
struct V_1 * V_1 = F_5 ( V_7 ) ;
struct V_20 * V_21 = V_7 -> V_21 ;
struct V_31 * V_32 = V_21 -> V_33 ;
int V_27 = F_11 ( F_10 ( V_1 ) ) ;
int V_28 = F_9 ( V_1 ) ;
if ( F_1 ( V_1 ) && V_32 -> V_34 ) {
if ( V_30 -> V_35 > V_32 -> V_34 -> V_35 )
return V_36 ;
if ( V_30 -> V_37 > V_32 -> V_34 -> V_37 )
return V_36 ;
}
if ( ! F_1 ( V_1 ) &&
( F_12 ( V_7 -> V_21 , V_1 , V_30 -> clock )
> F_14 ( V_27 , V_28 ) ) )
return V_38 ;
if ( V_30 -> clock < 10000 )
return V_39 ;
return V_40 ;
}
static T_2
F_16 ( T_1 * V_41 , int V_42 )
{
int V_43 ;
T_2 V_44 = 0 ;
if ( V_42 > 4 )
V_42 = 4 ;
for ( V_43 = 0 ; V_43 < V_42 ; V_43 ++ )
V_44 |= ( ( T_2 ) V_41 [ V_43 ] ) << ( ( 3 - V_43 ) * 8 ) ;
return V_44 ;
}
static void
F_17 ( T_2 V_41 , T_1 * V_45 , int V_46 )
{
int V_43 ;
if ( V_46 > 4 )
V_46 = 4 ;
for ( V_43 = 0 ; V_43 < V_46 ; V_43 ++ )
V_45 [ V_43 ] = V_41 >> ( ( 3 - V_43 ) * 8 ) ;
}
static int
F_18 ( struct V_20 * V_21 )
{
struct V_31 * V_32 = V_21 -> V_33 ;
T_2 V_47 ;
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
static int
F_20 ( struct V_1 * V_1 ,
T_1 * V_58 , int V_59 ,
T_1 * V_60 , int V_61 )
{
T_2 V_62 = V_1 -> V_62 ;
struct V_20 * V_21 = V_1 -> V_2 . V_2 . V_21 ;
struct V_31 * V_32 = V_21 -> V_33 ;
T_2 V_63 = V_62 + 0x10 ;
T_2 V_64 = V_63 + 4 ;
int V_43 ;
int V_65 ;
T_2 V_66 ;
T_2 V_67 ;
int V_68 , V_69 ;
if ( F_1 ( V_1 ) && ! F_2 ( V_1 ) ) {
if ( F_21 ( V_21 ) )
V_67 = 200 ;
else
V_67 = 225 ;
} else if ( F_22 ( V_21 ) )
V_67 = 62 ;
else
V_67 = F_18 ( V_21 ) / 2 ;
if ( F_21 ( V_21 ) )
V_69 = 3 ;
else
V_69 = 5 ;
for ( V_68 = 0 ; V_68 < 3 ; V_68 ++ ) {
V_66 = F_19 ( V_63 ) ;
if ( ( V_66 & V_70 ) == 0 )
break;
F_23 ( 1 ) ;
}
if ( V_68 == 3 ) {
F_24 ( 1 , L_1 ,
F_19 ( V_63 ) ) ;
return - V_71 ;
}
for ( V_68 = 0 ; V_68 < 5 ; V_68 ++ ) {
for ( V_43 = 0 ; V_43 < V_59 ; V_43 += 4 )
F_25 ( V_64 + V_43 ,
F_16 ( V_58 + V_43 , V_59 - V_43 ) ) ;
F_25 ( V_63 ,
V_70 |
V_72 |
( V_59 << V_73 ) |
( V_69 << V_74 ) |
( V_67 << V_75 ) |
V_76 |
V_77 |
V_78 ) ;
for (; ; ) {
V_66 = F_19 ( V_63 ) ;
if ( ( V_66 & V_70 ) == 0 )
break;
F_26 ( 100 ) ;
}
F_25 ( V_63 ,
V_66 |
V_76 |
V_77 |
V_78 ) ;
if ( V_66 & V_76 )
break;
}
if ( ( V_66 & V_76 ) == 0 ) {
F_27 ( L_2 , V_66 ) ;
return - V_71 ;
}
if ( V_66 & V_78 ) {
F_27 ( L_3 , V_66 ) ;
return - V_79 ;
}
if ( V_66 & V_77 ) {
F_28 ( L_4 , V_66 ) ;
return - V_80 ;
}
V_65 = ( ( V_66 & V_81 ) >>
V_73 ) ;
if ( V_65 > V_61 )
V_65 = V_61 ;
for ( V_43 = 0 ; V_43 < V_65 ; V_43 += 4 )
F_17 ( F_19 ( V_64 + V_43 ) ,
V_60 + V_43 , V_65 - V_43 ) ;
return V_65 ;
}
static int
F_29 ( struct V_1 * V_1 ,
T_3 V_82 , T_1 * V_58 , int V_59 )
{
int V_83 ;
T_1 V_84 [ 20 ] ;
int V_85 ;
T_1 V_86 ;
if ( V_59 > 16 )
return - 1 ;
V_84 [ 0 ] = V_87 << 4 ;
V_84 [ 1 ] = V_82 >> 8 ;
V_84 [ 2 ] = V_82 & 0xff ;
V_84 [ 3 ] = V_59 - 1 ;
memcpy ( & V_84 [ 4 ] , V_58 , V_59 ) ;
V_85 = V_59 + 4 ;
for (; ; ) {
V_83 = F_20 ( V_1 , V_84 , V_85 , & V_86 , 1 ) ;
if ( V_83 < 0 )
return V_83 ;
if ( ( V_86 & V_88 ) == V_89 )
break;
else if ( ( V_86 & V_88 ) == V_90 )
F_26 ( 100 ) ;
else
return - V_79 ;
}
return V_59 ;
}
static int
F_30 ( struct V_1 * V_1 ,
T_3 V_82 , T_1 V_91 )
{
return F_29 ( V_1 , V_82 , & V_91 , 1 ) ;
}
static int
F_31 ( struct V_1 * V_1 ,
T_3 V_82 , T_1 * V_60 , int V_65 )
{
T_1 V_84 [ 4 ] ;
int V_85 ;
T_1 V_92 [ 20 ] ;
int V_93 ;
T_1 V_86 ;
int V_83 ;
V_84 [ 0 ] = V_94 << 4 ;
V_84 [ 1 ] = V_82 >> 8 ;
V_84 [ 2 ] = V_82 & 0xff ;
V_84 [ 3 ] = V_65 - 1 ;
V_85 = 4 ;
V_93 = V_65 + 1 ;
for (; ; ) {
V_83 = F_20 ( V_1 , V_84 , V_85 ,
V_92 , V_93 ) ;
if ( V_83 == 0 )
return - V_95 ;
if ( V_83 < 0 )
return V_83 ;
V_86 = V_92 [ 0 ] ;
if ( ( V_86 & V_88 ) == V_89 ) {
memcpy ( V_60 , V_92 + 1 , V_83 - 1 ) ;
return V_83 - 1 ;
}
else if ( ( V_86 & V_88 ) == V_90 )
F_26 ( 100 ) ;
else
return - V_79 ;
}
}
static int
F_32 ( struct V_96 * V_97 , int V_30 ,
T_1 V_98 , T_1 * V_99 )
{
struct V_100 * V_101 = V_97 -> V_101 ;
struct V_1 * V_1 = F_4 ( V_97 ,
struct V_1 ,
V_97 ) ;
T_3 V_82 = V_101 -> V_82 ;
T_1 V_84 [ 5 ] ;
T_1 V_92 [ 2 ] ;
unsigned V_102 ;
int V_85 ;
int V_93 ;
int V_83 ;
if ( V_30 & V_103 )
V_84 [ 0 ] = V_104 << 4 ;
else
V_84 [ 0 ] = V_105 << 4 ;
if ( ! ( V_30 & V_106 ) )
V_84 [ 0 ] |= V_107 << 4 ;
V_84 [ 1 ] = V_82 >> 8 ;
V_84 [ 2 ] = V_82 ;
switch ( V_30 ) {
case V_108 :
V_84 [ 3 ] = 0 ;
V_84 [ 4 ] = V_98 ;
V_85 = 5 ;
V_93 = 1 ;
break;
case V_103 :
V_84 [ 3 ] = 0 ;
V_85 = 4 ;
V_93 = 2 ;
break;
default:
V_85 = 3 ;
V_93 = 1 ;
break;
}
for ( V_102 = 0 ; V_102 < 5 ; V_102 ++ ) {
V_83 = F_20 ( V_1 ,
V_84 , V_85 ,
V_92 , V_93 ) ;
if ( V_83 < 0 ) {
F_28 ( L_5 , V_83 ) ;
return V_83 ;
}
switch ( V_92 [ 0 ] & V_88 ) {
case V_89 :
break;
case V_109 :
F_28 ( L_6 ) ;
return - V_110 ;
case V_90 :
F_26 ( 100 ) ;
continue;
default:
F_27 ( L_7 ,
V_92 [ 0 ] ) ;
return - V_110 ;
}
switch ( V_92 [ 0 ] & V_111 ) {
case V_112 :
if ( V_30 == V_103 ) {
* V_99 = V_92 [ 1 ] ;
}
return V_93 - 1 ;
case V_113 :
F_28 ( L_8 ) ;
return - V_110 ;
case V_114 :
F_28 ( L_9 ) ;
F_26 ( 100 ) ;
break;
default:
F_27 ( L_10 , V_92 [ 0 ] ) ;
return - V_110 ;
}
}
F_27 ( L_11 ) ;
return - V_110 ;
}
static int
F_33 ( struct V_1 * V_1 ,
struct V_115 * V_115 , const char * V_116 )
{
F_28 ( L_12 , V_116 ) ;
V_1 -> V_117 . V_118 = false ;
V_1 -> V_117 . V_82 = 0 ;
V_1 -> V_117 . V_119 = F_32 ;
memset ( & V_1 -> V_97 , '\0' , sizeof ( V_1 -> V_97 ) ) ;
V_1 -> V_97 . V_120 = V_121 ;
V_1 -> V_97 . V_122 = V_123 ;
strncpy ( V_1 -> V_97 . V_116 , V_116 , sizeof( V_1 -> V_97 . V_116 ) - 1 ) ;
V_1 -> V_97 . V_116 [ sizeof( V_1 -> V_97 . V_116 ) - 1 ] = '\0' ;
V_1 -> V_97 . V_101 = & V_1 -> V_117 ;
V_1 -> V_97 . V_21 . V_124 = & V_115 -> V_2 . V_125 ;
return F_34 ( & V_1 -> V_97 ) ;
}
static bool
F_35 ( struct V_4 * V_5 , struct V_29 * V_30 ,
struct V_29 * V_126 )
{
struct V_20 * V_21 = V_5 -> V_21 ;
struct V_31 * V_32 = V_21 -> V_33 ;
struct V_1 * V_1 = F_3 ( V_5 ) ;
int V_11 , clock ;
int V_14 = F_9 ( V_1 ) ;
int V_127 = F_10 ( V_1 ) == V_13 ? 1 : 0 ;
static int V_128 [ 2 ] = { V_12 , V_13 } ;
if ( F_1 ( V_1 ) && V_32 -> V_34 ) {
F_36 ( V_32 -> V_34 , V_126 ) ;
F_37 ( V_21 , V_129 ,
V_30 , V_126 ) ;
V_30 -> clock = V_32 -> V_34 -> clock ;
}
for ( V_11 = 1 ; V_11 <= V_14 ; V_11 <<= 1 ) {
for ( clock = 0 ; clock <= V_127 ; clock ++ ) {
int V_130 = F_14 ( F_11 ( V_128 [ clock ] ) , V_11 ) ;
if ( F_12 ( V_5 -> V_21 , V_1 , V_30 -> clock )
<= V_130 ) {
V_1 -> V_10 = V_128 [ clock ] ;
V_1 -> V_11 = V_11 ;
V_126 -> clock = F_11 ( V_1 -> V_10 ) ;
F_28 ( L_13
L_14 ,
V_1 -> V_10 , V_1 -> V_11 ,
V_126 -> clock ) ;
return true ;
}
}
}
if ( F_1 ( V_1 ) ) {
V_1 -> V_11 = V_14 ;
V_1 -> V_10 = V_128 [ V_127 ] ;
V_126 -> clock = F_11 ( V_1 -> V_10 ) ;
F_28 ( L_15
L_14 ,
V_1 -> V_10 , V_1 -> V_11 ,
V_126 -> clock ) ;
return true ;
}
return false ;
}
static void
F_38 ( T_2 * V_131 , T_2 * V_132 )
{
while ( * V_131 > 0xffffff || * V_132 > 0xffffff ) {
* V_131 >>= 1 ;
* V_132 >>= 1 ;
}
}
static void
F_39 ( int V_26 ,
int V_133 ,
int V_22 ,
int V_134 ,
struct V_135 * V_136 )
{
V_136 -> V_137 = 64 ;
V_136 -> V_138 = ( V_22 * V_26 ) >> 3 ;
V_136 -> V_139 = V_134 * V_133 ;
F_38 ( & V_136 -> V_138 , & V_136 -> V_139 ) ;
V_136 -> V_140 = V_22 ;
V_136 -> V_141 = V_134 ;
F_38 ( & V_136 -> V_140 , & V_136 -> V_141 ) ;
}
void
F_40 ( struct V_23 * V_24 , struct V_29 * V_30 ,
struct V_29 * V_126 )
{
struct V_20 * V_21 = V_24 -> V_21 ;
struct V_142 * V_143 = & V_21 -> V_143 ;
struct V_4 * V_5 ;
struct V_31 * V_32 = V_21 -> V_33 ;
struct V_25 * V_25 = F_13 ( V_24 ) ;
int V_11 = 4 ;
struct V_135 V_136 ;
int V_144 = V_25 -> V_144 ;
F_41 (encoder, &mode_config->encoder_list, head) {
struct V_1 * V_1 ;
if ( V_5 -> V_24 != V_24 )
continue;
V_1 = F_3 ( V_5 ) ;
if ( V_1 -> V_2 . type == V_145 ) {
V_11 = V_1 -> V_11 ;
break;
} else if ( F_1 ( V_1 ) ) {
V_11 = V_32 -> V_146 . V_147 ;
break;
}
}
F_39 ( V_25 -> V_26 , V_11 ,
V_30 -> clock , V_126 -> clock , & V_136 ) ;
if ( F_22 ( V_21 ) ) {
F_25 ( F_42 ( V_144 ) ,
( ( V_136 . V_137 - 1 ) << V_148 ) |
V_136 . V_138 ) ;
F_25 ( F_43 ( V_144 ) , V_136 . V_139 ) ;
F_25 ( F_44 ( V_144 ) , V_136 . V_140 ) ;
F_25 ( F_45 ( V_144 ) , V_136 . V_141 ) ;
} else {
F_25 ( F_46 ( V_144 ) ,
( ( V_136 . V_137 - 1 ) << V_148 ) |
V_136 . V_138 ) ;
F_25 ( F_47 ( V_144 ) , V_136 . V_139 ) ;
F_25 ( F_48 ( V_144 ) , V_136 . V_140 ) ;
F_25 ( F_49 ( V_144 ) , V_136 . V_141 ) ;
}
}
static void
F_50 ( struct V_4 * V_5 , struct V_29 * V_30 ,
struct V_29 * V_126 )
{
struct V_20 * V_21 = V_5 -> V_21 ;
struct V_1 * V_1 = F_3 ( V_5 ) ;
struct V_23 * V_24 = V_1 -> V_2 . V_2 . V_24 ;
struct V_25 * V_25 = F_13 ( V_24 ) ;
V_1 -> V_149 = V_150 | V_151 ;
V_1 -> V_149 |= V_1 -> V_152 ;
if ( V_126 -> V_153 & V_154 )
V_1 -> V_149 |= V_155 ;
if ( V_126 -> V_153 & V_156 )
V_1 -> V_149 |= V_157 ;
if ( F_51 ( V_21 ) && ! F_1 ( V_1 ) )
V_1 -> V_149 |= V_158 ;
else
V_1 -> V_149 |= V_159 ;
switch ( V_1 -> V_11 ) {
case 1 :
V_1 -> V_149 |= V_160 ;
break;
case 2 :
V_1 -> V_149 |= V_161 ;
break;
case 4 :
V_1 -> V_149 |= V_162 ;
break;
}
if ( V_1 -> V_163 )
V_1 -> V_149 |= V_164 ;
memset ( V_1 -> V_165 , 0 , V_166 ) ;
V_1 -> V_165 [ 0 ] = V_1 -> V_10 ;
V_1 -> V_165 [ 1 ] = V_1 -> V_11 ;
V_1 -> V_165 [ 8 ] = V_167 ;
if ( V_1 -> V_15 [ V_16 ] >= 0x11 &&
( V_1 -> V_15 [ V_17 ] & V_168 ) ) {
V_1 -> V_165 [ 1 ] |= V_169 ;
V_1 -> V_149 |= V_170 ;
}
if ( V_25 -> V_144 == 1 && ! F_51 ( V_21 ) )
V_1 -> V_149 |= V_171 ;
if ( F_1 ( V_1 ) && ! F_2 ( V_1 ) ) {
V_1 -> V_149 |= V_172 ;
if ( V_126 -> clock < 200000 )
V_1 -> V_149 |= V_173 ;
else
V_1 -> V_149 |= V_174 ;
}
}
static void F_52 ( struct V_1 * V_1 )
{
struct V_20 * V_21 = V_1 -> V_2 . V_2 . V_21 ;
struct V_31 * V_32 = V_21 -> V_33 ;
T_4 V_175 ;
if ( ! ( F_19 ( V_176 ) & V_177 ) )
F_23 ( V_32 -> V_178 ) ;
V_175 = F_19 ( V_179 ) ;
V_175 |= V_180 ;
F_25 ( V_179 , V_175 ) ;
F_53 ( V_179 ) ;
}
static void F_54 ( struct V_1 * V_1 )
{
struct V_20 * V_21 = V_1 -> V_2 . V_2 . V_21 ;
struct V_31 * V_32 = V_21 -> V_33 ;
T_4 V_175 ;
V_175 = F_19 ( V_179 ) ;
V_175 &= ~ V_180 ;
F_25 ( V_179 , V_175 ) ;
F_53 ( V_179 ) ;
F_23 ( V_32 -> V_181 ) ;
}
static bool F_55 ( struct V_1 * V_1 )
{
struct V_20 * V_21 = V_1 -> V_2 . V_2 . V_21 ;
struct V_31 * V_32 = V_21 -> V_33 ;
T_4 V_175 , V_182 = V_177 | V_183 ;
if ( F_19 ( V_176 ) & V_177 )
return true ;
V_175 = F_19 ( V_179 ) ;
V_175 &= ~ V_184 ;
F_25 ( V_179 , V_175 ) ;
F_53 ( V_179 ) ;
V_175 |= V_185 | V_186 ;
F_25 ( V_179 , V_175 ) ;
F_53 ( V_179 ) ;
if ( F_56 ( ( F_19 ( V_176 ) & V_182 ) == V_182 ,
5000 ) )
F_27 ( L_16 ,
F_19 ( V_176 ) ) ;
V_175 |= V_184 ;
F_25 ( V_179 , V_175 ) ;
F_53 ( V_179 ) ;
return false ;
}
static void F_57 ( struct V_20 * V_21 )
{
struct V_31 * V_32 = V_21 -> V_33 ;
T_4 V_175 , V_187 = V_177 | V_188 |
V_189 | V_190 ;
V_175 = F_19 ( V_179 ) ;
V_175 &= ~ V_184 ;
F_25 ( V_179 , V_175 ) ;
F_53 ( V_179 ) ;
V_175 &= ~ V_186 ;
F_25 ( V_179 , V_175 ) ;
F_53 ( V_179 ) ;
if ( F_56 ( ( F_19 ( V_176 ) & V_187 ) == 0 , 5000 ) )
F_27 ( L_17 ,
F_19 ( V_176 ) ) ;
V_175 |= V_184 ;
F_25 ( V_179 , V_175 ) ;
F_53 ( V_179 ) ;
}
static void F_58 ( struct V_20 * V_21 )
{
struct V_31 * V_32 = V_21 -> V_33 ;
T_4 V_175 ;
F_28 ( L_18 ) ;
F_23 ( 300 ) ;
V_175 = F_19 ( V_179 ) ;
V_175 |= V_191 ;
F_25 ( V_179 , V_175 ) ;
}
static void F_59 ( struct V_20 * V_21 )
{
struct V_31 * V_32 = V_21 -> V_33 ;
T_4 V_175 ;
F_28 ( L_18 ) ;
V_175 = F_19 ( V_179 ) ;
V_175 &= ~ V_191 ;
F_25 ( V_179 , V_175 ) ;
}
static void F_60 ( struct V_4 * V_5 )
{
struct V_20 * V_21 = V_5 -> V_21 ;
struct V_31 * V_32 = V_21 -> V_33 ;
T_4 V_192 ;
F_28 ( L_18 ) ;
V_192 = F_19 ( V_193 ) ;
V_192 |= V_172 ;
F_25 ( V_193 , V_192 ) ;
F_53 ( V_193 ) ;
F_26 ( 200 ) ;
}
static void F_61 ( struct V_4 * V_5 )
{
struct V_20 * V_21 = V_5 -> V_21 ;
struct V_31 * V_32 = V_21 -> V_33 ;
T_4 V_192 ;
V_192 = F_19 ( V_193 ) ;
V_192 &= ~ V_172 ;
F_25 ( V_193 , V_192 ) ;
F_53 ( V_193 ) ;
F_26 ( 200 ) ;
}
static void F_62 ( struct V_1 * V_1 , int V_30 )
{
int V_83 , V_43 ;
if ( V_1 -> V_15 [ V_16 ] < 0x11 )
return;
if ( V_30 != V_194 ) {
V_83 = F_30 ( V_1 , V_195 ,
V_196 ) ;
if ( V_83 != 1 )
F_63 ( L_19 ) ;
} else {
for ( V_43 = 0 ; V_43 < 3 ; V_43 ++ ) {
V_83 = F_30 ( V_1 ,
V_195 ,
V_197 ) ;
if ( V_83 == 1 )
break;
F_23 ( 1 ) ;
}
}
}
static void F_64 ( struct V_4 * V_5 )
{
struct V_1 * V_1 = F_3 ( V_5 ) ;
struct V_20 * V_21 = V_5 -> V_21 ;
F_62 ( V_1 , V_194 ) ;
if ( F_1 ( V_1 ) ) {
F_59 ( V_21 ) ;
F_57 ( V_21 ) ;
if ( ! F_2 ( V_1 ) )
F_60 ( V_5 ) ;
else
F_61 ( V_5 ) ;
}
F_65 ( V_1 ) ;
}
static void F_66 ( struct V_4 * V_5 )
{
struct V_1 * V_1 = F_3 ( V_5 ) ;
struct V_20 * V_21 = V_5 -> V_21 ;
if ( F_1 ( V_1 ) )
F_52 ( V_1 ) ;
F_67 ( V_1 ) ;
if ( F_1 ( V_1 ) ) {
F_55 ( V_1 ) ;
F_54 ( V_1 ) ;
}
F_68 ( V_1 ) ;
if ( F_1 ( V_1 ) )
F_58 ( V_21 ) ;
V_1 -> V_198 = V_194 ;
}
static void
F_69 ( struct V_4 * V_5 , int V_30 )
{
struct V_1 * V_1 = F_3 ( V_5 ) ;
struct V_20 * V_21 = V_5 -> V_21 ;
struct V_31 * V_32 = V_21 -> V_33 ;
T_2 V_199 = F_19 ( V_1 -> V_62 ) ;
if ( V_30 != V_194 ) {
if ( F_1 ( V_1 ) )
F_59 ( V_21 ) ;
F_62 ( V_1 , V_30 ) ;
F_65 ( V_1 ) ;
if ( F_1 ( V_1 ) )
F_57 ( V_21 ) ;
if ( F_1 ( V_1 ) && ! F_2 ( V_1 ) )
F_61 ( V_5 ) ;
} else {
if ( F_1 ( V_1 ) )
F_52 ( V_1 ) ;
F_62 ( V_1 , V_30 ) ;
if ( ! ( V_199 & V_200 ) ) {
F_67 ( V_1 ) ;
if ( F_1 ( V_1 ) ) {
F_55 ( V_1 ) ;
F_54 ( V_1 ) ;
}
F_68 ( V_1 ) ;
}
if ( F_1 ( V_1 ) )
F_58 ( V_21 ) ;
}
V_1 -> V_198 = V_30 ;
}
static bool
F_70 ( struct V_1 * V_1 , T_3 V_82 ,
T_1 * V_60 , int V_65 )
{
int V_83 , V_43 ;
for ( V_43 = 0 ; V_43 < 3 ; V_43 ++ ) {
V_83 = F_31 ( V_1 , V_82 , V_60 ,
V_65 ) ;
if ( V_83 == V_65 )
return true ;
F_23 ( 1 ) ;
}
return false ;
}
static bool
F_71 ( struct V_1 * V_1 )
{
return F_70 ( V_1 ,
V_201 ,
V_1 -> V_202 ,
V_203 ) ;
}
static T_1
F_72 ( T_1 V_202 [ V_203 ] ,
int V_204 )
{
return V_202 [ V_204 - V_201 ] ;
}
static T_1
F_73 ( T_1 V_202 [ V_203 ] ,
int V_205 )
{
int V_43 = V_206 + ( V_205 >> 1 ) ;
int V_207 = ( ( V_205 & 1 ) ?
V_208 :
V_209 ) ;
T_1 V_210 = F_72 ( V_202 , V_43 ) ;
return ( ( V_210 >> V_207 ) & 3 ) << V_211 ;
}
static T_1
F_74 ( T_1 V_202 [ V_203 ] ,
int V_205 )
{
int V_43 = V_206 + ( V_205 >> 1 ) ;
int V_207 = ( ( V_205 & 1 ) ?
V_212 :
V_213 ) ;
T_1 V_210 = F_72 ( V_202 , V_43 ) ;
return ( ( V_210 >> V_207 ) & 3 ) << V_214 ;
}
static T_1
F_75 ( T_1 V_215 )
{
switch ( V_215 & V_216 ) {
case V_217 :
return V_218 ;
case V_219 :
return V_218 ;
case V_220 :
return V_221 ;
case V_222 :
default:
return V_223 ;
}
}
static void
F_76 ( struct V_1 * V_1 )
{
T_1 V_44 = 0 ;
T_1 V_224 = 0 ;
int V_205 ;
for ( V_205 = 0 ; V_205 < V_1 -> V_11 ; V_205 ++ ) {
T_1 V_225 = F_73 ( V_1 -> V_202 , V_205 ) ;
T_1 V_226 = F_74 ( V_1 -> V_202 , V_205 ) ;
if ( V_225 > V_44 )
V_44 = V_225 ;
if ( V_226 > V_224 )
V_224 = V_226 ;
}
if ( V_44 >= V_227 )
V_44 = V_227 | V_228 ;
if ( V_224 >= F_75 ( V_44 ) )
V_224 = F_75 ( V_44 ) | V_229 ;
for ( V_205 = 0 ; V_205 < 4 ; V_205 ++ )
V_1 -> V_230 [ V_205 ] = V_44 | V_224 ;
}
static T_2
F_77 ( T_1 V_230 , int V_11 )
{
T_2 V_231 = 0 ;
switch ( V_230 & V_216 ) {
case V_217 :
default:
V_231 |= V_150 ;
break;
case V_219 :
V_231 |= V_232 ;
break;
case V_220 :
V_231 |= V_233 ;
break;
case V_222 :
V_231 |= V_234 ;
break;
}
switch ( V_230 & V_235 ) {
case V_223 :
default:
V_231 |= V_151 ;
break;
case V_221 :
V_231 |= V_236 ;
break;
case V_218 :
V_231 |= V_237 ;
break;
case V_238 :
V_231 |= V_239 ;
break;
}
return V_231 ;
}
static T_2
F_78 ( T_1 V_230 )
{
int V_231 = V_230 & ( V_216 |
V_235 ) ;
switch ( V_231 ) {
case V_217 | V_223 :
case V_219 | V_223 :
return V_240 ;
case V_217 | V_221 :
return V_241 ;
case V_217 | V_218 :
case V_219 | V_218 :
return V_242 ;
case V_219 | V_221 :
case V_220 | V_221 :
return V_243 ;
case V_220 | V_223 :
case V_222 | V_223 :
return V_244 ;
default:
F_28 ( L_20
L_21 , V_231 ) ;
return V_240 ;
}
}
static T_1
F_79 ( T_1 V_202 [ V_203 ] ,
int V_205 )
{
int V_43 = V_201 + ( V_205 >> 1 ) ;
int V_207 = ( V_205 & 1 ) * 4 ;
T_1 V_210 = F_72 ( V_202 , V_43 ) ;
return ( V_210 >> V_207 ) & 0xf ;
}
static bool
F_80 ( T_1 V_202 [ V_203 ] , int V_11 )
{
int V_205 ;
T_1 V_245 ;
for ( V_205 = 0 ; V_205 < V_11 ; V_205 ++ ) {
V_245 = F_79 ( V_202 , V_205 ) ;
if ( ( V_245 & V_246 ) == 0 )
return false ;
}
return true ;
}
static bool
F_81 ( struct V_1 * V_1 )
{
T_1 V_247 ;
T_1 V_245 ;
int V_205 ;
V_247 = F_72 ( V_1 -> V_202 ,
V_248 ) ;
if ( ( V_247 & V_249 ) == 0 )
return false ;
for ( V_205 = 0 ; V_205 < V_1 -> V_11 ; V_205 ++ ) {
V_245 = F_79 ( V_1 -> V_202 , V_205 ) ;
if ( ( V_245 & V_250 ) != V_250 )
return false ;
}
return true ;
}
static bool
F_82 ( struct V_1 * V_1 ,
T_2 V_251 ,
T_1 V_252 )
{
struct V_20 * V_21 = V_1 -> V_2 . V_2 . V_21 ;
struct V_31 * V_32 = V_21 -> V_33 ;
int V_83 ;
F_25 ( V_1 -> V_62 , V_251 ) ;
F_53 ( V_1 -> V_62 ) ;
F_30 ( V_1 ,
V_253 ,
V_252 ) ;
V_83 = F_29 ( V_1 ,
V_254 ,
V_1 -> V_230 , 4 ) ;
if ( V_83 != 4 )
return false ;
return true ;
}
static void
F_67 ( struct V_1 * V_1 )
{
struct V_20 * V_21 = V_1 -> V_2 . V_2 . V_21 ;
struct V_31 * V_32 = V_21 -> V_33 ;
struct V_25 * V_25 = F_13 ( V_1 -> V_2 . V_2 . V_24 ) ;
int V_43 ;
T_1 V_255 ;
bool V_256 = false ;
int V_257 ;
T_4 V_258 ;
T_2 V_149 = V_1 -> V_149 ;
if ( ! F_51 ( V_21 ) ) {
F_25 ( V_1 -> V_62 , V_1 -> V_149 ) ;
F_53 ( V_1 -> V_62 ) ;
F_83 ( V_21 , V_25 -> V_144 ) ;
}
F_29 ( V_1 , V_259 ,
V_1 -> V_165 ,
V_166 ) ;
V_149 |= V_200 ;
if ( F_51 ( V_21 ) && ! F_1 ( V_1 ) )
V_149 &= ~ V_260 ;
else
V_149 &= ~ V_261 ;
memset ( V_1 -> V_230 , 0 , 4 ) ;
V_255 = 0xff ;
V_257 = 0 ;
V_256 = false ;
for (; ; ) {
T_2 V_231 ;
if ( F_21 ( V_21 ) && F_1 ( V_1 ) ) {
V_231 = F_78 ( V_1 -> V_230 [ 0 ] ) ;
V_149 = ( V_149 & ~ V_262 ) | V_231 ;
} else {
V_231 = F_77 ( V_1 -> V_230 [ 0 ] , V_1 -> V_11 ) ;
V_149 = ( V_149 & ~ ( V_263 | V_264 ) ) | V_231 ;
}
if ( F_51 ( V_21 ) && ! F_1 ( V_1 ) )
V_258 = V_149 | V_265 ;
else
V_258 = V_149 | V_266 ;
if ( ! F_82 ( V_1 , V_258 ,
V_267 |
V_268 ) )
break;
F_26 ( 100 ) ;
if ( ! F_71 ( V_1 ) )
break;
if ( F_80 ( V_1 -> V_202 , V_1 -> V_11 ) ) {
V_256 = true ;
break;
}
for ( V_43 = 0 ; V_43 < V_1 -> V_11 ; V_43 ++ )
if ( ( V_1 -> V_230 [ V_43 ] & V_228 ) == 0 )
break;
if ( V_43 == V_1 -> V_11 )
break;
if ( ( V_1 -> V_230 [ 0 ] & V_216 ) == V_255 ) {
++ V_257 ;
if ( V_257 == 5 )
break;
} else
V_257 = 0 ;
V_255 = V_1 -> V_230 [ 0 ] & V_216 ;
F_76 ( V_1 ) ;
}
V_1 -> V_149 = V_149 ;
}
static void
F_68 ( struct V_1 * V_1 )
{
struct V_20 * V_21 = V_1 -> V_2 . V_2 . V_21 ;
struct V_31 * V_32 = V_21 -> V_33 ;
bool V_269 = false ;
int V_257 , V_270 ;
T_4 V_258 ;
T_2 V_149 = V_1 -> V_149 ;
V_257 = 0 ;
V_270 = 0 ;
V_269 = false ;
for (; ; ) {
T_2 V_231 ;
if ( V_270 > 5 ) {
F_27 ( L_22 ) ;
F_65 ( V_1 ) ;
break;
}
if ( F_21 ( V_21 ) && F_1 ( V_1 ) ) {
V_231 = F_78 ( V_1 -> V_230 [ 0 ] ) ;
V_149 = ( V_149 & ~ V_262 ) | V_231 ;
} else {
V_231 = F_77 ( V_1 -> V_230 [ 0 ] , V_1 -> V_11 ) ;
V_149 = ( V_149 & ~ ( V_263 | V_264 ) ) | V_231 ;
}
if ( F_51 ( V_21 ) && ! F_1 ( V_1 ) )
V_258 = V_149 | V_271 ;
else
V_258 = V_149 | V_272 ;
if ( ! F_82 ( V_1 , V_258 ,
V_273 |
V_268 ) )
break;
F_26 ( 400 ) ;
if ( ! F_71 ( V_1 ) )
break;
if ( ! F_80 ( V_1 -> V_202 , V_1 -> V_11 ) ) {
F_67 ( V_1 ) ;
V_270 ++ ;
continue;
}
if ( F_81 ( V_1 ) ) {
V_269 = true ;
break;
}
if ( V_257 > 5 ) {
F_65 ( V_1 ) ;
F_67 ( V_1 ) ;
V_257 = 0 ;
V_270 ++ ;
continue;
}
F_76 ( V_1 ) ;
++ V_257 ;
}
if ( F_51 ( V_21 ) && ! F_1 ( V_1 ) )
V_258 = V_149 | V_158 ;
else
V_258 = V_149 | V_159 ;
F_25 ( V_1 -> V_62 , V_258 ) ;
F_53 ( V_1 -> V_62 ) ;
F_30 ( V_1 ,
V_253 , V_274 ) ;
}
static void
F_65 ( struct V_1 * V_1 )
{
struct V_20 * V_21 = V_1 -> V_2 . V_2 . V_21 ;
struct V_31 * V_32 = V_21 -> V_33 ;
T_2 V_149 = V_1 -> V_149 ;
if ( ( F_19 ( V_1 -> V_62 ) & V_200 ) == 0 )
return;
F_28 ( L_18 ) ;
if ( F_1 ( V_1 ) ) {
V_149 &= ~ V_172 ;
F_25 ( V_1 -> V_62 , V_149 ) ;
F_53 ( V_1 -> V_62 ) ;
F_26 ( 100 ) ;
}
if ( F_51 ( V_21 ) && ! F_1 ( V_1 ) ) {
V_149 &= ~ V_260 ;
F_25 ( V_1 -> V_62 , V_149 | V_275 ) ;
} else {
V_149 &= ~ V_261 ;
F_25 ( V_1 -> V_62 , V_149 | V_276 ) ;
}
F_53 ( V_1 -> V_62 ) ;
F_23 ( 17 ) ;
if ( F_1 ( V_1 ) )
V_149 |= V_159 ;
if ( ! F_51 ( V_21 ) &&
F_19 ( V_1 -> V_62 ) & V_171 ) {
struct V_23 * V_24 = V_1 -> V_2 . V_2 . V_24 ;
V_149 &= ~ V_171 ;
F_25 ( V_1 -> V_62 , V_149 ) ;
if ( V_24 == NULL ) {
F_53 ( V_1 -> V_62 ) ;
F_23 ( 50 ) ;
} else
F_83 ( V_21 , F_13 ( V_24 ) -> V_144 ) ;
}
F_25 ( V_1 -> V_62 , V_149 & ~ V_200 ) ;
F_53 ( V_1 -> V_62 ) ;
}
static bool
F_84 ( struct V_1 * V_1 )
{
if ( F_70 ( V_1 , 0x000 , V_1 -> V_15 ,
sizeof ( V_1 -> V_15 ) ) &&
( V_1 -> V_15 [ V_16 ] != 0 ) ) {
return true ;
}
return false ;
}
static void
F_85 ( struct V_1 * V_1 )
{
if ( V_1 -> V_198 != V_194 )
return;
if ( ! V_1 -> V_2 . V_2 . V_24 )
return;
if ( ! F_71 ( V_1 ) ) {
F_65 ( V_1 ) ;
return;
}
if ( ! F_84 ( V_1 ) ) {
F_65 ( V_1 ) ;
return;
}
if ( ! F_81 ( V_1 ) ) {
F_28 ( L_23 ,
F_86 ( & V_1 -> V_2 . V_2 ) ) ;
F_67 ( V_1 ) ;
F_68 ( V_1 ) ;
}
}
static enum V_277
F_87 ( struct V_1 * V_1 )
{
if ( F_84 ( V_1 ) )
return V_278 ;
return V_279 ;
}
static enum V_277
F_88 ( struct V_1 * V_1 )
{
enum V_277 V_66 ;
if ( F_1 ( V_1 ) ) {
V_66 = F_89 ( V_1 -> V_2 . V_2 . V_21 ) ;
if ( V_66 == V_280 )
V_66 = V_278 ;
return V_66 ;
}
return F_87 ( V_1 ) ;
}
static enum V_277
F_90 ( struct V_1 * V_1 )
{
struct V_20 * V_21 = V_1 -> V_2 . V_2 . V_21 ;
struct V_31 * V_32 = V_21 -> V_33 ;
T_2 V_281 , V_282 ;
switch ( V_1 -> V_62 ) {
case V_283 :
V_282 = V_284 ;
break;
case V_285 :
V_282 = V_286 ;
break;
case V_287 :
V_282 = V_288 ;
break;
default:
return V_280 ;
}
V_281 = F_19 ( V_289 ) ;
if ( ( V_281 & V_282 ) == 0 )
return V_279 ;
return F_87 ( V_1 ) ;
}
static enum V_277
F_91 ( struct V_6 * V_7 , bool V_290 )
{
struct V_1 * V_1 = F_5 ( V_7 ) ;
struct V_20 * V_21 = V_1 -> V_2 . V_2 . V_21 ;
enum V_277 V_66 ;
struct V_291 * V_291 = NULL ;
V_1 -> V_163 = false ;
if ( F_22 ( V_21 ) )
V_66 = F_88 ( V_1 ) ;
else
V_66 = F_90 ( V_1 ) ;
F_28 ( L_24 ,
V_1 -> V_15 [ 0 ] , V_1 -> V_15 [ 1 ] , V_1 -> V_15 [ 2 ] ,
V_1 -> V_15 [ 3 ] , V_1 -> V_15 [ 4 ] , V_1 -> V_15 [ 5 ] ,
V_1 -> V_15 [ 6 ] , V_1 -> V_15 [ 7 ] ) ;
if ( V_66 != V_278 )
return V_66 ;
if ( V_1 -> V_292 ) {
V_1 -> V_163 = V_1 -> V_292 > 0 ;
} else {
V_291 = F_92 ( V_7 , & V_1 -> V_97 ) ;
if ( V_291 ) {
V_1 -> V_163 = F_93 ( V_291 ) ;
V_7 -> V_293 . V_294 = NULL ;
F_94 ( V_291 ) ;
}
}
return V_278 ;
}
static int F_95 ( struct V_6 * V_7 )
{
struct V_1 * V_1 = F_5 ( V_7 ) ;
struct V_20 * V_21 = V_1 -> V_2 . V_2 . V_21 ;
struct V_31 * V_32 = V_21 -> V_33 ;
int V_83 ;
V_83 = F_96 ( V_7 , & V_1 -> V_97 ) ;
if ( V_83 ) {
if ( F_1 ( V_1 ) && ! V_32 -> V_34 ) {
struct V_29 * V_295 ;
F_41 (newmode, &connector->probed_modes,
head) {
if ( V_295 -> type & V_296 ) {
V_32 -> V_34 =
F_97 ( V_21 , V_295 ) ;
break;
}
}
}
return V_83 ;
}
if ( F_1 ( V_1 ) ) {
if ( V_32 -> V_34 != NULL ) {
struct V_29 * V_30 ;
V_30 = F_97 ( V_21 , V_32 -> V_34 ) ;
F_98 ( V_7 , V_30 ) ;
return 1 ;
}
}
return 0 ;
}
static bool
F_99 ( struct V_6 * V_7 )
{
struct V_1 * V_1 = F_5 ( V_7 ) ;
struct V_291 * V_291 ;
bool V_163 = false ;
V_291 = F_92 ( V_7 , & V_1 -> V_97 ) ;
if ( V_291 ) {
V_163 = F_93 ( V_291 ) ;
V_7 -> V_293 . V_294 = NULL ;
F_94 ( V_291 ) ;
}
return V_163 ;
}
static int
F_100 ( struct V_6 * V_7 ,
struct V_297 * V_298 ,
T_5 V_299 )
{
struct V_31 * V_32 = V_7 -> V_21 -> V_33 ;
struct V_1 * V_1 = F_5 ( V_7 ) ;
int V_83 ;
V_83 = F_101 ( V_7 , V_298 , V_299 ) ;
if ( V_83 )
return V_83 ;
if ( V_298 == V_32 -> V_300 ) {
int V_43 = V_299 ;
bool V_163 ;
if ( V_43 == V_1 -> V_292 )
return 0 ;
V_1 -> V_292 = V_43 ;
if ( V_43 == 0 )
V_163 = F_99 ( V_7 ) ;
else
V_163 = V_43 > 0 ;
if ( V_163 == V_1 -> V_163 )
return 0 ;
V_1 -> V_163 = V_163 ;
goto V_301;
}
if ( V_298 == V_32 -> V_302 ) {
if ( V_299 == ! ! V_1 -> V_152 )
return 0 ;
V_1 -> V_152 = V_299 ? V_303 : 0 ;
goto V_301;
}
return - V_304 ;
V_301:
if ( V_1 -> V_2 . V_2 . V_24 ) {
struct V_23 * V_24 = V_1 -> V_2 . V_2 . V_24 ;
F_102 ( V_24 , & V_24 -> V_30 ,
V_24 -> V_305 , V_24 -> V_306 ,
V_24 -> V_307 ) ;
}
return 0 ;
}
static void
F_103 ( struct V_6 * V_7 )
{
struct V_20 * V_21 = V_7 -> V_21 ;
if ( F_104 ( V_21 ) )
F_105 ( V_21 ) ;
F_106 ( V_7 ) ;
F_107 ( V_7 ) ;
F_94 ( V_7 ) ;
}
static void F_108 ( struct V_4 * V_5 )
{
struct V_1 * V_1 = F_3 ( V_5 ) ;
F_109 ( & V_1 -> V_97 ) ;
F_110 ( V_5 ) ;
F_94 ( V_1 ) ;
}
static void
F_111 ( struct V_8 * V_8 )
{
struct V_1 * V_1 = F_4 ( V_8 , struct V_1 , V_2 ) ;
F_85 ( V_1 ) ;
}
int
F_112 ( struct V_23 * V_24 )
{
struct V_20 * V_21 = V_24 -> V_21 ;
struct V_142 * V_143 = & V_21 -> V_143 ;
struct V_4 * V_5 ;
F_41 (encoder, &mode_config->encoder_list, head) {
struct V_1 * V_1 ;
if ( V_5 -> V_24 != V_24 )
continue;
V_1 = F_3 ( V_5 ) ;
if ( V_1 -> V_2 . type == V_145 )
return V_1 -> V_62 ;
}
return - 1 ;
}
bool F_104 ( struct V_20 * V_21 )
{
struct V_31 * V_32 = V_21 -> V_33 ;
struct V_308 * V_309 ;
int V_43 ;
if ( ! V_32 -> V_310 )
return false ;
for ( V_43 = 0 ; V_43 < V_32 -> V_310 ; V_43 ++ ) {
V_309 = V_32 -> V_311 + V_43 ;
if ( V_309 -> V_312 == V_313 &&
V_309 -> V_314 == V_315 )
return true ;
}
return false ;
}
static void
F_113 ( struct V_1 * V_1 , struct V_6 * V_7 )
{
F_114 ( V_7 ) ;
F_115 ( V_7 ) ;
}
void
F_116 ( struct V_20 * V_21 , int V_62 )
{
struct V_31 * V_32 = V_21 -> V_33 ;
struct V_6 * V_7 ;
struct V_1 * V_1 ;
struct V_8 * V_8 ;
struct V_115 * V_115 ;
const char * V_116 = NULL ;
int type ;
V_1 = F_117 ( sizeof( struct V_1 ) , V_316 ) ;
if ( ! V_1 )
return;
V_1 -> V_62 = V_62 ;
V_1 -> V_198 = - 1 ;
V_115 = F_117 ( sizeof( struct V_115 ) , V_316 ) ;
if ( ! V_115 ) {
F_94 ( V_1 ) ;
return;
}
V_8 = & V_1 -> V_2 ;
if ( F_22 ( V_21 ) && V_62 == V_317 )
if ( F_104 ( V_21 ) )
V_1 -> F_2 = true ;
if ( V_62 == V_193 || F_2 ( V_1 ) ) {
type = V_318 ;
V_8 -> type = V_3 ;
} else {
type = V_319 ;
V_8 -> type = V_145 ;
}
V_7 = & V_115 -> V_2 ;
F_118 ( V_21 , V_7 , & V_320 , type ) ;
F_119 ( V_7 , & V_321 ) ;
V_7 -> V_322 = V_323 ;
if ( V_62 == V_283 || V_62 == V_324 )
V_8 -> V_325 = ( 1 << V_326 ) ;
else if ( V_62 == V_285 || V_62 == V_327 )
V_8 -> V_325 = ( 1 << V_328 ) ;
else if ( V_62 == V_287 || V_62 == V_317 )
V_8 -> V_325 = ( 1 << V_329 ) ;
if ( F_1 ( V_1 ) )
V_8 -> V_325 = ( 1 << V_330 ) ;
V_8 -> V_331 = ( 1 << 0 ) | ( 1 << 1 ) ;
V_7 -> V_332 = true ;
V_7 -> V_333 = 0 ;
F_120 ( V_21 , & V_8 -> V_2 , & V_334 ,
V_335 ) ;
F_121 ( & V_8 -> V_2 , & V_336 ) ;
F_122 ( V_115 , V_8 ) ;
F_123 ( V_7 ) ;
switch ( V_62 ) {
case V_193 :
V_116 = L_25 ;
break;
case V_283 :
case V_324 :
V_32 -> V_337 |=
V_338 ;
V_116 = L_26 ;
break;
case V_285 :
case V_327 :
V_32 -> V_337 |=
V_339 ;
V_116 = L_27 ;
break;
case V_287 :
case V_317 :
V_32 -> V_337 |=
V_340 ;
V_116 = L_28 ;
break;
}
F_33 ( V_1 , V_115 , V_116 ) ;
if ( F_1 ( V_1 ) ) {
bool V_83 ;
T_4 V_341 , V_342 ;
V_341 = F_19 ( V_343 ) ;
V_342 = F_19 ( V_344 ) ;
V_32 -> V_178 = ( V_341 & 0x1fff0000 ) >> 16 ;
V_32 -> V_178 /= 10 ;
V_32 -> V_181 = V_342 & 0xf ;
V_32 -> V_181 *= 100 ;
F_52 ( V_1 ) ;
V_83 = F_84 ( V_1 ) ;
F_54 ( V_1 ) ;
if ( V_83 ) {
if ( V_1 -> V_15 [ V_16 ] >= 0x11 )
V_32 -> V_345 =
V_1 -> V_15 [ V_346 ] &
V_347 ;
} else {
F_124 ( L_29 ) ;
F_108 ( & V_1 -> V_2 . V_2 ) ;
F_103 ( & V_115 -> V_2 ) ;
return;
}
}
V_8 -> V_348 = F_111 ;
if ( F_1 ( V_1 ) ) {
if ( V_32 -> V_349 ) {
V_32 -> V_34 =
F_97 ( V_21 , V_32 -> V_349 ) ;
if ( V_32 -> V_34 ) {
V_32 -> V_34 -> type |=
V_296 ;
}
}
V_32 -> V_350 = V_7 ;
F_125 ( V_21 ) ;
}
F_113 ( V_1 , V_7 ) ;
if ( F_126 ( V_21 ) && ! F_127 ( V_21 ) ) {
T_4 V_281 = F_19 ( V_351 ) ;
F_25 ( V_351 , ( V_281 & ~ 0xf ) | 0xd ) ;
}
}
