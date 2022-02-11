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
default:
return - V_28 ;
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
case V_29 :
return V_30 ;
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
default:
return - V_28 ;
}
}
static int F_3 ( struct V_47 * V_48 , unsigned int V_49 )
{
struct V_50 * V_51 = F_4 ( V_48 ) ;
struct V_52 * V_53 = V_51 -> V_53 ;
int V_54 , V_55 , V_1 = F_5 ( V_48 ) ;
V_54 = V_51 -> V_56 ( V_1 ) ;
if ( V_54 < 0 )
return V_54 ;
switch ( V_49 ) {
case V_57 :
return F_6 ( V_51 -> V_53 , V_54 ,
V_58 | V_59 ,
V_59 ) ;
case V_60 :
V_55 = V_59 | V_58 ;
return F_7 ( V_53 , V_54 , V_55 ) ;
case V_61 :
return F_8 ( V_53 , V_54 , V_59 ) ;
}
return - V_28 ;
}
static unsigned int F_9 ( struct V_47 * V_48 )
{
struct V_50 * V_51 = F_4 ( V_48 ) ;
int V_62 , V_54 , V_55 , V_1 = F_5 ( V_48 ) ;
V_54 = V_51 -> V_56 ( V_1 ) ;
if ( V_54 < 0 )
return V_54 ;
V_62 = F_10 ( V_51 -> V_53 , V_54 , & V_55 ) ;
if ( V_62 < 0 )
return V_62 ;
if ( ! ( V_55 & V_59 ) )
return V_61 ;
else if ( V_55 & V_58 )
return V_60 ;
else
return V_57 ;
}
static int F_11 ( struct V_47 * V_48 )
{
struct V_50 * V_51 = F_4 ( V_48 ) ;
int V_62 , V_1 = F_5 ( V_48 ) ;
int V_63 = 0 , V_64 = 0 , V_65 = 0 , V_66 = 0 , V_67 = 0 ;
switch ( V_1 ) {
case V_6 :
V_62 = F_10 ( V_51 -> V_53 , V_68 , & V_63 ) ;
if ( V_62 < 0 )
return V_62 ;
V_62 = F_10 ( V_51 -> V_53 , V_7 , & V_66 ) ;
if ( V_62 < 0 )
return V_62 ;
V_66 = ( V_66 & V_69 ) >> V_70 ;
V_62 = F_10 ( V_51 -> V_53 , V_71 , & V_64 ) ;
if ( V_62 < 0 )
return V_62 ;
V_67 = V_63 & V_72 ;
V_63 &= V_73 ;
V_64 &= V_74 ;
V_65 = 75 ;
break;
case V_8 :
V_62 = F_10 ( V_51 -> V_53 , V_75 , & V_63 ) ;
if ( V_62 < 0 )
return V_62 ;
V_62 = F_10 ( V_51 -> V_53 , V_9 , & V_66 ) ;
if ( V_62 < 0 )
return V_62 ;
V_66 = ( V_66 & V_76 ) >> V_77 ;
V_62 = F_10 ( V_51 -> V_53 , V_78 , & V_64 ) ;
if ( V_62 < 0 )
return V_62 ;
V_67 = V_63 & V_79 ;
V_63 &= V_80 ;
V_64 &= V_81 ;
V_65 = 75 ;
break;
case V_29 :
V_62 = F_10 ( V_51 -> V_53 , V_82 ,
& V_63 ) ;
if ( V_62 < 0 )
return V_62 ;
V_62 = F_10 ( V_51 -> V_53 , V_83 ,
& V_64 ) ;
if ( V_62 < 0 )
return V_62 ;
V_67 = V_63 & V_84 ;
V_63 &= V_85 ;
V_64 &= V_86 ;
V_65 = 64 ;
break;
}
if ( ! V_66 )
V_66 = 1 ;
if ( V_67 ) {
if ( V_64 < 3 )
V_64 = 3 ;
if ( V_64 > V_65 )
V_64 = V_65 ;
return V_64 - 3 ;
} else {
if ( V_63 < 3 )
V_63 = 3 ;
if ( V_63 > V_65 )
V_63 = V_65 ;
return V_63 - 3 ;
}
return - V_28 ;
}
static int F_12 ( struct V_47 * V_48 )
{
struct V_50 * V_51 = F_4 ( V_48 ) ;
int V_62 , V_54 , V_55 , V_1 = F_5 ( V_48 ) ;
V_54 = V_51 -> V_56 ( V_1 ) ;
if ( V_54 < 0 )
return V_54 ;
V_62 = F_10 ( V_51 -> V_53 , V_54 , & V_55 ) ;
if ( V_62 < 0 )
return V_62 ;
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
V_55 &= V_87 ;
V_55 >>= V_88 ;
break;
default:
return - V_28 ;
}
return V_55 ;
}
static int F_13 ( struct V_47 * V_48 )
{
return V_48 -> V_89 -> V_90 [ 0 ] ;
}
static int F_14 ( struct V_47 * V_48 )
{
struct V_50 * V_51 = F_4 ( V_48 ) ;
int V_62 , V_1 = F_5 ( V_48 ) ;
unsigned int V_55 , V_54 ;
V_54 = V_51 -> V_56 ( V_1 ) ;
V_62 = F_10 ( V_51 -> V_53 , V_54 , & V_55 ) ;
if ( V_62 < 0 )
return V_62 ;
switch ( V_1 ) {
case V_31 :
case V_33 :
case V_37 :
V_55 &= V_91 ;
V_55 >>= V_88 ;
break;
case V_35 :
case V_39 :
case V_41 :
case V_43 :
case V_45 :
V_55 &= V_92 ;
V_55 >>= V_88 ;
break;
case V_4 :
V_55 &= V_87 ;
V_55 >>= V_88 ;
break;
default:
return - V_28 ;
}
return V_55 ;
}
static int F_15 ( struct V_47 * V_48 ,
unsigned V_93 )
{
struct V_50 * V_51 = F_4 ( V_48 ) ;
int V_1 = F_5 ( V_48 ) , V_94 ;
int V_95 = 0 ;
switch ( V_1 ) {
case V_6 :
V_95 = ( V_93 / V_96 ) + 1 ;
if ( V_95 == 1 )
V_95 -- ;
V_94 = ( V_93 % V_96 ) + 3 ;
F_6 ( V_51 -> V_53 , V_7 ,
V_69 ,
V_95 << V_70 ) ;
F_16 ( V_51 -> V_53 , V_68 , V_94 ) ;
break;
case V_8 :
V_95 = ( V_93 / V_96 ) + 1 ;
if ( V_95 == 1 )
V_95 -- ;
V_94 = ( V_93 % V_96 ) + 3 ;
F_6 ( V_51 -> V_53 , V_9 ,
V_69 ,
V_95 << V_77 ) ;
F_16 ( V_51 -> V_53 , V_75 , V_94 ) ;
break;
case V_29 :
V_94 = V_93 + 3 ;
F_16 ( V_51 -> V_53 , V_82 , V_94 ) ;
}
return 0 ;
}
static int F_17 ( struct V_47 * V_48 ,
unsigned V_93 )
{
struct V_50 * V_51 = F_4 ( V_48 ) ;
int V_54 , V_1 = F_5 ( V_48 ) ;
V_54 = V_51 -> V_56 ( V_1 ) ;
if ( V_54 < 0 )
return V_54 ;
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
return F_6 ( V_51 -> V_53 , V_54 , V_87 ,
V_93 << V_88 ) ;
}
return - V_28 ;
}
static int F_18 ( struct V_47 * V_48 ,
unsigned V_93 )
{
struct V_50 * V_51 = F_4 ( V_48 ) ;
int V_54 , V_1 = F_5 ( V_48 ) ;
V_54 = V_51 -> V_56 ( V_1 ) ;
if ( V_54 < 0 )
return V_54 ;
switch ( V_1 ) {
case V_31 :
case V_33 :
case V_37 :
return F_6 ( V_51 -> V_53 , V_54 , V_91 ,
V_93 << V_88 ) ;
case V_35 :
case V_39 :
case V_41 :
case V_43 :
case V_45 :
return F_6 ( V_51 -> V_53 , V_54 , V_92 ,
V_93 << V_88 ) ;
case V_4 :
return F_6 ( V_51 -> V_53 , V_54 , V_87 ,
V_93 << V_88 ) ;
}
return - V_28 ;
}
static int F_19 ( struct V_47 * V_48 ,
unsigned V_93 )
{
int V_97 , V_66 = 1 , V_1 = F_5 ( V_48 ) ;
switch ( V_1 ) {
case V_6 :
case V_8 :
V_66 = ( V_93 / V_96 ) + 1 ;
V_97 = V_98 +
( V_93 % V_96 ) * V_99 ;
break;
case V_29 :
V_97 = V_100 + ( V_93 * V_101 ) ;
break;
default:
F_20 () ;
return - V_28 ;
}
return V_97 * 100 * V_66 ;
}
static int F_21 ( struct V_47 * V_48 , unsigned V_93 )
{
struct V_50 * V_51 = F_4 ( V_48 ) ;
int V_102 = 0 , V_1 = F_5 ( V_48 ) ;
switch( V_1 ) {
case V_31 :
case V_33 :
case V_37 :
if ( V_93 < 5 )
V_93 = 0 ;
else
V_93 -= 4 ;
V_102 = 50 ;
break;
case V_35 :
case V_39 :
case V_41 :
case V_43 :
case V_45 :
if ( V_93 < 3 )
V_93 = 0 ;
else
V_93 -= 2 ;
V_102 = 100 ;
break;
case V_4 :
return V_51 -> V_103 [ V_1 ] -> V_104 [ V_93 ] ;
default:
return - V_28 ;
}
return ( V_105 + V_93 * V_102 ) * 1000 ;
}
static int F_22 ( struct V_50 * V_51 ,
int V_1 , int V_106 )
{
struct V_52 * V_53 = V_51 -> V_53 ;
T_1 V_107 = ( V_51 -> V_108 [ V_1 ] >> 8 ) & 0xFF ;
T_1 V_109 = ( 1 << V_51 -> V_108 [ V_1 ] & 0xFF ) ;
int V_62 ;
if ( V_106 & V_110 ) {
int V_111 ;
V_111 = ( ( V_106 &
V_112 ) != 0 ) ;
V_111 += ( ( V_106 &
V_113 ) != 0 ) ;
V_111 += ( ( V_106 &
V_114 ) != 0 ) ;
V_111 += ( ( V_106 &
V_115 ) != 0 ) ;
if ( V_111 > 1 ) {
F_23 ( V_53 -> V_48 ,
L_1 ) ;
return - V_28 ;
}
}
V_51 -> V_116 [ V_1 ] = V_106 ;
if ( V_106 & V_112 )
V_62 = F_7 ( V_53 ,
V_117 + V_107 , V_109 ) ;
else
V_62 = F_8 ( V_53 ,
V_117 + V_107 , V_109 ) ;
if ( V_62 < 0 ) {
F_23 ( V_53 -> V_48 ,
L_2 ) ;
return V_62 ;
}
if ( V_106 & V_113 )
V_62 = F_7 ( V_53 ,
V_118 + V_107 , V_109 ) ;
else
V_62 = F_8 ( V_53 ,
V_118 + V_107 , V_109 ) ;
if ( V_62 < 0 ) {
F_23 ( V_53 -> V_48 ,
L_3 ) ;
return V_62 ;
}
if ( ( F_24 ( V_53 ) == V_119 ) &&
( V_1 >= V_12 ) ) {
if ( V_106 & V_114 )
V_62 = F_7 ( V_53 ,
V_120 + V_107 , V_109 ) ;
else
V_62 = F_8 ( V_53 ,
V_120 + V_107 , V_109 ) ;
if ( V_62 < 0 ) {
F_23 ( V_53 -> V_48 ,
L_4 ) ;
return V_62 ;
}
}
if ( ! ( V_106 & V_110 ) ) {
V_62 = F_8 ( V_53 ,
V_121 + V_107 , V_109 ) ;
if ( ! V_62 )
V_62 = F_8 ( V_53 ,
V_122 + V_107 , V_109 ) ;
if ( V_62 < 0 )
F_23 ( V_53 -> V_48 ,
L_5 ) ;
return V_62 ;
}
if ( ( V_1 == V_6 ) ||
( V_1 == V_8 ) ||
( ( V_1 == V_29 ) &&
( F_24 ( V_53 ) == V_123 ) ) ) {
int V_124 = V_51 -> V_56 ( V_1 ) + 1 ;
int V_125 = V_51 -> V_56 ( V_1 ) + 2 ;
int V_63 , V_64 ;
V_62 = F_10 ( V_51 -> V_53 , V_124 , & V_63 ) ;
if ( V_62 < 0 )
return V_62 ;
V_62 = F_10 ( V_51 -> V_53 , V_125 , & V_64 ) ;
if ( V_62 < 0 )
return V_62 ;
if ( V_63 & V_72 ) {
T_1 V_126 = V_64 & V_73 ;
V_62 = F_16 ( V_51 -> V_53 , V_124 ,
V_126 ) ;
if ( V_62 < 0 ) {
F_23 ( V_53 -> V_48 ,
L_6 ) ;
return V_62 ;
}
}
V_62 = F_16 ( V_51 -> V_53 , V_125 , 0 ) ;
if ( V_62 < 0 ) {
F_23 ( V_53 -> V_48 , L_7 ) ;
return V_62 ;
}
}
V_62 = F_8 ( V_53 ,
V_121 + V_107 , V_109 ) ;
if ( ! V_62 ) {
if ( V_106 & V_115 )
V_62 = F_7 ( V_53 ,
V_122 + V_107 , V_109 ) ;
else
V_62 = F_8 ( V_53 ,
V_122 + V_107 , V_109 ) ;
}
if ( V_62 < 0 )
F_23 ( V_53 -> V_48 ,
L_5 ) ;
return V_62 ;
}
static struct V_127 * F_25 (
struct V_128 * V_129 ,
struct V_130 * * V_131 )
{
struct V_127 * V_132 ;
struct V_52 * V_52 = F_26 ( V_129 -> V_48 . V_133 ) ;
struct V_134 * V_135 , * V_136 ;
struct V_130 * V_137 ;
unsigned int V_138 ;
int V_139 = 0 , V_62 , V_140 ;
V_132 = F_27 ( & V_129 -> V_48 , sizeof( * V_132 ) ,
V_141 ) ;
if ( ! V_132 ) {
F_23 ( & V_129 -> V_48 , L_8 ) ;
return NULL ;
}
V_135 = F_28 ( V_129 -> V_48 . V_133 -> V_142 ) ;
V_136 = F_29 ( V_135 , L_9 ) ;
if ( ! V_136 ) {
F_23 ( & V_129 -> V_48 , L_10 ) ;
return NULL ;
}
switch ( F_24 ( V_52 ) ) {
case V_119 :
V_140 = F_30 ( V_143 ) ;
V_137 = V_143 ;
break;
case V_123 :
V_140 = F_30 ( V_144 ) ;
V_137 = V_144 ;
break;
default:
F_31 ( V_136 ) ;
F_23 ( & V_129 -> V_48 , L_11 ) ;
return NULL ;
}
V_62 = V_130 ( & V_129 -> V_48 , V_136 , V_137 , V_140 ) ;
F_31 ( V_136 ) ;
if ( V_62 < 0 ) {
F_23 ( & V_129 -> V_48 , L_12 ,
V_62 ) ;
return NULL ;
}
* V_131 = V_137 ;
for ( V_139 = 0 ; V_139 < V_140 ; V_139 ++ ) {
if ( ! V_137 [ V_139 ] . V_145 || ! V_137 [ V_139 ] . V_142 )
continue;
V_132 -> V_146 [ V_139 ] =
V_137 [ V_139 ] . V_145 ;
V_62 = F_32 ( V_137 [ V_139 ] . V_142 ,
L_13 , & V_138 ) ;
if ( ! V_62 )
V_132 -> V_147 [ V_139 ] = V_138 ;
}
return V_132 ;
}
static inline struct V_127 * F_25 (
struct V_128 * V_129 ,
struct V_130 * * V_131 )
{
* V_131 = NULL ;
return NULL ;
}
static int F_33 ( struct V_128 * V_129 )
{
struct V_52 * V_52 = F_26 ( V_129 -> V_48 . V_133 ) ;
struct V_148 V_149 = { } ;
struct V_150 * V_103 ;
struct V_151 * V_152 ;
struct V_47 * V_153 ;
struct V_50 * V_51 ;
struct V_127 * V_132 ;
struct V_130 * V_131 = NULL ;
int V_154 , V_155 ;
V_132 = F_34 ( V_52 -> V_48 ) ;
if ( ! V_132 && V_52 -> V_48 -> V_142 )
V_132 = F_25 ( V_129 ,
& V_131 ) ;
if ( ! V_132 ) {
F_23 ( & V_129 -> V_48 , L_14 ) ;
return - V_28 ;
}
V_51 = F_27 ( & V_129 -> V_48 , sizeof( * V_51 ) , V_141 ) ;
if ( ! V_51 ) {
F_23 ( & V_129 -> V_48 , L_15 ) ;
return - V_156 ;
}
V_51 -> V_53 = V_52 ;
F_35 ( V_129 , V_51 ) ;
F_7 ( V_51 -> V_53 , V_157 ,
V_158 ) ;
switch( F_24 ( V_52 ) ) {
case V_119 :
V_51 -> V_56 = & F_1 ;
V_51 -> V_159 = F_30 ( V_160 ) ;
V_51 -> V_108 = V_161 ;
V_103 = V_160 ;
break;
case V_123 :
V_51 -> V_56 = & F_2 ;
V_51 -> V_159 = F_30 ( V_162 ) ;
V_51 -> V_108 = V_163 ;
V_103 = V_162 ;
break;
default:
F_23 ( & V_129 -> V_48 , L_11 ) ;
return - V_164 ;
}
V_51 -> V_89 = F_27 ( & V_129 -> V_48 , V_51 -> V_159 *
sizeof( struct V_165 ) , V_141 ) ;
if ( ! V_51 -> V_89 ) {
F_23 ( & V_129 -> V_48 , L_16 ) ;
return - V_156 ;
}
V_51 -> V_103 = F_27 ( & V_129 -> V_48 , V_51 -> V_159 *
sizeof( struct V_150 * ) , V_141 ) ;
if ( ! V_51 -> V_103 ) {
F_23 ( & V_129 -> V_48 , L_17 ) ;
return - V_156 ;
}
V_51 -> V_153 = F_27 ( & V_129 -> V_48 , V_51 -> V_159 *
sizeof( struct V_47 * ) , V_141 ) ;
if ( ! V_51 -> V_153 ) {
F_23 ( & V_129 -> V_48 , L_18 ) ;
return - V_156 ;
}
for ( V_154 = 0 ; V_154 < V_51 -> V_159 && V_154 < V_166 ;
V_154 ++ , V_103 ++ ) {
V_152 = V_132 -> V_146 [ V_154 ] ;
if ( ! V_152 )
continue;
V_51 -> V_103 [ V_154 ] = V_103 ;
V_51 -> V_89 [ V_154 ] . V_167 = V_103 -> V_167 ;
V_51 -> V_89 [ V_154 ] . V_168 = V_103 -> V_169 ;
V_51 -> V_89 [ V_154 ] . V_1 = V_154 ;
V_51 -> V_89 [ V_154 ] . V_170 = V_103 -> V_170 ;
V_51 -> V_89 [ V_154 ] . V_171 = V_103 -> V_172 ;
if ( V_154 == V_6 || V_154 == V_8 ) {
V_51 -> V_89 [ V_154 ] . V_173 = & V_174 ;
V_51 -> V_89 [ V_154 ] . V_170 = V_96 *
V_175 ;
V_51 -> V_89 [ V_154 ] . V_176 = 12500 ;
} else if ( V_154 == V_10 ) {
if ( F_24 ( V_52 ) == V_119 ) {
V_51 -> V_89 [ V_154 ] . V_173 = & V_177 ;
V_51 -> V_89 [ V_154 ] . V_90 = V_103 -> V_104 ;
} else {
V_51 -> V_89 [ V_154 ] . V_173 = & V_174 ;
V_51 -> V_89 [ V_154 ] . V_176 = 5000 ;
}
} else {
if ( F_24 ( V_52 ) == V_119 ) {
V_51 -> V_89 [ V_154 ] . V_173 = & V_178 ;
V_51 -> V_89 [ V_154 ] . V_90 = V_103 -> V_104 ;
} else {
V_51 -> V_89 [ V_154 ] . V_173 = & V_179 ;
}
}
V_155 = F_22 ( V_51 , V_154 ,
V_132 -> V_147 [ V_154 ] ) ;
if ( V_155 < 0 )
F_36 ( V_52 -> V_48 ,
L_19 ) ;
V_51 -> V_89 [ V_154 ] . type = V_180 ;
V_51 -> V_89 [ V_154 ] . V_181 = V_182 ;
V_51 -> V_89 [ V_154 ] . V_183 = V_51 -> V_56 ( V_154 ) ;
V_51 -> V_89 [ V_154 ] . V_184 = V_185 ;
V_149 . V_48 = V_52 -> V_48 ;
V_149 . V_145 = V_152 ;
V_149 . V_186 = V_51 ;
V_149 . V_187 = V_52 -> V_187 ;
if ( V_131 )
V_149 . V_142 = V_131 [ V_154 ] . V_142 ;
V_153 = F_37 ( & V_51 -> V_89 [ V_154 ] , & V_149 ) ;
if ( F_38 ( V_153 ) ) {
F_23 ( V_52 -> V_48 ,
L_20 ,
V_129 -> V_167 ) ;
V_155 = F_39 ( V_153 ) ;
goto V_188;
}
V_51 -> V_153 [ V_154 ] = V_153 ;
}
return 0 ;
V_188:
while ( -- V_154 >= 0 )
F_40 ( V_51 -> V_153 [ V_154 ] ) ;
return V_155 ;
}
static int F_41 ( struct V_128 * V_129 )
{
struct V_50 * V_51 = F_42 ( V_129 ) ;
int V_154 ;
for ( V_154 = 0 ; V_154 < V_51 -> V_159 ; V_154 ++ )
F_40 ( V_51 -> V_153 [ V_154 ] ) ;
return 0 ;
}
static void F_43 ( struct V_128 * V_129 )
{
struct V_50 * V_51 = F_42 ( V_129 ) ;
int V_154 ;
for ( V_154 = 0 ; V_154 < V_51 -> V_159 ; V_154 ++ ) {
int V_155 ;
if ( ! V_51 -> V_153 [ V_154 ] )
continue;
V_155 = F_22 ( V_51 , V_154 , 0 ) ;
if ( V_155 < 0 )
F_23 ( & V_129 -> V_48 ,
L_21 ) ;
}
}
static int T_2 F_44 ( void )
{
return F_45 ( & V_189 ) ;
}
static void T_3 F_46 ( void )
{
F_47 ( & V_189 ) ;
}
