static int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_5 * V_6 = V_4 -> V_6 ;
struct V_7 * V_8 = V_4 -> V_8 ;
struct V_9 * V_10 ;
struct V_11 V_12 ;
int V_13 = F_2 ( 1 , 8 ) ;
int V_14 = F_2 ( 8 , 1 ) ;
if ( ! V_8 || ! V_6 )
return 0 ;
V_10 = F_3 ( V_4 -> V_15 ,
V_8 ) ;
if ( F_4 ( ! V_10 ) )
return - V_16 ;
if ( ! V_10 -> V_17 )
return 0 ;
if ( ! V_4 -> V_8 )
return - V_16 ;
V_12 . V_18 = 0 ;
V_12 . y1 = 0 ;
V_12 . V_19 = V_10 -> V_20 . V_21 ;
V_12 . V_22 = V_10 -> V_20 . V_23 ;
return F_5 ( V_4 , & V_12 ,
V_13 , V_14 ,
true , true ) ;
}
static int F_6 ( T_1 V_24 )
{
switch ( V_24 ) {
case V_25 :
return V_26 ;
case V_27 :
return V_28 | V_26 ;
case V_29 :
return V_30 | V_31 ;
case V_32 :
return V_33 | V_31 ;
case V_34 :
return V_35 | V_31 ;
case V_36 :
return V_37 | V_31 ;
case V_38 :
return V_39 ;
default:
F_7 ( 1 , L_1 , V_24 ) ;
return - V_16 ;
}
}
static inline void F_8 ( struct V_40 * V_41 )
{
void T_2 * V_42 = V_41 -> V_42 ;
F_9 ( V_42 + V_43 , V_44 , V_44 ) ;
}
static inline void F_10 ( struct V_40 * V_41 )
{
F_11 ( V_41 -> V_45 + V_46 , 1 ) ;
}
static int F_12 ( T_1 V_24 )
{
switch ( V_24 ) {
case V_25 :
case V_27 :
return V_47 ;
case V_29 :
case V_32 :
case V_34 :
case V_36 :
return V_48 ;
case V_38 :
return V_49 ;
default:
F_7 ( 1 , L_1 , V_24 ) ;
return - V_16 ;
}
}
static inline T_3 F_13 ( T_3 V_50 , T_3 V_51 )
{
T_3 V_52 = 0 ;
if ( V_50 == V_51 )
V_52 = 0 ;
else if ( V_50 < V_51 )
V_52 = F_14 ( ( V_50 << 16 ) / V_51 ) ;
else if ( V_50 > V_51 )
V_52 = F_15 ( V_50 / V_51 ) |
F_14 ( ( ( V_50 << 16 ) / V_51 ) & 0xffff ) ;
return V_52 ;
}
static void F_16 ( struct V_40 * V_41 , T_1 V_24 ,
T_3 V_53 , T_3 V_54 , T_3 V_55 , T_3 V_56 )
{
void T_2 * V_45 = V_41 -> V_45 ;
T_3 V_57 = V_53 ;
T_3 V_58 = V_54 ;
int V_59 ;
F_11 ( V_45 + V_60 , F_17 ( V_54 - 1 ) | F_18 ( V_53 - 1 ) ) ;
F_11 ( V_45 + V_61 , F_17 ( V_56 - 1 ) | F_18 ( V_55 - 1 ) ) ;
V_59 = F_12 ( V_24 ) ;
if ( V_59 >= 0 )
F_9 ( V_45 + V_62 , V_63 , V_59 ) ;
if ( V_59 == V_47 ) {
V_57 = V_53 >> 1 ;
V_58 = V_54 >> 1 ;
} else if ( V_59 == V_48 ) {
V_57 = V_53 >> 1 ;
}
F_11 ( V_45 + V_64 , F_13 ( V_53 , V_55 ) ) ;
F_11 ( V_45 + V_65 , F_13 ( V_54 , V_56 ) ) ;
F_11 ( V_45 + V_66 , F_13 ( V_57 , V_55 ) ) ;
F_11 ( V_45 + V_67 , F_13 ( V_58 , V_56 ) ) ;
F_10 ( V_41 ) ;
}
static void F_19 ( struct V_1 * V_2 ,
struct V_3 * V_68 )
{
struct V_40 * V_41 = F_20 ( V_2 ) ;
struct V_3 * V_15 = V_2 -> V_15 ;
struct V_5 * V_6 = V_15 -> V_6 ;
struct V_11 * V_50 = & V_15 -> V_50 ;
struct V_11 * V_51 = & V_15 -> V_51 ;
struct V_69 * V_70 ;
void T_2 * V_42 = V_41 -> V_42 ;
void T_2 * V_71 = V_41 -> V_71 ;
void T_2 * V_72 ;
T_4 V_73 ;
T_3 V_74 , V_75 , V_53 , V_54 ;
T_3 V_76 , V_77 , V_55 , V_56 ;
T_1 V_24 ;
int V_59 ;
int V_78 ;
int V_79 ;
if ( ! V_6 )
return;
V_24 = V_6 -> V_24 -> V_24 ;
V_74 = V_50 -> V_18 >> 16 ;
V_75 = V_50 -> y1 >> 16 ;
V_53 = F_21 ( V_50 ) >> 16 ;
V_54 = F_22 ( V_50 ) >> 16 ;
V_76 = V_51 -> V_18 ;
V_77 = V_51 -> y1 ;
V_55 = F_21 ( V_51 ) ;
V_56 = F_22 ( V_51 ) ;
V_78 = F_23 ( V_24 ) ;
V_72 = V_42 + V_80 ;
for ( V_79 = 0 ; V_79 < V_78 ; V_79 ++ ) {
V_70 = F_24 ( V_6 , V_79 ) ;
V_73 = V_70 -> V_73 + V_6 -> V_81 [ V_79 ] ;
V_73 += V_75 * V_6 -> V_82 [ V_79 ] ;
V_73 += V_74 * F_25 ( V_24 , V_79 ) ;
F_11 ( V_72 , V_73 ) ;
V_72 += 4 ;
}
F_11 ( V_42 + V_83 , F_26 ( V_53 ) | F_27 ( V_54 ) ) ;
F_11 ( V_42 + V_84 , F_28 ( V_76 ) | F_29 ( V_77 ) ) ;
F_11 ( V_42 + V_85 ,
F_28 ( V_76 + V_55 ) | F_29 ( V_77 + V_56 ) ) ;
F_11 ( V_42 + V_86 , F_30 ( V_6 -> V_82 [ 0 ] ) |
F_31 ( V_6 -> V_82 [ 1 ] ) ) ;
V_59 = F_6 ( V_24 ) ;
if ( V_59 >= 0 )
F_11 ( V_42 + V_87 , V_59 ) ;
F_9 ( V_42 + V_88 , V_89 ,
V_89 ) ;
F_16 ( V_41 , V_24 , V_53 , V_54 , V_55 , V_56 ) ;
F_9 ( V_71 + V_90 , V_91 , V_91 ) ;
F_32 ( V_2 ) ;
F_8 ( V_41 ) ;
}
static void F_33 ( struct V_1 * V_2 ,
struct V_3 * V_68 )
{
struct V_40 * V_41 = F_20 ( V_2 ) ;
void T_2 * V_71 = V_41 -> V_71 ;
F_34 ( V_2 ) ;
F_9 ( V_71 + V_90 , V_91 , 0 ) ;
}
static int F_35 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_5 * V_6 = V_4 -> V_6 ;
struct V_7 * V_8 = V_4 -> V_8 ;
struct V_9 * V_10 ;
struct V_11 V_12 ;
if ( ! V_8 || ! V_6 )
return 0 ;
V_10 = F_3 ( V_4 -> V_15 ,
V_8 ) ;
if ( F_4 ( ! V_10 ) )
return - V_16 ;
if ( ! V_10 -> V_17 )
return 0 ;
if ( ! V_4 -> V_8 )
return - V_16 ;
V_12 . V_18 = 0 ;
V_12 . y1 = 0 ;
V_12 . V_19 = V_10 -> V_20 . V_21 ;
V_12 . V_22 = V_10 -> V_20 . V_23 ;
return F_5 ( V_4 , & V_12 ,
V_92 ,
V_92 ,
false , true ) ;
}
static int F_36 ( T_1 V_24 )
{
switch ( V_24 ) {
case V_93 :
case V_94 :
return V_95 ;
case V_96 :
return V_97 ;
case V_98 :
return V_99 ;
case V_100 :
return V_101 ;
case V_102 :
return V_103 ;
default:
F_7 ( 1 , L_1 , V_24 ) ;
return - V_16 ;
}
}
static inline void F_37 ( struct V_40 * V_41 )
{
void T_2 * V_42 = V_41 -> V_42 ;
F_9 ( V_42 + V_104 , V_105 , V_105 ) ;
}
static inline void F_38 ( struct V_40 * V_41 )
{
F_11 ( V_41 -> V_45 + V_106 , 1 ) ;
}
static void F_39 ( struct V_40 * V_41 , T_3 V_53 , T_3 V_54 ,
T_3 V_55 , T_3 V_56 )
{
void T_2 * V_45 = V_41 -> V_45 ;
F_11 ( V_45 + V_60 , F_17 ( V_54 - 1 ) | F_18 ( V_53 - 1 ) ) ;
F_11 ( V_45 + V_61 , F_17 ( V_56 - 1 ) | F_18 ( V_55 - 1 ) ) ;
F_38 ( V_41 ) ;
}
static void F_40 ( struct V_1 * V_2 ,
struct V_3 * V_68 )
{
struct V_40 * V_41 = F_20 ( V_2 ) ;
struct V_5 * V_6 = V_2 -> V_15 -> V_6 ;
struct V_69 * V_70 ;
void T_2 * V_42 = V_41 -> V_42 ;
void T_2 * V_107 = V_41 -> V_107 ;
void T_2 * V_71 = V_41 -> V_71 ;
T_3 V_74 , V_75 , V_53 , V_54 ;
T_3 V_76 , V_77 , V_55 , V_56 ;
unsigned int V_108 ;
T_1 V_24 ;
T_4 V_73 ;
T_3 V_109 ;
int V_59 ;
if ( ! V_6 )
return;
V_24 = V_6 -> V_24 -> V_24 ;
V_109 = V_6 -> V_82 [ 0 ] ;
V_74 = V_2 -> V_15 -> V_74 >> 16 ;
V_75 = V_2 -> V_15 -> V_75 >> 16 ;
V_53 = V_2 -> V_15 -> V_53 >> 16 ;
V_54 = V_2 -> V_15 -> V_54 >> 16 ;
V_76 = V_2 -> V_15 -> V_110 ;
V_77 = V_2 -> V_15 -> V_111 ;
V_55 = V_2 -> V_15 -> V_112 ;
V_56 = V_2 -> V_15 -> V_113 ;
V_108 = V_6 -> V_24 -> V_114 [ 0 ] ;
V_70 = F_24 ( V_6 , 0 ) ;
V_73 = V_70 -> V_73 + V_6 -> V_81 [ 0 ] ;
V_73 += V_75 * V_109 + V_74 * V_108 / 8 ;
F_11 ( V_42 + V_115 , V_73 ) ;
F_11 ( V_42 + V_116 , F_26 ( V_53 ) | F_27 ( V_54 ) ) ;
F_11 ( V_42 + V_117 , F_28 ( V_76 ) | F_29 ( V_77 ) ) ;
F_11 ( V_42 + V_118 ,
F_28 ( V_76 + V_55 ) | F_29 ( V_77 + V_56 ) ) ;
F_11 ( V_42 + V_119 , V_109 & 0xffff ) ;
V_59 = F_36 ( V_24 ) ;
if ( V_59 >= 0 )
F_9 ( V_42 + V_120 , V_121 ,
V_59 << V_122 ) ;
F_9 ( V_42 + V_123 , V_124 ,
0xff << V_125 ) ;
if ( V_56 > 720 )
F_9 ( V_107 + V_126 , V_127 ,
V_128 << V_129 ) ;
else
F_9 ( V_107 + V_126 , V_127 ,
V_130 << V_129 ) ;
F_9 ( V_107 + V_126 , V_131 , V_131 ) ;
F_9 ( V_42 + V_132 , V_133 ,
V_133 ) ;
F_39 ( V_41 , V_53 , V_54 , V_55 , V_56 ) ;
F_9 ( V_71 + V_90 , V_91 , V_91 ) ;
F_32 ( V_2 ) ;
F_37 ( V_41 ) ;
}
static void F_41 ( struct V_1 * V_2 )
{
F_42 ( V_2 ) ;
F_43 ( V_2 ) ;
}
void F_44 ( struct V_1 * V_2 )
{
struct V_40 * V_41 = F_20 ( V_2 ) ;
if ( ! V_2 -> V_15 -> V_8 )
return;
switch ( V_2 -> type ) {
case V_134 :
F_38 ( V_41 ) ;
F_37 ( V_41 ) ;
break;
case V_135 :
F_10 ( V_41 ) ;
F_8 ( V_41 ) ;
break;
default:
F_7 ( 1 , L_2 , V_2 -> type ) ;
}
}
static void F_45 ( struct V_40 * V_41 )
{
void T_2 * V_71 = V_41 -> V_71 ;
F_11 ( V_71 + V_136 , 0x200 ) ;
F_11 ( V_71 + V_137 , 0x0 ) ;
F_11 ( V_71 + V_138 , 0x0 ) ;
F_11 ( V_71 + V_139 , 0x200 ) ;
F_11 ( V_71 + V_140 , ( 0x3ac << 16 ) | 0x40 ) ;
F_11 ( V_71 + V_141 , ( 0x3c0 << 16 ) | 0x40 ) ;
F_11 ( V_71 + V_142 , ( 0x3c0 << 16 ) | 0x40 ) ;
}
int F_46 ( struct V_143 * V_144 , struct V_40 * V_41 ,
enum V_145 type )
{
const struct V_146 * V_147 ;
struct V_1 * V_2 = & V_41 -> V_2 ;
struct V_148 * V_149 = V_41 -> V_149 ;
const T_1 * V_150 ;
unsigned int V_151 ;
int V_152 ;
F_45 ( V_41 ) ;
switch ( type ) {
case V_134 :
V_147 = & V_153 ;
V_150 = V_154 ;
V_151 = F_47 ( V_154 ) ;
break;
case V_135 :
V_147 = & V_155 ;
V_150 = V_156 ;
V_151 = F_47 ( V_156 ) ;
break;
default:
return - V_157 ;
}
V_152 = F_48 ( V_144 , V_2 , V_158 ,
& V_159 , V_150 , V_151 ,
type , NULL ) ;
if ( V_152 ) {
F_49 ( V_149 , L_3 , V_152 ) ;
return V_152 ;
}
F_50 ( V_2 , V_147 ) ;
return 0 ;
}
