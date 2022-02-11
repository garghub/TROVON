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
static bool
F_15 ( struct V_1 * V_1 ,
struct V_23 * V_24 ,
struct V_23 * V_25 )
{
int V_21 = F_12 ( F_11 ( V_1 ) ) ;
int V_22 = F_10 ( V_1 ) ;
int V_26 , V_27 ;
V_27 = F_13 ( V_24 -> clock , 24 ) ;
V_26 = F_14 ( V_21 , V_22 ) ;
if ( V_27 > V_26 ) {
V_27 = F_13 ( V_24 -> clock , 18 ) ;
if ( V_27 > V_26 )
return false ;
if ( V_25 )
V_25 -> V_28
|= V_29 ;
return true ;
}
return true ;
}
static int
F_16 ( struct V_6 * V_7 ,
struct V_23 * V_24 )
{
struct V_1 * V_1 = F_6 ( V_7 ) ;
if ( F_1 ( V_1 ) && V_1 -> V_30 ) {
if ( V_24 -> V_31 > V_1 -> V_30 -> V_31 )
return V_32 ;
if ( V_24 -> V_33 > V_1 -> V_30 -> V_33 )
return V_32 ;
}
if ( ! F_15 ( V_1 , V_24 , NULL ) )
return V_34 ;
if ( V_24 -> clock < 10000 )
return V_35 ;
return V_36 ;
}
static T_2
F_17 ( T_1 * V_37 , int V_38 )
{
int V_39 ;
T_2 V_40 = 0 ;
if ( V_38 > 4 )
V_38 = 4 ;
for ( V_39 = 0 ; V_39 < V_38 ; V_39 ++ )
V_40 |= ( ( T_2 ) V_37 [ V_39 ] ) << ( ( 3 - V_39 ) * 8 ) ;
return V_40 ;
}
static void
F_18 ( T_2 V_37 , T_1 * V_41 , int V_42 )
{
int V_39 ;
if ( V_42 > 4 )
V_42 = 4 ;
for ( V_39 = 0 ; V_39 < V_42 ; V_39 ++ )
V_41 [ V_39 ] = V_37 >> ( ( 3 - V_39 ) * 8 ) ;
}
static int
F_19 ( struct V_43 * V_44 )
{
struct V_45 * V_46 = V_44 -> V_47 ;
T_2 V_48 ;
V_48 = F_20 ( V_49 ) ;
switch ( V_48 & V_50 ) {
case V_51 :
return 100 ;
case V_52 :
return 133 ;
case V_53 :
return 166 ;
case V_54 :
return 200 ;
case V_55 :
return 266 ;
case V_56 :
return 333 ;
case V_57 :
case V_58 :
return 400 ;
default:
return 133 ;
}
}
static bool F_21 ( struct V_1 * V_1 )
{
struct V_43 * V_44 = V_1 -> V_2 . V_2 . V_44 ;
struct V_45 * V_46 = V_44 -> V_47 ;
return ( F_20 ( V_59 ) & V_60 ) != 0 ;
}
static bool F_22 ( struct V_1 * V_1 )
{
struct V_43 * V_44 = V_1 -> V_2 . V_2 . V_44 ;
struct V_45 * V_46 = V_44 -> V_47 ;
return ( F_20 ( V_61 ) & V_62 ) != 0 ;
}
static void
F_23 ( struct V_1 * V_1 )
{
struct V_43 * V_44 = V_1 -> V_2 . V_2 . V_44 ;
struct V_45 * V_46 = V_44 -> V_47 ;
if ( ! F_1 ( V_1 ) )
return;
if ( ! F_21 ( V_1 ) && ! F_22 ( V_1 ) ) {
F_24 ( 1 , L_1 ) ;
F_25 ( L_2 ,
F_20 ( V_59 ) ,
F_20 ( V_61 ) ) ;
}
}
static int
F_26 ( struct V_1 * V_1 ,
T_1 * V_63 , int V_64 ,
T_1 * V_65 , int V_66 )
{
T_2 V_67 = V_1 -> V_67 ;
struct V_43 * V_44 = V_1 -> V_2 . V_2 . V_44 ;
struct V_45 * V_46 = V_44 -> V_47 ;
T_2 V_68 = V_67 + 0x10 ;
T_2 V_69 = V_68 + 4 ;
int V_39 ;
int V_70 ;
T_2 V_71 ;
T_2 V_72 ;
int V_73 , V_74 = 5 ;
F_23 ( V_1 ) ;
if ( F_3 ( V_1 ) ) {
if ( F_27 ( V_44 ) || F_28 ( V_44 ) )
V_72 = 200 ;
else
V_72 = 225 ;
} else if ( F_29 ( V_44 ) )
V_72 = 63 ;
else
V_72 = F_19 ( V_44 ) / 2 ;
for ( V_73 = 0 ; V_73 < 3 ; V_73 ++ ) {
V_71 = F_20 ( V_68 ) ;
if ( ( V_71 & V_75 ) == 0 )
break;
F_30 ( 1 ) ;
}
if ( V_73 == 3 ) {
F_24 ( 1 , L_3 ,
F_20 ( V_68 ) ) ;
return - V_76 ;
}
for ( V_73 = 0 ; V_73 < 5 ; V_73 ++ ) {
for ( V_39 = 0 ; V_39 < V_64 ; V_39 += 4 )
F_31 ( V_69 + V_39 ,
F_17 ( V_63 + V_39 , V_64 - V_39 ) ) ;
F_31 ( V_68 ,
V_75 |
V_77 |
( V_64 << V_78 ) |
( V_74 << V_79 ) |
( V_72 << V_80 ) |
V_81 |
V_82 |
V_83 ) ;
for (; ; ) {
V_71 = F_20 ( V_68 ) ;
if ( ( V_71 & V_75 ) == 0 )
break;
F_32 ( 100 ) ;
}
F_31 ( V_68 ,
V_71 |
V_81 |
V_82 |
V_83 ) ;
if ( V_71 & ( V_82 |
V_83 ) )
continue;
if ( V_71 & V_81 )
break;
}
if ( ( V_71 & V_81 ) == 0 ) {
F_33 ( L_4 , V_71 ) ;
return - V_76 ;
}
if ( V_71 & V_83 ) {
F_33 ( L_5 , V_71 ) ;
return - V_84 ;
}
if ( V_71 & V_82 ) {
F_25 ( L_6 , V_71 ) ;
return - V_85 ;
}
V_70 = ( ( V_71 & V_86 ) >>
V_78 ) ;
if ( V_70 > V_66 )
V_70 = V_66 ;
for ( V_39 = 0 ; V_39 < V_70 ; V_39 += 4 )
F_18 ( F_20 ( V_69 + V_39 ) ,
V_65 + V_39 , V_70 - V_39 ) ;
return V_70 ;
}
static int
F_34 ( struct V_1 * V_1 ,
T_3 V_87 , T_1 * V_63 , int V_64 )
{
int V_88 ;
T_1 V_89 [ 20 ] ;
int V_90 ;
T_1 V_91 ;
F_23 ( V_1 ) ;
if ( V_64 > 16 )
return - 1 ;
V_89 [ 0 ] = V_92 << 4 ;
V_89 [ 1 ] = V_87 >> 8 ;
V_89 [ 2 ] = V_87 & 0xff ;
V_89 [ 3 ] = V_64 - 1 ;
memcpy ( & V_89 [ 4 ] , V_63 , V_64 ) ;
V_90 = V_64 + 4 ;
for (; ; ) {
V_88 = F_26 ( V_1 , V_89 , V_90 , & V_91 , 1 ) ;
if ( V_88 < 0 )
return V_88 ;
if ( ( V_91 & V_93 ) == V_94 )
break;
else if ( ( V_91 & V_93 ) == V_95 )
F_32 ( 100 ) ;
else
return - V_84 ;
}
return V_64 ;
}
static int
F_35 ( struct V_1 * V_1 ,
T_3 V_87 , T_1 V_96 )
{
return F_34 ( V_1 , V_87 , & V_96 , 1 ) ;
}
static int
F_36 ( struct V_1 * V_1 ,
T_3 V_87 , T_1 * V_65 , int V_70 )
{
T_1 V_89 [ 4 ] ;
int V_90 ;
T_1 V_97 [ 20 ] ;
int V_98 ;
T_1 V_91 ;
int V_88 ;
F_23 ( V_1 ) ;
V_89 [ 0 ] = V_99 << 4 ;
V_89 [ 1 ] = V_87 >> 8 ;
V_89 [ 2 ] = V_87 & 0xff ;
V_89 [ 3 ] = V_70 - 1 ;
V_90 = 4 ;
V_98 = V_70 + 1 ;
for (; ; ) {
V_88 = F_26 ( V_1 , V_89 , V_90 ,
V_97 , V_98 ) ;
if ( V_88 == 0 )
return - V_100 ;
if ( V_88 < 0 )
return V_88 ;
V_91 = V_97 [ 0 ] ;
if ( ( V_91 & V_93 ) == V_94 ) {
memcpy ( V_65 , V_97 + 1 , V_88 - 1 ) ;
return V_88 - 1 ;
}
else if ( ( V_91 & V_93 ) == V_95 )
F_32 ( 100 ) ;
else
return - V_84 ;
}
}
static int
F_37 ( struct V_101 * V_102 , int V_24 ,
T_1 V_103 , T_1 * V_104 )
{
struct V_105 * V_106 = V_102 -> V_106 ;
struct V_1 * V_1 = F_5 ( V_102 ,
struct V_1 ,
V_102 ) ;
T_3 V_87 = V_106 -> V_87 ;
T_1 V_89 [ 5 ] ;
T_1 V_97 [ 2 ] ;
unsigned V_107 ;
int V_90 ;
int V_98 ;
int V_88 ;
F_23 ( V_1 ) ;
if ( V_24 & V_108 )
V_89 [ 0 ] = V_109 << 4 ;
else
V_89 [ 0 ] = V_110 << 4 ;
if ( ! ( V_24 & V_111 ) )
V_89 [ 0 ] |= V_112 << 4 ;
V_89 [ 1 ] = V_87 >> 8 ;
V_89 [ 2 ] = V_87 ;
switch ( V_24 ) {
case V_113 :
V_89 [ 3 ] = 0 ;
V_89 [ 4 ] = V_103 ;
V_90 = 5 ;
V_98 = 1 ;
break;
case V_108 :
V_89 [ 3 ] = 0 ;
V_90 = 4 ;
V_98 = 2 ;
break;
default:
V_90 = 3 ;
V_98 = 1 ;
break;
}
for ( V_107 = 0 ; V_107 < 5 ; V_107 ++ ) {
V_88 = F_26 ( V_1 ,
V_89 , V_90 ,
V_97 , V_98 ) ;
if ( V_88 < 0 ) {
F_25 ( L_7 , V_88 ) ;
return V_88 ;
}
switch ( V_97 [ 0 ] & V_93 ) {
case V_94 :
break;
case V_114 :
F_25 ( L_8 ) ;
return - V_115 ;
case V_95 :
F_32 ( 100 ) ;
continue;
default:
F_33 ( L_9 ,
V_97 [ 0 ] ) ;
return - V_115 ;
}
switch ( V_97 [ 0 ] & V_116 ) {
case V_117 :
if ( V_24 == V_108 ) {
* V_104 = V_97 [ 1 ] ;
}
return V_98 - 1 ;
case V_118 :
F_25 ( L_10 ) ;
return - V_115 ;
case V_119 :
F_25 ( L_11 ) ;
F_32 ( 100 ) ;
break;
default:
F_33 ( L_12 , V_97 [ 0 ] ) ;
return - V_115 ;
}
}
F_33 ( L_13 ) ;
return - V_115 ;
}
static int
F_38 ( struct V_1 * V_1 ,
struct V_120 * V_120 , const char * V_121 )
{
int V_88 ;
F_25 ( L_14 , V_121 ) ;
V_1 -> V_122 . V_123 = false ;
V_1 -> V_122 . V_87 = 0 ;
V_1 -> V_122 . V_124 = F_37 ;
memset ( & V_1 -> V_102 , '\0' , sizeof( V_1 -> V_102 ) ) ;
V_1 -> V_102 . V_125 = V_126 ;
V_1 -> V_102 . V_127 = V_128 ;
strncpy ( V_1 -> V_102 . V_121 , V_121 , sizeof( V_1 -> V_102 . V_121 ) - 1 ) ;
V_1 -> V_102 . V_121 [ sizeof( V_1 -> V_102 . V_121 ) - 1 ] = '\0' ;
V_1 -> V_102 . V_106 = & V_1 -> V_122 ;
V_1 -> V_102 . V_44 . V_129 = & V_120 -> V_2 . V_130 ;
F_39 ( V_1 ) ;
V_88 = F_40 ( & V_1 -> V_102 ) ;
F_41 ( V_1 , false ) ;
return V_88 ;
}
static bool
F_42 ( struct V_4 * V_5 , struct V_23 * V_24 ,
struct V_23 * V_25 )
{
struct V_43 * V_44 = V_5 -> V_44 ;
struct V_1 * V_1 = F_4 ( V_5 ) ;
int V_11 , clock ;
int V_14 = F_10 ( V_1 ) ;
int V_131 = F_11 ( V_1 ) == V_13 ? 1 : 0 ;
int V_20 ;
static int V_132 [ 2 ] = { V_12 , V_13 } ;
if ( F_1 ( V_1 ) && V_1 -> V_30 ) {
F_43 ( V_1 -> V_30 , V_25 ) ;
F_44 ( V_44 , V_133 ,
V_24 , V_25 ) ;
V_24 -> clock = V_1 -> V_30 -> clock ;
}
if ( ! F_15 ( V_1 , V_24 , V_25 ) )
return false ;
V_20 = V_25 -> V_28 & V_29 ? 18 : 24 ;
for ( V_11 = 1 ; V_11 <= V_14 ; V_11 <<= 1 ) {
for ( clock = 0 ; clock <= V_131 ; clock ++ ) {
int V_134 = F_14 ( F_12 ( V_132 [ clock ] ) , V_11 ) ;
if ( F_13 ( V_24 -> clock , V_20 )
<= V_134 ) {
V_1 -> V_10 = V_132 [ clock ] ;
V_1 -> V_11 = V_11 ;
V_25 -> clock = F_12 ( V_1 -> V_10 ) ;
F_25 ( L_15
L_16 ,
V_1 -> V_10 , V_1 -> V_11 ,
V_25 -> clock ) ;
return true ;
}
}
}
return false ;
}
static void
F_45 ( T_2 * V_135 , T_2 * V_136 )
{
while ( * V_135 > 0xffffff || * V_136 > 0xffffff ) {
* V_135 >>= 1 ;
* V_136 >>= 1 ;
}
}
static void
F_46 ( int V_20 ,
int V_137 ,
int V_19 ,
int V_138 ,
struct V_139 * V_140 )
{
V_140 -> V_141 = 64 ;
V_140 -> V_142 = ( V_19 * V_20 ) >> 3 ;
V_140 -> V_143 = V_138 * V_137 ;
F_45 ( & V_140 -> V_142 , & V_140 -> V_143 ) ;
V_140 -> V_144 = V_19 ;
V_140 -> V_145 = V_138 ;
F_45 ( & V_140 -> V_144 , & V_140 -> V_145 ) ;
}
void
F_47 ( struct V_146 * V_147 , struct V_23 * V_24 ,
struct V_23 * V_25 )
{
struct V_43 * V_44 = V_147 -> V_44 ;
struct V_148 * V_149 = & V_44 -> V_149 ;
struct V_4 * V_5 ;
struct V_45 * V_46 = V_44 -> V_47 ;
struct V_150 * V_150 = F_48 ( V_147 ) ;
int V_11 = 4 ;
struct V_139 V_140 ;
int V_151 = V_150 -> V_151 ;
F_49 (encoder, &mode_config->encoder_list, head) {
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
F_46 ( V_150 -> V_20 , V_11 ,
V_24 -> clock , V_25 -> clock , & V_140 ) ;
if ( F_29 ( V_44 ) ) {
F_31 ( F_50 ( V_151 ) ,
( ( V_140 . V_141 - 1 ) << V_153 ) |
V_140 . V_142 ) ;
F_31 ( F_51 ( V_151 ) , V_140 . V_143 ) ;
F_31 ( F_52 ( V_151 ) , V_140 . V_144 ) ;
F_31 ( F_53 ( V_151 ) , V_140 . V_145 ) ;
} else {
F_31 ( F_54 ( V_151 ) ,
( ( V_140 . V_141 - 1 ) << V_153 ) |
V_140 . V_142 ) ;
F_31 ( F_55 ( V_151 ) , V_140 . V_143 ) ;
F_31 ( F_56 ( V_151 ) , V_140 . V_144 ) ;
F_31 ( F_57 ( V_151 ) , V_140 . V_145 ) ;
}
}
static void
F_58 ( struct V_4 * V_5 , struct V_23 * V_24 ,
struct V_23 * V_25 )
{
struct V_43 * V_44 = V_5 -> V_44 ;
struct V_45 * V_46 = V_44 -> V_47 ;
struct V_1 * V_1 = F_4 ( V_5 ) ;
struct V_146 * V_147 = V_1 -> V_2 . V_2 . V_147 ;
struct V_150 * V_150 = F_48 ( V_147 ) ;
if ( F_1 ( V_1 ) ) {
if ( ! F_2 ( V_1 ) )
F_59 ( V_5 ) ;
else
F_60 ( V_5 ) ;
}
V_1 -> V_154 = F_20 ( V_1 -> V_67 ) & V_155 ;
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
F_61 ( L_17 ,
F_62 ( V_150 -> V_151 ) ) ;
V_1 -> V_154 |= V_162 ;
F_63 ( V_5 , V_25 ) ;
}
memset ( V_1 -> V_163 , 0 , V_164 ) ;
V_1 -> V_163 [ 0 ] = V_1 -> V_10 ;
V_1 -> V_163 [ 1 ] = V_1 -> V_11 ;
V_1 -> V_163 [ 8 ] = V_165 ;
if ( V_1 -> V_15 [ V_166 ] >= 0x11 &&
( V_1 -> V_15 [ V_16 ] & V_167 ) ) {
V_1 -> V_163 [ 1 ] |= V_168 ;
}
if ( F_3 ( V_1 ) && F_28 ( V_44 ) ) {
if ( V_25 -> V_169 & V_170 )
V_1 -> V_154 |= V_171 ;
if ( V_25 -> V_169 & V_172 )
V_1 -> V_154 |= V_173 ;
V_1 -> V_154 |= V_174 ;
if ( V_1 -> V_163 [ 1 ] & V_168 )
V_1 -> V_154 |= V_175 ;
V_1 -> V_154 |= V_150 -> V_151 << 29 ;
V_1 -> V_154 |= V_176 ;
if ( V_25 -> clock < 200000 )
V_1 -> V_154 |= V_177 ;
else
V_1 -> V_154 |= V_178 ;
} else if ( ! F_64 ( V_44 ) || F_3 ( V_1 ) ) {
V_1 -> V_154 |= V_1 -> V_179 ;
if ( V_25 -> V_169 & V_170 )
V_1 -> V_154 |= V_171 ;
if ( V_25 -> V_169 & V_172 )
V_1 -> V_154 |= V_173 ;
V_1 -> V_154 |= V_180 ;
if ( V_1 -> V_163 [ 1 ] & V_168 )
V_1 -> V_154 |= V_175 ;
if ( V_150 -> V_151 == 1 )
V_1 -> V_154 |= V_181 ;
if ( F_3 ( V_1 ) ) {
V_1 -> V_154 |= V_176 ;
if ( V_25 -> clock < 200000 )
V_1 -> V_154 |= V_177 ;
else
V_1 -> V_154 |= V_178 ;
}
} else {
V_1 -> V_154 |= V_174 ;
}
}
static void F_65 ( struct V_1 * V_1 ,
T_4 V_182 ,
T_4 V_183 )
{
struct V_43 * V_44 = V_1 -> V_2 . V_2 . V_44 ;
struct V_45 * V_46 = V_44 -> V_47 ;
F_25 ( L_18 ,
V_182 , V_183 ,
F_20 ( V_59 ) ,
F_20 ( V_61 ) ) ;
if ( F_66 ( ( F_20 ( V_59 ) & V_182 ) == V_183 , 5000 , 10 ) ) {
F_33 ( L_19 ,
F_20 ( V_59 ) ,
F_20 ( V_61 ) ) ;
}
}
static void F_67 ( struct V_1 * V_1 )
{
F_25 ( L_20 ) ;
F_65 ( V_1 , V_184 , V_185 ) ;
}
static void F_68 ( struct V_1 * V_1 )
{
F_25 ( L_21 ) ;
F_65 ( V_1 , V_186 , V_187 ) ;
}
static void F_69 ( struct V_1 * V_1 )
{
F_25 ( L_22 ) ;
F_65 ( V_1 , V_188 , V_189 ) ;
}
static T_4 F_70 ( struct V_45 * V_46 )
{
T_4 V_190 = F_20 ( V_61 ) ;
V_190 &= ~ V_191 ;
V_190 |= V_192 ;
return V_190 ;
}
static void F_39 ( struct V_1 * V_1 )
{
struct V_43 * V_44 = V_1 -> V_2 . V_2 . V_44 ;
struct V_45 * V_46 = V_44 -> V_47 ;
T_4 V_193 ;
if ( ! F_1 ( V_1 ) )
return;
F_25 ( L_23 ) ;
F_24 ( V_1 -> V_194 ,
L_24 ) ;
V_1 -> V_194 = true ;
if ( F_22 ( V_1 ) ) {
F_25 ( L_25 ) ;
return;
}
if ( ! F_21 ( V_1 ) )
F_69 ( V_1 ) ;
V_193 = F_70 ( V_46 ) ;
V_193 |= V_62 ;
F_31 ( V_61 , V_193 ) ;
F_71 ( V_61 ) ;
F_25 ( L_26 ,
F_20 ( V_59 ) , F_20 ( V_61 ) ) ;
if ( ! F_21 ( V_1 ) ) {
F_25 ( L_27 ) ;
F_30 ( V_1 -> V_195 ) ;
}
}
static void F_72 ( struct V_1 * V_1 )
{
struct V_43 * V_44 = V_1 -> V_2 . V_2 . V_44 ;
struct V_45 * V_46 = V_44 -> V_47 ;
T_4 V_193 ;
if ( ! V_1 -> V_194 && F_22 ( V_1 ) ) {
V_193 = F_70 ( V_46 ) ;
V_193 &= ~ V_62 ;
F_31 ( V_61 , V_193 ) ;
F_71 ( V_61 ) ;
F_25 ( L_26 ,
F_20 ( V_59 ) , F_20 ( V_61 ) ) ;
F_30 ( V_1 -> V_196 ) ;
}
}
static void F_73 ( struct V_197 * V_198 )
{
struct V_1 * V_1 = F_5 ( F_74 ( V_198 ) ,
struct V_1 , V_199 ) ;
struct V_43 * V_44 = V_1 -> V_2 . V_2 . V_44 ;
F_75 ( & V_44 -> V_149 . V_200 ) ;
F_72 ( V_1 ) ;
F_76 ( & V_44 -> V_149 . V_200 ) ;
}
static void F_41 ( struct V_1 * V_1 , bool V_201 )
{
if ( ! F_1 ( V_1 ) )
return;
F_25 ( L_28 , V_1 -> V_194 ) ;
F_24 ( ! V_1 -> V_194 , L_29 ) ;
V_1 -> V_194 = false ;
if ( V_201 ) {
F_72 ( V_1 ) ;
} else {
F_77 ( & V_1 -> V_199 ,
F_78 ( V_1 -> V_202 * 5 ) ) ;
}
}
static void F_79 ( struct V_1 * V_1 )
{
struct V_43 * V_44 = V_1 -> V_2 . V_2 . V_44 ;
struct V_45 * V_46 = V_44 -> V_47 ;
T_4 V_193 ;
if ( ! F_1 ( V_1 ) )
return;
F_25 ( L_30 ) ;
if ( F_21 ( V_1 ) ) {
F_25 ( L_31 ) ;
return;
}
F_69 ( V_1 ) ;
V_193 = F_70 ( V_46 ) ;
if ( F_80 ( V_44 ) ) {
V_193 &= ~ V_203 ;
F_31 ( V_61 , V_193 ) ;
F_71 ( V_61 ) ;
}
V_193 |= V_204 ;
if ( ! F_80 ( V_44 ) )
V_193 |= V_203 ;
F_31 ( V_61 , V_193 ) ;
F_71 ( V_61 ) ;
F_67 ( V_1 ) ;
if ( F_80 ( V_44 ) ) {
V_193 |= V_203 ;
F_31 ( V_61 , V_193 ) ;
F_71 ( V_61 ) ;
}
}
static void F_81 ( struct V_1 * V_1 )
{
struct V_43 * V_44 = V_1 -> V_2 . V_2 . V_44 ;
struct V_45 * V_46 = V_44 -> V_47 ;
T_4 V_193 ;
if ( ! F_1 ( V_1 ) )
return;
F_25 ( L_32 ) ;
F_24 ( V_1 -> V_194 , L_33 ) ;
V_193 = F_70 ( V_46 ) ;
V_193 &= ~ ( V_204 | V_62 | V_203 | V_205 ) ;
F_31 ( V_61 , V_193 ) ;
F_71 ( V_61 ) ;
F_68 ( V_1 ) ;
}
static void F_82 ( struct V_1 * V_1 )
{
struct V_43 * V_44 = V_1 -> V_2 . V_2 . V_44 ;
struct V_45 * V_46 = V_44 -> V_47 ;
T_4 V_193 ;
if ( ! F_1 ( V_1 ) )
return;
F_25 ( L_34 ) ;
F_30 ( V_1 -> V_206 ) ;
V_193 = F_70 ( V_46 ) ;
V_193 |= V_205 ;
F_31 ( V_61 , V_193 ) ;
F_71 ( V_61 ) ;
}
static void F_83 ( struct V_1 * V_1 )
{
struct V_43 * V_44 = V_1 -> V_2 . V_2 . V_44 ;
struct V_45 * V_46 = V_44 -> V_47 ;
T_4 V_193 ;
if ( ! F_1 ( V_1 ) )
return;
F_25 ( L_34 ) ;
V_193 = F_70 ( V_46 ) ;
V_193 &= ~ V_205 ;
F_31 ( V_61 , V_193 ) ;
F_71 ( V_61 ) ;
F_30 ( V_1 -> V_207 ) ;
}
static void F_59 ( struct V_4 * V_5 )
{
struct V_43 * V_44 = V_5 -> V_44 ;
struct V_45 * V_46 = V_44 -> V_47 ;
T_4 V_208 ;
F_25 ( L_34 ) ;
V_208 = F_20 ( V_209 ) ;
V_208 |= V_176 ;
F_31 ( V_209 , V_208 ) ;
F_71 ( V_209 ) ;
F_32 ( 200 ) ;
}
static void F_60 ( struct V_4 * V_5 )
{
struct V_43 * V_44 = V_5 -> V_44 ;
struct V_45 * V_46 = V_44 -> V_47 ;
T_4 V_208 ;
V_208 = F_20 ( V_209 ) ;
V_208 &= ~ V_176 ;
F_31 ( V_209 , V_208 ) ;
F_71 ( V_209 ) ;
F_32 ( 200 ) ;
}
static void F_84 ( struct V_1 * V_1 , int V_24 )
{
int V_88 , V_39 ;
if ( V_1 -> V_15 [ V_166 ] < 0x11 )
return;
if ( V_24 != V_210 ) {
V_88 = F_35 ( V_1 , V_211 ,
V_212 ) ;
if ( V_88 != 1 )
F_61 ( L_35 ) ;
} else {
for ( V_39 = 0 ; V_39 < 3 ; V_39 ++ ) {
V_88 = F_35 ( V_1 ,
V_211 ,
V_213 ) ;
if ( V_88 == 1 )
break;
F_30 ( 1 ) ;
}
}
}
static void F_85 ( struct V_4 * V_5 )
{
struct V_1 * V_1 = F_4 ( V_5 ) ;
F_83 ( V_1 ) ;
F_81 ( V_1 ) ;
F_39 ( V_1 ) ;
F_84 ( V_1 , V_210 ) ;
F_86 ( V_1 ) ;
F_41 ( V_1 , false ) ;
}
static void F_87 ( struct V_4 * V_5 )
{
struct V_1 * V_1 = F_4 ( V_5 ) ;
struct V_43 * V_44 = V_5 -> V_44 ;
struct V_150 * V_150 = F_48 ( V_1 -> V_2 . V_2 . V_147 ) ;
F_39 ( V_1 ) ;
F_84 ( V_1 , V_210 ) ;
F_88 ( V_1 ) ;
F_79 ( V_1 ) ;
F_41 ( V_1 , true ) ;
F_89 ( V_1 ) ;
F_82 ( V_1 ) ;
V_1 -> V_214 = V_210 ;
if ( F_64 ( V_44 ) )
F_90 ( V_44 , V_150 -> V_151 ) ;
}
static void
F_91 ( struct V_4 * V_5 , int V_24 )
{
struct V_1 * V_1 = F_4 ( V_5 ) ;
struct V_43 * V_44 = V_5 -> V_44 ;
struct V_45 * V_46 = V_44 -> V_47 ;
T_2 V_215 = F_20 ( V_1 -> V_67 ) ;
if ( V_24 != V_210 ) {
F_83 ( V_1 ) ;
F_81 ( V_1 ) ;
F_39 ( V_1 ) ;
F_84 ( V_1 , V_24 ) ;
F_86 ( V_1 ) ;
F_41 ( V_1 , false ) ;
if ( F_3 ( V_1 ) )
F_60 ( V_5 ) ;
} else {
if ( F_3 ( V_1 ) )
F_59 ( V_5 ) ;
F_39 ( V_1 ) ;
F_84 ( V_1 , V_24 ) ;
if ( ! ( V_215 & V_216 ) ) {
F_88 ( V_1 ) ;
F_79 ( V_1 ) ;
F_41 ( V_1 , true ) ;
F_89 ( V_1 ) ;
} else
F_41 ( V_1 , false ) ;
F_82 ( V_1 ) ;
}
V_1 -> V_214 = V_24 ;
}
static bool
F_92 ( struct V_1 * V_1 , T_3 V_87 ,
T_1 * V_65 , int V_70 )
{
int V_88 , V_39 ;
for ( V_39 = 0 ; V_39 < 3 ; V_39 ++ ) {
V_88 = F_36 ( V_1 , V_87 , V_65 ,
V_70 ) ;
if ( V_88 == V_70 )
return true ;
F_30 ( 1 ) ;
}
return false ;
}
static bool
F_93 ( struct V_1 * V_1 , T_1 V_217 [ V_218 ] )
{
return F_92 ( V_1 ,
V_219 ,
V_217 ,
V_218 ) ;
}
static T_1
F_94 ( T_1 V_217 [ V_218 ] ,
int V_220 )
{
return V_217 [ V_220 - V_219 ] ;
}
static T_1
F_95 ( T_1 V_221 [ 2 ] ,
int V_222 )
{
int V_223 = ( ( V_222 & 1 ) ?
V_224 :
V_225 ) ;
T_1 V_226 = V_221 [ V_222 >> 1 ] ;
return ( ( V_226 >> V_223 ) & 3 ) << V_227 ;
}
static T_1
F_96 ( T_1 V_221 [ 2 ] ,
int V_222 )
{
int V_223 = ( ( V_222 & 1 ) ?
V_228 :
V_229 ) ;
T_1 V_226 = V_221 [ V_222 >> 1 ] ;
return ( ( V_226 >> V_223 ) & 3 ) << V_230 ;
}
static T_1
F_97 ( struct V_1 * V_1 )
{
struct V_43 * V_44 = V_1 -> V_2 . V_2 . V_44 ;
if ( F_28 ( V_44 ) && F_3 ( V_1 ) )
return V_231 ;
else if ( F_64 ( V_44 ) && ! F_3 ( V_1 ) )
return V_232 ;
else
return V_231 ;
}
static T_1
F_98 ( struct V_1 * V_1 , T_1 V_233 )
{
struct V_43 * V_44 = V_1 -> V_2 . V_2 . V_44 ;
if ( F_28 ( V_44 ) && F_3 ( V_1 ) ) {
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
F_99 ( struct V_1 * V_1 , T_1 V_217 [ V_218 ] )
{
T_1 V_40 = 0 ;
T_1 V_240 = 0 ;
int V_222 ;
T_1 * V_221 = V_217 + ( V_241 - V_219 ) ;
T_1 V_242 ;
T_1 V_243 ;
for ( V_222 = 0 ; V_222 < V_1 -> V_11 ; V_222 ++ ) {
T_1 V_244 = F_95 ( V_221 , V_222 ) ;
T_1 V_245 = F_96 ( V_221 , V_222 ) ;
if ( V_244 > V_40 )
V_40 = V_244 ;
if ( V_245 > V_240 )
V_240 = V_245 ;
}
V_242 = F_97 ( V_1 ) ;
if ( V_40 >= V_242 )
V_40 = V_242 | V_246 ;
V_243 = F_98 ( V_1 , V_40 ) ;
if ( V_240 >= V_243 )
V_240 = V_243 | V_247 ;
for ( V_222 = 0 ; V_222 < 4 ; V_222 ++ )
V_1 -> V_248 [ V_222 ] = V_40 | V_240 ;
}
static T_2
F_100 ( T_1 V_248 )
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
F_101 ( T_1 V_248 )
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
F_25 ( L_36
L_37 , V_249 ) ;
return V_258 ;
}
}
static T_2
F_102 ( T_1 V_248 )
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
F_25 ( L_36
L_37 , V_249 ) ;
return V_270 ;
}
}
static T_1
F_103 ( T_1 V_217 [ V_218 ] ,
int V_222 )
{
int V_223 = ( V_222 & 1 ) * 4 ;
T_1 V_226 = V_217 [ V_222 >> 1 ] ;
return ( V_226 >> V_223 ) & 0xf ;
}
static bool
F_104 ( T_1 V_217 [ V_218 ] , int V_11 )
{
int V_222 ;
T_1 V_271 ;
for ( V_222 = 0 ; V_222 < V_11 ; V_222 ++ ) {
V_271 = F_103 ( V_217 , V_222 ) ;
if ( ( V_271 & V_272 ) == 0 )
return false ;
}
return true ;
}
static bool
F_105 ( struct V_1 * V_1 , T_1 V_217 [ V_218 ] )
{
T_1 V_273 ;
T_1 V_271 ;
int V_222 ;
V_273 = F_94 ( V_217 ,
V_274 ) ;
if ( ( V_273 & V_275 ) == 0 )
return false ;
for ( V_222 = 0 ; V_222 < V_1 -> V_11 ; V_222 ++ ) {
V_271 = F_103 ( V_217 , V_222 ) ;
if ( ( V_271 & V_276 ) != V_276 )
return false ;
}
return true ;
}
static bool
F_106 ( struct V_1 * V_1 ,
T_2 V_277 ,
T_1 V_278 )
{
struct V_43 * V_44 = V_1 -> V_2 . V_2 . V_44 ;
struct V_45 * V_46 = V_44 -> V_47 ;
int V_88 ;
F_31 ( V_1 -> V_67 , V_277 ) ;
F_71 ( V_1 -> V_67 ) ;
F_35 ( V_1 ,
V_279 ,
V_278 ) ;
V_88 = F_34 ( V_1 ,
V_280 ,
V_1 -> V_248 ,
V_1 -> V_11 ) ;
if ( V_88 != V_1 -> V_11 )
return false ;
return true ;
}
static void
F_88 ( struct V_1 * V_1 )
{
struct V_43 * V_44 = V_1 -> V_2 . V_2 . V_44 ;
struct V_45 * V_46 = V_44 -> V_47 ;
struct V_150 * V_150 = F_48 ( V_1 -> V_2 . V_2 . V_147 ) ;
int V_39 ;
T_1 V_281 ;
bool V_282 = false ;
int V_283 , V_284 ;
T_4 V_285 ;
T_2 V_154 = V_1 -> V_154 ;
if ( ! F_64 ( V_44 ) ) {
F_31 ( V_1 -> V_67 , V_1 -> V_154 ) ;
F_71 ( V_1 -> V_67 ) ;
F_107 ( V_44 , V_150 -> V_151 ) ;
}
F_34 ( V_1 , V_286 ,
V_1 -> V_163 ,
V_164 ) ;
V_154 |= V_216 ;
if ( F_64 ( V_44 ) && ( F_28 ( V_44 ) || ! F_3 ( V_1 ) ) )
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
if ( F_28 ( V_44 ) && F_3 ( V_1 ) ) {
V_249 = F_102 ( V_1 -> V_248 [ 0 ] ) ;
V_154 = ( V_154 & ~ V_289 ) | V_249 ;
} else if ( F_27 ( V_44 ) && F_3 ( V_1 ) ) {
V_249 = F_101 ( V_1 -> V_248 [ 0 ] ) ;
V_154 = ( V_154 & ~ V_290 ) | V_249 ;
} else {
V_249 = F_100 ( V_1 -> V_248 [ 0 ] ) ;
F_25 ( L_38 , V_249 ) ;
V_154 = ( V_154 & ~ ( V_291 | V_292 ) ) | V_249 ;
}
if ( F_64 ( V_44 ) && ( F_28 ( V_44 ) || ! F_3 ( V_1 ) ) )
V_285 = V_154 | V_293 ;
else
V_285 = V_154 | V_294 ;
if ( ! F_106 ( V_1 , V_285 ,
V_295 |
V_296 ) )
break;
F_32 ( 100 ) ;
if ( ! F_93 ( V_1 , V_217 ) ) {
F_33 ( L_39 ) ;
break;
}
if ( F_104 ( V_217 , V_1 -> V_11 ) ) {
F_25 ( L_40 ) ;
V_282 = true ;
break;
}
for ( V_39 = 0 ; V_39 < V_1 -> V_11 ; V_39 ++ )
if ( ( V_1 -> V_248 [ V_39 ] & V_246 ) == 0 )
break;
if ( V_39 == V_1 -> V_11 ) {
++ V_284 ;
if ( V_284 == 5 ) {
F_25 ( L_41 ) ;
break;
}
memset ( V_1 -> V_248 , 0 , 4 ) ;
V_283 = 0 ;
continue;
}
if ( ( V_1 -> V_248 [ 0 ] & V_234 ) == V_281 ) {
++ V_283 ;
if ( V_283 == 5 ) {
F_25 ( L_42 ) ;
break;
}
} else
V_283 = 0 ;
V_281 = V_1 -> V_248 [ 0 ] & V_234 ;
F_99 ( V_1 , V_217 ) ;
}
V_1 -> V_154 = V_154 ;
}
static void
F_89 ( struct V_1 * V_1 )
{
struct V_43 * V_44 = V_1 -> V_2 . V_2 . V_44 ;
struct V_45 * V_46 = V_44 -> V_47 ;
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
F_33 ( L_43 ) ;
F_86 ( V_1 ) ;
break;
}
if ( F_28 ( V_44 ) && F_3 ( V_1 ) ) {
V_249 = F_102 ( V_1 -> V_248 [ 0 ] ) ;
V_154 = ( V_154 & ~ V_289 ) | V_249 ;
} else if ( F_27 ( V_44 ) && F_3 ( V_1 ) ) {
V_249 = F_101 ( V_1 -> V_248 [ 0 ] ) ;
V_154 = ( V_154 & ~ V_290 ) | V_249 ;
} else {
V_249 = F_100 ( V_1 -> V_248 [ 0 ] ) ;
V_154 = ( V_154 & ~ ( V_291 | V_292 ) ) | V_249 ;
}
if ( F_64 ( V_44 ) && ( F_28 ( V_44 ) || ! F_3 ( V_1 ) ) )
V_285 = V_154 | V_300 ;
else
V_285 = V_154 | V_301 ;
if ( ! F_106 ( V_1 , V_285 ,
V_302 |
V_296 ) )
break;
F_32 ( 400 ) ;
if ( ! F_93 ( V_1 , V_217 ) )
break;
if ( ! F_104 ( V_217 , V_1 -> V_11 ) ) {
F_88 ( V_1 ) ;
V_299 ++ ;
continue;
}
if ( F_105 ( V_1 , V_217 ) ) {
V_297 = true ;
break;
}
if ( V_298 > 5 ) {
F_86 ( V_1 ) ;
F_88 ( V_1 ) ;
V_298 = 0 ;
V_299 ++ ;
continue;
}
F_99 ( V_1 , V_217 ) ;
++ V_298 ;
}
if ( F_64 ( V_44 ) && ( F_28 ( V_44 ) || ! F_3 ( V_1 ) ) )
V_285 = V_154 | V_174 ;
else
V_285 = V_154 | V_180 ;
F_31 ( V_1 -> V_67 , V_285 ) ;
F_71 ( V_1 -> V_67 ) ;
F_35 ( V_1 ,
V_279 , V_303 ) ;
}
static void
F_86 ( struct V_1 * V_1 )
{
struct V_43 * V_44 = V_1 -> V_2 . V_2 . V_44 ;
struct V_45 * V_46 = V_44 -> V_47 ;
T_2 V_154 = V_1 -> V_154 ;
if ( ( F_20 ( V_1 -> V_67 ) & V_216 ) == 0 )
return;
F_25 ( L_34 ) ;
if ( F_1 ( V_1 ) ) {
V_154 &= ~ V_176 ;
F_31 ( V_1 -> V_67 , V_154 ) ;
F_71 ( V_1 -> V_67 ) ;
F_32 ( 100 ) ;
}
if ( F_64 ( V_44 ) && ( F_28 ( V_44 ) || ! F_3 ( V_1 ) ) ) {
V_154 &= ~ V_287 ;
F_31 ( V_1 -> V_67 , V_154 | V_304 ) ;
} else {
V_154 &= ~ V_288 ;
F_31 ( V_1 -> V_67 , V_154 | V_305 ) ;
}
F_71 ( V_1 -> V_67 ) ;
F_30 ( 17 ) ;
if ( F_1 ( V_1 ) ) {
if ( F_64 ( V_44 ) && ( F_28 ( V_44 ) || ! F_3 ( V_1 ) ) )
V_154 |= V_174 ;
else
V_154 |= V_180 ;
}
if ( ! F_64 ( V_44 ) &&
F_20 ( V_1 -> V_67 ) & V_181 ) {
struct V_146 * V_147 = V_1 -> V_2 . V_2 . V_147 ;
V_154 &= ~ V_181 ;
F_31 ( V_1 -> V_67 , V_154 ) ;
if ( V_147 == NULL ) {
F_71 ( V_1 -> V_67 ) ;
F_30 ( 50 ) ;
} else
F_107 ( V_44 , F_48 ( V_147 ) -> V_151 ) ;
}
V_154 &= ~ V_162 ;
F_31 ( V_1 -> V_67 , V_154 & ~ V_216 ) ;
F_71 ( V_1 -> V_67 ) ;
F_30 ( V_1 -> V_196 ) ;
}
static bool
F_108 ( struct V_1 * V_1 )
{
if ( F_92 ( V_1 , 0x000 , V_1 -> V_15 ,
sizeof( V_1 -> V_15 ) ) &&
( V_1 -> V_15 [ V_166 ] != 0 ) ) {
return true ;
}
return false ;
}
static bool
F_109 ( struct V_1 * V_1 , T_5 * V_306 )
{
int V_88 ;
V_88 = F_92 ( V_1 ,
V_307 ,
V_306 , 1 ) ;
if ( ! V_88 )
return false ;
return true ;
}
static void
F_110 ( struct V_1 * V_1 )
{
F_35 ( V_1 , V_308 , V_309 ) ;
}
static void
F_111 ( struct V_1 * V_1 )
{
T_5 V_306 ;
T_5 V_217 [ V_218 ] ;
if ( V_1 -> V_214 != V_210 )
return;
if ( ! V_1 -> V_2 . V_2 . V_147 )
return;
if ( ! F_93 ( V_1 , V_217 ) ) {
F_86 ( V_1 ) ;
return;
}
if ( ! F_108 ( V_1 ) ) {
F_86 ( V_1 ) ;
return;
}
if ( V_1 -> V_15 [ V_166 ] >= 0x11 &&
F_109 ( V_1 , & V_306 ) ) {
F_35 ( V_1 ,
V_307 ,
V_306 ) ;
if ( V_306 & V_310 )
F_110 ( V_1 ) ;
if ( V_306 & ( V_311 | V_312 ) )
F_61 ( L_44 ) ;
}
if ( ! F_105 ( V_1 , V_217 ) ) {
F_25 ( L_45 ,
F_112 ( & V_1 -> V_2 . V_2 ) ) ;
F_88 ( V_1 ) ;
F_89 ( V_1 ) ;
}
}
static enum V_313
F_113 ( struct V_1 * V_1 )
{
if ( F_108 ( V_1 ) )
return V_314 ;
return V_315 ;
}
static enum V_313
F_114 ( struct V_1 * V_1 )
{
enum V_313 V_71 ;
if ( F_1 ( V_1 ) ) {
V_71 = F_115 ( V_1 -> V_2 . V_2 . V_44 ) ;
if ( V_71 == V_316 )
V_71 = V_314 ;
return V_71 ;
}
return F_113 ( V_1 ) ;
}
static enum V_313
F_116 ( struct V_1 * V_1 )
{
struct V_43 * V_44 = V_1 -> V_2 . V_2 . V_44 ;
struct V_45 * V_46 = V_44 -> V_47 ;
T_2 V_317 , V_318 ;
switch ( V_1 -> V_67 ) {
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
V_317 = F_20 ( V_325 ) ;
if ( ( V_317 & V_318 ) == 0 )
return V_315 ;
return F_113 ( V_1 ) ;
}
static struct V_326 *
F_117 ( struct V_6 * V_7 , struct V_101 * V_102 )
{
struct V_1 * V_1 = F_6 ( V_7 ) ;
struct V_326 * V_326 ;
F_39 ( V_1 ) ;
V_326 = F_118 ( V_7 , V_102 ) ;
F_41 ( V_1 , false ) ;
return V_326 ;
}
static int
F_119 ( struct V_6 * V_7 , struct V_101 * V_102 )
{
struct V_1 * V_1 = F_6 ( V_7 ) ;
int V_88 ;
F_39 ( V_1 ) ;
V_88 = F_120 ( V_7 , V_102 ) ;
F_41 ( V_1 , false ) ;
return V_88 ;
}
static enum V_313
F_121 ( struct V_6 * V_7 , bool V_327 )
{
struct V_1 * V_1 = F_6 ( V_7 ) ;
struct V_43 * V_44 = V_1 -> V_2 . V_2 . V_44 ;
enum V_313 V_71 ;
struct V_326 * V_326 = NULL ;
V_1 -> V_161 = false ;
if ( F_29 ( V_44 ) )
V_71 = F_114 ( V_1 ) ;
else
V_71 = F_116 ( V_1 ) ;
F_25 ( L_46 ,
V_1 -> V_15 [ 0 ] , V_1 -> V_15 [ 1 ] , V_1 -> V_15 [ 2 ] ,
V_1 -> V_15 [ 3 ] , V_1 -> V_15 [ 4 ] , V_1 -> V_15 [ 5 ] ,
V_1 -> V_15 [ 6 ] , V_1 -> V_15 [ 7 ] ) ;
if ( V_71 != V_314 )
return V_71 ;
if ( V_1 -> V_328 != V_329 ) {
V_1 -> V_161 = ( V_1 -> V_328 == V_330 ) ;
} else {
V_326 = F_117 ( V_7 , & V_1 -> V_102 ) ;
if ( V_326 ) {
V_1 -> V_161 = F_122 ( V_326 ) ;
V_7 -> V_331 . V_332 = NULL ;
F_123 ( V_326 ) ;
}
}
return V_314 ;
}
static int F_124 ( struct V_6 * V_7 )
{
struct V_1 * V_1 = F_6 ( V_7 ) ;
struct V_43 * V_44 = V_1 -> V_2 . V_2 . V_44 ;
struct V_45 * V_46 = V_44 -> V_47 ;
int V_88 ;
V_88 = F_119 ( V_7 , & V_1 -> V_102 ) ;
if ( V_88 ) {
if ( F_1 ( V_1 ) && ! V_1 -> V_30 ) {
struct V_23 * V_333 ;
F_49 (newmode, &connector->probed_modes,
head) {
if ( ( V_333 -> type & V_334 ) ) {
V_1 -> V_30 =
F_125 ( V_44 , V_333 ) ;
break;
}
}
}
return V_88 ;
}
if ( F_1 ( V_1 ) ) {
if ( V_1 -> V_30 == NULL && V_46 -> V_335 != NULL ) {
V_1 -> V_30 =
F_125 ( V_44 , V_46 -> V_335 ) ;
if ( V_1 -> V_30 ) {
V_1 -> V_30 -> type |=
V_334 ;
}
}
if ( V_1 -> V_30 ) {
struct V_23 * V_24 ;
V_24 = F_125 ( V_44 , V_1 -> V_30 ) ;
F_126 ( V_7 , V_24 ) ;
return 1 ;
}
}
return 0 ;
}
static bool
F_127 ( struct V_6 * V_7 )
{
struct V_1 * V_1 = F_6 ( V_7 ) ;
struct V_326 * V_326 ;
bool V_161 = false ;
V_326 = F_117 ( V_7 , & V_1 -> V_102 ) ;
if ( V_326 ) {
V_161 = F_122 ( V_326 ) ;
V_7 -> V_331 . V_332 = NULL ;
F_123 ( V_326 ) ;
}
return V_161 ;
}
static int
F_128 ( struct V_6 * V_7 ,
struct V_336 * V_337 ,
T_6 V_338 )
{
struct V_45 * V_46 = V_7 -> V_44 -> V_47 ;
struct V_1 * V_1 = F_6 ( V_7 ) ;
int V_88 ;
V_88 = F_129 ( V_7 , V_337 , V_338 ) ;
if ( V_88 )
return V_88 ;
if ( V_337 == V_46 -> V_339 ) {
int V_39 = V_338 ;
bool V_161 ;
if ( V_39 == V_1 -> V_328 )
return 0 ;
V_1 -> V_328 = V_39 ;
if ( V_39 == V_329 )
V_161 = F_127 ( V_7 ) ;
else
V_161 = ( V_39 == V_330 ) ;
if ( V_161 == V_1 -> V_161 )
return 0 ;
V_1 -> V_161 = V_161 ;
goto V_340;
}
if ( V_337 == V_46 -> V_341 ) {
if ( V_338 == ! ! V_1 -> V_179 )
return 0 ;
V_1 -> V_179 = V_338 ? V_342 : 0 ;
goto V_340;
}
return - V_343 ;
V_340:
if ( V_1 -> V_2 . V_2 . V_147 ) {
struct V_146 * V_147 = V_1 -> V_2 . V_2 . V_147 ;
F_130 ( V_147 , & V_147 -> V_24 ,
V_147 -> V_344 , V_147 -> V_345 ,
V_147 -> V_346 ) ;
}
return 0 ;
}
static void
F_131 ( struct V_6 * V_7 )
{
struct V_43 * V_44 = V_7 -> V_44 ;
if ( F_132 ( V_44 ) )
F_133 ( V_44 ) ;
F_134 ( V_7 ) ;
F_135 ( V_7 ) ;
F_123 ( V_7 ) ;
}
static void F_136 ( struct V_4 * V_5 )
{
struct V_1 * V_1 = F_4 ( V_5 ) ;
F_137 ( & V_1 -> V_102 ) ;
F_138 ( V_5 ) ;
if ( F_1 ( V_1 ) ) {
F_139 ( & V_1 -> V_199 ) ;
F_72 ( V_1 ) ;
}
F_123 ( V_1 ) ;
}
static void
F_140 ( struct V_8 * V_8 )
{
struct V_1 * V_1 = F_5 ( V_8 , struct V_1 , V_2 ) ;
F_111 ( V_1 ) ;
}
int
F_141 ( struct V_146 * V_147 )
{
struct V_43 * V_44 = V_147 -> V_44 ;
struct V_148 * V_149 = & V_44 -> V_149 ;
struct V_4 * V_5 ;
F_49 (encoder, &mode_config->encoder_list, head) {
struct V_1 * V_1 ;
if ( V_5 -> V_147 != V_147 )
continue;
V_1 = F_4 ( V_5 ) ;
if ( V_1 -> V_2 . type == V_152 ||
V_1 -> V_2 . type == V_3 )
return V_1 -> V_67 ;
}
return - 1 ;
}
bool F_132 ( struct V_43 * V_44 )
{
struct V_45 * V_46 = V_44 -> V_47 ;
struct V_347 * V_348 ;
int V_39 ;
if ( ! V_46 -> V_349 )
return false ;
for ( V_39 = 0 ; V_39 < V_46 -> V_349 ; V_39 ++ ) {
V_348 = V_46 -> V_350 + V_39 ;
if ( V_348 -> V_351 == V_352 &&
V_348 -> V_353 == V_354 )
return true ;
}
return false ;
}
static void
F_142 ( struct V_1 * V_1 , struct V_6 * V_7 )
{
F_143 ( V_7 ) ;
F_144 ( V_7 ) ;
}
void
F_145 ( struct V_43 * V_44 , int V_67 )
{
struct V_45 * V_46 = V_44 -> V_47 ;
struct V_6 * V_7 ;
struct V_1 * V_1 ;
struct V_8 * V_8 ;
struct V_120 * V_120 ;
const char * V_121 = NULL ;
int type ;
V_1 = F_146 ( sizeof( struct V_1 ) , V_355 ) ;
if ( ! V_1 )
return;
V_1 -> V_67 = V_67 ;
V_1 -> V_214 = - 1 ;
V_120 = F_146 ( sizeof( struct V_120 ) , V_355 ) ;
if ( ! V_120 ) {
F_123 ( V_1 ) ;
return;
}
V_8 = & V_1 -> V_2 ;
if ( F_29 ( V_44 ) && V_67 == V_356 )
if ( F_132 ( V_44 ) )
V_1 -> F_2 = true ;
if ( V_67 == V_209 || F_2 ( V_1 ) ) {
type = V_357 ;
V_8 -> type = V_3 ;
} else {
type = V_358 ;
V_8 -> type = V_152 ;
}
V_7 = & V_120 -> V_2 ;
F_147 ( V_44 , V_7 , & V_359 , type ) ;
F_148 ( V_7 , & V_360 ) ;
V_7 -> V_361 = V_362 ;
if ( V_67 == V_319 || V_67 == V_363 )
V_8 -> V_364 = ( 1 << V_365 ) ;
else if ( V_67 == V_321 || V_67 == V_366 )
V_8 -> V_364 = ( 1 << V_367 ) ;
else if ( V_67 == V_323 || V_67 == V_356 )
V_8 -> V_364 = ( 1 << V_368 ) ;
if ( F_1 ( V_1 ) ) {
V_8 -> V_364 = ( 1 << V_369 ) ;
F_149 ( & V_1 -> V_199 ,
F_73 ) ;
}
V_8 -> V_370 = ( 1 << 0 ) | ( 1 << 1 ) | ( 1 << 2 ) ;
V_7 -> V_371 = true ;
V_7 -> V_372 = 0 ;
F_150 ( V_44 , & V_8 -> V_2 , & V_373 ,
V_374 ) ;
F_151 ( & V_8 -> V_2 , & V_375 ) ;
F_152 ( V_120 , V_8 ) ;
F_153 ( V_7 ) ;
switch ( V_67 ) {
case V_209 :
V_121 = L_47 ;
break;
case V_319 :
case V_363 :
V_46 -> V_376 |=
V_377 ;
V_121 = L_48 ;
break;
case V_321 :
case V_366 :
V_46 -> V_376 |=
V_378 ;
V_121 = L_49 ;
break;
case V_323 :
case V_356 :
V_46 -> V_376 |=
V_379 ;
V_121 = L_50 ;
break;
}
if ( F_1 ( V_1 ) ) {
bool V_88 ;
struct V_380 V_381 , V_382 ;
T_4 V_383 , V_384 , V_385 ;
V_383 = F_20 ( V_386 ) ;
V_384 = F_20 ( V_387 ) ;
V_385 = F_20 ( V_388 ) ;
V_381 . V_389 = ( V_383 & V_390 ) >>
V_391 ;
V_381 . V_392 = ( V_383 & V_393 ) >>
V_394 ;
V_381 . V_395 = ( V_384 & V_396 ) >>
V_397 ;
V_381 . V_398 = ( V_384 & V_399 ) >>
V_400 ;
V_381 . V_401 = ( ( V_385 & V_402 ) >>
V_403 ) * 1000 ;
F_25 ( L_51 ,
V_381 . V_389 , V_381 . V_392 , V_381 . V_395 , V_381 . V_398 , V_381 . V_401 ) ;
V_382 = V_46 -> V_404 . V_405 ;
F_25 ( L_52 ,
V_382 . V_389 , V_382 . V_392 , V_382 . V_395 , V_382 . V_398 , V_382 . V_401 ) ;
#define F_154 ( T_7 ) ((max(cur.field, vbt.field) + 9) / 10)
V_1 -> V_195 = F_154 ( V_389 ) ;
V_1 -> V_206 = F_154 ( V_392 ) ;
V_1 -> V_207 = F_154 ( V_395 ) ;
V_1 -> V_196 = F_154 ( V_398 ) ;
V_1 -> V_202 = F_154 ( V_401 ) ;
F_25 ( L_53 ,
V_1 -> V_195 , V_1 -> V_196 ,
V_1 -> V_202 ) ;
F_25 ( L_54 ,
V_1 -> V_206 , V_1 -> V_207 ) ;
F_39 ( V_1 ) ;
V_88 = F_108 ( V_1 ) ;
F_41 ( V_1 , false ) ;
if ( V_88 ) {
if ( V_1 -> V_15 [ V_166 ] >= 0x11 )
V_46 -> V_406 =
V_1 -> V_15 [ V_407 ] &
V_408 ;
} else {
F_155 ( L_55 ) ;
F_136 ( & V_1 -> V_2 . V_2 ) ;
F_131 ( & V_120 -> V_2 ) ;
return;
}
}
F_38 ( V_1 , V_120 , V_121 ) ;
V_8 -> V_409 = F_140 ;
if ( F_1 ( V_1 ) ) {
V_46 -> V_410 = V_7 ;
F_156 ( V_44 ) ;
}
F_142 ( V_1 , V_7 ) ;
if ( F_157 ( V_44 ) && ! F_158 ( V_44 ) ) {
T_4 V_317 = F_20 ( V_411 ) ;
F_31 ( V_411 , ( V_317 & ~ 0xf ) | 0xd ) ;
}
}
