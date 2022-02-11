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
static inline int F_7 ( const struct V_3 * V_4 )
{
if ( ! V_4 -> V_5 )
return 0 ;
return F_8 ( V_4 -> V_5 ) ;
}
static inline int F_9 ( const struct V_3 * V_4 )
{
if ( ! V_4 -> V_5 )
return 0 ;
return F_10 ( V_4 -> V_5 ) ;
}
static inline int F_11 ( const struct V_3 * V_4 ,
T_1 V_6 )
{
return ( V_4 -> V_7 . V_8 & V_9 ) &&
( V_6 & V_10 ) ;
}
static int F_12 ( struct V_3 * V_4 )
{
struct V_11 T_2 * V_12 = V_4 -> V_13 ;
unsigned int V_14 = V_15 / 10 ;
T_1 V_16 ;
V_16 = F_1 ( & V_12 -> V_17 ) ;
V_16 &= ~ V_18 ;
F_3 ( V_16 , & V_12 -> V_17 ) ;
while ( V_14 -- && ( F_1 ( & V_12 -> V_17 ) & V_19 ) )
F_13 ( 10 ) ;
if ( F_1 ( & V_12 -> V_17 ) & V_19 )
return - V_20 ;
return 0 ;
}
static int F_14 ( struct V_3 * V_4 )
{
struct V_11 T_2 * V_12 = V_4 -> V_13 ;
unsigned int V_14 = V_15 / 10 ;
T_1 V_16 ;
V_16 = F_1 ( & V_12 -> V_17 ) ;
V_16 |= V_18 ;
F_3 ( V_16 , & V_12 -> V_17 ) ;
while ( V_14 -- && ! ( F_1 ( & V_12 -> V_17 ) & V_19 ) )
F_13 ( 10 ) ;
if ( ! ( F_1 ( & V_12 -> V_17 ) & V_19 ) )
return - V_20 ;
return 0 ;
}
static int F_15 ( struct V_3 * V_4 )
{
struct V_11 T_2 * V_12 = V_4 -> V_13 ;
unsigned int V_14 = 1000 * 1000 * 10 / V_4 -> V_7 . V_21 . V_22 ;
T_1 V_16 ;
V_16 = F_1 ( & V_12 -> V_17 ) ;
V_16 |= V_23 ;
F_3 ( V_16 , & V_12 -> V_17 ) ;
while ( V_14 -- && ! ( F_1 ( & V_12 -> V_17 ) & V_24 ) )
F_13 ( 100 ) ;
if ( ! ( F_1 ( & V_12 -> V_17 ) & V_24 ) )
return - V_20 ;
return 0 ;
}
static int F_16 ( struct V_3 * V_4 )
{
struct V_11 T_2 * V_12 = V_4 -> V_13 ;
unsigned int V_14 = V_15 / 10 ;
T_1 V_16 ;
V_16 = F_1 ( & V_12 -> V_17 ) ;
V_16 &= ~ V_23 ;
F_3 ( V_16 , & V_12 -> V_17 ) ;
while ( V_14 -- && ( F_1 ( & V_12 -> V_17 ) & V_24 ) )
F_13 ( 10 ) ;
if ( F_1 ( & V_12 -> V_17 ) & V_24 )
return - V_20 ;
return 0 ;
}
static int F_17 ( struct V_3 * V_4 )
{
struct V_11 T_2 * V_12 = V_4 -> V_13 ;
unsigned int V_14 = V_15 / 10 ;
F_3 ( V_25 , & V_12 -> V_17 ) ;
while ( V_14 -- && ( F_1 ( & V_12 -> V_17 ) & V_25 ) )
F_13 ( 10 ) ;
if ( F_1 ( & V_12 -> V_17 ) & V_25 )
return - V_20 ;
return 0 ;
}
static int F_18 ( const struct V_26 * V_27 ,
struct V_28 * V_29 )
{
const struct V_3 * V_4 = F_19 ( V_27 ) ;
struct V_11 T_2 * V_12 = V_4 -> V_13 ;
T_1 V_16 = F_1 ( & V_12 -> V_30 ) ;
V_29 -> V_31 = ( V_16 >> 0 ) & 0xff ;
V_29 -> V_32 = ( V_16 >> 8 ) & 0xff ;
return 0 ;
}
static int F_20 ( struct V_33 * V_34 , struct V_26 * V_27 )
{
const struct V_3 * V_4 = F_19 ( V_27 ) ;
struct V_11 T_2 * V_12 = V_4 -> V_13 ;
struct V_35 * V_36 = (struct V_35 * ) V_34 -> V_37 ;
T_1 V_38 ;
T_1 V_39 = F_21 ( 0xc ) | ( V_36 -> V_40 << 16 ) ;
if ( F_22 ( V_27 , V_34 ) )
return V_41 ;
F_23 ( V_27 ) ;
if ( V_36 -> V_38 & V_42 ) {
V_38 = V_36 -> V_38 & V_43 ;
V_39 |= V_44 | V_45 ;
} else {
V_38 = ( V_36 -> V_38 & V_46 ) << 18 ;
}
if ( V_36 -> V_38 & V_47 )
V_39 |= V_48 ;
if ( V_36 -> V_40 > 0 ) {
T_1 V_37 = F_24 ( ( V_49 * ) & V_36 -> V_37 [ 0 ] ) ;
F_3 ( V_37 , & V_12 -> V_50 [ V_51 ] . V_37 [ 0 ] ) ;
}
if ( V_36 -> V_40 > 3 ) {
T_1 V_37 = F_24 ( ( V_49 * ) & V_36 -> V_37 [ 4 ] ) ;
F_3 ( V_37 , & V_12 -> V_50 [ V_51 ] . V_37 [ 1 ] ) ;
}
F_25 ( V_34 , V_27 , 0 ) ;
F_3 ( V_38 , & V_12 -> V_50 [ V_51 ] . V_38 ) ;
F_3 ( V_39 , & V_12 -> V_50 [ V_51 ] . V_52 ) ;
F_3 ( V_53 ,
& V_12 -> V_50 [ V_54 ] . V_52 ) ;
F_3 ( V_53 ,
& V_12 -> V_50 [ V_54 ] . V_52 ) ;
return V_41 ;
}
static void F_26 ( struct V_26 * V_27 ,
struct V_35 * V_36 , T_1 V_6 )
{
struct V_3 * V_4 = F_19 ( V_27 ) ;
int V_55 = 0 , V_56 = 0 ;
V_36 -> V_38 |= V_57 | V_58 ;
if ( V_6 & V_59 ) {
F_27 ( V_27 , L_1 ) ;
V_36 -> V_37 [ 2 ] |= V_60 ;
V_56 = 1 ;
}
if ( V_6 & V_61 ) {
F_27 ( V_27 , L_2 ) ;
V_36 -> V_37 [ 2 ] |= V_62 ;
V_56 = 1 ;
}
if ( V_6 & V_63 ) {
F_27 ( V_27 , L_3 ) ;
V_36 -> V_38 |= V_64 ;
V_36 -> V_37 [ 3 ] |= V_65 ;
V_56 = 1 ;
}
if ( V_6 & V_66 ) {
F_27 ( V_27 , L_4 ) ;
V_36 -> V_37 [ 2 ] |= V_67 ;
V_36 -> V_37 [ 3 ] |= V_68 ;
V_55 = 1 ;
}
if ( V_6 & V_69 ) {
F_27 ( V_27 , L_5 ) ;
V_36 -> V_37 [ 2 ] |= V_70 ;
V_55 = 1 ;
}
if ( V_6 & V_71 ) {
F_27 ( V_27 , L_6 ) ;
V_36 -> V_37 [ 2 ] |= V_72 ;
V_55 = 1 ;
}
V_4 -> V_7 . V_73 . V_74 ++ ;
if ( V_55 )
V_27 -> V_75 . V_55 ++ ;
if ( V_56 )
V_27 -> V_75 . V_56 ++ ;
}
static int F_28 ( struct V_26 * V_27 , T_1 V_6 )
{
struct V_33 * V_34 ;
struct V_35 * V_36 ;
V_34 = F_29 ( V_27 , & V_36 ) ;
if ( F_30 ( ! V_34 ) )
return 0 ;
F_26 ( V_27 , V_36 , V_6 ) ;
F_31 ( V_34 ) ;
V_27 -> V_75 . V_76 ++ ;
V_27 -> V_75 . V_77 += V_36 -> V_40 ;
return 1 ;
}
static void F_32 ( struct V_26 * V_27 ,
struct V_35 * V_36 , enum V_78 V_79 )
{
struct V_3 * V_4 = F_19 ( V_27 ) ;
struct V_28 V_29 ;
F_18 ( V_27 , & V_29 ) ;
switch ( V_4 -> V_7 . V_80 ) {
case V_81 :
if ( V_79 >= V_82 &&
V_79 <= V_83 ) {
F_27 ( V_27 , L_7 ) ;
V_4 -> V_7 . V_73 . V_84 ++ ;
V_36 -> V_38 |= V_85 ;
V_36 -> V_37 [ 1 ] = ( V_29 . V_31 > V_29 . V_32 ) ?
V_86 :
V_87 ;
}
case V_82 :
if ( V_79 >= V_88 &&
V_79 <= V_83 ) {
F_27 ( V_27 , L_8 ) ;
V_4 -> V_7 . V_73 . V_89 ++ ;
V_36 -> V_38 |= V_85 ;
V_36 -> V_37 [ 1 ] = ( V_29 . V_31 > V_29 . V_32 ) ?
V_90 :
V_91 ;
}
break;
case V_83 :
F_33 ( V_27 , L_9
L_10 ) ;
break;
default:
break;
}
switch ( V_79 ) {
case V_82 :
F_27 ( V_27 , L_11 ) ;
V_36 -> V_38 |= V_85 ;
V_36 -> V_37 [ 1 ] = ( V_29 . V_31 > V_29 . V_32 ) ?
V_86 :
V_87 ;
break;
case V_81 :
F_27 ( V_27 , L_12 ) ;
V_36 -> V_38 |= V_57 ;
V_36 -> V_37 [ 2 ] = V_92 ;
break;
case V_83 :
V_36 -> V_38 |= V_93 ;
F_34 ( V_27 ) ;
break;
default:
break;
}
}
static int F_35 ( struct V_26 * V_27 , T_1 V_6 )
{
struct V_3 * V_4 = F_19 ( V_27 ) ;
struct V_33 * V_34 ;
struct V_35 * V_36 ;
enum V_78 V_79 ;
int V_94 ;
V_94 = V_6 & V_95 ;
if ( F_36 ( V_94 == V_96 ) ) {
if ( F_36 ( ! ( V_6 & ( V_97 |
V_98 ) ) ) )
V_79 = V_81 ;
else
V_79 = V_82 ;
} else if ( F_30 ( V_94 == V_99 ) )
V_79 = V_88 ;
else
V_79 = V_83 ;
if ( F_36 ( V_79 == V_4 -> V_7 . V_80 ) )
return 0 ;
V_34 = F_29 ( V_27 , & V_36 ) ;
if ( F_30 ( ! V_34 ) )
return 0 ;
F_32 ( V_27 , V_36 , V_79 ) ;
V_4 -> V_7 . V_80 = V_79 ;
F_31 ( V_34 ) ;
V_27 -> V_75 . V_76 ++ ;
V_27 -> V_75 . V_77 += V_36 -> V_40 ;
return 1 ;
}
static void F_37 ( const struct V_26 * V_27 ,
struct V_35 * V_36 )
{
const struct V_3 * V_4 = F_19 ( V_27 ) ;
struct V_11 T_2 * V_12 = V_4 -> V_13 ;
struct V_100 T_2 * V_101 = & V_12 -> V_50 [ 0 ] ;
T_1 V_102 , V_103 ;
V_102 = F_1 ( & V_101 -> V_52 ) ;
V_103 = F_1 ( & V_101 -> V_38 ) ;
if ( V_102 & V_44 )
V_36 -> V_38 = ( ( V_103 >> 0 ) & V_43 ) | V_42 ;
else
V_36 -> V_38 = ( V_103 >> 18 ) & V_46 ;
if ( V_102 & V_48 )
V_36 -> V_38 |= V_47 ;
V_36 -> V_40 = F_38 ( ( V_102 >> 16 ) & 0xf ) ;
* ( V_49 * ) ( V_36 -> V_37 + 0 ) = F_39 ( F_1 ( & V_101 -> V_37 [ 0 ] ) ) ;
* ( V_49 * ) ( V_36 -> V_37 + 4 ) = F_39 ( F_1 ( & V_101 -> V_37 [ 1 ] ) ) ;
F_3 ( V_104 , & V_12 -> V_105 ) ;
F_1 ( & V_12 -> V_106 ) ;
}
static int F_40 ( struct V_26 * V_27 )
{
struct V_107 * V_75 = & V_27 -> V_75 ;
struct V_35 * V_36 ;
struct V_33 * V_34 ;
V_34 = F_41 ( V_27 , & V_36 ) ;
if ( F_30 ( ! V_34 ) ) {
V_75 -> V_108 ++ ;
return 0 ;
}
F_37 ( V_27 , V_36 ) ;
F_31 ( V_34 ) ;
V_75 -> V_76 ++ ;
V_75 -> V_77 += V_36 -> V_40 ;
F_42 ( V_27 , V_109 ) ;
return 1 ;
}
static int F_43 ( struct V_110 * V_111 , int V_112 )
{
struct V_26 * V_27 = V_111 -> V_27 ;
const struct V_3 * V_4 = F_19 ( V_27 ) ;
struct V_11 T_2 * V_12 = V_4 -> V_13 ;
T_1 V_113 , V_6 ;
int V_114 = 0 ;
V_6 = F_1 ( & V_12 -> V_115 ) | V_4 -> V_6 ;
V_114 += F_35 ( V_27 , V_6 ) ;
V_113 = F_1 ( & V_12 -> V_105 ) ;
while ( V_113 & V_104 &&
V_114 < V_112 ) {
V_114 += F_40 ( V_27 ) ;
V_113 = F_1 ( & V_12 -> V_105 ) ;
}
if ( F_11 ( V_4 , V_6 ) && V_114 < V_112 )
V_114 += F_28 ( V_27 , V_6 ) ;
if ( V_114 < V_112 ) {
F_44 ( V_111 ) ;
F_3 ( V_116 , & V_12 -> V_117 ) ;
F_3 ( V_4 -> V_118 , & V_12 -> V_39 ) ;
}
return V_114 ;
}
static T_3 F_45 ( int V_119 , void * V_120 )
{
struct V_26 * V_27 = V_120 ;
struct V_107 * V_75 = & V_27 -> V_75 ;
struct V_3 * V_4 = F_19 ( V_27 ) ;
struct V_11 T_2 * V_12 = V_4 -> V_13 ;
T_1 V_113 , V_6 ;
V_113 = F_1 ( & V_12 -> V_105 ) ;
V_6 = F_1 ( & V_12 -> V_115 ) ;
if ( V_6 & V_121 )
F_3 ( V_6 & V_121 , & V_12 -> V_115 ) ;
if ( ( V_113 & V_104 ) ||
( V_6 & V_122 ) ||
F_11 ( V_4 , V_6 ) ) {
V_4 -> V_6 = V_6 & V_10 ;
F_3 ( V_116 &
~ V_104 , & V_12 -> V_117 ) ;
F_3 ( V_4 -> V_118 & ~ V_123 ,
& V_12 -> V_39 ) ;
F_46 ( & V_4 -> V_111 ) ;
}
if ( V_113 & V_124 ) {
F_3 ( V_124 , & V_12 -> V_105 ) ;
V_27 -> V_75 . V_125 ++ ;
V_27 -> V_75 . V_55 ++ ;
}
if ( V_113 & ( 1 << V_51 ) ) {
V_75 -> V_126 += F_47 ( V_27 , 0 ) ;
V_75 -> V_127 ++ ;
F_42 ( V_27 , V_128 ) ;
F_3 ( V_53 ,
& V_12 -> V_50 [ V_51 ] . V_52 ) ;
F_3 ( ( 1 << V_51 ) , & V_12 -> V_105 ) ;
F_48 ( V_27 ) ;
}
return V_129 ;
}
static void F_49 ( struct V_26 * V_27 )
{
const struct V_3 * V_4 = F_19 ( V_27 ) ;
const struct V_130 * V_131 = & V_4 -> V_7 . V_21 ;
struct V_11 T_2 * V_12 = V_4 -> V_13 ;
T_1 V_16 ;
V_16 = F_1 ( & V_12 -> V_39 ) ;
V_16 &= ~ ( F_50 ( 0xff ) |
F_51 ( 0x3 ) |
F_52 ( 0x7 ) |
F_53 ( 0x7 ) |
F_54 ( 0x7 ) |
V_132 |
V_133 |
V_134 ) ;
V_16 |= F_50 ( V_131 -> V_135 - 1 ) |
F_52 ( V_131 -> V_136 - 1 ) |
F_53 ( V_131 -> V_137 - 1 ) |
F_51 ( V_131 -> V_138 - 1 ) |
F_54 ( V_131 -> V_139 - 1 ) ;
if ( V_4 -> V_7 . V_8 & V_140 )
V_16 |= V_132 ;
if ( V_4 -> V_7 . V_8 & V_141 )
V_16 |= V_134 ;
if ( V_4 -> V_7 . V_8 & V_142 )
V_16 |= V_133 ;
F_55 ( V_27 , L_13 , V_16 ) ;
F_3 ( V_16 , & V_12 -> V_39 ) ;
F_27 ( V_27 , L_14 , V_143 ,
F_1 ( & V_12 -> V_17 ) , F_1 ( & V_12 -> V_39 ) ) ;
}
static int F_56 ( struct V_26 * V_27 )
{
struct V_3 * V_4 = F_19 ( V_27 ) ;
struct V_11 T_2 * V_12 = V_4 -> V_13 ;
int V_144 ;
T_1 V_145 , V_102 ;
int V_146 ;
V_144 = F_12 ( V_4 ) ;
if ( V_144 )
return V_144 ;
V_144 = F_17 ( V_4 ) ;
if ( V_144 )
goto V_147;
F_49 ( V_27 ) ;
V_145 = F_1 ( & V_12 -> V_17 ) ;
V_145 &= ~ F_57 ( 0xff ) ;
V_145 |= V_148 | V_149 | V_23 |
V_150 | V_151 |
V_152 | V_153 |
F_57 ( V_51 ) ;
F_27 ( V_27 , L_15 , V_143 , V_145 ) ;
F_3 ( V_145 , & V_12 -> V_17 ) ;
V_102 = F_1 ( & V_12 -> V_39 ) ;
V_102 &= ~ V_154 ;
V_102 |= V_155 | V_156 |
V_157 ;
if ( V_4 -> V_158 -> V_159 & V_160 ||
V_4 -> V_7 . V_8 & V_9 )
V_102 |= V_161 ;
else
V_102 &= ~ V_161 ;
V_4 -> V_118 = V_102 ;
F_27 ( V_27 , L_16 , V_143 , V_102 ) ;
F_3 ( V_102 , & V_12 -> V_39 ) ;
for ( V_146 = V_51 ; V_146 < F_58 ( V_12 -> V_50 ) ; V_146 ++ ) {
F_3 ( V_162 ,
& V_12 -> V_50 [ V_146 ] . V_52 ) ;
}
F_3 ( V_53 ,
& V_12 -> V_50 [ V_54 ] . V_52 ) ;
F_3 ( V_53 ,
& V_12 -> V_50 [ V_51 ] . V_52 ) ;
F_3 ( 0x0 , & V_12 -> V_163 ) ;
F_3 ( 0x0 , & V_12 -> V_164 ) ;
F_3 ( 0x0 , & V_12 -> V_165 ) ;
if ( V_4 -> V_158 -> V_159 & V_166 )
F_3 ( 0x0 , & V_12 -> V_167 ) ;
V_144 = F_7 ( V_4 ) ;
if ( V_144 )
goto V_147;
V_144 = F_16 ( V_4 ) ;
if ( V_144 )
goto V_168;
V_4 -> V_7 . V_80 = V_81 ;
F_3 ( V_116 , & V_12 -> V_117 ) ;
F_27 ( V_27 , L_17 , V_143 ,
F_1 ( & V_12 -> V_17 ) , F_1 ( & V_12 -> V_39 ) ) ;
return 0 ;
V_168:
F_9 ( V_4 ) ;
V_147:
F_14 ( V_4 ) ;
return V_144 ;
}
static void F_59 ( struct V_26 * V_27 )
{
struct V_3 * V_4 = F_19 ( V_27 ) ;
struct V_11 T_2 * V_12 = V_4 -> V_13 ;
F_15 ( V_4 ) ;
F_14 ( V_4 ) ;
F_3 ( 0 , & V_12 -> V_117 ) ;
F_3 ( V_4 -> V_118 & ~ V_123 ,
& V_12 -> V_39 ) ;
F_9 ( V_4 ) ;
V_4 -> V_7 . V_80 = V_169 ;
return;
}
static int F_60 ( struct V_26 * V_27 )
{
struct V_3 * V_4 = F_19 ( V_27 ) ;
int V_144 ;
V_144 = F_61 ( V_4 -> V_170 ) ;
if ( V_144 )
return V_144 ;
V_144 = F_61 ( V_4 -> V_171 ) ;
if ( V_144 )
goto V_172;
V_144 = F_62 ( V_27 ) ;
if ( V_144 )
goto V_173;
V_144 = F_63 ( V_27 -> V_119 , F_45 , V_174 , V_27 -> V_175 , V_27 ) ;
if ( V_144 )
goto V_176;
V_144 = F_56 ( V_27 ) ;
if ( V_144 )
goto V_177;
F_42 ( V_27 , V_178 ) ;
F_64 ( & V_4 -> V_111 ) ;
F_65 ( V_27 ) ;
return 0 ;
V_177:
F_66 ( V_27 -> V_119 , V_27 ) ;
V_176:
F_67 ( V_27 ) ;
V_173:
F_68 ( V_4 -> V_171 ) ;
V_172:
F_68 ( V_4 -> V_170 ) ;
return V_144 ;
}
static int F_69 ( struct V_26 * V_27 )
{
struct V_3 * V_4 = F_19 ( V_27 ) ;
F_23 ( V_27 ) ;
F_70 ( & V_4 -> V_111 ) ;
F_59 ( V_27 ) ;
F_66 ( V_27 -> V_119 , V_27 ) ;
F_68 ( V_4 -> V_171 ) ;
F_68 ( V_4 -> V_170 ) ;
F_67 ( V_27 ) ;
F_42 ( V_27 , V_179 ) ;
return 0 ;
}
static int F_71 ( struct V_26 * V_27 , enum V_180 V_181 )
{
int V_144 ;
switch ( V_181 ) {
case V_182 :
V_144 = F_56 ( V_27 ) ;
if ( V_144 )
return V_144 ;
F_48 ( V_27 ) ;
break;
default:
return - V_183 ;
}
return 0 ;
}
static int F_72 ( struct V_26 * V_27 )
{
struct V_3 * V_4 = F_19 ( V_27 ) ;
struct V_11 T_2 * V_12 = V_4 -> V_13 ;
T_1 V_16 , V_144 ;
V_144 = F_61 ( V_4 -> V_170 ) ;
if ( V_144 )
return V_144 ;
V_144 = F_61 ( V_4 -> V_171 ) ;
if ( V_144 )
goto V_172;
V_144 = F_14 ( V_4 ) ;
if ( V_144 )
goto V_173;
V_16 = F_1 ( & V_12 -> V_39 ) ;
V_16 |= V_184 ;
F_3 ( V_16 , & V_12 -> V_39 ) ;
V_144 = F_12 ( V_4 ) ;
if ( V_144 )
goto V_147;
V_16 = F_1 ( & V_12 -> V_17 ) ;
V_16 |= V_148 | V_23 |
V_149 | V_150 ;
F_3 ( V_16 , & V_12 -> V_17 ) ;
V_16 = F_1 ( & V_12 -> V_17 ) ;
if ( ! ( V_16 & V_149 ) ) {
F_33 ( V_27 , L_18 ) ;
V_144 = - V_185 ;
goto V_147;
}
V_144 = F_73 ( V_27 ) ;
V_147:
F_14 ( V_4 ) ;
V_173:
F_68 ( V_4 -> V_171 ) ;
V_172:
F_68 ( V_4 -> V_170 ) ;
return V_144 ;
}
static void F_74 ( struct V_26 * V_27 )
{
F_75 ( V_27 ) ;
}
static int F_76 ( struct V_186 * V_187 )
{
const struct V_188 * V_189 ;
const struct V_190 * V_158 ;
struct V_26 * V_27 ;
struct V_3 * V_4 ;
struct V_191 * V_192 ;
struct V_193 * V_170 = NULL , * V_171 = NULL ;
void T_2 * V_13 ;
int V_144 , V_119 ;
T_1 V_194 = 0 ;
if ( V_187 -> V_27 . V_195 )
F_77 ( V_187 -> V_27 . V_195 ,
L_19 , & V_194 ) ;
if ( ! V_194 ) {
V_170 = F_78 ( & V_187 -> V_27 , L_20 ) ;
if ( F_79 ( V_170 ) ) {
F_80 ( & V_187 -> V_27 , L_21 ) ;
return F_81 ( V_170 ) ;
}
V_171 = F_78 ( & V_187 -> V_27 , L_22 ) ;
if ( F_79 ( V_171 ) ) {
F_80 ( & V_187 -> V_27 , L_23 ) ;
return F_81 ( V_171 ) ;
}
V_194 = F_82 ( V_171 ) ;
}
V_192 = F_83 ( V_187 , V_196 , 0 ) ;
V_119 = F_84 ( V_187 , 0 ) ;
if ( V_119 <= 0 )
return - V_185 ;
V_13 = F_85 ( & V_187 -> V_27 , V_192 ) ;
if ( F_79 ( V_13 ) )
return F_81 ( V_13 ) ;
V_189 = F_86 ( V_197 , & V_187 -> V_27 ) ;
if ( V_189 ) {
V_158 = V_189 -> V_37 ;
} else if ( F_87 ( V_187 ) -> V_198 ) {
V_158 = (struct V_190 * )
F_87 ( V_187 ) -> V_198 ;
} else {
return - V_185 ;
}
V_27 = F_88 ( sizeof( struct V_3 ) , 1 ) ;
if ( ! V_27 )
return - V_199 ;
V_27 -> V_200 = & V_201 ;
V_27 -> V_119 = V_119 ;
V_27 -> V_202 |= V_203 ;
V_4 = F_19 ( V_27 ) ;
V_4 -> V_7 . clock . V_204 = V_194 ;
V_4 -> V_7 . V_205 = & V_206 ;
V_4 -> V_7 . V_207 = F_71 ;
V_4 -> V_7 . V_208 = F_18 ;
V_4 -> V_7 . V_209 = V_140 |
V_141 | V_142 |
V_9 ;
V_4 -> V_13 = V_13 ;
V_4 -> V_27 = V_27 ;
V_4 -> V_170 = V_170 ;
V_4 -> V_171 = V_171 ;
V_4 -> V_210 = F_89 ( & V_187 -> V_27 ) ;
V_4 -> V_158 = V_158 ;
V_4 -> V_5 = F_90 ( & V_187 -> V_27 , L_24 ) ;
if ( F_79 ( V_4 -> V_5 ) )
V_4 -> V_5 = NULL ;
F_91 ( V_27 , & V_4 -> V_111 , F_43 , V_211 ) ;
F_92 ( V_187 , V_27 ) ;
F_93 ( V_27 , & V_187 -> V_27 ) ;
V_144 = F_72 ( V_27 ) ;
if ( V_144 ) {
F_80 ( & V_187 -> V_27 , L_25 ) ;
goto V_212;
}
F_94 ( V_27 ) ;
F_95 ( & V_187 -> V_27 , L_26 ,
V_4 -> V_13 , V_27 -> V_119 ) ;
return 0 ;
V_212:
F_96 ( V_27 ) ;
return V_144 ;
}
static int F_97 ( struct V_186 * V_187 )
{
struct V_26 * V_27 = F_98 ( V_187 ) ;
struct V_3 * V_4 = F_19 ( V_27 ) ;
F_74 ( V_27 ) ;
F_99 ( & V_4 -> V_111 ) ;
F_96 ( V_27 ) ;
return 0 ;
}
static int T_4 F_100 ( struct V_213 * V_213 )
{
struct V_26 * V_27 = F_101 ( V_213 ) ;
struct V_3 * V_4 = F_19 ( V_27 ) ;
int V_144 ;
V_144 = F_14 ( V_4 ) ;
if ( V_144 )
return V_144 ;
if ( F_102 ( V_27 ) ) {
F_23 ( V_27 ) ;
F_103 ( V_27 ) ;
}
V_4 -> V_7 . V_80 = V_214 ;
return 0 ;
}
static int T_4 F_104 ( struct V_213 * V_213 )
{
struct V_26 * V_27 = F_101 ( V_213 ) ;
struct V_3 * V_4 = F_19 ( V_27 ) ;
V_4 -> V_7 . V_80 = V_81 ;
if ( F_102 ( V_27 ) ) {
F_105 ( V_27 ) ;
F_65 ( V_27 ) ;
}
return F_12 ( V_4 ) ;
}
