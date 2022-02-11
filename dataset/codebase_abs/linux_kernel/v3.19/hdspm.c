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
unsigned int V_32 , V_33 ;
int V_34 , V_28 = 0 , V_35 ;
switch ( V_3 -> V_5 ) {
case V_36 :
V_33 = F_5 ( V_3 , V_37 ) ;
V_32 = F_5 ( V_3 , V_38 ) ;
V_34 = F_19 ( V_3 ) ;
switch ( V_34 ) {
case V_39 :
if ( F_20 ( V_3 ) )
return F_1 ( F_21 ( V_3 ) ) ;
break;
case V_40 :
case V_41 :
case V_42 :
case V_43 :
case V_44 :
case V_45 :
case V_46 :
case V_47 :
if ( F_22 ( V_3 , V_34 - V_40 ) )
return F_1 ( F_23 ( V_3 ,
V_34 - V_40 ) ) ;
break;
case V_48 :
if ( F_24 ( V_3 ) )
return F_1 ( F_25 ( V_3 ) ) ;
break;
default:
return 0 ;
}
break;
case V_49 :
V_32 = F_5 ( V_3 , V_38 ) ;
if ( ! ( V_32 & V_50 ) ) {
V_28 = 0 ;
} else {
switch ( V_32 & ( V_51 ) ) {
case V_52 * 1 :
V_28 = 32000 ; break;
case V_52 * 2 :
V_28 = 44100 ; break;
case V_52 * 3 :
V_28 = 48000 ; break;
case V_52 * 4 :
V_28 = 64000 ; break;
case V_52 * 5 :
V_28 = 88200 ; break;
case V_52 * 6 :
V_28 = 96000 ; break;
case V_52 * 7 :
V_28 = 128000 ; break;
case V_52 * 8 :
V_28 = 176400 ; break;
case V_52 * 9 :
V_28 = 192000 ; break;
default:
V_28 = 0 ; break;
}
}
break;
case V_53 :
case V_4 :
case V_6 :
V_33 = F_5 ( V_3 , V_37 ) ;
V_32 = F_5 ( V_3 , V_38 ) ;
V_28 = 0 ;
if ( ( V_33 & V_54 ) != 0 &&
( V_33 & V_55 ) == 0 ) {
V_35 = V_33 & V_56 ;
switch ( V_35 ) {
case V_57 :
V_28 = 32000 ;
break;
case V_58 :
V_28 = 44100 ;
break;
case V_59 :
V_28 = 48000 ;
break;
case V_60 :
V_28 = 64000 ;
break;
case V_61 :
V_28 = 88200 ;
break;
case V_62 :
V_28 = 96000 ;
break;
case V_63 :
V_28 = 128000 ;
break;
case V_64 :
V_28 = 176400 ;
break;
case V_65 :
V_28 = 192000 ;
break;
default:
V_28 = 0 ;
break;
}
}
if ( V_28 != 0 &&
( V_33 & V_66 ) == V_67 )
return F_17 ( V_3 , V_28 ) ;
if ( V_32 & V_50 ) {
V_35 = V_32 & V_68 ;
switch ( V_35 ) {
case V_69 :
V_28 = 32000 ;
break;
case V_70 :
V_28 = 44100 ;
break;
case V_71 :
V_28 = 48000 ;
break;
case V_72 :
V_28 = 64000 ;
break;
case V_73 :
V_28 = 88200 ;
break;
case V_74 :
V_28 = 96000 ;
break;
case V_75 :
V_28 = 128000 ;
break;
case V_76 :
V_28 = 176400 ;
break;
case V_77 :
V_28 = 192000 ;
break;
default:
V_28 = 0 ;
break;
}
}
{
bool V_78 = 0 ;
bool V_79 = 0 ;
V_34 = F_19 ( V_3 ) ;
if ( V_80 == V_34 ) {
V_78 = 1 ;
V_79 = ( V_81 ==
F_24 ( V_3 ) ) ;
} else if ( V_82 == V_34 ) {
V_78 = 1 ;
V_79 = ( V_81 ==
F_26 ( V_3 ) ) ;
}
if ( V_78 && V_79 ) {
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
V_3 -> V_83 = 4 * F_28 ( V_3 ) ;
}
static T_1 F_31 ( struct V_3 * V_3 )
{
int V_84 ;
V_84 = F_5 ( V_3 , V_38 ) ;
switch ( V_3 -> V_5 ) {
case V_6 :
case V_4 :
V_84 &= V_85 ;
V_84 /= 4 ;
break;
default:
V_84 = ( V_84 & V_86 ) ?
( V_3 -> V_83 / 4 ) : 0 ;
}
return V_84 ;
}
static inline void F_32 ( struct V_3 * V_87 )
{
V_87 -> V_29 |= ( V_88 | V_89 ) ;
F_3 ( V_87 , V_90 , V_87 -> V_29 ) ;
}
static inline void F_33 ( struct V_3 * V_87 )
{
V_87 -> V_29 &= ~ ( V_89 | V_88 ) ;
F_3 ( V_87 , V_90 , V_87 -> V_29 ) ;
}
static void F_34 ( struct V_3 * V_3 )
{
int V_19 ;
int V_1 = V_3 -> V_83 ;
void * V_91 = V_3 -> V_92 ;
if ( V_91 == NULL )
return;
for ( V_19 = 0 ; V_19 < V_93 ; V_19 ++ ) {
memset ( V_91 , 0 , V_1 ) ;
V_91 += V_94 ;
}
}
static int F_35 ( struct V_3 * V_87 , unsigned int V_95 )
{
int V_1 ;
F_36 ( & V_87 -> V_25 ) ;
if ( 32 == V_95 ) {
V_1 = 7 ;
} else {
V_95 >>= 7 ;
V_1 = 0 ;
while ( V_95 ) {
V_1 ++ ;
V_95 >>= 1 ;
}
}
V_87 -> V_29 &= ~ V_96 ;
V_87 -> V_29 |= F_37 ( V_1 ) ;
F_3 ( V_87 , V_90 , V_87 -> V_29 ) ;
F_30 ( V_87 ) ;
F_38 ( & V_87 -> V_25 ) ;
return 0 ;
}
static T_2 F_39 ( struct V_3 * V_3 , T_2 V_97 )
{
T_2 V_98 ;
if ( V_97 == 0 )
return 0 ;
switch ( V_3 -> V_5 ) {
case V_53 :
case V_36 :
V_98 = 110069313433624ULL ;
break;
case V_6 :
case V_4 :
V_98 = 104857600000000ULL ;
break;
case V_49 :
V_98 = 131072000000000ULL ;
break;
default:
F_40 () ;
return 0 ;
}
return F_41 ( V_98 , V_97 ) ;
}
static void F_42 ( struct V_3 * V_3 , int V_28 )
{
T_2 V_1 ;
if ( V_28 >= 112000 )
V_28 /= 4 ;
else if ( V_28 >= 56000 )
V_28 /= 2 ;
switch ( V_3 -> V_5 ) {
case V_49 :
V_1 = 131072000000000ULL ;
break;
case V_53 :
case V_36 :
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
F_3 ( V_3 , V_99 , ( V_18 ) V_1 ) ;
}
static int F_44 ( struct V_3 * V_3 , int V_28 , int V_100 )
{
int V_101 ;
int V_35 ;
int V_102 = 0 ;
int V_103 , V_104 ;
if ( ! ( V_3 -> V_29 & V_105 ) ) {
if ( V_100 ) {
F_45 ( V_3 -> V_106 -> V_107 ,
L_1 ) ;
V_102 = 1 ;
} else {
int V_108 =
F_18 ( V_3 ) ;
if ( F_19 ( V_3 ) ==
V_109 ) {
F_45 ( V_3 -> V_106 -> V_107 ,
L_2 ) ;
V_102 = 1 ;
} else if ( V_28 != V_108 ) {
F_45 ( V_3 -> V_106 -> V_107 ,
L_3 ) ;
V_102 = 1 ;
}
}
}
V_101 = V_3 -> V_110 ;
if ( V_101 <= 48000 )
V_103 = V_111 ;
else if ( V_101 <= 96000 )
V_103 = V_112 ;
else
V_103 = V_113 ;
if ( V_28 <= 48000 )
V_104 = V_111 ;
else if ( V_28 <= 96000 )
V_104 = V_112 ;
else
V_104 = V_113 ;
switch ( V_28 ) {
case 32000 :
V_35 = V_114 ;
break;
case 44100 :
V_35 = V_115 ;
break;
case 48000 :
V_35 = V_116 ;
break;
case 64000 :
V_35 = V_117 ;
break;
case 88200 :
V_35 = V_118 ;
break;
case 96000 :
V_35 = V_119 ;
break;
case 128000 :
V_35 = V_120 ;
break;
case 176400 :
V_35 = V_121 ;
break;
case 192000 :
V_35 = V_122 ;
break;
default:
return - V_123 ;
}
if ( V_103 != V_104
&& ( V_3 -> V_27 >= 0 || V_3 -> V_26 >= 0 ) ) {
F_46 ( V_3 -> V_106 -> V_107 ,
L_4 ,
V_124 [ V_103 ] ,
V_124 [ V_104 ] ,
V_3 -> V_27 , V_3 -> V_26 ) ;
return - V_125 ;
}
V_3 -> V_29 &= ~ V_126 ;
V_3 -> V_29 |= V_35 ;
F_3 ( V_3 , V_90 , V_3 -> V_29 ) ;
F_42 ( V_3 , V_28 ) ;
if ( V_36 == V_3 -> V_5 && V_28 != V_101 )
F_3 ( V_3 , V_127 , 0 ) ;
V_3 -> V_110 = V_28 ;
if ( V_28 <= 48000 ) {
V_3 -> V_128 = V_3 -> V_129 ;
V_3 -> V_130 = V_3 -> V_131 ;
V_3 -> V_132 = V_3 -> V_133 ;
V_3 -> V_134 = V_3 -> V_135 ;
V_3 -> V_136 = V_3 -> V_137 ;
V_3 -> V_138 = V_3 -> V_139 ;
} else if ( V_28 <= 96000 ) {
V_3 -> V_128 = V_3 -> V_140 ;
V_3 -> V_130 = V_3 -> V_141 ;
V_3 -> V_132 = V_3 -> V_142 ;
V_3 -> V_134 = V_3 -> V_143 ;
V_3 -> V_136 = V_3 -> V_144 ;
V_3 -> V_138 = V_3 -> V_145 ;
} else {
V_3 -> V_128 = V_3 -> V_146 ;
V_3 -> V_130 = V_3 -> V_147 ;
V_3 -> V_132 = V_3 -> V_148 ;
V_3 -> V_134 = V_3 -> V_149 ;
V_3 -> V_136 = V_3 -> V_150 ;
V_3 -> V_138 = V_3 -> V_151 ;
}
if ( V_102 != 0 )
return - 1 ;
return 0 ;
}
static void F_47 ( struct V_3 * V_3 , int V_152 )
{
int V_19 , V_153 ;
unsigned int V_154 ;
if ( V_152 > V_155 )
V_154 = V_155 ;
else if ( V_152 < 0 )
V_154 = 0 ;
else
V_154 = V_152 ;
for ( V_19 = 0 ; V_19 < V_12 ; V_19 ++ )
for ( V_153 = 0 ; V_153 < V_12 ; V_153 ++ ) {
F_9 ( V_3 , V_19 , V_153 , V_154 ) ;
F_10 ( V_3 , V_19 , V_153 , V_154 ) ;
}
}
static inline unsigned char F_48 ( struct V_3 * V_3 ,
int V_156 )
{
return F_5 ( V_3 , V_3 -> V_157 [ V_156 ] . V_158 ) ;
}
static inline void F_49 ( struct V_3 * V_3 , int V_156 ,
int V_8 )
{
return F_3 ( V_3 , V_3 -> V_157 [ V_156 ] . V_159 , V_8 ) ;
}
static inline int F_50 ( struct V_3 * V_3 , int V_156 )
{
return F_5 ( V_3 , V_3 -> V_157 [ V_156 ] . V_160 ) & 0xFF ;
}
static inline int F_51 ( struct V_3 * V_3 , int V_156 )
{
int V_161 ;
V_161 = F_5 ( V_3 , V_3 -> V_157 [ V_156 ] . V_162 ) & 0xFF ;
if ( V_161 < 128 )
return 128 - V_161 ;
else
return 0 ;
}
static void F_52 ( struct V_3 * V_3 , int V_156 )
{
while ( F_50 ( V_3 , V_156 ) )
F_48 ( V_3 , V_156 ) ;
}
static int F_53 ( struct V_163 * V_164 )
{
unsigned long V_23 ;
int V_165 ;
int V_166 ;
int V_19 ;
unsigned char V_91 [ 128 ] ;
F_14 ( & V_164 -> V_25 , V_23 ) ;
if ( V_164 -> V_167 &&
! F_54 ( V_164 -> V_167 ) ) {
V_165 = F_51 ( V_164 -> V_3 ,
V_164 -> V_156 ) ;
if ( V_165 > 0 ) {
if ( V_165 > ( int ) sizeof ( V_91 ) )
V_165 = sizeof ( V_91 ) ;
V_166 = F_55 ( V_164 -> V_167 , V_91 ,
V_165 ) ;
if ( V_166 > 0 ) {
for ( V_19 = 0 ; V_19 < V_166 ; ++ V_19 )
F_49 ( V_164 -> V_3 ,
V_164 -> V_156 ,
V_91 [ V_19 ] ) ;
}
}
}
F_15 ( & V_164 -> V_25 , V_23 ) ;
return 0 ;
}
static int F_56 ( struct V_163 * V_164 )
{
unsigned char V_91 [ 128 ] ;
unsigned long V_23 ;
int V_165 ;
int V_19 ;
F_14 ( & V_164 -> V_25 , V_23 ) ;
V_165 = F_50 ( V_164 -> V_3 , V_164 -> V_156 ) ;
if ( V_165 > 0 ) {
if ( V_164 -> V_168 ) {
if ( V_165 > ( int ) sizeof ( V_91 ) )
V_165 = sizeof ( V_91 ) ;
for ( V_19 = 0 ; V_19 < V_165 ; ++ V_19 )
V_91 [ V_19 ] = F_48 ( V_164 -> V_3 ,
V_164 -> V_156 ) ;
if ( V_165 )
F_57 ( V_164 -> V_168 , V_91 ,
V_165 ) ;
} else {
while ( V_165 -- )
F_48 ( V_164 -> V_3 ,
V_164 -> V_156 ) ;
}
}
V_164 -> V_169 = 0 ;
F_15 ( & V_164 -> V_25 , V_23 ) ;
F_14 ( & V_164 -> V_3 -> V_25 , V_23 ) ;
V_164 -> V_3 -> V_29 |= V_164 -> V_170 ;
F_3 ( V_164 -> V_3 , V_90 ,
V_164 -> V_3 -> V_29 ) ;
F_15 ( & V_164 -> V_3 -> V_25 , V_23 ) ;
return F_53 ( V_164 ) ;
}
static void
F_58 ( struct V_171 * V_172 , int V_173 )
{
struct V_3 * V_3 ;
struct V_163 * V_164 ;
unsigned long V_23 ;
V_164 = V_172 -> V_174 -> V_175 ;
V_3 = V_164 -> V_3 ;
F_14 ( & V_3 -> V_25 , V_23 ) ;
if ( V_173 ) {
if ( ! ( V_3 -> V_29 & V_164 -> V_170 ) ) {
F_52 ( V_3 , V_164 -> V_156 ) ;
V_3 -> V_29 |= V_164 -> V_170 ;
}
} else {
V_3 -> V_29 &= ~ V_164 -> V_170 ;
}
F_3 ( V_3 , V_90 , V_3 -> V_29 ) ;
F_15 ( & V_3 -> V_25 , V_23 ) ;
}
static void F_59 ( unsigned long V_16 )
{
struct V_163 * V_164 = (struct V_163 * ) V_16 ;
unsigned long V_23 ;
F_53 ( V_164 ) ;
F_14 ( & V_164 -> V_25 , V_23 ) ;
if ( V_164 -> V_176 ) {
V_164 -> V_177 . V_178 = 1 + V_179 ;
F_60 ( & V_164 -> V_177 ) ;
}
F_15 ( & V_164 -> V_25 , V_23 ) ;
}
static void
F_61 ( struct V_171 * V_172 , int V_173 )
{
struct V_163 * V_164 ;
unsigned long V_23 ;
V_164 = V_172 -> V_174 -> V_175 ;
F_14 ( & V_164 -> V_25 , V_23 ) ;
if ( V_173 ) {
if ( ! V_164 -> V_176 ) {
F_62 ( & V_164 -> V_177 ) ;
V_164 -> V_177 . V_180 = F_59 ;
V_164 -> V_177 . V_16 = ( unsigned long ) V_164 ;
V_164 -> V_177 . V_178 = 1 + V_179 ;
F_60 ( & V_164 -> V_177 ) ;
V_164 -> V_176 ++ ;
}
} else {
if ( V_164 -> V_176 && -- V_164 -> V_176 <= 0 )
F_63 ( & V_164 -> V_177 ) ;
}
F_15 ( & V_164 -> V_25 , V_23 ) ;
if ( V_173 )
F_53 ( V_164 ) ;
}
static int F_64 ( struct V_171 * V_172 )
{
struct V_163 * V_164 ;
V_164 = V_172 -> V_174 -> V_175 ;
F_36 ( & V_164 -> V_25 ) ;
F_52 ( V_164 -> V_3 , V_164 -> V_156 ) ;
V_164 -> V_168 = V_172 ;
F_38 ( & V_164 -> V_25 ) ;
return 0 ;
}
static int F_65 ( struct V_171 * V_172 )
{
struct V_163 * V_164 ;
V_164 = V_172 -> V_174 -> V_175 ;
F_36 ( & V_164 -> V_25 ) ;
V_164 -> V_167 = V_172 ;
F_38 ( & V_164 -> V_25 ) ;
return 0 ;
}
static int F_66 ( struct V_171 * V_172 )
{
struct V_163 * V_164 ;
F_58 ( V_172 , 0 ) ;
V_164 = V_172 -> V_174 -> V_175 ;
F_36 ( & V_164 -> V_25 ) ;
V_164 -> V_168 = NULL ;
F_38 ( & V_164 -> V_25 ) ;
return 0 ;
}
static int F_67 ( struct V_171 * V_172 )
{
struct V_163 * V_164 ;
F_61 ( V_172 , 0 ) ;
V_164 = V_172 -> V_174 -> V_175 ;
F_36 ( & V_164 -> V_25 ) ;
V_164 -> V_167 = NULL ;
F_38 ( & V_164 -> V_25 ) ;
return 0 ;
}
static int F_68 ( struct V_181 * V_106 ,
struct V_3 * V_3 , int V_156 )
{
int V_182 ;
char V_91 [ 32 ] ;
V_3 -> V_157 [ V_156 ] . V_156 = V_156 ;
V_3 -> V_157 [ V_156 ] . V_3 = V_3 ;
F_69 ( & V_3 -> V_157 [ V_156 ] . V_25 ) ;
if ( 0 == V_156 ) {
if ( V_49 == V_3 -> V_5 ) {
V_3 -> V_157 [ 0 ] . V_158 = V_183 ;
V_3 -> V_157 [ 0 ] . V_160 = V_184 ;
V_3 -> V_157 [ 0 ] . V_159 = V_185 ;
V_3 -> V_157 [ 0 ] . V_162 = V_186 ;
V_3 -> V_157 [ 0 ] . V_170 = V_187 ;
V_3 -> V_157 [ 0 ] . V_188 = V_189 ;
} else {
V_3 -> V_157 [ 0 ] . V_158 = V_190 ;
V_3 -> V_157 [ 0 ] . V_160 = V_191 ;
V_3 -> V_157 [ 0 ] . V_159 = V_192 ;
V_3 -> V_157 [ 0 ] . V_162 = V_193 ;
V_3 -> V_157 [ 0 ] . V_170 = V_194 ;
V_3 -> V_157 [ 0 ] . V_188 = V_195 ;
}
} else if ( 1 == V_156 ) {
V_3 -> V_157 [ 1 ] . V_158 = V_196 ;
V_3 -> V_157 [ 1 ] . V_160 = V_197 ;
V_3 -> V_157 [ 1 ] . V_159 = V_198 ;
V_3 -> V_157 [ 1 ] . V_162 = V_199 ;
V_3 -> V_157 [ 1 ] . V_170 = V_200 ;
V_3 -> V_157 [ 1 ] . V_188 = V_201 ;
} else if ( ( 2 == V_156 ) && ( V_53 == V_3 -> V_5 ) ) {
V_3 -> V_157 [ 2 ] . V_158 = V_183 ;
V_3 -> V_157 [ 2 ] . V_160 = V_184 ;
V_3 -> V_157 [ 2 ] . V_159 = V_185 ;
V_3 -> V_157 [ 2 ] . V_162 = V_186 ;
V_3 -> V_157 [ 2 ] . V_170 = V_187 ;
V_3 -> V_157 [ 2 ] . V_188 = V_189 ;
} else if ( 2 == V_156 ) {
V_3 -> V_157 [ 2 ] . V_158 = V_183 ;
V_3 -> V_157 [ 2 ] . V_160 = V_184 ;
V_3 -> V_157 [ 2 ] . V_159 = - 1 ;
V_3 -> V_157 [ 2 ] . V_162 = - 1 ;
V_3 -> V_157 [ 2 ] . V_170 = V_187 ;
V_3 -> V_157 [ 2 ] . V_188 = V_202 ;
} else if ( 3 == V_156 ) {
V_3 -> V_157 [ 3 ] . V_158 = V_203 ;
V_3 -> V_157 [ 3 ] . V_160 = V_204 ;
V_3 -> V_157 [ 3 ] . V_159 = - 1 ;
V_3 -> V_157 [ 3 ] . V_162 = - 1 ;
V_3 -> V_157 [ 3 ] . V_170 = V_205 ;
V_3 -> V_157 [ 3 ] . V_188 = V_206 ;
}
if ( ( V_156 < 2 ) || ( ( 2 == V_156 ) && ( ( V_53 == V_3 -> V_5 ) ||
( V_49 == V_3 -> V_5 ) ) ) ) {
if ( ( V_156 == 0 ) && ( V_49 == V_3 -> V_5 ) ) {
sprintf ( V_91 , L_5 , V_106 -> V_207 ) ;
} else if ( ( V_156 == 2 ) && ( V_53 == V_3 -> V_5 ) ) {
sprintf ( V_91 , L_5 , V_106 -> V_207 ) ;
} else {
sprintf ( V_91 , L_6 , V_106 -> V_207 , V_156 + 1 ) ;
}
V_182 = F_70 ( V_106 , V_91 , V_156 , 1 , 1 ,
& V_3 -> V_157 [ V_156 ] . V_174 ) ;
if ( V_182 < 0 )
return V_182 ;
sprintf ( V_3 -> V_157 [ V_156 ] . V_174 -> V_208 , L_6 ,
V_106 -> V_156 , V_156 + 1 ) ;
V_3 -> V_157 [ V_156 ] . V_174 -> V_175 = & V_3 -> V_157 [ V_156 ] ;
F_71 ( V_3 -> V_157 [ V_156 ] . V_174 ,
V_209 ,
& V_210 ) ;
F_71 ( V_3 -> V_157 [ V_156 ] . V_174 ,
V_211 ,
& V_212 ) ;
V_3 -> V_157 [ V_156 ] . V_174 -> V_213 |=
V_214 |
V_215 |
V_216 ;
} else {
sprintf ( V_91 , L_7 , V_106 -> V_207 , V_156 + 1 ) ;
V_182 = F_70 ( V_106 , V_91 , V_156 , 1 , 1 ,
& V_3 -> V_157 [ V_156 ] . V_174 ) ;
if ( V_182 < 0 )
return V_182 ;
sprintf ( V_3 -> V_157 [ V_156 ] . V_174 -> V_208 ,
L_7 , V_106 -> V_156 , V_156 + 1 ) ;
V_3 -> V_157 [ V_156 ] . V_174 -> V_175 = & V_3 -> V_157 [ V_156 ] ;
F_71 ( V_3 -> V_157 [ V_156 ] . V_174 ,
V_211 ,
& V_212 ) ;
V_3 -> V_157 [ V_156 ] . V_174 -> V_213 |= V_215 ;
}
return 0 ;
}
static void F_72 ( unsigned long V_217 )
{
struct V_3 * V_3 = (struct V_3 * ) V_217 ;
int V_19 = 0 ;
while ( V_19 < V_3 -> V_218 ) {
if ( V_3 -> V_157 [ V_19 ] . V_169 )
F_56 ( & V_3 -> V_157 [ V_19 ] ) ;
V_19 ++ ;
}
}
static inline int F_27 ( struct V_3 * V_3 )
{
unsigned int V_97 , V_28 ;
V_97 = F_5 ( V_3 , V_219 ) ;
V_28 = F_39 ( V_3 , V_97 ) ;
return V_28 ;
}
static int F_73 ( struct V_3 * V_3 )
{
unsigned int V_28 ;
V_28 = F_27 ( V_3 ) ;
if ( V_28 > 207000 ) {
if ( 0 == F_74 ( V_3 ) ) {
V_28 = V_3 -> V_110 ;
} else {
V_28 = F_18 ( V_3 ) ;
}
}
return V_28 ;
}
static int F_75 ( struct V_220 * V_221 ,
struct V_222 * V_223 )
{
V_223 -> type = V_224 ;
V_223 -> V_225 = 1 ;
V_223 -> V_226 . integer . V_227 = 27000 ;
V_223 -> V_226 . integer . V_228 = 207000 ;
V_223 -> V_226 . integer . V_229 = 1 ;
return 0 ;
}
static int F_76 ( struct V_220 * V_221 ,
struct V_230 *
V_231 )
{
struct V_3 * V_3 = F_77 ( V_221 ) ;
V_231 -> V_226 . integer . V_226 [ 0 ] = F_73 ( V_3 ) ;
return 0 ;
}
static int F_78 ( struct V_220 * V_221 ,
struct V_230 *
V_231 )
{
struct V_3 * V_3 = F_77 ( V_221 ) ;
F_42 ( V_3 , V_231 -> V_226 . V_232 . V_233 [ 0 ] ) ;
return 0 ;
}
static int F_21 ( struct V_3 * V_3 )
{
int V_32 ;
switch ( V_3 -> V_5 ) {
case V_6 :
case V_4 :
V_32 = F_5 ( V_3 , V_234 ) ;
return ( V_32 >> 16 ) & 0xF ;
break;
case V_36 :
V_32 = F_5 ( V_3 , V_38 ) ;
return ( V_32 >> V_235 ) & 0xF ;
default:
break;
}
return 0 ;
}
static int F_25 ( struct V_3 * V_3 )
{
int V_32 ;
if ( V_3 -> V_236 ) {
switch ( V_3 -> V_5 ) {
case V_6 :
case V_4 :
V_32 = F_5 ( V_3 , V_234 ) ;
return ( V_32 >> 20 ) & 0xF ;
break;
case V_36 :
V_32 = F_5 ( V_3 , V_38 ) ;
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
if ( V_3 -> V_236 ) {
switch ( V_3 -> V_5 ) {
case V_6 :
case V_4 :
V_32 = F_5 ( V_3 , V_237 ) ;
return ( V_32 >> 12 ) & 0xF ;
break;
default:
break;
}
}
return 0 ;
}
static int F_23 ( struct V_3 * V_3 , int V_238 )
{
int V_239 ;
switch ( V_3 -> V_5 ) {
case V_36 :
V_239 = F_5 ( V_3 , V_240 ) ;
return ( V_239 >> ( 4 * V_238 ) ) & 0xF ;
break;
default:
break;
}
return 0 ;
}
static int F_80 ( struct V_3 * V_3 , unsigned int V_241 )
{
int V_32 = F_5 ( V_3 , V_237 ) ;
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
static int F_82 ( struct V_220 * V_221 ,
struct V_222 * V_223 )
{
F_83 ( V_223 , V_243 ) ;
return 0 ;
}
static int F_84 ( struct V_220 * V_221 ,
struct V_230 *
V_231 )
{
struct V_3 * V_3 = F_77 ( V_221 ) ;
switch ( V_3 -> V_5 ) {
case V_6 :
switch ( V_221 -> V_244 ) {
case 0 :
V_231 -> V_226 . V_232 . V_233 [ 0 ] =
F_21 ( V_3 ) ;
break;
case 7 :
V_231 -> V_226 . V_232 . V_233 [ 0 ] =
F_25 ( V_3 ) ;
break;
case 8 :
V_231 -> V_226 . V_232 . V_233 [ 0 ] =
F_79 ( V_3 ) ;
break;
default:
V_231 -> V_226 . V_232 . V_233 [ 0 ] =
F_80 ( V_3 ,
V_221 -> V_244 - 1 ) ;
}
break;
case V_4 :
switch ( V_221 -> V_244 ) {
case 0 :
V_231 -> V_226 . V_232 . V_233 [ 0 ] =
F_21 ( V_3 ) ;
break;
case 4 :
V_231 -> V_226 . V_232 . V_233 [ 0 ] =
F_25 ( V_3 ) ;
break;
case 5 :
V_231 -> V_226 . V_232 . V_233 [ 0 ] =
F_79 ( V_3 ) ;
break;
default:
V_231 -> V_226 . V_232 . V_233 [ 0 ] =
F_80 ( V_3 ,
V_221 -> V_244 - 1 ) ;
}
break;
case V_36 :
switch ( V_221 -> V_244 ) {
case 0 :
V_231 -> V_226 . V_232 . V_233 [ 0 ] =
F_21 ( V_3 ) ;
break;
case 9 :
V_231 -> V_226 . V_232 . V_233 [ 0 ] =
F_25 ( V_3 ) ;
break;
case 10 :
V_231 -> V_226 . V_232 . V_233 [ 0 ] =
F_79 ( V_3 ) ;
break;
case 11 :
V_231 -> V_226 . V_232 . V_233 [ 0 ] =
F_81 ( V_3 ) ;
break;
default:
V_231 -> V_226 . V_232 . V_233 [ 0 ] =
F_23 ( V_3 ,
V_221 -> V_244 -
V_40 ) ;
break;
}
break;
case V_53 :
case V_49 :
V_231 -> V_226 . V_232 . V_233 [ 0 ] =
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
if ( V_3 -> V_29 & V_105 )
return 0 ;
}
return 1 ;
}
static void F_85 ( struct V_3 * V_3 , int V_247 )
{
F_86 ( V_3 ,
( F_2 ( V_3 ) ) ?
V_246 : V_105 ,
( 0 == V_247 ) ) ;
}
static int F_87 ( struct V_220 * V_221 ,
struct V_222 * V_223 )
{
static const char * const V_248 [] = { L_8 , L_9 } ;
F_83 ( V_223 , V_248 ) ;
return 0 ;
}
static int F_88 ( struct V_220 * V_221 ,
struct V_230 * V_231 )
{
struct V_3 * V_3 = F_77 ( V_221 ) ;
V_231 -> V_226 . V_232 . V_233 [ 0 ] = F_74 ( V_3 ) ;
return 0 ;
}
static int F_89 ( struct V_220 * V_221 ,
struct V_230 * V_231 )
{
struct V_3 * V_3 = F_77 ( V_221 ) ;
int V_8 ;
if ( ! F_13 ( V_3 ) )
return - V_125 ;
V_8 = V_231 -> V_226 . V_232 . V_233 [ 0 ] ;
if ( V_8 < 0 )
V_8 = 0 ;
else if ( V_8 > 1 )
V_8 = 1 ;
F_85 ( V_3 , V_8 ) ;
return 0 ;
}
static int F_90 ( struct V_3 * V_3 )
{
switch ( V_3 -> V_110 ) {
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
static int F_92 ( struct V_220 * V_221 ,
struct V_222 * V_223 )
{
return F_93 ( V_223 , 1 , 9 , V_243 + 1 ) ;
}
static int F_94 ( struct V_220 * V_221 ,
struct V_230 * V_231 )
{
struct V_3 * V_3 = F_77 ( V_221 ) ;
V_231 -> V_226 . V_232 . V_233 [ 0 ] = F_90 ( V_3 ) ;
return 0 ;
}
static int F_95 ( struct V_220 * V_221 ,
struct V_230 * V_231 )
{
struct V_3 * V_3 = F_77 ( V_221 ) ;
int V_249 ;
int V_8 ;
if ( ! F_13 ( V_3 ) )
return - V_125 ;
V_8 = V_231 -> V_226 . V_232 . V_233 [ 0 ] ;
if ( V_8 < 0 )
V_8 = 0 ;
if ( V_8 > 9 )
V_8 = 9 ;
F_36 ( & V_3 -> V_25 ) ;
if ( V_8 != F_90 ( V_3 ) )
V_249 = ( F_91 ( V_3 , V_8 ) == 0 ) ? 1 : 0 ;
else
V_249 = 0 ;
F_38 ( & V_3 -> V_25 ) ;
return V_249 ;
}
static int F_96 ( struct V_3 * V_3 )
{
switch ( V_3 -> V_5 ) {
case V_36 :
switch ( V_3 -> V_29 & V_250 ) {
case 0 : return 0 ;
case V_251 : return 1 ;
case V_252 : return 2 ;
case V_252 + V_251 : return 3 ;
case V_253 : return 4 ;
case V_253 + V_251 : return 5 ;
case V_253 + V_252 : return 6 ;
case V_253 + V_252 + V_251 :
return 7 ;
case V_254 : return 8 ;
case V_254 + V_251 : return 9 ;
}
break;
case V_53 :
case V_49 :
if ( V_3 -> V_236 ) {
switch ( V_3 -> V_29 & V_250 ) {
case 0 : return 0 ;
case V_251 : return 1 ;
case V_252 : return 2 ;
case V_252 + V_251 :
return 3 ;
}
} else {
switch ( V_3 -> V_29 & V_250 ) {
case 0 : return 0 ;
case V_251 : return 1 ;
case V_252 + V_251 :
return 2 ;
}
}
break;
case V_6 :
if ( V_3 -> V_236 ) {
switch ( ( V_3 -> V_245 &
V_255 ) / V_256 ) {
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
V_255 ) / V_256 ) {
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
if ( V_3 -> V_236 ) {
switch ( ( V_3 -> V_245 &
V_255 ) / V_256 ) {
case 0 : return 0 ;
case 3 : return 1 ;
case 1 : return 2 ;
case 2 : return 3 ;
case 9 : return 4 ;
case 10 : return 5 ;
}
} else {
switch ( ( V_3 -> V_245 &
V_255 ) / V_256 ) {
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
static int F_97 ( struct V_3 * V_3 , int V_257 )
{
int V_258 = 0 ;
switch ( V_3 -> V_5 ) {
case V_36 :
V_3 -> V_29 &= ~ V_250 ;
switch ( V_257 ) {
case 0 :
break;
case 1 :
V_3 -> V_29 |= V_251 ;
break;
case 2 :
V_3 -> V_29 |= V_252 ;
break;
case 3 :
V_3 -> V_29 |=
V_252 + V_251 ;
break;
case 4 :
V_3 -> V_29 |= V_253 ;
break;
case 5 :
V_3 -> V_29 |=
V_253 + V_251 ;
break;
case 6 :
V_3 -> V_29 |=
V_253 + V_252 ;
break;
case 7 :
V_3 -> V_29 |=
V_253 + V_252 + V_251 ;
break;
case 8 :
V_3 -> V_29 |= V_254 ;
break;
case 9 :
V_3 -> V_29 |=
V_254 + V_251 ;
break;
default:
return - 1 ;
}
break;
case V_53 :
case V_49 :
V_3 -> V_29 &= ~ V_250 ;
if ( V_3 -> V_236 ) {
switch ( V_257 ) {
case 0 :
break;
case 1 :
V_3 -> V_29 |= V_251 ;
break;
case 2 :
V_3 -> V_29 |= V_252 ;
break;
case 3 :
V_3 -> V_29 |=
V_251 + V_252 ;
break;
default:
return - 1 ;
}
} else {
switch ( V_257 ) {
case 0 :
break;
case 1 :
V_3 -> V_29 |= V_251 ;
break;
case 2 :
V_3 -> V_29 |=
V_251 + V_252 ;
break;
default:
return - 1 ;
}
}
break;
case V_6 :
if ( V_3 -> V_236 ) {
switch ( V_257 ) {
case 0 : V_258 = 0 ; break;
case 1 : V_258 = 3 ; break;
case 2 : V_258 = 4 ; break;
case 3 : V_258 = 5 ; break;
case 4 : V_258 = 6 ; break;
case 5 : V_258 = 1 ; break;
case 6 : V_258 = 2 ; break;
case 7 : V_258 = 9 ; break;
case 8 : V_258 = 10 ; break;
default: return - 1 ;
}
} else {
switch ( V_257 ) {
case 0 : V_258 = 0 ; break;
case 1 : V_258 = 3 ; break;
case 2 : V_258 = 4 ; break;
case 3 : V_258 = 5 ; break;
case 4 : V_258 = 6 ; break;
case 5 : V_258 = 1 ; break;
case 6 : V_258 = 2 ; break;
case 7 : V_258 = 10 ; break;
default: return - 1 ;
}
}
break;
case V_4 :
if ( V_3 -> V_236 ) {
switch ( V_257 ) {
case 0 : V_258 = 0 ; break;
case 1 : V_258 = 3 ; break;
case 2 : V_258 = 1 ; break;
case 3 : V_258 = 2 ; break;
case 4 : V_258 = 9 ; break;
case 5 : V_258 = 10 ; break;
default: return - 1 ;
}
} else {
switch ( V_257 ) {
case 0 : V_258 = 0 ; break;
case 1 : V_258 = 3 ; break;
case 2 : V_258 = 1 ; break;
case 3 : V_258 = 2 ; break;
case 4 : V_258 = 10 ; break;
default: return - 1 ;
}
}
break;
}
switch ( V_3 -> V_5 ) {
case V_6 :
case V_4 :
V_3 -> V_245 &= ~ V_255 ;
V_3 -> V_245 |= V_256 * V_258 ;
F_3 ( V_3 , V_259 , V_3 -> V_245 ) ;
break;
case V_53 :
case V_49 :
case V_36 :
F_3 ( V_3 , V_90 ,
V_3 -> V_29 ) ;
}
return 0 ;
}
static int F_98 ( struct V_220 * V_221 ,
struct V_222 * V_223 )
{
struct V_3 * V_3 = F_77 ( V_221 ) ;
F_93 ( V_223 , 1 , V_3 -> V_260 , V_3 -> V_261 ) ;
return 0 ;
}
static int F_99 ( struct V_220 * V_221 ,
struct V_230 * V_231 )
{
struct V_3 * V_3 = F_77 ( V_221 ) ;
int V_262 = F_96 ( V_3 ) ;
if ( V_262 >= 0 ) {
V_231 -> V_226 . V_232 . V_233 [ 0 ] = V_262 ;
return 0 ;
}
return - 1 ;
}
static int F_100 ( struct V_220 * V_221 ,
struct V_230 * V_231 )
{
struct V_3 * V_3 = F_77 ( V_221 ) ;
int V_8 , V_249 = 0 ;
if ( ! F_13 ( V_3 ) )
return - V_125 ;
V_8 = V_231 -> V_226 . V_232 . V_233 [ 0 ] ;
if ( V_8 < 0 )
V_8 = 0 ;
else if ( V_8 >= V_3 -> V_260 )
V_8 = V_3 -> V_260 - 1 ;
F_36 ( & V_3 -> V_25 ) ;
if ( V_8 != F_96 ( V_3 ) )
V_249 = ( 0 == F_97 ( V_3 , V_8 ) ) ? 1 : 0 ;
F_38 ( & V_3 -> V_25 ) ;
return V_249 ;
}
static int F_19 ( struct V_3 * V_3 )
{
if ( V_36 == V_3 -> V_5 ) {
unsigned int V_32 = F_5 ( V_3 , V_38 ) ;
unsigned int V_34 = ( V_32 >> V_263 ) & 0xF ;
if ( ( V_34 >= V_39 ) &&
( V_34 <= V_264 ) ) {
return V_34 ;
}
return V_265 ;
} else if ( V_53 == V_3 -> V_5 ) {
unsigned int V_33 = F_5 ( V_3 , V_37 ) ;
switch ( V_33 & V_66 ) {
case V_67 :
return V_266 ;
case V_267 :
return V_268 ;
case V_269 :
return V_80 ;
case V_270 :
return V_82 ;
case V_271 :
return V_109 ;
default:
return V_109 ;
}
}
return 0 ;
}
static int F_101 ( struct V_220 * V_221 ,
struct V_222 * V_223 )
{
struct V_3 * V_3 = F_77 ( V_221 ) ;
if ( V_36 == V_3 -> V_5 ) {
static const char * const V_248 [] = { L_10 , L_11 , L_12 , L_13 ,
L_14 , L_15 , L_16 , L_17 , L_18 , L_19 , L_20 , L_21 } ;
F_83 ( V_223 , V_248 ) ;
} else if ( V_53 == V_3 -> V_5 ) {
static const char * const V_248 [] = { L_22 , L_23 , L_19 ,
L_20 , L_21 } ;
F_83 ( V_223 , V_248 ) ;
}
return 0 ;
}
static int F_102 ( struct V_220 * V_221 ,
struct V_230 * V_231 )
{
struct V_3 * V_3 = F_77 ( V_221 ) ;
V_231 -> V_226 . V_232 . V_233 [ 0 ] = F_19 ( V_3 ) ;
return 0 ;
}
static int F_103 ( struct V_220 * V_221 ,
struct V_222 * V_223 )
{
static const char * const V_248 [] = { L_24 , L_25 , L_26 } ;
F_83 ( V_223 , V_248 ) ;
return 0 ;
}
static int F_104 ( struct V_220 * V_221 ,
struct V_230 * V_231 )
{
V_18 V_32 ;
int V_24 = 0 ;
struct V_3 * V_3 = F_77 ( V_221 ) ;
V_32 = F_5 ( V_3 , V_272 + 4 ) ;
switch ( V_32 & ( V_273 |
V_274 ) ) {
case V_273 :
V_24 = 1 ;
break;
case V_274 :
V_24 = 2 ;
break;
default:
V_24 = 0 ;
break;
}
V_231 -> V_226 . V_232 . V_233 [ 0 ] = V_24 ;
return 0 ;
}
static int F_105 ( struct V_220 * V_221 ,
struct V_222 * V_223 )
{
static const char * const V_248 [] = { L_27 , L_28 , L_29 , L_30 ,
L_31 } ;
F_83 ( V_223 , V_248 ) ;
return 0 ;
}
static int F_106 ( struct V_3 * V_3 )
{
V_18 V_32 ;
int V_24 = 0 ;
V_32 = F_5 ( V_3 , V_272 + 4 ) ;
if ( V_32 & V_275 ) {
switch ( V_32 & ( V_276 |
V_277 ) ) {
case 0 :
V_24 = V_278 ;
break;
case V_276 :
V_24 = V_279 ;
break;
case V_277 :
V_24 = V_280 ;
break;
default:
V_24 = V_281 ;
break;
}
}
return V_24 ;
}
static int F_107 ( struct V_220 * V_221 ,
struct V_230 * V_231 )
{
struct V_3 * V_3 = F_77 ( V_221 ) ;
V_231 -> V_226 . V_232 . V_233 [ 0 ] = F_106 ( V_3 ) ;
return 0 ;
}
static int F_108 ( struct V_3 * V_3 , V_18 V_282 )
{
V_18 V_7 ;
if ( F_2 ( V_3 ) )
V_7 = V_3 -> V_245 ;
else
V_7 = V_3 -> V_29 ;
return ( V_7 & V_282 ) ? 1 : 0 ;
}
static int F_86 ( struct V_3 * V_3 , V_18 V_282 , int V_283 )
{
V_18 * V_7 ;
V_18 V_284 ;
if ( F_2 ( V_3 ) ) {
V_7 = & ( V_3 -> V_245 ) ;
V_284 = V_259 ;
} else {
V_7 = & ( V_3 -> V_29 ) ;
V_284 = V_90 ;
}
if ( V_283 )
* V_7 |= V_282 ;
else
* V_7 &= ~ V_282 ;
F_3 ( V_3 , V_284 , * V_7 ) ;
return 0 ;
}
static int F_109 ( struct V_220 * V_221 ,
struct V_230 * V_231 )
{
struct V_3 * V_3 = F_77 ( V_221 ) ;
V_18 V_282 = V_221 -> V_244 ;
F_36 ( & V_3 -> V_25 ) ;
V_231 -> V_226 . integer . V_226 [ 0 ] = F_108 ( V_3 , V_282 ) ;
F_38 ( & V_3 -> V_25 ) ;
return 0 ;
}
static int F_110 ( struct V_220 * V_221 ,
struct V_230 * V_231 )
{
struct V_3 * V_3 = F_77 ( V_221 ) ;
V_18 V_282 = V_221 -> V_244 ;
int V_249 ;
unsigned int V_8 ;
if ( ! F_13 ( V_3 ) )
return - V_125 ;
V_8 = V_231 -> V_226 . integer . V_226 [ 0 ] & 1 ;
F_36 ( & V_3 -> V_25 ) ;
V_249 = ( int ) V_8 != F_108 ( V_3 , V_282 ) ;
F_86 ( V_3 , V_282 , V_8 ) ;
F_38 ( & V_3 -> V_25 ) ;
return V_249 ;
}
static int F_111 ( struct V_3 * V_3 )
{
return ( V_3 -> V_29 & V_285 ) ? 1 : 0 ;
}
static int F_112 ( struct V_3 * V_3 , int V_283 )
{
if ( V_283 )
V_3 -> V_29 |= V_285 ;
else
V_3 -> V_29 &= ~ V_285 ;
F_3 ( V_3 , V_90 , V_3 -> V_29 ) ;
return 0 ;
}
static int F_113 ( struct V_220 * V_221 ,
struct V_222 * V_223 )
{
static const char * const V_248 [] = { L_32 , L_33 } ;
F_83 ( V_223 , V_248 ) ;
return 0 ;
}
static int F_114 ( struct V_220 * V_221 ,
struct V_230 * V_231 )
{
struct V_3 * V_3 = F_77 ( V_221 ) ;
F_36 ( & V_3 -> V_25 ) ;
V_231 -> V_226 . V_232 . V_233 [ 0 ] = F_111 ( V_3 ) ;
F_38 ( & V_3 -> V_25 ) ;
return 0 ;
}
static int F_115 ( struct V_220 * V_221 ,
struct V_230 * V_231 )
{
struct V_3 * V_3 = F_77 ( V_221 ) ;
int V_249 ;
unsigned int V_8 ;
if ( ! F_13 ( V_3 ) )
return - V_125 ;
V_8 = V_231 -> V_226 . integer . V_226 [ 0 ] & 1 ;
F_36 ( & V_3 -> V_25 ) ;
V_249 = ( int ) V_8 != F_111 ( V_3 ) ;
F_112 ( V_3 , V_8 ) ;
F_38 ( & V_3 -> V_25 ) ;
return V_249 ;
}
static int F_116 ( struct V_3 * V_3 )
{
return ( V_3 -> V_29 & V_286 ) ? 1 : 0 ;
}
static int F_117 ( struct V_3 * V_3 , int V_287 )
{
if ( V_287 )
V_3 -> V_29 |= V_286 ;
else
V_3 -> V_29 &= ~ V_286 ;
F_3 ( V_3 , V_90 , V_3 -> V_29 ) ;
return 0 ;
}
static int F_118 ( struct V_220 * V_221 ,
struct V_222 * V_223 )
{
static const char * const V_248 [] = { L_34 , L_35 } ;
F_83 ( V_223 , V_248 ) ;
return 0 ;
}
static int F_119 ( struct V_220 * V_221 ,
struct V_230 * V_231 )
{
struct V_3 * V_3 = F_77 ( V_221 ) ;
F_36 ( & V_3 -> V_25 ) ;
V_231 -> V_226 . V_232 . V_233 [ 0 ] = F_116 ( V_3 ) ;
F_38 ( & V_3 -> V_25 ) ;
return 0 ;
}
static int F_120 ( struct V_220 * V_221 ,
struct V_230 * V_231 )
{
struct V_3 * V_3 = F_77 ( V_221 ) ;
int V_249 ;
unsigned int V_8 ;
if ( ! F_13 ( V_3 ) )
return - V_125 ;
V_8 = V_231 -> V_226 . integer . V_226 [ 0 ] & 1 ;
F_36 ( & V_3 -> V_25 ) ;
V_249 = ( int ) V_8 != F_116 ( V_3 ) ;
F_117 ( V_3 , V_8 ) ;
F_38 ( & V_3 -> V_25 ) ;
return V_249 ;
}
static int F_121 ( struct V_3 * V_3 )
{
if ( V_3 -> V_29 & V_288 )
return 1 ;
if ( V_3 -> V_29 & V_289 )
return 2 ;
return 0 ;
}
static int F_122 ( struct V_3 * V_3 , int V_247 )
{
V_3 -> V_29 &= ~ ( V_288 | V_289 ) ;
switch ( V_247 ) {
case 0 :
break;
case 1 :
V_3 -> V_29 |= V_288 ;
break;
case 2 :
V_3 -> V_29 |= V_289 ;
break;
}
F_3 ( V_3 , V_90 , V_3 -> V_29 ) ;
return 0 ;
}
static int F_123 ( struct V_220 * V_221 ,
struct V_222 * V_223 )
{
static const char * const V_248 [] = { L_34 , L_35 , L_36 } ;
F_83 ( V_223 , V_248 ) ;
return 0 ;
}
static int F_124 ( struct V_220 * V_221 ,
struct V_230 * V_231 )
{
struct V_3 * V_3 = F_77 ( V_221 ) ;
F_36 ( & V_3 -> V_25 ) ;
V_231 -> V_226 . V_232 . V_233 [ 0 ] = F_121 ( V_3 ) ;
F_38 ( & V_3 -> V_25 ) ;
return 0 ;
}
static int F_125 ( struct V_220 * V_221 ,
struct V_230 * V_231 )
{
struct V_3 * V_3 = F_77 ( V_221 ) ;
int V_249 ;
int V_8 ;
if ( ! F_13 ( V_3 ) )
return - V_125 ;
V_8 = V_231 -> V_226 . integer . V_226 [ 0 ] ;
if ( V_8 < 0 )
V_8 = 0 ;
if ( V_8 > 2 )
V_8 = 2 ;
F_36 ( & V_3 -> V_25 ) ;
V_249 = V_8 != F_121 ( V_3 ) ;
F_122 ( V_3 , V_8 ) ;
F_38 ( & V_3 -> V_25 ) ;
return V_249 ;
}
static int F_126 ( struct V_3 * V_3 , V_18 V_282 )
{
V_18 V_7 = V_3 -> V_245 & ( V_282 * 3 ) ;
return V_7 / V_282 ;
}
static int F_127 ( struct V_3 * V_3 , int V_247 , V_18 V_282 )
{
V_3 -> V_245 &= ~ ( V_282 * 3 ) ;
V_3 -> V_245 |= ( V_282 * V_247 ) ;
F_3 ( V_3 , V_259 , V_3 -> V_245 ) ;
return 0 ;
}
static int F_128 ( struct V_220 * V_221 ,
struct V_222 * V_223 )
{
V_18 V_282 = V_221 -> V_244 ;
static const char * const V_290 [] = { L_37 , L_38 , L_39 } ;
static const char * const V_291 [] = { L_40 , L_41 , L_42 } ;
switch ( V_282 ) {
case V_292 :
F_83 ( V_223 , V_290 ) ;
break;
default:
F_83 ( V_223 , V_291 ) ;
break;
}
return 0 ;
}
static int F_129 ( struct V_220 * V_221 ,
struct V_230 * V_231 )
{
struct V_3 * V_3 = F_77 ( V_221 ) ;
V_18 V_282 = V_221 -> V_244 ;
F_36 ( & V_3 -> V_25 ) ;
V_231 -> V_226 . V_232 . V_233 [ 0 ] = F_126 ( V_3 , V_282 ) ;
F_38 ( & V_3 -> V_25 ) ;
return 0 ;
}
static int F_130 ( struct V_220 * V_221 ,
struct V_230 * V_231 )
{
struct V_3 * V_3 = F_77 ( V_221 ) ;
V_18 V_282 = V_221 -> V_244 ;
int V_249 ;
int V_8 ;
if ( ! F_13 ( V_3 ) )
return - V_125 ;
V_8 = V_231 -> V_226 . integer . V_226 [ 0 ] ;
if ( V_8 < 0 )
V_8 = 0 ;
if ( V_8 > 2 )
V_8 = 2 ;
F_36 ( & V_3 -> V_25 ) ;
V_249 = V_8 != F_126 ( V_3 , V_282 ) ;
F_127 ( V_3 , V_8 , V_282 ) ;
F_38 ( & V_3 -> V_25 ) ;
return V_249 ;
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
F_3 ( V_3 , V_90 , V_3 -> V_29 ) ;
return 0 ;
}
static int F_133 ( struct V_220 * V_221 ,
struct V_222 * V_223 )
{
static const char * const V_248 [] = { L_34 , L_35 , L_36 } ;
F_83 ( V_223 , V_248 ) ;
return 0 ;
}
static int F_134 ( struct V_220 * V_221 ,
struct V_230 * V_231 )
{
struct V_3 * V_3 = F_77 ( V_221 ) ;
F_36 ( & V_3 -> V_25 ) ;
V_231 -> V_226 . V_232 . V_233 [ 0 ] = F_131 ( V_3 ) ;
F_38 ( & V_3 -> V_25 ) ;
return 0 ;
}
static int F_135 ( struct V_220 * V_221 ,
struct V_230 * V_231 )
{
struct V_3 * V_3 = F_77 ( V_221 ) ;
int V_249 ;
int V_8 ;
if ( ! F_13 ( V_3 ) )
return - V_125 ;
V_8 = V_231 -> V_226 . integer . V_226 [ 0 ] ;
if ( V_8 < 0 )
V_8 = 0 ;
if ( V_8 > 2 )
V_8 = 2 ;
F_36 ( & V_3 -> V_25 ) ;
V_249 = V_8 != F_131 ( V_3 ) ;
F_132 ( V_3 , V_8 ) ;
F_38 ( & V_3 -> V_25 ) ;
return V_249 ;
}
static int F_136 ( struct V_220 * V_221 ,
struct V_222 * V_223 )
{
V_223 -> type = V_224 ;
V_223 -> V_225 = 3 ;
V_223 -> V_226 . integer . V_227 = 0 ;
V_223 -> V_226 . integer . V_228 = 65535 ;
V_223 -> V_226 . integer . V_229 = 1 ;
return 0 ;
}
static int F_137 ( struct V_220 * V_221 ,
struct V_230 * V_231 )
{
struct V_3 * V_3 = F_77 ( V_221 ) ;
int V_293 ;
int V_294 ;
V_293 = V_231 -> V_226 . integer . V_226 [ 0 ] ;
if ( V_293 < 0 )
V_293 = 0 ;
else if ( V_293 >= 2 * V_93 )
V_293 = 2 * V_93 - 1 ;
V_294 = V_231 -> V_226 . integer . V_226 [ 1 ] ;
if ( V_294 < 0 )
V_294 = 0 ;
else if ( V_294 >= V_93 )
V_294 = V_93 - 1 ;
F_36 ( & V_3 -> V_25 ) ;
if ( V_293 >= V_93 )
V_231 -> V_226 . integer . V_226 [ 2 ] =
F_8 ( V_3 , V_294 ,
V_293 - V_93 ) ;
else
V_231 -> V_226 . integer . V_226 [ 2 ] =
F_7 ( V_3 , V_294 , V_293 ) ;
F_38 ( & V_3 -> V_25 ) ;
return 0 ;
}
static int F_138 ( struct V_220 * V_221 ,
struct V_230 * V_231 )
{
struct V_3 * V_3 = F_77 ( V_221 ) ;
int V_249 ;
int V_293 ;
int V_294 ;
int V_154 ;
if ( ! F_13 ( V_3 ) )
return - V_125 ;
V_293 = V_231 -> V_226 . integer . V_226 [ 0 ] ;
V_294 = V_231 -> V_226 . integer . V_226 [ 1 ] ;
if ( V_293 < 0 || V_293 >= 2 * V_93 )
return - 1 ;
if ( V_294 < 0 || V_294 >= V_93 )
return - 1 ;
V_154 = V_231 -> V_226 . integer . V_226 [ 2 ] ;
F_36 ( & V_3 -> V_25 ) ;
if ( V_293 >= V_93 )
V_249 = V_154 != F_8 ( V_3 , V_294 ,
V_293 -
V_93 ) ;
else
V_249 = V_154 != F_7 ( V_3 , V_294 ,
V_293 ) ;
if ( V_249 ) {
if ( V_293 >= V_93 )
F_10 ( V_3 , V_294 ,
V_293 - V_93 ,
V_154 ) ;
else
F_9 ( V_3 , V_294 , V_293 ,
V_154 ) ;
}
F_38 ( & V_3 -> V_25 ) ;
return V_249 ;
}
static int F_139 ( struct V_220 * V_221 ,
struct V_222 * V_223 )
{
V_223 -> type = V_224 ;
V_223 -> V_225 = 1 ;
V_223 -> V_226 . integer . V_227 = 0 ;
V_223 -> V_226 . integer . V_228 = 64 ;
V_223 -> V_226 . integer . V_229 = 1 ;
return 0 ;
}
static int F_140 ( struct V_220 * V_221 ,
struct V_230 * V_231 )
{
struct V_3 * V_3 = F_77 ( V_221 ) ;
int V_295 ;
V_295 = V_231 -> V_156 . V_238 - 1 ;
if ( F_43 ( V_295 < 0 || V_295 >= V_93 ) )
return - V_123 ;
F_36 ( & V_3 -> V_25 ) ;
V_231 -> V_226 . integer . V_226 [ 0 ] =
( F_8 ( V_3 , V_295 , V_295 ) * 64 ) / V_155 ;
F_38 ( & V_3 -> V_25 ) ;
return 0 ;
}
static int F_141 ( struct V_220 * V_221 ,
struct V_230 * V_231 )
{
struct V_3 * V_3 = F_77 ( V_221 ) ;
int V_249 ;
int V_295 ;
int V_154 ;
if ( ! F_13 ( V_3 ) )
return - V_125 ;
V_295 = V_231 -> V_156 . V_238 - 1 ;
if ( F_43 ( V_295 < 0 || V_295 >= V_93 ) )
return - V_123 ;
V_154 = V_231 -> V_226 . integer . V_226 [ 0 ] * V_155 / 64 ;
F_36 ( & V_3 -> V_25 ) ;
V_249 =
V_154 != F_8 ( V_3 , V_295 ,
V_295 ) ;
if ( V_249 )
F_10 ( V_3 , V_295 , V_295 ,
V_154 ) ;
F_38 ( & V_3 -> V_25 ) ;
return V_249 ;
}
static int F_142 ( struct V_220 * V_221 ,
struct V_222 * V_223 )
{
static const char * const V_248 [] = { L_43 , L_44 , L_45 , L_46 } ;
F_83 ( V_223 , V_248 ) ;
return 0 ;
}
static int F_143 ( struct V_220 * V_221 ,
struct V_222 * V_223 )
{
static const char * const V_248 [] = { L_43 , L_44 } ;
F_83 ( V_223 , V_248 ) ;
return 0 ;
}
static int F_20 ( struct V_3 * V_3 )
{
int V_32 , V_33 ;
switch ( V_3 -> V_5 ) {
case V_36 :
V_32 = F_5 ( V_3 , V_38 ) ;
if ( V_32 & V_296 ) {
if ( V_32 & V_297 )
return 2 ;
else
return 1 ;
}
return 0 ;
break;
case V_53 :
V_33 = F_5 ( V_3 , V_37 ) ;
if ( V_33 & V_54 ) {
if ( V_33 & V_298 )
return 2 ;
else
return 1 ;
}
return 0 ;
break;
case V_6 :
case V_4 :
V_32 = F_5 ( V_3 , V_38 ) ;
if ( V_32 & 0x2000000 )
return 2 ;
else if ( V_32 & 0x1000000 )
return 1 ;
return 0 ;
break;
case V_49 :
break;
}
return 3 ;
}
static int F_144 ( struct V_3 * V_3 )
{
int V_32 = F_5 ( V_3 , V_38 ) ;
if ( V_32 & V_50 ) {
if ( V_32 & V_299 )
return 2 ;
else
return 1 ;
}
return 0 ;
}
static int F_145 ( struct V_3 * V_3 , int V_241 )
{
int V_32 , V_25 , V_300 ;
V_32 = F_5 ( V_3 , V_234 ) ;
V_25 = ( V_32 & ( 0x1 << V_241 ) ) ? 1 : 0 ;
V_300 = ( V_32 & ( 0x100 << V_241 ) ) ? 1 : 0 ;
if ( V_25 && V_300 )
return 2 ;
else if ( V_25 )
return 1 ;
return 0 ;
}
static int F_26 ( struct V_3 * V_3 )
{
int V_32 , V_25 = 0 , V_300 = 0 ;
switch ( V_3 -> V_5 ) {
case V_6 :
case V_4 :
V_32 = F_5 ( V_3 , V_301 ) ;
V_25 = ( V_32 & 0x400 ) ? 1 : 0 ;
V_300 = ( V_32 & 0x800 ) ? 1 : 0 ;
break;
case V_53 :
V_32 = F_5 ( V_3 , V_38 ) ;
V_25 = ( V_32 & V_302 ) ? 1 : 0 ;
V_300 = ( V_32 & V_303 ) ? 1 : 0 ;
break;
case V_36 :
V_32 = F_5 ( V_3 , V_37 ) ;
V_25 = ( V_32 & 0x100000 ) ? 1 : 0 ;
V_300 = ( V_32 & 0x200000 ) ? 1 : 0 ;
break;
case V_49 :
break;
}
if ( V_25 && V_300 )
return 2 ;
else if ( V_25 )
return 1 ;
return 0 ;
}
static int F_22 ( struct V_3 * V_3 , int V_241 )
{
int V_33 , V_25 , V_300 ;
V_33 = F_5 ( V_3 , V_37 ) ;
V_25 = ( V_33 & ( 0x0080 >> V_241 ) ) ? 1 : 0 ;
V_300 = ( V_33 & ( 0x8000 >> V_241 ) ) ? 1 : 0 ;
if ( V_300 )
return 2 ;
else if ( V_25 )
return 1 ;
return 0 ;
}
static int F_146 ( struct V_3 * V_3 , V_18 V_304 )
{
V_18 V_32 ;
V_32 = F_5 ( V_3 , V_272 + 4 ) ;
return ( V_32 & V_304 ) ? 1 : 0 ;
}
static int F_24 ( struct V_3 * V_3 )
{
int V_32 ;
if ( V_3 -> V_236 ) {
switch ( V_3 -> V_5 ) {
case V_53 :
V_32 = F_5 ( V_3 , V_38 ) ;
if ( V_32 & V_305 ) {
if ( V_32 & V_306 )
return 2 ;
else
return 1 ;
}
return 0 ;
case V_36 :
V_32 = F_5 ( V_3 , V_38 ) ;
if ( V_32 & V_307 ) {
if ( V_32 & V_306 )
return 2 ;
else
return 1 ;
}
return 0 ;
case V_6 :
case V_4 :
V_32 = F_5 ( V_3 , V_234 ) ;
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
static int F_147 ( struct V_220 * V_221 ,
struct V_230 * V_231 )
{
struct V_3 * V_3 = F_77 ( V_221 ) ;
int V_8 = - 1 ;
switch ( V_3 -> V_5 ) {
case V_6 :
switch ( V_221 -> V_244 ) {
case 0 :
V_8 = F_20 ( V_3 ) ; break;
case 7 :
V_8 = F_24 ( V_3 ) ; break;
case 8 :
V_8 = F_26 ( V_3 ) ; break;
default:
V_8 = F_145 ( V_3 ,
V_221 -> V_244 - 1 ) ;
}
break;
case V_4 :
switch ( V_221 -> V_244 ) {
case 0 :
V_8 = F_20 ( V_3 ) ; break;
case 4 :
V_8 = F_24 ( V_3 ) ; break;
case 5 :
V_8 = F_26 ( V_3 ) ; break;
default:
V_8 = F_145 ( V_3 ,
V_221 -> V_244 - 1 ) ;
}
break;
case V_53 :
switch ( V_221 -> V_244 ) {
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
case V_49 :
V_8 = F_144 ( V_3 ) ;
break;
case V_36 :
switch ( V_221 -> V_244 ) {
case 0 :
V_8 = F_20 ( V_3 ) ; break;
case 9 :
V_8 = F_24 ( V_3 ) ; break;
case 10 :
V_8 = F_26 ( V_3 ) ; break;
default:
V_8 = F_22 ( V_3 ,
V_221 -> V_244 - 1 ) ;
}
break;
}
if ( V_3 -> V_236 ) {
switch ( V_221 -> V_244 ) {
case 11 :
V_8 = F_146 ( V_3 , V_308 ) ;
break;
case 12 :
V_8 = F_146 ( V_3 ,
V_275 ) ;
break;
default:
break;
}
}
if ( - 1 == V_8 )
V_8 = 3 ;
V_231 -> V_226 . V_232 . V_233 [ 0 ] = V_8 ;
return 0 ;
}
static void F_148 ( struct V_3 * V_3 )
{
unsigned int V_309 [ 4 ] = { 0 , 0 , 0 , 0 } ;
switch ( V_3 -> V_236 -> V_168 ) {
case 0 :
V_309 [ 2 ] |= V_310 ;
break;
case 1 :
V_309 [ 2 ] |= V_311 ;
break;
default:
break;
}
switch ( V_3 -> V_236 -> V_312 ) {
case 1 :
V_309 [ 1 ] |= V_276 ;
break;
case 2 :
V_309 [ 1 ] |= V_277 ;
break;
case 3 :
V_309 [ 1 ] |= V_277 +
V_313 ;
break;
case 4 :
V_309 [ 1 ] |= V_276 +
V_277 ;
break;
case 5 :
V_309 [ 1 ] |= V_276 +
V_277 +
V_313 ;
break;
default:
break;
}
switch ( V_3 -> V_236 -> V_314 ) {
case 1 :
V_309 [ 2 ] |= V_315 ;
break;
case 2 :
V_309 [ 2 ] |= V_316 ;
break;
default:
break;
}
switch ( V_3 -> V_236 -> V_317 ) {
case 1 :
V_309 [ 2 ] |= V_318 ;
break;
case 2 :
V_309 [ 2 ] |= V_319 ;
break;
default:
break;
}
switch ( V_3 -> V_236 -> V_320 ) {
case 1 :
V_309 [ 2 ] |= V_321 ;
break;
case 2 :
V_309 [ 2 ] |= V_322 ;
break;
case 3 :
V_309 [ 2 ] |= V_321 + V_323 ;
break;
case 4 :
V_309 [ 2 ] |= V_322 + V_323 ;
break;
default:
break;
}
if ( 1 == V_3 -> V_236 -> V_324 ) {
V_309 [ 2 ] |= V_325 ;
}
F_3 ( V_3 , V_326 , V_309 [ 0 ] ) ;
F_3 ( V_3 , V_326 + 4 , V_309 [ 1 ] ) ;
F_3 ( V_3 , V_326 + 8 , V_309 [ 2 ] ) ;
F_3 ( V_3 , V_326 + 12 , V_309 [ 3 ] ) ;
}
static int F_149 ( struct V_220 * V_221 ,
struct V_222 * V_223 )
{
static const char * const V_248 [] = { L_47 , L_48 } ;
F_83 ( V_223 , V_248 ) ;
return 0 ;
}
static int F_150 ( struct V_220 * V_221 ,
struct V_230 * V_231 )
{
struct V_3 * V_3 = F_77 ( V_221 ) ;
V_231 -> V_226 . V_232 . V_233 [ 0 ] = V_3 -> V_236 -> V_317 ;
return 0 ;
}
static int F_151 ( struct V_220 * V_221 ,
struct V_230 * V_231 )
{
struct V_3 * V_3 = F_77 ( V_221 ) ;
if ( V_3 -> V_236 -> V_317 != V_231 -> V_226 . V_232 . V_233 [ 0 ] ) {
V_3 -> V_236 -> V_317 = V_231 -> V_226 . V_232 . V_233 [ 0 ] ;
F_148 ( V_3 ) ;
return 1 ;
}
return 0 ;
}
static int F_152 ( struct V_220 * V_221 ,
struct V_222 * V_223 )
{
static const char * const V_248 [] = { L_49 , L_50 , L_51 ,
L_52 , L_53 } ;
F_83 ( V_223 , V_248 ) ;
return 0 ;
}
static int F_153 ( struct V_220 * V_221 ,
struct V_230 * V_231 )
{
struct V_3 * V_3 = F_77 ( V_221 ) ;
V_231 -> V_226 . V_232 . V_233 [ 0 ] = V_3 -> V_236 -> V_320 ;
return 0 ;
}
static int F_154 ( struct V_220 * V_221 ,
struct V_230 * V_231 )
{
struct V_3 * V_3 = F_77 ( V_221 ) ;
if ( V_3 -> V_236 -> V_320 != V_231 -> V_226 . V_232 . V_233 [ 0 ] ) {
V_3 -> V_236 -> V_320 = V_231 -> V_226 . V_232 . V_233 [ 0 ] ;
F_148 ( V_3 ) ;
return 1 ;
}
return 0 ;
}
static int F_155 ( struct V_220 * V_221 ,
struct V_222 * V_223 )
{
static const char * const V_248 [] = { L_54 , L_55 , L_56 } ;
F_83 ( V_223 , V_248 ) ;
return 0 ;
}
static int F_156 ( struct V_220 * V_221 ,
struct V_230 * V_231 )
{
struct V_3 * V_3 = F_77 ( V_221 ) ;
V_231 -> V_226 . V_232 . V_233 [ 0 ] = V_3 -> V_236 -> V_314 ;
return 0 ;
}
static int F_157 ( struct V_220 * V_221 ,
struct V_230 * V_231 )
{
struct V_3 * V_3 = F_77 ( V_221 ) ;
if ( V_3 -> V_236 -> V_314 != V_231 -> V_226 . V_232 . V_233 [ 0 ] ) {
V_3 -> V_236 -> V_314 = V_231 -> V_226 . V_232 . V_233 [ 0 ] ;
F_148 ( V_3 ) ;
return 1 ;
}
return 0 ;
}
static int F_158 ( struct V_220 * V_221 ,
struct V_222 * V_223 )
{
static const char * const V_248 [] = { L_28 , L_29 , L_57 ,
L_58 , L_31 , L_59 } ;
F_83 ( V_223 , V_248 ) ;
return 0 ;
}
static int F_159 ( struct V_220 * V_221 ,
struct V_230 * V_231 )
{
struct V_3 * V_3 = F_77 ( V_221 ) ;
V_231 -> V_226 . V_232 . V_233 [ 0 ] = V_3 -> V_236 -> V_312 ;
return 0 ;
}
static int F_160 ( struct V_220 * V_221 ,
struct V_230 * V_231 )
{
struct V_3 * V_3 = F_77 ( V_221 ) ;
if ( V_3 -> V_236 -> V_312 != V_231 -> V_226 . V_232 . V_233 [ 0 ] ) {
V_3 -> V_236 -> V_312 = V_231 -> V_226 . V_232 . V_233 [ 0 ] ;
F_148 ( V_3 ) ;
return 1 ;
}
return 0 ;
}
static int F_161 ( struct V_220 * V_221 ,
struct V_222 * V_223 )
{
static const char * const V_248 [] = { L_60 , L_61 , L_62 } ;
F_83 ( V_223 , V_248 ) ;
return 0 ;
}
static int F_162 ( struct V_220 * V_221 ,
struct V_230 * V_231 )
{
struct V_3 * V_3 = F_77 ( V_221 ) ;
V_231 -> V_226 . V_232 . V_233 [ 0 ] = V_3 -> V_236 -> V_168 ;
return 0 ;
}
static int F_163 ( struct V_220 * V_221 ,
struct V_230 * V_231 )
{
struct V_3 * V_3 = F_77 ( V_221 ) ;
if ( V_3 -> V_236 -> V_168 != V_231 -> V_226 . V_232 . V_233 [ 0 ] ) {
V_3 -> V_236 -> V_168 = V_231 -> V_226 . V_232 . V_233 [ 0 ] ;
F_148 ( V_3 ) ;
return 1 ;
}
return 0 ;
}
static int F_164 ( struct V_220 * V_221 ,
struct V_222 * V_223 )
{
V_223 -> type = V_327 ;
V_223 -> V_225 = 1 ;
V_223 -> V_226 . integer . V_227 = 0 ;
V_223 -> V_226 . integer . V_228 = 1 ;
return 0 ;
}
static int F_165 ( struct V_220 * V_221 ,
struct V_230 * V_231 )
{
struct V_3 * V_3 = F_77 ( V_221 ) ;
V_231 -> V_226 . V_232 . V_233 [ 0 ] = V_3 -> V_236 -> V_324 ;
return 0 ;
}
static int F_166 ( struct V_220 * V_221 ,
struct V_230 * V_231 )
{
struct V_3 * V_3 = F_77 ( V_221 ) ;
if ( V_3 -> V_236 -> V_324 != V_231 -> V_226 . V_232 . V_233 [ 0 ] ) {
V_3 -> V_236 -> V_324 = V_231 -> V_226 . V_232 . V_233 [ 0 ] ;
F_148 ( V_3 ) ;
return 1 ;
}
return 0 ;
}
static int F_167 ( struct V_3 * V_3 )
{
int V_19 ;
for ( V_19 = V_3 -> V_143 ; V_19 < V_3 -> V_135 ; ++ V_19 ) {
if ( V_3 -> V_110 > 48000 ) {
V_3 -> V_328 [ V_19 ] -> V_329 [ 0 ] . V_330 =
V_331 |
V_332 |
V_333 ;
} else {
V_3 -> V_328 [ V_19 ] -> V_329 [ 0 ] . V_330 =
V_334 |
V_333 ;
}
F_168 ( V_3 -> V_106 , V_335 |
V_336 ,
& V_3 -> V_328 [ V_19 ] -> V_156 ) ;
}
return 0 ;
}
static int F_169 ( struct V_181 * V_106 ,
struct V_3 * V_3 )
{
unsigned int V_241 , V_337 ;
int V_182 ;
struct V_220 * V_338 ;
struct V_339 * V_340 = NULL ;
switch ( V_3 -> V_5 ) {
case V_53 :
V_340 = V_341 ;
V_337 = F_170 ( V_341 ) ;
break;
case V_49 :
V_340 = V_342 ;
V_337 = F_170 ( V_342 ) ;
break;
case V_4 :
V_340 = V_343 ;
V_337 = F_170 ( V_343 ) ;
break;
case V_6 :
V_340 = V_344 ;
V_337 = F_170 ( V_344 ) ;
break;
case V_36 :
V_340 = V_345 ;
V_337 = F_170 ( V_345 ) ;
break;
}
if ( NULL != V_340 ) {
for ( V_241 = 0 ; V_241 < V_337 ; V_241 ++ ) {
V_182 = F_171 ( V_106 ,
F_172 ( & V_340 [ V_241 ] , V_3 ) ) ;
if ( V_182 < 0 )
return V_182 ;
}
}
V_346 . V_208 = L_63 ;
if ( V_3 -> V_110 >= 128000 ) {
V_337 = V_3 -> V_149 ;
} else if ( V_3 -> V_110 >= 64000 ) {
V_337 = V_3 -> V_143 ;
} else {
V_337 = V_3 -> V_135 ;
}
for ( V_241 = 0 ; V_241 < V_337 ; ++ V_241 ) {
V_346 . V_238 = V_241 + 1 ;
V_338 = F_172 ( & V_346 , V_3 ) ;
V_182 = F_171 ( V_106 , V_338 ) ;
if ( V_182 < 0 )
return V_182 ;
V_3 -> V_328 [ V_241 ] = V_338 ;
}
if ( V_3 -> V_236 ) {
V_340 = V_347 ;
V_337 = F_170 ( V_347 ) ;
for ( V_241 = 0 ; V_241 < V_337 ; V_241 ++ ) {
V_182 = F_171 ( V_106 ,
F_172 ( & V_340 [ V_241 ] , V_3 ) ) ;
if ( V_182 < 0 )
return V_182 ;
}
}
return 0 ;
}
static void
F_173 ( struct V_348 * V_349 ,
struct V_350 * V_351 )
{
struct V_3 * V_3 = V_349 -> V_175 ;
unsigned int V_32 , V_352 ;
int V_353 , V_354 , V_95 , V_355 , V_356 , V_357 ;
unsigned int V_97 ;
T_2 V_98 = 0 ;
V_18 V_28 ;
F_174 ( V_351 , L_64 ) ;
V_32 = F_5 ( V_3 , V_38 ) ;
V_352 = V_3 -> V_29 ;
if ( V_32 & V_358 ) {
F_174 ( V_351 , L_65 ) ;
V_353 = F_5 ( V_3 , V_272 + 4 ) ;
if ( V_353 & V_275 ) {
F_174 ( V_351 , L_66 ) ;
switch ( V_353 & ( V_276 |
V_277 ) ) {
case 0 :
F_174 ( V_351 , L_67 ) ;
break;
case V_276 :
F_174 ( V_351 , L_68 ) ;
break;
case V_277 :
F_174 ( V_351 , L_69 ) ;
break;
default:
F_174 ( V_351 , L_70 ) ;
break;
}
if ( V_353 & V_313 ) {
F_174 ( V_351 , L_71 ) ;
} else {
F_174 ( V_351 , L_72 ) ;
}
} else {
F_174 ( V_351 , L_73 ) ;
}
if ( V_353 & V_273 ) {
F_174 ( V_351 , L_74 ) ;
} else if ( V_353 & V_274 ) {
F_174 ( V_351 , L_75 ) ;
} else {
F_174 ( V_351 , L_76 ) ;
}
if ( V_353 & V_308 ) {
F_174 ( V_351 , L_77 ) ;
} else {
F_174 ( V_351 , L_78 ) ;
}
switch ( V_3 -> V_5 ) {
case V_53 :
case V_36 :
V_98 = 110069313433624ULL ;
break;
case V_6 :
case V_4 :
V_98 = 104857600000000ULL ;
break;
case V_49 :
break;
}
V_97 = F_5 ( V_3 , V_219 ) ;
F_174 ( V_351 , L_79 , V_97 ) ;
V_28 = F_41 ( V_98 , V_97 ) ;
if ( V_352 & V_30 ) {
V_28 *= 4 ;
} else if ( V_352 & V_31 ) {
V_28 *= 2 ;
}
F_174 ( V_351 , L_80 ,
( unsigned int ) V_28 ) ;
V_354 = F_5 ( V_3 , V_272 ) ;
V_95 = V_354 & 0xF ;
V_354 >>= 4 ;
V_95 += ( V_354 & 0x3 ) * 10 ;
V_354 >>= 4 ;
V_355 = V_354 & 0xF ;
V_354 >>= 4 ;
V_355 += ( V_354 & 0x7 ) * 10 ;
V_354 >>= 4 ;
V_356 = V_354 & 0xF ;
V_354 >>= 4 ;
V_356 += ( V_354 & 0x7 ) * 10 ;
V_354 >>= 4 ;
V_357 = V_354 & 0xF ;
V_354 >>= 4 ;
V_357 += ( V_354 & 0x3 ) * 10 ;
F_174 ( V_351 ,
L_81 ,
V_357 , V_356 , V_355 , V_95 ) ;
} else {
F_174 ( V_351 , L_82 ) ;
}
}
static void
F_175 ( struct V_348 * V_349 ,
struct V_350 * V_351 )
{
struct V_3 * V_3 = V_349 -> V_175 ;
unsigned int V_32 , V_33 ;
char * V_359 ;
char * V_360 ;
char * V_361 ;
int V_362 , V_363 ;
V_32 = F_5 ( V_3 , V_38 ) ;
V_33 = F_5 ( V_3 , V_37 ) ;
F_174 ( V_351 , L_83 ,
V_3 -> V_364 , V_3 -> V_106 -> V_365 + 1 ,
V_3 -> V_366 ,
( V_33 & V_367 ) |
( V_33 & V_368 ) | ( V_33 &
V_369 ) ) ;
F_174 ( V_351 , L_84 ,
( F_5 ( V_3 , V_197 ) >> 8 ) & 0xFFFFFF ,
V_3 -> V_370 ) ;
F_174 ( V_351 , L_85 ,
V_3 -> V_188 , V_3 -> V_371 , ( unsigned long ) V_3 -> V_9 ) ;
F_174 ( V_351 , L_86 ) ;
F_174 ( V_351 ,
L_87 ,
V_32 & V_372 ,
( V_32 & V_195 ) ? 1 : 0 ,
( V_32 & V_201 ) ? 1 : 0 ,
V_3 -> V_373 ) ;
F_174 ( V_351 ,
L_88
L_89 ,
( ( V_32 & V_86 ) ? 1 : 0 ) ,
( V_32 & V_85 ) ,
( V_32 & V_85 ) %
( 2 * ( int ) V_3 -> V_83 ) ,
( ( V_32 & V_85 ) - 64 ) %
( 2 * ( int ) V_3 -> V_83 ) ,
( long ) F_31 ( V_3 ) * 4 ) ;
F_174 ( V_351 ,
L_90 ,
F_5 ( V_3 , V_193 ) & 0xFF ,
F_5 ( V_3 , V_199 ) & 0xFF ,
F_5 ( V_3 , V_191 ) & 0xFF ,
F_5 ( V_3 , V_197 ) & 0xFF ) ;
F_174 ( V_351 ,
L_91 ,
F_5 ( V_3 , V_184 ) & 0xFF ,
F_5 ( V_3 , V_186 ) & 0xFF ) ;
F_174 ( V_351 ,
L_92
L_93 ,
V_3 -> V_29 , V_3 -> V_374 ,
V_32 , V_33 ) ;
F_174 ( V_351 , L_94 ) ;
V_362 = F_28 ( V_3 ) ;
F_174 ( V_351 ,
L_95 ,
V_362 , ( unsigned long ) V_3 -> V_83 ) ;
F_174 ( V_351 , L_96 ,
( V_3 -> V_29 & V_375 ) ? L_97 : L_98 ) ;
F_174 ( V_351 ,
L_99
L_100 ,
( V_3 -> V_29 & V_376 ) ? L_101 : L_98 ,
( V_3 -> V_29 & V_377 ) ? L_102 : L_103 ,
( V_3 -> V_29 & V_378 ) ? L_101 : L_98 ) ;
if ( ! ( V_3 -> V_29 & V_105 ) )
V_361 = L_9 ;
else
V_361 = L_8 ;
F_174 ( V_351 , L_104 , V_361 ) ;
switch ( F_96 ( V_3 ) ) {
case V_379 :
V_359 = L_22 ;
break;
case V_380 :
V_359 = L_105 ;
break;
case V_381 :
V_359 = L_19 ;
break;
case V_382 :
V_359 = L_20 ;
break;
default:
V_359 = L_106 ;
break;
}
F_174 ( V_351 , L_107 ,
V_359 ) ;
F_174 ( V_351 , L_108 ,
V_3 -> V_110 ) ;
F_174 ( V_351 , L_109 ) ;
V_362 = V_32 & V_299 ;
V_363 = V_33 & V_298 ;
F_174 ( V_351 , L_110 ,
( V_32 & V_50 ) ? ( V_362 ? L_45 : L_44 ) :
L_111 ,
( V_33 & V_54 ) ? ( V_363 ? L_45 : L_44 ) :
L_111 ) ;
switch ( F_19 ( V_3 ) ) {
case V_82 :
V_360 = L_20 ;
break;
case V_80 :
V_360 = L_19 ;
break;
case V_266 :
V_360 = L_22 ;
break;
case V_268 :
V_360 = L_105 ;
break;
case V_109 :
V_360 = L_112 ;
break;
default:
V_360 = L_113 ;
break;
}
F_174 ( V_351 ,
L_114 ,
V_360 , F_18 ( V_3 ) ,
( V_32 & V_68 ) >> 22 ,
( V_33 & V_56 ) >> 5 ) ;
F_174 ( V_351 , L_115 ,
( V_32 & V_383 ) ? L_116 : L_37 ,
( V_32 & V_384 ) ? L_117 :
L_118 ) ;
F_173 ( V_349 , V_351 ) ;
F_174 ( V_351 , L_119 ) ;
}
static void
F_176 ( struct V_348 * V_349 ,
struct V_350 * V_351 )
{
struct V_3 * V_3 = V_349 -> V_175 ;
unsigned int V_32 ;
unsigned int V_33 ;
unsigned int V_239 ;
unsigned int V_385 , V_386 ;
int V_387 ;
char * V_360 ;
int V_362 ;
V_32 = F_5 ( V_3 , V_38 ) ;
V_33 = F_5 ( V_3 , V_37 ) ;
V_239 = F_5 ( V_3 , V_240 ) ;
F_174 ( V_351 , L_120 ,
V_3 -> V_364 , V_3 -> V_106 -> V_365 + 1 ,
V_3 -> V_366 ) ;
F_174 ( V_351 , L_85 ,
V_3 -> V_188 , V_3 -> V_371 , ( unsigned long ) V_3 -> V_9 ) ;
F_174 ( V_351 , L_86 ) ;
F_174 ( V_351 ,
L_87 ,
V_32 & V_372 ,
( V_32 & V_195 ) ? 1 : 0 ,
( V_32 & V_201 ) ? 1 : 0 ,
V_3 -> V_373 ) ;
F_174 ( V_351 ,
L_88
L_89 ,
( ( V_32 & V_86 ) ? 1 : 0 ) ,
( V_32 & V_85 ) ,
( V_32 & V_85 ) %
( 2 * ( int ) V_3 -> V_83 ) ,
( ( V_32 & V_85 ) - 64 ) %
( 2 * ( int ) V_3 -> V_83 ) ,
( long ) F_31 ( V_3 ) * 4 ) ;
F_174 ( V_351 ,
L_90 ,
F_5 ( V_3 , V_193 ) & 0xFF ,
F_5 ( V_3 , V_199 ) & 0xFF ,
F_5 ( V_3 , V_191 ) & 0xFF ,
F_5 ( V_3 , V_197 ) & 0xFF ) ;
F_174 ( V_351 ,
L_91 ,
F_5 ( V_3 , V_184 ) & 0xFF ,
F_5 ( V_3 , V_186 ) & 0xFF ) ;
F_174 ( V_351 ,
L_92
L_93 ,
V_3 -> V_29 , V_3 -> V_374 ,
V_32 , V_33 ) ;
F_174 ( V_351 , L_94 ) ;
V_362 = F_28 ( V_3 ) ;
F_174 ( V_351 ,
L_95 ,
V_362 , ( unsigned long ) V_3 -> V_83 ) ;
F_174 ( V_351 , L_96 ,
( V_3 ->
V_29 & V_375 ) ? L_97 : L_98 ) ;
F_174 ( V_351 ,
L_121 ,
( V_3 ->
V_29 & V_376 ) ? L_101 : L_98 ,
( V_3 ->
V_29 & V_388 ) ? L_101 : L_98 ,
( V_3 ->
V_29 & V_389 ) ? L_101 : L_98 ) ;
V_387 = F_96 ( V_3 ) ;
if ( V_387 == 0 )
F_174 ( V_351 , L_122 ) ;
else
F_174 ( V_351 , L_123 ,
V_387 ) ;
F_174 ( V_351 , L_108 ,
V_3 -> V_110 ) ;
F_174 ( V_351 , L_124 ,
V_3 -> V_29 & V_286 ?
L_125 : L_126 ) ;
F_174 ( V_351 , L_127 ,
V_3 -> V_29 & V_288 ?
L_125 :
V_3 -> V_29 & V_289 ?
L_128 : L_126 ) ;
F_174 ( V_351 , L_109 ) ;
V_385 = V_32 & V_296 ;
V_386 = V_385 && ( V_32 & V_297 ) ;
F_174 ( V_351 , L_129 ,
( V_385 ) ? ( V_386 ? L_130 : L_131 ) : L_43 ,
F_1 ( ( V_32 >> V_235 ) & 0xF ) ) ;
for ( V_362 = 0 ; V_362 < 8 ; V_362 ++ ) {
F_174 ( V_351 , L_132 ,
V_362 + 1 ,
( V_33 & ( V_390 >> V_362 ) ) ?
L_130 : L_43 ,
F_1 ( ( V_239 >> ( 4 * V_362 ) ) & 0xF ) ) ;
}
switch ( F_19 ( V_3 ) ) {
case V_265 :
V_360 = L_21 ; break;
case V_39 :
V_360 = L_22 ; break;
case V_40 :
V_360 = L_11 ; break;
case V_41 :
V_360 = L_12 ; break;
case V_42 :
V_360 = L_13 ; break;
case V_43 :
V_360 = L_14 ; break;
case V_44 :
V_360 = L_15 ; break;
case V_45 :
V_360 = L_16 ; break;
case V_46 :
V_360 = L_17 ; break;
case V_47 :
V_360 = L_18 ; break;
case V_48 :
V_360 = L_19 ; break;
case V_264 :
V_360 = L_20 ; break;
default:
V_360 = L_113 ; break;
}
F_174 ( V_351 , L_133 , V_360 ) ;
F_173 ( V_349 , V_351 ) ;
F_174 ( V_351 , L_119 ) ;
}
static void
F_177 ( struct V_348 * V_349 ,
struct V_350 * V_351 )
{
struct V_3 * V_3 = V_349 -> V_175 ;
unsigned int V_391 , V_33 , V_392 , V_19 ;
unsigned int V_25 , V_300 ;
V_391 = F_5 ( V_3 , V_234 ) ;
V_33 = F_5 ( V_3 , V_237 ) ;
V_392 = F_5 ( V_3 , V_301 ) ;
F_174 ( V_351 , L_134 , V_391 ) ;
F_174 ( V_351 , L_135 , V_33 ) ;
F_174 ( V_351 , L_136 , V_392 ) ;
F_174 ( V_351 , L_137 ) ;
F_174 ( V_351 , L_138 ,
( F_74 ( V_3 ) == 0 ) ? L_139 : L_140 ) ;
F_174 ( V_351 , L_141 ,
F_73 ( V_3 ) ) ;
F_174 ( V_351 , L_142 ) ;
V_25 = 0x1 ;
V_300 = 0x100 ;
for ( V_19 = 0 ; V_19 < 8 ; V_19 ++ ) {
F_174 ( V_351 , L_143 ,
V_19 ,
( V_391 & V_25 ) ? 1 : 0 ,
( V_391 & V_300 ) ? 1 : 0 ,
V_243 [ ( V_33 >> ( V_19 * 4 ) ) & 0xF ] ) ;
V_25 = V_25 << 1 ;
V_300 = V_300 << 1 ;
}
F_174 ( V_351 , L_144 ,
( V_391 & 0x1000000 ) ? 1 : 0 ,
( V_391 & 0x2000000 ) ? 1 : 0 ,
V_243 [ ( V_391 >> 16 ) & 0xF ] ) ;
F_174 ( V_351 , L_145 ,
( V_391 & 0x4000000 ) ? 1 : 0 ,
( V_391 & 0x8000000 ) ? 1 : 0 ,
V_243 [ ( V_391 >> 20 ) & 0xF ] ) ;
F_174 ( V_351 , L_146 ,
( V_392 & 0x400 ) ? 1 : 0 ,
( V_392 & 0x800 ) ? 1 : 0 ,
V_243 [ ( V_33 >> 12 ) & 0xF ] ) ;
}
static void
F_178 ( struct V_348 * V_349 ,
struct V_350 * V_351 )
{
struct V_3 * V_3 = V_349 -> V_175 ;
int V_153 , V_19 ;
for ( V_19 = 0 ; V_19 < 256 ; V_19 += V_153 ) {
F_174 ( V_351 , L_147 , V_19 ) ;
for ( V_153 = 0 ; V_153 < 16 ; V_153 += 4 )
F_174 ( V_351 , L_148 , F_5 ( V_3 , V_19 + V_153 ) ) ;
F_174 ( V_351 , L_119 ) ;
}
}
static void F_179 ( struct V_348 * V_349 ,
struct V_350 * V_351 )
{
struct V_3 * V_3 = V_349 -> V_175 ;
int V_19 ;
F_174 ( V_351 , L_149 ) ;
for ( V_19 = 0 ; V_19 < V_3 -> V_132 ; V_19 ++ ) {
F_174 ( V_351 , L_150 , V_19 + 1 , V_3 -> V_136 [ V_19 ] ) ;
}
}
static void F_180 ( struct V_348 * V_349 ,
struct V_350 * V_351 )
{
struct V_3 * V_3 = V_349 -> V_175 ;
int V_19 ;
F_174 ( V_351 , L_149 ) ;
for ( V_19 = 0 ; V_19 < V_3 -> V_134 ; V_19 ++ ) {
F_174 ( V_351 , L_150 , V_19 + 1 , V_3 -> V_138 [ V_19 ] ) ;
}
}
static void F_181 ( struct V_3 * V_3 )
{
struct V_348 * V_349 ;
if ( ! F_182 ( V_3 -> V_106 , L_151 , & V_349 ) ) {
switch ( V_3 -> V_5 ) {
case V_36 :
F_183 ( V_349 , V_3 ,
F_176 ) ;
break;
case V_53 :
F_183 ( V_349 , V_3 ,
F_175 ) ;
break;
case V_49 :
break;
case V_6 :
F_183 ( V_349 , V_3 ,
F_177 ) ;
break;
case V_4 :
break;
}
}
if ( ! F_182 ( V_3 -> V_106 , L_152 , & V_349 ) ) {
F_183 ( V_349 , V_3 , F_179 ) ;
}
if ( ! F_182 ( V_3 -> V_106 , L_153 , & V_349 ) ) {
F_183 ( V_349 , V_3 , F_180 ) ;
}
#ifdef F_184
if ( ! F_182 ( V_3 -> V_106 , L_154 , & V_349 ) )
F_183 ( V_349 , V_3 ,
F_178 ) ;
#endif
}
static int F_185 ( struct V_3 * V_3 )
{
V_3 -> V_245 = 0 ;
switch ( V_3 -> V_5 ) {
case V_53 :
case V_49 :
V_3 -> V_29 =
0x2 + 0x8 + 0x10 + 0x80 + 0x400 + 0x4000 + 0x1000000 ;
break;
case V_6 :
case V_4 :
V_3 -> V_245 = 0x1 + 0x1000 ;
V_3 -> V_29 =
0x2 + 0x8 + 0x10 + 0x80 + 0x400 + 0x4000 + 0x1000000 ;
break;
case V_36 :
V_3 -> V_29 =
V_105 |
F_37 ( 7 ) |
V_251 |
V_375 |
V_393 ;
break;
}
F_3 ( V_3 , V_90 , V_3 -> V_29 ) ;
if ( V_36 == V_3 -> V_5 ) {
#ifdef F_186
V_3 -> V_374 = V_394 ;
#else
V_3 -> V_374 = 0 ;
#endif
F_3 ( V_3 , V_395 , V_3 -> V_374 ) ;
}
F_30 ( V_3 ) ;
F_47 ( V_3 , 0 * V_155 ) ;
if ( F_2 ( V_3 ) )
F_3 ( V_3 , V_259 , V_3 -> V_245 ) ;
F_44 ( V_3 , 48000 , 1 ) ;
return 0 ;
}
static T_3 F_187 ( int V_188 , void * V_396 )
{
struct V_3 * V_3 = (struct V_3 * ) V_396 ;
unsigned int V_32 ;
int V_19 , V_397 , V_157 , V_398 = 0 ;
V_32 = F_5 ( V_3 , V_38 ) ;
V_397 = V_32 & V_372 ;
V_157 = V_32 & ( V_195 | V_201 |
V_189 | V_206 ) ;
if ( ! V_397 && ! V_157 )
return V_399 ;
F_3 ( V_3 , V_400 , 0 ) ;
V_3 -> V_373 ++ ;
if ( V_397 ) {
if ( V_3 -> V_401 )
F_188 ( V_3 -> V_401 ) ;
if ( V_3 -> V_402 )
F_188 ( V_3 -> V_402 ) ;
}
if ( V_157 ) {
V_19 = 0 ;
while ( V_19 < V_3 -> V_218 ) {
if ( ( F_5 ( V_3 ,
V_3 -> V_157 [ V_19 ] . V_160 ) & 0xff ) &&
( V_32 & V_3 -> V_157 [ V_19 ] . V_188 ) ) {
V_3 -> V_29 &= ~ V_3 -> V_157 [ V_19 ] . V_170 ;
F_3 ( V_3 , V_90 ,
V_3 -> V_29 ) ;
V_3 -> V_157 [ V_19 ] . V_169 = 1 ;
V_398 = 1 ;
}
V_19 ++ ;
}
if ( V_398 )
F_189 ( & V_3 -> V_403 ) ;
}
return V_404 ;
}
static T_1 F_190 ( struct V_405
* V_172 )
{
struct V_3 * V_3 = F_191 ( V_172 ) ;
return F_31 ( V_3 ) ;
}
static int F_192 ( struct V_405 * V_172 )
{
struct V_406 * V_407 = V_172 -> V_407 ;
struct V_3 * V_3 = F_191 ( V_172 ) ;
struct V_405 * V_408 ;
if ( V_172 -> V_409 == V_410 )
V_408 = V_3 -> V_401 ;
else
V_408 = V_3 -> V_402 ;
if ( V_3 -> V_411 )
V_407 -> V_32 -> V_412 = F_31 ( V_3 ) ;
else
V_407 -> V_32 -> V_412 = 0 ;
if ( V_408 ) {
struct V_405 * V_87 ;
struct V_406 * V_413 = V_408 -> V_407 ;
F_193 (s, substream) {
if ( V_87 == V_408 ) {
V_413 -> V_32 -> V_412 =
V_407 -> V_32 -> V_412 ;
break;
}
}
}
return 0 ;
}
static int F_194 ( struct V_405 * V_172 ,
struct V_414 * V_415 )
{
struct V_3 * V_3 = F_191 ( V_172 ) ;
int V_182 ;
int V_19 ;
T_4 V_416 ;
T_4 V_417 ;
F_36 ( & V_3 -> V_25 ) ;
if ( V_172 -> V_418 -> V_409 == V_410 ) {
V_416 = V_3 -> V_26 ;
V_417 = V_3 -> V_27 ;
} else {
V_416 = V_3 -> V_27 ;
V_417 = V_3 -> V_26 ;
}
if ( V_417 > 0 && V_416 != V_417 ) {
if ( F_195 ( V_415 ) != V_3 -> V_110 ) {
F_38 ( & V_3 -> V_25 ) ;
F_196 ( V_415 ,
V_419 ) ;
return - V_125 ;
}
if ( F_197 ( V_415 ) != V_3 -> V_83 / 4 ) {
F_38 ( & V_3 -> V_25 ) ;
F_196 ( V_415 ,
V_420 ) ;
return - V_125 ;
}
}
F_38 ( & V_3 -> V_25 ) ;
F_36 ( & V_3 -> V_25 ) ;
V_182 = F_44 ( V_3 , F_195 ( V_415 ) , 0 ) ;
if ( V_182 < 0 ) {
F_198 ( V_3 -> V_106 -> V_107 , L_155 , V_182 ) ;
F_38 ( & V_3 -> V_25 ) ;
F_196 ( V_415 ,
V_419 ) ;
return V_182 ;
}
F_38 ( & V_3 -> V_25 ) ;
V_182 = F_35 ( V_3 ,
F_197 ( V_415 ) ) ;
if ( V_182 < 0 ) {
F_198 ( V_3 -> V_106 -> V_107 ,
L_156 , V_182 ) ;
F_196 ( V_415 ,
V_420 ) ;
return V_182 ;
}
V_182 =
F_199 ( V_172 , V_421 ) ;
if ( V_182 < 0 ) {
F_198 ( V_3 -> V_106 -> V_107 ,
L_157 , V_182 ) ;
return V_182 ;
}
if ( V_172 -> V_409 == V_410 ) {
F_200 ( V_3 , V_172 , V_422 ,
F_201 ( V_415 ) ) ;
for ( V_19 = 0 ; V_19 < F_201 ( V_415 ) ; ++ V_19 )
F_12 ( V_3 , V_19 , 1 ) ;
V_3 -> V_92 =
( unsigned char * ) V_172 -> V_407 -> V_423 ;
F_202 ( V_3 -> V_106 -> V_107 ,
L_158 ,
V_3 -> V_92 ) ;
} else {
F_200 ( V_3 , V_172 , V_424 ,
F_201 ( V_415 ) ) ;
for ( V_19 = 0 ; V_19 < F_201 ( V_415 ) ; ++ V_19 )
F_11 ( V_3 , V_19 , 1 ) ;
V_3 -> V_425 =
( unsigned char * ) V_172 -> V_407 -> V_423 ;
F_202 ( V_3 -> V_106 -> V_107 ,
L_159 ,
V_3 -> V_425 ) ;
}
if ( V_3 -> V_5 == V_36 ) {
return 0 ;
}
if ( V_426 == F_203 ( V_415 ) ) {
if ( ! ( V_3 -> V_29 & V_427 ) )
F_198 ( V_3 -> V_106 -> V_107 ,
L_160 ) ;
V_3 -> V_29 |= V_427 ;
} else if ( V_428 == F_203 ( V_415 ) ) {
if ( V_3 -> V_29 & V_427 )
F_198 ( V_3 -> V_106 -> V_107 ,
L_161 ) ;
V_3 -> V_29 &= ~ V_427 ;
}
F_3 ( V_3 , V_90 , V_3 -> V_29 ) ;
return 0 ;
}
static int F_204 ( struct V_405 * V_172 )
{
int V_19 ;
struct V_3 * V_3 = F_191 ( V_172 ) ;
if ( V_172 -> V_409 == V_410 ) {
for ( V_19 = 0 ; V_19 < V_3 -> V_134 ; ++ V_19 )
F_12 ( V_3 , V_19 , 0 ) ;
V_3 -> V_92 = NULL ;
} else {
for ( V_19 = 0 ; V_19 < V_3 -> V_132 ; ++ V_19 )
F_11 ( V_3 , V_19 , 0 ) ;
V_3 -> V_425 = NULL ;
}
F_205 ( V_172 ) ;
return 0 ;
}
static int F_206 ( struct V_405 * V_172 ,
struct V_429 * V_430 )
{
struct V_3 * V_3 = F_191 ( V_172 ) ;
if ( V_172 -> V_409 == V_410 ) {
if ( F_43 ( V_430 -> V_295 >= V_3 -> V_134 ) ) {
F_198 ( V_3 -> V_106 -> V_107 ,
L_162 ,
V_430 -> V_295 ) ;
return - V_123 ;
}
if ( V_3 -> V_130 [ V_430 -> V_295 ] < 0 ) {
F_198 ( V_3 -> V_106 -> V_107 ,
L_163 ,
V_430 -> V_295 ) ;
return - V_123 ;
}
V_430 -> V_431 = V_3 -> V_130 [ V_430 -> V_295 ] *
V_94 ;
} else {
if ( F_43 ( V_430 -> V_295 >= V_3 -> V_132 ) ) {
F_198 ( V_3 -> V_106 -> V_107 ,
L_164 ,
V_430 -> V_295 ) ;
return - V_123 ;
}
if ( V_3 -> V_128 [ V_430 -> V_295 ] < 0 ) {
F_198 ( V_3 -> V_106 -> V_107 ,
L_165 ,
V_430 -> V_295 ) ;
return - V_123 ;
}
V_430 -> V_431 = V_3 -> V_128 [ V_430 -> V_295 ] *
V_94 ;
}
V_430 -> V_432 = 0 ;
V_430 -> V_229 = 32 ;
return 0 ;
}
static int F_207 ( struct V_405 * V_172 ,
unsigned int V_433 , void * V_217 )
{
switch ( V_433 ) {
case V_434 :
return F_192 ( V_172 ) ;
case V_435 :
{
struct V_429 * V_430 = V_217 ;
return F_206 ( V_172 , V_430 ) ;
}
default:
break;
}
return F_208 ( V_172 , V_433 , V_217 ) ;
}
static int F_209 ( struct V_405 * V_172 , int V_433 )
{
struct V_3 * V_3 = F_191 ( V_172 ) ;
struct V_405 * V_408 ;
int V_411 ;
F_210 ( & V_3 -> V_25 ) ;
V_411 = V_3 -> V_411 ;
switch ( V_433 ) {
case V_436 :
V_411 |= 1 << V_172 -> V_409 ;
break;
case V_437 :
V_411 &= ~ ( 1 << V_172 -> V_409 ) ;
break;
default:
F_40 () ;
F_211 ( & V_3 -> V_25 ) ;
return - V_123 ;
}
if ( V_172 -> V_409 == V_410 )
V_408 = V_3 -> V_401 ;
else
V_408 = V_3 -> V_402 ;
if ( V_408 ) {
struct V_405 * V_87 ;
F_193 (s, substream) {
if ( V_87 == V_408 ) {
F_212 ( V_87 , V_172 ) ;
if ( V_433 == V_436 )
V_411 |= 1 << V_87 -> V_409 ;
else
V_411 &= ~ ( 1 << V_87 -> V_409 ) ;
goto V_438;
}
}
if ( V_433 == V_436 ) {
if ( ! ( V_411 & ( 1 << V_410 ) )
&& V_172 -> V_409 ==
V_439 )
F_34 ( V_3 ) ;
} else {
if ( V_411 &&
V_172 -> V_409 == V_410 )
F_34 ( V_3 ) ;
}
} else {
if ( V_172 -> V_409 == V_439 )
F_34 ( V_3 ) ;
}
V_438:
F_212 ( V_172 , V_172 ) ;
if ( ! V_3 -> V_411 && V_411 )
F_32 ( V_3 ) ;
else if ( V_3 -> V_411 && ! V_411 )
F_33 ( V_3 ) ;
V_3 -> V_411 = V_411 ;
F_211 ( & V_3 -> V_25 ) ;
return 0 ;
}
static int F_213 ( struct V_405 * V_172 )
{
return 0 ;
}
static int F_214 ( struct V_414 * V_415 ,
struct V_440 * V_441 )
{
struct V_3 * V_3 = V_441 -> V_442 ;
struct V_443 * V_444 =
F_215 ( V_415 , V_445 ) ;
struct V_443 * V_446 =
F_215 ( V_415 , V_419 ) ;
if ( V_446 -> V_227 > 96000 && V_446 -> V_228 <= 192000 ) {
struct V_443 V_447 = {
. V_227 = V_3 -> V_148 ,
. V_228 = V_3 -> V_148 ,
. integer = 1 ,
} ;
return F_216 ( V_444 , & V_447 ) ;
} else if ( V_446 -> V_227 > 48000 && V_446 -> V_228 <= 96000 ) {
struct V_443 V_447 = {
. V_227 = V_3 -> V_142 ,
. V_228 = V_3 -> V_142 ,
. integer = 1 ,
} ;
return F_216 ( V_444 , & V_447 ) ;
} else if ( V_446 -> V_228 < 64000 ) {
struct V_443 V_447 = {
. V_227 = V_3 -> V_133 ,
. V_228 = V_3 -> V_133 ,
. integer = 1 ,
} ;
return F_216 ( V_444 , & V_447 ) ;
}
return 0 ;
}
static int F_217 ( struct V_414 * V_415 ,
struct V_440 * V_441 )
{
struct V_3 * V_3 = V_441 -> V_442 ;
struct V_443 * V_444 =
F_215 ( V_415 , V_445 ) ;
struct V_443 * V_446 =
F_215 ( V_415 , V_419 ) ;
if ( V_446 -> V_227 > 96000 && V_446 -> V_228 <= 192000 ) {
struct V_443 V_447 = {
. V_227 = V_3 -> V_149 ,
. V_228 = V_3 -> V_149 ,
. integer = 1 ,
} ;
return F_216 ( V_444 , & V_447 ) ;
} else if ( V_446 -> V_227 > 48000 && V_446 -> V_228 <= 96000 ) {
struct V_443 V_447 = {
. V_227 = V_3 -> V_143 ,
. V_228 = V_3 -> V_143 ,
. integer = 1 ,
} ;
return F_216 ( V_444 , & V_447 ) ;
} else if ( V_446 -> V_228 < 64000 ) {
struct V_443 V_447 = {
. V_227 = V_3 -> V_135 ,
. V_228 = V_3 -> V_135 ,
. integer = 1 ,
} ;
return F_216 ( V_444 , & V_447 ) ;
} else {
}
return 0 ;
}
static int F_218 ( struct V_414 * V_415 ,
struct V_440 * V_441 )
{
struct V_3 * V_3 = V_441 -> V_442 ;
struct V_443 * V_444 =
F_215 ( V_415 , V_445 ) ;
struct V_443 * V_446 =
F_215 ( V_415 , V_419 ) ;
if ( V_444 -> V_227 >= V_3 -> V_133 ) {
struct V_443 V_447 = {
. V_227 = 32000 ,
. V_228 = 48000 ,
. integer = 1 ,
} ;
return F_216 ( V_446 , & V_447 ) ;
} else if ( V_444 -> V_228 <= V_3 -> V_148 ) {
struct V_443 V_447 = {
. V_227 = 128000 ,
. V_228 = 192000 ,
. integer = 1 ,
} ;
return F_216 ( V_446 , & V_447 ) ;
} else if ( V_444 -> V_228 <= V_3 -> V_142 ) {
struct V_443 V_447 = {
. V_227 = 64000 ,
. V_228 = 96000 ,
. integer = 1 ,
} ;
return F_216 ( V_446 , & V_447 ) ;
}
return 0 ;
}
static int F_219 ( struct V_414 * V_415 ,
struct V_440 * V_441 )
{
struct V_3 * V_3 = V_441 -> V_442 ;
struct V_443 * V_444 =
F_215 ( V_415 , V_445 ) ;
struct V_443 * V_446 =
F_215 ( V_415 , V_419 ) ;
if ( V_444 -> V_227 >= V_3 -> V_135 ) {
struct V_443 V_447 = {
. V_227 = 32000 ,
. V_228 = 48000 ,
. integer = 1 ,
} ;
return F_216 ( V_446 , & V_447 ) ;
} else if ( V_444 -> V_228 <= V_3 -> V_149 ) {
struct V_443 V_447 = {
. V_227 = 128000 ,
. V_228 = 192000 ,
. integer = 1 ,
} ;
return F_216 ( V_446 , & V_447 ) ;
} else if ( V_444 -> V_228 <= V_3 -> V_143 ) {
struct V_443 V_447 = {
. V_227 = 64000 ,
. V_228 = 96000 ,
. integer = 1 ,
} ;
return F_216 ( V_446 , & V_447 ) ;
}
return 0 ;
}
static int F_220 ( struct V_414 * V_415 ,
struct V_440 * V_441 )
{
unsigned int V_340 [ 3 ] ;
struct V_3 * V_3 = V_441 -> V_442 ;
struct V_443 * V_444 = F_215 ( V_415 ,
V_445 ) ;
V_340 [ 0 ] = V_3 -> V_148 ;
V_340 [ 1 ] = V_3 -> V_142 ;
V_340 [ 2 ] = V_3 -> V_133 ;
return F_221 ( V_444 , 3 , V_340 , 0 ) ;
}
static int F_222 ( struct V_414 * V_415 ,
struct V_440 * V_441 )
{
unsigned int V_340 [ 3 ] ;
struct V_3 * V_3 = V_441 -> V_442 ;
struct V_443 * V_444 = F_215 ( V_415 ,
V_445 ) ;
V_340 [ 0 ] = V_3 -> V_149 ;
V_340 [ 1 ] = V_3 -> V_143 ;
V_340 [ 2 ] = V_3 -> V_135 ;
return F_221 ( V_444 , 3 , V_340 , 0 ) ;
}
static int F_223 ( struct V_405 * V_172 )
{
struct V_3 * V_3 = F_191 ( V_172 ) ;
struct V_406 * V_407 = V_172 -> V_407 ;
F_36 ( & V_3 -> V_25 ) ;
F_224 ( V_172 ) ;
V_407 -> V_448 = V_449 ;
if ( V_3 -> V_401 == NULL )
F_33 ( V_3 ) ;
V_3 -> V_26 = V_450 -> V_451 ;
V_3 -> V_402 = V_172 ;
F_38 ( & V_3 -> V_25 ) ;
F_225 ( V_407 , 0 , 32 , 24 ) ;
F_226 ( V_407 , 0 , V_420 ) ;
switch ( V_3 -> V_5 ) {
case V_4 :
case V_6 :
F_227 ( V_407 ,
V_420 ,
32 , 4096 ) ;
F_227 ( V_407 ,
V_452 ,
16384 , 16384 ) ;
break;
default:
F_227 ( V_407 ,
V_420 ,
64 , 8192 ) ;
break;
}
if ( V_36 == V_3 -> V_5 ) {
V_407 -> V_448 . V_453 |= V_454 ;
F_228 ( V_407 , 0 , V_419 ,
& V_455 ) ;
} else {
F_229 ( V_407 , 0 , V_419 ,
F_219 , V_3 ,
V_445 , - 1 ) ;
}
F_229 ( V_407 , 0 , V_445 ,
F_222 , V_3 ,
V_445 , - 1 ) ;
F_229 ( V_407 , 0 , V_445 ,
F_217 , V_3 ,
V_419 , - 1 ) ;
return 0 ;
}
static int F_230 ( struct V_405 * V_172 )
{
struct V_3 * V_3 = F_191 ( V_172 ) ;
F_36 ( & V_3 -> V_25 ) ;
V_3 -> V_26 = - 1 ;
V_3 -> V_402 = NULL ;
F_38 ( & V_3 -> V_25 ) ;
return 0 ;
}
static int F_231 ( struct V_405 * V_172 )
{
struct V_3 * V_3 = F_191 ( V_172 ) ;
struct V_406 * V_407 = V_172 -> V_407 ;
F_36 ( & V_3 -> V_25 ) ;
F_224 ( V_172 ) ;
V_407 -> V_448 = V_456 ;
if ( V_3 -> V_402 == NULL )
F_33 ( V_3 ) ;
V_3 -> V_27 = V_450 -> V_451 ;
V_3 -> V_401 = V_172 ;
F_38 ( & V_3 -> V_25 ) ;
F_225 ( V_407 , 0 , 32 , 24 ) ;
F_226 ( V_407 , 0 , V_420 ) ;
switch ( V_3 -> V_5 ) {
case V_4 :
case V_6 :
F_227 ( V_407 ,
V_420 ,
32 , 4096 ) ;
F_227 ( V_407 ,
V_452 ,
16384 , 16384 ) ;
break;
default:
F_227 ( V_407 ,
V_420 ,
64 , 8192 ) ;
break;
}
if ( V_36 == V_3 -> V_5 ) {
V_407 -> V_448 . V_453 |= V_454 ;
F_228 ( V_407 , 0 , V_419 ,
& V_455 ) ;
} else {
F_229 ( V_407 , 0 , V_419 ,
F_218 , V_3 ,
V_445 , - 1 ) ;
}
F_229 ( V_407 , 0 , V_445 ,
F_220 , V_3 ,
V_445 , - 1 ) ;
F_229 ( V_407 , 0 , V_445 ,
F_214 , V_3 ,
V_419 , - 1 ) ;
return 0 ;
}
static int F_232 ( struct V_405 * V_172 )
{
struct V_3 * V_3 = F_191 ( V_172 ) ;
F_36 ( & V_3 -> V_25 ) ;
V_3 -> V_27 = - 1 ;
V_3 -> V_401 = NULL ;
F_38 ( & V_3 -> V_25 ) ;
return 0 ;
}
static int F_233 ( struct V_457 * V_448 , struct V_458 * V_458 )
{
return 0 ;
}
static inline int F_234 ( void T_5 * V_459 , void T_6 * V_460 )
{
V_18 V_8 = F_6 ( V_460 ) ;
return F_235 ( V_459 , & V_8 , 4 ) ;
}
static int F_236 ( struct V_457 * V_448 , struct V_458 * V_458 ,
unsigned int V_433 , unsigned long V_217 )
{
void T_5 * V_461 = ( void T_5 * ) V_217 ;
struct V_3 * V_3 = V_448 -> V_175 ;
struct V_462 V_13 ;
struct V_463 V_430 ;
struct V_464 V_32 ;
struct V_465 V_465 ;
struct V_466 * V_467 ;
struct V_468 V_354 ;
unsigned int V_469 ;
long unsigned int V_87 ;
int V_19 = 0 ;
switch ( V_433 ) {
case V_470 :
V_467 = & V_3 -> V_471 ;
for ( V_19 = 0 ; V_19 < V_93 ; V_19 ++ ) {
V_467 -> V_472 [ V_19 ] =
F_6 ( V_3 -> V_9 +
V_473 + V_19 * 4 ) ;
V_467 -> V_474 [ V_19 ] =
F_6 ( V_3 -> V_9 +
V_475 + V_19 * 4 ) ;
V_467 -> V_476 [ V_19 ] =
F_6 ( V_3 -> V_9 +
V_477 + V_19 * 4 ) ;
V_467 -> V_478 [ V_19 ] =
( ( V_479 ) F_6 ( V_3 -> V_9 +
V_480 + V_19 * 4 ) << 32 ) |
( V_479 ) F_6 ( V_3 -> V_9 +
V_481 + V_19 * 4 ) ;
V_467 -> V_482 [ V_19 ] =
( ( V_479 ) F_6 ( V_3 -> V_9 +
V_483 + V_19 * 4 ) << 32 ) |
( V_479 ) F_6 ( V_3 -> V_9 +
V_484 + V_19 * 4 ) ;
V_467 -> V_485 [ V_19 ] =
( ( V_479 ) F_6 ( V_3 -> V_9 +
V_486 + V_19 * 4 ) << 32 ) |
( V_479 ) F_6 ( V_3 -> V_9 +
V_487 + V_19 * 4 ) ;
}
if ( V_3 -> V_110 > 96000 ) {
V_467 -> V_488 = V_489 ;
} else if ( V_3 -> V_110 > 48000 ) {
V_467 -> V_488 = V_287 ;
} else {
V_467 -> V_488 = V_490 ;
}
V_467 -> V_33 = F_5 ( V_3 , V_37 ) ;
V_87 = F_235 ( V_461 , V_467 , sizeof( struct V_466 ) ) ;
if ( 0 != V_87 ) {
return - V_491 ;
}
break;
case V_492 :
V_354 . V_354 = F_5 ( V_3 , V_272 ) ;
V_19 = F_5 ( V_3 , V_272 + 4 ) ;
if ( V_19 & V_275 ) {
switch ( V_19 & ( V_276 |
V_277 ) ) {
case 0 :
V_354 . V_493 = V_278 ;
break;
case V_276 :
V_354 . V_493 = V_279 ;
break;
case V_277 :
V_354 . V_493 = V_280 ;
break;
default:
V_354 . V_493 = V_281 ;
break;
}
if ( V_19 & V_313 ) {
V_354 . V_494 = V_495 ;
} else {
V_354 . V_494 = V_496 ;
}
} else {
V_354 . V_493 = V_497 ;
V_354 . V_494 = V_498 ;
}
if ( V_19 & V_273 ) {
V_354 . V_499 = V_500 ;
} else if ( V_19 & V_274 ) {
V_354 . V_499 = V_501 ;
} else {
V_354 . V_499 = V_502 ;
}
V_87 = F_235 ( V_461 , & V_354 , sizeof( struct V_468 ) ) ;
if ( 0 != V_87 ) {
return - V_491 ;
}
break;
case V_503 :
memset ( & V_430 , 0 , sizeof( V_430 ) ) ;
F_36 ( & V_3 -> V_25 ) ;
V_430 . V_359 = F_96 ( V_3 ) ;
V_430 . V_504 = F_20 ( V_3 ) ;
V_430 . V_110 = V_3 -> V_110 ;
V_430 . V_505 =
F_18 ( V_3 ) ;
V_430 . V_361 = F_74 ( V_3 ) ;
V_430 . V_506 = F_90 ( V_3 ) ;
V_430 . V_360 = F_19 ( V_3 ) ;
V_430 . V_507 = F_108 ( V_3 , V_375 ) ;
V_430 . V_508 = 0 ;
F_38 ( & V_3 -> V_25 ) ;
if ( F_235 ( V_461 , & V_430 , sizeof( V_430 ) ) )
return - V_491 ;
break;
case V_509 :
memset ( & V_32 , 0 , sizeof( V_32 ) ) ;
V_32 . V_510 = V_3 -> V_5 ;
V_32 . V_511 = F_19 ( V_3 ) ;
V_32 . V_512 = 110069313433624ULL ;
V_32 . V_513 = F_5 ( V_3 , V_219 ) ;
switch ( V_3 -> V_5 ) {
case V_53 :
case V_49 :
V_32 . V_514 . V_515 . V_516 =
F_20 ( V_3 ) ;
V_32 . V_514 . V_515 . V_517 =
F_144 ( V_3 ) ;
V_32 . V_514 . V_515 . V_518 =
F_24 ( V_3 ) ;
V_32 . V_514 . V_515 . V_519 =
F_26 ( V_3 ) ;
V_469 =
F_5 ( V_3 , V_38 ) ;
V_32 . V_514 . V_515 . V_520 =
( V_469 & V_383 ) ? 1 : 0 ;
V_32 . V_514 . V_515 . V_521 =
( V_469 & V_384 ) ? 1 : 0 ;
V_32 . V_514 . V_515 . V_522 = 0 ;
default:
break;
}
if ( F_235 ( V_461 , & V_32 , sizeof( V_32 ) ) )
return - V_491 ;
break;
case V_523 :
memset ( & V_465 , 0 , sizeof( V_465 ) ) ;
V_465 . V_510 = V_3 -> V_5 ;
F_237 ( V_465 . V_524 , V_3 -> V_364 ,
sizeof( V_465 . V_524 ) ) ;
V_465 . V_370 = V_3 -> V_370 ;
V_465 . V_366 = V_3 -> V_366 ;
V_465 . V_525 = 0 ;
if ( V_3 -> V_236 )
V_465 . V_525 |= V_526 ;
if ( F_235 ( V_461 , & V_465 ,
sizeof( V_465 ) ) )
return - V_491 ;
break;
case V_527 :
if ( F_238 ( & V_13 , V_461 , sizeof( V_13 ) ) )
return - V_491 ;
if ( F_235 ( ( void T_5 * ) V_13 . V_13 , V_3 -> V_13 ,
sizeof( struct V_528 ) ) )
return - V_491 ;
break;
default:
return - V_123 ;
}
return 0 ;
}
static int F_239 ( struct V_181 * V_106 ,
struct V_3 * V_3 )
{
struct V_457 * V_448 ;
int V_182 ;
V_182 = F_240 ( V_106 , L_166 , 0 , & V_448 ) ;
if ( V_182 < 0 )
return V_182 ;
V_3 -> V_529 = V_448 ;
V_448 -> V_175 = V_3 ;
strcpy ( V_448 -> V_208 , L_167 ) ;
V_448 -> V_530 . V_531 = F_233 ;
V_448 -> V_530 . V_532 = F_236 ;
V_448 -> V_530 . V_533 = F_236 ;
V_448 -> V_530 . V_534 = F_233 ;
return 0 ;
}
static int F_241 ( struct V_3 * V_3 )
{
int V_182 ;
struct V_535 * V_536 ;
T_7 V_537 ;
V_536 = V_3 -> V_536 ;
V_537 = V_421 ;
V_182 =
F_242 ( V_536 ,
V_538 ,
F_243 ( V_3 -> V_539 ) ,
V_537 ,
V_537 ) ;
if ( V_182 < 0 ) {
F_202 ( V_3 -> V_106 -> V_107 ,
L_168 , V_537 ) ;
return V_182 ;
} else
F_202 ( V_3 -> V_106 -> V_107 ,
L_169 , V_537 ) ;
return 0 ;
}
static void F_200 ( struct V_3 * V_3 ,
struct V_405 * V_172 ,
unsigned int V_7 , int V_540 )
{
int V_19 ;
for ( V_19 = 0 ; V_19 < ( V_540 * 16 ) ; V_19 ++ )
F_3 ( V_3 , V_7 + 4 * V_19 ,
F_244 ( V_172 , 4096 * V_19 ) ) ;
}
static int F_245 ( struct V_181 * V_106 ,
struct V_3 * V_3 )
{
struct V_535 * V_536 ;
int V_182 ;
V_182 = F_246 ( V_106 , V_3 -> V_364 , 0 , 1 , 1 , & V_536 ) ;
if ( V_182 < 0 )
return V_182 ;
V_3 -> V_536 = V_536 ;
V_536 -> V_175 = V_3 ;
strcpy ( V_536 -> V_208 , V_3 -> V_364 ) ;
F_247 ( V_536 , V_410 ,
& V_541 ) ;
F_247 ( V_536 , V_439 ,
& V_542 ) ;
V_536 -> V_213 = V_543 ;
V_182 = F_241 ( V_3 ) ;
if ( V_182 < 0 )
return V_182 ;
return 0 ;
}
static inline void F_248 ( struct V_3 * V_3 )
{
int V_19 ;
for ( V_19 = 0 ; V_19 < V_3 -> V_218 ; V_19 ++ )
F_52 ( V_3 , V_19 ) ;
}
static int F_249 ( struct V_181 * V_106 ,
struct V_3 * V_3 )
{
int V_182 , V_19 ;
F_202 ( V_106 -> V_107 , L_170 ) ;
V_182 = F_245 ( V_106 , V_3 ) ;
if ( V_182 < 0 )
return V_182 ;
V_19 = 0 ;
while ( V_19 < V_3 -> V_218 ) {
V_182 = F_68 ( V_106 , V_3 , V_19 ) ;
if ( V_182 < 0 ) {
return V_182 ;
}
V_19 ++ ;
}
V_182 = F_169 ( V_106 , V_3 ) ;
if ( V_182 < 0 )
return V_182 ;
V_182 = F_239 ( V_106 , V_3 ) ;
if ( V_182 < 0 )
return V_182 ;
F_202 ( V_106 -> V_107 , L_171 ) ;
F_181 ( V_3 ) ;
V_3 -> V_110 = - 1 ;
V_3 -> V_544 = - 1 ;
V_3 -> V_545 = - 1 ;
V_3 -> V_26 = - 1 ;
V_3 -> V_27 = - 1 ;
V_3 -> V_401 = NULL ;
V_3 -> V_402 = NULL ;
F_202 ( V_106 -> V_107 , L_172 ) ;
V_182 = F_185 ( V_3 ) ;
if ( V_182 < 0 )
return V_182 ;
F_202 ( V_106 -> V_107 , L_173 ) ;
F_167 ( V_3 ) ;
F_202 ( V_106 -> V_107 , L_174 ) ;
V_182 = F_250 ( V_106 ) ;
if ( V_182 < 0 ) {
F_46 ( V_106 -> V_107 , L_175 ) ;
return V_182 ;
}
F_202 ( V_106 -> V_107 , L_176 ) ;
return 0 ;
}
static int F_251 ( struct V_181 * V_106 ,
struct V_3 * V_3 )
{
struct V_546 * V_539 = V_3 -> V_539 ;
int V_182 ;
unsigned long V_547 ;
V_3 -> V_188 = - 1 ;
V_3 -> V_106 = V_106 ;
F_69 ( & V_3 -> V_25 ) ;
F_252 ( V_3 -> V_539 ,
V_548 , & V_3 -> V_366 ) ;
strcpy ( V_106 -> V_549 , L_177 ) ;
strcpy ( V_106 -> V_550 , L_178 ) ;
switch ( V_3 -> V_366 ) {
case V_551 :
V_3 -> V_5 = V_6 ;
V_3 -> V_364 = L_179 ;
V_3 -> V_218 = 2 ;
break;
case V_552 :
V_3 -> V_5 = V_4 ;
V_3 -> V_364 = L_180 ;
V_3 -> V_218 = 1 ;
break;
case V_553 :
V_3 -> V_5 = V_49 ;
V_3 -> V_364 = L_181 ;
V_3 -> V_218 = 1 ;
break;
default:
if ( ( V_3 -> V_366 == 0xf0 ) ||
( ( V_3 -> V_366 >= 0xe6 ) &&
( V_3 -> V_366 <= 0xea ) ) ) {
V_3 -> V_5 = V_36 ;
V_3 -> V_364 = L_182 ;
V_3 -> V_218 = 2 ;
} else if ( ( V_3 -> V_366 == 0xd2 ) ||
( ( V_3 -> V_366 >= 0xc8 ) &&
( V_3 -> V_366 <= 0xcf ) ) ) {
V_3 -> V_5 = V_53 ;
V_3 -> V_364 = L_183 ;
V_3 -> V_218 = 3 ;
} else {
F_46 ( V_106 -> V_107 ,
L_184 ,
V_3 -> V_366 ) ;
return - V_554 ;
}
}
V_182 = F_253 ( V_539 ) ;
if ( V_182 < 0 )
return V_182 ;
F_254 ( V_3 -> V_539 ) ;
V_182 = F_255 ( V_539 , L_151 ) ;
if ( V_182 < 0 )
return V_182 ;
V_3 -> V_371 = F_256 ( V_539 , 0 ) ;
V_547 = F_257 ( V_539 , 0 ) ;
F_202 ( V_106 -> V_107 , L_185 ,
V_3 -> V_371 , V_3 -> V_371 + V_547 - 1 ) ;
V_3 -> V_9 = F_258 ( V_3 -> V_371 , V_547 ) ;
if ( ! V_3 -> V_9 ) {
F_46 ( V_106 -> V_107 , L_186 ,
V_3 -> V_371 , V_3 -> V_371 + V_547 - 1 ) ;
return - V_125 ;
}
F_202 ( V_106 -> V_107 , L_187 ,
( unsigned long ) V_3 -> V_9 , V_3 -> V_371 ,
V_3 -> V_371 + V_547 - 1 ) ;
if ( F_259 ( V_539 -> V_188 , F_187 ,
V_555 , V_556 , V_3 ) ) {
F_46 ( V_106 -> V_107 , L_188 , V_539 -> V_188 ) ;
return - V_125 ;
}
F_202 ( V_106 -> V_107 , L_189 , V_539 -> V_188 ) ;
V_3 -> V_188 = V_539 -> V_188 ;
F_202 ( V_106 -> V_107 , L_190 ,
sizeof( struct V_528 ) ) ;
V_3 -> V_13 = F_260 ( sizeof( struct V_528 ) , V_557 ) ;
if ( ! V_3 -> V_13 ) {
F_46 ( V_106 -> V_107 ,
L_191 ,
( int ) sizeof( struct V_528 ) ) ;
return - V_558 ;
}
V_3 -> V_136 = NULL ;
V_3 -> V_138 = NULL ;
switch ( V_3 -> V_5 ) {
case V_36 :
V_3 -> V_133 = V_3 -> V_135 = V_559 ;
V_3 -> V_142 = V_3 -> V_143 = V_559 ;
V_3 -> V_148 = V_3 -> V_149 = V_559 ;
V_3 -> V_129 = V_3 -> V_131 =
V_560 ;
V_3 -> V_140 = V_3 -> V_141 =
V_560 ;
V_3 -> V_146 = V_3 -> V_147 =
V_560 ;
V_3 -> V_137 = V_3 -> V_139 =
V_561 ;
V_3 -> V_144 = V_3 -> V_145 =
V_561 ;
V_3 -> V_150 = V_3 -> V_151 =
V_561 ;
V_3 -> V_134 = V_3 -> V_132 =
V_559 ;
V_3 -> V_136 = V_3 -> V_138 =
V_561 ;
V_3 -> V_128 = V_3 -> V_130 =
V_560 ;
break;
case V_53 :
case V_49 :
V_3 -> V_133 = V_3 -> V_135 =
V_562 ;
V_3 -> V_142 = V_3 -> V_143 =
V_563 ;
V_3 -> V_148 = V_3 -> V_149 =
V_564 ;
V_3 -> V_129 = V_3 -> V_131 =
V_565 ;
V_3 -> V_140 = V_3 -> V_141 =
V_565 ;
V_3 -> V_146 = V_3 -> V_147 =
V_565 ;
V_3 -> V_137 = V_3 -> V_139 =
V_566 ;
V_3 -> V_144 = V_3 -> V_145 =
V_566 ;
V_3 -> V_150 = V_3 -> V_151 =
V_566 ;
break;
case V_4 :
V_3 -> V_133 = V_567 ;
V_3 -> V_142 = V_568 ;
V_3 -> V_148 = V_569 ;
V_3 -> V_135 = V_570 ;
V_3 -> V_143 = V_571 ;
V_3 -> V_149 = V_572 ;
if ( 0 == ( F_5 ( V_3 , V_37 ) & V_573 ) ) {
F_198 ( V_106 -> V_107 , L_192 ) ;
V_3 -> V_133 += 4 ;
V_3 -> V_142 += 4 ;
V_3 -> V_148 += 4 ;
}
if ( 0 == ( F_5 ( V_3 , V_37 ) & V_574 ) ) {
F_198 ( V_106 -> V_107 , L_193 ) ;
V_3 -> V_135 += 4 ;
V_3 -> V_143 += 4 ;
V_3 -> V_149 += 4 ;
}
V_3 -> V_131 = V_575 ;
V_3 -> V_141 = V_576 ;
V_3 -> V_147 = V_577 ;
V_3 -> V_129 = V_578 ;
V_3 -> V_140 = V_579 ;
V_3 -> V_146 = V_580 ;
V_3 -> V_137 = V_581 ;
V_3 -> V_139 = V_582 ;
V_3 -> V_144 = V_583 ;
V_3 -> V_145 = V_584 ;
V_3 -> V_150 = V_585 ;
V_3 -> V_151 = V_586 ;
break;
case V_6 :
V_3 -> V_133 = V_3 -> V_135 =
V_587 ;
V_3 -> V_142 = V_3 -> V_143 =
V_588 ;
V_3 -> V_148 = V_3 -> V_149 =
V_589 ;
V_3 -> V_132 = V_587 ;
V_3 -> V_134 = V_587 ;
V_3 -> V_129 = V_3 -> V_131 =
V_590 ;
V_3 -> V_140 = V_3 -> V_141 =
V_591 ;
V_3 -> V_146 = V_3 -> V_147 =
V_592 ;
V_3 -> V_128 = V_3 -> V_130 =
V_590 ;
V_3 -> V_137 = V_3 -> V_139 =
V_593 ;
V_3 -> V_144 = V_3 -> V_145 =
V_594 ;
V_3 -> V_150 = V_3 -> V_151 =
V_595 ;
break;
}
switch ( V_3 -> V_5 ) {
case V_4 :
case V_6 :
if ( F_5 ( V_3 , V_37 ) &
V_596 ) {
V_3 -> V_218 ++ ;
V_3 -> V_236 = F_260 ( sizeof( struct V_597 ) ,
V_557 ) ;
if ( NULL != V_3 -> V_236 ) {
F_148 ( V_3 ) ;
}
F_198 ( V_106 -> V_107 , L_194 ) ;
} else {
V_3 -> V_236 = NULL ;
}
break;
case V_53 :
case V_36 :
if ( F_5 ( V_3 , V_38 ) & V_358 ) {
V_3 -> V_218 ++ ;
V_3 -> V_236 = F_260 ( sizeof( struct V_597 ) ,
V_557 ) ;
if ( NULL != V_3 -> V_236 ) {
F_148 ( V_3 ) ;
}
F_198 ( V_106 -> V_107 , L_195 ) ;
} else {
V_3 -> V_236 = NULL ;
}
break;
default:
V_3 -> V_236 = NULL ;
}
switch ( V_3 -> V_5 ) {
case V_36 :
if ( V_3 -> V_236 ) {
V_3 -> V_261 = V_598 ;
V_3 -> V_260 =
F_170 ( V_598 ) ;
} else {
V_3 -> V_261 = V_599 ;
V_3 -> V_260 =
F_170 ( V_599 ) ;
}
break;
case V_53 :
if ( V_3 -> V_236 ) {
V_3 -> V_261 = V_600 ;
V_3 -> V_260 = 4 ;
} else {
V_3 -> V_261 = V_601 ;
V_3 -> V_260 = 3 ;
}
break;
case V_49 :
break;
case V_6 :
if ( V_3 -> V_236 ) {
V_3 -> V_261 = V_602 ;
V_3 -> V_260 = 9 ;
} else {
V_3 -> V_261 = V_603 ;
V_3 -> V_260 = 8 ;
}
break;
case V_4 :
if ( V_3 -> V_236 ) {
V_3 -> V_261 = V_604 ;
V_3 -> V_260 = 6 ;
} else {
V_3 -> V_261 = V_605 ;
V_3 -> V_260 = 5 ;
}
break;
}
F_261 ( & V_3 -> V_403 ,
F_72 , ( unsigned long ) V_3 ) ;
if ( V_3 -> V_5 != V_49 ) {
V_3 -> V_370 = ( F_5 ( V_3 ,
V_191 ) >> 8 ) & 0xFFFFFF ;
if ( NULL == V_156 [ V_3 -> V_107 ] && V_3 -> V_370 != 0xFFFFFF ) {
sprintf ( V_106 -> V_156 , L_196 , V_3 -> V_370 ) ;
F_262 ( V_106 , V_106 -> V_156 ) ;
}
}
F_202 ( V_106 -> V_107 , L_197 ) ;
V_182 = F_249 ( V_106 , V_3 ) ;
if ( V_182 < 0 )
return V_182 ;
F_248 ( V_3 ) ;
return 0 ;
}
static int F_263 ( struct V_3 * V_3 )
{
if ( V_3 -> V_371 ) {
V_3 -> V_29 &=
~ ( V_89 | V_88 |
V_194 | V_200 |
V_187 | V_205 ) ;
F_3 ( V_3 , V_90 ,
V_3 -> V_29 ) ;
}
if ( V_3 -> V_188 >= 0 )
F_264 ( V_3 -> V_188 , ( void * ) V_3 ) ;
F_265 ( V_3 -> V_13 ) ;
if ( V_3 -> V_9 )
F_266 ( V_3 -> V_9 ) ;
if ( V_3 -> V_371 )
F_267 ( V_3 -> V_539 ) ;
F_268 ( V_3 -> V_539 ) ;
return 0 ;
}
static void F_269 ( struct V_181 * V_106 )
{
struct V_3 * V_3 = V_106 -> V_175 ;
if ( V_3 )
F_263 ( V_3 ) ;
}
static int F_270 ( struct V_546 * V_539 ,
const struct V_606 * V_607 )
{
static int V_107 ;
struct V_3 * V_3 ;
struct V_181 * V_106 ;
int V_182 ;
if ( V_107 >= V_608 )
return - V_554 ;
if ( ! V_609 [ V_107 ] ) {
V_107 ++ ;
return - V_610 ;
}
V_182 = F_271 ( & V_539 -> V_107 , V_238 [ V_107 ] , V_156 [ V_107 ] ,
V_611 , sizeof( struct V_3 ) , & V_106 ) ;
if ( V_182 < 0 )
return V_182 ;
V_3 = V_106 -> V_175 ;
V_106 -> V_612 = F_269 ;
V_3 -> V_107 = V_107 ;
V_3 -> V_539 = V_539 ;
V_182 = F_251 ( V_106 , V_3 ) ;
if ( V_182 < 0 ) {
F_272 ( V_106 ) ;
return V_182 ;
}
if ( V_3 -> V_5 != V_49 ) {
sprintf ( V_106 -> V_207 , L_198 ,
V_3 -> V_364 ,
V_3 -> V_370 ) ;
sprintf ( V_106 -> V_613 , L_199 ,
V_3 -> V_364 ,
V_3 -> V_370 ,
V_3 -> V_371 , V_3 -> V_188 ) ;
} else {
sprintf ( V_106 -> V_207 , L_200 , V_3 -> V_364 ) ;
sprintf ( V_106 -> V_613 , L_201 ,
V_3 -> V_364 , V_3 -> V_371 , V_3 -> V_188 ) ;
}
V_182 = F_250 ( V_106 ) ;
if ( V_182 < 0 ) {
F_272 ( V_106 ) ;
return V_182 ;
}
F_273 ( V_539 , V_106 ) ;
V_107 ++ ;
return 0 ;
}
static void F_274 ( struct V_546 * V_539 )
{
F_272 ( F_275 ( V_539 ) ) ;
}
