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
static T_3 F_35 ( struct V_4 * V_14 ,
struct V_1 * V_45 )
{
T_3 V_67 = V_14 -> V_6 . V_67 ;
if ( ++ V_67 < 0 )
V_67 = 1 ;
V_14 -> V_6 . V_67 = V_67 ;
V_45 -> V_3 . V_67 = V_67 ;
return V_67 ;
}
static T_3 F_36 ( struct V_2 * V_3 )
{
struct V_1 * V_45 = F_1 ( V_3 ) ;
struct V_4 * V_14 = F_3 ( V_3 -> V_6 ) ;
T_3 V_67 ;
F_37 ( & V_14 -> V_68 ) ;
V_67 = F_35 ( V_14 , V_45 ) ;
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
V_45 -> V_3 . V_72 = F_36 ;
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
F_37 ( & V_14 -> V_68 ) ;
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
F_37 ( & V_14 -> V_68 ) ;
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
F_37 ( & V_14 -> V_68 ) ;
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
V_14 -> V_82 = V_6 -> V_67 = 1 ;
F_52 ( & V_14 -> V_68 ) ;
F_10 ( V_6 , 1 ) ;
return V_14 -> V_77 ;
}
static void F_53 ( struct V_5 * V_6 )
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
F_52 ( & V_14 -> V_68 ) ;
F_29 (desc, _d, &tmp_list, desc_node)
F_54 ( V_19 -> V_71 , V_45 , V_45 -> V_3 . V_57 ) ;
F_10 ( V_6 , 0 ) ;
}
static enum V_83 F_55 ( struct V_5 * V_6 , T_3 V_67 ,
struct V_84 * V_85 )
{
struct V_4 * V_14 = F_3 ( V_6 ) ;
T_3 V_86 ;
T_3 V_87 ;
int V_74 ;
F_50 ( & V_14 -> V_68 ) ;
V_87 = V_14 -> V_82 ;
V_86 = V_6 -> V_67 ;
F_52 ( & V_14 -> V_68 ) ;
V_74 = F_56 ( V_67 , V_87 , V_86 ) ;
F_57 ( V_85 , V_87 , V_86 , 0 ) ;
return V_74 ;
}
static void F_58 ( struct V_5 * V_6 )
{
struct V_4 * V_14 = F_3 ( V_6 ) ;
if ( F_18 ( V_14 ) ) {
F_37 ( & V_14 -> V_68 ) ;
F_33 ( V_14 ) ;
F_39 ( & V_14 -> V_68 ) ;
}
}
static struct V_2 * F_59 ( struct V_5 * V_6 ,
struct V_88 * V_89 , unsigned int V_90 ,
enum V_91 V_92 , unsigned long V_69 )
{
struct V_4 * V_14 = F_3 ( V_6 ) ;
struct V_93 * V_94 = V_6 -> V_95 ;
struct V_1 * V_96 = NULL ;
struct V_1 * V_66 = NULL ;
struct V_1 * V_45 = NULL ;
struct V_88 * V_97 ;
T_5 V_98 ;
int V_75 ;
if ( F_60 ( ! V_90 ) ) {
F_61 ( F_5 ( V_6 ) , L_16 ) ;
return NULL ;
}
if ( V_92 == V_99 )
V_98 = V_94 -> V_100 ;
else if ( V_92 == V_31 )
V_98 = V_94 -> V_101 ;
else
return NULL ;
V_14 -> V_30 = V_92 ;
F_14 ( V_6 ) ;
F_62 (sgl, sg, sg_len, i) {
V_45 = F_44 ( V_14 ) ;
if ( ! V_45 )
goto V_102;
V_45 -> V_46 . V_47 = V_98 ;
V_45 -> V_46 . V_48 = F_63 ( V_97 ) ;
V_45 -> V_46 . V_49 = F_64 ( V_97 ) ;
V_45 -> V_46 . V_50 = V_103 ;
switch ( V_94 -> V_104 ) {
case V_105 :
if ( V_45 -> V_46 . V_49 > V_106 )
goto V_102;
V_45 -> V_46 . V_49 |= V_107 ;
break;
case V_108 :
if ( V_45 -> V_46 . V_49 > V_109 )
goto V_102;
V_45 -> V_46 . V_49 |= V_110 ;
break;
case V_111 :
if ( V_45 -> V_46 . V_49 > V_112 )
goto V_102;
V_45 -> V_46 . V_49 |= V_113 ;
break;
default:
goto V_102;
}
if ( ! V_96 ) {
V_96 = V_45 ;
} else {
V_66 -> V_46 . V_50 |= V_45 -> V_3 . V_57 ;
F_38 ( & V_45 -> V_16 , & V_96 -> V_51 ) ;
}
V_66 = V_45 ;
}
if ( V_69 & V_114 )
V_45 -> V_46 . V_50 = V_115 ;
else
V_45 -> V_46 . V_50 = V_116 ;
V_96 -> V_3 . V_67 = - V_117 ;
V_45 -> V_3 . V_69 = V_69 ;
return & V_96 -> V_3 ;
V_102:
F_20 ( F_5 ( V_6 ) , L_17 ) ;
F_46 ( V_14 , V_96 ) ;
return NULL ;
}
static int F_65 ( struct V_5 * V_6 , enum V_118 V_119 ,
unsigned long V_120 )
{
struct V_4 * V_14 = F_3 ( V_6 ) ;
struct V_1 * V_45 , * V_63 ;
F_27 ( V_64 ) ;
if ( V_119 != V_121 )
return - V_122 ;
F_50 ( & V_14 -> V_68 ) ;
F_15 ( & V_14 -> V_6 , V_123 ) ;
F_24 ( & V_14 -> V_15 , & V_64 ) ;
F_24 ( & V_14 -> V_17 , & V_64 ) ;
F_29 (desc, _d, &list, desc_node)
F_23 ( V_14 , V_45 ) ;
F_52 ( & V_14 -> V_68 ) ;
return 0 ;
}
static void F_66 ( unsigned long V_124 )
{
struct V_4 * V_14 = (struct V_4 * ) V_124 ;
unsigned long V_69 ;
if ( ! F_18 ( V_14 ) ) {
F_20 ( F_5 ( & V_14 -> V_6 ) ,
L_18 ) ;
return;
}
F_67 ( & V_14 -> V_68 , V_69 ) ;
if ( F_68 ( 0 , & V_14 -> V_125 ) )
F_30 ( V_14 ) ;
else
F_33 ( V_14 ) ;
F_69 ( & V_14 -> V_68 , V_69 ) ;
}
static T_6 F_70 ( int V_126 , void * V_127 )
{
struct V_7 * V_19 = (struct V_7 * ) V_127 ;
struct V_4 * V_14 ;
T_1 V_128 ;
T_1 V_129 ;
int V_75 ;
int V_130 = V_131 ;
int V_132 = V_131 ;
V_128 = F_11 ( V_19 , V_38 ) ;
V_129 = F_11 ( V_19 , V_42 ) ;
F_13 ( V_19 -> V_10 . V_12 , L_19 , V_128 ) ;
for ( V_75 = 0 ; V_75 < V_19 -> V_10 . V_133 ; V_75 ++ ) {
V_14 = & V_19 -> V_134 [ V_75 ] ;
if ( V_75 < 8 ) {
if ( V_128 & F_71 ( V_75 ) ) {
if ( V_128 & F_72 ( V_75 ) )
F_73 ( 0 , & V_14 -> V_125 ) ;
F_74 ( & V_14 -> V_135 ) ;
V_130 = V_136 ;
}
} else {
if ( V_129 & F_71 ( V_75 - 8 ) ) {
if ( V_129 & F_75 ( V_75 ) )
F_73 ( 0 , & V_14 -> V_125 ) ;
F_74 ( & V_14 -> V_135 ) ;
V_132 = V_136 ;
}
}
}
if ( V_130 )
F_12 ( V_19 , V_38 , V_128 ) ;
if ( V_132 )
F_12 ( V_19 , V_42 , V_129 ) ;
return V_130 | V_132 ;
}
static void F_76 ( struct V_7 * V_19 )
{
struct V_4 * V_14 ;
struct V_5 * V_6 , * V_137 ;
int V_75 = 0 ;
V_19 -> V_46 . V_138 = F_11 ( V_19 , V_26 ) ;
V_19 -> V_46 . V_139 = F_11 ( V_19 , V_140 ) ;
V_19 -> V_46 . V_141 = F_11 ( V_19 , V_23 ) ;
V_19 -> V_46 . V_142 = F_11 ( V_19 , V_34 ) ;
F_29 (chan, _c, &pd->dma.channels, device_node) {
V_14 = F_3 ( V_6 ) ;
V_19 -> V_143 [ V_75 ] . V_47 = F_77 ( V_14 , V_52 ) ;
V_19 -> V_143 [ V_75 ] . V_48 = F_77 ( V_14 , V_53 ) ;
V_19 -> V_143 [ V_75 ] . V_49 = F_77 ( V_14 , V_54 ) ;
V_19 -> V_143 [ V_75 ] . V_50 = F_77 ( V_14 , V_55 ) ;
V_75 ++ ;
}
}
static void F_78 ( struct V_7 * V_19 )
{
struct V_4 * V_14 ;
struct V_5 * V_6 , * V_137 ;
int V_75 = 0 ;
F_12 ( V_19 , V_26 , V_19 -> V_46 . V_138 ) ;
F_12 ( V_19 , V_140 , V_19 -> V_46 . V_139 ) ;
F_12 ( V_19 , V_23 , V_19 -> V_46 . V_141 ) ;
F_12 ( V_19 , V_34 , V_19 -> V_46 . V_142 ) ;
F_29 (chan, _c, &pd->dma.channels, device_node) {
V_14 = F_3 ( V_6 ) ;
F_22 ( V_14 , V_52 , V_19 -> V_143 [ V_75 ] . V_47 ) ;
F_22 ( V_14 , V_53 , V_19 -> V_143 [ V_75 ] . V_48 ) ;
F_22 ( V_14 , V_54 , V_19 -> V_143 [ V_75 ] . V_49 ) ;
F_22 ( V_14 , V_55 , V_19 -> V_143 [ V_75 ] . V_50 ) ;
V_75 ++ ;
}
}
static int F_79 ( struct V_144 * V_145 , T_7 V_146 )
{
struct V_7 * V_19 = F_80 ( V_145 ) ;
if ( V_19 )
F_76 ( V_19 ) ;
F_81 ( V_145 ) ;
F_82 ( V_145 ) ;
F_83 ( V_145 , F_84 ( V_145 , V_146 ) ) ;
return 0 ;
}
static int F_85 ( struct V_144 * V_145 )
{
struct V_7 * V_19 = F_80 ( V_145 ) ;
int V_147 ;
F_83 ( V_145 , V_148 ) ;
F_86 ( V_145 ) ;
V_147 = F_87 ( V_145 ) ;
if ( V_147 ) {
F_13 ( & V_145 -> V_12 , L_20 ) ;
return V_147 ;
}
if ( V_19 )
F_78 ( V_19 ) ;
return 0 ;
}
static int T_8 F_88 ( struct V_144 * V_145 ,
const struct V_149 * V_150 )
{
struct V_7 * V_19 ;
struct V_151 * V_46 ;
unsigned int V_152 ;
int V_147 ;
int V_75 ;
V_152 = V_150 -> V_153 ;
V_19 = F_89 ( sizeof( * V_19 ) , V_81 ) ;
if ( ! V_19 )
return - V_154 ;
F_90 ( V_145 , V_19 ) ;
V_147 = F_87 ( V_145 ) ;
if ( V_147 ) {
F_20 ( & V_145 -> V_12 , L_21 ) ;
goto V_155;
}
if ( ! ( F_91 ( V_145 , 1 ) & V_156 ) ) {
F_20 ( & V_145 -> V_12 , L_22 ) ;
goto V_157;
}
V_147 = F_92 ( V_145 , V_158 ) ;
if ( V_147 ) {
F_20 ( & V_145 -> V_12 , L_23 ) ;
goto V_157;
}
V_147 = F_93 ( V_145 , F_94 ( 32 ) ) ;
if ( V_147 ) {
F_20 ( & V_145 -> V_12 , L_24 ) ;
goto V_159;
}
V_46 = V_19 -> V_160 = F_95 ( V_145 , 1 , 0 ) ;
if ( ! V_19 -> V_160 ) {
F_20 ( & V_145 -> V_12 , L_25 ) ;
V_147 = - V_154 ;
goto V_159;
}
F_96 ( V_145 ) ;
V_147 = F_97 ( V_145 -> V_126 , F_70 , V_161 , V_158 , V_19 ) ;
if ( V_147 ) {
F_20 ( & V_145 -> V_12 , L_26 ) ;
goto V_162;
}
V_19 -> V_71 = F_98 ( L_27 , V_145 ,
sizeof( struct V_1 ) , 4 , 0 ) ;
if ( ! V_19 -> V_71 ) {
F_20 ( & V_145 -> V_12 , L_28 ) ;
V_147 = - V_154 ;
goto V_163;
}
V_19 -> V_10 . V_12 = & V_145 -> V_12 ;
F_42 ( & V_19 -> V_10 . V_134 ) ;
for ( V_75 = 0 ; V_75 < V_152 ; V_75 ++ ) {
struct V_4 * V_14 = & V_19 -> V_134 [ V_75 ] ;
V_14 -> V_6 . V_11 = & V_19 -> V_10 ;
V_14 -> V_6 . V_67 = 1 ;
V_14 -> V_160 = & V_46 -> V_45 [ V_75 ] ;
F_99 ( & V_14 -> V_68 ) ;
F_42 ( & V_14 -> V_15 ) ;
F_42 ( & V_14 -> V_17 ) ;
F_42 ( & V_14 -> V_62 ) ;
F_100 ( & V_14 -> V_135 , F_66 ,
( unsigned long ) V_14 ) ;
F_38 ( & V_14 -> V_6 . V_164 , & V_19 -> V_10 . V_134 ) ;
}
F_101 ( V_19 -> V_10 . V_165 ) ;
F_102 ( V_166 , V_19 -> V_10 . V_165 ) ;
F_102 ( V_167 , V_19 -> V_10 . V_165 ) ;
V_19 -> V_10 . V_168 = F_48 ;
V_19 -> V_10 . V_169 = F_53 ;
V_19 -> V_10 . V_170 = F_55 ;
V_19 -> V_10 . V_171 = F_58 ;
V_19 -> V_10 . V_172 = F_59 ;
V_19 -> V_10 . V_173 = F_65 ;
V_147 = F_103 ( & V_19 -> V_10 ) ;
if ( V_147 ) {
F_20 ( & V_145 -> V_12 , L_29 ) ;
goto V_174;
}
return 0 ;
V_174:
F_104 ( V_19 -> V_71 ) ;
V_163:
F_105 ( V_145 -> V_126 , V_19 ) ;
V_162:
F_106 ( V_145 , V_19 -> V_160 ) ;
V_159:
F_107 ( V_145 ) ;
V_157:
F_82 ( V_145 ) ;
V_155:
return V_147 ;
}
static void T_9 F_108 ( struct V_144 * V_145 )
{
struct V_7 * V_19 = F_80 ( V_145 ) ;
struct V_4 * V_14 ;
struct V_5 * V_6 , * V_137 ;
if ( V_19 ) {
F_109 ( & V_19 -> V_10 ) ;
F_29 (chan, _c, &pd->dma.channels,
device_node) {
V_14 = F_3 ( V_6 ) ;
F_110 ( & V_14 -> V_135 ) ;
F_111 ( & V_14 -> V_135 ) ;
}
F_104 ( V_19 -> V_71 ) ;
F_105 ( V_145 -> V_126 , V_19 ) ;
F_106 ( V_145 , V_19 -> V_160 ) ;
F_107 ( V_145 ) ;
F_82 ( V_145 ) ;
F_112 ( V_19 ) ;
}
}
static int T_10 F_113 ( void )
{
return F_114 ( & V_175 ) ;
}
static void T_11 F_115 ( void )
{
F_116 ( & V_175 ) ;
}
