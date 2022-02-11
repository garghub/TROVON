static bool F_1 ( struct V_1 * V_1 )
{
return V_1 -> V_2 . type == V_3 ;
}
static bool F_2 ( struct V_1 * V_1 )
{
return V_1 -> F_2 ;
}
static bool F_3 ( struct V_1 * V_1 )
{
return F_1 ( V_1 ) && ! F_2 ( V_1 ) ;
}
static struct V_1 * F_4 ( struct V_4 * V_5 )
{
return F_5 ( V_5 , struct V_1 , V_2 . V_2 ) ;
}
static struct V_1 * F_6 ( struct V_6 * V_7 )
{
return F_5 ( F_7 ( V_7 ) ,
struct V_1 , V_2 ) ;
}
bool F_8 ( struct V_4 * V_5 )
{
struct V_1 * V_1 ;
if ( ! V_5 )
return false ;
V_1 = F_4 ( V_5 ) ;
return F_2 ( V_1 ) ;
}
void
F_9 ( struct V_8 * V_8 ,
int * V_9 , int * V_10 )
{
struct V_1 * V_1 = F_5 ( V_8 , struct V_1 , V_2 ) ;
* V_9 = V_1 -> V_11 ;
if ( V_1 -> V_10 == V_12 )
* V_10 = 162000 ;
else if ( V_1 -> V_10 == V_13 )
* V_10 = 270000 ;
}
static int
F_10 ( struct V_1 * V_1 )
{
int V_14 = V_1 -> V_15 [ V_16 ] & 0x1f ;
switch ( V_14 ) {
case 1 : case 2 : case 4 :
break;
default:
V_14 = 4 ;
}
return V_14 ;
}
static int
F_11 ( struct V_1 * V_1 )
{
int V_17 = V_1 -> V_15 [ V_18 ] ;
switch ( V_17 ) {
case V_12 :
case V_13 :
break;
default:
V_17 = V_12 ;
break;
}
return V_17 ;
}
static int
F_12 ( T_1 V_10 )
{
if ( V_10 == V_13 )
return 270000 ;
else
return 162000 ;
}
static int
F_13 ( int V_19 , int V_20 )
{
return ( V_19 * V_20 + 9 ) / 10 ;
}
static int
F_14 ( int V_21 , int V_22 )
{
return ( V_21 * V_22 * 8 ) / 10 ;
}
static int
F_15 ( struct V_6 * V_7 ,
struct V_23 * V_24 )
{
struct V_1 * V_1 = F_6 ( V_7 ) ;
int V_21 = F_12 ( F_11 ( V_1 ) ) ;
int V_22 = F_10 ( V_1 ) ;
int V_25 , V_26 ;
if ( F_1 ( V_1 ) && V_1 -> V_27 ) {
if ( V_24 -> V_28 > V_1 -> V_27 -> V_28 )
return V_29 ;
if ( V_24 -> V_30 > V_1 -> V_27 -> V_30 )
return V_29 ;
}
V_26 = F_13 ( V_24 -> clock , 24 ) ;
V_25 = F_14 ( V_21 , V_22 ) ;
if ( V_26 > V_25 ) {
V_26 = F_13 ( V_24 -> clock , 18 ) ;
if ( V_26 > V_25 )
return V_31 ;
else
V_24 -> V_32 |= V_33 ;
}
if ( V_24 -> clock < 10000 )
return V_34 ;
return V_35 ;
}
static T_2
F_16 ( T_1 * V_36 , int V_37 )
{
int V_38 ;
T_2 V_39 = 0 ;
if ( V_37 > 4 )
V_37 = 4 ;
for ( V_38 = 0 ; V_38 < V_37 ; V_38 ++ )
V_39 |= ( ( T_2 ) V_36 [ V_38 ] ) << ( ( 3 - V_38 ) * 8 ) ;
return V_39 ;
}
static void
F_17 ( T_2 V_36 , T_1 * V_40 , int V_41 )
{
int V_38 ;
if ( V_41 > 4 )
V_41 = 4 ;
for ( V_38 = 0 ; V_38 < V_41 ; V_38 ++ )
V_40 [ V_38 ] = V_36 >> ( ( 3 - V_38 ) * 8 ) ;
}
static int
F_18 ( struct V_42 * V_43 )
{
struct V_44 * V_45 = V_43 -> V_46 ;
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
static bool F_20 ( struct V_1 * V_1 )
{
struct V_42 * V_43 = V_1 -> V_2 . V_2 . V_43 ;
struct V_44 * V_45 = V_43 -> V_46 ;
return ( F_19 ( V_58 ) & V_59 ) != 0 ;
}
static bool F_21 ( struct V_1 * V_1 )
{
struct V_42 * V_43 = V_1 -> V_2 . V_2 . V_43 ;
struct V_44 * V_45 = V_43 -> V_46 ;
return ( F_19 ( V_60 ) & V_61 ) != 0 ;
}
static void
F_22 ( struct V_1 * V_1 )
{
struct V_42 * V_43 = V_1 -> V_2 . V_2 . V_43 ;
struct V_44 * V_45 = V_43 -> V_46 ;
if ( ! F_1 ( V_1 ) )
return;
if ( ! F_20 ( V_1 ) && ! F_21 ( V_1 ) ) {
F_23 ( 1 , L_1 ) ;
F_24 ( L_2 ,
F_19 ( V_58 ) ,
F_19 ( V_60 ) ) ;
}
}
static int
F_25 ( struct V_1 * V_1 ,
T_1 * V_62 , int V_63 ,
T_1 * V_64 , int V_65 )
{
T_2 V_66 = V_1 -> V_66 ;
struct V_42 * V_43 = V_1 -> V_2 . V_2 . V_43 ;
struct V_44 * V_45 = V_43 -> V_46 ;
T_2 V_67 = V_66 + 0x10 ;
T_2 V_68 = V_67 + 4 ;
int V_38 ;
int V_69 ;
T_2 V_70 ;
T_2 V_71 ;
int V_72 , V_73 ;
F_22 ( V_1 ) ;
if ( F_3 ( V_1 ) ) {
if ( F_26 ( V_43 ) || F_27 ( V_43 ) )
V_71 = 200 ;
else
V_71 = 225 ;
} else if ( F_28 ( V_43 ) )
V_71 = 62 ;
else
V_71 = F_18 ( V_43 ) / 2 ;
if ( F_26 ( V_43 ) )
V_73 = 3 ;
else
V_73 = 5 ;
for ( V_72 = 0 ; V_72 < 3 ; V_72 ++ ) {
V_70 = F_19 ( V_67 ) ;
if ( ( V_70 & V_74 ) == 0 )
break;
F_29 ( 1 ) ;
}
if ( V_72 == 3 ) {
F_23 ( 1 , L_3 ,
F_19 ( V_67 ) ) ;
return - V_75 ;
}
for ( V_72 = 0 ; V_72 < 5 ; V_72 ++ ) {
for ( V_38 = 0 ; V_38 < V_63 ; V_38 += 4 )
F_30 ( V_68 + V_38 ,
F_16 ( V_62 + V_38 , V_63 - V_38 ) ) ;
F_30 ( V_67 ,
V_74 |
V_76 |
( V_63 << V_77 ) |
( V_73 << V_78 ) |
( V_71 << V_79 ) |
V_80 |
V_81 |
V_82 ) ;
for (; ; ) {
V_70 = F_19 ( V_67 ) ;
if ( ( V_70 & V_74 ) == 0 )
break;
F_31 ( 100 ) ;
}
F_30 ( V_67 ,
V_70 |
V_80 |
V_81 |
V_82 ) ;
if ( V_70 & V_80 )
break;
}
if ( ( V_70 & V_80 ) == 0 ) {
F_32 ( L_4 , V_70 ) ;
return - V_75 ;
}
if ( V_70 & V_82 ) {
F_32 ( L_5 , V_70 ) ;
return - V_83 ;
}
if ( V_70 & V_81 ) {
F_24 ( L_6 , V_70 ) ;
return - V_84 ;
}
V_69 = ( ( V_70 & V_85 ) >>
V_77 ) ;
if ( V_69 > V_65 )
V_69 = V_65 ;
for ( V_38 = 0 ; V_38 < V_69 ; V_38 += 4 )
F_17 ( F_19 ( V_68 + V_38 ) ,
V_64 + V_38 , V_69 - V_38 ) ;
return V_69 ;
}
static int
F_33 ( struct V_1 * V_1 ,
T_3 V_86 , T_1 * V_62 , int V_63 )
{
int V_87 ;
T_1 V_88 [ 20 ] ;
int V_89 ;
T_1 V_90 ;
F_22 ( V_1 ) ;
if ( V_63 > 16 )
return - 1 ;
V_88 [ 0 ] = V_91 << 4 ;
V_88 [ 1 ] = V_86 >> 8 ;
V_88 [ 2 ] = V_86 & 0xff ;
V_88 [ 3 ] = V_63 - 1 ;
memcpy ( & V_88 [ 4 ] , V_62 , V_63 ) ;
V_89 = V_63 + 4 ;
for (; ; ) {
V_87 = F_25 ( V_1 , V_88 , V_89 , & V_90 , 1 ) ;
if ( V_87 < 0 )
return V_87 ;
if ( ( V_90 & V_92 ) == V_93 )
break;
else if ( ( V_90 & V_92 ) == V_94 )
F_31 ( 100 ) ;
else
return - V_83 ;
}
return V_63 ;
}
static int
F_34 ( struct V_1 * V_1 ,
T_3 V_86 , T_1 V_95 )
{
return F_33 ( V_1 , V_86 , & V_95 , 1 ) ;
}
static int
F_35 ( struct V_1 * V_1 ,
T_3 V_86 , T_1 * V_64 , int V_69 )
{
T_1 V_88 [ 4 ] ;
int V_89 ;
T_1 V_96 [ 20 ] ;
int V_97 ;
T_1 V_90 ;
int V_87 ;
F_22 ( V_1 ) ;
V_88 [ 0 ] = V_98 << 4 ;
V_88 [ 1 ] = V_86 >> 8 ;
V_88 [ 2 ] = V_86 & 0xff ;
V_88 [ 3 ] = V_69 - 1 ;
V_89 = 4 ;
V_97 = V_69 + 1 ;
for (; ; ) {
V_87 = F_25 ( V_1 , V_88 , V_89 ,
V_96 , V_97 ) ;
if ( V_87 == 0 )
return - V_99 ;
if ( V_87 < 0 )
return V_87 ;
V_90 = V_96 [ 0 ] ;
if ( ( V_90 & V_92 ) == V_93 ) {
memcpy ( V_64 , V_96 + 1 , V_87 - 1 ) ;
return V_87 - 1 ;
}
else if ( ( V_90 & V_92 ) == V_94 )
F_31 ( 100 ) ;
else
return - V_83 ;
}
}
static int
F_36 ( struct V_100 * V_101 , int V_24 ,
T_1 V_102 , T_1 * V_103 )
{
struct V_104 * V_105 = V_101 -> V_105 ;
struct V_1 * V_1 = F_5 ( V_101 ,
struct V_1 ,
V_101 ) ;
T_3 V_86 = V_105 -> V_86 ;
T_1 V_88 [ 5 ] ;
T_1 V_96 [ 2 ] ;
unsigned V_106 ;
int V_89 ;
int V_97 ;
int V_87 ;
F_22 ( V_1 ) ;
if ( V_24 & V_107 )
V_88 [ 0 ] = V_108 << 4 ;
else
V_88 [ 0 ] = V_109 << 4 ;
if ( ! ( V_24 & V_110 ) )
V_88 [ 0 ] |= V_111 << 4 ;
V_88 [ 1 ] = V_86 >> 8 ;
V_88 [ 2 ] = V_86 ;
switch ( V_24 ) {
case V_112 :
V_88 [ 3 ] = 0 ;
V_88 [ 4 ] = V_102 ;
V_89 = 5 ;
V_97 = 1 ;
break;
case V_107 :
V_88 [ 3 ] = 0 ;
V_89 = 4 ;
V_97 = 2 ;
break;
default:
V_89 = 3 ;
V_97 = 1 ;
break;
}
for ( V_106 = 0 ; V_106 < 5 ; V_106 ++ ) {
V_87 = F_25 ( V_1 ,
V_88 , V_89 ,
V_96 , V_97 ) ;
if ( V_87 < 0 ) {
F_24 ( L_7 , V_87 ) ;
return V_87 ;
}
switch ( V_96 [ 0 ] & V_92 ) {
case V_93 :
break;
case V_113 :
F_24 ( L_8 ) ;
return - V_114 ;
case V_94 :
F_31 ( 100 ) ;
continue;
default:
F_32 ( L_9 ,
V_96 [ 0 ] ) ;
return - V_114 ;
}
switch ( V_96 [ 0 ] & V_115 ) {
case V_116 :
if ( V_24 == V_107 ) {
* V_103 = V_96 [ 1 ] ;
}
return V_97 - 1 ;
case V_117 :
F_24 ( L_10 ) ;
return - V_114 ;
case V_118 :
F_24 ( L_11 ) ;
F_31 ( 100 ) ;
break;
default:
F_32 ( L_12 , V_96 [ 0 ] ) ;
return - V_114 ;
}
}
F_32 ( L_13 ) ;
return - V_114 ;
}
static int
F_37 ( struct V_1 * V_1 ,
struct V_119 * V_119 , const char * V_120 )
{
int V_87 ;
F_24 ( L_14 , V_120 ) ;
V_1 -> V_121 . V_122 = false ;
V_1 -> V_121 . V_86 = 0 ;
V_1 -> V_121 . V_123 = F_36 ;
memset ( & V_1 -> V_101 , '\0' , sizeof( V_1 -> V_101 ) ) ;
V_1 -> V_101 . V_124 = V_125 ;
V_1 -> V_101 . V_126 = V_127 ;
strncpy ( V_1 -> V_101 . V_120 , V_120 , sizeof( V_1 -> V_101 . V_120 ) - 1 ) ;
V_1 -> V_101 . V_120 [ sizeof( V_1 -> V_101 . V_120 ) - 1 ] = '\0' ;
V_1 -> V_101 . V_105 = & V_1 -> V_121 ;
V_1 -> V_101 . V_43 . V_128 = & V_119 -> V_2 . V_129 ;
F_38 ( V_1 ) ;
V_87 = F_39 ( & V_1 -> V_101 ) ;
F_40 ( V_1 , false ) ;
return V_87 ;
}
static bool
F_41 ( struct V_4 * V_5 , struct V_23 * V_24 ,
struct V_23 * V_130 )
{
struct V_42 * V_43 = V_5 -> V_43 ;
struct V_1 * V_1 = F_4 ( V_5 ) ;
int V_11 , clock ;
int V_14 = F_10 ( V_1 ) ;
int V_131 = F_11 ( V_1 ) == V_13 ? 1 : 0 ;
int V_20 = V_24 -> V_32 & V_33 ? 18 : 24 ;
static int V_132 [ 2 ] = { V_12 , V_13 } ;
if ( F_1 ( V_1 ) && V_1 -> V_27 ) {
F_42 ( V_1 -> V_27 , V_130 ) ;
F_43 ( V_43 , V_133 ,
V_24 , V_130 ) ;
V_24 -> clock = V_1 -> V_27 -> clock ;
}
for ( V_11 = 1 ; V_11 <= V_14 ; V_11 <<= 1 ) {
for ( clock = 0 ; clock <= V_131 ; clock ++ ) {
int V_134 = F_14 ( F_12 ( V_132 [ clock ] ) , V_11 ) ;
if ( F_13 ( V_24 -> clock , V_20 )
<= V_134 ) {
V_1 -> V_10 = V_132 [ clock ] ;
V_1 -> V_11 = V_11 ;
V_130 -> clock = F_12 ( V_1 -> V_10 ) ;
F_24 ( L_15
L_16 ,
V_1 -> V_10 , V_1 -> V_11 ,
V_130 -> clock ) ;
return true ;
}
}
}
return false ;
}
static void
F_44 ( T_2 * V_135 , T_2 * V_136 )
{
while ( * V_135 > 0xffffff || * V_136 > 0xffffff ) {
* V_135 >>= 1 ;
* V_136 >>= 1 ;
}
}
static void
F_45 ( int V_20 ,
int V_137 ,
int V_19 ,
int V_138 ,
struct V_139 * V_140 )
{
V_140 -> V_141 = 64 ;
V_140 -> V_142 = ( V_19 * V_20 ) >> 3 ;
V_140 -> V_143 = V_138 * V_137 ;
F_44 ( & V_140 -> V_142 , & V_140 -> V_143 ) ;
V_140 -> V_144 = V_19 ;
V_140 -> V_145 = V_138 ;
F_44 ( & V_140 -> V_144 , & V_140 -> V_145 ) ;
}
void
F_46 ( struct V_146 * V_147 , struct V_23 * V_24 ,
struct V_23 * V_130 )
{
struct V_42 * V_43 = V_147 -> V_43 ;
struct V_148 * V_149 = & V_43 -> V_149 ;
struct V_4 * V_5 ;
struct V_44 * V_45 = V_43 -> V_46 ;
struct V_150 * V_150 = F_47 ( V_147 ) ;
int V_11 = 4 ;
struct V_139 V_140 ;
int V_151 = V_150 -> V_151 ;
F_48 (encoder, &mode_config->encoder_list, head) {
struct V_1 * V_1 ;
if ( V_5 -> V_147 != V_147 )
continue;
V_1 = F_4 ( V_5 ) ;
if ( V_1 -> V_2 . type == V_152 ||
V_1 -> V_2 . type == V_3 )
{
V_11 = V_1 -> V_11 ;
break;
}
}
F_45 ( V_150 -> V_20 , V_11 ,
V_24 -> clock , V_130 -> clock , & V_140 ) ;
if ( F_28 ( V_43 ) ) {
F_30 ( F_49 ( V_151 ) ,
( ( V_140 . V_141 - 1 ) << V_153 ) |
V_140 . V_142 ) ;
F_30 ( F_50 ( V_151 ) , V_140 . V_143 ) ;
F_30 ( F_51 ( V_151 ) , V_140 . V_144 ) ;
F_30 ( F_52 ( V_151 ) , V_140 . V_145 ) ;
} else {
F_30 ( F_53 ( V_151 ) ,
( ( V_140 . V_141 - 1 ) << V_153 ) |
V_140 . V_142 ) ;
F_30 ( F_54 ( V_151 ) , V_140 . V_143 ) ;
F_30 ( F_55 ( V_151 ) , V_140 . V_144 ) ;
F_30 ( F_56 ( V_151 ) , V_140 . V_145 ) ;
}
}
static void
F_57 ( struct V_4 * V_5 , struct V_23 * V_24 ,
struct V_23 * V_130 )
{
struct V_42 * V_43 = V_5 -> V_43 ;
struct V_44 * V_45 = V_43 -> V_46 ;
struct V_1 * V_1 = F_4 ( V_5 ) ;
struct V_146 * V_147 = V_1 -> V_2 . V_2 . V_147 ;
struct V_150 * V_150 = F_47 ( V_147 ) ;
if ( F_1 ( V_1 ) ) {
if ( ! F_2 ( V_1 ) )
F_58 ( V_5 ) ;
else
F_59 ( V_5 ) ;
}
V_1 -> V_154 = F_19 ( V_1 -> V_66 ) & V_155 ;
V_1 -> V_154 |= V_156 | V_157 ;
V_1 -> V_154 |= V_156 | V_157 ;
switch ( V_1 -> V_11 ) {
case 1 :
V_1 -> V_154 |= V_158 ;
break;
case 2 :
V_1 -> V_154 |= V_159 ;
break;
case 4 :
V_1 -> V_154 |= V_160 ;
break;
}
if ( V_1 -> V_161 ) {
F_60 ( L_17 ,
F_61 ( V_150 -> V_151 ) ) ;
V_1 -> V_154 |= V_162 ;
F_62 ( V_5 , V_130 ) ;
}
memset ( V_1 -> V_163 , 0 , V_164 ) ;
V_1 -> V_163 [ 0 ] = V_1 -> V_10 ;
V_1 -> V_163 [ 1 ] = V_1 -> V_11 ;
V_1 -> V_163 [ 8 ] = V_165 ;
if ( V_1 -> V_15 [ V_166 ] >= 0x11 &&
( V_1 -> V_15 [ V_16 ] & V_167 ) ) {
V_1 -> V_163 [ 1 ] |= V_168 ;
}
if ( F_3 ( V_1 ) && F_27 ( V_43 ) ) {
if ( V_130 -> V_169 & V_170 )
V_1 -> V_154 |= V_171 ;
if ( V_130 -> V_169 & V_172 )
V_1 -> V_154 |= V_173 ;
V_1 -> V_154 |= V_174 ;
if ( V_1 -> V_163 [ 1 ] & V_168 )
V_1 -> V_154 |= V_175 ;
V_1 -> V_154 |= V_150 -> V_151 << 29 ;
V_1 -> V_154 |= V_176 ;
if ( V_130 -> clock < 200000 )
V_1 -> V_154 |= V_177 ;
else
V_1 -> V_154 |= V_178 ;
} else if ( ! F_63 ( V_43 ) || F_3 ( V_1 ) ) {
V_1 -> V_154 |= V_1 -> V_179 ;
if ( V_130 -> V_169 & V_170 )
V_1 -> V_154 |= V_171 ;
if ( V_130 -> V_169 & V_172 )
V_1 -> V_154 |= V_173 ;
V_1 -> V_154 |= V_180 ;
if ( V_1 -> V_163 [ 1 ] & V_168 )
V_1 -> V_154 |= V_175 ;
if ( V_150 -> V_151 == 1 )
V_1 -> V_154 |= V_181 ;
if ( F_3 ( V_1 ) ) {
V_1 -> V_154 |= V_176 ;
if ( V_130 -> clock < 200000 )
V_1 -> V_154 |= V_177 ;
else
V_1 -> V_154 |= V_178 ;
}
} else {
V_1 -> V_154 |= V_174 ;
}
}
static void F_64 ( struct V_1 * V_1 ,
T_4 V_182 ,
T_4 V_183 )
{
struct V_42 * V_43 = V_1 -> V_2 . V_2 . V_43 ;
struct V_44 * V_45 = V_43 -> V_46 ;
F_24 ( L_18 ,
V_182 , V_183 ,
F_19 ( V_58 ) ,
F_19 ( V_60 ) ) ;
if ( F_65 ( ( F_19 ( V_58 ) & V_182 ) == V_183 , 5000 , 10 ) ) {
F_32 ( L_19 ,
F_19 ( V_58 ) ,
F_19 ( V_60 ) ) ;
}
}
static void F_66 ( struct V_1 * V_1 )
{
F_24 ( L_20 ) ;
F_64 ( V_1 , V_184 , V_185 ) ;
}
static void F_67 ( struct V_1 * V_1 )
{
F_24 ( L_21 ) ;
F_64 ( V_1 , V_186 , V_187 ) ;
}
static void F_68 ( struct V_1 * V_1 )
{
F_24 ( L_22 ) ;
F_64 ( V_1 , V_188 , V_189 ) ;
}
static T_4 F_69 ( struct V_44 * V_45 )
{
T_4 V_190 = F_19 ( V_60 ) ;
V_190 &= ~ V_191 ;
V_190 |= V_192 ;
return V_190 ;
}
static void F_38 ( struct V_1 * V_1 )
{
struct V_42 * V_43 = V_1 -> V_2 . V_2 . V_43 ;
struct V_44 * V_45 = V_43 -> V_46 ;
T_4 V_193 ;
if ( ! F_1 ( V_1 ) )
return;
F_24 ( L_23 ) ;
F_23 ( V_1 -> V_194 ,
L_24 ) ;
V_1 -> V_194 = true ;
if ( F_21 ( V_1 ) ) {
F_24 ( L_25 ) ;
return;
}
if ( ! F_20 ( V_1 ) )
F_68 ( V_1 ) ;
V_193 = F_69 ( V_45 ) ;
V_193 |= V_61 ;
F_30 ( V_60 , V_193 ) ;
F_70 ( V_60 ) ;
F_24 ( L_26 ,
F_19 ( V_58 ) , F_19 ( V_60 ) ) ;
if ( ! F_20 ( V_1 ) ) {
F_24 ( L_27 ) ;
F_29 ( V_1 -> V_195 ) ;
}
}
static void F_71 ( struct V_1 * V_1 )
{
struct V_42 * V_43 = V_1 -> V_2 . V_2 . V_43 ;
struct V_44 * V_45 = V_43 -> V_46 ;
T_4 V_193 ;
if ( ! V_1 -> V_194 && F_21 ( V_1 ) ) {
V_193 = F_69 ( V_45 ) ;
V_193 &= ~ V_61 ;
F_30 ( V_60 , V_193 ) ;
F_70 ( V_60 ) ;
F_24 ( L_26 ,
F_19 ( V_58 ) , F_19 ( V_60 ) ) ;
F_29 ( V_1 -> V_196 ) ;
}
}
static void F_72 ( struct V_197 * V_198 )
{
struct V_1 * V_1 = F_5 ( F_73 ( V_198 ) ,
struct V_1 , V_199 ) ;
struct V_42 * V_43 = V_1 -> V_2 . V_2 . V_43 ;
F_74 ( & V_43 -> V_149 . V_200 ) ;
F_71 ( V_1 ) ;
F_75 ( & V_43 -> V_149 . V_200 ) ;
}
static void F_40 ( struct V_1 * V_1 , bool V_201 )
{
if ( ! F_1 ( V_1 ) )
return;
F_24 ( L_28 , V_1 -> V_194 ) ;
F_23 ( ! V_1 -> V_194 , L_29 ) ;
V_1 -> V_194 = false ;
if ( V_201 ) {
F_71 ( V_1 ) ;
} else {
F_76 ( & V_1 -> V_199 ,
F_77 ( V_1 -> V_202 * 5 ) ) ;
}
}
static void F_78 ( struct V_1 * V_1 )
{
struct V_42 * V_43 = V_1 -> V_2 . V_2 . V_43 ;
struct V_44 * V_45 = V_43 -> V_46 ;
T_4 V_193 ;
if ( ! F_1 ( V_1 ) )
return;
F_24 ( L_30 ) ;
if ( F_20 ( V_1 ) ) {
F_24 ( L_31 ) ;
return;
}
F_68 ( V_1 ) ;
V_193 = F_69 ( V_45 ) ;
if ( F_79 ( V_43 ) ) {
V_193 &= ~ V_203 ;
F_30 ( V_60 , V_193 ) ;
F_70 ( V_60 ) ;
}
V_193 |= V_204 ;
if ( ! F_79 ( V_43 ) )
V_193 |= V_203 ;
F_30 ( V_60 , V_193 ) ;
F_70 ( V_60 ) ;
F_66 ( V_1 ) ;
if ( F_79 ( V_43 ) ) {
V_193 |= V_203 ;
F_30 ( V_60 , V_193 ) ;
F_70 ( V_60 ) ;
}
}
static void F_80 ( struct V_1 * V_1 )
{
struct V_42 * V_43 = V_1 -> V_2 . V_2 . V_43 ;
struct V_44 * V_45 = V_43 -> V_46 ;
T_4 V_193 ;
if ( ! F_1 ( V_1 ) )
return;
F_24 ( L_32 ) ;
F_23 ( V_1 -> V_194 , L_33 ) ;
V_193 = F_69 ( V_45 ) ;
V_193 &= ~ ( V_204 | V_61 | V_203 | V_205 ) ;
F_30 ( V_60 , V_193 ) ;
F_70 ( V_60 ) ;
F_67 ( V_1 ) ;
}
static void F_81 ( struct V_1 * V_1 )
{
struct V_42 * V_43 = V_1 -> V_2 . V_2 . V_43 ;
struct V_44 * V_45 = V_43 -> V_46 ;
T_4 V_193 ;
if ( ! F_1 ( V_1 ) )
return;
F_24 ( L_34 ) ;
F_29 ( V_1 -> V_206 ) ;
V_193 = F_69 ( V_45 ) ;
V_193 |= V_205 ;
F_30 ( V_60 , V_193 ) ;
F_70 ( V_60 ) ;
}
static void F_82 ( struct V_1 * V_1 )
{
struct V_42 * V_43 = V_1 -> V_2 . V_2 . V_43 ;
struct V_44 * V_45 = V_43 -> V_46 ;
T_4 V_193 ;
if ( ! F_1 ( V_1 ) )
return;
F_24 ( L_34 ) ;
V_193 = F_69 ( V_45 ) ;
V_193 &= ~ V_205 ;
F_30 ( V_60 , V_193 ) ;
F_70 ( V_60 ) ;
F_29 ( V_1 -> V_207 ) ;
}
static void F_58 ( struct V_4 * V_5 )
{
struct V_42 * V_43 = V_5 -> V_43 ;
struct V_44 * V_45 = V_43 -> V_46 ;
T_4 V_208 ;
F_24 ( L_34 ) ;
V_208 = F_19 ( V_209 ) ;
V_208 |= V_176 ;
F_30 ( V_209 , V_208 ) ;
F_70 ( V_209 ) ;
F_31 ( 200 ) ;
}
static void F_59 ( struct V_4 * V_5 )
{
struct V_42 * V_43 = V_5 -> V_43 ;
struct V_44 * V_45 = V_43 -> V_46 ;
T_4 V_208 ;
V_208 = F_19 ( V_209 ) ;
V_208 &= ~ V_176 ;
F_30 ( V_209 , V_208 ) ;
F_70 ( V_209 ) ;
F_31 ( 200 ) ;
}
static void F_83 ( struct V_1 * V_1 , int V_24 )
{
int V_87 , V_38 ;
if ( V_1 -> V_15 [ V_166 ] < 0x11 )
return;
if ( V_24 != V_210 ) {
V_87 = F_34 ( V_1 , V_211 ,
V_212 ) ;
if ( V_87 != 1 )
F_60 ( L_35 ) ;
} else {
for ( V_38 = 0 ; V_38 < 3 ; V_38 ++ ) {
V_87 = F_34 ( V_1 ,
V_211 ,
V_213 ) ;
if ( V_87 == 1 )
break;
F_29 ( 1 ) ;
}
}
}
static void F_84 ( struct V_4 * V_5 )
{
struct V_1 * V_1 = F_4 ( V_5 ) ;
F_82 ( V_1 ) ;
F_80 ( V_1 ) ;
F_38 ( V_1 ) ;
F_83 ( V_1 , V_210 ) ;
F_85 ( V_1 ) ;
F_40 ( V_1 , false ) ;
}
static void F_86 ( struct V_4 * V_5 )
{
struct V_1 * V_1 = F_4 ( V_5 ) ;
struct V_42 * V_43 = V_5 -> V_43 ;
struct V_150 * V_150 = F_47 ( V_1 -> V_2 . V_2 . V_147 ) ;
F_38 ( V_1 ) ;
F_83 ( V_1 , V_210 ) ;
F_87 ( V_1 ) ;
F_78 ( V_1 ) ;
F_40 ( V_1 , true ) ;
F_88 ( V_1 ) ;
F_81 ( V_1 ) ;
V_1 -> V_214 = V_210 ;
if ( F_63 ( V_43 ) )
F_89 ( V_43 , V_150 -> V_151 ) ;
}
static void
F_90 ( struct V_4 * V_5 , int V_24 )
{
struct V_1 * V_1 = F_4 ( V_5 ) ;
struct V_42 * V_43 = V_5 -> V_43 ;
struct V_44 * V_45 = V_43 -> V_46 ;
T_2 V_215 = F_19 ( V_1 -> V_66 ) ;
if ( V_24 != V_210 ) {
F_82 ( V_1 ) ;
F_80 ( V_1 ) ;
F_38 ( V_1 ) ;
F_83 ( V_1 , V_24 ) ;
F_85 ( V_1 ) ;
F_40 ( V_1 , false ) ;
if ( F_3 ( V_1 ) )
F_59 ( V_5 ) ;
} else {
if ( F_3 ( V_1 ) )
F_58 ( V_5 ) ;
F_38 ( V_1 ) ;
F_83 ( V_1 , V_24 ) ;
if ( ! ( V_215 & V_216 ) ) {
F_87 ( V_1 ) ;
F_78 ( V_1 ) ;
F_40 ( V_1 , true ) ;
F_88 ( V_1 ) ;
} else
F_40 ( V_1 , false ) ;
F_81 ( V_1 ) ;
}
V_1 -> V_214 = V_24 ;
}
static bool
F_91 ( struct V_1 * V_1 , T_3 V_86 ,
T_1 * V_64 , int V_69 )
{
int V_87 , V_38 ;
for ( V_38 = 0 ; V_38 < 3 ; V_38 ++ ) {
V_87 = F_35 ( V_1 , V_86 , V_64 ,
V_69 ) ;
if ( V_87 == V_69 )
return true ;
F_29 ( 1 ) ;
}
return false ;
}
static bool
F_92 ( struct V_1 * V_1 , T_1 V_217 [ V_218 ] )
{
return F_91 ( V_1 ,
V_219 ,
V_217 ,
V_218 ) ;
}
static T_1
F_93 ( T_1 V_217 [ V_218 ] ,
int V_220 )
{
return V_217 [ V_220 - V_219 ] ;
}
static T_1
F_94 ( T_1 V_221 [ 2 ] ,
int V_222 )
{
int V_223 = ( ( V_222 & 1 ) ?
V_224 :
V_225 ) ;
T_1 V_226 = V_221 [ V_222 >> 1 ] ;
return ( ( V_226 >> V_223 ) & 3 ) << V_227 ;
}
static T_1
F_95 ( T_1 V_221 [ 2 ] ,
int V_222 )
{
int V_223 = ( ( V_222 & 1 ) ?
V_228 :
V_229 ) ;
T_1 V_226 = V_221 [ V_222 >> 1 ] ;
return ( ( V_226 >> V_223 ) & 3 ) << V_230 ;
}
static T_1
F_96 ( struct V_1 * V_1 )
{
struct V_42 * V_43 = V_1 -> V_2 . V_2 . V_43 ;
if ( F_27 ( V_43 ) && F_3 ( V_1 ) )
return V_231 ;
else if ( F_63 ( V_43 ) && ! F_3 ( V_1 ) )
return V_232 ;
else
return V_231 ;
}
static T_1
F_97 ( struct V_1 * V_1 , T_1 V_233 )
{
struct V_42 * V_43 = V_1 -> V_2 . V_2 . V_43 ;
if ( F_27 ( V_43 ) && F_3 ( V_1 ) ) {
switch ( V_233 & V_234 ) {
case V_235 :
return V_236 ;
case V_237 :
case V_231 :
return V_238 ;
default:
return V_239 ;
}
} else {
switch ( V_233 & V_234 ) {
case V_235 :
return V_236 ;
case V_237 :
return V_236 ;
case V_231 :
return V_238 ;
case V_232 :
default:
return V_239 ;
}
}
}
static void
F_98 ( struct V_1 * V_1 , T_1 V_217 [ V_218 ] )
{
T_1 V_39 = 0 ;
T_1 V_240 = 0 ;
int V_222 ;
T_1 * V_221 = V_217 + ( V_241 - V_219 ) ;
T_1 V_242 ;
T_1 V_243 ;
for ( V_222 = 0 ; V_222 < V_1 -> V_11 ; V_222 ++ ) {
T_1 V_244 = F_94 ( V_221 , V_222 ) ;
T_1 V_245 = F_95 ( V_221 , V_222 ) ;
if ( V_244 > V_39 )
V_39 = V_244 ;
if ( V_245 > V_240 )
V_240 = V_245 ;
}
V_242 = F_96 ( V_1 ) ;
if ( V_39 >= V_242 )
V_39 = V_242 | V_246 ;
V_243 = F_97 ( V_1 , V_39 ) ;
if ( V_240 >= V_243 )
V_240 = V_243 | V_247 ;
for ( V_222 = 0 ; V_222 < 4 ; V_222 ++ )
V_1 -> V_248 [ V_222 ] = V_39 | V_240 ;
}
static T_2
F_99 ( T_1 V_248 )
{
T_2 V_249 = 0 ;
switch ( V_248 & V_234 ) {
case V_235 :
default:
V_249 |= V_156 ;
break;
case V_237 :
V_249 |= V_250 ;
break;
case V_231 :
V_249 |= V_251 ;
break;
case V_232 :
V_249 |= V_252 ;
break;
}
switch ( V_248 & V_253 ) {
case V_239 :
default:
V_249 |= V_157 ;
break;
case V_238 :
V_249 |= V_254 ;
break;
case V_236 :
V_249 |= V_255 ;
break;
case V_256 :
V_249 |= V_257 ;
break;
}
return V_249 ;
}
static T_2
F_100 ( T_1 V_248 )
{
int V_249 = V_248 & ( V_234 |
V_253 ) ;
switch ( V_249 ) {
case V_235 | V_239 :
case V_237 | V_239 :
return V_258 ;
case V_235 | V_238 :
return V_259 ;
case V_235 | V_236 :
case V_237 | V_236 :
return V_260 ;
case V_237 | V_238 :
case V_231 | V_238 :
return V_261 ;
case V_231 | V_239 :
case V_232 | V_239 :
return V_262 ;
default:
F_24 ( L_36
L_37 , V_249 ) ;
return V_258 ;
}
}
static T_2
F_101 ( T_1 V_248 )
{
int V_249 = V_248 & ( V_234 |
V_253 ) ;
switch ( V_249 ) {
case V_235 | V_239 :
return V_263 ;
case V_235 | V_238 :
return V_264 ;
case V_235 | V_236 :
return V_265 ;
case V_237 | V_239 :
return V_266 ;
case V_237 | V_238 :
return V_267 ;
case V_231 | V_239 :
return V_268 ;
case V_231 | V_238 :
return V_269 ;
default:
F_24 ( L_36
L_37 , V_249 ) ;
return V_270 ;
}
}
static T_1
F_102 ( T_1 V_217 [ V_218 ] ,
int V_222 )
{
int V_223 = ( V_222 & 1 ) * 4 ;
T_1 V_226 = V_217 [ V_222 >> 1 ] ;
return ( V_226 >> V_223 ) & 0xf ;
}
static bool
F_103 ( T_1 V_217 [ V_218 ] , int V_11 )
{
int V_222 ;
T_1 V_271 ;
for ( V_222 = 0 ; V_222 < V_11 ; V_222 ++ ) {
V_271 = F_102 ( V_217 , V_222 ) ;
if ( ( V_271 & V_272 ) == 0 )
return false ;
}
return true ;
}
static bool
F_104 ( struct V_1 * V_1 , T_1 V_217 [ V_218 ] )
{
T_1 V_273 ;
T_1 V_271 ;
int V_222 ;
V_273 = F_93 ( V_217 ,
V_274 ) ;
if ( ( V_273 & V_275 ) == 0 )
return false ;
for ( V_222 = 0 ; V_222 < V_1 -> V_11 ; V_222 ++ ) {
V_271 = F_102 ( V_217 , V_222 ) ;
if ( ( V_271 & V_276 ) != V_276 )
return false ;
}
return true ;
}
static bool
F_105 ( struct V_1 * V_1 ,
T_2 V_277 ,
T_1 V_278 )
{
struct V_42 * V_43 = V_1 -> V_2 . V_2 . V_43 ;
struct V_44 * V_45 = V_43 -> V_46 ;
int V_87 ;
F_30 ( V_1 -> V_66 , V_277 ) ;
F_70 ( V_1 -> V_66 ) ;
F_34 ( V_1 ,
V_279 ,
V_278 ) ;
V_87 = F_33 ( V_1 ,
V_280 ,
V_1 -> V_248 ,
V_1 -> V_11 ) ;
if ( V_87 != V_1 -> V_11 )
return false ;
return true ;
}
static void
F_87 ( struct V_1 * V_1 )
{
struct V_42 * V_43 = V_1 -> V_2 . V_2 . V_43 ;
struct V_44 * V_45 = V_43 -> V_46 ;
struct V_150 * V_150 = F_47 ( V_1 -> V_2 . V_2 . V_147 ) ;
int V_38 ;
T_1 V_281 ;
bool V_282 = false ;
int V_283 , V_284 ;
T_4 V_285 ;
T_2 V_154 = V_1 -> V_154 ;
if ( ! F_63 ( V_43 ) ) {
F_30 ( V_1 -> V_66 , V_1 -> V_154 ) ;
F_70 ( V_1 -> V_66 ) ;
F_106 ( V_43 , V_150 -> V_151 ) ;
}
F_33 ( V_1 , V_286 ,
V_1 -> V_163 ,
V_164 ) ;
V_154 |= V_216 ;
if ( F_63 ( V_43 ) && ( F_27 ( V_43 ) || ! F_3 ( V_1 ) ) )
V_154 &= ~ V_287 ;
else
V_154 &= ~ V_288 ;
memset ( V_1 -> V_248 , 0 , 4 ) ;
V_281 = 0xff ;
V_283 = 0 ;
V_284 = 0 ;
V_282 = false ;
for (; ; ) {
T_1 V_217 [ V_218 ] ;
T_2 V_249 ;
if ( F_27 ( V_43 ) && F_3 ( V_1 ) ) {
V_249 = F_101 ( V_1 -> V_248 [ 0 ] ) ;
V_154 = ( V_154 & ~ V_289 ) | V_249 ;
} else if ( F_26 ( V_43 ) && F_3 ( V_1 ) ) {
V_249 = F_100 ( V_1 -> V_248 [ 0 ] ) ;
V_154 = ( V_154 & ~ V_290 ) | V_249 ;
} else {
V_249 = F_99 ( V_1 -> V_248 [ 0 ] ) ;
F_24 ( L_38 , V_249 ) ;
V_154 = ( V_154 & ~ ( V_291 | V_292 ) ) | V_249 ;
}
if ( F_63 ( V_43 ) && ( F_27 ( V_43 ) || ! F_3 ( V_1 ) ) )
V_285 = V_154 | V_293 ;
else
V_285 = V_154 | V_294 ;
if ( ! F_105 ( V_1 , V_285 ,
V_295 |
V_296 ) )
break;
F_31 ( 100 ) ;
if ( ! F_92 ( V_1 , V_217 ) ) {
F_32 ( L_39 ) ;
break;
}
if ( F_103 ( V_217 , V_1 -> V_11 ) ) {
F_24 ( L_40 ) ;
V_282 = true ;
break;
}
for ( V_38 = 0 ; V_38 < V_1 -> V_11 ; V_38 ++ )
if ( ( V_1 -> V_248 [ V_38 ] & V_246 ) == 0 )
break;
if ( V_38 == V_1 -> V_11 ) {
++ V_284 ;
if ( V_284 == 5 ) {
F_24 ( L_41 ) ;
break;
}
memset ( V_1 -> V_248 , 0 , 4 ) ;
V_283 = 0 ;
continue;
}
if ( ( V_1 -> V_248 [ 0 ] & V_234 ) == V_281 ) {
++ V_283 ;
if ( V_283 == 5 ) {
F_24 ( L_42 ) ;
break;
}
} else
V_283 = 0 ;
V_281 = V_1 -> V_248 [ 0 ] & V_234 ;
F_98 ( V_1 , V_217 ) ;
}
V_1 -> V_154 = V_154 ;
}
static void
F_88 ( struct V_1 * V_1 )
{
struct V_42 * V_43 = V_1 -> V_2 . V_2 . V_43 ;
struct V_44 * V_45 = V_43 -> V_46 ;
bool V_297 = false ;
int V_298 , V_299 ;
T_4 V_285 ;
T_2 V_154 = V_1 -> V_154 ;
V_298 = 0 ;
V_299 = 0 ;
V_297 = false ;
for (; ; ) {
T_2 V_249 ;
T_1 V_217 [ V_218 ] ;
if ( V_299 > 5 ) {
F_32 ( L_43 ) ;
F_85 ( V_1 ) ;
break;
}
if ( F_27 ( V_43 ) && F_3 ( V_1 ) ) {
V_249 = F_101 ( V_1 -> V_248 [ 0 ] ) ;
V_154 = ( V_154 & ~ V_289 ) | V_249 ;
} else if ( F_26 ( V_43 ) && F_3 ( V_1 ) ) {
V_249 = F_100 ( V_1 -> V_248 [ 0 ] ) ;
V_154 = ( V_154 & ~ V_290 ) | V_249 ;
} else {
V_249 = F_99 ( V_1 -> V_248 [ 0 ] ) ;
V_154 = ( V_154 & ~ ( V_291 | V_292 ) ) | V_249 ;
}
if ( F_63 ( V_43 ) && ( F_27 ( V_43 ) || ! F_3 ( V_1 ) ) )
V_285 = V_154 | V_300 ;
else
V_285 = V_154 | V_301 ;
if ( ! F_105 ( V_1 , V_285 ,
V_302 |
V_296 ) )
break;
F_31 ( 400 ) ;
if ( ! F_92 ( V_1 , V_217 ) )
break;
if ( ! F_103 ( V_217 , V_1 -> V_11 ) ) {
F_87 ( V_1 ) ;
V_299 ++ ;
continue;
}
if ( F_104 ( V_1 , V_217 ) ) {
V_297 = true ;
break;
}
if ( V_298 > 5 ) {
F_85 ( V_1 ) ;
F_87 ( V_1 ) ;
V_298 = 0 ;
V_299 ++ ;
continue;
}
F_98 ( V_1 , V_217 ) ;
++ V_298 ;
}
if ( F_63 ( V_43 ) && ( F_27 ( V_43 ) || ! F_3 ( V_1 ) ) )
V_285 = V_154 | V_174 ;
else
V_285 = V_154 | V_180 ;
F_30 ( V_1 -> V_66 , V_285 ) ;
F_70 ( V_1 -> V_66 ) ;
F_34 ( V_1 ,
V_279 , V_303 ) ;
}
static void
F_85 ( struct V_1 * V_1 )
{
struct V_42 * V_43 = V_1 -> V_2 . V_2 . V_43 ;
struct V_44 * V_45 = V_43 -> V_46 ;
T_2 V_154 = V_1 -> V_154 ;
if ( ( F_19 ( V_1 -> V_66 ) & V_216 ) == 0 )
return;
F_24 ( L_34 ) ;
if ( F_1 ( V_1 ) ) {
V_154 &= ~ V_176 ;
F_30 ( V_1 -> V_66 , V_154 ) ;
F_70 ( V_1 -> V_66 ) ;
F_31 ( 100 ) ;
}
if ( F_63 ( V_43 ) && ( F_27 ( V_43 ) || ! F_3 ( V_1 ) ) ) {
V_154 &= ~ V_287 ;
F_30 ( V_1 -> V_66 , V_154 | V_304 ) ;
} else {
V_154 &= ~ V_288 ;
F_30 ( V_1 -> V_66 , V_154 | V_305 ) ;
}
F_70 ( V_1 -> V_66 ) ;
F_29 ( 17 ) ;
if ( F_1 ( V_1 ) ) {
if ( F_63 ( V_43 ) && ( F_27 ( V_43 ) || ! F_3 ( V_1 ) ) )
V_154 |= V_174 ;
else
V_154 |= V_180 ;
}
if ( ! F_63 ( V_43 ) &&
F_19 ( V_1 -> V_66 ) & V_181 ) {
struct V_146 * V_147 = V_1 -> V_2 . V_2 . V_147 ;
V_154 &= ~ V_181 ;
F_30 ( V_1 -> V_66 , V_154 ) ;
if ( V_147 == NULL ) {
F_70 ( V_1 -> V_66 ) ;
F_29 ( 50 ) ;
} else
F_106 ( V_43 , F_47 ( V_147 ) -> V_151 ) ;
}
V_154 &= ~ V_162 ;
F_30 ( V_1 -> V_66 , V_154 & ~ V_216 ) ;
F_70 ( V_1 -> V_66 ) ;
F_29 ( V_1 -> V_196 ) ;
}
static bool
F_107 ( struct V_1 * V_1 )
{
if ( F_91 ( V_1 , 0x000 , V_1 -> V_15 ,
sizeof( V_1 -> V_15 ) ) &&
( V_1 -> V_15 [ V_166 ] != 0 ) ) {
return true ;
}
return false ;
}
static bool
F_108 ( struct V_1 * V_1 , T_5 * V_306 )
{
int V_87 ;
V_87 = F_91 ( V_1 ,
V_307 ,
V_306 , 1 ) ;
if ( ! V_87 )
return false ;
return true ;
}
static void
F_109 ( struct V_1 * V_1 )
{
F_34 ( V_1 , V_308 , V_309 ) ;
}
static void
F_110 ( struct V_1 * V_1 )
{
T_5 V_306 ;
T_5 V_217 [ V_218 ] ;
if ( V_1 -> V_214 != V_210 )
return;
if ( ! V_1 -> V_2 . V_2 . V_147 )
return;
if ( ! F_92 ( V_1 , V_217 ) ) {
F_85 ( V_1 ) ;
return;
}
if ( ! F_107 ( V_1 ) ) {
F_85 ( V_1 ) ;
return;
}
if ( V_1 -> V_15 [ V_166 ] >= 0x11 &&
F_108 ( V_1 , & V_306 ) ) {
F_34 ( V_1 ,
V_307 ,
V_306 ) ;
if ( V_306 & V_310 )
F_109 ( V_1 ) ;
if ( V_306 & ( V_311 | V_312 ) )
F_60 ( L_44 ) ;
}
if ( ! F_104 ( V_1 , V_217 ) ) {
F_24 ( L_45 ,
F_111 ( & V_1 -> V_2 . V_2 ) ) ;
F_87 ( V_1 ) ;
F_88 ( V_1 ) ;
}
}
static enum V_313
F_112 ( struct V_1 * V_1 )
{
if ( F_107 ( V_1 ) )
return V_314 ;
return V_315 ;
}
static enum V_313
F_113 ( struct V_1 * V_1 )
{
enum V_313 V_70 ;
if ( F_1 ( V_1 ) ) {
V_70 = F_114 ( V_1 -> V_2 . V_2 . V_43 ) ;
if ( V_70 == V_316 )
V_70 = V_314 ;
return V_70 ;
}
return F_112 ( V_1 ) ;
}
static enum V_313
F_115 ( struct V_1 * V_1 )
{
struct V_42 * V_43 = V_1 -> V_2 . V_2 . V_43 ;
struct V_44 * V_45 = V_43 -> V_46 ;
T_2 V_317 , V_318 ;
switch ( V_1 -> V_66 ) {
case V_319 :
V_318 = V_320 ;
break;
case V_321 :
V_318 = V_322 ;
break;
case V_323 :
V_318 = V_324 ;
break;
default:
return V_316 ;
}
V_317 = F_19 ( V_325 ) ;
if ( ( V_317 & V_318 ) == 0 )
return V_315 ;
return F_112 ( V_1 ) ;
}
static struct V_326 *
F_116 ( struct V_6 * V_7 , struct V_100 * V_101 )
{
struct V_1 * V_1 = F_6 ( V_7 ) ;
struct V_326 * V_326 ;
F_38 ( V_1 ) ;
V_326 = F_117 ( V_7 , V_101 ) ;
F_40 ( V_1 , false ) ;
return V_326 ;
}
static int
F_118 ( struct V_6 * V_7 , struct V_100 * V_101 )
{
struct V_1 * V_1 = F_6 ( V_7 ) ;
int V_87 ;
F_38 ( V_1 ) ;
V_87 = F_119 ( V_7 , V_101 ) ;
F_40 ( V_1 , false ) ;
return V_87 ;
}
static enum V_313
F_120 ( struct V_6 * V_7 , bool V_327 )
{
struct V_1 * V_1 = F_6 ( V_7 ) ;
struct V_42 * V_43 = V_1 -> V_2 . V_2 . V_43 ;
enum V_313 V_70 ;
struct V_326 * V_326 = NULL ;
V_1 -> V_161 = false ;
if ( F_28 ( V_43 ) )
V_70 = F_113 ( V_1 ) ;
else
V_70 = F_115 ( V_1 ) ;
F_24 ( L_46 ,
V_1 -> V_15 [ 0 ] , V_1 -> V_15 [ 1 ] , V_1 -> V_15 [ 2 ] ,
V_1 -> V_15 [ 3 ] , V_1 -> V_15 [ 4 ] , V_1 -> V_15 [ 5 ] ,
V_1 -> V_15 [ 6 ] , V_1 -> V_15 [ 7 ] ) ;
if ( V_70 != V_314 )
return V_70 ;
if ( V_1 -> V_328 ) {
V_1 -> V_161 = V_1 -> V_328 > 0 ;
} else {
V_326 = F_116 ( V_7 , & V_1 -> V_101 ) ;
if ( V_326 ) {
V_1 -> V_161 = F_121 ( V_326 ) ;
V_7 -> V_329 . V_330 = NULL ;
F_122 ( V_326 ) ;
}
}
return V_314 ;
}
static int F_123 ( struct V_6 * V_7 )
{
struct V_1 * V_1 = F_6 ( V_7 ) ;
struct V_42 * V_43 = V_1 -> V_2 . V_2 . V_43 ;
struct V_44 * V_45 = V_43 -> V_46 ;
int V_87 ;
V_87 = F_118 ( V_7 , & V_1 -> V_101 ) ;
if ( V_87 ) {
if ( F_1 ( V_1 ) && ! V_1 -> V_27 ) {
struct V_23 * V_331 ;
F_48 (newmode, &connector->probed_modes,
head) {
if ( ( V_331 -> type & V_332 ) ) {
V_1 -> V_27 =
F_124 ( V_43 , V_331 ) ;
break;
}
}
}
return V_87 ;
}
if ( F_1 ( V_1 ) ) {
if ( V_1 -> V_27 == NULL && V_45 -> V_333 != NULL ) {
V_1 -> V_27 =
F_124 ( V_43 , V_45 -> V_333 ) ;
if ( V_1 -> V_27 ) {
V_1 -> V_27 -> type |=
V_332 ;
}
}
if ( V_1 -> V_27 ) {
struct V_23 * V_24 ;
V_24 = F_124 ( V_43 , V_1 -> V_27 ) ;
F_125 ( V_7 , V_24 ) ;
return 1 ;
}
}
return 0 ;
}
static bool
F_126 ( struct V_6 * V_7 )
{
struct V_1 * V_1 = F_6 ( V_7 ) ;
struct V_326 * V_326 ;
bool V_161 = false ;
V_326 = F_116 ( V_7 , & V_1 -> V_101 ) ;
if ( V_326 ) {
V_161 = F_121 ( V_326 ) ;
V_7 -> V_329 . V_330 = NULL ;
F_122 ( V_326 ) ;
}
return V_161 ;
}
static int
F_127 ( struct V_6 * V_7 ,
struct V_334 * V_335 ,
T_6 V_336 )
{
struct V_44 * V_45 = V_7 -> V_43 -> V_46 ;
struct V_1 * V_1 = F_6 ( V_7 ) ;
int V_87 ;
V_87 = F_128 ( V_7 , V_335 , V_336 ) ;
if ( V_87 )
return V_87 ;
if ( V_335 == V_45 -> V_337 ) {
int V_38 = V_336 ;
bool V_161 ;
if ( V_38 == V_1 -> V_328 )
return 0 ;
V_1 -> V_328 = V_38 ;
if ( V_38 == 0 )
V_161 = F_126 ( V_7 ) ;
else
V_161 = V_38 > 0 ;
if ( V_161 == V_1 -> V_161 )
return 0 ;
V_1 -> V_161 = V_161 ;
goto V_338;
}
if ( V_335 == V_45 -> V_339 ) {
if ( V_336 == ! ! V_1 -> V_179 )
return 0 ;
V_1 -> V_179 = V_336 ? V_340 : 0 ;
goto V_338;
}
return - V_341 ;
V_338:
if ( V_1 -> V_2 . V_2 . V_147 ) {
struct V_146 * V_147 = V_1 -> V_2 . V_2 . V_147 ;
F_129 ( V_147 , & V_147 -> V_24 ,
V_147 -> V_342 , V_147 -> V_343 ,
V_147 -> V_344 ) ;
}
return 0 ;
}
static void
F_130 ( struct V_6 * V_7 )
{
struct V_42 * V_43 = V_7 -> V_43 ;
if ( F_131 ( V_43 ) )
F_132 ( V_43 ) ;
F_133 ( V_7 ) ;
F_134 ( V_7 ) ;
F_122 ( V_7 ) ;
}
static void F_135 ( struct V_4 * V_5 )
{
struct V_1 * V_1 = F_4 ( V_5 ) ;
F_136 ( & V_1 -> V_101 ) ;
F_137 ( V_5 ) ;
if ( F_1 ( V_1 ) ) {
F_138 ( & V_1 -> V_199 ) ;
F_71 ( V_1 ) ;
}
F_122 ( V_1 ) ;
}
static void
F_139 ( struct V_8 * V_8 )
{
struct V_1 * V_1 = F_5 ( V_8 , struct V_1 , V_2 ) ;
F_110 ( V_1 ) ;
}
int
F_140 ( struct V_146 * V_147 )
{
struct V_42 * V_43 = V_147 -> V_43 ;
struct V_148 * V_149 = & V_43 -> V_149 ;
struct V_4 * V_5 ;
F_48 (encoder, &mode_config->encoder_list, head) {
struct V_1 * V_1 ;
if ( V_5 -> V_147 != V_147 )
continue;
V_1 = F_4 ( V_5 ) ;
if ( V_1 -> V_2 . type == V_152 ||
V_1 -> V_2 . type == V_3 )
return V_1 -> V_66 ;
}
return - 1 ;
}
bool F_131 ( struct V_42 * V_43 )
{
struct V_44 * V_45 = V_43 -> V_46 ;
struct V_345 * V_346 ;
int V_38 ;
if ( ! V_45 -> V_347 )
return false ;
for ( V_38 = 0 ; V_38 < V_45 -> V_347 ; V_38 ++ ) {
V_346 = V_45 -> V_348 + V_38 ;
if ( V_346 -> V_349 == V_350 &&
V_346 -> V_351 == V_352 )
return true ;
}
return false ;
}
static void
F_141 ( struct V_1 * V_1 , struct V_6 * V_7 )
{
F_142 ( V_7 ) ;
F_143 ( V_7 ) ;
}
void
F_144 ( struct V_42 * V_43 , int V_66 )
{
struct V_44 * V_45 = V_43 -> V_46 ;
struct V_6 * V_7 ;
struct V_1 * V_1 ;
struct V_8 * V_8 ;
struct V_119 * V_119 ;
const char * V_120 = NULL ;
int type ;
V_1 = F_145 ( sizeof( struct V_1 ) , V_353 ) ;
if ( ! V_1 )
return;
V_1 -> V_66 = V_66 ;
V_1 -> V_214 = - 1 ;
V_119 = F_145 ( sizeof( struct V_119 ) , V_353 ) ;
if ( ! V_119 ) {
F_122 ( V_1 ) ;
return;
}
V_8 = & V_1 -> V_2 ;
if ( F_28 ( V_43 ) && V_66 == V_354 )
if ( F_131 ( V_43 ) )
V_1 -> F_2 = true ;
if ( V_66 == V_209 || F_2 ( V_1 ) ) {
type = V_355 ;
V_8 -> type = V_3 ;
} else {
type = V_356 ;
V_8 -> type = V_152 ;
}
V_7 = & V_119 -> V_2 ;
F_146 ( V_43 , V_7 , & V_357 , type ) ;
F_147 ( V_7 , & V_358 ) ;
V_7 -> V_359 = V_360 ;
if ( V_66 == V_319 || V_66 == V_361 )
V_8 -> V_362 = ( 1 << V_363 ) ;
else if ( V_66 == V_321 || V_66 == V_364 )
V_8 -> V_362 = ( 1 << V_365 ) ;
else if ( V_66 == V_323 || V_66 == V_354 )
V_8 -> V_362 = ( 1 << V_366 ) ;
if ( F_1 ( V_1 ) ) {
V_8 -> V_362 = ( 1 << V_367 ) ;
F_148 ( & V_1 -> V_199 ,
F_72 ) ;
}
V_8 -> V_368 = ( 1 << 0 ) | ( 1 << 1 ) | ( 1 << 2 ) ;
V_7 -> V_369 = true ;
V_7 -> V_370 = 0 ;
F_149 ( V_43 , & V_8 -> V_2 , & V_371 ,
V_372 ) ;
F_150 ( & V_8 -> V_2 , & V_373 ) ;
F_151 ( V_119 , V_8 ) ;
F_152 ( V_7 ) ;
switch ( V_66 ) {
case V_209 :
V_120 = L_47 ;
break;
case V_319 :
case V_361 :
V_45 -> V_374 |=
V_375 ;
V_120 = L_48 ;
break;
case V_321 :
case V_364 :
V_45 -> V_374 |=
V_376 ;
V_120 = L_49 ;
break;
case V_323 :
case V_354 :
V_45 -> V_374 |=
V_377 ;
V_120 = L_50 ;
break;
}
if ( F_1 ( V_1 ) ) {
bool V_87 ;
struct V_378 V_379 , V_380 ;
T_4 V_381 , V_382 , V_383 ;
V_381 = F_19 ( V_384 ) ;
V_382 = F_19 ( V_385 ) ;
V_383 = F_19 ( V_386 ) ;
V_379 . V_387 = ( V_381 & V_388 ) >>
V_389 ;
V_379 . V_390 = ( V_381 & V_391 ) >>
V_392 ;
V_379 . V_393 = ( V_382 & V_394 ) >>
V_395 ;
V_379 . V_396 = ( V_382 & V_397 ) >>
V_398 ;
V_379 . V_399 = ( ( V_383 & V_400 ) >>
V_401 ) * 1000 ;
F_24 ( L_51 ,
V_379 . V_387 , V_379 . V_390 , V_379 . V_393 , V_379 . V_396 , V_379 . V_399 ) ;
V_380 = V_45 -> V_402 . V_403 ;
F_24 ( L_52 ,
V_380 . V_387 , V_380 . V_390 , V_380 . V_393 , V_380 . V_396 , V_380 . V_399 ) ;
#define F_153 ( T_7 ) ((max(cur.field, vbt.field) + 9) / 10)
V_1 -> V_195 = F_153 ( V_387 ) ;
V_1 -> V_206 = F_153 ( V_390 ) ;
V_1 -> V_207 = F_153 ( V_393 ) ;
V_1 -> V_196 = F_153 ( V_396 ) ;
V_1 -> V_202 = F_153 ( V_399 ) ;
F_24 ( L_53 ,
V_1 -> V_195 , V_1 -> V_196 ,
V_1 -> V_202 ) ;
F_24 ( L_54 ,
V_1 -> V_206 , V_1 -> V_207 ) ;
F_38 ( V_1 ) ;
V_87 = F_107 ( V_1 ) ;
F_40 ( V_1 , false ) ;
if ( V_87 ) {
if ( V_1 -> V_15 [ V_166 ] >= 0x11 )
V_45 -> V_404 =
V_1 -> V_15 [ V_405 ] &
V_406 ;
} else {
F_154 ( L_55 ) ;
F_135 ( & V_1 -> V_2 . V_2 ) ;
F_130 ( & V_119 -> V_2 ) ;
return;
}
}
F_37 ( V_1 , V_119 , V_120 ) ;
V_8 -> V_407 = F_139 ;
if ( F_1 ( V_1 ) ) {
V_45 -> V_408 = V_7 ;
F_155 ( V_43 ) ;
}
F_141 ( V_1 , V_7 ) ;
if ( F_156 ( V_43 ) && ! F_157 ( V_43 ) ) {
T_4 V_317 = F_19 ( V_409 ) ;
F_30 ( V_409 , ( V_317 & ~ 0xf ) | 0xd ) ;
}
}
