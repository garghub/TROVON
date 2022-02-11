static struct V_1 * F_1 ( struct V_2 * V_3 )
{
return F_2 ( V_3 -> V_4 . V_3 . V_5 , struct V_1 ,
V_6 ) ;
}
static struct V_2 * F_3 ( struct V_7 * V_8 )
{
return F_2 ( V_8 , struct V_2 , V_4 . V_3 ) ;
}
static struct V_9 * F_4 ( struct V_10 * V_11 )
{
return F_2 ( V_11 , struct V_9 , V_11 ) ;
}
static void F_5 ( struct V_1 * V_1 , unsigned int V_12 ,
unsigned int V_13 )
{
F_6 ( V_13 , V_1 -> V_14 + V_12 ) ;
}
static int F_7 ( struct V_1 * V_1 , unsigned int V_12 )
{
return F_8 ( V_1 -> V_14 + V_12 ) ;
}
static int F_9 ( struct V_2 * V_3 )
{
return V_3 -> V_15 == V_16 ;
}
static int F_10 ( struct V_2 * V_3 )
{
return V_3 -> V_17 == V_16 ;
}
static bool F_11 ( struct V_2 * V_3 , unsigned int V_18 )
{
if ( V_18 == 0 || V_18 > V_3 -> V_19 )
return false ;
if ( ( V_18 & V_3 -> V_20 ) != 0 )
return false ;
return true ;
}
static bool F_12 ( struct V_2 * V_3 , T_1 V_21 )
{
if ( ( V_21 & V_3 -> V_20 ) != 0 )
return false ;
return true ;
}
static void F_13 ( struct V_2 * V_3 )
{
struct V_1 * V_22 = F_1 ( V_3 ) ;
struct V_10 * V_11 ;
struct V_9 * V_23 ;
struct V_24 * V_25 ;
unsigned int V_26 = 0 ;
unsigned int V_13 ;
V_13 = F_7 ( V_22 , V_27 ) ;
if ( V_13 )
return;
V_23 = V_3 -> V_28 ;
if ( ! V_23 ) {
V_11 = F_14 ( & V_3 -> V_4 ) ;
if ( ! V_11 )
return;
F_15 ( & V_11 -> V_29 , & V_3 -> V_30 ) ;
V_23 = F_4 ( V_11 ) ;
}
V_25 = & V_23 -> V_25 [ V_23 -> V_31 ] ;
V_23 -> V_31 ++ ;
if ( V_23 -> V_31 == V_23 -> V_32 )
V_3 -> V_28 = NULL ;
else
V_3 -> V_28 = V_23 ;
V_25 -> V_33 = F_7 ( V_22 , V_34 ) ;
if ( F_10 ( V_3 ) ) {
F_5 ( V_22 , V_35 , V_25 -> V_36 ) ;
F_5 ( V_22 , V_37 , V_25 -> V_38 ) ;
}
if ( F_9 ( V_3 ) ) {
F_5 ( V_22 , V_39 , V_25 -> V_40 ) ;
F_5 ( V_22 , V_41 , V_25 -> V_42 ) ;
}
if ( V_3 -> V_43 && V_23 -> V_44 && ! V_23 -> V_11 . V_45 . V_46 )
V_26 |= V_47 ;
F_5 ( V_22 , V_48 , V_25 -> V_49 - 1 ) ;
F_5 ( V_22 , V_50 , V_25 -> V_51 - 1 ) ;
F_5 ( V_22 , V_52 , V_26 ) ;
F_5 ( V_22 , V_27 , 1 ) ;
}
static struct V_9 * F_16 ( struct V_2 * V_3 )
{
return F_17 ( & V_3 -> V_30 ,
struct V_9 , V_11 . V_29 ) ;
}
static void F_18 ( struct V_2 * V_3 ,
unsigned int V_53 )
{
struct V_9 * V_54 ;
struct V_24 * V_25 ;
V_54 = F_16 ( V_3 ) ;
if ( ! V_54 )
return;
if ( V_54 -> V_44 ) {
F_19 ( & V_54 -> V_11 ) ;
} else {
do {
V_25 = & V_54 -> V_25 [ V_54 -> V_55 ] ;
if ( ! ( F_20 ( V_25 -> V_33 ) & V_53 ) )
break;
V_54 -> V_55 ++ ;
if ( V_54 -> V_55 == V_54 -> V_32 ) {
F_21 ( & V_54 -> V_11 . V_29 ) ;
F_22 ( & V_54 -> V_11 ) ;
V_54 = F_16 ( V_3 ) ;
}
} while ( V_54 );
}
}
static T_2 F_23 ( int V_56 , void * V_57 )
{
struct V_1 * V_22 = V_57 ;
unsigned int V_58 ;
V_58 = F_7 ( V_22 , V_59 ) ;
if ( ! V_58 )
return V_60 ;
F_5 ( V_22 , V_59 , V_58 ) ;
F_24 ( & V_22 -> V_3 . V_4 . V_61 ) ;
if ( V_58 & V_62 ) {
unsigned int V_63 ;
V_63 = F_7 ( V_22 , V_64 ) ;
F_18 ( & V_22 -> V_3 , V_63 ) ;
}
if ( V_58 & V_65 )
F_13 ( & V_22 -> V_3 ) ;
F_25 ( & V_22 -> V_3 . V_4 . V_61 ) ;
return V_66 ;
}
static int F_26 ( struct V_7 * V_8 )
{
struct V_2 * V_3 = F_3 ( V_8 ) ;
struct V_1 * V_22 = F_1 ( V_3 ) ;
unsigned long V_26 ;
F_27 ( V_67 ) ;
F_28 ( & V_3 -> V_4 . V_61 , V_26 ) ;
F_5 ( V_22 , V_68 , 0 ) ;
V_3 -> V_28 = NULL ;
F_29 ( & V_3 -> V_4 , & V_67 ) ;
F_30 ( & V_3 -> V_30 , & V_67 ) ;
F_31 ( & V_3 -> V_4 . V_61 , V_26 ) ;
F_32 ( & V_3 -> V_4 , & V_67 ) ;
return 0 ;
}
static void F_33 ( struct V_7 * V_8 )
{
struct V_2 * V_3 = F_3 ( V_8 ) ;
F_34 ( & V_3 -> V_4 ) ;
}
static void F_35 ( struct V_7 * V_8 )
{
struct V_2 * V_3 = F_3 ( V_8 ) ;
struct V_1 * V_22 = F_1 ( V_3 ) ;
unsigned long V_26 ;
F_5 ( V_22 , V_68 , V_69 ) ;
F_28 ( & V_3 -> V_4 . V_61 , V_26 ) ;
if ( F_36 ( & V_3 -> V_4 ) )
F_13 ( V_3 ) ;
F_31 ( & V_3 -> V_4 . V_61 , V_26 ) ;
}
static struct V_9 * F_37 ( unsigned int V_32 )
{
struct V_9 * V_23 ;
V_23 = F_38 ( sizeof( struct V_9 ) +
sizeof( struct V_24 ) * V_32 , V_70 ) ;
if ( ! V_23 )
return NULL ;
V_23 -> V_32 = V_32 ;
return V_23 ;
}
static struct V_71 * F_39 (
struct V_7 * V_8 , struct V_72 * V_73 ,
unsigned int V_74 , enum V_75 V_76 ,
unsigned long V_26 , void * V_77 )
{
struct V_2 * V_3 = F_3 ( V_8 ) ;
struct V_9 * V_23 ;
struct V_72 * V_25 ;
unsigned int V_78 ;
if ( V_76 != V_3 -> V_76 )
return NULL ;
V_23 = F_37 ( V_74 ) ;
if ( ! V_23 )
return NULL ;
F_40 (sgl, sg, sg_len, i) {
if ( ! F_12 ( V_3 , F_41 ( V_25 ) ) ||
! F_11 ( V_3 , F_42 ( V_25 ) ) ) {
F_43 ( V_23 ) ;
return NULL ;
}
if ( V_76 == V_79 )
V_23 -> V_25 [ V_78 ] . V_36 = F_41 ( V_25 ) ;
else
V_23 -> V_25 [ V_78 ] . V_40 = F_41 ( V_25 ) ;
V_23 -> V_25 [ V_78 ] . V_49 = F_42 ( V_25 ) ;
V_23 -> V_25 [ V_78 ] . V_51 = 1 ;
}
V_23 -> V_44 = false ;
return F_44 ( & V_3 -> V_4 , & V_23 -> V_11 , V_26 ) ;
}
static struct V_71 * F_45 (
struct V_7 * V_8 , T_1 V_80 , T_3 V_81 ,
T_3 V_82 , enum V_75 V_76 ,
unsigned long V_26 )
{
struct V_2 * V_3 = F_3 ( V_8 ) ;
struct V_9 * V_23 ;
unsigned int V_83 , V_78 ;
if ( V_76 != V_3 -> V_76 )
return NULL ;
if ( ! F_11 ( V_3 , V_81 ) ||
! F_12 ( V_3 , V_80 ) )
return NULL ;
if ( V_82 == 0 || V_81 % V_82 )
return NULL ;
V_83 = V_81 / V_82 ;
V_23 = F_37 ( V_83 ) ;
if ( ! V_23 )
return NULL ;
for ( V_78 = 0 ; V_78 < V_83 ; V_78 ++ ) {
if ( V_76 == V_79 )
V_23 -> V_25 [ V_78 ] . V_36 = V_80 ;
else
V_23 -> V_25 [ V_78 ] . V_40 = V_80 ;
V_23 -> V_25 [ V_78 ] . V_49 = V_82 ;
V_23 -> V_25 [ V_78 ] . V_51 = 1 ;
V_80 += V_82 ;
}
V_23 -> V_44 = true ;
return F_44 ( & V_3 -> V_4 , & V_23 -> V_11 , V_26 ) ;
}
static struct V_71 * F_46 (
struct V_7 * V_8 , struct V_84 * V_85 ,
unsigned long V_26 )
{
struct V_2 * V_3 = F_3 ( V_8 ) ;
struct V_9 * V_23 ;
T_3 V_86 , V_87 ;
if ( V_85 -> V_88 != 1 )
return NULL ;
if ( V_85 -> V_89 != V_3 -> V_76 )
return NULL ;
if ( F_9 ( V_3 ) ) {
if ( ! V_85 -> V_90 || ! F_12 ( V_3 , V_85 -> V_91 ) )
return NULL ;
}
if ( F_10 ( V_3 ) ) {
if ( ! V_85 -> V_92 || ! F_12 ( V_3 , V_85 -> V_93 ) )
return NULL ;
}
V_86 = F_47 ( V_85 , & V_85 -> V_73 [ 0 ] ) ;
V_87 = F_48 ( V_85 , & V_85 -> V_73 [ 0 ] ) ;
if ( V_3 -> V_94 ) {
if ( ! F_11 ( V_3 , V_85 -> V_73 [ 0 ] . V_95 ) ||
! F_11 ( V_3 , V_85 -> V_96 ) )
return NULL ;
if ( V_85 -> V_73 [ 0 ] . V_95 + V_86 > V_3 -> V_19 ||
V_85 -> V_73 [ 0 ] . V_95 + V_87 > V_3 -> V_19 )
return NULL ;
} else {
if ( V_86 != 0 || V_87 != 0 )
return NULL ;
if ( V_3 -> V_19 / V_85 -> V_73 [ 0 ] . V_95 < V_85 -> V_96 )
return NULL ;
if ( ! F_11 ( V_3 , V_85 -> V_73 [ 0 ] . V_95 * V_85 -> V_96 ) )
return NULL ;
}
V_23 = F_37 ( 1 ) ;
if ( ! V_23 )
return NULL ;
if ( F_9 ( V_3 ) ) {
V_23 -> V_25 [ 0 ] . V_40 = V_85 -> V_91 ;
V_23 -> V_25 [ 0 ] . V_42 = V_85 -> V_73 [ 0 ] . V_95 + V_87 ;
}
if ( F_10 ( V_3 ) ) {
V_23 -> V_25 [ 0 ] . V_36 = V_85 -> V_93 ;
V_23 -> V_25 [ 0 ] . V_38 = V_85 -> V_73 [ 0 ] . V_95 + V_86 ;
}
if ( V_3 -> V_94 ) {
V_23 -> V_25 [ 0 ] . V_49 = V_85 -> V_73 [ 0 ] . V_95 ;
V_23 -> V_25 [ 0 ] . V_51 = V_85 -> V_96 ;
} else {
V_23 -> V_25 [ 0 ] . V_49 = V_85 -> V_73 [ 0 ] . V_95 * V_85 -> V_96 ;
V_23 -> V_25 [ 0 ] . V_51 = 1 ;
}
return F_44 ( & V_3 -> V_4 , & V_23 -> V_11 , V_26 ) ;
}
static void F_49 ( struct V_7 * V_8 )
{
F_50 ( F_51 ( V_8 ) ) ;
}
static void F_52 ( struct V_10 * V_11 )
{
F_43 ( F_2 ( V_11 , struct V_9 , V_11 ) ) ;
}
static int F_53 ( struct V_97 * V_98 ,
struct V_2 * V_3 )
{
T_4 V_13 ;
int V_99 ;
V_99 = F_54 ( V_98 , L_1 , & V_13 ) ;
if ( V_99 )
return V_99 ;
if ( V_13 != 0 )
return - V_100 ;
V_99 = F_54 ( V_98 , L_2 , & V_13 ) ;
if ( V_99 )
return V_99 ;
if ( V_13 > V_101 )
return - V_100 ;
V_3 -> V_15 = V_13 ;
V_99 = F_54 ( V_98 , L_3 , & V_13 ) ;
if ( V_99 )
return V_99 ;
if ( V_13 > V_101 )
return - V_100 ;
V_3 -> V_17 = V_13 ;
V_99 = F_54 ( V_98 , L_4 , & V_13 ) ;
if ( V_99 )
return V_99 ;
V_3 -> V_102 = V_13 / 8 ;
V_99 = F_54 ( V_98 , L_5 , & V_13 ) ;
if ( V_99 )
return V_99 ;
V_3 -> V_103 = V_13 / 8 ;
V_99 = F_54 ( V_98 , L_6 , & V_13 ) ;
if ( V_99 )
return V_99 ;
if ( V_13 >= 32 )
V_3 -> V_19 = V_104 ;
else
V_3 -> V_19 = ( 1ULL << V_13 ) - 1 ;
V_3 -> V_20 = F_55 ( V_3 -> V_103 , V_3 -> V_102 ) - 1 ;
if ( F_10 ( V_3 ) && F_9 ( V_3 ) )
V_3 -> V_76 = V_105 ;
else if ( ! F_10 ( V_3 ) && F_9 ( V_3 ) )
V_3 -> V_76 = V_106 ;
else if ( F_10 ( V_3 ) && ! F_9 ( V_3 ) )
V_3 -> V_76 = V_79 ;
else
V_3 -> V_76 = V_107 ;
V_3 -> V_43 = F_56 ( V_98 , L_7 ) ;
V_3 -> V_94 = F_56 ( V_98 , L_8 ) ;
return 0 ;
}
static int F_57 ( struct V_108 * V_109 )
{
struct V_97 * V_110 , * V_98 ;
struct V_111 * V_6 ;
struct V_1 * V_22 ;
struct V_112 * V_113 ;
int V_99 ;
V_22 = F_58 ( & V_109 -> V_114 , sizeof( * V_22 ) , V_115 ) ;
if ( ! V_22 )
return - V_116 ;
V_22 -> V_56 = F_59 ( V_109 , 0 ) ;
if ( V_22 -> V_56 < 0 )
return V_22 -> V_56 ;
if ( V_22 -> V_56 == 0 )
return - V_100 ;
V_113 = F_60 ( V_109 , V_117 , 0 ) ;
V_22 -> V_14 = F_61 ( & V_109 -> V_114 , V_113 ) ;
if ( F_62 ( V_22 -> V_14 ) )
return F_63 ( V_22 -> V_14 ) ;
V_22 -> V_118 = F_64 ( & V_109 -> V_114 , NULL ) ;
if ( F_62 ( V_22 -> V_118 ) )
return F_63 ( V_22 -> V_118 ) ;
F_65 ( & V_22 -> V_3 . V_30 ) ;
V_110 = F_66 ( V_109 -> V_114 . V_119 , L_9 ) ;
if ( V_110 == NULL )
return - V_120 ;
F_67 (of_channels, of_chan) {
V_99 = F_53 ( V_98 , & V_22 -> V_3 ) ;
if ( V_99 ) {
F_68 ( V_98 ) ;
F_68 ( V_110 ) ;
return - V_100 ;
}
}
F_68 ( V_110 ) ;
V_109 -> V_114 . V_121 = & V_22 -> V_121 ;
F_69 ( & V_109 -> V_114 , V_22 -> V_3 . V_19 ) ;
V_6 = & V_22 -> V_6 ;
F_70 ( V_122 , V_6 -> V_123 ) ;
F_70 ( V_124 , V_6 -> V_123 ) ;
V_6 -> V_125 = F_49 ;
V_6 -> V_126 = V_127 ;
V_6 -> V_128 = F_35 ;
V_6 -> V_129 = F_39 ;
V_6 -> V_130 = F_45 ;
V_6 -> V_131 = F_46 ;
V_6 -> V_132 = F_26 ;
V_6 -> V_133 = F_33 ;
V_6 -> V_114 = & V_109 -> V_114 ;
V_6 -> V_134 = 1 ;
V_6 -> V_135 = F_20 ( V_22 -> V_3 . V_102 ) ;
V_6 -> V_136 = F_20 ( V_22 -> V_3 . V_103 ) ;
V_6 -> V_137 = F_20 ( V_22 -> V_3 . V_76 ) ;
V_6 -> V_138 = V_139 ;
F_65 ( & V_6 -> V_140 ) ;
V_22 -> V_3 . V_4 . V_141 = F_52 ;
F_71 ( & V_22 -> V_3 . V_4 , V_6 ) ;
V_99 = F_72 ( V_22 -> V_118 ) ;
if ( V_99 < 0 )
return V_99 ;
F_5 ( V_22 , V_142 , 0x00 ) ;
V_99 = F_73 ( V_6 ) ;
if ( V_99 )
goto V_143;
V_99 = F_74 ( V_109 -> V_114 . V_119 ,
V_144 , V_6 ) ;
if ( V_99 )
goto V_145;
V_99 = F_75 ( V_22 -> V_56 , F_23 , 0 ,
F_76 ( & V_109 -> V_114 ) , V_22 ) ;
if ( V_99 )
goto V_146;
F_77 ( V_109 , V_22 ) ;
return 0 ;
V_146:
F_78 ( V_109 -> V_114 . V_119 ) ;
V_145:
F_79 ( & V_22 -> V_6 ) ;
V_143:
F_80 ( V_22 -> V_118 ) ;
return V_99 ;
}
static int F_81 ( struct V_108 * V_109 )
{
struct V_1 * V_22 = F_82 ( V_109 ) ;
F_78 ( V_109 -> V_114 . V_119 ) ;
F_83 ( V_22 -> V_56 , V_22 ) ;
F_84 ( & V_22 -> V_3 . V_4 . V_147 ) ;
F_79 ( & V_22 -> V_6 ) ;
F_80 ( V_22 -> V_118 ) ;
return 0 ;
}
