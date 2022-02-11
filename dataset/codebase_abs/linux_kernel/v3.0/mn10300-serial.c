static void F_1 ( unsigned int V_1 )
{
unsigned long V_2 ;
T_1 V_3 ;
V_2 = F_2 () ;
F_3 ( V_1 ) = V_4 ;
V_3 = F_3 ( V_1 ) ;
F_4 ( V_2 ) ;
}
static void F_5 ( struct V_5 * V_6 )
{
F_1 ( V_6 -> V_1 ) ;
}
static void F_6 ( struct V_5 * V_6 )
{
}
static void F_7 ( struct V_7 * V_8 )
{
unsigned long V_2 ;
T_1 V_9 ;
V_2 = F_2 () ;
* V_8 -> V_10 = F_8 ( V_11 ) ;
V_9 = * V_8 -> V_10 ;
F_4 ( V_2 ) ;
}
static void F_9 ( struct V_7 * V_8 )
{
unsigned long V_2 ;
T_1 V_9 ;
V_2 = F_2 () ;
* V_8 -> V_10 =
F_8 ( V_11 ) | V_12 ;
V_9 = * V_8 -> V_10 ;
F_4 ( V_2 ) ;
}
static void F_10 ( struct V_7 * V_8 )
{
unsigned long V_2 ;
T_1 V_9 ;
V_2 = F_2 () ;
* V_8 -> V_13 = F_8 ( V_11 ) ;
V_9 = * V_8 -> V_13 ;
F_4 ( V_2 ) ;
}
static int F_11 ( volatile T_2 * V_14 , T_2 V_15 )
{
T_3 V_16 ;
asm volatile(" bclr %1,(%2) \n"
" mov epsw,%0 \n"
: "=d"(epsw) : "d"(mask), "a"(ptr)
: "cc", "memory");
return ! ( V_16 & V_17 ) ;
}
static void F_12 ( struct V_7 * V_8 )
{
struct V_18 * V_19 = & V_8 -> V_20 . V_19 ;
struct V_21 * V_22 = V_8 -> V_20 . V_23 -> V_8 . V_22 ;
unsigned V_24 ;
int V_25 ;
T_2 V_26 , V_27 , V_28 , V_29 , V_30 ;
F_13 ( L_1 , V_8 -> V_31 ) ;
V_28 = 0 ;
V_25 = F_14 ( V_8 -> V_32 , V_8 -> V_33 , V_34 ) ;
V_25 = F_15 ( V_22 , V_25 ) ;
if ( V_25 == 0 ) {
if ( ! V_22 -> V_35 )
F_16 ( V_22 ) ;
return;
}
V_36:
V_24 = V_8 -> V_33 ;
if ( V_24 == V_8 -> V_32 ) {
if ( V_28 && ! V_22 -> V_35 )
F_16 ( V_22 ) ;
return;
}
V_27 = V_8 -> V_37 [ V_24 ++ ] ;
V_26 = V_8 -> V_37 [ V_24 ++ ] ;
F_17 () ;
V_8 -> V_33 = V_24 & ( V_34 - 1 ) ;
V_8 -> V_20 . V_19 . V_38 ++ ;
V_26 &= V_39 | V_40 | V_41 ;
V_29 = 0 ;
V_30 = 0 ;
switch ( V_8 -> V_42 ) {
case 0 :
break;
case 1 :
if ( V_26 & V_39 && V_27 == 0 ) {
V_8 -> V_42 = 2 ;
goto V_36;
}
goto V_43;
case 2 :
if ( V_26 & V_39 && V_27 == 0 ) {
V_8 -> V_42 = 3 ;
F_18 ( L_2 ) ;
V_19 -> V_44 ++ ;
if ( F_19 ( & V_8 -> V_20 ) )
goto V_45;
V_29 |= 1 << V_46 ;
goto V_47;
}
goto V_43;
default:
if ( V_26 & ( V_39 | V_40 | V_41 ) )
goto V_36;
V_8 -> V_42 = 0 ;
switch ( V_27 ) {
case 0xFF :
case 0xFE :
case 0xFC :
case 0xF8 :
case 0xF0 :
case 0xE0 :
case 0xC0 :
case 0x80 :
case 0x00 :
goto V_36;
}
break;
}
V_48:
if ( V_26 & V_39 ) {
if ( V_27 == 0 ) {
V_8 -> V_42 = 1 ;
goto V_36;
}
F_18 ( L_3 ) ;
V_19 -> V_49 ++ ;
V_29 |= 1 << V_50 ;
}
if ( V_26 & V_40 ) {
F_18 ( L_4 ) ;
V_19 -> V_51 ++ ;
V_29 = V_52 ;
}
if ( V_29 == 0 ) {
if ( F_20 ( & V_8 -> V_20 , V_27 ) )
goto V_45;
V_29 = ( 1 << V_53 ) ;
}
if ( V_26 & V_41 ) {
if ( V_8 -> V_42 )
goto V_36;
F_18 ( L_5 ) ;
V_19 -> V_30 ++ ;
V_30 = 1 ;
}
V_47:
V_29 &= V_8 -> V_20 . V_54 ;
if ( ! V_30 && ! ( V_29 & V_8 -> V_20 . V_55 ) ) {
int V_56 ;
if ( V_29 & ( 1 << V_46 ) )
V_56 = V_46 ;
else if ( V_29 & ( 1 << V_52 ) )
V_56 = V_52 ;
else if ( V_29 & ( 1 << V_50 ) )
V_56 = V_50 ;
else
V_56 = V_53 ;
F_21 ( V_22 , V_27 , V_56 ) ;
}
if ( V_30 )
F_21 ( V_22 , 0 , V_57 ) ;
V_25 -- ;
if ( V_25 <= 0 ) {
if ( ! V_22 -> V_35 )
F_16 ( V_22 ) ;
return;
}
V_45:
V_28 = 1 ;
goto V_36;
V_43:
V_8 -> V_42 = 0 ;
goto V_48;
}
static void F_22 ( struct V_7 * V_8 )
{
F_13 ( L_1 , V_8 -> V_31 ) ;
if ( ! V_8 -> V_20 . V_23 || ! V_8 -> V_20 . V_23 -> V_8 . V_22 ) {
F_7 ( V_8 ) ;
return;
}
if ( F_23 ( & V_8 -> V_20 ) ||
F_24 ( & V_8 -> V_20 . V_23 -> V_58 ) )
F_7 ( V_8 ) ;
if ( F_25 ( & V_8 -> V_20 . V_23 -> V_58 ) < V_59 )
F_26 ( & V_8 -> V_20 ) ;
}
static void F_27 ( struct V_7 * V_8 , T_2 V_26 )
{
T_1 V_60 ;
V_8 -> V_61 = V_26 ;
V_8 -> V_20 . V_19 . V_62 ++ ;
V_60 = * V_8 -> V_63 ;
V_60 ^= V_64 ;
* V_8 -> V_63 = V_60 ;
F_28 ( & V_8 -> V_20 , V_26 & V_65 ) ;
F_29 ( & V_8 -> V_20 . V_23 -> V_8 . V_66 ) ;
}
static T_4 F_30 ( int V_1 , void * V_67 )
{
struct V_7 * V_8 = V_67 ;
T_2 V_26 ;
F_31 ( & V_8 -> V_20 . V_68 ) ;
if ( V_8 -> V_69 ) {
F_32 ( L_6 , V_8 -> V_31 , V_8 -> V_69 ) ;
if ( F_11 ( & V_8 -> V_69 , V_70 ) )
F_12 ( V_8 ) ;
if ( F_11 ( & V_8 -> V_69 ,
V_71 | V_72 ) )
F_22 ( V_8 ) ;
}
if ( V_8 -> type == V_73 ) {
V_26 = * V_8 -> V_74 ;
if ( ( V_8 -> V_61 ^ V_26 ) & V_65 )
F_27 ( V_8 , V_26 ) ;
}
F_33 ( & V_8 -> V_20 . V_68 ) ;
return V_75 ;
}
static unsigned int F_34 ( struct V_76 * V_77 )
{
struct V_7 * V_8 =
F_35 ( V_77 , struct V_7 , V_20 ) ;
F_13 ( L_1 , V_8 -> V_31 ) ;
return ( * V_8 -> V_74 & ( V_78 | V_79 ) ) ?
0 : V_80 ;
}
static void F_36 ( struct V_76 * V_77 ,
unsigned int V_81 )
{
struct V_7 * V_8 V_82 ( ( V_83 ) ) =
F_35 ( V_77 , struct V_7 , V_20 ) ;
F_13 ( L_7 , V_8 -> V_31 , V_81 ) ;
}
static unsigned int F_37 ( struct V_76 * V_77 )
{
struct V_7 * V_8 =
F_35 ( V_77 , struct V_7 , V_20 ) ;
F_13 ( L_1 , V_8 -> V_31 ) ;
if ( V_8 -> type == V_73 && ! ( * V_8 -> V_74 & V_65 ) )
return V_84 | V_85 ;
return V_84 | V_86 | V_85 ;
}
static void F_38 ( struct V_76 * V_77 )
{
struct V_7 * V_8 =
F_35 ( V_77 , struct V_7 , V_20 ) ;
F_13 ( L_1 , V_8 -> V_31 ) ;
F_7 ( V_8 ) ;
}
static void F_39 ( struct V_76 * V_77 )
{
struct V_7 * V_8 =
F_35 ( V_77 , struct V_7 , V_20 ) ;
T_1 V_9 ;
F_13 ( L_8 ,
V_8 -> V_31 ,
F_14 ( & V_8 -> V_20 . V_23 -> V_58 . V_87 ,
& V_8 -> V_20 . V_23 -> V_58 . V_88 ,
V_89 ) ) ;
F_40 () ;
V_9 = * V_8 -> V_10 ;
V_9 |= V_12 ;
if ( * V_8 -> V_74 & V_79 )
V_9 &= ~ ( V_90 | V_91 ) ;
else
V_9 |= V_90 | V_91 ;
F_32 ( L_9 ,
* V_8 -> V_63 , * V_8 -> V_92 , * V_8 -> V_74 ,
* V_8 -> V_93 ,
( V_8 -> V_94 == V_95 ) ?
* ( volatile T_2 * ) V_8 -> V_96 : * V_8 -> V_96 ,
* V_8 -> V_10 ) ;
* V_8 -> V_10 = V_9 ;
V_9 = * V_8 -> V_10 ;
F_41 () ;
}
static void F_42 ( struct V_76 * V_77 , char V_27 )
{
struct V_7 * V_8 =
F_35 ( V_77 , struct V_7 , V_20 ) ;
F_13 ( L_10 , V_8 -> V_31 , V_27 ) ;
if ( F_43 ( V_8 -> V_97 ) ) {
V_8 -> V_98 = V_27 ;
if ( V_27 )
F_9 ( V_8 ) ;
}
}
static void F_44 ( struct V_76 * V_77 )
{
struct V_7 * V_8 =
F_35 ( V_77 , struct V_7 , V_20 ) ;
T_1 V_60 ;
F_13 ( L_1 , V_8 -> V_31 ) ;
V_60 = * V_8 -> V_63 ;
V_60 &= ~ V_99 ;
* V_8 -> V_63 = V_60 ;
F_10 ( V_8 ) ;
}
static void F_45 ( struct V_76 * V_77 )
{
struct V_7 * V_8 =
F_35 ( V_77 , struct V_7 , V_20 ) ;
T_1 V_60 , V_62 ;
F_13 ( L_1 , V_8 -> V_31 ) ;
if ( V_8 -> type == V_73 ) {
V_8 -> V_61 = * V_8 -> V_74 ;
V_62 = ( V_8 -> V_61 & V_65 ) ?
V_100 : V_100 | V_64 ;
V_60 = * V_8 -> V_63 ;
V_60 &= ~ V_64 ;
V_60 |= V_62 ;
* V_8 -> V_63 = V_60 ;
F_9 ( V_8 ) ;
}
}
static void F_46 ( struct V_76 * V_77 , int V_101 )
{
struct V_7 * V_8 =
F_35 ( V_77 , struct V_7 , V_20 ) ;
F_13 ( L_11 , V_8 -> V_31 , V_101 ) ;
if ( V_101 ) {
V_8 -> V_102 = 1 ;
F_9 ( V_8 ) ;
} else {
V_8 -> V_102 = 0 ;
* V_8 -> V_63 &= ~ V_103 ;
F_9 ( V_8 ) ;
}
}
static int F_47 ( struct V_76 * V_77 )
{
struct V_7 * V_8 =
F_35 ( V_77 , struct V_7 , V_20 ) ;
struct V_104 * V_105 ;
F_13 ( L_12 , V_8 -> V_31 , V_8 -> V_97 ) ;
if ( F_48 ( V_8 -> V_97 ) )
return - V_106 ;
V_8 -> V_37 = F_49 ( V_34 , V_107 ) ;
if ( ! V_8 -> V_37 )
return - V_108 ;
V_8 -> V_32 = V_8 -> V_33 = 0 ;
* V_8 -> V_92 = V_109 ;
* V_8 -> V_63 |= V_110 | V_99 ;
V_105 = & V_111 [ V_8 -> V_112 ] ;
V_105 -> V_8 = V_8 ;
V_105 -> V_113 = V_114 ;
V_105 = & V_111 [ V_8 -> V_115 ] ;
V_105 -> V_8 = V_8 ;
V_105 -> V_113 = V_116 ;
F_50 ( V_8 -> V_112 ,
F_8 ( V_11 ) ) ;
F_50 ( V_8 -> V_115 ,
F_8 ( V_11 ) ) ;
F_51 ( V_8 -> V_117 , & V_118 ) ;
if ( F_52 ( V_8 -> V_112 , F_30 ,
V_119 , V_8 -> V_120 , V_8 ) < 0 )
goto error;
if ( F_52 ( V_8 -> V_115 , F_30 ,
V_119 , V_8 -> V_121 , V_8 ) < 0 )
goto V_122;
if ( F_52 ( V_8 -> V_117 , F_30 ,
V_119 , V_8 -> V_123 , V_8 ) < 0 )
goto V_124;
F_1 ( V_8 -> V_117 ) ;
return 0 ;
V_124:
F_53 ( V_8 -> V_115 , V_8 ) ;
V_122:
F_53 ( V_8 -> V_112 , V_8 ) ;
error:
F_54 ( V_8 -> V_37 ) ;
V_8 -> V_37 = NULL ;
return - V_106 ;
}
static void F_55 ( struct V_76 * V_77 )
{
T_1 V_9 ;
struct V_7 * V_8 =
F_35 ( V_77 , struct V_7 , V_20 ) ;
F_13 ( L_1 , V_8 -> V_31 ) ;
V_8 -> V_102 = 0 ;
* V_8 -> V_63 &= ~ ( V_110 | V_99 | V_103 ) ;
* V_8 -> V_93 = 0 ;
if ( V_8 -> V_37 ) {
void * V_125 = V_8 -> V_37 ;
V_8 -> V_37 = NULL ;
F_54 ( V_125 ) ;
}
F_53 ( V_8 -> V_117 , V_8 ) ;
F_53 ( V_8 -> V_112 , V_8 ) ;
F_53 ( V_8 -> V_115 , V_8 ) ;
F_40 () ;
* V_8 -> V_13 = F_8 ( V_11 ) ;
V_9 = * V_8 -> V_13 ;
* V_8 -> V_10 = F_8 ( V_11 ) ;
V_9 = * V_8 -> V_10 ;
F_41 () ;
}
static void F_56 ( struct V_7 * V_8 ,
struct V_126 * V_127 ,
struct V_126 * V_128 )
{
unsigned long V_2 ;
unsigned long V_129 = V_8 -> V_129 ;
unsigned V_130 ;
int V_131 , V_132 , V_133 , V_3 ;
T_1 V_134 , V_135 ;
T_2 V_136 , V_137 ;
T_2 V_94 = V_8 -> V_94 ;
F_13 ( L_8 , V_8 -> V_31 , V_129 ) ;
V_130 = V_127 -> V_138 ;
switch ( V_130 & V_139 ) {
case V_140 : V_135 = V_141 ; V_132 = 9 ; break;
case V_142 : V_135 = V_143 ; V_132 = 10 ; break;
default: V_135 = V_143 ; V_132 = 10 ; break;
}
if ( V_130 & V_144 ) {
V_135 |= V_145 ;
V_132 ++ ;
}
if ( V_130 & V_146 ) {
V_132 ++ ;
if ( V_130 & V_147 )
V_135 |= V_148 ;
#ifdef F_57
else if ( V_130 & F_57 )
V_135 |= V_149 ;
#endif
else
V_135 |= V_150 ;
}
V_137 = 0 ;
switch ( V_8 -> V_20 . line ) {
#ifdef F_58
case 0 :
#if F_59 ( V_151 )
V_135 |= V_152 ;
#elif F_59 ( V_153 )
V_135 |= V_154 ;
#elif F_59 ( V_155 )
V_135 |= V_156 ;
#else
#error "Unknown config for ttySM0"
#endif
break;
#endif
#ifdef F_60
case 1 :
#if F_59 ( V_157 ) || F_59 ( V_158 )
#if F_59 ( V_159 )
V_135 |= V_160 ;
#elif F_59 ( V_161 )
V_135 |= V_162 ;
#else
#error "Unknown config for ttySM1"
#endif
#else
#if F_59 ( V_163 )
V_135 |= V_164 ;
#else
#error "Unknown config for ttySM1"
#endif
#endif
break;
#endif
#ifdef F_61
case 2 :
#if F_59 ( V_157 )
#if F_59 ( V_165 )
V_135 |= V_166 ;
#else
#error "Unknown config for ttySM2"
#endif
#else
#if F_59 ( V_167 )
V_135 |= V_168 ;
#elif F_59 ( V_169 )
V_135 |= V_170 ;
#elif F_59 ( V_171 )
V_135 |= V_172 ;
#else
#error "Unknown config for ttySM2"
#endif
#endif
break;
#endif
default:
break;
}
V_173:
V_131 = F_62 ( & V_8 -> V_20 , V_127 , V_128 , 0 ,
V_8 -> V_129 / 8 ) ;
F_32 ( L_13 , V_137 , V_131 ) ;
if ( ! V_131 )
V_131 = 9600 ;
V_133 = 1 ;
if ( V_131 == 134 ) {
V_131 = 269 ;
V_133 = 2 ;
}
if ( V_131 == 38400 &&
( V_8 -> V_20 . V_2 & V_174 ) == V_175
) {
F_32 ( L_14 , V_8 -> V_20 . V_176 ) ;
if ( V_94 == V_177 ) {
if ( V_8 -> V_20 . V_176 <= 65535 ) {
V_136 = V_178 ;
V_134 = V_8 -> V_20 . V_176 ;
V_8 -> V_20 . V_179 = V_129 ;
goto V_180;
}
if ( V_8 -> V_20 . V_176 / 8 <= 65535 ) {
V_136 = V_181 ;
V_134 = V_8 -> V_20 . V_176 / 8 ;
V_8 -> V_20 . V_176 = V_134 * 8 ;
V_8 -> V_20 . V_179 = V_129 / 8 ;
goto V_180;
}
if ( V_8 -> V_20 . V_176 / 32 <= 65535 ) {
V_136 = V_182 ;
V_134 = V_8 -> V_20 . V_176 / 32 ;
V_8 -> V_20 . V_176 = V_134 * 32 ;
V_8 -> V_20 . V_179 = V_129 / 32 ;
goto V_180;
}
} else if ( V_94 == V_95 ) {
if ( V_8 -> V_20 . V_176 <= 255 ) {
V_136 = V_183 ;
V_134 = V_8 -> V_20 . V_176 ;
V_8 -> V_20 . V_179 = V_129 ;
goto V_180;
}
if ( V_8 -> V_20 . V_176 / 8 <= 255 ) {
V_136 = V_184 ;
V_134 = V_8 -> V_20 . V_176 / 8 ;
V_8 -> V_20 . V_176 = V_134 * 8 ;
V_8 -> V_20 . V_179 = V_129 / 8 ;
goto V_180;
}
if ( V_8 -> V_20 . V_176 / 32 <= 255 ) {
V_136 = V_185 ;
V_134 = V_8 -> V_20 . V_176 / 32 ;
V_8 -> V_20 . V_176 = V_134 * 32 ;
V_8 -> V_20 . V_179 = V_129 / 32 ;
goto V_180;
}
}
}
switch ( V_94 ) {
case V_177 :
V_8 -> V_20 . V_179 = V_129 ;
V_136 = V_178 ;
V_134 = V_3 = ( V_129 / ( V_131 * V_133 ) + 4 ) / 8 - 1 ;
if ( V_3 > 0 && V_3 <= 65535 )
goto V_180;
V_8 -> V_20 . V_179 = V_129 / 8 ;
V_136 = V_181 ;
V_134 = V_3 = ( V_129 / ( V_131 * 8 * V_133 ) + 4 ) / 8 - 1 ;
if ( V_3 > 0 && V_3 <= 65535 )
goto V_180;
V_8 -> V_20 . V_179 = V_129 / 32 ;
V_136 = V_182 ;
V_134 = V_3 = ( V_129 / ( V_131 * 32 * V_133 ) + 4 ) / 8 - 1 ;
if ( V_3 > 0 && V_3 <= 65535 )
goto V_180;
break;
case V_95 :
V_8 -> V_20 . V_179 = V_129 ;
V_136 = V_183 ;
V_134 = V_3 = ( V_129 / ( V_131 * V_133 ) + 4 ) / 8 - 1 ;
if ( V_3 > 0 && V_3 <= 255 )
goto V_180;
V_8 -> V_20 . V_179 = V_129 / 8 ;
V_136 = V_184 ;
V_134 = V_3 = ( V_129 / ( V_131 * 8 * V_133 ) + 4 ) / 8 - 1 ;
if ( V_3 > 0 && V_3 <= 255 )
goto V_180;
V_8 -> V_20 . V_179 = V_129 / 32 ;
V_136 = V_185 ;
V_134 = V_3 = ( V_129 / ( V_131 * 32 * V_133 ) + 4 ) / 8 - 1 ;
if ( V_3 > 0 && V_3 <= 255 )
goto V_180;
break;
default:
F_63 () ;
return;
}
F_32 ( L_15 ) ;
switch ( V_137 ) {
case 0 :
if ( V_128 ) {
V_127 -> V_138 &= ~ V_186 ;
V_127 -> V_138 |= ( V_128 -> V_138 & V_186 ) ;
V_137 = 1 ;
goto V_173;
}
case 1 :
V_127 -> V_138 &= ~ V_186 ;
V_127 -> V_138 |= V_187 ;
V_137 = 2 ;
goto V_173;
default:
V_127 -> V_138 &= ~ V_186 ;
V_127 -> V_138 |= V_188 ;
if ( V_94 == V_177 )
V_136 = V_182 ;
else if ( V_94 == V_95 )
V_136 = V_185 ;
V_134 = 1 ;
V_8 -> V_20 . V_179 = V_129 / 32 ;
break;
}
V_180:
F_32 ( L_16 , V_8 -> V_20 . V_179 , V_134 ) ;
F_64 ( & V_8 -> V_20 . V_68 , V_2 ) ;
F_65 ( & V_8 -> V_20 , V_127 -> V_138 , V_131 ) ;
switch ( V_94 ) {
case V_177 :
* V_8 -> V_93 = 0 ;
* V_8 -> V_96 = V_134 ;
* V_8 -> V_93 = V_189 ;
* V_8 -> V_93 = V_136 | V_190 ;
break;
case V_95 :
* V_8 -> V_93 = 0 ;
* ( volatile T_2 * ) V_8 -> V_96 = ( T_2 ) V_134 ;
* V_8 -> V_93 = V_191 ;
* V_8 -> V_93 = V_136 | V_192 ;
break;
}
V_135 &= ~ ( V_100 | V_64 ) ;
if ( V_8 -> type == V_73 && V_130 & V_193 ) {
V_8 -> V_61 = * V_8 -> V_74 ;
if ( V_8 -> V_61 & V_65 )
V_135 |= V_100 ;
else
V_135 |= V_100 | V_64 ;
}
V_8 -> V_20 . V_54 = ( 1 << V_53 ) | ( 1 << V_57 ) ;
if ( V_127 -> V_194 & V_195 )
V_8 -> V_20 . V_54 |=
( 1 << V_52 ) | ( 1 << V_50 ) ;
if ( V_127 -> V_194 & ( V_196 | V_197 ) )
V_8 -> V_20 . V_54 |= ( 1 << V_46 ) ;
V_8 -> V_20 . V_55 = 0 ;
if ( V_127 -> V_194 & V_198 )
V_8 -> V_20 . V_55 |=
( 1 << V_52 ) | ( 1 << V_50 ) ;
if ( V_127 -> V_194 & V_199 ) {
V_8 -> V_20 . V_55 |= ( 1 << V_46 ) ;
if ( V_127 -> V_194 & V_198 )
V_8 -> V_20 . V_55 |= ( 1 << V_57 ) ;
}
if ( ( V_127 -> V_138 & V_200 ) == 0 )
V_8 -> V_20 . V_55 |= ( 1 << V_53 ) ;
V_135 |= * V_8 -> V_63 & ( V_110 | V_99 | V_103 ) ;
* V_8 -> V_63 = V_135 ;
F_66 ( & V_8 -> V_20 . V_68 , V_2 ) ;
}
static void F_67 ( struct V_76 * V_77 ,
struct V_126 * V_127 ,
struct V_126 * V_128 )
{
struct V_7 * V_8 =
F_35 ( V_77 , struct V_7 , V_20 ) ;
F_13 ( L_17 , V_8 -> V_31 , V_127 , V_128 ) ;
F_56 ( V_8 , V_127 , V_128 ) ;
if ( ! ( V_127 -> V_138 & V_193 ) ) {
T_1 V_60 = * V_8 -> V_63 ;
V_60 &= ~ V_100 ;
* V_8 -> V_63 = V_60 ;
}
if ( V_127 -> V_138 & V_201 )
* V_8 -> V_63 |= V_202 ;
else
* V_8 -> V_63 &= ~ V_202 ;
}
static const char * F_68 ( struct V_76 * V_77 )
{
struct V_7 * V_8 =
F_35 ( V_77 , struct V_7 , V_20 ) ;
if ( V_8 -> V_20 . type == V_73 )
return L_18 ;
return L_19 ;
}
static void F_69 ( struct V_76 * V_77 )
{
struct V_7 * V_8 =
F_35 ( V_77 , struct V_7 , V_20 ) ;
F_13 ( L_1 , V_8 -> V_31 ) ;
F_70 ( ( unsigned long ) V_8 -> V_203 , 16 ) ;
}
static int F_71 ( struct V_76 * V_77 )
{
struct V_7 * V_8 =
F_35 ( V_77 , struct V_7 , V_20 ) ;
F_13 ( L_1 , V_8 -> V_31 ) ;
F_72 ( ( unsigned long ) V_8 -> V_203 , 16 , V_8 -> V_31 ) ;
return 0 ;
}
static void F_73 ( struct V_76 * V_77 , int type )
{
struct V_7 * V_8 =
F_35 ( V_77 , struct V_7 , V_20 ) ;
F_13 ( L_1 , V_8 -> V_31 ) ;
V_8 -> V_20 . type = V_204 ;
if ( V_8 -> V_205 & V_206 )
V_8 -> V_20 . type = V_73 ;
F_71 ( V_77 ) ;
}
static int F_74 ( struct V_76 * V_77 ,
struct V_207 * V_208 )
{
struct V_7 * V_8 =
F_35 ( V_77 , struct V_7 , V_20 ) ;
void * V_209 = ( void * ) ( unsigned long ) V_8 -> V_20 . V_209 ;
F_13 ( L_1 , V_8 -> V_31 ) ;
if ( V_208 -> V_1 != V_8 -> V_20 . V_1 ||
V_208 -> V_8 != V_8 -> V_20 . V_210 ||
V_208 -> V_211 != V_8 -> V_20 . V_212 ||
V_208 -> V_213 != V_209 ||
V_208 -> V_214 != V_8 -> V_20 . V_215 ||
V_208 -> V_216 != V_8 -> V_20 . V_216 ||
V_208 -> V_217 != V_8 -> V_20 . V_218 )
return - V_219 ;
if ( V_208 -> type != V_8 -> V_20 . type ) {
if ( ! ( V_8 -> V_205 & V_206 ) )
return - V_219 ;
if ( V_208 -> type != V_204 &&
V_208 -> type != V_73 )
return - V_219 ;
}
return 0 ;
}
static int T_5 F_75 ( void )
{
struct V_7 * V_8 ;
int V_220 , V_221 ;
F_76 ( V_222 L_20 ,
V_223 , V_224 , V_225 ) ;
#if F_59 ( F_61 ) && F_59 ( V_157 )
{
int V_3 ;
V_226 = 8 ;
V_3 = V_226 ;
}
#endif
F_77 ( F_78 ( V_11 ) ,
V_227 ) ;
V_220 = F_79 ( & V_228 ) ;
if ( ! V_220 ) {
for ( V_221 = 0 ; V_221 < V_229 ; V_221 ++ ) {
V_8 = V_230 [ V_221 ] ;
if ( ! V_8 || V_8 -> V_97 )
continue;
switch ( V_8 -> V_231 ) {
case V_232 :
V_8 -> V_129 = V_233 ;
break;
#ifdef F_80
case V_234 :
V_8 -> V_129 = F_80 ;
break;
#endif
default:
F_63 () ;
}
V_220 = F_81 ( & V_228 ,
& V_8 -> V_20 ) ;
if ( V_220 < 0 ) {
F_32 ( L_21 , - V_220 ) ;
break;
}
}
if ( V_220 )
F_82 ( & V_228 ) ;
}
return V_220 ;
}
static void F_83 ( struct V_235 * V_236 ,
const char * V_237 , unsigned V_25 )
{
struct V_7 * V_8 ;
unsigned V_221 ;
T_1 V_135 , V_238 , V_3 ;
T_2 V_136 ;
V_8 = V_230 [ V_236 -> V_239 ] ;
F_40 () ;
V_238 = * V_8 -> V_10 ;
* V_8 -> V_10 = F_8 ( V_11 ) ;
V_3 = * V_8 -> V_10 ;
F_41 () ;
V_135 = * V_8 -> V_63 ;
if ( ! ( V_135 & V_110 ) ) {
V_136 = * V_8 -> V_93 ;
switch ( V_8 -> V_94 ) {
case V_177 :
* V_8 -> V_93 = 0 ;
* V_8 -> V_93 = V_189 ;
* V_8 -> V_93 = V_136 | V_190 ;
break;
case V_95 :
* V_8 -> V_93 = 0 ;
* V_8 -> V_93 = V_191 ;
* V_8 -> V_93 = V_136 | V_192 ;
break;
}
* V_8 -> V_63 = ( V_135 & ~ V_103 ) | V_110 ;
} else if ( V_135 & V_103 ) {
* V_8 -> V_63 = ( V_135 & ~ V_103 ) ;
}
for ( V_221 = 0 ; V_221 < V_25 ; V_221 ++ ) {
char V_27 = * V_237 ++ ;
while ( * V_8 -> V_74 & V_79 )
continue;
* ( T_2 * ) V_8 -> V_240 = V_27 ;
if ( V_27 == 0x0a ) {
while ( * V_8 -> V_74 & V_79 )
continue;
* ( T_2 * ) V_8 -> V_240 = 0xd ;
}
}
while ( * V_8 -> V_74 & ( V_78 | V_79 ) )
continue;
if ( ! ( V_135 & V_110 ) )
* V_8 -> V_63 = V_135 ;
F_40 () ;
* V_8 -> V_10 = V_238 ;
V_3 = * V_8 -> V_10 ;
F_41 () ;
}
static int T_5 F_84 ( struct V_235 * V_236 ,
char * V_205 )
{
struct V_7 * V_8 ;
int V_221 , V_51 = 'n' , V_131 = 9600 , V_132 = 8 , V_241 = 0 ;
for ( V_221 = 0 ; V_221 < V_229 ; V_221 ++ ) {
V_8 = V_230 [ V_221 ] ;
if ( V_8 && ! V_8 -> V_97 && V_8 -> V_20 . line == V_236 -> V_239 )
goto V_242;
}
return - V_243 ;
V_242:
switch ( V_8 -> V_231 ) {
case V_232 :
V_8 -> V_129 = V_233 ;
break;
#ifdef F_80
case V_234 :
V_8 -> V_129 = F_80 ;
break;
#endif
default:
F_63 () ;
}
if ( V_205 )
F_85 ( V_205 , & V_131 , & V_51 , & V_132 , & V_241 ) ;
return F_86 ( & V_8 -> V_20 , V_236 , V_131 , V_51 , V_132 , V_241 ) ;
}
static int T_5 F_87 ( void )
{
F_88 ( & V_244 ) ;
return 0 ;
}
static int F_89 ( struct V_76 * V_77 )
{
struct V_7 * V_8 =
F_35 ( V_77 , struct V_7 , V_20 ) ;
unsigned V_24 ;
T_2 V_26 , V_27 ;
F_13 ( L_1 , V_8 -> V_31 ) ;
do {
V_24 = V_8 -> V_33 ;
if ( V_24 == V_8 -> V_32 )
return V_245 ;
V_27 = V_8 -> V_37 [ V_24 ++ ] ;
V_26 = V_8 -> V_37 [ V_24 ++ ] ;
F_17 () ;
V_8 -> V_33 = V_24 & ( V_34 - 1 ) ;
} while ( V_26 & ( V_39 | V_40 | V_41 ) );
return V_27 ;
}
static void F_90 ( struct V_76 * V_77 ,
unsigned char V_27 )
{
struct V_7 * V_8 =
F_35 ( V_77 , struct V_7 , V_20 ) ;
T_2 V_246 , V_3 ;
while ( * V_8 -> V_74 & ( V_79 | V_78 ) )
continue;
V_246 = * V_8 -> V_92 ;
* V_8 -> V_92 = V_246 & ~ V_109 ;
V_3 = * V_8 -> V_92 ;
if ( V_27 == 0x0a ) {
* ( T_2 * ) V_8 -> V_240 = 0x0d ;
while ( * V_8 -> V_74 & V_79 )
continue;
}
* ( T_2 * ) V_8 -> V_240 = V_27 ;
while ( * V_8 -> V_74 & V_79 )
continue;
* V_8 -> V_92 = V_246 ;
V_3 = * V_8 -> V_92 ;
}
