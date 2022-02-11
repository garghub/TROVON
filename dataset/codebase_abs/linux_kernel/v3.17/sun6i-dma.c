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
static inline int F_13 ( T_2 V_30 , T_3 * V_31 )
{
switch ( V_30 ) {
case 1 :
* V_31 = 0 ;
break;
case 8 :
* V_31 = 2 ;
break;
default:
return - V_32 ;
}
return 0 ;
}
static inline int F_14 ( enum V_33 V_34 , T_3 * V_35 )
{
if ( ( V_34 < V_36 ) ||
( V_34 > V_37 ) )
return - V_32 ;
* V_35 = V_34 >> 1 ;
return 0 ;
}
static void * F_15 ( struct V_38 * V_39 ,
struct V_38 * V_40 ,
T_4 V_41 ,
struct V_11 * V_42 )
{
if ( ( ! V_39 && ! V_42 ) || ! V_40 )
return NULL ;
if ( ! V_39 ) {
V_42 -> V_43 = V_41 ;
V_42 -> V_44 = V_40 ;
} else {
V_39 -> V_45 = V_41 ;
V_39 -> V_46 = V_40 ;
}
V_40 -> V_45 = V_47 ;
V_40 -> V_46 = NULL ;
return V_40 ;
}
static inline int F_16 ( struct V_38 * V_48 ,
T_4 V_49 ,
T_4 V_50 , T_2 V_51 ,
struct V_52 * V_53 )
{
T_3 V_54 , V_55 , V_56 , V_57 ;
int V_58 ;
if ( ! V_53 )
return - V_32 ;
V_58 = F_13 ( V_53 -> V_59 , & V_56 ) ;
if ( V_58 )
return V_58 ;
V_58 = F_13 ( V_53 -> V_60 , & V_57 ) ;
if ( V_58 )
return V_58 ;
V_58 = F_14 ( V_53 -> V_61 , & V_54 ) ;
if ( V_58 )
return V_58 ;
V_58 = F_14 ( V_53 -> V_62 , & V_55 ) ;
if ( V_58 )
return V_58 ;
V_48 -> V_63 = F_17 ( V_56 ) |
F_18 ( V_54 ) |
F_19 ( V_57 ) |
F_20 ( V_55 ) ;
V_48 -> V_49 = V_49 ;
V_48 -> V_50 = V_50 ;
V_48 -> V_51 = V_51 ;
V_48 -> V_64 = V_65 ;
return 0 ;
}
static inline void F_21 ( struct V_9 * V_66 ,
struct V_38 * V_48 )
{
T_1 V_43 = F_12 ( V_48 ) ;
F_7 ( F_1 ( & V_66 -> V_10 . V_3 ) ,
L_16
L_17
L_18 ,
& V_43 , V_48 ,
V_48 -> V_63 , V_48 -> V_49 , V_48 -> V_50 ,
V_48 -> V_51 , V_48 -> V_64 , V_48 -> V_45 ) ;
}
static void F_22 ( struct V_67 * V_14 )
{
struct V_11 * V_42 = F_5 ( & V_14 -> V_13 ) ;
struct V_5 * V_15 = F_2 ( V_14 -> V_13 . V_3 -> V_1 ) ;
struct V_38 * V_44 , * V_68 ;
T_4 V_43 , V_69 ;
if ( F_23 ( ! V_42 ) )
return;
V_43 = V_42 -> V_43 ;
V_44 = V_42 -> V_44 ;
while ( V_44 ) {
V_68 = V_44 -> V_46 ;
V_69 = V_44 -> V_45 ;
F_24 ( V_15 -> V_70 , V_44 , V_43 ) ;
V_44 = V_68 ;
V_43 = V_69 ;
}
F_25 ( V_42 ) ;
}
static int F_26 ( struct V_9 * V_66 )
{
struct V_5 * V_15 = F_2 ( V_66 -> V_10 . V_3 . V_1 ) ;
struct V_18 * V_19 = V_66 -> V_71 ;
unsigned long V_72 ;
F_27 ( V_73 ) ;
F_28 ( & V_15 -> V_74 ) ;
F_29 ( & V_66 -> V_75 ) ;
F_30 ( & V_15 -> V_74 ) ;
F_31 ( & V_66 -> V_10 . V_74 , V_72 ) ;
F_32 ( & V_66 -> V_10 , & V_73 ) ;
if ( V_19 ) {
F_33 ( V_76 , V_19 -> V_16 + V_22 ) ;
F_33 ( V_77 , V_19 -> V_16 + V_23 ) ;
V_66 -> V_71 = NULL ;
V_19 -> V_66 = NULL ;
V_19 -> V_78 = NULL ;
V_19 -> V_79 = NULL ;
}
F_34 ( & V_66 -> V_10 . V_74 , V_72 ) ;
F_35 ( & V_66 -> V_10 , & V_73 ) ;
return 0 ;
}
static int F_36 ( struct V_9 * V_66 )
{
struct V_5 * V_15 = F_2 ( V_66 -> V_10 . V_3 . V_1 ) ;
struct V_67 * V_78 = F_37 ( & V_66 -> V_10 ) ;
struct V_18 * V_19 = V_66 -> V_71 ;
T_2 V_80 , V_81 , V_82 ;
if ( ! V_19 )
return - V_83 ;
if ( ! V_78 ) {
V_19 -> V_78 = NULL ;
V_19 -> V_79 = NULL ;
return - V_83 ;
}
F_38 ( & V_78 -> V_75 ) ;
V_19 -> V_78 = F_5 ( & V_78 -> V_13 ) ;
V_19 -> V_79 = NULL ;
F_21 ( V_66 , V_19 -> V_78 -> V_44 ) ;
V_81 = V_19 -> V_21 / V_84 ;
V_82 = V_19 -> V_21 % V_84 ;
V_80 = F_9 ( V_15 -> V_16 + F_8 ( V_82 ) ) ;
V_80 |= V_85 << ( V_82 * V_86 ) ;
F_33 ( V_80 , V_15 -> V_16 + F_8 ( V_82 ) ) ;
F_33 ( V_19 -> V_78 -> V_43 , V_19 -> V_16 + V_24 ) ;
F_33 ( V_87 , V_19 -> V_16 + V_22 ) ;
F_6 ( V_15 ) ;
F_11 ( V_15 , V_19 ) ;
return 0 ;
}
static void F_39 ( unsigned long V_88 )
{
struct V_5 * V_15 = (struct V_5 * ) V_88 ;
struct V_9 * V_66 ;
struct V_18 * V_19 ;
unsigned int V_89 = 0 ;
unsigned int V_90 ;
F_40 (vchan, &sdev->slave.channels, vc.chan.device_node) {
F_41 ( & V_66 -> V_10 . V_74 ) ;
V_19 = V_66 -> V_71 ;
if ( V_19 && V_19 -> V_79 ) {
if ( F_36 ( V_66 ) ) {
F_7 ( V_15 -> V_8 . V_4 , L_19 ,
V_19 -> V_21 ) ;
V_66 -> V_71 = NULL ;
V_19 -> V_66 = NULL ;
}
}
F_42 ( & V_66 -> V_10 . V_74 ) ;
}
F_41 ( & V_15 -> V_74 ) ;
for ( V_90 = 0 ; V_90 < V_91 ; V_90 ++ ) {
V_19 = & V_15 -> V_92 [ V_90 ] ;
if ( V_19 -> V_66 || F_43 ( & V_15 -> V_93 ) )
continue;
V_66 = F_44 ( & V_15 -> V_93 ,
struct V_9 , V_75 ) ;
F_29 ( & V_66 -> V_75 ) ;
V_89 |= F_45 ( V_90 ) ;
V_19 -> V_66 = V_66 ;
V_66 -> V_71 = V_19 ;
F_7 ( V_15 -> V_8 . V_4 , L_20 ,
V_19 -> V_21 , & V_66 -> V_10 ) ;
}
F_42 ( & V_15 -> V_74 ) ;
for ( V_90 = 0 ; V_90 < V_91 ; V_90 ++ ) {
if ( ! ( V_89 & F_45 ( V_90 ) ) )
continue;
V_19 = V_15 -> V_92 + V_90 ;
V_66 = V_19 -> V_66 ;
if ( V_66 ) {
F_41 ( & V_66 -> V_10 . V_74 ) ;
F_36 ( V_66 ) ;
F_42 ( & V_66 -> V_10 . V_74 ) ;
}
}
}
static T_5 F_46 ( int V_94 , void * V_95 )
{
struct V_5 * V_15 = V_95 ;
struct V_9 * V_66 ;
struct V_18 * V_19 ;
int V_96 , V_97 , V_58 = V_98 ;
T_2 V_99 ;
for ( V_96 = 0 ; V_96 < 2 ; V_96 ++ ) {
V_99 = F_9 ( V_15 -> V_16 + F_10 ( V_96 ) ) ;
if ( ! V_99 )
continue;
F_7 ( V_15 -> V_8 . V_4 , L_21 ,
V_96 ? L_22 : L_23 , V_99 ) ;
F_33 ( V_99 , V_15 -> V_16 + F_10 ( V_96 ) ) ;
for ( V_97 = 0 ; ( V_97 < 8 ) && V_99 ; V_97 ++ ) {
if ( V_99 & V_85 ) {
V_19 = V_15 -> V_92 + V_97 ;
V_66 = V_19 -> V_66 ;
if ( V_66 ) {
F_28 ( & V_66 -> V_10 . V_74 ) ;
F_47 ( & V_19 -> V_78 -> V_14 ) ;
V_19 -> V_79 = V_19 -> V_78 ;
F_30 ( & V_66 -> V_10 . V_74 ) ;
}
}
V_99 = V_99 >> 4 ;
}
if ( ! F_48 ( & V_15 -> V_100 ) )
F_49 ( & V_15 -> V_101 ) ;
V_58 = V_102 ;
}
return V_58 ;
}
static struct V_12 * F_50 (
struct V_2 * V_3 , T_4 V_103 , T_4 V_49 ,
T_6 V_51 , unsigned long V_72 )
{
struct V_5 * V_15 = F_2 ( V_3 -> V_1 ) ;
struct V_9 * V_66 = F_4 ( V_3 ) ;
struct V_52 * V_104 = & V_66 -> V_63 ;
struct V_38 * V_44 ;
struct V_11 * V_42 ;
T_4 V_43 ;
int V_58 ;
F_7 ( F_1 ( V_3 ) ,
L_24 ,
V_105 , V_66 -> V_10 . V_3 . V_106 , & V_103 , & V_49 , V_51 , V_72 ) ;
if ( ! V_51 )
return NULL ;
V_42 = F_51 ( sizeof( * V_42 ) , V_107 ) ;
if ( ! V_42 )
return NULL ;
V_44 = F_52 ( V_15 -> V_70 , V_107 , & V_43 ) ;
if ( ! V_44 ) {
F_53 ( V_15 -> V_8 . V_4 , L_25 ) ;
goto V_108;
}
V_58 = F_16 ( V_44 , V_49 , V_103 , V_51 , V_104 ) ;
if ( V_58 )
goto V_109;
V_44 -> V_63 |= F_54 ( V_110 ) |
F_55 ( V_110 ) |
V_111 |
V_112 ;
F_15 ( NULL , V_44 , V_43 , V_42 ) ;
F_21 ( V_66 , V_44 ) ;
return F_56 ( & V_66 -> V_10 , & V_42 -> V_14 , V_72 ) ;
V_109:
F_24 ( V_15 -> V_70 , V_44 , V_43 ) ;
V_108:
F_25 ( V_42 ) ;
return NULL ;
}
static struct V_12 * F_57 (
struct V_2 * V_3 , struct V_113 * V_114 ,
unsigned int V_115 , enum V_116 V_117 ,
unsigned long V_72 , void * V_118 )
{
struct V_5 * V_15 = F_2 ( V_3 -> V_1 ) ;
struct V_9 * V_66 = F_4 ( V_3 ) ;
struct V_52 * V_104 = & V_66 -> V_63 ;
struct V_38 * V_44 , * V_39 = NULL ;
struct V_11 * V_42 ;
struct V_113 * V_119 ;
T_4 V_43 ;
int V_96 , V_58 ;
if ( ! V_114 )
return NULL ;
if ( ! F_58 ( V_117 ) ) {
F_53 ( F_1 ( V_3 ) , L_26 ) ;
return NULL ;
}
V_42 = F_51 ( sizeof( * V_42 ) , V_107 ) ;
if ( ! V_42 )
return NULL ;
F_59 (sgl, sg, sg_len, i) {
V_44 = F_52 ( V_15 -> V_70 , V_107 , & V_43 ) ;
if ( ! V_44 )
goto V_120;
if ( V_117 == V_121 ) {
V_58 = F_16 ( V_44 , F_60 ( V_119 ) ,
V_104 -> V_122 , F_61 ( V_119 ) ,
V_104 ) ;
if ( V_58 )
goto V_123;
V_44 -> V_63 |= V_124 |
V_112 |
F_54 ( V_110 ) |
F_55 ( V_66 -> V_125 ) ;
F_7 ( F_1 ( V_3 ) ,
L_27 ,
V_105 , V_66 -> V_10 . V_3 . V_106 ,
& V_104 -> V_122 , & F_60 ( V_119 ) ,
F_61 ( V_119 ) , V_72 ) ;
} else {
V_58 = F_16 ( V_44 , V_104 -> V_126 ,
F_60 ( V_119 ) , F_61 ( V_119 ) ,
V_104 ) ;
if ( V_58 )
goto V_123;
V_44 -> V_63 |= V_111 |
V_127 |
F_55 ( V_110 ) |
F_54 ( V_66 -> V_125 ) ;
F_7 ( F_1 ( V_3 ) ,
L_27 ,
V_105 , V_66 -> V_10 . V_3 . V_106 ,
& F_60 ( V_119 ) , & V_104 -> V_126 ,
F_61 ( V_119 ) , V_72 ) ;
}
V_39 = F_15 ( V_39 , V_44 , V_43 , V_42 ) ;
}
F_7 ( F_1 ( V_3 ) , L_28 , & V_42 -> V_43 ) ;
for ( V_39 = V_42 -> V_44 ; V_39 ; V_39 = V_39 -> V_46 )
F_21 ( V_66 , V_39 ) ;
return F_56 ( & V_66 -> V_10 , & V_42 -> V_14 , V_72 ) ;
V_123:
F_24 ( V_15 -> V_70 , V_44 , V_43 ) ;
V_120:
for ( V_39 = V_42 -> V_44 ; V_39 ; V_39 = V_39 -> V_46 )
F_24 ( V_15 -> V_70 , V_39 , F_12 ( V_39 ) ) ;
F_25 ( V_42 ) ;
return NULL ;
}
static int F_62 ( struct V_2 * V_3 , enum V_128 V_129 ,
unsigned long V_130 )
{
struct V_5 * V_15 = F_2 ( V_3 -> V_1 ) ;
struct V_9 * V_66 = F_4 ( V_3 ) ;
struct V_18 * V_19 = V_66 -> V_71 ;
unsigned long V_72 ;
int V_58 = 0 ;
switch ( V_129 ) {
case V_131 :
F_7 ( F_1 ( V_3 ) , L_29 , & V_66 -> V_10 ) ;
F_31 ( & V_66 -> V_10 . V_74 , V_72 ) ;
if ( V_19 ) {
F_33 ( V_77 ,
V_19 -> V_16 + V_23 ) ;
} else if ( ! F_43 ( & V_66 -> V_10 . V_132 ) ) {
F_28 ( & V_15 -> V_74 ) ;
F_63 ( & V_66 -> V_75 , & V_15 -> V_93 ) ;
F_30 ( & V_15 -> V_74 ) ;
}
F_34 ( & V_66 -> V_10 . V_74 , V_72 ) ;
break;
case V_133 :
F_7 ( F_1 ( V_3 ) , L_30 , & V_66 -> V_10 ) ;
if ( V_19 ) {
F_33 ( V_134 ,
V_19 -> V_16 + V_23 ) ;
} else {
F_28 ( & V_15 -> V_74 ) ;
F_29 ( & V_66 -> V_75 ) ;
F_30 ( & V_15 -> V_74 ) ;
}
break;
case V_135 :
V_58 = F_26 ( V_66 ) ;
break;
case V_136 :
memcpy ( & V_66 -> V_63 , ( void * ) V_130 , sizeof( struct V_52 ) ) ;
break;
default:
V_58 = - V_137 ;
break;
}
return V_58 ;
}
static enum V_138 F_64 ( struct V_2 * V_3 ,
T_7 V_139 ,
struct V_140 * V_141 )
{
struct V_9 * V_66 = F_4 ( V_3 ) ;
struct V_18 * V_19 = V_66 -> V_71 ;
struct V_38 * V_48 ;
struct V_67 * V_14 ;
struct V_11 * V_42 ;
enum V_138 V_58 ;
unsigned long V_72 ;
T_6 V_142 = 0 ;
V_58 = F_65 ( V_3 , V_139 , V_141 ) ;
if ( V_58 == V_143 )
return V_58 ;
F_31 ( & V_66 -> V_10 . V_74 , V_72 ) ;
V_14 = F_66 ( & V_66 -> V_10 , V_139 ) ;
V_42 = F_5 ( & V_14 -> V_13 ) ;
if ( V_14 ) {
for ( V_48 = V_42 -> V_44 ; V_48 != NULL ; V_48 = V_48 -> V_46 )
V_142 += V_48 -> V_51 ;
} else if ( ! V_19 || ! V_19 -> V_78 ) {
V_142 = 0 ;
} else {
V_142 = F_9 ( V_19 -> V_16 + V_28 ) ;
}
F_34 ( & V_66 -> V_10 . V_74 , V_72 ) ;
F_67 ( V_141 , V_142 ) ;
return V_58 ;
}
static void F_68 ( struct V_2 * V_3 )
{
struct V_5 * V_15 = F_2 ( V_3 -> V_1 ) ;
struct V_9 * V_66 = F_4 ( V_3 ) ;
unsigned long V_72 ;
F_31 ( & V_66 -> V_10 . V_74 , V_72 ) ;
if ( F_69 ( & V_66 -> V_10 ) ) {
F_28 ( & V_15 -> V_74 ) ;
if ( ! V_66 -> V_71 && F_43 ( & V_66 -> V_75 ) ) {
F_63 ( & V_66 -> V_75 , & V_15 -> V_93 ) ;
F_49 ( & V_15 -> V_101 ) ;
F_7 ( F_1 ( V_3 ) , L_31 ,
& V_66 -> V_10 ) ;
}
F_30 ( & V_15 -> V_74 ) ;
} else {
F_7 ( F_1 ( V_3 ) , L_32 ,
& V_66 -> V_10 ) ;
}
F_34 ( & V_66 -> V_10 . V_74 , V_72 ) ;
}
static int F_70 ( struct V_2 * V_3 )
{
return 0 ;
}
static void F_71 ( struct V_2 * V_3 )
{
struct V_5 * V_15 = F_2 ( V_3 -> V_1 ) ;
struct V_9 * V_66 = F_4 ( V_3 ) ;
unsigned long V_72 ;
F_31 ( & V_15 -> V_74 , V_72 ) ;
F_29 ( & V_66 -> V_75 ) ;
F_34 ( & V_15 -> V_74 , V_72 ) ;
F_72 ( & V_66 -> V_10 ) ;
}
static struct V_2 * F_73 ( struct V_144 * V_145 ,
struct V_146 * V_147 )
{
struct V_5 * V_15 = V_147 -> V_148 ;
struct V_9 * V_66 ;
struct V_2 * V_3 ;
T_3 V_125 = V_145 -> args [ 0 ] ;
if ( V_125 > V_149 )
return NULL ;
V_3 = F_74 ( & V_15 -> V_8 ) ;
if ( ! V_3 )
return NULL ;
V_66 = F_4 ( V_3 ) ;
V_66 -> V_125 = V_125 ;
return V_3 ;
}
static inline void F_75 ( struct V_5 * V_15 )
{
F_33 ( 0 , V_15 -> V_16 + F_8 ( 0 ) ) ;
F_33 ( 0 , V_15 -> V_16 + F_8 ( 1 ) ) ;
F_76 ( & V_15 -> V_100 ) ;
F_77 ( V_15 -> V_8 . V_4 , V_15 -> V_94 , V_15 ) ;
F_78 ( & V_15 -> V_101 ) ;
}
static inline void F_79 ( struct V_5 * V_15 )
{
int V_96 ;
for ( V_96 = 0 ; V_96 < V_150 ; V_96 ++ ) {
struct V_9 * V_66 = & V_15 -> V_151 [ V_96 ] ;
F_38 ( & V_66 -> V_10 . V_3 . V_152 ) ;
F_78 ( & V_66 -> V_10 . V_101 ) ;
}
}
static int F_80 ( struct V_153 * V_154 )
{
struct V_5 * V_155 ;
struct V_156 * V_157 ;
struct V_158 * V_159 , * V_160 ;
int V_58 , V_96 ;
V_155 = F_81 ( & V_154 -> V_4 , sizeof( * V_155 ) , V_161 ) ;
if ( ! V_155 )
return - V_162 ;
V_157 = F_82 ( V_154 , V_163 , 0 ) ;
V_155 -> V_16 = F_83 ( & V_154 -> V_4 , V_157 ) ;
if ( F_84 ( V_155 -> V_16 ) )
return F_85 ( V_155 -> V_16 ) ;
V_155 -> V_94 = F_86 ( V_154 , 0 ) ;
if ( V_155 -> V_94 < 0 ) {
F_53 ( & V_154 -> V_4 , L_33 ) ;
return V_155 -> V_94 ;
}
V_155 -> V_158 = F_87 ( & V_154 -> V_4 , NULL ) ;
if ( F_84 ( V_155 -> V_158 ) ) {
F_53 ( & V_154 -> V_4 , L_34 ) ;
return F_85 ( V_155 -> V_158 ) ;
}
V_159 = F_88 ( NULL , L_35 ) ;
if ( F_84 ( V_159 ) ) {
F_53 ( & V_154 -> V_4 , L_36 ) ;
return F_85 ( V_159 ) ;
}
V_160 = F_88 ( NULL , L_37 ) ;
if ( F_84 ( V_160 ) ) {
F_53 ( & V_154 -> V_4 , L_38 ) ;
F_89 ( V_159 ) ;
return F_85 ( V_160 ) ;
}
V_58 = F_90 ( V_159 , V_160 ) ;
F_89 ( V_160 ) ;
F_89 ( V_159 ) ;
if ( V_58 ) {
F_53 ( & V_154 -> V_4 , L_39 ) ;
return V_58 ;
}
V_155 -> V_164 = F_91 ( & V_154 -> V_4 , NULL ) ;
if ( F_84 ( V_155 -> V_164 ) ) {
F_53 ( & V_154 -> V_4 , L_40 ) ;
return F_85 ( V_155 -> V_164 ) ;
}
V_155 -> V_70 = F_92 ( F_93 ( & V_154 -> V_4 ) , & V_154 -> V_4 ,
sizeof( struct V_38 ) , 4 , 0 ) ;
if ( ! V_155 -> V_70 ) {
F_53 ( & V_154 -> V_4 , L_41 ) ;
return - V_162 ;
}
F_94 ( V_154 , V_155 ) ;
F_95 ( & V_155 -> V_93 ) ;
F_96 ( & V_155 -> V_74 ) ;
F_97 ( V_165 , V_155 -> V_8 . V_166 ) ;
F_97 ( V_167 , V_155 -> V_8 . V_166 ) ;
F_97 ( V_168 , V_155 -> V_8 . V_166 ) ;
F_95 ( & V_155 -> V_8 . V_169 ) ;
V_155 -> V_8 . V_170 = F_70 ;
V_155 -> V_8 . V_171 = F_71 ;
V_155 -> V_8 . V_172 = F_64 ;
V_155 -> V_8 . V_173 = F_68 ;
V_155 -> V_8 . V_174 = F_57 ;
V_155 -> V_8 . V_175 = F_50 ;
V_155 -> V_8 . V_176 = F_62 ;
V_155 -> V_8 . V_177 = V_150 ;
V_155 -> V_8 . V_4 = & V_154 -> V_4 ;
V_155 -> V_92 = F_98 ( & V_154 -> V_4 , V_91 ,
sizeof( struct V_18 ) , V_161 ) ;
if ( ! V_155 -> V_92 )
return - V_162 ;
V_155 -> V_151 = F_98 ( & V_154 -> V_4 , V_150 ,
sizeof( struct V_9 ) , V_161 ) ;
if ( ! V_155 -> V_151 )
return - V_162 ;
F_99 ( & V_155 -> V_101 , F_39 , ( unsigned long ) V_155 ) ;
for ( V_96 = 0 ; V_96 < V_91 ; V_96 ++ ) {
struct V_18 * V_19 = & V_155 -> V_92 [ V_96 ] ;
V_19 -> V_21 = V_96 ;
V_19 -> V_16 = V_155 -> V_16 + 0x100 + V_96 * 0x40 ;
}
for ( V_96 = 0 ; V_96 < V_150 ; V_96 ++ ) {
struct V_9 * V_66 = & V_155 -> V_151 [ V_96 ] ;
F_95 ( & V_66 -> V_75 ) ;
V_66 -> V_10 . V_178 = F_22 ;
F_100 ( & V_66 -> V_10 , & V_155 -> V_8 ) ;
}
V_58 = F_101 ( V_155 -> V_164 ) ;
if ( V_58 ) {
F_53 ( & V_154 -> V_4 , L_42 ) ;
goto V_179;
}
V_58 = F_102 ( V_155 -> V_158 ) ;
if ( V_58 ) {
F_53 ( & V_154 -> V_4 , L_43 ) ;
goto V_180;
}
V_58 = F_103 ( & V_154 -> V_4 , V_155 -> V_94 , F_46 , 0 ,
F_93 ( & V_154 -> V_4 ) , V_155 ) ;
if ( V_58 ) {
F_53 ( & V_154 -> V_4 , L_44 ) ;
goto V_181;
}
V_58 = F_104 ( & V_155 -> V_8 ) ;
if ( V_58 ) {
F_105 ( & V_154 -> V_4 , L_45 ) ;
goto V_182;
}
V_58 = F_106 ( V_154 -> V_4 . V_183 , F_73 ,
V_155 ) ;
if ( V_58 ) {
F_53 ( & V_154 -> V_4 , L_46 ) ;
goto V_184;
}
return 0 ;
V_184:
F_107 ( & V_155 -> V_8 ) ;
V_182:
F_75 ( V_155 ) ;
V_181:
F_108 ( V_155 -> V_158 ) ;
V_180:
F_109 ( V_155 -> V_164 ) ;
V_179:
F_79 ( V_155 ) ;
return V_58 ;
}
static int F_110 ( struct V_153 * V_154 )
{
struct V_5 * V_155 = F_111 ( V_154 ) ;
F_112 ( V_154 -> V_4 . V_183 ) ;
F_107 ( & V_155 -> V_8 ) ;
F_75 ( V_155 ) ;
F_108 ( V_155 -> V_158 ) ;
F_109 ( V_155 -> V_164 ) ;
F_79 ( V_155 ) ;
return 0 ;
}
