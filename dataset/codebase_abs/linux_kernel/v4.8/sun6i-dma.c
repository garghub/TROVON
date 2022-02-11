static struct V_1 * F_1 ( struct V_2 * V_3 )
{
return & V_3 -> V_4 -> V_1 ;
}
static inline struct V_5 * F_2 ( struct V_6 * V_7 )
{
return F_3 ( V_7 , struct V_5 , V_8 ) ;
}
static inline struct V_9 * F_4 ( struct V_2 * V_3 )
{
return F_3 ( V_3 , struct V_9 , V_10 . V_3 ) ;
}
static inline struct V_11 *
F_5 ( struct V_12 * V_13 )
{
return F_3 ( V_13 , struct V_11 , V_14 . V_13 ) ;
}
static inline void F_6 ( struct V_5 * V_15 )
{
F_7 ( V_15 -> V_8 . V_4 , L_1
L_2
L_3
L_4
L_5
L_6 ,
F_8 ( 0 ) , F_9 ( V_15 -> V_16 + F_8 ( 0 ) ) ,
F_8 ( 1 ) , F_9 ( V_15 -> V_16 + F_8 ( 1 ) ) ,
F_10 ( 0 ) , F_9 ( V_15 -> V_16 + F_10 ( 0 ) ) ,
F_10 ( 1 ) , F_9 ( V_15 -> V_16 + F_10 ( 1 ) ) ,
V_17 , F_9 ( V_15 -> V_16 + V_17 ) ) ;
}
static inline void F_11 ( struct V_5 * V_15 ,
struct V_18 * V_19 )
{
T_1 V_20 = F_12 ( V_19 -> V_16 ) ;
F_7 ( V_15 -> V_8 . V_4 , L_7
L_8
L_9
L_10
L_11
L_12
L_13
L_14
L_15 ,
V_19 -> V_21 , & V_20 ,
V_22 ,
F_9 ( V_19 -> V_16 + V_22 ) ,
V_23 ,
F_9 ( V_19 -> V_16 + V_23 ) ,
V_24 ,
F_9 ( V_19 -> V_16 + V_24 ) ,
V_25 ,
F_9 ( V_19 -> V_16 + V_25 ) ,
V_26 ,
F_9 ( V_19 -> V_16 + V_26 ) ,
V_27 ,
F_9 ( V_19 -> V_16 + V_27 ) ,
V_28 ,
F_9 ( V_19 -> V_16 + V_28 ) ,
V_29 ,
F_9 ( V_19 -> V_16 + V_29 ) ) ;
}
static inline T_2 F_13 ( T_3 V_30 )
{
switch ( V_30 ) {
case 1 :
return 0 ;
case 8 :
return 2 ;
default:
return - V_31 ;
}
}
static inline T_2 F_14 ( enum V_32 V_33 )
{
if ( ( V_33 < V_34 ) ||
( V_33 > V_35 ) )
return - V_31 ;
return V_33 >> 1 ;
}
static T_4 F_15 ( struct V_18 * V_19 )
{
struct V_11 * V_36 = V_19 -> V_37 ;
struct V_38 * V_39 ;
T_4 V_40 ;
T_5 V_41 ;
V_41 = F_9 ( V_19 -> V_16 + V_24 ) ;
V_40 = F_9 ( V_19 -> V_16 + V_28 ) ;
if ( V_41 == V_42 )
return V_40 ;
for ( V_39 = V_36 -> V_43 ; V_39 ; V_39 = V_39 -> V_44 ) {
if ( V_39 -> V_45 == V_41 ) {
for ( V_39 = V_39 -> V_44 ; V_39 ; V_39 = V_39 -> V_44 )
V_40 += V_39 -> V_46 ;
break;
}
}
return V_40 ;
}
static void * F_16 ( struct V_38 * V_47 ,
struct V_38 * V_48 ,
T_5 V_49 ,
struct V_11 * V_36 )
{
if ( ( ! V_47 && ! V_36 ) || ! V_48 )
return NULL ;
if ( ! V_47 ) {
V_36 -> V_50 = V_49 ;
V_36 -> V_43 = V_48 ;
} else {
V_47 -> V_45 = V_49 ;
V_47 -> V_44 = V_48 ;
}
V_48 -> V_45 = V_42 ;
V_48 -> V_44 = NULL ;
return V_48 ;
}
static inline void F_17 ( struct V_9 * V_51 ,
struct V_38 * V_39 )
{
T_1 V_50 = F_12 ( V_39 ) ;
F_7 ( F_1 ( & V_51 -> V_10 . V_3 ) ,
L_16
L_17
L_18 ,
& V_50 , V_39 ,
V_39 -> V_52 , V_39 -> V_53 , V_39 -> V_54 ,
V_39 -> V_46 , V_39 -> V_55 , V_39 -> V_45 ) ;
}
static void F_18 ( struct V_56 * V_14 )
{
struct V_11 * V_36 = F_5 ( & V_14 -> V_13 ) ;
struct V_5 * V_15 = F_2 ( V_14 -> V_13 . V_3 -> V_1 ) ;
struct V_38 * V_43 , * V_57 ;
T_5 V_50 , V_58 ;
if ( F_19 ( ! V_36 ) )
return;
V_50 = V_36 -> V_50 ;
V_43 = V_36 -> V_43 ;
while ( V_43 ) {
V_57 = V_43 -> V_44 ;
V_58 = V_43 -> V_45 ;
F_20 ( V_15 -> V_59 , V_43 , V_50 ) ;
V_43 = V_57 ;
V_50 = V_58 ;
}
F_21 ( V_36 ) ;
}
static int F_22 ( struct V_9 * V_51 )
{
struct V_5 * V_15 = F_2 ( V_51 -> V_10 . V_3 . V_1 ) ;
struct V_56 * V_37 = F_23 ( & V_51 -> V_10 ) ;
struct V_18 * V_19 = V_51 -> V_60 ;
T_3 V_61 , V_62 , V_63 ;
if ( ! V_19 )
return - V_64 ;
if ( ! V_37 ) {
V_19 -> V_37 = NULL ;
V_19 -> V_65 = NULL ;
return - V_64 ;
}
F_24 ( & V_37 -> V_66 ) ;
V_19 -> V_37 = F_5 ( & V_37 -> V_13 ) ;
V_19 -> V_65 = NULL ;
F_17 ( V_51 , V_19 -> V_37 -> V_43 ) ;
V_62 = V_19 -> V_21 / V_67 ;
V_63 = V_19 -> V_21 % V_67 ;
V_51 -> V_68 = V_51 -> V_69 ? V_70 : V_71 ;
V_61 = F_9 ( V_15 -> V_16 + F_8 ( V_62 ) ) ;
V_61 &= ~ ( ( V_72 | V_70 | V_71 ) <<
( V_63 * V_73 ) ) ;
V_61 |= V_51 -> V_68 << ( V_63 * V_73 ) ;
F_25 ( V_61 , V_15 -> V_16 + F_8 ( V_62 ) ) ;
F_25 ( V_19 -> V_37 -> V_50 , V_19 -> V_16 + V_24 ) ;
F_25 ( V_74 , V_19 -> V_16 + V_22 ) ;
F_6 ( V_15 ) ;
F_11 ( V_15 , V_19 ) ;
return 0 ;
}
static void F_26 ( unsigned long V_75 )
{
struct V_5 * V_15 = (struct V_5 * ) V_75 ;
const struct V_76 * V_52 = V_15 -> V_52 ;
struct V_9 * V_51 ;
struct V_18 * V_19 ;
unsigned int V_77 = 0 ;
unsigned int V_78 ;
F_27 (vchan, &sdev->slave.channels, vc.chan.device_node) {
F_28 ( & V_51 -> V_10 . V_79 ) ;
V_19 = V_51 -> V_60 ;
if ( V_19 && V_19 -> V_65 ) {
if ( F_22 ( V_51 ) ) {
F_7 ( V_15 -> V_8 . V_4 , L_19 ,
V_19 -> V_21 ) ;
V_51 -> V_60 = NULL ;
V_19 -> V_51 = NULL ;
}
}
F_29 ( & V_51 -> V_10 . V_79 ) ;
}
F_28 ( & V_15 -> V_79 ) ;
for ( V_78 = 0 ; V_78 < V_52 -> V_80 ; V_78 ++ ) {
V_19 = & V_15 -> V_81 [ V_78 ] ;
if ( V_19 -> V_51 || F_30 ( & V_15 -> V_82 ) )
continue;
V_51 = F_31 ( & V_15 -> V_82 ,
struct V_9 , V_66 ) ;
F_32 ( & V_51 -> V_66 ) ;
V_77 |= F_33 ( V_78 ) ;
V_19 -> V_51 = V_51 ;
V_51 -> V_60 = V_19 ;
F_7 ( V_15 -> V_8 . V_4 , L_20 ,
V_19 -> V_21 , & V_51 -> V_10 ) ;
}
F_29 ( & V_15 -> V_79 ) ;
for ( V_78 = 0 ; V_78 < V_52 -> V_80 ; V_78 ++ ) {
if ( ! ( V_77 & F_33 ( V_78 ) ) )
continue;
V_19 = V_15 -> V_81 + V_78 ;
V_51 = V_19 -> V_51 ;
if ( V_51 ) {
F_28 ( & V_51 -> V_10 . V_79 ) ;
F_22 ( V_51 ) ;
F_29 ( & V_51 -> V_10 . V_79 ) ;
}
}
}
static T_6 F_34 ( int V_83 , void * V_84 )
{
struct V_5 * V_15 = V_84 ;
struct V_9 * V_51 ;
struct V_18 * V_19 ;
int V_85 , V_86 , V_87 = V_88 ;
T_3 V_89 ;
for ( V_85 = 0 ; V_85 < V_15 -> V_52 -> V_80 / V_67 ; V_85 ++ ) {
V_89 = F_9 ( V_15 -> V_16 + F_10 ( V_85 ) ) ;
if ( ! V_89 )
continue;
F_7 ( V_15 -> V_8 . V_4 , L_21 ,
V_85 ? L_22 : L_23 , V_89 ) ;
F_25 ( V_89 , V_15 -> V_16 + F_10 ( V_85 ) ) ;
for ( V_86 = 0 ; ( V_86 < V_67 ) && V_89 ; V_86 ++ ) {
V_19 = V_15 -> V_81 + V_86 ;
V_51 = V_19 -> V_51 ;
if ( V_51 && ( V_89 & V_51 -> V_68 ) ) {
if ( V_51 -> V_69 ) {
F_35 ( & V_19 -> V_37 -> V_14 ) ;
} else {
F_36 ( & V_51 -> V_10 . V_79 ) ;
F_37 ( & V_19 -> V_37 -> V_14 ) ;
V_19 -> V_65 = V_19 -> V_37 ;
F_38 ( & V_51 -> V_10 . V_79 ) ;
}
}
V_89 = V_89 >> V_73 ;
}
if ( ! F_39 ( & V_15 -> V_90 ) )
F_40 ( & V_15 -> V_91 ) ;
V_87 = V_92 ;
}
return V_87 ;
}
static int F_41 ( struct V_5 * V_15 ,
struct V_93 * V_94 ,
enum V_95 V_96 ,
T_3 * V_97 )
{
T_2 V_98 , V_99 , V_100 , V_101 ;
switch ( V_96 ) {
case V_102 :
V_100 = F_13 ( V_94 -> V_103 ?
V_94 -> V_103 : 8 ) ;
V_98 = F_14 ( V_94 -> V_104 !=
V_105 ?
V_94 -> V_104 :
V_35 ) ;
V_101 = F_13 ( V_94 -> V_106 ) ;
V_99 = F_14 ( V_94 -> V_107 ) ;
break;
case V_108 :
V_100 = F_13 ( V_94 -> V_103 ) ;
V_98 = F_14 ( V_94 -> V_104 ) ;
V_101 = F_13 ( V_94 -> V_106 ?
V_94 -> V_106 : 8 ) ;
V_99 = F_14 ( V_94 -> V_107 !=
V_105 ?
V_94 -> V_107 :
V_35 ) ;
break;
default:
return - V_31 ;
}
if ( V_100 < 0 )
return V_100 ;
if ( V_98 < 0 )
return V_98 ;
if ( V_101 < 0 )
return V_101 ;
if ( V_99 < 0 )
return V_99 ;
* V_97 = F_42 ( V_100 ) |
F_43 ( V_98 ) |
F_44 ( V_101 ) |
F_45 ( V_99 ) ;
return 0 ;
}
static struct V_12 * F_46 (
struct V_2 * V_3 , T_5 V_109 , T_5 V_53 ,
T_4 V_46 , unsigned long V_110 )
{
struct V_5 * V_15 = F_2 ( V_3 -> V_1 ) ;
struct V_9 * V_51 = F_4 ( V_3 ) ;
struct V_38 * V_43 ;
struct V_11 * V_36 ;
T_5 V_50 ;
T_2 V_111 , V_112 ;
F_7 ( F_1 ( V_3 ) ,
L_24 ,
V_113 , V_51 -> V_10 . V_3 . V_114 , & V_109 , & V_53 , V_46 , V_110 ) ;
if ( ! V_46 )
return NULL ;
V_36 = F_47 ( sizeof( * V_36 ) , V_115 ) ;
if ( ! V_36 )
return NULL ;
V_43 = F_48 ( V_15 -> V_59 , V_115 , & V_50 ) ;
if ( ! V_43 ) {
F_49 ( V_15 -> V_8 . V_4 , L_25 ) ;
goto V_116;
}
V_43 -> V_53 = V_53 ;
V_43 -> V_54 = V_109 ;
V_43 -> V_46 = V_46 ;
V_43 -> V_55 = V_117 ;
V_111 = F_13 ( 8 ) ;
V_112 = F_14 ( V_35 ) ;
V_43 -> V_52 |= F_50 ( V_118 ) |
F_51 ( V_118 ) |
V_119 |
V_120 |
F_42 ( V_111 ) |
F_43 ( V_112 ) |
F_44 ( V_111 ) |
F_45 ( V_112 ) ;
F_16 ( NULL , V_43 , V_50 , V_36 ) ;
F_17 ( V_51 , V_43 ) ;
return F_52 ( & V_51 -> V_10 , & V_36 -> V_14 , V_110 ) ;
V_116:
F_21 ( V_36 ) ;
return NULL ;
}
static struct V_12 * F_53 (
struct V_2 * V_3 , struct V_121 * V_122 ,
unsigned int V_123 , enum V_95 V_124 ,
unsigned long V_110 , void * V_125 )
{
struct V_5 * V_15 = F_2 ( V_3 -> V_1 ) ;
struct V_9 * V_51 = F_4 ( V_3 ) ;
struct V_93 * V_94 = & V_51 -> V_52 ;
struct V_38 * V_43 , * V_47 = NULL ;
struct V_11 * V_36 ;
struct V_121 * V_126 ;
T_5 V_50 ;
T_3 V_127 ;
int V_85 , V_87 ;
if ( ! V_122 )
return NULL ;
V_87 = F_41 ( V_15 , V_94 , V_124 , & V_127 ) ;
if ( V_87 ) {
F_49 ( F_1 ( V_3 ) , L_26 ) ;
return NULL ;
}
V_36 = F_47 ( sizeof( * V_36 ) , V_115 ) ;
if ( ! V_36 )
return NULL ;
F_54 (sgl, sg, sg_len, i) {
V_43 = F_48 ( V_15 -> V_59 , V_115 , & V_50 ) ;
if ( ! V_43 )
goto V_128;
V_43 -> V_46 = F_55 ( V_126 ) ;
V_43 -> V_55 = V_117 ;
if ( V_124 == V_102 ) {
V_43 -> V_53 = F_56 ( V_126 ) ;
V_43 -> V_54 = V_94 -> V_129 ;
V_43 -> V_52 = V_127 |
V_130 |
V_120 |
F_50 ( V_118 ) |
F_51 ( V_51 -> V_131 ) ;
F_7 ( F_1 ( V_3 ) ,
L_27 ,
V_113 , V_51 -> V_10 . V_3 . V_114 ,
& V_94 -> V_129 , & F_56 ( V_126 ) ,
F_55 ( V_126 ) , V_110 ) ;
} else {
V_43 -> V_53 = V_94 -> V_132 ;
V_43 -> V_54 = F_56 ( V_126 ) ;
V_43 -> V_52 = V_127 |
V_119 |
V_133 |
F_51 ( V_118 ) |
F_50 ( V_51 -> V_131 ) ;
F_7 ( F_1 ( V_3 ) ,
L_27 ,
V_113 , V_51 -> V_10 . V_3 . V_114 ,
& F_56 ( V_126 ) , & V_94 -> V_132 ,
F_55 ( V_126 ) , V_110 ) ;
}
V_47 = F_16 ( V_47 , V_43 , V_50 , V_36 ) ;
}
F_7 ( F_1 ( V_3 ) , L_28 , & V_36 -> V_50 ) ;
for ( V_47 = V_36 -> V_43 ; V_47 ; V_47 = V_47 -> V_44 )
F_17 ( V_51 , V_47 ) ;
return F_52 ( & V_51 -> V_10 , & V_36 -> V_14 , V_110 ) ;
V_128:
for ( V_47 = V_36 -> V_43 ; V_47 ; V_47 = V_47 -> V_44 )
F_20 ( V_15 -> V_59 , V_47 , F_12 ( V_47 ) ) ;
F_21 ( V_36 ) ;
return NULL ;
}
static struct V_12 * F_57 (
struct V_2 * V_3 ,
T_5 V_134 ,
T_4 V_135 ,
T_4 V_136 ,
enum V_95 V_124 ,
unsigned long V_110 )
{
struct V_5 * V_15 = F_2 ( V_3 -> V_1 ) ;
struct V_9 * V_51 = F_4 ( V_3 ) ;
struct V_93 * V_94 = & V_51 -> V_52 ;
struct V_38 * V_43 , * V_47 = NULL ;
struct V_11 * V_36 ;
T_5 V_50 ;
T_3 V_127 ;
unsigned int V_85 , V_137 = V_135 / V_136 ;
int V_87 ;
V_87 = F_41 ( V_15 , V_94 , V_124 , & V_127 ) ;
if ( V_87 ) {
F_49 ( F_1 ( V_3 ) , L_26 ) ;
return NULL ;
}
V_36 = F_47 ( sizeof( * V_36 ) , V_115 ) ;
if ( ! V_36 )
return NULL ;
for ( V_85 = 0 ; V_85 < V_137 ; V_85 ++ ) {
V_43 = F_48 ( V_15 -> V_59 , V_115 , & V_50 ) ;
if ( ! V_43 ) {
F_49 ( V_15 -> V_8 . V_4 , L_25 ) ;
goto V_128;
}
V_43 -> V_46 = V_136 ;
V_43 -> V_55 = V_117 ;
if ( V_124 == V_102 ) {
V_43 -> V_53 = V_134 + V_136 * V_85 ;
V_43 -> V_54 = V_94 -> V_129 ;
V_43 -> V_52 = V_127 |
V_130 |
V_120 |
F_50 ( V_118 ) |
F_51 ( V_51 -> V_131 ) ;
} else {
V_43 -> V_53 = V_94 -> V_132 ;
V_43 -> V_54 = V_134 + V_136 * V_85 ;
V_43 -> V_52 = V_127 |
V_119 |
V_133 |
F_51 ( V_118 ) |
F_50 ( V_51 -> V_131 ) ;
}
V_47 = F_16 ( V_47 , V_43 , V_50 , V_36 ) ;
}
V_47 -> V_45 = V_36 -> V_50 ;
V_51 -> V_69 = true ;
return F_52 ( & V_51 -> V_10 , & V_36 -> V_14 , V_110 ) ;
V_128:
for ( V_47 = V_36 -> V_43 ; V_47 ; V_47 = V_47 -> V_44 )
F_20 ( V_15 -> V_59 , V_47 , F_12 ( V_47 ) ) ;
F_21 ( V_36 ) ;
return NULL ;
}
static int V_76 ( struct V_2 * V_3 ,
struct V_93 * V_138 )
{
struct V_9 * V_51 = F_4 ( V_3 ) ;
memcpy ( & V_51 -> V_52 , V_138 , sizeof( * V_138 ) ) ;
return 0 ;
}
static int F_58 ( struct V_2 * V_3 )
{
struct V_5 * V_15 = F_2 ( V_3 -> V_1 ) ;
struct V_9 * V_51 = F_4 ( V_3 ) ;
struct V_18 * V_19 = V_51 -> V_60 ;
F_7 ( F_1 ( V_3 ) , L_29 , & V_51 -> V_10 ) ;
if ( V_19 ) {
F_25 ( V_139 ,
V_19 -> V_16 + V_23 ) ;
} else {
F_36 ( & V_15 -> V_79 ) ;
F_32 ( & V_51 -> V_66 ) ;
F_38 ( & V_15 -> V_79 ) ;
}
return 0 ;
}
static int F_59 ( struct V_2 * V_3 )
{
struct V_5 * V_15 = F_2 ( V_3 -> V_1 ) ;
struct V_9 * V_51 = F_4 ( V_3 ) ;
struct V_18 * V_19 = V_51 -> V_60 ;
unsigned long V_110 ;
F_7 ( F_1 ( V_3 ) , L_30 , & V_51 -> V_10 ) ;
F_60 ( & V_51 -> V_10 . V_79 , V_110 ) ;
if ( V_19 ) {
F_25 ( V_140 ,
V_19 -> V_16 + V_23 ) ;
} else if ( ! F_30 ( & V_51 -> V_10 . V_141 ) ) {
F_36 ( & V_15 -> V_79 ) ;
F_61 ( & V_51 -> V_66 , & V_15 -> V_82 ) ;
F_38 ( & V_15 -> V_79 ) ;
}
F_62 ( & V_51 -> V_10 . V_79 , V_110 ) ;
return 0 ;
}
static int F_63 ( struct V_2 * V_3 )
{
struct V_5 * V_15 = F_2 ( V_3 -> V_1 ) ;
struct V_9 * V_51 = F_4 ( V_3 ) ;
struct V_18 * V_19 = V_51 -> V_60 ;
unsigned long V_110 ;
F_64 ( V_142 ) ;
F_36 ( & V_15 -> V_79 ) ;
F_32 ( & V_51 -> V_66 ) ;
F_38 ( & V_15 -> V_79 ) ;
F_60 ( & V_51 -> V_10 . V_79 , V_110 ) ;
if ( V_51 -> V_69 ) {
V_51 -> V_69 = false ;
if ( V_19 && V_19 -> V_37 ) {
struct V_56 * V_14 = & V_19 -> V_37 -> V_14 ;
struct V_143 * V_10 = & V_51 -> V_10 ;
F_61 ( & V_14 -> V_66 , & V_10 -> V_144 ) ;
}
}
F_65 ( & V_51 -> V_10 , & V_142 ) ;
if ( V_19 ) {
F_25 ( V_145 , V_19 -> V_16 + V_22 ) ;
F_25 ( V_140 , V_19 -> V_16 + V_23 ) ;
V_51 -> V_60 = NULL ;
V_19 -> V_51 = NULL ;
V_19 -> V_37 = NULL ;
V_19 -> V_65 = NULL ;
}
F_62 ( & V_51 -> V_10 . V_79 , V_110 ) ;
F_66 ( & V_51 -> V_10 , & V_142 ) ;
return 0 ;
}
static enum V_146 F_67 ( struct V_2 * V_3 ,
T_7 V_147 ,
struct V_148 * V_149 )
{
struct V_9 * V_51 = F_4 ( V_3 ) ;
struct V_18 * V_19 = V_51 -> V_60 ;
struct V_38 * V_39 ;
struct V_56 * V_14 ;
struct V_11 * V_36 ;
enum V_146 V_87 ;
unsigned long V_110 ;
T_4 V_40 = 0 ;
V_87 = F_68 ( V_3 , V_147 , V_149 ) ;
if ( V_87 == V_150 || ! V_149 )
return V_87 ;
F_60 ( & V_51 -> V_10 . V_79 , V_110 ) ;
V_14 = F_69 ( & V_51 -> V_10 , V_147 ) ;
V_36 = F_5 ( & V_14 -> V_13 ) ;
if ( V_14 ) {
for ( V_39 = V_36 -> V_43 ; V_39 != NULL ; V_39 = V_39 -> V_44 )
V_40 += V_39 -> V_46 ;
} else if ( ! V_19 || ! V_19 -> V_37 ) {
V_40 = 0 ;
} else {
V_40 = F_15 ( V_19 ) ;
}
F_62 ( & V_51 -> V_10 . V_79 , V_110 ) ;
F_70 ( V_149 , V_40 ) ;
return V_87 ;
}
static void F_71 ( struct V_2 * V_3 )
{
struct V_5 * V_15 = F_2 ( V_3 -> V_1 ) ;
struct V_9 * V_51 = F_4 ( V_3 ) ;
unsigned long V_110 ;
F_60 ( & V_51 -> V_10 . V_79 , V_110 ) ;
if ( F_72 ( & V_51 -> V_10 ) ) {
F_36 ( & V_15 -> V_79 ) ;
if ( ! V_51 -> V_60 && F_30 ( & V_51 -> V_66 ) ) {
F_61 ( & V_51 -> V_66 , & V_15 -> V_82 ) ;
F_40 ( & V_15 -> V_91 ) ;
F_7 ( F_1 ( V_3 ) , L_31 ,
& V_51 -> V_10 ) ;
}
F_38 ( & V_15 -> V_79 ) ;
} else {
F_7 ( F_1 ( V_3 ) , L_32 ,
& V_51 -> V_10 ) ;
}
F_62 ( & V_51 -> V_10 . V_79 , V_110 ) ;
}
static void F_73 ( struct V_2 * V_3 )
{
struct V_5 * V_15 = F_2 ( V_3 -> V_1 ) ;
struct V_9 * V_51 = F_4 ( V_3 ) ;
unsigned long V_110 ;
F_60 ( & V_15 -> V_79 , V_110 ) ;
F_32 ( & V_51 -> V_66 ) ;
F_62 ( & V_15 -> V_79 , V_110 ) ;
F_74 ( & V_51 -> V_10 ) ;
}
static struct V_2 * F_75 ( struct V_151 * V_152 ,
struct V_153 * V_154 )
{
struct V_5 * V_15 = V_154 -> V_155 ;
struct V_9 * V_51 ;
struct V_2 * V_3 ;
T_8 V_131 = V_152 -> args [ 0 ] ;
if ( V_131 > V_15 -> V_52 -> V_156 )
return NULL ;
V_3 = F_76 ( & V_15 -> V_8 ) ;
if ( ! V_3 )
return NULL ;
V_51 = F_4 ( V_3 ) ;
V_51 -> V_131 = V_131 ;
return V_3 ;
}
static inline void F_77 ( struct V_5 * V_15 )
{
F_25 ( 0 , V_15 -> V_16 + F_8 ( 0 ) ) ;
F_25 ( 0 , V_15 -> V_16 + F_8 ( 1 ) ) ;
F_78 ( & V_15 -> V_90 ) ;
F_79 ( V_15 -> V_8 . V_4 , V_15 -> V_83 , V_15 ) ;
F_80 ( & V_15 -> V_91 ) ;
}
static inline void F_81 ( struct V_5 * V_15 )
{
int V_85 ;
for ( V_85 = 0 ; V_85 < V_15 -> V_52 -> V_157 ; V_85 ++ ) {
struct V_9 * V_51 = & V_15 -> V_158 [ V_85 ] ;
F_24 ( & V_51 -> V_10 . V_3 . V_159 ) ;
F_80 ( & V_51 -> V_10 . V_91 ) ;
}
}
static int F_82 ( struct V_160 * V_161 )
{
const struct V_162 * V_1 ;
struct V_5 * V_163 ;
struct V_164 * V_165 ;
int V_87 , V_85 ;
V_163 = F_83 ( & V_161 -> V_4 , sizeof( * V_163 ) , V_166 ) ;
if ( ! V_163 )
return - V_167 ;
V_1 = F_84 ( V_168 , & V_161 -> V_4 ) ;
if ( ! V_1 )
return - V_169 ;
V_163 -> V_52 = V_1 -> V_75 ;
V_165 = F_85 ( V_161 , V_170 , 0 ) ;
V_163 -> V_16 = F_86 ( & V_161 -> V_4 , V_165 ) ;
if ( F_87 ( V_163 -> V_16 ) )
return F_88 ( V_163 -> V_16 ) ;
V_163 -> V_83 = F_89 ( V_161 , 0 ) ;
if ( V_163 -> V_83 < 0 ) {
F_49 ( & V_161 -> V_4 , L_33 ) ;
return V_163 -> V_83 ;
}
V_163 -> V_171 = F_90 ( & V_161 -> V_4 , NULL ) ;
if ( F_87 ( V_163 -> V_171 ) ) {
F_49 ( & V_161 -> V_4 , L_34 ) ;
return F_88 ( V_163 -> V_171 ) ;
}
V_163 -> V_172 = F_91 ( & V_161 -> V_4 , NULL ) ;
if ( F_87 ( V_163 -> V_172 ) ) {
F_49 ( & V_161 -> V_4 , L_35 ) ;
return F_88 ( V_163 -> V_172 ) ;
}
V_163 -> V_59 = F_92 ( F_93 ( & V_161 -> V_4 ) , & V_161 -> V_4 ,
sizeof( struct V_38 ) , 4 , 0 ) ;
if ( ! V_163 -> V_59 ) {
F_49 ( & V_161 -> V_4 , L_36 ) ;
return - V_167 ;
}
F_94 ( V_161 , V_163 ) ;
F_95 ( & V_163 -> V_82 ) ;
F_96 ( & V_163 -> V_79 ) ;
F_97 ( V_173 , V_163 -> V_8 . V_174 ) ;
F_97 ( V_175 , V_163 -> V_8 . V_174 ) ;
F_97 ( V_176 , V_163 -> V_8 . V_174 ) ;
F_97 ( V_177 , V_163 -> V_8 . V_174 ) ;
F_95 ( & V_163 -> V_8 . V_178 ) ;
V_163 -> V_8 . V_179 = F_73 ;
V_163 -> V_8 . V_180 = F_67 ;
V_163 -> V_8 . V_181 = F_71 ;
V_163 -> V_8 . V_182 = F_53 ;
V_163 -> V_8 . V_183 = F_46 ;
V_163 -> V_8 . V_184 = F_57 ;
V_163 -> V_8 . V_185 = V_186 ;
V_163 -> V_8 . V_187 = V_76 ;
V_163 -> V_8 . V_188 = F_58 ;
V_163 -> V_8 . V_189 = F_59 ;
V_163 -> V_8 . V_190 = F_63 ;
V_163 -> V_8 . V_191 = F_33 ( V_34 ) |
F_33 ( V_192 ) |
F_33 ( V_35 ) ;
V_163 -> V_8 . V_193 = F_33 ( V_34 ) |
F_33 ( V_192 ) |
F_33 ( V_35 ) ;
V_163 -> V_8 . V_194 = F_33 ( V_108 ) |
F_33 ( V_102 ) ;
V_163 -> V_8 . V_195 = V_196 ;
V_163 -> V_8 . V_4 = & V_161 -> V_4 ;
V_163 -> V_81 = F_98 ( & V_161 -> V_4 , V_163 -> V_52 -> V_80 ,
sizeof( struct V_18 ) , V_166 ) ;
if ( ! V_163 -> V_81 )
return - V_167 ;
V_163 -> V_158 = F_98 ( & V_161 -> V_4 , V_163 -> V_52 -> V_157 ,
sizeof( struct V_9 ) , V_166 ) ;
if ( ! V_163 -> V_158 )
return - V_167 ;
F_99 ( & V_163 -> V_91 , F_26 , ( unsigned long ) V_163 ) ;
for ( V_85 = 0 ; V_85 < V_163 -> V_52 -> V_80 ; V_85 ++ ) {
struct V_18 * V_19 = & V_163 -> V_81 [ V_85 ] ;
V_19 -> V_21 = V_85 ;
V_19 -> V_16 = V_163 -> V_16 + 0x100 + V_85 * 0x40 ;
}
for ( V_85 = 0 ; V_85 < V_163 -> V_52 -> V_157 ; V_85 ++ ) {
struct V_9 * V_51 = & V_163 -> V_158 [ V_85 ] ;
F_95 ( & V_51 -> V_66 ) ;
V_51 -> V_10 . V_197 = F_18 ;
F_100 ( & V_51 -> V_10 , & V_163 -> V_8 ) ;
}
V_87 = F_101 ( V_163 -> V_172 ) ;
if ( V_87 ) {
F_49 ( & V_161 -> V_4 , L_37 ) ;
goto V_198;
}
V_87 = F_102 ( V_163 -> V_171 ) ;
if ( V_87 ) {
F_49 ( & V_161 -> V_4 , L_38 ) ;
goto V_199;
}
V_87 = F_103 ( & V_161 -> V_4 , V_163 -> V_83 , F_34 , 0 ,
F_93 ( & V_161 -> V_4 ) , V_163 ) ;
if ( V_87 ) {
F_49 ( & V_161 -> V_4 , L_39 ) ;
goto V_200;
}
V_87 = F_104 ( & V_163 -> V_8 ) ;
if ( V_87 ) {
F_105 ( & V_161 -> V_4 , L_40 ) ;
goto V_201;
}
V_87 = F_106 ( V_161 -> V_4 . V_202 , F_75 ,
V_163 ) ;
if ( V_87 ) {
F_49 ( & V_161 -> V_4 , L_41 ) ;
goto V_203;
}
if ( F_107 ( V_161 -> V_4 . V_202 ,
L_42 ) )
F_25 ( V_204 , V_163 -> V_16 + V_205 ) ;
return 0 ;
V_203:
F_108 ( & V_163 -> V_8 ) ;
V_201:
F_77 ( V_163 ) ;
V_200:
F_109 ( V_163 -> V_171 ) ;
V_199:
F_110 ( V_163 -> V_172 ) ;
V_198:
F_81 ( V_163 ) ;
return V_87 ;
}
static int F_111 ( struct V_160 * V_161 )
{
struct V_5 * V_163 = F_112 ( V_161 ) ;
F_113 ( V_161 -> V_4 . V_202 ) ;
F_108 ( & V_163 -> V_8 ) ;
F_77 ( V_163 ) ;
F_109 ( V_163 -> V_171 ) ;
F_110 ( V_163 -> V_172 ) ;
F_81 ( V_163 ) ;
return 0 ;
}
