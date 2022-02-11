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
int V_21 ;
if ( V_6 -> V_22 < 8 )
V_21 = V_6 -> V_22 ;
else
V_21 = V_6 -> V_22 + 8 ;
V_20 = F_11 ( V_19 , V_23 ) ;
if ( V_18 )
V_20 |= 0x1 << V_21 ;
else
V_20 &= ~ ( 0x1 << V_21 ) ;
F_12 ( V_19 , V_23 , V_20 ) ;
F_13 ( F_5 ( V_6 ) , L_1 ,
V_6 -> V_22 , V_20 ) ;
}
static void F_14 ( struct V_5 * V_6 )
{
struct V_4 * V_14 = F_3 ( V_6 ) ;
struct V_7 * V_19 = F_4 ( V_6 -> V_11 ) ;
T_1 V_20 ;
T_1 V_24 ;
T_1 V_25 ;
if ( V_6 -> V_22 < 8 ) {
V_20 = F_11 ( V_19 , V_26 ) ;
V_24 = V_27 <<
( V_28 * V_6 -> V_22 ) ;
V_25 = V_29 & ~ ( V_27 <<
( V_28 * V_6 -> V_22 ) ) ;
V_20 &= V_24 ;
if ( V_14 -> V_30 == V_31 )
V_20 |= 0x1 << ( V_28 * V_6 -> V_22 +
V_32 ) ;
else
V_20 &= ~ ( 0x1 << ( V_28 * V_6 -> V_22 +
V_32 ) ) ;
V_20 |= V_25 ;
F_12 ( V_19 , V_26 , V_20 ) ;
} else {
int V_33 = V_6 -> V_22 - 8 ;
V_20 = F_11 ( V_19 , V_34 ) ;
V_24 = V_27 <<
( V_28 * V_33 ) ;
V_25 = V_35 & ~ ( V_27 <<
( V_28 * V_33 ) ) ;
V_20 &= V_24 ;
if ( V_14 -> V_30 == V_31 )
V_20 |= 0x1 << ( V_28 * V_33 +
V_32 ) ;
else
V_20 &= ~ ( 0x1 << ( V_28 * V_33 +
V_32 ) ) ;
V_20 |= V_25 ;
F_12 ( V_19 , V_34 , V_20 ) ;
}
F_13 ( F_5 ( V_6 ) , L_2 ,
V_6 -> V_22 , V_20 ) ;
}
static void F_15 ( struct V_5 * V_6 , T_1 V_36 )
{
struct V_7 * V_19 = F_4 ( V_6 -> V_11 ) ;
T_1 V_20 ;
T_1 V_25 ;
T_1 V_37 ;
if ( V_6 -> V_22 < 8 ) {
V_25 = V_29 & ~ ( V_27 <<
( V_28 * V_6 -> V_22 ) ) ;
V_37 = 1 << ( V_28 * V_6 -> V_22 +\
V_32 ) ;
V_20 = F_11 ( V_19 , V_26 ) ;
V_20 &= V_37 ;
V_20 |= V_36 << ( V_28 * V_6 -> V_22 ) ;
V_20 |= V_25 ;
F_12 ( V_19 , V_26 , V_20 ) ;
} else {
int V_33 = V_6 -> V_22 - 8 ;
V_25 = V_35 & ~ ( V_27 <<
( V_28 * V_33 ) ) ;
V_37 = 1 << ( V_28 * V_33 +\
V_32 ) ;
V_20 = F_11 ( V_19 , V_34 ) ;
V_20 &= V_37 ;
V_20 |= V_36 << ( V_28 * V_33 ) ;
V_20 |= V_25 ;
F_12 ( V_19 , V_34 , V_20 ) ;
}
F_13 ( F_5 ( V_6 ) , L_3 ,
V_6 -> V_22 , V_20 ) ;
}
static T_1 F_16 ( struct V_4 * V_14 )
{
struct V_7 * V_19 = F_4 ( V_14 -> V_6 . V_11 ) ;
T_1 V_20 ;
V_20 = F_11 ( V_19 , V_38 ) ;
return V_39 & ( V_20 >> ( V_40 +
V_41 * V_14 -> V_6 . V_22 ) ) ;
}
static T_1 F_17 ( struct V_4 * V_14 )
{
struct V_7 * V_19 = F_4 ( V_14 -> V_6 . V_11 ) ;
T_1 V_20 ;
V_20 = F_11 ( V_19 , V_42 ) ;
return V_39 & ( V_20 >> ( V_40 +
V_41 * ( V_14 -> V_6 . V_22 - 8 ) ) ) ;
}
static bool F_18 ( struct V_4 * V_14 )
{
T_1 V_43 ;
if ( V_14 -> V_6 . V_22 < 8 )
V_43 = F_16 ( V_14 ) ;
else
V_43 = F_17 ( V_14 ) ;
if ( V_43 == V_44 )
return true ;
else
return false ;
}
static void F_19 ( struct V_4 * V_14 , struct V_1 * V_45 )
{
if ( ! F_18 ( V_14 ) ) {
F_20 ( F_5 ( & V_14 -> V_6 ) ,
L_4 ) ;
return;
}
F_13 ( F_5 ( & V_14 -> V_6 ) , L_5 ,
V_14 -> V_6 . V_22 , V_45 -> V_46 . V_47 ) ;
F_13 ( F_5 ( & V_14 -> V_6 ) , L_6 ,
V_14 -> V_6 . V_22 , V_45 -> V_46 . V_48 ) ;
F_13 ( F_5 ( & V_14 -> V_6 ) , L_7 ,
V_14 -> V_6 . V_22 , V_45 -> V_46 . V_49 ) ;
F_13 ( F_5 ( & V_14 -> V_6 ) , L_8 ,
V_14 -> V_6 . V_22 , V_45 -> V_46 . V_50 ) ;
if ( F_21 ( & V_45 -> V_51 ) ) {
F_22 ( V_14 , V_52 , V_45 -> V_46 . V_47 ) ;
F_22 ( V_14 , V_53 , V_45 -> V_46 . V_48 ) ;
F_22 ( V_14 , V_54 , V_45 -> V_46 . V_49 ) ;
F_22 ( V_14 , V_55 , V_45 -> V_46 . V_50 ) ;
F_15 ( & V_14 -> V_6 , V_56 ) ;
} else {
F_22 ( V_14 , V_55 , V_45 -> V_3 . V_57 ) ;
F_15 ( & V_14 -> V_6 , V_58 ) ;
}
}
static void F_23 ( struct V_4 * V_14 ,
struct V_1 * V_45 )
{
struct V_2 * V_3 = & V_45 -> V_3 ;
struct V_59 V_60 ;
F_24 ( V_3 , & V_60 ) ;
F_25 ( & V_45 -> V_51 , & V_14 -> V_61 ) ;
F_26 ( & V_45 -> V_16 , & V_14 -> V_61 ) ;
F_27 ( & V_60 , NULL ) ;
}
static void F_28 ( struct V_4 * V_14 )
{
struct V_1 * V_45 , * V_62 ;
F_29 ( V_63 ) ;
F_30 ( ! F_18 ( V_14 ) ) ;
if ( ! F_21 ( & V_14 -> V_17 ) )
F_19 ( V_14 , F_9 ( V_14 ) ) ;
F_25 ( & V_14 -> V_15 , & V_63 ) ;
F_25 ( & V_14 -> V_17 , & V_14 -> V_15 ) ;
F_31 (desc, _d, &list, desc_node)
F_23 ( V_14 , V_45 ) ;
}
static void F_32 ( struct V_4 * V_14 )
{
struct V_1 * V_64 ;
V_64 = F_7 ( V_14 ) ;
F_33 ( & V_64 -> V_16 ) ;
F_25 ( & V_14 -> V_17 , V_14 -> V_15 . V_65 ) ;
if ( ! F_21 ( & V_14 -> V_15 ) )
F_19 ( V_14 , F_7 ( V_14 ) ) ;
F_34 ( F_5 ( & V_14 -> V_6 ) , L_9 ) ;
F_34 ( F_5 ( & V_14 -> V_6 ) , L_10 ,
V_64 -> V_3 . V_66 ) ;
F_23 ( V_14 , V_64 ) ;
}
static void F_35 ( struct V_4 * V_14 )
{
if ( F_21 ( & V_14 -> V_15 ) ||
F_36 ( & V_14 -> V_15 ) ) {
F_28 ( V_14 ) ;
} else {
F_23 ( V_14 , F_7 ( V_14 ) ) ;
F_19 ( V_14 , F_7 ( V_14 ) ) ;
}
}
static T_2 F_37 ( struct V_2 * V_3 )
{
struct V_1 * V_45 = F_1 ( V_3 ) ;
struct V_4 * V_14 = F_3 ( V_3 -> V_6 ) ;
T_2 V_66 ;
F_38 ( & V_14 -> V_67 ) ;
V_66 = F_39 ( V_3 ) ;
if ( F_21 ( & V_14 -> V_15 ) ) {
F_40 ( & V_45 -> V_16 , & V_14 -> V_15 ) ;
F_19 ( V_14 , V_45 ) ;
} else {
F_40 ( & V_45 -> V_16 , & V_14 -> V_17 ) ;
}
F_41 ( & V_14 -> V_67 ) ;
return 0 ;
}
static struct V_1 * F_42 ( struct V_5 * V_6 , T_3 V_68 )
{
struct V_1 * V_45 = NULL ;
struct V_7 * V_19 = F_4 ( V_6 -> V_11 ) ;
T_4 V_69 ;
V_45 = F_43 ( V_19 -> V_70 , V_68 , & V_69 ) ;
if ( V_45 ) {
memset ( V_45 , 0 , sizeof( struct V_1 ) ) ;
F_44 ( & V_45 -> V_51 ) ;
F_45 ( & V_45 -> V_3 , V_6 ) ;
V_45 -> V_3 . V_71 = F_37 ;
V_45 -> V_3 . V_68 = V_72 ;
V_45 -> V_3 . V_57 = V_69 ;
}
return V_45 ;
}
static struct V_1 * F_46 ( struct V_4 * V_14 )
{
struct V_1 * V_45 , * V_62 ;
struct V_1 * V_73 = NULL ;
int V_74 = 0 ;
F_38 ( & V_14 -> V_67 ) ;
F_31 (desc, _d, &pd_chan->free_list, desc_node) {
V_74 ++ ;
if ( F_47 ( & V_45 -> V_3 ) ) {
F_33 ( & V_45 -> V_16 ) ;
V_73 = V_45 ;
break;
}
F_13 ( F_5 ( & V_14 -> V_6 ) , L_11 , V_45 ) ;
}
F_41 ( & V_14 -> V_67 ) ;
F_13 ( F_5 ( & V_14 -> V_6 ) , L_12 , V_74 ) ;
if ( ! V_73 ) {
V_73 = F_42 ( & V_14 -> V_6 , V_75 ) ;
if ( V_73 ) {
F_38 ( & V_14 -> V_67 ) ;
V_14 -> V_76 ++ ;
F_41 ( & V_14 -> V_67 ) ;
} else {
F_20 ( F_5 ( & V_14 -> V_6 ) ,
L_13 ) ;
}
}
return V_73 ;
}
static void F_48 ( struct V_4 * V_14 ,
struct V_1 * V_45 )
{
if ( V_45 ) {
F_38 ( & V_14 -> V_67 ) ;
F_25 ( & V_45 -> V_51 , & V_14 -> V_61 ) ;
F_49 ( & V_45 -> V_16 , & V_14 -> V_61 ) ;
F_41 ( & V_14 -> V_67 ) ;
}
}
static int F_50 ( struct V_5 * V_6 )
{
struct V_4 * V_14 = F_3 ( V_6 ) ;
struct V_1 * V_45 ;
F_29 ( V_77 ) ;
int V_74 ;
if ( ! F_18 ( V_14 ) ) {
F_13 ( F_5 ( V_6 ) , L_14 ) ;
return - V_78 ;
}
if ( ! F_21 ( & V_14 -> V_61 ) )
return V_14 -> V_76 ;
for ( V_74 = 0 ; V_74 < V_79 ; V_74 ++ ) {
V_45 = F_42 ( V_6 , V_80 ) ;
if ( ! V_45 ) {
F_51 ( F_5 ( V_6 ) ,
L_15 , V_74 ) ;
break;
}
F_40 ( & V_45 -> V_16 , & V_77 ) ;
}
F_52 ( & V_14 -> V_67 ) ;
F_53 ( & V_77 , & V_14 -> V_61 ) ;
V_14 -> V_76 = V_74 ;
F_54 ( V_6 ) ;
F_55 ( & V_14 -> V_67 ) ;
F_10 ( V_6 , 1 ) ;
return V_14 -> V_76 ;
}
static void F_56 ( struct V_5 * V_6 )
{
struct V_4 * V_14 = F_3 ( V_6 ) ;
struct V_7 * V_19 = F_4 ( V_6 -> V_11 ) ;
struct V_1 * V_45 , * V_62 ;
F_29 ( V_77 ) ;
F_30 ( ! F_18 ( V_14 ) ) ;
F_30 ( ! F_21 ( & V_14 -> V_15 ) ) ;
F_30 ( ! F_21 ( & V_14 -> V_17 ) ) ;
F_52 ( & V_14 -> V_67 ) ;
F_25 ( & V_14 -> V_61 , & V_77 ) ;
V_14 -> V_76 = 0 ;
F_55 ( & V_14 -> V_67 ) ;
F_31 (desc, _d, &tmp_list, desc_node)
F_57 ( V_19 -> V_70 , V_45 , V_45 -> V_3 . V_57 ) ;
F_10 ( V_6 , 0 ) ;
}
static enum V_81 F_58 ( struct V_5 * V_6 , T_2 V_66 ,
struct V_82 * V_83 )
{
return F_59 ( V_6 , V_66 , V_83 ) ;
}
static void F_60 ( struct V_5 * V_6 )
{
struct V_4 * V_14 = F_3 ( V_6 ) ;
if ( F_18 ( V_14 ) ) {
F_38 ( & V_14 -> V_67 ) ;
F_35 ( V_14 ) ;
F_41 ( & V_14 -> V_67 ) ;
}
}
static struct V_2 * F_61 ( struct V_5 * V_6 ,
struct V_84 * V_85 , unsigned int V_86 ,
enum V_87 V_88 , unsigned long V_68 ,
void * V_89 )
{
struct V_4 * V_14 = F_3 ( V_6 ) ;
struct V_90 * V_91 = V_6 -> V_92 ;
struct V_1 * V_93 = NULL ;
struct V_1 * V_65 = NULL ;
struct V_1 * V_45 = NULL ;
struct V_84 * V_94 ;
T_4 V_95 ;
int V_74 ;
if ( F_62 ( ! V_86 ) ) {
F_63 ( F_5 ( V_6 ) , L_16 ) ;
return NULL ;
}
if ( V_88 == V_96 )
V_95 = V_91 -> V_97 ;
else if ( V_88 == V_31 )
V_95 = V_91 -> V_98 ;
else
return NULL ;
V_14 -> V_30 = V_88 ;
F_14 ( V_6 ) ;
F_64 (sgl, sg, sg_len, i) {
V_45 = F_46 ( V_14 ) ;
if ( ! V_45 )
goto V_99;
V_45 -> V_46 . V_47 = V_95 ;
V_45 -> V_46 . V_48 = F_65 ( V_94 ) ;
V_45 -> V_46 . V_49 = F_66 ( V_94 ) ;
V_45 -> V_46 . V_50 = V_100 ;
switch ( V_91 -> V_101 ) {
case V_102 :
if ( V_45 -> V_46 . V_49 > V_103 )
goto V_99;
V_45 -> V_46 . V_49 |= V_104 ;
break;
case V_105 :
if ( V_45 -> V_46 . V_49 > V_106 )
goto V_99;
V_45 -> V_46 . V_49 |= V_107 ;
break;
case V_108 :
if ( V_45 -> V_46 . V_49 > V_109 )
goto V_99;
V_45 -> V_46 . V_49 |= V_110 ;
break;
default:
goto V_99;
}
if ( ! V_93 ) {
V_93 = V_45 ;
} else {
V_65 -> V_46 . V_50 |= V_45 -> V_3 . V_57 ;
F_40 ( & V_45 -> V_16 , & V_93 -> V_51 ) ;
}
V_65 = V_45 ;
}
if ( V_68 & V_111 )
V_45 -> V_46 . V_50 = V_112 ;
else
V_45 -> V_46 . V_50 = V_113 ;
V_93 -> V_3 . V_66 = - V_114 ;
V_45 -> V_3 . V_68 = V_68 ;
return & V_93 -> V_3 ;
V_99:
F_20 ( F_5 ( V_6 ) , L_17 ) ;
F_48 ( V_14 , V_93 ) ;
return NULL ;
}
static int F_67 ( struct V_5 * V_6 )
{
struct V_4 * V_14 = F_3 ( V_6 ) ;
struct V_1 * V_45 , * V_62 ;
F_29 ( V_63 ) ;
F_52 ( & V_14 -> V_67 ) ;
F_15 ( & V_14 -> V_6 , V_115 ) ;
F_25 ( & V_14 -> V_15 , & V_63 ) ;
F_25 ( & V_14 -> V_17 , & V_63 ) ;
F_31 (desc, _d, &list, desc_node)
F_23 ( V_14 , V_45 ) ;
F_55 ( & V_14 -> V_67 ) ;
return 0 ;
}
static void F_68 ( unsigned long V_116 )
{
struct V_4 * V_14 = (struct V_4 * ) V_116 ;
unsigned long V_68 ;
if ( ! F_18 ( V_14 ) ) {
F_20 ( F_5 ( & V_14 -> V_6 ) ,
L_18 ) ;
return;
}
F_69 ( & V_14 -> V_67 , V_68 ) ;
if ( F_70 ( 0 , & V_14 -> V_117 ) )
F_32 ( V_14 ) ;
else
F_35 ( V_14 ) ;
F_71 ( & V_14 -> V_67 , V_68 ) ;
}
static T_5 F_72 ( int V_118 , void * V_119 )
{
struct V_7 * V_19 = (struct V_7 * ) V_119 ;
struct V_4 * V_14 ;
T_1 V_120 ;
T_1 V_121 ;
int V_74 ;
int V_122 = V_123 ;
int V_124 = V_123 ;
V_120 = F_11 ( V_19 , V_38 ) ;
V_121 = F_11 ( V_19 , V_42 ) ;
F_13 ( V_19 -> V_10 . V_12 , L_19 , V_120 ) ;
for ( V_74 = 0 ; V_74 < V_19 -> V_10 . V_125 ; V_74 ++ ) {
V_14 = & V_19 -> V_126 [ V_74 ] ;
if ( V_74 < 8 ) {
if ( V_120 & F_73 ( V_74 ) ) {
if ( V_120 & F_74 ( V_74 ) )
F_75 ( 0 , & V_14 -> V_117 ) ;
F_76 ( & V_14 -> V_127 ) ;
V_122 = V_128 ;
}
} else {
if ( V_121 & F_73 ( V_74 - 8 ) ) {
if ( V_121 & F_77 ( V_74 ) )
F_75 ( 0 , & V_14 -> V_117 ) ;
F_76 ( & V_14 -> V_127 ) ;
V_124 = V_128 ;
}
}
}
if ( V_122 )
F_12 ( V_19 , V_38 , V_120 ) ;
if ( V_124 )
F_12 ( V_19 , V_42 , V_121 ) ;
return V_122 | V_124 ;
}
static void F_78 ( struct V_7 * V_19 )
{
struct V_4 * V_14 ;
struct V_5 * V_6 , * V_129 ;
int V_74 = 0 ;
V_19 -> V_46 . V_130 = F_11 ( V_19 , V_26 ) ;
V_19 -> V_46 . V_131 = F_11 ( V_19 , V_132 ) ;
V_19 -> V_46 . V_133 = F_11 ( V_19 , V_23 ) ;
V_19 -> V_46 . V_134 = F_11 ( V_19 , V_34 ) ;
F_31 (chan, _c, &pd->dma.channels, device_node) {
V_14 = F_3 ( V_6 ) ;
V_19 -> V_135 [ V_74 ] . V_47 = F_79 ( V_14 , V_52 ) ;
V_19 -> V_135 [ V_74 ] . V_48 = F_79 ( V_14 , V_53 ) ;
V_19 -> V_135 [ V_74 ] . V_49 = F_79 ( V_14 , V_54 ) ;
V_19 -> V_135 [ V_74 ] . V_50 = F_79 ( V_14 , V_55 ) ;
V_74 ++ ;
}
}
static void F_80 ( struct V_7 * V_19 )
{
struct V_4 * V_14 ;
struct V_5 * V_6 , * V_129 ;
int V_74 = 0 ;
F_12 ( V_19 , V_26 , V_19 -> V_46 . V_130 ) ;
F_12 ( V_19 , V_132 , V_19 -> V_46 . V_131 ) ;
F_12 ( V_19 , V_23 , V_19 -> V_46 . V_133 ) ;
F_12 ( V_19 , V_34 , V_19 -> V_46 . V_134 ) ;
F_31 (chan, _c, &pd->dma.channels, device_node) {
V_14 = F_3 ( V_6 ) ;
F_22 ( V_14 , V_52 , V_19 -> V_135 [ V_74 ] . V_47 ) ;
F_22 ( V_14 , V_53 , V_19 -> V_135 [ V_74 ] . V_48 ) ;
F_22 ( V_14 , V_54 , V_19 -> V_135 [ V_74 ] . V_49 ) ;
F_22 ( V_14 , V_55 , V_19 -> V_135 [ V_74 ] . V_50 ) ;
V_74 ++ ;
}
}
static int F_81 ( struct V_136 * V_137 , T_6 V_138 )
{
struct V_7 * V_19 = F_82 ( V_137 ) ;
if ( V_19 )
F_78 ( V_19 ) ;
F_83 ( V_137 ) ;
F_84 ( V_137 ) ;
F_85 ( V_137 , F_86 ( V_137 , V_138 ) ) ;
return 0 ;
}
static int F_87 ( struct V_136 * V_137 )
{
struct V_7 * V_19 = F_82 ( V_137 ) ;
int V_139 ;
F_85 ( V_137 , V_140 ) ;
F_88 ( V_137 ) ;
V_139 = F_89 ( V_137 ) ;
if ( V_139 ) {
F_13 ( & V_137 -> V_12 , L_20 ) ;
return V_139 ;
}
if ( V_19 )
F_80 ( V_19 ) ;
return 0 ;
}
static int F_90 ( struct V_136 * V_137 ,
const struct V_141 * V_142 )
{
struct V_7 * V_19 ;
struct V_143 * V_46 ;
unsigned int V_144 ;
int V_139 ;
int V_74 ;
V_144 = V_142 -> V_145 ;
V_19 = F_91 ( sizeof( * V_19 ) , V_80 ) ;
if ( ! V_19 )
return - V_146 ;
F_92 ( V_137 , V_19 ) ;
V_139 = F_89 ( V_137 ) ;
if ( V_139 ) {
F_20 ( & V_137 -> V_12 , L_21 ) ;
goto V_147;
}
if ( ! ( F_93 ( V_137 , 1 ) & V_148 ) ) {
F_20 ( & V_137 -> V_12 , L_22 ) ;
V_139 = - V_149 ;
goto V_150;
}
V_139 = F_94 ( V_137 , V_151 ) ;
if ( V_139 ) {
F_20 ( & V_137 -> V_12 , L_23 ) ;
goto V_150;
}
V_139 = F_95 ( V_137 , F_96 ( 32 ) ) ;
if ( V_139 ) {
F_20 ( & V_137 -> V_12 , L_24 ) ;
goto V_152;
}
V_46 = V_19 -> V_153 = F_97 ( V_137 , 1 , 0 ) ;
if ( ! V_19 -> V_153 ) {
F_20 ( & V_137 -> V_12 , L_25 ) ;
V_139 = - V_146 ;
goto V_152;
}
F_98 ( V_137 ) ;
V_139 = F_99 ( V_137 -> V_118 , F_72 , V_154 , V_151 , V_19 ) ;
if ( V_139 ) {
F_20 ( & V_137 -> V_12 , L_26 ) ;
goto V_155;
}
V_19 -> V_70 = F_100 ( L_27 , V_137 ,
sizeof( struct V_1 ) , 4 , 0 ) ;
if ( ! V_19 -> V_70 ) {
F_20 ( & V_137 -> V_12 , L_28 ) ;
V_139 = - V_146 ;
goto V_156;
}
V_19 -> V_10 . V_12 = & V_137 -> V_12 ;
F_44 ( & V_19 -> V_10 . V_126 ) ;
for ( V_74 = 0 ; V_74 < V_144 ; V_74 ++ ) {
struct V_4 * V_14 = & V_19 -> V_126 [ V_74 ] ;
V_14 -> V_6 . V_11 = & V_19 -> V_10 ;
F_54 ( & V_14 -> V_6 ) ;
V_14 -> V_153 = & V_46 -> V_45 [ V_74 ] ;
F_101 ( & V_14 -> V_67 ) ;
F_44 ( & V_14 -> V_15 ) ;
F_44 ( & V_14 -> V_17 ) ;
F_44 ( & V_14 -> V_61 ) ;
F_102 ( & V_14 -> V_127 , F_68 ,
( unsigned long ) V_14 ) ;
F_40 ( & V_14 -> V_6 . V_157 , & V_19 -> V_10 . V_126 ) ;
}
F_103 ( V_19 -> V_10 . V_158 ) ;
F_104 ( V_159 , V_19 -> V_10 . V_158 ) ;
F_104 ( V_160 , V_19 -> V_10 . V_158 ) ;
V_19 -> V_10 . V_161 = F_50 ;
V_19 -> V_10 . V_162 = F_56 ;
V_19 -> V_10 . V_163 = F_58 ;
V_19 -> V_10 . V_164 = F_60 ;
V_19 -> V_10 . V_165 = F_61 ;
V_19 -> V_10 . V_166 = F_67 ;
V_139 = F_105 ( & V_19 -> V_10 ) ;
if ( V_139 ) {
F_20 ( & V_137 -> V_12 , L_29 ) ;
goto V_167;
}
return 0 ;
V_167:
F_106 ( V_19 -> V_70 ) ;
V_156:
F_107 ( V_137 -> V_118 , V_19 ) ;
V_155:
F_108 ( V_137 , V_19 -> V_153 ) ;
V_152:
F_109 ( V_137 ) ;
V_150:
F_84 ( V_137 ) ;
V_147:
F_110 ( V_19 ) ;
return V_139 ;
}
static void F_111 ( struct V_136 * V_137 )
{
struct V_7 * V_19 = F_82 ( V_137 ) ;
struct V_4 * V_14 ;
struct V_5 * V_6 , * V_129 ;
if ( V_19 ) {
F_112 ( & V_19 -> V_10 ) ;
F_107 ( V_137 -> V_118 , V_19 ) ;
F_31 (chan, _c, &pd->dma.channels,
device_node) {
V_14 = F_3 ( V_6 ) ;
F_113 ( & V_14 -> V_127 ) ;
}
F_106 ( V_19 -> V_70 ) ;
F_108 ( V_137 , V_19 -> V_153 ) ;
F_109 ( V_137 ) ;
F_84 ( V_137 ) ;
F_110 ( V_19 ) ;
}
}
