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
if ( V_164 -> V_176 )
F_60 ( & V_164 -> V_177 , 1 + V_178 ) ;
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
F_62 ( & V_164 -> V_177 , F_59 ,
( unsigned long ) V_164 ) ;
F_60 ( & V_164 -> V_177 , 1 + V_178 ) ;
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
static int F_68 ( struct V_179 * V_106 ,
struct V_3 * V_3 , int V_156 )
{
int V_180 ;
char V_91 [ 32 ] ;
V_3 -> V_157 [ V_156 ] . V_156 = V_156 ;
V_3 -> V_157 [ V_156 ] . V_3 = V_3 ;
F_69 ( & V_3 -> V_157 [ V_156 ] . V_25 ) ;
if ( 0 == V_156 ) {
if ( V_49 == V_3 -> V_5 ) {
V_3 -> V_157 [ 0 ] . V_158 = V_181 ;
V_3 -> V_157 [ 0 ] . V_160 = V_182 ;
V_3 -> V_157 [ 0 ] . V_159 = V_183 ;
V_3 -> V_157 [ 0 ] . V_162 = V_184 ;
V_3 -> V_157 [ 0 ] . V_170 = V_185 ;
V_3 -> V_157 [ 0 ] . V_186 = V_187 ;
} else {
V_3 -> V_157 [ 0 ] . V_158 = V_188 ;
V_3 -> V_157 [ 0 ] . V_160 = V_189 ;
V_3 -> V_157 [ 0 ] . V_159 = V_190 ;
V_3 -> V_157 [ 0 ] . V_162 = V_191 ;
V_3 -> V_157 [ 0 ] . V_170 = V_192 ;
V_3 -> V_157 [ 0 ] . V_186 = V_193 ;
}
} else if ( 1 == V_156 ) {
V_3 -> V_157 [ 1 ] . V_158 = V_194 ;
V_3 -> V_157 [ 1 ] . V_160 = V_195 ;
V_3 -> V_157 [ 1 ] . V_159 = V_196 ;
V_3 -> V_157 [ 1 ] . V_162 = V_197 ;
V_3 -> V_157 [ 1 ] . V_170 = V_198 ;
V_3 -> V_157 [ 1 ] . V_186 = V_199 ;
} else if ( ( 2 == V_156 ) && ( V_53 == V_3 -> V_5 ) ) {
V_3 -> V_157 [ 2 ] . V_158 = V_181 ;
V_3 -> V_157 [ 2 ] . V_160 = V_182 ;
V_3 -> V_157 [ 2 ] . V_159 = V_183 ;
V_3 -> V_157 [ 2 ] . V_162 = V_184 ;
V_3 -> V_157 [ 2 ] . V_170 = V_185 ;
V_3 -> V_157 [ 2 ] . V_186 = V_187 ;
} else if ( 2 == V_156 ) {
V_3 -> V_157 [ 2 ] . V_158 = V_181 ;
V_3 -> V_157 [ 2 ] . V_160 = V_182 ;
V_3 -> V_157 [ 2 ] . V_159 = - 1 ;
V_3 -> V_157 [ 2 ] . V_162 = - 1 ;
V_3 -> V_157 [ 2 ] . V_170 = V_185 ;
V_3 -> V_157 [ 2 ] . V_186 = V_200 ;
} else if ( 3 == V_156 ) {
V_3 -> V_157 [ 3 ] . V_158 = V_201 ;
V_3 -> V_157 [ 3 ] . V_160 = V_202 ;
V_3 -> V_157 [ 3 ] . V_159 = - 1 ;
V_3 -> V_157 [ 3 ] . V_162 = - 1 ;
V_3 -> V_157 [ 3 ] . V_170 = V_203 ;
V_3 -> V_157 [ 3 ] . V_186 = V_204 ;
}
if ( ( V_156 < 2 ) || ( ( 2 == V_156 ) && ( ( V_53 == V_3 -> V_5 ) ||
( V_49 == V_3 -> V_5 ) ) ) ) {
if ( ( V_156 == 0 ) && ( V_49 == V_3 -> V_5 ) ) {
sprintf ( V_91 , L_5 , V_106 -> V_205 ) ;
} else if ( ( V_156 == 2 ) && ( V_53 == V_3 -> V_5 ) ) {
sprintf ( V_91 , L_5 , V_106 -> V_205 ) ;
} else {
sprintf ( V_91 , L_6 , V_106 -> V_205 , V_156 + 1 ) ;
}
V_180 = F_70 ( V_106 , V_91 , V_156 , 1 , 1 ,
& V_3 -> V_157 [ V_156 ] . V_174 ) ;
if ( V_180 < 0 )
return V_180 ;
sprintf ( V_3 -> V_157 [ V_156 ] . V_174 -> V_206 , L_6 ,
V_106 -> V_156 , V_156 + 1 ) ;
V_3 -> V_157 [ V_156 ] . V_174 -> V_175 = & V_3 -> V_157 [ V_156 ] ;
F_71 ( V_3 -> V_157 [ V_156 ] . V_174 ,
V_207 ,
& V_208 ) ;
F_71 ( V_3 -> V_157 [ V_156 ] . V_174 ,
V_209 ,
& V_210 ) ;
V_3 -> V_157 [ V_156 ] . V_174 -> V_211 |=
V_212 |
V_213 |
V_214 ;
} else {
sprintf ( V_91 , L_7 , V_106 -> V_205 , V_156 + 1 ) ;
V_180 = F_70 ( V_106 , V_91 , V_156 , 1 , 1 ,
& V_3 -> V_157 [ V_156 ] . V_174 ) ;
if ( V_180 < 0 )
return V_180 ;
sprintf ( V_3 -> V_157 [ V_156 ] . V_174 -> V_206 ,
L_7 , V_106 -> V_156 , V_156 + 1 ) ;
V_3 -> V_157 [ V_156 ] . V_174 -> V_175 = & V_3 -> V_157 [ V_156 ] ;
F_71 ( V_3 -> V_157 [ V_156 ] . V_174 ,
V_209 ,
& V_210 ) ;
V_3 -> V_157 [ V_156 ] . V_174 -> V_211 |= V_213 ;
}
return 0 ;
}
static void F_72 ( unsigned long V_215 )
{
struct V_3 * V_3 = (struct V_3 * ) V_215 ;
int V_19 = 0 ;
while ( V_19 < V_3 -> V_216 ) {
if ( V_3 -> V_157 [ V_19 ] . V_169 )
F_56 ( & V_3 -> V_157 [ V_19 ] ) ;
V_19 ++ ;
}
}
static inline int F_27 ( struct V_3 * V_3 )
{
unsigned int V_97 , V_28 ;
V_97 = F_5 ( V_3 , V_217 ) ;
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
static int F_75 ( struct V_218 * V_219 ,
struct V_220 * V_221 )
{
V_221 -> type = V_222 ;
V_221 -> V_223 = 1 ;
V_221 -> V_224 . integer . V_225 = 27000 ;
V_221 -> V_224 . integer . V_226 = 207000 ;
V_221 -> V_224 . integer . V_227 = 1 ;
return 0 ;
}
static int F_76 ( struct V_218 * V_219 ,
struct V_228 *
V_229 )
{
struct V_3 * V_3 = F_77 ( V_219 ) ;
V_229 -> V_224 . integer . V_224 [ 0 ] = F_73 ( V_3 ) ;
return 0 ;
}
static int F_78 ( struct V_218 * V_219 ,
struct V_228 *
V_229 )
{
struct V_3 * V_3 = F_77 ( V_219 ) ;
F_42 ( V_3 , V_229 -> V_224 . V_230 . V_231 [ 0 ] ) ;
return 0 ;
}
static int F_21 ( struct V_3 * V_3 )
{
int V_32 ;
switch ( V_3 -> V_5 ) {
case V_6 :
case V_4 :
V_32 = F_5 ( V_3 , V_232 ) ;
return ( V_32 >> 16 ) & 0xF ;
break;
case V_36 :
V_32 = F_5 ( V_3 , V_38 ) ;
return ( V_32 >> V_233 ) & 0xF ;
default:
break;
}
return 0 ;
}
static int F_25 ( struct V_3 * V_3 )
{
int V_32 ;
if ( V_3 -> V_234 ) {
switch ( V_3 -> V_5 ) {
case V_6 :
case V_4 :
V_32 = F_5 ( V_3 , V_232 ) ;
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
if ( V_3 -> V_234 ) {
switch ( V_3 -> V_5 ) {
case V_6 :
case V_4 :
V_32 = F_5 ( V_3 , V_235 ) ;
return ( V_32 >> 12 ) & 0xF ;
break;
default:
break;
}
}
return 0 ;
}
static int F_23 ( struct V_3 * V_3 , int V_236 )
{
int V_237 ;
switch ( V_3 -> V_5 ) {
case V_36 :
V_237 = F_5 ( V_3 , V_238 ) ;
return ( V_237 >> ( 4 * V_236 ) ) & 0xF ;
break;
default:
break;
}
return 0 ;
}
static int F_80 ( struct V_3 * V_3 , unsigned int V_239 )
{
int V_32 = F_5 ( V_3 , V_235 ) ;
return ( V_32 >> ( V_239 * 4 ) ) & 0xF ;
}
static int F_81 ( struct V_3 * V_3 )
{
int V_28 = F_18 ( V_3 ) ;
int V_19 , V_240 = 0 ;
for ( V_19 = 1 ; V_19 < 10 ; V_19 ++ )
if ( F_1 ( V_19 ) == V_28 ) {
V_240 = V_19 ;
break;
}
return V_240 ;
}
static int F_82 ( struct V_218 * V_219 ,
struct V_220 * V_221 )
{
F_83 ( V_221 , V_241 ) ;
return 0 ;
}
static int F_84 ( struct V_218 * V_219 ,
struct V_228 *
V_229 )
{
struct V_3 * V_3 = F_77 ( V_219 ) ;
switch ( V_3 -> V_5 ) {
case V_6 :
switch ( V_219 -> V_242 ) {
case 0 :
V_229 -> V_224 . V_230 . V_231 [ 0 ] =
F_21 ( V_3 ) ;
break;
case 7 :
V_229 -> V_224 . V_230 . V_231 [ 0 ] =
F_25 ( V_3 ) ;
break;
case 8 :
V_229 -> V_224 . V_230 . V_231 [ 0 ] =
F_79 ( V_3 ) ;
break;
default:
V_229 -> V_224 . V_230 . V_231 [ 0 ] =
F_80 ( V_3 ,
V_219 -> V_242 - 1 ) ;
}
break;
case V_4 :
switch ( V_219 -> V_242 ) {
case 0 :
V_229 -> V_224 . V_230 . V_231 [ 0 ] =
F_21 ( V_3 ) ;
break;
case 4 :
V_229 -> V_224 . V_230 . V_231 [ 0 ] =
F_25 ( V_3 ) ;
break;
case 5 :
V_229 -> V_224 . V_230 . V_231 [ 0 ] =
F_79 ( V_3 ) ;
break;
default:
V_229 -> V_224 . V_230 . V_231 [ 0 ] =
F_80 ( V_3 ,
V_219 -> V_242 - 1 ) ;
}
break;
case V_36 :
switch ( V_219 -> V_242 ) {
case 0 :
V_229 -> V_224 . V_230 . V_231 [ 0 ] =
F_21 ( V_3 ) ;
break;
case 9 :
V_229 -> V_224 . V_230 . V_231 [ 0 ] =
F_25 ( V_3 ) ;
break;
case 10 :
V_229 -> V_224 . V_230 . V_231 [ 0 ] =
F_79 ( V_3 ) ;
break;
case 11 :
V_229 -> V_224 . V_230 . V_231 [ 0 ] =
F_81 ( V_3 ) ;
break;
default:
V_229 -> V_224 . V_230 . V_231 [ 0 ] =
F_23 ( V_3 ,
V_219 -> V_242 -
V_40 ) ;
break;
}
break;
case V_53 :
case V_49 :
V_229 -> V_224 . V_230 . V_231 [ 0 ] =
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
if ( V_3 -> V_243 & V_244 )
return 0 ;
break;
default:
if ( V_3 -> V_29 & V_105 )
return 0 ;
}
return 1 ;
}
static void F_85 ( struct V_3 * V_3 , int V_245 )
{
F_86 ( V_3 ,
( F_2 ( V_3 ) ) ?
V_244 : V_105 ,
( 0 == V_245 ) ) ;
}
static int F_87 ( struct V_218 * V_219 ,
struct V_220 * V_221 )
{
static const char * const V_246 [] = { L_8 , L_9 } ;
F_83 ( V_221 , V_246 ) ;
return 0 ;
}
static int F_88 ( struct V_218 * V_219 ,
struct V_228 * V_229 )
{
struct V_3 * V_3 = F_77 ( V_219 ) ;
V_229 -> V_224 . V_230 . V_231 [ 0 ] = F_74 ( V_3 ) ;
return 0 ;
}
static int F_89 ( struct V_218 * V_219 ,
struct V_228 * V_229 )
{
struct V_3 * V_3 = F_77 ( V_219 ) ;
int V_8 ;
if ( ! F_13 ( V_3 ) )
return - V_125 ;
V_8 = V_229 -> V_224 . V_230 . V_231 [ 0 ] ;
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
static int F_91 ( struct V_3 * V_3 , int V_245 )
{
int V_28 ;
switch ( V_245 ) {
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
static int F_92 ( struct V_218 * V_219 ,
struct V_220 * V_221 )
{
return F_93 ( V_221 , 1 , 9 , V_241 + 1 ) ;
}
static int F_94 ( struct V_218 * V_219 ,
struct V_228 * V_229 )
{
struct V_3 * V_3 = F_77 ( V_219 ) ;
V_229 -> V_224 . V_230 . V_231 [ 0 ] = F_90 ( V_3 ) ;
return 0 ;
}
static int F_95 ( struct V_218 * V_219 ,
struct V_228 * V_229 )
{
struct V_3 * V_3 = F_77 ( V_219 ) ;
int V_247 ;
int V_8 ;
if ( ! F_13 ( V_3 ) )
return - V_125 ;
V_8 = V_229 -> V_224 . V_230 . V_231 [ 0 ] ;
if ( V_8 < 0 )
V_8 = 0 ;
if ( V_8 > 9 )
V_8 = 9 ;
F_36 ( & V_3 -> V_25 ) ;
if ( V_8 != F_90 ( V_3 ) )
V_247 = ( F_91 ( V_3 , V_8 ) == 0 ) ? 1 : 0 ;
else
V_247 = 0 ;
F_38 ( & V_3 -> V_25 ) ;
return V_247 ;
}
static int F_96 ( struct V_3 * V_3 )
{
switch ( V_3 -> V_5 ) {
case V_36 :
switch ( V_3 -> V_29 & V_248 ) {
case 0 : return 0 ;
case V_249 : return 1 ;
case V_250 : return 2 ;
case V_250 + V_249 : return 3 ;
case V_251 : return 4 ;
case V_251 + V_249 : return 5 ;
case V_251 + V_250 : return 6 ;
case V_251 + V_250 + V_249 :
return 7 ;
case V_252 : return 8 ;
case V_252 + V_249 : return 9 ;
}
break;
case V_53 :
case V_49 :
if ( V_3 -> V_234 ) {
switch ( V_3 -> V_29 & V_248 ) {
case 0 : return 0 ;
case V_249 : return 1 ;
case V_250 : return 2 ;
case V_250 + V_249 :
return 3 ;
}
} else {
switch ( V_3 -> V_29 & V_248 ) {
case 0 : return 0 ;
case V_249 : return 1 ;
case V_250 + V_249 :
return 2 ;
}
}
break;
case V_6 :
if ( V_3 -> V_234 ) {
switch ( ( V_3 -> V_243 &
V_253 ) / V_254 ) {
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
switch ( ( V_3 -> V_243 &
V_253 ) / V_254 ) {
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
if ( V_3 -> V_234 ) {
switch ( ( V_3 -> V_243 &
V_253 ) / V_254 ) {
case 0 : return 0 ;
case 3 : return 1 ;
case 1 : return 2 ;
case 2 : return 3 ;
case 9 : return 4 ;
case 10 : return 5 ;
}
} else {
switch ( ( V_3 -> V_243 &
V_253 ) / V_254 ) {
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
static int F_97 ( struct V_3 * V_3 , int V_255 )
{
int V_256 = 0 ;
switch ( V_3 -> V_5 ) {
case V_36 :
V_3 -> V_29 &= ~ V_248 ;
switch ( V_255 ) {
case 0 :
break;
case 1 :
V_3 -> V_29 |= V_249 ;
break;
case 2 :
V_3 -> V_29 |= V_250 ;
break;
case 3 :
V_3 -> V_29 |=
V_250 + V_249 ;
break;
case 4 :
V_3 -> V_29 |= V_251 ;
break;
case 5 :
V_3 -> V_29 |=
V_251 + V_249 ;
break;
case 6 :
V_3 -> V_29 |=
V_251 + V_250 ;
break;
case 7 :
V_3 -> V_29 |=
V_251 + V_250 + V_249 ;
break;
case 8 :
V_3 -> V_29 |= V_252 ;
break;
case 9 :
V_3 -> V_29 |=
V_252 + V_249 ;
break;
default:
return - 1 ;
}
break;
case V_53 :
case V_49 :
V_3 -> V_29 &= ~ V_248 ;
if ( V_3 -> V_234 ) {
switch ( V_255 ) {
case 0 :
break;
case 1 :
V_3 -> V_29 |= V_249 ;
break;
case 2 :
V_3 -> V_29 |= V_250 ;
break;
case 3 :
V_3 -> V_29 |=
V_249 + V_250 ;
break;
default:
return - 1 ;
}
} else {
switch ( V_255 ) {
case 0 :
break;
case 1 :
V_3 -> V_29 |= V_249 ;
break;
case 2 :
V_3 -> V_29 |=
V_249 + V_250 ;
break;
default:
return - 1 ;
}
}
break;
case V_6 :
if ( V_3 -> V_234 ) {
switch ( V_255 ) {
case 0 : V_256 = 0 ; break;
case 1 : V_256 = 3 ; break;
case 2 : V_256 = 4 ; break;
case 3 : V_256 = 5 ; break;
case 4 : V_256 = 6 ; break;
case 5 : V_256 = 1 ; break;
case 6 : V_256 = 2 ; break;
case 7 : V_256 = 9 ; break;
case 8 : V_256 = 10 ; break;
default: return - 1 ;
}
} else {
switch ( V_255 ) {
case 0 : V_256 = 0 ; break;
case 1 : V_256 = 3 ; break;
case 2 : V_256 = 4 ; break;
case 3 : V_256 = 5 ; break;
case 4 : V_256 = 6 ; break;
case 5 : V_256 = 1 ; break;
case 6 : V_256 = 2 ; break;
case 7 : V_256 = 10 ; break;
default: return - 1 ;
}
}
break;
case V_4 :
if ( V_3 -> V_234 ) {
switch ( V_255 ) {
case 0 : V_256 = 0 ; break;
case 1 : V_256 = 3 ; break;
case 2 : V_256 = 1 ; break;
case 3 : V_256 = 2 ; break;
case 4 : V_256 = 9 ; break;
case 5 : V_256 = 10 ; break;
default: return - 1 ;
}
} else {
switch ( V_255 ) {
case 0 : V_256 = 0 ; break;
case 1 : V_256 = 3 ; break;
case 2 : V_256 = 1 ; break;
case 3 : V_256 = 2 ; break;
case 4 : V_256 = 10 ; break;
default: return - 1 ;
}
}
break;
}
switch ( V_3 -> V_5 ) {
case V_6 :
case V_4 :
V_3 -> V_243 &= ~ V_253 ;
V_3 -> V_243 |= V_254 * V_256 ;
F_3 ( V_3 , V_257 , V_3 -> V_243 ) ;
break;
case V_53 :
case V_49 :
case V_36 :
F_3 ( V_3 , V_90 ,
V_3 -> V_29 ) ;
}
return 0 ;
}
static int F_98 ( struct V_218 * V_219 ,
struct V_220 * V_221 )
{
struct V_3 * V_3 = F_77 ( V_219 ) ;
F_93 ( V_221 , 1 , V_3 -> V_258 , V_3 -> V_259 ) ;
return 0 ;
}
static int F_99 ( struct V_218 * V_219 ,
struct V_228 * V_229 )
{
struct V_3 * V_3 = F_77 ( V_219 ) ;
int V_260 = F_96 ( V_3 ) ;
if ( V_260 >= 0 ) {
V_229 -> V_224 . V_230 . V_231 [ 0 ] = V_260 ;
return 0 ;
}
return - 1 ;
}
static int F_100 ( struct V_218 * V_219 ,
struct V_228 * V_229 )
{
struct V_3 * V_3 = F_77 ( V_219 ) ;
int V_8 , V_247 = 0 ;
if ( ! F_13 ( V_3 ) )
return - V_125 ;
V_8 = V_229 -> V_224 . V_230 . V_231 [ 0 ] ;
if ( V_8 < 0 )
V_8 = 0 ;
else if ( V_8 >= V_3 -> V_258 )
V_8 = V_3 -> V_258 - 1 ;
F_36 ( & V_3 -> V_25 ) ;
if ( V_8 != F_96 ( V_3 ) )
V_247 = ( 0 == F_97 ( V_3 , V_8 ) ) ? 1 : 0 ;
F_38 ( & V_3 -> V_25 ) ;
return V_247 ;
}
static int F_19 ( struct V_3 * V_3 )
{
if ( V_36 == V_3 -> V_5 ) {
unsigned int V_32 = F_5 ( V_3 , V_38 ) ;
unsigned int V_34 = ( V_32 >> V_261 ) & 0xF ;
if ( ( V_34 >= V_39 ) &&
( V_34 <= V_262 ) ) {
return V_34 ;
}
return V_263 ;
} else if ( V_53 == V_3 -> V_5 ) {
unsigned int V_33 = F_5 ( V_3 , V_37 ) ;
switch ( V_33 & V_66 ) {
case V_67 :
return V_264 ;
case V_265 :
return V_266 ;
case V_267 :
return V_80 ;
case V_268 :
return V_82 ;
case V_269 :
return V_109 ;
default:
return V_109 ;
}
}
return 0 ;
}
static int F_101 ( struct V_218 * V_219 ,
struct V_220 * V_221 )
{
struct V_3 * V_3 = F_77 ( V_219 ) ;
if ( V_36 == V_3 -> V_5 ) {
static const char * const V_246 [] = { L_10 , L_11 , L_12 , L_13 ,
L_14 , L_15 , L_16 , L_17 , L_18 , L_19 , L_20 , L_21 } ;
F_83 ( V_221 , V_246 ) ;
} else if ( V_53 == V_3 -> V_5 ) {
static const char * const V_246 [] = { L_22 , L_23 , L_19 ,
L_20 , L_21 } ;
F_83 ( V_221 , V_246 ) ;
}
return 0 ;
}
static int F_102 ( struct V_218 * V_219 ,
struct V_228 * V_229 )
{
struct V_3 * V_3 = F_77 ( V_219 ) ;
V_229 -> V_224 . V_230 . V_231 [ 0 ] = F_19 ( V_3 ) ;
return 0 ;
}
static int F_103 ( struct V_218 * V_219 ,
struct V_220 * V_221 )
{
static const char * const V_246 [] = { L_24 , L_25 , L_26 } ;
F_83 ( V_221 , V_246 ) ;
return 0 ;
}
static int F_104 ( struct V_218 * V_219 ,
struct V_228 * V_229 )
{
V_18 V_32 ;
int V_24 = 0 ;
struct V_3 * V_3 = F_77 ( V_219 ) ;
V_32 = F_5 ( V_3 , V_270 + 4 ) ;
switch ( V_32 & ( V_271 |
V_272 ) ) {
case V_271 :
V_24 = 1 ;
break;
case V_272 :
V_24 = 2 ;
break;
default:
V_24 = 0 ;
break;
}
V_229 -> V_224 . V_230 . V_231 [ 0 ] = V_24 ;
return 0 ;
}
static int F_105 ( struct V_218 * V_219 ,
struct V_220 * V_221 )
{
static const char * const V_246 [] = { L_27 , L_28 , L_29 , L_30 ,
L_31 } ;
F_83 ( V_221 , V_246 ) ;
return 0 ;
}
static int F_106 ( struct V_3 * V_3 )
{
V_18 V_32 ;
int V_24 = 0 ;
V_32 = F_5 ( V_3 , V_270 + 4 ) ;
if ( V_32 & V_273 ) {
switch ( V_32 & ( V_274 |
V_275 ) ) {
case 0 :
V_24 = V_276 ;
break;
case V_274 :
V_24 = V_277 ;
break;
case V_275 :
V_24 = V_278 ;
break;
default:
V_24 = V_279 ;
break;
}
}
return V_24 ;
}
static int F_107 ( struct V_218 * V_219 ,
struct V_228 * V_229 )
{
struct V_3 * V_3 = F_77 ( V_219 ) ;
V_229 -> V_224 . V_230 . V_231 [ 0 ] = F_106 ( V_3 ) ;
return 0 ;
}
static int F_108 ( struct V_3 * V_3 , V_18 V_280 )
{
V_18 V_7 ;
if ( F_2 ( V_3 ) )
V_7 = V_3 -> V_243 ;
else
V_7 = V_3 -> V_29 ;
return ( V_7 & V_280 ) ? 1 : 0 ;
}
static int F_86 ( struct V_3 * V_3 , V_18 V_280 , int V_281 )
{
V_18 * V_7 ;
V_18 V_282 ;
if ( F_2 ( V_3 ) ) {
V_7 = & ( V_3 -> V_243 ) ;
V_282 = V_257 ;
} else {
V_7 = & ( V_3 -> V_29 ) ;
V_282 = V_90 ;
}
if ( V_281 )
* V_7 |= V_280 ;
else
* V_7 &= ~ V_280 ;
F_3 ( V_3 , V_282 , * V_7 ) ;
return 0 ;
}
static int F_109 ( struct V_218 * V_219 ,
struct V_228 * V_229 )
{
struct V_3 * V_3 = F_77 ( V_219 ) ;
V_18 V_280 = V_219 -> V_242 ;
F_36 ( & V_3 -> V_25 ) ;
V_229 -> V_224 . integer . V_224 [ 0 ] = F_108 ( V_3 , V_280 ) ;
F_38 ( & V_3 -> V_25 ) ;
return 0 ;
}
static int F_110 ( struct V_218 * V_219 ,
struct V_228 * V_229 )
{
struct V_3 * V_3 = F_77 ( V_219 ) ;
V_18 V_280 = V_219 -> V_242 ;
int V_247 ;
unsigned int V_8 ;
if ( ! F_13 ( V_3 ) )
return - V_125 ;
V_8 = V_229 -> V_224 . integer . V_224 [ 0 ] & 1 ;
F_36 ( & V_3 -> V_25 ) ;
V_247 = ( int ) V_8 != F_108 ( V_3 , V_280 ) ;
F_86 ( V_3 , V_280 , V_8 ) ;
F_38 ( & V_3 -> V_25 ) ;
return V_247 ;
}
static int F_111 ( struct V_3 * V_3 )
{
return ( V_3 -> V_29 & V_283 ) ? 1 : 0 ;
}
static int F_112 ( struct V_3 * V_3 , int V_281 )
{
if ( V_281 )
V_3 -> V_29 |= V_283 ;
else
V_3 -> V_29 &= ~ V_283 ;
F_3 ( V_3 , V_90 , V_3 -> V_29 ) ;
return 0 ;
}
static int F_113 ( struct V_218 * V_219 ,
struct V_220 * V_221 )
{
static const char * const V_246 [] = { L_32 , L_33 } ;
F_83 ( V_221 , V_246 ) ;
return 0 ;
}
static int F_114 ( struct V_218 * V_219 ,
struct V_228 * V_229 )
{
struct V_3 * V_3 = F_77 ( V_219 ) ;
F_36 ( & V_3 -> V_25 ) ;
V_229 -> V_224 . V_230 . V_231 [ 0 ] = F_111 ( V_3 ) ;
F_38 ( & V_3 -> V_25 ) ;
return 0 ;
}
static int F_115 ( struct V_218 * V_219 ,
struct V_228 * V_229 )
{
struct V_3 * V_3 = F_77 ( V_219 ) ;
int V_247 ;
unsigned int V_8 ;
if ( ! F_13 ( V_3 ) )
return - V_125 ;
V_8 = V_229 -> V_224 . integer . V_224 [ 0 ] & 1 ;
F_36 ( & V_3 -> V_25 ) ;
V_247 = ( int ) V_8 != F_111 ( V_3 ) ;
F_112 ( V_3 , V_8 ) ;
F_38 ( & V_3 -> V_25 ) ;
return V_247 ;
}
static int F_116 ( struct V_3 * V_3 )
{
return ( V_3 -> V_29 & V_284 ) ? 1 : 0 ;
}
static int F_117 ( struct V_3 * V_3 , int V_285 )
{
if ( V_285 )
V_3 -> V_29 |= V_284 ;
else
V_3 -> V_29 &= ~ V_284 ;
F_3 ( V_3 , V_90 , V_3 -> V_29 ) ;
return 0 ;
}
static int F_118 ( struct V_218 * V_219 ,
struct V_220 * V_221 )
{
static const char * const V_246 [] = { L_34 , L_35 } ;
F_83 ( V_221 , V_246 ) ;
return 0 ;
}
static int F_119 ( struct V_218 * V_219 ,
struct V_228 * V_229 )
{
struct V_3 * V_3 = F_77 ( V_219 ) ;
F_36 ( & V_3 -> V_25 ) ;
V_229 -> V_224 . V_230 . V_231 [ 0 ] = F_116 ( V_3 ) ;
F_38 ( & V_3 -> V_25 ) ;
return 0 ;
}
static int F_120 ( struct V_218 * V_219 ,
struct V_228 * V_229 )
{
struct V_3 * V_3 = F_77 ( V_219 ) ;
int V_247 ;
unsigned int V_8 ;
if ( ! F_13 ( V_3 ) )
return - V_125 ;
V_8 = V_229 -> V_224 . integer . V_224 [ 0 ] & 1 ;
F_36 ( & V_3 -> V_25 ) ;
V_247 = ( int ) V_8 != F_116 ( V_3 ) ;
F_117 ( V_3 , V_8 ) ;
F_38 ( & V_3 -> V_25 ) ;
return V_247 ;
}
static int F_121 ( struct V_3 * V_3 )
{
if ( V_3 -> V_29 & V_286 )
return 1 ;
if ( V_3 -> V_29 & V_287 )
return 2 ;
return 0 ;
}
static int F_122 ( struct V_3 * V_3 , int V_245 )
{
V_3 -> V_29 &= ~ ( V_286 | V_287 ) ;
switch ( V_245 ) {
case 0 :
break;
case 1 :
V_3 -> V_29 |= V_286 ;
break;
case 2 :
V_3 -> V_29 |= V_287 ;
break;
}
F_3 ( V_3 , V_90 , V_3 -> V_29 ) ;
return 0 ;
}
static int F_123 ( struct V_218 * V_219 ,
struct V_220 * V_221 )
{
static const char * const V_246 [] = { L_34 , L_35 , L_36 } ;
F_83 ( V_221 , V_246 ) ;
return 0 ;
}
static int F_124 ( struct V_218 * V_219 ,
struct V_228 * V_229 )
{
struct V_3 * V_3 = F_77 ( V_219 ) ;
F_36 ( & V_3 -> V_25 ) ;
V_229 -> V_224 . V_230 . V_231 [ 0 ] = F_121 ( V_3 ) ;
F_38 ( & V_3 -> V_25 ) ;
return 0 ;
}
static int F_125 ( struct V_218 * V_219 ,
struct V_228 * V_229 )
{
struct V_3 * V_3 = F_77 ( V_219 ) ;
int V_247 ;
int V_8 ;
if ( ! F_13 ( V_3 ) )
return - V_125 ;
V_8 = V_229 -> V_224 . integer . V_224 [ 0 ] ;
if ( V_8 < 0 )
V_8 = 0 ;
if ( V_8 > 2 )
V_8 = 2 ;
F_36 ( & V_3 -> V_25 ) ;
V_247 = V_8 != F_121 ( V_3 ) ;
F_122 ( V_3 , V_8 ) ;
F_38 ( & V_3 -> V_25 ) ;
return V_247 ;
}
static int F_126 ( struct V_3 * V_3 , V_18 V_280 )
{
V_18 V_7 = V_3 -> V_243 & ( V_280 * 3 ) ;
return V_7 / V_280 ;
}
static int F_127 ( struct V_3 * V_3 , int V_245 , V_18 V_280 )
{
V_3 -> V_243 &= ~ ( V_280 * 3 ) ;
V_3 -> V_243 |= ( V_280 * V_245 ) ;
F_3 ( V_3 , V_257 , V_3 -> V_243 ) ;
return 0 ;
}
static int F_128 ( struct V_218 * V_219 ,
struct V_220 * V_221 )
{
V_18 V_280 = V_219 -> V_242 ;
static const char * const V_288 [] = { L_37 , L_38 , L_39 } ;
static const char * const V_289 [] = { L_40 , L_41 , L_42 } ;
switch ( V_280 ) {
case V_290 :
F_83 ( V_221 , V_288 ) ;
break;
default:
F_83 ( V_221 , V_289 ) ;
break;
}
return 0 ;
}
static int F_129 ( struct V_218 * V_219 ,
struct V_228 * V_229 )
{
struct V_3 * V_3 = F_77 ( V_219 ) ;
V_18 V_280 = V_219 -> V_242 ;
F_36 ( & V_3 -> V_25 ) ;
V_229 -> V_224 . V_230 . V_231 [ 0 ] = F_126 ( V_3 , V_280 ) ;
F_38 ( & V_3 -> V_25 ) ;
return 0 ;
}
static int F_130 ( struct V_218 * V_219 ,
struct V_228 * V_229 )
{
struct V_3 * V_3 = F_77 ( V_219 ) ;
V_18 V_280 = V_219 -> V_242 ;
int V_247 ;
int V_8 ;
if ( ! F_13 ( V_3 ) )
return - V_125 ;
V_8 = V_229 -> V_224 . integer . V_224 [ 0 ] ;
if ( V_8 < 0 )
V_8 = 0 ;
if ( V_8 > 2 )
V_8 = 2 ;
F_36 ( & V_3 -> V_25 ) ;
V_247 = V_8 != F_126 ( V_3 , V_280 ) ;
F_127 ( V_3 , V_8 , V_280 ) ;
F_38 ( & V_3 -> V_25 ) ;
return V_247 ;
}
static int F_131 ( struct V_3 * V_3 )
{
if ( V_3 -> V_29 & V_30 )
return 2 ;
if ( V_3 -> V_29 & V_31 )
return 1 ;
return 0 ;
}
static int F_132 ( struct V_3 * V_3 , int V_245 )
{
V_3 -> V_29 &= ~ ( V_31 | V_30 ) ;
switch ( V_245 ) {
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
static int F_133 ( struct V_218 * V_219 ,
struct V_220 * V_221 )
{
static const char * const V_246 [] = { L_34 , L_35 , L_36 } ;
F_83 ( V_221 , V_246 ) ;
return 0 ;
}
static int F_134 ( struct V_218 * V_219 ,
struct V_228 * V_229 )
{
struct V_3 * V_3 = F_77 ( V_219 ) ;
F_36 ( & V_3 -> V_25 ) ;
V_229 -> V_224 . V_230 . V_231 [ 0 ] = F_131 ( V_3 ) ;
F_38 ( & V_3 -> V_25 ) ;
return 0 ;
}
static int F_135 ( struct V_218 * V_219 ,
struct V_228 * V_229 )
{
struct V_3 * V_3 = F_77 ( V_219 ) ;
int V_247 ;
int V_8 ;
if ( ! F_13 ( V_3 ) )
return - V_125 ;
V_8 = V_229 -> V_224 . integer . V_224 [ 0 ] ;
if ( V_8 < 0 )
V_8 = 0 ;
if ( V_8 > 2 )
V_8 = 2 ;
F_36 ( & V_3 -> V_25 ) ;
V_247 = V_8 != F_131 ( V_3 ) ;
F_132 ( V_3 , V_8 ) ;
F_38 ( & V_3 -> V_25 ) ;
return V_247 ;
}
static int F_136 ( struct V_218 * V_219 ,
struct V_220 * V_221 )
{
V_221 -> type = V_222 ;
V_221 -> V_223 = 3 ;
V_221 -> V_224 . integer . V_225 = 0 ;
V_221 -> V_224 . integer . V_226 = 65535 ;
V_221 -> V_224 . integer . V_227 = 1 ;
return 0 ;
}
static int F_137 ( struct V_218 * V_219 ,
struct V_228 * V_229 )
{
struct V_3 * V_3 = F_77 ( V_219 ) ;
int V_291 ;
int V_292 ;
V_291 = V_229 -> V_224 . integer . V_224 [ 0 ] ;
if ( V_291 < 0 )
V_291 = 0 ;
else if ( V_291 >= 2 * V_93 )
V_291 = 2 * V_93 - 1 ;
V_292 = V_229 -> V_224 . integer . V_224 [ 1 ] ;
if ( V_292 < 0 )
V_292 = 0 ;
else if ( V_292 >= V_93 )
V_292 = V_93 - 1 ;
F_36 ( & V_3 -> V_25 ) ;
if ( V_291 >= V_93 )
V_229 -> V_224 . integer . V_224 [ 2 ] =
F_8 ( V_3 , V_292 ,
V_291 - V_93 ) ;
else
V_229 -> V_224 . integer . V_224 [ 2 ] =
F_7 ( V_3 , V_292 , V_291 ) ;
F_38 ( & V_3 -> V_25 ) ;
return 0 ;
}
static int F_138 ( struct V_218 * V_219 ,
struct V_228 * V_229 )
{
struct V_3 * V_3 = F_77 ( V_219 ) ;
int V_247 ;
int V_291 ;
int V_292 ;
int V_154 ;
if ( ! F_13 ( V_3 ) )
return - V_125 ;
V_291 = V_229 -> V_224 . integer . V_224 [ 0 ] ;
V_292 = V_229 -> V_224 . integer . V_224 [ 1 ] ;
if ( V_291 < 0 || V_291 >= 2 * V_93 )
return - 1 ;
if ( V_292 < 0 || V_292 >= V_93 )
return - 1 ;
V_154 = V_229 -> V_224 . integer . V_224 [ 2 ] ;
F_36 ( & V_3 -> V_25 ) ;
if ( V_291 >= V_93 )
V_247 = V_154 != F_8 ( V_3 , V_292 ,
V_291 -
V_93 ) ;
else
V_247 = V_154 != F_7 ( V_3 , V_292 ,
V_291 ) ;
if ( V_247 ) {
if ( V_291 >= V_93 )
F_10 ( V_3 , V_292 ,
V_291 - V_93 ,
V_154 ) ;
else
F_9 ( V_3 , V_292 , V_291 ,
V_154 ) ;
}
F_38 ( & V_3 -> V_25 ) ;
return V_247 ;
}
static int F_139 ( struct V_218 * V_219 ,
struct V_220 * V_221 )
{
V_221 -> type = V_222 ;
V_221 -> V_223 = 1 ;
V_221 -> V_224 . integer . V_225 = 0 ;
V_221 -> V_224 . integer . V_226 = 64 ;
V_221 -> V_224 . integer . V_227 = 1 ;
return 0 ;
}
static int F_140 ( struct V_218 * V_219 ,
struct V_228 * V_229 )
{
struct V_3 * V_3 = F_77 ( V_219 ) ;
int V_293 ;
V_293 = V_229 -> V_156 . V_236 - 1 ;
if ( F_43 ( V_293 < 0 || V_293 >= V_93 ) )
return - V_123 ;
F_36 ( & V_3 -> V_25 ) ;
V_229 -> V_224 . integer . V_224 [ 0 ] =
( F_8 ( V_3 , V_293 , V_293 ) * 64 ) / V_155 ;
F_38 ( & V_3 -> V_25 ) ;
return 0 ;
}
static int F_141 ( struct V_218 * V_219 ,
struct V_228 * V_229 )
{
struct V_3 * V_3 = F_77 ( V_219 ) ;
int V_247 ;
int V_293 ;
int V_154 ;
if ( ! F_13 ( V_3 ) )
return - V_125 ;
V_293 = V_229 -> V_156 . V_236 - 1 ;
if ( F_43 ( V_293 < 0 || V_293 >= V_93 ) )
return - V_123 ;
V_154 = V_229 -> V_224 . integer . V_224 [ 0 ] * V_155 / 64 ;
F_36 ( & V_3 -> V_25 ) ;
V_247 =
V_154 != F_8 ( V_3 , V_293 ,
V_293 ) ;
if ( V_247 )
F_10 ( V_3 , V_293 , V_293 ,
V_154 ) ;
F_38 ( & V_3 -> V_25 ) ;
return V_247 ;
}
static int F_142 ( struct V_218 * V_219 ,
struct V_220 * V_221 )
{
static const char * const V_246 [] = { L_43 , L_44 , L_45 , L_46 } ;
F_83 ( V_221 , V_246 ) ;
return 0 ;
}
static int F_143 ( struct V_218 * V_219 ,
struct V_220 * V_221 )
{
static const char * const V_246 [] = { L_43 , L_44 } ;
F_83 ( V_221 , V_246 ) ;
return 0 ;
}
static int F_20 ( struct V_3 * V_3 )
{
int V_32 , V_33 ;
switch ( V_3 -> V_5 ) {
case V_36 :
V_32 = F_5 ( V_3 , V_38 ) ;
if ( V_32 & V_294 ) {
if ( V_32 & V_295 )
return 2 ;
else
return 1 ;
}
return 0 ;
break;
case V_53 :
V_33 = F_5 ( V_3 , V_37 ) ;
if ( V_33 & V_54 ) {
if ( V_33 & V_296 )
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
if ( V_32 & V_297 )
return 2 ;
else
return 1 ;
}
return 0 ;
}
static int F_145 ( struct V_3 * V_3 , int V_239 )
{
int V_32 , V_25 , V_298 ;
V_32 = F_5 ( V_3 , V_232 ) ;
V_25 = ( V_32 & ( 0x1 << V_239 ) ) ? 1 : 0 ;
V_298 = ( V_32 & ( 0x100 << V_239 ) ) ? 1 : 0 ;
if ( V_25 && V_298 )
return 2 ;
else if ( V_25 )
return 1 ;
return 0 ;
}
static int F_26 ( struct V_3 * V_3 )
{
int V_32 , V_25 = 0 , V_298 = 0 ;
switch ( V_3 -> V_5 ) {
case V_6 :
case V_4 :
V_32 = F_5 ( V_3 , V_299 ) ;
V_25 = ( V_32 & 0x400 ) ? 1 : 0 ;
V_298 = ( V_32 & 0x800 ) ? 1 : 0 ;
break;
case V_53 :
V_32 = F_5 ( V_3 , V_38 ) ;
V_25 = ( V_32 & V_300 ) ? 1 : 0 ;
V_298 = ( V_32 & V_301 ) ? 1 : 0 ;
break;
case V_36 :
V_32 = F_5 ( V_3 , V_37 ) ;
V_25 = ( V_32 & 0x100000 ) ? 1 : 0 ;
V_298 = ( V_32 & 0x200000 ) ? 1 : 0 ;
break;
case V_49 :
break;
}
if ( V_25 && V_298 )
return 2 ;
else if ( V_25 )
return 1 ;
return 0 ;
}
static int F_22 ( struct V_3 * V_3 , int V_239 )
{
int V_33 , V_25 , V_298 ;
V_33 = F_5 ( V_3 , V_37 ) ;
V_25 = ( V_33 & ( 0x0080 >> V_239 ) ) ? 1 : 0 ;
V_298 = ( V_33 & ( 0x8000 >> V_239 ) ) ? 1 : 0 ;
if ( V_298 )
return 2 ;
else if ( V_25 )
return 1 ;
return 0 ;
}
static int F_146 ( struct V_3 * V_3 , V_18 V_302 )
{
V_18 V_32 ;
V_32 = F_5 ( V_3 , V_270 + 4 ) ;
return ( V_32 & V_302 ) ? 1 : 0 ;
}
static int F_24 ( struct V_3 * V_3 )
{
int V_32 ;
if ( V_3 -> V_234 ) {
switch ( V_3 -> V_5 ) {
case V_53 :
V_32 = F_5 ( V_3 , V_38 ) ;
if ( V_32 & V_303 ) {
if ( V_32 & V_304 )
return 2 ;
else
return 1 ;
}
return 0 ;
case V_36 :
V_32 = F_5 ( V_3 , V_38 ) ;
if ( V_32 & V_305 ) {
if ( V_32 & V_304 )
return 2 ;
else
return 1 ;
}
return 0 ;
case V_6 :
case V_4 :
V_32 = F_5 ( V_3 , V_232 ) ;
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
static int F_147 ( struct V_218 * V_219 ,
struct V_228 * V_229 )
{
struct V_3 * V_3 = F_77 ( V_219 ) ;
int V_8 = - 1 ;
switch ( V_3 -> V_5 ) {
case V_6 :
switch ( V_219 -> V_242 ) {
case 0 :
V_8 = F_20 ( V_3 ) ; break;
case 7 :
V_8 = F_24 ( V_3 ) ; break;
case 8 :
V_8 = F_26 ( V_3 ) ; break;
default:
V_8 = F_145 ( V_3 ,
V_219 -> V_242 - 1 ) ;
}
break;
case V_4 :
switch ( V_219 -> V_242 ) {
case 0 :
V_8 = F_20 ( V_3 ) ; break;
case 4 :
V_8 = F_24 ( V_3 ) ; break;
case 5 :
V_8 = F_26 ( V_3 ) ; break;
default:
V_8 = F_145 ( V_3 ,
V_219 -> V_242 - 1 ) ;
}
break;
case V_53 :
switch ( V_219 -> V_242 ) {
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
switch ( V_219 -> V_242 ) {
case 0 :
V_8 = F_20 ( V_3 ) ; break;
case 9 :
V_8 = F_24 ( V_3 ) ; break;
case 10 :
V_8 = F_26 ( V_3 ) ; break;
default:
V_8 = F_22 ( V_3 ,
V_219 -> V_242 - 1 ) ;
}
break;
}
if ( V_3 -> V_234 ) {
switch ( V_219 -> V_242 ) {
case 11 :
V_8 = F_146 ( V_3 , V_306 ) ;
break;
case 12 :
V_8 = F_146 ( V_3 ,
V_273 ) ;
break;
default:
break;
}
}
if ( - 1 == V_8 )
V_8 = 3 ;
V_229 -> V_224 . V_230 . V_231 [ 0 ] = V_8 ;
return 0 ;
}
static void F_148 ( struct V_3 * V_3 )
{
unsigned int V_307 [ 4 ] = { 0 , 0 , 0 , 0 } ;
switch ( V_3 -> V_234 -> V_168 ) {
case 0 :
V_307 [ 2 ] |= V_308 ;
break;
case 1 :
V_307 [ 2 ] |= V_309 ;
break;
default:
break;
}
switch ( V_3 -> V_234 -> V_310 ) {
case 1 :
V_307 [ 1 ] |= V_274 ;
break;
case 2 :
V_307 [ 1 ] |= V_275 ;
break;
case 3 :
V_307 [ 1 ] |= V_275 +
V_311 ;
break;
case 4 :
V_307 [ 1 ] |= V_274 +
V_275 ;
break;
case 5 :
V_307 [ 1 ] |= V_274 +
V_275 +
V_311 ;
break;
default:
break;
}
switch ( V_3 -> V_234 -> V_312 ) {
case 1 :
V_307 [ 2 ] |= V_313 ;
break;
case 2 :
V_307 [ 2 ] |= V_314 ;
break;
default:
break;
}
switch ( V_3 -> V_234 -> V_315 ) {
case 1 :
V_307 [ 2 ] |= V_316 ;
break;
case 2 :
V_307 [ 2 ] |= V_317 ;
break;
default:
break;
}
switch ( V_3 -> V_234 -> V_318 ) {
case 1 :
V_307 [ 2 ] |= V_319 ;
break;
case 2 :
V_307 [ 2 ] |= V_320 ;
break;
case 3 :
V_307 [ 2 ] |= V_319 + V_321 ;
break;
case 4 :
V_307 [ 2 ] |= V_320 + V_321 ;
break;
default:
break;
}
if ( 1 == V_3 -> V_234 -> V_322 ) {
V_307 [ 2 ] |= V_323 ;
}
F_3 ( V_3 , V_324 , V_307 [ 0 ] ) ;
F_3 ( V_3 , V_324 + 4 , V_307 [ 1 ] ) ;
F_3 ( V_3 , V_324 + 8 , V_307 [ 2 ] ) ;
F_3 ( V_3 , V_324 + 12 , V_307 [ 3 ] ) ;
}
static int F_149 ( struct V_218 * V_219 ,
struct V_220 * V_221 )
{
static const char * const V_246 [] = { L_47 , L_48 } ;
F_83 ( V_221 , V_246 ) ;
return 0 ;
}
static int F_150 ( struct V_218 * V_219 ,
struct V_228 * V_229 )
{
struct V_3 * V_3 = F_77 ( V_219 ) ;
V_229 -> V_224 . V_230 . V_231 [ 0 ] = V_3 -> V_234 -> V_315 ;
return 0 ;
}
static int F_151 ( struct V_218 * V_219 ,
struct V_228 * V_229 )
{
struct V_3 * V_3 = F_77 ( V_219 ) ;
if ( V_3 -> V_234 -> V_315 != V_229 -> V_224 . V_230 . V_231 [ 0 ] ) {
V_3 -> V_234 -> V_315 = V_229 -> V_224 . V_230 . V_231 [ 0 ] ;
F_148 ( V_3 ) ;
return 1 ;
}
return 0 ;
}
static int F_152 ( struct V_218 * V_219 ,
struct V_220 * V_221 )
{
static const char * const V_246 [] = { L_49 , L_50 , L_51 ,
L_52 , L_53 } ;
F_83 ( V_221 , V_246 ) ;
return 0 ;
}
static int F_153 ( struct V_218 * V_219 ,
struct V_228 * V_229 )
{
struct V_3 * V_3 = F_77 ( V_219 ) ;
V_229 -> V_224 . V_230 . V_231 [ 0 ] = V_3 -> V_234 -> V_318 ;
return 0 ;
}
static int F_154 ( struct V_218 * V_219 ,
struct V_228 * V_229 )
{
struct V_3 * V_3 = F_77 ( V_219 ) ;
if ( V_3 -> V_234 -> V_318 != V_229 -> V_224 . V_230 . V_231 [ 0 ] ) {
V_3 -> V_234 -> V_318 = V_229 -> V_224 . V_230 . V_231 [ 0 ] ;
F_148 ( V_3 ) ;
return 1 ;
}
return 0 ;
}
static int F_155 ( struct V_218 * V_219 ,
struct V_220 * V_221 )
{
static const char * const V_246 [] = { L_54 , L_55 , L_56 } ;
F_83 ( V_221 , V_246 ) ;
return 0 ;
}
static int F_156 ( struct V_218 * V_219 ,
struct V_228 * V_229 )
{
struct V_3 * V_3 = F_77 ( V_219 ) ;
V_229 -> V_224 . V_230 . V_231 [ 0 ] = V_3 -> V_234 -> V_312 ;
return 0 ;
}
static int F_157 ( struct V_218 * V_219 ,
struct V_228 * V_229 )
{
struct V_3 * V_3 = F_77 ( V_219 ) ;
if ( V_3 -> V_234 -> V_312 != V_229 -> V_224 . V_230 . V_231 [ 0 ] ) {
V_3 -> V_234 -> V_312 = V_229 -> V_224 . V_230 . V_231 [ 0 ] ;
F_148 ( V_3 ) ;
return 1 ;
}
return 0 ;
}
static int F_158 ( struct V_218 * V_219 ,
struct V_220 * V_221 )
{
static const char * const V_246 [] = { L_28 , L_29 , L_57 ,
L_58 , L_31 , L_59 } ;
F_83 ( V_221 , V_246 ) ;
return 0 ;
}
static int F_159 ( struct V_218 * V_219 ,
struct V_228 * V_229 )
{
struct V_3 * V_3 = F_77 ( V_219 ) ;
V_229 -> V_224 . V_230 . V_231 [ 0 ] = V_3 -> V_234 -> V_310 ;
return 0 ;
}
static int F_160 ( struct V_218 * V_219 ,
struct V_228 * V_229 )
{
struct V_3 * V_3 = F_77 ( V_219 ) ;
if ( V_3 -> V_234 -> V_310 != V_229 -> V_224 . V_230 . V_231 [ 0 ] ) {
V_3 -> V_234 -> V_310 = V_229 -> V_224 . V_230 . V_231 [ 0 ] ;
F_148 ( V_3 ) ;
return 1 ;
}
return 0 ;
}
static int F_161 ( struct V_218 * V_219 ,
struct V_220 * V_221 )
{
static const char * const V_246 [] = { L_60 , L_61 , L_62 } ;
F_83 ( V_221 , V_246 ) ;
return 0 ;
}
static int F_162 ( struct V_218 * V_219 ,
struct V_228 * V_229 )
{
struct V_3 * V_3 = F_77 ( V_219 ) ;
V_229 -> V_224 . V_230 . V_231 [ 0 ] = V_3 -> V_234 -> V_168 ;
return 0 ;
}
static int F_163 ( struct V_218 * V_219 ,
struct V_228 * V_229 )
{
struct V_3 * V_3 = F_77 ( V_219 ) ;
if ( V_3 -> V_234 -> V_168 != V_229 -> V_224 . V_230 . V_231 [ 0 ] ) {
V_3 -> V_234 -> V_168 = V_229 -> V_224 . V_230 . V_231 [ 0 ] ;
F_148 ( V_3 ) ;
return 1 ;
}
return 0 ;
}
static int F_164 ( struct V_218 * V_219 ,
struct V_220 * V_221 )
{
V_221 -> type = V_325 ;
V_221 -> V_223 = 1 ;
V_221 -> V_224 . integer . V_225 = 0 ;
V_221 -> V_224 . integer . V_226 = 1 ;
return 0 ;
}
static int F_165 ( struct V_218 * V_219 ,
struct V_228 * V_229 )
{
struct V_3 * V_3 = F_77 ( V_219 ) ;
V_229 -> V_224 . V_230 . V_231 [ 0 ] = V_3 -> V_234 -> V_322 ;
return 0 ;
}
static int F_166 ( struct V_218 * V_219 ,
struct V_228 * V_229 )
{
struct V_3 * V_3 = F_77 ( V_219 ) ;
if ( V_3 -> V_234 -> V_322 != V_229 -> V_224 . V_230 . V_231 [ 0 ] ) {
V_3 -> V_234 -> V_322 = V_229 -> V_224 . V_230 . V_231 [ 0 ] ;
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
V_3 -> V_326 [ V_19 ] -> V_327 [ 0 ] . V_328 =
V_329 |
V_330 |
V_331 ;
} else {
V_3 -> V_326 [ V_19 ] -> V_327 [ 0 ] . V_328 =
V_332 |
V_331 ;
}
F_168 ( V_3 -> V_106 , V_333 |
V_334 ,
& V_3 -> V_326 [ V_19 ] -> V_156 ) ;
}
return 0 ;
}
static int F_169 ( struct V_179 * V_106 ,
struct V_3 * V_3 )
{
unsigned int V_239 , V_335 ;
int V_180 ;
struct V_218 * V_336 ;
struct V_337 * V_338 = NULL ;
switch ( V_3 -> V_5 ) {
case V_53 :
V_338 = V_339 ;
V_335 = F_170 ( V_339 ) ;
break;
case V_49 :
V_338 = V_340 ;
V_335 = F_170 ( V_340 ) ;
break;
case V_4 :
V_338 = V_341 ;
V_335 = F_170 ( V_341 ) ;
break;
case V_6 :
V_338 = V_342 ;
V_335 = F_170 ( V_342 ) ;
break;
case V_36 :
V_338 = V_343 ;
V_335 = F_170 ( V_343 ) ;
break;
}
if ( NULL != V_338 ) {
for ( V_239 = 0 ; V_239 < V_335 ; V_239 ++ ) {
V_180 = F_171 ( V_106 ,
F_172 ( & V_338 [ V_239 ] , V_3 ) ) ;
if ( V_180 < 0 )
return V_180 ;
}
}
V_344 . V_206 = L_63 ;
if ( V_3 -> V_110 >= 128000 ) {
V_335 = V_3 -> V_149 ;
} else if ( V_3 -> V_110 >= 64000 ) {
V_335 = V_3 -> V_143 ;
} else {
V_335 = V_3 -> V_135 ;
}
for ( V_239 = 0 ; V_239 < V_335 ; ++ V_239 ) {
V_344 . V_236 = V_239 + 1 ;
V_336 = F_172 ( & V_344 , V_3 ) ;
V_180 = F_171 ( V_106 , V_336 ) ;
if ( V_180 < 0 )
return V_180 ;
V_3 -> V_326 [ V_239 ] = V_336 ;
}
if ( V_3 -> V_234 ) {
V_338 = V_345 ;
V_335 = F_170 ( V_345 ) ;
for ( V_239 = 0 ; V_239 < V_335 ; V_239 ++ ) {
V_180 = F_171 ( V_106 ,
F_172 ( & V_338 [ V_239 ] , V_3 ) ) ;
if ( V_180 < 0 )
return V_180 ;
}
}
return 0 ;
}
static void
F_173 ( struct V_346 * V_347 ,
struct V_348 * V_349 )
{
struct V_3 * V_3 = V_347 -> V_175 ;
unsigned int V_32 , V_350 ;
int V_351 , V_352 , V_95 , V_353 , V_354 , V_355 ;
unsigned int V_97 ;
T_2 V_98 = 0 ;
V_18 V_28 ;
F_174 ( V_349 , L_64 ) ;
V_32 = F_5 ( V_3 , V_38 ) ;
V_350 = V_3 -> V_29 ;
if ( V_32 & V_356 ) {
F_174 ( V_349 , L_65 ) ;
V_351 = F_5 ( V_3 , V_270 + 4 ) ;
if ( V_351 & V_273 ) {
F_174 ( V_349 , L_66 ) ;
switch ( V_351 & ( V_274 |
V_275 ) ) {
case 0 :
F_174 ( V_349 , L_67 ) ;
break;
case V_274 :
F_174 ( V_349 , L_68 ) ;
break;
case V_275 :
F_174 ( V_349 , L_69 ) ;
break;
default:
F_174 ( V_349 , L_70 ) ;
break;
}
if ( V_351 & V_311 ) {
F_174 ( V_349 , L_71 ) ;
} else {
F_174 ( V_349 , L_72 ) ;
}
} else {
F_174 ( V_349 , L_73 ) ;
}
if ( V_351 & V_271 ) {
F_174 ( V_349 , L_74 ) ;
} else if ( V_351 & V_272 ) {
F_174 ( V_349 , L_75 ) ;
} else {
F_174 ( V_349 , L_76 ) ;
}
if ( V_351 & V_306 ) {
F_174 ( V_349 , L_77 ) ;
} else {
F_174 ( V_349 , L_78 ) ;
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
V_97 = F_5 ( V_3 , V_217 ) ;
F_174 ( V_349 , L_79 , V_97 ) ;
V_28 = F_41 ( V_98 , V_97 ) ;
if ( V_350 & V_30 ) {
V_28 *= 4 ;
} else if ( V_350 & V_31 ) {
V_28 *= 2 ;
}
F_174 ( V_349 , L_80 ,
( unsigned int ) V_28 ) ;
V_352 = F_5 ( V_3 , V_270 ) ;
V_95 = V_352 & 0xF ;
V_352 >>= 4 ;
V_95 += ( V_352 & 0x3 ) * 10 ;
V_352 >>= 4 ;
V_353 = V_352 & 0xF ;
V_352 >>= 4 ;
V_353 += ( V_352 & 0x7 ) * 10 ;
V_352 >>= 4 ;
V_354 = V_352 & 0xF ;
V_352 >>= 4 ;
V_354 += ( V_352 & 0x7 ) * 10 ;
V_352 >>= 4 ;
V_355 = V_352 & 0xF ;
V_352 >>= 4 ;
V_355 += ( V_352 & 0x3 ) * 10 ;
F_174 ( V_349 ,
L_81 ,
V_355 , V_354 , V_353 , V_95 ) ;
} else {
F_174 ( V_349 , L_82 ) ;
}
}
static void
F_175 ( struct V_346 * V_347 ,
struct V_348 * V_349 )
{
struct V_3 * V_3 = V_347 -> V_175 ;
unsigned int V_32 , V_33 ;
char * V_357 ;
char * V_358 ;
char * V_359 ;
int V_360 , V_361 ;
V_32 = F_5 ( V_3 , V_38 ) ;
V_33 = F_5 ( V_3 , V_37 ) ;
F_174 ( V_349 , L_83 ,
V_3 -> V_362 , V_3 -> V_106 -> V_363 + 1 ,
V_3 -> V_364 ,
( V_33 & V_365 ) |
( V_33 & V_366 ) | ( V_33 &
V_367 ) ) ;
F_174 ( V_349 , L_84 ,
( F_5 ( V_3 , V_195 ) >> 8 ) & 0xFFFFFF ,
V_3 -> V_368 ) ;
F_174 ( V_349 , L_85 ,
V_3 -> V_186 , V_3 -> V_369 , ( unsigned long ) V_3 -> V_9 ) ;
F_174 ( V_349 , L_86 ) ;
F_174 ( V_349 ,
L_87 ,
V_32 & V_370 ,
( V_32 & V_193 ) ? 1 : 0 ,
( V_32 & V_199 ) ? 1 : 0 ,
V_3 -> V_371 ) ;
F_174 ( V_349 ,
L_88
L_89 ,
( ( V_32 & V_86 ) ? 1 : 0 ) ,
( V_32 & V_85 ) ,
( V_32 & V_85 ) %
( 2 * ( int ) V_3 -> V_83 ) ,
( ( V_32 & V_85 ) - 64 ) %
( 2 * ( int ) V_3 -> V_83 ) ,
( long ) F_31 ( V_3 ) * 4 ) ;
F_174 ( V_349 ,
L_90 ,
F_5 ( V_3 , V_191 ) & 0xFF ,
F_5 ( V_3 , V_197 ) & 0xFF ,
F_5 ( V_3 , V_189 ) & 0xFF ,
F_5 ( V_3 , V_195 ) & 0xFF ) ;
F_174 ( V_349 ,
L_91 ,
F_5 ( V_3 , V_182 ) & 0xFF ,
F_5 ( V_3 , V_184 ) & 0xFF ) ;
F_174 ( V_349 ,
L_92
L_93 ,
V_3 -> V_29 , V_3 -> V_372 ,
V_32 , V_33 ) ;
F_174 ( V_349 , L_94 ) ;
V_360 = F_28 ( V_3 ) ;
F_174 ( V_349 ,
L_95 ,
V_360 , ( unsigned long ) V_3 -> V_83 ) ;
F_174 ( V_349 , L_96 ,
( V_3 -> V_29 & V_373 ) ? L_97 : L_98 ) ;
F_174 ( V_349 ,
L_99
L_100 ,
( V_3 -> V_29 & V_374 ) ? L_101 : L_98 ,
( V_3 -> V_29 & V_375 ) ? L_102 : L_103 ,
( V_3 -> V_29 & V_376 ) ? L_101 : L_98 ) ;
if ( ! ( V_3 -> V_29 & V_105 ) )
V_359 = L_9 ;
else
V_359 = L_8 ;
F_174 ( V_349 , L_104 , V_359 ) ;
switch ( F_96 ( V_3 ) ) {
case V_377 :
V_357 = L_22 ;
break;
case V_378 :
V_357 = L_105 ;
break;
case V_379 :
V_357 = L_19 ;
break;
case V_380 :
V_357 = L_20 ;
break;
default:
V_357 = L_106 ;
break;
}
F_174 ( V_349 , L_107 ,
V_357 ) ;
F_174 ( V_349 , L_108 ,
V_3 -> V_110 ) ;
F_174 ( V_349 , L_109 ) ;
V_360 = V_32 & V_297 ;
V_361 = V_33 & V_296 ;
F_174 ( V_349 , L_110 ,
( V_32 & V_50 ) ? ( V_360 ? L_45 : L_44 ) :
L_111 ,
( V_33 & V_54 ) ? ( V_361 ? L_45 : L_44 ) :
L_111 ) ;
switch ( F_19 ( V_3 ) ) {
case V_82 :
V_358 = L_20 ;
break;
case V_80 :
V_358 = L_19 ;
break;
case V_264 :
V_358 = L_22 ;
break;
case V_266 :
V_358 = L_105 ;
break;
case V_109 :
V_358 = L_112 ;
break;
default:
V_358 = L_113 ;
break;
}
F_174 ( V_349 ,
L_114 ,
V_358 , F_18 ( V_3 ) ,
( V_32 & V_68 ) >> 22 ,
( V_33 & V_56 ) >> 5 ) ;
F_174 ( V_349 , L_115 ,
( V_32 & V_381 ) ? L_116 : L_37 ,
( V_32 & V_382 ) ? L_117 :
L_118 ) ;
F_173 ( V_347 , V_349 ) ;
F_174 ( V_349 , L_119 ) ;
}
static void
F_176 ( struct V_346 * V_347 ,
struct V_348 * V_349 )
{
struct V_3 * V_3 = V_347 -> V_175 ;
unsigned int V_32 ;
unsigned int V_33 ;
unsigned int V_237 ;
unsigned int V_383 , V_384 ;
int V_385 ;
char * V_358 ;
int V_360 ;
V_32 = F_5 ( V_3 , V_38 ) ;
V_33 = F_5 ( V_3 , V_37 ) ;
V_237 = F_5 ( V_3 , V_238 ) ;
F_174 ( V_349 , L_120 ,
V_3 -> V_362 , V_3 -> V_106 -> V_363 + 1 ,
V_3 -> V_364 ) ;
F_174 ( V_349 , L_85 ,
V_3 -> V_186 , V_3 -> V_369 , ( unsigned long ) V_3 -> V_9 ) ;
F_174 ( V_349 , L_86 ) ;
F_174 ( V_349 ,
L_87 ,
V_32 & V_370 ,
( V_32 & V_193 ) ? 1 : 0 ,
( V_32 & V_199 ) ? 1 : 0 ,
V_3 -> V_371 ) ;
F_174 ( V_349 ,
L_88
L_89 ,
( ( V_32 & V_86 ) ? 1 : 0 ) ,
( V_32 & V_85 ) ,
( V_32 & V_85 ) %
( 2 * ( int ) V_3 -> V_83 ) ,
( ( V_32 & V_85 ) - 64 ) %
( 2 * ( int ) V_3 -> V_83 ) ,
( long ) F_31 ( V_3 ) * 4 ) ;
F_174 ( V_349 ,
L_90 ,
F_5 ( V_3 , V_191 ) & 0xFF ,
F_5 ( V_3 , V_197 ) & 0xFF ,
F_5 ( V_3 , V_189 ) & 0xFF ,
F_5 ( V_3 , V_195 ) & 0xFF ) ;
F_174 ( V_349 ,
L_91 ,
F_5 ( V_3 , V_182 ) & 0xFF ,
F_5 ( V_3 , V_184 ) & 0xFF ) ;
F_174 ( V_349 ,
L_92
L_93 ,
V_3 -> V_29 , V_3 -> V_372 ,
V_32 , V_33 ) ;
F_174 ( V_349 , L_94 ) ;
V_360 = F_28 ( V_3 ) ;
F_174 ( V_349 ,
L_95 ,
V_360 , ( unsigned long ) V_3 -> V_83 ) ;
F_174 ( V_349 , L_96 ,
( V_3 ->
V_29 & V_373 ) ? L_97 : L_98 ) ;
F_174 ( V_349 ,
L_121 ,
( V_3 ->
V_29 & V_374 ) ? L_101 : L_98 ,
( V_3 ->
V_29 & V_386 ) ? L_101 : L_98 ,
( V_3 ->
V_29 & V_387 ) ? L_101 : L_98 ) ;
V_385 = F_96 ( V_3 ) ;
if ( V_385 == 0 )
F_174 ( V_349 , L_122 ) ;
else
F_174 ( V_349 , L_123 ,
V_385 ) ;
F_174 ( V_349 , L_108 ,
V_3 -> V_110 ) ;
F_174 ( V_349 , L_124 ,
V_3 -> V_29 & V_284 ?
L_125 : L_126 ) ;
F_174 ( V_349 , L_127 ,
V_3 -> V_29 & V_286 ?
L_125 :
V_3 -> V_29 & V_287 ?
L_128 : L_126 ) ;
F_174 ( V_349 , L_109 ) ;
V_383 = V_32 & V_294 ;
V_384 = V_383 && ( V_32 & V_295 ) ;
F_174 ( V_349 , L_129 ,
( V_383 ) ? ( V_384 ? L_130 : L_131 ) : L_43 ,
F_1 ( ( V_32 >> V_233 ) & 0xF ) ) ;
for ( V_360 = 0 ; V_360 < 8 ; V_360 ++ ) {
F_174 ( V_349 , L_132 ,
V_360 + 1 ,
( V_33 & ( V_388 >> V_360 ) ) ?
L_130 : L_43 ,
F_1 ( ( V_237 >> ( 4 * V_360 ) ) & 0xF ) ) ;
}
switch ( F_19 ( V_3 ) ) {
case V_263 :
V_358 = L_21 ; break;
case V_39 :
V_358 = L_22 ; break;
case V_40 :
V_358 = L_11 ; break;
case V_41 :
V_358 = L_12 ; break;
case V_42 :
V_358 = L_13 ; break;
case V_43 :
V_358 = L_14 ; break;
case V_44 :
V_358 = L_15 ; break;
case V_45 :
V_358 = L_16 ; break;
case V_46 :
V_358 = L_17 ; break;
case V_47 :
V_358 = L_18 ; break;
case V_48 :
V_358 = L_19 ; break;
case V_262 :
V_358 = L_20 ; break;
default:
V_358 = L_113 ; break;
}
F_174 ( V_349 , L_133 , V_358 ) ;
F_173 ( V_347 , V_349 ) ;
F_174 ( V_349 , L_119 ) ;
}
static void
F_177 ( struct V_346 * V_347 ,
struct V_348 * V_349 )
{
struct V_3 * V_3 = V_347 -> V_175 ;
unsigned int V_389 , V_33 , V_390 , V_19 ;
unsigned int V_25 , V_298 ;
V_389 = F_5 ( V_3 , V_232 ) ;
V_33 = F_5 ( V_3 , V_235 ) ;
V_390 = F_5 ( V_3 , V_299 ) ;
F_174 ( V_349 , L_134 , V_389 ) ;
F_174 ( V_349 , L_135 , V_33 ) ;
F_174 ( V_349 , L_136 , V_390 ) ;
F_174 ( V_349 , L_137 ) ;
F_174 ( V_349 , L_138 ,
( F_74 ( V_3 ) == 0 ) ? L_139 : L_140 ) ;
F_174 ( V_349 , L_141 ,
F_73 ( V_3 ) ) ;
F_174 ( V_349 , L_142 ) ;
V_25 = 0x1 ;
V_298 = 0x100 ;
for ( V_19 = 0 ; V_19 < 8 ; V_19 ++ ) {
F_174 ( V_349 , L_143 ,
V_19 ,
( V_389 & V_25 ) ? 1 : 0 ,
( V_389 & V_298 ) ? 1 : 0 ,
V_241 [ ( V_33 >> ( V_19 * 4 ) ) & 0xF ] ) ;
V_25 = V_25 << 1 ;
V_298 = V_298 << 1 ;
}
F_174 ( V_349 , L_144 ,
( V_389 & 0x1000000 ) ? 1 : 0 ,
( V_389 & 0x2000000 ) ? 1 : 0 ,
V_241 [ ( V_389 >> 16 ) & 0xF ] ) ;
F_174 ( V_349 , L_145 ,
( V_389 & 0x4000000 ) ? 1 : 0 ,
( V_389 & 0x8000000 ) ? 1 : 0 ,
V_241 [ ( V_389 >> 20 ) & 0xF ] ) ;
F_174 ( V_349 , L_146 ,
( V_390 & 0x400 ) ? 1 : 0 ,
( V_390 & 0x800 ) ? 1 : 0 ,
V_241 [ ( V_33 >> 12 ) & 0xF ] ) ;
}
static void
F_178 ( struct V_346 * V_347 ,
struct V_348 * V_349 )
{
struct V_3 * V_3 = V_347 -> V_175 ;
int V_153 , V_19 ;
for ( V_19 = 0 ; V_19 < 256 ; V_19 += V_153 ) {
F_174 ( V_349 , L_147 , V_19 ) ;
for ( V_153 = 0 ; V_153 < 16 ; V_153 += 4 )
F_174 ( V_349 , L_148 , F_5 ( V_3 , V_19 + V_153 ) ) ;
F_174 ( V_349 , L_119 ) ;
}
}
static void F_179 ( struct V_346 * V_347 ,
struct V_348 * V_349 )
{
struct V_3 * V_3 = V_347 -> V_175 ;
int V_19 ;
F_174 ( V_349 , L_149 ) ;
for ( V_19 = 0 ; V_19 < V_3 -> V_132 ; V_19 ++ ) {
F_174 ( V_349 , L_150 , V_19 + 1 , V_3 -> V_136 [ V_19 ] ) ;
}
}
static void F_180 ( struct V_346 * V_347 ,
struct V_348 * V_349 )
{
struct V_3 * V_3 = V_347 -> V_175 ;
int V_19 ;
F_174 ( V_349 , L_149 ) ;
for ( V_19 = 0 ; V_19 < V_3 -> V_134 ; V_19 ++ ) {
F_174 ( V_349 , L_150 , V_19 + 1 , V_3 -> V_138 [ V_19 ] ) ;
}
}
static void F_181 ( struct V_3 * V_3 )
{
struct V_346 * V_347 ;
if ( ! F_182 ( V_3 -> V_106 , L_151 , & V_347 ) ) {
switch ( V_3 -> V_5 ) {
case V_36 :
F_183 ( V_347 , V_3 ,
F_176 ) ;
break;
case V_53 :
F_183 ( V_347 , V_3 ,
F_175 ) ;
break;
case V_49 :
break;
case V_6 :
F_183 ( V_347 , V_3 ,
F_177 ) ;
break;
case V_4 :
break;
}
}
if ( ! F_182 ( V_3 -> V_106 , L_152 , & V_347 ) ) {
F_183 ( V_347 , V_3 , F_179 ) ;
}
if ( ! F_182 ( V_3 -> V_106 , L_153 , & V_347 ) ) {
F_183 ( V_347 , V_3 , F_180 ) ;
}
#ifdef F_184
if ( ! F_182 ( V_3 -> V_106 , L_154 , & V_347 ) )
F_183 ( V_347 , V_3 ,
F_178 ) ;
#endif
}
static int F_185 ( struct V_3 * V_3 )
{
V_3 -> V_243 = 0 ;
switch ( V_3 -> V_5 ) {
case V_53 :
case V_49 :
V_3 -> V_29 =
0x2 + 0x8 + 0x10 + 0x80 + 0x400 + 0x4000 + 0x1000000 ;
break;
case V_6 :
case V_4 :
V_3 -> V_243 = 0x1 + 0x1000 ;
V_3 -> V_29 =
0x2 + 0x8 + 0x10 + 0x80 + 0x400 + 0x4000 + 0x1000000 ;
break;
case V_36 :
V_3 -> V_29 =
V_105 |
F_37 ( 7 ) |
V_249 |
V_373 |
V_391 ;
break;
}
F_3 ( V_3 , V_90 , V_3 -> V_29 ) ;
if ( V_36 == V_3 -> V_5 ) {
#ifdef F_186
V_3 -> V_372 = V_392 ;
#else
V_3 -> V_372 = 0 ;
#endif
F_3 ( V_3 , V_393 , V_3 -> V_372 ) ;
}
F_30 ( V_3 ) ;
F_47 ( V_3 , 0 * V_155 ) ;
if ( F_2 ( V_3 ) )
F_3 ( V_3 , V_257 , V_3 -> V_243 ) ;
F_44 ( V_3 , 48000 , 1 ) ;
return 0 ;
}
static T_3 F_187 ( int V_186 , void * V_394 )
{
struct V_3 * V_3 = (struct V_3 * ) V_394 ;
unsigned int V_32 ;
int V_19 , V_395 , V_157 , V_396 = 0 ;
V_32 = F_5 ( V_3 , V_38 ) ;
V_395 = V_32 & V_370 ;
V_157 = V_32 & ( V_193 | V_199 |
V_187 | V_204 ) ;
if ( ! V_395 && ! V_157 )
return V_397 ;
F_3 ( V_3 , V_398 , 0 ) ;
V_3 -> V_371 ++ ;
if ( V_395 ) {
if ( V_3 -> V_399 )
F_188 ( V_3 -> V_399 ) ;
if ( V_3 -> V_400 )
F_188 ( V_3 -> V_400 ) ;
}
if ( V_157 ) {
V_19 = 0 ;
while ( V_19 < V_3 -> V_216 ) {
if ( ( F_5 ( V_3 ,
V_3 -> V_157 [ V_19 ] . V_160 ) & 0xff ) &&
( V_32 & V_3 -> V_157 [ V_19 ] . V_186 ) ) {
V_3 -> V_29 &= ~ V_3 -> V_157 [ V_19 ] . V_170 ;
F_3 ( V_3 , V_90 ,
V_3 -> V_29 ) ;
V_3 -> V_157 [ V_19 ] . V_169 = 1 ;
V_396 = 1 ;
}
V_19 ++ ;
}
if ( V_396 )
F_189 ( & V_3 -> V_401 ) ;
}
return V_402 ;
}
static T_1 F_190 ( struct V_403
* V_172 )
{
struct V_3 * V_3 = F_191 ( V_172 ) ;
return F_31 ( V_3 ) ;
}
static int F_192 ( struct V_403 * V_172 )
{
struct V_404 * V_405 = V_172 -> V_405 ;
struct V_3 * V_3 = F_191 ( V_172 ) ;
struct V_403 * V_406 ;
if ( V_172 -> V_407 == V_408 )
V_406 = V_3 -> V_399 ;
else
V_406 = V_3 -> V_400 ;
if ( V_3 -> V_409 )
V_405 -> V_32 -> V_410 = F_31 ( V_3 ) ;
else
V_405 -> V_32 -> V_410 = 0 ;
if ( V_406 ) {
struct V_403 * V_87 ;
struct V_404 * V_411 = V_406 -> V_405 ;
F_193 (s, substream) {
if ( V_87 == V_406 ) {
V_411 -> V_32 -> V_410 =
V_405 -> V_32 -> V_410 ;
break;
}
}
}
return 0 ;
}
static int F_194 ( struct V_403 * V_172 ,
struct V_412 * V_413 )
{
struct V_3 * V_3 = F_191 ( V_172 ) ;
int V_180 ;
int V_19 ;
T_4 V_414 ;
T_4 V_415 ;
F_36 ( & V_3 -> V_25 ) ;
if ( V_172 -> V_416 -> V_407 == V_408 ) {
V_414 = V_3 -> V_26 ;
V_415 = V_3 -> V_27 ;
} else {
V_414 = V_3 -> V_27 ;
V_415 = V_3 -> V_26 ;
}
if ( V_415 > 0 && V_414 != V_415 ) {
if ( F_195 ( V_413 ) != V_3 -> V_110 ) {
F_38 ( & V_3 -> V_25 ) ;
F_196 ( V_413 ,
V_417 ) ;
return - V_125 ;
}
if ( F_197 ( V_413 ) != V_3 -> V_83 / 4 ) {
F_38 ( & V_3 -> V_25 ) ;
F_196 ( V_413 ,
V_418 ) ;
return - V_125 ;
}
}
F_38 ( & V_3 -> V_25 ) ;
F_36 ( & V_3 -> V_25 ) ;
V_180 = F_44 ( V_3 , F_195 ( V_413 ) , 0 ) ;
if ( V_180 < 0 ) {
F_198 ( V_3 -> V_106 -> V_107 , L_155 , V_180 ) ;
F_38 ( & V_3 -> V_25 ) ;
F_196 ( V_413 ,
V_417 ) ;
return V_180 ;
}
F_38 ( & V_3 -> V_25 ) ;
V_180 = F_35 ( V_3 ,
F_197 ( V_413 ) ) ;
if ( V_180 < 0 ) {
F_198 ( V_3 -> V_106 -> V_107 ,
L_156 , V_180 ) ;
F_196 ( V_413 ,
V_418 ) ;
return V_180 ;
}
V_180 =
F_199 ( V_172 , V_419 ) ;
if ( V_180 < 0 ) {
F_198 ( V_3 -> V_106 -> V_107 ,
L_157 , V_180 ) ;
return V_180 ;
}
if ( V_172 -> V_407 == V_408 ) {
F_200 ( V_3 , V_172 , V_420 ,
F_201 ( V_413 ) ) ;
for ( V_19 = 0 ; V_19 < F_201 ( V_413 ) ; ++ V_19 )
F_12 ( V_3 , V_19 , 1 ) ;
V_3 -> V_92 =
( unsigned char * ) V_172 -> V_405 -> V_421 ;
F_202 ( V_3 -> V_106 -> V_107 ,
L_158 ,
V_3 -> V_92 ) ;
} else {
F_200 ( V_3 , V_172 , V_422 ,
F_201 ( V_413 ) ) ;
for ( V_19 = 0 ; V_19 < F_201 ( V_413 ) ; ++ V_19 )
F_11 ( V_3 , V_19 , 1 ) ;
V_3 -> V_423 =
( unsigned char * ) V_172 -> V_405 -> V_421 ;
F_202 ( V_3 -> V_106 -> V_107 ,
L_159 ,
V_3 -> V_423 ) ;
}
if ( V_3 -> V_5 == V_36 ) {
return 0 ;
}
if ( V_424 == F_203 ( V_413 ) ) {
if ( ! ( V_3 -> V_29 & V_425 ) )
F_198 ( V_3 -> V_106 -> V_107 ,
L_160 ) ;
V_3 -> V_29 |= V_425 ;
} else if ( V_426 == F_203 ( V_413 ) ) {
if ( V_3 -> V_29 & V_425 )
F_198 ( V_3 -> V_106 -> V_107 ,
L_161 ) ;
V_3 -> V_29 &= ~ V_425 ;
}
F_3 ( V_3 , V_90 , V_3 -> V_29 ) ;
return 0 ;
}
static int F_204 ( struct V_403 * V_172 )
{
int V_19 ;
struct V_3 * V_3 = F_191 ( V_172 ) ;
if ( V_172 -> V_407 == V_408 ) {
for ( V_19 = 0 ; V_19 < V_3 -> V_134 ; ++ V_19 )
F_12 ( V_3 , V_19 , 0 ) ;
V_3 -> V_92 = NULL ;
} else {
for ( V_19 = 0 ; V_19 < V_3 -> V_132 ; ++ V_19 )
F_11 ( V_3 , V_19 , 0 ) ;
V_3 -> V_423 = NULL ;
}
F_205 ( V_172 ) ;
return 0 ;
}
static int F_206 ( struct V_403 * V_172 ,
struct V_427 * V_428 )
{
struct V_3 * V_3 = F_191 ( V_172 ) ;
if ( V_172 -> V_407 == V_408 ) {
if ( F_43 ( V_428 -> V_293 >= V_3 -> V_134 ) ) {
F_198 ( V_3 -> V_106 -> V_107 ,
L_162 ,
V_428 -> V_293 ) ;
return - V_123 ;
}
if ( V_3 -> V_130 [ V_428 -> V_293 ] < 0 ) {
F_198 ( V_3 -> V_106 -> V_107 ,
L_163 ,
V_428 -> V_293 ) ;
return - V_123 ;
}
V_428 -> V_429 = V_3 -> V_130 [ V_428 -> V_293 ] *
V_94 ;
} else {
if ( F_43 ( V_428 -> V_293 >= V_3 -> V_132 ) ) {
F_198 ( V_3 -> V_106 -> V_107 ,
L_164 ,
V_428 -> V_293 ) ;
return - V_123 ;
}
if ( V_3 -> V_128 [ V_428 -> V_293 ] < 0 ) {
F_198 ( V_3 -> V_106 -> V_107 ,
L_165 ,
V_428 -> V_293 ) ;
return - V_123 ;
}
V_428 -> V_429 = V_3 -> V_128 [ V_428 -> V_293 ] *
V_94 ;
}
V_428 -> V_430 = 0 ;
V_428 -> V_227 = 32 ;
return 0 ;
}
static int F_207 ( struct V_403 * V_172 ,
unsigned int V_431 , void * V_215 )
{
switch ( V_431 ) {
case V_432 :
return F_192 ( V_172 ) ;
case V_433 :
{
struct V_427 * V_428 = V_215 ;
return F_206 ( V_172 , V_428 ) ;
}
default:
break;
}
return F_208 ( V_172 , V_431 , V_215 ) ;
}
static int F_209 ( struct V_403 * V_172 , int V_431 )
{
struct V_3 * V_3 = F_191 ( V_172 ) ;
struct V_403 * V_406 ;
int V_409 ;
F_210 ( & V_3 -> V_25 ) ;
V_409 = V_3 -> V_409 ;
switch ( V_431 ) {
case V_434 :
V_409 |= 1 << V_172 -> V_407 ;
break;
case V_435 :
V_409 &= ~ ( 1 << V_172 -> V_407 ) ;
break;
default:
F_40 () ;
F_211 ( & V_3 -> V_25 ) ;
return - V_123 ;
}
if ( V_172 -> V_407 == V_408 )
V_406 = V_3 -> V_399 ;
else
V_406 = V_3 -> V_400 ;
if ( V_406 ) {
struct V_403 * V_87 ;
F_193 (s, substream) {
if ( V_87 == V_406 ) {
F_212 ( V_87 , V_172 ) ;
if ( V_431 == V_434 )
V_409 |= 1 << V_87 -> V_407 ;
else
V_409 &= ~ ( 1 << V_87 -> V_407 ) ;
goto V_436;
}
}
if ( V_431 == V_434 ) {
if ( ! ( V_409 & ( 1 << V_408 ) )
&& V_172 -> V_407 ==
V_437 )
F_34 ( V_3 ) ;
} else {
if ( V_409 &&
V_172 -> V_407 == V_408 )
F_34 ( V_3 ) ;
}
} else {
if ( V_172 -> V_407 == V_437 )
F_34 ( V_3 ) ;
}
V_436:
F_212 ( V_172 , V_172 ) ;
if ( ! V_3 -> V_409 && V_409 )
F_32 ( V_3 ) ;
else if ( V_3 -> V_409 && ! V_409 )
F_33 ( V_3 ) ;
V_3 -> V_409 = V_409 ;
F_211 ( & V_3 -> V_25 ) ;
return 0 ;
}
static int F_213 ( struct V_403 * V_172 )
{
return 0 ;
}
static int F_214 ( struct V_412 * V_413 ,
struct V_438 * V_439 )
{
struct V_3 * V_3 = V_439 -> V_440 ;
struct V_441 * V_442 =
F_215 ( V_413 , V_443 ) ;
struct V_441 * V_444 =
F_215 ( V_413 , V_417 ) ;
if ( V_444 -> V_225 > 96000 && V_444 -> V_226 <= 192000 ) {
struct V_441 V_445 = {
. V_225 = V_3 -> V_148 ,
. V_226 = V_3 -> V_148 ,
. integer = 1 ,
} ;
return F_216 ( V_442 , & V_445 ) ;
} else if ( V_444 -> V_225 > 48000 && V_444 -> V_226 <= 96000 ) {
struct V_441 V_445 = {
. V_225 = V_3 -> V_142 ,
. V_226 = V_3 -> V_142 ,
. integer = 1 ,
} ;
return F_216 ( V_442 , & V_445 ) ;
} else if ( V_444 -> V_226 < 64000 ) {
struct V_441 V_445 = {
. V_225 = V_3 -> V_133 ,
. V_226 = V_3 -> V_133 ,
. integer = 1 ,
} ;
return F_216 ( V_442 , & V_445 ) ;
}
return 0 ;
}
static int F_217 ( struct V_412 * V_413 ,
struct V_438 * V_439 )
{
struct V_3 * V_3 = V_439 -> V_440 ;
struct V_441 * V_442 =
F_215 ( V_413 , V_443 ) ;
struct V_441 * V_444 =
F_215 ( V_413 , V_417 ) ;
if ( V_444 -> V_225 > 96000 && V_444 -> V_226 <= 192000 ) {
struct V_441 V_445 = {
. V_225 = V_3 -> V_149 ,
. V_226 = V_3 -> V_149 ,
. integer = 1 ,
} ;
return F_216 ( V_442 , & V_445 ) ;
} else if ( V_444 -> V_225 > 48000 && V_444 -> V_226 <= 96000 ) {
struct V_441 V_445 = {
. V_225 = V_3 -> V_143 ,
. V_226 = V_3 -> V_143 ,
. integer = 1 ,
} ;
return F_216 ( V_442 , & V_445 ) ;
} else if ( V_444 -> V_226 < 64000 ) {
struct V_441 V_445 = {
. V_225 = V_3 -> V_135 ,
. V_226 = V_3 -> V_135 ,
. integer = 1 ,
} ;
return F_216 ( V_442 , & V_445 ) ;
} else {
}
return 0 ;
}
static int F_218 ( struct V_412 * V_413 ,
struct V_438 * V_439 )
{
struct V_3 * V_3 = V_439 -> V_440 ;
struct V_441 * V_442 =
F_215 ( V_413 , V_443 ) ;
struct V_441 * V_444 =
F_215 ( V_413 , V_417 ) ;
if ( V_442 -> V_225 >= V_3 -> V_133 ) {
struct V_441 V_445 = {
. V_225 = 32000 ,
. V_226 = 48000 ,
. integer = 1 ,
} ;
return F_216 ( V_444 , & V_445 ) ;
} else if ( V_442 -> V_226 <= V_3 -> V_148 ) {
struct V_441 V_445 = {
. V_225 = 128000 ,
. V_226 = 192000 ,
. integer = 1 ,
} ;
return F_216 ( V_444 , & V_445 ) ;
} else if ( V_442 -> V_226 <= V_3 -> V_142 ) {
struct V_441 V_445 = {
. V_225 = 64000 ,
. V_226 = 96000 ,
. integer = 1 ,
} ;
return F_216 ( V_444 , & V_445 ) ;
}
return 0 ;
}
static int F_219 ( struct V_412 * V_413 ,
struct V_438 * V_439 )
{
struct V_3 * V_3 = V_439 -> V_440 ;
struct V_441 * V_442 =
F_215 ( V_413 , V_443 ) ;
struct V_441 * V_444 =
F_215 ( V_413 , V_417 ) ;
if ( V_442 -> V_225 >= V_3 -> V_135 ) {
struct V_441 V_445 = {
. V_225 = 32000 ,
. V_226 = 48000 ,
. integer = 1 ,
} ;
return F_216 ( V_444 , & V_445 ) ;
} else if ( V_442 -> V_226 <= V_3 -> V_149 ) {
struct V_441 V_445 = {
. V_225 = 128000 ,
. V_226 = 192000 ,
. integer = 1 ,
} ;
return F_216 ( V_444 , & V_445 ) ;
} else if ( V_442 -> V_226 <= V_3 -> V_143 ) {
struct V_441 V_445 = {
. V_225 = 64000 ,
. V_226 = 96000 ,
. integer = 1 ,
} ;
return F_216 ( V_444 , & V_445 ) ;
}
return 0 ;
}
static int F_220 ( struct V_412 * V_413 ,
struct V_438 * V_439 )
{
unsigned int V_338 [ 3 ] ;
struct V_3 * V_3 = V_439 -> V_440 ;
struct V_441 * V_442 = F_215 ( V_413 ,
V_443 ) ;
V_338 [ 0 ] = V_3 -> V_148 ;
V_338 [ 1 ] = V_3 -> V_142 ;
V_338 [ 2 ] = V_3 -> V_133 ;
return F_221 ( V_442 , 3 , V_338 , 0 ) ;
}
static int F_222 ( struct V_412 * V_413 ,
struct V_438 * V_439 )
{
unsigned int V_338 [ 3 ] ;
struct V_3 * V_3 = V_439 -> V_440 ;
struct V_441 * V_442 = F_215 ( V_413 ,
V_443 ) ;
V_338 [ 0 ] = V_3 -> V_149 ;
V_338 [ 1 ] = V_3 -> V_143 ;
V_338 [ 2 ] = V_3 -> V_135 ;
return F_221 ( V_442 , 3 , V_338 , 0 ) ;
}
static int F_223 ( struct V_403 * V_172 )
{
struct V_3 * V_3 = F_191 ( V_172 ) ;
struct V_404 * V_405 = V_172 -> V_405 ;
bool V_446 = ( V_172 -> V_407 == V_408 ) ;
F_36 ( & V_3 -> V_25 ) ;
F_224 ( V_172 ) ;
V_405 -> V_447 = ( V_446 ) ? V_448 :
V_449 ;
if ( V_446 ) {
if ( V_3 -> V_399 == NULL )
F_33 ( V_3 ) ;
V_3 -> V_26 = V_450 -> V_451 ;
V_3 -> V_400 = V_172 ;
} else {
if ( V_3 -> V_400 == NULL )
F_33 ( V_3 ) ;
V_3 -> V_27 = V_450 -> V_451 ;
V_3 -> V_399 = V_172 ;
}
F_38 ( & V_3 -> V_25 ) ;
F_225 ( V_405 , 0 , 32 , 24 ) ;
F_226 ( V_405 , 0 , V_418 ) ;
switch ( V_3 -> V_5 ) {
case V_4 :
case V_6 :
F_227 ( V_405 ,
V_418 ,
32 , 4096 ) ;
F_227 ( V_405 ,
V_452 ,
16384 , 16384 ) ;
break;
default:
F_227 ( V_405 ,
V_418 ,
64 , 8192 ) ;
F_227 ( V_405 ,
V_453 ,
2 , 2 ) ;
break;
}
if ( V_36 == V_3 -> V_5 ) {
V_405 -> V_447 . V_454 |= V_455 ;
F_228 ( V_405 , 0 , V_417 ,
& V_456 ) ;
} else {
F_229 ( V_405 , 0 , V_417 ,
( V_446 ?
F_219 :
F_218 ) , V_3 ,
V_443 , - 1 ) ;
}
F_229 ( V_405 , 0 , V_443 ,
( V_446 ? F_222 :
F_220 ) , V_3 ,
V_443 , - 1 ) ;
F_229 ( V_405 , 0 , V_443 ,
( V_446 ? F_217 :
F_214 ) , V_3 ,
V_417 , - 1 ) ;
return 0 ;
}
static int F_230 ( struct V_403 * V_172 )
{
struct V_3 * V_3 = F_191 ( V_172 ) ;
bool V_446 = ( V_172 -> V_407 == V_408 ) ;
F_36 ( & V_3 -> V_25 ) ;
if ( V_446 ) {
V_3 -> V_26 = - 1 ;
V_3 -> V_400 = NULL ;
} else {
V_3 -> V_27 = - 1 ;
V_3 -> V_399 = NULL ;
}
F_38 ( & V_3 -> V_25 ) ;
return 0 ;
}
static int F_231 ( struct V_457 * V_447 , struct V_458 * V_458 )
{
return 0 ;
}
static inline int F_232 ( void T_5 * V_459 , void T_6 * V_460 )
{
V_18 V_8 = F_6 ( V_460 ) ;
return F_233 ( V_459 , & V_8 , 4 ) ;
}
static int F_234 ( struct V_457 * V_447 , struct V_458 * V_458 ,
unsigned int V_431 , unsigned long V_215 )
{
void T_5 * V_461 = ( void T_5 * ) V_215 ;
struct V_3 * V_3 = V_447 -> V_175 ;
struct V_462 V_13 ;
struct V_463 V_428 ;
struct V_464 V_32 ;
struct V_465 V_465 ;
struct V_466 * V_467 ;
struct V_468 V_352 ;
unsigned int V_469 ;
long unsigned int V_87 ;
int V_19 = 0 ;
switch ( V_431 ) {
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
V_467 -> V_488 = V_285 ;
} else {
V_467 -> V_488 = V_490 ;
}
V_467 -> V_33 = F_5 ( V_3 , V_37 ) ;
V_87 = F_233 ( V_461 , V_467 , sizeof( struct V_466 ) ) ;
if ( 0 != V_87 ) {
return - V_491 ;
}
break;
case V_492 :
V_352 . V_352 = F_5 ( V_3 , V_270 ) ;
V_19 = F_5 ( V_3 , V_270 + 4 ) ;
if ( V_19 & V_273 ) {
switch ( V_19 & ( V_274 |
V_275 ) ) {
case 0 :
V_352 . V_493 = V_276 ;
break;
case V_274 :
V_352 . V_493 = V_277 ;
break;
case V_275 :
V_352 . V_493 = V_278 ;
break;
default:
V_352 . V_493 = V_279 ;
break;
}
if ( V_19 & V_311 ) {
V_352 . V_494 = V_495 ;
} else {
V_352 . V_494 = V_496 ;
}
} else {
V_352 . V_493 = V_497 ;
V_352 . V_494 = V_498 ;
}
if ( V_19 & V_271 ) {
V_352 . V_499 = V_500 ;
} else if ( V_19 & V_272 ) {
V_352 . V_499 = V_501 ;
} else {
V_352 . V_499 = V_502 ;
}
V_87 = F_233 ( V_461 , & V_352 , sizeof( struct V_468 ) ) ;
if ( 0 != V_87 ) {
return - V_491 ;
}
break;
case V_503 :
memset ( & V_428 , 0 , sizeof( V_428 ) ) ;
F_36 ( & V_3 -> V_25 ) ;
V_428 . V_357 = F_96 ( V_3 ) ;
V_428 . V_504 = F_20 ( V_3 ) ;
V_428 . V_110 = V_3 -> V_110 ;
V_428 . V_505 =
F_18 ( V_3 ) ;
V_428 . V_359 = F_74 ( V_3 ) ;
V_428 . V_506 = F_90 ( V_3 ) ;
V_428 . V_358 = F_19 ( V_3 ) ;
V_428 . V_507 = F_108 ( V_3 , V_373 ) ;
V_428 . V_508 = 0 ;
F_38 ( & V_3 -> V_25 ) ;
if ( F_233 ( V_461 , & V_428 , sizeof( V_428 ) ) )
return - V_491 ;
break;
case V_509 :
memset ( & V_32 , 0 , sizeof( V_32 ) ) ;
V_32 . V_510 = V_3 -> V_5 ;
V_32 . V_511 = F_19 ( V_3 ) ;
V_32 . V_512 = 110069313433624ULL ;
V_32 . V_513 = F_5 ( V_3 , V_217 ) ;
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
( V_469 & V_381 ) ? 1 : 0 ;
V_32 . V_514 . V_515 . V_521 =
( V_469 & V_382 ) ? 1 : 0 ;
V_32 . V_514 . V_515 . V_522 = 0 ;
default:
break;
}
if ( F_233 ( V_461 , & V_32 , sizeof( V_32 ) ) )
return - V_491 ;
break;
case V_523 :
memset ( & V_465 , 0 , sizeof( V_465 ) ) ;
V_465 . V_510 = V_3 -> V_5 ;
F_235 ( V_465 . V_524 , V_3 -> V_362 ,
sizeof( V_465 . V_524 ) ) ;
V_465 . V_368 = V_3 -> V_368 ;
V_465 . V_364 = V_3 -> V_364 ;
V_465 . V_525 = 0 ;
if ( V_3 -> V_234 )
V_465 . V_525 |= V_526 ;
if ( F_233 ( V_461 , & V_465 ,
sizeof( V_465 ) ) )
return - V_491 ;
break;
case V_527 :
if ( F_236 ( & V_13 , V_461 , sizeof( V_13 ) ) )
return - V_491 ;
if ( F_233 ( ( void T_5 * ) V_13 . V_13 , V_3 -> V_13 ,
sizeof( struct V_528 ) ) )
return - V_491 ;
break;
default:
return - V_123 ;
}
return 0 ;
}
static int F_237 ( struct V_179 * V_106 ,
struct V_3 * V_3 )
{
struct V_457 * V_447 ;
int V_180 ;
V_180 = F_238 ( V_106 , L_166 , 0 , & V_447 ) ;
if ( V_180 < 0 )
return V_180 ;
V_3 -> V_529 = V_447 ;
V_447 -> V_175 = V_3 ;
strcpy ( V_447 -> V_206 , L_167 ) ;
V_447 -> V_530 . V_531 = F_231 ;
V_447 -> V_530 . V_532 = F_234 ;
V_447 -> V_530 . V_533 = F_234 ;
V_447 -> V_530 . V_534 = F_231 ;
return 0 ;
}
static int F_239 ( struct V_3 * V_3 )
{
int V_180 ;
struct V_535 * V_536 ;
T_7 V_537 ;
V_536 = V_3 -> V_536 ;
V_537 = V_419 ;
V_180 =
F_240 ( V_536 ,
V_538 ,
F_241 ( V_3 -> V_539 ) ,
V_537 ,
V_537 ) ;
if ( V_180 < 0 ) {
F_202 ( V_3 -> V_106 -> V_107 ,
L_168 , V_537 ) ;
return V_180 ;
} else
F_202 ( V_3 -> V_106 -> V_107 ,
L_169 , V_537 ) ;
return 0 ;
}
static void F_200 ( struct V_3 * V_3 ,
struct V_403 * V_172 ,
unsigned int V_7 , int V_540 )
{
int V_19 ;
for ( V_19 = 0 ; V_19 < ( V_540 * 16 ) ; V_19 ++ )
F_3 ( V_3 , V_7 + 4 * V_19 ,
F_242 ( V_172 , 4096 * V_19 ) ) ;
}
static int F_243 ( struct V_179 * V_106 ,
struct V_3 * V_3 )
{
struct V_535 * V_536 ;
int V_180 ;
V_180 = F_244 ( V_106 , V_3 -> V_362 , 0 , 1 , 1 , & V_536 ) ;
if ( V_180 < 0 )
return V_180 ;
V_3 -> V_536 = V_536 ;
V_536 -> V_175 = V_3 ;
strcpy ( V_536 -> V_206 , V_3 -> V_362 ) ;
F_245 ( V_536 , V_408 ,
& V_541 ) ;
F_245 ( V_536 , V_437 ,
& V_541 ) ;
V_536 -> V_211 = V_542 ;
V_180 = F_239 ( V_3 ) ;
if ( V_180 < 0 )
return V_180 ;
return 0 ;
}
static inline void F_246 ( struct V_3 * V_3 )
{
int V_19 ;
for ( V_19 = 0 ; V_19 < V_3 -> V_216 ; V_19 ++ )
F_52 ( V_3 , V_19 ) ;
}
static int F_247 ( struct V_179 * V_106 ,
struct V_3 * V_3 )
{
int V_180 , V_19 ;
F_202 ( V_106 -> V_107 , L_170 ) ;
V_180 = F_243 ( V_106 , V_3 ) ;
if ( V_180 < 0 )
return V_180 ;
V_19 = 0 ;
while ( V_19 < V_3 -> V_216 ) {
V_180 = F_68 ( V_106 , V_3 , V_19 ) ;
if ( V_180 < 0 ) {
return V_180 ;
}
V_19 ++ ;
}
V_180 = F_169 ( V_106 , V_3 ) ;
if ( V_180 < 0 )
return V_180 ;
V_180 = F_237 ( V_106 , V_3 ) ;
if ( V_180 < 0 )
return V_180 ;
F_202 ( V_106 -> V_107 , L_171 ) ;
F_181 ( V_3 ) ;
V_3 -> V_110 = - 1 ;
V_3 -> V_543 = - 1 ;
V_3 -> V_544 = - 1 ;
V_3 -> V_26 = - 1 ;
V_3 -> V_27 = - 1 ;
V_3 -> V_399 = NULL ;
V_3 -> V_400 = NULL ;
F_202 ( V_106 -> V_107 , L_172 ) ;
V_180 = F_185 ( V_3 ) ;
if ( V_180 < 0 )
return V_180 ;
F_202 ( V_106 -> V_107 , L_173 ) ;
F_167 ( V_3 ) ;
F_202 ( V_106 -> V_107 , L_174 ) ;
V_180 = F_248 ( V_106 ) ;
if ( V_180 < 0 ) {
F_46 ( V_106 -> V_107 , L_175 ) ;
return V_180 ;
}
F_202 ( V_106 -> V_107 , L_176 ) ;
return 0 ;
}
static int F_249 ( struct V_179 * V_106 ,
struct V_3 * V_3 )
{
struct V_545 * V_539 = V_3 -> V_539 ;
int V_180 ;
unsigned long V_546 ;
V_3 -> V_186 = - 1 ;
V_3 -> V_106 = V_106 ;
F_69 ( & V_3 -> V_25 ) ;
F_250 ( V_3 -> V_539 ,
V_547 , & V_3 -> V_364 ) ;
strcpy ( V_106 -> V_548 , L_177 ) ;
strcpy ( V_106 -> V_549 , L_178 ) ;
switch ( V_3 -> V_364 ) {
case V_550 :
V_3 -> V_5 = V_6 ;
V_3 -> V_362 = L_179 ;
V_3 -> V_216 = 2 ;
break;
case V_551 :
V_3 -> V_5 = V_4 ;
V_3 -> V_362 = L_180 ;
V_3 -> V_216 = 1 ;
break;
case V_552 :
V_3 -> V_5 = V_49 ;
V_3 -> V_362 = L_181 ;
V_3 -> V_216 = 1 ;
break;
default:
if ( ( V_3 -> V_364 == 0xf0 ) ||
( ( V_3 -> V_364 >= 0xe6 ) &&
( V_3 -> V_364 <= 0xea ) ) ) {
V_3 -> V_5 = V_36 ;
V_3 -> V_362 = L_182 ;
V_3 -> V_216 = 2 ;
} else if ( ( V_3 -> V_364 == 0xd2 ) ||
( ( V_3 -> V_364 >= 0xc8 ) &&
( V_3 -> V_364 <= 0xcf ) ) ) {
V_3 -> V_5 = V_53 ;
V_3 -> V_362 = L_183 ;
V_3 -> V_216 = 3 ;
} else {
F_46 ( V_106 -> V_107 ,
L_184 ,
V_3 -> V_364 ) ;
return - V_553 ;
}
}
V_180 = F_251 ( V_539 ) ;
if ( V_180 < 0 )
return V_180 ;
F_252 ( V_3 -> V_539 ) ;
V_180 = F_253 ( V_539 , L_151 ) ;
if ( V_180 < 0 )
return V_180 ;
V_3 -> V_369 = F_254 ( V_539 , 0 ) ;
V_546 = F_255 ( V_539 , 0 ) ;
F_202 ( V_106 -> V_107 , L_185 ,
V_3 -> V_369 , V_3 -> V_369 + V_546 - 1 ) ;
V_3 -> V_9 = F_256 ( V_3 -> V_369 , V_546 ) ;
if ( ! V_3 -> V_9 ) {
F_46 ( V_106 -> V_107 , L_186 ,
V_3 -> V_369 , V_3 -> V_369 + V_546 - 1 ) ;
return - V_125 ;
}
F_202 ( V_106 -> V_107 , L_187 ,
( unsigned long ) V_3 -> V_9 , V_3 -> V_369 ,
V_3 -> V_369 + V_546 - 1 ) ;
if ( F_257 ( V_539 -> V_186 , F_187 ,
V_554 , V_555 , V_3 ) ) {
F_46 ( V_106 -> V_107 , L_188 , V_539 -> V_186 ) ;
return - V_125 ;
}
F_202 ( V_106 -> V_107 , L_189 , V_539 -> V_186 ) ;
V_3 -> V_186 = V_539 -> V_186 ;
F_202 ( V_106 -> V_107 , L_190 ,
sizeof( struct V_528 ) ) ;
V_3 -> V_13 = F_258 ( sizeof( struct V_528 ) , V_556 ) ;
if ( ! V_3 -> V_13 ) {
F_46 ( V_106 -> V_107 ,
L_191 ,
( int ) sizeof( struct V_528 ) ) ;
return - V_557 ;
}
V_3 -> V_136 = NULL ;
V_3 -> V_138 = NULL ;
switch ( V_3 -> V_5 ) {
case V_36 :
V_3 -> V_133 = V_3 -> V_135 = V_558 ;
V_3 -> V_142 = V_3 -> V_143 = V_558 ;
V_3 -> V_148 = V_3 -> V_149 = V_558 ;
V_3 -> V_129 = V_3 -> V_131 =
V_559 ;
V_3 -> V_140 = V_3 -> V_141 =
V_559 ;
V_3 -> V_146 = V_3 -> V_147 =
V_559 ;
V_3 -> V_137 = V_3 -> V_139 =
V_560 ;
V_3 -> V_144 = V_3 -> V_145 =
V_560 ;
V_3 -> V_150 = V_3 -> V_151 =
V_560 ;
V_3 -> V_134 = V_3 -> V_132 =
V_558 ;
V_3 -> V_136 = V_3 -> V_138 =
V_560 ;
V_3 -> V_128 = V_3 -> V_130 =
V_559 ;
break;
case V_53 :
case V_49 :
V_3 -> V_133 = V_3 -> V_135 =
V_561 ;
V_3 -> V_142 = V_3 -> V_143 =
V_562 ;
V_3 -> V_148 = V_3 -> V_149 =
V_563 ;
V_3 -> V_129 = V_3 -> V_131 =
V_564 ;
V_3 -> V_140 = V_3 -> V_141 =
V_564 ;
V_3 -> V_146 = V_3 -> V_147 =
V_564 ;
V_3 -> V_137 = V_3 -> V_139 =
V_565 ;
V_3 -> V_144 = V_3 -> V_145 =
V_565 ;
V_3 -> V_150 = V_3 -> V_151 =
V_565 ;
break;
case V_4 :
V_3 -> V_133 = V_566 ;
V_3 -> V_142 = V_567 ;
V_3 -> V_148 = V_568 ;
V_3 -> V_135 = V_569 ;
V_3 -> V_143 = V_570 ;
V_3 -> V_149 = V_571 ;
if ( 0 == ( F_5 ( V_3 , V_37 ) & V_572 ) ) {
F_198 ( V_106 -> V_107 , L_192 ) ;
V_3 -> V_133 += 4 ;
V_3 -> V_142 += 4 ;
V_3 -> V_148 += 4 ;
}
if ( 0 == ( F_5 ( V_3 , V_37 ) & V_573 ) ) {
F_198 ( V_106 -> V_107 , L_193 ) ;
V_3 -> V_135 += 4 ;
V_3 -> V_143 += 4 ;
V_3 -> V_149 += 4 ;
}
V_3 -> V_131 = V_574 ;
V_3 -> V_141 = V_575 ;
V_3 -> V_147 = V_576 ;
V_3 -> V_129 = V_577 ;
V_3 -> V_140 = V_578 ;
V_3 -> V_146 = V_579 ;
V_3 -> V_137 = V_580 ;
V_3 -> V_139 = V_581 ;
V_3 -> V_144 = V_582 ;
V_3 -> V_145 = V_583 ;
V_3 -> V_150 = V_584 ;
V_3 -> V_151 = V_585 ;
break;
case V_6 :
V_3 -> V_133 = V_3 -> V_135 =
V_586 ;
V_3 -> V_142 = V_3 -> V_143 =
V_587 ;
V_3 -> V_148 = V_3 -> V_149 =
V_588 ;
V_3 -> V_132 = V_586 ;
V_3 -> V_134 = V_586 ;
V_3 -> V_129 = V_3 -> V_131 =
V_589 ;
V_3 -> V_140 = V_3 -> V_141 =
V_590 ;
V_3 -> V_146 = V_3 -> V_147 =
V_591 ;
V_3 -> V_128 = V_3 -> V_130 =
V_589 ;
V_3 -> V_137 = V_3 -> V_139 =
V_592 ;
V_3 -> V_144 = V_3 -> V_145 =
V_593 ;
V_3 -> V_150 = V_3 -> V_151 =
V_594 ;
break;
}
switch ( V_3 -> V_5 ) {
case V_4 :
case V_6 :
if ( F_5 ( V_3 , V_37 ) &
V_595 ) {
V_3 -> V_216 ++ ;
V_3 -> V_234 = F_258 ( sizeof( struct V_596 ) ,
V_556 ) ;
if ( NULL != V_3 -> V_234 ) {
F_148 ( V_3 ) ;
}
F_198 ( V_106 -> V_107 , L_194 ) ;
} else {
V_3 -> V_234 = NULL ;
}
break;
case V_53 :
case V_36 :
if ( F_5 ( V_3 , V_38 ) & V_356 ) {
V_3 -> V_216 ++ ;
V_3 -> V_234 = F_258 ( sizeof( struct V_596 ) ,
V_556 ) ;
if ( NULL != V_3 -> V_234 ) {
F_148 ( V_3 ) ;
}
F_198 ( V_106 -> V_107 , L_195 ) ;
} else {
V_3 -> V_234 = NULL ;
}
break;
default:
V_3 -> V_234 = NULL ;
}
switch ( V_3 -> V_5 ) {
case V_36 :
if ( V_3 -> V_234 ) {
V_3 -> V_259 = V_597 ;
V_3 -> V_258 =
F_170 ( V_597 ) ;
} else {
V_3 -> V_259 = V_598 ;
V_3 -> V_258 =
F_170 ( V_598 ) ;
}
break;
case V_53 :
if ( V_3 -> V_234 ) {
V_3 -> V_259 = V_599 ;
V_3 -> V_258 = 4 ;
} else {
V_3 -> V_259 = V_600 ;
V_3 -> V_258 = 3 ;
}
break;
case V_49 :
break;
case V_6 :
if ( V_3 -> V_234 ) {
V_3 -> V_259 = V_601 ;
V_3 -> V_258 = 9 ;
} else {
V_3 -> V_259 = V_602 ;
V_3 -> V_258 = 8 ;
}
break;
case V_4 :
if ( V_3 -> V_234 ) {
V_3 -> V_259 = V_603 ;
V_3 -> V_258 = 6 ;
} else {
V_3 -> V_259 = V_604 ;
V_3 -> V_258 = 5 ;
}
break;
}
F_259 ( & V_3 -> V_401 ,
F_72 , ( unsigned long ) V_3 ) ;
if ( V_3 -> V_5 != V_49 ) {
V_3 -> V_368 = ( F_5 ( V_3 ,
V_189 ) >> 8 ) & 0xFFFFFF ;
if ( NULL == V_156 [ V_3 -> V_107 ] && V_3 -> V_368 != 0xFFFFFF ) {
sprintf ( V_106 -> V_156 , L_196 , V_3 -> V_368 ) ;
F_260 ( V_106 , V_106 -> V_156 ) ;
}
}
F_202 ( V_106 -> V_107 , L_197 ) ;
V_180 = F_247 ( V_106 , V_3 ) ;
if ( V_180 < 0 )
return V_180 ;
F_246 ( V_3 ) ;
return 0 ;
}
static int F_261 ( struct V_3 * V_3 )
{
if ( V_3 -> V_369 ) {
V_3 -> V_29 &=
~ ( V_89 | V_88 |
V_192 | V_198 |
V_185 | V_203 ) ;
F_3 ( V_3 , V_90 ,
V_3 -> V_29 ) ;
}
if ( V_3 -> V_186 >= 0 )
F_262 ( V_3 -> V_186 , ( void * ) V_3 ) ;
F_263 ( V_3 -> V_13 ) ;
F_264 ( V_3 -> V_9 ) ;
if ( V_3 -> V_369 )
F_265 ( V_3 -> V_539 ) ;
F_266 ( V_3 -> V_539 ) ;
return 0 ;
}
static void F_267 ( struct V_179 * V_106 )
{
struct V_3 * V_3 = V_106 -> V_175 ;
if ( V_3 )
F_261 ( V_3 ) ;
}
static int F_268 ( struct V_545 * V_539 ,
const struct V_605 * V_606 )
{
static int V_107 ;
struct V_3 * V_3 ;
struct V_179 * V_106 ;
int V_180 ;
if ( V_107 >= V_607 )
return - V_553 ;
if ( ! V_608 [ V_107 ] ) {
V_107 ++ ;
return - V_609 ;
}
V_180 = F_269 ( & V_539 -> V_107 , V_236 [ V_107 ] , V_156 [ V_107 ] ,
V_610 , sizeof( struct V_3 ) , & V_106 ) ;
if ( V_180 < 0 )
return V_180 ;
V_3 = V_106 -> V_175 ;
V_106 -> V_611 = F_267 ;
V_3 -> V_107 = V_107 ;
V_3 -> V_539 = V_539 ;
V_180 = F_249 ( V_106 , V_3 ) ;
if ( V_180 < 0 ) {
F_270 ( V_106 ) ;
return V_180 ;
}
if ( V_3 -> V_5 != V_49 ) {
sprintf ( V_106 -> V_205 , L_198 ,
V_3 -> V_362 ,
V_3 -> V_368 ) ;
sprintf ( V_106 -> V_612 , L_199 ,
V_3 -> V_362 ,
V_3 -> V_368 ,
V_3 -> V_369 , V_3 -> V_186 ) ;
} else {
sprintf ( V_106 -> V_205 , L_200 , V_3 -> V_362 ) ;
sprintf ( V_106 -> V_612 , L_201 ,
V_3 -> V_362 , V_3 -> V_369 , V_3 -> V_186 ) ;
}
V_180 = F_248 ( V_106 ) ;
if ( V_180 < 0 ) {
F_270 ( V_106 ) ;
return V_180 ;
}
F_271 ( V_539 , V_106 ) ;
V_107 ++ ;
return 0 ;
}
static void F_272 ( struct V_545 * V_539 )
{
F_270 ( F_273 ( V_539 ) ) ;
}
