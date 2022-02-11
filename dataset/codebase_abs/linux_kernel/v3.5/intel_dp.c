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
if ( V_24 -> V_36 & V_37 )
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
V_75 = 63 ;
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
if ( V_74 & ( V_85 |
V_86 ) )
continue;
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
F_37 ( struct V_104 * V_105 , int V_24 ,
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
if ( V_24 & V_111 )
V_92 [ 0 ] = V_112 << 4 ;
else
V_92 [ 0 ] = V_113 << 4 ;
if ( ! ( V_24 & V_114 ) )
V_92 [ 0 ] |= V_115 << 4 ;
V_92 [ 1 ] = V_90 >> 8 ;
V_92 [ 2 ] = V_90 ;
switch ( V_24 ) {
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
if ( V_24 == V_111 ) {
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
F_42 ( struct V_4 * V_5 , struct V_23 * V_24 ,
struct V_23 * V_25 )
{
struct V_46 * V_47 = V_5 -> V_47 ;
struct V_1 * V_1 = F_4 ( V_5 ) ;
int V_11 , clock ;
int V_14 = F_10 ( V_1 ) ;
int V_134 = F_11 ( V_1 ) == V_13 ? 1 : 0 ;
int V_20 , V_27 ;
static int V_135 [ 2 ] = { V_12 , V_13 } ;
if ( F_1 ( V_1 ) && V_1 -> V_30 ) {
F_43 ( V_1 -> V_30 , V_25 ) ;
F_44 ( V_47 , V_136 ,
V_24 , V_25 ) ;
V_24 -> clock = V_1 -> V_30 -> clock ;
}
if ( V_24 -> V_36 & V_37 )
return false ;
F_25 ( L_15
L_16 ,
V_14 , V_135 [ V_134 ] , V_24 -> clock ) ;
if ( ! F_15 ( V_1 , V_24 , V_25 ) )
return false ;
V_20 = V_25 -> V_28 & V_29 ? 18 : 24 ;
V_27 = F_13 ( V_24 -> clock , V_20 ) ;
for ( V_11 = 1 ; V_11 <= V_14 ; V_11 <<= 1 ) {
for ( clock = 0 ; clock <= V_134 ; clock ++ ) {
int V_137 = F_14 ( F_12 ( V_135 [ clock ] ) , V_11 ) ;
if ( V_27 <= V_137 ) {
V_1 -> V_10 = V_135 [ clock ] ;
V_1 -> V_11 = V_11 ;
V_25 -> clock = F_12 ( V_1 -> V_10 ) ;
F_25 ( L_17
L_18 ,
V_1 -> V_10 , V_1 -> V_11 ,
V_25 -> clock , V_20 ) ;
F_25 ( L_19 ,
V_27 , V_137 ) ;
return true ;
}
}
}
return false ;
}
static void
F_45 ( T_2 * V_138 , T_2 * V_139 )
{
while ( * V_138 > 0xffffff || * V_139 > 0xffffff ) {
* V_138 >>= 1 ;
* V_139 >>= 1 ;
}
}
static void
F_46 ( int V_20 ,
int V_140 ,
int V_19 ,
int V_141 ,
struct V_142 * V_143 )
{
V_143 -> V_144 = 64 ;
V_143 -> V_145 = ( V_19 * V_20 ) >> 3 ;
V_143 -> V_146 = V_141 * V_140 ;
F_45 ( & V_143 -> V_145 , & V_143 -> V_146 ) ;
V_143 -> V_147 = V_19 ;
V_143 -> V_148 = V_141 ;
F_45 ( & V_143 -> V_147 , & V_143 -> V_148 ) ;
}
void
F_47 ( struct V_149 * V_150 , struct V_23 * V_24 ,
struct V_23 * V_25 )
{
struct V_46 * V_47 = V_150 -> V_47 ;
struct V_151 * V_152 = & V_47 -> V_152 ;
struct V_4 * V_5 ;
struct V_48 * V_49 = V_47 -> V_50 ;
struct V_153 * V_153 = F_48 ( V_150 ) ;
int V_11 = 4 ;
struct V_142 V_143 ;
int V_154 = V_153 -> V_154 ;
F_49 (encoder, &mode_config->encoder_list, head) {
struct V_1 * V_1 ;
if ( V_5 -> V_150 != V_150 )
continue;
V_1 = F_4 ( V_5 ) ;
if ( V_1 -> V_2 . type == V_155 ||
V_1 -> V_2 . type == V_3 )
{
V_11 = V_1 -> V_11 ;
break;
}
}
F_46 ( V_153 -> V_20 , V_11 ,
V_24 -> clock , V_25 -> clock , & V_143 ) ;
if ( F_29 ( V_47 ) ) {
F_31 ( F_50 ( V_154 ) ,
( ( V_143 . V_144 - 1 ) << V_156 ) |
V_143 . V_145 ) ;
F_31 ( F_51 ( V_154 ) , V_143 . V_146 ) ;
F_31 ( F_52 ( V_154 ) , V_143 . V_147 ) ;
F_31 ( F_53 ( V_154 ) , V_143 . V_148 ) ;
} else {
F_31 ( F_54 ( V_154 ) ,
( ( V_143 . V_144 - 1 ) << V_156 ) |
V_143 . V_145 ) ;
F_31 ( F_55 ( V_154 ) , V_143 . V_146 ) ;
F_31 ( F_56 ( V_154 ) , V_143 . V_147 ) ;
F_31 ( F_57 ( V_154 ) , V_143 . V_148 ) ;
}
}
static void
F_58 ( struct V_4 * V_5 , struct V_23 * V_24 ,
struct V_23 * V_25 )
{
struct V_46 * V_47 = V_5 -> V_47 ;
struct V_48 * V_49 = V_47 -> V_50 ;
struct V_1 * V_1 = F_4 ( V_5 ) ;
struct V_149 * V_150 = V_1 -> V_2 . V_2 . V_150 ;
struct V_153 * V_153 = F_48 ( V_150 ) ;
if ( F_1 ( V_1 ) ) {
if ( ! F_2 ( V_1 ) )
F_59 ( V_5 ) ;
else
F_60 ( V_5 ) ;
}
V_1 -> V_157 = F_20 ( V_1 -> V_70 ) & V_158 ;
V_1 -> V_157 |= V_159 | V_160 ;
V_1 -> V_157 |= V_159 | V_160 ;
switch ( V_1 -> V_11 ) {
case 1 :
V_1 -> V_157 |= V_161 ;
break;
case 2 :
V_1 -> V_157 |= V_162 ;
break;
case 4 :
V_1 -> V_157 |= V_163 ;
break;
}
if ( V_1 -> V_164 ) {
F_61 ( L_20 ,
F_62 ( V_153 -> V_154 ) ) ;
V_1 -> V_157 |= V_165 ;
F_63 ( V_5 , V_25 ) ;
}
memset ( V_1 -> V_166 , 0 , V_167 ) ;
V_1 -> V_166 [ 0 ] = V_1 -> V_10 ;
V_1 -> V_166 [ 1 ] = V_1 -> V_11 ;
V_1 -> V_166 [ 8 ] = V_168 ;
if ( V_1 -> V_15 [ V_169 ] >= 0x11 &&
( V_1 -> V_15 [ V_16 ] & V_170 ) ) {
V_1 -> V_166 [ 1 ] |= V_171 ;
}
if ( F_3 ( V_1 ) && F_28 ( V_47 ) ) {
if ( V_25 -> V_36 & V_172 )
V_1 -> V_157 |= V_173 ;
if ( V_25 -> V_36 & V_174 )
V_1 -> V_157 |= V_175 ;
V_1 -> V_157 |= V_176 ;
if ( V_1 -> V_166 [ 1 ] & V_171 )
V_1 -> V_157 |= V_177 ;
V_1 -> V_157 |= V_153 -> V_154 << 29 ;
V_1 -> V_157 |= V_178 ;
if ( V_25 -> clock < 200000 )
V_1 -> V_157 |= V_179 ;
else
V_1 -> V_157 |= V_180 ;
} else if ( ! F_64 ( V_47 ) || F_3 ( V_1 ) ) {
V_1 -> V_157 |= V_1 -> V_181 ;
if ( V_25 -> V_36 & V_172 )
V_1 -> V_157 |= V_173 ;
if ( V_25 -> V_36 & V_174 )
V_1 -> V_157 |= V_175 ;
V_1 -> V_157 |= V_182 ;
if ( V_1 -> V_166 [ 1 ] & V_171 )
V_1 -> V_157 |= V_177 ;
if ( V_153 -> V_154 == 1 )
V_1 -> V_157 |= V_183 ;
if ( F_3 ( V_1 ) ) {
V_1 -> V_157 |= V_178 ;
if ( V_25 -> clock < 200000 )
V_1 -> V_157 |= V_179 ;
else
V_1 -> V_157 |= V_180 ;
}
} else {
V_1 -> V_157 |= V_176 ;
}
}
static void F_65 ( struct V_1 * V_1 ,
T_4 V_184 ,
T_4 V_185 )
{
struct V_46 * V_47 = V_1 -> V_2 . V_2 . V_47 ;
struct V_48 * V_49 = V_47 -> V_50 ;
F_25 ( L_21 ,
V_184 , V_185 ,
F_20 ( V_62 ) ,
F_20 ( V_64 ) ) ;
if ( F_66 ( ( F_20 ( V_62 ) & V_184 ) == V_185 , 5000 , 10 ) ) {
F_33 ( L_22 ,
F_20 ( V_62 ) ,
F_20 ( V_64 ) ) ;
}
}
static void F_67 ( struct V_1 * V_1 )
{
F_25 ( L_23 ) ;
F_65 ( V_1 , V_186 , V_187 ) ;
}
static void F_68 ( struct V_1 * V_1 )
{
F_25 ( L_24 ) ;
F_65 ( V_1 , V_188 , V_189 ) ;
}
static void F_69 ( struct V_1 * V_1 )
{
F_25 ( L_25 ) ;
F_65 ( V_1 , V_190 , V_191 ) ;
}
static T_4 F_70 ( struct V_48 * V_49 )
{
T_4 V_192 = F_20 ( V_64 ) ;
V_192 &= ~ V_193 ;
V_192 |= V_194 ;
return V_192 ;
}
static void F_39 ( struct V_1 * V_1 )
{
struct V_46 * V_47 = V_1 -> V_2 . V_2 . V_47 ;
struct V_48 * V_49 = V_47 -> V_50 ;
T_4 V_195 ;
if ( ! F_1 ( V_1 ) )
return;
F_25 ( L_26 ) ;
F_24 ( V_1 -> V_196 ,
L_27 ) ;
V_1 -> V_196 = true ;
if ( F_22 ( V_1 ) ) {
F_25 ( L_28 ) ;
return;
}
if ( ! F_21 ( V_1 ) )
F_69 ( V_1 ) ;
V_195 = F_70 ( V_49 ) ;
V_195 |= V_65 ;
F_31 ( V_64 , V_195 ) ;
F_71 ( V_64 ) ;
F_25 ( L_29 ,
F_20 ( V_62 ) , F_20 ( V_64 ) ) ;
if ( ! F_21 ( V_1 ) ) {
F_25 ( L_30 ) ;
F_30 ( V_1 -> V_197 ) ;
}
}
static void F_72 ( struct V_1 * V_1 )
{
struct V_46 * V_47 = V_1 -> V_2 . V_2 . V_47 ;
struct V_48 * V_49 = V_47 -> V_50 ;
T_4 V_195 ;
if ( ! V_1 -> V_196 && F_22 ( V_1 ) ) {
V_195 = F_70 ( V_49 ) ;
V_195 &= ~ V_65 ;
F_31 ( V_64 , V_195 ) ;
F_71 ( V_64 ) ;
F_25 ( L_29 ,
F_20 ( V_62 ) , F_20 ( V_64 ) ) ;
F_30 ( V_1 -> V_198 ) ;
}
}
static void F_73 ( struct V_199 * V_200 )
{
struct V_1 * V_1 = F_5 ( F_74 ( V_200 ) ,
struct V_1 , V_201 ) ;
struct V_46 * V_47 = V_1 -> V_2 . V_2 . V_47 ;
F_75 ( & V_47 -> V_152 . V_202 ) ;
F_72 ( V_1 ) ;
F_76 ( & V_47 -> V_152 . V_202 ) ;
}
static void F_41 ( struct V_1 * V_1 , bool V_203 )
{
if ( ! F_1 ( V_1 ) )
return;
F_25 ( L_31 , V_1 -> V_196 ) ;
F_24 ( ! V_1 -> V_196 , L_32 ) ;
V_1 -> V_196 = false ;
if ( V_203 ) {
F_72 ( V_1 ) ;
} else {
F_77 ( & V_1 -> V_201 ,
F_78 ( V_1 -> V_204 * 5 ) ) ;
}
}
static void F_79 ( struct V_1 * V_1 )
{
struct V_46 * V_47 = V_1 -> V_2 . V_2 . V_47 ;
struct V_48 * V_49 = V_47 -> V_50 ;
T_4 V_195 ;
if ( ! F_1 ( V_1 ) )
return;
F_25 ( L_33 ) ;
if ( F_21 ( V_1 ) ) {
F_25 ( L_34 ) ;
return;
}
F_69 ( V_1 ) ;
V_195 = F_70 ( V_49 ) ;
if ( F_80 ( V_47 ) ) {
V_195 &= ~ V_205 ;
F_31 ( V_64 , V_195 ) ;
F_71 ( V_64 ) ;
}
V_195 |= V_206 ;
if ( ! F_80 ( V_47 ) )
V_195 |= V_205 ;
F_31 ( V_64 , V_195 ) ;
F_71 ( V_64 ) ;
F_67 ( V_1 ) ;
if ( F_80 ( V_47 ) ) {
V_195 |= V_205 ;
F_31 ( V_64 , V_195 ) ;
F_71 ( V_64 ) ;
}
}
static void F_81 ( struct V_1 * V_1 )
{
struct V_46 * V_47 = V_1 -> V_2 . V_2 . V_47 ;
struct V_48 * V_49 = V_47 -> V_50 ;
T_4 V_195 ;
if ( ! F_1 ( V_1 ) )
return;
F_25 ( L_35 ) ;
F_24 ( ! V_1 -> V_196 , L_36 ) ;
V_195 = F_70 ( V_49 ) ;
V_195 &= ~ ( V_206 | V_205 | V_207 ) ;
F_31 ( V_64 , V_195 ) ;
F_71 ( V_64 ) ;
F_68 ( V_1 ) ;
}
static void F_82 ( struct V_1 * V_1 )
{
struct V_46 * V_47 = V_1 -> V_2 . V_2 . V_47 ;
struct V_48 * V_49 = V_47 -> V_50 ;
T_4 V_195 ;
if ( ! F_1 ( V_1 ) )
return;
F_25 ( L_37 ) ;
F_30 ( V_1 -> V_208 ) ;
V_195 = F_70 ( V_49 ) ;
V_195 |= V_207 ;
F_31 ( V_64 , V_195 ) ;
F_71 ( V_64 ) ;
}
static void F_83 ( struct V_1 * V_1 )
{
struct V_46 * V_47 = V_1 -> V_2 . V_2 . V_47 ;
struct V_48 * V_49 = V_47 -> V_50 ;
T_4 V_195 ;
if ( ! F_1 ( V_1 ) )
return;
F_25 ( L_37 ) ;
V_195 = F_70 ( V_49 ) ;
V_195 &= ~ V_207 ;
F_31 ( V_64 , V_195 ) ;
F_71 ( V_64 ) ;
F_30 ( V_1 -> V_209 ) ;
}
static void F_59 ( struct V_4 * V_5 )
{
struct V_46 * V_47 = V_5 -> V_47 ;
struct V_48 * V_49 = V_47 -> V_50 ;
T_4 V_210 ;
F_25 ( L_37 ) ;
V_210 = F_20 ( V_211 ) ;
V_210 |= V_178 ;
F_31 ( V_211 , V_210 ) ;
F_71 ( V_211 ) ;
F_32 ( 200 ) ;
}
static void F_60 ( struct V_4 * V_5 )
{
struct V_46 * V_47 = V_5 -> V_47 ;
struct V_48 * V_49 = V_47 -> V_50 ;
T_4 V_210 ;
V_210 = F_20 ( V_211 ) ;
V_210 &= ~ V_178 ;
F_31 ( V_211 , V_210 ) ;
F_71 ( V_211 ) ;
F_32 ( 200 ) ;
}
static void F_84 ( struct V_1 * V_1 , int V_24 )
{
int V_91 , V_42 ;
if ( V_1 -> V_15 [ V_169 ] < 0x11 )
return;
if ( V_24 != V_212 ) {
V_91 = F_35 ( V_1 , V_213 ,
V_214 ) ;
if ( V_91 != 1 )
F_61 ( L_38 ) ;
} else {
for ( V_42 = 0 ; V_42 < 3 ; V_42 ++ ) {
V_91 = F_35 ( V_1 ,
V_213 ,
V_215 ) ;
if ( V_91 == 1 )
break;
F_30 ( 1 ) ;
}
}
}
static void F_85 ( struct V_4 * V_5 )
{
struct V_1 * V_1 = F_4 ( V_5 ) ;
F_39 ( V_1 ) ;
F_83 ( V_1 ) ;
F_81 ( V_1 ) ;
F_84 ( V_1 , V_212 ) ;
F_86 ( V_1 ) ;
F_41 ( V_1 , false ) ;
}
static void F_87 ( struct V_4 * V_5 )
{
struct V_1 * V_1 = F_4 ( V_5 ) ;
struct V_46 * V_47 = V_5 -> V_47 ;
struct V_153 * V_153 = F_48 ( V_1 -> V_2 . V_2 . V_150 ) ;
F_39 ( V_1 ) ;
F_84 ( V_1 , V_212 ) ;
F_88 ( V_1 ) ;
F_79 ( V_1 ) ;
F_41 ( V_1 , true ) ;
F_89 ( V_1 ) ;
F_82 ( V_1 ) ;
V_1 -> V_216 = V_212 ;
if ( F_64 ( V_47 ) )
F_90 ( V_47 , V_153 -> V_154 ) ;
}
static void
F_91 ( struct V_4 * V_5 , int V_24 )
{
struct V_1 * V_1 = F_4 ( V_5 ) ;
struct V_46 * V_47 = V_5 -> V_47 ;
struct V_48 * V_49 = V_47 -> V_50 ;
T_2 V_217 = F_20 ( V_1 -> V_70 ) ;
if ( V_24 != V_212 ) {
F_39 ( V_1 ) ;
F_83 ( V_1 ) ;
F_81 ( V_1 ) ;
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
if ( ! ( V_217 & V_218 ) ) {
F_88 ( V_1 ) ;
F_79 ( V_1 ) ;
F_41 ( V_1 , true ) ;
F_89 ( V_1 ) ;
} else
F_41 ( V_1 , false ) ;
F_82 ( V_1 ) ;
}
V_1 -> V_216 = V_24 ;
}
static bool
F_92 ( struct V_1 * V_1 , T_3 V_90 ,
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
F_93 ( struct V_1 * V_1 , T_1 V_219 [ V_220 ] )
{
return F_92 ( V_1 ,
V_221 ,
V_219 ,
V_220 ) ;
}
static T_1
F_94 ( T_1 V_219 [ V_220 ] ,
int V_222 )
{
return V_219 [ V_222 - V_221 ] ;
}
static T_1
F_95 ( T_1 V_223 [ 2 ] ,
int V_224 )
{
int V_225 = ( ( V_224 & 1 ) ?
V_226 :
V_227 ) ;
T_1 V_228 = V_223 [ V_224 >> 1 ] ;
return ( ( V_228 >> V_225 ) & 3 ) << V_229 ;
}
static T_1
F_96 ( T_1 V_223 [ 2 ] ,
int V_224 )
{
int V_225 = ( ( V_224 & 1 ) ?
V_230 :
V_231 ) ;
T_1 V_228 = V_223 [ V_224 >> 1 ] ;
return ( ( V_228 >> V_225 ) & 3 ) << V_232 ;
}
static T_1
F_97 ( struct V_1 * V_1 )
{
struct V_46 * V_47 = V_1 -> V_2 . V_2 . V_47 ;
if ( F_28 ( V_47 ) && F_3 ( V_1 ) )
return V_233 ;
else if ( F_64 ( V_47 ) && ! F_3 ( V_1 ) )
return V_234 ;
else
return V_233 ;
}
static T_1
F_98 ( struct V_1 * V_1 , T_1 V_235 )
{
struct V_46 * V_47 = V_1 -> V_2 . V_2 . V_47 ;
if ( F_28 ( V_47 ) && F_3 ( V_1 ) ) {
switch ( V_235 & V_236 ) {
case V_237 :
return V_238 ;
case V_239 :
case V_233 :
return V_240 ;
default:
return V_241 ;
}
} else {
switch ( V_235 & V_236 ) {
case V_237 :
return V_238 ;
case V_239 :
return V_238 ;
case V_233 :
return V_240 ;
case V_234 :
default:
return V_241 ;
}
}
}
static void
F_99 ( struct V_1 * V_1 , T_1 V_219 [ V_220 ] )
{
T_1 V_43 = 0 ;
T_1 V_242 = 0 ;
int V_224 ;
T_1 * V_223 = V_219 + ( V_243 - V_221 ) ;
T_1 V_244 ;
T_1 V_245 ;
for ( V_224 = 0 ; V_224 < V_1 -> V_11 ; V_224 ++ ) {
T_1 V_246 = F_95 ( V_223 , V_224 ) ;
T_1 V_247 = F_96 ( V_223 , V_224 ) ;
if ( V_246 > V_43 )
V_43 = V_246 ;
if ( V_247 > V_242 )
V_242 = V_247 ;
}
V_244 = F_97 ( V_1 ) ;
if ( V_43 >= V_244 )
V_43 = V_244 | V_248 ;
V_245 = F_98 ( V_1 , V_43 ) ;
if ( V_242 >= V_245 )
V_242 = V_245 | V_249 ;
for ( V_224 = 0 ; V_224 < 4 ; V_224 ++ )
V_1 -> V_250 [ V_224 ] = V_43 | V_242 ;
}
static T_2
F_100 ( T_1 V_250 )
{
T_2 V_251 = 0 ;
switch ( V_250 & V_236 ) {
case V_237 :
default:
V_251 |= V_159 ;
break;
case V_239 :
V_251 |= V_252 ;
break;
case V_233 :
V_251 |= V_253 ;
break;
case V_234 :
V_251 |= V_254 ;
break;
}
switch ( V_250 & V_255 ) {
case V_241 :
default:
V_251 |= V_160 ;
break;
case V_240 :
V_251 |= V_256 ;
break;
case V_238 :
V_251 |= V_257 ;
break;
case V_258 :
V_251 |= V_259 ;
break;
}
return V_251 ;
}
static T_2
F_101 ( T_1 V_250 )
{
int V_251 = V_250 & ( V_236 |
V_255 ) ;
switch ( V_251 ) {
case V_237 | V_241 :
case V_239 | V_241 :
return V_260 ;
case V_237 | V_240 :
return V_261 ;
case V_237 | V_238 :
case V_239 | V_238 :
return V_262 ;
case V_239 | V_240 :
case V_233 | V_240 :
return V_263 ;
case V_233 | V_241 :
case V_234 | V_241 :
return V_264 ;
default:
F_25 ( L_39
L_40 , V_251 ) ;
return V_260 ;
}
}
static T_2
F_102 ( T_1 V_250 )
{
int V_251 = V_250 & ( V_236 |
V_255 ) ;
switch ( V_251 ) {
case V_237 | V_241 :
return V_265 ;
case V_237 | V_240 :
return V_266 ;
case V_237 | V_238 :
return V_267 ;
case V_239 | V_241 :
return V_268 ;
case V_239 | V_240 :
return V_269 ;
case V_233 | V_241 :
return V_270 ;
case V_233 | V_240 :
return V_271 ;
default:
F_25 ( L_39
L_40 , V_251 ) ;
return V_272 ;
}
}
static T_1
F_103 ( T_1 V_219 [ V_220 ] ,
int V_224 )
{
int V_225 = ( V_224 & 1 ) * 4 ;
T_1 V_228 = V_219 [ V_224 >> 1 ] ;
return ( V_228 >> V_225 ) & 0xf ;
}
static bool
F_104 ( T_1 V_219 [ V_220 ] , int V_11 )
{
int V_224 ;
T_1 V_273 ;
for ( V_224 = 0 ; V_224 < V_11 ; V_224 ++ ) {
V_273 = F_103 ( V_219 , V_224 ) ;
if ( ( V_273 & V_274 ) == 0 )
return false ;
}
return true ;
}
static bool
F_105 ( struct V_1 * V_1 , T_1 V_219 [ V_220 ] )
{
T_1 V_275 ;
T_1 V_273 ;
int V_224 ;
V_275 = F_94 ( V_219 ,
V_276 ) ;
if ( ( V_275 & V_277 ) == 0 )
return false ;
for ( V_224 = 0 ; V_224 < V_1 -> V_11 ; V_224 ++ ) {
V_273 = F_103 ( V_219 , V_224 ) ;
if ( ( V_273 & V_278 ) != V_278 )
return false ;
}
return true ;
}
static bool
F_106 ( struct V_1 * V_1 ,
T_2 V_279 ,
T_1 V_280 )
{
struct V_46 * V_47 = V_1 -> V_2 . V_2 . V_47 ;
struct V_48 * V_49 = V_47 -> V_50 ;
int V_91 ;
F_31 ( V_1 -> V_70 , V_279 ) ;
F_71 ( V_1 -> V_70 ) ;
F_35 ( V_1 ,
V_281 ,
V_280 ) ;
V_91 = F_34 ( V_1 ,
V_282 ,
V_1 -> V_250 ,
V_1 -> V_11 ) ;
if ( V_91 != V_1 -> V_11 )
return false ;
return true ;
}
static void
F_88 ( struct V_1 * V_1 )
{
struct V_46 * V_47 = V_1 -> V_2 . V_2 . V_47 ;
struct V_48 * V_49 = V_47 -> V_50 ;
struct V_153 * V_153 = F_48 ( V_1 -> V_2 . V_2 . V_150 ) ;
int V_42 ;
T_1 V_283 ;
bool V_284 = false ;
int V_285 , V_286 ;
T_4 V_287 ;
T_2 V_157 = V_1 -> V_157 ;
if ( ! F_64 ( V_47 ) ) {
F_31 ( V_1 -> V_70 , V_1 -> V_157 ) ;
F_71 ( V_1 -> V_70 ) ;
F_107 ( V_47 , V_153 -> V_154 ) ;
}
F_34 ( V_1 , V_288 ,
V_1 -> V_166 ,
V_167 ) ;
V_157 |= V_218 ;
if ( F_64 ( V_47 ) && ( F_28 ( V_47 ) || ! F_3 ( V_1 ) ) )
V_157 &= ~ V_289 ;
else
V_157 &= ~ V_290 ;
memset ( V_1 -> V_250 , 0 , 4 ) ;
V_283 = 0xff ;
V_285 = 0 ;
V_286 = 0 ;
V_284 = false ;
for (; ; ) {
T_1 V_219 [ V_220 ] ;
T_2 V_251 ;
if ( F_28 ( V_47 ) && F_3 ( V_1 ) ) {
V_251 = F_102 ( V_1 -> V_250 [ 0 ] ) ;
V_157 = ( V_157 & ~ V_291 ) | V_251 ;
} else if ( F_27 ( V_47 ) && F_3 ( V_1 ) ) {
V_251 = F_101 ( V_1 -> V_250 [ 0 ] ) ;
V_157 = ( V_157 & ~ V_292 ) | V_251 ;
} else {
V_251 = F_100 ( V_1 -> V_250 [ 0 ] ) ;
F_25 ( L_41 , V_251 ) ;
V_157 = ( V_157 & ~ ( V_293 | V_294 ) ) | V_251 ;
}
if ( F_64 ( V_47 ) && ( F_28 ( V_47 ) || ! F_3 ( V_1 ) ) )
V_287 = V_157 | V_295 ;
else
V_287 = V_157 | V_296 ;
if ( ! F_106 ( V_1 , V_287 ,
V_297 |
V_298 ) )
break;
F_32 ( 100 ) ;
if ( ! F_93 ( V_1 , V_219 ) ) {
F_33 ( L_42 ) ;
break;
}
if ( F_104 ( V_219 , V_1 -> V_11 ) ) {
F_25 ( L_43 ) ;
V_284 = true ;
break;
}
for ( V_42 = 0 ; V_42 < V_1 -> V_11 ; V_42 ++ )
if ( ( V_1 -> V_250 [ V_42 ] & V_248 ) == 0 )
break;
if ( V_42 == V_1 -> V_11 ) {
++ V_286 ;
if ( V_286 == 5 ) {
F_25 ( L_44 ) ;
break;
}
memset ( V_1 -> V_250 , 0 , 4 ) ;
V_285 = 0 ;
continue;
}
if ( ( V_1 -> V_250 [ 0 ] & V_236 ) == V_283 ) {
++ V_285 ;
if ( V_285 == 5 ) {
F_25 ( L_45 ) ;
break;
}
} else
V_285 = 0 ;
V_283 = V_1 -> V_250 [ 0 ] & V_236 ;
F_99 ( V_1 , V_219 ) ;
}
V_1 -> V_157 = V_157 ;
}
static void
F_89 ( struct V_1 * V_1 )
{
struct V_46 * V_47 = V_1 -> V_2 . V_2 . V_47 ;
struct V_48 * V_49 = V_47 -> V_50 ;
bool V_299 = false ;
int V_300 , V_301 ;
T_4 V_287 ;
T_2 V_157 = V_1 -> V_157 ;
V_300 = 0 ;
V_301 = 0 ;
V_299 = false ;
for (; ; ) {
T_2 V_251 ;
T_1 V_219 [ V_220 ] ;
if ( V_301 > 5 ) {
F_33 ( L_46 ) ;
F_86 ( V_1 ) ;
break;
}
if ( F_28 ( V_47 ) && F_3 ( V_1 ) ) {
V_251 = F_102 ( V_1 -> V_250 [ 0 ] ) ;
V_157 = ( V_157 & ~ V_291 ) | V_251 ;
} else if ( F_27 ( V_47 ) && F_3 ( V_1 ) ) {
V_251 = F_101 ( V_1 -> V_250 [ 0 ] ) ;
V_157 = ( V_157 & ~ V_292 ) | V_251 ;
} else {
V_251 = F_100 ( V_1 -> V_250 [ 0 ] ) ;
V_157 = ( V_157 & ~ ( V_293 | V_294 ) ) | V_251 ;
}
if ( F_64 ( V_47 ) && ( F_28 ( V_47 ) || ! F_3 ( V_1 ) ) )
V_287 = V_157 | V_302 ;
else
V_287 = V_157 | V_303 ;
if ( ! F_106 ( V_1 , V_287 ,
V_304 |
V_298 ) )
break;
F_32 ( 400 ) ;
if ( ! F_93 ( V_1 , V_219 ) )
break;
if ( ! F_104 ( V_219 , V_1 -> V_11 ) ) {
F_88 ( V_1 ) ;
V_301 ++ ;
continue;
}
if ( F_105 ( V_1 , V_219 ) ) {
V_299 = true ;
break;
}
if ( V_300 > 5 ) {
F_86 ( V_1 ) ;
F_88 ( V_1 ) ;
V_300 = 0 ;
V_301 ++ ;
continue;
}
F_99 ( V_1 , V_219 ) ;
++ V_300 ;
}
if ( F_64 ( V_47 ) && ( F_28 ( V_47 ) || ! F_3 ( V_1 ) ) )
V_287 = V_157 | V_176 ;
else
V_287 = V_157 | V_182 ;
F_31 ( V_1 -> V_70 , V_287 ) ;
F_71 ( V_1 -> V_70 ) ;
F_35 ( V_1 ,
V_281 , V_305 ) ;
}
static void
F_86 ( struct V_1 * V_1 )
{
struct V_46 * V_47 = V_1 -> V_2 . V_2 . V_47 ;
struct V_48 * V_49 = V_47 -> V_50 ;
T_2 V_157 = V_1 -> V_157 ;
if ( ( F_20 ( V_1 -> V_70 ) & V_218 ) == 0 )
return;
F_25 ( L_37 ) ;
if ( F_1 ( V_1 ) ) {
V_157 &= ~ V_178 ;
F_31 ( V_1 -> V_70 , V_157 ) ;
F_71 ( V_1 -> V_70 ) ;
F_32 ( 100 ) ;
}
if ( F_64 ( V_47 ) && ( F_28 ( V_47 ) || ! F_3 ( V_1 ) ) ) {
V_157 &= ~ V_289 ;
F_31 ( V_1 -> V_70 , V_157 | V_306 ) ;
} else {
V_157 &= ~ V_290 ;
F_31 ( V_1 -> V_70 , V_157 | V_307 ) ;
}
F_71 ( V_1 -> V_70 ) ;
F_30 ( 17 ) ;
if ( F_1 ( V_1 ) ) {
if ( F_64 ( V_47 ) && ( F_28 ( V_47 ) || ! F_3 ( V_1 ) ) )
V_157 |= V_176 ;
else
V_157 |= V_182 ;
}
if ( ! F_64 ( V_47 ) &&
F_20 ( V_1 -> V_70 ) & V_183 ) {
struct V_149 * V_150 = V_1 -> V_2 . V_2 . V_150 ;
V_157 &= ~ V_183 ;
F_31 ( V_1 -> V_70 , V_157 ) ;
if ( V_150 == NULL ) {
F_71 ( V_1 -> V_70 ) ;
F_30 ( 50 ) ;
} else
F_107 ( V_47 , F_48 ( V_150 ) -> V_154 ) ;
}
V_157 &= ~ V_165 ;
F_31 ( V_1 -> V_70 , V_157 & ~ V_218 ) ;
F_71 ( V_1 -> V_70 ) ;
F_30 ( V_1 -> V_198 ) ;
}
static bool
F_108 ( struct V_1 * V_1 )
{
if ( F_92 ( V_1 , 0x000 , V_1 -> V_15 ,
sizeof( V_1 -> V_15 ) ) &&
( V_1 -> V_15 [ V_169 ] != 0 ) ) {
return true ;
}
return false ;
}
static void
F_109 ( struct V_1 * V_1 )
{
T_5 V_308 [ 3 ] ;
if ( ! ( V_1 -> V_15 [ V_309 ] & V_310 ) )
return;
F_39 ( V_1 ) ;
if ( F_92 ( V_1 , V_311 , V_308 , 3 ) )
F_25 ( L_47 ,
V_308 [ 0 ] , V_308 [ 1 ] , V_308 [ 2 ] ) ;
if ( F_92 ( V_1 , V_312 , V_308 , 3 ) )
F_25 ( L_48 ,
V_308 [ 0 ] , V_308 [ 1 ] , V_308 [ 2 ] ) ;
F_41 ( V_1 , false ) ;
}
static bool
F_110 ( struct V_1 * V_1 , T_5 * V_313 )
{
int V_91 ;
V_91 = F_92 ( V_1 ,
V_314 ,
V_313 , 1 ) ;
if ( ! V_91 )
return false ;
return true ;
}
static void
F_111 ( struct V_1 * V_1 )
{
F_35 ( V_1 , V_315 , V_316 ) ;
}
static void
F_112 ( struct V_1 * V_1 )
{
T_5 V_313 ;
T_5 V_219 [ V_220 ] ;
if ( V_1 -> V_216 != V_212 )
return;
if ( ! V_1 -> V_2 . V_2 . V_150 )
return;
if ( ! F_93 ( V_1 , V_219 ) ) {
F_86 ( V_1 ) ;
return;
}
if ( ! F_108 ( V_1 ) ) {
F_86 ( V_1 ) ;
return;
}
if ( V_1 -> V_15 [ V_169 ] >= 0x11 &&
F_110 ( V_1 , & V_313 ) ) {
F_35 ( V_1 ,
V_314 ,
V_313 ) ;
if ( V_313 & V_317 )
F_111 ( V_1 ) ;
if ( V_313 & ( V_318 | V_319 ) )
F_61 ( L_49 ) ;
}
if ( ! F_105 ( V_1 , V_219 ) ) {
F_25 ( L_50 ,
F_113 ( & V_1 -> V_2 . V_2 ) ) ;
F_88 ( V_1 ) ;
F_89 ( V_1 ) ;
}
}
static enum V_320
F_114 ( struct V_1 * V_1 )
{
if ( F_108 ( V_1 ) )
return V_321 ;
return V_322 ;
}
static enum V_320
F_115 ( struct V_1 * V_1 )
{
enum V_320 V_74 ;
if ( F_1 ( V_1 ) ) {
V_74 = F_116 ( V_1 -> V_2 . V_2 . V_47 ) ;
if ( V_74 == V_323 )
V_74 = V_321 ;
return V_74 ;
}
return F_114 ( V_1 ) ;
}
static enum V_320
F_117 ( struct V_1 * V_1 )
{
struct V_46 * V_47 = V_1 -> V_2 . V_2 . V_47 ;
struct V_48 * V_49 = V_47 -> V_50 ;
T_2 V_324 , V_325 ;
switch ( V_1 -> V_70 ) {
case V_326 :
V_325 = V_327 ;
break;
case V_328 :
V_325 = V_329 ;
break;
case V_330 :
V_325 = V_331 ;
break;
default:
return V_323 ;
}
V_324 = F_20 ( V_332 ) ;
if ( ( V_324 & V_325 ) == 0 )
return V_322 ;
return F_114 ( V_1 ) ;
}
static struct V_333 *
F_118 ( struct V_6 * V_7 , struct V_104 * V_105 )
{
struct V_1 * V_1 = F_6 ( V_7 ) ;
struct V_333 * V_333 ;
int V_334 ;
if ( F_1 ( V_1 ) ) {
if ( ! V_1 -> V_333 )
return NULL ;
V_334 = ( V_1 -> V_333 -> V_335 + 1 ) * V_336 ;
V_333 = F_119 ( V_334 , V_337 ) ;
if ( ! V_333 )
return NULL ;
memcpy ( V_333 , V_1 -> V_333 , V_334 ) ;
return V_333 ;
}
V_333 = F_120 ( V_7 , V_105 ) ;
return V_333 ;
}
static int
F_121 ( struct V_6 * V_7 , struct V_104 * V_105 )
{
struct V_1 * V_1 = F_6 ( V_7 ) ;
int V_91 ;
if ( F_1 ( V_1 ) ) {
F_122 ( V_7 ,
V_1 -> V_333 ) ;
V_91 = F_123 ( V_7 , V_1 -> V_333 ) ;
F_124 ( V_7 ,
V_1 -> V_333 ) ;
V_7 -> V_338 . V_339 = NULL ;
return V_1 -> V_340 ;
}
V_91 = F_125 ( V_7 , V_105 ) ;
return V_91 ;
}
static enum V_320
F_126 ( struct V_6 * V_7 , bool V_341 )
{
struct V_1 * V_1 = F_6 ( V_7 ) ;
struct V_46 * V_47 = V_1 -> V_2 . V_2 . V_47 ;
enum V_320 V_74 ;
struct V_333 * V_333 = NULL ;
V_1 -> V_164 = false ;
if ( F_29 ( V_47 ) )
V_74 = F_115 ( V_1 ) ;
else
V_74 = F_117 ( V_1 ) ;
F_25 ( L_51 ,
V_1 -> V_15 [ 0 ] , V_1 -> V_15 [ 1 ] , V_1 -> V_15 [ 2 ] ,
V_1 -> V_15 [ 3 ] , V_1 -> V_15 [ 4 ] , V_1 -> V_15 [ 5 ] ,
V_1 -> V_15 [ 6 ] , V_1 -> V_15 [ 7 ] ) ;
if ( V_74 != V_321 )
return V_74 ;
F_109 ( V_1 ) ;
if ( V_1 -> V_342 != V_343 ) {
V_1 -> V_164 = ( V_1 -> V_342 == V_344 ) ;
} else {
V_333 = F_118 ( V_7 , & V_1 -> V_105 ) ;
if ( V_333 ) {
V_1 -> V_164 = F_127 ( V_333 ) ;
V_7 -> V_338 . V_339 = NULL ;
F_128 ( V_333 ) ;
}
}
return V_321 ;
}
static int F_129 ( struct V_6 * V_7 )
{
struct V_1 * V_1 = F_6 ( V_7 ) ;
struct V_46 * V_47 = V_1 -> V_2 . V_2 . V_47 ;
struct V_48 * V_49 = V_47 -> V_50 ;
int V_91 ;
V_91 = F_121 ( V_7 , & V_1 -> V_105 ) ;
if ( V_91 ) {
if ( F_1 ( V_1 ) && ! V_1 -> V_30 ) {
struct V_23 * V_345 ;
F_49 (newmode, &connector->probed_modes,
head) {
if ( ( V_345 -> type & V_346 ) ) {
V_1 -> V_30 =
F_130 ( V_47 , V_345 ) ;
break;
}
}
}
return V_91 ;
}
if ( F_1 ( V_1 ) ) {
if ( V_1 -> V_30 == NULL && V_49 -> V_347 != NULL ) {
V_1 -> V_30 =
F_130 ( V_47 , V_49 -> V_347 ) ;
if ( V_1 -> V_30 ) {
V_1 -> V_30 -> type |=
V_346 ;
}
}
if ( V_1 -> V_30 ) {
struct V_23 * V_24 ;
V_24 = F_130 ( V_47 , V_1 -> V_30 ) ;
F_131 ( V_7 , V_24 ) ;
return 1 ;
}
}
return 0 ;
}
static bool
F_132 ( struct V_6 * V_7 )
{
struct V_1 * V_1 = F_6 ( V_7 ) ;
struct V_333 * V_333 ;
bool V_164 = false ;
V_333 = F_118 ( V_7 , & V_1 -> V_105 ) ;
if ( V_333 ) {
V_164 = F_127 ( V_333 ) ;
V_7 -> V_338 . V_339 = NULL ;
F_128 ( V_333 ) ;
}
return V_164 ;
}
static int
F_133 ( struct V_6 * V_7 ,
struct V_348 * V_349 ,
T_6 V_350 )
{
struct V_48 * V_49 = V_7 -> V_47 -> V_50 ;
struct V_1 * V_1 = F_6 ( V_7 ) ;
int V_91 ;
V_91 = F_134 ( V_7 , V_349 , V_350 ) ;
if ( V_91 )
return V_91 ;
if ( V_349 == V_49 -> V_351 ) {
int V_42 = V_350 ;
bool V_164 ;
if ( V_42 == V_1 -> V_342 )
return 0 ;
V_1 -> V_342 = V_42 ;
if ( V_42 == V_343 )
V_164 = F_132 ( V_7 ) ;
else
V_164 = ( V_42 == V_344 ) ;
if ( V_164 == V_1 -> V_164 )
return 0 ;
V_1 -> V_164 = V_164 ;
goto V_352;
}
if ( V_349 == V_49 -> V_353 ) {
if ( V_350 == ! ! V_1 -> V_181 )
return 0 ;
V_1 -> V_181 = V_350 ? V_354 : 0 ;
goto V_352;
}
return - V_355 ;
V_352:
if ( V_1 -> V_2 . V_2 . V_150 ) {
struct V_149 * V_150 = V_1 -> V_2 . V_2 . V_150 ;
F_135 ( V_150 , & V_150 -> V_24 ,
V_150 -> V_356 , V_150 -> V_357 ,
V_150 -> V_358 ) ;
}
return 0 ;
}
static void
F_136 ( struct V_6 * V_7 )
{
struct V_46 * V_47 = V_7 -> V_47 ;
if ( F_137 ( V_47 ) )
F_138 ( V_47 ) ;
F_139 ( V_7 ) ;
F_140 ( V_7 ) ;
F_128 ( V_7 ) ;
}
static void F_141 ( struct V_4 * V_5 )
{
struct V_1 * V_1 = F_4 ( V_5 ) ;
F_142 ( & V_1 -> V_105 ) ;
F_143 ( V_5 ) ;
if ( F_1 ( V_1 ) ) {
F_128 ( V_1 -> V_333 ) ;
F_144 ( & V_1 -> V_201 ) ;
F_72 ( V_1 ) ;
}
F_128 ( V_1 ) ;
}
static void
F_145 ( struct V_8 * V_8 )
{
struct V_1 * V_1 = F_5 ( V_8 , struct V_1 , V_2 ) ;
F_112 ( V_1 ) ;
}
int
F_146 ( struct V_149 * V_150 )
{
struct V_46 * V_47 = V_150 -> V_47 ;
struct V_151 * V_152 = & V_47 -> V_152 ;
struct V_4 * V_5 ;
F_49 (encoder, &mode_config->encoder_list, head) {
struct V_1 * V_1 ;
if ( V_5 -> V_150 != V_150 )
continue;
V_1 = F_4 ( V_5 ) ;
if ( V_1 -> V_2 . type == V_155 ||
V_1 -> V_2 . type == V_3 )
return V_1 -> V_70 ;
}
return - 1 ;
}
bool F_137 ( struct V_46 * V_47 )
{
struct V_48 * V_49 = V_47 -> V_50 ;
struct V_359 * V_360 ;
int V_42 ;
if ( ! V_49 -> V_361 )
return false ;
for ( V_42 = 0 ; V_42 < V_49 -> V_361 ; V_42 ++ ) {
V_360 = V_49 -> V_362 + V_42 ;
if ( V_360 -> V_363 == V_364 &&
V_360 -> V_365 == V_366 )
return true ;
}
return false ;
}
static void
F_147 ( struct V_1 * V_1 , struct V_6 * V_7 )
{
F_148 ( V_7 ) ;
F_149 ( V_7 ) ;
}
void
F_150 ( struct V_46 * V_47 , int V_70 )
{
struct V_48 * V_49 = V_47 -> V_50 ;
struct V_6 * V_7 ;
struct V_1 * V_1 ;
struct V_8 * V_8 ;
struct V_123 * V_123 ;
const char * V_124 = NULL ;
int type ;
V_1 = F_151 ( sizeof( struct V_1 ) , V_337 ) ;
if ( ! V_1 )
return;
V_1 -> V_70 = V_70 ;
V_1 -> V_216 = - 1 ;
V_123 = F_151 ( sizeof( struct V_123 ) , V_337 ) ;
if ( ! V_123 ) {
F_128 ( V_1 ) ;
return;
}
V_8 = & V_1 -> V_2 ;
if ( F_29 ( V_47 ) && V_70 == V_367 )
if ( F_137 ( V_47 ) )
V_1 -> F_2 = true ;
if ( V_70 == V_211 || F_2 ( V_1 ) ) {
type = V_368 ;
V_8 -> type = V_3 ;
} else {
type = V_369 ;
V_8 -> type = V_155 ;
}
V_7 = & V_123 -> V_2 ;
F_152 ( V_47 , V_7 , & V_370 , type ) ;
F_153 ( V_7 , & V_371 ) ;
V_7 -> V_372 = V_373 ;
if ( V_70 == V_326 || V_70 == V_374 )
V_8 -> V_375 = ( 1 << V_376 ) ;
else if ( V_70 == V_328 || V_70 == V_377 )
V_8 -> V_375 = ( 1 << V_378 ) ;
else if ( V_70 == V_330 || V_70 == V_367 )
V_8 -> V_375 = ( 1 << V_379 ) ;
if ( F_1 ( V_1 ) ) {
V_8 -> V_375 = ( 1 << V_380 ) ;
F_154 ( & V_1 -> V_201 ,
F_73 ) ;
}
V_8 -> V_381 = ( 1 << 0 ) | ( 1 << 1 ) | ( 1 << 2 ) ;
V_7 -> V_382 = true ;
V_7 -> V_383 = 0 ;
F_155 ( V_47 , & V_8 -> V_2 , & V_384 ,
V_385 ) ;
F_156 ( & V_8 -> V_2 , & V_386 ) ;
F_157 ( V_123 , V_8 ) ;
F_158 ( V_7 ) ;
switch ( V_70 ) {
case V_211 :
V_124 = L_52 ;
break;
case V_326 :
case V_374 :
V_49 -> V_387 |=
V_388 ;
V_124 = L_53 ;
break;
case V_328 :
case V_377 :
V_49 -> V_387 |=
V_389 ;
V_124 = L_54 ;
break;
case V_330 :
case V_367 :
V_49 -> V_387 |=
V_390 ;
V_124 = L_55 ;
break;
}
F_38 ( V_1 , V_123 , V_124 ) ;
if ( F_1 ( V_1 ) ) {
bool V_91 ;
struct V_391 V_392 , V_393 ;
T_4 V_394 , V_395 , V_396 ;
struct V_333 * V_333 ;
V_394 = F_20 ( V_397 ) ;
V_395 = F_20 ( V_398 ) ;
V_396 = F_20 ( V_399 ) ;
if ( ! V_394 || ! V_395 || ! V_396 ) {
F_159 ( L_56 ) ;
F_141 ( & V_1 -> V_2 . V_2 ) ;
F_136 ( & V_123 -> V_2 ) ;
return;
}
V_392 . V_400 = ( V_394 & V_401 ) >>
V_402 ;
V_392 . V_403 = ( V_394 & V_404 ) >>
V_405 ;
V_392 . V_406 = ( V_395 & V_407 ) >>
V_408 ;
V_392 . V_409 = ( V_395 & V_410 ) >>
V_411 ;
V_392 . V_412 = ( ( V_396 & V_413 ) >>
V_414 ) * 1000 ;
F_25 ( L_57 ,
V_392 . V_400 , V_392 . V_403 , V_392 . V_406 , V_392 . V_409 , V_392 . V_412 ) ;
V_393 = V_49 -> V_415 . V_416 ;
F_25 ( L_58 ,
V_393 . V_400 , V_393 . V_403 , V_393 . V_406 , V_393 . V_409 , V_393 . V_412 ) ;
#define F_160 ( T_7 ) ((max(cur.field, vbt.field) + 9) / 10)
V_1 -> V_197 = F_160 ( V_400 ) ;
V_1 -> V_208 = F_160 ( V_403 ) ;
V_1 -> V_209 = F_160 ( V_406 ) ;
V_1 -> V_198 = F_160 ( V_409 ) ;
V_1 -> V_204 = F_160 ( V_412 ) ;
F_25 ( L_59 ,
V_1 -> V_197 , V_1 -> V_198 ,
V_1 -> V_204 ) ;
F_25 ( L_60 ,
V_1 -> V_208 , V_1 -> V_209 ) ;
F_39 ( V_1 ) ;
V_91 = F_108 ( V_1 ) ;
F_41 ( V_1 , false ) ;
if ( V_91 ) {
if ( V_1 -> V_15 [ V_169 ] >= 0x11 )
V_49 -> V_417 =
V_1 -> V_15 [ V_418 ] &
V_419 ;
} else {
F_159 ( L_61 ) ;
F_141 ( & V_1 -> V_2 . V_2 ) ;
F_136 ( & V_123 -> V_2 ) ;
return;
}
F_39 ( V_1 ) ;
V_333 = F_120 ( V_7 , & V_1 -> V_105 ) ;
if ( V_333 ) {
F_122 ( V_7 ,
V_333 ) ;
V_1 -> V_340 =
F_123 ( V_7 , V_333 ) ;
F_124 ( V_7 , V_333 ) ;
V_1 -> V_333 = V_333 ;
}
F_41 ( V_1 , false ) ;
}
V_8 -> V_420 = F_145 ;
if ( F_1 ( V_1 ) ) {
V_49 -> V_421 = V_7 ;
F_161 ( V_47 ) ;
}
F_147 ( V_1 , V_7 ) ;
if ( F_162 ( V_47 ) && ! F_163 ( V_47 ) ) {
T_4 V_324 = F_20 ( V_422 ) ;
F_31 ( V_422 , ( V_324 & ~ 0xf ) | 0xd ) ;
}
}
