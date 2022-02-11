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
static void F_7 ( struct V_5 * V_6 )
{
unsigned long V_2 ;
T_1 V_3 ;
V_2 = F_2 () ;
F_3 ( V_6 -> V_1 ) = F_8 ( V_7 ) ;
V_3 = F_3 ( V_6 -> V_1 ) ;
F_4 ( V_2 ) ;
}
static void F_9 ( struct V_5 * V_6 )
{
unsigned long V_2 ;
T_1 V_3 ;
V_2 = F_2 () ;
F_3 ( V_6 -> V_1 ) =
F_8 ( V_7 ) | V_8 ;
V_3 = F_3 ( V_6 -> V_1 ) ;
F_4 ( V_2 ) ;
}
static void F_10 ( struct V_9 * V_10 )
{
int V_11 = 100 ;
T_1 V_12 ;
if ( ! V_13 [ V_10 -> V_14 ] . V_10 )
return;
V_10 -> V_15 |= V_16 ;
F_11 () ;
while ( ( * V_10 -> V_17 & V_8 ) && V_11 -- > 0 )
;
if ( V_11 <= 0 ) {
* V_10 -> V_17 =
F_8 ( V_7 ) ;
V_12 = * V_10 -> V_17 ;
}
}
static void F_12 ( struct V_9 * V_10 )
{
T_1 V_12 ;
if ( ! V_13 [ V_10 -> V_14 ] . V_10 )
return;
if ( ! ( V_10 -> V_15 & V_16 ) )
F_10 ( V_10 ) ;
V_10 -> V_15 &= ~ V_16 ;
F_11 () ;
* V_10 -> V_17 =
F_8 ( V_7 ) |
V_8 | V_18 | V_19 ;
V_12 = * V_10 -> V_17 ;
}
static void F_13 ( struct V_9 * V_10 )
{
unsigned long V_2 ;
T_1 V_12 ;
V_2 = F_2 () ;
* V_10 -> V_20 = F_8 ( V_7 ) ;
V_12 = * V_10 -> V_20 ;
F_4 ( V_2 ) ;
}
static int F_14 ( volatile T_2 * V_21 , T_2 V_22 )
{
T_3 V_23 ;
asm volatile(" bclr %1,(%2) \n"
" mov epsw,%0 \n"
: "=d"(epsw) : "d"(mask), "a"(ptr)
: "cc", "memory");
return ! ( V_23 & V_24 ) ;
}
static void F_15 ( struct V_9 * V_10 )
{
struct V_25 * V_26 = & V_10 -> V_27 . V_26 ;
struct V_28 * V_29 = & V_10 -> V_27 . V_30 -> V_10 ;
unsigned V_31 ;
int V_32 ;
T_2 V_33 , V_34 , V_35 , V_36 , V_37 ;
F_16 ( L_1 , V_10 -> V_38 ) ;
V_35 = 0 ;
V_32 = F_17 ( V_10 -> V_39 , V_10 -> V_40 , V_41 ) ;
V_32 = F_18 ( V_29 , V_32 ) ;
if ( V_32 == 0 ) {
if ( ! V_29 -> V_42 )
F_19 ( V_29 ) ;
return;
}
V_43:
V_31 = F_20 ( V_10 -> V_40 ) ;
if ( F_17 ( V_10 -> V_39 , V_31 , V_41 ) == 0 ) {
if ( V_35 && ! V_29 -> V_42 )
F_19 ( V_29 ) ;
return;
}
F_21 () ;
V_34 = V_10 -> V_44 [ V_31 ++ ] ;
V_33 = V_10 -> V_44 [ V_31 ++ ] ;
F_22 () ;
V_10 -> V_40 = V_31 & ( V_41 - 1 ) ;
V_10 -> V_27 . V_26 . V_45 ++ ;
V_33 &= V_46 | V_47 | V_48 ;
V_36 = 0 ;
V_37 = 0 ;
switch ( V_10 -> V_49 ) {
case 0 :
break;
case 1 :
if ( V_33 & V_46 && V_34 == 0 ) {
V_10 -> V_49 = 2 ;
goto V_43;
}
goto V_50;
case 2 :
if ( V_33 & V_46 && V_34 == 0 ) {
V_10 -> V_49 = 3 ;
F_23 ( L_2 ) ;
V_26 -> V_51 ++ ;
if ( F_24 ( & V_10 -> V_27 ) )
goto V_52;
V_36 |= 1 << V_53 ;
goto V_54;
}
goto V_50;
default:
if ( V_33 & ( V_46 | V_47 | V_48 ) )
goto V_43;
V_10 -> V_49 = 0 ;
switch ( V_34 ) {
case 0xFF :
case 0xFE :
case 0xFC :
case 0xF8 :
case 0xF0 :
case 0xE0 :
case 0xC0 :
case 0x80 :
case 0x00 :
goto V_43;
}
break;
}
V_55:
if ( V_33 & V_46 ) {
if ( V_34 == 0 ) {
V_10 -> V_49 = 1 ;
goto V_43;
}
F_23 ( L_3 ) ;
V_26 -> V_56 ++ ;
V_36 |= 1 << V_57 ;
}
if ( V_33 & V_47 ) {
F_23 ( L_4 ) ;
V_26 -> V_58 ++ ;
V_36 = V_59 ;
}
if ( V_36 == 0 ) {
if ( F_25 ( & V_10 -> V_27 , V_34 ) )
goto V_52;
V_36 = ( 1 << V_60 ) ;
}
if ( V_33 & V_48 ) {
if ( V_10 -> V_49 )
goto V_43;
F_23 ( L_5 ) ;
V_26 -> V_37 ++ ;
V_37 = 1 ;
}
V_54:
V_36 &= V_10 -> V_27 . V_61 ;
if ( ! V_37 && ! ( V_36 & V_10 -> V_27 . V_62 ) ) {
int V_63 ;
if ( V_36 & ( 1 << V_53 ) )
V_63 = V_53 ;
else if ( V_36 & ( 1 << V_59 ) )
V_63 = V_59 ;
else if ( V_36 & ( 1 << V_57 ) )
V_63 = V_57 ;
else
V_63 = V_60 ;
F_26 ( V_29 , V_34 , V_63 ) ;
}
if ( V_37 )
F_26 ( V_29 , 0 , V_64 ) ;
V_32 -- ;
if ( V_32 <= 0 ) {
if ( ! V_29 -> V_42 )
F_19 ( V_29 ) ;
return;
}
V_52:
V_35 = 1 ;
goto V_43;
V_50:
V_10 -> V_49 = 0 ;
goto V_55;
}
static void F_27 ( struct V_9 * V_10 )
{
F_16 ( L_1 , V_10 -> V_38 ) ;
if ( ! V_10 -> V_27 . V_30 || ! V_10 -> V_27 . V_30 -> V_10 . V_65 ) {
F_10 ( V_10 ) ;
return;
}
if ( F_28 ( & V_10 -> V_27 ) ||
F_29 ( & V_10 -> V_27 . V_30 -> V_66 ) )
F_10 ( V_10 ) ;
if ( F_30 ( & V_10 -> V_27 . V_30 -> V_66 ) < V_67 )
F_31 ( & V_10 -> V_27 ) ;
}
static void F_32 ( struct V_9 * V_10 , T_2 V_33 )
{
T_1 V_68 ;
V_10 -> V_69 = V_33 ;
V_10 -> V_27 . V_26 . V_70 ++ ;
V_68 = * V_10 -> V_71 ;
V_68 ^= V_72 ;
* V_10 -> V_71 = V_68 ;
F_33 ( & V_10 -> V_27 , V_33 & V_73 ) ;
F_34 ( & V_10 -> V_27 . V_30 -> V_10 . V_74 ) ;
}
static T_4 F_35 ( int V_1 , void * V_75 )
{
struct V_9 * V_10 = V_75 ;
T_2 V_33 ;
F_36 ( & V_10 -> V_27 . V_76 ) ;
if ( V_10 -> V_77 ) {
F_37 ( L_6 , V_10 -> V_38 , V_10 -> V_77 ) ;
if ( F_14 ( & V_10 -> V_77 , V_78 ) )
F_15 ( V_10 ) ;
if ( F_14 ( & V_10 -> V_77 ,
V_79 | V_80 ) )
F_27 ( V_10 ) ;
}
if ( V_10 -> type == V_81 ) {
V_33 = * V_10 -> V_82 ;
if ( ( V_10 -> V_69 ^ V_33 ) & V_73 )
F_32 ( V_10 , V_33 ) ;
}
F_38 ( & V_10 -> V_27 . V_76 ) ;
return V_83 ;
}
static unsigned int F_39 ( struct V_84 * V_85 )
{
struct V_9 * V_10 =
F_40 ( V_85 , struct V_9 , V_27 ) ;
F_16 ( L_1 , V_10 -> V_38 ) ;
return ( * V_10 -> V_82 & ( V_86 | V_87 ) ) ?
0 : V_88 ;
}
static void F_41 ( struct V_84 * V_85 ,
unsigned int V_89 )
{
struct V_9 * V_10 V_90 ( ( V_91 ) ) =
F_40 ( V_85 , struct V_9 , V_27 ) ;
F_16 ( L_7 , V_10 -> V_38 , V_89 ) ;
}
static unsigned int F_42 ( struct V_84 * V_85 )
{
struct V_9 * V_10 =
F_40 ( V_85 , struct V_9 , V_27 ) ;
F_16 ( L_1 , V_10 -> V_38 ) ;
if ( V_10 -> type == V_81 && ! ( * V_10 -> V_82 & V_73 ) )
return V_92 | V_93 ;
return V_92 | V_94 | V_93 ;
}
static void F_43 ( struct V_84 * V_85 )
{
struct V_9 * V_10 =
F_40 ( V_85 , struct V_9 , V_27 ) ;
F_16 ( L_1 , V_10 -> V_38 ) ;
F_10 ( V_10 ) ;
}
static void F_44 ( struct V_84 * V_85 )
{
struct V_9 * V_10 =
F_40 ( V_85 , struct V_9 , V_27 ) ;
F_16 ( L_8 ,
V_10 -> V_38 ,
F_17 ( & V_10 -> V_27 . V_30 -> V_66 . V_95 ,
& V_10 -> V_27 . V_30 -> V_66 . V_96 ,
V_97 ) ) ;
F_12 ( V_10 ) ;
F_37 ( L_9 ,
* V_10 -> V_71 , * V_10 -> V_98 , * V_10 -> V_82 ,
* V_10 -> V_99 ,
( V_10 -> V_100 == V_101 ) ?
* ( volatile T_2 * ) V_10 -> V_102 : * V_10 -> V_102 ,
* V_10 -> V_17 ) ;
}
static void F_45 ( struct V_84 * V_85 , char V_34 )
{
struct V_9 * V_10 =
F_40 ( V_85 , struct V_9 , V_27 ) ;
unsigned long V_2 ;
F_16 ( L_10 , V_10 -> V_38 , V_34 ) ;
if ( F_46 ( V_10 -> V_103 ) ) {
V_10 -> V_104 = V_34 ;
if ( V_34 ) {
F_47 ( & V_10 -> V_27 . V_76 , V_2 ) ;
F_12 ( V_10 ) ;
F_48 ( & V_10 -> V_27 . V_76 , V_2 ) ;
}
}
}
static void F_49 ( struct V_84 * V_85 )
{
struct V_9 * V_10 =
F_40 ( V_85 , struct V_9 , V_27 ) ;
T_1 V_68 ;
F_16 ( L_1 , V_10 -> V_38 ) ;
V_68 = * V_10 -> V_71 ;
V_68 &= ~ V_105 ;
* V_10 -> V_71 = V_68 ;
F_13 ( V_10 ) ;
}
static void F_50 ( struct V_84 * V_85 )
{
struct V_9 * V_10 =
F_40 ( V_85 , struct V_9 , V_27 ) ;
T_1 V_68 , V_70 ;
F_16 ( L_1 , V_10 -> V_38 ) ;
if ( V_10 -> type == V_81 ) {
V_10 -> V_69 = * V_10 -> V_82 ;
V_70 = ( V_10 -> V_69 & V_73 ) ?
V_106 : V_106 | V_72 ;
V_68 = * V_10 -> V_71 ;
V_68 &= ~ V_72 ;
V_68 |= V_70 ;
* V_10 -> V_71 = V_68 ;
F_12 ( V_10 ) ;
}
}
static void F_51 ( struct V_84 * V_85 , int V_107 )
{
struct V_9 * V_10 =
F_40 ( V_85 , struct V_9 , V_27 ) ;
unsigned long V_2 ;
F_16 ( L_11 , V_10 -> V_38 , V_107 ) ;
F_47 ( & V_10 -> V_27 . V_76 , V_2 ) ;
if ( V_107 ) {
V_10 -> V_15 |= V_108 ;
F_12 ( V_10 ) ;
} else {
V_10 -> V_15 &= ~ V_108 ;
* V_10 -> V_71 &= ~ V_109 ;
F_12 ( V_10 ) ;
}
F_48 ( & V_10 -> V_27 . V_76 , V_2 ) ;
}
static int F_52 ( struct V_84 * V_85 )
{
struct V_9 * V_10 =
F_40 ( V_85 , struct V_9 , V_27 ) ;
struct V_110 * V_111 ;
F_16 ( L_12 , V_10 -> V_38 , V_10 -> V_103 ) ;
if ( F_53 ( V_10 -> V_103 ) )
return - V_112 ;
V_10 -> V_44 = F_54 ( V_41 , V_113 ) ;
if ( ! V_10 -> V_44 )
return - V_114 ;
V_10 -> V_39 = V_10 -> V_40 = 0 ;
V_10 -> V_15 = 0 ;
* V_10 -> V_98 = V_115 ;
* V_10 -> V_71 |= V_116 | V_105 ;
V_111 = & V_13 [ V_10 -> V_117 ] ;
V_111 -> V_10 = V_10 ;
V_111 -> V_118 = V_119 ;
V_111 = & V_13 [ V_10 -> V_14 ] ;
V_111 -> V_10 = V_10 ;
V_111 -> V_118 = V_120 ;
F_55 ( V_10 -> V_117 , & V_121 ) ;
F_55 ( V_10 -> V_14 , & V_121 ) ;
F_55 ( V_10 -> V_122 , & V_123 ) ;
if ( F_56 ( V_10 -> V_117 , F_35 ,
V_124 | V_125 ,
V_10 -> V_126 , V_10 ) < 0 )
goto error;
if ( F_56 ( V_10 -> V_14 , F_35 ,
V_124 | V_125 ,
V_10 -> V_127 , V_10 ) < 0 )
goto V_128;
if ( F_56 ( V_10 -> V_122 , F_35 ,
V_124 | V_125 ,
V_10 -> V_129 , V_10 ) < 0 )
goto V_130;
F_1 ( V_10 -> V_122 ) ;
return 0 ;
V_130:
F_57 ( V_10 -> V_14 , V_10 ) ;
V_128:
F_57 ( V_10 -> V_117 , V_10 ) ;
error:
F_58 ( V_10 -> V_44 ) ;
V_10 -> V_44 = NULL ;
return - V_112 ;
}
static void F_59 ( struct V_84 * V_85 )
{
unsigned long V_2 ;
T_1 V_12 ;
struct V_9 * V_10 =
F_40 ( V_85 , struct V_9 , V_27 ) ;
F_16 ( L_1 , V_10 -> V_38 ) ;
F_47 ( & V_85 -> V_76 , V_2 ) ;
F_10 ( V_10 ) ;
* V_10 -> V_20 = F_8 ( V_7 ) ;
V_12 = * V_10 -> V_20 ;
V_10 -> V_15 = 0 ;
F_48 ( & V_85 -> V_76 , V_2 ) ;
* V_10 -> V_71 &= ~ ( V_116 | V_105 | V_109 ) ;
* V_10 -> V_99 = 0 ;
if ( V_10 -> V_44 ) {
void * V_131 = V_10 -> V_44 ;
V_10 -> V_44 = NULL ;
F_58 ( V_131 ) ;
}
F_57 ( V_10 -> V_122 , V_10 ) ;
F_57 ( V_10 -> V_117 , V_10 ) ;
F_57 ( V_10 -> V_14 , V_10 ) ;
V_13 [ V_10 -> V_14 ] . V_10 = NULL ;
V_13 [ V_10 -> V_117 ] . V_10 = NULL ;
}
static void F_60 ( struct V_9 * V_10 ,
struct V_132 * V_133 ,
struct V_132 * V_134 )
{
unsigned long V_2 ;
unsigned long V_135 = V_10 -> V_135 ;
unsigned V_136 ;
int V_137 , V_138 , V_139 , V_3 ;
T_1 V_140 , V_141 ;
T_2 V_142 , V_143 ;
T_2 V_100 = V_10 -> V_100 ;
F_16 ( L_8 , V_10 -> V_38 , V_135 ) ;
V_136 = V_133 -> V_144 ;
switch ( V_136 & V_145 ) {
case V_146 : V_141 = V_147 ; V_138 = 9 ; break;
case V_148 : V_141 = V_149 ; V_138 = 10 ; break;
default: V_141 = V_149 ; V_138 = 10 ; break;
}
if ( V_136 & V_150 ) {
V_141 |= V_151 ;
V_138 ++ ;
}
if ( V_136 & V_152 ) {
V_138 ++ ;
if ( V_136 & V_153 )
V_141 |= V_154 ;
#ifdef F_61
else if ( V_136 & F_61 )
V_141 |= V_155 ;
#endif
else
V_141 |= V_156 ;
}
V_143 = 0 ;
switch ( V_10 -> V_27 . line ) {
#ifdef F_62
case 0 :
#if F_63 ( V_157 )
V_141 |= V_158 ;
#elif F_63 ( V_159 )
V_141 |= V_160 ;
#elif F_63 ( V_161 )
V_141 |= V_162 ;
#else
#error "Unknown config for ttySM0"
#endif
break;
#endif
#ifdef F_64
case 1 :
#if F_63 ( V_163 ) || F_63 ( V_164 )
#if F_63 ( V_165 )
V_141 |= V_166 ;
#elif F_63 ( V_167 )
V_141 |= V_168 ;
#else
#error "Unknown config for ttySM1"
#endif
#else
#if F_63 ( V_169 )
V_141 |= V_170 ;
#else
#error "Unknown config for ttySM1"
#endif
#endif
break;
#endif
#ifdef F_65
case 2 :
#if F_63 ( V_163 )
#if F_63 ( V_171 )
V_141 |= V_172 ;
#else
#error "Unknown config for ttySM2"
#endif
#else
#if F_63 ( V_173 )
V_141 |= V_174 ;
#elif F_63 ( V_175 )
V_141 |= V_176 ;
#elif F_63 ( V_177 )
V_141 |= V_178 ;
#else
#error "Unknown config for ttySM2"
#endif
#endif
break;
#endif
default:
break;
}
V_179:
V_137 = F_66 ( & V_10 -> V_27 , V_133 , V_134 , 0 ,
V_10 -> V_135 / 8 ) ;
F_37 ( L_13 , V_143 , V_137 ) ;
if ( ! V_137 )
V_137 = 9600 ;
V_139 = 1 ;
if ( V_137 == 134 ) {
V_137 = 269 ;
V_139 = 2 ;
}
if ( V_137 == 38400 &&
( V_10 -> V_27 . V_2 & V_180 ) == V_181
) {
F_37 ( L_14 , V_10 -> V_27 . V_182 ) ;
if ( V_100 == V_183 ) {
if ( V_10 -> V_27 . V_182 <= 65535 ) {
V_142 = V_184 ;
V_140 = V_10 -> V_27 . V_182 ;
V_10 -> V_27 . V_185 = V_135 ;
goto V_186;
}
if ( V_10 -> V_27 . V_182 / 8 <= 65535 ) {
V_142 = V_187 ;
V_140 = V_10 -> V_27 . V_182 / 8 ;
V_10 -> V_27 . V_182 = V_140 * 8 ;
V_10 -> V_27 . V_185 = V_135 / 8 ;
goto V_186;
}
if ( V_10 -> V_27 . V_182 / 32 <= 65535 ) {
V_142 = V_188 ;
V_140 = V_10 -> V_27 . V_182 / 32 ;
V_10 -> V_27 . V_182 = V_140 * 32 ;
V_10 -> V_27 . V_185 = V_135 / 32 ;
goto V_186;
}
} else if ( V_100 == V_101 ) {
if ( V_10 -> V_27 . V_182 <= 255 ) {
V_142 = V_189 ;
V_140 = V_10 -> V_27 . V_182 ;
V_10 -> V_27 . V_185 = V_135 ;
goto V_186;
}
if ( V_10 -> V_27 . V_182 / 8 <= 255 ) {
V_142 = V_190 ;
V_140 = V_10 -> V_27 . V_182 / 8 ;
V_10 -> V_27 . V_182 = V_140 * 8 ;
V_10 -> V_27 . V_185 = V_135 / 8 ;
goto V_186;
}
if ( V_10 -> V_27 . V_182 / 32 <= 255 ) {
V_142 = V_191 ;
V_140 = V_10 -> V_27 . V_182 / 32 ;
V_10 -> V_27 . V_182 = V_140 * 32 ;
V_10 -> V_27 . V_185 = V_135 / 32 ;
goto V_186;
}
}
}
switch ( V_100 ) {
case V_183 :
V_10 -> V_27 . V_185 = V_135 ;
V_142 = V_184 ;
V_140 = V_3 = ( V_135 / ( V_137 * V_139 ) + 4 ) / 8 - 1 ;
if ( V_3 > 0 && V_3 <= 65535 )
goto V_186;
V_10 -> V_27 . V_185 = V_135 / 8 ;
V_142 = V_187 ;
V_140 = V_3 = ( V_135 / ( V_137 * 8 * V_139 ) + 4 ) / 8 - 1 ;
if ( V_3 > 0 && V_3 <= 65535 )
goto V_186;
V_10 -> V_27 . V_185 = V_135 / 32 ;
V_142 = V_188 ;
V_140 = V_3 = ( V_135 / ( V_137 * 32 * V_139 ) + 4 ) / 8 - 1 ;
if ( V_3 > 0 && V_3 <= 65535 )
goto V_186;
break;
case V_101 :
V_10 -> V_27 . V_185 = V_135 ;
V_142 = V_189 ;
V_140 = V_3 = ( V_135 / ( V_137 * V_139 ) + 4 ) / 8 - 1 ;
if ( V_3 > 0 && V_3 <= 255 )
goto V_186;
V_10 -> V_27 . V_185 = V_135 / 8 ;
V_142 = V_190 ;
V_140 = V_3 = ( V_135 / ( V_137 * 8 * V_139 ) + 4 ) / 8 - 1 ;
if ( V_3 > 0 && V_3 <= 255 )
goto V_186;
V_10 -> V_27 . V_185 = V_135 / 32 ;
V_142 = V_191 ;
V_140 = V_3 = ( V_135 / ( V_137 * 32 * V_139 ) + 4 ) / 8 - 1 ;
if ( V_3 > 0 && V_3 <= 255 )
goto V_186;
break;
default:
F_67 () ;
return;
}
F_37 ( L_15 ) ;
switch ( V_143 ) {
case 0 :
if ( V_134 ) {
V_133 -> V_144 &= ~ V_192 ;
V_133 -> V_144 |= ( V_134 -> V_144 & V_192 ) ;
V_143 = 1 ;
goto V_179;
}
case 1 :
V_133 -> V_144 &= ~ V_192 ;
V_133 -> V_144 |= V_193 ;
V_143 = 2 ;
goto V_179;
default:
V_133 -> V_144 &= ~ V_192 ;
V_133 -> V_144 |= V_194 ;
if ( V_100 == V_183 )
V_142 = V_188 ;
else if ( V_100 == V_101 )
V_142 = V_191 ;
V_140 = 1 ;
V_10 -> V_27 . V_185 = V_135 / 32 ;
break;
}
V_186:
F_37 ( L_16 , V_10 -> V_27 . V_185 , V_140 ) ;
F_47 ( & V_10 -> V_27 . V_76 , V_2 ) ;
F_68 ( & V_10 -> V_27 , V_133 -> V_144 , V_137 ) ;
switch ( V_100 ) {
case V_183 :
* V_10 -> V_99 = 0 ;
* V_10 -> V_102 = V_140 ;
* V_10 -> V_99 = V_195 ;
* V_10 -> V_99 = V_142 | V_196 ;
break;
case V_101 :
* V_10 -> V_99 = 0 ;
* ( volatile T_2 * ) V_10 -> V_102 = ( T_2 ) V_140 ;
* V_10 -> V_99 = V_197 ;
* V_10 -> V_99 = V_142 | V_198 ;
break;
}
V_141 &= ~ ( V_106 | V_72 ) ;
if ( V_10 -> type == V_81 && V_136 & V_199 ) {
V_10 -> V_69 = * V_10 -> V_82 ;
if ( V_10 -> V_69 & V_73 )
V_141 |= V_106 ;
else
V_141 |= V_106 | V_72 ;
}
V_10 -> V_27 . V_61 = ( 1 << V_60 ) | ( 1 << V_64 ) ;
if ( V_133 -> V_200 & V_201 )
V_10 -> V_27 . V_61 |=
( 1 << V_59 ) | ( 1 << V_57 ) ;
if ( V_133 -> V_200 & ( V_202 | V_203 ) )
V_10 -> V_27 . V_61 |= ( 1 << V_53 ) ;
V_10 -> V_27 . V_62 = 0 ;
if ( V_133 -> V_200 & V_204 )
V_10 -> V_27 . V_62 |=
( 1 << V_59 ) | ( 1 << V_57 ) ;
if ( V_133 -> V_200 & V_205 ) {
V_10 -> V_27 . V_62 |= ( 1 << V_53 ) ;
if ( V_133 -> V_200 & V_204 )
V_10 -> V_27 . V_62 |= ( 1 << V_64 ) ;
}
if ( ( V_133 -> V_144 & V_206 ) == 0 )
V_10 -> V_27 . V_62 |= ( 1 << V_60 ) ;
V_141 |= V_116 | V_105 ;
V_141 |= * V_10 -> V_71 & V_109 ;
* V_10 -> V_71 = V_141 ;
F_48 ( & V_10 -> V_27 . V_76 , V_2 ) ;
}
static void F_69 ( struct V_84 * V_85 ,
struct V_132 * V_133 ,
struct V_132 * V_134 )
{
struct V_9 * V_10 =
F_40 ( V_85 , struct V_9 , V_27 ) ;
F_16 ( L_17 , V_10 -> V_38 , V_133 , V_134 ) ;
F_60 ( V_10 , V_133 , V_134 ) ;
if ( ! ( V_133 -> V_144 & V_199 ) ) {
T_1 V_68 = * V_10 -> V_71 ;
V_68 &= ~ V_106 ;
* V_10 -> V_71 = V_68 ;
}
if ( V_133 -> V_144 & V_207 )
* V_10 -> V_71 |= V_208 ;
else
* V_10 -> V_71 &= ~ V_208 ;
}
static const char * F_70 ( struct V_84 * V_85 )
{
struct V_9 * V_10 =
F_40 ( V_85 , struct V_9 , V_27 ) ;
if ( V_10 -> V_27 . type == V_81 )
return L_18 ;
return L_19 ;
}
static void F_71 ( struct V_84 * V_85 )
{
struct V_9 * V_10 =
F_40 ( V_85 , struct V_9 , V_27 ) ;
F_16 ( L_1 , V_10 -> V_38 ) ;
F_72 ( ( unsigned long ) V_10 -> V_209 , 16 ) ;
}
static int F_73 ( struct V_84 * V_85 )
{
struct V_9 * V_10 =
F_40 ( V_85 , struct V_9 , V_27 ) ;
F_16 ( L_1 , V_10 -> V_38 ) ;
F_74 ( ( unsigned long ) V_10 -> V_209 , 16 , V_10 -> V_38 ) ;
return 0 ;
}
static void F_75 ( struct V_84 * V_85 , int type )
{
struct V_9 * V_10 =
F_40 ( V_85 , struct V_9 , V_27 ) ;
F_16 ( L_1 , V_10 -> V_38 ) ;
V_10 -> V_27 . type = V_210 ;
if ( V_10 -> V_211 & V_212 )
V_10 -> V_27 . type = V_81 ;
F_73 ( V_85 ) ;
}
static int F_76 ( struct V_84 * V_85 ,
struct V_213 * V_214 )
{
struct V_9 * V_10 =
F_40 ( V_85 , struct V_9 , V_27 ) ;
void * V_215 = ( void * ) ( unsigned long ) V_10 -> V_27 . V_215 ;
F_16 ( L_1 , V_10 -> V_38 ) ;
if ( V_214 -> V_1 != V_10 -> V_27 . V_1 ||
V_214 -> V_10 != V_10 -> V_27 . V_216 ||
V_214 -> V_217 != V_10 -> V_27 . V_218 ||
V_214 -> V_219 != V_215 ||
V_214 -> V_220 != V_10 -> V_27 . V_221 ||
V_214 -> V_222 != V_10 -> V_27 . V_222 ||
V_214 -> V_223 != V_10 -> V_27 . V_224 )
return - V_225 ;
if ( V_214 -> type != V_10 -> V_27 . type ) {
if ( ! ( V_10 -> V_211 & V_212 ) )
return - V_225 ;
if ( V_214 -> type != V_210 &&
V_214 -> type != V_81 )
return - V_225 ;
}
return 0 ;
}
static int T_5 F_77 ( void )
{
struct V_9 * V_10 ;
int V_226 , V_227 ;
F_78 ( V_228 L_20 ,
V_229 , V_230 , V_231 ) ;
#if F_63 ( F_65 ) && F_63 ( V_163 )
{
int V_3 ;
V_232 = 8 ;
V_3 = V_232 ;
}
#endif
F_79 ( F_80 ( V_7 ) ,
V_233 ) ;
V_226 = F_81 ( & V_234 ) ;
if ( ! V_226 ) {
for ( V_227 = 0 ; V_227 < V_235 ; V_227 ++ ) {
V_10 = V_236 [ V_227 ] ;
if ( ! V_10 || V_10 -> V_103 )
continue;
switch ( V_10 -> V_237 ) {
case V_238 :
V_10 -> V_135 = V_239 ;
break;
#ifdef F_82
case V_240 :
V_10 -> V_135 = F_82 ;
break;
#endif
default:
F_67 () ;
}
V_226 = F_83 ( & V_234 ,
& V_10 -> V_27 ) ;
if ( V_226 < 0 ) {
F_37 ( L_21 , - V_226 ) ;
break;
}
}
if ( V_226 )
F_84 ( & V_234 ) ;
}
return V_226 ;
}
static void F_85 ( struct V_241 * V_242 ,
const char * V_243 , unsigned V_32 )
{
struct V_9 * V_10 ;
unsigned V_227 ;
T_1 V_141 ;
T_2 V_142 ;
unsigned long V_2 ;
int V_244 = 1 ;
V_10 = V_236 [ V_242 -> V_245 ] ;
F_86 ( V_2 ) ;
if ( V_10 -> V_27 . V_246 ) {
V_244 = 0 ;
} else if ( V_247 ) {
V_244 = F_87 ( & V_10 -> V_27 . V_76 ) ;
} else
F_36 ( & V_10 -> V_27 . V_76 ) ;
F_10 ( V_10 ) ;
V_141 = * V_10 -> V_71 ;
if ( ! ( V_141 & V_116 ) ) {
V_142 = * V_10 -> V_99 ;
switch ( V_10 -> V_100 ) {
case V_183 :
* V_10 -> V_99 = 0 ;
* V_10 -> V_99 = V_195 ;
* V_10 -> V_99 = V_142 | V_196 ;
break;
case V_101 :
* V_10 -> V_99 = 0 ;
* V_10 -> V_99 = V_197 ;
* V_10 -> V_99 = V_142 | V_198 ;
break;
}
* V_10 -> V_71 = ( V_141 & ~ V_109 ) | V_116 ;
} else if ( V_141 & V_109 ) {
* V_10 -> V_71 = ( V_141 & ~ V_109 ) ;
}
for ( V_227 = 0 ; V_227 < V_32 ; V_227 ++ ) {
char V_34 = * V_243 ++ ;
while ( * V_10 -> V_82 & V_87 )
continue;
* V_10 -> V_248 = V_34 ;
if ( V_34 == 0x0a ) {
while ( * V_10 -> V_82 & V_87 )
continue;
* V_10 -> V_248 = 0xd ;
}
}
while ( * V_10 -> V_82 & ( V_86 | V_87 ) )
continue;
if ( ! ( V_141 & V_116 ) )
* V_10 -> V_71 = V_141 ;
F_12 ( V_10 ) ;
if ( V_244 )
F_38 ( & V_10 -> V_27 . V_76 ) ;
F_88 ( V_2 ) ;
}
static int T_5 F_89 ( struct V_241 * V_242 ,
char * V_211 )
{
struct V_9 * V_10 ;
int V_227 , V_58 = 'n' , V_137 = 9600 , V_138 = 8 , V_249 = 0 ;
for ( V_227 = 0 ; V_227 < V_235 ; V_227 ++ ) {
V_10 = V_236 [ V_227 ] ;
if ( V_10 && ! V_10 -> V_103 && V_10 -> V_27 . line == V_242 -> V_245 )
goto V_250;
}
return - V_251 ;
V_250:
switch ( V_10 -> V_237 ) {
case V_238 :
V_10 -> V_135 = V_239 ;
break;
#ifdef F_82
case V_240 :
V_10 -> V_135 = F_82 ;
break;
#endif
default:
F_67 () ;
}
if ( V_211 )
F_90 ( V_211 , & V_137 , & V_58 , & V_138 , & V_249 ) ;
return F_91 ( & V_10 -> V_27 , V_242 , V_137 , V_58 , V_138 , V_249 ) ;
}
static int T_5 F_92 ( void )
{
F_93 ( & V_252 ) ;
return 0 ;
}
static int F_94 ( struct V_84 * V_85 )
{
struct V_9 * V_10 =
F_40 ( V_85 , struct V_9 , V_27 ) ;
unsigned V_31 ;
T_2 V_33 , V_34 ;
F_16 ( L_1 , V_10 -> V_38 ) ;
if ( V_13 [ V_10 -> V_117 ] . V_10 != NULL ) {
do {
V_31 = F_20 ( V_10 -> V_40 ) ;
if ( F_17 ( V_10 -> V_39 , V_31 , V_41 ) == 0 )
return V_253 ;
F_21 () ;
V_34 = V_10 -> V_44 [ V_31 ++ ] ;
V_33 = V_10 -> V_44 [ V_31 ++ ] ;
F_22 () ;
V_10 -> V_40 = V_31 & ( V_41 - 1 ) ;
} while ( V_33 & ( V_46 | V_47 | V_48 ) );
} else {
do {
V_33 = * V_10 -> V_82 ;
if ( V_33 & ( V_46 | V_47 | V_48 ) )
continue;
} while ( ! ( V_33 & V_254 ) );
V_34 = * V_10 -> V_255 ;
}
return V_34 ;
}
static void F_95 ( struct V_84 * V_85 ,
unsigned char V_34 )
{
struct V_9 * V_10 =
F_40 ( V_85 , struct V_9 , V_27 ) ;
T_2 V_256 , V_3 ;
while ( * V_10 -> V_82 & ( V_87 | V_86 ) )
continue;
V_256 = * V_10 -> V_98 ;
* V_10 -> V_98 = V_256 & ~ V_115 ;
V_3 = * V_10 -> V_98 ;
if ( V_34 == 0x0a ) {
* V_10 -> V_248 = 0x0d ;
while ( * V_10 -> V_82 & V_87 )
continue;
}
* V_10 -> V_248 = V_34 ;
while ( * V_10 -> V_82 & V_87 )
continue;
* V_10 -> V_98 = V_256 ;
V_3 = * V_10 -> V_98 ;
}
