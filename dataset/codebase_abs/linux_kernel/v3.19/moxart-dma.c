static struct V_1 * F_1 ( struct V_2 * V_3 )
{
return & V_3 -> V_4 -> V_1 ;
}
static inline struct V_5 * F_2 ( struct V_2 * V_6 )
{
return F_3 ( V_6 , struct V_5 , V_7 . V_3 ) ;
}
static inline struct V_8 * F_4 (
struct V_9 * V_10 )
{
return F_3 ( V_10 , struct V_8 , V_11 . V_12 ) ;
}
static void F_5 ( struct V_13 * V_11 )
{
F_6 ( F_3 ( V_11 , struct V_8 , V_11 ) ) ;
}
static int F_7 ( struct V_2 * V_3 )
{
struct V_5 * V_14 = F_2 ( V_3 ) ;
unsigned long V_15 ;
F_8 ( V_16 ) ;
T_1 V_17 ;
F_9 ( F_1 ( V_3 ) , L_1 , V_18 , V_14 ) ;
F_10 ( & V_14 -> V_7 . V_19 , V_15 ) ;
if ( V_14 -> V_20 )
V_14 -> V_20 = NULL ;
V_17 = F_11 ( V_14 -> V_21 + V_22 ) ;
V_17 &= ~ ( V_23 | V_24 | V_25 ) ;
F_12 ( V_17 , V_14 -> V_21 + V_22 ) ;
F_13 ( & V_14 -> V_7 , & V_16 ) ;
F_14 ( & V_14 -> V_7 . V_19 , V_15 ) ;
F_15 ( & V_14 -> V_7 , & V_16 ) ;
return 0 ;
}
static int F_16 ( struct V_2 * V_3 ,
struct V_26 * V_27 )
{
struct V_5 * V_14 = F_2 ( V_3 ) ;
T_1 V_17 ;
V_14 -> V_27 = * V_27 ;
V_17 = F_11 ( V_14 -> V_21 + V_22 ) ;
V_17 |= V_28 ;
V_17 &= ~ ( V_29 | V_30 ) ;
V_17 &= ~ ( V_31 | V_32 ) ;
switch ( V_14 -> V_27 . V_33 ) {
case V_34 :
V_17 |= V_35 ;
if ( V_14 -> V_27 . V_36 != V_37 )
V_17 |= V_38 ;
else
V_17 |= V_39 ;
break;
case V_40 :
V_17 |= V_41 ;
if ( V_14 -> V_27 . V_36 != V_37 )
V_17 |= V_42 ;
else
V_17 |= V_43 ;
break;
case V_44 :
V_17 &= ~ V_45 ;
if ( V_14 -> V_27 . V_36 != V_37 )
V_17 |= V_46 ;
else
V_17 |= V_47 ;
break;
default:
return - V_48 ;
}
if ( V_14 -> V_27 . V_36 == V_37 ) {
V_17 &= ~ V_49 ;
V_17 |= V_50 ;
V_17 |= ( V_14 -> V_51 << 16 &
V_31 ) ;
} else {
V_17 |= V_49 ;
V_17 &= ~ V_50 ;
V_17 |= ( V_14 -> V_51 << 24 &
V_32 ) ;
}
F_12 ( V_17 , V_14 -> V_21 + V_22 ) ;
return 0 ;
}
static int F_17 ( struct V_2 * V_3 , enum V_52 V_53 ,
unsigned long V_54 )
{
int V_55 = 0 ;
switch ( V_53 ) {
case V_56 :
case V_57 :
return - V_48 ;
case V_58 :
F_7 ( V_3 ) ;
break;
case V_59 :
V_55 = F_16 ( V_3 , (struct V_26 * ) V_54 ) ;
break;
default:
V_55 = - V_60 ;
}
return V_55 ;
}
static struct V_9 * F_18 (
struct V_2 * V_3 , struct V_61 * V_62 ,
unsigned int V_63 , enum V_64 V_65 ,
unsigned long V_66 , void * V_67 )
{
struct V_5 * V_14 = F_2 ( V_3 ) ;
struct V_8 * V_68 ;
enum V_69 V_70 ;
T_2 V_71 ;
struct V_61 * V_72 ;
unsigned int V_73 ;
unsigned int V_74 ;
if ( ! F_19 ( V_65 ) ) {
F_20 ( F_1 ( V_3 ) , L_2 ,
V_18 ) ;
return NULL ;
}
if ( V_65 == V_75 ) {
V_71 = V_14 -> V_27 . V_76 ;
V_70 = V_14 -> V_27 . V_33 ;
} else {
V_71 = V_14 -> V_27 . V_77 ;
V_70 = V_14 -> V_27 . V_78 ;
}
switch ( V_70 ) {
case V_34 :
V_73 = V_79 ;
break;
case V_40 :
V_73 = V_80 ;
break;
case V_44 :
V_73 = V_81 ;
break;
default:
F_20 ( F_1 ( V_3 ) , L_3 ,
V_18 , V_70 ) ;
return NULL ;
}
V_68 = F_21 ( sizeof( * V_68 ) + V_63 * sizeof( V_68 -> V_82 [ 0 ] ) , V_83 ) ;
if ( ! V_68 )
return NULL ;
V_68 -> V_84 = V_65 ;
V_68 -> V_71 = V_71 ;
V_68 -> V_73 = V_73 ;
F_22 (sgl, sgent, sg_len, i) {
V_68 -> V_82 [ V_74 ] . V_85 = F_23 ( V_72 ) ;
V_68 -> V_82 [ V_74 ] . V_86 = F_24 ( V_72 ) ;
}
V_68 -> V_87 = V_63 ;
V_14 -> error = 0 ;
return F_25 ( & V_14 -> V_7 , & V_68 -> V_11 , V_66 ) ;
}
static struct V_2 * F_26 ( struct V_88 * V_89 ,
struct V_90 * V_91 )
{
struct V_92 * V_93 = V_91 -> V_94 ;
struct V_2 * V_3 ;
struct V_5 * V_14 ;
V_3 = F_27 ( & V_93 -> V_95 ) ;
if ( ! V_3 )
return NULL ;
V_14 = F_2 ( V_3 ) ;
V_14 -> V_51 = V_89 -> args [ 0 ] ;
return V_3 ;
}
static int F_28 ( struct V_2 * V_3 )
{
struct V_5 * V_14 = F_2 ( V_3 ) ;
F_9 ( F_1 ( V_3 ) , L_4 ,
V_18 , V_14 -> V_96 ) ;
V_14 -> V_97 = 1 ;
return 0 ;
}
static void F_29 ( struct V_2 * V_3 )
{
struct V_5 * V_14 = F_2 ( V_3 ) ;
F_30 ( & V_14 -> V_7 ) ;
F_9 ( F_1 ( V_3 ) , L_5 ,
V_18 , V_14 -> V_96 ) ;
V_14 -> V_97 = 0 ;
}
static void F_31 ( struct V_5 * V_14 , T_2 V_76 ,
T_2 V_77 )
{
F_12 ( V_76 , V_14 -> V_21 + V_98 ) ;
F_12 ( V_77 , V_14 -> V_21 + V_99 ) ;
}
static void F_32 ( struct V_5 * V_14 , unsigned int V_86 )
{
struct V_8 * V_68 = V_14 -> V_20 ;
unsigned int V_100 = V_101 [ V_68 -> V_73 ] ;
V_68 -> V_102 = V_86 >> V_100 ;
F_12 ( V_68 -> V_102 , V_14 -> V_21 + V_103 ) ;
F_9 ( F_1 ( & V_14 -> V_7 . V_3 ) , L_6 ,
V_18 , V_68 -> V_102 , V_86 ) ;
}
static void F_33 ( struct V_5 * V_14 )
{
T_1 V_17 ;
V_17 = F_11 ( V_14 -> V_21 + V_22 ) ;
V_17 |= ( V_23 | V_24 | V_25 ) ;
F_12 ( V_17 , V_14 -> V_21 + V_22 ) ;
}
static void F_34 ( struct V_5 * V_14 , unsigned int V_104 )
{
struct V_8 * V_68 = V_14 -> V_20 ;
struct V_105 * V_82 = V_14 -> V_20 -> V_82 + V_104 ;
if ( V_14 -> V_20 -> V_84 == V_37 )
F_31 ( V_14 , V_82 -> V_85 , V_68 -> V_71 ) ;
else if ( V_14 -> V_20 -> V_84 == V_75 )
F_31 ( V_14 , V_68 -> V_71 , V_82 -> V_85 ) ;
F_32 ( V_14 , V_82 -> V_86 ) ;
F_33 ( V_14 ) ;
}
static void F_35 ( struct V_2 * V_3 )
{
struct V_5 * V_14 = F_2 ( V_3 ) ;
struct V_13 * V_11 ;
V_11 = F_36 ( & V_14 -> V_7 ) ;
if ( ! V_11 ) {
V_14 -> V_20 = NULL ;
return;
}
F_37 ( & V_11 -> V_106 ) ;
V_14 -> V_20 = F_4 ( & V_11 -> V_12 ) ;
V_14 -> V_107 = 0 ;
F_34 ( V_14 , 0 ) ;
}
static void F_38 ( struct V_2 * V_3 )
{
struct V_5 * V_14 = F_2 ( V_3 ) ;
unsigned long V_15 ;
F_10 ( & V_14 -> V_7 . V_19 , V_15 ) ;
if ( F_39 ( & V_14 -> V_7 ) && ! V_14 -> V_20 )
F_35 ( V_3 ) ;
F_14 ( & V_14 -> V_7 . V_19 , V_15 ) ;
}
static T_3 F_40 ( struct V_8 * V_68 ,
unsigned int V_108 )
{
unsigned int V_74 ;
T_3 V_109 ;
for ( V_109 = V_74 = V_108 ; V_74 < V_68 -> V_87 ; V_74 ++ )
V_109 += V_68 -> V_82 [ V_74 ] . V_86 ;
return V_109 ;
}
static T_3 F_41 ( struct V_5 * V_14 )
{
T_3 V_109 ;
unsigned int V_110 , V_111 ;
V_109 = F_40 ( V_14 -> V_20 , V_14 -> V_107 ) ;
V_111 = F_11 ( V_14 -> V_21 + V_103 ) ;
V_110 = ( V_14 -> V_20 -> V_102 - V_111 ) ;
V_109 -= V_110 << V_101 [ V_14 -> V_20 -> V_73 ] ;
F_9 ( F_1 ( & V_14 -> V_7 . V_3 ) , L_7 , V_18 , V_109 ) ;
return V_109 ;
}
static enum V_112 F_42 ( struct V_2 * V_3 ,
T_4 V_113 ,
struct V_114 * V_115 )
{
struct V_5 * V_14 = F_2 ( V_3 ) ;
struct V_13 * V_11 ;
struct V_8 * V_68 ;
enum V_112 V_55 ;
unsigned long V_15 ;
V_55 = F_43 ( V_3 , V_113 , V_115 ) ;
F_10 ( & V_14 -> V_7 . V_19 , V_15 ) ;
V_11 = F_44 ( & V_14 -> V_7 , V_113 ) ;
if ( V_11 ) {
V_68 = F_4 ( & V_11 -> V_12 ) ;
V_115 -> V_116 = F_40 ( V_68 , 0 ) ;
} else if ( V_14 -> V_20 && V_14 -> V_20 -> V_11 . V_12 . V_113 == V_113 ) {
V_115 -> V_116 = F_41 ( V_14 ) ;
}
F_14 ( & V_14 -> V_7 . V_19 , V_15 ) ;
if ( V_14 -> error )
return V_117 ;
return V_55 ;
}
static void F_45 ( struct V_118 * V_119 , struct V_1 * V_4 )
{
V_119 -> V_120 = F_18 ;
V_119 -> V_121 = F_28 ;
V_119 -> V_122 = F_29 ;
V_119 -> V_123 = F_38 ;
V_119 -> V_124 = F_42 ;
V_119 -> V_125 = F_17 ;
V_119 -> V_4 = V_4 ;
F_46 ( & V_119 -> V_126 ) ;
}
static T_5 F_47 ( int V_127 , void * V_128 )
{
struct V_92 * V_129 = V_128 ;
struct V_5 * V_14 = & V_129 -> V_130 [ 0 ] ;
unsigned int V_74 ;
unsigned long V_15 ;
T_1 V_17 ;
F_9 ( F_1 ( & V_14 -> V_7 . V_3 ) , L_8 , V_18 ) ;
for ( V_74 = 0 ; V_74 < V_131 ; V_74 ++ , V_14 ++ ) {
if ( ! V_14 -> V_97 )
continue;
V_17 = F_11 ( V_14 -> V_21 + V_22 ) ;
F_9 ( F_1 ( & V_14 -> V_7 . V_3 ) , L_9 ,
V_18 , V_14 , V_14 -> V_21 , V_17 ) ;
if ( V_17 & V_132 ) {
V_17 &= ~ V_132 ;
if ( V_14 -> V_20 ) {
F_10 ( & V_14 -> V_7 . V_19 , V_15 ) ;
if ( ++ V_14 -> V_107 < V_14 -> V_20 -> V_87 ) {
F_34 ( V_14 , V_14 -> V_107 ) ;
} else {
F_48 ( & V_14 -> V_20 -> V_11 ) ;
F_35 ( & V_14 -> V_7 . V_3 ) ;
}
F_14 ( & V_14 -> V_7 . V_19 , V_15 ) ;
}
}
if ( V_17 & V_133 ) {
V_17 &= ~ V_133 ;
V_14 -> error = 1 ;
}
F_12 ( V_17 , V_14 -> V_21 + V_22 ) ;
}
return V_134 ;
}
static int F_49 ( struct V_135 * V_136 )
{
struct V_1 * V_4 = & V_136 -> V_4 ;
struct V_137 * V_106 = V_4 -> V_138 ;
struct V_139 * V_140 ;
static void T_6 * V_141 ;
int V_55 , V_74 ;
unsigned int V_127 ;
struct V_5 * V_14 ;
struct V_92 * V_93 ;
V_93 = F_50 ( V_4 , sizeof( * V_93 ) , V_142 ) ;
if ( ! V_93 ) {
F_20 ( V_4 , L_10 ) ;
return - V_143 ;
}
V_127 = F_51 ( V_106 , 0 ) ;
if ( V_127 == V_144 ) {
F_20 ( V_4 , L_11 ) ;
return - V_48 ;
}
V_140 = F_52 ( V_136 , V_145 , 0 ) ;
V_141 = F_53 ( V_4 , V_140 ) ;
if ( F_54 ( V_141 ) )
return F_55 ( V_141 ) ;
F_56 ( V_93 -> V_95 . V_146 ) ;
F_57 ( V_147 , V_93 -> V_95 . V_146 ) ;
F_57 ( V_148 , V_93 -> V_95 . V_146 ) ;
F_45 ( & V_93 -> V_95 , V_4 ) ;
V_14 = & V_93 -> V_130 [ 0 ] ;
for ( V_74 = 0 ; V_74 < V_131 ; V_74 ++ , V_14 ++ ) {
V_14 -> V_96 = V_74 ;
V_14 -> V_21 = V_141 + V_74 * V_149 ;
V_14 -> V_97 = 0 ;
V_14 -> V_7 . V_150 = F_5 ;
F_58 ( & V_14 -> V_7 , & V_93 -> V_95 ) ;
F_9 ( V_4 , L_12 ,
V_18 , V_74 , V_14 -> V_96 , V_14 -> V_21 ) ;
}
F_59 ( V_136 , V_93 ) ;
V_55 = F_60 ( V_4 , V_127 , F_47 , 0 ,
L_13 , V_93 ) ;
if ( V_55 ) {
F_20 ( V_4 , L_14 ) ;
return V_55 ;
}
V_55 = F_61 ( & V_93 -> V_95 ) ;
if ( V_55 ) {
F_20 ( V_4 , L_15 ) ;
return V_55 ;
}
V_55 = F_62 ( V_106 , F_26 , V_93 ) ;
if ( V_55 ) {
F_20 ( V_4 , L_16 ) ;
F_63 ( & V_93 -> V_95 ) ;
return V_55 ;
}
F_9 ( V_4 , L_17 , V_18 , V_127 ) ;
return 0 ;
}
static int F_64 ( struct V_135 * V_136 )
{
struct V_92 * V_151 = F_65 ( V_136 ) ;
F_63 ( & V_151 -> V_95 ) ;
if ( V_136 -> V_4 . V_138 )
F_66 ( V_136 -> V_4 . V_138 ) ;
return 0 ;
}
static int F_67 ( void )
{
return F_68 ( & V_152 ) ;
}
static void T_7 F_69 ( void )
{
F_70 ( & V_152 ) ;
}
