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
struct V_18 * V_19 = V_63 -> V_68 ;
unsigned long V_69 ;
F_27 ( V_70 ) ;
F_28 ( & V_15 -> V_71 ) ;
F_29 ( & V_63 -> V_72 ) ;
F_30 ( & V_15 -> V_71 ) ;
F_31 ( & V_63 -> V_10 . V_71 , V_69 ) ;
F_32 ( & V_63 -> V_10 , & V_70 ) ;
if ( V_19 ) {
F_33 ( V_73 , V_19 -> V_16 + V_22 ) ;
F_33 ( V_74 , V_19 -> V_16 + V_23 ) ;
V_63 -> V_68 = NULL ;
V_19 -> V_63 = NULL ;
V_19 -> V_75 = NULL ;
V_19 -> V_76 = NULL ;
}
F_34 ( & V_63 -> V_10 . V_71 , V_69 ) ;
F_35 ( & V_63 -> V_10 , & V_70 ) ;
return 0 ;
}
static int F_36 ( struct V_9 * V_63 )
{
struct V_5 * V_15 = F_2 ( V_63 -> V_10 . V_3 . V_1 ) ;
struct V_64 * V_75 = F_37 ( & V_63 -> V_10 ) ;
struct V_18 * V_19 = V_63 -> V_68 ;
T_3 V_77 , V_78 , V_79 ;
if ( ! V_19 )
return - V_80 ;
if ( ! V_75 ) {
V_19 -> V_75 = NULL ;
V_19 -> V_76 = NULL ;
return - V_80 ;
}
F_38 ( & V_75 -> V_72 ) ;
V_19 -> V_75 = F_5 ( & V_75 -> V_13 ) ;
V_19 -> V_76 = NULL ;
F_21 ( V_63 , V_19 -> V_75 -> V_42 ) ;
V_78 = V_19 -> V_21 / V_81 ;
V_79 = V_19 -> V_21 % V_81 ;
V_77 = F_9 ( V_15 -> V_16 + F_8 ( V_79 ) ) ;
V_77 |= V_82 << ( V_79 * V_83 ) ;
F_33 ( V_77 , V_15 -> V_16 + F_8 ( V_79 ) ) ;
F_33 ( V_19 -> V_75 -> V_41 , V_19 -> V_16 + V_24 ) ;
F_33 ( V_84 , V_19 -> V_16 + V_22 ) ;
F_6 ( V_15 ) ;
F_11 ( V_15 , V_19 ) ;
return 0 ;
}
static void F_39 ( unsigned long V_85 )
{
struct V_5 * V_15 = (struct V_5 * ) V_85 ;
const struct V_86 * V_60 = V_15 -> V_60 ;
struct V_9 * V_63 ;
struct V_18 * V_19 ;
unsigned int V_87 = 0 ;
unsigned int V_88 ;
F_40 (vchan, &sdev->slave.channels, vc.chan.device_node) {
F_41 ( & V_63 -> V_10 . V_71 ) ;
V_19 = V_63 -> V_68 ;
if ( V_19 && V_19 -> V_76 ) {
if ( F_36 ( V_63 ) ) {
F_7 ( V_15 -> V_8 . V_4 , L_19 ,
V_19 -> V_21 ) ;
V_63 -> V_68 = NULL ;
V_19 -> V_63 = NULL ;
}
}
F_42 ( & V_63 -> V_10 . V_71 ) ;
}
F_41 ( & V_15 -> V_71 ) ;
for ( V_88 = 0 ; V_88 < V_60 -> V_89 ; V_88 ++ ) {
V_19 = & V_15 -> V_90 [ V_88 ] ;
if ( V_19 -> V_63 || F_43 ( & V_15 -> V_91 ) )
continue;
V_63 = F_44 ( & V_15 -> V_91 ,
struct V_9 , V_72 ) ;
F_29 ( & V_63 -> V_72 ) ;
V_87 |= F_45 ( V_88 ) ;
V_19 -> V_63 = V_63 ;
V_63 -> V_68 = V_19 ;
F_7 ( V_15 -> V_8 . V_4 , L_20 ,
V_19 -> V_21 , & V_63 -> V_10 ) ;
}
F_42 ( & V_15 -> V_71 ) ;
for ( V_88 = 0 ; V_88 < V_60 -> V_89 ; V_88 ++ ) {
if ( ! ( V_87 & F_45 ( V_88 ) ) )
continue;
V_19 = V_15 -> V_90 + V_88 ;
V_63 = V_19 -> V_63 ;
if ( V_63 ) {
F_41 ( & V_63 -> V_10 . V_71 ) ;
F_36 ( V_63 ) ;
F_42 ( & V_63 -> V_10 . V_71 ) ;
}
}
}
static T_6 F_46 ( int V_92 , void * V_93 )
{
struct V_5 * V_15 = V_93 ;
struct V_9 * V_63 ;
struct V_18 * V_19 ;
int V_94 , V_95 , V_96 = V_97 ;
T_3 V_98 ;
for ( V_94 = 0 ; V_94 < V_15 -> V_60 -> V_89 / V_81 ; V_94 ++ ) {
V_98 = F_9 ( V_15 -> V_16 + F_10 ( V_94 ) ) ;
if ( ! V_98 )
continue;
F_7 ( V_15 -> V_8 . V_4 , L_21 ,
V_94 ? L_22 : L_23 , V_98 ) ;
F_33 ( V_98 , V_15 -> V_16 + F_10 ( V_94 ) ) ;
for ( V_95 = 0 ; ( V_95 < V_81 ) && V_98 ; V_95 ++ ) {
if ( V_98 & V_82 ) {
V_19 = V_15 -> V_90 + V_95 ;
V_63 = V_19 -> V_63 ;
if ( V_63 ) {
F_28 ( & V_63 -> V_10 . V_71 ) ;
F_47 ( & V_19 -> V_75 -> V_14 ) ;
V_19 -> V_76 = V_19 -> V_75 ;
F_30 ( & V_63 -> V_10 . V_71 ) ;
}
}
V_98 = V_98 >> V_83 ;
}
if ( ! F_48 ( & V_15 -> V_99 ) )
F_49 ( & V_15 -> V_100 ) ;
V_96 = V_101 ;
}
return V_96 ;
}
static struct V_12 * F_50 (
struct V_2 * V_3 , T_4 V_102 , T_4 V_47 ,
T_7 V_49 , unsigned long V_69 )
{
struct V_5 * V_15 = F_2 ( V_3 -> V_1 ) ;
struct V_9 * V_63 = F_4 ( V_3 ) ;
struct V_36 * V_42 ;
struct V_11 * V_40 ;
T_4 V_41 ;
T_2 V_103 , V_104 ;
F_7 ( F_1 ( V_3 ) ,
L_24 ,
V_105 , V_63 -> V_10 . V_3 . V_106 , & V_102 , & V_47 , V_49 , V_69 ) ;
if ( ! V_49 )
return NULL ;
V_40 = F_51 ( sizeof( * V_40 ) , V_107 ) ;
if ( ! V_40 )
return NULL ;
V_42 = F_52 ( V_15 -> V_67 , V_107 , & V_41 ) ;
if ( ! V_42 ) {
F_53 ( V_15 -> V_8 . V_4 , L_25 ) ;
goto V_108;
}
V_42 -> V_47 = V_47 ;
V_42 -> V_48 = V_102 ;
V_42 -> V_49 = V_49 ;
V_42 -> V_61 = V_62 ;
V_103 = F_13 ( 8 ) ;
V_104 = F_14 ( V_35 ) ;
V_42 -> V_60 |= F_54 ( V_109 ) |
F_55 ( V_109 ) |
V_110 |
V_111 |
F_17 ( V_103 ) |
F_18 ( V_104 ) |
F_19 ( V_103 ) |
F_20 ( V_104 ) ;
F_15 ( NULL , V_42 , V_41 , V_40 ) ;
F_21 ( V_63 , V_42 ) ;
return F_56 ( & V_63 -> V_10 , & V_40 -> V_14 , V_69 ) ;
V_108:
F_25 ( V_40 ) ;
return NULL ;
}
static struct V_12 * F_57 (
struct V_2 * V_3 , struct V_112 * V_113 ,
unsigned int V_114 , enum V_115 V_116 ,
unsigned long V_69 , void * V_117 )
{
struct V_5 * V_15 = F_2 ( V_3 -> V_1 ) ;
struct V_9 * V_63 = F_4 ( V_3 ) ;
struct V_50 * V_118 = & V_63 -> V_60 ;
struct V_36 * V_42 , * V_37 = NULL ;
struct V_11 * V_40 ;
struct V_112 * V_119 ;
T_4 V_41 ;
int V_94 , V_96 ;
if ( ! V_113 )
return NULL ;
if ( ! F_58 ( V_116 ) ) {
F_53 ( F_1 ( V_3 ) , L_26 ) ;
return NULL ;
}
V_40 = F_51 ( sizeof( * V_40 ) , V_107 ) ;
if ( ! V_40 )
return NULL ;
F_59 (sgl, sg, sg_len, i) {
V_42 = F_52 ( V_15 -> V_67 , V_107 , & V_41 ) ;
if ( ! V_42 )
goto V_120;
if ( V_116 == V_121 ) {
V_96 = F_16 ( V_42 , F_60 ( V_119 ) ,
V_118 -> V_122 , F_61 ( V_119 ) ,
V_118 ) ;
if ( V_96 )
goto V_123;
V_42 -> V_60 |= V_124 |
V_111 |
F_54 ( V_109 ) |
F_55 ( V_63 -> V_125 ) ;
F_7 ( F_1 ( V_3 ) ,
L_27 ,
V_105 , V_63 -> V_10 . V_3 . V_106 ,
& V_118 -> V_122 , & F_60 ( V_119 ) ,
F_61 ( V_119 ) , V_69 ) ;
} else {
V_96 = F_16 ( V_42 , V_118 -> V_126 ,
F_60 ( V_119 ) , F_61 ( V_119 ) ,
V_118 ) ;
if ( V_96 )
goto V_123;
V_42 -> V_60 |= V_110 |
V_127 |
F_55 ( V_109 ) |
F_54 ( V_63 -> V_125 ) ;
F_7 ( F_1 ( V_3 ) ,
L_27 ,
V_105 , V_63 -> V_10 . V_3 . V_106 ,
& F_60 ( V_119 ) , & V_118 -> V_126 ,
F_61 ( V_119 ) , V_69 ) ;
}
V_37 = F_15 ( V_37 , V_42 , V_41 , V_40 ) ;
}
F_7 ( F_1 ( V_3 ) , L_28 , & V_40 -> V_41 ) ;
for ( V_37 = V_40 -> V_42 ; V_37 ; V_37 = V_37 -> V_44 )
F_21 ( V_63 , V_37 ) ;
return F_56 ( & V_63 -> V_10 , & V_40 -> V_14 , V_69 ) ;
V_123:
F_24 ( V_15 -> V_67 , V_42 , V_41 ) ;
V_120:
for ( V_37 = V_40 -> V_42 ; V_37 ; V_37 = V_37 -> V_44 )
F_24 ( V_15 -> V_67 , V_37 , F_12 ( V_37 ) ) ;
F_25 ( V_40 ) ;
return NULL ;
}
static int F_62 ( struct V_2 * V_3 , enum V_128 V_129 ,
unsigned long V_130 )
{
struct V_5 * V_15 = F_2 ( V_3 -> V_1 ) ;
struct V_9 * V_63 = F_4 ( V_3 ) ;
struct V_18 * V_19 = V_63 -> V_68 ;
unsigned long V_69 ;
int V_96 = 0 ;
switch ( V_129 ) {
case V_131 :
F_7 ( F_1 ( V_3 ) , L_29 , & V_63 -> V_10 ) ;
F_31 ( & V_63 -> V_10 . V_71 , V_69 ) ;
if ( V_19 ) {
F_33 ( V_74 ,
V_19 -> V_16 + V_23 ) ;
} else if ( ! F_43 ( & V_63 -> V_10 . V_132 ) ) {
F_28 ( & V_15 -> V_71 ) ;
F_63 ( & V_63 -> V_72 , & V_15 -> V_91 ) ;
F_30 ( & V_15 -> V_71 ) ;
}
F_34 ( & V_63 -> V_10 . V_71 , V_69 ) ;
break;
case V_133 :
F_7 ( F_1 ( V_3 ) , L_30 , & V_63 -> V_10 ) ;
if ( V_19 ) {
F_33 ( V_134 ,
V_19 -> V_16 + V_23 ) ;
} else {
F_28 ( & V_15 -> V_71 ) ;
F_29 ( & V_63 -> V_72 ) ;
F_30 ( & V_15 -> V_71 ) ;
}
break;
case V_135 :
V_96 = F_26 ( V_63 ) ;
break;
case V_136 :
memcpy ( & V_63 -> V_60 , ( void * ) V_130 , sizeof( struct V_50 ) ) ;
break;
default:
V_96 = - V_137 ;
break;
}
return V_96 ;
}
static enum V_138 F_64 ( struct V_2 * V_3 ,
T_8 V_139 ,
struct V_140 * V_141 )
{
struct V_9 * V_63 = F_4 ( V_3 ) ;
struct V_18 * V_19 = V_63 -> V_68 ;
struct V_36 * V_46 ;
struct V_64 * V_14 ;
struct V_11 * V_40 ;
enum V_138 V_96 ;
unsigned long V_69 ;
T_7 V_142 = 0 ;
V_96 = F_65 ( V_3 , V_139 , V_141 ) ;
if ( V_96 == V_143 )
return V_96 ;
F_31 ( & V_63 -> V_10 . V_71 , V_69 ) ;
V_14 = F_66 ( & V_63 -> V_10 , V_139 ) ;
V_40 = F_5 ( & V_14 -> V_13 ) ;
if ( V_14 ) {
for ( V_46 = V_40 -> V_42 ; V_46 != NULL ; V_46 = V_46 -> V_44 )
V_142 += V_46 -> V_49 ;
} else if ( ! V_19 || ! V_19 -> V_75 ) {
V_142 = 0 ;
} else {
V_142 = F_9 ( V_19 -> V_16 + V_28 ) ;
}
F_34 ( & V_63 -> V_10 . V_71 , V_69 ) ;
F_67 ( V_141 , V_142 ) ;
return V_96 ;
}
static void F_68 ( struct V_2 * V_3 )
{
struct V_5 * V_15 = F_2 ( V_3 -> V_1 ) ;
struct V_9 * V_63 = F_4 ( V_3 ) ;
unsigned long V_69 ;
F_31 ( & V_63 -> V_10 . V_71 , V_69 ) ;
if ( F_69 ( & V_63 -> V_10 ) ) {
F_28 ( & V_15 -> V_71 ) ;
if ( ! V_63 -> V_68 && F_43 ( & V_63 -> V_72 ) ) {
F_63 ( & V_63 -> V_72 , & V_15 -> V_91 ) ;
F_49 ( & V_15 -> V_100 ) ;
F_7 ( F_1 ( V_3 ) , L_31 ,
& V_63 -> V_10 ) ;
}
F_30 ( & V_15 -> V_71 ) ;
} else {
F_7 ( F_1 ( V_3 ) , L_32 ,
& V_63 -> V_10 ) ;
}
F_34 ( & V_63 -> V_10 . V_71 , V_69 ) ;
}
static int F_70 ( struct V_2 * V_3 )
{
return 0 ;
}
static void F_71 ( struct V_2 * V_3 )
{
struct V_5 * V_15 = F_2 ( V_3 -> V_1 ) ;
struct V_9 * V_63 = F_4 ( V_3 ) ;
unsigned long V_69 ;
F_31 ( & V_15 -> V_71 , V_69 ) ;
F_29 ( & V_63 -> V_72 ) ;
F_34 ( & V_15 -> V_71 , V_69 ) ;
F_72 ( & V_63 -> V_10 ) ;
}
static struct V_2 * F_73 ( struct V_144 * V_145 ,
struct V_146 * V_147 )
{
struct V_5 * V_15 = V_147 -> V_148 ;
struct V_9 * V_63 ;
struct V_2 * V_3 ;
T_5 V_125 = V_145 -> args [ 0 ] ;
if ( V_125 > V_15 -> V_60 -> V_149 )
return NULL ;
V_3 = F_74 ( & V_15 -> V_8 ) ;
if ( ! V_3 )
return NULL ;
V_63 = F_4 ( V_3 ) ;
V_63 -> V_125 = V_125 ;
return V_3 ;
}
static inline void F_75 ( struct V_5 * V_15 )
{
F_33 ( 0 , V_15 -> V_16 + F_8 ( 0 ) ) ;
F_33 ( 0 , V_15 -> V_16 + F_8 ( 1 ) ) ;
F_76 ( & V_15 -> V_99 ) ;
F_77 ( V_15 -> V_8 . V_4 , V_15 -> V_92 , V_15 ) ;
F_78 ( & V_15 -> V_100 ) ;
}
static inline void F_79 ( struct V_5 * V_15 )
{
int V_94 ;
for ( V_94 = 0 ; V_94 < V_15 -> V_60 -> V_150 ; V_94 ++ ) {
struct V_9 * V_63 = & V_15 -> V_151 [ V_94 ] ;
F_38 ( & V_63 -> V_10 . V_3 . V_152 ) ;
F_78 ( & V_63 -> V_10 . V_100 ) ;
}
}
static int F_80 ( struct V_153 * V_154 )
{
const struct V_155 * V_1 ;
struct V_5 * V_156 ;
struct V_157 * V_158 ;
int V_96 , V_94 ;
V_156 = F_81 ( & V_154 -> V_4 , sizeof( * V_156 ) , V_159 ) ;
if ( ! V_156 )
return - V_160 ;
V_1 = F_82 ( V_161 , & V_154 -> V_4 ) ;
if ( ! V_1 )
return - V_162 ;
V_156 -> V_60 = V_1 -> V_85 ;
V_158 = F_83 ( V_154 , V_163 , 0 ) ;
V_156 -> V_16 = F_84 ( & V_154 -> V_4 , V_158 ) ;
if ( F_85 ( V_156 -> V_16 ) )
return F_86 ( V_156 -> V_16 ) ;
V_156 -> V_92 = F_87 ( V_154 , 0 ) ;
if ( V_156 -> V_92 < 0 ) {
F_53 ( & V_154 -> V_4 , L_33 ) ;
return V_156 -> V_92 ;
}
V_156 -> V_164 = F_88 ( & V_154 -> V_4 , NULL ) ;
if ( F_85 ( V_156 -> V_164 ) ) {
F_53 ( & V_154 -> V_4 , L_34 ) ;
return F_86 ( V_156 -> V_164 ) ;
}
V_156 -> V_165 = F_89 ( & V_154 -> V_4 , NULL ) ;
if ( F_85 ( V_156 -> V_165 ) ) {
F_53 ( & V_154 -> V_4 , L_35 ) ;
return F_86 ( V_156 -> V_165 ) ;
}
V_156 -> V_67 = F_90 ( F_91 ( & V_154 -> V_4 ) , & V_154 -> V_4 ,
sizeof( struct V_36 ) , 4 , 0 ) ;
if ( ! V_156 -> V_67 ) {
F_53 ( & V_154 -> V_4 , L_36 ) ;
return - V_160 ;
}
F_92 ( V_154 , V_156 ) ;
F_93 ( & V_156 -> V_91 ) ;
F_94 ( & V_156 -> V_71 ) ;
F_95 ( V_166 , V_156 -> V_8 . V_167 ) ;
F_95 ( V_168 , V_156 -> V_8 . V_167 ) ;
F_95 ( V_169 , V_156 -> V_8 . V_167 ) ;
F_93 ( & V_156 -> V_8 . V_170 ) ;
V_156 -> V_8 . V_171 = F_70 ;
V_156 -> V_8 . V_172 = F_71 ;
V_156 -> V_8 . V_173 = F_64 ;
V_156 -> V_8 . V_174 = F_68 ;
V_156 -> V_8 . V_175 = F_57 ;
V_156 -> V_8 . V_176 = F_50 ;
V_156 -> V_8 . V_177 = F_62 ;
V_156 -> V_8 . V_178 = 4 ;
V_156 -> V_8 . V_4 = & V_154 -> V_4 ;
V_156 -> V_90 = F_96 ( & V_154 -> V_4 , V_156 -> V_60 -> V_89 ,
sizeof( struct V_18 ) , V_159 ) ;
if ( ! V_156 -> V_90 )
return - V_160 ;
V_156 -> V_151 = F_96 ( & V_154 -> V_4 , V_156 -> V_60 -> V_150 ,
sizeof( struct V_9 ) , V_159 ) ;
if ( ! V_156 -> V_151 )
return - V_160 ;
F_97 ( & V_156 -> V_100 , F_39 , ( unsigned long ) V_156 ) ;
for ( V_94 = 0 ; V_94 < V_156 -> V_60 -> V_89 ; V_94 ++ ) {
struct V_18 * V_19 = & V_156 -> V_90 [ V_94 ] ;
V_19 -> V_21 = V_94 ;
V_19 -> V_16 = V_156 -> V_16 + 0x100 + V_94 * 0x40 ;
}
for ( V_94 = 0 ; V_94 < V_156 -> V_60 -> V_150 ; V_94 ++ ) {
struct V_9 * V_63 = & V_156 -> V_151 [ V_94 ] ;
F_93 ( & V_63 -> V_72 ) ;
V_63 -> V_10 . V_179 = F_22 ;
F_98 ( & V_63 -> V_10 , & V_156 -> V_8 ) ;
}
V_96 = F_99 ( V_156 -> V_165 ) ;
if ( V_96 ) {
F_53 ( & V_154 -> V_4 , L_37 ) ;
goto V_180;
}
V_96 = F_100 ( V_156 -> V_164 ) ;
if ( V_96 ) {
F_53 ( & V_154 -> V_4 , L_38 ) ;
goto V_181;
}
V_96 = F_101 ( & V_154 -> V_4 , V_156 -> V_92 , F_46 , 0 ,
F_91 ( & V_154 -> V_4 ) , V_156 ) ;
if ( V_96 ) {
F_53 ( & V_154 -> V_4 , L_39 ) ;
goto V_182;
}
V_96 = F_102 ( & V_156 -> V_8 ) ;
if ( V_96 ) {
F_103 ( & V_154 -> V_4 , L_40 ) ;
goto V_183;
}
V_96 = F_104 ( V_154 -> V_4 . V_184 , F_73 ,
V_156 ) ;
if ( V_96 ) {
F_53 ( & V_154 -> V_4 , L_41 ) ;
goto V_185;
}
if ( F_105 ( V_154 -> V_4 . V_184 ,
L_42 ) )
F_33 ( V_186 , V_156 -> V_16 + V_187 ) ;
return 0 ;
V_185:
F_106 ( & V_156 -> V_8 ) ;
V_183:
F_75 ( V_156 ) ;
V_182:
F_107 ( V_156 -> V_164 ) ;
V_181:
F_108 ( V_156 -> V_165 ) ;
V_180:
F_79 ( V_156 ) ;
return V_96 ;
}
static int F_109 ( struct V_153 * V_154 )
{
struct V_5 * V_156 = F_110 ( V_154 ) ;
F_111 ( V_154 -> V_4 . V_184 ) ;
F_106 ( & V_156 -> V_8 ) ;
F_75 ( V_156 ) ;
F_107 ( V_156 -> V_164 ) ;
F_108 ( V_156 -> V_165 ) ;
F_79 ( V_156 ) ;
return 0 ;
}
