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
F_13 ( struct V_1 * V_1 , int V_19 , int V_20 )
{
struct V_21 * V_22 = V_1 -> V_2 . V_2 . V_22 ;
struct V_23 * V_23 = F_14 ( V_22 ) ;
int V_24 = 24 ;
if ( V_20 )
V_24 = V_20 ;
else if ( V_23 )
V_24 = V_23 -> V_24 ;
return ( V_19 * V_24 + 9 ) / 10 ;
}
static int
F_15 ( int V_25 , int V_26 )
{
return ( V_25 * V_26 * 8 ) / 10 ;
}
static int
F_16 ( struct V_6 * V_7 ,
struct V_27 * V_28 )
{
struct V_1 * V_1 = F_6 ( V_7 ) ;
int V_25 = F_12 ( F_11 ( V_1 ) ) ;
int V_26 = F_10 ( V_1 ) ;
int V_29 , V_30 ;
if ( F_1 ( V_1 ) && V_1 -> V_31 ) {
if ( V_28 -> V_32 > V_1 -> V_31 -> V_32 )
return V_33 ;
if ( V_28 -> V_34 > V_1 -> V_31 -> V_34 )
return V_33 ;
}
V_30 = F_13 ( V_1 , V_28 -> clock , 0 ) ;
V_29 = F_15 ( V_25 , V_26 ) ;
if ( V_30 > V_29 ) {
V_30 = F_13 ( V_1 ,
V_28 -> clock , 18 ) ;
if ( V_30 > V_29 )
return V_35 ;
else
V_28 -> V_36 |= V_37 ;
}
if ( V_28 -> clock < 10000 )
return V_38 ;
return V_39 ;
}
static T_2
F_17 ( T_1 * V_40 , int V_41 )
{
int V_42 ;
T_2 V_43 = 0 ;
if ( V_41 > 4 )
V_41 = 4 ;
for ( V_42 = 0 ; V_42 < V_41 ; V_42 ++ )
V_43 |= ( ( T_2 ) V_40 [ V_42 ] ) << ( ( 3 - V_42 ) * 8 ) ;
return V_43 ;
}
static void
F_18 ( T_2 V_40 , T_1 * V_44 , int V_45 )
{
int V_42 ;
if ( V_45 > 4 )
V_45 = 4 ;
for ( V_42 = 0 ; V_42 < V_45 ; V_42 ++ )
V_44 [ V_42 ] = V_40 >> ( ( 3 - V_42 ) * 8 ) ;
}
static int
F_19 ( struct V_46 * V_47 )
{
struct V_48 * V_49 = V_47 -> V_50 ;
T_2 V_51 ;
V_51 = F_20 ( V_52 ) ;
switch ( V_51 & V_53 ) {
case V_54 :
return 100 ;
case V_55 :
return 133 ;
case V_56 :
return 166 ;
case V_57 :
return 200 ;
case V_58 :
return 266 ;
case V_59 :
return 333 ;
case V_60 :
case V_61 :
return 400 ;
default:
return 133 ;
}
}
static bool F_21 ( struct V_1 * V_1 )
{
struct V_46 * V_47 = V_1 -> V_2 . V_2 . V_47 ;
struct V_48 * V_49 = V_47 -> V_50 ;
return ( F_20 ( V_62 ) & V_63 ) != 0 ;
}
static bool F_22 ( struct V_1 * V_1 )
{
struct V_46 * V_47 = V_1 -> V_2 . V_2 . V_47 ;
struct V_48 * V_49 = V_47 -> V_50 ;
return ( F_20 ( V_64 ) & V_65 ) != 0 ;
}
static void
F_23 ( struct V_1 * V_1 )
{
struct V_46 * V_47 = V_1 -> V_2 . V_2 . V_47 ;
struct V_48 * V_49 = V_47 -> V_50 ;
if ( ! F_1 ( V_1 ) )
return;
if ( ! F_21 ( V_1 ) && ! F_22 ( V_1 ) ) {
F_24 ( 1 , L_1 ) ;
F_25 ( L_2 ,
F_20 ( V_62 ) ,
F_20 ( V_64 ) ) ;
}
}
static int
F_26 ( struct V_1 * V_1 ,
T_1 * V_66 , int V_67 ,
T_1 * V_68 , int V_69 )
{
T_2 V_70 = V_1 -> V_70 ;
struct V_46 * V_47 = V_1 -> V_2 . V_2 . V_47 ;
struct V_48 * V_49 = V_47 -> V_50 ;
T_2 V_71 = V_70 + 0x10 ;
T_2 V_72 = V_71 + 4 ;
int V_42 ;
int V_73 ;
T_2 V_74 ;
T_2 V_75 ;
int V_76 , V_77 ;
F_23 ( V_1 ) ;
if ( F_3 ( V_1 ) ) {
if ( F_27 ( V_47 ) || F_28 ( V_47 ) )
V_75 = 200 ;
else
V_75 = 225 ;
} else if ( F_29 ( V_47 ) )
V_75 = 62 ;
else
V_75 = F_19 ( V_47 ) / 2 ;
if ( F_27 ( V_47 ) )
V_77 = 3 ;
else
V_77 = 5 ;
for ( V_76 = 0 ; V_76 < 3 ; V_76 ++ ) {
V_74 = F_20 ( V_71 ) ;
if ( ( V_74 & V_78 ) == 0 )
break;
F_30 ( 1 ) ;
}
if ( V_76 == 3 ) {
F_24 ( 1 , L_3 ,
F_20 ( V_71 ) ) ;
return - V_79 ;
}
for ( V_76 = 0 ; V_76 < 5 ; V_76 ++ ) {
for ( V_42 = 0 ; V_42 < V_67 ; V_42 += 4 )
F_31 ( V_72 + V_42 ,
F_17 ( V_66 + V_42 , V_67 - V_42 ) ) ;
F_31 ( V_71 ,
V_78 |
V_80 |
( V_67 << V_81 ) |
( V_77 << V_82 ) |
( V_75 << V_83 ) |
V_84 |
V_85 |
V_86 ) ;
for (; ; ) {
V_74 = F_20 ( V_71 ) ;
if ( ( V_74 & V_78 ) == 0 )
break;
F_32 ( 100 ) ;
}
F_31 ( V_71 ,
V_74 |
V_84 |
V_85 |
V_86 ) ;
if ( V_74 & V_84 )
break;
}
if ( ( V_74 & V_84 ) == 0 ) {
F_33 ( L_4 , V_74 ) ;
return - V_79 ;
}
if ( V_74 & V_86 ) {
F_33 ( L_5 , V_74 ) ;
return - V_87 ;
}
if ( V_74 & V_85 ) {
F_25 ( L_6 , V_74 ) ;
return - V_88 ;
}
V_73 = ( ( V_74 & V_89 ) >>
V_81 ) ;
if ( V_73 > V_69 )
V_73 = V_69 ;
for ( V_42 = 0 ; V_42 < V_73 ; V_42 += 4 )
F_18 ( F_20 ( V_72 + V_42 ) ,
V_68 + V_42 , V_73 - V_42 ) ;
return V_73 ;
}
static int
F_34 ( struct V_1 * V_1 ,
T_3 V_90 , T_1 * V_66 , int V_67 )
{
int V_91 ;
T_1 V_92 [ 20 ] ;
int V_93 ;
T_1 V_94 ;
F_23 ( V_1 ) ;
if ( V_67 > 16 )
return - 1 ;
V_92 [ 0 ] = V_95 << 4 ;
V_92 [ 1 ] = V_90 >> 8 ;
V_92 [ 2 ] = V_90 & 0xff ;
V_92 [ 3 ] = V_67 - 1 ;
memcpy ( & V_92 [ 4 ] , V_66 , V_67 ) ;
V_93 = V_67 + 4 ;
for (; ; ) {
V_91 = F_26 ( V_1 , V_92 , V_93 , & V_94 , 1 ) ;
if ( V_91 < 0 )
return V_91 ;
if ( ( V_94 & V_96 ) == V_97 )
break;
else if ( ( V_94 & V_96 ) == V_98 )
F_32 ( 100 ) ;
else
return - V_87 ;
}
return V_67 ;
}
static int
F_35 ( struct V_1 * V_1 ,
T_3 V_90 , T_1 V_99 )
{
return F_34 ( V_1 , V_90 , & V_99 , 1 ) ;
}
static int
F_36 ( struct V_1 * V_1 ,
T_3 V_90 , T_1 * V_68 , int V_73 )
{
T_1 V_92 [ 4 ] ;
int V_93 ;
T_1 V_100 [ 20 ] ;
int V_101 ;
T_1 V_94 ;
int V_91 ;
F_23 ( V_1 ) ;
V_92 [ 0 ] = V_102 << 4 ;
V_92 [ 1 ] = V_90 >> 8 ;
V_92 [ 2 ] = V_90 & 0xff ;
V_92 [ 3 ] = V_73 - 1 ;
V_93 = 4 ;
V_101 = V_73 + 1 ;
for (; ; ) {
V_91 = F_26 ( V_1 , V_92 , V_93 ,
V_100 , V_101 ) ;
if ( V_91 == 0 )
return - V_103 ;
if ( V_91 < 0 )
return V_91 ;
V_94 = V_100 [ 0 ] ;
if ( ( V_94 & V_96 ) == V_97 ) {
memcpy ( V_68 , V_100 + 1 , V_91 - 1 ) ;
return V_91 - 1 ;
}
else if ( ( V_94 & V_96 ) == V_98 )
F_32 ( 100 ) ;
else
return - V_87 ;
}
}
static int
F_37 ( struct V_104 * V_105 , int V_28 ,
T_1 V_106 , T_1 * V_107 )
{
struct V_108 * V_109 = V_105 -> V_109 ;
struct V_1 * V_1 = F_5 ( V_105 ,
struct V_1 ,
V_105 ) ;
T_3 V_90 = V_109 -> V_90 ;
T_1 V_92 [ 5 ] ;
T_1 V_100 [ 2 ] ;
unsigned V_110 ;
int V_93 ;
int V_101 ;
int V_91 ;
F_23 ( V_1 ) ;
if ( V_28 & V_111 )
V_92 [ 0 ] = V_112 << 4 ;
else
V_92 [ 0 ] = V_113 << 4 ;
if ( ! ( V_28 & V_114 ) )
V_92 [ 0 ] |= V_115 << 4 ;
V_92 [ 1 ] = V_90 >> 8 ;
V_92 [ 2 ] = V_90 ;
switch ( V_28 ) {
case V_116 :
V_92 [ 3 ] = 0 ;
V_92 [ 4 ] = V_106 ;
V_93 = 5 ;
V_101 = 1 ;
break;
case V_111 :
V_92 [ 3 ] = 0 ;
V_93 = 4 ;
V_101 = 2 ;
break;
default:
V_93 = 3 ;
V_101 = 1 ;
break;
}
for ( V_110 = 0 ; V_110 < 5 ; V_110 ++ ) {
V_91 = F_26 ( V_1 ,
V_92 , V_93 ,
V_100 , V_101 ) ;
if ( V_91 < 0 ) {
F_25 ( L_7 , V_91 ) ;
return V_91 ;
}
switch ( V_100 [ 0 ] & V_96 ) {
case V_97 :
break;
case V_117 :
F_25 ( L_8 ) ;
return - V_118 ;
case V_98 :
F_32 ( 100 ) ;
continue;
default:
F_33 ( L_9 ,
V_100 [ 0 ] ) ;
return - V_118 ;
}
switch ( V_100 [ 0 ] & V_119 ) {
case V_120 :
if ( V_28 == V_111 ) {
* V_107 = V_100 [ 1 ] ;
}
return V_101 - 1 ;
case V_121 :
F_25 ( L_10 ) ;
return - V_118 ;
case V_122 :
F_25 ( L_11 ) ;
F_32 ( 100 ) ;
break;
default:
F_33 ( L_12 , V_100 [ 0 ] ) ;
return - V_118 ;
}
}
F_33 ( L_13 ) ;
return - V_118 ;
}
static int
F_38 ( struct V_1 * V_1 ,
struct V_123 * V_123 , const char * V_124 )
{
int V_91 ;
F_25 ( L_14 , V_124 ) ;
V_1 -> V_125 . V_126 = false ;
V_1 -> V_125 . V_90 = 0 ;
V_1 -> V_125 . V_127 = F_37 ;
memset ( & V_1 -> V_105 , '\0' , sizeof( V_1 -> V_105 ) ) ;
V_1 -> V_105 . V_128 = V_129 ;
V_1 -> V_105 . V_130 = V_131 ;
strncpy ( V_1 -> V_105 . V_124 , V_124 , sizeof( V_1 -> V_105 . V_124 ) - 1 ) ;
V_1 -> V_105 . V_124 [ sizeof( V_1 -> V_105 . V_124 ) - 1 ] = '\0' ;
V_1 -> V_105 . V_109 = & V_1 -> V_125 ;
V_1 -> V_105 . V_47 . V_132 = & V_123 -> V_2 . V_133 ;
F_39 ( V_1 ) ;
V_91 = F_40 ( & V_1 -> V_105 ) ;
F_41 ( V_1 , false ) ;
return V_91 ;
}
static bool
F_42 ( struct V_4 * V_5 , struct V_27 * V_28 ,
struct V_27 * V_134 )
{
struct V_46 * V_47 = V_5 -> V_47 ;
struct V_1 * V_1 = F_4 ( V_5 ) ;
int V_11 , clock ;
int V_14 = F_10 ( V_1 ) ;
int V_135 = F_11 ( V_1 ) == V_13 ? 1 : 0 ;
int V_24 = V_28 -> V_36 & V_37 ? 18 : 0 ;
static int V_136 [ 2 ] = { V_12 , V_13 } ;
if ( F_1 ( V_1 ) && V_1 -> V_31 ) {
F_43 ( V_1 -> V_31 , V_134 ) ;
F_44 ( V_47 , V_137 ,
V_28 , V_134 ) ;
V_28 -> clock = V_1 -> V_31 -> clock ;
}
for ( V_11 = 1 ; V_11 <= V_14 ; V_11 <<= 1 ) {
for ( clock = 0 ; clock <= V_135 ; clock ++ ) {
int V_138 = F_15 ( F_12 ( V_136 [ clock ] ) , V_11 ) ;
if ( F_13 ( V_1 , V_28 -> clock , V_24 )
<= V_138 ) {
V_1 -> V_10 = V_136 [ clock ] ;
V_1 -> V_11 = V_11 ;
V_134 -> clock = F_12 ( V_1 -> V_10 ) ;
F_25 ( L_15
L_16 ,
V_1 -> V_10 , V_1 -> V_11 ,
V_134 -> clock ) ;
return true ;
}
}
}
return false ;
}
static void
F_45 ( T_2 * V_139 , T_2 * V_140 )
{
while ( * V_139 > 0xffffff || * V_140 > 0xffffff ) {
* V_139 >>= 1 ;
* V_140 >>= 1 ;
}
}
static void
F_46 ( int V_24 ,
int V_141 ,
int V_19 ,
int V_142 ,
struct V_143 * V_144 )
{
V_144 -> V_145 = 64 ;
V_144 -> V_146 = ( V_19 * V_24 ) >> 3 ;
V_144 -> V_147 = V_142 * V_141 ;
F_45 ( & V_144 -> V_146 , & V_144 -> V_147 ) ;
V_144 -> V_148 = V_19 ;
V_144 -> V_149 = V_142 ;
F_45 ( & V_144 -> V_148 , & V_144 -> V_149 ) ;
}
void
F_47 ( struct V_21 * V_22 , struct V_27 * V_28 ,
struct V_27 * V_134 )
{
struct V_46 * V_47 = V_22 -> V_47 ;
struct V_150 * V_151 = & V_47 -> V_151 ;
struct V_4 * V_5 ;
struct V_48 * V_49 = V_47 -> V_50 ;
struct V_23 * V_23 = F_14 ( V_22 ) ;
int V_11 = 4 ;
struct V_143 V_144 ;
int V_152 = V_23 -> V_152 ;
F_48 (encoder, &mode_config->encoder_list, head) {
struct V_1 * V_1 ;
if ( V_5 -> V_22 != V_22 )
continue;
V_1 = F_4 ( V_5 ) ;
if ( V_1 -> V_2 . type == V_153 ||
V_1 -> V_2 . type == V_3 )
{
V_11 = V_1 -> V_11 ;
break;
}
}
F_46 ( V_23 -> V_24 , V_11 ,
V_28 -> clock , V_134 -> clock , & V_144 ) ;
if ( F_29 ( V_47 ) ) {
F_31 ( F_49 ( V_152 ) ,
( ( V_144 . V_145 - 1 ) << V_154 ) |
V_144 . V_146 ) ;
F_31 ( F_50 ( V_152 ) , V_144 . V_147 ) ;
F_31 ( F_51 ( V_152 ) , V_144 . V_148 ) ;
F_31 ( F_52 ( V_152 ) , V_144 . V_149 ) ;
} else {
F_31 ( F_53 ( V_152 ) ,
( ( V_144 . V_145 - 1 ) << V_154 ) |
V_144 . V_146 ) ;
F_31 ( F_54 ( V_152 ) , V_144 . V_147 ) ;
F_31 ( F_55 ( V_152 ) , V_144 . V_148 ) ;
F_31 ( F_56 ( V_152 ) , V_144 . V_149 ) ;
}
}
static void
F_57 ( struct V_4 * V_5 , struct V_27 * V_28 ,
struct V_27 * V_134 )
{
struct V_46 * V_47 = V_5 -> V_47 ;
struct V_48 * V_49 = V_47 -> V_50 ;
struct V_1 * V_1 = F_4 ( V_5 ) ;
struct V_21 * V_22 = V_1 -> V_2 . V_2 . V_22 ;
struct V_23 * V_23 = F_14 ( V_22 ) ;
if ( F_1 ( V_1 ) ) {
if ( ! F_2 ( V_1 ) )
F_58 ( V_5 ) ;
else
F_59 ( V_5 ) ;
}
V_1 -> V_155 = F_20 ( V_1 -> V_70 ) & V_156 ;
V_1 -> V_155 |= V_157 | V_158 ;
V_1 -> V_155 |= V_157 | V_158 ;
switch ( V_1 -> V_11 ) {
case 1 :
V_1 -> V_155 |= V_159 ;
break;
case 2 :
V_1 -> V_155 |= V_160 ;
break;
case 4 :
V_1 -> V_155 |= V_161 ;
break;
}
if ( V_1 -> V_162 ) {
F_60 ( L_17 ,
F_61 ( V_23 -> V_152 ) ) ;
V_1 -> V_155 |= V_163 ;
F_62 ( V_5 , V_134 ) ;
}
memset ( V_1 -> V_164 , 0 , V_165 ) ;
V_1 -> V_164 [ 0 ] = V_1 -> V_10 ;
V_1 -> V_164 [ 1 ] = V_1 -> V_11 ;
V_1 -> V_164 [ 8 ] = V_166 ;
if ( V_1 -> V_15 [ V_167 ] >= 0x11 &&
( V_1 -> V_15 [ V_16 ] & V_168 ) ) {
V_1 -> V_164 [ 1 ] |= V_169 ;
}
if ( F_3 ( V_1 ) && F_28 ( V_47 ) ) {
if ( V_134 -> V_170 & V_171 )
V_1 -> V_155 |= V_172 ;
if ( V_134 -> V_170 & V_173 )
V_1 -> V_155 |= V_174 ;
V_1 -> V_155 |= V_175 ;
if ( V_1 -> V_164 [ 1 ] & V_169 )
V_1 -> V_155 |= V_176 ;
V_1 -> V_155 |= V_23 -> V_152 << 29 ;
V_1 -> V_155 |= V_177 ;
if ( V_134 -> clock < 200000 )
V_1 -> V_155 |= V_178 ;
else
V_1 -> V_155 |= V_179 ;
} else if ( ! F_63 ( V_47 ) || F_3 ( V_1 ) ) {
V_1 -> V_155 |= V_1 -> V_180 ;
if ( V_134 -> V_170 & V_171 )
V_1 -> V_155 |= V_172 ;
if ( V_134 -> V_170 & V_173 )
V_1 -> V_155 |= V_174 ;
V_1 -> V_155 |= V_181 ;
if ( V_1 -> V_164 [ 1 ] & V_169 )
V_1 -> V_155 |= V_176 ;
if ( V_23 -> V_152 == 1 )
V_1 -> V_155 |= V_182 ;
if ( F_3 ( V_1 ) ) {
V_1 -> V_155 |= V_177 ;
if ( V_134 -> clock < 200000 )
V_1 -> V_155 |= V_178 ;
else
V_1 -> V_155 |= V_179 ;
}
} else {
V_1 -> V_155 |= V_175 ;
}
}
static void F_64 ( struct V_1 * V_1 ,
T_4 V_183 ,
T_4 V_184 )
{
struct V_46 * V_47 = V_1 -> V_2 . V_2 . V_47 ;
struct V_48 * V_49 = V_47 -> V_50 ;
F_25 ( L_18 ,
V_183 , V_184 ,
F_20 ( V_62 ) ,
F_20 ( V_64 ) ) ;
if ( F_65 ( ( F_20 ( V_62 ) & V_183 ) == V_184 , 5000 , 10 ) ) {
F_33 ( L_19 ,
F_20 ( V_62 ) ,
F_20 ( V_64 ) ) ;
}
}
static void F_66 ( struct V_1 * V_1 )
{
F_25 ( L_20 ) ;
F_64 ( V_1 , V_185 , V_186 ) ;
}
static void F_67 ( struct V_1 * V_1 )
{
F_25 ( L_21 ) ;
F_64 ( V_1 , V_187 , V_188 ) ;
}
static void F_68 ( struct V_1 * V_1 )
{
F_25 ( L_22 ) ;
F_64 ( V_1 , V_189 , V_190 ) ;
}
static T_4 F_69 ( struct V_48 * V_49 )
{
T_4 V_191 = F_20 ( V_64 ) ;
V_191 &= ~ V_192 ;
V_191 |= V_193 ;
return V_191 ;
}
static void F_39 ( struct V_1 * V_1 )
{
struct V_46 * V_47 = V_1 -> V_2 . V_2 . V_47 ;
struct V_48 * V_49 = V_47 -> V_50 ;
T_4 V_194 ;
if ( ! F_1 ( V_1 ) )
return;
F_25 ( L_23 ) ;
F_24 ( V_1 -> V_195 ,
L_24 ) ;
V_1 -> V_195 = true ;
if ( F_22 ( V_1 ) ) {
F_25 ( L_25 ) ;
return;
}
if ( ! F_21 ( V_1 ) )
F_68 ( V_1 ) ;
V_194 = F_69 ( V_49 ) ;
V_194 |= V_65 ;
F_31 ( V_64 , V_194 ) ;
F_70 ( V_64 ) ;
F_25 ( L_26 ,
F_20 ( V_62 ) , F_20 ( V_64 ) ) ;
if ( ! F_21 ( V_1 ) ) {
F_25 ( L_27 ) ;
F_30 ( V_1 -> V_196 ) ;
}
}
static void F_71 ( struct V_1 * V_1 )
{
struct V_46 * V_47 = V_1 -> V_2 . V_2 . V_47 ;
struct V_48 * V_49 = V_47 -> V_50 ;
T_4 V_194 ;
if ( ! V_1 -> V_195 && F_22 ( V_1 ) ) {
V_194 = F_69 ( V_49 ) ;
V_194 &= ~ V_65 ;
F_31 ( V_64 , V_194 ) ;
F_70 ( V_64 ) ;
F_25 ( L_26 ,
F_20 ( V_62 ) , F_20 ( V_64 ) ) ;
F_30 ( V_1 -> V_197 ) ;
}
}
static void F_72 ( struct V_198 * V_199 )
{
struct V_1 * V_1 = F_5 ( F_73 ( V_199 ) ,
struct V_1 , V_200 ) ;
struct V_46 * V_47 = V_1 -> V_2 . V_2 . V_47 ;
F_74 ( & V_47 -> V_151 . V_201 ) ;
F_71 ( V_1 ) ;
F_75 ( & V_47 -> V_151 . V_201 ) ;
}
static void F_41 ( struct V_1 * V_1 , bool V_202 )
{
if ( ! F_1 ( V_1 ) )
return;
F_25 ( L_28 , V_1 -> V_195 ) ;
F_24 ( ! V_1 -> V_195 , L_29 ) ;
V_1 -> V_195 = false ;
if ( V_202 ) {
F_71 ( V_1 ) ;
} else {
F_76 ( & V_1 -> V_200 ,
F_77 ( V_1 -> V_203 * 5 ) ) ;
}
}
static void F_78 ( struct V_1 * V_1 )
{
struct V_46 * V_47 = V_1 -> V_2 . V_2 . V_47 ;
struct V_48 * V_49 = V_47 -> V_50 ;
T_4 V_194 ;
if ( ! F_1 ( V_1 ) )
return;
F_25 ( L_30 ) ;
if ( F_21 ( V_1 ) ) {
F_25 ( L_31 ) ;
return;
}
F_68 ( V_1 ) ;
V_194 = F_69 ( V_49 ) ;
if ( F_79 ( V_47 ) ) {
V_194 &= ~ V_204 ;
F_31 ( V_64 , V_194 ) ;
F_70 ( V_64 ) ;
}
V_194 |= V_205 ;
if ( ! F_79 ( V_47 ) )
V_194 |= V_204 ;
F_31 ( V_64 , V_194 ) ;
F_70 ( V_64 ) ;
F_66 ( V_1 ) ;
if ( F_79 ( V_47 ) ) {
V_194 |= V_204 ;
F_31 ( V_64 , V_194 ) ;
F_70 ( V_64 ) ;
}
}
static void F_80 ( struct V_1 * V_1 )
{
struct V_46 * V_47 = V_1 -> V_2 . V_2 . V_47 ;
struct V_48 * V_49 = V_47 -> V_50 ;
T_4 V_194 ;
if ( ! F_1 ( V_1 ) )
return;
F_25 ( L_32 ) ;
F_24 ( V_1 -> V_195 , L_33 ) ;
V_194 = F_69 ( V_49 ) ;
V_194 &= ~ ( V_205 | V_65 | V_204 | V_206 ) ;
F_31 ( V_64 , V_194 ) ;
F_70 ( V_64 ) ;
F_67 ( V_1 ) ;
}
static void F_81 ( struct V_1 * V_1 )
{
struct V_46 * V_47 = V_1 -> V_2 . V_2 . V_47 ;
struct V_48 * V_49 = V_47 -> V_50 ;
T_4 V_194 ;
if ( ! F_1 ( V_1 ) )
return;
F_25 ( L_34 ) ;
F_30 ( V_1 -> V_207 ) ;
V_194 = F_69 ( V_49 ) ;
V_194 |= V_206 ;
F_31 ( V_64 , V_194 ) ;
F_70 ( V_64 ) ;
}
static void F_82 ( struct V_1 * V_1 )
{
struct V_46 * V_47 = V_1 -> V_2 . V_2 . V_47 ;
struct V_48 * V_49 = V_47 -> V_50 ;
T_4 V_194 ;
if ( ! F_1 ( V_1 ) )
return;
F_25 ( L_34 ) ;
V_194 = F_69 ( V_49 ) ;
V_194 &= ~ V_206 ;
F_31 ( V_64 , V_194 ) ;
F_70 ( V_64 ) ;
F_30 ( V_1 -> V_208 ) ;
}
static void F_58 ( struct V_4 * V_5 )
{
struct V_46 * V_47 = V_5 -> V_47 ;
struct V_48 * V_49 = V_47 -> V_50 ;
T_4 V_209 ;
F_25 ( L_34 ) ;
V_209 = F_20 ( V_210 ) ;
V_209 |= V_177 ;
F_31 ( V_210 , V_209 ) ;
F_70 ( V_210 ) ;
F_32 ( 200 ) ;
}
static void F_59 ( struct V_4 * V_5 )
{
struct V_46 * V_47 = V_5 -> V_47 ;
struct V_48 * V_49 = V_47 -> V_50 ;
T_4 V_209 ;
V_209 = F_20 ( V_210 ) ;
V_209 &= ~ V_177 ;
F_31 ( V_210 , V_209 ) ;
F_70 ( V_210 ) ;
F_32 ( 200 ) ;
}
static void F_83 ( struct V_1 * V_1 , int V_28 )
{
int V_91 , V_42 ;
if ( V_1 -> V_15 [ V_167 ] < 0x11 )
return;
if ( V_28 != V_211 ) {
V_91 = F_35 ( V_1 , V_212 ,
V_213 ) ;
if ( V_91 != 1 )
F_60 ( L_35 ) ;
} else {
for ( V_42 = 0 ; V_42 < 3 ; V_42 ++ ) {
V_91 = F_35 ( V_1 ,
V_212 ,
V_214 ) ;
if ( V_91 == 1 )
break;
F_30 ( 1 ) ;
}
}
}
static void F_84 ( struct V_4 * V_5 )
{
struct V_1 * V_1 = F_4 ( V_5 ) ;
F_82 ( V_1 ) ;
F_80 ( V_1 ) ;
F_39 ( V_1 ) ;
F_83 ( V_1 , V_211 ) ;
F_85 ( V_1 ) ;
F_41 ( V_1 , false ) ;
}
static void F_86 ( struct V_4 * V_5 )
{
struct V_1 * V_1 = F_4 ( V_5 ) ;
struct V_46 * V_47 = V_5 -> V_47 ;
struct V_23 * V_23 = F_14 ( V_1 -> V_2 . V_2 . V_22 ) ;
F_39 ( V_1 ) ;
F_83 ( V_1 , V_211 ) ;
F_87 ( V_1 ) ;
F_78 ( V_1 ) ;
F_41 ( V_1 , true ) ;
F_88 ( V_1 ) ;
F_81 ( V_1 ) ;
V_1 -> V_215 = V_211 ;
if ( F_63 ( V_47 ) )
F_89 ( V_47 , V_23 -> V_152 ) ;
}
static void
F_90 ( struct V_4 * V_5 , int V_28 )
{
struct V_1 * V_1 = F_4 ( V_5 ) ;
struct V_46 * V_47 = V_5 -> V_47 ;
struct V_48 * V_49 = V_47 -> V_50 ;
T_2 V_216 = F_20 ( V_1 -> V_70 ) ;
if ( V_28 != V_211 ) {
F_82 ( V_1 ) ;
F_80 ( V_1 ) ;
F_39 ( V_1 ) ;
F_83 ( V_1 , V_28 ) ;
F_85 ( V_1 ) ;
F_41 ( V_1 , false ) ;
if ( F_3 ( V_1 ) )
F_59 ( V_5 ) ;
} else {
if ( F_3 ( V_1 ) )
F_58 ( V_5 ) ;
F_39 ( V_1 ) ;
F_83 ( V_1 , V_28 ) ;
if ( ! ( V_216 & V_217 ) ) {
F_87 ( V_1 ) ;
F_78 ( V_1 ) ;
F_41 ( V_1 , true ) ;
F_88 ( V_1 ) ;
} else
F_41 ( V_1 , false ) ;
F_81 ( V_1 ) ;
}
V_1 -> V_215 = V_28 ;
}
static bool
F_91 ( struct V_1 * V_1 , T_3 V_90 ,
T_1 * V_68 , int V_73 )
{
int V_91 , V_42 ;
for ( V_42 = 0 ; V_42 < 3 ; V_42 ++ ) {
V_91 = F_36 ( V_1 , V_90 , V_68 ,
V_73 ) ;
if ( V_91 == V_73 )
return true ;
F_30 ( 1 ) ;
}
return false ;
}
static bool
F_92 ( struct V_1 * V_1 , T_1 V_218 [ V_219 ] )
{
return F_91 ( V_1 ,
V_220 ,
V_218 ,
V_219 ) ;
}
static T_1
F_93 ( T_1 V_218 [ V_219 ] ,
int V_221 )
{
return V_218 [ V_221 - V_220 ] ;
}
static T_1
F_94 ( T_1 V_222 [ 2 ] ,
int V_223 )
{
int V_224 = ( ( V_223 & 1 ) ?
V_225 :
V_226 ) ;
T_1 V_227 = V_222 [ V_223 >> 1 ] ;
return ( ( V_227 >> V_224 ) & 3 ) << V_228 ;
}
static T_1
F_95 ( T_1 V_222 [ 2 ] ,
int V_223 )
{
int V_224 = ( ( V_223 & 1 ) ?
V_229 :
V_230 ) ;
T_1 V_227 = V_222 [ V_223 >> 1 ] ;
return ( ( V_227 >> V_224 ) & 3 ) << V_231 ;
}
static T_1
F_96 ( struct V_1 * V_1 )
{
struct V_46 * V_47 = V_1 -> V_2 . V_2 . V_47 ;
if ( F_28 ( V_47 ) && F_3 ( V_1 ) )
return V_232 ;
else if ( F_63 ( V_47 ) && ! F_3 ( V_1 ) )
return V_233 ;
else
return V_232 ;
}
static T_1
F_97 ( struct V_1 * V_1 , T_1 V_234 )
{
struct V_46 * V_47 = V_1 -> V_2 . V_2 . V_47 ;
if ( F_28 ( V_47 ) && F_3 ( V_1 ) ) {
switch ( V_234 & V_235 ) {
case V_236 :
return V_237 ;
case V_238 :
case V_232 :
return V_239 ;
default:
return V_240 ;
}
} else {
switch ( V_234 & V_235 ) {
case V_236 :
return V_237 ;
case V_238 :
return V_237 ;
case V_232 :
return V_239 ;
case V_233 :
default:
return V_240 ;
}
}
}
static void
F_98 ( struct V_1 * V_1 , T_1 V_218 [ V_219 ] )
{
T_1 V_43 = 0 ;
T_1 V_241 = 0 ;
int V_223 ;
T_1 * V_222 = V_218 + ( V_242 - V_220 ) ;
T_1 V_243 ;
T_1 V_244 ;
for ( V_223 = 0 ; V_223 < V_1 -> V_11 ; V_223 ++ ) {
T_1 V_245 = F_94 ( V_222 , V_223 ) ;
T_1 V_246 = F_95 ( V_222 , V_223 ) ;
if ( V_245 > V_43 )
V_43 = V_245 ;
if ( V_246 > V_241 )
V_241 = V_246 ;
}
V_243 = F_96 ( V_1 ) ;
if ( V_43 >= V_243 )
V_43 = V_243 | V_247 ;
V_244 = F_97 ( V_1 , V_43 ) ;
if ( V_241 >= V_244 )
V_241 = V_244 | V_248 ;
for ( V_223 = 0 ; V_223 < 4 ; V_223 ++ )
V_1 -> V_249 [ V_223 ] = V_43 | V_241 ;
}
static T_2
F_99 ( T_1 V_249 )
{
T_2 V_250 = 0 ;
switch ( V_249 & V_235 ) {
case V_236 :
default:
V_250 |= V_157 ;
break;
case V_238 :
V_250 |= V_251 ;
break;
case V_232 :
V_250 |= V_252 ;
break;
case V_233 :
V_250 |= V_253 ;
break;
}
switch ( V_249 & V_254 ) {
case V_240 :
default:
V_250 |= V_158 ;
break;
case V_239 :
V_250 |= V_255 ;
break;
case V_237 :
V_250 |= V_256 ;
break;
case V_257 :
V_250 |= V_258 ;
break;
}
return V_250 ;
}
static T_2
F_100 ( T_1 V_249 )
{
int V_250 = V_249 & ( V_235 |
V_254 ) ;
switch ( V_250 ) {
case V_236 | V_240 :
case V_238 | V_240 :
return V_259 ;
case V_236 | V_239 :
return V_260 ;
case V_236 | V_237 :
case V_238 | V_237 :
return V_261 ;
case V_238 | V_239 :
case V_232 | V_239 :
return V_262 ;
case V_232 | V_240 :
case V_233 | V_240 :
return V_263 ;
default:
F_25 ( L_36
L_37 , V_250 ) ;
return V_259 ;
}
}
static T_2
F_101 ( T_1 V_249 )
{
int V_250 = V_249 & ( V_235 |
V_254 ) ;
switch ( V_250 ) {
case V_236 | V_240 :
return V_264 ;
case V_236 | V_239 :
return V_265 ;
case V_236 | V_237 :
return V_266 ;
case V_238 | V_240 :
return V_267 ;
case V_238 | V_239 :
return V_268 ;
case V_232 | V_240 :
return V_269 ;
case V_232 | V_239 :
return V_270 ;
default:
F_25 ( L_36
L_37 , V_250 ) ;
return V_271 ;
}
}
static T_1
F_102 ( T_1 V_218 [ V_219 ] ,
int V_223 )
{
int V_224 = ( V_223 & 1 ) * 4 ;
T_1 V_227 = V_218 [ V_223 >> 1 ] ;
return ( V_227 >> V_224 ) & 0xf ;
}
static bool
F_103 ( T_1 V_218 [ V_219 ] , int V_11 )
{
int V_223 ;
T_1 V_272 ;
for ( V_223 = 0 ; V_223 < V_11 ; V_223 ++ ) {
V_272 = F_102 ( V_218 , V_223 ) ;
if ( ( V_272 & V_273 ) == 0 )
return false ;
}
return true ;
}
static bool
F_104 ( struct V_1 * V_1 , T_1 V_218 [ V_219 ] )
{
T_1 V_274 ;
T_1 V_272 ;
int V_223 ;
V_274 = F_93 ( V_218 ,
V_275 ) ;
if ( ( V_274 & V_276 ) == 0 )
return false ;
for ( V_223 = 0 ; V_223 < V_1 -> V_11 ; V_223 ++ ) {
V_272 = F_102 ( V_218 , V_223 ) ;
if ( ( V_272 & V_277 ) != V_277 )
return false ;
}
return true ;
}
static bool
F_105 ( struct V_1 * V_1 ,
T_2 V_278 ,
T_1 V_279 )
{
struct V_46 * V_47 = V_1 -> V_2 . V_2 . V_47 ;
struct V_48 * V_49 = V_47 -> V_50 ;
int V_91 ;
F_31 ( V_1 -> V_70 , V_278 ) ;
F_70 ( V_1 -> V_70 ) ;
F_35 ( V_1 ,
V_280 ,
V_279 ) ;
V_91 = F_34 ( V_1 ,
V_281 ,
V_1 -> V_249 ,
V_1 -> V_11 ) ;
if ( V_91 != V_1 -> V_11 )
return false ;
return true ;
}
static void
F_87 ( struct V_1 * V_1 )
{
struct V_46 * V_47 = V_1 -> V_2 . V_2 . V_47 ;
struct V_48 * V_49 = V_47 -> V_50 ;
struct V_23 * V_23 = F_14 ( V_1 -> V_2 . V_2 . V_22 ) ;
int V_42 ;
T_1 V_282 ;
bool V_283 = false ;
int V_284 , V_285 ;
T_4 V_286 ;
T_2 V_155 = V_1 -> V_155 ;
if ( ! F_63 ( V_47 ) ) {
F_31 ( V_1 -> V_70 , V_1 -> V_155 ) ;
F_70 ( V_1 -> V_70 ) ;
F_106 ( V_47 , V_23 -> V_152 ) ;
}
F_34 ( V_1 , V_287 ,
V_1 -> V_164 ,
V_165 ) ;
V_155 |= V_217 ;
if ( F_63 ( V_47 ) && ( F_28 ( V_47 ) || ! F_3 ( V_1 ) ) )
V_155 &= ~ V_288 ;
else
V_155 &= ~ V_289 ;
memset ( V_1 -> V_249 , 0 , 4 ) ;
V_282 = 0xff ;
V_284 = 0 ;
V_285 = 0 ;
V_283 = false ;
for (; ; ) {
T_1 V_218 [ V_219 ] ;
T_2 V_250 ;
if ( F_28 ( V_47 ) && F_3 ( V_1 ) ) {
V_250 = F_101 ( V_1 -> V_249 [ 0 ] ) ;
V_155 = ( V_155 & ~ V_290 ) | V_250 ;
} else if ( F_27 ( V_47 ) && F_3 ( V_1 ) ) {
V_250 = F_100 ( V_1 -> V_249 [ 0 ] ) ;
V_155 = ( V_155 & ~ V_291 ) | V_250 ;
} else {
V_250 = F_99 ( V_1 -> V_249 [ 0 ] ) ;
F_25 ( L_38 , V_250 ) ;
V_155 = ( V_155 & ~ ( V_292 | V_293 ) ) | V_250 ;
}
if ( F_63 ( V_47 ) && ( F_28 ( V_47 ) || ! F_3 ( V_1 ) ) )
V_286 = V_155 | V_294 ;
else
V_286 = V_155 | V_295 ;
if ( ! F_105 ( V_1 , V_286 ,
V_296 |
V_297 ) )
break;
F_32 ( 100 ) ;
if ( ! F_92 ( V_1 , V_218 ) ) {
F_33 ( L_39 ) ;
break;
}
if ( F_103 ( V_218 , V_1 -> V_11 ) ) {
F_25 ( L_40 ) ;
V_283 = true ;
break;
}
for ( V_42 = 0 ; V_42 < V_1 -> V_11 ; V_42 ++ )
if ( ( V_1 -> V_249 [ V_42 ] & V_247 ) == 0 )
break;
if ( V_42 == V_1 -> V_11 ) {
++ V_285 ;
if ( V_285 == 5 ) {
F_25 ( L_41 ) ;
break;
}
memset ( V_1 -> V_249 , 0 , 4 ) ;
V_284 = 0 ;
continue;
}
if ( ( V_1 -> V_249 [ 0 ] & V_235 ) == V_282 ) {
++ V_284 ;
if ( V_284 == 5 ) {
F_25 ( L_42 ) ;
break;
}
} else
V_284 = 0 ;
V_282 = V_1 -> V_249 [ 0 ] & V_235 ;
F_98 ( V_1 , V_218 ) ;
}
V_1 -> V_155 = V_155 ;
}
static void
F_88 ( struct V_1 * V_1 )
{
struct V_46 * V_47 = V_1 -> V_2 . V_2 . V_47 ;
struct V_48 * V_49 = V_47 -> V_50 ;
bool V_298 = false ;
int V_299 , V_300 ;
T_4 V_286 ;
T_2 V_155 = V_1 -> V_155 ;
V_299 = 0 ;
V_300 = 0 ;
V_298 = false ;
for (; ; ) {
T_2 V_250 ;
T_1 V_218 [ V_219 ] ;
if ( V_300 > 5 ) {
F_33 ( L_43 ) ;
F_85 ( V_1 ) ;
break;
}
if ( F_28 ( V_47 ) && F_3 ( V_1 ) ) {
V_250 = F_101 ( V_1 -> V_249 [ 0 ] ) ;
V_155 = ( V_155 & ~ V_290 ) | V_250 ;
} else if ( F_27 ( V_47 ) && F_3 ( V_1 ) ) {
V_250 = F_100 ( V_1 -> V_249 [ 0 ] ) ;
V_155 = ( V_155 & ~ V_291 ) | V_250 ;
} else {
V_250 = F_99 ( V_1 -> V_249 [ 0 ] ) ;
V_155 = ( V_155 & ~ ( V_292 | V_293 ) ) | V_250 ;
}
if ( F_63 ( V_47 ) && ( F_28 ( V_47 ) || ! F_3 ( V_1 ) ) )
V_286 = V_155 | V_301 ;
else
V_286 = V_155 | V_302 ;
if ( ! F_105 ( V_1 , V_286 ,
V_303 |
V_297 ) )
break;
F_32 ( 400 ) ;
if ( ! F_92 ( V_1 , V_218 ) )
break;
if ( ! F_103 ( V_218 , V_1 -> V_11 ) ) {
F_87 ( V_1 ) ;
V_300 ++ ;
continue;
}
if ( F_104 ( V_1 , V_218 ) ) {
V_298 = true ;
break;
}
if ( V_299 > 5 ) {
F_85 ( V_1 ) ;
F_87 ( V_1 ) ;
V_299 = 0 ;
V_300 ++ ;
continue;
}
F_98 ( V_1 , V_218 ) ;
++ V_299 ;
}
if ( F_63 ( V_47 ) && ( F_28 ( V_47 ) || ! F_3 ( V_1 ) ) )
V_286 = V_155 | V_175 ;
else
V_286 = V_155 | V_181 ;
F_31 ( V_1 -> V_70 , V_286 ) ;
F_70 ( V_1 -> V_70 ) ;
F_35 ( V_1 ,
V_280 , V_304 ) ;
}
static void
F_85 ( struct V_1 * V_1 )
{
struct V_46 * V_47 = V_1 -> V_2 . V_2 . V_47 ;
struct V_48 * V_49 = V_47 -> V_50 ;
T_2 V_155 = V_1 -> V_155 ;
if ( ( F_20 ( V_1 -> V_70 ) & V_217 ) == 0 )
return;
F_25 ( L_34 ) ;
if ( F_1 ( V_1 ) ) {
V_155 &= ~ V_177 ;
F_31 ( V_1 -> V_70 , V_155 ) ;
F_70 ( V_1 -> V_70 ) ;
F_32 ( 100 ) ;
}
if ( F_63 ( V_47 ) && ( F_28 ( V_47 ) || ! F_3 ( V_1 ) ) ) {
V_155 &= ~ V_288 ;
F_31 ( V_1 -> V_70 , V_155 | V_305 ) ;
} else {
V_155 &= ~ V_289 ;
F_31 ( V_1 -> V_70 , V_155 | V_306 ) ;
}
F_70 ( V_1 -> V_70 ) ;
F_30 ( 17 ) ;
if ( F_1 ( V_1 ) ) {
if ( F_63 ( V_47 ) && ( F_28 ( V_47 ) || ! F_3 ( V_1 ) ) )
V_155 |= V_175 ;
else
V_155 |= V_181 ;
}
if ( ! F_63 ( V_47 ) &&
F_20 ( V_1 -> V_70 ) & V_182 ) {
struct V_21 * V_22 = V_1 -> V_2 . V_2 . V_22 ;
V_155 &= ~ V_182 ;
F_31 ( V_1 -> V_70 , V_155 ) ;
if ( V_22 == NULL ) {
F_70 ( V_1 -> V_70 ) ;
F_30 ( 50 ) ;
} else
F_106 ( V_47 , F_14 ( V_22 ) -> V_152 ) ;
}
F_31 ( V_1 -> V_70 , V_155 & ~ V_217 ) ;
F_70 ( V_1 -> V_70 ) ;
F_30 ( V_1 -> V_197 ) ;
}
static bool
F_107 ( struct V_1 * V_1 )
{
if ( F_91 ( V_1 , 0x000 , V_1 -> V_15 ,
sizeof( V_1 -> V_15 ) ) &&
( V_1 -> V_15 [ V_167 ] != 0 ) ) {
return true ;
}
return false ;
}
static bool
F_108 ( struct V_1 * V_1 , T_5 * V_307 )
{
int V_91 ;
V_91 = F_91 ( V_1 ,
V_308 ,
V_307 , 1 ) ;
if ( ! V_91 )
return false ;
return true ;
}
static void
F_109 ( struct V_1 * V_1 )
{
F_35 ( V_1 , V_309 , V_310 ) ;
}
static void
F_110 ( struct V_1 * V_1 )
{
T_5 V_307 ;
T_5 V_218 [ V_219 ] ;
if ( V_1 -> V_215 != V_211 )
return;
if ( ! V_1 -> V_2 . V_2 . V_22 )
return;
if ( ! F_92 ( V_1 , V_218 ) ) {
F_85 ( V_1 ) ;
return;
}
if ( ! F_107 ( V_1 ) ) {
F_85 ( V_1 ) ;
return;
}
if ( V_1 -> V_15 [ V_167 ] >= 0x11 &&
F_108 ( V_1 , & V_307 ) ) {
F_35 ( V_1 ,
V_308 ,
V_307 ) ;
if ( V_307 & V_311 )
F_109 ( V_1 ) ;
if ( V_307 & ( V_312 | V_313 ) )
F_60 ( L_44 ) ;
}
if ( ! F_104 ( V_1 , V_218 ) ) {
F_25 ( L_45 ,
F_111 ( & V_1 -> V_2 . V_2 ) ) ;
F_87 ( V_1 ) ;
F_88 ( V_1 ) ;
}
}
static enum V_314
F_112 ( struct V_1 * V_1 )
{
if ( F_107 ( V_1 ) )
return V_315 ;
return V_316 ;
}
static enum V_314
F_113 ( struct V_1 * V_1 )
{
enum V_314 V_74 ;
if ( F_1 ( V_1 ) ) {
V_74 = F_114 ( V_1 -> V_2 . V_2 . V_47 ) ;
if ( V_74 == V_317 )
V_74 = V_315 ;
return V_74 ;
}
return F_112 ( V_1 ) ;
}
static enum V_314
F_115 ( struct V_1 * V_1 )
{
struct V_46 * V_47 = V_1 -> V_2 . V_2 . V_47 ;
struct V_48 * V_49 = V_47 -> V_50 ;
T_2 V_318 , V_319 ;
switch ( V_1 -> V_70 ) {
case V_320 :
V_319 = V_321 ;
break;
case V_322 :
V_319 = V_323 ;
break;
case V_324 :
V_319 = V_325 ;
break;
default:
return V_317 ;
}
V_318 = F_20 ( V_326 ) ;
if ( ( V_318 & V_319 ) == 0 )
return V_316 ;
return F_112 ( V_1 ) ;
}
static struct V_327 *
F_116 ( struct V_6 * V_7 , struct V_104 * V_105 )
{
struct V_1 * V_1 = F_6 ( V_7 ) ;
struct V_327 * V_327 ;
F_39 ( V_1 ) ;
V_327 = F_117 ( V_7 , V_105 ) ;
F_41 ( V_1 , false ) ;
return V_327 ;
}
static int
F_118 ( struct V_6 * V_7 , struct V_104 * V_105 )
{
struct V_1 * V_1 = F_6 ( V_7 ) ;
int V_91 ;
F_39 ( V_1 ) ;
V_91 = F_119 ( V_7 , V_105 ) ;
F_41 ( V_1 , false ) ;
return V_91 ;
}
static enum V_314
F_120 ( struct V_6 * V_7 , bool V_328 )
{
struct V_1 * V_1 = F_6 ( V_7 ) ;
struct V_46 * V_47 = V_1 -> V_2 . V_2 . V_47 ;
enum V_314 V_74 ;
struct V_327 * V_327 = NULL ;
V_1 -> V_162 = false ;
if ( F_29 ( V_47 ) )
V_74 = F_113 ( V_1 ) ;
else
V_74 = F_115 ( V_1 ) ;
F_25 ( L_46 ,
V_1 -> V_15 [ 0 ] , V_1 -> V_15 [ 1 ] , V_1 -> V_15 [ 2 ] ,
V_1 -> V_15 [ 3 ] , V_1 -> V_15 [ 4 ] , V_1 -> V_15 [ 5 ] ,
V_1 -> V_15 [ 6 ] , V_1 -> V_15 [ 7 ] ) ;
if ( V_74 != V_315 )
return V_74 ;
if ( V_1 -> V_329 ) {
V_1 -> V_162 = V_1 -> V_329 > 0 ;
} else {
V_327 = F_116 ( V_7 , & V_1 -> V_105 ) ;
if ( V_327 ) {
V_1 -> V_162 = F_121 ( V_327 ) ;
V_7 -> V_330 . V_331 = NULL ;
F_122 ( V_327 ) ;
}
}
return V_315 ;
}
static int F_123 ( struct V_6 * V_7 )
{
struct V_1 * V_1 = F_6 ( V_7 ) ;
struct V_46 * V_47 = V_1 -> V_2 . V_2 . V_47 ;
struct V_48 * V_49 = V_47 -> V_50 ;
int V_91 ;
V_91 = F_118 ( V_7 , & V_1 -> V_105 ) ;
if ( V_91 ) {
if ( F_1 ( V_1 ) && ! V_1 -> V_31 ) {
struct V_27 * V_332 ;
F_48 (newmode, &connector->probed_modes,
head) {
if ( ( V_332 -> type & V_333 ) ) {
V_1 -> V_31 =
F_124 ( V_47 , V_332 ) ;
break;
}
}
}
return V_91 ;
}
if ( F_1 ( V_1 ) ) {
if ( V_1 -> V_31 == NULL && V_49 -> V_334 != NULL ) {
V_1 -> V_31 =
F_124 ( V_47 , V_49 -> V_334 ) ;
if ( V_1 -> V_31 ) {
V_1 -> V_31 -> type |=
V_333 ;
}
}
if ( V_1 -> V_31 ) {
struct V_27 * V_28 ;
V_28 = F_124 ( V_47 , V_1 -> V_31 ) ;
F_125 ( V_7 , V_28 ) ;
return 1 ;
}
}
return 0 ;
}
static bool
F_126 ( struct V_6 * V_7 )
{
struct V_1 * V_1 = F_6 ( V_7 ) ;
struct V_327 * V_327 ;
bool V_162 = false ;
V_327 = F_116 ( V_7 , & V_1 -> V_105 ) ;
if ( V_327 ) {
V_162 = F_121 ( V_327 ) ;
V_7 -> V_330 . V_331 = NULL ;
F_122 ( V_327 ) ;
}
return V_162 ;
}
static int
F_127 ( struct V_6 * V_7 ,
struct V_335 * V_336 ,
T_6 V_337 )
{
struct V_48 * V_49 = V_7 -> V_47 -> V_50 ;
struct V_1 * V_1 = F_6 ( V_7 ) ;
int V_91 ;
V_91 = F_128 ( V_7 , V_336 , V_337 ) ;
if ( V_91 )
return V_91 ;
if ( V_336 == V_49 -> V_338 ) {
int V_42 = V_337 ;
bool V_162 ;
if ( V_42 == V_1 -> V_329 )
return 0 ;
V_1 -> V_329 = V_42 ;
if ( V_42 == 0 )
V_162 = F_126 ( V_7 ) ;
else
V_162 = V_42 > 0 ;
if ( V_162 == V_1 -> V_162 )
return 0 ;
V_1 -> V_162 = V_162 ;
goto V_339;
}
if ( V_336 == V_49 -> V_340 ) {
if ( V_337 == ! ! V_1 -> V_180 )
return 0 ;
V_1 -> V_180 = V_337 ? V_341 : 0 ;
goto V_339;
}
return - V_342 ;
V_339:
if ( V_1 -> V_2 . V_2 . V_22 ) {
struct V_21 * V_22 = V_1 -> V_2 . V_2 . V_22 ;
F_129 ( V_22 , & V_22 -> V_28 ,
V_22 -> V_343 , V_22 -> V_344 ,
V_22 -> V_345 ) ;
}
return 0 ;
}
static void
F_130 ( struct V_6 * V_7 )
{
struct V_46 * V_47 = V_7 -> V_47 ;
if ( F_131 ( V_47 ) )
F_132 ( V_47 ) ;
F_133 ( V_7 ) ;
F_134 ( V_7 ) ;
F_122 ( V_7 ) ;
}
static void F_135 ( struct V_4 * V_5 )
{
struct V_1 * V_1 = F_4 ( V_5 ) ;
F_136 ( & V_1 -> V_105 ) ;
F_137 ( V_5 ) ;
if ( F_1 ( V_1 ) ) {
F_138 ( & V_1 -> V_200 ) ;
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
F_140 ( struct V_21 * V_22 )
{
struct V_46 * V_47 = V_22 -> V_47 ;
struct V_150 * V_151 = & V_47 -> V_151 ;
struct V_4 * V_5 ;
F_48 (encoder, &mode_config->encoder_list, head) {
struct V_1 * V_1 ;
if ( V_5 -> V_22 != V_22 )
continue;
V_1 = F_4 ( V_5 ) ;
if ( V_1 -> V_2 . type == V_153 ||
V_1 -> V_2 . type == V_3 )
return V_1 -> V_70 ;
}
return - 1 ;
}
bool F_131 ( struct V_46 * V_47 )
{
struct V_48 * V_49 = V_47 -> V_50 ;
struct V_346 * V_347 ;
int V_42 ;
if ( ! V_49 -> V_348 )
return false ;
for ( V_42 = 0 ; V_42 < V_49 -> V_348 ; V_42 ++ ) {
V_347 = V_49 -> V_349 + V_42 ;
if ( V_347 -> V_350 == V_351 &&
V_347 -> V_352 == V_353 )
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
F_144 ( struct V_46 * V_47 , int V_70 )
{
struct V_48 * V_49 = V_47 -> V_50 ;
struct V_6 * V_7 ;
struct V_1 * V_1 ;
struct V_8 * V_8 ;
struct V_123 * V_123 ;
const char * V_124 = NULL ;
int type ;
V_1 = F_145 ( sizeof( struct V_1 ) , V_354 ) ;
if ( ! V_1 )
return;
V_1 -> V_70 = V_70 ;
V_1 -> V_215 = - 1 ;
V_123 = F_145 ( sizeof( struct V_123 ) , V_354 ) ;
if ( ! V_123 ) {
F_122 ( V_1 ) ;
return;
}
V_8 = & V_1 -> V_2 ;
if ( F_29 ( V_47 ) && V_70 == V_355 )
if ( F_131 ( V_47 ) )
V_1 -> F_2 = true ;
if ( V_70 == V_210 || F_2 ( V_1 ) ) {
type = V_356 ;
V_8 -> type = V_3 ;
} else {
type = V_357 ;
V_8 -> type = V_153 ;
}
V_7 = & V_123 -> V_2 ;
F_146 ( V_47 , V_7 , & V_358 , type ) ;
F_147 ( V_7 , & V_359 ) ;
V_7 -> V_360 = V_361 ;
if ( V_70 == V_320 || V_70 == V_362 )
V_8 -> V_363 = ( 1 << V_364 ) ;
else if ( V_70 == V_322 || V_70 == V_365 )
V_8 -> V_363 = ( 1 << V_366 ) ;
else if ( V_70 == V_324 || V_70 == V_355 )
V_8 -> V_363 = ( 1 << V_367 ) ;
if ( F_1 ( V_1 ) ) {
V_8 -> V_363 = ( 1 << V_368 ) ;
F_148 ( & V_1 -> V_200 ,
F_72 ) ;
}
V_8 -> V_369 = ( 1 << 0 ) | ( 1 << 1 ) | ( 1 << 2 ) ;
V_7 -> V_370 = true ;
V_7 -> V_371 = 0 ;
F_149 ( V_47 , & V_8 -> V_2 , & V_372 ,
V_373 ) ;
F_150 ( & V_8 -> V_2 , & V_374 ) ;
F_151 ( V_123 , V_8 ) ;
F_152 ( V_7 ) ;
switch ( V_70 ) {
case V_210 :
V_124 = L_47 ;
break;
case V_320 :
case V_362 :
V_49 -> V_375 |=
V_376 ;
V_124 = L_48 ;
break;
case V_322 :
case V_365 :
V_49 -> V_375 |=
V_377 ;
V_124 = L_49 ;
break;
case V_324 :
case V_355 :
V_49 -> V_375 |=
V_378 ;
V_124 = L_50 ;
break;
}
if ( F_1 ( V_1 ) ) {
bool V_91 ;
struct V_379 V_380 , V_381 ;
T_4 V_382 , V_383 , V_384 ;
V_382 = F_20 ( V_385 ) ;
V_383 = F_20 ( V_386 ) ;
V_384 = F_20 ( V_387 ) ;
V_380 . V_388 = ( V_382 & V_389 ) >>
V_390 ;
V_380 . V_391 = ( V_382 & V_392 ) >>
V_393 ;
V_380 . V_394 = ( V_383 & V_395 ) >>
V_396 ;
V_380 . V_397 = ( V_383 & V_398 ) >>
V_399 ;
V_380 . V_400 = ( ( V_384 & V_401 ) >>
V_402 ) * 1000 ;
F_25 ( L_51 ,
V_380 . V_388 , V_380 . V_391 , V_380 . V_394 , V_380 . V_397 , V_380 . V_400 ) ;
V_381 = V_49 -> V_403 . V_404 ;
F_25 ( L_52 ,
V_381 . V_388 , V_381 . V_391 , V_381 . V_394 , V_381 . V_397 , V_381 . V_400 ) ;
#define F_153 ( T_7 ) ((max(cur.field, vbt.field) + 9) / 10)
V_1 -> V_196 = F_153 ( V_388 ) ;
V_1 -> V_207 = F_153 ( V_391 ) ;
V_1 -> V_208 = F_153 ( V_394 ) ;
V_1 -> V_197 = F_153 ( V_397 ) ;
V_1 -> V_203 = F_153 ( V_400 ) ;
F_25 ( L_53 ,
V_1 -> V_196 , V_1 -> V_197 ,
V_1 -> V_203 ) ;
F_25 ( L_54 ,
V_1 -> V_207 , V_1 -> V_208 ) ;
F_39 ( V_1 ) ;
V_91 = F_107 ( V_1 ) ;
F_41 ( V_1 , false ) ;
if ( V_91 ) {
if ( V_1 -> V_15 [ V_167 ] >= 0x11 )
V_49 -> V_405 =
V_1 -> V_15 [ V_406 ] &
V_407 ;
} else {
F_154 ( L_55 ) ;
F_135 ( & V_1 -> V_2 . V_2 ) ;
F_130 ( & V_123 -> V_2 ) ;
return;
}
}
F_38 ( V_1 , V_123 , V_124 ) ;
V_8 -> V_408 = F_139 ;
if ( F_1 ( V_1 ) ) {
V_49 -> V_409 = V_7 ;
F_155 ( V_47 ) ;
}
F_141 ( V_1 , V_7 ) ;
if ( F_156 ( V_47 ) && ! F_157 ( V_47 ) ) {
T_4 V_318 = F_20 ( V_410 ) ;
F_31 ( V_410 , ( V_318 & ~ 0xf ) | 0xd ) ;
}
}
