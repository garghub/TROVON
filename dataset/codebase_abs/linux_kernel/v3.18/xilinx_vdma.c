static inline T_1 F_1 ( struct V_1 * V_2 , T_1 V_3 )
{
return F_2 ( V_2 -> V_4 -> V_5 + V_3 ) ;
}
static inline void F_3 ( struct V_1 * V_2 , T_1 V_3 , T_1 V_6 )
{
F_4 ( V_6 , V_2 -> V_4 -> V_5 + V_3 ) ;
}
static inline void F_5 ( struct V_1 * V_2 , T_1 V_3 ,
T_1 V_6 )
{
F_3 ( V_2 , V_2 -> V_7 + V_3 , V_6 ) ;
}
static inline T_1 F_6 ( struct V_1 * V_2 , T_1 V_3 )
{
return F_1 ( V_2 , V_2 -> V_8 + V_3 ) ;
}
static inline void F_7 ( struct V_1 * V_2 , T_1 V_3 ,
T_1 V_6 )
{
F_3 ( V_2 , V_2 -> V_8 + V_3 , V_6 ) ;
}
static inline void F_8 ( struct V_1 * V_2 , T_1 V_3 ,
T_1 V_9 )
{
F_7 ( V_2 , V_3 , F_6 ( V_2 , V_3 ) & ~ V_9 ) ;
}
static inline void F_9 ( struct V_1 * V_2 , T_1 V_3 ,
T_1 V_10 )
{
F_7 ( V_2 , V_3 , F_6 ( V_2 , V_3 ) | V_10 ) ;
}
static struct V_11 *
F_10 ( struct V_1 * V_2 )
{
struct V_11 * V_12 ;
T_2 V_13 ;
V_12 = F_11 ( V_2 -> V_14 , V_15 , & V_13 ) ;
if ( ! V_12 )
return NULL ;
memset ( V_12 , 0 , sizeof( * V_12 ) ) ;
V_12 -> V_13 = V_13 ;
return V_12 ;
}
static void F_12 ( struct V_1 * V_2 ,
struct V_11 * V_12 )
{
F_13 ( V_2 -> V_14 , V_12 , V_12 -> V_13 ) ;
}
static struct V_16 *
F_14 ( struct V_1 * V_2 )
{
struct V_16 * V_17 ;
unsigned long V_18 ;
if ( V_2 -> V_19 )
return V_2 -> V_19 ;
V_17 = F_15 ( sizeof( * V_17 ) , V_20 ) ;
if ( ! V_17 )
return NULL ;
F_16 ( & V_2 -> V_21 , V_18 ) ;
V_2 -> V_19 = V_17 ;
F_17 ( & V_2 -> V_21 , V_18 ) ;
F_18 ( & V_17 -> V_22 ) ;
return V_17 ;
}
static void
F_19 ( struct V_1 * V_2 ,
struct V_16 * V_17 )
{
struct V_11 * V_12 , * V_23 ;
if ( ! V_17 )
return;
F_20 (segment, next, &desc->segments, node) {
F_21 ( & V_12 -> V_24 ) ;
F_12 ( V_2 , V_12 ) ;
}
F_22 ( V_17 ) ;
}
static void F_23 ( struct V_1 * V_2 ,
struct V_25 * V_26 )
{
struct V_16 * V_17 , * V_23 ;
F_20 (desc, next, list, node) {
F_21 ( & V_17 -> V_24 ) ;
F_19 ( V_2 , V_17 ) ;
}
}
static void F_24 ( struct V_1 * V_2 )
{
unsigned long V_18 ;
F_16 ( & V_2 -> V_21 , V_18 ) ;
F_23 ( V_2 , & V_2 -> V_27 ) ;
F_23 ( V_2 , & V_2 -> V_28 ) ;
F_19 ( V_2 , V_2 -> V_29 ) ;
V_2 -> V_29 = NULL ;
F_17 ( & V_2 -> V_21 , V_18 ) ;
}
static void F_25 ( struct V_30 * V_31 )
{
struct V_1 * V_2 = F_26 ( V_31 ) ;
F_27 ( V_2 -> V_32 , L_1 ) ;
F_24 ( V_2 ) ;
F_28 ( V_2 -> V_14 ) ;
V_2 -> V_14 = NULL ;
}
static void F_29 ( struct V_1 * V_2 )
{
struct V_16 * V_17 , * V_23 ;
unsigned long V_18 ;
F_16 ( & V_2 -> V_21 , V_18 ) ;
F_20 (desc, next, &chan->done_list, node) {
T_3 V_33 ;
void * V_34 ;
F_21 ( & V_17 -> V_24 ) ;
V_33 = V_17 -> V_35 . V_33 ;
V_34 = V_17 -> V_35 . V_34 ;
if ( V_33 ) {
F_17 ( & V_2 -> V_21 , V_18 ) ;
V_33 ( V_34 ) ;
F_16 ( & V_2 -> V_21 , V_18 ) ;
}
F_30 ( & V_17 -> V_35 ) ;
F_19 ( V_2 , V_17 ) ;
}
F_17 ( & V_2 -> V_21 , V_18 ) ;
}
static void F_31 ( unsigned long V_36 )
{
struct V_1 * V_2 = (struct V_1 * ) V_36 ;
F_29 ( V_2 ) ;
}
static int F_32 ( struct V_30 * V_31 )
{
struct V_1 * V_2 = F_26 ( V_31 ) ;
if ( V_2 -> V_14 )
return 0 ;
V_2 -> V_14 = F_33 ( L_2 ,
V_2 -> V_32 ,
sizeof( struct V_11 ) ,
F_34 ( struct V_11 ) , 0 ) ;
if ( ! V_2 -> V_14 ) {
F_35 ( V_2 -> V_32 ,
L_3 ,
V_2 -> V_37 ) ;
return - V_38 ;
}
F_36 ( V_31 ) ;
return 0 ;
}
static enum V_39 F_37 ( struct V_30 * V_31 ,
T_4 V_40 ,
struct V_41 * V_42 )
{
return F_38 ( V_31 , V_40 , V_42 ) ;
}
static bool F_39 ( struct V_1 * V_2 )
{
return ! ( F_6 ( V_2 , V_43 ) &
V_44 ) &&
( F_6 ( V_2 , V_45 ) &
V_46 ) ;
}
static bool F_40 ( struct V_1 * V_2 )
{
return F_6 ( V_2 , V_43 ) &
V_47 ;
}
static void F_41 ( struct V_1 * V_2 )
{
int V_48 = V_49 ;
F_8 ( V_2 , V_45 , V_46 ) ;
do {
if ( F_6 ( V_2 , V_43 ) &
V_44 )
break;
} while ( V_48 -- );
if ( ! V_48 ) {
F_35 ( V_2 -> V_32 , L_4 ,
V_2 , F_6 ( V_2 , V_43 ) ) ;
V_2 -> V_50 = true ;
}
return;
}
static void F_42 ( struct V_1 * V_2 )
{
int V_48 = V_49 ;
F_9 ( V_2 , V_45 , V_46 ) ;
do {
if ( ! ( F_6 ( V_2 , V_43 ) &
V_44 ) )
break;
} while ( V_48 -- );
if ( ! V_48 ) {
F_35 ( V_2 -> V_32 , L_5 ,
V_2 , F_6 ( V_2 , V_43 ) ) ;
V_2 -> V_50 = true ;
}
return;
}
static void F_43 ( struct V_1 * V_2 )
{
struct V_51 * V_52 = & V_2 -> V_52 ;
struct V_16 * V_17 ;
unsigned long V_18 ;
T_1 V_3 ;
struct V_11 * V_53 , * V_54 = NULL ;
if ( V_2 -> V_50 )
return;
F_16 ( & V_2 -> V_21 , V_18 ) ;
if ( V_2 -> V_29 )
goto V_55;
if ( F_44 ( & V_2 -> V_27 ) )
goto V_55;
V_17 = F_45 ( & V_2 -> V_27 ,
struct V_16 , V_24 ) ;
if ( V_2 -> V_56 && F_39 ( V_2 ) &&
! F_40 ( V_2 ) ) {
F_27 ( V_2 -> V_32 , L_6 ) ;
goto V_55;
}
if ( V_2 -> V_56 ) {
V_53 = F_45 ( & V_17 -> V_22 ,
struct V_11 , V_24 ) ;
V_54 = F_46 ( V_17 -> V_22 . V_57 ,
struct V_11 , V_24 ) ;
F_7 ( V_2 , V_58 , V_53 -> V_13 ) ;
}
V_3 = F_6 ( V_2 , V_45 ) ;
if ( V_52 -> V_59 )
V_3 |= V_60 ;
else
V_3 &= ~ V_60 ;
if ( V_2 -> V_56 || ! V_52 -> V_61 )
V_3 |= V_62 ;
if ( V_52 -> V_61 )
V_3 &= ~ V_62 ;
F_7 ( V_2 , V_45 , V_3 ) ;
if ( V_52 -> V_61 && ( V_52 -> V_63 >= 0 ) &&
( V_52 -> V_63 < V_2 -> V_64 ) ) {
if ( V_2 -> V_65 == V_66 )
F_3 ( V_2 , V_67 ,
V_52 -> V_63 <<
V_68 ) ;
else
F_3 ( V_2 , V_67 ,
V_52 -> V_63 <<
V_69 ) ;
}
F_42 ( V_2 ) ;
if ( V_2 -> V_50 )
goto V_55;
if ( V_2 -> V_56 ) {
F_7 ( V_2 , V_70 , V_54 -> V_13 ) ;
} else {
struct V_11 * V_12 , * V_71 = NULL ;
int V_72 = 0 ;
F_47 (segment, &desc->segments, node) {
F_5 ( V_2 ,
F_48 ( V_72 ++ ) ,
V_12 -> V_73 . V_74 ) ;
V_71 = V_12 ;
}
if ( ! V_71 )
goto V_55;
F_5 ( V_2 , V_75 , V_71 -> V_73 . V_76 ) ;
F_5 ( V_2 , V_77 ,
V_71 -> V_73 . V_78 ) ;
F_5 ( V_2 , V_79 , V_71 -> V_73 . V_80 ) ;
}
F_21 ( & V_17 -> V_24 ) ;
V_2 -> V_29 = V_17 ;
V_55:
F_17 ( & V_2 -> V_21 , V_18 ) ;
}
static void F_49 ( struct V_30 * V_31 )
{
struct V_1 * V_2 = F_26 ( V_31 ) ;
F_43 ( V_2 ) ;
}
static void F_50 ( struct V_1 * V_2 )
{
struct V_16 * V_17 ;
unsigned long V_18 ;
F_16 ( & V_2 -> V_21 , V_18 ) ;
V_17 = V_2 -> V_29 ;
if ( ! V_17 ) {
F_27 ( V_2 -> V_32 , L_7 ) ;
goto V_55;
}
F_51 ( & V_17 -> V_35 ) ;
F_52 ( & V_17 -> V_24 , & V_2 -> V_28 ) ;
V_2 -> V_29 = NULL ;
V_55:
F_17 ( & V_2 -> V_21 , V_18 ) ;
}
static int F_53 ( struct V_1 * V_2 )
{
int V_48 = V_49 ;
T_1 V_81 ;
F_9 ( V_2 , V_45 , V_82 ) ;
V_81 = F_6 ( V_2 , V_45 ) &
V_82 ;
do {
V_81 = F_6 ( V_2 , V_45 ) &
V_82 ;
} while ( V_48 -- && V_81 );
if ( ! V_48 ) {
F_35 ( V_2 -> V_32 , L_8 ,
F_6 ( V_2 , V_45 ) ,
F_6 ( V_2 , V_43 ) ) ;
return - V_83 ;
}
V_2 -> V_50 = false ;
return 0 ;
}
static int F_54 ( struct V_1 * V_2 )
{
int V_50 ;
V_50 = F_53 ( V_2 ) ;
if ( V_50 )
return V_50 ;
F_9 ( V_2 , V_45 ,
V_84 ) ;
return 0 ;
}
static T_5 F_55 ( int V_85 , void * V_36 )
{
struct V_1 * V_2 = V_36 ;
T_1 V_86 ;
V_86 = F_6 ( V_2 , V_43 ) ;
if ( ! ( V_86 & V_84 ) )
return V_87 ;
F_7 ( V_2 , V_43 ,
V_86 & V_84 ) ;
if ( V_86 & V_88 ) {
T_1 V_89 = V_86 & V_90 ;
F_7 ( V_2 , V_43 ,
V_89 & V_91 ) ;
if ( ! V_2 -> V_92 ||
( V_89 & ~ V_91 ) ) {
F_35 ( V_2 -> V_32 ,
L_9 ,
V_2 , V_89 ,
F_6 ( V_2 , V_58 ) ,
F_6 ( V_2 , V_70 ) ) ;
V_2 -> V_50 = true ;
}
}
if ( V_86 & V_93 ) {
F_27 ( V_2 -> V_32 , L_10 ) ;
}
if ( V_86 & V_94 ) {
F_50 ( V_2 ) ;
F_43 ( V_2 ) ;
}
F_56 ( & V_2 -> V_95 ) ;
return V_96 ;
}
static T_4 F_57 ( struct V_97 * V_98 )
{
struct V_16 * V_17 = F_58 ( V_98 ) ;
struct V_1 * V_2 = F_26 ( V_98 -> V_2 ) ;
T_4 V_40 ;
unsigned long V_18 ;
int V_50 ;
if ( V_2 -> V_50 ) {
V_50 = F_54 ( V_2 ) ;
if ( V_50 < 0 )
return V_50 ;
}
F_16 ( & V_2 -> V_21 , V_18 ) ;
V_40 = F_59 ( V_98 ) ;
F_52 ( & V_17 -> V_24 , & V_2 -> V_27 ) ;
V_2 -> V_19 = NULL ;
F_17 ( & V_2 -> V_21 , V_18 ) ;
return V_40 ;
}
static struct V_97 *
F_60 ( struct V_30 * V_31 ,
struct V_99 * V_100 ,
unsigned long V_18 )
{
struct V_1 * V_2 = F_26 ( V_31 ) ;
struct V_16 * V_17 ;
struct V_11 * V_12 , * V_57 = NULL ;
struct V_101 * V_73 ;
if ( ! F_61 ( V_100 -> V_102 ) )
return NULL ;
if ( ! V_100 -> V_103 || ! V_100 -> V_104 [ 0 ] . V_105 )
return NULL ;
V_17 = F_14 ( V_2 ) ;
if ( ! V_17 )
return NULL ;
F_62 ( & V_17 -> V_35 , & V_2 -> V_106 ) ;
V_17 -> V_35 . V_107 = F_57 ;
F_63 ( & V_17 -> V_35 ) ;
V_12 = F_10 ( V_2 ) ;
if ( ! V_12 )
goto error;
V_73 = & V_12 -> V_73 ;
V_73 -> V_80 = V_100 -> V_103 ;
V_73 -> V_76 = V_100 -> V_104 [ 0 ] . V_105 ;
V_73 -> V_78 = V_100 -> V_104 [ 0 ] . V_108 <<
V_109 ;
V_73 -> V_78 |= V_2 -> V_52 . V_110 <<
V_111 ;
if ( V_100 -> V_102 != V_66 )
V_73 -> V_74 = V_100 -> V_112 ;
else
V_73 -> V_74 = V_100 -> V_113 ;
V_57 = F_64 ( & V_17 -> V_22 ,
struct V_11 , V_24 ) ;
V_57 -> V_73 . V_114 = V_12 -> V_13 ;
F_52 ( & V_12 -> V_24 , & V_17 -> V_22 ) ;
V_57 = V_12 ;
V_12 = F_45 ( & V_17 -> V_22 ,
struct V_11 , V_24 ) ;
V_57 -> V_73 . V_114 = V_12 -> V_13 ;
return & V_17 -> V_35 ;
error:
F_19 ( V_2 , V_17 ) ;
return NULL ;
}
static void F_65 ( struct V_1 * V_2 )
{
F_41 ( V_2 ) ;
F_24 ( V_2 ) ;
}
int F_66 ( struct V_30 * V_31 ,
struct V_51 * V_115 )
{
struct V_1 * V_2 = F_26 ( V_31 ) ;
T_1 V_116 ;
if ( V_115 -> V_117 )
return F_54 ( V_2 ) ;
V_116 = F_6 ( V_2 , V_45 ) ;
V_2 -> V_52 . V_110 = V_115 -> V_110 ;
V_2 -> V_52 . V_61 = V_115 -> V_61 ;
V_2 -> V_52 . V_118 = V_115 -> V_118 ;
V_2 -> V_52 . V_119 = V_115 -> V_119 ;
if ( V_115 -> V_118 && V_2 -> V_120 ) {
V_116 |= V_121 ;
V_116 |= V_115 -> V_119 << V_122 ;
}
V_2 -> V_52 . V_59 = V_115 -> V_59 ;
if ( V_115 -> V_61 )
V_2 -> V_52 . V_63 = V_115 -> V_63 ;
else
V_2 -> V_52 . V_63 = - 1 ;
V_2 -> V_52 . V_123 = V_115 -> V_123 ;
V_2 -> V_52 . V_124 = V_115 -> V_124 ;
if ( V_115 -> V_123 <= V_125 ) {
V_116 |= V_115 -> V_123 << V_126 ;
V_2 -> V_52 . V_123 = V_115 -> V_123 ;
}
if ( V_115 -> V_124 <= V_127 ) {
V_116 |= V_115 -> V_124 << V_128 ;
V_2 -> V_52 . V_124 = V_115 -> V_124 ;
}
V_116 &= ~ V_129 ;
V_116 |= V_115 -> V_130 << V_131 ;
F_7 ( V_2 , V_45 , V_116 ) ;
return 0 ;
}
static int F_67 ( struct V_30 * V_31 ,
enum V_132 V_133 , unsigned long V_134 )
{
struct V_1 * V_2 = F_26 ( V_31 ) ;
if ( V_133 != V_135 )
return - V_136 ;
F_65 ( V_2 ) ;
return 0 ;
}
static void F_68 ( struct V_1 * V_2 )
{
F_8 ( V_2 , V_45 ,
V_84 ) ;
if ( V_2 -> V_85 > 0 )
F_69 ( V_2 -> V_85 , V_2 ) ;
F_70 ( & V_2 -> V_95 ) ;
F_21 ( & V_2 -> V_106 . V_137 ) ;
}
static int F_71 ( struct V_138 * V_4 ,
struct V_137 * V_24 )
{
struct V_1 * V_2 ;
bool V_139 = false ;
T_1 V_6 , V_140 ;
int V_50 ;
V_2 = F_72 ( V_4 -> V_32 , sizeof( * V_2 ) , V_20 ) ;
if ( ! V_2 )
return - V_38 ;
V_2 -> V_32 = V_4 -> V_32 ;
V_2 -> V_4 = V_4 ;
V_2 -> V_56 = V_4 -> V_56 ;
F_73 ( & V_2 -> V_21 ) ;
F_18 ( & V_2 -> V_27 ) ;
F_18 ( & V_2 -> V_28 ) ;
V_139 = F_74 ( V_24 , L_11 ) ;
V_2 -> V_120 = F_74 ( V_24 , L_12 ) ;
V_50 = F_75 ( V_24 , L_13 , & V_6 ) ;
if ( V_50 ) {
F_35 ( V_4 -> V_32 , L_14 ) ;
return V_50 ;
}
V_140 = V_6 >> 3 ;
if ( V_140 > 8 )
V_139 = false ;
if ( ! V_139 )
V_4 -> V_106 . V_141 = F_76 ( V_140 - 1 ) ;
if ( F_77 ( V_24 , L_15 ) ) {
V_2 -> V_65 = V_66 ;
V_2 -> V_37 = 0 ;
V_2 -> V_8 = V_142 ;
V_2 -> V_7 = V_143 ;
if ( V_4 -> V_92 == V_144 ||
V_4 -> V_92 == V_145 )
V_2 -> V_92 = true ;
} else if ( F_77 ( V_24 ,
L_16 ) ) {
V_2 -> V_65 = V_146 ;
V_2 -> V_37 = 1 ;
V_2 -> V_8 = V_147 ;
V_2 -> V_7 = V_148 ;
if ( V_4 -> V_92 == V_144 ||
V_4 -> V_92 == V_149 )
V_2 -> V_92 = true ;
} else {
F_35 ( V_4 -> V_32 , L_17 ) ;
return - V_150 ;
}
V_2 -> V_85 = F_78 ( V_24 , 0 ) ;
V_50 = F_79 ( V_2 -> V_85 , F_55 , V_151 ,
L_18 , V_2 ) ;
if ( V_50 ) {
F_35 ( V_4 -> V_32 , L_19 , V_2 -> V_85 ) ;
return V_50 ;
}
F_80 ( & V_2 -> V_95 , F_31 ,
( unsigned long ) V_2 ) ;
V_2 -> V_106 . V_152 = & V_4 -> V_106 ;
F_52 ( & V_2 -> V_106 . V_137 , & V_4 -> V_106 . V_153 ) ;
V_4 -> V_2 [ V_2 -> V_37 ] = V_2 ;
V_50 = F_54 ( V_2 ) ;
if ( V_50 < 0 ) {
F_35 ( V_4 -> V_32 , L_20 ) ;
return V_50 ;
}
return 0 ;
}
static struct V_30 * F_81 ( struct V_154 * V_155 ,
struct V_156 * V_157 )
{
struct V_138 * V_4 = V_157 -> V_158 ;
int V_159 = V_155 -> args [ 0 ] ;
if ( V_159 >= V_160 )
return NULL ;
return F_82 ( & V_4 -> V_2 [ V_159 ] -> V_106 ) ;
}
static int F_83 ( struct V_161 * V_162 )
{
struct V_137 * V_24 = V_162 -> V_32 . V_163 ;
struct V_138 * V_4 ;
struct V_137 * V_164 ;
struct V_165 * V_166 ;
T_1 V_167 ;
int V_72 , V_50 ;
V_4 = F_72 ( & V_162 -> V_32 , sizeof( * V_4 ) , V_20 ) ;
if ( ! V_4 )
return - V_38 ;
V_4 -> V_32 = & V_162 -> V_32 ;
V_166 = F_84 ( V_162 , V_168 , 0 ) ;
V_4 -> V_5 = F_85 ( & V_162 -> V_32 , V_166 ) ;
if ( F_86 ( V_4 -> V_5 ) )
return F_87 ( V_4 -> V_5 ) ;
V_4 -> V_56 = F_74 ( V_24 , L_21 ) ;
V_50 = F_75 ( V_24 , L_22 , & V_167 ) ;
if ( V_50 < 0 ) {
F_35 ( V_4 -> V_32 , L_23 ) ;
return V_50 ;
}
V_50 = F_75 ( V_24 , L_24 ,
& V_4 -> V_92 ) ;
if ( V_50 < 0 )
F_88 ( V_4 -> V_32 , L_25 ) ;
V_4 -> V_106 . V_32 = & V_162 -> V_32 ;
F_18 ( & V_4 -> V_106 . V_153 ) ;
F_89 ( V_169 , V_4 -> V_106 . V_170 ) ;
F_89 ( V_171 , V_4 -> V_106 . V_170 ) ;
V_4 -> V_106 . V_172 =
F_32 ;
V_4 -> V_106 . V_173 =
F_25 ;
V_4 -> V_106 . V_174 =
F_60 ;
V_4 -> V_106 . V_175 = F_67 ;
V_4 -> V_106 . V_176 = F_37 ;
V_4 -> V_106 . V_177 = F_49 ;
F_90 ( V_162 , V_4 ) ;
F_91 (node, child) {
V_50 = F_71 ( V_4 , V_164 ) ;
if ( V_50 < 0 )
goto error;
}
for ( V_72 = 0 ; V_72 < V_160 ; V_72 ++ )
if ( V_4 -> V_2 [ V_72 ] )
V_4 -> V_2 [ V_72 ] -> V_64 = V_167 ;
F_92 ( & V_4 -> V_106 ) ;
V_50 = F_93 ( V_24 , F_81 ,
V_4 ) ;
if ( V_50 < 0 ) {
F_35 ( & V_162 -> V_32 , L_26 ) ;
F_94 ( & V_4 -> V_106 ) ;
goto error;
}
F_95 ( & V_162 -> V_32 , L_27 ) ;
return 0 ;
error:
for ( V_72 = 0 ; V_72 < V_160 ; V_72 ++ )
if ( V_4 -> V_2 [ V_72 ] )
F_68 ( V_4 -> V_2 [ V_72 ] ) ;
return V_50 ;
}
static int F_96 ( struct V_161 * V_162 )
{
struct V_138 * V_4 = F_97 ( V_162 ) ;
int V_72 ;
F_98 ( V_162 -> V_32 . V_163 ) ;
F_94 ( & V_4 -> V_106 ) ;
for ( V_72 = 0 ; V_72 < V_160 ; V_72 ++ )
if ( V_4 -> V_2 [ V_72 ] )
F_68 ( V_4 -> V_2 [ V_72 ] ) ;
return 0 ;
}
