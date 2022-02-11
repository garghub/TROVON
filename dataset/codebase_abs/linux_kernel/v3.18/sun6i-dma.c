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
struct V_9 * V_63 ;
struct V_18 * V_19 ;
unsigned int V_86 = 0 ;
unsigned int V_87 ;
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
for ( V_87 = 0 ; V_87 < V_88 ; V_87 ++ ) {
V_19 = & V_15 -> V_89 [ V_87 ] ;
if ( V_19 -> V_63 || F_43 ( & V_15 -> V_90 ) )
continue;
V_63 = F_44 ( & V_15 -> V_90 ,
struct V_9 , V_72 ) ;
F_29 ( & V_63 -> V_72 ) ;
V_86 |= F_45 ( V_87 ) ;
V_19 -> V_63 = V_63 ;
V_63 -> V_68 = V_19 ;
F_7 ( V_15 -> V_8 . V_4 , L_20 ,
V_19 -> V_21 , & V_63 -> V_10 ) ;
}
F_42 ( & V_15 -> V_71 ) ;
for ( V_87 = 0 ; V_87 < V_88 ; V_87 ++ ) {
if ( ! ( V_86 & F_45 ( V_87 ) ) )
continue;
V_19 = V_15 -> V_89 + V_87 ;
V_63 = V_19 -> V_63 ;
if ( V_63 ) {
F_41 ( & V_63 -> V_10 . V_71 ) ;
F_36 ( V_63 ) ;
F_42 ( & V_63 -> V_10 . V_71 ) ;
}
}
}
static T_6 F_46 ( int V_91 , void * V_92 )
{
struct V_5 * V_15 = V_92 ;
struct V_9 * V_63 ;
struct V_18 * V_19 ;
int V_93 , V_94 , V_95 = V_96 ;
T_3 V_97 ;
for ( V_93 = 0 ; V_93 < 2 ; V_93 ++ ) {
V_97 = F_9 ( V_15 -> V_16 + F_10 ( V_93 ) ) ;
if ( ! V_97 )
continue;
F_7 ( V_15 -> V_8 . V_4 , L_21 ,
V_93 ? L_22 : L_23 , V_97 ) ;
F_33 ( V_97 , V_15 -> V_16 + F_10 ( V_93 ) ) ;
for ( V_94 = 0 ; ( V_94 < 8 ) && V_97 ; V_94 ++ ) {
if ( V_97 & V_82 ) {
V_19 = V_15 -> V_89 + V_94 ;
V_63 = V_19 -> V_63 ;
if ( V_63 ) {
F_28 ( & V_63 -> V_10 . V_71 ) ;
F_47 ( & V_19 -> V_75 -> V_14 ) ;
V_19 -> V_76 = V_19 -> V_75 ;
F_30 ( & V_63 -> V_10 . V_71 ) ;
}
}
V_97 = V_97 >> 4 ;
}
if ( ! F_48 ( & V_15 -> V_98 ) )
F_49 ( & V_15 -> V_99 ) ;
V_95 = V_100 ;
}
return V_95 ;
}
static struct V_12 * F_50 (
struct V_2 * V_3 , T_4 V_101 , T_4 V_47 ,
T_7 V_49 , unsigned long V_69 )
{
struct V_5 * V_15 = F_2 ( V_3 -> V_1 ) ;
struct V_9 * V_63 = F_4 ( V_3 ) ;
struct V_36 * V_42 ;
struct V_11 * V_40 ;
T_4 V_41 ;
T_2 V_102 , V_103 ;
F_7 ( F_1 ( V_3 ) ,
L_24 ,
V_104 , V_63 -> V_10 . V_3 . V_105 , & V_101 , & V_47 , V_49 , V_69 ) ;
if ( ! V_49 )
return NULL ;
V_40 = F_51 ( sizeof( * V_40 ) , V_106 ) ;
if ( ! V_40 )
return NULL ;
V_42 = F_52 ( V_15 -> V_67 , V_106 , & V_41 ) ;
if ( ! V_42 ) {
F_53 ( V_15 -> V_8 . V_4 , L_25 ) ;
goto V_107;
}
V_42 -> V_47 = V_47 ;
V_42 -> V_48 = V_101 ;
V_42 -> V_49 = V_49 ;
V_42 -> V_61 = V_62 ;
V_102 = F_13 ( 8 ) ;
V_103 = F_14 ( V_35 ) ;
V_42 -> V_60 |= F_54 ( V_108 ) |
F_55 ( V_108 ) |
V_109 |
V_110 |
F_17 ( V_102 ) |
F_18 ( V_103 ) |
F_19 ( V_102 ) |
F_20 ( V_103 ) ;
F_15 ( NULL , V_42 , V_41 , V_40 ) ;
F_21 ( V_63 , V_42 ) ;
return F_56 ( & V_63 -> V_10 , & V_40 -> V_14 , V_69 ) ;
V_107:
F_25 ( V_40 ) ;
return NULL ;
}
static struct V_12 * F_57 (
struct V_2 * V_3 , struct V_111 * V_112 ,
unsigned int V_113 , enum V_114 V_115 ,
unsigned long V_69 , void * V_116 )
{
struct V_5 * V_15 = F_2 ( V_3 -> V_1 ) ;
struct V_9 * V_63 = F_4 ( V_3 ) ;
struct V_50 * V_117 = & V_63 -> V_60 ;
struct V_36 * V_42 , * V_37 = NULL ;
struct V_11 * V_40 ;
struct V_111 * V_118 ;
T_4 V_41 ;
int V_93 , V_95 ;
if ( ! V_112 )
return NULL ;
if ( ! F_58 ( V_115 ) ) {
F_53 ( F_1 ( V_3 ) , L_26 ) ;
return NULL ;
}
V_40 = F_51 ( sizeof( * V_40 ) , V_106 ) ;
if ( ! V_40 )
return NULL ;
F_59 (sgl, sg, sg_len, i) {
V_42 = F_52 ( V_15 -> V_67 , V_106 , & V_41 ) ;
if ( ! V_42 )
goto V_119;
if ( V_115 == V_120 ) {
V_95 = F_16 ( V_42 , F_60 ( V_118 ) ,
V_117 -> V_121 , F_61 ( V_118 ) ,
V_117 ) ;
if ( V_95 )
goto V_122;
V_42 -> V_60 |= V_123 |
V_110 |
F_54 ( V_108 ) |
F_55 ( V_63 -> V_124 ) ;
F_7 ( F_1 ( V_3 ) ,
L_27 ,
V_104 , V_63 -> V_10 . V_3 . V_105 ,
& V_117 -> V_121 , & F_60 ( V_118 ) ,
F_61 ( V_118 ) , V_69 ) ;
} else {
V_95 = F_16 ( V_42 , V_117 -> V_125 ,
F_60 ( V_118 ) , F_61 ( V_118 ) ,
V_117 ) ;
if ( V_95 )
goto V_122;
V_42 -> V_60 |= V_109 |
V_126 |
F_55 ( V_108 ) |
F_54 ( V_63 -> V_124 ) ;
F_7 ( F_1 ( V_3 ) ,
L_27 ,
V_104 , V_63 -> V_10 . V_3 . V_105 ,
& F_60 ( V_118 ) , & V_117 -> V_125 ,
F_61 ( V_118 ) , V_69 ) ;
}
V_37 = F_15 ( V_37 , V_42 , V_41 , V_40 ) ;
}
F_7 ( F_1 ( V_3 ) , L_28 , & V_40 -> V_41 ) ;
for ( V_37 = V_40 -> V_42 ; V_37 ; V_37 = V_37 -> V_44 )
F_21 ( V_63 , V_37 ) ;
return F_56 ( & V_63 -> V_10 , & V_40 -> V_14 , V_69 ) ;
V_122:
F_24 ( V_15 -> V_67 , V_42 , V_41 ) ;
V_119:
for ( V_37 = V_40 -> V_42 ; V_37 ; V_37 = V_37 -> V_44 )
F_24 ( V_15 -> V_67 , V_37 , F_12 ( V_37 ) ) ;
F_25 ( V_40 ) ;
return NULL ;
}
static int F_62 ( struct V_2 * V_3 , enum V_127 V_128 ,
unsigned long V_129 )
{
struct V_5 * V_15 = F_2 ( V_3 -> V_1 ) ;
struct V_9 * V_63 = F_4 ( V_3 ) ;
struct V_18 * V_19 = V_63 -> V_68 ;
unsigned long V_69 ;
int V_95 = 0 ;
switch ( V_128 ) {
case V_130 :
F_7 ( F_1 ( V_3 ) , L_29 , & V_63 -> V_10 ) ;
F_31 ( & V_63 -> V_10 . V_71 , V_69 ) ;
if ( V_19 ) {
F_33 ( V_74 ,
V_19 -> V_16 + V_23 ) ;
} else if ( ! F_43 ( & V_63 -> V_10 . V_131 ) ) {
F_28 ( & V_15 -> V_71 ) ;
F_63 ( & V_63 -> V_72 , & V_15 -> V_90 ) ;
F_30 ( & V_15 -> V_71 ) ;
}
F_34 ( & V_63 -> V_10 . V_71 , V_69 ) ;
break;
case V_132 :
F_7 ( F_1 ( V_3 ) , L_30 , & V_63 -> V_10 ) ;
if ( V_19 ) {
F_33 ( V_133 ,
V_19 -> V_16 + V_23 ) ;
} else {
F_28 ( & V_15 -> V_71 ) ;
F_29 ( & V_63 -> V_72 ) ;
F_30 ( & V_15 -> V_71 ) ;
}
break;
case V_134 :
V_95 = F_26 ( V_63 ) ;
break;
case V_135 :
memcpy ( & V_63 -> V_60 , ( void * ) V_129 , sizeof( struct V_50 ) ) ;
break;
default:
V_95 = - V_136 ;
break;
}
return V_95 ;
}
static enum V_137 F_64 ( struct V_2 * V_3 ,
T_8 V_138 ,
struct V_139 * V_140 )
{
struct V_9 * V_63 = F_4 ( V_3 ) ;
struct V_18 * V_19 = V_63 -> V_68 ;
struct V_36 * V_46 ;
struct V_64 * V_14 ;
struct V_11 * V_40 ;
enum V_137 V_95 ;
unsigned long V_69 ;
T_7 V_141 = 0 ;
V_95 = F_65 ( V_3 , V_138 , V_140 ) ;
if ( V_95 == V_142 )
return V_95 ;
F_31 ( & V_63 -> V_10 . V_71 , V_69 ) ;
V_14 = F_66 ( & V_63 -> V_10 , V_138 ) ;
V_40 = F_5 ( & V_14 -> V_13 ) ;
if ( V_14 ) {
for ( V_46 = V_40 -> V_42 ; V_46 != NULL ; V_46 = V_46 -> V_44 )
V_141 += V_46 -> V_49 ;
} else if ( ! V_19 || ! V_19 -> V_75 ) {
V_141 = 0 ;
} else {
V_141 = F_9 ( V_19 -> V_16 + V_28 ) ;
}
F_34 ( & V_63 -> V_10 . V_71 , V_69 ) ;
F_67 ( V_140 , V_141 ) ;
return V_95 ;
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
F_63 ( & V_63 -> V_72 , & V_15 -> V_90 ) ;
F_49 ( & V_15 -> V_99 ) ;
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
static struct V_2 * F_73 ( struct V_143 * V_144 ,
struct V_145 * V_146 )
{
struct V_5 * V_15 = V_146 -> V_147 ;
struct V_9 * V_63 ;
struct V_2 * V_3 ;
T_5 V_124 = V_144 -> args [ 0 ] ;
if ( V_124 > V_148 )
return NULL ;
V_3 = F_74 ( & V_15 -> V_8 ) ;
if ( ! V_3 )
return NULL ;
V_63 = F_4 ( V_3 ) ;
V_63 -> V_124 = V_124 ;
return V_3 ;
}
static inline void F_75 ( struct V_5 * V_15 )
{
F_33 ( 0 , V_15 -> V_16 + F_8 ( 0 ) ) ;
F_33 ( 0 , V_15 -> V_16 + F_8 ( 1 ) ) ;
F_76 ( & V_15 -> V_98 ) ;
F_77 ( V_15 -> V_8 . V_4 , V_15 -> V_91 , V_15 ) ;
F_78 ( & V_15 -> V_99 ) ;
}
static inline void F_79 ( struct V_5 * V_15 )
{
int V_93 ;
for ( V_93 = 0 ; V_93 < V_149 ; V_93 ++ ) {
struct V_9 * V_63 = & V_15 -> V_150 [ V_93 ] ;
F_38 ( & V_63 -> V_10 . V_3 . V_151 ) ;
F_78 ( & V_63 -> V_10 . V_99 ) ;
}
}
static int F_80 ( struct V_152 * V_153 )
{
struct V_5 * V_154 ;
struct V_155 * V_156 ;
int V_95 , V_93 ;
V_154 = F_81 ( & V_153 -> V_4 , sizeof( * V_154 ) , V_157 ) ;
if ( ! V_154 )
return - V_158 ;
V_156 = F_82 ( V_153 , V_159 , 0 ) ;
V_154 -> V_16 = F_83 ( & V_153 -> V_4 , V_156 ) ;
if ( F_84 ( V_154 -> V_16 ) )
return F_85 ( V_154 -> V_16 ) ;
V_154 -> V_91 = F_86 ( V_153 , 0 ) ;
if ( V_154 -> V_91 < 0 ) {
F_53 ( & V_153 -> V_4 , L_33 ) ;
return V_154 -> V_91 ;
}
V_154 -> V_160 = F_87 ( & V_153 -> V_4 , NULL ) ;
if ( F_84 ( V_154 -> V_160 ) ) {
F_53 ( & V_153 -> V_4 , L_34 ) ;
return F_85 ( V_154 -> V_160 ) ;
}
V_154 -> V_161 = F_88 ( & V_153 -> V_4 , NULL ) ;
if ( F_84 ( V_154 -> V_161 ) ) {
F_53 ( & V_153 -> V_4 , L_35 ) ;
return F_85 ( V_154 -> V_161 ) ;
}
V_154 -> V_67 = F_89 ( F_90 ( & V_153 -> V_4 ) , & V_153 -> V_4 ,
sizeof( struct V_36 ) , 4 , 0 ) ;
if ( ! V_154 -> V_67 ) {
F_53 ( & V_153 -> V_4 , L_36 ) ;
return - V_158 ;
}
F_91 ( V_153 , V_154 ) ;
F_92 ( & V_154 -> V_90 ) ;
F_93 ( & V_154 -> V_71 ) ;
F_94 ( V_162 , V_154 -> V_8 . V_163 ) ;
F_94 ( V_164 , V_154 -> V_8 . V_163 ) ;
F_94 ( V_165 , V_154 -> V_8 . V_163 ) ;
F_92 ( & V_154 -> V_8 . V_166 ) ;
V_154 -> V_8 . V_167 = F_70 ;
V_154 -> V_8 . V_168 = F_71 ;
V_154 -> V_8 . V_169 = F_64 ;
V_154 -> V_8 . V_170 = F_68 ;
V_154 -> V_8 . V_171 = F_57 ;
V_154 -> V_8 . V_172 = F_50 ;
V_154 -> V_8 . V_173 = F_62 ;
V_154 -> V_8 . V_174 = V_149 ;
V_154 -> V_8 . V_175 = 4 ;
V_154 -> V_8 . V_4 = & V_153 -> V_4 ;
V_154 -> V_89 = F_95 ( & V_153 -> V_4 , V_88 ,
sizeof( struct V_18 ) , V_157 ) ;
if ( ! V_154 -> V_89 )
return - V_158 ;
V_154 -> V_150 = F_95 ( & V_153 -> V_4 , V_149 ,
sizeof( struct V_9 ) , V_157 ) ;
if ( ! V_154 -> V_150 )
return - V_158 ;
F_96 ( & V_154 -> V_99 , F_39 , ( unsigned long ) V_154 ) ;
for ( V_93 = 0 ; V_93 < V_88 ; V_93 ++ ) {
struct V_18 * V_19 = & V_154 -> V_89 [ V_93 ] ;
V_19 -> V_21 = V_93 ;
V_19 -> V_16 = V_154 -> V_16 + 0x100 + V_93 * 0x40 ;
}
for ( V_93 = 0 ; V_93 < V_149 ; V_93 ++ ) {
struct V_9 * V_63 = & V_154 -> V_150 [ V_93 ] ;
F_92 ( & V_63 -> V_72 ) ;
V_63 -> V_10 . V_176 = F_22 ;
F_97 ( & V_63 -> V_10 , & V_154 -> V_8 ) ;
}
V_95 = F_98 ( V_154 -> V_161 ) ;
if ( V_95 ) {
F_53 ( & V_153 -> V_4 , L_37 ) ;
goto V_177;
}
V_95 = F_99 ( V_154 -> V_160 ) ;
if ( V_95 ) {
F_53 ( & V_153 -> V_4 , L_38 ) ;
goto V_178;
}
V_95 = F_100 ( & V_153 -> V_4 , V_154 -> V_91 , F_46 , 0 ,
F_90 ( & V_153 -> V_4 ) , V_154 ) ;
if ( V_95 ) {
F_53 ( & V_153 -> V_4 , L_39 ) ;
goto V_179;
}
V_95 = F_101 ( & V_154 -> V_8 ) ;
if ( V_95 ) {
F_102 ( & V_153 -> V_4 , L_40 ) ;
goto V_180;
}
V_95 = F_103 ( V_153 -> V_4 . V_181 , F_73 ,
V_154 ) ;
if ( V_95 ) {
F_53 ( & V_153 -> V_4 , L_41 ) ;
goto V_182;
}
return 0 ;
V_182:
F_104 ( & V_154 -> V_8 ) ;
V_180:
F_75 ( V_154 ) ;
V_179:
F_105 ( V_154 -> V_160 ) ;
V_178:
F_106 ( V_154 -> V_161 ) ;
V_177:
F_79 ( V_154 ) ;
return V_95 ;
}
static int F_107 ( struct V_152 * V_153 )
{
struct V_5 * V_154 = F_108 ( V_153 ) ;
F_109 ( V_153 -> V_4 . V_181 ) ;
F_104 ( & V_154 -> V_8 ) ;
F_75 ( V_154 ) ;
F_105 ( V_154 -> V_160 ) ;
F_106 ( V_154 -> V_161 ) ;
F_79 ( V_154 ) ;
return 0 ;
}
