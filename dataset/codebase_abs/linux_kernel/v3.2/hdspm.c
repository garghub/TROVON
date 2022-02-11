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
if ( V_29 <= 48000 ) {
if ( V_3 -> V_70 & V_71 )
V_29 *= 4 ;
else if ( V_3 -> V_70 &
V_72 )
V_29 *= 2 ;
}
}
break;
}
return V_29 ;
}
static int F_17 ( struct V_3 * V_3 )
{
int V_1 ;
V_1 = F_18 ( V_3 -> V_70 ) ;
if ( ( 7 == V_1 ) && ( V_48 == V_3 -> V_31 || V_47 == V_3 -> V_31 ) )
V_1 = - 1 ;
return 1 << ( V_1 + 6 ) ;
}
static inline void F_19 ( struct V_3 * V_3 )
{
V_3 -> V_73 = 4 * F_17 ( V_3 ) ;
}
static T_1 F_20 ( struct V_3 * V_3 )
{
int V_74 ;
V_74 = F_4 ( V_3 , V_34 ) ;
switch ( V_3 -> V_31 ) {
case V_48 :
case V_47 :
V_74 &= V_75 ;
V_74 /= 4 ;
break;
default:
V_74 = ( V_74 & V_76 ) ?
( V_3 -> V_73 / 4 ) : 0 ;
}
return V_74 ;
}
static inline void F_21 ( struct V_3 * V_77 )
{
V_77 -> V_70 |= ( V_78 | V_79 ) ;
F_2 ( V_77 , V_80 , V_77 -> V_70 ) ;
}
static inline void F_22 ( struct V_3 * V_77 )
{
V_77 -> V_70 &= ~ ( V_79 | V_78 ) ;
F_2 ( V_77 , V_80 , V_77 -> V_70 ) ;
}
static void F_23 ( struct V_3 * V_3 )
{
int V_16 ;
int V_1 = V_3 -> V_73 ;
void * V_81 = V_3 -> V_82 ;
if ( V_81 == NULL )
return;
for ( V_16 = 0 ; V_16 < V_83 ; V_16 ++ ) {
memset ( V_81 , 0 , V_1 ) ;
V_81 += V_84 ;
}
}
static int F_24 ( struct V_3 * V_77 , unsigned int V_85 )
{
int V_1 ;
F_25 ( & V_77 -> V_22 ) ;
if ( 32 == V_85 ) {
V_1 = 7 ;
} else {
V_85 >>= 7 ;
V_1 = 0 ;
while ( V_85 ) {
V_1 ++ ;
V_85 >>= 1 ;
}
}
V_77 -> V_70 &= ~ V_86 ;
V_77 -> V_70 |= F_26 ( V_1 ) ;
F_2 ( V_77 , V_80 , V_77 -> V_70 ) ;
F_19 ( V_77 ) ;
F_27 ( & V_77 -> V_22 ) ;
return 0 ;
}
static T_2 F_28 ( struct V_3 * V_3 , T_2 V_87 )
{
T_2 V_88 ;
if ( V_87 == 0 )
return 0 ;
switch ( V_3 -> V_31 ) {
case V_46 :
case V_32 :
V_88 = 110069313433624ULL ;
break;
case V_48 :
case V_47 :
V_88 = 104857600000000ULL ;
break;
case V_42 :
V_88 = 131072000000000ULL ;
break;
default:
F_29 () ;
return 0 ;
}
return F_30 ( V_88 , V_87 ) ;
}
static void F_31 ( struct V_3 * V_3 , int V_29 )
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
default:
F_29 () ;
return;
}
V_1 = F_30 ( V_1 , V_29 ) ;
F_32 ( V_1 >> 32 ) ;
F_2 ( V_3 , V_89 , ( V_15 ) V_1 ) ;
}
static int F_33 ( struct V_3 * V_3 , int V_29 , int V_90 )
{
int V_91 ;
int V_30 ;
int V_92 = 0 ;
int V_93 , V_94 ;
if ( ! ( V_3 -> V_70 & V_95 ) ) {
if ( V_90 ) {
F_34 ( V_96 L_1
L_2
L_3 ) ;
V_92 = 1 ;
} else {
int V_97 =
F_15 ( V_3 ) ;
if ( F_16 ( V_3 ) ==
V_98 ) {
F_34 ( V_96 L_1
L_4 ) ;
V_92 = 1 ;
} else if ( V_29 != V_97 ) {
F_34 ( V_96 L_1
L_5
L_6 ) ;
V_92 = 1 ;
}
}
}
V_91 = V_3 -> V_99 ;
if ( V_91 <= 48000 )
V_93 = V_100 ;
else if ( V_91 <= 96000 )
V_93 = V_101 ;
else
V_93 = V_102 ;
if ( V_29 <= 48000 )
V_94 = V_100 ;
else if ( V_29 <= 96000 )
V_94 = V_101 ;
else
V_94 = V_102 ;
switch ( V_29 ) {
case 32000 :
V_30 = V_103 ;
break;
case 44100 :
V_30 = V_104 ;
break;
case 48000 :
V_30 = V_105 ;
break;
case 64000 :
V_30 = V_106 ;
break;
case 88200 :
V_30 = V_107 ;
break;
case 96000 :
V_30 = V_108 ;
break;
case 128000 :
V_30 = V_109 ;
break;
case 176400 :
V_30 = V_110 ;
break;
case 192000 :
V_30 = V_111 ;
break;
default:
return - V_112 ;
}
if ( V_93 != V_94
&& ( V_3 -> V_24 >= 0 || V_3 -> V_23 >= 0 ) ) {
F_34
( V_113 L_1
L_7
L_8 ,
V_114 [ V_93 ] ,
V_114 [ V_94 ] ,
V_3 -> V_24 , V_3 -> V_23 ) ;
return - V_115 ;
}
V_3 -> V_70 &= ~ V_116 ;
V_3 -> V_70 |= V_30 ;
F_2 ( V_3 , V_80 , V_3 -> V_70 ) ;
F_31 ( V_3 , V_29 ) ;
if ( V_32 == V_3 -> V_31 && V_29 != V_91 )
F_2 ( V_3 , V_117 , 0 ) ;
V_3 -> V_99 = V_29 ;
if ( V_29 <= 48000 ) {
V_3 -> V_118 = V_3 -> V_119 ;
V_3 -> V_120 = V_3 -> V_121 ;
V_3 -> V_122 = V_3 -> V_123 ;
V_3 -> V_124 = V_3 -> V_125 ;
V_3 -> V_126 = V_3 -> V_127 ;
V_3 -> V_128 = V_3 -> V_129 ;
} else if ( V_29 <= 96000 ) {
V_3 -> V_118 = V_3 -> V_130 ;
V_3 -> V_120 = V_3 -> V_131 ;
V_3 -> V_122 = V_3 -> V_132 ;
V_3 -> V_124 = V_3 -> V_133 ;
V_3 -> V_126 = V_3 -> V_134 ;
V_3 -> V_128 = V_3 -> V_135 ;
} else {
V_3 -> V_118 = V_3 -> V_136 ;
V_3 -> V_120 = V_3 -> V_137 ;
V_3 -> V_122 = V_3 -> V_138 ;
V_3 -> V_124 = V_3 -> V_139 ;
V_3 -> V_126 = V_3 -> V_140 ;
V_3 -> V_128 = V_3 -> V_141 ;
}
if ( V_92 != 0 )
return - 1 ;
return 0 ;
}
static void F_35 ( struct V_3 * V_3 , int V_142 )
{
int V_16 , V_143 ;
unsigned int V_144 ;
if ( V_142 > V_145 )
V_144 = V_145 ;
else if ( V_142 < 0 )
V_144 = 0 ;
else
V_144 = V_142 ;
for ( V_16 = 0 ; V_16 < V_9 ; V_16 ++ )
for ( V_143 = 0 ; V_143 < V_9 ; V_143 ++ ) {
F_8 ( V_3 , V_16 , V_143 , V_144 ) ;
F_9 ( V_3 , V_16 , V_143 , V_144 ) ;
}
}
static inline unsigned char F_36 ( struct V_3 * V_3 ,
int V_146 )
{
return F_4 ( V_3 , V_3 -> V_147 [ V_146 ] . V_148 ) ;
}
static inline void F_37 ( struct V_3 * V_3 , int V_146 ,
int V_5 )
{
return F_2 ( V_3 , V_3 -> V_147 [ V_146 ] . V_149 , V_5 ) ;
}
static inline int F_38 ( struct V_3 * V_3 , int V_146 )
{
return F_4 ( V_3 , V_3 -> V_147 [ V_146 ] . V_150 ) & 0xFF ;
}
static inline int F_39 ( struct V_3 * V_3 , int V_146 )
{
int V_151 ;
V_151 = F_4 ( V_3 , V_3 -> V_147 [ V_146 ] . V_152 ) & 0xFF ;
if ( V_151 < 128 )
return 128 - V_151 ;
else
return 0 ;
}
static void F_40 ( struct V_3 * V_3 , int V_146 )
{
while ( F_38 ( V_3 , V_146 ) )
F_36 ( V_3 , V_146 ) ;
}
static int F_41 ( struct V_153 * V_154 )
{
unsigned long V_20 ;
int V_155 ;
int V_156 ;
int V_16 ;
unsigned char V_81 [ 128 ] ;
F_13 ( & V_154 -> V_22 , V_20 ) ;
if ( V_154 -> V_157 &&
! F_42 ( V_154 -> V_157 ) ) {
V_155 = F_39 ( V_154 -> V_3 ,
V_154 -> V_146 ) ;
if ( V_155 > 0 ) {
if ( V_155 > ( int ) sizeof ( V_81 ) )
V_155 = sizeof ( V_81 ) ;
V_156 = F_43 ( V_154 -> V_157 , V_81 ,
V_155 ) ;
if ( V_156 > 0 ) {
for ( V_16 = 0 ; V_16 < V_156 ; ++ V_16 )
F_37 ( V_154 -> V_3 ,
V_154 -> V_146 ,
V_81 [ V_16 ] ) ;
}
}
}
F_14 ( & V_154 -> V_22 , V_20 ) ;
return 0 ;
}
static int F_44 ( struct V_153 * V_154 )
{
unsigned char V_81 [ 128 ] ;
unsigned long V_20 ;
int V_155 ;
int V_16 ;
F_13 ( & V_154 -> V_22 , V_20 ) ;
V_155 = F_38 ( V_154 -> V_3 , V_154 -> V_146 ) ;
if ( V_155 > 0 ) {
if ( V_154 -> V_158 ) {
if ( V_155 > ( int ) sizeof ( V_81 ) )
V_155 = sizeof ( V_81 ) ;
for ( V_16 = 0 ; V_16 < V_155 ; ++ V_16 )
V_81 [ V_16 ] = F_36 ( V_154 -> V_3 ,
V_154 -> V_146 ) ;
if ( V_155 )
F_45 ( V_154 -> V_158 , V_81 ,
V_155 ) ;
} else {
while ( V_155 -- )
F_36 ( V_154 -> V_3 ,
V_154 -> V_146 ) ;
}
}
V_154 -> V_159 = 0 ;
F_14 ( & V_154 -> V_22 , V_20 ) ;
F_13 ( & V_154 -> V_3 -> V_22 , V_20 ) ;
V_154 -> V_3 -> V_70 |= V_154 -> V_160 ;
F_2 ( V_154 -> V_3 , V_80 ,
V_154 -> V_3 -> V_70 ) ;
F_14 ( & V_154 -> V_3 -> V_22 , V_20 ) ;
return F_41 ( V_154 ) ;
}
static void
F_46 ( struct V_161 * V_162 , int V_163 )
{
struct V_3 * V_3 ;
struct V_153 * V_154 ;
unsigned long V_20 ;
V_154 = V_162 -> V_164 -> V_165 ;
V_3 = V_154 -> V_3 ;
F_13 ( & V_3 -> V_22 , V_20 ) ;
if ( V_163 ) {
if ( ! ( V_3 -> V_70 & V_154 -> V_160 ) ) {
F_40 ( V_3 , V_154 -> V_146 ) ;
V_3 -> V_70 |= V_154 -> V_160 ;
}
} else {
V_3 -> V_70 &= ~ V_154 -> V_160 ;
}
F_2 ( V_3 , V_80 , V_3 -> V_70 ) ;
F_14 ( & V_3 -> V_22 , V_20 ) ;
}
static void F_47 ( unsigned long V_13 )
{
struct V_153 * V_154 = (struct V_153 * ) V_13 ;
unsigned long V_20 ;
F_41 ( V_154 ) ;
F_13 ( & V_154 -> V_22 , V_20 ) ;
if ( V_154 -> V_166 ) {
V_154 -> V_167 . V_168 = 1 + V_169 ;
F_48 ( & V_154 -> V_167 ) ;
}
F_14 ( & V_154 -> V_22 , V_20 ) ;
}
static void
F_49 ( struct V_161 * V_162 , int V_163 )
{
struct V_153 * V_154 ;
unsigned long V_20 ;
V_154 = V_162 -> V_164 -> V_165 ;
F_13 ( & V_154 -> V_22 , V_20 ) ;
if ( V_163 ) {
if ( ! V_154 -> V_166 ) {
F_50 ( & V_154 -> V_167 ) ;
V_154 -> V_167 . V_170 = F_47 ;
V_154 -> V_167 . V_13 = ( unsigned long ) V_154 ;
V_154 -> V_167 . V_168 = 1 + V_169 ;
F_48 ( & V_154 -> V_167 ) ;
V_154 -> V_166 ++ ;
}
} else {
if ( V_154 -> V_166 && -- V_154 -> V_166 <= 0 )
F_51 ( & V_154 -> V_167 ) ;
}
F_14 ( & V_154 -> V_22 , V_20 ) ;
if ( V_163 )
F_41 ( V_154 ) ;
}
static int F_52 ( struct V_161 * V_162 )
{
struct V_153 * V_154 ;
V_154 = V_162 -> V_164 -> V_165 ;
F_25 ( & V_154 -> V_22 ) ;
F_40 ( V_154 -> V_3 , V_154 -> V_146 ) ;
V_154 -> V_158 = V_162 ;
F_27 ( & V_154 -> V_22 ) ;
return 0 ;
}
static int F_53 ( struct V_161 * V_162 )
{
struct V_153 * V_154 ;
V_154 = V_162 -> V_164 -> V_165 ;
F_25 ( & V_154 -> V_22 ) ;
V_154 -> V_157 = V_162 ;
F_27 ( & V_154 -> V_22 ) ;
return 0 ;
}
static int F_54 ( struct V_161 * V_162 )
{
struct V_153 * V_154 ;
F_46 ( V_162 , 0 ) ;
V_154 = V_162 -> V_164 -> V_165 ;
F_25 ( & V_154 -> V_22 ) ;
V_154 -> V_158 = NULL ;
F_27 ( & V_154 -> V_22 ) ;
return 0 ;
}
static int F_55 ( struct V_161 * V_162 )
{
struct V_153 * V_154 ;
F_49 ( V_162 , 0 ) ;
V_154 = V_162 -> V_164 -> V_165 ;
F_25 ( & V_154 -> V_22 ) ;
V_154 -> V_157 = NULL ;
F_27 ( & V_154 -> V_22 ) ;
return 0 ;
}
static int T_3 F_56 ( struct V_171 * V_172 ,
struct V_3 * V_3 , int V_146 )
{
int V_173 ;
char V_81 [ 32 ] ;
V_3 -> V_147 [ V_146 ] . V_146 = V_146 ;
V_3 -> V_147 [ V_146 ] . V_3 = V_3 ;
F_57 ( & V_3 -> V_147 [ V_146 ] . V_22 ) ;
if ( 0 == V_146 ) {
if ( V_42 == V_3 -> V_31 ) {
V_3 -> V_147 [ 0 ] . V_148 = V_174 ;
V_3 -> V_147 [ 0 ] . V_150 = V_175 ;
V_3 -> V_147 [ 0 ] . V_149 = V_176 ;
V_3 -> V_147 [ 0 ] . V_152 = V_177 ;
V_3 -> V_147 [ 0 ] . V_160 = V_178 ;
V_3 -> V_147 [ 0 ] . V_179 = V_180 ;
} else {
V_3 -> V_147 [ 0 ] . V_148 = V_181 ;
V_3 -> V_147 [ 0 ] . V_150 = V_182 ;
V_3 -> V_147 [ 0 ] . V_149 = V_183 ;
V_3 -> V_147 [ 0 ] . V_152 = V_184 ;
V_3 -> V_147 [ 0 ] . V_160 = V_185 ;
V_3 -> V_147 [ 0 ] . V_179 = V_186 ;
}
} else if ( 1 == V_146 ) {
V_3 -> V_147 [ 1 ] . V_148 = V_187 ;
V_3 -> V_147 [ 1 ] . V_150 = V_188 ;
V_3 -> V_147 [ 1 ] . V_149 = V_189 ;
V_3 -> V_147 [ 1 ] . V_152 = V_190 ;
V_3 -> V_147 [ 1 ] . V_160 = V_191 ;
V_3 -> V_147 [ 1 ] . V_179 = V_192 ;
} else if ( ( 2 == V_146 ) && ( V_46 == V_3 -> V_31 ) ) {
V_3 -> V_147 [ 2 ] . V_148 = V_174 ;
V_3 -> V_147 [ 2 ] . V_150 = V_175 ;
V_3 -> V_147 [ 2 ] . V_149 = V_176 ;
V_3 -> V_147 [ 2 ] . V_152 = V_177 ;
V_3 -> V_147 [ 2 ] . V_160 = V_178 ;
V_3 -> V_147 [ 2 ] . V_179 = V_180 ;
} else if ( 2 == V_146 ) {
V_3 -> V_147 [ 2 ] . V_148 = V_174 ;
V_3 -> V_147 [ 2 ] . V_150 = V_175 ;
V_3 -> V_147 [ 2 ] . V_149 = - 1 ;
V_3 -> V_147 [ 2 ] . V_152 = - 1 ;
V_3 -> V_147 [ 2 ] . V_160 = V_178 ;
V_3 -> V_147 [ 2 ] . V_179 = V_193 ;
} else if ( 3 == V_146 ) {
V_3 -> V_147 [ 3 ] . V_148 = V_194 ;
V_3 -> V_147 [ 3 ] . V_150 = V_195 ;
V_3 -> V_147 [ 3 ] . V_149 = - 1 ;
V_3 -> V_147 [ 3 ] . V_152 = - 1 ;
V_3 -> V_147 [ 3 ] . V_160 = V_196 ;
V_3 -> V_147 [ 3 ] . V_179 = V_197 ;
}
if ( ( V_146 < 2 ) || ( ( 2 == V_146 ) && ( ( V_46 == V_3 -> V_31 ) ||
( V_42 == V_3 -> V_31 ) ) ) ) {
if ( ( V_146 == 0 ) && ( V_42 == V_3 -> V_31 ) ) {
sprintf ( V_81 , L_9 , V_172 -> V_198 ) ;
} else if ( ( V_146 == 2 ) && ( V_46 == V_3 -> V_31 ) ) {
sprintf ( V_81 , L_9 , V_172 -> V_198 ) ;
} else {
sprintf ( V_81 , L_10 , V_172 -> V_198 , V_146 + 1 ) ;
}
V_173 = F_58 ( V_172 , V_81 , V_146 , 1 , 1 ,
& V_3 -> V_147 [ V_146 ] . V_164 ) ;
if ( V_173 < 0 )
return V_173 ;
sprintf ( V_3 -> V_147 [ V_146 ] . V_164 -> V_199 , L_10 ,
V_172 -> V_146 , V_146 + 1 ) ;
V_3 -> V_147 [ V_146 ] . V_164 -> V_165 = & V_3 -> V_147 [ V_146 ] ;
F_59 ( V_3 -> V_147 [ V_146 ] . V_164 ,
V_200 ,
& V_201 ) ;
F_59 ( V_3 -> V_147 [ V_146 ] . V_164 ,
V_202 ,
& V_203 ) ;
V_3 -> V_147 [ V_146 ] . V_164 -> V_204 |=
V_205 |
V_206 |
V_207 ;
} else {
sprintf ( V_81 , L_11 , V_172 -> V_198 , V_146 + 1 ) ;
V_173 = F_58 ( V_172 , V_81 , V_146 , 1 , 1 ,
& V_3 -> V_147 [ V_146 ] . V_164 ) ;
if ( V_173 < 0 )
return V_173 ;
sprintf ( V_3 -> V_147 [ V_146 ] . V_164 -> V_199 ,
L_11 , V_172 -> V_146 , V_146 + 1 ) ;
V_3 -> V_147 [ V_146 ] . V_164 -> V_165 = & V_3 -> V_147 [ V_146 ] ;
F_59 ( V_3 -> V_147 [ V_146 ] . V_164 ,
V_202 ,
& V_203 ) ;
V_3 -> V_147 [ V_146 ] . V_164 -> V_204 |= V_206 ;
}
return 0 ;
}
static void F_60 ( unsigned long V_208 )
{
struct V_3 * V_3 = (struct V_3 * ) V_208 ;
int V_16 = 0 ;
while ( V_16 < V_3 -> V_209 ) {
if ( V_3 -> V_147 [ V_16 ] . V_159 )
F_44 ( & V_3 -> V_147 [ V_16 ] ) ;
V_16 ++ ;
}
}
static int F_61 ( struct V_3 * V_3 )
{
unsigned int V_87 , V_29 ;
V_87 = F_4 ( V_3 , V_210 ) ;
V_29 = F_28 ( V_3 , V_87 ) ;
return V_29 ;
}
static int F_62 ( struct V_211 * V_212 ,
struct V_213 * V_214 )
{
V_214 -> type = V_215 ;
V_214 -> V_216 = 1 ;
V_214 -> V_217 . integer . V_218 = 27000 ;
V_214 -> V_217 . integer . V_219 = 207000 ;
V_214 -> V_217 . integer . V_220 = 1 ;
return 0 ;
}
static int F_63 ( struct V_211 * V_212 ,
struct V_221 *
V_222 )
{
struct V_3 * V_3 = F_64 ( V_212 ) ;
V_222 -> V_217 . integer . V_217 [ 0 ] = F_61 ( V_3 ) ;
return 0 ;
}
static int F_65 ( struct V_3 * V_3 )
{
int V_25 ;
switch ( V_3 -> V_31 ) {
case V_48 :
case V_47 :
V_25 = F_4 ( V_3 , V_223 ) ;
return ( V_25 >> 16 ) & 0xF ;
break;
default:
break;
}
return 0 ;
}
static int F_66 ( struct V_3 * V_3 )
{
int V_25 ;
if ( V_3 -> V_224 ) {
switch ( V_3 -> V_31 ) {
case V_48 :
case V_47 :
V_25 = F_4 ( V_3 , V_223 ) ;
return ( V_25 >> 20 ) & 0xF ;
break;
default:
break;
}
}
return 0 ;
}
static int F_67 ( struct V_3 * V_3 )
{
int V_25 ;
if ( V_3 -> V_224 ) {
switch ( V_3 -> V_31 ) {
case V_48 :
case V_47 :
V_25 = F_4 ( V_3 , V_225 ) ;
return ( V_25 >> 12 ) & 0xF ;
break;
default:
break;
}
}
return 0 ;
}
static int F_68 ( struct V_3 * V_3 , unsigned int V_226 )
{
int V_25 = F_4 ( V_3 , V_225 ) ;
return ( V_25 >> ( V_226 * 4 ) ) & 0xF ;
}
static int F_69 ( struct V_211 * V_212 ,
struct V_213 * V_214 )
{
V_214 -> type = V_227 ;
V_214 -> V_216 = 1 ;
V_214 -> V_217 . V_228 . V_229 = 10 ;
if ( V_214 -> V_217 . V_228 . V_230 >= V_214 -> V_217 . V_228 . V_229 )
V_214 -> V_217 . V_228 . V_230 = V_214 -> V_217 . V_228 . V_229 - 1 ;
strcpy ( V_214 -> V_217 . V_228 . V_199 ,
V_231 [ V_214 -> V_217 . V_228 . V_230 ] ) ;
return 0 ;
}
static int F_70 ( struct V_211 * V_212 ,
struct V_221 *
V_222 )
{
struct V_3 * V_3 = F_64 ( V_212 ) ;
switch ( V_3 -> V_31 ) {
case V_48 :
switch ( V_212 -> V_232 ) {
case 0 :
V_222 -> V_217 . V_228 . V_230 [ 0 ] =
F_65 ( V_3 ) ;
break;
case 7 :
V_222 -> V_217 . V_228 . V_230 [ 0 ] =
F_66 ( V_3 ) ;
break;
case 8 :
V_222 -> V_217 . V_228 . V_230 [ 0 ] =
F_67 ( V_3 ) ;
break;
default:
V_222 -> V_217 . V_228 . V_230 [ 0 ] =
F_68 ( V_3 ,
V_212 -> V_232 - 1 ) ;
}
case V_47 :
switch ( V_212 -> V_232 ) {
case 0 :
V_222 -> V_217 . V_228 . V_230 [ 0 ] =
F_65 ( V_3 ) ;
break;
case 4 :
V_222 -> V_217 . V_228 . V_230 [ 0 ] =
F_66 ( V_3 ) ;
break;
case 5 :
V_222 -> V_217 . V_228 . V_230 [ 0 ] =
F_67 ( V_3 ) ;
break;
default:
V_222 -> V_217 . V_228 . V_230 [ 0 ] =
F_68 ( V_3 ,
V_222 -> V_146 . V_233 - 1 ) ;
}
case V_32 :
switch ( V_212 -> V_232 ) {
case 0 :
V_222 -> V_217 . V_228 . V_230 [ 0 ] =
F_65 ( V_3 ) ;
break;
case 9 :
V_222 -> V_217 . V_228 . V_230 [ 0 ] =
F_66 ( V_3 ) ;
break;
case 10 :
V_222 -> V_217 . V_228 . V_230 [ 0 ] =
F_67 ( V_3 ) ;
break;
default:
V_222 -> V_217 . V_228 . V_230 [ 0 ] =
F_68 ( V_3 ,
V_212 -> V_232 - 1 ) ;
break;
}
default:
break;
}
return 0 ;
}
static int F_71 ( struct V_3 * V_3 )
{
switch ( V_3 -> V_31 ) {
case V_47 :
case V_48 :
if ( V_3 -> V_234 & V_235 )
return 0 ;
break;
default:
if ( V_3 -> V_70 & V_95 )
return 0 ;
}
return 1 ;
}
static void F_72 ( struct V_3 * V_3 , int V_236 )
{
switch ( V_3 -> V_31 ) {
case V_47 :
case V_48 :
if ( 0 == V_236 )
V_3 -> V_234 |= V_235 ;
else
V_3 -> V_234 &= ~ V_235 ;
F_2 ( V_3 , V_237 , V_3 -> V_234 ) ;
break;
default:
if ( 0 == V_236 )
V_3 -> V_70 |= V_95 ;
else
V_3 -> V_70 &= ~ V_95 ;
F_2 ( V_3 , V_80 ,
V_3 -> V_70 ) ;
}
}
static int F_73 ( struct V_211 * V_212 ,
struct V_213 * V_214 )
{
static char * V_238 [] = { L_12 , L_13 } ;
V_214 -> type = V_227 ;
V_214 -> V_216 = 1 ;
V_214 -> V_217 . V_228 . V_229 = 2 ;
if ( V_214 -> V_217 . V_228 . V_230 >= V_214 -> V_217 . V_228 . V_229 )
V_214 -> V_217 . V_228 . V_230 =
V_214 -> V_217 . V_228 . V_229 - 1 ;
strcpy ( V_214 -> V_217 . V_228 . V_199 ,
V_238 [ V_214 -> V_217 . V_228 . V_230 ] ) ;
return 0 ;
}
static int F_74 ( struct V_211 * V_212 ,
struct V_221 * V_222 )
{
struct V_3 * V_3 = F_64 ( V_212 ) ;
V_222 -> V_217 . V_228 . V_230 [ 0 ] = F_71 ( V_3 ) ;
return 0 ;
}
static int F_75 ( struct V_211 * V_212 ,
struct V_221 * V_222 )
{
struct V_3 * V_3 = F_64 ( V_212 ) ;
int V_5 ;
if ( ! F_12 ( V_3 ) )
return - V_115 ;
V_5 = V_222 -> V_217 . V_228 . V_230 [ 0 ] ;
if ( V_5 < 0 )
V_5 = 0 ;
else if ( V_5 > 1 )
V_5 = 1 ;
F_72 ( V_3 , V_5 ) ;
return 0 ;
}
static int F_76 ( struct V_3 * V_3 )
{
switch ( V_3 -> V_99 ) {
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
static int F_77 ( struct V_3 * V_3 , int V_236 )
{
int V_29 ;
switch ( V_236 ) {
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
F_33 ( V_3 , V_29 , 1 ) ;
return 0 ;
}
static int F_78 ( struct V_211 * V_212 ,
struct V_213 * V_214 )
{
V_214 -> type = V_227 ;
V_214 -> V_216 = 1 ;
V_214 -> V_217 . V_228 . V_229 = 9 ;
if ( V_214 -> V_217 . V_228 . V_230 >= V_214 -> V_217 . V_228 . V_229 )
V_214 -> V_217 . V_228 . V_230 =
V_214 -> V_217 . V_228 . V_229 - 1 ;
strcpy ( V_214 -> V_217 . V_228 . V_199 ,
V_231 [ V_214 -> V_217 . V_228 . V_230 + 1 ] ) ;
return 0 ;
}
static int F_79 ( struct V_211 * V_212 ,
struct V_221 * V_222 )
{
struct V_3 * V_3 = F_64 ( V_212 ) ;
V_222 -> V_217 . V_228 . V_230 [ 0 ] = F_76 ( V_3 ) ;
return 0 ;
}
static int F_80 ( struct V_211 * V_212 ,
struct V_221 * V_222 )
{
struct V_3 * V_3 = F_64 ( V_212 ) ;
int V_239 ;
int V_5 ;
if ( ! F_12 ( V_3 ) )
return - V_115 ;
V_5 = V_222 -> V_217 . V_228 . V_230 [ 0 ] ;
if ( V_5 < 0 )
V_5 = 0 ;
if ( V_5 > 9 )
V_5 = 9 ;
F_25 ( & V_3 -> V_22 ) ;
if ( V_5 != F_76 ( V_3 ) )
V_239 = ( F_77 ( V_3 , V_5 ) == 0 ) ? 1 : 0 ;
else
V_239 = 0 ;
F_27 ( & V_3 -> V_22 ) ;
return V_239 ;
}
static int F_81 ( struct V_3 * V_3 )
{
switch ( V_3 -> V_31 ) {
case V_32 :
switch ( V_3 -> V_70 & V_240 ) {
case 0 : return 0 ;
case V_241 : return 1 ;
case V_242 : return 2 ;
case V_242 + V_241 : return 3 ;
case V_243 : return 4 ;
case V_243 + V_241 : return 5 ;
case V_243 + V_242 : return 6 ;
case V_243 + V_242 + V_241 :
return 7 ;
case V_244 : return 8 ;
case V_244 + V_241 : return 9 ;
}
break;
case V_46 :
case V_42 :
if ( V_3 -> V_224 ) {
switch ( V_3 -> V_70 & V_240 ) {
case 0 : return 0 ;
case V_241 : return 1 ;
case V_242 : return 2 ;
case V_242 + V_241 :
return 3 ;
}
} else {
switch ( V_3 -> V_70 & V_240 ) {
case 0 : return 0 ;
case V_241 : return 1 ;
case V_242 + V_241 :
return 2 ;
}
}
break;
case V_48 :
if ( V_3 -> V_224 ) {
switch ( ( V_3 -> V_234 &
V_245 ) / V_246 ) {
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
switch ( ( V_3 -> V_234 &
V_245 ) / V_246 ) {
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
if ( V_3 -> V_224 ) {
switch ( ( V_3 -> V_234 &
V_245 ) / V_246 ) {
case 0 : return 0 ;
case 3 : return 1 ;
case 1 : return 2 ;
case 2 : return 3 ;
case 9 : return 4 ;
case 10 : return 5 ;
}
} else {
switch ( ( V_3 -> V_234 &
V_245 ) / V_246 ) {
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
static int F_82 ( struct V_3 * V_3 , int V_247 )
{
int V_248 = 0 ;
switch ( V_3 -> V_31 ) {
case V_32 :
V_3 -> V_70 &= ~ V_240 ;
switch ( V_247 ) {
case 0 :
break;
case 1 :
V_3 -> V_70 |= V_241 ;
break;
case 2 :
V_3 -> V_70 |= V_242 ;
break;
case 3 :
V_3 -> V_70 |=
V_242 + V_241 ;
break;
case 4 :
V_3 -> V_70 |= V_243 ;
break;
case 5 :
V_3 -> V_70 |=
V_243 + V_241 ;
break;
case 6 :
V_3 -> V_70 |=
V_243 + V_242 ;
break;
case 7 :
V_3 -> V_70 |=
V_243 + V_242 + V_241 ;
break;
case 8 :
V_3 -> V_70 |= V_244 ;
break;
case 9 :
V_3 -> V_70 |=
V_244 + V_241 ;
break;
default:
return - 1 ;
}
break;
case V_46 :
case V_42 :
V_3 -> V_70 &= ~ V_240 ;
if ( V_3 -> V_224 ) {
switch ( V_247 ) {
case 0 :
break;
case 1 :
V_3 -> V_70 |= V_241 ;
break;
case 2 :
V_3 -> V_70 |= V_242 ;
break;
case 3 :
V_3 -> V_70 |=
V_241 + V_242 ;
break;
default:
return - 1 ;
}
} else {
switch ( V_247 ) {
case 0 :
break;
case 1 :
V_3 -> V_70 |= V_241 ;
break;
case 2 :
V_3 -> V_70 |=
V_241 + V_242 ;
break;
default:
return - 1 ;
}
}
break;
case V_48 :
if ( V_3 -> V_224 ) {
switch ( V_247 ) {
case 0 : V_248 = 0 ; break;
case 1 : V_248 = 3 ; break;
case 2 : V_248 = 4 ; break;
case 3 : V_248 = 5 ; break;
case 4 : V_248 = 6 ; break;
case 5 : V_248 = 1 ; break;
case 6 : V_248 = 2 ; break;
case 7 : V_248 = 9 ; break;
case 8 : V_248 = 10 ; break;
default: return - 1 ;
}
} else {
switch ( V_247 ) {
case 0 : V_248 = 0 ; break;
case 1 : V_248 = 3 ; break;
case 2 : V_248 = 4 ; break;
case 3 : V_248 = 5 ; break;
case 4 : V_248 = 6 ; break;
case 5 : V_248 = 1 ; break;
case 6 : V_248 = 2 ; break;
case 7 : V_248 = 10 ; break;
default: return - 1 ;
}
}
break;
case V_47 :
if ( V_3 -> V_224 ) {
switch ( V_247 ) {
case 0 : V_248 = 0 ; break;
case 1 : V_248 = 3 ; break;
case 2 : V_248 = 1 ; break;
case 3 : V_248 = 2 ; break;
case 4 : V_248 = 9 ; break;
case 5 : V_248 = 10 ; break;
default: return - 1 ;
}
} else {
switch ( V_247 ) {
case 0 : V_248 = 0 ; break;
case 1 : V_248 = 3 ; break;
case 2 : V_248 = 1 ; break;
case 3 : V_248 = 2 ; break;
case 4 : V_248 = 10 ; break;
default: return - 1 ;
}
}
break;
}
switch ( V_3 -> V_31 ) {
case V_48 :
case V_47 :
V_3 -> V_234 &= ~ V_245 ;
V_3 -> V_234 |= V_246 * V_248 ;
F_2 ( V_3 , V_237 , V_3 -> V_234 ) ;
break;
case V_46 :
case V_42 :
case V_32 :
F_2 ( V_3 , V_80 ,
V_3 -> V_70 ) ;
}
return 0 ;
}
static int F_83 ( struct V_211 * V_212 ,
struct V_213 * V_214 )
{
struct V_3 * V_3 = F_64 ( V_212 ) ;
V_214 -> type = V_227 ;
V_214 -> V_216 = 1 ;
V_214 -> V_217 . V_228 . V_229 = V_3 -> V_249 ;
if ( V_214 -> V_217 . V_228 . V_230 >= V_214 -> V_217 . V_228 . V_229 )
V_214 -> V_217 . V_228 . V_230 =
V_214 -> V_217 . V_228 . V_229 - 1 ;
strcpy ( V_214 -> V_217 . V_228 . V_199 ,
V_3 -> V_250 [ V_214 -> V_217 . V_228 . V_230 ] ) ;
return 0 ;
}
static int F_84 ( struct V_211 * V_212 ,
struct V_221 * V_222 )
{
struct V_3 * V_3 = F_64 ( V_212 ) ;
int V_251 = F_81 ( V_3 ) ;
if ( V_251 >= 0 ) {
V_222 -> V_217 . V_228 . V_230 [ 0 ] = V_251 ;
return 0 ;
}
return - 1 ;
}
static int F_85 ( struct V_211 * V_212 ,
struct V_221 * V_222 )
{
struct V_3 * V_3 = F_64 ( V_212 ) ;
int V_5 , V_239 = 0 ;
if ( ! F_12 ( V_3 ) )
return - V_115 ;
V_5 = V_222 -> V_217 . V_228 . V_230 [ 0 ] ;
if ( V_5 < 0 )
V_5 = 0 ;
else if ( V_5 >= V_3 -> V_249 )
V_5 = V_3 -> V_249 - 1 ;
F_25 ( & V_3 -> V_22 ) ;
if ( V_5 != F_81 ( V_3 ) )
V_239 = ( 0 == F_82 ( V_3 , V_5 ) ) ? 1 : 0 ;
F_27 ( & V_3 -> V_22 ) ;
return V_239 ;
}
static int F_16 ( struct V_3 * V_3 )
{
if ( V_32 == V_3 -> V_31 ) {
unsigned int V_25 = F_4 ( V_3 , V_34 ) ;
unsigned int V_28 =
( V_25 >> V_252 ) & 0xF ;
if ( V_28 == 0 )
return V_36 ;
if ( V_28 <= 8 )
return V_28 ;
return V_253 ;
} else if ( V_46 == V_3 -> V_31 ) {
unsigned int V_26 = F_4 ( V_3 , V_33 ) ;
switch ( V_26 & V_58 ) {
case V_59 :
return V_254 ;
case V_255 :
return V_256 ;
case V_257 :
return V_258 ;
case V_259 :
return V_260 ;
case V_261 :
return V_98 ;
default:
return 0 ;
}
}
return 0 ;
}
static int F_86 ( struct V_211 * V_212 ,
struct V_213 * V_214 )
{
struct V_3 * V_3 = F_64 ( V_212 ) ;
if ( V_32 == V_3 -> V_31 ) {
static char * V_238 [] = { L_14 , L_15 , L_16 , L_17 ,
L_18 , L_19 , L_20 , L_21 , L_22 , L_23 } ;
V_214 -> type = V_227 ;
V_214 -> V_216 = 1 ;
V_214 -> V_217 . V_228 . V_229 = 10 ;
if ( V_214 -> V_217 . V_228 . V_230 >=
V_214 -> V_217 . V_228 . V_229 )
V_214 -> V_217 . V_228 . V_230 =
V_214 -> V_217 . V_228 . V_229 - 1 ;
strcpy ( V_214 -> V_217 . V_228 . V_199 ,
V_238 [ V_214 -> V_217 . V_228 . V_230 ] ) ;
} else if ( V_46 == V_3 -> V_31 ) {
static char * V_238 [] = { L_24 , L_25 , L_26 ,
L_27 , L_23 } ;
V_214 -> type = V_227 ;
V_214 -> V_216 = 1 ;
V_214 -> V_217 . V_228 . V_229 = 5 ;
if ( V_214 -> V_217 . V_228 . V_230 >=
V_214 -> V_217 . V_228 . V_229 )
V_214 -> V_217 . V_228 . V_230 =
V_214 -> V_217 . V_228 . V_229 - 1 ;
strcpy ( V_214 -> V_217 . V_228 . V_199 ,
V_238 [ V_214 -> V_217 . V_228 . V_230 ] ) ;
}
return 0 ;
}
static int F_87 ( struct V_211 * V_212 ,
struct V_221 * V_222 )
{
struct V_3 * V_3 = F_64 ( V_212 ) ;
V_222 -> V_217 . V_228 . V_230 [ 0 ] = F_16 ( V_3 ) ;
return 0 ;
}
static int F_88 ( struct V_3 * V_3 )
{
return ( V_3 -> V_70 & V_262 ) ? 1 : 0 ;
}
static int F_89 ( struct V_3 * V_3 , int V_263 )
{
if ( V_263 )
V_3 -> V_70 |= V_262 ;
else
V_3 -> V_70 &= ~ V_262 ;
F_2 ( V_3 , V_80 , V_3 -> V_70 ) ;
return 0 ;
}
static int F_90 ( struct V_211 * V_212 ,
struct V_221 * V_222 )
{
struct V_3 * V_3 = F_64 ( V_212 ) ;
F_25 ( & V_3 -> V_22 ) ;
V_222 -> V_217 . integer . V_217 [ 0 ] = F_88 ( V_3 ) ;
F_27 ( & V_3 -> V_22 ) ;
return 0 ;
}
static int F_91 ( struct V_211 * V_212 ,
struct V_221 * V_222 )
{
struct V_3 * V_3 = F_64 ( V_212 ) ;
int V_239 ;
unsigned int V_5 ;
if ( ! F_12 ( V_3 ) )
return - V_115 ;
V_5 = V_222 -> V_217 . integer . V_217 [ 0 ] & 1 ;
F_25 ( & V_3 -> V_22 ) ;
V_239 = ( int ) V_5 != F_88 ( V_3 ) ;
F_89 ( V_3 , V_5 ) ;
F_27 ( & V_3 -> V_22 ) ;
return V_239 ;
}
static int F_92 ( struct V_3 * V_3 )
{
return ( V_3 -> V_70 & V_264 ) ? 1 : 0 ;
}
static int F_93 ( struct V_3 * V_3 , int V_263 )
{
if ( V_263 )
V_3 -> V_70 |= V_264 ;
else
V_3 -> V_70 &= ~ V_264 ;
F_2 ( V_3 , V_80 , V_3 -> V_70 ) ;
return 0 ;
}
static int F_94 ( struct V_211 * V_212 ,
struct V_221 * V_222 )
{
struct V_3 * V_3 = F_64 ( V_212 ) ;
F_25 ( & V_3 -> V_22 ) ;
V_222 -> V_217 . integer . V_217 [ 0 ] = F_92 ( V_3 ) ;
F_27 ( & V_3 -> V_22 ) ;
return 0 ;
}
static int F_95 ( struct V_211 * V_212 ,
struct V_221 * V_222 )
{
struct V_3 * V_3 = F_64 ( V_212 ) ;
int V_239 ;
unsigned int V_5 ;
if ( ! F_12 ( V_3 ) )
return - V_115 ;
V_5 = V_222 -> V_217 . integer . V_217 [ 0 ] & 1 ;
F_25 ( & V_3 -> V_22 ) ;
V_239 = ( int ) V_5 != F_92 ( V_3 ) ;
F_93 ( V_3 , V_5 ) ;
F_27 ( & V_3 -> V_22 ) ;
return V_239 ;
}
static int F_96 ( struct V_3 * V_3 )
{
return ( V_3 -> V_70 & V_265 ) ? 1 : 0 ;
}
static int F_97 ( struct V_3 * V_3 , int V_263 )
{
if ( V_263 )
V_3 -> V_70 |= V_265 ;
else
V_3 -> V_70 &= ~ V_265 ;
F_2 ( V_3 , V_80 , V_3 -> V_70 ) ;
return 0 ;
}
static int F_98 ( struct V_211 * V_212 ,
struct V_221 * V_222 )
{
struct V_3 * V_3 = F_64 ( V_212 ) ;
F_25 ( & V_3 -> V_22 ) ;
V_222 -> V_217 . integer . V_217 [ 0 ] = F_96 ( V_3 ) ;
F_27 ( & V_3 -> V_22 ) ;
return 0 ;
}
static int F_99 ( struct V_211 * V_212 ,
struct V_221 * V_222 )
{
struct V_3 * V_3 = F_64 ( V_212 ) ;
int V_239 ;
unsigned int V_5 ;
if ( ! F_12 ( V_3 ) )
return - V_115 ;
V_5 = V_222 -> V_217 . integer . V_217 [ 0 ] & 1 ;
F_25 ( & V_3 -> V_22 ) ;
V_239 = ( int ) V_5 != F_96 ( V_3 ) ;
F_97 ( V_3 , V_5 ) ;
F_27 ( & V_3 -> V_22 ) ;
return V_239 ;
}
static int F_100 ( struct V_3 * V_3 )
{
return ( V_3 -> V_70 & V_266 ) ? 1 : 0 ;
}
static int F_101 ( struct V_3 * V_3 , int V_263 )
{
if ( V_263 )
V_3 -> V_70 |= V_266 ;
else
V_3 -> V_70 &= ~ V_266 ;
F_2 ( V_3 , V_80 , V_3 -> V_70 ) ;
return 0 ;
}
static int F_102 ( struct V_211 * V_212 ,
struct V_221 * V_222 )
{
struct V_3 * V_3 = F_64 ( V_212 ) ;
F_25 ( & V_3 -> V_22 ) ;
V_222 -> V_217 . integer . V_217 [ 0 ] = F_100 ( V_3 ) ;
F_27 ( & V_3 -> V_22 ) ;
return 0 ;
}
static int F_103 ( struct V_211 * V_212 ,
struct V_221 * V_222 )
{
struct V_3 * V_3 = F_64 ( V_212 ) ;
int V_239 ;
unsigned int V_5 ;
if ( ! F_12 ( V_3 ) )
return - V_115 ;
V_5 = V_222 -> V_217 . integer . V_217 [ 0 ] & 1 ;
F_25 ( & V_3 -> V_22 ) ;
V_239 = ( int ) V_5 != F_100 ( V_3 ) ;
F_101 ( V_3 , V_5 ) ;
F_27 ( & V_3 -> V_22 ) ;
return V_239 ;
}
static int F_104 ( struct V_3 * V_3 )
{
return ( V_3 -> V_70 & V_267 ) ? 1 : 0 ;
}
static int F_105 ( struct V_3 * V_3 , int V_268 )
{
if ( V_268 )
V_3 -> V_70 |= V_267 ;
else
V_3 -> V_70 &= ~ V_267 ;
F_2 ( V_3 , V_80 , V_3 -> V_70 ) ;
return 0 ;
}
static int F_106 ( struct V_211 * V_212 ,
struct V_221 * V_222 )
{
struct V_3 * V_3 = F_64 ( V_212 ) ;
F_25 ( & V_3 -> V_22 ) ;
V_222 -> V_217 . V_228 . V_230 [ 0 ] = F_104 ( V_3 ) ;
F_27 ( & V_3 -> V_22 ) ;
return 0 ;
}
static int F_107 ( struct V_211 * V_212 ,
struct V_221 * V_222 )
{
struct V_3 * V_3 = F_64 ( V_212 ) ;
int V_239 ;
unsigned int V_5 ;
if ( ! F_12 ( V_3 ) )
return - V_115 ;
V_5 = V_222 -> V_217 . integer . V_217 [ 0 ] & 1 ;
F_25 ( & V_3 -> V_22 ) ;
V_239 = ( int ) V_5 != F_104 ( V_3 ) ;
F_105 ( V_3 , V_5 ) ;
F_27 ( & V_3 -> V_22 ) ;
return V_239 ;
}
static int F_108 ( struct V_3 * V_3 )
{
return ( V_3 -> V_70 & V_269 ) ? 1 : 0 ;
}
static int F_109 ( struct V_3 * V_3 , int V_270 )
{
if ( V_270 )
V_3 -> V_70 |= V_269 ;
else
V_3 -> V_70 &= ~ V_269 ;
F_2 ( V_3 , V_80 , V_3 -> V_70 ) ;
return 0 ;
}
static int F_110 ( struct V_211 * V_212 ,
struct V_221 * V_222 )
{
struct V_3 * V_3 = F_64 ( V_212 ) ;
F_25 ( & V_3 -> V_22 ) ;
V_222 -> V_217 . V_228 . V_230 [ 0 ] = F_108 ( V_3 ) ;
F_27 ( & V_3 -> V_22 ) ;
return 0 ;
}
static int F_111 ( struct V_211 * V_212 ,
struct V_221 * V_222 )
{
struct V_3 * V_3 = F_64 ( V_212 ) ;
int V_239 ;
unsigned int V_5 ;
if ( ! F_12 ( V_3 ) )
return - V_115 ;
V_5 = V_222 -> V_217 . integer . V_217 [ 0 ] & 1 ;
F_25 ( & V_3 -> V_22 ) ;
V_239 = ( int ) V_5 != F_108 ( V_3 ) ;
F_109 ( V_3 , V_5 ) ;
F_27 ( & V_3 -> V_22 ) ;
return V_239 ;
}
static int F_112 ( struct V_3 * V_3 )
{
return ( V_3 -> V_70 & V_271 ) ? 1 : 0 ;
}
static int F_113 ( struct V_3 * V_3 , int V_270 )
{
if ( V_270 )
V_3 -> V_70 |= V_271 ;
else
V_3 -> V_70 &= ~ V_271 ;
F_2 ( V_3 , V_80 , V_3 -> V_70 ) ;
return 0 ;
}
static int F_114 ( struct V_211 * V_212 ,
struct V_221 * V_222 )
{
struct V_3 * V_3 = F_64 ( V_212 ) ;
F_25 ( & V_3 -> V_22 ) ;
V_222 -> V_217 . V_228 . V_230 [ 0 ] = F_112 ( V_3 ) ;
F_27 ( & V_3 -> V_22 ) ;
return 0 ;
}
static int F_115 ( struct V_211 * V_212 ,
struct V_221 * V_222 )
{
struct V_3 * V_3 = F_64 ( V_212 ) ;
int V_239 ;
unsigned int V_5 ;
if ( ! F_12 ( V_3 ) )
return - V_115 ;
V_5 = V_222 -> V_217 . integer . V_217 [ 0 ] & 1 ;
F_25 ( & V_3 -> V_22 ) ;
V_239 = ( int ) V_5 != F_112 ( V_3 ) ;
F_113 ( V_3 , V_5 ) ;
F_27 ( & V_3 -> V_22 ) ;
return V_239 ;
}
static int F_116 ( struct V_3 * V_3 )
{
return ( V_3 -> V_70 & V_272 ) ? 1 : 0 ;
}
static int F_117 ( struct V_3 * V_3 , int V_263 )
{
if ( V_263 )
V_3 -> V_70 |= V_272 ;
else
V_3 -> V_70 &= ~ V_272 ;
F_2 ( V_3 , V_80 , V_3 -> V_70 ) ;
return 0 ;
}
static int F_118 ( struct V_211 * V_212 ,
struct V_213 * V_214 )
{
static char * V_238 [] = { L_28 , L_29 } ;
V_214 -> type = V_227 ;
V_214 -> V_216 = 1 ;
V_214 -> V_217 . V_228 . V_229 = 2 ;
if ( V_214 -> V_217 . V_228 . V_230 >= V_214 -> V_217 . V_228 . V_229 )
V_214 -> V_217 . V_228 . V_230 =
V_214 -> V_217 . V_228 . V_229 - 1 ;
strcpy ( V_214 -> V_217 . V_228 . V_199 ,
V_238 [ V_214 -> V_217 . V_228 . V_230 ] ) ;
return 0 ;
}
static int F_119 ( struct V_211 * V_212 ,
struct V_221 * V_222 )
{
struct V_3 * V_3 = F_64 ( V_212 ) ;
F_25 ( & V_3 -> V_22 ) ;
V_222 -> V_217 . V_228 . V_230 [ 0 ] = F_116 ( V_3 ) ;
F_27 ( & V_3 -> V_22 ) ;
return 0 ;
}
static int F_120 ( struct V_211 * V_212 ,
struct V_221 * V_222 )
{
struct V_3 * V_3 = F_64 ( V_212 ) ;
int V_239 ;
unsigned int V_5 ;
if ( ! F_12 ( V_3 ) )
return - V_115 ;
V_5 = V_222 -> V_217 . integer . V_217 [ 0 ] & 1 ;
F_25 ( & V_3 -> V_22 ) ;
V_239 = ( int ) V_5 != F_116 ( V_3 ) ;
F_117 ( V_3 , V_5 ) ;
F_27 ( & V_3 -> V_22 ) ;
return V_239 ;
}
static int F_121 ( struct V_3 * V_3 )
{
return ( V_3 -> V_70 & V_273 ) ? 1 : 0 ;
}
static int F_122 ( struct V_3 * V_3 , int V_274 )
{
if ( V_274 )
V_3 -> V_70 |= V_273 ;
else
V_3 -> V_70 &= ~ V_273 ;
F_2 ( V_3 , V_80 , V_3 -> V_70 ) ;
return 0 ;
}
static int F_123 ( struct V_211 * V_212 ,
struct V_213 * V_214 )
{
static char * V_238 [] = { L_30 , L_31 } ;
V_214 -> type = V_227 ;
V_214 -> V_216 = 1 ;
V_214 -> V_217 . V_228 . V_229 = 2 ;
if ( V_214 -> V_217 . V_228 . V_230 >= V_214 -> V_217 . V_228 . V_229 )
V_214 -> V_217 . V_228 . V_230 =
V_214 -> V_217 . V_228 . V_229 - 1 ;
strcpy ( V_214 -> V_217 . V_228 . V_199 ,
V_238 [ V_214 -> V_217 . V_228 . V_230 ] ) ;
return 0 ;
}
static int F_124 ( struct V_211 * V_212 ,
struct V_221 * V_222 )
{
struct V_3 * V_3 = F_64 ( V_212 ) ;
F_25 ( & V_3 -> V_22 ) ;
V_222 -> V_217 . V_228 . V_230 [ 0 ] = F_121 ( V_3 ) ;
F_27 ( & V_3 -> V_22 ) ;
return 0 ;
}
static int F_125 ( struct V_211 * V_212 ,
struct V_221 * V_222 )
{
struct V_3 * V_3 = F_64 ( V_212 ) ;
int V_239 ;
unsigned int V_5 ;
if ( ! F_12 ( V_3 ) )
return - V_115 ;
V_5 = V_222 -> V_217 . integer . V_217 [ 0 ] & 1 ;
F_25 ( & V_3 -> V_22 ) ;
V_239 = ( int ) V_5 != F_121 ( V_3 ) ;
F_122 ( V_3 , V_5 ) ;
F_27 ( & V_3 -> V_22 ) ;
return V_239 ;
}
static int F_126 ( struct V_3 * V_3 )
{
if ( V_3 -> V_70 & V_275 )
return 1 ;
if ( V_3 -> V_70 & V_276 )
return 2 ;
return 0 ;
}
static int F_127 ( struct V_3 * V_3 , int V_236 )
{
V_3 -> V_70 &= ~ ( V_275 | V_276 ) ;
switch ( V_236 ) {
case 0 :
break;
case 1 :
V_3 -> V_70 |= V_275 ;
break;
case 2 :
V_3 -> V_70 |= V_276 ;
break;
}
F_2 ( V_3 , V_80 , V_3 -> V_70 ) ;
return 0 ;
}
static int F_128 ( struct V_211 * V_212 ,
struct V_213 * V_214 )
{
static char * V_238 [] = { L_30 , L_31 , L_32 } ;
V_214 -> type = V_227 ;
V_214 -> V_216 = 1 ;
V_214 -> V_217 . V_228 . V_229 = 3 ;
if ( V_214 -> V_217 . V_228 . V_230 >= V_214 -> V_217 . V_228 . V_229 )
V_214 -> V_217 . V_228 . V_230 =
V_214 -> V_217 . V_228 . V_229 - 1 ;
strcpy ( V_214 -> V_217 . V_228 . V_199 ,
V_238 [ V_214 -> V_217 . V_228 . V_230 ] ) ;
return 0 ;
}
static int F_129 ( struct V_211 * V_212 ,
struct V_221 * V_222 )
{
struct V_3 * V_3 = F_64 ( V_212 ) ;
F_25 ( & V_3 -> V_22 ) ;
V_222 -> V_217 . V_228 . V_230 [ 0 ] = F_126 ( V_3 ) ;
F_27 ( & V_3 -> V_22 ) ;
return 0 ;
}
static int F_130 ( struct V_211 * V_212 ,
struct V_221 * V_222 )
{
struct V_3 * V_3 = F_64 ( V_212 ) ;
int V_239 ;
int V_5 ;
if ( ! F_12 ( V_3 ) )
return - V_115 ;
V_5 = V_222 -> V_217 . integer . V_217 [ 0 ] ;
if ( V_5 < 0 )
V_5 = 0 ;
if ( V_5 > 2 )
V_5 = 2 ;
F_25 ( & V_3 -> V_22 ) ;
V_239 = V_5 != F_126 ( V_3 ) ;
F_127 ( V_3 , V_5 ) ;
F_27 ( & V_3 -> V_22 ) ;
return V_239 ;
}
static int F_131 ( struct V_3 * V_3 )
{
if ( V_3 -> V_70 & V_71 )
return 2 ;
if ( V_3 -> V_70 & V_72 )
return 1 ;
return 0 ;
}
static int F_132 ( struct V_3 * V_3 , int V_236 )
{
V_3 -> V_70 &= ~ ( V_72 | V_71 ) ;
switch ( V_236 ) {
case 0 :
break;
case 1 :
V_3 -> V_70 |= V_72 ;
break;
case 2 :
V_3 -> V_70 |= V_71 ;
break;
}
F_2 ( V_3 , V_80 , V_3 -> V_70 ) ;
return 0 ;
}
static int F_133 ( struct V_211 * V_212 ,
struct V_213 * V_214 )
{
static char * V_238 [] = { L_30 , L_31 , L_32 } ;
V_214 -> type = V_227 ;
V_214 -> V_216 = 1 ;
V_214 -> V_217 . V_228 . V_229 = 3 ;
if ( V_214 -> V_217 . V_228 . V_230 >= V_214 -> V_217 . V_228 . V_229 )
V_214 -> V_217 . V_228 . V_230 =
V_214 -> V_217 . V_228 . V_229 - 1 ;
strcpy ( V_214 -> V_217 . V_228 . V_199 ,
V_238 [ V_214 -> V_217 . V_228 . V_230 ] ) ;
return 0 ;
}
static int F_134 ( struct V_211 * V_212 ,
struct V_221 * V_222 )
{
struct V_3 * V_3 = F_64 ( V_212 ) ;
F_25 ( & V_3 -> V_22 ) ;
V_222 -> V_217 . V_228 . V_230 [ 0 ] = F_131 ( V_3 ) ;
F_27 ( & V_3 -> V_22 ) ;
return 0 ;
}
static int F_135 ( struct V_211 * V_212 ,
struct V_221 * V_222 )
{
struct V_3 * V_3 = F_64 ( V_212 ) ;
int V_239 ;
int V_5 ;
if ( ! F_12 ( V_3 ) )
return - V_115 ;
V_5 = V_222 -> V_217 . integer . V_217 [ 0 ] ;
if ( V_5 < 0 )
V_5 = 0 ;
if ( V_5 > 2 )
V_5 = 2 ;
F_25 ( & V_3 -> V_22 ) ;
V_239 = V_5 != F_131 ( V_3 ) ;
F_132 ( V_3 , V_5 ) ;
F_27 ( & V_3 -> V_22 ) ;
return V_239 ;
}
static int F_136 ( struct V_211 * V_212 ,
struct V_213 * V_214 )
{
V_214 -> type = V_215 ;
V_214 -> V_216 = 3 ;
V_214 -> V_217 . integer . V_218 = 0 ;
V_214 -> V_217 . integer . V_219 = 65535 ;
V_214 -> V_217 . integer . V_220 = 1 ;
return 0 ;
}
static int F_137 ( struct V_211 * V_212 ,
struct V_221 * V_222 )
{
struct V_3 * V_3 = F_64 ( V_212 ) ;
int V_277 ;
int V_278 ;
V_277 = V_222 -> V_217 . integer . V_217 [ 0 ] ;
if ( V_277 < 0 )
V_277 = 0 ;
else if ( V_277 >= 2 * V_83 )
V_277 = 2 * V_83 - 1 ;
V_278 = V_222 -> V_217 . integer . V_217 [ 1 ] ;
if ( V_278 < 0 )
V_278 = 0 ;
else if ( V_278 >= V_83 )
V_278 = V_83 - 1 ;
F_25 ( & V_3 -> V_22 ) ;
if ( V_277 >= V_83 )
V_222 -> V_217 . integer . V_217 [ 2 ] =
F_7 ( V_3 , V_278 ,
V_277 - V_83 ) ;
else
V_222 -> V_217 . integer . V_217 [ 2 ] =
F_6 ( V_3 , V_278 , V_277 ) ;
F_27 ( & V_3 -> V_22 ) ;
return 0 ;
}
static int F_138 ( struct V_211 * V_212 ,
struct V_221 * V_222 )
{
struct V_3 * V_3 = F_64 ( V_212 ) ;
int V_239 ;
int V_277 ;
int V_278 ;
int V_144 ;
if ( ! F_12 ( V_3 ) )
return - V_115 ;
V_277 = V_222 -> V_217 . integer . V_217 [ 0 ] ;
V_278 = V_222 -> V_217 . integer . V_217 [ 1 ] ;
if ( V_277 < 0 || V_277 >= 2 * V_83 )
return - 1 ;
if ( V_278 < 0 || V_278 >= V_83 )
return - 1 ;
V_144 = V_222 -> V_217 . integer . V_217 [ 2 ] ;
F_25 ( & V_3 -> V_22 ) ;
if ( V_277 >= V_83 )
V_239 = V_144 != F_7 ( V_3 , V_278 ,
V_277 -
V_83 ) ;
else
V_239 = V_144 != F_6 ( V_3 , V_278 ,
V_277 ) ;
if ( V_239 ) {
if ( V_277 >= V_83 )
F_9 ( V_3 , V_278 ,
V_277 - V_83 ,
V_144 ) ;
else
F_8 ( V_3 , V_278 , V_277 ,
V_144 ) ;
}
F_27 ( & V_3 -> V_22 ) ;
return V_239 ;
}
static int F_139 ( struct V_211 * V_212 ,
struct V_213 * V_214 )
{
V_214 -> type = V_215 ;
V_214 -> V_216 = 1 ;
V_214 -> V_217 . integer . V_218 = 0 ;
V_214 -> V_217 . integer . V_219 = 64 ;
V_214 -> V_217 . integer . V_220 = 1 ;
return 0 ;
}
static int F_140 ( struct V_211 * V_212 ,
struct V_221 * V_222 )
{
struct V_3 * V_3 = F_64 ( V_212 ) ;
int V_279 ;
V_279 = V_222 -> V_146 . V_233 - 1 ;
if ( F_32 ( V_279 < 0 || V_279 >= V_83 ) )
return - V_112 ;
F_25 ( & V_3 -> V_22 ) ;
V_222 -> V_217 . integer . V_217 [ 0 ] =
( F_7 ( V_3 , V_279 , V_279 ) * 64 ) / V_145 ;
F_27 ( & V_3 -> V_22 ) ;
return 0 ;
}
static int F_141 ( struct V_211 * V_212 ,
struct V_221 * V_222 )
{
struct V_3 * V_3 = F_64 ( V_212 ) ;
int V_239 ;
int V_279 ;
int V_144 ;
if ( ! F_12 ( V_3 ) )
return - V_115 ;
V_279 = V_222 -> V_146 . V_233 - 1 ;
if ( F_32 ( V_279 < 0 || V_279 >= V_83 ) )
return - V_112 ;
V_144 = V_222 -> V_217 . integer . V_217 [ 0 ] * V_145 / 64 ;
F_25 ( & V_3 -> V_22 ) ;
V_239 =
V_144 != F_7 ( V_3 , V_279 ,
V_279 ) ;
if ( V_239 )
F_9 ( V_3 , V_279 , V_279 ,
V_144 ) ;
F_27 ( & V_3 -> V_22 ) ;
return V_239 ;
}
static int F_142 ( struct V_211 * V_212 ,
struct V_213 * V_214 )
{
static char * V_238 [] = { L_33 , L_34 , L_35 , L_36 } ;
V_214 -> type = V_227 ;
V_214 -> V_216 = 1 ;
V_214 -> V_217 . V_228 . V_229 = 4 ;
if ( V_214 -> V_217 . V_228 . V_230 >= V_214 -> V_217 . V_228 . V_229 )
V_214 -> V_217 . V_228 . V_230 =
V_214 -> V_217 . V_228 . V_229 - 1 ;
strcpy ( V_214 -> V_217 . V_228 . V_199 ,
V_238 [ V_214 -> V_217 . V_228 . V_230 ] ) ;
return 0 ;
}
static int F_143 ( struct V_3 * V_3 )
{
int V_25 , V_26 ;
switch ( V_3 -> V_31 ) {
case V_32 :
V_25 = F_4 ( V_3 , V_34 ) ;
if ( V_25 & V_280 )
return 2 ;
else if ( V_25 & V_49 )
return 1 ;
return 0 ;
break;
case V_46 :
V_26 = F_4 ( V_3 , V_33 ) ;
if ( V_26 & V_49 ) {
if ( V_26 & V_280 )
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
static int F_144 ( struct V_3 * V_3 )
{
int V_25 = F_4 ( V_3 , V_34 ) ;
if ( V_25 & V_43 ) {
if ( V_25 & V_281 )
return 2 ;
else
return 1 ;
}
return 0 ;
}
static int F_145 ( struct V_3 * V_3 , int V_226 )
{
int V_25 , V_22 , V_282 ;
V_25 = F_4 ( V_3 , V_223 ) ;
V_22 = ( V_25 & ( 0x1 << V_226 ) ) ? 1 : 0 ;
V_282 = ( V_25 & ( 0x100 << V_226 ) ) ? 1 : 0 ;
if ( V_22 && V_282 )
return 2 ;
else if ( V_22 )
return 1 ;
return 0 ;
}
static int F_146 ( struct V_3 * V_3 )
{
int V_25 , V_22 = 0 , V_282 = 0 ;
switch ( V_3 -> V_31 ) {
case V_48 :
case V_47 :
V_25 = F_4 ( V_3 , V_283 ) ;
V_22 = ( V_25 & 0x400 ) ? 1 : 0 ;
V_282 = ( V_25 & 0x800 ) ? 1 : 0 ;
break;
case V_46 :
case V_32 :
V_25 = F_4 ( V_3 , V_33 ) ;
V_22 = ( V_25 & V_284 ) ? 1 : 0 ;
V_282 = ( V_25 & V_285 ) ? 1 : 0 ;
break;
case V_42 :
break;
}
if ( V_22 && V_282 )
return 2 ;
else if ( V_22 )
return 1 ;
return 0 ;
}
static int F_147 ( struct V_3 * V_3 , int V_226 )
{
int V_26 , V_22 , V_282 ;
V_26 = F_4 ( V_3 , V_33 ) ;
V_22 = ( V_26 & ( 0x0080 >> V_226 ) ) ? 1 : 0 ;
V_282 = ( V_26 & ( 0x8000 >> V_226 ) ) ? 1 : 0 ;
if ( V_282 )
return 2 ;
else if ( V_22 )
return 1 ;
return 0 ;
}
static int F_148 ( struct V_3 * V_3 )
{
int V_25 ;
if ( V_3 -> V_224 ) {
switch ( V_3 -> V_31 ) {
case V_46 :
case V_32 :
V_25 = F_4 ( V_3 , V_34 ) ;
if ( V_25 & V_286 ) {
if ( V_25 & V_287 )
return 2 ;
else
return 1 ;
}
return 0 ;
break;
case V_48 :
case V_47 :
V_25 = F_4 ( V_3 , V_223 ) ;
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
static int F_149 ( struct V_211 * V_212 ,
struct V_221 * V_222 )
{
struct V_3 * V_3 = F_64 ( V_212 ) ;
int V_5 = - 1 ;
switch ( V_3 -> V_31 ) {
case V_48 :
switch ( V_212 -> V_232 ) {
case 0 :
V_5 = F_143 ( V_3 ) ; break;
case 7 :
V_5 = F_148 ( V_3 ) ; break;
case 8 :
V_5 = F_146 ( V_3 ) ; break;
default:
V_5 = F_145 ( V_3 , V_222 -> V_146 . V_233 - 1 ) ;
}
case V_47 :
switch ( V_212 -> V_232 ) {
case 0 :
V_5 = F_143 ( V_3 ) ; break;
case 4 :
V_5 = F_148 ( V_3 ) ; break;
case 5 :
V_5 = F_146 ( V_3 ) ; break;
default:
V_5 = F_145 ( V_3 , V_222 -> V_146 . V_233 - 1 ) ;
}
case V_46 :
switch ( V_212 -> V_232 ) {
case 0 :
V_5 = F_143 ( V_3 ) ; break;
case 1 :
V_5 = F_144 ( V_3 ) ; break;
case 2 :
V_5 = F_148 ( V_3 ) ; break;
case 3 :
V_5 = F_146 ( V_3 ) ; break;
}
case V_42 :
V_5 = F_144 ( V_3 ) ;
break;
case V_32 :
switch ( V_212 -> V_232 ) {
case 0 :
V_5 = F_143 ( V_3 ) ; break;
case 9 :
V_5 = F_148 ( V_3 ) ; break;
case 10 :
V_5 = F_146 ( V_3 ) ; break;
default:
V_5 = F_147 ( V_3 ,
V_212 -> V_232 - 1 ) ;
}
}
if ( - 1 == V_5 )
V_5 = 3 ;
V_222 -> V_217 . V_228 . V_230 [ 0 ] = V_5 ;
return 0 ;
}
static void F_150 ( struct V_3 * V_3 )
{
unsigned int V_288 [ 4 ] = { 0 , 0 , 0 , 0 } ;
switch ( V_3 -> V_224 -> V_158 ) {
case 0 :
V_288 [ 2 ] |= V_289 ;
break;
case 1 :
V_288 [ 2 ] |= V_290 ;
break;
default:
break;
}
switch ( V_3 -> V_224 -> V_291 ) {
case 1 :
V_288 [ 1 ] |= V_292 ;
break;
case 2 :
V_288 [ 1 ] |= V_293 ;
break;
case 3 :
V_288 [ 1 ] |= V_293 +
V_294 ;
break;
case 4 :
V_288 [ 1 ] |= V_292 +
V_293 ;
break;
case 5 :
V_288 [ 1 ] |= V_292 +
V_293 +
V_294 ;
break;
default:
break;
}
switch ( V_3 -> V_224 -> V_295 ) {
case 1 :
V_288 [ 2 ] |= V_296 ;
break;
case 2 :
V_288 [ 2 ] |= V_297 ;
break;
default:
break;
}
switch ( V_3 -> V_224 -> V_298 ) {
case 1 :
V_288 [ 2 ] |= V_299 ;
break;
case 2 :
V_288 [ 2 ] |= V_300 ;
break;
default:
break;
}
switch ( V_3 -> V_224 -> V_301 ) {
case 1 :
V_288 [ 2 ] |= V_302 ;
break;
case 2 :
V_288 [ 2 ] |= V_303 ;
break;
case 3 :
V_288 [ 2 ] |= V_302 + V_304 ;
break;
case 4 :
V_288 [ 2 ] |= V_303 + V_304 ;
break;
default:
break;
}
if ( 1 == V_3 -> V_224 -> V_305 ) {
V_288 [ 2 ] |= V_306 ;
}
F_2 ( V_3 , V_307 , V_288 [ 0 ] ) ;
F_2 ( V_3 , V_307 + 4 , V_288 [ 1 ] ) ;
F_2 ( V_3 , V_307 + 8 , V_288 [ 2 ] ) ;
F_2 ( V_3 , V_307 + 12 , V_288 [ 3 ] ) ;
}
static int F_151 ( struct V_211 * V_212 ,
struct V_213 * V_214 )
{
static char * V_238 [] = { L_37 , L_38 } ;
V_214 -> type = V_227 ;
V_214 -> V_216 = 1 ;
V_214 -> V_217 . V_228 . V_229 = 2 ;
if ( V_214 -> V_217 . V_228 . V_230 >= V_214 -> V_217 . V_228 . V_229 )
V_214 -> V_217 . V_228 . V_230 =
V_214 -> V_217 . V_228 . V_229 - 1 ;
strcpy ( V_214 -> V_217 . V_228 . V_199 ,
V_238 [ V_214 -> V_217 . V_228 . V_230 ] ) ;
return 0 ;
}
static int F_152 ( struct V_211 * V_212 ,
struct V_221 * V_222 )
{
struct V_3 * V_3 = F_64 ( V_212 ) ;
V_222 -> V_217 . V_228 . V_230 [ 0 ] = V_3 -> V_224 -> V_298 ;
return 0 ;
}
static int F_153 ( struct V_211 * V_212 ,
struct V_221 * V_222 )
{
struct V_3 * V_3 = F_64 ( V_212 ) ;
if ( V_3 -> V_224 -> V_298 != V_222 -> V_217 . V_228 . V_230 [ 0 ] ) {
V_3 -> V_224 -> V_298 = V_222 -> V_217 . V_228 . V_230 [ 0 ] ;
F_150 ( V_3 ) ;
return 1 ;
}
return 0 ;
}
static int F_154 ( struct V_211 * V_212 ,
struct V_213 * V_214 )
{
static char * V_238 [] = { L_39 , L_40 , L_41 , L_42 , L_43 } ;
V_214 -> type = V_227 ;
V_214 -> V_216 = 1 ;
V_214 -> V_217 . V_228 . V_229 = 5 ;
if ( V_214 -> V_217 . V_228 . V_230 >= V_214 -> V_217 . V_228 . V_229 )
V_214 -> V_217 . V_228 . V_230 =
V_214 -> V_217 . V_228 . V_229 - 1 ;
strcpy ( V_214 -> V_217 . V_228 . V_199 ,
V_238 [ V_214 -> V_217 . V_228 . V_230 ] ) ;
return 0 ;
}
static int F_155 ( struct V_211 * V_212 ,
struct V_221 * V_222 )
{
struct V_3 * V_3 = F_64 ( V_212 ) ;
V_222 -> V_217 . V_228 . V_230 [ 0 ] = V_3 -> V_224 -> V_301 ;
return 0 ;
}
static int F_156 ( struct V_211 * V_212 ,
struct V_221 * V_222 )
{
struct V_3 * V_3 = F_64 ( V_212 ) ;
if ( V_3 -> V_224 -> V_301 != V_222 -> V_217 . V_228 . V_230 [ 0 ] ) {
V_3 -> V_224 -> V_301 = V_222 -> V_217 . V_228 . V_230 [ 0 ] ;
F_150 ( V_3 ) ;
return 1 ;
}
return 0 ;
}
static int F_157 ( struct V_211 * V_212 ,
struct V_213 * V_214 )
{
static char * V_238 [] = { L_44 , L_45 , L_46 } ;
V_214 -> type = V_227 ;
V_214 -> V_216 = 1 ;
V_214 -> V_217 . V_228 . V_229 = 3 ;
if ( V_214 -> V_217 . V_228 . V_230 >= V_214 -> V_217 . V_228 . V_229 )
V_214 -> V_217 . V_228 . V_230 =
V_214 -> V_217 . V_228 . V_229 - 1 ;
strcpy ( V_214 -> V_217 . V_228 . V_199 ,
V_238 [ V_214 -> V_217 . V_228 . V_230 ] ) ;
return 0 ;
}
static int F_158 ( struct V_211 * V_212 ,
struct V_221 * V_222 )
{
struct V_3 * V_3 = F_64 ( V_212 ) ;
V_222 -> V_217 . V_228 . V_230 [ 0 ] = V_3 -> V_224 -> V_295 ;
return 0 ;
}
static int F_159 ( struct V_211 * V_212 ,
struct V_221 * V_222 )
{
struct V_3 * V_3 = F_64 ( V_212 ) ;
if ( V_3 -> V_224 -> V_295 != V_222 -> V_217 . V_228 . V_230 [ 0 ] ) {
V_3 -> V_224 -> V_295 = V_222 -> V_217 . V_228 . V_230 [ 0 ] ;
F_150 ( V_3 ) ;
return 1 ;
}
return 0 ;
}
static int F_160 ( struct V_211 * V_212 ,
struct V_213 * V_214 )
{
static char * V_238 [] = { L_47 , L_48 , L_49 ,
L_50 , L_51 , L_52 } ;
V_214 -> type = V_227 ;
V_214 -> V_216 = 1 ;
V_214 -> V_217 . V_228 . V_229 = 6 ;
if ( V_214 -> V_217 . V_228 . V_230 >= V_214 -> V_217 . V_228 . V_229 )
V_214 -> V_217 . V_228 . V_230 =
V_214 -> V_217 . V_228 . V_229 - 1 ;
strcpy ( V_214 -> V_217 . V_228 . V_199 ,
V_238 [ V_214 -> V_217 . V_228 . V_230 ] ) ;
return 0 ;
}
static int F_161 ( struct V_211 * V_212 ,
struct V_221 * V_222 )
{
struct V_3 * V_3 = F_64 ( V_212 ) ;
V_222 -> V_217 . V_228 . V_230 [ 0 ] = V_3 -> V_224 -> V_291 ;
return 0 ;
}
static int F_162 ( struct V_211 * V_212 ,
struct V_221 * V_222 )
{
struct V_3 * V_3 = F_64 ( V_212 ) ;
if ( V_3 -> V_224 -> V_291 != V_222 -> V_217 . V_228 . V_230 [ 0 ] ) {
V_3 -> V_224 -> V_291 = V_222 -> V_217 . V_228 . V_230 [ 0 ] ;
F_150 ( V_3 ) ;
return 1 ;
}
return 0 ;
}
static int F_163 ( struct V_211 * V_212 ,
struct V_213 * V_214 )
{
static char * V_238 [] = { L_53 , L_54 , L_55 } ;
V_214 -> type = V_227 ;
V_214 -> V_216 = 1 ;
V_214 -> V_217 . V_228 . V_229 = 3 ;
if ( V_214 -> V_217 . V_228 . V_230 >= V_214 -> V_217 . V_228 . V_229 )
V_214 -> V_217 . V_228 . V_230 =
V_214 -> V_217 . V_228 . V_229 - 1 ;
strcpy ( V_214 -> V_217 . V_228 . V_199 ,
V_238 [ V_214 -> V_217 . V_228 . V_230 ] ) ;
return 0 ;
}
static int F_164 ( struct V_211 * V_212 ,
struct V_221 * V_222 )
{
struct V_3 * V_3 = F_64 ( V_212 ) ;
V_222 -> V_217 . V_228 . V_230 [ 0 ] = V_3 -> V_224 -> V_158 ;
return 0 ;
}
static int F_165 ( struct V_211 * V_212 ,
struct V_221 * V_222 )
{
struct V_3 * V_3 = F_64 ( V_212 ) ;
if ( V_3 -> V_224 -> V_158 != V_222 -> V_217 . V_228 . V_230 [ 0 ] ) {
V_3 -> V_224 -> V_158 = V_222 -> V_217 . V_228 . V_230 [ 0 ] ;
F_150 ( V_3 ) ;
return 1 ;
}
return 0 ;
}
static int F_166 ( struct V_211 * V_212 ,
struct V_213 * V_214 )
{
V_214 -> type = V_308 ;
V_214 -> V_216 = 1 ;
V_214 -> V_217 . integer . V_218 = 0 ;
V_214 -> V_217 . integer . V_219 = 1 ;
return 0 ;
}
static int F_167 ( struct V_211 * V_212 ,
struct V_221 * V_222 )
{
struct V_3 * V_3 = F_64 ( V_212 ) ;
V_222 -> V_217 . V_228 . V_230 [ 0 ] = V_3 -> V_224 -> V_305 ;
return 0 ;
}
static int F_168 ( struct V_211 * V_212 ,
struct V_221 * V_222 )
{
struct V_3 * V_3 = F_64 ( V_212 ) ;
if ( V_3 -> V_224 -> V_305 != V_222 -> V_217 . V_228 . V_230 [ 0 ] ) {
V_3 -> V_224 -> V_305 = V_222 -> V_217 . V_228 . V_230 [ 0 ] ;
F_150 ( V_3 ) ;
return 1 ;
}
return 0 ;
}
static int F_169 ( struct V_3 * V_3 )
{
int V_16 ;
for ( V_16 = V_3 -> V_133 ; V_16 < V_3 -> V_125 ; ++ V_16 ) {
if ( V_3 -> V_99 > 48000 ) {
V_3 -> V_309 [ V_16 ] -> V_310 [ 0 ] . V_311 =
V_312 |
V_313 |
V_314 ;
} else {
V_3 -> V_309 [ V_16 ] -> V_310 [ 0 ] . V_311 =
V_315 |
V_314 ;
}
F_170 ( V_3 -> V_172 , V_316 |
V_317 ,
& V_3 -> V_309 [ V_16 ] -> V_146 ) ;
}
return 0 ;
}
static int F_171 ( struct V_171 * V_172 ,
struct V_3 * V_3 )
{
unsigned int V_226 , V_318 ;
int V_173 ;
struct V_211 * V_319 ;
struct V_320 * V_321 = NULL ;
switch ( V_3 -> V_31 ) {
case V_46 :
V_321 = V_322 ;
V_318 = F_172 ( V_322 ) ;
break;
case V_42 :
V_321 = V_323 ;
V_318 = F_172 ( V_323 ) ;
break;
case V_47 :
V_321 = V_324 ;
V_318 = F_172 ( V_324 ) ;
break;
case V_48 :
V_321 = V_325 ;
V_318 = F_172 ( V_325 ) ;
break;
case V_32 :
V_321 = V_326 ;
V_318 = F_172 ( V_326 ) ;
break;
}
if ( NULL != V_321 ) {
for ( V_226 = 0 ; V_226 < V_318 ; V_226 ++ ) {
V_173 = F_173 ( V_172 ,
F_174 ( & V_321 [ V_226 ] , V_3 ) ) ;
if ( V_173 < 0 )
return V_173 ;
}
}
V_327 . V_199 = L_56 ;
if ( V_3 -> V_99 >= 128000 ) {
V_318 = V_3 -> V_139 ;
} else if ( V_3 -> V_99 >= 64000 ) {
V_318 = V_3 -> V_133 ;
} else {
V_318 = V_3 -> V_125 ;
}
for ( V_226 = 0 ; V_226 < V_318 ; ++ V_226 ) {
V_327 . V_233 = V_226 + 1 ;
V_319 = F_174 ( & V_327 , V_3 ) ;
V_173 = F_173 ( V_172 , V_319 ) ;
if ( V_173 < 0 )
return V_173 ;
V_3 -> V_309 [ V_226 ] = V_319 ;
}
if ( V_3 -> V_224 ) {
V_321 = V_328 ;
V_318 = F_172 ( V_328 ) ;
for ( V_226 = 0 ; V_226 < V_318 ; V_226 ++ ) {
V_173 = F_173 ( V_172 ,
F_174 ( & V_321 [ V_226 ] , V_3 ) ) ;
if ( V_173 < 0 )
return V_173 ;
}
}
return 0 ;
}
static void
F_175 ( struct V_329 * V_330 ,
struct V_331 * V_332 )
{
struct V_3 * V_3 = V_330 -> V_165 ;
unsigned int V_25 , V_26 , V_333 , V_334 ;
char * V_335 ;
char * V_336 ;
char * V_337 ;
char * V_338 ;
int V_339 , V_340 ;
int V_341 , V_342 , V_85 , V_343 , V_344 , V_345 ;
unsigned int V_87 ;
T_2 V_88 = 0 ;
V_15 V_29 ;
V_25 = F_4 ( V_3 , V_34 ) ;
V_26 = F_4 ( V_3 , V_33 ) ;
V_333 = V_3 -> V_70 ;
V_334 = F_4 ( V_3 , V_35 ) ;
F_176 ( V_332 , L_57 ,
V_3 -> V_346 , V_3 -> V_172 -> V_347 + 1 ,
V_3 -> V_348 ,
( V_26 & V_349 ) |
( V_26 & V_350 ) | ( V_26 &
V_351 ) ) ;
F_176 ( V_332 , L_58 ,
( F_4 ( V_3 , V_188 ) >> 8 ) & 0xFFFFFF ,
( F_4 ( V_3 , V_182 ) >> 8 ) & 0xFFFFFF ) ;
F_176 ( V_332 , L_59 ,
V_3 -> V_179 , V_3 -> V_352 , ( unsigned long ) V_3 -> V_6 ) ;
F_176 ( V_332 , L_60 ) ;
F_176 ( V_332 ,
L_61 ,
V_25 & V_353 ,
( V_25 & V_186 ) ? 1 : 0 ,
( V_25 & V_192 ) ? 1 : 0 ,
V_3 -> V_354 ) ;
F_176 ( V_332 ,
L_62
L_63 ,
( ( V_25 & V_76 ) ? 1 : 0 ) ,
( V_25 & V_75 ) ,
( V_25 & V_75 ) %
( 2 * ( int ) V_3 -> V_73 ) ,
( ( V_25 & V_75 ) - 64 ) %
( 2 * ( int ) V_3 -> V_73 ) ,
( long ) F_20 ( V_3 ) * 4 ) ;
F_176 ( V_332 ,
L_64 ,
F_4 ( V_3 , V_184 ) & 0xFF ,
F_4 ( V_3 , V_190 ) & 0xFF ,
F_4 ( V_3 , V_182 ) & 0xFF ,
F_4 ( V_3 , V_188 ) & 0xFF ) ;
F_176 ( V_332 ,
L_65 ,
F_4 ( V_3 , V_175 ) & 0xFF ,
F_4 ( V_3 , V_177 ) & 0xFF ) ;
F_176 ( V_332 ,
L_66
L_67 ,
V_3 -> V_70 , V_3 -> V_355 ,
V_25 , V_26 ) ;
if ( V_25 & V_356 ) {
F_176 ( V_332 , L_68 ) ;
V_341 = F_4 ( V_3 , V_357 + 4 ) ;
if ( V_341 & V_358 ) {
F_176 ( V_332 , L_69 ) ;
switch ( V_341 & ( V_292 |
V_293 ) ) {
case 0 :
F_176 ( V_332 , L_70 ) ;
break;
case V_292 :
F_176 ( V_332 , L_71 ) ;
break;
case V_293 :
F_176 ( V_332 , L_72 ) ;
break;
default:
F_176 ( V_332 , L_73 ) ;
break;
}
if ( V_341 & V_294 ) {
F_176 ( V_332 , L_74 ) ;
} else {
F_176 ( V_332 , L_75 ) ;
}
} else {
F_176 ( V_332 , L_76 ) ;
}
if ( V_341 & V_359 ) {
F_176 ( V_332 , L_77 ) ;
} else if ( V_341 & V_360 ) {
F_176 ( V_332 , L_78 ) ;
} else {
F_176 ( V_332 , L_79 ) ;
}
if ( V_341 & V_361 ) {
F_176 ( V_332 , L_80 ) ;
} else {
F_176 ( V_332 , L_81 ) ;
}
switch ( V_3 -> V_31 ) {
case V_46 :
case V_32 :
V_88 = 110069313433624ULL ;
break;
case V_48 :
case V_47 :
V_88 = 104857600000000ULL ;
break;
case V_42 :
break;
}
V_87 = F_4 ( V_3 , V_210 ) ;
F_176 ( V_332 , L_82 , V_87 ) ;
V_29 = F_30 ( V_88 , V_87 ) ;
if ( V_333 & V_71 ) {
V_29 *= 4 ;
} else if ( V_333 & V_72 ) {
V_29 *= 2 ;
}
F_176 ( V_332 , L_83 ,
( unsigned int ) V_29 ) ;
V_342 = F_4 ( V_3 , V_357 ) ;
V_85 = V_342 & 0xF ;
V_342 >>= 4 ;
V_85 += ( V_342 & 0x3 ) * 10 ;
V_342 >>= 4 ;
V_343 = V_342 & 0xF ;
V_342 >>= 4 ;
V_343 += ( V_342 & 0x7 ) * 10 ;
V_342 >>= 4 ;
V_344 = V_342 & 0xF ;
V_342 >>= 4 ;
V_344 += ( V_342 & 0x7 ) * 10 ;
V_342 >>= 4 ;
V_345 = V_342 & 0xF ;
V_342 >>= 4 ;
V_345 += ( V_342 & 0x3 ) * 10 ;
F_176 ( V_332 ,
L_84 ,
V_345 , V_344 , V_343 , V_85 ) ;
} else {
F_176 ( V_332 , L_85 ) ;
}
F_176 ( V_332 , L_86 ) ;
V_339 = F_17 ( V_3 ) ;
F_176 ( V_332 ,
L_87 ,
V_339 , ( unsigned long ) V_3 -> V_73 ) ;
F_176 ( V_332 , L_88 ,
( V_3 -> V_70 & V_262 ) ? L_89 : L_90 ) ;
switch ( V_3 -> V_70 & V_362 ) {
case V_363 :
V_338 = L_91 ;
break;
case V_364 :
V_338 = L_92 ;
break;
default:
V_338 = L_93 ;
}
F_176 ( V_332 ,
L_94
L_95 ,
( V_3 -> V_70 & V_265 ) ? L_96 : L_90 ,
( V_3 -> V_70 & V_264 ) ? L_97 : L_98 ,
( V_3 -> V_70 & V_266 ) ? L_96 : L_90 ) ;
if ( ! ( V_3 -> V_70 & V_95 ) )
V_337 = L_13 ;
else
V_337 = L_12 ;
F_176 ( V_332 , L_99 , V_337 ) ;
switch ( F_81 ( V_3 ) ) {
case V_365 :
V_335 = L_24 ;
break;
case V_366 :
V_335 = L_100 ;
break;
case V_367 :
V_335 = L_26 ;
break;
case V_368 :
V_335 = L_27 ;
break;
default:
V_335 = L_101 ;
break;
}
F_176 ( V_332 , L_102 ,
V_335 ) ;
F_176 ( V_332 , L_103 ,
V_3 -> V_99 ) ;
F_176 ( V_332 , L_104 ) ;
V_339 = V_25 & V_281 ;
V_340 = V_26 & V_280 ;
F_176 ( V_332 , L_105 ,
( V_25 & V_43 ) ? ( V_339 ? L_35 : L_34 ) :
L_106 ,
( V_26 & V_49 ) ? ( V_340 ? L_35 : L_34 ) :
L_106 ) ;
switch ( F_16 ( V_3 ) ) {
case V_260 :
V_336 = L_27 ;
break;
case V_258 :
V_336 = L_26 ;
break;
case V_254 :
V_336 = L_24 ;
break;
case V_256 :
V_336 = L_100 ;
break;
case V_98 :
V_336 = L_107 ;
break;
default:
V_336 = L_108 ;
break;
}
F_176 ( V_332 ,
L_109 ,
V_336 , F_15 ( V_3 ) ,
( V_25 & V_60 ) >> 22 ,
( V_26 & V_51 ) >> 5 ) ;
F_176 ( V_332 , L_110 ,
( V_25 & V_369 ) ? L_111 : L_91 ,
( V_25 & V_370 ) ? L_112 :
L_113 ) ;
F_176 ( V_332 , L_114 ) ;
}
static void
F_177 ( struct V_329 * V_330 ,
struct V_331 * V_332 )
{
struct V_3 * V_3 = V_330 -> V_165 ;
unsigned int V_25 ;
unsigned int V_26 ;
unsigned int V_27 ;
int V_371 ;
char * V_336 ;
int V_339 ;
V_25 = F_4 ( V_3 , V_34 ) ;
V_26 = F_4 ( V_3 , V_33 ) ;
V_27 = F_4 ( V_3 , V_35 ) ;
F_176 ( V_332 , L_115 ,
V_3 -> V_346 , V_3 -> V_172 -> V_347 + 1 ,
V_3 -> V_348 ) ;
F_176 ( V_332 , L_59 ,
V_3 -> V_179 , V_3 -> V_352 , ( unsigned long ) V_3 -> V_6 ) ;
F_176 ( V_332 , L_60 ) ;
F_176 ( V_332 ,
L_61 ,
V_25 & V_353 ,
( V_25 & V_186 ) ? 1 : 0 ,
( V_25 & V_192 ) ? 1 : 0 ,
V_3 -> V_354 ) ;
F_176 ( V_332 ,
L_62
L_63 ,
( ( V_25 & V_76 ) ? 1 : 0 ) ,
( V_25 & V_75 ) ,
( V_25 & V_75 ) %
( 2 * ( int ) V_3 -> V_73 ) ,
( ( V_25 & V_75 ) - 64 ) %
( 2 * ( int ) V_3 -> V_73 ) ,
( long ) F_20 ( V_3 ) * 4 ) ;
F_176 ( V_332 ,
L_64 ,
F_4 ( V_3 , V_184 ) & 0xFF ,
F_4 ( V_3 , V_190 ) & 0xFF ,
F_4 ( V_3 , V_182 ) & 0xFF ,
F_4 ( V_3 , V_188 ) & 0xFF ) ;
F_176 ( V_332 ,
L_65 ,
F_4 ( V_3 , V_175 ) & 0xFF ,
F_4 ( V_3 , V_177 ) & 0xFF ) ;
F_176 ( V_332 ,
L_66
L_67 ,
V_3 -> V_70 , V_3 -> V_355 ,
V_25 , V_26 ) ;
F_176 ( V_332 , L_86 ) ;
V_339 = F_17 ( V_3 ) ;
F_176 ( V_332 ,
L_87 ,
V_339 , ( unsigned long ) V_3 -> V_73 ) ;
F_176 ( V_332 , L_88 ,
( V_3 ->
V_70 & V_262 ) ? L_89 : L_90 ) ;
F_176 ( V_332 ,
L_116 ,
( V_3 ->
V_70 & V_265 ) ? L_96 : L_90 ,
( V_3 ->
V_70 & V_267 ) ? L_96 : L_90 ,
( V_3 ->
V_70 & V_269 ) ? L_96 : L_90 ) ;
V_371 = F_81 ( V_3 ) ;
if ( V_371 == 0 )
F_176 ( V_332 , L_117 ) ;
else
F_176 ( V_332 , L_118 ,
V_371 ) ;
F_176 ( V_332 , L_103 ,
V_3 -> V_99 ) ;
F_176 ( V_332 , L_119 ,
V_3 -> V_70 & V_273 ?
L_120 : L_121 ) ;
F_176 ( V_332 , L_122 ,
V_3 -> V_70 & V_275 ?
L_120 :
V_3 -> V_70 & V_276 ?
L_123 : L_121 ) ;
F_176 ( V_332 , L_104 ) ;
F_176 ( V_332 , L_124 ,
( V_25 & V_37 ) ? L_125 : L_33 ,
F_1 ( ( V_25 >> V_38 ) & 0xF ) ) ;
for ( V_339 = 0 ; V_339 < 8 ; V_339 ++ ) {
F_176 ( V_332 , L_126 ,
V_339 + 1 ,
( V_26 & ( V_41 >> V_339 ) ) ?
L_125 : L_33 ,
F_1 ( ( V_27 >> ( 4 * V_339 ) ) & 0xF ) ) ;
}
switch ( F_16 ( V_3 ) ) {
case V_253 :
V_336 = L_23 ; break;
case V_36 :
V_336 = L_24 ; break;
case V_39 :
V_336 = L_15 ; break;
case V_372 :
V_336 = L_16 ; break;
case V_373 :
V_336 = L_17 ; break;
case V_374 :
V_336 = L_18 ; break;
case V_375 :
V_336 = L_19 ; break;
case V_376 :
V_336 = L_20 ; break;
case V_377 :
V_336 = L_21 ; break;
case V_40 :
V_336 = L_22 ; break;
default:
V_336 = L_108 ; break;
}
F_176 ( V_332 , L_127 , V_336 ) ;
F_176 ( V_332 , L_114 ) ;
}
static void
F_178 ( struct V_329 * V_330 ,
struct V_331 * V_332 )
{
struct V_3 * V_3 = V_330 -> V_165 ;
unsigned int V_378 , V_26 , V_379 , V_333 , V_16 ;
unsigned int V_22 , V_282 ;
V_378 = F_4 ( V_3 , V_223 ) ;
V_26 = F_4 ( V_3 , V_225 ) ;
V_379 = F_4 ( V_3 , V_283 ) ;
V_333 = V_3 -> V_70 ;
F_176 ( V_332 , L_128 , V_378 ) ;
F_176 ( V_332 , L_129 , V_26 ) ;
F_176 ( V_332 , L_130 , V_379 ) ;
F_176 ( V_332 , L_131 ) ;
F_176 ( V_332 , L_132 ,
( F_71 ( V_3 ) == 0 ) ? L_133 : L_134 ) ;
F_176 ( V_332 , L_135 ,
F_61 ( V_3 ) ) ;
F_176 ( V_332 , L_136 ) ;
V_22 = 0x1 ;
V_282 = 0x100 ;
for ( V_16 = 0 ; V_16 < 8 ; V_16 ++ ) {
F_176 ( V_332 , L_137 ,
V_16 ,
( V_378 & V_22 ) ? 1 : 0 ,
( V_378 & V_282 ) ? 1 : 0 ,
V_231 [ ( V_26 >> ( V_16 * 4 ) ) & 0xF ] ) ;
V_22 = V_22 << 1 ;
V_282 = V_282 << 1 ;
}
F_176 ( V_332 , L_138 ,
( V_378 & 0x1000000 ) ? 1 : 0 ,
( V_378 & 0x2000000 ) ? 1 : 0 ,
V_231 [ ( V_378 >> 16 ) & 0xF ] ) ;
F_176 ( V_332 , L_139 ,
( V_378 & 0x4000000 ) ? 1 : 0 ,
( V_378 & 0x8000000 ) ? 1 : 0 ,
V_231 [ ( V_378 >> 20 ) & 0xF ] ) ;
F_176 ( V_332 , L_140 ,
( V_379 & 0x400 ) ? 1 : 0 ,
( V_379 & 0x800 ) ? 1 : 0 ,
V_231 [ ( V_26 >> 12 ) & 0xF ] ) ;
}
static void
F_179 ( struct V_329 * V_330 ,
struct V_331 * V_332 )
{
struct V_3 * V_3 = V_330 -> V_165 ;
int V_143 , V_16 ;
for ( V_16 = 0 ; V_16 < 256 ; V_16 += V_143 ) {
F_176 ( V_332 , L_141 , V_16 ) ;
for ( V_143 = 0 ; V_143 < 16 ; V_143 += 4 )
F_176 ( V_332 , L_142 , F_4 ( V_3 , V_16 + V_143 ) ) ;
F_176 ( V_332 , L_114 ) ;
}
}
static void F_180 ( struct V_329 * V_330 ,
struct V_331 * V_332 )
{
struct V_3 * V_3 = V_330 -> V_165 ;
int V_16 ;
F_176 ( V_332 , L_143 ) ;
for ( V_16 = 0 ; V_16 < V_3 -> V_122 ; V_16 ++ ) {
F_176 ( V_332 , L_144 , V_16 + 1 , V_3 -> V_126 [ V_16 ] ) ;
}
}
static void F_181 ( struct V_329 * V_330 ,
struct V_331 * V_332 )
{
struct V_3 * V_3 = V_330 -> V_165 ;
int V_16 ;
F_176 ( V_332 , L_143 ) ;
for ( V_16 = 0 ; V_16 < V_3 -> V_124 ; V_16 ++ ) {
F_176 ( V_332 , L_144 , V_16 + 1 , V_3 -> V_128 [ V_16 ] ) ;
}
}
static void T_3 F_182 ( struct V_3 * V_3 )
{
struct V_329 * V_330 ;
if ( ! F_183 ( V_3 -> V_172 , L_145 , & V_330 ) ) {
switch ( V_3 -> V_31 ) {
case V_32 :
F_184 ( V_330 , V_3 ,
F_177 ) ;
break;
case V_46 :
F_184 ( V_330 , V_3 ,
F_175 ) ;
break;
case V_42 :
break;
case V_48 :
F_184 ( V_330 , V_3 ,
F_178 ) ;
break;
case V_47 :
break;
}
}
if ( ! F_183 ( V_3 -> V_172 , L_146 , & V_330 ) ) {
F_184 ( V_330 , V_3 , F_180 ) ;
}
if ( ! F_183 ( V_3 -> V_172 , L_147 , & V_330 ) ) {
F_184 ( V_330 , V_3 , F_181 ) ;
}
#ifdef F_185
if ( ! F_183 ( V_3 -> V_172 , L_148 , & V_330 ) )
F_184 ( V_330 , V_3 ,
F_179 ) ;
#endif
}
static int F_186 ( struct V_3 * V_3 )
{
V_3 -> V_234 = 0 ;
switch ( V_3 -> V_31 ) {
case V_46 :
case V_42 :
V_3 -> V_70 =
0x2 + 0x8 + 0x10 + 0x80 + 0x400 + 0x4000 + 0x1000000 ;
break;
case V_48 :
case V_47 :
V_3 -> V_234 = 0x1 + 0x1000 ;
V_3 -> V_70 =
0x2 + 0x8 + 0x10 + 0x80 + 0x400 + 0x4000 + 0x1000000 ;
break;
case V_32 :
V_3 -> V_70 =
V_95 |
F_26 ( 7 ) |
V_241 |
V_262 |
V_271 ;
break;
}
F_2 ( V_3 , V_80 , V_3 -> V_70 ) ;
if ( V_32 == V_3 -> V_31 ) {
#ifdef F_187
V_3 -> V_355 = V_380 ;
#else
V_3 -> V_355 = 0 ;
#endif
F_2 ( V_3 , V_381 , V_3 -> V_355 ) ;
}
F_19 ( V_3 ) ;
F_35 ( V_3 , 0 * V_145 ) ;
if ( V_3 -> V_31 == V_47 || V_3 -> V_31 == V_48 ) {
F_2 ( V_3 , V_237 , V_3 -> V_234 ) ;
}
F_33 ( V_3 , 48000 , 1 ) ;
return 0 ;
}
static T_4 F_188 ( int V_179 , void * V_382 )
{
struct V_3 * V_3 = (struct V_3 * ) V_382 ;
unsigned int V_25 ;
int V_16 , V_383 , V_147 , V_384 = 0 ;
V_25 = F_4 ( V_3 , V_34 ) ;
V_383 = V_25 & V_353 ;
V_147 = V_25 & ( V_186 | V_192 |
V_180 | V_197 ) ;
if ( ! V_383 && ! V_147 )
return V_385 ;
F_2 ( V_3 , V_386 , 0 ) ;
V_3 -> V_354 ++ ;
if ( V_383 ) {
if ( V_3 -> V_387 )
F_189 ( V_3 -> V_387 ) ;
if ( V_3 -> V_388 )
F_189 ( V_3 -> V_388 ) ;
}
if ( V_147 ) {
V_16 = 0 ;
while ( V_16 < V_3 -> V_209 ) {
if ( ( F_4 ( V_3 ,
V_3 -> V_147 [ V_16 ] . V_150 ) & 0xff ) &&
( V_25 & V_3 -> V_147 [ V_16 ] . V_179 ) ) {
V_3 -> V_70 &= ~ V_3 -> V_147 [ V_16 ] . V_160 ;
F_2 ( V_3 , V_80 ,
V_3 -> V_70 ) ;
V_3 -> V_147 [ V_16 ] . V_159 = 1 ;
V_384 = 1 ;
}
V_16 ++ ;
}
if ( V_384 )
F_190 ( & V_3 -> V_389 ) ;
}
return V_390 ;
}
static T_1 F_191 ( struct V_391
* V_162 )
{
struct V_3 * V_3 = F_192 ( V_162 ) ;
return F_20 ( V_3 ) ;
}
static int F_193 ( struct V_391 * V_162 )
{
struct V_392 * V_393 = V_162 -> V_393 ;
struct V_3 * V_3 = F_192 ( V_162 ) ;
struct V_391 * V_394 ;
if ( V_162 -> V_395 == V_396 )
V_394 = V_3 -> V_387 ;
else
V_394 = V_3 -> V_388 ;
if ( V_3 -> V_397 )
V_393 -> V_25 -> V_398 = F_20 ( V_3 ) ;
else
V_393 -> V_25 -> V_398 = 0 ;
if ( V_394 ) {
struct V_391 * V_77 ;
struct V_392 * V_399 = V_394 -> V_393 ;
F_194 (s, substream) {
if ( V_77 == V_394 ) {
V_399 -> V_25 -> V_398 =
V_393 -> V_25 -> V_398 ;
break;
}
}
}
return 0 ;
}
static int F_195 ( struct V_391 * V_162 ,
struct V_400 * V_401 )
{
struct V_3 * V_3 = F_192 ( V_162 ) ;
int V_173 ;
int V_16 ;
T_5 V_402 ;
T_5 V_403 ;
F_25 ( & V_3 -> V_22 ) ;
if ( V_162 -> V_404 -> V_395 == V_396 ) {
V_402 = V_3 -> V_23 ;
V_403 = V_3 -> V_24 ;
} else {
V_402 = V_3 -> V_24 ;
V_403 = V_3 -> V_23 ;
}
if ( V_403 > 0 && V_402 != V_403 ) {
if ( F_196 ( V_401 ) != V_3 -> V_99 ) {
F_27 ( & V_3 -> V_22 ) ;
F_197 ( V_401 ,
V_405 ) ;
return - V_115 ;
}
if ( F_198 ( V_401 ) != V_3 -> V_73 / 4 ) {
F_27 ( & V_3 -> V_22 ) ;
F_197 ( V_401 ,
V_406 ) ;
return - V_115 ;
}
}
F_27 ( & V_3 -> V_22 ) ;
F_25 ( & V_3 -> V_22 ) ;
V_173 = F_33 ( V_3 , F_196 ( V_401 ) , 0 ) ;
if ( V_173 < 0 ) {
F_34 ( V_407 L_149 , V_173 ) ;
F_27 ( & V_3 -> V_22 ) ;
F_197 ( V_401 ,
V_405 ) ;
return V_173 ;
}
F_27 ( & V_3 -> V_22 ) ;
V_173 = F_24 ( V_3 ,
F_198 ( V_401 ) ) ;
if ( V_173 < 0 ) {
F_34 ( V_407 L_150 , V_173 ) ;
F_197 ( V_401 ,
V_406 ) ;
return V_173 ;
}
V_173 =
F_199 ( V_162 , V_408 ) ;
if ( V_173 < 0 ) {
F_34 ( V_407 L_151 , V_173 ) ;
return V_173 ;
}
if ( V_162 -> V_395 == V_396 ) {
F_200 ( V_3 , V_162 , V_409 ,
F_201 ( V_401 ) ) ;
for ( V_16 = 0 ; V_16 < F_201 ( V_401 ) ; ++ V_16 )
F_11 ( V_3 , V_16 , 1 ) ;
V_3 -> V_82 =
( unsigned char * ) V_162 -> V_393 -> V_410 ;
F_202 ( L_152 ,
V_3 -> V_82 ) ;
} else {
F_200 ( V_3 , V_162 , V_411 ,
F_201 ( V_401 ) ) ;
for ( V_16 = 0 ; V_16 < F_201 ( V_401 ) ; ++ V_16 )
F_10 ( V_3 , V_16 , 1 ) ;
V_3 -> V_412 =
( unsigned char * ) V_162 -> V_393 -> V_410 ;
F_202 ( L_153 ,
V_3 -> V_412 ) ;
}
if ( V_413 == F_203 ( V_401 ) ) {
if ( ! ( V_3 -> V_70 & V_414 ) )
F_34 ( V_407 L_154 ) ;
V_3 -> V_70 |= V_414 ;
} else if ( V_415 == F_203 ( V_401 ) ) {
if ( V_3 -> V_70 & V_414 )
F_34 ( V_407 L_155 ) ;
V_3 -> V_70 &= ~ V_414 ;
}
F_2 ( V_3 , V_80 , V_3 -> V_70 ) ;
return 0 ;
}
static int F_204 ( struct V_391 * V_162 )
{
int V_16 ;
struct V_3 * V_3 = F_192 ( V_162 ) ;
if ( V_162 -> V_395 == V_396 ) {
for ( V_16 = 0 ; V_16 < V_3 -> V_124 ; ++ V_16 )
F_11 ( V_3 , V_16 , 0 ) ;
V_3 -> V_82 = NULL ;
} else {
for ( V_16 = 0 ; V_16 < V_3 -> V_122 ; ++ V_16 )
F_10 ( V_3 , V_16 , 0 ) ;
V_3 -> V_412 = NULL ;
}
F_205 ( V_162 ) ;
return 0 ;
}
static int F_206 ( struct V_391 * V_162 ,
struct V_416 * V_417 )
{
struct V_3 * V_3 = F_192 ( V_162 ) ;
if ( V_162 -> V_395 == V_396 ) {
if ( F_32 ( V_417 -> V_279 >= V_3 -> V_124 ) ) {
F_34 ( V_407 L_156 , V_417 -> V_279 ) ;
return - V_112 ;
}
if ( V_3 -> V_120 [ V_417 -> V_279 ] < 0 ) {
F_34 ( V_407 L_157 , V_417 -> V_279 ) ;
return - V_112 ;
}
V_417 -> V_418 = V_3 -> V_120 [ V_417 -> V_279 ] *
V_84 ;
} else {
if ( F_32 ( V_417 -> V_279 >= V_3 -> V_122 ) ) {
F_34 ( V_407 L_158 , V_417 -> V_279 ) ;
return - V_112 ;
}
if ( V_3 -> V_118 [ V_417 -> V_279 ] < 0 ) {
F_34 ( V_407 L_159 , V_417 -> V_279 ) ;
return - V_112 ;
}
V_417 -> V_418 = V_3 -> V_118 [ V_417 -> V_279 ] *
V_84 ;
}
V_417 -> V_419 = 0 ;
V_417 -> V_220 = 32 ;
return 0 ;
}
static int F_207 ( struct V_391 * V_162 ,
unsigned int V_420 , void * V_208 )
{
switch ( V_420 ) {
case V_421 :
return F_193 ( V_162 ) ;
case V_422 :
{
struct V_416 * V_417 = V_208 ;
return F_206 ( V_162 , V_417 ) ;
}
default:
break;
}
return F_208 ( V_162 , V_420 , V_208 ) ;
}
static int F_209 ( struct V_391 * V_162 , int V_420 )
{
struct V_3 * V_3 = F_192 ( V_162 ) ;
struct V_391 * V_394 ;
int V_397 ;
F_210 ( & V_3 -> V_22 ) ;
V_397 = V_3 -> V_397 ;
switch ( V_420 ) {
case V_423 :
V_397 |= 1 << V_162 -> V_395 ;
break;
case V_424 :
V_397 &= ~ ( 1 << V_162 -> V_395 ) ;
break;
default:
F_29 () ;
F_211 ( & V_3 -> V_22 ) ;
return - V_112 ;
}
if ( V_162 -> V_395 == V_396 )
V_394 = V_3 -> V_387 ;
else
V_394 = V_3 -> V_388 ;
if ( V_394 ) {
struct V_391 * V_77 ;
F_194 (s, substream) {
if ( V_77 == V_394 ) {
F_212 ( V_77 , V_162 ) ;
if ( V_420 == V_423 )
V_397 |= 1 << V_77 -> V_395 ;
else
V_397 &= ~ ( 1 << V_77 -> V_395 ) ;
goto V_425;
}
}
if ( V_420 == V_423 ) {
if ( ! ( V_397 & ( 1 << V_396 ) )
&& V_162 -> V_395 ==
V_426 )
F_23 ( V_3 ) ;
} else {
if ( V_397 &&
V_162 -> V_395 == V_396 )
F_23 ( V_3 ) ;
}
} else {
if ( V_162 -> V_395 == V_426 )
F_23 ( V_3 ) ;
}
V_425:
F_212 ( V_162 , V_162 ) ;
if ( ! V_3 -> V_397 && V_397 )
F_21 ( V_3 ) ;
else if ( V_3 -> V_397 && ! V_397 )
F_22 ( V_3 ) ;
V_3 -> V_397 = V_397 ;
F_211 ( & V_3 -> V_22 ) ;
return 0 ;
}
static int F_213 ( struct V_391 * V_162 )
{
return 0 ;
}
static int F_214 ( struct V_400 * V_401 ,
struct V_427 * V_428 )
{
struct V_3 * V_3 = V_428 -> V_429 ;
struct V_430 * V_431 =
F_215 ( V_401 , V_432 ) ;
struct V_430 * V_433 =
F_215 ( V_401 , V_405 ) ;
if ( V_433 -> V_218 > 96000 && V_433 -> V_219 <= 192000 ) {
struct V_430 V_434 = {
. V_218 = V_3 -> V_138 ,
. V_219 = V_3 -> V_138 ,
. integer = 1 ,
} ;
return F_216 ( V_431 , & V_434 ) ;
} else if ( V_433 -> V_218 > 48000 && V_433 -> V_219 <= 96000 ) {
struct V_430 V_434 = {
. V_218 = V_3 -> V_132 ,
. V_219 = V_3 -> V_132 ,
. integer = 1 ,
} ;
return F_216 ( V_431 , & V_434 ) ;
} else if ( V_433 -> V_219 < 64000 ) {
struct V_430 V_434 = {
. V_218 = V_3 -> V_123 ,
. V_219 = V_3 -> V_123 ,
. integer = 1 ,
} ;
return F_216 ( V_431 , & V_434 ) ;
}
return 0 ;
}
static int F_217 ( struct V_400 * V_401 ,
struct V_427 * V_428 )
{
struct V_3 * V_3 = V_428 -> V_429 ;
struct V_430 * V_431 =
F_215 ( V_401 , V_432 ) ;
struct V_430 * V_433 =
F_215 ( V_401 , V_405 ) ;
if ( V_433 -> V_218 > 96000 && V_433 -> V_219 <= 192000 ) {
struct V_430 V_434 = {
. V_218 = V_3 -> V_139 ,
. V_219 = V_3 -> V_139 ,
. integer = 1 ,
} ;
return F_216 ( V_431 , & V_434 ) ;
} else if ( V_433 -> V_218 > 48000 && V_433 -> V_219 <= 96000 ) {
struct V_430 V_434 = {
. V_218 = V_3 -> V_133 ,
. V_219 = V_3 -> V_133 ,
. integer = 1 ,
} ;
return F_216 ( V_431 , & V_434 ) ;
} else if ( V_433 -> V_219 < 64000 ) {
struct V_430 V_434 = {
. V_218 = V_3 -> V_125 ,
. V_219 = V_3 -> V_125 ,
. integer = 1 ,
} ;
return F_216 ( V_431 , & V_434 ) ;
} else {
}
return 0 ;
}
static int F_218 ( struct V_400 * V_401 ,
struct V_427 * V_428 )
{
struct V_3 * V_3 = V_428 -> V_429 ;
struct V_430 * V_431 =
F_215 ( V_401 , V_432 ) ;
struct V_430 * V_433 =
F_215 ( V_401 , V_405 ) ;
if ( V_431 -> V_218 >= V_3 -> V_123 ) {
struct V_430 V_434 = {
. V_218 = 32000 ,
. V_219 = 48000 ,
. integer = 1 ,
} ;
return F_216 ( V_433 , & V_434 ) ;
} else if ( V_431 -> V_219 <= V_3 -> V_138 ) {
struct V_430 V_434 = {
. V_218 = 128000 ,
. V_219 = 192000 ,
. integer = 1 ,
} ;
return F_216 ( V_433 , & V_434 ) ;
} else if ( V_431 -> V_219 <= V_3 -> V_132 ) {
struct V_430 V_434 = {
. V_218 = 64000 ,
. V_219 = 96000 ,
. integer = 1 ,
} ;
return F_216 ( V_433 , & V_434 ) ;
}
return 0 ;
}
static int F_219 ( struct V_400 * V_401 ,
struct V_427 * V_428 )
{
struct V_3 * V_3 = V_428 -> V_429 ;
struct V_430 * V_431 =
F_215 ( V_401 , V_432 ) ;
struct V_430 * V_433 =
F_215 ( V_401 , V_405 ) ;
if ( V_431 -> V_218 >= V_3 -> V_125 ) {
struct V_430 V_434 = {
. V_218 = 32000 ,
. V_219 = 48000 ,
. integer = 1 ,
} ;
return F_216 ( V_433 , & V_434 ) ;
} else if ( V_431 -> V_219 <= V_3 -> V_139 ) {
struct V_430 V_434 = {
. V_218 = 128000 ,
. V_219 = 192000 ,
. integer = 1 ,
} ;
return F_216 ( V_433 , & V_434 ) ;
} else if ( V_431 -> V_219 <= V_3 -> V_133 ) {
struct V_430 V_434 = {
. V_218 = 64000 ,
. V_219 = 96000 ,
. integer = 1 ,
} ;
return F_216 ( V_433 , & V_434 ) ;
}
return 0 ;
}
static int F_220 ( struct V_400 * V_401 ,
struct V_427 * V_428 )
{
unsigned int V_321 [ 3 ] ;
struct V_3 * V_3 = V_428 -> V_429 ;
struct V_430 * V_431 = F_215 ( V_401 ,
V_432 ) ;
V_321 [ 0 ] = V_3 -> V_138 ;
V_321 [ 1 ] = V_3 -> V_132 ;
V_321 [ 2 ] = V_3 -> V_123 ;
return F_221 ( V_431 , 3 , V_321 , 0 ) ;
}
static int F_222 ( struct V_400 * V_401 ,
struct V_427 * V_428 )
{
unsigned int V_321 [ 3 ] ;
struct V_3 * V_3 = V_428 -> V_429 ;
struct V_430 * V_431 = F_215 ( V_401 ,
V_432 ) ;
V_321 [ 0 ] = V_3 -> V_139 ;
V_321 [ 1 ] = V_3 -> V_133 ;
V_321 [ 2 ] = V_3 -> V_125 ;
return F_221 ( V_431 , 3 , V_321 , 0 ) ;
}
static int F_223 ( struct V_391 * V_162 )
{
struct V_3 * V_3 = F_192 ( V_162 ) ;
struct V_392 * V_393 = V_162 -> V_393 ;
F_25 ( & V_3 -> V_22 ) ;
F_224 ( V_162 ) ;
V_393 -> V_435 = V_436 ;
if ( V_3 -> V_387 == NULL )
F_22 ( V_3 ) ;
V_3 -> V_23 = V_437 -> V_438 ;
V_3 -> V_388 = V_162 ;
F_27 ( & V_3 -> V_22 ) ;
F_225 ( V_393 , 0 , 32 , 24 ) ;
F_226 ( V_393 , 0 , V_406 ) ;
switch ( V_3 -> V_31 ) {
case V_47 :
case V_48 :
F_227 ( V_393 ,
V_406 ,
32 , 4096 ) ;
F_227 ( V_393 ,
V_439 ,
16384 , 16384 ) ;
break;
default:
F_227 ( V_393 ,
V_406 ,
64 , 8192 ) ;
break;
}
if ( V_32 == V_3 -> V_31 ) {
V_393 -> V_435 . V_440 |= V_441 ;
F_228 ( V_393 , 0 , V_405 ,
& V_442 ) ;
} else {
F_229 ( V_393 , 0 , V_405 ,
F_219 , V_3 ,
V_432 , - 1 ) ;
}
F_229 ( V_393 , 0 , V_432 ,
F_222 , V_3 ,
V_432 , - 1 ) ;
F_229 ( V_393 , 0 , V_432 ,
F_217 , V_3 ,
V_405 , - 1 ) ;
return 0 ;
}
static int F_230 ( struct V_391 * V_162 )
{
struct V_3 * V_3 = F_192 ( V_162 ) ;
F_25 ( & V_3 -> V_22 ) ;
V_3 -> V_23 = - 1 ;
V_3 -> V_388 = NULL ;
F_27 ( & V_3 -> V_22 ) ;
return 0 ;
}
static int F_231 ( struct V_391 * V_162 )
{
struct V_3 * V_3 = F_192 ( V_162 ) ;
struct V_392 * V_393 = V_162 -> V_393 ;
F_25 ( & V_3 -> V_22 ) ;
F_224 ( V_162 ) ;
V_393 -> V_435 = V_443 ;
if ( V_3 -> V_388 == NULL )
F_22 ( V_3 ) ;
V_3 -> V_24 = V_437 -> V_438 ;
V_3 -> V_387 = V_162 ;
F_27 ( & V_3 -> V_22 ) ;
F_225 ( V_393 , 0 , 32 , 24 ) ;
F_226 ( V_393 , 0 , V_406 ) ;
switch ( V_3 -> V_31 ) {
case V_47 :
case V_48 :
F_227 ( V_393 ,
V_406 ,
32 , 4096 ) ;
F_227 ( V_393 ,
V_439 ,
16384 , 16384 ) ;
break;
default:
F_227 ( V_393 ,
V_406 ,
64 , 8192 ) ;
break;
}
if ( V_32 == V_3 -> V_31 ) {
V_393 -> V_435 . V_440 |= V_441 ;
F_228 ( V_393 , 0 , V_405 ,
& V_442 ) ;
} else {
F_229 ( V_393 , 0 , V_405 ,
F_218 , V_3 ,
V_432 , - 1 ) ;
}
F_229 ( V_393 , 0 , V_432 ,
F_220 , V_3 ,
V_432 , - 1 ) ;
F_229 ( V_393 , 0 , V_432 ,
F_214 , V_3 ,
V_405 , - 1 ) ;
return 0 ;
}
static int F_232 ( struct V_391 * V_162 )
{
struct V_3 * V_3 = F_192 ( V_162 ) ;
F_25 ( & V_3 -> V_22 ) ;
V_3 -> V_24 = - 1 ;
V_3 -> V_387 = NULL ;
F_27 ( & V_3 -> V_22 ) ;
return 0 ;
}
static int F_233 ( struct V_444 * V_435 , struct V_445 * V_445 )
{
return 0 ;
}
static inline int F_234 ( void T_6 * V_446 , void T_7 * V_447 )
{
V_15 V_5 = F_5 ( V_447 ) ;
return F_235 ( V_446 , & V_5 , 4 ) ;
}
static int F_236 ( struct V_444 * V_435 , struct V_445 * V_445 ,
unsigned int V_420 , unsigned long V_208 )
{
void T_6 * V_448 = ( void T_6 * ) V_208 ;
struct V_3 * V_3 = V_435 -> V_165 ;
struct V_449 V_10 ;
struct V_450 V_417 ;
struct V_451 V_25 ;
struct V_452 V_452 ;
struct V_453 * V_454 ;
struct V_455 V_342 ;
unsigned int V_456 ;
long unsigned int V_77 ;
int V_16 = 0 ;
switch ( V_420 ) {
case V_457 :
V_454 = & V_3 -> V_458 ;
for ( V_16 = 0 ; V_16 < V_83 ; V_16 ++ ) {
V_454 -> V_459 [ V_16 ] =
F_5 ( V_3 -> V_6 +
V_460 + V_16 * 4 ) ;
V_454 -> V_461 [ V_16 ] =
F_5 ( V_3 -> V_6 +
V_462 + V_16 * 4 ) ;
V_454 -> V_463 [ V_16 ] =
F_5 ( V_3 -> V_6 +
V_464 + V_16 * 4 ) ;
V_454 -> V_465 [ V_16 ] =
( ( V_466 ) F_5 ( V_3 -> V_6 +
V_467 + V_16 * 4 ) << 32 ) |
( V_466 ) F_5 ( V_3 -> V_6 +
V_468 + V_16 * 4 ) ;
V_454 -> V_469 [ V_16 ] =
( ( V_466 ) F_5 ( V_3 -> V_6 +
V_470 + V_16 * 4 ) << 32 ) |
( V_466 ) F_5 ( V_3 -> V_6 +
V_471 + V_16 * 4 ) ;
V_454 -> V_472 [ V_16 ] =
( ( V_466 ) F_5 ( V_3 -> V_6 +
V_473 + V_16 * 4 ) << 32 ) |
( V_466 ) F_5 ( V_3 -> V_6 +
V_474 + V_16 * 4 ) ;
}
if ( V_3 -> V_99 > 96000 ) {
V_454 -> V_475 = V_476 ;
} else if ( V_3 -> V_99 > 48000 ) {
V_454 -> V_475 = V_274 ;
} else {
V_454 -> V_475 = V_477 ;
}
V_454 -> V_26 = F_4 ( V_3 , V_33 ) ;
V_77 = F_235 ( V_448 , V_454 , sizeof( struct V_453 ) ) ;
if ( 0 != V_77 ) {
return - V_478 ;
}
break;
case V_479 :
V_342 . V_342 = F_4 ( V_3 , V_357 ) ;
V_16 = F_4 ( V_3 , V_357 + 4 ) ;
if ( V_16 & V_358 ) {
switch ( V_16 & ( V_292 |
V_293 ) ) {
case 0 :
V_342 . V_480 = V_481 ;
break;
case V_292 :
V_342 . V_480 = V_482 ;
break;
case V_293 :
V_342 . V_480 = V_483 ;
break;
default:
V_342 . V_480 = 30 ;
break;
}
if ( V_16 & V_294 ) {
V_342 . V_484 = V_485 ;
} else {
V_342 . V_484 = V_486 ;
}
} else {
V_342 . V_480 = V_487 ;
V_342 . V_484 = V_488 ;
}
if ( V_16 & V_359 ) {
V_342 . V_489 = V_490 ;
} else if ( V_16 & V_360 ) {
V_342 . V_489 = V_491 ;
} else {
V_342 . V_489 = V_492 ;
}
V_77 = F_235 ( V_448 , & V_342 , sizeof( struct V_455 ) ) ;
if ( 0 != V_77 ) {
return - V_478 ;
}
break;
case V_493 :
memset ( & V_417 , 0 , sizeof( V_417 ) ) ;
F_25 ( & V_3 -> V_22 ) ;
V_417 . V_335 = F_81 ( V_3 ) ;
V_417 . V_494 = F_143 ( V_3 ) ;
V_417 . V_99 = V_3 -> V_99 ;
V_417 . V_495 =
F_15 ( V_3 ) ;
V_417 . V_337 = F_71 ( V_3 ) ;
V_417 . V_496 = F_76 ( V_3 ) ;
V_417 . V_336 = F_16 ( V_3 ) ;
V_417 . V_497 = F_88 ( V_3 ) ;
V_417 . V_498 = 0 ;
F_27 ( & V_3 -> V_22 ) ;
if ( F_235 ( V_448 , & V_417 , sizeof( V_417 ) ) )
return - V_478 ;
break;
case V_499 :
memset ( & V_25 , 0 , sizeof( V_25 ) ) ;
V_25 . V_500 = V_3 -> V_31 ;
V_25 . V_501 = F_16 ( V_3 ) ;
V_25 . V_502 = 110069313433624ULL ;
V_25 . V_503 = F_4 ( V_3 , V_210 ) ;
switch ( V_3 -> V_31 ) {
case V_46 :
case V_42 :
V_25 . V_504 . V_505 . V_506 =
F_143 ( V_3 ) ;
V_25 . V_504 . V_505 . V_507 =
F_144 ( V_3 ) ;
V_25 . V_504 . V_505 . V_508 =
F_148 ( V_3 ) ;
V_25 . V_504 . V_505 . V_509 =
F_146 ( V_3 ) ;
V_456 =
F_4 ( V_3 , V_34 ) ;
V_25 . V_504 . V_505 . V_510 =
( V_456 & V_369 ) ? 1 : 0 ;
V_25 . V_504 . V_505 . V_511 =
( V_456 & V_370 ) ? 1 : 0 ;
V_25 . V_504 . V_505 . V_512 = 0 ;
default:
break;
}
if ( F_235 ( V_448 , & V_25 , sizeof( V_25 ) ) )
return - V_478 ;
break;
case V_513 :
memset ( & V_452 , 0 , sizeof( V_452 ) ) ;
V_452 . V_500 = V_3 -> V_31 ;
strncpy ( V_452 . V_514 , V_3 -> V_346 ,
sizeof( V_452 . V_514 ) ) ;
V_452 . V_515 = ( F_4 ( V_3 ,
V_182 ) >> 8 ) & 0xFFFFFF ;
V_452 . V_348 = V_3 -> V_348 ;
V_452 . V_516 = 0 ;
if ( V_3 -> V_224 )
V_452 . V_516 |= V_517 ;
if ( F_235 ( V_448 , & V_452 ,
sizeof( V_452 ) ) )
return - V_478 ;
break;
case V_518 :
if ( F_237 ( & V_10 , V_448 , sizeof( V_10 ) ) )
return - V_478 ;
if ( F_235 ( ( void T_6 * ) V_10 . V_10 , V_3 -> V_10 ,
sizeof( struct V_519 ) ) )
return - V_478 ;
break;
default:
return - V_112 ;
}
return 0 ;
}
static int T_3 F_238 ( struct V_171 * V_172 ,
struct V_3 * V_3 )
{
struct V_444 * V_435 ;
int V_173 ;
V_173 = F_239 ( V_172 , L_160 , 0 , & V_435 ) ;
if ( V_173 < 0 )
return V_173 ;
V_3 -> V_520 = V_435 ;
V_435 -> V_165 = V_3 ;
strcpy ( V_435 -> V_199 , L_161 ) ;
V_435 -> V_521 . V_522 = F_233 ;
V_435 -> V_521 . V_523 = F_236 ;
V_435 -> V_521 . V_524 = F_233 ;
return 0 ;
}
static int T_3 F_240 ( struct V_3 * V_3 )
{
int V_173 ;
struct V_525 * V_526 ;
T_8 V_527 ;
V_526 = V_3 -> V_526 ;
V_527 = V_408 ;
V_173 =
F_241 ( V_526 ,
V_528 ,
F_242 ( V_3 -> V_529 ) ,
V_527 ,
V_527 ) ;
if ( V_173 < 0 ) {
F_202 ( L_162 , V_527 ) ;
return V_173 ;
} else
F_202 ( L_163 , V_527 ) ;
return 0 ;
}
static void F_200 ( struct V_3 * V_3 ,
struct V_391 * V_162 ,
unsigned int V_4 , int V_530 )
{
int V_16 ;
for ( V_16 = 0 ; V_16 < ( V_530 * 16 ) ; V_16 ++ )
F_2 ( V_3 , V_4 + 4 * V_16 ,
F_243 ( V_162 , 4096 * V_16 ) ) ;
}
static int T_3 F_244 ( struct V_171 * V_172 ,
struct V_3 * V_3 )
{
struct V_525 * V_526 ;
int V_173 ;
V_173 = F_245 ( V_172 , V_3 -> V_346 , 0 , 1 , 1 , & V_526 ) ;
if ( V_173 < 0 )
return V_173 ;
V_3 -> V_526 = V_526 ;
V_526 -> V_165 = V_3 ;
strcpy ( V_526 -> V_199 , V_3 -> V_346 ) ;
F_246 ( V_526 , V_396 ,
& V_531 ) ;
F_246 ( V_526 , V_426 ,
& V_532 ) ;
V_526 -> V_204 = V_533 ;
V_173 = F_240 ( V_3 ) ;
if ( V_173 < 0 )
return V_173 ;
return 0 ;
}
static inline void F_247 ( struct V_3 * V_3 )
{
int V_16 ;
for ( V_16 = 0 ; V_16 < V_3 -> V_209 ; V_16 ++ )
F_40 ( V_3 , V_16 ) ;
}
static int T_3 F_248 ( struct V_171 * V_172 ,
struct V_3 * V_3 )
{
int V_173 , V_16 ;
F_202 ( L_164 ) ;
V_173 = F_244 ( V_172 , V_3 ) ;
if ( V_173 < 0 )
return V_173 ;
V_16 = 0 ;
while ( V_16 < V_3 -> V_209 ) {
V_173 = F_56 ( V_172 , V_3 , V_16 ) ;
if ( V_173 < 0 ) {
return V_173 ;
}
V_16 ++ ;
}
V_173 = F_171 ( V_172 , V_3 ) ;
if ( V_173 < 0 )
return V_173 ;
V_173 = F_238 ( V_172 , V_3 ) ;
if ( V_173 < 0 )
return V_173 ;
F_202 ( L_165 ) ;
F_182 ( V_3 ) ;
V_3 -> V_99 = - 1 ;
V_3 -> V_534 = - 1 ;
V_3 -> V_535 = - 1 ;
V_3 -> V_23 = - 1 ;
V_3 -> V_24 = - 1 ;
V_3 -> V_387 = NULL ;
V_3 -> V_388 = NULL ;
F_202 ( L_166 ) ;
V_173 = F_186 ( V_3 ) ;
if ( V_173 < 0 )
return V_173 ;
F_202 ( L_167 ) ;
F_169 ( V_3 ) ;
F_202 ( L_168 ) ;
V_173 = F_249 ( V_172 ) ;
if ( V_173 < 0 ) {
F_34 ( V_113 L_169 ) ;
return V_173 ;
}
F_202 ( L_170 ) ;
return 0 ;
}
static int T_3 F_250 ( struct V_171 * V_172 ,
struct V_3 * V_3 ) {
struct V_536 * V_529 = V_3 -> V_529 ;
int V_173 ;
unsigned long V_537 ;
V_3 -> V_179 = - 1 ;
V_3 -> V_172 = V_172 ;
F_57 ( & V_3 -> V_22 ) ;
F_251 ( V_3 -> V_529 ,
V_538 , & V_3 -> V_348 ) ;
strcpy ( V_172 -> V_539 , L_171 ) ;
strcpy ( V_172 -> V_540 , L_172 ) ;
switch ( V_3 -> V_348 ) {
case V_541 :
V_3 -> V_31 = V_48 ;
V_3 -> V_346 = L_173 ;
V_3 -> V_209 = 2 ;
break;
case V_542 :
V_3 -> V_31 = V_47 ;
V_3 -> V_346 = L_174 ;
V_3 -> V_209 = 1 ;
break;
case V_543 :
V_3 -> V_31 = V_42 ;
V_3 -> V_346 = L_175 ;
V_3 -> V_209 = 1 ;
break;
default:
if ( ( V_3 -> V_348 == 0xf0 ) ||
( ( V_3 -> V_348 >= 0xe6 ) &&
( V_3 -> V_348 <= 0xea ) ) ) {
V_3 -> V_31 = V_32 ;
V_3 -> V_346 = L_176 ;
V_3 -> V_209 = 2 ;
} else if ( ( V_3 -> V_348 == 0xd2 ) ||
( ( V_3 -> V_348 >= 0xc8 ) &&
( V_3 -> V_348 <= 0xcf ) ) ) {
V_3 -> V_31 = V_46 ;
V_3 -> V_346 = L_177 ;
V_3 -> V_209 = 3 ;
} else {
F_34 ( V_113
L_178 ,
V_3 -> V_348 ) ;
return - V_544 ;
}
}
V_173 = F_252 ( V_529 ) ;
if ( V_173 < 0 )
return V_173 ;
F_253 ( V_3 -> V_529 ) ;
V_173 = F_254 ( V_529 , L_145 ) ;
if ( V_173 < 0 )
return V_173 ;
V_3 -> V_352 = F_255 ( V_529 , 0 ) ;
V_537 = F_256 ( V_529 , 0 ) ;
F_202 ( L_179 ,
V_3 -> V_352 , V_3 -> V_352 + V_537 - 1 ) ;
V_3 -> V_6 = F_257 ( V_3 -> V_352 , V_537 ) ;
if ( ! V_3 -> V_6 ) {
F_34 ( V_113 L_1
L_180 ,
V_3 -> V_352 , V_3 -> V_352 + V_537 - 1 ) ;
return - V_115 ;
}
F_202 ( L_181 ,
( unsigned long ) V_3 -> V_6 , V_3 -> V_352 ,
V_3 -> V_352 + V_537 - 1 ) ;
if ( F_258 ( V_529 -> V_179 , F_188 ,
V_545 , V_546 , V_3 ) ) {
F_34 ( V_113 L_182 , V_529 -> V_179 ) ;
return - V_115 ;
}
F_202 ( L_183 , V_529 -> V_179 ) ;
V_3 -> V_179 = V_529 -> V_179 ;
F_202 ( L_184 ,
sizeof( struct V_519 ) ) ;
V_3 -> V_10 = F_259 ( sizeof( struct V_519 ) , V_547 ) ;
if ( ! V_3 -> V_10 ) {
F_34 ( V_113 L_1
L_185 ,
( int ) sizeof( struct V_519 ) ) ;
return V_173 ;
}
V_3 -> V_126 = NULL ;
V_3 -> V_128 = NULL ;
switch ( V_3 -> V_31 ) {
case V_32 :
V_3 -> V_123 = V_3 -> V_125 = V_548 ;
V_3 -> V_132 = V_3 -> V_133 = V_548 ;
V_3 -> V_138 = V_3 -> V_139 = V_548 ;
V_3 -> V_119 = V_3 -> V_121 =
V_549 ;
V_3 -> V_130 = V_3 -> V_131 =
V_549 ;
V_3 -> V_136 = V_3 -> V_137 =
V_549 ;
V_3 -> V_127 = V_3 -> V_129 =
V_550 ;
V_3 -> V_134 = V_3 -> V_135 =
V_550 ;
V_3 -> V_140 = V_3 -> V_141 =
V_550 ;
V_3 -> V_124 = V_3 -> V_122 =
V_548 ;
V_3 -> V_126 = V_3 -> V_128 =
V_550 ;
V_3 -> V_118 = V_3 -> V_120 =
V_549 ;
break;
case V_46 :
case V_42 :
V_3 -> V_123 = V_3 -> V_125 =
V_551 ;
V_3 -> V_132 = V_3 -> V_133 =
V_552 ;
V_3 -> V_138 = V_3 -> V_139 =
V_553 ;
V_3 -> V_119 = V_3 -> V_121 =
V_554 ;
V_3 -> V_130 = V_3 -> V_131 =
V_554 ;
V_3 -> V_136 = V_3 -> V_137 =
V_554 ;
V_3 -> V_127 = V_3 -> V_129 =
V_555 ;
V_3 -> V_134 = V_3 -> V_135 =
V_555 ;
V_3 -> V_140 = V_3 -> V_141 =
V_555 ;
break;
case V_47 :
if ( 0 == ( F_4 ( V_3 , V_33 ) & V_556 ) ) {
F_34 ( V_407 L_186 ) ;
}
V_3 -> V_123 = V_557 ;
V_3 -> V_132 = V_558 ;
V_3 -> V_138 = V_559 ;
V_3 -> V_125 = V_560 ;
V_3 -> V_133 = V_561 ;
V_3 -> V_139 = V_562 ;
V_3 -> V_121 = V_563 ;
V_3 -> V_131 = V_564 ;
V_3 -> V_137 = V_565 ;
V_3 -> V_119 = V_566 ;
V_3 -> V_130 = V_567 ;
V_3 -> V_136 = V_568 ;
V_3 -> V_127 = V_569 ;
V_3 -> V_129 = V_570 ;
V_3 -> V_134 = V_571 ;
V_3 -> V_135 = V_572 ;
V_3 -> V_140 = V_573 ;
V_3 -> V_141 = V_574 ;
break;
case V_48 :
V_3 -> V_123 = V_3 -> V_125 =
V_575 ;
V_3 -> V_132 = V_3 -> V_133 =
V_576 ;
V_3 -> V_138 = V_3 -> V_139 =
V_577 ;
V_3 -> V_122 = V_575 ;
V_3 -> V_124 = V_575 ;
V_3 -> V_119 = V_3 -> V_121 =
V_578 ;
V_3 -> V_130 = V_3 -> V_131 =
V_579 ;
V_3 -> V_136 = V_3 -> V_137 =
V_580 ;
V_3 -> V_118 = V_3 -> V_120 =
V_578 ;
V_3 -> V_127 = V_3 -> V_129 =
V_581 ;
V_3 -> V_134 = V_3 -> V_135 =
V_582 ;
V_3 -> V_140 = V_3 -> V_141 =
V_583 ;
break;
}
switch ( V_3 -> V_31 ) {
case V_47 :
case V_48 :
if ( F_4 ( V_3 , V_33 ) &
V_584 ) {
V_3 -> V_209 ++ ;
V_3 -> V_224 = F_259 ( sizeof( struct V_585 ) ,
V_547 ) ;
if ( NULL != V_3 -> V_224 ) {
F_150 ( V_3 ) ;
}
F_34 ( V_407 L_187 ) ;
} else {
V_3 -> V_224 = NULL ;
}
break;
case V_46 :
if ( F_4 ( V_3 , V_34 ) & V_356 ) {
V_3 -> V_209 ++ ;
V_3 -> V_224 = F_259 ( sizeof( struct V_585 ) ,
V_547 ) ;
if ( NULL != V_3 -> V_224 ) {
F_150 ( V_3 ) ;
}
F_34 ( V_407 L_188 ) ;
} else {
V_3 -> V_224 = NULL ;
}
break;
default:
V_3 -> V_224 = NULL ;
}
switch ( V_3 -> V_31 ) {
case V_32 :
if ( V_3 -> V_224 ) {
V_3 -> V_250 = V_586 ;
V_3 -> V_249 = 10 ;
} else {
V_3 -> V_250 = V_587 ;
V_3 -> V_249 = 9 ;
}
break;
case V_46 :
if ( V_3 -> V_224 ) {
V_3 -> V_250 = V_588 ;
V_3 -> V_249 = 4 ;
} else {
V_3 -> V_250 = V_589 ;
V_3 -> V_249 = 3 ;
}
break;
case V_42 :
break;
case V_48 :
if ( V_3 -> V_224 ) {
V_3 -> V_250 = V_590 ;
V_3 -> V_249 = 9 ;
} else {
V_3 -> V_250 = V_591 ;
V_3 -> V_249 = 8 ;
}
break;
case V_47 :
if ( V_3 -> V_224 ) {
V_3 -> V_250 = V_592 ;
V_3 -> V_249 = 6 ;
} else {
V_3 -> V_250 = V_593 ;
V_3 -> V_249 = 5 ;
}
break;
}
F_260 ( & V_3 -> V_389 ,
F_60 , ( unsigned long ) V_3 ) ;
F_202 ( L_189 ) ;
V_173 = F_248 ( V_172 , V_3 ) ;
if ( V_173 < 0 )
return V_173 ;
F_247 ( V_3 ) ;
return 0 ;
}
static int F_261 ( struct V_3 * V_3 )
{
if ( V_3 -> V_352 ) {
V_3 -> V_70 &=
~ ( V_79 | V_78 |
V_185 | V_191 |
V_178 | V_196 ) ;
F_2 ( V_3 , V_80 ,
V_3 -> V_70 ) ;
}
if ( V_3 -> V_179 >= 0 )
F_262 ( V_3 -> V_179 , ( void * ) V_3 ) ;
F_263 ( V_3 -> V_10 ) ;
if ( V_3 -> V_6 )
F_264 ( V_3 -> V_6 ) ;
if ( V_3 -> V_352 )
F_265 ( V_3 -> V_529 ) ;
F_266 ( V_3 -> V_529 ) ;
return 0 ;
}
static void F_267 ( struct V_171 * V_172 )
{
struct V_3 * V_3 = V_172 -> V_165 ;
if ( V_3 )
F_261 ( V_3 ) ;
}
static int T_3 F_268 ( struct V_536 * V_529 ,
const struct V_594 * V_595 )
{
static int V_596 ;
struct V_3 * V_3 ;
struct V_171 * V_172 ;
int V_173 ;
if ( V_596 >= V_597 )
return - V_544 ;
if ( ! V_598 [ V_596 ] ) {
V_596 ++ ;
return - V_599 ;
}
V_173 = F_269 ( V_233 [ V_596 ] , V_146 [ V_596 ] ,
V_600 , sizeof( struct V_3 ) , & V_172 ) ;
if ( V_173 < 0 )
return V_173 ;
V_3 = V_172 -> V_165 ;
V_172 -> V_601 = F_267 ;
V_3 -> V_596 = V_596 ;
V_3 -> V_529 = V_529 ;
F_270 ( V_172 , & V_529 -> V_596 ) ;
V_173 = F_250 ( V_172 , V_3 ) ;
if ( V_173 < 0 ) {
F_271 ( V_172 ) ;
return V_173 ;
}
if ( V_3 -> V_31 != V_42 ) {
sprintf ( V_172 -> V_198 , L_190 ,
V_3 -> V_346 ,
( F_4 ( V_3 , V_182 ) >> 8 ) & 0xFFFFFF ) ;
sprintf ( V_172 -> V_602 , L_191 ,
V_3 -> V_346 ,
( F_4 ( V_3 , V_182 ) >> 8 ) & 0xFFFFFF ,
V_3 -> V_352 , V_3 -> V_179 ) ;
} else {
sprintf ( V_172 -> V_198 , L_192 , V_3 -> V_346 ) ;
sprintf ( V_172 -> V_602 , L_193 ,
V_3 -> V_346 , V_3 -> V_352 , V_3 -> V_179 ) ;
}
V_173 = F_249 ( V_172 ) ;
if ( V_173 < 0 ) {
F_271 ( V_172 ) ;
return V_173 ;
}
F_272 ( V_529 , V_172 ) ;
V_596 ++ ;
return 0 ;
}
static void T_9 F_273 ( struct V_536 * V_529 )
{
F_271 ( F_274 ( V_529 ) ) ;
F_272 ( V_529 , NULL ) ;
}
static int T_10 F_275 ( void )
{
return F_276 ( & V_540 ) ;
}
static void T_11 F_277 ( void )
{
F_278 ( & V_540 ) ;
}
