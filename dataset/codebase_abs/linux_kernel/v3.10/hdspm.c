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
static int F_15 ( int V_25 )
{
if ( V_25 < 38050 )
return 32000 ;
if ( V_25 < 46008 )
return 44100 ;
else
return 48000 ;
}
static int F_16 ( struct V_3 * V_3 )
{
unsigned int V_26 , V_27 , V_28 ;
int V_29 , V_25 = 0 , V_30 ;
switch ( V_3 -> V_31 ) {
case V_32 :
V_27 = F_4 ( V_3 , V_33 ) ;
V_26 = F_4 ( V_3 , V_34 ) ;
V_28 = F_4 ( V_3 , V_35 ) ;
V_29 = F_17 ( V_3 ) ;
if ( V_29 == V_36 &&
V_26 & V_37 )
return F_1 ( ( V_26 >> V_38 ) & 0xF ) ;
if ( V_29 >= V_39 &&
V_29 <= V_40 &&
V_27 & ( V_41 >>
( V_29 - V_39 ) ) )
return F_1 ( ( V_28 >> ( 4 * ( V_29 - V_39 ) ) ) & 0xF ) ;
return 0 ;
break;
case V_42 :
V_26 = F_4 ( V_3 , V_34 ) ;
if ( ! ( V_26 & V_43 ) ) {
V_25 = 0 ;
} else {
switch ( V_26 & ( V_44 ) ) {
case V_45 * 1 :
V_25 = 32000 ; break;
case V_45 * 2 :
V_25 = 44100 ; break;
case V_45 * 3 :
V_25 = 48000 ; break;
case V_45 * 4 :
V_25 = 64000 ; break;
case V_45 * 5 :
V_25 = 88200 ; break;
case V_45 * 6 :
V_25 = 96000 ; break;
case V_45 * 7 :
V_25 = 128000 ; break;
case V_45 * 8 :
V_25 = 176400 ; break;
case V_45 * 9 :
V_25 = 192000 ; break;
default:
V_25 = 0 ; break;
}
}
break;
case V_46 :
case V_47 :
case V_48 :
V_27 = F_4 ( V_3 , V_33 ) ;
V_26 = F_4 ( V_3 , V_34 ) ;
V_25 = 0 ;
if ( ( V_27 & V_49 ) != 0 &&
( V_27 & V_50 ) == 0 ) {
V_30 = V_27 & V_51 ;
switch ( V_30 ) {
case V_52 :
V_25 = 32000 ;
break;
case V_53 :
V_25 = 44100 ;
break;
case V_54 :
V_25 = 48000 ;
break;
case V_55 :
V_25 = 64000 ;
break;
case V_56 :
V_25 = 88200 ;
break;
case V_57 :
V_25 = 96000 ;
break;
default:
V_25 = 0 ;
break;
}
}
if ( V_25 != 0 &&
( V_27 & V_58 ) == V_59 )
return V_25 ;
if ( V_26 & V_43 ) {
V_30 = V_26 & V_60 ;
switch ( V_30 ) {
case V_61 :
V_25 = 32000 ;
break;
case V_62 :
V_25 = 44100 ;
break;
case V_63 :
V_25 = 48000 ;
break;
case V_64 :
V_25 = 64000 ;
break;
case V_65 :
V_25 = 88200 ;
break;
case V_66 :
V_25 = 96000 ;
break;
case V_67 :
V_25 = 128000 ;
break;
case V_68 :
V_25 = 176400 ;
break;
case V_69 :
V_25 = 192000 ;
break;
default:
V_25 = 0 ;
break;
}
}
{
bool V_70 = 0 ;
bool V_71 = 0 ;
V_29 = F_17 ( V_3 ) ;
if ( V_72 == V_29 ) {
V_70 = 1 ;
V_71 = ( V_73 ==
F_18 ( V_3 ) ) ;
} else if ( V_74 == V_29 ) {
V_70 = 1 ;
V_71 = ( V_73 ==
F_19 ( V_3 ) ) ;
}
if ( V_70 && V_71 ) {
V_25 = F_15 (
F_20 ( V_3 ) ) ;
}
}
if ( V_25 <= 48000 ) {
if ( V_3 -> V_75 & V_76 )
V_25 *= 4 ;
else if ( V_3 -> V_75 &
V_77 )
V_25 *= 2 ;
}
break;
}
return V_25 ;
}
static int F_21 ( struct V_3 * V_3 )
{
int V_1 ;
V_1 = F_22 ( V_3 -> V_75 ) ;
if ( ( 7 == V_1 ) && ( V_48 == V_3 -> V_31 || V_47 == V_3 -> V_31 ) )
V_1 = - 1 ;
return 1 << ( V_1 + 6 ) ;
}
static inline void F_23 ( struct V_3 * V_3 )
{
V_3 -> V_78 = 4 * F_21 ( V_3 ) ;
}
static T_1 F_24 ( struct V_3 * V_3 )
{
int V_79 ;
V_79 = F_4 ( V_3 , V_34 ) ;
switch ( V_3 -> V_31 ) {
case V_48 :
case V_47 :
V_79 &= V_80 ;
V_79 /= 4 ;
break;
default:
V_79 = ( V_79 & V_81 ) ?
( V_3 -> V_78 / 4 ) : 0 ;
}
return V_79 ;
}
static inline void F_25 ( struct V_3 * V_82 )
{
V_82 -> V_75 |= ( V_83 | V_84 ) ;
F_2 ( V_82 , V_85 , V_82 -> V_75 ) ;
}
static inline void F_26 ( struct V_3 * V_82 )
{
V_82 -> V_75 &= ~ ( V_84 | V_83 ) ;
F_2 ( V_82 , V_85 , V_82 -> V_75 ) ;
}
static void F_27 ( struct V_3 * V_3 )
{
int V_16 ;
int V_1 = V_3 -> V_78 ;
void * V_86 = V_3 -> V_87 ;
if ( V_86 == NULL )
return;
for ( V_16 = 0 ; V_16 < V_88 ; V_16 ++ ) {
memset ( V_86 , 0 , V_1 ) ;
V_86 += V_89 ;
}
}
static int F_28 ( struct V_3 * V_82 , unsigned int V_90 )
{
int V_1 ;
F_29 ( & V_82 -> V_22 ) ;
if ( 32 == V_90 ) {
V_1 = 7 ;
} else {
V_90 >>= 7 ;
V_1 = 0 ;
while ( V_90 ) {
V_1 ++ ;
V_90 >>= 1 ;
}
}
V_82 -> V_75 &= ~ V_91 ;
V_82 -> V_75 |= F_30 ( V_1 ) ;
F_2 ( V_82 , V_85 , V_82 -> V_75 ) ;
F_23 ( V_82 ) ;
F_31 ( & V_82 -> V_22 ) ;
return 0 ;
}
static T_2 F_32 ( struct V_3 * V_3 , T_2 V_92 )
{
T_2 V_93 ;
if ( V_92 == 0 )
return 0 ;
switch ( V_3 -> V_31 ) {
case V_46 :
case V_32 :
V_93 = 110069313433624ULL ;
break;
case V_48 :
case V_47 :
V_93 = 104857600000000ULL ;
break;
case V_42 :
V_93 = 131072000000000ULL ;
break;
default:
F_33 () ;
return 0 ;
}
return F_34 ( V_93 , V_92 ) ;
}
static void F_35 ( struct V_3 * V_3 , int V_25 )
{
T_2 V_1 ;
if ( V_25 >= 112000 )
V_25 /= 4 ;
else if ( V_25 >= 56000 )
V_25 /= 2 ;
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
F_33 () ;
return;
}
V_1 = F_34 ( V_1 , V_25 ) ;
F_36 ( V_1 >> 32 ) ;
F_2 ( V_3 , V_94 , ( V_15 ) V_1 ) ;
}
static int F_37 ( struct V_3 * V_3 , int V_25 , int V_95 )
{
int V_96 ;
int V_30 ;
int V_97 = 0 ;
int V_98 , V_99 ;
if ( ! ( V_3 -> V_75 & V_100 ) ) {
if ( V_95 ) {
F_38 ( V_101 L_1
L_2
L_3 ) ;
V_97 = 1 ;
} else {
int V_102 =
F_16 ( V_3 ) ;
if ( F_17 ( V_3 ) ==
V_103 ) {
F_38 ( V_101 L_1
L_4 ) ;
V_97 = 1 ;
} else if ( V_25 != V_102 ) {
F_38 ( V_101 L_1
L_5
L_6 ) ;
V_97 = 1 ;
}
}
}
V_96 = V_3 -> V_104 ;
if ( V_96 <= 48000 )
V_98 = V_105 ;
else if ( V_96 <= 96000 )
V_98 = V_106 ;
else
V_98 = V_107 ;
if ( V_25 <= 48000 )
V_99 = V_105 ;
else if ( V_25 <= 96000 )
V_99 = V_106 ;
else
V_99 = V_107 ;
switch ( V_25 ) {
case 32000 :
V_30 = V_108 ;
break;
case 44100 :
V_30 = V_109 ;
break;
case 48000 :
V_30 = V_110 ;
break;
case 64000 :
V_30 = V_111 ;
break;
case 88200 :
V_30 = V_112 ;
break;
case 96000 :
V_30 = V_113 ;
break;
case 128000 :
V_30 = V_114 ;
break;
case 176400 :
V_30 = V_115 ;
break;
case 192000 :
V_30 = V_116 ;
break;
default:
return - V_117 ;
}
if ( V_98 != V_99
&& ( V_3 -> V_24 >= 0 || V_3 -> V_23 >= 0 ) ) {
F_38
( V_118 L_1
L_7
L_8 ,
V_119 [ V_98 ] ,
V_119 [ V_99 ] ,
V_3 -> V_24 , V_3 -> V_23 ) ;
return - V_120 ;
}
V_3 -> V_75 &= ~ V_121 ;
V_3 -> V_75 |= V_30 ;
F_2 ( V_3 , V_85 , V_3 -> V_75 ) ;
F_35 ( V_3 , V_25 ) ;
if ( V_32 == V_3 -> V_31 && V_25 != V_96 )
F_2 ( V_3 , V_122 , 0 ) ;
V_3 -> V_104 = V_25 ;
if ( V_25 <= 48000 ) {
V_3 -> V_123 = V_3 -> V_124 ;
V_3 -> V_125 = V_3 -> V_126 ;
V_3 -> V_127 = V_3 -> V_128 ;
V_3 -> V_129 = V_3 -> V_130 ;
V_3 -> V_131 = V_3 -> V_132 ;
V_3 -> V_133 = V_3 -> V_134 ;
} else if ( V_25 <= 96000 ) {
V_3 -> V_123 = V_3 -> V_135 ;
V_3 -> V_125 = V_3 -> V_136 ;
V_3 -> V_127 = V_3 -> V_137 ;
V_3 -> V_129 = V_3 -> V_138 ;
V_3 -> V_131 = V_3 -> V_139 ;
V_3 -> V_133 = V_3 -> V_140 ;
} else {
V_3 -> V_123 = V_3 -> V_141 ;
V_3 -> V_125 = V_3 -> V_142 ;
V_3 -> V_127 = V_3 -> V_143 ;
V_3 -> V_129 = V_3 -> V_144 ;
V_3 -> V_131 = V_3 -> V_145 ;
V_3 -> V_133 = V_3 -> V_146 ;
}
if ( V_97 != 0 )
return - 1 ;
return 0 ;
}
static void F_39 ( struct V_3 * V_3 , int V_147 )
{
int V_16 , V_148 ;
unsigned int V_149 ;
if ( V_147 > V_150 )
V_149 = V_150 ;
else if ( V_147 < 0 )
V_149 = 0 ;
else
V_149 = V_147 ;
for ( V_16 = 0 ; V_16 < V_9 ; V_16 ++ )
for ( V_148 = 0 ; V_148 < V_9 ; V_148 ++ ) {
F_8 ( V_3 , V_16 , V_148 , V_149 ) ;
F_9 ( V_3 , V_16 , V_148 , V_149 ) ;
}
}
static inline unsigned char F_40 ( struct V_3 * V_3 ,
int V_151 )
{
return F_4 ( V_3 , V_3 -> V_152 [ V_151 ] . V_153 ) ;
}
static inline void F_41 ( struct V_3 * V_3 , int V_151 ,
int V_5 )
{
return F_2 ( V_3 , V_3 -> V_152 [ V_151 ] . V_154 , V_5 ) ;
}
static inline int F_42 ( struct V_3 * V_3 , int V_151 )
{
return F_4 ( V_3 , V_3 -> V_152 [ V_151 ] . V_155 ) & 0xFF ;
}
static inline int F_43 ( struct V_3 * V_3 , int V_151 )
{
int V_156 ;
V_156 = F_4 ( V_3 , V_3 -> V_152 [ V_151 ] . V_157 ) & 0xFF ;
if ( V_156 < 128 )
return 128 - V_156 ;
else
return 0 ;
}
static void F_44 ( struct V_3 * V_3 , int V_151 )
{
while ( F_42 ( V_3 , V_151 ) )
F_40 ( V_3 , V_151 ) ;
}
static int F_45 ( struct V_158 * V_159 )
{
unsigned long V_20 ;
int V_160 ;
int V_161 ;
int V_16 ;
unsigned char V_86 [ 128 ] ;
F_13 ( & V_159 -> V_22 , V_20 ) ;
if ( V_159 -> V_162 &&
! F_46 ( V_159 -> V_162 ) ) {
V_160 = F_43 ( V_159 -> V_3 ,
V_159 -> V_151 ) ;
if ( V_160 > 0 ) {
if ( V_160 > ( int ) sizeof ( V_86 ) )
V_160 = sizeof ( V_86 ) ;
V_161 = F_47 ( V_159 -> V_162 , V_86 ,
V_160 ) ;
if ( V_161 > 0 ) {
for ( V_16 = 0 ; V_16 < V_161 ; ++ V_16 )
F_41 ( V_159 -> V_3 ,
V_159 -> V_151 ,
V_86 [ V_16 ] ) ;
}
}
}
F_14 ( & V_159 -> V_22 , V_20 ) ;
return 0 ;
}
static int F_48 ( struct V_158 * V_159 )
{
unsigned char V_86 [ 128 ] ;
unsigned long V_20 ;
int V_160 ;
int V_16 ;
F_13 ( & V_159 -> V_22 , V_20 ) ;
V_160 = F_42 ( V_159 -> V_3 , V_159 -> V_151 ) ;
if ( V_160 > 0 ) {
if ( V_159 -> V_163 ) {
if ( V_160 > ( int ) sizeof ( V_86 ) )
V_160 = sizeof ( V_86 ) ;
for ( V_16 = 0 ; V_16 < V_160 ; ++ V_16 )
V_86 [ V_16 ] = F_40 ( V_159 -> V_3 ,
V_159 -> V_151 ) ;
if ( V_160 )
F_49 ( V_159 -> V_163 , V_86 ,
V_160 ) ;
} else {
while ( V_160 -- )
F_40 ( V_159 -> V_3 ,
V_159 -> V_151 ) ;
}
}
V_159 -> V_164 = 0 ;
F_14 ( & V_159 -> V_22 , V_20 ) ;
F_13 ( & V_159 -> V_3 -> V_22 , V_20 ) ;
V_159 -> V_3 -> V_75 |= V_159 -> V_165 ;
F_2 ( V_159 -> V_3 , V_85 ,
V_159 -> V_3 -> V_75 ) ;
F_14 ( & V_159 -> V_3 -> V_22 , V_20 ) ;
return F_45 ( V_159 ) ;
}
static void
F_50 ( struct V_166 * V_167 , int V_168 )
{
struct V_3 * V_3 ;
struct V_158 * V_159 ;
unsigned long V_20 ;
V_159 = V_167 -> V_169 -> V_170 ;
V_3 = V_159 -> V_3 ;
F_13 ( & V_3 -> V_22 , V_20 ) ;
if ( V_168 ) {
if ( ! ( V_3 -> V_75 & V_159 -> V_165 ) ) {
F_44 ( V_3 , V_159 -> V_151 ) ;
V_3 -> V_75 |= V_159 -> V_165 ;
}
} else {
V_3 -> V_75 &= ~ V_159 -> V_165 ;
}
F_2 ( V_3 , V_85 , V_3 -> V_75 ) ;
F_14 ( & V_3 -> V_22 , V_20 ) ;
}
static void F_51 ( unsigned long V_13 )
{
struct V_158 * V_159 = (struct V_158 * ) V_13 ;
unsigned long V_20 ;
F_45 ( V_159 ) ;
F_13 ( & V_159 -> V_22 , V_20 ) ;
if ( V_159 -> V_171 ) {
V_159 -> V_172 . V_173 = 1 + V_174 ;
F_52 ( & V_159 -> V_172 ) ;
}
F_14 ( & V_159 -> V_22 , V_20 ) ;
}
static void
F_53 ( struct V_166 * V_167 , int V_168 )
{
struct V_158 * V_159 ;
unsigned long V_20 ;
V_159 = V_167 -> V_169 -> V_170 ;
F_13 ( & V_159 -> V_22 , V_20 ) ;
if ( V_168 ) {
if ( ! V_159 -> V_171 ) {
F_54 ( & V_159 -> V_172 ) ;
V_159 -> V_172 . V_175 = F_51 ;
V_159 -> V_172 . V_13 = ( unsigned long ) V_159 ;
V_159 -> V_172 . V_173 = 1 + V_174 ;
F_52 ( & V_159 -> V_172 ) ;
V_159 -> V_171 ++ ;
}
} else {
if ( V_159 -> V_171 && -- V_159 -> V_171 <= 0 )
F_55 ( & V_159 -> V_172 ) ;
}
F_14 ( & V_159 -> V_22 , V_20 ) ;
if ( V_168 )
F_45 ( V_159 ) ;
}
static int F_56 ( struct V_166 * V_167 )
{
struct V_158 * V_159 ;
V_159 = V_167 -> V_169 -> V_170 ;
F_29 ( & V_159 -> V_22 ) ;
F_44 ( V_159 -> V_3 , V_159 -> V_151 ) ;
V_159 -> V_163 = V_167 ;
F_31 ( & V_159 -> V_22 ) ;
return 0 ;
}
static int F_57 ( struct V_166 * V_167 )
{
struct V_158 * V_159 ;
V_159 = V_167 -> V_169 -> V_170 ;
F_29 ( & V_159 -> V_22 ) ;
V_159 -> V_162 = V_167 ;
F_31 ( & V_159 -> V_22 ) ;
return 0 ;
}
static int F_58 ( struct V_166 * V_167 )
{
struct V_158 * V_159 ;
F_50 ( V_167 , 0 ) ;
V_159 = V_167 -> V_169 -> V_170 ;
F_29 ( & V_159 -> V_22 ) ;
V_159 -> V_163 = NULL ;
F_31 ( & V_159 -> V_22 ) ;
return 0 ;
}
static int F_59 ( struct V_166 * V_167 )
{
struct V_158 * V_159 ;
F_53 ( V_167 , 0 ) ;
V_159 = V_167 -> V_169 -> V_170 ;
F_29 ( & V_159 -> V_22 ) ;
V_159 -> V_162 = NULL ;
F_31 ( & V_159 -> V_22 ) ;
return 0 ;
}
static int F_60 ( struct V_176 * V_177 ,
struct V_3 * V_3 , int V_151 )
{
int V_178 ;
char V_86 [ 32 ] ;
V_3 -> V_152 [ V_151 ] . V_151 = V_151 ;
V_3 -> V_152 [ V_151 ] . V_3 = V_3 ;
F_61 ( & V_3 -> V_152 [ V_151 ] . V_22 ) ;
if ( 0 == V_151 ) {
if ( V_42 == V_3 -> V_31 ) {
V_3 -> V_152 [ 0 ] . V_153 = V_179 ;
V_3 -> V_152 [ 0 ] . V_155 = V_180 ;
V_3 -> V_152 [ 0 ] . V_154 = V_181 ;
V_3 -> V_152 [ 0 ] . V_157 = V_182 ;
V_3 -> V_152 [ 0 ] . V_165 = V_183 ;
V_3 -> V_152 [ 0 ] . V_184 = V_185 ;
} else {
V_3 -> V_152 [ 0 ] . V_153 = V_186 ;
V_3 -> V_152 [ 0 ] . V_155 = V_187 ;
V_3 -> V_152 [ 0 ] . V_154 = V_188 ;
V_3 -> V_152 [ 0 ] . V_157 = V_189 ;
V_3 -> V_152 [ 0 ] . V_165 = V_190 ;
V_3 -> V_152 [ 0 ] . V_184 = V_191 ;
}
} else if ( 1 == V_151 ) {
V_3 -> V_152 [ 1 ] . V_153 = V_192 ;
V_3 -> V_152 [ 1 ] . V_155 = V_193 ;
V_3 -> V_152 [ 1 ] . V_154 = V_194 ;
V_3 -> V_152 [ 1 ] . V_157 = V_195 ;
V_3 -> V_152 [ 1 ] . V_165 = V_196 ;
V_3 -> V_152 [ 1 ] . V_184 = V_197 ;
} else if ( ( 2 == V_151 ) && ( V_46 == V_3 -> V_31 ) ) {
V_3 -> V_152 [ 2 ] . V_153 = V_179 ;
V_3 -> V_152 [ 2 ] . V_155 = V_180 ;
V_3 -> V_152 [ 2 ] . V_154 = V_181 ;
V_3 -> V_152 [ 2 ] . V_157 = V_182 ;
V_3 -> V_152 [ 2 ] . V_165 = V_183 ;
V_3 -> V_152 [ 2 ] . V_184 = V_185 ;
} else if ( 2 == V_151 ) {
V_3 -> V_152 [ 2 ] . V_153 = V_179 ;
V_3 -> V_152 [ 2 ] . V_155 = V_180 ;
V_3 -> V_152 [ 2 ] . V_154 = - 1 ;
V_3 -> V_152 [ 2 ] . V_157 = - 1 ;
V_3 -> V_152 [ 2 ] . V_165 = V_183 ;
V_3 -> V_152 [ 2 ] . V_184 = V_198 ;
} else if ( 3 == V_151 ) {
V_3 -> V_152 [ 3 ] . V_153 = V_199 ;
V_3 -> V_152 [ 3 ] . V_155 = V_200 ;
V_3 -> V_152 [ 3 ] . V_154 = - 1 ;
V_3 -> V_152 [ 3 ] . V_157 = - 1 ;
V_3 -> V_152 [ 3 ] . V_165 = V_201 ;
V_3 -> V_152 [ 3 ] . V_184 = V_202 ;
}
if ( ( V_151 < 2 ) || ( ( 2 == V_151 ) && ( ( V_46 == V_3 -> V_31 ) ||
( V_42 == V_3 -> V_31 ) ) ) ) {
if ( ( V_151 == 0 ) && ( V_42 == V_3 -> V_31 ) ) {
sprintf ( V_86 , L_9 , V_177 -> V_203 ) ;
} else if ( ( V_151 == 2 ) && ( V_46 == V_3 -> V_31 ) ) {
sprintf ( V_86 , L_9 , V_177 -> V_203 ) ;
} else {
sprintf ( V_86 , L_10 , V_177 -> V_203 , V_151 + 1 ) ;
}
V_178 = F_62 ( V_177 , V_86 , V_151 , 1 , 1 ,
& V_3 -> V_152 [ V_151 ] . V_169 ) ;
if ( V_178 < 0 )
return V_178 ;
sprintf ( V_3 -> V_152 [ V_151 ] . V_169 -> V_204 , L_10 ,
V_177 -> V_151 , V_151 + 1 ) ;
V_3 -> V_152 [ V_151 ] . V_169 -> V_170 = & V_3 -> V_152 [ V_151 ] ;
F_63 ( V_3 -> V_152 [ V_151 ] . V_169 ,
V_205 ,
& V_206 ) ;
F_63 ( V_3 -> V_152 [ V_151 ] . V_169 ,
V_207 ,
& V_208 ) ;
V_3 -> V_152 [ V_151 ] . V_169 -> V_209 |=
V_210 |
V_211 |
V_212 ;
} else {
sprintf ( V_86 , L_11 , V_177 -> V_203 , V_151 + 1 ) ;
V_178 = F_62 ( V_177 , V_86 , V_151 , 1 , 1 ,
& V_3 -> V_152 [ V_151 ] . V_169 ) ;
if ( V_178 < 0 )
return V_178 ;
sprintf ( V_3 -> V_152 [ V_151 ] . V_169 -> V_204 ,
L_11 , V_177 -> V_151 , V_151 + 1 ) ;
V_3 -> V_152 [ V_151 ] . V_169 -> V_170 = & V_3 -> V_152 [ V_151 ] ;
F_63 ( V_3 -> V_152 [ V_151 ] . V_169 ,
V_207 ,
& V_208 ) ;
V_3 -> V_152 [ V_151 ] . V_169 -> V_209 |= V_211 ;
}
return 0 ;
}
static void F_64 ( unsigned long V_213 )
{
struct V_3 * V_3 = (struct V_3 * ) V_213 ;
int V_16 = 0 ;
while ( V_16 < V_3 -> V_214 ) {
if ( V_3 -> V_152 [ V_16 ] . V_164 )
F_48 ( & V_3 -> V_152 [ V_16 ] ) ;
V_16 ++ ;
}
}
static inline int F_20 ( struct V_3 * V_3 )
{
unsigned int V_92 , V_25 ;
V_92 = F_4 ( V_3 , V_215 ) ;
V_25 = F_32 ( V_3 , V_92 ) ;
return V_25 ;
}
static int F_65 ( struct V_3 * V_3 )
{
unsigned int V_25 ;
V_25 = F_20 ( V_3 ) ;
if ( V_25 > 207000 ) {
if ( 0 == F_66 ( V_3 ) ) {
V_25 = V_3 -> V_104 ;
} else {
V_25 = F_16 ( V_3 ) ;
}
}
return V_25 ;
}
static int F_67 ( struct V_216 * V_217 ,
struct V_218 * V_219 )
{
V_219 -> type = V_220 ;
V_219 -> V_221 = 1 ;
V_219 -> V_222 . integer . V_223 = 27000 ;
V_219 -> V_222 . integer . V_224 = 207000 ;
V_219 -> V_222 . integer . V_225 = 1 ;
return 0 ;
}
static int F_68 ( struct V_216 * V_217 ,
struct V_226 *
V_227 )
{
struct V_3 * V_3 = F_69 ( V_217 ) ;
V_227 -> V_222 . integer . V_222 [ 0 ] = F_65 ( V_3 ) ;
return 0 ;
}
static int F_70 ( struct V_216 * V_217 ,
struct V_226 *
V_227 )
{
struct V_3 * V_3 = F_69 ( V_217 ) ;
F_35 ( V_3 , V_227 -> V_222 . V_228 . V_229 [ 0 ] ) ;
return 0 ;
}
static int F_71 ( struct V_3 * V_3 )
{
int V_26 ;
switch ( V_3 -> V_31 ) {
case V_48 :
case V_47 :
V_26 = F_4 ( V_3 , V_230 ) ;
return ( V_26 >> 16 ) & 0xF ;
break;
default:
break;
}
return 0 ;
}
static int F_72 ( struct V_3 * V_3 )
{
int V_26 ;
if ( V_3 -> V_231 ) {
switch ( V_3 -> V_31 ) {
case V_48 :
case V_47 :
V_26 = F_4 ( V_3 , V_230 ) ;
return ( V_26 >> 20 ) & 0xF ;
break;
default:
break;
}
}
return 0 ;
}
static int F_73 ( struct V_3 * V_3 )
{
int V_26 ;
if ( V_3 -> V_231 ) {
switch ( V_3 -> V_31 ) {
case V_48 :
case V_47 :
V_26 = F_4 ( V_3 , V_232 ) ;
return ( V_26 >> 12 ) & 0xF ;
break;
default:
break;
}
}
return 0 ;
}
static int F_74 ( struct V_3 * V_3 , unsigned int V_233 )
{
int V_26 = F_4 ( V_3 , V_232 ) ;
return ( V_26 >> ( V_233 * 4 ) ) & 0xF ;
}
static int F_75 ( struct V_216 * V_217 ,
struct V_218 * V_219 )
{
F_76 ( V_219 , V_234 ) ;
return 0 ;
}
static int F_77 ( struct V_216 * V_217 ,
struct V_226 *
V_227 )
{
struct V_3 * V_3 = F_69 ( V_217 ) ;
switch ( V_3 -> V_31 ) {
case V_48 :
switch ( V_217 -> V_235 ) {
case 0 :
V_227 -> V_222 . V_228 . V_229 [ 0 ] =
F_71 ( V_3 ) ;
break;
case 7 :
V_227 -> V_222 . V_228 . V_229 [ 0 ] =
F_72 ( V_3 ) ;
break;
case 8 :
V_227 -> V_222 . V_228 . V_229 [ 0 ] =
F_73 ( V_3 ) ;
break;
default:
V_227 -> V_222 . V_228 . V_229 [ 0 ] =
F_74 ( V_3 ,
V_217 -> V_235 - 1 ) ;
}
break;
case V_47 :
switch ( V_217 -> V_235 ) {
case 0 :
V_227 -> V_222 . V_228 . V_229 [ 0 ] =
F_71 ( V_3 ) ;
break;
case 4 :
V_227 -> V_222 . V_228 . V_229 [ 0 ] =
F_72 ( V_3 ) ;
break;
case 5 :
V_227 -> V_222 . V_228 . V_229 [ 0 ] =
F_73 ( V_3 ) ;
break;
default:
V_227 -> V_222 . V_228 . V_229 [ 0 ] =
F_74 ( V_3 ,
V_227 -> V_151 . V_236 - 1 ) ;
}
break;
case V_32 :
switch ( V_217 -> V_235 ) {
case 0 :
V_227 -> V_222 . V_228 . V_229 [ 0 ] =
F_71 ( V_3 ) ;
break;
case 9 :
V_227 -> V_222 . V_228 . V_229 [ 0 ] =
F_72 ( V_3 ) ;
break;
case 10 :
V_227 -> V_222 . V_228 . V_229 [ 0 ] =
F_73 ( V_3 ) ;
break;
default:
V_227 -> V_222 . V_228 . V_229 [ 0 ] =
F_74 ( V_3 ,
V_217 -> V_235 - 1 ) ;
break;
}
break;
case V_46 :
case V_42 :
{
int V_25 = F_16 ( V_3 ) ;
int V_16 , V_237 = 0 ;
for ( V_16 = 1 ; V_16 < 10 ; V_16 ++ )
if ( F_1 ( V_16 ) == V_25 ) {
V_237 = V_16 ;
break;
}
V_227 -> V_222 . V_228 . V_229 [ 0 ] = V_237 ;
}
break;
default:
break;
}
return 0 ;
}
static int F_66 ( struct V_3 * V_3 )
{
switch ( V_3 -> V_31 ) {
case V_47 :
case V_48 :
if ( V_3 -> V_238 & V_239 )
return 0 ;
break;
default:
if ( V_3 -> V_75 & V_100 )
return 0 ;
}
return 1 ;
}
static void F_78 ( struct V_3 * V_3 , int V_240 )
{
switch ( V_3 -> V_31 ) {
case V_47 :
case V_48 :
if ( 0 == V_240 )
V_3 -> V_238 |= V_239 ;
else
V_3 -> V_238 &= ~ V_239 ;
F_2 ( V_3 , V_241 , V_3 -> V_238 ) ;
break;
default:
if ( 0 == V_240 )
V_3 -> V_75 |= V_100 ;
else
V_3 -> V_75 &= ~ V_100 ;
F_2 ( V_3 , V_85 ,
V_3 -> V_75 ) ;
}
}
static int F_79 ( struct V_216 * V_217 ,
struct V_218 * V_219 )
{
static char * V_242 [] = { L_12 , L_13 } ;
F_76 ( V_219 , V_242 ) ;
return 0 ;
}
static int F_80 ( struct V_216 * V_217 ,
struct V_226 * V_227 )
{
struct V_3 * V_3 = F_69 ( V_217 ) ;
V_227 -> V_222 . V_228 . V_229 [ 0 ] = F_66 ( V_3 ) ;
return 0 ;
}
static int F_81 ( struct V_216 * V_217 ,
struct V_226 * V_227 )
{
struct V_3 * V_3 = F_69 ( V_217 ) ;
int V_5 ;
if ( ! F_12 ( V_3 ) )
return - V_120 ;
V_5 = V_227 -> V_222 . V_228 . V_229 [ 0 ] ;
if ( V_5 < 0 )
V_5 = 0 ;
else if ( V_5 > 1 )
V_5 = 1 ;
F_78 ( V_3 , V_5 ) ;
return 0 ;
}
static int F_82 ( struct V_3 * V_3 )
{
switch ( V_3 -> V_104 ) {
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
static int F_83 ( struct V_3 * V_3 , int V_240 )
{
int V_25 ;
switch ( V_240 ) {
case 0 :
V_25 = 32000 ; break;
case 1 :
V_25 = 44100 ; break;
case 2 :
V_25 = 48000 ; break;
case 3 :
V_25 = 64000 ; break;
case 4 :
V_25 = 88200 ; break;
case 5 :
V_25 = 96000 ; break;
case 6 :
V_25 = 128000 ; break;
case 7 :
V_25 = 176400 ; break;
case 8 :
V_25 = 192000 ; break;
default:
V_25 = 48000 ;
}
F_37 ( V_3 , V_25 , 1 ) ;
return 0 ;
}
static int F_84 ( struct V_216 * V_217 ,
struct V_218 * V_219 )
{
V_219 -> type = V_243 ;
V_219 -> V_221 = 1 ;
V_219 -> V_222 . V_228 . V_244 = 9 ;
if ( V_219 -> V_222 . V_228 . V_229 >= V_219 -> V_222 . V_228 . V_244 )
V_219 -> V_222 . V_228 . V_229 =
V_219 -> V_222 . V_228 . V_244 - 1 ;
strcpy ( V_219 -> V_222 . V_228 . V_204 ,
V_234 [ V_219 -> V_222 . V_228 . V_229 + 1 ] ) ;
return 0 ;
}
static int F_85 ( struct V_216 * V_217 ,
struct V_226 * V_227 )
{
struct V_3 * V_3 = F_69 ( V_217 ) ;
V_227 -> V_222 . V_228 . V_229 [ 0 ] = F_82 ( V_3 ) ;
return 0 ;
}
static int F_86 ( struct V_216 * V_217 ,
struct V_226 * V_227 )
{
struct V_3 * V_3 = F_69 ( V_217 ) ;
int V_245 ;
int V_5 ;
if ( ! F_12 ( V_3 ) )
return - V_120 ;
V_5 = V_227 -> V_222 . V_228 . V_229 [ 0 ] ;
if ( V_5 < 0 )
V_5 = 0 ;
if ( V_5 > 9 )
V_5 = 9 ;
F_29 ( & V_3 -> V_22 ) ;
if ( V_5 != F_82 ( V_3 ) )
V_245 = ( F_83 ( V_3 , V_5 ) == 0 ) ? 1 : 0 ;
else
V_245 = 0 ;
F_31 ( & V_3 -> V_22 ) ;
return V_245 ;
}
static int F_87 ( struct V_3 * V_3 )
{
switch ( V_3 -> V_31 ) {
case V_32 :
switch ( V_3 -> V_75 & V_246 ) {
case 0 : return 0 ;
case V_247 : return 1 ;
case V_248 : return 2 ;
case V_248 + V_247 : return 3 ;
case V_249 : return 4 ;
case V_249 + V_247 : return 5 ;
case V_249 + V_248 : return 6 ;
case V_249 + V_248 + V_247 :
return 7 ;
case V_250 : return 8 ;
case V_250 + V_247 : return 9 ;
}
break;
case V_46 :
case V_42 :
if ( V_3 -> V_231 ) {
switch ( V_3 -> V_75 & V_246 ) {
case 0 : return 0 ;
case V_247 : return 1 ;
case V_248 : return 2 ;
case V_248 + V_247 :
return 3 ;
}
} else {
switch ( V_3 -> V_75 & V_246 ) {
case 0 : return 0 ;
case V_247 : return 1 ;
case V_248 + V_247 :
return 2 ;
}
}
break;
case V_48 :
if ( V_3 -> V_231 ) {
switch ( ( V_3 -> V_238 &
V_251 ) / V_252 ) {
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
switch ( ( V_3 -> V_238 &
V_251 ) / V_252 ) {
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
if ( V_3 -> V_231 ) {
switch ( ( V_3 -> V_238 &
V_251 ) / V_252 ) {
case 0 : return 0 ;
case 3 : return 1 ;
case 1 : return 2 ;
case 2 : return 3 ;
case 9 : return 4 ;
case 10 : return 5 ;
}
} else {
switch ( ( V_3 -> V_238 &
V_251 ) / V_252 ) {
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
static int F_88 ( struct V_3 * V_3 , int V_253 )
{
int V_254 = 0 ;
switch ( V_3 -> V_31 ) {
case V_32 :
V_3 -> V_75 &= ~ V_246 ;
switch ( V_253 ) {
case 0 :
break;
case 1 :
V_3 -> V_75 |= V_247 ;
break;
case 2 :
V_3 -> V_75 |= V_248 ;
break;
case 3 :
V_3 -> V_75 |=
V_248 + V_247 ;
break;
case 4 :
V_3 -> V_75 |= V_249 ;
break;
case 5 :
V_3 -> V_75 |=
V_249 + V_247 ;
break;
case 6 :
V_3 -> V_75 |=
V_249 + V_248 ;
break;
case 7 :
V_3 -> V_75 |=
V_249 + V_248 + V_247 ;
break;
case 8 :
V_3 -> V_75 |= V_250 ;
break;
case 9 :
V_3 -> V_75 |=
V_250 + V_247 ;
break;
default:
return - 1 ;
}
break;
case V_46 :
case V_42 :
V_3 -> V_75 &= ~ V_246 ;
if ( V_3 -> V_231 ) {
switch ( V_253 ) {
case 0 :
break;
case 1 :
V_3 -> V_75 |= V_247 ;
break;
case 2 :
V_3 -> V_75 |= V_248 ;
break;
case 3 :
V_3 -> V_75 |=
V_247 + V_248 ;
break;
default:
return - 1 ;
}
} else {
switch ( V_253 ) {
case 0 :
break;
case 1 :
V_3 -> V_75 |= V_247 ;
break;
case 2 :
V_3 -> V_75 |=
V_247 + V_248 ;
break;
default:
return - 1 ;
}
}
break;
case V_48 :
if ( V_3 -> V_231 ) {
switch ( V_253 ) {
case 0 : V_254 = 0 ; break;
case 1 : V_254 = 3 ; break;
case 2 : V_254 = 4 ; break;
case 3 : V_254 = 5 ; break;
case 4 : V_254 = 6 ; break;
case 5 : V_254 = 1 ; break;
case 6 : V_254 = 2 ; break;
case 7 : V_254 = 9 ; break;
case 8 : V_254 = 10 ; break;
default: return - 1 ;
}
} else {
switch ( V_253 ) {
case 0 : V_254 = 0 ; break;
case 1 : V_254 = 3 ; break;
case 2 : V_254 = 4 ; break;
case 3 : V_254 = 5 ; break;
case 4 : V_254 = 6 ; break;
case 5 : V_254 = 1 ; break;
case 6 : V_254 = 2 ; break;
case 7 : V_254 = 10 ; break;
default: return - 1 ;
}
}
break;
case V_47 :
if ( V_3 -> V_231 ) {
switch ( V_253 ) {
case 0 : V_254 = 0 ; break;
case 1 : V_254 = 3 ; break;
case 2 : V_254 = 1 ; break;
case 3 : V_254 = 2 ; break;
case 4 : V_254 = 9 ; break;
case 5 : V_254 = 10 ; break;
default: return - 1 ;
}
} else {
switch ( V_253 ) {
case 0 : V_254 = 0 ; break;
case 1 : V_254 = 3 ; break;
case 2 : V_254 = 1 ; break;
case 3 : V_254 = 2 ; break;
case 4 : V_254 = 10 ; break;
default: return - 1 ;
}
}
break;
}
switch ( V_3 -> V_31 ) {
case V_48 :
case V_47 :
V_3 -> V_238 &= ~ V_251 ;
V_3 -> V_238 |= V_252 * V_254 ;
F_2 ( V_3 , V_241 , V_3 -> V_238 ) ;
break;
case V_46 :
case V_42 :
case V_32 :
F_2 ( V_3 , V_85 ,
V_3 -> V_75 ) ;
}
return 0 ;
}
static int F_89 ( struct V_216 * V_217 ,
struct V_218 * V_219 )
{
struct V_3 * V_3 = F_69 ( V_217 ) ;
V_219 -> type = V_243 ;
V_219 -> V_221 = 1 ;
V_219 -> V_222 . V_228 . V_244 = V_3 -> V_255 ;
if ( V_219 -> V_222 . V_228 . V_229 >= V_219 -> V_222 . V_228 . V_244 )
V_219 -> V_222 . V_228 . V_229 =
V_219 -> V_222 . V_228 . V_244 - 1 ;
strcpy ( V_219 -> V_222 . V_228 . V_204 ,
V_3 -> V_256 [ V_219 -> V_222 . V_228 . V_229 ] ) ;
return 0 ;
}
static int F_90 ( struct V_216 * V_217 ,
struct V_226 * V_227 )
{
struct V_3 * V_3 = F_69 ( V_217 ) ;
int V_257 = F_87 ( V_3 ) ;
if ( V_257 >= 0 ) {
V_227 -> V_222 . V_228 . V_229 [ 0 ] = V_257 ;
return 0 ;
}
return - 1 ;
}
static int F_91 ( struct V_216 * V_217 ,
struct V_226 * V_227 )
{
struct V_3 * V_3 = F_69 ( V_217 ) ;
int V_5 , V_245 = 0 ;
if ( ! F_12 ( V_3 ) )
return - V_120 ;
V_5 = V_227 -> V_222 . V_228 . V_229 [ 0 ] ;
if ( V_5 < 0 )
V_5 = 0 ;
else if ( V_5 >= V_3 -> V_255 )
V_5 = V_3 -> V_255 - 1 ;
F_29 ( & V_3 -> V_22 ) ;
if ( V_5 != F_87 ( V_3 ) )
V_245 = ( 0 == F_88 ( V_3 , V_5 ) ) ? 1 : 0 ;
F_31 ( & V_3 -> V_22 ) ;
return V_245 ;
}
static int F_17 ( struct V_3 * V_3 )
{
if ( V_32 == V_3 -> V_31 ) {
unsigned int V_26 = F_4 ( V_3 , V_34 ) ;
unsigned int V_29 =
( V_26 >> V_258 ) & 0xF ;
if ( V_29 == 0 )
return V_36 ;
if ( V_29 <= 8 )
return V_29 ;
return V_259 ;
} else if ( V_46 == V_3 -> V_31 ) {
unsigned int V_27 = F_4 ( V_3 , V_33 ) ;
switch ( V_27 & V_58 ) {
case V_59 :
return V_260 ;
case V_261 :
return V_262 ;
case V_263 :
return V_72 ;
case V_264 :
return V_74 ;
case V_265 :
return V_103 ;
default:
return 0 ;
}
}
return 0 ;
}
static int F_92 ( struct V_216 * V_217 ,
struct V_218 * V_219 )
{
struct V_3 * V_3 = F_69 ( V_217 ) ;
if ( V_32 == V_3 -> V_31 ) {
static char * V_242 [] = { L_14 , L_15 , L_16 , L_17 ,
L_18 , L_19 , L_20 , L_21 , L_22 , L_23 } ;
V_219 -> type = V_243 ;
V_219 -> V_221 = 1 ;
V_219 -> V_222 . V_228 . V_244 = 10 ;
if ( V_219 -> V_222 . V_228 . V_229 >=
V_219 -> V_222 . V_228 . V_244 )
V_219 -> V_222 . V_228 . V_229 =
V_219 -> V_222 . V_228 . V_244 - 1 ;
strcpy ( V_219 -> V_222 . V_228 . V_204 ,
V_242 [ V_219 -> V_222 . V_228 . V_229 ] ) ;
} else if ( V_46 == V_3 -> V_31 ) {
static char * V_242 [] = { L_24 , L_25 , L_26 ,
L_27 , L_23 } ;
V_219 -> type = V_243 ;
V_219 -> V_221 = 1 ;
V_219 -> V_222 . V_228 . V_244 = 5 ;
if ( V_219 -> V_222 . V_228 . V_229 >=
V_219 -> V_222 . V_228 . V_244 )
V_219 -> V_222 . V_228 . V_229 =
V_219 -> V_222 . V_228 . V_244 - 1 ;
strcpy ( V_219 -> V_222 . V_228 . V_204 ,
V_242 [ V_219 -> V_222 . V_228 . V_229 ] ) ;
}
return 0 ;
}
static int F_93 ( struct V_216 * V_217 ,
struct V_226 * V_227 )
{
struct V_3 * V_3 = F_69 ( V_217 ) ;
V_227 -> V_222 . V_228 . V_229 [ 0 ] = F_17 ( V_3 ) ;
return 0 ;
}
static int F_94 ( struct V_216 * V_217 ,
struct V_218 * V_219 )
{
static char * V_242 [] = { L_28 , L_29 , L_30 } ;
F_76 ( V_219 , V_242 ) ;
return 0 ;
}
static int F_95 ( struct V_216 * V_217 ,
struct V_226 * V_227 )
{
V_15 V_26 ;
int V_21 = 0 ;
struct V_3 * V_3 = F_69 ( V_217 ) ;
V_26 = F_4 ( V_3 , V_266 + 4 ) ;
switch ( V_26 & ( V_267 |
V_268 ) ) {
case V_267 :
V_21 = 1 ;
break;
case V_268 :
V_21 = 2 ;
break;
default:
V_21 = 0 ;
break;
}
V_227 -> V_222 . V_228 . V_229 [ 0 ] = V_21 ;
return 0 ;
}
static int F_96 ( struct V_216 * V_217 ,
struct V_218 * V_219 )
{
static char * V_242 [] = { L_31 , L_32 , L_33 , L_34 ,
L_35 } ;
F_76 ( V_219 , V_242 ) ;
return 0 ;
}
static int F_97 ( struct V_3 * V_3 )
{
V_15 V_26 ;
int V_21 = 0 ;
V_26 = F_4 ( V_3 , V_266 + 4 ) ;
if ( V_26 & V_269 ) {
switch ( V_26 & ( V_270 |
V_271 ) ) {
case 0 :
V_21 = 1 ;
break;
case V_270 :
V_21 = 2 ;
break;
case V_271 :
V_21 = 3 ;
break;
default:
V_21 = 4 ;
break;
}
}
return V_21 ;
}
static int F_98 ( struct V_216 * V_217 ,
struct V_226 * V_227 )
{
struct V_3 * V_3 = F_69 ( V_217 ) ;
V_227 -> V_222 . V_228 . V_229 [ 0 ] = F_97 ( V_3 ) ;
return 0 ;
}
static int F_99 ( struct V_3 * V_3 , V_15 V_272 )
{
return ( V_3 -> V_75 & V_272 ) ? 1 : 0 ;
}
static int F_100 ( struct V_3 * V_3 , V_15 V_272 , int V_273 )
{
if ( V_273 )
V_3 -> V_75 |= V_272 ;
else
V_3 -> V_75 &= ~ V_272 ;
F_2 ( V_3 , V_85 , V_3 -> V_75 ) ;
return 0 ;
}
static int F_101 ( struct V_216 * V_217 ,
struct V_226 * V_227 )
{
struct V_3 * V_3 = F_69 ( V_217 ) ;
V_15 V_272 = V_217 -> V_235 ;
F_29 ( & V_3 -> V_22 ) ;
V_227 -> V_222 . integer . V_222 [ 0 ] = F_99 ( V_3 , V_272 ) ;
F_31 ( & V_3 -> V_22 ) ;
return 0 ;
}
static int F_102 ( struct V_216 * V_217 ,
struct V_226 * V_227 )
{
struct V_3 * V_3 = F_69 ( V_217 ) ;
V_15 V_272 = V_217 -> V_235 ;
int V_245 ;
unsigned int V_5 ;
if ( ! F_12 ( V_3 ) )
return - V_120 ;
V_5 = V_227 -> V_222 . integer . V_222 [ 0 ] & 1 ;
F_29 ( & V_3 -> V_22 ) ;
V_245 = ( int ) V_5 != F_99 ( V_3 , V_272 ) ;
F_100 ( V_3 , V_272 , V_5 ) ;
F_31 ( & V_3 -> V_22 ) ;
return V_245 ;
}
static int F_103 ( struct V_3 * V_3 )
{
return ( V_3 -> V_75 & V_274 ) ? 1 : 0 ;
}
static int F_104 ( struct V_3 * V_3 , int V_273 )
{
if ( V_273 )
V_3 -> V_75 |= V_274 ;
else
V_3 -> V_75 &= ~ V_274 ;
F_2 ( V_3 , V_85 , V_3 -> V_75 ) ;
return 0 ;
}
static int F_105 ( struct V_216 * V_217 ,
struct V_218 * V_219 )
{
static char * V_242 [] = { L_36 , L_37 } ;
F_76 ( V_219 , V_242 ) ;
return 0 ;
}
static int F_106 ( struct V_216 * V_217 ,
struct V_226 * V_227 )
{
struct V_3 * V_3 = F_69 ( V_217 ) ;
F_29 ( & V_3 -> V_22 ) ;
V_227 -> V_222 . V_228 . V_229 [ 0 ] = F_103 ( V_3 ) ;
F_31 ( & V_3 -> V_22 ) ;
return 0 ;
}
static int F_107 ( struct V_216 * V_217 ,
struct V_226 * V_227 )
{
struct V_3 * V_3 = F_69 ( V_217 ) ;
int V_245 ;
unsigned int V_5 ;
if ( ! F_12 ( V_3 ) )
return - V_120 ;
V_5 = V_227 -> V_222 . integer . V_222 [ 0 ] & 1 ;
F_29 ( & V_3 -> V_22 ) ;
V_245 = ( int ) V_5 != F_103 ( V_3 ) ;
F_104 ( V_3 , V_5 ) ;
F_31 ( & V_3 -> V_22 ) ;
return V_245 ;
}
static int F_108 ( struct V_3 * V_3 )
{
return ( V_3 -> V_75 & V_275 ) ? 1 : 0 ;
}
static int F_109 ( struct V_3 * V_3 , int V_276 )
{
if ( V_276 )
V_3 -> V_75 |= V_275 ;
else
V_3 -> V_75 &= ~ V_275 ;
F_2 ( V_3 , V_85 , V_3 -> V_75 ) ;
return 0 ;
}
static int F_110 ( struct V_216 * V_217 ,
struct V_218 * V_219 )
{
static char * V_242 [] = { L_38 , L_39 } ;
F_76 ( V_219 , V_242 ) ;
return 0 ;
}
static int F_111 ( struct V_216 * V_217 ,
struct V_226 * V_227 )
{
struct V_3 * V_3 = F_69 ( V_217 ) ;
F_29 ( & V_3 -> V_22 ) ;
V_227 -> V_222 . V_228 . V_229 [ 0 ] = F_108 ( V_3 ) ;
F_31 ( & V_3 -> V_22 ) ;
return 0 ;
}
static int F_112 ( struct V_216 * V_217 ,
struct V_226 * V_227 )
{
struct V_3 * V_3 = F_69 ( V_217 ) ;
int V_245 ;
unsigned int V_5 ;
if ( ! F_12 ( V_3 ) )
return - V_120 ;
V_5 = V_227 -> V_222 . integer . V_222 [ 0 ] & 1 ;
F_29 ( & V_3 -> V_22 ) ;
V_245 = ( int ) V_5 != F_108 ( V_3 ) ;
F_109 ( V_3 , V_5 ) ;
F_31 ( & V_3 -> V_22 ) ;
return V_245 ;
}
static int F_113 ( struct V_3 * V_3 )
{
if ( V_3 -> V_75 & V_277 )
return 1 ;
if ( V_3 -> V_75 & V_278 )
return 2 ;
return 0 ;
}
static int F_114 ( struct V_3 * V_3 , int V_240 )
{
V_3 -> V_75 &= ~ ( V_277 | V_278 ) ;
switch ( V_240 ) {
case 0 :
break;
case 1 :
V_3 -> V_75 |= V_277 ;
break;
case 2 :
V_3 -> V_75 |= V_278 ;
break;
}
F_2 ( V_3 , V_85 , V_3 -> V_75 ) ;
return 0 ;
}
static int F_115 ( struct V_216 * V_217 ,
struct V_218 * V_219 )
{
static char * V_242 [] = { L_38 , L_39 , L_40 } ;
F_76 ( V_219 , V_242 ) ;
return 0 ;
}
static int F_116 ( struct V_216 * V_217 ,
struct V_226 * V_227 )
{
struct V_3 * V_3 = F_69 ( V_217 ) ;
F_29 ( & V_3 -> V_22 ) ;
V_227 -> V_222 . V_228 . V_229 [ 0 ] = F_113 ( V_3 ) ;
F_31 ( & V_3 -> V_22 ) ;
return 0 ;
}
static int F_117 ( struct V_216 * V_217 ,
struct V_226 * V_227 )
{
struct V_3 * V_3 = F_69 ( V_217 ) ;
int V_245 ;
int V_5 ;
if ( ! F_12 ( V_3 ) )
return - V_120 ;
V_5 = V_227 -> V_222 . integer . V_222 [ 0 ] ;
if ( V_5 < 0 )
V_5 = 0 ;
if ( V_5 > 2 )
V_5 = 2 ;
F_29 ( & V_3 -> V_22 ) ;
V_245 = V_5 != F_113 ( V_3 ) ;
F_114 ( V_3 , V_5 ) ;
F_31 ( & V_3 -> V_22 ) ;
return V_245 ;
}
static int F_118 ( struct V_3 * V_3 )
{
if ( V_3 -> V_75 & V_76 )
return 2 ;
if ( V_3 -> V_75 & V_77 )
return 1 ;
return 0 ;
}
static int F_119 ( struct V_3 * V_3 , int V_240 )
{
V_3 -> V_75 &= ~ ( V_77 | V_76 ) ;
switch ( V_240 ) {
case 0 :
break;
case 1 :
V_3 -> V_75 |= V_77 ;
break;
case 2 :
V_3 -> V_75 |= V_76 ;
break;
}
F_2 ( V_3 , V_85 , V_3 -> V_75 ) ;
return 0 ;
}
static int F_120 ( struct V_216 * V_217 ,
struct V_218 * V_219 )
{
static char * V_242 [] = { L_38 , L_39 , L_40 } ;
F_76 ( V_219 , V_242 ) ;
return 0 ;
}
static int F_121 ( struct V_216 * V_217 ,
struct V_226 * V_227 )
{
struct V_3 * V_3 = F_69 ( V_217 ) ;
F_29 ( & V_3 -> V_22 ) ;
V_227 -> V_222 . V_228 . V_229 [ 0 ] = F_118 ( V_3 ) ;
F_31 ( & V_3 -> V_22 ) ;
return 0 ;
}
static int F_122 ( struct V_216 * V_217 ,
struct V_226 * V_227 )
{
struct V_3 * V_3 = F_69 ( V_217 ) ;
int V_245 ;
int V_5 ;
if ( ! F_12 ( V_3 ) )
return - V_120 ;
V_5 = V_227 -> V_222 . integer . V_222 [ 0 ] ;
if ( V_5 < 0 )
V_5 = 0 ;
if ( V_5 > 2 )
V_5 = 2 ;
F_29 ( & V_3 -> V_22 ) ;
V_245 = V_5 != F_118 ( V_3 ) ;
F_119 ( V_3 , V_5 ) ;
F_31 ( & V_3 -> V_22 ) ;
return V_245 ;
}
static int F_123 ( struct V_216 * V_217 ,
struct V_218 * V_219 )
{
V_219 -> type = V_220 ;
V_219 -> V_221 = 3 ;
V_219 -> V_222 . integer . V_223 = 0 ;
V_219 -> V_222 . integer . V_224 = 65535 ;
V_219 -> V_222 . integer . V_225 = 1 ;
return 0 ;
}
static int F_124 ( struct V_216 * V_217 ,
struct V_226 * V_227 )
{
struct V_3 * V_3 = F_69 ( V_217 ) ;
int V_279 ;
int V_280 ;
V_279 = V_227 -> V_222 . integer . V_222 [ 0 ] ;
if ( V_279 < 0 )
V_279 = 0 ;
else if ( V_279 >= 2 * V_88 )
V_279 = 2 * V_88 - 1 ;
V_280 = V_227 -> V_222 . integer . V_222 [ 1 ] ;
if ( V_280 < 0 )
V_280 = 0 ;
else if ( V_280 >= V_88 )
V_280 = V_88 - 1 ;
F_29 ( & V_3 -> V_22 ) ;
if ( V_279 >= V_88 )
V_227 -> V_222 . integer . V_222 [ 2 ] =
F_7 ( V_3 , V_280 ,
V_279 - V_88 ) ;
else
V_227 -> V_222 . integer . V_222 [ 2 ] =
F_6 ( V_3 , V_280 , V_279 ) ;
F_31 ( & V_3 -> V_22 ) ;
return 0 ;
}
static int F_125 ( struct V_216 * V_217 ,
struct V_226 * V_227 )
{
struct V_3 * V_3 = F_69 ( V_217 ) ;
int V_245 ;
int V_279 ;
int V_280 ;
int V_149 ;
if ( ! F_12 ( V_3 ) )
return - V_120 ;
V_279 = V_227 -> V_222 . integer . V_222 [ 0 ] ;
V_280 = V_227 -> V_222 . integer . V_222 [ 1 ] ;
if ( V_279 < 0 || V_279 >= 2 * V_88 )
return - 1 ;
if ( V_280 < 0 || V_280 >= V_88 )
return - 1 ;
V_149 = V_227 -> V_222 . integer . V_222 [ 2 ] ;
F_29 ( & V_3 -> V_22 ) ;
if ( V_279 >= V_88 )
V_245 = V_149 != F_7 ( V_3 , V_280 ,
V_279 -
V_88 ) ;
else
V_245 = V_149 != F_6 ( V_3 , V_280 ,
V_279 ) ;
if ( V_245 ) {
if ( V_279 >= V_88 )
F_9 ( V_3 , V_280 ,
V_279 - V_88 ,
V_149 ) ;
else
F_8 ( V_3 , V_280 , V_279 ,
V_149 ) ;
}
F_31 ( & V_3 -> V_22 ) ;
return V_245 ;
}
static int F_126 ( struct V_216 * V_217 ,
struct V_218 * V_219 )
{
V_219 -> type = V_220 ;
V_219 -> V_221 = 1 ;
V_219 -> V_222 . integer . V_223 = 0 ;
V_219 -> V_222 . integer . V_224 = 64 ;
V_219 -> V_222 . integer . V_225 = 1 ;
return 0 ;
}
static int F_127 ( struct V_216 * V_217 ,
struct V_226 * V_227 )
{
struct V_3 * V_3 = F_69 ( V_217 ) ;
int V_281 ;
V_281 = V_227 -> V_151 . V_236 - 1 ;
if ( F_36 ( V_281 < 0 || V_281 >= V_88 ) )
return - V_117 ;
F_29 ( & V_3 -> V_22 ) ;
V_227 -> V_222 . integer . V_222 [ 0 ] =
( F_7 ( V_3 , V_281 , V_281 ) * 64 ) / V_150 ;
F_31 ( & V_3 -> V_22 ) ;
return 0 ;
}
static int F_128 ( struct V_216 * V_217 ,
struct V_226 * V_227 )
{
struct V_3 * V_3 = F_69 ( V_217 ) ;
int V_245 ;
int V_281 ;
int V_149 ;
if ( ! F_12 ( V_3 ) )
return - V_120 ;
V_281 = V_227 -> V_151 . V_236 - 1 ;
if ( F_36 ( V_281 < 0 || V_281 >= V_88 ) )
return - V_117 ;
V_149 = V_227 -> V_222 . integer . V_222 [ 0 ] * V_150 / 64 ;
F_29 ( & V_3 -> V_22 ) ;
V_245 =
V_149 != F_7 ( V_3 , V_281 ,
V_281 ) ;
if ( V_245 )
F_9 ( V_3 , V_281 , V_281 ,
V_149 ) ;
F_31 ( & V_3 -> V_22 ) ;
return V_245 ;
}
static int F_129 ( struct V_216 * V_217 ,
struct V_218 * V_219 )
{
static char * V_242 [] = { L_41 , L_42 , L_43 , L_44 } ;
F_76 ( V_219 , V_242 ) ;
return 0 ;
}
static int F_130 ( struct V_216 * V_217 ,
struct V_218 * V_219 )
{
static char * V_242 [] = { L_41 , L_42 } ;
F_76 ( V_219 , V_242 ) ;
return 0 ;
}
static int F_131 ( struct V_3 * V_3 )
{
int V_26 , V_27 ;
switch ( V_3 -> V_31 ) {
case V_32 :
V_26 = F_4 ( V_3 , V_34 ) ;
if ( V_26 & V_37 ) {
if ( V_26 & V_282 )
return 2 ;
else
return 1 ;
}
return 0 ;
break;
case V_46 :
V_27 = F_4 ( V_3 , V_33 ) ;
if ( V_27 & V_49 ) {
if ( V_27 & V_283 )
return 2 ;
else
return 1 ;
}
return 0 ;
break;
case V_48 :
case V_47 :
V_26 = F_4 ( V_3 , V_34 ) ;
if ( V_26 & 0x2000000 )
return 2 ;
else if ( V_26 & 0x1000000 )
return 1 ;
return 0 ;
break;
case V_42 :
break;
}
return 3 ;
}
static int F_132 ( struct V_3 * V_3 )
{
int V_26 = F_4 ( V_3 , V_34 ) ;
if ( V_26 & V_43 ) {
if ( V_26 & V_284 )
return 2 ;
else
return 1 ;
}
return 0 ;
}
static int F_133 ( struct V_3 * V_3 , int V_233 )
{
int V_26 , V_22 , V_285 ;
V_26 = F_4 ( V_3 , V_230 ) ;
V_22 = ( V_26 & ( 0x1 << V_233 ) ) ? 1 : 0 ;
V_285 = ( V_26 & ( 0x100 << V_233 ) ) ? 1 : 0 ;
if ( V_22 && V_285 )
return 2 ;
else if ( V_22 )
return 1 ;
return 0 ;
}
static int F_19 ( struct V_3 * V_3 )
{
int V_26 , V_22 = 0 , V_285 = 0 ;
switch ( V_3 -> V_31 ) {
case V_48 :
case V_47 :
V_26 = F_4 ( V_3 , V_286 ) ;
V_22 = ( V_26 & 0x400 ) ? 1 : 0 ;
V_285 = ( V_26 & 0x800 ) ? 1 : 0 ;
break;
case V_46 :
V_26 = F_4 ( V_3 , V_34 ) ;
V_22 = ( V_26 & V_287 ) ? 1 : 0 ;
V_285 = ( V_26 & V_288 ) ? 1 : 0 ;
break;
case V_32 :
V_26 = F_4 ( V_3 , V_33 ) ;
V_22 = ( V_26 & 0x100000 ) ? 1 : 0 ;
V_285 = ( V_26 & 0x200000 ) ? 1 : 0 ;
break;
case V_42 :
break;
}
if ( V_22 && V_285 )
return 2 ;
else if ( V_22 )
return 1 ;
return 0 ;
}
static int F_134 ( struct V_3 * V_3 , int V_233 )
{
int V_27 , V_22 , V_285 ;
V_27 = F_4 ( V_3 , V_33 ) ;
V_22 = ( V_27 & ( 0x0080 >> V_233 ) ) ? 1 : 0 ;
V_285 = ( V_27 & ( 0x8000 >> V_233 ) ) ? 1 : 0 ;
if ( V_285 )
return 2 ;
else if ( V_22 )
return 1 ;
return 0 ;
}
static int F_135 ( struct V_3 * V_3 , V_15 V_289 )
{
V_15 V_26 ;
V_26 = F_4 ( V_3 , V_266 + 4 ) ;
return ( V_26 & V_289 ) ? 1 : 0 ;
}
static int F_18 ( struct V_3 * V_3 )
{
int V_26 ;
if ( V_3 -> V_231 ) {
switch ( V_3 -> V_31 ) {
case V_46 :
case V_32 :
V_26 = F_4 ( V_3 , V_34 ) ;
if ( V_26 & V_290 ) {
if ( V_26 & V_291 )
return 2 ;
else
return 1 ;
}
return 0 ;
break;
case V_48 :
case V_47 :
V_26 = F_4 ( V_3 , V_230 ) ;
if ( V_26 & 0x8000000 )
return 2 ;
if ( V_26 & 0x4000000 )
return 1 ;
return 0 ;
break;
default:
break;
}
}
return 3 ;
}
static int F_136 ( struct V_216 * V_217 ,
struct V_226 * V_227 )
{
struct V_3 * V_3 = F_69 ( V_217 ) ;
int V_5 = - 1 ;
switch ( V_3 -> V_31 ) {
case V_48 :
switch ( V_217 -> V_235 ) {
case 0 :
V_5 = F_131 ( V_3 ) ; break;
case 7 :
V_5 = F_18 ( V_3 ) ; break;
case 8 :
V_5 = F_19 ( V_3 ) ; break;
default:
V_5 = F_133 ( V_3 ,
V_217 -> V_235 - 1 ) ;
}
break;
case V_47 :
switch ( V_217 -> V_235 ) {
case 0 :
V_5 = F_131 ( V_3 ) ; break;
case 4 :
V_5 = F_18 ( V_3 ) ; break;
case 5 :
V_5 = F_19 ( V_3 ) ; break;
default:
V_5 = F_133 ( V_3 , V_227 -> V_151 . V_236 - 1 ) ;
}
break;
case V_46 :
switch ( V_217 -> V_235 ) {
case 0 :
V_5 = F_131 ( V_3 ) ; break;
case 1 :
V_5 = F_132 ( V_3 ) ; break;
case 2 :
V_5 = F_18 ( V_3 ) ; break;
case 3 :
V_5 = F_19 ( V_3 ) ; break;
}
break;
case V_42 :
V_5 = F_132 ( V_3 ) ;
break;
case V_32 :
switch ( V_217 -> V_235 ) {
case 0 :
V_5 = F_131 ( V_3 ) ; break;
case 9 :
V_5 = F_18 ( V_3 ) ; break;
case 10 :
V_5 = F_19 ( V_3 ) ; break;
default:
V_5 = F_134 ( V_3 ,
V_217 -> V_235 - 1 ) ;
}
break;
}
if ( V_3 -> V_231 ) {
switch ( V_217 -> V_235 ) {
case 11 :
V_5 = F_135 ( V_3 , V_292 ) ;
break;
case 12 :
V_5 = F_135 ( V_3 ,
V_269 ) ;
break;
default:
break;
}
}
if ( - 1 == V_5 )
V_5 = 3 ;
V_227 -> V_222 . V_228 . V_229 [ 0 ] = V_5 ;
return 0 ;
}
static void F_137 ( struct V_3 * V_3 )
{
unsigned int V_293 [ 4 ] = { 0 , 0 , 0 , 0 } ;
switch ( V_3 -> V_231 -> V_163 ) {
case 0 :
V_293 [ 2 ] |= V_294 ;
break;
case 1 :
V_293 [ 2 ] |= V_295 ;
break;
default:
break;
}
switch ( V_3 -> V_231 -> V_296 ) {
case 1 :
V_293 [ 1 ] |= V_270 ;
break;
case 2 :
V_293 [ 1 ] |= V_271 ;
break;
case 3 :
V_293 [ 1 ] |= V_271 +
V_297 ;
break;
case 4 :
V_293 [ 1 ] |= V_270 +
V_271 ;
break;
case 5 :
V_293 [ 1 ] |= V_270 +
V_271 +
V_297 ;
break;
default:
break;
}
switch ( V_3 -> V_231 -> V_298 ) {
case 1 :
V_293 [ 2 ] |= V_299 ;
break;
case 2 :
V_293 [ 2 ] |= V_300 ;
break;
default:
break;
}
switch ( V_3 -> V_231 -> V_301 ) {
case 1 :
V_293 [ 2 ] |= V_302 ;
break;
case 2 :
V_293 [ 2 ] |= V_303 ;
break;
default:
break;
}
switch ( V_3 -> V_231 -> V_304 ) {
case 1 :
V_293 [ 2 ] |= V_305 ;
break;
case 2 :
V_293 [ 2 ] |= V_306 ;
break;
case 3 :
V_293 [ 2 ] |= V_305 + V_307 ;
break;
case 4 :
V_293 [ 2 ] |= V_306 + V_307 ;
break;
default:
break;
}
if ( 1 == V_3 -> V_231 -> V_308 ) {
V_293 [ 2 ] |= V_309 ;
}
F_2 ( V_3 , V_310 , V_293 [ 0 ] ) ;
F_2 ( V_3 , V_310 + 4 , V_293 [ 1 ] ) ;
F_2 ( V_3 , V_310 + 8 , V_293 [ 2 ] ) ;
F_2 ( V_3 , V_310 + 12 , V_293 [ 3 ] ) ;
}
static int F_138 ( struct V_216 * V_217 ,
struct V_218 * V_219 )
{
static char * V_242 [] = { L_45 , L_46 } ;
F_76 ( V_219 , V_242 ) ;
return 0 ;
}
static int F_139 ( struct V_216 * V_217 ,
struct V_226 * V_227 )
{
struct V_3 * V_3 = F_69 ( V_217 ) ;
V_227 -> V_222 . V_228 . V_229 [ 0 ] = V_3 -> V_231 -> V_301 ;
return 0 ;
}
static int F_140 ( struct V_216 * V_217 ,
struct V_226 * V_227 )
{
struct V_3 * V_3 = F_69 ( V_217 ) ;
if ( V_3 -> V_231 -> V_301 != V_227 -> V_222 . V_228 . V_229 [ 0 ] ) {
V_3 -> V_231 -> V_301 = V_227 -> V_222 . V_228 . V_229 [ 0 ] ;
F_137 ( V_3 ) ;
return 1 ;
}
return 0 ;
}
static int F_141 ( struct V_216 * V_217 ,
struct V_218 * V_219 )
{
static char * V_242 [] = { L_47 , L_48 , L_49 , L_50 , L_51 } ;
F_76 ( V_219 , V_242 ) ;
return 0 ;
}
static int F_142 ( struct V_216 * V_217 ,
struct V_226 * V_227 )
{
struct V_3 * V_3 = F_69 ( V_217 ) ;
V_227 -> V_222 . V_228 . V_229 [ 0 ] = V_3 -> V_231 -> V_304 ;
return 0 ;
}
static int F_143 ( struct V_216 * V_217 ,
struct V_226 * V_227 )
{
struct V_3 * V_3 = F_69 ( V_217 ) ;
if ( V_3 -> V_231 -> V_304 != V_227 -> V_222 . V_228 . V_229 [ 0 ] ) {
V_3 -> V_231 -> V_304 = V_227 -> V_222 . V_228 . V_229 [ 0 ] ;
F_137 ( V_3 ) ;
return 1 ;
}
return 0 ;
}
static int F_144 ( struct V_216 * V_217 ,
struct V_218 * V_219 )
{
static char * V_242 [] = { L_52 , L_53 , L_54 } ;
F_76 ( V_219 , V_242 ) ;
return 0 ;
}
static int F_145 ( struct V_216 * V_217 ,
struct V_226 * V_227 )
{
struct V_3 * V_3 = F_69 ( V_217 ) ;
V_227 -> V_222 . V_228 . V_229 [ 0 ] = V_3 -> V_231 -> V_298 ;
return 0 ;
}
static int F_146 ( struct V_216 * V_217 ,
struct V_226 * V_227 )
{
struct V_3 * V_3 = F_69 ( V_217 ) ;
if ( V_3 -> V_231 -> V_298 != V_227 -> V_222 . V_228 . V_229 [ 0 ] ) {
V_3 -> V_231 -> V_298 = V_227 -> V_222 . V_228 . V_229 [ 0 ] ;
F_137 ( V_3 ) ;
return 1 ;
}
return 0 ;
}
static int F_147 ( struct V_216 * V_217 ,
struct V_218 * V_219 )
{
static char * V_242 [] = { L_32 , L_33 , L_55 ,
L_56 , L_35 , L_57 } ;
F_76 ( V_219 , V_242 ) ;
return 0 ;
}
static int F_148 ( struct V_216 * V_217 ,
struct V_226 * V_227 )
{
struct V_3 * V_3 = F_69 ( V_217 ) ;
V_227 -> V_222 . V_228 . V_229 [ 0 ] = V_3 -> V_231 -> V_296 ;
return 0 ;
}
static int F_149 ( struct V_216 * V_217 ,
struct V_226 * V_227 )
{
struct V_3 * V_3 = F_69 ( V_217 ) ;
if ( V_3 -> V_231 -> V_296 != V_227 -> V_222 . V_228 . V_229 [ 0 ] ) {
V_3 -> V_231 -> V_296 = V_227 -> V_222 . V_228 . V_229 [ 0 ] ;
F_137 ( V_3 ) ;
return 1 ;
}
return 0 ;
}
static int F_150 ( struct V_216 * V_217 ,
struct V_218 * V_219 )
{
static char * V_242 [] = { L_58 , L_59 , L_60 } ;
F_76 ( V_219 , V_242 ) ;
return 0 ;
}
static int F_151 ( struct V_216 * V_217 ,
struct V_226 * V_227 )
{
struct V_3 * V_3 = F_69 ( V_217 ) ;
V_227 -> V_222 . V_228 . V_229 [ 0 ] = V_3 -> V_231 -> V_163 ;
return 0 ;
}
static int F_152 ( struct V_216 * V_217 ,
struct V_226 * V_227 )
{
struct V_3 * V_3 = F_69 ( V_217 ) ;
if ( V_3 -> V_231 -> V_163 != V_227 -> V_222 . V_228 . V_229 [ 0 ] ) {
V_3 -> V_231 -> V_163 = V_227 -> V_222 . V_228 . V_229 [ 0 ] ;
F_137 ( V_3 ) ;
return 1 ;
}
return 0 ;
}
static int F_153 ( struct V_216 * V_217 ,
struct V_218 * V_219 )
{
V_219 -> type = V_311 ;
V_219 -> V_221 = 1 ;
V_219 -> V_222 . integer . V_223 = 0 ;
V_219 -> V_222 . integer . V_224 = 1 ;
return 0 ;
}
static int F_154 ( struct V_216 * V_217 ,
struct V_226 * V_227 )
{
struct V_3 * V_3 = F_69 ( V_217 ) ;
V_227 -> V_222 . V_228 . V_229 [ 0 ] = V_3 -> V_231 -> V_308 ;
return 0 ;
}
static int F_155 ( struct V_216 * V_217 ,
struct V_226 * V_227 )
{
struct V_3 * V_3 = F_69 ( V_217 ) ;
if ( V_3 -> V_231 -> V_308 != V_227 -> V_222 . V_228 . V_229 [ 0 ] ) {
V_3 -> V_231 -> V_308 = V_227 -> V_222 . V_228 . V_229 [ 0 ] ;
F_137 ( V_3 ) ;
return 1 ;
}
return 0 ;
}
static int F_156 ( struct V_3 * V_3 )
{
int V_16 ;
for ( V_16 = V_3 -> V_138 ; V_16 < V_3 -> V_130 ; ++ V_16 ) {
if ( V_3 -> V_104 > 48000 ) {
V_3 -> V_312 [ V_16 ] -> V_313 [ 0 ] . V_314 =
V_315 |
V_316 |
V_317 ;
} else {
V_3 -> V_312 [ V_16 ] -> V_313 [ 0 ] . V_314 =
V_318 |
V_317 ;
}
F_157 ( V_3 -> V_177 , V_319 |
V_320 ,
& V_3 -> V_312 [ V_16 ] -> V_151 ) ;
}
return 0 ;
}
static int F_158 ( struct V_176 * V_177 ,
struct V_3 * V_3 )
{
unsigned int V_233 , V_321 ;
int V_178 ;
struct V_216 * V_322 ;
struct V_323 * V_324 = NULL ;
switch ( V_3 -> V_31 ) {
case V_46 :
V_324 = V_325 ;
V_321 = F_159 ( V_325 ) ;
break;
case V_42 :
V_324 = V_326 ;
V_321 = F_159 ( V_326 ) ;
break;
case V_47 :
V_324 = V_327 ;
V_321 = F_159 ( V_327 ) ;
break;
case V_48 :
V_324 = V_328 ;
V_321 = F_159 ( V_328 ) ;
break;
case V_32 :
V_324 = V_329 ;
V_321 = F_159 ( V_329 ) ;
break;
}
if ( NULL != V_324 ) {
for ( V_233 = 0 ; V_233 < V_321 ; V_233 ++ ) {
V_178 = F_160 ( V_177 ,
F_161 ( & V_324 [ V_233 ] , V_3 ) ) ;
if ( V_178 < 0 )
return V_178 ;
}
}
V_330 . V_204 = L_61 ;
if ( V_3 -> V_104 >= 128000 ) {
V_321 = V_3 -> V_144 ;
} else if ( V_3 -> V_104 >= 64000 ) {
V_321 = V_3 -> V_138 ;
} else {
V_321 = V_3 -> V_130 ;
}
for ( V_233 = 0 ; V_233 < V_321 ; ++ V_233 ) {
V_330 . V_236 = V_233 + 1 ;
V_322 = F_161 ( & V_330 , V_3 ) ;
V_178 = F_160 ( V_177 , V_322 ) ;
if ( V_178 < 0 )
return V_178 ;
V_3 -> V_312 [ V_233 ] = V_322 ;
}
if ( V_3 -> V_231 ) {
V_324 = V_331 ;
V_321 = F_159 ( V_331 ) ;
for ( V_233 = 0 ; V_233 < V_321 ; V_233 ++ ) {
V_178 = F_160 ( V_177 ,
F_161 ( & V_324 [ V_233 ] , V_3 ) ) ;
if ( V_178 < 0 )
return V_178 ;
}
}
return 0 ;
}
static void
F_162 ( struct V_332 * V_333 ,
struct V_334 * V_335 )
{
struct V_3 * V_3 = V_333 -> V_170 ;
unsigned int V_26 , V_27 , V_336 , V_337 ;
char * V_338 ;
char * V_339 ;
char * V_340 ;
char * V_341 ;
int V_342 , V_343 ;
int V_344 , V_345 , V_90 , V_346 , V_347 , V_348 ;
unsigned int V_92 ;
T_2 V_93 = 0 ;
V_15 V_25 ;
V_26 = F_4 ( V_3 , V_34 ) ;
V_27 = F_4 ( V_3 , V_33 ) ;
V_336 = V_3 -> V_75 ;
V_337 = F_4 ( V_3 , V_35 ) ;
F_163 ( V_335 , L_62 ,
V_3 -> V_349 , V_3 -> V_177 -> V_350 + 1 ,
V_3 -> V_351 ,
( V_27 & V_352 ) |
( V_27 & V_353 ) | ( V_27 &
V_354 ) ) ;
F_163 ( V_335 , L_63 ,
( F_4 ( V_3 , V_193 ) >> 8 ) & 0xFFFFFF ,
V_3 -> V_355 ) ;
F_163 ( V_335 , L_64 ,
V_3 -> V_184 , V_3 -> V_356 , ( unsigned long ) V_3 -> V_6 ) ;
F_163 ( V_335 , L_65 ) ;
F_163 ( V_335 ,
L_66 ,
V_26 & V_357 ,
( V_26 & V_191 ) ? 1 : 0 ,
( V_26 & V_197 ) ? 1 : 0 ,
V_3 -> V_358 ) ;
F_163 ( V_335 ,
L_67
L_68 ,
( ( V_26 & V_81 ) ? 1 : 0 ) ,
( V_26 & V_80 ) ,
( V_26 & V_80 ) %
( 2 * ( int ) V_3 -> V_78 ) ,
( ( V_26 & V_80 ) - 64 ) %
( 2 * ( int ) V_3 -> V_78 ) ,
( long ) F_24 ( V_3 ) * 4 ) ;
F_163 ( V_335 ,
L_69 ,
F_4 ( V_3 , V_189 ) & 0xFF ,
F_4 ( V_3 , V_195 ) & 0xFF ,
F_4 ( V_3 , V_187 ) & 0xFF ,
F_4 ( V_3 , V_193 ) & 0xFF ) ;
F_163 ( V_335 ,
L_70 ,
F_4 ( V_3 , V_180 ) & 0xFF ,
F_4 ( V_3 , V_182 ) & 0xFF ) ;
F_163 ( V_335 ,
L_71
L_72 ,
V_3 -> V_75 , V_3 -> V_359 ,
V_26 , V_27 ) ;
if ( V_26 & V_360 ) {
F_163 ( V_335 , L_73 ) ;
V_344 = F_4 ( V_3 , V_266 + 4 ) ;
if ( V_344 & V_269 ) {
F_163 ( V_335 , L_74 ) ;
switch ( V_344 & ( V_270 |
V_271 ) ) {
case 0 :
F_163 ( V_335 , L_75 ) ;
break;
case V_270 :
F_163 ( V_335 , L_76 ) ;
break;
case V_271 :
F_163 ( V_335 , L_77 ) ;
break;
default:
F_163 ( V_335 , L_78 ) ;
break;
}
if ( V_344 & V_297 ) {
F_163 ( V_335 , L_79 ) ;
} else {
F_163 ( V_335 , L_80 ) ;
}
} else {
F_163 ( V_335 , L_81 ) ;
}
if ( V_344 & V_267 ) {
F_163 ( V_335 , L_82 ) ;
} else if ( V_344 & V_268 ) {
F_163 ( V_335 , L_83 ) ;
} else {
F_163 ( V_335 , L_84 ) ;
}
if ( V_344 & V_292 ) {
F_163 ( V_335 , L_85 ) ;
} else {
F_163 ( V_335 , L_86 ) ;
}
switch ( V_3 -> V_31 ) {
case V_46 :
case V_32 :
V_93 = 110069313433624ULL ;
break;
case V_48 :
case V_47 :
V_93 = 104857600000000ULL ;
break;
case V_42 :
break;
}
V_92 = F_4 ( V_3 , V_215 ) ;
F_163 ( V_335 , L_87 , V_92 ) ;
V_25 = F_34 ( V_93 , V_92 ) ;
if ( V_336 & V_76 ) {
V_25 *= 4 ;
} else if ( V_336 & V_77 ) {
V_25 *= 2 ;
}
F_163 ( V_335 , L_88 ,
( unsigned int ) V_25 ) ;
V_345 = F_4 ( V_3 , V_266 ) ;
V_90 = V_345 & 0xF ;
V_345 >>= 4 ;
V_90 += ( V_345 & 0x3 ) * 10 ;
V_345 >>= 4 ;
V_346 = V_345 & 0xF ;
V_345 >>= 4 ;
V_346 += ( V_345 & 0x7 ) * 10 ;
V_345 >>= 4 ;
V_347 = V_345 & 0xF ;
V_345 >>= 4 ;
V_347 += ( V_345 & 0x7 ) * 10 ;
V_345 >>= 4 ;
V_348 = V_345 & 0xF ;
V_345 >>= 4 ;
V_348 += ( V_345 & 0x3 ) * 10 ;
F_163 ( V_335 ,
L_89 ,
V_348 , V_347 , V_346 , V_90 ) ;
} else {
F_163 ( V_335 , L_90 ) ;
}
F_163 ( V_335 , L_91 ) ;
V_342 = F_21 ( V_3 ) ;
F_163 ( V_335 ,
L_92 ,
V_342 , ( unsigned long ) V_3 -> V_78 ) ;
F_163 ( V_335 , L_93 ,
( V_3 -> V_75 & V_361 ) ? L_94 : L_95 ) ;
switch ( V_3 -> V_75 & V_362 ) {
case V_363 :
V_341 = L_96 ;
break;
case V_364 :
V_341 = L_97 ;
break;
default:
V_341 = L_98 ;
}
F_163 ( V_335 ,
L_99
L_100 ,
( V_3 -> V_75 & V_365 ) ? L_101 : L_95 ,
( V_3 -> V_75 & V_366 ) ? L_102 : L_103 ,
( V_3 -> V_75 & V_367 ) ? L_101 : L_95 ) ;
if ( ! ( V_3 -> V_75 & V_100 ) )
V_340 = L_13 ;
else
V_340 = L_12 ;
F_163 ( V_335 , L_104 , V_340 ) ;
switch ( F_87 ( V_3 ) ) {
case V_368 :
V_338 = L_24 ;
break;
case V_369 :
V_338 = L_105 ;
break;
case V_370 :
V_338 = L_26 ;
break;
case V_371 :
V_338 = L_27 ;
break;
default:
V_338 = L_106 ;
break;
}
F_163 ( V_335 , L_107 ,
V_338 ) ;
F_163 ( V_335 , L_108 ,
V_3 -> V_104 ) ;
F_163 ( V_335 , L_109 ) ;
V_342 = V_26 & V_284 ;
V_343 = V_27 & V_283 ;
F_163 ( V_335 , L_110 ,
( V_26 & V_43 ) ? ( V_342 ? L_43 : L_42 ) :
L_111 ,
( V_27 & V_49 ) ? ( V_343 ? L_43 : L_42 ) :
L_111 ) ;
switch ( F_17 ( V_3 ) ) {
case V_74 :
V_339 = L_27 ;
break;
case V_72 :
V_339 = L_26 ;
break;
case V_260 :
V_339 = L_24 ;
break;
case V_262 :
V_339 = L_105 ;
break;
case V_103 :
V_339 = L_112 ;
break;
default:
V_339 = L_113 ;
break;
}
F_163 ( V_335 ,
L_114 ,
V_339 , F_16 ( V_3 ) ,
( V_26 & V_60 ) >> 22 ,
( V_27 & V_51 ) >> 5 ) ;
F_163 ( V_335 , L_115 ,
( V_26 & V_372 ) ? L_116 : L_96 ,
( V_26 & V_373 ) ? L_117 :
L_118 ) ;
F_163 ( V_335 , L_119 ) ;
}
static void
F_164 ( struct V_332 * V_333 ,
struct V_334 * V_335 )
{
struct V_3 * V_3 = V_333 -> V_170 ;
unsigned int V_26 ;
unsigned int V_27 ;
unsigned int V_28 ;
unsigned int V_374 , V_375 ;
int V_376 ;
char * V_339 ;
int V_342 ;
V_26 = F_4 ( V_3 , V_34 ) ;
V_27 = F_4 ( V_3 , V_33 ) ;
V_28 = F_4 ( V_3 , V_35 ) ;
F_163 ( V_335 , L_120 ,
V_3 -> V_349 , V_3 -> V_177 -> V_350 + 1 ,
V_3 -> V_351 ) ;
F_163 ( V_335 , L_64 ,
V_3 -> V_184 , V_3 -> V_356 , ( unsigned long ) V_3 -> V_6 ) ;
F_163 ( V_335 , L_65 ) ;
F_163 ( V_335 ,
L_66 ,
V_26 & V_357 ,
( V_26 & V_191 ) ? 1 : 0 ,
( V_26 & V_197 ) ? 1 : 0 ,
V_3 -> V_358 ) ;
F_163 ( V_335 ,
L_67
L_68 ,
( ( V_26 & V_81 ) ? 1 : 0 ) ,
( V_26 & V_80 ) ,
( V_26 & V_80 ) %
( 2 * ( int ) V_3 -> V_78 ) ,
( ( V_26 & V_80 ) - 64 ) %
( 2 * ( int ) V_3 -> V_78 ) ,
( long ) F_24 ( V_3 ) * 4 ) ;
F_163 ( V_335 ,
L_69 ,
F_4 ( V_3 , V_189 ) & 0xFF ,
F_4 ( V_3 , V_195 ) & 0xFF ,
F_4 ( V_3 , V_187 ) & 0xFF ,
F_4 ( V_3 , V_193 ) & 0xFF ) ;
F_163 ( V_335 ,
L_70 ,
F_4 ( V_3 , V_180 ) & 0xFF ,
F_4 ( V_3 , V_182 ) & 0xFF ) ;
F_163 ( V_335 ,
L_71
L_72 ,
V_3 -> V_75 , V_3 -> V_359 ,
V_26 , V_27 ) ;
F_163 ( V_335 , L_91 ) ;
V_342 = F_21 ( V_3 ) ;
F_163 ( V_335 ,
L_92 ,
V_342 , ( unsigned long ) V_3 -> V_78 ) ;
F_163 ( V_335 , L_93 ,
( V_3 ->
V_75 & V_361 ) ? L_94 : L_95 ) ;
F_163 ( V_335 ,
L_121 ,
( V_3 ->
V_75 & V_365 ) ? L_101 : L_95 ,
( V_3 ->
V_75 & V_377 ) ? L_101 : L_95 ,
( V_3 ->
V_75 & V_378 ) ? L_101 : L_95 ) ;
V_376 = F_87 ( V_3 ) ;
if ( V_376 == 0 )
F_163 ( V_335 , L_122 ) ;
else
F_163 ( V_335 , L_123 ,
V_376 ) ;
F_163 ( V_335 , L_108 ,
V_3 -> V_104 ) ;
F_163 ( V_335 , L_124 ,
V_3 -> V_75 & V_275 ?
L_125 : L_126 ) ;
F_163 ( V_335 , L_127 ,
V_3 -> V_75 & V_277 ?
L_125 :
V_3 -> V_75 & V_278 ?
L_128 : L_126 ) ;
F_163 ( V_335 , L_109 ) ;
V_374 = V_26 & V_37 ;
V_375 = V_374 && ( V_26 & V_282 ) ;
F_163 ( V_335 , L_129 ,
( V_374 ) ? ( V_375 ? L_130 : L_131 ) : L_41 ,
F_1 ( ( V_26 >> V_38 ) & 0xF ) ) ;
for ( V_342 = 0 ; V_342 < 8 ; V_342 ++ ) {
F_163 ( V_335 , L_132 ,
V_342 + 1 ,
( V_27 & ( V_41 >> V_342 ) ) ?
L_130 : L_41 ,
F_1 ( ( V_28 >> ( 4 * V_342 ) ) & 0xF ) ) ;
}
switch ( F_17 ( V_3 ) ) {
case V_259 :
V_339 = L_23 ; break;
case V_36 :
V_339 = L_24 ; break;
case V_39 :
V_339 = L_15 ; break;
case V_379 :
V_339 = L_16 ; break;
case V_380 :
V_339 = L_17 ; break;
case V_381 :
V_339 = L_18 ; break;
case V_382 :
V_339 = L_19 ; break;
case V_383 :
V_339 = L_20 ; break;
case V_384 :
V_339 = L_21 ; break;
case V_40 :
V_339 = L_22 ; break;
default:
V_339 = L_113 ; break;
}
F_163 ( V_335 , L_133 , V_339 ) ;
F_163 ( V_335 , L_119 ) ;
}
static void
F_165 ( struct V_332 * V_333 ,
struct V_334 * V_335 )
{
struct V_3 * V_3 = V_333 -> V_170 ;
unsigned int V_385 , V_27 , V_386 , V_336 , V_16 ;
unsigned int V_22 , V_285 ;
V_385 = F_4 ( V_3 , V_230 ) ;
V_27 = F_4 ( V_3 , V_232 ) ;
V_386 = F_4 ( V_3 , V_286 ) ;
V_336 = V_3 -> V_75 ;
F_163 ( V_335 , L_134 , V_385 ) ;
F_163 ( V_335 , L_135 , V_27 ) ;
F_163 ( V_335 , L_136 , V_386 ) ;
F_163 ( V_335 , L_137 ) ;
F_163 ( V_335 , L_138 ,
( F_66 ( V_3 ) == 0 ) ? L_139 : L_140 ) ;
F_163 ( V_335 , L_141 ,
F_65 ( V_3 ) ) ;
F_163 ( V_335 , L_142 ) ;
V_22 = 0x1 ;
V_285 = 0x100 ;
for ( V_16 = 0 ; V_16 < 8 ; V_16 ++ ) {
F_163 ( V_335 , L_143 ,
V_16 ,
( V_385 & V_22 ) ? 1 : 0 ,
( V_385 & V_285 ) ? 1 : 0 ,
V_234 [ ( V_27 >> ( V_16 * 4 ) ) & 0xF ] ) ;
V_22 = V_22 << 1 ;
V_285 = V_285 << 1 ;
}
F_163 ( V_335 , L_144 ,
( V_385 & 0x1000000 ) ? 1 : 0 ,
( V_385 & 0x2000000 ) ? 1 : 0 ,
V_234 [ ( V_385 >> 16 ) & 0xF ] ) ;
F_163 ( V_335 , L_145 ,
( V_385 & 0x4000000 ) ? 1 : 0 ,
( V_385 & 0x8000000 ) ? 1 : 0 ,
V_234 [ ( V_385 >> 20 ) & 0xF ] ) ;
F_163 ( V_335 , L_146 ,
( V_386 & 0x400 ) ? 1 : 0 ,
( V_386 & 0x800 ) ? 1 : 0 ,
V_234 [ ( V_27 >> 12 ) & 0xF ] ) ;
}
static void
F_166 ( struct V_332 * V_333 ,
struct V_334 * V_335 )
{
struct V_3 * V_3 = V_333 -> V_170 ;
int V_148 , V_16 ;
for ( V_16 = 0 ; V_16 < 256 ; V_16 += V_148 ) {
F_163 ( V_335 , L_147 , V_16 ) ;
for ( V_148 = 0 ; V_148 < 16 ; V_148 += 4 )
F_163 ( V_335 , L_148 , F_4 ( V_3 , V_16 + V_148 ) ) ;
F_163 ( V_335 , L_119 ) ;
}
}
static void F_167 ( struct V_332 * V_333 ,
struct V_334 * V_335 )
{
struct V_3 * V_3 = V_333 -> V_170 ;
int V_16 ;
F_163 ( V_335 , L_149 ) ;
for ( V_16 = 0 ; V_16 < V_3 -> V_127 ; V_16 ++ ) {
F_163 ( V_335 , L_150 , V_16 + 1 , V_3 -> V_131 [ V_16 ] ) ;
}
}
static void F_168 ( struct V_332 * V_333 ,
struct V_334 * V_335 )
{
struct V_3 * V_3 = V_333 -> V_170 ;
int V_16 ;
F_163 ( V_335 , L_149 ) ;
for ( V_16 = 0 ; V_16 < V_3 -> V_129 ; V_16 ++ ) {
F_163 ( V_335 , L_150 , V_16 + 1 , V_3 -> V_133 [ V_16 ] ) ;
}
}
static void F_169 ( struct V_3 * V_3 )
{
struct V_332 * V_333 ;
if ( ! F_170 ( V_3 -> V_177 , L_151 , & V_333 ) ) {
switch ( V_3 -> V_31 ) {
case V_32 :
F_171 ( V_333 , V_3 ,
F_164 ) ;
break;
case V_46 :
F_171 ( V_333 , V_3 ,
F_162 ) ;
break;
case V_42 :
break;
case V_48 :
F_171 ( V_333 , V_3 ,
F_165 ) ;
break;
case V_47 :
break;
}
}
if ( ! F_170 ( V_3 -> V_177 , L_152 , & V_333 ) ) {
F_171 ( V_333 , V_3 , F_167 ) ;
}
if ( ! F_170 ( V_3 -> V_177 , L_153 , & V_333 ) ) {
F_171 ( V_333 , V_3 , F_168 ) ;
}
#ifdef F_172
if ( ! F_170 ( V_3 -> V_177 , L_154 , & V_333 ) )
F_171 ( V_333 , V_3 ,
F_166 ) ;
#endif
}
static int F_173 ( struct V_3 * V_3 )
{
V_3 -> V_238 = 0 ;
switch ( V_3 -> V_31 ) {
case V_46 :
case V_42 :
V_3 -> V_75 =
0x2 + 0x8 + 0x10 + 0x80 + 0x400 + 0x4000 + 0x1000000 ;
break;
case V_48 :
case V_47 :
V_3 -> V_238 = 0x1 + 0x1000 ;
V_3 -> V_75 =
0x2 + 0x8 + 0x10 + 0x80 + 0x400 + 0x4000 + 0x1000000 ;
break;
case V_32 :
V_3 -> V_75 =
V_100 |
F_30 ( 7 ) |
V_247 |
V_361 |
V_387 ;
break;
}
F_2 ( V_3 , V_85 , V_3 -> V_75 ) ;
if ( V_32 == V_3 -> V_31 ) {
#ifdef F_174
V_3 -> V_359 = V_388 ;
#else
V_3 -> V_359 = 0 ;
#endif
F_2 ( V_3 , V_389 , V_3 -> V_359 ) ;
}
F_23 ( V_3 ) ;
F_39 ( V_3 , 0 * V_150 ) ;
if ( V_3 -> V_31 == V_47 || V_3 -> V_31 == V_48 ) {
F_2 ( V_3 , V_241 , V_3 -> V_238 ) ;
}
F_37 ( V_3 , 48000 , 1 ) ;
return 0 ;
}
static T_3 F_175 ( int V_184 , void * V_390 )
{
struct V_3 * V_3 = (struct V_3 * ) V_390 ;
unsigned int V_26 ;
int V_16 , V_391 , V_152 , V_392 = 0 ;
V_26 = F_4 ( V_3 , V_34 ) ;
V_391 = V_26 & V_357 ;
V_152 = V_26 & ( V_191 | V_197 |
V_185 | V_202 ) ;
if ( ! V_391 && ! V_152 )
return V_393 ;
F_2 ( V_3 , V_394 , 0 ) ;
V_3 -> V_358 ++ ;
if ( V_391 ) {
if ( V_3 -> V_395 )
F_176 ( V_3 -> V_395 ) ;
if ( V_3 -> V_396 )
F_176 ( V_3 -> V_396 ) ;
}
if ( V_152 ) {
V_16 = 0 ;
while ( V_16 < V_3 -> V_214 ) {
if ( ( F_4 ( V_3 ,
V_3 -> V_152 [ V_16 ] . V_155 ) & 0xff ) &&
( V_26 & V_3 -> V_152 [ V_16 ] . V_184 ) ) {
V_3 -> V_75 &= ~ V_3 -> V_152 [ V_16 ] . V_165 ;
F_2 ( V_3 , V_85 ,
V_3 -> V_75 ) ;
V_3 -> V_152 [ V_16 ] . V_164 = 1 ;
V_392 = 1 ;
}
V_16 ++ ;
}
if ( V_392 )
F_177 ( & V_3 -> V_397 ) ;
}
return V_398 ;
}
static T_1 F_178 ( struct V_399
* V_167 )
{
struct V_3 * V_3 = F_179 ( V_167 ) ;
return F_24 ( V_3 ) ;
}
static int F_180 ( struct V_399 * V_167 )
{
struct V_400 * V_401 = V_167 -> V_401 ;
struct V_3 * V_3 = F_179 ( V_167 ) ;
struct V_399 * V_402 ;
if ( V_167 -> V_403 == V_404 )
V_402 = V_3 -> V_395 ;
else
V_402 = V_3 -> V_396 ;
if ( V_3 -> V_405 )
V_401 -> V_26 -> V_406 = F_24 ( V_3 ) ;
else
V_401 -> V_26 -> V_406 = 0 ;
if ( V_402 ) {
struct V_399 * V_82 ;
struct V_400 * V_407 = V_402 -> V_401 ;
F_181 (s, substream) {
if ( V_82 == V_402 ) {
V_407 -> V_26 -> V_406 =
V_401 -> V_26 -> V_406 ;
break;
}
}
}
return 0 ;
}
static int F_182 ( struct V_399 * V_167 ,
struct V_408 * V_409 )
{
struct V_3 * V_3 = F_179 ( V_167 ) ;
int V_178 ;
int V_16 ;
T_4 V_410 ;
T_4 V_411 ;
F_29 ( & V_3 -> V_22 ) ;
if ( V_167 -> V_412 -> V_403 == V_404 ) {
V_410 = V_3 -> V_23 ;
V_411 = V_3 -> V_24 ;
} else {
V_410 = V_3 -> V_24 ;
V_411 = V_3 -> V_23 ;
}
if ( V_411 > 0 && V_410 != V_411 ) {
if ( F_183 ( V_409 ) != V_3 -> V_104 ) {
F_31 ( & V_3 -> V_22 ) ;
F_184 ( V_409 ,
V_413 ) ;
return - V_120 ;
}
if ( F_185 ( V_409 ) != V_3 -> V_78 / 4 ) {
F_31 ( & V_3 -> V_22 ) ;
F_184 ( V_409 ,
V_414 ) ;
return - V_120 ;
}
}
F_31 ( & V_3 -> V_22 ) ;
F_29 ( & V_3 -> V_22 ) ;
V_178 = F_37 ( V_3 , F_183 ( V_409 ) , 0 ) ;
if ( V_178 < 0 ) {
F_38 ( V_415 L_155 , V_178 ) ;
F_31 ( & V_3 -> V_22 ) ;
F_184 ( V_409 ,
V_413 ) ;
return V_178 ;
}
F_31 ( & V_3 -> V_22 ) ;
V_178 = F_28 ( V_3 ,
F_185 ( V_409 ) ) ;
if ( V_178 < 0 ) {
F_38 ( V_415 L_156 , V_178 ) ;
F_184 ( V_409 ,
V_414 ) ;
return V_178 ;
}
V_178 =
F_186 ( V_167 , V_416 ) ;
if ( V_178 < 0 ) {
F_38 ( V_415 L_157 , V_178 ) ;
return V_178 ;
}
if ( V_167 -> V_403 == V_404 ) {
F_187 ( V_3 , V_167 , V_417 ,
F_188 ( V_409 ) ) ;
for ( V_16 = 0 ; V_16 < F_188 ( V_409 ) ; ++ V_16 )
F_11 ( V_3 , V_16 , 1 ) ;
V_3 -> V_87 =
( unsigned char * ) V_167 -> V_401 -> V_418 ;
F_189 ( L_158 ,
V_3 -> V_87 ) ;
} else {
F_187 ( V_3 , V_167 , V_419 ,
F_188 ( V_409 ) ) ;
for ( V_16 = 0 ; V_16 < F_188 ( V_409 ) ; ++ V_16 )
F_10 ( V_3 , V_16 , 1 ) ;
V_3 -> V_420 =
( unsigned char * ) V_167 -> V_401 -> V_418 ;
F_189 ( L_159 ,
V_3 -> V_420 ) ;
}
if ( V_421 == F_190 ( V_409 ) ) {
if ( ! ( V_3 -> V_75 & V_422 ) )
F_38 ( V_415 L_160 ) ;
V_3 -> V_75 |= V_422 ;
} else if ( V_423 == F_190 ( V_409 ) ) {
if ( V_3 -> V_75 & V_422 )
F_38 ( V_415 L_161 ) ;
V_3 -> V_75 &= ~ V_422 ;
}
F_2 ( V_3 , V_85 , V_3 -> V_75 ) ;
return 0 ;
}
static int F_191 ( struct V_399 * V_167 )
{
int V_16 ;
struct V_3 * V_3 = F_179 ( V_167 ) ;
if ( V_167 -> V_403 == V_404 ) {
for ( V_16 = 0 ; V_16 < V_3 -> V_129 ; ++ V_16 )
F_11 ( V_3 , V_16 , 0 ) ;
V_3 -> V_87 = NULL ;
} else {
for ( V_16 = 0 ; V_16 < V_3 -> V_127 ; ++ V_16 )
F_10 ( V_3 , V_16 , 0 ) ;
V_3 -> V_420 = NULL ;
}
F_192 ( V_167 ) ;
return 0 ;
}
static int F_193 ( struct V_399 * V_167 ,
struct V_424 * V_425 )
{
struct V_3 * V_3 = F_179 ( V_167 ) ;
if ( V_167 -> V_403 == V_404 ) {
if ( F_36 ( V_425 -> V_281 >= V_3 -> V_129 ) ) {
F_38 ( V_415 L_162 , V_425 -> V_281 ) ;
return - V_117 ;
}
if ( V_3 -> V_125 [ V_425 -> V_281 ] < 0 ) {
F_38 ( V_415 L_163 , V_425 -> V_281 ) ;
return - V_117 ;
}
V_425 -> V_426 = V_3 -> V_125 [ V_425 -> V_281 ] *
V_89 ;
} else {
if ( F_36 ( V_425 -> V_281 >= V_3 -> V_127 ) ) {
F_38 ( V_415 L_164 , V_425 -> V_281 ) ;
return - V_117 ;
}
if ( V_3 -> V_123 [ V_425 -> V_281 ] < 0 ) {
F_38 ( V_415 L_165 , V_425 -> V_281 ) ;
return - V_117 ;
}
V_425 -> V_426 = V_3 -> V_123 [ V_425 -> V_281 ] *
V_89 ;
}
V_425 -> V_427 = 0 ;
V_425 -> V_225 = 32 ;
return 0 ;
}
static int F_194 ( struct V_399 * V_167 ,
unsigned int V_428 , void * V_213 )
{
switch ( V_428 ) {
case V_429 :
return F_180 ( V_167 ) ;
case V_430 :
{
struct V_424 * V_425 = V_213 ;
return F_193 ( V_167 , V_425 ) ;
}
default:
break;
}
return F_195 ( V_167 , V_428 , V_213 ) ;
}
static int F_196 ( struct V_399 * V_167 , int V_428 )
{
struct V_3 * V_3 = F_179 ( V_167 ) ;
struct V_399 * V_402 ;
int V_405 ;
F_197 ( & V_3 -> V_22 ) ;
V_405 = V_3 -> V_405 ;
switch ( V_428 ) {
case V_431 :
V_405 |= 1 << V_167 -> V_403 ;
break;
case V_432 :
V_405 &= ~ ( 1 << V_167 -> V_403 ) ;
break;
default:
F_33 () ;
F_198 ( & V_3 -> V_22 ) ;
return - V_117 ;
}
if ( V_167 -> V_403 == V_404 )
V_402 = V_3 -> V_395 ;
else
V_402 = V_3 -> V_396 ;
if ( V_402 ) {
struct V_399 * V_82 ;
F_181 (s, substream) {
if ( V_82 == V_402 ) {
F_199 ( V_82 , V_167 ) ;
if ( V_428 == V_431 )
V_405 |= 1 << V_82 -> V_403 ;
else
V_405 &= ~ ( 1 << V_82 -> V_403 ) ;
goto V_433;
}
}
if ( V_428 == V_431 ) {
if ( ! ( V_405 & ( 1 << V_404 ) )
&& V_167 -> V_403 ==
V_434 )
F_27 ( V_3 ) ;
} else {
if ( V_405 &&
V_167 -> V_403 == V_404 )
F_27 ( V_3 ) ;
}
} else {
if ( V_167 -> V_403 == V_434 )
F_27 ( V_3 ) ;
}
V_433:
F_199 ( V_167 , V_167 ) ;
if ( ! V_3 -> V_405 && V_405 )
F_25 ( V_3 ) ;
else if ( V_3 -> V_405 && ! V_405 )
F_26 ( V_3 ) ;
V_3 -> V_405 = V_405 ;
F_198 ( & V_3 -> V_22 ) ;
return 0 ;
}
static int F_200 ( struct V_399 * V_167 )
{
return 0 ;
}
static int F_201 ( struct V_408 * V_409 ,
struct V_435 * V_436 )
{
struct V_3 * V_3 = V_436 -> V_437 ;
struct V_438 * V_439 =
F_202 ( V_409 , V_440 ) ;
struct V_438 * V_441 =
F_202 ( V_409 , V_413 ) ;
if ( V_441 -> V_223 > 96000 && V_441 -> V_224 <= 192000 ) {
struct V_438 V_442 = {
. V_223 = V_3 -> V_143 ,
. V_224 = V_3 -> V_143 ,
. integer = 1 ,
} ;
return F_203 ( V_439 , & V_442 ) ;
} else if ( V_441 -> V_223 > 48000 && V_441 -> V_224 <= 96000 ) {
struct V_438 V_442 = {
. V_223 = V_3 -> V_137 ,
. V_224 = V_3 -> V_137 ,
. integer = 1 ,
} ;
return F_203 ( V_439 , & V_442 ) ;
} else if ( V_441 -> V_224 < 64000 ) {
struct V_438 V_442 = {
. V_223 = V_3 -> V_128 ,
. V_224 = V_3 -> V_128 ,
. integer = 1 ,
} ;
return F_203 ( V_439 , & V_442 ) ;
}
return 0 ;
}
static int F_204 ( struct V_408 * V_409 ,
struct V_435 * V_436 )
{
struct V_3 * V_3 = V_436 -> V_437 ;
struct V_438 * V_439 =
F_202 ( V_409 , V_440 ) ;
struct V_438 * V_441 =
F_202 ( V_409 , V_413 ) ;
if ( V_441 -> V_223 > 96000 && V_441 -> V_224 <= 192000 ) {
struct V_438 V_442 = {
. V_223 = V_3 -> V_144 ,
. V_224 = V_3 -> V_144 ,
. integer = 1 ,
} ;
return F_203 ( V_439 , & V_442 ) ;
} else if ( V_441 -> V_223 > 48000 && V_441 -> V_224 <= 96000 ) {
struct V_438 V_442 = {
. V_223 = V_3 -> V_138 ,
. V_224 = V_3 -> V_138 ,
. integer = 1 ,
} ;
return F_203 ( V_439 , & V_442 ) ;
} else if ( V_441 -> V_224 < 64000 ) {
struct V_438 V_442 = {
. V_223 = V_3 -> V_130 ,
. V_224 = V_3 -> V_130 ,
. integer = 1 ,
} ;
return F_203 ( V_439 , & V_442 ) ;
} else {
}
return 0 ;
}
static int F_205 ( struct V_408 * V_409 ,
struct V_435 * V_436 )
{
struct V_3 * V_3 = V_436 -> V_437 ;
struct V_438 * V_439 =
F_202 ( V_409 , V_440 ) ;
struct V_438 * V_441 =
F_202 ( V_409 , V_413 ) ;
if ( V_439 -> V_223 >= V_3 -> V_128 ) {
struct V_438 V_442 = {
. V_223 = 32000 ,
. V_224 = 48000 ,
. integer = 1 ,
} ;
return F_203 ( V_441 , & V_442 ) ;
} else if ( V_439 -> V_224 <= V_3 -> V_143 ) {
struct V_438 V_442 = {
. V_223 = 128000 ,
. V_224 = 192000 ,
. integer = 1 ,
} ;
return F_203 ( V_441 , & V_442 ) ;
} else if ( V_439 -> V_224 <= V_3 -> V_137 ) {
struct V_438 V_442 = {
. V_223 = 64000 ,
. V_224 = 96000 ,
. integer = 1 ,
} ;
return F_203 ( V_441 , & V_442 ) ;
}
return 0 ;
}
static int F_206 ( struct V_408 * V_409 ,
struct V_435 * V_436 )
{
struct V_3 * V_3 = V_436 -> V_437 ;
struct V_438 * V_439 =
F_202 ( V_409 , V_440 ) ;
struct V_438 * V_441 =
F_202 ( V_409 , V_413 ) ;
if ( V_439 -> V_223 >= V_3 -> V_130 ) {
struct V_438 V_442 = {
. V_223 = 32000 ,
. V_224 = 48000 ,
. integer = 1 ,
} ;
return F_203 ( V_441 , & V_442 ) ;
} else if ( V_439 -> V_224 <= V_3 -> V_144 ) {
struct V_438 V_442 = {
. V_223 = 128000 ,
. V_224 = 192000 ,
. integer = 1 ,
} ;
return F_203 ( V_441 , & V_442 ) ;
} else if ( V_439 -> V_224 <= V_3 -> V_138 ) {
struct V_438 V_442 = {
. V_223 = 64000 ,
. V_224 = 96000 ,
. integer = 1 ,
} ;
return F_203 ( V_441 , & V_442 ) ;
}
return 0 ;
}
static int F_207 ( struct V_408 * V_409 ,
struct V_435 * V_436 )
{
unsigned int V_324 [ 3 ] ;
struct V_3 * V_3 = V_436 -> V_437 ;
struct V_438 * V_439 = F_202 ( V_409 ,
V_440 ) ;
V_324 [ 0 ] = V_3 -> V_143 ;
V_324 [ 1 ] = V_3 -> V_137 ;
V_324 [ 2 ] = V_3 -> V_128 ;
return F_208 ( V_439 , 3 , V_324 , 0 ) ;
}
static int F_209 ( struct V_408 * V_409 ,
struct V_435 * V_436 )
{
unsigned int V_324 [ 3 ] ;
struct V_3 * V_3 = V_436 -> V_437 ;
struct V_438 * V_439 = F_202 ( V_409 ,
V_440 ) ;
V_324 [ 0 ] = V_3 -> V_144 ;
V_324 [ 1 ] = V_3 -> V_138 ;
V_324 [ 2 ] = V_3 -> V_130 ;
return F_208 ( V_439 , 3 , V_324 , 0 ) ;
}
static int F_210 ( struct V_399 * V_167 )
{
struct V_3 * V_3 = F_179 ( V_167 ) ;
struct V_400 * V_401 = V_167 -> V_401 ;
F_29 ( & V_3 -> V_22 ) ;
F_211 ( V_167 ) ;
V_401 -> V_443 = V_444 ;
if ( V_3 -> V_395 == NULL )
F_26 ( V_3 ) ;
V_3 -> V_23 = V_445 -> V_446 ;
V_3 -> V_396 = V_167 ;
F_31 ( & V_3 -> V_22 ) ;
F_212 ( V_401 , 0 , 32 , 24 ) ;
F_213 ( V_401 , 0 , V_414 ) ;
switch ( V_3 -> V_31 ) {
case V_47 :
case V_48 :
F_214 ( V_401 ,
V_414 ,
32 , 4096 ) ;
F_214 ( V_401 ,
V_447 ,
16384 , 16384 ) ;
break;
default:
F_214 ( V_401 ,
V_414 ,
64 , 8192 ) ;
break;
}
if ( V_32 == V_3 -> V_31 ) {
V_401 -> V_443 . V_448 |= V_449 ;
F_215 ( V_401 , 0 , V_413 ,
& V_450 ) ;
} else {
F_216 ( V_401 , 0 , V_413 ,
F_206 , V_3 ,
V_440 , - 1 ) ;
}
F_216 ( V_401 , 0 , V_440 ,
F_209 , V_3 ,
V_440 , - 1 ) ;
F_216 ( V_401 , 0 , V_440 ,
F_204 , V_3 ,
V_413 , - 1 ) ;
return 0 ;
}
static int F_217 ( struct V_399 * V_167 )
{
struct V_3 * V_3 = F_179 ( V_167 ) ;
F_29 ( & V_3 -> V_22 ) ;
V_3 -> V_23 = - 1 ;
V_3 -> V_396 = NULL ;
F_31 ( & V_3 -> V_22 ) ;
return 0 ;
}
static int F_218 ( struct V_399 * V_167 )
{
struct V_3 * V_3 = F_179 ( V_167 ) ;
struct V_400 * V_401 = V_167 -> V_401 ;
F_29 ( & V_3 -> V_22 ) ;
F_211 ( V_167 ) ;
V_401 -> V_443 = V_451 ;
if ( V_3 -> V_396 == NULL )
F_26 ( V_3 ) ;
V_3 -> V_24 = V_445 -> V_446 ;
V_3 -> V_395 = V_167 ;
F_31 ( & V_3 -> V_22 ) ;
F_212 ( V_401 , 0 , 32 , 24 ) ;
F_213 ( V_401 , 0 , V_414 ) ;
switch ( V_3 -> V_31 ) {
case V_47 :
case V_48 :
F_214 ( V_401 ,
V_414 ,
32 , 4096 ) ;
F_214 ( V_401 ,
V_447 ,
16384 , 16384 ) ;
break;
default:
F_214 ( V_401 ,
V_414 ,
64 , 8192 ) ;
break;
}
if ( V_32 == V_3 -> V_31 ) {
V_401 -> V_443 . V_448 |= V_449 ;
F_215 ( V_401 , 0 , V_413 ,
& V_450 ) ;
} else {
F_216 ( V_401 , 0 , V_413 ,
F_205 , V_3 ,
V_440 , - 1 ) ;
}
F_216 ( V_401 , 0 , V_440 ,
F_207 , V_3 ,
V_440 , - 1 ) ;
F_216 ( V_401 , 0 , V_440 ,
F_201 , V_3 ,
V_413 , - 1 ) ;
return 0 ;
}
static int F_219 ( struct V_399 * V_167 )
{
struct V_3 * V_3 = F_179 ( V_167 ) ;
F_29 ( & V_3 -> V_22 ) ;
V_3 -> V_24 = - 1 ;
V_3 -> V_395 = NULL ;
F_31 ( & V_3 -> V_22 ) ;
return 0 ;
}
static int F_220 ( struct V_452 * V_443 , struct V_453 * V_453 )
{
return 0 ;
}
static inline int F_221 ( void T_5 * V_454 , void T_6 * V_455 )
{
V_15 V_5 = F_5 ( V_455 ) ;
return F_222 ( V_454 , & V_5 , 4 ) ;
}
static int F_223 ( struct V_452 * V_443 , struct V_453 * V_453 ,
unsigned int V_428 , unsigned long V_213 )
{
void T_5 * V_456 = ( void T_5 * ) V_213 ;
struct V_3 * V_3 = V_443 -> V_170 ;
struct V_457 V_10 ;
struct V_458 V_425 ;
struct V_459 V_26 ;
struct V_460 V_460 ;
struct V_461 * V_462 ;
struct V_463 V_345 ;
unsigned int V_464 ;
long unsigned int V_82 ;
int V_16 = 0 ;
switch ( V_428 ) {
case V_465 :
V_462 = & V_3 -> V_466 ;
for ( V_16 = 0 ; V_16 < V_88 ; V_16 ++ ) {
V_462 -> V_467 [ V_16 ] =
F_5 ( V_3 -> V_6 +
V_468 + V_16 * 4 ) ;
V_462 -> V_469 [ V_16 ] =
F_5 ( V_3 -> V_6 +
V_470 + V_16 * 4 ) ;
V_462 -> V_471 [ V_16 ] =
F_5 ( V_3 -> V_6 +
V_472 + V_16 * 4 ) ;
V_462 -> V_473 [ V_16 ] =
( ( V_474 ) F_5 ( V_3 -> V_6 +
V_475 + V_16 * 4 ) << 32 ) |
( V_474 ) F_5 ( V_3 -> V_6 +
V_476 + V_16 * 4 ) ;
V_462 -> V_477 [ V_16 ] =
( ( V_474 ) F_5 ( V_3 -> V_6 +
V_478 + V_16 * 4 ) << 32 ) |
( V_474 ) F_5 ( V_3 -> V_6 +
V_479 + V_16 * 4 ) ;
V_462 -> V_480 [ V_16 ] =
( ( V_474 ) F_5 ( V_3 -> V_6 +
V_481 + V_16 * 4 ) << 32 ) |
( V_474 ) F_5 ( V_3 -> V_6 +
V_482 + V_16 * 4 ) ;
}
if ( V_3 -> V_104 > 96000 ) {
V_462 -> V_483 = V_484 ;
} else if ( V_3 -> V_104 > 48000 ) {
V_462 -> V_483 = V_276 ;
} else {
V_462 -> V_483 = V_485 ;
}
V_462 -> V_27 = F_4 ( V_3 , V_33 ) ;
V_82 = F_222 ( V_456 , V_462 , sizeof( struct V_461 ) ) ;
if ( 0 != V_82 ) {
return - V_486 ;
}
break;
case V_487 :
V_345 . V_345 = F_4 ( V_3 , V_266 ) ;
V_16 = F_4 ( V_3 , V_266 + 4 ) ;
if ( V_16 & V_269 ) {
switch ( V_16 & ( V_270 |
V_271 ) ) {
case 0 :
V_345 . V_488 = V_489 ;
break;
case V_270 :
V_345 . V_488 = V_490 ;
break;
case V_271 :
V_345 . V_488 = V_491 ;
break;
default:
V_345 . V_488 = 30 ;
break;
}
if ( V_16 & V_297 ) {
V_345 . V_492 = V_493 ;
} else {
V_345 . V_492 = V_494 ;
}
} else {
V_345 . V_488 = V_495 ;
V_345 . V_492 = V_496 ;
}
if ( V_16 & V_267 ) {
V_345 . V_497 = V_498 ;
} else if ( V_16 & V_268 ) {
V_345 . V_497 = V_499 ;
} else {
V_345 . V_497 = V_500 ;
}
V_82 = F_222 ( V_456 , & V_345 , sizeof( struct V_463 ) ) ;
if ( 0 != V_82 ) {
return - V_486 ;
}
break;
case V_501 :
memset ( & V_425 , 0 , sizeof( V_425 ) ) ;
F_29 ( & V_3 -> V_22 ) ;
V_425 . V_338 = F_87 ( V_3 ) ;
V_425 . V_502 = F_131 ( V_3 ) ;
V_425 . V_104 = V_3 -> V_104 ;
V_425 . V_503 =
F_16 ( V_3 ) ;
V_425 . V_340 = F_66 ( V_3 ) ;
V_425 . V_504 = F_82 ( V_3 ) ;
V_425 . V_339 = F_17 ( V_3 ) ;
V_425 . V_505 = F_99 ( V_3 , V_361 ) ;
V_425 . V_506 = 0 ;
F_31 ( & V_3 -> V_22 ) ;
if ( F_222 ( V_456 , & V_425 , sizeof( V_425 ) ) )
return - V_486 ;
break;
case V_507 :
memset ( & V_26 , 0 , sizeof( V_26 ) ) ;
V_26 . V_508 = V_3 -> V_31 ;
V_26 . V_509 = F_17 ( V_3 ) ;
V_26 . V_510 = 110069313433624ULL ;
V_26 . V_511 = F_4 ( V_3 , V_215 ) ;
switch ( V_3 -> V_31 ) {
case V_46 :
case V_42 :
V_26 . V_512 . V_513 . V_514 =
F_131 ( V_3 ) ;
V_26 . V_512 . V_513 . V_515 =
F_132 ( V_3 ) ;
V_26 . V_512 . V_513 . V_516 =
F_18 ( V_3 ) ;
V_26 . V_512 . V_513 . V_517 =
F_19 ( V_3 ) ;
V_464 =
F_4 ( V_3 , V_34 ) ;
V_26 . V_512 . V_513 . V_518 =
( V_464 & V_372 ) ? 1 : 0 ;
V_26 . V_512 . V_513 . V_519 =
( V_464 & V_373 ) ? 1 : 0 ;
V_26 . V_512 . V_513 . V_520 = 0 ;
default:
break;
}
if ( F_222 ( V_456 , & V_26 , sizeof( V_26 ) ) )
return - V_486 ;
break;
case V_521 :
memset ( & V_460 , 0 , sizeof( V_460 ) ) ;
V_460 . V_508 = V_3 -> V_31 ;
strncpy ( V_460 . V_522 , V_3 -> V_349 ,
sizeof( V_460 . V_522 ) ) ;
V_460 . V_355 = V_3 -> V_355 ;
V_460 . V_351 = V_3 -> V_351 ;
V_460 . V_523 = 0 ;
if ( V_3 -> V_231 )
V_460 . V_523 |= V_524 ;
if ( F_222 ( V_456 , & V_460 ,
sizeof( V_460 ) ) )
return - V_486 ;
break;
case V_525 :
if ( F_224 ( & V_10 , V_456 , sizeof( V_10 ) ) )
return - V_486 ;
if ( F_222 ( ( void T_5 * ) V_10 . V_10 , V_3 -> V_10 ,
sizeof( struct V_526 ) ) )
return - V_486 ;
break;
default:
return - V_117 ;
}
return 0 ;
}
static int F_225 ( struct V_176 * V_177 ,
struct V_3 * V_3 )
{
struct V_452 * V_443 ;
int V_178 ;
V_178 = F_226 ( V_177 , L_166 , 0 , & V_443 ) ;
if ( V_178 < 0 )
return V_178 ;
V_3 -> V_527 = V_443 ;
V_443 -> V_170 = V_3 ;
strcpy ( V_443 -> V_204 , L_167 ) ;
V_443 -> V_528 . V_529 = F_220 ;
V_443 -> V_528 . V_530 = F_223 ;
V_443 -> V_528 . V_531 = F_223 ;
V_443 -> V_528 . V_532 = F_220 ;
return 0 ;
}
static int F_227 ( struct V_3 * V_3 )
{
int V_178 ;
struct V_533 * V_534 ;
T_7 V_535 ;
V_534 = V_3 -> V_534 ;
V_535 = V_416 ;
V_178 =
F_228 ( V_534 ,
V_536 ,
F_229 ( V_3 -> V_537 ) ,
V_535 ,
V_535 ) ;
if ( V_178 < 0 ) {
F_189 ( L_168 , V_535 ) ;
return V_178 ;
} else
F_189 ( L_169 , V_535 ) ;
return 0 ;
}
static void F_187 ( struct V_3 * V_3 ,
struct V_399 * V_167 ,
unsigned int V_4 , int V_538 )
{
int V_16 ;
for ( V_16 = 0 ; V_16 < ( V_538 * 16 ) ; V_16 ++ )
F_2 ( V_3 , V_4 + 4 * V_16 ,
F_230 ( V_167 , 4096 * V_16 ) ) ;
}
static int F_231 ( struct V_176 * V_177 ,
struct V_3 * V_3 )
{
struct V_533 * V_534 ;
int V_178 ;
V_178 = F_232 ( V_177 , V_3 -> V_349 , 0 , 1 , 1 , & V_534 ) ;
if ( V_178 < 0 )
return V_178 ;
V_3 -> V_534 = V_534 ;
V_534 -> V_170 = V_3 ;
strcpy ( V_534 -> V_204 , V_3 -> V_349 ) ;
F_233 ( V_534 , V_404 ,
& V_539 ) ;
F_233 ( V_534 , V_434 ,
& V_540 ) ;
V_534 -> V_209 = V_541 ;
V_178 = F_227 ( V_3 ) ;
if ( V_178 < 0 )
return V_178 ;
return 0 ;
}
static inline void F_234 ( struct V_3 * V_3 )
{
int V_16 ;
for ( V_16 = 0 ; V_16 < V_3 -> V_214 ; V_16 ++ )
F_44 ( V_3 , V_16 ) ;
}
static int F_235 ( struct V_176 * V_177 ,
struct V_3 * V_3 )
{
int V_178 , V_16 ;
F_189 ( L_170 ) ;
V_178 = F_231 ( V_177 , V_3 ) ;
if ( V_178 < 0 )
return V_178 ;
V_16 = 0 ;
while ( V_16 < V_3 -> V_214 ) {
V_178 = F_60 ( V_177 , V_3 , V_16 ) ;
if ( V_178 < 0 ) {
return V_178 ;
}
V_16 ++ ;
}
V_178 = F_158 ( V_177 , V_3 ) ;
if ( V_178 < 0 )
return V_178 ;
V_178 = F_225 ( V_177 , V_3 ) ;
if ( V_178 < 0 )
return V_178 ;
F_189 ( L_171 ) ;
F_169 ( V_3 ) ;
V_3 -> V_104 = - 1 ;
V_3 -> V_542 = - 1 ;
V_3 -> V_543 = - 1 ;
V_3 -> V_23 = - 1 ;
V_3 -> V_24 = - 1 ;
V_3 -> V_395 = NULL ;
V_3 -> V_396 = NULL ;
F_189 ( L_172 ) ;
V_178 = F_173 ( V_3 ) ;
if ( V_178 < 0 )
return V_178 ;
F_189 ( L_173 ) ;
F_156 ( V_3 ) ;
F_189 ( L_174 ) ;
V_178 = F_236 ( V_177 ) ;
if ( V_178 < 0 ) {
F_38 ( V_118 L_175 ) ;
return V_178 ;
}
F_189 ( L_176 ) ;
return 0 ;
}
static int F_237 ( struct V_176 * V_177 ,
struct V_3 * V_3 )
{
struct V_544 * V_537 = V_3 -> V_537 ;
int V_178 ;
unsigned long V_545 ;
V_3 -> V_184 = - 1 ;
V_3 -> V_177 = V_177 ;
F_61 ( & V_3 -> V_22 ) ;
F_238 ( V_3 -> V_537 ,
V_546 , & V_3 -> V_351 ) ;
strcpy ( V_177 -> V_547 , L_177 ) ;
strcpy ( V_177 -> V_548 , L_178 ) ;
switch ( V_3 -> V_351 ) {
case V_549 :
V_3 -> V_31 = V_48 ;
V_3 -> V_349 = L_179 ;
V_3 -> V_214 = 2 ;
break;
case V_550 :
V_3 -> V_31 = V_47 ;
V_3 -> V_349 = L_180 ;
V_3 -> V_214 = 1 ;
break;
case V_551 :
V_3 -> V_31 = V_42 ;
V_3 -> V_349 = L_181 ;
V_3 -> V_214 = 1 ;
break;
default:
if ( ( V_3 -> V_351 == 0xf0 ) ||
( ( V_3 -> V_351 >= 0xe6 ) &&
( V_3 -> V_351 <= 0xea ) ) ) {
V_3 -> V_31 = V_32 ;
V_3 -> V_349 = L_182 ;
V_3 -> V_214 = 2 ;
} else if ( ( V_3 -> V_351 == 0xd2 ) ||
( ( V_3 -> V_351 >= 0xc8 ) &&
( V_3 -> V_351 <= 0xcf ) ) ) {
V_3 -> V_31 = V_46 ;
V_3 -> V_349 = L_183 ;
V_3 -> V_214 = 3 ;
} else {
F_38 ( V_118
L_184 ,
V_3 -> V_351 ) ;
return - V_552 ;
}
}
V_178 = F_239 ( V_537 ) ;
if ( V_178 < 0 )
return V_178 ;
F_240 ( V_3 -> V_537 ) ;
V_178 = F_241 ( V_537 , L_151 ) ;
if ( V_178 < 0 )
return V_178 ;
V_3 -> V_356 = F_242 ( V_537 , 0 ) ;
V_545 = F_243 ( V_537 , 0 ) ;
F_189 ( L_185 ,
V_3 -> V_356 , V_3 -> V_356 + V_545 - 1 ) ;
V_3 -> V_6 = F_244 ( V_3 -> V_356 , V_545 ) ;
if ( ! V_3 -> V_6 ) {
F_38 ( V_118 L_1
L_186 ,
V_3 -> V_356 , V_3 -> V_356 + V_545 - 1 ) ;
return - V_120 ;
}
F_189 ( L_187 ,
( unsigned long ) V_3 -> V_6 , V_3 -> V_356 ,
V_3 -> V_356 + V_545 - 1 ) ;
if ( F_245 ( V_537 -> V_184 , F_175 ,
V_553 , V_554 , V_3 ) ) {
F_38 ( V_118 L_188 , V_537 -> V_184 ) ;
return - V_120 ;
}
F_189 ( L_189 , V_537 -> V_184 ) ;
V_3 -> V_184 = V_537 -> V_184 ;
F_189 ( L_190 ,
sizeof( struct V_526 ) ) ;
V_3 -> V_10 = F_246 ( sizeof( struct V_526 ) , V_555 ) ;
if ( ! V_3 -> V_10 ) {
F_38 ( V_118 L_1
L_191 ,
( int ) sizeof( struct V_526 ) ) ;
return - V_556 ;
}
V_3 -> V_131 = NULL ;
V_3 -> V_133 = NULL ;
switch ( V_3 -> V_31 ) {
case V_32 :
V_3 -> V_128 = V_3 -> V_130 = V_557 ;
V_3 -> V_137 = V_3 -> V_138 = V_557 ;
V_3 -> V_143 = V_3 -> V_144 = V_557 ;
V_3 -> V_124 = V_3 -> V_126 =
V_558 ;
V_3 -> V_135 = V_3 -> V_136 =
V_558 ;
V_3 -> V_141 = V_3 -> V_142 =
V_558 ;
V_3 -> V_132 = V_3 -> V_134 =
V_559 ;
V_3 -> V_139 = V_3 -> V_140 =
V_559 ;
V_3 -> V_145 = V_3 -> V_146 =
V_559 ;
V_3 -> V_129 = V_3 -> V_127 =
V_557 ;
V_3 -> V_131 = V_3 -> V_133 =
V_559 ;
V_3 -> V_123 = V_3 -> V_125 =
V_558 ;
break;
case V_46 :
case V_42 :
V_3 -> V_128 = V_3 -> V_130 =
V_560 ;
V_3 -> V_137 = V_3 -> V_138 =
V_561 ;
V_3 -> V_143 = V_3 -> V_144 =
V_562 ;
V_3 -> V_124 = V_3 -> V_126 =
V_563 ;
V_3 -> V_135 = V_3 -> V_136 =
V_563 ;
V_3 -> V_141 = V_3 -> V_142 =
V_563 ;
V_3 -> V_132 = V_3 -> V_134 =
V_564 ;
V_3 -> V_139 = V_3 -> V_140 =
V_564 ;
V_3 -> V_145 = V_3 -> V_146 =
V_564 ;
break;
case V_47 :
if ( 0 == ( F_4 ( V_3 , V_33 ) & V_565 ) ) {
F_38 ( V_415 L_192 ) ;
}
V_3 -> V_128 = V_566 ;
V_3 -> V_137 = V_567 ;
V_3 -> V_143 = V_568 ;
V_3 -> V_130 = V_569 ;
V_3 -> V_138 = V_570 ;
V_3 -> V_144 = V_571 ;
V_3 -> V_126 = V_572 ;
V_3 -> V_136 = V_573 ;
V_3 -> V_142 = V_574 ;
V_3 -> V_124 = V_575 ;
V_3 -> V_135 = V_576 ;
V_3 -> V_141 = V_577 ;
V_3 -> V_132 = V_578 ;
V_3 -> V_134 = V_579 ;
V_3 -> V_139 = V_580 ;
V_3 -> V_140 = V_581 ;
V_3 -> V_145 = V_582 ;
V_3 -> V_146 = V_583 ;
break;
case V_48 :
V_3 -> V_128 = V_3 -> V_130 =
V_584 ;
V_3 -> V_137 = V_3 -> V_138 =
V_585 ;
V_3 -> V_143 = V_3 -> V_144 =
V_586 ;
V_3 -> V_127 = V_584 ;
V_3 -> V_129 = V_584 ;
V_3 -> V_124 = V_3 -> V_126 =
V_587 ;
V_3 -> V_135 = V_3 -> V_136 =
V_588 ;
V_3 -> V_141 = V_3 -> V_142 =
V_589 ;
V_3 -> V_123 = V_3 -> V_125 =
V_587 ;
V_3 -> V_132 = V_3 -> V_134 =
V_590 ;
V_3 -> V_139 = V_3 -> V_140 =
V_591 ;
V_3 -> V_145 = V_3 -> V_146 =
V_592 ;
break;
}
switch ( V_3 -> V_31 ) {
case V_47 :
case V_48 :
if ( F_4 ( V_3 , V_33 ) &
V_593 ) {
V_3 -> V_214 ++ ;
V_3 -> V_231 = F_246 ( sizeof( struct V_594 ) ,
V_555 ) ;
if ( NULL != V_3 -> V_231 ) {
F_137 ( V_3 ) ;
}
F_38 ( V_415 L_193 ) ;
} else {
V_3 -> V_231 = NULL ;
}
break;
case V_46 :
if ( F_4 ( V_3 , V_34 ) & V_360 ) {
V_3 -> V_214 ++ ;
V_3 -> V_231 = F_246 ( sizeof( struct V_594 ) ,
V_555 ) ;
if ( NULL != V_3 -> V_231 ) {
F_137 ( V_3 ) ;
}
F_38 ( V_415 L_194 ) ;
} else {
V_3 -> V_231 = NULL ;
}
break;
default:
V_3 -> V_231 = NULL ;
}
switch ( V_3 -> V_31 ) {
case V_32 :
if ( V_3 -> V_231 ) {
V_3 -> V_256 = V_595 ;
V_3 -> V_255 = 10 ;
} else {
V_3 -> V_256 = V_596 ;
V_3 -> V_255 = 9 ;
}
break;
case V_46 :
if ( V_3 -> V_231 ) {
V_3 -> V_256 = V_597 ;
V_3 -> V_255 = 4 ;
} else {
V_3 -> V_256 = V_598 ;
V_3 -> V_255 = 3 ;
}
break;
case V_42 :
break;
case V_48 :
if ( V_3 -> V_231 ) {
V_3 -> V_256 = V_599 ;
V_3 -> V_255 = 9 ;
} else {
V_3 -> V_256 = V_600 ;
V_3 -> V_255 = 8 ;
}
break;
case V_47 :
if ( V_3 -> V_231 ) {
V_3 -> V_256 = V_601 ;
V_3 -> V_255 = 6 ;
} else {
V_3 -> V_256 = V_602 ;
V_3 -> V_255 = 5 ;
}
break;
}
F_247 ( & V_3 -> V_397 ,
F_64 , ( unsigned long ) V_3 ) ;
if ( V_3 -> V_31 != V_42 ) {
V_3 -> V_355 = ( F_4 ( V_3 ,
V_187 ) >> 8 ) & 0xFFFFFF ;
if ( NULL == V_151 [ V_3 -> V_603 ] && V_3 -> V_355 != 0xFFFFFF ) {
sprintf ( V_177 -> V_151 , L_195 , V_3 -> V_355 ) ;
F_248 ( V_177 , V_177 -> V_151 ) ;
}
}
F_189 ( L_196 ) ;
V_178 = F_235 ( V_177 , V_3 ) ;
if ( V_178 < 0 )
return V_178 ;
F_234 ( V_3 ) ;
return 0 ;
}
static int F_249 ( struct V_3 * V_3 )
{
if ( V_3 -> V_356 ) {
V_3 -> V_75 &=
~ ( V_84 | V_83 |
V_190 | V_196 |
V_183 | V_201 ) ;
F_2 ( V_3 , V_85 ,
V_3 -> V_75 ) ;
}
if ( V_3 -> V_184 >= 0 )
F_250 ( V_3 -> V_184 , ( void * ) V_3 ) ;
F_251 ( V_3 -> V_10 ) ;
if ( V_3 -> V_6 )
F_252 ( V_3 -> V_6 ) ;
if ( V_3 -> V_356 )
F_253 ( V_3 -> V_537 ) ;
F_254 ( V_3 -> V_537 ) ;
return 0 ;
}
static void F_255 ( struct V_176 * V_177 )
{
struct V_3 * V_3 = V_177 -> V_170 ;
if ( V_3 )
F_249 ( V_3 ) ;
}
static int F_256 ( struct V_544 * V_537 ,
const struct V_604 * V_605 )
{
static int V_603 ;
struct V_3 * V_3 ;
struct V_176 * V_177 ;
int V_178 ;
if ( V_603 >= V_606 )
return - V_552 ;
if ( ! V_607 [ V_603 ] ) {
V_603 ++ ;
return - V_608 ;
}
V_178 = F_257 ( V_236 [ V_603 ] , V_151 [ V_603 ] ,
V_609 , sizeof( struct V_3 ) , & V_177 ) ;
if ( V_178 < 0 )
return V_178 ;
V_3 = V_177 -> V_170 ;
V_177 -> V_610 = F_255 ;
V_3 -> V_603 = V_603 ;
V_3 -> V_537 = V_537 ;
F_258 ( V_177 , & V_537 -> V_603 ) ;
V_178 = F_237 ( V_177 , V_3 ) ;
if ( V_178 < 0 ) {
F_259 ( V_177 ) ;
return V_178 ;
}
if ( V_3 -> V_31 != V_42 ) {
sprintf ( V_177 -> V_203 , L_197 ,
V_3 -> V_349 ,
V_3 -> V_355 ) ;
sprintf ( V_177 -> V_611 , L_198 ,
V_3 -> V_349 ,
V_3 -> V_355 ,
V_3 -> V_356 , V_3 -> V_184 ) ;
} else {
sprintf ( V_177 -> V_203 , L_199 , V_3 -> V_349 ) ;
sprintf ( V_177 -> V_611 , L_200 ,
V_3 -> V_349 , V_3 -> V_356 , V_3 -> V_184 ) ;
}
V_178 = F_236 ( V_177 ) ;
if ( V_178 < 0 ) {
F_259 ( V_177 ) ;
return V_178 ;
}
F_260 ( V_537 , V_177 ) ;
V_603 ++ ;
return 0 ;
}
static void F_261 ( struct V_544 * V_537 )
{
F_259 ( F_262 ( V_537 ) ) ;
F_260 ( V_537 , NULL ) ;
}
