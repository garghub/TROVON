static void F_1 ( struct V_1 * V_2 )
{
F_2 ( V_3 , V_4 ) ;
while ( ! F_3 ( V_3 , V_4 ) )
;
while ( F_4 ( V_5 ) & V_6 )
;
}
static T_1 F_5 ( struct V_1 * V_2 , T_1 V_7 )
{
T_1 V_8 ;
F_6 ( V_9 , V_10 | V_7 ) ;
F_1 ( V_2 ) ;
V_8 = ( T_1 ) F_4 ( V_11 ) ;
return V_8 ;
}
static void F_7 ( struct V_1 * V_2 , T_1 V_7 , T_1 V_12 )
{
F_6 ( V_9 , V_13 | V_7 ) ;
F_6 ( V_11 , V_12 ) ;
F_1 ( V_2 ) ;
}
static void F_8 ( struct V_1 * V_2 , T_1 V_7 , T_1 V_14 ,
T_1 V_12 )
{
F_6 ( V_9 , V_10 | V_7 ) ;
F_1 ( V_2 ) ;
F_6 ( V_9 , V_13 | V_7 ) ;
F_6 ( V_11 , V_12 | ( ( T_1 ) F_4 ( V_11 ) & V_14 ) ) ;
F_1 ( V_2 ) ;
}
static T_2 F_9 ( struct V_1 * V_2 , T_2 V_15 )
{
F_6 ( V_16 , V_15 ) ;
F_2 ( V_3 , V_17 ) ;
while ( ! F_3 ( V_3 , V_17 ) )
;
while ( ( F_4 ( V_16 ) & ( V_18 | V_19 ) ) == V_18 )
;
return F_4 ( V_16 ) & V_19 ;
}
static T_3 F_10 ( struct V_1 * V_2 , T_3 V_7 )
{
T_3 V_20 ;
if ( F_9 ( V_2 , F_11 ( V_21 , V_22 )
| F_12 ( V_23 , V_7 )
| F_13 ( V_24 , 0 ) ) ) {
return 0 ;
}
if ( F_9 ( V_2 , F_11 ( V_21 , V_25 )
| F_12 ( V_23 , 0 )
| F_13 ( V_24 , 0 ) ) ) {
return 0 ;
}
V_20 = ( T_3 ) ( F_4 ( V_16 ) >> 16 ) ;
return V_20 ;
}
static void F_14 ( struct V_1 * V_2 , T_2 V_15 )
{
F_7 ( V_2 , V_26 , V_27 -> V_28 ) ;
* V_27 -> V_29 = V_15 ;
F_2 ( V_30 , V_31 ) ;
F_6 ( V_32 , V_33 ) ;
while ( ( F_4 ( V_30 ) & V_31 ) != 0 )
;
F_15 ( 0 , V_34 | V_35 | V_36 ) ;
while ( ( F_4 ( V_37 ) & V_38 ) == 0 )
;
F_15 ( 0 , V_34 | V_39 | V_40 | V_36 | V_41 ) ;
if ( ( F_4 ( V_42 ) & 0xFF000000 ) != 0 ) {
while ( ( F_4 ( V_42 ) & 0xFF000000 ) != 0 )
;
}
F_15 ( 0 , V_35 | V_36 | V_41 ) ;
while ( ( F_4 ( V_42 ) & 0xFF000000 ) == 0 )
;
}
static void F_16 ( struct V_1 * V_2 , T_1 V_43 , short V_44 )
{
register T_1 V_45 ;
register T_2 V_46 ;
V_45 = 1 << V_43 ;
if ( V_44 < 0 ) {
V_44 = - V_44 ;
V_27 -> V_28 |= V_45 ;
} else
V_27 -> V_28 &= ~ V_45 ;
if ( ( T_1 ) V_44 > 0x1FFF )
V_44 = 0x1FFF ;
V_46 = ( V_43 & 2 ) ? V_47 : V_48 ;
F_15 ( 2 , V_34 | V_49 | V_46 ) ;
F_15 ( 3 , V_34 | V_50 | V_46 ) ;
F_15 ( 4 , V_34 | V_51 | V_52 ) ;
F_15 ( 5 , V_34 | V_39 | V_52 | V_41 ) ;
F_14 ( V_2 , 0x0F000000
| 0x00004000
| ( ( T_2 ) ( V_43 & 1 ) << 15 )
| ( T_2 ) V_44 ) ;
}
static void F_17 ( struct V_1 * V_2 , T_3 V_53 ,
T_3 V_54 )
{
T_2 V_43 ;
V_27 -> V_55 [ V_53 ] = ( T_3 ) V_54 ;
V_43 = ( T_2 ) V_56 [ V_53 ] ;
F_15 ( 2 , V_34 | V_49 | V_52 ) ;
F_15 ( 3 , V_34 | V_50 | V_52 ) ;
F_15 ( 4 , V_34 | V_51 | V_47 ) ;
F_15 ( 5 , V_34 | V_39 | V_47 | V_41 ) ;
F_14 ( V_2 , ( ( T_2 ) V_43 << 8 )
| ( T_2 ) V_54 ) ;
}
static void F_18 ( struct V_1 * V_2 )
{
register T_3 V_57 ;
for ( V_57 = 0 ; V_57 < F_19 ( V_56 ) ; V_57 ++ )
F_17 ( V_2 , V_57 , F_10 ( V_2 , V_58 [ V_57 ] ) ) ;
}
static T_2 F_20 ( struct V_1 * V_2 , struct V_59 * V_60 )
{
register T_2 V_61 ;
V_61 = ( T_2 ) F_5 ( V_2 , V_60 -> V_62 ) ;
V_61 |= ( ( T_2 ) F_5 ( V_2 , V_60 -> V_62 + 2 ) << 16 ) ;
return V_61 ;
}
static void F_21 ( struct V_1 * V_2 , struct V_59 * V_60 ,
T_1 V_61 )
{
F_8 ( V_2 , V_60 -> V_63 ,
( T_1 ) ( ~ ( V_64 | V_65 ) ) ,
( T_1 ) ( V_61 << V_66 ) ) ;
}
static void F_22 ( struct V_1 * V_2 , struct V_59 * V_60 ,
T_2 V_61 )
{
F_7 ( V_2 , ( T_1 ) ( V_60 -> V_62 ) , ( T_1 ) V_61 ) ;
F_7 ( V_2 , ( T_1 ) ( V_60 -> V_62 + 2 ) ,
( T_1 ) ( V_61 >> 16 ) ) ;
}
static unsigned int F_23 ( int V_67 )
{
unsigned int V_68 ;
V_68 = ( V_67 >> 18 ) ;
if ( V_68 & 0x2000 )
V_68 &= 0x1fff ;
else
V_68 += ( 1 << 13 ) ;
return V_68 ;
}
static int F_24 ( struct V_1 * V_2 , unsigned int V_43 )
{
unsigned int V_69 ;
unsigned int V_70 ;
unsigned int V_71 ;
V_69 = V_43 / 16 ;
V_70 = 1 << ( V_43 - ( 16 * V_69 ) ) ;
V_71 = F_5 ( V_2 ,
( (struct V_72 * ) ( V_2 -> V_73 + 2 +
V_69 ) -> V_74 ) -> V_75 ) ;
F_7 ( V_2 ,
( (struct V_72 * ) ( V_2 -> V_73 + 2 +
V_69 ) -> V_74 ) -> V_76 ,
V_70 | V_71 ) ;
V_71 = F_5 ( V_2 ,
( (struct V_72 * ) ( V_2 -> V_73 + 2 +
V_69 ) -> V_74 ) -> V_77 ) ;
F_7 ( V_2 ,
( (struct V_72 * ) ( V_2 -> V_73 + 2 +
V_69 ) -> V_74 ) -> V_78 ,
V_70 | V_71 ) ;
F_7 ( V_2 , V_79 , V_80 ) ;
V_71 = F_5 ( V_2 ,
( (struct V_72 * ) ( V_2 -> V_73 + 2 +
V_69 ) -> V_74 ) -> V_81 ) ;
F_7 ( V_2 ,
( (struct V_72 * ) ( V_2 -> V_73 + 2 +
V_69 ) -> V_74 ) -> V_82 ,
V_70 | V_71 ) ;
return 0 ;
}
static int F_25 ( struct V_1 * V_2 , unsigned int V_69 ,
unsigned int V_14 )
{
F_7 ( V_2 , V_79 , V_83 ) ;
F_7 ( V_2 ,
( (struct V_72 * ) ( V_2 -> V_73 + 2 +
V_69 ) -> V_74 ) -> V_82 , V_14 ) ;
return 0 ;
}
static int F_26 ( struct V_1 * V_2 )
{
unsigned int V_69 ;
F_7 ( V_2 , V_79 , V_83 ) ;
for ( V_69 = 0 ; V_69 < V_84 ; V_69 ++ ) {
F_7 ( V_2 ,
( (struct V_72 * ) ( V_2 -> V_73 + 2 +
V_69 ) -> V_74 ) -> V_82 ,
0xffff ) ;
}
return 0 ;
}
static T_4 F_27 ( int V_85 , void * V_86 )
{
struct V_1 * V_2 = V_86 ;
struct V_87 * V_88 ;
struct V_89 * V_90 ;
struct V_59 * V_60 ;
unsigned long V_91 ;
T_5 * V_92 ;
T_2 V_93 , V_94 ;
int V_57 = 0 ;
short V_68 ;
T_3 V_69 ;
T_1 V_95 ;
if ( V_2 -> V_96 == 0 )
return V_97 ;
F_28 ( & V_2 -> V_98 , V_91 ) ;
V_94 = F_29 ( V_27 -> V_99 + V_100 ) ;
V_93 = F_29 ( V_27 -> V_99 + V_32 ) ;
F_30 ( 0 , V_27 -> V_99 + V_100 ) ;
F_30 ( V_93 , V_27 -> V_99 + V_32 ) ;
switch ( V_93 ) {
case V_101 :
V_88 = V_2 -> V_73 ;
V_90 = & ( V_88 -> V_102 -> V_90 ) ;
V_92 = ( T_5 * ) V_27 -> V_103 . V_104 + 1 ;
for ( V_57 = 0 ; V_57 < ( V_88 -> V_102 -> V_90 . V_105 ) ; V_57 ++ ) {
V_68 = F_23 ( ( int ) * V_92 ) ;
V_92 ++ ;
if ( F_31 ( V_88 , V_68 ) == 0 )
F_32
( L_1 ) ;
}
V_88 -> V_102 -> V_106 |= V_107 ;
if ( ! ( V_27 -> V_108 ) )
V_27 -> V_109 -- ;
if ( V_27 -> V_109 <= 0 ) {
V_27 -> V_110 = 0 ;
F_33 ( V_30 , V_111 ) ;
V_88 -> V_102 -> V_106 |= V_112 ;
V_94 = 0 ;
}
if ( V_27 -> V_110 && V_90 -> V_113 == V_114 )
F_24 ( V_2 , V_90 -> V_115 ) ;
F_34 ( V_2 , V_88 ) ;
break;
case V_116 :
V_88 = V_2 -> V_73 ;
V_90 = & ( V_88 -> V_102 -> V_90 ) ;
for ( V_69 = 0 ; V_69 < V_84 ; V_69 ++ ) {
V_95 = 0 ;
V_95 = F_5 ( V_2 ,
( (struct V_72 * ) ( V_2 ->
V_73 +
2 +
V_69 ) ->
V_74 ) -> V_117 ) ;
if ( V_95 ) {
F_25 ( V_2 , V_69 , V_95 ) ;
if ( V_27 -> V_110 ) {
if ( ( V_95 >> ( V_90 -> V_118 -
( 16 * V_69 ) ) )
== 1 && V_90 -> V_119 == V_114 ) {
F_2 ( V_30 , V_111 ) ;
if ( V_90 -> V_113 ==
V_114 ) {
F_24 ( V_2 ,
V_90 -> V_115 ) ;
}
}
if ( ( V_95 >> ( V_90 -> V_115 -
( 16 * V_69 ) ) )
== 1
&& V_90 -> V_113 ==
V_114 ) {
F_2 ( V_3 , V_120 ) ;
if ( V_90 -> V_121 ==
V_114 ) {
V_27 -> V_122
= V_90 -> V_105 ;
F_24 ( V_2 ,
V_90 -> V_123 ) ;
}
if ( V_90 -> V_121 ==
V_124 ) {
V_60 = & V_125 [ 5 ] ;
V_27 -> V_122
= V_90 -> V_105 ;
V_60 -> V_126 ( V_2 , V_60 ,
V_127 ) ;
}
}
if ( ( V_95 >> ( V_90 -> V_123 -
( 16 * V_69 ) ) )
== 1
&& V_90 -> V_121 == V_114 ) {
F_2 ( V_3 , V_120 ) ;
V_27 -> V_122 -- ;
if ( V_27 -> V_122 >
0 ) {
F_24 ( V_2 ,
V_90 -> V_123 ) ;
}
}
}
break;
}
}
V_95 = F_5 ( V_2 , V_128 ) ;
if ( V_95 & V_129 ) {
V_60 = & V_125 [ 0 ] ;
V_60 -> V_130 ( V_2 , V_60 ) ;
}
if ( V_95 & V_131 ) {
V_60 = & V_125 [ 1 ] ;
V_60 -> V_130 ( V_2 , V_60 ) ;
}
if ( V_95 & V_132 ) {
V_60 = & V_125 [ 2 ] ;
V_60 -> V_130 ( V_2 , V_60 ) ;
}
if ( V_95 & V_133 ) {
V_60 = & V_125 [ 3 ] ;
V_60 -> V_130 ( V_2 , V_60 ) ;
}
if ( V_95 & V_134 ) {
V_60 = & V_125 [ 4 ] ;
V_60 -> V_130 ( V_2 , V_60 ) ;
if ( V_27 -> V_122 > 0 ) {
V_27 -> V_122 -- ;
if ( V_27 -> V_122 == 0 )
V_60 -> V_126 ( V_2 , V_60 , V_135 ) ;
if ( V_90 -> V_121 == V_124 ) {
F_2 ( V_3 , V_120 ) ;
}
}
}
if ( V_95 & V_136 ) {
V_60 = & V_125 [ 5 ] ;
V_60 -> V_130 ( V_2 , V_60 ) ;
if ( V_90 -> V_113 == V_124 ) {
F_2 ( V_3 , V_120 ) ;
}
if ( V_90 -> V_121 == V_124 ) {
V_60 = & V_125 [ 4 ] ;
V_27 -> V_122 = V_90 -> V_105 ;
V_60 -> V_126 ( V_2 , V_60 , V_127 ) ;
}
}
}
F_30 ( V_94 , V_27 -> V_99 + V_100 ) ;
F_35 ( & V_2 -> V_98 , V_91 ) ;
return V_137 ;
}
static void F_36 ( struct V_1 * V_2 , T_3 * V_138 )
{
register T_2 * V_139 ;
T_2 V_140 ;
T_1 V_57 ;
T_1 V_141 ;
T_2 V_142 ;
struct V_89 * V_90 = & ( V_2 -> V_73 -> V_102 -> V_90 ) ;
F_33 ( V_30 , V_111 ) ;
V_139 = ( T_2 * ) V_27 -> V_143 . V_104 ;
F_6 ( V_144 , ( T_2 ) V_27 -> V_143 . V_145 ) ;
if ( V_90 != NULL && V_90 -> V_113 != V_146 ) {
* V_139 ++ = V_147 | V_148 ;
* V_139 ++ = V_149 | V_148 ;
}
* V_139 ++ = V_150 | ( V_9 >> 2 ) ;
* V_139 ++ = V_13 | V_151 ;
* V_139 ++ = V_150 | ( V_11 >> 2 ) ;
* V_139 ++ = V_152 ;
* V_139 ++ = V_149 | V_153 ;
* V_139 ++ = V_154 | V_153 ;
* V_139 ++ = V_147 | V_153 ;
for ( V_27 -> V_155 = 0 ; V_27 -> V_155 < 16 ; V_27 -> V_155 ++ ) {
V_142 =
( * V_138 << 8 ) | ( * V_138 & 0x10 ? V_152 :
V_156 ) ;
* V_139 ++ = V_150 | ( V_9 >> 2 ) ;
* V_139 ++ = V_13 | V_151 ;
* V_139 ++ = V_150 | ( V_11 >> 2 ) ;
* V_139 ++ = V_142 ;
* V_139 ++ = V_149 | V_153 ;
* V_139 ++ = V_154 | V_153 ;
* V_139 ++ = V_147 | V_153 ;
* V_139 ++ = V_150 | ( V_9 >> 2 ) ;
* V_139 ++ = V_13 | V_157 ;
* V_139 ++ = V_150 | ( V_11 >> 2 ) ;
* V_139 ++ = V_142 ;
* V_139 ++ = V_149 | V_153 ;
* V_139 ++ = V_154 | V_153 ;
* V_139 ++ = V_147 | V_153 ;
V_140 =
( T_2 ) V_27 -> V_143 . V_145 +
( T_2 ) ( ( unsigned long ) V_139 -
( unsigned long ) V_27 -> V_143 . V_104 ) ;
for ( V_57 = 0 ; V_57 < ( 10 * V_158 / 2 ) ; V_57 ++ ) {
V_140 += 8 ;
* V_139 ++ = V_159 ;
* V_139 ++ = V_140 ;
}
if ( V_90 != NULL && V_90 -> V_121 != V_160 ) {
* V_139 ++ = V_147 | V_148 ;
* V_139 ++ = V_149 | V_148 ;
}
* V_139 ++ = V_150 | ( V_161 >> 2 ) ;
* V_139 ++ = V_162 | V_163 ;
* V_139 ++ = V_164 ;
* V_139 ++ = V_150 | ( V_161 >> 2 ) ;
* V_139 ++ = V_162 | V_165 ;
* V_139 ++ = V_147 | V_166 ;
* V_139 ++ = V_167 | ( F_37 ( V_168 ) >> 2 ) ;
* V_139 ++ =
( T_2 ) V_27 -> V_103 . V_145 +
( V_27 -> V_155 << 2 ) ;
if ( * V_138 ++ & V_169 ) {
V_27 -> V_155 ++ ;
break;
}
}
for ( V_141 = 0 ; V_141 < ( 2 * V_158 ) ; V_141 ++ )
* V_139 ++ = V_164 ;
* V_139 ++ = V_150 | ( V_161 >> 2 ) ;
* V_139 ++ = V_162 | V_163 ;
* V_139 ++ = V_164 ;
* V_139 ++ = V_150 | ( V_161 >> 2 ) ;
* V_139 ++ = V_162 | V_165 ;
* V_139 ++ = V_147 | V_166 ;
* V_139 ++ = V_167 | ( F_37 ( V_168 ) >> 2 ) ;
* V_139 ++ =
( T_2 ) V_27 -> V_103 . V_145 + ( V_27 -> V_155 << 2 ) ;
if ( V_27 -> V_110 == 1 ) {
* V_139 ++ = V_170 ;
}
* V_139 ++ = V_159 ;
* V_139 ++ = ( T_2 ) V_27 -> V_143 . V_145 ;
}
static int F_38 ( struct V_1 * V_2 ,
struct V_87 * V_88 ,
struct V_171 * V_172 , unsigned int * V_67 )
{
return - V_173 ;
}
static int F_39 ( struct V_1 * V_2 ,
struct V_87 * V_88 ,
struct V_171 * V_172 , unsigned int * V_67 )
{
T_1 V_43 = F_40 ( V_172 -> V_174 ) ;
T_1 V_175 = F_41 ( V_172 -> V_174 ) ;
T_1 V_176 = 0 ;
T_2 V_177 ;
int V_141 ;
if ( V_175 == 0 )
V_176 = ( V_43 << 8 ) | ( V_152 ) ;
else
V_176 = ( V_43 << 8 ) | ( V_156 ) ;
F_7 ( V_2 , V_151 , V_176 ) ;
F_7 ( V_2 , V_157 , V_176 ) ;
for ( V_141 = 0 ; V_141 < V_172 -> V_141 ; V_141 ++ ) {
F_42 ( 10 ) ;
V_177 = F_4 ( V_161 ) ;
F_6 ( V_161 , V_177 & ~ V_165 ) ;
F_6 ( V_161 , V_177 & ~ V_165 ) ;
F_6 ( V_161 , V_177 & ~ V_165 ) ;
F_6 ( V_161 , V_177 | V_165 ) ;
while ( ! ( F_4 ( V_5 ) & V_178 ) )
;
if ( V_141 != 0 )
V_67 [ V_141 - 1 ] = F_23 ( F_4 ( V_168 ) ) ;
F_42 ( 4 ) ;
}
V_177 = F_4 ( V_161 ) ;
F_6 ( V_161 , V_177 & ~ V_165 ) ;
F_6 ( V_161 , V_177 & ~ V_165 ) ;
F_6 ( V_161 , V_177 & ~ V_165 ) ;
F_6 ( V_161 , V_177 | V_165 ) ;
while ( ! ( F_4 ( V_5 ) & V_178 ) )
;
if ( V_141 != 0 )
V_67 [ V_141 - 1 ] = F_23 ( F_4 ( V_168 ) ) ;
return V_141 ;
}
static int F_43 ( T_3 * V_138 , struct V_89 * V_90 )
{
int V_141 ;
for ( V_141 = 0 ; V_141 < V_90 -> V_105 ; V_141 ++ ) {
if ( F_41 ( ( V_90 -> V_179 ) [ V_141 ] ) == 0 )
V_138 [ V_141 ] = ( F_40 ( ( V_90 -> V_179 ) [ V_141 ] ) ) | ( V_180 ) ;
else
V_138 [ V_141 ] = ( F_40 ( ( V_90 -> V_179 ) [ V_141 ] ) ) | ( V_181 ) ;
}
if ( V_141 != 0 )
V_138 [ V_141 - 1 ] |= V_169 ;
return V_141 ;
}
static int F_44 ( struct V_1 * V_2 ,
struct V_87 * V_88 , unsigned int V_182 )
{
if ( V_182 != 0 )
return - V_173 ;
F_2 ( V_30 , V_111 ) ;
V_88 -> V_102 -> V_183 = NULL ;
return 1 ;
}
static int F_45 ( int * V_184 , int V_185 )
{
int V_186 , V_187 ;
V_187 = 500 ;
switch ( V_185 ) {
case V_188 :
default:
V_186 = ( * V_184 + V_187 / 2 ) / V_187 ;
break;
case V_189 :
V_186 = ( * V_184 ) / V_187 ;
break;
case V_190 :
V_186 = ( * V_184 + V_187 - 1 ) / V_187 ;
break;
}
* V_184 = V_187 * V_186 ;
return V_186 - 1 ;
}
static void F_46 ( struct V_1 * V_2 , struct V_59 * V_60 ,
int V_191 )
{
T_1 V_192 = ( V_193 << V_194 ) |
( V_195 << V_196 ) |
( V_197 << V_198 ) |
( V_199 << V_200 ) |
( V_201 << V_200 ) |
( V_202 << V_203 ) |
( V_135 << V_204 ) ;
T_1 V_205 = V_206 ;
V_60 -> V_207 ( V_2 , V_60 , V_192 , FALSE ) ;
F_22 ( V_2 , V_60 , V_191 ) ;
V_60 -> V_208 ( V_2 , V_60 , 0 ) ;
V_60 -> V_209 ( V_2 , V_60 ) ;
V_60 -> V_208 ( V_2 , V_60 , 1 ) ;
V_60 -> V_210 ( V_2 , V_60 , V_211 ) ;
F_21 ( V_2 , V_60 , V_205 ) ;
}
static int F_47 ( struct V_1 * V_2 , struct V_87 * V_88 )
{
T_3 V_138 [ 16 ] ;
struct V_89 * V_90 = & V_88 -> V_102 -> V_90 ;
struct V_59 * V_60 ;
int V_191 ;
if ( V_27 -> V_110 ) {
F_32 ( V_212 L_2 ,
V_2 -> V_213 ) ;
return - V_214 ;
}
F_30 ( 0 , V_27 -> V_99 + V_100 ) ;
F_30 ( V_101 | V_116 , V_27 -> V_99 + V_32 ) ;
F_26 ( V_2 ) ;
V_27 -> V_110 = 0 ;
if ( V_90 == NULL )
return - V_173 ;
if ( V_2 -> V_85 == 0 ) {
F_48 ( V_2 ,
L_3 ) ;
return - V_215 ;
}
F_43 ( V_138 , V_90 ) ;
V_27 -> V_110 = 1 ;
V_27 -> V_122 = 0 ;
switch ( V_90 -> V_113 ) {
case V_146 :
break;
case V_124 :
V_60 = & V_125 [ 5 ] ;
V_191 = F_45 ( ( int * ) & V_90 -> V_115 ,
V_90 -> V_91 & V_216 ) ;
F_46 ( V_2 , V_60 , V_191 ) ;
V_60 -> V_126 ( V_2 , V_60 , V_127 ) ;
break;
case V_114 :
if ( V_90 -> V_119 != V_114 )
F_24 ( V_2 , V_90 -> V_115 ) ;
break;
}
switch ( V_90 -> V_121 ) {
case V_160 :
break;
case V_124 :
V_60 = & V_125 [ 4 ] ;
V_191 = F_45 ( ( int * ) & V_90 -> V_123 ,
V_90 -> V_91 & V_216 ) ;
F_46 ( V_2 , V_60 , V_191 ) ;
V_60 -> V_126 ( V_2 , V_60 , V_135 ) ;
break;
case V_114 :
if ( V_90 -> V_113 != V_114
&& V_90 -> V_119 == V_114 )
F_24 ( V_2 , V_90 -> V_123 ) ;
break;
}
switch ( V_90 -> V_217 ) {
case V_218 :
V_27 -> V_109 = V_90 -> V_219 ;
V_27 -> V_108 = 0 ;
break;
case V_220 :
V_27 -> V_108 = 1 ;
V_27 -> V_109 = 0 ;
break;
}
F_36 ( V_2 , V_138 ) ;
switch ( V_90 -> V_119 ) {
case V_160 :
F_2 ( V_30 , V_111 ) ;
V_88 -> V_102 -> V_183 = NULL ;
break;
case V_114 :
F_24 ( V_2 , V_90 -> V_118 ) ;
V_88 -> V_102 -> V_183 = NULL ;
break;
case V_221 :
V_88 -> V_102 -> V_183 = F_44 ;
break;
}
F_30 ( V_116 | V_101 , V_27 -> V_99 + V_100 ) ;
return 0 ;
}
static int F_49 ( struct V_1 * V_2 ,
struct V_87 * V_88 , struct V_89 * V_90 )
{
int V_222 = 0 ;
int V_223 ;
V_223 = V_90 -> V_119 ;
V_90 -> V_119 &= V_160 | V_221 | V_114 ;
if ( ! V_90 -> V_119 || V_223 != V_90 -> V_119 )
V_222 ++ ;
V_223 = V_90 -> V_113 ;
V_90 -> V_113 &= V_124 | V_114 | V_146 ;
if ( ! V_90 -> V_113 || V_223 != V_90 -> V_113 )
V_222 ++ ;
V_223 = V_90 -> V_121 ;
V_90 -> V_121 &= V_124 | V_114 | V_160 ;
if ( ! V_90 -> V_121 || V_223 != V_90 -> V_121 )
V_222 ++ ;
V_223 = V_90 -> V_224 ;
V_90 -> V_224 &= V_218 ;
if ( ! V_90 -> V_224 || V_223 != V_90 -> V_224 )
V_222 ++ ;
V_223 = V_90 -> V_217 ;
V_90 -> V_217 &= V_218 | V_220 ;
if ( ! V_90 -> V_217 || V_223 != V_90 -> V_217 )
V_222 ++ ;
if ( V_222 )
return 1 ;
if ( V_90 -> V_113 != V_124 &&
V_90 -> V_113 != V_114
&& V_90 -> V_113 != V_146 )
V_222 ++ ;
if ( V_90 -> V_121 != V_124 &&
V_90 -> V_121 != V_114 && V_90 -> V_121 != V_160 )
V_222 ++ ;
if ( V_90 -> V_217 != V_218 && V_90 -> V_217 != V_220 )
V_222 ++ ;
if ( V_222 )
return 2 ;
if ( V_90 -> V_119 != V_114 && V_90 -> V_118 != 0 ) {
V_90 -> V_118 = 0 ;
V_222 ++ ;
}
if ( V_90 -> V_119 == V_114 && V_90 -> V_118 > 39 ) {
V_90 -> V_118 = 39 ;
V_222 ++ ;
}
if ( V_90 -> V_113 == V_114 && V_90 -> V_115 > 39 ) {
V_90 -> V_115 = 39 ;
V_222 ++ ;
}
if ( V_90 -> V_121 == V_114 && V_90 -> V_123 > 39 ) {
V_90 -> V_123 = 39 ;
V_222 ++ ;
}
#define F_50 200000
#define F_51 2000000000
if ( V_90 -> V_113 == V_124 ) {
if ( V_90 -> V_115 < F_50 ) {
V_90 -> V_115 = F_50 ;
V_222 ++ ;
}
if ( V_90 -> V_115 > F_51 ) {
V_90 -> V_115 = F_51 ;
V_222 ++ ;
}
} else {
}
if ( V_90 -> V_121 == V_124 ) {
if ( V_90 -> V_123 < F_50 ) {
V_90 -> V_123 = F_50 ;
V_222 ++ ;
}
if ( V_90 -> V_123 > F_51 ) {
V_90 -> V_123 = F_51 ;
V_222 ++ ;
}
} else {
}
if ( V_90 -> V_225 != V_90 -> V_105 ) {
V_90 -> V_225 = V_90 -> V_105 ;
V_222 ++ ;
}
if ( V_90 -> V_217 == V_218 ) {
if ( V_90 -> V_219 > 0x00ffffff ) {
V_90 -> V_219 = 0x00ffffff ;
V_222 ++ ;
}
} else {
if ( V_90 -> V_219 != 0 ) {
V_90 -> V_219 = 0 ;
V_222 ++ ;
}
}
if ( V_222 )
return 3 ;
if ( V_90 -> V_113 == V_124 ) {
V_223 = V_90 -> V_115 ;
F_45 ( ( int * ) & V_90 -> V_115 ,
V_90 -> V_91 & V_216 ) ;
if ( V_223 != V_90 -> V_115 )
V_222 ++ ;
}
if ( V_90 -> V_121 == V_124 ) {
V_223 = V_90 -> V_123 ;
F_45 ( ( int * ) & V_90 -> V_123 ,
V_90 -> V_91 & V_216 ) ;
if ( V_223 != V_90 -> V_123 )
V_222 ++ ;
if ( V_90 -> V_113 == V_124 &&
V_90 -> V_115 <
V_90 -> V_123 * V_90 -> V_225 ) {
V_90 -> V_115 =
V_90 -> V_123 * V_90 -> V_225 ;
V_222 ++ ;
}
}
if ( V_222 )
return 4 ;
return 0 ;
}
static int F_52 ( struct V_1 * V_2 , struct V_87 * V_88 )
{
F_33 ( V_30 , V_111 ) ;
F_30 ( 0 , V_27 -> V_99 + V_100 ) ;
V_27 -> V_110 = 0 ;
return 0 ;
}
static int F_53 ( struct V_1 * V_2 , struct V_87 * V_88 ,
struct V_171 * V_172 , unsigned int * V_67 )
{
int V_57 ;
T_1 V_43 = F_40 ( V_172 -> V_174 ) ;
T_6 V_44 ;
for ( V_57 = 0 ; V_57 < V_172 -> V_141 ; V_57 ++ ) {
V_44 = ( T_6 ) V_67 [ V_57 ] ;
V_27 -> V_226 [ F_40 ( V_172 -> V_174 ) ] = V_67 [ V_57 ] ;
V_44 -= ( 0x1fff ) ;
F_16 ( V_2 , V_43 , V_44 ) ;
}
return V_57 ;
}
static int F_54 ( struct V_1 * V_2 , struct V_87 * V_88 ,
struct V_171 * V_172 , unsigned int * V_67 )
{
int V_57 ;
for ( V_57 = 0 ; V_57 < V_172 -> V_141 ; V_57 ++ )
V_67 [ V_57 ] = V_27 -> V_226 [ F_40 ( V_172 -> V_174 ) ] ;
return V_57 ;
}
static void F_55 ( struct V_1 * V_2 )
{
T_1 V_69 ;
struct V_87 * V_88 ;
F_7 ( V_2 , V_79 , V_83 ) ;
for ( V_69 = 0 ; V_69 < V_84 ; V_69 ++ ) {
V_88 = V_2 -> V_73 + 2 + V_69 ;
F_7 ( V_2 , V_227 -> V_78 , 0 ) ;
F_7 ( V_2 , V_227 -> V_82 , 0xFFFF ) ;
F_7 ( V_2 , V_227 -> V_76 , 0 ) ;
F_7 ( V_2 , V_227 -> V_228 , 0 ) ;
}
}
static int F_56 ( struct V_1 * V_2 ,
struct V_87 * V_88 ,
struct V_171 * V_172 , unsigned int * V_67 )
{
if ( V_67 [ 0 ] ) {
if ( ( V_88 -> V_229 & V_67 [ 0 ] ) != V_67 [ 0 ] )
return - V_215 ;
V_88 -> V_230 &= ~ V_67 [ 0 ] ;
V_88 -> V_230 |= V_67 [ 0 ] & V_67 [ 1 ] ;
F_7 ( V_2 , V_227 -> V_228 , V_88 -> V_230 ) ;
}
V_67 [ 1 ] = F_5 ( V_2 , V_227 -> V_231 ) ;
return V_172 -> V_141 ;
}
static int F_57 ( struct V_1 * V_2 ,
struct V_87 * V_88 ,
struct V_171 * V_172 , unsigned int * V_67 )
{
switch ( V_67 [ 0 ] ) {
case V_232 :
V_67 [ 1 ] =
( V_88 ->
V_229 & ( 1 << F_40 ( V_172 -> V_174 ) ) ) ? V_233 :
V_234 ;
return V_172 -> V_141 ;
break;
case V_234 :
V_88 -> V_229 &= ~ ( 1 << F_40 ( V_172 -> V_174 ) ) ;
break;
case V_233 :
V_88 -> V_229 |= 1 << F_40 ( V_172 -> V_174 ) ;
break;
default:
return - V_173 ;
break;
}
F_7 ( V_2 , V_227 -> V_228 , V_88 -> V_229 ) ;
return 1 ;
}
static int F_58 ( struct V_1 * V_2 ,
struct V_87 * V_88 ,
struct V_171 * V_172 , unsigned int * V_67 )
{
T_1 V_192 = ( V_193 << V_194 ) |
( V_195 << V_196 ) |
( V_235 << V_198 ) |
( V_199 << V_200 ) |
( V_202 << V_203 ) |
( V_135 << V_204 ) ;
T_1 V_205 = V_236 ;
T_1 V_237 = V_127 ;
struct V_59 * V_60 = & V_125 [ F_40 ( V_172 -> V_174 ) ] ;
V_60 -> V_207 ( V_2 , V_60 , V_192 , TRUE ) ;
F_22 ( V_2 , V_60 , * ( V_172 -> V_67 ) ) ;
V_60 -> V_209 ( V_2 , V_60 ) ;
F_21 ( V_2 , V_60 , V_205 ) ;
V_60 -> V_126 ( V_2 , V_60 , ( T_1 ) ( V_237 != 0 ) ) ;
return V_172 -> V_141 ;
}
static int F_59 ( struct V_1 * V_2 ,
struct V_87 * V_88 ,
struct V_171 * V_172 , unsigned int * V_67 )
{
int V_141 ;
struct V_59 * V_60 = & V_125 [ F_40 ( V_172 -> V_174 ) ] ;
for ( V_141 = 0 ; V_141 < V_172 -> V_141 ; V_141 ++ )
V_67 [ V_141 ] = F_20 ( V_2 , V_60 ) ;
return V_141 ;
}
static int F_60 ( struct V_1 * V_2 ,
struct V_87 * V_88 ,
struct V_171 * V_172 , unsigned int * V_67 )
{
struct V_59 * V_60 = & V_125 [ F_40 ( V_172 -> V_174 ) ] ;
F_22 ( V_2 , V_60 , V_67 [ 0 ] ) ;
V_60 -> V_208 ( V_2 , V_60 , 0 ) ;
V_60 -> V_209 ( V_2 , V_60 ) ;
V_60 -> V_208 ( V_2 , V_60 , 2 ) ;
return 1 ;
}
static void F_61 ( struct V_1 * V_2 , T_1 V_238 )
{
F_7 ( V_2 , V_79 , V_239 ) ;
F_7 ( V_2 , V_240 , V_238 ) ;
F_7 ( V_2 , V_79 , V_241 ) ;
}
static void F_62 ( struct V_1 * V_2 , struct V_242 * V_243 ,
T_7 V_244 )
{
void * V_245 ;
T_8 V_246 ;
if ( V_243 == NULL )
return;
V_245 = V_243 -> V_104 ;
V_246 = V_243 -> V_145 ;
if ( V_245 ) {
F_63 ( V_27 -> V_247 , V_244 , V_245 , V_246 ) ;
V_243 -> V_104 = NULL ;
V_243 -> V_145 = 0 ;
}
}
static void F_64 ( struct V_1 * V_2 , struct V_59 * V_60 )
{
F_8 ( V_2 , V_60 -> V_63 , ( T_1 ) ( ~ V_64 ) ,
V_248 | V_249 ) ;
}
static void F_65 ( struct V_1 * V_2 , struct V_59 * V_60 )
{
F_8 ( V_2 , V_60 -> V_63 , ( T_1 ) ( ~ V_64 ) ,
V_248 | V_250 ) ;
}
static T_1 F_66 ( struct V_1 * V_2 , struct V_59 * V_60 )
{
register T_1 V_251 ;
register T_1 V_252 ;
register T_1 V_253 ;
V_251 = F_5 ( V_2 , V_60 -> V_254 ) ;
V_252 = F_5 ( V_2 , V_60 -> V_63 ) ;
V_253 = ( ( V_251 & V_255 )
| ( ( V_252 << ( V_256 - V_66 ) ) & V_257 )
| ( ( V_251 << ( V_258 - V_259 ) ) & V_260 )
| ( ( V_251 << ( V_261 - ( V_262 + 1 ) ) ) & V_263 )
| ( ( V_251 >> ( V_264 - V_265 ) ) & V_266 )
| ( ( V_252 >> ( V_267 - V_268 ) ) & V_269 ) ) ;
if ( V_251 & ( 2 << V_270 ) )
V_253 |= ( ( V_197 << V_271 )
| ( ( V_251 << ( V_272 - V_270 ) ) & V_273 )
| ( V_274 << V_275 ) ) ;
else
V_253 |= ( ( V_235 << V_271 )
| ( ( V_251 >> ( V_276 - V_272 ) ) & V_273 )
| ( ( ( V_251 & V_277 ) == ( V_278 << V_279 ) ) ?
( V_274 << V_275 ) :
( ( V_251 >> ( V_279 -
V_275 ) ) & V_280 ) ) ) ;
return V_253 ;
}
static T_1 F_67 ( struct V_1 * V_2 , struct V_59 * V_60 )
{
register T_1 V_251 ;
register T_1 V_252 ;
register T_1 V_253 ;
V_251 = F_5 ( V_2 , V_60 -> V_254 ) ;
V_252 = F_5 ( V_2 , V_60 -> V_63 ) ;
V_253 = ( ( ( V_252 << ( V_258 - V_281 ) ) & V_260 )
| ( ( V_252 << ( V_256 - V_66 ) ) & V_257 )
| ( ( V_252 << ( V_282 - V_283 ) ) & V_255 )
| ( ( V_252 << ( V_265 - V_284 ) ) & V_266 )
| ( ( V_252 >> ( V_285 - V_268 ) ) & V_269 )
| ( ( V_251 >> ( ( V_286 + 1 ) - V_261 ) ) & V_263 ) ) ;
if ( ( V_252 & V_287 ) == ( V_278 << V_288 ) )
V_253 |= ( ( V_289 << V_271 )
| ( V_274 << V_275 )
| ( ( V_251 >> ( V_290 - V_272 ) ) & V_273 ) ) ;
else if ( V_251 & ( 2 << V_290 ) )
V_253 |= ( ( V_197 << V_271 )
| ( V_274 << V_275 )
| ( ( V_251 >> ( V_290 - V_272 ) ) & V_273 ) ) ;
else
V_253 |= ( ( V_235 << V_271 )
| ( ( V_252 >> ( V_288 - V_275 ) ) & V_280 )
| ( ( V_252 << ( V_272 - V_291 ) ) & V_273 ) ) ;
return V_253 ;
}
static void F_68 ( struct V_1 * V_2 , struct V_59 * V_60 ,
T_1 V_192 , T_1 V_292 )
{
register T_1 V_251 ;
register T_1 V_252 ;
register T_1 V_253 = V_192 ;
V_251 = ( ( V_253 & V_293 )
| ( ( V_253 & V_263 ) >> ( V_261 - ( V_262 + 1 ) ) ) ) ;
V_252 = ( V_248 | V_249
| ( ( V_253 & V_269 ) << ( V_267 - V_268 ) ) ) ;
if ( ! V_292 )
V_251 |= ( ( V_253 & V_260 ) >> ( V_258 -
V_259 ) ) ;
switch ( ( V_253 & V_294 ) >> V_271 ) {
case V_289 :
case V_197 :
V_251 |= ( ( 2 << V_270 )
| ( ( V_253 & V_273 ) >> ( V_272 - V_270 ) )
| ( 1 << V_276 )
| ( V_274 << V_279 ) ) ;
break;
default:
V_251 |= ( V_235
| ( ( V_253 & V_273 ) << ( V_276 - V_272 ) )
| ( ( ( V_253 & V_280 ) == ( V_278 << V_275 ) ) ?
( V_274 << V_279 ) :
( ( V_253 & V_280 ) << ( V_279 -
V_275 ) ) ) ) ;
}
if ( ~ V_253 & V_263 )
V_251 |= ( ( V_253 & V_266 ) << ( V_264 -
V_265 ) ) ;
if ( V_292 )
V_27 -> V_295 &= ~ V_60 -> V_296 [ 3 ] ;
F_8 ( V_2 , V_60 -> V_254 , V_297 | V_298 , V_251 ) ;
F_8 ( V_2 , V_60 -> V_63 ,
( T_1 ) ( ~ ( V_64 | V_299 ) ) , V_252 ) ;
}
static void F_69 ( struct V_1 * V_2 , struct V_59 * V_60 ,
T_1 V_192 , T_1 V_292 )
{
register T_1 V_251 ;
register T_1 V_252 ;
register T_1 V_253 = V_192 ;
V_251 = ( ( V_253 & V_263 ) << ( ( V_286 + 1 ) - V_261 ) ) ;
V_252 = ( V_248 | V_250
| ( ( V_253 & V_269 ) << ( V_285 - V_268 ) )
| ( ( V_253 & V_255 ) >> ( V_282 - V_283 ) ) ) ;
if ( ! V_292 )
V_252 |= ( ( V_253 & V_260 ) >> ( V_258 -
V_281 ) ) ;
switch ( ( V_253 & V_294 ) >> V_271 ) {
case V_197 :
V_251 |= ( ( 2 << V_290 )
| ( ( V_253 & V_273 ) << ( V_290 - V_272 ) ) ) ;
V_252 |= ( ( 1 << V_291 )
| ( V_274 << V_288 ) ) ;
break;
case V_289 :
V_251 |= ( ( 2 << V_290 )
| ( ( V_253 & V_273 ) << ( V_290 - V_272 ) ) ) ;
V_252 |= ( ( 1 << V_291 )
| ( V_278 << V_288 ) ) ;
break;
default:
V_251 |= ( V_235 << V_290 ) ;
V_252 |= ( ( ( V_253 & V_273 ) >> ( V_272 - V_291 ) )
| ( ( ( V_253 & V_280 ) == ( V_278 << V_275 ) ) ?
( V_274 << V_288 ) :
( ( V_253 & V_280 ) << ( V_288 -
V_275 ) ) ) ) ;
}
if ( ~ V_253 & V_263 )
V_252 |= ( ( V_253 & V_266 ) >> ( V_265 -
V_284 ) ) ;
if ( V_292 )
V_27 -> V_295 &= ~ V_60 -> V_296 [ 3 ] ;
F_8 ( V_2 , V_60 -> V_254 ,
( T_1 ) ( ~ ( V_297 | V_298 ) ) , V_251 ) ;
F_8 ( V_2 , V_60 -> V_63 , V_299 | V_65 , V_252 ) ;
}
static void F_70 ( struct V_1 * V_2 , struct V_59 * V_60 ,
T_1 V_237 )
{
F_8 ( V_2 , V_60 -> V_63 ,
( T_1 ) ( ~ ( V_64 | V_299 ) ) ,
( T_1 ) ( V_237 << V_267 ) ) ;
}
static void F_71 ( struct V_1 * V_2 , struct V_59 * V_60 ,
T_1 V_237 )
{
F_8 ( V_2 , V_60 -> V_63 ,
( T_1 ) ( ~ ( V_64 | V_300 ) ) ,
( T_1 ) ( V_237 << V_285 ) ) ;
}
static T_1 F_72 ( struct V_1 * V_2 , struct V_59 * V_60 )
{
return ( F_5 ( V_2 , V_60 -> V_63 ) >> V_267 ) & 1 ;
}
static T_1 F_73 ( struct V_1 * V_2 , struct V_59 * V_60 )
{
return ( F_5 ( V_2 , V_60 -> V_63 ) >> V_285 ) & 1 ;
}
static void F_74 ( struct V_1 * V_2 , struct V_59 * V_60 ,
T_1 V_301 )
{
F_8 ( V_2 , V_60 -> V_254 , ( T_1 ) ( ~ V_293 ) ,
( T_1 ) ( V_301 << V_302 ) ) ;
}
static void F_75 ( struct V_1 * V_2 , struct V_59 * V_60 ,
T_1 V_301 )
{
F_8 ( V_2 , V_60 -> V_63 ,
( T_1 ) ( ~ ( V_303 | V_64 ) ) ,
( T_1 ) ( V_301 << V_283 ) ) ;
}
static T_1 F_76 ( struct V_1 * V_2 , struct V_59 * V_60 )
{
return ( F_5 ( V_2 , V_60 -> V_254 ) >> V_302 ) & 3 ;
}
static T_1 F_77 ( struct V_1 * V_2 , struct V_59 * V_60 )
{
return ( F_5 ( V_2 , V_60 -> V_63 ) >> V_283 ) & 3 ;
}
static void F_78 ( struct V_1 * V_2 , struct V_59 * V_60 ,
T_1 V_304 )
{
F_8 ( V_2 , V_60 -> V_63 , ( T_1 ) ( ~ V_64 ) ,
V_248 | V_249 ) ;
F_8 ( V_2 , V_60 -> V_254 , ~ V_305 ,
( T_1 ) ( V_304 << V_259 ) ) ;
V_27 -> V_295 =
( V_27 -> V_295 & ~ V_60 ->
V_296 [ 3 ] ) | V_60 -> V_296 [ V_304 ] ;
}
static void F_79 ( struct V_1 * V_2 , struct V_59 * V_60 ,
T_1 V_304 )
{
T_1 V_252 ;
V_252 = F_5 ( V_2 , V_60 -> V_63 ) & ~ V_64 ;
F_7 ( V_2 , V_60 -> V_63 ,
( T_1 ) ( V_252 | V_248 | V_250 ) ) ;
F_7 ( V_2 , V_60 -> V_63 ,
( T_1 ) ( ( V_252 & ~ V_306 ) | ( V_304 <<
V_281 ) ) ) ;
V_27 -> V_295 =
( V_27 -> V_295 & ~ V_60 ->
V_296 [ 3 ] ) | V_60 -> V_296 [ V_304 ] ;
}
static T_1 F_80 ( struct V_1 * V_2 , struct V_59 * V_60 )
{
return ( F_5 ( V_2 , V_60 -> V_254 ) >> V_259 ) & 3 ;
}
static T_1 F_81 ( struct V_1 * V_2 , struct V_59 * V_60 )
{
return ( F_5 ( V_2 , V_60 -> V_63 ) >> V_281 ) & 3 ;
}
static void F_82 ( struct V_1 * V_2 , struct V_59 * V_60 )
{
register T_1 V_251 ;
V_251 = F_5 ( V_2 , V_60 -> V_254 ) ;
F_7 ( V_2 , V_60 -> V_254 , ( T_1 ) ( V_251 ^ V_307 ) ) ;
F_7 ( V_2 , V_60 -> V_254 , V_251 ) ;
}
static void F_83 ( struct V_1 * V_2 , struct V_59 * V_60 )
{
register T_1 V_252 ;
V_252 = F_5 ( V_2 , V_60 -> V_63 ) & ~ V_64 ;
F_7 ( V_2 , V_60 -> V_63 , ( T_1 ) ( V_252 ^ V_308 ) ) ;
F_7 ( V_2 , V_60 -> V_63 , V_252 ) ;
}
static void F_84 ( struct V_1 * V_2 )
{
int V_43 ;
struct V_59 * V_60 ;
T_1 V_192 = ( V_193 << V_194 ) |
( V_195 << V_196 ) |
( V_235 << V_198 ) |
( V_199 << V_200 ) |
( V_309 << V_200 ) |
( V_202 << V_203 ) |
( V_135 << V_204 ) ;
for ( V_43 = 0 ; V_43 < V_310 ; V_43 ++ ) {
V_60 = & V_125 [ V_43 ] ;
V_60 -> V_207 ( V_2 , V_60 , V_192 , TRUE ) ;
V_60 -> V_210 ( V_2 , V_60 , 0 ) ;
V_60 -> V_130 ( V_2 , V_60 ) ;
V_60 -> V_126 ( V_2 , V_60 , V_127 ) ;
}
}
static struct V_311 * F_85 ( struct V_1 * V_2 ,
struct V_312 * V_313 )
{
struct V_311 * V_314 = NULL ;
int V_315 = V_313 -> V_316 [ 0 ] ;
int V_317 = V_313 -> V_316 [ 1 ] ;
int V_57 ;
for ( V_57 = 0 ; V_57 < F_19 ( V_318 ) && ! V_314 ; V_57 ++ ) {
do {
V_314 = F_86 ( V_318 [ V_57 ] . V_319 ,
V_318 [ V_57 ] . V_320 ,
V_318 [ V_57 ] . V_321 ,
V_318 [ V_57 ] . V_322 ,
V_314 ) ;
if ( ( V_315 || V_317 ) && V_314 ) {
if ( V_314 -> V_315 -> V_323 == V_315 &&
F_87 ( V_314 -> V_324 ) == V_317 )
break;
} else {
break;
}
} while ( 1 );
}
return V_314 ;
}
static int F_88 ( struct V_1 * V_2 , struct V_312 * V_313 )
{
int V_325 ;
int V_57 ;
int V_326 ;
T_9 V_327 ;
T_8 V_328 ;
struct V_87 * V_88 ;
if ( F_89 ( V_2 , sizeof( struct V_329 ) ) < 0 )
return - V_330 ;
V_27 -> V_247 = F_85 ( V_2 , V_313 ) ;
if ( ! V_27 -> V_247 ) {
F_32 ( V_212 L_4 ) ;
return - V_331 ;
}
V_325 = F_90 ( V_27 -> V_247 , L_5 ) ;
if ( V_325 < 0 ) {
F_32 ( V_212 L_6 ) ;
return - V_331 ;
}
V_27 -> V_332 = 1 ;
V_327 = F_91 ( V_27 -> V_247 , 0 ) ;
V_27 -> V_99 = F_92 ( V_327 , V_333 ) ;
if ( V_27 -> V_99 == NULL ) {
F_32 ( V_212 L_7 ) ;
return - V_331 ;
}
if ( V_27 -> V_99 ) {
F_30 ( 0 , V_27 -> V_99 + V_100 ) ;
F_30 ( V_334 , V_27 -> V_99 + V_30 ) ;
V_27 -> V_335 = 0 ;
V_27 -> V_103 . V_104 =
F_93 ( V_27 -> V_247 , V_336 , & V_328 ) ;
if ( V_27 -> V_103 . V_104 == NULL ) {
F_32 ( V_212 L_8 ) ;
return - V_330 ;
}
V_27 -> V_103 . V_145 = V_328 ;
V_27 -> V_335 ++ ;
V_27 -> V_143 . V_104 =
F_93 ( V_27 -> V_247 , V_336 , & V_328 ) ;
if ( V_27 -> V_143 . V_104 == NULL ) {
F_32 ( V_212 L_8 ) ;
return - V_330 ;
}
V_27 -> V_143 . V_145 = V_328 ;
V_27 -> V_335 ++ ;
}
V_2 -> V_337 = V_318 ;
V_2 -> V_338 = V_339 -> V_340 ;
V_326 = F_94 ( V_2 , 6 ) ;
if ( V_326 )
return V_326 ;
V_2 -> V_341 = ( unsigned long ) V_27 -> V_99 ;
V_2 -> V_85 = V_27 -> V_247 -> V_85 ;
if ( V_2 -> V_85 == 0 ) {
F_32 ( V_212 L_9 ) ;
} else {
V_326 = F_95 ( V_2 -> V_85 , F_27 , V_342 ,
L_5 , V_2 ) ;
if ( V_326 < 0 ) {
F_32 ( V_212 L_10 ) ;
V_2 -> V_85 = 0 ;
}
}
V_88 = V_2 -> V_73 + 0 ;
V_2 -> V_343 = V_88 ;
V_88 -> type = V_344 ;
V_88 -> V_345 = V_346 | V_347 | V_348 ;
V_88 -> V_349 = V_339 -> V_350 ;
V_88 -> V_351 = ( 0xffff >> 2 ) ;
V_88 -> V_352 = & V_353 ;
V_88 -> V_354 = V_339 -> V_350 ;
V_88 -> V_355 = F_38 ;
V_88 -> V_356 = F_39 ;
V_88 -> V_357 = F_47 ;
V_88 -> V_358 = F_49 ;
V_88 -> V_359 = F_52 ;
V_88 = V_2 -> V_73 + 1 ;
V_88 -> type = V_360 ;
V_88 -> V_345 = V_361 | V_346 ;
V_88 -> V_349 = V_339 -> V_362 ;
V_88 -> V_351 = ( 0x3fff ) ;
V_88 -> V_352 = & V_363 ;
V_88 -> V_364 = F_53 ;
V_88 -> V_356 = F_54 ;
V_88 = V_2 -> V_73 + 2 ;
V_88 -> type = V_365 ;
V_88 -> V_345 = V_361 | V_346 ;
V_88 -> V_349 = 16 ;
V_88 -> V_351 = 1 ;
V_88 -> V_229 = 0xffff ;
V_88 -> V_74 = & V_366 ;
V_88 -> V_352 = & V_367 ;
V_88 -> V_355 = F_57 ;
V_88 -> V_368 = F_56 ;
V_88 = V_2 -> V_73 + 3 ;
V_88 -> type = V_365 ;
V_88 -> V_345 = V_361 | V_346 ;
V_88 -> V_349 = 16 ;
V_88 -> V_351 = 1 ;
V_88 -> V_229 = 0xffff ;
V_88 -> V_74 = & V_369 ;
V_88 -> V_352 = & V_367 ;
V_88 -> V_355 = F_57 ;
V_88 -> V_368 = F_56 ;
V_88 = V_2 -> V_73 + 4 ;
V_88 -> type = V_365 ;
V_88 -> V_345 = V_361 | V_346 ;
V_88 -> V_349 = 16 ;
V_88 -> V_351 = 1 ;
V_88 -> V_229 = 0xffff ;
V_88 -> V_74 = & V_370 ;
V_88 -> V_352 = & V_367 ;
V_88 -> V_355 = F_57 ;
V_88 -> V_368 = F_56 ;
V_88 = V_2 -> V_73 + 5 ;
V_88 -> type = V_371 ;
V_88 -> V_345 = V_361 | V_346 | V_372 ;
V_88 -> V_349 = V_339 -> V_373 ;
V_88 -> V_74 = V_374 ;
V_88 -> V_355 = F_58 ;
V_88 -> V_356 = F_59 ;
V_88 -> V_364 = F_60 ;
V_88 -> V_351 = 0xffffff ;
V_88 -> V_352 = & V_375 ;
V_27 -> V_110 = 0 ;
if ( V_27 -> V_99 && ( V_27 -> V_335 == 2 ) ) {
T_8 V_376 ;
T_1 V_43 ;
F_2 ( V_30 , V_377 | V_378 | V_379 ) ;
F_6 ( V_380 , V_381
| ( V_382 << V_383 )
| V_384
| V_385 ) ;
F_6 ( V_386 , V_387 ) ;
F_6 ( V_161 , V_162 | V_165 ) ;
V_27 -> V_388 = 0xA0 ;
F_6 ( V_389 , V_390 | V_391 ) ;
F_2 ( V_3 , V_17 ) ;
while ( ( F_4 ( V_3 ) & V_17 ) == 0 )
;
for ( V_57 = 0 ; V_57 < 2 ; V_57 ++ ) {
F_6 ( V_389 , V_390 ) ;
F_2 ( V_3 , V_17 ) ;
while ( ! F_3 ( V_3 , V_17 ) )
;
}
F_6 ( V_392 , V_393 ) ;
F_6 ( V_394 , V_395 | V_396 ) ;
F_6 ( V_394 + 4 , V_395 | V_396 | V_41 ) ;
F_6 ( V_397 , V_398 ) ;
F_6 ( V_144 , ( T_2 ) V_27 -> V_143 . V_145 ) ;
F_6 ( V_399 , 0 ) ;
F_6 ( V_400 , 0 ) ;
F_6 ( V_401 , 0 ) ;
V_376 =
V_27 -> V_103 . V_145 +
( V_402 * sizeof( T_2 ) ) ;
F_6 ( V_403 , ( T_2 ) V_376 ) ;
F_6 ( V_404 , ( T_2 ) ( V_376 + sizeof( T_2 ) ) ) ;
V_27 -> V_29 =
( T_2 * ) V_27 -> V_103 . V_104 + V_402 ;
F_6 ( V_405 , 8 ) ;
F_15 ( 0 , V_34 | V_35 | V_36 | V_41 ) ;
F_15 ( 1 , V_406 ) ;
F_6 ( V_397 , V_407 ) ;
F_18 ( V_2 ) ;
F_18 ( V_2 ) ;
for ( V_43 = 0 ; V_43 < V_408 ; V_43 ++ )
F_16 ( V_2 , V_43 , 0 ) ;
V_27 -> V_409 = 0 ;
V_27 -> V_410 = 0 ;
V_27 -> V_295 = 0 ;
F_84 ( V_2 ) ;
F_61 ( V_2 , ( T_1 ) ( F_5 ( V_2 ,
V_128 ) &
V_411 ) ) ;
F_55 ( V_2 ) ;
}
return 1 ;
}
static void F_96 ( struct V_1 * V_2 )
{
if ( V_27 ) {
V_27 -> V_110 = 0 ;
if ( V_27 -> V_99 ) {
F_6 ( V_100 , 0 ) ;
F_6 ( V_32 , V_116 | V_101 ) ;
F_61 ( V_2 , 0 ) ;
F_6 ( V_30 , V_412 ) ;
F_6 ( V_397 , V_413 ) ;
F_62 ( V_2 , & V_27 -> V_143 , V_336 ) ;
F_62 ( V_2 , & V_27 -> V_103 , V_336 ) ;
}
if ( V_2 -> V_85 )
F_97 ( V_2 -> V_85 , V_2 ) ;
if ( V_27 -> V_99 )
F_98 ( V_27 -> V_99 ) ;
if ( V_27 -> V_247 ) {
if ( V_27 -> V_332 )
F_99 ( V_27 -> V_247 ) ;
F_100 ( V_27 -> V_247 ) ;
}
}
}
static int T_10 F_101 ( struct V_311 * V_2 ,
const struct V_414 * V_415 )
{
return F_102 ( V_2 , & V_416 ) ;
}
static void T_11 F_103 ( struct V_311 * V_2 )
{
F_104 ( V_2 ) ;
}
