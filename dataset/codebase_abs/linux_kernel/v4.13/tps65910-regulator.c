static int F_1 ( int V_1 )
{
switch ( V_1 ) {
case V_2 :
return V_3 ;
case V_4 :
return V_5 ;
case V_6 :
return V_7 ;
case V_8 :
return V_9 ;
case V_10 :
return V_11 ;
case V_12 :
return V_13 ;
case V_14 :
return V_15 ;
case V_16 :
return V_17 ;
case V_18 :
return V_19 ;
case V_20 :
return V_21 ;
case V_22 :
return V_23 ;
case V_24 :
return V_25 ;
case V_26 :
return V_27 ;
case V_28 :
return V_29 ;
default:
return - V_30 ;
}
}
static int F_2 ( int V_1 )
{
switch ( V_1 ) {
case V_2 :
return V_3 ;
case V_4 :
return V_5 ;
case V_6 :
return V_7 ;
case V_8 :
return V_9 ;
case V_31 :
return V_32 ;
case V_33 :
return V_34 ;
case V_35 :
return V_36 ;
case V_37 :
return V_38 ;
case V_39 :
return V_40 ;
case V_41 :
return V_42 ;
case V_43 :
return V_44 ;
case V_45 :
return V_46 ;
case V_47 :
return V_48 ;
default:
return - V_30 ;
}
}
static int F_3 ( struct V_49 * V_50 , unsigned int V_51 )
{
struct V_52 * V_53 = F_4 ( V_50 ) ;
struct V_54 * V_55 = V_53 -> V_55 ;
int V_56 , V_57 , V_1 = F_5 ( V_50 ) ;
V_56 = V_53 -> V_58 ( V_1 ) ;
if ( V_56 < 0 )
return V_56 ;
switch ( V_51 ) {
case V_59 :
return F_6 ( V_53 -> V_55 , V_56 ,
V_60 | V_61 ,
V_61 ) ;
case V_62 :
V_57 = V_61 | V_60 ;
return F_7 ( V_55 , V_56 , V_57 ) ;
case V_63 :
return F_8 ( V_55 , V_56 , V_61 ) ;
}
return - V_30 ;
}
static unsigned int F_9 ( struct V_49 * V_50 )
{
struct V_52 * V_53 = F_4 ( V_50 ) ;
int V_64 , V_56 , V_57 , V_1 = F_5 ( V_50 ) ;
V_56 = V_53 -> V_58 ( V_1 ) ;
if ( V_56 < 0 )
return V_56 ;
V_64 = F_10 ( V_53 -> V_55 , V_56 , & V_57 ) ;
if ( V_64 < 0 )
return V_64 ;
if ( ! ( V_57 & V_61 ) )
return V_63 ;
else if ( V_57 & V_60 )
return V_62 ;
else
return V_59 ;
}
static int F_11 ( struct V_49 * V_50 )
{
struct V_52 * V_53 = F_4 ( V_50 ) ;
int V_64 , V_1 = F_5 ( V_50 ) ;
int V_65 = 0 , V_66 = 0 , V_67 = 0 , V_68 = 0 , V_69 = 0 ;
switch ( V_1 ) {
case V_6 :
V_64 = F_10 ( V_53 -> V_55 , V_70 , & V_65 ) ;
if ( V_64 < 0 )
return V_64 ;
V_64 = F_10 ( V_53 -> V_55 , V_7 , & V_68 ) ;
if ( V_64 < 0 )
return V_64 ;
V_68 = ( V_68 & V_71 ) >> V_72 ;
V_64 = F_10 ( V_53 -> V_55 , V_73 , & V_66 ) ;
if ( V_64 < 0 )
return V_64 ;
V_69 = V_65 & V_74 ;
V_65 &= V_75 ;
V_66 &= V_76 ;
V_67 = 75 ;
break;
case V_8 :
V_64 = F_10 ( V_53 -> V_55 , V_77 , & V_65 ) ;
if ( V_64 < 0 )
return V_64 ;
V_64 = F_10 ( V_53 -> V_55 , V_9 , & V_68 ) ;
if ( V_64 < 0 )
return V_64 ;
V_68 = ( V_68 & V_78 ) >> V_79 ;
V_64 = F_10 ( V_53 -> V_55 , V_80 , & V_66 ) ;
if ( V_64 < 0 )
return V_64 ;
V_69 = V_65 & V_81 ;
V_65 &= V_82 ;
V_66 &= V_83 ;
V_67 = 75 ;
break;
case V_31 :
V_64 = F_10 ( V_53 -> V_55 , V_84 ,
& V_65 ) ;
if ( V_64 < 0 )
return V_64 ;
V_64 = F_10 ( V_53 -> V_55 , V_85 ,
& V_66 ) ;
if ( V_64 < 0 )
return V_64 ;
V_69 = V_65 & V_86 ;
V_65 &= V_87 ;
V_66 &= V_88 ;
V_67 = 64 ;
break;
}
if ( ! V_68 )
V_68 = 1 ;
if ( V_69 ) {
if ( V_66 < 3 )
V_66 = 3 ;
if ( V_66 > V_67 )
V_66 = V_67 ;
return V_66 - 3 ;
} else {
if ( V_65 < 3 )
V_65 = 3 ;
if ( V_65 > V_67 )
V_65 = V_67 ;
return V_65 - 3 ;
}
return - V_30 ;
}
static int F_12 ( struct V_49 * V_50 )
{
struct V_52 * V_53 = F_4 ( V_50 ) ;
int V_64 , V_56 , V_57 , V_1 = F_5 ( V_50 ) ;
V_56 = V_53 -> V_58 ( V_1 ) ;
if ( V_56 < 0 )
return V_56 ;
V_64 = F_10 ( V_53 -> V_55 , V_56 , & V_57 ) ;
if ( V_64 < 0 )
return V_64 ;
switch ( V_1 ) {
case V_4 :
case V_12 :
case V_14 :
case V_16 :
case V_18 :
case V_20 :
case V_22 :
case V_24 :
case V_26 :
V_57 &= V_89 ;
V_57 >>= V_90 ;
break;
case V_28 :
V_57 &= V_91 ;
V_57 >>= V_92 ;
break;
default:
return - V_30 ;
}
return V_57 ;
}
static int F_13 ( struct V_49 * V_50 )
{
return V_50 -> V_93 -> V_94 [ 0 ] ;
}
static int F_14 ( struct V_49 * V_50 )
{
struct V_52 * V_53 = F_4 ( V_50 ) ;
int V_64 , V_1 = F_5 ( V_50 ) ;
unsigned int V_57 , V_56 ;
V_56 = V_53 -> V_58 ( V_1 ) ;
V_64 = F_10 ( V_53 -> V_55 , V_56 , & V_57 ) ;
if ( V_64 < 0 )
return V_64 ;
switch ( V_1 ) {
case V_33 :
case V_35 :
case V_39 :
V_57 &= V_95 ;
V_57 >>= V_90 ;
break;
case V_37 :
case V_41 :
case V_43 :
case V_45 :
case V_47 :
V_57 &= V_96 ;
V_57 >>= V_90 ;
break;
case V_4 :
V_57 &= V_89 ;
V_57 >>= V_90 ;
break;
default:
return - V_30 ;
}
return V_57 ;
}
static int F_15 ( struct V_49 * V_50 ,
unsigned V_97 )
{
struct V_52 * V_53 = F_4 ( V_50 ) ;
int V_1 = F_5 ( V_50 ) , V_98 ;
int V_99 = 0 ;
switch ( V_1 ) {
case V_6 :
V_99 = ( V_97 / V_100 ) + 1 ;
if ( V_99 == 1 )
V_99 -- ;
V_98 = ( V_97 % V_100 ) + 3 ;
F_6 ( V_53 -> V_55 , V_7 ,
V_71 ,
V_99 << V_72 ) ;
F_16 ( V_53 -> V_55 , V_70 , V_98 ) ;
break;
case V_8 :
V_99 = ( V_97 / V_100 ) + 1 ;
if ( V_99 == 1 )
V_99 -- ;
V_98 = ( V_97 % V_100 ) + 3 ;
F_6 ( V_53 -> V_55 , V_9 ,
V_71 ,
V_99 << V_79 ) ;
F_16 ( V_53 -> V_55 , V_77 , V_98 ) ;
break;
case V_31 :
V_98 = V_97 + 3 ;
F_16 ( V_53 -> V_55 , V_84 , V_98 ) ;
}
return 0 ;
}
static int F_17 ( struct V_49 * V_50 ,
unsigned V_97 )
{
struct V_52 * V_53 = F_4 ( V_50 ) ;
int V_56 , V_1 = F_5 ( V_50 ) ;
V_56 = V_53 -> V_58 ( V_1 ) ;
if ( V_56 < 0 )
return V_56 ;
switch ( V_1 ) {
case V_4 :
case V_12 :
case V_14 :
case V_16 :
case V_18 :
case V_20 :
case V_22 :
case V_24 :
case V_26 :
return F_6 ( V_53 -> V_55 , V_56 , V_89 ,
V_97 << V_90 ) ;
case V_28 :
return F_6 ( V_53 -> V_55 , V_56 , V_91 ,
V_97 << V_92 ) ;
}
return - V_30 ;
}
static int F_18 ( struct V_49 * V_50 ,
unsigned V_97 )
{
struct V_52 * V_53 = F_4 ( V_50 ) ;
int V_56 , V_1 = F_5 ( V_50 ) ;
V_56 = V_53 -> V_58 ( V_1 ) ;
if ( V_56 < 0 )
return V_56 ;
switch ( V_1 ) {
case V_33 :
case V_35 :
case V_39 :
return F_6 ( V_53 -> V_55 , V_56 , V_95 ,
V_97 << V_90 ) ;
case V_37 :
case V_41 :
case V_43 :
case V_45 :
case V_47 :
return F_6 ( V_53 -> V_55 , V_56 , V_96 ,
V_97 << V_90 ) ;
case V_4 :
return F_6 ( V_53 -> V_55 , V_56 , V_89 ,
V_97 << V_90 ) ;
case V_28 :
return F_6 ( V_53 -> V_55 , V_56 , V_91 ,
V_97 << V_92 ) ;
}
return - V_30 ;
}
static int F_19 ( struct V_49 * V_50 ,
unsigned V_97 )
{
int V_101 , V_68 = 1 , V_1 = F_5 ( V_50 ) ;
switch ( V_1 ) {
case V_6 :
case V_8 :
V_68 = ( V_97 / V_100 ) + 1 ;
V_101 = V_102 +
( V_97 % V_100 ) * V_103 ;
break;
case V_31 :
V_101 = V_104 + ( V_97 * V_105 ) ;
break;
default:
F_20 () ;
return - V_30 ;
}
return V_101 * 100 * V_68 ;
}
static int F_21 ( struct V_49 * V_50 , unsigned V_97 )
{
struct V_52 * V_53 = F_4 ( V_50 ) ;
int V_106 = 0 , V_1 = F_5 ( V_50 ) ;
switch ( V_1 ) {
case V_33 :
case V_35 :
case V_39 :
if ( V_97 < 5 )
V_97 = 0 ;
else
V_97 -= 4 ;
V_106 = 50 ;
break;
case V_37 :
case V_41 :
case V_43 :
case V_45 :
case V_47 :
if ( V_97 < 3 )
V_97 = 0 ;
else
V_97 -= 2 ;
V_106 = 100 ;
break;
case V_4 :
return V_53 -> V_107 [ V_1 ] -> V_108 [ V_97 ] ;
default:
return - V_30 ;
}
return ( V_109 + V_97 * V_106 ) * 1000 ;
}
static int F_22 ( struct V_52 * V_53 ,
int V_1 , int V_110 )
{
struct V_54 * V_55 = V_53 -> V_55 ;
T_1 V_111 = ( V_53 -> V_112 [ V_1 ] >> 8 ) & 0xFF ;
T_1 V_113 = ( 1 << V_53 -> V_112 [ V_1 ] & 0xFF ) ;
int V_64 ;
if ( V_110 & V_114 ) {
int V_115 ;
V_115 = ( ( V_110 &
V_116 ) != 0 ) ;
V_115 += ( ( V_110 &
V_117 ) != 0 ) ;
V_115 += ( ( V_110 &
V_118 ) != 0 ) ;
V_115 += ( ( V_110 &
V_119 ) != 0 ) ;
if ( V_115 > 1 ) {
F_23 ( V_55 -> V_50 ,
L_1 ) ;
return - V_30 ;
}
}
V_53 -> V_120 [ V_1 ] = V_110 ;
if ( V_110 & V_116 )
V_64 = F_7 ( V_55 ,
V_121 + V_111 , V_113 ) ;
else
V_64 = F_8 ( V_55 ,
V_121 + V_111 , V_113 ) ;
if ( V_64 < 0 ) {
F_23 ( V_55 -> V_50 ,
L_2 ) ;
return V_64 ;
}
if ( V_110 & V_117 )
V_64 = F_7 ( V_55 ,
V_122 + V_111 , V_113 ) ;
else
V_64 = F_8 ( V_55 ,
V_122 + V_111 , V_113 ) ;
if ( V_64 < 0 ) {
F_23 ( V_55 -> V_50 ,
L_3 ) ;
return V_64 ;
}
if ( ( F_24 ( V_55 ) == V_123 ) &&
( V_1 >= V_12 ) ) {
if ( V_110 & V_118 )
V_64 = F_7 ( V_55 ,
V_124 + V_111 , V_113 ) ;
else
V_64 = F_8 ( V_55 ,
V_124 + V_111 , V_113 ) ;
if ( V_64 < 0 ) {
F_23 ( V_55 -> V_50 ,
L_4 ) ;
return V_64 ;
}
}
if ( ! ( V_110 & V_114 ) ) {
V_64 = F_8 ( V_55 ,
V_125 + V_111 , V_113 ) ;
if ( ! V_64 )
V_64 = F_8 ( V_55 ,
V_126 + V_111 , V_113 ) ;
if ( V_64 < 0 )
F_23 ( V_55 -> V_50 ,
L_5 ) ;
return V_64 ;
}
if ( ( V_1 == V_6 ) ||
( V_1 == V_8 ) ||
( ( V_1 == V_31 ) &&
( F_24 ( V_55 ) == V_127 ) ) ) {
int V_128 = V_53 -> V_58 ( V_1 ) + 1 ;
int V_129 = V_53 -> V_58 ( V_1 ) + 2 ;
int V_65 , V_66 ;
V_64 = F_10 ( V_53 -> V_55 , V_128 , & V_65 ) ;
if ( V_64 < 0 )
return V_64 ;
V_64 = F_10 ( V_53 -> V_55 , V_129 , & V_66 ) ;
if ( V_64 < 0 )
return V_64 ;
if ( V_65 & V_74 ) {
T_1 V_130 = V_66 & V_75 ;
V_64 = F_16 ( V_53 -> V_55 , V_128 ,
V_130 ) ;
if ( V_64 < 0 ) {
F_23 ( V_55 -> V_50 ,
L_6 ) ;
return V_64 ;
}
}
V_64 = F_16 ( V_53 -> V_55 , V_129 , 0 ) ;
if ( V_64 < 0 ) {
F_23 ( V_55 -> V_50 , L_7 ) ;
return V_64 ;
}
}
V_64 = F_8 ( V_55 ,
V_125 + V_111 , V_113 ) ;
if ( ! V_64 ) {
if ( V_110 & V_119 )
V_64 = F_7 ( V_55 ,
V_126 + V_111 , V_113 ) ;
else
V_64 = F_8 ( V_55 ,
V_126 + V_111 , V_113 ) ;
}
if ( V_64 < 0 )
F_23 ( V_55 -> V_50 ,
L_5 ) ;
return V_64 ;
}
static struct V_131 * F_25 (
struct V_132 * V_133 ,
struct V_134 * * V_135 )
{
struct V_131 * V_136 ;
struct V_54 * V_54 = F_26 ( V_133 -> V_50 . V_137 ) ;
struct V_138 * V_139 , * V_140 ;
struct V_134 * V_141 ;
unsigned int V_142 ;
int V_143 = 0 , V_64 , V_144 ;
V_136 = F_27 ( & V_133 -> V_50 , sizeof( * V_136 ) ,
V_145 ) ;
if ( ! V_136 )
return NULL ;
V_139 = V_133 -> V_50 . V_137 -> V_146 ;
V_140 = F_28 ( V_139 , L_8 ) ;
if ( ! V_140 ) {
F_23 ( & V_133 -> V_50 , L_9 ) ;
return NULL ;
}
switch ( F_24 ( V_54 ) ) {
case V_123 :
V_144 = F_29 ( V_147 ) ;
V_141 = V_147 ;
break;
case V_127 :
V_144 = F_29 ( V_148 ) ;
V_141 = V_148 ;
break;
default:
F_30 ( V_140 ) ;
F_23 ( & V_133 -> V_50 , L_10 ) ;
return NULL ;
}
V_64 = V_134 ( & V_133 -> V_50 , V_140 , V_141 , V_144 ) ;
F_30 ( V_140 ) ;
if ( V_64 < 0 ) {
F_23 ( & V_133 -> V_50 , L_11 ,
V_64 ) ;
return NULL ;
}
* V_135 = V_141 ;
for ( V_143 = 0 ; V_143 < V_144 ; V_143 ++ ) {
if ( ! V_141 [ V_143 ] . V_146 )
continue;
V_136 -> V_149 [ V_143 ] =
V_141 [ V_143 ] . V_150 ;
V_64 = F_31 ( V_141 [ V_143 ] . V_146 ,
L_12 , & V_142 ) ;
if ( ! V_64 )
V_136 -> V_151 [ V_143 ] = V_142 ;
}
return V_136 ;
}
static inline struct V_131 * F_25 (
struct V_132 * V_133 ,
struct V_134 * * V_135 )
{
* V_135 = NULL ;
return NULL ;
}
static int F_32 ( struct V_132 * V_133 )
{
struct V_54 * V_54 = F_26 ( V_133 -> V_50 . V_137 ) ;
struct V_152 V_153 = { } ;
struct V_154 * V_107 ;
struct V_49 * V_155 ;
struct V_52 * V_53 ;
struct V_131 * V_136 ;
struct V_134 * V_135 = NULL ;
int V_156 , V_157 ;
V_136 = F_33 ( V_54 -> V_50 ) ;
if ( ! V_136 && V_54 -> V_50 -> V_146 )
V_136 = F_25 ( V_133 ,
& V_135 ) ;
if ( ! V_136 ) {
F_23 ( & V_133 -> V_50 , L_13 ) ;
return - V_30 ;
}
V_53 = F_27 ( & V_133 -> V_50 , sizeof( * V_53 ) , V_145 ) ;
if ( ! V_53 )
return - V_158 ;
V_53 -> V_55 = V_54 ;
F_34 ( V_133 , V_53 ) ;
F_7 ( V_53 -> V_55 , V_159 ,
V_160 ) ;
switch ( F_24 ( V_54 ) ) {
case V_123 :
F_35 ( V_161 < F_29 ( V_162 ) ) ;
V_53 -> V_58 = & F_1 ;
V_53 -> V_163 = F_29 ( V_162 ) ;
V_53 -> V_112 = V_164 ;
V_107 = V_162 ;
F_8 ( V_53 -> V_55 , V_165 ,
V_166 ) ;
break;
case V_127 :
F_35 ( V_161 < F_29 ( V_167 ) ) ;
V_53 -> V_58 = & F_2 ;
V_53 -> V_163 = F_29 ( V_167 ) ;
V_53 -> V_112 = V_168 ;
V_107 = V_167 ;
break;
default:
F_23 ( & V_133 -> V_50 , L_10 ) ;
return - V_169 ;
}
V_53 -> V_93 = F_27 ( & V_133 -> V_50 , V_53 -> V_163 *
sizeof( struct V_170 ) , V_145 ) ;
if ( ! V_53 -> V_93 )
return - V_158 ;
V_53 -> V_107 = F_27 ( & V_133 -> V_50 , V_53 -> V_163 *
sizeof( struct V_154 * ) , V_145 ) ;
if ( ! V_53 -> V_107 )
return - V_158 ;
V_53 -> V_155 = F_27 ( & V_133 -> V_50 , V_53 -> V_163 *
sizeof( struct V_49 * ) , V_145 ) ;
if ( ! V_53 -> V_155 )
return - V_158 ;
for ( V_156 = 0 ; V_156 < V_53 -> V_163 ; V_156 ++ , V_107 ++ ) {
V_53 -> V_107 [ V_156 ] = V_107 ;
V_53 -> V_93 [ V_156 ] . V_171 = V_107 -> V_171 ;
V_53 -> V_93 [ V_156 ] . V_172 = V_107 -> V_173 ;
V_53 -> V_93 [ V_156 ] . V_1 = V_156 ;
V_53 -> V_93 [ V_156 ] . V_174 = V_107 -> V_174 ;
V_53 -> V_93 [ V_156 ] . V_175 = V_107 -> V_176 ;
if ( V_156 == V_6 || V_156 == V_8 ) {
V_53 -> V_93 [ V_156 ] . V_177 = & V_178 ;
V_53 -> V_93 [ V_156 ] . V_174 = V_100 *
V_179 ;
V_53 -> V_93 [ V_156 ] . V_180 = 12500 ;
} else if ( V_156 == V_10 ) {
if ( F_24 ( V_54 ) == V_123 ) {
V_53 -> V_93 [ V_156 ] . V_177 = & V_181 ;
V_53 -> V_93 [ V_156 ] . V_94 = V_107 -> V_108 ;
} else {
V_53 -> V_93 [ V_156 ] . V_177 = & V_178 ;
V_53 -> V_93 [ V_156 ] . V_180 = 5000 ;
}
} else if ( V_156 == V_28 &&
F_24 ( V_54 ) == V_123 ) {
V_53 -> V_93 [ V_156 ] . V_177 = & V_182 ;
V_53 -> V_93 [ V_156 ] . V_94 = V_107 -> V_108 ;
} else {
if ( F_24 ( V_54 ) == V_123 ) {
V_53 -> V_93 [ V_156 ] . V_177 = & V_183 ;
V_53 -> V_93 [ V_156 ] . V_94 = V_107 -> V_108 ;
} else {
V_53 -> V_93 [ V_156 ] . V_177 = & V_184 ;
}
}
V_157 = F_22 ( V_53 , V_156 ,
V_136 -> V_151 [ V_156 ] ) ;
if ( V_157 < 0 )
F_36 ( V_54 -> V_50 ,
L_14 ) ;
V_53 -> V_93 [ V_156 ] . type = V_185 ;
V_53 -> V_93 [ V_156 ] . V_186 = V_187 ;
V_53 -> V_93 [ V_156 ] . V_188 = V_53 -> V_58 ( V_156 ) ;
V_53 -> V_93 [ V_156 ] . V_189 = V_190 ;
V_153 . V_50 = V_54 -> V_50 ;
V_153 . V_150 = V_136 -> V_149 [ V_156 ] ;
V_153 . V_191 = V_53 ;
V_153 . V_192 = V_54 -> V_192 ;
if ( V_135 )
V_153 . V_146 = V_135 [ V_156 ] . V_146 ;
V_155 = F_37 ( & V_133 -> V_50 , & V_53 -> V_93 [ V_156 ] ,
& V_153 ) ;
if ( F_38 ( V_155 ) ) {
F_23 ( V_54 -> V_50 ,
L_15 ,
V_133 -> V_171 ) ;
return F_39 ( V_155 ) ;
}
V_53 -> V_155 [ V_156 ] = V_155 ;
}
return 0 ;
}
static void F_40 ( struct V_132 * V_133 )
{
struct V_52 * V_53 = F_41 ( V_133 ) ;
int V_156 ;
for ( V_156 = 0 ; V_156 < V_53 -> V_163 ; V_156 ++ ) {
int V_157 ;
if ( ! V_53 -> V_155 [ V_156 ] )
continue;
V_157 = F_22 ( V_53 , V_156 , 0 ) ;
if ( V_157 < 0 )
F_23 ( & V_133 -> V_50 ,
L_16 ) ;
}
}
static int T_2 F_42 ( void )
{
return F_43 ( & V_193 ) ;
}
static void T_3 F_44 ( void )
{
F_45 ( & V_193 ) ;
}
