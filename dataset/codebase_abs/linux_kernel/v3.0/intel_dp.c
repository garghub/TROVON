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
struct V_23 * V_24 = V_21 -> V_25 ;
if ( F_1 ( V_1 ) )
return ( V_22 * V_24 -> V_26 . V_27 + 7 ) / 8 ;
else
return V_22 * 3 ;
}
static int
F_13 ( int V_28 , int V_29 )
{
return ( V_28 * V_29 * 8 ) / 10 ;
}
static int
F_14 ( struct V_6 * V_7 ,
struct V_30 * V_31 )
{
struct V_1 * V_1 = F_5 ( V_7 ) ;
struct V_20 * V_21 = V_7 -> V_21 ;
struct V_23 * V_24 = V_21 -> V_25 ;
int V_28 = F_11 ( F_10 ( V_1 ) ) ;
int V_29 = F_9 ( V_1 ) ;
if ( F_1 ( V_1 ) && V_24 -> V_32 ) {
if ( V_31 -> V_33 > V_24 -> V_32 -> V_33 )
return V_34 ;
if ( V_31 -> V_35 > V_24 -> V_32 -> V_35 )
return V_34 ;
}
if ( ! F_1 ( V_1 ) &&
( F_12 ( V_7 -> V_21 , V_1 , V_31 -> clock )
> F_13 ( V_28 , V_29 ) ) )
return V_36 ;
if ( V_31 -> clock < 10000 )
return V_37 ;
return V_38 ;
}
static T_2
F_15 ( T_1 * V_39 , int V_40 )
{
int V_41 ;
T_2 V_42 = 0 ;
if ( V_40 > 4 )
V_40 = 4 ;
for ( V_41 = 0 ; V_41 < V_40 ; V_41 ++ )
V_42 |= ( ( T_2 ) V_39 [ V_41 ] ) << ( ( 3 - V_41 ) * 8 ) ;
return V_42 ;
}
static void
F_16 ( T_2 V_39 , T_1 * V_43 , int V_44 )
{
int V_41 ;
if ( V_44 > 4 )
V_44 = 4 ;
for ( V_41 = 0 ; V_41 < V_44 ; V_41 ++ )
V_43 [ V_41 ] = V_39 >> ( ( 3 - V_41 ) * 8 ) ;
}
static int
F_17 ( struct V_20 * V_21 )
{
struct V_23 * V_24 = V_21 -> V_25 ;
T_2 V_45 ;
V_45 = F_18 ( V_46 ) ;
switch ( V_45 & V_47 ) {
case V_48 :
return 100 ;
case V_49 :
return 133 ;
case V_50 :
return 166 ;
case V_51 :
return 200 ;
case V_52 :
return 266 ;
case V_53 :
return 333 ;
case V_54 :
case V_55 :
return 400 ;
default:
return 133 ;
}
}
static int
F_19 ( struct V_1 * V_1 ,
T_1 * V_56 , int V_57 ,
T_1 * V_58 , int V_59 )
{
T_2 V_60 = V_1 -> V_60 ;
struct V_20 * V_21 = V_1 -> V_2 . V_2 . V_21 ;
struct V_23 * V_24 = V_21 -> V_25 ;
T_2 V_61 = V_60 + 0x10 ;
T_2 V_62 = V_61 + 4 ;
int V_41 ;
int V_63 ;
T_2 V_64 ;
T_2 V_65 ;
int V_66 , V_67 ;
if ( F_1 ( V_1 ) && ! F_2 ( V_1 ) ) {
if ( F_20 ( V_21 ) )
V_65 = 200 ;
else
V_65 = 225 ;
} else if ( F_21 ( V_21 ) )
V_65 = 62 ;
else
V_65 = F_17 ( V_21 ) / 2 ;
if ( F_20 ( V_21 ) )
V_67 = 3 ;
else
V_67 = 5 ;
if ( F_18 ( V_61 ) & V_68 ) {
F_22 ( L_1 ,
F_18 ( V_61 ) ) ;
return - V_69 ;
}
for ( V_66 = 0 ; V_66 < 5 ; V_66 ++ ) {
for ( V_41 = 0 ; V_41 < V_57 ; V_41 += 4 )
F_23 ( V_62 + V_41 ,
F_15 ( V_56 + V_41 , V_57 - V_41 ) ) ;
F_23 ( V_61 ,
V_68 |
V_70 |
( V_57 << V_71 ) |
( V_67 << V_72 ) |
( V_65 << V_73 ) |
V_74 |
V_75 |
V_76 ) ;
for (; ; ) {
V_64 = F_18 ( V_61 ) ;
if ( ( V_64 & V_68 ) == 0 )
break;
F_24 ( 100 ) ;
}
F_23 ( V_61 ,
V_64 |
V_74 |
V_75 |
V_76 ) ;
if ( V_64 & V_74 )
break;
}
if ( ( V_64 & V_74 ) == 0 ) {
F_22 ( L_2 , V_64 ) ;
return - V_69 ;
}
if ( V_64 & V_76 ) {
F_22 ( L_3 , V_64 ) ;
return - V_77 ;
}
if ( V_64 & V_75 ) {
F_25 ( L_4 , V_64 ) ;
return - V_78 ;
}
V_63 = ( ( V_64 & V_79 ) >>
V_71 ) ;
if ( V_63 > V_59 )
V_63 = V_59 ;
for ( V_41 = 0 ; V_41 < V_63 ; V_41 += 4 )
F_16 ( F_18 ( V_62 + V_41 ) ,
V_58 + V_41 , V_63 - V_41 ) ;
return V_63 ;
}
static int
F_26 ( struct V_1 * V_1 ,
T_3 V_80 , T_1 * V_56 , int V_57 )
{
int V_81 ;
T_1 V_82 [ 20 ] ;
int V_83 ;
T_1 V_84 ;
if ( V_57 > 16 )
return - 1 ;
V_82 [ 0 ] = V_85 << 4 ;
V_82 [ 1 ] = V_80 >> 8 ;
V_82 [ 2 ] = V_80 & 0xff ;
V_82 [ 3 ] = V_57 - 1 ;
memcpy ( & V_82 [ 4 ] , V_56 , V_57 ) ;
V_83 = V_57 + 4 ;
for (; ; ) {
V_81 = F_19 ( V_1 , V_82 , V_83 , & V_84 , 1 ) ;
if ( V_81 < 0 )
return V_81 ;
if ( ( V_84 & V_86 ) == V_87 )
break;
else if ( ( V_84 & V_86 ) == V_88 )
F_24 ( 100 ) ;
else
return - V_77 ;
}
return V_57 ;
}
static int
F_27 ( struct V_1 * V_1 ,
T_3 V_80 , T_1 V_89 )
{
return F_26 ( V_1 , V_80 , & V_89 , 1 ) ;
}
static int
F_28 ( struct V_1 * V_1 ,
T_3 V_80 , T_1 * V_58 , int V_63 )
{
T_1 V_82 [ 4 ] ;
int V_83 ;
T_1 V_90 [ 20 ] ;
int V_91 ;
T_1 V_84 ;
int V_81 ;
V_82 [ 0 ] = V_92 << 4 ;
V_82 [ 1 ] = V_80 >> 8 ;
V_82 [ 2 ] = V_80 & 0xff ;
V_82 [ 3 ] = V_63 - 1 ;
V_83 = 4 ;
V_91 = V_63 + 1 ;
for (; ; ) {
V_81 = F_19 ( V_1 , V_82 , V_83 ,
V_90 , V_91 ) ;
if ( V_81 == 0 )
return - V_93 ;
if ( V_81 < 0 )
return V_81 ;
V_84 = V_90 [ 0 ] ;
if ( ( V_84 & V_86 ) == V_87 ) {
memcpy ( V_58 , V_90 + 1 , V_81 - 1 ) ;
return V_81 - 1 ;
}
else if ( ( V_84 & V_86 ) == V_88 )
F_24 ( 100 ) ;
else
return - V_77 ;
}
}
static int
F_29 ( struct V_94 * V_95 , int V_31 ,
T_1 V_96 , T_1 * V_97 )
{
struct V_98 * V_99 = V_95 -> V_99 ;
struct V_1 * V_1 = F_4 ( V_95 ,
struct V_1 ,
V_95 ) ;
T_3 V_80 = V_99 -> V_80 ;
T_1 V_82 [ 5 ] ;
T_1 V_90 [ 2 ] ;
unsigned V_100 ;
int V_83 ;
int V_91 ;
int V_81 ;
if ( V_31 & V_101 )
V_82 [ 0 ] = V_102 << 4 ;
else
V_82 [ 0 ] = V_103 << 4 ;
if ( ! ( V_31 & V_104 ) )
V_82 [ 0 ] |= V_105 << 4 ;
V_82 [ 1 ] = V_80 >> 8 ;
V_82 [ 2 ] = V_80 ;
switch ( V_31 ) {
case V_106 :
V_82 [ 3 ] = 0 ;
V_82 [ 4 ] = V_96 ;
V_83 = 5 ;
V_91 = 1 ;
break;
case V_101 :
V_82 [ 3 ] = 0 ;
V_83 = 4 ;
V_91 = 2 ;
break;
default:
V_83 = 3 ;
V_91 = 1 ;
break;
}
for ( V_100 = 0 ; V_100 < 5 ; V_100 ++ ) {
V_81 = F_19 ( V_1 ,
V_82 , V_83 ,
V_90 , V_91 ) ;
if ( V_81 < 0 ) {
F_25 ( L_5 , V_81 ) ;
return V_81 ;
}
switch ( V_90 [ 0 ] & V_86 ) {
case V_87 :
break;
case V_107 :
F_25 ( L_6 ) ;
return - V_108 ;
case V_88 :
F_24 ( 100 ) ;
continue;
default:
F_22 ( L_7 ,
V_90 [ 0 ] ) ;
return - V_108 ;
}
switch ( V_90 [ 0 ] & V_109 ) {
case V_110 :
if ( V_31 == V_101 ) {
* V_97 = V_90 [ 1 ] ;
}
return V_91 - 1 ;
case V_111 :
F_25 ( L_8 ) ;
return - V_108 ;
case V_112 :
F_25 ( L_9 ) ;
F_24 ( 100 ) ;
break;
default:
F_22 ( L_10 , V_90 [ 0 ] ) ;
return - V_108 ;
}
}
F_22 ( L_11 ) ;
return - V_108 ;
}
static int
F_30 ( struct V_1 * V_1 ,
struct V_113 * V_113 , const char * V_114 )
{
F_25 ( L_12 , V_114 ) ;
V_1 -> V_115 . V_116 = false ;
V_1 -> V_115 . V_80 = 0 ;
V_1 -> V_115 . V_117 = F_29 ;
memset ( & V_1 -> V_95 , '\0' , sizeof ( V_1 -> V_95 ) ) ;
V_1 -> V_95 . V_118 = V_119 ;
V_1 -> V_95 . V_120 = V_121 ;
strncpy ( V_1 -> V_95 . V_114 , V_114 , sizeof( V_1 -> V_95 . V_114 ) - 1 ) ;
V_1 -> V_95 . V_114 [ sizeof( V_1 -> V_95 . V_114 ) - 1 ] = '\0' ;
V_1 -> V_95 . V_99 = & V_1 -> V_115 ;
V_1 -> V_95 . V_21 . V_122 = & V_113 -> V_2 . V_123 ;
return F_31 ( & V_1 -> V_95 ) ;
}
static bool
F_32 ( struct V_4 * V_5 , struct V_30 * V_31 ,
struct V_30 * V_124 )
{
struct V_20 * V_21 = V_5 -> V_21 ;
struct V_23 * V_24 = V_21 -> V_25 ;
struct V_1 * V_1 = F_3 ( V_5 ) ;
int V_11 , clock ;
int V_14 = F_9 ( V_1 ) ;
int V_125 = F_10 ( V_1 ) == V_13 ? 1 : 0 ;
static int V_126 [ 2 ] = { V_12 , V_13 } ;
if ( F_1 ( V_1 ) && V_24 -> V_32 ) {
F_33 ( V_24 -> V_32 , V_124 ) ;
F_34 ( V_21 , V_127 ,
V_31 , V_124 ) ;
V_31 -> clock = V_24 -> V_32 -> clock ;
}
for ( V_11 = 1 ; V_11 <= V_14 ; V_11 <<= 1 ) {
for ( clock = 0 ; clock <= V_125 ; clock ++ ) {
int V_128 = F_13 ( F_11 ( V_126 [ clock ] ) , V_11 ) ;
if ( F_12 ( V_5 -> V_21 , V_1 , V_31 -> clock )
<= V_128 ) {
V_1 -> V_10 = V_126 [ clock ] ;
V_1 -> V_11 = V_11 ;
V_124 -> clock = F_11 ( V_1 -> V_10 ) ;
F_25 ( L_13
L_14 ,
V_1 -> V_10 , V_1 -> V_11 ,
V_124 -> clock ) ;
return true ;
}
}
}
if ( F_1 ( V_1 ) ) {
V_1 -> V_11 = V_14 ;
V_1 -> V_10 = V_126 [ V_125 ] ;
V_124 -> clock = F_11 ( V_1 -> V_10 ) ;
F_25 ( L_15
L_14 ,
V_1 -> V_10 , V_1 -> V_11 ,
V_124 -> clock ) ;
return true ;
}
return false ;
}
static void
F_35 ( T_2 * V_129 , T_2 * V_130 )
{
while ( * V_129 > 0xffffff || * V_130 > 0xffffff ) {
* V_129 >>= 1 ;
* V_130 >>= 1 ;
}
}
static void
F_36 ( int V_27 ,
int V_131 ,
int V_22 ,
int V_132 ,
struct V_133 * V_134 )
{
V_134 -> V_135 = 64 ;
V_134 -> V_136 = ( V_22 * V_27 ) >> 3 ;
V_134 -> V_137 = V_132 * V_131 ;
F_35 ( & V_134 -> V_136 , & V_134 -> V_137 ) ;
V_134 -> V_138 = V_22 ;
V_134 -> V_139 = V_132 ;
F_35 ( & V_134 -> V_138 , & V_134 -> V_139 ) ;
}
void
F_37 ( struct V_140 * V_141 , struct V_30 * V_31 ,
struct V_30 * V_124 )
{
struct V_20 * V_21 = V_141 -> V_21 ;
struct V_142 * V_143 = & V_21 -> V_143 ;
struct V_4 * V_5 ;
struct V_23 * V_24 = V_21 -> V_25 ;
struct V_144 * V_144 = F_38 ( V_141 ) ;
int V_11 = 4 , V_27 = 24 ;
struct V_133 V_134 ;
int V_145 = V_144 -> V_145 ;
F_39 (encoder, &mode_config->encoder_list, head) {
struct V_1 * V_1 ;
if ( V_5 -> V_141 != V_141 )
continue;
V_1 = F_3 ( V_5 ) ;
if ( V_1 -> V_2 . type == V_146 ) {
V_11 = V_1 -> V_11 ;
break;
} else if ( F_1 ( V_1 ) ) {
V_11 = V_24 -> V_26 . V_147 ;
V_27 = V_24 -> V_26 . V_27 ;
break;
}
}
F_36 ( V_27 , V_11 ,
V_31 -> clock , V_124 -> clock , & V_134 ) ;
if ( F_21 ( V_21 ) ) {
F_23 ( F_40 ( V_145 ) ,
( ( V_134 . V_135 - 1 ) << V_148 ) |
V_134 . V_136 ) ;
F_23 ( F_41 ( V_145 ) , V_134 . V_137 ) ;
F_23 ( F_42 ( V_145 ) , V_134 . V_138 ) ;
F_23 ( F_43 ( V_145 ) , V_134 . V_139 ) ;
} else {
F_23 ( F_44 ( V_145 ) ,
( ( V_134 . V_135 - 1 ) << V_148 ) |
V_134 . V_136 ) ;
F_23 ( F_45 ( V_145 ) , V_134 . V_137 ) ;
F_23 ( F_46 ( V_145 ) , V_134 . V_138 ) ;
F_23 ( F_47 ( V_145 ) , V_134 . V_139 ) ;
}
}
static void
F_48 ( struct V_4 * V_5 , struct V_30 * V_31 ,
struct V_30 * V_124 )
{
struct V_20 * V_21 = V_5 -> V_21 ;
struct V_1 * V_1 = F_3 ( V_5 ) ;
struct V_140 * V_141 = V_1 -> V_2 . V_2 . V_141 ;
struct V_144 * V_144 = F_38 ( V_141 ) ;
V_1 -> V_149 = V_150 | V_151 ;
V_1 -> V_149 |= V_1 -> V_152 ;
if ( V_124 -> V_153 & V_154 )
V_1 -> V_149 |= V_155 ;
if ( V_124 -> V_153 & V_156 )
V_1 -> V_149 |= V_157 ;
if ( F_49 ( V_21 ) && ! F_1 ( V_1 ) )
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
if ( V_1 -> V_15 [ V_16 ] >= 0x11 &&
( V_1 -> V_15 [ V_17 ] & V_167 ) ) {
V_1 -> V_165 [ 1 ] |= V_168 ;
V_1 -> V_149 |= V_169 ;
}
if ( V_144 -> V_145 == 1 && ! F_49 ( V_21 ) )
V_1 -> V_149 |= V_170 ;
if ( F_1 ( V_1 ) && ! F_2 ( V_1 ) ) {
V_1 -> V_149 |= V_171 ;
if ( V_124 -> clock < 200000 )
V_1 -> V_149 |= V_172 ;
else
V_1 -> V_149 |= V_173 ;
}
}
static void F_50 ( struct V_1 * V_1 )
{
struct V_20 * V_21 = V_1 -> V_2 . V_2 . V_21 ;
struct V_23 * V_24 = V_21 -> V_25 ;
T_4 V_174 ;
if ( ! ( F_18 ( V_175 ) & V_176 ) )
F_51 ( V_24 -> V_177 ) ;
V_174 = F_18 ( V_178 ) ;
V_174 |= V_179 ;
F_23 ( V_178 , V_174 ) ;
F_52 ( V_178 ) ;
}
static void F_53 ( struct V_1 * V_1 )
{
struct V_20 * V_21 = V_1 -> V_2 . V_2 . V_21 ;
struct V_23 * V_24 = V_21 -> V_25 ;
T_4 V_174 ;
V_174 = F_18 ( V_178 ) ;
V_174 &= ~ V_179 ;
F_23 ( V_178 , V_174 ) ;
F_52 ( V_178 ) ;
F_51 ( V_24 -> V_180 ) ;
}
static bool F_54 ( struct V_1 * V_1 )
{
struct V_20 * V_21 = V_1 -> V_2 . V_2 . V_21 ;
struct V_23 * V_24 = V_21 -> V_25 ;
T_4 V_174 , V_181 = V_176 | V_182 ;
if ( F_18 ( V_175 ) & V_176 )
return true ;
V_174 = F_18 ( V_178 ) ;
V_174 &= ~ V_183 ;
F_23 ( V_178 , V_174 ) ;
F_52 ( V_178 ) ;
V_174 |= V_184 | V_185 ;
F_23 ( V_178 , V_174 ) ;
F_52 ( V_178 ) ;
if ( F_55 ( ( F_18 ( V_175 ) & V_181 ) == V_181 ,
5000 ) )
F_22 ( L_16 ,
F_18 ( V_175 ) ) ;
V_174 |= V_183 ;
F_23 ( V_178 , V_174 ) ;
F_52 ( V_178 ) ;
return false ;
}
static void F_56 ( struct V_20 * V_21 )
{
struct V_23 * V_24 = V_21 -> V_25 ;
T_4 V_174 , V_186 = V_176 | V_187 |
V_188 | V_189 ;
V_174 = F_18 ( V_178 ) ;
V_174 &= ~ V_183 ;
F_23 ( V_178 , V_174 ) ;
F_52 ( V_178 ) ;
V_174 &= ~ V_185 ;
F_23 ( V_178 , V_174 ) ;
F_52 ( V_178 ) ;
if ( F_55 ( ( F_18 ( V_175 ) & V_186 ) == 0 , 5000 ) )
F_22 ( L_17 ,
F_18 ( V_175 ) ) ;
V_174 |= V_183 ;
F_23 ( V_178 , V_174 ) ;
F_52 ( V_178 ) ;
}
static void F_57 ( struct V_20 * V_21 )
{
struct V_23 * V_24 = V_21 -> V_25 ;
T_4 V_174 ;
F_25 ( L_18 ) ;
F_51 ( 300 ) ;
V_174 = F_18 ( V_178 ) ;
V_174 |= V_190 ;
F_23 ( V_178 , V_174 ) ;
}
static void F_58 ( struct V_20 * V_21 )
{
struct V_23 * V_24 = V_21 -> V_25 ;
T_4 V_174 ;
F_25 ( L_18 ) ;
V_174 = F_18 ( V_178 ) ;
V_174 &= ~ V_190 ;
F_23 ( V_178 , V_174 ) ;
}
static void F_59 ( struct V_4 * V_5 )
{
struct V_20 * V_21 = V_5 -> V_21 ;
struct V_23 * V_24 = V_21 -> V_25 ;
T_4 V_191 ;
F_25 ( L_18 ) ;
V_191 = F_18 ( V_192 ) ;
V_191 |= V_171 ;
F_23 ( V_192 , V_191 ) ;
F_52 ( V_192 ) ;
F_24 ( 200 ) ;
}
static void F_60 ( struct V_4 * V_5 )
{
struct V_20 * V_21 = V_5 -> V_21 ;
struct V_23 * V_24 = V_21 -> V_25 ;
T_4 V_191 ;
V_191 = F_18 ( V_192 ) ;
V_191 &= ~ V_171 ;
F_23 ( V_192 , V_191 ) ;
F_52 ( V_192 ) ;
F_24 ( 200 ) ;
}
static void F_61 ( struct V_1 * V_1 , int V_31 )
{
int V_81 , V_41 ;
if ( V_1 -> V_15 [ V_16 ] < 0x11 )
return;
if ( V_31 != V_193 ) {
V_81 = F_27 ( V_1 , V_194 ,
V_195 ) ;
if ( V_81 != 1 )
F_62 ( L_19 ) ;
} else {
for ( V_41 = 0 ; V_41 < 3 ; V_41 ++ ) {
V_81 = F_27 ( V_1 ,
V_194 ,
V_196 ) ;
if ( V_81 == 1 )
break;
F_51 ( 1 ) ;
}
}
}
static void F_63 ( struct V_4 * V_5 )
{
struct V_1 * V_1 = F_3 ( V_5 ) ;
struct V_20 * V_21 = V_5 -> V_21 ;
F_61 ( V_1 , V_193 ) ;
if ( F_1 ( V_1 ) ) {
F_58 ( V_21 ) ;
F_56 ( V_21 ) ;
if ( ! F_2 ( V_1 ) )
F_59 ( V_5 ) ;
else
F_60 ( V_5 ) ;
}
F_64 ( V_1 ) ;
}
static void F_65 ( struct V_4 * V_5 )
{
struct V_1 * V_1 = F_3 ( V_5 ) ;
struct V_20 * V_21 = V_5 -> V_21 ;
if ( F_1 ( V_1 ) )
F_50 ( V_1 ) ;
F_66 ( V_1 ) ;
if ( F_1 ( V_1 ) ) {
F_54 ( V_1 ) ;
F_53 ( V_1 ) ;
}
F_67 ( V_1 ) ;
if ( F_1 ( V_1 ) )
F_57 ( V_21 ) ;
}
static void
F_68 ( struct V_4 * V_5 , int V_31 )
{
struct V_1 * V_1 = F_3 ( V_5 ) ;
struct V_20 * V_21 = V_5 -> V_21 ;
struct V_23 * V_24 = V_21 -> V_25 ;
T_2 V_197 = F_18 ( V_1 -> V_60 ) ;
if ( V_31 != V_193 ) {
if ( F_1 ( V_1 ) )
F_58 ( V_21 ) ;
F_61 ( V_1 , V_31 ) ;
F_64 ( V_1 ) ;
if ( F_1 ( V_1 ) )
F_56 ( V_21 ) ;
if ( F_1 ( V_1 ) && ! F_2 ( V_1 ) )
F_60 ( V_5 ) ;
} else {
if ( F_1 ( V_1 ) )
F_50 ( V_1 ) ;
F_61 ( V_1 , V_31 ) ;
if ( ! ( V_197 & V_198 ) ) {
F_66 ( V_1 ) ;
if ( F_1 ( V_1 ) ) {
F_54 ( V_1 ) ;
F_53 ( V_1 ) ;
}
F_67 ( V_1 ) ;
}
if ( F_1 ( V_1 ) )
F_57 ( V_21 ) ;
}
}
static bool
F_69 ( struct V_1 * V_1 , T_3 V_80 ,
T_1 * V_58 , int V_63 )
{
int V_81 , V_41 ;
for ( V_41 = 0 ; V_41 < 3 ; V_41 ++ ) {
V_81 = F_28 ( V_1 , V_80 , V_58 ,
V_63 ) ;
if ( V_81 == V_63 )
return true ;
F_51 ( 1 ) ;
}
return false ;
}
static bool
F_70 ( struct V_1 * V_1 )
{
return F_69 ( V_1 ,
V_199 ,
V_1 -> V_200 ,
V_201 ) ;
}
static T_1
F_71 ( T_1 V_200 [ V_201 ] ,
int V_202 )
{
return V_200 [ V_202 - V_199 ] ;
}
static T_1
F_72 ( T_1 V_200 [ V_201 ] ,
int V_203 )
{
int V_41 = V_204 + ( V_203 >> 1 ) ;
int V_205 = ( ( V_203 & 1 ) ?
V_206 :
V_207 ) ;
T_1 V_208 = F_71 ( V_200 , V_41 ) ;
return ( ( V_208 >> V_205 ) & 3 ) << V_209 ;
}
static T_1
F_73 ( T_1 V_200 [ V_201 ] ,
int V_203 )
{
int V_41 = V_204 + ( V_203 >> 1 ) ;
int V_205 = ( ( V_203 & 1 ) ?
V_210 :
V_211 ) ;
T_1 V_208 = F_71 ( V_200 , V_41 ) ;
return ( ( V_208 >> V_205 ) & 3 ) << V_212 ;
}
static T_1
F_74 ( T_1 V_213 )
{
switch ( V_213 & V_214 ) {
case V_215 :
return V_216 ;
case V_217 :
return V_216 ;
case V_218 :
return V_219 ;
case V_220 :
default:
return V_221 ;
}
}
static void
F_75 ( struct V_1 * V_1 )
{
T_1 V_42 = 0 ;
T_1 V_222 = 0 ;
int V_203 ;
for ( V_203 = 0 ; V_203 < V_1 -> V_11 ; V_203 ++ ) {
T_1 V_223 = F_72 ( V_1 -> V_200 , V_203 ) ;
T_1 V_224 = F_73 ( V_1 -> V_200 , V_203 ) ;
if ( V_223 > V_42 )
V_42 = V_223 ;
if ( V_224 > V_222 )
V_222 = V_224 ;
}
if ( V_42 >= V_225 )
V_42 = V_225 | V_226 ;
if ( V_222 >= F_74 ( V_42 ) )
V_222 = F_74 ( V_42 ) | V_227 ;
for ( V_203 = 0 ; V_203 < 4 ; V_203 ++ )
V_1 -> V_228 [ V_203 ] = V_42 | V_222 ;
}
static T_2
F_76 ( T_1 V_228 , int V_11 )
{
T_2 V_229 = 0 ;
switch ( V_228 & V_214 ) {
case V_215 :
default:
V_229 |= V_150 ;
break;
case V_217 :
V_229 |= V_230 ;
break;
case V_218 :
V_229 |= V_231 ;
break;
case V_220 :
V_229 |= V_232 ;
break;
}
switch ( V_228 & V_233 ) {
case V_221 :
default:
V_229 |= V_151 ;
break;
case V_219 :
V_229 |= V_234 ;
break;
case V_216 :
V_229 |= V_235 ;
break;
case V_236 :
V_229 |= V_237 ;
break;
}
return V_229 ;
}
static T_2
F_77 ( T_1 V_228 )
{
int V_229 = V_228 & ( V_214 |
V_233 ) ;
switch ( V_229 ) {
case V_215 | V_221 :
case V_217 | V_221 :
return V_238 ;
case V_215 | V_219 :
return V_239 ;
case V_215 | V_216 :
case V_217 | V_216 :
return V_240 ;
case V_217 | V_219 :
case V_218 | V_219 :
return V_241 ;
case V_218 | V_221 :
case V_220 | V_221 :
return V_242 ;
default:
F_25 ( L_20
L_21 , V_229 ) ;
return V_238 ;
}
}
static T_1
F_78 ( T_1 V_200 [ V_201 ] ,
int V_203 )
{
int V_41 = V_199 + ( V_203 >> 1 ) ;
int V_205 = ( V_203 & 1 ) * 4 ;
T_1 V_208 = F_71 ( V_200 , V_41 ) ;
return ( V_208 >> V_205 ) & 0xf ;
}
static bool
F_79 ( T_1 V_200 [ V_201 ] , int V_11 )
{
int V_203 ;
T_1 V_243 ;
for ( V_203 = 0 ; V_203 < V_11 ; V_203 ++ ) {
V_243 = F_78 ( V_200 , V_203 ) ;
if ( ( V_243 & V_244 ) == 0 )
return false ;
}
return true ;
}
static bool
F_80 ( struct V_1 * V_1 )
{
T_1 V_245 ;
T_1 V_243 ;
int V_203 ;
V_245 = F_71 ( V_1 -> V_200 ,
V_246 ) ;
if ( ( V_245 & V_247 ) == 0 )
return false ;
for ( V_203 = 0 ; V_203 < V_1 -> V_11 ; V_203 ++ ) {
V_243 = F_78 ( V_1 -> V_200 , V_203 ) ;
if ( ( V_243 & V_248 ) != V_248 )
return false ;
}
return true ;
}
static bool
F_81 ( struct V_1 * V_1 ,
T_2 V_249 ,
T_1 V_250 )
{
struct V_20 * V_21 = V_1 -> V_2 . V_2 . V_21 ;
struct V_23 * V_24 = V_21 -> V_25 ;
int V_81 ;
F_23 ( V_1 -> V_60 , V_249 ) ;
F_52 ( V_1 -> V_60 ) ;
F_27 ( V_1 ,
V_251 ,
V_250 ) ;
V_81 = F_26 ( V_1 ,
V_252 ,
V_1 -> V_228 , 4 ) ;
if ( V_81 != 4 )
return false ;
return true ;
}
static void
F_66 ( struct V_1 * V_1 )
{
struct V_20 * V_21 = V_1 -> V_2 . V_2 . V_21 ;
struct V_23 * V_24 = V_21 -> V_25 ;
struct V_144 * V_144 = F_38 ( V_1 -> V_2 . V_2 . V_141 ) ;
int V_41 ;
T_1 V_253 ;
bool V_254 = false ;
int V_255 ;
T_4 V_256 ;
T_2 V_149 = V_1 -> V_149 ;
F_23 ( V_1 -> V_60 , V_1 -> V_149 ) ;
F_52 ( V_1 -> V_60 ) ;
F_82 ( V_21 , V_144 -> V_145 ) ;
F_26 ( V_1 , V_257 ,
V_1 -> V_165 ,
V_166 ) ;
V_149 |= V_198 ;
if ( F_49 ( V_21 ) && ! F_1 ( V_1 ) )
V_149 &= ~ V_258 ;
else
V_149 &= ~ V_259 ;
memset ( V_1 -> V_228 , 0 , 4 ) ;
V_253 = 0xff ;
V_255 = 0 ;
V_254 = false ;
for (; ; ) {
T_2 V_229 ;
if ( F_20 ( V_21 ) && F_1 ( V_1 ) ) {
V_229 = F_77 ( V_1 -> V_228 [ 0 ] ) ;
V_149 = ( V_149 & ~ V_260 ) | V_229 ;
} else {
V_229 = F_76 ( V_1 -> V_228 [ 0 ] , V_1 -> V_11 ) ;
V_149 = ( V_149 & ~ ( V_261 | V_262 ) ) | V_229 ;
}
if ( F_49 ( V_21 ) && ! F_1 ( V_1 ) )
V_256 = V_149 | V_263 ;
else
V_256 = V_149 | V_264 ;
if ( ! F_81 ( V_1 , V_256 ,
V_265 ) )
break;
F_24 ( 100 ) ;
if ( ! F_70 ( V_1 ) )
break;
if ( F_79 ( V_1 -> V_200 , V_1 -> V_11 ) ) {
V_254 = true ;
break;
}
for ( V_41 = 0 ; V_41 < V_1 -> V_11 ; V_41 ++ )
if ( ( V_1 -> V_228 [ V_41 ] & V_226 ) == 0 )
break;
if ( V_41 == V_1 -> V_11 )
break;
if ( ( V_1 -> V_228 [ 0 ] & V_214 ) == V_253 ) {
++ V_255 ;
if ( V_255 == 5 )
break;
} else
V_255 = 0 ;
V_253 = V_1 -> V_228 [ 0 ] & V_214 ;
F_75 ( V_1 ) ;
}
V_1 -> V_149 = V_149 ;
}
static void
F_67 ( struct V_1 * V_1 )
{
struct V_20 * V_21 = V_1 -> V_2 . V_2 . V_21 ;
struct V_23 * V_24 = V_21 -> V_25 ;
bool V_266 = false ;
int V_255 , V_267 ;
T_4 V_256 ;
T_2 V_149 = V_1 -> V_149 ;
V_255 = 0 ;
V_267 = 0 ;
V_266 = false ;
for (; ; ) {
T_2 V_229 ;
if ( V_267 > 5 ) {
F_22 ( L_22 ) ;
F_64 ( V_1 ) ;
break;
}
if ( F_20 ( V_21 ) && F_1 ( V_1 ) ) {
V_229 = F_77 ( V_1 -> V_228 [ 0 ] ) ;
V_149 = ( V_149 & ~ V_260 ) | V_229 ;
} else {
V_229 = F_76 ( V_1 -> V_228 [ 0 ] , V_1 -> V_11 ) ;
V_149 = ( V_149 & ~ ( V_261 | V_262 ) ) | V_229 ;
}
if ( F_49 ( V_21 ) && ! F_1 ( V_1 ) )
V_256 = V_149 | V_268 ;
else
V_256 = V_149 | V_269 ;
if ( ! F_81 ( V_1 , V_256 ,
V_270 ) )
break;
F_24 ( 400 ) ;
if ( ! F_70 ( V_1 ) )
break;
if ( ! F_79 ( V_1 -> V_200 , V_1 -> V_11 ) ) {
F_66 ( V_1 ) ;
V_267 ++ ;
continue;
}
if ( F_80 ( V_1 ) ) {
V_266 = true ;
break;
}
if ( V_255 > 5 ) {
F_64 ( V_1 ) ;
F_66 ( V_1 ) ;
V_255 = 0 ;
V_267 ++ ;
continue;
}
F_75 ( V_1 ) ;
++ V_255 ;
}
if ( F_49 ( V_21 ) && ! F_1 ( V_1 ) )
V_256 = V_149 | V_158 ;
else
V_256 = V_149 | V_159 ;
F_23 ( V_1 -> V_60 , V_256 ) ;
F_52 ( V_1 -> V_60 ) ;
F_27 ( V_1 ,
V_251 , V_271 ) ;
}
static void
F_64 ( struct V_1 * V_1 )
{
struct V_20 * V_21 = V_1 -> V_2 . V_2 . V_21 ;
struct V_23 * V_24 = V_21 -> V_25 ;
T_2 V_149 = V_1 -> V_149 ;
if ( ( F_18 ( V_1 -> V_60 ) & V_198 ) == 0 )
return;
F_25 ( L_18 ) ;
if ( F_1 ( V_1 ) ) {
V_149 &= ~ V_171 ;
F_23 ( V_1 -> V_60 , V_149 ) ;
F_52 ( V_1 -> V_60 ) ;
F_24 ( 100 ) ;
}
if ( F_49 ( V_21 ) && ! F_1 ( V_1 ) ) {
V_149 &= ~ V_258 ;
F_23 ( V_1 -> V_60 , V_149 | V_272 ) ;
} else {
V_149 &= ~ V_259 ;
F_23 ( V_1 -> V_60 , V_149 | V_273 ) ;
}
F_52 ( V_1 -> V_60 ) ;
F_51 ( 17 ) ;
if ( F_1 ( V_1 ) )
V_149 |= V_159 ;
if ( ! F_49 ( V_21 ) &&
F_18 ( V_1 -> V_60 ) & V_170 ) {
struct V_140 * V_141 = V_1 -> V_2 . V_2 . V_141 ;
V_149 &= ~ V_170 ;
F_23 ( V_1 -> V_60 , V_149 ) ;
if ( V_141 == NULL ) {
F_52 ( V_1 -> V_60 ) ;
F_51 ( 50 ) ;
} else
F_82 ( V_21 , F_38 ( V_141 ) -> V_145 ) ;
}
F_23 ( V_1 -> V_60 , V_149 & ~ V_198 ) ;
F_52 ( V_1 -> V_60 ) ;
}
static void
F_83 ( struct V_1 * V_1 )
{
int V_81 ;
if ( ! V_1 -> V_2 . V_2 . V_141 )
return;
if ( ! F_70 ( V_1 ) ) {
F_64 ( V_1 ) ;
return;
}
V_81 = F_28 ( V_1 ,
0x000 , V_1 -> V_15 ,
sizeof ( V_1 -> V_15 ) ) ;
if ( V_81 != sizeof( V_1 -> V_15 ) ) {
F_64 ( V_1 ) ;
return;
}
if ( ! F_80 ( V_1 ) ) {
F_66 ( V_1 ) ;
F_67 ( V_1 ) ;
}
}
static enum V_274
F_84 ( struct V_1 * V_1 )
{
enum V_274 V_64 ;
bool V_81 ;
if ( F_1 ( V_1 ) ) {
V_64 = F_85 ( V_1 -> V_2 . V_2 . V_21 ) ;
if ( V_64 == V_275 )
V_64 = V_276 ;
return V_64 ;
}
V_64 = V_277 ;
V_81 = F_69 ( V_1 ,
0x000 , V_1 -> V_15 ,
sizeof ( V_1 -> V_15 ) ) ;
if ( V_81 && V_1 -> V_15 [ V_16 ] != 0 )
V_64 = V_276 ;
F_25 ( L_23 , V_1 -> V_15 [ 0 ] ,
V_1 -> V_15 [ 1 ] , V_1 -> V_15 [ 2 ] , V_1 -> V_15 [ 3 ] ) ;
return V_64 ;
}
static enum V_274
F_86 ( struct V_1 * V_1 )
{
struct V_20 * V_21 = V_1 -> V_2 . V_2 . V_21 ;
struct V_23 * V_24 = V_21 -> V_25 ;
enum V_274 V_64 ;
T_2 V_278 , V_279 ;
switch ( V_1 -> V_60 ) {
case V_280 :
V_279 = V_281 ;
break;
case V_282 :
V_279 = V_283 ;
break;
case V_284 :
V_279 = V_285 ;
break;
default:
return V_275 ;
}
V_278 = F_18 ( V_286 ) ;
if ( ( V_278 & V_279 ) == 0 )
return V_277 ;
V_64 = V_277 ;
if ( F_28 ( V_1 , 0x000 , V_1 -> V_15 ,
sizeof ( V_1 -> V_15 ) ) == sizeof ( V_1 -> V_15 ) )
{
if ( V_1 -> V_15 [ V_16 ] != 0 )
V_64 = V_276 ;
}
return V_64 ;
}
static enum V_274
F_87 ( struct V_6 * V_7 , bool V_287 )
{
struct V_1 * V_1 = F_5 ( V_7 ) ;
struct V_20 * V_21 = V_1 -> V_2 . V_2 . V_21 ;
enum V_274 V_64 ;
struct V_288 * V_288 = NULL ;
V_1 -> V_163 = false ;
if ( F_21 ( V_21 ) )
V_64 = F_84 ( V_1 ) ;
else
V_64 = F_86 ( V_1 ) ;
if ( V_64 != V_276 )
return V_64 ;
if ( V_1 -> V_289 ) {
V_1 -> V_163 = V_1 -> V_289 > 0 ;
} else {
V_288 = F_88 ( V_7 , & V_1 -> V_95 ) ;
if ( V_288 ) {
V_1 -> V_163 = F_89 ( V_288 ) ;
V_7 -> V_290 . V_291 = NULL ;
F_90 ( V_288 ) ;
}
}
return V_276 ;
}
static int F_91 ( struct V_6 * V_7 )
{
struct V_1 * V_1 = F_5 ( V_7 ) ;
struct V_20 * V_21 = V_1 -> V_2 . V_2 . V_21 ;
struct V_23 * V_24 = V_21 -> V_25 ;
int V_81 ;
V_81 = F_92 ( V_7 , & V_1 -> V_95 ) ;
if ( V_81 ) {
if ( F_1 ( V_1 ) && ! V_24 -> V_32 ) {
struct V_30 * V_292 ;
F_39 (newmode, &connector->probed_modes,
head) {
if ( V_292 -> type & V_293 ) {
V_24 -> V_32 =
F_93 ( V_21 , V_292 ) ;
break;
}
}
}
return V_81 ;
}
if ( F_1 ( V_1 ) ) {
if ( V_24 -> V_32 != NULL ) {
struct V_30 * V_31 ;
V_31 = F_93 ( V_21 , V_24 -> V_32 ) ;
F_94 ( V_7 , V_31 ) ;
return 1 ;
}
}
return 0 ;
}
static bool
F_95 ( struct V_6 * V_7 )
{
struct V_1 * V_1 = F_5 ( V_7 ) ;
struct V_288 * V_288 ;
bool V_163 = false ;
V_288 = F_88 ( V_7 , & V_1 -> V_95 ) ;
if ( V_288 ) {
V_163 = F_89 ( V_288 ) ;
V_7 -> V_290 . V_291 = NULL ;
F_90 ( V_288 ) ;
}
return V_163 ;
}
static int
F_96 ( struct V_6 * V_7 ,
struct V_294 * V_295 ,
T_5 V_296 )
{
struct V_23 * V_24 = V_7 -> V_21 -> V_25 ;
struct V_1 * V_1 = F_5 ( V_7 ) ;
int V_81 ;
V_81 = F_97 ( V_7 , V_295 , V_296 ) ;
if ( V_81 )
return V_81 ;
if ( V_295 == V_24 -> V_297 ) {
int V_41 = V_296 ;
bool V_163 ;
if ( V_41 == V_1 -> V_289 )
return 0 ;
V_1 -> V_289 = V_41 ;
if ( V_41 == 0 )
V_163 = F_95 ( V_7 ) ;
else
V_163 = V_41 > 0 ;
if ( V_163 == V_1 -> V_163 )
return 0 ;
V_1 -> V_163 = V_163 ;
goto V_298;
}
if ( V_295 == V_24 -> V_299 ) {
if ( V_296 == ! ! V_1 -> V_152 )
return 0 ;
V_1 -> V_152 = V_296 ? V_300 : 0 ;
goto V_298;
}
return - V_301 ;
V_298:
if ( V_1 -> V_2 . V_2 . V_141 ) {
struct V_140 * V_141 = V_1 -> V_2 . V_2 . V_141 ;
F_98 ( V_141 , & V_141 -> V_31 ,
V_141 -> V_302 , V_141 -> V_303 ,
V_141 -> V_304 ) ;
}
return 0 ;
}
static void
F_99 ( struct V_6 * V_7 )
{
F_100 ( V_7 ) ;
F_101 ( V_7 ) ;
F_90 ( V_7 ) ;
}
static void F_102 ( struct V_4 * V_5 )
{
struct V_1 * V_1 = F_3 ( V_5 ) ;
F_103 ( & V_1 -> V_95 ) ;
F_104 ( V_5 ) ;
F_90 ( V_1 ) ;
}
static void
F_105 ( struct V_8 * V_8 )
{
struct V_1 * V_1 = F_4 ( V_8 , struct V_1 , V_2 ) ;
F_83 ( V_1 ) ;
}
int
F_106 ( struct V_140 * V_141 )
{
struct V_20 * V_21 = V_141 -> V_21 ;
struct V_142 * V_143 = & V_21 -> V_143 ;
struct V_4 * V_5 ;
F_39 (encoder, &mode_config->encoder_list, head) {
struct V_1 * V_1 ;
if ( V_5 -> V_141 != V_141 )
continue;
V_1 = F_3 ( V_5 ) ;
if ( V_1 -> V_2 . type == V_146 )
return V_1 -> V_60 ;
}
return - 1 ;
}
bool F_107 ( struct V_20 * V_21 )
{
struct V_23 * V_24 = V_21 -> V_25 ;
struct V_305 * V_306 ;
int V_41 ;
if ( ! V_24 -> V_307 )
return false ;
for ( V_41 = 0 ; V_41 < V_24 -> V_307 ; V_41 ++ ) {
V_306 = V_24 -> V_308 + V_41 ;
if ( V_306 -> V_309 == V_310 &&
V_306 -> V_311 == V_312 )
return true ;
}
return false ;
}
static void
F_108 ( struct V_1 * V_1 , struct V_6 * V_7 )
{
F_109 ( V_7 ) ;
F_110 ( V_7 ) ;
}
void
F_111 ( struct V_20 * V_21 , int V_60 )
{
struct V_23 * V_24 = V_21 -> V_25 ;
struct V_6 * V_7 ;
struct V_1 * V_1 ;
struct V_8 * V_8 ;
struct V_113 * V_113 ;
const char * V_114 = NULL ;
int type ;
V_1 = F_112 ( sizeof( struct V_1 ) , V_313 ) ;
if ( ! V_1 )
return;
V_1 -> V_60 = V_60 ;
V_113 = F_112 ( sizeof( struct V_113 ) , V_313 ) ;
if ( ! V_113 ) {
F_90 ( V_1 ) ;
return;
}
V_8 = & V_1 -> V_2 ;
if ( F_21 ( V_21 ) && V_60 == V_314 )
if ( F_107 ( V_21 ) )
V_1 -> F_2 = true ;
if ( V_60 == V_192 || F_2 ( V_1 ) ) {
type = V_315 ;
V_8 -> type = V_3 ;
} else {
type = V_316 ;
V_8 -> type = V_146 ;
}
V_7 = & V_113 -> V_2 ;
F_113 ( V_21 , V_7 , & V_317 , type ) ;
F_114 ( V_7 , & V_318 ) ;
V_7 -> V_319 = V_320 ;
if ( V_60 == V_280 || V_60 == V_321 )
V_8 -> V_322 = ( 1 << V_323 ) ;
else if ( V_60 == V_282 || V_60 == V_324 )
V_8 -> V_322 = ( 1 << V_325 ) ;
else if ( V_60 == V_284 || V_60 == V_314 )
V_8 -> V_322 = ( 1 << V_326 ) ;
if ( F_1 ( V_1 ) )
V_8 -> V_322 = ( 1 << V_327 ) ;
V_8 -> V_328 = ( 1 << 0 ) | ( 1 << 1 ) ;
V_7 -> V_329 = true ;
V_7 -> V_330 = 0 ;
F_115 ( V_21 , & V_8 -> V_2 , & V_331 ,
V_332 ) ;
F_116 ( & V_8 -> V_2 , & V_333 ) ;
F_117 ( V_113 , V_8 ) ;
F_118 ( V_7 ) ;
switch ( V_60 ) {
case V_192 :
V_114 = L_24 ;
break;
case V_280 :
case V_321 :
V_24 -> V_334 |=
V_335 ;
V_114 = L_25 ;
break;
case V_282 :
case V_324 :
V_24 -> V_334 |=
V_336 ;
V_114 = L_26 ;
break;
case V_284 :
case V_314 :
V_24 -> V_334 |=
V_337 ;
V_114 = L_27 ;
break;
}
F_30 ( V_1 , V_113 , V_114 ) ;
if ( F_1 ( V_1 ) ) {
int V_81 ;
T_4 V_338 , V_339 ;
V_338 = F_18 ( V_340 ) ;
V_339 = F_18 ( V_341 ) ;
V_24 -> V_177 = ( V_338 & 0x1fff0000 ) >> 16 ;
V_24 -> V_177 /= 10 ;
V_24 -> V_180 = V_339 & 0xf ;
V_24 -> V_180 *= 100 ;
F_50 ( V_1 ) ;
V_81 = F_28 ( V_1 , V_16 ,
V_1 -> V_15 ,
sizeof( V_1 -> V_15 ) ) ;
F_53 ( V_1 ) ;
if ( V_81 == sizeof( V_1 -> V_15 ) ) {
if ( V_1 -> V_15 [ V_16 ] >= 0x11 )
V_24 -> V_342 =
V_1 -> V_15 [ V_343 ] &
V_344 ;
} else {
F_119 ( L_28 ) ;
F_102 ( & V_1 -> V_2 . V_2 ) ;
F_99 ( & V_113 -> V_2 ) ;
return;
}
}
V_8 -> V_345 = F_105 ;
if ( F_1 ( V_1 ) ) {
if ( V_24 -> V_346 ) {
V_24 -> V_32 =
F_93 ( V_21 , V_24 -> V_346 ) ;
if ( V_24 -> V_32 ) {
V_24 -> V_32 -> type |=
V_293 ;
}
}
}
F_108 ( V_1 , V_7 ) ;
if ( F_120 ( V_21 ) && ! F_121 ( V_21 ) ) {
T_4 V_278 = F_18 ( V_347 ) ;
F_23 ( V_347 , ( V_278 & ~ 0xf ) | 0xd ) ;
}
}
