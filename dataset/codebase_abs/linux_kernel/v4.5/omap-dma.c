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
F_6 ( F_2 ( V_13 , struct V_10 , V_13 ) ) ;
}
static void F_7 ( T_1 V_16 , unsigned type , void T_2 * V_17 )
{
switch ( type ) {
case V_18 :
F_8 ( V_16 , V_17 ) ;
break;
case V_19 :
F_8 ( V_16 , V_17 ) ;
F_8 ( V_16 >> 16 , V_17 + 2 ) ;
break;
case V_20 :
F_9 ( V_16 , V_17 ) ;
break;
default:
F_10 ( 1 ) ;
}
}
static unsigned F_11 ( unsigned type , void T_2 * V_17 )
{
unsigned V_16 ;
switch ( type ) {
case V_18 :
V_16 = F_12 ( V_17 ) ;
break;
case V_19 :
V_16 = F_12 ( V_17 ) ;
V_16 |= F_12 ( V_17 + 2 ) << 16 ;
break;
case V_20 :
V_16 = F_13 ( V_17 ) ;
break;
default:
F_10 ( 1 ) ;
V_16 = 0 ;
}
return V_16 ;
}
static void F_14 ( struct V_1 * V_21 , unsigned V_22 , unsigned V_16 )
{
const struct V_23 * V_24 = V_21 -> V_25 + V_22 ;
F_10 ( V_24 -> V_26 ) ;
F_7 ( V_16 , V_24 -> type , V_21 -> V_27 + V_24 -> V_28 ) ;
}
static unsigned F_15 ( struct V_1 * V_21 , unsigned V_22 )
{
const struct V_23 * V_24 = V_21 -> V_25 + V_22 ;
F_10 ( V_24 -> V_26 ) ;
return F_11 ( V_24 -> type , V_21 -> V_27 + V_24 -> V_28 ) ;
}
static void F_16 ( struct V_5 * V_7 , unsigned V_22 , unsigned V_16 )
{
const struct V_23 * V_24 = V_7 -> V_25 + V_22 ;
F_7 ( V_16 , V_24 -> type , V_7 -> V_29 + V_24 -> V_28 ) ;
}
static unsigned F_17 ( struct V_5 * V_7 , unsigned V_22 )
{
const struct V_23 * V_24 = V_7 -> V_25 + V_22 ;
return F_11 ( V_24 -> type , V_7 -> V_29 + V_24 -> V_28 ) ;
}
static void F_18 ( struct V_5 * V_7 )
{
if ( F_19 () )
F_17 ( V_7 , V_30 ) ;
else
F_16 ( V_7 , V_30 , ~ 0 ) ;
}
static unsigned F_20 ( struct V_5 * V_7 )
{
unsigned V_16 = F_17 ( V_7 , V_30 ) ;
if ( ! F_19 () )
F_16 ( V_7 , V_30 , V_16 ) ;
return V_16 ;
}
static void F_21 ( struct V_1 * V_21 , struct V_5 * V_7 ,
unsigned V_31 )
{
V_7 -> V_29 = V_21 -> V_27 + V_21 -> V_32 -> V_33 * V_31 ;
V_21 -> V_34 [ V_31 ] = V_7 ;
}
static void F_22 ( struct V_5 * V_7 , struct V_10 * V_3 )
{
struct V_1 * V_21 = F_1 ( V_7 -> V_8 . V_9 . V_35 ) ;
if ( F_23 ( V_21 -> V_32 -> V_36 ) )
F_16 ( V_7 , V_37 , 0 ) ;
else
F_16 ( V_7 , V_38 , 0 ) ;
F_18 ( V_7 ) ;
F_16 ( V_7 , V_39 , V_3 -> V_40 ) ;
F_16 ( V_7 , V_41 , V_3 -> V_42 | V_43 ) ;
}
static void F_24 ( struct V_5 * V_7 )
{
struct V_1 * V_21 = F_1 ( V_7 -> V_8 . V_9 . V_35 ) ;
T_1 V_16 ;
F_16 ( V_7 , V_39 , 0 ) ;
F_18 ( V_7 ) ;
V_16 = F_17 ( V_7 , V_41 ) ;
if ( V_21 -> V_32 -> V_44 & V_45 && V_16 & V_46 ) {
T_1 V_47 ;
unsigned V_48 ;
V_47 = F_15 ( V_21 , V_49 ) ;
V_16 = V_47 & ~ V_50 ;
V_16 |= F_25 ( V_51 ) ;
F_14 ( V_21 , V_49 , V_16 ) ;
V_16 = F_17 ( V_7 , V_41 ) ;
V_16 &= ~ V_43 ;
F_16 ( V_7 , V_41 , V_16 ) ;
for ( V_48 = 0 ; ; V_48 ++ ) {
V_16 = F_17 ( V_7 , V_41 ) ;
if ( ! ( V_16 & ( V_52 | V_53 ) ) )
break;
if ( V_48 > 100 )
break;
F_26 ( 5 ) ;
}
if ( V_16 & ( V_52 | V_53 ) )
F_27 ( V_7 -> V_8 . V_9 . V_35 -> V_54 ,
L_1 ,
V_7 -> V_55 ) ;
F_14 ( V_21 , V_49 , V_47 ) ;
} else {
V_16 &= ~ V_43 ;
F_16 ( V_7 , V_41 , V_16 ) ;
}
F_28 () ;
if ( ! F_23 ( V_21 -> V_32 -> V_36 ) && V_7 -> V_56 ) {
V_16 = F_17 ( V_7 , V_57 ) ;
if ( F_19 () )
V_16 |= 1 << 14 ;
else
V_16 &= ~ V_58 ;
F_16 ( V_7 , V_57 , V_16 ) ;
}
}
static void F_29 ( struct V_5 * V_7 , struct V_10 * V_3 ,
unsigned V_59 )
{
struct V_60 * V_61 = V_3 -> V_61 + V_59 ;
unsigned V_62 , V_63 , V_64 ;
if ( V_3 -> V_65 == V_66 || V_3 -> V_65 == V_67 ) {
V_62 = V_68 ;
V_63 = V_69 ;
V_64 = V_70 ;
} else {
V_62 = V_71 ;
V_63 = V_72 ;
V_64 = V_73 ;
}
F_16 ( V_7 , V_62 , V_61 -> V_17 ) ;
F_16 ( V_7 , V_63 , 0 ) ;
F_16 ( V_7 , V_64 , 0 ) ;
F_16 ( V_7 , V_74 , V_61 -> V_75 ) ;
F_16 ( V_7 , V_76 , V_61 -> V_77 ) ;
F_22 ( V_7 , V_3 ) ;
}
static void F_30 ( struct V_5 * V_7 )
{
struct V_15 * V_13 = F_31 ( & V_7 -> V_8 ) ;
struct V_10 * V_3 ;
unsigned V_62 , V_63 , V_64 ;
if ( ! V_13 ) {
V_7 -> V_78 = NULL ;
return;
}
F_32 ( & V_13 -> V_79 ) ;
V_7 -> V_78 = V_3 = F_4 ( & V_13 -> V_14 ) ;
V_7 -> V_80 = 0 ;
F_28 () ;
F_16 ( V_7 , V_41 , V_3 -> V_42 ) ;
if ( F_19 () )
F_16 ( V_7 , V_81 , V_3 -> V_42 >> 16 ) ;
if ( V_3 -> V_65 == V_66 || V_3 -> V_65 == V_67 ) {
V_62 = V_71 ;
V_63 = V_72 ;
V_64 = V_73 ;
} else {
V_62 = V_68 ;
V_63 = V_69 ;
V_64 = V_70 ;
}
F_16 ( V_7 , V_62 , V_3 -> V_82 ) ;
F_16 ( V_7 , V_63 , 0 ) ;
F_16 ( V_7 , V_64 , V_3 -> V_83 ) ;
F_16 ( V_7 , V_84 , V_3 -> V_85 ) ;
F_16 ( V_7 , V_57 , V_3 -> V_86 ) ;
F_29 ( V_7 , V_3 , 0 ) ;
}
static void F_33 ( int V_87 , T_3 V_88 , void * V_89 )
{
struct V_5 * V_7 = V_89 ;
struct V_10 * V_3 ;
unsigned long V_90 ;
F_34 ( & V_7 -> V_8 . V_91 , V_90 ) ;
V_3 = V_7 -> V_78 ;
if ( V_3 ) {
if ( ! V_7 -> V_56 ) {
if ( ++ V_7 -> V_80 < V_3 -> V_92 ) {
F_29 ( V_7 , V_3 , V_7 -> V_80 ) ;
} else {
F_30 ( V_7 ) ;
F_35 ( & V_3 -> V_13 ) ;
}
} else {
F_36 ( & V_3 -> V_13 ) ;
}
}
F_37 ( & V_7 -> V_8 . V_91 , V_90 ) ;
}
static T_4 F_38 ( int V_93 , void * V_94 )
{
struct V_1 * V_21 = V_94 ;
unsigned V_88 , V_95 ;
F_39 ( & V_21 -> V_96 ) ;
V_88 = F_15 ( V_21 , V_97 ) ;
V_88 &= V_21 -> V_98 ;
if ( V_88 == 0 ) {
F_40 ( & V_21 -> V_96 ) ;
return V_99 ;
}
while ( ( V_95 = F_41 ( V_88 ) ) != 0 ) {
unsigned V_100 , V_101 ;
struct V_5 * V_7 ;
V_95 -= 1 ;
V_100 = F_42 ( V_95 ) ;
V_88 &= ~ V_100 ;
V_7 = V_21 -> V_34 [ V_95 ] ;
if ( V_7 == NULL ) {
F_27 ( V_21 -> V_4 . V_54 , L_2 , V_95 ) ;
continue;
}
V_101 = F_20 ( V_7 ) ;
F_14 ( V_21 , V_97 , V_100 ) ;
F_33 ( V_95 , V_101 , V_7 ) ;
}
F_40 ( & V_21 -> V_96 ) ;
return V_102 ;
}
static int F_43 ( struct V_6 * V_9 )
{
struct V_1 * V_21 = F_1 ( V_9 -> V_35 ) ;
struct V_5 * V_7 = F_3 ( V_9 ) ;
int V_103 ;
if ( V_21 -> V_104 ) {
V_103 = F_44 ( V_7 -> V_105 , L_3 ,
F_33 , V_7 , & V_7 -> V_55 ) ;
} else {
V_103 = F_44 ( V_7 -> V_105 , L_3 , NULL , NULL ,
& V_7 -> V_55 ) ;
}
F_45 ( V_21 -> V_4 . V_54 , L_4 ,
V_7 -> V_55 , V_7 -> V_105 ) ;
if ( V_103 >= 0 ) {
F_21 ( V_21 , V_7 , V_7 -> V_55 ) ;
if ( ! V_21 -> V_104 ) {
unsigned V_16 ;
F_46 ( & V_21 -> V_96 ) ;
V_16 = F_42 ( V_7 -> V_55 ) ;
F_14 ( V_21 , V_97 , V_16 ) ;
V_21 -> V_98 |= V_16 ;
F_14 ( V_21 , V_106 , V_21 -> V_98 ) ;
V_16 = F_15 ( V_21 , V_107 ) ;
V_16 &= ~ F_42 ( V_7 -> V_55 ) ;
F_14 ( V_21 , V_107 , V_16 ) ;
F_47 ( & V_21 -> V_96 ) ;
}
}
if ( F_19 () ) {
if ( F_48 ( V_21 -> V_32 -> V_36 ) ) {
V_7 -> V_42 = V_108 ;
V_7 -> V_42 |= V_7 -> V_55 + 1 ;
} else {
V_7 -> V_42 = V_7 -> V_105 & 0x1f ;
}
} else {
V_7 -> V_42 = V_7 -> V_105 & 0x1f ;
V_7 -> V_42 |= ( V_7 -> V_105 & ~ 0x1f ) << 14 ;
}
if ( V_21 -> V_32 -> V_44 & V_109 )
V_7 -> V_42 |= V_110 ;
return V_103 ;
}
static void F_49 ( struct V_6 * V_9 )
{
struct V_1 * V_21 = F_1 ( V_9 -> V_35 ) ;
struct V_5 * V_7 = F_3 ( V_9 ) ;
if ( ! V_21 -> V_104 ) {
F_46 ( & V_21 -> V_96 ) ;
V_21 -> V_98 &= ~ F_42 ( V_7 -> V_55 ) ;
F_14 ( V_21 , V_106 , V_21 -> V_98 ) ;
F_47 ( & V_21 -> V_96 ) ;
}
V_7 -> V_29 = NULL ;
V_21 -> V_34 [ V_7 -> V_55 ] = NULL ;
F_50 ( & V_7 -> V_8 ) ;
F_51 ( V_7 -> V_55 ) ;
F_45 ( V_21 -> V_4 . V_54 , L_5 , V_7 -> V_105 ) ;
V_7 -> V_105 = 0 ;
}
static T_5 F_52 ( struct V_60 * V_61 )
{
return V_61 -> V_75 * V_61 -> V_77 ;
}
static T_5 F_53 ( struct V_10 * V_3 )
{
unsigned V_48 ;
T_5 V_111 ;
for ( V_111 = V_48 = 0 ; V_48 < V_3 -> V_92 ; V_48 ++ )
V_111 += F_52 ( & V_3 -> V_61 [ V_48 ] ) ;
return V_111 * V_112 [ V_3 -> V_113 ] ;
}
static T_5 F_54 ( struct V_10 * V_3 , T_6 V_17 )
{
unsigned V_48 ;
T_5 V_111 , V_114 = V_112 [ V_3 -> V_113 ] ;
for ( V_111 = V_48 = 0 ; V_48 < V_3 -> V_92 ; V_48 ++ ) {
T_5 V_115 = F_52 ( & V_3 -> V_61 [ V_48 ] ) * V_114 ;
if ( V_111 )
V_111 += V_115 ;
else if ( V_17 >= V_3 -> V_61 [ V_48 ] . V_17 &&
V_17 < V_3 -> V_61 [ V_48 ] . V_17 + V_115 )
V_111 += V_3 -> V_61 [ V_48 ] . V_17 + V_115 - V_17 ;
}
return V_111 ;
}
static T_1 F_55 ( struct V_5 * V_7 , unsigned V_22 )
{
struct V_1 * V_21 = F_1 ( V_7 -> V_8 . V_9 . V_35 ) ;
T_1 V_16 ;
V_16 = F_17 ( V_7 , V_22 ) ;
if ( V_16 == 0 && V_21 -> V_32 -> V_44 & V_116 )
V_16 = F_17 ( V_7 , V_22 ) ;
return V_16 ;
}
static T_6 F_56 ( struct V_5 * V_7 )
{
struct V_1 * V_21 = F_1 ( V_7 -> V_8 . V_9 . V_35 ) ;
T_6 V_17 , V_117 ;
if ( F_23 ( V_21 -> V_32 -> V_36 ) ) {
V_17 = F_17 ( V_7 , V_37 ) ;
} else {
V_17 = F_55 ( V_7 , V_118 ) ;
V_117 = F_55 ( V_7 , V_38 ) ;
if ( V_117 == 0 )
V_17 = F_17 ( V_7 , V_71 ) ;
}
if ( F_19 () )
V_17 |= F_17 ( V_7 , V_71 ) & 0xffff0000 ;
return V_17 ;
}
static T_6 F_57 ( struct V_5 * V_7 )
{
struct V_1 * V_21 = F_1 ( V_7 -> V_8 . V_9 . V_35 ) ;
T_6 V_17 ;
if ( F_23 ( V_21 -> V_32 -> V_36 ) ) {
V_17 = F_17 ( V_7 , V_37 ) ;
} else {
V_17 = F_55 ( V_7 , V_38 ) ;
if ( V_17 == 0 )
V_17 = F_17 ( V_7 , V_68 ) ;
}
if ( F_19 () )
V_17 |= F_17 ( V_7 , V_68 ) & 0xffff0000 ;
return V_17 ;
}
static enum V_119 F_58 ( struct V_6 * V_9 ,
T_7 V_120 , struct V_121 * V_122 )
{
struct V_5 * V_7 = F_3 ( V_9 ) ;
struct V_15 * V_13 ;
enum V_119 V_103 ;
T_1 V_42 ;
unsigned long V_90 ;
V_42 = F_17 ( V_7 , V_41 ) ;
if ( ! ( V_42 & V_43 ) )
F_33 ( V_7 -> V_55 , 0 , V_7 ) ;
V_103 = F_59 ( V_9 , V_120 , V_122 ) ;
if ( V_103 == V_123 || ! V_122 )
return V_103 ;
F_34 ( & V_7 -> V_8 . V_91 , V_90 ) ;
V_13 = F_60 ( & V_7 -> V_8 , V_120 ) ;
if ( V_13 ) {
V_122 -> V_124 = F_53 ( F_4 ( & V_13 -> V_14 ) ) ;
} else if ( V_7 -> V_78 && V_7 -> V_78 -> V_13 . V_14 . V_120 == V_120 ) {
struct V_10 * V_3 = V_7 -> V_78 ;
T_6 V_125 ;
if ( V_3 -> V_65 == V_126 )
V_125 = F_56 ( V_7 ) ;
else if ( V_3 -> V_65 == V_66 || V_3 -> V_65 == V_67 )
V_125 = F_57 ( V_7 ) ;
else
V_125 = 0 ;
V_122 -> V_124 = F_54 ( V_3 , V_125 ) ;
} else {
V_122 -> V_124 = 0 ;
}
F_37 ( & V_7 -> V_8 . V_91 , V_90 ) ;
return V_103 ;
}
static void F_61 ( struct V_6 * V_9 )
{
struct V_5 * V_7 = F_3 ( V_9 ) ;
unsigned long V_90 ;
F_34 ( & V_7 -> V_8 . V_91 , V_90 ) ;
if ( F_62 ( & V_7 -> V_8 ) && ! V_7 -> V_78 )
F_30 ( V_7 ) ;
F_37 ( & V_7 -> V_8 . V_91 , V_90 ) ;
}
static struct V_11 * F_63 (
struct V_6 * V_9 , struct V_127 * V_128 , unsigned V_92 ,
enum V_129 V_65 , unsigned long V_130 , void * V_131 )
{
struct V_1 * V_21 = F_1 ( V_9 -> V_35 ) ;
struct V_5 * V_7 = F_3 ( V_9 ) ;
enum V_132 V_133 ;
struct V_127 * V_134 ;
struct V_10 * V_3 ;
T_6 V_82 ;
unsigned V_48 , V_113 , V_75 , V_135 ;
T_8 V_136 ;
if ( V_65 == V_66 ) {
V_82 = V_7 -> V_137 . V_138 ;
V_133 = V_7 -> V_137 . V_139 ;
V_136 = V_7 -> V_137 . V_140 ;
} else if ( V_65 == V_126 ) {
V_82 = V_7 -> V_137 . V_141 ;
V_133 = V_7 -> V_137 . V_142 ;
V_136 = V_7 -> V_137 . V_143 ;
} else {
F_27 ( V_9 -> V_35 -> V_54 , L_6 , V_144 ) ;
return NULL ;
}
switch ( V_133 ) {
case V_145 :
V_113 = V_146 ;
break;
case V_147 :
V_113 = V_148 ;
break;
case V_149 :
V_113 = V_150 ;
break;
default:
return NULL ;
}
V_3 = F_64 ( sizeof( * V_3 ) + V_92 * sizeof( V_3 -> V_61 [ 0 ] ) , V_151 ) ;
if ( ! V_3 )
return NULL ;
V_3 -> V_65 = V_65 ;
V_3 -> V_82 = V_82 ;
V_3 -> V_113 = V_113 ;
V_3 -> V_42 = V_7 -> V_42 | V_152 ;
if ( V_65 == V_66 )
V_3 -> V_42 |= V_153 | V_154 ;
else
V_3 -> V_42 |= V_155 | V_156 ;
V_3 -> V_40 = V_157 | V_158 ;
V_3 -> V_85 = V_113 ;
if ( F_19 () ) {
V_3 -> V_40 |= V_159 ;
if ( V_65 == V_66 )
V_3 -> V_85 |= V_160 | V_161 ;
else
V_3 -> V_85 |= V_162 | V_163 ;
} else {
if ( V_65 == V_66 )
V_3 -> V_42 |= V_46 ;
V_3 -> V_40 |= V_164 | V_165 ;
}
if ( V_21 -> V_32 -> V_44 & V_166 )
V_3 -> V_86 = V_7 -> V_55 ;
V_75 = V_136 ;
V_135 = V_112 [ V_113 ] * V_75 ;
F_65 (sgl, sgent, sglen, i) {
V_3 -> V_61 [ V_48 ] . V_17 = F_66 ( V_134 ) ;
V_3 -> V_61 [ V_48 ] . V_75 = V_75 ;
V_3 -> V_61 [ V_48 ] . V_77 = F_67 ( V_134 ) / V_135 ;
}
V_3 -> V_92 = V_92 ;
return F_68 ( & V_7 -> V_8 , & V_3 -> V_13 , V_130 ) ;
}
static struct V_11 * F_69 (
struct V_6 * V_9 , T_6 V_167 , T_5 V_168 ,
T_5 V_169 , enum V_129 V_65 , unsigned long V_90 )
{
struct V_1 * V_21 = F_1 ( V_9 -> V_35 ) ;
struct V_5 * V_7 = F_3 ( V_9 ) ;
enum V_132 V_133 ;
struct V_10 * V_3 ;
T_6 V_82 ;
unsigned V_113 ;
T_8 V_136 ;
if ( V_65 == V_66 ) {
V_82 = V_7 -> V_137 . V_138 ;
V_133 = V_7 -> V_137 . V_139 ;
V_136 = V_7 -> V_137 . V_140 ;
} else if ( V_65 == V_126 ) {
V_82 = V_7 -> V_137 . V_141 ;
V_133 = V_7 -> V_137 . V_142 ;
V_136 = V_7 -> V_137 . V_143 ;
} else {
F_27 ( V_9 -> V_35 -> V_54 , L_6 , V_144 ) ;
return NULL ;
}
switch ( V_133 ) {
case V_145 :
V_113 = V_146 ;
break;
case V_147 :
V_113 = V_148 ;
break;
case V_149 :
V_113 = V_150 ;
break;
default:
return NULL ;
}
V_3 = F_64 ( sizeof( * V_3 ) + sizeof( V_3 -> V_61 [ 0 ] ) , V_151 ) ;
if ( ! V_3 )
return NULL ;
V_3 -> V_65 = V_65 ;
V_3 -> V_82 = V_82 ;
V_3 -> V_83 = V_136 ;
V_3 -> V_113 = V_113 ;
V_3 -> V_61 [ 0 ] . V_17 = V_167 ;
V_3 -> V_61 [ 0 ] . V_75 = V_169 / V_112 [ V_113 ] ;
V_3 -> V_61 [ 0 ] . V_77 = V_168 / V_169 ;
V_3 -> V_92 = 1 ;
V_3 -> V_42 = V_7 -> V_42 ;
if ( V_65 == V_66 )
V_3 -> V_42 |= V_153 | V_154 ;
else
V_3 -> V_42 |= V_155 | V_156 ;
V_3 -> V_40 = V_157 ;
if ( V_90 & V_170 )
V_3 -> V_40 |= V_171 ;
V_3 -> V_85 = V_113 ;
if ( F_19 () ) {
V_3 -> V_40 |= V_159 ;
if ( V_65 == V_66 )
V_3 -> V_85 |= V_160 | V_172 ;
else
V_3 -> V_85 |= V_173 | V_163 ;
} else {
if ( V_136 )
V_3 -> V_42 |= V_174 ;
else
V_3 -> V_42 |= V_175 ;
if ( V_65 == V_66 ) {
V_3 -> V_42 |= V_46 ;
V_3 -> V_85 |= V_176 ;
} else {
V_3 -> V_85 |= V_177 ;
}
V_3 -> V_40 |= V_164 | V_165 ;
V_3 -> V_85 |= V_178 | V_179 ;
}
if ( F_23 ( V_21 -> V_32 -> V_36 ) )
V_3 -> V_42 |= V_180 | V_181 ;
else
V_3 -> V_86 = V_7 -> V_55 | V_58 ;
V_7 -> V_56 = true ;
return F_68 ( & V_7 -> V_8 , & V_3 -> V_13 , V_90 ) ;
}
static struct V_11 * F_70 (
struct V_6 * V_9 , T_6 V_182 , T_6 V_183 ,
T_5 V_184 , unsigned long V_130 )
{
struct V_5 * V_7 = F_3 ( V_9 ) ;
struct V_10 * V_3 ;
T_9 V_185 ;
V_3 = F_64 ( sizeof( * V_3 ) + sizeof( V_3 -> V_61 [ 0 ] ) , V_151 ) ;
if ( ! V_3 )
return NULL ;
V_185 = F_71 ( ( V_183 | V_182 | V_184 ) ) ;
if ( V_185 > V_150 )
V_185 = V_150 ;
V_3 -> V_65 = V_67 ;
V_3 -> V_82 = V_183 ;
V_3 -> V_83 = 0 ;
V_3 -> V_113 = V_185 ;
V_3 -> V_61 [ 0 ] . V_75 = V_184 / F_42 ( V_185 ) ;
V_3 -> V_61 [ 0 ] . V_77 = 1 ;
V_3 -> V_61 [ 0 ] . V_17 = V_182 ;
V_3 -> V_92 = 1 ;
V_3 -> V_42 = V_7 -> V_42 ;
V_3 -> V_42 |= V_153 | V_156 ;
V_3 -> V_40 = V_157 ;
if ( V_130 & V_170 )
V_3 -> V_40 |= V_171 ;
V_3 -> V_85 = V_185 ;
if ( F_19 () ) {
V_3 -> V_40 |= V_159 ;
V_3 -> V_85 |= V_160 | V_163 ;
} else {
V_3 -> V_85 |= V_176 | V_177 ;
V_3 -> V_40 |= V_164 | V_165 ;
V_3 -> V_85 |= V_178 | V_179 ;
}
return F_68 ( & V_7 -> V_8 , & V_3 -> V_13 , V_130 ) ;
}
static int F_72 ( struct V_6 * V_9 , struct V_186 * V_137 )
{
struct V_5 * V_7 = F_3 ( V_9 ) ;
if ( V_137 -> V_139 == V_187 ||
V_137 -> V_142 == V_187 )
return - V_188 ;
memcpy ( & V_7 -> V_137 , V_137 , sizeof( V_7 -> V_137 ) ) ;
return 0 ;
}
static int F_73 ( struct V_6 * V_9 )
{
struct V_5 * V_7 = F_3 ( V_9 ) ;
unsigned long V_90 ;
F_74 ( V_189 ) ;
F_34 ( & V_7 -> V_8 . V_91 , V_90 ) ;
if ( V_7 -> V_78 ) {
F_5 ( & V_7 -> V_78 -> V_13 ) ;
V_7 -> V_78 = NULL ;
if ( ! V_7 -> V_190 )
F_24 ( V_7 ) ;
}
if ( V_7 -> V_56 ) {
V_7 -> V_56 = false ;
V_7 -> V_190 = false ;
}
F_75 ( & V_7 -> V_8 , & V_189 ) ;
F_37 ( & V_7 -> V_8 . V_91 , V_90 ) ;
F_76 ( & V_7 -> V_8 , & V_189 ) ;
return 0 ;
}
static int F_77 ( struct V_6 * V_9 )
{
struct V_5 * V_7 = F_3 ( V_9 ) ;
if ( ! V_7 -> V_56 )
return - V_188 ;
if ( ! V_7 -> V_190 ) {
F_24 ( V_7 ) ;
V_7 -> V_190 = true ;
}
return 0 ;
}
static int F_78 ( struct V_6 * V_9 )
{
struct V_5 * V_7 = F_3 ( V_9 ) ;
if ( ! V_7 -> V_56 )
return - V_188 ;
if ( V_7 -> V_190 ) {
F_28 () ;
F_16 ( V_7 , V_57 , V_7 -> V_78 -> V_86 ) ;
F_22 ( V_7 , V_7 -> V_78 ) ;
V_7 -> V_190 = false ;
}
return 0 ;
}
static int F_79 ( struct V_1 * V_21 )
{
struct V_5 * V_7 ;
V_7 = F_64 ( sizeof( * V_7 ) , V_191 ) ;
if ( ! V_7 )
return - V_192 ;
V_7 -> V_25 = V_21 -> V_25 ;
V_7 -> V_8 . V_193 = F_5 ;
F_80 ( & V_7 -> V_8 , & V_21 -> V_4 ) ;
return 0 ;
}
static void F_81 ( struct V_1 * V_21 )
{
while ( ! F_82 ( & V_21 -> V_4 . V_194 ) ) {
struct V_5 * V_7 = F_83 ( & V_21 -> V_4 . V_194 ,
struct V_5 , V_8 . V_9 . V_195 ) ;
F_32 ( & V_7 -> V_8 . V_9 . V_195 ) ;
F_84 ( & V_7 -> V_8 . V_196 ) ;
F_6 ( V_7 ) ;
}
}
static int F_85 ( struct V_197 * V_198 )
{
struct V_1 * V_21 ;
struct V_199 * V_200 ;
int V_201 , V_48 , V_93 ;
V_21 = F_86 ( & V_198 -> V_54 , sizeof( * V_21 ) , V_191 ) ;
if ( ! V_21 )
return - V_192 ;
V_200 = F_87 ( V_198 , V_202 , 0 ) ;
V_21 -> V_27 = F_88 ( & V_198 -> V_54 , V_200 ) ;
if ( F_89 ( V_21 -> V_27 ) )
return F_90 ( V_21 -> V_27 ) ;
V_21 -> V_32 = F_91 () ;
if ( ! V_21 -> V_32 )
return - V_203 ;
V_21 -> V_25 = V_21 -> V_32 -> V_25 ;
F_92 ( V_204 , V_21 -> V_4 . V_205 ) ;
F_92 ( V_206 , V_21 -> V_4 . V_205 ) ;
F_92 ( V_207 , V_21 -> V_4 . V_205 ) ;
V_21 -> V_4 . V_208 = F_43 ;
V_21 -> V_4 . V_209 = F_49 ;
V_21 -> V_4 . V_210 = F_58 ;
V_21 -> V_4 . V_211 = F_61 ;
V_21 -> V_4 . V_212 = F_63 ;
V_21 -> V_4 . V_213 = F_69 ;
V_21 -> V_4 . V_214 = F_70 ;
V_21 -> V_4 . V_215 = F_72 ;
V_21 -> V_4 . V_216 = F_77 ;
V_21 -> V_4 . V_217 = F_78 ;
V_21 -> V_4 . V_218 = F_73 ;
V_21 -> V_4 . V_219 = V_220 ;
V_21 -> V_4 . V_221 = V_220 ;
V_21 -> V_4 . V_222 = F_42 ( V_66 ) | F_42 ( V_126 ) ;
V_21 -> V_4 . V_223 = V_224 ;
V_21 -> V_4 . V_54 = & V_198 -> V_54 ;
F_93 ( & V_21 -> V_4 . V_194 ) ;
F_94 ( & V_21 -> V_91 ) ;
F_94 ( & V_21 -> V_96 ) ;
V_21 -> V_225 = V_226 ;
if ( V_198 -> V_54 . V_227 && F_95 ( V_198 -> V_54 . V_227 ,
L_7 ,
& V_21 -> V_225 ) ) {
F_96 ( & V_198 -> V_54 ,
L_8 ,
V_226 ) ;
}
for ( V_48 = 0 ; V_48 < V_228 ; V_48 ++ ) {
V_201 = F_79 ( V_21 ) ;
if ( V_201 ) {
F_81 ( V_21 ) ;
return V_201 ;
}
}
V_93 = F_97 ( V_198 , 1 ) ;
if ( V_93 <= 0 ) {
F_96 ( & V_198 -> V_54 , L_9 , V_93 ) ;
V_21 -> V_104 = true ;
} else {
V_21 -> V_98 = 0 ;
F_14 ( V_21 , V_106 , 0 ) ;
V_201 = F_98 ( & V_198 -> V_54 , V_93 , F_38 ,
V_229 , L_10 , V_21 ) ;
if ( V_201 )
return V_201 ;
}
V_21 -> V_4 . V_230 . V_231 = V_21 -> V_32 -> V_232 ;
V_21 -> V_4 . V_230 . V_233 = V_21 -> V_32 -> V_234 ;
V_21 -> V_4 . V_230 . V_77 = V_235 ;
V_201 = F_99 ( & V_21 -> V_4 ) ;
if ( V_201 ) {
F_100 ( L_11 ,
V_201 ) ;
F_81 ( V_21 ) ;
return V_201 ;
}
F_101 ( V_198 , V_21 ) ;
if ( V_198 -> V_54 . V_227 ) {
V_236 . V_237 = V_21 -> V_4 . V_205 ;
V_201 = F_102 ( V_198 -> V_54 . V_227 ,
V_238 , & V_236 ) ;
if ( V_201 ) {
F_100 ( L_12 ) ;
F_103 ( & V_21 -> V_4 ) ;
F_81 ( V_21 ) ;
}
}
F_96 ( & V_198 -> V_54 , L_13 ) ;
return V_201 ;
}
static int F_104 ( struct V_197 * V_198 )
{
struct V_1 * V_21 = F_105 ( V_198 ) ;
if ( V_198 -> V_54 . V_227 )
F_106 ( V_198 -> V_54 . V_227 ) ;
F_103 ( & V_21 -> V_4 ) ;
if ( ! V_21 -> V_104 ) {
F_14 ( V_21 , V_107 , 0 ) ;
}
F_81 ( V_21 ) ;
return 0 ;
}
bool V_235 ( struct V_6 * V_9 , void * V_239 )
{
if ( V_9 -> V_35 -> V_54 -> V_240 == & V_241 . V_240 ) {
struct V_1 * V_21 = F_1 ( V_9 -> V_35 ) ;
struct V_5 * V_7 = F_3 ( V_9 ) ;
unsigned V_242 = * ( unsigned * ) V_239 ;
if ( V_242 <= V_21 -> V_225 ) {
V_7 -> V_105 = V_242 ;
return true ;
}
}
return false ;
}
static int F_107 ( void )
{
return F_108 ( & V_241 ) ;
}
static void T_10 F_109 ( void )
{
F_110 ( & V_241 ) ;
}
