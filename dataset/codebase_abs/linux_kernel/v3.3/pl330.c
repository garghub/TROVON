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
bool F_21 ( struct V_2 * V_4 , void * V_17 )
{
T_2 * V_47 ;
if ( V_4 -> V_48 -> V_34 -> V_49 != & V_50 . V_51 )
return false ;
#ifdef F_22
if ( V_4 -> V_48 -> V_34 -> V_52 ) {
const T_3 * V_53 ;
T_4 T_4 ;
struct V_54 * V_41 ;
V_53 = ( (struct V_55 * ) V_17 ) -> V_56 ;
T_4 = F_23 ( V_53 ++ ) ;
V_41 = F_24 ( T_4 ) ;
return ( ( V_4 -> V_57 == V_41 ) &&
( V_4 -> V_58 == F_23 ( V_53 ) ) ) ;
}
#endif
V_47 = V_4 -> V_57 ;
return * V_47 == ( unsigned ) V_17 ;
}
static int F_25 ( struct V_2 * V_4 )
{
struct V_1 * V_14 = F_1 ( V_4 ) ;
struct V_11 * V_12 = V_14 -> V_20 ;
unsigned long V_15 ;
F_7 ( & V_14 -> V_25 , V_15 ) ;
V_14 -> V_40 = V_4 -> V_36 = 1 ;
V_14 -> V_43 = false ;
V_14 -> V_29 = F_26 ( & V_12 -> V_33 ) ;
if ( ! V_14 -> V_29 ) {
F_9 ( & V_14 -> V_25 , V_15 ) ;
return 0 ;
}
F_27 ( & V_14 -> V_37 , F_15 , ( unsigned long ) V_14 ) ;
F_9 ( & V_14 -> V_25 , V_15 ) ;
return 1 ;
}
static int F_28 ( struct V_2 * V_4 , enum V_59 V_60 , unsigned long V_61 )
{
struct V_1 * V_14 = F_1 ( V_4 ) ;
struct V_5 * V_13 , * V_39 ;
unsigned long V_15 ;
struct V_11 * V_12 = V_14 -> V_20 ;
struct V_62 * V_63 ;
F_16 ( V_10 ) ;
switch ( V_60 ) {
case V_64 :
F_7 ( & V_14 -> V_25 , V_15 ) ;
F_19 ( V_14 -> V_29 , V_65 ) ;
F_17 (desc, _dt, &pch->work_list , node) {
V_13 -> V_23 = V_32 ;
V_14 -> V_40 = V_13 -> V_8 . V_36 ;
F_18 ( & V_13 -> V_41 , & V_10 ) ;
}
F_8 ( & V_10 , & V_12 -> V_22 ) ;
F_9 ( & V_14 -> V_25 , V_15 ) ;
break;
case V_66 :
V_63 = (struct V_62 * ) V_61 ;
if ( V_63 -> V_67 == V_68 ) {
if ( V_63 -> V_69 )
V_14 -> V_70 = V_63 -> V_69 ;
if ( V_63 -> V_71 )
V_14 -> V_72 = F_29 ( V_63 -> V_71 ) ;
if ( V_63 -> V_73 )
V_14 -> V_74 = V_63 -> V_73 ;
} else if ( V_63 -> V_67 == V_75 ) {
if ( V_63 -> V_76 )
V_14 -> V_70 = V_63 -> V_76 ;
if ( V_63 -> V_77 )
V_14 -> V_72 = F_29 ( V_63 -> V_77 ) ;
if ( V_63 -> V_78 )
V_14 -> V_74 = V_63 -> V_78 ;
}
break;
default:
F_13 ( V_14 -> V_20 -> V_33 . V_34 , L_2 ) ;
return - V_79 ;
}
return 0 ;
}
static void F_30 ( struct V_2 * V_4 )
{
struct V_1 * V_14 = F_1 ( V_4 ) ;
unsigned long V_15 ;
F_7 ( & V_14 -> V_25 , V_15 ) ;
F_31 ( & V_14 -> V_37 ) ;
F_32 ( V_14 -> V_29 ) ;
V_14 -> V_29 = NULL ;
if ( V_14 -> V_43 )
F_8 ( & V_14 -> V_26 , & V_14 -> V_20 -> V_22 ) ;
F_9 ( & V_14 -> V_25 , V_15 ) ;
}
static enum V_80
F_33 ( struct V_2 * V_4 , T_5 V_36 ,
struct V_81 * V_82 )
{
struct V_1 * V_14 = F_1 ( V_4 ) ;
T_5 V_83 , V_84 ;
int V_27 ;
V_83 = V_14 -> V_40 ;
V_84 = V_4 -> V_36 ;
V_27 = F_34 ( V_36 , V_83 , V_84 ) ;
F_35 ( V_82 , V_83 , V_84 , 0 ) ;
return V_27 ;
}
static void F_36 ( struct V_2 * V_4 )
{
F_15 ( ( unsigned long ) F_1 ( V_4 ) ) ;
}
static T_5 F_37 ( struct V_6 * V_7 )
{
struct V_5 * V_13 , * V_85 = F_3 ( V_7 ) ;
struct V_1 * V_14 = F_1 ( V_7 -> V_4 ) ;
T_5 V_36 ;
unsigned long V_15 ;
F_7 ( & V_14 -> V_25 , V_15 ) ;
V_36 = V_7 -> V_4 -> V_36 ;
while ( ! F_5 ( & V_85 -> V_41 ) ) {
V_13 = F_38 ( V_85 -> V_41 . V_86 , struct V_5 , V_41 ) ;
if ( ++ V_36 < 0 )
V_36 = 1 ;
V_13 -> V_8 . V_36 = V_36 ;
F_18 ( & V_13 -> V_41 , & V_14 -> V_26 ) ;
}
if ( ++ V_36 < 0 )
V_36 = 1 ;
V_85 -> V_8 . V_36 = V_36 ;
F_39 ( & V_85 -> V_41 , & V_14 -> V_26 ) ;
V_7 -> V_4 -> V_36 = V_36 ;
F_9 ( & V_14 -> V_25 , V_15 ) ;
return V_36 ;
}
static inline void F_40 ( struct V_5 * V_13 )
{
V_13 -> V_18 = NULL ;
V_13 -> V_30 . V_87 = & V_13 -> V_88 ;
V_13 -> V_30 . V_44 = V_13 ;
V_13 -> V_89 . V_90 = V_91 ;
V_13 -> V_89 . V_92 = 0 ;
V_13 -> V_89 . V_93 = 0 ;
V_13 -> V_89 . V_94 = V_95 ;
V_13 -> V_89 . V_96 = V_97 ;
V_13 -> V_30 . V_98 = & V_13 -> V_89 ;
V_13 -> V_30 . V_99 = F_20 ;
V_13 -> V_8 . V_100 = F_37 ;
F_41 ( & V_13 -> V_41 ) ;
}
int F_42 ( struct V_11 * V_12 , T_6 V_101 , int V_102 )
{
struct V_5 * V_13 ;
unsigned long V_15 ;
int V_103 ;
if ( ! V_12 )
return 0 ;
V_13 = F_43 ( V_102 * sizeof( * V_13 ) , V_101 ) ;
if ( ! V_13 )
return 0 ;
F_7 ( & V_12 -> V_21 , V_15 ) ;
for ( V_103 = 0 ; V_103 < V_102 ; V_103 ++ ) {
F_40 ( & V_13 [ V_103 ] ) ;
F_39 ( & V_13 [ V_103 ] . V_41 , & V_12 -> V_22 ) ;
}
F_9 ( & V_12 -> V_21 , V_15 ) ;
return V_102 ;
}
static struct V_5 *
F_44 ( struct V_11 * V_12 )
{
struct V_5 * V_13 = NULL ;
unsigned long V_15 ;
if ( ! V_12 )
return NULL ;
F_7 ( & V_12 -> V_21 , V_15 ) ;
if ( ! F_5 ( & V_12 -> V_22 ) ) {
V_13 = F_38 ( V_12 -> V_22 . V_86 ,
struct V_5 , V_41 ) ;
F_45 ( & V_13 -> V_41 ) ;
V_13 -> V_23 = V_24 ;
V_13 -> V_8 . V_16 = NULL ;
}
F_9 ( & V_12 -> V_21 , V_15 ) ;
return V_13 ;
}
static struct V_5 * F_46 ( struct V_1 * V_14 )
{
struct V_11 * V_12 = V_14 -> V_20 ;
T_2 * V_47 = V_14 -> V_4 . V_57 ;
struct V_5 * V_13 ;
V_13 = F_44 ( V_12 ) ;
if ( ! V_13 ) {
if ( ! F_42 ( V_12 , V_104 , 1 ) )
return NULL ;
V_13 = F_44 ( V_12 ) ;
if ( ! V_13 ) {
F_13 ( V_14 -> V_20 -> V_33 . V_34 ,
L_3 , V_35 , __LINE__ ) ;
return NULL ;
}
}
V_13 -> V_18 = V_14 ;
V_13 -> V_8 . V_36 = 0 ;
F_47 ( & V_13 -> V_8 ) ;
V_13 -> V_30 . V_105 = V_47 ? V_14 -> V_4 . V_58 : 0 ;
F_48 ( & V_13 -> V_8 , & V_14 -> V_4 ) ;
return V_13 ;
}
static inline void F_49 ( struct V_106 * V_88 ,
T_7 V_107 , T_7 V_108 , T_8 V_109 )
{
V_88 -> V_86 = NULL ;
V_88 -> V_110 = V_109 ;
V_88 -> V_69 = V_107 ;
V_88 -> V_76 = V_108 ;
}
static struct V_5 *
F_50 ( struct V_1 * V_14 , T_7 V_107 ,
T_7 V_108 , T_8 V_109 )
{
struct V_5 * V_13 = F_46 ( V_14 ) ;
if ( ! V_13 ) {
F_13 ( V_14 -> V_20 -> V_33 . V_34 , L_4 ,
V_35 , __LINE__ ) ;
return NULL ;
}
F_49 ( & V_13 -> V_88 , V_107 , V_108 , V_109 ) ;
return V_13 ;
}
static inline int F_51 ( struct V_5 * V_13 , T_8 V_109 )
{
struct V_1 * V_14 = V_13 -> V_18 ;
struct V_111 * V_112 = & V_14 -> V_20 -> V_33 ;
int V_74 ;
V_74 = V_112 -> V_113 . V_114 / 8 ;
V_74 *= V_112 -> V_113 . V_115 ;
V_74 >>= V_13 -> V_89 . V_116 ;
if ( V_74 > 16 )
V_74 = 16 ;
while ( V_74 > 1 ) {
if ( ! ( V_109 % ( V_74 << V_13 -> V_89 . V_116 ) ) )
break;
V_74 -- ;
}
return V_74 ;
}
static struct V_6 * F_52 (
struct V_2 * V_4 , T_7 V_117 , T_8 V_109 ,
T_8 V_118 , enum V_119 V_67 )
{
struct V_5 * V_13 ;
struct V_1 * V_14 = F_1 ( V_4 ) ;
T_7 V_107 ;
T_7 V_108 ;
V_13 = F_46 ( V_14 ) ;
if ( ! V_13 ) {
F_13 ( V_14 -> V_20 -> V_33 . V_34 , L_4 ,
V_35 , __LINE__ ) ;
return NULL ;
}
switch ( V_67 ) {
case V_68 :
V_13 -> V_89 . V_120 = 1 ;
V_13 -> V_89 . V_121 = 0 ;
V_13 -> V_30 . V_122 = V_123 ;
V_108 = V_117 ;
V_107 = V_14 -> V_70 ;
break;
case V_75 :
V_13 -> V_89 . V_120 = 0 ;
V_13 -> V_89 . V_121 = 1 ;
V_13 -> V_30 . V_122 = V_124 ;
V_108 = V_14 -> V_70 ;
V_107 = V_117 ;
break;
default:
F_13 ( V_14 -> V_20 -> V_33 . V_34 , L_5 ,
V_35 , __LINE__ ) ;
return NULL ;
}
V_13 -> V_89 . V_116 = V_14 -> V_72 ;
V_13 -> V_89 . V_125 = 1 ;
V_14 -> V_43 = true ;
F_49 ( & V_13 -> V_88 , V_107 , V_108 , V_118 ) ;
return & V_13 -> V_8 ;
}
static struct V_6 *
F_53 ( struct V_2 * V_4 , T_7 V_107 ,
T_7 V_108 , T_8 V_109 , unsigned long V_15 )
{
struct V_5 * V_13 ;
struct V_1 * V_14 = F_1 ( V_4 ) ;
struct V_111 * V_112 ;
int V_126 ;
if ( F_54 ( ! V_14 || ! V_109 ) )
return NULL ;
V_112 = & V_14 -> V_20 -> V_33 ;
V_13 = F_50 ( V_14 , V_107 , V_108 , V_109 ) ;
if ( ! V_13 )
return NULL ;
V_13 -> V_89 . V_120 = 1 ;
V_13 -> V_89 . V_121 = 1 ;
V_13 -> V_30 . V_122 = V_127 ;
V_126 = V_112 -> V_113 . V_114 / 8 ;
while ( V_126 > 1 ) {
if ( ! ( V_109 % V_126 ) )
break;
V_126 /= 2 ;
}
V_13 -> V_89 . V_116 = 0 ;
while ( V_126 != ( 1 << V_13 -> V_89 . V_116 ) )
V_13 -> V_89 . V_116 ++ ;
V_13 -> V_89 . V_125 = F_51 ( V_13 , V_109 ) ;
V_13 -> V_8 . V_15 = V_15 ;
return & V_13 -> V_8 ;
}
static struct V_6 *
F_55 ( struct V_2 * V_4 , struct V_128 * V_129 ,
unsigned int V_130 , enum V_119 V_67 ,
unsigned long V_101 )
{
struct V_5 * V_131 , * V_13 = NULL ;
struct V_1 * V_14 = F_1 ( V_4 ) ;
struct V_128 * V_132 ;
unsigned long V_15 ;
int V_103 ;
T_7 V_133 ;
if ( F_54 ( ! V_14 || ! V_129 || ! V_130 ) )
return NULL ;
V_133 = V_14 -> V_70 ;
V_131 = NULL ;
F_56 (sgl, sg, sg_len, i) {
V_13 = F_46 ( V_14 ) ;
if ( ! V_13 ) {
struct V_11 * V_12 = V_14 -> V_20 ;
F_13 ( V_14 -> V_20 -> V_33 . V_34 ,
L_4 ,
V_35 , __LINE__ ) ;
if ( ! V_131 )
return NULL ;
F_7 ( & V_12 -> V_21 , V_15 ) ;
while ( ! F_5 ( & V_131 -> V_41 ) ) {
V_13 = F_38 ( V_131 -> V_41 . V_86 ,
struct V_5 , V_41 ) ;
F_18 ( & V_13 -> V_41 , & V_12 -> V_22 ) ;
}
F_18 ( & V_131 -> V_41 , & V_12 -> V_22 ) ;
F_9 ( & V_12 -> V_21 , V_15 ) ;
return NULL ;
}
if ( ! V_131 )
V_131 = V_13 ;
else
F_39 ( & V_13 -> V_41 , & V_131 -> V_41 ) ;
if ( V_67 == V_68 ) {
V_13 -> V_89 . V_120 = 1 ;
V_13 -> V_89 . V_121 = 0 ;
V_13 -> V_30 . V_122 = V_123 ;
F_49 ( & V_13 -> V_88 ,
V_133 , F_57 ( V_132 ) , F_58 ( V_132 ) ) ;
} else {
V_13 -> V_89 . V_120 = 0 ;
V_13 -> V_89 . V_121 = 1 ;
V_13 -> V_30 . V_122 = V_124 ;
F_49 ( & V_13 -> V_88 ,
F_57 ( V_132 ) , V_133 , F_58 ( V_132 ) ) ;
}
V_13 -> V_89 . V_116 = V_14 -> V_72 ;
V_13 -> V_89 . V_125 = 1 ;
}
V_13 -> V_8 . V_15 = V_101 ;
return & V_13 -> V_8 ;
}
static T_9 F_59 ( int V_134 , void * V_38 )
{
if ( F_60 ( V_38 ) )
return V_135 ;
else
return V_136 ;
}
static int T_10
F_61 ( struct V_137 * V_138 , const struct V_139 * V_140 )
{
struct V_141 * V_142 ;
struct V_11 * V_12 ;
struct V_1 * V_14 ;
struct V_111 * V_112 ;
struct V_143 * V_144 ;
struct V_145 * V_146 ;
int V_103 , V_27 , V_134 ;
int V_147 ;
V_142 = V_138 -> V_34 . V_148 ;
V_12 = F_62 ( sizeof( * V_12 ) , V_149 ) ;
if ( ! V_12 ) {
F_13 ( & V_138 -> V_34 , L_6 ) ;
return - V_150 ;
}
V_112 = & V_12 -> V_33 ;
V_112 -> V_34 = & V_138 -> V_34 ;
V_112 -> V_151 = NULL ;
V_112 -> V_152 = V_142 ? V_142 -> V_153 : 0 ;
V_146 = & V_138 -> V_146 ;
F_63 ( V_146 -> V_154 , F_64 ( V_146 ) , L_7 ) ;
V_112 -> V_155 = F_65 ( V_146 -> V_154 , F_64 ( V_146 ) ) ;
if ( ! V_112 -> V_155 ) {
V_27 = - V_79 ;
goto V_156;
}
V_12 -> V_157 = F_66 ( & V_138 -> V_34 , L_8 ) ;
if ( F_67 ( V_12 -> V_157 ) ) {
F_13 ( & V_138 -> V_34 , L_9 ) ;
V_27 = - V_158 ;
goto V_156;
}
F_68 ( V_138 , V_12 ) ;
#ifndef F_69
F_70 ( V_12 -> V_157 ) ;
#endif
V_134 = V_138 -> V_134 [ 0 ] ;
V_27 = F_71 ( V_134 , F_59 , 0 ,
F_72 ( & V_138 -> V_34 ) , V_112 ) ;
if ( V_27 )
goto V_159;
V_27 = F_73 ( V_112 ) ;
if ( V_27 )
goto V_160;
F_41 ( & V_12 -> V_22 ) ;
F_74 ( & V_12 -> V_21 ) ;
if ( ! F_42 ( V_12 , V_149 , V_161 ) )
F_75 ( & V_138 -> V_34 , L_10 ) ;
V_144 = & V_12 -> V_162 ;
F_41 ( & V_144 -> V_163 ) ;
V_147 = F_76 ( V_142 ? V_142 -> V_164 : ( T_2 ) V_112 -> V_113 . V_165 ,
( T_2 ) V_112 -> V_113 . V_147 ) ;
V_12 -> V_166 = F_62 ( V_147 * sizeof( * V_14 ) , V_149 ) ;
for ( V_103 = 0 ; V_103 < V_147 ; V_103 ++ ) {
V_14 = & V_12 -> V_166 [ V_103 ] ;
if ( ! V_138 -> V_34 . V_52 )
V_14 -> V_4 . V_57 = V_142 ? & V_142 -> V_47 [ V_103 ] : NULL ;
else
V_14 -> V_4 . V_57 = V_138 -> V_34 . V_52 ;
F_41 ( & V_14 -> V_26 ) ;
F_74 ( & V_14 -> V_25 ) ;
V_14 -> V_29 = NULL ;
V_14 -> V_4 . V_48 = V_144 ;
V_14 -> V_20 = V_12 ;
F_39 ( & V_14 -> V_4 . V_54 , & V_144 -> V_163 ) ;
}
V_144 -> V_34 = & V_138 -> V_34 ;
if ( V_142 ) {
V_144 -> V_167 = V_142 -> V_167 ;
} else {
F_77 ( V_168 , V_144 -> V_167 ) ;
if ( V_112 -> V_113 . V_165 ) {
F_77 ( V_169 , V_144 -> V_167 ) ;
F_77 ( V_170 , V_144 -> V_167 ) ;
}
}
V_144 -> V_171 = F_25 ;
V_144 -> V_172 = F_30 ;
V_144 -> V_173 = F_53 ;
V_144 -> V_174 = F_52 ;
V_144 -> V_175 = F_33 ;
V_144 -> V_176 = F_55 ;
V_144 -> V_177 = F_28 ;
V_144 -> V_178 = F_36 ;
V_27 = F_78 ( V_144 ) ;
if ( V_27 ) {
F_13 ( & V_138 -> V_34 , L_11 ) ;
goto V_179;
}
F_79 ( & V_138 -> V_34 ,
L_12 , V_138 -> V_180 ) ;
F_79 ( & V_138 -> V_34 ,
L_13 ,
V_112 -> V_113 . V_115 ,
V_112 -> V_113 . V_114 / 8 , V_112 -> V_113 . V_147 ,
V_112 -> V_113 . V_165 , V_112 -> V_113 . V_181 ) ;
return 0 ;
V_179:
F_80 ( V_112 ) ;
V_160:
F_81 ( V_134 , V_112 ) ;
V_159:
F_82 ( V_112 -> V_155 ) ;
V_156:
F_83 ( V_146 -> V_154 , F_64 ( V_146 ) ) ;
F_84 ( V_12 ) ;
return V_27 ;
}
static int T_11 F_85 ( struct V_137 * V_138 )
{
struct V_11 * V_12 = F_86 ( V_138 ) ;
struct V_1 * V_14 , * V_182 ;
struct V_111 * V_112 ;
struct V_145 * V_146 ;
int V_134 ;
if ( ! V_12 )
return 0 ;
F_68 ( V_138 , NULL ) ;
F_17 (pch, _p, &pdmac->ddma.channels,
chan.device_node) {
F_87 ( & V_14 -> V_4 . V_54 ) ;
F_28 ( & V_14 -> V_4 , V_64 , 0 ) ;
F_30 ( & V_14 -> V_4 ) ;
}
V_112 = & V_12 -> V_33 ;
F_80 ( V_112 ) ;
V_134 = V_138 -> V_134 [ 0 ] ;
F_81 ( V_134 , V_112 ) ;
F_82 ( V_112 -> V_155 ) ;
V_146 = & V_138 -> V_146 ;
F_83 ( V_146 -> V_154 , F_64 ( V_146 ) ) ;
#ifndef F_69
F_88 ( V_12 -> V_157 ) ;
#endif
F_84 ( V_12 ) ;
return 0 ;
}
static int F_89 ( struct V_48 * V_34 )
{
struct V_11 * V_12 = F_90 ( V_34 ) ;
if ( ! V_12 ) {
F_13 ( V_34 , L_14 ) ;
return - V_183 ;
}
F_88 ( V_12 -> V_157 ) ;
return 0 ;
}
static int F_91 ( struct V_48 * V_34 )
{
struct V_11 * V_12 = F_90 ( V_34 ) ;
if ( ! V_12 ) {
F_13 ( V_34 , L_14 ) ;
return - V_183 ;
}
F_70 ( V_12 -> V_157 ) ;
return 0 ;
}
static int T_12 F_92 ( void )
{
return F_93 ( & V_50 ) ;
}
static void T_13 F_94 ( void )
{
F_95 ( & V_50 ) ;
return;
}
