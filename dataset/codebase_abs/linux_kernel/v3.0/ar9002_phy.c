static int F_1 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
T_1 V_5 , V_6 , V_7 = 0 ;
T_2 V_8 , V_9 , V_10 = 0 , V_11 = 0 , V_12 = 0 ;
struct V_13 V_14 ;
T_2 V_15 = 24 ;
F_2 ( V_2 , V_4 , & V_14 ) ;
V_8 = V_14 . V_16 ;
V_12 = F_3 ( V_2 , V_17 ) ;
V_12 &= 0xc0000000 ;
if ( V_8 < 4800 ) {
T_2 V_18 ;
int V_19 = 0 ;
V_5 = 1 ;
V_6 = 1 ;
V_7 = 0 ;
V_10 = F_4 ( V_8 ) ;
if ( F_5 ( V_2 ) ) {
if ( V_8 == 2484 ) {
F_6 ( & V_2 -> V_20 ,
1 , V_19 ) ;
} else {
F_6 ( & V_2 -> V_21 ,
1 , V_19 ) ;
}
} else {
V_18 = F_3 ( V_2 , V_22 ) ;
if ( V_8 == 2484 ) {
F_7 ( V_2 , V_22 ,
V_18 | V_23 ) ;
} else {
F_7 ( V_2 , V_22 ,
V_18 & ~ V_23 ) ;
}
}
} else {
V_5 = 0 ;
V_6 = 0 ;
switch ( V_2 -> V_24 -> V_25 ( V_2 , V_26 ) ) {
case 0 :
if ( ( V_8 % 20 ) == 0 )
V_7 = 3 ;
else if ( ( V_8 % 10 ) == 0 )
V_7 = 2 ;
if ( V_7 )
break;
case 1 :
default:
V_7 = 0 ;
V_6 = 1 ;
V_15 = 1 ;
V_10 = F_8 ( V_8 ) ;
F_9 ( V_2 , V_27 ,
V_28 , V_15 ) ;
}
if ( ! V_6 ) {
V_9 = ( V_8 * ( V_15 >> V_7 ) ) / 60 ;
V_10 = V_9 & 0x1ff ;
V_11 = ( V_9 & 0xfffffe00 ) * 2 ;
V_10 = ( V_10 << 17 ) | V_11 ;
}
}
V_12 = V_12 |
( V_5 << 29 ) |
( V_6 << 28 ) | ( V_7 << 26 ) | ( V_10 ) ;
F_7 ( V_2 , V_17 , V_12 ) ;
V_2 -> V_29 = V_4 ;
V_2 -> V_30 = - 1 ;
return 0 ;
}
static void F_10 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
int V_31 = V_32 ;
int V_8 ;
int V_33 , V_34 ;
int V_35 , V_36 ;
int V_37 ;
int V_38 ;
int V_39 ;
int V_40 , V_41 , V_42 ;
int V_43 , V_44 ;
int V_45 ;
static const int V_46 [ 4 ] = {
V_47 , V_48 ,
V_49 , V_50
} ;
static const int V_51 [ 4 ] = {
V_52 , V_53 ,
V_54 , V_55
} ;
static const int V_56 [ 4 ] = { 0 , 100 , 0 , 0 } ;
struct V_13 V_14 ;
T_3 V_57 [ 123 ] ;
T_3 V_58 [ 123 ] ;
T_3 V_59 ;
int V_60 ;
int V_61 ;
bool V_62 = F_11 ( V_4 ) ;
memset ( & V_57 , 0 , sizeof( T_3 ) * 123 ) ;
memset ( & V_58 , 0 , sizeof( T_3 ) * 123 ) ;
F_2 ( V_2 , V_4 , & V_14 ) ;
V_8 = V_14 . V_16 ;
V_2 -> V_63 . V_64 = V_65 ;
for ( V_45 = 0 ; V_45 < V_66 ; V_45 ++ ) {
V_61 = V_2 -> V_24 -> V_67 ( V_2 , V_45 , V_62 ) ;
if ( V_32 == V_61 )
break;
if ( V_62 )
V_61 = ( V_61 / 10 ) + V_68 ;
else
V_61 = ( V_61 / 10 ) + V_69 ;
V_61 = V_61 - V_8 ;
if ( F_12 ( V_4 ) ) {
if ( ( V_61 > - V_70 ) &&
( V_61 < V_70 ) ) {
V_31 = V_61 ;
break;
}
} else if ( ( V_61 > - V_71 ) &&
( V_61 < V_71 ) ) {
V_31 = V_61 ;
break;
}
}
if ( V_32 == V_31 ) {
F_13 ( V_2 , V_72 ,
V_73 ) ;
return;
} else {
F_13 ( V_2 , V_72 ,
V_73 ) ;
}
V_33 = V_31 * 320 ;
V_43 = F_3 ( V_2 , F_14 ( 0 ) ) ;
F_15 ( V_2 ) ;
V_44 = V_43 | ( V_74 |
V_75 |
V_76 |
V_77 ) ;
F_7 ( V_2 , F_14 ( 0 ) , V_44 ) ;
V_44 = ( V_78 |
V_79 |
V_80 |
V_81 |
F_16 ( V_82 , V_83 ) ) ;
F_7 ( V_2 , V_84 , V_44 ) ;
if ( F_12 ( V_4 ) ) {
if ( V_31 < 0 ) {
V_36 = 1 ;
V_35 = V_31 + 10 ;
} else {
V_36 = 0 ;
V_35 = V_31 - 10 ;
}
} else {
V_36 = 0 ;
V_35 = V_31 ;
}
if ( F_12 ( V_4 ) )
V_38 =
( ( V_31 * 262144 ) /
10 ) & V_85 ;
else
V_38 =
( ( V_31 * 524288 ) /
10 ) & V_85 ;
V_39 = F_11 ( V_4 ) ? 44 : 40 ;
V_37 = ( ( V_35 * 2048 ) / V_39 ) & 0x3ff ;
V_44 = ( V_86 |
F_16 ( V_37 , V_87 ) |
F_16 ( V_38 , V_85 ) ) ;
F_7 ( V_2 , V_88 , V_44 ) ;
V_44 = V_36 << V_89 ;
F_7 ( V_2 , V_90 , V_44 ) ;
V_34 = - 6000 ;
V_40 = V_33 + 100 ;
V_41 = V_33 - 100 ;
for ( V_45 = 0 ; V_45 < 4 ; V_45 ++ ) {
int V_91 = 0 ;
int V_92 = 0 ;
int V_93 = 0 ;
for ( V_93 = 0 ; V_93 < 30 ; V_93 ++ ) {
if ( ( V_34 > V_41 ) && ( V_34 < V_40 ) ) {
V_91 = V_91 | 0x1 << V_93 ;
V_92 = V_92 | 0x1 << V_93 ;
}
V_34 += 100 ;
}
V_34 += V_56 [ V_45 ] ;
F_7 ( V_2 , V_46 [ V_45 ] , V_91 ) ;
F_7 ( V_2 , V_51 [ V_45 ] , V_92 ) ;
}
V_42 = 6100 ;
V_40 = V_33 + 120 ;
V_41 = V_33 - 120 ;
for ( V_45 = 0 ; V_45 < 123 ; V_45 ++ ) {
if ( ( V_42 > V_41 ) && ( V_42 < V_40 ) ) {
volatile int V_94 = abs ( V_42 - V_33 ) ;
if ( V_94 < 75 )
V_59 = 1 ;
else
V_59 = 0 ;
if ( V_42 < 0 )
V_57 [ abs ( V_42 / 100 ) ] = V_59 ;
else
V_58 [ V_42 / 100 ] = V_59 ;
}
V_42 -= 100 ;
}
V_60 = ( V_57 [ 46 ] << 30 ) | ( V_57 [ 47 ] << 28 )
| ( V_57 [ 48 ] << 26 ) | ( V_57 [ 49 ] << 24 )
| ( V_57 [ 50 ] << 22 ) | ( V_57 [ 51 ] << 20 )
| ( V_57 [ 52 ] << 18 ) | ( V_57 [ 53 ] << 16 )
| ( V_57 [ 54 ] << 14 ) | ( V_57 [ 55 ] << 12 )
| ( V_57 [ 56 ] << 10 ) | ( V_57 [ 57 ] << 8 )
| ( V_57 [ 58 ] << 6 ) | ( V_57 [ 59 ] << 4 )
| ( V_57 [ 60 ] << 2 ) | ( V_57 [ 61 ] << 0 ) ;
F_7 ( V_2 , V_95 , V_60 ) ;
F_7 ( V_2 , V_96 , V_60 ) ;
V_60 = ( V_57 [ 31 ] << 28 )
| ( V_57 [ 32 ] << 26 ) | ( V_57 [ 33 ] << 24 )
| ( V_57 [ 34 ] << 22 ) | ( V_57 [ 35 ] << 20 )
| ( V_57 [ 36 ] << 18 ) | ( V_57 [ 37 ] << 16 )
| ( V_57 [ 48 ] << 14 ) | ( V_57 [ 39 ] << 12 )
| ( V_57 [ 40 ] << 10 ) | ( V_57 [ 41 ] << 8 )
| ( V_57 [ 42 ] << 6 ) | ( V_57 [ 43 ] << 4 )
| ( V_57 [ 44 ] << 2 ) | ( V_57 [ 45 ] << 0 ) ;
F_7 ( V_2 , V_97 , V_60 ) ;
F_7 ( V_2 , V_98 , V_60 ) ;
V_60 = ( V_57 [ 16 ] << 30 ) | ( V_57 [ 16 ] << 28 )
| ( V_57 [ 18 ] << 26 ) | ( V_57 [ 18 ] << 24 )
| ( V_57 [ 20 ] << 22 ) | ( V_57 [ 20 ] << 20 )
| ( V_57 [ 22 ] << 18 ) | ( V_57 [ 22 ] << 16 )
| ( V_57 [ 24 ] << 14 ) | ( V_57 [ 24 ] << 12 )
| ( V_57 [ 25 ] << 10 ) | ( V_57 [ 26 ] << 8 )
| ( V_57 [ 27 ] << 6 ) | ( V_57 [ 28 ] << 4 )
| ( V_57 [ 29 ] << 2 ) | ( V_57 [ 30 ] << 0 ) ;
F_7 ( V_2 , V_99 , V_60 ) ;
F_7 ( V_2 , V_100 , V_60 ) ;
V_60 = ( V_57 [ 0 ] << 30 ) | ( V_57 [ 1 ] << 28 )
| ( V_57 [ 2 ] << 26 ) | ( V_57 [ 3 ] << 24 )
| ( V_57 [ 4 ] << 22 ) | ( V_57 [ 5 ] << 20 )
| ( V_57 [ 6 ] << 18 ) | ( V_57 [ 7 ] << 16 )
| ( V_57 [ 8 ] << 14 ) | ( V_57 [ 9 ] << 12 )
| ( V_57 [ 10 ] << 10 ) | ( V_57 [ 11 ] << 8 )
| ( V_57 [ 12 ] << 6 ) | ( V_57 [ 13 ] << 4 )
| ( V_57 [ 14 ] << 2 ) | ( V_57 [ 15 ] << 0 ) ;
F_7 ( V_2 , V_101 , V_60 ) ;
F_7 ( V_2 , V_102 , V_60 ) ;
V_60 = ( V_58 [ 15 ] << 28 )
| ( V_58 [ 14 ] << 26 ) | ( V_58 [ 13 ] << 24 )
| ( V_58 [ 12 ] << 22 ) | ( V_58 [ 11 ] << 20 )
| ( V_58 [ 10 ] << 18 ) | ( V_58 [ 9 ] << 16 )
| ( V_58 [ 8 ] << 14 ) | ( V_58 [ 7 ] << 12 )
| ( V_58 [ 6 ] << 10 ) | ( V_58 [ 5 ] << 8 )
| ( V_58 [ 4 ] << 6 ) | ( V_58 [ 3 ] << 4 )
| ( V_58 [ 2 ] << 2 ) | ( V_58 [ 1 ] << 0 ) ;
F_7 ( V_2 , V_103 , V_60 ) ;
F_7 ( V_2 , V_104 , V_60 ) ;
V_60 = ( V_58 [ 30 ] << 28 )
| ( V_58 [ 29 ] << 26 ) | ( V_58 [ 28 ] << 24 )
| ( V_58 [ 27 ] << 22 ) | ( V_58 [ 26 ] << 20 )
| ( V_58 [ 25 ] << 18 ) | ( V_58 [ 24 ] << 16 )
| ( V_58 [ 23 ] << 14 ) | ( V_58 [ 22 ] << 12 )
| ( V_58 [ 21 ] << 10 ) | ( V_58 [ 20 ] << 8 )
| ( V_58 [ 19 ] << 6 ) | ( V_58 [ 18 ] << 4 )
| ( V_58 [ 17 ] << 2 ) | ( V_58 [ 16 ] << 0 ) ;
F_7 ( V_2 , V_105 , V_60 ) ;
F_7 ( V_2 , V_106 , V_60 ) ;
V_60 = ( V_58 [ 45 ] << 28 )
| ( V_58 [ 44 ] << 26 ) | ( V_58 [ 43 ] << 24 )
| ( V_58 [ 42 ] << 22 ) | ( V_58 [ 41 ] << 20 )
| ( V_58 [ 40 ] << 18 ) | ( V_58 [ 39 ] << 16 )
| ( V_58 [ 38 ] << 14 ) | ( V_58 [ 37 ] << 12 )
| ( V_58 [ 36 ] << 10 ) | ( V_58 [ 35 ] << 8 )
| ( V_58 [ 34 ] << 6 ) | ( V_58 [ 33 ] << 4 )
| ( V_58 [ 32 ] << 2 ) | ( V_58 [ 31 ] << 0 ) ;
F_7 ( V_2 , V_107 , V_60 ) ;
F_7 ( V_2 , V_108 , V_60 ) ;
V_60 = ( V_58 [ 61 ] << 30 ) | ( V_58 [ 60 ] << 28 )
| ( V_58 [ 59 ] << 26 ) | ( V_58 [ 58 ] << 24 )
| ( V_58 [ 57 ] << 22 ) | ( V_58 [ 56 ] << 20 )
| ( V_58 [ 55 ] << 18 ) | ( V_58 [ 54 ] << 16 )
| ( V_58 [ 53 ] << 14 ) | ( V_58 [ 52 ] << 12 )
| ( V_58 [ 51 ] << 10 ) | ( V_58 [ 50 ] << 8 )
| ( V_58 [ 49 ] << 6 ) | ( V_58 [ 48 ] << 4 )
| ( V_58 [ 47 ] << 2 ) | ( V_58 [ 46 ] << 0 ) ;
F_7 ( V_2 , V_109 , V_60 ) ;
F_7 ( V_2 , V_110 , V_60 ) ;
F_17 ( V_2 ) ;
}
static void F_18 ( struct V_1 * V_2 )
{
T_2 V_45 ;
if ( ! V_111 )
return;
if ( V_112 ) {
F_19 ( V_2 , V_113 ,
V_114 ) ;
F_20 ( V_2 , V_115 ,
V_116 ,
V_117 ,
V_118 ) ;
F_21 ( 100 ) ;
} else {
for ( V_45 = 0 ; V_45 < V_119 ; V_45 ++ )
V_2 -> V_120 [ V_45 ] =
F_22 ( F_3 ( V_2 , V_121 + V_45 * 4 ) ,
V_122 ) ;
V_2 -> V_123 = 0 ;
}
}
static T_2 F_23 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
T_2 V_124 ;
V_124 = F_16 ( 0x5 , V_125 ) ;
if ( V_4 && F_24 ( V_4 ) )
V_124 |= F_16 ( 0x1 , V_126 ) ;
else if ( V_4 && F_25 ( V_4 ) )
V_124 |= F_16 ( 0x2 , V_126 ) ;
if ( V_4 && F_26 ( V_4 ) ) {
if ( F_27 ( V_2 , V_4 ) )
V_124 = 0x142c ;
else if ( F_28 ( V_2 ) )
V_124 = 0x2850 ;
else
V_124 |= F_16 ( 0x28 , V_127 ) ;
} else {
V_124 |= F_16 ( 0x2c , V_127 ) ;
}
return V_124 ;
}
static void F_29 ( struct V_1 * V_2 ,
T_4 V_128 [ V_129 ] )
{
T_4 V_130 ;
V_130 = F_22 ( F_3 ( V_2 , V_131 ) , V_132 ) ;
V_128 [ 0 ] = F_30 ( V_130 , 8 ) ;
V_130 = F_22 ( F_3 ( V_2 , V_133 ) , V_134 ) ;
if ( F_12 ( V_2 -> V_29 ) )
V_128 [ 3 ] = F_30 ( V_130 , 8 ) ;
if ( F_31 ( V_2 ) || F_32 ( V_2 ) )
return;
V_130 = F_22 ( F_3 ( V_2 , V_135 ) , V_136 ) ;
V_128 [ 1 ] = F_30 ( V_130 , 8 ) ;
V_130 = F_22 ( F_3 ( V_2 , V_137 ) , V_138 ) ;
if ( F_12 ( V_2 -> V_29 ) )
V_128 [ 4 ] = F_30 ( V_130 , 8 ) ;
}
static void F_33 ( struct V_1 * V_2 )
{
if ( F_31 ( V_2 ) ) {
V_2 -> V_139 . V_140 = V_141 ;
V_2 -> V_139 . V_142 = V_143 ;
V_2 -> V_139 . V_144 = V_145 ;
} else if ( F_34 ( V_2 ) ) {
V_2 -> V_139 . V_140 = V_146 ;
V_2 -> V_139 . V_142 = V_147 ;
V_2 -> V_139 . V_144 = V_148 ;
} else if ( F_32 ( V_2 ) ) {
V_2 -> V_139 . V_140 = V_149 ;
V_2 -> V_139 . V_142 = V_150 ;
V_2 -> V_139 . V_144 = V_151 ;
} else {
V_2 -> V_139 . V_140 = V_152 ;
V_2 -> V_139 . V_142 = V_153 ;
V_2 -> V_139 . V_144 = V_154 ;
V_2 -> V_155 . V_140 = V_156 ;
V_2 -> V_155 . V_142 = V_157 ;
V_2 -> V_155 . V_144 = V_158 ;
}
}
static void F_35 ( struct V_1 * V_2 ,
struct V_159 * V_160 )
{
T_2 V_161 ;
V_161 = F_3 ( V_2 , V_162 ) ;
V_160 -> V_163 = ( V_161 & V_164 ) >>
V_165 ;
V_160 -> V_166 = ( V_161 & V_167 ) >>
V_168 ;
V_160 -> V_169 = ( V_161 & V_170 ) >>
V_171 ;
V_160 -> V_172 = - 3 ;
V_160 -> V_173 = 0 ;
}
static void F_36 ( struct V_1 * V_2 ,
struct V_159 * V_160 )
{
T_2 V_161 ;
V_161 = F_3 ( V_2 , V_162 ) ;
V_161 &= ~ ( V_164 |
V_167 |
V_170 ) ;
V_161 |= ( ( V_160 -> V_163 << V_165 )
& V_164 ) ;
V_161 |= ( ( V_160 -> V_166 << V_168 )
& V_167 ) ;
V_161 |= ( ( V_160 -> V_169 << V_171 )
& V_170 ) ;
F_7 ( V_2 , V_162 , V_161 ) ;
}
void F_37 ( struct V_1 * V_2 )
{
struct V_174 * V_175 = F_38 ( V_2 ) ;
struct V_176 * V_177 = F_39 ( V_2 ) ;
V_175 -> V_178 = NULL ;
V_175 -> V_179 = NULL ;
V_175 -> V_180 = NULL ;
V_175 -> V_181 = F_1 ;
V_175 -> V_182 = F_10 ;
V_175 -> V_183 = F_18 ;
V_175 -> V_184 = F_23 ;
V_175 -> V_185 = F_29 ;
V_177 -> V_186 = F_35 ;
V_177 -> V_187 = F_36 ;
F_33 ( V_2 ) ;
}
