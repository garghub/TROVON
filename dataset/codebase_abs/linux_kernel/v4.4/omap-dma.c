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
static void F_38 ( unsigned long V_89 )
{
struct V_1 * V_3 = (struct V_1 * ) V_89 ;
F_39 ( V_93 ) ;
F_40 ( & V_3 -> V_91 ) ;
F_41 ( & V_3 -> V_94 , & V_93 ) ;
F_42 ( & V_3 -> V_91 ) ;
while ( ! F_43 ( & V_93 ) ) {
struct V_5 * V_7 = F_44 ( & V_93 ,
struct V_5 , V_79 ) ;
F_40 ( & V_7 -> V_8 . V_91 ) ;
F_45 ( & V_7 -> V_79 ) ;
F_30 ( V_7 ) ;
F_42 ( & V_7 -> V_8 . V_91 ) ;
}
}
static T_4 F_46 ( int V_95 , void * V_96 )
{
struct V_1 * V_21 = V_96 ;
unsigned V_88 , V_97 ;
F_47 ( & V_21 -> V_98 ) ;
V_88 = F_15 ( V_21 , V_99 ) ;
V_88 &= V_21 -> V_100 ;
if ( V_88 == 0 ) {
F_48 ( & V_21 -> V_98 ) ;
return V_101 ;
}
while ( ( V_97 = F_49 ( V_88 ) ) != 0 ) {
unsigned V_102 , V_103 ;
struct V_5 * V_7 ;
V_97 -= 1 ;
V_102 = F_50 ( V_97 ) ;
V_88 &= ~ V_102 ;
V_7 = V_21 -> V_34 [ V_97 ] ;
if ( V_7 == NULL ) {
F_27 ( V_21 -> V_4 . V_54 , L_2 , V_97 ) ;
continue;
}
V_103 = F_20 ( V_7 ) ;
F_14 ( V_21 , V_99 , V_102 ) ;
F_33 ( V_97 , V_103 , V_7 ) ;
}
F_48 ( & V_21 -> V_98 ) ;
return V_104 ;
}
static int F_51 ( struct V_6 * V_9 )
{
struct V_1 * V_21 = F_1 ( V_9 -> V_35 ) ;
struct V_5 * V_7 = F_3 ( V_9 ) ;
int V_105 ;
if ( V_21 -> V_106 ) {
V_105 = F_52 ( V_7 -> V_107 , L_3 ,
F_33 , V_7 , & V_7 -> V_55 ) ;
} else {
V_105 = F_52 ( V_7 -> V_107 , L_3 , NULL , NULL ,
& V_7 -> V_55 ) ;
}
F_53 ( V_21 -> V_4 . V_54 , L_4 ,
V_7 -> V_55 , V_7 -> V_107 ) ;
if ( V_105 >= 0 ) {
F_21 ( V_21 , V_7 , V_7 -> V_55 ) ;
if ( ! V_21 -> V_106 ) {
unsigned V_16 ;
F_40 ( & V_21 -> V_98 ) ;
V_16 = F_50 ( V_7 -> V_55 ) ;
F_14 ( V_21 , V_99 , V_16 ) ;
V_21 -> V_100 |= V_16 ;
F_14 ( V_21 , V_108 , V_21 -> V_100 ) ;
V_16 = F_15 ( V_21 , V_109 ) ;
V_16 &= ~ F_50 ( V_7 -> V_55 ) ;
F_14 ( V_21 , V_109 , V_16 ) ;
F_42 ( & V_21 -> V_98 ) ;
}
}
if ( F_19 () ) {
if ( F_54 ( V_21 -> V_32 -> V_36 ) ) {
V_7 -> V_42 = V_110 ;
V_7 -> V_42 |= V_7 -> V_55 + 1 ;
} else {
V_7 -> V_42 = V_7 -> V_107 & 0x1f ;
}
} else {
V_7 -> V_42 = V_7 -> V_107 & 0x1f ;
V_7 -> V_42 |= ( V_7 -> V_107 & ~ 0x1f ) << 14 ;
}
if ( V_21 -> V_32 -> V_44 & V_111 )
V_7 -> V_42 |= V_112 ;
return V_105 ;
}
static void F_55 ( struct V_6 * V_9 )
{
struct V_1 * V_21 = F_1 ( V_9 -> V_35 ) ;
struct V_5 * V_7 = F_3 ( V_9 ) ;
if ( ! V_21 -> V_106 ) {
F_40 ( & V_21 -> V_98 ) ;
V_21 -> V_100 &= ~ F_50 ( V_7 -> V_55 ) ;
F_14 ( V_21 , V_108 , V_21 -> V_100 ) ;
F_42 ( & V_21 -> V_98 ) ;
}
V_7 -> V_29 = NULL ;
V_21 -> V_34 [ V_7 -> V_55 ] = NULL ;
F_56 ( & V_7 -> V_8 ) ;
F_57 ( V_7 -> V_55 ) ;
F_53 ( V_21 -> V_4 . V_54 , L_5 , V_7 -> V_107 ) ;
V_7 -> V_107 = 0 ;
}
static T_5 F_58 ( struct V_60 * V_61 )
{
return V_61 -> V_75 * V_61 -> V_77 ;
}
static T_5 F_59 ( struct V_10 * V_3 )
{
unsigned V_48 ;
T_5 V_113 ;
for ( V_113 = V_48 = 0 ; V_48 < V_3 -> V_92 ; V_48 ++ )
V_113 += F_58 ( & V_3 -> V_61 [ V_48 ] ) ;
return V_113 * V_114 [ V_3 -> V_115 ] ;
}
static T_5 F_60 ( struct V_10 * V_3 , T_6 V_17 )
{
unsigned V_48 ;
T_5 V_113 , V_116 = V_114 [ V_3 -> V_115 ] ;
for ( V_113 = V_48 = 0 ; V_48 < V_3 -> V_92 ; V_48 ++ ) {
T_5 V_117 = F_58 ( & V_3 -> V_61 [ V_48 ] ) * V_116 ;
if ( V_113 )
V_113 += V_117 ;
else if ( V_17 >= V_3 -> V_61 [ V_48 ] . V_17 &&
V_17 < V_3 -> V_61 [ V_48 ] . V_17 + V_117 )
V_113 += V_3 -> V_61 [ V_48 ] . V_17 + V_117 - V_17 ;
}
return V_113 ;
}
static T_1 F_61 ( struct V_5 * V_7 , unsigned V_22 )
{
struct V_1 * V_21 = F_1 ( V_7 -> V_8 . V_9 . V_35 ) ;
T_1 V_16 ;
V_16 = F_17 ( V_7 , V_22 ) ;
if ( V_16 == 0 && V_21 -> V_32 -> V_44 & V_118 )
V_16 = F_17 ( V_7 , V_22 ) ;
return V_16 ;
}
static T_6 F_62 ( struct V_5 * V_7 )
{
struct V_1 * V_21 = F_1 ( V_7 -> V_8 . V_9 . V_35 ) ;
T_6 V_17 , V_119 ;
if ( F_23 ( V_21 -> V_32 -> V_36 ) ) {
V_17 = F_17 ( V_7 , V_37 ) ;
} else {
V_17 = F_61 ( V_7 , V_120 ) ;
V_119 = F_61 ( V_7 , V_38 ) ;
if ( V_119 == 0 )
V_17 = F_17 ( V_7 , V_71 ) ;
}
if ( F_19 () )
V_17 |= F_17 ( V_7 , V_71 ) & 0xffff0000 ;
return V_17 ;
}
static T_6 F_63 ( struct V_5 * V_7 )
{
struct V_1 * V_21 = F_1 ( V_7 -> V_8 . V_9 . V_35 ) ;
T_6 V_17 ;
if ( F_23 ( V_21 -> V_32 -> V_36 ) ) {
V_17 = F_17 ( V_7 , V_37 ) ;
} else {
V_17 = F_61 ( V_7 , V_38 ) ;
if ( V_17 == 0 )
V_17 = F_17 ( V_7 , V_68 ) ;
}
if ( F_19 () )
V_17 |= F_17 ( V_7 , V_68 ) & 0xffff0000 ;
return V_17 ;
}
static enum V_121 F_64 ( struct V_6 * V_9 ,
T_7 V_122 , struct V_123 * V_124 )
{
struct V_5 * V_7 = F_3 ( V_9 ) ;
struct V_15 * V_13 ;
enum V_121 V_105 ;
unsigned long V_90 ;
V_105 = F_65 ( V_9 , V_122 , V_124 ) ;
if ( V_105 == V_125 || ! V_124 )
return V_105 ;
F_34 ( & V_7 -> V_8 . V_91 , V_90 ) ;
V_13 = F_66 ( & V_7 -> V_8 , V_122 ) ;
if ( V_13 ) {
V_124 -> V_126 = F_59 ( F_4 ( & V_13 -> V_14 ) ) ;
} else if ( V_7 -> V_78 && V_7 -> V_78 -> V_13 . V_14 . V_122 == V_122 ) {
struct V_10 * V_3 = V_7 -> V_78 ;
T_6 V_127 ;
if ( V_3 -> V_65 == V_128 )
V_127 = F_62 ( V_7 ) ;
else if ( V_3 -> V_65 == V_66 )
V_127 = F_63 ( V_7 ) ;
else
V_127 = 0 ;
V_124 -> V_126 = F_60 ( V_3 , V_127 ) ;
} else {
V_124 -> V_126 = 0 ;
}
F_37 ( & V_7 -> V_8 . V_91 , V_90 ) ;
return V_105 ;
}
static void F_67 ( struct V_6 * V_9 )
{
struct V_5 * V_7 = F_3 ( V_9 ) ;
unsigned long V_90 ;
F_34 ( & V_7 -> V_8 . V_91 , V_90 ) ;
if ( F_68 ( & V_7 -> V_8 ) && ! V_7 -> V_78 ) {
if ( ! V_7 -> V_56 ) {
struct V_1 * V_3 = F_1 ( V_9 -> V_35 ) ;
F_47 ( & V_3 -> V_91 ) ;
if ( F_43 ( & V_7 -> V_79 ) )
F_69 ( & V_7 -> V_79 , & V_3 -> V_94 ) ;
F_48 ( & V_3 -> V_91 ) ;
F_70 ( & V_3 -> V_129 ) ;
} else {
F_30 ( V_7 ) ;
}
}
F_37 ( & V_7 -> V_8 . V_91 , V_90 ) ;
}
static struct V_11 * F_71 (
struct V_6 * V_9 , struct V_130 * V_131 , unsigned V_92 ,
enum V_132 V_65 , unsigned long V_133 , void * V_134 )
{
struct V_1 * V_21 = F_1 ( V_9 -> V_35 ) ;
struct V_5 * V_7 = F_3 ( V_9 ) ;
enum V_135 V_136 ;
struct V_130 * V_137 ;
struct V_10 * V_3 ;
T_6 V_82 ;
unsigned V_48 , V_138 = 0 , V_115 , V_75 , V_139 ;
T_8 V_140 ;
if ( V_65 == V_66 ) {
V_82 = V_7 -> V_141 . V_142 ;
V_136 = V_7 -> V_141 . V_143 ;
V_140 = V_7 -> V_141 . V_144 ;
} else if ( V_65 == V_128 ) {
V_82 = V_7 -> V_141 . V_145 ;
V_136 = V_7 -> V_141 . V_146 ;
V_140 = V_7 -> V_141 . V_147 ;
} else {
F_27 ( V_9 -> V_35 -> V_54 , L_6 , V_148 ) ;
return NULL ;
}
switch ( V_136 ) {
case V_149 :
V_115 = V_150 ;
break;
case V_151 :
V_115 = V_152 ;
break;
case V_153 :
V_115 = V_154 ;
break;
default:
return NULL ;
}
V_3 = F_72 ( sizeof( * V_3 ) + V_92 * sizeof( V_3 -> V_61 [ 0 ] ) , V_155 ) ;
if ( ! V_3 )
return NULL ;
V_3 -> V_65 = V_65 ;
V_3 -> V_82 = V_82 ;
V_3 -> V_115 = V_115 ;
V_3 -> V_42 = V_7 -> V_42 | V_156 ;
if ( V_65 == V_66 )
V_3 -> V_42 |= V_157 | V_158 ;
else
V_3 -> V_42 |= V_159 | V_160 ;
V_3 -> V_40 = V_161 | V_162 ;
V_3 -> V_85 = V_115 ;
if ( F_19 () ) {
V_3 -> V_40 |= V_163 ;
if ( V_65 == V_66 )
V_3 -> V_85 |= V_164 | V_165 ;
else
V_3 -> V_85 |= V_166 | V_167 ;
} else {
if ( V_65 == V_66 )
V_3 -> V_42 |= V_46 ;
V_3 -> V_40 |= V_168 | V_169 ;
}
if ( V_21 -> V_32 -> V_44 & V_170 )
V_3 -> V_86 = V_7 -> V_55 ;
V_75 = V_140 ;
V_139 = V_114 [ V_115 ] * V_75 ;
F_73 (sgl, sgent, sglen, i) {
V_3 -> V_61 [ V_138 ] . V_17 = F_74 ( V_137 ) ;
V_3 -> V_61 [ V_138 ] . V_75 = V_75 ;
V_3 -> V_61 [ V_138 ] . V_77 = F_75 ( V_137 ) / V_139 ;
V_138 ++ ;
}
V_3 -> V_92 = V_138 ;
return F_76 ( & V_7 -> V_8 , & V_3 -> V_13 , V_133 ) ;
}
static struct V_11 * F_77 (
struct V_6 * V_9 , T_6 V_171 , T_5 V_172 ,
T_5 V_173 , enum V_132 V_65 , unsigned long V_90 )
{
struct V_1 * V_21 = F_1 ( V_9 -> V_35 ) ;
struct V_5 * V_7 = F_3 ( V_9 ) ;
enum V_135 V_136 ;
struct V_10 * V_3 ;
T_6 V_82 ;
unsigned V_115 ;
T_8 V_140 ;
if ( V_65 == V_66 ) {
V_82 = V_7 -> V_141 . V_142 ;
V_136 = V_7 -> V_141 . V_143 ;
V_140 = V_7 -> V_141 . V_144 ;
} else if ( V_65 == V_128 ) {
V_82 = V_7 -> V_141 . V_145 ;
V_136 = V_7 -> V_141 . V_146 ;
V_140 = V_7 -> V_141 . V_147 ;
} else {
F_27 ( V_9 -> V_35 -> V_54 , L_6 , V_148 ) ;
return NULL ;
}
switch ( V_136 ) {
case V_149 :
V_115 = V_150 ;
break;
case V_151 :
V_115 = V_152 ;
break;
case V_153 :
V_115 = V_154 ;
break;
default:
return NULL ;
}
V_3 = F_72 ( sizeof( * V_3 ) + sizeof( V_3 -> V_61 [ 0 ] ) , V_155 ) ;
if ( ! V_3 )
return NULL ;
V_3 -> V_65 = V_65 ;
V_3 -> V_82 = V_82 ;
V_3 -> V_83 = V_140 ;
V_3 -> V_115 = V_115 ;
V_3 -> V_61 [ 0 ] . V_17 = V_171 ;
V_3 -> V_61 [ 0 ] . V_75 = V_173 / V_114 [ V_115 ] ;
V_3 -> V_61 [ 0 ] . V_77 = V_172 / V_173 ;
V_3 -> V_92 = 1 ;
V_3 -> V_42 = V_7 -> V_42 ;
if ( V_65 == V_66 )
V_3 -> V_42 |= V_157 | V_158 ;
else
V_3 -> V_42 |= V_159 | V_160 ;
V_3 -> V_40 = V_161 ;
if ( V_90 & V_174 )
V_3 -> V_40 |= V_175 ;
V_3 -> V_85 = V_115 ;
if ( F_19 () ) {
V_3 -> V_40 |= V_163 ;
if ( V_65 == V_66 )
V_3 -> V_85 |= V_164 | V_176 ;
else
V_3 -> V_85 |= V_177 | V_167 ;
} else {
if ( V_140 )
V_3 -> V_42 |= V_178 ;
else
V_3 -> V_42 |= V_179 ;
if ( V_65 == V_66 ) {
V_3 -> V_42 |= V_46 ;
V_3 -> V_85 |= V_180 ;
} else {
V_3 -> V_85 |= V_181 ;
}
V_3 -> V_40 |= V_168 | V_169 ;
V_3 -> V_85 |= V_182 | V_183 ;
}
if ( F_23 ( V_21 -> V_32 -> V_36 ) )
V_3 -> V_42 |= V_184 | V_185 ;
else
V_3 -> V_86 = V_7 -> V_55 | V_58 ;
V_7 -> V_56 = true ;
return F_76 ( & V_7 -> V_8 , & V_3 -> V_13 , V_90 ) ;
}
static struct V_11 * F_78 (
struct V_6 * V_9 , T_6 V_186 , T_6 V_187 ,
T_5 V_188 , unsigned long V_133 )
{
struct V_5 * V_7 = F_3 ( V_9 ) ;
struct V_10 * V_3 ;
T_9 V_189 ;
V_3 = F_72 ( sizeof( * V_3 ) + sizeof( V_3 -> V_61 [ 0 ] ) , V_155 ) ;
if ( ! V_3 )
return NULL ;
V_189 = F_79 ( ( V_187 | V_186 | V_188 ) ) ;
if ( V_189 > V_154 )
V_189 = V_154 ;
V_3 -> V_65 = V_67 ;
V_3 -> V_82 = V_187 ;
V_3 -> V_83 = 0 ;
V_3 -> V_115 = V_189 ;
V_3 -> V_61 [ 0 ] . V_75 = V_188 / F_50 ( V_189 ) ;
V_3 -> V_61 [ 0 ] . V_77 = 1 ;
V_3 -> V_61 [ 0 ] . V_17 = V_186 ;
V_3 -> V_92 = 1 ;
V_3 -> V_42 = V_7 -> V_42 ;
V_3 -> V_42 |= V_157 | V_160 ;
V_3 -> V_40 = V_161 ;
if ( V_133 & V_174 )
V_3 -> V_40 |= V_175 ;
V_3 -> V_85 = V_189 ;
if ( F_19 () ) {
V_3 -> V_40 |= V_163 ;
V_3 -> V_85 |= V_164 | V_167 ;
} else {
V_3 -> V_85 |= V_180 | V_181 ;
V_3 -> V_40 |= V_168 | V_169 ;
V_3 -> V_85 |= V_182 | V_183 ;
}
return F_76 ( & V_7 -> V_8 , & V_3 -> V_13 , V_133 ) ;
}
static int F_80 ( struct V_6 * V_9 , struct V_190 * V_141 )
{
struct V_5 * V_7 = F_3 ( V_9 ) ;
if ( V_141 -> V_143 == V_191 ||
V_141 -> V_146 == V_191 )
return - V_192 ;
memcpy ( & V_7 -> V_141 , V_141 , sizeof( V_7 -> V_141 ) ) ;
return 0 ;
}
static int F_81 ( struct V_6 * V_9 )
{
struct V_5 * V_7 = F_3 ( V_9 ) ;
struct V_1 * V_3 = F_1 ( V_7 -> V_8 . V_9 . V_35 ) ;
unsigned long V_90 ;
F_39 ( V_93 ) ;
F_34 ( & V_7 -> V_8 . V_91 , V_90 ) ;
F_47 ( & V_3 -> V_91 ) ;
F_45 ( & V_7 -> V_79 ) ;
F_48 ( & V_3 -> V_91 ) ;
if ( V_7 -> V_78 ) {
F_5 ( & V_7 -> V_78 -> V_13 ) ;
V_7 -> V_78 = NULL ;
if ( ! V_7 -> V_193 )
F_24 ( V_7 ) ;
}
if ( V_7 -> V_56 ) {
V_7 -> V_56 = false ;
V_7 -> V_193 = false ;
}
F_82 ( & V_7 -> V_8 , & V_93 ) ;
F_37 ( & V_7 -> V_8 . V_91 , V_90 ) ;
F_83 ( & V_7 -> V_8 , & V_93 ) ;
return 0 ;
}
static int F_84 ( struct V_6 * V_9 )
{
struct V_5 * V_7 = F_3 ( V_9 ) ;
if ( ! V_7 -> V_56 )
return - V_192 ;
if ( ! V_7 -> V_193 ) {
F_24 ( V_7 ) ;
V_7 -> V_193 = true ;
}
return 0 ;
}
static int F_85 ( struct V_6 * V_9 )
{
struct V_5 * V_7 = F_3 ( V_9 ) ;
if ( ! V_7 -> V_56 )
return - V_192 ;
if ( V_7 -> V_193 ) {
F_28 () ;
F_16 ( V_7 , V_57 , V_7 -> V_78 -> V_86 ) ;
F_22 ( V_7 , V_7 -> V_78 ) ;
V_7 -> V_193 = false ;
}
return 0 ;
}
static int F_86 ( struct V_1 * V_21 )
{
struct V_5 * V_7 ;
V_7 = F_72 ( sizeof( * V_7 ) , V_194 ) ;
if ( ! V_7 )
return - V_195 ;
V_7 -> V_25 = V_21 -> V_25 ;
V_7 -> V_8 . V_196 = F_5 ;
F_87 ( & V_7 -> V_8 , & V_21 -> V_4 ) ;
F_88 ( & V_7 -> V_79 ) ;
return 0 ;
}
static void F_89 ( struct V_1 * V_21 )
{
F_90 ( & V_21 -> V_129 ) ;
while ( ! F_43 ( & V_21 -> V_4 . V_197 ) ) {
struct V_5 * V_7 = F_44 ( & V_21 -> V_4 . V_197 ,
struct V_5 , V_8 . V_9 . V_198 ) ;
F_32 ( & V_7 -> V_8 . V_9 . V_198 ) ;
F_90 ( & V_7 -> V_8 . V_129 ) ;
F_6 ( V_7 ) ;
}
}
static int F_91 ( struct V_199 * V_200 )
{
struct V_1 * V_21 ;
struct V_201 * V_202 ;
int V_203 , V_48 , V_95 ;
V_21 = F_92 ( & V_200 -> V_54 , sizeof( * V_21 ) , V_194 ) ;
if ( ! V_21 )
return - V_195 ;
V_202 = F_93 ( V_200 , V_204 , 0 ) ;
V_21 -> V_27 = F_94 ( & V_200 -> V_54 , V_202 ) ;
if ( F_95 ( V_21 -> V_27 ) )
return F_96 ( V_21 -> V_27 ) ;
V_21 -> V_32 = F_97 () ;
if ( ! V_21 -> V_32 )
return - V_205 ;
V_21 -> V_25 = V_21 -> V_32 -> V_25 ;
F_98 ( V_206 , V_21 -> V_4 . V_207 ) ;
F_98 ( V_208 , V_21 -> V_4 . V_207 ) ;
F_98 ( V_209 , V_21 -> V_4 . V_207 ) ;
V_21 -> V_4 . V_210 = F_51 ;
V_21 -> V_4 . V_211 = F_55 ;
V_21 -> V_4 . V_212 = F_64 ;
V_21 -> V_4 . V_213 = F_67 ;
V_21 -> V_4 . V_214 = F_71 ;
V_21 -> V_4 . V_215 = F_77 ;
V_21 -> V_4 . V_216 = F_78 ;
V_21 -> V_4 . V_217 = F_80 ;
V_21 -> V_4 . V_218 = F_84 ;
V_21 -> V_4 . V_219 = F_85 ;
V_21 -> V_4 . V_220 = F_81 ;
V_21 -> V_4 . V_221 = V_222 ;
V_21 -> V_4 . V_223 = V_222 ;
V_21 -> V_4 . V_224 = F_50 ( V_66 ) | F_50 ( V_128 ) ;
V_21 -> V_4 . V_225 = V_226 ;
V_21 -> V_4 . V_54 = & V_200 -> V_54 ;
F_88 ( & V_21 -> V_4 . V_197 ) ;
F_88 ( & V_21 -> V_94 ) ;
F_99 ( & V_21 -> V_91 ) ;
F_99 ( & V_21 -> V_98 ) ;
F_100 ( & V_21 -> V_129 , F_38 , ( unsigned long ) V_21 ) ;
V_21 -> V_227 = V_228 ;
if ( V_200 -> V_54 . V_229 && F_101 ( V_200 -> V_54 . V_229 ,
L_7 ,
& V_21 -> V_227 ) ) {
F_102 ( & V_200 -> V_54 ,
L_8 ,
V_228 ) ;
}
for ( V_48 = 0 ; V_48 < V_230 ; V_48 ++ ) {
V_203 = F_86 ( V_21 ) ;
if ( V_203 ) {
F_89 ( V_21 ) ;
return V_203 ;
}
}
V_95 = F_103 ( V_200 , 1 ) ;
if ( V_95 <= 0 ) {
F_102 ( & V_200 -> V_54 , L_9 , V_95 ) ;
V_21 -> V_106 = true ;
} else {
V_21 -> V_100 = 0 ;
F_14 ( V_21 , V_108 , 0 ) ;
V_203 = F_104 ( & V_200 -> V_54 , V_95 , F_46 ,
V_231 , L_10 , V_21 ) ;
if ( V_203 )
return V_203 ;
}
V_203 = F_105 ( & V_21 -> V_4 ) ;
if ( V_203 ) {
F_106 ( L_11 ,
V_203 ) ;
F_89 ( V_21 ) ;
return V_203 ;
}
F_107 ( V_200 , V_21 ) ;
if ( V_200 -> V_54 . V_229 ) {
V_232 . V_233 = V_21 -> V_4 . V_207 ;
V_203 = F_108 ( V_200 -> V_54 . V_229 ,
V_234 , & V_232 ) ;
if ( V_203 ) {
F_106 ( L_12 ) ;
F_109 ( & V_21 -> V_4 ) ;
F_89 ( V_21 ) ;
}
}
F_102 ( & V_200 -> V_54 , L_13 ) ;
return V_203 ;
}
static int F_110 ( struct V_199 * V_200 )
{
struct V_1 * V_21 = F_111 ( V_200 ) ;
if ( V_200 -> V_54 . V_229 )
F_112 ( V_200 -> V_54 . V_229 ) ;
F_109 ( & V_21 -> V_4 ) ;
if ( ! V_21 -> V_106 ) {
F_14 ( V_21 , V_109 , 0 ) ;
}
F_89 ( V_21 ) ;
return 0 ;
}
bool F_113 ( struct V_6 * V_9 , void * V_235 )
{
if ( V_9 -> V_35 -> V_54 -> V_236 == & V_237 . V_236 ) {
struct V_1 * V_21 = F_1 ( V_9 -> V_35 ) ;
struct V_5 * V_7 = F_3 ( V_9 ) ;
unsigned V_238 = * ( unsigned * ) V_235 ;
if ( V_238 <= V_21 -> V_227 ) {
V_7 -> V_107 = V_238 ;
return true ;
}
}
return false ;
}
static int F_114 ( void )
{
return F_115 ( & V_237 ) ;
}
static void T_10 F_116 ( void )
{
F_117 ( & V_237 ) ;
}
