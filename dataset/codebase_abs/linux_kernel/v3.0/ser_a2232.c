static inline volatile struct V_1 * F_1 ( unsigned int V_2 )
{
return ( volatile struct V_1 * ) F_2 ( V_3 [ V_2 ] -> V_4 . V_5 ) ;
}
static inline volatile struct V_6 * F_3 ( unsigned int V_2 ,
unsigned int V_7 )
{
volatile struct V_1 * V_8 = F_1 ( V_2 ) ;
return & ( V_8 -> V_9 [ V_7 ] ) ;
}
static inline void F_4 ( struct V_10 * V_11 , int V_12 , int V_13 )
{
struct V_14 * V_15 = V_11 -> V_16 . V_11 . V_15 ;
#if 0
switch(err) {
case TTY_BREAK:
break;
case TTY_PARITY:
break;
case TTY_OVERRUN:
break;
case TTY_FRAME:
break;
}
#endif
F_5 ( V_15 , V_12 , V_13 ) ;
F_6 ( V_15 ) ;
}
static void F_7 ( void * V_17 )
{
struct V_10 * V_11 ;
volatile struct V_6 * V_18 ;
unsigned long V_19 ;
V_11 = V_17 ;
V_18 = F_3 ( V_11 -> V_20 , V_11 -> V_21 ) ;
V_18 -> V_22 = - 1 ;
F_8 ( V_19 ) ;
V_11 -> V_16 . V_11 . V_19 &= ~ V_23 ;
F_9 ( V_19 ) ;
}
static void F_10 ( void * V_17 )
{
struct V_10 * V_11 ;
volatile struct V_6 * V_18 ;
unsigned long V_19 ;
V_11 = V_17 ;
V_18 = F_3 ( V_11 -> V_20 , V_11 -> V_21 ) ;
V_18 -> V_22 = 0 ;
F_8 ( V_19 ) ;
V_11 -> V_16 . V_11 . V_19 |= V_23 ;
F_9 ( V_19 ) ;
}
static void F_11 ( void * V_17 )
{
struct V_10 * V_11 ;
V_11 = V_17 ;
V_11 -> V_24 = - 1 ;
}
static void F_12 ( void * V_17 )
{
struct V_10 * V_11 ;
V_11 = V_17 ;
V_11 -> V_24 = 0 ;
}
static int F_13 ( struct V_25 * V_11 )
{
struct V_10 * V_26 = F_14 ( V_11 , struct V_10 , V_16 . V_11 ) ;
return V_26 -> V_27 ;
}
static void F_15 ( void * V_17 )
{
struct V_10 * V_11 ;
volatile struct V_6 * V_18 ;
unsigned long V_19 ;
V_11 = V_17 ;
V_18 = F_3 ( V_11 -> V_20 , V_11 -> V_21 ) ;
F_8 ( V_19 ) ;
V_11 -> V_16 . V_11 . V_19 &= ~ V_28 ;
if ( V_11 -> V_16 . V_11 . V_15 && V_11 -> V_16 . V_11 . V_15 -> V_29 -> V_30 & V_31 ) {
V_18 -> V_32 = ( ( V_18 -> V_32 & ~ V_33 ) |
V_34 ) ;
V_18 -> V_35 = - 1 ;
V_18 -> V_36 = - 1 ;
}
F_9 ( V_19 ) ;
}
static int F_16 ( void * V_17 )
{
unsigned int V_37 , V_38 , V_39 , V_40 , V_41 , V_42 ;
int V_43 ;
int V_44 , V_45 ;
unsigned long V_19 ;
unsigned int V_46 ;
struct V_10 * V_11 = V_17 ;
volatile struct V_6 * V_47 ;
volatile struct V_1 * V_8 ;
if ( ! V_11 -> V_16 . V_11 . V_15 || ! V_11 -> V_16 . V_11 . V_15 -> V_29 ) return 0 ;
V_47 = F_3 ( V_11 -> V_20 , V_11 -> V_21 ) ;
V_8 = F_1 ( V_11 -> V_20 ) ;
V_44 = V_45 = 0 ;
V_38 = V_11 -> V_16 . V_38 ;
if ( V_38 == 0 ) {
F_8 ( V_19 ) ;
V_47 -> V_32 = ( ( V_47 -> V_32 & ~ V_33 ) |
V_34 ) ;
V_47 -> V_35 = - 1 ;
V_47 -> V_36 = - 1 ;
F_9 ( V_19 ) ;
return 0 ;
}
V_43 = V_48 ;
for ( V_46 = 0 ; V_46 < V_49 * 3 ; V_46 += 3 ) {
if ( V_50 [ V_46 ] == V_38 ) {
if ( V_8 -> V_51 . V_52 == V_53 ) V_43 = V_50 [ V_46 + 2 ] ;
else V_43 = V_50 [ V_46 + 1 ] ;
}
}
if ( V_43 == V_48 ) {
F_17 ( L_1 , V_11 -> V_20 , V_11 -> V_21 , V_38 ) ;
V_43 = V_54 ;
}
V_44 |= V_43 ;
V_37 = V_11 -> V_16 . V_11 . V_15 -> V_29 -> V_30 ;
V_39 = V_37 & V_55 ;
switch ( V_39 ) {
case V_56 : V_44 |= V_57 ; break;
case V_58 : V_44 |= V_59 ; break;
case V_60 : V_44 |= V_61 ; break;
case V_62 : V_44 |= V_63 ; break;
default: F_17 ( L_2 ,
V_11 -> V_20 , V_11 -> V_21 , V_39 ) ;
V_44 |= V_57 ; break;
}
V_40 = V_37 & V_64 ;
if ( V_40 ) {
F_17 ( L_3 ,
V_11 -> V_20 , V_11 -> V_21 ) ;
}
if ( ! ( V_37 & V_65 ) ) {
#ifndef F_18
F_17 ( L_4 ,
V_11 -> V_20 , V_11 -> V_21 ) ;
#endif
}
V_42 = ! ! ( V_11 -> V_16 . V_11 . V_15 -> V_29 -> V_66 & V_67 ) ;
V_41 = V_37 & ( V_68 | V_69 ) ;
if ( V_41 & V_68 ) {
if ( V_41 & V_69 ) {
V_45 |= V_70 ;
}
else{
V_45 |= V_71 ;
}
}
else V_45 |= V_72 ;
if ( V_37 & V_73 )
V_11 -> V_16 . V_11 . V_19 &= ~ V_74 ;
else
V_11 -> V_16 . V_11 . V_19 |= V_74 ;
F_8 ( V_19 ) ;
V_47 -> V_75 = V_44 | V_76 ;
V_47 -> V_32 = V_45 | V_77 | V_78 ;
V_47 -> V_79 = V_42 ;
V_47 -> V_22 = 0 ;
V_47 -> V_36 = - 1 ;
F_9 ( V_19 ) ;
return 0 ;
}
static int F_19 ( void * V_17 )
{
struct V_10 * V_11 ;
volatile struct V_6 * V_47 ;
unsigned char V_80 ;
V_11 = V_17 ;
V_47 = F_3 ( V_11 -> V_20 , V_11 -> V_21 ) ;
#if V_81 != 256
#error "Re-Implement a2232_chars_in_buffer()!"
#endif
V_80 = ( V_47 -> V_82 - V_47 -> V_83 ) ;
return V_80 ;
}
static void F_20 ( void * V_17 )
{
F_7 ( V_17 ) ;
F_11 ( V_17 ) ;
}
static void F_21 ( void * V_17 )
{
F_20 ( V_17 ) ;
}
static int F_22 ( struct V_14 * V_15 ,
unsigned int V_84 , unsigned long V_85 )
{
return - V_86 ;
}
static void F_23 ( struct V_14 * V_15 )
{
struct V_10 * V_11 = V_15 -> V_87 ;
V_11 -> V_88 = - 1 ;
}
static void F_24 ( struct V_14 * V_15 )
{
struct V_10 * V_11 = V_15 -> V_87 ;
V_11 -> V_88 = 0 ;
}
static int F_25 ( struct V_14 * V_15 , struct V_89 * V_90 )
{
int line ;
int V_91 ;
struct V_10 * V_11 ;
line = V_15 -> V_92 ;
V_11 = & V_93 [ line ] ;
V_15 -> V_87 = V_11 ;
V_11 -> V_16 . V_11 . V_15 = V_15 ;
V_11 -> V_16 . V_11 . V_94 ++ ;
V_91 = F_26 ( & V_11 -> V_16 ) ;
if ( V_91 ) {
V_11 -> V_16 . V_11 . V_94 -- ;
return V_91 ;
}
V_11 -> V_16 . V_11 . V_19 |= V_28 ;
V_91 = F_27 ( V_11 , V_90 ) ;
if ( V_91 ) {
V_11 -> V_16 . V_11 . V_94 -- ;
return V_91 ;
}
F_12 ( V_11 ) ;
return 0 ;
}
static T_1 F_28 ( int V_95 , void * V_96 )
{
#if V_81 != 256
#error "Re-Implement a2232_vbl_inter()!"
#endif
struct V_10 * V_11 ;
volatile struct V_1 * V_8 ;
volatile struct V_6 * V_47 ;
unsigned char V_97 ;
unsigned char V_98 ;
unsigned char V_99 , V_100 , V_101 ;
volatile T_2 * V_102 , * V_103 , * V_104 ;
int V_12 , V_13 , V_105 , V_106 ;
for ( V_105 = 0 ; V_105 < V_107 ; V_105 ++ ) {
V_8 = F_1 ( V_105 ) ;
for ( V_106 = 0 ; V_106 < V_108 ; V_106 ++ ) {
V_13 = 0 ;
V_11 = & V_93 [ V_105 * V_108 + V_106 ] ;
if ( V_11 -> V_16 . V_11 . V_19 & V_28 ) {
V_47 = F_3 ( V_105 , V_106 ) ;
if ( ! V_11 -> V_24 && ! V_11 -> V_88 ) {
V_97 = V_47 -> V_109 ;
V_98 = V_47 -> V_110 ;
if ( V_97 != V_98 ) {
V_102 = V_8 -> V_111 [ V_106 ] ;
V_103 = V_8 -> V_112 [ V_106 ] ;
while ( V_98 != V_97 ) {
switch ( V_103 [ V_98 ] ) {
case V_113 :
switch ( V_102 [ V_98 ++ ] ) {
case V_114 :
break;
case V_115 :
F_17 ( L_5 ) ;
break;
default:
F_17 ( L_6 , V_102 [ V_98 - 1 ] ) ;
}
break;
case V_116 :
F_4 ( V_11 , V_102 [ V_98 ] , V_13 ) ;
V_98 ++ ;
break;
default:
F_17 ( L_7 , V_103 [ V_98 ] ) ;
V_98 ++ ;
}
}
V_47 -> V_110 = V_98 ;
}
}
V_104 = V_8 -> V_117 [ V_106 ] ;
V_98 = V_47 -> V_82 ;
while ( ( V_11 -> V_16 . V_118 > 0 ) &&
( ! V_11 -> V_16 . V_11 . V_15 -> V_119 ) &&
( ! V_11 -> V_16 . V_11 . V_15 -> V_120 ) ) {
if ( ( ( V_98 + 1 ) & V_121 ) != V_47 -> V_83 ) {
V_12 = V_11 -> V_16 . V_122 [ V_11 -> V_16 . V_123 ] ;
V_11 -> V_16 . V_123 = ( V_11 -> V_16 . V_123 + 1 ) & ( V_124 - 1 ) ;
V_104 [ V_98 ++ ] = V_12 ;
V_11 -> V_16 . V_118 -- ;
}
else{
break;
}
}
V_47 -> V_82 = V_98 ;
if ( ( V_11 -> V_16 . V_118 <= V_11 -> V_16 . V_125 ) && V_11 -> V_16 . V_11 . V_15 ) {
F_29 ( V_11 -> V_16 . V_11 . V_15 ) ;
}
}
}
V_97 = V_8 -> V_51 . V_126 ;
V_98 = V_8 -> V_51 . V_127 ;
if ( V_97 != V_98 ) {
V_100 = V_8 -> V_51 . V_128 ;
while ( V_97 != V_98 ) {
V_99 = V_8 -> V_129 [ V_98 ++ ] ;
V_101 = V_99 ^ V_100 ;
V_100 = V_99 ;
for( V_106 = 0 ; V_106 < V_108 ; V_106 ++ ) {
if ( V_101 & 1 ) {
struct V_10 * V_11 = & V_93 [ V_105 * 7 + V_106 ] ;
V_11 -> V_27 = ! ( V_99 & 1 ) ;
if ( ! ( V_11 -> V_16 . V_11 . V_19 & V_74 ) )
;
else if ( V_11 -> V_27 ) {
F_30 ( & V_11 -> V_16 . V_11 . V_130 ) ;
}
else {
if ( V_11 -> V_16 . V_11 . V_15 )
F_31 ( V_11 -> V_16 . V_11 . V_15 ) ;
}
}
V_101 >>= 1 ;
V_99 >>= 1 ;
}
}
V_8 -> V_51 . V_128 = V_100 ;
V_8 -> V_51 . V_127 = V_98 ;
}
}
return V_131 ;
}
static void F_32 ( void )
{
struct V_10 * V_11 ;
int V_46 ;
for ( V_46 = 0 ; V_46 < V_132 * V_108 ; V_46 ++ ) {
V_11 = V_93 + V_46 ;
F_33 ( & V_11 -> V_16 . V_11 ) ;
V_11 -> V_16 . V_11 . V_133 = & V_134 ;
V_11 -> V_20 = V_46 / V_108 ;
V_11 -> V_21 = V_46 % V_108 ;
V_11 -> V_24 = V_11 -> V_88 = V_11 -> V_27 = 0 ;
V_11 -> V_16 . V_135 = V_136 ;
V_11 -> V_16 . V_137 = V_138 / 2 ;
V_11 -> V_16 . V_139 = 30 * V_138 ;
V_11 -> V_16 . V_140 = & V_141 ;
}
}
static int F_34 ( void )
{
int error ;
V_142 = F_35 ( V_108 * V_107 ) ;
if ( ! V_142 )
return - V_143 ;
V_142 -> V_144 = V_145 ;
V_142 -> V_146 = L_8 ;
V_142 -> V_147 = L_9 ;
V_142 -> V_148 = V_149 ;
V_142 -> type = V_150 ;
V_142 -> V_151 = V_152 ;
V_142 -> V_153 = V_154 ;
V_142 -> V_153 . V_30 =
V_155 | V_56 | V_156 | V_31 | V_73 ;
V_142 -> V_153 . V_157 = 9600 ;
V_142 -> V_153 . V_158 = 9600 ;
V_142 -> V_19 = V_159 ;
F_36 ( V_142 , & V_160 ) ;
if ( ( error = F_37 ( V_142 ) ) ) {
F_17 ( V_161 L_10 ,
error ) ;
F_38 ( V_142 ) ;
return 1 ;
}
return 0 ;
}
static int T_3 F_39 ( void )
{
struct V_162 * V_163 ;
unsigned int V_164 ;
int V_165 ;
short V_5 ;
T_2 * V_166 ;
volatile T_2 * V_167 ;
volatile struct V_1 * V_8 ;
int error , V_46 ;
#ifdef F_40
return - V_168 ;
#endif
if ( ! V_169 ) {
return - V_168 ;
}
F_17 ( L_11 ) ;
V_163 = NULL ;
V_107 = 0 ;
while ( ( V_163 = F_41 ( V_170 , V_163 ) ) ) {
if ( ( V_163 -> V_171 != V_172 ) &&
( V_163 -> V_171 != V_173 ) ) {
continue;
}
if ( ! F_42 ( V_163 , L_12 ) )
continue;
F_17 ( L_13 , V_107 ) ;
V_3 [ V_107 ] = V_163 ;
V_164 = F_2 ( V_163 -> V_4 . V_5 ) ;
F_17 ( L_14 , V_164 , ( unsigned int ) ( ( V_163 -> V_4 . V_174 + 1 ) - ( V_163 -> V_4 . V_5 ) ) ) ;
V_8 = ( volatile struct V_1 * ) V_164 ;
( void ) V_8 -> V_175 ;
V_167 = ( T_2 * ) V_8 ; V_166 = V_176 ; V_165 = sizeof( V_176 ) - 2 ;
V_5 = * ( short * ) V_166 ;
V_166 += sizeof( V_5 ) ;
V_167 += V_5 ;
while( V_165 -- ) * V_167 ++ = * V_166 ++ ;
F_17 ( L_15 ) ;
V_8 -> V_51 . V_52 = V_177 ;
( void ) V_8 -> V_178 ;
F_17 ( L_16 ) ;
for ( V_165 = 0 ; V_165 < 2000 ; V_165 ++ ) {
F_43 ( 1000 ) ;
if ( V_8 -> V_51 . V_52 )
break;
}
F_17 ( ( V_8 -> V_51 . V_52 ? L_17 : L_18 ) ) ;
switch ( V_8 -> V_51 . V_52 ) {
case V_177 :
F_17 ( L_19 ) ;
break;
case V_179 :
F_17 ( L_20 ) ;
break;
case V_53 :
F_17 ( L_21 ) ;
break;
default:
F_17 ( L_22 , V_8 -> V_51 . V_52 ) ;
}
V_107 ++ ;
}
F_17 ( L_23 , V_107 ) ;
F_32 () ;
if ( F_34 () ) return - V_168 ;
error = F_44 ( V_180 , F_28 , 0 ,
L_24 , V_181 ) ;
if ( error ) {
for ( V_46 = 0 ; V_46 < V_107 ; V_46 ++ )
F_45 ( V_3 [ V_46 ] ) ;
F_46 ( V_142 ) ;
F_38 ( V_142 ) ;
}
return error ;
}
static void T_4 F_47 ( void )
{
int V_46 ;
for ( V_46 = 0 ; V_46 < V_107 ; V_46 ++ ) {
F_45 ( V_3 [ V_46 ] ) ;
}
F_46 ( V_142 ) ;
F_38 ( V_142 ) ;
F_48 ( V_180 , V_181 ) ;
}
