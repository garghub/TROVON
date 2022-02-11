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
static int F_56 ( struct V_171 * V_172 ,
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
if ( V_29 > 207000 ) {
if ( 0 == F_62 ( V_3 ) ) {
V_29 = V_3 -> V_99 ;
} else {
V_29 = F_15 ( V_3 ) ;
}
}
return V_29 ;
}
static int F_63 ( struct V_211 * V_212 ,
struct V_213 * V_214 )
{
V_214 -> type = V_215 ;
V_214 -> V_216 = 1 ;
V_214 -> V_217 . integer . V_218 = 27000 ;
V_214 -> V_217 . integer . V_219 = 207000 ;
V_214 -> V_217 . integer . V_220 = 1 ;
return 0 ;
}
static int F_64 ( struct V_211 * V_212 ,
struct V_221 *
V_222 )
{
struct V_3 * V_3 = F_65 ( V_212 ) ;
V_222 -> V_217 . integer . V_217 [ 0 ] = F_61 ( V_3 ) ;
return 0 ;
}
static int F_66 ( struct V_211 * V_212 ,
struct V_221 *
V_222 )
{
struct V_3 * V_3 = F_65 ( V_212 ) ;
F_31 ( V_3 , V_222 -> V_217 . V_223 . V_224 [ 0 ] ) ;
return 0 ;
}
static int F_67 ( struct V_3 * V_3 )
{
int V_25 ;
switch ( V_3 -> V_31 ) {
case V_48 :
case V_47 :
V_25 = F_4 ( V_3 , V_225 ) ;
return ( V_25 >> 16 ) & 0xF ;
break;
default:
break;
}
return 0 ;
}
static int F_68 ( struct V_3 * V_3 )
{
int V_25 ;
if ( V_3 -> V_226 ) {
switch ( V_3 -> V_31 ) {
case V_48 :
case V_47 :
V_25 = F_4 ( V_3 , V_225 ) ;
return ( V_25 >> 20 ) & 0xF ;
break;
default:
break;
}
}
return 0 ;
}
static int F_69 ( struct V_3 * V_3 )
{
int V_25 ;
if ( V_3 -> V_226 ) {
switch ( V_3 -> V_31 ) {
case V_48 :
case V_47 :
V_25 = F_4 ( V_3 , V_227 ) ;
return ( V_25 >> 12 ) & 0xF ;
break;
default:
break;
}
}
return 0 ;
}
static int F_70 ( struct V_3 * V_3 , unsigned int V_228 )
{
int V_25 = F_4 ( V_3 , V_227 ) ;
return ( V_25 >> ( V_228 * 4 ) ) & 0xF ;
}
static int F_71 ( struct V_211 * V_212 ,
struct V_213 * V_214 )
{
V_214 -> type = V_229 ;
V_214 -> V_216 = 1 ;
V_214 -> V_217 . V_223 . V_230 = 10 ;
if ( V_214 -> V_217 . V_223 . V_224 >= V_214 -> V_217 . V_223 . V_230 )
V_214 -> V_217 . V_223 . V_224 = V_214 -> V_217 . V_223 . V_230 - 1 ;
strcpy ( V_214 -> V_217 . V_223 . V_199 ,
V_231 [ V_214 -> V_217 . V_223 . V_224 ] ) ;
return 0 ;
}
static int F_72 ( struct V_211 * V_212 ,
struct V_221 *
V_222 )
{
struct V_3 * V_3 = F_65 ( V_212 ) ;
switch ( V_3 -> V_31 ) {
case V_48 :
switch ( V_212 -> V_232 ) {
case 0 :
V_222 -> V_217 . V_223 . V_224 [ 0 ] =
F_67 ( V_3 ) ;
break;
case 7 :
V_222 -> V_217 . V_223 . V_224 [ 0 ] =
F_68 ( V_3 ) ;
break;
case 8 :
V_222 -> V_217 . V_223 . V_224 [ 0 ] =
F_69 ( V_3 ) ;
break;
default:
V_222 -> V_217 . V_223 . V_224 [ 0 ] =
F_70 ( V_3 ,
V_212 -> V_232 - 1 ) ;
}
break;
case V_47 :
switch ( V_212 -> V_232 ) {
case 0 :
V_222 -> V_217 . V_223 . V_224 [ 0 ] =
F_67 ( V_3 ) ;
break;
case 4 :
V_222 -> V_217 . V_223 . V_224 [ 0 ] =
F_68 ( V_3 ) ;
break;
case 5 :
V_222 -> V_217 . V_223 . V_224 [ 0 ] =
F_69 ( V_3 ) ;
break;
default:
V_222 -> V_217 . V_223 . V_224 [ 0 ] =
F_70 ( V_3 ,
V_222 -> V_146 . V_233 - 1 ) ;
}
break;
case V_32 :
switch ( V_212 -> V_232 ) {
case 0 :
V_222 -> V_217 . V_223 . V_224 [ 0 ] =
F_67 ( V_3 ) ;
break;
case 9 :
V_222 -> V_217 . V_223 . V_224 [ 0 ] =
F_68 ( V_3 ) ;
break;
case 10 :
V_222 -> V_217 . V_223 . V_224 [ 0 ] =
F_69 ( V_3 ) ;
break;
default:
V_222 -> V_217 . V_223 . V_224 [ 0 ] =
F_70 ( V_3 ,
V_212 -> V_232 - 1 ) ;
break;
}
break;
case V_46 :
case V_42 :
{
int V_29 = F_15 ( V_3 ) ;
int V_16 , V_234 = 0 ;
for ( V_16 = 1 ; V_16 < 10 ; V_16 ++ )
if ( F_1 ( V_16 ) == V_29 ) {
V_234 = V_16 ;
break;
}
V_222 -> V_217 . V_223 . V_224 [ 0 ] = V_234 ;
}
break;
default:
break;
}
return 0 ;
}
static int F_62 ( struct V_3 * V_3 )
{
switch ( V_3 -> V_31 ) {
case V_47 :
case V_48 :
if ( V_3 -> V_235 & V_236 )
return 0 ;
break;
default:
if ( V_3 -> V_70 & V_95 )
return 0 ;
}
return 1 ;
}
static void F_73 ( struct V_3 * V_3 , int V_237 )
{
switch ( V_3 -> V_31 ) {
case V_47 :
case V_48 :
if ( 0 == V_237 )
V_3 -> V_235 |= V_236 ;
else
V_3 -> V_235 &= ~ V_236 ;
F_2 ( V_3 , V_238 , V_3 -> V_235 ) ;
break;
default:
if ( 0 == V_237 )
V_3 -> V_70 |= V_95 ;
else
V_3 -> V_70 &= ~ V_95 ;
F_2 ( V_3 , V_80 ,
V_3 -> V_70 ) ;
}
}
static int F_74 ( struct V_211 * V_212 ,
struct V_213 * V_214 )
{
static char * V_239 [] = { L_12 , L_13 } ;
V_214 -> type = V_229 ;
V_214 -> V_216 = 1 ;
V_214 -> V_217 . V_223 . V_230 = 2 ;
if ( V_214 -> V_217 . V_223 . V_224 >= V_214 -> V_217 . V_223 . V_230 )
V_214 -> V_217 . V_223 . V_224 =
V_214 -> V_217 . V_223 . V_230 - 1 ;
strcpy ( V_214 -> V_217 . V_223 . V_199 ,
V_239 [ V_214 -> V_217 . V_223 . V_224 ] ) ;
return 0 ;
}
static int F_75 ( struct V_211 * V_212 ,
struct V_221 * V_222 )
{
struct V_3 * V_3 = F_65 ( V_212 ) ;
V_222 -> V_217 . V_223 . V_224 [ 0 ] = F_62 ( V_3 ) ;
return 0 ;
}
static int F_76 ( struct V_211 * V_212 ,
struct V_221 * V_222 )
{
struct V_3 * V_3 = F_65 ( V_212 ) ;
int V_5 ;
if ( ! F_12 ( V_3 ) )
return - V_115 ;
V_5 = V_222 -> V_217 . V_223 . V_224 [ 0 ] ;
if ( V_5 < 0 )
V_5 = 0 ;
else if ( V_5 > 1 )
V_5 = 1 ;
F_73 ( V_3 , V_5 ) ;
return 0 ;
}
static int F_77 ( struct V_3 * V_3 )
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
static int F_78 ( struct V_3 * V_3 , int V_237 )
{
int V_29 ;
switch ( V_237 ) {
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
static int F_79 ( struct V_211 * V_212 ,
struct V_213 * V_214 )
{
V_214 -> type = V_229 ;
V_214 -> V_216 = 1 ;
V_214 -> V_217 . V_223 . V_230 = 9 ;
if ( V_214 -> V_217 . V_223 . V_224 >= V_214 -> V_217 . V_223 . V_230 )
V_214 -> V_217 . V_223 . V_224 =
V_214 -> V_217 . V_223 . V_230 - 1 ;
strcpy ( V_214 -> V_217 . V_223 . V_199 ,
V_231 [ V_214 -> V_217 . V_223 . V_224 + 1 ] ) ;
return 0 ;
}
static int F_80 ( struct V_211 * V_212 ,
struct V_221 * V_222 )
{
struct V_3 * V_3 = F_65 ( V_212 ) ;
V_222 -> V_217 . V_223 . V_224 [ 0 ] = F_77 ( V_3 ) ;
return 0 ;
}
static int F_81 ( struct V_211 * V_212 ,
struct V_221 * V_222 )
{
struct V_3 * V_3 = F_65 ( V_212 ) ;
int V_240 ;
int V_5 ;
if ( ! F_12 ( V_3 ) )
return - V_115 ;
V_5 = V_222 -> V_217 . V_223 . V_224 [ 0 ] ;
if ( V_5 < 0 )
V_5 = 0 ;
if ( V_5 > 9 )
V_5 = 9 ;
F_25 ( & V_3 -> V_22 ) ;
if ( V_5 != F_77 ( V_3 ) )
V_240 = ( F_78 ( V_3 , V_5 ) == 0 ) ? 1 : 0 ;
else
V_240 = 0 ;
F_27 ( & V_3 -> V_22 ) ;
return V_240 ;
}
static int F_82 ( struct V_3 * V_3 )
{
switch ( V_3 -> V_31 ) {
case V_32 :
switch ( V_3 -> V_70 & V_241 ) {
case 0 : return 0 ;
case V_242 : return 1 ;
case V_243 : return 2 ;
case V_243 + V_242 : return 3 ;
case V_244 : return 4 ;
case V_244 + V_242 : return 5 ;
case V_244 + V_243 : return 6 ;
case V_244 + V_243 + V_242 :
return 7 ;
case V_245 : return 8 ;
case V_245 + V_242 : return 9 ;
}
break;
case V_46 :
case V_42 :
if ( V_3 -> V_226 ) {
switch ( V_3 -> V_70 & V_241 ) {
case 0 : return 0 ;
case V_242 : return 1 ;
case V_243 : return 2 ;
case V_243 + V_242 :
return 3 ;
}
} else {
switch ( V_3 -> V_70 & V_241 ) {
case 0 : return 0 ;
case V_242 : return 1 ;
case V_243 + V_242 :
return 2 ;
}
}
break;
case V_48 :
if ( V_3 -> V_226 ) {
switch ( ( V_3 -> V_235 &
V_246 ) / V_247 ) {
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
switch ( ( V_3 -> V_235 &
V_246 ) / V_247 ) {
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
if ( V_3 -> V_226 ) {
switch ( ( V_3 -> V_235 &
V_246 ) / V_247 ) {
case 0 : return 0 ;
case 3 : return 1 ;
case 1 : return 2 ;
case 2 : return 3 ;
case 9 : return 4 ;
case 10 : return 5 ;
}
} else {
switch ( ( V_3 -> V_235 &
V_246 ) / V_247 ) {
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
static int F_83 ( struct V_3 * V_3 , int V_248 )
{
int V_249 = 0 ;
switch ( V_3 -> V_31 ) {
case V_32 :
V_3 -> V_70 &= ~ V_241 ;
switch ( V_248 ) {
case 0 :
break;
case 1 :
V_3 -> V_70 |= V_242 ;
break;
case 2 :
V_3 -> V_70 |= V_243 ;
break;
case 3 :
V_3 -> V_70 |=
V_243 + V_242 ;
break;
case 4 :
V_3 -> V_70 |= V_244 ;
break;
case 5 :
V_3 -> V_70 |=
V_244 + V_242 ;
break;
case 6 :
V_3 -> V_70 |=
V_244 + V_243 ;
break;
case 7 :
V_3 -> V_70 |=
V_244 + V_243 + V_242 ;
break;
case 8 :
V_3 -> V_70 |= V_245 ;
break;
case 9 :
V_3 -> V_70 |=
V_245 + V_242 ;
break;
default:
return - 1 ;
}
break;
case V_46 :
case V_42 :
V_3 -> V_70 &= ~ V_241 ;
if ( V_3 -> V_226 ) {
switch ( V_248 ) {
case 0 :
break;
case 1 :
V_3 -> V_70 |= V_242 ;
break;
case 2 :
V_3 -> V_70 |= V_243 ;
break;
case 3 :
V_3 -> V_70 |=
V_242 + V_243 ;
break;
default:
return - 1 ;
}
} else {
switch ( V_248 ) {
case 0 :
break;
case 1 :
V_3 -> V_70 |= V_242 ;
break;
case 2 :
V_3 -> V_70 |=
V_242 + V_243 ;
break;
default:
return - 1 ;
}
}
break;
case V_48 :
if ( V_3 -> V_226 ) {
switch ( V_248 ) {
case 0 : V_249 = 0 ; break;
case 1 : V_249 = 3 ; break;
case 2 : V_249 = 4 ; break;
case 3 : V_249 = 5 ; break;
case 4 : V_249 = 6 ; break;
case 5 : V_249 = 1 ; break;
case 6 : V_249 = 2 ; break;
case 7 : V_249 = 9 ; break;
case 8 : V_249 = 10 ; break;
default: return - 1 ;
}
} else {
switch ( V_248 ) {
case 0 : V_249 = 0 ; break;
case 1 : V_249 = 3 ; break;
case 2 : V_249 = 4 ; break;
case 3 : V_249 = 5 ; break;
case 4 : V_249 = 6 ; break;
case 5 : V_249 = 1 ; break;
case 6 : V_249 = 2 ; break;
case 7 : V_249 = 10 ; break;
default: return - 1 ;
}
}
break;
case V_47 :
if ( V_3 -> V_226 ) {
switch ( V_248 ) {
case 0 : V_249 = 0 ; break;
case 1 : V_249 = 3 ; break;
case 2 : V_249 = 1 ; break;
case 3 : V_249 = 2 ; break;
case 4 : V_249 = 9 ; break;
case 5 : V_249 = 10 ; break;
default: return - 1 ;
}
} else {
switch ( V_248 ) {
case 0 : V_249 = 0 ; break;
case 1 : V_249 = 3 ; break;
case 2 : V_249 = 1 ; break;
case 3 : V_249 = 2 ; break;
case 4 : V_249 = 10 ; break;
default: return - 1 ;
}
}
break;
}
switch ( V_3 -> V_31 ) {
case V_48 :
case V_47 :
V_3 -> V_235 &= ~ V_246 ;
V_3 -> V_235 |= V_247 * V_249 ;
F_2 ( V_3 , V_238 , V_3 -> V_235 ) ;
break;
case V_46 :
case V_42 :
case V_32 :
F_2 ( V_3 , V_80 ,
V_3 -> V_70 ) ;
}
return 0 ;
}
static int F_84 ( struct V_211 * V_212 ,
struct V_213 * V_214 )
{
struct V_3 * V_3 = F_65 ( V_212 ) ;
V_214 -> type = V_229 ;
V_214 -> V_216 = 1 ;
V_214 -> V_217 . V_223 . V_230 = V_3 -> V_250 ;
if ( V_214 -> V_217 . V_223 . V_224 >= V_214 -> V_217 . V_223 . V_230 )
V_214 -> V_217 . V_223 . V_224 =
V_214 -> V_217 . V_223 . V_230 - 1 ;
strcpy ( V_214 -> V_217 . V_223 . V_199 ,
V_3 -> V_251 [ V_214 -> V_217 . V_223 . V_224 ] ) ;
return 0 ;
}
static int F_85 ( struct V_211 * V_212 ,
struct V_221 * V_222 )
{
struct V_3 * V_3 = F_65 ( V_212 ) ;
int V_252 = F_82 ( V_3 ) ;
if ( V_252 >= 0 ) {
V_222 -> V_217 . V_223 . V_224 [ 0 ] = V_252 ;
return 0 ;
}
return - 1 ;
}
static int F_86 ( struct V_211 * V_212 ,
struct V_221 * V_222 )
{
struct V_3 * V_3 = F_65 ( V_212 ) ;
int V_5 , V_240 = 0 ;
if ( ! F_12 ( V_3 ) )
return - V_115 ;
V_5 = V_222 -> V_217 . V_223 . V_224 [ 0 ] ;
if ( V_5 < 0 )
V_5 = 0 ;
else if ( V_5 >= V_3 -> V_250 )
V_5 = V_3 -> V_250 - 1 ;
F_25 ( & V_3 -> V_22 ) ;
if ( V_5 != F_82 ( V_3 ) )
V_240 = ( 0 == F_83 ( V_3 , V_5 ) ) ? 1 : 0 ;
F_27 ( & V_3 -> V_22 ) ;
return V_240 ;
}
static int F_16 ( struct V_3 * V_3 )
{
if ( V_32 == V_3 -> V_31 ) {
unsigned int V_25 = F_4 ( V_3 , V_34 ) ;
unsigned int V_28 =
( V_25 >> V_253 ) & 0xF ;
if ( V_28 == 0 )
return V_36 ;
if ( V_28 <= 8 )
return V_28 ;
return V_254 ;
} else if ( V_46 == V_3 -> V_31 ) {
unsigned int V_26 = F_4 ( V_3 , V_33 ) ;
switch ( V_26 & V_58 ) {
case V_59 :
return V_255 ;
case V_256 :
return V_257 ;
case V_258 :
return V_259 ;
case V_260 :
return V_261 ;
case V_262 :
return V_98 ;
default:
return 0 ;
}
}
return 0 ;
}
static int F_87 ( struct V_211 * V_212 ,
struct V_213 * V_214 )
{
struct V_3 * V_3 = F_65 ( V_212 ) ;
if ( V_32 == V_3 -> V_31 ) {
static char * V_239 [] = { L_14 , L_15 , L_16 , L_17 ,
L_18 , L_19 , L_20 , L_21 , L_22 , L_23 } ;
V_214 -> type = V_229 ;
V_214 -> V_216 = 1 ;
V_214 -> V_217 . V_223 . V_230 = 10 ;
if ( V_214 -> V_217 . V_223 . V_224 >=
V_214 -> V_217 . V_223 . V_230 )
V_214 -> V_217 . V_223 . V_224 =
V_214 -> V_217 . V_223 . V_230 - 1 ;
strcpy ( V_214 -> V_217 . V_223 . V_199 ,
V_239 [ V_214 -> V_217 . V_223 . V_224 ] ) ;
} else if ( V_46 == V_3 -> V_31 ) {
static char * V_239 [] = { L_24 , L_25 , L_26 ,
L_27 , L_23 } ;
V_214 -> type = V_229 ;
V_214 -> V_216 = 1 ;
V_214 -> V_217 . V_223 . V_230 = 5 ;
if ( V_214 -> V_217 . V_223 . V_224 >=
V_214 -> V_217 . V_223 . V_230 )
V_214 -> V_217 . V_223 . V_224 =
V_214 -> V_217 . V_223 . V_230 - 1 ;
strcpy ( V_214 -> V_217 . V_223 . V_199 ,
V_239 [ V_214 -> V_217 . V_223 . V_224 ] ) ;
}
return 0 ;
}
static int F_88 ( struct V_211 * V_212 ,
struct V_221 * V_222 )
{
struct V_3 * V_3 = F_65 ( V_212 ) ;
V_222 -> V_217 . V_223 . V_224 [ 0 ] = F_16 ( V_3 ) ;
return 0 ;
}
static int F_89 ( struct V_3 * V_3 , V_15 V_263 )
{
return ( V_3 -> V_70 & V_263 ) ? 1 : 0 ;
}
static int F_90 ( struct V_3 * V_3 , V_15 V_263 , int V_264 )
{
if ( V_264 )
V_3 -> V_70 |= V_263 ;
else
V_3 -> V_70 &= ~ V_263 ;
F_2 ( V_3 , V_80 , V_3 -> V_70 ) ;
return 0 ;
}
static int F_91 ( struct V_211 * V_212 ,
struct V_221 * V_222 )
{
struct V_3 * V_3 = F_65 ( V_212 ) ;
V_15 V_263 = V_212 -> V_232 ;
F_25 ( & V_3 -> V_22 ) ;
V_222 -> V_217 . integer . V_217 [ 0 ] = F_89 ( V_3 , V_263 ) ;
F_27 ( & V_3 -> V_22 ) ;
return 0 ;
}
static int F_92 ( struct V_211 * V_212 ,
struct V_221 * V_222 )
{
struct V_3 * V_3 = F_65 ( V_212 ) ;
V_15 V_263 = V_212 -> V_232 ;
int V_240 ;
unsigned int V_5 ;
if ( ! F_12 ( V_3 ) )
return - V_115 ;
V_5 = V_222 -> V_217 . integer . V_217 [ 0 ] & 1 ;
F_25 ( & V_3 -> V_22 ) ;
V_240 = ( int ) V_5 != F_89 ( V_3 , V_263 ) ;
F_90 ( V_3 , V_263 , V_5 ) ;
F_27 ( & V_3 -> V_22 ) ;
return V_240 ;
}
static int F_93 ( struct V_3 * V_3 )
{
return ( V_3 -> V_70 & V_265 ) ? 1 : 0 ;
}
static int F_94 ( struct V_3 * V_3 , int V_264 )
{
if ( V_264 )
V_3 -> V_70 |= V_265 ;
else
V_3 -> V_70 &= ~ V_265 ;
F_2 ( V_3 , V_80 , V_3 -> V_70 ) ;
return 0 ;
}
static int F_95 ( struct V_211 * V_212 ,
struct V_213 * V_214 )
{
static char * V_239 [] = { L_28 , L_29 } ;
V_214 -> type = V_229 ;
V_214 -> V_216 = 1 ;
V_214 -> V_217 . V_223 . V_230 = 2 ;
if ( V_214 -> V_217 . V_223 . V_224 >= V_214 -> V_217 . V_223 . V_230 )
V_214 -> V_217 . V_223 . V_224 =
V_214 -> V_217 . V_223 . V_230 - 1 ;
strcpy ( V_214 -> V_217 . V_223 . V_199 ,
V_239 [ V_214 -> V_217 . V_223 . V_224 ] ) ;
return 0 ;
}
static int F_96 ( struct V_211 * V_212 ,
struct V_221 * V_222 )
{
struct V_3 * V_3 = F_65 ( V_212 ) ;
F_25 ( & V_3 -> V_22 ) ;
V_222 -> V_217 . V_223 . V_224 [ 0 ] = F_93 ( V_3 ) ;
F_27 ( & V_3 -> V_22 ) ;
return 0 ;
}
static int F_97 ( struct V_211 * V_212 ,
struct V_221 * V_222 )
{
struct V_3 * V_3 = F_65 ( V_212 ) ;
int V_240 ;
unsigned int V_5 ;
if ( ! F_12 ( V_3 ) )
return - V_115 ;
V_5 = V_222 -> V_217 . integer . V_217 [ 0 ] & 1 ;
F_25 ( & V_3 -> V_22 ) ;
V_240 = ( int ) V_5 != F_93 ( V_3 ) ;
F_94 ( V_3 , V_5 ) ;
F_27 ( & V_3 -> V_22 ) ;
return V_240 ;
}
static int F_98 ( struct V_3 * V_3 )
{
return ( V_3 -> V_70 & V_266 ) ? 1 : 0 ;
}
static int F_99 ( struct V_3 * V_3 , int V_267 )
{
if ( V_267 )
V_3 -> V_70 |= V_266 ;
else
V_3 -> V_70 &= ~ V_266 ;
F_2 ( V_3 , V_80 , V_3 -> V_70 ) ;
return 0 ;
}
static int F_100 ( struct V_211 * V_212 ,
struct V_213 * V_214 )
{
static char * V_239 [] = { L_30 , L_31 } ;
V_214 -> type = V_229 ;
V_214 -> V_216 = 1 ;
V_214 -> V_217 . V_223 . V_230 = 2 ;
if ( V_214 -> V_217 . V_223 . V_224 >= V_214 -> V_217 . V_223 . V_230 )
V_214 -> V_217 . V_223 . V_224 =
V_214 -> V_217 . V_223 . V_230 - 1 ;
strcpy ( V_214 -> V_217 . V_223 . V_199 ,
V_239 [ V_214 -> V_217 . V_223 . V_224 ] ) ;
return 0 ;
}
static int F_101 ( struct V_211 * V_212 ,
struct V_221 * V_222 )
{
struct V_3 * V_3 = F_65 ( V_212 ) ;
F_25 ( & V_3 -> V_22 ) ;
V_222 -> V_217 . V_223 . V_224 [ 0 ] = F_98 ( V_3 ) ;
F_27 ( & V_3 -> V_22 ) ;
return 0 ;
}
static int F_102 ( struct V_211 * V_212 ,
struct V_221 * V_222 )
{
struct V_3 * V_3 = F_65 ( V_212 ) ;
int V_240 ;
unsigned int V_5 ;
if ( ! F_12 ( V_3 ) )
return - V_115 ;
V_5 = V_222 -> V_217 . integer . V_217 [ 0 ] & 1 ;
F_25 ( & V_3 -> V_22 ) ;
V_240 = ( int ) V_5 != F_98 ( V_3 ) ;
F_99 ( V_3 , V_5 ) ;
F_27 ( & V_3 -> V_22 ) ;
return V_240 ;
}
static int F_103 ( struct V_3 * V_3 )
{
if ( V_3 -> V_70 & V_268 )
return 1 ;
if ( V_3 -> V_70 & V_269 )
return 2 ;
return 0 ;
}
static int F_104 ( struct V_3 * V_3 , int V_237 )
{
V_3 -> V_70 &= ~ ( V_268 | V_269 ) ;
switch ( V_237 ) {
case 0 :
break;
case 1 :
V_3 -> V_70 |= V_268 ;
break;
case 2 :
V_3 -> V_70 |= V_269 ;
break;
}
F_2 ( V_3 , V_80 , V_3 -> V_70 ) ;
return 0 ;
}
static int F_105 ( struct V_211 * V_212 ,
struct V_213 * V_214 )
{
static char * V_239 [] = { L_30 , L_31 , L_32 } ;
V_214 -> type = V_229 ;
V_214 -> V_216 = 1 ;
V_214 -> V_217 . V_223 . V_230 = 3 ;
if ( V_214 -> V_217 . V_223 . V_224 >= V_214 -> V_217 . V_223 . V_230 )
V_214 -> V_217 . V_223 . V_224 =
V_214 -> V_217 . V_223 . V_230 - 1 ;
strcpy ( V_214 -> V_217 . V_223 . V_199 ,
V_239 [ V_214 -> V_217 . V_223 . V_224 ] ) ;
return 0 ;
}
static int F_106 ( struct V_211 * V_212 ,
struct V_221 * V_222 )
{
struct V_3 * V_3 = F_65 ( V_212 ) ;
F_25 ( & V_3 -> V_22 ) ;
V_222 -> V_217 . V_223 . V_224 [ 0 ] = F_103 ( V_3 ) ;
F_27 ( & V_3 -> V_22 ) ;
return 0 ;
}
static int F_107 ( struct V_211 * V_212 ,
struct V_221 * V_222 )
{
struct V_3 * V_3 = F_65 ( V_212 ) ;
int V_240 ;
int V_5 ;
if ( ! F_12 ( V_3 ) )
return - V_115 ;
V_5 = V_222 -> V_217 . integer . V_217 [ 0 ] ;
if ( V_5 < 0 )
V_5 = 0 ;
if ( V_5 > 2 )
V_5 = 2 ;
F_25 ( & V_3 -> V_22 ) ;
V_240 = V_5 != F_103 ( V_3 ) ;
F_104 ( V_3 , V_5 ) ;
F_27 ( & V_3 -> V_22 ) ;
return V_240 ;
}
static int F_108 ( struct V_3 * V_3 )
{
if ( V_3 -> V_70 & V_71 )
return 2 ;
if ( V_3 -> V_70 & V_72 )
return 1 ;
return 0 ;
}
static int F_109 ( struct V_3 * V_3 , int V_237 )
{
V_3 -> V_70 &= ~ ( V_72 | V_71 ) ;
switch ( V_237 ) {
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
static int F_110 ( struct V_211 * V_212 ,
struct V_213 * V_214 )
{
static char * V_239 [] = { L_30 , L_31 , L_32 } ;
V_214 -> type = V_229 ;
V_214 -> V_216 = 1 ;
V_214 -> V_217 . V_223 . V_230 = 3 ;
if ( V_214 -> V_217 . V_223 . V_224 >= V_214 -> V_217 . V_223 . V_230 )
V_214 -> V_217 . V_223 . V_224 =
V_214 -> V_217 . V_223 . V_230 - 1 ;
strcpy ( V_214 -> V_217 . V_223 . V_199 ,
V_239 [ V_214 -> V_217 . V_223 . V_224 ] ) ;
return 0 ;
}
static int F_111 ( struct V_211 * V_212 ,
struct V_221 * V_222 )
{
struct V_3 * V_3 = F_65 ( V_212 ) ;
F_25 ( & V_3 -> V_22 ) ;
V_222 -> V_217 . V_223 . V_224 [ 0 ] = F_108 ( V_3 ) ;
F_27 ( & V_3 -> V_22 ) ;
return 0 ;
}
static int F_112 ( struct V_211 * V_212 ,
struct V_221 * V_222 )
{
struct V_3 * V_3 = F_65 ( V_212 ) ;
int V_240 ;
int V_5 ;
if ( ! F_12 ( V_3 ) )
return - V_115 ;
V_5 = V_222 -> V_217 . integer . V_217 [ 0 ] ;
if ( V_5 < 0 )
V_5 = 0 ;
if ( V_5 > 2 )
V_5 = 2 ;
F_25 ( & V_3 -> V_22 ) ;
V_240 = V_5 != F_108 ( V_3 ) ;
F_109 ( V_3 , V_5 ) ;
F_27 ( & V_3 -> V_22 ) ;
return V_240 ;
}
static int F_113 ( struct V_211 * V_212 ,
struct V_213 * V_214 )
{
V_214 -> type = V_215 ;
V_214 -> V_216 = 3 ;
V_214 -> V_217 . integer . V_218 = 0 ;
V_214 -> V_217 . integer . V_219 = 65535 ;
V_214 -> V_217 . integer . V_220 = 1 ;
return 0 ;
}
static int F_114 ( struct V_211 * V_212 ,
struct V_221 * V_222 )
{
struct V_3 * V_3 = F_65 ( V_212 ) ;
int V_270 ;
int V_271 ;
V_270 = V_222 -> V_217 . integer . V_217 [ 0 ] ;
if ( V_270 < 0 )
V_270 = 0 ;
else if ( V_270 >= 2 * V_83 )
V_270 = 2 * V_83 - 1 ;
V_271 = V_222 -> V_217 . integer . V_217 [ 1 ] ;
if ( V_271 < 0 )
V_271 = 0 ;
else if ( V_271 >= V_83 )
V_271 = V_83 - 1 ;
F_25 ( & V_3 -> V_22 ) ;
if ( V_270 >= V_83 )
V_222 -> V_217 . integer . V_217 [ 2 ] =
F_7 ( V_3 , V_271 ,
V_270 - V_83 ) ;
else
V_222 -> V_217 . integer . V_217 [ 2 ] =
F_6 ( V_3 , V_271 , V_270 ) ;
F_27 ( & V_3 -> V_22 ) ;
return 0 ;
}
static int F_115 ( struct V_211 * V_212 ,
struct V_221 * V_222 )
{
struct V_3 * V_3 = F_65 ( V_212 ) ;
int V_240 ;
int V_270 ;
int V_271 ;
int V_144 ;
if ( ! F_12 ( V_3 ) )
return - V_115 ;
V_270 = V_222 -> V_217 . integer . V_217 [ 0 ] ;
V_271 = V_222 -> V_217 . integer . V_217 [ 1 ] ;
if ( V_270 < 0 || V_270 >= 2 * V_83 )
return - 1 ;
if ( V_271 < 0 || V_271 >= V_83 )
return - 1 ;
V_144 = V_222 -> V_217 . integer . V_217 [ 2 ] ;
F_25 ( & V_3 -> V_22 ) ;
if ( V_270 >= V_83 )
V_240 = V_144 != F_7 ( V_3 , V_271 ,
V_270 -
V_83 ) ;
else
V_240 = V_144 != F_6 ( V_3 , V_271 ,
V_270 ) ;
if ( V_240 ) {
if ( V_270 >= V_83 )
F_9 ( V_3 , V_271 ,
V_270 - V_83 ,
V_144 ) ;
else
F_8 ( V_3 , V_271 , V_270 ,
V_144 ) ;
}
F_27 ( & V_3 -> V_22 ) ;
return V_240 ;
}
static int F_116 ( struct V_211 * V_212 ,
struct V_213 * V_214 )
{
V_214 -> type = V_215 ;
V_214 -> V_216 = 1 ;
V_214 -> V_217 . integer . V_218 = 0 ;
V_214 -> V_217 . integer . V_219 = 64 ;
V_214 -> V_217 . integer . V_220 = 1 ;
return 0 ;
}
static int F_117 ( struct V_211 * V_212 ,
struct V_221 * V_222 )
{
struct V_3 * V_3 = F_65 ( V_212 ) ;
int V_272 ;
V_272 = V_222 -> V_146 . V_233 - 1 ;
if ( F_32 ( V_272 < 0 || V_272 >= V_83 ) )
return - V_112 ;
F_25 ( & V_3 -> V_22 ) ;
V_222 -> V_217 . integer . V_217 [ 0 ] =
( F_7 ( V_3 , V_272 , V_272 ) * 64 ) / V_145 ;
F_27 ( & V_3 -> V_22 ) ;
return 0 ;
}
static int F_118 ( struct V_211 * V_212 ,
struct V_221 * V_222 )
{
struct V_3 * V_3 = F_65 ( V_212 ) ;
int V_240 ;
int V_272 ;
int V_144 ;
if ( ! F_12 ( V_3 ) )
return - V_115 ;
V_272 = V_222 -> V_146 . V_233 - 1 ;
if ( F_32 ( V_272 < 0 || V_272 >= V_83 ) )
return - V_112 ;
V_144 = V_222 -> V_217 . integer . V_217 [ 0 ] * V_145 / 64 ;
F_25 ( & V_3 -> V_22 ) ;
V_240 =
V_144 != F_7 ( V_3 , V_272 ,
V_272 ) ;
if ( V_240 )
F_9 ( V_3 , V_272 , V_272 ,
V_144 ) ;
F_27 ( & V_3 -> V_22 ) ;
return V_240 ;
}
static int F_119 ( struct V_211 * V_212 ,
struct V_213 * V_214 )
{
static char * V_239 [] = { L_33 , L_34 , L_35 , L_36 } ;
V_214 -> type = V_229 ;
V_214 -> V_216 = 1 ;
V_214 -> V_217 . V_223 . V_230 = 4 ;
if ( V_214 -> V_217 . V_223 . V_224 >= V_214 -> V_217 . V_223 . V_230 )
V_214 -> V_217 . V_223 . V_224 =
V_214 -> V_217 . V_223 . V_230 - 1 ;
strcpy ( V_214 -> V_217 . V_223 . V_199 ,
V_239 [ V_214 -> V_217 . V_223 . V_224 ] ) ;
return 0 ;
}
static int F_120 ( struct V_3 * V_3 )
{
int V_25 , V_26 ;
switch ( V_3 -> V_31 ) {
case V_32 :
V_25 = F_4 ( V_3 , V_34 ) ;
if ( V_25 & V_37 ) {
if ( V_25 & V_273 )
return 2 ;
else
return 1 ;
}
return 0 ;
break;
case V_46 :
V_26 = F_4 ( V_3 , V_33 ) ;
if ( V_26 & V_49 ) {
if ( V_26 & V_274 )
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
static int F_121 ( struct V_3 * V_3 )
{
int V_25 = F_4 ( V_3 , V_34 ) ;
if ( V_25 & V_43 ) {
if ( V_25 & V_275 )
return 2 ;
else
return 1 ;
}
return 0 ;
}
static int F_122 ( struct V_3 * V_3 , int V_228 )
{
int V_25 , V_22 , V_276 ;
V_25 = F_4 ( V_3 , V_225 ) ;
V_22 = ( V_25 & ( 0x1 << V_228 ) ) ? 1 : 0 ;
V_276 = ( V_25 & ( 0x100 << V_228 ) ) ? 1 : 0 ;
if ( V_22 && V_276 )
return 2 ;
else if ( V_22 )
return 1 ;
return 0 ;
}
static int F_123 ( struct V_3 * V_3 )
{
int V_25 , V_22 = 0 , V_276 = 0 ;
switch ( V_3 -> V_31 ) {
case V_48 :
case V_47 :
V_25 = F_4 ( V_3 , V_277 ) ;
V_22 = ( V_25 & 0x400 ) ? 1 : 0 ;
V_276 = ( V_25 & 0x800 ) ? 1 : 0 ;
break;
case V_46 :
V_25 = F_4 ( V_3 , V_34 ) ;
V_22 = ( V_25 & V_278 ) ? 1 : 0 ;
V_276 = ( V_25 & V_279 ) ? 1 : 0 ;
break;
case V_32 :
V_25 = F_4 ( V_3 , V_33 ) ;
V_22 = ( V_25 & 0x100000 ) ? 1 : 0 ;
V_276 = ( V_25 & 0x200000 ) ? 1 : 0 ;
break;
case V_42 :
break;
}
if ( V_22 && V_276 )
return 2 ;
else if ( V_22 )
return 1 ;
return 0 ;
}
static int F_124 ( struct V_3 * V_3 , int V_228 )
{
int V_26 , V_22 , V_276 ;
V_26 = F_4 ( V_3 , V_33 ) ;
V_22 = ( V_26 & ( 0x0080 >> V_228 ) ) ? 1 : 0 ;
V_276 = ( V_26 & ( 0x8000 >> V_228 ) ) ? 1 : 0 ;
if ( V_276 )
return 2 ;
else if ( V_22 )
return 1 ;
return 0 ;
}
static int F_125 ( struct V_3 * V_3 )
{
int V_25 ;
if ( V_3 -> V_226 ) {
switch ( V_3 -> V_31 ) {
case V_46 :
case V_32 :
V_25 = F_4 ( V_3 , V_34 ) ;
if ( V_25 & V_280 ) {
if ( V_25 & V_281 )
return 2 ;
else
return 1 ;
}
return 0 ;
break;
case V_48 :
case V_47 :
V_25 = F_4 ( V_3 , V_225 ) ;
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
static int F_126 ( struct V_211 * V_212 ,
struct V_221 * V_222 )
{
struct V_3 * V_3 = F_65 ( V_212 ) ;
int V_5 = - 1 ;
switch ( V_3 -> V_31 ) {
case V_48 :
switch ( V_212 -> V_232 ) {
case 0 :
V_5 = F_120 ( V_3 ) ; break;
case 7 :
V_5 = F_125 ( V_3 ) ; break;
case 8 :
V_5 = F_123 ( V_3 ) ; break;
default:
V_5 = F_122 ( V_3 ,
V_212 -> V_232 - 1 ) ;
}
break;
case V_47 :
switch ( V_212 -> V_232 ) {
case 0 :
V_5 = F_120 ( V_3 ) ; break;
case 4 :
V_5 = F_125 ( V_3 ) ; break;
case 5 :
V_5 = F_123 ( V_3 ) ; break;
default:
V_5 = F_122 ( V_3 , V_222 -> V_146 . V_233 - 1 ) ;
}
break;
case V_46 :
switch ( V_212 -> V_232 ) {
case 0 :
V_5 = F_120 ( V_3 ) ; break;
case 1 :
V_5 = F_121 ( V_3 ) ; break;
case 2 :
V_5 = F_125 ( V_3 ) ; break;
case 3 :
V_5 = F_123 ( V_3 ) ; break;
}
break;
case V_42 :
V_5 = F_121 ( V_3 ) ;
break;
case V_32 :
switch ( V_212 -> V_232 ) {
case 0 :
V_5 = F_120 ( V_3 ) ; break;
case 9 :
V_5 = F_125 ( V_3 ) ; break;
case 10 :
V_5 = F_123 ( V_3 ) ; break;
default:
V_5 = F_124 ( V_3 ,
V_212 -> V_232 - 1 ) ;
}
break;
}
if ( - 1 == V_5 )
V_5 = 3 ;
V_222 -> V_217 . V_223 . V_224 [ 0 ] = V_5 ;
return 0 ;
}
static void F_127 ( struct V_3 * V_3 )
{
unsigned int V_282 [ 4 ] = { 0 , 0 , 0 , 0 } ;
switch ( V_3 -> V_226 -> V_158 ) {
case 0 :
V_282 [ 2 ] |= V_283 ;
break;
case 1 :
V_282 [ 2 ] |= V_284 ;
break;
default:
break;
}
switch ( V_3 -> V_226 -> V_285 ) {
case 1 :
V_282 [ 1 ] |= V_286 ;
break;
case 2 :
V_282 [ 1 ] |= V_287 ;
break;
case 3 :
V_282 [ 1 ] |= V_287 +
V_288 ;
break;
case 4 :
V_282 [ 1 ] |= V_286 +
V_287 ;
break;
case 5 :
V_282 [ 1 ] |= V_286 +
V_287 +
V_288 ;
break;
default:
break;
}
switch ( V_3 -> V_226 -> V_289 ) {
case 1 :
V_282 [ 2 ] |= V_290 ;
break;
case 2 :
V_282 [ 2 ] |= V_291 ;
break;
default:
break;
}
switch ( V_3 -> V_226 -> V_292 ) {
case 1 :
V_282 [ 2 ] |= V_293 ;
break;
case 2 :
V_282 [ 2 ] |= V_294 ;
break;
default:
break;
}
switch ( V_3 -> V_226 -> V_295 ) {
case 1 :
V_282 [ 2 ] |= V_296 ;
break;
case 2 :
V_282 [ 2 ] |= V_297 ;
break;
case 3 :
V_282 [ 2 ] |= V_296 + V_298 ;
break;
case 4 :
V_282 [ 2 ] |= V_297 + V_298 ;
break;
default:
break;
}
if ( 1 == V_3 -> V_226 -> V_299 ) {
V_282 [ 2 ] |= V_300 ;
}
F_2 ( V_3 , V_301 , V_282 [ 0 ] ) ;
F_2 ( V_3 , V_301 + 4 , V_282 [ 1 ] ) ;
F_2 ( V_3 , V_301 + 8 , V_282 [ 2 ] ) ;
F_2 ( V_3 , V_301 + 12 , V_282 [ 3 ] ) ;
}
static int F_128 ( struct V_211 * V_212 ,
struct V_213 * V_214 )
{
static char * V_239 [] = { L_37 , L_38 } ;
V_214 -> type = V_229 ;
V_214 -> V_216 = 1 ;
V_214 -> V_217 . V_223 . V_230 = 2 ;
if ( V_214 -> V_217 . V_223 . V_224 >= V_214 -> V_217 . V_223 . V_230 )
V_214 -> V_217 . V_223 . V_224 =
V_214 -> V_217 . V_223 . V_230 - 1 ;
strcpy ( V_214 -> V_217 . V_223 . V_199 ,
V_239 [ V_214 -> V_217 . V_223 . V_224 ] ) ;
return 0 ;
}
static int F_129 ( struct V_211 * V_212 ,
struct V_221 * V_222 )
{
struct V_3 * V_3 = F_65 ( V_212 ) ;
V_222 -> V_217 . V_223 . V_224 [ 0 ] = V_3 -> V_226 -> V_292 ;
return 0 ;
}
static int F_130 ( struct V_211 * V_212 ,
struct V_221 * V_222 )
{
struct V_3 * V_3 = F_65 ( V_212 ) ;
if ( V_3 -> V_226 -> V_292 != V_222 -> V_217 . V_223 . V_224 [ 0 ] ) {
V_3 -> V_226 -> V_292 = V_222 -> V_217 . V_223 . V_224 [ 0 ] ;
F_127 ( V_3 ) ;
return 1 ;
}
return 0 ;
}
static int F_131 ( struct V_211 * V_212 ,
struct V_213 * V_214 )
{
static char * V_239 [] = { L_39 , L_40 , L_41 , L_42 , L_43 } ;
V_214 -> type = V_229 ;
V_214 -> V_216 = 1 ;
V_214 -> V_217 . V_223 . V_230 = 5 ;
if ( V_214 -> V_217 . V_223 . V_224 >= V_214 -> V_217 . V_223 . V_230 )
V_214 -> V_217 . V_223 . V_224 =
V_214 -> V_217 . V_223 . V_230 - 1 ;
strcpy ( V_214 -> V_217 . V_223 . V_199 ,
V_239 [ V_214 -> V_217 . V_223 . V_224 ] ) ;
return 0 ;
}
static int F_132 ( struct V_211 * V_212 ,
struct V_221 * V_222 )
{
struct V_3 * V_3 = F_65 ( V_212 ) ;
V_222 -> V_217 . V_223 . V_224 [ 0 ] = V_3 -> V_226 -> V_295 ;
return 0 ;
}
static int F_133 ( struct V_211 * V_212 ,
struct V_221 * V_222 )
{
struct V_3 * V_3 = F_65 ( V_212 ) ;
if ( V_3 -> V_226 -> V_295 != V_222 -> V_217 . V_223 . V_224 [ 0 ] ) {
V_3 -> V_226 -> V_295 = V_222 -> V_217 . V_223 . V_224 [ 0 ] ;
F_127 ( V_3 ) ;
return 1 ;
}
return 0 ;
}
static int F_134 ( struct V_211 * V_212 ,
struct V_213 * V_214 )
{
static char * V_239 [] = { L_44 , L_45 , L_46 } ;
V_214 -> type = V_229 ;
V_214 -> V_216 = 1 ;
V_214 -> V_217 . V_223 . V_230 = 3 ;
if ( V_214 -> V_217 . V_223 . V_224 >= V_214 -> V_217 . V_223 . V_230 )
V_214 -> V_217 . V_223 . V_224 =
V_214 -> V_217 . V_223 . V_230 - 1 ;
strcpy ( V_214 -> V_217 . V_223 . V_199 ,
V_239 [ V_214 -> V_217 . V_223 . V_224 ] ) ;
return 0 ;
}
static int F_135 ( struct V_211 * V_212 ,
struct V_221 * V_222 )
{
struct V_3 * V_3 = F_65 ( V_212 ) ;
V_222 -> V_217 . V_223 . V_224 [ 0 ] = V_3 -> V_226 -> V_289 ;
return 0 ;
}
static int F_136 ( struct V_211 * V_212 ,
struct V_221 * V_222 )
{
struct V_3 * V_3 = F_65 ( V_212 ) ;
if ( V_3 -> V_226 -> V_289 != V_222 -> V_217 . V_223 . V_224 [ 0 ] ) {
V_3 -> V_226 -> V_289 = V_222 -> V_217 . V_223 . V_224 [ 0 ] ;
F_127 ( V_3 ) ;
return 1 ;
}
return 0 ;
}
static int F_137 ( struct V_211 * V_212 ,
struct V_213 * V_214 )
{
static char * V_239 [] = { L_47 , L_48 , L_49 ,
L_50 , L_51 , L_52 } ;
V_214 -> type = V_229 ;
V_214 -> V_216 = 1 ;
V_214 -> V_217 . V_223 . V_230 = 6 ;
if ( V_214 -> V_217 . V_223 . V_224 >= V_214 -> V_217 . V_223 . V_230 )
V_214 -> V_217 . V_223 . V_224 =
V_214 -> V_217 . V_223 . V_230 - 1 ;
strcpy ( V_214 -> V_217 . V_223 . V_199 ,
V_239 [ V_214 -> V_217 . V_223 . V_224 ] ) ;
return 0 ;
}
static int F_138 ( struct V_211 * V_212 ,
struct V_221 * V_222 )
{
struct V_3 * V_3 = F_65 ( V_212 ) ;
V_222 -> V_217 . V_223 . V_224 [ 0 ] = V_3 -> V_226 -> V_285 ;
return 0 ;
}
static int F_139 ( struct V_211 * V_212 ,
struct V_221 * V_222 )
{
struct V_3 * V_3 = F_65 ( V_212 ) ;
if ( V_3 -> V_226 -> V_285 != V_222 -> V_217 . V_223 . V_224 [ 0 ] ) {
V_3 -> V_226 -> V_285 = V_222 -> V_217 . V_223 . V_224 [ 0 ] ;
F_127 ( V_3 ) ;
return 1 ;
}
return 0 ;
}
static int F_140 ( struct V_211 * V_212 ,
struct V_213 * V_214 )
{
static char * V_239 [] = { L_53 , L_54 , L_55 } ;
V_214 -> type = V_229 ;
V_214 -> V_216 = 1 ;
V_214 -> V_217 . V_223 . V_230 = 3 ;
if ( V_214 -> V_217 . V_223 . V_224 >= V_214 -> V_217 . V_223 . V_230 )
V_214 -> V_217 . V_223 . V_224 =
V_214 -> V_217 . V_223 . V_230 - 1 ;
strcpy ( V_214 -> V_217 . V_223 . V_199 ,
V_239 [ V_214 -> V_217 . V_223 . V_224 ] ) ;
return 0 ;
}
static int F_141 ( struct V_211 * V_212 ,
struct V_221 * V_222 )
{
struct V_3 * V_3 = F_65 ( V_212 ) ;
V_222 -> V_217 . V_223 . V_224 [ 0 ] = V_3 -> V_226 -> V_158 ;
return 0 ;
}
static int F_142 ( struct V_211 * V_212 ,
struct V_221 * V_222 )
{
struct V_3 * V_3 = F_65 ( V_212 ) ;
if ( V_3 -> V_226 -> V_158 != V_222 -> V_217 . V_223 . V_224 [ 0 ] ) {
V_3 -> V_226 -> V_158 = V_222 -> V_217 . V_223 . V_224 [ 0 ] ;
F_127 ( V_3 ) ;
return 1 ;
}
return 0 ;
}
static int F_143 ( struct V_211 * V_212 ,
struct V_213 * V_214 )
{
V_214 -> type = V_302 ;
V_214 -> V_216 = 1 ;
V_214 -> V_217 . integer . V_218 = 0 ;
V_214 -> V_217 . integer . V_219 = 1 ;
return 0 ;
}
static int F_144 ( struct V_211 * V_212 ,
struct V_221 * V_222 )
{
struct V_3 * V_3 = F_65 ( V_212 ) ;
V_222 -> V_217 . V_223 . V_224 [ 0 ] = V_3 -> V_226 -> V_299 ;
return 0 ;
}
static int F_145 ( struct V_211 * V_212 ,
struct V_221 * V_222 )
{
struct V_3 * V_3 = F_65 ( V_212 ) ;
if ( V_3 -> V_226 -> V_299 != V_222 -> V_217 . V_223 . V_224 [ 0 ] ) {
V_3 -> V_226 -> V_299 = V_222 -> V_217 . V_223 . V_224 [ 0 ] ;
F_127 ( V_3 ) ;
return 1 ;
}
return 0 ;
}
static int F_146 ( struct V_3 * V_3 )
{
int V_16 ;
for ( V_16 = V_3 -> V_133 ; V_16 < V_3 -> V_125 ; ++ V_16 ) {
if ( V_3 -> V_99 > 48000 ) {
V_3 -> V_303 [ V_16 ] -> V_304 [ 0 ] . V_305 =
V_306 |
V_307 |
V_308 ;
} else {
V_3 -> V_303 [ V_16 ] -> V_304 [ 0 ] . V_305 =
V_309 |
V_308 ;
}
F_147 ( V_3 -> V_172 , V_310 |
V_311 ,
& V_3 -> V_303 [ V_16 ] -> V_146 ) ;
}
return 0 ;
}
static int F_148 ( struct V_171 * V_172 ,
struct V_3 * V_3 )
{
unsigned int V_228 , V_312 ;
int V_173 ;
struct V_211 * V_313 ;
struct V_314 * V_315 = NULL ;
switch ( V_3 -> V_31 ) {
case V_46 :
V_315 = V_316 ;
V_312 = F_149 ( V_316 ) ;
break;
case V_42 :
V_315 = V_317 ;
V_312 = F_149 ( V_317 ) ;
break;
case V_47 :
V_315 = V_318 ;
V_312 = F_149 ( V_318 ) ;
break;
case V_48 :
V_315 = V_319 ;
V_312 = F_149 ( V_319 ) ;
break;
case V_32 :
V_315 = V_320 ;
V_312 = F_149 ( V_320 ) ;
break;
}
if ( NULL != V_315 ) {
for ( V_228 = 0 ; V_228 < V_312 ; V_228 ++ ) {
V_173 = F_150 ( V_172 ,
F_151 ( & V_315 [ V_228 ] , V_3 ) ) ;
if ( V_173 < 0 )
return V_173 ;
}
}
V_321 . V_199 = L_56 ;
if ( V_3 -> V_99 >= 128000 ) {
V_312 = V_3 -> V_139 ;
} else if ( V_3 -> V_99 >= 64000 ) {
V_312 = V_3 -> V_133 ;
} else {
V_312 = V_3 -> V_125 ;
}
for ( V_228 = 0 ; V_228 < V_312 ; ++ V_228 ) {
V_321 . V_233 = V_228 + 1 ;
V_313 = F_151 ( & V_321 , V_3 ) ;
V_173 = F_150 ( V_172 , V_313 ) ;
if ( V_173 < 0 )
return V_173 ;
V_3 -> V_303 [ V_228 ] = V_313 ;
}
if ( V_3 -> V_226 ) {
V_315 = V_322 ;
V_312 = F_149 ( V_322 ) ;
for ( V_228 = 0 ; V_228 < V_312 ; V_228 ++ ) {
V_173 = F_150 ( V_172 ,
F_151 ( & V_315 [ V_228 ] , V_3 ) ) ;
if ( V_173 < 0 )
return V_173 ;
}
}
return 0 ;
}
static void
F_152 ( struct V_323 * V_324 ,
struct V_325 * V_326 )
{
struct V_3 * V_3 = V_324 -> V_165 ;
unsigned int V_25 , V_26 , V_327 , V_328 ;
char * V_329 ;
char * V_330 ;
char * V_331 ;
char * V_332 ;
int V_333 , V_334 ;
int V_335 , V_336 , V_85 , V_337 , V_338 , V_339 ;
unsigned int V_87 ;
T_2 V_88 = 0 ;
V_15 V_29 ;
V_25 = F_4 ( V_3 , V_34 ) ;
V_26 = F_4 ( V_3 , V_33 ) ;
V_327 = V_3 -> V_70 ;
V_328 = F_4 ( V_3 , V_35 ) ;
F_153 ( V_326 , L_57 ,
V_3 -> V_340 , V_3 -> V_172 -> V_341 + 1 ,
V_3 -> V_342 ,
( V_26 & V_343 ) |
( V_26 & V_344 ) | ( V_26 &
V_345 ) ) ;
F_153 ( V_326 , L_58 ,
( F_4 ( V_3 , V_188 ) >> 8 ) & 0xFFFFFF ,
V_3 -> V_346 ) ;
F_153 ( V_326 , L_59 ,
V_3 -> V_179 , V_3 -> V_347 , ( unsigned long ) V_3 -> V_6 ) ;
F_153 ( V_326 , L_60 ) ;
F_153 ( V_326 ,
L_61 ,
V_25 & V_348 ,
( V_25 & V_186 ) ? 1 : 0 ,
( V_25 & V_192 ) ? 1 : 0 ,
V_3 -> V_349 ) ;
F_153 ( V_326 ,
L_62
L_63 ,
( ( V_25 & V_76 ) ? 1 : 0 ) ,
( V_25 & V_75 ) ,
( V_25 & V_75 ) %
( 2 * ( int ) V_3 -> V_73 ) ,
( ( V_25 & V_75 ) - 64 ) %
( 2 * ( int ) V_3 -> V_73 ) ,
( long ) F_20 ( V_3 ) * 4 ) ;
F_153 ( V_326 ,
L_64 ,
F_4 ( V_3 , V_184 ) & 0xFF ,
F_4 ( V_3 , V_190 ) & 0xFF ,
F_4 ( V_3 , V_182 ) & 0xFF ,
F_4 ( V_3 , V_188 ) & 0xFF ) ;
F_153 ( V_326 ,
L_65 ,
F_4 ( V_3 , V_175 ) & 0xFF ,
F_4 ( V_3 , V_177 ) & 0xFF ) ;
F_153 ( V_326 ,
L_66
L_67 ,
V_3 -> V_70 , V_3 -> V_350 ,
V_25 , V_26 ) ;
if ( V_25 & V_351 ) {
F_153 ( V_326 , L_68 ) ;
V_335 = F_4 ( V_3 , V_352 + 4 ) ;
if ( V_335 & V_353 ) {
F_153 ( V_326 , L_69 ) ;
switch ( V_335 & ( V_286 |
V_287 ) ) {
case 0 :
F_153 ( V_326 , L_70 ) ;
break;
case V_286 :
F_153 ( V_326 , L_71 ) ;
break;
case V_287 :
F_153 ( V_326 , L_72 ) ;
break;
default:
F_153 ( V_326 , L_73 ) ;
break;
}
if ( V_335 & V_288 ) {
F_153 ( V_326 , L_74 ) ;
} else {
F_153 ( V_326 , L_75 ) ;
}
} else {
F_153 ( V_326 , L_76 ) ;
}
if ( V_335 & V_354 ) {
F_153 ( V_326 , L_77 ) ;
} else if ( V_335 & V_355 ) {
F_153 ( V_326 , L_78 ) ;
} else {
F_153 ( V_326 , L_79 ) ;
}
if ( V_335 & V_356 ) {
F_153 ( V_326 , L_80 ) ;
} else {
F_153 ( V_326 , L_81 ) ;
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
F_153 ( V_326 , L_82 , V_87 ) ;
V_29 = F_30 ( V_88 , V_87 ) ;
if ( V_327 & V_71 ) {
V_29 *= 4 ;
} else if ( V_327 & V_72 ) {
V_29 *= 2 ;
}
F_153 ( V_326 , L_83 ,
( unsigned int ) V_29 ) ;
V_336 = F_4 ( V_3 , V_352 ) ;
V_85 = V_336 & 0xF ;
V_336 >>= 4 ;
V_85 += ( V_336 & 0x3 ) * 10 ;
V_336 >>= 4 ;
V_337 = V_336 & 0xF ;
V_336 >>= 4 ;
V_337 += ( V_336 & 0x7 ) * 10 ;
V_336 >>= 4 ;
V_338 = V_336 & 0xF ;
V_336 >>= 4 ;
V_338 += ( V_336 & 0x7 ) * 10 ;
V_336 >>= 4 ;
V_339 = V_336 & 0xF ;
V_336 >>= 4 ;
V_339 += ( V_336 & 0x3 ) * 10 ;
F_153 ( V_326 ,
L_84 ,
V_339 , V_338 , V_337 , V_85 ) ;
} else {
F_153 ( V_326 , L_85 ) ;
}
F_153 ( V_326 , L_86 ) ;
V_333 = F_17 ( V_3 ) ;
F_153 ( V_326 ,
L_87 ,
V_333 , ( unsigned long ) V_3 -> V_73 ) ;
F_153 ( V_326 , L_88 ,
( V_3 -> V_70 & V_357 ) ? L_89 : L_90 ) ;
switch ( V_3 -> V_70 & V_358 ) {
case V_359 :
V_332 = L_91 ;
break;
case V_360 :
V_332 = L_92 ;
break;
default:
V_332 = L_93 ;
}
F_153 ( V_326 ,
L_94
L_95 ,
( V_3 -> V_70 & V_361 ) ? L_96 : L_90 ,
( V_3 -> V_70 & V_362 ) ? L_97 : L_98 ,
( V_3 -> V_70 & V_363 ) ? L_96 : L_90 ) ;
if ( ! ( V_3 -> V_70 & V_95 ) )
V_331 = L_13 ;
else
V_331 = L_12 ;
F_153 ( V_326 , L_99 , V_331 ) ;
switch ( F_82 ( V_3 ) ) {
case V_364 :
V_329 = L_24 ;
break;
case V_365 :
V_329 = L_100 ;
break;
case V_366 :
V_329 = L_26 ;
break;
case V_367 :
V_329 = L_27 ;
break;
default:
V_329 = L_101 ;
break;
}
F_153 ( V_326 , L_102 ,
V_329 ) ;
F_153 ( V_326 , L_103 ,
V_3 -> V_99 ) ;
F_153 ( V_326 , L_104 ) ;
V_333 = V_25 & V_275 ;
V_334 = V_26 & V_274 ;
F_153 ( V_326 , L_105 ,
( V_25 & V_43 ) ? ( V_333 ? L_35 : L_34 ) :
L_106 ,
( V_26 & V_49 ) ? ( V_334 ? L_35 : L_34 ) :
L_106 ) ;
switch ( F_16 ( V_3 ) ) {
case V_261 :
V_330 = L_27 ;
break;
case V_259 :
V_330 = L_26 ;
break;
case V_255 :
V_330 = L_24 ;
break;
case V_257 :
V_330 = L_100 ;
break;
case V_98 :
V_330 = L_107 ;
break;
default:
V_330 = L_108 ;
break;
}
F_153 ( V_326 ,
L_109 ,
V_330 , F_15 ( V_3 ) ,
( V_25 & V_60 ) >> 22 ,
( V_26 & V_51 ) >> 5 ) ;
F_153 ( V_326 , L_110 ,
( V_25 & V_368 ) ? L_111 : L_91 ,
( V_25 & V_369 ) ? L_112 :
L_113 ) ;
F_153 ( V_326 , L_114 ) ;
}
static void
F_154 ( struct V_323 * V_324 ,
struct V_325 * V_326 )
{
struct V_3 * V_3 = V_324 -> V_165 ;
unsigned int V_25 ;
unsigned int V_26 ;
unsigned int V_27 ;
unsigned int V_370 , V_371 ;
int V_372 ;
char * V_330 ;
int V_333 ;
V_25 = F_4 ( V_3 , V_34 ) ;
V_26 = F_4 ( V_3 , V_33 ) ;
V_27 = F_4 ( V_3 , V_35 ) ;
F_153 ( V_326 , L_115 ,
V_3 -> V_340 , V_3 -> V_172 -> V_341 + 1 ,
V_3 -> V_342 ) ;
F_153 ( V_326 , L_59 ,
V_3 -> V_179 , V_3 -> V_347 , ( unsigned long ) V_3 -> V_6 ) ;
F_153 ( V_326 , L_60 ) ;
F_153 ( V_326 ,
L_61 ,
V_25 & V_348 ,
( V_25 & V_186 ) ? 1 : 0 ,
( V_25 & V_192 ) ? 1 : 0 ,
V_3 -> V_349 ) ;
F_153 ( V_326 ,
L_62
L_63 ,
( ( V_25 & V_76 ) ? 1 : 0 ) ,
( V_25 & V_75 ) ,
( V_25 & V_75 ) %
( 2 * ( int ) V_3 -> V_73 ) ,
( ( V_25 & V_75 ) - 64 ) %
( 2 * ( int ) V_3 -> V_73 ) ,
( long ) F_20 ( V_3 ) * 4 ) ;
F_153 ( V_326 ,
L_64 ,
F_4 ( V_3 , V_184 ) & 0xFF ,
F_4 ( V_3 , V_190 ) & 0xFF ,
F_4 ( V_3 , V_182 ) & 0xFF ,
F_4 ( V_3 , V_188 ) & 0xFF ) ;
F_153 ( V_326 ,
L_65 ,
F_4 ( V_3 , V_175 ) & 0xFF ,
F_4 ( V_3 , V_177 ) & 0xFF ) ;
F_153 ( V_326 ,
L_66
L_67 ,
V_3 -> V_70 , V_3 -> V_350 ,
V_25 , V_26 ) ;
F_153 ( V_326 , L_86 ) ;
V_333 = F_17 ( V_3 ) ;
F_153 ( V_326 ,
L_87 ,
V_333 , ( unsigned long ) V_3 -> V_73 ) ;
F_153 ( V_326 , L_88 ,
( V_3 ->
V_70 & V_357 ) ? L_89 : L_90 ) ;
F_153 ( V_326 ,
L_116 ,
( V_3 ->
V_70 & V_361 ) ? L_96 : L_90 ,
( V_3 ->
V_70 & V_373 ) ? L_96 : L_90 ,
( V_3 ->
V_70 & V_374 ) ? L_96 : L_90 ) ;
V_372 = F_82 ( V_3 ) ;
if ( V_372 == 0 )
F_153 ( V_326 , L_117 ) ;
else
F_153 ( V_326 , L_118 ,
V_372 ) ;
F_153 ( V_326 , L_103 ,
V_3 -> V_99 ) ;
F_153 ( V_326 , L_119 ,
V_3 -> V_70 & V_266 ?
L_120 : L_121 ) ;
F_153 ( V_326 , L_122 ,
V_3 -> V_70 & V_268 ?
L_120 :
V_3 -> V_70 & V_269 ?
L_123 : L_121 ) ;
F_153 ( V_326 , L_104 ) ;
V_370 = V_25 & V_37 ;
V_371 = V_370 && ( V_25 & V_273 ) ;
F_153 ( V_326 , L_124 ,
( V_370 ) ? ( V_371 ? L_125 : L_126 ) : L_33 ,
F_1 ( ( V_25 >> V_38 ) & 0xF ) ) ;
for ( V_333 = 0 ; V_333 < 8 ; V_333 ++ ) {
F_153 ( V_326 , L_127 ,
V_333 + 1 ,
( V_26 & ( V_41 >> V_333 ) ) ?
L_125 : L_33 ,
F_1 ( ( V_27 >> ( 4 * V_333 ) ) & 0xF ) ) ;
}
switch ( F_16 ( V_3 ) ) {
case V_254 :
V_330 = L_23 ; break;
case V_36 :
V_330 = L_24 ; break;
case V_39 :
V_330 = L_15 ; break;
case V_375 :
V_330 = L_16 ; break;
case V_376 :
V_330 = L_17 ; break;
case V_377 :
V_330 = L_18 ; break;
case V_378 :
V_330 = L_19 ; break;
case V_379 :
V_330 = L_20 ; break;
case V_380 :
V_330 = L_21 ; break;
case V_40 :
V_330 = L_22 ; break;
default:
V_330 = L_108 ; break;
}
F_153 ( V_326 , L_128 , V_330 ) ;
F_153 ( V_326 , L_114 ) ;
}
static void
F_155 ( struct V_323 * V_324 ,
struct V_325 * V_326 )
{
struct V_3 * V_3 = V_324 -> V_165 ;
unsigned int V_381 , V_26 , V_382 , V_327 , V_16 ;
unsigned int V_22 , V_276 ;
V_381 = F_4 ( V_3 , V_225 ) ;
V_26 = F_4 ( V_3 , V_227 ) ;
V_382 = F_4 ( V_3 , V_277 ) ;
V_327 = V_3 -> V_70 ;
F_153 ( V_326 , L_129 , V_381 ) ;
F_153 ( V_326 , L_130 , V_26 ) ;
F_153 ( V_326 , L_131 , V_382 ) ;
F_153 ( V_326 , L_132 ) ;
F_153 ( V_326 , L_133 ,
( F_62 ( V_3 ) == 0 ) ? L_134 : L_135 ) ;
F_153 ( V_326 , L_136 ,
F_61 ( V_3 ) ) ;
F_153 ( V_326 , L_137 ) ;
V_22 = 0x1 ;
V_276 = 0x100 ;
for ( V_16 = 0 ; V_16 < 8 ; V_16 ++ ) {
F_153 ( V_326 , L_138 ,
V_16 ,
( V_381 & V_22 ) ? 1 : 0 ,
( V_381 & V_276 ) ? 1 : 0 ,
V_231 [ ( V_26 >> ( V_16 * 4 ) ) & 0xF ] ) ;
V_22 = V_22 << 1 ;
V_276 = V_276 << 1 ;
}
F_153 ( V_326 , L_139 ,
( V_381 & 0x1000000 ) ? 1 : 0 ,
( V_381 & 0x2000000 ) ? 1 : 0 ,
V_231 [ ( V_381 >> 16 ) & 0xF ] ) ;
F_153 ( V_326 , L_140 ,
( V_381 & 0x4000000 ) ? 1 : 0 ,
( V_381 & 0x8000000 ) ? 1 : 0 ,
V_231 [ ( V_381 >> 20 ) & 0xF ] ) ;
F_153 ( V_326 , L_141 ,
( V_382 & 0x400 ) ? 1 : 0 ,
( V_382 & 0x800 ) ? 1 : 0 ,
V_231 [ ( V_26 >> 12 ) & 0xF ] ) ;
}
static void
F_156 ( struct V_323 * V_324 ,
struct V_325 * V_326 )
{
struct V_3 * V_3 = V_324 -> V_165 ;
int V_143 , V_16 ;
for ( V_16 = 0 ; V_16 < 256 ; V_16 += V_143 ) {
F_153 ( V_326 , L_142 , V_16 ) ;
for ( V_143 = 0 ; V_143 < 16 ; V_143 += 4 )
F_153 ( V_326 , L_143 , F_4 ( V_3 , V_16 + V_143 ) ) ;
F_153 ( V_326 , L_114 ) ;
}
}
static void F_157 ( struct V_323 * V_324 ,
struct V_325 * V_326 )
{
struct V_3 * V_3 = V_324 -> V_165 ;
int V_16 ;
F_153 ( V_326 , L_144 ) ;
for ( V_16 = 0 ; V_16 < V_3 -> V_122 ; V_16 ++ ) {
F_153 ( V_326 , L_145 , V_16 + 1 , V_3 -> V_126 [ V_16 ] ) ;
}
}
static void F_158 ( struct V_323 * V_324 ,
struct V_325 * V_326 )
{
struct V_3 * V_3 = V_324 -> V_165 ;
int V_16 ;
F_153 ( V_326 , L_144 ) ;
for ( V_16 = 0 ; V_16 < V_3 -> V_124 ; V_16 ++ ) {
F_153 ( V_326 , L_145 , V_16 + 1 , V_3 -> V_128 [ V_16 ] ) ;
}
}
static void F_159 ( struct V_3 * V_3 )
{
struct V_323 * V_324 ;
if ( ! F_160 ( V_3 -> V_172 , L_146 , & V_324 ) ) {
switch ( V_3 -> V_31 ) {
case V_32 :
F_161 ( V_324 , V_3 ,
F_154 ) ;
break;
case V_46 :
F_161 ( V_324 , V_3 ,
F_152 ) ;
break;
case V_42 :
break;
case V_48 :
F_161 ( V_324 , V_3 ,
F_155 ) ;
break;
case V_47 :
break;
}
}
if ( ! F_160 ( V_3 -> V_172 , L_147 , & V_324 ) ) {
F_161 ( V_324 , V_3 , F_157 ) ;
}
if ( ! F_160 ( V_3 -> V_172 , L_148 , & V_324 ) ) {
F_161 ( V_324 , V_3 , F_158 ) ;
}
#ifdef F_162
if ( ! F_160 ( V_3 -> V_172 , L_149 , & V_324 ) )
F_161 ( V_324 , V_3 ,
F_156 ) ;
#endif
}
static int F_163 ( struct V_3 * V_3 )
{
V_3 -> V_235 = 0 ;
switch ( V_3 -> V_31 ) {
case V_46 :
case V_42 :
V_3 -> V_70 =
0x2 + 0x8 + 0x10 + 0x80 + 0x400 + 0x4000 + 0x1000000 ;
break;
case V_48 :
case V_47 :
V_3 -> V_235 = 0x1 + 0x1000 ;
V_3 -> V_70 =
0x2 + 0x8 + 0x10 + 0x80 + 0x400 + 0x4000 + 0x1000000 ;
break;
case V_32 :
V_3 -> V_70 =
V_95 |
F_26 ( 7 ) |
V_242 |
V_357 |
V_383 ;
break;
}
F_2 ( V_3 , V_80 , V_3 -> V_70 ) ;
if ( V_32 == V_3 -> V_31 ) {
#ifdef F_164
V_3 -> V_350 = V_384 ;
#else
V_3 -> V_350 = 0 ;
#endif
F_2 ( V_3 , V_385 , V_3 -> V_350 ) ;
}
F_19 ( V_3 ) ;
F_35 ( V_3 , 0 * V_145 ) ;
if ( V_3 -> V_31 == V_47 || V_3 -> V_31 == V_48 ) {
F_2 ( V_3 , V_238 , V_3 -> V_235 ) ;
}
F_33 ( V_3 , 48000 , 1 ) ;
return 0 ;
}
static T_3 F_165 ( int V_179 , void * V_386 )
{
struct V_3 * V_3 = (struct V_3 * ) V_386 ;
unsigned int V_25 ;
int V_16 , V_387 , V_147 , V_388 = 0 ;
V_25 = F_4 ( V_3 , V_34 ) ;
V_387 = V_25 & V_348 ;
V_147 = V_25 & ( V_186 | V_192 |
V_180 | V_197 ) ;
if ( ! V_387 && ! V_147 )
return V_389 ;
F_2 ( V_3 , V_390 , 0 ) ;
V_3 -> V_349 ++ ;
if ( V_387 ) {
if ( V_3 -> V_391 )
F_166 ( V_3 -> V_391 ) ;
if ( V_3 -> V_392 )
F_166 ( V_3 -> V_392 ) ;
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
V_388 = 1 ;
}
V_16 ++ ;
}
if ( V_388 )
F_167 ( & V_3 -> V_393 ) ;
}
return V_394 ;
}
static T_1 F_168 ( struct V_395
* V_162 )
{
struct V_3 * V_3 = F_169 ( V_162 ) ;
return F_20 ( V_3 ) ;
}
static int F_170 ( struct V_395 * V_162 )
{
struct V_396 * V_397 = V_162 -> V_397 ;
struct V_3 * V_3 = F_169 ( V_162 ) ;
struct V_395 * V_398 ;
if ( V_162 -> V_399 == V_400 )
V_398 = V_3 -> V_391 ;
else
V_398 = V_3 -> V_392 ;
if ( V_3 -> V_401 )
V_397 -> V_25 -> V_402 = F_20 ( V_3 ) ;
else
V_397 -> V_25 -> V_402 = 0 ;
if ( V_398 ) {
struct V_395 * V_77 ;
struct V_396 * V_403 = V_398 -> V_397 ;
F_171 (s, substream) {
if ( V_77 == V_398 ) {
V_403 -> V_25 -> V_402 =
V_397 -> V_25 -> V_402 ;
break;
}
}
}
return 0 ;
}
static int F_172 ( struct V_395 * V_162 ,
struct V_404 * V_405 )
{
struct V_3 * V_3 = F_169 ( V_162 ) ;
int V_173 ;
int V_16 ;
T_4 V_406 ;
T_4 V_407 ;
F_25 ( & V_3 -> V_22 ) ;
if ( V_162 -> V_408 -> V_399 == V_400 ) {
V_406 = V_3 -> V_23 ;
V_407 = V_3 -> V_24 ;
} else {
V_406 = V_3 -> V_24 ;
V_407 = V_3 -> V_23 ;
}
if ( V_407 > 0 && V_406 != V_407 ) {
if ( F_173 ( V_405 ) != V_3 -> V_99 ) {
F_27 ( & V_3 -> V_22 ) ;
F_174 ( V_405 ,
V_409 ) ;
return - V_115 ;
}
if ( F_175 ( V_405 ) != V_3 -> V_73 / 4 ) {
F_27 ( & V_3 -> V_22 ) ;
F_174 ( V_405 ,
V_410 ) ;
return - V_115 ;
}
}
F_27 ( & V_3 -> V_22 ) ;
F_25 ( & V_3 -> V_22 ) ;
V_173 = F_33 ( V_3 , F_173 ( V_405 ) , 0 ) ;
if ( V_173 < 0 ) {
F_34 ( V_411 L_150 , V_173 ) ;
F_27 ( & V_3 -> V_22 ) ;
F_174 ( V_405 ,
V_409 ) ;
return V_173 ;
}
F_27 ( & V_3 -> V_22 ) ;
V_173 = F_24 ( V_3 ,
F_175 ( V_405 ) ) ;
if ( V_173 < 0 ) {
F_34 ( V_411 L_151 , V_173 ) ;
F_174 ( V_405 ,
V_410 ) ;
return V_173 ;
}
V_173 =
F_176 ( V_162 , V_412 ) ;
if ( V_173 < 0 ) {
F_34 ( V_411 L_152 , V_173 ) ;
return V_173 ;
}
if ( V_162 -> V_399 == V_400 ) {
F_177 ( V_3 , V_162 , V_413 ,
F_178 ( V_405 ) ) ;
for ( V_16 = 0 ; V_16 < F_178 ( V_405 ) ; ++ V_16 )
F_11 ( V_3 , V_16 , 1 ) ;
V_3 -> V_82 =
( unsigned char * ) V_162 -> V_397 -> V_414 ;
F_179 ( L_153 ,
V_3 -> V_82 ) ;
} else {
F_177 ( V_3 , V_162 , V_415 ,
F_178 ( V_405 ) ) ;
for ( V_16 = 0 ; V_16 < F_178 ( V_405 ) ; ++ V_16 )
F_10 ( V_3 , V_16 , 1 ) ;
V_3 -> V_416 =
( unsigned char * ) V_162 -> V_397 -> V_414 ;
F_179 ( L_154 ,
V_3 -> V_416 ) ;
}
if ( V_417 == F_180 ( V_405 ) ) {
if ( ! ( V_3 -> V_70 & V_418 ) )
F_34 ( V_411 L_155 ) ;
V_3 -> V_70 |= V_418 ;
} else if ( V_419 == F_180 ( V_405 ) ) {
if ( V_3 -> V_70 & V_418 )
F_34 ( V_411 L_156 ) ;
V_3 -> V_70 &= ~ V_418 ;
}
F_2 ( V_3 , V_80 , V_3 -> V_70 ) ;
return 0 ;
}
static int F_181 ( struct V_395 * V_162 )
{
int V_16 ;
struct V_3 * V_3 = F_169 ( V_162 ) ;
if ( V_162 -> V_399 == V_400 ) {
for ( V_16 = 0 ; V_16 < V_3 -> V_124 ; ++ V_16 )
F_11 ( V_3 , V_16 , 0 ) ;
V_3 -> V_82 = NULL ;
} else {
for ( V_16 = 0 ; V_16 < V_3 -> V_122 ; ++ V_16 )
F_10 ( V_3 , V_16 , 0 ) ;
V_3 -> V_416 = NULL ;
}
F_182 ( V_162 ) ;
return 0 ;
}
static int F_183 ( struct V_395 * V_162 ,
struct V_420 * V_421 )
{
struct V_3 * V_3 = F_169 ( V_162 ) ;
if ( V_162 -> V_399 == V_400 ) {
if ( F_32 ( V_421 -> V_272 >= V_3 -> V_124 ) ) {
F_34 ( V_411 L_157 , V_421 -> V_272 ) ;
return - V_112 ;
}
if ( V_3 -> V_120 [ V_421 -> V_272 ] < 0 ) {
F_34 ( V_411 L_158 , V_421 -> V_272 ) ;
return - V_112 ;
}
V_421 -> V_422 = V_3 -> V_120 [ V_421 -> V_272 ] *
V_84 ;
} else {
if ( F_32 ( V_421 -> V_272 >= V_3 -> V_122 ) ) {
F_34 ( V_411 L_159 , V_421 -> V_272 ) ;
return - V_112 ;
}
if ( V_3 -> V_118 [ V_421 -> V_272 ] < 0 ) {
F_34 ( V_411 L_160 , V_421 -> V_272 ) ;
return - V_112 ;
}
V_421 -> V_422 = V_3 -> V_118 [ V_421 -> V_272 ] *
V_84 ;
}
V_421 -> V_423 = 0 ;
V_421 -> V_220 = 32 ;
return 0 ;
}
static int F_184 ( struct V_395 * V_162 ,
unsigned int V_424 , void * V_208 )
{
switch ( V_424 ) {
case V_425 :
return F_170 ( V_162 ) ;
case V_426 :
{
struct V_420 * V_421 = V_208 ;
return F_183 ( V_162 , V_421 ) ;
}
default:
break;
}
return F_185 ( V_162 , V_424 , V_208 ) ;
}
static int F_186 ( struct V_395 * V_162 , int V_424 )
{
struct V_3 * V_3 = F_169 ( V_162 ) ;
struct V_395 * V_398 ;
int V_401 ;
F_187 ( & V_3 -> V_22 ) ;
V_401 = V_3 -> V_401 ;
switch ( V_424 ) {
case V_427 :
V_401 |= 1 << V_162 -> V_399 ;
break;
case V_428 :
V_401 &= ~ ( 1 << V_162 -> V_399 ) ;
break;
default:
F_29 () ;
F_188 ( & V_3 -> V_22 ) ;
return - V_112 ;
}
if ( V_162 -> V_399 == V_400 )
V_398 = V_3 -> V_391 ;
else
V_398 = V_3 -> V_392 ;
if ( V_398 ) {
struct V_395 * V_77 ;
F_171 (s, substream) {
if ( V_77 == V_398 ) {
F_189 ( V_77 , V_162 ) ;
if ( V_424 == V_427 )
V_401 |= 1 << V_77 -> V_399 ;
else
V_401 &= ~ ( 1 << V_77 -> V_399 ) ;
goto V_429;
}
}
if ( V_424 == V_427 ) {
if ( ! ( V_401 & ( 1 << V_400 ) )
&& V_162 -> V_399 ==
V_430 )
F_23 ( V_3 ) ;
} else {
if ( V_401 &&
V_162 -> V_399 == V_400 )
F_23 ( V_3 ) ;
}
} else {
if ( V_162 -> V_399 == V_430 )
F_23 ( V_3 ) ;
}
V_429:
F_189 ( V_162 , V_162 ) ;
if ( ! V_3 -> V_401 && V_401 )
F_21 ( V_3 ) ;
else if ( V_3 -> V_401 && ! V_401 )
F_22 ( V_3 ) ;
V_3 -> V_401 = V_401 ;
F_188 ( & V_3 -> V_22 ) ;
return 0 ;
}
static int F_190 ( struct V_395 * V_162 )
{
return 0 ;
}
static int F_191 ( struct V_404 * V_405 ,
struct V_431 * V_432 )
{
struct V_3 * V_3 = V_432 -> V_433 ;
struct V_434 * V_435 =
F_192 ( V_405 , V_436 ) ;
struct V_434 * V_437 =
F_192 ( V_405 , V_409 ) ;
if ( V_437 -> V_218 > 96000 && V_437 -> V_219 <= 192000 ) {
struct V_434 V_438 = {
. V_218 = V_3 -> V_138 ,
. V_219 = V_3 -> V_138 ,
. integer = 1 ,
} ;
return F_193 ( V_435 , & V_438 ) ;
} else if ( V_437 -> V_218 > 48000 && V_437 -> V_219 <= 96000 ) {
struct V_434 V_438 = {
. V_218 = V_3 -> V_132 ,
. V_219 = V_3 -> V_132 ,
. integer = 1 ,
} ;
return F_193 ( V_435 , & V_438 ) ;
} else if ( V_437 -> V_219 < 64000 ) {
struct V_434 V_438 = {
. V_218 = V_3 -> V_123 ,
. V_219 = V_3 -> V_123 ,
. integer = 1 ,
} ;
return F_193 ( V_435 , & V_438 ) ;
}
return 0 ;
}
static int F_194 ( struct V_404 * V_405 ,
struct V_431 * V_432 )
{
struct V_3 * V_3 = V_432 -> V_433 ;
struct V_434 * V_435 =
F_192 ( V_405 , V_436 ) ;
struct V_434 * V_437 =
F_192 ( V_405 , V_409 ) ;
if ( V_437 -> V_218 > 96000 && V_437 -> V_219 <= 192000 ) {
struct V_434 V_438 = {
. V_218 = V_3 -> V_139 ,
. V_219 = V_3 -> V_139 ,
. integer = 1 ,
} ;
return F_193 ( V_435 , & V_438 ) ;
} else if ( V_437 -> V_218 > 48000 && V_437 -> V_219 <= 96000 ) {
struct V_434 V_438 = {
. V_218 = V_3 -> V_133 ,
. V_219 = V_3 -> V_133 ,
. integer = 1 ,
} ;
return F_193 ( V_435 , & V_438 ) ;
} else if ( V_437 -> V_219 < 64000 ) {
struct V_434 V_438 = {
. V_218 = V_3 -> V_125 ,
. V_219 = V_3 -> V_125 ,
. integer = 1 ,
} ;
return F_193 ( V_435 , & V_438 ) ;
} else {
}
return 0 ;
}
static int F_195 ( struct V_404 * V_405 ,
struct V_431 * V_432 )
{
struct V_3 * V_3 = V_432 -> V_433 ;
struct V_434 * V_435 =
F_192 ( V_405 , V_436 ) ;
struct V_434 * V_437 =
F_192 ( V_405 , V_409 ) ;
if ( V_435 -> V_218 >= V_3 -> V_123 ) {
struct V_434 V_438 = {
. V_218 = 32000 ,
. V_219 = 48000 ,
. integer = 1 ,
} ;
return F_193 ( V_437 , & V_438 ) ;
} else if ( V_435 -> V_219 <= V_3 -> V_138 ) {
struct V_434 V_438 = {
. V_218 = 128000 ,
. V_219 = 192000 ,
. integer = 1 ,
} ;
return F_193 ( V_437 , & V_438 ) ;
} else if ( V_435 -> V_219 <= V_3 -> V_132 ) {
struct V_434 V_438 = {
. V_218 = 64000 ,
. V_219 = 96000 ,
. integer = 1 ,
} ;
return F_193 ( V_437 , & V_438 ) ;
}
return 0 ;
}
static int F_196 ( struct V_404 * V_405 ,
struct V_431 * V_432 )
{
struct V_3 * V_3 = V_432 -> V_433 ;
struct V_434 * V_435 =
F_192 ( V_405 , V_436 ) ;
struct V_434 * V_437 =
F_192 ( V_405 , V_409 ) ;
if ( V_435 -> V_218 >= V_3 -> V_125 ) {
struct V_434 V_438 = {
. V_218 = 32000 ,
. V_219 = 48000 ,
. integer = 1 ,
} ;
return F_193 ( V_437 , & V_438 ) ;
} else if ( V_435 -> V_219 <= V_3 -> V_139 ) {
struct V_434 V_438 = {
. V_218 = 128000 ,
. V_219 = 192000 ,
. integer = 1 ,
} ;
return F_193 ( V_437 , & V_438 ) ;
} else if ( V_435 -> V_219 <= V_3 -> V_133 ) {
struct V_434 V_438 = {
. V_218 = 64000 ,
. V_219 = 96000 ,
. integer = 1 ,
} ;
return F_193 ( V_437 , & V_438 ) ;
}
return 0 ;
}
static int F_197 ( struct V_404 * V_405 ,
struct V_431 * V_432 )
{
unsigned int V_315 [ 3 ] ;
struct V_3 * V_3 = V_432 -> V_433 ;
struct V_434 * V_435 = F_192 ( V_405 ,
V_436 ) ;
V_315 [ 0 ] = V_3 -> V_138 ;
V_315 [ 1 ] = V_3 -> V_132 ;
V_315 [ 2 ] = V_3 -> V_123 ;
return F_198 ( V_435 , 3 , V_315 , 0 ) ;
}
static int F_199 ( struct V_404 * V_405 ,
struct V_431 * V_432 )
{
unsigned int V_315 [ 3 ] ;
struct V_3 * V_3 = V_432 -> V_433 ;
struct V_434 * V_435 = F_192 ( V_405 ,
V_436 ) ;
V_315 [ 0 ] = V_3 -> V_139 ;
V_315 [ 1 ] = V_3 -> V_133 ;
V_315 [ 2 ] = V_3 -> V_125 ;
return F_198 ( V_435 , 3 , V_315 , 0 ) ;
}
static int F_200 ( struct V_395 * V_162 )
{
struct V_3 * V_3 = F_169 ( V_162 ) ;
struct V_396 * V_397 = V_162 -> V_397 ;
F_25 ( & V_3 -> V_22 ) ;
F_201 ( V_162 ) ;
V_397 -> V_439 = V_440 ;
if ( V_3 -> V_391 == NULL )
F_22 ( V_3 ) ;
V_3 -> V_23 = V_441 -> V_442 ;
V_3 -> V_392 = V_162 ;
F_27 ( & V_3 -> V_22 ) ;
F_202 ( V_397 , 0 , 32 , 24 ) ;
F_203 ( V_397 , 0 , V_410 ) ;
switch ( V_3 -> V_31 ) {
case V_47 :
case V_48 :
F_204 ( V_397 ,
V_410 ,
32 , 4096 ) ;
F_204 ( V_397 ,
V_443 ,
16384 , 16384 ) ;
break;
default:
F_204 ( V_397 ,
V_410 ,
64 , 8192 ) ;
break;
}
if ( V_32 == V_3 -> V_31 ) {
V_397 -> V_439 . V_444 |= V_445 ;
F_205 ( V_397 , 0 , V_409 ,
& V_446 ) ;
} else {
F_206 ( V_397 , 0 , V_409 ,
F_196 , V_3 ,
V_436 , - 1 ) ;
}
F_206 ( V_397 , 0 , V_436 ,
F_199 , V_3 ,
V_436 , - 1 ) ;
F_206 ( V_397 , 0 , V_436 ,
F_194 , V_3 ,
V_409 , - 1 ) ;
return 0 ;
}
static int F_207 ( struct V_395 * V_162 )
{
struct V_3 * V_3 = F_169 ( V_162 ) ;
F_25 ( & V_3 -> V_22 ) ;
V_3 -> V_23 = - 1 ;
V_3 -> V_392 = NULL ;
F_27 ( & V_3 -> V_22 ) ;
return 0 ;
}
static int F_208 ( struct V_395 * V_162 )
{
struct V_3 * V_3 = F_169 ( V_162 ) ;
struct V_396 * V_397 = V_162 -> V_397 ;
F_25 ( & V_3 -> V_22 ) ;
F_201 ( V_162 ) ;
V_397 -> V_439 = V_447 ;
if ( V_3 -> V_392 == NULL )
F_22 ( V_3 ) ;
V_3 -> V_24 = V_441 -> V_442 ;
V_3 -> V_391 = V_162 ;
F_27 ( & V_3 -> V_22 ) ;
F_202 ( V_397 , 0 , 32 , 24 ) ;
F_203 ( V_397 , 0 , V_410 ) ;
switch ( V_3 -> V_31 ) {
case V_47 :
case V_48 :
F_204 ( V_397 ,
V_410 ,
32 , 4096 ) ;
F_204 ( V_397 ,
V_443 ,
16384 , 16384 ) ;
break;
default:
F_204 ( V_397 ,
V_410 ,
64 , 8192 ) ;
break;
}
if ( V_32 == V_3 -> V_31 ) {
V_397 -> V_439 . V_444 |= V_445 ;
F_205 ( V_397 , 0 , V_409 ,
& V_446 ) ;
} else {
F_206 ( V_397 , 0 , V_409 ,
F_195 , V_3 ,
V_436 , - 1 ) ;
}
F_206 ( V_397 , 0 , V_436 ,
F_197 , V_3 ,
V_436 , - 1 ) ;
F_206 ( V_397 , 0 , V_436 ,
F_191 , V_3 ,
V_409 , - 1 ) ;
return 0 ;
}
static int F_209 ( struct V_395 * V_162 )
{
struct V_3 * V_3 = F_169 ( V_162 ) ;
F_25 ( & V_3 -> V_22 ) ;
V_3 -> V_24 = - 1 ;
V_3 -> V_391 = NULL ;
F_27 ( & V_3 -> V_22 ) ;
return 0 ;
}
static int F_210 ( struct V_448 * V_439 , struct V_449 * V_449 )
{
return 0 ;
}
static inline int F_211 ( void T_5 * V_450 , void T_6 * V_451 )
{
V_15 V_5 = F_5 ( V_451 ) ;
return F_212 ( V_450 , & V_5 , 4 ) ;
}
static int F_213 ( struct V_448 * V_439 , struct V_449 * V_449 ,
unsigned int V_424 , unsigned long V_208 )
{
void T_5 * V_452 = ( void T_5 * ) V_208 ;
struct V_3 * V_3 = V_439 -> V_165 ;
struct V_453 V_10 ;
struct V_454 V_421 ;
struct V_455 V_25 ;
struct V_456 V_456 ;
struct V_457 * V_458 ;
struct V_459 V_336 ;
unsigned int V_460 ;
long unsigned int V_77 ;
int V_16 = 0 ;
switch ( V_424 ) {
case V_461 :
V_458 = & V_3 -> V_462 ;
for ( V_16 = 0 ; V_16 < V_83 ; V_16 ++ ) {
V_458 -> V_463 [ V_16 ] =
F_5 ( V_3 -> V_6 +
V_464 + V_16 * 4 ) ;
V_458 -> V_465 [ V_16 ] =
F_5 ( V_3 -> V_6 +
V_466 + V_16 * 4 ) ;
V_458 -> V_467 [ V_16 ] =
F_5 ( V_3 -> V_6 +
V_468 + V_16 * 4 ) ;
V_458 -> V_469 [ V_16 ] =
( ( V_470 ) F_5 ( V_3 -> V_6 +
V_471 + V_16 * 4 ) << 32 ) |
( V_470 ) F_5 ( V_3 -> V_6 +
V_472 + V_16 * 4 ) ;
V_458 -> V_473 [ V_16 ] =
( ( V_470 ) F_5 ( V_3 -> V_6 +
V_474 + V_16 * 4 ) << 32 ) |
( V_470 ) F_5 ( V_3 -> V_6 +
V_475 + V_16 * 4 ) ;
V_458 -> V_476 [ V_16 ] =
( ( V_470 ) F_5 ( V_3 -> V_6 +
V_477 + V_16 * 4 ) << 32 ) |
( V_470 ) F_5 ( V_3 -> V_6 +
V_478 + V_16 * 4 ) ;
}
if ( V_3 -> V_99 > 96000 ) {
V_458 -> V_479 = V_480 ;
} else if ( V_3 -> V_99 > 48000 ) {
V_458 -> V_479 = V_267 ;
} else {
V_458 -> V_479 = V_481 ;
}
V_458 -> V_26 = F_4 ( V_3 , V_33 ) ;
V_77 = F_212 ( V_452 , V_458 , sizeof( struct V_457 ) ) ;
if ( 0 != V_77 ) {
return - V_482 ;
}
break;
case V_483 :
V_336 . V_336 = F_4 ( V_3 , V_352 ) ;
V_16 = F_4 ( V_3 , V_352 + 4 ) ;
if ( V_16 & V_353 ) {
switch ( V_16 & ( V_286 |
V_287 ) ) {
case 0 :
V_336 . V_484 = V_485 ;
break;
case V_286 :
V_336 . V_484 = V_486 ;
break;
case V_287 :
V_336 . V_484 = V_487 ;
break;
default:
V_336 . V_484 = 30 ;
break;
}
if ( V_16 & V_288 ) {
V_336 . V_488 = V_489 ;
} else {
V_336 . V_488 = V_490 ;
}
} else {
V_336 . V_484 = V_491 ;
V_336 . V_488 = V_492 ;
}
if ( V_16 & V_354 ) {
V_336 . V_493 = V_494 ;
} else if ( V_16 & V_355 ) {
V_336 . V_493 = V_495 ;
} else {
V_336 . V_493 = V_496 ;
}
V_77 = F_212 ( V_452 , & V_336 , sizeof( struct V_459 ) ) ;
if ( 0 != V_77 ) {
return - V_482 ;
}
break;
case V_497 :
memset ( & V_421 , 0 , sizeof( V_421 ) ) ;
F_25 ( & V_3 -> V_22 ) ;
V_421 . V_329 = F_82 ( V_3 ) ;
V_421 . V_498 = F_120 ( V_3 ) ;
V_421 . V_99 = V_3 -> V_99 ;
V_421 . V_499 =
F_15 ( V_3 ) ;
V_421 . V_331 = F_62 ( V_3 ) ;
V_421 . V_500 = F_77 ( V_3 ) ;
V_421 . V_330 = F_16 ( V_3 ) ;
V_421 . V_501 = F_89 ( V_3 , V_357 ) ;
V_421 . V_502 = 0 ;
F_27 ( & V_3 -> V_22 ) ;
if ( F_212 ( V_452 , & V_421 , sizeof( V_421 ) ) )
return - V_482 ;
break;
case V_503 :
memset ( & V_25 , 0 , sizeof( V_25 ) ) ;
V_25 . V_504 = V_3 -> V_31 ;
V_25 . V_505 = F_16 ( V_3 ) ;
V_25 . V_506 = 110069313433624ULL ;
V_25 . V_507 = F_4 ( V_3 , V_210 ) ;
switch ( V_3 -> V_31 ) {
case V_46 :
case V_42 :
V_25 . V_508 . V_509 . V_510 =
F_120 ( V_3 ) ;
V_25 . V_508 . V_509 . V_511 =
F_121 ( V_3 ) ;
V_25 . V_508 . V_509 . V_512 =
F_125 ( V_3 ) ;
V_25 . V_508 . V_509 . V_513 =
F_123 ( V_3 ) ;
V_460 =
F_4 ( V_3 , V_34 ) ;
V_25 . V_508 . V_509 . V_514 =
( V_460 & V_368 ) ? 1 : 0 ;
V_25 . V_508 . V_509 . V_515 =
( V_460 & V_369 ) ? 1 : 0 ;
V_25 . V_508 . V_509 . V_516 = 0 ;
default:
break;
}
if ( F_212 ( V_452 , & V_25 , sizeof( V_25 ) ) )
return - V_482 ;
break;
case V_517 :
memset ( & V_456 , 0 , sizeof( V_456 ) ) ;
V_456 . V_504 = V_3 -> V_31 ;
strncpy ( V_456 . V_518 , V_3 -> V_340 ,
sizeof( V_456 . V_518 ) ) ;
V_456 . V_346 = V_3 -> V_346 ;
V_456 . V_342 = V_3 -> V_342 ;
V_456 . V_519 = 0 ;
if ( V_3 -> V_226 )
V_456 . V_519 |= V_520 ;
if ( F_212 ( V_452 , & V_456 ,
sizeof( V_456 ) ) )
return - V_482 ;
break;
case V_521 :
if ( F_214 ( & V_10 , V_452 , sizeof( V_10 ) ) )
return - V_482 ;
if ( F_212 ( ( void T_5 * ) V_10 . V_10 , V_3 -> V_10 ,
sizeof( struct V_522 ) ) )
return - V_482 ;
break;
default:
return - V_112 ;
}
return 0 ;
}
static int F_215 ( struct V_171 * V_172 ,
struct V_3 * V_3 )
{
struct V_448 * V_439 ;
int V_173 ;
V_173 = F_216 ( V_172 , L_161 , 0 , & V_439 ) ;
if ( V_173 < 0 )
return V_173 ;
V_3 -> V_523 = V_439 ;
V_439 -> V_165 = V_3 ;
strcpy ( V_439 -> V_199 , L_162 ) ;
V_439 -> V_524 . V_525 = F_210 ;
V_439 -> V_524 . V_526 = F_213 ;
V_439 -> V_524 . V_527 = F_213 ;
V_439 -> V_524 . V_528 = F_210 ;
return 0 ;
}
static int F_217 ( struct V_3 * V_3 )
{
int V_173 ;
struct V_529 * V_530 ;
T_7 V_531 ;
V_530 = V_3 -> V_530 ;
V_531 = V_412 ;
V_173 =
F_218 ( V_530 ,
V_532 ,
F_219 ( V_3 -> V_533 ) ,
V_531 ,
V_531 ) ;
if ( V_173 < 0 ) {
F_179 ( L_163 , V_531 ) ;
return V_173 ;
} else
F_179 ( L_164 , V_531 ) ;
return 0 ;
}
static void F_177 ( struct V_3 * V_3 ,
struct V_395 * V_162 ,
unsigned int V_4 , int V_534 )
{
int V_16 ;
for ( V_16 = 0 ; V_16 < ( V_534 * 16 ) ; V_16 ++ )
F_2 ( V_3 , V_4 + 4 * V_16 ,
F_220 ( V_162 , 4096 * V_16 ) ) ;
}
static int F_221 ( struct V_171 * V_172 ,
struct V_3 * V_3 )
{
struct V_529 * V_530 ;
int V_173 ;
V_173 = F_222 ( V_172 , V_3 -> V_340 , 0 , 1 , 1 , & V_530 ) ;
if ( V_173 < 0 )
return V_173 ;
V_3 -> V_530 = V_530 ;
V_530 -> V_165 = V_3 ;
strcpy ( V_530 -> V_199 , V_3 -> V_340 ) ;
F_223 ( V_530 , V_400 ,
& V_535 ) ;
F_223 ( V_530 , V_430 ,
& V_536 ) ;
V_530 -> V_204 = V_537 ;
V_173 = F_217 ( V_3 ) ;
if ( V_173 < 0 )
return V_173 ;
return 0 ;
}
static inline void F_224 ( struct V_3 * V_3 )
{
int V_16 ;
for ( V_16 = 0 ; V_16 < V_3 -> V_209 ; V_16 ++ )
F_40 ( V_3 , V_16 ) ;
}
static int F_225 ( struct V_171 * V_172 ,
struct V_3 * V_3 )
{
int V_173 , V_16 ;
F_179 ( L_165 ) ;
V_173 = F_221 ( V_172 , V_3 ) ;
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
V_173 = F_148 ( V_172 , V_3 ) ;
if ( V_173 < 0 )
return V_173 ;
V_173 = F_215 ( V_172 , V_3 ) ;
if ( V_173 < 0 )
return V_173 ;
F_179 ( L_166 ) ;
F_159 ( V_3 ) ;
V_3 -> V_99 = - 1 ;
V_3 -> V_538 = - 1 ;
V_3 -> V_539 = - 1 ;
V_3 -> V_23 = - 1 ;
V_3 -> V_24 = - 1 ;
V_3 -> V_391 = NULL ;
V_3 -> V_392 = NULL ;
F_179 ( L_167 ) ;
V_173 = F_163 ( V_3 ) ;
if ( V_173 < 0 )
return V_173 ;
F_179 ( L_168 ) ;
F_146 ( V_3 ) ;
F_179 ( L_169 ) ;
V_173 = F_226 ( V_172 ) ;
if ( V_173 < 0 ) {
F_34 ( V_113 L_170 ) ;
return V_173 ;
}
F_179 ( L_171 ) ;
return 0 ;
}
static int F_227 ( struct V_171 * V_172 ,
struct V_3 * V_3 )
{
struct V_540 * V_533 = V_3 -> V_533 ;
int V_173 ;
unsigned long V_541 ;
V_3 -> V_179 = - 1 ;
V_3 -> V_172 = V_172 ;
F_57 ( & V_3 -> V_22 ) ;
F_228 ( V_3 -> V_533 ,
V_542 , & V_3 -> V_342 ) ;
strcpy ( V_172 -> V_543 , L_172 ) ;
strcpy ( V_172 -> V_544 , L_173 ) ;
switch ( V_3 -> V_342 ) {
case V_545 :
V_3 -> V_31 = V_48 ;
V_3 -> V_340 = L_174 ;
V_3 -> V_209 = 2 ;
break;
case V_546 :
V_3 -> V_31 = V_47 ;
V_3 -> V_340 = L_175 ;
V_3 -> V_209 = 1 ;
break;
case V_547 :
V_3 -> V_31 = V_42 ;
V_3 -> V_340 = L_176 ;
V_3 -> V_209 = 1 ;
break;
default:
if ( ( V_3 -> V_342 == 0xf0 ) ||
( ( V_3 -> V_342 >= 0xe6 ) &&
( V_3 -> V_342 <= 0xea ) ) ) {
V_3 -> V_31 = V_32 ;
V_3 -> V_340 = L_177 ;
V_3 -> V_209 = 2 ;
} else if ( ( V_3 -> V_342 == 0xd2 ) ||
( ( V_3 -> V_342 >= 0xc8 ) &&
( V_3 -> V_342 <= 0xcf ) ) ) {
V_3 -> V_31 = V_46 ;
V_3 -> V_340 = L_178 ;
V_3 -> V_209 = 3 ;
} else {
F_34 ( V_113
L_179 ,
V_3 -> V_342 ) ;
return - V_548 ;
}
}
V_173 = F_229 ( V_533 ) ;
if ( V_173 < 0 )
return V_173 ;
F_230 ( V_3 -> V_533 ) ;
V_173 = F_231 ( V_533 , L_146 ) ;
if ( V_173 < 0 )
return V_173 ;
V_3 -> V_347 = F_232 ( V_533 , 0 ) ;
V_541 = F_233 ( V_533 , 0 ) ;
F_179 ( L_180 ,
V_3 -> V_347 , V_3 -> V_347 + V_541 - 1 ) ;
V_3 -> V_6 = F_234 ( V_3 -> V_347 , V_541 ) ;
if ( ! V_3 -> V_6 ) {
F_34 ( V_113 L_1
L_181 ,
V_3 -> V_347 , V_3 -> V_347 + V_541 - 1 ) ;
return - V_115 ;
}
F_179 ( L_182 ,
( unsigned long ) V_3 -> V_6 , V_3 -> V_347 ,
V_3 -> V_347 + V_541 - 1 ) ;
if ( F_235 ( V_533 -> V_179 , F_165 ,
V_549 , V_550 , V_3 ) ) {
F_34 ( V_113 L_183 , V_533 -> V_179 ) ;
return - V_115 ;
}
F_179 ( L_184 , V_533 -> V_179 ) ;
V_3 -> V_179 = V_533 -> V_179 ;
F_179 ( L_185 ,
sizeof( struct V_522 ) ) ;
V_3 -> V_10 = F_236 ( sizeof( struct V_522 ) , V_551 ) ;
if ( ! V_3 -> V_10 ) {
F_34 ( V_113 L_1
L_186 ,
( int ) sizeof( struct V_522 ) ) ;
return - V_552 ;
}
V_3 -> V_126 = NULL ;
V_3 -> V_128 = NULL ;
switch ( V_3 -> V_31 ) {
case V_32 :
V_3 -> V_123 = V_3 -> V_125 = V_553 ;
V_3 -> V_132 = V_3 -> V_133 = V_553 ;
V_3 -> V_138 = V_3 -> V_139 = V_553 ;
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
V_3 -> V_124 = V_3 -> V_122 =
V_553 ;
V_3 -> V_126 = V_3 -> V_128 =
V_555 ;
V_3 -> V_118 = V_3 -> V_120 =
V_554 ;
break;
case V_46 :
case V_42 :
V_3 -> V_123 = V_3 -> V_125 =
V_556 ;
V_3 -> V_132 = V_3 -> V_133 =
V_557 ;
V_3 -> V_138 = V_3 -> V_139 =
V_558 ;
V_3 -> V_119 = V_3 -> V_121 =
V_559 ;
V_3 -> V_130 = V_3 -> V_131 =
V_559 ;
V_3 -> V_136 = V_3 -> V_137 =
V_559 ;
V_3 -> V_127 = V_3 -> V_129 =
V_560 ;
V_3 -> V_134 = V_3 -> V_135 =
V_560 ;
V_3 -> V_140 = V_3 -> V_141 =
V_560 ;
break;
case V_47 :
if ( 0 == ( F_4 ( V_3 , V_33 ) & V_561 ) ) {
F_34 ( V_411 L_187 ) ;
}
V_3 -> V_123 = V_562 ;
V_3 -> V_132 = V_563 ;
V_3 -> V_138 = V_564 ;
V_3 -> V_125 = V_565 ;
V_3 -> V_133 = V_566 ;
V_3 -> V_139 = V_567 ;
V_3 -> V_121 = V_568 ;
V_3 -> V_131 = V_569 ;
V_3 -> V_137 = V_570 ;
V_3 -> V_119 = V_571 ;
V_3 -> V_130 = V_572 ;
V_3 -> V_136 = V_573 ;
V_3 -> V_127 = V_574 ;
V_3 -> V_129 = V_575 ;
V_3 -> V_134 = V_576 ;
V_3 -> V_135 = V_577 ;
V_3 -> V_140 = V_578 ;
V_3 -> V_141 = V_579 ;
break;
case V_48 :
V_3 -> V_123 = V_3 -> V_125 =
V_580 ;
V_3 -> V_132 = V_3 -> V_133 =
V_581 ;
V_3 -> V_138 = V_3 -> V_139 =
V_582 ;
V_3 -> V_122 = V_580 ;
V_3 -> V_124 = V_580 ;
V_3 -> V_119 = V_3 -> V_121 =
V_583 ;
V_3 -> V_130 = V_3 -> V_131 =
V_584 ;
V_3 -> V_136 = V_3 -> V_137 =
V_585 ;
V_3 -> V_118 = V_3 -> V_120 =
V_583 ;
V_3 -> V_127 = V_3 -> V_129 =
V_586 ;
V_3 -> V_134 = V_3 -> V_135 =
V_587 ;
V_3 -> V_140 = V_3 -> V_141 =
V_588 ;
break;
}
switch ( V_3 -> V_31 ) {
case V_47 :
case V_48 :
if ( F_4 ( V_3 , V_33 ) &
V_589 ) {
V_3 -> V_209 ++ ;
V_3 -> V_226 = F_236 ( sizeof( struct V_590 ) ,
V_551 ) ;
if ( NULL != V_3 -> V_226 ) {
F_127 ( V_3 ) ;
}
F_34 ( V_411 L_188 ) ;
} else {
V_3 -> V_226 = NULL ;
}
break;
case V_46 :
if ( F_4 ( V_3 , V_34 ) & V_351 ) {
V_3 -> V_209 ++ ;
V_3 -> V_226 = F_236 ( sizeof( struct V_590 ) ,
V_551 ) ;
if ( NULL != V_3 -> V_226 ) {
F_127 ( V_3 ) ;
}
F_34 ( V_411 L_189 ) ;
} else {
V_3 -> V_226 = NULL ;
}
break;
default:
V_3 -> V_226 = NULL ;
}
switch ( V_3 -> V_31 ) {
case V_32 :
if ( V_3 -> V_226 ) {
V_3 -> V_251 = V_591 ;
V_3 -> V_250 = 10 ;
} else {
V_3 -> V_251 = V_592 ;
V_3 -> V_250 = 9 ;
}
break;
case V_46 :
if ( V_3 -> V_226 ) {
V_3 -> V_251 = V_593 ;
V_3 -> V_250 = 4 ;
} else {
V_3 -> V_251 = V_594 ;
V_3 -> V_250 = 3 ;
}
break;
case V_42 :
break;
case V_48 :
if ( V_3 -> V_226 ) {
V_3 -> V_251 = V_595 ;
V_3 -> V_250 = 9 ;
} else {
V_3 -> V_251 = V_596 ;
V_3 -> V_250 = 8 ;
}
break;
case V_47 :
if ( V_3 -> V_226 ) {
V_3 -> V_251 = V_597 ;
V_3 -> V_250 = 6 ;
} else {
V_3 -> V_251 = V_598 ;
V_3 -> V_250 = 5 ;
}
break;
}
F_237 ( & V_3 -> V_393 ,
F_60 , ( unsigned long ) V_3 ) ;
if ( V_3 -> V_31 != V_42 ) {
V_3 -> V_346 = ( F_4 ( V_3 ,
V_182 ) >> 8 ) & 0xFFFFFF ;
if ( NULL == V_146 [ V_3 -> V_599 ] && V_3 -> V_346 != 0xFFFFFF ) {
sprintf ( V_172 -> V_146 , L_190 , V_3 -> V_346 ) ;
F_238 ( V_172 , V_172 -> V_146 ) ;
}
}
F_179 ( L_191 ) ;
V_173 = F_225 ( V_172 , V_3 ) ;
if ( V_173 < 0 )
return V_173 ;
F_224 ( V_3 ) ;
return 0 ;
}
static int F_239 ( struct V_3 * V_3 )
{
if ( V_3 -> V_347 ) {
V_3 -> V_70 &=
~ ( V_79 | V_78 |
V_185 | V_191 |
V_178 | V_196 ) ;
F_2 ( V_3 , V_80 ,
V_3 -> V_70 ) ;
}
if ( V_3 -> V_179 >= 0 )
F_240 ( V_3 -> V_179 , ( void * ) V_3 ) ;
F_241 ( V_3 -> V_10 ) ;
if ( V_3 -> V_6 )
F_242 ( V_3 -> V_6 ) ;
if ( V_3 -> V_347 )
F_243 ( V_3 -> V_533 ) ;
F_244 ( V_3 -> V_533 ) ;
return 0 ;
}
static void F_245 ( struct V_171 * V_172 )
{
struct V_3 * V_3 = V_172 -> V_165 ;
if ( V_3 )
F_239 ( V_3 ) ;
}
static int F_246 ( struct V_540 * V_533 ,
const struct V_600 * V_601 )
{
static int V_599 ;
struct V_3 * V_3 ;
struct V_171 * V_172 ;
int V_173 ;
if ( V_599 >= V_602 )
return - V_548 ;
if ( ! V_603 [ V_599 ] ) {
V_599 ++ ;
return - V_604 ;
}
V_173 = F_247 ( V_233 [ V_599 ] , V_146 [ V_599 ] ,
V_605 , sizeof( struct V_3 ) , & V_172 ) ;
if ( V_173 < 0 )
return V_173 ;
V_3 = V_172 -> V_165 ;
V_172 -> V_606 = F_245 ;
V_3 -> V_599 = V_599 ;
V_3 -> V_533 = V_533 ;
F_248 ( V_172 , & V_533 -> V_599 ) ;
V_173 = F_227 ( V_172 , V_3 ) ;
if ( V_173 < 0 ) {
F_249 ( V_172 ) ;
return V_173 ;
}
if ( V_3 -> V_31 != V_42 ) {
sprintf ( V_172 -> V_198 , L_192 ,
V_3 -> V_340 ,
V_3 -> V_346 ) ;
sprintf ( V_172 -> V_607 , L_193 ,
V_3 -> V_340 ,
V_3 -> V_346 ,
V_3 -> V_347 , V_3 -> V_179 ) ;
} else {
sprintf ( V_172 -> V_198 , L_194 , V_3 -> V_340 ) ;
sprintf ( V_172 -> V_607 , L_195 ,
V_3 -> V_340 , V_3 -> V_347 , V_3 -> V_179 ) ;
}
V_173 = F_226 ( V_172 ) ;
if ( V_173 < 0 ) {
F_249 ( V_172 ) ;
return V_173 ;
}
F_250 ( V_533 , V_172 ) ;
V_599 ++ ;
return 0 ;
}
static void F_251 ( struct V_540 * V_533 )
{
F_249 ( F_252 ( V_533 ) ) ;
F_250 ( V_533 , NULL ) ;
}
