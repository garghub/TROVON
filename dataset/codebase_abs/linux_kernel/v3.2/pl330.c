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
static inline void F_10 ( struct V_9 * V_10 )
{
struct V_5 * V_13 ;
struct V_1 * V_14 ;
unsigned long V_15 ;
if ( F_5 ( V_10 ) )
return;
F_6 (desc, list, node) {
T_1 V_16 ;
V_13 -> V_23 = V_24 ;
V_14 = V_13 -> V_18 ;
V_16 = V_13 -> V_8 . V_16 ;
if ( V_16 )
V_16 ( V_13 -> V_8 . V_19 ) ;
}
F_7 ( & V_14 -> V_25 , V_15 ) ;
F_8 ( V_10 , & V_14 -> V_26 ) ;
F_9 ( & V_14 -> V_25 , V_15 ) ;
}
static inline void F_11 ( struct V_1 * V_14 )
{
struct V_5 * V_13 ;
int V_27 ;
F_6 (desc, &pch->work_list, node) {
if ( V_13 -> V_23 == V_28 )
break;
V_27 = F_12 ( V_14 -> V_29 ,
& V_13 -> V_30 ) ;
if ( ! V_27 ) {
V_13 -> V_23 = V_28 ;
break;
} else if ( V_27 == - V_31 ) {
break;
} else {
V_13 -> V_23 = V_32 ;
F_13 ( V_14 -> V_20 -> V_33 . V_34 , L_1 ,
V_35 , __LINE__ , V_13 -> V_8 . V_36 ) ;
F_14 ( & V_14 -> V_37 ) ;
}
}
}
static void F_15 ( unsigned long V_38 )
{
struct V_1 * V_14 = (struct V_1 * ) V_38 ;
struct V_5 * V_13 , * V_39 ;
unsigned long V_15 ;
F_16 ( V_10 ) ;
F_7 ( & V_14 -> V_25 , V_15 ) ;
F_17 (desc, _dt, &pch->work_list, node)
if ( V_13 -> V_23 == V_32 ) {
V_14 -> V_40 = V_13 -> V_8 . V_36 ;
F_18 ( & V_13 -> V_41 , & V_10 ) ;
}
F_11 ( V_14 ) ;
F_19 ( V_14 -> V_29 , V_42 ) ;
F_9 ( & V_14 -> V_25 , V_15 ) ;
if ( V_14 -> V_43 )
F_10 ( & V_10 ) ;
else
F_4 ( & V_10 ) ;
}
static void F_20 ( void * V_44 , enum V_45 V_46 )
{
struct V_5 * V_13 = V_44 ;
struct V_1 * V_14 = V_13 -> V_18 ;
unsigned long V_15 ;
if ( ! V_14 )
return;
F_7 ( & V_14 -> V_25 , V_15 ) ;
V_13 -> V_23 = V_32 ;
F_9 ( & V_14 -> V_25 , V_15 ) ;
F_14 ( & V_14 -> V_37 ) ;
}
static int F_21 ( struct V_2 * V_4 )
{
struct V_1 * V_14 = F_1 ( V_4 ) ;
struct V_11 * V_12 = V_14 -> V_20 ;
unsigned long V_15 ;
F_7 ( & V_14 -> V_25 , V_15 ) ;
V_14 -> V_40 = V_4 -> V_36 = 1 ;
V_14 -> V_43 = false ;
V_14 -> V_29 = F_22 ( & V_12 -> V_33 ) ;
if ( ! V_14 -> V_29 ) {
F_9 ( & V_14 -> V_25 , V_15 ) ;
return 0 ;
}
F_23 ( & V_14 -> V_37 , F_15 , ( unsigned long ) V_14 ) ;
F_9 ( & V_14 -> V_25 , V_15 ) ;
return 1 ;
}
static int F_24 ( struct V_2 * V_4 , enum V_47 V_48 , unsigned long V_49 )
{
struct V_1 * V_14 = F_1 ( V_4 ) ;
struct V_5 * V_13 , * V_39 ;
unsigned long V_15 ;
struct V_11 * V_12 = V_14 -> V_20 ;
struct V_50 * V_51 ;
F_16 ( V_10 ) ;
switch ( V_48 ) {
case V_52 :
F_7 ( & V_14 -> V_25 , V_15 ) ;
F_19 ( V_14 -> V_29 , V_53 ) ;
F_17 (desc, _dt, &pch->work_list , node) {
V_13 -> V_23 = V_32 ;
V_14 -> V_40 = V_13 -> V_8 . V_36 ;
F_18 ( & V_13 -> V_41 , & V_10 ) ;
}
F_8 ( & V_10 , & V_12 -> V_22 ) ;
F_9 ( & V_14 -> V_25 , V_15 ) ;
break;
case V_54 :
V_51 = (struct V_50 * ) V_49 ;
if ( V_51 -> V_55 == V_56 ) {
if ( V_51 -> V_57 )
V_14 -> V_58 = V_51 -> V_57 ;
if ( V_51 -> V_59 )
V_14 -> V_60 = F_25 ( V_51 -> V_59 ) ;
if ( V_51 -> V_61 )
V_14 -> V_62 = V_51 -> V_61 ;
} else if ( V_51 -> V_55 == V_63 ) {
if ( V_51 -> V_64 )
V_14 -> V_58 = V_51 -> V_64 ;
if ( V_51 -> V_65 )
V_14 -> V_60 = F_25 ( V_51 -> V_65 ) ;
if ( V_51 -> V_66 )
V_14 -> V_62 = V_51 -> V_66 ;
}
break;
default:
F_13 ( V_14 -> V_20 -> V_33 . V_34 , L_2 ) ;
return - V_67 ;
}
return 0 ;
}
static void F_26 ( struct V_2 * V_4 )
{
struct V_1 * V_14 = F_1 ( V_4 ) ;
unsigned long V_15 ;
F_7 ( & V_14 -> V_25 , V_15 ) ;
F_27 ( & V_14 -> V_37 ) ;
F_28 ( V_14 -> V_29 ) ;
V_14 -> V_29 = NULL ;
if ( V_14 -> V_43 )
F_8 ( & V_14 -> V_26 , & V_14 -> V_20 -> V_22 ) ;
F_9 ( & V_14 -> V_25 , V_15 ) ;
}
static enum V_68
F_29 ( struct V_2 * V_4 , T_2 V_36 ,
struct V_69 * V_70 )
{
struct V_1 * V_14 = F_1 ( V_4 ) ;
T_2 V_71 , V_72 ;
int V_27 ;
V_71 = V_14 -> V_40 ;
V_72 = V_4 -> V_36 ;
V_27 = F_30 ( V_36 , V_71 , V_72 ) ;
F_31 ( V_70 , V_71 , V_72 , 0 ) ;
return V_27 ;
}
static void F_32 ( struct V_2 * V_4 )
{
F_15 ( ( unsigned long ) F_1 ( V_4 ) ) ;
}
static T_2 F_33 ( struct V_6 * V_7 )
{
struct V_5 * V_13 , * V_73 = F_3 ( V_7 ) ;
struct V_1 * V_14 = F_1 ( V_7 -> V_4 ) ;
T_2 V_36 ;
unsigned long V_15 ;
F_7 ( & V_14 -> V_25 , V_15 ) ;
V_36 = V_7 -> V_4 -> V_36 ;
while ( ! F_5 ( & V_73 -> V_41 ) ) {
V_13 = F_34 ( V_73 -> V_41 . V_74 , struct V_5 , V_41 ) ;
if ( ++ V_36 < 0 )
V_36 = 1 ;
V_13 -> V_8 . V_36 = V_36 ;
F_18 ( & V_13 -> V_41 , & V_14 -> V_26 ) ;
}
if ( ++ V_36 < 0 )
V_36 = 1 ;
V_73 -> V_8 . V_36 = V_36 ;
F_35 ( & V_73 -> V_41 , & V_14 -> V_26 ) ;
V_7 -> V_4 -> V_36 = V_36 ;
F_9 ( & V_14 -> V_25 , V_15 ) ;
return V_36 ;
}
static inline void F_36 ( struct V_5 * V_13 )
{
V_13 -> V_18 = NULL ;
V_13 -> V_30 . V_75 = & V_13 -> V_76 ;
V_13 -> V_30 . V_44 = V_13 ;
V_13 -> V_77 . V_78 = V_79 ;
V_13 -> V_77 . V_80 = 0 ;
V_13 -> V_77 . V_81 = 0 ;
V_13 -> V_77 . V_82 = V_83 ;
V_13 -> V_77 . V_84 = V_85 ;
V_13 -> V_30 . V_86 = & V_13 -> V_77 ;
V_13 -> V_30 . V_87 = F_20 ;
V_13 -> V_8 . V_88 = F_33 ;
F_37 ( & V_13 -> V_41 ) ;
}
int F_38 ( struct V_11 * V_12 , T_3 V_89 , int V_90 )
{
struct V_5 * V_13 ;
unsigned long V_15 ;
int V_91 ;
if ( ! V_12 )
return 0 ;
V_13 = F_39 ( V_90 * sizeof( * V_13 ) , V_89 ) ;
if ( ! V_13 )
return 0 ;
F_7 ( & V_12 -> V_21 , V_15 ) ;
for ( V_91 = 0 ; V_91 < V_90 ; V_91 ++ ) {
F_36 ( & V_13 [ V_91 ] ) ;
F_35 ( & V_13 [ V_91 ] . V_41 , & V_12 -> V_22 ) ;
}
F_9 ( & V_12 -> V_21 , V_15 ) ;
return V_90 ;
}
static struct V_5 *
F_40 ( struct V_11 * V_12 )
{
struct V_5 * V_13 = NULL ;
unsigned long V_15 ;
if ( ! V_12 )
return NULL ;
F_7 ( & V_12 -> V_21 , V_15 ) ;
if ( ! F_5 ( & V_12 -> V_22 ) ) {
V_13 = F_34 ( V_12 -> V_22 . V_74 ,
struct V_5 , V_41 ) ;
F_41 ( & V_13 -> V_41 ) ;
V_13 -> V_23 = V_24 ;
V_13 -> V_8 . V_16 = NULL ;
}
F_9 ( & V_12 -> V_21 , V_15 ) ;
return V_13 ;
}
static struct V_5 * F_42 ( struct V_1 * V_14 )
{
struct V_11 * V_12 = V_14 -> V_20 ;
struct V_92 * V_93 = V_14 -> V_4 . V_94 ;
struct V_5 * V_13 ;
V_13 = F_40 ( V_12 ) ;
if ( ! V_13 ) {
if ( ! F_38 ( V_12 , V_95 , 1 ) )
return NULL ;
V_13 = F_40 ( V_12 ) ;
if ( ! V_13 ) {
F_13 ( V_14 -> V_20 -> V_33 . V_34 ,
L_3 , V_35 , __LINE__ ) ;
return NULL ;
}
}
V_13 -> V_18 = V_14 ;
V_13 -> V_8 . V_36 = 0 ;
F_43 ( & V_13 -> V_8 ) ;
if ( V_93 ) {
V_13 -> V_30 . V_96 = V_93 -> V_96 ;
V_13 -> V_30 . V_93 = V_14 -> V_4 . V_97 ;
} else {
V_13 -> V_30 . V_96 = V_98 ;
V_13 -> V_30 . V_93 = 0 ;
}
F_44 ( & V_13 -> V_8 , & V_14 -> V_4 ) ;
return V_13 ;
}
static inline void F_45 ( struct V_99 * V_76 ,
T_4 V_100 , T_4 V_101 , T_5 V_102 )
{
V_76 -> V_74 = NULL ;
V_76 -> V_103 = V_102 ;
V_76 -> V_57 = V_100 ;
V_76 -> V_64 = V_101 ;
}
static struct V_5 *
F_46 ( struct V_1 * V_14 , T_4 V_100 ,
T_4 V_101 , T_5 V_102 )
{
struct V_5 * V_13 = F_42 ( V_14 ) ;
if ( ! V_13 ) {
F_13 ( V_14 -> V_20 -> V_33 . V_34 , L_4 ,
V_35 , __LINE__ ) ;
return NULL ;
}
F_45 ( & V_13 -> V_76 , V_100 , V_101 , V_102 ) ;
return V_13 ;
}
static inline int F_47 ( struct V_5 * V_13 , T_5 V_102 )
{
struct V_1 * V_14 = V_13 -> V_18 ;
struct V_104 * V_105 = & V_14 -> V_20 -> V_33 ;
int V_62 ;
V_62 = V_105 -> V_106 . V_107 / 8 ;
V_62 *= V_105 -> V_106 . V_108 ;
V_62 >>= V_13 -> V_77 . V_109 ;
if ( V_62 > 16 )
V_62 = 16 ;
while ( V_62 > 1 ) {
if ( ! ( V_102 % ( V_62 << V_13 -> V_77 . V_109 ) ) )
break;
V_62 -- ;
}
return V_62 ;
}
static struct V_6 * F_48 (
struct V_2 * V_4 , T_4 V_110 , T_5 V_102 ,
T_5 V_111 , enum V_112 V_55 )
{
struct V_5 * V_13 ;
struct V_1 * V_14 = F_1 ( V_4 ) ;
T_4 V_100 ;
T_4 V_101 ;
V_13 = F_42 ( V_14 ) ;
if ( ! V_13 ) {
F_13 ( V_14 -> V_20 -> V_33 . V_34 , L_4 ,
V_35 , __LINE__ ) ;
return NULL ;
}
switch ( V_55 ) {
case V_56 :
V_13 -> V_77 . V_113 = 1 ;
V_13 -> V_77 . V_114 = 0 ;
V_101 = V_110 ;
V_100 = V_14 -> V_58 ;
break;
case V_63 :
V_13 -> V_77 . V_113 = 0 ;
V_13 -> V_77 . V_114 = 1 ;
V_101 = V_14 -> V_58 ;
V_100 = V_110 ;
break;
default:
F_13 ( V_14 -> V_20 -> V_33 . V_34 , L_5 ,
V_35 , __LINE__ ) ;
return NULL ;
}
V_13 -> V_77 . V_109 = V_14 -> V_60 ;
V_13 -> V_77 . V_115 = 1 ;
V_14 -> V_43 = true ;
F_45 ( & V_13 -> V_76 , V_100 , V_101 , V_111 ) ;
return & V_13 -> V_8 ;
}
static struct V_6 *
F_49 ( struct V_2 * V_4 , T_4 V_100 ,
T_4 V_101 , T_5 V_102 , unsigned long V_15 )
{
struct V_5 * V_13 ;
struct V_1 * V_14 = F_1 ( V_4 ) ;
struct V_92 * V_93 = V_4 -> V_94 ;
struct V_104 * V_105 ;
int V_116 ;
if ( F_50 ( ! V_14 || ! V_102 ) )
return NULL ;
if ( V_93 && V_93 -> V_96 != V_98 )
return NULL ;
V_105 = & V_14 -> V_20 -> V_33 ;
V_13 = F_46 ( V_14 , V_100 , V_101 , V_102 ) ;
if ( ! V_13 )
return NULL ;
V_13 -> V_77 . V_113 = 1 ;
V_13 -> V_77 . V_114 = 1 ;
V_116 = V_105 -> V_106 . V_107 / 8 ;
while ( V_116 > 1 ) {
if ( ! ( V_102 % V_116 ) )
break;
V_116 /= 2 ;
}
V_13 -> V_77 . V_109 = 0 ;
while ( V_116 != ( 1 << V_13 -> V_77 . V_109 ) )
V_13 -> V_77 . V_109 ++ ;
V_13 -> V_77 . V_115 = F_47 ( V_13 , V_102 ) ;
V_13 -> V_8 . V_15 = V_15 ;
return & V_13 -> V_8 ;
}
static struct V_6 *
F_51 ( struct V_2 * V_4 , struct V_117 * V_118 ,
unsigned int V_119 , enum V_112 V_55 ,
unsigned long V_89 )
{
struct V_5 * V_120 , * V_13 = NULL ;
struct V_1 * V_14 = F_1 ( V_4 ) ;
struct V_92 * V_93 = V_4 -> V_94 ;
struct V_117 * V_121 ;
unsigned long V_15 ;
int V_91 ;
T_4 V_122 ;
if ( F_50 ( ! V_14 || ! V_118 || ! V_119 || ! V_93 ) )
return NULL ;
if ( ( V_55 == V_56 &&
V_93 -> V_96 != V_123 ) ||
( V_55 == V_63 &&
V_93 -> V_96 != V_124 ) ) {
F_13 ( V_14 -> V_20 -> V_33 . V_34 , L_6 ,
V_35 , __LINE__ ) ;
return NULL ;
}
V_122 = V_14 -> V_58 ;
V_120 = NULL ;
F_52 (sgl, sg, sg_len, i) {
V_13 = F_42 ( V_14 ) ;
if ( ! V_13 ) {
struct V_11 * V_12 = V_14 -> V_20 ;
F_13 ( V_14 -> V_20 -> V_33 . V_34 ,
L_4 ,
V_35 , __LINE__ ) ;
if ( ! V_120 )
return NULL ;
F_7 ( & V_12 -> V_21 , V_15 ) ;
while ( ! F_5 ( & V_120 -> V_41 ) ) {
V_13 = F_34 ( V_120 -> V_41 . V_74 ,
struct V_5 , V_41 ) ;
F_18 ( & V_13 -> V_41 , & V_12 -> V_22 ) ;
}
F_18 ( & V_120 -> V_41 , & V_12 -> V_22 ) ;
F_9 ( & V_12 -> V_21 , V_15 ) ;
return NULL ;
}
if ( ! V_120 )
V_120 = V_13 ;
else
F_35 ( & V_13 -> V_41 , & V_120 -> V_41 ) ;
if ( V_55 == V_56 ) {
V_13 -> V_77 . V_113 = 1 ;
V_13 -> V_77 . V_114 = 0 ;
F_45 ( & V_13 -> V_76 ,
V_122 , F_53 ( V_121 ) , F_54 ( V_121 ) ) ;
} else {
V_13 -> V_77 . V_113 = 0 ;
V_13 -> V_77 . V_114 = 1 ;
F_45 ( & V_13 -> V_76 ,
F_53 ( V_121 ) , V_122 , F_54 ( V_121 ) ) ;
}
V_13 -> V_77 . V_109 = V_14 -> V_60 ;
V_13 -> V_77 . V_115 = 1 ;
}
V_13 -> V_8 . V_15 = V_89 ;
return & V_13 -> V_8 ;
}
static T_6 F_55 ( int V_125 , void * V_38 )
{
if ( F_56 ( V_38 ) )
return V_126 ;
else
return V_127 ;
}
static int T_7
F_57 ( struct V_128 * V_129 , const struct V_130 * V_131 )
{
struct V_132 * V_133 ;
struct V_11 * V_12 ;
struct V_1 * V_14 ;
struct V_104 * V_105 ;
struct V_134 * V_135 ;
struct V_136 * V_137 ;
int V_91 , V_27 , V_125 ;
int V_138 ;
V_133 = V_129 -> V_34 . V_139 ;
V_12 = F_58 ( sizeof( * V_12 ) , V_140 ) ;
if ( ! V_12 ) {
F_13 ( & V_129 -> V_34 , L_7 ) ;
return - V_141 ;
}
V_105 = & V_12 -> V_33 ;
V_105 -> V_34 = & V_129 -> V_34 ;
V_105 -> V_142 = NULL ;
V_105 -> V_143 = V_133 ? V_133 -> V_144 : 0 ;
V_137 = & V_129 -> V_137 ;
F_59 ( V_137 -> V_145 , F_60 ( V_137 ) , L_8 ) ;
V_105 -> V_146 = F_61 ( V_137 -> V_145 , F_60 ( V_137 ) ) ;
if ( ! V_105 -> V_146 ) {
V_27 = - V_67 ;
goto V_147;
}
V_12 -> V_148 = F_62 ( & V_129 -> V_34 , L_9 ) ;
if ( F_63 ( V_12 -> V_148 ) ) {
F_13 ( & V_129 -> V_34 , L_10 ) ;
V_27 = - V_149 ;
goto V_147;
}
F_64 ( V_129 , V_12 ) ;
#ifdef F_65
F_66 ( & V_129 -> V_34 ) ;
if ( F_67 ( & V_129 -> V_34 ) ) {
F_13 ( & V_129 -> V_34 , L_11 ) ;
V_27 = - V_150 ;
goto V_147;
}
#else
F_68 ( V_12 -> V_148 ) ;
#endif
V_125 = V_129 -> V_125 [ 0 ] ;
V_27 = F_69 ( V_125 , F_55 , 0 ,
F_70 ( & V_129 -> V_34 ) , V_105 ) ;
if ( V_27 )
goto V_151;
V_27 = F_71 ( V_105 ) ;
if ( V_27 )
goto V_152;
F_37 ( & V_12 -> V_22 ) ;
F_72 ( & V_12 -> V_21 ) ;
if ( ! F_38 ( V_12 , V_140 , V_153 ) )
F_73 ( & V_129 -> V_34 , L_12 ) ;
V_135 = & V_12 -> V_154 ;
F_37 ( & V_135 -> V_155 ) ;
V_138 = F_74 ( V_133 ? V_133 -> V_156 : 0 , ( V_157 ) V_105 -> V_106 . V_138 ) ;
V_12 -> V_158 = F_58 ( V_138 * sizeof( * V_14 ) , V_140 ) ;
for ( V_91 = 0 ; V_91 < V_138 ; V_91 ++ ) {
V_14 = & V_12 -> V_158 [ V_91 ] ;
if ( V_133 ) {
struct V_92 * V_93 = & V_133 -> V_93 [ V_91 ] ;
switch ( V_93 -> V_96 ) {
case V_98 :
F_75 ( V_159 , V_135 -> V_160 ) ;
break;
case V_123 :
case V_124 :
F_75 ( V_161 , V_135 -> V_160 ) ;
F_75 ( V_162 , V_135 -> V_160 ) ;
break;
default:
F_13 ( & V_129 -> V_34 , L_13 ) ;
continue;
}
V_14 -> V_4 . V_94 = V_93 ;
} else {
F_75 ( V_159 , V_135 -> V_160 ) ;
V_14 -> V_4 . V_94 = NULL ;
}
F_37 ( & V_14 -> V_26 ) ;
F_72 ( & V_14 -> V_25 ) ;
V_14 -> V_29 = NULL ;
V_14 -> V_4 . V_163 = V_135 ;
V_14 -> V_20 = V_12 ;
F_35 ( & V_14 -> V_4 . V_164 , & V_135 -> V_155 ) ;
}
V_135 -> V_34 = & V_129 -> V_34 ;
V_135 -> V_165 = F_21 ;
V_135 -> V_166 = F_26 ;
V_135 -> V_167 = F_49 ;
V_135 -> V_168 = F_48 ;
V_135 -> V_169 = F_29 ;
V_135 -> V_170 = F_51 ;
V_135 -> V_171 = F_24 ;
V_135 -> V_172 = F_32 ;
V_27 = F_76 ( V_135 ) ;
if ( V_27 ) {
F_13 ( & V_129 -> V_34 , L_14 ) ;
goto V_173;
}
F_77 ( & V_129 -> V_34 ,
L_15 , V_129 -> V_174 ) ;
F_77 ( & V_129 -> V_34 ,
L_16 ,
V_105 -> V_106 . V_108 ,
V_105 -> V_106 . V_107 / 8 , V_105 -> V_106 . V_138 ,
V_105 -> V_106 . V_175 , V_105 -> V_106 . V_176 ) ;
return 0 ;
V_173:
F_78 ( V_105 ) ;
V_152:
F_79 ( V_125 , V_105 ) ;
V_151:
F_80 ( V_105 -> V_146 ) ;
V_147:
F_81 ( V_137 -> V_145 , F_60 ( V_137 ) ) ;
F_82 ( V_12 ) ;
return V_27 ;
}
static int T_8 F_83 ( struct V_128 * V_129 )
{
struct V_11 * V_12 = F_84 ( V_129 ) ;
struct V_1 * V_14 , * V_177 ;
struct V_104 * V_105 ;
struct V_136 * V_137 ;
int V_125 ;
if ( ! V_12 )
return 0 ;
F_64 ( V_129 , NULL ) ;
F_17 (pch, _p, &pdmac->ddma.channels,
chan.device_node) {
F_85 ( & V_14 -> V_4 . V_164 ) ;
F_24 ( & V_14 -> V_4 , V_52 , 0 ) ;
F_26 ( & V_14 -> V_4 ) ;
}
V_105 = & V_12 -> V_33 ;
F_78 ( V_105 ) ;
V_125 = V_129 -> V_125 [ 0 ] ;
F_79 ( V_125 , V_105 ) ;
F_80 ( V_105 -> V_146 ) ;
V_137 = & V_129 -> V_137 ;
F_81 ( V_137 -> V_145 , F_60 ( V_137 ) ) ;
#ifdef F_65
F_86 ( & V_129 -> V_34 ) ;
F_87 ( & V_129 -> V_34 ) ;
#else
F_88 ( V_12 -> V_148 ) ;
#endif
F_82 ( V_12 ) ;
return 0 ;
}
static int F_89 ( struct V_163 * V_34 )
{
struct V_11 * V_12 = F_90 ( V_34 ) ;
if ( ! V_12 ) {
F_13 ( V_34 , L_17 ) ;
return - V_150 ;
}
F_88 ( V_12 -> V_148 ) ;
return 0 ;
}
static int F_91 ( struct V_163 * V_34 )
{
struct V_11 * V_12 = F_90 ( V_34 ) ;
if ( ! V_12 ) {
F_13 ( V_34 , L_17 ) ;
return - V_150 ;
}
F_68 ( V_12 -> V_148 ) ;
return 0 ;
}
static int T_9 F_92 ( void )
{
return F_93 ( & V_178 ) ;
}
static void T_10 F_94 ( void )
{
F_95 ( & V_178 ) ;
return;
}
