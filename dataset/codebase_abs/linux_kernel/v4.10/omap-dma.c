static inline struct V_1 * F_1 ( struct V_2 * V_3 )
{
return F_2 ( V_3 , struct V_1 , V_4 ) ;
}
static inline struct V_5 * F_3 ( struct V_6 * V_7 )
{
return F_2 ( V_7 , struct V_5 , V_8 . V_9 ) ;
}
static inline struct V_10 * F_4 ( struct V_11 * V_12 )
{
return F_2 ( V_12 , struct V_10 , V_13 . V_14 ) ;
}
static void F_5 ( struct V_15 * V_13 )
{
struct V_10 * V_3 = F_4 ( & V_13 -> V_14 ) ;
if ( V_3 -> V_16 ) {
struct V_1 * V_17 = F_1 ( V_13 -> V_14 . V_9 -> V_18 ) ;
int V_19 ;
for ( V_19 = 0 ; V_19 < V_3 -> V_20 ; V_19 ++ ) {
if ( V_3 -> V_21 [ V_19 ] . V_22 )
F_6 ( V_17 -> V_23 , V_3 -> V_21 [ V_19 ] . V_22 ,
V_3 -> V_21 [ V_19 ] . V_24 ) ;
}
}
F_7 ( V_3 ) ;
}
static void F_8 ( struct V_10 * V_3 , int V_25 ,
enum V_26 V_27 , bool V_28 )
{
struct V_29 * V_21 = & V_3 -> V_21 [ V_25 ] ;
struct V_30 * V_22 = V_21 -> V_22 ;
if ( V_25 )
V_3 -> V_21 [ V_25 - 1 ] . V_22 -> V_31 = V_21 -> V_24 ;
if ( V_28 )
V_22 -> V_31 = 0xfffffffc ;
V_22 -> V_32 = V_21 -> V_32 ;
V_22 -> V_33 = V_21 -> V_33 ;
V_22 -> V_34 = V_21 -> V_34 & 0xffff ;
V_22 -> V_35 = V_3 -> V_35 ;
if ( ! V_28 )
V_22 -> V_35 &= ~ V_36 ;
switch ( V_27 ) {
case V_37 :
V_22 -> V_38 = V_21 -> V_39 ;
V_22 -> V_40 = V_3 -> V_39 ;
V_22 -> V_41 = V_21 -> V_42 ;
V_22 -> V_43 = V_3 -> V_42 ;
V_22 -> V_32 |= V_44 ;
V_22 -> V_32 |= V_45 ;
break;
case V_46 :
V_22 -> V_38 = V_3 -> V_39 ;
V_22 -> V_40 = V_21 -> V_39 ;
V_22 -> V_41 = V_3 -> V_42 ;
V_22 -> V_43 = V_21 -> V_42 ;
V_22 -> V_32 |= V_47 ;
V_22 -> V_32 |= V_48 ;
break;
default:
return;
}
V_22 -> V_32 |= V_49 ;
}
static void F_9 ( T_1 V_50 , unsigned type , void T_2 * V_33 )
{
switch ( type ) {
case V_51 :
F_10 ( V_50 , V_33 ) ;
break;
case V_52 :
F_10 ( V_50 , V_33 ) ;
F_10 ( V_50 >> 16 , V_33 + 2 ) ;
break;
case V_53 :
F_11 ( V_50 , V_33 ) ;
break;
default:
F_12 ( 1 ) ;
}
}
static unsigned F_13 ( unsigned type , void T_2 * V_33 )
{
unsigned V_50 ;
switch ( type ) {
case V_51 :
V_50 = F_14 ( V_33 ) ;
break;
case V_52 :
V_50 = F_14 ( V_33 ) ;
V_50 |= F_14 ( V_33 + 2 ) << 16 ;
break;
case V_53 :
V_50 = F_15 ( V_33 ) ;
break;
default:
F_12 ( 1 ) ;
V_50 = 0 ;
}
return V_50 ;
}
static void F_16 ( struct V_1 * V_17 , unsigned V_54 , unsigned V_50 )
{
const struct V_55 * V_56 = V_17 -> V_57 + V_54 ;
F_12 ( V_56 -> V_58 ) ;
F_9 ( V_50 , V_56 -> type , V_17 -> V_59 + V_56 -> V_60 ) ;
}
static unsigned F_17 ( struct V_1 * V_17 , unsigned V_54 )
{
const struct V_55 * V_56 = V_17 -> V_57 + V_54 ;
F_12 ( V_56 -> V_58 ) ;
return F_13 ( V_56 -> type , V_17 -> V_59 + V_56 -> V_60 ) ;
}
static void F_18 ( struct V_5 * V_7 , unsigned V_54 , unsigned V_50 )
{
const struct V_55 * V_56 = V_7 -> V_57 + V_54 ;
F_9 ( V_50 , V_56 -> type , V_7 -> V_61 + V_56 -> V_60 ) ;
}
static unsigned F_19 ( struct V_5 * V_7 , unsigned V_54 )
{
const struct V_55 * V_56 = V_7 -> V_57 + V_54 ;
return F_13 ( V_56 -> type , V_7 -> V_61 + V_56 -> V_60 ) ;
}
static void F_20 ( struct V_5 * V_7 )
{
if ( F_21 () )
F_19 ( V_7 , V_62 ) ;
else
F_18 ( V_7 , V_62 , ~ 0 ) ;
}
static unsigned F_22 ( struct V_5 * V_7 )
{
unsigned V_50 = F_19 ( V_7 , V_62 ) ;
if ( ! F_21 () )
F_18 ( V_7 , V_62 , V_50 ) ;
return V_50 ;
}
static void F_23 ( struct V_1 * V_17 , struct V_5 * V_7 ,
unsigned V_63 )
{
V_7 -> V_61 = V_17 -> V_59 + V_17 -> V_64 -> V_65 * V_63 ;
V_17 -> V_66 [ V_63 ] = V_7 ;
}
static void F_24 ( struct V_5 * V_7 , struct V_10 * V_3 )
{
struct V_1 * V_17 = F_1 ( V_7 -> V_8 . V_9 . V_18 ) ;
T_3 V_35 = V_3 -> V_35 ;
if ( F_25 ( V_17 -> V_64 -> V_67 ) )
F_18 ( V_7 , V_68 , 0 ) ;
else
F_18 ( V_7 , V_69 , 0 ) ;
F_20 ( V_7 ) ;
if ( V_3 -> V_16 ) {
T_1 V_70 = V_71 | V_72 | V_73 ;
if ( V_3 -> V_27 == V_37 )
V_70 |= ( V_74 | V_75 ) ;
else
V_70 |= ( V_76 | V_77 ) ;
F_18 ( V_7 , V_78 , V_70 ) ;
F_18 ( V_7 , V_79 , V_3 -> V_21 [ 0 ] . V_24 ) ;
F_18 ( V_7 , V_80 , 0 ) ;
F_18 ( V_7 , V_81 , 0xffff ) ;
F_18 ( V_7 , V_82 , 0xffffff ) ;
V_35 &= ~ V_36 ;
} else if ( V_17 -> V_83 ) {
F_18 ( V_7 , V_78 , 0 ) ;
}
F_18 ( V_7 , V_84 , V_35 ) ;
F_18 ( V_7 , V_85 , V_3 -> V_86 | V_87 ) ;
V_7 -> V_88 = true ;
}
static void F_26 ( struct V_5 * V_7 )
{
int V_19 ;
T_4 V_50 ;
for ( V_19 = 0 ; ; V_19 ++ ) {
V_50 = F_19 ( V_7 , V_85 ) ;
if ( ! ( V_50 & ( V_89 | V_90 ) ) )
break;
if ( V_19 > 100 )
break;
F_27 ( 5 ) ;
}
if ( V_50 & ( V_89 | V_90 ) )
F_28 ( V_7 -> V_8 . V_9 . V_18 -> V_91 ,
L_1 ,
V_7 -> V_92 ) ;
}
static int F_29 ( struct V_5 * V_7 )
{
struct V_1 * V_17 = F_1 ( V_7 -> V_8 . V_9 . V_18 ) ;
T_1 V_50 ;
F_18 ( V_7 , V_84 , 0 ) ;
F_20 ( V_7 ) ;
V_50 = F_19 ( V_7 , V_85 ) ;
if ( V_17 -> V_64 -> V_93 & V_94 && V_50 & V_95 ) {
T_1 V_96 ;
V_96 = F_17 ( V_17 , V_97 ) ;
V_50 = V_96 & ~ V_98 ;
V_50 |= F_30 ( V_99 ) ;
F_16 ( V_17 , V_97 , V_50 ) ;
V_50 = F_19 ( V_7 , V_85 ) ;
V_50 &= ~ V_87 ;
F_18 ( V_7 , V_85 , V_50 ) ;
if ( ! ( V_7 -> V_86 & V_100 ) )
F_26 ( V_7 ) ;
F_16 ( V_17 , V_97 , V_96 ) ;
} else {
if ( ! ( V_50 & V_87 ) )
return - V_101 ;
V_50 &= ~ V_87 ;
F_18 ( V_7 , V_85 , V_50 ) ;
if ( ! ( V_7 -> V_86 & V_100 ) )
F_26 ( V_7 ) ;
}
F_31 () ;
if ( ! F_25 ( V_17 -> V_64 -> V_67 ) && V_7 -> V_102 ) {
V_50 = F_19 ( V_7 , V_103 ) ;
if ( F_21 () )
V_50 |= 1 << 14 ;
else
V_50 &= ~ V_104 ;
F_18 ( V_7 , V_103 , V_50 ) ;
}
V_7 -> V_88 = false ;
return 0 ;
}
static void F_32 ( struct V_5 * V_7 , struct V_10 * V_3 )
{
struct V_29 * V_21 = V_3 -> V_21 + V_7 -> V_105 ;
unsigned V_106 , V_107 , V_108 ;
if ( V_3 -> V_27 == V_37 || V_3 -> V_27 == V_109 ) {
V_106 = V_110 ;
V_107 = V_111 ;
V_108 = V_112 ;
} else {
V_106 = V_113 ;
V_107 = V_114 ;
V_108 = V_115 ;
}
F_18 ( V_7 , V_106 , V_21 -> V_33 ) ;
F_18 ( V_7 , V_107 , V_21 -> V_39 ) ;
F_18 ( V_7 , V_108 , V_21 -> V_42 ) ;
F_18 ( V_7 , V_116 , V_21 -> V_32 ) ;
F_18 ( V_7 , V_117 , V_21 -> V_34 ) ;
F_24 ( V_7 , V_3 ) ;
V_7 -> V_105 ++ ;
}
static void F_33 ( struct V_5 * V_7 )
{
struct V_15 * V_13 = F_34 ( & V_7 -> V_8 ) ;
struct V_10 * V_3 ;
unsigned V_106 , V_107 , V_108 ;
if ( ! V_13 ) {
V_7 -> V_118 = NULL ;
return;
}
F_35 ( & V_13 -> V_119 ) ;
V_7 -> V_118 = V_3 = F_4 ( & V_13 -> V_14 ) ;
V_7 -> V_105 = 0 ;
F_31 () ;
F_18 ( V_7 , V_85 , V_3 -> V_86 ) ;
if ( F_21 () )
F_18 ( V_7 , V_120 , V_3 -> V_86 >> 16 ) ;
if ( V_3 -> V_27 == V_37 || V_3 -> V_27 == V_109 ) {
V_106 = V_113 ;
V_107 = V_114 ;
V_108 = V_115 ;
} else {
V_106 = V_110 ;
V_107 = V_111 ;
V_108 = V_112 ;
}
F_18 ( V_7 , V_106 , V_3 -> V_121 ) ;
F_18 ( V_7 , V_107 , V_3 -> V_39 ) ;
F_18 ( V_7 , V_108 , V_3 -> V_42 ) ;
F_18 ( V_7 , V_122 , V_3 -> V_123 ) ;
F_18 ( V_7 , V_103 , V_3 -> V_124 ) ;
F_32 ( V_7 , V_3 ) ;
}
static void F_36 ( int V_125 , T_5 V_126 , void * V_127 )
{
struct V_5 * V_7 = V_127 ;
struct V_10 * V_3 ;
unsigned long V_128 ;
F_37 ( & V_7 -> V_8 . V_129 , V_128 ) ;
V_3 = V_7 -> V_118 ;
if ( V_3 ) {
if ( V_7 -> V_102 ) {
F_38 ( & V_3 -> V_13 ) ;
} else if ( V_3 -> V_16 || V_7 -> V_105 == V_3 -> V_20 ) {
F_33 ( V_7 ) ;
F_39 ( & V_3 -> V_13 ) ;
} else {
F_32 ( V_7 , V_3 ) ;
}
}
F_40 ( & V_7 -> V_8 . V_129 , V_128 ) ;
}
static T_6 F_41 ( int V_130 , void * V_131 )
{
struct V_1 * V_17 = V_131 ;
unsigned V_126 , V_132 ;
F_42 ( & V_17 -> V_133 ) ;
V_126 = F_17 ( V_17 , V_134 ) ;
V_126 &= V_17 -> V_135 ;
if ( V_126 == 0 ) {
F_43 ( & V_17 -> V_133 ) ;
return V_136 ;
}
while ( ( V_132 = F_44 ( V_126 ) ) != 0 ) {
unsigned V_137 , V_138 ;
struct V_5 * V_7 ;
V_132 -= 1 ;
V_137 = F_45 ( V_132 ) ;
V_126 &= ~ V_137 ;
V_7 = V_17 -> V_66 [ V_132 ] ;
if ( V_7 == NULL ) {
F_28 ( V_17 -> V_4 . V_91 , L_2 , V_132 ) ;
continue;
}
V_138 = F_22 ( V_7 ) ;
F_16 ( V_17 , V_134 , V_137 ) ;
F_36 ( V_132 , V_138 , V_7 ) ;
}
F_43 ( & V_17 -> V_133 ) ;
return V_139 ;
}
static int F_46 ( struct V_6 * V_9 )
{
struct V_1 * V_17 = F_1 ( V_9 -> V_18 ) ;
struct V_5 * V_7 = F_3 ( V_9 ) ;
struct V_18 * V_91 = V_17 -> V_4 . V_91 ;
int V_140 ;
if ( V_17 -> V_141 ) {
V_140 = F_47 ( V_7 -> V_142 , L_3 ,
F_36 , V_7 , & V_7 -> V_92 ) ;
} else {
V_140 = F_47 ( V_7 -> V_142 , L_3 , NULL , NULL ,
& V_7 -> V_92 ) ;
}
F_48 ( V_91 , L_4 , V_7 -> V_92 , V_7 -> V_142 ) ;
if ( V_140 >= 0 ) {
F_23 ( V_17 , V_7 , V_7 -> V_92 ) ;
if ( ! V_17 -> V_141 ) {
unsigned V_50 ;
F_49 ( & V_17 -> V_133 ) ;
V_50 = F_45 ( V_7 -> V_92 ) ;
F_16 ( V_17 , V_134 , V_50 ) ;
V_17 -> V_135 |= V_50 ;
F_16 ( V_17 , V_143 , V_17 -> V_135 ) ;
V_50 = F_17 ( V_17 , V_144 ) ;
V_50 &= ~ F_45 ( V_7 -> V_92 ) ;
F_16 ( V_17 , V_144 , V_50 ) ;
F_50 ( & V_17 -> V_133 ) ;
}
}
if ( F_21 () ) {
if ( F_51 ( V_17 -> V_64 -> V_67 ) ) {
V_7 -> V_86 = V_145 ;
V_7 -> V_86 |= V_7 -> V_92 + 1 ;
} else {
V_7 -> V_86 = V_7 -> V_142 & 0x1f ;
}
} else {
V_7 -> V_86 = V_7 -> V_142 & 0x1f ;
V_7 -> V_86 |= ( V_7 -> V_142 & ~ 0x1f ) << 14 ;
}
if ( V_17 -> V_64 -> V_93 & V_146 )
V_7 -> V_86 |= V_100 ;
return V_140 ;
}
static void F_52 ( struct V_6 * V_9 )
{
struct V_1 * V_17 = F_1 ( V_9 -> V_18 ) ;
struct V_5 * V_7 = F_3 ( V_9 ) ;
if ( ! V_17 -> V_141 ) {
F_49 ( & V_17 -> V_133 ) ;
V_17 -> V_135 &= ~ F_45 ( V_7 -> V_92 ) ;
F_16 ( V_17 , V_143 , V_17 -> V_135 ) ;
F_50 ( & V_17 -> V_133 ) ;
}
V_7 -> V_61 = NULL ;
V_17 -> V_66 [ V_7 -> V_92 ] = NULL ;
F_53 ( & V_7 -> V_8 ) ;
F_54 ( V_7 -> V_92 ) ;
F_48 ( V_17 -> V_4 . V_91 , L_5 , V_7 -> V_92 ,
V_7 -> V_142 ) ;
V_7 -> V_142 = 0 ;
}
static T_7 F_55 ( struct V_29 * V_21 )
{
return V_21 -> V_32 * V_21 -> V_34 ;
}
static T_7 F_56 ( struct V_10 * V_3 )
{
unsigned V_19 ;
T_7 V_147 ;
for ( V_147 = V_19 = 0 ; V_19 < V_3 -> V_20 ; V_19 ++ )
V_147 += F_55 ( & V_3 -> V_21 [ V_19 ] ) ;
return V_147 * V_148 [ V_3 -> V_149 ] ;
}
static T_7 F_57 ( struct V_10 * V_3 , T_8 V_33 )
{
unsigned V_19 ;
T_7 V_147 , V_150 = V_148 [ V_3 -> V_149 ] ;
for ( V_147 = V_19 = 0 ; V_19 < V_3 -> V_20 ; V_19 ++ ) {
T_7 V_151 = F_55 ( & V_3 -> V_21 [ V_19 ] ) * V_150 ;
if ( V_147 )
V_147 += V_151 ;
else if ( V_33 >= V_3 -> V_21 [ V_19 ] . V_33 &&
V_33 < V_3 -> V_21 [ V_19 ] . V_33 + V_151 )
V_147 += V_3 -> V_21 [ V_19 ] . V_33 + V_151 - V_33 ;
}
return V_147 ;
}
static T_1 F_58 ( struct V_5 * V_7 , unsigned V_54 )
{
struct V_1 * V_17 = F_1 ( V_7 -> V_8 . V_9 . V_18 ) ;
T_1 V_50 ;
V_50 = F_19 ( V_7 , V_54 ) ;
if ( V_50 == 0 && V_17 -> V_64 -> V_93 & V_152 )
V_50 = F_19 ( V_7 , V_54 ) ;
return V_50 ;
}
static T_8 F_59 ( struct V_5 * V_7 )
{
struct V_1 * V_17 = F_1 ( V_7 -> V_8 . V_9 . V_18 ) ;
T_8 V_33 , V_153 ;
if ( F_25 ( V_17 -> V_64 -> V_67 ) ) {
V_33 = F_19 ( V_7 , V_68 ) ;
} else {
V_33 = F_58 ( V_7 , V_154 ) ;
V_153 = F_58 ( V_7 , V_69 ) ;
if ( V_153 == 0 )
V_33 = F_19 ( V_7 , V_113 ) ;
}
if ( F_21 () )
V_33 |= F_19 ( V_7 , V_113 ) & 0xffff0000 ;
return V_33 ;
}
static T_8 F_60 ( struct V_5 * V_7 )
{
struct V_1 * V_17 = F_1 ( V_7 -> V_8 . V_9 . V_18 ) ;
T_8 V_33 ;
if ( F_25 ( V_17 -> V_64 -> V_67 ) ) {
V_33 = F_19 ( V_7 , V_68 ) ;
} else {
V_33 = F_58 ( V_7 , V_69 ) ;
if ( V_33 == 0 )
V_33 = F_19 ( V_7 , V_110 ) ;
}
if ( F_21 () )
V_33 |= F_19 ( V_7 , V_110 ) & 0xffff0000 ;
return V_33 ;
}
static enum V_155 F_61 ( struct V_6 * V_9 ,
T_9 V_156 , struct V_157 * V_158 )
{
struct V_5 * V_7 = F_3 ( V_9 ) ;
struct V_15 * V_13 ;
enum V_155 V_140 ;
unsigned long V_128 ;
V_140 = F_62 ( V_9 , V_156 , V_158 ) ;
if ( ! V_7 -> V_159 && V_7 -> V_88 ) {
T_1 V_86 = F_19 ( V_7 , V_85 ) ;
if ( ! ( V_86 & V_87 ) )
V_140 = V_160 ;
}
if ( V_140 == V_160 || ! V_158 )
return V_140 ;
F_37 ( & V_7 -> V_8 . V_129 , V_128 ) ;
V_13 = F_63 ( & V_7 -> V_8 , V_156 ) ;
if ( V_13 ) {
V_158 -> V_161 = F_56 ( F_4 ( & V_13 -> V_14 ) ) ;
} else if ( V_7 -> V_118 && V_7 -> V_118 -> V_13 . V_14 . V_156 == V_156 ) {
struct V_10 * V_3 = V_7 -> V_118 ;
T_8 V_162 ;
if ( V_3 -> V_27 == V_46 )
V_162 = F_59 ( V_7 ) ;
else if ( V_3 -> V_27 == V_37 || V_3 -> V_27 == V_109 )
V_162 = F_60 ( V_7 ) ;
else
V_162 = 0 ;
V_158 -> V_161 = F_57 ( V_3 , V_162 ) ;
} else {
V_158 -> V_161 = 0 ;
}
if ( V_140 == V_163 && V_7 -> V_159 )
V_140 = V_164 ;
F_40 ( & V_7 -> V_8 . V_129 , V_128 ) ;
return V_140 ;
}
static void F_64 ( struct V_6 * V_9 )
{
struct V_5 * V_7 = F_3 ( V_9 ) ;
unsigned long V_128 ;
F_37 ( & V_7 -> V_8 . V_129 , V_128 ) ;
if ( F_65 ( & V_7 -> V_8 ) && ! V_7 -> V_118 )
F_33 ( V_7 ) ;
F_40 ( & V_7 -> V_8 . V_129 , V_128 ) ;
}
static struct V_11 * F_66 (
struct V_6 * V_9 , struct V_165 * V_166 , unsigned V_20 ,
enum V_26 V_27 , unsigned long V_167 , void * V_168 )
{
struct V_1 * V_17 = F_1 ( V_9 -> V_18 ) ;
struct V_5 * V_7 = F_3 ( V_9 ) ;
enum V_169 V_170 ;
struct V_165 * V_171 ;
struct V_10 * V_3 ;
T_8 V_121 ;
unsigned V_19 , V_149 , V_32 , V_172 ;
bool V_173 = false ;
T_4 V_174 ;
T_4 V_175 , V_176 ;
if ( V_27 == V_37 ) {
V_121 = V_7 -> V_177 . V_178 ;
V_170 = V_7 -> V_177 . V_179 ;
V_174 = V_7 -> V_177 . V_180 ;
V_175 = V_7 -> V_177 . V_181 ;
} else if ( V_27 == V_46 ) {
V_121 = V_7 -> V_177 . V_182 ;
V_170 = V_7 -> V_177 . V_183 ;
V_174 = V_7 -> V_177 . V_184 ;
V_175 = V_7 -> V_177 . V_185 ;
} else {
F_28 ( V_9 -> V_18 -> V_91 , L_6 , V_186 ) ;
return NULL ;
}
switch ( V_170 ) {
case V_187 :
V_149 = V_188 ;
break;
case V_189 :
V_149 = V_190 ;
break;
case V_191 :
V_149 = V_192 ;
break;
default:
return NULL ;
}
if ( V_175 ) {
V_174 = V_175 ;
V_176 = V_175 * V_148 [ V_149 ] ;
}
V_3 = F_67 ( sizeof( * V_3 ) + V_20 * sizeof( V_3 -> V_21 [ 0 ] ) , V_193 ) ;
if ( ! V_3 )
return NULL ;
V_3 -> V_27 = V_27 ;
V_3 -> V_121 = V_121 ;
V_3 -> V_149 = V_149 ;
V_3 -> V_86 = V_7 -> V_86 | V_194 ;
if ( V_27 == V_37 ) {
V_3 -> V_123 = V_195 | V_196 ;
V_3 -> V_86 |= V_197 ;
if ( V_175 ) {
V_3 -> V_86 |= V_198 ;
if ( V_176 >= 64 )
V_3 -> V_123 |= V_199 ;
else if ( V_176 >= 32 )
V_3 -> V_123 |= V_200 ;
else if ( V_176 >= 16 )
V_3 -> V_123 |= V_201 ;
} else {
V_3 -> V_86 |= V_202 ;
}
} else {
V_3 -> V_123 = V_199 | V_203 ;
V_3 -> V_86 |= V_204 ;
if ( V_175 ) {
V_3 -> V_86 |= V_205 ;
V_3 -> V_39 = 1 ;
V_3 -> V_42 = - ( V_176 - 1 ) ;
if ( V_176 >= 64 )
V_3 -> V_123 |= V_195 ;
else if ( V_176 >= 32 )
V_3 -> V_123 |= V_206 ;
else if ( V_176 >= 16 )
V_3 -> V_123 |= V_207 ;
} else {
V_3 -> V_86 |= V_208 ;
}
}
V_3 -> V_35 = V_209 | V_36 ;
V_3 -> V_123 |= V_149 ;
if ( F_21 () ) {
V_3 -> V_35 |= V_210 ;
if ( V_27 == V_37 )
V_3 -> V_123 |= V_211 | V_212 ;
else
V_3 -> V_123 |= V_213 | V_214 ;
} else {
if ( V_27 == V_37 )
V_3 -> V_86 |= V_95 ;
V_3 -> V_35 |= V_215 | V_216 ;
if ( V_175 )
V_3 -> V_123 |= V_217 ;
}
if ( V_17 -> V_64 -> V_93 & V_218 )
V_3 -> V_124 = V_7 -> V_92 ;
V_32 = V_174 ;
V_172 = V_148 [ V_149 ] * V_32 ;
if ( V_20 >= 2 )
V_3 -> V_16 = V_17 -> V_83 ;
F_68 (sgl, sgent, sglen, i) {
struct V_29 * V_219 = & V_3 -> V_21 [ V_19 ] ;
V_219 -> V_33 = F_69 ( V_171 ) ;
V_219 -> V_32 = V_32 ;
V_219 -> V_34 = F_70 ( V_171 ) / V_172 ;
if ( V_175 && V_27 == V_37 ) {
V_219 -> V_39 = 1 ;
V_219 -> V_42 = - ( V_176 - 1 ) ;
}
if ( V_3 -> V_16 ) {
V_219 -> V_22 = F_71 ( V_17 -> V_23 , V_193 ,
& V_219 -> V_24 ) ;
if ( ! V_219 -> V_22 ) {
F_28 ( V_9 -> V_18 -> V_91 ,
L_7 , V_19 ) ;
V_173 = true ;
V_3 -> V_16 = false ;
continue;
}
F_8 ( V_3 , V_19 , V_27 , ( V_19 == V_20 - 1 ) ) ;
}
}
V_3 -> V_20 = V_20 ;
if ( V_173 ) {
for ( V_19 = 0 ; V_19 < V_3 -> V_20 ; V_19 ++ ) {
struct V_29 * V_219 = & V_3 -> V_21 [ V_19 ] ;
if ( V_219 -> V_22 ) {
F_6 ( V_17 -> V_23 , V_219 -> V_22 ,
V_219 -> V_24 ) ;
V_219 -> V_22 = NULL ;
}
}
}
return F_72 ( & V_7 -> V_8 , & V_3 -> V_13 , V_167 ) ;
}
static struct V_11 * F_73 (
struct V_6 * V_9 , T_8 V_220 , T_7 V_221 ,
T_7 V_222 , enum V_26 V_27 , unsigned long V_128 )
{
struct V_1 * V_17 = F_1 ( V_9 -> V_18 ) ;
struct V_5 * V_7 = F_3 ( V_9 ) ;
enum V_169 V_170 ;
struct V_10 * V_3 ;
T_8 V_121 ;
unsigned V_149 ;
T_4 V_174 ;
if ( V_27 == V_37 ) {
V_121 = V_7 -> V_177 . V_178 ;
V_170 = V_7 -> V_177 . V_179 ;
V_174 = V_7 -> V_177 . V_180 ;
} else if ( V_27 == V_46 ) {
V_121 = V_7 -> V_177 . V_182 ;
V_170 = V_7 -> V_177 . V_183 ;
V_174 = V_7 -> V_177 . V_184 ;
} else {
F_28 ( V_9 -> V_18 -> V_91 , L_6 , V_186 ) ;
return NULL ;
}
switch ( V_170 ) {
case V_187 :
V_149 = V_188 ;
break;
case V_189 :
V_149 = V_190 ;
break;
case V_191 :
V_149 = V_192 ;
break;
default:
return NULL ;
}
V_3 = F_67 ( sizeof( * V_3 ) + sizeof( V_3 -> V_21 [ 0 ] ) , V_193 ) ;
if ( ! V_3 )
return NULL ;
V_3 -> V_27 = V_27 ;
V_3 -> V_121 = V_121 ;
V_3 -> V_42 = V_174 ;
V_3 -> V_149 = V_149 ;
V_3 -> V_21 [ 0 ] . V_33 = V_220 ;
V_3 -> V_21 [ 0 ] . V_32 = V_222 / V_148 [ V_149 ] ;
V_3 -> V_21 [ 0 ] . V_34 = V_221 / V_222 ;
V_3 -> V_20 = 1 ;
V_3 -> V_86 = V_7 -> V_86 ;
if ( V_27 == V_37 )
V_3 -> V_86 |= V_197 | V_202 ;
else
V_3 -> V_86 |= V_208 | V_204 ;
V_3 -> V_35 = V_209 ;
if ( V_128 & V_223 )
V_3 -> V_35 |= V_224 ;
V_3 -> V_123 = V_149 ;
if ( F_21 () ) {
V_3 -> V_35 |= V_210 ;
if ( V_27 == V_37 )
V_3 -> V_123 |= V_211 | V_225 ;
else
V_3 -> V_123 |= V_226 | V_214 ;
} else {
if ( V_174 )
V_3 -> V_86 |= V_227 ;
else
V_3 -> V_86 |= V_228 ;
if ( V_27 == V_37 ) {
V_3 -> V_86 |= V_95 ;
V_3 -> V_123 |= V_196 ;
} else {
V_3 -> V_123 |= V_203 ;
}
V_3 -> V_35 |= V_215 | V_216 ;
V_3 -> V_123 |= V_195 | V_199 ;
}
if ( F_25 ( V_17 -> V_64 -> V_67 ) )
V_3 -> V_86 |= V_229 | V_230 ;
else
V_3 -> V_124 = V_7 -> V_92 | V_104 ;
V_7 -> V_102 = true ;
return F_72 ( & V_7 -> V_8 , & V_3 -> V_13 , V_128 ) ;
}
static struct V_11 * F_74 (
struct V_6 * V_9 , T_8 V_231 , T_8 V_232 ,
T_7 V_233 , unsigned long V_167 )
{
struct V_5 * V_7 = F_3 ( V_9 ) ;
struct V_10 * V_3 ;
T_10 V_234 ;
V_3 = F_67 ( sizeof( * V_3 ) + sizeof( V_3 -> V_21 [ 0 ] ) , V_193 ) ;
if ( ! V_3 )
return NULL ;
V_234 = F_75 ( ( V_232 | V_231 | V_233 ) ) ;
if ( V_234 > V_192 )
V_234 = V_192 ;
V_3 -> V_27 = V_109 ;
V_3 -> V_121 = V_232 ;
V_3 -> V_42 = 0 ;
V_3 -> V_149 = V_234 ;
V_3 -> V_21 [ 0 ] . V_32 = V_233 / F_45 ( V_234 ) ;
V_3 -> V_21 [ 0 ] . V_34 = 1 ;
V_3 -> V_21 [ 0 ] . V_33 = V_231 ;
V_3 -> V_20 = 1 ;
V_3 -> V_86 = V_7 -> V_86 ;
V_3 -> V_86 |= V_197 | V_204 ;
V_3 -> V_35 = V_209 | V_224 ;
V_3 -> V_123 = V_234 ;
if ( F_21 () ) {
V_3 -> V_35 |= V_210 ;
V_3 -> V_123 |= V_211 | V_214 ;
} else {
V_3 -> V_123 |= V_196 | V_203 ;
V_3 -> V_35 |= V_215 | V_216 ;
V_3 -> V_123 |= V_195 | V_199 ;
}
return F_72 ( & V_7 -> V_8 , & V_3 -> V_13 , V_167 ) ;
}
static struct V_11 * F_76 (
struct V_6 * V_9 , struct V_235 * V_236 ,
unsigned long V_128 )
{
struct V_5 * V_7 = F_3 ( V_9 ) ;
struct V_10 * V_3 ;
struct V_29 * V_21 ;
T_10 V_234 ;
T_7 V_237 , V_238 ;
if ( F_77 ( V_236 -> V_27 ) )
return NULL ;
if ( V_236 -> V_239 != 1 || V_236 -> V_240 == 0 )
return NULL ;
V_3 = F_67 ( sizeof( * V_3 ) + sizeof( V_3 -> V_21 [ 0 ] ) , V_193 ) ;
if ( ! V_3 )
return NULL ;
V_234 = F_75 ( ( V_236 -> V_241 | V_236 -> V_242 | V_236 -> V_166 [ 0 ] . V_147 ) ) ;
if ( V_234 > V_192 )
V_234 = V_192 ;
V_21 = & V_3 -> V_21 [ 0 ] ;
V_3 -> V_27 = V_109 ;
V_3 -> V_121 = V_236 -> V_241 ;
V_3 -> V_149 = V_234 ;
V_21 -> V_32 = V_236 -> V_166 [ 0 ] . V_147 / F_45 ( V_234 ) ;
V_21 -> V_34 = V_236 -> V_240 ;
V_21 -> V_33 = V_236 -> V_242 ;
V_3 -> V_20 = 1 ;
V_3 -> V_86 = V_7 -> V_86 ;
V_237 = F_78 ( V_236 , & V_236 -> V_166 [ 0 ] ) ;
V_238 = F_79 ( V_236 , & V_236 -> V_166 [ 0 ] ) ;
if ( V_237 ) {
V_3 -> V_86 |= V_198 ;
V_3 -> V_39 = 1 ;
V_3 -> V_42 = V_237 ;
} else if ( V_236 -> V_243 ) {
V_3 -> V_86 |= V_204 ;
V_3 -> V_42 = 0 ;
} else {
F_28 ( V_9 -> V_18 -> V_91 ,
L_8 ,
V_186 ) ;
F_7 ( V_3 ) ;
return NULL ;
}
if ( V_238 ) {
V_3 -> V_86 |= V_205 ;
V_21 -> V_39 = 1 ;
V_21 -> V_42 = V_238 ;
} else if ( V_236 -> V_244 ) {
V_3 -> V_86 |= V_197 ;
V_21 -> V_42 = 0 ;
} else {
F_28 ( V_9 -> V_18 -> V_91 ,
L_9 ,
V_186 ) ;
F_7 ( V_3 ) ;
return NULL ;
}
V_3 -> V_35 = V_209 | V_224 ;
V_3 -> V_123 = V_234 ;
if ( F_21 () ) {
V_3 -> V_35 |= V_210 ;
V_3 -> V_123 |= V_211 | V_214 ;
} else {
V_3 -> V_123 |= V_196 | V_203 ;
V_3 -> V_35 |= V_215 | V_216 ;
V_3 -> V_123 |= V_195 | V_199 ;
}
return F_72 ( & V_7 -> V_8 , & V_3 -> V_13 , V_128 ) ;
}
static int F_80 ( struct V_6 * V_9 , struct V_245 * V_177 )
{
struct V_5 * V_7 = F_3 ( V_9 ) ;
if ( V_177 -> V_179 == V_246 ||
V_177 -> V_183 == V_246 )
return - V_101 ;
memcpy ( & V_7 -> V_177 , V_177 , sizeof( V_7 -> V_177 ) ) ;
return 0 ;
}
static int F_81 ( struct V_6 * V_9 )
{
struct V_5 * V_7 = F_3 ( V_9 ) ;
unsigned long V_128 ;
F_82 ( V_247 ) ;
F_37 ( & V_7 -> V_8 . V_129 , V_128 ) ;
if ( V_7 -> V_118 ) {
F_5 ( & V_7 -> V_118 -> V_13 ) ;
V_7 -> V_118 = NULL ;
if ( ! V_7 -> V_159 )
F_29 ( V_7 ) ;
}
V_7 -> V_102 = false ;
V_7 -> V_159 = false ;
F_83 ( & V_7 -> V_8 , & V_247 ) ;
F_40 ( & V_7 -> V_8 . V_129 , V_128 ) ;
F_84 ( & V_7 -> V_8 , & V_247 ) ;
return 0 ;
}
static void F_85 ( struct V_6 * V_9 )
{
struct V_5 * V_7 = F_3 ( V_9 ) ;
F_86 ( & V_7 -> V_8 ) ;
}
static int F_87 ( struct V_6 * V_9 )
{
struct V_5 * V_7 = F_3 ( V_9 ) ;
struct V_1 * V_17 = F_1 ( V_9 -> V_18 ) ;
unsigned long V_128 ;
int V_140 = - V_101 ;
bool V_248 = false ;
F_37 ( & V_17 -> V_133 , V_128 ) ;
if ( ! V_7 -> V_118 )
goto V_249;
if ( V_7 -> V_102 )
V_248 = true ;
else if ( V_7 -> V_118 -> V_27 == V_37 )
V_248 = true ;
if ( V_248 && ! V_7 -> V_159 ) {
V_140 = F_29 ( V_7 ) ;
if ( ! V_140 )
V_7 -> V_159 = true ;
}
V_249:
F_40 ( & V_17 -> V_133 , V_128 ) ;
return V_140 ;
}
static int F_88 ( struct V_6 * V_9 )
{
struct V_5 * V_7 = F_3 ( V_9 ) ;
struct V_1 * V_17 = F_1 ( V_9 -> V_18 ) ;
unsigned long V_128 ;
int V_140 = - V_101 ;
F_37 ( & V_17 -> V_133 , V_128 ) ;
if ( V_7 -> V_159 && V_7 -> V_118 ) {
F_31 () ;
F_18 ( V_7 , V_103 , V_7 -> V_118 -> V_124 ) ;
F_24 ( V_7 , V_7 -> V_118 ) ;
V_7 -> V_159 = false ;
V_140 = 0 ;
}
F_40 ( & V_17 -> V_133 , V_128 ) ;
return V_140 ;
}
static int F_89 ( struct V_1 * V_17 )
{
struct V_5 * V_7 ;
V_7 = F_67 ( sizeof( * V_7 ) , V_250 ) ;
if ( ! V_7 )
return - V_251 ;
V_7 -> V_57 = V_17 -> V_57 ;
V_7 -> V_8 . V_252 = F_5 ;
F_90 ( & V_7 -> V_8 , & V_17 -> V_4 ) ;
return 0 ;
}
static void F_91 ( struct V_1 * V_17 )
{
while ( ! F_92 ( & V_17 -> V_4 . V_253 ) ) {
struct V_5 * V_7 = F_93 ( & V_17 -> V_4 . V_253 ,
struct V_5 , V_8 . V_9 . V_254 ) ;
F_35 ( & V_7 -> V_8 . V_9 . V_254 ) ;
F_94 ( & V_7 -> V_8 . V_255 ) ;
F_7 ( V_7 ) ;
}
}
static int F_95 ( struct V_256 * V_257 )
{
struct V_1 * V_17 ;
struct V_258 * V_259 ;
int V_260 , V_19 , V_130 ;
T_4 V_261 ;
V_17 = F_96 ( & V_257 -> V_91 , sizeof( * V_17 ) , V_250 ) ;
if ( ! V_17 )
return - V_251 ;
V_259 = F_97 ( V_257 , V_262 , 0 ) ;
V_17 -> V_59 = F_98 ( & V_257 -> V_91 , V_259 ) ;
if ( F_99 ( V_17 -> V_59 ) )
return F_100 ( V_17 -> V_59 ) ;
V_17 -> V_64 = F_101 () ;
if ( ! V_17 -> V_64 )
return - V_263 ;
V_17 -> V_57 = V_17 -> V_64 -> V_57 ;
F_102 ( V_264 , V_17 -> V_4 . V_265 ) ;
F_102 ( V_266 , V_17 -> V_4 . V_265 ) ;
F_102 ( V_267 , V_17 -> V_4 . V_265 ) ;
F_102 ( V_268 , V_17 -> V_4 . V_265 ) ;
V_17 -> V_4 . V_269 = F_46 ;
V_17 -> V_4 . V_270 = F_52 ;
V_17 -> V_4 . V_271 = F_61 ;
V_17 -> V_4 . V_272 = F_64 ;
V_17 -> V_4 . V_273 = F_66 ;
V_17 -> V_4 . V_274 = F_73 ;
V_17 -> V_4 . V_275 = F_74 ;
V_17 -> V_4 . V_276 = F_76 ;
V_17 -> V_4 . V_277 = F_80 ;
V_17 -> V_4 . V_278 = F_87 ;
V_17 -> V_4 . V_279 = F_88 ;
V_17 -> V_4 . V_280 = F_81 ;
V_17 -> V_4 . V_281 = F_85 ;
V_17 -> V_4 . V_282 = V_283 ;
V_17 -> V_4 . V_284 = V_283 ;
V_17 -> V_4 . V_285 = F_45 ( V_37 ) | F_45 ( V_46 ) ;
V_17 -> V_4 . V_286 = V_287 ;
V_17 -> V_4 . V_91 = & V_257 -> V_91 ;
F_103 ( & V_17 -> V_4 . V_253 ) ;
F_104 ( & V_17 -> V_129 ) ;
F_104 ( & V_17 -> V_133 ) ;
V_17 -> V_288 = V_289 ;
if ( V_257 -> V_91 . V_290 && F_105 ( V_257 -> V_91 . V_290 ,
L_10 ,
& V_17 -> V_288 ) ) {
F_106 ( & V_257 -> V_91 ,
L_11 ,
V_289 ) ;
}
if ( ! V_257 -> V_91 . V_290 ) {
V_261 = V_17 -> V_64 -> V_67 -> V_261 ;
if ( F_107 ( ! V_261 ) )
V_261 = V_291 ;
} else if ( F_105 ( V_257 -> V_91 . V_290 , L_12 ,
& V_261 ) ) {
F_106 ( & V_257 -> V_91 ,
L_13 ,
V_291 ) ;
V_261 = V_291 ;
}
V_17 -> V_66 = F_108 ( & V_257 -> V_91 , V_261 , sizeof( * V_17 -> V_66 ) ,
V_250 ) ;
if ( ! V_17 -> V_66 )
return - V_251 ;
for ( V_19 = 0 ; V_19 < V_17 -> V_288 ; V_19 ++ ) {
V_260 = F_89 ( V_17 ) ;
if ( V_260 ) {
F_91 ( V_17 ) ;
return V_260 ;
}
}
V_130 = F_109 ( V_257 , 1 ) ;
if ( V_130 <= 0 ) {
F_106 ( & V_257 -> V_91 , L_14 , V_130 ) ;
V_17 -> V_141 = true ;
} else {
V_17 -> V_135 = 0 ;
F_16 ( V_17 , V_143 , 0 ) ;
V_260 = F_110 ( & V_257 -> V_91 , V_130 , F_41 ,
V_292 , L_15 , V_17 ) ;
if ( V_260 )
return V_260 ;
}
if ( F_17 ( V_17 , V_293 ) & V_294 )
V_17 -> V_83 = true ;
V_17 -> V_4 . V_295 . V_296 = V_17 -> V_64 -> V_297 ;
V_17 -> V_4 . V_295 . V_298 = V_17 -> V_64 -> V_299 ;
V_17 -> V_4 . V_295 . V_34 = V_300 ;
if ( V_17 -> V_83 ) {
V_17 -> V_23 = F_111 ( F_112 ( & V_257 -> V_91 ) ,
& V_257 -> V_91 ,
sizeof( struct V_30 ) ,
4 , 0 ) ;
if ( ! V_17 -> V_23 ) {
F_28 ( & V_257 -> V_91 ,
L_16 ) ;
V_17 -> V_83 = false ;
}
}
V_260 = F_113 ( & V_17 -> V_4 ) ;
if ( V_260 ) {
F_114 ( L_17 ,
V_260 ) ;
F_91 ( V_17 ) ;
return V_260 ;
}
F_115 ( V_257 , V_17 ) ;
if ( V_257 -> V_91 . V_290 ) {
V_301 . V_302 = V_17 -> V_4 . V_265 ;
V_260 = F_116 ( V_257 -> V_91 . V_290 ,
V_303 , & V_301 ) ;
if ( V_260 ) {
F_114 ( L_18 ) ;
F_117 ( & V_17 -> V_4 ) ;
F_91 ( V_17 ) ;
}
}
F_106 ( & V_257 -> V_91 , L_19 ,
V_17 -> V_83 ? L_20 : L_21 ) ;
return V_260 ;
}
static int F_118 ( struct V_256 * V_257 )
{
struct V_1 * V_17 = F_119 ( V_257 ) ;
int V_130 ;
if ( V_257 -> V_91 . V_290 )
F_120 ( V_257 -> V_91 . V_290 ) ;
V_130 = F_109 ( V_257 , 1 ) ;
F_121 ( & V_257 -> V_91 , V_130 , V_17 ) ;
F_117 ( & V_17 -> V_4 ) ;
if ( ! V_17 -> V_141 ) {
F_16 ( V_17 , V_144 , 0 ) ;
}
if ( V_17 -> V_83 )
F_122 ( V_17 -> V_23 ) ;
F_91 ( V_17 ) ;
return 0 ;
}
bool V_300 ( struct V_6 * V_9 , void * V_304 )
{
if ( V_9 -> V_18 -> V_91 -> V_305 == & V_306 . V_305 ) {
struct V_1 * V_17 = F_1 ( V_9 -> V_18 ) ;
struct V_5 * V_7 = F_3 ( V_9 ) ;
unsigned V_307 = * ( unsigned * ) V_304 ;
if ( V_307 <= V_17 -> V_288 ) {
V_7 -> V_142 = V_307 ;
return true ;
}
}
return false ;
}
static int F_123 ( void )
{
return F_124 ( & V_306 ) ;
}
static void T_11 F_125 ( void )
{
F_126 ( & V_306 ) ;
}
