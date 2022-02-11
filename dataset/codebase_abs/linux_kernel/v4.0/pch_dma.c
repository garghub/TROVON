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
T_2 V_59 = V_3 -> V_59 ;
void * V_60 = V_3 -> V_61 ;
F_24 ( & V_45 -> V_51 , & V_14 -> V_62 ) ;
F_25 ( & V_45 -> V_16 , & V_14 -> V_62 ) ;
if ( V_59 )
V_59 ( V_60 ) ;
}
static void F_26 ( struct V_4 * V_14 )
{
struct V_1 * V_45 , * V_63 ;
F_27 ( V_64 ) ;
F_28 ( ! F_18 ( V_14 ) ) ;
if ( ! F_21 ( & V_14 -> V_17 ) )
F_19 ( V_14 , F_9 ( V_14 ) ) ;
F_24 ( & V_14 -> V_15 , & V_64 ) ;
F_24 ( & V_14 -> V_17 , & V_14 -> V_15 ) ;
F_29 (desc, _d, &list, desc_node)
F_23 ( V_14 , V_45 ) ;
}
static void F_30 ( struct V_4 * V_14 )
{
struct V_1 * V_65 ;
V_65 = F_7 ( V_14 ) ;
F_31 ( & V_65 -> V_16 ) ;
F_24 ( & V_14 -> V_17 , V_14 -> V_15 . V_66 ) ;
if ( ! F_21 ( & V_14 -> V_15 ) )
F_19 ( V_14 , F_7 ( V_14 ) ) ;
F_32 ( F_5 ( & V_14 -> V_6 ) , L_9 ) ;
F_32 ( F_5 ( & V_14 -> V_6 ) , L_10 ,
V_65 -> V_3 . V_67 ) ;
F_23 ( V_14 , V_65 ) ;
}
static void F_33 ( struct V_4 * V_14 )
{
if ( F_21 ( & V_14 -> V_15 ) ||
F_34 ( & V_14 -> V_15 ) ) {
F_26 ( V_14 ) ;
} else {
F_23 ( V_14 , F_7 ( V_14 ) ) ;
F_19 ( V_14 , F_7 ( V_14 ) ) ;
}
}
static T_3 F_35 ( struct V_2 * V_3 )
{
struct V_1 * V_45 = F_1 ( V_3 ) ;
struct V_4 * V_14 = F_3 ( V_3 -> V_6 ) ;
T_3 V_67 ;
F_36 ( & V_14 -> V_68 ) ;
V_67 = F_37 ( V_3 ) ;
if ( F_21 ( & V_14 -> V_15 ) ) {
F_38 ( & V_45 -> V_16 , & V_14 -> V_15 ) ;
F_19 ( V_14 , V_45 ) ;
} else {
F_38 ( & V_45 -> V_16 , & V_14 -> V_17 ) ;
}
F_39 ( & V_14 -> V_68 ) ;
return 0 ;
}
static struct V_1 * F_40 ( struct V_5 * V_6 , T_4 V_69 )
{
struct V_1 * V_45 = NULL ;
struct V_7 * V_19 = F_4 ( V_6 -> V_11 ) ;
T_5 V_70 ;
V_45 = F_41 ( V_19 -> V_71 , V_69 , & V_70 ) ;
if ( V_45 ) {
memset ( V_45 , 0 , sizeof( struct V_1 ) ) ;
F_42 ( & V_45 -> V_51 ) ;
F_43 ( & V_45 -> V_3 , V_6 ) ;
V_45 -> V_3 . V_72 = F_35 ;
V_45 -> V_3 . V_69 = V_73 ;
V_45 -> V_3 . V_57 = V_70 ;
}
return V_45 ;
}
static struct V_1 * F_44 ( struct V_4 * V_14 )
{
struct V_1 * V_45 , * V_63 ;
struct V_1 * V_74 = NULL ;
int V_75 = 0 ;
F_36 ( & V_14 -> V_68 ) ;
F_29 (desc, _d, &pd_chan->free_list, desc_node) {
V_75 ++ ;
if ( F_45 ( & V_45 -> V_3 ) ) {
F_31 ( & V_45 -> V_16 ) ;
V_74 = V_45 ;
break;
}
F_13 ( F_5 ( & V_14 -> V_6 ) , L_11 , V_45 ) ;
}
F_39 ( & V_14 -> V_68 ) ;
F_13 ( F_5 ( & V_14 -> V_6 ) , L_12 , V_75 ) ;
if ( ! V_74 ) {
V_74 = F_40 ( & V_14 -> V_6 , V_76 ) ;
if ( V_74 ) {
F_36 ( & V_14 -> V_68 ) ;
V_14 -> V_77 ++ ;
F_39 ( & V_14 -> V_68 ) ;
} else {
F_20 ( F_5 ( & V_14 -> V_6 ) ,
L_13 ) ;
}
}
return V_74 ;
}
static void F_46 ( struct V_4 * V_14 ,
struct V_1 * V_45 )
{
if ( V_45 ) {
F_36 ( & V_14 -> V_68 ) ;
F_24 ( & V_45 -> V_51 , & V_14 -> V_62 ) ;
F_47 ( & V_45 -> V_16 , & V_14 -> V_62 ) ;
F_39 ( & V_14 -> V_68 ) ;
}
}
static int F_48 ( struct V_5 * V_6 )
{
struct V_4 * V_14 = F_3 ( V_6 ) ;
struct V_1 * V_45 ;
F_27 ( V_78 ) ;
int V_75 ;
if ( ! F_18 ( V_14 ) ) {
F_13 ( F_5 ( V_6 ) , L_14 ) ;
return - V_79 ;
}
if ( ! F_21 ( & V_14 -> V_62 ) )
return V_14 -> V_77 ;
for ( V_75 = 0 ; V_75 < V_80 ; V_75 ++ ) {
V_45 = F_40 ( V_6 , V_81 ) ;
if ( ! V_45 ) {
F_49 ( F_5 ( V_6 ) ,
L_15 , V_75 ) ;
break;
}
F_38 ( & V_45 -> V_16 , & V_78 ) ;
}
F_50 ( & V_14 -> V_68 ) ;
F_51 ( & V_78 , & V_14 -> V_62 ) ;
V_14 -> V_77 = V_75 ;
F_52 ( V_6 ) ;
F_53 ( & V_14 -> V_68 ) ;
F_10 ( V_6 , 1 ) ;
return V_14 -> V_77 ;
}
static void F_54 ( struct V_5 * V_6 )
{
struct V_4 * V_14 = F_3 ( V_6 ) ;
struct V_7 * V_19 = F_4 ( V_6 -> V_11 ) ;
struct V_1 * V_45 , * V_63 ;
F_27 ( V_78 ) ;
F_28 ( ! F_18 ( V_14 ) ) ;
F_28 ( ! F_21 ( & V_14 -> V_15 ) ) ;
F_28 ( ! F_21 ( & V_14 -> V_17 ) ) ;
F_50 ( & V_14 -> V_68 ) ;
F_24 ( & V_14 -> V_62 , & V_78 ) ;
V_14 -> V_77 = 0 ;
F_53 ( & V_14 -> V_68 ) ;
F_29 (desc, _d, &tmp_list, desc_node)
F_55 ( V_19 -> V_71 , V_45 , V_45 -> V_3 . V_57 ) ;
F_10 ( V_6 , 0 ) ;
}
static enum V_82 F_56 ( struct V_5 * V_6 , T_3 V_67 ,
struct V_83 * V_84 )
{
return F_57 ( V_6 , V_67 , V_84 ) ;
}
static void F_58 ( struct V_5 * V_6 )
{
struct V_4 * V_14 = F_3 ( V_6 ) ;
if ( F_18 ( V_14 ) ) {
F_36 ( & V_14 -> V_68 ) ;
F_33 ( V_14 ) ;
F_39 ( & V_14 -> V_68 ) ;
}
}
static struct V_2 * F_59 ( struct V_5 * V_6 ,
struct V_85 * V_86 , unsigned int V_87 ,
enum V_88 V_89 , unsigned long V_69 ,
void * V_90 )
{
struct V_4 * V_14 = F_3 ( V_6 ) ;
struct V_91 * V_92 = V_6 -> V_93 ;
struct V_1 * V_94 = NULL ;
struct V_1 * V_66 = NULL ;
struct V_1 * V_45 = NULL ;
struct V_85 * V_95 ;
T_5 V_96 ;
int V_75 ;
if ( F_60 ( ! V_87 ) ) {
F_61 ( F_5 ( V_6 ) , L_16 ) ;
return NULL ;
}
if ( V_89 == V_97 )
V_96 = V_92 -> V_98 ;
else if ( V_89 == V_31 )
V_96 = V_92 -> V_99 ;
else
return NULL ;
V_14 -> V_30 = V_89 ;
F_14 ( V_6 ) ;
F_62 (sgl, sg, sg_len, i) {
V_45 = F_44 ( V_14 ) ;
if ( ! V_45 )
goto V_100;
V_45 -> V_46 . V_47 = V_96 ;
V_45 -> V_46 . V_48 = F_63 ( V_95 ) ;
V_45 -> V_46 . V_49 = F_64 ( V_95 ) ;
V_45 -> V_46 . V_50 = V_101 ;
switch ( V_92 -> V_102 ) {
case V_103 :
if ( V_45 -> V_46 . V_49 > V_104 )
goto V_100;
V_45 -> V_46 . V_49 |= V_105 ;
break;
case V_106 :
if ( V_45 -> V_46 . V_49 > V_107 )
goto V_100;
V_45 -> V_46 . V_49 |= V_108 ;
break;
case V_109 :
if ( V_45 -> V_46 . V_49 > V_110 )
goto V_100;
V_45 -> V_46 . V_49 |= V_111 ;
break;
default:
goto V_100;
}
if ( ! V_94 ) {
V_94 = V_45 ;
} else {
V_66 -> V_46 . V_50 |= V_45 -> V_3 . V_57 ;
F_38 ( & V_45 -> V_16 , & V_94 -> V_51 ) ;
}
V_66 = V_45 ;
}
if ( V_69 & V_112 )
V_45 -> V_46 . V_50 = V_113 ;
else
V_45 -> V_46 . V_50 = V_114 ;
V_94 -> V_3 . V_67 = - V_115 ;
V_45 -> V_3 . V_69 = V_69 ;
return & V_94 -> V_3 ;
V_100:
F_20 ( F_5 ( V_6 ) , L_17 ) ;
F_46 ( V_14 , V_94 ) ;
return NULL ;
}
static int F_65 ( struct V_5 * V_6 )
{
struct V_4 * V_14 = F_3 ( V_6 ) ;
struct V_1 * V_45 , * V_63 ;
F_27 ( V_64 ) ;
F_50 ( & V_14 -> V_68 ) ;
F_15 ( & V_14 -> V_6 , V_116 ) ;
F_24 ( & V_14 -> V_15 , & V_64 ) ;
F_24 ( & V_14 -> V_17 , & V_64 ) ;
F_29 (desc, _d, &list, desc_node)
F_23 ( V_14 , V_45 ) ;
F_53 ( & V_14 -> V_68 ) ;
return 0 ;
}
static void F_66 ( unsigned long V_117 )
{
struct V_4 * V_14 = (struct V_4 * ) V_117 ;
unsigned long V_69 ;
if ( ! F_18 ( V_14 ) ) {
F_20 ( F_5 ( & V_14 -> V_6 ) ,
L_18 ) ;
return;
}
F_67 ( & V_14 -> V_68 , V_69 ) ;
if ( F_68 ( 0 , & V_14 -> V_118 ) )
F_30 ( V_14 ) ;
else
F_33 ( V_14 ) ;
F_69 ( & V_14 -> V_68 , V_69 ) ;
}
static T_6 F_70 ( int V_119 , void * V_120 )
{
struct V_7 * V_19 = (struct V_7 * ) V_120 ;
struct V_4 * V_14 ;
T_1 V_121 ;
T_1 V_122 ;
int V_75 ;
int V_123 = V_124 ;
int V_125 = V_124 ;
V_121 = F_11 ( V_19 , V_38 ) ;
V_122 = F_11 ( V_19 , V_42 ) ;
F_13 ( V_19 -> V_10 . V_12 , L_19 , V_121 ) ;
for ( V_75 = 0 ; V_75 < V_19 -> V_10 . V_126 ; V_75 ++ ) {
V_14 = & V_19 -> V_127 [ V_75 ] ;
if ( V_75 < 8 ) {
if ( V_121 & F_71 ( V_75 ) ) {
if ( V_121 & F_72 ( V_75 ) )
F_73 ( 0 , & V_14 -> V_118 ) ;
F_74 ( & V_14 -> V_128 ) ;
V_123 = V_129 ;
}
} else {
if ( V_122 & F_71 ( V_75 - 8 ) ) {
if ( V_122 & F_75 ( V_75 ) )
F_73 ( 0 , & V_14 -> V_118 ) ;
F_74 ( & V_14 -> V_128 ) ;
V_125 = V_129 ;
}
}
}
if ( V_123 )
F_12 ( V_19 , V_38 , V_121 ) ;
if ( V_125 )
F_12 ( V_19 , V_42 , V_122 ) ;
return V_123 | V_125 ;
}
static void F_76 ( struct V_7 * V_19 )
{
struct V_4 * V_14 ;
struct V_5 * V_6 , * V_130 ;
int V_75 = 0 ;
V_19 -> V_46 . V_131 = F_11 ( V_19 , V_26 ) ;
V_19 -> V_46 . V_132 = F_11 ( V_19 , V_133 ) ;
V_19 -> V_46 . V_134 = F_11 ( V_19 , V_23 ) ;
V_19 -> V_46 . V_135 = F_11 ( V_19 , V_34 ) ;
F_29 (chan, _c, &pd->dma.channels, device_node) {
V_14 = F_3 ( V_6 ) ;
V_19 -> V_136 [ V_75 ] . V_47 = F_77 ( V_14 , V_52 ) ;
V_19 -> V_136 [ V_75 ] . V_48 = F_77 ( V_14 , V_53 ) ;
V_19 -> V_136 [ V_75 ] . V_49 = F_77 ( V_14 , V_54 ) ;
V_19 -> V_136 [ V_75 ] . V_50 = F_77 ( V_14 , V_55 ) ;
V_75 ++ ;
}
}
static void F_78 ( struct V_7 * V_19 )
{
struct V_4 * V_14 ;
struct V_5 * V_6 , * V_130 ;
int V_75 = 0 ;
F_12 ( V_19 , V_26 , V_19 -> V_46 . V_131 ) ;
F_12 ( V_19 , V_133 , V_19 -> V_46 . V_132 ) ;
F_12 ( V_19 , V_23 , V_19 -> V_46 . V_134 ) ;
F_12 ( V_19 , V_34 , V_19 -> V_46 . V_135 ) ;
F_29 (chan, _c, &pd->dma.channels, device_node) {
V_14 = F_3 ( V_6 ) ;
F_22 ( V_14 , V_52 , V_19 -> V_136 [ V_75 ] . V_47 ) ;
F_22 ( V_14 , V_53 , V_19 -> V_136 [ V_75 ] . V_48 ) ;
F_22 ( V_14 , V_54 , V_19 -> V_136 [ V_75 ] . V_49 ) ;
F_22 ( V_14 , V_55 , V_19 -> V_136 [ V_75 ] . V_50 ) ;
V_75 ++ ;
}
}
static int F_79 ( struct V_137 * V_138 , T_7 V_139 )
{
struct V_7 * V_19 = F_80 ( V_138 ) ;
if ( V_19 )
F_76 ( V_19 ) ;
F_81 ( V_138 ) ;
F_82 ( V_138 ) ;
F_83 ( V_138 , F_84 ( V_138 , V_139 ) ) ;
return 0 ;
}
static int F_85 ( struct V_137 * V_138 )
{
struct V_7 * V_19 = F_80 ( V_138 ) ;
int V_140 ;
F_83 ( V_138 , V_141 ) ;
F_86 ( V_138 ) ;
V_140 = F_87 ( V_138 ) ;
if ( V_140 ) {
F_13 ( & V_138 -> V_12 , L_20 ) ;
return V_140 ;
}
if ( V_19 )
F_78 ( V_19 ) ;
return 0 ;
}
static int F_88 ( struct V_137 * V_138 ,
const struct V_142 * V_143 )
{
struct V_7 * V_19 ;
struct V_144 * V_46 ;
unsigned int V_145 ;
int V_140 ;
int V_75 ;
V_145 = V_143 -> V_146 ;
V_19 = F_89 ( sizeof( * V_19 ) , V_81 ) ;
if ( ! V_19 )
return - V_147 ;
F_90 ( V_138 , V_19 ) ;
V_140 = F_87 ( V_138 ) ;
if ( V_140 ) {
F_20 ( & V_138 -> V_12 , L_21 ) ;
goto V_148;
}
if ( ! ( F_91 ( V_138 , 1 ) & V_149 ) ) {
F_20 ( & V_138 -> V_12 , L_22 ) ;
V_140 = - V_150 ;
goto V_151;
}
V_140 = F_92 ( V_138 , V_152 ) ;
if ( V_140 ) {
F_20 ( & V_138 -> V_12 , L_23 ) ;
goto V_151;
}
V_140 = F_93 ( V_138 , F_94 ( 32 ) ) ;
if ( V_140 ) {
F_20 ( & V_138 -> V_12 , L_24 ) ;
goto V_153;
}
V_46 = V_19 -> V_154 = F_95 ( V_138 , 1 , 0 ) ;
if ( ! V_19 -> V_154 ) {
F_20 ( & V_138 -> V_12 , L_25 ) ;
V_140 = - V_147 ;
goto V_153;
}
F_96 ( V_138 ) ;
V_140 = F_97 ( V_138 -> V_119 , F_70 , V_155 , V_152 , V_19 ) ;
if ( V_140 ) {
F_20 ( & V_138 -> V_12 , L_26 ) ;
goto V_156;
}
V_19 -> V_71 = F_98 ( L_27 , V_138 ,
sizeof( struct V_1 ) , 4 , 0 ) ;
if ( ! V_19 -> V_71 ) {
F_20 ( & V_138 -> V_12 , L_28 ) ;
V_140 = - V_147 ;
goto V_157;
}
V_19 -> V_10 . V_12 = & V_138 -> V_12 ;
F_42 ( & V_19 -> V_10 . V_127 ) ;
for ( V_75 = 0 ; V_75 < V_145 ; V_75 ++ ) {
struct V_4 * V_14 = & V_19 -> V_127 [ V_75 ] ;
V_14 -> V_6 . V_11 = & V_19 -> V_10 ;
F_52 ( & V_14 -> V_6 ) ;
V_14 -> V_154 = & V_46 -> V_45 [ V_75 ] ;
F_99 ( & V_14 -> V_68 ) ;
F_42 ( & V_14 -> V_15 ) ;
F_42 ( & V_14 -> V_17 ) ;
F_42 ( & V_14 -> V_62 ) ;
F_100 ( & V_14 -> V_128 , F_66 ,
( unsigned long ) V_14 ) ;
F_38 ( & V_14 -> V_6 . V_158 , & V_19 -> V_10 . V_127 ) ;
}
F_101 ( V_19 -> V_10 . V_159 ) ;
F_102 ( V_160 , V_19 -> V_10 . V_159 ) ;
F_102 ( V_161 , V_19 -> V_10 . V_159 ) ;
V_19 -> V_10 . V_162 = F_48 ;
V_19 -> V_10 . V_163 = F_54 ;
V_19 -> V_10 . V_164 = F_56 ;
V_19 -> V_10 . V_165 = F_58 ;
V_19 -> V_10 . V_166 = F_59 ;
V_19 -> V_10 . V_167 = F_65 ;
V_140 = F_103 ( & V_19 -> V_10 ) ;
if ( V_140 ) {
F_20 ( & V_138 -> V_12 , L_29 ) ;
goto V_168;
}
return 0 ;
V_168:
F_104 ( V_19 -> V_71 ) ;
V_157:
F_105 ( V_138 -> V_119 , V_19 ) ;
V_156:
F_106 ( V_138 , V_19 -> V_154 ) ;
V_153:
F_107 ( V_138 ) ;
V_151:
F_82 ( V_138 ) ;
V_148:
return V_140 ;
}
static void F_108 ( struct V_137 * V_138 )
{
struct V_7 * V_19 = F_80 ( V_138 ) ;
struct V_4 * V_14 ;
struct V_5 * V_6 , * V_130 ;
if ( V_19 ) {
F_109 ( & V_19 -> V_10 ) ;
F_105 ( V_138 -> V_119 , V_19 ) ;
F_29 (chan, _c, &pd->dma.channels,
device_node) {
V_14 = F_3 ( V_6 ) ;
F_110 ( & V_14 -> V_128 ) ;
}
F_104 ( V_19 -> V_71 ) ;
F_106 ( V_138 , V_19 -> V_154 ) ;
F_107 ( V_138 ) ;
F_82 ( V_138 ) ;
F_111 ( V_19 ) ;
}
}
