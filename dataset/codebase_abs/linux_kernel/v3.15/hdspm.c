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
F_45 ( V_3 -> V_108 -> V_109 ,
L_1 ) ;
V_104 = 1 ;
} else {
int V_110 =
F_18 ( V_3 ) ;
if ( F_19 ( V_3 ) ==
V_111 ) {
F_45 ( V_3 -> V_108 -> V_109 ,
L_2 ) ;
V_104 = 1 ;
} else if ( V_28 != V_110 ) {
F_45 ( V_3 -> V_108 -> V_109 ,
L_3 ) ;
V_104 = 1 ;
}
}
}
V_103 = V_3 -> V_112 ;
if ( V_103 <= 48000 )
V_105 = V_113 ;
else if ( V_103 <= 96000 )
V_105 = V_114 ;
else
V_105 = V_115 ;
if ( V_28 <= 48000 )
V_106 = V_113 ;
else if ( V_28 <= 96000 )
V_106 = V_114 ;
else
V_106 = V_115 ;
switch ( V_28 ) {
case 32000 :
V_36 = V_116 ;
break;
case 44100 :
V_36 = V_117 ;
break;
case 48000 :
V_36 = V_118 ;
break;
case 64000 :
V_36 = V_119 ;
break;
case 88200 :
V_36 = V_120 ;
break;
case 96000 :
V_36 = V_121 ;
break;
case 128000 :
V_36 = V_122 ;
break;
case 176400 :
V_36 = V_123 ;
break;
case 192000 :
V_36 = V_124 ;
break;
default:
return - V_125 ;
}
if ( V_105 != V_106
&& ( V_3 -> V_27 >= 0 || V_3 -> V_26 >= 0 ) ) {
F_46 ( V_3 -> V_108 -> V_109 ,
L_4 ,
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
V_3 -> V_112 = V_28 ;
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
static void F_47 ( struct V_3 * V_3 , int V_154 )
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
static inline unsigned char F_48 ( struct V_3 * V_3 ,
int V_158 )
{
return F_5 ( V_3 , V_3 -> V_159 [ V_158 ] . V_160 ) ;
}
static inline void F_49 ( struct V_3 * V_3 , int V_158 ,
int V_8 )
{
return F_3 ( V_3 , V_3 -> V_159 [ V_158 ] . V_161 , V_8 ) ;
}
static inline int F_50 ( struct V_3 * V_3 , int V_158 )
{
return F_5 ( V_3 , V_3 -> V_159 [ V_158 ] . V_162 ) & 0xFF ;
}
static inline int F_51 ( struct V_3 * V_3 , int V_158 )
{
int V_163 ;
V_163 = F_5 ( V_3 , V_3 -> V_159 [ V_158 ] . V_164 ) & 0xFF ;
if ( V_163 < 128 )
return 128 - V_163 ;
else
return 0 ;
}
static void F_52 ( struct V_3 * V_3 , int V_158 )
{
while ( F_50 ( V_3 , V_158 ) )
F_48 ( V_3 , V_158 ) ;
}
static int F_53 ( struct V_165 * V_166 )
{
unsigned long V_23 ;
int V_167 ;
int V_168 ;
int V_19 ;
unsigned char V_93 [ 128 ] ;
F_14 ( & V_166 -> V_25 , V_23 ) ;
if ( V_166 -> V_169 &&
! F_54 ( V_166 -> V_169 ) ) {
V_167 = F_51 ( V_166 -> V_3 ,
V_166 -> V_158 ) ;
if ( V_167 > 0 ) {
if ( V_167 > ( int ) sizeof ( V_93 ) )
V_167 = sizeof ( V_93 ) ;
V_168 = F_55 ( V_166 -> V_169 , V_93 ,
V_167 ) ;
if ( V_168 > 0 ) {
for ( V_19 = 0 ; V_19 < V_168 ; ++ V_19 )
F_49 ( V_166 -> V_3 ,
V_166 -> V_158 ,
V_93 [ V_19 ] ) ;
}
}
}
F_15 ( & V_166 -> V_25 , V_23 ) ;
return 0 ;
}
static int F_56 ( struct V_165 * V_166 )
{
unsigned char V_93 [ 128 ] ;
unsigned long V_23 ;
int V_167 ;
int V_19 ;
F_14 ( & V_166 -> V_25 , V_23 ) ;
V_167 = F_50 ( V_166 -> V_3 , V_166 -> V_158 ) ;
if ( V_167 > 0 ) {
if ( V_166 -> V_170 ) {
if ( V_167 > ( int ) sizeof ( V_93 ) )
V_167 = sizeof ( V_93 ) ;
for ( V_19 = 0 ; V_19 < V_167 ; ++ V_19 )
V_93 [ V_19 ] = F_48 ( V_166 -> V_3 ,
V_166 -> V_158 ) ;
if ( V_167 )
F_57 ( V_166 -> V_170 , V_93 ,
V_167 ) ;
} else {
while ( V_167 -- )
F_48 ( V_166 -> V_3 ,
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
return F_53 ( V_166 ) ;
}
static void
F_58 ( struct V_173 * V_174 , int V_175 )
{
struct V_3 * V_3 ;
struct V_165 * V_166 ;
unsigned long V_23 ;
V_166 = V_174 -> V_176 -> V_177 ;
V_3 = V_166 -> V_3 ;
F_14 ( & V_3 -> V_25 , V_23 ) ;
if ( V_175 ) {
if ( ! ( V_3 -> V_29 & V_166 -> V_172 ) ) {
F_52 ( V_3 , V_166 -> V_158 ) ;
V_3 -> V_29 |= V_166 -> V_172 ;
}
} else {
V_3 -> V_29 &= ~ V_166 -> V_172 ;
}
F_3 ( V_3 , V_92 , V_3 -> V_29 ) ;
F_15 ( & V_3 -> V_25 , V_23 ) ;
}
static void F_59 ( unsigned long V_16 )
{
struct V_165 * V_166 = (struct V_165 * ) V_16 ;
unsigned long V_23 ;
F_53 ( V_166 ) ;
F_14 ( & V_166 -> V_25 , V_23 ) ;
if ( V_166 -> V_178 ) {
V_166 -> V_179 . V_180 = 1 + V_181 ;
F_60 ( & V_166 -> V_179 ) ;
}
F_15 ( & V_166 -> V_25 , V_23 ) ;
}
static void
F_61 ( struct V_173 * V_174 , int V_175 )
{
struct V_165 * V_166 ;
unsigned long V_23 ;
V_166 = V_174 -> V_176 -> V_177 ;
F_14 ( & V_166 -> V_25 , V_23 ) ;
if ( V_175 ) {
if ( ! V_166 -> V_178 ) {
F_62 ( & V_166 -> V_179 ) ;
V_166 -> V_179 . V_182 = F_59 ;
V_166 -> V_179 . V_16 = ( unsigned long ) V_166 ;
V_166 -> V_179 . V_180 = 1 + V_181 ;
F_60 ( & V_166 -> V_179 ) ;
V_166 -> V_178 ++ ;
}
} else {
if ( V_166 -> V_178 && -- V_166 -> V_178 <= 0 )
F_63 ( & V_166 -> V_179 ) ;
}
F_15 ( & V_166 -> V_25 , V_23 ) ;
if ( V_175 )
F_53 ( V_166 ) ;
}
static int F_64 ( struct V_173 * V_174 )
{
struct V_165 * V_166 ;
V_166 = V_174 -> V_176 -> V_177 ;
F_36 ( & V_166 -> V_25 ) ;
F_52 ( V_166 -> V_3 , V_166 -> V_158 ) ;
V_166 -> V_170 = V_174 ;
F_38 ( & V_166 -> V_25 ) ;
return 0 ;
}
static int F_65 ( struct V_173 * V_174 )
{
struct V_165 * V_166 ;
V_166 = V_174 -> V_176 -> V_177 ;
F_36 ( & V_166 -> V_25 ) ;
V_166 -> V_169 = V_174 ;
F_38 ( & V_166 -> V_25 ) ;
return 0 ;
}
static int F_66 ( struct V_173 * V_174 )
{
struct V_165 * V_166 ;
F_58 ( V_174 , 0 ) ;
V_166 = V_174 -> V_176 -> V_177 ;
F_36 ( & V_166 -> V_25 ) ;
V_166 -> V_170 = NULL ;
F_38 ( & V_166 -> V_25 ) ;
return 0 ;
}
static int F_67 ( struct V_173 * V_174 )
{
struct V_165 * V_166 ;
F_61 ( V_174 , 0 ) ;
V_166 = V_174 -> V_176 -> V_177 ;
F_36 ( & V_166 -> V_25 ) ;
V_166 -> V_169 = NULL ;
F_38 ( & V_166 -> V_25 ) ;
return 0 ;
}
static int F_68 ( struct V_183 * V_108 ,
struct V_3 * V_3 , int V_158 )
{
int V_184 ;
char V_93 [ 32 ] ;
V_3 -> V_159 [ V_158 ] . V_158 = V_158 ;
V_3 -> V_159 [ V_158 ] . V_3 = V_3 ;
F_69 ( & V_3 -> V_159 [ V_158 ] . V_25 ) ;
if ( 0 == V_158 ) {
if ( V_51 == V_3 -> V_5 ) {
V_3 -> V_159 [ 0 ] . V_160 = V_185 ;
V_3 -> V_159 [ 0 ] . V_162 = V_186 ;
V_3 -> V_159 [ 0 ] . V_161 = V_187 ;
V_3 -> V_159 [ 0 ] . V_164 = V_188 ;
V_3 -> V_159 [ 0 ] . V_172 = V_189 ;
V_3 -> V_159 [ 0 ] . V_190 = V_191 ;
} else {
V_3 -> V_159 [ 0 ] . V_160 = V_192 ;
V_3 -> V_159 [ 0 ] . V_162 = V_193 ;
V_3 -> V_159 [ 0 ] . V_161 = V_194 ;
V_3 -> V_159 [ 0 ] . V_164 = V_195 ;
V_3 -> V_159 [ 0 ] . V_172 = V_196 ;
V_3 -> V_159 [ 0 ] . V_190 = V_197 ;
}
} else if ( 1 == V_158 ) {
V_3 -> V_159 [ 1 ] . V_160 = V_198 ;
V_3 -> V_159 [ 1 ] . V_162 = V_199 ;
V_3 -> V_159 [ 1 ] . V_161 = V_200 ;
V_3 -> V_159 [ 1 ] . V_164 = V_201 ;
V_3 -> V_159 [ 1 ] . V_172 = V_202 ;
V_3 -> V_159 [ 1 ] . V_190 = V_203 ;
} else if ( ( 2 == V_158 ) && ( V_55 == V_3 -> V_5 ) ) {
V_3 -> V_159 [ 2 ] . V_160 = V_185 ;
V_3 -> V_159 [ 2 ] . V_162 = V_186 ;
V_3 -> V_159 [ 2 ] . V_161 = V_187 ;
V_3 -> V_159 [ 2 ] . V_164 = V_188 ;
V_3 -> V_159 [ 2 ] . V_172 = V_189 ;
V_3 -> V_159 [ 2 ] . V_190 = V_191 ;
} else if ( 2 == V_158 ) {
V_3 -> V_159 [ 2 ] . V_160 = V_185 ;
V_3 -> V_159 [ 2 ] . V_162 = V_186 ;
V_3 -> V_159 [ 2 ] . V_161 = - 1 ;
V_3 -> V_159 [ 2 ] . V_164 = - 1 ;
V_3 -> V_159 [ 2 ] . V_172 = V_189 ;
V_3 -> V_159 [ 2 ] . V_190 = V_204 ;
} else if ( 3 == V_158 ) {
V_3 -> V_159 [ 3 ] . V_160 = V_205 ;
V_3 -> V_159 [ 3 ] . V_162 = V_206 ;
V_3 -> V_159 [ 3 ] . V_161 = - 1 ;
V_3 -> V_159 [ 3 ] . V_164 = - 1 ;
V_3 -> V_159 [ 3 ] . V_172 = V_207 ;
V_3 -> V_159 [ 3 ] . V_190 = V_208 ;
}
if ( ( V_158 < 2 ) || ( ( 2 == V_158 ) && ( ( V_55 == V_3 -> V_5 ) ||
( V_51 == V_3 -> V_5 ) ) ) ) {
if ( ( V_158 == 0 ) && ( V_51 == V_3 -> V_5 ) ) {
sprintf ( V_93 , L_5 , V_108 -> V_209 ) ;
} else if ( ( V_158 == 2 ) && ( V_55 == V_3 -> V_5 ) ) {
sprintf ( V_93 , L_5 , V_108 -> V_209 ) ;
} else {
sprintf ( V_93 , L_6 , V_108 -> V_209 , V_158 + 1 ) ;
}
V_184 = F_70 ( V_108 , V_93 , V_158 , 1 , 1 ,
& V_3 -> V_159 [ V_158 ] . V_176 ) ;
if ( V_184 < 0 )
return V_184 ;
sprintf ( V_3 -> V_159 [ V_158 ] . V_176 -> V_210 , L_6 ,
V_108 -> V_158 , V_158 + 1 ) ;
V_3 -> V_159 [ V_158 ] . V_176 -> V_177 = & V_3 -> V_159 [ V_158 ] ;
F_71 ( V_3 -> V_159 [ V_158 ] . V_176 ,
V_211 ,
& V_212 ) ;
F_71 ( V_3 -> V_159 [ V_158 ] . V_176 ,
V_213 ,
& V_214 ) ;
V_3 -> V_159 [ V_158 ] . V_176 -> V_215 |=
V_216 |
V_217 |
V_218 ;
} else {
sprintf ( V_93 , L_7 , V_108 -> V_209 , V_158 + 1 ) ;
V_184 = F_70 ( V_108 , V_93 , V_158 , 1 , 1 ,
& V_3 -> V_159 [ V_158 ] . V_176 ) ;
if ( V_184 < 0 )
return V_184 ;
sprintf ( V_3 -> V_159 [ V_158 ] . V_176 -> V_210 ,
L_7 , V_108 -> V_158 , V_158 + 1 ) ;
V_3 -> V_159 [ V_158 ] . V_176 -> V_177 = & V_3 -> V_159 [ V_158 ] ;
F_71 ( V_3 -> V_159 [ V_158 ] . V_176 ,
V_213 ,
& V_214 ) ;
V_3 -> V_159 [ V_158 ] . V_176 -> V_215 |= V_217 ;
}
return 0 ;
}
static void F_72 ( unsigned long V_219 )
{
struct V_3 * V_3 = (struct V_3 * ) V_219 ;
int V_19 = 0 ;
while ( V_19 < V_3 -> V_220 ) {
if ( V_3 -> V_159 [ V_19 ] . V_171 )
F_56 ( & V_3 -> V_159 [ V_19 ] ) ;
V_19 ++ ;
}
}
static inline int F_27 ( struct V_3 * V_3 )
{
unsigned int V_99 , V_28 ;
V_99 = F_5 ( V_3 , V_221 ) ;
V_28 = F_39 ( V_3 , V_99 ) ;
return V_28 ;
}
static int F_73 ( struct V_3 * V_3 )
{
unsigned int V_28 ;
V_28 = F_27 ( V_3 ) ;
if ( V_28 > 207000 ) {
if ( 0 == F_74 ( V_3 ) ) {
V_28 = V_3 -> V_112 ;
} else {
V_28 = F_18 ( V_3 ) ;
}
}
return V_28 ;
}
static int F_75 ( struct V_222 * V_223 ,
struct V_224 * V_225 )
{
V_225 -> type = V_226 ;
V_225 -> V_227 = 1 ;
V_225 -> V_228 . integer . V_229 = 27000 ;
V_225 -> V_228 . integer . V_230 = 207000 ;
V_225 -> V_228 . integer . V_231 = 1 ;
return 0 ;
}
static int F_76 ( struct V_222 * V_223 ,
struct V_232 *
V_233 )
{
struct V_3 * V_3 = F_77 ( V_223 ) ;
V_233 -> V_228 . integer . V_228 [ 0 ] = F_73 ( V_3 ) ;
return 0 ;
}
static int F_78 ( struct V_222 * V_223 ,
struct V_232 *
V_233 )
{
struct V_3 * V_3 = F_77 ( V_223 ) ;
F_42 ( V_3 , V_233 -> V_228 . V_234 . V_235 [ 0 ] ) ;
return 0 ;
}
static int F_21 ( struct V_3 * V_3 )
{
int V_32 ;
switch ( V_3 -> V_5 ) {
case V_6 :
case V_4 :
V_32 = F_5 ( V_3 , V_236 ) ;
return ( V_32 >> 16 ) & 0xF ;
break;
case V_37 :
V_32 = F_5 ( V_3 , V_39 ) ;
return ( V_32 >> V_237 ) & 0xF ;
default:
break;
}
return 0 ;
}
static int F_25 ( struct V_3 * V_3 )
{
int V_32 ;
if ( V_3 -> V_238 ) {
switch ( V_3 -> V_5 ) {
case V_6 :
case V_4 :
V_32 = F_5 ( V_3 , V_236 ) ;
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
static int F_79 ( struct V_3 * V_3 )
{
int V_32 ;
if ( V_3 -> V_238 ) {
switch ( V_3 -> V_5 ) {
case V_6 :
case V_4 :
V_32 = F_5 ( V_3 , V_239 ) ;
return ( V_32 >> 12 ) & 0xF ;
break;
default:
break;
}
}
return 0 ;
}
static int F_23 ( struct V_3 * V_3 , int V_240 )
{
int V_34 ;
switch ( V_3 -> V_5 ) {
case V_37 :
V_34 = F_5 ( V_3 , V_40 ) ;
return ( V_34 >> ( 4 * V_240 ) ) & 0xF ;
break;
default:
break;
}
return 0 ;
}
static int F_80 ( struct V_3 * V_3 , unsigned int V_241 )
{
int V_32 = F_5 ( V_3 , V_239 ) ;
return ( V_32 >> ( V_241 * 4 ) ) & 0xF ;
}
static int F_81 ( struct V_3 * V_3 )
{
int V_28 = F_18 ( V_3 ) ;
int V_19 , V_242 = 0 ;
for ( V_19 = 1 ; V_19 < 10 ; V_19 ++ )
if ( F_1 ( V_19 ) == V_28 ) {
V_242 = V_19 ;
break;
}
return V_242 ;
}
static int F_82 ( struct V_222 * V_223 ,
struct V_224 * V_225 )
{
F_83 ( V_225 , V_243 ) ;
return 0 ;
}
static int F_84 ( struct V_222 * V_223 ,
struct V_232 *
V_233 )
{
struct V_3 * V_3 = F_77 ( V_223 ) ;
switch ( V_3 -> V_5 ) {
case V_6 :
switch ( V_223 -> V_244 ) {
case 0 :
V_233 -> V_228 . V_234 . V_235 [ 0 ] =
F_21 ( V_3 ) ;
break;
case 7 :
V_233 -> V_228 . V_234 . V_235 [ 0 ] =
F_25 ( V_3 ) ;
break;
case 8 :
V_233 -> V_228 . V_234 . V_235 [ 0 ] =
F_79 ( V_3 ) ;
break;
default:
V_233 -> V_228 . V_234 . V_235 [ 0 ] =
F_80 ( V_3 ,
V_223 -> V_244 - 1 ) ;
}
break;
case V_4 :
switch ( V_223 -> V_244 ) {
case 0 :
V_233 -> V_228 . V_234 . V_235 [ 0 ] =
F_21 ( V_3 ) ;
break;
case 4 :
V_233 -> V_228 . V_234 . V_235 [ 0 ] =
F_25 ( V_3 ) ;
break;
case 5 :
V_233 -> V_228 . V_234 . V_235 [ 0 ] =
F_79 ( V_3 ) ;
break;
default:
V_233 -> V_228 . V_234 . V_235 [ 0 ] =
F_80 ( V_3 ,
V_223 -> V_244 - 1 ) ;
}
break;
case V_37 :
switch ( V_223 -> V_244 ) {
case 0 :
V_233 -> V_228 . V_234 . V_235 [ 0 ] =
F_21 ( V_3 ) ;
break;
case 9 :
V_233 -> V_228 . V_234 . V_235 [ 0 ] =
F_25 ( V_3 ) ;
break;
case 10 :
V_233 -> V_228 . V_234 . V_235 [ 0 ] =
F_79 ( V_3 ) ;
break;
case 11 :
V_233 -> V_228 . V_234 . V_235 [ 0 ] =
F_81 ( V_3 ) ;
break;
default:
V_233 -> V_228 . V_234 . V_235 [ 0 ] =
F_23 ( V_3 ,
V_223 -> V_244 -
V_42 ) ;
break;
}
break;
case V_55 :
case V_51 :
V_233 -> V_228 . V_234 . V_235 [ 0 ] =
F_81 ( V_3 ) ;
break;
default:
break;
}
return 0 ;
}
static int F_74 ( struct V_3 * V_3 )
{
switch ( V_3 -> V_5 ) {
case V_4 :
case V_6 :
if ( V_3 -> V_245 & V_246 )
return 0 ;
break;
default:
if ( V_3 -> V_29 & V_107 )
return 0 ;
}
return 1 ;
}
static void F_85 ( struct V_3 * V_3 , int V_247 )
{
F_86 ( V_3 ,
( F_2 ( V_3 ) ) ?
V_246 : V_107 ,
( 0 == V_247 ) ) ;
}
static int F_87 ( struct V_222 * V_223 ,
struct V_224 * V_225 )
{
static const char * const V_248 [] = { L_8 , L_9 } ;
F_83 ( V_225 , V_248 ) ;
return 0 ;
}
static int F_88 ( struct V_222 * V_223 ,
struct V_232 * V_233 )
{
struct V_3 * V_3 = F_77 ( V_223 ) ;
V_233 -> V_228 . V_234 . V_235 [ 0 ] = F_74 ( V_3 ) ;
return 0 ;
}
static int F_89 ( struct V_222 * V_223 ,
struct V_232 * V_233 )
{
struct V_3 * V_3 = F_77 ( V_223 ) ;
int V_8 ;
if ( ! F_13 ( V_3 ) )
return - V_127 ;
V_8 = V_233 -> V_228 . V_234 . V_235 [ 0 ] ;
if ( V_8 < 0 )
V_8 = 0 ;
else if ( V_8 > 1 )
V_8 = 1 ;
F_85 ( V_3 , V_8 ) ;
return 0 ;
}
static int F_90 ( struct V_3 * V_3 )
{
switch ( V_3 -> V_112 ) {
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
static int F_91 ( struct V_3 * V_3 , int V_247 )
{
int V_28 ;
switch ( V_247 ) {
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
static int F_92 ( struct V_222 * V_223 ,
struct V_224 * V_225 )
{
V_225 -> type = V_249 ;
V_225 -> V_227 = 1 ;
V_225 -> V_228 . V_234 . V_250 = 9 ;
if ( V_225 -> V_228 . V_234 . V_235 >= V_225 -> V_228 . V_234 . V_250 )
V_225 -> V_228 . V_234 . V_235 =
V_225 -> V_228 . V_234 . V_250 - 1 ;
strcpy ( V_225 -> V_228 . V_234 . V_210 ,
V_243 [ V_225 -> V_228 . V_234 . V_235 + 1 ] ) ;
return 0 ;
}
static int F_93 ( struct V_222 * V_223 ,
struct V_232 * V_233 )
{
struct V_3 * V_3 = F_77 ( V_223 ) ;
V_233 -> V_228 . V_234 . V_235 [ 0 ] = F_90 ( V_3 ) ;
return 0 ;
}
static int F_94 ( struct V_222 * V_223 ,
struct V_232 * V_233 )
{
struct V_3 * V_3 = F_77 ( V_223 ) ;
int V_251 ;
int V_8 ;
if ( ! F_13 ( V_3 ) )
return - V_127 ;
V_8 = V_233 -> V_228 . V_234 . V_235 [ 0 ] ;
if ( V_8 < 0 )
V_8 = 0 ;
if ( V_8 > 9 )
V_8 = 9 ;
F_36 ( & V_3 -> V_25 ) ;
if ( V_8 != F_90 ( V_3 ) )
V_251 = ( F_91 ( V_3 , V_8 ) == 0 ) ? 1 : 0 ;
else
V_251 = 0 ;
F_38 ( & V_3 -> V_25 ) ;
return V_251 ;
}
static int F_95 ( struct V_3 * V_3 )
{
switch ( V_3 -> V_5 ) {
case V_37 :
switch ( V_3 -> V_29 & V_252 ) {
case 0 : return 0 ;
case V_253 : return 1 ;
case V_254 : return 2 ;
case V_254 + V_253 : return 3 ;
case V_255 : return 4 ;
case V_255 + V_253 : return 5 ;
case V_255 + V_254 : return 6 ;
case V_255 + V_254 + V_253 :
return 7 ;
case V_256 : return 8 ;
case V_256 + V_253 : return 9 ;
}
break;
case V_55 :
case V_51 :
if ( V_3 -> V_238 ) {
switch ( V_3 -> V_29 & V_252 ) {
case 0 : return 0 ;
case V_253 : return 1 ;
case V_254 : return 2 ;
case V_254 + V_253 :
return 3 ;
}
} else {
switch ( V_3 -> V_29 & V_252 ) {
case 0 : return 0 ;
case V_253 : return 1 ;
case V_254 + V_253 :
return 2 ;
}
}
break;
case V_6 :
if ( V_3 -> V_238 ) {
switch ( ( V_3 -> V_245 &
V_257 ) / V_258 ) {
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
switch ( ( V_3 -> V_245 &
V_257 ) / V_258 ) {
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
if ( V_3 -> V_238 ) {
switch ( ( V_3 -> V_245 &
V_257 ) / V_258 ) {
case 0 : return 0 ;
case 3 : return 1 ;
case 1 : return 2 ;
case 2 : return 3 ;
case 9 : return 4 ;
case 10 : return 5 ;
}
} else {
switch ( ( V_3 -> V_245 &
V_257 ) / V_258 ) {
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
static int F_96 ( struct V_3 * V_3 , int V_259 )
{
int V_260 = 0 ;
switch ( V_3 -> V_5 ) {
case V_37 :
V_3 -> V_29 &= ~ V_252 ;
switch ( V_259 ) {
case 0 :
break;
case 1 :
V_3 -> V_29 |= V_253 ;
break;
case 2 :
V_3 -> V_29 |= V_254 ;
break;
case 3 :
V_3 -> V_29 |=
V_254 + V_253 ;
break;
case 4 :
V_3 -> V_29 |= V_255 ;
break;
case 5 :
V_3 -> V_29 |=
V_255 + V_253 ;
break;
case 6 :
V_3 -> V_29 |=
V_255 + V_254 ;
break;
case 7 :
V_3 -> V_29 |=
V_255 + V_254 + V_253 ;
break;
case 8 :
V_3 -> V_29 |= V_256 ;
break;
case 9 :
V_3 -> V_29 |=
V_256 + V_253 ;
break;
default:
return - 1 ;
}
break;
case V_55 :
case V_51 :
V_3 -> V_29 &= ~ V_252 ;
if ( V_3 -> V_238 ) {
switch ( V_259 ) {
case 0 :
break;
case 1 :
V_3 -> V_29 |= V_253 ;
break;
case 2 :
V_3 -> V_29 |= V_254 ;
break;
case 3 :
V_3 -> V_29 |=
V_253 + V_254 ;
break;
default:
return - 1 ;
}
} else {
switch ( V_259 ) {
case 0 :
break;
case 1 :
V_3 -> V_29 |= V_253 ;
break;
case 2 :
V_3 -> V_29 |=
V_253 + V_254 ;
break;
default:
return - 1 ;
}
}
break;
case V_6 :
if ( V_3 -> V_238 ) {
switch ( V_259 ) {
case 0 : V_260 = 0 ; break;
case 1 : V_260 = 3 ; break;
case 2 : V_260 = 4 ; break;
case 3 : V_260 = 5 ; break;
case 4 : V_260 = 6 ; break;
case 5 : V_260 = 1 ; break;
case 6 : V_260 = 2 ; break;
case 7 : V_260 = 9 ; break;
case 8 : V_260 = 10 ; break;
default: return - 1 ;
}
} else {
switch ( V_259 ) {
case 0 : V_260 = 0 ; break;
case 1 : V_260 = 3 ; break;
case 2 : V_260 = 4 ; break;
case 3 : V_260 = 5 ; break;
case 4 : V_260 = 6 ; break;
case 5 : V_260 = 1 ; break;
case 6 : V_260 = 2 ; break;
case 7 : V_260 = 10 ; break;
default: return - 1 ;
}
}
break;
case V_4 :
if ( V_3 -> V_238 ) {
switch ( V_259 ) {
case 0 : V_260 = 0 ; break;
case 1 : V_260 = 3 ; break;
case 2 : V_260 = 1 ; break;
case 3 : V_260 = 2 ; break;
case 4 : V_260 = 9 ; break;
case 5 : V_260 = 10 ; break;
default: return - 1 ;
}
} else {
switch ( V_259 ) {
case 0 : V_260 = 0 ; break;
case 1 : V_260 = 3 ; break;
case 2 : V_260 = 1 ; break;
case 3 : V_260 = 2 ; break;
case 4 : V_260 = 10 ; break;
default: return - 1 ;
}
}
break;
}
switch ( V_3 -> V_5 ) {
case V_6 :
case V_4 :
V_3 -> V_245 &= ~ V_257 ;
V_3 -> V_245 |= V_258 * V_260 ;
F_3 ( V_3 , V_261 , V_3 -> V_245 ) ;
break;
case V_55 :
case V_51 :
case V_37 :
F_3 ( V_3 , V_92 ,
V_3 -> V_29 ) ;
}
return 0 ;
}
static int F_97 ( struct V_222 * V_223 ,
struct V_224 * V_225 )
{
struct V_3 * V_3 = F_77 ( V_223 ) ;
F_98 ( V_225 , 1 , V_3 -> V_262 , V_3 -> V_263 ) ;
return 0 ;
}
static int F_99 ( struct V_222 * V_223 ,
struct V_232 * V_233 )
{
struct V_3 * V_3 = F_77 ( V_223 ) ;
int V_264 = F_95 ( V_3 ) ;
if ( V_264 >= 0 ) {
V_233 -> V_228 . V_234 . V_235 [ 0 ] = V_264 ;
return 0 ;
}
return - 1 ;
}
static int F_100 ( struct V_222 * V_223 ,
struct V_232 * V_233 )
{
struct V_3 * V_3 = F_77 ( V_223 ) ;
int V_8 , V_251 = 0 ;
if ( ! F_13 ( V_3 ) )
return - V_127 ;
V_8 = V_233 -> V_228 . V_234 . V_235 [ 0 ] ;
if ( V_8 < 0 )
V_8 = 0 ;
else if ( V_8 >= V_3 -> V_262 )
V_8 = V_3 -> V_262 - 1 ;
F_36 ( & V_3 -> V_25 ) ;
if ( V_8 != F_95 ( V_3 ) )
V_251 = ( 0 == F_96 ( V_3 , V_8 ) ) ? 1 : 0 ;
F_38 ( & V_3 -> V_25 ) ;
return V_251 ;
}
static int F_19 ( struct V_3 * V_3 )
{
if ( V_37 == V_3 -> V_5 ) {
unsigned int V_32 = F_5 ( V_3 , V_39 ) ;
unsigned int V_35 = ( V_32 >> V_265 ) & 0xF ;
if ( ( V_35 >= V_41 ) &&
( V_35 <= V_266 ) ) {
return V_35 ;
}
return V_267 ;
} else if ( V_55 == V_3 -> V_5 ) {
unsigned int V_33 = F_5 ( V_3 , V_38 ) ;
switch ( V_33 & V_68 ) {
case V_69 :
return V_268 ;
case V_269 :
return V_270 ;
case V_271 :
return V_82 ;
case V_272 :
return V_84 ;
case V_273 :
return V_111 ;
default:
return V_111 ;
}
}
return 0 ;
}
static int F_101 ( struct V_222 * V_223 ,
struct V_224 * V_225 )
{
struct V_3 * V_3 = F_77 ( V_223 ) ;
if ( V_37 == V_3 -> V_5 ) {
static const char * const V_248 [] = { L_10 , L_11 , L_12 , L_13 ,
L_14 , L_15 , L_16 , L_17 , L_18 , L_19 , L_20 , L_21 } ;
F_83 ( V_225 , V_248 ) ;
} else if ( V_55 == V_3 -> V_5 ) {
static const char * const V_248 [] = { L_22 , L_23 , L_19 ,
L_20 , L_21 } ;
F_83 ( V_225 , V_248 ) ;
}
return 0 ;
}
static int F_102 ( struct V_222 * V_223 ,
struct V_232 * V_233 )
{
struct V_3 * V_3 = F_77 ( V_223 ) ;
V_233 -> V_228 . V_234 . V_235 [ 0 ] = F_19 ( V_3 ) ;
return 0 ;
}
static int F_103 ( struct V_222 * V_223 ,
struct V_224 * V_225 )
{
static const char * const V_248 [] = { L_24 , L_25 , L_26 } ;
F_83 ( V_225 , V_248 ) ;
return 0 ;
}
static int F_104 ( struct V_222 * V_223 ,
struct V_232 * V_233 )
{
V_18 V_32 ;
int V_24 = 0 ;
struct V_3 * V_3 = F_77 ( V_223 ) ;
V_32 = F_5 ( V_3 , V_274 + 4 ) ;
switch ( V_32 & ( V_275 |
V_276 ) ) {
case V_275 :
V_24 = 1 ;
break;
case V_276 :
V_24 = 2 ;
break;
default:
V_24 = 0 ;
break;
}
V_233 -> V_228 . V_234 . V_235 [ 0 ] = V_24 ;
return 0 ;
}
static int F_105 ( struct V_222 * V_223 ,
struct V_224 * V_225 )
{
static const char * const V_248 [] = { L_27 , L_28 , L_29 , L_30 ,
L_31 } ;
F_83 ( V_225 , V_248 ) ;
return 0 ;
}
static int F_106 ( struct V_3 * V_3 )
{
V_18 V_32 ;
int V_24 = 0 ;
V_32 = F_5 ( V_3 , V_274 + 4 ) ;
if ( V_32 & V_277 ) {
switch ( V_32 & ( V_278 |
V_279 ) ) {
case 0 :
V_24 = V_280 ;
break;
case V_278 :
V_24 = V_281 ;
break;
case V_279 :
V_24 = V_282 ;
break;
default:
V_24 = V_283 ;
break;
}
}
return V_24 ;
}
static int F_107 ( struct V_222 * V_223 ,
struct V_232 * V_233 )
{
struct V_3 * V_3 = F_77 ( V_223 ) ;
V_233 -> V_228 . V_234 . V_235 [ 0 ] = F_106 ( V_3 ) ;
return 0 ;
}
static int F_108 ( struct V_3 * V_3 , V_18 V_284 )
{
V_18 V_7 ;
if ( F_2 ( V_3 ) )
V_7 = V_3 -> V_245 ;
else
V_7 = V_3 -> V_29 ;
return ( V_7 & V_284 ) ? 1 : 0 ;
}
static int F_86 ( struct V_3 * V_3 , V_18 V_284 , int V_285 )
{
V_18 * V_7 ;
V_18 V_286 ;
if ( F_2 ( V_3 ) ) {
V_7 = & ( V_3 -> V_245 ) ;
V_286 = V_261 ;
} else {
V_7 = & ( V_3 -> V_29 ) ;
V_286 = V_92 ;
}
if ( V_285 )
* V_7 |= V_284 ;
else
* V_7 &= ~ V_284 ;
F_3 ( V_3 , V_286 , * V_7 ) ;
return 0 ;
}
static int F_109 ( struct V_222 * V_223 ,
struct V_232 * V_233 )
{
struct V_3 * V_3 = F_77 ( V_223 ) ;
V_18 V_284 = V_223 -> V_244 ;
F_36 ( & V_3 -> V_25 ) ;
V_233 -> V_228 . integer . V_228 [ 0 ] = F_108 ( V_3 , V_284 ) ;
F_38 ( & V_3 -> V_25 ) ;
return 0 ;
}
static int F_110 ( struct V_222 * V_223 ,
struct V_232 * V_233 )
{
struct V_3 * V_3 = F_77 ( V_223 ) ;
V_18 V_284 = V_223 -> V_244 ;
int V_251 ;
unsigned int V_8 ;
if ( ! F_13 ( V_3 ) )
return - V_127 ;
V_8 = V_233 -> V_228 . integer . V_228 [ 0 ] & 1 ;
F_36 ( & V_3 -> V_25 ) ;
V_251 = ( int ) V_8 != F_108 ( V_3 , V_284 ) ;
F_86 ( V_3 , V_284 , V_8 ) ;
F_38 ( & V_3 -> V_25 ) ;
return V_251 ;
}
static int F_111 ( struct V_3 * V_3 )
{
return ( V_3 -> V_29 & V_287 ) ? 1 : 0 ;
}
static int F_112 ( struct V_3 * V_3 , int V_285 )
{
if ( V_285 )
V_3 -> V_29 |= V_287 ;
else
V_3 -> V_29 &= ~ V_287 ;
F_3 ( V_3 , V_92 , V_3 -> V_29 ) ;
return 0 ;
}
static int F_113 ( struct V_222 * V_223 ,
struct V_224 * V_225 )
{
static const char * const V_248 [] = { L_32 , L_33 } ;
F_83 ( V_225 , V_248 ) ;
return 0 ;
}
static int F_114 ( struct V_222 * V_223 ,
struct V_232 * V_233 )
{
struct V_3 * V_3 = F_77 ( V_223 ) ;
F_36 ( & V_3 -> V_25 ) ;
V_233 -> V_228 . V_234 . V_235 [ 0 ] = F_111 ( V_3 ) ;
F_38 ( & V_3 -> V_25 ) ;
return 0 ;
}
static int F_115 ( struct V_222 * V_223 ,
struct V_232 * V_233 )
{
struct V_3 * V_3 = F_77 ( V_223 ) ;
int V_251 ;
unsigned int V_8 ;
if ( ! F_13 ( V_3 ) )
return - V_127 ;
V_8 = V_233 -> V_228 . integer . V_228 [ 0 ] & 1 ;
F_36 ( & V_3 -> V_25 ) ;
V_251 = ( int ) V_8 != F_111 ( V_3 ) ;
F_112 ( V_3 , V_8 ) ;
F_38 ( & V_3 -> V_25 ) ;
return V_251 ;
}
static int F_116 ( struct V_3 * V_3 )
{
return ( V_3 -> V_29 & V_288 ) ? 1 : 0 ;
}
static int F_117 ( struct V_3 * V_3 , int V_289 )
{
if ( V_289 )
V_3 -> V_29 |= V_288 ;
else
V_3 -> V_29 &= ~ V_288 ;
F_3 ( V_3 , V_92 , V_3 -> V_29 ) ;
return 0 ;
}
static int F_118 ( struct V_222 * V_223 ,
struct V_224 * V_225 )
{
static const char * const V_248 [] = { L_34 , L_35 } ;
F_83 ( V_225 , V_248 ) ;
return 0 ;
}
static int F_119 ( struct V_222 * V_223 ,
struct V_232 * V_233 )
{
struct V_3 * V_3 = F_77 ( V_223 ) ;
F_36 ( & V_3 -> V_25 ) ;
V_233 -> V_228 . V_234 . V_235 [ 0 ] = F_116 ( V_3 ) ;
F_38 ( & V_3 -> V_25 ) ;
return 0 ;
}
static int F_120 ( struct V_222 * V_223 ,
struct V_232 * V_233 )
{
struct V_3 * V_3 = F_77 ( V_223 ) ;
int V_251 ;
unsigned int V_8 ;
if ( ! F_13 ( V_3 ) )
return - V_127 ;
V_8 = V_233 -> V_228 . integer . V_228 [ 0 ] & 1 ;
F_36 ( & V_3 -> V_25 ) ;
V_251 = ( int ) V_8 != F_116 ( V_3 ) ;
F_117 ( V_3 , V_8 ) ;
F_38 ( & V_3 -> V_25 ) ;
return V_251 ;
}
static int F_121 ( struct V_3 * V_3 )
{
if ( V_3 -> V_29 & V_290 )
return 1 ;
if ( V_3 -> V_29 & V_291 )
return 2 ;
return 0 ;
}
static int F_122 ( struct V_3 * V_3 , int V_247 )
{
V_3 -> V_29 &= ~ ( V_290 | V_291 ) ;
switch ( V_247 ) {
case 0 :
break;
case 1 :
V_3 -> V_29 |= V_290 ;
break;
case 2 :
V_3 -> V_29 |= V_291 ;
break;
}
F_3 ( V_3 , V_92 , V_3 -> V_29 ) ;
return 0 ;
}
static int F_123 ( struct V_222 * V_223 ,
struct V_224 * V_225 )
{
static const char * const V_248 [] = { L_34 , L_35 , L_36 } ;
F_83 ( V_225 , V_248 ) ;
return 0 ;
}
static int F_124 ( struct V_222 * V_223 ,
struct V_232 * V_233 )
{
struct V_3 * V_3 = F_77 ( V_223 ) ;
F_36 ( & V_3 -> V_25 ) ;
V_233 -> V_228 . V_234 . V_235 [ 0 ] = F_121 ( V_3 ) ;
F_38 ( & V_3 -> V_25 ) ;
return 0 ;
}
static int F_125 ( struct V_222 * V_223 ,
struct V_232 * V_233 )
{
struct V_3 * V_3 = F_77 ( V_223 ) ;
int V_251 ;
int V_8 ;
if ( ! F_13 ( V_3 ) )
return - V_127 ;
V_8 = V_233 -> V_228 . integer . V_228 [ 0 ] ;
if ( V_8 < 0 )
V_8 = 0 ;
if ( V_8 > 2 )
V_8 = 2 ;
F_36 ( & V_3 -> V_25 ) ;
V_251 = V_8 != F_121 ( V_3 ) ;
F_122 ( V_3 , V_8 ) ;
F_38 ( & V_3 -> V_25 ) ;
return V_251 ;
}
static int F_126 ( struct V_3 * V_3 , V_18 V_284 )
{
V_18 V_7 = V_3 -> V_245 & ( V_284 * 3 ) ;
return V_7 / V_284 ;
}
static int F_127 ( struct V_3 * V_3 , int V_247 , V_18 V_284 )
{
V_3 -> V_245 &= ~ ( V_284 * 3 ) ;
V_3 -> V_245 |= ( V_284 * V_247 ) ;
F_3 ( V_3 , V_261 , V_3 -> V_245 ) ;
return 0 ;
}
static int F_128 ( struct V_222 * V_223 ,
struct V_224 * V_225 )
{
V_18 V_284 = V_223 -> V_244 ;
static const char * const V_292 [] = { L_37 , L_38 , L_39 } ;
static const char * const V_293 [] = { L_40 , L_41 , L_42 } ;
switch ( V_284 ) {
case V_294 :
F_83 ( V_225 , V_292 ) ;
break;
default:
F_83 ( V_225 , V_293 ) ;
break;
}
return 0 ;
}
static int F_129 ( struct V_222 * V_223 ,
struct V_232 * V_233 )
{
struct V_3 * V_3 = F_77 ( V_223 ) ;
V_18 V_284 = V_223 -> V_244 ;
F_36 ( & V_3 -> V_25 ) ;
V_233 -> V_228 . V_234 . V_235 [ 0 ] = F_126 ( V_3 , V_284 ) ;
F_38 ( & V_3 -> V_25 ) ;
return 0 ;
}
static int F_130 ( struct V_222 * V_223 ,
struct V_232 * V_233 )
{
struct V_3 * V_3 = F_77 ( V_223 ) ;
V_18 V_284 = V_223 -> V_244 ;
int V_251 ;
int V_8 ;
if ( ! F_13 ( V_3 ) )
return - V_127 ;
V_8 = V_233 -> V_228 . integer . V_228 [ 0 ] ;
if ( V_8 < 0 )
V_8 = 0 ;
if ( V_8 > 2 )
V_8 = 2 ;
F_36 ( & V_3 -> V_25 ) ;
V_251 = V_8 != F_126 ( V_3 , V_284 ) ;
F_127 ( V_3 , V_8 , V_284 ) ;
F_38 ( & V_3 -> V_25 ) ;
return V_251 ;
}
static int F_131 ( struct V_3 * V_3 )
{
if ( V_3 -> V_29 & V_30 )
return 2 ;
if ( V_3 -> V_29 & V_31 )
return 1 ;
return 0 ;
}
static int F_132 ( struct V_3 * V_3 , int V_247 )
{
V_3 -> V_29 &= ~ ( V_31 | V_30 ) ;
switch ( V_247 ) {
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
static int F_133 ( struct V_222 * V_223 ,
struct V_224 * V_225 )
{
static const char * const V_248 [] = { L_34 , L_35 , L_36 } ;
F_83 ( V_225 , V_248 ) ;
return 0 ;
}
static int F_134 ( struct V_222 * V_223 ,
struct V_232 * V_233 )
{
struct V_3 * V_3 = F_77 ( V_223 ) ;
F_36 ( & V_3 -> V_25 ) ;
V_233 -> V_228 . V_234 . V_235 [ 0 ] = F_131 ( V_3 ) ;
F_38 ( & V_3 -> V_25 ) ;
return 0 ;
}
static int F_135 ( struct V_222 * V_223 ,
struct V_232 * V_233 )
{
struct V_3 * V_3 = F_77 ( V_223 ) ;
int V_251 ;
int V_8 ;
if ( ! F_13 ( V_3 ) )
return - V_127 ;
V_8 = V_233 -> V_228 . integer . V_228 [ 0 ] ;
if ( V_8 < 0 )
V_8 = 0 ;
if ( V_8 > 2 )
V_8 = 2 ;
F_36 ( & V_3 -> V_25 ) ;
V_251 = V_8 != F_131 ( V_3 ) ;
F_132 ( V_3 , V_8 ) ;
F_38 ( & V_3 -> V_25 ) ;
return V_251 ;
}
static int F_136 ( struct V_222 * V_223 ,
struct V_224 * V_225 )
{
V_225 -> type = V_226 ;
V_225 -> V_227 = 3 ;
V_225 -> V_228 . integer . V_229 = 0 ;
V_225 -> V_228 . integer . V_230 = 65535 ;
V_225 -> V_228 . integer . V_231 = 1 ;
return 0 ;
}
static int F_137 ( struct V_222 * V_223 ,
struct V_232 * V_233 )
{
struct V_3 * V_3 = F_77 ( V_223 ) ;
int V_295 ;
int V_296 ;
V_295 = V_233 -> V_228 . integer . V_228 [ 0 ] ;
if ( V_295 < 0 )
V_295 = 0 ;
else if ( V_295 >= 2 * V_95 )
V_295 = 2 * V_95 - 1 ;
V_296 = V_233 -> V_228 . integer . V_228 [ 1 ] ;
if ( V_296 < 0 )
V_296 = 0 ;
else if ( V_296 >= V_95 )
V_296 = V_95 - 1 ;
F_36 ( & V_3 -> V_25 ) ;
if ( V_295 >= V_95 )
V_233 -> V_228 . integer . V_228 [ 2 ] =
F_8 ( V_3 , V_296 ,
V_295 - V_95 ) ;
else
V_233 -> V_228 . integer . V_228 [ 2 ] =
F_7 ( V_3 , V_296 , V_295 ) ;
F_38 ( & V_3 -> V_25 ) ;
return 0 ;
}
static int F_138 ( struct V_222 * V_223 ,
struct V_232 * V_233 )
{
struct V_3 * V_3 = F_77 ( V_223 ) ;
int V_251 ;
int V_295 ;
int V_296 ;
int V_156 ;
if ( ! F_13 ( V_3 ) )
return - V_127 ;
V_295 = V_233 -> V_228 . integer . V_228 [ 0 ] ;
V_296 = V_233 -> V_228 . integer . V_228 [ 1 ] ;
if ( V_295 < 0 || V_295 >= 2 * V_95 )
return - 1 ;
if ( V_296 < 0 || V_296 >= V_95 )
return - 1 ;
V_156 = V_233 -> V_228 . integer . V_228 [ 2 ] ;
F_36 ( & V_3 -> V_25 ) ;
if ( V_295 >= V_95 )
V_251 = V_156 != F_8 ( V_3 , V_296 ,
V_295 -
V_95 ) ;
else
V_251 = V_156 != F_7 ( V_3 , V_296 ,
V_295 ) ;
if ( V_251 ) {
if ( V_295 >= V_95 )
F_10 ( V_3 , V_296 ,
V_295 - V_95 ,
V_156 ) ;
else
F_9 ( V_3 , V_296 , V_295 ,
V_156 ) ;
}
F_38 ( & V_3 -> V_25 ) ;
return V_251 ;
}
static int F_139 ( struct V_222 * V_223 ,
struct V_224 * V_225 )
{
V_225 -> type = V_226 ;
V_225 -> V_227 = 1 ;
V_225 -> V_228 . integer . V_229 = 0 ;
V_225 -> V_228 . integer . V_230 = 64 ;
V_225 -> V_228 . integer . V_231 = 1 ;
return 0 ;
}
static int F_140 ( struct V_222 * V_223 ,
struct V_232 * V_233 )
{
struct V_3 * V_3 = F_77 ( V_223 ) ;
int V_297 ;
V_297 = V_233 -> V_158 . V_240 - 1 ;
if ( F_43 ( V_297 < 0 || V_297 >= V_95 ) )
return - V_125 ;
F_36 ( & V_3 -> V_25 ) ;
V_233 -> V_228 . integer . V_228 [ 0 ] =
( F_8 ( V_3 , V_297 , V_297 ) * 64 ) / V_157 ;
F_38 ( & V_3 -> V_25 ) ;
return 0 ;
}
static int F_141 ( struct V_222 * V_223 ,
struct V_232 * V_233 )
{
struct V_3 * V_3 = F_77 ( V_223 ) ;
int V_251 ;
int V_297 ;
int V_156 ;
if ( ! F_13 ( V_3 ) )
return - V_127 ;
V_297 = V_233 -> V_158 . V_240 - 1 ;
if ( F_43 ( V_297 < 0 || V_297 >= V_95 ) )
return - V_125 ;
V_156 = V_233 -> V_228 . integer . V_228 [ 0 ] * V_157 / 64 ;
F_36 ( & V_3 -> V_25 ) ;
V_251 =
V_156 != F_8 ( V_3 , V_297 ,
V_297 ) ;
if ( V_251 )
F_10 ( V_3 , V_297 , V_297 ,
V_156 ) ;
F_38 ( & V_3 -> V_25 ) ;
return V_251 ;
}
static int F_142 ( struct V_222 * V_223 ,
struct V_224 * V_225 )
{
static const char * const V_248 [] = { L_43 , L_44 , L_45 , L_46 } ;
F_83 ( V_225 , V_248 ) ;
return 0 ;
}
static int F_143 ( struct V_222 * V_223 ,
struct V_224 * V_225 )
{
static const char * const V_248 [] = { L_43 , L_44 } ;
F_83 ( V_225 , V_248 ) ;
return 0 ;
}
static int F_20 ( struct V_3 * V_3 )
{
int V_32 , V_33 ;
switch ( V_3 -> V_5 ) {
case V_37 :
V_32 = F_5 ( V_3 , V_39 ) ;
if ( V_32 & V_298 ) {
if ( V_32 & V_299 )
return 2 ;
else
return 1 ;
}
return 0 ;
break;
case V_55 :
V_33 = F_5 ( V_3 , V_38 ) ;
if ( V_33 & V_56 ) {
if ( V_33 & V_300 )
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
static int F_144 ( struct V_3 * V_3 )
{
int V_32 = F_5 ( V_3 , V_39 ) ;
if ( V_32 & V_52 ) {
if ( V_32 & V_301 )
return 2 ;
else
return 1 ;
}
return 0 ;
}
static int F_145 ( struct V_3 * V_3 , int V_241 )
{
int V_32 , V_25 , V_302 ;
V_32 = F_5 ( V_3 , V_236 ) ;
V_25 = ( V_32 & ( 0x1 << V_241 ) ) ? 1 : 0 ;
V_302 = ( V_32 & ( 0x100 << V_241 ) ) ? 1 : 0 ;
if ( V_25 && V_302 )
return 2 ;
else if ( V_25 )
return 1 ;
return 0 ;
}
static int F_26 ( struct V_3 * V_3 )
{
int V_32 , V_25 = 0 , V_302 = 0 ;
switch ( V_3 -> V_5 ) {
case V_6 :
case V_4 :
V_32 = F_5 ( V_3 , V_303 ) ;
V_25 = ( V_32 & 0x400 ) ? 1 : 0 ;
V_302 = ( V_32 & 0x800 ) ? 1 : 0 ;
break;
case V_55 :
V_32 = F_5 ( V_3 , V_39 ) ;
V_25 = ( V_32 & V_304 ) ? 1 : 0 ;
V_302 = ( V_32 & V_305 ) ? 1 : 0 ;
break;
case V_37 :
V_32 = F_5 ( V_3 , V_38 ) ;
V_25 = ( V_32 & 0x100000 ) ? 1 : 0 ;
V_302 = ( V_32 & 0x200000 ) ? 1 : 0 ;
break;
case V_51 :
break;
}
if ( V_25 && V_302 )
return 2 ;
else if ( V_25 )
return 1 ;
return 0 ;
}
static int F_22 ( struct V_3 * V_3 , int V_241 )
{
int V_33 , V_25 , V_302 ;
V_33 = F_5 ( V_3 , V_38 ) ;
V_25 = ( V_33 & ( 0x0080 >> V_241 ) ) ? 1 : 0 ;
V_302 = ( V_33 & ( 0x8000 >> V_241 ) ) ? 1 : 0 ;
if ( V_302 )
return 2 ;
else if ( V_25 )
return 1 ;
return 0 ;
}
static int F_146 ( struct V_3 * V_3 , V_18 V_306 )
{
V_18 V_32 ;
V_32 = F_5 ( V_3 , V_274 + 4 ) ;
return ( V_32 & V_306 ) ? 1 : 0 ;
}
static int F_24 ( struct V_3 * V_3 )
{
int V_32 ;
if ( V_3 -> V_238 ) {
switch ( V_3 -> V_5 ) {
case V_55 :
V_32 = F_5 ( V_3 , V_39 ) ;
if ( V_32 & V_307 ) {
if ( V_32 & V_308 )
return 2 ;
else
return 1 ;
}
return 0 ;
case V_37 :
V_32 = F_5 ( V_3 , V_39 ) ;
if ( V_32 & V_309 ) {
if ( V_32 & V_308 )
return 2 ;
else
return 1 ;
}
return 0 ;
case V_6 :
case V_4 :
V_32 = F_5 ( V_3 , V_236 ) ;
if ( V_32 & 0x8000000 )
return 2 ;
if ( V_32 & 0x4000000 )
return 1 ;
return 0 ;
default:
break;
}
}
return 3 ;
}
static int F_147 ( struct V_222 * V_223 ,
struct V_232 * V_233 )
{
struct V_3 * V_3 = F_77 ( V_223 ) ;
int V_8 = - 1 ;
switch ( V_3 -> V_5 ) {
case V_6 :
switch ( V_223 -> V_244 ) {
case 0 :
V_8 = F_20 ( V_3 ) ; break;
case 7 :
V_8 = F_24 ( V_3 ) ; break;
case 8 :
V_8 = F_26 ( V_3 ) ; break;
default:
V_8 = F_145 ( V_3 ,
V_223 -> V_244 - 1 ) ;
}
break;
case V_4 :
switch ( V_223 -> V_244 ) {
case 0 :
V_8 = F_20 ( V_3 ) ; break;
case 4 :
V_8 = F_24 ( V_3 ) ; break;
case 5 :
V_8 = F_26 ( V_3 ) ; break;
default:
V_8 = F_145 ( V_3 ,
V_223 -> V_244 - 1 ) ;
}
break;
case V_55 :
switch ( V_223 -> V_244 ) {
case 0 :
V_8 = F_20 ( V_3 ) ; break;
case 1 :
V_8 = F_144 ( V_3 ) ; break;
case 2 :
V_8 = F_24 ( V_3 ) ; break;
case 3 :
V_8 = F_26 ( V_3 ) ; break;
}
break;
case V_51 :
V_8 = F_144 ( V_3 ) ;
break;
case V_37 :
switch ( V_223 -> V_244 ) {
case 0 :
V_8 = F_20 ( V_3 ) ; break;
case 9 :
V_8 = F_24 ( V_3 ) ; break;
case 10 :
V_8 = F_26 ( V_3 ) ; break;
default:
V_8 = F_22 ( V_3 ,
V_223 -> V_244 - 1 ) ;
}
break;
}
if ( V_3 -> V_238 ) {
switch ( V_223 -> V_244 ) {
case 11 :
V_8 = F_146 ( V_3 , V_310 ) ;
break;
case 12 :
V_8 = F_146 ( V_3 ,
V_277 ) ;
break;
default:
break;
}
}
if ( - 1 == V_8 )
V_8 = 3 ;
V_233 -> V_228 . V_234 . V_235 [ 0 ] = V_8 ;
return 0 ;
}
static void F_148 ( struct V_3 * V_3 )
{
unsigned int V_311 [ 4 ] = { 0 , 0 , 0 , 0 } ;
switch ( V_3 -> V_238 -> V_170 ) {
case 0 :
V_311 [ 2 ] |= V_312 ;
break;
case 1 :
V_311 [ 2 ] |= V_313 ;
break;
default:
break;
}
switch ( V_3 -> V_238 -> V_314 ) {
case 1 :
V_311 [ 1 ] |= V_278 ;
break;
case 2 :
V_311 [ 1 ] |= V_279 ;
break;
case 3 :
V_311 [ 1 ] |= V_279 +
V_315 ;
break;
case 4 :
V_311 [ 1 ] |= V_278 +
V_279 ;
break;
case 5 :
V_311 [ 1 ] |= V_278 +
V_279 +
V_315 ;
break;
default:
break;
}
switch ( V_3 -> V_238 -> V_316 ) {
case 1 :
V_311 [ 2 ] |= V_317 ;
break;
case 2 :
V_311 [ 2 ] |= V_318 ;
break;
default:
break;
}
switch ( V_3 -> V_238 -> V_319 ) {
case 1 :
V_311 [ 2 ] |= V_320 ;
break;
case 2 :
V_311 [ 2 ] |= V_321 ;
break;
default:
break;
}
switch ( V_3 -> V_238 -> V_322 ) {
case 1 :
V_311 [ 2 ] |= V_323 ;
break;
case 2 :
V_311 [ 2 ] |= V_324 ;
break;
case 3 :
V_311 [ 2 ] |= V_323 + V_325 ;
break;
case 4 :
V_311 [ 2 ] |= V_324 + V_325 ;
break;
default:
break;
}
if ( 1 == V_3 -> V_238 -> V_326 ) {
V_311 [ 2 ] |= V_327 ;
}
F_3 ( V_3 , V_328 , V_311 [ 0 ] ) ;
F_3 ( V_3 , V_328 + 4 , V_311 [ 1 ] ) ;
F_3 ( V_3 , V_328 + 8 , V_311 [ 2 ] ) ;
F_3 ( V_3 , V_328 + 12 , V_311 [ 3 ] ) ;
}
static int F_149 ( struct V_222 * V_223 ,
struct V_224 * V_225 )
{
static const char * const V_248 [] = { L_47 , L_48 } ;
F_83 ( V_225 , V_248 ) ;
return 0 ;
}
static int F_150 ( struct V_222 * V_223 ,
struct V_232 * V_233 )
{
struct V_3 * V_3 = F_77 ( V_223 ) ;
V_233 -> V_228 . V_234 . V_235 [ 0 ] = V_3 -> V_238 -> V_319 ;
return 0 ;
}
static int F_151 ( struct V_222 * V_223 ,
struct V_232 * V_233 )
{
struct V_3 * V_3 = F_77 ( V_223 ) ;
if ( V_3 -> V_238 -> V_319 != V_233 -> V_228 . V_234 . V_235 [ 0 ] ) {
V_3 -> V_238 -> V_319 = V_233 -> V_228 . V_234 . V_235 [ 0 ] ;
F_148 ( V_3 ) ;
return 1 ;
}
return 0 ;
}
static int F_152 ( struct V_222 * V_223 ,
struct V_224 * V_225 )
{
static const char * const V_248 [] = { L_49 , L_50 , L_51 ,
L_52 , L_53 } ;
F_83 ( V_225 , V_248 ) ;
return 0 ;
}
static int F_153 ( struct V_222 * V_223 ,
struct V_232 * V_233 )
{
struct V_3 * V_3 = F_77 ( V_223 ) ;
V_233 -> V_228 . V_234 . V_235 [ 0 ] = V_3 -> V_238 -> V_322 ;
return 0 ;
}
static int F_154 ( struct V_222 * V_223 ,
struct V_232 * V_233 )
{
struct V_3 * V_3 = F_77 ( V_223 ) ;
if ( V_3 -> V_238 -> V_322 != V_233 -> V_228 . V_234 . V_235 [ 0 ] ) {
V_3 -> V_238 -> V_322 = V_233 -> V_228 . V_234 . V_235 [ 0 ] ;
F_148 ( V_3 ) ;
return 1 ;
}
return 0 ;
}
static int F_155 ( struct V_222 * V_223 ,
struct V_224 * V_225 )
{
static const char * const V_248 [] = { L_54 , L_55 , L_56 } ;
F_83 ( V_225 , V_248 ) ;
return 0 ;
}
static int F_156 ( struct V_222 * V_223 ,
struct V_232 * V_233 )
{
struct V_3 * V_3 = F_77 ( V_223 ) ;
V_233 -> V_228 . V_234 . V_235 [ 0 ] = V_3 -> V_238 -> V_316 ;
return 0 ;
}
static int F_157 ( struct V_222 * V_223 ,
struct V_232 * V_233 )
{
struct V_3 * V_3 = F_77 ( V_223 ) ;
if ( V_3 -> V_238 -> V_316 != V_233 -> V_228 . V_234 . V_235 [ 0 ] ) {
V_3 -> V_238 -> V_316 = V_233 -> V_228 . V_234 . V_235 [ 0 ] ;
F_148 ( V_3 ) ;
return 1 ;
}
return 0 ;
}
static int F_158 ( struct V_222 * V_223 ,
struct V_224 * V_225 )
{
static const char * const V_248 [] = { L_28 , L_29 , L_57 ,
L_58 , L_31 , L_59 } ;
F_83 ( V_225 , V_248 ) ;
return 0 ;
}
static int F_159 ( struct V_222 * V_223 ,
struct V_232 * V_233 )
{
struct V_3 * V_3 = F_77 ( V_223 ) ;
V_233 -> V_228 . V_234 . V_235 [ 0 ] = V_3 -> V_238 -> V_314 ;
return 0 ;
}
static int F_160 ( struct V_222 * V_223 ,
struct V_232 * V_233 )
{
struct V_3 * V_3 = F_77 ( V_223 ) ;
if ( V_3 -> V_238 -> V_314 != V_233 -> V_228 . V_234 . V_235 [ 0 ] ) {
V_3 -> V_238 -> V_314 = V_233 -> V_228 . V_234 . V_235 [ 0 ] ;
F_148 ( V_3 ) ;
return 1 ;
}
return 0 ;
}
static int F_161 ( struct V_222 * V_223 ,
struct V_224 * V_225 )
{
static const char * const V_248 [] = { L_60 , L_61 , L_62 } ;
F_83 ( V_225 , V_248 ) ;
return 0 ;
}
static int F_162 ( struct V_222 * V_223 ,
struct V_232 * V_233 )
{
struct V_3 * V_3 = F_77 ( V_223 ) ;
V_233 -> V_228 . V_234 . V_235 [ 0 ] = V_3 -> V_238 -> V_170 ;
return 0 ;
}
static int F_163 ( struct V_222 * V_223 ,
struct V_232 * V_233 )
{
struct V_3 * V_3 = F_77 ( V_223 ) ;
if ( V_3 -> V_238 -> V_170 != V_233 -> V_228 . V_234 . V_235 [ 0 ] ) {
V_3 -> V_238 -> V_170 = V_233 -> V_228 . V_234 . V_235 [ 0 ] ;
F_148 ( V_3 ) ;
return 1 ;
}
return 0 ;
}
static int F_164 ( struct V_222 * V_223 ,
struct V_224 * V_225 )
{
V_225 -> type = V_329 ;
V_225 -> V_227 = 1 ;
V_225 -> V_228 . integer . V_229 = 0 ;
V_225 -> V_228 . integer . V_230 = 1 ;
return 0 ;
}
static int F_165 ( struct V_222 * V_223 ,
struct V_232 * V_233 )
{
struct V_3 * V_3 = F_77 ( V_223 ) ;
V_233 -> V_228 . V_234 . V_235 [ 0 ] = V_3 -> V_238 -> V_326 ;
return 0 ;
}
static int F_166 ( struct V_222 * V_223 ,
struct V_232 * V_233 )
{
struct V_3 * V_3 = F_77 ( V_223 ) ;
if ( V_3 -> V_238 -> V_326 != V_233 -> V_228 . V_234 . V_235 [ 0 ] ) {
V_3 -> V_238 -> V_326 = V_233 -> V_228 . V_234 . V_235 [ 0 ] ;
F_148 ( V_3 ) ;
return 1 ;
}
return 0 ;
}
static int F_167 ( struct V_3 * V_3 )
{
int V_19 ;
for ( V_19 = V_3 -> V_145 ; V_19 < V_3 -> V_137 ; ++ V_19 ) {
if ( V_3 -> V_112 > 48000 ) {
V_3 -> V_330 [ V_19 ] -> V_331 [ 0 ] . V_332 =
V_333 |
V_334 |
V_335 ;
} else {
V_3 -> V_330 [ V_19 ] -> V_331 [ 0 ] . V_332 =
V_336 |
V_335 ;
}
F_168 ( V_3 -> V_108 , V_337 |
V_338 ,
& V_3 -> V_330 [ V_19 ] -> V_158 ) ;
}
return 0 ;
}
static int F_169 ( struct V_183 * V_108 ,
struct V_3 * V_3 )
{
unsigned int V_241 , V_339 ;
int V_184 ;
struct V_222 * V_340 ;
struct V_341 * V_342 = NULL ;
switch ( V_3 -> V_5 ) {
case V_55 :
V_342 = V_343 ;
V_339 = F_170 ( V_343 ) ;
break;
case V_51 :
V_342 = V_344 ;
V_339 = F_170 ( V_344 ) ;
break;
case V_4 :
V_342 = V_345 ;
V_339 = F_170 ( V_345 ) ;
break;
case V_6 :
V_342 = V_346 ;
V_339 = F_170 ( V_346 ) ;
break;
case V_37 :
V_342 = V_347 ;
V_339 = F_170 ( V_347 ) ;
break;
}
if ( NULL != V_342 ) {
for ( V_241 = 0 ; V_241 < V_339 ; V_241 ++ ) {
V_184 = F_171 ( V_108 ,
F_172 ( & V_342 [ V_241 ] , V_3 ) ) ;
if ( V_184 < 0 )
return V_184 ;
}
}
V_348 . V_210 = L_63 ;
if ( V_3 -> V_112 >= 128000 ) {
V_339 = V_3 -> V_151 ;
} else if ( V_3 -> V_112 >= 64000 ) {
V_339 = V_3 -> V_145 ;
} else {
V_339 = V_3 -> V_137 ;
}
for ( V_241 = 0 ; V_241 < V_339 ; ++ V_241 ) {
V_348 . V_240 = V_241 + 1 ;
V_340 = F_172 ( & V_348 , V_3 ) ;
V_184 = F_171 ( V_108 , V_340 ) ;
if ( V_184 < 0 )
return V_184 ;
V_3 -> V_330 [ V_241 ] = V_340 ;
}
if ( V_3 -> V_238 ) {
V_342 = V_349 ;
V_339 = F_170 ( V_349 ) ;
for ( V_241 = 0 ; V_241 < V_339 ; V_241 ++ ) {
V_184 = F_171 ( V_108 ,
F_172 ( & V_342 [ V_241 ] , V_3 ) ) ;
if ( V_184 < 0 )
return V_184 ;
}
}
return 0 ;
}
static void
F_173 ( struct V_350 * V_351 ,
struct V_352 * V_353 )
{
struct V_3 * V_3 = V_351 -> V_177 ;
unsigned int V_32 , V_354 ;
int V_355 , V_356 , V_97 , V_357 , V_358 , V_359 ;
unsigned int V_99 ;
T_2 V_100 = 0 ;
V_18 V_28 ;
F_174 ( V_353 , L_64 ) ;
V_32 = F_5 ( V_3 , V_39 ) ;
V_354 = V_3 -> V_29 ;
if ( V_32 & V_360 ) {
F_174 ( V_353 , L_65 ) ;
V_355 = F_5 ( V_3 , V_274 + 4 ) ;
if ( V_355 & V_277 ) {
F_174 ( V_353 , L_66 ) ;
switch ( V_355 & ( V_278 |
V_279 ) ) {
case 0 :
F_174 ( V_353 , L_67 ) ;
break;
case V_278 :
F_174 ( V_353 , L_68 ) ;
break;
case V_279 :
F_174 ( V_353 , L_69 ) ;
break;
default:
F_174 ( V_353 , L_70 ) ;
break;
}
if ( V_355 & V_315 ) {
F_174 ( V_353 , L_71 ) ;
} else {
F_174 ( V_353 , L_72 ) ;
}
} else {
F_174 ( V_353 , L_73 ) ;
}
if ( V_355 & V_275 ) {
F_174 ( V_353 , L_74 ) ;
} else if ( V_355 & V_276 ) {
F_174 ( V_353 , L_75 ) ;
} else {
F_174 ( V_353 , L_76 ) ;
}
if ( V_355 & V_310 ) {
F_174 ( V_353 , L_77 ) ;
} else {
F_174 ( V_353 , L_78 ) ;
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
V_99 = F_5 ( V_3 , V_221 ) ;
F_174 ( V_353 , L_79 , V_99 ) ;
V_28 = F_41 ( V_100 , V_99 ) ;
if ( V_354 & V_30 ) {
V_28 *= 4 ;
} else if ( V_354 & V_31 ) {
V_28 *= 2 ;
}
F_174 ( V_353 , L_80 ,
( unsigned int ) V_28 ) ;
V_356 = F_5 ( V_3 , V_274 ) ;
V_97 = V_356 & 0xF ;
V_356 >>= 4 ;
V_97 += ( V_356 & 0x3 ) * 10 ;
V_356 >>= 4 ;
V_357 = V_356 & 0xF ;
V_356 >>= 4 ;
V_357 += ( V_356 & 0x7 ) * 10 ;
V_356 >>= 4 ;
V_358 = V_356 & 0xF ;
V_356 >>= 4 ;
V_358 += ( V_356 & 0x7 ) * 10 ;
V_356 >>= 4 ;
V_359 = V_356 & 0xF ;
V_356 >>= 4 ;
V_359 += ( V_356 & 0x3 ) * 10 ;
F_174 ( V_353 ,
L_81 ,
V_359 , V_358 , V_357 , V_97 ) ;
} else {
F_174 ( V_353 , L_82 ) ;
}
}
static void
F_175 ( struct V_350 * V_351 ,
struct V_352 * V_353 )
{
struct V_3 * V_3 = V_351 -> V_177 ;
unsigned int V_32 , V_33 , V_354 , V_361 ;
char * V_362 ;
char * V_363 ;
char * V_364 ;
char * V_365 ;
int V_366 , V_367 ;
V_32 = F_5 ( V_3 , V_39 ) ;
V_33 = F_5 ( V_3 , V_38 ) ;
V_354 = V_3 -> V_29 ;
V_361 = F_5 ( V_3 , V_40 ) ;
F_174 ( V_353 , L_83 ,
V_3 -> V_368 , V_3 -> V_108 -> V_369 + 1 ,
V_3 -> V_370 ,
( V_33 & V_371 ) |
( V_33 & V_372 ) | ( V_33 &
V_373 ) ) ;
F_174 ( V_353 , L_84 ,
( F_5 ( V_3 , V_199 ) >> 8 ) & 0xFFFFFF ,
V_3 -> V_374 ) ;
F_174 ( V_353 , L_85 ,
V_3 -> V_190 , V_3 -> V_375 , ( unsigned long ) V_3 -> V_9 ) ;
F_174 ( V_353 , L_86 ) ;
F_174 ( V_353 ,
L_87 ,
V_32 & V_376 ,
( V_32 & V_197 ) ? 1 : 0 ,
( V_32 & V_203 ) ? 1 : 0 ,
V_3 -> V_377 ) ;
F_174 ( V_353 ,
L_88
L_89 ,
( ( V_32 & V_88 ) ? 1 : 0 ) ,
( V_32 & V_87 ) ,
( V_32 & V_87 ) %
( 2 * ( int ) V_3 -> V_85 ) ,
( ( V_32 & V_87 ) - 64 ) %
( 2 * ( int ) V_3 -> V_85 ) ,
( long ) F_31 ( V_3 ) * 4 ) ;
F_174 ( V_353 ,
L_90 ,
F_5 ( V_3 , V_195 ) & 0xFF ,
F_5 ( V_3 , V_201 ) & 0xFF ,
F_5 ( V_3 , V_193 ) & 0xFF ,
F_5 ( V_3 , V_199 ) & 0xFF ) ;
F_174 ( V_353 ,
L_91 ,
F_5 ( V_3 , V_186 ) & 0xFF ,
F_5 ( V_3 , V_188 ) & 0xFF ) ;
F_174 ( V_353 ,
L_92
L_93 ,
V_3 -> V_29 , V_3 -> V_378 ,
V_32 , V_33 ) ;
F_174 ( V_353 , L_94 ) ;
V_366 = F_28 ( V_3 ) ;
F_174 ( V_353 ,
L_95 ,
V_366 , ( unsigned long ) V_3 -> V_85 ) ;
F_174 ( V_353 , L_96 ,
( V_3 -> V_29 & V_379 ) ? L_97 : L_98 ) ;
switch ( V_3 -> V_29 & V_380 ) {
case V_381 :
V_365 = L_37 ;
break;
case V_382 :
V_365 = L_38 ;
break;
default:
V_365 = L_99 ;
}
F_174 ( V_353 ,
L_100
L_101 ,
( V_3 -> V_29 & V_383 ) ? L_102 : L_98 ,
( V_3 -> V_29 & V_384 ) ? L_103 : L_104 ,
( V_3 -> V_29 & V_385 ) ? L_102 : L_98 ) ;
if ( ! ( V_3 -> V_29 & V_107 ) )
V_364 = L_9 ;
else
V_364 = L_8 ;
F_174 ( V_353 , L_105 , V_364 ) ;
switch ( F_95 ( V_3 ) ) {
case V_386 :
V_362 = L_22 ;
break;
case V_387 :
V_362 = L_106 ;
break;
case V_388 :
V_362 = L_19 ;
break;
case V_389 :
V_362 = L_20 ;
break;
default:
V_362 = L_107 ;
break;
}
F_174 ( V_353 , L_108 ,
V_362 ) ;
F_174 ( V_353 , L_109 ,
V_3 -> V_112 ) ;
F_174 ( V_353 , L_110 ) ;
V_366 = V_32 & V_301 ;
V_367 = V_33 & V_300 ;
F_174 ( V_353 , L_111 ,
( V_32 & V_52 ) ? ( V_366 ? L_45 : L_44 ) :
L_112 ,
( V_33 & V_56 ) ? ( V_367 ? L_45 : L_44 ) :
L_112 ) ;
switch ( F_19 ( V_3 ) ) {
case V_84 :
V_363 = L_20 ;
break;
case V_82 :
V_363 = L_19 ;
break;
case V_268 :
V_363 = L_22 ;
break;
case V_270 :
V_363 = L_106 ;
break;
case V_111 :
V_363 = L_113 ;
break;
default:
V_363 = L_114 ;
break;
}
F_174 ( V_353 ,
L_115 ,
V_363 , F_18 ( V_3 ) ,
( V_32 & V_70 ) >> 22 ,
( V_33 & V_58 ) >> 5 ) ;
F_174 ( V_353 , L_116 ,
( V_32 & V_390 ) ? L_117 : L_37 ,
( V_32 & V_391 ) ? L_118 :
L_119 ) ;
F_173 ( V_351 , V_353 ) ;
F_174 ( V_353 , L_120 ) ;
}
static void
F_176 ( struct V_350 * V_351 ,
struct V_352 * V_353 )
{
struct V_3 * V_3 = V_351 -> V_177 ;
unsigned int V_32 ;
unsigned int V_33 ;
unsigned int V_34 ;
unsigned int V_392 , V_393 ;
int V_394 ;
char * V_363 ;
int V_366 ;
V_32 = F_5 ( V_3 , V_39 ) ;
V_33 = F_5 ( V_3 , V_38 ) ;
V_34 = F_5 ( V_3 , V_40 ) ;
F_174 ( V_353 , L_121 ,
V_3 -> V_368 , V_3 -> V_108 -> V_369 + 1 ,
V_3 -> V_370 ) ;
F_174 ( V_353 , L_85 ,
V_3 -> V_190 , V_3 -> V_375 , ( unsigned long ) V_3 -> V_9 ) ;
F_174 ( V_353 , L_86 ) ;
F_174 ( V_353 ,
L_87 ,
V_32 & V_376 ,
( V_32 & V_197 ) ? 1 : 0 ,
( V_32 & V_203 ) ? 1 : 0 ,
V_3 -> V_377 ) ;
F_174 ( V_353 ,
L_88
L_89 ,
( ( V_32 & V_88 ) ? 1 : 0 ) ,
( V_32 & V_87 ) ,
( V_32 & V_87 ) %
( 2 * ( int ) V_3 -> V_85 ) ,
( ( V_32 & V_87 ) - 64 ) %
( 2 * ( int ) V_3 -> V_85 ) ,
( long ) F_31 ( V_3 ) * 4 ) ;
F_174 ( V_353 ,
L_90 ,
F_5 ( V_3 , V_195 ) & 0xFF ,
F_5 ( V_3 , V_201 ) & 0xFF ,
F_5 ( V_3 , V_193 ) & 0xFF ,
F_5 ( V_3 , V_199 ) & 0xFF ) ;
F_174 ( V_353 ,
L_91 ,
F_5 ( V_3 , V_186 ) & 0xFF ,
F_5 ( V_3 , V_188 ) & 0xFF ) ;
F_174 ( V_353 ,
L_92
L_93 ,
V_3 -> V_29 , V_3 -> V_378 ,
V_32 , V_33 ) ;
F_174 ( V_353 , L_94 ) ;
V_366 = F_28 ( V_3 ) ;
F_174 ( V_353 ,
L_95 ,
V_366 , ( unsigned long ) V_3 -> V_85 ) ;
F_174 ( V_353 , L_96 ,
( V_3 ->
V_29 & V_379 ) ? L_97 : L_98 ) ;
F_174 ( V_353 ,
L_122 ,
( V_3 ->
V_29 & V_383 ) ? L_102 : L_98 ,
( V_3 ->
V_29 & V_395 ) ? L_102 : L_98 ,
( V_3 ->
V_29 & V_396 ) ? L_102 : L_98 ) ;
V_394 = F_95 ( V_3 ) ;
if ( V_394 == 0 )
F_174 ( V_353 , L_123 ) ;
else
F_174 ( V_353 , L_124 ,
V_394 ) ;
F_174 ( V_353 , L_109 ,
V_3 -> V_112 ) ;
F_174 ( V_353 , L_125 ,
V_3 -> V_29 & V_288 ?
L_126 : L_127 ) ;
F_174 ( V_353 , L_128 ,
V_3 -> V_29 & V_290 ?
L_126 :
V_3 -> V_29 & V_291 ?
L_129 : L_127 ) ;
F_174 ( V_353 , L_110 ) ;
V_392 = V_32 & V_298 ;
V_393 = V_392 && ( V_32 & V_299 ) ;
F_174 ( V_353 , L_130 ,
( V_392 ) ? ( V_393 ? L_131 : L_132 ) : L_43 ,
F_1 ( ( V_32 >> V_237 ) & 0xF ) ) ;
for ( V_366 = 0 ; V_366 < 8 ; V_366 ++ ) {
F_174 ( V_353 , L_133 ,
V_366 + 1 ,
( V_33 & ( V_397 >> V_366 ) ) ?
L_131 : L_43 ,
F_1 ( ( V_34 >> ( 4 * V_366 ) ) & 0xF ) ) ;
}
switch ( F_19 ( V_3 ) ) {
case V_267 :
V_363 = L_21 ; break;
case V_41 :
V_363 = L_22 ; break;
case V_42 :
V_363 = L_11 ; break;
case V_43 :
V_363 = L_12 ; break;
case V_44 :
V_363 = L_13 ; break;
case V_45 :
V_363 = L_14 ; break;
case V_46 :
V_363 = L_15 ; break;
case V_47 :
V_363 = L_16 ; break;
case V_48 :
V_363 = L_17 ; break;
case V_49 :
V_363 = L_18 ; break;
case V_50 :
V_363 = L_19 ; break;
case V_266 :
V_363 = L_20 ; break;
default:
V_363 = L_114 ; break;
}
F_174 ( V_353 , L_134 , V_363 ) ;
F_173 ( V_351 , V_353 ) ;
F_174 ( V_353 , L_120 ) ;
}
static void
F_177 ( struct V_350 * V_351 ,
struct V_352 * V_353 )
{
struct V_3 * V_3 = V_351 -> V_177 ;
unsigned int V_398 , V_33 , V_399 , V_354 , V_19 ;
unsigned int V_25 , V_302 ;
V_398 = F_5 ( V_3 , V_236 ) ;
V_33 = F_5 ( V_3 , V_239 ) ;
V_399 = F_5 ( V_3 , V_303 ) ;
V_354 = V_3 -> V_29 ;
F_174 ( V_353 , L_135 , V_398 ) ;
F_174 ( V_353 , L_136 , V_33 ) ;
F_174 ( V_353 , L_137 , V_399 ) ;
F_174 ( V_353 , L_138 ) ;
F_174 ( V_353 , L_139 ,
( F_74 ( V_3 ) == 0 ) ? L_140 : L_141 ) ;
F_174 ( V_353 , L_142 ,
F_73 ( V_3 ) ) ;
F_174 ( V_353 , L_143 ) ;
V_25 = 0x1 ;
V_302 = 0x100 ;
for ( V_19 = 0 ; V_19 < 8 ; V_19 ++ ) {
F_174 ( V_353 , L_144 ,
V_19 ,
( V_398 & V_25 ) ? 1 : 0 ,
( V_398 & V_302 ) ? 1 : 0 ,
V_243 [ ( V_33 >> ( V_19 * 4 ) ) & 0xF ] ) ;
V_25 = V_25 << 1 ;
V_302 = V_302 << 1 ;
}
F_174 ( V_353 , L_145 ,
( V_398 & 0x1000000 ) ? 1 : 0 ,
( V_398 & 0x2000000 ) ? 1 : 0 ,
V_243 [ ( V_398 >> 16 ) & 0xF ] ) ;
F_174 ( V_353 , L_146 ,
( V_398 & 0x4000000 ) ? 1 : 0 ,
( V_398 & 0x8000000 ) ? 1 : 0 ,
V_243 [ ( V_398 >> 20 ) & 0xF ] ) ;
F_174 ( V_353 , L_147 ,
( V_399 & 0x400 ) ? 1 : 0 ,
( V_399 & 0x800 ) ? 1 : 0 ,
V_243 [ ( V_33 >> 12 ) & 0xF ] ) ;
}
static void
F_178 ( struct V_350 * V_351 ,
struct V_352 * V_353 )
{
struct V_3 * V_3 = V_351 -> V_177 ;
int V_155 , V_19 ;
for ( V_19 = 0 ; V_19 < 256 ; V_19 += V_155 ) {
F_174 ( V_353 , L_148 , V_19 ) ;
for ( V_155 = 0 ; V_155 < 16 ; V_155 += 4 )
F_174 ( V_353 , L_149 , F_5 ( V_3 , V_19 + V_155 ) ) ;
F_174 ( V_353 , L_120 ) ;
}
}
static void F_179 ( struct V_350 * V_351 ,
struct V_352 * V_353 )
{
struct V_3 * V_3 = V_351 -> V_177 ;
int V_19 ;
F_174 ( V_353 , L_150 ) ;
for ( V_19 = 0 ; V_19 < V_3 -> V_134 ; V_19 ++ ) {
F_174 ( V_353 , L_151 , V_19 + 1 , V_3 -> V_138 [ V_19 ] ) ;
}
}
static void F_180 ( struct V_350 * V_351 ,
struct V_352 * V_353 )
{
struct V_3 * V_3 = V_351 -> V_177 ;
int V_19 ;
F_174 ( V_353 , L_150 ) ;
for ( V_19 = 0 ; V_19 < V_3 -> V_136 ; V_19 ++ ) {
F_174 ( V_353 , L_151 , V_19 + 1 , V_3 -> V_140 [ V_19 ] ) ;
}
}
static void F_181 ( struct V_3 * V_3 )
{
struct V_350 * V_351 ;
if ( ! F_182 ( V_3 -> V_108 , L_152 , & V_351 ) ) {
switch ( V_3 -> V_5 ) {
case V_37 :
F_183 ( V_351 , V_3 ,
F_176 ) ;
break;
case V_55 :
F_183 ( V_351 , V_3 ,
F_175 ) ;
break;
case V_51 :
break;
case V_6 :
F_183 ( V_351 , V_3 ,
F_177 ) ;
break;
case V_4 :
break;
}
}
if ( ! F_182 ( V_3 -> V_108 , L_153 , & V_351 ) ) {
F_183 ( V_351 , V_3 , F_179 ) ;
}
if ( ! F_182 ( V_3 -> V_108 , L_154 , & V_351 ) ) {
F_183 ( V_351 , V_3 , F_180 ) ;
}
#ifdef F_184
if ( ! F_182 ( V_3 -> V_108 , L_155 , & V_351 ) )
F_183 ( V_351 , V_3 ,
F_178 ) ;
#endif
}
static int F_185 ( struct V_3 * V_3 )
{
V_3 -> V_245 = 0 ;
switch ( V_3 -> V_5 ) {
case V_55 :
case V_51 :
V_3 -> V_29 =
0x2 + 0x8 + 0x10 + 0x80 + 0x400 + 0x4000 + 0x1000000 ;
break;
case V_6 :
case V_4 :
V_3 -> V_245 = 0x1 + 0x1000 ;
V_3 -> V_29 =
0x2 + 0x8 + 0x10 + 0x80 + 0x400 + 0x4000 + 0x1000000 ;
break;
case V_37 :
V_3 -> V_29 =
V_107 |
F_37 ( 7 ) |
V_253 |
V_379 |
V_400 ;
break;
}
F_3 ( V_3 , V_92 , V_3 -> V_29 ) ;
if ( V_37 == V_3 -> V_5 ) {
#ifdef F_186
V_3 -> V_378 = V_401 ;
#else
V_3 -> V_378 = 0 ;
#endif
F_3 ( V_3 , V_402 , V_3 -> V_378 ) ;
}
F_30 ( V_3 ) ;
F_47 ( V_3 , 0 * V_157 ) ;
if ( F_2 ( V_3 ) )
F_3 ( V_3 , V_261 , V_3 -> V_245 ) ;
F_44 ( V_3 , 48000 , 1 ) ;
return 0 ;
}
static T_3 F_187 ( int V_190 , void * V_403 )
{
struct V_3 * V_3 = (struct V_3 * ) V_403 ;
unsigned int V_32 ;
int V_19 , V_404 , V_159 , V_405 = 0 ;
V_32 = F_5 ( V_3 , V_39 ) ;
V_404 = V_32 & V_376 ;
V_159 = V_32 & ( V_197 | V_203 |
V_191 | V_208 ) ;
if ( ! V_404 && ! V_159 )
return V_406 ;
F_3 ( V_3 , V_407 , 0 ) ;
V_3 -> V_377 ++ ;
if ( V_404 ) {
if ( V_3 -> V_408 )
F_188 ( V_3 -> V_408 ) ;
if ( V_3 -> V_409 )
F_188 ( V_3 -> V_409 ) ;
}
if ( V_159 ) {
V_19 = 0 ;
while ( V_19 < V_3 -> V_220 ) {
if ( ( F_5 ( V_3 ,
V_3 -> V_159 [ V_19 ] . V_162 ) & 0xff ) &&
( V_32 & V_3 -> V_159 [ V_19 ] . V_190 ) ) {
V_3 -> V_29 &= ~ V_3 -> V_159 [ V_19 ] . V_172 ;
F_3 ( V_3 , V_92 ,
V_3 -> V_29 ) ;
V_3 -> V_159 [ V_19 ] . V_171 = 1 ;
V_405 = 1 ;
}
V_19 ++ ;
}
if ( V_405 )
F_189 ( & V_3 -> V_410 ) ;
}
return V_411 ;
}
static T_1 F_190 ( struct V_412
* V_174 )
{
struct V_3 * V_3 = F_191 ( V_174 ) ;
return F_31 ( V_3 ) ;
}
static int F_192 ( struct V_412 * V_174 )
{
struct V_413 * V_414 = V_174 -> V_414 ;
struct V_3 * V_3 = F_191 ( V_174 ) ;
struct V_412 * V_415 ;
if ( V_174 -> V_416 == V_417 )
V_415 = V_3 -> V_408 ;
else
V_415 = V_3 -> V_409 ;
if ( V_3 -> V_418 )
V_414 -> V_32 -> V_419 = F_31 ( V_3 ) ;
else
V_414 -> V_32 -> V_419 = 0 ;
if ( V_415 ) {
struct V_412 * V_89 ;
struct V_413 * V_420 = V_415 -> V_414 ;
F_193 (s, substream) {
if ( V_89 == V_415 ) {
V_420 -> V_32 -> V_419 =
V_414 -> V_32 -> V_419 ;
break;
}
}
}
return 0 ;
}
static int F_194 ( struct V_412 * V_174 ,
struct V_421 * V_422 )
{
struct V_3 * V_3 = F_191 ( V_174 ) ;
int V_184 ;
int V_19 ;
T_4 V_423 ;
T_4 V_424 ;
F_36 ( & V_3 -> V_25 ) ;
if ( V_174 -> V_425 -> V_416 == V_417 ) {
V_423 = V_3 -> V_26 ;
V_424 = V_3 -> V_27 ;
} else {
V_423 = V_3 -> V_27 ;
V_424 = V_3 -> V_26 ;
}
if ( V_424 > 0 && V_423 != V_424 ) {
if ( F_195 ( V_422 ) != V_3 -> V_112 ) {
F_38 ( & V_3 -> V_25 ) ;
F_196 ( V_422 ,
V_426 ) ;
return - V_127 ;
}
if ( F_197 ( V_422 ) != V_3 -> V_85 / 4 ) {
F_38 ( & V_3 -> V_25 ) ;
F_196 ( V_422 ,
V_427 ) ;
return - V_127 ;
}
}
F_38 ( & V_3 -> V_25 ) ;
F_36 ( & V_3 -> V_25 ) ;
V_184 = F_44 ( V_3 , F_195 ( V_422 ) , 0 ) ;
if ( V_184 < 0 ) {
F_198 ( V_3 -> V_108 -> V_109 , L_156 , V_184 ) ;
F_38 ( & V_3 -> V_25 ) ;
F_196 ( V_422 ,
V_426 ) ;
return V_184 ;
}
F_38 ( & V_3 -> V_25 ) ;
V_184 = F_35 ( V_3 ,
F_197 ( V_422 ) ) ;
if ( V_184 < 0 ) {
F_198 ( V_3 -> V_108 -> V_109 ,
L_157 , V_184 ) ;
F_196 ( V_422 ,
V_427 ) ;
return V_184 ;
}
V_184 =
F_199 ( V_174 , V_428 ) ;
if ( V_184 < 0 ) {
F_198 ( V_3 -> V_108 -> V_109 ,
L_158 , V_184 ) ;
return V_184 ;
}
if ( V_174 -> V_416 == V_417 ) {
F_200 ( V_3 , V_174 , V_429 ,
F_201 ( V_422 ) ) ;
for ( V_19 = 0 ; V_19 < F_201 ( V_422 ) ; ++ V_19 )
F_12 ( V_3 , V_19 , 1 ) ;
V_3 -> V_94 =
( unsigned char * ) V_174 -> V_414 -> V_430 ;
F_202 ( V_3 -> V_108 -> V_109 ,
L_159 ,
V_3 -> V_94 ) ;
} else {
F_200 ( V_3 , V_174 , V_431 ,
F_201 ( V_422 ) ) ;
for ( V_19 = 0 ; V_19 < F_201 ( V_422 ) ; ++ V_19 )
F_11 ( V_3 , V_19 , 1 ) ;
V_3 -> V_432 =
( unsigned char * ) V_174 -> V_414 -> V_430 ;
F_202 ( V_3 -> V_108 -> V_109 ,
L_160 ,
V_3 -> V_432 ) ;
}
if ( V_3 -> V_5 == V_37 ) {
return 0 ;
}
if ( V_433 == F_203 ( V_422 ) ) {
if ( ! ( V_3 -> V_29 & V_434 ) )
F_198 ( V_3 -> V_108 -> V_109 ,
L_161 ) ;
V_3 -> V_29 |= V_434 ;
} else if ( V_435 == F_203 ( V_422 ) ) {
if ( V_3 -> V_29 & V_434 )
F_198 ( V_3 -> V_108 -> V_109 ,
L_162 ) ;
V_3 -> V_29 &= ~ V_434 ;
}
F_3 ( V_3 , V_92 , V_3 -> V_29 ) ;
return 0 ;
}
static int F_204 ( struct V_412 * V_174 )
{
int V_19 ;
struct V_3 * V_3 = F_191 ( V_174 ) ;
if ( V_174 -> V_416 == V_417 ) {
for ( V_19 = 0 ; V_19 < V_3 -> V_136 ; ++ V_19 )
F_12 ( V_3 , V_19 , 0 ) ;
V_3 -> V_94 = NULL ;
} else {
for ( V_19 = 0 ; V_19 < V_3 -> V_134 ; ++ V_19 )
F_11 ( V_3 , V_19 , 0 ) ;
V_3 -> V_432 = NULL ;
}
F_205 ( V_174 ) ;
return 0 ;
}
static int F_206 ( struct V_412 * V_174 ,
struct V_436 * V_437 )
{
struct V_3 * V_3 = F_191 ( V_174 ) ;
if ( V_174 -> V_416 == V_417 ) {
if ( F_43 ( V_437 -> V_297 >= V_3 -> V_136 ) ) {
F_198 ( V_3 -> V_108 -> V_109 ,
L_163 ,
V_437 -> V_297 ) ;
return - V_125 ;
}
if ( V_3 -> V_132 [ V_437 -> V_297 ] < 0 ) {
F_198 ( V_3 -> V_108 -> V_109 ,
L_164 ,
V_437 -> V_297 ) ;
return - V_125 ;
}
V_437 -> V_438 = V_3 -> V_132 [ V_437 -> V_297 ] *
V_96 ;
} else {
if ( F_43 ( V_437 -> V_297 >= V_3 -> V_134 ) ) {
F_198 ( V_3 -> V_108 -> V_109 ,
L_165 ,
V_437 -> V_297 ) ;
return - V_125 ;
}
if ( V_3 -> V_130 [ V_437 -> V_297 ] < 0 ) {
F_198 ( V_3 -> V_108 -> V_109 ,
L_166 ,
V_437 -> V_297 ) ;
return - V_125 ;
}
V_437 -> V_438 = V_3 -> V_130 [ V_437 -> V_297 ] *
V_96 ;
}
V_437 -> V_439 = 0 ;
V_437 -> V_231 = 32 ;
return 0 ;
}
static int F_207 ( struct V_412 * V_174 ,
unsigned int V_440 , void * V_219 )
{
switch ( V_440 ) {
case V_441 :
return F_192 ( V_174 ) ;
case V_442 :
{
struct V_436 * V_437 = V_219 ;
return F_206 ( V_174 , V_437 ) ;
}
default:
break;
}
return F_208 ( V_174 , V_440 , V_219 ) ;
}
static int F_209 ( struct V_412 * V_174 , int V_440 )
{
struct V_3 * V_3 = F_191 ( V_174 ) ;
struct V_412 * V_415 ;
int V_418 ;
F_210 ( & V_3 -> V_25 ) ;
V_418 = V_3 -> V_418 ;
switch ( V_440 ) {
case V_443 :
V_418 |= 1 << V_174 -> V_416 ;
break;
case V_444 :
V_418 &= ~ ( 1 << V_174 -> V_416 ) ;
break;
default:
F_40 () ;
F_211 ( & V_3 -> V_25 ) ;
return - V_125 ;
}
if ( V_174 -> V_416 == V_417 )
V_415 = V_3 -> V_408 ;
else
V_415 = V_3 -> V_409 ;
if ( V_415 ) {
struct V_412 * V_89 ;
F_193 (s, substream) {
if ( V_89 == V_415 ) {
F_212 ( V_89 , V_174 ) ;
if ( V_440 == V_443 )
V_418 |= 1 << V_89 -> V_416 ;
else
V_418 &= ~ ( 1 << V_89 -> V_416 ) ;
goto V_445;
}
}
if ( V_440 == V_443 ) {
if ( ! ( V_418 & ( 1 << V_417 ) )
&& V_174 -> V_416 ==
V_446 )
F_34 ( V_3 ) ;
} else {
if ( V_418 &&
V_174 -> V_416 == V_417 )
F_34 ( V_3 ) ;
}
} else {
if ( V_174 -> V_416 == V_446 )
F_34 ( V_3 ) ;
}
V_445:
F_212 ( V_174 , V_174 ) ;
if ( ! V_3 -> V_418 && V_418 )
F_32 ( V_3 ) ;
else if ( V_3 -> V_418 && ! V_418 )
F_33 ( V_3 ) ;
V_3 -> V_418 = V_418 ;
F_211 ( & V_3 -> V_25 ) ;
return 0 ;
}
static int F_213 ( struct V_412 * V_174 )
{
return 0 ;
}
static int F_214 ( struct V_421 * V_422 ,
struct V_447 * V_448 )
{
struct V_3 * V_3 = V_448 -> V_449 ;
struct V_450 * V_451 =
F_215 ( V_422 , V_452 ) ;
struct V_450 * V_453 =
F_215 ( V_422 , V_426 ) ;
if ( V_453 -> V_229 > 96000 && V_453 -> V_230 <= 192000 ) {
struct V_450 V_454 = {
. V_229 = V_3 -> V_150 ,
. V_230 = V_3 -> V_150 ,
. integer = 1 ,
} ;
return F_216 ( V_451 , & V_454 ) ;
} else if ( V_453 -> V_229 > 48000 && V_453 -> V_230 <= 96000 ) {
struct V_450 V_454 = {
. V_229 = V_3 -> V_144 ,
. V_230 = V_3 -> V_144 ,
. integer = 1 ,
} ;
return F_216 ( V_451 , & V_454 ) ;
} else if ( V_453 -> V_230 < 64000 ) {
struct V_450 V_454 = {
. V_229 = V_3 -> V_135 ,
. V_230 = V_3 -> V_135 ,
. integer = 1 ,
} ;
return F_216 ( V_451 , & V_454 ) ;
}
return 0 ;
}
static int F_217 ( struct V_421 * V_422 ,
struct V_447 * V_448 )
{
struct V_3 * V_3 = V_448 -> V_449 ;
struct V_450 * V_451 =
F_215 ( V_422 , V_452 ) ;
struct V_450 * V_453 =
F_215 ( V_422 , V_426 ) ;
if ( V_453 -> V_229 > 96000 && V_453 -> V_230 <= 192000 ) {
struct V_450 V_454 = {
. V_229 = V_3 -> V_151 ,
. V_230 = V_3 -> V_151 ,
. integer = 1 ,
} ;
return F_216 ( V_451 , & V_454 ) ;
} else if ( V_453 -> V_229 > 48000 && V_453 -> V_230 <= 96000 ) {
struct V_450 V_454 = {
. V_229 = V_3 -> V_145 ,
. V_230 = V_3 -> V_145 ,
. integer = 1 ,
} ;
return F_216 ( V_451 , & V_454 ) ;
} else if ( V_453 -> V_230 < 64000 ) {
struct V_450 V_454 = {
. V_229 = V_3 -> V_137 ,
. V_230 = V_3 -> V_137 ,
. integer = 1 ,
} ;
return F_216 ( V_451 , & V_454 ) ;
} else {
}
return 0 ;
}
static int F_218 ( struct V_421 * V_422 ,
struct V_447 * V_448 )
{
struct V_3 * V_3 = V_448 -> V_449 ;
struct V_450 * V_451 =
F_215 ( V_422 , V_452 ) ;
struct V_450 * V_453 =
F_215 ( V_422 , V_426 ) ;
if ( V_451 -> V_229 >= V_3 -> V_135 ) {
struct V_450 V_454 = {
. V_229 = 32000 ,
. V_230 = 48000 ,
. integer = 1 ,
} ;
return F_216 ( V_453 , & V_454 ) ;
} else if ( V_451 -> V_230 <= V_3 -> V_150 ) {
struct V_450 V_454 = {
. V_229 = 128000 ,
. V_230 = 192000 ,
. integer = 1 ,
} ;
return F_216 ( V_453 , & V_454 ) ;
} else if ( V_451 -> V_230 <= V_3 -> V_144 ) {
struct V_450 V_454 = {
. V_229 = 64000 ,
. V_230 = 96000 ,
. integer = 1 ,
} ;
return F_216 ( V_453 , & V_454 ) ;
}
return 0 ;
}
static int F_219 ( struct V_421 * V_422 ,
struct V_447 * V_448 )
{
struct V_3 * V_3 = V_448 -> V_449 ;
struct V_450 * V_451 =
F_215 ( V_422 , V_452 ) ;
struct V_450 * V_453 =
F_215 ( V_422 , V_426 ) ;
if ( V_451 -> V_229 >= V_3 -> V_137 ) {
struct V_450 V_454 = {
. V_229 = 32000 ,
. V_230 = 48000 ,
. integer = 1 ,
} ;
return F_216 ( V_453 , & V_454 ) ;
} else if ( V_451 -> V_230 <= V_3 -> V_151 ) {
struct V_450 V_454 = {
. V_229 = 128000 ,
. V_230 = 192000 ,
. integer = 1 ,
} ;
return F_216 ( V_453 , & V_454 ) ;
} else if ( V_451 -> V_230 <= V_3 -> V_145 ) {
struct V_450 V_454 = {
. V_229 = 64000 ,
. V_230 = 96000 ,
. integer = 1 ,
} ;
return F_216 ( V_453 , & V_454 ) ;
}
return 0 ;
}
static int F_220 ( struct V_421 * V_422 ,
struct V_447 * V_448 )
{
unsigned int V_342 [ 3 ] ;
struct V_3 * V_3 = V_448 -> V_449 ;
struct V_450 * V_451 = F_215 ( V_422 ,
V_452 ) ;
V_342 [ 0 ] = V_3 -> V_150 ;
V_342 [ 1 ] = V_3 -> V_144 ;
V_342 [ 2 ] = V_3 -> V_135 ;
return F_221 ( V_451 , 3 , V_342 , 0 ) ;
}
static int F_222 ( struct V_421 * V_422 ,
struct V_447 * V_448 )
{
unsigned int V_342 [ 3 ] ;
struct V_3 * V_3 = V_448 -> V_449 ;
struct V_450 * V_451 = F_215 ( V_422 ,
V_452 ) ;
V_342 [ 0 ] = V_3 -> V_151 ;
V_342 [ 1 ] = V_3 -> V_145 ;
V_342 [ 2 ] = V_3 -> V_137 ;
return F_221 ( V_451 , 3 , V_342 , 0 ) ;
}
static int F_223 ( struct V_412 * V_174 )
{
struct V_3 * V_3 = F_191 ( V_174 ) ;
struct V_413 * V_414 = V_174 -> V_414 ;
F_36 ( & V_3 -> V_25 ) ;
F_224 ( V_174 ) ;
V_414 -> V_455 = V_456 ;
if ( V_3 -> V_408 == NULL )
F_33 ( V_3 ) ;
V_3 -> V_26 = V_457 -> V_458 ;
V_3 -> V_409 = V_174 ;
F_38 ( & V_3 -> V_25 ) ;
F_225 ( V_414 , 0 , 32 , 24 ) ;
F_226 ( V_414 , 0 , V_427 ) ;
switch ( V_3 -> V_5 ) {
case V_4 :
case V_6 :
F_227 ( V_414 ,
V_427 ,
32 , 4096 ) ;
F_227 ( V_414 ,
V_459 ,
16384 , 16384 ) ;
break;
default:
F_227 ( V_414 ,
V_427 ,
64 , 8192 ) ;
break;
}
if ( V_37 == V_3 -> V_5 ) {
V_414 -> V_455 . V_460 |= V_461 ;
F_228 ( V_414 , 0 , V_426 ,
& V_462 ) ;
} else {
F_229 ( V_414 , 0 , V_426 ,
F_219 , V_3 ,
V_452 , - 1 ) ;
}
F_229 ( V_414 , 0 , V_452 ,
F_222 , V_3 ,
V_452 , - 1 ) ;
F_229 ( V_414 , 0 , V_452 ,
F_217 , V_3 ,
V_426 , - 1 ) ;
return 0 ;
}
static int F_230 ( struct V_412 * V_174 )
{
struct V_3 * V_3 = F_191 ( V_174 ) ;
F_36 ( & V_3 -> V_25 ) ;
V_3 -> V_26 = - 1 ;
V_3 -> V_409 = NULL ;
F_38 ( & V_3 -> V_25 ) ;
return 0 ;
}
static int F_231 ( struct V_412 * V_174 )
{
struct V_3 * V_3 = F_191 ( V_174 ) ;
struct V_413 * V_414 = V_174 -> V_414 ;
F_36 ( & V_3 -> V_25 ) ;
F_224 ( V_174 ) ;
V_414 -> V_455 = V_463 ;
if ( V_3 -> V_409 == NULL )
F_33 ( V_3 ) ;
V_3 -> V_27 = V_457 -> V_458 ;
V_3 -> V_408 = V_174 ;
F_38 ( & V_3 -> V_25 ) ;
F_225 ( V_414 , 0 , 32 , 24 ) ;
F_226 ( V_414 , 0 , V_427 ) ;
switch ( V_3 -> V_5 ) {
case V_4 :
case V_6 :
F_227 ( V_414 ,
V_427 ,
32 , 4096 ) ;
F_227 ( V_414 ,
V_459 ,
16384 , 16384 ) ;
break;
default:
F_227 ( V_414 ,
V_427 ,
64 , 8192 ) ;
break;
}
if ( V_37 == V_3 -> V_5 ) {
V_414 -> V_455 . V_460 |= V_461 ;
F_228 ( V_414 , 0 , V_426 ,
& V_462 ) ;
} else {
F_229 ( V_414 , 0 , V_426 ,
F_218 , V_3 ,
V_452 , - 1 ) ;
}
F_229 ( V_414 , 0 , V_452 ,
F_220 , V_3 ,
V_452 , - 1 ) ;
F_229 ( V_414 , 0 , V_452 ,
F_214 , V_3 ,
V_426 , - 1 ) ;
return 0 ;
}
static int F_232 ( struct V_412 * V_174 )
{
struct V_3 * V_3 = F_191 ( V_174 ) ;
F_36 ( & V_3 -> V_25 ) ;
V_3 -> V_27 = - 1 ;
V_3 -> V_408 = NULL ;
F_38 ( & V_3 -> V_25 ) ;
return 0 ;
}
static int F_233 ( struct V_464 * V_455 , struct V_465 * V_465 )
{
return 0 ;
}
static inline int F_234 ( void T_5 * V_466 , void T_6 * V_467 )
{
V_18 V_8 = F_6 ( V_467 ) ;
return F_235 ( V_466 , & V_8 , 4 ) ;
}
static int F_236 ( struct V_464 * V_455 , struct V_465 * V_465 ,
unsigned int V_440 , unsigned long V_219 )
{
void T_5 * V_468 = ( void T_5 * ) V_219 ;
struct V_3 * V_3 = V_455 -> V_177 ;
struct V_469 V_13 ;
struct V_470 V_437 ;
struct V_471 V_32 ;
struct V_472 V_472 ;
struct V_473 * V_474 ;
struct V_475 V_356 ;
unsigned int V_476 ;
long unsigned int V_89 ;
int V_19 = 0 ;
switch ( V_440 ) {
case V_477 :
V_474 = & V_3 -> V_478 ;
for ( V_19 = 0 ; V_19 < V_95 ; V_19 ++ ) {
V_474 -> V_479 [ V_19 ] =
F_6 ( V_3 -> V_9 +
V_480 + V_19 * 4 ) ;
V_474 -> V_481 [ V_19 ] =
F_6 ( V_3 -> V_9 +
V_482 + V_19 * 4 ) ;
V_474 -> V_483 [ V_19 ] =
F_6 ( V_3 -> V_9 +
V_484 + V_19 * 4 ) ;
V_474 -> V_485 [ V_19 ] =
( ( V_486 ) F_6 ( V_3 -> V_9 +
V_487 + V_19 * 4 ) << 32 ) |
( V_486 ) F_6 ( V_3 -> V_9 +
V_488 + V_19 * 4 ) ;
V_474 -> V_489 [ V_19 ] =
( ( V_486 ) F_6 ( V_3 -> V_9 +
V_490 + V_19 * 4 ) << 32 ) |
( V_486 ) F_6 ( V_3 -> V_9 +
V_491 + V_19 * 4 ) ;
V_474 -> V_492 [ V_19 ] =
( ( V_486 ) F_6 ( V_3 -> V_9 +
V_493 + V_19 * 4 ) << 32 ) |
( V_486 ) F_6 ( V_3 -> V_9 +
V_494 + V_19 * 4 ) ;
}
if ( V_3 -> V_112 > 96000 ) {
V_474 -> V_495 = V_496 ;
} else if ( V_3 -> V_112 > 48000 ) {
V_474 -> V_495 = V_289 ;
} else {
V_474 -> V_495 = V_497 ;
}
V_474 -> V_33 = F_5 ( V_3 , V_38 ) ;
V_89 = F_235 ( V_468 , V_474 , sizeof( struct V_473 ) ) ;
if ( 0 != V_89 ) {
return - V_498 ;
}
break;
case V_499 :
V_356 . V_356 = F_5 ( V_3 , V_274 ) ;
V_19 = F_5 ( V_3 , V_274 + 4 ) ;
if ( V_19 & V_277 ) {
switch ( V_19 & ( V_278 |
V_279 ) ) {
case 0 :
V_356 . V_500 = V_280 ;
break;
case V_278 :
V_356 . V_500 = V_281 ;
break;
case V_279 :
V_356 . V_500 = V_282 ;
break;
default:
V_356 . V_500 = V_283 ;
break;
}
if ( V_19 & V_315 ) {
V_356 . V_501 = V_502 ;
} else {
V_356 . V_501 = V_503 ;
}
} else {
V_356 . V_500 = V_504 ;
V_356 . V_501 = V_505 ;
}
if ( V_19 & V_275 ) {
V_356 . V_506 = V_507 ;
} else if ( V_19 & V_276 ) {
V_356 . V_506 = V_508 ;
} else {
V_356 . V_506 = V_509 ;
}
V_89 = F_235 ( V_468 , & V_356 , sizeof( struct V_475 ) ) ;
if ( 0 != V_89 ) {
return - V_498 ;
}
break;
case V_510 :
memset ( & V_437 , 0 , sizeof( V_437 ) ) ;
F_36 ( & V_3 -> V_25 ) ;
V_437 . V_362 = F_95 ( V_3 ) ;
V_437 . V_511 = F_20 ( V_3 ) ;
V_437 . V_112 = V_3 -> V_112 ;
V_437 . V_512 =
F_18 ( V_3 ) ;
V_437 . V_364 = F_74 ( V_3 ) ;
V_437 . V_513 = F_90 ( V_3 ) ;
V_437 . V_363 = F_19 ( V_3 ) ;
V_437 . V_514 = F_108 ( V_3 , V_379 ) ;
V_437 . V_515 = 0 ;
F_38 ( & V_3 -> V_25 ) ;
if ( F_235 ( V_468 , & V_437 , sizeof( V_437 ) ) )
return - V_498 ;
break;
case V_516 :
memset ( & V_32 , 0 , sizeof( V_32 ) ) ;
V_32 . V_517 = V_3 -> V_5 ;
V_32 . V_518 = F_19 ( V_3 ) ;
V_32 . V_519 = 110069313433624ULL ;
V_32 . V_520 = F_5 ( V_3 , V_221 ) ;
switch ( V_3 -> V_5 ) {
case V_55 :
case V_51 :
V_32 . V_521 . V_522 . V_523 =
F_20 ( V_3 ) ;
V_32 . V_521 . V_522 . V_524 =
F_144 ( V_3 ) ;
V_32 . V_521 . V_522 . V_525 =
F_24 ( V_3 ) ;
V_32 . V_521 . V_522 . V_526 =
F_26 ( V_3 ) ;
V_476 =
F_5 ( V_3 , V_39 ) ;
V_32 . V_521 . V_522 . V_527 =
( V_476 & V_390 ) ? 1 : 0 ;
V_32 . V_521 . V_522 . V_528 =
( V_476 & V_391 ) ? 1 : 0 ;
V_32 . V_521 . V_522 . V_529 = 0 ;
default:
break;
}
if ( F_235 ( V_468 , & V_32 , sizeof( V_32 ) ) )
return - V_498 ;
break;
case V_530 :
memset ( & V_472 , 0 , sizeof( V_472 ) ) ;
V_472 . V_517 = V_3 -> V_5 ;
F_237 ( V_472 . V_531 , V_3 -> V_368 ,
sizeof( V_472 . V_531 ) ) ;
V_472 . V_374 = V_3 -> V_374 ;
V_472 . V_370 = V_3 -> V_370 ;
V_472 . V_532 = 0 ;
if ( V_3 -> V_238 )
V_472 . V_532 |= V_533 ;
if ( F_235 ( V_468 , & V_472 ,
sizeof( V_472 ) ) )
return - V_498 ;
break;
case V_534 :
if ( F_238 ( & V_13 , V_468 , sizeof( V_13 ) ) )
return - V_498 ;
if ( F_235 ( ( void T_5 * ) V_13 . V_13 , V_3 -> V_13 ,
sizeof( struct V_535 ) ) )
return - V_498 ;
break;
default:
return - V_125 ;
}
return 0 ;
}
static int F_239 ( struct V_183 * V_108 ,
struct V_3 * V_3 )
{
struct V_464 * V_455 ;
int V_184 ;
V_184 = F_240 ( V_108 , L_167 , 0 , & V_455 ) ;
if ( V_184 < 0 )
return V_184 ;
V_3 -> V_536 = V_455 ;
V_455 -> V_177 = V_3 ;
strcpy ( V_455 -> V_210 , L_168 ) ;
V_455 -> V_537 . V_538 = F_233 ;
V_455 -> V_537 . V_539 = F_236 ;
V_455 -> V_537 . V_540 = F_236 ;
V_455 -> V_537 . V_541 = F_233 ;
return 0 ;
}
static int F_241 ( struct V_3 * V_3 )
{
int V_184 ;
struct V_542 * V_543 ;
T_7 V_544 ;
V_543 = V_3 -> V_543 ;
V_544 = V_428 ;
V_184 =
F_242 ( V_543 ,
V_545 ,
F_243 ( V_3 -> V_546 ) ,
V_544 ,
V_544 ) ;
if ( V_184 < 0 ) {
F_202 ( V_3 -> V_108 -> V_109 ,
L_169 , V_544 ) ;
return V_184 ;
} else
F_202 ( V_3 -> V_108 -> V_109 ,
L_170 , V_544 ) ;
return 0 ;
}
static void F_200 ( struct V_3 * V_3 ,
struct V_412 * V_174 ,
unsigned int V_7 , int V_547 )
{
int V_19 ;
for ( V_19 = 0 ; V_19 < ( V_547 * 16 ) ; V_19 ++ )
F_3 ( V_3 , V_7 + 4 * V_19 ,
F_244 ( V_174 , 4096 * V_19 ) ) ;
}
static int F_245 ( struct V_183 * V_108 ,
struct V_3 * V_3 )
{
struct V_542 * V_543 ;
int V_184 ;
V_184 = F_246 ( V_108 , V_3 -> V_368 , 0 , 1 , 1 , & V_543 ) ;
if ( V_184 < 0 )
return V_184 ;
V_3 -> V_543 = V_543 ;
V_543 -> V_177 = V_3 ;
strcpy ( V_543 -> V_210 , V_3 -> V_368 ) ;
F_247 ( V_543 , V_417 ,
& V_548 ) ;
F_247 ( V_543 , V_446 ,
& V_549 ) ;
V_543 -> V_215 = V_550 ;
V_184 = F_241 ( V_3 ) ;
if ( V_184 < 0 )
return V_184 ;
return 0 ;
}
static inline void F_248 ( struct V_3 * V_3 )
{
int V_19 ;
for ( V_19 = 0 ; V_19 < V_3 -> V_220 ; V_19 ++ )
F_52 ( V_3 , V_19 ) ;
}
static int F_249 ( struct V_183 * V_108 ,
struct V_3 * V_3 )
{
int V_184 , V_19 ;
F_202 ( V_108 -> V_109 , L_171 ) ;
V_184 = F_245 ( V_108 , V_3 ) ;
if ( V_184 < 0 )
return V_184 ;
V_19 = 0 ;
while ( V_19 < V_3 -> V_220 ) {
V_184 = F_68 ( V_108 , V_3 , V_19 ) ;
if ( V_184 < 0 ) {
return V_184 ;
}
V_19 ++ ;
}
V_184 = F_169 ( V_108 , V_3 ) ;
if ( V_184 < 0 )
return V_184 ;
V_184 = F_239 ( V_108 , V_3 ) ;
if ( V_184 < 0 )
return V_184 ;
F_202 ( V_108 -> V_109 , L_172 ) ;
F_181 ( V_3 ) ;
V_3 -> V_112 = - 1 ;
V_3 -> V_551 = - 1 ;
V_3 -> V_552 = - 1 ;
V_3 -> V_26 = - 1 ;
V_3 -> V_27 = - 1 ;
V_3 -> V_408 = NULL ;
V_3 -> V_409 = NULL ;
F_202 ( V_108 -> V_109 , L_173 ) ;
V_184 = F_185 ( V_3 ) ;
if ( V_184 < 0 )
return V_184 ;
F_202 ( V_108 -> V_109 , L_174 ) ;
F_167 ( V_3 ) ;
F_202 ( V_108 -> V_109 , L_175 ) ;
V_184 = F_250 ( V_108 ) ;
if ( V_184 < 0 ) {
F_46 ( V_108 -> V_109 , L_176 ) ;
return V_184 ;
}
F_202 ( V_108 -> V_109 , L_177 ) ;
return 0 ;
}
static int F_251 ( struct V_183 * V_108 ,
struct V_3 * V_3 )
{
struct V_553 * V_546 = V_3 -> V_546 ;
int V_184 ;
unsigned long V_554 ;
V_3 -> V_190 = - 1 ;
V_3 -> V_108 = V_108 ;
F_69 ( & V_3 -> V_25 ) ;
F_252 ( V_3 -> V_546 ,
V_555 , & V_3 -> V_370 ) ;
strcpy ( V_108 -> V_556 , L_178 ) ;
strcpy ( V_108 -> V_557 , L_179 ) ;
switch ( V_3 -> V_370 ) {
case V_558 :
V_3 -> V_5 = V_6 ;
V_3 -> V_368 = L_180 ;
V_3 -> V_220 = 2 ;
break;
case V_559 :
V_3 -> V_5 = V_4 ;
V_3 -> V_368 = L_181 ;
V_3 -> V_220 = 1 ;
break;
case V_560 :
V_3 -> V_5 = V_51 ;
V_3 -> V_368 = L_182 ;
V_3 -> V_220 = 1 ;
break;
default:
if ( ( V_3 -> V_370 == 0xf0 ) ||
( ( V_3 -> V_370 >= 0xe6 ) &&
( V_3 -> V_370 <= 0xea ) ) ) {
V_3 -> V_5 = V_37 ;
V_3 -> V_368 = L_183 ;
V_3 -> V_220 = 2 ;
} else if ( ( V_3 -> V_370 == 0xd2 ) ||
( ( V_3 -> V_370 >= 0xc8 ) &&
( V_3 -> V_370 <= 0xcf ) ) ) {
V_3 -> V_5 = V_55 ;
V_3 -> V_368 = L_184 ;
V_3 -> V_220 = 3 ;
} else {
F_46 ( V_108 -> V_109 ,
L_185 ,
V_3 -> V_370 ) ;
return - V_561 ;
}
}
V_184 = F_253 ( V_546 ) ;
if ( V_184 < 0 )
return V_184 ;
F_254 ( V_3 -> V_546 ) ;
V_184 = F_255 ( V_546 , L_152 ) ;
if ( V_184 < 0 )
return V_184 ;
V_3 -> V_375 = F_256 ( V_546 , 0 ) ;
V_554 = F_257 ( V_546 , 0 ) ;
F_202 ( V_108 -> V_109 , L_186 ,
V_3 -> V_375 , V_3 -> V_375 + V_554 - 1 ) ;
V_3 -> V_9 = F_258 ( V_3 -> V_375 , V_554 ) ;
if ( ! V_3 -> V_9 ) {
F_46 ( V_108 -> V_109 , L_187 ,
V_3 -> V_375 , V_3 -> V_375 + V_554 - 1 ) ;
return - V_127 ;
}
F_202 ( V_108 -> V_109 , L_188 ,
( unsigned long ) V_3 -> V_9 , V_3 -> V_375 ,
V_3 -> V_375 + V_554 - 1 ) ;
if ( F_259 ( V_546 -> V_190 , F_187 ,
V_562 , V_563 , V_3 ) ) {
F_46 ( V_108 -> V_109 , L_189 , V_546 -> V_190 ) ;
return - V_127 ;
}
F_202 ( V_108 -> V_109 , L_190 , V_546 -> V_190 ) ;
V_3 -> V_190 = V_546 -> V_190 ;
F_202 ( V_108 -> V_109 , L_191 ,
sizeof( struct V_535 ) ) ;
V_3 -> V_13 = F_260 ( sizeof( struct V_535 ) , V_564 ) ;
if ( ! V_3 -> V_13 ) {
F_46 ( V_108 -> V_109 ,
L_192 ,
( int ) sizeof( struct V_535 ) ) ;
return - V_565 ;
}
V_3 -> V_138 = NULL ;
V_3 -> V_140 = NULL ;
switch ( V_3 -> V_5 ) {
case V_37 :
V_3 -> V_135 = V_3 -> V_137 = V_566 ;
V_3 -> V_144 = V_3 -> V_145 = V_566 ;
V_3 -> V_150 = V_3 -> V_151 = V_566 ;
V_3 -> V_131 = V_3 -> V_133 =
V_567 ;
V_3 -> V_142 = V_3 -> V_143 =
V_567 ;
V_3 -> V_148 = V_3 -> V_149 =
V_567 ;
V_3 -> V_139 = V_3 -> V_141 =
V_568 ;
V_3 -> V_146 = V_3 -> V_147 =
V_568 ;
V_3 -> V_152 = V_3 -> V_153 =
V_568 ;
V_3 -> V_136 = V_3 -> V_134 =
V_566 ;
V_3 -> V_138 = V_3 -> V_140 =
V_568 ;
V_3 -> V_130 = V_3 -> V_132 =
V_567 ;
break;
case V_55 :
case V_51 :
V_3 -> V_135 = V_3 -> V_137 =
V_569 ;
V_3 -> V_144 = V_3 -> V_145 =
V_570 ;
V_3 -> V_150 = V_3 -> V_151 =
V_571 ;
V_3 -> V_131 = V_3 -> V_133 =
V_572 ;
V_3 -> V_142 = V_3 -> V_143 =
V_572 ;
V_3 -> V_148 = V_3 -> V_149 =
V_572 ;
V_3 -> V_139 = V_3 -> V_141 =
V_573 ;
V_3 -> V_146 = V_3 -> V_147 =
V_573 ;
V_3 -> V_152 = V_3 -> V_153 =
V_573 ;
break;
case V_4 :
V_3 -> V_135 = V_574 ;
V_3 -> V_144 = V_575 ;
V_3 -> V_150 = V_576 ;
V_3 -> V_137 = V_577 ;
V_3 -> V_145 = V_578 ;
V_3 -> V_151 = V_579 ;
if ( 0 == ( F_5 ( V_3 , V_38 ) & V_580 ) ) {
F_198 ( V_108 -> V_109 , L_193 ) ;
V_3 -> V_135 += 4 ;
V_3 -> V_144 += 4 ;
V_3 -> V_150 += 4 ;
}
if ( 0 == ( F_5 ( V_3 , V_38 ) & V_581 ) ) {
F_198 ( V_108 -> V_109 , L_194 ) ;
V_3 -> V_137 += 4 ;
V_3 -> V_145 += 4 ;
V_3 -> V_151 += 4 ;
}
V_3 -> V_133 = V_582 ;
V_3 -> V_143 = V_583 ;
V_3 -> V_149 = V_584 ;
V_3 -> V_131 = V_585 ;
V_3 -> V_142 = V_586 ;
V_3 -> V_148 = V_587 ;
V_3 -> V_139 = V_588 ;
V_3 -> V_141 = V_589 ;
V_3 -> V_146 = V_590 ;
V_3 -> V_147 = V_591 ;
V_3 -> V_152 = V_592 ;
V_3 -> V_153 = V_593 ;
break;
case V_6 :
V_3 -> V_135 = V_3 -> V_137 =
V_594 ;
V_3 -> V_144 = V_3 -> V_145 =
V_595 ;
V_3 -> V_150 = V_3 -> V_151 =
V_596 ;
V_3 -> V_134 = V_594 ;
V_3 -> V_136 = V_594 ;
V_3 -> V_131 = V_3 -> V_133 =
V_597 ;
V_3 -> V_142 = V_3 -> V_143 =
V_598 ;
V_3 -> V_148 = V_3 -> V_149 =
V_599 ;
V_3 -> V_130 = V_3 -> V_132 =
V_597 ;
V_3 -> V_139 = V_3 -> V_141 =
V_600 ;
V_3 -> V_146 = V_3 -> V_147 =
V_601 ;
V_3 -> V_152 = V_3 -> V_153 =
V_602 ;
break;
}
switch ( V_3 -> V_5 ) {
case V_4 :
case V_6 :
if ( F_5 ( V_3 , V_38 ) &
V_603 ) {
V_3 -> V_220 ++ ;
V_3 -> V_238 = F_260 ( sizeof( struct V_604 ) ,
V_564 ) ;
if ( NULL != V_3 -> V_238 ) {
F_148 ( V_3 ) ;
}
F_198 ( V_108 -> V_109 , L_195 ) ;
} else {
V_3 -> V_238 = NULL ;
}
break;
case V_55 :
case V_37 :
if ( F_5 ( V_3 , V_39 ) & V_360 ) {
V_3 -> V_220 ++ ;
V_3 -> V_238 = F_260 ( sizeof( struct V_604 ) ,
V_564 ) ;
if ( NULL != V_3 -> V_238 ) {
F_148 ( V_3 ) ;
}
F_198 ( V_108 -> V_109 , L_196 ) ;
} else {
V_3 -> V_238 = NULL ;
}
break;
default:
V_3 -> V_238 = NULL ;
}
switch ( V_3 -> V_5 ) {
case V_37 :
if ( V_3 -> V_238 ) {
V_3 -> V_263 = V_605 ;
V_3 -> V_262 =
F_170 ( V_605 ) ;
} else {
V_3 -> V_263 = V_606 ;
V_3 -> V_262 =
F_170 ( V_606 ) ;
}
break;
case V_55 :
if ( V_3 -> V_238 ) {
V_3 -> V_263 = V_607 ;
V_3 -> V_262 = 4 ;
} else {
V_3 -> V_263 = V_608 ;
V_3 -> V_262 = 3 ;
}
break;
case V_51 :
break;
case V_6 :
if ( V_3 -> V_238 ) {
V_3 -> V_263 = V_609 ;
V_3 -> V_262 = 9 ;
} else {
V_3 -> V_263 = V_610 ;
V_3 -> V_262 = 8 ;
}
break;
case V_4 :
if ( V_3 -> V_238 ) {
V_3 -> V_263 = V_611 ;
V_3 -> V_262 = 6 ;
} else {
V_3 -> V_263 = V_612 ;
V_3 -> V_262 = 5 ;
}
break;
}
F_261 ( & V_3 -> V_410 ,
F_72 , ( unsigned long ) V_3 ) ;
if ( V_3 -> V_5 != V_51 ) {
V_3 -> V_374 = ( F_5 ( V_3 ,
V_193 ) >> 8 ) & 0xFFFFFF ;
if ( NULL == V_158 [ V_3 -> V_109 ] && V_3 -> V_374 != 0xFFFFFF ) {
sprintf ( V_108 -> V_158 , L_197 , V_3 -> V_374 ) ;
F_262 ( V_108 , V_108 -> V_158 ) ;
}
}
F_202 ( V_108 -> V_109 , L_198 ) ;
V_184 = F_249 ( V_108 , V_3 ) ;
if ( V_184 < 0 )
return V_184 ;
F_248 ( V_3 ) ;
return 0 ;
}
static int F_263 ( struct V_3 * V_3 )
{
if ( V_3 -> V_375 ) {
V_3 -> V_29 &=
~ ( V_91 | V_90 |
V_196 | V_202 |
V_189 | V_207 ) ;
F_3 ( V_3 , V_92 ,
V_3 -> V_29 ) ;
}
if ( V_3 -> V_190 >= 0 )
F_264 ( V_3 -> V_190 , ( void * ) V_3 ) ;
F_265 ( V_3 -> V_13 ) ;
if ( V_3 -> V_9 )
F_266 ( V_3 -> V_9 ) ;
if ( V_3 -> V_375 )
F_267 ( V_3 -> V_546 ) ;
F_268 ( V_3 -> V_546 ) ;
return 0 ;
}
static void F_269 ( struct V_183 * V_108 )
{
struct V_3 * V_3 = V_108 -> V_177 ;
if ( V_3 )
F_263 ( V_3 ) ;
}
static int F_270 ( struct V_553 * V_546 ,
const struct V_613 * V_614 )
{
static int V_109 ;
struct V_3 * V_3 ;
struct V_183 * V_108 ;
int V_184 ;
if ( V_109 >= V_615 )
return - V_561 ;
if ( ! V_616 [ V_109 ] ) {
V_109 ++ ;
return - V_617 ;
}
V_184 = F_271 ( & V_546 -> V_109 , V_240 [ V_109 ] , V_158 [ V_109 ] ,
V_618 , sizeof( struct V_3 ) , & V_108 ) ;
if ( V_184 < 0 )
return V_184 ;
V_3 = V_108 -> V_177 ;
V_108 -> V_619 = F_269 ;
V_3 -> V_109 = V_109 ;
V_3 -> V_546 = V_546 ;
V_184 = F_251 ( V_108 , V_3 ) ;
if ( V_184 < 0 ) {
F_272 ( V_108 ) ;
return V_184 ;
}
if ( V_3 -> V_5 != V_51 ) {
sprintf ( V_108 -> V_209 , L_199 ,
V_3 -> V_368 ,
V_3 -> V_374 ) ;
sprintf ( V_108 -> V_620 , L_200 ,
V_3 -> V_368 ,
V_3 -> V_374 ,
V_3 -> V_375 , V_3 -> V_190 ) ;
} else {
sprintf ( V_108 -> V_209 , L_201 , V_3 -> V_368 ) ;
sprintf ( V_108 -> V_620 , L_202 ,
V_3 -> V_368 , V_3 -> V_375 , V_3 -> V_190 ) ;
}
V_184 = F_250 ( V_108 ) ;
if ( V_184 < 0 ) {
F_272 ( V_108 ) ;
return V_184 ;
}
F_273 ( V_546 , V_108 ) ;
V_109 ++ ;
return 0 ;
}
static void F_274 ( struct V_553 * V_546 )
{
F_272 ( F_275 ( V_546 ) ) ;
}
