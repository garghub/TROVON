static int F_1 ( struct V_1 * V_2 )
{
unsigned int V_3 = F_2 ( V_2 -> V_4 + V_5 ) ;
return V_3 & V_6 ;
}
static bool F_3 ( struct V_7 * V_8 ,
struct V_1 * V_2 )
{
struct V_9 * V_10 = V_8 -> V_11 ;
const struct V_12 * V_13 = V_10 -> V_13 ;
struct V_14 * V_15 = & V_13 -> V_16 [ V_8 -> V_17 ] ;
int V_18 ;
if ( ! V_8 -> V_19 )
return true ;
if ( V_10 -> V_20 -> V_21 )
return true ;
V_18 = ( V_15 -> V_22 >> ( V_2 -> V_17 * V_23 ) ) ;
return ( V_18 & V_24 ) ? true : false ;
}
static
struct V_1 * F_4 ( struct V_7 * V_8 )
{
struct V_9 * V_10 = V_8 -> V_11 ;
const struct V_12 * V_13 = V_10 -> V_13 ;
struct V_14 * V_15 ;
struct V_1 * V_2 = NULL ;
unsigned long V_25 ;
int V_26 ;
int V_27 ;
if ( V_8 -> V_19 )
V_15 = & V_13 -> V_16 [ V_8 -> V_17 ] ;
for ( V_26 = 0 ; V_26 < V_10 -> V_13 -> V_28 ; V_26 ++ ) {
V_2 = & V_10 -> V_29 [ V_26 ] ;
if ( ! V_2 -> V_30 )
continue;
if ( ! F_3 ( V_8 , V_2 ) )
continue;
F_5 ( & V_2 -> V_31 , V_25 ) ;
if ( ! V_2 -> V_32 ) {
V_2 -> V_32 = V_8 ;
F_6 ( & V_2 -> V_31 , V_25 ) ;
break;
}
F_6 ( & V_2 -> V_31 , V_25 ) ;
}
if ( V_26 == V_10 -> V_13 -> V_28 ) {
F_7 ( & V_10 -> V_33 -> V_34 , L_1 ) ;
return NULL ;
}
if ( V_10 -> V_20 -> V_35 ) {
V_27 = F_8 ( V_2 -> V_36 ) ;
if ( V_27 ) {
F_9 ( & V_10 -> V_33 -> V_34 , L_2 ,
V_2 -> V_17 , V_27 ) ;
V_2 -> V_32 = NULL ;
return NULL ;
}
}
return V_2 ;
}
static inline void F_10 ( struct V_1 * V_2 )
{
struct V_9 * V_10 = V_2 -> V_11 ;
if ( V_10 -> V_20 -> V_35 )
F_11 ( V_2 -> V_36 ) ;
V_2 -> V_32 = NULL ;
}
static void F_12 ( struct V_1 * V_2 )
{
F_13 ( V_37 , V_2 -> V_4 + V_38 ) ;
}
static inline
struct V_7 * F_14 ( struct V_39 * V_40 )
{
return F_15 ( V_40 , struct V_7 , V_41 . V_40 ) ;
}
static T_1 F_16 ( struct V_7 * V_8 )
{
struct V_1 * V_2 = V_8 -> V_2 ;
struct V_42 * V_43 = V_8 -> V_44 ;
T_1 V_45 = F_2 ( V_2 -> V_4 + V_5 ) & V_46 ;
return V_45 * V_43 -> V_47 ;
}
static int F_17 ( struct V_39 * V_40 ,
struct V_48 * V_49 )
{
struct V_7 * V_8 = F_14 ( V_40 ) ;
unsigned long V_25 ;
int V_27 = 0 ;
if ( V_49 -> V_50 == V_51 ||
V_49 -> V_52 == V_51 )
return - V_53 ;
F_5 ( & V_8 -> V_41 . V_31 , V_25 ) ;
if ( ! V_8 -> V_19 ) {
V_27 = - V_53 ;
goto V_54;
}
V_8 -> V_55 = * V_49 ;
V_54:
F_6 ( & V_8 -> V_41 . V_31 , V_25 ) ;
return V_27 ;
}
static inline
struct V_42 * F_18 ( struct V_56 * V_57 )
{
return F_15 ( V_57 , struct V_42 , V_58 . V_57 ) ;
}
static struct V_42 * F_19 ( void )
{
struct V_42 * V_43 = F_20 ( sizeof( * V_43 ) , V_59 ) ;
if ( V_43 ) {
F_21 ( & V_43 -> V_60 ) ;
V_43 -> V_61 = V_62 | V_63 ;
}
return V_43 ;
}
static void F_22 ( struct V_42 * V_43 )
{
struct V_64 * V_65 , * V_66 ;
F_23 (dsg, _dsg, &txd->dsg_list, node) {
F_24 ( & V_65 -> V_67 ) ;
F_25 ( V_65 ) ;
}
F_25 ( V_43 ) ;
}
static void F_26 ( struct V_7 * V_8 ,
struct V_42 * V_43 )
{
struct V_9 * V_10 = V_8 -> V_11 ;
struct V_1 * V_2 = V_8 -> V_2 ;
const struct V_12 * V_13 = V_10 -> V_13 ;
struct V_64 * V_65 = F_27 ( V_43 -> V_44 , struct V_64 , V_67 ) ;
T_1 V_61 = V_43 -> V_61 ;
T_1 V_3 ;
switch ( V_43 -> V_47 ) {
case 1 :
V_61 |= V_68 | V_65 -> V_69 ;
break;
case 2 :
V_61 |= V_70 | ( V_65 -> V_69 / 2 ) ;
break;
case 4 :
V_61 |= V_71 | ( V_65 -> V_69 / 4 ) ;
break;
}
if ( V_8 -> V_19 ) {
struct V_14 * V_15 =
& V_13 -> V_16 [ V_8 -> V_17 ] ;
if ( V_10 -> V_20 -> V_21 ) {
F_28 ( ( V_15 -> V_22 << 1 ) |
V_72 ,
V_2 -> V_4 + V_73 ) ;
} else {
int V_74 = V_15 -> V_22 >> ( V_2 -> V_17 *
V_23 ) ;
V_74 &= V_75 ;
V_61 |= V_74 << V_76 ;
V_61 |= V_77 ;
}
} else {
if ( V_10 -> V_20 -> V_21 )
F_28 ( 0 , V_2 -> V_4 + V_73 ) ;
}
F_28 ( V_65 -> V_78 , V_2 -> V_4 + V_79 ) ;
F_28 ( V_43 -> V_80 , V_2 -> V_4 + V_81 ) ;
F_28 ( V_65 -> V_82 , V_2 -> V_4 + V_83 ) ;
F_28 ( V_43 -> V_84 , V_2 -> V_4 + V_85 ) ;
F_28 ( V_61 , V_2 -> V_4 + V_86 ) ;
V_3 = F_29 ( V_2 -> V_4 + V_38 ) ;
V_3 &= ~ V_37 ;
V_3 |= V_87 ;
if ( ! V_8 -> V_19 )
V_3 |= V_88 ;
F_13 ( V_3 , V_2 -> V_4 + V_38 ) ;
}
static void F_30 ( struct V_7 * V_8 )
{
struct V_1 * V_2 = V_8 -> V_2 ;
struct V_89 * V_58 = F_31 ( & V_8 -> V_41 ) ;
struct V_42 * V_43 = F_18 ( & V_58 -> V_57 ) ;
F_24 ( & V_43 -> V_58 . V_67 ) ;
V_8 -> V_44 = V_43 ;
while ( F_1 ( V_2 ) )
F_32 () ;
V_43 -> V_44 = V_43 -> V_60 . V_90 ;
F_26 ( V_8 , V_43 ) ;
}
static void F_33 ( struct V_9 * V_10 ,
struct V_7 * V_8 )
{
F_34 ( V_91 ) ;
F_35 ( & V_8 -> V_41 , & V_91 ) ;
F_36 ( & V_8 -> V_41 , & V_91 ) ;
}
static void F_37 ( struct V_7 * V_8 )
{
struct V_9 * V_10 = V_8 -> V_11 ;
struct V_1 * V_2 ;
V_2 = F_4 ( V_8 ) ;
if ( ! V_2 ) {
F_38 ( & V_10 -> V_33 -> V_34 , L_3 ,
V_8 -> V_92 ) ;
V_8 -> V_93 = V_94 ;
return;
}
F_38 ( & V_10 -> V_33 -> V_34 , L_4 ,
V_2 -> V_17 , V_8 -> V_92 ) ;
V_8 -> V_2 = V_2 ;
V_8 -> V_93 = V_95 ;
F_30 ( V_8 ) ;
}
static void F_39 ( struct V_1 * V_2 ,
struct V_7 * V_8 )
{
struct V_9 * V_10 = V_8 -> V_11 ;
F_38 ( & V_10 -> V_33 -> V_34 , L_5 ,
V_2 -> V_17 , V_8 -> V_92 ) ;
V_2 -> V_32 = V_8 ;
V_8 -> V_2 = V_2 ;
V_8 -> V_93 = V_95 ;
F_30 ( V_8 ) ;
}
static void F_40 ( struct V_7 * V_8 )
{
struct V_9 * V_10 = V_8 -> V_11 ;
struct V_7 * V_96 , * V_90 ;
V_97:
V_90 = NULL ;
F_41 (p, &s3cdma->memcpy.channels, vc.chan.device_node)
if ( V_96 -> V_93 == V_94 ) {
V_90 = V_96 ;
break;
}
if ( ! V_90 ) {
F_41 (p, &s3cdma->slave.channels,
vc.chan.device_node)
if ( V_96 -> V_93 == V_94 &&
F_3 ( V_96 , V_8 -> V_2 ) ) {
V_90 = V_96 ;
break;
}
}
F_12 ( V_8 -> V_2 ) ;
if ( V_90 ) {
bool V_98 ;
F_42 ( & V_90 -> V_41 . V_31 ) ;
V_98 = V_90 -> V_93 == V_94 ;
if ( V_98 )
F_39 ( V_8 -> V_2 , V_90 ) ;
F_43 ( & V_90 -> V_41 . V_31 ) ;
if ( ! V_98 )
goto V_97;
} else {
F_10 ( V_8 -> V_2 ) ;
}
V_8 -> V_2 = NULL ;
V_8 -> V_93 = V_99 ;
}
static void F_44 ( struct V_89 * V_58 )
{
struct V_42 * V_43 = F_18 ( & V_58 -> V_57 ) ;
struct V_7 * V_8 = F_14 ( V_58 -> V_57 . V_40 ) ;
if ( ! V_8 -> V_19 )
F_45 ( & V_58 -> V_57 ) ;
F_22 ( V_43 ) ;
}
static T_2 F_46 ( int V_100 , void * V_101 )
{
struct V_1 * V_2 = V_101 ;
struct V_7 * V_8 = V_2 -> V_32 ;
struct V_42 * V_43 ;
F_38 ( & V_2 -> V_11 -> V_33 -> V_34 , L_6 , V_2 -> V_17 ) ;
if ( F_47 ( ! V_8 ) ) {
F_9 ( & V_2 -> V_11 -> V_33 -> V_34 , L_7 ,
V_2 -> V_17 ) ;
F_12 ( V_2 ) ;
return V_102 ;
}
F_42 ( & V_8 -> V_41 . V_31 ) ;
V_43 = V_8 -> V_44 ;
if ( V_43 ) {
if ( ! F_48 ( V_43 -> V_44 , & V_43 -> V_60 ) ) {
V_43 -> V_44 = V_43 -> V_44 -> V_90 ;
if ( V_43 -> V_103 )
F_49 ( & V_43 -> V_58 ) ;
F_26 ( V_8 , V_43 ) ;
} else if ( ! V_43 -> V_103 ) {
V_8 -> V_44 = NULL ;
F_50 ( & V_43 -> V_58 ) ;
if ( F_31 ( & V_8 -> V_41 ) )
F_30 ( V_8 ) ;
else
F_40 ( V_8 ) ;
} else {
F_49 ( & V_43 -> V_58 ) ;
V_43 -> V_44 = V_43 -> V_60 . V_90 ;
F_26 ( V_8 , V_43 ) ;
}
}
F_43 ( & V_8 -> V_41 . V_31 ) ;
return V_102 ;
}
static int F_51 ( struct V_39 * V_40 )
{
struct V_7 * V_8 = F_14 ( V_40 ) ;
struct V_9 * V_10 = V_8 -> V_11 ;
unsigned long V_25 ;
int V_27 = 0 ;
F_5 ( & V_8 -> V_41 . V_31 , V_25 ) ;
if ( ! V_8 -> V_2 && ! V_8 -> V_44 ) {
F_9 ( & V_10 -> V_33 -> V_34 , L_8 ,
V_8 -> V_17 ) ;
V_27 = - V_53 ;
goto V_104;
}
V_8 -> V_93 = V_99 ;
if ( V_8 -> V_2 )
F_40 ( V_8 ) ;
if ( V_8 -> V_44 ) {
F_44 ( & V_8 -> V_44 -> V_58 ) ;
V_8 -> V_44 = NULL ;
}
F_33 ( V_10 , V_8 ) ;
V_104:
F_6 ( & V_8 -> V_41 . V_31 , V_25 ) ;
return V_27 ;
}
static void F_52 ( struct V_39 * V_40 )
{
F_53 ( F_54 ( V_40 ) ) ;
}
static enum V_105 F_55 ( struct V_39 * V_40 ,
T_3 V_106 , struct V_107 * V_108 )
{
struct V_7 * V_8 = F_14 ( V_40 ) ;
struct V_42 * V_43 ;
struct V_64 * V_65 ;
struct V_89 * V_58 ;
unsigned long V_25 ;
enum V_105 V_27 ;
T_4 V_109 = 0 ;
F_5 ( & V_8 -> V_41 . V_31 , V_25 ) ;
V_27 = F_56 ( V_40 , V_106 , V_108 ) ;
if ( V_27 == V_110 ) {
F_6 ( & V_8 -> V_41 . V_31 , V_25 ) ;
return V_27 ;
}
if ( ! V_108 ) {
F_6 ( & V_8 -> V_41 . V_31 , V_25 ) ;
return V_27 ;
}
V_58 = F_57 ( & V_8 -> V_41 , V_106 ) ;
if ( V_58 ) {
V_43 = F_18 ( & V_58 -> V_57 ) ;
F_41 (dsg, &txd->dsg_list, node)
V_109 += V_65 -> V_69 ;
} else {
V_43 = V_8 -> V_44 ;
V_65 = F_27 ( V_43 -> V_44 , struct V_64 , V_67 ) ;
F_58 (dsg, &txd->dsg_list, node)
V_109 += V_65 -> V_69 ;
V_109 += F_16 ( V_8 ) ;
}
F_6 ( & V_8 -> V_41 . V_31 , V_25 ) ;
F_59 ( V_108 , V_109 ) ;
return V_27 ;
}
static struct V_56 * F_60 (
struct V_39 * V_40 , T_5 V_111 , T_5 V_112 ,
T_4 V_69 , unsigned long V_25 )
{
struct V_7 * V_8 = F_14 ( V_40 ) ;
struct V_9 * V_10 = V_8 -> V_11 ;
struct V_42 * V_43 ;
struct V_64 * V_65 ;
int V_113 , V_114 ;
F_38 ( & V_10 -> V_33 -> V_34 , L_9 ,
V_69 , V_8 -> V_92 ) ;
if ( ( V_69 & V_115 ) != V_69 ) {
F_9 ( & V_10 -> V_33 -> V_34 , L_10 , V_69 ) ;
return NULL ;
}
V_43 = F_19 () ;
if ( ! V_43 )
return NULL ;
V_65 = F_20 ( sizeof( * V_65 ) , V_59 ) ;
if ( ! V_65 ) {
F_22 ( V_43 ) ;
return NULL ;
}
F_61 ( & V_65 -> V_67 , & V_43 -> V_60 ) ;
V_65 -> V_78 = V_112 ;
V_65 -> V_82 = V_111 ;
V_65 -> V_69 = V_69 ;
V_113 = V_112 % 4 ;
V_114 = V_111 % 4 ;
switch ( V_69 % 4 ) {
case 0 :
V_43 -> V_47 = ( V_113 == 0 && V_114 == 0 ) ? 4 : 1 ;
break;
case 2 :
V_43 -> V_47 = ( ( V_113 == 2 || V_113 == 0 ) &&
( V_114 == 2 || V_114 == 0 ) ) ? 2 : 1 ;
break;
default:
V_43 -> V_47 = 1 ;
break;
}
V_43 -> V_80 = V_116 | V_117 ;
V_43 -> V_84 = V_118 | V_119 ;
V_43 -> V_61 |= V_120 | V_121 |
V_122 ;
return F_62 ( & V_8 -> V_41 , & V_43 -> V_58 , V_25 ) ;
}
static struct V_56 * F_63 (
struct V_39 * V_40 , T_5 V_123 , T_4 V_124 , T_4 V_125 ,
enum V_126 V_127 , unsigned long V_25 )
{
struct V_7 * V_8 = F_14 ( V_40 ) ;
struct V_9 * V_10 = V_8 -> V_11 ;
const struct V_12 * V_13 = V_10 -> V_13 ;
struct V_14 * V_15 = & V_13 -> V_16 [ V_8 -> V_17 ] ;
struct V_42 * V_43 ;
struct V_64 * V_65 ;
unsigned V_128 ;
T_5 V_129 ;
T_1 V_130 = 0 ;
int V_26 ;
F_38 ( & V_10 -> V_33 -> V_34 ,
L_11 ,
V_124 , V_125 , V_8 -> V_92 ) ;
if ( ! F_64 ( V_127 ) ) {
F_9 ( & V_10 -> V_33 -> V_34 ,
L_12 , V_127 ) ;
return NULL ;
}
V_43 = F_19 () ;
if ( ! V_43 )
return NULL ;
V_43 -> V_103 = 1 ;
if ( V_15 -> V_131 )
V_43 -> V_61 |= V_132 ;
switch ( V_15 -> V_133 ) {
case V_134 :
V_43 -> V_61 |= V_135 ;
V_130 |= V_136 ;
break;
case V_137 :
V_43 -> V_61 |= V_121 ;
V_130 |= V_116 ;
break;
}
V_130 |= V_138 ;
V_43 -> V_61 |= V_139 ;
if ( V_127 == V_140 ) {
V_43 -> V_80 = V_116 |
V_117 ;
V_43 -> V_84 = V_130 ;
V_129 = V_8 -> V_55 . V_82 ;
V_43 -> V_47 = V_8 -> V_55 . V_52 ;
} else {
V_43 -> V_80 = V_130 ;
V_43 -> V_84 = V_118 |
V_119 ;
V_129 = V_8 -> V_55 . V_78 ;
V_43 -> V_47 = V_8 -> V_55 . V_50 ;
}
V_128 = V_124 / V_125 ;
for ( V_26 = 0 ; V_26 < V_128 ; V_26 ++ ) {
V_65 = F_20 ( sizeof( * V_65 ) , V_59 ) ;
if ( ! V_65 ) {
F_22 ( V_43 ) ;
return NULL ;
}
F_61 ( & V_65 -> V_67 , & V_43 -> V_60 ) ;
V_65 -> V_69 = V_125 ;
if ( V_26 == V_128 - 1 )
V_65 -> V_69 = V_124 - V_125 * V_26 ;
if ( V_127 == V_140 ) {
V_65 -> V_78 = V_123 + V_125 * V_26 ;
V_65 -> V_82 = V_129 ;
} else {
V_65 -> V_78 = V_129 ;
V_65 -> V_82 = V_123 + V_125 * V_26 ;
}
}
return F_62 ( & V_8 -> V_41 , & V_43 -> V_58 , V_25 ) ;
}
static struct V_56 * F_65 (
struct V_39 * V_40 , struct V_141 * V_142 ,
unsigned int V_128 , enum V_126 V_127 ,
unsigned long V_25 , void * V_143 )
{
struct V_7 * V_8 = F_14 ( V_40 ) ;
struct V_9 * V_10 = V_8 -> V_11 ;
const struct V_12 * V_13 = V_10 -> V_13 ;
struct V_14 * V_15 = & V_13 -> V_16 [ V_8 -> V_17 ] ;
struct V_42 * V_43 ;
struct V_64 * V_65 ;
struct V_141 * V_144 ;
T_5 V_129 ;
T_1 V_130 = 0 ;
int V_145 ;
F_38 ( & V_10 -> V_33 -> V_34 , L_13 ,
F_66 ( V_142 ) , V_8 -> V_92 ) ;
V_43 = F_19 () ;
if ( ! V_43 )
return NULL ;
if ( V_15 -> V_131 )
V_43 -> V_61 |= V_132 ;
switch ( V_15 -> V_133 ) {
case V_134 :
V_43 -> V_61 |= V_135 ;
V_130 |= V_136 ;
break;
case V_137 :
V_43 -> V_61 |= V_121 ;
V_130 |= V_116 ;
break;
}
V_130 |= V_138 ;
V_43 -> V_61 |= V_139 ;
if ( V_127 == V_140 ) {
V_43 -> V_80 = V_116 |
V_117 ;
V_43 -> V_84 = V_130 ;
V_129 = V_8 -> V_55 . V_82 ;
V_43 -> V_47 = V_8 -> V_55 . V_52 ;
} else if ( V_127 == V_146 ) {
V_43 -> V_80 = V_130 ;
V_43 -> V_84 = V_118 |
V_119 ;
V_129 = V_8 -> V_55 . V_78 ;
V_43 -> V_47 = V_8 -> V_55 . V_50 ;
} else {
F_22 ( V_43 ) ;
F_9 ( & V_10 -> V_33 -> V_34 ,
L_12 , V_127 ) ;
return NULL ;
}
F_67 (sgl, sg, sg_len, tmp) {
V_65 = F_20 ( sizeof( * V_65 ) , V_59 ) ;
if ( ! V_65 ) {
F_22 ( V_43 ) ;
return NULL ;
}
F_61 ( & V_65 -> V_67 , & V_43 -> V_60 ) ;
V_65 -> V_69 = F_66 ( V_144 ) ;
if ( V_127 == V_140 ) {
V_65 -> V_78 = F_68 ( V_144 ) ;
V_65 -> V_82 = V_129 ;
} else {
V_65 -> V_78 = V_129 ;
V_65 -> V_82 = F_68 ( V_144 ) ;
}
}
return F_62 ( & V_8 -> V_41 , & V_43 -> V_58 , V_25 ) ;
}
static void F_69 ( struct V_39 * V_40 )
{
struct V_7 * V_8 = F_14 ( V_40 ) ;
unsigned long V_25 ;
F_5 ( & V_8 -> V_41 . V_31 , V_25 ) ;
if ( F_70 ( & V_8 -> V_41 ) ) {
if ( ! V_8 -> V_2 && V_8 -> V_93 != V_94 )
F_37 ( V_8 ) ;
}
F_6 ( & V_8 -> V_41 . V_31 , V_25 ) ;
}
static int F_71 ( struct V_9 * V_10 ,
struct V_147 * V_148 , unsigned int V_16 , bool V_19 )
{
struct V_7 * V_40 ;
int V_26 ;
F_21 ( & V_148 -> V_16 ) ;
for ( V_26 = 0 ; V_26 < V_16 ; V_26 ++ ) {
V_40 = F_72 ( V_148 -> V_34 , sizeof( * V_40 ) , V_149 ) ;
if ( ! V_40 ) {
F_9 ( V_148 -> V_34 ,
L_14 , V_150 ) ;
return - V_151 ;
}
V_40 -> V_17 = V_26 ;
V_40 -> V_11 = V_10 ;
V_40 -> V_93 = V_99 ;
if ( V_19 ) {
V_40 -> V_19 = true ;
V_40 -> V_92 = F_73 ( V_149 , L_15 , V_26 ) ;
if ( ! V_40 -> V_92 )
return - V_151 ;
} else {
V_40 -> V_92 = F_73 ( V_149 , L_16 , V_26 ) ;
if ( ! V_40 -> V_92 )
return - V_151 ;
}
F_38 ( V_148 -> V_34 ,
L_17 ,
V_40 -> V_92 ) ;
V_40 -> V_41 . V_152 = F_44 ;
F_74 ( & V_40 -> V_41 , V_148 ) ;
}
F_75 ( V_148 -> V_34 , L_18 ,
V_26 , V_19 ? L_19 : L_20 ) ;
return V_26 ;
}
static void F_76 ( struct V_147 * V_148 )
{
struct V_7 * V_40 = NULL ;
struct V_7 * V_90 ;
F_23 (chan,
next, &dmadev->channels, vc.chan.device_node)
F_24 ( & V_40 -> V_41 . V_40 . V_153 ) ;
}
static struct V_154 * F_77 ( struct V_155 * V_33 )
{
return (struct V_154 * )
F_78 ( V_33 ) -> V_156 ;
}
static int F_79 ( struct V_155 * V_33 )
{
const struct V_12 * V_13 = F_80 ( & V_33 -> V_34 ) ;
struct V_9 * V_10 ;
struct V_154 * V_20 ;
struct V_157 * V_158 ;
int V_27 ;
int V_26 ;
if ( ! V_13 ) {
F_9 ( & V_33 -> V_34 , L_21 ) ;
return - V_159 ;
}
if ( V_13 -> V_28 > V_160 ) {
F_9 ( & V_33 -> V_34 , L_22 ,
V_13 -> V_28 , V_160 ) ;
return - V_53 ;
}
V_20 = F_77 ( V_33 ) ;
if ( ! V_20 )
return - V_53 ;
V_10 = F_72 ( & V_33 -> V_34 , sizeof( * V_10 ) , V_149 ) ;
if ( ! V_10 )
return - V_151 ;
V_10 -> V_33 = V_33 ;
V_10 -> V_13 = V_13 ;
V_10 -> V_20 = V_20 ;
V_158 = F_81 ( V_33 , V_161 , 0 ) ;
V_10 -> V_4 = F_82 ( & V_33 -> V_34 , V_158 ) ;
if ( F_83 ( V_10 -> V_4 ) )
return F_84 ( V_10 -> V_4 ) ;
V_10 -> V_29 = F_72 ( & V_33 -> V_34 ,
sizeof( struct V_1 ) *
V_13 -> V_28 ,
V_149 ) ;
if ( ! V_10 -> V_29 )
return - V_151 ;
for ( V_26 = 0 ; V_26 < V_13 -> V_28 ; V_26 ++ ) {
struct V_1 * V_2 = & V_10 -> V_29 [ V_26 ] ;
char V_162 [ 6 ] ;
V_2 -> V_17 = V_26 ;
V_2 -> V_4 = V_10 -> V_4 + ( V_26 * V_20 -> V_163 ) ;
V_2 -> V_11 = V_10 ;
V_2 -> V_100 = F_85 ( V_33 , V_26 ) ;
if ( V_2 -> V_100 < 0 ) {
F_9 ( & V_33 -> V_34 , L_23 ,
V_26 , V_2 -> V_100 ) ;
continue;
}
V_27 = F_86 ( & V_33 -> V_34 , V_2 -> V_100 , F_46 ,
0 , V_33 -> V_92 , V_2 ) ;
if ( V_27 ) {
F_9 ( & V_33 -> V_34 , L_24 ,
V_26 , V_27 ) ;
continue;
}
if ( V_20 -> V_35 ) {
sprintf ( V_162 , L_25 , V_26 ) ;
V_2 -> V_36 = F_87 ( & V_33 -> V_34 , V_162 ) ;
if ( F_83 ( V_2 -> V_36 ) && V_20 -> V_35 ) {
F_9 ( & V_33 -> V_34 , L_26 ,
V_26 , F_84 ( V_2 -> V_36 ) ) ;
continue;
}
V_27 = F_88 ( V_2 -> V_36 ) ;
if ( V_27 ) {
F_9 ( & V_33 -> V_34 , L_27 ,
V_26 , V_27 ) ;
continue;
}
}
F_89 ( & V_2 -> V_31 ) ;
V_2 -> V_30 = true ;
F_38 ( & V_33 -> V_34 , L_28 ,
V_26 , F_1 ( V_2 ) ? L_29 : L_30 ) ;
}
F_90 ( V_164 , V_10 -> memcpy . V_165 ) ;
F_90 ( V_166 , V_10 -> memcpy . V_165 ) ;
V_10 -> memcpy . V_34 = & V_33 -> V_34 ;
V_10 -> memcpy . V_167 =
F_52 ;
V_10 -> memcpy . V_168 = F_60 ;
V_10 -> memcpy . V_169 = F_55 ;
V_10 -> memcpy . V_170 = F_69 ;
V_10 -> memcpy . V_171 = F_17 ;
V_10 -> memcpy . V_172 = F_51 ;
F_90 ( V_173 , V_10 -> V_19 . V_165 ) ;
F_90 ( V_174 , V_10 -> V_19 . V_165 ) ;
F_90 ( V_166 , V_10 -> V_19 . V_165 ) ;
V_10 -> V_19 . V_34 = & V_33 -> V_34 ;
V_10 -> V_19 . V_167 =
F_52 ;
V_10 -> V_19 . V_169 = F_55 ;
V_10 -> V_19 . V_170 = F_69 ;
V_10 -> V_19 . V_175 = F_65 ;
V_10 -> V_19 . V_176 = F_63 ;
V_10 -> V_19 . V_171 = F_17 ;
V_10 -> V_19 . V_172 = F_51 ;
V_27 = F_71 ( V_10 , & V_10 -> memcpy ,
V_13 -> V_28 , false ) ;
if ( V_27 <= 0 ) {
F_7 ( & V_33 -> V_34 ,
L_31 ,
V_150 , V_27 ) ;
goto V_177;
}
V_27 = F_71 ( V_10 , & V_10 -> V_19 ,
V_13 -> V_178 , true ) ;
if ( V_27 <= 0 ) {
F_7 ( & V_33 -> V_34 ,
L_32 ,
V_150 , V_27 ) ;
goto V_179;
}
V_27 = F_91 ( & V_10 -> memcpy ) ;
if ( V_27 ) {
F_7 ( & V_33 -> V_34 ,
L_33 ,
V_150 , V_27 ) ;
goto V_180;
}
V_27 = F_91 ( & V_10 -> V_19 ) ;
if ( V_27 ) {
F_7 ( & V_33 -> V_34 ,
L_34 ,
V_150 , V_27 ) ;
goto V_181;
}
F_92 ( V_33 , V_10 ) ;
F_75 ( & V_33 -> V_34 , L_35 ,
V_13 -> V_28 ) ;
return 0 ;
V_181:
F_93 ( & V_10 -> memcpy ) ;
V_180:
F_76 ( & V_10 -> V_19 ) ;
V_179:
F_76 ( & V_10 -> memcpy ) ;
V_177:
if ( V_20 -> V_35 )
for ( V_26 = 0 ; V_26 < V_13 -> V_28 ; V_26 ++ ) {
struct V_1 * V_2 = & V_10 -> V_29 [ V_26 ] ;
if ( V_2 -> V_30 )
F_94 ( V_2 -> V_36 ) ;
}
return V_27 ;
}
static int F_95 ( struct V_155 * V_33 )
{
const struct V_12 * V_13 = F_80 ( & V_33 -> V_34 ) ;
struct V_9 * V_10 = F_96 ( V_33 ) ;
struct V_154 * V_20 = F_77 ( V_33 ) ;
int V_26 ;
F_93 ( & V_10 -> V_19 ) ;
F_93 ( & V_10 -> memcpy ) ;
F_76 ( & V_10 -> V_19 ) ;
F_76 ( & V_10 -> memcpy ) ;
if ( V_20 -> V_35 )
for ( V_26 = 0 ; V_26 < V_13 -> V_28 ; V_26 ++ ) {
struct V_1 * V_2 = & V_10 -> V_29 [ V_26 ] ;
if ( V_2 -> V_30 )
F_94 ( V_2 -> V_36 ) ;
}
return 0 ;
}
bool F_97 ( struct V_39 * V_40 , void * V_182 )
{
struct V_7 * V_8 ;
if ( V_40 -> V_183 -> V_34 -> V_184 != & V_185 . V_184 )
return false ;
V_8 = F_14 ( V_40 ) ;
return V_8 -> V_17 == ( int ) V_182 ;
}
