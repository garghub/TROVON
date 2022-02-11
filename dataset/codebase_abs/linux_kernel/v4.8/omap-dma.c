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
F_16 ( V_7 , V_64 , V_62 -> V_75 ) ;
F_16 ( V_7 , V_65 , V_62 -> V_76 ) ;
F_16 ( V_7 , V_77 , V_62 -> V_78 ) ;
F_16 ( V_7 , V_79 , V_62 -> V_80 ) ;
F_22 ( V_7 , V_3 ) ;
}
static void F_30 ( struct V_5 * V_7 )
{
struct V_15 * V_13 = F_31 ( & V_7 -> V_8 ) ;
struct V_10 * V_3 ;
unsigned V_63 , V_64 , V_65 ;
if ( ! V_13 ) {
V_7 -> V_81 = NULL ;
return;
}
F_32 ( & V_13 -> V_82 ) ;
V_7 -> V_81 = V_3 = F_4 ( & V_13 -> V_14 ) ;
V_7 -> V_83 = 0 ;
F_28 () ;
F_16 ( V_7 , V_41 , V_3 -> V_42 ) ;
if ( F_19 () )
F_16 ( V_7 , V_84 , V_3 -> V_42 >> 16 ) ;
if ( V_3 -> V_66 == V_67 || V_3 -> V_66 == V_68 ) {
V_63 = V_72 ;
V_64 = V_73 ;
V_65 = V_74 ;
} else {
V_63 = V_69 ;
V_64 = V_70 ;
V_65 = V_71 ;
}
F_16 ( V_7 , V_63 , V_3 -> V_85 ) ;
F_16 ( V_7 , V_64 , V_3 -> V_75 ) ;
F_16 ( V_7 , V_65 , V_3 -> V_76 ) ;
F_16 ( V_7 , V_86 , V_3 -> V_87 ) ;
F_16 ( V_7 , V_58 , V_3 -> V_88 ) ;
F_29 ( V_7 , V_3 , 0 ) ;
}
static void F_33 ( int V_89 , T_3 V_90 , void * V_91 )
{
struct V_5 * V_7 = V_91 ;
struct V_10 * V_3 ;
unsigned long V_92 ;
F_34 ( & V_7 -> V_8 . V_93 , V_92 ) ;
V_3 = V_7 -> V_81 ;
if ( V_3 ) {
if ( ! V_7 -> V_57 ) {
if ( ++ V_7 -> V_83 < V_3 -> V_94 ) {
F_29 ( V_7 , V_3 , V_7 -> V_83 ) ;
} else {
F_30 ( V_7 ) ;
F_35 ( & V_3 -> V_13 ) ;
}
} else {
F_36 ( & V_3 -> V_13 ) ;
}
}
F_37 ( & V_7 -> V_8 . V_93 , V_92 ) ;
}
static T_4 F_38 ( int V_95 , void * V_96 )
{
struct V_1 * V_21 = V_96 ;
unsigned V_90 , V_97 ;
F_39 ( & V_21 -> V_98 ) ;
V_90 = F_15 ( V_21 , V_99 ) ;
V_90 &= V_21 -> V_100 ;
if ( V_90 == 0 ) {
F_40 ( & V_21 -> V_98 ) ;
return V_101 ;
}
while ( ( V_97 = F_41 ( V_90 ) ) != 0 ) {
unsigned V_102 , V_103 ;
struct V_5 * V_7 ;
V_97 -= 1 ;
V_102 = F_42 ( V_97 ) ;
V_90 &= ~ V_102 ;
V_7 = V_21 -> V_34 [ V_97 ] ;
if ( V_7 == NULL ) {
F_27 ( V_21 -> V_4 . V_55 , L_2 , V_97 ) ;
continue;
}
V_103 = F_20 ( V_7 ) ;
F_14 ( V_21 , V_99 , V_102 ) ;
F_33 ( V_97 , V_103 , V_7 ) ;
}
F_40 ( & V_21 -> V_98 ) ;
return V_104 ;
}
static int F_43 ( struct V_6 * V_9 )
{
struct V_1 * V_21 = F_1 ( V_9 -> V_35 ) ;
struct V_5 * V_7 = F_3 ( V_9 ) ;
int V_105 ;
if ( V_21 -> V_106 ) {
V_105 = F_44 ( V_7 -> V_107 , L_3 ,
F_33 , V_7 , & V_7 -> V_56 ) ;
} else {
V_105 = F_44 ( V_7 -> V_107 , L_3 , NULL , NULL ,
& V_7 -> V_56 ) ;
}
F_45 ( V_21 -> V_4 . V_55 , L_4 ,
V_7 -> V_56 , V_7 -> V_107 ) ;
if ( V_105 >= 0 ) {
F_21 ( V_21 , V_7 , V_7 -> V_56 ) ;
if ( ! V_21 -> V_106 ) {
unsigned V_16 ;
F_46 ( & V_21 -> V_98 ) ;
V_16 = F_42 ( V_7 -> V_56 ) ;
F_14 ( V_21 , V_99 , V_16 ) ;
V_21 -> V_100 |= V_16 ;
F_14 ( V_21 , V_108 , V_21 -> V_100 ) ;
V_16 = F_15 ( V_21 , V_109 ) ;
V_16 &= ~ F_42 ( V_7 -> V_56 ) ;
F_14 ( V_21 , V_109 , V_16 ) ;
F_47 ( & V_21 -> V_98 ) ;
}
}
if ( F_19 () ) {
if ( F_48 ( V_21 -> V_32 -> V_36 ) ) {
V_7 -> V_42 = V_110 ;
V_7 -> V_42 |= V_7 -> V_56 + 1 ;
} else {
V_7 -> V_42 = V_7 -> V_107 & 0x1f ;
}
} else {
V_7 -> V_42 = V_7 -> V_107 & 0x1f ;
V_7 -> V_42 |= ( V_7 -> V_107 & ~ 0x1f ) << 14 ;
}
if ( V_21 -> V_32 -> V_45 & V_111 )
V_7 -> V_42 |= V_112 ;
return V_105 ;
}
static void F_49 ( struct V_6 * V_9 )
{
struct V_1 * V_21 = F_1 ( V_9 -> V_35 ) ;
struct V_5 * V_7 = F_3 ( V_9 ) ;
if ( ! V_21 -> V_106 ) {
F_46 ( & V_21 -> V_98 ) ;
V_21 -> V_100 &= ~ F_42 ( V_7 -> V_56 ) ;
F_14 ( V_21 , V_108 , V_21 -> V_100 ) ;
F_47 ( & V_21 -> V_98 ) ;
}
V_7 -> V_29 = NULL ;
V_21 -> V_34 [ V_7 -> V_56 ] = NULL ;
F_50 ( & V_7 -> V_8 ) ;
F_51 ( V_7 -> V_56 ) ;
F_45 ( V_21 -> V_4 . V_55 , L_5 , V_7 -> V_107 ) ;
V_7 -> V_107 = 0 ;
}
static T_5 F_52 ( struct V_61 * V_62 )
{
return V_62 -> V_78 * V_62 -> V_80 ;
}
static T_5 F_53 ( struct V_10 * V_3 )
{
unsigned V_49 ;
T_5 V_113 ;
for ( V_113 = V_49 = 0 ; V_49 < V_3 -> V_94 ; V_49 ++ )
V_113 += F_52 ( & V_3 -> V_62 [ V_49 ] ) ;
return V_113 * V_114 [ V_3 -> V_115 ] ;
}
static T_5 F_54 ( struct V_10 * V_3 , T_6 V_17 )
{
unsigned V_49 ;
T_5 V_113 , V_116 = V_114 [ V_3 -> V_115 ] ;
for ( V_113 = V_49 = 0 ; V_49 < V_3 -> V_94 ; V_49 ++ ) {
T_5 V_117 = F_52 ( & V_3 -> V_62 [ V_49 ] ) * V_116 ;
if ( V_113 )
V_113 += V_117 ;
else if ( V_17 >= V_3 -> V_62 [ V_49 ] . V_17 &&
V_17 < V_3 -> V_62 [ V_49 ] . V_17 + V_117 )
V_113 += V_3 -> V_62 [ V_49 ] . V_17 + V_117 - V_17 ;
}
return V_113 ;
}
static T_1 F_55 ( struct V_5 * V_7 , unsigned V_22 )
{
struct V_1 * V_21 = F_1 ( V_7 -> V_8 . V_9 . V_35 ) ;
T_1 V_16 ;
V_16 = F_17 ( V_7 , V_22 ) ;
if ( V_16 == 0 && V_21 -> V_32 -> V_45 & V_118 )
V_16 = F_17 ( V_7 , V_22 ) ;
return V_16 ;
}
static T_6 F_56 ( struct V_5 * V_7 )
{
struct V_1 * V_21 = F_1 ( V_7 -> V_8 . V_9 . V_35 ) ;
T_6 V_17 , V_119 ;
if ( F_23 ( V_21 -> V_32 -> V_36 ) ) {
V_17 = F_17 ( V_7 , V_37 ) ;
} else {
V_17 = F_55 ( V_7 , V_120 ) ;
V_119 = F_55 ( V_7 , V_38 ) ;
if ( V_119 == 0 )
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
static enum V_121 F_58 ( struct V_6 * V_9 ,
T_7 V_122 , struct V_123 * V_124 )
{
struct V_5 * V_7 = F_3 ( V_9 ) ;
struct V_15 * V_13 ;
enum V_121 V_105 ;
unsigned long V_92 ;
V_105 = F_59 ( V_9 , V_122 , V_124 ) ;
if ( ! V_7 -> V_125 && V_7 -> V_44 ) {
T_1 V_42 = F_17 ( V_7 , V_41 ) ;
if ( ! ( V_42 & V_43 ) )
V_105 = V_126 ;
}
if ( V_105 == V_126 || ! V_124 )
return V_105 ;
F_34 ( & V_7 -> V_8 . V_93 , V_92 ) ;
V_13 = F_60 ( & V_7 -> V_8 , V_122 ) ;
if ( V_13 ) {
V_124 -> V_127 = F_53 ( F_4 ( & V_13 -> V_14 ) ) ;
} else if ( V_7 -> V_81 && V_7 -> V_81 -> V_13 . V_14 . V_122 == V_122 ) {
struct V_10 * V_3 = V_7 -> V_81 ;
T_6 V_128 ;
if ( V_3 -> V_66 == V_129 )
V_128 = F_56 ( V_7 ) ;
else if ( V_3 -> V_66 == V_67 || V_3 -> V_66 == V_68 )
V_128 = F_57 ( V_7 ) ;
else
V_128 = 0 ;
V_124 -> V_127 = F_54 ( V_3 , V_128 ) ;
} else {
V_124 -> V_127 = 0 ;
}
F_37 ( & V_7 -> V_8 . V_93 , V_92 ) ;
return V_105 ;
}
static void F_61 ( struct V_6 * V_9 )
{
struct V_5 * V_7 = F_3 ( V_9 ) ;
unsigned long V_92 ;
F_34 ( & V_7 -> V_8 . V_93 , V_92 ) ;
if ( F_62 ( & V_7 -> V_8 ) && ! V_7 -> V_81 )
F_30 ( V_7 ) ;
F_37 ( & V_7 -> V_8 . V_93 , V_92 ) ;
}
static struct V_11 * F_63 (
struct V_6 * V_9 , struct V_130 * V_131 , unsigned V_94 ,
enum V_132 V_66 , unsigned long V_133 , void * V_134 )
{
struct V_1 * V_21 = F_1 ( V_9 -> V_35 ) ;
struct V_5 * V_7 = F_3 ( V_9 ) ;
enum V_135 V_136 ;
struct V_130 * V_137 ;
struct V_10 * V_3 ;
T_6 V_85 ;
unsigned V_49 , V_115 , V_78 , V_138 ;
T_8 V_139 ;
if ( V_66 == V_67 ) {
V_85 = V_7 -> V_140 . V_141 ;
V_136 = V_7 -> V_140 . V_142 ;
V_139 = V_7 -> V_140 . V_143 ;
} else if ( V_66 == V_129 ) {
V_85 = V_7 -> V_140 . V_144 ;
V_136 = V_7 -> V_140 . V_145 ;
V_139 = V_7 -> V_140 . V_146 ;
} else {
F_27 ( V_9 -> V_35 -> V_55 , L_6 , V_147 ) ;
return NULL ;
}
switch ( V_136 ) {
case V_148 :
V_115 = V_149 ;
break;
case V_150 :
V_115 = V_151 ;
break;
case V_152 :
V_115 = V_153 ;
break;
default:
return NULL ;
}
V_3 = F_64 ( sizeof( * V_3 ) + V_94 * sizeof( V_3 -> V_62 [ 0 ] ) , V_154 ) ;
if ( ! V_3 )
return NULL ;
V_3 -> V_66 = V_66 ;
V_3 -> V_85 = V_85 ;
V_3 -> V_115 = V_115 ;
V_3 -> V_42 = V_7 -> V_42 | V_155 ;
if ( V_66 == V_67 )
V_3 -> V_42 |= V_156 | V_157 ;
else
V_3 -> V_42 |= V_158 | V_159 ;
V_3 -> V_40 = V_160 | V_161 ;
V_3 -> V_87 = V_115 ;
if ( F_19 () ) {
V_3 -> V_40 |= V_162 ;
if ( V_66 == V_67 )
V_3 -> V_87 |= V_163 | V_164 ;
else
V_3 -> V_87 |= V_165 | V_166 ;
} else {
if ( V_66 == V_67 )
V_3 -> V_42 |= V_47 ;
V_3 -> V_40 |= V_167 | V_168 ;
}
if ( V_21 -> V_32 -> V_45 & V_169 )
V_3 -> V_88 = V_7 -> V_56 ;
V_78 = V_139 ;
V_138 = V_114 [ V_115 ] * V_78 ;
F_65 (sgl, sgent, sglen, i) {
V_3 -> V_62 [ V_49 ] . V_17 = F_66 ( V_137 ) ;
V_3 -> V_62 [ V_49 ] . V_78 = V_78 ;
V_3 -> V_62 [ V_49 ] . V_80 = F_67 ( V_137 ) / V_138 ;
}
V_3 -> V_94 = V_94 ;
return F_68 ( & V_7 -> V_8 , & V_3 -> V_13 , V_133 ) ;
}
static struct V_11 * F_69 (
struct V_6 * V_9 , T_6 V_170 , T_5 V_171 ,
T_5 V_172 , enum V_132 V_66 , unsigned long V_92 )
{
struct V_1 * V_21 = F_1 ( V_9 -> V_35 ) ;
struct V_5 * V_7 = F_3 ( V_9 ) ;
enum V_135 V_136 ;
struct V_10 * V_3 ;
T_6 V_85 ;
unsigned V_115 ;
T_8 V_139 ;
if ( V_66 == V_67 ) {
V_85 = V_7 -> V_140 . V_141 ;
V_136 = V_7 -> V_140 . V_142 ;
V_139 = V_7 -> V_140 . V_143 ;
} else if ( V_66 == V_129 ) {
V_85 = V_7 -> V_140 . V_144 ;
V_136 = V_7 -> V_140 . V_145 ;
V_139 = V_7 -> V_140 . V_146 ;
} else {
F_27 ( V_9 -> V_35 -> V_55 , L_6 , V_147 ) ;
return NULL ;
}
switch ( V_136 ) {
case V_148 :
V_115 = V_149 ;
break;
case V_150 :
V_115 = V_151 ;
break;
case V_152 :
V_115 = V_153 ;
break;
default:
return NULL ;
}
V_3 = F_64 ( sizeof( * V_3 ) + sizeof( V_3 -> V_62 [ 0 ] ) , V_154 ) ;
if ( ! V_3 )
return NULL ;
V_3 -> V_66 = V_66 ;
V_3 -> V_85 = V_85 ;
V_3 -> V_76 = V_139 ;
V_3 -> V_115 = V_115 ;
V_3 -> V_62 [ 0 ] . V_17 = V_170 ;
V_3 -> V_62 [ 0 ] . V_78 = V_172 / V_114 [ V_115 ] ;
V_3 -> V_62 [ 0 ] . V_80 = V_171 / V_172 ;
V_3 -> V_94 = 1 ;
V_3 -> V_42 = V_7 -> V_42 ;
if ( V_66 == V_67 )
V_3 -> V_42 |= V_156 | V_157 ;
else
V_3 -> V_42 |= V_158 | V_159 ;
V_3 -> V_40 = V_160 ;
if ( V_92 & V_173 )
V_3 -> V_40 |= V_174 ;
V_3 -> V_87 = V_115 ;
if ( F_19 () ) {
V_3 -> V_40 |= V_162 ;
if ( V_66 == V_67 )
V_3 -> V_87 |= V_163 | V_175 ;
else
V_3 -> V_87 |= V_176 | V_166 ;
} else {
if ( V_139 )
V_3 -> V_42 |= V_177 ;
else
V_3 -> V_42 |= V_178 ;
if ( V_66 == V_67 ) {
V_3 -> V_42 |= V_47 ;
V_3 -> V_87 |= V_179 ;
} else {
V_3 -> V_87 |= V_180 ;
}
V_3 -> V_40 |= V_167 | V_168 ;
V_3 -> V_87 |= V_181 | V_182 ;
}
if ( F_23 ( V_21 -> V_32 -> V_36 ) )
V_3 -> V_42 |= V_183 | V_184 ;
else
V_3 -> V_88 = V_7 -> V_56 | V_59 ;
V_7 -> V_57 = true ;
return F_68 ( & V_7 -> V_8 , & V_3 -> V_13 , V_92 ) ;
}
static struct V_11 * F_70 (
struct V_6 * V_9 , T_6 V_185 , T_6 V_186 ,
T_5 V_187 , unsigned long V_133 )
{
struct V_5 * V_7 = F_3 ( V_9 ) ;
struct V_10 * V_3 ;
T_9 V_188 ;
V_3 = F_64 ( sizeof( * V_3 ) + sizeof( V_3 -> V_62 [ 0 ] ) , V_154 ) ;
if ( ! V_3 )
return NULL ;
V_188 = F_71 ( ( V_186 | V_185 | V_187 ) ) ;
if ( V_188 > V_153 )
V_188 = V_153 ;
V_3 -> V_66 = V_68 ;
V_3 -> V_85 = V_186 ;
V_3 -> V_76 = 0 ;
V_3 -> V_115 = V_188 ;
V_3 -> V_62 [ 0 ] . V_78 = V_187 / F_42 ( V_188 ) ;
V_3 -> V_62 [ 0 ] . V_80 = 1 ;
V_3 -> V_62 [ 0 ] . V_17 = V_185 ;
V_3 -> V_94 = 1 ;
V_3 -> V_42 = V_7 -> V_42 ;
V_3 -> V_42 |= V_156 | V_159 ;
V_3 -> V_40 = V_160 | V_174 ;
V_3 -> V_87 = V_188 ;
if ( F_19 () ) {
V_3 -> V_40 |= V_162 ;
V_3 -> V_87 |= V_163 | V_166 ;
} else {
V_3 -> V_87 |= V_179 | V_180 ;
V_3 -> V_40 |= V_167 | V_168 ;
V_3 -> V_87 |= V_181 | V_182 ;
}
return F_68 ( & V_7 -> V_8 , & V_3 -> V_13 , V_133 ) ;
}
static struct V_11 * F_72 (
struct V_6 * V_9 , struct V_189 * V_190 ,
unsigned long V_92 )
{
struct V_5 * V_7 = F_3 ( V_9 ) ;
struct V_10 * V_3 ;
struct V_61 * V_62 ;
T_9 V_188 ;
T_5 V_191 , V_192 ;
if ( F_73 ( V_190 -> V_66 ) )
return NULL ;
if ( V_190 -> V_193 != 1 || V_190 -> V_194 == 0 )
return NULL ;
V_3 = F_64 ( sizeof( * V_3 ) + sizeof( V_3 -> V_62 [ 0 ] ) , V_154 ) ;
if ( ! V_3 )
return NULL ;
V_188 = F_71 ( ( V_190 -> V_195 | V_190 -> V_196 | V_190 -> V_131 [ 0 ] . V_113 ) ) ;
if ( V_188 > V_153 )
V_188 = V_153 ;
V_62 = & V_3 -> V_62 [ 0 ] ;
V_3 -> V_66 = V_68 ;
V_3 -> V_85 = V_190 -> V_195 ;
V_3 -> V_115 = V_188 ;
V_62 -> V_78 = V_190 -> V_131 [ 0 ] . V_113 / F_42 ( V_188 ) ;
V_62 -> V_80 = V_190 -> V_194 ;
V_62 -> V_17 = V_190 -> V_196 ;
V_3 -> V_94 = 1 ;
V_3 -> V_42 = V_7 -> V_42 ;
V_191 = F_74 ( V_190 , & V_190 -> V_131 [ 0 ] ) ;
V_192 = F_75 ( V_190 , & V_190 -> V_131 [ 0 ] ) ;
if ( V_191 ) {
V_3 -> V_42 |= V_197 ;
V_3 -> V_75 = 1 ;
V_3 -> V_76 = V_191 ;
} else if ( V_190 -> V_198 ) {
V_3 -> V_42 |= V_159 ;
V_3 -> V_76 = 0 ;
} else {
F_27 ( V_9 -> V_35 -> V_55 ,
L_7 ,
V_147 ) ;
F_6 ( V_3 ) ;
return NULL ;
}
if ( V_192 ) {
V_3 -> V_42 |= V_199 ;
V_62 -> V_75 = 1 ;
V_62 -> V_76 = V_192 ;
} else if ( V_190 -> V_200 ) {
V_3 -> V_42 |= V_156 ;
V_62 -> V_76 = 0 ;
} else {
F_27 ( V_9 -> V_35 -> V_55 ,
L_8 ,
V_147 ) ;
F_6 ( V_3 ) ;
return NULL ;
}
V_3 -> V_40 = V_160 | V_174 ;
V_3 -> V_87 = V_188 ;
if ( F_19 () ) {
V_3 -> V_40 |= V_162 ;
V_3 -> V_87 |= V_163 | V_166 ;
} else {
V_3 -> V_87 |= V_179 | V_180 ;
V_3 -> V_40 |= V_167 | V_168 ;
V_3 -> V_87 |= V_181 | V_182 ;
}
return F_68 ( & V_7 -> V_8 , & V_3 -> V_13 , V_92 ) ;
}
static int F_76 ( struct V_6 * V_9 , struct V_201 * V_140 )
{
struct V_5 * V_7 = F_3 ( V_9 ) ;
if ( V_140 -> V_142 == V_202 ||
V_140 -> V_145 == V_202 )
return - V_203 ;
memcpy ( & V_7 -> V_140 , V_140 , sizeof( V_7 -> V_140 ) ) ;
return 0 ;
}
static int F_77 ( struct V_6 * V_9 )
{
struct V_5 * V_7 = F_3 ( V_9 ) ;
unsigned long V_92 ;
F_78 ( V_204 ) ;
F_34 ( & V_7 -> V_8 . V_93 , V_92 ) ;
if ( V_7 -> V_81 ) {
F_5 ( & V_7 -> V_81 -> V_13 ) ;
V_7 -> V_81 = NULL ;
if ( ! V_7 -> V_125 )
F_24 ( V_7 ) ;
}
if ( V_7 -> V_57 ) {
V_7 -> V_57 = false ;
V_7 -> V_125 = false ;
}
F_79 ( & V_7 -> V_8 , & V_204 ) ;
F_37 ( & V_7 -> V_8 . V_93 , V_92 ) ;
F_80 ( & V_7 -> V_8 , & V_204 ) ;
return 0 ;
}
static void F_81 ( struct V_6 * V_9 )
{
struct V_5 * V_7 = F_3 ( V_9 ) ;
F_82 ( & V_7 -> V_8 ) ;
}
static int F_83 ( struct V_6 * V_9 )
{
struct V_5 * V_7 = F_3 ( V_9 ) ;
if ( ! V_7 -> V_57 )
return - V_203 ;
if ( ! V_7 -> V_125 ) {
F_24 ( V_7 ) ;
V_7 -> V_125 = true ;
}
return 0 ;
}
static int F_84 ( struct V_6 * V_9 )
{
struct V_5 * V_7 = F_3 ( V_9 ) ;
if ( ! V_7 -> V_57 )
return - V_203 ;
if ( V_7 -> V_125 ) {
F_28 () ;
F_16 ( V_7 , V_58 , V_7 -> V_81 -> V_88 ) ;
F_22 ( V_7 , V_7 -> V_81 ) ;
V_7 -> V_125 = false ;
}
return 0 ;
}
static int F_85 ( struct V_1 * V_21 )
{
struct V_5 * V_7 ;
V_7 = F_64 ( sizeof( * V_7 ) , V_205 ) ;
if ( ! V_7 )
return - V_206 ;
V_7 -> V_25 = V_21 -> V_25 ;
V_7 -> V_8 . V_207 = F_5 ;
F_86 ( & V_7 -> V_8 , & V_21 -> V_4 ) ;
return 0 ;
}
static void F_87 ( struct V_1 * V_21 )
{
while ( ! F_88 ( & V_21 -> V_4 . V_208 ) ) {
struct V_5 * V_7 = F_89 ( & V_21 -> V_4 . V_208 ,
struct V_5 , V_8 . V_9 . V_209 ) ;
F_32 ( & V_7 -> V_8 . V_9 . V_209 ) ;
F_90 ( & V_7 -> V_8 . V_210 ) ;
F_6 ( V_7 ) ;
}
}
static int F_91 ( struct V_211 * V_212 )
{
struct V_1 * V_21 ;
struct V_213 * V_214 ;
int V_215 , V_49 , V_95 ;
V_21 = F_92 ( & V_212 -> V_55 , sizeof( * V_21 ) , V_205 ) ;
if ( ! V_21 )
return - V_206 ;
V_214 = F_93 ( V_212 , V_216 , 0 ) ;
V_21 -> V_27 = F_94 ( & V_212 -> V_55 , V_214 ) ;
if ( F_95 ( V_21 -> V_27 ) )
return F_96 ( V_21 -> V_27 ) ;
V_21 -> V_32 = F_97 () ;
if ( ! V_21 -> V_32 )
return - V_217 ;
V_21 -> V_25 = V_21 -> V_32 -> V_25 ;
F_98 ( V_218 , V_21 -> V_4 . V_219 ) ;
F_98 ( V_220 , V_21 -> V_4 . V_219 ) ;
F_98 ( V_221 , V_21 -> V_4 . V_219 ) ;
F_98 ( V_222 , V_21 -> V_4 . V_219 ) ;
V_21 -> V_4 . V_223 = F_43 ;
V_21 -> V_4 . V_224 = F_49 ;
V_21 -> V_4 . V_225 = F_58 ;
V_21 -> V_4 . V_226 = F_61 ;
V_21 -> V_4 . V_227 = F_63 ;
V_21 -> V_4 . V_228 = F_69 ;
V_21 -> V_4 . V_229 = F_70 ;
V_21 -> V_4 . V_230 = F_72 ;
V_21 -> V_4 . V_231 = F_76 ;
V_21 -> V_4 . V_232 = F_83 ;
V_21 -> V_4 . V_233 = F_84 ;
V_21 -> V_4 . V_234 = F_77 ;
V_21 -> V_4 . V_235 = F_81 ;
V_21 -> V_4 . V_236 = V_237 ;
V_21 -> V_4 . V_238 = V_237 ;
V_21 -> V_4 . V_239 = F_42 ( V_67 ) | F_42 ( V_129 ) ;
V_21 -> V_4 . V_240 = V_241 ;
V_21 -> V_4 . V_55 = & V_212 -> V_55 ;
F_99 ( & V_21 -> V_4 . V_208 ) ;
F_100 ( & V_21 -> V_93 ) ;
F_100 ( & V_21 -> V_98 ) ;
V_21 -> V_242 = V_243 ;
if ( V_212 -> V_55 . V_244 && F_101 ( V_212 -> V_55 . V_244 ,
L_9 ,
& V_21 -> V_242 ) ) {
F_102 ( & V_212 -> V_55 ,
L_10 ,
V_243 ) ;
}
for ( V_49 = 0 ; V_49 < V_245 ; V_49 ++ ) {
V_215 = F_85 ( V_21 ) ;
if ( V_215 ) {
F_87 ( V_21 ) ;
return V_215 ;
}
}
V_95 = F_103 ( V_212 , 1 ) ;
if ( V_95 <= 0 ) {
F_102 ( & V_212 -> V_55 , L_11 , V_95 ) ;
V_21 -> V_106 = true ;
} else {
V_21 -> V_100 = 0 ;
F_14 ( V_21 , V_108 , 0 ) ;
V_215 = F_104 ( & V_212 -> V_55 , V_95 , F_38 ,
V_246 , L_12 , V_21 ) ;
if ( V_215 )
return V_215 ;
}
V_21 -> V_4 . V_247 . V_248 = V_21 -> V_32 -> V_249 ;
V_21 -> V_4 . V_247 . V_250 = V_21 -> V_32 -> V_251 ;
V_21 -> V_4 . V_247 . V_80 = V_252 ;
V_215 = F_105 ( & V_21 -> V_4 ) ;
if ( V_215 ) {
F_106 ( L_13 ,
V_215 ) ;
F_87 ( V_21 ) ;
return V_215 ;
}
F_107 ( V_212 , V_21 ) ;
if ( V_212 -> V_55 . V_244 ) {
V_253 . V_254 = V_21 -> V_4 . V_219 ;
V_215 = F_108 ( V_212 -> V_55 . V_244 ,
V_255 , & V_253 ) ;
if ( V_215 ) {
F_106 ( L_14 ) ;
F_109 ( & V_21 -> V_4 ) ;
F_87 ( V_21 ) ;
}
}
F_102 ( & V_212 -> V_55 , L_15 ) ;
return V_215 ;
}
static int F_110 ( struct V_211 * V_212 )
{
struct V_1 * V_21 = F_111 ( V_212 ) ;
int V_95 ;
if ( V_212 -> V_55 . V_244 )
F_112 ( V_212 -> V_55 . V_244 ) ;
V_95 = F_103 ( V_212 , 1 ) ;
F_113 ( & V_212 -> V_55 , V_95 , V_21 ) ;
F_109 ( & V_21 -> V_4 ) ;
if ( ! V_21 -> V_106 ) {
F_14 ( V_21 , V_109 , 0 ) ;
}
F_87 ( V_21 ) ;
return 0 ;
}
bool V_252 ( struct V_6 * V_9 , void * V_256 )
{
if ( V_9 -> V_35 -> V_55 -> V_257 == & V_258 . V_257 ) {
struct V_1 * V_21 = F_1 ( V_9 -> V_35 ) ;
struct V_5 * V_7 = F_3 ( V_9 ) ;
unsigned V_259 = * ( unsigned * ) V_256 ;
if ( V_259 <= V_21 -> V_242 ) {
V_7 -> V_107 = V_259 ;
return true ;
}
}
return false ;
}
static int F_114 ( void )
{
return F_115 ( & V_258 ) ;
}
static void T_10 F_116 ( void )
{
F_117 ( & V_258 ) ;
}
