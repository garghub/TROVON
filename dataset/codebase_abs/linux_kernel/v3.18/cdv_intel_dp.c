static bool F_1 ( struct V_1 * V_2 )
{
return V_2 -> type == V_3 ;
}
static int
F_2 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
int V_7 = 4 ;
if ( V_5 -> V_8 [ V_9 ] >= 0x11 ) {
V_7 = V_5 -> V_8 [ V_10 ] & 0x1f ;
switch ( V_7 ) {
case 1 : case 2 : case 4 :
break;
default:
V_7 = 4 ;
}
}
return V_7 ;
}
static int
F_3 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
int V_11 = V_5 -> V_8 [ V_12 ] ;
switch ( V_11 ) {
case V_13 :
case V_14 :
break;
default:
V_11 = V_13 ;
break;
}
return V_11 ;
}
static int
F_4 ( T_1 V_15 )
{
if ( V_15 == V_14 )
return 270000 ;
else
return 162000 ;
}
static int
F_5 ( int V_16 , int V_17 )
{
return ( V_16 * V_17 + 7 ) / 8 ;
}
static int
F_6 ( int V_18 , int V_19 )
{
return ( V_18 * V_19 * 19 ) / 20 ;
}
static void F_7 ( struct V_1 * V_20 )
{
struct V_21 * V_22 = V_20 -> V_23 . V_22 ;
struct V_4 * V_5 = V_20 -> V_6 ;
T_2 V_24 ;
if ( V_5 -> V_25 ) {
F_8 ( L_1 ) ;
return;
}
F_8 ( L_2 ) ;
V_24 = F_9 ( V_26 ) ;
V_24 |= V_27 ;
F_10 ( V_26 , V_24 ) ;
F_9 ( V_26 ) ;
F_11 ( V_5 -> V_28 ) ;
}
static void F_12 ( struct V_1 * V_20 )
{
struct V_21 * V_22 = V_20 -> V_23 . V_22 ;
T_2 V_24 ;
F_8 ( L_2 ) ;
V_24 = F_9 ( V_26 ) ;
V_24 &= ~ V_27 ;
F_10 ( V_26 , V_24 ) ;
F_9 ( V_26 ) ;
}
static bool F_13 ( struct V_1 * V_20 )
{
struct V_21 * V_22 = V_20 -> V_23 . V_22 ;
struct V_4 * V_5 = V_20 -> V_6 ;
T_2 V_24 , V_29 = V_30 | V_31 ;
if ( V_5 -> V_25 )
return true ;
F_8 ( L_2 ) ;
V_24 = F_9 ( V_26 ) ;
V_24 &= ~ V_32 ;
V_24 |= ( V_33 | V_34 ) ;
F_10 ( V_26 , V_24 ) ;
F_9 ( V_26 ) ;
if ( F_14 ( ( ( F_9 ( V_35 ) & V_29 ) == V_29 ) , 1000 ) ) {
F_8 ( L_3 , F_9 ( V_35 ) ) ;
V_5 -> V_25 = false ;
} else
V_5 -> V_25 = true ;
F_11 ( V_5 -> V_28 ) ;
return false ;
}
static void F_15 ( struct V_1 * V_20 )
{
struct V_21 * V_22 = V_20 -> V_23 . V_22 ;
T_2 V_24 , V_36 = V_30 ;
struct V_4 * V_5 = V_20 -> V_6 ;
F_8 ( L_2 ) ;
V_24 = F_9 ( V_26 ) ;
if ( ( V_24 & V_34 ) == 0 )
return;
V_5 -> V_25 = false ;
V_24 &= ~ V_32 ;
V_24 &= ~ V_34 ;
V_24 &= ~ V_27 ;
V_24 &= ~ V_37 ;
F_10 ( V_26 , V_24 ) ;
F_9 ( V_26 ) ;
F_8 ( L_4 , F_9 ( V_35 ) ) ;
if ( F_14 ( ( F_9 ( V_35 ) & V_36 ) == 0 , 1000 ) ) {
F_8 ( L_5 ) ;
}
F_11 ( V_5 -> V_38 ) ;
F_8 ( L_6 ) ;
}
static void F_16 ( struct V_1 * V_20 )
{
struct V_21 * V_22 = V_20 -> V_23 . V_22 ;
T_2 V_24 ;
F_8 ( L_2 ) ;
F_11 ( 300 ) ;
V_24 = F_9 ( V_26 ) ;
V_24 |= V_37 ;
F_10 ( V_26 , V_24 ) ;
F_17 ( V_22 ) ;
}
static void F_18 ( struct V_1 * V_20 )
{
struct V_21 * V_22 = V_20 -> V_23 . V_22 ;
struct V_4 * V_5 = V_20 -> V_6 ;
T_2 V_24 ;
F_8 ( L_2 ) ;
F_19 ( V_22 ) ;
F_11 ( 10 ) ;
V_24 = F_9 ( V_26 ) ;
V_24 &= ~ V_37 ;
F_10 ( V_26 , V_24 ) ;
F_11 ( V_5 -> V_39 ) ;
}
static int
F_20 ( struct V_40 * V_41 ,
struct V_42 * V_43 )
{
struct V_1 * V_2 = F_21 ( V_41 ) ;
struct V_4 * V_5 = V_2 -> V_6 ;
int V_18 = F_4 ( F_3 ( V_2 ) ) ;
int V_19 = F_2 ( V_2 ) ;
struct V_44 * V_6 = V_41 -> V_22 -> V_45 ;
if ( F_1 ( V_2 ) && V_5 -> V_46 ) {
if ( V_43 -> V_47 > V_5 -> V_46 -> V_47 )
return V_48 ;
if ( V_43 -> V_49 > V_5 -> V_46 -> V_49 )
return V_48 ;
}
if ( ! F_1 ( V_2 ) &&
( F_5 ( V_43 -> clock , V_6 -> V_50 . V_17 )
> F_6 ( V_18 , V_19 ) ) )
return V_51 ;
if ( F_1 ( V_2 ) ) {
if ( F_5 ( V_43 -> clock , 24 )
> F_6 ( V_18 , V_19 ) )
return V_51 ;
}
if ( V_43 -> clock < 10000 )
return V_52 ;
return V_53 ;
}
static T_3
F_22 ( T_1 * V_54 , int V_55 )
{
int V_56 ;
T_3 V_57 = 0 ;
if ( V_55 > 4 )
V_55 = 4 ;
for ( V_56 = 0 ; V_56 < V_55 ; V_56 ++ )
V_57 |= ( ( T_3 ) V_54 [ V_56 ] ) << ( ( 3 - V_56 ) * 8 ) ;
return V_57 ;
}
static void
F_23 ( T_3 V_54 , T_1 * V_58 , int V_59 )
{
int V_56 ;
if ( V_59 > 4 )
V_59 = 4 ;
for ( V_56 = 0 ; V_56 < V_59 ; V_56 ++ )
V_58 [ V_56 ] = V_54 >> ( ( 3 - V_56 ) * 8 ) ;
}
static int
F_24 ( struct V_1 * V_2 ,
T_1 * V_60 , int V_61 ,
T_1 * V_62 , int V_63 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
T_3 V_64 = V_5 -> V_64 ;
struct V_21 * V_22 = V_2 -> V_23 . V_22 ;
T_3 V_65 = V_64 + 0x10 ;
T_3 V_66 = V_65 + 4 ;
int V_56 ;
int V_67 ;
T_3 V_68 ;
T_3 V_69 ;
int V_70 , V_71 ;
V_69 = 200 / 2 ;
V_71 = 4 ;
if ( F_1 ( V_2 ) )
V_71 = 10 ;
if ( F_9 ( V_65 ) & V_72 ) {
F_25 ( L_7 ,
F_9 ( V_65 ) ) ;
return - V_73 ;
}
for ( V_70 = 0 ; V_70 < 5 ; V_70 ++ ) {
for ( V_56 = 0 ; V_56 < V_61 ; V_56 += 4 )
F_10 ( V_66 + V_56 ,
F_22 ( V_60 + V_56 , V_61 - V_56 ) ) ;
F_10 ( V_65 ,
V_72 |
V_74 |
( V_61 << V_75 ) |
( V_71 << V_76 ) |
( V_69 << V_77 ) |
V_78 |
V_79 |
V_80 ) ;
for (; ; ) {
V_68 = F_9 ( V_65 ) ;
if ( ( V_68 & V_72 ) == 0 )
break;
F_26 ( 100 ) ;
}
F_10 ( V_65 ,
V_68 |
V_78 |
V_79 |
V_80 ) ;
if ( V_68 & V_78 )
break;
}
if ( ( V_68 & V_78 ) == 0 ) {
F_25 ( L_8 , V_68 ) ;
return - V_73 ;
}
if ( V_68 & V_80 ) {
F_25 ( L_9 , V_68 ) ;
return - V_81 ;
}
if ( V_68 & V_79 ) {
F_8 ( L_10 , V_68 ) ;
return - V_82 ;
}
V_67 = ( ( V_68 & V_83 ) >>
V_75 ) ;
if ( V_67 > V_63 )
V_67 = V_63 ;
for ( V_56 = 0 ; V_56 < V_67 ; V_56 += 4 )
F_23 ( F_9 ( V_66 + V_56 ) ,
V_62 + V_56 , V_67 - V_56 ) ;
return V_67 ;
}
static int
F_27 ( struct V_1 * V_2 ,
T_4 V_84 , T_1 * V_60 , int V_61 )
{
int V_85 ;
T_1 V_86 [ 20 ] ;
int V_87 ;
T_1 V_88 ;
if ( V_61 > 16 )
return - 1 ;
V_86 [ 0 ] = V_89 << 4 ;
V_86 [ 1 ] = V_84 >> 8 ;
V_86 [ 2 ] = V_84 & 0xff ;
V_86 [ 3 ] = V_61 - 1 ;
memcpy ( & V_86 [ 4 ] , V_60 , V_61 ) ;
V_87 = V_61 + 4 ;
for (; ; ) {
V_85 = F_24 ( V_2 , V_86 , V_87 , & V_88 , 1 ) ;
if ( V_85 < 0 )
return V_85 ;
V_88 >>= 4 ;
if ( ( V_88 & V_90 ) == V_91 )
break;
else if ( ( V_88 & V_90 ) == V_92 )
F_26 ( 100 ) ;
else
return - V_81 ;
}
return V_61 ;
}
static int
F_28 ( struct V_1 * V_2 ,
T_4 V_84 , T_1 V_93 )
{
return F_27 ( V_2 , V_84 , & V_93 , 1 ) ;
}
static int
F_29 ( struct V_1 * V_2 ,
T_4 V_84 , T_1 * V_62 , int V_67 )
{
T_1 V_86 [ 4 ] ;
int V_87 ;
T_1 V_94 [ 20 ] ;
int V_95 ;
T_1 V_88 ;
int V_85 ;
V_86 [ 0 ] = V_96 << 4 ;
V_86 [ 1 ] = V_84 >> 8 ;
V_86 [ 2 ] = V_84 & 0xff ;
V_86 [ 3 ] = V_67 - 1 ;
V_87 = 4 ;
V_95 = V_67 + 1 ;
for (; ; ) {
V_85 = F_24 ( V_2 , V_86 , V_87 ,
V_94 , V_95 ) ;
if ( V_85 == 0 )
return - V_97 ;
if ( V_85 < 0 )
return V_85 ;
V_88 = V_94 [ 0 ] >> 4 ;
if ( ( V_88 & V_90 ) == V_91 ) {
memcpy ( V_62 , V_94 + 1 , V_85 - 1 ) ;
return V_85 - 1 ;
}
else if ( ( V_88 & V_90 ) == V_92 )
F_26 ( 100 ) ;
else
return - V_81 ;
}
}
static int
F_30 ( struct V_98 * V_99 , int V_43 ,
T_1 V_100 , T_1 * V_101 )
{
struct V_102 * V_103 = V_99 -> V_103 ;
struct V_4 * V_5 = F_31 ( V_99 ,
struct V_4 ,
V_99 ) ;
struct V_1 * V_2 = V_5 -> V_2 ;
T_4 V_84 = V_103 -> V_84 ;
T_1 V_86 [ 5 ] ;
T_1 V_94 [ 2 ] ;
unsigned V_104 ;
int V_87 ;
int V_95 ;
int V_85 ;
if ( V_43 & V_105 )
V_86 [ 0 ] = V_106 << 4 ;
else
V_86 [ 0 ] = V_107 << 4 ;
if ( ! ( V_43 & V_108 ) )
V_86 [ 0 ] |= V_109 << 4 ;
V_86 [ 1 ] = V_84 >> 8 ;
V_86 [ 2 ] = V_84 ;
switch ( V_43 ) {
case V_110 :
V_86 [ 3 ] = 0 ;
V_86 [ 4 ] = V_100 ;
V_87 = 5 ;
V_95 = 1 ;
break;
case V_105 :
V_86 [ 3 ] = 0 ;
V_87 = 4 ;
V_95 = 2 ;
break;
default:
V_87 = 3 ;
V_95 = 1 ;
break;
}
for ( V_104 = 0 ; V_104 < 5 ; V_104 ++ ) {
V_85 = F_24 ( V_2 ,
V_86 , V_87 ,
V_94 , V_95 ) ;
if ( V_85 < 0 ) {
F_8 ( L_11 , V_85 ) ;
return V_85 ;
}
switch ( ( V_94 [ 0 ] >> 4 ) & V_90 ) {
case V_91 :
break;
case V_111 :
F_8 ( L_12 ) ;
return - V_112 ;
case V_92 :
F_26 ( 100 ) ;
continue;
default:
F_25 ( L_13 ,
V_94 [ 0 ] ) ;
return - V_112 ;
}
switch ( ( V_94 [ 0 ] >> 4 ) & V_113 ) {
case V_114 :
if ( V_43 == V_105 ) {
* V_101 = V_94 [ 1 ] ;
}
return V_95 - 1 ;
case V_115 :
F_8 ( L_14 ) ;
return - V_112 ;
case V_116 :
F_8 ( L_15 ) ;
F_26 ( 100 ) ;
break;
default:
F_25 ( L_16 , V_94 [ 0 ] ) ;
return - V_112 ;
}
}
F_25 ( L_17 ) ;
return - V_112 ;
}
static int
F_32 ( struct V_117 * V_41 ,
struct V_1 * V_2 , const char * V_118 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
int V_85 ;
F_8 ( L_18 , V_118 ) ;
V_5 -> V_119 . V_120 = false ;
V_5 -> V_119 . V_84 = 0 ;
V_5 -> V_119 . V_121 = F_30 ;
memset ( & V_5 -> V_99 , '\0' , sizeof ( V_5 -> V_99 ) ) ;
V_5 -> V_99 . V_122 = V_123 ;
V_5 -> V_99 . V_124 = V_125 ;
strncpy ( V_5 -> V_99 . V_118 , V_118 , sizeof( V_5 -> V_99 . V_118 ) - 1 ) ;
V_5 -> V_99 . V_118 [ sizeof( V_5 -> V_99 . V_118 ) - 1 ] = '\0' ;
V_5 -> V_99 . V_103 = & V_5 -> V_119 ;
V_5 -> V_99 . V_22 . V_126 = V_41 -> V_23 . V_127 ;
if ( F_1 ( V_2 ) )
F_7 ( V_2 ) ;
V_85 = F_33 ( & V_5 -> V_99 ) ;
if ( F_1 ( V_2 ) )
F_12 ( V_2 ) ;
return V_85 ;
}
static void F_34 ( struct V_42 * V_128 ,
struct V_42 * V_129 )
{
V_129 -> V_47 = V_128 -> V_47 ;
V_129 -> V_130 = V_128 -> V_130 ;
V_129 -> V_131 = V_128 -> V_131 ;
V_129 -> V_132 = V_128 -> V_132 ;
V_129 -> V_49 = V_128 -> V_49 ;
V_129 -> V_133 = V_128 -> V_133 ;
V_129 -> V_134 = V_128 -> V_134 ;
V_129 -> V_135 = V_128 -> V_135 ;
V_129 -> clock = V_128 -> clock ;
F_35 ( V_129 , V_136 ) ;
}
static bool
F_36 ( struct V_137 * V_2 , const struct V_42 * V_43 ,
struct V_42 * V_129 )
{
struct V_44 * V_6 = V_2 -> V_22 -> V_45 ;
struct V_1 * V_20 = F_37 ( V_2 ) ;
struct V_4 * V_5 = V_20 -> V_6 ;
int V_138 , clock ;
int V_7 = F_2 ( V_20 ) ;
int V_139 = F_3 ( V_20 ) == V_14 ? 1 : 0 ;
static int V_140 [ 2 ] = { V_13 , V_14 } ;
int V_141 = V_43 -> clock ;
int V_17 = 24 ;
if ( F_1 ( V_20 ) && V_5 -> V_46 ) {
F_34 ( V_5 -> V_46 , V_129 ) ;
V_141 = V_5 -> V_46 -> clock ;
V_17 = V_6 -> V_50 . V_17 ;
}
for ( V_138 = 1 ; V_138 <= V_7 ; V_138 <<= 1 ) {
for ( clock = V_139 ; clock >= 0 ; clock -- ) {
int V_142 = F_6 ( F_4 ( V_140 [ clock ] ) , V_138 ) ;
if ( F_5 ( V_141 , V_17 ) <= V_142 ) {
V_5 -> V_15 = V_140 [ clock ] ;
V_5 -> V_138 = V_138 ;
V_129 -> clock = F_4 ( V_5 -> V_15 ) ;
F_8 ( L_19
L_20 ,
V_5 -> V_15 , V_5 -> V_138 ,
V_129 -> clock ) ;
return true ;
}
}
}
if ( F_1 ( V_20 ) ) {
V_5 -> V_138 = V_7 ;
V_5 -> V_15 = V_140 [ V_139 ] ;
V_129 -> clock = F_4 ( V_5 -> V_15 ) ;
F_8 ( L_21
L_20 ,
V_5 -> V_15 , V_5 -> V_138 ,
V_129 -> clock ) ;
return true ;
}
return false ;
}
static void
F_38 ( T_3 * V_143 , T_3 * V_144 )
{
T_5 V_145 , V_146 ;
V_146 = * V_143 ;
V_145 = V_146 * ( 0x800000 ) ;
V_146 = F_39 ( V_145 , * V_144 ) ;
* V_143 = V_145 ;
* V_144 = 0x800000 ;
}
static void
F_40 ( int V_17 ,
int V_147 ,
int V_16 ,
int V_148 ,
struct V_149 * V_150 )
{
V_150 -> V_151 = 64 ;
V_150 -> V_152 = ( V_16 * V_17 + 7 ) >> 3 ;
V_150 -> V_153 = V_148 * V_147 ;
F_38 ( & V_150 -> V_152 , & V_150 -> V_153 ) ;
V_150 -> V_154 = V_16 ;
V_150 -> V_155 = V_148 ;
F_38 ( & V_150 -> V_154 , & V_150 -> V_155 ) ;
}
void
F_41 ( struct V_156 * V_157 , struct V_42 * V_43 ,
struct V_42 * V_129 )
{
struct V_21 * V_22 = V_157 -> V_22 ;
struct V_44 * V_6 = V_22 -> V_45 ;
struct V_158 * V_159 = & V_22 -> V_159 ;
struct V_137 * V_2 ;
struct V_160 * V_160 = F_42 ( V_157 ) ;
int V_138 = 4 , V_17 = 24 ;
struct V_149 V_150 ;
int V_161 = V_160 -> V_161 ;
F_43 (encoder, &mode_config->encoder_list, head) {
struct V_1 * V_20 ;
struct V_4 * V_5 ;
if ( V_2 -> V_157 != V_157 )
continue;
V_20 = F_37 ( V_2 ) ;
V_5 = V_20 -> V_6 ;
if ( V_20 -> type == V_162 ) {
V_138 = V_5 -> V_138 ;
break;
} else if ( F_1 ( V_20 ) ) {
V_138 = V_5 -> V_138 ;
V_17 = V_6 -> V_50 . V_17 ;
break;
}
}
F_40 ( V_17 , V_138 ,
V_43 -> clock , V_129 -> clock , & V_150 ) ;
{
F_10 ( F_44 ( V_161 ) ,
( ( V_150 . V_151 - 1 ) << V_163 ) |
V_150 . V_152 ) ;
F_10 ( F_45 ( V_161 ) , V_150 . V_153 ) ;
F_10 ( F_46 ( V_161 ) , V_150 . V_154 ) ;
F_10 ( F_47 ( V_161 ) , V_150 . V_155 ) ;
}
}
static void
F_48 ( struct V_137 * V_2 , struct V_42 * V_43 ,
struct V_42 * V_129 )
{
struct V_1 * V_20 = F_37 ( V_2 ) ;
struct V_156 * V_157 = V_2 -> V_157 ;
struct V_160 * V_160 = F_42 ( V_157 ) ;
struct V_4 * V_5 = V_20 -> V_6 ;
struct V_21 * V_22 = V_2 -> V_22 ;
V_5 -> V_164 = V_165 | V_166 ;
V_5 -> V_164 |= V_5 -> V_167 ;
if ( V_129 -> V_168 & V_169 )
V_5 -> V_164 |= V_170 ;
if ( V_129 -> V_168 & V_171 )
V_5 -> V_164 |= V_172 ;
V_5 -> V_164 |= V_173 ;
switch ( V_5 -> V_138 ) {
case 1 :
V_5 -> V_164 |= V_174 ;
break;
case 2 :
V_5 -> V_164 |= V_175 ;
break;
case 4 :
V_5 -> V_164 |= V_176 ;
break;
}
if ( V_5 -> V_177 )
V_5 -> V_164 |= V_178 ;
memset ( V_5 -> V_179 , 0 , V_180 ) ;
V_5 -> V_179 [ 0 ] = V_5 -> V_15 ;
V_5 -> V_179 [ 1 ] = V_5 -> V_138 ;
if ( V_5 -> V_8 [ V_9 ] >= 0x11 &&
( V_5 -> V_8 [ V_10 ] & V_181 ) ) {
V_5 -> V_179 [ 1 ] |= V_182 ;
V_5 -> V_164 |= V_183 ;
}
if ( V_160 -> V_161 == 1 )
V_5 -> V_164 |= V_184 ;
F_10 ( V_5 -> V_64 , ( V_5 -> V_164 | V_185 ) ) ;
F_8 ( L_22 , V_5 -> V_164 ) ;
if ( F_1 ( V_20 ) ) {
T_3 V_186 ;
F_13 ( V_20 ) ;
if ( V_43 -> V_47 != V_129 -> V_47 ||
V_43 -> V_49 != V_129 -> V_49 )
V_186 = V_187 ;
else
V_186 = 0 ;
V_186 |= V_160 -> V_161 << V_188 ;
F_10 ( V_189 , V_186 ) ;
}
}
static void F_49 ( struct V_1 * V_2 , int V_43 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
int V_85 , V_56 ;
if ( V_5 -> V_8 [ V_9 ] < 0x11 )
return;
if ( V_43 != V_190 ) {
V_85 = F_28 ( V_2 , V_191 ,
V_192 ) ;
if ( V_85 != 1 )
F_50 ( L_23 ) ;
} else {
for ( V_56 = 0 ; V_56 < 3 ; V_56 ++ ) {
V_85 = F_28 ( V_2 ,
V_191 ,
V_193 ) ;
if ( V_85 == 1 )
break;
F_26 ( 1000 ) ;
}
}
}
static void F_51 ( struct V_137 * V_2 )
{
struct V_1 * V_20 = F_37 ( V_2 ) ;
int V_50 = F_1 ( V_20 ) ;
if ( V_50 ) {
F_18 ( V_20 ) ;
F_15 ( V_20 ) ;
F_7 ( V_20 ) ;
}
F_49 ( V_20 , V_190 ) ;
F_52 ( V_20 ) ;
if ( V_50 )
F_12 ( V_20 ) ;
}
static void F_53 ( struct V_137 * V_2 )
{
struct V_1 * V_20 = F_37 ( V_2 ) ;
int V_50 = F_1 ( V_20 ) ;
if ( V_50 )
F_13 ( V_20 ) ;
F_54 ( V_20 ) ;
F_55 ( V_20 ) ;
if ( V_50 )
F_16 ( V_20 ) ;
}
static void
F_56 ( struct V_137 * V_2 , int V_43 )
{
struct V_1 * V_20 = F_37 ( V_2 ) ;
struct V_4 * V_5 = V_20 -> V_6 ;
struct V_21 * V_22 = V_2 -> V_22 ;
T_3 V_194 = F_9 ( V_5 -> V_64 ) ;
int V_50 = F_1 ( V_20 ) ;
if ( V_43 != V_190 ) {
if ( V_50 ) {
F_18 ( V_20 ) ;
F_7 ( V_20 ) ;
}
F_49 ( V_20 , V_43 ) ;
F_52 ( V_20 ) ;
if ( V_50 ) {
F_12 ( V_20 ) ;
F_15 ( V_20 ) ;
}
} else {
if ( V_50 )
F_13 ( V_20 ) ;
F_49 ( V_20 , V_43 ) ;
if ( ! ( V_194 & V_185 ) ) {
F_54 ( V_20 ) ;
F_55 ( V_20 ) ;
}
if ( V_50 )
F_16 ( V_20 ) ;
}
}
static bool
F_57 ( struct V_1 * V_2 , T_4 V_84 ,
T_1 * V_62 , int V_67 )
{
int V_85 , V_56 ;
for ( V_56 = 0 ; V_56 < 3 ; V_56 ++ ) {
V_85 = F_29 ( V_2 , V_84 , V_62 ,
V_67 ) ;
if ( V_85 == V_67 )
return true ;
F_26 ( 1000 ) ;
}
return false ;
}
static bool
F_58 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
return F_57 ( V_2 ,
V_195 ,
V_5 -> V_196 ,
V_197 ) ;
}
static T_1
F_59 ( T_1 V_196 [ V_197 ] ,
int V_198 )
{
return V_196 [ V_198 - V_195 ] ;
}
static T_1
F_60 ( T_1 V_196 [ V_197 ] ,
int V_199 )
{
int V_56 = V_200 + ( V_199 >> 1 ) ;
int V_201 = ( ( V_199 & 1 ) ?
V_202 :
V_203 ) ;
T_1 V_204 = F_59 ( V_196 , V_56 ) ;
return ( ( V_204 >> V_201 ) & 3 ) << V_205 ;
}
static T_1
F_61 ( T_1 V_196 [ V_197 ] ,
int V_199 )
{
int V_56 = V_200 + ( V_199 >> 1 ) ;
int V_201 = ( ( V_199 & 1 ) ?
V_206 :
V_207 ) ;
T_1 V_204 = F_59 ( V_196 , V_56 ) ;
return ( ( V_204 >> V_201 ) & 3 ) << V_208 ;
}
static void
F_62 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
T_1 V_57 = 0 ;
T_1 V_209 = 0 ;
int V_199 ;
for ( V_199 = 0 ; V_199 < V_5 -> V_138 ; V_199 ++ ) {
T_1 V_210 = F_60 ( V_5 -> V_196 , V_199 ) ;
T_1 V_211 = F_61 ( V_5 -> V_196 , V_199 ) ;
if ( V_210 > V_57 )
V_57 = V_210 ;
if ( V_211 > V_209 )
V_209 = V_211 ;
}
if ( V_57 >= V_212 )
V_57 = V_212 | V_213 ;
if ( V_209 == V_214 )
V_209 |= V_215 ;
for ( V_199 = 0 ; V_199 < 4 ; V_199 ++ )
V_5 -> V_216 [ V_199 ] = V_57 | V_209 ;
}
static T_1
F_63 ( T_1 V_196 [ V_197 ] ,
int V_199 )
{
int V_56 = V_195 + ( V_199 >> 1 ) ;
int V_201 = ( V_199 & 1 ) * 4 ;
T_1 V_204 = F_59 ( V_196 , V_56 ) ;
return ( V_204 >> V_201 ) & 0xf ;
}
static bool
F_64 ( T_1 V_196 [ V_197 ] , int V_138 )
{
int V_199 ;
T_1 V_217 ;
for ( V_199 = 0 ; V_199 < V_138 ; V_199 ++ ) {
V_217 = F_63 ( V_196 , V_199 ) ;
if ( ( V_217 & V_218 ) == 0 )
return false ;
}
return true ;
}
static bool
F_65 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
T_1 V_219 ;
T_1 V_217 ;
int V_199 ;
V_219 = F_59 ( V_5 -> V_196 ,
V_220 ) ;
if ( ( V_219 & V_221 ) == 0 )
return false ;
for ( V_199 = 0 ; V_199 < V_5 -> V_138 ; V_199 ++ ) {
V_217 = F_63 ( V_5 -> V_196 , V_199 ) ;
if ( ( V_217 & V_222 ) != V_222 )
return false ;
}
return true ;
}
static bool
F_66 ( struct V_1 * V_2 ,
T_3 V_223 ,
T_1 V_224 )
{
struct V_21 * V_22 = V_2 -> V_23 . V_22 ;
int V_85 ;
struct V_4 * V_5 = V_2 -> V_6 ;
F_10 ( V_5 -> V_64 , V_223 ) ;
F_9 ( V_5 -> V_64 ) ;
V_85 = F_28 ( V_2 ,
V_225 ,
V_224 ) ;
if ( V_85 != 1 ) {
F_8 ( L_24 ,
V_224 ) ;
return false ;
}
return true ;
}
static bool
F_67 ( struct V_1 * V_2 ,
T_1 V_224 )
{
int V_85 ;
struct V_4 * V_5 = V_2 -> V_6 ;
V_85 = F_27 ( V_2 ,
V_226 ,
V_5 -> V_216 ,
V_5 -> V_138 ) ;
if ( V_85 != V_5 -> V_138 ) {
F_8 ( L_25 ,
V_5 -> V_216 [ 0 ] , V_5 -> V_138 ) ;
return false ;
}
return true ;
}
static void
F_68 ( struct V_1 * V_2 , T_1 V_227 )
{
struct V_21 * V_22 = V_2 -> V_23 . V_22 ;
struct V_4 * V_5 = V_2 -> V_6 ;
struct V_228 * V_229 ;
int V_230 , V_231 , V_232 ;
if ( V_5 -> V_64 == V_233 )
V_229 = & V_234 [ 0 ] ;
else
V_229 = & V_234 [ 1 ] ;
V_230 = ( V_227 & V_235 ) ;
V_231 = ( ( V_227 & V_214 ) ) >>
V_208 ;
if ( V_230 + V_231 > 3 )
return;
#ifdef F_69
return;
#endif
F_8 ( L_26 ) ;
F_70 ( V_22 ) ;
F_71 ( V_22 , V_229 -> V_236 , 0x0505313A ) ;
F_71 ( V_22 , V_229 -> V_237 , 0x43406055 ) ;
V_232 = ( V_230 + V_231 ) * 2 ;
if ( V_231 == 1 && V_230 == 1 ) {
F_71 ( V_22 , V_229 -> V_238 , 0x055738954 ) ;
} else
F_71 ( V_22 , V_229 -> V_238 , V_239 [ V_232 ] ) ;
if ( ( V_230 + V_231 ) == V_240 )
F_71 ( V_22 , V_229 -> V_241 , 0x70802040 ) ;
else
F_71 ( V_22 , V_229 -> V_241 , 0x40802040 ) ;
F_71 ( V_22 , V_229 -> V_237 , 0xc3406055 ) ;
F_71 ( V_22 , V_229 -> V_242 , 0x1f030040 ) ;
V_232 = 2 * V_231 + 1 ;
F_71 ( V_22 , V_229 -> V_243 , V_239 [ V_232 ] ) ;
return;
}
static void
F_54 ( struct V_1 * V_2 )
{
struct V_21 * V_22 = V_2 -> V_23 . V_22 ;
struct V_4 * V_5 = V_2 -> V_6 ;
int V_56 ;
T_1 V_244 ;
bool V_245 = false ;
int V_246 ;
T_2 V_247 ;
T_3 V_164 = V_5 -> V_164 ;
V_164 |= V_185 ;
V_164 &= ~ V_248 ;
V_247 = V_164 ;
V_247 |= V_249 ;
F_10 ( V_5 -> V_64 , V_247 ) ;
F_9 ( V_5 -> V_64 ) ;
F_72 ( V_22 ) ;
F_8 ( L_27 ) ;
F_27 ( V_2 , V_250 ,
V_5 -> V_179 ,
2 ) ;
memset ( V_5 -> V_216 , 0 , 4 ) ;
V_244 = 0 ;
V_246 = 0 ;
V_245 = false ;
F_8 ( L_28 ) ;
V_247 = V_164 | V_249 ;
for (; ; ) {
F_8 ( L_29 ,
V_5 -> V_216 [ 0 ] ,
V_5 -> V_179 [ 0 ] ,
V_5 -> V_179 [ 1 ] ) ;
if ( ! F_66 ( V_2 , V_247 , V_251 ) ) {
F_8 ( L_30 ) ;
}
F_68 ( V_2 , V_5 -> V_216 [ 0 ] ) ;
F_67 ( V_2 , V_251 ) ;
F_26 ( 200 ) ;
if ( ! F_58 ( V_2 ) )
break;
F_8 ( L_31 ,
V_5 -> V_196 [ 0 ] , V_5 -> V_196 [ 1 ] , V_5 -> V_196 [ 2 ] ,
V_5 -> V_196 [ 3 ] , V_5 -> V_196 [ 4 ] , V_5 -> V_196 [ 5 ] ) ;
if ( F_64 ( V_5 -> V_196 , V_5 -> V_138 ) ) {
F_8 ( L_32 ) ;
V_245 = true ;
break;
}
for ( V_56 = 0 ; V_56 < V_5 -> V_138 ; V_56 ++ )
if ( ( V_5 -> V_216 [ V_56 ] & V_213 ) == 0 )
break;
if ( V_56 == V_5 -> V_138 )
break;
if ( ( V_5 -> V_216 [ 0 ] & V_235 ) == V_244 ) {
++ V_246 ;
if ( V_246 == 5 )
break;
} else
V_246 = 0 ;
V_244 = V_5 -> V_216 [ 0 ] & V_235 ;
F_62 ( V_2 ) ;
}
if ( ! V_245 ) {
F_8 ( L_33 , V_5 -> V_216 [ 0 ] ) ;
}
V_5 -> V_164 = V_164 ;
}
static void
F_55 ( struct V_1 * V_2 )
{
struct V_21 * V_22 = V_2 -> V_23 . V_22 ;
struct V_4 * V_5 = V_2 -> V_6 ;
bool V_252 = false ;
int V_246 , V_253 ;
T_2 V_247 ;
T_3 V_164 = V_5 -> V_164 ;
V_246 = 0 ;
V_253 = 0 ;
V_252 = false ;
F_8 ( L_2 ) ;
V_247 = V_164 | V_254 ;
for (; ; ) {
F_8 ( L_29 ,
V_5 -> V_216 [ 0 ] ,
V_5 -> V_179 [ 0 ] ,
V_5 -> V_179 [ 1 ] ) ;
if ( ! F_66 ( V_2 , V_247 ,
V_255 ) ) {
F_8 ( L_34 ) ;
}
if ( V_253 > 5 ) {
F_25 ( L_35 ) ;
F_52 ( V_2 ) ;
break;
}
F_68 ( V_2 , V_5 -> V_216 [ 0 ] ) ;
F_67 ( V_2 , V_255 ) ;
F_26 ( 1000 ) ;
if ( ! F_58 ( V_2 ) )
break;
F_8 ( L_31 ,
V_5 -> V_196 [ 0 ] , V_5 -> V_196 [ 1 ] , V_5 -> V_196 [ 2 ] ,
V_5 -> V_196 [ 3 ] , V_5 -> V_196 [ 4 ] , V_5 -> V_196 [ 5 ] ) ;
if ( ! F_64 ( V_5 -> V_196 , V_5 -> V_138 ) ) {
F_54 ( V_2 ) ;
V_253 ++ ;
continue;
}
if ( F_65 ( V_2 ) ) {
F_8 ( L_36 ) ;
V_252 = true ;
break;
}
if ( V_246 > 5 ) {
F_52 ( V_2 ) ;
F_54 ( V_2 ) ;
V_246 = 0 ;
V_253 ++ ;
continue;
}
F_62 ( V_2 ) ;
++ V_246 ;
}
V_247 = V_164 | V_173 ;
F_10 ( V_5 -> V_64 , V_247 ) ;
F_9 ( V_5 -> V_64 ) ;
F_28 ( V_2 ,
V_225 , V_256 ) ;
}
static void
F_52 ( struct V_1 * V_2 )
{
struct V_21 * V_22 = V_2 -> V_23 . V_22 ;
struct V_4 * V_5 = V_2 -> V_6 ;
T_3 V_164 = V_5 -> V_164 ;
if ( ( F_9 ( V_5 -> V_64 ) & V_185 ) == 0 )
return;
F_8 ( L_2 ) ;
{
V_164 &= ~ V_248 ;
F_10 ( V_5 -> V_64 , V_164 | V_257 ) ;
}
F_9 ( V_5 -> V_64 ) ;
F_11 ( 17 ) ;
F_10 ( V_5 -> V_64 , V_164 & ~ V_185 ) ;
F_9 ( V_5 -> V_64 ) ;
}
static enum V_258 F_73 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
enum V_258 V_68 ;
V_68 = V_259 ;
if ( F_29 ( V_2 , 0x000 , V_5 -> V_8 ,
sizeof ( V_5 -> V_8 ) ) == sizeof ( V_5 -> V_8 ) )
{
if ( V_5 -> V_8 [ V_9 ] != 0 )
V_68 = V_260 ;
}
if ( V_68 == V_260 )
F_8 ( L_37 ,
V_5 -> V_8 [ 0 ] , V_5 -> V_8 [ 1 ] ,
V_5 -> V_8 [ 2 ] , V_5 -> V_8 [ 3 ] ) ;
return V_68 ;
}
static enum V_258
F_74 ( struct V_40 * V_41 , bool V_261 )
{
struct V_1 * V_2 = F_21 ( V_41 ) ;
struct V_4 * V_5 = V_2 -> V_6 ;
enum V_258 V_68 ;
struct V_262 * V_262 = NULL ;
int V_50 = F_1 ( V_2 ) ;
V_5 -> V_177 = false ;
if ( V_50 )
F_7 ( V_2 ) ;
V_68 = F_73 ( V_2 ) ;
if ( V_68 != V_260 ) {
if ( V_50 )
F_12 ( V_2 ) ;
return V_68 ;
}
if ( V_5 -> V_263 ) {
V_5 -> V_177 = V_5 -> V_263 > 0 ;
} else {
V_262 = F_75 ( V_41 , & V_5 -> V_99 ) ;
if ( V_262 ) {
V_5 -> V_177 = F_76 ( V_262 ) ;
F_77 ( V_262 ) ;
}
}
if ( V_50 )
F_12 ( V_2 ) ;
return V_260 ;
}
static int F_78 ( struct V_40 * V_41 )
{
struct V_1 * V_20 = F_21 ( V_41 ) ;
struct V_4 * V_5 = V_20 -> V_6 ;
struct V_262 * V_262 = NULL ;
int V_85 = 0 ;
int V_50 = F_1 ( V_20 ) ;
V_262 = F_75 ( V_41 , & V_5 -> V_99 ) ;
if ( V_262 ) {
F_79 ( V_41 , V_262 ) ;
V_85 = F_80 ( V_41 , V_262 ) ;
F_77 ( V_262 ) ;
}
if ( F_1 ( V_20 ) ) {
struct V_21 * V_22 = V_41 -> V_22 ;
struct V_44 * V_6 = V_22 -> V_45 ;
F_12 ( V_20 ) ;
if ( V_85 ) {
if ( V_50 && ! V_5 -> V_46 ) {
struct V_42 * V_264 ;
F_43 (newmode, &connector->probed_modes,
head) {
if ( V_264 -> type & V_265 ) {
V_5 -> V_46 =
F_81 ( V_22 , V_264 ) ;
break;
}
}
}
return V_85 ;
}
if ( ! V_5 -> V_46 && V_6 -> V_266 ) {
V_5 -> V_46 =
F_81 ( V_22 , V_6 -> V_266 ) ;
if ( V_5 -> V_46 ) {
V_5 -> V_46 -> type |=
V_265 ;
}
}
if ( V_5 -> V_46 != NULL ) {
struct V_42 * V_43 ;
V_43 = F_81 ( V_22 , V_5 -> V_46 ) ;
F_82 ( V_41 , V_43 ) ;
return 1 ;
}
}
return V_85 ;
}
static bool
F_83 ( struct V_40 * V_41 )
{
struct V_1 * V_2 = F_21 ( V_41 ) ;
struct V_4 * V_5 = V_2 -> V_6 ;
struct V_262 * V_262 ;
bool V_177 = false ;
int V_50 = F_1 ( V_2 ) ;
if ( V_50 )
F_7 ( V_2 ) ;
V_262 = F_75 ( V_41 , & V_5 -> V_99 ) ;
if ( V_262 ) {
V_177 = F_76 ( V_262 ) ;
F_77 ( V_262 ) ;
}
if ( V_50 )
F_12 ( V_2 ) ;
return V_177 ;
}
static int
F_84 ( struct V_40 * V_41 ,
struct V_267 * V_268 ,
T_5 V_269 )
{
struct V_44 * V_6 = V_41 -> V_22 -> V_45 ;
struct V_1 * V_2 = F_21 ( V_41 ) ;
struct V_4 * V_5 = V_2 -> V_6 ;
int V_85 ;
V_85 = F_85 ( & V_41 -> V_23 , V_268 , V_269 ) ;
if ( V_85 )
return V_85 ;
if ( V_268 == V_6 -> V_270 ) {
int V_56 = V_269 ;
bool V_177 ;
if ( V_56 == V_5 -> V_263 )
return 0 ;
V_5 -> V_263 = V_56 ;
if ( V_56 == 0 )
V_177 = F_83 ( V_41 ) ;
else
V_177 = V_56 > 0 ;
if ( V_177 == V_5 -> V_177 )
return 0 ;
V_5 -> V_177 = V_177 ;
goto V_271;
}
if ( V_268 == V_6 -> V_272 ) {
if ( V_269 == ! ! V_5 -> V_167 )
return 0 ;
V_5 -> V_167 = V_269 ? V_273 : 0 ;
goto V_271;
}
return - V_274 ;
V_271:
if ( V_2 -> V_23 . V_157 ) {
struct V_156 * V_157 = V_2 -> V_23 . V_157 ;
F_86 ( V_157 , & V_157 -> V_43 ,
V_157 -> V_275 , V_157 -> V_276 ,
V_157 -> V_277 -> V_278 ) ;
}
return 0 ;
}
static void
F_87 ( struct V_40 * V_41 )
{
struct V_1 * V_1 = F_21 ( V_41 ) ;
struct V_4 * V_5 = V_1 -> V_6 ;
if ( F_1 ( V_1 ) ) {
if ( V_5 -> V_46 ) {
F_77 ( V_5 -> V_46 ) ;
V_5 -> V_46 = NULL ;
}
}
F_88 ( & V_5 -> V_99 ) ;
F_89 ( V_41 ) ;
F_90 ( V_41 ) ;
F_77 ( V_41 ) ;
}
static void F_91 ( struct V_137 * V_2 )
{
F_92 ( V_2 ) ;
}
static void F_93 ( struct V_40 * V_41 )
{
F_94 ( V_41 ) ;
F_95 ( V_41 ) ;
}
static bool F_96 ( struct V_21 * V_22 )
{
struct V_44 * V_6 = V_22 -> V_45 ;
struct V_279 * V_280 ;
int V_56 ;
if ( ! V_6 -> V_281 )
return false ;
for ( V_56 = 0 ; V_56 < V_6 -> V_281 ; V_56 ++ ) {
V_280 = V_6 -> V_282 + V_56 ;
if ( V_280 -> V_283 == V_284 &&
V_280 -> V_285 == V_286 )
return true ;
}
return false ;
}
static void F_97 ( struct V_21 * V_22 )
{
T_2 V_287 ;
V_287 = F_9 ( V_288 ) ;
V_287 |= ( V_289 |
V_290 |
V_291 |
V_292 |
V_293 |
V_294 ) ;
F_10 ( V_288 , V_287 ) ;
F_26 ( 500 ) ;
}
void
F_98 ( struct V_21 * V_22 , struct V_295 * V_296 , int V_64 )
{
struct V_1 * V_1 ;
struct V_117 * V_117 ;
struct V_40 * V_41 ;
struct V_137 * V_2 ;
struct V_4 * V_5 ;
const char * V_118 = NULL ;
int type = V_297 ;
V_1 = F_99 ( sizeof( struct V_1 ) , V_298 ) ;
if ( ! V_1 )
return;
V_117 = F_99 ( sizeof( struct V_117 ) , V_298 ) ;
if ( ! V_117 )
goto V_299;
V_5 = F_99 ( sizeof( struct V_4 ) , V_298 ) ;
if ( ! V_5 )
goto V_300;
if ( ( V_64 == V_301 ) && F_96 ( V_22 ) )
type = V_302 ;
V_41 = & V_117 -> V_23 ;
V_2 = & V_1 -> V_23 ;
F_100 ( V_22 , V_41 , & V_303 , type ) ;
F_101 ( V_22 , V_2 , & V_304 , V_305 ) ;
F_102 ( V_117 , V_1 ) ;
if ( type == V_297 )
V_1 -> type = V_162 ;
else
V_1 -> type = V_3 ;
V_1 -> V_6 = V_5 ;
V_5 -> V_2 = V_1 ;
V_5 -> V_64 = V_64 ;
F_103 ( V_2 , & V_306 ) ;
F_104 ( V_41 , & V_307 ) ;
V_41 -> V_308 = V_309 ;
V_41 -> V_310 = false ;
V_41 -> V_311 = false ;
F_105 ( V_41 ) ;
switch ( V_64 ) {
case V_233 :
V_118 = L_38 ;
V_1 -> V_312 = ( V_313 | V_314 ) ;
break;
case V_301 :
V_118 = L_39 ;
V_1 -> V_312 = ( V_313 | V_315 ) ;
break;
}
F_97 ( V_22 ) ;
F_32 ( V_117 , V_1 , V_118 ) ;
F_93 ( V_41 ) ;
if ( F_1 ( V_1 ) ) {
int V_85 ;
struct V_316 V_317 ;
T_2 V_318 , V_319 , V_320 ;
T_2 V_321 ;
V_318 = F_9 ( V_26 ) ;
V_318 &= ~ V_32 ;
V_318 |= V_33 ;
F_10 ( V_26 , V_318 ) ;
V_321 = F_9 ( V_322 ) ;
V_321 |= V_323 ;
F_10 ( V_322 , V_321 ) ;
V_318 = F_9 ( V_324 ) ;
V_319 = F_9 ( V_325 ) ;
V_320 = F_9 ( V_326 ) ;
V_317 . V_327 = ( V_318 & V_328 ) >>
V_329 ;
V_317 . V_330 = ( V_318 & V_331 ) >>
V_332 ;
V_317 . V_333 = ( V_319 & V_334 ) >>
V_335 ;
V_317 . V_336 = ( V_319 & V_337 ) >>
V_338 ;
V_317 . V_339 = ( ( V_320 & V_340 ) >>
V_341 ) ;
F_8 ( L_40 ,
V_317 . V_327 , V_317 . V_330 , V_317 . V_333 , V_317 . V_336 , V_317 . V_339 ) ;
V_5 -> V_28 = V_317 . V_327 / 10 ;
V_5 -> V_342 = V_317 . V_330 / 10 ;
V_5 -> V_39 = V_317 . V_333 / 10 ;
V_5 -> V_343 = V_317 . V_336 / 10 ;
V_5 -> V_38 = ( V_317 . V_339 - 1 ) * 100 ;
F_8 ( L_41 ,
V_5 -> V_28 , V_5 -> V_343 ,
V_5 -> V_38 ) ;
F_8 ( L_42 ,
V_5 -> V_342 , V_5 -> V_39 ) ;
F_7 ( V_1 ) ;
V_85 = F_29 ( V_1 , V_9 ,
V_5 -> V_8 ,
sizeof( V_5 -> V_8 ) ) ;
F_12 ( V_1 ) ;
if ( V_85 == 0 ) {
F_106 ( L_43 ) ;
F_91 ( V_2 ) ;
F_87 ( V_41 ) ;
goto V_300;
} else {
F_8 ( L_37 ,
V_5 -> V_8 [ 0 ] , V_5 -> V_8 [ 1 ] ,
V_5 -> V_8 [ 2 ] , V_5 -> V_8 [ 3 ] ) ;
}
}
return;
V_300:
F_77 ( V_117 ) ;
V_299:
F_77 ( V_1 ) ;
}
