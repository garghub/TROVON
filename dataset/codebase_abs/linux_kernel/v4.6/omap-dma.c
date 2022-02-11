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
V_7 -> V_44 = true ;
}
static void F_24 ( struct V_5 * V_7 )
{
struct V_1 * V_21 = F_1 ( V_7 -> V_8 . V_9 . V_35 ) ;
T_1 V_16 ;
F_16 ( V_7 , V_39 , 0 ) ;
F_18 ( V_7 ) ;
V_16 = F_17 ( V_7 , V_41 ) ;
if ( V_21 -> V_32 -> V_45 & V_46 && V_16 & V_47 ) {
T_1 V_48 ;
unsigned V_49 ;
V_48 = F_15 ( V_21 , V_50 ) ;
V_16 = V_48 & ~ V_51 ;
V_16 |= F_25 ( V_52 ) ;
F_14 ( V_21 , V_50 , V_16 ) ;
V_16 = F_17 ( V_7 , V_41 ) ;
V_16 &= ~ V_43 ;
F_16 ( V_7 , V_41 , V_16 ) ;
for ( V_49 = 0 ; ; V_49 ++ ) {
V_16 = F_17 ( V_7 , V_41 ) ;
if ( ! ( V_16 & ( V_53 | V_54 ) ) )
break;
if ( V_49 > 100 )
break;
F_26 ( 5 ) ;
}
if ( V_16 & ( V_53 | V_54 ) )
F_27 ( V_7 -> V_8 . V_9 . V_35 -> V_55 ,
L_1 ,
V_7 -> V_56 ) ;
F_14 ( V_21 , V_50 , V_48 ) ;
} else {
V_16 &= ~ V_43 ;
F_16 ( V_7 , V_41 , V_16 ) ;
}
F_28 () ;
if ( ! F_23 ( V_21 -> V_32 -> V_36 ) && V_7 -> V_57 ) {
V_16 = F_17 ( V_7 , V_58 ) ;
if ( F_19 () )
V_16 |= 1 << 14 ;
else
V_16 &= ~ V_59 ;
F_16 ( V_7 , V_58 , V_16 ) ;
}
V_7 -> V_44 = false ;
}
static void F_29 ( struct V_5 * V_7 , struct V_10 * V_3 ,
unsigned V_60 )
{
struct V_61 * V_62 = V_3 -> V_62 + V_60 ;
unsigned V_63 , V_64 , V_65 ;
if ( V_3 -> V_66 == V_67 || V_3 -> V_66 == V_68 ) {
V_63 = V_69 ;
V_64 = V_70 ;
V_65 = V_71 ;
} else {
V_63 = V_72 ;
V_64 = V_73 ;
V_65 = V_74 ;
}
F_16 ( V_7 , V_63 , V_62 -> V_17 ) ;
F_16 ( V_7 , V_64 , 0 ) ;
F_16 ( V_7 , V_65 , 0 ) ;
F_16 ( V_7 , V_75 , V_62 -> V_76 ) ;
F_16 ( V_7 , V_77 , V_62 -> V_78 ) ;
F_22 ( V_7 , V_3 ) ;
}
static void F_30 ( struct V_5 * V_7 )
{
struct V_15 * V_13 = F_31 ( & V_7 -> V_8 ) ;
struct V_10 * V_3 ;
unsigned V_63 , V_64 , V_65 ;
if ( ! V_13 ) {
V_7 -> V_79 = NULL ;
return;
}
F_32 ( & V_13 -> V_80 ) ;
V_7 -> V_79 = V_3 = F_4 ( & V_13 -> V_14 ) ;
V_7 -> V_81 = 0 ;
F_28 () ;
F_16 ( V_7 , V_41 , V_3 -> V_42 ) ;
if ( F_19 () )
F_16 ( V_7 , V_82 , V_3 -> V_42 >> 16 ) ;
if ( V_3 -> V_66 == V_67 || V_3 -> V_66 == V_68 ) {
V_63 = V_72 ;
V_64 = V_73 ;
V_65 = V_74 ;
} else {
V_63 = V_69 ;
V_64 = V_70 ;
V_65 = V_71 ;
}
F_16 ( V_7 , V_63 , V_3 -> V_83 ) ;
F_16 ( V_7 , V_64 , 0 ) ;
F_16 ( V_7 , V_65 , V_3 -> V_84 ) ;
F_16 ( V_7 , V_85 , V_3 -> V_86 ) ;
F_16 ( V_7 , V_58 , V_3 -> V_87 ) ;
F_29 ( V_7 , V_3 , 0 ) ;
}
static void F_33 ( int V_88 , T_3 V_89 , void * V_90 )
{
struct V_5 * V_7 = V_90 ;
struct V_10 * V_3 ;
unsigned long V_91 ;
F_34 ( & V_7 -> V_8 . V_92 , V_91 ) ;
V_3 = V_7 -> V_79 ;
if ( V_3 ) {
if ( ! V_7 -> V_57 ) {
if ( ++ V_7 -> V_81 < V_3 -> V_93 ) {
F_29 ( V_7 , V_3 , V_7 -> V_81 ) ;
} else {
F_30 ( V_7 ) ;
F_35 ( & V_3 -> V_13 ) ;
}
} else {
F_36 ( & V_3 -> V_13 ) ;
}
}
F_37 ( & V_7 -> V_8 . V_92 , V_91 ) ;
}
static T_4 F_38 ( int V_94 , void * V_95 )
{
struct V_1 * V_21 = V_95 ;
unsigned V_89 , V_96 ;
F_39 ( & V_21 -> V_97 ) ;
V_89 = F_15 ( V_21 , V_98 ) ;
V_89 &= V_21 -> V_99 ;
if ( V_89 == 0 ) {
F_40 ( & V_21 -> V_97 ) ;
return V_100 ;
}
while ( ( V_96 = F_41 ( V_89 ) ) != 0 ) {
unsigned V_101 , V_102 ;
struct V_5 * V_7 ;
V_96 -= 1 ;
V_101 = F_42 ( V_96 ) ;
V_89 &= ~ V_101 ;
V_7 = V_21 -> V_34 [ V_96 ] ;
if ( V_7 == NULL ) {
F_27 ( V_21 -> V_4 . V_55 , L_2 , V_96 ) ;
continue;
}
V_102 = F_20 ( V_7 ) ;
F_14 ( V_21 , V_98 , V_101 ) ;
F_33 ( V_96 , V_102 , V_7 ) ;
}
F_40 ( & V_21 -> V_97 ) ;
return V_103 ;
}
static int F_43 ( struct V_6 * V_9 )
{
struct V_1 * V_21 = F_1 ( V_9 -> V_35 ) ;
struct V_5 * V_7 = F_3 ( V_9 ) ;
int V_104 ;
if ( V_21 -> V_105 ) {
V_104 = F_44 ( V_7 -> V_106 , L_3 ,
F_33 , V_7 , & V_7 -> V_56 ) ;
} else {
V_104 = F_44 ( V_7 -> V_106 , L_3 , NULL , NULL ,
& V_7 -> V_56 ) ;
}
F_45 ( V_21 -> V_4 . V_55 , L_4 ,
V_7 -> V_56 , V_7 -> V_106 ) ;
if ( V_104 >= 0 ) {
F_21 ( V_21 , V_7 , V_7 -> V_56 ) ;
if ( ! V_21 -> V_105 ) {
unsigned V_16 ;
F_46 ( & V_21 -> V_97 ) ;
V_16 = F_42 ( V_7 -> V_56 ) ;
F_14 ( V_21 , V_98 , V_16 ) ;
V_21 -> V_99 |= V_16 ;
F_14 ( V_21 , V_107 , V_21 -> V_99 ) ;
V_16 = F_15 ( V_21 , V_108 ) ;
V_16 &= ~ F_42 ( V_7 -> V_56 ) ;
F_14 ( V_21 , V_108 , V_16 ) ;
F_47 ( & V_21 -> V_97 ) ;
}
}
if ( F_19 () ) {
if ( F_48 ( V_21 -> V_32 -> V_36 ) ) {
V_7 -> V_42 = V_109 ;
V_7 -> V_42 |= V_7 -> V_56 + 1 ;
} else {
V_7 -> V_42 = V_7 -> V_106 & 0x1f ;
}
} else {
V_7 -> V_42 = V_7 -> V_106 & 0x1f ;
V_7 -> V_42 |= ( V_7 -> V_106 & ~ 0x1f ) << 14 ;
}
if ( V_21 -> V_32 -> V_45 & V_110 )
V_7 -> V_42 |= V_111 ;
return V_104 ;
}
static void F_49 ( struct V_6 * V_9 )
{
struct V_1 * V_21 = F_1 ( V_9 -> V_35 ) ;
struct V_5 * V_7 = F_3 ( V_9 ) ;
if ( ! V_21 -> V_105 ) {
F_46 ( & V_21 -> V_97 ) ;
V_21 -> V_99 &= ~ F_42 ( V_7 -> V_56 ) ;
F_14 ( V_21 , V_107 , V_21 -> V_99 ) ;
F_47 ( & V_21 -> V_97 ) ;
}
V_7 -> V_29 = NULL ;
V_21 -> V_34 [ V_7 -> V_56 ] = NULL ;
F_50 ( & V_7 -> V_8 ) ;
F_51 ( V_7 -> V_56 ) ;
F_45 ( V_21 -> V_4 . V_55 , L_5 , V_7 -> V_106 ) ;
V_7 -> V_106 = 0 ;
}
static T_5 F_52 ( struct V_61 * V_62 )
{
return V_62 -> V_76 * V_62 -> V_78 ;
}
static T_5 F_53 ( struct V_10 * V_3 )
{
unsigned V_49 ;
T_5 V_112 ;
for ( V_112 = V_49 = 0 ; V_49 < V_3 -> V_93 ; V_49 ++ )
V_112 += F_52 ( & V_3 -> V_62 [ V_49 ] ) ;
return V_112 * V_113 [ V_3 -> V_114 ] ;
}
static T_5 F_54 ( struct V_10 * V_3 , T_6 V_17 )
{
unsigned V_49 ;
T_5 V_112 , V_115 = V_113 [ V_3 -> V_114 ] ;
for ( V_112 = V_49 = 0 ; V_49 < V_3 -> V_93 ; V_49 ++ ) {
T_5 V_116 = F_52 ( & V_3 -> V_62 [ V_49 ] ) * V_115 ;
if ( V_112 )
V_112 += V_116 ;
else if ( V_17 >= V_3 -> V_62 [ V_49 ] . V_17 &&
V_17 < V_3 -> V_62 [ V_49 ] . V_17 + V_116 )
V_112 += V_3 -> V_62 [ V_49 ] . V_17 + V_116 - V_17 ;
}
return V_112 ;
}
static T_1 F_55 ( struct V_5 * V_7 , unsigned V_22 )
{
struct V_1 * V_21 = F_1 ( V_7 -> V_8 . V_9 . V_35 ) ;
T_1 V_16 ;
V_16 = F_17 ( V_7 , V_22 ) ;
if ( V_16 == 0 && V_21 -> V_32 -> V_45 & V_117 )
V_16 = F_17 ( V_7 , V_22 ) ;
return V_16 ;
}
static T_6 F_56 ( struct V_5 * V_7 )
{
struct V_1 * V_21 = F_1 ( V_7 -> V_8 . V_9 . V_35 ) ;
T_6 V_17 , V_118 ;
if ( F_23 ( V_21 -> V_32 -> V_36 ) ) {
V_17 = F_17 ( V_7 , V_37 ) ;
} else {
V_17 = F_55 ( V_7 , V_119 ) ;
V_118 = F_55 ( V_7 , V_38 ) ;
if ( V_118 == 0 )
V_17 = F_17 ( V_7 , V_72 ) ;
}
if ( F_19 () )
V_17 |= F_17 ( V_7 , V_72 ) & 0xffff0000 ;
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
V_17 = F_17 ( V_7 , V_69 ) ;
}
if ( F_19 () )
V_17 |= F_17 ( V_7 , V_69 ) & 0xffff0000 ;
return V_17 ;
}
static enum V_120 F_58 ( struct V_6 * V_9 ,
T_7 V_121 , struct V_122 * V_123 )
{
struct V_5 * V_7 = F_3 ( V_9 ) ;
struct V_15 * V_13 ;
enum V_120 V_104 ;
unsigned long V_91 ;
V_104 = F_59 ( V_9 , V_121 , V_123 ) ;
if ( ! V_7 -> V_124 && V_7 -> V_44 ) {
T_1 V_42 = F_17 ( V_7 , V_41 ) ;
if ( ! ( V_42 & V_43 ) )
V_104 = V_125 ;
}
if ( V_104 == V_125 || ! V_123 )
return V_104 ;
F_34 ( & V_7 -> V_8 . V_92 , V_91 ) ;
V_13 = F_60 ( & V_7 -> V_8 , V_121 ) ;
if ( V_13 ) {
V_123 -> V_126 = F_53 ( F_4 ( & V_13 -> V_14 ) ) ;
} else if ( V_7 -> V_79 && V_7 -> V_79 -> V_13 . V_14 . V_121 == V_121 ) {
struct V_10 * V_3 = V_7 -> V_79 ;
T_6 V_127 ;
if ( V_3 -> V_66 == V_128 )
V_127 = F_56 ( V_7 ) ;
else if ( V_3 -> V_66 == V_67 || V_3 -> V_66 == V_68 )
V_127 = F_57 ( V_7 ) ;
else
V_127 = 0 ;
V_123 -> V_126 = F_54 ( V_3 , V_127 ) ;
} else {
V_123 -> V_126 = 0 ;
}
F_37 ( & V_7 -> V_8 . V_92 , V_91 ) ;
return V_104 ;
}
static void F_61 ( struct V_6 * V_9 )
{
struct V_5 * V_7 = F_3 ( V_9 ) ;
unsigned long V_91 ;
F_34 ( & V_7 -> V_8 . V_92 , V_91 ) ;
if ( F_62 ( & V_7 -> V_8 ) && ! V_7 -> V_79 )
F_30 ( V_7 ) ;
F_37 ( & V_7 -> V_8 . V_92 , V_91 ) ;
}
static struct V_11 * F_63 (
struct V_6 * V_9 , struct V_129 * V_130 , unsigned V_93 ,
enum V_131 V_66 , unsigned long V_132 , void * V_133 )
{
struct V_1 * V_21 = F_1 ( V_9 -> V_35 ) ;
struct V_5 * V_7 = F_3 ( V_9 ) ;
enum V_134 V_135 ;
struct V_129 * V_136 ;
struct V_10 * V_3 ;
T_6 V_83 ;
unsigned V_49 , V_114 , V_76 , V_137 ;
T_8 V_138 ;
if ( V_66 == V_67 ) {
V_83 = V_7 -> V_139 . V_140 ;
V_135 = V_7 -> V_139 . V_141 ;
V_138 = V_7 -> V_139 . V_142 ;
} else if ( V_66 == V_128 ) {
V_83 = V_7 -> V_139 . V_143 ;
V_135 = V_7 -> V_139 . V_144 ;
V_138 = V_7 -> V_139 . V_145 ;
} else {
F_27 ( V_9 -> V_35 -> V_55 , L_6 , V_146 ) ;
return NULL ;
}
switch ( V_135 ) {
case V_147 :
V_114 = V_148 ;
break;
case V_149 :
V_114 = V_150 ;
break;
case V_151 :
V_114 = V_152 ;
break;
default:
return NULL ;
}
V_3 = F_64 ( sizeof( * V_3 ) + V_93 * sizeof( V_3 -> V_62 [ 0 ] ) , V_153 ) ;
if ( ! V_3 )
return NULL ;
V_3 -> V_66 = V_66 ;
V_3 -> V_83 = V_83 ;
V_3 -> V_114 = V_114 ;
V_3 -> V_42 = V_7 -> V_42 | V_154 ;
if ( V_66 == V_67 )
V_3 -> V_42 |= V_155 | V_156 ;
else
V_3 -> V_42 |= V_157 | V_158 ;
V_3 -> V_40 = V_159 | V_160 ;
V_3 -> V_86 = V_114 ;
if ( F_19 () ) {
V_3 -> V_40 |= V_161 ;
if ( V_66 == V_67 )
V_3 -> V_86 |= V_162 | V_163 ;
else
V_3 -> V_86 |= V_164 | V_165 ;
} else {
if ( V_66 == V_67 )
V_3 -> V_42 |= V_47 ;
V_3 -> V_40 |= V_166 | V_167 ;
}
if ( V_21 -> V_32 -> V_45 & V_168 )
V_3 -> V_87 = V_7 -> V_56 ;
V_76 = V_138 ;
V_137 = V_113 [ V_114 ] * V_76 ;
F_65 (sgl, sgent, sglen, i) {
V_3 -> V_62 [ V_49 ] . V_17 = F_66 ( V_136 ) ;
V_3 -> V_62 [ V_49 ] . V_76 = V_76 ;
V_3 -> V_62 [ V_49 ] . V_78 = F_67 ( V_136 ) / V_137 ;
}
V_3 -> V_93 = V_93 ;
return F_68 ( & V_7 -> V_8 , & V_3 -> V_13 , V_132 ) ;
}
static struct V_11 * F_69 (
struct V_6 * V_9 , T_6 V_169 , T_5 V_170 ,
T_5 V_171 , enum V_131 V_66 , unsigned long V_91 )
{
struct V_1 * V_21 = F_1 ( V_9 -> V_35 ) ;
struct V_5 * V_7 = F_3 ( V_9 ) ;
enum V_134 V_135 ;
struct V_10 * V_3 ;
T_6 V_83 ;
unsigned V_114 ;
T_8 V_138 ;
if ( V_66 == V_67 ) {
V_83 = V_7 -> V_139 . V_140 ;
V_135 = V_7 -> V_139 . V_141 ;
V_138 = V_7 -> V_139 . V_142 ;
} else if ( V_66 == V_128 ) {
V_83 = V_7 -> V_139 . V_143 ;
V_135 = V_7 -> V_139 . V_144 ;
V_138 = V_7 -> V_139 . V_145 ;
} else {
F_27 ( V_9 -> V_35 -> V_55 , L_6 , V_146 ) ;
return NULL ;
}
switch ( V_135 ) {
case V_147 :
V_114 = V_148 ;
break;
case V_149 :
V_114 = V_150 ;
break;
case V_151 :
V_114 = V_152 ;
break;
default:
return NULL ;
}
V_3 = F_64 ( sizeof( * V_3 ) + sizeof( V_3 -> V_62 [ 0 ] ) , V_153 ) ;
if ( ! V_3 )
return NULL ;
V_3 -> V_66 = V_66 ;
V_3 -> V_83 = V_83 ;
V_3 -> V_84 = V_138 ;
V_3 -> V_114 = V_114 ;
V_3 -> V_62 [ 0 ] . V_17 = V_169 ;
V_3 -> V_62 [ 0 ] . V_76 = V_171 / V_113 [ V_114 ] ;
V_3 -> V_62 [ 0 ] . V_78 = V_170 / V_171 ;
V_3 -> V_93 = 1 ;
V_3 -> V_42 = V_7 -> V_42 ;
if ( V_66 == V_67 )
V_3 -> V_42 |= V_155 | V_156 ;
else
V_3 -> V_42 |= V_157 | V_158 ;
V_3 -> V_40 = V_159 ;
if ( V_91 & V_172 )
V_3 -> V_40 |= V_173 ;
V_3 -> V_86 = V_114 ;
if ( F_19 () ) {
V_3 -> V_40 |= V_161 ;
if ( V_66 == V_67 )
V_3 -> V_86 |= V_162 | V_174 ;
else
V_3 -> V_86 |= V_175 | V_165 ;
} else {
if ( V_138 )
V_3 -> V_42 |= V_176 ;
else
V_3 -> V_42 |= V_177 ;
if ( V_66 == V_67 ) {
V_3 -> V_42 |= V_47 ;
V_3 -> V_86 |= V_178 ;
} else {
V_3 -> V_86 |= V_179 ;
}
V_3 -> V_40 |= V_166 | V_167 ;
V_3 -> V_86 |= V_180 | V_181 ;
}
if ( F_23 ( V_21 -> V_32 -> V_36 ) )
V_3 -> V_42 |= V_182 | V_183 ;
else
V_3 -> V_87 = V_7 -> V_56 | V_59 ;
V_7 -> V_57 = true ;
return F_68 ( & V_7 -> V_8 , & V_3 -> V_13 , V_91 ) ;
}
static struct V_11 * F_70 (
struct V_6 * V_9 , T_6 V_184 , T_6 V_185 ,
T_5 V_186 , unsigned long V_132 )
{
struct V_5 * V_7 = F_3 ( V_9 ) ;
struct V_10 * V_3 ;
T_9 V_187 ;
V_3 = F_64 ( sizeof( * V_3 ) + sizeof( V_3 -> V_62 [ 0 ] ) , V_153 ) ;
if ( ! V_3 )
return NULL ;
V_187 = F_71 ( ( V_185 | V_184 | V_186 ) ) ;
if ( V_187 > V_152 )
V_187 = V_152 ;
V_3 -> V_66 = V_68 ;
V_3 -> V_83 = V_185 ;
V_3 -> V_84 = 0 ;
V_3 -> V_114 = V_187 ;
V_3 -> V_62 [ 0 ] . V_76 = V_186 / F_42 ( V_187 ) ;
V_3 -> V_62 [ 0 ] . V_78 = 1 ;
V_3 -> V_62 [ 0 ] . V_17 = V_184 ;
V_3 -> V_93 = 1 ;
V_3 -> V_42 = V_7 -> V_42 ;
V_3 -> V_42 |= V_155 | V_158 ;
V_3 -> V_40 = V_159 | V_173 ;
V_3 -> V_86 = V_187 ;
if ( F_19 () ) {
V_3 -> V_40 |= V_161 ;
V_3 -> V_86 |= V_162 | V_165 ;
} else {
V_3 -> V_86 |= V_178 | V_179 ;
V_3 -> V_40 |= V_166 | V_167 ;
V_3 -> V_86 |= V_180 | V_181 ;
}
return F_68 ( & V_7 -> V_8 , & V_3 -> V_13 , V_132 ) ;
}
static int F_72 ( struct V_6 * V_9 , struct V_188 * V_139 )
{
struct V_5 * V_7 = F_3 ( V_9 ) ;
if ( V_139 -> V_141 == V_189 ||
V_139 -> V_144 == V_189 )
return - V_190 ;
memcpy ( & V_7 -> V_139 , V_139 , sizeof( V_7 -> V_139 ) ) ;
return 0 ;
}
static int F_73 ( struct V_6 * V_9 )
{
struct V_5 * V_7 = F_3 ( V_9 ) ;
unsigned long V_91 ;
F_74 ( V_191 ) ;
F_34 ( & V_7 -> V_8 . V_92 , V_91 ) ;
if ( V_7 -> V_79 ) {
F_5 ( & V_7 -> V_79 -> V_13 ) ;
V_7 -> V_79 = NULL ;
if ( ! V_7 -> V_124 )
F_24 ( V_7 ) ;
}
if ( V_7 -> V_57 ) {
V_7 -> V_57 = false ;
V_7 -> V_124 = false ;
}
F_75 ( & V_7 -> V_8 , & V_191 ) ;
F_37 ( & V_7 -> V_8 . V_92 , V_91 ) ;
F_76 ( & V_7 -> V_8 , & V_191 ) ;
return 0 ;
}
static void F_77 ( struct V_6 * V_9 )
{
struct V_5 * V_7 = F_3 ( V_9 ) ;
F_78 ( & V_7 -> V_8 ) ;
}
static int F_79 ( struct V_6 * V_9 )
{
struct V_5 * V_7 = F_3 ( V_9 ) ;
if ( ! V_7 -> V_57 )
return - V_190 ;
if ( ! V_7 -> V_124 ) {
F_24 ( V_7 ) ;
V_7 -> V_124 = true ;
}
return 0 ;
}
static int F_80 ( struct V_6 * V_9 )
{
struct V_5 * V_7 = F_3 ( V_9 ) ;
if ( ! V_7 -> V_57 )
return - V_190 ;
if ( V_7 -> V_124 ) {
F_28 () ;
F_16 ( V_7 , V_58 , V_7 -> V_79 -> V_87 ) ;
F_22 ( V_7 , V_7 -> V_79 ) ;
V_7 -> V_124 = false ;
}
return 0 ;
}
static int F_81 ( struct V_1 * V_21 )
{
struct V_5 * V_7 ;
V_7 = F_64 ( sizeof( * V_7 ) , V_192 ) ;
if ( ! V_7 )
return - V_193 ;
V_7 -> V_25 = V_21 -> V_25 ;
V_7 -> V_8 . V_194 = F_5 ;
F_82 ( & V_7 -> V_8 , & V_21 -> V_4 ) ;
return 0 ;
}
static void F_83 ( struct V_1 * V_21 )
{
while ( ! F_84 ( & V_21 -> V_4 . V_195 ) ) {
struct V_5 * V_7 = F_85 ( & V_21 -> V_4 . V_195 ,
struct V_5 , V_8 . V_9 . V_196 ) ;
F_32 ( & V_7 -> V_8 . V_9 . V_196 ) ;
F_86 ( & V_7 -> V_8 . V_197 ) ;
F_6 ( V_7 ) ;
}
}
static int F_87 ( struct V_198 * V_199 )
{
struct V_1 * V_21 ;
struct V_200 * V_201 ;
int V_202 , V_49 , V_94 ;
V_21 = F_88 ( & V_199 -> V_55 , sizeof( * V_21 ) , V_192 ) ;
if ( ! V_21 )
return - V_193 ;
V_201 = F_89 ( V_199 , V_203 , 0 ) ;
V_21 -> V_27 = F_90 ( & V_199 -> V_55 , V_201 ) ;
if ( F_91 ( V_21 -> V_27 ) )
return F_92 ( V_21 -> V_27 ) ;
V_21 -> V_32 = F_93 () ;
if ( ! V_21 -> V_32 )
return - V_204 ;
V_21 -> V_25 = V_21 -> V_32 -> V_25 ;
F_94 ( V_205 , V_21 -> V_4 . V_206 ) ;
F_94 ( V_207 , V_21 -> V_4 . V_206 ) ;
F_94 ( V_208 , V_21 -> V_4 . V_206 ) ;
V_21 -> V_4 . V_209 = F_43 ;
V_21 -> V_4 . V_210 = F_49 ;
V_21 -> V_4 . V_211 = F_58 ;
V_21 -> V_4 . V_212 = F_61 ;
V_21 -> V_4 . V_213 = F_63 ;
V_21 -> V_4 . V_214 = F_69 ;
V_21 -> V_4 . V_215 = F_70 ;
V_21 -> V_4 . V_216 = F_72 ;
V_21 -> V_4 . V_217 = F_79 ;
V_21 -> V_4 . V_218 = F_80 ;
V_21 -> V_4 . V_219 = F_73 ;
V_21 -> V_4 . V_220 = F_77 ;
V_21 -> V_4 . V_221 = V_222 ;
V_21 -> V_4 . V_223 = V_222 ;
V_21 -> V_4 . V_224 = F_42 ( V_67 ) | F_42 ( V_128 ) ;
V_21 -> V_4 . V_225 = V_226 ;
V_21 -> V_4 . V_55 = & V_199 -> V_55 ;
F_95 ( & V_21 -> V_4 . V_195 ) ;
F_96 ( & V_21 -> V_92 ) ;
F_96 ( & V_21 -> V_97 ) ;
V_21 -> V_227 = V_228 ;
if ( V_199 -> V_55 . V_229 && F_97 ( V_199 -> V_55 . V_229 ,
L_7 ,
& V_21 -> V_227 ) ) {
F_98 ( & V_199 -> V_55 ,
L_8 ,
V_228 ) ;
}
for ( V_49 = 0 ; V_49 < V_230 ; V_49 ++ ) {
V_202 = F_81 ( V_21 ) ;
if ( V_202 ) {
F_83 ( V_21 ) ;
return V_202 ;
}
}
V_94 = F_99 ( V_199 , 1 ) ;
if ( V_94 <= 0 ) {
F_98 ( & V_199 -> V_55 , L_9 , V_94 ) ;
V_21 -> V_105 = true ;
} else {
V_21 -> V_99 = 0 ;
F_14 ( V_21 , V_107 , 0 ) ;
V_202 = F_100 ( & V_199 -> V_55 , V_94 , F_38 ,
V_231 , L_10 , V_21 ) ;
if ( V_202 )
return V_202 ;
}
V_21 -> V_4 . V_232 . V_233 = V_21 -> V_32 -> V_234 ;
V_21 -> V_4 . V_232 . V_235 = V_21 -> V_32 -> V_236 ;
V_21 -> V_4 . V_232 . V_78 = V_237 ;
V_202 = F_101 ( & V_21 -> V_4 ) ;
if ( V_202 ) {
F_102 ( L_11 ,
V_202 ) ;
F_83 ( V_21 ) ;
return V_202 ;
}
F_103 ( V_199 , V_21 ) ;
if ( V_199 -> V_55 . V_229 ) {
V_238 . V_239 = V_21 -> V_4 . V_206 ;
V_202 = F_104 ( V_199 -> V_55 . V_229 ,
V_240 , & V_238 ) ;
if ( V_202 ) {
F_102 ( L_12 ) ;
F_105 ( & V_21 -> V_4 ) ;
F_83 ( V_21 ) ;
}
}
F_98 ( & V_199 -> V_55 , L_13 ) ;
return V_202 ;
}
static int F_106 ( struct V_198 * V_199 )
{
struct V_1 * V_21 = F_107 ( V_199 ) ;
if ( V_199 -> V_55 . V_229 )
F_108 ( V_199 -> V_55 . V_229 ) ;
F_105 ( & V_21 -> V_4 ) ;
if ( ! V_21 -> V_105 ) {
F_14 ( V_21 , V_108 , 0 ) ;
}
F_83 ( V_21 ) ;
return 0 ;
}
bool V_237 ( struct V_6 * V_9 , void * V_241 )
{
if ( V_9 -> V_35 -> V_55 -> V_242 == & V_243 . V_242 ) {
struct V_1 * V_21 = F_1 ( V_9 -> V_35 ) ;
struct V_5 * V_7 = F_3 ( V_9 ) ;
unsigned V_244 = * ( unsigned * ) V_241 ;
if ( V_244 <= V_21 -> V_227 ) {
V_7 -> V_106 = V_244 ;
return true ;
}
}
return false ;
}
static int F_109 ( void )
{
return F_110 ( & V_243 ) ;
}
static void T_10 F_111 ( void )
{
F_112 ( & V_243 ) ;
}
