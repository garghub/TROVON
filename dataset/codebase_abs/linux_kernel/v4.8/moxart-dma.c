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
if ( V_14 -> V_20 ) {
F_5 ( & V_14 -> V_20 -> V_11 ) ;
V_14 -> V_20 = NULL ;
}
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
static struct V_9 * F_17 (
struct V_2 * V_3 , struct V_52 * V_53 ,
unsigned int V_54 , enum V_55 V_56 ,
unsigned long V_57 , void * V_58 )
{
struct V_5 * V_14 = F_2 ( V_3 ) ;
struct V_8 * V_59 ;
enum V_60 V_61 ;
T_2 V_62 ;
struct V_52 * V_63 ;
unsigned int V_64 ;
unsigned int V_65 ;
if ( ! F_18 ( V_56 ) ) {
F_19 ( F_1 ( V_3 ) , L_2 ,
V_18 ) ;
return NULL ;
}
if ( V_56 == V_66 ) {
V_62 = V_14 -> V_27 . V_67 ;
V_61 = V_14 -> V_27 . V_33 ;
} else {
V_62 = V_14 -> V_27 . V_68 ;
V_61 = V_14 -> V_27 . V_69 ;
}
switch ( V_61 ) {
case V_34 :
V_64 = V_70 ;
break;
case V_40 :
V_64 = V_71 ;
break;
case V_44 :
V_64 = V_72 ;
break;
default:
F_19 ( F_1 ( V_3 ) , L_3 ,
V_18 , V_61 ) ;
return NULL ;
}
V_59 = F_20 ( sizeof( * V_59 ) + V_54 * sizeof( V_59 -> V_73 [ 0 ] ) , V_74 ) ;
if ( ! V_59 )
return NULL ;
V_59 -> V_75 = V_56 ;
V_59 -> V_62 = V_62 ;
V_59 -> V_64 = V_64 ;
F_21 (sgl, sgent, sg_len, i) {
V_59 -> V_73 [ V_65 ] . V_76 = F_22 ( V_63 ) ;
V_59 -> V_73 [ V_65 ] . V_77 = F_23 ( V_63 ) ;
}
V_59 -> V_78 = V_54 ;
V_14 -> error = 0 ;
return F_24 ( & V_14 -> V_7 , & V_59 -> V_11 , V_57 ) ;
}
static struct V_2 * F_25 ( struct V_79 * V_80 ,
struct V_81 * V_82 )
{
struct V_83 * V_84 = V_82 -> V_85 ;
struct V_2 * V_3 ;
struct V_5 * V_14 ;
V_3 = F_26 ( & V_84 -> V_86 ) ;
if ( ! V_3 )
return NULL ;
V_14 = F_2 ( V_3 ) ;
V_14 -> V_51 = V_80 -> args [ 0 ] ;
return V_3 ;
}
static int F_27 ( struct V_2 * V_3 )
{
struct V_5 * V_14 = F_2 ( V_3 ) ;
F_9 ( F_1 ( V_3 ) , L_4 ,
V_18 , V_14 -> V_87 ) ;
V_14 -> V_88 = 1 ;
return 0 ;
}
static void F_28 ( struct V_2 * V_3 )
{
struct V_5 * V_14 = F_2 ( V_3 ) ;
F_29 ( & V_14 -> V_7 ) ;
F_9 ( F_1 ( V_3 ) , L_5 ,
V_18 , V_14 -> V_87 ) ;
V_14 -> V_88 = 0 ;
}
static void F_30 ( struct V_5 * V_14 , T_2 V_67 ,
T_2 V_68 )
{
F_12 ( V_67 , V_14 -> V_21 + V_89 ) ;
F_12 ( V_68 , V_14 -> V_21 + V_90 ) ;
}
static void F_31 ( struct V_5 * V_14 , unsigned int V_77 )
{
struct V_8 * V_59 = V_14 -> V_20 ;
unsigned int V_91 = V_92 [ V_59 -> V_64 ] ;
V_59 -> V_93 = V_77 >> V_91 ;
F_12 ( V_59 -> V_93 , V_14 -> V_21 + V_94 ) ;
F_9 ( F_1 ( & V_14 -> V_7 . V_3 ) , L_6 ,
V_18 , V_59 -> V_93 , V_77 ) ;
}
static void F_32 ( struct V_5 * V_14 )
{
T_1 V_17 ;
V_17 = F_11 ( V_14 -> V_21 + V_22 ) ;
V_17 |= ( V_23 | V_24 | V_25 ) ;
F_12 ( V_17 , V_14 -> V_21 + V_22 ) ;
}
static void F_33 ( struct V_5 * V_14 , unsigned int V_95 )
{
struct V_8 * V_59 = V_14 -> V_20 ;
struct V_96 * V_73 = V_14 -> V_20 -> V_73 + V_95 ;
if ( V_14 -> V_20 -> V_75 == V_37 )
F_30 ( V_14 , V_73 -> V_76 , V_59 -> V_62 ) ;
else if ( V_14 -> V_20 -> V_75 == V_66 )
F_30 ( V_14 , V_59 -> V_62 , V_73 -> V_76 ) ;
F_31 ( V_14 , V_73 -> V_77 ) ;
F_32 ( V_14 ) ;
}
static void F_34 ( struct V_2 * V_3 )
{
struct V_5 * V_14 = F_2 ( V_3 ) ;
struct V_13 * V_11 ;
V_11 = F_35 ( & V_14 -> V_7 ) ;
if ( ! V_11 ) {
V_14 -> V_20 = NULL ;
return;
}
F_36 ( & V_11 -> V_97 ) ;
V_14 -> V_20 = F_4 ( & V_11 -> V_12 ) ;
V_14 -> V_98 = 0 ;
F_33 ( V_14 , 0 ) ;
}
static void F_37 ( struct V_2 * V_3 )
{
struct V_5 * V_14 = F_2 ( V_3 ) ;
unsigned long V_15 ;
F_10 ( & V_14 -> V_7 . V_19 , V_15 ) ;
if ( F_38 ( & V_14 -> V_7 ) && ! V_14 -> V_20 )
F_34 ( V_3 ) ;
F_14 ( & V_14 -> V_7 . V_19 , V_15 ) ;
}
static T_3 F_39 ( struct V_8 * V_59 ,
unsigned int V_99 )
{
unsigned int V_65 ;
T_3 V_100 ;
for ( V_100 = V_65 = V_99 ; V_65 < V_59 -> V_78 ; V_65 ++ )
V_100 += V_59 -> V_73 [ V_65 ] . V_77 ;
return V_100 ;
}
static T_3 F_40 ( struct V_5 * V_14 )
{
T_3 V_100 ;
unsigned int V_101 , V_102 ;
V_100 = F_39 ( V_14 -> V_20 , V_14 -> V_98 ) ;
V_102 = F_11 ( V_14 -> V_21 + V_94 ) ;
V_101 = ( V_14 -> V_20 -> V_93 - V_102 ) ;
V_100 -= V_101 << V_92 [ V_14 -> V_20 -> V_64 ] ;
F_9 ( F_1 ( & V_14 -> V_7 . V_3 ) , L_7 , V_18 , V_100 ) ;
return V_100 ;
}
static enum V_103 F_41 ( struct V_2 * V_3 ,
T_4 V_104 ,
struct V_105 * V_106 )
{
struct V_5 * V_14 = F_2 ( V_3 ) ;
struct V_13 * V_11 ;
struct V_8 * V_59 ;
enum V_103 V_107 ;
unsigned long V_15 ;
V_107 = F_42 ( V_3 , V_104 , V_106 ) ;
F_10 ( & V_14 -> V_7 . V_19 , V_15 ) ;
V_11 = F_43 ( & V_14 -> V_7 , V_104 ) ;
if ( V_11 ) {
V_59 = F_4 ( & V_11 -> V_12 ) ;
V_106 -> V_108 = F_39 ( V_59 , 0 ) ;
} else if ( V_14 -> V_20 && V_14 -> V_20 -> V_11 . V_12 . V_104 == V_104 ) {
V_106 -> V_108 = F_40 ( V_14 ) ;
}
F_14 ( & V_14 -> V_7 . V_19 , V_15 ) ;
if ( V_14 -> error )
return V_109 ;
return V_107 ;
}
static void F_44 ( struct V_110 * V_111 , struct V_1 * V_4 )
{
V_111 -> V_112 = F_17 ;
V_111 -> V_113 = F_27 ;
V_111 -> V_114 = F_28 ;
V_111 -> V_115 = F_37 ;
V_111 -> V_116 = F_41 ;
V_111 -> V_117 = F_16 ;
V_111 -> V_118 = F_7 ;
V_111 -> V_4 = V_4 ;
F_45 ( & V_111 -> V_119 ) ;
}
static T_5 F_46 ( int V_120 , void * V_121 )
{
struct V_83 * V_122 = V_121 ;
struct V_5 * V_14 = & V_122 -> V_123 [ 0 ] ;
unsigned int V_65 ;
unsigned long V_15 ;
T_1 V_17 ;
F_9 ( F_1 ( & V_14 -> V_7 . V_3 ) , L_8 , V_18 ) ;
for ( V_65 = 0 ; V_65 < V_124 ; V_65 ++ , V_14 ++ ) {
if ( ! V_14 -> V_88 )
continue;
V_17 = F_11 ( V_14 -> V_21 + V_22 ) ;
F_9 ( F_1 ( & V_14 -> V_7 . V_3 ) , L_9 ,
V_18 , V_14 , V_14 -> V_21 , V_17 ) ;
if ( V_17 & V_125 ) {
V_17 &= ~ V_125 ;
if ( V_14 -> V_20 ) {
F_10 ( & V_14 -> V_7 . V_19 , V_15 ) ;
if ( ++ V_14 -> V_98 < V_14 -> V_20 -> V_78 ) {
F_33 ( V_14 , V_14 -> V_98 ) ;
} else {
F_47 ( & V_14 -> V_20 -> V_11 ) ;
F_34 ( & V_14 -> V_7 . V_3 ) ;
}
F_14 ( & V_14 -> V_7 . V_19 , V_15 ) ;
}
}
if ( V_17 & V_126 ) {
V_17 &= ~ V_126 ;
V_14 -> error = 1 ;
}
F_12 ( V_17 , V_14 -> V_21 + V_22 ) ;
}
return V_127 ;
}
static int F_48 ( struct V_128 * V_129 )
{
struct V_1 * V_4 = & V_129 -> V_4 ;
struct V_130 * V_97 = V_4 -> V_131 ;
struct V_132 * V_133 ;
static void T_6 * V_134 ;
int V_107 , V_65 ;
unsigned int V_120 ;
struct V_5 * V_14 ;
struct V_83 * V_84 ;
V_84 = F_49 ( V_4 , sizeof( * V_84 ) , V_135 ) ;
if ( ! V_84 )
return - V_136 ;
V_120 = F_50 ( V_97 , 0 ) ;
if ( V_120 == V_137 ) {
F_19 ( V_4 , L_10 ) ;
return - V_48 ;
}
V_133 = F_51 ( V_129 , V_138 , 0 ) ;
V_134 = F_52 ( V_4 , V_133 ) ;
if ( F_53 ( V_134 ) )
return F_54 ( V_134 ) ;
F_55 ( V_84 -> V_86 . V_139 ) ;
F_56 ( V_140 , V_84 -> V_86 . V_139 ) ;
F_56 ( V_141 , V_84 -> V_86 . V_139 ) ;
F_44 ( & V_84 -> V_86 , V_4 ) ;
V_14 = & V_84 -> V_123 [ 0 ] ;
for ( V_65 = 0 ; V_65 < V_124 ; V_65 ++ , V_14 ++ ) {
V_14 -> V_87 = V_65 ;
V_14 -> V_21 = V_134 + V_65 * V_142 ;
V_14 -> V_88 = 0 ;
V_14 -> V_7 . V_143 = F_5 ;
F_57 ( & V_14 -> V_7 , & V_84 -> V_86 ) ;
F_9 ( V_4 , L_11 ,
V_18 , V_65 , V_14 -> V_87 , V_14 -> V_21 ) ;
}
F_58 ( V_129 , V_84 ) ;
V_107 = F_59 ( V_4 , V_120 , F_46 , 0 ,
L_12 , V_84 ) ;
if ( V_107 ) {
F_19 ( V_4 , L_13 ) ;
return V_107 ;
}
V_84 -> V_120 = V_120 ;
V_107 = F_60 ( & V_84 -> V_86 ) ;
if ( V_107 ) {
F_19 ( V_4 , L_14 ) ;
return V_107 ;
}
V_107 = F_61 ( V_97 , F_25 , V_84 ) ;
if ( V_107 ) {
F_19 ( V_4 , L_15 ) ;
F_62 ( & V_84 -> V_86 ) ;
return V_107 ;
}
F_9 ( V_4 , L_16 , V_18 , V_120 ) ;
return 0 ;
}
static int F_63 ( struct V_128 * V_129 )
{
struct V_83 * V_144 = F_64 ( V_129 ) ;
F_65 ( & V_129 -> V_4 , V_144 -> V_120 , V_144 ) ;
F_62 ( & V_144 -> V_86 ) ;
if ( V_129 -> V_4 . V_131 )
F_66 ( V_129 -> V_4 . V_131 ) ;
return 0 ;
}
static int F_67 ( void )
{
return F_68 ( & V_145 ) ;
}
static void T_7 F_69 ( void )
{
F_70 ( & V_145 ) ;
}
