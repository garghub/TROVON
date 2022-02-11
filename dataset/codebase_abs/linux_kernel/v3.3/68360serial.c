static inline int F_1 ( T_1 * V_1 ,
char * V_2 , const char * V_3 )
{
#ifdef F_2
static const char * V_4 =
L_1 ;
static const char * V_5 =
L_2 ;
if ( ! V_1 ) {
F_3 ( V_5 , V_2 , V_3 ) ;
return 1 ;
}
if ( V_1 -> V_6 != V_7 ) {
F_3 ( V_4 , V_2 , V_3 ) ;
return 1 ;
}
#endif
return 0 ;
}
static void F_4 ( struct V_8 * V_9 )
{
T_1 * V_1 = ( T_1 * ) V_9 -> V_10 ;
int V_11 ;
unsigned long V_12 ;
volatile struct V_13 * V_14 ;
volatile struct V_15 * V_16 ;
if ( F_1 ( V_1 , V_9 -> V_2 , L_3 ) )
return;
F_5 ( V_12 ) ;
V_11 = F_6 ( V_1 -> V_17 -> V_18 ) ;
if ( V_1 -> V_17 -> V_18 & V_19 ) {
V_14 = & V_20 -> V_13 [ V_11 ] ;
V_14 -> V_21 &= ~ V_22 ;
} else {
V_16 = & V_20 -> V_15 [ V_11 ] ;
V_16 -> V_23 &= ~ V_24 ;
}
F_7 ( V_12 ) ;
}
static void F_8 ( struct V_8 * V_9 )
{
T_1 * V_1 = ( T_1 * ) V_9 -> V_10 ;
int V_11 ;
unsigned long V_12 ;
volatile struct V_13 * V_14 ;
volatile struct V_15 * V_16 ;
if ( F_1 ( V_1 , V_9 -> V_2 , L_3 ) )
return;
F_5 ( V_12 ) ;
V_11 = F_6 ( V_1 -> V_17 -> V_18 ) ;
if ( V_1 -> V_17 -> V_18 & V_19 ) {
V_14 = & V_20 -> V_13 [ V_11 ] ;
V_14 -> V_21 |= V_22 ;
} else {
V_16 = & V_20 -> V_15 [ V_11 ] ;
V_16 -> V_23 |= V_24 ;
}
F_7 ( V_12 ) ;
}
static T_2 void F_9 ( T_1 * V_1 )
{
struct V_8 * V_9 = V_1 -> V_25 . V_9 ;
unsigned char V_26 , V_27 , * V_28 ;
int V_29 ;
T_3 V_30 ;
struct V_31 * V_32 ;
volatile T_4 * V_33 ;
V_32 = & V_1 -> V_17 -> V_32 ;
V_33 = V_1 -> V_34 ;
for (; ; ) {
if ( V_33 -> V_30 & V_35 )
break;
if ( ! ( V_1 -> V_36 & V_35 ) ) {
V_33 -> V_30 |= V_35 ;
V_33 -> V_30 &=
~ ( V_37 | V_38 | V_39 | V_40 ) ;
if ( V_33 -> V_30 & V_41 )
V_33 = V_1 -> V_42 ;
else
V_33 ++ ;
continue;
}
V_29 = V_33 -> V_43 ;
V_28 = ( char * ) V_33 -> V_44 ;
V_30 = V_33 -> V_30 ;
while ( V_29 -- > 0 ) {
V_26 = * V_28 ++ ;
V_32 -> V_45 ++ ;
#ifdef F_10
F_3 ( L_4 , V_26 , V_30 ) ;
#endif
V_27 = V_46 ;
if ( V_30 & ( V_37 | V_38 |
V_39 | V_40 ) ) {
if ( V_30 & V_37 )
V_32 -> V_47 ++ ;
else if ( V_30 & V_39 )
V_32 -> V_48 ++ ;
else if ( V_30 & V_38 )
V_32 -> V_49 ++ ;
if ( V_30 & V_40 )
V_32 -> V_50 ++ ;
V_30 &= V_1 -> V_36 ;
if ( V_30 & ( V_37 ) ) {
#ifdef F_10
F_3 ( L_5 ) ;
#endif
* V_9 -> V_51 . V_52 = V_53 ;
if ( V_1 -> V_12 & V_54 )
F_11 ( V_9 ) ;
} else if ( V_30 & V_39 )
V_27 = V_55 ;
else if ( V_30 & V_38 )
V_27 = V_56 ;
}
F_12 ( V_9 , V_26 , V_27 ) ;
if ( V_30 & V_40 )
F_12 ( V_9 , 0 , V_57 ) ;
}
V_33 -> V_30 |= V_35 ;
V_33 -> V_30 &= ~ ( V_37 | V_38 | V_39 | V_40 ) ;
if ( V_33 -> V_30 & V_41 )
V_33 = V_1 -> V_42 ;
else
V_33 ++ ;
}
V_1 -> V_34 = ( T_4 * ) V_33 ;
F_13 ( V_9 ) ;
}
static T_2 void F_14 ( T_1 * V_1 )
{
struct V_8 * V_9 = V_1 -> V_25 . V_9 ;
V_1 -> V_17 -> V_32 . V_47 ++ ;
F_12 ( V_9 , 0 , V_53 ) ;
F_13 ( V_9 ) ;
}
static T_2 void F_15 ( T_1 * V_1 )
{
if ( ( V_1 -> V_12 & V_58 ) ||
( V_1 -> V_25 . V_9 -> V_12 & ( 1 << V_59 ) ) ) {
F_16 ( & V_1 -> V_60 ) ;
}
#ifdef F_10
F_3 ( L_6 ) ;
#endif
}
static T_2 void F_17 ( struct V_61 * V_1 )
{
int V_30 ;
struct V_62 * V_32 ;
V_30 = F_18 ( V_1 , V_63 ) ;
if ( V_30 & V_64 ) {
V_32 = & V_1 -> V_17 -> V_32 ;
if ( V_30 & V_65 )
V_32 -> V_66 ++ ;
if ( V_30 & V_67 )
V_32 -> V_68 ++ ;
if ( V_30 & V_69 ) {
V_32 -> V_70 ++ ;
#ifdef F_19
if ( ( V_1 -> V_12 & V_71 ) &&
( V_30 & V_72 ) )
F_20 () ;
#endif
}
if ( V_30 & V_73 )
V_32 -> V_74 ++ ;
F_21 ( & V_1 -> V_75 ) ;
}
if ( ( V_1 -> V_12 & V_76 ) && ( V_30 & V_69 ) ) {
#if ( F_22 ( V_77 ) || F_22 ( F_10 ) )
F_3 ( L_7 , V_1 -> line ,
( V_30 & V_72 ) ? L_8 : L_9 ) ;
#endif
if ( V_30 & V_72 )
F_21 ( & V_1 -> V_78 ) ;
else {
#ifdef V_77
F_3 ( L_10 ) ;
#endif
F_23 ( & V_1 -> V_79 ,
& V_80 ) ;
}
}
if ( V_1 -> V_12 & V_81 ) {
if ( V_1 -> V_25 . V_9 -> V_82 ) {
if ( V_30 & V_83 ) {
#if ( F_22 ( F_10 ) || F_22 ( V_84 ) )
F_3 ( L_11 ) ;
#endif
V_1 -> V_25 . V_9 -> V_82 = 0 ;
V_1 -> V_85 |= V_86 ;
F_24 ( V_1 , V_87 , V_1 -> V_85 ) ;
F_25 ( V_1 , V_88 ) ;
return;
}
} else {
if ( ! ( V_30 & V_83 ) ) {
#if ( F_22 ( F_10 ) || F_22 ( V_84 ) )
F_3 ( L_12 ) ;
#endif
V_1 -> V_25 . V_9 -> V_82 = 1 ;
V_1 -> V_85 &= ~ V_86 ;
F_24 ( V_1 , V_87 , V_1 -> V_85 ) ;
}
}
}
}
static void F_26 ( int V_89 , void * V_90 )
{
T_5 V_91 ;
int V_11 ;
T_1 * V_1 ;
volatile struct V_15 * V_16 ;
volatile struct V_13 * V_14 ;
V_1 = V_90 ;
V_11 = F_6 ( V_1 -> V_17 -> V_18 ) ;
if ( V_1 -> V_17 -> V_18 & V_19 ) {
V_14 = & V_20 -> V_13 [ V_11 ] ;
V_91 = V_14 -> V_92 ;
if ( V_91 & V_93 )
F_9 ( V_1 ) ;
if ( V_91 & V_94 )
F_15 ( V_1 ) ;
V_14 -> V_92 = V_91 ;
} else {
V_16 = & V_20 -> V_15 [ V_11 ] ;
V_91 = V_16 -> V_95 ;
if ( V_91 & V_96 )
F_14 ( V_1 ) ;
if ( V_91 & V_97 )
F_9 ( V_1 ) ;
if ( V_91 & V_24 )
F_15 ( V_1 ) ;
V_16 -> V_95 = V_91 ;
}
#ifdef F_10
F_3 ( L_13 ,
V_1 -> V_17 -> V_18 , V_91 ) ;
#endif
#ifdef F_27
F_17 ( V_1 ) ;
#endif
V_1 -> V_98 = V_99 ;
#ifdef F_10
F_3 ( L_14 ) ;
#endif
}
static void F_28 ( void * V_100 )
{
T_1 * V_1 = ( T_1 * ) V_100 ;
struct V_8 * V_9 ;
V_9 = V_1 -> V_25 . V_9 ;
if ( ! V_9 )
return;
if ( F_29 ( V_88 , & V_1 -> V_101 ) )
F_30 ( V_9 ) ;
}
static void F_31 ( void * V_100 )
{
struct V_61 * V_1 = (struct V_61 * ) V_100 ;
struct V_8 * V_9 ;
V_9 = V_1 -> V_25 . V_9 ;
if ( ! V_9 )
return;
F_32 ( V_9 ) ;
}
static int F_33 ( T_1 * V_1 )
{
unsigned long V_12 ;
int V_102 = 0 ;
int V_11 ;
volatile struct V_15 * V_16 ;
volatile struct V_13 * V_14 ;
volatile struct V_103 * V_104 ;
volatile struct V_105 * V_106 ;
F_5 ( V_12 ) ;
if ( V_1 -> V_12 & V_107 ) {
goto V_108;
}
#ifdef F_34
if ( ! V_17 -> V_25 || ! V_17 -> type ) {
if ( V_1 -> V_25 . V_9 )
F_35 ( V_109 , & V_1 -> V_25 . V_9 -> V_12 ) ;
goto V_108;
}
#endif
#ifdef V_77
F_3 ( L_15 , V_1 -> line , V_17 -> V_110 ) ;
#endif
#ifdef F_27
V_1 -> V_111 = 0 ;
if ( V_1 -> V_25 . V_9 -> V_112 -> V_113 & V_114 )
V_1 -> V_111 = V_115 | V_116 ;
#endif
if ( V_1 -> V_25 . V_9 )
F_36 ( V_109 , & V_1 -> V_25 . V_9 -> V_12 ) ;
F_37 ( V_1 ) ;
V_11 = F_6 ( V_1 -> V_17 -> V_18 ) ;
if ( V_1 -> V_17 -> V_18 & V_19 ) {
V_14 = & V_20 -> V_13 [ V_11 ] ;
V_106 = & V_20 -> V_117 [ V_1 -> V_17 -> V_25 ] . V_118 . V_119 . V_120 ;
V_106 -> V_121 = V_122 ;
V_106 -> V_123 = V_122 ;
V_14 -> V_21 |= ( V_22 | V_124 ) ;
V_14 -> V_125 . V_126 . V_127 |= ( V_128 | V_129 ) ;
} else {
V_16 = & V_20 -> V_15 [ V_11 ] ;
V_16 -> V_23 |= ( V_97 | V_24 ) ;
V_16 -> V_130 |= ( V_131 | V_132 ) ;
V_104 = & V_20 -> V_117 [ V_1 -> V_17 -> V_25 ] . V_118 . V_133 . V_134 . V_135 . V_120 ;
V_104 -> V_121 = V_122 ;
V_104 -> V_123 = V_122 ;
V_104 -> V_136 = 1 ;
}
V_1 -> V_12 |= V_107 ;
F_7 ( V_12 ) ;
return 0 ;
V_108:
F_7 ( V_12 ) ;
return V_102 ;
}
static void F_38 ( T_1 * V_1 )
{
unsigned long V_12 ;
struct V_137 * V_17 ;
int V_11 ;
volatile struct V_15 * V_16 ;
volatile struct V_13 * V_14 ;
if ( ! ( V_1 -> V_12 & V_107 ) )
return;
V_17 = V_1 -> V_17 ;
#ifdef V_77
F_3 ( L_16 , V_1 -> line ,
V_17 -> V_110 ) ;
#endif
F_5 ( V_12 ) ;
V_11 = F_6 ( V_17 -> V_18 ) ;
if ( V_17 -> V_18 & V_19 ) {
V_14 = & V_20 -> V_13 [ V_11 ] ;
V_14 -> V_125 . V_126 . V_127 &= ~ ( V_128 | V_129 ) ;
#ifdef F_39
if ( ( V_17 - V_138 ) != V_139 )
#endif
V_14 -> V_21 &= ~ ( V_22 | V_124 ) ;
} else {
V_16 = & V_20 -> V_15 [ V_11 ] ;
V_16 -> V_23 &= ~ ( V_97 | V_24 ) ;
#ifdef F_39
if ( ( V_17 - V_138 ) != V_139 )
#endif
V_16 -> V_130 &= ~ ( V_131 | V_132 ) ;
}
if ( V_1 -> V_25 . V_9 )
F_35 ( V_109 , & V_1 -> V_25 . V_9 -> V_12 ) ;
V_1 -> V_12 &= ~ V_107 ;
F_7 ( V_12 ) ;
}
static void F_37 ( T_1 * V_1 )
{
int V_140 ;
unsigned V_141 , V_142 , V_143 , V_144 ;
int V_29 , V_145 , V_146 , V_11 ;
unsigned long V_12 ;
struct V_137 * V_17 ;
volatile struct V_15 * V_16 ;
volatile struct V_13 * V_14 ;
if ( ! V_1 -> V_25 . V_9 || ! V_1 -> V_25 . V_9 -> V_112 )
return;
V_141 = V_1 -> V_25 . V_9 -> V_112 -> V_113 ;
V_17 = V_1 -> V_17 ;
V_142 = 0 ;
V_143 = 0 ;
switch ( V_141 & V_147 ) {
case V_148 : V_145 = 5 ; break;
case V_149 : V_145 = 6 ; break;
case V_150 : V_145 = 7 ; break;
case V_151 : V_145 = 8 ; break;
default: V_145 = 8 ; break;
}
V_146 = V_145 - 5 ;
if ( V_141 & V_152 ) {
V_142 |= V_153 ;
V_143 |= V_154 ;
V_145 ++ ;
}
if ( V_141 & V_155 ) {
V_142 |= V_156 ;
V_143 |= V_157 ;
V_145 ++ ;
}
if ( ! ( V_141 & V_158 ) ) {
V_142 |= V_159 ;
V_143 |= ( V_160 | V_161 ) ;
}
V_29 = V_141 & V_114 ;
if ( V_29 >= ( sizeof( V_162 ) / sizeof( int ) ) )
V_140 = 9600 ;
else
V_140 = V_162 [ V_29 ] ;
V_1 -> V_163 = ( V_164 * V_165 * V_145 ) ;
V_1 -> V_163 += V_165 / 50 ;
#ifdef F_27
V_1 -> V_85 &= ~ V_166 ;
if ( V_1 -> V_12 & V_71 )
V_1 -> V_85 |= V_166 ;
if ( V_141 & V_167 ) {
V_1 -> V_12 |= V_81 ;
V_1 -> V_85 |= V_166 ;
} else
V_1 -> V_12 &= ~ V_81 ;
if ( V_141 & V_168 )
V_1 -> V_12 &= ~ V_76 ;
else {
V_1 -> V_12 |= V_76 ;
V_1 -> V_85 |= V_166 ;
}
F_24 ( V_1 , V_87 , V_1 -> V_85 ) ;
#endif
V_1 -> V_36 = ( V_35 | V_40 ) ;
if ( F_40 ( V_1 -> V_25 . V_9 ) )
V_1 -> V_36 |= V_38 | V_39 ;
if ( F_41 ( V_1 -> V_25 . V_9 ) || F_42 ( V_1 -> V_25 . V_9 ) )
V_1 -> V_36 |= V_37 ;
V_1 -> V_169 = 0 ;
if ( F_43 ( V_1 -> V_25 . V_9 ) )
V_1 -> V_169 |= V_39 | V_38 ;
if ( F_44 ( V_1 -> V_25 . V_9 ) ) {
V_1 -> V_169 |= V_37 ;
if ( F_43 ( V_1 -> V_25 . V_9 ) )
V_1 -> V_169 |= V_40 ;
}
if ( ( V_141 & V_170 ) == 0 )
V_1 -> V_36 &= ~ V_35 ;
F_5 ( V_12 ) ;
V_145 ++ ;
V_11 = F_6 ( V_17 -> V_18 ) ;
if ( V_17 -> V_18 & V_19 ) {
V_14 = & V_20 -> V_13 [ V_11 ] ;
V_14 -> V_171 = ( V_146 << 12 ) | V_143 ;
} else {
V_16 = & V_20 -> V_15 [ V_11 ] ;
V_144 = V_16 -> V_130 ;
V_16 -> V_130 = F_45 ( V_145 ) | V_142 | V_172 ;
V_16 -> V_130 |= ( V_144 & ( V_131 | V_132 ) ) ;
}
F_46 ( ( V_17 - V_138 ) , V_140 ) ;
F_7 ( V_12 ) ;
}
static void F_47 ( struct V_8 * V_9 , unsigned char V_26 )
{
T_1 * V_1 = ( T_1 * ) V_9 -> V_10 ;
volatile T_4 * V_33 ;
if ( F_1 ( V_1 , V_9 -> V_2 , L_17 ) )
return 0 ;
if ( ! V_9 )
return 0 ;
V_33 = V_1 -> V_173 ;
while ( V_33 -> V_30 & V_174 ) ;
* ( ( char * ) V_33 -> V_44 ) = V_26 ;
V_33 -> V_43 = 1 ;
V_33 -> V_30 |= V_174 ;
if ( V_33 -> V_30 & V_41 )
V_33 = V_1 -> V_175 ;
else
V_33 ++ ;
V_1 -> V_173 = ( T_4 * ) V_33 ;
return 1 ;
}
static int F_48 ( struct V_8 * V_9 ,
const unsigned char * V_44 , int V_176 )
{
int V_177 , V_178 = 0 ;
T_1 * V_1 = ( T_1 * ) V_9 -> V_10 ;
volatile T_4 * V_33 ;
#ifdef F_49
if ( F_50 ( V_44 , V_176 ) )
return V_178 ;
#endif
if ( F_1 ( V_1 , V_9 -> V_2 , L_18 ) )
return 0 ;
if ( ! V_9 )
return 0 ;
V_33 = V_1 -> V_173 ;
while ( 1 ) {
V_177 = F_51 ( V_176 , V_164 ) ;
if ( V_177 <= 0 )
break;
if ( V_33 -> V_30 & V_174 ) {
V_1 -> V_12 |= V_58 ;
break;
}
memcpy ( ( void * ) V_33 -> V_44 , V_44 , V_177 ) ;
V_33 -> V_43 = V_177 ;
V_33 -> V_30 |= V_174 ;
V_44 += V_177 ;
V_176 -= V_177 ;
V_178 += V_177 ;
if ( V_33 -> V_30 & V_41 )
V_33 = V_1 -> V_175 ;
else
V_33 ++ ;
V_1 -> V_173 = ( T_4 * ) V_33 ;
}
return V_178 ;
}
static int F_52 ( struct V_8 * V_9 )
{
T_1 * V_1 = ( T_1 * ) V_9 -> V_10 ;
int V_178 ;
if ( F_1 ( V_1 , V_9 -> V_2 , L_19 ) )
return 0 ;
if ( ( V_1 -> V_173 -> V_30 & V_174 ) == 0 ) {
V_1 -> V_12 &= ~ V_58 ;
V_178 = V_164 ;
}
else {
V_1 -> V_12 |= V_58 ;
V_178 = 0 ;
}
return V_178 ;
}
static int F_53 ( struct V_8 * V_9 )
{
T_1 * V_1 = ( T_1 * ) V_9 -> V_10 ;
if ( F_1 ( V_1 , V_9 -> V_2 , L_20 ) )
return 0 ;
return 0 ;
}
static void F_54 ( struct V_8 * V_9 )
{
T_1 * V_1 = ( T_1 * ) V_9 -> V_10 ;
if ( F_1 ( V_1 , V_9 -> V_2 , L_21 ) )
return;
F_30 ( V_9 ) ;
V_1 -> V_12 &= ~ V_58 ;
}
static void F_55 ( struct V_8 * V_9 , char V_26 )
{
volatile T_4 * V_33 ;
T_1 * V_1 = ( T_1 * ) V_9 -> V_10 ;
if ( F_1 ( V_1 , V_9 -> V_2 , L_22 ) )
return;
V_33 = V_1 -> V_173 ;
while ( V_33 -> V_30 & V_174 ) ;
* ( ( char * ) V_33 -> V_44 ) = V_26 ;
V_33 -> V_43 = 1 ;
V_33 -> V_30 |= V_174 ;
if ( V_33 -> V_30 & V_41 )
V_33 = V_1 -> V_175 ;
else
V_33 ++ ;
V_1 -> V_173 = ( T_4 * ) V_33 ;
}
static void F_56 ( struct V_8 * V_9 )
{
T_1 * V_1 = ( T_1 * ) V_9 -> V_10 ;
#ifdef F_57
char V_44 [ 64 ] ;
F_3 ( L_23 , F_58 ( V_9 , V_44 ) ,
V_9 -> V_179 . V_180 ( V_9 ) ) ;
#endif
if ( F_1 ( V_1 , V_9 -> V_2 , L_24 ) )
return;
if ( F_59 ( V_9 ) )
F_55 ( V_9 , F_60 ( V_9 ) ) ;
#ifdef F_27
if ( V_9 -> V_112 -> V_113 & V_167 )
V_1 -> V_111 &= ~ V_116 ;
F_61 () ;
F_24 ( V_1 , V_181 , V_1 -> V_111 ) ;
F_62 () ;
#endif
}
static void F_63 ( struct V_8 * V_9 )
{
T_1 * V_1 = ( T_1 * ) V_9 -> V_10 ;
#ifdef F_57
char V_44 [ 64 ] ;
F_3 ( L_25 , F_58 ( V_9 , V_44 ) ,
V_9 -> V_179 . V_180 ( V_9 ) ) ;
#endif
if ( F_1 ( V_1 , V_9 -> V_2 , L_26 ) )
return;
if ( F_59 ( V_9 ) ) {
if ( V_1 -> V_182 )
V_1 -> V_182 = 0 ;
else
F_55 ( V_9 , F_64 ( V_9 ) ) ;
}
#ifdef F_27
if ( V_9 -> V_112 -> V_113 & V_167 )
V_1 -> V_111 |= V_116 ;
F_61 () ;
F_24 ( V_1 , V_181 , V_1 -> V_111 ) ;
F_62 () ;
#endif
}
static int F_65 ( struct V_61 * V_1 , unsigned int * V_183 )
{
unsigned char V_30 ;
unsigned int V_184 ;
F_61 () ;
V_30 = F_18 ( V_1 , V_185 ) ;
F_62 () ;
V_184 = ( ( V_30 & V_186 ) ? V_187 : 0 ) ;
return F_66 ( V_184 , V_183 ) ;
}
static int F_67 ( struct V_8 * V_9 )
{
T_1 * V_1 = ( T_1 * ) V_9 -> V_10 ;
unsigned int V_184 = 0 ;
#ifdef F_27
unsigned char V_188 , V_30 ;
if ( F_1 ( V_1 , V_9 -> V_2 , V_189 ) )
return - V_190 ;
if ( V_9 -> V_12 & ( 1 << V_109 ) )
return - V_191 ;
V_188 = V_1 -> V_111 ;
F_61 () ;
V_30 = F_18 ( V_1 , V_63 ) ;
F_62 () ;
V_184 = ( ( V_188 & V_116 ) ? V_192 : 0 )
| ( ( V_188 & V_115 ) ? V_193 : 0 )
#ifdef F_68
| ( ( V_188 & V_194 ) ? F_68 : 0 )
| ( ( V_188 & V_195 ) ? V_196 : 0 )
#endif
| ( ( V_30 & V_72 ) ? V_197 : 0 )
| ( ( V_30 & V_198 ) ? V_199 : 0 )
| ( ( V_30 & V_200 ) ? V_201 : 0 )
| ( ( V_30 & V_83 ) ? V_202 : 0 ) ;
#endif
return V_184 ;
}
static int F_69 ( struct V_8 * V_9 ,
unsigned int V_203 , unsigned int V_204 )
{
#ifdef F_27
T_1 * V_1 = ( T_1 * ) V_9 -> V_10 ;
unsigned int V_205 ;
if ( F_1 ( V_1 , V_9 -> V_2 , V_189 ) )
return - V_190 ;
if ( V_9 -> V_12 & ( 1 << V_109 ) )
return - V_191 ;
if ( V_203 & V_192 )
V_1 -> V_206 |= V_116 ;
if ( V_203 & V_193 )
V_1 -> V_206 |= V_115 ;
if ( V_204 & V_192 )
V_1 -> V_111 &= ~ V_116 ;
if ( V_204 & V_193 )
V_1 -> V_111 &= ~ V_115 ;
#ifdef F_68
if ( V_203 & F_68 )
V_1 -> V_111 |= V_194 ;
if ( V_203 & V_196 )
V_1 -> V_111 |= V_195 ;
if ( V_204 & F_68 )
V_1 -> V_111 &= ~ V_194 ;
if ( V_204 & V_196 )
V_1 -> V_111 &= ~ V_195 ;
#endif
F_61 () ;
F_24 ( V_1 , V_181 , V_1 -> V_111 ) ;
F_62 () ;
#endif
return 0 ;
}
static void F_70 ( T_1 * V_1 )
{
volatile T_6 * V_28 ;
T_3 V_207 ;
int V_11 ;
V_28 = V_20 ;
V_11 = F_6 ( V_1 -> V_17 -> V_18 ) ;
if ( V_1 -> V_17 -> V_18 & V_19 )
V_207 = V_208 [ V_11 ] ;
else
V_207 = V_209 [ V_11 ] ;
V_28 -> V_210 = F_71 ( V_207 , V_211 ) | V_212 ;
while ( V_28 -> V_210 & V_212 ) ;
}
static void F_72 ( T_1 * V_1 )
{
volatile T_6 * V_28 ;
T_3 V_207 ;
int V_11 ;
V_28 = V_20 ;
V_11 = F_6 ( V_1 -> V_17 -> V_18 ) ;
if ( V_1 -> V_17 -> V_18 & V_19 )
V_207 = V_208 [ V_11 ] ;
else
V_207 = V_209 [ V_11 ] ;
V_28 -> V_210 = F_71 ( V_207 , V_213 ) | V_212 ;
while ( V_28 -> V_210 & V_212 ) ;
}
static void F_73 ( T_1 * V_1 , unsigned int V_214 )
{
#ifdef F_74
F_3 ( L_27 , V_214 , V_99 ) ;
#endif
F_70 ( V_1 ) ;
F_75 ( V_214 ) ;
F_72 ( V_1 ) ;
#ifdef F_74
F_3 ( L_28 , V_99 ) ;
#endif
}
static int F_76 ( struct V_8 * V_9 ,
struct V_215 * V_32 )
{
T_1 * V_1 = ( T_1 * ) V_9 -> V_10 ;
struct V_31 V_216 ;
F_61 () ;
V_216 = V_1 -> V_17 -> V_32 ;
F_62 () ;
V_32 -> V_74 = V_216 . V_74 ;
V_32 -> V_68 = V_216 . V_68 ;
V_32 -> V_66 = V_216 . V_66 ;
V_32 -> V_70 = V_216 . V_70 ;
return 0 ;
}
static int F_77 ( struct V_8 * V_9 ,
unsigned int V_217 , unsigned long V_205 )
{
int error ;
T_1 * V_1 = ( T_1 * ) V_9 -> V_10 ;
int V_102 ;
struct V_31 V_216 ;
struct V_215 * V_218 ;
if ( F_1 ( V_1 , V_9 -> V_2 , L_29 ) )
return - V_190 ;
if ( V_217 != V_219 ) {
if ( V_9 -> V_12 & ( 1 << V_109 ) )
return - V_191 ;
}
switch ( V_217 ) {
case V_220 :
V_102 = F_78 ( V_9 ) ;
if ( V_102 )
return V_102 ;
F_79 ( V_9 , 0 ) ;
if ( F_80 ( V_221 ) )
return - V_222 ;
if ( ! V_205 ) {
F_73 ( V_1 , 250 ) ;
if ( F_80 ( V_221 ) )
return - V_222 ;
}
return 0 ;
case V_223 :
V_102 = F_78 ( V_9 ) ;
if ( V_102 )
return V_102 ;
F_79 ( V_9 , 0 ) ;
if ( F_80 ( V_221 ) )
return - V_222 ;
F_73 ( V_1 , V_205 ? V_205 * 100 : 250 ) ;
if ( F_80 ( V_221 ) )
return - V_222 ;
return 0 ;
case V_224 :
V_102 = F_78 ( V_9 ) ;
if ( V_102 )
return V_102 ;
F_79 ( V_9 , 0 ) ;
F_70 ( V_1 ) ;
return 0 ;
case V_225 :
V_102 = F_78 ( V_9 ) ;
if ( V_102 )
return V_102 ;
F_72 ( V_1 ) ;
return 0 ;
#ifdef F_34
case V_226 :
return F_65 ( V_1 , ( unsigned int * ) V_205 ) ;
#endif
case V_219 :
#ifdef F_27
F_61 () ;
V_227 = V_1 -> V_17 -> V_32 ;
F_62 () ;
while ( 1 ) {
F_81 ( & V_1 -> V_75 ) ;
if ( F_80 ( V_221 ) )
return - V_228 ;
F_61 () ;
V_216 = V_1 -> V_17 -> V_32 ;
F_62 () ;
if ( V_216 . V_66 == V_227 . V_66 && V_216 . V_68 == V_227 . V_68 &&
V_216 . V_70 == V_227 . V_70 && V_216 . V_74 == V_227 . V_74 )
return - V_191 ;
if ( ( ( V_205 & V_199 ) && ( V_216 . V_66 != V_227 . V_66 ) ) ||
( ( V_205 & V_201 ) && ( V_216 . V_68 != V_227 . V_68 ) ) ||
( ( V_205 & V_229 ) && ( V_216 . V_70 != V_227 . V_70 ) ) ||
( ( V_205 & V_202 ) && ( V_216 . V_74 != V_227 . V_74 ) ) ) {
return 0 ;
}
V_227 = V_216 ;
}
#else
return 0 ;
#endif
default:
return - V_230 ;
}
return 0 ;
}
static void F_82 ( struct V_8 * V_9 , struct V_231 * V_232 )
{
T_1 * V_1 = ( T_1 * ) V_9 -> V_10 ;
F_37 ( V_1 ) ;
#ifdef F_27
if ( ( V_232 -> V_113 & V_114 ) &&
! ( V_9 -> V_112 -> V_113 & V_114 ) ) {
V_1 -> V_111 &= ~ ( V_115 | V_116 ) ;
F_61 () ;
F_24 ( V_1 , V_181 , V_1 -> V_111 ) ;
F_62 () ;
}
if ( ! ( V_232 -> V_113 & V_114 ) &&
( V_9 -> V_112 -> V_113 & V_114 ) ) {
V_1 -> V_111 |= V_115 ;
if ( ! V_9 -> V_82 ||
! ( V_9 -> V_112 -> V_113 & V_167 ) ) {
V_1 -> V_111 |= V_116 ;
}
F_61 () ;
F_24 ( V_1 , V_181 , V_1 -> V_111 ) ;
F_62 () ;
}
if ( ( V_232 -> V_113 & V_167 ) &&
! ( V_9 -> V_112 -> V_113 & V_167 ) ) {
V_9 -> V_82 = 0 ;
F_8 ( V_9 ) ;
}
#endif
#if 0
if (!(old_termios->c_cflag & CLOCAL) &&
(tty->termios->c_cflag & CLOCAL))
wake_up_interruptible(&info->open_wait);
#endif
}
static void F_83 ( struct V_8 * V_9 , struct V_233 * V_234 )
{
T_1 * V_1 = ( T_1 * ) V_9 -> V_10 ;
struct V_137 * V_17 ;
unsigned long V_12 ;
int V_11 ;
volatile struct V_15 * V_16 ;
volatile struct V_13 * V_14 ;
if ( ! V_1 || F_1 ( V_1 , V_9 -> V_2 , L_30 ) )
return;
V_17 = V_1 -> V_17 ;
F_5 ( V_12 ) ;
if ( F_84 ( V_234 ) ) {
F_85 ( L_31 ) ;
F_7 ( V_12 ) ;
return;
}
#ifdef V_77
F_3 ( L_32 , V_1 -> line , V_17 -> V_176 ) ;
#endif
if ( ( V_9 -> V_176 == 1 ) && ( V_17 -> V_176 != 1 ) ) {
F_3 ( L_33
L_34 , V_17 -> V_176 ) ;
V_17 -> V_176 = 1 ;
}
if ( -- V_17 -> V_176 < 0 ) {
F_3 ( L_35 ,
V_1 -> line , V_17 -> V_176 ) ;
V_17 -> V_176 = 0 ;
}
if ( V_17 -> V_176 ) {
F_85 ( L_36 ) ;
F_7 ( V_12 ) ;
return;
}
V_1 -> V_12 |= V_235 ;
V_9 -> V_236 = 1 ;
if ( V_1 -> V_237 != V_238 )
F_79 ( V_9 , V_1 -> V_237 ) ;
V_1 -> V_36 &= ~ V_35 ;
if ( V_1 -> V_12 & V_107 ) {
V_11 = F_6 ( V_1 -> V_17 -> V_18 ) ;
if ( V_1 -> V_17 -> V_18 & V_19 ) {
V_14 = & V_20 -> V_13 [ V_11 ] ;
V_14 -> V_21 &= ~ V_124 ;
V_14 -> V_125 . V_126 . V_127 &= ~ V_128 ;
} else {
V_16 = & V_20 -> V_15 [ V_11 ] ;
V_16 -> V_23 &= ~ V_97 ;
V_16 -> V_130 &= ~ V_131 ;
}
F_86 ( V_9 , V_1 -> V_163 ) ;
}
F_38 ( V_1 ) ;
F_54 ( V_9 ) ;
F_87 ( V_9 ) ;
V_9 -> V_236 = 0 ;
V_1 -> V_101 = 0 ;
V_1 -> V_25 . V_9 = NULL ;
if ( V_1 -> V_239 ) {
if ( V_1 -> V_240 ) {
F_75 ( F_88 ( V_1 -> V_240 ) ) ;
}
F_21 ( & V_1 -> V_78 ) ;
}
V_1 -> V_12 &= ~ ( V_241 | V_235 ) ;
F_21 ( & V_1 -> V_242 ) ;
F_7 ( V_12 ) ;
}
static void F_86 ( struct V_8 * V_9 , int V_163 )
{
T_1 * V_1 = ( T_1 * ) V_9 -> V_10 ;
unsigned long V_243 , V_244 ;
volatile T_4 * V_33 ;
if ( F_1 ( V_1 , V_9 -> V_2 , L_37 ) )
return;
#ifdef F_34
if ( V_1 -> V_17 -> type == V_245 )
return;
#endif
V_243 = V_99 ;
V_244 = 1 ;
if ( V_163 )
V_244 = F_51 ( V_244 , ( unsigned long ) V_163 ) ;
#ifdef F_89
F_3 ( L_38 , V_163 , V_244 ) ;
F_3 ( L_39 , V_99 ) ;
#endif
do {
#ifdef F_89
F_3 ( L_40 , V_246 , V_99 ) ;
#endif
F_75 ( F_88 ( V_244 ) ) ;
if ( F_80 ( V_221 ) )
break;
if ( V_163 && ( F_90 ( V_99 , V_243 + V_163 ) ) )
break;
V_33 = V_1 -> V_173 ;
if ( V_33 == V_1 -> V_175 )
V_33 += ( V_247 - 1 ) ;
else
V_33 -- ;
} while ( V_33 -> V_30 & V_174 );
V_221 -> V_17 = V_248 ;
#ifdef F_89
F_3 ( L_41 , V_246 , V_99 ) ;
#endif
}
static void F_91 ( struct V_8 * V_9 )
{
T_1 * V_1 = ( T_1 * ) V_9 -> V_10 ;
struct V_137 * V_17 = V_1 -> V_17 ;
if ( F_1 ( V_1 , V_9 -> V_2 , L_42 ) )
return;
V_17 = V_1 -> V_17 ;
F_54 ( V_9 ) ;
F_38 ( V_1 ) ;
V_1 -> V_101 = 0 ;
V_17 -> V_176 = 0 ;
V_1 -> V_12 &= ~ V_241 ;
V_1 -> V_25 . V_9 = NULL ;
F_21 ( & V_1 -> V_78 ) ;
}
static int F_92 ( struct V_8 * V_9 , struct V_233 * V_234 ,
T_1 * V_1 )
{
#ifdef F_93
F_94 ( V_249 , V_221 ) ;
#endif
struct V_137 * V_17 = V_1 -> V_17 ;
int V_102 ;
int V_250 = 0 ;
if ( F_84 ( V_234 ) ||
( V_1 -> V_12 & V_235 ) ) {
if ( V_1 -> V_12 & V_235 )
F_81 ( & V_1 -> V_242 ) ;
#ifdef F_95
if ( V_1 -> V_12 & V_251 )
return - V_252 ;
else
return - V_228 ;
#else
return - V_252 ;
#endif
}
if ( ( V_234 -> V_253 & V_254 ) ||
( V_9 -> V_12 & ( 1 << V_109 ) ) ||
! ( V_1 -> V_17 -> V_18 & V_19 ) ) {
V_1 -> V_12 |= V_241 ;
return 0 ;
}
if ( V_9 -> V_112 -> V_113 & V_168 )
V_250 = 1 ;
V_102 = 0 ;
#ifdef F_93
F_96 ( & V_1 -> V_78 , & V_249 ) ;
#ifdef V_77
F_3 ( L_43 ,
V_17 -> line , V_17 -> V_176 ) ;
#endif
F_61 () ;
if ( ! F_84 ( V_234 ) )
V_17 -> V_176 -- ;
F_62 () ;
V_1 -> V_239 ++ ;
while ( 1 ) {
F_61 () ;
if ( V_9 -> V_112 -> V_113 & V_114 )
F_24 ( V_1 , V_181 ,
F_97 ( V_1 , V_181 ) |
( V_115 | V_116 ) ) ;
F_62 () ;
F_98 ( V_255 ) ;
if ( F_84 ( V_234 ) ||
! ( V_1 -> V_12 & V_107 ) ) {
#ifdef F_95
if ( V_1 -> V_12 & V_251 )
V_102 = - V_252 ;
else
V_102 = - V_228 ;
#else
V_102 = - V_252 ;
#endif
break;
}
if ( ! ( V_1 -> V_12 & V_235 ) &&
( V_250 || ( F_18 ( V_1 , V_63 ) &
V_72 ) ) )
break;
if ( F_80 ( V_221 ) ) {
V_102 = - V_228 ;
break;
}
#ifdef V_77
F_3 ( L_44 ,
V_1 -> line , V_17 -> V_176 ) ;
#endif
F_99 () ;
F_100 () ;
F_101 () ;
}
V_221 -> V_17 = V_248 ;
F_102 ( & V_1 -> V_78 , & V_249 ) ;
if ( ! F_84 ( V_234 ) )
V_17 -> V_176 ++ ;
V_1 -> V_239 -- ;
#ifdef V_77
F_3 ( L_45 ,
V_1 -> line , V_17 -> V_176 ) ;
#endif
#endif
if ( V_102 )
return V_102 ;
V_1 -> V_12 |= V_241 ;
return 0 ;
}
static int F_103 ( int line , T_1 * * V_256 )
{
struct V_137 * V_257 ;
V_257 = V_138 + line ;
if ( V_257 -> V_1 ) {
V_257 -> V_176 ++ ;
* V_256 = ( T_1 * ) V_257 -> V_1 ;
return 0 ;
}
else {
return - V_258 ;
}
}
static int F_104 ( struct V_8 * V_9 , struct V_233 * V_234 )
{
T_1 * V_1 ;
int V_102 , line ;
line = V_9 -> V_259 ;
if ( ( line < 0 ) || ( line >= V_260 ) )
return - V_190 ;
V_102 = F_103 ( line , & V_1 ) ;
if ( V_102 )
return V_102 ;
if ( F_1 ( V_1 , V_9 -> V_2 , L_46 ) )
return - V_190 ;
#ifdef V_77
F_3 ( L_47 , V_9 -> V_2 , V_1 -> V_17 -> V_176 ) ;
#endif
V_9 -> V_10 = V_1 ;
V_1 -> V_25 . V_9 = V_9 ;
V_102 = F_33 ( V_1 ) ;
if ( V_102 )
return V_102 ;
V_102 = F_92 ( V_9 , V_234 , V_1 ) ;
if ( V_102 ) {
#ifdef V_77
F_3 ( L_48 ,
V_102 ) ;
#endif
return V_102 ;
}
#ifdef V_77
F_3 ( L_49 , V_9 -> V_2 ) ;
#endif
return 0 ;
}
static inline int F_105 ( char * V_44 , struct V_137 * V_17 )
{
#ifdef F_106
struct V_61 * V_1 = V_17 -> V_1 , V_261 ;
char V_262 [ 30 ] , V_188 , V_30 ;
#endif
int V_178 ;
V_178 = sprintf ( V_44 , L_50 ,
V_17 -> line ,
( V_17 -> V_18 & V_19 ) ? L_51 : L_52 ,
( unsigned int ) ( V_17 -> V_25 ) , V_17 -> V_110 ) ;
if ( ! V_17 -> V_25 || ( V_17 -> type == V_245 ) ) {
V_178 += sprintf ( V_44 + V_178 , L_53 ) ;
return V_178 ;
}
#ifdef F_106
if ( ! V_1 ) {
V_1 = & V_261 ;
V_1 -> V_6 = V_7 ;
V_1 -> V_25 = V_17 -> V_25 ;
V_1 -> V_12 = V_17 -> V_12 ;
V_1 -> V_263 = 0 ;
V_1 -> V_25 . V_9 = NULL ;
}
F_61 () ;
V_30 = F_18 ( V_1 , V_63 ) ;
V_188 = V_1 ? V_1 -> V_111 : F_18 ( V_1 , V_181 ) ;
F_62 () ;
V_262 [ 0 ] = 0 ;
V_262 [ 1 ] = 0 ;
if ( V_188 & V_116 )
strcat ( V_262 , L_54 ) ;
if ( V_30 & V_83 )
strcat ( V_262 , L_55 ) ;
if ( V_188 & V_115 )
strcat ( V_262 , L_56 ) ;
if ( V_30 & V_200 )
strcat ( V_262 , L_57 ) ;
if ( V_30 & V_72 )
strcat ( V_262 , L_58 ) ;
if ( V_30 & V_198 )
strcat ( V_262 , L_59 ) ;
if ( V_1 -> V_263 ) {
V_178 += sprintf ( V_44 + V_178 , L_60 ,
V_17 -> V_264 / V_1 -> V_263 ) ;
}
V_178 += sprintf ( V_44 + V_178 , L_61 ,
V_17 -> V_32 . V_265 , V_17 -> V_32 . V_45 ) ;
if ( V_17 -> V_32 . V_49 )
V_178 += sprintf ( V_44 + V_178 , L_62 , V_17 -> V_32 . V_49 ) ;
if ( V_17 -> V_32 . V_48 )
V_178 += sprintf ( V_44 + V_178 , L_63 , V_17 -> V_32 . V_48 ) ;
if ( V_17 -> V_32 . V_47 )
V_178 += sprintf ( V_44 + V_178 , L_64 , V_17 -> V_32 . V_47 ) ;
if ( V_17 -> V_32 . V_50 )
V_178 += sprintf ( V_44 + V_178 , L_65 , V_17 -> V_32 . V_50 ) ;
V_178 += sprintf ( V_44 + V_178 , L_66 , V_262 + 1 ) ;
#endif
return V_178 ;
}
int F_107 ( char * V_266 , char * * V_267 , T_7 V_268 , int V_176 ,
int * V_269 , void * V_270 )
{
int V_29 , V_271 = 0 ;
T_7 V_272 = 0 ;
V_271 += sprintf ( V_266 , L_67 , V_273 ) ;
for ( V_29 = 0 ; V_29 < V_260 && V_271 < 4000 ; V_29 ++ ) {
V_271 += F_105 ( V_266 + V_271 , & V_138 [ V_29 ] ) ;
if ( V_271 + V_272 > V_268 + V_176 )
goto V_274;
if ( V_271 + V_272 < V_268 ) {
V_272 += V_271 ;
V_271 = 0 ;
}
}
* V_269 = 1 ;
V_274:
if ( V_268 >= V_271 + V_272 )
return 0 ;
* V_267 = V_266 + ( V_272 - V_268 ) ;
return ( ( V_176 < V_272 + V_271 - V_268 ) ? V_176 : V_272 + V_271 - V_268 ) ;
}
static T_2 void F_108 ( void )
{
F_3 ( V_275 L_68 , V_276 , V_273 ) ;
}
static void F_109 ( int V_11 , const char * V_277 ,
unsigned V_176 )
{
struct V_137 * V_278 ;
T_1 * V_1 ;
unsigned V_29 ;
T_4 * V_33 , * V_279 ;
volatile struct V_103 * V_104 ;
volatile T_5 * V_28 ;
V_278 = V_138 + V_11 ;
if ( ( V_1 = ( T_1 * ) V_278 -> V_1 ) != NULL ) {
V_33 = V_1 -> V_173 ;
V_279 = V_1 -> V_175 ;
}
else {
V_104 = & V_20 -> V_117 [ V_278 -> V_25 ] . V_118 . V_133 . V_134 . V_135 . V_120 ;
V_33 = V_279 = ( T_4 * ) ( ( V_280 ) V_20 + ( V_280 ) V_104 -> V_281 ) ;
}
for ( V_29 = 0 ; V_29 < V_176 ; V_29 ++ , V_277 ++ ) {
while ( V_33 -> V_30 & V_174 ) ;
V_28 = V_33 -> V_44 ;
* V_28 = * V_277 ;
V_33 -> V_43 = 1 ;
V_33 -> V_30 |= V_174 ;
if ( V_33 -> V_30 & V_41 )
V_33 = V_279 ;
else
V_33 ++ ;
if ( * V_277 == 10 ) {
while ( V_33 -> V_30 & V_174 ) ;
V_28 = V_33 -> V_44 ;
* V_28 = 13 ;
V_33 -> V_43 = 1 ;
V_33 -> V_30 |= V_174 ;
if ( V_33 -> V_30 & V_41 ) {
V_33 = V_279 ;
}
else {
V_33 ++ ;
}
}
}
while ( V_33 -> V_30 & V_174 ) ;
if ( V_1 )
V_1 -> V_173 = ( T_4 * ) V_33 ;
}
static void F_110 ( struct V_282 * V_177 , const char * V_277 ,
unsigned V_176 )
{
#ifdef F_49
if ( F_50 ( V_277 , V_176 ) )
return;
#endif
F_109 ( V_177 -> V_259 , V_277 , V_176 ) ;
}
int
F_111 ( const char * V_277 , unsigned V_176 )
{
F_109 ( 0 , V_277 , V_176 ) ;
return ( V_176 ) ;
}
void
F_112 ( char V_26 )
{
F_109 ( 0 , & V_26 , 1 ) ;
}
static int F_113 ( int V_11 , int V_283 , char * V_284 )
{
struct V_137 * V_278 ;
T_5 V_177 , * V_28 ;
T_1 * V_1 ;
T_4 * V_33 ;
volatile struct V_103 * V_104 ;
int V_29 ;
V_278 = V_138 + V_11 ;
if ( ( V_1 = ( T_1 * ) V_278 -> V_1 ) )
V_33 = V_1 -> V_34 ;
else
V_33 = ( T_4 * ) ( ( V_280 ) V_20 + ( V_280 ) V_104 -> V_281 ) ;
V_104 = & V_20 -> V_117 [ V_1 -> V_17 -> V_25 ] . V_118 . V_133 . V_134 . V_135 . V_120 ;
if ( ! V_283 ) {
while ( V_33 -> V_30 & V_35 ) ;
}
else {
if ( V_33 -> V_30 & V_35 )
return - 1 ;
}
V_28 = ( char * ) V_33 -> V_44 ;
if ( V_284 ) {
V_29 = V_177 = V_33 -> V_43 ;
while ( V_29 -- > 0 )
* V_284 ++ = * V_28 ++ ;
}
else {
V_177 = * V_28 ;
}
V_33 -> V_30 |= V_35 ;
if ( V_1 ) {
if ( V_33 -> V_30 & V_41 ) {
V_33 = V_1 -> V_42 ;
}
else {
V_33 ++ ;
}
V_1 -> V_34 = ( T_4 * ) V_33 ;
}
return ( ( int ) V_177 ) ;
}
static int F_114 ( struct V_282 * V_285 )
{
return ( F_113 ( V_285 -> V_259 , 0 , NULL ) ) ;
}
int
F_115 ( void )
{
return ( F_113 ( 0 , 1 , NULL ) ) ;
}
int
F_116 ( void )
{
return ( F_113 ( 0 , 0 , NULL ) ) ;
}
unsigned char
F_117 ( void )
{
if ( V_286 <= 0 ) {
V_286 = F_113 ( 0 , 0 , V_287 ) ;
V_288 = V_287 ;
}
V_286 -- ;
return ( * V_288 ++ ) ;
}
void F_118 ( int V_17 )
{
}
void F_119 ( void )
{
struct V_137 * V_278 ;
V_280 V_289 ;
volatile T_4 * V_33 ;
volatile T_8 * V_104 ;
V_290 = ( V_291 * ) & ( ( ( V_292 * ) V_293 ) -> V_294 ) ;
V_278 = V_138 ;
V_104 = ( T_8 * ) & V_290 -> V_295 [ V_278 -> V_25 ] ;
V_289 = ( V_280 ) ( & V_290 -> V_296 [ 0x1000 ] ) ;
V_33 = ( T_4 * ) & V_290 -> V_296 [ V_104 -> V_297 ] ;
V_33 -> V_44 = V_289 ;
V_33 = ( T_4 * ) & V_290 -> V_296 [ V_104 -> V_298 ] ;
V_33 -> V_44 = V_289 + V_122 ;
V_104 -> V_299 = V_122 ;
V_104 -> V_300 = V_122 ;
}
static struct V_8 * F_120 ( struct V_282 * V_177 , int * V_259 )
{
* V_259 = V_177 -> V_259 ;
return V_301 ;
}
long F_121 ( long V_302 , long V_303 )
{
F_122 ( & V_304 ) ;
return V_302 ;
}
static int T_9 F_123 ( void )
{
struct V_137 * V_17 ;
T_1 * V_1 ;
void * V_289 ;
V_280 V_305 , V_306 ;
int V_29 , V_307 , V_11 ;
T_3 V_207 ;
T_4 * V_33 ;
volatile T_6 * V_28 ;
volatile struct V_15 * V_308 ;
volatile struct V_103 * V_104 ;
volatile struct V_13 * V_309 ;
volatile struct V_105 * V_310 ;
V_301 = F_124 ( V_260 ) ;
if ( ! V_301 )
return - 1 ;
F_108 () ;
V_301 -> V_2 = L_69 ;
V_301 -> V_311 = V_312 ;
V_301 -> V_313 = 64 ;
V_301 -> type = V_314 ;
V_301 -> V_315 = V_316 ;
V_301 -> V_317 = V_318 ;
V_301 -> V_317 . V_113 =
V_319 | V_151 | V_170 | V_320 | V_168 ;
V_301 -> V_12 = V_321 ;
F_125 ( V_301 , & V_322 ) ;
if ( F_126 ( V_301 ) )
F_127 ( L_70 ) ;
V_28 = V_20 ;
V_28 -> V_323 |= 0x00fc ;
V_28 -> V_324 &= ~ 0x00fc ;
V_28 -> V_325 &= ~ 0x00ffff00 ;
V_28 -> V_325 |= 0x001b1200 ;
#ifdef F_128
V_326 -> V_327 . V_328 |= 0x000c ;
V_326 -> V_327 . V_329 &= ~ 0x000c ;
V_326 -> V_327 . V_330 &= ~ 0x000c ;
V_28 -> V_331 &= ~ 0x6000 ;
V_28 -> V_332 &= ~ 0x6000 ;
#endif
for ( V_29 = 0 , V_17 = V_138 ; V_29 < V_260 ; V_29 ++ , V_17 ++ ) {
V_17 -> V_6 = V_333 ;
V_17 -> line = V_29 ;
V_17 -> type = V_245 ;
V_17 -> V_334 = 0 ;
V_17 -> V_240 = 5 * V_165 / 10 ;
V_17 -> V_237 = 30 * V_165 ;
V_17 -> V_32 . V_74 = V_17 -> V_32 . V_68 =
V_17 -> V_32 . V_66 = V_17 -> V_32 . V_70 = 0 ;
V_17 -> V_32 . V_45 = V_17 -> V_32 . V_265 = 0 ;
V_17 -> V_32 . V_49 = V_17 -> V_32 . V_48 = 0 ;
V_17 -> V_32 . V_50 = V_17 -> V_32 . V_47 = 0 ;
F_3 ( V_275 L_71 ,
V_29 , ( unsigned int ) ( V_17 -> V_110 ) ,
( V_17 -> V_18 & V_19 ) ? L_51 : L_52 ) ;
#ifdef F_39
if ( V_29 == V_139 )
F_129 ( 8 ) ;
#endif
V_1 = & V_335 [ V_29 ] ;
if ( V_1 ) {
memset ( V_1 , 0 , sizeof( T_1 ) ) ;
V_1 -> V_6 = V_7 ;
V_1 -> line = V_29 ;
V_1 -> V_12 = V_17 -> V_12 ;
F_130 ( & V_1 -> V_60 , F_28 , V_1 ) ;
F_130 ( & V_1 -> V_79 , F_31 , V_1 ) ;
F_131 ( & V_1 -> V_78 ) ;
F_131 ( & V_1 -> V_242 ) ;
V_1 -> V_17 = V_17 ;
V_17 -> V_1 = (struct V_61 * ) V_1 ;
V_305 = F_132 ( sizeof( T_4 ) * V_336 ) ;
V_289 = & V_337 [ V_29 * V_336 * V_122 ] ;
V_33 = ( T_4 * ) ( ( V_280 ) V_20 + V_305 ) ;
V_1 -> V_34 = V_1 -> V_42 = V_33 ;
for ( V_307 = 0 ; V_307 < ( V_336 - 1 ) ; V_307 ++ ) {
V_33 -> V_44 = & V_337 [ ( V_29 * V_336 + V_307 ) * V_122 ] ;
V_33 -> V_30 = V_35 | V_338 ;
V_289 += V_122 ;
V_33 ++ ;
}
V_33 -> V_44 = & V_337 [ ( V_29 * V_336 + V_307 ) * V_122 ] ;
V_33 -> V_30 = V_41 | V_35 | V_338 ;
V_11 = F_6 ( V_1 -> V_17 -> V_18 ) ;
if ( V_1 -> V_17 -> V_18 & V_19 ) {
#if F_22 ( V_339 ) && 1
V_340 &= ~ ( V_280 ) F_133 ( V_11 , 0x0f ) ;
V_340 |= ( V_280 ) F_133 ( V_11 , 0x02 ) ;
* ( V_280 * ) V_341 = V_340 ;
#endif
}
V_305 = F_132 ( sizeof( T_4 ) * V_247 ) ;
V_289 = & V_342 [ V_29 * V_247 * V_164 ] ;
V_33 = ( T_4 * ) ( ( V_280 ) V_20 + V_305 ) ;
V_1 -> V_173 = V_1 -> V_175 = ( T_4 * ) V_33 ;
for ( V_307 = 0 ; V_307 < ( V_247 - 1 ) ; V_307 ++ ) {
V_33 -> V_44 = & V_342 [ ( V_29 * V_247 + V_307 ) * V_164 ] ;
V_33 -> V_30 = V_338 ;
V_289 += V_164 ;
V_33 ++ ;
}
V_33 -> V_44 = & V_342 [ ( V_29 * V_247 + V_307 ) * V_164 ] ;
V_33 -> V_30 = ( V_41 | V_338 ) ;
if ( V_1 -> V_17 -> V_18 & V_19 ) {
V_309 = & V_20 -> V_13 [ V_11 ] ;
V_310 = & V_20 -> V_117 [ V_1 -> V_17 -> V_25 ] . V_118 . V_119 . V_120 ;
V_310 -> V_343 = V_305 ;
V_310 -> V_281 = V_305 ;
V_310 -> V_344 = V_345 ;
V_310 -> V_346 = V_345 ;
V_310 -> V_121 = 1 ;
V_310 -> V_123 = 0 ;
V_310 -> V_136 = 1 ;
V_310 -> V_347 = 0 ;
V_310 -> V_348 = 0 ;
V_310 -> V_349 = 0 ;
V_310 -> V_350 = 0 ;
V_310 -> V_351 = 0 ;
V_310 -> V_352 = 0 ;
V_310 -> V_353 = 0 ;
{
int V_29 ;
for ( V_29 = 0 ; V_29 < 8 ; V_29 ++ )
V_310 -> V_354 [ V_29 ] = 0x8000 ;
}
V_310 -> V_355 = 0xc0ff ;
V_207 = V_208 [ V_11 ] ;
V_28 -> V_210 = F_71 ( V_207 , V_356 ) | V_212 ;
while ( V_28 -> V_210 & V_212 ) ;
V_309 -> V_125 . V_126 . V_357 = 0 ;
V_309 -> V_125 . V_126 . V_127 =
( V_358 | V_359 | V_360 ) ;
V_309 -> V_21 = 0 ;
V_309 -> V_92 = 0xffff ;
V_309 -> V_361 = 0x7e7e ;
V_309 -> V_171 = 0x3000 ;
#ifdef F_39
if ( V_29 == V_139 )
V_309 -> V_125 . V_126 . V_127 |= ( V_128 | V_129 ) ;
#endif
}
else {
V_104 = & V_20 -> V_117 [ V_1 -> V_17 -> V_25 ] . V_118 . V_133 . V_134 . V_135 . V_120 ;
V_104 -> V_343 = V_305 ;
V_306 = 0xc0 << ( V_11 * 4 ) ;
V_28 -> V_362 |= V_306 ;
V_28 -> V_363 &= ~ V_306 ;
V_28 -> V_364 &= ~ V_306 ;
V_28 -> V_365 &= ~ ( 0xffff << ( V_11 * 16 ) ) ;
V_28 -> V_365 |= ( V_29 << ( ( V_11 * 16 ) + 12 ) ) ;
V_104 -> V_281 = V_305 ;
V_104 -> V_344 = V_345 ;
V_104 -> V_346 = V_345 ;
V_104 -> V_121 = 1 ;
V_104 -> V_123 = 0 ;
V_104 -> V_136 = 1 ;
V_207 = V_209 [ V_11 ] ;
V_28 -> V_210 = F_71 ( V_207 ,
V_356 ) | V_212 ;
#ifdef F_39
if ( V_29 == V_139 )
F_3 ( L_72 ) ;
#endif
while ( V_28 -> V_210 & V_212 ) ;
V_308 = & V_28 -> V_15 [ V_11 ] ;
V_308 -> V_130 = F_45 ( 9 ) | V_172 ;
V_308 -> V_23 = 0 ;
V_308 -> V_95 = 0xff ;
#ifdef F_39
if ( V_29 == V_139 )
V_308 -> V_130 |= V_131 | V_132 ;
#endif
}
F_134 ( V_17 -> V_110 , F_26 , 0 , L_69 ,
( void * ) V_1 ) ;
F_46 ( V_29 , V_162 [ V_319 ] ) ;
}
}
return 0 ;
}
int F_135 ( struct V_282 * V_285 , char * V_366 )
{
struct V_137 * V_278 ;
V_280 V_289 , V_305 , V_367 , V_11 , V_306 ;
T_3 V_207 ;
T_4 * V_33 ;
volatile T_6 * V_28 ;
volatile struct V_15 * V_308 ;
volatile struct V_13 * V_309 ;
volatile struct V_103 * V_104 ;
volatile struct V_105 * V_310 ;
for ( V_367 = 0 ; V_367 < ( sizeof( V_162 ) / sizeof( int ) ) ; V_367 ++ )
if ( V_368 == V_162 [ V_367 ] )
break;
V_319 = V_367 ;
V_278 = V_138 + V_139 ;
V_28 = V_20 ;
V_11 = F_6 ( V_278 -> V_18 ) ;
if ( V_278 -> V_18 & V_19 ) {
}
else {
V_306 = 0xc0 << ( V_11 * 4 ) ;
V_28 -> V_362 |= V_306 ;
V_28 -> V_363 &= ~ V_306 ;
V_28 -> V_364 &= ~ V_306 ;
V_28 -> V_365 &= ~ ( 0xffff << ( V_11 * 16 ) ) ;
V_28 -> V_365 |= ( V_11 << ( ( V_11 * 16 ) + 12 ) ) ;
}
V_305 = F_132 ( sizeof( T_4 ) * V_369 ) ;
V_289 = ( V_280 ) V_370 ;
V_33 = ( T_4 * ) ( ( V_280 ) V_20 + V_305 ) ;
V_33 -> V_44 = ( char * ) V_289 ;
( V_33 + 1 ) -> V_44 = ( char * ) ( V_289 + 4 ) ;
V_33 -> V_30 = V_35 | V_41 ;
( V_33 + 1 ) -> V_30 = V_41 ;
if ( V_278 -> V_18 & V_19 ) {
V_309 = & V_28 -> V_13 [ V_11 ] ;
V_310 = & V_20 -> V_117 [ V_278 -> V_25 ] . V_118 . V_119 . V_120 ;
V_310 -> V_343 = V_305 ;
V_310 -> V_281 = V_305 + sizeof( T_4 ) ;
V_310 -> V_344 = V_345 ;
V_310 -> V_346 = V_345 ;
V_310 -> V_121 = 1 ;
V_310 -> V_123 = 0 ;
V_310 -> V_136 = 1 ;
V_310 -> V_347 = 0 ;
V_310 -> V_348 = 0 ;
V_310 -> V_349 = 0 ;
V_310 -> V_350 = 0 ;
V_310 -> V_351 = 0 ;
V_310 -> V_352 = 0 ;
V_310 -> V_353 = 0 ;
{
int V_29 ;
for ( V_29 = 0 ; V_29 < 8 ; V_29 ++ )
V_310 -> V_354 [ V_29 ] = 0x8000 ;
}
V_310 -> V_355 = 0xc0ff ;
V_207 = V_208 [ V_11 ] ;
V_28 -> V_210 = F_71 ( V_207 , V_356 ) | V_212 ;
while ( V_28 -> V_210 & V_212 ) ;
V_309 -> V_125 . V_126 . V_357 = 0 ;
V_309 -> V_125 . V_126 . V_127 =
( V_358 | V_359 | V_360 ) ;
V_309 -> V_21 = 0 ;
V_309 -> V_92 = 0xffff ;
V_309 -> V_361 = 0x7e7e ;
V_309 -> V_171 = 0x3000 ;
V_309 -> V_125 . V_126 . V_127 |= ( V_128 | V_129 ) ;
}
else {
V_104 = & V_20 -> V_117 [ V_278 -> V_25 ] . V_118 . V_133 . V_134 . V_135 . V_120 ;
V_104 -> V_343 = V_305 ;
V_104 -> V_281 = V_305 + sizeof( T_4 ) ;
V_104 -> V_344 = V_345 ;
V_104 -> V_346 = V_345 ;
V_104 -> V_121 = 1 ;
V_104 -> V_123 = 0 ;
V_207 = V_209 [ V_11 ] ;
V_28 -> V_210 = F_71 ( V_207 , V_356 ) | V_212 ;
while ( V_28 -> V_210 & V_212 ) ;
V_308 = & V_28 -> V_15 [ V_11 ] ;
V_308 -> V_130 = F_45 ( 9 ) | V_172 ;
V_308 -> V_130 |= V_131 | V_132 ;
}
F_46 ( ( V_278 - V_138 ) , V_368 ) ;
return 0 ;
}
