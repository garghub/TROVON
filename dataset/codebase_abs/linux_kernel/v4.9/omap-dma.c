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
struct V_1 * V_17 = F_1 ( V_7 -> V_8 . V_9 . V_18 ) ;
T_1 V_50 ;
F_18 ( V_7 , V_84 , 0 ) ;
F_20 ( V_7 ) ;
V_50 = F_19 ( V_7 , V_85 ) ;
if ( V_17 -> V_64 -> V_89 & V_90 && V_50 & V_91 ) {
T_1 V_92 ;
unsigned V_19 ;
V_92 = F_17 ( V_17 , V_93 ) ;
V_50 = V_92 & ~ V_94 ;
V_50 |= F_27 ( V_95 ) ;
F_16 ( V_17 , V_93 , V_50 ) ;
V_50 = F_19 ( V_7 , V_85 ) ;
V_50 &= ~ V_87 ;
F_18 ( V_7 , V_85 , V_50 ) ;
for ( V_19 = 0 ; ; V_19 ++ ) {
V_50 = F_19 ( V_7 , V_85 ) ;
if ( ! ( V_50 & ( V_96 | V_97 ) ) )
break;
if ( V_19 > 100 )
break;
F_28 ( 5 ) ;
}
if ( V_50 & ( V_96 | V_97 ) )
F_29 ( V_7 -> V_8 . V_9 . V_18 -> V_98 ,
L_1 ,
V_7 -> V_99 ) ;
F_16 ( V_17 , V_93 , V_92 ) ;
} else {
V_50 &= ~ V_87 ;
F_18 ( V_7 , V_85 , V_50 ) ;
}
F_30 () ;
if ( ! F_25 ( V_17 -> V_64 -> V_67 ) && V_7 -> V_100 ) {
V_50 = F_19 ( V_7 , V_101 ) ;
if ( F_21 () )
V_50 |= 1 << 14 ;
else
V_50 &= ~ V_102 ;
F_18 ( V_7 , V_101 , V_50 ) ;
}
V_7 -> V_88 = false ;
}
static void F_31 ( struct V_5 * V_7 , struct V_10 * V_3 )
{
struct V_29 * V_21 = V_3 -> V_21 + V_7 -> V_103 ;
unsigned V_104 , V_105 , V_106 ;
if ( V_3 -> V_27 == V_37 || V_3 -> V_27 == V_107 ) {
V_104 = V_108 ;
V_105 = V_109 ;
V_106 = V_110 ;
} else {
V_104 = V_111 ;
V_105 = V_112 ;
V_106 = V_113 ;
}
F_18 ( V_7 , V_104 , V_21 -> V_33 ) ;
F_18 ( V_7 , V_105 , V_21 -> V_39 ) ;
F_18 ( V_7 , V_106 , V_21 -> V_42 ) ;
F_18 ( V_7 , V_114 , V_21 -> V_32 ) ;
F_18 ( V_7 , V_115 , V_21 -> V_34 ) ;
F_24 ( V_7 , V_3 ) ;
V_7 -> V_103 ++ ;
}
static void F_32 ( struct V_5 * V_7 )
{
struct V_15 * V_13 = F_33 ( & V_7 -> V_8 ) ;
struct V_10 * V_3 ;
unsigned V_104 , V_105 , V_106 ;
if ( ! V_13 ) {
V_7 -> V_116 = NULL ;
return;
}
F_34 ( & V_13 -> V_117 ) ;
V_7 -> V_116 = V_3 = F_4 ( & V_13 -> V_14 ) ;
V_7 -> V_103 = 0 ;
F_30 () ;
F_18 ( V_7 , V_85 , V_3 -> V_86 ) ;
if ( F_21 () )
F_18 ( V_7 , V_118 , V_3 -> V_86 >> 16 ) ;
if ( V_3 -> V_27 == V_37 || V_3 -> V_27 == V_107 ) {
V_104 = V_111 ;
V_105 = V_112 ;
V_106 = V_113 ;
} else {
V_104 = V_108 ;
V_105 = V_109 ;
V_106 = V_110 ;
}
F_18 ( V_7 , V_104 , V_3 -> V_119 ) ;
F_18 ( V_7 , V_105 , V_3 -> V_39 ) ;
F_18 ( V_7 , V_106 , V_3 -> V_42 ) ;
F_18 ( V_7 , V_120 , V_3 -> V_121 ) ;
F_18 ( V_7 , V_101 , V_3 -> V_122 ) ;
F_31 ( V_7 , V_3 ) ;
}
static void F_35 ( int V_123 , T_4 V_124 , void * V_125 )
{
struct V_5 * V_7 = V_125 ;
struct V_10 * V_3 ;
unsigned long V_126 ;
F_36 ( & V_7 -> V_8 . V_127 , V_126 ) ;
V_3 = V_7 -> V_116 ;
if ( V_3 ) {
if ( V_7 -> V_100 ) {
F_37 ( & V_3 -> V_13 ) ;
} else if ( V_3 -> V_16 || V_7 -> V_103 == V_3 -> V_20 ) {
F_32 ( V_7 ) ;
F_38 ( & V_3 -> V_13 ) ;
} else {
F_31 ( V_7 , V_3 ) ;
}
}
F_39 ( & V_7 -> V_8 . V_127 , V_126 ) ;
}
static T_5 F_40 ( int V_128 , void * V_129 )
{
struct V_1 * V_17 = V_129 ;
unsigned V_124 , V_130 ;
F_41 ( & V_17 -> V_131 ) ;
V_124 = F_17 ( V_17 , V_132 ) ;
V_124 &= V_17 -> V_133 ;
if ( V_124 == 0 ) {
F_42 ( & V_17 -> V_131 ) ;
return V_134 ;
}
while ( ( V_130 = F_43 ( V_124 ) ) != 0 ) {
unsigned V_135 , V_136 ;
struct V_5 * V_7 ;
V_130 -= 1 ;
V_135 = F_44 ( V_130 ) ;
V_124 &= ~ V_135 ;
V_7 = V_17 -> V_66 [ V_130 ] ;
if ( V_7 == NULL ) {
F_29 ( V_17 -> V_4 . V_98 , L_2 , V_130 ) ;
continue;
}
V_136 = F_22 ( V_7 ) ;
F_16 ( V_17 , V_132 , V_135 ) ;
F_35 ( V_130 , V_136 , V_7 ) ;
}
F_42 ( & V_17 -> V_131 ) ;
return V_137 ;
}
static int F_45 ( struct V_6 * V_9 )
{
struct V_1 * V_17 = F_1 ( V_9 -> V_18 ) ;
struct V_5 * V_7 = F_3 ( V_9 ) ;
struct V_18 * V_98 = V_17 -> V_4 . V_98 ;
int V_138 ;
if ( V_17 -> V_139 ) {
V_138 = F_46 ( V_7 -> V_140 , L_3 ,
F_35 , V_7 , & V_7 -> V_99 ) ;
} else {
V_138 = F_46 ( V_7 -> V_140 , L_3 , NULL , NULL ,
& V_7 -> V_99 ) ;
}
F_47 ( V_98 , L_4 , V_7 -> V_99 , V_7 -> V_140 ) ;
if ( V_138 >= 0 ) {
F_23 ( V_17 , V_7 , V_7 -> V_99 ) ;
if ( ! V_17 -> V_139 ) {
unsigned V_50 ;
F_48 ( & V_17 -> V_131 ) ;
V_50 = F_44 ( V_7 -> V_99 ) ;
F_16 ( V_17 , V_132 , V_50 ) ;
V_17 -> V_133 |= V_50 ;
F_16 ( V_17 , V_141 , V_17 -> V_133 ) ;
V_50 = F_17 ( V_17 , V_142 ) ;
V_50 &= ~ F_44 ( V_7 -> V_99 ) ;
F_16 ( V_17 , V_142 , V_50 ) ;
F_49 ( & V_17 -> V_131 ) ;
}
}
if ( F_21 () ) {
if ( F_50 ( V_17 -> V_64 -> V_67 ) ) {
V_7 -> V_86 = V_143 ;
V_7 -> V_86 |= V_7 -> V_99 + 1 ;
} else {
V_7 -> V_86 = V_7 -> V_140 & 0x1f ;
}
} else {
V_7 -> V_86 = V_7 -> V_140 & 0x1f ;
V_7 -> V_86 |= ( V_7 -> V_140 & ~ 0x1f ) << 14 ;
}
if ( V_17 -> V_64 -> V_89 & V_144 )
V_7 -> V_86 |= V_145 ;
return V_138 ;
}
static void F_51 ( struct V_6 * V_9 )
{
struct V_1 * V_17 = F_1 ( V_9 -> V_18 ) ;
struct V_5 * V_7 = F_3 ( V_9 ) ;
if ( ! V_17 -> V_139 ) {
F_48 ( & V_17 -> V_131 ) ;
V_17 -> V_133 &= ~ F_44 ( V_7 -> V_99 ) ;
F_16 ( V_17 , V_141 , V_17 -> V_133 ) ;
F_49 ( & V_17 -> V_131 ) ;
}
V_7 -> V_61 = NULL ;
V_17 -> V_66 [ V_7 -> V_99 ] = NULL ;
F_52 ( & V_7 -> V_8 ) ;
F_53 ( V_7 -> V_99 ) ;
F_47 ( V_17 -> V_4 . V_98 , L_5 , V_7 -> V_99 ,
V_7 -> V_140 ) ;
V_7 -> V_140 = 0 ;
}
static T_6 F_54 ( struct V_29 * V_21 )
{
return V_21 -> V_32 * V_21 -> V_34 ;
}
static T_6 F_55 ( struct V_10 * V_3 )
{
unsigned V_19 ;
T_6 V_146 ;
for ( V_146 = V_19 = 0 ; V_19 < V_3 -> V_20 ; V_19 ++ )
V_146 += F_54 ( & V_3 -> V_21 [ V_19 ] ) ;
return V_146 * V_147 [ V_3 -> V_148 ] ;
}
static T_6 F_56 ( struct V_10 * V_3 , T_7 V_33 )
{
unsigned V_19 ;
T_6 V_146 , V_149 = V_147 [ V_3 -> V_148 ] ;
for ( V_146 = V_19 = 0 ; V_19 < V_3 -> V_20 ; V_19 ++ ) {
T_6 V_150 = F_54 ( & V_3 -> V_21 [ V_19 ] ) * V_149 ;
if ( V_146 )
V_146 += V_150 ;
else if ( V_33 >= V_3 -> V_21 [ V_19 ] . V_33 &&
V_33 < V_3 -> V_21 [ V_19 ] . V_33 + V_150 )
V_146 += V_3 -> V_21 [ V_19 ] . V_33 + V_150 - V_33 ;
}
return V_146 ;
}
static T_1 F_57 ( struct V_5 * V_7 , unsigned V_54 )
{
struct V_1 * V_17 = F_1 ( V_7 -> V_8 . V_9 . V_18 ) ;
T_1 V_50 ;
V_50 = F_19 ( V_7 , V_54 ) ;
if ( V_50 == 0 && V_17 -> V_64 -> V_89 & V_151 )
V_50 = F_19 ( V_7 , V_54 ) ;
return V_50 ;
}
static T_7 F_58 ( struct V_5 * V_7 )
{
struct V_1 * V_17 = F_1 ( V_7 -> V_8 . V_9 . V_18 ) ;
T_7 V_33 , V_152 ;
if ( F_25 ( V_17 -> V_64 -> V_67 ) ) {
V_33 = F_19 ( V_7 , V_68 ) ;
} else {
V_33 = F_57 ( V_7 , V_153 ) ;
V_152 = F_57 ( V_7 , V_69 ) ;
if ( V_152 == 0 )
V_33 = F_19 ( V_7 , V_111 ) ;
}
if ( F_21 () )
V_33 |= F_19 ( V_7 , V_111 ) & 0xffff0000 ;
return V_33 ;
}
static T_7 F_59 ( struct V_5 * V_7 )
{
struct V_1 * V_17 = F_1 ( V_7 -> V_8 . V_9 . V_18 ) ;
T_7 V_33 ;
if ( F_25 ( V_17 -> V_64 -> V_67 ) ) {
V_33 = F_19 ( V_7 , V_68 ) ;
} else {
V_33 = F_57 ( V_7 , V_69 ) ;
if ( V_33 == 0 )
V_33 = F_19 ( V_7 , V_108 ) ;
}
if ( F_21 () )
V_33 |= F_19 ( V_7 , V_108 ) & 0xffff0000 ;
return V_33 ;
}
static enum V_154 F_60 ( struct V_6 * V_9 ,
T_8 V_155 , struct V_156 * V_157 )
{
struct V_5 * V_7 = F_3 ( V_9 ) ;
struct V_15 * V_13 ;
enum V_154 V_138 ;
unsigned long V_126 ;
V_138 = F_61 ( V_9 , V_155 , V_157 ) ;
if ( ! V_7 -> V_158 && V_7 -> V_88 ) {
T_1 V_86 = F_19 ( V_7 , V_85 ) ;
if ( ! ( V_86 & V_87 ) )
V_138 = V_159 ;
}
if ( V_138 == V_159 || ! V_157 )
return V_138 ;
F_36 ( & V_7 -> V_8 . V_127 , V_126 ) ;
V_13 = F_62 ( & V_7 -> V_8 , V_155 ) ;
if ( V_13 ) {
V_157 -> V_160 = F_55 ( F_4 ( & V_13 -> V_14 ) ) ;
} else if ( V_7 -> V_116 && V_7 -> V_116 -> V_13 . V_14 . V_155 == V_155 ) {
struct V_10 * V_3 = V_7 -> V_116 ;
T_7 V_161 ;
if ( V_3 -> V_27 == V_46 )
V_161 = F_58 ( V_7 ) ;
else if ( V_3 -> V_27 == V_37 || V_3 -> V_27 == V_107 )
V_161 = F_59 ( V_7 ) ;
else
V_161 = 0 ;
V_157 -> V_160 = F_56 ( V_3 , V_161 ) ;
} else {
V_157 -> V_160 = 0 ;
}
F_39 ( & V_7 -> V_8 . V_127 , V_126 ) ;
return V_138 ;
}
static void F_63 ( struct V_6 * V_9 )
{
struct V_5 * V_7 = F_3 ( V_9 ) ;
unsigned long V_126 ;
F_36 ( & V_7 -> V_8 . V_127 , V_126 ) ;
if ( F_64 ( & V_7 -> V_8 ) && ! V_7 -> V_116 )
F_32 ( V_7 ) ;
F_39 ( & V_7 -> V_8 . V_127 , V_126 ) ;
}
static struct V_11 * F_65 (
struct V_6 * V_9 , struct V_162 * V_163 , unsigned V_20 ,
enum V_26 V_27 , unsigned long V_164 , void * V_165 )
{
struct V_1 * V_17 = F_1 ( V_9 -> V_18 ) ;
struct V_5 * V_7 = F_3 ( V_9 ) ;
enum V_166 V_167 ;
struct V_162 * V_168 ;
struct V_10 * V_3 ;
T_7 V_119 ;
unsigned V_19 , V_148 , V_32 , V_169 ;
bool V_170 = false ;
T_9 V_171 ;
if ( V_27 == V_37 ) {
V_119 = V_7 -> V_172 . V_173 ;
V_167 = V_7 -> V_172 . V_174 ;
V_171 = V_7 -> V_172 . V_175 ;
} else if ( V_27 == V_46 ) {
V_119 = V_7 -> V_172 . V_176 ;
V_167 = V_7 -> V_172 . V_177 ;
V_171 = V_7 -> V_172 . V_178 ;
} else {
F_29 ( V_9 -> V_18 -> V_98 , L_6 , V_179 ) ;
return NULL ;
}
switch ( V_167 ) {
case V_180 :
V_148 = V_181 ;
break;
case V_182 :
V_148 = V_183 ;
break;
case V_184 :
V_148 = V_185 ;
break;
default:
return NULL ;
}
V_3 = F_66 ( sizeof( * V_3 ) + V_20 * sizeof( V_3 -> V_21 [ 0 ] ) , V_186 ) ;
if ( ! V_3 )
return NULL ;
V_3 -> V_27 = V_27 ;
V_3 -> V_119 = V_119 ;
V_3 -> V_148 = V_148 ;
V_3 -> V_86 = V_7 -> V_86 | V_187 ;
if ( V_27 == V_37 ) {
V_3 -> V_86 |= V_188 | V_189 ;
V_3 -> V_121 = V_190 | V_191 ;
} else {
V_3 -> V_86 |= V_192 | V_193 ;
V_3 -> V_121 = V_194 | V_195 ;
}
V_3 -> V_35 = V_196 | V_36 ;
V_3 -> V_121 |= V_148 ;
if ( F_21 () ) {
V_3 -> V_35 |= V_197 ;
if ( V_27 == V_37 )
V_3 -> V_121 |= V_198 | V_199 ;
else
V_3 -> V_121 |= V_200 | V_201 ;
} else {
if ( V_27 == V_37 )
V_3 -> V_86 |= V_91 ;
V_3 -> V_35 |= V_202 | V_203 ;
}
if ( V_17 -> V_64 -> V_89 & V_204 )
V_3 -> V_122 = V_7 -> V_99 ;
V_32 = V_171 ;
V_169 = V_147 [ V_148 ] * V_32 ;
if ( V_20 >= 2 )
V_3 -> V_16 = V_17 -> V_83 ;
F_67 (sgl, sgent, sglen, i) {
struct V_29 * V_205 = & V_3 -> V_21 [ V_19 ] ;
V_205 -> V_33 = F_68 ( V_168 ) ;
V_205 -> V_32 = V_32 ;
V_205 -> V_34 = F_69 ( V_168 ) / V_169 ;
if ( V_3 -> V_16 ) {
V_205 -> V_22 = F_70 ( V_17 -> V_23 , V_186 ,
& V_205 -> V_24 ) ;
if ( ! V_205 -> V_22 ) {
F_29 ( V_9 -> V_18 -> V_98 ,
L_7 , V_19 ) ;
V_170 = true ;
V_3 -> V_16 = false ;
continue;
}
F_8 ( V_3 , V_19 , V_27 , ( V_19 == V_20 - 1 ) ) ;
}
}
V_3 -> V_20 = V_20 ;
if ( V_170 ) {
for ( V_19 = 0 ; V_19 < V_3 -> V_20 ; V_19 ++ ) {
struct V_29 * V_205 = & V_3 -> V_21 [ V_19 ] ;
if ( V_205 -> V_22 ) {
F_6 ( V_17 -> V_23 , V_205 -> V_22 ,
V_205 -> V_24 ) ;
V_205 -> V_22 = NULL ;
}
}
}
return F_71 ( & V_7 -> V_8 , & V_3 -> V_13 , V_164 ) ;
}
static struct V_11 * F_72 (
struct V_6 * V_9 , T_7 V_206 , T_6 V_207 ,
T_6 V_208 , enum V_26 V_27 , unsigned long V_126 )
{
struct V_1 * V_17 = F_1 ( V_9 -> V_18 ) ;
struct V_5 * V_7 = F_3 ( V_9 ) ;
enum V_166 V_167 ;
struct V_10 * V_3 ;
T_7 V_119 ;
unsigned V_148 ;
T_9 V_171 ;
if ( V_27 == V_37 ) {
V_119 = V_7 -> V_172 . V_173 ;
V_167 = V_7 -> V_172 . V_174 ;
V_171 = V_7 -> V_172 . V_175 ;
} else if ( V_27 == V_46 ) {
V_119 = V_7 -> V_172 . V_176 ;
V_167 = V_7 -> V_172 . V_177 ;
V_171 = V_7 -> V_172 . V_178 ;
} else {
F_29 ( V_9 -> V_18 -> V_98 , L_6 , V_179 ) ;
return NULL ;
}
switch ( V_167 ) {
case V_180 :
V_148 = V_181 ;
break;
case V_182 :
V_148 = V_183 ;
break;
case V_184 :
V_148 = V_185 ;
break;
default:
return NULL ;
}
V_3 = F_66 ( sizeof( * V_3 ) + sizeof( V_3 -> V_21 [ 0 ] ) , V_186 ) ;
if ( ! V_3 )
return NULL ;
V_3 -> V_27 = V_27 ;
V_3 -> V_119 = V_119 ;
V_3 -> V_42 = V_171 ;
V_3 -> V_148 = V_148 ;
V_3 -> V_21 [ 0 ] . V_33 = V_206 ;
V_3 -> V_21 [ 0 ] . V_32 = V_208 / V_147 [ V_148 ] ;
V_3 -> V_21 [ 0 ] . V_34 = V_207 / V_208 ;
V_3 -> V_20 = 1 ;
V_3 -> V_86 = V_7 -> V_86 ;
if ( V_27 == V_37 )
V_3 -> V_86 |= V_188 | V_189 ;
else
V_3 -> V_86 |= V_192 | V_193 ;
V_3 -> V_35 = V_196 ;
if ( V_126 & V_209 )
V_3 -> V_35 |= V_210 ;
V_3 -> V_121 = V_148 ;
if ( F_21 () ) {
V_3 -> V_35 |= V_197 ;
if ( V_27 == V_37 )
V_3 -> V_121 |= V_198 | V_211 ;
else
V_3 -> V_121 |= V_212 | V_201 ;
} else {
if ( V_171 )
V_3 -> V_86 |= V_213 ;
else
V_3 -> V_86 |= V_214 ;
if ( V_27 == V_37 ) {
V_3 -> V_86 |= V_91 ;
V_3 -> V_121 |= V_191 ;
} else {
V_3 -> V_121 |= V_195 ;
}
V_3 -> V_35 |= V_202 | V_203 ;
V_3 -> V_121 |= V_190 | V_194 ;
}
if ( F_25 ( V_17 -> V_64 -> V_67 ) )
V_3 -> V_86 |= V_215 | V_216 ;
else
V_3 -> V_122 = V_7 -> V_99 | V_102 ;
V_7 -> V_100 = true ;
return F_71 ( & V_7 -> V_8 , & V_3 -> V_13 , V_126 ) ;
}
static struct V_11 * F_73 (
struct V_6 * V_9 , T_7 V_217 , T_7 V_218 ,
T_6 V_219 , unsigned long V_164 )
{
struct V_5 * V_7 = F_3 ( V_9 ) ;
struct V_10 * V_3 ;
T_10 V_220 ;
V_3 = F_66 ( sizeof( * V_3 ) + sizeof( V_3 -> V_21 [ 0 ] ) , V_186 ) ;
if ( ! V_3 )
return NULL ;
V_220 = F_74 ( ( V_218 | V_217 | V_219 ) ) ;
if ( V_220 > V_185 )
V_220 = V_185 ;
V_3 -> V_27 = V_107 ;
V_3 -> V_119 = V_218 ;
V_3 -> V_42 = 0 ;
V_3 -> V_148 = V_220 ;
V_3 -> V_21 [ 0 ] . V_32 = V_219 / F_44 ( V_220 ) ;
V_3 -> V_21 [ 0 ] . V_34 = 1 ;
V_3 -> V_21 [ 0 ] . V_33 = V_217 ;
V_3 -> V_20 = 1 ;
V_3 -> V_86 = V_7 -> V_86 ;
V_3 -> V_86 |= V_188 | V_193 ;
V_3 -> V_35 = V_196 | V_210 ;
V_3 -> V_121 = V_220 ;
if ( F_21 () ) {
V_3 -> V_35 |= V_197 ;
V_3 -> V_121 |= V_198 | V_201 ;
} else {
V_3 -> V_121 |= V_191 | V_195 ;
V_3 -> V_35 |= V_202 | V_203 ;
V_3 -> V_121 |= V_190 | V_194 ;
}
return F_71 ( & V_7 -> V_8 , & V_3 -> V_13 , V_164 ) ;
}
static struct V_11 * F_75 (
struct V_6 * V_9 , struct V_221 * V_222 ,
unsigned long V_126 )
{
struct V_5 * V_7 = F_3 ( V_9 ) ;
struct V_10 * V_3 ;
struct V_29 * V_21 ;
T_10 V_220 ;
T_6 V_223 , V_224 ;
if ( F_76 ( V_222 -> V_27 ) )
return NULL ;
if ( V_222 -> V_225 != 1 || V_222 -> V_226 == 0 )
return NULL ;
V_3 = F_66 ( sizeof( * V_3 ) + sizeof( V_3 -> V_21 [ 0 ] ) , V_186 ) ;
if ( ! V_3 )
return NULL ;
V_220 = F_74 ( ( V_222 -> V_227 | V_222 -> V_228 | V_222 -> V_163 [ 0 ] . V_146 ) ) ;
if ( V_220 > V_185 )
V_220 = V_185 ;
V_21 = & V_3 -> V_21 [ 0 ] ;
V_3 -> V_27 = V_107 ;
V_3 -> V_119 = V_222 -> V_227 ;
V_3 -> V_148 = V_220 ;
V_21 -> V_32 = V_222 -> V_163 [ 0 ] . V_146 / F_44 ( V_220 ) ;
V_21 -> V_34 = V_222 -> V_226 ;
V_21 -> V_33 = V_222 -> V_228 ;
V_3 -> V_20 = 1 ;
V_3 -> V_86 = V_7 -> V_86 ;
V_223 = F_77 ( V_222 , & V_222 -> V_163 [ 0 ] ) ;
V_224 = F_78 ( V_222 , & V_222 -> V_163 [ 0 ] ) ;
if ( V_223 ) {
V_3 -> V_86 |= V_229 ;
V_3 -> V_39 = 1 ;
V_3 -> V_42 = V_223 ;
} else if ( V_222 -> V_230 ) {
V_3 -> V_86 |= V_193 ;
V_3 -> V_42 = 0 ;
} else {
F_29 ( V_9 -> V_18 -> V_98 ,
L_8 ,
V_179 ) ;
F_7 ( V_3 ) ;
return NULL ;
}
if ( V_224 ) {
V_3 -> V_86 |= V_231 ;
V_21 -> V_39 = 1 ;
V_21 -> V_42 = V_224 ;
} else if ( V_222 -> V_232 ) {
V_3 -> V_86 |= V_188 ;
V_21 -> V_42 = 0 ;
} else {
F_29 ( V_9 -> V_18 -> V_98 ,
L_9 ,
V_179 ) ;
F_7 ( V_3 ) ;
return NULL ;
}
V_3 -> V_35 = V_196 | V_210 ;
V_3 -> V_121 = V_220 ;
if ( F_21 () ) {
V_3 -> V_35 |= V_197 ;
V_3 -> V_121 |= V_198 | V_201 ;
} else {
V_3 -> V_121 |= V_191 | V_195 ;
V_3 -> V_35 |= V_202 | V_203 ;
V_3 -> V_121 |= V_190 | V_194 ;
}
return F_71 ( & V_7 -> V_8 , & V_3 -> V_13 , V_126 ) ;
}
static int F_79 ( struct V_6 * V_9 , struct V_233 * V_172 )
{
struct V_5 * V_7 = F_3 ( V_9 ) ;
if ( V_172 -> V_174 == V_234 ||
V_172 -> V_177 == V_234 )
return - V_235 ;
memcpy ( & V_7 -> V_172 , V_172 , sizeof( V_7 -> V_172 ) ) ;
return 0 ;
}
static int F_80 ( struct V_6 * V_9 )
{
struct V_5 * V_7 = F_3 ( V_9 ) ;
unsigned long V_126 ;
F_81 ( V_236 ) ;
F_36 ( & V_7 -> V_8 . V_127 , V_126 ) ;
if ( V_7 -> V_116 ) {
F_5 ( & V_7 -> V_116 -> V_13 ) ;
V_7 -> V_116 = NULL ;
if ( ! V_7 -> V_158 )
F_26 ( V_7 ) ;
}
if ( V_7 -> V_100 ) {
V_7 -> V_100 = false ;
V_7 -> V_158 = false ;
}
F_82 ( & V_7 -> V_8 , & V_236 ) ;
F_39 ( & V_7 -> V_8 . V_127 , V_126 ) ;
F_83 ( & V_7 -> V_8 , & V_236 ) ;
return 0 ;
}
static void F_84 ( struct V_6 * V_9 )
{
struct V_5 * V_7 = F_3 ( V_9 ) ;
F_85 ( & V_7 -> V_8 ) ;
}
static int F_86 ( struct V_6 * V_9 )
{
struct V_5 * V_7 = F_3 ( V_9 ) ;
if ( ! V_7 -> V_100 )
return - V_235 ;
if ( ! V_7 -> V_158 ) {
F_26 ( V_7 ) ;
V_7 -> V_158 = true ;
}
return 0 ;
}
static int F_87 ( struct V_6 * V_9 )
{
struct V_5 * V_7 = F_3 ( V_9 ) ;
if ( ! V_7 -> V_100 )
return - V_235 ;
if ( V_7 -> V_158 ) {
F_30 () ;
F_18 ( V_7 , V_101 , V_7 -> V_116 -> V_122 ) ;
F_24 ( V_7 , V_7 -> V_116 ) ;
V_7 -> V_158 = false ;
}
return 0 ;
}
static int F_88 ( struct V_1 * V_17 )
{
struct V_5 * V_7 ;
V_7 = F_66 ( sizeof( * V_7 ) , V_237 ) ;
if ( ! V_7 )
return - V_238 ;
V_7 -> V_57 = V_17 -> V_57 ;
V_7 -> V_8 . V_239 = F_5 ;
F_89 ( & V_7 -> V_8 , & V_17 -> V_4 ) ;
return 0 ;
}
static void F_90 ( struct V_1 * V_17 )
{
while ( ! F_91 ( & V_17 -> V_4 . V_240 ) ) {
struct V_5 * V_7 = F_92 ( & V_17 -> V_4 . V_240 ,
struct V_5 , V_8 . V_9 . V_241 ) ;
F_34 ( & V_7 -> V_8 . V_9 . V_241 ) ;
F_93 ( & V_7 -> V_8 . V_242 ) ;
F_7 ( V_7 ) ;
}
}
static int F_94 ( struct V_243 * V_244 )
{
struct V_1 * V_17 ;
struct V_245 * V_246 ;
int V_247 , V_19 , V_128 ;
V_17 = F_95 ( & V_244 -> V_98 , sizeof( * V_17 ) , V_237 ) ;
if ( ! V_17 )
return - V_238 ;
V_246 = F_96 ( V_244 , V_248 , 0 ) ;
V_17 -> V_59 = F_97 ( & V_244 -> V_98 , V_246 ) ;
if ( F_98 ( V_17 -> V_59 ) )
return F_99 ( V_17 -> V_59 ) ;
V_17 -> V_64 = F_100 () ;
if ( ! V_17 -> V_64 )
return - V_249 ;
V_17 -> V_57 = V_17 -> V_64 -> V_57 ;
F_101 ( V_250 , V_17 -> V_4 . V_251 ) ;
F_101 ( V_252 , V_17 -> V_4 . V_251 ) ;
F_101 ( V_253 , V_17 -> V_4 . V_251 ) ;
F_101 ( V_254 , V_17 -> V_4 . V_251 ) ;
V_17 -> V_4 . V_255 = F_45 ;
V_17 -> V_4 . V_256 = F_51 ;
V_17 -> V_4 . V_257 = F_60 ;
V_17 -> V_4 . V_258 = F_63 ;
V_17 -> V_4 . V_259 = F_65 ;
V_17 -> V_4 . V_260 = F_72 ;
V_17 -> V_4 . V_261 = F_73 ;
V_17 -> V_4 . V_262 = F_75 ;
V_17 -> V_4 . V_263 = F_79 ;
V_17 -> V_4 . V_264 = F_86 ;
V_17 -> V_4 . V_265 = F_87 ;
V_17 -> V_4 . V_266 = F_80 ;
V_17 -> V_4 . V_267 = F_84 ;
V_17 -> V_4 . V_268 = V_269 ;
V_17 -> V_4 . V_270 = V_269 ;
V_17 -> V_4 . V_271 = F_44 ( V_37 ) | F_44 ( V_46 ) ;
V_17 -> V_4 . V_272 = V_273 ;
V_17 -> V_4 . V_98 = & V_244 -> V_98 ;
F_102 ( & V_17 -> V_4 . V_240 ) ;
F_103 ( & V_17 -> V_127 ) ;
F_103 ( & V_17 -> V_131 ) ;
if ( ! V_244 -> V_98 . V_274 ) {
V_17 -> V_275 = V_17 -> V_64 -> V_67 -> V_276 ;
if ( F_104 ( ! V_17 -> V_275 ) )
V_17 -> V_275 = V_277 ;
} else if ( F_105 ( V_244 -> V_98 . V_274 , L_10 ,
& V_17 -> V_275 ) ) {
F_106 ( & V_244 -> V_98 ,
L_11 ,
V_277 ) ;
V_17 -> V_275 = V_277 ;
}
V_17 -> V_66 = F_107 ( & V_244 -> V_98 , V_17 -> V_275 ,
sizeof( * V_17 -> V_66 ) , V_237 ) ;
if ( ! V_17 -> V_66 )
return - V_238 ;
for ( V_19 = 0 ; V_19 < V_17 -> V_275 ; V_19 ++ ) {
V_247 = F_88 ( V_17 ) ;
if ( V_247 ) {
F_90 ( V_17 ) ;
return V_247 ;
}
}
V_128 = F_108 ( V_244 , 1 ) ;
if ( V_128 <= 0 ) {
F_106 ( & V_244 -> V_98 , L_12 , V_128 ) ;
V_17 -> V_139 = true ;
} else {
V_17 -> V_133 = 0 ;
F_16 ( V_17 , V_141 , 0 ) ;
V_247 = F_109 ( & V_244 -> V_98 , V_128 , F_40 ,
V_278 , L_13 , V_17 ) ;
if ( V_247 )
return V_247 ;
}
if ( F_17 ( V_17 , V_279 ) & V_280 )
V_17 -> V_83 = true ;
V_17 -> V_4 . V_281 . V_282 = V_17 -> V_64 -> V_283 ;
V_17 -> V_4 . V_281 . V_284 = V_17 -> V_64 -> V_285 ;
V_17 -> V_4 . V_281 . V_34 = V_286 ;
if ( V_17 -> V_83 ) {
V_17 -> V_23 = F_110 ( F_111 ( & V_244 -> V_98 ) ,
& V_244 -> V_98 ,
sizeof( struct V_30 ) ,
4 , 0 ) ;
if ( ! V_17 -> V_23 ) {
F_29 ( & V_244 -> V_98 ,
L_14 ) ;
V_17 -> V_83 = false ;
}
}
V_247 = F_112 ( & V_17 -> V_4 ) ;
if ( V_247 ) {
F_113 ( L_15 ,
V_247 ) ;
F_90 ( V_17 ) ;
return V_247 ;
}
F_114 ( V_244 , V_17 ) ;
if ( V_244 -> V_98 . V_274 ) {
V_287 . V_288 = V_17 -> V_4 . V_251 ;
V_247 = F_115 ( V_244 -> V_98 . V_274 ,
V_289 , & V_287 ) ;
if ( V_247 ) {
F_113 ( L_16 ) ;
F_116 ( & V_17 -> V_4 ) ;
F_90 ( V_17 ) ;
}
}
F_106 ( & V_244 -> V_98 , L_17 ,
V_17 -> V_83 ? L_18 : L_19 ) ;
return V_247 ;
}
static int F_117 ( struct V_243 * V_244 )
{
struct V_1 * V_17 = F_118 ( V_244 ) ;
int V_128 ;
if ( V_244 -> V_98 . V_274 )
F_119 ( V_244 -> V_98 . V_274 ) ;
V_128 = F_108 ( V_244 , 1 ) ;
F_120 ( & V_244 -> V_98 , V_128 , V_17 ) ;
F_116 ( & V_17 -> V_4 ) ;
if ( ! V_17 -> V_139 ) {
F_16 ( V_17 , V_142 , 0 ) ;
}
if ( V_17 -> V_83 )
F_121 ( V_17 -> V_23 ) ;
F_90 ( V_17 ) ;
return 0 ;
}
bool V_286 ( struct V_6 * V_9 , void * V_290 )
{
if ( V_9 -> V_18 -> V_98 -> V_291 == & V_292 . V_291 ) {
struct V_1 * V_17 = F_1 ( V_9 -> V_18 ) ;
struct V_5 * V_7 = F_3 ( V_9 ) ;
unsigned V_293 = * ( unsigned * ) V_290 ;
if ( V_293 <= V_17 -> V_275 ) {
V_7 -> V_140 = V_293 ;
return true ;
}
}
return false ;
}
static int F_122 ( void )
{
return F_123 ( & V_292 ) ;
}
static void T_11 F_124 ( void )
{
F_125 ( & V_292 ) ;
}
