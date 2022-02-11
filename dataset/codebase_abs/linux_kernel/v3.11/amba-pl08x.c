static inline struct V_1 * F_1 ( struct V_2 * V_3 )
{
return F_2 ( V_3 , struct V_1 , V_4 . V_3 ) ;
}
static inline struct V_5 * F_3 ( struct V_6 * V_7 )
{
return F_2 ( V_7 , struct V_5 , V_8 . V_7 ) ;
}
static int F_4 ( struct V_1 * V_9 )
{
const struct V_10 * V_11 = V_9 -> V_12 -> V_11 ;
int V_13 ;
if ( V_9 -> V_14 ++ == 0 && V_11 -> V_15 ) {
V_13 = V_11 -> V_15 ( V_9 -> V_16 ) ;
if ( V_13 < 0 ) {
V_9 -> V_14 = 0 ;
return V_13 ;
}
V_9 -> signal = V_13 ;
}
return 0 ;
}
static void F_5 ( struct V_1 * V_9 )
{
const struct V_10 * V_11 = V_9 -> V_12 -> V_11 ;
if ( V_9 -> signal >= 0 ) {
F_6 ( V_9 -> V_14 == 0 ) ;
if ( -- V_9 -> V_14 == 0 && V_11 -> V_17 ) {
V_11 -> V_17 ( V_9 -> V_16 , V_9 -> signal ) ;
V_9 -> signal = - 1 ;
}
}
}
static int F_7 ( struct V_18 * V_19 )
{
unsigned int V_20 ;
V_20 = F_8 ( V_19 -> V_21 + V_22 ) ;
return V_20 & V_23 ;
}
static void F_9 ( struct V_1 * V_9 )
{
struct V_24 * V_25 = V_9 -> V_12 ;
struct V_18 * V_26 = V_9 -> V_26 ;
struct V_27 * V_8 = F_10 ( & V_9 -> V_4 ) ;
struct V_5 * V_28 = F_3 ( & V_8 -> V_7 ) ;
struct V_29 * V_30 ;
T_1 V_20 ;
F_11 ( & V_28 -> V_8 . V_31 ) ;
V_9 -> V_32 = V_28 ;
while ( F_7 ( V_26 ) )
F_12 () ;
V_30 = & V_28 -> V_33 [ 0 ] ;
F_13 ( & V_25 -> V_34 -> V_35 ,
L_1
L_2 ,
V_26 -> V_36 , V_30 -> V_37 , V_30 -> V_38 , V_30 -> V_30 , V_30 -> V_39 ,
V_28 -> V_40 ) ;
F_14 ( V_30 -> V_37 , V_26 -> V_21 + V_41 ) ;
F_14 ( V_30 -> V_38 , V_26 -> V_21 + V_42 ) ;
F_14 ( V_30 -> V_30 , V_26 -> V_21 + V_43 ) ;
F_14 ( V_30 -> V_39 , V_26 -> V_21 + V_44 ) ;
F_14 ( V_28 -> V_40 , V_26 -> V_21 + V_22 ) ;
while ( F_8 ( V_25 -> V_21 + V_45 ) & ( 1 << V_26 -> V_36 ) )
F_12 () ;
V_20 = F_8 ( V_26 -> V_21 + V_22 ) ;
while ( ( V_20 & V_23 ) || ( V_20 & V_46 ) )
V_20 = F_8 ( V_26 -> V_21 + V_22 ) ;
F_14 ( V_20 | V_46 , V_26 -> V_21 + V_22 ) ;
}
static void F_15 ( struct V_18 * V_19 )
{
T_1 V_20 ;
int V_47 ;
V_20 = F_8 ( V_19 -> V_21 + V_22 ) ;
V_20 |= V_48 ;
F_14 ( V_20 , V_19 -> V_21 + V_22 ) ;
for ( V_47 = 1000 ; V_47 ; V_47 -- ) {
if ( ! F_7 ( V_19 ) )
break;
F_16 ( 1 ) ;
}
if ( F_7 ( V_19 ) )
F_17 ( L_3 , V_19 -> V_36 ) ;
}
static void F_18 ( struct V_18 * V_19 )
{
T_1 V_20 ;
V_20 = F_8 ( V_19 -> V_21 + V_22 ) ;
V_20 &= ~ V_48 ;
F_14 ( V_20 , V_19 -> V_21 + V_22 ) ;
}
static void F_19 ( struct V_24 * V_25 ,
struct V_18 * V_19 )
{
T_1 V_20 = F_8 ( V_19 -> V_21 + V_22 ) ;
V_20 &= ~ ( V_46 | V_49 |
V_50 ) ;
F_14 ( V_20 , V_19 -> V_21 + V_22 ) ;
F_14 ( 1 << V_19 -> V_36 , V_25 -> V_21 + V_51 ) ;
F_14 ( 1 << V_19 -> V_36 , V_25 -> V_21 + V_52 ) ;
}
static inline T_1 F_20 ( T_1 V_39 )
{
T_1 V_53 = V_39 & V_54 ;
switch ( V_39 >> V_55 ) {
case V_56 :
break;
case V_57 :
V_53 *= 2 ;
break;
case V_58 :
V_53 *= 4 ;
break;
}
return V_53 ;
}
static T_1 F_21 ( struct V_1 * V_9 )
{
struct V_18 * V_19 ;
struct V_5 * V_28 ;
T_2 V_53 = 0 ;
V_19 = V_9 -> V_26 ;
V_28 = V_9 -> V_32 ;
if ( V_19 && V_28 ) {
T_1 V_59 = F_8 ( V_19 -> V_21 + V_43 ) & ~ V_60 ;
V_53 = F_20 ( F_8 ( V_19 -> V_21 + V_44 ) ) ;
if ( V_59 ) {
struct V_29 * V_33 = V_28 -> V_33 ;
T_3 V_61 = V_28 -> V_61 ;
int V_62 ;
F_22 ( V_59 < V_61 || V_59 >= V_61 +
sizeof( struct V_29 ) * V_63 ) ;
V_62 = ( V_59 - V_61 ) / sizeof( struct V_29 ) ;
for (; V_62 < V_63 ; V_62 ++ ) {
V_53 += F_20 ( V_33 [ V_62 ] . V_39 ) ;
if ( ! V_33 [ V_62 ] . V_30 )
break;
}
}
}
return V_53 ;
}
static struct V_18 *
F_23 ( struct V_24 * V_25 ,
struct V_1 * V_64 )
{
struct V_18 * V_19 = NULL ;
unsigned long V_65 ;
int V_66 ;
for ( V_66 = 0 ; V_66 < V_25 -> V_8 -> V_67 ; V_66 ++ ) {
V_19 = & V_25 -> V_68 [ V_66 ] ;
F_24 ( & V_19 -> V_69 , V_65 ) ;
if ( ! V_19 -> V_70 && ! V_19 -> V_71 ) {
V_19 -> V_71 = V_64 ;
F_25 ( & V_19 -> V_69 , V_65 ) ;
break;
}
F_25 ( & V_19 -> V_69 , V_65 ) ;
}
if ( V_66 == V_25 -> V_8 -> V_67 ) {
return NULL ;
}
return V_19 ;
}
static inline void F_26 ( struct V_24 * V_25 ,
struct V_18 * V_19 )
{
V_19 -> V_71 = NULL ;
}
static void F_27 ( struct V_1 * V_9 )
{
struct V_24 * V_25 = V_9 -> V_12 ;
struct V_18 * V_19 ;
V_19 = F_23 ( V_25 , V_9 ) ;
if ( ! V_19 ) {
F_28 ( & V_25 -> V_34 -> V_35 , L_4 , V_9 -> V_72 ) ;
V_9 -> V_73 = V_74 ;
return;
}
F_28 ( & V_25 -> V_34 -> V_35 , L_5 ,
V_19 -> V_36 , V_9 -> V_72 ) ;
V_9 -> V_26 = V_19 ;
V_9 -> V_73 = V_75 ;
F_9 ( V_9 ) ;
}
static void F_29 ( struct V_18 * V_19 ,
struct V_1 * V_9 )
{
struct V_24 * V_25 = V_9 -> V_12 ;
F_28 ( & V_25 -> V_34 -> V_35 , L_6 ,
V_19 -> V_36 , V_9 -> V_72 ) ;
V_19 -> V_71 = V_9 ;
V_9 -> V_26 = V_19 ;
V_9 -> V_73 = V_75 ;
F_9 ( V_9 ) ;
}
static void F_30 ( struct V_1 * V_9 )
{
struct V_24 * V_25 = V_9 -> V_12 ;
struct V_1 * V_76 , * V_77 ;
V_78:
V_77 = NULL ;
F_31 (p, &pl08x->memcpy.channels, vc.chan.device_node)
if ( V_76 -> V_73 == V_74 ) {
V_77 = V_76 ;
break;
}
if ( ! V_77 ) {
F_31 (p, &pl08x->slave.channels, vc.chan.device_node)
if ( V_76 -> V_73 == V_74 ) {
V_77 = V_76 ;
break;
}
}
F_19 ( V_25 , V_9 -> V_26 ) ;
if ( V_77 ) {
bool V_79 ;
F_32 ( & V_77 -> V_4 . V_69 ) ;
V_79 = V_77 -> V_73 == V_74 ;
if ( V_79 )
F_29 ( V_9 -> V_26 , V_77 ) ;
F_33 ( & V_77 -> V_4 . V_69 ) ;
if ( ! V_79 )
goto V_78;
} else {
F_26 ( V_25 , V_9 -> V_26 ) ;
}
V_9 -> V_26 = NULL ;
V_9 -> V_73 = V_80 ;
}
static inline unsigned int F_34 ( unsigned int V_81 )
{
switch ( V_81 ) {
case V_56 :
return 1 ;
case V_57 :
return 2 ;
case V_58 :
return 4 ;
default:
break;
}
F_35 () ;
return 0 ;
}
static inline T_1 F_36 ( T_1 V_39 , T_4 V_82 , T_4 V_83 ,
T_2 V_84 )
{
T_1 V_85 = V_39 ;
V_85 &= ~ V_86 ;
V_85 &= ~ V_87 ;
V_85 &= ~ V_54 ;
switch ( V_82 ) {
case 1 :
V_85 |= V_56 << V_55 ;
break;
case 2 :
V_85 |= V_57 << V_55 ;
break;
case 4 :
V_85 |= V_58 << V_55 ;
break;
default:
F_35 () ;
break;
}
switch ( V_83 ) {
case 1 :
V_85 |= V_56 << V_88 ;
break;
case 2 :
V_85 |= V_57 << V_88 ;
break;
case 4 :
V_85 |= V_58 << V_88 ;
break;
default:
F_35 () ;
break;
}
V_85 |= V_84 << V_89 ;
return V_85 ;
}
static void F_37 ( struct V_90 * V_91 ,
struct V_92 * * V_93 , struct V_92 * * V_94 , T_1 V_39 )
{
if ( ! ( V_39 & V_95 ) ) {
* V_93 = & V_91 -> V_96 ;
* V_94 = & V_91 -> V_97 ;
} else if ( ! ( V_39 & V_98 ) ) {
* V_93 = & V_91 -> V_97 ;
* V_94 = & V_91 -> V_96 ;
} else {
if ( V_91 -> V_96 . V_99 >= V_91 -> V_97 . V_99 ) {
* V_93 = & V_91 -> V_96 ;
* V_94 = & V_91 -> V_97 ;
} else {
* V_93 = & V_91 -> V_97 ;
* V_94 = & V_91 -> V_96 ;
}
}
}
static void F_38 ( struct V_90 * V_91 ,
int V_100 , int V_101 , T_1 V_39 )
{
struct V_29 * V_33 = V_91 -> V_28 -> V_33 ;
T_3 V_61 = V_91 -> V_28 -> V_61 ;
F_22 ( V_100 >= V_63 ) ;
V_33 [ V_100 ] . V_39 = V_39 ;
V_33 [ V_100 ] . V_37 = V_91 -> V_97 . V_102 ;
V_33 [ V_100 ] . V_38 = V_91 -> V_96 . V_102 ;
V_33 [ V_100 ] . V_30 = V_61 + ( V_100 + 1 ) *
sizeof( struct V_29 ) ;
V_33 [ V_100 ] . V_30 |= V_91 -> V_103 ;
if ( V_39 & V_98 )
V_91 -> V_97 . V_102 += V_101 ;
if ( V_39 & V_95 )
V_91 -> V_96 . V_102 += V_101 ;
F_22 ( V_91 -> V_104 < V_101 ) ;
V_91 -> V_104 -= V_101 ;
}
static inline void F_39 ( struct V_90 * V_91 ,
T_1 * V_39 , T_1 V_101 , int V_100 , T_2 * V_105 )
{
* V_39 = F_36 ( * V_39 , 1 , 1 , V_101 ) ;
F_38 ( V_91 , V_100 , V_101 , * V_39 ) ;
( * V_105 ) += V_101 ;
}
static int F_40 ( struct V_24 * V_25 ,
struct V_5 * V_28 )
{
struct V_92 * V_93 , * V_94 ;
struct V_90 V_91 ;
int V_100 = 0 ;
T_1 V_39 , V_106 = 0 ;
T_2 V_107 , V_105 ;
struct V_29 * V_33 ;
struct V_108 * V_109 ;
V_28 -> V_33 = F_41 ( V_25 -> V_110 , V_111 , & V_28 -> V_61 ) ;
if ( ! V_28 -> V_33 ) {
F_42 ( & V_25 -> V_34 -> V_35 , L_7 , V_112 ) ;
return 0 ;
}
V_91 . V_28 = V_28 ;
V_91 . V_103 = ( V_25 -> V_113 & V_114 ) ? V_60 : 0 ;
V_39 = V_28 -> V_39 ;
V_91 . V_97 . V_115 =
F_34 ( ( V_39 & V_87 ) >>
V_55 ) ;
V_91 . V_96 . V_115 =
F_34 ( ( V_39 & V_86 ) >>
V_88 ) ;
F_31 (dsg, &txd->dsg_list, node) {
V_105 = 0 ;
V_39 = V_28 -> V_39 ;
V_91 . V_97 . V_102 = V_109 -> V_116 ;
V_91 . V_96 . V_102 = V_109 -> V_117 ;
V_91 . V_104 = V_109 -> V_101 ;
V_91 . V_97 . V_99 = V_91 . V_97 . V_115 ;
V_91 . V_96 . V_99 = V_91 . V_96 . V_115 ;
F_37 ( & V_91 , & V_93 , & V_94 , V_39 ) ;
F_13 ( & V_25 -> V_34 -> V_35 , L_8 ,
V_91 . V_97 . V_102 , V_39 & V_98 ? L_9 : L_10 ,
V_91 . V_97 . V_99 ,
V_91 . V_96 . V_102 , V_39 & V_95 ? L_9 : L_10 ,
V_91 . V_96 . V_99 ,
V_91 . V_104 ) ;
F_13 ( & V_25 -> V_34 -> V_35 , L_11 ,
V_93 == & V_91 . V_97 ? L_12 : L_13 ,
V_94 == & V_91 . V_97 ? L_12 : L_13 ) ;
if ( ! V_91 . V_104 ) {
T_1 V_118 = ( V_28 -> V_40 & V_119 ) >>
V_120 ;
if ( ! ( ( V_118 >= V_121 ) &&
( V_118 <= V_122 ) ) ) {
F_42 ( & V_25 -> V_34 -> V_35 , L_14 ,
V_112 ) ;
return 0 ;
}
if ( ( V_91 . V_97 . V_102 % V_91 . V_97 . V_99 ) ||
( V_91 . V_96 . V_102 % V_91 . V_96 . V_99 ) ) {
F_42 ( & V_25 -> V_34 -> V_35 ,
L_15
L_16 ,
V_112 ) ;
return 0 ;
}
V_39 = F_36 ( V_39 , V_91 . V_97 . V_99 ,
V_91 . V_96 . V_99 , 0 ) ;
F_38 ( & V_91 , V_100 ++ , 0 , V_39 ) ;
break;
}
if ( V_91 . V_104 < V_93 -> V_99 )
V_106 = V_91 . V_104 ;
else if ( ( V_93 -> V_102 ) % ( V_93 -> V_99 ) ) {
V_106 = V_93 -> V_99 - ( V_93 -> V_102 ) %
( V_93 -> V_99 ) ;
if ( ( V_91 . V_104 - V_106 ) < V_93 -> V_99 )
V_106 = V_91 . V_104 ;
}
if ( V_106 ) {
F_13 ( & V_25 -> V_34 -> V_35 ,
L_17 ,
V_112 , V_91 . V_104 ) ;
F_39 ( & V_91 , & V_39 , V_106 , V_100 ++ ,
& V_105 ) ;
}
if ( V_91 . V_104 ) {
if ( V_94 -> V_102 % V_94 -> V_99 ) {
F_28 ( & V_25 -> V_34 -> V_35 ,
L_18 ,
V_112 ) ;
V_94 -> V_99 = 1 ;
}
V_107 = V_91 . V_97 . V_99 *
V_54 ;
F_13 ( & V_25 -> V_34 -> V_35 ,
L_19 ,
V_112 , V_107 ) ;
while ( V_91 . V_104 > ( V_93 -> V_99 - 1 ) ) {
T_2 V_123 , V_84 , V_124 ;
V_123 = F_43 ( V_91 . V_104 , V_107 ) ;
V_124 = F_44 ( V_93 -> V_99 , V_94 -> V_99 ) ;
V_123 = ( V_123 / V_124 ) * V_124 ;
V_84 = V_123 / V_91 . V_97 . V_99 ;
F_13 ( & V_25 -> V_34 -> V_35 ,
L_20
L_21 ,
V_112 , V_123 , V_91 . V_104 ) ;
V_39 = F_36 ( V_39 , V_91 . V_97 . V_99 ,
V_91 . V_96 . V_99 , V_84 ) ;
F_38 ( & V_91 , V_100 ++ ,
V_123 , V_39 ) ;
V_105 += V_123 ;
}
if ( V_91 . V_104 ) {
F_13 ( & V_25 -> V_34 -> V_35 ,
L_22 ,
V_112 , V_91 . V_104 ) ;
F_39 ( & V_91 , & V_39 , V_91 . V_104 ,
V_100 ++ , & V_105 ) ;
}
}
if ( V_105 != V_109 -> V_101 ) {
F_42 ( & V_25 -> V_34 -> V_35 ,
L_23 ,
V_112 , V_105 , V_109 -> V_101 ) ;
return 0 ;
}
if ( V_100 >= V_63 ) {
F_42 ( & V_25 -> V_34 -> V_35 ,
L_24 ,
V_112 , ( T_1 ) V_63 ) ;
return 0 ;
}
}
V_33 = V_28 -> V_33 ;
V_33 [ V_100 - 1 ] . V_30 = 0 ;
V_33 [ V_100 - 1 ] . V_39 |= V_125 ;
#ifdef F_45
{
int V_66 ;
F_13 ( & V_25 -> V_34 -> V_35 ,
L_25 ,
L_26 , L_10 , L_27 , L_28 , L_29 , L_30 ) ;
for ( V_66 = 0 ; V_66 < V_100 ; V_66 ++ ) {
F_13 ( & V_25 -> V_34 -> V_35 ,
L_31 ,
V_66 , & V_33 [ V_66 ] , V_33 [ V_66 ] . V_37 ,
V_33 [ V_66 ] . V_38 , V_33 [ V_66 ] . V_30 , V_33 [ V_66 ] . V_39
) ;
}
}
#endif
return V_100 ;
}
static void F_46 ( struct V_24 * V_25 ,
struct V_5 * V_28 )
{
struct V_108 * V_109 , * V_126 ;
if ( V_28 -> V_33 )
F_47 ( V_25 -> V_110 , V_28 -> V_33 , V_28 -> V_61 ) ;
F_48 (dsg, _dsg, &txd->dsg_list, node) {
F_11 ( & V_109 -> V_31 ) ;
F_49 ( V_109 ) ;
}
F_49 ( V_28 ) ;
}
static void F_50 ( struct V_5 * V_28 )
{
struct V_127 * V_35 = V_28 -> V_8 . V_7 . V_3 -> V_127 -> V_35 ;
struct V_108 * V_109 ;
if ( ! ( V_28 -> V_8 . V_7 . V_65 & V_128 ) ) {
if ( V_28 -> V_8 . V_7 . V_65 & V_129 )
F_31 (dsg, &txd->dsg_list, node)
F_51 ( V_35 , V_109 -> V_116 , V_109 -> V_101 ,
V_130 ) ;
else {
F_31 (dsg, &txd->dsg_list, node)
F_52 ( V_35 , V_109 -> V_116 , V_109 -> V_101 ,
V_130 ) ;
}
}
if ( ! ( V_28 -> V_8 . V_7 . V_65 & V_131 ) ) {
if ( V_28 -> V_8 . V_7 . V_65 & V_132 )
F_31 (dsg, &txd->dsg_list, node)
F_51 ( V_35 , V_109 -> V_117 , V_109 -> V_101 ,
V_133 ) ;
else
F_31 (dsg, &txd->dsg_list, node)
F_52 ( V_35 , V_109 -> V_117 , V_109 -> V_101 ,
V_133 ) ;
}
}
static void F_53 ( struct V_27 * V_8 )
{
struct V_5 * V_28 = F_3 ( & V_8 -> V_7 ) ;
struct V_1 * V_9 = F_1 ( V_8 -> V_7 . V_3 ) ;
if ( ! V_9 -> V_134 )
F_50 ( V_28 ) ;
if ( ! V_28 -> V_135 )
F_5 ( V_9 ) ;
F_46 ( V_9 -> V_12 , V_28 ) ;
}
static void F_54 ( struct V_24 * V_25 ,
struct V_1 * V_9 )
{
F_55 ( V_136 ) ;
F_56 ( & V_9 -> V_4 , & V_136 ) ;
F_57 ( & V_9 -> V_4 , & V_136 ) ;
}
static int F_58 ( struct V_2 * V_3 )
{
return 0 ;
}
static void F_59 ( struct V_2 * V_3 )
{
F_60 ( F_61 ( V_3 ) ) ;
}
static struct V_6 * F_62 (
struct V_2 * V_3 , unsigned long V_65 )
{
struct V_6 * V_137 = NULL ;
return V_137 ;
}
static enum V_138 F_63 ( struct V_2 * V_3 ,
T_5 V_139 , struct V_140 * V_141 )
{
struct V_1 * V_9 = F_1 ( V_3 ) ;
struct V_27 * V_8 ;
unsigned long V_65 ;
enum V_138 V_13 ;
T_2 V_53 = 0 ;
V_13 = F_64 ( V_3 , V_139 , V_141 ) ;
if ( V_13 == V_142 )
return V_13 ;
if ( ! V_141 ) {
if ( V_9 -> V_73 == V_143 )
V_13 = V_144 ;
return V_13 ;
}
F_24 ( & V_9 -> V_4 . V_69 , V_65 ) ;
V_13 = F_64 ( V_3 , V_139 , V_141 ) ;
if ( V_13 != V_142 ) {
V_8 = F_65 ( & V_9 -> V_4 , V_139 ) ;
if ( V_8 ) {
struct V_5 * V_28 = F_3 ( & V_8 -> V_7 ) ;
struct V_108 * V_109 ;
F_31 (dsg, &txd->dsg_list, node)
V_53 += V_109 -> V_101 ;
} else {
V_53 = F_21 ( V_9 ) ;
}
}
F_25 ( & V_9 -> V_4 . V_69 , V_65 ) ;
F_66 ( V_141 , V_53 ) ;
if ( V_9 -> V_73 == V_143 && V_13 == V_145 )
V_13 = V_144 ;
return V_13 ;
}
static T_1 F_67 ( T_4 V_37 , T_4 V_38 )
{
T_1 V_39 = 0 ;
if ( ! ( V_38 & V_146 ) || ( ( V_38 & V_114 ) && ( V_37 & V_146 ) ) )
V_39 |= V_147 ;
if ( ! ( V_37 & V_146 ) || ( ( V_37 & V_114 ) && ! ( V_38 & V_114 ) ) )
V_39 |= V_148 ;
return V_39 ;
}
static T_1 F_68 ( T_1 V_39 )
{
V_39 &= ~ ( V_148 | V_147 |
V_98 | V_95 |
V_149 ) ;
return V_39 | V_150 ;
}
static T_1 F_69 ( enum V_151 V_124 )
{
switch ( V_124 ) {
case V_152 :
return V_56 ;
case V_153 :
return V_57 ;
case V_154 :
return V_58 ;
default:
return ~ 0 ;
}
}
static T_1 F_70 ( T_1 V_155 )
{
int V_66 ;
for ( V_66 = 0 ; V_66 < F_71 ( V_156 ) ; V_66 ++ )
if ( V_156 [ V_66 ] . V_157 <= V_155 )
break;
return V_156 [ V_66 ] . V_158 ;
}
static T_1 F_72 ( struct V_1 * V_9 ,
enum V_151 V_159 , T_1 V_155 )
{
T_1 V_124 , V_160 , V_39 = 0 ;
V_124 = F_69 ( V_159 ) ;
if ( V_124 == ~ 0 )
return ~ 0 ;
V_39 |= V_124 << V_55 ;
V_39 |= V_124 << V_88 ;
if ( V_9 -> V_16 -> V_161 )
V_155 = 1 ;
V_160 = F_70 ( V_155 ) ;
V_39 |= V_160 << V_162 ;
V_39 |= V_160 << V_163 ;
return F_68 ( V_39 ) ;
}
static int F_73 ( struct V_2 * V_3 ,
struct V_164 * V_165 )
{
struct V_1 * V_9 = F_1 ( V_3 ) ;
if ( ! V_9 -> V_134 )
return - V_166 ;
if ( V_165 -> V_167 == V_168 ||
V_165 -> V_169 == V_168 )
return - V_166 ;
V_9 -> V_170 = * V_165 ;
return 0 ;
}
static void F_74 ( struct V_2 * V_3 )
{
struct V_1 * V_9 = F_1 ( V_3 ) ;
unsigned long V_65 ;
F_24 ( & V_9 -> V_4 . V_69 , V_65 ) ;
if ( F_75 ( & V_9 -> V_4 ) ) {
if ( ! V_9 -> V_26 && V_9 -> V_73 != V_74 )
F_27 ( V_9 ) ;
}
F_25 ( & V_9 -> V_4 . V_69 , V_65 ) ;
}
static struct V_5 * F_76 ( struct V_1 * V_9 )
{
struct V_5 * V_28 = F_77 ( sizeof( * V_28 ) , V_111 ) ;
if ( V_28 ) {
F_78 ( & V_28 -> V_171 ) ;
V_28 -> V_40 = V_49 |
V_50 ;
}
return V_28 ;
}
static struct V_6 * F_79 (
struct V_2 * V_3 , T_3 V_172 , T_3 V_37 ,
T_2 V_101 , unsigned long V_65 )
{
struct V_1 * V_9 = F_1 ( V_3 ) ;
struct V_24 * V_25 = V_9 -> V_12 ;
struct V_5 * V_28 ;
struct V_108 * V_109 ;
int V_13 ;
V_28 = F_76 ( V_9 ) ;
if ( ! V_28 ) {
F_42 ( & V_25 -> V_34 -> V_35 ,
L_32 , V_112 ) ;
return NULL ;
}
V_109 = F_77 ( sizeof( struct V_108 ) , V_111 ) ;
if ( ! V_109 ) {
F_46 ( V_25 , V_28 ) ;
F_42 ( & V_25 -> V_34 -> V_35 , L_33 ,
V_112 ) ;
return NULL ;
}
F_80 ( & V_109 -> V_31 , & V_28 -> V_171 ) ;
V_109 -> V_116 = V_37 ;
V_109 -> V_117 = V_172 ;
V_109 -> V_101 = V_101 ;
V_28 -> V_40 |= V_173 << V_120 ;
V_28 -> V_39 = V_25 -> V_11 -> V_174 . V_175 &
~ ( V_147 | V_148 ) ;
V_28 -> V_39 |= V_98 | V_95 ;
if ( V_25 -> V_8 -> V_176 )
V_28 -> V_39 |= F_67 ( V_25 -> V_177 ,
V_25 -> V_177 ) ;
V_13 = F_40 ( V_9 -> V_12 , V_28 ) ;
if ( ! V_13 ) {
F_46 ( V_25 , V_28 ) ;
return NULL ;
}
return F_81 ( & V_9 -> V_4 , & V_28 -> V_8 , V_65 ) ;
}
static struct V_6 * F_82 (
struct V_2 * V_3 , struct V_178 * V_179 ,
unsigned int V_180 , enum V_181 V_182 ,
unsigned long V_65 , void * V_183 )
{
struct V_1 * V_9 = F_1 ( V_3 ) ;
struct V_24 * V_25 = V_9 -> V_12 ;
struct V_5 * V_28 ;
struct V_108 * V_109 ;
struct V_178 * V_184 ;
enum V_151 V_159 ;
T_3 V_185 ;
int V_13 , V_186 ;
T_4 V_187 , V_188 ;
T_1 V_155 , V_39 ;
F_28 ( & V_25 -> V_34 -> V_35 , L_34 ,
V_112 , F_83 ( V_179 ) , V_9 -> V_72 ) ;
V_28 = F_76 ( V_9 ) ;
if ( ! V_28 ) {
F_42 ( & V_25 -> V_34 -> V_35 , L_35 , V_112 ) ;
return NULL ;
}
if ( V_182 == V_189 ) {
V_39 = V_98 ;
V_185 = V_9 -> V_170 . V_117 ;
V_159 = V_9 -> V_170 . V_169 ;
V_155 = V_9 -> V_170 . V_190 ;
V_187 = V_25 -> V_177 ;
V_188 = V_9 -> V_16 -> V_191 ;
} else if ( V_182 == V_192 ) {
V_39 = V_95 ;
V_185 = V_9 -> V_170 . V_116 ;
V_159 = V_9 -> V_170 . V_167 ;
V_155 = V_9 -> V_170 . V_193 ;
V_187 = V_9 -> V_16 -> V_191 ;
V_188 = V_25 -> V_177 ;
} else {
F_46 ( V_25 , V_28 ) ;
F_42 ( & V_25 -> V_34 -> V_35 ,
L_36 , V_112 ) ;
return NULL ;
}
V_39 |= F_72 ( V_9 , V_159 , V_155 ) ;
if ( V_39 == ~ 0 ) {
F_46 ( V_25 , V_28 ) ;
F_42 ( & V_25 -> V_34 -> V_35 ,
L_37 ) ;
return NULL ;
}
V_28 -> V_39 = V_39 | F_67 ( V_187 , V_188 ) ;
if ( V_9 -> V_170 . V_194 )
V_186 = ( V_182 == V_189 ) ? V_195 :
V_196 ;
else
V_186 = ( V_182 == V_189 ) ? V_197 :
V_198 ;
V_28 -> V_40 |= V_186 << V_120 ;
V_13 = F_4 ( V_9 ) ;
if ( V_13 < 0 ) {
F_46 ( V_25 , V_28 ) ;
F_28 ( & V_25 -> V_34 -> V_35 ,
L_38 ,
V_9 -> V_72 ) ;
return NULL ;
}
F_28 ( & V_25 -> V_34 -> V_35 , L_39 ,
V_9 -> signal , V_9 -> V_72 ) ;
if ( V_182 == V_189 )
V_28 -> V_40 |= V_9 -> signal << V_199 ;
else
V_28 -> V_40 |= V_9 -> signal << V_200 ;
F_84 (sgl, sg, sg_len, tmp) {
V_109 = F_77 ( sizeof( struct V_108 ) , V_111 ) ;
if ( ! V_109 ) {
F_5 ( V_9 ) ;
F_46 ( V_25 , V_28 ) ;
F_42 ( & V_25 -> V_34 -> V_35 , L_40 ,
V_112 ) ;
return NULL ;
}
F_80 ( & V_109 -> V_31 , & V_28 -> V_171 ) ;
V_109 -> V_101 = F_83 ( V_184 ) ;
if ( V_182 == V_189 ) {
V_109 -> V_116 = F_85 ( V_184 ) ;
V_109 -> V_117 = V_185 ;
} else {
V_109 -> V_116 = V_185 ;
V_109 -> V_117 = F_85 ( V_184 ) ;
}
}
V_13 = F_40 ( V_9 -> V_12 , V_28 ) ;
if ( ! V_13 ) {
F_5 ( V_9 ) ;
F_46 ( V_25 , V_28 ) ;
return NULL ;
}
return F_81 ( & V_9 -> V_4 , & V_28 -> V_8 , V_65 ) ;
}
static int F_86 ( struct V_2 * V_3 , enum V_201 V_202 ,
unsigned long V_203 )
{
struct V_1 * V_9 = F_1 ( V_3 ) ;
struct V_24 * V_25 = V_9 -> V_12 ;
unsigned long V_65 ;
int V_13 = 0 ;
if ( V_202 == V_204 ) {
return F_73 ( V_3 ,
(struct V_164 * ) V_203 ) ;
}
F_24 ( & V_9 -> V_4 . V_69 , V_65 ) ;
if ( ! V_9 -> V_26 && ! V_9 -> V_32 ) {
F_25 ( & V_9 -> V_4 . V_69 , V_65 ) ;
return 0 ;
}
switch ( V_202 ) {
case V_205 :
V_9 -> V_73 = V_80 ;
if ( V_9 -> V_26 ) {
F_30 ( V_9 ) ;
}
if ( V_9 -> V_32 ) {
F_53 ( & V_9 -> V_32 -> V_8 ) ;
V_9 -> V_32 = NULL ;
}
F_54 ( V_25 , V_9 ) ;
break;
case V_206 :
F_15 ( V_9 -> V_26 ) ;
V_9 -> V_73 = V_143 ;
break;
case V_207 :
F_18 ( V_9 -> V_26 ) ;
V_9 -> V_73 = V_75 ;
break;
default:
V_13 = - V_208 ;
break;
}
F_25 ( & V_9 -> V_4 . V_69 , V_65 ) ;
return V_13 ;
}
bool F_87 ( struct V_2 * V_3 , void * V_209 )
{
struct V_1 * V_9 ;
char * V_72 = V_209 ;
if ( V_3 -> V_127 -> V_35 -> V_210 != & V_211 . V_212 )
return false ;
V_9 = F_1 ( V_3 ) ;
if ( ! strcmp ( V_9 -> V_72 , V_72 ) )
return true ;
return false ;
}
static void F_88 ( struct V_24 * V_25 )
{
if ( V_25 -> V_8 -> V_213 )
return;
F_14 ( V_46 , V_25 -> V_21 + V_214 ) ;
}
static T_6 F_89 ( int V_215 , void * V_35 )
{
struct V_24 * V_25 = V_35 ;
T_1 V_216 = 0 , V_217 , V_218 , V_66 ;
V_217 = F_8 ( V_25 -> V_21 + V_219 ) ;
if ( V_217 ) {
F_42 ( & V_25 -> V_34 -> V_35 , L_41 ,
V_112 , V_217 ) ;
F_14 ( V_217 , V_25 -> V_21 + V_51 ) ;
}
V_218 = F_8 ( V_25 -> V_21 + V_220 ) ;
if ( V_218 )
F_14 ( V_218 , V_25 -> V_21 + V_52 ) ;
if ( ! V_217 && ! V_218 )
return V_221 ;
for ( V_66 = 0 ; V_66 < V_25 -> V_8 -> V_67 ; V_66 ++ ) {
if ( ( ( 1 << V_66 ) & V_217 ) || ( ( 1 << V_66 ) & V_218 ) ) {
struct V_18 * V_26 = & V_25 -> V_68 [ V_66 ] ;
struct V_1 * V_9 = V_26 -> V_71 ;
struct V_5 * V_7 ;
if ( ! V_9 ) {
F_42 ( & V_25 -> V_34 -> V_35 ,
L_42 ,
V_112 , V_66 ) ;
continue;
}
F_32 ( & V_9 -> V_4 . V_69 ) ;
V_7 = V_9 -> V_32 ;
if ( V_7 ) {
V_9 -> V_32 = NULL ;
F_5 ( V_9 ) ;
V_7 -> V_135 = true ;
F_90 ( & V_7 -> V_8 ) ;
if ( F_10 ( & V_9 -> V_4 ) )
F_9 ( V_9 ) ;
else
F_30 ( V_9 ) ;
}
F_33 ( & V_9 -> V_4 . V_69 ) ;
V_216 |= ( 1 << V_66 ) ;
}
}
return V_216 ? V_222 : V_221 ;
}
static void F_91 ( struct V_1 * V_3 )
{
V_3 -> V_134 = true ;
V_3 -> V_72 = V_3 -> V_16 -> V_223 ;
V_3 -> V_170 . V_116 = V_3 -> V_16 -> V_102 ;
V_3 -> V_170 . V_117 = V_3 -> V_16 -> V_102 ;
}
static int F_92 ( struct V_24 * V_25 ,
struct V_224 * V_225 , unsigned int V_67 , bool V_134 )
{
struct V_1 * V_3 ;
int V_66 ;
F_78 ( & V_225 -> V_67 ) ;
for ( V_66 = 0 ; V_66 < V_67 ; V_66 ++ ) {
V_3 = F_77 ( sizeof( * V_3 ) , V_226 ) ;
if ( ! V_3 ) {
F_42 ( & V_25 -> V_34 -> V_35 ,
L_43 , V_112 ) ;
return - V_227 ;
}
V_3 -> V_12 = V_25 ;
V_3 -> V_73 = V_80 ;
V_3 -> signal = - 1 ;
if ( V_134 ) {
V_3 -> V_16 = & V_25 -> V_11 -> V_228 [ V_66 ] ;
F_91 ( V_3 ) ;
} else {
V_3 -> V_16 = & V_25 -> V_11 -> V_174 ;
V_3 -> V_72 = F_93 ( V_226 , L_44 , V_66 ) ;
if ( ! V_3 -> V_72 ) {
F_49 ( V_3 ) ;
return - V_227 ;
}
}
F_28 ( & V_25 -> V_34 -> V_35 ,
L_45 ,
V_3 -> V_72 ) ;
V_3 -> V_4 . V_229 = F_53 ;
F_94 ( & V_3 -> V_4 , V_225 ) ;
}
F_95 ( & V_25 -> V_34 -> V_35 , L_46 ,
V_66 , V_134 ? L_47 : L_48 ) ;
return V_66 ;
}
static void F_96 ( struct V_224 * V_225 )
{
struct V_1 * V_3 = NULL ;
struct V_1 * V_77 ;
F_48 (chan,
next, &dmadev->channels, vc.chan.device_node) {
F_11 ( & V_3 -> V_4 . V_3 . V_230 ) ;
F_49 ( V_3 ) ;
}
}
static const char * F_97 ( enum V_231 V_73 )
{
switch ( V_73 ) {
case V_80 :
return L_49 ;
case V_75 :
return L_50 ;
case V_143 :
return L_51 ;
case V_74 :
return L_52 ;
default:
break;
}
return L_53 ;
}
static int F_98 ( struct V_232 * V_233 , void * V_234 )
{
struct V_24 * V_25 = V_233 -> V_235 ;
struct V_1 * V_3 ;
struct V_18 * V_19 ;
unsigned long V_65 ;
int V_66 ;
F_99 ( V_233 , L_54 ) ;
F_99 ( V_233 , L_55 ) ;
F_99 ( V_233 , L_56 ) ;
for ( V_66 = 0 ; V_66 < V_25 -> V_8 -> V_67 ; V_66 ++ ) {
struct V_1 * V_64 ;
V_19 = & V_25 -> V_68 [ V_66 ] ;
F_24 ( & V_19 -> V_69 , V_65 ) ;
V_64 = V_19 -> V_71 ;
F_99 ( V_233 , L_57 ,
V_19 -> V_36 ,
V_64 ? V_64 -> V_72 : L_58 ,
V_19 -> V_70 ? L_59 : L_10 ) ;
F_25 ( & V_19 -> V_69 , V_65 ) ;
}
F_99 ( V_233 , L_60 ) ;
F_99 ( V_233 , L_61 ) ;
F_99 ( V_233 , L_62 ) ;
F_31 (chan, &pl08x->memcpy.channels, vc.chan.device_node) {
F_99 ( V_233 , L_63 , V_3 -> V_72 ,
F_97 ( V_3 -> V_73 ) ) ;
}
F_99 ( V_233 , L_64 ) ;
F_99 ( V_233 , L_61 ) ;
F_99 ( V_233 , L_62 ) ;
F_31 (chan, &pl08x->slave.channels, vc.chan.device_node) {
F_99 ( V_233 , L_63 , V_3 -> V_72 ,
F_97 ( V_3 -> V_73 ) ) ;
}
return 0 ;
}
static int F_100 ( struct V_236 * V_236 , struct V_237 * V_237 )
{
return F_101 ( V_237 , F_98 , V_236 -> V_238 ) ;
}
static void F_102 ( struct V_24 * V_25 )
{
( void ) F_103 ( F_104 ( & V_25 -> V_34 -> V_35 ) ,
V_239 | V_240 , NULL , V_25 ,
& V_241 ) ;
}
static inline void F_102 ( struct V_24 * V_25 )
{
}
static int F_105 ( struct V_242 * V_34 , const struct V_243 * V_36 )
{
struct V_24 * V_25 ;
const struct V_244 * V_8 = V_36 -> V_234 ;
int V_13 = 0 ;
int V_66 ;
V_13 = F_106 ( V_34 , NULL ) ;
if ( V_13 )
return V_13 ;
V_25 = F_77 ( sizeof( * V_25 ) , V_226 ) ;
if ( ! V_25 ) {
V_13 = - V_227 ;
goto V_245;
}
F_107 ( V_246 , V_25 -> memcpy . V_247 ) ;
V_25 -> memcpy . V_35 = & V_34 -> V_35 ;
V_25 -> memcpy . V_248 = F_58 ;
V_25 -> memcpy . V_249 = F_59 ;
V_25 -> memcpy . V_250 = F_79 ;
V_25 -> memcpy . V_251 = F_62 ;
V_25 -> memcpy . V_252 = F_63 ;
V_25 -> memcpy . V_253 = F_74 ;
V_25 -> memcpy . V_254 = F_86 ;
F_107 ( V_255 , V_25 -> V_134 . V_247 ) ;
V_25 -> V_134 . V_35 = & V_34 -> V_35 ;
V_25 -> V_134 . V_248 = F_58 ;
V_25 -> V_134 . V_249 = F_59 ;
V_25 -> V_134 . V_251 = F_62 ;
V_25 -> V_134 . V_252 = F_63 ;
V_25 -> V_134 . V_253 = F_74 ;
V_25 -> V_134 . V_256 = F_82 ;
V_25 -> V_134 . V_254 = F_86 ;
V_25 -> V_11 = F_108 ( & V_34 -> V_35 ) ;
if ( ! V_25 -> V_11 ) {
F_42 ( & V_34 -> V_35 , L_65 ) ;
V_13 = - V_166 ;
goto V_257;
}
V_25 -> V_34 = V_34 ;
V_25 -> V_8 = V_8 ;
V_25 -> V_113 = V_146 ;
V_25 -> V_177 = V_146 ;
if ( V_25 -> V_8 -> V_176 ) {
V_25 -> V_113 = V_25 -> V_11 -> V_113 ;
V_25 -> V_177 = V_25 -> V_11 -> V_177 ;
}
V_25 -> V_110 = F_109 ( V_258 , & V_25 -> V_34 -> V_35 ,
V_259 , V_260 , 0 ) ;
if ( ! V_25 -> V_110 ) {
V_13 = - V_227 ;
goto V_261;
}
V_25 -> V_21 = F_110 ( V_34 -> V_262 . V_263 , F_111 ( & V_34 -> V_262 ) ) ;
if ( ! V_25 -> V_21 ) {
V_13 = - V_227 ;
goto V_264;
}
F_88 ( V_25 ) ;
F_14 ( 0x000000FF , V_25 -> V_21 + V_51 ) ;
F_14 ( 0x000000FF , V_25 -> V_21 + V_52 ) ;
V_13 = F_112 ( V_34 -> V_215 [ 0 ] , F_89 , V_265 ,
V_258 , V_25 ) ;
if ( V_13 ) {
F_42 ( & V_34 -> V_35 , L_66 ,
V_112 , V_34 -> V_215 [ 0 ] ) ;
goto V_266;
}
V_25 -> V_68 = F_77 ( ( V_8 -> V_67 * sizeof( * V_25 -> V_68 ) ) ,
V_226 ) ;
if ( ! V_25 -> V_68 ) {
F_42 ( & V_34 -> V_35 , L_67
L_68 ,
V_112 ) ;
V_13 = - V_227 ;
goto V_267;
}
for ( V_66 = 0 ; V_66 < V_8 -> V_67 ; V_66 ++ ) {
struct V_18 * V_19 = & V_25 -> V_68 [ V_66 ] ;
V_19 -> V_36 = V_66 ;
V_19 -> V_21 = V_25 -> V_21 + F_113 ( V_66 ) ;
F_114 ( & V_19 -> V_69 ) ;
if ( V_8 -> V_213 ) {
T_1 V_20 ;
V_20 = F_8 ( V_19 -> V_21 + V_22 ) ;
if ( V_20 & ( V_268 | V_269 ) ) {
F_95 ( & V_34 -> V_35 , L_69 , V_66 ) ;
V_19 -> V_70 = true ;
}
}
F_28 ( & V_34 -> V_35 , L_70 ,
V_66 , F_7 ( V_19 ) ? L_71 : L_72 ) ;
}
V_13 = F_92 ( V_25 , & V_25 -> memcpy ,
V_25 -> V_8 -> V_67 , false ) ;
if ( V_13 <= 0 ) {
F_115 ( & V_25 -> V_34 -> V_35 ,
L_73 ,
V_112 , V_13 ) ;
goto V_270;
}
V_25 -> memcpy . V_271 = V_13 ;
V_13 = F_92 ( V_25 , & V_25 -> V_134 ,
V_25 -> V_11 -> V_272 , true ) ;
if ( V_13 <= 0 ) {
F_115 ( & V_25 -> V_34 -> V_35 ,
L_74 ,
V_112 , V_13 ) ;
goto V_273;
}
V_25 -> V_134 . V_271 = V_13 ;
V_13 = F_116 ( & V_25 -> memcpy ) ;
if ( V_13 ) {
F_115 ( & V_25 -> V_34 -> V_35 ,
L_75 ,
V_112 , V_13 ) ;
goto V_274;
}
V_13 = F_116 ( & V_25 -> V_134 ) ;
if ( V_13 ) {
F_115 ( & V_25 -> V_34 -> V_35 ,
L_76 ,
V_112 , V_13 ) ;
goto V_275;
}
F_117 ( V_34 , V_25 ) ;
F_102 ( V_25 ) ;
F_95 ( & V_25 -> V_34 -> V_35 , L_77 ,
F_118 ( V_34 ) , F_119 ( V_34 ) ,
( unsigned long long ) V_34 -> V_262 . V_263 , V_34 -> V_215 [ 0 ] ) ;
return 0 ;
V_275:
F_120 ( & V_25 -> memcpy ) ;
V_274:
F_96 ( & V_25 -> V_134 ) ;
V_273:
F_96 ( & V_25 -> memcpy ) ;
V_270:
F_49 ( V_25 -> V_68 ) ;
V_267:
F_121 ( V_34 -> V_215 [ 0 ] , V_25 ) ;
V_266:
F_122 ( V_25 -> V_21 ) ;
V_264:
F_123 ( V_25 -> V_110 ) ;
V_261:
V_257:
F_49 ( V_25 ) ;
V_245:
F_124 ( V_34 ) ;
return V_13 ;
}
static int T_7 F_125 ( void )
{
int V_137 ;
V_137 = F_126 ( & V_211 ) ;
if ( V_137 )
F_127 (KERN_WARNING DRIVER_NAME
L_78 ,
retval) ;
return V_137 ;
}
