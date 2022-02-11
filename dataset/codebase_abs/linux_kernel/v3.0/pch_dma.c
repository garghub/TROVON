static inline
struct V_1 * F_1 ( struct V_2 * V_3 )
{
return F_2 ( V_3 , struct V_1 , V_3 ) ;
}
static inline struct V_4 * F_3 ( struct V_5 * V_6 )
{
return F_2 ( V_6 , struct V_4 , V_6 ) ;
}
static inline struct V_7 * F_4 ( struct V_8 * V_9 )
{
return F_2 ( V_9 , struct V_7 , V_10 ) ;
}
static inline struct V_11 * F_5 ( struct V_5 * V_6 )
{
return & V_6 -> V_12 -> V_11 ;
}
static inline struct V_11 * F_6 ( struct V_5 * V_6 )
{
return V_6 -> V_12 -> V_11 . V_13 ;
}
static inline
struct V_1 * F_7 ( struct V_4 * V_14 )
{
return F_8 ( & V_14 -> V_15 ,
struct V_1 , V_16 ) ;
}
static inline
struct V_1 * F_9 ( struct V_4 * V_14 )
{
return F_8 ( & V_14 -> V_17 ,
struct V_1 , V_16 ) ;
}
static void F_10 ( struct V_5 * V_6 , int V_18 )
{
struct V_7 * V_19 = F_4 ( V_6 -> V_11 ) ;
T_1 V_20 ;
V_20 = F_11 ( V_19 , V_21 ) ;
if ( V_18 )
V_20 |= 0x1 << V_6 -> V_22 ;
else
V_20 &= ~ ( 0x1 << V_6 -> V_22 ) ;
F_12 ( V_19 , V_21 , V_20 ) ;
F_13 ( F_5 ( V_6 ) , L_1 ,
V_6 -> V_22 , V_20 ) ;
}
static void F_14 ( struct V_5 * V_6 )
{
struct V_4 * V_14 = F_3 ( V_6 ) ;
struct V_7 * V_19 = F_4 ( V_6 -> V_11 ) ;
T_1 V_20 ;
if ( V_6 -> V_22 < 8 ) {
V_20 = F_11 ( V_19 , V_23 ) ;
if ( V_14 -> V_24 == V_25 )
V_20 |= 0x1 << ( V_26 * V_6 -> V_22 +
V_27 ) ;
else
V_20 &= ~ ( 0x1 << ( V_26 * V_6 -> V_22 +
V_27 ) ) ;
F_12 ( V_19 , V_23 , V_20 ) ;
} else {
int V_28 = V_6 -> V_22 - 8 ;
V_20 = F_11 ( V_19 , V_29 ) ;
if ( V_14 -> V_24 == V_25 )
V_20 |= 0x1 << ( V_26 * V_28 +
V_27 ) ;
else
V_20 &= ~ ( 0x1 << ( V_26 * V_28 +
V_27 ) ) ;
F_12 ( V_19 , V_29 , V_20 ) ;
}
F_13 ( F_5 ( V_6 ) , L_2 ,
V_6 -> V_22 , V_20 ) ;
}
static void F_15 ( struct V_5 * V_6 , T_1 V_30 )
{
struct V_7 * V_19 = F_4 ( V_6 -> V_11 ) ;
T_1 V_20 ;
if ( V_6 -> V_22 < 8 ) {
V_20 = F_11 ( V_19 , V_23 ) ;
V_20 &= ~ ( V_31 <<
( V_26 * V_6 -> V_22 ) ) ;
V_20 |= V_30 << ( V_26 * V_6 -> V_22 ) ;
F_12 ( V_19 , V_23 , V_20 ) ;
} else {
int V_28 = V_6 -> V_22 - 8 ;
V_20 = F_11 ( V_19 , V_29 ) ;
V_20 &= ~ ( V_31 <<
( V_26 * V_28 ) ) ;
V_20 |= V_30 << ( V_26 * V_28 ) ;
F_12 ( V_19 , V_29 , V_20 ) ;
}
F_13 ( F_5 ( V_6 ) , L_3 ,
V_6 -> V_22 , V_20 ) ;
}
static T_1 F_16 ( struct V_4 * V_14 )
{
struct V_7 * V_19 = F_4 ( V_14 -> V_6 . V_11 ) ;
T_1 V_20 ;
V_20 = F_11 ( V_19 , V_32 ) ;
return V_33 & ( V_20 >> ( V_34 +
V_35 * V_14 -> V_6 . V_22 ) ) ;
}
static bool F_17 ( struct V_4 * V_14 )
{
if ( F_16 ( V_14 ) == V_36 )
return true ;
else
return false ;
}
static void F_18 ( struct V_4 * V_14 , struct V_1 * V_37 )
{
if ( ! F_17 ( V_14 ) ) {
F_19 ( F_5 ( & V_14 -> V_6 ) ,
L_4 ) ;
return;
}
F_13 ( F_5 ( & V_14 -> V_6 ) , L_5 ,
V_14 -> V_6 . V_22 , V_37 -> V_38 . V_39 ) ;
F_13 ( F_5 ( & V_14 -> V_6 ) , L_6 ,
V_14 -> V_6 . V_22 , V_37 -> V_38 . V_40 ) ;
F_13 ( F_5 ( & V_14 -> V_6 ) , L_7 ,
V_14 -> V_6 . V_22 , V_37 -> V_38 . V_41 ) ;
F_13 ( F_5 ( & V_14 -> V_6 ) , L_8 ,
V_14 -> V_6 . V_22 , V_37 -> V_38 . V_42 ) ;
if ( F_20 ( & V_37 -> V_43 ) ) {
F_21 ( V_14 , V_44 , V_37 -> V_38 . V_39 ) ;
F_21 ( V_14 , V_45 , V_37 -> V_38 . V_40 ) ;
F_21 ( V_14 , V_46 , V_37 -> V_38 . V_41 ) ;
F_21 ( V_14 , V_47 , V_37 -> V_38 . V_42 ) ;
F_15 ( & V_14 -> V_6 , V_48 ) ;
} else {
F_21 ( V_14 , V_47 , V_37 -> V_3 . V_49 ) ;
F_15 ( & V_14 -> V_6 , V_50 ) ;
}
}
static void F_22 ( struct V_4 * V_14 ,
struct V_1 * V_37 )
{
struct V_2 * V_3 = & V_37 -> V_3 ;
T_2 V_51 = V_3 -> V_51 ;
void * V_52 = V_3 -> V_53 ;
F_23 ( & V_37 -> V_43 , & V_14 -> V_54 ) ;
F_24 ( & V_37 -> V_16 , & V_14 -> V_54 ) ;
if ( V_51 )
V_51 ( V_52 ) ;
}
static void F_25 ( struct V_4 * V_14 )
{
struct V_1 * V_37 , * V_55 ;
F_26 ( V_56 ) ;
F_27 ( ! F_17 ( V_14 ) ) ;
if ( ! F_20 ( & V_14 -> V_17 ) )
F_18 ( V_14 , F_9 ( V_14 ) ) ;
F_23 ( & V_14 -> V_15 , & V_56 ) ;
F_23 ( & V_14 -> V_17 , & V_14 -> V_15 ) ;
F_28 (desc, _d, &list, desc_node)
F_22 ( V_14 , V_37 ) ;
}
static void F_29 ( struct V_4 * V_14 )
{
struct V_1 * V_57 ;
V_57 = F_7 ( V_14 ) ;
F_30 ( & V_57 -> V_16 ) ;
F_23 ( & V_14 -> V_17 , V_14 -> V_15 . V_58 ) ;
if ( ! F_20 ( & V_14 -> V_15 ) )
F_18 ( V_14 , F_7 ( V_14 ) ) ;
F_31 ( F_5 ( & V_14 -> V_6 ) , L_9 ) ;
F_31 ( F_5 ( & V_14 -> V_6 ) , L_10 ,
V_57 -> V_3 . V_59 ) ;
F_22 ( V_14 , V_57 ) ;
}
static void F_32 ( struct V_4 * V_14 )
{
if ( F_20 ( & V_14 -> V_15 ) ||
F_33 ( & V_14 -> V_15 ) ) {
F_25 ( V_14 ) ;
} else {
F_22 ( V_14 , F_7 ( V_14 ) ) ;
F_18 ( V_14 , F_7 ( V_14 ) ) ;
}
}
static T_3 F_34 ( struct V_4 * V_14 ,
struct V_1 * V_37 )
{
T_3 V_59 = V_14 -> V_6 . V_59 ;
if ( ++ V_59 < 0 )
V_59 = 1 ;
V_14 -> V_6 . V_59 = V_59 ;
V_37 -> V_3 . V_59 = V_59 ;
return V_59 ;
}
static T_3 F_35 ( struct V_2 * V_3 )
{
struct V_1 * V_37 = F_1 ( V_3 ) ;
struct V_4 * V_14 = F_3 ( V_3 -> V_6 ) ;
T_3 V_59 ;
F_36 ( & V_14 -> V_60 ) ;
V_59 = F_34 ( V_14 , V_37 ) ;
if ( F_20 ( & V_14 -> V_15 ) ) {
F_37 ( & V_37 -> V_16 , & V_14 -> V_15 ) ;
F_18 ( V_14 , V_37 ) ;
} else {
F_37 ( & V_37 -> V_16 , & V_14 -> V_17 ) ;
}
F_38 ( & V_14 -> V_60 ) ;
return 0 ;
}
static struct V_1 * F_39 ( struct V_5 * V_6 , T_4 V_61 )
{
struct V_1 * V_37 = NULL ;
struct V_7 * V_19 = F_4 ( V_6 -> V_11 ) ;
T_5 V_62 ;
V_37 = F_40 ( V_19 -> V_63 , V_61 , & V_62 ) ;
if ( V_37 ) {
memset ( V_37 , 0 , sizeof( struct V_1 ) ) ;
F_41 ( & V_37 -> V_43 ) ;
F_42 ( & V_37 -> V_3 , V_6 ) ;
V_37 -> V_3 . V_64 = F_35 ;
V_37 -> V_3 . V_61 = V_65 ;
V_37 -> V_3 . V_49 = V_62 ;
}
return V_37 ;
}
static struct V_1 * F_43 ( struct V_4 * V_14 )
{
struct V_1 * V_37 , * V_55 ;
struct V_1 * V_66 = NULL ;
int V_67 = 0 ;
F_36 ( & V_14 -> V_60 ) ;
F_28 (desc, _d, &pd_chan->free_list, desc_node) {
V_67 ++ ;
if ( F_44 ( & V_37 -> V_3 ) ) {
F_30 ( & V_37 -> V_16 ) ;
V_66 = V_37 ;
break;
}
F_13 ( F_5 ( & V_14 -> V_6 ) , L_11 , V_37 ) ;
}
F_38 ( & V_14 -> V_60 ) ;
F_13 ( F_5 ( & V_14 -> V_6 ) , L_12 , V_67 ) ;
if ( ! V_66 ) {
V_66 = F_39 ( & V_14 -> V_6 , V_68 ) ;
if ( V_66 ) {
F_36 ( & V_14 -> V_60 ) ;
V_14 -> V_69 ++ ;
F_38 ( & V_14 -> V_60 ) ;
} else {
F_19 ( F_5 ( & V_14 -> V_6 ) ,
L_13 ) ;
}
}
return V_66 ;
}
static void F_45 ( struct V_4 * V_14 ,
struct V_1 * V_37 )
{
if ( V_37 ) {
F_36 ( & V_14 -> V_60 ) ;
F_23 ( & V_37 -> V_43 , & V_14 -> V_54 ) ;
F_46 ( & V_37 -> V_16 , & V_14 -> V_54 ) ;
F_38 ( & V_14 -> V_60 ) ;
}
}
static int F_47 ( struct V_5 * V_6 )
{
struct V_4 * V_14 = F_3 ( V_6 ) ;
struct V_1 * V_37 ;
F_26 ( V_70 ) ;
int V_67 ;
if ( ! F_17 ( V_14 ) ) {
F_13 ( F_5 ( V_6 ) , L_14 ) ;
return - V_71 ;
}
if ( ! F_20 ( & V_14 -> V_54 ) )
return V_14 -> V_69 ;
for ( V_67 = 0 ; V_67 < V_72 ; V_67 ++ ) {
V_37 = F_39 ( V_6 , V_73 ) ;
if ( ! V_37 ) {
F_48 ( F_5 ( V_6 ) ,
L_15 , V_67 ) ;
break;
}
F_37 ( & V_37 -> V_16 , & V_70 ) ;
}
F_49 ( & V_14 -> V_60 ) ;
F_50 ( & V_70 , & V_14 -> V_54 ) ;
V_14 -> V_69 = V_67 ;
V_14 -> V_74 = V_6 -> V_59 = 1 ;
F_51 ( & V_14 -> V_60 ) ;
F_10 ( V_6 , 1 ) ;
return V_14 -> V_69 ;
}
static void F_52 ( struct V_5 * V_6 )
{
struct V_4 * V_14 = F_3 ( V_6 ) ;
struct V_7 * V_19 = F_4 ( V_6 -> V_11 ) ;
struct V_1 * V_37 , * V_55 ;
F_26 ( V_70 ) ;
F_27 ( ! F_17 ( V_14 ) ) ;
F_27 ( ! F_20 ( & V_14 -> V_15 ) ) ;
F_27 ( ! F_20 ( & V_14 -> V_17 ) ) ;
F_49 ( & V_14 -> V_60 ) ;
F_23 ( & V_14 -> V_54 , & V_70 ) ;
V_14 -> V_69 = 0 ;
F_51 ( & V_14 -> V_60 ) ;
F_28 (desc, _d, &tmp_list, desc_node)
F_53 ( V_19 -> V_63 , V_37 , V_37 -> V_3 . V_49 ) ;
F_10 ( V_6 , 0 ) ;
}
static enum V_75 F_54 ( struct V_5 * V_6 , T_3 V_59 ,
struct V_76 * V_77 )
{
struct V_4 * V_14 = F_3 ( V_6 ) ;
T_3 V_78 ;
T_3 V_79 ;
int V_66 ;
F_49 ( & V_14 -> V_60 ) ;
V_79 = V_14 -> V_74 ;
V_78 = V_6 -> V_59 ;
F_51 ( & V_14 -> V_60 ) ;
V_66 = F_55 ( V_59 , V_79 , V_78 ) ;
F_56 ( V_77 , V_79 , V_78 , 0 ) ;
return V_66 ;
}
static void F_57 ( struct V_5 * V_6 )
{
struct V_4 * V_14 = F_3 ( V_6 ) ;
if ( F_17 ( V_14 ) ) {
F_36 ( & V_14 -> V_60 ) ;
F_32 ( V_14 ) ;
F_38 ( & V_14 -> V_60 ) ;
}
}
static struct V_2 * F_58 ( struct V_5 * V_6 ,
struct V_80 * V_81 , unsigned int V_82 ,
enum V_83 V_84 , unsigned long V_61 )
{
struct V_4 * V_14 = F_3 ( V_6 ) ;
struct V_85 * V_86 = V_6 -> V_87 ;
struct V_1 * V_88 = NULL ;
struct V_1 * V_58 = NULL ;
struct V_1 * V_37 = NULL ;
struct V_80 * V_89 ;
T_5 V_90 ;
int V_67 ;
if ( F_59 ( ! V_82 ) ) {
F_60 ( F_5 ( V_6 ) , L_16 ) ;
return NULL ;
}
if ( V_84 == V_91 )
V_90 = V_86 -> V_92 ;
else if ( V_84 == V_25 )
V_90 = V_86 -> V_93 ;
else
return NULL ;
V_14 -> V_24 = V_84 ;
F_14 ( V_6 ) ;
F_61 (sgl, sg, sg_len, i) {
V_37 = F_43 ( V_14 ) ;
if ( ! V_37 )
goto V_94;
V_37 -> V_38 . V_39 = V_90 ;
V_37 -> V_38 . V_40 = F_62 ( V_89 ) ;
V_37 -> V_38 . V_41 = F_63 ( V_89 ) ;
V_37 -> V_38 . V_42 = V_95 ;
switch ( V_86 -> V_96 ) {
case V_97 :
if ( V_37 -> V_38 . V_41 > V_98 )
goto V_94;
V_37 -> V_38 . V_41 |= V_99 ;
break;
case V_100 :
if ( V_37 -> V_38 . V_41 > V_101 )
goto V_94;
V_37 -> V_38 . V_41 |= V_102 ;
break;
case V_103 :
if ( V_37 -> V_38 . V_41 > V_104 )
goto V_94;
V_37 -> V_38 . V_41 |= V_105 ;
break;
default:
goto V_94;
}
if ( ! V_88 ) {
V_88 = V_37 ;
} else {
V_58 -> V_38 . V_42 |= V_37 -> V_3 . V_49 ;
F_37 ( & V_37 -> V_16 , & V_88 -> V_43 ) ;
}
V_58 = V_37 ;
}
if ( V_61 & V_106 )
V_37 -> V_38 . V_42 = V_107 ;
else
V_37 -> V_38 . V_42 = V_108 ;
V_88 -> V_3 . V_59 = - V_109 ;
V_37 -> V_3 . V_61 = V_61 ;
return & V_88 -> V_3 ;
V_94:
F_19 ( F_5 ( V_6 ) , L_17 ) ;
F_45 ( V_14 , V_88 ) ;
return NULL ;
}
static int F_64 ( struct V_5 * V_6 , enum V_110 V_111 ,
unsigned long V_112 )
{
struct V_4 * V_14 = F_3 ( V_6 ) ;
struct V_1 * V_37 , * V_55 ;
F_26 ( V_56 ) ;
if ( V_111 != V_113 )
return - V_114 ;
F_49 ( & V_14 -> V_60 ) ;
F_15 ( & V_14 -> V_6 , V_115 ) ;
F_23 ( & V_14 -> V_15 , & V_56 ) ;
F_23 ( & V_14 -> V_17 , & V_56 ) ;
F_28 (desc, _d, &list, desc_node)
F_22 ( V_14 , V_37 ) ;
F_51 ( & V_14 -> V_60 ) ;
return 0 ;
}
static void F_65 ( unsigned long V_116 )
{
struct V_4 * V_14 = (struct V_4 * ) V_116 ;
unsigned long V_61 ;
if ( ! F_17 ( V_14 ) ) {
F_19 ( F_5 ( & V_14 -> V_6 ) ,
L_18 ) ;
return;
}
F_66 ( & V_14 -> V_60 , V_61 ) ;
if ( F_67 ( 0 , & V_14 -> V_117 ) )
F_29 ( V_14 ) ;
else
F_32 ( V_14 ) ;
F_68 ( & V_14 -> V_60 , V_61 ) ;
}
static T_6 F_69 ( int V_118 , void * V_119 )
{
struct V_7 * V_19 = (struct V_7 * ) V_119 ;
struct V_4 * V_14 ;
T_1 V_120 ;
int V_67 ;
int V_66 = V_121 ;
V_120 = F_11 ( V_19 , V_32 ) ;
F_13 ( V_19 -> V_10 . V_12 , L_19 , V_120 ) ;
for ( V_67 = 0 ; V_67 < V_19 -> V_10 . V_122 ; V_67 ++ ) {
V_14 = & V_19 -> V_123 [ V_67 ] ;
if ( V_120 & F_70 ( V_67 ) ) {
if ( V_120 & F_71 ( V_67 ) )
F_72 ( 0 , & V_14 -> V_117 ) ;
F_73 ( & V_14 -> V_124 ) ;
V_66 = V_125 ;
}
}
F_12 ( V_19 , V_32 , V_120 ) ;
return V_66 ;
}
static void F_74 ( struct V_7 * V_19 )
{
struct V_4 * V_14 ;
struct V_5 * V_6 , * V_126 ;
int V_67 = 0 ;
V_19 -> V_38 . V_127 = F_11 ( V_19 , V_23 ) ;
V_19 -> V_38 . V_128 = F_11 ( V_19 , V_129 ) ;
V_19 -> V_38 . V_130 = F_11 ( V_19 , V_21 ) ;
V_19 -> V_38 . V_131 = F_11 ( V_19 , V_29 ) ;
F_28 (chan, _c, &pd->dma.channels, device_node) {
V_14 = F_3 ( V_6 ) ;
V_19 -> V_132 [ V_67 ] . V_39 = F_75 ( V_14 , V_44 ) ;
V_19 -> V_132 [ V_67 ] . V_40 = F_75 ( V_14 , V_45 ) ;
V_19 -> V_132 [ V_67 ] . V_41 = F_75 ( V_14 , V_46 ) ;
V_19 -> V_132 [ V_67 ] . V_42 = F_75 ( V_14 , V_47 ) ;
V_67 ++ ;
}
}
static void F_76 ( struct V_7 * V_19 )
{
struct V_4 * V_14 ;
struct V_5 * V_6 , * V_126 ;
int V_67 = 0 ;
F_12 ( V_19 , V_23 , V_19 -> V_38 . V_127 ) ;
F_12 ( V_19 , V_129 , V_19 -> V_38 . V_128 ) ;
F_12 ( V_19 , V_21 , V_19 -> V_38 . V_130 ) ;
F_12 ( V_19 , V_29 , V_19 -> V_38 . V_131 ) ;
F_28 (chan, _c, &pd->dma.channels, device_node) {
V_14 = F_3 ( V_6 ) ;
F_21 ( V_14 , V_44 , V_19 -> V_132 [ V_67 ] . V_39 ) ;
F_21 ( V_14 , V_45 , V_19 -> V_132 [ V_67 ] . V_40 ) ;
F_21 ( V_14 , V_46 , V_19 -> V_132 [ V_67 ] . V_41 ) ;
F_21 ( V_14 , V_47 , V_19 -> V_132 [ V_67 ] . V_42 ) ;
V_67 ++ ;
}
}
static int F_77 ( struct V_133 * V_134 , T_7 V_135 )
{
struct V_7 * V_19 = F_78 ( V_134 ) ;
if ( V_19 )
F_74 ( V_19 ) ;
F_79 ( V_134 ) ;
F_80 ( V_134 ) ;
F_81 ( V_134 , F_82 ( V_134 , V_135 ) ) ;
return 0 ;
}
static int F_83 ( struct V_133 * V_134 )
{
struct V_7 * V_19 = F_78 ( V_134 ) ;
int V_136 ;
F_81 ( V_134 , V_137 ) ;
F_84 ( V_134 ) ;
V_136 = F_85 ( V_134 ) ;
if ( V_136 ) {
F_13 ( & V_134 -> V_12 , L_20 ) ;
return V_136 ;
}
if ( V_19 )
F_76 ( V_19 ) ;
return 0 ;
}
static int T_8 F_86 ( struct V_133 * V_134 ,
const struct V_138 * V_139 )
{
struct V_7 * V_19 ;
struct V_140 * V_38 ;
unsigned int V_141 ;
int V_136 ;
int V_67 ;
V_141 = V_139 -> V_142 ;
V_19 = F_87 ( sizeof( struct V_7 ) +
sizeof( struct V_4 ) * V_141 , V_73 ) ;
if ( ! V_19 )
return - V_143 ;
F_88 ( V_134 , V_19 ) ;
V_136 = F_85 ( V_134 ) ;
if ( V_136 ) {
F_19 ( & V_134 -> V_12 , L_21 ) ;
goto V_144;
}
if ( ! ( F_89 ( V_134 , 1 ) & V_145 ) ) {
F_19 ( & V_134 -> V_12 , L_22 ) ;
goto V_146;
}
V_136 = F_90 ( V_134 , V_147 ) ;
if ( V_136 ) {
F_19 ( & V_134 -> V_12 , L_23 ) ;
goto V_146;
}
V_136 = F_91 ( V_134 , F_92 ( 32 ) ) ;
if ( V_136 ) {
F_19 ( & V_134 -> V_12 , L_24 ) ;
goto V_148;
}
V_38 = V_19 -> V_149 = F_93 ( V_134 , 1 , 0 ) ;
if ( ! V_19 -> V_149 ) {
F_19 ( & V_134 -> V_12 , L_25 ) ;
V_136 = - V_143 ;
goto V_148;
}
F_94 ( V_134 ) ;
V_136 = F_95 ( V_134 -> V_118 , F_69 , V_150 , V_147 , V_19 ) ;
if ( V_136 ) {
F_19 ( & V_134 -> V_12 , L_26 ) ;
goto V_151;
}
V_19 -> V_63 = F_96 ( L_27 , V_134 ,
sizeof( struct V_1 ) , 4 , 0 ) ;
if ( ! V_19 -> V_63 ) {
F_19 ( & V_134 -> V_12 , L_28 ) ;
V_136 = - V_143 ;
goto V_152;
}
V_19 -> V_10 . V_12 = & V_134 -> V_12 ;
V_19 -> V_10 . V_122 = V_141 ;
F_41 ( & V_19 -> V_10 . V_123 ) ;
for ( V_67 = 0 ; V_67 < V_141 ; V_67 ++ ) {
struct V_4 * V_14 = & V_19 -> V_123 [ V_67 ] ;
V_14 -> V_6 . V_11 = & V_19 -> V_10 ;
V_14 -> V_6 . V_59 = 1 ;
V_14 -> V_6 . V_22 = V_67 ;
V_14 -> V_149 = & V_38 -> V_37 [ V_67 ] ;
F_97 ( & V_14 -> V_60 ) ;
F_41 ( & V_14 -> V_15 ) ;
F_41 ( & V_14 -> V_17 ) ;
F_41 ( & V_14 -> V_54 ) ;
F_98 ( & V_14 -> V_124 , F_65 ,
( unsigned long ) V_14 ) ;
F_37 ( & V_14 -> V_6 . V_153 , & V_19 -> V_10 . V_123 ) ;
}
F_99 ( V_19 -> V_10 . V_154 ) ;
F_100 ( V_155 , V_19 -> V_10 . V_154 ) ;
F_100 ( V_156 , V_19 -> V_10 . V_154 ) ;
V_19 -> V_10 . V_157 = F_47 ;
V_19 -> V_10 . V_158 = F_52 ;
V_19 -> V_10 . V_159 = F_54 ;
V_19 -> V_10 . V_160 = F_57 ;
V_19 -> V_10 . V_161 = F_58 ;
V_19 -> V_10 . V_162 = F_64 ;
V_136 = F_101 ( & V_19 -> V_10 ) ;
if ( V_136 ) {
F_19 ( & V_134 -> V_12 , L_29 ) ;
goto V_163;
}
return 0 ;
V_163:
F_102 ( V_19 -> V_63 ) ;
V_152:
F_103 ( V_134 -> V_118 , V_19 ) ;
V_151:
F_104 ( V_134 , V_19 -> V_149 ) ;
V_148:
F_105 ( V_134 ) ;
V_146:
F_80 ( V_134 ) ;
V_144:
return V_136 ;
}
static void T_9 F_106 ( struct V_133 * V_134 )
{
struct V_7 * V_19 = F_78 ( V_134 ) ;
struct V_4 * V_14 ;
struct V_5 * V_6 , * V_126 ;
if ( V_19 ) {
F_107 ( & V_19 -> V_10 ) ;
F_28 (chan, _c, &pd->dma.channels,
device_node) {
V_14 = F_3 ( V_6 ) ;
F_108 ( & V_14 -> V_124 ) ;
F_109 ( & V_14 -> V_124 ) ;
}
F_102 ( V_19 -> V_63 ) ;
F_103 ( V_134 -> V_118 , V_19 ) ;
F_104 ( V_134 , V_19 -> V_149 ) ;
F_105 ( V_134 ) ;
F_80 ( V_134 ) ;
F_110 ( V_19 ) ;
}
}
static int T_10 F_111 ( void )
{
return F_112 ( & V_164 ) ;
}
static void T_11 F_113 ( void )
{
F_114 ( & V_164 ) ;
}
