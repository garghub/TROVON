static inline int F_1 ( int V_1 )
{
static const int V_2 [] = {
0 , 32000 , 44100 , 48000 , 64000 , 88200 ,
96000 , 128000 , 176400 , 192000 } ;
if ( V_1 < 1 || V_1 > 9 )
return 0 ;
return V_2 [ V_1 ] ;
}
static inline void F_2 ( struct V_3 * V_3 , unsigned int V_4 ,
unsigned int V_5 )
{
F_3 ( V_5 , V_3 -> V_6 + V_4 ) ;
}
static inline unsigned int F_4 ( struct V_3 * V_3 , unsigned int V_4 )
{
return F_5 ( V_3 -> V_6 + V_4 ) ;
}
static inline int F_6 ( struct V_3 * V_3 , unsigned int V_7 ,
unsigned int V_8 )
{
if ( V_7 >= V_9 || V_8 >= V_9 )
return 0 ;
return V_3 -> V_10 -> V_11 [ V_7 ] . V_8 [ V_8 ] ;
}
static inline int F_7 ( struct V_3 * V_3 , unsigned int V_7 ,
unsigned int V_12 )
{
if ( V_7 >= V_9 || V_12 >= V_9 )
return 0 ;
return V_3 -> V_10 -> V_11 [ V_7 ] . V_12 [ V_12 ] ;
}
static int F_8 ( struct V_3 * V_3 , unsigned int V_7 ,
unsigned int V_8 , unsigned short V_13 )
{
if ( V_7 >= V_9 || V_8 >= V_9 )
return - 1 ;
F_2 ( V_3 ,
V_14 +
( ( V_8 + 128 * V_7 ) * sizeof( V_15 ) ) ,
( V_3 -> V_10 -> V_11 [ V_7 ] . V_8 [ V_8 ] = V_13 & 0xFFFF ) ) ;
return 0 ;
}
static int F_9 ( struct V_3 * V_3 , unsigned int V_7 ,
unsigned int V_12 , unsigned short V_13 )
{
if ( V_7 >= V_9 || V_12 >= V_9 )
return - 1 ;
F_2 ( V_3 ,
V_14 +
( ( 64 + V_12 + 128 * V_7 ) * sizeof( V_15 ) ) ,
( V_3 -> V_10 -> V_11 [ V_7 ] . V_12 [ V_12 ] = V_13 & 0xFFFF ) ) ;
return 0 ;
}
static inline void F_10 ( struct V_3 * V_3 , int V_16 , int V_17 )
{
F_2 ( V_3 , V_18 + ( 4 * V_16 ) , V_17 ) ;
}
static inline void F_11 ( struct V_3 * V_3 , int V_16 , int V_17 )
{
F_2 ( V_3 , V_19 + ( 4 * V_16 ) , V_17 ) ;
}
static int F_12 ( struct V_3 * V_3 )
{
unsigned long V_20 ;
int V_21 = 1 ;
F_13 ( & V_3 -> V_22 , V_20 ) ;
if ( ( V_3 -> V_23 != V_3 -> V_24 ) &&
( V_3 -> V_23 >= 0 ) && ( V_3 -> V_24 >= 0 ) ) {
V_21 = 0 ;
}
F_14 ( & V_3 -> V_22 , V_20 ) ;
return V_21 ;
}
static int F_15 ( struct V_3 * V_3 )
{
unsigned int V_25 , V_26 , V_27 ;
int V_28 , V_29 = 0 , V_30 ;
switch ( V_3 -> V_31 ) {
case V_32 :
V_26 = F_4 ( V_3 , V_33 ) ;
V_25 = F_4 ( V_3 , V_34 ) ;
V_27 = F_4 ( V_3 , V_35 ) ;
V_28 = F_16 ( V_3 ) ;
if ( V_28 == V_36 &&
V_25 & V_37 )
return F_1 ( ( V_25 >> V_38 ) & 0xF ) ;
if ( V_28 >= V_39 &&
V_28 <= V_40 &&
V_26 & ( V_41 >>
( V_28 - V_39 ) ) )
return F_1 ( ( V_27 >> ( 4 * ( V_28 - V_39 ) ) ) & 0xF ) ;
return 0 ;
break;
case V_42 :
V_25 = F_4 ( V_3 , V_34 ) ;
if ( ! ( V_25 & V_43 ) ) {
V_29 = 0 ;
} else {
switch ( V_25 & ( V_44 ) ) {
case V_45 * 1 :
V_29 = 32000 ; break;
case V_45 * 2 :
V_29 = 44100 ; break;
case V_45 * 3 :
V_29 = 48000 ; break;
case V_45 * 4 :
V_29 = 64000 ; break;
case V_45 * 5 :
V_29 = 88200 ; break;
case V_45 * 6 :
V_29 = 96000 ; break;
case V_45 * 7 :
V_29 = 128000 ; break;
case V_45 * 8 :
V_29 = 176400 ; break;
case V_45 * 9 :
V_29 = 192000 ; break;
default:
V_29 = 0 ; break;
}
}
break;
case V_46 :
case V_47 :
case V_48 :
V_26 = F_4 ( V_3 , V_33 ) ;
V_25 = F_4 ( V_3 , V_34 ) ;
V_29 = 0 ;
if ( ( V_26 & V_49 ) != 0 &&
( V_26 & V_50 ) == 0 ) {
V_30 = V_26 & V_51 ;
switch ( V_30 ) {
case V_52 :
V_29 = 32000 ;
break;
case V_53 :
V_29 = 44100 ;
break;
case V_54 :
V_29 = 48000 ;
break;
case V_55 :
V_29 = 64000 ;
break;
case V_56 :
V_29 = 88200 ;
break;
case V_57 :
V_29 = 96000 ;
break;
default:
V_29 = 0 ;
break;
}
}
if ( V_29 != 0 &&
( V_26 & V_58 ) == V_59 )
return V_29 ;
if ( V_25 & V_43 ) {
V_30 = V_25 & V_60 ;
switch ( V_30 ) {
case V_61 :
V_29 = 32000 ;
break;
case V_62 :
V_29 = 44100 ;
break;
case V_63 :
V_29 = 48000 ;
break;
case V_64 :
V_29 = 64000 ;
break;
case V_65 :
V_29 = 88200 ;
break;
case V_66 :
V_29 = 96000 ;
break;
case V_67 :
V_29 = 128000 ;
break;
case V_68 :
V_29 = 176400 ;
break;
case V_69 :
V_29 = 192000 ;
break;
default:
V_29 = 0 ;
break;
}
}
break;
}
return V_29 ;
}
static inline void F_17 ( struct V_3 * V_3 )
{
V_3 -> V_70 = 1 << ( ( F_18 ( V_3 -> V_71 ) + 8 ) ) ;
}
static T_1 F_19 ( struct V_3 * V_3 )
{
int V_72 ;
V_72 = F_4 ( V_3 , V_34 ) ;
switch ( V_3 -> V_31 ) {
case V_48 :
case V_47 :
V_72 &= V_73 ;
V_72 /= 4 ;
break;
default:
V_72 = ( V_72 & V_74 ) ?
( V_3 -> V_70 / 4 ) : 0 ;
}
return V_72 ;
}
static inline void F_20 ( struct V_3 * V_75 )
{
V_75 -> V_71 |= ( V_76 | V_77 ) ;
F_2 ( V_75 , V_78 , V_75 -> V_71 ) ;
}
static inline void F_21 ( struct V_3 * V_75 )
{
V_75 -> V_71 &= ~ ( V_77 | V_76 ) ;
F_2 ( V_75 , V_78 , V_75 -> V_71 ) ;
}
static void F_22 ( struct V_3 * V_3 )
{
int V_16 ;
int V_1 = V_3 -> V_70 ;
void * V_79 = V_3 -> V_80 ;
if ( V_79 == NULL )
return;
for ( V_16 = 0 ; V_16 < V_81 ; V_16 ++ ) {
memset ( V_79 , 0 , V_1 ) ;
V_79 += V_82 ;
}
}
static int F_23 ( struct V_3 * V_75 , unsigned int V_83 )
{
int V_1 ;
F_24 ( & V_75 -> V_22 ) ;
V_83 >>= 7 ;
V_1 = 0 ;
while ( V_83 ) {
V_1 ++ ;
V_83 >>= 1 ;
}
V_75 -> V_71 &= ~ V_84 ;
V_75 -> V_71 |= F_25 ( V_1 ) ;
F_2 ( V_75 , V_78 , V_75 -> V_71 ) ;
F_17 ( V_75 ) ;
F_26 ( & V_75 -> V_22 ) ;
return 0 ;
}
static T_2 F_27 ( struct V_3 * V_3 , T_2 V_85 )
{
T_2 V_86 ;
if ( V_85 == 0 )
return 0 ;
switch ( V_3 -> V_31 ) {
case V_46 :
case V_32 :
V_86 = 110069313433624ULL ;
break;
case V_48 :
case V_47 :
V_86 = 104857600000000ULL ;
break;
case V_42 :
V_86 = 131072000000000ULL ;
}
return F_28 ( V_86 , V_85 ) ;
}
static void F_29 ( struct V_3 * V_3 , int V_29 )
{
T_2 V_1 ;
if ( V_29 >= 112000 )
V_29 /= 4 ;
else if ( V_29 >= 56000 )
V_29 /= 2 ;
switch ( V_3 -> V_31 ) {
case V_42 :
V_1 = 131072000000000ULL ;
break;
case V_46 :
case V_32 :
V_1 = 110069313433624ULL ;
break;
case V_48 :
case V_47 :
V_1 = 104857600000000ULL ;
break;
}
V_1 = F_28 ( V_1 , V_29 ) ;
F_30 ( V_1 >> 32 ) ;
F_2 ( V_3 , V_87 , ( V_15 ) V_1 ) ;
}
static int F_31 ( struct V_3 * V_3 , int V_29 , int V_88 )
{
int V_89 ;
int V_30 ;
int V_90 = 0 ;
int V_91 , V_92 ;
if ( ! ( V_3 -> V_71 & V_93 ) ) {
if ( V_88 ) {
F_32 ( V_94 L_1
L_2
L_3 ) ;
V_90 = 1 ;
} else {
int V_95 =
F_15 ( V_3 ) ;
if ( F_16 ( V_3 ) ==
V_96 ) {
F_32 ( V_94 L_1
L_4 ) ;
V_90 = 1 ;
} else if ( V_29 != V_95 ) {
F_32 ( V_94 L_1
L_5
L_6 ) ;
V_90 = 1 ;
}
}
}
V_89 = V_3 -> V_97 ;
if ( V_89 <= 48000 )
V_91 = V_98 ;
else if ( V_89 <= 96000 )
V_91 = V_99 ;
else
V_91 = V_100 ;
if ( V_29 <= 48000 )
V_92 = V_98 ;
else if ( V_29 <= 96000 )
V_92 = V_99 ;
else
V_92 = V_100 ;
switch ( V_29 ) {
case 32000 :
V_30 = V_101 ;
break;
case 44100 :
V_30 = V_102 ;
break;
case 48000 :
V_30 = V_103 ;
break;
case 64000 :
V_30 = V_104 ;
break;
case 88200 :
V_30 = V_105 ;
break;
case 96000 :
V_30 = V_106 ;
break;
case 128000 :
V_30 = V_107 ;
break;
case 176400 :
V_30 = V_108 ;
break;
case 192000 :
V_30 = V_109 ;
break;
default:
return - V_110 ;
}
if ( V_91 != V_92
&& ( V_3 -> V_24 >= 0 || V_3 -> V_23 >= 0 ) ) {
F_32
( V_111 L_1
L_7
L_8 ,
V_112 [ V_91 ] ,
V_112 [ V_92 ] ,
V_3 -> V_24 , V_3 -> V_23 ) ;
return - V_113 ;
}
V_3 -> V_71 &= ~ V_114 ;
V_3 -> V_71 |= V_30 ;
F_2 ( V_3 , V_78 , V_3 -> V_71 ) ;
F_29 ( V_3 , V_29 ) ;
if ( V_32 == V_3 -> V_31 && V_29 != V_89 )
F_2 ( V_3 , V_115 , 0 ) ;
V_3 -> V_97 = V_29 ;
if ( V_29 <= 48000 ) {
V_3 -> V_116 = V_3 -> V_117 ;
V_3 -> V_118 = V_3 -> V_119 ;
V_3 -> V_120 = V_3 -> V_121 ;
V_3 -> V_122 = V_3 -> V_123 ;
V_3 -> V_124 = V_3 -> V_125 ;
V_3 -> V_126 = V_3 -> V_127 ;
} else if ( V_29 <= 96000 ) {
V_3 -> V_116 = V_3 -> V_128 ;
V_3 -> V_118 = V_3 -> V_129 ;
V_3 -> V_120 = V_3 -> V_130 ;
V_3 -> V_122 = V_3 -> V_131 ;
V_3 -> V_124 = V_3 -> V_132 ;
V_3 -> V_126 = V_3 -> V_133 ;
} else {
V_3 -> V_116 = V_3 -> V_134 ;
V_3 -> V_118 = V_3 -> V_135 ;
V_3 -> V_120 = V_3 -> V_136 ;
V_3 -> V_122 = V_3 -> V_137 ;
V_3 -> V_124 = V_3 -> V_138 ;
V_3 -> V_126 = V_3 -> V_139 ;
}
if ( V_90 != 0 )
return - 1 ;
return 0 ;
}
static void F_33 ( struct V_3 * V_3 , int V_140 )
{
int V_16 , V_141 ;
unsigned int V_142 ;
if ( V_140 > V_143 )
V_142 = V_143 ;
else if ( V_140 < 0 )
V_142 = 0 ;
else
V_142 = V_140 ;
for ( V_16 = 0 ; V_16 < V_9 ; V_16 ++ )
for ( V_141 = 0 ; V_141 < V_9 ; V_141 ++ ) {
F_8 ( V_3 , V_16 , V_141 , V_142 ) ;
F_9 ( V_3 , V_16 , V_141 , V_142 ) ;
}
}
static inline unsigned char F_34 ( struct V_3 * V_3 ,
int V_144 )
{
return F_4 ( V_3 , V_3 -> V_145 [ V_144 ] . V_146 ) ;
}
static inline void F_35 ( struct V_3 * V_3 , int V_144 ,
int V_5 )
{
return F_2 ( V_3 , V_3 -> V_145 [ V_144 ] . V_147 , V_5 ) ;
}
static inline int F_36 ( struct V_3 * V_3 , int V_144 )
{
return F_4 ( V_3 , V_3 -> V_145 [ V_144 ] . V_148 ) & 0xFF ;
}
static inline int F_37 ( struct V_3 * V_3 , int V_144 )
{
int V_149 ;
V_149 = F_4 ( V_3 , V_3 -> V_145 [ V_144 ] . V_150 ) & 0xFF ;
if ( V_149 < 128 )
return 128 - V_149 ;
else
return 0 ;
}
static void F_38 ( struct V_3 * V_3 , int V_144 )
{
while ( F_36 ( V_3 , V_144 ) )
F_34 ( V_3 , V_144 ) ;
}
static int F_39 ( struct V_151 * V_152 )
{
unsigned long V_20 ;
int V_153 ;
int V_154 ;
int V_16 ;
unsigned char V_79 [ 128 ] ;
F_13 ( & V_152 -> V_22 , V_20 ) ;
if ( V_152 -> V_155 &&
! F_40 ( V_152 -> V_155 ) ) {
V_153 = F_37 ( V_152 -> V_3 ,
V_152 -> V_144 ) ;
if ( V_153 > 0 ) {
if ( V_153 > ( int ) sizeof ( V_79 ) )
V_153 = sizeof ( V_79 ) ;
V_154 = F_41 ( V_152 -> V_155 , V_79 ,
V_153 ) ;
if ( V_154 > 0 ) {
for ( V_16 = 0 ; V_16 < V_154 ; ++ V_16 )
F_35 ( V_152 -> V_3 ,
V_152 -> V_144 ,
V_79 [ V_16 ] ) ;
}
}
}
F_14 ( & V_152 -> V_22 , V_20 ) ;
return 0 ;
}
static int F_42 ( struct V_151 * V_152 )
{
unsigned char V_79 [ 128 ] ;
unsigned long V_20 ;
int V_153 ;
int V_16 ;
F_13 ( & V_152 -> V_22 , V_20 ) ;
V_153 = F_36 ( V_152 -> V_3 , V_152 -> V_144 ) ;
if ( V_153 > 0 ) {
if ( V_152 -> V_156 ) {
if ( V_153 > ( int ) sizeof ( V_79 ) )
V_153 = sizeof ( V_79 ) ;
for ( V_16 = 0 ; V_16 < V_153 ; ++ V_16 )
V_79 [ V_16 ] = F_34 ( V_152 -> V_3 ,
V_152 -> V_144 ) ;
if ( V_153 )
F_43 ( V_152 -> V_156 , V_79 ,
V_153 ) ;
} else {
while ( V_153 -- )
F_34 ( V_152 -> V_3 ,
V_152 -> V_144 ) ;
}
}
V_152 -> V_157 = 0 ;
F_14 ( & V_152 -> V_22 , V_20 ) ;
F_13 ( & V_152 -> V_3 -> V_22 , V_20 ) ;
V_152 -> V_3 -> V_71 |= V_152 -> V_158 ;
F_2 ( V_152 -> V_3 , V_78 ,
V_152 -> V_3 -> V_71 ) ;
F_14 ( & V_152 -> V_3 -> V_22 , V_20 ) ;
return F_39 ( V_152 ) ;
}
static void
F_44 ( struct V_159 * V_160 , int V_161 )
{
struct V_3 * V_3 ;
struct V_151 * V_152 ;
unsigned long V_20 ;
V_152 = V_160 -> V_162 -> V_163 ;
V_3 = V_152 -> V_3 ;
F_13 ( & V_3 -> V_22 , V_20 ) ;
if ( V_161 ) {
if ( ! ( V_3 -> V_71 & V_152 -> V_158 ) ) {
F_38 ( V_3 , V_152 -> V_144 ) ;
V_3 -> V_71 |= V_152 -> V_158 ;
}
} else {
V_3 -> V_71 &= ~ V_152 -> V_158 ;
}
F_2 ( V_3 , V_78 , V_3 -> V_71 ) ;
F_14 ( & V_3 -> V_22 , V_20 ) ;
}
static void F_45 ( unsigned long V_13 )
{
struct V_151 * V_152 = (struct V_151 * ) V_13 ;
unsigned long V_20 ;
F_39 ( V_152 ) ;
F_13 ( & V_152 -> V_22 , V_20 ) ;
if ( V_152 -> V_164 ) {
V_152 -> V_165 . V_166 = 1 + V_167 ;
F_46 ( & V_152 -> V_165 ) ;
}
F_14 ( & V_152 -> V_22 , V_20 ) ;
}
static void
F_47 ( struct V_159 * V_160 , int V_161 )
{
struct V_151 * V_152 ;
unsigned long V_20 ;
V_152 = V_160 -> V_162 -> V_163 ;
F_13 ( & V_152 -> V_22 , V_20 ) ;
if ( V_161 ) {
if ( ! V_152 -> V_164 ) {
F_48 ( & V_152 -> V_165 ) ;
V_152 -> V_165 . V_168 = F_45 ;
V_152 -> V_165 . V_13 = ( unsigned long ) V_152 ;
V_152 -> V_165 . V_166 = 1 + V_167 ;
F_46 ( & V_152 -> V_165 ) ;
V_152 -> V_164 ++ ;
}
} else {
if ( V_152 -> V_164 && -- V_152 -> V_164 <= 0 )
F_49 ( & V_152 -> V_165 ) ;
}
F_14 ( & V_152 -> V_22 , V_20 ) ;
if ( V_161 )
F_39 ( V_152 ) ;
}
static int F_50 ( struct V_159 * V_160 )
{
struct V_151 * V_152 ;
V_152 = V_160 -> V_162 -> V_163 ;
F_24 ( & V_152 -> V_22 ) ;
F_38 ( V_152 -> V_3 , V_152 -> V_144 ) ;
V_152 -> V_156 = V_160 ;
F_26 ( & V_152 -> V_22 ) ;
return 0 ;
}
static int F_51 ( struct V_159 * V_160 )
{
struct V_151 * V_152 ;
V_152 = V_160 -> V_162 -> V_163 ;
F_24 ( & V_152 -> V_22 ) ;
V_152 -> V_155 = V_160 ;
F_26 ( & V_152 -> V_22 ) ;
return 0 ;
}
static int F_52 ( struct V_159 * V_160 )
{
struct V_151 * V_152 ;
F_44 ( V_160 , 0 ) ;
V_152 = V_160 -> V_162 -> V_163 ;
F_24 ( & V_152 -> V_22 ) ;
V_152 -> V_156 = NULL ;
F_26 ( & V_152 -> V_22 ) ;
return 0 ;
}
static int F_53 ( struct V_159 * V_160 )
{
struct V_151 * V_152 ;
F_47 ( V_160 , 0 ) ;
V_152 = V_160 -> V_162 -> V_163 ;
F_24 ( & V_152 -> V_22 ) ;
V_152 -> V_155 = NULL ;
F_26 ( & V_152 -> V_22 ) ;
return 0 ;
}
static int T_3 F_54 ( struct V_169 * V_170 ,
struct V_3 * V_3 , int V_144 )
{
int V_171 ;
char V_79 [ 32 ] ;
V_3 -> V_145 [ V_144 ] . V_144 = V_144 ;
V_3 -> V_145 [ V_144 ] . V_3 = V_3 ;
F_55 ( & V_3 -> V_145 [ V_144 ] . V_22 ) ;
if ( 0 == V_144 ) {
if ( V_42 == V_3 -> V_31 ) {
V_3 -> V_145 [ 0 ] . V_146 = V_172 ;
V_3 -> V_145 [ 0 ] . V_148 = V_173 ;
V_3 -> V_145 [ 0 ] . V_147 = V_174 ;
V_3 -> V_145 [ 0 ] . V_150 = V_175 ;
V_3 -> V_145 [ 0 ] . V_158 = V_176 ;
V_3 -> V_145 [ 0 ] . V_177 = V_178 ;
} else {
V_3 -> V_145 [ 0 ] . V_146 = V_179 ;
V_3 -> V_145 [ 0 ] . V_148 = V_180 ;
V_3 -> V_145 [ 0 ] . V_147 = V_181 ;
V_3 -> V_145 [ 0 ] . V_150 = V_182 ;
V_3 -> V_145 [ 0 ] . V_158 = V_183 ;
V_3 -> V_145 [ 0 ] . V_177 = V_184 ;
}
} else if ( 1 == V_144 ) {
V_3 -> V_145 [ 1 ] . V_146 = V_185 ;
V_3 -> V_145 [ 1 ] . V_148 = V_186 ;
V_3 -> V_145 [ 1 ] . V_147 = V_187 ;
V_3 -> V_145 [ 1 ] . V_150 = V_188 ;
V_3 -> V_145 [ 1 ] . V_158 = V_189 ;
V_3 -> V_145 [ 1 ] . V_177 = V_190 ;
} else if ( ( 2 == V_144 ) && ( V_46 == V_3 -> V_31 ) ) {
V_3 -> V_145 [ 2 ] . V_146 = V_172 ;
V_3 -> V_145 [ 2 ] . V_148 = V_173 ;
V_3 -> V_145 [ 2 ] . V_147 = V_174 ;
V_3 -> V_145 [ 2 ] . V_150 = V_175 ;
V_3 -> V_145 [ 2 ] . V_158 = V_176 ;
V_3 -> V_145 [ 2 ] . V_177 = V_178 ;
} else if ( 2 == V_144 ) {
V_3 -> V_145 [ 2 ] . V_146 = V_172 ;
V_3 -> V_145 [ 2 ] . V_148 = V_173 ;
V_3 -> V_145 [ 2 ] . V_147 = - 1 ;
V_3 -> V_145 [ 2 ] . V_150 = - 1 ;
V_3 -> V_145 [ 2 ] . V_158 = V_176 ;
V_3 -> V_145 [ 2 ] . V_177 = V_191 ;
} else if ( 3 == V_144 ) {
V_3 -> V_145 [ 3 ] . V_146 = V_192 ;
V_3 -> V_145 [ 3 ] . V_148 = V_193 ;
V_3 -> V_145 [ 3 ] . V_147 = - 1 ;
V_3 -> V_145 [ 3 ] . V_150 = - 1 ;
V_3 -> V_145 [ 3 ] . V_158 = V_194 ;
V_3 -> V_145 [ 3 ] . V_177 = V_195 ;
}
if ( ( V_144 < 2 ) || ( ( 2 == V_144 ) && ( ( V_46 == V_3 -> V_31 ) ||
( V_42 == V_3 -> V_31 ) ) ) ) {
if ( ( V_144 == 0 ) && ( V_42 == V_3 -> V_31 ) ) {
sprintf ( V_79 , L_9 , V_170 -> V_196 ) ;
} else if ( ( V_144 == 2 ) && ( V_46 == V_3 -> V_31 ) ) {
sprintf ( V_79 , L_9 , V_170 -> V_196 ) ;
} else {
sprintf ( V_79 , L_10 , V_170 -> V_196 , V_144 + 1 ) ;
}
V_171 = F_56 ( V_170 , V_79 , V_144 , 1 , 1 ,
& V_3 -> V_145 [ V_144 ] . V_162 ) ;
if ( V_171 < 0 )
return V_171 ;
sprintf ( V_3 -> V_145 [ V_144 ] . V_162 -> V_197 , L_10 ,
V_170 -> V_144 , V_144 + 1 ) ;
V_3 -> V_145 [ V_144 ] . V_162 -> V_163 = & V_3 -> V_145 [ V_144 ] ;
F_57 ( V_3 -> V_145 [ V_144 ] . V_162 ,
V_198 ,
& V_199 ) ;
F_57 ( V_3 -> V_145 [ V_144 ] . V_162 ,
V_200 ,
& V_201 ) ;
V_3 -> V_145 [ V_144 ] . V_162 -> V_202 |=
V_203 |
V_204 |
V_205 ;
} else {
sprintf ( V_79 , L_11 , V_170 -> V_196 , V_144 + 1 ) ;
V_171 = F_56 ( V_170 , V_79 , V_144 , 1 , 1 ,
& V_3 -> V_145 [ V_144 ] . V_162 ) ;
if ( V_171 < 0 )
return V_171 ;
sprintf ( V_3 -> V_145 [ V_144 ] . V_162 -> V_197 ,
L_11 , V_170 -> V_144 , V_144 + 1 ) ;
V_3 -> V_145 [ V_144 ] . V_162 -> V_163 = & V_3 -> V_145 [ V_144 ] ;
F_57 ( V_3 -> V_145 [ V_144 ] . V_162 ,
V_200 ,
& V_201 ) ;
V_3 -> V_145 [ V_144 ] . V_162 -> V_202 |= V_204 ;
}
return 0 ;
}
static void F_58 ( unsigned long V_206 )
{
struct V_3 * V_3 = (struct V_3 * ) V_206 ;
int V_16 = 0 ;
while ( V_16 < V_3 -> V_207 ) {
if ( V_3 -> V_145 [ V_16 ] . V_157 )
F_42 ( & V_3 -> V_145 [ V_16 ] ) ;
V_16 ++ ;
}
}
static int F_59 ( struct V_3 * V_3 )
{
unsigned int V_85 , V_29 ;
V_85 = F_4 ( V_3 , V_208 ) ;
V_29 = F_27 ( V_3 , V_85 ) ;
return V_29 ;
}
static int F_60 ( struct V_209 * V_210 ,
struct V_211 * V_212 )
{
V_212 -> type = V_213 ;
V_212 -> V_214 = 1 ;
V_212 -> V_215 . integer . V_216 = 27000 ;
V_212 -> V_215 . integer . V_217 = 207000 ;
V_212 -> V_215 . integer . V_218 = 1 ;
return 0 ;
}
static int F_61 ( struct V_209 * V_210 ,
struct V_219 *
V_220 )
{
struct V_3 * V_3 = F_62 ( V_210 ) ;
V_220 -> V_215 . integer . V_215 [ 0 ] = F_59 ( V_3 ) ;
return 0 ;
}
static int F_63 ( struct V_3 * V_3 )
{
int V_25 ;
switch ( V_3 -> V_31 ) {
case V_48 :
case V_47 :
V_25 = F_4 ( V_3 , V_221 ) ;
return ( V_25 >> 16 ) & 0xF ;
break;
default:
break;
}
return 0 ;
}
static int F_64 ( struct V_3 * V_3 )
{
int V_25 ;
if ( V_3 -> V_222 ) {
switch ( V_3 -> V_31 ) {
case V_48 :
case V_47 :
V_25 = F_4 ( V_3 , V_221 ) ;
return ( V_25 >> 20 ) & 0xF ;
break;
default:
break;
}
}
return 0 ;
}
static int F_65 ( struct V_3 * V_3 )
{
int V_25 ;
if ( V_3 -> V_222 ) {
switch ( V_3 -> V_31 ) {
case V_48 :
case V_47 :
V_25 = F_4 ( V_3 , V_223 ) ;
return ( V_25 >> 12 ) & 0xF ;
break;
default:
break;
}
}
return 0 ;
}
static int F_66 ( struct V_3 * V_3 , unsigned int V_224 )
{
int V_25 = F_4 ( V_3 , V_223 ) ;
return ( V_25 >> ( V_224 * 4 ) ) & 0xF ;
}
static int F_67 ( struct V_209 * V_210 ,
struct V_211 * V_212 )
{
V_212 -> type = V_225 ;
V_212 -> V_214 = 1 ;
V_212 -> V_215 . V_226 . V_227 = 10 ;
if ( V_212 -> V_215 . V_226 . V_228 >= V_212 -> V_215 . V_226 . V_227 )
V_212 -> V_215 . V_226 . V_228 = V_212 -> V_215 . V_226 . V_227 - 1 ;
strcpy ( V_212 -> V_215 . V_226 . V_197 ,
V_229 [ V_212 -> V_215 . V_226 . V_228 ] ) ;
return 0 ;
}
static int F_68 ( struct V_209 * V_210 ,
struct V_219 *
V_220 )
{
struct V_3 * V_3 = F_62 ( V_210 ) ;
switch ( V_3 -> V_31 ) {
case V_48 :
switch ( V_210 -> V_230 ) {
case 0 :
V_220 -> V_215 . V_226 . V_228 [ 0 ] =
F_63 ( V_3 ) ;
break;
case 7 :
V_220 -> V_215 . V_226 . V_228 [ 0 ] =
F_64 ( V_3 ) ;
break;
case 8 :
V_220 -> V_215 . V_226 . V_228 [ 0 ] =
F_65 ( V_3 ) ;
break;
default:
V_220 -> V_215 . V_226 . V_228 [ 0 ] =
F_66 ( V_3 ,
V_210 -> V_230 - 1 ) ;
}
case V_47 :
switch ( V_210 -> V_230 ) {
case 0 :
V_220 -> V_215 . V_226 . V_228 [ 0 ] =
F_63 ( V_3 ) ;
break;
case 4 :
V_220 -> V_215 . V_226 . V_228 [ 0 ] =
F_64 ( V_3 ) ;
break;
case 5 :
V_220 -> V_215 . V_226 . V_228 [ 0 ] =
F_65 ( V_3 ) ;
break;
default:
V_220 -> V_215 . V_226 . V_228 [ 0 ] =
F_66 ( V_3 ,
V_220 -> V_144 . V_231 - 1 ) ;
}
case V_32 :
switch ( V_210 -> V_230 ) {
case 0 :
V_220 -> V_215 . V_226 . V_228 [ 0 ] =
F_63 ( V_3 ) ;
break;
case 9 :
V_220 -> V_215 . V_226 . V_228 [ 0 ] =
F_64 ( V_3 ) ;
break;
case 10 :
V_220 -> V_215 . V_226 . V_228 [ 0 ] =
F_65 ( V_3 ) ;
break;
default:
V_220 -> V_215 . V_226 . V_228 [ 0 ] =
F_66 ( V_3 ,
V_210 -> V_230 - 1 ) ;
break;
}
default:
break;
}
return 0 ;
}
static int F_69 ( struct V_3 * V_3 )
{
switch ( V_3 -> V_31 ) {
case V_47 :
case V_48 :
if ( V_3 -> V_232 & V_233 )
return 0 ;
break;
default:
if ( V_3 -> V_71 & V_93 )
return 0 ;
}
return 1 ;
}
static void F_70 ( struct V_3 * V_3 , int V_234 )
{
switch ( V_3 -> V_31 ) {
case V_47 :
case V_48 :
if ( 0 == V_234 )
V_3 -> V_232 |= V_233 ;
else
V_3 -> V_232 &= ~ V_233 ;
F_2 ( V_3 , V_235 , V_3 -> V_232 ) ;
break;
default:
if ( 0 == V_234 )
V_3 -> V_71 |= V_93 ;
else
V_3 -> V_71 &= ~ V_93 ;
F_2 ( V_3 , V_78 ,
V_3 -> V_71 ) ;
}
}
static int F_71 ( struct V_209 * V_210 ,
struct V_211 * V_212 )
{
static char * V_236 [] = { L_12 , L_13 } ;
V_212 -> type = V_225 ;
V_212 -> V_214 = 1 ;
V_212 -> V_215 . V_226 . V_227 = 2 ;
if ( V_212 -> V_215 . V_226 . V_228 >= V_212 -> V_215 . V_226 . V_227 )
V_212 -> V_215 . V_226 . V_228 =
V_212 -> V_215 . V_226 . V_227 - 1 ;
strcpy ( V_212 -> V_215 . V_226 . V_197 ,
V_236 [ V_212 -> V_215 . V_226 . V_228 ] ) ;
return 0 ;
}
static int F_72 ( struct V_209 * V_210 ,
struct V_219 * V_220 )
{
struct V_3 * V_3 = F_62 ( V_210 ) ;
V_220 -> V_215 . V_226 . V_228 [ 0 ] = F_69 ( V_3 ) ;
return 0 ;
}
static int F_73 ( struct V_209 * V_210 ,
struct V_219 * V_220 )
{
struct V_3 * V_3 = F_62 ( V_210 ) ;
int V_5 ;
if ( ! F_12 ( V_3 ) )
return - V_113 ;
V_5 = V_220 -> V_215 . V_226 . V_228 [ 0 ] ;
if ( V_5 < 0 )
V_5 = 0 ;
else if ( V_5 > 1 )
V_5 = 1 ;
F_70 ( V_3 , V_5 ) ;
return 0 ;
}
static int F_74 ( struct V_3 * V_3 )
{
switch ( V_3 -> V_97 ) {
case 32000 : return 0 ;
case 44100 : return 1 ;
case 48000 : return 2 ;
case 64000 : return 3 ;
case 88200 : return 4 ;
case 96000 : return 5 ;
case 128000 : return 6 ;
case 176400 : return 7 ;
case 192000 : return 8 ;
}
return - 1 ;
}
static int F_75 ( struct V_3 * V_3 , int V_234 )
{
int V_29 ;
switch ( V_234 ) {
case 0 :
V_29 = 32000 ; break;
case 1 :
V_29 = 44100 ; break;
case 2 :
V_29 = 48000 ; break;
case 3 :
V_29 = 64000 ; break;
case 4 :
V_29 = 88200 ; break;
case 5 :
V_29 = 96000 ; break;
case 6 :
V_29 = 128000 ; break;
case 7 :
V_29 = 176400 ; break;
case 8 :
V_29 = 192000 ; break;
default:
V_29 = 48000 ;
}
F_31 ( V_3 , V_29 , 1 ) ;
return 0 ;
}
static int F_76 ( struct V_209 * V_210 ,
struct V_211 * V_212 )
{
V_212 -> type = V_225 ;
V_212 -> V_214 = 1 ;
V_212 -> V_215 . V_226 . V_227 = 9 ;
if ( V_212 -> V_215 . V_226 . V_228 >= V_212 -> V_215 . V_226 . V_227 )
V_212 -> V_215 . V_226 . V_228 =
V_212 -> V_215 . V_226 . V_227 - 1 ;
strcpy ( V_212 -> V_215 . V_226 . V_197 ,
V_229 [ V_212 -> V_215 . V_226 . V_228 + 1 ] ) ;
return 0 ;
}
static int F_77 ( struct V_209 * V_210 ,
struct V_219 * V_220 )
{
struct V_3 * V_3 = F_62 ( V_210 ) ;
V_220 -> V_215 . V_226 . V_228 [ 0 ] = F_74 ( V_3 ) ;
return 0 ;
}
static int F_78 ( struct V_209 * V_210 ,
struct V_219 * V_220 )
{
struct V_3 * V_3 = F_62 ( V_210 ) ;
int V_237 ;
int V_5 ;
if ( ! F_12 ( V_3 ) )
return - V_113 ;
V_5 = V_220 -> V_215 . V_226 . V_228 [ 0 ] ;
if ( V_5 < 0 )
V_5 = 0 ;
if ( V_5 > 9 )
V_5 = 9 ;
F_24 ( & V_3 -> V_22 ) ;
if ( V_5 != F_74 ( V_3 ) )
V_237 = ( F_75 ( V_3 , V_5 ) == 0 ) ? 1 : 0 ;
else
V_237 = 0 ;
F_26 ( & V_3 -> V_22 ) ;
return V_237 ;
}
static int F_79 ( struct V_3 * V_3 )
{
switch ( V_3 -> V_31 ) {
case V_32 :
switch ( V_3 -> V_71 & V_238 ) {
case 0 : return 0 ;
case V_239 : return 1 ;
case V_240 : return 2 ;
case V_240 + V_239 : return 3 ;
case V_241 : return 4 ;
case V_241 + V_239 : return 5 ;
case V_241 + V_240 : return 6 ;
case V_241 + V_240 + V_239 :
return 7 ;
case V_242 : return 8 ;
case V_242 + V_239 : return 9 ;
}
break;
case V_46 :
case V_42 :
if ( V_3 -> V_222 ) {
switch ( V_3 -> V_71 & V_238 ) {
case 0 : return 0 ;
case V_239 : return 1 ;
case V_240 : return 2 ;
case V_240 + V_239 :
return 3 ;
}
} else {
switch ( V_3 -> V_71 & V_238 ) {
case 0 : return 0 ;
case V_239 : return 1 ;
case V_240 + V_239 :
return 2 ;
}
}
break;
case V_48 :
if ( V_3 -> V_222 ) {
switch ( ( V_3 -> V_232 &
V_243 ) / V_244 ) {
case 0 : return 0 ;
case 3 : return 1 ;
case 4 : return 2 ;
case 5 : return 3 ;
case 6 : return 4 ;
case 1 : return 5 ;
case 2 : return 6 ;
case 9 : return 7 ;
case 10 : return 8 ;
}
} else {
switch ( ( V_3 -> V_232 &
V_243 ) / V_244 ) {
case 0 : return 0 ;
case 3 : return 1 ;
case 4 : return 2 ;
case 5 : return 3 ;
case 6 : return 4 ;
case 1 : return 5 ;
case 2 : return 6 ;
case 10 : return 7 ;
}
}
break;
case V_47 :
if ( V_3 -> V_222 ) {
switch ( ( V_3 -> V_232 &
V_243 ) / V_244 ) {
case 0 : return 0 ;
case 3 : return 1 ;
case 1 : return 2 ;
case 2 : return 3 ;
case 9 : return 4 ;
case 10 : return 5 ;
}
} else {
switch ( ( V_3 -> V_232 &
V_243 ) / V_244 ) {
case 0 : return 0 ;
case 3 : return 1 ;
case 1 : return 2 ;
case 2 : return 3 ;
case 10 : return 4 ;
}
}
break;
}
return - 1 ;
}
static int F_80 ( struct V_3 * V_3 , int V_245 )
{
int V_246 = 0 ;
switch ( V_3 -> V_31 ) {
case V_32 :
V_3 -> V_71 &= ~ V_238 ;
switch ( V_245 ) {
case 0 :
break;
case 1 :
V_3 -> V_71 |= V_239 ;
break;
case 2 :
V_3 -> V_71 |= V_240 ;
break;
case 3 :
V_3 -> V_71 |=
V_240 + V_239 ;
break;
case 4 :
V_3 -> V_71 |= V_241 ;
break;
case 5 :
V_3 -> V_71 |=
V_241 + V_239 ;
break;
case 6 :
V_3 -> V_71 |=
V_241 + V_240 ;
break;
case 7 :
V_3 -> V_71 |=
V_241 + V_240 + V_239 ;
break;
case 8 :
V_3 -> V_71 |= V_242 ;
break;
case 9 :
V_3 -> V_71 |=
V_242 + V_239 ;
break;
default:
return - 1 ;
}
break;
case V_46 :
case V_42 :
V_3 -> V_71 &= ~ V_238 ;
if ( V_3 -> V_222 ) {
switch ( V_245 ) {
case 0 :
break;
case 1 :
V_3 -> V_71 |= V_239 ;
break;
case 2 :
V_3 -> V_71 |= V_240 ;
break;
case 3 :
V_3 -> V_71 |=
V_239 + V_240 ;
break;
default:
return - 1 ;
}
} else {
switch ( V_245 ) {
case 0 :
break;
case 1 :
V_3 -> V_71 |= V_239 ;
break;
case 2 :
V_3 -> V_71 |=
V_239 + V_240 ;
break;
default:
return - 1 ;
}
}
break;
case V_48 :
if ( V_3 -> V_222 ) {
switch ( V_245 ) {
case 0 : V_246 = 0 ; break;
case 1 : V_246 = 3 ; break;
case 2 : V_246 = 4 ; break;
case 3 : V_246 = 5 ; break;
case 4 : V_246 = 6 ; break;
case 5 : V_246 = 1 ; break;
case 6 : V_246 = 2 ; break;
case 7 : V_246 = 9 ; break;
case 8 : V_246 = 10 ; break;
default: return - 1 ;
}
} else {
switch ( V_245 ) {
case 0 : V_246 = 0 ; break;
case 1 : V_246 = 3 ; break;
case 2 : V_246 = 4 ; break;
case 3 : V_246 = 5 ; break;
case 4 : V_246 = 6 ; break;
case 5 : V_246 = 1 ; break;
case 6 : V_246 = 2 ; break;
case 7 : V_246 = 10 ; break;
default: return - 1 ;
}
}
break;
case V_47 :
if ( V_3 -> V_222 ) {
switch ( V_245 ) {
case 0 : V_246 = 0 ; break;
case 1 : V_246 = 3 ; break;
case 2 : V_246 = 1 ; break;
case 3 : V_246 = 2 ; break;
case 4 : V_246 = 9 ; break;
case 5 : V_246 = 10 ; break;
default: return - 1 ;
}
} else {
switch ( V_245 ) {
case 0 : V_246 = 0 ; break;
case 1 : V_246 = 3 ; break;
case 2 : V_246 = 1 ; break;
case 3 : V_246 = 2 ; break;
case 4 : V_246 = 10 ; break;
default: return - 1 ;
}
}
break;
}
switch ( V_3 -> V_31 ) {
case V_48 :
case V_47 :
V_3 -> V_232 &= ~ V_243 ;
V_3 -> V_232 |= V_244 * V_246 ;
F_2 ( V_3 , V_235 , V_3 -> V_232 ) ;
break;
case V_46 :
case V_42 :
case V_32 :
F_2 ( V_3 , V_78 ,
V_3 -> V_71 ) ;
}
return 0 ;
}
static int F_81 ( struct V_209 * V_210 ,
struct V_211 * V_212 )
{
struct V_3 * V_3 = F_62 ( V_210 ) ;
V_212 -> type = V_225 ;
V_212 -> V_214 = 1 ;
V_212 -> V_215 . V_226 . V_227 = V_3 -> V_247 ;
if ( V_212 -> V_215 . V_226 . V_228 >= V_212 -> V_215 . V_226 . V_227 )
V_212 -> V_215 . V_226 . V_228 =
V_212 -> V_215 . V_226 . V_227 - 1 ;
strcpy ( V_212 -> V_215 . V_226 . V_197 ,
V_3 -> V_248 [ V_212 -> V_215 . V_226 . V_228 ] ) ;
return 0 ;
}
static int F_82 ( struct V_209 * V_210 ,
struct V_219 * V_220 )
{
struct V_3 * V_3 = F_62 ( V_210 ) ;
int V_249 = F_79 ( V_3 ) ;
if ( V_249 >= 0 ) {
V_220 -> V_215 . V_226 . V_228 [ 0 ] = V_249 ;
return 0 ;
}
return - 1 ;
}
static int F_83 ( struct V_209 * V_210 ,
struct V_219 * V_220 )
{
struct V_3 * V_3 = F_62 ( V_210 ) ;
int V_5 , V_237 = 0 ;
if ( ! F_12 ( V_3 ) )
return - V_113 ;
V_5 = V_220 -> V_215 . V_226 . V_228 [ 0 ] ;
if ( V_5 < 0 )
V_5 = 0 ;
else if ( V_5 >= V_3 -> V_247 )
V_5 = V_3 -> V_247 - 1 ;
F_24 ( & V_3 -> V_22 ) ;
if ( V_5 != F_79 ( V_3 ) )
V_237 = ( 0 == F_80 ( V_3 , V_5 ) ) ? 1 : 0 ;
F_26 ( & V_3 -> V_22 ) ;
return V_237 ;
}
static int F_16 ( struct V_3 * V_3 )
{
if ( V_32 == V_3 -> V_31 ) {
unsigned int V_25 = F_4 ( V_3 , V_34 ) ;
unsigned int V_28 =
( V_25 >> V_250 ) & 0xF ;
if ( V_28 == 0 )
return V_36 ;
if ( V_28 <= 8 )
return V_28 ;
return V_251 ;
} else if ( V_46 == V_3 -> V_31 ) {
unsigned int V_26 = F_4 ( V_3 , V_33 ) ;
switch ( V_26 & V_58 ) {
case V_59 :
return V_252 ;
case V_253 :
return V_254 ;
case V_255 :
return V_256 ;
case V_257 :
return V_258 ;
case V_259 :
return V_96 ;
default:
return 0 ;
}
}
return 0 ;
}
static int F_84 ( struct V_209 * V_210 ,
struct V_211 * V_212 )
{
struct V_3 * V_3 = F_62 ( V_210 ) ;
if ( V_32 == V_3 -> V_31 ) {
static char * V_236 [] = { L_14 , L_15 , L_16 , L_17 ,
L_18 , L_19 , L_20 , L_21 , L_22 , L_23 } ;
V_212 -> type = V_225 ;
V_212 -> V_214 = 1 ;
V_212 -> V_215 . V_226 . V_227 = 10 ;
if ( V_212 -> V_215 . V_226 . V_228 >=
V_212 -> V_215 . V_226 . V_227 )
V_212 -> V_215 . V_226 . V_228 =
V_212 -> V_215 . V_226 . V_227 - 1 ;
strcpy ( V_212 -> V_215 . V_226 . V_197 ,
V_236 [ V_212 -> V_215 . V_226 . V_228 ] ) ;
} else if ( V_46 == V_3 -> V_31 ) {
static char * V_236 [] = { L_24 , L_25 , L_26 ,
L_27 , L_23 } ;
V_212 -> type = V_225 ;
V_212 -> V_214 = 1 ;
V_212 -> V_215 . V_226 . V_227 = 5 ;
if ( V_212 -> V_215 . V_226 . V_228 >=
V_212 -> V_215 . V_226 . V_227 )
V_212 -> V_215 . V_226 . V_228 =
V_212 -> V_215 . V_226 . V_227 - 1 ;
strcpy ( V_212 -> V_215 . V_226 . V_197 ,
V_236 [ V_212 -> V_215 . V_226 . V_228 ] ) ;
}
return 0 ;
}
static int F_85 ( struct V_209 * V_210 ,
struct V_219 * V_220 )
{
struct V_3 * V_3 = F_62 ( V_210 ) ;
V_220 -> V_215 . V_226 . V_228 [ 0 ] = F_16 ( V_3 ) ;
return 0 ;
}
static int F_86 ( struct V_3 * V_3 )
{
return ( V_3 -> V_71 & V_260 ) ? 1 : 0 ;
}
static int F_87 ( struct V_3 * V_3 , int V_261 )
{
if ( V_261 )
V_3 -> V_71 |= V_260 ;
else
V_3 -> V_71 &= ~ V_260 ;
F_2 ( V_3 , V_78 , V_3 -> V_71 ) ;
return 0 ;
}
static int F_88 ( struct V_209 * V_210 ,
struct V_219 * V_220 )
{
struct V_3 * V_3 = F_62 ( V_210 ) ;
F_24 ( & V_3 -> V_22 ) ;
V_220 -> V_215 . integer . V_215 [ 0 ] = F_86 ( V_3 ) ;
F_26 ( & V_3 -> V_22 ) ;
return 0 ;
}
static int F_89 ( struct V_209 * V_210 ,
struct V_219 * V_220 )
{
struct V_3 * V_3 = F_62 ( V_210 ) ;
int V_237 ;
unsigned int V_5 ;
if ( ! F_12 ( V_3 ) )
return - V_113 ;
V_5 = V_220 -> V_215 . integer . V_215 [ 0 ] & 1 ;
F_24 ( & V_3 -> V_22 ) ;
V_237 = ( int ) V_5 != F_86 ( V_3 ) ;
F_87 ( V_3 , V_5 ) ;
F_26 ( & V_3 -> V_22 ) ;
return V_237 ;
}
static int F_90 ( struct V_3 * V_3 )
{
return ( V_3 -> V_71 & V_262 ) ? 1 : 0 ;
}
static int F_91 ( struct V_3 * V_3 , int V_261 )
{
if ( V_261 )
V_3 -> V_71 |= V_262 ;
else
V_3 -> V_71 &= ~ V_262 ;
F_2 ( V_3 , V_78 , V_3 -> V_71 ) ;
return 0 ;
}
static int F_92 ( struct V_209 * V_210 ,
struct V_219 * V_220 )
{
struct V_3 * V_3 = F_62 ( V_210 ) ;
F_24 ( & V_3 -> V_22 ) ;
V_220 -> V_215 . integer . V_215 [ 0 ] = F_90 ( V_3 ) ;
F_26 ( & V_3 -> V_22 ) ;
return 0 ;
}
static int F_93 ( struct V_209 * V_210 ,
struct V_219 * V_220 )
{
struct V_3 * V_3 = F_62 ( V_210 ) ;
int V_237 ;
unsigned int V_5 ;
if ( ! F_12 ( V_3 ) )
return - V_113 ;
V_5 = V_220 -> V_215 . integer . V_215 [ 0 ] & 1 ;
F_24 ( & V_3 -> V_22 ) ;
V_237 = ( int ) V_5 != F_90 ( V_3 ) ;
F_91 ( V_3 , V_5 ) ;
F_26 ( & V_3 -> V_22 ) ;
return V_237 ;
}
static int F_94 ( struct V_3 * V_3 )
{
return ( V_3 -> V_71 & V_263 ) ? 1 : 0 ;
}
static int F_95 ( struct V_3 * V_3 , int V_261 )
{
if ( V_261 )
V_3 -> V_71 |= V_263 ;
else
V_3 -> V_71 &= ~ V_263 ;
F_2 ( V_3 , V_78 , V_3 -> V_71 ) ;
return 0 ;
}
static int F_96 ( struct V_209 * V_210 ,
struct V_219 * V_220 )
{
struct V_3 * V_3 = F_62 ( V_210 ) ;
F_24 ( & V_3 -> V_22 ) ;
V_220 -> V_215 . integer . V_215 [ 0 ] = F_94 ( V_3 ) ;
F_26 ( & V_3 -> V_22 ) ;
return 0 ;
}
static int F_97 ( struct V_209 * V_210 ,
struct V_219 * V_220 )
{
struct V_3 * V_3 = F_62 ( V_210 ) ;
int V_237 ;
unsigned int V_5 ;
if ( ! F_12 ( V_3 ) )
return - V_113 ;
V_5 = V_220 -> V_215 . integer . V_215 [ 0 ] & 1 ;
F_24 ( & V_3 -> V_22 ) ;
V_237 = ( int ) V_5 != F_94 ( V_3 ) ;
F_95 ( V_3 , V_5 ) ;
F_26 ( & V_3 -> V_22 ) ;
return V_237 ;
}
static int F_98 ( struct V_3 * V_3 )
{
return ( V_3 -> V_71 & V_264 ) ? 1 : 0 ;
}
static int F_99 ( struct V_3 * V_3 , int V_261 )
{
if ( V_261 )
V_3 -> V_71 |= V_264 ;
else
V_3 -> V_71 &= ~ V_264 ;
F_2 ( V_3 , V_78 , V_3 -> V_71 ) ;
return 0 ;
}
static int F_100 ( struct V_209 * V_210 ,
struct V_219 * V_220 )
{
struct V_3 * V_3 = F_62 ( V_210 ) ;
F_24 ( & V_3 -> V_22 ) ;
V_220 -> V_215 . integer . V_215 [ 0 ] = F_98 ( V_3 ) ;
F_26 ( & V_3 -> V_22 ) ;
return 0 ;
}
static int F_101 ( struct V_209 * V_210 ,
struct V_219 * V_220 )
{
struct V_3 * V_3 = F_62 ( V_210 ) ;
int V_237 ;
unsigned int V_5 ;
if ( ! F_12 ( V_3 ) )
return - V_113 ;
V_5 = V_220 -> V_215 . integer . V_215 [ 0 ] & 1 ;
F_24 ( & V_3 -> V_22 ) ;
V_237 = ( int ) V_5 != F_98 ( V_3 ) ;
F_99 ( V_3 , V_5 ) ;
F_26 ( & V_3 -> V_22 ) ;
return V_237 ;
}
static int F_102 ( struct V_3 * V_3 )
{
return ( V_3 -> V_71 & V_265 ) ? 1 : 0 ;
}
static int F_103 ( struct V_3 * V_3 , int V_266 )
{
if ( V_266 )
V_3 -> V_71 |= V_265 ;
else
V_3 -> V_71 &= ~ V_265 ;
F_2 ( V_3 , V_78 , V_3 -> V_71 ) ;
return 0 ;
}
static int F_104 ( struct V_209 * V_210 ,
struct V_219 * V_220 )
{
struct V_3 * V_3 = F_62 ( V_210 ) ;
F_24 ( & V_3 -> V_22 ) ;
V_220 -> V_215 . V_226 . V_228 [ 0 ] = F_102 ( V_3 ) ;
F_26 ( & V_3 -> V_22 ) ;
return 0 ;
}
static int F_105 ( struct V_209 * V_210 ,
struct V_219 * V_220 )
{
struct V_3 * V_3 = F_62 ( V_210 ) ;
int V_237 ;
unsigned int V_5 ;
if ( ! F_12 ( V_3 ) )
return - V_113 ;
V_5 = V_220 -> V_215 . integer . V_215 [ 0 ] & 1 ;
F_24 ( & V_3 -> V_22 ) ;
V_237 = ( int ) V_5 != F_102 ( V_3 ) ;
F_103 ( V_3 , V_5 ) ;
F_26 ( & V_3 -> V_22 ) ;
return V_237 ;
}
static int F_106 ( struct V_3 * V_3 )
{
return ( V_3 -> V_71 & V_267 ) ? 1 : 0 ;
}
static int F_107 ( struct V_3 * V_3 , int V_268 )
{
if ( V_268 )
V_3 -> V_71 |= V_267 ;
else
V_3 -> V_71 &= ~ V_267 ;
F_2 ( V_3 , V_78 , V_3 -> V_71 ) ;
return 0 ;
}
static int F_108 ( struct V_209 * V_210 ,
struct V_219 * V_220 )
{
struct V_3 * V_3 = F_62 ( V_210 ) ;
F_24 ( & V_3 -> V_22 ) ;
V_220 -> V_215 . V_226 . V_228 [ 0 ] = F_106 ( V_3 ) ;
F_26 ( & V_3 -> V_22 ) ;
return 0 ;
}
static int F_109 ( struct V_209 * V_210 ,
struct V_219 * V_220 )
{
struct V_3 * V_3 = F_62 ( V_210 ) ;
int V_237 ;
unsigned int V_5 ;
if ( ! F_12 ( V_3 ) )
return - V_113 ;
V_5 = V_220 -> V_215 . integer . V_215 [ 0 ] & 1 ;
F_24 ( & V_3 -> V_22 ) ;
V_237 = ( int ) V_5 != F_106 ( V_3 ) ;
F_107 ( V_3 , V_5 ) ;
F_26 ( & V_3 -> V_22 ) ;
return V_237 ;
}
static int F_110 ( struct V_3 * V_3 )
{
return ( V_3 -> V_71 & V_269 ) ? 1 : 0 ;
}
static int F_111 ( struct V_3 * V_3 , int V_268 )
{
if ( V_268 )
V_3 -> V_71 |= V_269 ;
else
V_3 -> V_71 &= ~ V_269 ;
F_2 ( V_3 , V_78 , V_3 -> V_71 ) ;
return 0 ;
}
static int F_112 ( struct V_209 * V_210 ,
struct V_219 * V_220 )
{
struct V_3 * V_3 = F_62 ( V_210 ) ;
F_24 ( & V_3 -> V_22 ) ;
V_220 -> V_215 . V_226 . V_228 [ 0 ] = F_110 ( V_3 ) ;
F_26 ( & V_3 -> V_22 ) ;
return 0 ;
}
static int F_113 ( struct V_209 * V_210 ,
struct V_219 * V_220 )
{
struct V_3 * V_3 = F_62 ( V_210 ) ;
int V_237 ;
unsigned int V_5 ;
if ( ! F_12 ( V_3 ) )
return - V_113 ;
V_5 = V_220 -> V_215 . integer . V_215 [ 0 ] & 1 ;
F_24 ( & V_3 -> V_22 ) ;
V_237 = ( int ) V_5 != F_110 ( V_3 ) ;
F_111 ( V_3 , V_5 ) ;
F_26 ( & V_3 -> V_22 ) ;
return V_237 ;
}
static int F_114 ( struct V_3 * V_3 )
{
return ( V_3 -> V_71 & V_270 ) ? 1 : 0 ;
}
static int F_115 ( struct V_3 * V_3 , int V_261 )
{
if ( V_261 )
V_3 -> V_71 |= V_270 ;
else
V_3 -> V_71 &= ~ V_270 ;
F_2 ( V_3 , V_78 , V_3 -> V_71 ) ;
return 0 ;
}
static int F_116 ( struct V_209 * V_210 ,
struct V_211 * V_212 )
{
static char * V_236 [] = { L_28 , L_29 } ;
V_212 -> type = V_225 ;
V_212 -> V_214 = 1 ;
V_212 -> V_215 . V_226 . V_227 = 2 ;
if ( V_212 -> V_215 . V_226 . V_228 >= V_212 -> V_215 . V_226 . V_227 )
V_212 -> V_215 . V_226 . V_228 =
V_212 -> V_215 . V_226 . V_227 - 1 ;
strcpy ( V_212 -> V_215 . V_226 . V_197 ,
V_236 [ V_212 -> V_215 . V_226 . V_228 ] ) ;
return 0 ;
}
static int F_117 ( struct V_209 * V_210 ,
struct V_219 * V_220 )
{
struct V_3 * V_3 = F_62 ( V_210 ) ;
F_24 ( & V_3 -> V_22 ) ;
V_220 -> V_215 . V_226 . V_228 [ 0 ] = F_114 ( V_3 ) ;
F_26 ( & V_3 -> V_22 ) ;
return 0 ;
}
static int F_118 ( struct V_209 * V_210 ,
struct V_219 * V_220 )
{
struct V_3 * V_3 = F_62 ( V_210 ) ;
int V_237 ;
unsigned int V_5 ;
if ( ! F_12 ( V_3 ) )
return - V_113 ;
V_5 = V_220 -> V_215 . integer . V_215 [ 0 ] & 1 ;
F_24 ( & V_3 -> V_22 ) ;
V_237 = ( int ) V_5 != F_114 ( V_3 ) ;
F_115 ( V_3 , V_5 ) ;
F_26 ( & V_3 -> V_22 ) ;
return V_237 ;
}
static int F_119 ( struct V_3 * V_3 )
{
return ( V_3 -> V_71 & V_271 ) ? 1 : 0 ;
}
static int F_120 ( struct V_3 * V_3 , int V_272 )
{
if ( V_272 )
V_3 -> V_71 |= V_271 ;
else
V_3 -> V_71 &= ~ V_271 ;
F_2 ( V_3 , V_78 , V_3 -> V_71 ) ;
return 0 ;
}
static int F_121 ( struct V_209 * V_210 ,
struct V_211 * V_212 )
{
static char * V_236 [] = { L_30 , L_31 } ;
V_212 -> type = V_225 ;
V_212 -> V_214 = 1 ;
V_212 -> V_215 . V_226 . V_227 = 2 ;
if ( V_212 -> V_215 . V_226 . V_228 >= V_212 -> V_215 . V_226 . V_227 )
V_212 -> V_215 . V_226 . V_228 =
V_212 -> V_215 . V_226 . V_227 - 1 ;
strcpy ( V_212 -> V_215 . V_226 . V_197 ,
V_236 [ V_212 -> V_215 . V_226 . V_228 ] ) ;
return 0 ;
}
static int F_122 ( struct V_209 * V_210 ,
struct V_219 * V_220 )
{
struct V_3 * V_3 = F_62 ( V_210 ) ;
F_24 ( & V_3 -> V_22 ) ;
V_220 -> V_215 . V_226 . V_228 [ 0 ] = F_119 ( V_3 ) ;
F_26 ( & V_3 -> V_22 ) ;
return 0 ;
}
static int F_123 ( struct V_209 * V_210 ,
struct V_219 * V_220 )
{
struct V_3 * V_3 = F_62 ( V_210 ) ;
int V_237 ;
unsigned int V_5 ;
if ( ! F_12 ( V_3 ) )
return - V_113 ;
V_5 = V_220 -> V_215 . integer . V_215 [ 0 ] & 1 ;
F_24 ( & V_3 -> V_22 ) ;
V_237 = ( int ) V_5 != F_119 ( V_3 ) ;
F_120 ( V_3 , V_5 ) ;
F_26 ( & V_3 -> V_22 ) ;
return V_237 ;
}
static int F_124 ( struct V_3 * V_3 )
{
if ( V_3 -> V_71 & V_273 )
return 1 ;
if ( V_3 -> V_71 & V_274 )
return 2 ;
return 0 ;
}
static int F_125 ( struct V_3 * V_3 , int V_234 )
{
V_3 -> V_71 &= ~ ( V_273 | V_274 ) ;
switch ( V_234 ) {
case 0 :
break;
case 1 :
V_3 -> V_71 |= V_273 ;
break;
case 2 :
V_3 -> V_71 |= V_274 ;
break;
}
F_2 ( V_3 , V_78 , V_3 -> V_71 ) ;
return 0 ;
}
static int F_126 ( struct V_209 * V_210 ,
struct V_211 * V_212 )
{
static char * V_236 [] = { L_30 , L_31 , L_32 } ;
V_212 -> type = V_225 ;
V_212 -> V_214 = 1 ;
V_212 -> V_215 . V_226 . V_227 = 3 ;
if ( V_212 -> V_215 . V_226 . V_228 >= V_212 -> V_215 . V_226 . V_227 )
V_212 -> V_215 . V_226 . V_228 =
V_212 -> V_215 . V_226 . V_227 - 1 ;
strcpy ( V_212 -> V_215 . V_226 . V_197 ,
V_236 [ V_212 -> V_215 . V_226 . V_228 ] ) ;
return 0 ;
}
static int F_127 ( struct V_209 * V_210 ,
struct V_219 * V_220 )
{
struct V_3 * V_3 = F_62 ( V_210 ) ;
F_24 ( & V_3 -> V_22 ) ;
V_220 -> V_215 . V_226 . V_228 [ 0 ] = F_124 ( V_3 ) ;
F_26 ( & V_3 -> V_22 ) ;
return 0 ;
}
static int F_128 ( struct V_209 * V_210 ,
struct V_219 * V_220 )
{
struct V_3 * V_3 = F_62 ( V_210 ) ;
int V_237 ;
int V_5 ;
if ( ! F_12 ( V_3 ) )
return - V_113 ;
V_5 = V_220 -> V_215 . integer . V_215 [ 0 ] ;
if ( V_5 < 0 )
V_5 = 0 ;
if ( V_5 > 2 )
V_5 = 2 ;
F_24 ( & V_3 -> V_22 ) ;
V_237 = V_5 != F_124 ( V_3 ) ;
F_125 ( V_3 , V_5 ) ;
F_26 ( & V_3 -> V_22 ) ;
return V_237 ;
}
static int F_129 ( struct V_209 * V_210 ,
struct V_211 * V_212 )
{
V_212 -> type = V_213 ;
V_212 -> V_214 = 3 ;
V_212 -> V_215 . integer . V_216 = 0 ;
V_212 -> V_215 . integer . V_217 = 65535 ;
V_212 -> V_215 . integer . V_218 = 1 ;
return 0 ;
}
static int F_130 ( struct V_209 * V_210 ,
struct V_219 * V_220 )
{
struct V_3 * V_3 = F_62 ( V_210 ) ;
int V_275 ;
int V_276 ;
V_275 = V_220 -> V_215 . integer . V_215 [ 0 ] ;
if ( V_275 < 0 )
V_275 = 0 ;
else if ( V_275 >= 2 * V_81 )
V_275 = 2 * V_81 - 1 ;
V_276 = V_220 -> V_215 . integer . V_215 [ 1 ] ;
if ( V_276 < 0 )
V_276 = 0 ;
else if ( V_276 >= V_81 )
V_276 = V_81 - 1 ;
F_24 ( & V_3 -> V_22 ) ;
if ( V_275 >= V_81 )
V_220 -> V_215 . integer . V_215 [ 2 ] =
F_7 ( V_3 , V_276 ,
V_275 - V_81 ) ;
else
V_220 -> V_215 . integer . V_215 [ 2 ] =
F_6 ( V_3 , V_276 , V_275 ) ;
F_26 ( & V_3 -> V_22 ) ;
return 0 ;
}
static int F_131 ( struct V_209 * V_210 ,
struct V_219 * V_220 )
{
struct V_3 * V_3 = F_62 ( V_210 ) ;
int V_237 ;
int V_275 ;
int V_276 ;
int V_142 ;
if ( ! F_12 ( V_3 ) )
return - V_113 ;
V_275 = V_220 -> V_215 . integer . V_215 [ 0 ] ;
V_276 = V_220 -> V_215 . integer . V_215 [ 1 ] ;
if ( V_275 < 0 || V_275 >= 2 * V_81 )
return - 1 ;
if ( V_276 < 0 || V_276 >= V_81 )
return - 1 ;
V_142 = V_220 -> V_215 . integer . V_215 [ 2 ] ;
F_24 ( & V_3 -> V_22 ) ;
if ( V_275 >= V_81 )
V_237 = V_142 != F_7 ( V_3 , V_276 ,
V_275 -
V_81 ) ;
else
V_237 = V_142 != F_6 ( V_3 , V_276 ,
V_275 ) ;
if ( V_237 ) {
if ( V_275 >= V_81 )
F_9 ( V_3 , V_276 ,
V_275 - V_81 ,
V_142 ) ;
else
F_8 ( V_3 , V_276 , V_275 ,
V_142 ) ;
}
F_26 ( & V_3 -> V_22 ) ;
return V_237 ;
}
static int F_132 ( struct V_209 * V_210 ,
struct V_211 * V_212 )
{
V_212 -> type = V_213 ;
V_212 -> V_214 = 1 ;
V_212 -> V_215 . integer . V_216 = 0 ;
V_212 -> V_215 . integer . V_217 = 64 ;
V_212 -> V_215 . integer . V_218 = 1 ;
return 0 ;
}
static int F_133 ( struct V_209 * V_210 ,
struct V_219 * V_220 )
{
struct V_3 * V_3 = F_62 ( V_210 ) ;
int V_277 ;
V_277 = V_220 -> V_144 . V_231 - 1 ;
if ( F_30 ( V_277 < 0 || V_277 >= V_81 ) )
return - V_110 ;
F_24 ( & V_3 -> V_22 ) ;
V_220 -> V_215 . integer . V_215 [ 0 ] =
( F_7 ( V_3 , V_277 , V_277 ) * 64 ) / V_143 ;
F_26 ( & V_3 -> V_22 ) ;
return 0 ;
}
static int F_134 ( struct V_209 * V_210 ,
struct V_219 * V_220 )
{
struct V_3 * V_3 = F_62 ( V_210 ) ;
int V_237 ;
int V_277 ;
int V_142 ;
if ( ! F_12 ( V_3 ) )
return - V_113 ;
V_277 = V_220 -> V_144 . V_231 - 1 ;
if ( F_30 ( V_277 < 0 || V_277 >= V_81 ) )
return - V_110 ;
V_142 = V_220 -> V_215 . integer . V_215 [ 0 ] * V_143 / 64 ;
F_24 ( & V_3 -> V_22 ) ;
V_237 =
V_142 != F_7 ( V_3 , V_277 ,
V_277 ) ;
if ( V_237 )
F_9 ( V_3 , V_277 , V_277 ,
V_142 ) ;
F_26 ( & V_3 -> V_22 ) ;
return V_237 ;
}
static int F_135 ( struct V_209 * V_210 ,
struct V_211 * V_212 )
{
static char * V_236 [] = { L_33 , L_34 , L_35 , L_36 } ;
V_212 -> type = V_225 ;
V_212 -> V_214 = 1 ;
V_212 -> V_215 . V_226 . V_227 = 4 ;
if ( V_212 -> V_215 . V_226 . V_228 >= V_212 -> V_215 . V_226 . V_227 )
V_212 -> V_215 . V_226 . V_228 =
V_212 -> V_215 . V_226 . V_227 - 1 ;
strcpy ( V_212 -> V_215 . V_226 . V_197 ,
V_236 [ V_212 -> V_215 . V_226 . V_228 ] ) ;
return 0 ;
}
static int F_136 ( struct V_3 * V_3 )
{
int V_25 , V_26 ;
switch ( V_3 -> V_31 ) {
case V_32 :
V_25 = F_4 ( V_3 , V_34 ) ;
if ( V_25 & V_278 )
return 2 ;
else if ( V_25 & V_49 )
return 1 ;
return 0 ;
break;
case V_46 :
V_26 = F_4 ( V_3 , V_33 ) ;
if ( V_26 & V_49 ) {
if ( V_26 & V_278 )
return 2 ;
else
return 1 ;
}
return 0 ;
break;
case V_48 :
case V_47 :
V_25 = F_4 ( V_3 , V_34 ) ;
if ( V_25 & 0x2000000 )
return 2 ;
else if ( V_25 & 0x1000000 )
return 1 ;
return 0 ;
break;
case V_42 :
break;
}
return 3 ;
}
static int F_137 ( struct V_3 * V_3 )
{
int V_25 = F_4 ( V_3 , V_34 ) ;
if ( V_25 & V_43 ) {
if ( V_25 & V_279 )
return 2 ;
else
return 1 ;
}
return 0 ;
}
static int F_138 ( struct V_3 * V_3 , int V_224 )
{
int V_25 , V_22 , V_280 ;
V_25 = F_4 ( V_3 , V_221 ) ;
V_22 = ( V_25 & ( 0x1 << V_224 ) ) ? 1 : 0 ;
V_280 = ( V_25 & ( 0x100 << V_224 ) ) ? 1 : 0 ;
if ( V_22 && V_280 )
return 2 ;
else if ( V_22 )
return 1 ;
return 0 ;
}
static int F_139 ( struct V_3 * V_3 )
{
int V_25 , V_22 = 0 , V_280 = 0 ;
switch ( V_3 -> V_31 ) {
case V_48 :
case V_47 :
V_25 = F_4 ( V_3 , V_281 ) ;
V_22 = ( V_25 & 0x400 ) ? 1 : 0 ;
V_280 = ( V_25 & 0x800 ) ? 1 : 0 ;
break;
case V_46 :
case V_32 :
V_25 = F_4 ( V_3 , V_33 ) ;
V_22 = ( V_25 & V_282 ) ? 1 : 0 ;
V_280 = ( V_25 & V_283 ) ? 1 : 0 ;
break;
case V_42 :
break;
}
if ( V_22 && V_280 )
return 2 ;
else if ( V_22 )
return 1 ;
return 0 ;
}
static int F_140 ( struct V_3 * V_3 , int V_224 )
{
int V_26 , V_22 , V_280 ;
V_26 = F_4 ( V_3 , V_33 ) ;
V_22 = ( V_26 & ( 0x0080 >> V_224 ) ) ? 1 : 0 ;
V_280 = ( V_26 & ( 0x8000 >> V_224 ) ) ? 1 : 0 ;
if ( V_280 )
return 2 ;
else if ( V_22 )
return 1 ;
return 0 ;
}
static int F_141 ( struct V_3 * V_3 )
{
int V_25 ;
if ( V_3 -> V_222 ) {
switch ( V_3 -> V_31 ) {
case V_46 :
case V_32 :
V_25 = F_4 ( V_3 , V_34 ) ;
if ( V_25 & V_284 ) {
if ( V_25 & V_285 )
return 2 ;
else
return 1 ;
}
return 0 ;
break;
case V_48 :
case V_47 :
V_25 = F_4 ( V_3 , V_221 ) ;
if ( V_25 & 0x8000000 )
return 2 ;
if ( V_25 & 0x4000000 )
return 1 ;
return 0 ;
break;
default:
break;
}
}
return 3 ;
}
static int F_142 ( struct V_209 * V_210 ,
struct V_219 * V_220 )
{
struct V_3 * V_3 = F_62 ( V_210 ) ;
int V_5 = - 1 ;
switch ( V_3 -> V_31 ) {
case V_48 :
switch ( V_210 -> V_230 ) {
case 0 :
V_5 = F_136 ( V_3 ) ; break;
case 7 :
V_5 = F_141 ( V_3 ) ; break;
case 8 :
V_5 = F_139 ( V_3 ) ; break;
default:
V_5 = F_138 ( V_3 , V_220 -> V_144 . V_231 - 1 ) ;
}
case V_47 :
switch ( V_210 -> V_230 ) {
case 0 :
V_5 = F_136 ( V_3 ) ; break;
case 4 :
V_5 = F_141 ( V_3 ) ; break;
case 5 :
V_5 = F_139 ( V_3 ) ; break;
default:
V_5 = F_138 ( V_3 , V_220 -> V_144 . V_231 - 1 ) ;
}
case V_46 :
switch ( V_210 -> V_230 ) {
case 0 :
V_5 = F_136 ( V_3 ) ; break;
case 1 :
V_5 = F_137 ( V_3 ) ; break;
case 2 :
V_5 = F_141 ( V_3 ) ; break;
case 3 :
V_5 = F_139 ( V_3 ) ; break;
}
case V_42 :
V_5 = F_137 ( V_3 ) ;
break;
case V_32 :
switch ( V_210 -> V_230 ) {
case 0 :
V_5 = F_136 ( V_3 ) ; break;
case 9 :
V_5 = F_141 ( V_3 ) ; break;
case 10 :
V_5 = F_139 ( V_3 ) ; break;
default:
V_5 = F_140 ( V_3 ,
V_210 -> V_230 - 1 ) ;
}
}
if ( - 1 == V_5 )
V_5 = 3 ;
V_220 -> V_215 . V_226 . V_228 [ 0 ] = V_5 ;
return 0 ;
}
static void F_143 ( struct V_3 * V_3 )
{
unsigned int V_286 [ 4 ] = { 0 , 0 , 0 , 0 } ;
switch ( V_3 -> V_222 -> V_156 ) {
case 0 :
V_286 [ 2 ] |= V_287 ;
break;
case 1 :
V_286 [ 2 ] |= V_288 ;
break;
default:
break;
}
switch ( V_3 -> V_222 -> V_289 ) {
case 1 :
V_286 [ 1 ] |= V_290 ;
break;
case 2 :
V_286 [ 1 ] |= V_291 ;
break;
case 3 :
V_286 [ 1 ] |= V_291 +
V_292 ;
break;
case 4 :
V_286 [ 1 ] |= V_290 +
V_291 ;
break;
case 5 :
V_286 [ 1 ] |= V_290 +
V_291 +
V_292 ;
break;
default:
break;
}
switch ( V_3 -> V_222 -> V_293 ) {
case 1 :
V_286 [ 2 ] |= V_294 ;
break;
case 2 :
V_286 [ 2 ] |= V_295 ;
break;
default:
break;
}
switch ( V_3 -> V_222 -> V_296 ) {
case 1 :
V_286 [ 2 ] |= V_297 ;
break;
case 2 :
V_286 [ 2 ] |= V_298 ;
break;
default:
break;
}
switch ( V_3 -> V_222 -> V_299 ) {
case 1 :
V_286 [ 2 ] |= V_300 ;
break;
case 2 :
V_286 [ 2 ] |= V_301 ;
break;
case 3 :
V_286 [ 2 ] |= V_300 + V_302 ;
break;
case 4 :
V_286 [ 2 ] |= V_301 + V_302 ;
break;
default:
break;
}
if ( 1 == V_3 -> V_222 -> V_303 ) {
V_286 [ 2 ] |= V_304 ;
}
F_2 ( V_3 , V_305 , V_286 [ 0 ] ) ;
F_2 ( V_3 , V_305 + 4 , V_286 [ 1 ] ) ;
F_2 ( V_3 , V_305 + 8 , V_286 [ 2 ] ) ;
F_2 ( V_3 , V_305 + 12 , V_286 [ 3 ] ) ;
}
static int F_144 ( struct V_209 * V_210 ,
struct V_211 * V_212 )
{
static char * V_236 [] = { L_37 , L_38 } ;
V_212 -> type = V_225 ;
V_212 -> V_214 = 1 ;
V_212 -> V_215 . V_226 . V_227 = 2 ;
if ( V_212 -> V_215 . V_226 . V_228 >= V_212 -> V_215 . V_226 . V_227 )
V_212 -> V_215 . V_226 . V_228 =
V_212 -> V_215 . V_226 . V_227 - 1 ;
strcpy ( V_212 -> V_215 . V_226 . V_197 ,
V_236 [ V_212 -> V_215 . V_226 . V_228 ] ) ;
return 0 ;
}
static int F_145 ( struct V_209 * V_210 ,
struct V_219 * V_220 )
{
struct V_3 * V_3 = F_62 ( V_210 ) ;
V_220 -> V_215 . V_226 . V_228 [ 0 ] = V_3 -> V_222 -> V_296 ;
return 0 ;
}
static int F_146 ( struct V_209 * V_210 ,
struct V_219 * V_220 )
{
struct V_3 * V_3 = F_62 ( V_210 ) ;
if ( V_3 -> V_222 -> V_296 != V_220 -> V_215 . V_226 . V_228 [ 0 ] ) {
V_3 -> V_222 -> V_296 = V_220 -> V_215 . V_226 . V_228 [ 0 ] ;
F_143 ( V_3 ) ;
return 1 ;
}
return 0 ;
}
static int F_147 ( struct V_209 * V_210 ,
struct V_211 * V_212 )
{
static char * V_236 [] = { L_39 , L_40 , L_41 , L_42 , L_43 } ;
V_212 -> type = V_225 ;
V_212 -> V_214 = 1 ;
V_212 -> V_215 . V_226 . V_227 = 5 ;
if ( V_212 -> V_215 . V_226 . V_228 >= V_212 -> V_215 . V_226 . V_227 )
V_212 -> V_215 . V_226 . V_228 =
V_212 -> V_215 . V_226 . V_227 - 1 ;
strcpy ( V_212 -> V_215 . V_226 . V_197 ,
V_236 [ V_212 -> V_215 . V_226 . V_228 ] ) ;
return 0 ;
}
static int F_148 ( struct V_209 * V_210 ,
struct V_219 * V_220 )
{
struct V_3 * V_3 = F_62 ( V_210 ) ;
V_220 -> V_215 . V_226 . V_228 [ 0 ] = V_3 -> V_222 -> V_299 ;
return 0 ;
}
static int F_149 ( struct V_209 * V_210 ,
struct V_219 * V_220 )
{
struct V_3 * V_3 = F_62 ( V_210 ) ;
if ( V_3 -> V_222 -> V_299 != V_220 -> V_215 . V_226 . V_228 [ 0 ] ) {
V_3 -> V_222 -> V_299 = V_220 -> V_215 . V_226 . V_228 [ 0 ] ;
F_143 ( V_3 ) ;
return 1 ;
}
return 0 ;
}
static int F_150 ( struct V_209 * V_210 ,
struct V_211 * V_212 )
{
static char * V_236 [] = { L_44 , L_45 , L_46 } ;
V_212 -> type = V_225 ;
V_212 -> V_214 = 1 ;
V_212 -> V_215 . V_226 . V_227 = 3 ;
if ( V_212 -> V_215 . V_226 . V_228 >= V_212 -> V_215 . V_226 . V_227 )
V_212 -> V_215 . V_226 . V_228 =
V_212 -> V_215 . V_226 . V_227 - 1 ;
strcpy ( V_212 -> V_215 . V_226 . V_197 ,
V_236 [ V_212 -> V_215 . V_226 . V_228 ] ) ;
return 0 ;
}
static int F_151 ( struct V_209 * V_210 ,
struct V_219 * V_220 )
{
struct V_3 * V_3 = F_62 ( V_210 ) ;
V_220 -> V_215 . V_226 . V_228 [ 0 ] = V_3 -> V_222 -> V_293 ;
return 0 ;
}
static int F_152 ( struct V_209 * V_210 ,
struct V_219 * V_220 )
{
struct V_3 * V_3 = F_62 ( V_210 ) ;
if ( V_3 -> V_222 -> V_293 != V_220 -> V_215 . V_226 . V_228 [ 0 ] ) {
V_3 -> V_222 -> V_293 = V_220 -> V_215 . V_226 . V_228 [ 0 ] ;
F_143 ( V_3 ) ;
return 1 ;
}
return 0 ;
}
static int F_153 ( struct V_209 * V_210 ,
struct V_211 * V_212 )
{
static char * V_236 [] = { L_47 , L_48 , L_49 ,
L_50 , L_51 , L_52 } ;
V_212 -> type = V_225 ;
V_212 -> V_214 = 1 ;
V_212 -> V_215 . V_226 . V_227 = 6 ;
if ( V_212 -> V_215 . V_226 . V_228 >= V_212 -> V_215 . V_226 . V_227 )
V_212 -> V_215 . V_226 . V_228 =
V_212 -> V_215 . V_226 . V_227 - 1 ;
strcpy ( V_212 -> V_215 . V_226 . V_197 ,
V_236 [ V_212 -> V_215 . V_226 . V_228 ] ) ;
return 0 ;
}
static int F_154 ( struct V_209 * V_210 ,
struct V_219 * V_220 )
{
struct V_3 * V_3 = F_62 ( V_210 ) ;
V_220 -> V_215 . V_226 . V_228 [ 0 ] = V_3 -> V_222 -> V_289 ;
return 0 ;
}
static int F_155 ( struct V_209 * V_210 ,
struct V_219 * V_220 )
{
struct V_3 * V_3 = F_62 ( V_210 ) ;
if ( V_3 -> V_222 -> V_289 != V_220 -> V_215 . V_226 . V_228 [ 0 ] ) {
V_3 -> V_222 -> V_289 = V_220 -> V_215 . V_226 . V_228 [ 0 ] ;
F_143 ( V_3 ) ;
return 1 ;
}
return 0 ;
}
static int F_156 ( struct V_209 * V_210 ,
struct V_211 * V_212 )
{
static char * V_236 [] = { L_53 , L_54 , L_55 } ;
V_212 -> type = V_225 ;
V_212 -> V_214 = 1 ;
V_212 -> V_215 . V_226 . V_227 = 3 ;
if ( V_212 -> V_215 . V_226 . V_228 >= V_212 -> V_215 . V_226 . V_227 )
V_212 -> V_215 . V_226 . V_228 =
V_212 -> V_215 . V_226 . V_227 - 1 ;
strcpy ( V_212 -> V_215 . V_226 . V_197 ,
V_236 [ V_212 -> V_215 . V_226 . V_228 ] ) ;
return 0 ;
}
static int F_157 ( struct V_209 * V_210 ,
struct V_219 * V_220 )
{
struct V_3 * V_3 = F_62 ( V_210 ) ;
V_220 -> V_215 . V_226 . V_228 [ 0 ] = V_3 -> V_222 -> V_156 ;
return 0 ;
}
static int F_158 ( struct V_209 * V_210 ,
struct V_219 * V_220 )
{
struct V_3 * V_3 = F_62 ( V_210 ) ;
if ( V_3 -> V_222 -> V_156 != V_220 -> V_215 . V_226 . V_228 [ 0 ] ) {
V_3 -> V_222 -> V_156 = V_220 -> V_215 . V_226 . V_228 [ 0 ] ;
F_143 ( V_3 ) ;
return 1 ;
}
return 0 ;
}
static int F_159 ( struct V_209 * V_210 ,
struct V_211 * V_212 )
{
V_212 -> type = V_306 ;
V_212 -> V_214 = 1 ;
V_212 -> V_215 . integer . V_216 = 0 ;
V_212 -> V_215 . integer . V_217 = 1 ;
return 0 ;
}
static int F_160 ( struct V_209 * V_210 ,
struct V_219 * V_220 )
{
struct V_3 * V_3 = F_62 ( V_210 ) ;
V_220 -> V_215 . V_226 . V_228 [ 0 ] = V_3 -> V_222 -> V_303 ;
return 0 ;
}
static int F_161 ( struct V_209 * V_210 ,
struct V_219 * V_220 )
{
struct V_3 * V_3 = F_62 ( V_210 ) ;
if ( V_3 -> V_222 -> V_303 != V_220 -> V_215 . V_226 . V_228 [ 0 ] ) {
V_3 -> V_222 -> V_303 = V_220 -> V_215 . V_226 . V_228 [ 0 ] ;
F_143 ( V_3 ) ;
return 1 ;
}
return 0 ;
}
static int F_162 ( struct V_3 * V_3 )
{
int V_16 ;
for ( V_16 = V_3 -> V_131 ; V_16 < V_3 -> V_123 ; ++ V_16 ) {
if ( V_3 -> V_97 > 48000 ) {
V_3 -> V_307 [ V_16 ] -> V_308 [ 0 ] . V_309 =
V_310 |
V_311 |
V_312 ;
} else {
V_3 -> V_307 [ V_16 ] -> V_308 [ 0 ] . V_309 =
V_313 |
V_312 ;
}
F_163 ( V_3 -> V_170 , V_314 |
V_315 ,
& V_3 -> V_307 [ V_16 ] -> V_144 ) ;
}
return 0 ;
}
static int F_164 ( struct V_169 * V_170 ,
struct V_3 * V_3 )
{
unsigned int V_224 , V_316 ;
int V_171 ;
struct V_209 * V_317 ;
struct V_318 * V_319 = NULL ;
switch ( V_3 -> V_31 ) {
case V_46 :
V_319 = V_320 ;
V_316 = F_165 ( V_320 ) ;
break;
case V_42 :
V_319 = V_321 ;
V_316 = F_165 ( V_321 ) ;
break;
case V_47 :
V_319 = V_322 ;
V_316 = F_165 ( V_322 ) ;
break;
case V_48 :
V_319 = V_323 ;
V_316 = F_165 ( V_323 ) ;
break;
case V_32 :
V_319 = V_324 ;
V_316 = F_165 ( V_324 ) ;
break;
}
if ( NULL != V_319 ) {
for ( V_224 = 0 ; V_224 < V_316 ; V_224 ++ ) {
V_171 = F_166 ( V_170 ,
F_167 ( & V_319 [ V_224 ] , V_3 ) ) ;
if ( V_171 < 0 )
return V_171 ;
}
}
V_325 . V_197 = L_56 ;
if ( V_3 -> V_97 >= 128000 ) {
V_316 = V_3 -> V_137 ;
} else if ( V_3 -> V_97 >= 64000 ) {
V_316 = V_3 -> V_131 ;
} else {
V_316 = V_3 -> V_123 ;
}
for ( V_224 = 0 ; V_224 < V_316 ; ++ V_224 ) {
V_325 . V_231 = V_224 + 1 ;
V_317 = F_167 ( & V_325 , V_3 ) ;
V_171 = F_166 ( V_170 , V_317 ) ;
if ( V_171 < 0 )
return V_171 ;
V_3 -> V_307 [ V_224 ] = V_317 ;
}
if ( V_3 -> V_222 ) {
V_319 = V_326 ;
V_316 = F_165 ( V_326 ) ;
for ( V_224 = 0 ; V_224 < V_316 ; V_224 ++ ) {
V_171 = F_166 ( V_170 ,
F_167 ( & V_319 [ V_224 ] , V_3 ) ) ;
if ( V_171 < 0 )
return V_171 ;
}
}
return 0 ;
}
static void
F_168 ( struct V_327 * V_328 ,
struct V_329 * V_330 )
{
struct V_3 * V_3 = V_328 -> V_163 ;
unsigned int V_25 , V_26 , V_331 , V_332 ;
char * V_333 ;
char * V_334 ;
char * V_335 ;
char * V_336 ;
int V_337 , V_338 ;
int V_339 , V_340 , V_83 , V_341 , V_342 , V_343 ;
unsigned int V_85 ;
T_2 V_86 = 0 ;
V_15 V_29 ;
V_25 = F_4 ( V_3 , V_34 ) ;
V_26 = F_4 ( V_3 , V_33 ) ;
V_331 = V_3 -> V_71 ;
V_332 = F_4 ( V_3 , V_35 ) ;
F_169 ( V_330 , L_57 ,
V_3 -> V_344 , V_3 -> V_170 -> V_345 + 1 ,
V_3 -> V_346 ,
( V_26 & V_347 ) |
( V_26 & V_348 ) | ( V_26 &
V_349 ) ) ;
F_169 ( V_330 , L_58 ,
( F_4 ( V_3 , V_186 ) >> 8 ) & 0xFFFFFF ,
( F_4 ( V_3 , V_180 ) >> 8 ) & 0xFFFFFF ) ;
F_169 ( V_330 , L_59 ,
V_3 -> V_177 , V_3 -> V_350 , ( unsigned long ) V_3 -> V_6 ) ;
F_169 ( V_330 , L_60 ) ;
F_169 ( V_330 ,
L_61 ,
V_25 & V_351 ,
( V_25 & V_184 ) ? 1 : 0 ,
( V_25 & V_190 ) ? 1 : 0 ,
V_3 -> V_352 ) ;
F_169 ( V_330 ,
L_62
L_63 ,
( ( V_25 & V_74 ) ? 1 : 0 ) ,
( V_25 & V_73 ) ,
( V_25 & V_73 ) %
( 2 * ( int ) V_3 -> V_70 ) ,
( ( V_25 & V_73 ) - 64 ) %
( 2 * ( int ) V_3 -> V_70 ) ,
( long ) F_19 ( V_3 ) * 4 ) ;
F_169 ( V_330 ,
L_64 ,
F_4 ( V_3 , V_182 ) & 0xFF ,
F_4 ( V_3 , V_188 ) & 0xFF ,
F_4 ( V_3 , V_180 ) & 0xFF ,
F_4 ( V_3 , V_186 ) & 0xFF ) ;
F_169 ( V_330 ,
L_65 ,
F_4 ( V_3 , V_173 ) & 0xFF ,
F_4 ( V_3 , V_175 ) & 0xFF ) ;
F_169 ( V_330 ,
L_66
L_67 ,
V_3 -> V_71 , V_3 -> V_353 ,
V_25 , V_26 ) ;
if ( V_25 & V_354 ) {
F_169 ( V_330 , L_68 ) ;
V_339 = F_4 ( V_3 , V_355 + 4 ) ;
if ( V_339 & V_356 ) {
F_169 ( V_330 , L_69 ) ;
switch ( V_339 & ( V_290 |
V_291 ) ) {
case 0 :
F_169 ( V_330 , L_70 ) ;
break;
case V_290 :
F_169 ( V_330 , L_71 ) ;
break;
case V_291 :
F_169 ( V_330 , L_72 ) ;
break;
default:
F_169 ( V_330 , L_73 ) ;
break;
}
if ( V_339 & V_292 ) {
F_169 ( V_330 , L_74 ) ;
} else {
F_169 ( V_330 , L_75 ) ;
}
} else {
F_169 ( V_330 , L_76 ) ;
}
if ( V_339 & V_357 ) {
F_169 ( V_330 , L_77 ) ;
} else if ( V_339 & V_358 ) {
F_169 ( V_330 , L_78 ) ;
} else {
F_169 ( V_330 , L_79 ) ;
}
if ( V_339 & V_359 ) {
F_169 ( V_330 , L_80 ) ;
} else {
F_169 ( V_330 , L_81 ) ;
}
switch ( V_3 -> V_31 ) {
case V_46 :
case V_32 :
V_86 = 110069313433624ULL ;
break;
case V_48 :
case V_47 :
V_86 = 104857600000000ULL ;
break;
case V_42 :
break;
}
V_85 = F_4 ( V_3 , V_208 ) ;
F_169 ( V_330 , L_82 , V_85 ) ;
V_29 = F_28 ( V_86 , V_85 ) ;
if ( V_331 & V_360 ) {
V_29 *= 4 ;
} else if ( V_331 & V_361 ) {
V_29 *= 2 ;
}
F_169 ( V_330 , L_83 ,
( unsigned int ) V_29 ) ;
V_340 = F_4 ( V_3 , V_355 ) ;
V_83 = V_340 & 0xF ;
V_340 >>= 4 ;
V_83 += ( V_340 & 0x3 ) * 10 ;
V_340 >>= 4 ;
V_341 = V_340 & 0xF ;
V_340 >>= 4 ;
V_341 += ( V_340 & 0x7 ) * 10 ;
V_340 >>= 4 ;
V_342 = V_340 & 0xF ;
V_340 >>= 4 ;
V_342 += ( V_340 & 0x7 ) * 10 ;
V_340 >>= 4 ;
V_343 = V_340 & 0xF ;
V_340 >>= 4 ;
V_343 += ( V_340 & 0x3 ) * 10 ;
F_169 ( V_330 ,
L_84 ,
V_343 , V_342 , V_341 , V_83 ) ;
} else {
F_169 ( V_330 , L_85 ) ;
}
F_169 ( V_330 , L_86 ) ;
V_337 = 1 << ( 6 + F_18 ( V_3 -> V_71 &
V_84 ) ) ;
F_169 ( V_330 ,
L_87 ,
V_337 , ( unsigned long ) V_3 -> V_70 ) ;
F_169 ( V_330 , L_88 ,
( V_3 -> V_71 & V_260 ) ? L_89 : L_90 ) ;
switch ( V_3 -> V_71 & V_362 ) {
case V_363 :
V_336 = L_91 ;
break;
case V_364 :
V_336 = L_92 ;
break;
default:
V_336 = L_93 ;
}
F_169 ( V_330 ,
L_94
L_95 ,
( V_3 -> V_71 & V_263 ) ? L_96 : L_90 ,
( V_3 -> V_71 & V_262 ) ? L_97 : L_98 ,
( V_3 -> V_71 & V_264 ) ? L_96 : L_90 ) ;
if ( ! ( V_3 -> V_71 & V_93 ) )
V_335 = L_13 ;
else
V_335 = L_12 ;
F_169 ( V_330 , L_99 , V_335 ) ;
switch ( F_79 ( V_3 ) ) {
case V_365 :
V_333 = L_24 ;
break;
case V_366 :
V_333 = L_100 ;
break;
case V_367 :
V_333 = L_26 ;
break;
case V_368 :
V_333 = L_27 ;
break;
default:
V_333 = L_101 ;
break;
}
F_169 ( V_330 , L_102 ,
V_333 ) ;
F_169 ( V_330 , L_103 ,
V_3 -> V_97 ) ;
F_169 ( V_330 , L_104 ) ;
V_337 = V_25 & V_279 ;
V_338 = V_26 & V_278 ;
F_169 ( V_330 , L_105 ,
( V_25 & V_43 ) ? ( V_337 ? L_35 : L_34 ) :
L_106 ,
( V_26 & V_49 ) ? ( V_338 ? L_35 : L_34 ) :
L_106 ) ;
switch ( F_16 ( V_3 ) ) {
case V_258 :
V_334 = L_27 ;
break;
case V_256 :
V_334 = L_26 ;
break;
case V_252 :
V_334 = L_24 ;
break;
case V_254 :
V_334 = L_100 ;
break;
case V_96 :
V_334 = L_107 ;
break;
default:
V_334 = L_108 ;
break;
}
F_169 ( V_330 ,
L_109 ,
V_334 , F_15 ( V_3 ) ,
( V_25 & V_60 ) >> 22 ,
( V_26 & V_51 ) >> 5 ) ;
F_169 ( V_330 , L_110 ,
( V_25 & V_369 ) ? L_111 : L_91 ,
( V_25 & V_370 ) ? L_112 :
L_113 ) ;
F_169 ( V_330 , L_114 ) ;
}
static void
F_170 ( struct V_327 * V_328 ,
struct V_329 * V_330 )
{
struct V_3 * V_3 = V_328 -> V_163 ;
unsigned int V_25 ;
unsigned int V_26 ;
unsigned int V_27 ;
int V_371 ;
char * V_334 ;
int V_337 ;
V_25 = F_4 ( V_3 , V_34 ) ;
V_26 = F_4 ( V_3 , V_33 ) ;
V_27 = F_4 ( V_3 , V_35 ) ;
F_169 ( V_330 , L_115 ,
V_3 -> V_344 , V_3 -> V_170 -> V_345 + 1 ,
V_3 -> V_346 ) ;
F_169 ( V_330 , L_59 ,
V_3 -> V_177 , V_3 -> V_350 , ( unsigned long ) V_3 -> V_6 ) ;
F_169 ( V_330 , L_60 ) ;
F_169 ( V_330 ,
L_61 ,
V_25 & V_351 ,
( V_25 & V_184 ) ? 1 : 0 ,
( V_25 & V_190 ) ? 1 : 0 ,
V_3 -> V_352 ) ;
F_169 ( V_330 ,
L_62
L_63 ,
( ( V_25 & V_74 ) ? 1 : 0 ) ,
( V_25 & V_73 ) ,
( V_25 & V_73 ) %
( 2 * ( int ) V_3 -> V_70 ) ,
( ( V_25 & V_73 ) - 64 ) %
( 2 * ( int ) V_3 -> V_70 ) ,
( long ) F_19 ( V_3 ) * 4 ) ;
F_169 ( V_330 ,
L_64 ,
F_4 ( V_3 , V_182 ) & 0xFF ,
F_4 ( V_3 , V_188 ) & 0xFF ,
F_4 ( V_3 , V_180 ) & 0xFF ,
F_4 ( V_3 , V_186 ) & 0xFF ) ;
F_169 ( V_330 ,
L_65 ,
F_4 ( V_3 , V_173 ) & 0xFF ,
F_4 ( V_3 , V_175 ) & 0xFF ) ;
F_169 ( V_330 ,
L_66
L_67 ,
V_3 -> V_71 , V_3 -> V_353 ,
V_25 , V_26 ) ;
F_169 ( V_330 , L_86 ) ;
V_337 = 1 << ( 6 + F_18 ( V_3 -> V_71 &
V_84 ) ) ;
F_169 ( V_330 ,
L_87 ,
V_337 , ( unsigned long ) V_3 -> V_70 ) ;
F_169 ( V_330 , L_88 ,
( V_3 ->
V_71 & V_260 ) ? L_89 : L_90 ) ;
F_169 ( V_330 ,
L_116 ,
( V_3 ->
V_71 & V_263 ) ? L_96 : L_90 ,
( V_3 ->
V_71 & V_265 ) ? L_96 : L_90 ,
( V_3 ->
V_71 & V_267 ) ? L_96 : L_90 ) ;
V_371 = F_79 ( V_3 ) ;
if ( V_371 == 0 )
F_169 ( V_330 , L_117 ) ;
else
F_169 ( V_330 , L_118 ,
V_371 ) ;
F_169 ( V_330 , L_103 ,
V_3 -> V_97 ) ;
F_169 ( V_330 , L_119 ,
V_3 -> V_71 & V_271 ?
L_120 : L_121 ) ;
F_169 ( V_330 , L_122 ,
V_3 -> V_71 & V_273 ?
L_120 :
V_3 -> V_71 & V_274 ?
L_123 : L_121 ) ;
F_169 ( V_330 , L_104 ) ;
F_169 ( V_330 , L_124 ,
( V_25 & V_37 ) ? L_125 : L_33 ,
F_1 ( ( V_25 >> V_38 ) & 0xF ) ) ;
for ( V_337 = 0 ; V_337 < 8 ; V_337 ++ ) {
F_169 ( V_330 , L_126 ,
V_337 + 1 ,
( V_26 & ( V_41 >> V_337 ) ) ?
L_125 : L_33 ,
F_1 ( ( V_27 >> ( 4 * V_337 ) ) & 0xF ) ) ;
}
switch ( F_16 ( V_3 ) ) {
case V_251 :
V_334 = L_23 ; break;
case V_36 :
V_334 = L_24 ; break;
case V_39 :
V_334 = L_15 ; break;
case V_372 :
V_334 = L_16 ; break;
case V_373 :
V_334 = L_17 ; break;
case V_374 :
V_334 = L_18 ; break;
case V_375 :
V_334 = L_19 ; break;
case V_376 :
V_334 = L_20 ; break;
case V_377 :
V_334 = L_21 ; break;
case V_40 :
V_334 = L_22 ; break;
default:
V_334 = L_108 ; break;
}
F_169 ( V_330 , L_127 , V_334 ) ;
F_169 ( V_330 , L_114 ) ;
}
static void
F_171 ( struct V_327 * V_328 ,
struct V_329 * V_330 )
{
struct V_3 * V_3 = V_328 -> V_163 ;
unsigned int V_378 , V_26 , V_379 , V_331 , V_16 ;
unsigned int V_22 , V_280 ;
V_378 = F_4 ( V_3 , V_221 ) ;
V_26 = F_4 ( V_3 , V_223 ) ;
V_379 = F_4 ( V_3 , V_281 ) ;
V_331 = V_3 -> V_71 ;
F_169 ( V_330 , L_128 , V_378 ) ;
F_169 ( V_330 , L_129 , V_26 ) ;
F_169 ( V_330 , L_130 , V_379 ) ;
F_169 ( V_330 , L_131 ) ;
F_169 ( V_330 , L_132 ,
( F_69 ( V_3 ) == 0 ) ? L_133 : L_134 ) ;
F_169 ( V_330 , L_135 ,
F_59 ( V_3 ) ) ;
F_169 ( V_330 , L_136 ) ;
V_22 = 0x1 ;
V_280 = 0x100 ;
for ( V_16 = 0 ; V_16 < 8 ; V_16 ++ ) {
F_169 ( V_330 , L_137 ,
V_16 ,
( V_378 & V_22 ) ? 1 : 0 ,
( V_378 & V_280 ) ? 1 : 0 ,
V_229 [ ( V_26 >> ( V_16 * 4 ) ) & 0xF ] ) ;
V_22 = V_22 << 1 ;
V_280 = V_280 << 1 ;
}
F_169 ( V_330 , L_138 ,
( V_378 & 0x1000000 ) ? 1 : 0 ,
( V_378 & 0x2000000 ) ? 1 : 0 ,
V_229 [ ( V_378 >> 16 ) & 0xF ] ) ;
F_169 ( V_330 , L_139 ,
( V_378 & 0x4000000 ) ? 1 : 0 ,
( V_378 & 0x8000000 ) ? 1 : 0 ,
V_229 [ ( V_378 >> 20 ) & 0xF ] ) ;
F_169 ( V_330 , L_140 ,
( V_379 & 0x400 ) ? 1 : 0 ,
( V_379 & 0x800 ) ? 1 : 0 ,
V_229 [ ( V_26 >> 12 ) & 0xF ] ) ;
}
static void
F_172 ( struct V_327 * V_328 ,
struct V_329 * V_330 )
{
struct V_3 * V_3 = V_328 -> V_163 ;
int V_141 , V_16 ;
for ( V_16 = 0 ; V_16 < 256 ; V_16 += V_141 ) {
F_169 ( V_330 , L_141 , V_16 ) ;
for ( V_141 = 0 ; V_141 < 16 ; V_141 += 4 )
F_169 ( V_330 , L_142 , F_4 ( V_3 , V_16 + V_141 ) ) ;
F_169 ( V_330 , L_114 ) ;
}
}
static void F_173 ( struct V_327 * V_328 ,
struct V_329 * V_330 )
{
struct V_3 * V_3 = V_328 -> V_163 ;
int V_16 ;
F_169 ( V_330 , L_143 ) ;
for ( V_16 = 0 ; V_16 < V_3 -> V_120 ; V_16 ++ ) {
F_169 ( V_330 , L_144 , V_16 + 1 , V_3 -> V_124 [ V_16 ] ) ;
}
}
static void F_174 ( struct V_327 * V_328 ,
struct V_329 * V_330 )
{
struct V_3 * V_3 = V_328 -> V_163 ;
int V_16 ;
F_169 ( V_330 , L_143 ) ;
for ( V_16 = 0 ; V_16 < V_3 -> V_122 ; V_16 ++ ) {
F_169 ( V_330 , L_144 , V_16 + 1 , V_3 -> V_126 [ V_16 ] ) ;
}
}
static void T_3 F_175 ( struct V_3 * V_3 )
{
struct V_327 * V_328 ;
if ( ! F_176 ( V_3 -> V_170 , L_145 , & V_328 ) ) {
switch ( V_3 -> V_31 ) {
case V_32 :
F_177 ( V_328 , V_3 ,
F_170 ) ;
break;
case V_46 :
F_177 ( V_328 , V_3 ,
F_168 ) ;
break;
case V_42 :
break;
case V_48 :
F_177 ( V_328 , V_3 ,
F_171 ) ;
break;
case V_47 :
break;
}
}
if ( ! F_176 ( V_3 -> V_170 , L_146 , & V_328 ) ) {
F_177 ( V_328 , V_3 , F_173 ) ;
}
if ( ! F_176 ( V_3 -> V_170 , L_147 , & V_328 ) ) {
F_177 ( V_328 , V_3 , F_174 ) ;
}
#ifdef F_178
if ( ! F_176 ( V_3 -> V_170 , L_148 , & V_328 ) )
F_177 ( V_328 , V_3 ,
F_172 ) ;
#endif
}
static int F_179 ( struct V_3 * V_3 )
{
V_3 -> V_232 = 0 ;
switch ( V_3 -> V_31 ) {
case V_46 :
case V_42 :
V_3 -> V_71 =
0x2 + 0x8 + 0x10 + 0x80 + 0x400 + 0x4000 + 0x1000000 ;
break;
case V_48 :
case V_47 :
V_3 -> V_232 = 0x1 + 0x1000 ;
V_3 -> V_71 =
0x2 + 0x8 + 0x10 + 0x80 + 0x400 + 0x4000 + 0x1000000 ;
break;
case V_32 :
V_3 -> V_71 =
V_93 |
F_25 ( 7 ) |
V_239 |
V_260 |
V_269 ;
break;
}
F_2 ( V_3 , V_78 , V_3 -> V_71 ) ;
if ( V_32 == V_3 -> V_31 ) {
#ifdef F_180
V_3 -> V_353 = V_380 ;
#else
V_3 -> V_353 = 0 ;
#endif
F_2 ( V_3 , V_381 , V_3 -> V_353 ) ;
}
F_17 ( V_3 ) ;
F_33 ( V_3 , 0 * V_143 ) ;
if ( V_3 -> V_31 == V_47 || V_3 -> V_31 == V_48 ) {
F_2 ( V_3 , V_235 , V_3 -> V_232 ) ;
}
F_31 ( V_3 , 48000 , 1 ) ;
return 0 ;
}
static T_4 F_181 ( int V_177 , void * V_382 )
{
struct V_3 * V_3 = (struct V_3 * ) V_382 ;
unsigned int V_25 ;
int V_16 , V_383 , V_145 , V_384 = 0 ;
V_25 = F_4 ( V_3 , V_34 ) ;
V_383 = V_25 & V_351 ;
V_145 = V_25 & ( V_184 | V_190 |
V_178 | V_195 ) ;
if ( ! V_383 && ! V_145 )
return V_385 ;
F_2 ( V_3 , V_386 , 0 ) ;
V_3 -> V_352 ++ ;
if ( V_383 ) {
if ( V_3 -> V_387 )
F_182 ( V_3 -> V_387 ) ;
if ( V_3 -> V_388 )
F_182 ( V_3 -> V_388 ) ;
}
if ( V_145 ) {
V_16 = 0 ;
while ( V_16 < V_3 -> V_207 ) {
if ( ( F_4 ( V_3 ,
V_3 -> V_145 [ V_16 ] . V_148 ) & 0xff ) &&
( V_25 & V_3 -> V_145 [ V_16 ] . V_177 ) ) {
V_3 -> V_71 &= ~ V_3 -> V_145 [ V_16 ] . V_158 ;
F_2 ( V_3 , V_78 ,
V_3 -> V_71 ) ;
V_3 -> V_145 [ V_16 ] . V_157 = 1 ;
V_384 = 1 ;
}
V_16 ++ ;
}
if ( V_384 )
F_183 ( & V_3 -> V_389 ) ;
}
return V_390 ;
}
static T_1 F_184 ( struct V_391
* V_160 )
{
struct V_3 * V_3 = F_185 ( V_160 ) ;
return F_19 ( V_3 ) ;
}
static int F_186 ( struct V_391 * V_160 )
{
struct V_392 * V_393 = V_160 -> V_393 ;
struct V_3 * V_3 = F_185 ( V_160 ) ;
struct V_391 * V_394 ;
if ( V_160 -> V_395 == V_396 )
V_394 = V_3 -> V_387 ;
else
V_394 = V_3 -> V_388 ;
if ( V_3 -> V_397 )
V_393 -> V_25 -> V_398 = F_19 ( V_3 ) ;
else
V_393 -> V_25 -> V_398 = 0 ;
if ( V_394 ) {
struct V_391 * V_75 ;
struct V_392 * V_399 = V_394 -> V_393 ;
F_187 (s, substream) {
if ( V_75 == V_394 ) {
V_399 -> V_25 -> V_398 =
V_393 -> V_25 -> V_398 ;
break;
}
}
}
return 0 ;
}
static int F_188 ( struct V_391 * V_160 ,
struct V_400 * V_401 )
{
struct V_3 * V_3 = F_185 ( V_160 ) ;
int V_171 ;
int V_16 ;
T_5 V_402 ;
T_5 V_403 ;
F_24 ( & V_3 -> V_22 ) ;
if ( V_160 -> V_404 -> V_395 == V_396 ) {
V_402 = V_3 -> V_23 ;
V_403 = V_3 -> V_24 ;
} else {
V_402 = V_3 -> V_24 ;
V_403 = V_3 -> V_23 ;
}
if ( V_403 > 0 && V_402 != V_403 ) {
if ( F_189 ( V_401 ) != V_3 -> V_97 ) {
F_26 ( & V_3 -> V_22 ) ;
F_190 ( V_401 ,
V_405 ) ;
return - V_113 ;
}
if ( F_191 ( V_401 ) != V_3 -> V_70 / 4 ) {
F_26 ( & V_3 -> V_22 ) ;
F_190 ( V_401 ,
V_406 ) ;
return - V_113 ;
}
}
F_26 ( & V_3 -> V_22 ) ;
F_24 ( & V_3 -> V_22 ) ;
V_171 = F_31 ( V_3 , F_189 ( V_401 ) , 0 ) ;
if ( V_171 < 0 ) {
F_32 ( V_407 L_149 , V_171 ) ;
F_26 ( & V_3 -> V_22 ) ;
F_190 ( V_401 ,
V_405 ) ;
return V_171 ;
}
F_26 ( & V_3 -> V_22 ) ;
V_171 = F_23 ( V_3 ,
F_191 ( V_401 ) ) ;
if ( V_171 < 0 ) {
F_32 ( V_407 L_150 , V_171 ) ;
F_190 ( V_401 ,
V_406 ) ;
return V_171 ;
}
V_171 =
F_192 ( V_160 , V_408 ) ;
if ( V_171 < 0 ) {
F_32 ( V_407 L_151 , V_171 ) ;
return V_171 ;
}
if ( V_160 -> V_395 == V_396 ) {
F_193 ( V_3 , V_160 , V_409 ,
F_194 ( V_401 ) ) ;
for ( V_16 = 0 ; V_16 < F_194 ( V_401 ) ; ++ V_16 )
F_11 ( V_3 , V_16 , 1 ) ;
V_3 -> V_80 =
( unsigned char * ) V_160 -> V_393 -> V_410 ;
F_195 ( L_152 ,
V_3 -> V_80 ) ;
} else {
F_193 ( V_3 , V_160 , V_411 ,
F_194 ( V_401 ) ) ;
for ( V_16 = 0 ; V_16 < F_194 ( V_401 ) ; ++ V_16 )
F_10 ( V_3 , V_16 , 1 ) ;
V_3 -> V_412 =
( unsigned char * ) V_160 -> V_393 -> V_410 ;
F_195 ( L_153 ,
V_3 -> V_412 ) ;
}
if ( V_413 == F_196 ( V_401 ) ) {
if ( ! ( V_3 -> V_71 & V_414 ) )
F_32 ( V_407 L_154 ) ;
V_3 -> V_71 |= V_414 ;
} else if ( V_415 == F_196 ( V_401 ) ) {
if ( V_3 -> V_71 & V_414 )
F_32 ( V_407 L_155 ) ;
V_3 -> V_71 &= ~ V_414 ;
}
F_2 ( V_3 , V_78 , V_3 -> V_71 ) ;
return 0 ;
}
static int F_197 ( struct V_391 * V_160 )
{
int V_16 ;
struct V_3 * V_3 = F_185 ( V_160 ) ;
if ( V_160 -> V_395 == V_396 ) {
for ( V_16 = 0 ; V_16 < V_3 -> V_122 ; ++ V_16 )
F_11 ( V_3 , V_16 , 0 ) ;
V_3 -> V_80 = NULL ;
} else {
for ( V_16 = 0 ; V_16 < V_3 -> V_120 ; ++ V_16 )
F_10 ( V_3 , V_16 , 0 ) ;
V_3 -> V_412 = NULL ;
}
F_198 ( V_160 ) ;
return 0 ;
}
static int F_199 ( struct V_391 * V_160 ,
struct V_416 * V_417 )
{
struct V_3 * V_3 = F_185 ( V_160 ) ;
if ( V_160 -> V_395 == V_396 ) {
if ( F_30 ( V_417 -> V_277 >= V_3 -> V_122 ) ) {
F_32 ( V_407 L_156 , V_417 -> V_277 ) ;
return - V_110 ;
}
if ( V_3 -> V_118 [ V_417 -> V_277 ] < 0 ) {
F_32 ( V_407 L_157 , V_417 -> V_277 ) ;
return - V_110 ;
}
V_417 -> V_418 = V_3 -> V_118 [ V_417 -> V_277 ] *
V_82 ;
} else {
if ( F_30 ( V_417 -> V_277 >= V_3 -> V_120 ) ) {
F_32 ( V_407 L_158 , V_417 -> V_277 ) ;
return - V_110 ;
}
if ( V_3 -> V_116 [ V_417 -> V_277 ] < 0 ) {
F_32 ( V_407 L_159 , V_417 -> V_277 ) ;
return - V_110 ;
}
V_417 -> V_418 = V_3 -> V_116 [ V_417 -> V_277 ] *
V_82 ;
}
V_417 -> V_419 = 0 ;
V_417 -> V_218 = 32 ;
return 0 ;
}
static int F_200 ( struct V_391 * V_160 ,
unsigned int V_420 , void * V_206 )
{
switch ( V_420 ) {
case V_421 :
return F_186 ( V_160 ) ;
case V_422 :
{
struct V_416 * V_417 = V_206 ;
return F_199 ( V_160 , V_417 ) ;
}
default:
break;
}
return F_201 ( V_160 , V_420 , V_206 ) ;
}
static int F_202 ( struct V_391 * V_160 , int V_420 )
{
struct V_3 * V_3 = F_185 ( V_160 ) ;
struct V_391 * V_394 ;
int V_397 ;
F_203 ( & V_3 -> V_22 ) ;
V_397 = V_3 -> V_397 ;
switch ( V_420 ) {
case V_423 :
V_397 |= 1 << V_160 -> V_395 ;
break;
case V_424 :
V_397 &= ~ ( 1 << V_160 -> V_395 ) ;
break;
default:
F_204 () ;
F_205 ( & V_3 -> V_22 ) ;
return - V_110 ;
}
if ( V_160 -> V_395 == V_396 )
V_394 = V_3 -> V_387 ;
else
V_394 = V_3 -> V_388 ;
if ( V_394 ) {
struct V_391 * V_75 ;
F_187 (s, substream) {
if ( V_75 == V_394 ) {
F_206 ( V_75 , V_160 ) ;
if ( V_420 == V_423 )
V_397 |= 1 << V_75 -> V_395 ;
else
V_397 &= ~ ( 1 << V_75 -> V_395 ) ;
goto V_425;
}
}
if ( V_420 == V_423 ) {
if ( ! ( V_397 & ( 1 << V_396 ) )
&& V_160 -> V_395 ==
V_426 )
F_22 ( V_3 ) ;
} else {
if ( V_397 &&
V_160 -> V_395 == V_396 )
F_22 ( V_3 ) ;
}
} else {
if ( V_160 -> V_395 == V_426 )
F_22 ( V_3 ) ;
}
V_425:
F_206 ( V_160 , V_160 ) ;
if ( ! V_3 -> V_397 && V_397 )
F_20 ( V_3 ) ;
else if ( V_3 -> V_397 && ! V_397 )
F_21 ( V_3 ) ;
V_3 -> V_397 = V_397 ;
F_205 ( & V_3 -> V_22 ) ;
return 0 ;
}
static int F_207 ( struct V_391 * V_160 )
{
return 0 ;
}
static int F_208 ( struct V_400 * V_401 ,
struct V_427 * V_428 )
{
struct V_3 * V_3 = V_428 -> V_429 ;
struct V_430 * V_431 =
F_209 ( V_401 , V_432 ) ;
struct V_430 * V_433 =
F_209 ( V_401 , V_405 ) ;
if ( V_433 -> V_216 > 96000 && V_433 -> V_217 <= 192000 ) {
struct V_430 V_434 = {
. V_216 = V_3 -> V_136 ,
. V_217 = V_3 -> V_136 ,
. integer = 1 ,
} ;
return F_210 ( V_431 , & V_434 ) ;
} else if ( V_433 -> V_216 > 48000 && V_433 -> V_217 <= 96000 ) {
struct V_430 V_434 = {
. V_216 = V_3 -> V_130 ,
. V_217 = V_3 -> V_130 ,
. integer = 1 ,
} ;
return F_210 ( V_431 , & V_434 ) ;
} else if ( V_433 -> V_217 < 64000 ) {
struct V_430 V_434 = {
. V_216 = V_3 -> V_121 ,
. V_217 = V_3 -> V_121 ,
. integer = 1 ,
} ;
return F_210 ( V_431 , & V_434 ) ;
}
return 0 ;
}
static int F_211 ( struct V_400 * V_401 ,
struct V_427 * V_428 )
{
struct V_3 * V_3 = V_428 -> V_429 ;
struct V_430 * V_431 =
F_209 ( V_401 , V_432 ) ;
struct V_430 * V_433 =
F_209 ( V_401 , V_405 ) ;
if ( V_433 -> V_216 > 96000 && V_433 -> V_217 <= 192000 ) {
struct V_430 V_434 = {
. V_216 = V_3 -> V_137 ,
. V_217 = V_3 -> V_137 ,
. integer = 1 ,
} ;
return F_210 ( V_431 , & V_434 ) ;
} else if ( V_433 -> V_216 > 48000 && V_433 -> V_217 <= 96000 ) {
struct V_430 V_434 = {
. V_216 = V_3 -> V_131 ,
. V_217 = V_3 -> V_131 ,
. integer = 1 ,
} ;
return F_210 ( V_431 , & V_434 ) ;
} else if ( V_433 -> V_217 < 64000 ) {
struct V_430 V_434 = {
. V_216 = V_3 -> V_123 ,
. V_217 = V_3 -> V_123 ,
. integer = 1 ,
} ;
return F_210 ( V_431 , & V_434 ) ;
} else {
}
return 0 ;
}
static int F_212 ( struct V_400 * V_401 ,
struct V_427 * V_428 )
{
struct V_3 * V_3 = V_428 -> V_429 ;
struct V_430 * V_431 =
F_209 ( V_401 , V_432 ) ;
struct V_430 * V_433 =
F_209 ( V_401 , V_405 ) ;
if ( V_431 -> V_216 >= V_3 -> V_121 ) {
struct V_430 V_434 = {
. V_216 = 32000 ,
. V_217 = 48000 ,
. integer = 1 ,
} ;
return F_210 ( V_433 , & V_434 ) ;
} else if ( V_431 -> V_217 <= V_3 -> V_136 ) {
struct V_430 V_434 = {
. V_216 = 128000 ,
. V_217 = 192000 ,
. integer = 1 ,
} ;
return F_210 ( V_433 , & V_434 ) ;
} else if ( V_431 -> V_217 <= V_3 -> V_130 ) {
struct V_430 V_434 = {
. V_216 = 64000 ,
. V_217 = 96000 ,
. integer = 1 ,
} ;
return F_210 ( V_433 , & V_434 ) ;
}
return 0 ;
}
static int F_213 ( struct V_400 * V_401 ,
struct V_427 * V_428 )
{
struct V_3 * V_3 = V_428 -> V_429 ;
struct V_430 * V_431 =
F_209 ( V_401 , V_432 ) ;
struct V_430 * V_433 =
F_209 ( V_401 , V_405 ) ;
if ( V_431 -> V_216 >= V_3 -> V_123 ) {
struct V_430 V_434 = {
. V_216 = 32000 ,
. V_217 = 48000 ,
. integer = 1 ,
} ;
return F_210 ( V_433 , & V_434 ) ;
} else if ( V_431 -> V_217 <= V_3 -> V_137 ) {
struct V_430 V_434 = {
. V_216 = 128000 ,
. V_217 = 192000 ,
. integer = 1 ,
} ;
return F_210 ( V_433 , & V_434 ) ;
} else if ( V_431 -> V_217 <= V_3 -> V_131 ) {
struct V_430 V_434 = {
. V_216 = 64000 ,
. V_217 = 96000 ,
. integer = 1 ,
} ;
return F_210 ( V_433 , & V_434 ) ;
}
return 0 ;
}
static int F_214 ( struct V_400 * V_401 ,
struct V_427 * V_428 )
{
unsigned int V_319 [ 3 ] ;
struct V_3 * V_3 = V_428 -> V_429 ;
struct V_430 * V_431 = F_209 ( V_401 ,
V_432 ) ;
V_319 [ 0 ] = V_3 -> V_136 ;
V_319 [ 1 ] = V_3 -> V_130 ;
V_319 [ 2 ] = V_3 -> V_121 ;
return F_215 ( V_431 , 3 , V_319 , 0 ) ;
}
static int F_216 ( struct V_400 * V_401 ,
struct V_427 * V_428 )
{
unsigned int V_319 [ 3 ] ;
struct V_3 * V_3 = V_428 -> V_429 ;
struct V_430 * V_431 = F_209 ( V_401 ,
V_432 ) ;
V_319 [ 0 ] = V_3 -> V_137 ;
V_319 [ 1 ] = V_3 -> V_131 ;
V_319 [ 2 ] = V_3 -> V_123 ;
return F_215 ( V_431 , 3 , V_319 , 0 ) ;
}
static int F_217 ( struct V_391 * V_160 )
{
struct V_3 * V_3 = F_185 ( V_160 ) ;
struct V_392 * V_393 = V_160 -> V_393 ;
F_24 ( & V_3 -> V_22 ) ;
F_218 ( V_160 ) ;
V_393 -> V_435 = V_436 ;
if ( V_3 -> V_387 == NULL )
F_21 ( V_3 ) ;
V_3 -> V_23 = V_437 -> V_438 ;
V_3 -> V_388 = V_160 ;
F_26 ( & V_3 -> V_22 ) ;
F_219 ( V_393 , 0 , 32 , 24 ) ;
switch ( V_3 -> V_31 ) {
case V_47 :
case V_48 :
F_220 ( V_393 , 0 ,
V_406 ,
& V_439 ) ;
F_220 ( V_393 , 0 ,
V_440 ,
& V_441 ) ;
break;
default:
F_220 ( V_393 , 0 ,
V_406 ,
& V_442 ) ;
}
if ( V_32 == V_3 -> V_31 ) {
F_220 ( V_393 , 0 , V_405 ,
& V_443 ) ;
} else {
F_221 ( V_393 , 0 , V_405 ,
F_213 , V_3 ,
V_432 , - 1 ) ;
}
F_221 ( V_393 , 0 , V_432 ,
F_216 , V_3 ,
V_432 , - 1 ) ;
F_221 ( V_393 , 0 , V_432 ,
F_211 , V_3 ,
V_405 , - 1 ) ;
return 0 ;
}
static int F_222 ( struct V_391 * V_160 )
{
struct V_3 * V_3 = F_185 ( V_160 ) ;
F_24 ( & V_3 -> V_22 ) ;
V_3 -> V_23 = - 1 ;
V_3 -> V_388 = NULL ;
F_26 ( & V_3 -> V_22 ) ;
return 0 ;
}
static int F_223 ( struct V_391 * V_160 )
{
struct V_3 * V_3 = F_185 ( V_160 ) ;
struct V_392 * V_393 = V_160 -> V_393 ;
F_24 ( & V_3 -> V_22 ) ;
F_218 ( V_160 ) ;
V_393 -> V_435 = V_444 ;
if ( V_3 -> V_388 == NULL )
F_21 ( V_3 ) ;
V_3 -> V_24 = V_437 -> V_438 ;
V_3 -> V_387 = V_160 ;
F_26 ( & V_3 -> V_22 ) ;
F_219 ( V_393 , 0 , 32 , 24 ) ;
switch ( V_3 -> V_31 ) {
case V_47 :
case V_48 :
F_220 ( V_393 , 0 ,
V_406 ,
& V_439 ) ;
F_220 ( V_393 , 0 ,
V_440 ,
& V_441 ) ;
break;
default:
F_220 ( V_393 , 0 ,
V_406 ,
& V_442 ) ;
}
if ( V_32 == V_3 -> V_31 ) {
F_220 ( V_393 , 0 , V_405 ,
& V_443 ) ;
} else {
F_221 ( V_393 , 0 , V_405 ,
F_212 , V_3 ,
V_432 , - 1 ) ;
}
F_221 ( V_393 , 0 , V_432 ,
F_214 , V_3 ,
V_432 , - 1 ) ;
F_221 ( V_393 , 0 , V_432 ,
F_208 , V_3 ,
V_405 , - 1 ) ;
return 0 ;
}
static int F_224 ( struct V_391 * V_160 )
{
struct V_3 * V_3 = F_185 ( V_160 ) ;
F_24 ( & V_3 -> V_22 ) ;
V_3 -> V_24 = - 1 ;
V_3 -> V_387 = NULL ;
F_26 ( & V_3 -> V_22 ) ;
return 0 ;
}
static int F_225 ( struct V_445 * V_435 , struct V_446 * V_446 )
{
return 0 ;
}
static inline int F_226 ( void T_6 * V_447 , void T_7 * V_448 )
{
V_15 V_5 = F_5 ( V_448 ) ;
return F_227 ( V_447 , & V_5 , 4 ) ;
}
static int F_228 ( struct V_445 * V_435 , struct V_446 * V_446 ,
unsigned int V_420 , unsigned long T_6 V_206 )
{
void T_6 * V_449 = ( void T_6 * ) V_206 ;
struct V_3 * V_3 = V_435 -> V_163 ;
struct V_450 V_10 ;
struct V_451 V_417 ;
struct V_452 V_25 ;
struct V_453 V_453 ;
struct V_454 * V_455 ;
struct V_456 V_340 ;
unsigned int V_457 ;
long unsigned int V_75 ;
int V_16 = 0 ;
switch ( V_420 ) {
case V_458 :
V_455 = & V_3 -> V_459 ;
for ( V_16 = 0 ; V_16 < V_81 ; V_16 ++ ) {
V_455 -> V_460 [ V_16 ] =
F_5 ( V_3 -> V_6 +
V_461 + V_16 * 4 ) ;
V_455 -> V_462 [ V_16 ] =
F_5 ( V_3 -> V_6 +
V_463 + V_16 * 4 ) ;
V_455 -> V_464 [ V_16 ] =
F_5 ( V_3 -> V_6 +
V_465 + V_16 * 4 ) ;
V_455 -> V_466 [ V_16 ] =
( ( V_467 ) F_5 ( V_3 -> V_6 +
V_468 + V_16 * 4 ) << 32 ) |
( V_467 ) F_5 ( V_3 -> V_6 +
V_469 + V_16 * 4 ) ;
V_455 -> V_470 [ V_16 ] =
( ( V_467 ) F_5 ( V_3 -> V_6 +
V_471 + V_16 * 4 ) << 32 ) |
( V_467 ) F_5 ( V_3 -> V_6 +
V_472 + V_16 * 4 ) ;
V_455 -> V_473 [ V_16 ] =
( ( V_467 ) F_5 ( V_3 -> V_6 +
V_474 + V_16 * 4 ) << 32 ) |
( V_467 ) F_5 ( V_3 -> V_6 +
V_475 + V_16 * 4 ) ;
}
if ( V_3 -> V_97 > 96000 ) {
V_455 -> V_476 = V_477 ;
} else if ( V_3 -> V_97 > 48000 ) {
V_455 -> V_476 = V_272 ;
} else {
V_455 -> V_476 = V_478 ;
}
V_455 -> V_26 = F_4 ( V_3 , V_33 ) ;
V_75 = F_227 ( V_449 , V_455 , sizeof( struct V_454 ) ) ;
if ( 0 != V_75 ) {
return - V_479 ;
}
break;
case V_480 :
V_340 . V_340 = F_4 ( V_3 , V_355 ) ;
V_16 = F_4 ( V_3 , V_355 + 4 ) ;
if ( V_16 & V_356 ) {
switch ( V_16 & ( V_290 |
V_291 ) ) {
case 0 :
V_340 . V_481 = V_482 ;
break;
case V_290 :
V_340 . V_481 = V_483 ;
break;
case V_291 :
V_340 . V_481 = V_484 ;
break;
default:
V_340 . V_481 = 30 ;
break;
}
if ( V_16 & V_292 ) {
V_340 . V_485 = V_486 ;
} else {
V_340 . V_485 = V_487 ;
}
} else {
V_340 . V_481 = V_488 ;
V_340 . V_485 = V_489 ;
}
if ( V_16 & V_357 ) {
V_340 . V_490 = V_491 ;
} else if ( V_16 & V_358 ) {
V_340 . V_490 = V_492 ;
} else {
V_340 . V_490 = V_493 ;
}
V_75 = F_227 ( V_449 , & V_340 , sizeof( struct V_456 ) ) ;
if ( 0 != V_75 ) {
return - V_479 ;
}
break;
case V_494 :
memset ( & V_417 , 0 , sizeof( V_417 ) ) ;
F_24 ( & V_3 -> V_22 ) ;
V_417 . V_333 = F_79 ( V_3 ) ;
V_417 . V_495 = F_136 ( V_3 ) ;
V_417 . V_97 = V_3 -> V_97 ;
V_417 . V_496 =
F_15 ( V_3 ) ;
V_417 . V_335 = F_69 ( V_3 ) ;
V_417 . V_497 = F_74 ( V_3 ) ;
V_417 . V_334 = F_16 ( V_3 ) ;
V_417 . V_498 = F_86 ( V_3 ) ;
V_417 . V_499 = 0 ;
F_26 ( & V_3 -> V_22 ) ;
if ( F_227 ( ( void T_6 * ) V_206 , & V_417 , sizeof( V_417 ) ) )
return - V_479 ;
break;
case V_500 :
V_25 . V_501 = V_3 -> V_31 ;
V_25 . V_502 = F_16 ( V_3 ) ;
V_25 . V_503 = 110069313433624ULL ;
V_25 . V_504 = F_4 ( V_3 , V_208 ) ;
switch ( V_3 -> V_31 ) {
case V_46 :
case V_42 :
V_25 . V_505 . V_506 . V_507 =
F_136 ( V_3 ) ;
V_25 . V_505 . V_506 . V_508 =
F_137 ( V_3 ) ;
V_25 . V_505 . V_506 . V_509 =
F_141 ( V_3 ) ;
V_25 . V_505 . V_506 . V_510 =
F_139 ( V_3 ) ;
V_457 =
F_4 ( V_3 , V_34 ) ;
V_25 . V_505 . V_506 . V_511 =
( V_457 & V_369 ) ? 1 : 0 ;
V_25 . V_505 . V_506 . V_512 =
( V_457 & V_262 ) ? 1 : 0 ;
V_25 . V_505 . V_506 . V_513 = 0 ;
default:
break;
}
if ( F_227 ( ( void T_6 * ) V_206 , & V_25 , sizeof( V_25 ) ) )
return - V_479 ;
break;
case V_514 :
V_453 . V_501 = V_3 -> V_31 ;
strncpy ( V_453 . V_515 , V_3 -> V_344 ,
sizeof( V_453 . V_515 ) ) ;
V_453 . V_516 = ( F_4 ( V_3 ,
V_180 ) >> 8 ) & 0xFFFFFF ;
V_453 . V_346 = V_3 -> V_346 ;
V_453 . V_517 = 0 ;
if ( V_3 -> V_222 )
V_453 . V_517 |= V_518 ;
if ( F_227 ( ( void T_6 * ) V_206 , & V_453 ,
sizeof( V_453 ) ) )
return - V_479 ;
break;
case V_519 :
if ( F_229 ( & V_10 , ( void T_6 * ) V_206 , sizeof( V_10 ) ) )
return - V_479 ;
if ( F_227 ( ( void T_6 * ) V_10 . V_10 , V_3 -> V_10 ,
sizeof( struct V_520 ) ) )
return - V_479 ;
break;
default:
return - V_110 ;
}
return 0 ;
}
static int T_3 F_230 ( struct V_169 * V_170 ,
struct V_3 * V_3 )
{
struct V_445 * V_435 ;
int V_171 ;
V_171 = F_231 ( V_170 , L_160 , 0 , & V_435 ) ;
if ( V_171 < 0 )
return V_171 ;
V_3 -> V_521 = V_435 ;
V_435 -> V_163 = V_3 ;
strcpy ( V_435 -> V_197 , L_161 ) ;
V_435 -> V_522 . V_523 = F_225 ;
V_435 -> V_522 . V_524 = F_228 ;
V_435 -> V_522 . V_525 = F_225 ;
return 0 ;
}
static int T_3 F_232 ( struct V_3 * V_3 )
{
int V_171 ;
struct V_526 * V_527 ;
T_8 V_528 ;
V_527 = V_3 -> V_527 ;
V_528 = V_408 ;
V_171 =
F_233 ( V_527 ,
V_529 ,
F_234 ( V_3 -> V_530 ) ,
V_528 ,
V_528 ) ;
if ( V_171 < 0 ) {
F_195 ( L_162 , V_528 ) ;
return V_171 ;
} else
F_195 ( L_163 , V_528 ) ;
return 0 ;
}
static void F_193 ( struct V_3 * V_3 ,
struct V_391 * V_160 ,
unsigned int V_4 , int V_531 )
{
int V_16 ;
for ( V_16 = 0 ; V_16 < ( V_531 * 16 ) ; V_16 ++ )
F_2 ( V_3 , V_4 + 4 * V_16 ,
F_235 ( V_160 , 4096 * V_16 ) ) ;
}
static int T_3 F_236 ( struct V_169 * V_170 ,
struct V_3 * V_3 )
{
struct V_526 * V_527 ;
int V_171 ;
V_171 = F_237 ( V_170 , V_3 -> V_344 , 0 , 1 , 1 , & V_527 ) ;
if ( V_171 < 0 )
return V_171 ;
V_3 -> V_527 = V_527 ;
V_527 -> V_163 = V_3 ;
strcpy ( V_527 -> V_197 , V_3 -> V_344 ) ;
F_238 ( V_527 , V_396 ,
& V_532 ) ;
F_238 ( V_527 , V_426 ,
& V_533 ) ;
V_527 -> V_202 = V_534 ;
V_171 = F_232 ( V_3 ) ;
if ( V_171 < 0 )
return V_171 ;
return 0 ;
}
static inline void F_239 ( struct V_3 * V_3 )
{
int V_16 ;
for ( V_16 = 0 ; V_16 < V_3 -> V_207 ; V_16 ++ )
F_38 ( V_3 , V_16 ) ;
}
static int T_3 F_240 ( struct V_169 * V_170 ,
struct V_3 * V_3 )
{
int V_171 , V_16 ;
F_195 ( L_164 ) ;
V_171 = F_236 ( V_170 , V_3 ) ;
if ( V_171 < 0 )
return V_171 ;
V_16 = 0 ;
while ( V_16 < V_3 -> V_207 ) {
V_171 = F_54 ( V_170 , V_3 , V_16 ) ;
if ( V_171 < 0 ) {
return V_171 ;
}
V_16 ++ ;
}
V_171 = F_164 ( V_170 , V_3 ) ;
if ( V_171 < 0 )
return V_171 ;
V_171 = F_230 ( V_170 , V_3 ) ;
if ( V_171 < 0 )
return V_171 ;
F_195 ( L_165 ) ;
F_175 ( V_3 ) ;
V_3 -> V_97 = - 1 ;
V_3 -> V_535 = - 1 ;
V_3 -> V_536 = - 1 ;
V_3 -> V_23 = - 1 ;
V_3 -> V_24 = - 1 ;
V_3 -> V_387 = NULL ;
V_3 -> V_388 = NULL ;
F_195 ( L_166 ) ;
V_171 = F_179 ( V_3 ) ;
if ( V_171 < 0 )
return V_171 ;
F_195 ( L_167 ) ;
F_162 ( V_3 ) ;
F_195 ( L_168 ) ;
V_171 = F_241 ( V_170 ) ;
if ( V_171 < 0 ) {
F_32 ( V_111 L_169 ) ;
return V_171 ;
}
F_195 ( L_170 ) ;
return 0 ;
}
static int T_3 F_242 ( struct V_169 * V_170 ,
struct V_3 * V_3 ) {
struct V_537 * V_530 = V_3 -> V_530 ;
int V_171 ;
unsigned long V_538 ;
V_3 -> V_177 = - 1 ;
V_3 -> V_170 = V_170 ;
F_55 ( & V_3 -> V_22 ) ;
F_243 ( V_3 -> V_530 ,
V_539 , & V_3 -> V_346 ) ;
strcpy ( V_170 -> V_540 , L_171 ) ;
strcpy ( V_170 -> V_541 , L_172 ) ;
switch ( V_3 -> V_346 ) {
case V_542 :
case V_543 :
V_3 -> V_31 = V_46 ;
V_3 -> V_344 = L_173 ;
V_3 -> V_207 = 3 ;
break;
case V_544 :
V_3 -> V_31 = V_48 ;
V_3 -> V_344 = L_174 ;
V_3 -> V_207 = 2 ;
break;
case V_545 :
V_3 -> V_31 = V_47 ;
V_3 -> V_344 = L_175 ;
V_3 -> V_207 = 1 ;
break;
case V_546 :
V_3 -> V_31 = V_42 ;
V_3 -> V_344 = L_176 ;
V_3 -> V_207 = 1 ;
break;
case V_547 :
case V_548 :
case V_549 :
V_3 -> V_31 = V_32 ;
V_3 -> V_344 = L_177 ;
V_3 -> V_207 = 2 ;
break;
default:
F_32 ( V_111 L_178 ,
V_3 -> V_346 ) ;
return - V_550 ;
}
V_171 = F_244 ( V_530 ) ;
if ( V_171 < 0 )
return V_171 ;
F_245 ( V_3 -> V_530 ) ;
V_171 = F_246 ( V_530 , L_145 ) ;
if ( V_171 < 0 )
return V_171 ;
V_3 -> V_350 = F_247 ( V_530 , 0 ) ;
V_538 = F_248 ( V_530 , 0 ) ;
F_195 ( L_179 ,
V_3 -> V_350 , V_3 -> V_350 + V_538 - 1 ) ;
V_3 -> V_6 = F_249 ( V_3 -> V_350 , V_538 ) ;
if ( ! V_3 -> V_6 ) {
F_32 ( V_111 L_1
L_180 ,
V_3 -> V_350 , V_3 -> V_350 + V_538 - 1 ) ;
return - V_113 ;
}
F_195 ( L_181 ,
( unsigned long ) V_3 -> V_6 , V_3 -> V_350 ,
V_3 -> V_350 + V_538 - 1 ) ;
if ( F_250 ( V_530 -> V_177 , F_181 ,
V_551 , L_145 , V_3 ) ) {
F_32 ( V_111 L_182 , V_530 -> V_177 ) ;
return - V_113 ;
}
F_195 ( L_183 , V_530 -> V_177 ) ;
V_3 -> V_177 = V_530 -> V_177 ;
F_195 ( L_184 ,
sizeof( struct V_520 ) ) ;
V_3 -> V_10 = F_251 ( sizeof( struct V_520 ) , V_552 ) ;
if ( ! V_3 -> V_10 ) {
F_32 ( V_111 L_1
L_185 ,
( int ) sizeof( struct V_520 ) ) ;
return V_171 ;
}
V_3 -> V_124 = NULL ;
V_3 -> V_126 = NULL ;
switch ( V_3 -> V_31 ) {
case V_32 :
V_3 -> V_121 = V_3 -> V_123 = V_553 ;
V_3 -> V_130 = V_3 -> V_131 = V_553 ;
V_3 -> V_136 = V_3 -> V_137 = V_553 ;
V_3 -> V_117 = V_3 -> V_119 =
V_554 ;
V_3 -> V_128 = V_3 -> V_129 =
V_554 ;
V_3 -> V_134 = V_3 -> V_135 =
V_554 ;
V_3 -> V_125 = V_3 -> V_127 =
V_555 ;
V_3 -> V_132 = V_3 -> V_133 =
V_555 ;
V_3 -> V_138 = V_3 -> V_139 =
V_555 ;
V_3 -> V_122 = V_3 -> V_120 =
V_553 ;
V_3 -> V_124 = V_3 -> V_126 =
V_555 ;
V_3 -> V_116 = V_3 -> V_118 =
V_554 ;
break;
case V_46 :
case V_42 :
V_3 -> V_121 = V_3 -> V_123 =
V_556 ;
V_3 -> V_130 = V_3 -> V_131 =
V_557 ;
V_3 -> V_136 = V_3 -> V_137 =
V_558 ;
V_3 -> V_117 = V_3 -> V_119 =
V_559 ;
V_3 -> V_128 = V_3 -> V_129 =
V_559 ;
V_3 -> V_134 = V_3 -> V_135 =
V_559 ;
V_3 -> V_125 = V_3 -> V_127 =
V_560 ;
V_3 -> V_132 = V_3 -> V_133 =
V_560 ;
V_3 -> V_138 = V_3 -> V_139 =
V_560 ;
break;
case V_47 :
if ( 0 == ( F_4 ( V_3 , V_33 ) & V_561 ) ) {
F_32 ( V_407 L_186 ) ;
}
V_3 -> V_121 = V_562 ;
V_3 -> V_130 = V_563 ;
V_3 -> V_136 = V_564 ;
V_3 -> V_123 = V_565 ;
V_3 -> V_131 = V_566 ;
V_3 -> V_137 = V_567 ;
V_3 -> V_119 = V_568 ;
V_3 -> V_129 = V_569 ;
V_3 -> V_135 = V_570 ;
V_3 -> V_117 = V_571 ;
V_3 -> V_128 = V_572 ;
V_3 -> V_134 = V_573 ;
V_3 -> V_125 = V_574 ;
V_3 -> V_127 = V_575 ;
V_3 -> V_132 = V_576 ;
V_3 -> V_133 = V_577 ;
V_3 -> V_138 = V_578 ;
V_3 -> V_139 = V_579 ;
break;
case V_48 :
V_3 -> V_121 = V_3 -> V_123 =
V_580 ;
V_3 -> V_130 = V_3 -> V_131 =
V_581 ;
V_3 -> V_136 = V_3 -> V_137 =
V_582 ;
V_3 -> V_120 = V_580 ;
V_3 -> V_122 = V_580 ;
V_3 -> V_117 = V_3 -> V_119 =
V_583 ;
V_3 -> V_128 = V_3 -> V_129 =
V_584 ;
V_3 -> V_134 = V_3 -> V_135 =
V_585 ;
V_3 -> V_116 = V_3 -> V_118 =
V_583 ;
V_3 -> V_125 = V_3 -> V_127 =
V_586 ;
V_3 -> V_132 = V_3 -> V_133 =
V_587 ;
V_3 -> V_138 = V_3 -> V_139 =
V_588 ;
break;
}
switch ( V_3 -> V_31 ) {
case V_47 :
case V_48 :
if ( F_4 ( V_3 , V_33 ) &
V_589 ) {
V_3 -> V_207 ++ ;
V_3 -> V_222 = F_251 ( sizeof( struct V_590 ) ,
V_552 ) ;
if ( NULL != V_3 -> V_222 ) {
F_143 ( V_3 ) ;
}
F_32 ( V_407 L_187 ) ;
} else {
V_3 -> V_222 = NULL ;
}
break;
case V_46 :
if ( F_4 ( V_3 , V_34 ) & V_354 ) {
V_3 -> V_207 ++ ;
V_3 -> V_222 = F_251 ( sizeof( struct V_590 ) ,
V_552 ) ;
if ( NULL != V_3 -> V_222 ) {
F_143 ( V_3 ) ;
}
F_32 ( V_407 L_188 ) ;
} else {
V_3 -> V_222 = NULL ;
}
break;
default:
V_3 -> V_222 = NULL ;
}
switch ( V_3 -> V_31 ) {
case V_32 :
if ( V_3 -> V_222 ) {
V_3 -> V_248 = V_591 ;
V_3 -> V_247 = 10 ;
} else {
V_3 -> V_248 = V_592 ;
V_3 -> V_247 = 9 ;
}
break;
case V_46 :
if ( V_3 -> V_222 ) {
V_3 -> V_248 = V_593 ;
V_3 -> V_247 = 4 ;
} else {
V_3 -> V_248 = V_594 ;
V_3 -> V_247 = 3 ;
}
break;
case V_42 :
break;
case V_48 :
if ( V_3 -> V_222 ) {
V_3 -> V_248 = V_595 ;
V_3 -> V_247 = 9 ;
} else {
V_3 -> V_248 = V_596 ;
V_3 -> V_247 = 8 ;
}
break;
case V_47 :
if ( V_3 -> V_222 ) {
V_3 -> V_248 = V_597 ;
V_3 -> V_247 = 6 ;
} else {
V_3 -> V_248 = V_598 ;
V_3 -> V_247 = 5 ;
}
break;
}
F_252 ( & V_3 -> V_389 ,
F_58 , ( unsigned long ) V_3 ) ;
F_195 ( L_189 ) ;
V_171 = F_240 ( V_170 , V_3 ) ;
if ( V_171 < 0 )
return V_171 ;
F_239 ( V_3 ) ;
return 0 ;
}
static int F_253 ( struct V_3 * V_3 )
{
if ( V_3 -> V_350 ) {
V_3 -> V_71 &=
~ ( V_77 | V_76 |
V_183 | V_189 |
V_176 | V_194 ) ;
F_2 ( V_3 , V_78 ,
V_3 -> V_71 ) ;
}
if ( V_3 -> V_177 >= 0 )
F_254 ( V_3 -> V_177 , ( void * ) V_3 ) ;
F_255 ( V_3 -> V_10 ) ;
if ( V_3 -> V_6 )
F_256 ( V_3 -> V_6 ) ;
if ( V_3 -> V_350 )
F_257 ( V_3 -> V_530 ) ;
F_258 ( V_3 -> V_530 ) ;
return 0 ;
}
static void F_259 ( struct V_169 * V_170 )
{
struct V_3 * V_3 = V_170 -> V_163 ;
if ( V_3 )
F_253 ( V_3 ) ;
}
static int T_3 F_260 ( struct V_537 * V_530 ,
const struct V_599 * V_600 )
{
static int V_601 ;
struct V_3 * V_3 ;
struct V_169 * V_170 ;
int V_171 ;
if ( V_601 >= V_602 )
return - V_550 ;
if ( ! V_603 [ V_601 ] ) {
V_601 ++ ;
return - V_604 ;
}
V_171 = F_261 ( V_231 [ V_601 ] , V_144 [ V_601 ] ,
V_605 , sizeof( struct V_3 ) , & V_170 ) ;
if ( V_171 < 0 )
return V_171 ;
V_3 = V_170 -> V_163 ;
V_170 -> V_606 = F_259 ;
V_3 -> V_601 = V_601 ;
V_3 -> V_530 = V_530 ;
F_262 ( V_170 , & V_530 -> V_601 ) ;
V_171 = F_242 ( V_170 , V_3 ) ;
if ( V_171 < 0 ) {
F_263 ( V_170 ) ;
return V_171 ;
}
if ( V_3 -> V_31 != V_42 ) {
sprintf ( V_170 -> V_196 , L_190 ,
V_3 -> V_344 ,
( F_4 ( V_3 , V_180 ) >> 8 ) & 0xFFFFFF ) ;
sprintf ( V_170 -> V_607 , L_191 ,
V_3 -> V_344 ,
( F_4 ( V_3 , V_180 ) >> 8 ) & 0xFFFFFF ,
V_3 -> V_350 , V_3 -> V_177 ) ;
} else {
sprintf ( V_170 -> V_196 , L_192 , V_3 -> V_344 ) ;
sprintf ( V_170 -> V_607 , L_193 ,
V_3 -> V_344 , V_3 -> V_350 , V_3 -> V_177 ) ;
}
V_171 = F_241 ( V_170 ) ;
if ( V_171 < 0 ) {
F_263 ( V_170 ) ;
return V_171 ;
}
F_264 ( V_530 , V_170 ) ;
V_601 ++ ;
return 0 ;
}
static void T_9 F_265 ( struct V_537 * V_530 )
{
F_263 ( F_266 ( V_530 ) ) ;
F_264 ( V_530 , NULL ) ;
}
static int T_10 F_267 ( void )
{
return F_268 ( & V_541 ) ;
}
static void T_11 F_269 ( void )
{
F_270 ( & V_541 ) ;
}
