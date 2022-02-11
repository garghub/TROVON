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
static int F_17 ( struct V_7 * V_8 ,
struct V_48 * V_49 )
{
if ( ! V_8 -> V_19 )
return - V_50 ;
if ( V_49 -> V_51 == V_52 ||
V_49 -> V_53 == V_52 )
return - V_50 ;
V_8 -> V_54 = * V_49 ;
return 0 ;
}
static inline
struct V_42 * F_18 ( struct V_55 * V_56 )
{
return F_15 ( V_56 , struct V_42 , V_57 . V_56 ) ;
}
static struct V_42 * F_19 ( void )
{
struct V_42 * V_43 = F_20 ( sizeof( * V_43 ) , V_58 ) ;
if ( V_43 ) {
F_21 ( & V_43 -> V_59 ) ;
V_43 -> V_60 = V_61 | V_62 ;
}
return V_43 ;
}
static void F_22 ( struct V_42 * V_43 )
{
struct V_63 * V_64 , * V_65 ;
F_23 (dsg, _dsg, &txd->dsg_list, node) {
F_24 ( & V_64 -> V_66 ) ;
F_25 ( V_64 ) ;
}
F_25 ( V_43 ) ;
}
static void F_26 ( struct V_7 * V_8 ,
struct V_42 * V_43 )
{
struct V_9 * V_10 = V_8 -> V_11 ;
struct V_1 * V_2 = V_8 -> V_2 ;
const struct V_12 * V_13 = V_10 -> V_13 ;
struct V_63 * V_64 = F_27 ( V_43 -> V_44 , struct V_63 , V_66 ) ;
T_1 V_60 = V_43 -> V_60 ;
T_1 V_3 ;
switch ( V_43 -> V_47 ) {
case 1 :
V_60 |= V_67 | V_64 -> V_68 ;
break;
case 2 :
V_60 |= V_69 | ( V_64 -> V_68 / 2 ) ;
break;
case 4 :
V_60 |= V_70 | ( V_64 -> V_68 / 4 ) ;
break;
}
if ( V_8 -> V_19 ) {
struct V_14 * V_15 =
& V_13 -> V_16 [ V_8 -> V_17 ] ;
if ( V_10 -> V_20 -> V_21 ) {
F_28 ( ( V_15 -> V_22 << 1 ) |
V_71 ,
V_2 -> V_4 + V_72 ) ;
} else {
int V_73 = V_15 -> V_22 >> ( V_2 -> V_17 *
V_23 ) ;
V_73 &= V_74 ;
V_60 |= V_73 << V_75 ;
V_60 |= V_76 ;
}
} else {
if ( V_10 -> V_20 -> V_21 )
F_28 ( 0 , V_2 -> V_4 + V_72 ) ;
}
F_28 ( V_64 -> V_77 , V_2 -> V_4 + V_78 ) ;
F_28 ( V_43 -> V_79 , V_2 -> V_4 + V_80 ) ;
F_28 ( V_64 -> V_81 , V_2 -> V_4 + V_82 ) ;
F_28 ( V_43 -> V_83 , V_2 -> V_4 + V_84 ) ;
F_28 ( V_60 , V_2 -> V_4 + V_85 ) ;
V_3 = F_29 ( V_2 -> V_4 + V_38 ) ;
V_3 &= ~ V_37 ;
V_3 |= V_86 ;
if ( ! V_8 -> V_19 )
V_3 |= V_87 ;
F_13 ( V_3 , V_2 -> V_4 + V_38 ) ;
}
static void F_30 ( struct V_7 * V_8 )
{
struct V_1 * V_2 = V_8 -> V_2 ;
struct V_88 * V_57 = F_31 ( & V_8 -> V_41 ) ;
struct V_42 * V_43 = F_18 ( & V_57 -> V_56 ) ;
F_24 ( & V_43 -> V_57 . V_66 ) ;
V_8 -> V_44 = V_43 ;
while ( F_1 ( V_2 ) )
F_32 () ;
V_43 -> V_44 = V_43 -> V_59 . V_89 ;
F_26 ( V_8 , V_43 ) ;
}
static void F_33 ( struct V_9 * V_10 ,
struct V_7 * V_8 )
{
F_34 ( V_90 ) ;
F_35 ( & V_8 -> V_41 , & V_90 ) ;
F_36 ( & V_8 -> V_41 , & V_90 ) ;
}
static void F_37 ( struct V_7 * V_8 )
{
struct V_9 * V_10 = V_8 -> V_11 ;
struct V_1 * V_2 ;
V_2 = F_4 ( V_8 ) ;
if ( ! V_2 ) {
F_38 ( & V_10 -> V_33 -> V_34 , L_3 ,
V_8 -> V_91 ) ;
V_8 -> V_92 = V_93 ;
return;
}
F_38 ( & V_10 -> V_33 -> V_34 , L_4 ,
V_2 -> V_17 , V_8 -> V_91 ) ;
V_8 -> V_2 = V_2 ;
V_8 -> V_92 = V_94 ;
F_30 ( V_8 ) ;
}
static void F_39 ( struct V_1 * V_2 ,
struct V_7 * V_8 )
{
struct V_9 * V_10 = V_8 -> V_11 ;
F_38 ( & V_10 -> V_33 -> V_34 , L_5 ,
V_2 -> V_17 , V_8 -> V_91 ) ;
V_2 -> V_32 = V_8 ;
V_8 -> V_2 = V_2 ;
V_8 -> V_92 = V_94 ;
F_30 ( V_8 ) ;
}
static void F_40 ( struct V_7 * V_8 )
{
struct V_9 * V_10 = V_8 -> V_11 ;
struct V_7 * V_95 , * V_89 ;
V_96:
V_89 = NULL ;
F_41 (p, &s3cdma->memcpy.channels, vc.chan.device_node)
if ( V_95 -> V_92 == V_93 ) {
V_89 = V_95 ;
break;
}
if ( ! V_89 ) {
F_41 (p, &s3cdma->slave.channels,
vc.chan.device_node)
if ( V_95 -> V_92 == V_93 &&
F_3 ( V_95 , V_8 -> V_2 ) ) {
V_89 = V_95 ;
break;
}
}
F_12 ( V_8 -> V_2 ) ;
if ( V_89 ) {
bool V_97 ;
F_42 ( & V_89 -> V_41 . V_31 ) ;
V_97 = V_89 -> V_92 == V_93 ;
if ( V_97 )
F_39 ( V_8 -> V_2 , V_89 ) ;
F_43 ( & V_89 -> V_41 . V_31 ) ;
if ( ! V_97 )
goto V_96;
} else {
F_10 ( V_8 -> V_2 ) ;
}
V_8 -> V_2 = NULL ;
V_8 -> V_92 = V_98 ;
}
static void F_44 ( struct V_88 * V_57 )
{
struct V_42 * V_43 = F_18 ( & V_57 -> V_56 ) ;
struct V_7 * V_8 = F_14 ( V_57 -> V_56 . V_40 ) ;
if ( ! V_8 -> V_19 )
F_45 ( & V_57 -> V_56 ) ;
F_22 ( V_43 ) ;
}
static T_2 F_46 ( int V_99 , void * V_100 )
{
struct V_1 * V_2 = V_100 ;
struct V_7 * V_8 = V_2 -> V_32 ;
struct V_42 * V_43 ;
F_38 ( & V_2 -> V_11 -> V_33 -> V_34 , L_6 , V_2 -> V_17 ) ;
if ( F_47 ( ! V_8 ) ) {
F_9 ( & V_2 -> V_11 -> V_33 -> V_34 , L_7 ,
V_2 -> V_17 ) ;
F_12 ( V_2 ) ;
return V_101 ;
}
F_42 ( & V_8 -> V_41 . V_31 ) ;
V_43 = V_8 -> V_44 ;
if ( V_43 ) {
if ( ! F_48 ( V_43 -> V_44 , & V_43 -> V_59 ) ) {
V_43 -> V_44 = V_43 -> V_44 -> V_89 ;
if ( V_43 -> V_102 )
F_49 ( & V_43 -> V_57 ) ;
F_26 ( V_8 , V_43 ) ;
} else if ( ! V_43 -> V_102 ) {
V_8 -> V_44 = NULL ;
F_50 ( & V_43 -> V_57 ) ;
if ( F_31 ( & V_8 -> V_41 ) )
F_30 ( V_8 ) ;
else
F_40 ( V_8 ) ;
} else {
F_49 ( & V_43 -> V_57 ) ;
V_43 -> V_44 = V_43 -> V_59 . V_89 ;
F_26 ( V_8 , V_43 ) ;
}
}
F_43 ( & V_8 -> V_41 . V_31 ) ;
return V_101 ;
}
static int F_51 ( struct V_39 * V_40 , enum V_103 V_104 ,
unsigned long V_105 )
{
struct V_7 * V_8 = F_14 ( V_40 ) ;
struct V_9 * V_10 = V_8 -> V_11 ;
unsigned long V_25 ;
int V_27 = 0 ;
F_5 ( & V_8 -> V_41 . V_31 , V_25 ) ;
switch ( V_104 ) {
case V_106 :
V_27 = F_17 ( V_8 ,
(struct V_48 * ) V_105 ) ;
break;
case V_107 :
if ( ! V_8 -> V_2 && ! V_8 -> V_44 ) {
F_9 ( & V_10 -> V_33 -> V_34 , L_8 ,
V_8 -> V_17 ) ;
V_27 = - V_50 ;
break;
}
V_8 -> V_92 = V_98 ;
if ( V_8 -> V_2 )
F_40 ( V_8 ) ;
if ( V_8 -> V_44 ) {
F_44 ( & V_8 -> V_44 -> V_57 ) ;
V_8 -> V_44 = NULL ;
}
F_33 ( V_10 , V_8 ) ;
break;
default:
V_27 = - V_108 ;
break;
}
F_6 ( & V_8 -> V_41 . V_31 , V_25 ) ;
return V_27 ;
}
static int F_52 ( struct V_39 * V_40 )
{
return 0 ;
}
static void F_53 ( struct V_39 * V_40 )
{
F_54 ( F_55 ( V_40 ) ) ;
}
static enum V_109 F_56 ( struct V_39 * V_40 ,
T_3 V_110 , struct V_111 * V_112 )
{
struct V_7 * V_8 = F_14 ( V_40 ) ;
struct V_42 * V_43 ;
struct V_63 * V_64 ;
struct V_88 * V_57 ;
unsigned long V_25 ;
enum V_109 V_27 ;
T_4 V_113 = 0 ;
F_5 ( & V_8 -> V_41 . V_31 , V_25 ) ;
V_27 = F_57 ( V_40 , V_110 , V_112 ) ;
if ( V_27 == V_114 ) {
F_6 ( & V_8 -> V_41 . V_31 , V_25 ) ;
return V_27 ;
}
if ( ! V_112 ) {
F_6 ( & V_8 -> V_41 . V_31 , V_25 ) ;
return V_27 ;
}
V_57 = F_58 ( & V_8 -> V_41 , V_110 ) ;
if ( V_57 ) {
V_43 = F_18 ( & V_57 -> V_56 ) ;
F_41 (dsg, &txd->dsg_list, node)
V_113 += V_64 -> V_68 ;
} else {
V_43 = V_8 -> V_44 ;
V_64 = F_27 ( V_43 -> V_44 , struct V_63 , V_66 ) ;
F_59 (dsg, &txd->dsg_list, node)
V_113 += V_64 -> V_68 ;
V_113 += F_16 ( V_8 ) ;
}
F_6 ( & V_8 -> V_41 . V_31 , V_25 ) ;
F_60 ( V_112 , V_113 ) ;
return V_27 ;
}
static struct V_55 * F_61 (
struct V_39 * V_40 , T_5 V_115 , T_5 V_116 ,
T_4 V_68 , unsigned long V_25 )
{
struct V_7 * V_8 = F_14 ( V_40 ) ;
struct V_9 * V_10 = V_8 -> V_11 ;
struct V_42 * V_43 ;
struct V_63 * V_64 ;
int V_117 , V_118 ;
F_38 ( & V_10 -> V_33 -> V_34 , L_9 ,
V_68 , V_8 -> V_91 ) ;
if ( ( V_68 & V_119 ) != V_68 ) {
F_9 ( & V_10 -> V_33 -> V_34 , L_10 , V_68 ) ;
return NULL ;
}
V_43 = F_19 () ;
if ( ! V_43 )
return NULL ;
V_64 = F_20 ( sizeof( * V_64 ) , V_58 ) ;
if ( ! V_64 ) {
F_22 ( V_43 ) ;
return NULL ;
}
F_62 ( & V_64 -> V_66 , & V_43 -> V_59 ) ;
V_64 -> V_77 = V_116 ;
V_64 -> V_81 = V_115 ;
V_64 -> V_68 = V_68 ;
V_117 = V_116 % 4 ;
V_118 = V_115 % 4 ;
switch ( V_68 % 4 ) {
case 0 :
V_43 -> V_47 = ( V_117 == 0 && V_118 == 0 ) ? 4 : 1 ;
break;
case 2 :
V_43 -> V_47 = ( ( V_117 == 2 || V_117 == 0 ) &&
( V_118 == 2 || V_118 == 0 ) ) ? 2 : 1 ;
break;
default:
V_43 -> V_47 = 1 ;
break;
}
V_43 -> V_79 = V_120 | V_121 ;
V_43 -> V_83 = V_122 | V_123 ;
V_43 -> V_60 |= V_124 | V_125 |
V_126 ;
return F_63 ( & V_8 -> V_41 , & V_43 -> V_57 , V_25 ) ;
}
static struct V_55 * F_64 (
struct V_39 * V_40 , T_5 V_127 , T_4 V_128 , T_4 V_129 ,
enum V_130 V_131 , unsigned long V_25 )
{
struct V_7 * V_8 = F_14 ( V_40 ) ;
struct V_9 * V_10 = V_8 -> V_11 ;
const struct V_12 * V_13 = V_10 -> V_13 ;
struct V_14 * V_15 = & V_13 -> V_16 [ V_8 -> V_17 ] ;
struct V_42 * V_43 ;
struct V_63 * V_64 ;
unsigned V_132 ;
T_5 V_133 ;
T_1 V_134 = 0 ;
int V_26 ;
F_38 ( & V_10 -> V_33 -> V_34 ,
L_11 ,
V_128 , V_129 , V_8 -> V_91 ) ;
if ( ! F_65 ( V_131 ) ) {
F_9 ( & V_10 -> V_33 -> V_34 ,
L_12 , V_131 ) ;
return NULL ;
}
V_43 = F_19 () ;
if ( ! V_43 )
return NULL ;
V_43 -> V_102 = 1 ;
if ( V_15 -> V_135 )
V_43 -> V_60 |= V_136 ;
switch ( V_15 -> V_137 ) {
case V_138 :
V_43 -> V_60 |= V_139 ;
V_134 |= V_140 ;
break;
case V_141 :
V_43 -> V_60 |= V_125 ;
V_134 |= V_120 ;
break;
}
V_134 |= V_142 ;
V_43 -> V_60 |= V_143 ;
if ( V_131 == V_144 ) {
V_43 -> V_79 = V_120 |
V_121 ;
V_43 -> V_83 = V_134 ;
V_133 = V_8 -> V_54 . V_81 ;
V_43 -> V_47 = V_8 -> V_54 . V_53 ;
} else {
V_43 -> V_79 = V_134 ;
V_43 -> V_83 = V_122 |
V_123 ;
V_133 = V_8 -> V_54 . V_77 ;
V_43 -> V_47 = V_8 -> V_54 . V_51 ;
}
V_132 = V_128 / V_129 ;
for ( V_26 = 0 ; V_26 < V_132 ; V_26 ++ ) {
V_64 = F_20 ( sizeof( * V_64 ) , V_58 ) ;
if ( ! V_64 ) {
F_22 ( V_43 ) ;
return NULL ;
}
F_62 ( & V_64 -> V_66 , & V_43 -> V_59 ) ;
V_64 -> V_68 = V_129 ;
if ( V_26 == V_132 - 1 )
V_64 -> V_68 = V_128 - V_129 * V_26 ;
if ( V_131 == V_144 ) {
V_64 -> V_77 = V_127 + V_129 * V_26 ;
V_64 -> V_81 = V_133 ;
} else {
V_64 -> V_77 = V_133 ;
V_64 -> V_81 = V_127 + V_129 * V_26 ;
}
}
return F_63 ( & V_8 -> V_41 , & V_43 -> V_57 , V_25 ) ;
}
static struct V_55 * F_66 (
struct V_39 * V_40 , struct V_145 * V_146 ,
unsigned int V_132 , enum V_130 V_131 ,
unsigned long V_25 , void * V_147 )
{
struct V_7 * V_8 = F_14 ( V_40 ) ;
struct V_9 * V_10 = V_8 -> V_11 ;
const struct V_12 * V_13 = V_10 -> V_13 ;
struct V_14 * V_15 = & V_13 -> V_16 [ V_8 -> V_17 ] ;
struct V_42 * V_43 ;
struct V_63 * V_64 ;
struct V_145 * V_148 ;
T_5 V_133 ;
T_1 V_134 = 0 ;
int V_149 ;
F_38 ( & V_10 -> V_33 -> V_34 , L_13 ,
F_67 ( V_146 ) , V_8 -> V_91 ) ;
V_43 = F_19 () ;
if ( ! V_43 )
return NULL ;
if ( V_15 -> V_135 )
V_43 -> V_60 |= V_136 ;
switch ( V_15 -> V_137 ) {
case V_138 :
V_43 -> V_60 |= V_139 ;
V_134 |= V_140 ;
break;
case V_141 :
V_43 -> V_60 |= V_125 ;
V_134 |= V_120 ;
break;
}
V_134 |= V_142 ;
V_43 -> V_60 |= V_143 ;
if ( V_131 == V_144 ) {
V_43 -> V_79 = V_120 |
V_121 ;
V_43 -> V_83 = V_134 ;
V_133 = V_8 -> V_54 . V_81 ;
V_43 -> V_47 = V_8 -> V_54 . V_53 ;
} else if ( V_131 == V_150 ) {
V_43 -> V_79 = V_134 ;
V_43 -> V_83 = V_122 |
V_123 ;
V_133 = V_8 -> V_54 . V_77 ;
V_43 -> V_47 = V_8 -> V_54 . V_51 ;
} else {
F_22 ( V_43 ) ;
F_9 ( & V_10 -> V_33 -> V_34 ,
L_12 , V_131 ) ;
return NULL ;
}
F_68 (sgl, sg, sg_len, tmp) {
V_64 = F_20 ( sizeof( * V_64 ) , V_58 ) ;
if ( ! V_64 ) {
F_22 ( V_43 ) ;
return NULL ;
}
F_62 ( & V_64 -> V_66 , & V_43 -> V_59 ) ;
V_64 -> V_68 = F_67 ( V_148 ) ;
if ( V_131 == V_144 ) {
V_64 -> V_77 = F_69 ( V_148 ) ;
V_64 -> V_81 = V_133 ;
} else {
V_64 -> V_77 = V_133 ;
V_64 -> V_81 = F_69 ( V_148 ) ;
}
}
return F_63 ( & V_8 -> V_41 , & V_43 -> V_57 , V_25 ) ;
}
static void F_70 ( struct V_39 * V_40 )
{
struct V_7 * V_8 = F_14 ( V_40 ) ;
unsigned long V_25 ;
F_5 ( & V_8 -> V_41 . V_31 , V_25 ) ;
if ( F_71 ( & V_8 -> V_41 ) ) {
if ( ! V_8 -> V_2 && V_8 -> V_92 != V_93 )
F_37 ( V_8 ) ;
}
F_6 ( & V_8 -> V_41 . V_31 , V_25 ) ;
}
static int F_72 ( struct V_9 * V_10 ,
struct V_151 * V_152 , unsigned int V_16 , bool V_19 )
{
struct V_7 * V_40 ;
int V_26 ;
F_21 ( & V_152 -> V_16 ) ;
for ( V_26 = 0 ; V_26 < V_16 ; V_26 ++ ) {
V_40 = F_73 ( V_152 -> V_34 , sizeof( * V_40 ) , V_153 ) ;
if ( ! V_40 ) {
F_9 ( V_152 -> V_34 ,
L_14 , V_154 ) ;
return - V_155 ;
}
V_40 -> V_17 = V_26 ;
V_40 -> V_11 = V_10 ;
V_40 -> V_92 = V_98 ;
if ( V_19 ) {
V_40 -> V_19 = true ;
V_40 -> V_91 = F_74 ( V_153 , L_15 , V_26 ) ;
if ( ! V_40 -> V_91 )
return - V_155 ;
} else {
V_40 -> V_91 = F_74 ( V_153 , L_16 , V_26 ) ;
if ( ! V_40 -> V_91 )
return - V_155 ;
}
F_38 ( V_152 -> V_34 ,
L_17 ,
V_40 -> V_91 ) ;
V_40 -> V_41 . V_156 = F_44 ;
F_75 ( & V_40 -> V_41 , V_152 ) ;
}
F_76 ( V_152 -> V_34 , L_18 ,
V_26 , V_19 ? L_19 : L_20 ) ;
return V_26 ;
}
static void F_77 ( struct V_151 * V_152 )
{
struct V_7 * V_40 = NULL ;
struct V_7 * V_89 ;
F_23 (chan,
next, &dmadev->channels, vc.chan.device_node)
F_24 ( & V_40 -> V_41 . V_40 . V_157 ) ;
}
static struct V_158 * F_78 ( struct V_159 * V_33 )
{
return (struct V_158 * )
F_79 ( V_33 ) -> V_160 ;
}
static int F_80 ( struct V_159 * V_33 )
{
const struct V_12 * V_13 = F_81 ( & V_33 -> V_34 ) ;
struct V_9 * V_10 ;
struct V_158 * V_20 ;
struct V_161 * V_162 ;
int V_27 ;
int V_26 ;
if ( ! V_13 ) {
F_9 ( & V_33 -> V_34 , L_21 ) ;
return - V_163 ;
}
if ( V_13 -> V_28 > V_164 ) {
F_9 ( & V_33 -> V_34 , L_22 ,
V_13 -> V_28 , V_164 ) ;
return - V_50 ;
}
V_20 = F_78 ( V_33 ) ;
if ( ! V_20 )
return - V_50 ;
V_10 = F_73 ( & V_33 -> V_34 , sizeof( * V_10 ) , V_153 ) ;
if ( ! V_10 )
return - V_155 ;
V_10 -> V_33 = V_33 ;
V_10 -> V_13 = V_13 ;
V_10 -> V_20 = V_20 ;
V_162 = F_82 ( V_33 , V_165 , 0 ) ;
V_10 -> V_4 = F_83 ( & V_33 -> V_34 , V_162 ) ;
if ( F_84 ( V_10 -> V_4 ) )
return F_85 ( V_10 -> V_4 ) ;
V_10 -> V_29 = F_73 ( & V_33 -> V_34 ,
sizeof( struct V_1 ) *
V_13 -> V_28 ,
V_153 ) ;
if ( ! V_10 -> V_29 )
return - V_155 ;
for ( V_26 = 0 ; V_26 < V_13 -> V_28 ; V_26 ++ ) {
struct V_1 * V_2 = & V_10 -> V_29 [ V_26 ] ;
char V_166 [ 6 ] ;
V_2 -> V_17 = V_26 ;
V_2 -> V_4 = V_10 -> V_4 + ( V_26 * V_20 -> V_167 ) ;
V_2 -> V_11 = V_10 ;
V_2 -> V_99 = F_86 ( V_33 , V_26 ) ;
if ( V_2 -> V_99 < 0 ) {
F_9 ( & V_33 -> V_34 , L_23 ,
V_26 , V_2 -> V_99 ) ;
continue;
}
V_27 = F_87 ( & V_33 -> V_34 , V_2 -> V_99 , F_46 ,
0 , V_33 -> V_91 , V_2 ) ;
if ( V_27 ) {
F_9 ( & V_33 -> V_34 , L_24 ,
V_26 , V_27 ) ;
continue;
}
if ( V_20 -> V_35 ) {
sprintf ( V_166 , L_25 , V_26 ) ;
V_2 -> V_36 = F_88 ( & V_33 -> V_34 , V_166 ) ;
if ( F_84 ( V_2 -> V_36 ) && V_20 -> V_35 ) {
F_9 ( & V_33 -> V_34 , L_26 ,
V_26 , F_85 ( V_2 -> V_36 ) ) ;
continue;
}
V_27 = F_89 ( V_2 -> V_36 ) ;
if ( V_27 ) {
F_9 ( & V_33 -> V_34 , L_27 ,
V_26 , V_27 ) ;
continue;
}
}
F_90 ( & V_2 -> V_31 ) ;
V_2 -> V_30 = true ;
F_38 ( & V_33 -> V_34 , L_28 ,
V_26 , F_1 ( V_2 ) ? L_29 : L_30 ) ;
}
F_91 ( V_168 , V_10 -> memcpy . V_169 ) ;
F_91 ( V_170 , V_10 -> memcpy . V_169 ) ;
V_10 -> memcpy . V_34 = & V_33 -> V_34 ;
V_10 -> memcpy . V_171 =
F_52 ;
V_10 -> memcpy . V_172 =
F_53 ;
V_10 -> memcpy . V_173 = F_61 ;
V_10 -> memcpy . V_174 = F_56 ;
V_10 -> memcpy . V_175 = F_70 ;
V_10 -> memcpy . V_176 = F_51 ;
F_91 ( V_177 , V_10 -> V_19 . V_169 ) ;
F_91 ( V_178 , V_10 -> V_19 . V_169 ) ;
F_91 ( V_170 , V_10 -> V_19 . V_169 ) ;
V_10 -> V_19 . V_34 = & V_33 -> V_34 ;
V_10 -> V_19 . V_171 =
F_52 ;
V_10 -> V_19 . V_172 =
F_53 ;
V_10 -> V_19 . V_174 = F_56 ;
V_10 -> V_19 . V_175 = F_70 ;
V_10 -> V_19 . V_179 = F_66 ;
V_10 -> V_19 . V_180 = F_64 ;
V_10 -> V_19 . V_176 = F_51 ;
V_27 = F_72 ( V_10 , & V_10 -> memcpy ,
V_13 -> V_28 , false ) ;
if ( V_27 <= 0 ) {
F_7 ( & V_33 -> V_34 ,
L_31 ,
V_154 , V_27 ) ;
goto V_181;
}
V_27 = F_72 ( V_10 , & V_10 -> V_19 ,
V_13 -> V_182 , true ) ;
if ( V_27 <= 0 ) {
F_7 ( & V_33 -> V_34 ,
L_32 ,
V_154 , V_27 ) ;
goto V_183;
}
V_27 = F_92 ( & V_10 -> memcpy ) ;
if ( V_27 ) {
F_7 ( & V_33 -> V_34 ,
L_33 ,
V_154 , V_27 ) ;
goto V_184;
}
V_27 = F_92 ( & V_10 -> V_19 ) ;
if ( V_27 ) {
F_7 ( & V_33 -> V_34 ,
L_34 ,
V_154 , V_27 ) ;
goto V_185;
}
F_93 ( V_33 , V_10 ) ;
F_76 ( & V_33 -> V_34 , L_35 ,
V_13 -> V_28 ) ;
return 0 ;
V_185:
F_94 ( & V_10 -> memcpy ) ;
V_184:
F_77 ( & V_10 -> V_19 ) ;
V_183:
F_77 ( & V_10 -> memcpy ) ;
V_181:
if ( V_20 -> V_35 )
for ( V_26 = 0 ; V_26 < V_13 -> V_28 ; V_26 ++ ) {
struct V_1 * V_2 = & V_10 -> V_29 [ V_26 ] ;
if ( V_2 -> V_30 )
F_95 ( V_2 -> V_36 ) ;
}
return V_27 ;
}
static int F_96 ( struct V_159 * V_33 )
{
const struct V_12 * V_13 = F_81 ( & V_33 -> V_34 ) ;
struct V_9 * V_10 = F_97 ( V_33 ) ;
struct V_158 * V_20 = F_78 ( V_33 ) ;
int V_26 ;
F_94 ( & V_10 -> V_19 ) ;
F_94 ( & V_10 -> memcpy ) ;
F_77 ( & V_10 -> V_19 ) ;
F_77 ( & V_10 -> memcpy ) ;
if ( V_20 -> V_35 )
for ( V_26 = 0 ; V_26 < V_13 -> V_28 ; V_26 ++ ) {
struct V_1 * V_2 = & V_10 -> V_29 [ V_26 ] ;
if ( V_2 -> V_30 )
F_95 ( V_2 -> V_36 ) ;
}
return 0 ;
}
bool F_98 ( struct V_39 * V_40 , void * V_186 )
{
struct V_7 * V_8 ;
if ( V_40 -> V_187 -> V_34 -> V_188 != & V_189 . V_188 )
return false ;
V_8 = F_14 ( V_40 ) ;
return V_8 -> V_17 == ( int ) V_186 ;
}
