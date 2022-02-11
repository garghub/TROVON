static void F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
F_3 ( V_4 -> V_7 , V_8 , sizeof( V_4 -> V_7 ) ) ;
F_3 ( V_4 -> V_9 , V_10 ,
sizeof( V_4 -> V_9 ) ) ;
snprintf ( V_4 -> V_11 , sizeof( V_4 -> V_11 ) ,
L_1 ,
V_6 -> V_12 . V_13 , V_6 -> V_12 . V_14 ,
V_6 -> V_12 . V_15 , V_6 -> V_12 . V_16 ) ;
F_3 ( V_4 -> V_17 , F_4 ( V_6 -> V_18 ) ,
sizeof( V_4 -> V_17 ) ) ;
V_4 -> V_19 = V_20 ;
V_4 -> V_21 = V_22 ;
}
static void F_5 ( struct V_1 * V_2 ,
struct V_23 * V_24 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
V_24 -> V_25 = V_26 ;
V_24 -> V_27 = V_28 ;
V_24 -> V_29 = V_6 -> V_30 ;
V_24 -> V_31 = V_6 -> V_32 ;
}
static int F_6 ( struct V_5 * V_6 , T_1 V_30 , T_1 V_32 )
{
struct V_33 * V_34 = NULL , * V_35 = NULL ;
struct V_33 V_36 = {
. V_37 = V_6 -> V_38 ,
. V_39 = V_6 -> V_2 -> V_39 ,
. V_40 = V_30 ,
} ;
struct V_33 V_41 = {
. V_37 = V_6 -> V_42 ,
. V_40 = V_32 ,
} ;
if ( V_6 -> V_30 != V_30 )
V_34 = & V_36 ;
if ( V_6 -> V_32 != V_32 )
V_35 = & V_41 ;
return F_7 ( V_6 , & V_6 -> V_43 ,
V_34 , V_35 ) ;
}
static int F_8 ( struct V_1 * V_2 ,
struct V_23 * V_24 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
T_1 V_30 , V_32 ;
if ( V_24 -> V_44 || V_24 -> V_45 )
return - V_46 ;
V_30 = F_9 ( V_24 -> V_29 ) ;
V_32 = F_9 ( V_24 -> V_31 ) ;
if ( V_30 < V_47 || V_30 > V_26 ||
V_32 < V_48 || V_32 > V_28 )
return - V_46 ;
if ( V_6 -> V_30 == V_30 && V_6 -> V_32 == V_32 )
return 0 ;
F_10 ( V_6 , L_2 ,
V_6 -> V_30 , V_30 , V_6 -> V_32 , V_32 ) ;
return F_6 ( V_6 , V_30 , V_32 ) ;
}
static void F_11 ( struct V_1 * V_2 ,
T_1 V_49 , T_2 * V_50 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
T_2 * V_51 = V_50 ;
int V_52 ;
switch ( V_49 ) {
case V_53 :
for ( V_52 = 0 ; V_52 < V_54 ; V_52 ++ ) {
memcpy ( V_51 , V_55 [ V_52 ] . V_56 , V_57 ) ;
V_51 += V_57 ;
}
for ( V_52 = 0 ; V_52 < V_6 -> V_58 ; V_52 ++ ) {
sprintf ( V_51 , L_3 , V_52 ) ;
V_51 += V_57 ;
sprintf ( V_51 , L_4 , V_52 ) ;
V_51 += V_57 ;
sprintf ( V_51 , L_5 , V_52 ) ;
V_51 += V_57 ;
}
strncpy ( V_51 , L_6 , V_57 ) ;
V_51 += V_57 ;
strncpy ( V_51 , L_7 , V_57 ) ;
V_51 += V_57 ;
strncpy ( V_51 , L_8 , V_57 ) ;
V_51 += V_57 ;
strncpy ( V_51 , L_9 , V_57 ) ;
V_51 += V_57 ;
strncpy ( V_51 , L_10 , V_57 ) ;
V_51 += V_57 ;
strncpy ( V_51 , L_11 , V_57 ) ;
V_51 += V_57 ;
strncpy ( V_51 , L_12 , V_57 ) ;
V_51 += V_57 ;
for ( V_52 = 0 ; V_52 < V_6 -> V_42 ; V_52 ++ ) {
sprintf ( V_51 , L_13 , V_52 ) ;
V_51 += V_57 ;
sprintf ( V_51 , L_14 , V_52 ) ;
V_51 += V_57 ;
}
for ( V_52 = 0 ; V_52 < V_6 -> V_38 ; V_52 ++ ) {
sprintf ( V_51 , L_15 , V_52 ) ;
V_51 += V_57 ;
sprintf ( V_51 , L_16 , V_52 ) ;
V_51 += V_57 ;
}
break;
}
}
static void F_12 ( struct V_1 * V_2 ,
struct V_59 * V_60 , T_3 * V_50 )
{
T_3 V_61 [ V_62 ] = {} ;
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_63 * V_64 ;
struct V_63 V_65 = {} ;
T_3 V_66 [ V_62 ] ;
T_2 T_4 * V_67 ;
int V_52 , V_68 , V_69 ;
T_2 * V_51 ;
V_64 = F_13 ( V_2 , & V_65 ) ;
for ( V_52 = 0 ; V_52 < V_54 ; V_52 ++ ) {
switch ( V_55 [ V_52 ] . type ) {
case V_70 :
V_51 = ( char * ) V_64 + V_55 [ V_52 ] . V_71 ;
V_50 [ V_52 ] = V_55 [ V_52 ] . V_72 == sizeof( T_3 ) ?
* ( T_3 * ) V_51 : * ( T_1 * ) V_51 ;
break;
case V_73 :
V_67 = V_6 -> V_74 + V_55 [ V_52 ] . V_71 ;
V_50 [ V_52 ] = F_14 ( V_67 ) ;
break;
}
}
for ( V_68 = 0 ; V_68 < V_6 -> V_58 ; V_68 ++ ) {
unsigned int V_75 ;
do {
V_75 = F_15 ( & V_6 -> V_76 [ V_68 ] . V_77 ) ;
V_50 [ V_52 ++ ] = V_6 -> V_76 [ V_68 ] . V_78 ;
V_66 [ 0 ] = V_6 -> V_76 [ V_68 ] . V_79 ;
V_66 [ 1 ] = V_6 -> V_76 [ V_68 ] . V_80 ;
V_66 [ 2 ] = V_6 -> V_76 [ V_68 ] . V_81 ;
} while ( F_16 ( & V_6 -> V_76 [ V_68 ] . V_77 , V_75 ) );
do {
V_75 = F_15 ( & V_6 -> V_76 [ V_68 ] . V_82 ) ;
V_50 [ V_52 ++ ] = V_6 -> V_76 [ V_68 ] . V_83 ;
V_50 [ V_52 ++ ] = V_6 -> V_76 [ V_68 ] . V_84 ;
V_66 [ 3 ] = V_6 -> V_76 [ V_68 ] . V_85 ;
V_66 [ 4 ] = V_6 -> V_76 [ V_68 ] . V_86 ;
V_66 [ 5 ] = V_6 -> V_76 [ V_68 ] . V_87 ;
V_66 [ 6 ] = V_6 -> V_76 [ V_68 ] . V_88 ;
} while ( F_16 ( & V_6 -> V_76 [ V_68 ] . V_82 , V_75 ) );
for ( V_69 = 0 ; V_69 < V_62 ; V_69 ++ )
V_61 [ V_69 ] += V_66 [ V_69 ] ;
}
for ( V_68 = 0 ; V_68 < V_62 ; V_68 ++ )
V_50 [ V_52 ++ ] = V_61 [ V_68 ] ;
for ( V_68 = 0 ; V_68 < V_6 -> V_42 ; V_68 ++ ) {
V_67 = V_6 -> V_74 + F_17 ( V_68 ) ;
V_50 [ V_52 ++ ] = F_14 ( V_67 ) ;
V_67 = V_6 -> V_74 + F_17 ( V_68 ) + 8 ;
V_50 [ V_52 ++ ] = F_14 ( V_67 ) ;
}
for ( V_68 = 0 ; V_68 < V_6 -> V_38 ; V_68 ++ ) {
V_67 = V_6 -> V_74 + F_18 ( V_68 ) ;
V_50 [ V_52 ++ ] = F_14 ( V_67 ) ;
V_67 = V_6 -> V_74 + F_18 ( V_68 ) + 8 ;
V_50 [ V_52 ++ ] = F_14 ( V_67 ) ;
}
}
static int F_19 ( struct V_1 * V_2 , int V_89 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
switch ( V_89 ) {
case V_53 :
return V_20 ;
default:
return - V_90 ;
}
}
static T_1 F_20 ( T_1 V_91 )
{
static const T_1 V_92 [ V_93 + 1 ] = {
[ V_94 ] = V_95 ,
[ V_96 ] = V_97 ,
[ V_98 ] = V_99 ,
[ V_100 ] = V_101 ,
[ V_102 ] = V_103 ,
[ V_93 ] = V_104 ,
} ;
if ( V_91 >= F_21 ( V_92 ) )
return 0 ;
return V_92 [ V_91 ] ;
}
static int F_22 ( struct V_5 * V_6 ,
struct V_105 * V_106 )
{
T_1 V_107 ;
V_106 -> V_50 = 0 ;
if ( ! ( V_6 -> V_108 & V_109 ) )
return - V_90 ;
V_107 = F_20 ( V_106 -> V_91 ) ;
if ( ! V_107 )
return - V_46 ;
V_106 -> V_50 |= V_110 | V_111 ;
if ( V_6 -> V_112 & V_107 )
V_106 -> V_50 |= V_113 | V_114 ;
return 0 ;
}
static int F_23 ( struct V_1 * V_2 ,
struct V_105 * V_106 , T_1 * V_115 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
switch ( V_106 -> V_106 ) {
case V_116 :
V_106 -> V_50 = V_6 -> V_38 ;
return 0 ;
case V_117 :
return F_22 ( V_6 , V_106 ) ;
default:
return - V_90 ;
}
}
static int F_24 ( struct V_5 * V_6 ,
struct V_105 * V_118 )
{
T_1 V_119 = V_6 -> V_112 ;
T_1 V_107 ;
int V_120 ;
if ( ! ( V_6 -> V_108 & V_109 ) )
return - V_90 ;
if ( V_118 -> V_50 & ~ ( V_110 | V_111 |
V_113 | V_114 ) )
return - V_46 ;
if ( ! ( V_118 -> V_50 & V_110 ) ||
! ( V_118 -> V_50 & V_111 ) )
return - V_46 ;
V_107 = F_20 ( V_118 -> V_91 ) ;
if ( ! V_107 )
return - V_46 ;
switch ( V_118 -> V_50 & ( V_113 | V_114 ) ) {
case 0 :
V_119 &= ~ V_107 ;
break;
case ( V_113 | V_114 ) :
V_119 |= V_107 ;
break;
default:
return - V_46 ;
}
V_119 |= V_121 ;
V_119 |= V_122 ;
if ( V_119 == V_6 -> V_112 )
return 0 ;
F_25 ( V_119 , V_6 -> V_74 + V_123 ) ;
V_120 = F_26 ( V_6 , V_124 ) ;
if ( V_120 )
return V_120 ;
V_6 -> V_112 = V_119 ;
F_10 ( V_6 , L_17 , V_6 -> V_112 ) ;
return 0 ;
}
static int F_27 ( struct V_1 * V_2 ,
struct V_105 * V_106 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
switch ( V_106 -> V_106 ) {
case V_125 :
return F_24 ( V_6 , V_106 ) ;
default:
return - V_90 ;
}
}
static T_1 F_28 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
if ( ! ( V_6 -> V_108 & V_109 ) )
return 0 ;
return F_21 ( V_6 -> V_126 ) ;
}
static T_1 F_29 ( struct V_1 * V_2 )
{
return V_127 ;
}
static int F_30 ( struct V_1 * V_2 , T_1 * V_128 , T_2 * V_129 ,
T_2 * V_130 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
int V_52 ;
if ( ! ( V_6 -> V_108 & V_109 ) )
return - V_90 ;
if ( V_128 )
for ( V_52 = 0 ; V_52 < F_21 ( V_6 -> V_126 ) ; V_52 ++ )
V_128 [ V_52 ] = V_6 -> V_126 [ V_52 ] ;
if ( V_129 )
memcpy ( V_129 , V_6 -> V_131 , V_127 ) ;
if ( V_130 )
* V_130 = V_132 ;
return 0 ;
}
static int F_31 ( struct V_1 * V_2 ,
const T_1 * V_128 , const T_2 * V_129 ,
const T_2 V_130 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
int V_52 ;
if ( ! ( V_6 -> V_108 & V_109 ) ||
! ( V_130 == V_133 || V_130 == V_132 ) )
return - V_90 ;
if ( ! V_129 && ! V_128 )
return 0 ;
if ( V_129 ) {
memcpy ( V_6 -> V_131 , V_129 , V_127 ) ;
F_32 ( V_6 ) ;
}
if ( V_128 ) {
for ( V_52 = 0 ; V_52 < F_21 ( V_6 -> V_126 ) ; V_52 ++ )
V_6 -> V_126 [ V_52 ] = V_128 [ V_52 ] ;
F_33 ( V_6 ) ;
}
return F_26 ( V_6 , V_124 ) ;
}
static int F_34 ( struct V_1 * V_2 )
{
return V_22 ;
}
static void F_35 ( struct V_1 * V_2 ,
struct V_134 * V_135 , void * V_51 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
T_1 * V_136 = V_51 ;
int V_52 ;
V_135 -> V_9 = F_36 ( V_6 , V_137 ) ;
for ( V_52 = 0 ; V_52 < V_22 / sizeof( T_1 ) ; V_52 ++ )
V_136 [ V_52 ] = F_37 ( V_6 -> V_74 + ( V_52 * sizeof( T_1 ) ) ) ;
}
static int F_38 ( struct V_1 * V_2 ,
struct V_138 * V_139 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
if ( ! ( V_6 -> V_108 & V_140 ) )
return - V_46 ;
V_139 -> V_141 = V_6 -> V_141 ;
V_139 -> V_142 = V_6 -> V_143 ;
V_139 -> V_144 = V_6 -> V_144 ;
V_139 -> V_145 = V_6 -> V_146 ;
return 0 ;
}
static int F_39 ( struct V_1 * V_2 ,
struct V_138 * V_139 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
unsigned int V_147 ;
if ( V_139 -> V_148 ||
V_139 -> V_149 ||
V_139 -> V_150 ||
V_139 -> V_151 ||
V_139 -> V_152 ||
V_139 -> V_153 ||
V_139 -> V_154 ||
V_139 -> V_155 ||
V_139 -> V_156 ||
V_139 -> V_157 ||
V_139 -> V_158 ||
V_139 -> V_159 ||
V_139 -> V_160 ||
V_139 -> V_161 ||
V_139 -> V_162 ||
V_139 -> V_163 ||
V_139 -> V_164 ||
V_139 -> V_165 )
return - V_166 ;
V_147 = V_6 -> V_167 / 16 ;
if ( ! ( V_6 -> V_108 & V_140 ) )
return - V_46 ;
if ( ! V_139 -> V_141 && ! V_139 -> V_142 )
return - V_46 ;
if ( ! V_139 -> V_144 && ! V_139 -> V_145 )
return - V_46 ;
if ( V_139 -> V_141 * V_147 >= ( ( 1 << 16 ) - 1 ) )
return - V_46 ;
if ( V_139 -> V_144 * V_147 >= ( ( 1 << 16 ) - 1 ) )
return - V_46 ;
if ( V_139 -> V_142 >= ( ( 1 << 16 ) - 1 ) )
return - V_46 ;
if ( V_139 -> V_145 >= ( ( 1 << 16 ) - 1 ) )
return - V_46 ;
V_6 -> V_141 = V_139 -> V_141 ;
V_6 -> V_143 = V_139 -> V_142 ;
V_6 -> V_144 = V_139 -> V_144 ;
V_6 -> V_146 = V_139 -> V_145 ;
F_40 ( V_6 ) ;
return F_26 ( V_6 , V_168 ) ;
}
static void F_41 ( struct V_1 * V_2 ,
struct V_169 * V_170 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
unsigned int V_42 ;
V_42 = V_6 -> V_42 ;
if ( V_6 -> V_43 )
V_42 -= V_6 -> V_38 ;
V_170 -> V_171 = F_42 ( V_6 -> V_172 , V_6 -> V_173 ) ;
V_170 -> V_174 = F_42 ( V_6 -> V_175 , V_6 -> V_173 ) ;
V_170 -> V_176 = F_42 ( V_170 -> V_171 , V_170 -> V_174 ) ;
V_170 -> V_177 = V_178 ;
V_170 -> V_179 = F_42 ( V_6 -> V_38 , V_42 ) ;
V_170 -> V_180 = V_6 -> V_38 - V_170 -> V_179 ;
V_170 -> V_181 = V_42 - V_170 -> V_179 ;
V_170 -> V_182 = V_178 ;
}
static int F_43 ( struct V_5 * V_6 , unsigned int V_183 ,
unsigned int V_184 )
{
struct V_33 * V_34 = NULL , * V_35 = NULL ;
struct V_33 V_36 = {
. V_37 = V_183 ,
. V_39 = V_6 -> V_2 -> V_39 ,
. V_40 = V_6 -> V_30 ,
} ;
struct V_33 V_41 = {
. V_37 = V_184 ,
. V_40 = V_6 -> V_32 ,
} ;
if ( V_6 -> V_38 != V_183 )
V_34 = & V_36 ;
if ( V_6 -> V_185 != V_184 ||
( V_6 -> V_43 && V_34 ) )
V_35 = & V_41 ;
if ( V_6 -> V_43 )
V_41 . V_37 += V_183 ;
return F_7 ( V_6 , & V_6 -> V_43 ,
V_34 , V_35 ) ;
}
static int F_44 ( struct V_1 * V_2 ,
struct V_169 * V_170 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
unsigned int V_183 , V_184 ;
if ( ! V_170 -> V_179 ||
V_170 -> V_182 != V_178 ||
( V_170 -> V_180 && V_170 -> V_181 ) )
return - V_46 ;
V_183 = V_170 -> V_179 + V_170 -> V_180 ;
V_184 = V_170 -> V_179 + V_170 -> V_181 ;
if ( V_183 > F_42 ( V_6 -> V_172 , V_6 -> V_173 ) ||
V_184 > F_42 ( V_6 -> V_175 , V_6 -> V_173 ) )
return - V_46 ;
return F_43 ( V_6 , V_183 , V_184 ) ;
}
void F_45 ( struct V_1 * V_2 )
{
V_2 -> V_186 = & V_187 ;
}
