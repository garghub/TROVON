static inline struct V_1 *
F_1 ( struct V_2 * V_3 )
{
if ( ! V_3 )
return NULL ;
return F_2 ( V_3 , struct V_1 , V_4 ) ;
}
static inline struct V_5 *
F_3 ( struct V_6 * V_7 )
{
return F_2 ( V_7 , struct V_5 , V_8 ) ;
}
static inline void F_4 ( struct V_9 * V_10 )
{
struct V_11 * V_12 ;
struct V_5 * V_13 ;
struct V_1 * V_14 ;
unsigned long V_15 ;
if ( F_5 ( V_10 ) )
return;
F_6 (desc, list, node) {
T_1 V_16 ;
void * V_17 ;
V_14 = V_13 -> V_18 ;
V_16 = V_13 -> V_8 . V_16 ;
V_17 = V_13 -> V_8 . V_19 ;
if ( V_16 )
V_16 ( V_17 ) ;
V_13 -> V_18 = NULL ;
}
V_12 = V_14 -> V_20 ;
F_7 ( & V_12 -> V_21 , V_15 ) ;
F_8 ( V_10 , & V_12 -> V_22 ) ;
F_9 ( & V_12 -> V_21 , V_15 ) ;
}
static inline void F_10 ( struct V_1 * V_14 )
{
struct V_5 * V_13 ;
int V_23 ;
F_6 (desc, &pch->work_list, node) {
if ( V_13 -> V_24 == V_25 )
break;
V_23 = F_11 ( V_14 -> V_26 ,
& V_13 -> V_27 ) ;
if ( ! V_23 ) {
V_13 -> V_24 = V_25 ;
break;
} else if ( V_23 == - V_28 ) {
break;
} else {
V_13 -> V_24 = V_29 ;
F_12 ( V_14 -> V_20 -> V_30 . V_31 , L_1 ,
V_32 , __LINE__ , V_13 -> V_8 . V_33 ) ;
F_13 ( & V_14 -> V_34 ) ;
}
}
}
static void F_14 ( unsigned long V_35 )
{
struct V_1 * V_14 = (struct V_1 * ) V_35 ;
struct V_5 * V_13 , * V_36 ;
unsigned long V_15 ;
F_15 ( V_10 ) ;
F_7 ( & V_14 -> V_37 , V_15 ) ;
F_16 (desc, _dt, &pch->work_list, node)
if ( V_13 -> V_24 == V_29 ) {
V_14 -> V_38 = V_13 -> V_8 . V_33 ;
F_17 ( & V_13 -> V_39 , & V_10 ) ;
}
F_10 ( V_14 ) ;
F_18 ( V_14 -> V_26 , V_40 ) ;
F_9 ( & V_14 -> V_37 , V_15 ) ;
F_4 ( & V_10 ) ;
}
static void F_19 ( void * V_41 , enum V_42 V_43 )
{
struct V_5 * V_13 = V_41 ;
struct V_1 * V_14 = V_13 -> V_18 ;
unsigned long V_15 ;
if ( ! V_14 )
return;
F_7 ( & V_14 -> V_37 , V_15 ) ;
V_13 -> V_24 = V_29 ;
F_9 ( & V_14 -> V_37 , V_15 ) ;
F_13 ( & V_14 -> V_34 ) ;
}
static int F_20 ( struct V_2 * V_4 )
{
struct V_1 * V_14 = F_1 ( V_4 ) ;
struct V_11 * V_12 = V_14 -> V_20 ;
unsigned long V_15 ;
F_7 ( & V_14 -> V_37 , V_15 ) ;
V_14 -> V_38 = V_4 -> V_33 = 1 ;
V_14 -> V_26 = F_21 ( & V_12 -> V_30 ) ;
if ( ! V_14 -> V_26 ) {
F_9 ( & V_14 -> V_37 , V_15 ) ;
return 0 ;
}
F_22 ( & V_14 -> V_34 , F_14 , ( unsigned long ) V_14 ) ;
F_9 ( & V_14 -> V_37 , V_15 ) ;
return 1 ;
}
static int F_23 ( struct V_2 * V_4 , enum V_44 V_45 , unsigned long V_46 )
{
struct V_1 * V_14 = F_1 ( V_4 ) ;
struct V_5 * V_13 ;
unsigned long V_15 ;
if ( V_45 != V_47 )
return - V_48 ;
F_7 ( & V_14 -> V_37 , V_15 ) ;
F_18 ( V_14 -> V_26 , V_49 ) ;
F_6 (desc, &pch->work_list, node)
V_13 -> V_24 = V_29 ;
F_9 ( & V_14 -> V_37 , V_15 ) ;
F_14 ( ( unsigned long ) V_14 ) ;
return 0 ;
}
static void F_24 ( struct V_2 * V_4 )
{
struct V_1 * V_14 = F_1 ( V_4 ) ;
unsigned long V_15 ;
F_7 ( & V_14 -> V_37 , V_15 ) ;
F_25 ( & V_14 -> V_34 ) ;
F_26 ( V_14 -> V_26 ) ;
V_14 -> V_26 = NULL ;
F_9 ( & V_14 -> V_37 , V_15 ) ;
}
static enum V_50
F_27 ( struct V_2 * V_4 , T_2 V_33 ,
struct V_51 * V_52 )
{
struct V_1 * V_14 = F_1 ( V_4 ) ;
T_2 V_53 , V_54 ;
int V_23 ;
V_53 = V_14 -> V_38 ;
V_54 = V_4 -> V_33 ;
V_23 = F_28 ( V_33 , V_53 , V_54 ) ;
F_29 ( V_52 , V_53 , V_54 , 0 ) ;
return V_23 ;
}
static void F_30 ( struct V_2 * V_4 )
{
F_14 ( ( unsigned long ) F_1 ( V_4 ) ) ;
}
static T_2 F_31 ( struct V_6 * V_7 )
{
struct V_5 * V_13 , * V_55 = F_3 ( V_7 ) ;
struct V_1 * V_14 = F_1 ( V_7 -> V_4 ) ;
T_2 V_33 ;
unsigned long V_15 ;
F_7 ( & V_14 -> V_37 , V_15 ) ;
V_33 = V_7 -> V_4 -> V_33 ;
while ( ! F_5 ( & V_55 -> V_39 ) ) {
V_13 = F_32 ( V_55 -> V_39 . V_56 , struct V_5 , V_39 ) ;
if ( ++ V_33 < 0 )
V_33 = 1 ;
V_13 -> V_8 . V_33 = V_33 ;
F_17 ( & V_13 -> V_39 , & V_14 -> V_57 ) ;
}
if ( ++ V_33 < 0 )
V_33 = 1 ;
V_55 -> V_8 . V_33 = V_33 ;
F_33 ( & V_55 -> V_39 , & V_14 -> V_57 ) ;
V_7 -> V_4 -> V_33 = V_33 ;
F_9 ( & V_14 -> V_37 , V_15 ) ;
return V_33 ;
}
static inline void F_34 ( struct V_5 * V_13 )
{
V_13 -> V_18 = NULL ;
V_13 -> V_27 . V_58 = & V_13 -> V_59 ;
V_13 -> V_27 . V_41 = V_13 ;
V_13 -> V_60 . V_61 = V_62 ;
V_13 -> V_60 . V_63 = 0 ;
V_13 -> V_60 . V_64 = 0 ;
V_13 -> V_60 . V_65 = V_66 ;
V_13 -> V_60 . V_67 = V_68 ;
V_13 -> V_27 . V_69 = & V_13 -> V_60 ;
V_13 -> V_27 . V_70 = F_19 ;
V_13 -> V_8 . V_71 = F_31 ;
F_35 ( & V_13 -> V_39 ) ;
}
int F_36 ( struct V_11 * V_12 , T_3 V_72 , int V_73 )
{
struct V_5 * V_13 ;
unsigned long V_15 ;
int V_74 ;
if ( ! V_12 )
return 0 ;
V_13 = F_37 ( V_73 * sizeof( * V_13 ) , V_72 ) ;
if ( ! V_13 )
return 0 ;
F_7 ( & V_12 -> V_21 , V_15 ) ;
for ( V_74 = 0 ; V_74 < V_73 ; V_74 ++ ) {
F_34 ( & V_13 [ V_74 ] ) ;
F_33 ( & V_13 [ V_74 ] . V_39 , & V_12 -> V_22 ) ;
}
F_9 ( & V_12 -> V_21 , V_15 ) ;
return V_73 ;
}
static struct V_5 *
F_38 ( struct V_11 * V_12 )
{
struct V_5 * V_13 = NULL ;
unsigned long V_15 ;
if ( ! V_12 )
return NULL ;
F_7 ( & V_12 -> V_21 , V_15 ) ;
if ( ! F_5 ( & V_12 -> V_22 ) ) {
V_13 = F_32 ( V_12 -> V_22 . V_56 ,
struct V_5 , V_39 ) ;
F_39 ( & V_13 -> V_39 ) ;
V_13 -> V_24 = V_75 ;
V_13 -> V_8 . V_16 = NULL ;
}
F_9 ( & V_12 -> V_21 , V_15 ) ;
return V_13 ;
}
static struct V_5 * F_40 ( struct V_1 * V_14 )
{
struct V_11 * V_12 = V_14 -> V_20 ;
struct V_76 * V_77 = V_14 -> V_4 . V_78 ;
struct V_5 * V_13 ;
V_13 = F_38 ( V_12 ) ;
if ( ! V_13 ) {
if ( ! F_36 ( V_12 , V_79 , 1 ) )
return NULL ;
V_13 = F_38 ( V_12 ) ;
if ( ! V_13 ) {
F_12 ( V_14 -> V_20 -> V_30 . V_31 ,
L_2 , V_32 , __LINE__ ) ;
return NULL ;
}
}
V_13 -> V_18 = V_14 ;
V_13 -> V_8 . V_33 = 0 ;
F_41 ( & V_13 -> V_8 ) ;
if ( V_77 ) {
V_13 -> V_27 . V_80 = V_77 -> V_80 ;
V_13 -> V_27 . V_77 = V_77 -> V_81 ;
} else {
V_13 -> V_27 . V_80 = V_82 ;
V_13 -> V_27 . V_77 = 0 ;
}
F_42 ( & V_13 -> V_8 , & V_14 -> V_4 ) ;
return V_13 ;
}
static inline void F_43 ( struct V_83 * V_59 ,
T_4 V_84 , T_4 V_85 , T_5 V_86 )
{
V_59 -> V_56 = NULL ;
V_59 -> V_87 = V_86 ;
V_59 -> V_88 = V_84 ;
V_59 -> V_89 = V_85 ;
}
static struct V_5 *
F_44 ( struct V_1 * V_14 , T_4 V_84 ,
T_4 V_85 , T_5 V_86 )
{
struct V_5 * V_13 = F_40 ( V_14 ) ;
if ( ! V_13 ) {
F_12 ( V_14 -> V_20 -> V_30 . V_31 , L_3 ,
V_32 , __LINE__ ) ;
return NULL ;
}
F_43 ( & V_13 -> V_59 , V_84 , V_85 , V_86 ) ;
return V_13 ;
}
static inline int F_45 ( struct V_5 * V_13 , T_5 V_86 )
{
struct V_1 * V_14 = V_13 -> V_18 ;
struct V_90 * V_91 = & V_14 -> V_20 -> V_30 ;
int V_92 ;
V_92 = V_91 -> V_93 . V_94 / 8 ;
V_92 *= V_91 -> V_93 . V_95 ;
V_92 >>= V_13 -> V_60 . V_96 ;
if ( V_92 > 16 )
V_92 = 16 ;
while ( V_92 > 1 ) {
if ( ! ( V_86 % ( V_92 << V_13 -> V_60 . V_96 ) ) )
break;
V_92 -- ;
}
return V_92 ;
}
static struct V_6 *
F_46 ( struct V_2 * V_4 , T_4 V_84 ,
T_4 V_85 , T_5 V_86 , unsigned long V_15 )
{
struct V_5 * V_13 ;
struct V_1 * V_14 = F_1 ( V_4 ) ;
struct V_76 * V_77 = V_4 -> V_78 ;
struct V_90 * V_91 ;
int V_97 ;
if ( F_47 ( ! V_14 || ! V_86 ) )
return NULL ;
if ( V_77 && V_77 -> V_80 != V_82 )
return NULL ;
V_91 = & V_14 -> V_20 -> V_30 ;
V_13 = F_44 ( V_14 , V_84 , V_85 , V_86 ) ;
if ( ! V_13 )
return NULL ;
V_13 -> V_60 . V_98 = 1 ;
V_13 -> V_60 . V_99 = 1 ;
V_97 = V_91 -> V_93 . V_94 / 8 ;
while ( V_97 > 1 ) {
if ( ! ( V_86 % V_97 ) )
break;
V_97 /= 2 ;
}
V_13 -> V_60 . V_96 = 0 ;
while ( V_97 != ( 1 << V_13 -> V_60 . V_96 ) )
V_13 -> V_60 . V_96 ++ ;
V_13 -> V_60 . V_100 = F_45 ( V_13 , V_86 ) ;
V_13 -> V_8 . V_15 = V_15 ;
return & V_13 -> V_8 ;
}
static struct V_6 *
F_48 ( struct V_2 * V_4 , struct V_101 * V_102 ,
unsigned int V_103 , enum V_104 V_105 ,
unsigned long V_72 )
{
struct V_5 * V_106 , * V_13 = NULL ;
struct V_1 * V_14 = F_1 ( V_4 ) ;
struct V_76 * V_77 = V_4 -> V_78 ;
struct V_101 * V_107 ;
unsigned long V_15 ;
int V_74 , V_108 ;
T_4 V_109 ;
if ( F_47 ( ! V_14 || ! V_102 || ! V_103 || ! V_77 ) )
return NULL ;
if ( ( V_105 == V_110 &&
V_77 -> V_80 != V_111 ) ||
( V_105 == V_112 &&
V_77 -> V_80 != V_113 ) ) {
F_12 ( V_14 -> V_20 -> V_30 . V_31 , L_4 ,
V_32 , __LINE__ ) ;
return NULL ;
}
V_109 = V_77 -> V_114 ;
V_108 = V_77 -> V_115 ;
V_106 = NULL ;
F_49 (sgl, sg, sg_len, i) {
V_13 = F_40 ( V_14 ) ;
if ( ! V_13 ) {
struct V_11 * V_12 = V_14 -> V_20 ;
F_12 ( V_14 -> V_20 -> V_30 . V_31 ,
L_3 ,
V_32 , __LINE__ ) ;
if ( ! V_106 )
return NULL ;
F_7 ( & V_12 -> V_21 , V_15 ) ;
while ( ! F_5 ( & V_106 -> V_39 ) ) {
V_13 = F_32 ( V_106 -> V_39 . V_56 ,
struct V_5 , V_39 ) ;
F_17 ( & V_13 -> V_39 , & V_12 -> V_22 ) ;
}
F_17 ( & V_106 -> V_39 , & V_12 -> V_22 ) ;
F_9 ( & V_12 -> V_21 , V_15 ) ;
return NULL ;
}
if ( ! V_106 )
V_106 = V_13 ;
else
F_33 ( & V_13 -> V_39 , & V_106 -> V_39 ) ;
if ( V_105 == V_110 ) {
V_13 -> V_60 . V_98 = 1 ;
V_13 -> V_60 . V_99 = 0 ;
F_43 ( & V_13 -> V_59 ,
V_109 , F_50 ( V_107 ) , F_51 ( V_107 ) ) ;
} else {
V_13 -> V_60 . V_98 = 0 ;
V_13 -> V_60 . V_99 = 1 ;
F_43 ( & V_13 -> V_59 ,
F_50 ( V_107 ) , V_109 , F_51 ( V_107 ) ) ;
}
V_13 -> V_60 . V_96 = V_108 ;
V_13 -> V_60 . V_100 = 1 ;
}
V_13 -> V_8 . V_15 = V_72 ;
return & V_13 -> V_8 ;
}
static T_6 F_52 ( int V_116 , void * V_35 )
{
if ( F_53 ( V_35 ) )
return V_117 ;
else
return V_118 ;
}
static int T_7
F_54 ( struct V_119 * V_120 , const struct V_121 * V_122 )
{
struct V_123 * V_124 ;
struct V_11 * V_12 ;
struct V_1 * V_14 ;
struct V_90 * V_91 ;
struct V_125 * V_126 ;
struct V_127 * V_128 ;
int V_74 , V_23 , V_116 ;
int V_129 ;
V_124 = V_120 -> V_31 . V_130 ;
V_12 = F_55 ( sizeof( * V_12 ) , V_131 ) ;
if ( ! V_12 ) {
F_12 ( & V_120 -> V_31 , L_5 ) ;
return - V_132 ;
}
V_91 = & V_12 -> V_30 ;
V_91 -> V_31 = & V_120 -> V_31 ;
V_91 -> V_133 = NULL ;
V_91 -> V_134 = V_124 ? V_124 -> V_135 : 0 ;
V_128 = & V_120 -> V_128 ;
F_56 ( V_128 -> V_136 , F_57 ( V_128 ) , L_6 ) ;
V_91 -> V_137 = F_58 ( V_128 -> V_136 , F_57 ( V_128 ) ) ;
if ( ! V_91 -> V_137 ) {
V_23 = - V_48 ;
goto V_138;
}
V_116 = V_120 -> V_116 [ 0 ] ;
V_23 = F_59 ( V_116 , F_52 , 0 ,
F_60 ( & V_120 -> V_31 ) , V_91 ) ;
if ( V_23 )
goto V_139;
V_23 = F_61 ( V_91 ) ;
if ( V_23 )
goto V_140;
F_35 ( & V_12 -> V_22 ) ;
F_62 ( & V_12 -> V_21 ) ;
if ( ! F_36 ( V_12 , V_131 , V_141 ) )
F_63 ( & V_120 -> V_31 , L_7 ) ;
V_126 = & V_12 -> V_142 ;
F_35 ( & V_126 -> V_143 ) ;
V_129 = F_64 ( V_124 ? V_124 -> V_144 : 0 , ( V_145 ) V_91 -> V_93 . V_129 ) ;
V_12 -> V_146 = F_55 ( V_129 * sizeof( * V_14 ) , V_131 ) ;
for ( V_74 = 0 ; V_74 < V_129 ; V_74 ++ ) {
V_14 = & V_12 -> V_146 [ V_74 ] ;
if ( V_124 ) {
struct V_76 * V_77 = & V_124 -> V_77 [ V_74 ] ;
switch ( V_77 -> V_80 ) {
case V_82 :
F_65 ( V_147 , V_126 -> V_148 ) ;
break;
case V_111 :
case V_113 :
F_65 ( V_149 , V_126 -> V_148 ) ;
break;
default:
F_12 ( & V_120 -> V_31 , L_8 ) ;
continue;
}
V_14 -> V_4 . V_78 = V_77 ;
} else {
F_65 ( V_147 , V_126 -> V_148 ) ;
V_14 -> V_4 . V_78 = NULL ;
}
F_35 ( & V_14 -> V_57 ) ;
F_62 ( & V_14 -> V_37 ) ;
V_14 -> V_26 = NULL ;
V_14 -> V_4 . V_150 = V_126 ;
V_14 -> V_4 . V_151 = V_74 ;
V_14 -> V_20 = V_12 ;
V_126 -> V_152 ++ ;
F_33 ( & V_14 -> V_4 . V_153 , & V_126 -> V_143 ) ;
}
V_126 -> V_31 = & V_120 -> V_31 ;
V_126 -> V_154 = F_20 ;
V_126 -> V_155 = F_24 ;
V_126 -> V_156 = F_46 ;
V_126 -> V_157 = F_27 ;
V_126 -> V_158 = F_48 ;
V_126 -> V_159 = F_23 ;
V_126 -> V_160 = F_30 ;
V_23 = F_66 ( V_126 ) ;
if ( V_23 ) {
F_12 ( & V_120 -> V_31 , L_9 ) ;
goto V_161;
}
F_67 ( V_120 , V_12 ) ;
F_68 ( & V_120 -> V_31 ,
L_10 , V_120 -> V_162 ) ;
F_68 ( & V_120 -> V_31 ,
L_11 ,
V_91 -> V_93 . V_95 ,
V_91 -> V_93 . V_94 / 8 , V_91 -> V_93 . V_129 ,
V_91 -> V_93 . V_163 , V_91 -> V_93 . V_164 ) ;
return 0 ;
V_161:
F_69 ( V_91 ) ;
V_140:
F_70 ( V_116 , V_91 ) ;
V_139:
F_71 ( V_91 -> V_137 ) ;
V_138:
F_72 ( V_128 -> V_136 , F_57 ( V_128 ) ) ;
F_73 ( V_12 ) ;
return V_23 ;
}
static int T_8 F_74 ( struct V_119 * V_120 )
{
struct V_11 * V_12 = F_75 ( V_120 ) ;
struct V_1 * V_14 , * V_165 ;
struct V_90 * V_91 ;
struct V_127 * V_128 ;
int V_116 ;
if ( ! V_12 )
return 0 ;
F_67 ( V_120 , NULL ) ;
F_16 (pch, _p, &pdmac->ddma.channels,
chan.device_node) {
F_76 ( & V_14 -> V_4 . V_153 ) ;
F_23 ( & V_14 -> V_4 , V_47 , 0 ) ;
F_24 ( & V_14 -> V_4 ) ;
}
V_91 = & V_12 -> V_30 ;
F_69 ( V_91 ) ;
V_116 = V_120 -> V_116 [ 0 ] ;
F_70 ( V_116 , V_91 ) ;
F_71 ( V_91 -> V_137 ) ;
V_128 = & V_120 -> V_128 ;
F_72 ( V_128 -> V_136 , F_57 ( V_128 ) ) ;
F_73 ( V_12 ) ;
return 0 ;
}
static int T_9 F_77 ( void )
{
return F_78 ( & V_166 ) ;
}
static void T_10 F_79 ( void )
{
F_80 ( & V_166 ) ;
return;
}
