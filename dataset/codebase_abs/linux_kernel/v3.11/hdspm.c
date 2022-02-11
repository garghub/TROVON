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
static int F_16 ( struct V_3 * V_3 , int V_25 )
{
if ( V_25 <= 48000 ) {
if ( V_3 -> V_26 & V_27 )
return V_25 * 4 ;
else if ( V_3 -> V_26 &
V_28 )
return V_25 * 2 ;
} ;
return V_25 ;
}
static int F_17 ( struct V_3 * V_3 )
{
unsigned int V_29 , V_30 , V_31 ;
int V_32 , V_25 = 0 , V_33 ;
switch ( V_3 -> V_34 ) {
case V_35 :
V_30 = F_4 ( V_3 , V_36 ) ;
V_29 = F_4 ( V_3 , V_37 ) ;
V_31 = F_4 ( V_3 , V_38 ) ;
V_32 = F_18 ( V_3 ) ;
if ( V_32 == V_39 &&
V_29 & V_40 )
return F_1 ( ( V_29 >> V_41 ) & 0xF ) ;
if ( V_32 >= V_42 &&
V_32 <= V_43 &&
V_30 & ( V_44 >>
( V_32 - V_42 ) ) )
return F_1 ( ( V_31 >> ( 4 * ( V_32 - V_42 ) ) ) & 0xF ) ;
return 0 ;
break;
case V_45 :
V_29 = F_4 ( V_3 , V_37 ) ;
if ( ! ( V_29 & V_46 ) ) {
V_25 = 0 ;
} else {
switch ( V_29 & ( V_47 ) ) {
case V_48 * 1 :
V_25 = 32000 ; break;
case V_48 * 2 :
V_25 = 44100 ; break;
case V_48 * 3 :
V_25 = 48000 ; break;
case V_48 * 4 :
V_25 = 64000 ; break;
case V_48 * 5 :
V_25 = 88200 ; break;
case V_48 * 6 :
V_25 = 96000 ; break;
case V_48 * 7 :
V_25 = 128000 ; break;
case V_48 * 8 :
V_25 = 176400 ; break;
case V_48 * 9 :
V_25 = 192000 ; break;
default:
V_25 = 0 ; break;
}
}
break;
case V_49 :
case V_50 :
case V_51 :
V_30 = F_4 ( V_3 , V_36 ) ;
V_29 = F_4 ( V_3 , V_37 ) ;
V_25 = 0 ;
if ( ( V_30 & V_52 ) != 0 &&
( V_30 & V_53 ) == 0 ) {
V_33 = V_30 & V_54 ;
switch ( V_33 ) {
case V_55 :
V_25 = 32000 ;
break;
case V_56 :
V_25 = 44100 ;
break;
case V_57 :
V_25 = 48000 ;
break;
case V_58 :
V_25 = 64000 ;
break;
case V_59 :
V_25 = 88200 ;
break;
case V_60 :
V_25 = 96000 ;
break;
case V_61 :
V_25 = 128000 ;
break;
case V_62 :
V_25 = 176400 ;
break;
case V_63 :
V_25 = 192000 ;
break;
default:
V_25 = 0 ;
break;
}
}
if ( V_25 != 0 &&
( V_30 & V_64 ) == V_65 )
return F_16 ( V_3 , V_25 ) ;
if ( V_29 & V_46 ) {
V_33 = V_29 & V_66 ;
switch ( V_33 ) {
case V_67 :
V_25 = 32000 ;
break;
case V_68 :
V_25 = 44100 ;
break;
case V_69 :
V_25 = 48000 ;
break;
case V_70 :
V_25 = 64000 ;
break;
case V_71 :
V_25 = 88200 ;
break;
case V_72 :
V_25 = 96000 ;
break;
case V_73 :
V_25 = 128000 ;
break;
case V_74 :
V_25 = 176400 ;
break;
case V_75 :
V_25 = 192000 ;
break;
default:
V_25 = 0 ;
break;
}
}
{
bool V_76 = 0 ;
bool V_77 = 0 ;
V_32 = F_18 ( V_3 ) ;
if ( V_78 == V_32 ) {
V_76 = 1 ;
V_77 = ( V_79 ==
F_19 ( V_3 ) ) ;
} else if ( V_80 == V_32 ) {
V_76 = 1 ;
V_77 = ( V_79 ==
F_20 ( V_3 ) ) ;
}
if ( V_76 && V_77 ) {
V_25 = F_15 (
F_21 ( V_3 ) ) ;
}
}
V_25 = F_16 ( V_3 , V_25 ) ;
break;
}
return V_25 ;
}
static int F_22 ( struct V_3 * V_3 )
{
int V_1 ;
V_1 = F_23 ( V_3 -> V_26 ) ;
if ( ( 7 == V_1 ) && ( V_51 == V_3 -> V_34 || V_50 == V_3 -> V_34 ) )
V_1 = - 1 ;
return 1 << ( V_1 + 6 ) ;
}
static inline void F_24 ( struct V_3 * V_3 )
{
V_3 -> V_81 = 4 * F_22 ( V_3 ) ;
}
static T_1 F_25 ( struct V_3 * V_3 )
{
int V_82 ;
V_82 = F_4 ( V_3 , V_37 ) ;
switch ( V_3 -> V_34 ) {
case V_51 :
case V_50 :
V_82 &= V_83 ;
V_82 /= 4 ;
break;
default:
V_82 = ( V_82 & V_84 ) ?
( V_3 -> V_81 / 4 ) : 0 ;
}
return V_82 ;
}
static inline void F_26 ( struct V_3 * V_85 )
{
V_85 -> V_26 |= ( V_86 | V_87 ) ;
F_2 ( V_85 , V_88 , V_85 -> V_26 ) ;
}
static inline void F_27 ( struct V_3 * V_85 )
{
V_85 -> V_26 &= ~ ( V_87 | V_86 ) ;
F_2 ( V_85 , V_88 , V_85 -> V_26 ) ;
}
static void F_28 ( struct V_3 * V_3 )
{
int V_16 ;
int V_1 = V_3 -> V_81 ;
void * V_89 = V_3 -> V_90 ;
if ( V_89 == NULL )
return;
for ( V_16 = 0 ; V_16 < V_91 ; V_16 ++ ) {
memset ( V_89 , 0 , V_1 ) ;
V_89 += V_92 ;
}
}
static int F_29 ( struct V_3 * V_85 , unsigned int V_93 )
{
int V_1 ;
F_30 ( & V_85 -> V_22 ) ;
if ( 32 == V_93 ) {
V_1 = 7 ;
} else {
V_93 >>= 7 ;
V_1 = 0 ;
while ( V_93 ) {
V_1 ++ ;
V_93 >>= 1 ;
}
}
V_85 -> V_26 &= ~ V_94 ;
V_85 -> V_26 |= F_31 ( V_1 ) ;
F_2 ( V_85 , V_88 , V_85 -> V_26 ) ;
F_24 ( V_85 ) ;
F_32 ( & V_85 -> V_22 ) ;
return 0 ;
}
static T_2 F_33 ( struct V_3 * V_3 , T_2 V_95 )
{
T_2 V_96 ;
if ( V_95 == 0 )
return 0 ;
switch ( V_3 -> V_34 ) {
case V_49 :
case V_35 :
V_96 = 110069313433624ULL ;
break;
case V_51 :
case V_50 :
V_96 = 104857600000000ULL ;
break;
case V_45 :
V_96 = 131072000000000ULL ;
break;
default:
F_34 () ;
return 0 ;
}
return F_35 ( V_96 , V_95 ) ;
}
static void F_36 ( struct V_3 * V_3 , int V_25 )
{
T_2 V_1 ;
if ( V_25 >= 112000 )
V_25 /= 4 ;
else if ( V_25 >= 56000 )
V_25 /= 2 ;
switch ( V_3 -> V_34 ) {
case V_45 :
V_1 = 131072000000000ULL ;
break;
case V_49 :
case V_35 :
V_1 = 110069313433624ULL ;
break;
case V_51 :
case V_50 :
V_1 = 104857600000000ULL ;
break;
default:
F_34 () ;
return;
}
V_1 = F_35 ( V_1 , V_25 ) ;
F_37 ( V_1 >> 32 ) ;
F_2 ( V_3 , V_97 , ( V_15 ) V_1 ) ;
}
static int F_38 ( struct V_3 * V_3 , int V_25 , int V_98 )
{
int V_99 ;
int V_33 ;
int V_100 = 0 ;
int V_101 , V_102 ;
if ( ! ( V_3 -> V_26 & V_103 ) ) {
if ( V_98 ) {
F_39 ( V_104 L_1
L_2
L_3 ) ;
V_100 = 1 ;
} else {
int V_105 =
F_17 ( V_3 ) ;
if ( F_18 ( V_3 ) ==
V_106 ) {
F_39 ( V_104 L_1
L_4 ) ;
V_100 = 1 ;
} else if ( V_25 != V_105 ) {
F_39 ( V_104 L_1
L_5
L_6 ) ;
V_100 = 1 ;
}
}
}
V_99 = V_3 -> V_107 ;
if ( V_99 <= 48000 )
V_101 = V_108 ;
else if ( V_99 <= 96000 )
V_101 = V_109 ;
else
V_101 = V_110 ;
if ( V_25 <= 48000 )
V_102 = V_108 ;
else if ( V_25 <= 96000 )
V_102 = V_109 ;
else
V_102 = V_110 ;
switch ( V_25 ) {
case 32000 :
V_33 = V_111 ;
break;
case 44100 :
V_33 = V_112 ;
break;
case 48000 :
V_33 = V_113 ;
break;
case 64000 :
V_33 = V_114 ;
break;
case 88200 :
V_33 = V_115 ;
break;
case 96000 :
V_33 = V_116 ;
break;
case 128000 :
V_33 = V_117 ;
break;
case 176400 :
V_33 = V_118 ;
break;
case 192000 :
V_33 = V_119 ;
break;
default:
return - V_120 ;
}
if ( V_101 != V_102
&& ( V_3 -> V_24 >= 0 || V_3 -> V_23 >= 0 ) ) {
F_39
( V_121 L_1
L_7
L_8 ,
V_122 [ V_101 ] ,
V_122 [ V_102 ] ,
V_3 -> V_24 , V_3 -> V_23 ) ;
return - V_123 ;
}
V_3 -> V_26 &= ~ V_124 ;
V_3 -> V_26 |= V_33 ;
F_2 ( V_3 , V_88 , V_3 -> V_26 ) ;
F_36 ( V_3 , V_25 ) ;
if ( V_35 == V_3 -> V_34 && V_25 != V_99 )
F_2 ( V_3 , V_125 , 0 ) ;
V_3 -> V_107 = V_25 ;
if ( V_25 <= 48000 ) {
V_3 -> V_126 = V_3 -> V_127 ;
V_3 -> V_128 = V_3 -> V_129 ;
V_3 -> V_130 = V_3 -> V_131 ;
V_3 -> V_132 = V_3 -> V_133 ;
V_3 -> V_134 = V_3 -> V_135 ;
V_3 -> V_136 = V_3 -> V_137 ;
} else if ( V_25 <= 96000 ) {
V_3 -> V_126 = V_3 -> V_138 ;
V_3 -> V_128 = V_3 -> V_139 ;
V_3 -> V_130 = V_3 -> V_140 ;
V_3 -> V_132 = V_3 -> V_141 ;
V_3 -> V_134 = V_3 -> V_142 ;
V_3 -> V_136 = V_3 -> V_143 ;
} else {
V_3 -> V_126 = V_3 -> V_144 ;
V_3 -> V_128 = V_3 -> V_145 ;
V_3 -> V_130 = V_3 -> V_146 ;
V_3 -> V_132 = V_3 -> V_147 ;
V_3 -> V_134 = V_3 -> V_148 ;
V_3 -> V_136 = V_3 -> V_149 ;
}
if ( V_100 != 0 )
return - 1 ;
return 0 ;
}
static void F_40 ( struct V_3 * V_3 , int V_150 )
{
int V_16 , V_151 ;
unsigned int V_152 ;
if ( V_150 > V_153 )
V_152 = V_153 ;
else if ( V_150 < 0 )
V_152 = 0 ;
else
V_152 = V_150 ;
for ( V_16 = 0 ; V_16 < V_9 ; V_16 ++ )
for ( V_151 = 0 ; V_151 < V_9 ; V_151 ++ ) {
F_8 ( V_3 , V_16 , V_151 , V_152 ) ;
F_9 ( V_3 , V_16 , V_151 , V_152 ) ;
}
}
static inline unsigned char F_41 ( struct V_3 * V_3 ,
int V_154 )
{
return F_4 ( V_3 , V_3 -> V_155 [ V_154 ] . V_156 ) ;
}
static inline void F_42 ( struct V_3 * V_3 , int V_154 ,
int V_5 )
{
return F_2 ( V_3 , V_3 -> V_155 [ V_154 ] . V_157 , V_5 ) ;
}
static inline int F_43 ( struct V_3 * V_3 , int V_154 )
{
return F_4 ( V_3 , V_3 -> V_155 [ V_154 ] . V_158 ) & 0xFF ;
}
static inline int F_44 ( struct V_3 * V_3 , int V_154 )
{
int V_159 ;
V_159 = F_4 ( V_3 , V_3 -> V_155 [ V_154 ] . V_160 ) & 0xFF ;
if ( V_159 < 128 )
return 128 - V_159 ;
else
return 0 ;
}
static void F_45 ( struct V_3 * V_3 , int V_154 )
{
while ( F_43 ( V_3 , V_154 ) )
F_41 ( V_3 , V_154 ) ;
}
static int F_46 ( struct V_161 * V_162 )
{
unsigned long V_20 ;
int V_163 ;
int V_164 ;
int V_16 ;
unsigned char V_89 [ 128 ] ;
F_13 ( & V_162 -> V_22 , V_20 ) ;
if ( V_162 -> V_165 &&
! F_47 ( V_162 -> V_165 ) ) {
V_163 = F_44 ( V_162 -> V_3 ,
V_162 -> V_154 ) ;
if ( V_163 > 0 ) {
if ( V_163 > ( int ) sizeof ( V_89 ) )
V_163 = sizeof ( V_89 ) ;
V_164 = F_48 ( V_162 -> V_165 , V_89 ,
V_163 ) ;
if ( V_164 > 0 ) {
for ( V_16 = 0 ; V_16 < V_164 ; ++ V_16 )
F_42 ( V_162 -> V_3 ,
V_162 -> V_154 ,
V_89 [ V_16 ] ) ;
}
}
}
F_14 ( & V_162 -> V_22 , V_20 ) ;
return 0 ;
}
static int F_49 ( struct V_161 * V_162 )
{
unsigned char V_89 [ 128 ] ;
unsigned long V_20 ;
int V_163 ;
int V_16 ;
F_13 ( & V_162 -> V_22 , V_20 ) ;
V_163 = F_43 ( V_162 -> V_3 , V_162 -> V_154 ) ;
if ( V_163 > 0 ) {
if ( V_162 -> V_166 ) {
if ( V_163 > ( int ) sizeof ( V_89 ) )
V_163 = sizeof ( V_89 ) ;
for ( V_16 = 0 ; V_16 < V_163 ; ++ V_16 )
V_89 [ V_16 ] = F_41 ( V_162 -> V_3 ,
V_162 -> V_154 ) ;
if ( V_163 )
F_50 ( V_162 -> V_166 , V_89 ,
V_163 ) ;
} else {
while ( V_163 -- )
F_41 ( V_162 -> V_3 ,
V_162 -> V_154 ) ;
}
}
V_162 -> V_167 = 0 ;
F_14 ( & V_162 -> V_22 , V_20 ) ;
F_13 ( & V_162 -> V_3 -> V_22 , V_20 ) ;
V_162 -> V_3 -> V_26 |= V_162 -> V_168 ;
F_2 ( V_162 -> V_3 , V_88 ,
V_162 -> V_3 -> V_26 ) ;
F_14 ( & V_162 -> V_3 -> V_22 , V_20 ) ;
return F_46 ( V_162 ) ;
}
static void
F_51 ( struct V_169 * V_170 , int V_171 )
{
struct V_3 * V_3 ;
struct V_161 * V_162 ;
unsigned long V_20 ;
V_162 = V_170 -> V_172 -> V_173 ;
V_3 = V_162 -> V_3 ;
F_13 ( & V_3 -> V_22 , V_20 ) ;
if ( V_171 ) {
if ( ! ( V_3 -> V_26 & V_162 -> V_168 ) ) {
F_45 ( V_3 , V_162 -> V_154 ) ;
V_3 -> V_26 |= V_162 -> V_168 ;
}
} else {
V_3 -> V_26 &= ~ V_162 -> V_168 ;
}
F_2 ( V_3 , V_88 , V_3 -> V_26 ) ;
F_14 ( & V_3 -> V_22 , V_20 ) ;
}
static void F_52 ( unsigned long V_13 )
{
struct V_161 * V_162 = (struct V_161 * ) V_13 ;
unsigned long V_20 ;
F_46 ( V_162 ) ;
F_13 ( & V_162 -> V_22 , V_20 ) ;
if ( V_162 -> V_174 ) {
V_162 -> V_175 . V_176 = 1 + V_177 ;
F_53 ( & V_162 -> V_175 ) ;
}
F_14 ( & V_162 -> V_22 , V_20 ) ;
}
static void
F_54 ( struct V_169 * V_170 , int V_171 )
{
struct V_161 * V_162 ;
unsigned long V_20 ;
V_162 = V_170 -> V_172 -> V_173 ;
F_13 ( & V_162 -> V_22 , V_20 ) ;
if ( V_171 ) {
if ( ! V_162 -> V_174 ) {
F_55 ( & V_162 -> V_175 ) ;
V_162 -> V_175 . V_178 = F_52 ;
V_162 -> V_175 . V_13 = ( unsigned long ) V_162 ;
V_162 -> V_175 . V_176 = 1 + V_177 ;
F_53 ( & V_162 -> V_175 ) ;
V_162 -> V_174 ++ ;
}
} else {
if ( V_162 -> V_174 && -- V_162 -> V_174 <= 0 )
F_56 ( & V_162 -> V_175 ) ;
}
F_14 ( & V_162 -> V_22 , V_20 ) ;
if ( V_171 )
F_46 ( V_162 ) ;
}
static int F_57 ( struct V_169 * V_170 )
{
struct V_161 * V_162 ;
V_162 = V_170 -> V_172 -> V_173 ;
F_30 ( & V_162 -> V_22 ) ;
F_45 ( V_162 -> V_3 , V_162 -> V_154 ) ;
V_162 -> V_166 = V_170 ;
F_32 ( & V_162 -> V_22 ) ;
return 0 ;
}
static int F_58 ( struct V_169 * V_170 )
{
struct V_161 * V_162 ;
V_162 = V_170 -> V_172 -> V_173 ;
F_30 ( & V_162 -> V_22 ) ;
V_162 -> V_165 = V_170 ;
F_32 ( & V_162 -> V_22 ) ;
return 0 ;
}
static int F_59 ( struct V_169 * V_170 )
{
struct V_161 * V_162 ;
F_51 ( V_170 , 0 ) ;
V_162 = V_170 -> V_172 -> V_173 ;
F_30 ( & V_162 -> V_22 ) ;
V_162 -> V_166 = NULL ;
F_32 ( & V_162 -> V_22 ) ;
return 0 ;
}
static int F_60 ( struct V_169 * V_170 )
{
struct V_161 * V_162 ;
F_54 ( V_170 , 0 ) ;
V_162 = V_170 -> V_172 -> V_173 ;
F_30 ( & V_162 -> V_22 ) ;
V_162 -> V_165 = NULL ;
F_32 ( & V_162 -> V_22 ) ;
return 0 ;
}
static int F_61 ( struct V_179 * V_180 ,
struct V_3 * V_3 , int V_154 )
{
int V_181 ;
char V_89 [ 32 ] ;
V_3 -> V_155 [ V_154 ] . V_154 = V_154 ;
V_3 -> V_155 [ V_154 ] . V_3 = V_3 ;
F_62 ( & V_3 -> V_155 [ V_154 ] . V_22 ) ;
if ( 0 == V_154 ) {
if ( V_45 == V_3 -> V_34 ) {
V_3 -> V_155 [ 0 ] . V_156 = V_182 ;
V_3 -> V_155 [ 0 ] . V_158 = V_183 ;
V_3 -> V_155 [ 0 ] . V_157 = V_184 ;
V_3 -> V_155 [ 0 ] . V_160 = V_185 ;
V_3 -> V_155 [ 0 ] . V_168 = V_186 ;
V_3 -> V_155 [ 0 ] . V_187 = V_188 ;
} else {
V_3 -> V_155 [ 0 ] . V_156 = V_189 ;
V_3 -> V_155 [ 0 ] . V_158 = V_190 ;
V_3 -> V_155 [ 0 ] . V_157 = V_191 ;
V_3 -> V_155 [ 0 ] . V_160 = V_192 ;
V_3 -> V_155 [ 0 ] . V_168 = V_193 ;
V_3 -> V_155 [ 0 ] . V_187 = V_194 ;
}
} else if ( 1 == V_154 ) {
V_3 -> V_155 [ 1 ] . V_156 = V_195 ;
V_3 -> V_155 [ 1 ] . V_158 = V_196 ;
V_3 -> V_155 [ 1 ] . V_157 = V_197 ;
V_3 -> V_155 [ 1 ] . V_160 = V_198 ;
V_3 -> V_155 [ 1 ] . V_168 = V_199 ;
V_3 -> V_155 [ 1 ] . V_187 = V_200 ;
} else if ( ( 2 == V_154 ) && ( V_49 == V_3 -> V_34 ) ) {
V_3 -> V_155 [ 2 ] . V_156 = V_182 ;
V_3 -> V_155 [ 2 ] . V_158 = V_183 ;
V_3 -> V_155 [ 2 ] . V_157 = V_184 ;
V_3 -> V_155 [ 2 ] . V_160 = V_185 ;
V_3 -> V_155 [ 2 ] . V_168 = V_186 ;
V_3 -> V_155 [ 2 ] . V_187 = V_188 ;
} else if ( 2 == V_154 ) {
V_3 -> V_155 [ 2 ] . V_156 = V_182 ;
V_3 -> V_155 [ 2 ] . V_158 = V_183 ;
V_3 -> V_155 [ 2 ] . V_157 = - 1 ;
V_3 -> V_155 [ 2 ] . V_160 = - 1 ;
V_3 -> V_155 [ 2 ] . V_168 = V_186 ;
V_3 -> V_155 [ 2 ] . V_187 = V_201 ;
} else if ( 3 == V_154 ) {
V_3 -> V_155 [ 3 ] . V_156 = V_202 ;
V_3 -> V_155 [ 3 ] . V_158 = V_203 ;
V_3 -> V_155 [ 3 ] . V_157 = - 1 ;
V_3 -> V_155 [ 3 ] . V_160 = - 1 ;
V_3 -> V_155 [ 3 ] . V_168 = V_204 ;
V_3 -> V_155 [ 3 ] . V_187 = V_205 ;
}
if ( ( V_154 < 2 ) || ( ( 2 == V_154 ) && ( ( V_49 == V_3 -> V_34 ) ||
( V_45 == V_3 -> V_34 ) ) ) ) {
if ( ( V_154 == 0 ) && ( V_45 == V_3 -> V_34 ) ) {
sprintf ( V_89 , L_9 , V_180 -> V_206 ) ;
} else if ( ( V_154 == 2 ) && ( V_49 == V_3 -> V_34 ) ) {
sprintf ( V_89 , L_9 , V_180 -> V_206 ) ;
} else {
sprintf ( V_89 , L_10 , V_180 -> V_206 , V_154 + 1 ) ;
}
V_181 = F_63 ( V_180 , V_89 , V_154 , 1 , 1 ,
& V_3 -> V_155 [ V_154 ] . V_172 ) ;
if ( V_181 < 0 )
return V_181 ;
sprintf ( V_3 -> V_155 [ V_154 ] . V_172 -> V_207 , L_10 ,
V_180 -> V_154 , V_154 + 1 ) ;
V_3 -> V_155 [ V_154 ] . V_172 -> V_173 = & V_3 -> V_155 [ V_154 ] ;
F_64 ( V_3 -> V_155 [ V_154 ] . V_172 ,
V_208 ,
& V_209 ) ;
F_64 ( V_3 -> V_155 [ V_154 ] . V_172 ,
V_210 ,
& V_211 ) ;
V_3 -> V_155 [ V_154 ] . V_172 -> V_212 |=
V_213 |
V_214 |
V_215 ;
} else {
sprintf ( V_89 , L_11 , V_180 -> V_206 , V_154 + 1 ) ;
V_181 = F_63 ( V_180 , V_89 , V_154 , 1 , 1 ,
& V_3 -> V_155 [ V_154 ] . V_172 ) ;
if ( V_181 < 0 )
return V_181 ;
sprintf ( V_3 -> V_155 [ V_154 ] . V_172 -> V_207 ,
L_11 , V_180 -> V_154 , V_154 + 1 ) ;
V_3 -> V_155 [ V_154 ] . V_172 -> V_173 = & V_3 -> V_155 [ V_154 ] ;
F_64 ( V_3 -> V_155 [ V_154 ] . V_172 ,
V_210 ,
& V_211 ) ;
V_3 -> V_155 [ V_154 ] . V_172 -> V_212 |= V_214 ;
}
return 0 ;
}
static void F_65 ( unsigned long V_216 )
{
struct V_3 * V_3 = (struct V_3 * ) V_216 ;
int V_16 = 0 ;
while ( V_16 < V_3 -> V_217 ) {
if ( V_3 -> V_155 [ V_16 ] . V_167 )
F_49 ( & V_3 -> V_155 [ V_16 ] ) ;
V_16 ++ ;
}
}
static inline int F_21 ( struct V_3 * V_3 )
{
unsigned int V_95 , V_25 ;
V_95 = F_4 ( V_3 , V_218 ) ;
V_25 = F_33 ( V_3 , V_95 ) ;
return V_25 ;
}
static int F_66 ( struct V_3 * V_3 )
{
unsigned int V_25 ;
V_25 = F_21 ( V_3 ) ;
if ( V_25 > 207000 ) {
if ( 0 == F_67 ( V_3 ) ) {
V_25 = V_3 -> V_107 ;
} else {
V_25 = F_17 ( V_3 ) ;
}
}
return V_25 ;
}
static int F_68 ( struct V_219 * V_220 ,
struct V_221 * V_222 )
{
V_222 -> type = V_223 ;
V_222 -> V_224 = 1 ;
V_222 -> V_225 . integer . V_226 = 27000 ;
V_222 -> V_225 . integer . V_227 = 207000 ;
V_222 -> V_225 . integer . V_228 = 1 ;
return 0 ;
}
static int F_69 ( struct V_219 * V_220 ,
struct V_229 *
V_230 )
{
struct V_3 * V_3 = F_70 ( V_220 ) ;
V_230 -> V_225 . integer . V_225 [ 0 ] = F_66 ( V_3 ) ;
return 0 ;
}
static int F_71 ( struct V_219 * V_220 ,
struct V_229 *
V_230 )
{
struct V_3 * V_3 = F_70 ( V_220 ) ;
F_36 ( V_3 , V_230 -> V_225 . V_231 . V_232 [ 0 ] ) ;
return 0 ;
}
static int F_72 ( struct V_3 * V_3 )
{
int V_29 ;
switch ( V_3 -> V_34 ) {
case V_51 :
case V_50 :
V_29 = F_4 ( V_3 , V_233 ) ;
return ( V_29 >> 16 ) & 0xF ;
break;
default:
break;
}
return 0 ;
}
static int F_73 ( struct V_3 * V_3 )
{
int V_29 ;
if ( V_3 -> V_234 ) {
switch ( V_3 -> V_34 ) {
case V_51 :
case V_50 :
V_29 = F_4 ( V_3 , V_233 ) ;
return ( V_29 >> 20 ) & 0xF ;
break;
default:
break;
}
}
return 0 ;
}
static int F_74 ( struct V_3 * V_3 )
{
int V_29 ;
if ( V_3 -> V_234 ) {
switch ( V_3 -> V_34 ) {
case V_51 :
case V_50 :
V_29 = F_4 ( V_3 , V_235 ) ;
return ( V_29 >> 12 ) & 0xF ;
break;
default:
break;
}
}
return 0 ;
}
static int F_75 ( struct V_3 * V_3 , unsigned int V_236 )
{
int V_29 = F_4 ( V_3 , V_235 ) ;
return ( V_29 >> ( V_236 * 4 ) ) & 0xF ;
}
static int F_76 ( struct V_219 * V_220 ,
struct V_221 * V_222 )
{
F_77 ( V_222 , V_237 ) ;
return 0 ;
}
static int F_78 ( struct V_219 * V_220 ,
struct V_229 *
V_230 )
{
struct V_3 * V_3 = F_70 ( V_220 ) ;
switch ( V_3 -> V_34 ) {
case V_51 :
switch ( V_220 -> V_238 ) {
case 0 :
V_230 -> V_225 . V_231 . V_232 [ 0 ] =
F_72 ( V_3 ) ;
break;
case 7 :
V_230 -> V_225 . V_231 . V_232 [ 0 ] =
F_73 ( V_3 ) ;
break;
case 8 :
V_230 -> V_225 . V_231 . V_232 [ 0 ] =
F_74 ( V_3 ) ;
break;
default:
V_230 -> V_225 . V_231 . V_232 [ 0 ] =
F_75 ( V_3 ,
V_220 -> V_238 - 1 ) ;
}
break;
case V_50 :
switch ( V_220 -> V_238 ) {
case 0 :
V_230 -> V_225 . V_231 . V_232 [ 0 ] =
F_72 ( V_3 ) ;
break;
case 4 :
V_230 -> V_225 . V_231 . V_232 [ 0 ] =
F_73 ( V_3 ) ;
break;
case 5 :
V_230 -> V_225 . V_231 . V_232 [ 0 ] =
F_74 ( V_3 ) ;
break;
default:
V_230 -> V_225 . V_231 . V_232 [ 0 ] =
F_75 ( V_3 ,
V_230 -> V_154 . V_239 - 1 ) ;
}
break;
case V_35 :
switch ( V_220 -> V_238 ) {
case 0 :
V_230 -> V_225 . V_231 . V_232 [ 0 ] =
F_72 ( V_3 ) ;
break;
case 9 :
V_230 -> V_225 . V_231 . V_232 [ 0 ] =
F_73 ( V_3 ) ;
break;
case 10 :
V_230 -> V_225 . V_231 . V_232 [ 0 ] =
F_74 ( V_3 ) ;
break;
default:
V_230 -> V_225 . V_231 . V_232 [ 0 ] =
F_75 ( V_3 ,
V_220 -> V_238 - 1 ) ;
break;
}
break;
case V_49 :
case V_45 :
{
int V_25 = F_17 ( V_3 ) ;
int V_16 , V_240 = 0 ;
for ( V_16 = 1 ; V_16 < 10 ; V_16 ++ )
if ( F_1 ( V_16 ) == V_25 ) {
V_240 = V_16 ;
break;
}
V_230 -> V_225 . V_231 . V_232 [ 0 ] = V_240 ;
}
break;
default:
break;
}
return 0 ;
}
static int F_67 ( struct V_3 * V_3 )
{
switch ( V_3 -> V_34 ) {
case V_50 :
case V_51 :
if ( V_3 -> V_241 & V_242 )
return 0 ;
break;
default:
if ( V_3 -> V_26 & V_103 )
return 0 ;
}
return 1 ;
}
static void F_79 ( struct V_3 * V_3 , int V_243 )
{
switch ( V_3 -> V_34 ) {
case V_50 :
case V_51 :
if ( 0 == V_243 )
V_3 -> V_241 |= V_242 ;
else
V_3 -> V_241 &= ~ V_242 ;
F_2 ( V_3 , V_244 , V_3 -> V_241 ) ;
break;
default:
if ( 0 == V_243 )
V_3 -> V_26 |= V_103 ;
else
V_3 -> V_26 &= ~ V_103 ;
F_2 ( V_3 , V_88 ,
V_3 -> V_26 ) ;
}
}
static int F_80 ( struct V_219 * V_220 ,
struct V_221 * V_222 )
{
static char * V_245 [] = { L_12 , L_13 } ;
F_77 ( V_222 , V_245 ) ;
return 0 ;
}
static int F_81 ( struct V_219 * V_220 ,
struct V_229 * V_230 )
{
struct V_3 * V_3 = F_70 ( V_220 ) ;
V_230 -> V_225 . V_231 . V_232 [ 0 ] = F_67 ( V_3 ) ;
return 0 ;
}
static int F_82 ( struct V_219 * V_220 ,
struct V_229 * V_230 )
{
struct V_3 * V_3 = F_70 ( V_220 ) ;
int V_5 ;
if ( ! F_12 ( V_3 ) )
return - V_123 ;
V_5 = V_230 -> V_225 . V_231 . V_232 [ 0 ] ;
if ( V_5 < 0 )
V_5 = 0 ;
else if ( V_5 > 1 )
V_5 = 1 ;
F_79 ( V_3 , V_5 ) ;
return 0 ;
}
static int F_83 ( struct V_3 * V_3 )
{
switch ( V_3 -> V_107 ) {
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
static int F_84 ( struct V_3 * V_3 , int V_243 )
{
int V_25 ;
switch ( V_243 ) {
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
F_38 ( V_3 , V_25 , 1 ) ;
return 0 ;
}
static int F_85 ( struct V_219 * V_220 ,
struct V_221 * V_222 )
{
V_222 -> type = V_246 ;
V_222 -> V_224 = 1 ;
V_222 -> V_225 . V_231 . V_247 = 9 ;
if ( V_222 -> V_225 . V_231 . V_232 >= V_222 -> V_225 . V_231 . V_247 )
V_222 -> V_225 . V_231 . V_232 =
V_222 -> V_225 . V_231 . V_247 - 1 ;
strcpy ( V_222 -> V_225 . V_231 . V_207 ,
V_237 [ V_222 -> V_225 . V_231 . V_232 + 1 ] ) ;
return 0 ;
}
static int F_86 ( struct V_219 * V_220 ,
struct V_229 * V_230 )
{
struct V_3 * V_3 = F_70 ( V_220 ) ;
V_230 -> V_225 . V_231 . V_232 [ 0 ] = F_83 ( V_3 ) ;
return 0 ;
}
static int F_87 ( struct V_219 * V_220 ,
struct V_229 * V_230 )
{
struct V_3 * V_3 = F_70 ( V_220 ) ;
int V_248 ;
int V_5 ;
if ( ! F_12 ( V_3 ) )
return - V_123 ;
V_5 = V_230 -> V_225 . V_231 . V_232 [ 0 ] ;
if ( V_5 < 0 )
V_5 = 0 ;
if ( V_5 > 9 )
V_5 = 9 ;
F_30 ( & V_3 -> V_22 ) ;
if ( V_5 != F_83 ( V_3 ) )
V_248 = ( F_84 ( V_3 , V_5 ) == 0 ) ? 1 : 0 ;
else
V_248 = 0 ;
F_32 ( & V_3 -> V_22 ) ;
return V_248 ;
}
static int F_88 ( struct V_3 * V_3 )
{
switch ( V_3 -> V_34 ) {
case V_35 :
switch ( V_3 -> V_26 & V_249 ) {
case 0 : return 0 ;
case V_250 : return 1 ;
case V_251 : return 2 ;
case V_251 + V_250 : return 3 ;
case V_252 : return 4 ;
case V_252 + V_250 : return 5 ;
case V_252 + V_251 : return 6 ;
case V_252 + V_251 + V_250 :
return 7 ;
case V_253 : return 8 ;
case V_253 + V_250 : return 9 ;
}
break;
case V_49 :
case V_45 :
if ( V_3 -> V_234 ) {
switch ( V_3 -> V_26 & V_249 ) {
case 0 : return 0 ;
case V_250 : return 1 ;
case V_251 : return 2 ;
case V_251 + V_250 :
return 3 ;
}
} else {
switch ( V_3 -> V_26 & V_249 ) {
case 0 : return 0 ;
case V_250 : return 1 ;
case V_251 + V_250 :
return 2 ;
}
}
break;
case V_51 :
if ( V_3 -> V_234 ) {
switch ( ( V_3 -> V_241 &
V_254 ) / V_255 ) {
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
switch ( ( V_3 -> V_241 &
V_254 ) / V_255 ) {
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
case V_50 :
if ( V_3 -> V_234 ) {
switch ( ( V_3 -> V_241 &
V_254 ) / V_255 ) {
case 0 : return 0 ;
case 3 : return 1 ;
case 1 : return 2 ;
case 2 : return 3 ;
case 9 : return 4 ;
case 10 : return 5 ;
}
} else {
switch ( ( V_3 -> V_241 &
V_254 ) / V_255 ) {
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
static int F_89 ( struct V_3 * V_3 , int V_256 )
{
int V_257 = 0 ;
switch ( V_3 -> V_34 ) {
case V_35 :
V_3 -> V_26 &= ~ V_249 ;
switch ( V_256 ) {
case 0 :
break;
case 1 :
V_3 -> V_26 |= V_250 ;
break;
case 2 :
V_3 -> V_26 |= V_251 ;
break;
case 3 :
V_3 -> V_26 |=
V_251 + V_250 ;
break;
case 4 :
V_3 -> V_26 |= V_252 ;
break;
case 5 :
V_3 -> V_26 |=
V_252 + V_250 ;
break;
case 6 :
V_3 -> V_26 |=
V_252 + V_251 ;
break;
case 7 :
V_3 -> V_26 |=
V_252 + V_251 + V_250 ;
break;
case 8 :
V_3 -> V_26 |= V_253 ;
break;
case 9 :
V_3 -> V_26 |=
V_253 + V_250 ;
break;
default:
return - 1 ;
}
break;
case V_49 :
case V_45 :
V_3 -> V_26 &= ~ V_249 ;
if ( V_3 -> V_234 ) {
switch ( V_256 ) {
case 0 :
break;
case 1 :
V_3 -> V_26 |= V_250 ;
break;
case 2 :
V_3 -> V_26 |= V_251 ;
break;
case 3 :
V_3 -> V_26 |=
V_250 + V_251 ;
break;
default:
return - 1 ;
}
} else {
switch ( V_256 ) {
case 0 :
break;
case 1 :
V_3 -> V_26 |= V_250 ;
break;
case 2 :
V_3 -> V_26 |=
V_250 + V_251 ;
break;
default:
return - 1 ;
}
}
break;
case V_51 :
if ( V_3 -> V_234 ) {
switch ( V_256 ) {
case 0 : V_257 = 0 ; break;
case 1 : V_257 = 3 ; break;
case 2 : V_257 = 4 ; break;
case 3 : V_257 = 5 ; break;
case 4 : V_257 = 6 ; break;
case 5 : V_257 = 1 ; break;
case 6 : V_257 = 2 ; break;
case 7 : V_257 = 9 ; break;
case 8 : V_257 = 10 ; break;
default: return - 1 ;
}
} else {
switch ( V_256 ) {
case 0 : V_257 = 0 ; break;
case 1 : V_257 = 3 ; break;
case 2 : V_257 = 4 ; break;
case 3 : V_257 = 5 ; break;
case 4 : V_257 = 6 ; break;
case 5 : V_257 = 1 ; break;
case 6 : V_257 = 2 ; break;
case 7 : V_257 = 10 ; break;
default: return - 1 ;
}
}
break;
case V_50 :
if ( V_3 -> V_234 ) {
switch ( V_256 ) {
case 0 : V_257 = 0 ; break;
case 1 : V_257 = 3 ; break;
case 2 : V_257 = 1 ; break;
case 3 : V_257 = 2 ; break;
case 4 : V_257 = 9 ; break;
case 5 : V_257 = 10 ; break;
default: return - 1 ;
}
} else {
switch ( V_256 ) {
case 0 : V_257 = 0 ; break;
case 1 : V_257 = 3 ; break;
case 2 : V_257 = 1 ; break;
case 3 : V_257 = 2 ; break;
case 4 : V_257 = 10 ; break;
default: return - 1 ;
}
}
break;
}
switch ( V_3 -> V_34 ) {
case V_51 :
case V_50 :
V_3 -> V_241 &= ~ V_254 ;
V_3 -> V_241 |= V_255 * V_257 ;
F_2 ( V_3 , V_244 , V_3 -> V_241 ) ;
break;
case V_49 :
case V_45 :
case V_35 :
F_2 ( V_3 , V_88 ,
V_3 -> V_26 ) ;
}
return 0 ;
}
static int F_90 ( struct V_219 * V_220 ,
struct V_221 * V_222 )
{
struct V_3 * V_3 = F_70 ( V_220 ) ;
V_222 -> type = V_246 ;
V_222 -> V_224 = 1 ;
V_222 -> V_225 . V_231 . V_247 = V_3 -> V_258 ;
if ( V_222 -> V_225 . V_231 . V_232 >= V_222 -> V_225 . V_231 . V_247 )
V_222 -> V_225 . V_231 . V_232 =
V_222 -> V_225 . V_231 . V_247 - 1 ;
strcpy ( V_222 -> V_225 . V_231 . V_207 ,
V_3 -> V_259 [ V_222 -> V_225 . V_231 . V_232 ] ) ;
return 0 ;
}
static int F_91 ( struct V_219 * V_220 ,
struct V_229 * V_230 )
{
struct V_3 * V_3 = F_70 ( V_220 ) ;
int V_260 = F_88 ( V_3 ) ;
if ( V_260 >= 0 ) {
V_230 -> V_225 . V_231 . V_232 [ 0 ] = V_260 ;
return 0 ;
}
return - 1 ;
}
static int F_92 ( struct V_219 * V_220 ,
struct V_229 * V_230 )
{
struct V_3 * V_3 = F_70 ( V_220 ) ;
int V_5 , V_248 = 0 ;
if ( ! F_12 ( V_3 ) )
return - V_123 ;
V_5 = V_230 -> V_225 . V_231 . V_232 [ 0 ] ;
if ( V_5 < 0 )
V_5 = 0 ;
else if ( V_5 >= V_3 -> V_258 )
V_5 = V_3 -> V_258 - 1 ;
F_30 ( & V_3 -> V_22 ) ;
if ( V_5 != F_88 ( V_3 ) )
V_248 = ( 0 == F_89 ( V_3 , V_5 ) ) ? 1 : 0 ;
F_32 ( & V_3 -> V_22 ) ;
return V_248 ;
}
static int F_18 ( struct V_3 * V_3 )
{
if ( V_35 == V_3 -> V_34 ) {
unsigned int V_29 = F_4 ( V_3 , V_37 ) ;
unsigned int V_32 =
( V_29 >> V_261 ) & 0xF ;
if ( V_32 == 0 )
return V_39 ;
if ( V_32 <= 8 )
return V_32 ;
return V_262 ;
} else if ( V_49 == V_3 -> V_34 ) {
unsigned int V_30 = F_4 ( V_3 , V_36 ) ;
switch ( V_30 & V_64 ) {
case V_65 :
return V_263 ;
case V_264 :
return V_265 ;
case V_266 :
return V_78 ;
case V_267 :
return V_80 ;
case V_268 :
return V_106 ;
default:
return 0 ;
}
}
return 0 ;
}
static int F_93 ( struct V_219 * V_220 ,
struct V_221 * V_222 )
{
struct V_3 * V_3 = F_70 ( V_220 ) ;
if ( V_35 == V_3 -> V_34 ) {
static char * V_245 [] = { L_14 , L_15 , L_16 , L_17 ,
L_18 , L_19 , L_20 , L_21 , L_22 , L_23 } ;
V_222 -> type = V_246 ;
V_222 -> V_224 = 1 ;
V_222 -> V_225 . V_231 . V_247 = 10 ;
if ( V_222 -> V_225 . V_231 . V_232 >=
V_222 -> V_225 . V_231 . V_247 )
V_222 -> V_225 . V_231 . V_232 =
V_222 -> V_225 . V_231 . V_247 - 1 ;
strcpy ( V_222 -> V_225 . V_231 . V_207 ,
V_245 [ V_222 -> V_225 . V_231 . V_232 ] ) ;
} else if ( V_49 == V_3 -> V_34 ) {
static char * V_245 [] = { L_24 , L_25 , L_26 ,
L_27 , L_23 } ;
V_222 -> type = V_246 ;
V_222 -> V_224 = 1 ;
V_222 -> V_225 . V_231 . V_247 = 5 ;
if ( V_222 -> V_225 . V_231 . V_232 >=
V_222 -> V_225 . V_231 . V_247 )
V_222 -> V_225 . V_231 . V_232 =
V_222 -> V_225 . V_231 . V_247 - 1 ;
strcpy ( V_222 -> V_225 . V_231 . V_207 ,
V_245 [ V_222 -> V_225 . V_231 . V_232 ] ) ;
}
return 0 ;
}
static int F_94 ( struct V_219 * V_220 ,
struct V_229 * V_230 )
{
struct V_3 * V_3 = F_70 ( V_220 ) ;
V_230 -> V_225 . V_231 . V_232 [ 0 ] = F_18 ( V_3 ) ;
return 0 ;
}
static int F_95 ( struct V_219 * V_220 ,
struct V_221 * V_222 )
{
static char * V_245 [] = { L_28 , L_29 , L_30 } ;
F_77 ( V_222 , V_245 ) ;
return 0 ;
}
static int F_96 ( struct V_219 * V_220 ,
struct V_229 * V_230 )
{
V_15 V_29 ;
int V_21 = 0 ;
struct V_3 * V_3 = F_70 ( V_220 ) ;
V_29 = F_4 ( V_3 , V_269 + 4 ) ;
switch ( V_29 & ( V_270 |
V_271 ) ) {
case V_270 :
V_21 = 1 ;
break;
case V_271 :
V_21 = 2 ;
break;
default:
V_21 = 0 ;
break;
}
V_230 -> V_225 . V_231 . V_232 [ 0 ] = V_21 ;
return 0 ;
}
static int F_97 ( struct V_219 * V_220 ,
struct V_221 * V_222 )
{
static char * V_245 [] = { L_31 , L_32 , L_33 , L_34 ,
L_35 } ;
F_77 ( V_222 , V_245 ) ;
return 0 ;
}
static int F_98 ( struct V_3 * V_3 )
{
V_15 V_29 ;
int V_21 = 0 ;
V_29 = F_4 ( V_3 , V_269 + 4 ) ;
if ( V_29 & V_272 ) {
switch ( V_29 & ( V_273 |
V_274 ) ) {
case 0 :
V_21 = 1 ;
break;
case V_273 :
V_21 = 2 ;
break;
case V_274 :
V_21 = 3 ;
break;
default:
V_21 = 4 ;
break;
}
}
return V_21 ;
}
static int F_99 ( struct V_219 * V_220 ,
struct V_229 * V_230 )
{
struct V_3 * V_3 = F_70 ( V_220 ) ;
V_230 -> V_225 . V_231 . V_232 [ 0 ] = F_98 ( V_3 ) ;
return 0 ;
}
static int F_100 ( struct V_3 * V_3 , V_15 V_275 )
{
return ( V_3 -> V_26 & V_275 ) ? 1 : 0 ;
}
static int F_101 ( struct V_3 * V_3 , V_15 V_275 , int V_276 )
{
if ( V_276 )
V_3 -> V_26 |= V_275 ;
else
V_3 -> V_26 &= ~ V_275 ;
F_2 ( V_3 , V_88 , V_3 -> V_26 ) ;
return 0 ;
}
static int F_102 ( struct V_219 * V_220 ,
struct V_229 * V_230 )
{
struct V_3 * V_3 = F_70 ( V_220 ) ;
V_15 V_275 = V_220 -> V_238 ;
F_30 ( & V_3 -> V_22 ) ;
V_230 -> V_225 . integer . V_225 [ 0 ] = F_100 ( V_3 , V_275 ) ;
F_32 ( & V_3 -> V_22 ) ;
return 0 ;
}
static int F_103 ( struct V_219 * V_220 ,
struct V_229 * V_230 )
{
struct V_3 * V_3 = F_70 ( V_220 ) ;
V_15 V_275 = V_220 -> V_238 ;
int V_248 ;
unsigned int V_5 ;
if ( ! F_12 ( V_3 ) )
return - V_123 ;
V_5 = V_230 -> V_225 . integer . V_225 [ 0 ] & 1 ;
F_30 ( & V_3 -> V_22 ) ;
V_248 = ( int ) V_5 != F_100 ( V_3 , V_275 ) ;
F_101 ( V_3 , V_275 , V_5 ) ;
F_32 ( & V_3 -> V_22 ) ;
return V_248 ;
}
static int F_104 ( struct V_3 * V_3 )
{
return ( V_3 -> V_26 & V_277 ) ? 1 : 0 ;
}
static int F_105 ( struct V_3 * V_3 , int V_276 )
{
if ( V_276 )
V_3 -> V_26 |= V_277 ;
else
V_3 -> V_26 &= ~ V_277 ;
F_2 ( V_3 , V_88 , V_3 -> V_26 ) ;
return 0 ;
}
static int F_106 ( struct V_219 * V_220 ,
struct V_221 * V_222 )
{
static char * V_245 [] = { L_36 , L_37 } ;
F_77 ( V_222 , V_245 ) ;
return 0 ;
}
static int F_107 ( struct V_219 * V_220 ,
struct V_229 * V_230 )
{
struct V_3 * V_3 = F_70 ( V_220 ) ;
F_30 ( & V_3 -> V_22 ) ;
V_230 -> V_225 . V_231 . V_232 [ 0 ] = F_104 ( V_3 ) ;
F_32 ( & V_3 -> V_22 ) ;
return 0 ;
}
static int F_108 ( struct V_219 * V_220 ,
struct V_229 * V_230 )
{
struct V_3 * V_3 = F_70 ( V_220 ) ;
int V_248 ;
unsigned int V_5 ;
if ( ! F_12 ( V_3 ) )
return - V_123 ;
V_5 = V_230 -> V_225 . integer . V_225 [ 0 ] & 1 ;
F_30 ( & V_3 -> V_22 ) ;
V_248 = ( int ) V_5 != F_104 ( V_3 ) ;
F_105 ( V_3 , V_5 ) ;
F_32 ( & V_3 -> V_22 ) ;
return V_248 ;
}
static int F_109 ( struct V_3 * V_3 )
{
return ( V_3 -> V_26 & V_278 ) ? 1 : 0 ;
}
static int F_110 ( struct V_3 * V_3 , int V_279 )
{
if ( V_279 )
V_3 -> V_26 |= V_278 ;
else
V_3 -> V_26 &= ~ V_278 ;
F_2 ( V_3 , V_88 , V_3 -> V_26 ) ;
return 0 ;
}
static int F_111 ( struct V_219 * V_220 ,
struct V_221 * V_222 )
{
static char * V_245 [] = { L_38 , L_39 } ;
F_77 ( V_222 , V_245 ) ;
return 0 ;
}
static int F_112 ( struct V_219 * V_220 ,
struct V_229 * V_230 )
{
struct V_3 * V_3 = F_70 ( V_220 ) ;
F_30 ( & V_3 -> V_22 ) ;
V_230 -> V_225 . V_231 . V_232 [ 0 ] = F_109 ( V_3 ) ;
F_32 ( & V_3 -> V_22 ) ;
return 0 ;
}
static int F_113 ( struct V_219 * V_220 ,
struct V_229 * V_230 )
{
struct V_3 * V_3 = F_70 ( V_220 ) ;
int V_248 ;
unsigned int V_5 ;
if ( ! F_12 ( V_3 ) )
return - V_123 ;
V_5 = V_230 -> V_225 . integer . V_225 [ 0 ] & 1 ;
F_30 ( & V_3 -> V_22 ) ;
V_248 = ( int ) V_5 != F_109 ( V_3 ) ;
F_110 ( V_3 , V_5 ) ;
F_32 ( & V_3 -> V_22 ) ;
return V_248 ;
}
static int F_114 ( struct V_3 * V_3 )
{
if ( V_3 -> V_26 & V_280 )
return 1 ;
if ( V_3 -> V_26 & V_281 )
return 2 ;
return 0 ;
}
static int F_115 ( struct V_3 * V_3 , int V_243 )
{
V_3 -> V_26 &= ~ ( V_280 | V_281 ) ;
switch ( V_243 ) {
case 0 :
break;
case 1 :
V_3 -> V_26 |= V_280 ;
break;
case 2 :
V_3 -> V_26 |= V_281 ;
break;
}
F_2 ( V_3 , V_88 , V_3 -> V_26 ) ;
return 0 ;
}
static int F_116 ( struct V_219 * V_220 ,
struct V_221 * V_222 )
{
static char * V_245 [] = { L_38 , L_39 , L_40 } ;
F_77 ( V_222 , V_245 ) ;
return 0 ;
}
static int F_117 ( struct V_219 * V_220 ,
struct V_229 * V_230 )
{
struct V_3 * V_3 = F_70 ( V_220 ) ;
F_30 ( & V_3 -> V_22 ) ;
V_230 -> V_225 . V_231 . V_232 [ 0 ] = F_114 ( V_3 ) ;
F_32 ( & V_3 -> V_22 ) ;
return 0 ;
}
static int F_118 ( struct V_219 * V_220 ,
struct V_229 * V_230 )
{
struct V_3 * V_3 = F_70 ( V_220 ) ;
int V_248 ;
int V_5 ;
if ( ! F_12 ( V_3 ) )
return - V_123 ;
V_5 = V_230 -> V_225 . integer . V_225 [ 0 ] ;
if ( V_5 < 0 )
V_5 = 0 ;
if ( V_5 > 2 )
V_5 = 2 ;
F_30 ( & V_3 -> V_22 ) ;
V_248 = V_5 != F_114 ( V_3 ) ;
F_115 ( V_3 , V_5 ) ;
F_32 ( & V_3 -> V_22 ) ;
return V_248 ;
}
static int F_119 ( struct V_3 * V_3 )
{
if ( V_3 -> V_26 & V_27 )
return 2 ;
if ( V_3 -> V_26 & V_28 )
return 1 ;
return 0 ;
}
static int F_120 ( struct V_3 * V_3 , int V_243 )
{
V_3 -> V_26 &= ~ ( V_28 | V_27 ) ;
switch ( V_243 ) {
case 0 :
break;
case 1 :
V_3 -> V_26 |= V_28 ;
break;
case 2 :
V_3 -> V_26 |= V_27 ;
break;
}
F_2 ( V_3 , V_88 , V_3 -> V_26 ) ;
return 0 ;
}
static int F_121 ( struct V_219 * V_220 ,
struct V_221 * V_222 )
{
static char * V_245 [] = { L_38 , L_39 , L_40 } ;
F_77 ( V_222 , V_245 ) ;
return 0 ;
}
static int F_122 ( struct V_219 * V_220 ,
struct V_229 * V_230 )
{
struct V_3 * V_3 = F_70 ( V_220 ) ;
F_30 ( & V_3 -> V_22 ) ;
V_230 -> V_225 . V_231 . V_232 [ 0 ] = F_119 ( V_3 ) ;
F_32 ( & V_3 -> V_22 ) ;
return 0 ;
}
static int F_123 ( struct V_219 * V_220 ,
struct V_229 * V_230 )
{
struct V_3 * V_3 = F_70 ( V_220 ) ;
int V_248 ;
int V_5 ;
if ( ! F_12 ( V_3 ) )
return - V_123 ;
V_5 = V_230 -> V_225 . integer . V_225 [ 0 ] ;
if ( V_5 < 0 )
V_5 = 0 ;
if ( V_5 > 2 )
V_5 = 2 ;
F_30 ( & V_3 -> V_22 ) ;
V_248 = V_5 != F_119 ( V_3 ) ;
F_120 ( V_3 , V_5 ) ;
F_32 ( & V_3 -> V_22 ) ;
return V_248 ;
}
static int F_124 ( struct V_219 * V_220 ,
struct V_221 * V_222 )
{
V_222 -> type = V_223 ;
V_222 -> V_224 = 3 ;
V_222 -> V_225 . integer . V_226 = 0 ;
V_222 -> V_225 . integer . V_227 = 65535 ;
V_222 -> V_225 . integer . V_228 = 1 ;
return 0 ;
}
static int F_125 ( struct V_219 * V_220 ,
struct V_229 * V_230 )
{
struct V_3 * V_3 = F_70 ( V_220 ) ;
int V_282 ;
int V_283 ;
V_282 = V_230 -> V_225 . integer . V_225 [ 0 ] ;
if ( V_282 < 0 )
V_282 = 0 ;
else if ( V_282 >= 2 * V_91 )
V_282 = 2 * V_91 - 1 ;
V_283 = V_230 -> V_225 . integer . V_225 [ 1 ] ;
if ( V_283 < 0 )
V_283 = 0 ;
else if ( V_283 >= V_91 )
V_283 = V_91 - 1 ;
F_30 ( & V_3 -> V_22 ) ;
if ( V_282 >= V_91 )
V_230 -> V_225 . integer . V_225 [ 2 ] =
F_7 ( V_3 , V_283 ,
V_282 - V_91 ) ;
else
V_230 -> V_225 . integer . V_225 [ 2 ] =
F_6 ( V_3 , V_283 , V_282 ) ;
F_32 ( & V_3 -> V_22 ) ;
return 0 ;
}
static int F_126 ( struct V_219 * V_220 ,
struct V_229 * V_230 )
{
struct V_3 * V_3 = F_70 ( V_220 ) ;
int V_248 ;
int V_282 ;
int V_283 ;
int V_152 ;
if ( ! F_12 ( V_3 ) )
return - V_123 ;
V_282 = V_230 -> V_225 . integer . V_225 [ 0 ] ;
V_283 = V_230 -> V_225 . integer . V_225 [ 1 ] ;
if ( V_282 < 0 || V_282 >= 2 * V_91 )
return - 1 ;
if ( V_283 < 0 || V_283 >= V_91 )
return - 1 ;
V_152 = V_230 -> V_225 . integer . V_225 [ 2 ] ;
F_30 ( & V_3 -> V_22 ) ;
if ( V_282 >= V_91 )
V_248 = V_152 != F_7 ( V_3 , V_283 ,
V_282 -
V_91 ) ;
else
V_248 = V_152 != F_6 ( V_3 , V_283 ,
V_282 ) ;
if ( V_248 ) {
if ( V_282 >= V_91 )
F_9 ( V_3 , V_283 ,
V_282 - V_91 ,
V_152 ) ;
else
F_8 ( V_3 , V_283 , V_282 ,
V_152 ) ;
}
F_32 ( & V_3 -> V_22 ) ;
return V_248 ;
}
static int F_127 ( struct V_219 * V_220 ,
struct V_221 * V_222 )
{
V_222 -> type = V_223 ;
V_222 -> V_224 = 1 ;
V_222 -> V_225 . integer . V_226 = 0 ;
V_222 -> V_225 . integer . V_227 = 64 ;
V_222 -> V_225 . integer . V_228 = 1 ;
return 0 ;
}
static int F_128 ( struct V_219 * V_220 ,
struct V_229 * V_230 )
{
struct V_3 * V_3 = F_70 ( V_220 ) ;
int V_284 ;
V_284 = V_230 -> V_154 . V_239 - 1 ;
if ( F_37 ( V_284 < 0 || V_284 >= V_91 ) )
return - V_120 ;
F_30 ( & V_3 -> V_22 ) ;
V_230 -> V_225 . integer . V_225 [ 0 ] =
( F_7 ( V_3 , V_284 , V_284 ) * 64 ) / V_153 ;
F_32 ( & V_3 -> V_22 ) ;
return 0 ;
}
static int F_129 ( struct V_219 * V_220 ,
struct V_229 * V_230 )
{
struct V_3 * V_3 = F_70 ( V_220 ) ;
int V_248 ;
int V_284 ;
int V_152 ;
if ( ! F_12 ( V_3 ) )
return - V_123 ;
V_284 = V_230 -> V_154 . V_239 - 1 ;
if ( F_37 ( V_284 < 0 || V_284 >= V_91 ) )
return - V_120 ;
V_152 = V_230 -> V_225 . integer . V_225 [ 0 ] * V_153 / 64 ;
F_30 ( & V_3 -> V_22 ) ;
V_248 =
V_152 != F_7 ( V_3 , V_284 ,
V_284 ) ;
if ( V_248 )
F_9 ( V_3 , V_284 , V_284 ,
V_152 ) ;
F_32 ( & V_3 -> V_22 ) ;
return V_248 ;
}
static int F_130 ( struct V_219 * V_220 ,
struct V_221 * V_222 )
{
static char * V_245 [] = { L_41 , L_42 , L_43 , L_44 } ;
F_77 ( V_222 , V_245 ) ;
return 0 ;
}
static int F_131 ( struct V_219 * V_220 ,
struct V_221 * V_222 )
{
static char * V_245 [] = { L_41 , L_42 } ;
F_77 ( V_222 , V_245 ) ;
return 0 ;
}
static int F_132 ( struct V_3 * V_3 )
{
int V_29 , V_30 ;
switch ( V_3 -> V_34 ) {
case V_35 :
V_29 = F_4 ( V_3 , V_37 ) ;
if ( V_29 & V_40 ) {
if ( V_29 & V_285 )
return 2 ;
else
return 1 ;
}
return 0 ;
break;
case V_49 :
V_30 = F_4 ( V_3 , V_36 ) ;
if ( V_30 & V_52 ) {
if ( V_30 & V_286 )
return 2 ;
else
return 1 ;
}
return 0 ;
break;
case V_51 :
case V_50 :
V_29 = F_4 ( V_3 , V_37 ) ;
if ( V_29 & 0x2000000 )
return 2 ;
else if ( V_29 & 0x1000000 )
return 1 ;
return 0 ;
break;
case V_45 :
break;
}
return 3 ;
}
static int F_133 ( struct V_3 * V_3 )
{
int V_29 = F_4 ( V_3 , V_37 ) ;
if ( V_29 & V_46 ) {
if ( V_29 & V_287 )
return 2 ;
else
return 1 ;
}
return 0 ;
}
static int F_134 ( struct V_3 * V_3 , int V_236 )
{
int V_29 , V_22 , V_288 ;
V_29 = F_4 ( V_3 , V_233 ) ;
V_22 = ( V_29 & ( 0x1 << V_236 ) ) ? 1 : 0 ;
V_288 = ( V_29 & ( 0x100 << V_236 ) ) ? 1 : 0 ;
if ( V_22 && V_288 )
return 2 ;
else if ( V_22 )
return 1 ;
return 0 ;
}
static int F_20 ( struct V_3 * V_3 )
{
int V_29 , V_22 = 0 , V_288 = 0 ;
switch ( V_3 -> V_34 ) {
case V_51 :
case V_50 :
V_29 = F_4 ( V_3 , V_289 ) ;
V_22 = ( V_29 & 0x400 ) ? 1 : 0 ;
V_288 = ( V_29 & 0x800 ) ? 1 : 0 ;
break;
case V_49 :
V_29 = F_4 ( V_3 , V_37 ) ;
V_22 = ( V_29 & V_290 ) ? 1 : 0 ;
V_288 = ( V_29 & V_291 ) ? 1 : 0 ;
break;
case V_35 :
V_29 = F_4 ( V_3 , V_36 ) ;
V_22 = ( V_29 & 0x100000 ) ? 1 : 0 ;
V_288 = ( V_29 & 0x200000 ) ? 1 : 0 ;
break;
case V_45 :
break;
}
if ( V_22 && V_288 )
return 2 ;
else if ( V_22 )
return 1 ;
return 0 ;
}
static int F_135 ( struct V_3 * V_3 , int V_236 )
{
int V_30 , V_22 , V_288 ;
V_30 = F_4 ( V_3 , V_36 ) ;
V_22 = ( V_30 & ( 0x0080 >> V_236 ) ) ? 1 : 0 ;
V_288 = ( V_30 & ( 0x8000 >> V_236 ) ) ? 1 : 0 ;
if ( V_288 )
return 2 ;
else if ( V_22 )
return 1 ;
return 0 ;
}
static int F_136 ( struct V_3 * V_3 , V_15 V_292 )
{
V_15 V_29 ;
V_29 = F_4 ( V_3 , V_269 + 4 ) ;
return ( V_29 & V_292 ) ? 1 : 0 ;
}
static int F_19 ( struct V_3 * V_3 )
{
int V_29 ;
if ( V_3 -> V_234 ) {
switch ( V_3 -> V_34 ) {
case V_49 :
case V_35 :
V_29 = F_4 ( V_3 , V_37 ) ;
if ( V_29 & V_293 ) {
if ( V_29 & V_294 )
return 2 ;
else
return 1 ;
}
return 0 ;
break;
case V_51 :
case V_50 :
V_29 = F_4 ( V_3 , V_233 ) ;
if ( V_29 & 0x8000000 )
return 2 ;
if ( V_29 & 0x4000000 )
return 1 ;
return 0 ;
break;
default:
break;
}
}
return 3 ;
}
static int F_137 ( struct V_219 * V_220 ,
struct V_229 * V_230 )
{
struct V_3 * V_3 = F_70 ( V_220 ) ;
int V_5 = - 1 ;
switch ( V_3 -> V_34 ) {
case V_51 :
switch ( V_220 -> V_238 ) {
case 0 :
V_5 = F_132 ( V_3 ) ; break;
case 7 :
V_5 = F_19 ( V_3 ) ; break;
case 8 :
V_5 = F_20 ( V_3 ) ; break;
default:
V_5 = F_134 ( V_3 ,
V_220 -> V_238 - 1 ) ;
}
break;
case V_50 :
switch ( V_220 -> V_238 ) {
case 0 :
V_5 = F_132 ( V_3 ) ; break;
case 4 :
V_5 = F_19 ( V_3 ) ; break;
case 5 :
V_5 = F_20 ( V_3 ) ; break;
default:
V_5 = F_134 ( V_3 , V_230 -> V_154 . V_239 - 1 ) ;
}
break;
case V_49 :
switch ( V_220 -> V_238 ) {
case 0 :
V_5 = F_132 ( V_3 ) ; break;
case 1 :
V_5 = F_133 ( V_3 ) ; break;
case 2 :
V_5 = F_19 ( V_3 ) ; break;
case 3 :
V_5 = F_20 ( V_3 ) ; break;
}
break;
case V_45 :
V_5 = F_133 ( V_3 ) ;
break;
case V_35 :
switch ( V_220 -> V_238 ) {
case 0 :
V_5 = F_132 ( V_3 ) ; break;
case 9 :
V_5 = F_19 ( V_3 ) ; break;
case 10 :
V_5 = F_20 ( V_3 ) ; break;
default:
V_5 = F_135 ( V_3 ,
V_220 -> V_238 - 1 ) ;
}
break;
}
if ( V_3 -> V_234 ) {
switch ( V_220 -> V_238 ) {
case 11 :
V_5 = F_136 ( V_3 , V_295 ) ;
break;
case 12 :
V_5 = F_136 ( V_3 ,
V_272 ) ;
break;
default:
break;
}
}
if ( - 1 == V_5 )
V_5 = 3 ;
V_230 -> V_225 . V_231 . V_232 [ 0 ] = V_5 ;
return 0 ;
}
static void F_138 ( struct V_3 * V_3 )
{
unsigned int V_296 [ 4 ] = { 0 , 0 , 0 , 0 } ;
switch ( V_3 -> V_234 -> V_166 ) {
case 0 :
V_296 [ 2 ] |= V_297 ;
break;
case 1 :
V_296 [ 2 ] |= V_298 ;
break;
default:
break;
}
switch ( V_3 -> V_234 -> V_299 ) {
case 1 :
V_296 [ 1 ] |= V_273 ;
break;
case 2 :
V_296 [ 1 ] |= V_274 ;
break;
case 3 :
V_296 [ 1 ] |= V_274 +
V_300 ;
break;
case 4 :
V_296 [ 1 ] |= V_273 +
V_274 ;
break;
case 5 :
V_296 [ 1 ] |= V_273 +
V_274 +
V_300 ;
break;
default:
break;
}
switch ( V_3 -> V_234 -> V_301 ) {
case 1 :
V_296 [ 2 ] |= V_302 ;
break;
case 2 :
V_296 [ 2 ] |= V_303 ;
break;
default:
break;
}
switch ( V_3 -> V_234 -> V_304 ) {
case 1 :
V_296 [ 2 ] |= V_305 ;
break;
case 2 :
V_296 [ 2 ] |= V_306 ;
break;
default:
break;
}
switch ( V_3 -> V_234 -> V_307 ) {
case 1 :
V_296 [ 2 ] |= V_308 ;
break;
case 2 :
V_296 [ 2 ] |= V_309 ;
break;
case 3 :
V_296 [ 2 ] |= V_308 + V_310 ;
break;
case 4 :
V_296 [ 2 ] |= V_309 + V_310 ;
break;
default:
break;
}
if ( 1 == V_3 -> V_234 -> V_311 ) {
V_296 [ 2 ] |= V_312 ;
}
F_2 ( V_3 , V_313 , V_296 [ 0 ] ) ;
F_2 ( V_3 , V_313 + 4 , V_296 [ 1 ] ) ;
F_2 ( V_3 , V_313 + 8 , V_296 [ 2 ] ) ;
F_2 ( V_3 , V_313 + 12 , V_296 [ 3 ] ) ;
}
static int F_139 ( struct V_219 * V_220 ,
struct V_221 * V_222 )
{
static char * V_245 [] = { L_45 , L_46 } ;
F_77 ( V_222 , V_245 ) ;
return 0 ;
}
static int F_140 ( struct V_219 * V_220 ,
struct V_229 * V_230 )
{
struct V_3 * V_3 = F_70 ( V_220 ) ;
V_230 -> V_225 . V_231 . V_232 [ 0 ] = V_3 -> V_234 -> V_304 ;
return 0 ;
}
static int F_141 ( struct V_219 * V_220 ,
struct V_229 * V_230 )
{
struct V_3 * V_3 = F_70 ( V_220 ) ;
if ( V_3 -> V_234 -> V_304 != V_230 -> V_225 . V_231 . V_232 [ 0 ] ) {
V_3 -> V_234 -> V_304 = V_230 -> V_225 . V_231 . V_232 [ 0 ] ;
F_138 ( V_3 ) ;
return 1 ;
}
return 0 ;
}
static int F_142 ( struct V_219 * V_220 ,
struct V_221 * V_222 )
{
static char * V_245 [] = { L_47 , L_48 , L_49 , L_50 , L_51 } ;
F_77 ( V_222 , V_245 ) ;
return 0 ;
}
static int F_143 ( struct V_219 * V_220 ,
struct V_229 * V_230 )
{
struct V_3 * V_3 = F_70 ( V_220 ) ;
V_230 -> V_225 . V_231 . V_232 [ 0 ] = V_3 -> V_234 -> V_307 ;
return 0 ;
}
static int F_144 ( struct V_219 * V_220 ,
struct V_229 * V_230 )
{
struct V_3 * V_3 = F_70 ( V_220 ) ;
if ( V_3 -> V_234 -> V_307 != V_230 -> V_225 . V_231 . V_232 [ 0 ] ) {
V_3 -> V_234 -> V_307 = V_230 -> V_225 . V_231 . V_232 [ 0 ] ;
F_138 ( V_3 ) ;
return 1 ;
}
return 0 ;
}
static int F_145 ( struct V_219 * V_220 ,
struct V_221 * V_222 )
{
static char * V_245 [] = { L_52 , L_53 , L_54 } ;
F_77 ( V_222 , V_245 ) ;
return 0 ;
}
static int F_146 ( struct V_219 * V_220 ,
struct V_229 * V_230 )
{
struct V_3 * V_3 = F_70 ( V_220 ) ;
V_230 -> V_225 . V_231 . V_232 [ 0 ] = V_3 -> V_234 -> V_301 ;
return 0 ;
}
static int F_147 ( struct V_219 * V_220 ,
struct V_229 * V_230 )
{
struct V_3 * V_3 = F_70 ( V_220 ) ;
if ( V_3 -> V_234 -> V_301 != V_230 -> V_225 . V_231 . V_232 [ 0 ] ) {
V_3 -> V_234 -> V_301 = V_230 -> V_225 . V_231 . V_232 [ 0 ] ;
F_138 ( V_3 ) ;
return 1 ;
}
return 0 ;
}
static int F_148 ( struct V_219 * V_220 ,
struct V_221 * V_222 )
{
static char * V_245 [] = { L_32 , L_33 , L_55 ,
L_56 , L_35 , L_57 } ;
F_77 ( V_222 , V_245 ) ;
return 0 ;
}
static int F_149 ( struct V_219 * V_220 ,
struct V_229 * V_230 )
{
struct V_3 * V_3 = F_70 ( V_220 ) ;
V_230 -> V_225 . V_231 . V_232 [ 0 ] = V_3 -> V_234 -> V_299 ;
return 0 ;
}
static int F_150 ( struct V_219 * V_220 ,
struct V_229 * V_230 )
{
struct V_3 * V_3 = F_70 ( V_220 ) ;
if ( V_3 -> V_234 -> V_299 != V_230 -> V_225 . V_231 . V_232 [ 0 ] ) {
V_3 -> V_234 -> V_299 = V_230 -> V_225 . V_231 . V_232 [ 0 ] ;
F_138 ( V_3 ) ;
return 1 ;
}
return 0 ;
}
static int F_151 ( struct V_219 * V_220 ,
struct V_221 * V_222 )
{
static char * V_245 [] = { L_58 , L_59 , L_60 } ;
F_77 ( V_222 , V_245 ) ;
return 0 ;
}
static int F_152 ( struct V_219 * V_220 ,
struct V_229 * V_230 )
{
struct V_3 * V_3 = F_70 ( V_220 ) ;
V_230 -> V_225 . V_231 . V_232 [ 0 ] = V_3 -> V_234 -> V_166 ;
return 0 ;
}
static int F_153 ( struct V_219 * V_220 ,
struct V_229 * V_230 )
{
struct V_3 * V_3 = F_70 ( V_220 ) ;
if ( V_3 -> V_234 -> V_166 != V_230 -> V_225 . V_231 . V_232 [ 0 ] ) {
V_3 -> V_234 -> V_166 = V_230 -> V_225 . V_231 . V_232 [ 0 ] ;
F_138 ( V_3 ) ;
return 1 ;
}
return 0 ;
}
static int F_154 ( struct V_219 * V_220 ,
struct V_221 * V_222 )
{
V_222 -> type = V_314 ;
V_222 -> V_224 = 1 ;
V_222 -> V_225 . integer . V_226 = 0 ;
V_222 -> V_225 . integer . V_227 = 1 ;
return 0 ;
}
static int F_155 ( struct V_219 * V_220 ,
struct V_229 * V_230 )
{
struct V_3 * V_3 = F_70 ( V_220 ) ;
V_230 -> V_225 . V_231 . V_232 [ 0 ] = V_3 -> V_234 -> V_311 ;
return 0 ;
}
static int F_156 ( struct V_219 * V_220 ,
struct V_229 * V_230 )
{
struct V_3 * V_3 = F_70 ( V_220 ) ;
if ( V_3 -> V_234 -> V_311 != V_230 -> V_225 . V_231 . V_232 [ 0 ] ) {
V_3 -> V_234 -> V_311 = V_230 -> V_225 . V_231 . V_232 [ 0 ] ;
F_138 ( V_3 ) ;
return 1 ;
}
return 0 ;
}
static int F_157 ( struct V_3 * V_3 )
{
int V_16 ;
for ( V_16 = V_3 -> V_141 ; V_16 < V_3 -> V_133 ; ++ V_16 ) {
if ( V_3 -> V_107 > 48000 ) {
V_3 -> V_315 [ V_16 ] -> V_316 [ 0 ] . V_317 =
V_318 |
V_319 |
V_320 ;
} else {
V_3 -> V_315 [ V_16 ] -> V_316 [ 0 ] . V_317 =
V_321 |
V_320 ;
}
F_158 ( V_3 -> V_180 , V_322 |
V_323 ,
& V_3 -> V_315 [ V_16 ] -> V_154 ) ;
}
return 0 ;
}
static int F_159 ( struct V_179 * V_180 ,
struct V_3 * V_3 )
{
unsigned int V_236 , V_324 ;
int V_181 ;
struct V_219 * V_325 ;
struct V_326 * V_327 = NULL ;
switch ( V_3 -> V_34 ) {
case V_49 :
V_327 = V_328 ;
V_324 = F_160 ( V_328 ) ;
break;
case V_45 :
V_327 = V_329 ;
V_324 = F_160 ( V_329 ) ;
break;
case V_50 :
V_327 = V_330 ;
V_324 = F_160 ( V_330 ) ;
break;
case V_51 :
V_327 = V_331 ;
V_324 = F_160 ( V_331 ) ;
break;
case V_35 :
V_327 = V_332 ;
V_324 = F_160 ( V_332 ) ;
break;
}
if ( NULL != V_327 ) {
for ( V_236 = 0 ; V_236 < V_324 ; V_236 ++ ) {
V_181 = F_161 ( V_180 ,
F_162 ( & V_327 [ V_236 ] , V_3 ) ) ;
if ( V_181 < 0 )
return V_181 ;
}
}
V_333 . V_207 = L_61 ;
if ( V_3 -> V_107 >= 128000 ) {
V_324 = V_3 -> V_147 ;
} else if ( V_3 -> V_107 >= 64000 ) {
V_324 = V_3 -> V_141 ;
} else {
V_324 = V_3 -> V_133 ;
}
for ( V_236 = 0 ; V_236 < V_324 ; ++ V_236 ) {
V_333 . V_239 = V_236 + 1 ;
V_325 = F_162 ( & V_333 , V_3 ) ;
V_181 = F_161 ( V_180 , V_325 ) ;
if ( V_181 < 0 )
return V_181 ;
V_3 -> V_315 [ V_236 ] = V_325 ;
}
if ( V_3 -> V_234 ) {
V_327 = V_334 ;
V_324 = F_160 ( V_334 ) ;
for ( V_236 = 0 ; V_236 < V_324 ; V_236 ++ ) {
V_181 = F_161 ( V_180 ,
F_162 ( & V_327 [ V_236 ] , V_3 ) ) ;
if ( V_181 < 0 )
return V_181 ;
}
}
return 0 ;
}
static void
F_163 ( struct V_335 * V_336 ,
struct V_337 * V_338 )
{
struct V_3 * V_3 = V_336 -> V_173 ;
unsigned int V_29 , V_30 , V_339 , V_340 ;
char * V_341 ;
char * V_342 ;
char * V_343 ;
char * V_344 ;
int V_345 , V_346 ;
int V_347 , V_348 , V_93 , V_349 , V_350 , V_351 ;
unsigned int V_95 ;
T_2 V_96 = 0 ;
V_15 V_25 ;
V_29 = F_4 ( V_3 , V_37 ) ;
V_30 = F_4 ( V_3 , V_36 ) ;
V_339 = V_3 -> V_26 ;
V_340 = F_4 ( V_3 , V_38 ) ;
F_164 ( V_338 , L_62 ,
V_3 -> V_352 , V_3 -> V_180 -> V_353 + 1 ,
V_3 -> V_354 ,
( V_30 & V_355 ) |
( V_30 & V_356 ) | ( V_30 &
V_357 ) ) ;
F_164 ( V_338 , L_63 ,
( F_4 ( V_3 , V_196 ) >> 8 ) & 0xFFFFFF ,
V_3 -> V_358 ) ;
F_164 ( V_338 , L_64 ,
V_3 -> V_187 , V_3 -> V_359 , ( unsigned long ) V_3 -> V_6 ) ;
F_164 ( V_338 , L_65 ) ;
F_164 ( V_338 ,
L_66 ,
V_29 & V_360 ,
( V_29 & V_194 ) ? 1 : 0 ,
( V_29 & V_200 ) ? 1 : 0 ,
V_3 -> V_361 ) ;
F_164 ( V_338 ,
L_67
L_68 ,
( ( V_29 & V_84 ) ? 1 : 0 ) ,
( V_29 & V_83 ) ,
( V_29 & V_83 ) %
( 2 * ( int ) V_3 -> V_81 ) ,
( ( V_29 & V_83 ) - 64 ) %
( 2 * ( int ) V_3 -> V_81 ) ,
( long ) F_25 ( V_3 ) * 4 ) ;
F_164 ( V_338 ,
L_69 ,
F_4 ( V_3 , V_192 ) & 0xFF ,
F_4 ( V_3 , V_198 ) & 0xFF ,
F_4 ( V_3 , V_190 ) & 0xFF ,
F_4 ( V_3 , V_196 ) & 0xFF ) ;
F_164 ( V_338 ,
L_70 ,
F_4 ( V_3 , V_183 ) & 0xFF ,
F_4 ( V_3 , V_185 ) & 0xFF ) ;
F_164 ( V_338 ,
L_71
L_72 ,
V_3 -> V_26 , V_3 -> V_362 ,
V_29 , V_30 ) ;
if ( V_29 & V_363 ) {
F_164 ( V_338 , L_73 ) ;
V_347 = F_4 ( V_3 , V_269 + 4 ) ;
if ( V_347 & V_272 ) {
F_164 ( V_338 , L_74 ) ;
switch ( V_347 & ( V_273 |
V_274 ) ) {
case 0 :
F_164 ( V_338 , L_75 ) ;
break;
case V_273 :
F_164 ( V_338 , L_76 ) ;
break;
case V_274 :
F_164 ( V_338 , L_77 ) ;
break;
default:
F_164 ( V_338 , L_78 ) ;
break;
}
if ( V_347 & V_300 ) {
F_164 ( V_338 , L_79 ) ;
} else {
F_164 ( V_338 , L_80 ) ;
}
} else {
F_164 ( V_338 , L_81 ) ;
}
if ( V_347 & V_270 ) {
F_164 ( V_338 , L_82 ) ;
} else if ( V_347 & V_271 ) {
F_164 ( V_338 , L_83 ) ;
} else {
F_164 ( V_338 , L_84 ) ;
}
if ( V_347 & V_295 ) {
F_164 ( V_338 , L_85 ) ;
} else {
F_164 ( V_338 , L_86 ) ;
}
switch ( V_3 -> V_34 ) {
case V_49 :
case V_35 :
V_96 = 110069313433624ULL ;
break;
case V_51 :
case V_50 :
V_96 = 104857600000000ULL ;
break;
case V_45 :
break;
}
V_95 = F_4 ( V_3 , V_218 ) ;
F_164 ( V_338 , L_87 , V_95 ) ;
V_25 = F_35 ( V_96 , V_95 ) ;
if ( V_339 & V_27 ) {
V_25 *= 4 ;
} else if ( V_339 & V_28 ) {
V_25 *= 2 ;
}
F_164 ( V_338 , L_88 ,
( unsigned int ) V_25 ) ;
V_348 = F_4 ( V_3 , V_269 ) ;
V_93 = V_348 & 0xF ;
V_348 >>= 4 ;
V_93 += ( V_348 & 0x3 ) * 10 ;
V_348 >>= 4 ;
V_349 = V_348 & 0xF ;
V_348 >>= 4 ;
V_349 += ( V_348 & 0x7 ) * 10 ;
V_348 >>= 4 ;
V_350 = V_348 & 0xF ;
V_348 >>= 4 ;
V_350 += ( V_348 & 0x7 ) * 10 ;
V_348 >>= 4 ;
V_351 = V_348 & 0xF ;
V_348 >>= 4 ;
V_351 += ( V_348 & 0x3 ) * 10 ;
F_164 ( V_338 ,
L_89 ,
V_351 , V_350 , V_349 , V_93 ) ;
} else {
F_164 ( V_338 , L_90 ) ;
}
F_164 ( V_338 , L_91 ) ;
V_345 = F_22 ( V_3 ) ;
F_164 ( V_338 ,
L_92 ,
V_345 , ( unsigned long ) V_3 -> V_81 ) ;
F_164 ( V_338 , L_93 ,
( V_3 -> V_26 & V_364 ) ? L_94 : L_95 ) ;
switch ( V_3 -> V_26 & V_365 ) {
case V_366 :
V_344 = L_96 ;
break;
case V_367 :
V_344 = L_97 ;
break;
default:
V_344 = L_98 ;
}
F_164 ( V_338 ,
L_99
L_100 ,
( V_3 -> V_26 & V_368 ) ? L_101 : L_95 ,
( V_3 -> V_26 & V_369 ) ? L_102 : L_103 ,
( V_3 -> V_26 & V_370 ) ? L_101 : L_95 ) ;
if ( ! ( V_3 -> V_26 & V_103 ) )
V_343 = L_13 ;
else
V_343 = L_12 ;
F_164 ( V_338 , L_104 , V_343 ) ;
switch ( F_88 ( V_3 ) ) {
case V_371 :
V_341 = L_24 ;
break;
case V_372 :
V_341 = L_105 ;
break;
case V_373 :
V_341 = L_26 ;
break;
case V_374 :
V_341 = L_27 ;
break;
default:
V_341 = L_106 ;
break;
}
F_164 ( V_338 , L_107 ,
V_341 ) ;
F_164 ( V_338 , L_108 ,
V_3 -> V_107 ) ;
F_164 ( V_338 , L_109 ) ;
V_345 = V_29 & V_287 ;
V_346 = V_30 & V_286 ;
F_164 ( V_338 , L_110 ,
( V_29 & V_46 ) ? ( V_345 ? L_43 : L_42 ) :
L_111 ,
( V_30 & V_52 ) ? ( V_346 ? L_43 : L_42 ) :
L_111 ) ;
switch ( F_18 ( V_3 ) ) {
case V_80 :
V_342 = L_27 ;
break;
case V_78 :
V_342 = L_26 ;
break;
case V_263 :
V_342 = L_24 ;
break;
case V_265 :
V_342 = L_105 ;
break;
case V_106 :
V_342 = L_112 ;
break;
default:
V_342 = L_113 ;
break;
}
F_164 ( V_338 ,
L_114 ,
V_342 , F_17 ( V_3 ) ,
( V_29 & V_66 ) >> 22 ,
( V_30 & V_54 ) >> 5 ) ;
F_164 ( V_338 , L_115 ,
( V_29 & V_375 ) ? L_116 : L_96 ,
( V_29 & V_376 ) ? L_117 :
L_118 ) ;
F_164 ( V_338 , L_119 ) ;
}
static void
F_165 ( struct V_335 * V_336 ,
struct V_337 * V_338 )
{
struct V_3 * V_3 = V_336 -> V_173 ;
unsigned int V_29 ;
unsigned int V_30 ;
unsigned int V_31 ;
unsigned int V_377 , V_378 ;
int V_379 ;
char * V_342 ;
int V_345 ;
V_29 = F_4 ( V_3 , V_37 ) ;
V_30 = F_4 ( V_3 , V_36 ) ;
V_31 = F_4 ( V_3 , V_38 ) ;
F_164 ( V_338 , L_120 ,
V_3 -> V_352 , V_3 -> V_180 -> V_353 + 1 ,
V_3 -> V_354 ) ;
F_164 ( V_338 , L_64 ,
V_3 -> V_187 , V_3 -> V_359 , ( unsigned long ) V_3 -> V_6 ) ;
F_164 ( V_338 , L_65 ) ;
F_164 ( V_338 ,
L_66 ,
V_29 & V_360 ,
( V_29 & V_194 ) ? 1 : 0 ,
( V_29 & V_200 ) ? 1 : 0 ,
V_3 -> V_361 ) ;
F_164 ( V_338 ,
L_67
L_68 ,
( ( V_29 & V_84 ) ? 1 : 0 ) ,
( V_29 & V_83 ) ,
( V_29 & V_83 ) %
( 2 * ( int ) V_3 -> V_81 ) ,
( ( V_29 & V_83 ) - 64 ) %
( 2 * ( int ) V_3 -> V_81 ) ,
( long ) F_25 ( V_3 ) * 4 ) ;
F_164 ( V_338 ,
L_69 ,
F_4 ( V_3 , V_192 ) & 0xFF ,
F_4 ( V_3 , V_198 ) & 0xFF ,
F_4 ( V_3 , V_190 ) & 0xFF ,
F_4 ( V_3 , V_196 ) & 0xFF ) ;
F_164 ( V_338 ,
L_70 ,
F_4 ( V_3 , V_183 ) & 0xFF ,
F_4 ( V_3 , V_185 ) & 0xFF ) ;
F_164 ( V_338 ,
L_71
L_72 ,
V_3 -> V_26 , V_3 -> V_362 ,
V_29 , V_30 ) ;
F_164 ( V_338 , L_91 ) ;
V_345 = F_22 ( V_3 ) ;
F_164 ( V_338 ,
L_92 ,
V_345 , ( unsigned long ) V_3 -> V_81 ) ;
F_164 ( V_338 , L_93 ,
( V_3 ->
V_26 & V_364 ) ? L_94 : L_95 ) ;
F_164 ( V_338 ,
L_121 ,
( V_3 ->
V_26 & V_368 ) ? L_101 : L_95 ,
( V_3 ->
V_26 & V_380 ) ? L_101 : L_95 ,
( V_3 ->
V_26 & V_381 ) ? L_101 : L_95 ) ;
V_379 = F_88 ( V_3 ) ;
if ( V_379 == 0 )
F_164 ( V_338 , L_122 ) ;
else
F_164 ( V_338 , L_123 ,
V_379 ) ;
F_164 ( V_338 , L_108 ,
V_3 -> V_107 ) ;
F_164 ( V_338 , L_124 ,
V_3 -> V_26 & V_278 ?
L_125 : L_126 ) ;
F_164 ( V_338 , L_127 ,
V_3 -> V_26 & V_280 ?
L_125 :
V_3 -> V_26 & V_281 ?
L_128 : L_126 ) ;
F_164 ( V_338 , L_109 ) ;
V_377 = V_29 & V_40 ;
V_378 = V_377 && ( V_29 & V_285 ) ;
F_164 ( V_338 , L_129 ,
( V_377 ) ? ( V_378 ? L_130 : L_131 ) : L_41 ,
F_1 ( ( V_29 >> V_41 ) & 0xF ) ) ;
for ( V_345 = 0 ; V_345 < 8 ; V_345 ++ ) {
F_164 ( V_338 , L_132 ,
V_345 + 1 ,
( V_30 & ( V_44 >> V_345 ) ) ?
L_130 : L_41 ,
F_1 ( ( V_31 >> ( 4 * V_345 ) ) & 0xF ) ) ;
}
switch ( F_18 ( V_3 ) ) {
case V_262 :
V_342 = L_23 ; break;
case V_39 :
V_342 = L_24 ; break;
case V_42 :
V_342 = L_15 ; break;
case V_382 :
V_342 = L_16 ; break;
case V_383 :
V_342 = L_17 ; break;
case V_384 :
V_342 = L_18 ; break;
case V_385 :
V_342 = L_19 ; break;
case V_386 :
V_342 = L_20 ; break;
case V_387 :
V_342 = L_21 ; break;
case V_43 :
V_342 = L_22 ; break;
default:
V_342 = L_113 ; break;
}
F_164 ( V_338 , L_133 , V_342 ) ;
F_164 ( V_338 , L_119 ) ;
}
static void
F_166 ( struct V_335 * V_336 ,
struct V_337 * V_338 )
{
struct V_3 * V_3 = V_336 -> V_173 ;
unsigned int V_388 , V_30 , V_389 , V_339 , V_16 ;
unsigned int V_22 , V_288 ;
V_388 = F_4 ( V_3 , V_233 ) ;
V_30 = F_4 ( V_3 , V_235 ) ;
V_389 = F_4 ( V_3 , V_289 ) ;
V_339 = V_3 -> V_26 ;
F_164 ( V_338 , L_134 , V_388 ) ;
F_164 ( V_338 , L_135 , V_30 ) ;
F_164 ( V_338 , L_136 , V_389 ) ;
F_164 ( V_338 , L_137 ) ;
F_164 ( V_338 , L_138 ,
( F_67 ( V_3 ) == 0 ) ? L_139 : L_140 ) ;
F_164 ( V_338 , L_141 ,
F_66 ( V_3 ) ) ;
F_164 ( V_338 , L_142 ) ;
V_22 = 0x1 ;
V_288 = 0x100 ;
for ( V_16 = 0 ; V_16 < 8 ; V_16 ++ ) {
F_164 ( V_338 , L_143 ,
V_16 ,
( V_388 & V_22 ) ? 1 : 0 ,
( V_388 & V_288 ) ? 1 : 0 ,
V_237 [ ( V_30 >> ( V_16 * 4 ) ) & 0xF ] ) ;
V_22 = V_22 << 1 ;
V_288 = V_288 << 1 ;
}
F_164 ( V_338 , L_144 ,
( V_388 & 0x1000000 ) ? 1 : 0 ,
( V_388 & 0x2000000 ) ? 1 : 0 ,
V_237 [ ( V_388 >> 16 ) & 0xF ] ) ;
F_164 ( V_338 , L_145 ,
( V_388 & 0x4000000 ) ? 1 : 0 ,
( V_388 & 0x8000000 ) ? 1 : 0 ,
V_237 [ ( V_388 >> 20 ) & 0xF ] ) ;
F_164 ( V_338 , L_146 ,
( V_389 & 0x400 ) ? 1 : 0 ,
( V_389 & 0x800 ) ? 1 : 0 ,
V_237 [ ( V_30 >> 12 ) & 0xF ] ) ;
}
static void
F_167 ( struct V_335 * V_336 ,
struct V_337 * V_338 )
{
struct V_3 * V_3 = V_336 -> V_173 ;
int V_151 , V_16 ;
for ( V_16 = 0 ; V_16 < 256 ; V_16 += V_151 ) {
F_164 ( V_338 , L_147 , V_16 ) ;
for ( V_151 = 0 ; V_151 < 16 ; V_151 += 4 )
F_164 ( V_338 , L_148 , F_4 ( V_3 , V_16 + V_151 ) ) ;
F_164 ( V_338 , L_119 ) ;
}
}
static void F_168 ( struct V_335 * V_336 ,
struct V_337 * V_338 )
{
struct V_3 * V_3 = V_336 -> V_173 ;
int V_16 ;
F_164 ( V_338 , L_149 ) ;
for ( V_16 = 0 ; V_16 < V_3 -> V_130 ; V_16 ++ ) {
F_164 ( V_338 , L_150 , V_16 + 1 , V_3 -> V_134 [ V_16 ] ) ;
}
}
static void F_169 ( struct V_335 * V_336 ,
struct V_337 * V_338 )
{
struct V_3 * V_3 = V_336 -> V_173 ;
int V_16 ;
F_164 ( V_338 , L_149 ) ;
for ( V_16 = 0 ; V_16 < V_3 -> V_132 ; V_16 ++ ) {
F_164 ( V_338 , L_150 , V_16 + 1 , V_3 -> V_136 [ V_16 ] ) ;
}
}
static void F_170 ( struct V_3 * V_3 )
{
struct V_335 * V_336 ;
if ( ! F_171 ( V_3 -> V_180 , L_151 , & V_336 ) ) {
switch ( V_3 -> V_34 ) {
case V_35 :
F_172 ( V_336 , V_3 ,
F_165 ) ;
break;
case V_49 :
F_172 ( V_336 , V_3 ,
F_163 ) ;
break;
case V_45 :
break;
case V_51 :
F_172 ( V_336 , V_3 ,
F_166 ) ;
break;
case V_50 :
break;
}
}
if ( ! F_171 ( V_3 -> V_180 , L_152 , & V_336 ) ) {
F_172 ( V_336 , V_3 , F_168 ) ;
}
if ( ! F_171 ( V_3 -> V_180 , L_153 , & V_336 ) ) {
F_172 ( V_336 , V_3 , F_169 ) ;
}
#ifdef F_173
if ( ! F_171 ( V_3 -> V_180 , L_154 , & V_336 ) )
F_172 ( V_336 , V_3 ,
F_167 ) ;
#endif
}
static int F_174 ( struct V_3 * V_3 )
{
V_3 -> V_241 = 0 ;
switch ( V_3 -> V_34 ) {
case V_49 :
case V_45 :
V_3 -> V_26 =
0x2 + 0x8 + 0x10 + 0x80 + 0x400 + 0x4000 + 0x1000000 ;
break;
case V_51 :
case V_50 :
V_3 -> V_241 = 0x1 + 0x1000 ;
V_3 -> V_26 =
0x2 + 0x8 + 0x10 + 0x80 + 0x400 + 0x4000 + 0x1000000 ;
break;
case V_35 :
V_3 -> V_26 =
V_103 |
F_31 ( 7 ) |
V_250 |
V_364 |
V_390 ;
break;
}
F_2 ( V_3 , V_88 , V_3 -> V_26 ) ;
if ( V_35 == V_3 -> V_34 ) {
#ifdef F_175
V_3 -> V_362 = V_391 ;
#else
V_3 -> V_362 = 0 ;
#endif
F_2 ( V_3 , V_392 , V_3 -> V_362 ) ;
}
F_24 ( V_3 ) ;
F_40 ( V_3 , 0 * V_153 ) ;
if ( V_3 -> V_34 == V_50 || V_3 -> V_34 == V_51 ) {
F_2 ( V_3 , V_244 , V_3 -> V_241 ) ;
}
F_38 ( V_3 , 48000 , 1 ) ;
return 0 ;
}
static T_3 F_176 ( int V_187 , void * V_393 )
{
struct V_3 * V_3 = (struct V_3 * ) V_393 ;
unsigned int V_29 ;
int V_16 , V_394 , V_155 , V_395 = 0 ;
V_29 = F_4 ( V_3 , V_37 ) ;
V_394 = V_29 & V_360 ;
V_155 = V_29 & ( V_194 | V_200 |
V_188 | V_205 ) ;
if ( ! V_394 && ! V_155 )
return V_396 ;
F_2 ( V_3 , V_397 , 0 ) ;
V_3 -> V_361 ++ ;
if ( V_394 ) {
if ( V_3 -> V_398 )
F_177 ( V_3 -> V_398 ) ;
if ( V_3 -> V_399 )
F_177 ( V_3 -> V_399 ) ;
}
if ( V_155 ) {
V_16 = 0 ;
while ( V_16 < V_3 -> V_217 ) {
if ( ( F_4 ( V_3 ,
V_3 -> V_155 [ V_16 ] . V_158 ) & 0xff ) &&
( V_29 & V_3 -> V_155 [ V_16 ] . V_187 ) ) {
V_3 -> V_26 &= ~ V_3 -> V_155 [ V_16 ] . V_168 ;
F_2 ( V_3 , V_88 ,
V_3 -> V_26 ) ;
V_3 -> V_155 [ V_16 ] . V_167 = 1 ;
V_395 = 1 ;
}
V_16 ++ ;
}
if ( V_395 )
F_178 ( & V_3 -> V_400 ) ;
}
return V_401 ;
}
static T_1 F_179 ( struct V_402
* V_170 )
{
struct V_3 * V_3 = F_180 ( V_170 ) ;
return F_25 ( V_3 ) ;
}
static int F_181 ( struct V_402 * V_170 )
{
struct V_403 * V_404 = V_170 -> V_404 ;
struct V_3 * V_3 = F_180 ( V_170 ) ;
struct V_402 * V_405 ;
if ( V_170 -> V_406 == V_407 )
V_405 = V_3 -> V_398 ;
else
V_405 = V_3 -> V_399 ;
if ( V_3 -> V_408 )
V_404 -> V_29 -> V_409 = F_25 ( V_3 ) ;
else
V_404 -> V_29 -> V_409 = 0 ;
if ( V_405 ) {
struct V_402 * V_85 ;
struct V_403 * V_410 = V_405 -> V_404 ;
F_182 (s, substream) {
if ( V_85 == V_405 ) {
V_410 -> V_29 -> V_409 =
V_404 -> V_29 -> V_409 ;
break;
}
}
}
return 0 ;
}
static int F_183 ( struct V_402 * V_170 ,
struct V_411 * V_412 )
{
struct V_3 * V_3 = F_180 ( V_170 ) ;
int V_181 ;
int V_16 ;
T_4 V_413 ;
T_4 V_414 ;
F_30 ( & V_3 -> V_22 ) ;
if ( V_170 -> V_415 -> V_406 == V_407 ) {
V_413 = V_3 -> V_23 ;
V_414 = V_3 -> V_24 ;
} else {
V_413 = V_3 -> V_24 ;
V_414 = V_3 -> V_23 ;
}
if ( V_414 > 0 && V_413 != V_414 ) {
if ( F_184 ( V_412 ) != V_3 -> V_107 ) {
F_32 ( & V_3 -> V_22 ) ;
F_185 ( V_412 ,
V_416 ) ;
return - V_123 ;
}
if ( F_186 ( V_412 ) != V_3 -> V_81 / 4 ) {
F_32 ( & V_3 -> V_22 ) ;
F_185 ( V_412 ,
V_417 ) ;
return - V_123 ;
}
}
F_32 ( & V_3 -> V_22 ) ;
F_30 ( & V_3 -> V_22 ) ;
V_181 = F_38 ( V_3 , F_184 ( V_412 ) , 0 ) ;
if ( V_181 < 0 ) {
F_39 ( V_418 L_155 , V_181 ) ;
F_32 ( & V_3 -> V_22 ) ;
F_185 ( V_412 ,
V_416 ) ;
return V_181 ;
}
F_32 ( & V_3 -> V_22 ) ;
V_181 = F_29 ( V_3 ,
F_186 ( V_412 ) ) ;
if ( V_181 < 0 ) {
F_39 ( V_418 L_156 , V_181 ) ;
F_185 ( V_412 ,
V_417 ) ;
return V_181 ;
}
V_181 =
F_187 ( V_170 , V_419 ) ;
if ( V_181 < 0 ) {
F_39 ( V_418 L_157 , V_181 ) ;
return V_181 ;
}
if ( V_170 -> V_406 == V_407 ) {
F_188 ( V_3 , V_170 , V_420 ,
F_189 ( V_412 ) ) ;
for ( V_16 = 0 ; V_16 < F_189 ( V_412 ) ; ++ V_16 )
F_11 ( V_3 , V_16 , 1 ) ;
V_3 -> V_90 =
( unsigned char * ) V_170 -> V_404 -> V_421 ;
F_190 ( L_158 ,
V_3 -> V_90 ) ;
} else {
F_188 ( V_3 , V_170 , V_422 ,
F_189 ( V_412 ) ) ;
for ( V_16 = 0 ; V_16 < F_189 ( V_412 ) ; ++ V_16 )
F_10 ( V_3 , V_16 , 1 ) ;
V_3 -> V_423 =
( unsigned char * ) V_170 -> V_404 -> V_421 ;
F_190 ( L_159 ,
V_3 -> V_423 ) ;
}
if ( V_424 == F_191 ( V_412 ) ) {
if ( ! ( V_3 -> V_26 & V_425 ) )
F_39 ( V_418 L_160 ) ;
V_3 -> V_26 |= V_425 ;
} else if ( V_426 == F_191 ( V_412 ) ) {
if ( V_3 -> V_26 & V_425 )
F_39 ( V_418 L_161 ) ;
V_3 -> V_26 &= ~ V_425 ;
}
F_2 ( V_3 , V_88 , V_3 -> V_26 ) ;
return 0 ;
}
static int F_192 ( struct V_402 * V_170 )
{
int V_16 ;
struct V_3 * V_3 = F_180 ( V_170 ) ;
if ( V_170 -> V_406 == V_407 ) {
for ( V_16 = 0 ; V_16 < V_3 -> V_132 ; ++ V_16 )
F_11 ( V_3 , V_16 , 0 ) ;
V_3 -> V_90 = NULL ;
} else {
for ( V_16 = 0 ; V_16 < V_3 -> V_130 ; ++ V_16 )
F_10 ( V_3 , V_16 , 0 ) ;
V_3 -> V_423 = NULL ;
}
F_193 ( V_170 ) ;
return 0 ;
}
static int F_194 ( struct V_402 * V_170 ,
struct V_427 * V_428 )
{
struct V_3 * V_3 = F_180 ( V_170 ) ;
if ( V_170 -> V_406 == V_407 ) {
if ( F_37 ( V_428 -> V_284 >= V_3 -> V_132 ) ) {
F_39 ( V_418 L_162 , V_428 -> V_284 ) ;
return - V_120 ;
}
if ( V_3 -> V_128 [ V_428 -> V_284 ] < 0 ) {
F_39 ( V_418 L_163 , V_428 -> V_284 ) ;
return - V_120 ;
}
V_428 -> V_429 = V_3 -> V_128 [ V_428 -> V_284 ] *
V_92 ;
} else {
if ( F_37 ( V_428 -> V_284 >= V_3 -> V_130 ) ) {
F_39 ( V_418 L_164 , V_428 -> V_284 ) ;
return - V_120 ;
}
if ( V_3 -> V_126 [ V_428 -> V_284 ] < 0 ) {
F_39 ( V_418 L_165 , V_428 -> V_284 ) ;
return - V_120 ;
}
V_428 -> V_429 = V_3 -> V_126 [ V_428 -> V_284 ] *
V_92 ;
}
V_428 -> V_430 = 0 ;
V_428 -> V_228 = 32 ;
return 0 ;
}
static int F_195 ( struct V_402 * V_170 ,
unsigned int V_431 , void * V_216 )
{
switch ( V_431 ) {
case V_432 :
return F_181 ( V_170 ) ;
case V_433 :
{
struct V_427 * V_428 = V_216 ;
return F_194 ( V_170 , V_428 ) ;
}
default:
break;
}
return F_196 ( V_170 , V_431 , V_216 ) ;
}
static int F_197 ( struct V_402 * V_170 , int V_431 )
{
struct V_3 * V_3 = F_180 ( V_170 ) ;
struct V_402 * V_405 ;
int V_408 ;
F_198 ( & V_3 -> V_22 ) ;
V_408 = V_3 -> V_408 ;
switch ( V_431 ) {
case V_434 :
V_408 |= 1 << V_170 -> V_406 ;
break;
case V_435 :
V_408 &= ~ ( 1 << V_170 -> V_406 ) ;
break;
default:
F_34 () ;
F_199 ( & V_3 -> V_22 ) ;
return - V_120 ;
}
if ( V_170 -> V_406 == V_407 )
V_405 = V_3 -> V_398 ;
else
V_405 = V_3 -> V_399 ;
if ( V_405 ) {
struct V_402 * V_85 ;
F_182 (s, substream) {
if ( V_85 == V_405 ) {
F_200 ( V_85 , V_170 ) ;
if ( V_431 == V_434 )
V_408 |= 1 << V_85 -> V_406 ;
else
V_408 &= ~ ( 1 << V_85 -> V_406 ) ;
goto V_436;
}
}
if ( V_431 == V_434 ) {
if ( ! ( V_408 & ( 1 << V_407 ) )
&& V_170 -> V_406 ==
V_437 )
F_28 ( V_3 ) ;
} else {
if ( V_408 &&
V_170 -> V_406 == V_407 )
F_28 ( V_3 ) ;
}
} else {
if ( V_170 -> V_406 == V_437 )
F_28 ( V_3 ) ;
}
V_436:
F_200 ( V_170 , V_170 ) ;
if ( ! V_3 -> V_408 && V_408 )
F_26 ( V_3 ) ;
else if ( V_3 -> V_408 && ! V_408 )
F_27 ( V_3 ) ;
V_3 -> V_408 = V_408 ;
F_199 ( & V_3 -> V_22 ) ;
return 0 ;
}
static int F_201 ( struct V_402 * V_170 )
{
return 0 ;
}
static int F_202 ( struct V_411 * V_412 ,
struct V_438 * V_439 )
{
struct V_3 * V_3 = V_439 -> V_440 ;
struct V_441 * V_442 =
F_203 ( V_412 , V_443 ) ;
struct V_441 * V_444 =
F_203 ( V_412 , V_416 ) ;
if ( V_444 -> V_226 > 96000 && V_444 -> V_227 <= 192000 ) {
struct V_441 V_445 = {
. V_226 = V_3 -> V_146 ,
. V_227 = V_3 -> V_146 ,
. integer = 1 ,
} ;
return F_204 ( V_442 , & V_445 ) ;
} else if ( V_444 -> V_226 > 48000 && V_444 -> V_227 <= 96000 ) {
struct V_441 V_445 = {
. V_226 = V_3 -> V_140 ,
. V_227 = V_3 -> V_140 ,
. integer = 1 ,
} ;
return F_204 ( V_442 , & V_445 ) ;
} else if ( V_444 -> V_227 < 64000 ) {
struct V_441 V_445 = {
. V_226 = V_3 -> V_131 ,
. V_227 = V_3 -> V_131 ,
. integer = 1 ,
} ;
return F_204 ( V_442 , & V_445 ) ;
}
return 0 ;
}
static int F_205 ( struct V_411 * V_412 ,
struct V_438 * V_439 )
{
struct V_3 * V_3 = V_439 -> V_440 ;
struct V_441 * V_442 =
F_203 ( V_412 , V_443 ) ;
struct V_441 * V_444 =
F_203 ( V_412 , V_416 ) ;
if ( V_444 -> V_226 > 96000 && V_444 -> V_227 <= 192000 ) {
struct V_441 V_445 = {
. V_226 = V_3 -> V_147 ,
. V_227 = V_3 -> V_147 ,
. integer = 1 ,
} ;
return F_204 ( V_442 , & V_445 ) ;
} else if ( V_444 -> V_226 > 48000 && V_444 -> V_227 <= 96000 ) {
struct V_441 V_445 = {
. V_226 = V_3 -> V_141 ,
. V_227 = V_3 -> V_141 ,
. integer = 1 ,
} ;
return F_204 ( V_442 , & V_445 ) ;
} else if ( V_444 -> V_227 < 64000 ) {
struct V_441 V_445 = {
. V_226 = V_3 -> V_133 ,
. V_227 = V_3 -> V_133 ,
. integer = 1 ,
} ;
return F_204 ( V_442 , & V_445 ) ;
} else {
}
return 0 ;
}
static int F_206 ( struct V_411 * V_412 ,
struct V_438 * V_439 )
{
struct V_3 * V_3 = V_439 -> V_440 ;
struct V_441 * V_442 =
F_203 ( V_412 , V_443 ) ;
struct V_441 * V_444 =
F_203 ( V_412 , V_416 ) ;
if ( V_442 -> V_226 >= V_3 -> V_131 ) {
struct V_441 V_445 = {
. V_226 = 32000 ,
. V_227 = 48000 ,
. integer = 1 ,
} ;
return F_204 ( V_444 , & V_445 ) ;
} else if ( V_442 -> V_227 <= V_3 -> V_146 ) {
struct V_441 V_445 = {
. V_226 = 128000 ,
. V_227 = 192000 ,
. integer = 1 ,
} ;
return F_204 ( V_444 , & V_445 ) ;
} else if ( V_442 -> V_227 <= V_3 -> V_140 ) {
struct V_441 V_445 = {
. V_226 = 64000 ,
. V_227 = 96000 ,
. integer = 1 ,
} ;
return F_204 ( V_444 , & V_445 ) ;
}
return 0 ;
}
static int F_207 ( struct V_411 * V_412 ,
struct V_438 * V_439 )
{
struct V_3 * V_3 = V_439 -> V_440 ;
struct V_441 * V_442 =
F_203 ( V_412 , V_443 ) ;
struct V_441 * V_444 =
F_203 ( V_412 , V_416 ) ;
if ( V_442 -> V_226 >= V_3 -> V_133 ) {
struct V_441 V_445 = {
. V_226 = 32000 ,
. V_227 = 48000 ,
. integer = 1 ,
} ;
return F_204 ( V_444 , & V_445 ) ;
} else if ( V_442 -> V_227 <= V_3 -> V_147 ) {
struct V_441 V_445 = {
. V_226 = 128000 ,
. V_227 = 192000 ,
. integer = 1 ,
} ;
return F_204 ( V_444 , & V_445 ) ;
} else if ( V_442 -> V_227 <= V_3 -> V_141 ) {
struct V_441 V_445 = {
. V_226 = 64000 ,
. V_227 = 96000 ,
. integer = 1 ,
} ;
return F_204 ( V_444 , & V_445 ) ;
}
return 0 ;
}
static int F_208 ( struct V_411 * V_412 ,
struct V_438 * V_439 )
{
unsigned int V_327 [ 3 ] ;
struct V_3 * V_3 = V_439 -> V_440 ;
struct V_441 * V_442 = F_203 ( V_412 ,
V_443 ) ;
V_327 [ 0 ] = V_3 -> V_146 ;
V_327 [ 1 ] = V_3 -> V_140 ;
V_327 [ 2 ] = V_3 -> V_131 ;
return F_209 ( V_442 , 3 , V_327 , 0 ) ;
}
static int F_210 ( struct V_411 * V_412 ,
struct V_438 * V_439 )
{
unsigned int V_327 [ 3 ] ;
struct V_3 * V_3 = V_439 -> V_440 ;
struct V_441 * V_442 = F_203 ( V_412 ,
V_443 ) ;
V_327 [ 0 ] = V_3 -> V_147 ;
V_327 [ 1 ] = V_3 -> V_141 ;
V_327 [ 2 ] = V_3 -> V_133 ;
return F_209 ( V_442 , 3 , V_327 , 0 ) ;
}
static int F_211 ( struct V_402 * V_170 )
{
struct V_3 * V_3 = F_180 ( V_170 ) ;
struct V_403 * V_404 = V_170 -> V_404 ;
F_30 ( & V_3 -> V_22 ) ;
F_212 ( V_170 ) ;
V_404 -> V_446 = V_447 ;
if ( V_3 -> V_398 == NULL )
F_27 ( V_3 ) ;
V_3 -> V_23 = V_448 -> V_449 ;
V_3 -> V_399 = V_170 ;
F_32 ( & V_3 -> V_22 ) ;
F_213 ( V_404 , 0 , 32 , 24 ) ;
F_214 ( V_404 , 0 , V_417 ) ;
switch ( V_3 -> V_34 ) {
case V_50 :
case V_51 :
F_215 ( V_404 ,
V_417 ,
32 , 4096 ) ;
F_215 ( V_404 ,
V_450 ,
16384 , 16384 ) ;
break;
default:
F_215 ( V_404 ,
V_417 ,
64 , 8192 ) ;
break;
}
if ( V_35 == V_3 -> V_34 ) {
V_404 -> V_446 . V_451 |= V_452 ;
F_216 ( V_404 , 0 , V_416 ,
& V_453 ) ;
} else {
F_217 ( V_404 , 0 , V_416 ,
F_207 , V_3 ,
V_443 , - 1 ) ;
}
F_217 ( V_404 , 0 , V_443 ,
F_210 , V_3 ,
V_443 , - 1 ) ;
F_217 ( V_404 , 0 , V_443 ,
F_205 , V_3 ,
V_416 , - 1 ) ;
return 0 ;
}
static int F_218 ( struct V_402 * V_170 )
{
struct V_3 * V_3 = F_180 ( V_170 ) ;
F_30 ( & V_3 -> V_22 ) ;
V_3 -> V_23 = - 1 ;
V_3 -> V_399 = NULL ;
F_32 ( & V_3 -> V_22 ) ;
return 0 ;
}
static int F_219 ( struct V_402 * V_170 )
{
struct V_3 * V_3 = F_180 ( V_170 ) ;
struct V_403 * V_404 = V_170 -> V_404 ;
F_30 ( & V_3 -> V_22 ) ;
F_212 ( V_170 ) ;
V_404 -> V_446 = V_454 ;
if ( V_3 -> V_399 == NULL )
F_27 ( V_3 ) ;
V_3 -> V_24 = V_448 -> V_449 ;
V_3 -> V_398 = V_170 ;
F_32 ( & V_3 -> V_22 ) ;
F_213 ( V_404 , 0 , 32 , 24 ) ;
F_214 ( V_404 , 0 , V_417 ) ;
switch ( V_3 -> V_34 ) {
case V_50 :
case V_51 :
F_215 ( V_404 ,
V_417 ,
32 , 4096 ) ;
F_215 ( V_404 ,
V_450 ,
16384 , 16384 ) ;
break;
default:
F_215 ( V_404 ,
V_417 ,
64 , 8192 ) ;
break;
}
if ( V_35 == V_3 -> V_34 ) {
V_404 -> V_446 . V_451 |= V_452 ;
F_216 ( V_404 , 0 , V_416 ,
& V_453 ) ;
} else {
F_217 ( V_404 , 0 , V_416 ,
F_206 , V_3 ,
V_443 , - 1 ) ;
}
F_217 ( V_404 , 0 , V_443 ,
F_208 , V_3 ,
V_443 , - 1 ) ;
F_217 ( V_404 , 0 , V_443 ,
F_202 , V_3 ,
V_416 , - 1 ) ;
return 0 ;
}
static int F_220 ( struct V_402 * V_170 )
{
struct V_3 * V_3 = F_180 ( V_170 ) ;
F_30 ( & V_3 -> V_22 ) ;
V_3 -> V_24 = - 1 ;
V_3 -> V_398 = NULL ;
F_32 ( & V_3 -> V_22 ) ;
return 0 ;
}
static int F_221 ( struct V_455 * V_446 , struct V_456 * V_456 )
{
return 0 ;
}
static inline int F_222 ( void T_5 * V_457 , void T_6 * V_458 )
{
V_15 V_5 = F_5 ( V_458 ) ;
return F_223 ( V_457 , & V_5 , 4 ) ;
}
static int F_224 ( struct V_455 * V_446 , struct V_456 * V_456 ,
unsigned int V_431 , unsigned long V_216 )
{
void T_5 * V_459 = ( void T_5 * ) V_216 ;
struct V_3 * V_3 = V_446 -> V_173 ;
struct V_460 V_10 ;
struct V_461 V_428 ;
struct V_462 V_29 ;
struct V_463 V_463 ;
struct V_464 * V_465 ;
struct V_466 V_348 ;
unsigned int V_467 ;
long unsigned int V_85 ;
int V_16 = 0 ;
switch ( V_431 ) {
case V_468 :
V_465 = & V_3 -> V_469 ;
for ( V_16 = 0 ; V_16 < V_91 ; V_16 ++ ) {
V_465 -> V_470 [ V_16 ] =
F_5 ( V_3 -> V_6 +
V_471 + V_16 * 4 ) ;
V_465 -> V_472 [ V_16 ] =
F_5 ( V_3 -> V_6 +
V_473 + V_16 * 4 ) ;
V_465 -> V_474 [ V_16 ] =
F_5 ( V_3 -> V_6 +
V_475 + V_16 * 4 ) ;
V_465 -> V_476 [ V_16 ] =
( ( V_477 ) F_5 ( V_3 -> V_6 +
V_478 + V_16 * 4 ) << 32 ) |
( V_477 ) F_5 ( V_3 -> V_6 +
V_479 + V_16 * 4 ) ;
V_465 -> V_480 [ V_16 ] =
( ( V_477 ) F_5 ( V_3 -> V_6 +
V_481 + V_16 * 4 ) << 32 ) |
( V_477 ) F_5 ( V_3 -> V_6 +
V_482 + V_16 * 4 ) ;
V_465 -> V_483 [ V_16 ] =
( ( V_477 ) F_5 ( V_3 -> V_6 +
V_484 + V_16 * 4 ) << 32 ) |
( V_477 ) F_5 ( V_3 -> V_6 +
V_485 + V_16 * 4 ) ;
}
if ( V_3 -> V_107 > 96000 ) {
V_465 -> V_486 = V_487 ;
} else if ( V_3 -> V_107 > 48000 ) {
V_465 -> V_486 = V_279 ;
} else {
V_465 -> V_486 = V_488 ;
}
V_465 -> V_30 = F_4 ( V_3 , V_36 ) ;
V_85 = F_223 ( V_459 , V_465 , sizeof( struct V_464 ) ) ;
if ( 0 != V_85 ) {
return - V_489 ;
}
break;
case V_490 :
V_348 . V_348 = F_4 ( V_3 , V_269 ) ;
V_16 = F_4 ( V_3 , V_269 + 4 ) ;
if ( V_16 & V_272 ) {
switch ( V_16 & ( V_273 |
V_274 ) ) {
case 0 :
V_348 . V_491 = V_492 ;
break;
case V_273 :
V_348 . V_491 = V_493 ;
break;
case V_274 :
V_348 . V_491 = V_494 ;
break;
default:
V_348 . V_491 = 30 ;
break;
}
if ( V_16 & V_300 ) {
V_348 . V_495 = V_496 ;
} else {
V_348 . V_495 = V_497 ;
}
} else {
V_348 . V_491 = V_498 ;
V_348 . V_495 = V_499 ;
}
if ( V_16 & V_270 ) {
V_348 . V_500 = V_501 ;
} else if ( V_16 & V_271 ) {
V_348 . V_500 = V_502 ;
} else {
V_348 . V_500 = V_503 ;
}
V_85 = F_223 ( V_459 , & V_348 , sizeof( struct V_466 ) ) ;
if ( 0 != V_85 ) {
return - V_489 ;
}
break;
case V_504 :
memset ( & V_428 , 0 , sizeof( V_428 ) ) ;
F_30 ( & V_3 -> V_22 ) ;
V_428 . V_341 = F_88 ( V_3 ) ;
V_428 . V_505 = F_132 ( V_3 ) ;
V_428 . V_107 = V_3 -> V_107 ;
V_428 . V_506 =
F_17 ( V_3 ) ;
V_428 . V_343 = F_67 ( V_3 ) ;
V_428 . V_507 = F_83 ( V_3 ) ;
V_428 . V_342 = F_18 ( V_3 ) ;
V_428 . V_508 = F_100 ( V_3 , V_364 ) ;
V_428 . V_509 = 0 ;
F_32 ( & V_3 -> V_22 ) ;
if ( F_223 ( V_459 , & V_428 , sizeof( V_428 ) ) )
return - V_489 ;
break;
case V_510 :
memset ( & V_29 , 0 , sizeof( V_29 ) ) ;
V_29 . V_511 = V_3 -> V_34 ;
V_29 . V_512 = F_18 ( V_3 ) ;
V_29 . V_513 = 110069313433624ULL ;
V_29 . V_514 = F_4 ( V_3 , V_218 ) ;
switch ( V_3 -> V_34 ) {
case V_49 :
case V_45 :
V_29 . V_515 . V_516 . V_517 =
F_132 ( V_3 ) ;
V_29 . V_515 . V_516 . V_518 =
F_133 ( V_3 ) ;
V_29 . V_515 . V_516 . V_519 =
F_19 ( V_3 ) ;
V_29 . V_515 . V_516 . V_520 =
F_20 ( V_3 ) ;
V_467 =
F_4 ( V_3 , V_37 ) ;
V_29 . V_515 . V_516 . V_521 =
( V_467 & V_375 ) ? 1 : 0 ;
V_29 . V_515 . V_516 . V_522 =
( V_467 & V_376 ) ? 1 : 0 ;
V_29 . V_515 . V_516 . V_523 = 0 ;
default:
break;
}
if ( F_223 ( V_459 , & V_29 , sizeof( V_29 ) ) )
return - V_489 ;
break;
case V_524 :
memset ( & V_463 , 0 , sizeof( V_463 ) ) ;
V_463 . V_511 = V_3 -> V_34 ;
strncpy ( V_463 . V_525 , V_3 -> V_352 ,
sizeof( V_463 . V_525 ) ) ;
V_463 . V_358 = V_3 -> V_358 ;
V_463 . V_354 = V_3 -> V_354 ;
V_463 . V_526 = 0 ;
if ( V_3 -> V_234 )
V_463 . V_526 |= V_527 ;
if ( F_223 ( V_459 , & V_463 ,
sizeof( V_463 ) ) )
return - V_489 ;
break;
case V_528 :
if ( F_225 ( & V_10 , V_459 , sizeof( V_10 ) ) )
return - V_489 ;
if ( F_223 ( ( void T_5 * ) V_10 . V_10 , V_3 -> V_10 ,
sizeof( struct V_529 ) ) )
return - V_489 ;
break;
default:
return - V_120 ;
}
return 0 ;
}
static int F_226 ( struct V_179 * V_180 ,
struct V_3 * V_3 )
{
struct V_455 * V_446 ;
int V_181 ;
V_181 = F_227 ( V_180 , L_166 , 0 , & V_446 ) ;
if ( V_181 < 0 )
return V_181 ;
V_3 -> V_530 = V_446 ;
V_446 -> V_173 = V_3 ;
strcpy ( V_446 -> V_207 , L_167 ) ;
V_446 -> V_531 . V_532 = F_221 ;
V_446 -> V_531 . V_533 = F_224 ;
V_446 -> V_531 . V_534 = F_224 ;
V_446 -> V_531 . V_535 = F_221 ;
return 0 ;
}
static int F_228 ( struct V_3 * V_3 )
{
int V_181 ;
struct V_536 * V_537 ;
T_7 V_538 ;
V_537 = V_3 -> V_537 ;
V_538 = V_419 ;
V_181 =
F_229 ( V_537 ,
V_539 ,
F_230 ( V_3 -> V_540 ) ,
V_538 ,
V_538 ) ;
if ( V_181 < 0 ) {
F_190 ( L_168 , V_538 ) ;
return V_181 ;
} else
F_190 ( L_169 , V_538 ) ;
return 0 ;
}
static void F_188 ( struct V_3 * V_3 ,
struct V_402 * V_170 ,
unsigned int V_4 , int V_541 )
{
int V_16 ;
for ( V_16 = 0 ; V_16 < ( V_541 * 16 ) ; V_16 ++ )
F_2 ( V_3 , V_4 + 4 * V_16 ,
F_231 ( V_170 , 4096 * V_16 ) ) ;
}
static int F_232 ( struct V_179 * V_180 ,
struct V_3 * V_3 )
{
struct V_536 * V_537 ;
int V_181 ;
V_181 = F_233 ( V_180 , V_3 -> V_352 , 0 , 1 , 1 , & V_537 ) ;
if ( V_181 < 0 )
return V_181 ;
V_3 -> V_537 = V_537 ;
V_537 -> V_173 = V_3 ;
strcpy ( V_537 -> V_207 , V_3 -> V_352 ) ;
F_234 ( V_537 , V_407 ,
& V_542 ) ;
F_234 ( V_537 , V_437 ,
& V_543 ) ;
V_537 -> V_212 = V_544 ;
V_181 = F_228 ( V_3 ) ;
if ( V_181 < 0 )
return V_181 ;
return 0 ;
}
static inline void F_235 ( struct V_3 * V_3 )
{
int V_16 ;
for ( V_16 = 0 ; V_16 < V_3 -> V_217 ; V_16 ++ )
F_45 ( V_3 , V_16 ) ;
}
static int F_236 ( struct V_179 * V_180 ,
struct V_3 * V_3 )
{
int V_181 , V_16 ;
F_190 ( L_170 ) ;
V_181 = F_232 ( V_180 , V_3 ) ;
if ( V_181 < 0 )
return V_181 ;
V_16 = 0 ;
while ( V_16 < V_3 -> V_217 ) {
V_181 = F_61 ( V_180 , V_3 , V_16 ) ;
if ( V_181 < 0 ) {
return V_181 ;
}
V_16 ++ ;
}
V_181 = F_159 ( V_180 , V_3 ) ;
if ( V_181 < 0 )
return V_181 ;
V_181 = F_226 ( V_180 , V_3 ) ;
if ( V_181 < 0 )
return V_181 ;
F_190 ( L_171 ) ;
F_170 ( V_3 ) ;
V_3 -> V_107 = - 1 ;
V_3 -> V_545 = - 1 ;
V_3 -> V_546 = - 1 ;
V_3 -> V_23 = - 1 ;
V_3 -> V_24 = - 1 ;
V_3 -> V_398 = NULL ;
V_3 -> V_399 = NULL ;
F_190 ( L_172 ) ;
V_181 = F_174 ( V_3 ) ;
if ( V_181 < 0 )
return V_181 ;
F_190 ( L_173 ) ;
F_157 ( V_3 ) ;
F_190 ( L_174 ) ;
V_181 = F_237 ( V_180 ) ;
if ( V_181 < 0 ) {
F_39 ( V_121 L_175 ) ;
return V_181 ;
}
F_190 ( L_176 ) ;
return 0 ;
}
static int F_238 ( struct V_179 * V_180 ,
struct V_3 * V_3 )
{
struct V_547 * V_540 = V_3 -> V_540 ;
int V_181 ;
unsigned long V_548 ;
V_3 -> V_187 = - 1 ;
V_3 -> V_180 = V_180 ;
F_62 ( & V_3 -> V_22 ) ;
F_239 ( V_3 -> V_540 ,
V_549 , & V_3 -> V_354 ) ;
strcpy ( V_180 -> V_550 , L_177 ) ;
strcpy ( V_180 -> V_551 , L_178 ) ;
switch ( V_3 -> V_354 ) {
case V_552 :
V_3 -> V_34 = V_51 ;
V_3 -> V_352 = L_179 ;
V_3 -> V_217 = 2 ;
break;
case V_553 :
V_3 -> V_34 = V_50 ;
V_3 -> V_352 = L_180 ;
V_3 -> V_217 = 1 ;
break;
case V_554 :
V_3 -> V_34 = V_45 ;
V_3 -> V_352 = L_181 ;
V_3 -> V_217 = 1 ;
break;
default:
if ( ( V_3 -> V_354 == 0xf0 ) ||
( ( V_3 -> V_354 >= 0xe6 ) &&
( V_3 -> V_354 <= 0xea ) ) ) {
V_3 -> V_34 = V_35 ;
V_3 -> V_352 = L_182 ;
V_3 -> V_217 = 2 ;
} else if ( ( V_3 -> V_354 == 0xd2 ) ||
( ( V_3 -> V_354 >= 0xc8 ) &&
( V_3 -> V_354 <= 0xcf ) ) ) {
V_3 -> V_34 = V_49 ;
V_3 -> V_352 = L_183 ;
V_3 -> V_217 = 3 ;
} else {
F_39 ( V_121
L_184 ,
V_3 -> V_354 ) ;
return - V_555 ;
}
}
V_181 = F_240 ( V_540 ) ;
if ( V_181 < 0 )
return V_181 ;
F_241 ( V_3 -> V_540 ) ;
V_181 = F_242 ( V_540 , L_151 ) ;
if ( V_181 < 0 )
return V_181 ;
V_3 -> V_359 = F_243 ( V_540 , 0 ) ;
V_548 = F_244 ( V_540 , 0 ) ;
F_190 ( L_185 ,
V_3 -> V_359 , V_3 -> V_359 + V_548 - 1 ) ;
V_3 -> V_6 = F_245 ( V_3 -> V_359 , V_548 ) ;
if ( ! V_3 -> V_6 ) {
F_39 ( V_121 L_1
L_186 ,
V_3 -> V_359 , V_3 -> V_359 + V_548 - 1 ) ;
return - V_123 ;
}
F_190 ( L_187 ,
( unsigned long ) V_3 -> V_6 , V_3 -> V_359 ,
V_3 -> V_359 + V_548 - 1 ) ;
if ( F_246 ( V_540 -> V_187 , F_176 ,
V_556 , V_557 , V_3 ) ) {
F_39 ( V_121 L_188 , V_540 -> V_187 ) ;
return - V_123 ;
}
F_190 ( L_189 , V_540 -> V_187 ) ;
V_3 -> V_187 = V_540 -> V_187 ;
F_190 ( L_190 ,
sizeof( struct V_529 ) ) ;
V_3 -> V_10 = F_247 ( sizeof( struct V_529 ) , V_558 ) ;
if ( ! V_3 -> V_10 ) {
F_39 ( V_121 L_1
L_191 ,
( int ) sizeof( struct V_529 ) ) ;
return - V_559 ;
}
V_3 -> V_134 = NULL ;
V_3 -> V_136 = NULL ;
switch ( V_3 -> V_34 ) {
case V_35 :
V_3 -> V_131 = V_3 -> V_133 = V_560 ;
V_3 -> V_140 = V_3 -> V_141 = V_560 ;
V_3 -> V_146 = V_3 -> V_147 = V_560 ;
V_3 -> V_127 = V_3 -> V_129 =
V_561 ;
V_3 -> V_138 = V_3 -> V_139 =
V_561 ;
V_3 -> V_144 = V_3 -> V_145 =
V_561 ;
V_3 -> V_135 = V_3 -> V_137 =
V_562 ;
V_3 -> V_142 = V_3 -> V_143 =
V_562 ;
V_3 -> V_148 = V_3 -> V_149 =
V_562 ;
V_3 -> V_132 = V_3 -> V_130 =
V_560 ;
V_3 -> V_134 = V_3 -> V_136 =
V_562 ;
V_3 -> V_126 = V_3 -> V_128 =
V_561 ;
break;
case V_49 :
case V_45 :
V_3 -> V_131 = V_3 -> V_133 =
V_563 ;
V_3 -> V_140 = V_3 -> V_141 =
V_564 ;
V_3 -> V_146 = V_3 -> V_147 =
V_565 ;
V_3 -> V_127 = V_3 -> V_129 =
V_566 ;
V_3 -> V_138 = V_3 -> V_139 =
V_566 ;
V_3 -> V_144 = V_3 -> V_145 =
V_566 ;
V_3 -> V_135 = V_3 -> V_137 =
V_567 ;
V_3 -> V_142 = V_3 -> V_143 =
V_567 ;
V_3 -> V_148 = V_3 -> V_149 =
V_567 ;
break;
case V_50 :
if ( 0 == ( F_4 ( V_3 , V_36 ) & V_568 ) ) {
F_39 ( V_418 L_192 ) ;
}
V_3 -> V_131 = V_569 ;
V_3 -> V_140 = V_570 ;
V_3 -> V_146 = V_571 ;
V_3 -> V_133 = V_572 ;
V_3 -> V_141 = V_573 ;
V_3 -> V_147 = V_574 ;
V_3 -> V_129 = V_575 ;
V_3 -> V_139 = V_576 ;
V_3 -> V_145 = V_577 ;
V_3 -> V_127 = V_578 ;
V_3 -> V_138 = V_579 ;
V_3 -> V_144 = V_580 ;
V_3 -> V_135 = V_581 ;
V_3 -> V_137 = V_582 ;
V_3 -> V_142 = V_583 ;
V_3 -> V_143 = V_584 ;
V_3 -> V_148 = V_585 ;
V_3 -> V_149 = V_586 ;
break;
case V_51 :
V_3 -> V_131 = V_3 -> V_133 =
V_587 ;
V_3 -> V_140 = V_3 -> V_141 =
V_588 ;
V_3 -> V_146 = V_3 -> V_147 =
V_589 ;
V_3 -> V_130 = V_587 ;
V_3 -> V_132 = V_587 ;
V_3 -> V_127 = V_3 -> V_129 =
V_590 ;
V_3 -> V_138 = V_3 -> V_139 =
V_591 ;
V_3 -> V_144 = V_3 -> V_145 =
V_592 ;
V_3 -> V_126 = V_3 -> V_128 =
V_590 ;
V_3 -> V_135 = V_3 -> V_137 =
V_593 ;
V_3 -> V_142 = V_3 -> V_143 =
V_594 ;
V_3 -> V_148 = V_3 -> V_149 =
V_595 ;
break;
}
switch ( V_3 -> V_34 ) {
case V_50 :
case V_51 :
if ( F_4 ( V_3 , V_36 ) &
V_596 ) {
V_3 -> V_217 ++ ;
V_3 -> V_234 = F_247 ( sizeof( struct V_597 ) ,
V_558 ) ;
if ( NULL != V_3 -> V_234 ) {
F_138 ( V_3 ) ;
}
F_39 ( V_418 L_193 ) ;
} else {
V_3 -> V_234 = NULL ;
}
break;
case V_49 :
if ( F_4 ( V_3 , V_37 ) & V_363 ) {
V_3 -> V_217 ++ ;
V_3 -> V_234 = F_247 ( sizeof( struct V_597 ) ,
V_558 ) ;
if ( NULL != V_3 -> V_234 ) {
F_138 ( V_3 ) ;
}
F_39 ( V_418 L_194 ) ;
} else {
V_3 -> V_234 = NULL ;
}
break;
default:
V_3 -> V_234 = NULL ;
}
switch ( V_3 -> V_34 ) {
case V_35 :
if ( V_3 -> V_234 ) {
V_3 -> V_259 = V_598 ;
V_3 -> V_258 = 10 ;
} else {
V_3 -> V_259 = V_599 ;
V_3 -> V_258 = 9 ;
}
break;
case V_49 :
if ( V_3 -> V_234 ) {
V_3 -> V_259 = V_600 ;
V_3 -> V_258 = 4 ;
} else {
V_3 -> V_259 = V_601 ;
V_3 -> V_258 = 3 ;
}
break;
case V_45 :
break;
case V_51 :
if ( V_3 -> V_234 ) {
V_3 -> V_259 = V_602 ;
V_3 -> V_258 = 9 ;
} else {
V_3 -> V_259 = V_603 ;
V_3 -> V_258 = 8 ;
}
break;
case V_50 :
if ( V_3 -> V_234 ) {
V_3 -> V_259 = V_604 ;
V_3 -> V_258 = 6 ;
} else {
V_3 -> V_259 = V_605 ;
V_3 -> V_258 = 5 ;
}
break;
}
F_248 ( & V_3 -> V_400 ,
F_65 , ( unsigned long ) V_3 ) ;
if ( V_3 -> V_34 != V_45 ) {
V_3 -> V_358 = ( F_4 ( V_3 ,
V_190 ) >> 8 ) & 0xFFFFFF ;
if ( NULL == V_154 [ V_3 -> V_606 ] && V_3 -> V_358 != 0xFFFFFF ) {
sprintf ( V_180 -> V_154 , L_195 , V_3 -> V_358 ) ;
F_249 ( V_180 , V_180 -> V_154 ) ;
}
}
F_190 ( L_196 ) ;
V_181 = F_236 ( V_180 , V_3 ) ;
if ( V_181 < 0 )
return V_181 ;
F_235 ( V_3 ) ;
return 0 ;
}
static int F_250 ( struct V_3 * V_3 )
{
if ( V_3 -> V_359 ) {
V_3 -> V_26 &=
~ ( V_87 | V_86 |
V_193 | V_199 |
V_186 | V_204 ) ;
F_2 ( V_3 , V_88 ,
V_3 -> V_26 ) ;
}
if ( V_3 -> V_187 >= 0 )
F_251 ( V_3 -> V_187 , ( void * ) V_3 ) ;
F_252 ( V_3 -> V_10 ) ;
if ( V_3 -> V_6 )
F_253 ( V_3 -> V_6 ) ;
if ( V_3 -> V_359 )
F_254 ( V_3 -> V_540 ) ;
F_255 ( V_3 -> V_540 ) ;
return 0 ;
}
static void F_256 ( struct V_179 * V_180 )
{
struct V_3 * V_3 = V_180 -> V_173 ;
if ( V_3 )
F_250 ( V_3 ) ;
}
static int F_257 ( struct V_547 * V_540 ,
const struct V_607 * V_608 )
{
static int V_606 ;
struct V_3 * V_3 ;
struct V_179 * V_180 ;
int V_181 ;
if ( V_606 >= V_609 )
return - V_555 ;
if ( ! V_610 [ V_606 ] ) {
V_606 ++ ;
return - V_611 ;
}
V_181 = F_258 ( V_239 [ V_606 ] , V_154 [ V_606 ] ,
V_612 , sizeof( struct V_3 ) , & V_180 ) ;
if ( V_181 < 0 )
return V_181 ;
V_3 = V_180 -> V_173 ;
V_180 -> V_613 = F_256 ;
V_3 -> V_606 = V_606 ;
V_3 -> V_540 = V_540 ;
F_259 ( V_180 , & V_540 -> V_606 ) ;
V_181 = F_238 ( V_180 , V_3 ) ;
if ( V_181 < 0 ) {
F_260 ( V_180 ) ;
return V_181 ;
}
if ( V_3 -> V_34 != V_45 ) {
sprintf ( V_180 -> V_206 , L_197 ,
V_3 -> V_352 ,
V_3 -> V_358 ) ;
sprintf ( V_180 -> V_614 , L_198 ,
V_3 -> V_352 ,
V_3 -> V_358 ,
V_3 -> V_359 , V_3 -> V_187 ) ;
} else {
sprintf ( V_180 -> V_206 , L_199 , V_3 -> V_352 ) ;
sprintf ( V_180 -> V_614 , L_200 ,
V_3 -> V_352 , V_3 -> V_359 , V_3 -> V_187 ) ;
}
V_181 = F_237 ( V_180 ) ;
if ( V_181 < 0 ) {
F_260 ( V_180 ) ;
return V_181 ;
}
F_261 ( V_540 , V_180 ) ;
V_606 ++ ;
return 0 ;
}
static void F_262 ( struct V_547 * V_540 )
{
F_260 ( F_263 ( V_540 ) ) ;
}
