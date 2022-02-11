static inline T_1 F_1 ( void T_2 * V_1 )
{
return F_2 ( V_1 ) ;
}
static inline void F_3 ( T_1 V_2 , void T_2 * V_1 )
{
F_4 ( V_1 , V_2 ) ;
}
static inline T_1 F_1 ( void T_2 * V_1 )
{
return F_5 ( V_1 ) ;
}
static inline void F_3 ( T_1 V_2 , void T_2 * V_1 )
{
F_6 ( V_2 , V_1 ) ;
}
static inline void F_7 ( const struct V_3 * V_4 )
{
struct V_5 T_2 * V_6 = V_4 -> V_6 ;
T_1 V_7 = ( V_4 -> V_8 | V_9 ) ;
F_3 ( V_7 , & V_6 -> V_10 ) ;
}
static inline void F_8 ( const struct V_3 * V_4 )
{
struct V_5 T_2 * V_6 = V_4 -> V_6 ;
T_1 V_7 = ( V_4 -> V_8 & ~ V_9 ) ;
F_3 ( V_7 , & V_6 -> V_10 ) ;
}
static inline int F_9 ( const struct V_3 * V_4 )
{
if ( ! V_4 -> V_11 )
return 0 ;
return F_10 ( V_4 -> V_11 ) ;
}
static inline int F_11 ( const struct V_3 * V_4 )
{
if ( ! V_4 -> V_11 )
return 0 ;
return F_12 ( V_4 -> V_11 ) ;
}
static int F_13 ( struct V_3 * V_4 )
{
struct V_5 T_2 * V_6 = V_4 -> V_6 ;
unsigned int V_12 = V_13 / 10 ;
T_1 V_14 ;
V_14 = F_1 ( & V_6 -> V_15 ) ;
V_14 &= ~ V_16 ;
F_3 ( V_14 , & V_6 -> V_15 ) ;
while ( V_12 -- && ( F_1 ( & V_6 -> V_15 ) & V_17 ) )
F_14 ( 10 ) ;
if ( F_1 ( & V_6 -> V_15 ) & V_17 )
return - V_18 ;
return 0 ;
}
static int F_15 ( struct V_3 * V_4 )
{
struct V_5 T_2 * V_6 = V_4 -> V_6 ;
unsigned int V_12 = V_13 / 10 ;
T_1 V_14 ;
V_14 = F_1 ( & V_6 -> V_15 ) ;
V_14 |= V_16 ;
F_3 ( V_14 , & V_6 -> V_15 ) ;
while ( V_12 -- && ! ( F_1 ( & V_6 -> V_15 ) & V_17 ) )
F_14 ( 10 ) ;
if ( ! ( F_1 ( & V_6 -> V_15 ) & V_17 ) )
return - V_18 ;
return 0 ;
}
static int F_16 ( struct V_3 * V_4 )
{
struct V_5 T_2 * V_6 = V_4 -> V_6 ;
unsigned int V_12 = 1000 * 1000 * 10 / V_4 -> V_19 . V_20 . V_21 ;
T_1 V_14 ;
V_14 = F_1 ( & V_6 -> V_15 ) ;
V_14 |= V_22 ;
F_3 ( V_14 , & V_6 -> V_15 ) ;
while ( V_12 -- && ! ( F_1 ( & V_6 -> V_15 ) & V_23 ) )
F_14 ( 100 ) ;
if ( ! ( F_1 ( & V_6 -> V_15 ) & V_23 ) )
return - V_18 ;
return 0 ;
}
static int F_17 ( struct V_3 * V_4 )
{
struct V_5 T_2 * V_6 = V_4 -> V_6 ;
unsigned int V_12 = V_13 / 10 ;
T_1 V_14 ;
V_14 = F_1 ( & V_6 -> V_15 ) ;
V_14 &= ~ V_22 ;
F_3 ( V_14 , & V_6 -> V_15 ) ;
while ( V_12 -- && ( F_1 ( & V_6 -> V_15 ) & V_23 ) )
F_14 ( 10 ) ;
if ( F_1 ( & V_6 -> V_15 ) & V_23 )
return - V_18 ;
return 0 ;
}
static int F_18 ( struct V_3 * V_4 )
{
struct V_5 T_2 * V_6 = V_4 -> V_6 ;
unsigned int V_12 = V_13 / 10 ;
F_3 ( V_24 , & V_6 -> V_15 ) ;
while ( V_12 -- && ( F_1 ( & V_6 -> V_15 ) & V_24 ) )
F_14 ( 10 ) ;
if ( F_1 ( & V_6 -> V_15 ) & V_24 )
return - V_18 ;
return 0 ;
}
static int F_19 ( const struct V_25 * V_26 ,
struct V_27 * V_28 )
{
const struct V_3 * V_4 = F_20 ( V_26 ) ;
struct V_5 T_2 * V_6 = V_4 -> V_6 ;
T_1 V_14 = F_1 ( & V_6 -> V_29 ) ;
V_28 -> V_30 = ( V_14 >> 0 ) & 0xff ;
V_28 -> V_31 = ( V_14 >> 8 ) & 0xff ;
return 0 ;
}
static int F_21 ( const struct V_25 * V_26 ,
struct V_27 * V_28 )
{
const struct V_3 * V_4 = F_20 ( V_26 ) ;
int V_32 ;
V_32 = F_22 ( V_4 -> V_33 ) ;
if ( V_32 )
return V_32 ;
V_32 = F_22 ( V_4 -> V_34 ) ;
if ( V_32 )
goto V_35;
V_32 = F_19 ( V_26 , V_28 ) ;
F_23 ( V_4 -> V_34 ) ;
V_35:
F_23 ( V_4 -> V_33 ) ;
return V_32 ;
}
static int F_24 ( struct V_36 * V_37 , struct V_25 * V_26 )
{
const struct V_3 * V_4 = F_20 ( V_26 ) ;
struct V_38 * V_39 = (struct V_38 * ) V_37 -> V_40 ;
T_1 V_41 ;
T_1 V_40 ;
T_1 V_10 = V_42 | ( V_39 -> V_43 << 16 ) ;
if ( F_25 ( V_26 , V_37 ) )
return V_44 ;
F_26 ( V_26 ) ;
if ( V_39 -> V_41 & V_45 ) {
V_41 = V_39 -> V_41 & V_46 ;
V_10 |= V_47 | V_48 ;
} else {
V_41 = ( V_39 -> V_41 & V_49 ) << 18 ;
}
if ( V_39 -> V_41 & V_50 )
V_10 |= V_51 ;
if ( V_39 -> V_43 > 0 ) {
V_40 = F_27 ( ( V_52 * ) & V_39 -> V_40 [ 0 ] ) ;
F_3 ( V_40 , & V_4 -> V_53 -> V_40 [ 0 ] ) ;
}
if ( V_39 -> V_43 > 3 ) {
V_40 = F_27 ( ( V_52 * ) & V_39 -> V_40 [ 4 ] ) ;
F_3 ( V_40 , & V_4 -> V_53 -> V_40 [ 1 ] ) ;
}
F_28 ( V_37 , V_26 , 0 ) ;
F_3 ( V_41 , & V_4 -> V_53 -> V_41 ) ;
F_3 ( V_10 , & V_4 -> V_53 -> V_54 ) ;
F_3 ( V_55 ,
& V_4 -> V_56 -> V_54 ) ;
F_3 ( V_55 ,
& V_4 -> V_56 -> V_54 ) ;
return V_44 ;
}
static void F_29 ( struct V_25 * V_26 , T_1 V_57 )
{
struct V_3 * V_4 = F_20 ( V_26 ) ;
struct V_36 * V_37 ;
struct V_38 * V_39 ;
bool V_58 = false , V_59 = false ;
V_37 = F_30 ( V_26 , & V_39 ) ;
if ( F_31 ( ! V_37 ) )
return;
V_39 -> V_41 |= V_60 | V_61 ;
if ( V_57 & V_62 ) {
F_32 ( V_26 , L_1 ) ;
V_39 -> V_40 [ 2 ] |= V_63 ;
V_59 = true ;
}
if ( V_57 & V_64 ) {
F_32 ( V_26 , L_2 ) ;
V_39 -> V_40 [ 2 ] |= V_65 ;
V_59 = true ;
}
if ( V_57 & V_66 ) {
F_32 ( V_26 , L_3 ) ;
V_39 -> V_41 |= V_67 ;
V_39 -> V_40 [ 3 ] = V_68 ;
V_59 = true ;
}
if ( V_57 & V_69 ) {
F_32 ( V_26 , L_4 ) ;
V_39 -> V_40 [ 2 ] |= V_70 ;
V_39 -> V_40 [ 3 ] = V_71 ;
V_58 = true ;
}
if ( V_57 & V_72 ) {
F_32 ( V_26 , L_5 ) ;
V_39 -> V_40 [ 2 ] |= V_73 ;
V_58 = true ;
}
if ( V_57 & V_74 ) {
F_32 ( V_26 , L_6 ) ;
V_39 -> V_40 [ 2 ] |= V_75 ;
V_58 = true ;
}
V_4 -> V_19 . V_76 . V_77 ++ ;
if ( V_58 )
V_26 -> V_78 . V_58 ++ ;
if ( V_59 )
V_26 -> V_78 . V_59 ++ ;
F_33 ( & V_4 -> V_79 , V_37 ) ;
}
static void F_34 ( struct V_25 * V_26 , T_1 V_57 )
{
struct V_3 * V_4 = F_20 ( V_26 ) ;
struct V_36 * V_37 ;
struct V_38 * V_39 ;
enum V_80 V_81 , V_82 , V_83 ;
int V_84 ;
struct V_27 V_28 ;
V_84 = V_57 & V_85 ;
if ( F_35 ( V_84 == V_86 ) ) {
V_83 = F_31 ( V_57 & V_87 ) ?
V_88 : V_89 ;
V_82 = F_31 ( V_57 & V_90 ) ?
V_88 : V_89 ;
V_81 = F_36 ( V_83 , V_82 ) ;
} else {
F_19 ( V_26 , & V_28 ) ;
V_81 = V_84 == V_91 ?
V_92 : V_93 ;
V_82 = V_28 . V_31 >= V_28 . V_30 ? V_81 : 0 ;
V_83 = V_28 . V_31 <= V_28 . V_30 ? V_81 : 0 ;
}
if ( F_35 ( V_81 == V_4 -> V_19 . V_94 ) )
return;
V_37 = F_30 ( V_26 , & V_39 ) ;
if ( F_31 ( ! V_37 ) )
return;
F_37 ( V_26 , V_39 , V_83 , V_82 ) ;
if ( F_31 ( V_81 == V_93 ) )
F_38 ( V_26 ) ;
F_33 ( & V_4 -> V_79 , V_37 ) ;
}
static inline struct V_3 * F_39 ( struct V_95 * V_79 )
{
return F_40 ( V_79 , struct V_3 , V_79 ) ;
}
static unsigned int F_41 ( struct V_95 * V_79 ,
struct V_38 * V_39 ,
T_1 * V_96 , unsigned int V_97 )
{
struct V_3 * V_4 = F_39 ( V_79 ) ;
struct V_5 T_2 * V_6 = V_4 -> V_6 ;
struct V_98 T_2 * V_99 = & V_6 -> V_99 [ V_97 ] ;
T_1 V_7 , V_100 , V_101 ;
if ( V_4 -> V_102 -> V_103 & V_104 ) {
T_1 V_105 ;
do {
V_7 = F_1 ( & V_99 -> V_54 ) ;
} while ( V_7 & V_106 );
V_105 = V_7 & V_107 ;
if ( ( V_105 != V_108 ) &&
( V_105 != V_109 ) )
return 0 ;
if ( V_105 == V_109 ) {
V_79 -> V_26 -> V_78 . V_110 ++ ;
V_79 -> V_26 -> V_78 . V_58 ++ ;
}
} else {
V_101 = F_1 ( & V_6 -> V_111 ) ;
if ( ! ( V_101 & V_112 ) )
return 0 ;
V_7 = F_1 ( & V_99 -> V_54 ) ;
}
* V_96 = V_7 << 16 ;
V_100 = F_1 ( & V_99 -> V_41 ) ;
if ( V_7 & V_47 )
V_39 -> V_41 = ( ( V_100 >> 0 ) & V_46 ) | V_45 ;
else
V_39 -> V_41 = ( V_100 >> 18 ) & V_49 ;
if ( V_7 & V_51 )
V_39 -> V_41 |= V_50 ;
V_39 -> V_43 = F_42 ( ( V_7 >> 16 ) & 0xf ) ;
* ( V_52 * ) ( V_39 -> V_40 + 0 ) = F_43 ( F_1 ( & V_99 -> V_40 [ 0 ] ) ) ;
* ( V_52 * ) ( V_39 -> V_40 + 4 ) = F_43 ( F_1 ( & V_99 -> V_40 [ 1 ] ) ) ;
if ( V_4 -> V_102 -> V_103 & V_104 ) {
if ( V_97 < 32 )
F_3 ( F_44 ( V_97 ) , & V_6 -> V_111 ) ;
else
F_3 ( F_44 ( V_97 - 32 ) , & V_6 -> V_113 ) ;
} else {
F_3 ( V_112 , & V_6 -> V_111 ) ;
F_1 ( & V_6 -> V_114 ) ;
}
return 1 ;
}
static inline T_3 F_45 ( struct V_3 * V_4 )
{
struct V_5 T_2 * V_6 = V_4 -> V_6 ;
T_1 V_111 , V_113 ;
V_113 = F_1 ( & V_6 -> V_113 ) & V_4 -> V_115 ;
V_111 = F_1 ( & V_6 -> V_111 ) & V_4 -> V_116 &
~ F_46 ( V_4 -> V_117 ) ;
return ( T_3 ) V_113 << 32 | V_111 ;
}
static T_4 F_47 ( int V_118 , void * V_119 )
{
struct V_25 * V_26 = V_119 ;
struct V_120 * V_78 = & V_26 -> V_78 ;
struct V_3 * V_4 = F_20 ( V_26 ) ;
struct V_5 T_2 * V_6 = V_4 -> V_6 ;
T_4 V_121 = V_122 ;
T_1 V_101 , V_57 ;
enum V_80 V_123 = V_4 -> V_19 . V_94 ;
V_101 = F_1 ( & V_6 -> V_111 ) ;
if ( V_4 -> V_102 -> V_103 & V_104 ) {
T_3 V_124 ;
int V_125 ;
while ( ( V_124 = F_45 ( V_4 ) ) ) {
V_121 = V_126 ;
V_125 = F_48 ( & V_4 -> V_79 ,
V_124 ) ;
if ( ! V_125 )
break;
}
} else {
if ( V_101 & V_112 ) {
V_121 = V_126 ;
F_49 ( & V_4 -> V_79 ) ;
}
if ( V_101 & V_127 ) {
V_121 = V_126 ;
F_3 ( V_127 , & V_6 -> V_111 ) ;
V_26 -> V_78 . V_110 ++ ;
V_26 -> V_78 . V_58 ++ ;
}
}
if ( V_101 & F_46 ( V_4 -> V_117 ) ) {
V_121 = V_126 ;
V_78 -> V_128 += F_50 ( V_26 , 0 ) ;
V_78 -> V_129 ++ ;
F_51 ( V_26 , V_130 ) ;
F_3 ( V_55 ,
& V_4 -> V_53 -> V_54 ) ;
F_3 ( F_46 ( V_4 -> V_117 ) , & V_6 -> V_111 ) ;
F_52 ( V_26 ) ;
}
V_57 = F_1 ( & V_6 -> V_131 ) ;
if ( V_57 & V_132 ) {
V_121 = V_126 ;
F_3 ( V_57 & V_132 , & V_6 -> V_131 ) ;
}
if ( ( V_57 & V_133 ) ||
( V_4 -> V_102 -> V_103 & ( V_134 |
V_135 ) ) )
F_34 ( V_26 , V_57 ) ;
if ( ( V_57 & V_136 ) &&
( V_4 -> V_19 . V_137 & V_138 ) )
F_29 ( V_26 , V_57 ) ;
if ( ( V_123 != V_4 -> V_19 . V_94 ) &&
( V_4 -> V_102 -> V_103 & V_135 ) &&
! ( V_4 -> V_19 . V_137 & V_138 ) ) {
switch ( V_4 -> V_19 . V_94 ) {
case V_89 :
if ( V_4 -> V_102 -> V_103 &
V_134 )
F_7 ( V_4 ) ;
else
F_8 ( V_4 ) ;
break;
case V_88 :
F_7 ( V_4 ) ;
break;
case V_92 :
case V_93 :
F_8 ( V_4 ) ;
break;
default:
break;
}
}
return V_121 ;
}
static void F_53 ( struct V_25 * V_26 )
{
const struct V_3 * V_4 = F_20 ( V_26 ) ;
const struct V_139 * V_140 = & V_4 -> V_19 . V_20 ;
struct V_5 T_2 * V_6 = V_4 -> V_6 ;
T_1 V_14 ;
V_14 = F_1 ( & V_6 -> V_10 ) ;
V_14 &= ~ ( F_54 ( 0xff ) |
F_55 ( 0x3 ) |
F_56 ( 0x7 ) |
F_57 ( 0x7 ) |
F_58 ( 0x7 ) |
V_141 |
V_142 |
V_143 ) ;
V_14 |= F_54 ( V_140 -> V_144 - 1 ) |
F_56 ( V_140 -> V_145 - 1 ) |
F_57 ( V_140 -> V_146 - 1 ) |
F_55 ( V_140 -> V_147 - 1 ) |
F_58 ( V_140 -> V_148 - 1 ) ;
if ( V_4 -> V_19 . V_137 & V_149 )
V_14 |= V_141 ;
if ( V_4 -> V_19 . V_137 & V_150 )
V_14 |= V_143 ;
if ( V_4 -> V_19 . V_137 & V_151 )
V_14 |= V_142 ;
F_32 ( V_26 , L_7 , V_14 ) ;
F_3 ( V_14 , & V_6 -> V_10 ) ;
F_32 ( V_26 , L_8 , V_152 ,
F_1 ( & V_6 -> V_15 ) , F_1 ( & V_6 -> V_10 ) ) ;
}
static int F_59 ( struct V_25 * V_26 )
{
struct V_3 * V_4 = F_20 ( V_26 ) ;
struct V_5 T_2 * V_6 = V_4 -> V_6 ;
T_1 V_153 , V_7 , V_154 , V_155 ;
int V_32 , V_156 ;
V_32 = F_13 ( V_4 ) ;
if ( V_32 )
return V_32 ;
V_32 = F_18 ( V_4 ) ;
if ( V_32 )
goto V_157;
F_53 ( V_26 ) ;
V_153 = F_1 ( & V_6 -> V_15 ) ;
V_153 &= ~ F_60 ( 0xff ) ;
V_153 |= V_158 | V_22 | V_159 |
V_160 | V_161 | V_162 |
V_163 ;
if ( V_4 -> V_102 -> V_103 & V_104 ) {
V_153 &= ~ V_164 ;
V_153 |= F_60 ( V_4 -> V_79 . V_165 ) ;
} else {
V_153 |= V_164 |
F_60 ( V_4 -> V_117 ) ;
}
F_32 ( V_26 , L_9 , V_152 , V_153 ) ;
F_3 ( V_153 , & V_6 -> V_15 ) ;
V_7 = F_1 ( & V_6 -> V_10 ) ;
V_7 &= ~ V_166 ;
V_7 |= V_167 | V_168 |
V_169 ;
if ( V_4 -> V_102 -> V_103 & V_134 ||
V_4 -> V_19 . V_137 & V_138 )
V_7 |= V_9 ;
else
V_7 &= ~ V_9 ;
V_4 -> V_8 = V_7 ;
V_7 &= ~ V_170 ;
F_32 ( V_26 , L_10 , V_152 , V_7 ) ;
F_3 ( V_7 , & V_6 -> V_10 ) ;
if ( ( V_4 -> V_102 -> V_103 & V_171 ) ) {
V_154 = F_1 ( & V_6 -> V_172 ) ;
V_154 |= V_173 | V_174 ;
F_3 ( V_154 , & V_6 -> V_172 ) ;
}
for ( V_156 = V_4 -> V_117 ; V_156 < F_61 ( V_6 -> V_99 ) ; V_156 ++ ) {
F_3 ( V_175 ,
& V_6 -> V_99 [ V_156 ] . V_54 ) ;
}
if ( V_4 -> V_102 -> V_103 & V_104 ) {
for ( V_156 = V_4 -> V_79 . V_176 ; V_156 <= V_4 -> V_79 . V_165 ; V_156 ++ )
F_3 ( V_177 ,
& V_6 -> V_99 [ V_156 ] . V_54 ) ;
}
F_3 ( V_55 ,
& V_4 -> V_56 -> V_54 ) ;
F_3 ( V_55 ,
& V_4 -> V_53 -> V_54 ) ;
F_3 ( 0x0 , & V_6 -> V_178 ) ;
F_3 ( 0x0 , & V_6 -> V_179 ) ;
F_3 ( 0x0 , & V_6 -> V_180 ) ;
if ( V_4 -> V_102 -> V_103 & V_181 )
F_3 ( 0x0 , & V_6 -> V_182 ) ;
for ( V_156 = 0 ; V_156 < F_61 ( V_6 -> V_99 ) ; V_156 ++ )
F_3 ( 0 , & V_6 -> V_183 [ V_156 ] ) ;
if ( V_4 -> V_102 -> V_103 & V_184 ) {
V_154 = F_1 ( & V_6 -> V_172 ) ;
V_154 |= V_185 ;
F_3 ( V_154 , & V_6 -> V_172 ) ;
V_155 = F_1 ( & V_6 -> V_186 ) ;
V_155 &= ~ V_187 ;
F_3 ( V_155 , & V_6 -> V_186 ) ;
V_155 &= ~ ( V_188 | V_189 |
V_190 ) ;
F_3 ( V_155 , & V_6 -> V_186 ) ;
}
V_32 = F_9 ( V_4 ) ;
if ( V_32 )
goto V_157;
V_32 = F_17 ( V_4 ) ;
if ( V_32 )
goto V_191;
V_4 -> V_19 . V_94 = V_89 ;
F_62 ( V_26 -> V_118 ) ;
F_3 ( V_4 -> V_8 , & V_6 -> V_10 ) ;
F_3 ( V_4 -> V_116 , & V_6 -> V_192 ) ;
F_3 ( V_4 -> V_115 , & V_6 -> V_193 ) ;
F_63 ( V_26 -> V_118 ) ;
F_32 ( V_26 , L_11 , V_152 ,
F_1 ( & V_6 -> V_15 ) , F_1 ( & V_6 -> V_10 ) ) ;
return 0 ;
V_191:
F_11 ( V_4 ) ;
V_157:
F_15 ( V_4 ) ;
return V_32 ;
}
static void F_64 ( struct V_25 * V_26 )
{
struct V_3 * V_4 = F_20 ( V_26 ) ;
struct V_5 T_2 * V_6 = V_4 -> V_6 ;
F_16 ( V_4 ) ;
F_15 ( V_4 ) ;
F_3 ( 0 , & V_6 -> V_193 ) ;
F_3 ( 0 , & V_6 -> V_192 ) ;
F_3 ( V_4 -> V_8 & ~ V_170 ,
& V_6 -> V_10 ) ;
F_11 ( V_4 ) ;
V_4 -> V_19 . V_94 = V_194 ;
}
static int F_65 ( struct V_25 * V_26 )
{
struct V_3 * V_4 = F_20 ( V_26 ) ;
int V_32 ;
V_32 = F_22 ( V_4 -> V_33 ) ;
if ( V_32 )
return V_32 ;
V_32 = F_22 ( V_4 -> V_34 ) ;
if ( V_32 )
goto V_35;
V_32 = F_66 ( V_26 ) ;
if ( V_32 )
goto V_195;
V_32 = F_67 ( V_26 -> V_118 , F_47 , V_196 , V_26 -> V_197 , V_26 ) ;
if ( V_32 )
goto V_198;
V_32 = F_59 ( V_26 ) ;
if ( V_32 )
goto V_199;
F_51 ( V_26 , V_200 ) ;
F_68 ( & V_4 -> V_79 ) ;
F_69 ( V_26 ) ;
return 0 ;
V_199:
F_70 ( V_26 -> V_118 , V_26 ) ;
V_198:
F_71 ( V_26 ) ;
V_195:
F_23 ( V_4 -> V_34 ) ;
V_35:
F_23 ( V_4 -> V_33 ) ;
return V_32 ;
}
static int F_72 ( struct V_25 * V_26 )
{
struct V_3 * V_4 = F_20 ( V_26 ) ;
F_26 ( V_26 ) ;
F_73 ( & V_4 -> V_79 ) ;
F_64 ( V_26 ) ;
F_70 ( V_26 -> V_118 , V_26 ) ;
F_23 ( V_4 -> V_34 ) ;
F_23 ( V_4 -> V_33 ) ;
F_71 ( V_26 ) ;
F_51 ( V_26 , V_201 ) ;
return 0 ;
}
static int F_74 ( struct V_25 * V_26 , enum V_202 V_203 )
{
int V_32 ;
switch ( V_203 ) {
case V_204 :
V_32 = F_59 ( V_26 ) ;
if ( V_32 )
return V_32 ;
F_52 ( V_26 ) ;
break;
default:
return - V_205 ;
}
return 0 ;
}
static int F_75 ( struct V_25 * V_26 )
{
struct V_3 * V_4 = F_20 ( V_26 ) ;
struct V_5 T_2 * V_6 = V_4 -> V_6 ;
T_1 V_14 , V_32 ;
V_32 = F_22 ( V_4 -> V_33 ) ;
if ( V_32 )
return V_32 ;
V_32 = F_22 ( V_4 -> V_34 ) ;
if ( V_32 )
goto V_35;
V_32 = F_15 ( V_4 ) ;
if ( V_32 )
goto V_195;
V_14 = F_1 ( & V_6 -> V_10 ) ;
V_14 |= V_206 ;
F_3 ( V_14 , & V_6 -> V_10 ) ;
V_32 = F_13 ( V_4 ) ;
if ( V_32 )
goto V_157;
V_14 = F_1 ( & V_6 -> V_15 ) ;
V_14 |= V_158 | V_22 |
V_164 | V_159 ;
F_3 ( V_14 , & V_6 -> V_15 ) ;
V_14 = F_1 ( & V_6 -> V_15 ) ;
if ( ! ( V_14 & V_164 ) ) {
F_76 ( V_26 , L_12 ) ;
V_32 = - V_207 ;
goto V_157;
}
V_32 = F_77 ( V_26 ) ;
V_157:
F_15 ( V_4 ) ;
V_195:
F_23 ( V_4 -> V_34 ) ;
V_35:
F_23 ( V_4 -> V_33 ) ;
return V_32 ;
}
static void F_78 ( struct V_25 * V_26 )
{
F_79 ( V_26 ) ;
}
static int F_80 ( struct V_208 * V_209 )
{
const struct V_210 * V_211 ;
const struct V_212 * V_102 ;
struct V_25 * V_26 ;
struct V_3 * V_4 ;
struct V_213 * V_11 ;
struct V_214 * V_215 ;
struct V_216 * V_33 = NULL , * V_34 = NULL ;
struct V_5 T_2 * V_6 ;
int V_32 , V_118 ;
T_1 V_217 = 0 ;
V_11 = F_81 ( & V_209 -> V_26 , L_13 ) ;
if ( F_82 ( V_11 ) == - V_218 )
return - V_218 ;
else if ( F_83 ( V_11 ) )
V_11 = NULL ;
if ( V_209 -> V_26 . V_219 )
F_84 ( V_209 -> V_26 . V_219 ,
L_14 , & V_217 ) ;
if ( ! V_217 ) {
V_33 = F_85 ( & V_209 -> V_26 , L_15 ) ;
if ( F_83 ( V_33 ) ) {
F_86 ( & V_209 -> V_26 , L_16 ) ;
return F_82 ( V_33 ) ;
}
V_34 = F_85 ( & V_209 -> V_26 , L_17 ) ;
if ( F_83 ( V_34 ) ) {
F_86 ( & V_209 -> V_26 , L_18 ) ;
return F_82 ( V_34 ) ;
}
V_217 = F_87 ( V_34 ) ;
}
V_215 = F_88 ( V_209 , V_220 , 0 ) ;
V_118 = F_89 ( V_209 , 0 ) ;
if ( V_118 <= 0 )
return - V_207 ;
V_6 = F_90 ( & V_209 -> V_26 , V_215 ) ;
if ( F_83 ( V_6 ) )
return F_82 ( V_6 ) ;
V_211 = F_91 ( V_221 , & V_209 -> V_26 ) ;
if ( V_211 ) {
V_102 = V_211 -> V_40 ;
} else if ( F_92 ( V_209 ) -> V_222 ) {
V_102 = (struct V_212 * )
F_92 ( V_209 ) -> V_222 ;
} else {
return - V_207 ;
}
V_26 = F_93 ( sizeof( struct V_3 ) , 1 ) ;
if ( ! V_26 )
return - V_223 ;
F_94 ( V_209 , V_26 ) ;
F_95 ( V_26 , & V_209 -> V_26 ) ;
V_26 -> V_224 = & V_225 ;
V_26 -> V_118 = V_118 ;
V_26 -> V_226 |= V_227 ;
V_4 = F_20 ( V_26 ) ;
V_4 -> V_19 . clock . V_228 = V_217 ;
V_4 -> V_19 . V_229 = & V_230 ;
V_4 -> V_19 . V_231 = F_74 ;
V_4 -> V_19 . V_232 = F_21 ;
V_4 -> V_19 . V_233 = V_149 |
V_150 | V_151 |
V_138 ;
V_4 -> V_6 = V_6 ;
V_4 -> V_33 = V_33 ;
V_4 -> V_34 = V_34 ;
V_4 -> V_102 = V_102 ;
V_4 -> V_11 = V_11 ;
if ( V_4 -> V_102 -> V_103 & V_104 ) {
V_4 -> V_117 = V_234 ;
V_4 -> V_56 = & V_6 -> V_99 [ V_235 ] ;
} else {
V_4 -> V_117 = V_236 ;
V_4 -> V_56 = & V_6 -> V_99 [ V_237 ] ;
}
V_4 -> V_53 = & V_6 -> V_99 [ V_4 -> V_117 ] ;
V_4 -> V_116 = F_46 ( V_4 -> V_117 ) ;
V_4 -> V_115 = 0 ;
V_4 -> V_79 . V_238 = F_41 ;
if ( V_4 -> V_102 -> V_103 & V_104 ) {
T_3 V_239 ;
V_4 -> V_79 . V_176 = V_240 ;
V_4 -> V_79 . V_165 = V_241 ;
V_239 = F_96 ( V_4 -> V_79 . V_165 , V_4 -> V_79 . V_176 ) ;
V_4 -> V_116 |= V_239 ;
V_4 -> V_115 |= V_239 >> 32 ;
V_32 = F_97 ( V_26 , & V_4 -> V_79 ) ;
} else {
V_4 -> V_116 |= V_127 |
V_112 ;
V_32 = F_98 ( V_26 , & V_4 -> V_79 , V_242 ) ;
}
if ( V_32 )
goto V_243;
V_32 = F_75 ( V_26 ) ;
if ( V_32 ) {
F_86 ( & V_209 -> V_26 , L_19 ) ;
goto V_244;
}
F_99 ( V_26 ) ;
F_100 ( & V_209 -> V_26 , L_20 ,
V_4 -> V_6 , V_26 -> V_118 ) ;
return 0 ;
V_243:
V_244:
F_101 ( V_26 ) ;
return V_32 ;
}
static int F_102 ( struct V_208 * V_209 )
{
struct V_25 * V_26 = F_103 ( V_209 ) ;
struct V_3 * V_4 = F_20 ( V_26 ) ;
F_78 ( V_26 ) ;
F_104 ( & V_4 -> V_79 ) ;
F_101 ( V_26 ) ;
return 0 ;
}
static int T_5 F_105 ( struct V_245 * V_245 )
{
struct V_25 * V_26 = F_106 ( V_245 ) ;
struct V_3 * V_4 = F_20 ( V_26 ) ;
int V_32 ;
if ( F_107 ( V_26 ) ) {
V_32 = F_15 ( V_4 ) ;
if ( V_32 )
return V_32 ;
F_26 ( V_26 ) ;
F_108 ( V_26 ) ;
}
V_4 -> V_19 . V_94 = V_246 ;
return 0 ;
}
static int T_5 F_109 ( struct V_245 * V_245 )
{
struct V_25 * V_26 = F_106 ( V_245 ) ;
struct V_3 * V_4 = F_20 ( V_26 ) ;
int V_32 ;
V_4 -> V_19 . V_94 = V_89 ;
if ( F_107 ( V_26 ) ) {
F_110 ( V_26 ) ;
F_69 ( V_26 ) ;
V_32 = F_13 ( V_4 ) ;
if ( V_32 )
return V_32 ;
}
return 0 ;
}
