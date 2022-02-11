static inline int F_1 ( struct V_1 * V_2 , T_1 V_3 )
{
unsigned int V_4 ;
int V_5 ;
V_5 = F_2 ( V_2 -> V_6 , V_3 , & V_4 ) ;
if ( V_5 )
return V_5 ;
return V_4 ;
}
static int F_3 ( struct V_1 * V_2 , T_1 V_3 ,
T_1 V_7 , T_1 V_8 )
{
int V_5 , V_9 ;
F_4 ( & V_2 -> V_10 ) ;
V_9 = F_1 ( V_2 , V_3 ) ;
if ( V_9 < 0 ) {
F_5 ( V_2 -> V_6 -> V_11 , L_1 , V_3 ) ;
V_5 = V_9 ;
goto V_12;
}
V_9 &= ~ V_8 ;
V_9 |= V_7 ;
V_5 = F_6 ( V_2 -> V_6 , V_3 , V_9 ) ;
if ( V_5 )
F_5 ( V_2 -> V_6 -> V_11 , L_2 , V_3 ) ;
V_12:
F_7 ( & V_2 -> V_10 ) ;
return V_5 ;
}
static int F_8 ( struct V_1 * V_2 , T_1 V_3 )
{
int V_9 ;
F_4 ( & V_2 -> V_10 ) ;
V_9 = F_1 ( V_2 , V_3 ) ;
if ( V_9 < 0 )
F_5 ( V_2 -> V_6 -> V_11 , L_1 , V_3 ) ;
F_7 ( & V_2 -> V_10 ) ;
return V_9 ;
}
static int F_9 ( struct V_1 * V_2 , T_1 V_3 , T_1 V_4 )
{
int V_5 ;
F_4 ( & V_2 -> V_10 ) ;
V_5 = F_6 ( V_2 -> V_6 , V_3 , V_4 ) ;
if ( V_5 < 0 )
F_5 ( V_2 -> V_6 -> V_11 , L_2 , V_3 ) ;
F_7 ( & V_2 -> V_10 ) ;
return V_5 ;
}
static int F_10 ( int V_13 )
{
switch ( V_13 ) {
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
case V_30 :
return V_31 ;
case V_32 :
return V_33 ;
case V_34 :
return V_35 ;
case V_36 :
return V_37 ;
case V_38 :
return V_39 ;
default:
return - V_40 ;
}
}
static int F_11 ( int V_13 )
{
switch ( V_13 ) {
case V_14 :
return V_15 ;
case V_16 :
return V_17 ;
case V_18 :
return V_19 ;
case V_20 :
return V_21 ;
case V_41 :
return V_42 ;
case V_43 :
return V_44 ;
case V_45 :
return V_46 ;
case V_47 :
return V_48 ;
case V_49 :
return V_50 ;
case V_51 :
return V_52 ;
case V_53 :
return V_54 ;
case V_55 :
return V_56 ;
case V_57 :
return V_58 ;
default:
return - V_40 ;
}
}
static int F_12 ( struct V_59 * V_11 )
{
struct V_1 * V_2 = F_13 ( V_11 ) ;
int V_13 = F_14 ( V_11 ) ;
return V_2 -> V_60 [ V_13 ] -> V_61 ;
}
static int F_15 ( struct V_59 * V_11 , unsigned int V_62 )
{
struct V_1 * V_2 = F_13 ( V_11 ) ;
struct V_63 * V_6 = V_2 -> V_6 ;
int V_3 , V_64 , V_13 = F_14 ( V_11 ) ;
V_3 = V_2 -> V_65 ( V_13 ) ;
if ( V_3 < 0 )
return V_3 ;
switch ( V_62 ) {
case V_66 :
return F_3 ( V_2 , V_3 , V_67 ,
V_68 ) ;
case V_69 :
V_64 = V_67 | V_68 ;
return F_16 ( V_6 , V_3 , V_64 ) ;
case V_70 :
return F_17 ( V_6 , V_3 , V_67 ) ;
}
return - V_40 ;
}
static unsigned int F_18 ( struct V_59 * V_11 )
{
struct V_1 * V_2 = F_13 ( V_11 ) ;
int V_3 , V_64 , V_13 = F_14 ( V_11 ) ;
V_3 = V_2 -> V_65 ( V_13 ) ;
if ( V_3 < 0 )
return V_3 ;
V_64 = F_8 ( V_2 , V_3 ) ;
if ( V_64 < 0 )
return V_64 ;
if ( ! ( V_64 & V_67 ) )
return V_70 ;
else if ( V_64 & V_68 )
return V_69 ;
else
return V_66 ;
}
static int F_19 ( struct V_59 * V_11 )
{
struct V_1 * V_2 = F_13 ( V_11 ) ;
int V_13 = F_14 ( V_11 ) ;
int V_71 = 0 , V_72 = 0 , V_73 = 0 , V_74 = 0 , V_75 = 0 ;
switch ( V_13 ) {
case V_18 :
V_71 = F_8 ( V_2 , V_76 ) ;
V_74 = F_8 ( V_2 , V_19 ) ;
V_74 = ( V_74 & V_77 ) >> V_78 ;
V_72 = F_8 ( V_2 , V_79 ) ;
V_75 = V_71 & V_80 ;
V_71 &= V_81 ;
V_72 &= V_82 ;
V_73 = 75 ;
break;
case V_20 :
V_71 = F_8 ( V_2 , V_83 ) ;
V_74 = F_8 ( V_2 , V_21 ) ;
V_74 = ( V_74 & V_84 ) >> V_85 ;
V_72 = F_8 ( V_2 , V_86 ) ;
V_75 = V_71 & V_87 ;
V_71 &= V_88 ;
V_72 &= V_89 ;
V_73 = 75 ;
break;
case V_41 :
V_71 = F_8 ( V_2 , V_90 ) ;
V_72 = F_8 ( V_2 , V_91 ) ;
V_75 = V_71 & V_92 ;
V_71 &= V_93 ;
V_72 &= V_94 ;
V_73 = 64 ;
break;
}
if ( ! V_74 )
V_74 = 1 ;
if ( V_75 ) {
if ( V_72 < 3 )
V_72 = 3 ;
if ( V_72 > V_73 )
V_72 = V_73 ;
return V_72 - 3 ;
} else {
if ( V_71 < 3 )
V_71 = 3 ;
if ( V_71 > V_73 )
V_71 = V_73 ;
return V_71 - 3 ;
}
return - V_40 ;
}
static int F_20 ( struct V_59 * V_11 )
{
struct V_1 * V_2 = F_13 ( V_11 ) ;
int V_3 , V_64 , V_13 = F_14 ( V_11 ) ;
V_3 = V_2 -> V_65 ( V_13 ) ;
if ( V_3 < 0 )
return V_3 ;
V_64 = F_8 ( V_2 , V_3 ) ;
if ( V_64 < 0 )
return V_64 ;
switch ( V_13 ) {
case V_16 :
case V_24 :
case V_26 :
case V_28 :
case V_30 :
case V_32 :
case V_34 :
case V_36 :
case V_38 :
V_64 &= V_95 ;
V_64 >>= V_96 ;
break;
default:
return - V_40 ;
}
return V_64 ;
}
static int F_21 ( struct V_59 * V_11 )
{
return 5 * 1000 * 1000 ;
}
static int F_22 ( struct V_59 * V_11 )
{
struct V_1 * V_2 = F_13 ( V_11 ) ;
int V_13 = F_14 ( V_11 ) ;
T_1 V_64 , V_3 ;
V_3 = V_2 -> V_65 ( V_13 ) ;
V_64 = F_8 ( V_2 , V_3 ) ;
switch ( V_13 ) {
case V_43 :
case V_45 :
case V_49 :
V_64 &= V_97 ;
V_64 >>= V_96 ;
break;
case V_47 :
case V_51 :
case V_53 :
case V_55 :
case V_57 :
V_64 &= V_98 ;
V_64 >>= V_96 ;
break;
case V_16 :
V_64 &= V_95 ;
V_64 >>= V_96 ;
break;
default:
return - V_40 ;
}
return V_64 ;
}
static int F_23 ( struct V_59 * V_11 ,
unsigned V_99 )
{
struct V_1 * V_2 = F_13 ( V_11 ) ;
int V_13 = F_14 ( V_11 ) , V_100 ;
int V_101 = 0 ;
switch ( V_13 ) {
case V_18 :
V_101 = ( V_99 / V_102 ) + 1 ;
if ( V_101 == 1 )
V_101 -- ;
V_100 = ( V_99 % V_102 ) + 3 ;
F_3 ( V_2 , V_19 ,
( V_101 << V_78 ) ,
V_77 ) ;
F_9 ( V_2 , V_76 , V_100 ) ;
break;
case V_20 :
V_101 = ( V_99 / V_102 ) + 1 ;
if ( V_101 == 1 )
V_101 -- ;
V_100 = ( V_99 % V_102 ) + 3 ;
F_3 ( V_2 , V_21 ,
( V_101 << V_85 ) ,
V_77 ) ;
F_9 ( V_2 , V_83 , V_100 ) ;
break;
case V_41 :
V_100 = V_99 + 3 ;
F_9 ( V_2 , V_90 , V_100 ) ;
}
return 0 ;
}
static int F_24 ( struct V_59 * V_11 ,
unsigned V_99 )
{
struct V_1 * V_2 = F_13 ( V_11 ) ;
int V_3 , V_13 = F_14 ( V_11 ) ;
V_3 = V_2 -> V_65 ( V_13 ) ;
if ( V_3 < 0 )
return V_3 ;
switch ( V_13 ) {
case V_16 :
case V_24 :
case V_26 :
case V_28 :
case V_30 :
case V_32 :
case V_34 :
case V_36 :
case V_38 :
return F_3 ( V_2 , V_3 ,
( V_99 << V_96 ) , V_95 ) ;
}
return - V_40 ;
}
static int F_25 ( struct V_59 * V_11 ,
unsigned V_99 )
{
struct V_1 * V_2 = F_13 ( V_11 ) ;
int V_3 , V_13 = F_14 ( V_11 ) ;
V_3 = V_2 -> V_65 ( V_13 ) ;
if ( V_3 < 0 )
return V_3 ;
switch ( V_13 ) {
case V_43 :
case V_45 :
case V_49 :
return F_3 ( V_2 , V_3 ,
( V_99 << V_96 ) , V_97 ) ;
case V_47 :
case V_51 :
case V_53 :
case V_55 :
case V_57 :
return F_3 ( V_2 , V_3 ,
( V_99 << V_96 ) , V_98 ) ;
case V_16 :
return F_3 ( V_2 , V_3 ,
( V_99 << V_96 ) , V_95 ) ;
}
return - V_40 ;
}
static int F_26 ( struct V_59 * V_11 ,
unsigned V_99 )
{
int V_103 , V_74 = 1 , V_13 = F_14 ( V_11 ) ;
switch ( V_13 ) {
case V_18 :
case V_20 :
V_74 = ( V_99 / V_102 ) + 1 ;
V_103 = V_104 +
( V_99 % V_102 ) * V_105 ;
break;
case V_41 :
V_103 = V_106 + ( V_99 * V_107 ) ;
break;
default:
F_27 () ;
return - V_40 ;
}
return V_103 * 100 * V_74 ;
}
static int F_28 ( struct V_59 * V_11 ,
unsigned V_99 )
{
struct V_1 * V_2 = F_13 ( V_11 ) ;
int V_13 = F_14 ( V_11 ) , V_108 ;
if ( V_13 < V_16 || V_13 > V_38 )
return - V_40 ;
if ( V_99 >= V_2 -> V_60 [ V_13 ] -> V_109 )
return - V_40 ;
else
V_108 = V_2 -> V_60 [ V_13 ] -> V_110 [ V_99 ] * 1000 ;
return V_108 ;
}
static int F_29 ( struct V_59 * V_11 , unsigned V_99 )
{
struct V_1 * V_2 = F_13 ( V_11 ) ;
int V_111 = 0 , V_13 = F_14 ( V_11 ) ;
switch( V_13 ) {
case V_43 :
case V_45 :
case V_49 :
if ( V_99 < 5 )
V_99 = 0 ;
else
V_99 -= 4 ;
V_111 = 50 ;
break;
case V_47 :
case V_51 :
case V_53 :
case V_55 :
case V_57 :
if ( V_99 < 3 )
V_99 = 0 ;
else
V_99 -= 2 ;
V_111 = 100 ;
break;
case V_16 :
return V_2 -> V_60 [ V_13 ] -> V_110 [ V_99 ] * 1000 ;
default:
return - V_40 ;
}
return ( V_112 + V_99 * V_111 ) * 1000 ;
}
static int F_30 ( struct V_59 * V_11 ,
unsigned int V_113 , unsigned int V_114 )
{
int V_13 = F_14 ( V_11 ) ;
int V_115 , V_116 ;
V_115 = F_26 ( V_11 , V_113 ) ;
if ( V_115 < 0 )
return V_115 ;
V_116 = F_26 ( V_11 , V_114 ) ;
if ( V_116 < 0 )
return V_116 ;
switch ( V_13 ) {
case V_18 :
case V_20 :
return F_31 ( abs ( V_115 - V_116 ) , 12500 ) ;
case V_41 :
return F_31 ( abs ( V_115 - V_116 ) , 5000 ) ;
}
return - V_40 ;
}
static int F_32 ( struct V_1 * V_2 ,
int V_13 , int V_117 )
{
struct V_63 * V_6 = V_2 -> V_6 ;
T_1 V_118 = ( V_2 -> V_119 [ V_13 ] >> 8 ) & 0xFF ;
T_1 V_120 = ( 1 << V_2 -> V_119 [ V_13 ] & 0xFF ) ;
int V_121 ;
if ( V_117 & V_122 ) {
int V_123 ;
V_123 = ( ( V_117 &
V_124 ) != 0 ) ;
V_123 += ( ( V_117 &
V_125 ) != 0 ) ;
V_123 += ( ( V_117 &
V_126 ) != 0 ) ;
V_123 += ( ( V_117 &
V_127 ) != 0 ) ;
if ( V_123 > 1 ) {
F_5 ( V_6 -> V_11 ,
L_3 ) ;
return - V_40 ;
}
}
V_2 -> V_128 [ V_13 ] = V_117 ;
if ( V_117 & V_124 )
V_121 = F_16 ( V_6 ,
V_129 + V_118 , V_120 ) ;
else
V_121 = F_17 ( V_6 ,
V_129 + V_118 , V_120 ) ;
if ( V_121 < 0 ) {
F_5 ( V_6 -> V_11 ,
L_4 ) ;
return V_121 ;
}
if ( V_117 & V_125 )
V_121 = F_16 ( V_6 ,
V_130 + V_118 , V_120 ) ;
else
V_121 = F_17 ( V_6 ,
V_130 + V_118 , V_120 ) ;
if ( V_121 < 0 ) {
F_5 ( V_6 -> V_11 ,
L_5 ) ;
return V_121 ;
}
if ( ( F_33 ( V_6 ) == V_131 ) &&
( V_13 >= V_24 ) ) {
if ( V_117 & V_126 )
V_121 = F_16 ( V_6 ,
V_132 + V_118 , V_120 ) ;
else
V_121 = F_17 ( V_6 ,
V_132 + V_118 , V_120 ) ;
if ( V_121 < 0 ) {
F_5 ( V_6 -> V_11 ,
L_6 ) ;
return V_121 ;
}
}
if ( ! ( V_117 & V_122 ) ) {
V_121 = F_17 ( V_6 ,
V_133 + V_118 , V_120 ) ;
if ( ! V_121 )
V_121 = F_17 ( V_6 ,
V_134 + V_118 , V_120 ) ;
if ( V_121 < 0 )
F_5 ( V_6 -> V_11 ,
L_7 ) ;
return V_121 ;
}
if ( ( V_13 == V_18 ) ||
( V_13 == V_20 ) ||
( ( V_13 == V_41 ) &&
( F_33 ( V_6 ) == V_135 ) ) ) {
int V_136 = V_2 -> V_65 ( V_13 ) + 1 ;
int V_137 = V_2 -> V_65 ( V_13 ) + 2 ;
int V_71 = F_8 ( V_2 , V_136 ) ;
int V_72 = F_8 ( V_2 , V_137 ) ;
if ( V_71 & V_80 ) {
T_1 V_138 = V_72 & V_81 ;
V_121 = F_9 ( V_2 , V_136 ,
V_138 ) ;
if ( V_121 < 0 ) {
F_5 ( V_6 -> V_11 ,
L_8 ) ;
return V_121 ;
}
}
V_121 = F_9 ( V_2 , V_137 , 0 ) ;
if ( V_121 < 0 ) {
F_5 ( V_6 -> V_11 , L_9 ) ;
return V_121 ;
}
}
V_121 = F_17 ( V_6 ,
V_133 + V_118 , V_120 ) ;
if ( ! V_121 ) {
if ( V_117 & V_127 )
V_121 = F_16 ( V_6 ,
V_134 + V_118 , V_120 ) ;
else
V_121 = F_17 ( V_6 ,
V_134 + V_118 , V_120 ) ;
}
if ( V_121 < 0 )
F_5 ( V_6 -> V_11 ,
L_7 ) ;
return V_121 ;
}
static struct V_139 * F_34 (
struct V_140 * V_141 ,
struct V_142 * * V_143 )
{
struct V_139 * V_144 ;
struct V_63 * V_63 = F_35 ( V_141 -> V_11 . V_145 ) ;
struct V_146 * V_147 = V_141 -> V_11 . V_145 -> V_148 ;
struct V_146 * V_149 ;
struct V_142 * V_150 ;
unsigned int V_151 ;
int V_152 = 0 , V_121 , V_153 ;
V_144 = F_36 ( & V_141 -> V_11 , sizeof( * V_144 ) ,
V_154 ) ;
if ( ! V_144 ) {
F_5 ( & V_141 -> V_11 , L_10 ) ;
return NULL ;
}
V_149 = F_37 ( V_147 , L_11 ) ;
if ( ! V_149 ) {
F_5 ( & V_141 -> V_11 , L_12 ) ;
return NULL ;
}
switch ( F_33 ( V_63 ) ) {
case V_131 :
V_153 = F_38 ( V_155 ) ;
V_150 = V_155 ;
break;
case V_135 :
V_153 = F_38 ( V_156 ) ;
V_150 = V_156 ;
break;
default:
F_5 ( & V_141 -> V_11 , L_13 ) ;
return NULL ;
}
V_121 = V_142 ( V_141 -> V_11 . V_145 , V_149 , V_150 , V_153 ) ;
if ( V_121 < 0 ) {
F_5 ( & V_141 -> V_11 , L_14 ,
V_121 ) ;
return NULL ;
}
* V_143 = V_150 ;
for ( V_152 = 0 ; V_152 < V_153 ; V_152 ++ ) {
if ( ! V_150 [ V_152 ] . V_157 || ! V_150 [ V_152 ] . V_148 )
continue;
V_144 -> V_158 [ V_152 ] =
V_150 [ V_152 ] . V_157 ;
V_121 = F_39 ( V_150 [ V_152 ] . V_148 ,
L_15 , & V_151 ) ;
if ( ! V_121 )
V_144 -> V_159 [ V_152 ] = V_151 ;
}
return V_144 ;
}
static inline struct V_139 * F_34 (
struct V_140 * V_141 ,
struct V_142 * * V_143 )
{
* V_143 = NULL ;
return 0 ;
}
static T_2 int F_40 ( struct V_140 * V_141 )
{
struct V_63 * V_63 = F_35 ( V_141 -> V_11 . V_145 ) ;
struct V_160 V_161 = { } ;
struct V_162 * V_60 ;
struct V_163 * V_164 ;
struct V_59 * V_165 ;
struct V_1 * V_2 ;
struct V_139 * V_144 ;
struct V_142 * V_143 = NULL ;
int V_166 , V_5 ;
V_144 = F_41 ( V_63 -> V_11 ) ;
if ( ! V_144 && V_63 -> V_11 -> V_148 )
V_144 = F_34 ( V_141 ,
& V_143 ) ;
if ( ! V_144 ) {
F_5 ( & V_141 -> V_11 , L_16 ) ;
return - V_40 ;
}
V_2 = F_36 ( & V_141 -> V_11 , sizeof( * V_2 ) , V_154 ) ;
if ( ! V_2 ) {
F_5 ( & V_141 -> V_11 , L_17 ) ;
return - V_167 ;
}
F_42 ( & V_2 -> V_10 ) ;
V_2 -> V_6 = V_63 ;
F_43 ( V_141 , V_2 ) ;
F_16 ( V_2 -> V_6 , V_168 ,
V_169 ) ;
switch( F_33 ( V_63 ) ) {
case V_131 :
V_2 -> V_65 = & F_10 ;
V_2 -> V_170 = F_38 ( V_171 ) ;
V_2 -> V_119 = V_172 ;
V_60 = V_171 ;
break;
case V_135 :
V_2 -> V_65 = & F_11 ;
V_2 -> V_170 = F_38 ( V_173 ) ;
V_2 -> V_119 = V_174 ;
V_60 = V_173 ;
break;
default:
F_5 ( & V_141 -> V_11 , L_13 ) ;
return - V_175 ;
}
V_2 -> V_176 = F_36 ( & V_141 -> V_11 , V_2 -> V_170 *
sizeof( struct V_177 ) , V_154 ) ;
if ( ! V_2 -> V_176 ) {
F_5 ( & V_141 -> V_11 , L_18 ) ;
return - V_167 ;
}
V_2 -> V_60 = F_36 ( & V_141 -> V_11 , V_2 -> V_170 *
sizeof( struct V_162 * ) , V_154 ) ;
if ( ! V_2 -> V_60 ) {
F_5 ( & V_141 -> V_11 , L_19 ) ;
return - V_167 ;
}
V_2 -> V_165 = F_36 ( & V_141 -> V_11 , V_2 -> V_170 *
sizeof( struct V_59 * ) , V_154 ) ;
if ( ! V_2 -> V_165 ) {
F_5 ( & V_141 -> V_11 , L_20 ) ;
return - V_167 ;
}
for ( V_166 = 0 ; V_166 < V_2 -> V_170 && V_166 < V_178 ;
V_166 ++ , V_60 ++ ) {
V_164 = V_144 -> V_158 [ V_166 ] ;
if ( ! V_164 )
continue;
V_2 -> V_60 [ V_166 ] = V_60 ;
V_2 -> V_176 [ V_166 ] . V_179 = V_60 -> V_179 ;
V_2 -> V_176 [ V_166 ] . V_13 = V_166 ;
V_2 -> V_176 [ V_166 ] . V_109 = V_60 -> V_109 ;
if ( V_166 == V_18 || V_166 == V_20 ) {
V_2 -> V_176 [ V_166 ] . V_180 = & V_181 ;
V_2 -> V_176 [ V_166 ] . V_109 = V_102 *
V_182 ;
} else if ( V_166 == V_22 ) {
if ( F_33 ( V_63 ) == V_131 )
V_2 -> V_176 [ V_166 ] . V_180 = & V_183 ;
else
V_2 -> V_176 [ V_166 ] . V_180 = & V_181 ;
} else {
if ( F_33 ( V_63 ) == V_131 )
V_2 -> V_176 [ V_166 ] . V_180 = & V_184 ;
else
V_2 -> V_176 [ V_166 ] . V_180 = & V_185 ;
}
V_5 = F_32 ( V_2 , V_166 ,
V_144 -> V_159 [ V_166 ] ) ;
if ( V_5 < 0 )
F_44 ( V_63 -> V_11 ,
L_21 ) ;
V_2 -> V_176 [ V_166 ] . type = V_186 ;
V_2 -> V_176 [ V_166 ] . V_187 = V_188 ;
V_2 -> V_176 [ V_166 ] . V_189 = V_2 -> V_65 ( V_166 ) ;
V_2 -> V_176 [ V_166 ] . V_190 = V_191 ;
V_161 . V_11 = V_63 -> V_11 ;
V_161 . V_157 = V_164 ;
V_161 . V_192 = V_2 ;
V_161 . V_193 = V_63 -> V_193 ;
if ( V_143 )
V_161 . V_148 = V_143 [ V_166 ] . V_148 ;
V_165 = F_45 ( & V_2 -> V_176 [ V_166 ] , & V_161 ) ;
if ( F_46 ( V_165 ) ) {
F_5 ( V_63 -> V_11 ,
L_22 ,
V_141 -> V_179 ) ;
V_5 = F_47 ( V_165 ) ;
goto V_194;
}
V_2 -> V_165 [ V_166 ] = V_165 ;
}
return 0 ;
V_194:
while ( -- V_166 >= 0 )
F_48 ( V_2 -> V_165 [ V_166 ] ) ;
return V_5 ;
}
static int T_3 F_49 ( struct V_140 * V_141 )
{
struct V_1 * V_2 = F_50 ( V_141 ) ;
int V_166 ;
for ( V_166 = 0 ; V_166 < V_2 -> V_170 ; V_166 ++ )
F_48 ( V_2 -> V_165 [ V_166 ] ) ;
return 0 ;
}
static void F_51 ( struct V_140 * V_141 )
{
struct V_1 * V_2 = F_50 ( V_141 ) ;
int V_166 ;
for ( V_166 = 0 ; V_166 < V_2 -> V_170 ; V_166 ++ ) {
int V_5 ;
if ( ! V_2 -> V_165 [ V_166 ] )
continue;
V_5 = F_32 ( V_2 , V_166 , 0 ) ;
if ( V_5 < 0 )
F_5 ( & V_141 -> V_11 ,
L_23 ) ;
}
}
static int T_4 F_52 ( void )
{
return F_53 ( & V_195 ) ;
}
static void T_5 F_54 ( void )
{
F_55 ( & V_195 ) ;
}
