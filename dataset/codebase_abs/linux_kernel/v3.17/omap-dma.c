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
if ( V_3 -> V_65 == V_66 ) {
V_62 = V_67 ;
V_63 = V_68 ;
V_64 = V_69 ;
} else {
V_62 = V_70 ;
V_63 = V_71 ;
V_64 = V_72 ;
}
F_16 ( V_7 , V_62 , V_61 -> V_17 ) ;
F_16 ( V_7 , V_63 , 0 ) ;
F_16 ( V_7 , V_64 , 0 ) ;
F_16 ( V_7 , V_73 , V_61 -> V_74 ) ;
F_16 ( V_7 , V_75 , V_61 -> V_76 ) ;
F_22 ( V_7 , V_3 ) ;
}
static void F_30 ( struct V_5 * V_7 )
{
struct V_15 * V_13 = F_31 ( & V_7 -> V_8 ) ;
struct V_10 * V_3 ;
unsigned V_62 , V_63 , V_64 ;
if ( ! V_13 ) {
V_7 -> V_77 = NULL ;
return;
}
F_32 ( & V_13 -> V_78 ) ;
V_7 -> V_77 = V_3 = F_4 ( & V_13 -> V_14 ) ;
V_7 -> V_79 = 0 ;
F_28 () ;
F_16 ( V_7 , V_41 , V_3 -> V_42 ) ;
if ( F_19 () )
F_16 ( V_7 , V_80 , V_3 -> V_42 >> 16 ) ;
if ( V_3 -> V_65 == V_66 ) {
V_62 = V_70 ;
V_63 = V_71 ;
V_64 = V_72 ;
} else {
V_62 = V_67 ;
V_63 = V_68 ;
V_64 = V_69 ;
}
F_16 ( V_7 , V_62 , V_3 -> V_81 ) ;
F_16 ( V_7 , V_63 , 0 ) ;
F_16 ( V_7 , V_64 , V_3 -> V_82 ) ;
F_16 ( V_7 , V_83 , V_3 -> V_84 ) ;
F_16 ( V_7 , V_57 , V_3 -> V_85 ) ;
F_29 ( V_7 , V_3 , 0 ) ;
}
static void F_33 ( int V_86 , T_3 V_87 , void * V_88 )
{
struct V_5 * V_7 = V_88 ;
struct V_10 * V_3 ;
unsigned long V_89 ;
F_34 ( & V_7 -> V_8 . V_90 , V_89 ) ;
V_3 = V_7 -> V_77 ;
if ( V_3 ) {
if ( ! V_7 -> V_56 ) {
if ( ++ V_7 -> V_79 < V_3 -> V_91 ) {
F_29 ( V_7 , V_3 , V_7 -> V_79 ) ;
} else {
F_30 ( V_7 ) ;
F_35 ( & V_3 -> V_13 ) ;
}
} else {
F_36 ( & V_3 -> V_13 ) ;
}
}
F_37 ( & V_7 -> V_8 . V_90 , V_89 ) ;
}
static void F_38 ( unsigned long V_88 )
{
struct V_1 * V_3 = (struct V_1 * ) V_88 ;
F_39 ( V_92 ) ;
F_40 ( & V_3 -> V_90 ) ;
F_41 ( & V_3 -> V_93 , & V_92 ) ;
F_42 ( & V_3 -> V_90 ) ;
while ( ! F_43 ( & V_92 ) ) {
struct V_5 * V_7 = F_44 ( & V_92 ,
struct V_5 , V_78 ) ;
F_40 ( & V_7 -> V_8 . V_90 ) ;
F_45 ( & V_7 -> V_78 ) ;
F_30 ( V_7 ) ;
F_42 ( & V_7 -> V_8 . V_90 ) ;
}
}
static T_4 F_46 ( int V_94 , void * V_95 )
{
struct V_1 * V_21 = V_95 ;
unsigned V_87 , V_96 ;
F_47 ( & V_21 -> V_97 ) ;
V_87 = F_15 ( V_21 , V_98 ) ;
V_87 &= V_21 -> V_99 ;
if ( V_87 == 0 ) {
F_48 ( & V_21 -> V_97 ) ;
return V_100 ;
}
while ( ( V_96 = F_49 ( V_87 ) ) != 0 ) {
unsigned V_101 , V_102 ;
struct V_5 * V_7 ;
V_96 -= 1 ;
V_101 = F_50 ( V_96 ) ;
V_87 &= ~ V_101 ;
V_7 = V_21 -> V_34 [ V_96 ] ;
if ( V_7 == NULL ) {
F_27 ( V_21 -> V_4 . V_54 , L_2 , V_96 ) ;
continue;
}
V_102 = F_20 ( V_7 ) ;
F_14 ( V_21 , V_98 , V_101 ) ;
F_33 ( V_96 , V_102 , V_7 ) ;
}
F_48 ( & V_21 -> V_97 ) ;
return V_103 ;
}
static int F_51 ( struct V_6 * V_9 )
{
struct V_1 * V_21 = F_1 ( V_9 -> V_35 ) ;
struct V_5 * V_7 = F_3 ( V_9 ) ;
int V_104 ;
if ( V_21 -> V_105 ) {
V_104 = F_52 ( V_7 -> V_106 , L_3 ,
F_33 , V_7 , & V_7 -> V_55 ) ;
} else {
V_104 = F_52 ( V_7 -> V_106 , L_3 , NULL , NULL ,
& V_7 -> V_55 ) ;
}
F_53 ( V_21 -> V_4 . V_54 , L_4 ,
V_7 -> V_55 , V_7 -> V_106 ) ;
if ( V_104 >= 0 ) {
F_21 ( V_21 , V_7 , V_7 -> V_55 ) ;
if ( ! V_21 -> V_105 ) {
unsigned V_16 ;
F_40 ( & V_21 -> V_97 ) ;
V_16 = F_50 ( V_7 -> V_55 ) ;
F_14 ( V_21 , V_98 , V_16 ) ;
V_21 -> V_99 |= V_16 ;
F_14 ( V_21 , V_107 , V_21 -> V_99 ) ;
V_16 = F_15 ( V_21 , V_108 ) ;
V_16 &= ~ F_50 ( V_7 -> V_55 ) ;
F_14 ( V_21 , V_108 , V_16 ) ;
F_42 ( & V_21 -> V_97 ) ;
}
}
if ( F_19 () ) {
if ( F_54 ( V_21 -> V_32 -> V_36 ) ) {
V_7 -> V_42 = V_109 ;
V_7 -> V_42 |= V_7 -> V_55 + 1 ;
} else {
V_7 -> V_42 = V_7 -> V_106 & 0x1f ;
}
} else {
V_7 -> V_42 = V_7 -> V_106 & 0x1f ;
V_7 -> V_42 |= ( V_7 -> V_106 & ~ 0x1f ) << 14 ;
}
if ( V_21 -> V_32 -> V_44 & V_110 )
V_7 -> V_42 |= V_111 ;
return V_104 ;
}
static void F_55 ( struct V_6 * V_9 )
{
struct V_1 * V_21 = F_1 ( V_9 -> V_35 ) ;
struct V_5 * V_7 = F_3 ( V_9 ) ;
if ( ! V_21 -> V_105 ) {
F_40 ( & V_21 -> V_97 ) ;
V_21 -> V_99 &= ~ F_50 ( V_7 -> V_55 ) ;
F_14 ( V_21 , V_107 , V_21 -> V_99 ) ;
F_42 ( & V_21 -> V_97 ) ;
}
V_7 -> V_29 = NULL ;
V_21 -> V_34 [ V_7 -> V_55 ] = NULL ;
F_56 ( & V_7 -> V_8 ) ;
F_57 ( V_7 -> V_55 ) ;
F_53 ( V_21 -> V_4 . V_54 , L_5 , V_7 -> V_106 ) ;
}
static T_5 F_58 ( struct V_60 * V_61 )
{
return V_61 -> V_74 * V_61 -> V_76 ;
}
static T_5 F_59 ( struct V_10 * V_3 )
{
unsigned V_48 ;
T_5 V_112 ;
for ( V_112 = V_48 = 0 ; V_48 < V_3 -> V_91 ; V_48 ++ )
V_112 += F_58 ( & V_3 -> V_61 [ V_48 ] ) ;
return V_112 * V_113 [ V_3 -> V_114 ] ;
}
static T_5 F_60 ( struct V_10 * V_3 , T_6 V_17 )
{
unsigned V_48 ;
T_5 V_112 , V_115 = V_113 [ V_3 -> V_114 ] ;
for ( V_112 = V_48 = 0 ; V_48 < V_3 -> V_91 ; V_48 ++ ) {
T_5 V_116 = F_58 ( & V_3 -> V_61 [ V_48 ] ) * V_115 ;
if ( V_112 )
V_112 += V_116 ;
else if ( V_17 >= V_3 -> V_61 [ V_48 ] . V_17 &&
V_17 < V_3 -> V_61 [ V_48 ] . V_17 + V_116 )
V_112 += V_3 -> V_61 [ V_48 ] . V_17 + V_116 - V_17 ;
}
return V_112 ;
}
static T_1 F_61 ( struct V_5 * V_7 , unsigned V_22 )
{
struct V_1 * V_21 = F_1 ( V_7 -> V_8 . V_9 . V_35 ) ;
T_1 V_16 ;
V_16 = F_17 ( V_7 , V_22 ) ;
if ( V_16 == 0 && V_21 -> V_32 -> V_44 & V_117 )
V_16 = F_17 ( V_7 , V_22 ) ;
return V_16 ;
}
static T_6 F_62 ( struct V_5 * V_7 )
{
struct V_1 * V_21 = F_1 ( V_7 -> V_8 . V_9 . V_35 ) ;
T_6 V_17 , V_118 ;
if ( F_23 ( V_21 -> V_32 -> V_36 ) ) {
V_17 = F_17 ( V_7 , V_37 ) ;
} else {
V_17 = F_61 ( V_7 , V_119 ) ;
V_118 = F_61 ( V_7 , V_38 ) ;
if ( V_118 == 0 )
V_17 = F_17 ( V_7 , V_70 ) ;
}
if ( F_19 () )
V_17 |= F_17 ( V_7 , V_70 ) & 0xffff0000 ;
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
V_17 = F_17 ( V_7 , V_67 ) ;
}
if ( F_19 () )
V_17 |= F_17 ( V_7 , V_67 ) & 0xffff0000 ;
return V_17 ;
}
static enum V_120 F_64 ( struct V_6 * V_9 ,
T_7 V_121 , struct V_122 * V_123 )
{
struct V_5 * V_7 = F_3 ( V_9 ) ;
struct V_15 * V_13 ;
enum V_120 V_104 ;
unsigned long V_89 ;
V_104 = F_65 ( V_9 , V_121 , V_123 ) ;
if ( V_104 == V_124 || ! V_123 )
return V_104 ;
F_34 ( & V_7 -> V_8 . V_90 , V_89 ) ;
V_13 = F_66 ( & V_7 -> V_8 , V_121 ) ;
if ( V_13 ) {
V_123 -> V_125 = F_59 ( F_4 ( & V_13 -> V_14 ) ) ;
} else if ( V_7 -> V_77 && V_7 -> V_77 -> V_13 . V_14 . V_121 == V_121 ) {
struct V_10 * V_3 = V_7 -> V_77 ;
T_6 V_126 ;
if ( V_3 -> V_65 == V_127 )
V_126 = F_62 ( V_7 ) ;
else if ( V_3 -> V_65 == V_66 )
V_126 = F_63 ( V_7 ) ;
else
V_126 = 0 ;
V_123 -> V_125 = F_60 ( V_3 , V_126 ) ;
} else {
V_123 -> V_125 = 0 ;
}
F_37 ( & V_7 -> V_8 . V_90 , V_89 ) ;
return V_104 ;
}
static void F_67 ( struct V_6 * V_9 )
{
struct V_5 * V_7 = F_3 ( V_9 ) ;
unsigned long V_89 ;
F_34 ( & V_7 -> V_8 . V_90 , V_89 ) ;
if ( F_68 ( & V_7 -> V_8 ) && ! V_7 -> V_77 ) {
if ( ! V_7 -> V_56 ) {
struct V_1 * V_3 = F_1 ( V_9 -> V_35 ) ;
F_47 ( & V_3 -> V_90 ) ;
if ( F_43 ( & V_7 -> V_78 ) )
F_69 ( & V_7 -> V_78 , & V_3 -> V_93 ) ;
F_48 ( & V_3 -> V_90 ) ;
F_70 ( & V_3 -> V_128 ) ;
} else {
F_30 ( V_7 ) ;
}
}
F_37 ( & V_7 -> V_8 . V_90 , V_89 ) ;
}
static struct V_11 * F_71 (
struct V_6 * V_9 , struct V_129 * V_130 , unsigned V_91 ,
enum V_131 V_65 , unsigned long V_132 , void * V_133 )
{
struct V_1 * V_21 = F_1 ( V_9 -> V_35 ) ;
struct V_5 * V_7 = F_3 ( V_9 ) ;
enum V_134 V_135 ;
struct V_129 * V_136 ;
struct V_10 * V_3 ;
T_6 V_81 ;
unsigned V_48 , V_137 = 0 , V_114 , V_74 , V_138 ;
T_8 V_139 ;
if ( V_65 == V_66 ) {
V_81 = V_7 -> V_140 . V_141 ;
V_135 = V_7 -> V_140 . V_142 ;
V_139 = V_7 -> V_140 . V_143 ;
} else if ( V_65 == V_127 ) {
V_81 = V_7 -> V_140 . V_144 ;
V_135 = V_7 -> V_140 . V_145 ;
V_139 = V_7 -> V_140 . V_146 ;
} else {
F_27 ( V_9 -> V_35 -> V_54 , L_6 , V_147 ) ;
return NULL ;
}
switch ( V_135 ) {
case V_148 :
V_114 = V_149 ;
break;
case V_150 :
V_114 = V_151 ;
break;
case V_152 :
V_114 = V_153 ;
break;
default:
return NULL ;
}
V_3 = F_72 ( sizeof( * V_3 ) + V_91 * sizeof( V_3 -> V_61 [ 0 ] ) , V_154 ) ;
if ( ! V_3 )
return NULL ;
V_3 -> V_65 = V_65 ;
V_3 -> V_81 = V_81 ;
V_3 -> V_114 = V_114 ;
V_3 -> V_42 = V_7 -> V_42 | V_155 ;
if ( V_65 == V_66 )
V_3 -> V_42 |= V_156 | V_157 ;
else
V_3 -> V_42 |= V_158 | V_159 ;
V_3 -> V_40 = V_160 | V_161 ;
V_3 -> V_84 = V_114 ;
if ( F_19 () ) {
V_3 -> V_40 |= V_162 ;
if ( V_65 == V_66 )
V_3 -> V_84 |= V_163 | V_164 ;
else
V_3 -> V_84 |= V_165 | V_166 ;
} else {
if ( V_65 == V_66 )
V_3 -> V_42 |= V_46 ;
V_3 -> V_40 |= V_167 | V_168 ;
}
if ( V_21 -> V_32 -> V_44 & V_169 )
V_3 -> V_85 = V_7 -> V_55 ;
V_74 = V_139 ;
V_138 = V_113 [ V_114 ] * V_74 ;
F_73 (sgl, sgent, sglen, i) {
V_3 -> V_61 [ V_137 ] . V_17 = F_74 ( V_136 ) ;
V_3 -> V_61 [ V_137 ] . V_74 = V_74 ;
V_3 -> V_61 [ V_137 ] . V_76 = F_75 ( V_136 ) / V_138 ;
V_137 ++ ;
}
V_3 -> V_91 = V_137 ;
return F_76 ( & V_7 -> V_8 , & V_3 -> V_13 , V_132 ) ;
}
static struct V_11 * F_77 (
struct V_6 * V_9 , T_6 V_170 , T_5 V_171 ,
T_5 V_172 , enum V_131 V_65 , unsigned long V_89 )
{
struct V_1 * V_21 = F_1 ( V_9 -> V_35 ) ;
struct V_5 * V_7 = F_3 ( V_9 ) ;
enum V_134 V_135 ;
struct V_10 * V_3 ;
T_6 V_81 ;
unsigned V_114 ;
T_8 V_139 ;
if ( V_65 == V_66 ) {
V_81 = V_7 -> V_140 . V_141 ;
V_135 = V_7 -> V_140 . V_142 ;
V_139 = V_7 -> V_140 . V_143 ;
} else if ( V_65 == V_127 ) {
V_81 = V_7 -> V_140 . V_144 ;
V_135 = V_7 -> V_140 . V_145 ;
V_139 = V_7 -> V_140 . V_146 ;
} else {
F_27 ( V_9 -> V_35 -> V_54 , L_6 , V_147 ) ;
return NULL ;
}
switch ( V_135 ) {
case V_148 :
V_114 = V_149 ;
break;
case V_150 :
V_114 = V_151 ;
break;
case V_152 :
V_114 = V_153 ;
break;
default:
return NULL ;
}
V_3 = F_72 ( sizeof( * V_3 ) + sizeof( V_3 -> V_61 [ 0 ] ) , V_154 ) ;
if ( ! V_3 )
return NULL ;
V_3 -> V_65 = V_65 ;
V_3 -> V_81 = V_81 ;
V_3 -> V_82 = V_139 ;
V_3 -> V_114 = V_114 ;
V_3 -> V_61 [ 0 ] . V_17 = V_170 ;
V_3 -> V_61 [ 0 ] . V_74 = V_172 / V_113 [ V_114 ] ;
V_3 -> V_61 [ 0 ] . V_76 = V_171 / V_172 ;
V_3 -> V_91 = 1 ;
V_3 -> V_42 = V_7 -> V_42 ;
if ( V_65 == V_66 )
V_3 -> V_42 |= V_156 | V_157 ;
else
V_3 -> V_42 |= V_158 | V_159 ;
V_3 -> V_40 = V_160 ;
if ( V_89 & V_173 )
V_3 -> V_40 |= V_174 ;
V_3 -> V_84 = V_114 ;
if ( F_19 () ) {
V_3 -> V_40 |= V_162 ;
if ( V_65 == V_66 )
V_3 -> V_84 |= V_163 | V_175 ;
else
V_3 -> V_84 |= V_176 | V_166 ;
} else {
if ( V_139 )
V_3 -> V_42 |= V_177 ;
else
V_3 -> V_42 |= V_178 ;
if ( V_65 == V_66 )
V_3 -> V_42 |= V_46 ;
V_3 -> V_40 |= V_167 | V_168 ;
V_3 -> V_84 |= V_179 | V_180 ;
}
if ( F_23 ( V_21 -> V_32 -> V_36 ) )
V_3 -> V_42 |= V_181 | V_182 ;
else
V_3 -> V_85 = V_7 -> V_55 | V_58 ;
V_7 -> V_56 = true ;
return F_76 ( & V_7 -> V_8 , & V_3 -> V_13 , V_89 ) ;
}
static int F_78 ( struct V_5 * V_7 , struct V_183 * V_140 )
{
if ( V_140 -> V_142 == V_184 ||
V_140 -> V_145 == V_184 )
return - V_185 ;
memcpy ( & V_7 -> V_140 , V_140 , sizeof( V_7 -> V_140 ) ) ;
return 0 ;
}
static int F_79 ( struct V_5 * V_7 )
{
struct V_1 * V_3 = F_1 ( V_7 -> V_8 . V_9 . V_35 ) ;
unsigned long V_89 ;
F_39 ( V_92 ) ;
F_34 ( & V_7 -> V_8 . V_90 , V_89 ) ;
F_47 ( & V_3 -> V_90 ) ;
F_45 ( & V_7 -> V_78 ) ;
F_48 ( & V_3 -> V_90 ) ;
if ( V_7 -> V_77 ) {
V_7 -> V_77 = NULL ;
if ( ! V_7 -> V_186 )
F_24 ( V_7 ) ;
}
if ( V_7 -> V_56 ) {
V_7 -> V_56 = false ;
V_7 -> V_186 = false ;
}
F_80 ( & V_7 -> V_8 , & V_92 ) ;
F_37 ( & V_7 -> V_8 . V_90 , V_89 ) ;
F_81 ( & V_7 -> V_8 , & V_92 ) ;
return 0 ;
}
static int F_82 ( struct V_5 * V_7 )
{
if ( ! V_7 -> V_56 )
return - V_185 ;
if ( ! V_7 -> V_186 ) {
F_24 ( V_7 ) ;
V_7 -> V_186 = true ;
}
return 0 ;
}
static int F_83 ( struct V_5 * V_7 )
{
if ( ! V_7 -> V_56 )
return - V_185 ;
if ( V_7 -> V_186 ) {
F_28 () ;
F_16 ( V_7 , V_57 , V_7 -> V_77 -> V_85 ) ;
F_22 ( V_7 , V_7 -> V_77 ) ;
V_7 -> V_186 = false ;
}
return 0 ;
}
static int F_84 ( struct V_6 * V_9 , enum V_187 V_188 ,
unsigned long V_189 )
{
struct V_5 * V_7 = F_3 ( V_9 ) ;
int V_104 ;
switch ( V_188 ) {
case V_190 :
V_104 = F_78 ( V_7 , (struct V_183 * ) V_189 ) ;
break;
case V_191 :
V_104 = F_79 ( V_7 ) ;
break;
case V_192 :
V_104 = F_82 ( V_7 ) ;
break;
case V_193 :
V_104 = F_83 ( V_7 ) ;
break;
default:
V_104 = - V_194 ;
break;
}
return V_104 ;
}
static int F_85 ( struct V_1 * V_21 , int V_106 )
{
struct V_5 * V_7 ;
V_7 = F_72 ( sizeof( * V_7 ) , V_195 ) ;
if ( ! V_7 )
return - V_196 ;
V_7 -> V_25 = V_21 -> V_25 ;
V_7 -> V_106 = V_106 ;
V_7 -> V_8 . V_197 = F_5 ;
F_86 ( & V_7 -> V_8 , & V_21 -> V_4 ) ;
F_87 ( & V_7 -> V_78 ) ;
V_21 -> V_4 . V_198 ++ ;
return 0 ;
}
static void F_88 ( struct V_1 * V_21 )
{
F_89 ( & V_21 -> V_128 ) ;
while ( ! F_43 ( & V_21 -> V_4 . V_199 ) ) {
struct V_5 * V_7 = F_44 ( & V_21 -> V_4 . V_199 ,
struct V_5 , V_8 . V_9 . V_200 ) ;
F_32 ( & V_7 -> V_8 . V_9 . V_200 ) ;
F_89 ( & V_7 -> V_8 . V_128 ) ;
F_6 ( V_7 ) ;
}
}
static int F_90 ( struct V_6 * V_201 ,
struct V_202 * V_203 )
{
V_203 -> V_204 = V_205 ;
V_203 -> V_206 = V_205 ;
V_203 -> V_207 = F_50 ( V_66 ) | F_50 ( V_127 ) ;
V_203 -> V_208 = true ;
V_203 -> V_209 = true ;
V_203 -> V_210 = V_211 ;
return 0 ;
}
static int F_91 ( struct V_212 * V_213 )
{
struct V_1 * V_21 ;
struct V_214 * V_215 ;
int V_216 , V_48 , V_94 ;
V_21 = F_92 ( & V_213 -> V_54 , sizeof( * V_21 ) , V_195 ) ;
if ( ! V_21 )
return - V_196 ;
V_215 = F_93 ( V_213 , V_217 , 0 ) ;
V_21 -> V_27 = F_94 ( & V_213 -> V_54 , V_215 ) ;
if ( F_95 ( V_21 -> V_27 ) )
return F_96 ( V_21 -> V_27 ) ;
V_21 -> V_32 = F_97 () ;
if ( ! V_21 -> V_32 )
return - V_218 ;
V_21 -> V_25 = V_21 -> V_32 -> V_25 ;
F_98 ( V_219 , V_21 -> V_4 . V_220 ) ;
F_98 ( V_221 , V_21 -> V_4 . V_220 ) ;
V_21 -> V_4 . V_222 = F_51 ;
V_21 -> V_4 . V_223 = F_55 ;
V_21 -> V_4 . V_224 = F_64 ;
V_21 -> V_4 . V_225 = F_67 ;
V_21 -> V_4 . V_226 = F_71 ;
V_21 -> V_4 . V_227 = F_77 ;
V_21 -> V_4 . V_228 = F_84 ;
V_21 -> V_4 . V_229 = F_90 ;
V_21 -> V_4 . V_54 = & V_213 -> V_54 ;
F_87 ( & V_21 -> V_4 . V_199 ) ;
F_87 ( & V_21 -> V_93 ) ;
F_99 ( & V_21 -> V_90 ) ;
F_99 ( & V_21 -> V_97 ) ;
F_100 ( & V_21 -> V_128 , F_38 , ( unsigned long ) V_21 ) ;
for ( V_48 = 0 ; V_48 < 127 ; V_48 ++ ) {
V_216 = F_85 ( V_21 , V_48 ) ;
if ( V_216 ) {
F_88 ( V_21 ) ;
return V_216 ;
}
}
V_94 = F_101 ( V_213 , 1 ) ;
if ( V_94 <= 0 ) {
F_102 ( & V_213 -> V_54 , L_7 , V_94 ) ;
V_21 -> V_105 = true ;
} else {
V_21 -> V_99 = 0 ;
F_14 ( V_21 , V_107 , 0 ) ;
V_216 = F_103 ( & V_213 -> V_54 , V_94 , F_46 ,
V_230 , L_8 , V_21 ) ;
if ( V_216 )
return V_216 ;
}
V_216 = F_104 ( & V_21 -> V_4 ) ;
if ( V_216 ) {
F_105 ( L_9 ,
V_216 ) ;
F_88 ( V_21 ) ;
return V_216 ;
}
F_106 ( V_213 , V_21 ) ;
if ( V_213 -> V_54 . V_231 ) {
V_232 . V_233 = V_21 -> V_4 . V_220 ;
V_216 = F_107 ( V_213 -> V_54 . V_231 ,
V_234 , & V_232 ) ;
if ( V_216 ) {
F_105 ( L_10 ) ;
F_108 ( & V_21 -> V_4 ) ;
F_88 ( V_21 ) ;
}
}
F_102 ( & V_213 -> V_54 , L_11 ) ;
return V_216 ;
}
static int F_109 ( struct V_212 * V_213 )
{
struct V_1 * V_21 = F_110 ( V_213 ) ;
if ( V_213 -> V_54 . V_231 )
F_111 ( V_213 -> V_54 . V_231 ) ;
F_108 ( & V_21 -> V_4 ) ;
if ( ! V_21 -> V_105 ) {
F_14 ( V_21 , V_108 , 0 ) ;
}
F_88 ( V_21 ) ;
return 0 ;
}
bool F_112 ( struct V_6 * V_9 , void * V_235 )
{
if ( V_9 -> V_35 -> V_54 -> V_236 == & V_237 . V_236 ) {
struct V_5 * V_7 = F_3 ( V_9 ) ;
unsigned V_238 = * ( unsigned * ) V_235 ;
return V_238 == V_7 -> V_106 ;
}
return false ;
}
static int F_113 ( void )
{
return F_114 ( & V_237 ) ;
}
static void T_9 F_115 ( void )
{
F_116 ( & V_237 ) ;
}
