static inline struct V_1 * F_1 ( struct V_2 * V_3 )
{
return F_2 ( V_3 , struct V_1 , V_4 . V_3 ) ;
}
static inline struct V_5 * F_3 ( struct V_6 * V_7 )
{
return F_2 ( V_7 , struct V_5 , V_8 . V_7 ) ;
}
static int F_4 ( struct V_1 * V_9 )
{
const struct V_10 * V_11 = V_9 -> V_12 -> V_11 ;
int V_13 ;
if ( V_9 -> V_14 ++ == 0 && V_11 -> V_15 ) {
V_13 = V_11 -> V_15 ( V_9 -> V_16 ) ;
if ( V_13 < 0 ) {
V_9 -> V_14 = 0 ;
return V_13 ;
}
V_9 -> signal = V_13 ;
}
return 0 ;
}
static void F_5 ( struct V_1 * V_9 )
{
const struct V_10 * V_11 = V_9 -> V_12 -> V_11 ;
if ( V_9 -> signal >= 0 ) {
F_6 ( V_9 -> V_14 == 0 ) ;
if ( -- V_9 -> V_14 == 0 && V_11 -> V_17 ) {
V_11 -> V_17 ( V_9 -> V_16 , V_9 -> signal ) ;
V_9 -> signal = - 1 ;
}
}
}
static int F_7 ( struct V_18 * V_19 )
{
unsigned int V_20 ;
if ( V_19 -> V_21 ) {
V_20 = F_8 ( V_19 -> V_21 ) ;
return ! ! ( V_20 & F_9 ( V_19 -> V_22 ) ) ;
}
V_20 = F_8 ( V_19 -> V_23 ) ;
return V_20 & V_24 ;
}
static void F_10 ( struct V_25 * V_26 ,
struct V_18 * V_27 , const T_1 * V_28 , T_1 V_29 )
{
if ( V_26 -> V_8 -> V_30 )
F_11 ( & V_26 -> V_31 -> V_32 ,
L_1
L_2 ,
V_27 -> V_22 , V_28 [ V_33 ] , V_28 [ V_34 ] ,
V_28 [ V_35 ] , V_28 [ V_36 ] ,
V_28 [ V_37 ] , V_29 ) ;
else
F_11 ( & V_26 -> V_31 -> V_32 ,
L_1
L_3 ,
V_27 -> V_22 , V_28 [ V_33 ] , V_28 [ V_34 ] ,
V_28 [ V_35 ] , V_28 [ V_36 ] , V_29 ) ;
F_12 ( V_28 [ V_33 ] , V_27 -> V_38 ) ;
F_12 ( V_28 [ V_34 ] , V_27 -> V_39 ) ;
F_12 ( V_28 [ V_35 ] , V_27 -> V_40 ) ;
if ( V_27 -> V_41 ) {
T_1 V_42 = V_28 [ V_36 ] ;
T_1 V_20 = 0 ;
F_12 ( V_42 & V_43 ,
V_27 -> V_44 + V_45 ) ;
if ( V_42 & V_46 )
V_20 |= V_47 ;
V_20 |= ( ( V_42 & V_48 ) >>
( V_49 -
V_50 ) ) ;
V_20 |= ( ( V_42 & V_51 ) >>
( V_52 -
V_53 ) ) ;
V_20 |= ( ( V_42 & V_54 ) >>
( V_55 -
V_56 ) ) ;
V_20 |= ( ( V_42 & V_57 ) >>
( V_58 -
V_59 ) ) ;
if ( V_42 & V_60 )
V_20 |= V_61 ;
if ( V_42 & V_62 )
V_20 |= V_63 ;
switch ( V_26 -> V_11 -> V_64 ) {
default:
case V_65 :
V_20 |= V_66 <<
V_67 ;
break;
case V_68 :
V_20 |= V_69 <<
V_67 ;
break;
case V_70 :
V_20 |= V_71 <<
V_67 ;
break;
case V_72 :
V_20 |= V_73 <<
V_67 ;
break;
case V_74 :
V_20 |= V_75 <<
V_67 ;
break;
case V_76 :
V_20 |= V_77 <<
V_67 ;
break;
case V_78 :
V_20 |= V_79 <<
V_67 ;
break;
case V_80 :
V_20 |= V_81 <<
V_67 ;
break;
}
if ( V_26 -> V_11 -> V_82 )
V_20 |= V_83 ;
if ( V_26 -> V_11 -> V_84 )
V_20 |= V_85 ;
V_20 |= V_86 ;
F_12 ( V_20 , V_27 -> V_87 ) ;
} else {
F_12 ( V_28 [ V_36 ] , V_27 -> V_87 ) ;
}
if ( V_26 -> V_8 -> V_30 )
F_12 ( V_28 [ V_37 ] ,
V_27 -> V_44 + V_88 ) ;
F_13 ( V_29 , V_27 -> V_23 ) ;
}
static void F_14 ( struct V_1 * V_9 )
{
struct V_25 * V_26 = V_9 -> V_12 ;
struct V_18 * V_27 = V_9 -> V_27 ;
struct V_89 * V_8 = F_15 ( & V_9 -> V_4 ) ;
struct V_5 * V_90 = F_3 ( & V_8 -> V_7 ) ;
T_1 V_20 ;
F_16 ( & V_90 -> V_8 . V_91 ) ;
V_9 -> V_92 = V_90 ;
while ( F_7 ( V_27 ) )
F_17 () ;
F_10 ( V_26 , V_27 , & V_90 -> V_93 [ 0 ] , V_90 -> V_29 ) ;
while ( F_8 ( V_26 -> V_44 + V_94 ) & F_9 ( V_27 -> V_22 ) )
F_17 () ;
if ( V_27 -> V_41 ) {
V_20 = F_8 ( V_27 -> V_23 ) ;
while ( V_20 & V_95 )
V_20 = F_8 ( V_27 -> V_23 ) ;
V_20 = F_8 ( V_27 -> V_87 ) ;
while ( V_20 & V_96 )
V_20 = F_8 ( V_27 -> V_87 ) ;
F_13 ( V_20 | V_96 ,
V_27 -> V_87 ) ;
} else {
V_20 = F_8 ( V_27 -> V_23 ) ;
while ( ( V_20 & V_24 ) ||
( V_20 & V_97 ) )
V_20 = F_8 ( V_27 -> V_23 ) ;
F_13 ( V_20 | V_97 , V_27 -> V_23 ) ;
}
}
static void F_18 ( struct V_18 * V_19 )
{
T_1 V_20 ;
int V_98 ;
if ( V_19 -> V_41 ) {
V_20 = F_8 ( V_19 -> V_87 ) ;
V_20 &= ~ V_96 ;
F_13 ( V_20 , V_19 -> V_87 ) ;
return;
}
V_20 = F_8 ( V_19 -> V_23 ) ;
V_20 |= V_99 ;
F_13 ( V_20 , V_19 -> V_23 ) ;
for ( V_98 = 1000 ; V_98 ; V_98 -- ) {
if ( ! F_7 ( V_19 ) )
break;
F_19 ( 1 ) ;
}
if ( F_7 ( V_19 ) )
F_20 ( L_4 , V_19 -> V_22 ) ;
}
static void F_21 ( struct V_18 * V_19 )
{
T_1 V_20 ;
if ( V_19 -> V_41 ) {
V_20 = F_8 ( V_19 -> V_87 ) ;
V_20 |= V_96 ;
F_13 ( V_20 , V_19 -> V_87 ) ;
return;
}
V_20 = F_8 ( V_19 -> V_23 ) ;
V_20 &= ~ V_99 ;
F_13 ( V_20 , V_19 -> V_23 ) ;
}
static void F_22 ( struct V_25 * V_26 ,
struct V_18 * V_19 )
{
T_1 V_20 ;
if ( V_19 -> V_41 ) {
V_20 = F_8 ( V_19 -> V_23 ) ;
V_20 |= ( V_100 |
V_101 |
V_102 ) ;
F_13 ( V_20 , V_19 -> V_23 ) ;
V_20 = F_8 ( V_19 -> V_87 ) ;
V_20 &= ~ V_96 ;
V_20 |= V_103 ;
F_13 ( V_20 , V_19 -> V_87 ) ;
F_13 ( F_9 ( V_19 -> V_22 ) | F_9 ( V_19 -> V_22 + 16 ) ,
V_26 -> V_44 + V_104 ) ;
F_13 ( F_9 ( V_19 -> V_22 ) , V_26 -> V_44 + V_105 ) ;
return;
}
V_20 = F_8 ( V_19 -> V_23 ) ;
V_20 &= ~ ( V_97 | V_106 |
V_107 ) ;
F_13 ( V_20 , V_19 -> V_23 ) ;
F_13 ( F_9 ( V_19 -> V_22 ) , V_26 -> V_44 + V_104 ) ;
F_13 ( F_9 ( V_19 -> V_22 ) , V_26 -> V_44 + V_105 ) ;
}
static T_1 F_23 ( struct V_18 * V_19 )
{
T_1 V_20 ;
T_1 V_108 ;
if ( V_19 -> V_41 ) {
V_108 = F_8 ( V_19 -> V_44 + V_45 ) ;
V_20 = F_8 ( V_19 -> V_87 ) ;
V_20 &= V_109 ;
V_20 >>= V_50 ;
} else if ( V_19 -> V_30 ) {
V_20 = F_8 ( V_19 -> V_44 + V_88 ) ;
V_108 = V_20 & V_110 ;
V_20 = F_8 ( V_19 -> V_87 ) ;
V_20 &= V_111 ;
V_20 >>= V_112 ;
} else {
V_20 = F_8 ( V_19 -> V_87 ) ;
V_108 = V_20 & V_113 ;
V_20 &= V_111 ;
V_20 >>= V_112 ;
}
switch ( V_20 ) {
case V_114 :
break;
case V_115 :
V_108 *= 2 ;
break;
case V_116 :
V_108 *= 4 ;
break;
}
return V_108 ;
}
static T_1 F_24 ( struct V_18 * V_19 , const T_1 * V_93 )
{
T_1 V_20 ;
T_1 V_108 ;
if ( V_19 -> V_41 ) {
V_20 = V_93 [ V_36 ] ;
V_108 = V_20 & V_43 ;
V_20 = V_93 [ V_36 ] ;
V_20 &= V_48 ;
V_20 >>= V_49 ;
} else if ( V_19 -> V_30 ) {
V_20 = V_93 [ V_37 ] ;
V_108 = V_20 & V_110 ;
V_20 = V_93 [ V_36 ] ;
V_20 &= V_111 ;
V_20 >>= V_112 ;
} else {
V_20 = V_93 [ V_36 ] ;
V_108 = V_20 & V_113 ;
V_20 &= V_111 ;
V_20 >>= V_112 ;
}
switch ( V_20 ) {
case V_114 :
break;
case V_115 :
V_108 *= 2 ;
break;
case V_116 :
V_108 *= 4 ;
break;
}
return V_108 ;
}
static T_1 F_25 ( struct V_1 * V_9 )
{
struct V_25 * V_26 = V_9 -> V_12 ;
const T_1 * V_93 , * V_117 ;
struct V_18 * V_19 ;
T_2 V_118 ;
struct V_5 * V_90 ;
T_1 V_119 ;
T_3 V_108 ;
T_1 V_120 ;
V_19 = V_9 -> V_27 ;
V_90 = V_9 -> V_92 ;
if ( ! V_19 || ! V_90 )
return 0 ;
V_120 = F_8 ( V_19 -> V_40 ) & ~ V_121 ;
V_108 = F_23 ( V_19 ) ;
if ( ! V_120 )
return V_108 ;
V_93 = V_90 -> V_93 ;
V_118 = V_90 -> V_118 ;
V_119 = V_26 -> V_122 * V_123 ;
F_26 ( V_120 < V_118 || V_120 >= V_118 +
sizeof( T_1 ) * V_119 ) ;
V_93 += ( V_120 - V_118 ) / sizeof( T_1 ) ;
V_117 = V_93 + V_119 ;
for (; V_93 < V_117 ; V_93 += V_26 -> V_122 ) {
V_108 += F_24 ( V_19 , V_93 ) ;
if ( V_93 [ V_35 ] <= V_120 )
break;
}
return V_108 ;
}
static struct V_18 *
F_27 ( struct V_25 * V_26 ,
struct V_1 * V_124 )
{
struct V_18 * V_19 = NULL ;
unsigned long V_125 ;
int V_126 ;
for ( V_126 = 0 ; V_126 < V_26 -> V_8 -> V_127 ; V_126 ++ ) {
V_19 = & V_26 -> V_128 [ V_126 ] ;
F_28 ( & V_19 -> V_129 , V_125 ) ;
if ( ! V_19 -> V_130 && ! V_19 -> V_131 ) {
V_19 -> V_131 = V_124 ;
F_29 ( & V_19 -> V_129 , V_125 ) ;
break;
}
F_29 ( & V_19 -> V_129 , V_125 ) ;
}
if ( V_126 == V_26 -> V_8 -> V_127 ) {
return NULL ;
}
return V_19 ;
}
static inline void F_30 ( struct V_25 * V_26 ,
struct V_18 * V_19 )
{
V_19 -> V_131 = NULL ;
}
static void F_31 ( struct V_1 * V_9 )
{
struct V_25 * V_26 = V_9 -> V_12 ;
struct V_18 * V_19 ;
V_19 = F_27 ( V_26 , V_9 ) ;
if ( ! V_19 ) {
F_32 ( & V_26 -> V_31 -> V_32 , L_5 , V_9 -> V_132 ) ;
V_9 -> V_133 = V_134 ;
return;
}
F_32 ( & V_26 -> V_31 -> V_32 , L_6 ,
V_19 -> V_22 , V_9 -> V_132 ) ;
V_9 -> V_27 = V_19 ;
V_9 -> V_133 = V_135 ;
F_14 ( V_9 ) ;
}
static void F_33 ( struct V_18 * V_19 ,
struct V_1 * V_9 )
{
struct V_25 * V_26 = V_9 -> V_12 ;
F_32 ( & V_26 -> V_31 -> V_32 , L_7 ,
V_19 -> V_22 , V_9 -> V_132 ) ;
V_19 -> V_131 = V_9 ;
V_9 -> V_27 = V_19 ;
V_9 -> V_133 = V_135 ;
F_14 ( V_9 ) ;
}
static void F_34 ( struct V_1 * V_9 )
{
struct V_25 * V_26 = V_9 -> V_12 ;
struct V_1 * V_136 , * V_137 ;
V_138:
V_137 = NULL ;
F_35 (p, &pl08x->memcpy.channels, vc.chan.device_node)
if ( V_136 -> V_133 == V_134 ) {
V_137 = V_136 ;
break;
}
if ( ! V_137 && V_26 -> V_139 ) {
F_35 (p, &pl08x->slave.channels, vc.chan.device_node)
if ( V_136 -> V_133 == V_134 ) {
V_137 = V_136 ;
break;
}
}
F_22 ( V_26 , V_9 -> V_27 ) ;
if ( V_137 ) {
bool V_140 ;
F_36 ( & V_137 -> V_4 . V_129 ) ;
V_140 = V_137 -> V_133 == V_134 ;
if ( V_140 )
F_33 ( V_9 -> V_27 , V_137 ) ;
F_37 ( & V_137 -> V_4 . V_129 ) ;
if ( ! V_140 )
goto V_138;
} else {
F_30 ( V_26 , V_9 -> V_27 ) ;
}
V_9 -> V_27 = NULL ;
V_9 -> V_133 = V_141 ;
}
static inline unsigned int
F_38 ( struct V_25 * V_26 ,
T_1 V_142 ,
bool V_143 )
{
T_1 V_20 ;
if ( V_26 -> V_8 -> V_41 ) {
if ( V_143 )
V_20 = ( V_142 & V_48 ) >>
V_49 ;
else
V_20 = ( V_142 & V_51 ) >>
V_52 ;
} else {
if ( V_143 )
V_20 = ( V_142 & V_111 ) >>
V_112 ;
else
V_20 = ( V_142 & V_144 ) >>
V_145 ;
}
switch ( V_20 ) {
case V_114 :
return 1 ;
case V_115 :
return 2 ;
case V_116 :
return 4 ;
default:
break;
}
F_39 () ;
return 0 ;
}
static inline T_1 F_40 ( struct V_25 * V_26 ,
T_1 V_142 ,
T_4 V_146 , T_4 V_147 ,
T_3 V_148 )
{
T_1 V_149 = V_142 ;
if ( V_26 -> V_8 -> V_41 ) {
V_149 &= ~ V_51 ;
V_149 &= ~ V_48 ;
V_149 &= ~ V_43 ;
switch ( V_146 ) {
case 1 :
V_149 |= V_114 <<
V_49 ;
break;
case 2 :
V_149 |= V_115 <<
V_49 ;
break;
case 4 :
V_149 |= V_116 <<
V_49 ;
break;
default:
F_39 () ;
break;
}
switch ( V_147 ) {
case 1 :
V_149 |= V_114 <<
V_52 ;
break;
case 2 :
V_149 |= V_115 <<
V_52 ;
break;
case 4 :
V_149 |= V_116 <<
V_52 ;
break;
default:
F_39 () ;
break;
}
V_148 &= V_43 ;
V_149 |= V_148 << V_150 ;
} else {
V_149 &= ~ V_144 ;
V_149 &= ~ V_111 ;
V_149 &= ~ V_113 ;
switch ( V_146 ) {
case 1 :
V_149 |= V_114 <<
V_112 ;
break;
case 2 :
V_149 |= V_115 <<
V_112 ;
break;
case 4 :
V_149 |= V_116 <<
V_112 ;
break;
default:
F_39 () ;
break;
}
switch ( V_147 ) {
case 1 :
V_149 |= V_114 <<
V_145 ;
break;
case 2 :
V_149 |= V_115 <<
V_145 ;
break;
case 4 :
V_149 |= V_116 <<
V_145 ;
break;
default:
F_39 () ;
break;
}
V_148 &= V_113 ;
V_149 |= V_148 << V_151 ;
}
return V_149 ;
}
static void F_41 ( struct V_25 * V_26 ,
struct V_152 * V_153 ,
struct V_154 * * V_155 ,
struct V_154 * * V_156 ,
T_1 V_142 )
{
bool V_157 ;
bool V_158 ;
if ( V_26 -> V_8 -> V_41 ) {
V_157 = true ;
V_158 = true ;
} else {
V_157 = ! ! ( V_142 & V_159 ) ;
V_158 = ! ! ( V_142 & V_160 ) ;
}
if ( ! V_157 ) {
* V_155 = & V_153 -> V_161 ;
* V_156 = & V_153 -> V_162 ;
} else if ( ! V_158 ) {
* V_155 = & V_153 -> V_162 ;
* V_156 = & V_153 -> V_161 ;
} else {
if ( V_153 -> V_161 . V_163 >= V_153 -> V_162 . V_163 ) {
* V_155 = & V_153 -> V_161 ;
* V_156 = & V_153 -> V_162 ;
} else {
* V_155 = & V_153 -> V_162 ;
* V_156 = & V_153 -> V_161 ;
}
}
}
static void F_42 ( struct V_25 * V_26 ,
struct V_152 * V_153 ,
int V_164 , int V_165 , T_1 V_142 , T_1 V_166 )
{
T_1 V_167 = V_164 * V_26 -> V_122 ;
T_1 * V_93 = V_153 -> V_90 -> V_93 + V_167 ;
T_2 V_118 = V_153 -> V_90 -> V_118 ;
F_26 ( V_164 >= V_123 ) ;
V_167 += V_26 -> V_122 ;
V_93 [ V_33 ] = V_153 -> V_162 . V_168 ;
V_93 [ V_34 ] = V_153 -> V_161 . V_168 ;
V_93 [ V_35 ] = ( V_118 + sizeof( T_1 ) * V_167 ) ;
V_93 [ V_35 ] |= V_153 -> V_169 ;
V_93 [ V_36 ] = V_142 ;
if ( V_26 -> V_8 -> V_30 )
V_93 [ V_37 ] = V_166 ;
if ( V_26 -> V_8 -> V_41 ) {
V_153 -> V_162 . V_168 += V_165 ;
V_153 -> V_161 . V_168 += V_165 ;
} else {
if ( V_142 & V_160 )
V_153 -> V_162 . V_168 += V_165 ;
if ( V_142 & V_159 )
V_153 -> V_161 . V_168 += V_165 ;
}
F_26 ( V_153 -> V_170 < V_165 ) ;
V_153 -> V_170 -= V_165 ;
}
static inline void F_43 ( struct V_25 * V_26 ,
struct V_152 * V_153 , T_1 * V_142 , T_1 V_165 ,
int V_164 , T_3 * V_171 )
{
* V_142 = F_40 ( V_26 , * V_142 , 1 , 1 , V_165 ) ;
F_42 ( V_26 , V_153 , V_164 , V_165 , * V_142 , V_165 ) ;
( * V_171 ) += V_165 ;
}
static void F_44 ( struct V_25 * V_26 ,
const T_1 * V_93 , int V_164 )
{
int V_126 ;
if ( V_26 -> V_8 -> V_30 ) {
F_11 ( & V_26 -> V_31 -> V_32 ,
L_8 ,
L_9 , L_10 , L_11 , L_12 , L_13 , L_14 , L_15 ) ;
for ( V_126 = 0 ; V_126 < V_164 ; V_126 ++ ) {
F_11 ( & V_26 -> V_31 -> V_32 ,
L_16 ,
V_126 , V_93 , V_93 [ V_33 ] ,
V_93 [ V_34 ] , V_93 [ V_35 ] ,
V_93 [ V_36 ] ,
V_93 [ V_37 ] ) ;
V_93 += V_26 -> V_122 ;
}
} else {
F_11 ( & V_26 -> V_31 -> V_32 ,
L_17 ,
L_9 , L_10 , L_11 , L_12 , L_13 , L_14 ) ;
for ( V_126 = 0 ; V_126 < V_164 ; V_126 ++ ) {
F_11 ( & V_26 -> V_31 -> V_32 ,
L_18 ,
V_126 , V_93 , V_93 [ V_33 ] ,
V_93 [ V_34 ] , V_93 [ V_35 ] ,
V_93 [ V_36 ] ) ;
V_93 += V_26 -> V_122 ;
}
}
}
static inline void F_44 ( struct V_25 * V_26 ,
const T_1 * V_93 , int V_164 ) {}
static int F_45 ( struct V_25 * V_26 ,
struct V_5 * V_90 )
{
struct V_154 * V_155 , * V_156 ;
struct V_152 V_153 ;
int V_164 = 0 ;
T_1 V_142 , V_172 = 0 ;
T_3 V_173 , V_171 ;
T_1 * V_93 , * V_174 ;
struct V_175 * V_176 ;
V_90 -> V_93 = F_46 ( V_26 -> V_177 , V_178 , & V_90 -> V_118 ) ;
if ( ! V_90 -> V_93 ) {
F_47 ( & V_26 -> V_31 -> V_32 , L_19 , V_179 ) ;
return 0 ;
}
V_153 . V_90 = V_90 ;
V_153 . V_169 = ( V_26 -> V_180 & V_181 ) ? V_121 : 0 ;
V_142 = V_90 -> V_142 ;
V_153 . V_162 . V_182 = F_38 ( V_26 , V_142 , true ) ;
V_153 . V_161 . V_182 = F_38 ( V_26 , V_142 , false ) ;
F_35 (dsg, &txd->dsg_list, node) {
V_171 = 0 ;
V_142 = V_90 -> V_142 ;
V_153 . V_162 . V_168 = V_176 -> V_183 ;
V_153 . V_161 . V_168 = V_176 -> V_184 ;
V_153 . V_170 = V_176 -> V_165 ;
V_153 . V_162 . V_163 = V_153 . V_162 . V_182 ;
V_153 . V_161 . V_163 = V_153 . V_161 . V_182 ;
F_41 ( V_26 , & V_153 , & V_155 , & V_156 , V_142 ) ;
F_11 ( & V_26 -> V_31 -> V_32 ,
L_20 ,
( V_185 ) V_153 . V_162 . V_168 ,
V_142 & V_160 ? L_21 : L_10 ,
V_153 . V_162 . V_163 ,
( V_185 ) V_153 . V_161 . V_168 ,
V_142 & V_159 ? L_21 : L_10 ,
V_153 . V_161 . V_163 ,
V_153 . V_170 ) ;
F_11 ( & V_26 -> V_31 -> V_32 , L_22 ,
V_155 == & V_153 . V_162 ? L_23 : L_24 ,
V_156 == & V_153 . V_162 ? L_23 : L_24 ) ;
if ( ! V_153 . V_170 ) {
T_1 V_186 ;
if ( V_26 -> V_8 -> V_41 )
V_186 = V_187 ;
else
V_186 = ( V_90 -> V_29 & V_188 ) >>
V_189 ;
if ( ! ( ( V_186 >= V_190 ) &&
( V_186 <= V_191 ) ) ) {
F_47 ( & V_26 -> V_31 -> V_32 , L_25 ,
V_179 ) ;
return 0 ;
}
if ( ! F_48 ( & V_153 . V_162 ) ||
! F_48 ( & V_153 . V_161 ) ) {
F_47 ( & V_26 -> V_31 -> V_32 ,
L_26
L_27 ,
V_179 ) ;
return 0 ;
}
V_142 = F_40 ( V_26 , V_142 ,
V_153 . V_162 . V_163 , V_153 . V_161 . V_163 ,
0 ) ;
F_42 ( V_26 , & V_153 , V_164 ++ ,
0 , V_142 , 0 ) ;
break;
}
if ( V_153 . V_170 < V_155 -> V_163 )
V_172 = V_153 . V_170 ;
else if ( ! F_48 ( V_155 ) ) {
V_172 = V_155 -> V_163 -
( V_155 -> V_168 & ( V_155 -> V_163 - 1 ) ) ;
if ( ( V_153 . V_170 - V_172 ) < V_155 -> V_163 )
V_172 = V_153 . V_170 ;
}
if ( V_172 ) {
F_11 ( & V_26 -> V_31 -> V_32 ,
L_28 ,
V_179 , V_153 . V_170 ) ;
F_43 ( V_26 , & V_153 , & V_142 , V_172 ,
V_164 ++ , & V_171 ) ;
}
if ( V_153 . V_170 ) {
if ( ! F_48 ( V_156 ) ) {
F_32 ( & V_26 -> V_31 -> V_32 ,
L_29 ,
V_179 ) ;
V_156 -> V_163 = 1 ;
}
V_173 = V_153 . V_162 . V_163 *
V_26 -> V_8 -> V_192 ;
F_11 ( & V_26 -> V_31 -> V_32 ,
L_30 ,
V_179 , V_173 ) ;
while ( V_153 . V_170 > ( V_155 -> V_163 - 1 ) ) {
T_3 V_193 , V_148 , V_194 ;
V_193 = F_49 ( V_153 . V_170 , V_173 ) ;
V_194 = F_50 ( V_155 -> V_163 , V_156 -> V_163 ) ;
V_193 = ( V_193 / V_194 ) * V_194 ;
V_148 = V_193 / V_153 . V_162 . V_163 ;
F_11 ( & V_26 -> V_31 -> V_32 ,
L_31
L_32 ,
V_179 , V_193 , V_153 . V_170 ) ;
V_142 = F_40 ( V_26 , V_142 ,
V_153 . V_162 . V_163 , V_153 . V_161 . V_163 ,
V_148 ) ;
F_42 ( V_26 , & V_153 , V_164 ++ ,
V_193 , V_142 , V_148 ) ;
V_171 += V_193 ;
}
if ( V_153 . V_170 ) {
F_11 ( & V_26 -> V_31 -> V_32 ,
L_33 ,
V_179 , V_153 . V_170 ) ;
F_43 ( V_26 , & V_153 , & V_142 ,
V_153 . V_170 , V_164 ++ , & V_171 ) ;
}
}
if ( V_171 != V_176 -> V_165 ) {
F_47 ( & V_26 -> V_31 -> V_32 ,
L_34 ,
V_179 , V_171 , V_176 -> V_165 ) ;
return 0 ;
}
if ( V_164 >= V_123 ) {
F_47 ( & V_26 -> V_31 -> V_32 ,
L_35 ,
V_179 , V_123 ) ;
return 0 ;
}
}
V_93 = V_90 -> V_93 ;
V_174 = V_93 + ( V_164 - 1 ) * V_26 -> V_122 ;
if ( V_90 -> V_195 ) {
V_174 [ V_35 ] = V_90 -> V_118 | V_153 . V_169 ;
} else {
V_174 [ V_35 ] = 0 ;
if ( V_26 -> V_8 -> V_41 )
V_174 [ V_36 ] &= ~ V_46 ;
else
V_174 [ V_36 ] |= V_196 ;
}
F_44 ( V_26 , V_93 , V_164 ) ;
return V_164 ;
}
static void F_51 ( struct V_25 * V_26 ,
struct V_5 * V_90 )
{
struct V_175 * V_176 , * V_197 ;
if ( V_90 -> V_93 )
F_52 ( V_26 -> V_177 , V_90 -> V_93 , V_90 -> V_118 ) ;
F_53 (dsg, _dsg, &txd->dsg_list, node) {
F_16 ( & V_176 -> V_91 ) ;
F_54 ( V_176 ) ;
}
F_54 ( V_90 ) ;
}
static void F_55 ( struct V_89 * V_8 )
{
struct V_5 * V_90 = F_3 ( & V_8 -> V_7 ) ;
struct V_1 * V_9 = F_1 ( V_8 -> V_7 . V_3 ) ;
F_56 ( & V_8 -> V_7 ) ;
if ( ! V_90 -> V_198 )
F_5 ( V_9 ) ;
F_51 ( V_9 -> V_12 , V_90 ) ;
}
static void F_57 ( struct V_25 * V_26 ,
struct V_1 * V_9 )
{
F_58 ( V_199 ) ;
F_59 ( & V_9 -> V_4 , & V_199 ) ;
F_60 ( & V_9 -> V_4 , & V_199 ) ;
}
static void F_61 ( struct V_2 * V_3 )
{
F_62 ( F_63 ( V_3 ) ) ;
}
static struct V_6 * F_64 (
struct V_2 * V_3 , unsigned long V_125 )
{
struct V_6 * V_200 = NULL ;
return V_200 ;
}
static enum V_201 F_65 ( struct V_2 * V_3 ,
T_5 V_202 , struct V_203 * V_204 )
{
struct V_1 * V_9 = F_1 ( V_3 ) ;
struct V_89 * V_8 ;
unsigned long V_125 ;
enum V_201 V_13 ;
T_3 V_108 = 0 ;
V_13 = F_66 ( V_3 , V_202 , V_204 ) ;
if ( V_13 == V_205 )
return V_13 ;
if ( ! V_204 ) {
if ( V_9 -> V_133 == V_206 )
V_13 = V_207 ;
return V_13 ;
}
F_28 ( & V_9 -> V_4 . V_129 , V_125 ) ;
V_13 = F_66 ( V_3 , V_202 , V_204 ) ;
if ( V_13 != V_205 ) {
V_8 = F_67 ( & V_9 -> V_4 , V_202 ) ;
if ( V_8 ) {
struct V_5 * V_90 = F_3 ( & V_8 -> V_7 ) ;
struct V_175 * V_176 ;
F_35 (dsg, &txd->dsg_list, node)
V_108 += V_176 -> V_165 ;
} else {
V_108 = F_25 ( V_9 ) ;
}
}
F_29 ( & V_9 -> V_4 . V_129 , V_125 ) ;
F_68 ( V_204 , V_108 ) ;
if ( V_9 -> V_133 == V_206 && V_13 == V_208 )
V_13 = V_207 ;
return V_13 ;
}
static T_1 F_69 ( bool V_41 , T_4 V_209 , T_4 V_210 )
{
T_1 V_142 = 0 ;
T_1 V_211 ;
T_1 V_212 ;
if ( V_41 ) {
V_211 = V_62 ;
V_212 = V_60 ;
} else {
V_211 = V_213 ;
V_212 = V_214 ;
}
if ( ! ( V_210 & V_215 ) || ( ( V_210 & V_181 ) && ( V_209 & V_215 ) ) )
V_142 |= V_211 ;
if ( ! ( V_209 & V_215 ) || ( ( V_209 & V_181 ) && ! ( V_210 & V_181 ) ) )
V_142 |= V_212 ;
return V_142 ;
}
static T_1 F_70 ( T_1 V_142 )
{
V_142 &= ~ ( V_214 | V_213 |
V_160 | V_159 |
V_216 ) ;
return V_142 | V_217 ;
}
static T_1 F_71 ( enum V_218 V_194 )
{
switch ( V_194 ) {
case V_219 :
return V_114 ;
case V_220 :
return V_115 ;
case V_221 :
return V_116 ;
default:
return ~ 0 ;
}
}
static T_1 F_72 ( T_1 V_222 )
{
int V_126 ;
for ( V_126 = 0 ; V_126 < F_73 ( V_223 ) ; V_126 ++ )
if ( V_223 [ V_126 ] . V_224 <= V_222 )
break;
return V_223 [ V_126 ] . V_225 ;
}
static T_1 F_74 ( struct V_1 * V_9 ,
enum V_218 V_226 , T_1 V_222 )
{
T_1 V_194 , V_227 , V_142 = 0 ;
V_194 = F_71 ( V_226 ) ;
if ( V_194 == ~ 0 )
return ~ 0 ;
V_142 |= V_194 << V_112 ;
V_142 |= V_194 << V_145 ;
if ( V_9 -> V_16 -> V_228 )
V_222 = 1 ;
V_227 = F_72 ( V_222 ) ;
V_142 |= V_227 << V_229 ;
V_142 |= V_227 << V_230 ;
return F_70 ( V_142 ) ;
}
static void F_75 ( struct V_2 * V_3 )
{
struct V_1 * V_9 = F_1 ( V_3 ) ;
unsigned long V_125 ;
F_28 ( & V_9 -> V_4 . V_129 , V_125 ) ;
if ( F_76 ( & V_9 -> V_4 ) ) {
if ( ! V_9 -> V_27 && V_9 -> V_133 != V_134 )
F_31 ( V_9 ) ;
}
F_29 ( & V_9 -> V_4 . V_129 , V_125 ) ;
}
static struct V_5 * F_77 ( struct V_1 * V_9 )
{
struct V_5 * V_90 = F_78 ( sizeof( * V_90 ) , V_178 ) ;
if ( V_90 )
F_79 ( & V_90 -> V_231 ) ;
return V_90 ;
}
static T_1 F_80 ( struct V_25 * V_26 )
{
T_1 V_142 = 0 ;
switch ( V_26 -> V_11 -> V_64 ) {
default:
F_47 ( & V_26 -> V_31 -> V_32 ,
L_36 ) ;
case V_65 :
V_142 |= V_66 << V_229 |
V_66 << V_230 ;
break;
case V_68 :
V_142 |= V_69 << V_229 |
V_69 << V_230 ;
break;
case V_70 :
V_142 |= V_71 << V_229 |
V_71 << V_230 ;
break;
case V_72 :
V_142 |= V_73 << V_229 |
V_73 << V_230 ;
break;
case V_74 :
V_142 |= V_75 << V_229 |
V_75 << V_230 ;
break;
case V_76 :
V_142 |= V_77 << V_229 |
V_77 << V_230 ;
break;
case V_78 :
V_142 |= V_79 << V_229 |
V_79 << V_230 ;
break;
case V_80 :
V_142 |= V_81 << V_229 |
V_81 << V_230 ;
break;
}
switch ( V_26 -> V_11 -> V_232 ) {
default:
F_47 ( & V_26 -> V_31 -> V_32 ,
L_37 ) ;
case V_233 :
V_142 |= V_114 << V_112 |
V_114 << V_145 ;
break;
case V_234 :
V_142 |= V_115 << V_112 |
V_115 << V_145 ;
break;
case V_235 :
V_142 |= V_116 << V_112 |
V_116 << V_145 ;
break;
}
if ( V_26 -> V_11 -> V_82 )
V_142 |= V_236 ;
if ( V_26 -> V_11 -> V_84 )
V_142 |= V_237 ;
V_142 |= V_217 ;
V_142 |= V_160 | V_159 ;
if ( V_26 -> V_8 -> V_238 )
V_142 |= F_69 ( false ,
V_26 -> V_239 ,
V_26 -> V_239 ) ;
return V_142 ;
}
static T_1 F_81 ( struct V_25 * V_26 )
{
T_1 V_142 = 0 ;
switch ( V_26 -> V_11 -> V_232 ) {
default:
F_47 ( & V_26 -> V_31 -> V_32 ,
L_37 ) ;
case V_233 :
V_142 |= V_114 << V_49 |
V_114 << V_52 ;
break;
case V_234 :
V_142 |= V_115 << V_49 |
V_115 << V_52 ;
break;
case V_235 :
V_142 |= V_116 << V_49 |
V_116 << V_52 ;
break;
}
V_142 |= V_46 ;
if ( V_26 -> V_8 -> V_238 )
V_142 |= F_69 ( true ,
V_26 -> V_239 ,
V_26 -> V_239 ) ;
return V_142 ;
}
static struct V_6 * F_82 (
struct V_2 * V_3 , T_2 V_240 , T_2 V_209 ,
T_3 V_165 , unsigned long V_125 )
{
struct V_1 * V_9 = F_1 ( V_3 ) ;
struct V_25 * V_26 = V_9 -> V_12 ;
struct V_5 * V_90 ;
struct V_175 * V_176 ;
int V_13 ;
V_90 = F_77 ( V_9 ) ;
if ( ! V_90 ) {
F_47 ( & V_26 -> V_31 -> V_32 ,
L_38 , V_179 ) ;
return NULL ;
}
V_176 = F_78 ( sizeof( struct V_175 ) , V_178 ) ;
if ( ! V_176 ) {
F_51 ( V_26 , V_90 ) ;
return NULL ;
}
F_83 ( & V_176 -> V_91 , & V_90 -> V_231 ) ;
V_176 -> V_183 = V_209 ;
V_176 -> V_184 = V_240 ;
V_176 -> V_165 = V_165 ;
if ( V_26 -> V_8 -> V_41 ) {
V_90 -> V_29 = 0 ;
V_90 -> V_142 = F_81 ( V_26 ) ;
} else {
V_90 -> V_29 = V_106 |
V_107 |
V_187 << V_189 ;
V_90 -> V_142 = F_80 ( V_26 ) ;
}
V_13 = F_45 ( V_9 -> V_12 , V_90 ) ;
if ( ! V_13 ) {
F_51 ( V_26 , V_90 ) ;
return NULL ;
}
return F_84 ( & V_9 -> V_4 , & V_90 -> V_8 , V_125 ) ;
}
static struct V_5 * F_85 (
struct V_2 * V_3 ,
enum V_241 V_242 ,
T_2 * V_243 )
{
struct V_1 * V_9 = F_1 ( V_3 ) ;
struct V_25 * V_26 = V_9 -> V_12 ;
struct V_5 * V_90 ;
enum V_218 V_226 ;
int V_13 , V_244 ;
T_4 V_245 , V_246 ;
T_1 V_222 , V_142 ;
V_90 = F_77 ( V_9 ) ;
if ( ! V_90 ) {
F_47 ( & V_26 -> V_31 -> V_32 , L_39 , V_179 ) ;
return NULL ;
}
if ( V_242 == V_247 ) {
V_142 = V_160 ;
* V_243 = V_9 -> V_248 . V_184 ;
V_226 = V_9 -> V_248 . V_249 ;
V_222 = V_9 -> V_248 . V_250 ;
V_245 = V_26 -> V_239 ;
V_246 = V_9 -> V_16 -> V_251 ;
} else if ( V_242 == V_252 ) {
V_142 = V_159 ;
* V_243 = V_9 -> V_248 . V_183 ;
V_226 = V_9 -> V_248 . V_253 ;
V_222 = V_9 -> V_248 . V_254 ;
V_245 = V_9 -> V_16 -> V_251 ;
V_246 = V_26 -> V_239 ;
} else {
F_51 ( V_26 , V_90 ) ;
F_47 ( & V_26 -> V_31 -> V_32 ,
L_40 , V_179 ) ;
return NULL ;
}
V_142 |= F_74 ( V_9 , V_226 , V_222 ) ;
if ( V_142 == ~ 0 ) {
F_51 ( V_26 , V_90 ) ;
F_47 ( & V_26 -> V_31 -> V_32 ,
L_41 ) ;
return NULL ;
}
V_90 -> V_142 = V_142 | F_69 ( false , V_245 , V_246 ) ;
if ( V_9 -> V_248 . V_255 )
V_244 = ( V_242 == V_247 ) ? V_256 :
V_257 ;
else
V_244 = ( V_242 == V_247 ) ? V_258 :
V_259 ;
V_90 -> V_29 = V_106 |
V_107 |
V_244 << V_189 ;
V_13 = F_4 ( V_9 ) ;
if ( V_13 < 0 ) {
F_51 ( V_26 , V_90 ) ;
F_32 ( & V_26 -> V_31 -> V_32 ,
L_42 ,
V_9 -> V_132 ) ;
return NULL ;
}
F_32 ( & V_26 -> V_31 -> V_32 , L_43 ,
V_9 -> signal , V_9 -> V_132 ) ;
if ( V_242 == V_247 )
V_90 -> V_29 |= V_9 -> signal << V_260 ;
else
V_90 -> V_29 |= V_9 -> signal << V_261 ;
return V_90 ;
}
static int F_86 ( struct V_5 * V_90 ,
enum V_241 V_242 ,
T_2 V_243 ,
T_2 V_262 ,
unsigned int V_165 )
{
struct V_175 * V_176 ;
V_176 = F_78 ( sizeof( struct V_175 ) , V_178 ) ;
if ( ! V_176 )
return - V_263 ;
F_83 ( & V_176 -> V_91 , & V_90 -> V_231 ) ;
V_176 -> V_165 = V_165 ;
if ( V_242 == V_247 ) {
V_176 -> V_183 = V_262 ;
V_176 -> V_184 = V_243 ;
} else {
V_176 -> V_183 = V_243 ;
V_176 -> V_184 = V_262 ;
}
return 0 ;
}
static struct V_6 * F_87 (
struct V_2 * V_3 , struct V_264 * V_265 ,
unsigned int V_266 , enum V_241 V_242 ,
unsigned long V_125 , void * V_267 )
{
struct V_1 * V_9 = F_1 ( V_3 ) ;
struct V_25 * V_26 = V_9 -> V_12 ;
struct V_5 * V_90 ;
struct V_264 * V_268 ;
int V_13 , V_244 ;
T_2 V_243 ;
F_32 ( & V_26 -> V_31 -> V_32 , L_44 ,
V_179 , F_88 ( V_265 ) , V_9 -> V_132 ) ;
V_90 = F_85 ( V_3 , V_242 , & V_243 ) ;
if ( ! V_90 )
return NULL ;
F_89 (sgl, sg, sg_len, tmp) {
V_13 = F_86 ( V_90 , V_242 , V_243 ,
F_90 ( V_268 ) ,
F_88 ( V_268 ) ) ;
if ( V_13 ) {
F_5 ( V_9 ) ;
F_51 ( V_26 , V_90 ) ;
F_47 ( & V_26 -> V_31 -> V_32 , L_45 ,
V_179 ) ;
return NULL ;
}
}
V_13 = F_45 ( V_9 -> V_12 , V_90 ) ;
if ( ! V_13 ) {
F_5 ( V_9 ) ;
F_51 ( V_26 , V_90 ) ;
return NULL ;
}
return F_84 ( & V_9 -> V_4 , & V_90 -> V_8 , V_125 ) ;
}
static struct V_6 * F_91 (
struct V_2 * V_3 , T_2 V_262 , T_3 V_269 ,
T_3 V_270 , enum V_241 V_242 ,
unsigned long V_125 )
{
struct V_1 * V_9 = F_1 ( V_3 ) ;
struct V_25 * V_26 = V_9 -> V_12 ;
struct V_5 * V_90 ;
int V_13 , V_244 ;
T_2 V_243 ;
F_32 ( & V_26 -> V_31 -> V_32 ,
L_46 ,
V_179 , V_270 , V_269 ,
V_242 == V_247 ? L_47 : L_48 ,
V_9 -> V_132 ) ;
V_90 = F_85 ( V_3 , V_242 , & V_243 ) ;
if ( ! V_90 )
return NULL ;
V_90 -> V_195 = true ;
V_90 -> V_142 |= V_196 ;
for ( V_244 = 0 ; V_244 < V_269 ; V_244 += V_270 ) {
V_13 = F_86 ( V_90 , V_242 , V_243 ,
V_262 + V_244 , V_270 ) ;
if ( V_13 ) {
F_5 ( V_9 ) ;
F_51 ( V_26 , V_90 ) ;
return NULL ;
}
}
V_13 = F_45 ( V_9 -> V_12 , V_90 ) ;
if ( ! V_13 ) {
F_5 ( V_9 ) ;
F_51 ( V_26 , V_90 ) ;
return NULL ;
}
return F_84 ( & V_9 -> V_4 , & V_90 -> V_8 , V_125 ) ;
}
static int F_92 ( struct V_2 * V_3 ,
struct V_271 * V_272 )
{
struct V_1 * V_9 = F_1 ( V_3 ) ;
struct V_25 * V_26 = V_9 -> V_12 ;
if ( ! V_9 -> V_273 )
return - V_274 ;
if ( V_272 -> V_253 == V_275 ||
V_272 -> V_249 == V_275 )
return - V_274 ;
if ( V_272 -> V_255 && V_26 -> V_8 -> V_30 ) {
F_47 ( & V_26 -> V_31 -> V_32 ,
L_49 ,
V_179 ) ;
return - V_274 ;
}
V_9 -> V_248 = * V_272 ;
return 0 ;
}
static int F_93 ( struct V_2 * V_3 )
{
struct V_1 * V_9 = F_1 ( V_3 ) ;
struct V_25 * V_26 = V_9 -> V_12 ;
unsigned long V_125 ;
F_28 ( & V_9 -> V_4 . V_129 , V_125 ) ;
if ( ! V_9 -> V_27 && ! V_9 -> V_92 ) {
F_29 ( & V_9 -> V_4 . V_129 , V_125 ) ;
return 0 ;
}
V_9 -> V_133 = V_141 ;
if ( V_9 -> V_27 ) {
F_34 ( V_9 ) ;
}
if ( V_9 -> V_92 ) {
F_55 ( & V_9 -> V_92 -> V_8 ) ;
V_9 -> V_92 = NULL ;
}
F_57 ( V_26 , V_9 ) ;
F_29 ( & V_9 -> V_4 . V_129 , V_125 ) ;
return 0 ;
}
static int F_94 ( struct V_2 * V_3 )
{
struct V_1 * V_9 = F_1 ( V_3 ) ;
unsigned long V_125 ;
F_28 ( & V_9 -> V_4 . V_129 , V_125 ) ;
if ( ! V_9 -> V_27 && ! V_9 -> V_92 ) {
F_29 ( & V_9 -> V_4 . V_129 , V_125 ) ;
return 0 ;
}
F_18 ( V_9 -> V_27 ) ;
V_9 -> V_133 = V_206 ;
F_29 ( & V_9 -> V_4 . V_129 , V_125 ) ;
return 0 ;
}
static int F_95 ( struct V_2 * V_3 )
{
struct V_1 * V_9 = F_1 ( V_3 ) ;
unsigned long V_125 ;
F_28 ( & V_9 -> V_4 . V_129 , V_125 ) ;
if ( ! V_9 -> V_27 && ! V_9 -> V_92 ) {
F_29 ( & V_9 -> V_4 . V_129 , V_125 ) ;
return 0 ;
}
F_21 ( V_9 -> V_27 ) ;
V_9 -> V_133 = V_135 ;
F_29 ( & V_9 -> V_4 . V_129 , V_125 ) ;
return 0 ;
}
bool F_96 ( struct V_2 * V_3 , void * V_276 )
{
struct V_1 * V_9 ;
char * V_132 = V_276 ;
if ( V_3 -> V_277 -> V_32 -> V_278 != & V_279 . V_280 )
return false ;
V_9 = F_1 ( V_3 ) ;
if ( ! strcmp ( V_9 -> V_132 , V_132 ) )
return true ;
return false ;
}
static bool F_97 ( struct V_2 * V_3 , void * V_276 )
{
struct V_1 * V_9 = F_1 ( V_3 ) ;
return V_9 -> V_16 == V_276 ;
}
static void F_98 ( struct V_25 * V_26 )
{
if ( V_26 -> V_8 -> V_281 )
return;
if ( V_26 -> V_8 -> V_41 ) {
F_13 ( V_97 , V_26 -> V_44 + V_282 ) ;
return;
}
F_13 ( V_97 , V_26 -> V_44 + V_283 ) ;
}
static T_6 F_99 ( int V_284 , void * V_32 )
{
struct V_25 * V_26 = V_32 ;
T_1 V_285 = 0 , V_286 , V_287 , V_126 ;
V_286 = F_8 ( V_26 -> V_44 + V_288 ) ;
if ( V_286 ) {
F_47 ( & V_26 -> V_31 -> V_32 , L_50 ,
V_179 , V_286 ) ;
F_13 ( V_286 , V_26 -> V_44 + V_104 ) ;
}
V_287 = F_8 ( V_26 -> V_44 + V_289 ) ;
if ( V_287 )
F_13 ( V_287 , V_26 -> V_44 + V_105 ) ;
if ( ! V_286 && ! V_287 )
return V_290 ;
for ( V_126 = 0 ; V_126 < V_26 -> V_8 -> V_127 ; V_126 ++ ) {
if ( ( F_9 ( V_126 ) & V_286 ) || ( F_9 ( V_126 ) & V_287 ) ) {
struct V_18 * V_27 = & V_26 -> V_128 [ V_126 ] ;
struct V_1 * V_9 = V_27 -> V_131 ;
struct V_5 * V_7 ;
if ( ! V_9 ) {
F_47 ( & V_26 -> V_31 -> V_32 ,
L_51 ,
V_179 , V_126 ) ;
continue;
}
F_36 ( & V_9 -> V_4 . V_129 ) ;
V_7 = V_9 -> V_92 ;
if ( V_7 && V_7 -> V_195 ) {
F_100 ( & V_7 -> V_8 ) ;
} else if ( V_7 ) {
V_9 -> V_92 = NULL ;
F_5 ( V_9 ) ;
V_7 -> V_198 = true ;
F_101 ( & V_7 -> V_8 ) ;
if ( F_15 ( & V_9 -> V_4 ) )
F_14 ( V_9 ) ;
else
F_34 ( V_9 ) ;
}
F_37 ( & V_9 -> V_4 . V_129 ) ;
V_285 |= F_9 ( V_126 ) ;
}
}
return V_285 ? V_291 : V_290 ;
}
static void F_102 ( struct V_1 * V_3 )
{
V_3 -> V_273 = true ;
V_3 -> V_132 = V_3 -> V_16 -> V_292 ;
V_3 -> V_248 . V_183 = V_3 -> V_16 -> V_168 ;
V_3 -> V_248 . V_184 = V_3 -> V_16 -> V_168 ;
}
static int F_103 ( struct V_25 * V_26 ,
struct V_293 * V_294 , unsigned int V_127 , bool V_273 )
{
struct V_1 * V_3 ;
int V_126 ;
F_79 ( & V_294 -> V_127 ) ;
for ( V_126 = 0 ; V_126 < V_127 ; V_126 ++ ) {
V_3 = F_78 ( sizeof( * V_3 ) , V_295 ) ;
if ( ! V_3 )
return - V_263 ;
V_3 -> V_12 = V_26 ;
V_3 -> V_133 = V_141 ;
V_3 -> signal = - 1 ;
if ( V_273 ) {
V_3 -> V_16 = & V_26 -> V_11 -> V_296 [ V_126 ] ;
V_3 -> signal = V_126 ;
F_102 ( V_3 ) ;
} else {
V_3 -> V_16 = F_78 ( sizeof( * V_3 -> V_16 ) , V_295 ) ;
if ( ! V_3 -> V_16 ) {
F_54 ( V_3 ) ;
return - V_263 ;
}
V_3 -> V_16 -> V_292 = L_52 ;
V_3 -> V_16 -> V_251 = V_26 -> V_11 -> V_239 ;
V_3 -> V_132 = F_104 ( V_295 , L_53 , V_126 ) ;
if ( ! V_3 -> V_132 ) {
F_54 ( V_3 -> V_16 ) ;
F_54 ( V_3 ) ;
return - V_263 ;
}
}
F_32 ( & V_26 -> V_31 -> V_32 ,
L_54 ,
V_3 -> V_132 ) ;
V_3 -> V_4 . V_297 = F_55 ;
F_105 ( & V_3 -> V_4 , V_294 ) ;
}
F_106 ( & V_26 -> V_31 -> V_32 , L_55 ,
V_126 , V_273 ? L_56 : L_52 ) ;
return V_126 ;
}
static void F_107 ( struct V_293 * V_294 )
{
struct V_1 * V_3 = NULL ;
struct V_1 * V_137 ;
F_53 (chan,
next, &dmadev->channels, vc.chan.device_node) {
F_16 ( & V_3 -> V_4 . V_3 . V_298 ) ;
F_54 ( V_3 ) ;
}
}
static const char * F_108 ( enum V_299 V_133 )
{
switch ( V_133 ) {
case V_141 :
return L_57 ;
case V_135 :
return L_58 ;
case V_206 :
return L_59 ;
case V_134 :
return L_60 ;
default:
break;
}
return L_61 ;
}
static int F_109 ( struct V_300 * V_301 , void * V_302 )
{
struct V_25 * V_26 = V_301 -> V_303 ;
struct V_1 * V_3 ;
struct V_18 * V_19 ;
unsigned long V_125 ;
int V_126 ;
F_110 ( V_301 , L_62 ) ;
F_110 ( V_301 , L_63 ) ;
F_110 ( V_301 , L_64 ) ;
for ( V_126 = 0 ; V_126 < V_26 -> V_8 -> V_127 ; V_126 ++ ) {
struct V_1 * V_124 ;
V_19 = & V_26 -> V_128 [ V_126 ] ;
F_28 ( & V_19 -> V_129 , V_125 ) ;
V_124 = V_19 -> V_131 ;
F_110 ( V_301 , L_65 ,
V_19 -> V_22 ,
V_124 ? V_124 -> V_132 : L_66 ,
V_19 -> V_130 ? L_67 : L_10 ) ;
F_29 ( & V_19 -> V_129 , V_125 ) ;
}
F_110 ( V_301 , L_68 ) ;
F_110 ( V_301 , L_69 ) ;
F_110 ( V_301 , L_70 ) ;
F_35 (chan, &pl08x->memcpy.channels, vc.chan.device_node) {
F_110 ( V_301 , L_71 , V_3 -> V_132 ,
F_108 ( V_3 -> V_133 ) ) ;
}
if ( V_26 -> V_139 ) {
F_110 ( V_301 , L_72 ) ;
F_110 ( V_301 , L_69 ) ;
F_110 ( V_301 , L_70 ) ;
F_35 (chan, &pl08x->slave.channels,
vc.chan.device_node) {
F_110 ( V_301 , L_71 , V_3 -> V_132 ,
F_108 ( V_3 -> V_133 ) ) ;
}
}
return 0 ;
}
static int F_111 ( struct V_304 * V_304 , struct V_305 * V_305 )
{
return F_112 ( V_305 , F_109 , V_304 -> V_306 ) ;
}
static void F_113 ( struct V_25 * V_26 )
{
( void ) F_114 ( F_115 ( & V_26 -> V_31 -> V_32 ) ,
V_307 | V_308 , NULL , V_26 ,
& V_309 ) ;
}
static inline void F_113 ( struct V_25 * V_26 )
{
}
static struct V_2 * F_116 ( struct V_25 * V_26 ,
T_1 V_22 )
{
struct V_1 * V_3 ;
if ( ! V_26 -> V_139 )
return NULL ;
F_35 (chan, &pl08x->slave.channels, vc.chan.device_node) {
if ( V_3 -> signal == V_22 )
return & V_3 -> V_4 . V_3 ;
}
return NULL ;
}
static struct V_2 * F_117 ( struct V_310 * V_311 ,
struct V_312 * V_313 )
{
struct V_25 * V_26 = V_313 -> V_314 ;
struct V_2 * V_2 ;
struct V_1 * V_9 ;
if ( ! V_26 )
return NULL ;
if ( V_311 -> V_315 != 2 ) {
F_47 ( & V_26 -> V_31 -> V_32 ,
L_73 ) ;
return NULL ;
}
V_2 = F_116 ( V_26 , V_311 -> args [ 0 ] ) ;
if ( ! V_2 ) {
F_47 ( & V_26 -> V_31 -> V_32 ,
L_74 ) ;
return NULL ;
}
V_9 = F_1 ( V_2 ) ;
F_32 ( & V_26 -> V_31 -> V_32 ,
L_75 ,
V_311 -> args [ 0 ] ) ;
V_9 -> V_16 -> V_251 = V_311 -> args [ 1 ] ;
return F_118 ( V_2 ) ;
}
static int F_119 ( struct V_316 * V_31 ,
struct V_25 * V_26 ,
struct V_298 * V_317 )
{
struct V_10 * V_11 ;
struct V_318 * V_319 = NULL ;
T_1 V_20 ;
int V_13 ;
int V_126 ;
V_11 = F_120 ( & V_31 -> V_32 , sizeof( * V_11 ) , V_295 ) ;
if ( ! V_11 )
return - V_263 ;
if ( F_121 ( V_317 , L_76 ) )
V_11 -> V_180 |= V_215 ;
if ( F_121 ( V_317 , L_77 ) )
V_11 -> V_180 |= V_181 ;
if ( ! V_11 -> V_180 ) {
F_106 ( & V_31 -> V_32 , L_78 ) ;
V_11 -> V_180 |= V_215 | V_181 ;
}
if ( F_121 ( V_317 , L_79 ) )
V_11 -> V_239 |= V_215 ;
if ( F_121 ( V_317 , L_80 ) )
V_11 -> V_239 |= V_181 ;
if ( ! V_11 -> V_239 ) {
F_106 ( & V_31 -> V_32 , L_81 ) ;
V_11 -> V_239 |= V_215 | V_181 ;
}
V_13 = F_122 ( V_317 , L_82 , & V_20 ) ;
if ( V_13 ) {
F_106 ( & V_31 -> V_32 , L_83 ) ;
V_20 = 1 ;
}
switch ( V_20 ) {
default:
F_47 ( & V_31 -> V_32 , L_36 ) ;
case 1 :
V_11 -> V_64 = V_65 ;
break;
case 4 :
V_11 -> V_64 = V_68 ;
break;
case 8 :
V_11 -> V_64 = V_70 ;
break;
case 16 :
V_11 -> V_64 = V_72 ;
break;
case 32 :
V_11 -> V_64 = V_74 ;
break;
case 64 :
V_11 -> V_64 = V_76 ;
break;
case 128 :
V_11 -> V_64 = V_78 ;
break;
case 256 :
V_11 -> V_64 = V_80 ;
break;
}
V_13 = F_122 ( V_317 , L_84 , & V_20 ) ;
if ( V_13 ) {
F_106 ( & V_31 -> V_32 , L_85 ) ;
V_20 = 8 ;
}
switch ( V_20 ) {
default:
F_47 ( & V_31 -> V_32 , L_37 ) ;
case 8 :
V_11 -> V_232 = V_233 ;
break;
case 16 :
V_11 -> V_232 = V_234 ;
break;
case 32 :
V_11 -> V_232 = V_235 ;
break;
}
if ( V_26 -> V_8 -> V_320 ) {
V_319 = F_123 ( & V_31 -> V_32 ,
V_26 -> V_8 -> V_320 ,
sizeof( struct V_318 ) ,
V_295 ) ;
if ( ! V_319 )
return - V_263 ;
V_11 -> V_296 = V_319 ;
for ( V_126 = 0 ; V_126 < V_26 -> V_8 -> V_320 ; V_126 ++ ) {
V_319 -> V_292 = F_104 ( V_295 , L_86 , V_126 ) ;
V_319 ++ ;
}
V_11 -> V_321 = V_26 -> V_8 -> V_320 ;
}
V_26 -> V_11 = V_11 ;
return F_124 ( V_31 -> V_32 . V_322 , F_117 ,
V_26 ) ;
}
static inline int F_119 ( struct V_316 * V_31 ,
struct V_25 * V_26 ,
struct V_298 * V_317 )
{
return - V_274 ;
}
static int F_125 ( struct V_316 * V_31 , const struct V_323 * V_22 )
{
struct V_25 * V_26 ;
struct V_324 * V_8 = V_22 -> V_302 ;
struct V_298 * V_317 = V_31 -> V_32 . V_322 ;
T_1 V_325 ;
int V_13 = 0 ;
int V_126 ;
V_13 = F_126 ( V_31 , NULL ) ;
if ( V_13 )
return V_13 ;
V_13 = F_127 ( & V_31 -> V_32 , F_128 ( 32 ) ) ;
if ( V_13 )
goto V_326;
V_26 = F_78 ( sizeof( * V_26 ) , V_295 ) ;
if ( ! V_26 ) {
V_13 = - V_263 ;
goto V_326;
}
V_26 -> V_31 = V_31 ;
V_26 -> V_8 = V_8 ;
V_26 -> V_44 = F_129 ( V_31 -> V_327 . V_328 , F_130 ( & V_31 -> V_327 ) ) ;
if ( ! V_26 -> V_44 ) {
V_13 = - V_263 ;
goto V_329;
}
if ( V_8 -> V_41 ) {
T_1 V_20 ;
V_20 = F_8 ( V_26 -> V_44 + V_330 ) ;
F_106 ( & V_26 -> V_31 -> V_32 , L_87 ,
( V_20 >> 16 ) & 0xff , ( V_20 >> 8 ) & 0xff , V_20 & 0xff ) ;
V_20 = F_8 ( V_26 -> V_44 + V_331 ) ;
F_106 ( & V_26 -> V_31 -> V_32 , L_88
L_89 ,
( V_20 >> 12 ) & 0x0f ,
( V_20 & F_9 ( 10 ) ) ? L_90 : L_91 ,
( V_20 & F_9 ( 9 ) ) ? L_92 : L_93 ,
( V_20 & F_9 ( 8 ) ) ? L_94 : L_95 ) ;
if ( ! ( V_20 & F_9 ( 8 ) ) )
F_131 ( & V_26 -> V_31 -> V_32 ,
L_96 ) ;
V_8 -> V_127 = ( V_20 >> 12 ) & 0x0f ;
V_8 -> V_238 = ! ! ( V_20 & F_9 ( 9 ) ) ;
}
F_132 ( V_332 , V_26 -> memcpy . V_333 ) ;
V_26 -> memcpy . V_32 = & V_31 -> V_32 ;
V_26 -> memcpy . V_334 = F_61 ;
V_26 -> memcpy . V_335 = F_82 ;
V_26 -> memcpy . V_336 = F_64 ;
V_26 -> memcpy . V_337 = F_65 ;
V_26 -> memcpy . V_338 = F_75 ;
V_26 -> memcpy . V_339 = F_92 ;
V_26 -> memcpy . V_340 = F_94 ;
V_26 -> memcpy . V_341 = F_95 ;
V_26 -> memcpy . V_342 = F_93 ;
V_26 -> memcpy . V_343 = V_344 ;
V_26 -> memcpy . V_345 = V_344 ;
V_26 -> memcpy . V_346 = F_9 ( V_347 ) ;
V_26 -> memcpy . V_348 = V_349 ;
if ( V_8 -> V_41 )
V_26 -> memcpy . V_350 = V_351 ;
if ( V_8 -> V_320 ) {
V_26 -> V_139 = true ;
F_132 ( V_352 , V_26 -> V_273 . V_333 ) ;
F_132 ( V_353 , V_26 -> V_273 . V_333 ) ;
V_26 -> V_273 . V_32 = & V_31 -> V_32 ;
V_26 -> V_273 . V_334 =
F_61 ;
V_26 -> V_273 . V_336 =
F_64 ;
V_26 -> V_273 . V_337 = F_65 ;
V_26 -> V_273 . V_338 = F_75 ;
V_26 -> V_273 . V_354 = F_87 ;
V_26 -> V_273 . V_355 = F_91 ;
V_26 -> V_273 . V_339 = F_92 ;
V_26 -> V_273 . V_340 = F_94 ;
V_26 -> V_273 . V_341 = F_95 ;
V_26 -> V_273 . V_342 = F_93 ;
V_26 -> V_273 . V_343 = V_344 ;
V_26 -> V_273 . V_345 = V_344 ;
V_26 -> V_273 . V_346 =
F_9 ( V_252 ) | F_9 ( V_247 ) ;
V_26 -> V_273 . V_348 =
V_349 ;
}
V_26 -> V_11 = F_133 ( & V_31 -> V_32 ) ;
if ( ! V_26 -> V_11 ) {
if ( V_317 ) {
V_13 = F_119 ( V_31 , V_26 , V_317 ) ;
if ( V_13 )
goto V_356;
} else {
F_47 ( & V_31 -> V_32 , L_97 ) ;
V_13 = - V_274 ;
goto V_356;
}
} else {
V_26 -> V_273 . V_357 . V_358 = V_26 -> V_11 -> V_359 ;
V_26 -> V_273 . V_357 . V_360 = V_26 -> V_11 -> V_361 ;
V_26 -> V_273 . V_357 . V_362 = F_97 ;
}
V_26 -> V_180 = V_215 ;
V_26 -> V_239 = V_215 ;
if ( V_26 -> V_8 -> V_238 ) {
V_26 -> V_180 = V_26 -> V_11 -> V_180 ;
V_26 -> V_239 = V_26 -> V_11 -> V_239 ;
}
if ( V_8 -> V_30 )
V_26 -> V_122 = V_363 ;
else
V_26 -> V_122 = V_364 ;
V_325 = V_123 * V_26 -> V_122 * sizeof( T_1 ) ;
V_26 -> V_177 = F_134 ( V_365 , & V_26 -> V_31 -> V_32 ,
V_325 , V_366 , 0 ) ;
if ( ! V_26 -> V_177 ) {
V_13 = - V_263 ;
goto V_367;
}
F_98 ( V_26 ) ;
if ( V_8 -> V_41 )
F_13 ( 0x0000FFFF , V_26 -> V_44 + V_104 ) ;
else
F_13 ( 0x000000FF , V_26 -> V_44 + V_104 ) ;
F_13 ( 0x000000FF , V_26 -> V_44 + V_105 ) ;
V_13 = F_135 ( V_31 -> V_284 [ 0 ] , F_99 , 0 , V_365 , V_26 ) ;
if ( V_13 ) {
F_47 ( & V_31 -> V_32 , L_98 ,
V_179 , V_31 -> V_284 [ 0 ] ) ;
goto V_368;
}
V_26 -> V_128 = F_78 ( ( V_8 -> V_127 * sizeof( * V_26 -> V_128 ) ) ,
V_295 ) ;
if ( ! V_26 -> V_128 ) {
V_13 = - V_263 ;
goto V_369;
}
for ( V_126 = 0 ; V_126 < V_8 -> V_127 ; V_126 ++ ) {
struct V_18 * V_19 = & V_26 -> V_128 [ V_126 ] ;
V_19 -> V_22 = V_126 ;
V_19 -> V_44 = V_26 -> V_44 + F_136 ( V_126 ) ;
if ( V_8 -> V_41 ) {
V_19 -> V_21 = V_19 -> V_44 + V_370 ;
V_19 -> V_23 = V_19 -> V_44 + V_371 ;
V_19 -> V_87 = V_19 -> V_44 + V_372 ;
V_19 -> V_38 = V_19 -> V_44 + V_373 ;
V_19 -> V_39 = V_19 -> V_44 + V_374 ;
V_19 -> V_40 = V_19 -> V_44 + V_375 ;
V_19 -> V_41 = true ;
} else {
V_19 -> V_23 = V_19 -> V_44 + V_8 -> V_376 ;
V_19 -> V_87 = V_19 -> V_44 + V_377 ;
V_19 -> V_38 = V_19 -> V_44 + V_378 ;
V_19 -> V_39 = V_19 -> V_44 + V_379 ;
V_19 -> V_40 = V_19 -> V_44 + V_380 ;
}
if ( V_8 -> V_30 )
V_19 -> V_30 = true ;
F_137 ( & V_19 -> V_129 ) ;
if ( V_8 -> V_281 ) {
T_1 V_20 ;
V_20 = F_8 ( V_19 -> V_23 ) ;
if ( V_20 & ( V_381 | V_382 ) ) {
F_106 ( & V_31 -> V_32 , L_99 , V_126 ) ;
V_19 -> V_130 = true ;
}
}
F_32 ( & V_31 -> V_32 , L_100 ,
V_126 , F_7 ( V_19 ) ? L_101 : L_102 ) ;
}
V_13 = F_103 ( V_26 , & V_26 -> memcpy ,
V_26 -> V_8 -> V_127 , false ) ;
if ( V_13 <= 0 ) {
F_131 ( & V_26 -> V_31 -> V_32 ,
L_103 ,
V_179 , V_13 ) ;
goto V_383;
}
if ( V_26 -> V_139 ) {
V_13 = F_103 ( V_26 , & V_26 -> V_273 ,
V_26 -> V_11 -> V_321 , true ) ;
if ( V_13 < 0 ) {
F_131 ( & V_26 -> V_31 -> V_32 ,
L_104 ,
V_179 , V_13 ) ;
goto V_384;
}
}
V_13 = F_138 ( & V_26 -> memcpy ) ;
if ( V_13 ) {
F_131 ( & V_26 -> V_31 -> V_32 ,
L_105 ,
V_179 , V_13 ) ;
goto V_385;
}
if ( V_26 -> V_139 ) {
V_13 = F_138 ( & V_26 -> V_273 ) ;
if ( V_13 ) {
F_131 ( & V_26 -> V_31 -> V_32 ,
L_106 ,
V_179 , V_13 ) ;
goto V_386;
}
}
F_139 ( V_31 , V_26 ) ;
F_113 ( V_26 ) ;
F_106 ( & V_26 -> V_31 -> V_32 , L_107 ,
F_140 ( V_31 ) , V_26 -> V_8 -> V_30 ? L_108 : L_10 , F_141 ( V_31 ) ,
( unsigned long long ) V_31 -> V_327 . V_328 , V_31 -> V_284 [ 0 ] ) ;
return 0 ;
V_386:
F_142 ( & V_26 -> memcpy ) ;
V_385:
if ( V_26 -> V_139 )
F_107 ( & V_26 -> V_273 ) ;
V_384:
F_107 ( & V_26 -> memcpy ) ;
V_383:
F_54 ( V_26 -> V_128 ) ;
V_369:
F_143 ( V_31 -> V_284 [ 0 ] , V_26 ) ;
V_368:
F_144 ( V_26 -> V_177 ) ;
V_367:
V_356:
F_145 ( V_26 -> V_44 ) ;
V_329:
F_54 ( V_26 ) ;
V_326:
F_146 ( V_31 ) ;
return V_13 ;
}
static int T_7 F_147 ( void )
{
int V_200 ;
V_200 = F_148 ( & V_279 ) ;
if ( V_200 )
F_149 (KERN_WARNING DRIVER_NAME
L_109 ,
retval) ;
return V_200 ;
}
