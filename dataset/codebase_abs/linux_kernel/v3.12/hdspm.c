static inline int F_1 ( int V_1 )
{
static const int V_2 [] = {
0 , 32000 , 44100 , 48000 , 64000 , 88200 ,
96000 , 128000 , 176400 , 192000 } ;
if ( V_1 < 1 || V_1 > 9 )
return 0 ;
return V_2 [ V_1 ] ;
}
static bool F_2 ( struct V_3 * V_3 )
{
return ( ( V_4 == V_3 -> V_5 ) || ( V_6 == V_3 -> V_5 ) ) ;
}
static inline void F_3 ( struct V_3 * V_3 , unsigned int V_7 ,
unsigned int V_8 )
{
F_4 ( V_8 , V_3 -> V_9 + V_7 ) ;
}
static inline unsigned int F_5 ( struct V_3 * V_3 , unsigned int V_7 )
{
return F_6 ( V_3 -> V_9 + V_7 ) ;
}
static inline int F_7 ( struct V_3 * V_3 , unsigned int V_10 ,
unsigned int V_11 )
{
if ( V_10 >= V_12 || V_11 >= V_12 )
return 0 ;
return V_3 -> V_13 -> V_14 [ V_10 ] . V_11 [ V_11 ] ;
}
static inline int F_8 ( struct V_3 * V_3 , unsigned int V_10 ,
unsigned int V_15 )
{
if ( V_10 >= V_12 || V_15 >= V_12 )
return 0 ;
return V_3 -> V_13 -> V_14 [ V_10 ] . V_15 [ V_15 ] ;
}
static int F_9 ( struct V_3 * V_3 , unsigned int V_10 ,
unsigned int V_11 , unsigned short V_16 )
{
if ( V_10 >= V_12 || V_11 >= V_12 )
return - 1 ;
F_3 ( V_3 ,
V_17 +
( ( V_11 + 128 * V_10 ) * sizeof( V_18 ) ) ,
( V_3 -> V_13 -> V_14 [ V_10 ] . V_11 [ V_11 ] = V_16 & 0xFFFF ) ) ;
return 0 ;
}
static int F_10 ( struct V_3 * V_3 , unsigned int V_10 ,
unsigned int V_15 , unsigned short V_16 )
{
if ( V_10 >= V_12 || V_15 >= V_12 )
return - 1 ;
F_3 ( V_3 ,
V_17 +
( ( 64 + V_15 + 128 * V_10 ) * sizeof( V_18 ) ) ,
( V_3 -> V_13 -> V_14 [ V_10 ] . V_15 [ V_15 ] = V_16 & 0xFFFF ) ) ;
return 0 ;
}
static inline void F_11 ( struct V_3 * V_3 , int V_19 , int V_20 )
{
F_3 ( V_3 , V_21 + ( 4 * V_19 ) , V_20 ) ;
}
static inline void F_12 ( struct V_3 * V_3 , int V_19 , int V_20 )
{
F_3 ( V_3 , V_22 + ( 4 * V_19 ) , V_20 ) ;
}
static int F_13 ( struct V_3 * V_3 )
{
unsigned long V_23 ;
int V_24 = 1 ;
F_14 ( & V_3 -> V_25 , V_23 ) ;
if ( ( V_3 -> V_26 != V_3 -> V_27 ) &&
( V_3 -> V_26 >= 0 ) && ( V_3 -> V_27 >= 0 ) ) {
V_24 = 0 ;
}
F_15 ( & V_3 -> V_25 , V_23 ) ;
return V_24 ;
}
static int F_16 ( int V_28 )
{
if ( V_28 < 38050 )
return 32000 ;
if ( V_28 < 46008 )
return 44100 ;
else
return 48000 ;
}
static int F_17 ( struct V_3 * V_3 , int V_28 )
{
if ( V_28 <= 48000 ) {
if ( V_3 -> V_29 & V_30 )
return V_28 * 4 ;
else if ( V_3 -> V_29 &
V_31 )
return V_28 * 2 ;
}
return V_28 ;
}
static int F_18 ( struct V_3 * V_3 )
{
unsigned int V_32 , V_33 , V_34 ;
int V_35 , V_28 = 0 , V_36 ;
switch ( V_3 -> V_5 ) {
case V_37 :
V_33 = F_5 ( V_3 , V_38 ) ;
V_32 = F_5 ( V_3 , V_39 ) ;
V_34 = F_5 ( V_3 , V_40 ) ;
V_35 = F_19 ( V_3 ) ;
switch ( V_35 ) {
case V_41 :
if ( F_20 ( V_3 ) )
return F_1 ( F_21 ( V_3 ) ) ;
break;
case V_42 :
case V_43 :
case V_44 :
case V_45 :
case V_46 :
case V_47 :
case V_48 :
case V_49 :
if ( F_22 ( V_3 , V_35 - V_42 ) )
return F_1 ( F_23 ( V_3 ,
V_35 - V_42 ) ) ;
break;
case V_50 :
if ( F_24 ( V_3 ) )
return F_1 ( F_25 ( V_3 ) ) ;
break;
default:
return 0 ;
}
break;
case V_51 :
V_32 = F_5 ( V_3 , V_39 ) ;
if ( ! ( V_32 & V_52 ) ) {
V_28 = 0 ;
} else {
switch ( V_32 & ( V_53 ) ) {
case V_54 * 1 :
V_28 = 32000 ; break;
case V_54 * 2 :
V_28 = 44100 ; break;
case V_54 * 3 :
V_28 = 48000 ; break;
case V_54 * 4 :
V_28 = 64000 ; break;
case V_54 * 5 :
V_28 = 88200 ; break;
case V_54 * 6 :
V_28 = 96000 ; break;
case V_54 * 7 :
V_28 = 128000 ; break;
case V_54 * 8 :
V_28 = 176400 ; break;
case V_54 * 9 :
V_28 = 192000 ; break;
default:
V_28 = 0 ; break;
}
}
break;
case V_55 :
case V_4 :
case V_6 :
V_33 = F_5 ( V_3 , V_38 ) ;
V_32 = F_5 ( V_3 , V_39 ) ;
V_28 = 0 ;
if ( ( V_33 & V_56 ) != 0 &&
( V_33 & V_57 ) == 0 ) {
V_36 = V_33 & V_58 ;
switch ( V_36 ) {
case V_59 :
V_28 = 32000 ;
break;
case V_60 :
V_28 = 44100 ;
break;
case V_61 :
V_28 = 48000 ;
break;
case V_62 :
V_28 = 64000 ;
break;
case V_63 :
V_28 = 88200 ;
break;
case V_64 :
V_28 = 96000 ;
break;
case V_65 :
V_28 = 128000 ;
break;
case V_66 :
V_28 = 176400 ;
break;
case V_67 :
V_28 = 192000 ;
break;
default:
V_28 = 0 ;
break;
}
}
if ( V_28 != 0 &&
( V_33 & V_68 ) == V_69 )
return F_17 ( V_3 , V_28 ) ;
if ( V_32 & V_52 ) {
V_36 = V_32 & V_70 ;
switch ( V_36 ) {
case V_71 :
V_28 = 32000 ;
break;
case V_72 :
V_28 = 44100 ;
break;
case V_73 :
V_28 = 48000 ;
break;
case V_74 :
V_28 = 64000 ;
break;
case V_75 :
V_28 = 88200 ;
break;
case V_76 :
V_28 = 96000 ;
break;
case V_77 :
V_28 = 128000 ;
break;
case V_78 :
V_28 = 176400 ;
break;
case V_79 :
V_28 = 192000 ;
break;
default:
V_28 = 0 ;
break;
}
}
{
bool V_80 = 0 ;
bool V_81 = 0 ;
V_35 = F_19 ( V_3 ) ;
if ( V_82 == V_35 ) {
V_80 = 1 ;
V_81 = ( V_83 ==
F_24 ( V_3 ) ) ;
} else if ( V_84 == V_35 ) {
V_80 = 1 ;
V_81 = ( V_83 ==
F_26 ( V_3 ) ) ;
}
if ( V_80 && V_81 ) {
V_28 = F_16 (
F_27 ( V_3 ) ) ;
}
}
V_28 = F_17 ( V_3 , V_28 ) ;
break;
}
return V_28 ;
}
static int F_28 ( struct V_3 * V_3 )
{
int V_1 ;
V_1 = F_29 ( V_3 -> V_29 ) ;
if ( ( 7 == V_1 ) && ( V_6 == V_3 -> V_5 || V_4 == V_3 -> V_5 ) )
V_1 = - 1 ;
return 1 << ( V_1 + 6 ) ;
}
static inline void F_30 ( struct V_3 * V_3 )
{
V_3 -> V_85 = 4 * F_28 ( V_3 ) ;
}
static T_1 F_31 ( struct V_3 * V_3 )
{
int V_86 ;
V_86 = F_5 ( V_3 , V_39 ) ;
switch ( V_3 -> V_5 ) {
case V_6 :
case V_4 :
V_86 &= V_87 ;
V_86 /= 4 ;
break;
default:
V_86 = ( V_86 & V_88 ) ?
( V_3 -> V_85 / 4 ) : 0 ;
}
return V_86 ;
}
static inline void F_32 ( struct V_3 * V_89 )
{
V_89 -> V_29 |= ( V_90 | V_91 ) ;
F_3 ( V_89 , V_92 , V_89 -> V_29 ) ;
}
static inline void F_33 ( struct V_3 * V_89 )
{
V_89 -> V_29 &= ~ ( V_91 | V_90 ) ;
F_3 ( V_89 , V_92 , V_89 -> V_29 ) ;
}
static void F_34 ( struct V_3 * V_3 )
{
int V_19 ;
int V_1 = V_3 -> V_85 ;
void * V_93 = V_3 -> V_94 ;
if ( V_93 == NULL )
return;
for ( V_19 = 0 ; V_19 < V_95 ; V_19 ++ ) {
memset ( V_93 , 0 , V_1 ) ;
V_93 += V_96 ;
}
}
static int F_35 ( struct V_3 * V_89 , unsigned int V_97 )
{
int V_1 ;
F_36 ( & V_89 -> V_25 ) ;
if ( 32 == V_97 ) {
V_1 = 7 ;
} else {
V_97 >>= 7 ;
V_1 = 0 ;
while ( V_97 ) {
V_1 ++ ;
V_97 >>= 1 ;
}
}
V_89 -> V_29 &= ~ V_98 ;
V_89 -> V_29 |= F_37 ( V_1 ) ;
F_3 ( V_89 , V_92 , V_89 -> V_29 ) ;
F_30 ( V_89 ) ;
F_38 ( & V_89 -> V_25 ) ;
return 0 ;
}
static T_2 F_39 ( struct V_3 * V_3 , T_2 V_99 )
{
T_2 V_100 ;
if ( V_99 == 0 )
return 0 ;
switch ( V_3 -> V_5 ) {
case V_55 :
case V_37 :
V_100 = 110069313433624ULL ;
break;
case V_6 :
case V_4 :
V_100 = 104857600000000ULL ;
break;
case V_51 :
V_100 = 131072000000000ULL ;
break;
default:
F_40 () ;
return 0 ;
}
return F_41 ( V_100 , V_99 ) ;
}
static void F_42 ( struct V_3 * V_3 , int V_28 )
{
T_2 V_1 ;
if ( V_28 >= 112000 )
V_28 /= 4 ;
else if ( V_28 >= 56000 )
V_28 /= 2 ;
switch ( V_3 -> V_5 ) {
case V_51 :
V_1 = 131072000000000ULL ;
break;
case V_55 :
case V_37 :
V_1 = 110069313433624ULL ;
break;
case V_6 :
case V_4 :
V_1 = 104857600000000ULL ;
break;
default:
F_40 () ;
return;
}
V_1 = F_41 ( V_1 , V_28 ) ;
F_43 ( V_1 >> 32 ) ;
F_3 ( V_3 , V_101 , ( V_18 ) V_1 ) ;
}
static int F_44 ( struct V_3 * V_3 , int V_28 , int V_102 )
{
int V_103 ;
int V_36 ;
int V_104 = 0 ;
int V_105 , V_106 ;
if ( ! ( V_3 -> V_29 & V_107 ) ) {
if ( V_102 ) {
F_45 ( V_108 L_1
L_2
L_3 ) ;
V_104 = 1 ;
} else {
int V_109 =
F_18 ( V_3 ) ;
if ( F_19 ( V_3 ) ==
V_110 ) {
F_45 ( V_108 L_1
L_4 ) ;
V_104 = 1 ;
} else if ( V_28 != V_109 ) {
F_45 ( V_108 L_1
L_5
L_6 ) ;
V_104 = 1 ;
}
}
}
V_103 = V_3 -> V_111 ;
if ( V_103 <= 48000 )
V_105 = V_112 ;
else if ( V_103 <= 96000 )
V_105 = V_113 ;
else
V_105 = V_114 ;
if ( V_28 <= 48000 )
V_106 = V_112 ;
else if ( V_28 <= 96000 )
V_106 = V_113 ;
else
V_106 = V_114 ;
switch ( V_28 ) {
case 32000 :
V_36 = V_115 ;
break;
case 44100 :
V_36 = V_116 ;
break;
case 48000 :
V_36 = V_117 ;
break;
case 64000 :
V_36 = V_118 ;
break;
case 88200 :
V_36 = V_119 ;
break;
case 96000 :
V_36 = V_120 ;
break;
case 128000 :
V_36 = V_121 ;
break;
case 176400 :
V_36 = V_122 ;
break;
case 192000 :
V_36 = V_123 ;
break;
default:
return - V_124 ;
}
if ( V_105 != V_106
&& ( V_3 -> V_27 >= 0 || V_3 -> V_26 >= 0 ) ) {
F_45
( V_125 L_1
L_7
L_8 ,
V_126 [ V_105 ] ,
V_126 [ V_106 ] ,
V_3 -> V_27 , V_3 -> V_26 ) ;
return - V_127 ;
}
V_3 -> V_29 &= ~ V_128 ;
V_3 -> V_29 |= V_36 ;
F_3 ( V_3 , V_92 , V_3 -> V_29 ) ;
F_42 ( V_3 , V_28 ) ;
if ( V_37 == V_3 -> V_5 && V_28 != V_103 )
F_3 ( V_3 , V_129 , 0 ) ;
V_3 -> V_111 = V_28 ;
if ( V_28 <= 48000 ) {
V_3 -> V_130 = V_3 -> V_131 ;
V_3 -> V_132 = V_3 -> V_133 ;
V_3 -> V_134 = V_3 -> V_135 ;
V_3 -> V_136 = V_3 -> V_137 ;
V_3 -> V_138 = V_3 -> V_139 ;
V_3 -> V_140 = V_3 -> V_141 ;
} else if ( V_28 <= 96000 ) {
V_3 -> V_130 = V_3 -> V_142 ;
V_3 -> V_132 = V_3 -> V_143 ;
V_3 -> V_134 = V_3 -> V_144 ;
V_3 -> V_136 = V_3 -> V_145 ;
V_3 -> V_138 = V_3 -> V_146 ;
V_3 -> V_140 = V_3 -> V_147 ;
} else {
V_3 -> V_130 = V_3 -> V_148 ;
V_3 -> V_132 = V_3 -> V_149 ;
V_3 -> V_134 = V_3 -> V_150 ;
V_3 -> V_136 = V_3 -> V_151 ;
V_3 -> V_138 = V_3 -> V_152 ;
V_3 -> V_140 = V_3 -> V_153 ;
}
if ( V_104 != 0 )
return - 1 ;
return 0 ;
}
static void F_46 ( struct V_3 * V_3 , int V_154 )
{
int V_19 , V_155 ;
unsigned int V_156 ;
if ( V_154 > V_157 )
V_156 = V_157 ;
else if ( V_154 < 0 )
V_156 = 0 ;
else
V_156 = V_154 ;
for ( V_19 = 0 ; V_19 < V_12 ; V_19 ++ )
for ( V_155 = 0 ; V_155 < V_12 ; V_155 ++ ) {
F_9 ( V_3 , V_19 , V_155 , V_156 ) ;
F_10 ( V_3 , V_19 , V_155 , V_156 ) ;
}
}
static inline unsigned char F_47 ( struct V_3 * V_3 ,
int V_158 )
{
return F_5 ( V_3 , V_3 -> V_159 [ V_158 ] . V_160 ) ;
}
static inline void F_48 ( struct V_3 * V_3 , int V_158 ,
int V_8 )
{
return F_3 ( V_3 , V_3 -> V_159 [ V_158 ] . V_161 , V_8 ) ;
}
static inline int F_49 ( struct V_3 * V_3 , int V_158 )
{
return F_5 ( V_3 , V_3 -> V_159 [ V_158 ] . V_162 ) & 0xFF ;
}
static inline int F_50 ( struct V_3 * V_3 , int V_158 )
{
int V_163 ;
V_163 = F_5 ( V_3 , V_3 -> V_159 [ V_158 ] . V_164 ) & 0xFF ;
if ( V_163 < 128 )
return 128 - V_163 ;
else
return 0 ;
}
static void F_51 ( struct V_3 * V_3 , int V_158 )
{
while ( F_49 ( V_3 , V_158 ) )
F_47 ( V_3 , V_158 ) ;
}
static int F_52 ( struct V_165 * V_166 )
{
unsigned long V_23 ;
int V_167 ;
int V_168 ;
int V_19 ;
unsigned char V_93 [ 128 ] ;
F_14 ( & V_166 -> V_25 , V_23 ) ;
if ( V_166 -> V_169 &&
! F_53 ( V_166 -> V_169 ) ) {
V_167 = F_50 ( V_166 -> V_3 ,
V_166 -> V_158 ) ;
if ( V_167 > 0 ) {
if ( V_167 > ( int ) sizeof ( V_93 ) )
V_167 = sizeof ( V_93 ) ;
V_168 = F_54 ( V_166 -> V_169 , V_93 ,
V_167 ) ;
if ( V_168 > 0 ) {
for ( V_19 = 0 ; V_19 < V_168 ; ++ V_19 )
F_48 ( V_166 -> V_3 ,
V_166 -> V_158 ,
V_93 [ V_19 ] ) ;
}
}
}
F_15 ( & V_166 -> V_25 , V_23 ) ;
return 0 ;
}
static int F_55 ( struct V_165 * V_166 )
{
unsigned char V_93 [ 128 ] ;
unsigned long V_23 ;
int V_167 ;
int V_19 ;
F_14 ( & V_166 -> V_25 , V_23 ) ;
V_167 = F_49 ( V_166 -> V_3 , V_166 -> V_158 ) ;
if ( V_167 > 0 ) {
if ( V_166 -> V_170 ) {
if ( V_167 > ( int ) sizeof ( V_93 ) )
V_167 = sizeof ( V_93 ) ;
for ( V_19 = 0 ; V_19 < V_167 ; ++ V_19 )
V_93 [ V_19 ] = F_47 ( V_166 -> V_3 ,
V_166 -> V_158 ) ;
if ( V_167 )
F_56 ( V_166 -> V_170 , V_93 ,
V_167 ) ;
} else {
while ( V_167 -- )
F_47 ( V_166 -> V_3 ,
V_166 -> V_158 ) ;
}
}
V_166 -> V_171 = 0 ;
F_15 ( & V_166 -> V_25 , V_23 ) ;
F_14 ( & V_166 -> V_3 -> V_25 , V_23 ) ;
V_166 -> V_3 -> V_29 |= V_166 -> V_172 ;
F_3 ( V_166 -> V_3 , V_92 ,
V_166 -> V_3 -> V_29 ) ;
F_15 ( & V_166 -> V_3 -> V_25 , V_23 ) ;
return F_52 ( V_166 ) ;
}
static void
F_57 ( struct V_173 * V_174 , int V_175 )
{
struct V_3 * V_3 ;
struct V_165 * V_166 ;
unsigned long V_23 ;
V_166 = V_174 -> V_176 -> V_177 ;
V_3 = V_166 -> V_3 ;
F_14 ( & V_3 -> V_25 , V_23 ) ;
if ( V_175 ) {
if ( ! ( V_3 -> V_29 & V_166 -> V_172 ) ) {
F_51 ( V_3 , V_166 -> V_158 ) ;
V_3 -> V_29 |= V_166 -> V_172 ;
}
} else {
V_3 -> V_29 &= ~ V_166 -> V_172 ;
}
F_3 ( V_3 , V_92 , V_3 -> V_29 ) ;
F_15 ( & V_3 -> V_25 , V_23 ) ;
}
static void F_58 ( unsigned long V_16 )
{
struct V_165 * V_166 = (struct V_165 * ) V_16 ;
unsigned long V_23 ;
F_52 ( V_166 ) ;
F_14 ( & V_166 -> V_25 , V_23 ) ;
if ( V_166 -> V_178 ) {
V_166 -> V_179 . V_180 = 1 + V_181 ;
F_59 ( & V_166 -> V_179 ) ;
}
F_15 ( & V_166 -> V_25 , V_23 ) ;
}
static void
F_60 ( struct V_173 * V_174 , int V_175 )
{
struct V_165 * V_166 ;
unsigned long V_23 ;
V_166 = V_174 -> V_176 -> V_177 ;
F_14 ( & V_166 -> V_25 , V_23 ) ;
if ( V_175 ) {
if ( ! V_166 -> V_178 ) {
F_61 ( & V_166 -> V_179 ) ;
V_166 -> V_179 . V_182 = F_58 ;
V_166 -> V_179 . V_16 = ( unsigned long ) V_166 ;
V_166 -> V_179 . V_180 = 1 + V_181 ;
F_59 ( & V_166 -> V_179 ) ;
V_166 -> V_178 ++ ;
}
} else {
if ( V_166 -> V_178 && -- V_166 -> V_178 <= 0 )
F_62 ( & V_166 -> V_179 ) ;
}
F_15 ( & V_166 -> V_25 , V_23 ) ;
if ( V_175 )
F_52 ( V_166 ) ;
}
static int F_63 ( struct V_173 * V_174 )
{
struct V_165 * V_166 ;
V_166 = V_174 -> V_176 -> V_177 ;
F_36 ( & V_166 -> V_25 ) ;
F_51 ( V_166 -> V_3 , V_166 -> V_158 ) ;
V_166 -> V_170 = V_174 ;
F_38 ( & V_166 -> V_25 ) ;
return 0 ;
}
static int F_64 ( struct V_173 * V_174 )
{
struct V_165 * V_166 ;
V_166 = V_174 -> V_176 -> V_177 ;
F_36 ( & V_166 -> V_25 ) ;
V_166 -> V_169 = V_174 ;
F_38 ( & V_166 -> V_25 ) ;
return 0 ;
}
static int F_65 ( struct V_173 * V_174 )
{
struct V_165 * V_166 ;
F_57 ( V_174 , 0 ) ;
V_166 = V_174 -> V_176 -> V_177 ;
F_36 ( & V_166 -> V_25 ) ;
V_166 -> V_170 = NULL ;
F_38 ( & V_166 -> V_25 ) ;
return 0 ;
}
static int F_66 ( struct V_173 * V_174 )
{
struct V_165 * V_166 ;
F_60 ( V_174 , 0 ) ;
V_166 = V_174 -> V_176 -> V_177 ;
F_36 ( & V_166 -> V_25 ) ;
V_166 -> V_169 = NULL ;
F_38 ( & V_166 -> V_25 ) ;
return 0 ;
}
static int F_67 ( struct V_183 * V_184 ,
struct V_3 * V_3 , int V_158 )
{
int V_185 ;
char V_93 [ 32 ] ;
V_3 -> V_159 [ V_158 ] . V_158 = V_158 ;
V_3 -> V_159 [ V_158 ] . V_3 = V_3 ;
F_68 ( & V_3 -> V_159 [ V_158 ] . V_25 ) ;
if ( 0 == V_158 ) {
if ( V_51 == V_3 -> V_5 ) {
V_3 -> V_159 [ 0 ] . V_160 = V_186 ;
V_3 -> V_159 [ 0 ] . V_162 = V_187 ;
V_3 -> V_159 [ 0 ] . V_161 = V_188 ;
V_3 -> V_159 [ 0 ] . V_164 = V_189 ;
V_3 -> V_159 [ 0 ] . V_172 = V_190 ;
V_3 -> V_159 [ 0 ] . V_191 = V_192 ;
} else {
V_3 -> V_159 [ 0 ] . V_160 = V_193 ;
V_3 -> V_159 [ 0 ] . V_162 = V_194 ;
V_3 -> V_159 [ 0 ] . V_161 = V_195 ;
V_3 -> V_159 [ 0 ] . V_164 = V_196 ;
V_3 -> V_159 [ 0 ] . V_172 = V_197 ;
V_3 -> V_159 [ 0 ] . V_191 = V_198 ;
}
} else if ( 1 == V_158 ) {
V_3 -> V_159 [ 1 ] . V_160 = V_199 ;
V_3 -> V_159 [ 1 ] . V_162 = V_200 ;
V_3 -> V_159 [ 1 ] . V_161 = V_201 ;
V_3 -> V_159 [ 1 ] . V_164 = V_202 ;
V_3 -> V_159 [ 1 ] . V_172 = V_203 ;
V_3 -> V_159 [ 1 ] . V_191 = V_204 ;
} else if ( ( 2 == V_158 ) && ( V_55 == V_3 -> V_5 ) ) {
V_3 -> V_159 [ 2 ] . V_160 = V_186 ;
V_3 -> V_159 [ 2 ] . V_162 = V_187 ;
V_3 -> V_159 [ 2 ] . V_161 = V_188 ;
V_3 -> V_159 [ 2 ] . V_164 = V_189 ;
V_3 -> V_159 [ 2 ] . V_172 = V_190 ;
V_3 -> V_159 [ 2 ] . V_191 = V_192 ;
} else if ( 2 == V_158 ) {
V_3 -> V_159 [ 2 ] . V_160 = V_186 ;
V_3 -> V_159 [ 2 ] . V_162 = V_187 ;
V_3 -> V_159 [ 2 ] . V_161 = - 1 ;
V_3 -> V_159 [ 2 ] . V_164 = - 1 ;
V_3 -> V_159 [ 2 ] . V_172 = V_190 ;
V_3 -> V_159 [ 2 ] . V_191 = V_205 ;
} else if ( 3 == V_158 ) {
V_3 -> V_159 [ 3 ] . V_160 = V_206 ;
V_3 -> V_159 [ 3 ] . V_162 = V_207 ;
V_3 -> V_159 [ 3 ] . V_161 = - 1 ;
V_3 -> V_159 [ 3 ] . V_164 = - 1 ;
V_3 -> V_159 [ 3 ] . V_172 = V_208 ;
V_3 -> V_159 [ 3 ] . V_191 = V_209 ;
}
if ( ( V_158 < 2 ) || ( ( 2 == V_158 ) && ( ( V_55 == V_3 -> V_5 ) ||
( V_51 == V_3 -> V_5 ) ) ) ) {
if ( ( V_158 == 0 ) && ( V_51 == V_3 -> V_5 ) ) {
sprintf ( V_93 , L_9 , V_184 -> V_210 ) ;
} else if ( ( V_158 == 2 ) && ( V_55 == V_3 -> V_5 ) ) {
sprintf ( V_93 , L_9 , V_184 -> V_210 ) ;
} else {
sprintf ( V_93 , L_10 , V_184 -> V_210 , V_158 + 1 ) ;
}
V_185 = F_69 ( V_184 , V_93 , V_158 , 1 , 1 ,
& V_3 -> V_159 [ V_158 ] . V_176 ) ;
if ( V_185 < 0 )
return V_185 ;
sprintf ( V_3 -> V_159 [ V_158 ] . V_176 -> V_211 , L_10 ,
V_184 -> V_158 , V_158 + 1 ) ;
V_3 -> V_159 [ V_158 ] . V_176 -> V_177 = & V_3 -> V_159 [ V_158 ] ;
F_70 ( V_3 -> V_159 [ V_158 ] . V_176 ,
V_212 ,
& V_213 ) ;
F_70 ( V_3 -> V_159 [ V_158 ] . V_176 ,
V_214 ,
& V_215 ) ;
V_3 -> V_159 [ V_158 ] . V_176 -> V_216 |=
V_217 |
V_218 |
V_219 ;
} else {
sprintf ( V_93 , L_11 , V_184 -> V_210 , V_158 + 1 ) ;
V_185 = F_69 ( V_184 , V_93 , V_158 , 1 , 1 ,
& V_3 -> V_159 [ V_158 ] . V_176 ) ;
if ( V_185 < 0 )
return V_185 ;
sprintf ( V_3 -> V_159 [ V_158 ] . V_176 -> V_211 ,
L_11 , V_184 -> V_158 , V_158 + 1 ) ;
V_3 -> V_159 [ V_158 ] . V_176 -> V_177 = & V_3 -> V_159 [ V_158 ] ;
F_70 ( V_3 -> V_159 [ V_158 ] . V_176 ,
V_214 ,
& V_215 ) ;
V_3 -> V_159 [ V_158 ] . V_176 -> V_216 |= V_218 ;
}
return 0 ;
}
static void F_71 ( unsigned long V_220 )
{
struct V_3 * V_3 = (struct V_3 * ) V_220 ;
int V_19 = 0 ;
while ( V_19 < V_3 -> V_221 ) {
if ( V_3 -> V_159 [ V_19 ] . V_171 )
F_55 ( & V_3 -> V_159 [ V_19 ] ) ;
V_19 ++ ;
}
}
static inline int F_27 ( struct V_3 * V_3 )
{
unsigned int V_99 , V_28 ;
V_99 = F_5 ( V_3 , V_222 ) ;
V_28 = F_39 ( V_3 , V_99 ) ;
return V_28 ;
}
static int F_72 ( struct V_3 * V_3 )
{
unsigned int V_28 ;
V_28 = F_27 ( V_3 ) ;
if ( V_28 > 207000 ) {
if ( 0 == F_73 ( V_3 ) ) {
V_28 = V_3 -> V_111 ;
} else {
V_28 = F_18 ( V_3 ) ;
}
}
return V_28 ;
}
static int F_74 ( struct V_223 * V_224 ,
struct V_225 * V_226 )
{
V_226 -> type = V_227 ;
V_226 -> V_228 = 1 ;
V_226 -> V_229 . integer . V_230 = 27000 ;
V_226 -> V_229 . integer . V_231 = 207000 ;
V_226 -> V_229 . integer . V_232 = 1 ;
return 0 ;
}
static int F_75 ( struct V_223 * V_224 ,
struct V_233 *
V_234 )
{
struct V_3 * V_3 = F_76 ( V_224 ) ;
V_234 -> V_229 . integer . V_229 [ 0 ] = F_72 ( V_3 ) ;
return 0 ;
}
static int F_77 ( struct V_223 * V_224 ,
struct V_233 *
V_234 )
{
struct V_3 * V_3 = F_76 ( V_224 ) ;
F_42 ( V_3 , V_234 -> V_229 . V_235 . V_236 [ 0 ] ) ;
return 0 ;
}
static int F_21 ( struct V_3 * V_3 )
{
int V_32 ;
switch ( V_3 -> V_5 ) {
case V_6 :
case V_4 :
V_32 = F_5 ( V_3 , V_237 ) ;
return ( V_32 >> 16 ) & 0xF ;
break;
case V_37 :
V_32 = F_5 ( V_3 , V_39 ) ;
return ( V_32 >> V_238 ) & 0xF ;
default:
break;
}
return 0 ;
}
static int F_25 ( struct V_3 * V_3 )
{
int V_32 ;
if ( V_3 -> V_239 ) {
switch ( V_3 -> V_5 ) {
case V_6 :
case V_4 :
V_32 = F_5 ( V_3 , V_237 ) ;
return ( V_32 >> 20 ) & 0xF ;
break;
case V_37 :
V_32 = F_5 ( V_3 , V_39 ) ;
return ( V_32 >> 1 ) & 0xF ;
default:
break;
}
}
return 0 ;
}
static int F_78 ( struct V_3 * V_3 )
{
int V_32 ;
if ( V_3 -> V_239 ) {
switch ( V_3 -> V_5 ) {
case V_6 :
case V_4 :
V_32 = F_5 ( V_3 , V_240 ) ;
return ( V_32 >> 12 ) & 0xF ;
break;
default:
break;
}
}
return 0 ;
}
static int F_23 ( struct V_3 * V_3 , int V_241 )
{
int V_34 ;
switch ( V_3 -> V_5 ) {
case V_37 :
V_34 = F_5 ( V_3 , V_40 ) ;
return ( V_34 >> ( 4 * V_241 ) ) & 0xF ;
break;
default:
break;
}
return 0 ;
}
static int F_79 ( struct V_3 * V_3 , unsigned int V_242 )
{
int V_32 = F_5 ( V_3 , V_240 ) ;
return ( V_32 >> ( V_242 * 4 ) ) & 0xF ;
}
static int F_80 ( struct V_3 * V_3 )
{
int V_28 = F_18 ( V_3 ) ;
int V_19 , V_243 = 0 ;
for ( V_19 = 1 ; V_19 < 10 ; V_19 ++ )
if ( F_1 ( V_19 ) == V_28 ) {
V_243 = V_19 ;
break;
}
return V_243 ;
}
static int F_81 ( struct V_223 * V_224 ,
struct V_225 * V_226 )
{
F_82 ( V_226 , V_244 ) ;
return 0 ;
}
static int F_83 ( struct V_223 * V_224 ,
struct V_233 *
V_234 )
{
struct V_3 * V_3 = F_76 ( V_224 ) ;
switch ( V_3 -> V_5 ) {
case V_6 :
switch ( V_224 -> V_245 ) {
case 0 :
V_234 -> V_229 . V_235 . V_236 [ 0 ] =
F_21 ( V_3 ) ;
break;
case 7 :
V_234 -> V_229 . V_235 . V_236 [ 0 ] =
F_25 ( V_3 ) ;
break;
case 8 :
V_234 -> V_229 . V_235 . V_236 [ 0 ] =
F_78 ( V_3 ) ;
break;
default:
V_234 -> V_229 . V_235 . V_236 [ 0 ] =
F_79 ( V_3 ,
V_224 -> V_245 - 1 ) ;
}
break;
case V_4 :
switch ( V_224 -> V_245 ) {
case 0 :
V_234 -> V_229 . V_235 . V_236 [ 0 ] =
F_21 ( V_3 ) ;
break;
case 4 :
V_234 -> V_229 . V_235 . V_236 [ 0 ] =
F_25 ( V_3 ) ;
break;
case 5 :
V_234 -> V_229 . V_235 . V_236 [ 0 ] =
F_78 ( V_3 ) ;
break;
default:
V_234 -> V_229 . V_235 . V_236 [ 0 ] =
F_79 ( V_3 ,
V_224 -> V_245 - 1 ) ;
}
break;
case V_37 :
switch ( V_224 -> V_245 ) {
case 0 :
V_234 -> V_229 . V_235 . V_236 [ 0 ] =
F_21 ( V_3 ) ;
break;
case 9 :
V_234 -> V_229 . V_235 . V_236 [ 0 ] =
F_25 ( V_3 ) ;
break;
case 10 :
V_234 -> V_229 . V_235 . V_236 [ 0 ] =
F_78 ( V_3 ) ;
break;
case 11 :
V_234 -> V_229 . V_235 . V_236 [ 0 ] =
F_80 ( V_3 ) ;
break;
default:
V_234 -> V_229 . V_235 . V_236 [ 0 ] =
F_23 ( V_3 ,
V_224 -> V_245 -
V_42 ) ;
break;
}
break;
case V_55 :
case V_51 :
V_234 -> V_229 . V_235 . V_236 [ 0 ] =
F_80 ( V_3 ) ;
break;
default:
break;
}
return 0 ;
}
static int F_73 ( struct V_3 * V_3 )
{
switch ( V_3 -> V_5 ) {
case V_4 :
case V_6 :
if ( V_3 -> V_246 & V_247 )
return 0 ;
break;
default:
if ( V_3 -> V_29 & V_107 )
return 0 ;
}
return 1 ;
}
static void F_84 ( struct V_3 * V_3 , int V_248 )
{
F_85 ( V_3 ,
( F_2 ( V_3 ) ) ?
V_247 : V_107 ,
( 0 == V_248 ) ) ;
}
static int F_86 ( struct V_223 * V_224 ,
struct V_225 * V_226 )
{
static const char * const V_249 [] = { L_12 , L_13 } ;
F_82 ( V_226 , V_249 ) ;
return 0 ;
}
static int F_87 ( struct V_223 * V_224 ,
struct V_233 * V_234 )
{
struct V_3 * V_3 = F_76 ( V_224 ) ;
V_234 -> V_229 . V_235 . V_236 [ 0 ] = F_73 ( V_3 ) ;
return 0 ;
}
static int F_88 ( struct V_223 * V_224 ,
struct V_233 * V_234 )
{
struct V_3 * V_3 = F_76 ( V_224 ) ;
int V_8 ;
if ( ! F_13 ( V_3 ) )
return - V_127 ;
V_8 = V_234 -> V_229 . V_235 . V_236 [ 0 ] ;
if ( V_8 < 0 )
V_8 = 0 ;
else if ( V_8 > 1 )
V_8 = 1 ;
F_84 ( V_3 , V_8 ) ;
return 0 ;
}
static int F_89 ( struct V_3 * V_3 )
{
switch ( V_3 -> V_111 ) {
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
static int F_90 ( struct V_3 * V_3 , int V_248 )
{
int V_28 ;
switch ( V_248 ) {
case 0 :
V_28 = 32000 ; break;
case 1 :
V_28 = 44100 ; break;
case 2 :
V_28 = 48000 ; break;
case 3 :
V_28 = 64000 ; break;
case 4 :
V_28 = 88200 ; break;
case 5 :
V_28 = 96000 ; break;
case 6 :
V_28 = 128000 ; break;
case 7 :
V_28 = 176400 ; break;
case 8 :
V_28 = 192000 ; break;
default:
V_28 = 48000 ;
}
F_44 ( V_3 , V_28 , 1 ) ;
return 0 ;
}
static int F_91 ( struct V_223 * V_224 ,
struct V_225 * V_226 )
{
V_226 -> type = V_250 ;
V_226 -> V_228 = 1 ;
V_226 -> V_229 . V_235 . V_251 = 9 ;
if ( V_226 -> V_229 . V_235 . V_236 >= V_226 -> V_229 . V_235 . V_251 )
V_226 -> V_229 . V_235 . V_236 =
V_226 -> V_229 . V_235 . V_251 - 1 ;
strcpy ( V_226 -> V_229 . V_235 . V_211 ,
V_244 [ V_226 -> V_229 . V_235 . V_236 + 1 ] ) ;
return 0 ;
}
static int F_92 ( struct V_223 * V_224 ,
struct V_233 * V_234 )
{
struct V_3 * V_3 = F_76 ( V_224 ) ;
V_234 -> V_229 . V_235 . V_236 [ 0 ] = F_89 ( V_3 ) ;
return 0 ;
}
static int F_93 ( struct V_223 * V_224 ,
struct V_233 * V_234 )
{
struct V_3 * V_3 = F_76 ( V_224 ) ;
int V_252 ;
int V_8 ;
if ( ! F_13 ( V_3 ) )
return - V_127 ;
V_8 = V_234 -> V_229 . V_235 . V_236 [ 0 ] ;
if ( V_8 < 0 )
V_8 = 0 ;
if ( V_8 > 9 )
V_8 = 9 ;
F_36 ( & V_3 -> V_25 ) ;
if ( V_8 != F_89 ( V_3 ) )
V_252 = ( F_90 ( V_3 , V_8 ) == 0 ) ? 1 : 0 ;
else
V_252 = 0 ;
F_38 ( & V_3 -> V_25 ) ;
return V_252 ;
}
static int F_94 ( struct V_3 * V_3 )
{
switch ( V_3 -> V_5 ) {
case V_37 :
switch ( V_3 -> V_29 & V_253 ) {
case 0 : return 0 ;
case V_254 : return 1 ;
case V_255 : return 2 ;
case V_255 + V_254 : return 3 ;
case V_256 : return 4 ;
case V_256 + V_254 : return 5 ;
case V_256 + V_255 : return 6 ;
case V_256 + V_255 + V_254 :
return 7 ;
case V_257 : return 8 ;
case V_257 + V_254 : return 9 ;
}
break;
case V_55 :
case V_51 :
if ( V_3 -> V_239 ) {
switch ( V_3 -> V_29 & V_253 ) {
case 0 : return 0 ;
case V_254 : return 1 ;
case V_255 : return 2 ;
case V_255 + V_254 :
return 3 ;
}
} else {
switch ( V_3 -> V_29 & V_253 ) {
case 0 : return 0 ;
case V_254 : return 1 ;
case V_255 + V_254 :
return 2 ;
}
}
break;
case V_6 :
if ( V_3 -> V_239 ) {
switch ( ( V_3 -> V_246 &
V_258 ) / V_259 ) {
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
switch ( ( V_3 -> V_246 &
V_258 ) / V_259 ) {
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
case V_4 :
if ( V_3 -> V_239 ) {
switch ( ( V_3 -> V_246 &
V_258 ) / V_259 ) {
case 0 : return 0 ;
case 3 : return 1 ;
case 1 : return 2 ;
case 2 : return 3 ;
case 9 : return 4 ;
case 10 : return 5 ;
}
} else {
switch ( ( V_3 -> V_246 &
V_258 ) / V_259 ) {
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
static int F_95 ( struct V_3 * V_3 , int V_260 )
{
int V_261 = 0 ;
switch ( V_3 -> V_5 ) {
case V_37 :
V_3 -> V_29 &= ~ V_253 ;
switch ( V_260 ) {
case 0 :
break;
case 1 :
V_3 -> V_29 |= V_254 ;
break;
case 2 :
V_3 -> V_29 |= V_255 ;
break;
case 3 :
V_3 -> V_29 |=
V_255 + V_254 ;
break;
case 4 :
V_3 -> V_29 |= V_256 ;
break;
case 5 :
V_3 -> V_29 |=
V_256 + V_254 ;
break;
case 6 :
V_3 -> V_29 |=
V_256 + V_255 ;
break;
case 7 :
V_3 -> V_29 |=
V_256 + V_255 + V_254 ;
break;
case 8 :
V_3 -> V_29 |= V_257 ;
break;
case 9 :
V_3 -> V_29 |=
V_257 + V_254 ;
break;
default:
return - 1 ;
}
break;
case V_55 :
case V_51 :
V_3 -> V_29 &= ~ V_253 ;
if ( V_3 -> V_239 ) {
switch ( V_260 ) {
case 0 :
break;
case 1 :
V_3 -> V_29 |= V_254 ;
break;
case 2 :
V_3 -> V_29 |= V_255 ;
break;
case 3 :
V_3 -> V_29 |=
V_254 + V_255 ;
break;
default:
return - 1 ;
}
} else {
switch ( V_260 ) {
case 0 :
break;
case 1 :
V_3 -> V_29 |= V_254 ;
break;
case 2 :
V_3 -> V_29 |=
V_254 + V_255 ;
break;
default:
return - 1 ;
}
}
break;
case V_6 :
if ( V_3 -> V_239 ) {
switch ( V_260 ) {
case 0 : V_261 = 0 ; break;
case 1 : V_261 = 3 ; break;
case 2 : V_261 = 4 ; break;
case 3 : V_261 = 5 ; break;
case 4 : V_261 = 6 ; break;
case 5 : V_261 = 1 ; break;
case 6 : V_261 = 2 ; break;
case 7 : V_261 = 9 ; break;
case 8 : V_261 = 10 ; break;
default: return - 1 ;
}
} else {
switch ( V_260 ) {
case 0 : V_261 = 0 ; break;
case 1 : V_261 = 3 ; break;
case 2 : V_261 = 4 ; break;
case 3 : V_261 = 5 ; break;
case 4 : V_261 = 6 ; break;
case 5 : V_261 = 1 ; break;
case 6 : V_261 = 2 ; break;
case 7 : V_261 = 10 ; break;
default: return - 1 ;
}
}
break;
case V_4 :
if ( V_3 -> V_239 ) {
switch ( V_260 ) {
case 0 : V_261 = 0 ; break;
case 1 : V_261 = 3 ; break;
case 2 : V_261 = 1 ; break;
case 3 : V_261 = 2 ; break;
case 4 : V_261 = 9 ; break;
case 5 : V_261 = 10 ; break;
default: return - 1 ;
}
} else {
switch ( V_260 ) {
case 0 : V_261 = 0 ; break;
case 1 : V_261 = 3 ; break;
case 2 : V_261 = 1 ; break;
case 3 : V_261 = 2 ; break;
case 4 : V_261 = 10 ; break;
default: return - 1 ;
}
}
break;
}
switch ( V_3 -> V_5 ) {
case V_6 :
case V_4 :
V_3 -> V_246 &= ~ V_258 ;
V_3 -> V_246 |= V_259 * V_261 ;
F_3 ( V_3 , V_262 , V_3 -> V_246 ) ;
break;
case V_55 :
case V_51 :
case V_37 :
F_3 ( V_3 , V_92 ,
V_3 -> V_29 ) ;
}
return 0 ;
}
static int F_96 ( struct V_223 * V_224 ,
struct V_225 * V_226 )
{
struct V_3 * V_3 = F_76 ( V_224 ) ;
F_97 ( V_226 , 1 , V_3 -> V_263 , V_3 -> V_264 ) ;
return 0 ;
}
static int F_98 ( struct V_223 * V_224 ,
struct V_233 * V_234 )
{
struct V_3 * V_3 = F_76 ( V_224 ) ;
int V_265 = F_94 ( V_3 ) ;
if ( V_265 >= 0 ) {
V_234 -> V_229 . V_235 . V_236 [ 0 ] = V_265 ;
return 0 ;
}
return - 1 ;
}
static int F_99 ( struct V_223 * V_224 ,
struct V_233 * V_234 )
{
struct V_3 * V_3 = F_76 ( V_224 ) ;
int V_8 , V_252 = 0 ;
if ( ! F_13 ( V_3 ) )
return - V_127 ;
V_8 = V_234 -> V_229 . V_235 . V_236 [ 0 ] ;
if ( V_8 < 0 )
V_8 = 0 ;
else if ( V_8 >= V_3 -> V_263 )
V_8 = V_3 -> V_263 - 1 ;
F_36 ( & V_3 -> V_25 ) ;
if ( V_8 != F_94 ( V_3 ) )
V_252 = ( 0 == F_95 ( V_3 , V_8 ) ) ? 1 : 0 ;
F_38 ( & V_3 -> V_25 ) ;
return V_252 ;
}
static int F_19 ( struct V_3 * V_3 )
{
if ( V_37 == V_3 -> V_5 ) {
unsigned int V_32 = F_5 ( V_3 , V_39 ) ;
unsigned int V_35 = ( V_32 >> V_266 ) & 0xF ;
if ( ( V_35 >= V_41 ) &&
( V_35 <= V_267 ) ) {
return V_35 ;
}
return V_268 ;
} else if ( V_55 == V_3 -> V_5 ) {
unsigned int V_33 = F_5 ( V_3 , V_38 ) ;
switch ( V_33 & V_68 ) {
case V_69 :
return V_269 ;
case V_270 :
return V_271 ;
case V_272 :
return V_82 ;
case V_273 :
return V_84 ;
case V_274 :
return V_110 ;
default:
return V_110 ;
}
}
return 0 ;
}
static int F_100 ( struct V_223 * V_224 ,
struct V_225 * V_226 )
{
struct V_3 * V_3 = F_76 ( V_224 ) ;
if ( V_37 == V_3 -> V_5 ) {
static const char * const V_249 [] = { L_14 , L_15 , L_16 , L_17 ,
L_18 , L_19 , L_20 , L_21 , L_22 , L_23 , L_24 , L_25 } ;
F_82 ( V_226 , V_249 ) ;
} else if ( V_55 == V_3 -> V_5 ) {
static const char * const V_249 [] = { L_26 , L_27 , L_23 ,
L_24 , L_25 } ;
F_82 ( V_226 , V_249 ) ;
}
return 0 ;
}
static int F_101 ( struct V_223 * V_224 ,
struct V_233 * V_234 )
{
struct V_3 * V_3 = F_76 ( V_224 ) ;
V_234 -> V_229 . V_235 . V_236 [ 0 ] = F_19 ( V_3 ) ;
return 0 ;
}
static int F_102 ( struct V_223 * V_224 ,
struct V_225 * V_226 )
{
static const char * const V_249 [] = { L_28 , L_29 , L_30 } ;
F_82 ( V_226 , V_249 ) ;
return 0 ;
}
static int F_103 ( struct V_223 * V_224 ,
struct V_233 * V_234 )
{
V_18 V_32 ;
int V_24 = 0 ;
struct V_3 * V_3 = F_76 ( V_224 ) ;
V_32 = F_5 ( V_3 , V_275 + 4 ) ;
switch ( V_32 & ( V_276 |
V_277 ) ) {
case V_276 :
V_24 = 1 ;
break;
case V_277 :
V_24 = 2 ;
break;
default:
V_24 = 0 ;
break;
}
V_234 -> V_229 . V_235 . V_236 [ 0 ] = V_24 ;
return 0 ;
}
static int F_104 ( struct V_223 * V_224 ,
struct V_225 * V_226 )
{
static const char * const V_249 [] = { L_31 , L_32 , L_33 , L_34 ,
L_35 } ;
F_82 ( V_226 , V_249 ) ;
return 0 ;
}
static int F_105 ( struct V_3 * V_3 )
{
V_18 V_32 ;
int V_24 = 0 ;
V_32 = F_5 ( V_3 , V_275 + 4 ) ;
if ( V_32 & V_278 ) {
switch ( V_32 & ( V_279 |
V_280 ) ) {
case 0 :
V_24 = V_281 ;
break;
case V_279 :
V_24 = V_282 ;
break;
case V_280 :
V_24 = V_283 ;
break;
default:
V_24 = V_284 ;
break;
}
}
return V_24 ;
}
static int F_106 ( struct V_223 * V_224 ,
struct V_233 * V_234 )
{
struct V_3 * V_3 = F_76 ( V_224 ) ;
V_234 -> V_229 . V_235 . V_236 [ 0 ] = F_105 ( V_3 ) ;
return 0 ;
}
static int F_107 ( struct V_3 * V_3 , V_18 V_285 )
{
V_18 V_7 ;
if ( F_2 ( V_3 ) )
V_7 = V_3 -> V_246 ;
else
V_7 = V_3 -> V_29 ;
return ( V_7 & V_285 ) ? 1 : 0 ;
}
static int F_85 ( struct V_3 * V_3 , V_18 V_285 , int V_286 )
{
V_18 * V_7 ;
V_18 V_287 ;
if ( F_2 ( V_3 ) ) {
V_7 = & ( V_3 -> V_246 ) ;
V_287 = V_262 ;
} else {
V_7 = & ( V_3 -> V_29 ) ;
V_287 = V_92 ;
}
if ( V_286 )
* V_7 |= V_285 ;
else
* V_7 &= ~ V_285 ;
F_3 ( V_3 , V_287 , * V_7 ) ;
return 0 ;
}
static int F_108 ( struct V_223 * V_224 ,
struct V_233 * V_234 )
{
struct V_3 * V_3 = F_76 ( V_224 ) ;
V_18 V_285 = V_224 -> V_245 ;
F_36 ( & V_3 -> V_25 ) ;
V_234 -> V_229 . integer . V_229 [ 0 ] = F_107 ( V_3 , V_285 ) ;
F_38 ( & V_3 -> V_25 ) ;
return 0 ;
}
static int F_109 ( struct V_223 * V_224 ,
struct V_233 * V_234 )
{
struct V_3 * V_3 = F_76 ( V_224 ) ;
V_18 V_285 = V_224 -> V_245 ;
int V_252 ;
unsigned int V_8 ;
if ( ! F_13 ( V_3 ) )
return - V_127 ;
V_8 = V_234 -> V_229 . integer . V_229 [ 0 ] & 1 ;
F_36 ( & V_3 -> V_25 ) ;
V_252 = ( int ) V_8 != F_107 ( V_3 , V_285 ) ;
F_85 ( V_3 , V_285 , V_8 ) ;
F_38 ( & V_3 -> V_25 ) ;
return V_252 ;
}
static int F_110 ( struct V_3 * V_3 )
{
return ( V_3 -> V_29 & V_288 ) ? 1 : 0 ;
}
static int F_111 ( struct V_3 * V_3 , int V_286 )
{
if ( V_286 )
V_3 -> V_29 |= V_288 ;
else
V_3 -> V_29 &= ~ V_288 ;
F_3 ( V_3 , V_92 , V_3 -> V_29 ) ;
return 0 ;
}
static int F_112 ( struct V_223 * V_224 ,
struct V_225 * V_226 )
{
static const char * const V_249 [] = { L_36 , L_37 } ;
F_82 ( V_226 , V_249 ) ;
return 0 ;
}
static int F_113 ( struct V_223 * V_224 ,
struct V_233 * V_234 )
{
struct V_3 * V_3 = F_76 ( V_224 ) ;
F_36 ( & V_3 -> V_25 ) ;
V_234 -> V_229 . V_235 . V_236 [ 0 ] = F_110 ( V_3 ) ;
F_38 ( & V_3 -> V_25 ) ;
return 0 ;
}
static int F_114 ( struct V_223 * V_224 ,
struct V_233 * V_234 )
{
struct V_3 * V_3 = F_76 ( V_224 ) ;
int V_252 ;
unsigned int V_8 ;
if ( ! F_13 ( V_3 ) )
return - V_127 ;
V_8 = V_234 -> V_229 . integer . V_229 [ 0 ] & 1 ;
F_36 ( & V_3 -> V_25 ) ;
V_252 = ( int ) V_8 != F_110 ( V_3 ) ;
F_111 ( V_3 , V_8 ) ;
F_38 ( & V_3 -> V_25 ) ;
return V_252 ;
}
static int F_115 ( struct V_3 * V_3 )
{
return ( V_3 -> V_29 & V_289 ) ? 1 : 0 ;
}
static int F_116 ( struct V_3 * V_3 , int V_290 )
{
if ( V_290 )
V_3 -> V_29 |= V_289 ;
else
V_3 -> V_29 &= ~ V_289 ;
F_3 ( V_3 , V_92 , V_3 -> V_29 ) ;
return 0 ;
}
static int F_117 ( struct V_223 * V_224 ,
struct V_225 * V_226 )
{
static const char * const V_249 [] = { L_38 , L_39 } ;
F_82 ( V_226 , V_249 ) ;
return 0 ;
}
static int F_118 ( struct V_223 * V_224 ,
struct V_233 * V_234 )
{
struct V_3 * V_3 = F_76 ( V_224 ) ;
F_36 ( & V_3 -> V_25 ) ;
V_234 -> V_229 . V_235 . V_236 [ 0 ] = F_115 ( V_3 ) ;
F_38 ( & V_3 -> V_25 ) ;
return 0 ;
}
static int F_119 ( struct V_223 * V_224 ,
struct V_233 * V_234 )
{
struct V_3 * V_3 = F_76 ( V_224 ) ;
int V_252 ;
unsigned int V_8 ;
if ( ! F_13 ( V_3 ) )
return - V_127 ;
V_8 = V_234 -> V_229 . integer . V_229 [ 0 ] & 1 ;
F_36 ( & V_3 -> V_25 ) ;
V_252 = ( int ) V_8 != F_115 ( V_3 ) ;
F_116 ( V_3 , V_8 ) ;
F_38 ( & V_3 -> V_25 ) ;
return V_252 ;
}
static int F_120 ( struct V_3 * V_3 )
{
if ( V_3 -> V_29 & V_291 )
return 1 ;
if ( V_3 -> V_29 & V_292 )
return 2 ;
return 0 ;
}
static int F_121 ( struct V_3 * V_3 , int V_248 )
{
V_3 -> V_29 &= ~ ( V_291 | V_292 ) ;
switch ( V_248 ) {
case 0 :
break;
case 1 :
V_3 -> V_29 |= V_291 ;
break;
case 2 :
V_3 -> V_29 |= V_292 ;
break;
}
F_3 ( V_3 , V_92 , V_3 -> V_29 ) ;
return 0 ;
}
static int F_122 ( struct V_223 * V_224 ,
struct V_225 * V_226 )
{
static const char * const V_249 [] = { L_38 , L_39 , L_40 } ;
F_82 ( V_226 , V_249 ) ;
return 0 ;
}
static int F_123 ( struct V_223 * V_224 ,
struct V_233 * V_234 )
{
struct V_3 * V_3 = F_76 ( V_224 ) ;
F_36 ( & V_3 -> V_25 ) ;
V_234 -> V_229 . V_235 . V_236 [ 0 ] = F_120 ( V_3 ) ;
F_38 ( & V_3 -> V_25 ) ;
return 0 ;
}
static int F_124 ( struct V_223 * V_224 ,
struct V_233 * V_234 )
{
struct V_3 * V_3 = F_76 ( V_224 ) ;
int V_252 ;
int V_8 ;
if ( ! F_13 ( V_3 ) )
return - V_127 ;
V_8 = V_234 -> V_229 . integer . V_229 [ 0 ] ;
if ( V_8 < 0 )
V_8 = 0 ;
if ( V_8 > 2 )
V_8 = 2 ;
F_36 ( & V_3 -> V_25 ) ;
V_252 = V_8 != F_120 ( V_3 ) ;
F_121 ( V_3 , V_8 ) ;
F_38 ( & V_3 -> V_25 ) ;
return V_252 ;
}
static int F_125 ( struct V_3 * V_3 , V_18 V_285 )
{
V_18 V_7 = V_3 -> V_246 & ( V_285 * 3 ) ;
return V_7 / V_285 ;
}
static int F_126 ( struct V_3 * V_3 , int V_248 , V_18 V_285 )
{
V_3 -> V_246 &= ~ ( V_285 * 3 ) ;
V_3 -> V_246 |= ( V_285 * V_248 ) ;
F_3 ( V_3 , V_262 , V_3 -> V_246 ) ;
return 0 ;
}
static int F_127 ( struct V_223 * V_224 ,
struct V_225 * V_226 )
{
V_18 V_285 = V_224 -> V_245 ;
static const char * const V_293 [] = { L_41 , L_42 , L_43 } ;
static const char * const V_294 [] = { L_44 , L_45 , L_46 } ;
switch ( V_285 ) {
case V_295 :
F_82 ( V_226 , V_293 ) ;
break;
default:
F_82 ( V_226 , V_294 ) ;
break;
}
return 0 ;
}
static int F_128 ( struct V_223 * V_224 ,
struct V_233 * V_234 )
{
struct V_3 * V_3 = F_76 ( V_224 ) ;
V_18 V_285 = V_224 -> V_245 ;
F_36 ( & V_3 -> V_25 ) ;
V_234 -> V_229 . V_235 . V_236 [ 0 ] = F_125 ( V_3 , V_285 ) ;
F_38 ( & V_3 -> V_25 ) ;
return 0 ;
}
static int F_129 ( struct V_223 * V_224 ,
struct V_233 * V_234 )
{
struct V_3 * V_3 = F_76 ( V_224 ) ;
V_18 V_285 = V_224 -> V_245 ;
int V_252 ;
int V_8 ;
if ( ! F_13 ( V_3 ) )
return - V_127 ;
V_8 = V_234 -> V_229 . integer . V_229 [ 0 ] ;
if ( V_8 < 0 )
V_8 = 0 ;
if ( V_8 > 2 )
V_8 = 2 ;
F_36 ( & V_3 -> V_25 ) ;
V_252 = V_8 != F_125 ( V_3 , V_285 ) ;
F_126 ( V_3 , V_8 , V_285 ) ;
F_38 ( & V_3 -> V_25 ) ;
return V_252 ;
}
static int F_130 ( struct V_3 * V_3 )
{
if ( V_3 -> V_29 & V_30 )
return 2 ;
if ( V_3 -> V_29 & V_31 )
return 1 ;
return 0 ;
}
static int F_131 ( struct V_3 * V_3 , int V_248 )
{
V_3 -> V_29 &= ~ ( V_31 | V_30 ) ;
switch ( V_248 ) {
case 0 :
break;
case 1 :
V_3 -> V_29 |= V_31 ;
break;
case 2 :
V_3 -> V_29 |= V_30 ;
break;
}
F_3 ( V_3 , V_92 , V_3 -> V_29 ) ;
return 0 ;
}
static int F_132 ( struct V_223 * V_224 ,
struct V_225 * V_226 )
{
static const char * const V_249 [] = { L_38 , L_39 , L_40 } ;
F_82 ( V_226 , V_249 ) ;
return 0 ;
}
static int F_133 ( struct V_223 * V_224 ,
struct V_233 * V_234 )
{
struct V_3 * V_3 = F_76 ( V_224 ) ;
F_36 ( & V_3 -> V_25 ) ;
V_234 -> V_229 . V_235 . V_236 [ 0 ] = F_130 ( V_3 ) ;
F_38 ( & V_3 -> V_25 ) ;
return 0 ;
}
static int F_134 ( struct V_223 * V_224 ,
struct V_233 * V_234 )
{
struct V_3 * V_3 = F_76 ( V_224 ) ;
int V_252 ;
int V_8 ;
if ( ! F_13 ( V_3 ) )
return - V_127 ;
V_8 = V_234 -> V_229 . integer . V_229 [ 0 ] ;
if ( V_8 < 0 )
V_8 = 0 ;
if ( V_8 > 2 )
V_8 = 2 ;
F_36 ( & V_3 -> V_25 ) ;
V_252 = V_8 != F_130 ( V_3 ) ;
F_131 ( V_3 , V_8 ) ;
F_38 ( & V_3 -> V_25 ) ;
return V_252 ;
}
static int F_135 ( struct V_223 * V_224 ,
struct V_225 * V_226 )
{
V_226 -> type = V_227 ;
V_226 -> V_228 = 3 ;
V_226 -> V_229 . integer . V_230 = 0 ;
V_226 -> V_229 . integer . V_231 = 65535 ;
V_226 -> V_229 . integer . V_232 = 1 ;
return 0 ;
}
static int F_136 ( struct V_223 * V_224 ,
struct V_233 * V_234 )
{
struct V_3 * V_3 = F_76 ( V_224 ) ;
int V_296 ;
int V_297 ;
V_296 = V_234 -> V_229 . integer . V_229 [ 0 ] ;
if ( V_296 < 0 )
V_296 = 0 ;
else if ( V_296 >= 2 * V_95 )
V_296 = 2 * V_95 - 1 ;
V_297 = V_234 -> V_229 . integer . V_229 [ 1 ] ;
if ( V_297 < 0 )
V_297 = 0 ;
else if ( V_297 >= V_95 )
V_297 = V_95 - 1 ;
F_36 ( & V_3 -> V_25 ) ;
if ( V_296 >= V_95 )
V_234 -> V_229 . integer . V_229 [ 2 ] =
F_8 ( V_3 , V_297 ,
V_296 - V_95 ) ;
else
V_234 -> V_229 . integer . V_229 [ 2 ] =
F_7 ( V_3 , V_297 , V_296 ) ;
F_38 ( & V_3 -> V_25 ) ;
return 0 ;
}
static int F_137 ( struct V_223 * V_224 ,
struct V_233 * V_234 )
{
struct V_3 * V_3 = F_76 ( V_224 ) ;
int V_252 ;
int V_296 ;
int V_297 ;
int V_156 ;
if ( ! F_13 ( V_3 ) )
return - V_127 ;
V_296 = V_234 -> V_229 . integer . V_229 [ 0 ] ;
V_297 = V_234 -> V_229 . integer . V_229 [ 1 ] ;
if ( V_296 < 0 || V_296 >= 2 * V_95 )
return - 1 ;
if ( V_297 < 0 || V_297 >= V_95 )
return - 1 ;
V_156 = V_234 -> V_229 . integer . V_229 [ 2 ] ;
F_36 ( & V_3 -> V_25 ) ;
if ( V_296 >= V_95 )
V_252 = V_156 != F_8 ( V_3 , V_297 ,
V_296 -
V_95 ) ;
else
V_252 = V_156 != F_7 ( V_3 , V_297 ,
V_296 ) ;
if ( V_252 ) {
if ( V_296 >= V_95 )
F_10 ( V_3 , V_297 ,
V_296 - V_95 ,
V_156 ) ;
else
F_9 ( V_3 , V_297 , V_296 ,
V_156 ) ;
}
F_38 ( & V_3 -> V_25 ) ;
return V_252 ;
}
static int F_138 ( struct V_223 * V_224 ,
struct V_225 * V_226 )
{
V_226 -> type = V_227 ;
V_226 -> V_228 = 1 ;
V_226 -> V_229 . integer . V_230 = 0 ;
V_226 -> V_229 . integer . V_231 = 64 ;
V_226 -> V_229 . integer . V_232 = 1 ;
return 0 ;
}
static int F_139 ( struct V_223 * V_224 ,
struct V_233 * V_234 )
{
struct V_3 * V_3 = F_76 ( V_224 ) ;
int V_298 ;
V_298 = V_234 -> V_158 . V_241 - 1 ;
if ( F_43 ( V_298 < 0 || V_298 >= V_95 ) )
return - V_124 ;
F_36 ( & V_3 -> V_25 ) ;
V_234 -> V_229 . integer . V_229 [ 0 ] =
( F_8 ( V_3 , V_298 , V_298 ) * 64 ) / V_157 ;
F_38 ( & V_3 -> V_25 ) ;
return 0 ;
}
static int F_140 ( struct V_223 * V_224 ,
struct V_233 * V_234 )
{
struct V_3 * V_3 = F_76 ( V_224 ) ;
int V_252 ;
int V_298 ;
int V_156 ;
if ( ! F_13 ( V_3 ) )
return - V_127 ;
V_298 = V_234 -> V_158 . V_241 - 1 ;
if ( F_43 ( V_298 < 0 || V_298 >= V_95 ) )
return - V_124 ;
V_156 = V_234 -> V_229 . integer . V_229 [ 0 ] * V_157 / 64 ;
F_36 ( & V_3 -> V_25 ) ;
V_252 =
V_156 != F_8 ( V_3 , V_298 ,
V_298 ) ;
if ( V_252 )
F_10 ( V_3 , V_298 , V_298 ,
V_156 ) ;
F_38 ( & V_3 -> V_25 ) ;
return V_252 ;
}
static int F_141 ( struct V_223 * V_224 ,
struct V_225 * V_226 )
{
static const char * const V_249 [] = { L_47 , L_48 , L_49 , L_50 } ;
F_82 ( V_226 , V_249 ) ;
return 0 ;
}
static int F_142 ( struct V_223 * V_224 ,
struct V_225 * V_226 )
{
static const char * const V_249 [] = { L_47 , L_48 } ;
F_82 ( V_226 , V_249 ) ;
return 0 ;
}
static int F_20 ( struct V_3 * V_3 )
{
int V_32 , V_33 ;
switch ( V_3 -> V_5 ) {
case V_37 :
V_32 = F_5 ( V_3 , V_39 ) ;
if ( V_32 & V_299 ) {
if ( V_32 & V_300 )
return 2 ;
else
return 1 ;
}
return 0 ;
break;
case V_55 :
V_33 = F_5 ( V_3 , V_38 ) ;
if ( V_33 & V_56 ) {
if ( V_33 & V_301 )
return 2 ;
else
return 1 ;
}
return 0 ;
break;
case V_6 :
case V_4 :
V_32 = F_5 ( V_3 , V_39 ) ;
if ( V_32 & 0x2000000 )
return 2 ;
else if ( V_32 & 0x1000000 )
return 1 ;
return 0 ;
break;
case V_51 :
break;
}
return 3 ;
}
static int F_143 ( struct V_3 * V_3 )
{
int V_32 = F_5 ( V_3 , V_39 ) ;
if ( V_32 & V_52 ) {
if ( V_32 & V_302 )
return 2 ;
else
return 1 ;
}
return 0 ;
}
static int F_144 ( struct V_3 * V_3 , int V_242 )
{
int V_32 , V_25 , V_303 ;
V_32 = F_5 ( V_3 , V_237 ) ;
V_25 = ( V_32 & ( 0x1 << V_242 ) ) ? 1 : 0 ;
V_303 = ( V_32 & ( 0x100 << V_242 ) ) ? 1 : 0 ;
if ( V_25 && V_303 )
return 2 ;
else if ( V_25 )
return 1 ;
return 0 ;
}
static int F_26 ( struct V_3 * V_3 )
{
int V_32 , V_25 = 0 , V_303 = 0 ;
switch ( V_3 -> V_5 ) {
case V_6 :
case V_4 :
V_32 = F_5 ( V_3 , V_304 ) ;
V_25 = ( V_32 & 0x400 ) ? 1 : 0 ;
V_303 = ( V_32 & 0x800 ) ? 1 : 0 ;
break;
case V_55 :
V_32 = F_5 ( V_3 , V_39 ) ;
V_25 = ( V_32 & V_305 ) ? 1 : 0 ;
V_303 = ( V_32 & V_306 ) ? 1 : 0 ;
break;
case V_37 :
V_32 = F_5 ( V_3 , V_38 ) ;
V_25 = ( V_32 & 0x100000 ) ? 1 : 0 ;
V_303 = ( V_32 & 0x200000 ) ? 1 : 0 ;
break;
case V_51 :
break;
}
if ( V_25 && V_303 )
return 2 ;
else if ( V_25 )
return 1 ;
return 0 ;
}
static int F_22 ( struct V_3 * V_3 , int V_242 )
{
int V_33 , V_25 , V_303 ;
V_33 = F_5 ( V_3 , V_38 ) ;
V_25 = ( V_33 & ( 0x0080 >> V_242 ) ) ? 1 : 0 ;
V_303 = ( V_33 & ( 0x8000 >> V_242 ) ) ? 1 : 0 ;
if ( V_303 )
return 2 ;
else if ( V_25 )
return 1 ;
return 0 ;
}
static int F_145 ( struct V_3 * V_3 , V_18 V_307 )
{
V_18 V_32 ;
V_32 = F_5 ( V_3 , V_275 + 4 ) ;
return ( V_32 & V_307 ) ? 1 : 0 ;
}
static int F_24 ( struct V_3 * V_3 )
{
int V_32 ;
if ( V_3 -> V_239 ) {
switch ( V_3 -> V_5 ) {
case V_55 :
V_32 = F_5 ( V_3 , V_39 ) ;
if ( V_32 & V_308 ) {
if ( V_32 & V_309 )
return 2 ;
else
return 1 ;
}
return 0 ;
break;
case V_37 :
V_32 = F_5 ( V_3 , V_39 ) ;
if ( V_32 & V_310 ) {
if ( V_32 & V_309 )
return 2 ;
else
return 1 ;
}
return 0 ;
break;
case V_6 :
case V_4 :
V_32 = F_5 ( V_3 , V_237 ) ;
if ( V_32 & 0x8000000 )
return 2 ;
if ( V_32 & 0x4000000 )
return 1 ;
return 0 ;
break;
default:
break;
}
}
return 3 ;
}
static int F_146 ( struct V_223 * V_224 ,
struct V_233 * V_234 )
{
struct V_3 * V_3 = F_76 ( V_224 ) ;
int V_8 = - 1 ;
switch ( V_3 -> V_5 ) {
case V_6 :
switch ( V_224 -> V_245 ) {
case 0 :
V_8 = F_20 ( V_3 ) ; break;
case 7 :
V_8 = F_24 ( V_3 ) ; break;
case 8 :
V_8 = F_26 ( V_3 ) ; break;
default:
V_8 = F_144 ( V_3 ,
V_224 -> V_245 - 1 ) ;
}
break;
case V_4 :
switch ( V_224 -> V_245 ) {
case 0 :
V_8 = F_20 ( V_3 ) ; break;
case 4 :
V_8 = F_24 ( V_3 ) ; break;
case 5 :
V_8 = F_26 ( V_3 ) ; break;
default:
V_8 = F_144 ( V_3 ,
V_224 -> V_245 - 1 ) ;
}
break;
case V_55 :
switch ( V_224 -> V_245 ) {
case 0 :
V_8 = F_20 ( V_3 ) ; break;
case 1 :
V_8 = F_143 ( V_3 ) ; break;
case 2 :
V_8 = F_24 ( V_3 ) ; break;
case 3 :
V_8 = F_26 ( V_3 ) ; break;
}
break;
case V_51 :
V_8 = F_143 ( V_3 ) ;
break;
case V_37 :
switch ( V_224 -> V_245 ) {
case 0 :
V_8 = F_20 ( V_3 ) ; break;
case 9 :
V_8 = F_24 ( V_3 ) ; break;
case 10 :
V_8 = F_26 ( V_3 ) ; break;
default:
V_8 = F_22 ( V_3 ,
V_224 -> V_245 - 1 ) ;
}
break;
}
if ( V_3 -> V_239 ) {
switch ( V_224 -> V_245 ) {
case 11 :
V_8 = F_145 ( V_3 , V_311 ) ;
break;
case 12 :
V_8 = F_145 ( V_3 ,
V_278 ) ;
break;
default:
break;
}
}
if ( - 1 == V_8 )
V_8 = 3 ;
V_234 -> V_229 . V_235 . V_236 [ 0 ] = V_8 ;
return 0 ;
}
static void F_147 ( struct V_3 * V_3 )
{
unsigned int V_312 [ 4 ] = { 0 , 0 , 0 , 0 } ;
switch ( V_3 -> V_239 -> V_170 ) {
case 0 :
V_312 [ 2 ] |= V_313 ;
break;
case 1 :
V_312 [ 2 ] |= V_314 ;
break;
default:
break;
}
switch ( V_3 -> V_239 -> V_315 ) {
case 1 :
V_312 [ 1 ] |= V_279 ;
break;
case 2 :
V_312 [ 1 ] |= V_280 ;
break;
case 3 :
V_312 [ 1 ] |= V_280 +
V_316 ;
break;
case 4 :
V_312 [ 1 ] |= V_279 +
V_280 ;
break;
case 5 :
V_312 [ 1 ] |= V_279 +
V_280 +
V_316 ;
break;
default:
break;
}
switch ( V_3 -> V_239 -> V_317 ) {
case 1 :
V_312 [ 2 ] |= V_318 ;
break;
case 2 :
V_312 [ 2 ] |= V_319 ;
break;
default:
break;
}
switch ( V_3 -> V_239 -> V_320 ) {
case 1 :
V_312 [ 2 ] |= V_321 ;
break;
case 2 :
V_312 [ 2 ] |= V_322 ;
break;
default:
break;
}
switch ( V_3 -> V_239 -> V_323 ) {
case 1 :
V_312 [ 2 ] |= V_324 ;
break;
case 2 :
V_312 [ 2 ] |= V_325 ;
break;
case 3 :
V_312 [ 2 ] |= V_324 + V_326 ;
break;
case 4 :
V_312 [ 2 ] |= V_325 + V_326 ;
break;
default:
break;
}
if ( 1 == V_3 -> V_239 -> V_327 ) {
V_312 [ 2 ] |= V_328 ;
}
F_3 ( V_3 , V_329 , V_312 [ 0 ] ) ;
F_3 ( V_3 , V_329 + 4 , V_312 [ 1 ] ) ;
F_3 ( V_3 , V_329 + 8 , V_312 [ 2 ] ) ;
F_3 ( V_3 , V_329 + 12 , V_312 [ 3 ] ) ;
}
static int F_148 ( struct V_223 * V_224 ,
struct V_225 * V_226 )
{
static const char * const V_249 [] = { L_51 , L_52 } ;
F_82 ( V_226 , V_249 ) ;
return 0 ;
}
static int F_149 ( struct V_223 * V_224 ,
struct V_233 * V_234 )
{
struct V_3 * V_3 = F_76 ( V_224 ) ;
V_234 -> V_229 . V_235 . V_236 [ 0 ] = V_3 -> V_239 -> V_320 ;
return 0 ;
}
static int F_150 ( struct V_223 * V_224 ,
struct V_233 * V_234 )
{
struct V_3 * V_3 = F_76 ( V_224 ) ;
if ( V_3 -> V_239 -> V_320 != V_234 -> V_229 . V_235 . V_236 [ 0 ] ) {
V_3 -> V_239 -> V_320 = V_234 -> V_229 . V_235 . V_236 [ 0 ] ;
F_147 ( V_3 ) ;
return 1 ;
}
return 0 ;
}
static int F_151 ( struct V_223 * V_224 ,
struct V_225 * V_226 )
{
static const char * const V_249 [] = { L_53 , L_54 , L_55 ,
L_56 , L_57 } ;
F_82 ( V_226 , V_249 ) ;
return 0 ;
}
static int F_152 ( struct V_223 * V_224 ,
struct V_233 * V_234 )
{
struct V_3 * V_3 = F_76 ( V_224 ) ;
V_234 -> V_229 . V_235 . V_236 [ 0 ] = V_3 -> V_239 -> V_323 ;
return 0 ;
}
static int F_153 ( struct V_223 * V_224 ,
struct V_233 * V_234 )
{
struct V_3 * V_3 = F_76 ( V_224 ) ;
if ( V_3 -> V_239 -> V_323 != V_234 -> V_229 . V_235 . V_236 [ 0 ] ) {
V_3 -> V_239 -> V_323 = V_234 -> V_229 . V_235 . V_236 [ 0 ] ;
F_147 ( V_3 ) ;
return 1 ;
}
return 0 ;
}
static int F_154 ( struct V_223 * V_224 ,
struct V_225 * V_226 )
{
static const char * const V_249 [] = { L_58 , L_59 , L_60 } ;
F_82 ( V_226 , V_249 ) ;
return 0 ;
}
static int F_155 ( struct V_223 * V_224 ,
struct V_233 * V_234 )
{
struct V_3 * V_3 = F_76 ( V_224 ) ;
V_234 -> V_229 . V_235 . V_236 [ 0 ] = V_3 -> V_239 -> V_317 ;
return 0 ;
}
static int F_156 ( struct V_223 * V_224 ,
struct V_233 * V_234 )
{
struct V_3 * V_3 = F_76 ( V_224 ) ;
if ( V_3 -> V_239 -> V_317 != V_234 -> V_229 . V_235 . V_236 [ 0 ] ) {
V_3 -> V_239 -> V_317 = V_234 -> V_229 . V_235 . V_236 [ 0 ] ;
F_147 ( V_3 ) ;
return 1 ;
}
return 0 ;
}
static int F_157 ( struct V_223 * V_224 ,
struct V_225 * V_226 )
{
static const char * const V_249 [] = { L_32 , L_33 , L_61 ,
L_62 , L_35 , L_63 } ;
F_82 ( V_226 , V_249 ) ;
return 0 ;
}
static int F_158 ( struct V_223 * V_224 ,
struct V_233 * V_234 )
{
struct V_3 * V_3 = F_76 ( V_224 ) ;
V_234 -> V_229 . V_235 . V_236 [ 0 ] = V_3 -> V_239 -> V_315 ;
return 0 ;
}
static int F_159 ( struct V_223 * V_224 ,
struct V_233 * V_234 )
{
struct V_3 * V_3 = F_76 ( V_224 ) ;
if ( V_3 -> V_239 -> V_315 != V_234 -> V_229 . V_235 . V_236 [ 0 ] ) {
V_3 -> V_239 -> V_315 = V_234 -> V_229 . V_235 . V_236 [ 0 ] ;
F_147 ( V_3 ) ;
return 1 ;
}
return 0 ;
}
static int F_160 ( struct V_223 * V_224 ,
struct V_225 * V_226 )
{
static const char * const V_249 [] = { L_64 , L_65 , L_66 } ;
F_82 ( V_226 , V_249 ) ;
return 0 ;
}
static int F_161 ( struct V_223 * V_224 ,
struct V_233 * V_234 )
{
struct V_3 * V_3 = F_76 ( V_224 ) ;
V_234 -> V_229 . V_235 . V_236 [ 0 ] = V_3 -> V_239 -> V_170 ;
return 0 ;
}
static int F_162 ( struct V_223 * V_224 ,
struct V_233 * V_234 )
{
struct V_3 * V_3 = F_76 ( V_224 ) ;
if ( V_3 -> V_239 -> V_170 != V_234 -> V_229 . V_235 . V_236 [ 0 ] ) {
V_3 -> V_239 -> V_170 = V_234 -> V_229 . V_235 . V_236 [ 0 ] ;
F_147 ( V_3 ) ;
return 1 ;
}
return 0 ;
}
static int F_163 ( struct V_223 * V_224 ,
struct V_225 * V_226 )
{
V_226 -> type = V_330 ;
V_226 -> V_228 = 1 ;
V_226 -> V_229 . integer . V_230 = 0 ;
V_226 -> V_229 . integer . V_231 = 1 ;
return 0 ;
}
static int F_164 ( struct V_223 * V_224 ,
struct V_233 * V_234 )
{
struct V_3 * V_3 = F_76 ( V_224 ) ;
V_234 -> V_229 . V_235 . V_236 [ 0 ] = V_3 -> V_239 -> V_327 ;
return 0 ;
}
static int F_165 ( struct V_223 * V_224 ,
struct V_233 * V_234 )
{
struct V_3 * V_3 = F_76 ( V_224 ) ;
if ( V_3 -> V_239 -> V_327 != V_234 -> V_229 . V_235 . V_236 [ 0 ] ) {
V_3 -> V_239 -> V_327 = V_234 -> V_229 . V_235 . V_236 [ 0 ] ;
F_147 ( V_3 ) ;
return 1 ;
}
return 0 ;
}
static int F_166 ( struct V_3 * V_3 )
{
int V_19 ;
for ( V_19 = V_3 -> V_145 ; V_19 < V_3 -> V_137 ; ++ V_19 ) {
if ( V_3 -> V_111 > 48000 ) {
V_3 -> V_331 [ V_19 ] -> V_332 [ 0 ] . V_333 =
V_334 |
V_335 |
V_336 ;
} else {
V_3 -> V_331 [ V_19 ] -> V_332 [ 0 ] . V_333 =
V_337 |
V_336 ;
}
F_167 ( V_3 -> V_184 , V_338 |
V_339 ,
& V_3 -> V_331 [ V_19 ] -> V_158 ) ;
}
return 0 ;
}
static int F_168 ( struct V_183 * V_184 ,
struct V_3 * V_3 )
{
unsigned int V_242 , V_340 ;
int V_185 ;
struct V_223 * V_341 ;
struct V_342 * V_343 = NULL ;
switch ( V_3 -> V_5 ) {
case V_55 :
V_343 = V_344 ;
V_340 = F_169 ( V_344 ) ;
break;
case V_51 :
V_343 = V_345 ;
V_340 = F_169 ( V_345 ) ;
break;
case V_4 :
V_343 = V_346 ;
V_340 = F_169 ( V_346 ) ;
break;
case V_6 :
V_343 = V_347 ;
V_340 = F_169 ( V_347 ) ;
break;
case V_37 :
V_343 = V_348 ;
V_340 = F_169 ( V_348 ) ;
break;
}
if ( NULL != V_343 ) {
for ( V_242 = 0 ; V_242 < V_340 ; V_242 ++ ) {
V_185 = F_170 ( V_184 ,
F_171 ( & V_343 [ V_242 ] , V_3 ) ) ;
if ( V_185 < 0 )
return V_185 ;
}
}
V_349 . V_211 = L_67 ;
if ( V_3 -> V_111 >= 128000 ) {
V_340 = V_3 -> V_151 ;
} else if ( V_3 -> V_111 >= 64000 ) {
V_340 = V_3 -> V_145 ;
} else {
V_340 = V_3 -> V_137 ;
}
for ( V_242 = 0 ; V_242 < V_340 ; ++ V_242 ) {
V_349 . V_241 = V_242 + 1 ;
V_341 = F_171 ( & V_349 , V_3 ) ;
V_185 = F_170 ( V_184 , V_341 ) ;
if ( V_185 < 0 )
return V_185 ;
V_3 -> V_331 [ V_242 ] = V_341 ;
}
if ( V_3 -> V_239 ) {
V_343 = V_350 ;
V_340 = F_169 ( V_350 ) ;
for ( V_242 = 0 ; V_242 < V_340 ; V_242 ++ ) {
V_185 = F_170 ( V_184 ,
F_171 ( & V_343 [ V_242 ] , V_3 ) ) ;
if ( V_185 < 0 )
return V_185 ;
}
}
return 0 ;
}
static void
F_172 ( struct V_351 * V_352 ,
struct V_353 * V_354 )
{
struct V_3 * V_3 = V_352 -> V_177 ;
unsigned int V_32 , V_355 ;
int V_356 , V_357 , V_97 , V_358 , V_359 , V_360 ;
unsigned int V_99 ;
T_2 V_100 = 0 ;
V_18 V_28 ;
F_173 ( V_354 , L_68 ) ;
V_32 = F_5 ( V_3 , V_39 ) ;
V_355 = V_3 -> V_29 ;
if ( V_32 & V_361 ) {
F_173 ( V_354 , L_69 ) ;
V_356 = F_5 ( V_3 , V_275 + 4 ) ;
if ( V_356 & V_278 ) {
F_173 ( V_354 , L_70 ) ;
switch ( V_356 & ( V_279 |
V_280 ) ) {
case 0 :
F_173 ( V_354 , L_71 ) ;
break;
case V_279 :
F_173 ( V_354 , L_72 ) ;
break;
case V_280 :
F_173 ( V_354 , L_73 ) ;
break;
default:
F_173 ( V_354 , L_74 ) ;
break;
}
if ( V_356 & V_316 ) {
F_173 ( V_354 , L_75 ) ;
} else {
F_173 ( V_354 , L_76 ) ;
}
} else {
F_173 ( V_354 , L_77 ) ;
}
if ( V_356 & V_276 ) {
F_173 ( V_354 , L_78 ) ;
} else if ( V_356 & V_277 ) {
F_173 ( V_354 , L_79 ) ;
} else {
F_173 ( V_354 , L_80 ) ;
}
if ( V_356 & V_311 ) {
F_173 ( V_354 , L_81 ) ;
} else {
F_173 ( V_354 , L_82 ) ;
}
switch ( V_3 -> V_5 ) {
case V_55 :
case V_37 :
V_100 = 110069313433624ULL ;
break;
case V_6 :
case V_4 :
V_100 = 104857600000000ULL ;
break;
case V_51 :
break;
}
V_99 = F_5 ( V_3 , V_222 ) ;
F_173 ( V_354 , L_83 , V_99 ) ;
V_28 = F_41 ( V_100 , V_99 ) ;
if ( V_355 & V_30 ) {
V_28 *= 4 ;
} else if ( V_355 & V_31 ) {
V_28 *= 2 ;
}
F_173 ( V_354 , L_84 ,
( unsigned int ) V_28 ) ;
V_357 = F_5 ( V_3 , V_275 ) ;
V_97 = V_357 & 0xF ;
V_357 >>= 4 ;
V_97 += ( V_357 & 0x3 ) * 10 ;
V_357 >>= 4 ;
V_358 = V_357 & 0xF ;
V_357 >>= 4 ;
V_358 += ( V_357 & 0x7 ) * 10 ;
V_357 >>= 4 ;
V_359 = V_357 & 0xF ;
V_357 >>= 4 ;
V_359 += ( V_357 & 0x7 ) * 10 ;
V_357 >>= 4 ;
V_360 = V_357 & 0xF ;
V_357 >>= 4 ;
V_360 += ( V_357 & 0x3 ) * 10 ;
F_173 ( V_354 ,
L_85 ,
V_360 , V_359 , V_358 , V_97 ) ;
} else {
F_173 ( V_354 , L_86 ) ;
}
}
static void
F_174 ( struct V_351 * V_352 ,
struct V_353 * V_354 )
{
struct V_3 * V_3 = V_352 -> V_177 ;
unsigned int V_32 , V_33 , V_355 , V_362 ;
char * V_363 ;
char * V_364 ;
char * V_365 ;
char * V_366 ;
int V_367 , V_368 ;
V_32 = F_5 ( V_3 , V_39 ) ;
V_33 = F_5 ( V_3 , V_38 ) ;
V_355 = V_3 -> V_29 ;
V_362 = F_5 ( V_3 , V_40 ) ;
F_173 ( V_354 , L_87 ,
V_3 -> V_369 , V_3 -> V_184 -> V_370 + 1 ,
V_3 -> V_371 ,
( V_33 & V_372 ) |
( V_33 & V_373 ) | ( V_33 &
V_374 ) ) ;
F_173 ( V_354 , L_88 ,
( F_5 ( V_3 , V_200 ) >> 8 ) & 0xFFFFFF ,
V_3 -> V_375 ) ;
F_173 ( V_354 , L_89 ,
V_3 -> V_191 , V_3 -> V_376 , ( unsigned long ) V_3 -> V_9 ) ;
F_173 ( V_354 , L_90 ) ;
F_173 ( V_354 ,
L_91 ,
V_32 & V_377 ,
( V_32 & V_198 ) ? 1 : 0 ,
( V_32 & V_204 ) ? 1 : 0 ,
V_3 -> V_378 ) ;
F_173 ( V_354 ,
L_92
L_93 ,
( ( V_32 & V_88 ) ? 1 : 0 ) ,
( V_32 & V_87 ) ,
( V_32 & V_87 ) %
( 2 * ( int ) V_3 -> V_85 ) ,
( ( V_32 & V_87 ) - 64 ) %
( 2 * ( int ) V_3 -> V_85 ) ,
( long ) F_31 ( V_3 ) * 4 ) ;
F_173 ( V_354 ,
L_94 ,
F_5 ( V_3 , V_196 ) & 0xFF ,
F_5 ( V_3 , V_202 ) & 0xFF ,
F_5 ( V_3 , V_194 ) & 0xFF ,
F_5 ( V_3 , V_200 ) & 0xFF ) ;
F_173 ( V_354 ,
L_95 ,
F_5 ( V_3 , V_187 ) & 0xFF ,
F_5 ( V_3 , V_189 ) & 0xFF ) ;
F_173 ( V_354 ,
L_96
L_97 ,
V_3 -> V_29 , V_3 -> V_379 ,
V_32 , V_33 ) ;
F_173 ( V_354 , L_98 ) ;
V_367 = F_28 ( V_3 ) ;
F_173 ( V_354 ,
L_99 ,
V_367 , ( unsigned long ) V_3 -> V_85 ) ;
F_173 ( V_354 , L_100 ,
( V_3 -> V_29 & V_380 ) ? L_101 : L_102 ) ;
switch ( V_3 -> V_29 & V_381 ) {
case V_382 :
V_366 = L_41 ;
break;
case V_383 :
V_366 = L_42 ;
break;
default:
V_366 = L_103 ;
}
F_173 ( V_354 ,
L_104
L_105 ,
( V_3 -> V_29 & V_384 ) ? L_106 : L_102 ,
( V_3 -> V_29 & V_385 ) ? L_107 : L_108 ,
( V_3 -> V_29 & V_386 ) ? L_106 : L_102 ) ;
if ( ! ( V_3 -> V_29 & V_107 ) )
V_365 = L_13 ;
else
V_365 = L_12 ;
F_173 ( V_354 , L_109 , V_365 ) ;
switch ( F_94 ( V_3 ) ) {
case V_387 :
V_363 = L_26 ;
break;
case V_388 :
V_363 = L_110 ;
break;
case V_389 :
V_363 = L_23 ;
break;
case V_390 :
V_363 = L_24 ;
break;
default:
V_363 = L_111 ;
break;
}
F_173 ( V_354 , L_112 ,
V_363 ) ;
F_173 ( V_354 , L_113 ,
V_3 -> V_111 ) ;
F_173 ( V_354 , L_114 ) ;
V_367 = V_32 & V_302 ;
V_368 = V_33 & V_301 ;
F_173 ( V_354 , L_115 ,
( V_32 & V_52 ) ? ( V_367 ? L_49 : L_48 ) :
L_116 ,
( V_33 & V_56 ) ? ( V_368 ? L_49 : L_48 ) :
L_116 ) ;
switch ( F_19 ( V_3 ) ) {
case V_84 :
V_364 = L_24 ;
break;
case V_82 :
V_364 = L_23 ;
break;
case V_269 :
V_364 = L_26 ;
break;
case V_271 :
V_364 = L_110 ;
break;
case V_110 :
V_364 = L_117 ;
break;
default:
V_364 = L_118 ;
break;
}
F_173 ( V_354 ,
L_119 ,
V_364 , F_18 ( V_3 ) ,
( V_32 & V_70 ) >> 22 ,
( V_33 & V_58 ) >> 5 ) ;
F_173 ( V_354 , L_120 ,
( V_32 & V_391 ) ? L_121 : L_41 ,
( V_32 & V_392 ) ? L_122 :
L_123 ) ;
F_172 ( V_352 , V_354 ) ;
F_173 ( V_354 , L_124 ) ;
}
static void
F_175 ( struct V_351 * V_352 ,
struct V_353 * V_354 )
{
struct V_3 * V_3 = V_352 -> V_177 ;
unsigned int V_32 ;
unsigned int V_33 ;
unsigned int V_34 ;
unsigned int V_393 , V_394 ;
int V_395 ;
char * V_364 ;
int V_367 ;
V_32 = F_5 ( V_3 , V_39 ) ;
V_33 = F_5 ( V_3 , V_38 ) ;
V_34 = F_5 ( V_3 , V_40 ) ;
F_173 ( V_354 , L_125 ,
V_3 -> V_369 , V_3 -> V_184 -> V_370 + 1 ,
V_3 -> V_371 ) ;
F_173 ( V_354 , L_89 ,
V_3 -> V_191 , V_3 -> V_376 , ( unsigned long ) V_3 -> V_9 ) ;
F_173 ( V_354 , L_90 ) ;
F_173 ( V_354 ,
L_91 ,
V_32 & V_377 ,
( V_32 & V_198 ) ? 1 : 0 ,
( V_32 & V_204 ) ? 1 : 0 ,
V_3 -> V_378 ) ;
F_173 ( V_354 ,
L_92
L_93 ,
( ( V_32 & V_88 ) ? 1 : 0 ) ,
( V_32 & V_87 ) ,
( V_32 & V_87 ) %
( 2 * ( int ) V_3 -> V_85 ) ,
( ( V_32 & V_87 ) - 64 ) %
( 2 * ( int ) V_3 -> V_85 ) ,
( long ) F_31 ( V_3 ) * 4 ) ;
F_173 ( V_354 ,
L_94 ,
F_5 ( V_3 , V_196 ) & 0xFF ,
F_5 ( V_3 , V_202 ) & 0xFF ,
F_5 ( V_3 , V_194 ) & 0xFF ,
F_5 ( V_3 , V_200 ) & 0xFF ) ;
F_173 ( V_354 ,
L_95 ,
F_5 ( V_3 , V_187 ) & 0xFF ,
F_5 ( V_3 , V_189 ) & 0xFF ) ;
F_173 ( V_354 ,
L_96
L_97 ,
V_3 -> V_29 , V_3 -> V_379 ,
V_32 , V_33 ) ;
F_173 ( V_354 , L_98 ) ;
V_367 = F_28 ( V_3 ) ;
F_173 ( V_354 ,
L_99 ,
V_367 , ( unsigned long ) V_3 -> V_85 ) ;
F_173 ( V_354 , L_100 ,
( V_3 ->
V_29 & V_380 ) ? L_101 : L_102 ) ;
F_173 ( V_354 ,
L_126 ,
( V_3 ->
V_29 & V_384 ) ? L_106 : L_102 ,
( V_3 ->
V_29 & V_396 ) ? L_106 : L_102 ,
( V_3 ->
V_29 & V_397 ) ? L_106 : L_102 ) ;
V_395 = F_94 ( V_3 ) ;
if ( V_395 == 0 )
F_173 ( V_354 , L_127 ) ;
else
F_173 ( V_354 , L_128 ,
V_395 ) ;
F_173 ( V_354 , L_113 ,
V_3 -> V_111 ) ;
F_173 ( V_354 , L_129 ,
V_3 -> V_29 & V_289 ?
L_130 : L_131 ) ;
F_173 ( V_354 , L_132 ,
V_3 -> V_29 & V_291 ?
L_130 :
V_3 -> V_29 & V_292 ?
L_133 : L_131 ) ;
F_173 ( V_354 , L_114 ) ;
V_393 = V_32 & V_299 ;
V_394 = V_393 && ( V_32 & V_300 ) ;
F_173 ( V_354 , L_134 ,
( V_393 ) ? ( V_394 ? L_135 : L_136 ) : L_47 ,
F_1 ( ( V_32 >> V_238 ) & 0xF ) ) ;
for ( V_367 = 0 ; V_367 < 8 ; V_367 ++ ) {
F_173 ( V_354 , L_137 ,
V_367 + 1 ,
( V_33 & ( V_398 >> V_367 ) ) ?
L_135 : L_47 ,
F_1 ( ( V_34 >> ( 4 * V_367 ) ) & 0xF ) ) ;
}
switch ( F_19 ( V_3 ) ) {
case V_268 :
V_364 = L_25 ; break;
case V_41 :
V_364 = L_26 ; break;
case V_42 :
V_364 = L_15 ; break;
case V_43 :
V_364 = L_16 ; break;
case V_44 :
V_364 = L_17 ; break;
case V_45 :
V_364 = L_18 ; break;
case V_46 :
V_364 = L_19 ; break;
case V_47 :
V_364 = L_20 ; break;
case V_48 :
V_364 = L_21 ; break;
case V_49 :
V_364 = L_22 ; break;
case V_50 :
V_364 = L_23 ; break;
case V_267 :
V_364 = L_24 ; break;
default:
V_364 = L_118 ; break;
}
F_173 ( V_354 , L_138 , V_364 ) ;
F_172 ( V_352 , V_354 ) ;
F_173 ( V_354 , L_124 ) ;
}
static void
F_176 ( struct V_351 * V_352 ,
struct V_353 * V_354 )
{
struct V_3 * V_3 = V_352 -> V_177 ;
unsigned int V_399 , V_33 , V_400 , V_355 , V_19 ;
unsigned int V_25 , V_303 ;
V_399 = F_5 ( V_3 , V_237 ) ;
V_33 = F_5 ( V_3 , V_240 ) ;
V_400 = F_5 ( V_3 , V_304 ) ;
V_355 = V_3 -> V_29 ;
F_173 ( V_354 , L_139 , V_399 ) ;
F_173 ( V_354 , L_140 , V_33 ) ;
F_173 ( V_354 , L_141 , V_400 ) ;
F_173 ( V_354 , L_142 ) ;
F_173 ( V_354 , L_143 ,
( F_73 ( V_3 ) == 0 ) ? L_144 : L_145 ) ;
F_173 ( V_354 , L_146 ,
F_72 ( V_3 ) ) ;
F_173 ( V_354 , L_147 ) ;
V_25 = 0x1 ;
V_303 = 0x100 ;
for ( V_19 = 0 ; V_19 < 8 ; V_19 ++ ) {
F_173 ( V_354 , L_148 ,
V_19 ,
( V_399 & V_25 ) ? 1 : 0 ,
( V_399 & V_303 ) ? 1 : 0 ,
V_244 [ ( V_33 >> ( V_19 * 4 ) ) & 0xF ] ) ;
V_25 = V_25 << 1 ;
V_303 = V_303 << 1 ;
}
F_173 ( V_354 , L_149 ,
( V_399 & 0x1000000 ) ? 1 : 0 ,
( V_399 & 0x2000000 ) ? 1 : 0 ,
V_244 [ ( V_399 >> 16 ) & 0xF ] ) ;
F_173 ( V_354 , L_150 ,
( V_399 & 0x4000000 ) ? 1 : 0 ,
( V_399 & 0x8000000 ) ? 1 : 0 ,
V_244 [ ( V_399 >> 20 ) & 0xF ] ) ;
F_173 ( V_354 , L_151 ,
( V_400 & 0x400 ) ? 1 : 0 ,
( V_400 & 0x800 ) ? 1 : 0 ,
V_244 [ ( V_33 >> 12 ) & 0xF ] ) ;
}
static void
F_177 ( struct V_351 * V_352 ,
struct V_353 * V_354 )
{
struct V_3 * V_3 = V_352 -> V_177 ;
int V_155 , V_19 ;
for ( V_19 = 0 ; V_19 < 256 ; V_19 += V_155 ) {
F_173 ( V_354 , L_152 , V_19 ) ;
for ( V_155 = 0 ; V_155 < 16 ; V_155 += 4 )
F_173 ( V_354 , L_153 , F_5 ( V_3 , V_19 + V_155 ) ) ;
F_173 ( V_354 , L_124 ) ;
}
}
static void F_178 ( struct V_351 * V_352 ,
struct V_353 * V_354 )
{
struct V_3 * V_3 = V_352 -> V_177 ;
int V_19 ;
F_173 ( V_354 , L_154 ) ;
for ( V_19 = 0 ; V_19 < V_3 -> V_134 ; V_19 ++ ) {
F_173 ( V_354 , L_155 , V_19 + 1 , V_3 -> V_138 [ V_19 ] ) ;
}
}
static void F_179 ( struct V_351 * V_352 ,
struct V_353 * V_354 )
{
struct V_3 * V_3 = V_352 -> V_177 ;
int V_19 ;
F_173 ( V_354 , L_154 ) ;
for ( V_19 = 0 ; V_19 < V_3 -> V_136 ; V_19 ++ ) {
F_173 ( V_354 , L_155 , V_19 + 1 , V_3 -> V_140 [ V_19 ] ) ;
}
}
static void F_180 ( struct V_3 * V_3 )
{
struct V_351 * V_352 ;
if ( ! F_181 ( V_3 -> V_184 , L_156 , & V_352 ) ) {
switch ( V_3 -> V_5 ) {
case V_37 :
F_182 ( V_352 , V_3 ,
F_175 ) ;
break;
case V_55 :
F_182 ( V_352 , V_3 ,
F_174 ) ;
break;
case V_51 :
break;
case V_6 :
F_182 ( V_352 , V_3 ,
F_176 ) ;
break;
case V_4 :
break;
}
}
if ( ! F_181 ( V_3 -> V_184 , L_157 , & V_352 ) ) {
F_182 ( V_352 , V_3 , F_178 ) ;
}
if ( ! F_181 ( V_3 -> V_184 , L_158 , & V_352 ) ) {
F_182 ( V_352 , V_3 , F_179 ) ;
}
#ifdef F_183
if ( ! F_181 ( V_3 -> V_184 , L_159 , & V_352 ) )
F_182 ( V_352 , V_3 ,
F_177 ) ;
#endif
}
static int F_184 ( struct V_3 * V_3 )
{
V_3 -> V_246 = 0 ;
switch ( V_3 -> V_5 ) {
case V_55 :
case V_51 :
V_3 -> V_29 =
0x2 + 0x8 + 0x10 + 0x80 + 0x400 + 0x4000 + 0x1000000 ;
break;
case V_6 :
case V_4 :
V_3 -> V_246 = 0x1 + 0x1000 ;
V_3 -> V_29 =
0x2 + 0x8 + 0x10 + 0x80 + 0x400 + 0x4000 + 0x1000000 ;
break;
case V_37 :
V_3 -> V_29 =
V_107 |
F_37 ( 7 ) |
V_254 |
V_380 |
V_401 ;
break;
}
F_3 ( V_3 , V_92 , V_3 -> V_29 ) ;
if ( V_37 == V_3 -> V_5 ) {
#ifdef F_185
V_3 -> V_379 = V_402 ;
#else
V_3 -> V_379 = 0 ;
#endif
F_3 ( V_3 , V_403 , V_3 -> V_379 ) ;
}
F_30 ( V_3 ) ;
F_46 ( V_3 , 0 * V_157 ) ;
if ( F_2 ( V_3 ) )
F_3 ( V_3 , V_262 , V_3 -> V_246 ) ;
F_44 ( V_3 , 48000 , 1 ) ;
return 0 ;
}
static T_3 F_186 ( int V_191 , void * V_404 )
{
struct V_3 * V_3 = (struct V_3 * ) V_404 ;
unsigned int V_32 ;
int V_19 , V_405 , V_159 , V_406 = 0 ;
V_32 = F_5 ( V_3 , V_39 ) ;
V_405 = V_32 & V_377 ;
V_159 = V_32 & ( V_198 | V_204 |
V_192 | V_209 ) ;
if ( ! V_405 && ! V_159 )
return V_407 ;
F_3 ( V_3 , V_408 , 0 ) ;
V_3 -> V_378 ++ ;
if ( V_405 ) {
if ( V_3 -> V_409 )
F_187 ( V_3 -> V_409 ) ;
if ( V_3 -> V_410 )
F_187 ( V_3 -> V_410 ) ;
}
if ( V_159 ) {
V_19 = 0 ;
while ( V_19 < V_3 -> V_221 ) {
if ( ( F_5 ( V_3 ,
V_3 -> V_159 [ V_19 ] . V_162 ) & 0xff ) &&
( V_32 & V_3 -> V_159 [ V_19 ] . V_191 ) ) {
V_3 -> V_29 &= ~ V_3 -> V_159 [ V_19 ] . V_172 ;
F_3 ( V_3 , V_92 ,
V_3 -> V_29 ) ;
V_3 -> V_159 [ V_19 ] . V_171 = 1 ;
V_406 = 1 ;
}
V_19 ++ ;
}
if ( V_406 )
F_188 ( & V_3 -> V_411 ) ;
}
return V_412 ;
}
static T_1 F_189 ( struct V_413
* V_174 )
{
struct V_3 * V_3 = F_190 ( V_174 ) ;
return F_31 ( V_3 ) ;
}
static int F_191 ( struct V_413 * V_174 )
{
struct V_414 * V_415 = V_174 -> V_415 ;
struct V_3 * V_3 = F_190 ( V_174 ) ;
struct V_413 * V_416 ;
if ( V_174 -> V_417 == V_418 )
V_416 = V_3 -> V_409 ;
else
V_416 = V_3 -> V_410 ;
if ( V_3 -> V_419 )
V_415 -> V_32 -> V_420 = F_31 ( V_3 ) ;
else
V_415 -> V_32 -> V_420 = 0 ;
if ( V_416 ) {
struct V_413 * V_89 ;
struct V_414 * V_421 = V_416 -> V_415 ;
F_192 (s, substream) {
if ( V_89 == V_416 ) {
V_421 -> V_32 -> V_420 =
V_415 -> V_32 -> V_420 ;
break;
}
}
}
return 0 ;
}
static int F_193 ( struct V_413 * V_174 ,
struct V_422 * V_423 )
{
struct V_3 * V_3 = F_190 ( V_174 ) ;
int V_185 ;
int V_19 ;
T_4 V_424 ;
T_4 V_425 ;
F_36 ( & V_3 -> V_25 ) ;
if ( V_174 -> V_426 -> V_417 == V_418 ) {
V_424 = V_3 -> V_26 ;
V_425 = V_3 -> V_27 ;
} else {
V_424 = V_3 -> V_27 ;
V_425 = V_3 -> V_26 ;
}
if ( V_425 > 0 && V_424 != V_425 ) {
if ( F_194 ( V_423 ) != V_3 -> V_111 ) {
F_38 ( & V_3 -> V_25 ) ;
F_195 ( V_423 ,
V_427 ) ;
return - V_127 ;
}
if ( F_196 ( V_423 ) != V_3 -> V_85 / 4 ) {
F_38 ( & V_3 -> V_25 ) ;
F_195 ( V_423 ,
V_428 ) ;
return - V_127 ;
}
}
F_38 ( & V_3 -> V_25 ) ;
F_36 ( & V_3 -> V_25 ) ;
V_185 = F_44 ( V_3 , F_194 ( V_423 ) , 0 ) ;
if ( V_185 < 0 ) {
F_45 ( V_429 L_160 , V_185 ) ;
F_38 ( & V_3 -> V_25 ) ;
F_195 ( V_423 ,
V_427 ) ;
return V_185 ;
}
F_38 ( & V_3 -> V_25 ) ;
V_185 = F_35 ( V_3 ,
F_196 ( V_423 ) ) ;
if ( V_185 < 0 ) {
F_45 ( V_429 L_161 , V_185 ) ;
F_195 ( V_423 ,
V_428 ) ;
return V_185 ;
}
V_185 =
F_197 ( V_174 , V_430 ) ;
if ( V_185 < 0 ) {
F_45 ( V_429 L_162 , V_185 ) ;
return V_185 ;
}
if ( V_174 -> V_417 == V_418 ) {
F_198 ( V_3 , V_174 , V_431 ,
F_199 ( V_423 ) ) ;
for ( V_19 = 0 ; V_19 < F_199 ( V_423 ) ; ++ V_19 )
F_12 ( V_3 , V_19 , 1 ) ;
V_3 -> V_94 =
( unsigned char * ) V_174 -> V_415 -> V_432 ;
F_200 ( L_163 ,
V_3 -> V_94 ) ;
} else {
F_198 ( V_3 , V_174 , V_433 ,
F_199 ( V_423 ) ) ;
for ( V_19 = 0 ; V_19 < F_199 ( V_423 ) ; ++ V_19 )
F_11 ( V_3 , V_19 , 1 ) ;
V_3 -> V_434 =
( unsigned char * ) V_174 -> V_415 -> V_432 ;
F_200 ( L_164 ,
V_3 -> V_434 ) ;
}
if ( V_3 -> V_5 == V_37 ) {
return 0 ;
}
if ( V_435 == F_201 ( V_423 ) ) {
if ( ! ( V_3 -> V_29 & V_436 ) )
F_45 ( V_429 L_165 ) ;
V_3 -> V_29 |= V_436 ;
} else if ( V_437 == F_201 ( V_423 ) ) {
if ( V_3 -> V_29 & V_436 )
F_45 ( V_429 L_166 ) ;
V_3 -> V_29 &= ~ V_436 ;
}
F_3 ( V_3 , V_92 , V_3 -> V_29 ) ;
return 0 ;
}
static int F_202 ( struct V_413 * V_174 )
{
int V_19 ;
struct V_3 * V_3 = F_190 ( V_174 ) ;
if ( V_174 -> V_417 == V_418 ) {
for ( V_19 = 0 ; V_19 < V_3 -> V_136 ; ++ V_19 )
F_12 ( V_3 , V_19 , 0 ) ;
V_3 -> V_94 = NULL ;
} else {
for ( V_19 = 0 ; V_19 < V_3 -> V_134 ; ++ V_19 )
F_11 ( V_3 , V_19 , 0 ) ;
V_3 -> V_434 = NULL ;
}
F_203 ( V_174 ) ;
return 0 ;
}
static int F_204 ( struct V_413 * V_174 ,
struct V_438 * V_439 )
{
struct V_3 * V_3 = F_190 ( V_174 ) ;
if ( V_174 -> V_417 == V_418 ) {
if ( F_43 ( V_439 -> V_298 >= V_3 -> V_136 ) ) {
F_45 ( V_429 L_167 , V_439 -> V_298 ) ;
return - V_124 ;
}
if ( V_3 -> V_132 [ V_439 -> V_298 ] < 0 ) {
F_45 ( V_429 L_168 , V_439 -> V_298 ) ;
return - V_124 ;
}
V_439 -> V_440 = V_3 -> V_132 [ V_439 -> V_298 ] *
V_96 ;
} else {
if ( F_43 ( V_439 -> V_298 >= V_3 -> V_134 ) ) {
F_45 ( V_429 L_169 , V_439 -> V_298 ) ;
return - V_124 ;
}
if ( V_3 -> V_130 [ V_439 -> V_298 ] < 0 ) {
F_45 ( V_429 L_170 , V_439 -> V_298 ) ;
return - V_124 ;
}
V_439 -> V_440 = V_3 -> V_130 [ V_439 -> V_298 ] *
V_96 ;
}
V_439 -> V_441 = 0 ;
V_439 -> V_232 = 32 ;
return 0 ;
}
static int F_205 ( struct V_413 * V_174 ,
unsigned int V_442 , void * V_220 )
{
switch ( V_442 ) {
case V_443 :
return F_191 ( V_174 ) ;
case V_444 :
{
struct V_438 * V_439 = V_220 ;
return F_204 ( V_174 , V_439 ) ;
}
default:
break;
}
return F_206 ( V_174 , V_442 , V_220 ) ;
}
static int F_207 ( struct V_413 * V_174 , int V_442 )
{
struct V_3 * V_3 = F_190 ( V_174 ) ;
struct V_413 * V_416 ;
int V_419 ;
F_208 ( & V_3 -> V_25 ) ;
V_419 = V_3 -> V_419 ;
switch ( V_442 ) {
case V_445 :
V_419 |= 1 << V_174 -> V_417 ;
break;
case V_446 :
V_419 &= ~ ( 1 << V_174 -> V_417 ) ;
break;
default:
F_40 () ;
F_209 ( & V_3 -> V_25 ) ;
return - V_124 ;
}
if ( V_174 -> V_417 == V_418 )
V_416 = V_3 -> V_409 ;
else
V_416 = V_3 -> V_410 ;
if ( V_416 ) {
struct V_413 * V_89 ;
F_192 (s, substream) {
if ( V_89 == V_416 ) {
F_210 ( V_89 , V_174 ) ;
if ( V_442 == V_445 )
V_419 |= 1 << V_89 -> V_417 ;
else
V_419 &= ~ ( 1 << V_89 -> V_417 ) ;
goto V_447;
}
}
if ( V_442 == V_445 ) {
if ( ! ( V_419 & ( 1 << V_418 ) )
&& V_174 -> V_417 ==
V_448 )
F_34 ( V_3 ) ;
} else {
if ( V_419 &&
V_174 -> V_417 == V_418 )
F_34 ( V_3 ) ;
}
} else {
if ( V_174 -> V_417 == V_448 )
F_34 ( V_3 ) ;
}
V_447:
F_210 ( V_174 , V_174 ) ;
if ( ! V_3 -> V_419 && V_419 )
F_32 ( V_3 ) ;
else if ( V_3 -> V_419 && ! V_419 )
F_33 ( V_3 ) ;
V_3 -> V_419 = V_419 ;
F_209 ( & V_3 -> V_25 ) ;
return 0 ;
}
static int F_211 ( struct V_413 * V_174 )
{
return 0 ;
}
static int F_212 ( struct V_422 * V_423 ,
struct V_449 * V_450 )
{
struct V_3 * V_3 = V_450 -> V_451 ;
struct V_452 * V_453 =
F_213 ( V_423 , V_454 ) ;
struct V_452 * V_455 =
F_213 ( V_423 , V_427 ) ;
if ( V_455 -> V_230 > 96000 && V_455 -> V_231 <= 192000 ) {
struct V_452 V_456 = {
. V_230 = V_3 -> V_150 ,
. V_231 = V_3 -> V_150 ,
. integer = 1 ,
} ;
return F_214 ( V_453 , & V_456 ) ;
} else if ( V_455 -> V_230 > 48000 && V_455 -> V_231 <= 96000 ) {
struct V_452 V_456 = {
. V_230 = V_3 -> V_144 ,
. V_231 = V_3 -> V_144 ,
. integer = 1 ,
} ;
return F_214 ( V_453 , & V_456 ) ;
} else if ( V_455 -> V_231 < 64000 ) {
struct V_452 V_456 = {
. V_230 = V_3 -> V_135 ,
. V_231 = V_3 -> V_135 ,
. integer = 1 ,
} ;
return F_214 ( V_453 , & V_456 ) ;
}
return 0 ;
}
static int F_215 ( struct V_422 * V_423 ,
struct V_449 * V_450 )
{
struct V_3 * V_3 = V_450 -> V_451 ;
struct V_452 * V_453 =
F_213 ( V_423 , V_454 ) ;
struct V_452 * V_455 =
F_213 ( V_423 , V_427 ) ;
if ( V_455 -> V_230 > 96000 && V_455 -> V_231 <= 192000 ) {
struct V_452 V_456 = {
. V_230 = V_3 -> V_151 ,
. V_231 = V_3 -> V_151 ,
. integer = 1 ,
} ;
return F_214 ( V_453 , & V_456 ) ;
} else if ( V_455 -> V_230 > 48000 && V_455 -> V_231 <= 96000 ) {
struct V_452 V_456 = {
. V_230 = V_3 -> V_145 ,
. V_231 = V_3 -> V_145 ,
. integer = 1 ,
} ;
return F_214 ( V_453 , & V_456 ) ;
} else if ( V_455 -> V_231 < 64000 ) {
struct V_452 V_456 = {
. V_230 = V_3 -> V_137 ,
. V_231 = V_3 -> V_137 ,
. integer = 1 ,
} ;
return F_214 ( V_453 , & V_456 ) ;
} else {
}
return 0 ;
}
static int F_216 ( struct V_422 * V_423 ,
struct V_449 * V_450 )
{
struct V_3 * V_3 = V_450 -> V_451 ;
struct V_452 * V_453 =
F_213 ( V_423 , V_454 ) ;
struct V_452 * V_455 =
F_213 ( V_423 , V_427 ) ;
if ( V_453 -> V_230 >= V_3 -> V_135 ) {
struct V_452 V_456 = {
. V_230 = 32000 ,
. V_231 = 48000 ,
. integer = 1 ,
} ;
return F_214 ( V_455 , & V_456 ) ;
} else if ( V_453 -> V_231 <= V_3 -> V_150 ) {
struct V_452 V_456 = {
. V_230 = 128000 ,
. V_231 = 192000 ,
. integer = 1 ,
} ;
return F_214 ( V_455 , & V_456 ) ;
} else if ( V_453 -> V_231 <= V_3 -> V_144 ) {
struct V_452 V_456 = {
. V_230 = 64000 ,
. V_231 = 96000 ,
. integer = 1 ,
} ;
return F_214 ( V_455 , & V_456 ) ;
}
return 0 ;
}
static int F_217 ( struct V_422 * V_423 ,
struct V_449 * V_450 )
{
struct V_3 * V_3 = V_450 -> V_451 ;
struct V_452 * V_453 =
F_213 ( V_423 , V_454 ) ;
struct V_452 * V_455 =
F_213 ( V_423 , V_427 ) ;
if ( V_453 -> V_230 >= V_3 -> V_137 ) {
struct V_452 V_456 = {
. V_230 = 32000 ,
. V_231 = 48000 ,
. integer = 1 ,
} ;
return F_214 ( V_455 , & V_456 ) ;
} else if ( V_453 -> V_231 <= V_3 -> V_151 ) {
struct V_452 V_456 = {
. V_230 = 128000 ,
. V_231 = 192000 ,
. integer = 1 ,
} ;
return F_214 ( V_455 , & V_456 ) ;
} else if ( V_453 -> V_231 <= V_3 -> V_145 ) {
struct V_452 V_456 = {
. V_230 = 64000 ,
. V_231 = 96000 ,
. integer = 1 ,
} ;
return F_214 ( V_455 , & V_456 ) ;
}
return 0 ;
}
static int F_218 ( struct V_422 * V_423 ,
struct V_449 * V_450 )
{
unsigned int V_343 [ 3 ] ;
struct V_3 * V_3 = V_450 -> V_451 ;
struct V_452 * V_453 = F_213 ( V_423 ,
V_454 ) ;
V_343 [ 0 ] = V_3 -> V_150 ;
V_343 [ 1 ] = V_3 -> V_144 ;
V_343 [ 2 ] = V_3 -> V_135 ;
return F_219 ( V_453 , 3 , V_343 , 0 ) ;
}
static int F_220 ( struct V_422 * V_423 ,
struct V_449 * V_450 )
{
unsigned int V_343 [ 3 ] ;
struct V_3 * V_3 = V_450 -> V_451 ;
struct V_452 * V_453 = F_213 ( V_423 ,
V_454 ) ;
V_343 [ 0 ] = V_3 -> V_151 ;
V_343 [ 1 ] = V_3 -> V_145 ;
V_343 [ 2 ] = V_3 -> V_137 ;
return F_219 ( V_453 , 3 , V_343 , 0 ) ;
}
static int F_221 ( struct V_413 * V_174 )
{
struct V_3 * V_3 = F_190 ( V_174 ) ;
struct V_414 * V_415 = V_174 -> V_415 ;
F_36 ( & V_3 -> V_25 ) ;
F_222 ( V_174 ) ;
V_415 -> V_457 = V_458 ;
if ( V_3 -> V_409 == NULL )
F_33 ( V_3 ) ;
V_3 -> V_26 = V_459 -> V_460 ;
V_3 -> V_410 = V_174 ;
F_38 ( & V_3 -> V_25 ) ;
F_223 ( V_415 , 0 , 32 , 24 ) ;
F_224 ( V_415 , 0 , V_428 ) ;
switch ( V_3 -> V_5 ) {
case V_4 :
case V_6 :
F_225 ( V_415 ,
V_428 ,
32 , 4096 ) ;
F_225 ( V_415 ,
V_461 ,
16384 , 16384 ) ;
break;
default:
F_225 ( V_415 ,
V_428 ,
64 , 8192 ) ;
break;
}
if ( V_37 == V_3 -> V_5 ) {
V_415 -> V_457 . V_462 |= V_463 ;
F_226 ( V_415 , 0 , V_427 ,
& V_464 ) ;
} else {
F_227 ( V_415 , 0 , V_427 ,
F_217 , V_3 ,
V_454 , - 1 ) ;
}
F_227 ( V_415 , 0 , V_454 ,
F_220 , V_3 ,
V_454 , - 1 ) ;
F_227 ( V_415 , 0 , V_454 ,
F_215 , V_3 ,
V_427 , - 1 ) ;
return 0 ;
}
static int F_228 ( struct V_413 * V_174 )
{
struct V_3 * V_3 = F_190 ( V_174 ) ;
F_36 ( & V_3 -> V_25 ) ;
V_3 -> V_26 = - 1 ;
V_3 -> V_410 = NULL ;
F_38 ( & V_3 -> V_25 ) ;
return 0 ;
}
static int F_229 ( struct V_413 * V_174 )
{
struct V_3 * V_3 = F_190 ( V_174 ) ;
struct V_414 * V_415 = V_174 -> V_415 ;
F_36 ( & V_3 -> V_25 ) ;
F_222 ( V_174 ) ;
V_415 -> V_457 = V_465 ;
if ( V_3 -> V_410 == NULL )
F_33 ( V_3 ) ;
V_3 -> V_27 = V_459 -> V_460 ;
V_3 -> V_409 = V_174 ;
F_38 ( & V_3 -> V_25 ) ;
F_223 ( V_415 , 0 , 32 , 24 ) ;
F_224 ( V_415 , 0 , V_428 ) ;
switch ( V_3 -> V_5 ) {
case V_4 :
case V_6 :
F_225 ( V_415 ,
V_428 ,
32 , 4096 ) ;
F_225 ( V_415 ,
V_461 ,
16384 , 16384 ) ;
break;
default:
F_225 ( V_415 ,
V_428 ,
64 , 8192 ) ;
break;
}
if ( V_37 == V_3 -> V_5 ) {
V_415 -> V_457 . V_462 |= V_463 ;
F_226 ( V_415 , 0 , V_427 ,
& V_464 ) ;
} else {
F_227 ( V_415 , 0 , V_427 ,
F_216 , V_3 ,
V_454 , - 1 ) ;
}
F_227 ( V_415 , 0 , V_454 ,
F_218 , V_3 ,
V_454 , - 1 ) ;
F_227 ( V_415 , 0 , V_454 ,
F_212 , V_3 ,
V_427 , - 1 ) ;
return 0 ;
}
static int F_230 ( struct V_413 * V_174 )
{
struct V_3 * V_3 = F_190 ( V_174 ) ;
F_36 ( & V_3 -> V_25 ) ;
V_3 -> V_27 = - 1 ;
V_3 -> V_409 = NULL ;
F_38 ( & V_3 -> V_25 ) ;
return 0 ;
}
static int F_231 ( struct V_466 * V_457 , struct V_467 * V_467 )
{
return 0 ;
}
static inline int F_232 ( void T_5 * V_468 , void T_6 * V_469 )
{
V_18 V_8 = F_6 ( V_469 ) ;
return F_233 ( V_468 , & V_8 , 4 ) ;
}
static int F_234 ( struct V_466 * V_457 , struct V_467 * V_467 ,
unsigned int V_442 , unsigned long V_220 )
{
void T_5 * V_470 = ( void T_5 * ) V_220 ;
struct V_3 * V_3 = V_457 -> V_177 ;
struct V_471 V_13 ;
struct V_472 V_439 ;
struct V_473 V_32 ;
struct V_474 V_474 ;
struct V_475 * V_476 ;
struct V_477 V_357 ;
unsigned int V_478 ;
long unsigned int V_89 ;
int V_19 = 0 ;
switch ( V_442 ) {
case V_479 :
V_476 = & V_3 -> V_480 ;
for ( V_19 = 0 ; V_19 < V_95 ; V_19 ++ ) {
V_476 -> V_481 [ V_19 ] =
F_6 ( V_3 -> V_9 +
V_482 + V_19 * 4 ) ;
V_476 -> V_483 [ V_19 ] =
F_6 ( V_3 -> V_9 +
V_484 + V_19 * 4 ) ;
V_476 -> V_485 [ V_19 ] =
F_6 ( V_3 -> V_9 +
V_486 + V_19 * 4 ) ;
V_476 -> V_487 [ V_19 ] =
( ( V_488 ) F_6 ( V_3 -> V_9 +
V_489 + V_19 * 4 ) << 32 ) |
( V_488 ) F_6 ( V_3 -> V_9 +
V_490 + V_19 * 4 ) ;
V_476 -> V_491 [ V_19 ] =
( ( V_488 ) F_6 ( V_3 -> V_9 +
V_492 + V_19 * 4 ) << 32 ) |
( V_488 ) F_6 ( V_3 -> V_9 +
V_493 + V_19 * 4 ) ;
V_476 -> V_494 [ V_19 ] =
( ( V_488 ) F_6 ( V_3 -> V_9 +
V_495 + V_19 * 4 ) << 32 ) |
( V_488 ) F_6 ( V_3 -> V_9 +
V_496 + V_19 * 4 ) ;
}
if ( V_3 -> V_111 > 96000 ) {
V_476 -> V_497 = V_498 ;
} else if ( V_3 -> V_111 > 48000 ) {
V_476 -> V_497 = V_290 ;
} else {
V_476 -> V_497 = V_499 ;
}
V_476 -> V_33 = F_5 ( V_3 , V_38 ) ;
V_89 = F_233 ( V_470 , V_476 , sizeof( struct V_475 ) ) ;
if ( 0 != V_89 ) {
return - V_500 ;
}
break;
case V_501 :
V_357 . V_357 = F_5 ( V_3 , V_275 ) ;
V_19 = F_5 ( V_3 , V_275 + 4 ) ;
if ( V_19 & V_278 ) {
switch ( V_19 & ( V_279 |
V_280 ) ) {
case 0 :
V_357 . V_502 = V_281 ;
break;
case V_279 :
V_357 . V_502 = V_282 ;
break;
case V_280 :
V_357 . V_502 = V_283 ;
break;
default:
V_357 . V_502 = V_284 ;
break;
}
if ( V_19 & V_316 ) {
V_357 . V_503 = V_504 ;
} else {
V_357 . V_503 = V_505 ;
}
} else {
V_357 . V_502 = V_506 ;
V_357 . V_503 = V_507 ;
}
if ( V_19 & V_276 ) {
V_357 . V_508 = V_509 ;
} else if ( V_19 & V_277 ) {
V_357 . V_508 = V_510 ;
} else {
V_357 . V_508 = V_511 ;
}
V_89 = F_233 ( V_470 , & V_357 , sizeof( struct V_477 ) ) ;
if ( 0 != V_89 ) {
return - V_500 ;
}
break;
case V_512 :
memset ( & V_439 , 0 , sizeof( V_439 ) ) ;
F_36 ( & V_3 -> V_25 ) ;
V_439 . V_363 = F_94 ( V_3 ) ;
V_439 . V_513 = F_20 ( V_3 ) ;
V_439 . V_111 = V_3 -> V_111 ;
V_439 . V_514 =
F_18 ( V_3 ) ;
V_439 . V_365 = F_73 ( V_3 ) ;
V_439 . V_515 = F_89 ( V_3 ) ;
V_439 . V_364 = F_19 ( V_3 ) ;
V_439 . V_516 = F_107 ( V_3 , V_380 ) ;
V_439 . V_517 = 0 ;
F_38 ( & V_3 -> V_25 ) ;
if ( F_233 ( V_470 , & V_439 , sizeof( V_439 ) ) )
return - V_500 ;
break;
case V_518 :
memset ( & V_32 , 0 , sizeof( V_32 ) ) ;
V_32 . V_519 = V_3 -> V_5 ;
V_32 . V_520 = F_19 ( V_3 ) ;
V_32 . V_521 = 110069313433624ULL ;
V_32 . V_522 = F_5 ( V_3 , V_222 ) ;
switch ( V_3 -> V_5 ) {
case V_55 :
case V_51 :
V_32 . V_523 . V_524 . V_525 =
F_20 ( V_3 ) ;
V_32 . V_523 . V_524 . V_526 =
F_143 ( V_3 ) ;
V_32 . V_523 . V_524 . V_527 =
F_24 ( V_3 ) ;
V_32 . V_523 . V_524 . V_528 =
F_26 ( V_3 ) ;
V_478 =
F_5 ( V_3 , V_39 ) ;
V_32 . V_523 . V_524 . V_529 =
( V_478 & V_391 ) ? 1 : 0 ;
V_32 . V_523 . V_524 . V_530 =
( V_478 & V_392 ) ? 1 : 0 ;
V_32 . V_523 . V_524 . V_531 = 0 ;
default:
break;
}
if ( F_233 ( V_470 , & V_32 , sizeof( V_32 ) ) )
return - V_500 ;
break;
case V_532 :
memset ( & V_474 , 0 , sizeof( V_474 ) ) ;
V_474 . V_519 = V_3 -> V_5 ;
strncpy ( V_474 . V_533 , V_3 -> V_369 ,
sizeof( V_474 . V_533 ) ) ;
V_474 . V_375 = V_3 -> V_375 ;
V_474 . V_371 = V_3 -> V_371 ;
V_474 . V_534 = 0 ;
if ( V_3 -> V_239 )
V_474 . V_534 |= V_535 ;
if ( F_233 ( V_470 , & V_474 ,
sizeof( V_474 ) ) )
return - V_500 ;
break;
case V_536 :
if ( F_235 ( & V_13 , V_470 , sizeof( V_13 ) ) )
return - V_500 ;
if ( F_233 ( ( void T_5 * ) V_13 . V_13 , V_3 -> V_13 ,
sizeof( struct V_537 ) ) )
return - V_500 ;
break;
default:
return - V_124 ;
}
return 0 ;
}
static int F_236 ( struct V_183 * V_184 ,
struct V_3 * V_3 )
{
struct V_466 * V_457 ;
int V_185 ;
V_185 = F_237 ( V_184 , L_171 , 0 , & V_457 ) ;
if ( V_185 < 0 )
return V_185 ;
V_3 -> V_538 = V_457 ;
V_457 -> V_177 = V_3 ;
strcpy ( V_457 -> V_211 , L_172 ) ;
V_457 -> V_539 . V_540 = F_231 ;
V_457 -> V_539 . V_541 = F_234 ;
V_457 -> V_539 . V_542 = F_234 ;
V_457 -> V_539 . V_543 = F_231 ;
return 0 ;
}
static int F_238 ( struct V_3 * V_3 )
{
int V_185 ;
struct V_544 * V_545 ;
T_7 V_546 ;
V_545 = V_3 -> V_545 ;
V_546 = V_430 ;
V_185 =
F_239 ( V_545 ,
V_547 ,
F_240 ( V_3 -> V_548 ) ,
V_546 ,
V_546 ) ;
if ( V_185 < 0 ) {
F_200 ( L_173 , V_546 ) ;
return V_185 ;
} else
F_200 ( L_174 , V_546 ) ;
return 0 ;
}
static void F_198 ( struct V_3 * V_3 ,
struct V_413 * V_174 ,
unsigned int V_7 , int V_549 )
{
int V_19 ;
for ( V_19 = 0 ; V_19 < ( V_549 * 16 ) ; V_19 ++ )
F_3 ( V_3 , V_7 + 4 * V_19 ,
F_241 ( V_174 , 4096 * V_19 ) ) ;
}
static int F_242 ( struct V_183 * V_184 ,
struct V_3 * V_3 )
{
struct V_544 * V_545 ;
int V_185 ;
V_185 = F_243 ( V_184 , V_3 -> V_369 , 0 , 1 , 1 , & V_545 ) ;
if ( V_185 < 0 )
return V_185 ;
V_3 -> V_545 = V_545 ;
V_545 -> V_177 = V_3 ;
strcpy ( V_545 -> V_211 , V_3 -> V_369 ) ;
F_244 ( V_545 , V_418 ,
& V_550 ) ;
F_244 ( V_545 , V_448 ,
& V_551 ) ;
V_545 -> V_216 = V_552 ;
V_185 = F_238 ( V_3 ) ;
if ( V_185 < 0 )
return V_185 ;
return 0 ;
}
static inline void F_245 ( struct V_3 * V_3 )
{
int V_19 ;
for ( V_19 = 0 ; V_19 < V_3 -> V_221 ; V_19 ++ )
F_51 ( V_3 , V_19 ) ;
}
static int F_246 ( struct V_183 * V_184 ,
struct V_3 * V_3 )
{
int V_185 , V_19 ;
F_200 ( L_175 ) ;
V_185 = F_242 ( V_184 , V_3 ) ;
if ( V_185 < 0 )
return V_185 ;
V_19 = 0 ;
while ( V_19 < V_3 -> V_221 ) {
V_185 = F_67 ( V_184 , V_3 , V_19 ) ;
if ( V_185 < 0 ) {
return V_185 ;
}
V_19 ++ ;
}
V_185 = F_168 ( V_184 , V_3 ) ;
if ( V_185 < 0 )
return V_185 ;
V_185 = F_236 ( V_184 , V_3 ) ;
if ( V_185 < 0 )
return V_185 ;
F_200 ( L_176 ) ;
F_180 ( V_3 ) ;
V_3 -> V_111 = - 1 ;
V_3 -> V_553 = - 1 ;
V_3 -> V_554 = - 1 ;
V_3 -> V_26 = - 1 ;
V_3 -> V_27 = - 1 ;
V_3 -> V_409 = NULL ;
V_3 -> V_410 = NULL ;
F_200 ( L_177 ) ;
V_185 = F_184 ( V_3 ) ;
if ( V_185 < 0 )
return V_185 ;
F_200 ( L_178 ) ;
F_166 ( V_3 ) ;
F_200 ( L_179 ) ;
V_185 = F_247 ( V_184 ) ;
if ( V_185 < 0 ) {
F_45 ( V_125 L_180 ) ;
return V_185 ;
}
F_200 ( L_181 ) ;
return 0 ;
}
static int F_248 ( struct V_183 * V_184 ,
struct V_3 * V_3 )
{
struct V_555 * V_548 = V_3 -> V_548 ;
int V_185 ;
unsigned long V_556 ;
V_3 -> V_191 = - 1 ;
V_3 -> V_184 = V_184 ;
F_68 ( & V_3 -> V_25 ) ;
F_249 ( V_3 -> V_548 ,
V_557 , & V_3 -> V_371 ) ;
strcpy ( V_184 -> V_558 , L_182 ) ;
strcpy ( V_184 -> V_559 , L_183 ) ;
switch ( V_3 -> V_371 ) {
case V_560 :
V_3 -> V_5 = V_6 ;
V_3 -> V_369 = L_184 ;
V_3 -> V_221 = 2 ;
break;
case V_561 :
V_3 -> V_5 = V_4 ;
V_3 -> V_369 = L_185 ;
V_3 -> V_221 = 1 ;
break;
case V_562 :
V_3 -> V_5 = V_51 ;
V_3 -> V_369 = L_186 ;
V_3 -> V_221 = 1 ;
break;
default:
if ( ( V_3 -> V_371 == 0xf0 ) ||
( ( V_3 -> V_371 >= 0xe6 ) &&
( V_3 -> V_371 <= 0xea ) ) ) {
V_3 -> V_5 = V_37 ;
V_3 -> V_369 = L_187 ;
V_3 -> V_221 = 2 ;
} else if ( ( V_3 -> V_371 == 0xd2 ) ||
( ( V_3 -> V_371 >= 0xc8 ) &&
( V_3 -> V_371 <= 0xcf ) ) ) {
V_3 -> V_5 = V_55 ;
V_3 -> V_369 = L_188 ;
V_3 -> V_221 = 3 ;
} else {
F_45 ( V_125
L_189 ,
V_3 -> V_371 ) ;
return - V_563 ;
}
}
V_185 = F_250 ( V_548 ) ;
if ( V_185 < 0 )
return V_185 ;
F_251 ( V_3 -> V_548 ) ;
V_185 = F_252 ( V_548 , L_156 ) ;
if ( V_185 < 0 )
return V_185 ;
V_3 -> V_376 = F_253 ( V_548 , 0 ) ;
V_556 = F_254 ( V_548 , 0 ) ;
F_200 ( L_190 ,
V_3 -> V_376 , V_3 -> V_376 + V_556 - 1 ) ;
V_3 -> V_9 = F_255 ( V_3 -> V_376 , V_556 ) ;
if ( ! V_3 -> V_9 ) {
F_45 ( V_125 L_1
L_191 ,
V_3 -> V_376 , V_3 -> V_376 + V_556 - 1 ) ;
return - V_127 ;
}
F_200 ( L_192 ,
( unsigned long ) V_3 -> V_9 , V_3 -> V_376 ,
V_3 -> V_376 + V_556 - 1 ) ;
if ( F_256 ( V_548 -> V_191 , F_186 ,
V_564 , V_565 , V_3 ) ) {
F_45 ( V_125 L_193 , V_548 -> V_191 ) ;
return - V_127 ;
}
F_200 ( L_194 , V_548 -> V_191 ) ;
V_3 -> V_191 = V_548 -> V_191 ;
F_200 ( L_195 ,
sizeof( struct V_537 ) ) ;
V_3 -> V_13 = F_257 ( sizeof( struct V_537 ) , V_566 ) ;
if ( ! V_3 -> V_13 ) {
F_45 ( V_125 L_1
L_196 ,
( int ) sizeof( struct V_537 ) ) ;
return - V_567 ;
}
V_3 -> V_138 = NULL ;
V_3 -> V_140 = NULL ;
switch ( V_3 -> V_5 ) {
case V_37 :
V_3 -> V_135 = V_3 -> V_137 = V_568 ;
V_3 -> V_144 = V_3 -> V_145 = V_568 ;
V_3 -> V_150 = V_3 -> V_151 = V_568 ;
V_3 -> V_131 = V_3 -> V_133 =
V_569 ;
V_3 -> V_142 = V_3 -> V_143 =
V_569 ;
V_3 -> V_148 = V_3 -> V_149 =
V_569 ;
V_3 -> V_139 = V_3 -> V_141 =
V_570 ;
V_3 -> V_146 = V_3 -> V_147 =
V_570 ;
V_3 -> V_152 = V_3 -> V_153 =
V_570 ;
V_3 -> V_136 = V_3 -> V_134 =
V_568 ;
V_3 -> V_138 = V_3 -> V_140 =
V_570 ;
V_3 -> V_130 = V_3 -> V_132 =
V_569 ;
break;
case V_55 :
case V_51 :
V_3 -> V_135 = V_3 -> V_137 =
V_571 ;
V_3 -> V_144 = V_3 -> V_145 =
V_572 ;
V_3 -> V_150 = V_3 -> V_151 =
V_573 ;
V_3 -> V_131 = V_3 -> V_133 =
V_574 ;
V_3 -> V_142 = V_3 -> V_143 =
V_574 ;
V_3 -> V_148 = V_3 -> V_149 =
V_574 ;
V_3 -> V_139 = V_3 -> V_141 =
V_575 ;
V_3 -> V_146 = V_3 -> V_147 =
V_575 ;
V_3 -> V_152 = V_3 -> V_153 =
V_575 ;
break;
case V_4 :
V_3 -> V_135 = V_576 ;
V_3 -> V_144 = V_577 ;
V_3 -> V_150 = V_578 ;
V_3 -> V_137 = V_579 ;
V_3 -> V_145 = V_580 ;
V_3 -> V_151 = V_581 ;
if ( 0 == ( F_5 ( V_3 , V_38 ) & V_582 ) ) {
F_45 ( V_429 L_197 ) ;
V_3 -> V_135 += 4 ;
V_3 -> V_144 += 4 ;
V_3 -> V_150 += 4 ;
}
if ( 0 == ( F_5 ( V_3 , V_38 ) & V_583 ) ) {
F_45 ( V_429 L_198 ) ;
V_3 -> V_137 += 4 ;
V_3 -> V_145 += 4 ;
V_3 -> V_151 += 4 ;
}
V_3 -> V_133 = V_584 ;
V_3 -> V_143 = V_585 ;
V_3 -> V_149 = V_586 ;
V_3 -> V_131 = V_587 ;
V_3 -> V_142 = V_588 ;
V_3 -> V_148 = V_589 ;
V_3 -> V_139 = V_590 ;
V_3 -> V_141 = V_591 ;
V_3 -> V_146 = V_592 ;
V_3 -> V_147 = V_593 ;
V_3 -> V_152 = V_594 ;
V_3 -> V_153 = V_595 ;
break;
case V_6 :
V_3 -> V_135 = V_3 -> V_137 =
V_596 ;
V_3 -> V_144 = V_3 -> V_145 =
V_597 ;
V_3 -> V_150 = V_3 -> V_151 =
V_598 ;
V_3 -> V_134 = V_596 ;
V_3 -> V_136 = V_596 ;
V_3 -> V_131 = V_3 -> V_133 =
V_599 ;
V_3 -> V_142 = V_3 -> V_143 =
V_600 ;
V_3 -> V_148 = V_3 -> V_149 =
V_601 ;
V_3 -> V_130 = V_3 -> V_132 =
V_599 ;
V_3 -> V_139 = V_3 -> V_141 =
V_602 ;
V_3 -> V_146 = V_3 -> V_147 =
V_603 ;
V_3 -> V_152 = V_3 -> V_153 =
V_604 ;
break;
}
switch ( V_3 -> V_5 ) {
case V_4 :
case V_6 :
if ( F_5 ( V_3 , V_38 ) &
V_605 ) {
V_3 -> V_221 ++ ;
V_3 -> V_239 = F_257 ( sizeof( struct V_606 ) ,
V_566 ) ;
if ( NULL != V_3 -> V_239 ) {
F_147 ( V_3 ) ;
}
F_45 ( V_429 L_199 ) ;
} else {
V_3 -> V_239 = NULL ;
}
break;
case V_55 :
case V_37 :
if ( F_5 ( V_3 , V_39 ) & V_361 ) {
V_3 -> V_221 ++ ;
V_3 -> V_239 = F_257 ( sizeof( struct V_606 ) ,
V_566 ) ;
if ( NULL != V_3 -> V_239 ) {
F_147 ( V_3 ) ;
}
F_45 ( V_429 L_200 ) ;
} else {
V_3 -> V_239 = NULL ;
}
break;
default:
V_3 -> V_239 = NULL ;
}
switch ( V_3 -> V_5 ) {
case V_37 :
if ( V_3 -> V_239 ) {
V_3 -> V_264 = V_607 ;
V_3 -> V_263 =
F_169 ( V_607 ) ;
} else {
V_3 -> V_264 = V_608 ;
V_3 -> V_263 =
F_169 ( V_608 ) ;
}
break;
case V_55 :
if ( V_3 -> V_239 ) {
V_3 -> V_264 = V_609 ;
V_3 -> V_263 = 4 ;
} else {
V_3 -> V_264 = V_610 ;
V_3 -> V_263 = 3 ;
}
break;
case V_51 :
break;
case V_6 :
if ( V_3 -> V_239 ) {
V_3 -> V_264 = V_611 ;
V_3 -> V_263 = 9 ;
} else {
V_3 -> V_264 = V_612 ;
V_3 -> V_263 = 8 ;
}
break;
case V_4 :
if ( V_3 -> V_239 ) {
V_3 -> V_264 = V_613 ;
V_3 -> V_263 = 6 ;
} else {
V_3 -> V_264 = V_614 ;
V_3 -> V_263 = 5 ;
}
break;
}
F_258 ( & V_3 -> V_411 ,
F_71 , ( unsigned long ) V_3 ) ;
if ( V_3 -> V_5 != V_51 ) {
V_3 -> V_375 = ( F_5 ( V_3 ,
V_194 ) >> 8 ) & 0xFFFFFF ;
if ( NULL == V_158 [ V_3 -> V_615 ] && V_3 -> V_375 != 0xFFFFFF ) {
sprintf ( V_184 -> V_158 , L_201 , V_3 -> V_375 ) ;
F_259 ( V_184 , V_184 -> V_158 ) ;
}
}
F_200 ( L_202 ) ;
V_185 = F_246 ( V_184 , V_3 ) ;
if ( V_185 < 0 )
return V_185 ;
F_245 ( V_3 ) ;
return 0 ;
}
static int F_260 ( struct V_3 * V_3 )
{
if ( V_3 -> V_376 ) {
V_3 -> V_29 &=
~ ( V_91 | V_90 |
V_197 | V_203 |
V_190 | V_208 ) ;
F_3 ( V_3 , V_92 ,
V_3 -> V_29 ) ;
}
if ( V_3 -> V_191 >= 0 )
F_261 ( V_3 -> V_191 , ( void * ) V_3 ) ;
F_262 ( V_3 -> V_13 ) ;
if ( V_3 -> V_9 )
F_263 ( V_3 -> V_9 ) ;
if ( V_3 -> V_376 )
F_264 ( V_3 -> V_548 ) ;
F_265 ( V_3 -> V_548 ) ;
return 0 ;
}
static void F_266 ( struct V_183 * V_184 )
{
struct V_3 * V_3 = V_184 -> V_177 ;
if ( V_3 )
F_260 ( V_3 ) ;
}
static int F_267 ( struct V_555 * V_548 ,
const struct V_616 * V_617 )
{
static int V_615 ;
struct V_3 * V_3 ;
struct V_183 * V_184 ;
int V_185 ;
if ( V_615 >= V_618 )
return - V_563 ;
if ( ! V_619 [ V_615 ] ) {
V_615 ++ ;
return - V_620 ;
}
V_185 = F_268 ( V_241 [ V_615 ] , V_158 [ V_615 ] ,
V_621 , sizeof( struct V_3 ) , & V_184 ) ;
if ( V_185 < 0 )
return V_185 ;
V_3 = V_184 -> V_177 ;
V_184 -> V_622 = F_266 ;
V_3 -> V_615 = V_615 ;
V_3 -> V_548 = V_548 ;
F_269 ( V_184 , & V_548 -> V_615 ) ;
V_185 = F_248 ( V_184 , V_3 ) ;
if ( V_185 < 0 ) {
F_270 ( V_184 ) ;
return V_185 ;
}
if ( V_3 -> V_5 != V_51 ) {
sprintf ( V_184 -> V_210 , L_203 ,
V_3 -> V_369 ,
V_3 -> V_375 ) ;
sprintf ( V_184 -> V_623 , L_204 ,
V_3 -> V_369 ,
V_3 -> V_375 ,
V_3 -> V_376 , V_3 -> V_191 ) ;
} else {
sprintf ( V_184 -> V_210 , L_205 , V_3 -> V_369 ) ;
sprintf ( V_184 -> V_623 , L_206 ,
V_3 -> V_369 , V_3 -> V_376 , V_3 -> V_191 ) ;
}
V_185 = F_247 ( V_184 ) ;
if ( V_185 < 0 ) {
F_270 ( V_184 ) ;
return V_185 ;
}
F_271 ( V_548 , V_184 ) ;
V_615 ++ ;
return 0 ;
}
static void F_272 ( struct V_555 * V_548 )
{
F_270 ( F_273 ( V_548 ) ) ;
}
