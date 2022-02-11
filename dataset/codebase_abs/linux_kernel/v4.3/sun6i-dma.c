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
static void * F_15 ( struct V_36 * V_37 ,
struct V_36 * V_38 ,
T_4 V_39 ,
struct V_11 * V_40 )
{
if ( ( ! V_37 && ! V_40 ) || ! V_38 )
return NULL ;
if ( ! V_37 ) {
V_40 -> V_41 = V_39 ;
V_40 -> V_42 = V_38 ;
} else {
V_37 -> V_43 = V_39 ;
V_37 -> V_44 = V_38 ;
}
V_38 -> V_43 = V_45 ;
V_38 -> V_44 = NULL ;
return V_38 ;
}
static inline int F_16 ( struct V_36 * V_46 ,
T_4 V_47 ,
T_4 V_48 , T_3 V_49 ,
struct V_50 * V_51 )
{
T_5 V_52 , V_53 , V_54 , V_55 ;
if ( ! V_51 )
return - V_31 ;
V_54 = F_13 ( V_51 -> V_56 ) ;
if ( V_54 )
return V_54 ;
V_55 = F_13 ( V_51 -> V_57 ) ;
if ( V_55 )
return V_55 ;
V_52 = F_14 ( V_51 -> V_58 ) ;
if ( V_52 )
return V_52 ;
V_53 = F_14 ( V_51 -> V_59 ) ;
if ( V_53 )
return V_53 ;
V_46 -> V_60 = F_17 ( V_54 ) |
F_18 ( V_52 ) |
F_19 ( V_55 ) |
F_20 ( V_53 ) ;
V_46 -> V_47 = V_47 ;
V_46 -> V_48 = V_48 ;
V_46 -> V_49 = V_49 ;
V_46 -> V_61 = V_62 ;
return 0 ;
}
static inline void F_21 ( struct V_9 * V_63 ,
struct V_36 * V_46 )
{
T_1 V_41 = F_12 ( V_46 ) ;
F_7 ( F_1 ( & V_63 -> V_10 . V_3 ) ,
L_16
L_17
L_18 ,
& V_41 , V_46 ,
V_46 -> V_60 , V_46 -> V_47 , V_46 -> V_48 ,
V_46 -> V_49 , V_46 -> V_61 , V_46 -> V_43 ) ;
}
static void F_22 ( struct V_64 * V_14 )
{
struct V_11 * V_40 = F_5 ( & V_14 -> V_13 ) ;
struct V_5 * V_15 = F_2 ( V_14 -> V_13 . V_3 -> V_1 ) ;
struct V_36 * V_42 , * V_65 ;
T_4 V_41 , V_66 ;
if ( F_23 ( ! V_40 ) )
return;
V_41 = V_40 -> V_41 ;
V_42 = V_40 -> V_42 ;
while ( V_42 ) {
V_65 = V_42 -> V_44 ;
V_66 = V_42 -> V_43 ;
F_24 ( V_15 -> V_67 , V_42 , V_41 ) ;
V_42 = V_65 ;
V_41 = V_66 ;
}
F_25 ( V_40 ) ;
}
static int F_26 ( struct V_9 * V_63 )
{
struct V_5 * V_15 = F_2 ( V_63 -> V_10 . V_3 . V_1 ) ;
struct V_64 * V_68 = F_27 ( & V_63 -> V_10 ) ;
struct V_18 * V_19 = V_63 -> V_69 ;
T_3 V_70 , V_71 , V_72 ;
if ( ! V_19 )
return - V_73 ;
if ( ! V_68 ) {
V_19 -> V_68 = NULL ;
V_19 -> V_74 = NULL ;
return - V_73 ;
}
F_28 ( & V_68 -> V_75 ) ;
V_19 -> V_68 = F_5 ( & V_68 -> V_13 ) ;
V_19 -> V_74 = NULL ;
F_21 ( V_63 , V_19 -> V_68 -> V_42 ) ;
V_71 = V_19 -> V_21 / V_76 ;
V_72 = V_19 -> V_21 % V_76 ;
V_70 = F_9 ( V_15 -> V_16 + F_8 ( V_72 ) ) ;
V_70 |= V_77 << ( V_72 * V_78 ) ;
F_29 ( V_70 , V_15 -> V_16 + F_8 ( V_72 ) ) ;
F_29 ( V_19 -> V_68 -> V_41 , V_19 -> V_16 + V_24 ) ;
F_29 ( V_79 , V_19 -> V_16 + V_22 ) ;
F_6 ( V_15 ) ;
F_11 ( V_15 , V_19 ) ;
return 0 ;
}
static void F_30 ( unsigned long V_80 )
{
struct V_5 * V_15 = (struct V_5 * ) V_80 ;
const struct V_81 * V_60 = V_15 -> V_60 ;
struct V_9 * V_63 ;
struct V_18 * V_19 ;
unsigned int V_82 = 0 ;
unsigned int V_83 ;
F_31 (vchan, &sdev->slave.channels, vc.chan.device_node) {
F_32 ( & V_63 -> V_10 . V_84 ) ;
V_19 = V_63 -> V_69 ;
if ( V_19 && V_19 -> V_74 ) {
if ( F_26 ( V_63 ) ) {
F_7 ( V_15 -> V_8 . V_4 , L_19 ,
V_19 -> V_21 ) ;
V_63 -> V_69 = NULL ;
V_19 -> V_63 = NULL ;
}
}
F_33 ( & V_63 -> V_10 . V_84 ) ;
}
F_32 ( & V_15 -> V_84 ) ;
for ( V_83 = 0 ; V_83 < V_60 -> V_85 ; V_83 ++ ) {
V_19 = & V_15 -> V_86 [ V_83 ] ;
if ( V_19 -> V_63 || F_34 ( & V_15 -> V_87 ) )
continue;
V_63 = F_35 ( & V_15 -> V_87 ,
struct V_9 , V_75 ) ;
F_36 ( & V_63 -> V_75 ) ;
V_82 |= F_37 ( V_83 ) ;
V_19 -> V_63 = V_63 ;
V_63 -> V_69 = V_19 ;
F_7 ( V_15 -> V_8 . V_4 , L_20 ,
V_19 -> V_21 , & V_63 -> V_10 ) ;
}
F_33 ( & V_15 -> V_84 ) ;
for ( V_83 = 0 ; V_83 < V_60 -> V_85 ; V_83 ++ ) {
if ( ! ( V_82 & F_37 ( V_83 ) ) )
continue;
V_19 = V_15 -> V_86 + V_83 ;
V_63 = V_19 -> V_63 ;
if ( V_63 ) {
F_32 ( & V_63 -> V_10 . V_84 ) ;
F_26 ( V_63 ) ;
F_33 ( & V_63 -> V_10 . V_84 ) ;
}
}
}
static T_6 F_38 ( int V_88 , void * V_89 )
{
struct V_5 * V_15 = V_89 ;
struct V_9 * V_63 ;
struct V_18 * V_19 ;
int V_90 , V_91 , V_92 = V_93 ;
T_3 V_94 ;
for ( V_90 = 0 ; V_90 < V_15 -> V_60 -> V_85 / V_76 ; V_90 ++ ) {
V_94 = F_9 ( V_15 -> V_16 + F_10 ( V_90 ) ) ;
if ( ! V_94 )
continue;
F_7 ( V_15 -> V_8 . V_4 , L_21 ,
V_90 ? L_22 : L_23 , V_94 ) ;
F_29 ( V_94 , V_15 -> V_16 + F_10 ( V_90 ) ) ;
for ( V_91 = 0 ; ( V_91 < V_76 ) && V_94 ; V_91 ++ ) {
if ( V_94 & V_77 ) {
V_19 = V_15 -> V_86 + V_91 ;
V_63 = V_19 -> V_63 ;
if ( V_63 ) {
F_39 ( & V_63 -> V_10 . V_84 ) ;
F_40 ( & V_19 -> V_68 -> V_14 ) ;
V_19 -> V_74 = V_19 -> V_68 ;
F_41 ( & V_63 -> V_10 . V_84 ) ;
}
}
V_94 = V_94 >> V_78 ;
}
if ( ! F_42 ( & V_15 -> V_95 ) )
F_43 ( & V_15 -> V_96 ) ;
V_92 = V_97 ;
}
return V_92 ;
}
static struct V_12 * F_44 (
struct V_2 * V_3 , T_4 V_98 , T_4 V_47 ,
T_7 V_49 , unsigned long V_99 )
{
struct V_5 * V_15 = F_2 ( V_3 -> V_1 ) ;
struct V_9 * V_63 = F_4 ( V_3 ) ;
struct V_36 * V_42 ;
struct V_11 * V_40 ;
T_4 V_41 ;
T_2 V_100 , V_101 ;
F_7 ( F_1 ( V_3 ) ,
L_24 ,
V_102 , V_63 -> V_10 . V_3 . V_103 , & V_98 , & V_47 , V_49 , V_99 ) ;
if ( ! V_49 )
return NULL ;
V_40 = F_45 ( sizeof( * V_40 ) , V_104 ) ;
if ( ! V_40 )
return NULL ;
V_42 = F_46 ( V_15 -> V_67 , V_104 , & V_41 ) ;
if ( ! V_42 ) {
F_47 ( V_15 -> V_8 . V_4 , L_25 ) ;
goto V_105;
}
V_42 -> V_47 = V_47 ;
V_42 -> V_48 = V_98 ;
V_42 -> V_49 = V_49 ;
V_42 -> V_61 = V_62 ;
V_100 = F_13 ( 8 ) ;
V_101 = F_14 ( V_35 ) ;
V_42 -> V_60 |= F_48 ( V_106 ) |
F_49 ( V_106 ) |
V_107 |
V_108 |
F_17 ( V_100 ) |
F_18 ( V_101 ) |
F_19 ( V_100 ) |
F_20 ( V_101 ) ;
F_15 ( NULL , V_42 , V_41 , V_40 ) ;
F_21 ( V_63 , V_42 ) ;
return F_50 ( & V_63 -> V_10 , & V_40 -> V_14 , V_99 ) ;
V_105:
F_25 ( V_40 ) ;
return NULL ;
}
static struct V_12 * F_51 (
struct V_2 * V_3 , struct V_109 * V_110 ,
unsigned int V_111 , enum V_112 V_113 ,
unsigned long V_99 , void * V_114 )
{
struct V_5 * V_15 = F_2 ( V_3 -> V_1 ) ;
struct V_9 * V_63 = F_4 ( V_3 ) ;
struct V_50 * V_115 = & V_63 -> V_60 ;
struct V_36 * V_42 , * V_37 = NULL ;
struct V_11 * V_40 ;
struct V_109 * V_116 ;
T_4 V_41 ;
int V_90 , V_92 ;
if ( ! V_110 )
return NULL ;
if ( ! F_52 ( V_113 ) ) {
F_47 ( F_1 ( V_3 ) , L_26 ) ;
return NULL ;
}
V_40 = F_45 ( sizeof( * V_40 ) , V_104 ) ;
if ( ! V_40 )
return NULL ;
F_53 (sgl, sg, sg_len, i) {
V_42 = F_46 ( V_15 -> V_67 , V_104 , & V_41 ) ;
if ( ! V_42 )
goto V_117;
if ( V_113 == V_118 ) {
V_92 = F_16 ( V_42 , F_54 ( V_116 ) ,
V_115 -> V_119 , F_55 ( V_116 ) ,
V_115 ) ;
if ( V_92 )
goto V_120;
V_42 -> V_60 |= V_121 |
V_108 |
F_48 ( V_106 ) |
F_49 ( V_63 -> V_122 ) ;
F_7 ( F_1 ( V_3 ) ,
L_27 ,
V_102 , V_63 -> V_10 . V_3 . V_103 ,
& V_115 -> V_119 , & F_54 ( V_116 ) ,
F_55 ( V_116 ) , V_99 ) ;
} else {
V_92 = F_16 ( V_42 , V_115 -> V_123 ,
F_54 ( V_116 ) , F_55 ( V_116 ) ,
V_115 ) ;
if ( V_92 )
goto V_120;
V_42 -> V_60 |= V_107 |
V_124 |
F_49 ( V_106 ) |
F_48 ( V_63 -> V_122 ) ;
F_7 ( F_1 ( V_3 ) ,
L_27 ,
V_102 , V_63 -> V_10 . V_3 . V_103 ,
& F_54 ( V_116 ) , & V_115 -> V_123 ,
F_55 ( V_116 ) , V_99 ) ;
}
V_37 = F_15 ( V_37 , V_42 , V_41 , V_40 ) ;
}
F_7 ( F_1 ( V_3 ) , L_28 , & V_40 -> V_41 ) ;
for ( V_37 = V_40 -> V_42 ; V_37 ; V_37 = V_37 -> V_44 )
F_21 ( V_63 , V_37 ) ;
return F_50 ( & V_63 -> V_10 , & V_40 -> V_14 , V_99 ) ;
V_120:
F_24 ( V_15 -> V_67 , V_42 , V_41 ) ;
V_117:
for ( V_37 = V_40 -> V_42 ; V_37 ; V_37 = V_37 -> V_44 )
F_24 ( V_15 -> V_67 , V_37 , F_12 ( V_37 ) ) ;
F_25 ( V_40 ) ;
return NULL ;
}
static int V_81 ( struct V_2 * V_3 ,
struct V_50 * V_51 )
{
struct V_9 * V_63 = F_4 ( V_3 ) ;
memcpy ( & V_63 -> V_60 , V_51 , sizeof( * V_51 ) ) ;
return 0 ;
}
static int F_56 ( struct V_2 * V_3 )
{
struct V_5 * V_15 = F_2 ( V_3 -> V_1 ) ;
struct V_9 * V_63 = F_4 ( V_3 ) ;
struct V_18 * V_19 = V_63 -> V_69 ;
F_7 ( F_1 ( V_3 ) , L_29 , & V_63 -> V_10 ) ;
if ( V_19 ) {
F_29 ( V_125 ,
V_19 -> V_16 + V_23 ) ;
} else {
F_39 ( & V_15 -> V_84 ) ;
F_36 ( & V_63 -> V_75 ) ;
F_41 ( & V_15 -> V_84 ) ;
}
return 0 ;
}
static int F_57 ( struct V_2 * V_3 )
{
struct V_5 * V_15 = F_2 ( V_3 -> V_1 ) ;
struct V_9 * V_63 = F_4 ( V_3 ) ;
struct V_18 * V_19 = V_63 -> V_69 ;
unsigned long V_99 ;
F_7 ( F_1 ( V_3 ) , L_30 , & V_63 -> V_10 ) ;
F_58 ( & V_63 -> V_10 . V_84 , V_99 ) ;
if ( V_19 ) {
F_29 ( V_126 ,
V_19 -> V_16 + V_23 ) ;
} else if ( ! F_34 ( & V_63 -> V_10 . V_127 ) ) {
F_39 ( & V_15 -> V_84 ) ;
F_59 ( & V_63 -> V_75 , & V_15 -> V_87 ) ;
F_41 ( & V_15 -> V_84 ) ;
}
F_60 ( & V_63 -> V_10 . V_84 , V_99 ) ;
return 0 ;
}
static int F_61 ( struct V_2 * V_3 )
{
struct V_5 * V_15 = F_2 ( V_3 -> V_1 ) ;
struct V_9 * V_63 = F_4 ( V_3 ) ;
struct V_18 * V_19 = V_63 -> V_69 ;
unsigned long V_99 ;
F_62 ( V_128 ) ;
F_39 ( & V_15 -> V_84 ) ;
F_36 ( & V_63 -> V_75 ) ;
F_41 ( & V_15 -> V_84 ) ;
F_58 ( & V_63 -> V_10 . V_84 , V_99 ) ;
F_63 ( & V_63 -> V_10 , & V_128 ) ;
if ( V_19 ) {
F_29 ( V_129 , V_19 -> V_16 + V_22 ) ;
F_29 ( V_126 , V_19 -> V_16 + V_23 ) ;
V_63 -> V_69 = NULL ;
V_19 -> V_63 = NULL ;
V_19 -> V_68 = NULL ;
V_19 -> V_74 = NULL ;
}
F_60 ( & V_63 -> V_10 . V_84 , V_99 ) ;
F_64 ( & V_63 -> V_10 , & V_128 ) ;
return 0 ;
}
static enum V_130 F_65 ( struct V_2 * V_3 ,
T_8 V_131 ,
struct V_132 * V_133 )
{
struct V_9 * V_63 = F_4 ( V_3 ) ;
struct V_18 * V_19 = V_63 -> V_69 ;
struct V_36 * V_46 ;
struct V_64 * V_14 ;
struct V_11 * V_40 ;
enum V_130 V_92 ;
unsigned long V_99 ;
T_7 V_134 = 0 ;
V_92 = F_66 ( V_3 , V_131 , V_133 ) ;
if ( V_92 == V_135 )
return V_92 ;
F_58 ( & V_63 -> V_10 . V_84 , V_99 ) ;
V_14 = F_67 ( & V_63 -> V_10 , V_131 ) ;
V_40 = F_5 ( & V_14 -> V_13 ) ;
if ( V_14 ) {
for ( V_46 = V_40 -> V_42 ; V_46 != NULL ; V_46 = V_46 -> V_44 )
V_134 += V_46 -> V_49 ;
} else if ( ! V_19 || ! V_19 -> V_68 ) {
V_134 = 0 ;
} else {
V_134 = F_9 ( V_19 -> V_16 + V_28 ) ;
}
F_60 ( & V_63 -> V_10 . V_84 , V_99 ) ;
F_68 ( V_133 , V_134 ) ;
return V_92 ;
}
static void F_69 ( struct V_2 * V_3 )
{
struct V_5 * V_15 = F_2 ( V_3 -> V_1 ) ;
struct V_9 * V_63 = F_4 ( V_3 ) ;
unsigned long V_99 ;
F_58 ( & V_63 -> V_10 . V_84 , V_99 ) ;
if ( F_70 ( & V_63 -> V_10 ) ) {
F_39 ( & V_15 -> V_84 ) ;
if ( ! V_63 -> V_69 && F_34 ( & V_63 -> V_75 ) ) {
F_59 ( & V_63 -> V_75 , & V_15 -> V_87 ) ;
F_43 ( & V_15 -> V_96 ) ;
F_7 ( F_1 ( V_3 ) , L_31 ,
& V_63 -> V_10 ) ;
}
F_41 ( & V_15 -> V_84 ) ;
} else {
F_7 ( F_1 ( V_3 ) , L_32 ,
& V_63 -> V_10 ) ;
}
F_60 ( & V_63 -> V_10 . V_84 , V_99 ) ;
}
static void F_71 ( struct V_2 * V_3 )
{
struct V_5 * V_15 = F_2 ( V_3 -> V_1 ) ;
struct V_9 * V_63 = F_4 ( V_3 ) ;
unsigned long V_99 ;
F_58 ( & V_15 -> V_84 , V_99 ) ;
F_36 ( & V_63 -> V_75 ) ;
F_60 ( & V_15 -> V_84 , V_99 ) ;
F_72 ( & V_63 -> V_10 ) ;
}
static struct V_2 * F_73 ( struct V_136 * V_137 ,
struct V_138 * V_139 )
{
struct V_5 * V_15 = V_139 -> V_140 ;
struct V_9 * V_63 ;
struct V_2 * V_3 ;
T_5 V_122 = V_137 -> args [ 0 ] ;
if ( V_122 > V_15 -> V_60 -> V_141 )
return NULL ;
V_3 = F_74 ( & V_15 -> V_8 ) ;
if ( ! V_3 )
return NULL ;
V_63 = F_4 ( V_3 ) ;
V_63 -> V_122 = V_122 ;
return V_3 ;
}
static inline void F_75 ( struct V_5 * V_15 )
{
F_29 ( 0 , V_15 -> V_16 + F_8 ( 0 ) ) ;
F_29 ( 0 , V_15 -> V_16 + F_8 ( 1 ) ) ;
F_76 ( & V_15 -> V_95 ) ;
F_77 ( V_15 -> V_8 . V_4 , V_15 -> V_88 , V_15 ) ;
F_78 ( & V_15 -> V_96 ) ;
}
static inline void F_79 ( struct V_5 * V_15 )
{
int V_90 ;
for ( V_90 = 0 ; V_90 < V_15 -> V_60 -> V_142 ; V_90 ++ ) {
struct V_9 * V_63 = & V_15 -> V_143 [ V_90 ] ;
F_28 ( & V_63 -> V_10 . V_3 . V_144 ) ;
F_78 ( & V_63 -> V_10 . V_96 ) ;
}
}
static int F_80 ( struct V_145 * V_146 )
{
const struct V_147 * V_1 ;
struct V_5 * V_148 ;
struct V_149 * V_150 ;
int V_92 , V_90 ;
V_148 = F_81 ( & V_146 -> V_4 , sizeof( * V_148 ) , V_151 ) ;
if ( ! V_148 )
return - V_152 ;
V_1 = F_82 ( V_153 , & V_146 -> V_4 ) ;
if ( ! V_1 )
return - V_154 ;
V_148 -> V_60 = V_1 -> V_80 ;
V_150 = F_83 ( V_146 , V_155 , 0 ) ;
V_148 -> V_16 = F_84 ( & V_146 -> V_4 , V_150 ) ;
if ( F_85 ( V_148 -> V_16 ) )
return F_86 ( V_148 -> V_16 ) ;
V_148 -> V_88 = F_87 ( V_146 , 0 ) ;
if ( V_148 -> V_88 < 0 ) {
F_47 ( & V_146 -> V_4 , L_33 ) ;
return V_148 -> V_88 ;
}
V_148 -> V_156 = F_88 ( & V_146 -> V_4 , NULL ) ;
if ( F_85 ( V_148 -> V_156 ) ) {
F_47 ( & V_146 -> V_4 , L_34 ) ;
return F_86 ( V_148 -> V_156 ) ;
}
V_148 -> V_157 = F_89 ( & V_146 -> V_4 , NULL ) ;
if ( F_85 ( V_148 -> V_157 ) ) {
F_47 ( & V_146 -> V_4 , L_35 ) ;
return F_86 ( V_148 -> V_157 ) ;
}
V_148 -> V_67 = F_90 ( F_91 ( & V_146 -> V_4 ) , & V_146 -> V_4 ,
sizeof( struct V_36 ) , 4 , 0 ) ;
if ( ! V_148 -> V_67 ) {
F_47 ( & V_146 -> V_4 , L_36 ) ;
return - V_152 ;
}
F_92 ( V_146 , V_148 ) ;
F_93 ( & V_148 -> V_87 ) ;
F_94 ( & V_148 -> V_84 ) ;
F_95 ( V_158 , V_148 -> V_8 . V_159 ) ;
F_95 ( V_160 , V_148 -> V_8 . V_159 ) ;
F_95 ( V_161 , V_148 -> V_8 . V_159 ) ;
F_93 ( & V_148 -> V_8 . V_162 ) ;
V_148 -> V_8 . V_163 = F_71 ;
V_148 -> V_8 . V_164 = F_65 ;
V_148 -> V_8 . V_165 = F_69 ;
V_148 -> V_8 . V_166 = F_51 ;
V_148 -> V_8 . V_167 = F_44 ;
V_148 -> V_8 . V_168 = V_169 ;
V_148 -> V_8 . V_170 = V_81 ;
V_148 -> V_8 . V_171 = F_56 ;
V_148 -> V_8 . V_172 = F_57 ;
V_148 -> V_8 . V_173 = F_61 ;
V_148 -> V_8 . V_174 = F_37 ( V_34 ) |
F_37 ( V_175 ) |
F_37 ( V_35 ) ;
V_148 -> V_8 . V_176 = F_37 ( V_34 ) |
F_37 ( V_175 ) |
F_37 ( V_35 ) ;
V_148 -> V_8 . V_177 = F_37 ( V_178 ) |
F_37 ( V_118 ) ;
V_148 -> V_8 . V_179 = V_180 ;
V_148 -> V_8 . V_4 = & V_146 -> V_4 ;
V_148 -> V_86 = F_96 ( & V_146 -> V_4 , V_148 -> V_60 -> V_85 ,
sizeof( struct V_18 ) , V_151 ) ;
if ( ! V_148 -> V_86 )
return - V_152 ;
V_148 -> V_143 = F_96 ( & V_146 -> V_4 , V_148 -> V_60 -> V_142 ,
sizeof( struct V_9 ) , V_151 ) ;
if ( ! V_148 -> V_143 )
return - V_152 ;
F_97 ( & V_148 -> V_96 , F_30 , ( unsigned long ) V_148 ) ;
for ( V_90 = 0 ; V_90 < V_148 -> V_60 -> V_85 ; V_90 ++ ) {
struct V_18 * V_19 = & V_148 -> V_86 [ V_90 ] ;
V_19 -> V_21 = V_90 ;
V_19 -> V_16 = V_148 -> V_16 + 0x100 + V_90 * 0x40 ;
}
for ( V_90 = 0 ; V_90 < V_148 -> V_60 -> V_142 ; V_90 ++ ) {
struct V_9 * V_63 = & V_148 -> V_143 [ V_90 ] ;
F_93 ( & V_63 -> V_75 ) ;
V_63 -> V_10 . V_181 = F_22 ;
F_98 ( & V_63 -> V_10 , & V_148 -> V_8 ) ;
}
V_92 = F_99 ( V_148 -> V_157 ) ;
if ( V_92 ) {
F_47 ( & V_146 -> V_4 , L_37 ) ;
goto V_182;
}
V_92 = F_100 ( V_148 -> V_156 ) ;
if ( V_92 ) {
F_47 ( & V_146 -> V_4 , L_38 ) ;
goto V_183;
}
V_92 = F_101 ( & V_146 -> V_4 , V_148 -> V_88 , F_38 , 0 ,
F_91 ( & V_146 -> V_4 ) , V_148 ) ;
if ( V_92 ) {
F_47 ( & V_146 -> V_4 , L_39 ) ;
goto V_184;
}
V_92 = F_102 ( & V_148 -> V_8 ) ;
if ( V_92 ) {
F_103 ( & V_146 -> V_4 , L_40 ) ;
goto V_185;
}
V_92 = F_104 ( V_146 -> V_4 . V_186 , F_73 ,
V_148 ) ;
if ( V_92 ) {
F_47 ( & V_146 -> V_4 , L_41 ) ;
goto V_187;
}
if ( F_105 ( V_146 -> V_4 . V_186 ,
L_42 ) )
F_29 ( V_188 , V_148 -> V_16 + V_189 ) ;
return 0 ;
V_187:
F_106 ( & V_148 -> V_8 ) ;
V_185:
F_75 ( V_148 ) ;
V_184:
F_107 ( V_148 -> V_156 ) ;
V_183:
F_108 ( V_148 -> V_157 ) ;
V_182:
F_79 ( V_148 ) ;
return V_92 ;
}
static int F_109 ( struct V_145 * V_146 )
{
struct V_5 * V_148 = F_110 ( V_146 ) ;
F_111 ( V_146 -> V_4 . V_186 ) ;
F_106 ( & V_148 -> V_8 ) ;
F_75 ( V_148 ) ;
F_107 ( V_148 -> V_156 ) ;
F_108 ( V_148 -> V_157 ) ;
F_79 ( V_148 ) ;
return 0 ;
}
