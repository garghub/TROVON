static inline long F_1 ( void )
{
if ( sizeof( long ) == 8 && V_1 )
return F_2 () ;
else
return F_3 () ;
}
static inline void F_4 ( long V_2 )
{
if ( sizeof( long ) == 8 &&
( V_3 || V_1 ) ) {
F_5 ( V_2 | V_4 ) ;
F_5 ( V_2 ) ;
} else {
F_6 ( V_2 | V_4 ) ;
F_6 ( V_2 ) ;
}
}
static inline unsigned int F_7 ( struct V_5 * V_6 )
{
return V_7 ;
}
static inline unsigned int F_8 ( struct V_5 * V_6 )
{
return 0 ;
}
static inline unsigned int F_9 ( struct V_5 * V_6 )
{
return 0 ;
}
static inline unsigned int F_10 ( struct V_5 * V_6 )
{
return V_8 ;
}
static inline unsigned int F_11 ( struct V_5 * V_6 )
{
return V_9 ;
}
static inline unsigned int F_12 ( struct V_5 * V_6 )
{
unsigned int V_10 = V_11 | V_12 | V_13 ;
if ( F_13 ( & V_6 -> V_14 ) )
V_10 |= V_15 ;
if ( F_14 ( & V_6 -> V_14 ) ) {
if ( V_16 )
V_10 |= V_17 ;
if ( V_18 )
V_10 |= V_19 | V_20 ;
}
return V_10 ;
}
static inline unsigned int F_15 ( struct V_5 * V_6 )
{
return F_7 ( V_6 ) | V_21 ;
}
static inline unsigned int F_16 ( struct V_5 * V_6 )
{
unsigned int V_10 = F_8 ( V_6 ) | V_21 ;
if ( F_17 ( & V_6 -> V_14 ) )
V_10 |= V_22 ;
return V_10 ;
}
static inline unsigned int F_18 ( struct V_5 * V_6 )
{
return F_9 ( V_6 ) | V_21 ;
}
static inline unsigned int F_19 ( struct V_5 * V_6 )
{
unsigned int V_10 = F_10 ( V_6 ) | V_21 |
V_23 | V_24 ;
if ( F_20 ( & V_6 -> V_14 ) )
V_10 |= V_25 ;
return V_10 ;
}
static inline unsigned int F_21 ( struct V_5 * V_6 )
{
return F_11 ( V_6 ) | V_21 ;
}
static inline unsigned int F_22 ( struct V_5 * V_6 )
{
return F_12 ( V_6 ) | V_26 ;
}
static T_1 F_23 ( T_2 V_27 )
{
return V_27 ;
}
static void F_24 ( struct V_5 * V_6 , unsigned int V_28 )
{
F_25 ( V_28 , & V_6 -> V_14 . V_29 ) ;
F_26 ( V_28 , & V_6 -> V_14 . V_30 ) ;
}
static void F_27 ( struct V_5 * V_6 , unsigned int V_28 )
{
F_26 ( V_28 , & V_6 -> V_14 . V_29 ) ;
F_25 ( V_28 , & V_6 -> V_14 . V_30 ) ;
}
static void F_28 ( struct V_5 * V_6 )
{
F_24 ( V_6 , V_31 ) ;
}
static void F_29 ( struct V_5 * V_6 )
{
F_27 ( V_6 , V_31 ) ;
}
static void F_30 ( struct V_5 * V_6 ,
struct V_32 * V_33 )
{
int V_34 = ( int ) V_33 -> V_33 ;
switch ( V_34 ) {
case 2 :
F_24 ( V_6 , V_35 ) ;
break;
case 3 :
F_24 ( V_6 , V_36 ) ;
break;
case 4 :
F_24 ( V_6 , V_37 ) ;
break;
default:
break;
}
}
static void F_31 ( struct V_5 * V_6 ,
struct V_32 * V_33 )
{
int V_34 = ( int ) V_33 -> V_33 ;
switch ( V_34 ) {
case - 2 :
F_27 ( V_6 , V_35 ) ;
break;
case - 3 :
F_27 ( V_6 , V_36 ) ;
break;
case - 4 :
F_27 ( V_6 , V_37 ) ;
break;
default:
break;
}
}
static int F_32 ( struct V_5 * V_6 , unsigned int V_28 ,
T_3 V_38 )
{
T_3 V_33 = ( V_28 < V_39 ) ?
V_40 [ V_28 ] : 0 ;
switch ( V_28 ) {
case V_31 :
F_33 ( V_41 ) ;
break;
case V_35 :
case V_36 :
case V_37 :
if ( V_42 )
F_34 ( V_33 ) ;
else
F_33 ( V_33 ) ;
break;
default:
break;
}
F_26 ( V_28 , & V_6 -> V_14 . V_29 ) ;
return 1 ;
}
static int F_35 ( struct V_5 * V_6 , unsigned int V_28 ,
T_3 V_38 )
{
T_3 V_33 = ( V_28 < V_39 ) ?
V_40 [ V_28 ] : 0 ;
switch ( V_28 ) {
case V_31 :
if ( V_42 ) {
if ( ! ( F_36 () & ( V_33 << 14 ) ) )
F_37 ( V_33 ) ;
} else {
F_38 ( V_33 ) ;
}
break;
case V_35 :
case V_36 :
case V_37 :
if ( V_42 ) {
if ( ! ( F_36 () & ( V_33 << 14 ) ) )
F_37 ( V_33 ) ;
} else {
F_38 ( V_33 ) ;
}
break;
default:
break;
}
F_26 ( V_28 , & V_6 -> V_14 . V_30 ) ;
return 1 ;
}
static bool F_39 ( struct V_5 * V_6 )
{
if ( F_40 ( V_6 ) )
return false ;
if ( V_43 != V_6 -> V_14 . V_44 )
return false ;
if ( V_45 . V_46 != 0xffffffff )
return false ;
return true ;
}
static void F_41 ( struct V_5 * V_6 , T_3 V_47 ,
T_3 V_38 )
{
F_42 ( V_47 - F_43 () ) ;
F_44 () ;
F_45 ( V_38 ) ;
}
static void F_46 ( struct V_5 * V_6 ,
T_3 V_47 , T_3 V_38 )
{
T_3 V_48 , V_49 ;
T_4 V_50 ;
unsigned long V_51 ;
F_47 ( V_51 ) ;
V_50 = F_48 ( V_6 , & V_48 ) ;
F_42 ( V_48 - F_43 () ) ;
F_49 ( V_51 ) ;
F_44 () ;
F_45 ( V_38 ) ;
F_44 () ;
V_49 = F_50 () ;
if ( V_49 - V_48 > V_47 - V_48 - 1 )
F_24 ( V_6 , V_31 ) ;
}
static void F_51 ( struct V_5 * V_6 )
{
struct V_52 * V_53 = V_6 -> V_14 . V_53 ;
T_3 V_38 , V_47 ;
V_47 = F_52 ( V_53 ) ;
V_38 = F_53 ( V_53 ) ;
F_54 ( V_47 ) ;
F_41 ( V_6 , V_47 , V_38 ) ;
}
void F_55 ( struct V_5 * V_6 )
{
T_3 V_54 ;
V_54 = F_56 () ;
if ( ! ( V_54 & V_55 ) && F_39 ( V_6 ) ) {
F_57 ( V_54 | V_55 ) ;
F_46 ( V_6 , F_58 () ,
F_59 () ) ;
}
}
static void F_60 ( struct V_5 * V_6 ,
T_3 * V_56 , T_3 * V_57 )
{
T_3 V_38 , V_47 , V_58 , V_59 ;
T_4 V_60 ;
V_47 = F_58 () ;
* V_56 = V_47 ;
V_60 = F_61 () ;
V_58 = F_50 () ;
F_44 () ;
V_38 = F_59 () ;
* V_57 = V_38 ;
F_44 () ;
V_59 = F_50 () ;
if ( V_59 - V_58 > V_47 - V_58 - 1 )
F_24 ( V_6 , V_31 ) ;
F_62 ( V_6 , V_60 , V_59 , - 0x10000 ) ;
}
static void F_63 ( struct V_5 * V_6 )
{
struct V_52 * V_53 = V_6 -> V_14 . V_53 ;
T_3 V_54 , V_47 , V_38 ;
V_54 = F_56 () ;
if ( V_54 & V_55 ) {
F_57 ( V_54 & ~ V_55 ) ;
F_60 ( V_6 , & V_47 , & V_38 ) ;
} else {
V_47 = F_58 () ;
V_38 = F_59 () ;
}
F_64 ( V_53 , V_38 ) ;
F_65 ( V_53 , V_47 ) ;
}
void F_66 ( struct V_5 * V_6 )
{
T_3 V_54 , V_47 , V_38 ;
F_67 () ;
V_54 = F_56 () ;
if ( V_54 & V_55 ) {
F_57 ( V_54 & ~ V_55 ) ;
F_60 ( V_6 , & V_47 , & V_38 ) ;
F_41 ( V_6 , V_47 , V_38 ) ;
}
F_68 () ;
}
static bool F_69 ( union V_61 V_62 )
{
if ( V_62 . V_63 . V_64 != V_65 )
return false ;
switch ( V_62 . V_63 . V_66 ) {
case V_67 :
case V_68 :
case V_69 :
case V_70 :
case V_71 :
case V_72 :
case V_73 :
case V_74 :
case V_75 :
case V_76 :
case V_77 :
case V_78 :
case V_79 :
case V_80 :
case V_81 :
case V_82 :
return true ;
default:
return false ;
}
}
static bool F_70 ( struct V_5 * V_6 , unsigned int V_83 , bool V_84 )
{
T_3 V_85 ;
int V_86 ;
V_85 = 0x70080000 << V_83 ;
if ( ( V_87 ) V_85 < 0 ) {
if ( ! V_84 || ! ( F_71 () & V_88 ) )
return true ;
} else {
V_85 <<= 8 ;
if ( ( V_87 ) V_85 < 0 ) {
union V_61 V_62 ;
unsigned int V_89 ;
T_3 * V_90 ;
V_89 = F_71 () ;
if ( ! ( V_89 & ( V_91 | V_88 ) ) &&
( V_89 & V_92 ) )
return true ;
V_90 = ( T_3 * ) V_6 -> V_14 . V_93 ;
if ( V_6 -> V_14 . V_94 & V_95 )
V_90 += 1 ;
V_86 = F_72 ( V_90 , V_6 , & V_62 . V_96 ) ;
if ( ! V_86 && F_69 ( V_62 ) )
return true ;
}
}
return false ;
}
static int F_73 ( struct V_5 * V_6 , unsigned long V_27 ,
unsigned long * V_97 )
{
T_3 V_98 = V_27 ;
unsigned long V_99 ;
if ( ( long ) V_27 == ( V_87 ) V_98 ) {
if ( V_100 ) {
unsigned long V_10 , V_101 ;
switch ( V_98 >> 29 ) {
case 0 :
case 1 :
V_99 = F_74 () >> 16 ;
V_10 = ( unsigned long ) 0xfc0000000ull ;
break;
case 2 :
case 3 :
V_99 = F_74 () ;
V_10 = ( unsigned long ) 0xfc0000000ull ;
break;
case 4 :
V_99 = F_75 () >> 16 ;
V_10 = ( unsigned long ) 0xfe0000000ull ;
break;
case 5 :
V_99 = F_75 () ;
V_10 = ( unsigned long ) 0xfe0000000ull ;
break;
case 6 :
V_99 = F_76 () >> 16 ;
V_10 = ( unsigned long ) 0xfe0000000ull ;
break;
case 7 :
V_99 = F_76 () ;
V_10 = ( unsigned long ) 0xfe0000000ull ;
break;
default:
F_77 () ;
}
if ( F_70 ( V_6 , ( V_99 >> 4 ) & 0x7 ,
V_99 & 0x0008 ) )
goto V_102;
V_101 = ( V_99 << 20 ) & V_10 ;
V_101 |= V_98 & ~ V_10 ;
* V_97 = V_101 ;
return 0 ;
} else if ( ( V_87 ) V_98 < ( V_87 ) 0xc0000000 ) {
* V_97 = V_98 & 0x1fffffff ;
return 0 ;
}
#ifdef F_78
} else if ( ( V_27 & 0xc000000000000000 ) == 0x8000000000000000 ) {
if ( V_100 ) {
V_99 = F_74 () ;
if ( V_99 & ( 1ull << ( 56 + ( ( V_27 >> 59 ) & 0x7 ) ) ) ) {
V_99 = F_75 () ;
if ( F_70 ( V_6 , ( V_99 >> 59 ) & 0x7 ,
0 ) )
goto V_102;
}
}
* V_97 = V_27 & 0x07ffffffffffffff ;
return 0 ;
#endif
}
V_102:
return F_79 ( V_6 , V_27 , V_97 ) ;
}
static int F_80 ( struct V_5 * V_6 , unsigned long V_103 ,
unsigned long * V_97 )
{
unsigned int V_104 = ( V_6 -> V_14 . V_105 &
V_106 ) >> V_107 ;
if ( F_81 ( V_104 == V_108 ) ) {
* V_97 = V_103 ;
return 0 ;
}
if ( F_82 ( V_104 != V_109 ,
L_1 , V_104 ) )
return - V_110 ;
return F_73 ( V_6 , V_103 , V_97 ) ;
}
static int F_83 ( struct V_5 * V_6 )
{
T_3 * V_90 = ( T_3 * ) V_6 -> V_14 . V_93 ;
T_3 V_38 = V_6 -> V_14 . V_94 ;
T_3 V_111 = ( V_38 & V_112 ) >> V_113 ;
unsigned long V_103 = V_6 -> V_14 . V_114 ;
T_3 V_62 = 0 ;
if ( V_38 & V_95 )
V_90 += 1 ;
F_72 ( V_90 , V_6 , & V_62 ) ;
F_84 ( L_2 ,
V_111 , V_90 , V_62 , V_103 ,
F_71 () ) ;
F_85 ( V_6 ) ;
V_6 -> V_115 -> V_116 = V_117 ;
return V_118 ;
}
static unsigned long F_86 ( unsigned int V_119 , unsigned long V_120 )
{
unsigned long V_10 = 0xfffff000 | V_121 | V_122 ;
if ( F_87 () & V_123 )
V_10 |= 0x00ffffff00000000ull ;
if ( V_124 )
V_10 |= V_125 ;
if ( V_119 == V_126 ) {
V_120 &= ~ V_125 ;
} else if ( V_119 == V_127 ) {
V_120 &= ~ V_125 ;
if ( V_120 & V_122 )
V_120 |= V_125 ;
}
return V_120 & V_10 ;
}
static void F_88 ( struct V_5 * V_6 , unsigned long V_120 )
{
struct V_52 * V_53 = V_6 -> V_14 . V_53 ;
V_120 &= V_128 ;
if ( V_120 == V_128 )
F_89 ( V_53 , F_90 ( V_6 -> V_14 . V_129 ) - 1 ) ;
else if ( V_120 < F_90 ( V_6 -> V_14 . V_129 ) )
F_89 ( V_53 , V_120 ) ;
}
static enum V_130 F_91 ( union V_61 V_62 ,
T_3 * V_90 , T_3 V_38 ,
struct V_131 * V_115 ,
struct V_5 * V_6 )
{
struct V_52 * V_53 = V_6 -> V_14 . V_53 ;
enum V_130 V_132 = V_133 ;
T_3 V_134 , V_135 , V_136 ;
unsigned long V_137 ;
unsigned long V_120 ;
V_137 = V_6 -> V_14 . V_93 ;
V_132 = F_92 ( V_6 , V_38 ) ;
if ( V_132 == V_138 )
return V_132 ;
if ( V_62 . V_139 . V_140 ) {
switch ( V_62 . V_139 . V_66 ) {
case V_141 :
V_132 = F_93 ( V_6 ) ;
break;
default:
V_132 = V_138 ;
}
} else {
V_134 = V_62 . V_142 . V_134 ;
V_135 = V_62 . V_142 . V_135 ;
V_136 = V_62 . V_142 . V_136 ;
switch ( V_62 . V_142 . V_143 ) {
case V_144 :
case V_145 :
#ifdef F_94
V_53 -> V_146 [ V_135 ] [ V_136 ] ++ ;
#endif
if ( V_135 == V_147 &&
V_136 == 0 ) {
V_120 = F_95 ( V_6 ) ;
} else if ( V_135 == V_148 &&
V_136 == 0 ) {
V_120 = F_58 () ;
} else if ( V_135 == V_149 &&
V_136 == 0 ) {
if ( V_150 )
V_120 = F_96 () &
V_151 ;
else
V_120 = 0 ;
} else if ( V_135 == V_149 &&
V_136 == 1 &&
V_152 &&
! V_153 ) {
F_97 ( F_98 ( V_53 ) >=
F_90 ( V_6 -> V_14 . V_129 ) ) ;
V_120 = V_6 -> V_14 . V_129 [
F_98 ( V_53 ) ] ;
} else if ( ( V_135 == V_154 &&
( V_136 == 0 ||
V_136 == 2 ||
V_136 == 3 ) ) ||
( V_135 == V_155 &&
( V_136 == 2 ||
V_136 == 3 ) ) ||
( V_135 == V_156 &&
( V_136 == 7 ) ) ||
( V_135 == V_149 &&
( V_136 == 2 ) &&
V_152 &&
! V_153 ) ||
( V_135 == V_157 &&
( V_136 == 0 ) ) ) {
V_120 = V_53 -> V_158 [ V_135 ] [ V_136 ] ;
} else {
V_120 = 0 ;
V_132 = V_138 ;
}
if ( V_132 != V_138 ) {
if ( V_62 . V_142 . V_143 == V_145 )
V_120 = ( int ) V_120 ;
V_6 -> V_14 . V_159 [ V_134 ] = V_120 ;
}
F_99 ( V_6 , ( V_62 . V_142 . V_143 == V_145 ) ?
V_160 : V_161 ,
F_100 ( V_135 , V_136 ) , V_120 ) ;
break;
case V_127 :
case V_126 :
#ifdef F_94
V_53 -> V_146 [ V_135 ] [ V_136 ] ++ ;
#endif
V_120 = V_6 -> V_14 . V_159 [ V_134 ] ;
F_99 ( V_6 , ( V_62 . V_142 . V_143 == V_126 ) ?
V_162 : V_163 ,
F_100 ( V_135 , V_136 ) , V_120 ) ;
if ( V_135 == V_147 &&
V_136 == 0 ) {
F_66 ( V_6 ) ;
F_101 ( V_6 , V_6 -> V_14 . V_159 [ V_134 ] ) ;
} else if ( V_135 == V_148 &&
V_136 == 0 ) {
F_102 ( V_6 ,
V_6 -> V_14 . V_159 [ V_134 ] ,
true ) ;
} else if ( V_135 == V_149 &&
V_136 == 0 ) {
if ( V_150 &&
! ( V_120 & V_151 ) )
F_103 ( 0 ) ;
} else if ( V_135 == V_149 &&
V_136 == 1 &&
V_152 &&
! V_153 ) {
V_120 = F_86 ( V_62 . V_142 . V_143 ,
V_120 ) ;
F_97 ( F_98 ( V_53 ) >=
F_90 ( V_6 -> V_14 . V_129 ) ) ;
V_6 -> V_14 . V_129 [ F_98 ( V_53 ) ] =
V_120 ;
} else if ( V_135 == V_149 &&
( V_136 == 2 ) &&
V_152 &&
! V_153 ) {
F_88 ( V_6 , V_120 ) ;
} else if ( V_135 == V_157 &&
( V_136 == 0 ) ) {
} else {
V_132 = V_138 ;
}
break;
default:
V_132 = V_138 ;
break;
}
}
if ( V_132 == V_138 ) {
F_84 ( L_3 ,
V_137 , V_164 , V_62 . V_96 ) ;
V_6 -> V_14 . V_93 = V_137 ;
}
return V_132 ;
}
static enum V_130 F_104 ( union V_61 V_62 ,
T_3 * V_90 , T_3 V_38 ,
struct V_131 * V_115 ,
struct V_5 * V_6 )
{
enum V_130 V_132 = V_133 ;
T_3 V_165 , V_166 , V_119 , V_167 ;
T_5 V_168 ;
struct V_169 * V_14 = & V_6 -> V_14 ;
unsigned long V_170 , V_137 ;
V_137 = V_6 -> V_14 . V_93 ;
V_132 = F_92 ( V_6 , V_38 ) ;
if ( V_132 == V_138 )
return V_132 ;
V_167 = V_62 . V_171 . V_143 ;
V_166 = V_62 . V_171 . V_134 ;
if ( V_172 )
V_168 = V_62 . V_63 . V_173 ;
else
V_168 = V_62 . V_171 . V_173 ;
V_165 = V_166 & V_174 ;
V_119 = V_166 & V_175 ;
V_170 = V_14 -> V_159 [ V_167 ] + V_168 ;
F_105 ( L_4 ,
V_165 , V_119 , V_167 , V_14 -> V_159 [ V_167 ] , V_168 ) ;
if ( V_165 != V_176 && V_165 != V_177 )
return V_133 ;
switch ( V_166 ) {
case V_178 :
F_106 ( V_170 ) ;
return V_133 ;
case V_179 :
F_107 ( V_170 ) ;
return V_133 ;
case V_180 :
case V_181 :
case V_182 :
if ( F_108 () == V_183 ) {
F_109 ( 0 , 0 ) ;
return V_133 ;
}
break;
default:
break;
} ;
F_84 ( L_5 ,
V_137 , V_6 -> V_14 . V_159 [ 31 ] , V_165 , V_119 , V_167 , V_14 -> V_159 [ V_167 ] ,
V_168 ) ;
V_6 -> V_14 . V_93 = V_137 ;
return V_138 ;
}
static enum V_130 F_110 ( T_3 V_38 , T_3 * V_90 ,
struct V_5 * V_6 )
{
enum V_130 V_132 = V_133 ;
struct V_169 * V_14 = & V_6 -> V_14 ;
struct V_131 * V_115 = V_6 -> V_115 ;
union V_61 V_62 ;
int V_135 , V_134 , V_136 ;
int V_86 ;
if ( V_38 & V_95 )
V_90 += 1 ;
V_86 = F_72 ( V_90 , V_6 , & V_62 . V_96 ) ;
if ( V_86 )
return V_138 ;
switch ( V_62 . V_184 . V_64 ) {
case V_185 :
V_132 = F_91 ( V_62 , V_90 , V_38 , V_115 , V_6 ) ;
break;
#ifndef F_111
case V_186 :
F_112 ( V_6 , V_187 ) ;
V_132 = F_104 ( V_62 , V_90 , V_38 , V_115 , V_6 ) ;
break;
#endif
case V_65 :
switch ( V_62 . V_63 . V_66 ) {
#ifdef F_111
case V_188 :
F_112 ( V_6 , V_187 ) ;
V_132 = F_104 ( V_62 , V_90 , V_38 , V_115 , V_6 ) ;
break;
#endif
case V_189 :
if ( V_62 . V_184 . V_143 || ( V_62 . V_184 . V_190 >> 3 ) )
goto V_191;
V_135 = V_62 . V_184 . V_135 ;
V_134 = V_62 . V_184 . V_134 ;
V_136 = V_62 . V_184 . V_190 & 0x7 ;
switch ( V_135 ) {
case V_192 :
V_14 -> V_159 [ V_134 ] =
( long ) ( int ) F_95 ( V_6 ) ;
break;
default:
F_99 ( V_6 , V_193 ,
F_113 ( V_135 , V_136 ) , 0 ) ;
goto V_191;
} ;
F_99 ( V_6 , V_193 ,
F_113 ( V_135 , V_136 ) , V_14 -> V_159 [ V_134 ] ) ;
V_132 = F_92 ( V_6 , V_38 ) ;
break;
default:
goto V_191;
} ;
break;
V_191:
default:
F_84 ( L_6 ,
V_90 , V_62 . V_96 ) ;
F_85 ( V_6 ) ;
V_132 = V_138 ;
break;
}
return V_132 ;
}
static enum V_130 F_114 ( T_3 V_38 , T_3 * V_90 ,
struct V_5 * V_6 )
{
enum V_130 V_132 = V_133 ;
struct V_169 * V_14 = & V_6 -> V_14 ;
union V_61 V_62 ;
int V_86 ;
if ( V_38 & V_95 )
V_90 += 1 ;
V_86 = F_72 ( V_90 , V_6 , & V_62 . V_96 ) ;
if ( V_86 )
return V_138 ;
if ( V_62 . V_142 . V_64 == V_185 &&
V_62 . V_142 . V_143 == V_126 &&
V_62 . V_142 . V_194 == 0 ) {
int V_134 = V_62 . V_142 . V_134 ;
int V_135 = V_62 . V_142 . V_135 ;
int V_136 = V_62 . V_142 . V_136 ;
unsigned int V_120 = V_14 -> V_159 [ V_134 ] ;
unsigned int V_195 , V_196 ;
F_99 ( V_6 , V_162 , F_100 ( V_135 , V_136 ) ,
V_120 ) ;
if ( ( V_135 == V_155 ) && ( V_136 == 0 ) ) {
if ( ! F_14 ( & V_6 -> V_14 ) )
V_120 &= ~ ( V_197 | V_198 ) ;
if ( ! ( V_199 . V_200 & V_201 ) )
V_120 &= ~ V_198 ;
V_195 = F_71 () ;
V_196 = V_120 ^ V_195 ;
if ( V_196 & V_198 ) {
F_115 ( V_6 ) ;
}
if ( V_196 & V_197 && ! ( V_120 & V_198 ) &&
V_6 -> V_14 . V_202 & V_203 )
F_116 ( V_6 ) ;
F_117 ( V_120 ) ;
} else if ( ( V_135 == V_204 ) && ( V_136 == 0 ) ) {
T_3 V_205 = F_59 () ;
T_3 V_196 = V_205 ^ V_120 ;
if ( V_196 & V_206 ) {
if ( V_120 & V_206 ) {
F_66 ( V_6 ) ;
F_118 ( V_6 ) ;
} else {
F_119 ( V_6 ) ;
}
}
V_196 &= ( V_206 | V_207 | V_208 |
V_209 | V_210 ) ;
V_196 &= ~ V_208 | V_205 ;
F_45 ( V_205 ^ V_196 ) ;
} else if ( ( V_135 == V_155 ) && ( V_136 == 1 ) ) {
F_120 ( V_120 ) ;
} else if ( ( V_135 == V_156 ) && ( V_136 == 5 ) ) {
V_195 = F_121 () ;
V_196 = V_120 ^ V_195 ;
F_67 () ;
if ( V_196 & V_19 &&
V_6 -> V_14 . V_202 & V_211 )
F_122 ( V_19 , V_120 ) ;
F_68 () ;
V_120 = V_195 ^
( V_196 & F_12 ( V_6 ) ) ;
F_123 ( V_120 ) ;
} else {
F_84 ( L_7 ,
V_90 , V_62 . V_96 ) ;
V_132 = V_138 ;
}
if ( V_132 != V_138 )
V_132 = F_92 ( V_6 , V_38 ) ;
} else {
F_84 ( L_8 ,
V_90 , V_62 . V_96 ) ;
V_132 = V_138 ;
}
return V_132 ;
}
static enum V_130 F_124 ( T_3 V_38 , T_3 * V_90 ,
struct V_5 * V_6 )
{
F_125 ( V_6 ) ;
return V_133 ;
}
static enum V_130 F_126 ( T_3 V_38 , T_3 * V_90 ,
struct V_5 * V_6 )
{
enum V_130 V_132 ;
union V_61 V_62 ;
unsigned long V_137 ;
int V_86 ;
if ( V_38 & V_95 )
V_90 += 1 ;
V_86 = F_72 ( V_90 , V_6 , & V_62 . V_96 ) ;
if ( V_86 )
return V_138 ;
V_137 = V_6 -> V_14 . V_93 ;
V_132 = F_92 ( V_6 , V_38 ) ;
if ( V_132 == V_138 )
return V_132 ;
V_132 = F_127 ( V_6 , V_62 ) ;
if ( V_132 == V_138 )
V_6 -> V_14 . V_93 = V_137 ;
return V_132 ;
}
static enum V_130 F_128 ( T_3 V_104 ,
T_3 V_38 ,
T_3 * V_90 ,
struct V_5 * V_6 )
{
T_3 V_62 ;
if ( V_38 & V_95 )
V_90 += 1 ;
F_72 ( V_90 , V_6 , & V_62 ) ;
F_84 ( L_9 ,
V_104 , V_90 , V_62 , F_71 () ) ;
return V_138 ;
}
static int F_129 ( struct V_5 * V_6 )
{
T_3 * V_90 = ( T_3 * ) V_6 -> V_14 . V_93 ;
T_3 V_38 = V_6 -> V_14 . V_94 ;
enum V_130 V_132 = V_133 ;
T_3 V_104 = ( V_6 -> V_14 . V_105 &
V_106 ) >> V_107 ;
int V_212 = V_213 ;
F_112 ( V_6 , V_214 + V_104 ) ;
switch ( V_104 ) {
case V_215 :
++ V_6 -> V_146 . V_216 ;
V_132 = F_110 ( V_38 , V_90 , V_6 ) ;
break;
case V_217 :
++ V_6 -> V_146 . V_218 ;
V_132 = F_114 ( V_38 , V_90 , V_6 ) ;
break;
case V_219 :
++ V_6 -> V_146 . V_220 ;
V_132 = F_126 ( V_38 , V_90 , V_6 ) ;
break;
case V_221 :
++ V_6 -> V_146 . V_222 ;
V_132 = F_128 ( V_104 , V_38 , V_90 ,
V_6 ) ;
break;
case V_109 :
++ V_6 -> V_146 . V_223 ;
V_132 = F_128 ( V_104 , V_38 , V_90 ,
V_6 ) ;
break;
case V_224 :
++ V_6 -> V_146 . V_225 ;
V_132 = F_124 ( V_38 , V_90 , V_6 ) ;
break;
case V_108 :
++ V_6 -> V_146 . V_226 ;
V_132 = F_128 ( V_104 , V_38 , V_90 ,
V_6 ) ;
break;
default:
++ V_6 -> V_146 . V_227 ;
V_132 = F_128 ( V_104 , V_38 , V_90 ,
V_6 ) ;
break;
}
if ( V_132 == V_133 ) {
V_212 = V_213 ;
} else if ( V_132 == V_228 ) {
V_212 = F_130 ( V_6 ) ;
} else {
V_6 -> V_115 -> V_116 = V_117 ;
V_212 = V_118 ;
}
return V_212 ;
}
static int F_131 ( struct V_5 * V_6 )
{
struct V_131 * V_115 = V_6 -> V_115 ;
T_3 V_38 = V_6 -> V_14 . V_94 ;
enum V_130 V_132 = V_138 ;
int V_212 = V_213 ;
if ( ( ( V_38 & V_229 ) >> V_230 ) == 1 ) {
if ( F_132 ( ! F_14 ( & V_6 -> V_14 ) ||
V_6 -> V_14 . V_202 & V_211 ) ) {
F_68 () ;
return V_138 ;
}
F_133 ( V_6 ) ;
V_132 = V_133 ;
}
switch ( V_132 ) {
case V_133 :
V_212 = V_213 ;
break;
case V_138 :
V_115 -> V_116 = V_117 ;
V_212 = V_118 ;
break;
default:
F_134 () ;
}
return V_212 ;
}
static int F_135 ( struct V_5 * V_6 )
{
struct V_131 * V_115 = V_6 -> V_115 ;
if ( ! F_13 ( & V_6 -> V_14 ) ||
( F_71 () & ( V_197 | V_198 ) ) == V_197 ||
! ( F_121 () & V_15 ) ||
V_6 -> V_14 . V_202 & V_203 ) {
V_115 -> V_116 = V_117 ;
return V_118 ;
}
F_136 ( V_6 ) ;
return V_213 ;
}
static int F_137 ( struct V_5 * V_6 )
{
struct V_131 * V_115 = V_6 -> V_115 ;
T_3 * V_90 = ( T_3 * ) V_6 -> V_14 . V_93 ;
T_3 V_38 = V_6 -> V_14 . V_94 ;
T_6 V_103 = V_6 -> V_14 . V_114 ;
union V_61 V_62 ;
enum V_130 V_132 = V_133 ;
int V_86 , V_212 = V_213 ;
if ( F_138 ( V_103 , V_6 , false ) ) {
if ( F_139 ( & V_6 -> V_14 ) ) {
V_115 -> V_116 = V_117 ;
return V_118 ;
}
if ( V_38 & V_95 )
V_90 += 1 ;
V_86 = F_72 ( V_90 , V_6 , & V_62 . V_96 ) ;
if ( V_86 ) {
V_115 -> V_116 = V_117 ;
return V_118 ;
}
V_132 = F_140 ( V_62 , V_38 , V_115 , V_6 ) ;
if ( V_132 == V_138 ) {
F_84 ( L_10 ,
V_90 , V_103 ) ;
V_115 -> V_116 = V_117 ;
}
}
if ( V_132 == V_133 ) {
V_212 = V_213 ;
} else if ( V_132 == V_231 ) {
V_115 -> V_116 = V_232 ;
V_212 = V_118 ;
} else {
V_115 -> V_116 = V_117 ;
V_212 = V_118 ;
}
return V_212 ;
}
static int F_141 ( struct V_5 * V_6 )
{
struct V_131 * V_115 = V_6 -> V_115 ;
T_3 * V_90 = ( T_3 * ) V_6 -> V_14 . V_93 ;
T_3 V_38 = V_6 -> V_14 . V_94 ;
T_6 V_103 = V_6 -> V_14 . V_114 ;
union V_61 V_62 ;
enum V_130 V_132 = V_133 ;
int V_86 ;
int V_212 = V_213 ;
if ( F_80 ( V_6 , V_103 , & V_103 ) )
return V_213 ;
V_6 -> V_14 . V_114 = V_103 ;
if ( F_138 ( V_103 , V_6 , true ) ) {
if ( V_38 & V_95 )
V_90 += 1 ;
V_86 = F_72 ( V_90 , V_6 , & V_62 . V_96 ) ;
if ( V_86 ) {
V_115 -> V_116 = V_117 ;
return V_118 ;
}
V_132 = F_142 ( V_62 , V_38 , V_115 , V_6 ) ;
if ( V_132 == V_138 ) {
F_84 ( L_11 ,
V_90 , V_103 ) ;
V_115 -> V_116 = V_117 ;
}
}
if ( V_132 == V_133 ) {
V_212 = V_213 ;
} else if ( V_132 == V_231 ) {
V_115 -> V_116 = V_232 ;
V_212 = V_118 ;
} else {
V_115 -> V_116 = V_117 ;
V_212 = V_118 ;
}
return V_212 ;
}
static unsigned long F_143 ( struct V_5 * V_6 )
{
unsigned long V_212 ;
V_212 = F_90 ( V_233 ) ;
if ( V_234 )
++ V_212 ;
if ( V_235 )
++ V_212 ;
if ( V_236 )
++ V_212 ;
if ( V_237 )
V_212 += F_90 ( V_238 ) ;
if ( V_100 )
V_212 += F_90 ( V_239 ) ;
if ( V_240 )
V_212 += F_90 ( V_241 ) ;
if ( V_152 && ! V_153 )
V_212 += 1 + F_90 ( V_6 -> V_14 . V_129 ) ;
V_212 += F_144 ( V_242 [ 0 ] . V_243 . V_244 ) ;
return V_212 ;
}
static int F_145 ( struct V_5 * V_6 , T_7 T_8 * V_245 )
{
T_7 V_246 ;
unsigned int V_247 ;
if ( F_146 ( V_245 , V_233 ,
sizeof( V_233 ) ) )
return - V_248 ;
V_245 += F_90 ( V_233 ) ;
if ( V_234 ) {
V_246 = V_249 ;
if ( F_146 ( V_245 , & V_246 , sizeof( V_246 ) ) )
return - V_248 ;
++ V_245 ;
}
if ( V_235 ) {
V_246 = V_250 ;
if ( F_146 ( V_245 , & V_246 , sizeof( V_246 ) ) )
return - V_248 ;
++ V_245 ;
}
if ( V_236 ) {
V_246 = V_251 ;
if ( F_146 ( V_245 , & V_246 , sizeof( V_246 ) ) )
return - V_248 ;
++ V_245 ;
}
if ( V_237 ) {
if ( F_146 ( V_245 , V_238 ,
sizeof( V_238 ) ) )
return - V_248 ;
V_245 += F_90 ( V_238 ) ;
}
if ( V_100 ) {
if ( F_146 ( V_245 , V_239 ,
sizeof( V_239 ) ) )
return - V_248 ;
V_245 += F_90 ( V_239 ) ;
}
if ( V_240 ) {
if ( F_146 ( V_245 , V_241 ,
sizeof( V_241 ) ) )
return - V_248 ;
V_245 += F_90 ( V_241 ) ;
}
if ( V_152 && ! V_153 ) {
for ( V_247 = 0 ; V_247 < F_90 ( V_6 -> V_14 . V_129 ) ; ++ V_247 ) {
V_246 = F_147 ( V_247 ) ;
if ( F_146 ( V_245 , & V_246 , sizeof( V_246 ) ) )
return - V_248 ;
++ V_245 ;
}
V_246 = V_252 ;
if ( F_146 ( V_245 , & V_246 , sizeof( V_246 ) ) )
return - V_248 ;
++ V_245 ;
}
for ( V_247 = 0 ; V_247 < 6 ; ++ V_247 ) {
if ( ! F_148 ( V_247 + 2 ) )
continue;
if ( F_146 ( V_245 , & V_253 [ V_247 ] ,
sizeof( V_253 [ V_247 ] ) ) )
return - V_248 ;
++ V_245 ;
}
return 0 ;
}
static inline T_9 F_149 ( unsigned long V_2 )
{
T_9 V_10 , V_212 = V_2 ;
if ( V_254 == 32 ) {
V_10 = V_255 | V_256 ;
V_212 &= ~ V_10 ;
V_212 |= ( ( T_9 ) V_2 & V_10 ) << 32 ;
}
return V_212 ;
}
static inline unsigned long F_150 ( T_9 V_2 )
{
unsigned long V_10 , V_212 = V_2 ;
if ( V_254 == 32 ) {
V_10 = V_255 | V_256 ;
V_212 &= ~ V_10 ;
V_212 |= ( V_2 >> 32 ) & V_10 ;
}
return V_212 ;
}
static int F_151 ( struct V_5 * V_6 ,
const struct V_257 * V_158 ,
T_9 * V_2 )
{
struct V_52 * V_53 = V_6 -> V_14 . V_53 ;
unsigned int V_258 ;
switch ( V_158 -> V_259 ) {
case V_260 :
* V_2 = ( long ) F_152 () ;
break;
case V_261 :
* V_2 = F_149 ( F_153 () ) ;
break;
case V_262 :
* V_2 = F_149 ( F_154 () ) ;
break;
case V_263 :
* V_2 = ( long ) F_155 () ;
break;
case V_264 :
if ( ! V_237 )
return - V_110 ;
* V_2 = F_156 () ;
break;
case V_249 :
if ( ! V_234 )
return - V_110 ;
* V_2 = F_157 () ;
break;
#ifdef F_78
case V_265 :
if ( ! V_237 )
return - V_110 ;
* V_2 = F_158 () ;
break;
#endif
case V_266 :
* V_2 = ( long ) F_159 () ;
break;
case V_267 :
* V_2 = ( long ) F_87 () ;
break;
case V_268 :
if ( ! V_100 )
return - V_110 ;
* V_2 = F_76 () ;
break;
case V_269 :
if ( ! V_100 )
return - V_110 ;
* V_2 = F_75 () ;
break;
case V_270 :
if ( ! V_100 )
return - V_110 ;
* V_2 = F_74 () ;
break;
case V_271 :
if ( ! V_240 )
return - V_110 ;
* V_2 = F_160 () ;
break;
case V_272 :
if ( ! V_240 )
return - V_110 ;
* V_2 = F_161 () ;
break;
case V_273 :
if ( ! V_240 )
return - V_110 ;
* V_2 = F_162 () ;
break;
case V_274 :
* V_2 = ( long ) F_163 () ;
break;
case V_275 :
if ( ! V_240 )
return - V_110 ;
* V_2 = F_164 () ;
break;
case V_276 :
* V_2 = ( long ) F_165 () ;
break;
case V_277 :
* V_2 = ( long ) F_166 () ;
break;
case V_250 :
if ( ! V_235 )
return - V_110 ;
* V_2 = F_167 () ;
break;
case V_251 :
if ( ! V_236 )
return - V_110 ;
* V_2 = F_168 () ;
break;
case V_278 :
* V_2 = F_95 ( V_6 ) ;
break;
case V_279 :
* V_2 = ( long ) F_169 () ;
break;
case V_280 :
* V_2 = ( long ) F_58 () ;
break;
case V_281 :
* V_2 = ( long ) F_71 () ;
break;
case V_282 :
* V_2 = F_170 () ;
break;
case V_283 :
* V_2 = ( long ) F_59 () ;
break;
case V_284 :
* V_2 = ( long ) F_171 () ;
break;
case V_285 :
switch ( F_108 () ) {
case V_183 :
* V_2 = F_172 () ;
break;
default:
* V_2 = ( long ) F_173 ( V_53 ) ;
break;
} ;
break;
case V_286 :
* V_2 = F_1 () ;
break;
case V_287 :
* V_2 = F_174 () ;
break;
case V_288 :
if ( ! V_289 )
return - V_110 ;
* V_2 = F_175 () ;
break;
case V_290 :
if ( ! V_291 )
return - V_110 ;
* V_2 = F_176 () ;
break;
case V_292 :
if ( ! V_293 )
return - V_110 ;
* V_2 = F_177 () ;
break;
case V_294 :
if ( ! V_295 )
return - V_110 ;
* V_2 = F_178 () ;
break;
case V_296 :
if ( ! V_297 )
return - V_110 ;
* V_2 = F_121 () ;
break;
case F_147 ( 0 ) ... F_147 ( 0x3f ) :
if ( ! V_152 || V_153 )
return - V_110 ;
V_258 = V_158 -> V_259 - F_147 ( 0 ) ;
if ( V_258 >= F_90 ( V_6 -> V_14 . V_129 ) )
return - V_110 ;
* V_2 = V_6 -> V_14 . V_129 [ V_258 ] ;
break;
case V_252 :
if ( ! V_152 || V_153 )
return - V_110 ;
* V_2 = F_98 ( V_6 -> V_14 . V_53 ) ;
break;
#ifdef F_78
case V_298 :
* V_2 = F_179 () ;
break;
#endif
case V_299 :
* V_2 = ( long ) F_180 () ;
break;
case V_300 ... V_301 :
V_258 = V_158 -> V_259 - V_300 + 2 ;
if ( ! F_148 ( V_258 ) )
return - V_110 ;
switch ( V_258 ) {
case 2 :
* V_2 = ( long ) F_181 () ;
break;
case 3 :
* V_2 = ( long ) F_182 () ;
break;
case 4 :
* V_2 = ( long ) F_183 () ;
break;
case 5 :
* V_2 = ( long ) F_184 () ;
break;
case 6 :
* V_2 = ( long ) F_185 () ;
break;
case 7 :
* V_2 = ( long ) F_186 () ;
break;
}
break;
case V_302 :
* V_2 = V_6 -> V_14 . V_303 ;
break;
case V_304 :
* V_2 = F_187 ( V_6 -> V_14 . V_305 ) ;
break;
case V_306 :
* V_2 = V_6 -> V_14 . V_44 ;
break;
default:
return - V_110 ;
}
return 0 ;
}
static int F_188 ( struct V_5 * V_6 ,
const struct V_257 * V_158 ,
T_9 V_2 )
{
struct V_52 * V_53 = V_6 -> V_14 . V_53 ;
unsigned int V_258 ;
int V_212 = 0 ;
unsigned int V_307 , V_196 ;
switch ( V_158 -> V_259 ) {
case V_260 :
F_189 ( V_2 ) ;
break;
case V_261 :
F_190 ( F_150 ( V_2 ) ) ;
break;
case V_262 :
F_191 ( F_150 ( V_2 ) ) ;
break;
case V_263 :
F_192 ( V_2 ) ;
break;
case V_264 :
if ( ! V_237 )
return - V_110 ;
F_193 ( V_2 ) ;
break;
case V_249 :
if ( ! V_234 )
return - V_110 ;
F_194 ( V_2 ) ;
break;
#ifdef F_78
case V_265 :
if ( ! V_237 )
return - V_110 ;
F_195 ( V_2 ) ;
break;
#endif
case V_266 :
F_196 ( V_2 ) ;
break;
case V_267 :
F_197 ( V_2 ) ;
break;
case V_268 :
if ( ! V_100 )
return - V_110 ;
F_198 ( V_2 ) ;
break;
case V_269 :
if ( ! V_100 )
return - V_110 ;
F_199 ( V_2 ) ;
break;
case V_270 :
if ( ! V_100 )
return - V_110 ;
F_200 ( V_2 ) ;
break;
case V_271 :
if ( ! V_240 )
return - V_110 ;
F_201 ( V_2 ) ;
break;
case V_272 :
if ( ! V_240 )
return - V_110 ;
F_202 ( V_2 ) ;
break;
case V_273 :
if ( ! V_240 )
return - V_110 ;
F_203 ( V_2 ) ;
break;
case V_274 :
F_204 ( V_308 , V_2 ) ;
break;
case V_275 :
if ( ! V_240 )
return - V_110 ;
F_205 ( V_2 ) ;
break;
case V_276 :
F_206 ( V_2 ) ;
break;
case V_277 :
F_207 ( V_2 ) ;
break;
case V_250 :
if ( ! V_235 )
return - V_110 ;
F_208 ( V_2 ) ;
break;
case V_251 :
if ( ! V_236 )
return - V_110 ;
F_209 ( V_2 ) ;
break;
case V_278 :
F_101 ( V_6 , V_2 ) ;
break;
case V_279 :
F_210 ( V_2 ) ;
break;
case V_280 :
F_102 ( V_6 , V_2 , false ) ;
break;
case V_281 :
F_117 ( V_2 ) ;
break;
case V_282 :
F_120 ( V_2 ) ;
break;
case V_283 :
if ( ( F_59 () ^ V_2 ) & V_206 ) {
if ( V_2 & V_206 ) {
F_118 ( V_6 ) ;
F_211 ( ( T_3 ) ~ V_206 , V_2 ) ;
} else {
F_211 ( ( T_3 ) ~ V_206 , V_2 ) ;
F_119 ( V_6 ) ;
}
} else {
F_45 ( V_2 ) ;
}
break;
case V_284 :
F_212 ( V_2 ) ;
break;
case V_285 :
switch ( F_108 () ) {
case V_183 :
break;
default:
F_213 ( V_53 , V_2 ) ;
break;
} ;
break;
case V_286 :
F_4 ( V_2 ) ;
break;
case V_287 :
V_307 = F_174 () ;
V_196 = ( V_307 ^ V_2 ) & F_15 ( V_6 ) ;
if ( V_196 ) {
V_2 = V_307 ^ V_196 ;
F_214 ( V_2 ) ;
}
break;
case V_288 :
if ( ! V_289 )
break;
V_307 = F_175 () ;
V_196 = ( V_307 ^ V_2 ) & F_16 ( V_6 ) ;
if ( V_196 ) {
V_2 = V_307 ^ V_196 ;
F_215 ( V_2 ) ;
}
break;
case V_290 :
if ( ! V_291 )
break;
V_307 = F_176 () ;
V_196 = ( V_307 ^ V_2 ) & F_18 ( V_6 ) ;
if ( V_196 ) {
V_2 = V_307 ^ V_196 ;
F_216 ( V_2 ) ;
}
break;
case V_292 :
if ( ! V_293 )
break;
V_307 = F_177 () ;
V_196 = ( V_307 ^ V_2 ) & F_19 ( V_6 ) ;
if ( V_196 ) {
V_2 = V_307 ^ V_196 ;
F_217 ( V_2 ) ;
}
break;
case V_294 :
if ( ! V_295 )
break;
V_307 = F_178 () ;
V_196 = ( V_307 ^ V_2 ) & F_21 ( V_6 ) ;
if ( V_196 ) {
V_2 = V_307 ^ V_196 ;
F_218 ( V_2 ) ;
}
break;
case V_296 :
if ( ! V_297 )
break;
V_307 = F_121 () ;
V_196 = ( V_307 ^ V_2 ) & F_22 ( V_6 ) ;
if ( V_196 ) {
V_2 = V_307 ^ V_196 ;
F_123 ( V_2 ) ;
}
break;
case F_147 ( 0 ) ... F_147 ( 0x3f ) :
if ( ! V_152 || V_153 )
return - V_110 ;
V_258 = V_158 -> V_259 - F_147 ( 0 ) ;
if ( V_258 >= F_90 ( V_6 -> V_14 . V_129 ) )
return - V_110 ;
V_6 -> V_14 . V_129 [ V_258 ] = F_86 ( V_127 , V_2 ) ;
break;
case V_252 :
if ( ! V_152 || V_153 )
return - V_110 ;
F_88 ( V_6 , V_2 ) ;
break;
#ifdef F_78
case V_298 :
F_219 ( V_2 ) ;
break;
#endif
case V_299 :
F_220 ( V_2 ) ;
break;
case V_300 ... V_301 :
V_258 = V_158 -> V_259 - V_300 + 2 ;
if ( ! F_148 ( V_258 ) )
return - V_110 ;
switch ( V_258 ) {
case 2 :
F_221 ( V_2 ) ;
break;
case 3 :
F_222 ( V_2 ) ;
break;
case 4 :
F_223 ( V_2 ) ;
break;
case 5 :
F_224 ( V_2 ) ;
break;
case 6 :
F_225 ( V_2 ) ;
break;
case 7 :
F_226 ( V_2 ) ;
break;
}
break;
case V_302 :
V_212 = F_227 ( V_6 , V_2 ) ;
break;
case V_304 :
V_212 = F_228 ( V_6 , V_2 ) ;
break;
case V_306 :
V_212 = F_229 ( V_6 , V_2 ) ;
break;
default:
return - V_110 ;
}
return V_212 ;
}
static void F_230 ( unsigned long V_309 , struct V_5 * V_6 )
{
unsigned long V_310 = F_231 ( V_309 ) ;
if ( ! ( ++ V_310 & V_311 ) ) {
if ( V_312 )
F_232 () ;
if ( ! V_310 )
V_310 = V_313 ;
++ V_310 ;
F_233 () ;
F_234 () ;
}
F_231 ( V_309 ) = V_310 ;
}
static int F_235 ( struct V_5 * V_6 , int V_309 )
{
int V_212 = 0 ;
int V_247 ;
if ( ! V_6 -> V_314 )
return 0 ;
if ( F_236 ( V_315 , V_6 ) ) {
if ( V_316 ) {
F_237 (i)
V_6 -> V_14 . V_317 [ V_247 ] = 0 ;
V_212 = 1 ;
}
}
return V_212 ;
}
static void F_238 ( struct V_5 * V_6 )
{
unsigned int V_318 = F_163 () ;
struct V_319 * V_320 ;
int V_247 ;
V_318 &= V_308 ;
if ( V_318 > V_6 -> V_14 . V_321 ) {
V_320 = F_239 ( V_6 -> V_14 . V_322 , V_318 *
sizeof( * V_6 -> V_14 . V_322 ) , V_323 ) ;
if ( F_132 ( ! V_320 ) ) {
V_318 = V_6 -> V_14 . V_321 ;
} else {
V_6 -> V_14 . V_322 = V_320 ;
V_6 -> V_14 . V_321 = V_318 ;
}
}
if ( V_318 )
F_240 ( V_6 -> V_14 . V_322 , 0 , V_318 ) ;
for ( V_247 = V_318 ; V_247 < V_6 -> V_14 . V_324 ; ++ V_247 ) {
V_6 -> V_14 . V_322 [ V_247 ] . V_325 = F_241 ( V_247 ) ;
V_6 -> V_14 . V_322 [ V_247 ] . V_326 [ 0 ] = 0 ;
V_6 -> V_14 . V_322 [ V_247 ] . V_326 [ 1 ] = 0 ;
V_6 -> V_14 . V_322 [ V_247 ] . V_327 = 0 ;
}
V_6 -> V_14 . V_324 = V_318 ;
}
static void F_242 ( struct V_5 * V_6 )
{
if ( V_6 -> V_14 . V_322 )
F_243 ( V_6 -> V_14 . V_322 , 0 ,
V_6 -> V_14 . V_324 ) ;
}
static void F_244 ( struct V_5 * V_6 , int V_309 )
{
struct V_328 * V_328 = V_6 -> V_328 ;
struct V_329 * V_330 = & V_328 -> V_14 . V_330 ;
bool V_331 ;
V_331 = ( V_6 -> V_14 . V_332 != V_309 ) ;
V_6 -> V_14 . V_332 = V_309 ;
if ( V_316 ) {
if ( V_331 ||
( V_6 -> V_14 . V_317 [ V_309 ] ^ F_231 ( V_309 ) ) &
V_333 ) {
F_230 ( V_309 , V_6 ) ;
V_6 -> V_14 . V_317 [ V_309 ] = F_231 ( V_309 ) ;
F_245 ( V_6 ,
V_6 -> V_14 . V_317 [ V_309 ] ) ;
}
F_246 ( V_311 , V_6 -> V_14 . V_317 [ V_309 ] ) ;
} else {
if ( V_331 || V_334 [ V_309 ] != V_6 )
F_234 () ;
V_334 [ V_309 ] = V_6 ;
if ( F_247 ( V_309 , & V_328 -> V_14 . V_335 )
|| ( F_248 ( V_309 , V_330 ) ^ F_249 ( V_309 ) ) &
F_250 ( V_309 ) )
F_251 ( V_330 , V_309 ) ;
}
}
static int F_252 ( struct V_5 * V_6 , int V_309 )
{
struct V_52 * V_53 = V_6 -> V_14 . V_53 ;
bool V_331 , V_336 ;
V_331 = ( V_6 -> V_14 . V_337 != V_309 ) ;
V_336 = V_331 || ( V_338 [ V_309 ] != V_6 ) ;
V_338 [ V_309 ] = V_6 ;
F_253 ( V_53 ) ;
if ( V_339 -> V_51 & V_340 ) {
F_254 () ;
F_244 ( V_6 , V_309 ) ;
F_242 ( V_6 ) ;
}
F_51 ( V_6 ) ;
if ( V_341 )
F_255 ( V_342 ) ;
else
F_256 ( V_342 ) ;
if ( ! V_336 )
return 0 ;
F_257 ( V_53 ) ;
if ( V_289 )
F_258 ( V_53 ) ;
if ( V_291 )
F_259 ( V_53 ) ;
if ( V_293 )
F_260 ( V_53 ) ;
if ( V_295 )
F_261 ( V_53 ) ;
if ( V_297 )
F_262 ( V_53 ) ;
if ( V_343 )
F_263 ( V_53 ) ;
if ( V_344 )
F_264 ( V_53 ) ;
F_265 ( V_53 ) ;
F_266 ( V_53 ) ;
F_267 ( V_53 ) ;
F_268 ( V_53 ) ;
if ( V_237 )
F_269 ( V_53 ) ;
#ifdef F_78
F_270 ( V_53 ) ;
if ( V_237 )
F_271 ( V_53 ) ;
#endif
F_272 ( V_53 ) ;
F_273 ( V_53 ) ;
F_274 ( V_53 ) ;
F_275 ( V_53 ) ;
F_276 ( V_53 ) ;
F_277 ( V_53 ) ;
F_278 ( V_53 ) ;
F_279 ( V_53 ) ;
F_4 ( F_280 ( V_53 ) ) ;
if ( V_234 )
F_281 ( V_53 ) ;
F_282 ( V_53 ) ;
if ( V_295 ) {
if ( F_148 ( 2 ) )
F_283 ( V_53 ) ;
if ( F_148 ( 3 ) )
F_284 ( V_53 ) ;
if ( F_148 ( 4 ) )
F_285 ( V_53 ) ;
if ( F_148 ( 5 ) )
F_286 ( V_53 ) ;
if ( F_148 ( 6 ) )
F_287 ( V_53 ) ;
if ( F_148 ( 7 ) )
F_288 ( V_53 ) ;
}
if ( V_235 )
F_289 ( V_53 ) ;
if ( V_236 )
F_290 ( V_53 ) ;
if ( V_100 ) {
F_291 ( V_53 ) ;
F_292 ( V_53 ) ;
F_293 ( V_53 ) ;
}
if ( V_240 ) {
F_294 ( V_53 ) ;
F_295 ( V_53 ) ;
F_296 ( V_53 ) ;
F_297 ( V_53 ) ;
}
if ( V_42 )
F_298 (
V_53 -> V_158 [ V_345 ] [ V_346 ] ) ;
if ( V_150 )
F_103 ( 0 ) ;
return 0 ;
}
static int F_299 ( struct V_5 * V_6 , int V_309 )
{
struct V_52 * V_53 = V_6 -> V_14 . V_53 ;
if ( V_339 -> V_51 & V_340 )
F_238 ( V_6 ) ;
F_116 ( V_6 ) ;
F_300 ( V_53 ) ;
F_301 ( V_53 ) ;
F_302 ( V_53 ) ;
F_303 ( V_53 ) ;
if ( V_237 )
F_304 ( V_53 ) ;
#ifdef F_78
F_305 ( V_53 ) ;
if ( V_237 )
F_306 ( V_53 ) ;
#endif
F_307 ( V_53 ) ;
F_308 ( V_53 ) ;
F_309 ( V_53 ) ;
F_310 ( V_308 ) ;
F_311 ( V_53 ) ;
F_312 ( V_53 ) ;
F_313 ( V_53 ) ;
F_314 ( V_53 ) ;
F_315 ( V_53 ) ;
F_316 ( V_53 ) ;
F_317 ( V_53 , F_1 () ) ;
if ( V_234 )
F_318 ( V_53 ) ;
F_319 ( V_53 ) ;
if ( V_289 )
F_320 ( V_53 ) ;
if ( V_291 )
F_321 ( V_53 ) ;
if ( V_293 )
F_322 ( V_53 ) ;
if ( V_295 )
F_323 ( V_53 ) ;
if ( V_297 )
F_324 ( V_53 ) ;
if ( V_343 )
F_325 ( V_53 ) ;
if ( V_344 )
F_326 ( V_53 ) ;
F_327 ( V_53 ) ;
if ( V_295 ) {
if ( F_148 ( 2 ) )
F_328 ( V_53 ) ;
if ( F_148 ( 3 ) )
F_329 ( V_53 ) ;
if ( F_148 ( 4 ) )
F_330 ( V_53 ) ;
if ( F_148 ( 5 ) )
F_331 ( V_53 ) ;
if ( F_148 ( 6 ) )
F_332 ( V_53 ) ;
if ( F_148 ( 7 ) )
F_333 ( V_53 ) ;
}
if ( V_235 )
F_334 ( V_53 ) ;
if ( V_236 )
F_335 ( V_53 ) ;
if ( V_100 ) {
F_336 ( V_53 ) ;
F_337 ( V_53 ) ;
F_338 ( V_53 ) ;
}
if ( V_240 &&
F_339 ( V_53 ) & V_347 ) {
F_340 ( V_53 ) ;
F_341 ( V_53 ) ;
F_342 ( V_53 ) ;
F_343 ( V_53 ) ;
}
F_63 ( V_6 ) ;
if ( V_42 )
V_53 -> V_158 [ V_345 ] [ V_346 ] =
F_36 () ;
return 0 ;
}
static unsigned int F_344 ( unsigned int V_348 )
{
unsigned int V_349 = 0 , V_212 = 0 , V_350 ;
if ( V_289 )
F_345 ( V_351 ,
( V_348 - 1 ) << V_352 ) ;
if ( V_295 ) {
V_349 = F_178 () ;
if ( V_172 || ( V_349 & V_353 ) ==
V_354 ) {
V_349 &= ~ V_355 ;
V_349 |= ( ( V_348 - 1 ) >> V_356 ) <<
V_357 ;
} else if ( ( V_349 & V_353 ) ==
V_358 ) {
V_349 &= ~ V_359 ;
V_349 |= ( ( V_348 - 1 ) >> V_356 ) <<
V_360 ;
}
F_218 ( V_349 ) ;
}
if ( V_172 ) {
V_350 = ( F_346 () & V_361 ) >>
V_362 ;
if ( V_348 - 1 <= V_350 )
V_350 = 0 ;
F_347 ( V_350 << V_362 ) ;
}
F_44 () ;
if ( V_289 )
V_212 = ( F_175 () & V_351 ) >>
V_352 ;
if ( V_349 ) {
if ( V_172 || ( V_349 & V_353 ) ==
V_354 )
V_212 |= ( ( V_349 & V_355 ) >>
V_357 ) <<
V_356 ;
else if ( ( V_349 & V_353 ) ==
V_358 )
V_212 |= ( ( V_349 & V_359 ) >>
V_360 ) <<
V_356 ;
}
return V_212 + 1 ;
}
static int F_348 ( void )
{
unsigned int V_363 , V_364 , V_365 ;
T_7 V_366 , V_367 ;
switch ( F_349 () ) {
case V_183 :
V_366 = F_350 () ;
V_366 &= ~ V_368 ;
V_366 |= 7ull << V_369 ;
V_366 &= ~ V_370 ;
V_366 |= 6ull << V_371 ;
F_351 ( V_366 ) ;
V_367 = F_352 () ;
V_367 |= V_372 ;
V_363 = ( ( V_367 & V_373 )
>> V_374 ) + 1 ;
V_364 = V_363 / 2 ;
V_363 -= V_364 ;
V_367 &= ~ V_375 ;
V_367 |= V_363 - 1 ;
F_353 ( V_367 ) ;
V_45 . V_376 = V_363 ;
V_45 . V_377 = V_363 ;
V_45 . V_243 . V_376 = V_364 ;
F_234 () ;
break;
default:
V_363 = V_45 . V_377 ;
V_365 = V_45 . V_376 - V_363 ;
V_364 = F_344 ( V_363 ) ;
V_45 . V_243 . V_376 = V_364 + V_365 ;
F_234 () ;
V_364 = V_363 - F_354 () - 2 ;
V_364 = F_344 ( V_364 ) ;
V_45 . V_243 . V_376 = V_364 + V_365 ;
if ( F_355 ( & V_378 , 0 , V_364 ) &&
F_82 ( V_364 != V_378 ,
L_12 ) )
return - V_110 ;
break;
}
F_57 ( V_379 |
( V_380 << V_381 ) |
V_382 | V_383 ) ;
if ( V_384 )
F_356 ( V_385 ) ;
if ( V_316 ) {
F_357 ( 0 ) ;
F_233 () ;
V_311 = V_45 . V_386 ;
V_313 = V_311 + 1 ;
V_333 = ~ V_311 ;
V_45 . F_231 = V_313 ;
}
if ( V_42 )
F_37 ( 0x3f << 10 ) ;
return 0 ;
}
static void F_358 ( void )
{
T_7 V_367 ;
unsigned int V_363 ;
F_234 () ;
switch ( F_349 () ) {
case V_183 :
V_367 = F_352 () ;
V_363 = ( ( V_367 & V_373 )
>> V_374 ) + 1 ;
V_367 &= ~ V_375 ;
V_367 |= V_363 - 1 ;
F_353 ( V_367 ) ;
V_45 . V_376 = V_363 ;
V_45 . V_377 = V_363 ;
V_45 . V_243 . V_376 = 0 ;
F_359 () ;
break;
}
if ( V_316 ) {
F_357 ( 0 ) ;
F_233 () ;
}
}
static int F_360 ( struct V_328 * V_328 , long V_387 )
{
int V_388 ;
switch ( V_387 ) {
case V_389 :
V_388 = 1 ;
break;
#ifdef F_78
case V_390 :
V_388 = 2 ;
break;
#endif
default:
V_388 = 0 ;
break;
}
return V_388 ;
}
static int F_361 ( struct V_5 * V_6 )
{
int V_247 ;
F_237 (i)
V_6 -> V_14 . V_317 [ V_247 ] = 0 ;
return 0 ;
}
static void F_362 ( struct V_5 * V_6 )
{
int V_309 ;
F_237 (cpu) {
if ( V_338 [ V_309 ] == V_6 )
V_338 [ V_309 ] = NULL ;
if ( V_334 [ V_309 ] == V_6 )
V_334 [ V_309 ] = NULL ;
}
}
static int F_363 ( struct V_5 * V_6 )
{
struct V_52 * V_53 = V_6 -> V_14 . V_53 ;
unsigned long V_44 = 100 * 1000 * 1000 ;
if ( V_43 && V_43 <= V_391 )
V_44 = V_43 ;
F_364 ( V_6 , V_44 ) ;
if ( V_172 )
F_365 ( V_53 , V_392 | V_393 | V_394 ) ;
if ( V_172 )
F_366 ( V_53 ,
F_163 () & V_361 ) ;
F_367 ( V_53 , V_395 | V_88 ) ;
if ( V_172 )
F_368 ( V_53 , V_198 , F_71 () ) ;
F_369 ( V_53 , F_170 () &
( V_396 | V_397 | V_398 ) ) ;
F_370 ( V_53 , V_199 . V_399 ) ;
F_317 ( V_53 , ( V_87 ) 0x80000000 | V_6 -> V_400 ) ;
F_319 ( V_53 ) ;
F_371 ( V_53 , V_7 ,
V_401 >> V_402 ) ;
F_371 ( V_53 , V_403 , F_372 () ) ;
if ( V_289 ) {
F_373 ( V_53 , V_21 ) ;
F_320 ( V_53 ) ;
F_374 ( V_53 , V_404 |
V_405 |
V_406 |
V_407 |
V_408 |
V_22 ) ;
}
if ( V_291 ) {
F_375 ( V_53 , V_21 ) ;
F_321 ( V_53 ) ;
}
if ( V_293 ) {
F_376 ( V_53 , V_21 ) ;
F_322 ( V_53 ) ;
F_377 ( V_53 , V_8 ) ;
F_377 ( V_53 , V_25 |
V_409 |
V_23 |
V_410 |
V_24 |
V_411 |
V_412 |
V_413 |
V_414 |
V_415 |
V_416 |
V_417 |
V_418 |
V_419 ) ;
}
if ( V_295 ) {
F_378 ( V_53 , V_21 ) ;
F_323 ( V_53 ) ;
}
if ( V_297 ) {
F_379 ( V_53 , V_21 ) ;
F_324 ( V_53 ) ;
F_380 ( V_53 , V_11 |
V_12 |
V_15 |
V_20 |
V_19 |
V_13 |
V_17 ) ;
F_380 ( V_53 , V_26 ) ;
}
if ( V_237 ) {
F_381 ( V_53 , 0x007ffff0 ) ;
#ifdef F_78
F_382 ( V_53 ,
( ( 1ull << ( V_420 - 13 ) ) - 1 ) << 4 ) ;
#endif
}
if ( V_100 ) {
F_383 ( V_53 , 0x00200010 ) ;
F_384 ( V_53 , 0x00000002 |
( V_401 >> V_402 ) <<
( 16 + V_421 ) ) ;
F_385 ( V_53 , 0x00380438 ) ;
}
if ( V_240 && V_172 ) {
F_386 ( V_53 , 0x0c30c302 ) ;
F_387 ( V_53 , 1 << V_422 ) ;
}
if ( V_42 )
V_53 -> V_158 [ V_345 ] [ V_346 ] = 0 ;
V_6 -> V_14 . V_93 = F_388 ( 0x1fc00000 ) ;
return 0 ;
}
static void F_389 ( struct V_328 * V_328 )
{
if ( V_316 ) {
F_390 ( V_328 ) ;
} else {
F_391 ( & V_328 -> V_14 . V_335 ) ;
F_390 ( V_328 ) ;
}
}
static void F_392 ( struct V_328 * V_328 ,
const struct V_423 * V_424 )
{
F_389 ( V_328 ) ;
}
static void F_393 ( struct V_131 * V_115 , struct V_5 * V_6 )
{
int V_309 = F_394 () ;
int V_425 ;
V_425 = F_235 ( V_6 , V_309 ) ;
if ( V_425 )
F_238 ( V_6 ) ;
F_244 ( V_6 , V_309 ) ;
if ( V_425 )
F_242 ( V_6 ) ;
}
static int F_395 ( struct V_131 * V_115 , struct V_5 * V_6 )
{
int V_309 = F_394 () ;
int V_388 ;
F_55 ( V_6 ) ;
F_396 ( V_6 , F_59 () ) ;
F_235 ( V_6 , V_309 ) ;
F_244 ( V_6 , V_309 ) ;
F_242 ( V_6 ) ;
V_388 = V_6 -> V_14 . V_426 ( V_115 , V_6 ) ;
F_238 ( V_6 ) ;
return V_388 ;
}
int F_397 ( struct V_427 * * V_428 )
{
if ( ! V_429 )
return - V_430 ;
if ( F_82 ( V_431 == - 1 ,
L_13 ) )
return - V_430 ;
F_398 ( L_14 ) ;
* V_428 = & V_432 ;
return 0 ;
}
