static void F_1 ( const struct V_1 * V_2 , int V_3 )
{
if ( V_2 -> V_4 && V_2 -> V_4 -> V_5 )
V_2 -> V_4 -> V_5 ( V_3 ) ;
}
static inline int F_2 ( const struct V_1 * V_2 ,
T_1 V_6 )
{
return ( V_2 -> V_7 . V_8 & V_9 ) &&
( V_6 & V_10 ) ;
}
static inline void F_3 ( struct V_1 * V_2 )
{
struct V_11 T_2 * V_12 = V_2 -> V_13 ;
T_1 V_14 ;
V_14 = F_4 ( & V_12 -> V_15 ) ;
V_14 &= ~ V_16 ;
F_5 ( V_14 , & V_12 -> V_15 ) ;
F_6 ( 10 ) ;
}
static inline void F_7 ( struct V_1 * V_2 )
{
struct V_11 T_2 * V_12 = V_2 -> V_13 ;
T_1 V_14 ;
V_14 = F_4 ( & V_12 -> V_15 ) ;
V_14 |= V_16 ;
F_5 ( V_14 , & V_12 -> V_15 ) ;
}
static int F_8 ( const struct V_17 * V_18 ,
struct V_19 * V_20 )
{
const struct V_1 * V_2 = F_9 ( V_18 ) ;
struct V_11 T_2 * V_12 = V_2 -> V_13 ;
T_1 V_14 = F_4 ( & V_12 -> V_21 ) ;
V_20 -> V_22 = ( V_14 >> 0 ) & 0xff ;
V_20 -> V_23 = ( V_14 >> 8 ) & 0xff ;
return 0 ;
}
static int F_10 ( struct V_24 * V_25 , struct V_17 * V_18 )
{
const struct V_1 * V_2 = F_9 ( V_18 ) ;
struct V_26 * V_27 = & V_18 -> V_27 ;
struct V_11 T_2 * V_12 = V_2 -> V_13 ;
struct V_28 * V_29 = (struct V_28 * ) V_25 -> V_30 ;
T_1 V_31 ;
T_1 V_32 = F_11 ( 0xc ) | ( V_29 -> V_33 << 16 ) ;
if ( F_12 ( V_18 , V_25 ) )
return V_34 ;
F_13 ( V_18 ) ;
if ( V_29 -> V_31 & V_35 ) {
V_31 = V_29 -> V_31 & V_36 ;
V_32 |= V_37 | V_38 ;
} else {
V_31 = ( V_29 -> V_31 & V_39 ) << 18 ;
}
if ( V_29 -> V_31 & V_40 )
V_32 |= V_41 ;
if ( V_29 -> V_33 > 0 ) {
T_1 V_30 = F_14 ( ( V_42 * ) & V_29 -> V_30 [ 0 ] ) ;
F_5 ( V_30 , & V_12 -> V_43 [ V_44 ] . V_30 [ 0 ] ) ;
}
if ( V_29 -> V_33 > 3 ) {
T_1 V_30 = F_14 ( ( V_42 * ) & V_29 -> V_30 [ 4 ] ) ;
F_5 ( V_30 , & V_12 -> V_43 [ V_44 ] . V_30 [ 1 ] ) ;
}
F_5 ( V_31 , & V_12 -> V_43 [ V_44 ] . V_31 ) ;
F_5 ( V_32 , & V_12 -> V_43 [ V_44 ] . V_45 ) ;
F_15 ( V_25 ) ;
V_27 -> V_46 += V_29 -> V_33 ;
return V_34 ;
}
static void F_16 ( struct V_17 * V_18 ,
struct V_28 * V_29 , T_1 V_6 )
{
struct V_1 * V_2 = F_9 ( V_18 ) ;
int V_47 = 0 , V_48 = 0 ;
V_29 -> V_31 |= V_49 | V_50 ;
if ( V_6 & V_51 ) {
F_17 ( V_18 -> V_18 . V_52 , L_1 ) ;
V_29 -> V_30 [ 2 ] |= V_53 ;
V_48 = 1 ;
}
if ( V_6 & V_54 ) {
F_17 ( V_18 -> V_18 . V_52 , L_2 ) ;
V_29 -> V_30 [ 2 ] |= V_55 ;
V_48 = 1 ;
}
if ( V_6 & V_56 ) {
F_17 ( V_18 -> V_18 . V_52 , L_3 ) ;
V_29 -> V_31 |= V_57 ;
V_29 -> V_30 [ 3 ] |= V_58 ;
V_48 = 1 ;
}
if ( V_6 & V_59 ) {
F_17 ( V_18 -> V_18 . V_52 , L_4 ) ;
V_29 -> V_30 [ 2 ] |= V_60 ;
V_29 -> V_30 [ 3 ] |= V_61 ;
V_47 = 1 ;
}
if ( V_6 & V_62 ) {
F_17 ( V_18 -> V_18 . V_52 , L_5 ) ;
V_29 -> V_30 [ 2 ] |= V_63 ;
V_47 = 1 ;
}
if ( V_6 & V_64 ) {
F_17 ( V_18 -> V_18 . V_52 , L_6 ) ;
V_29 -> V_30 [ 2 ] |= V_65 ;
V_47 = 1 ;
}
V_2 -> V_7 . V_66 . V_67 ++ ;
if ( V_47 )
V_18 -> V_27 . V_47 ++ ;
if ( V_48 )
V_18 -> V_27 . V_48 ++ ;
}
static int F_18 ( struct V_17 * V_18 , T_1 V_6 )
{
struct V_24 * V_25 ;
struct V_28 * V_29 ;
V_25 = F_19 ( V_18 , & V_29 ) ;
if ( F_20 ( ! V_25 ) )
return 0 ;
F_16 ( V_18 , V_29 , V_6 ) ;
F_21 ( V_25 ) ;
V_18 -> V_27 . V_68 ++ ;
V_18 -> V_27 . V_69 += V_29 -> V_33 ;
return 1 ;
}
static void F_22 ( struct V_17 * V_18 ,
struct V_28 * V_29 , enum V_70 V_71 )
{
struct V_1 * V_2 = F_9 ( V_18 ) ;
struct V_19 V_20 ;
F_8 ( V_18 , & V_20 ) ;
switch ( V_2 -> V_7 . V_72 ) {
case V_73 :
if ( V_71 >= V_74 &&
V_71 <= V_75 ) {
F_17 ( V_18 -> V_18 . V_52 , L_7 ) ;
V_2 -> V_7 . V_66 . V_76 ++ ;
V_29 -> V_31 |= V_77 ;
V_29 -> V_30 [ 1 ] = ( V_20 . V_22 > V_20 . V_23 ) ?
V_78 :
V_79 ;
}
case V_74 :
if ( V_71 >= V_80 &&
V_71 <= V_75 ) {
F_17 ( V_18 -> V_18 . V_52 , L_8 ) ;
V_2 -> V_7 . V_66 . V_81 ++ ;
V_29 -> V_31 |= V_77 ;
V_29 -> V_30 [ 1 ] = ( V_20 . V_22 > V_20 . V_23 ) ?
V_82 :
V_83 ;
}
break;
case V_75 :
F_23 ( V_18 -> V_18 . V_52 ,
L_9 ) ;
break;
default:
break;
}
switch ( V_71 ) {
case V_73 :
F_17 ( V_18 -> V_18 . V_52 , L_10 ) ;
V_29 -> V_31 |= V_49 ;
V_29 -> V_30 [ 2 ] = V_84 ;
break;
case V_75 :
V_29 -> V_31 |= V_85 ;
F_24 ( V_18 ) ;
break;
default:
break;
}
}
static int F_25 ( struct V_17 * V_18 , T_1 V_6 )
{
struct V_1 * V_2 = F_9 ( V_18 ) ;
struct V_24 * V_25 ;
struct V_28 * V_29 ;
enum V_70 V_71 ;
int V_86 ;
V_86 = V_6 & V_87 ;
if ( F_26 ( V_86 == V_88 ) ) {
if ( F_26 ( ! ( V_6 & ( V_89 |
V_90 ) ) ) )
V_71 = V_73 ;
else
V_71 = V_74 ;
} else if ( F_20 ( V_86 == V_91 ) )
V_71 = V_80 ;
else
V_71 = V_75 ;
if ( F_26 ( V_71 == V_2 -> V_7 . V_72 ) )
return 0 ;
V_25 = F_19 ( V_18 , & V_29 ) ;
if ( F_20 ( ! V_25 ) )
return 0 ;
F_22 ( V_18 , V_29 , V_71 ) ;
V_2 -> V_7 . V_72 = V_71 ;
F_21 ( V_25 ) ;
V_18 -> V_27 . V_68 ++ ;
V_18 -> V_27 . V_69 += V_29 -> V_33 ;
return 1 ;
}
static void F_27 ( const struct V_17 * V_18 ,
struct V_28 * V_29 )
{
const struct V_1 * V_2 = F_9 ( V_18 ) ;
struct V_11 T_2 * V_12 = V_2 -> V_13 ;
struct V_92 T_2 * V_93 = & V_12 -> V_43 [ 0 ] ;
T_1 V_94 , V_95 ;
V_94 = F_4 ( & V_93 -> V_45 ) ;
V_95 = F_4 ( & V_93 -> V_31 ) ;
if ( V_94 & V_37 )
V_29 -> V_31 = ( ( V_95 >> 0 ) & V_36 ) | V_35 ;
else
V_29 -> V_31 = ( V_95 >> 18 ) & V_39 ;
if ( V_94 & V_41 )
V_29 -> V_31 |= V_40 ;
V_29 -> V_33 = F_28 ( ( V_94 >> 16 ) & 0xf ) ;
* ( V_42 * ) ( V_29 -> V_30 + 0 ) = F_29 ( F_4 ( & V_93 -> V_30 [ 0 ] ) ) ;
* ( V_42 * ) ( V_29 -> V_30 + 4 ) = F_29 ( F_4 ( & V_93 -> V_30 [ 1 ] ) ) ;
F_5 ( V_96 , & V_12 -> V_97 ) ;
F_4 ( & V_12 -> V_98 ) ;
}
static int F_30 ( struct V_17 * V_18 )
{
struct V_26 * V_27 = & V_18 -> V_27 ;
struct V_28 * V_29 ;
struct V_24 * V_25 ;
V_25 = F_31 ( V_18 , & V_29 ) ;
if ( F_20 ( ! V_25 ) ) {
V_27 -> V_99 ++ ;
return 0 ;
}
F_27 ( V_18 , V_29 ) ;
F_21 ( V_25 ) ;
V_27 -> V_68 ++ ;
V_27 -> V_69 += V_29 -> V_33 ;
return 1 ;
}
static int F_32 ( struct V_100 * V_101 , int V_102 )
{
struct V_17 * V_18 = V_101 -> V_18 ;
const struct V_1 * V_2 = F_9 ( V_18 ) ;
struct V_11 T_2 * V_12 = V_2 -> V_13 ;
T_1 V_103 , V_6 ;
int V_104 = 0 ;
V_6 = F_4 ( & V_12 -> V_105 ) | V_2 -> V_6 ;
V_104 += F_25 ( V_18 , V_6 ) ;
V_103 = F_4 ( & V_12 -> V_97 ) ;
while ( V_103 & V_96 &&
V_104 < V_102 ) {
V_104 += F_30 ( V_18 ) ;
V_103 = F_4 ( & V_12 -> V_97 ) ;
}
if ( F_2 ( V_2 , V_6 ) && V_104 < V_102 )
V_104 += F_18 ( V_18 , V_6 ) ;
if ( V_104 < V_102 ) {
F_33 ( V_101 ) ;
F_5 ( V_106 , & V_12 -> V_107 ) ;
F_5 ( V_2 -> V_108 , & V_12 -> V_32 ) ;
}
return V_104 ;
}
static T_3 F_34 ( int V_109 , void * V_110 )
{
struct V_17 * V_18 = V_110 ;
struct V_26 * V_27 = & V_18 -> V_27 ;
struct V_1 * V_2 = F_9 ( V_18 ) ;
struct V_11 T_2 * V_12 = V_2 -> V_13 ;
T_1 V_103 , V_6 ;
V_103 = F_4 ( & V_12 -> V_97 ) ;
V_6 = F_4 ( & V_12 -> V_105 ) ;
F_5 ( V_111 , & V_12 -> V_105 ) ;
if ( ( V_103 & V_96 ) ||
( V_6 & V_112 ) ||
F_2 ( V_2 , V_6 ) ) {
V_2 -> V_6 = V_6 & V_10 ;
F_5 ( V_106 & ~ V_96 ,
& V_12 -> V_107 ) ;
F_5 ( V_2 -> V_108 & ~ V_113 ,
& V_12 -> V_32 ) ;
F_35 ( & V_2 -> V_101 ) ;
}
if ( V_103 & V_114 ) {
F_5 ( V_114 , & V_12 -> V_97 ) ;
V_18 -> V_27 . V_115 ++ ;
V_18 -> V_27 . V_47 ++ ;
}
if ( V_103 & ( 1 << V_44 ) ) {
V_27 -> V_116 ++ ;
F_5 ( ( 1 << V_44 ) , & V_12 -> V_97 ) ;
F_36 ( V_18 ) ;
}
return V_117 ;
}
static void F_37 ( struct V_17 * V_18 )
{
const struct V_1 * V_2 = F_9 ( V_18 ) ;
const struct V_118 * V_119 = & V_2 -> V_7 . V_120 ;
struct V_11 T_2 * V_12 = V_2 -> V_13 ;
T_1 V_14 ;
V_14 = F_4 ( & V_12 -> V_32 ) ;
V_14 &= ~ ( F_38 ( 0xff ) |
F_39 ( 0x3 ) |
F_40 ( 0x7 ) |
F_41 ( 0x7 ) |
F_42 ( 0x7 ) |
V_121 |
V_122 |
V_123 ) ;
V_14 |= F_38 ( V_119 -> V_124 - 1 ) |
F_40 ( V_119 -> V_125 - 1 ) |
F_41 ( V_119 -> V_126 - 1 ) |
F_39 ( V_119 -> V_127 - 1 ) |
F_42 ( V_119 -> V_128 - 1 ) ;
if ( V_2 -> V_7 . V_8 & V_129 )
V_14 |= V_121 ;
if ( V_2 -> V_7 . V_8 & V_130 )
V_14 |= V_123 ;
if ( V_2 -> V_7 . V_8 & V_131 )
V_14 |= V_122 ;
F_43 ( V_18 -> V_18 . V_52 , L_11 , V_14 ) ;
F_5 ( V_14 , & V_12 -> V_32 ) ;
F_17 ( V_18 -> V_18 . V_52 , L_12 , V_132 ,
F_4 ( & V_12 -> V_15 ) , F_4 ( & V_12 -> V_32 ) ) ;
}
static int F_44 ( struct V_17 * V_18 )
{
struct V_1 * V_2 = F_9 ( V_18 ) ;
struct V_11 T_2 * V_12 = V_2 -> V_13 ;
unsigned int V_133 ;
int V_134 ;
T_1 V_135 , V_94 ;
F_3 ( V_2 ) ;
F_5 ( V_136 , & V_12 -> V_15 ) ;
F_6 ( 10 ) ;
V_135 = F_4 ( & V_12 -> V_15 ) ;
if ( V_135 & V_136 ) {
F_23 ( V_18 -> V_18 . V_52 ,
L_13 ,
V_135 ) ;
V_134 = - V_137 ;
goto V_138;
}
F_37 ( V_18 ) ;
V_135 = F_4 ( & V_12 -> V_15 ) ;
V_135 |= V_139 | V_140 | V_141 |
V_142 | V_143 |
V_144 ;
F_17 ( V_18 -> V_18 . V_52 , L_14 , V_132 , V_135 ) ;
F_5 ( V_135 , & V_12 -> V_15 ) ;
V_94 = F_4 ( & V_12 -> V_32 ) ;
V_94 &= ~ V_145 ;
V_94 |= V_146 | V_147 |
V_148 | V_149 ;
V_2 -> V_108 = V_94 ;
F_17 ( V_18 -> V_18 . V_52 , L_15 , V_132 , V_94 ) ;
F_5 ( V_94 , & V_12 -> V_32 ) ;
for ( V_133 = 0 ; V_133 < F_45 ( V_12 -> V_43 ) ; V_133 ++ ) {
F_5 ( 0 , & V_12 -> V_43 [ V_133 ] . V_45 ) ;
F_5 ( 0 , & V_12 -> V_43 [ V_133 ] . V_31 ) ;
F_5 ( 0 , & V_12 -> V_43 [ V_133 ] . V_30 [ 0 ] ) ;
F_5 ( 0 , & V_12 -> V_43 [ V_133 ] . V_30 [ 1 ] ) ;
F_5 ( F_11 ( 0x4 ) , & V_12 -> V_43 [ V_133 ] . V_45 ) ;
}
F_5 ( 0x0 , & V_12 -> V_150 ) ;
F_5 ( 0x0 , & V_12 -> V_151 ) ;
F_5 ( 0x0 , & V_12 -> V_152 ) ;
F_1 ( V_2 , 1 ) ;
V_135 = F_4 ( & V_12 -> V_15 ) ;
V_135 &= ~ V_141 ;
F_5 ( V_135 , & V_12 -> V_15 ) ;
V_2 -> V_7 . V_72 = V_73 ;
F_5 ( V_106 , & V_12 -> V_107 ) ;
F_17 ( V_18 -> V_18 . V_52 , L_16 ,
V_132 , F_4 ( & V_12 -> V_15 ) , F_4 ( & V_12 -> V_32 ) ) ;
return 0 ;
V_138:
F_7 ( V_2 ) ;
return V_134 ;
}
static void F_46 ( struct V_17 * V_18 )
{
struct V_1 * V_2 = F_9 ( V_18 ) ;
struct V_11 T_2 * V_12 = V_2 -> V_13 ;
T_1 V_14 ;
F_5 ( 0 , & V_12 -> V_107 ) ;
V_14 = F_4 ( & V_12 -> V_15 ) ;
V_14 |= V_16 | V_141 ;
F_5 ( V_14 , & V_12 -> V_15 ) ;
F_1 ( V_2 , 0 ) ;
V_2 -> V_7 . V_72 = V_153 ;
return;
}
static int F_47 ( struct V_17 * V_18 )
{
struct V_1 * V_2 = F_9 ( V_18 ) ;
int V_134 ;
F_48 ( V_2 -> V_154 ) ;
V_134 = F_49 ( V_18 ) ;
if ( V_134 )
goto V_138;
V_134 = F_50 ( V_18 -> V_109 , F_34 , V_155 , V_18 -> V_156 , V_18 ) ;
if ( V_134 )
goto V_157;
V_134 = F_44 ( V_18 ) ;
if ( V_134 )
goto V_157;
F_51 ( & V_2 -> V_101 ) ;
F_52 ( V_18 ) ;
return 0 ;
V_157:
F_53 ( V_18 ) ;
V_138:
F_54 ( V_2 -> V_154 ) ;
return V_134 ;
}
static int F_55 ( struct V_17 * V_18 )
{
struct V_1 * V_2 = F_9 ( V_18 ) ;
F_13 ( V_18 ) ;
F_56 ( & V_2 -> V_101 ) ;
F_46 ( V_18 ) ;
F_57 ( V_18 -> V_109 , V_18 ) ;
F_54 ( V_2 -> V_154 ) ;
F_53 ( V_18 ) ;
return 0 ;
}
static int F_58 ( struct V_17 * V_18 , enum V_158 V_159 )
{
int V_134 ;
switch ( V_159 ) {
case V_160 :
V_134 = F_44 ( V_18 ) ;
if ( V_134 )
return V_134 ;
F_36 ( V_18 ) ;
break;
default:
return - V_161 ;
}
return 0 ;
}
static int T_4 F_59 ( struct V_17 * V_18 )
{
struct V_1 * V_2 = F_9 ( V_18 ) ;
struct V_11 T_2 * V_12 = V_2 -> V_13 ;
T_1 V_14 , V_134 ;
F_48 ( V_2 -> V_154 ) ;
F_7 ( V_2 ) ;
V_14 = F_4 ( & V_12 -> V_32 ) ;
V_14 |= V_162 ;
F_5 ( V_14 , & V_12 -> V_32 ) ;
F_3 ( V_2 ) ;
V_14 = F_4 ( & V_12 -> V_15 ) ;
V_14 |= V_139 | V_141 |
V_140 | V_142 ;
F_5 ( V_14 , & V_12 -> V_15 ) ;
V_14 = F_4 ( & V_12 -> V_15 ) ;
if ( ! ( V_14 & V_140 ) ) {
F_23 ( V_18 -> V_18 . V_52 ,
L_17 ) ;
V_134 = - V_137 ;
goto V_138;
}
V_134 = F_60 ( V_18 ) ;
V_138:
F_7 ( V_2 ) ;
F_54 ( V_2 -> V_154 ) ;
return V_134 ;
}
static void T_5 F_61 ( struct V_17 * V_18 )
{
F_62 ( V_18 ) ;
}
static int T_4 F_63 ( struct V_163 * V_164 )
{
struct V_17 * V_18 ;
struct V_1 * V_2 ;
struct V_165 * V_166 ;
struct V_154 * V_154 ;
void T_2 * V_13 ;
T_6 V_167 ;
int V_134 , V_109 ;
V_154 = F_64 ( & V_164 -> V_18 , NULL ) ;
if ( F_65 ( V_154 ) ) {
F_23 ( & V_164 -> V_18 , L_18 ) ;
V_134 = F_66 ( V_154 ) ;
goto V_168;
}
V_166 = F_67 ( V_164 , V_169 , 0 ) ;
V_109 = F_68 ( V_164 , 0 ) ;
if ( ! V_166 || V_109 <= 0 ) {
V_134 = - V_137 ;
goto V_170;
}
V_167 = F_69 ( V_166 ) ;
if ( ! F_70 ( V_166 -> V_171 , V_167 , V_164 -> V_156 ) ) {
V_134 = - V_172 ;
goto V_170;
}
V_13 = F_71 ( V_166 -> V_171 , V_167 ) ;
if ( ! V_13 ) {
V_134 = - V_173 ;
goto V_174;
}
V_18 = F_72 ( sizeof( struct V_1 ) , 0 ) ;
if ( ! V_18 ) {
V_134 = - V_173 ;
goto V_175;
}
V_18 -> V_176 = & V_177 ;
V_18 -> V_109 = V_109 ;
V_18 -> V_178 |= V_179 ;
V_2 = F_9 ( V_18 ) ;
V_2 -> V_7 . clock . V_180 = F_73 ( V_154 ) ;
V_2 -> V_7 . V_181 = & V_182 ;
V_2 -> V_7 . V_183 = F_58 ;
V_2 -> V_7 . V_184 = F_8 ;
V_2 -> V_7 . V_185 = V_129 |
V_130 | V_131 |
V_9 ;
V_2 -> V_13 = V_13 ;
V_2 -> V_18 = V_18 ;
V_2 -> V_154 = V_154 ;
V_2 -> V_4 = V_164 -> V_18 . V_186 ;
F_74 ( V_18 , & V_2 -> V_101 , F_32 , V_187 ) ;
F_75 ( & V_164 -> V_18 , V_18 ) ;
F_76 ( V_18 , & V_164 -> V_18 ) ;
V_134 = F_59 ( V_18 ) ;
if ( V_134 ) {
F_23 ( & V_164 -> V_18 , L_19 ) ;
goto V_188;
}
F_43 ( & V_164 -> V_18 , L_20 ,
V_2 -> V_13 , V_18 -> V_109 ) ;
return 0 ;
V_188:
F_77 ( V_18 ) ;
V_175:
F_78 ( V_13 ) ;
V_174:
F_79 ( V_166 -> V_171 , V_167 ) ;
V_170:
F_80 ( V_154 ) ;
V_168:
return V_134 ;
}
static int T_5 F_81 ( struct V_163 * V_164 )
{
struct V_17 * V_18 = F_82 ( V_164 ) ;
struct V_1 * V_2 = F_9 ( V_18 ) ;
struct V_165 * V_166 ;
F_61 ( V_18 ) ;
F_83 ( V_164 , NULL ) ;
F_78 ( V_2 -> V_13 ) ;
V_166 = F_67 ( V_164 , V_169 , 0 ) ;
F_79 ( V_166 -> V_171 , F_69 ( V_166 ) ) ;
F_80 ( V_2 -> V_154 ) ;
F_77 ( V_18 ) ;
return 0 ;
}
static int T_7 F_84 ( void )
{
F_85 ( L_21 , V_189 ) ;
return F_86 ( & V_190 ) ;
}
static void T_8 F_87 ( void )
{
F_88 ( & V_190 ) ;
F_85 ( L_22 , V_189 ) ;
}
