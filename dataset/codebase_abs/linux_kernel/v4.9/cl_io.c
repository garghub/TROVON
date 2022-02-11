static inline int F_1 ( enum V_1 type )
{
return V_2 <= type && type < V_3 ;
}
static inline int F_2 ( const struct V_4 * V_5 )
{
return F_1 ( V_5 -> V_6 ) && V_5 -> V_6 != V_7 ;
}
int F_3 ( const struct V_8 * V_9 )
{
return F_4 ( V_9 ) -> V_10 != NULL ;
}
static int F_5 ( const struct V_4 * V_5 )
{
struct V_4 * V_11 ;
V_11 = V_5 -> V_12 ;
return
F_6 ( V_5 -> V_13 > 0 , V_5 -> V_14 == V_15 ||
( V_5 -> V_14 == V_16 && V_11 ) ) ;
}
void F_7 ( const struct V_8 * V_9 , struct V_4 * V_5 )
{
struct V_17 * V_18 ;
struct V_19 * V_20 ;
F_8 ( F_1 ( V_5 -> V_6 ) ) ;
F_8 ( F_5 ( V_5 ) ) ;
while ( ! F_9 ( & V_5 -> V_21 ) ) {
V_18 = F_10 ( V_5 -> V_21 . V_22 , struct V_17 ,
V_23 ) ;
F_11 ( & V_18 -> V_23 ) ;
if ( V_18 -> V_24 -> V_25 [ V_5 -> V_6 ] . V_26 )
V_18 -> V_24 -> V_25 [ V_5 -> V_6 ] . V_26 ( V_9 , V_18 ) ;
V_18 -> V_27 = NULL ;
}
V_5 -> V_14 = V_28 ;
V_20 = F_4 ( V_9 ) ;
if ( V_20 -> V_10 == V_5 )
V_20 -> V_10 = NULL ;
switch ( V_5 -> V_6 ) {
case V_2 :
case V_29 :
break;
case V_30 :
break;
case V_31 :
F_12 ( ! V_5 -> V_32 ) ;
break;
case V_33 :
case V_7 :
F_12 ( F_6 ( V_5 -> V_34 || ! V_5 -> V_35 ,
! V_5 -> V_32 ) ) ;
break;
default:
F_13 () ;
}
}
static int F_14 ( const struct V_8 * V_9 , struct V_4 * V_5 ,
enum V_1 V_36 , struct V_37 * V_38 )
{
struct V_37 * V_39 ;
int V_40 ;
F_8 ( V_5 -> V_14 == V_41 || V_5 -> V_14 == V_28 ) ;
F_8 ( F_1 ( V_36 ) ) ;
F_8 ( F_5 ( V_5 ) ) ;
V_5 -> V_6 = V_36 ;
F_15 ( & V_5 -> V_42 . V_43 ) ;
F_15 ( & V_5 -> V_42 . V_44 ) ;
F_15 ( & V_5 -> V_21 ) ;
V_40 = 0 ;
F_16 (scan, obj) {
if ( V_39 -> V_45 -> V_46 ) {
V_40 = V_39 -> V_45 -> V_46 ( V_9 , V_39 , V_5 ) ;
if ( V_40 != 0 )
break;
}
}
if ( V_40 == 0 )
V_5 -> V_14 = V_47 ;
return V_40 ;
}
int F_17 ( const struct V_8 * V_9 , struct V_4 * V_5 ,
enum V_1 V_36 , struct V_37 * V_38 )
{
struct V_19 * V_20 = F_4 ( V_9 ) ;
F_12 ( V_38 != F_18 ( V_38 ) ) ;
if ( ! V_20 -> V_10 )
V_20 -> V_10 = V_5 ;
return F_14 ( V_9 , V_5 , V_36 , V_38 ) ;
}
int F_19 ( const struct V_8 * V_9 , struct V_4 * V_5 ,
enum V_1 V_36 , struct V_37 * V_38 )
{
struct V_19 * V_20 = F_4 ( V_9 ) ;
F_12 ( V_38 == F_18 ( V_38 ) ) ;
F_12 ( ! V_20 -> V_10 ) ;
V_20 -> V_10 = V_5 ;
return F_14 ( V_9 , V_5 , V_36 , V_38 ) ;
}
int F_20 ( const struct V_8 * V_9 , struct V_4 * V_5 ,
enum V_1 V_36 , T_1 V_48 , T_2 V_49 )
{
F_8 ( V_36 == V_2 || V_36 == V_29 ) ;
F_8 ( V_5 -> V_50 ) ;
F_21 ( V_51 , V_9 , & V_5 -> V_50 -> V_52 ,
L_1 ,
V_36 , ( V_53 ) V_48 , ( V_53 ) V_48 + V_49 ,
V_5 -> V_54 . V_55 . V_56 , V_5 -> V_54 . V_57 . V_58 ) ;
V_5 -> V_54 . V_55 . V_59 = V_48 ;
V_5 -> V_54 . V_55 . V_60 = V_49 ;
return F_19 ( V_9 , V_5 , V_36 , V_5 -> V_50 ) ;
}
static int F_22 ( const struct V_61 * V_62 ,
const struct V_61 * V_63 )
{
return F_23 ( F_24 ( & V_62 -> V_64 -> V_52 ) ,
F_24 ( & V_63 -> V_64 -> V_52 ) ) ;
}
static void F_25 ( struct V_4 * V_5 )
{
int V_65 = 0 ;
do {
struct V_66 * V_67 ;
struct V_66 * V_22 ;
struct V_66 * V_68 ;
V_65 = 1 ;
V_22 = NULL ;
F_26 (curr, temp,
&io->ci_lockset.cls_todo,
cill_linkage) {
if ( V_22 ) {
switch ( F_22 ( & V_22 -> V_69 ,
& V_67 -> V_69 ) ) {
case 0 :
default:
F_13 () ;
case 1 :
F_27 ( & V_67 -> V_70 ,
& V_22 -> V_70 ) ;
V_65 = 0 ;
continue;
case - 1 :
break;
}
}
V_22 = V_67 ;
}
} while ( ! V_65 );
}
static void F_28 ( struct V_61 * V_62 ,
const struct V_61 * V_63 )
{
V_62 -> V_71 = F_29 ( V_62 -> V_71 , V_63 -> V_71 ) ;
V_62 -> V_72 = F_30 ( V_62 -> V_72 , V_63 -> V_72 ) ;
if ( V_63 -> V_73 == V_74 && V_62 -> V_73 != V_74 )
V_62 -> V_73 = V_74 ;
if ( V_63 -> V_73 == V_75 && V_62 -> V_73 != V_75 )
V_62 -> V_73 = V_75 ;
}
static int F_31 ( const struct V_76 * V_77 ,
const struct V_61 * V_78 )
{
struct V_66 * V_39 ;
F_32 (scan, &set->cls_todo, cill_linkage) {
if ( ! F_33 ( V_39 -> V_69 . V_64 , V_78 -> V_64 ) )
continue;
F_28 ( & V_39 -> V_69 , V_78 ) ;
F_34 ( V_51 , L_2 ,
V_39 -> V_69 . V_73 , V_39 -> V_69 . V_71 ,
V_39 -> V_69 . V_72 ) ;
return 1 ;
}
return 0 ;
}
static int F_35 ( const struct V_8 * V_9 , struct V_4 * V_5 ,
struct V_76 * V_77 )
{
struct V_66 * V_79 ;
struct V_66 * V_68 ;
int V_40 ;
V_40 = 0 ;
F_26 (link, temp, &set->cls_todo, cill_linkage) {
V_40 = F_36 ( V_9 , V_5 , & V_79 -> V_80 ) ;
if ( V_40 < 0 )
break;
F_37 ( & V_79 -> V_70 , & V_77 -> V_44 ) ;
}
return V_40 ;
}
int F_38 ( const struct V_8 * V_9 , struct V_4 * V_5 )
{
const struct V_17 * V_39 ;
int V_40 = 0 ;
F_8 ( F_2 ( V_5 ) ) ;
F_8 ( V_5 -> V_14 == V_81 ) ;
F_8 ( F_5 ( V_5 ) ) ;
F_39 (scan, io) {
if ( ! V_39 -> V_24 -> V_25 [ V_5 -> V_6 ] . V_82 )
continue;
V_40 = V_39 -> V_24 -> V_25 [ V_5 -> V_6 ] . V_82 ( V_9 , V_39 ) ;
if ( V_40 != 0 )
break;
}
if ( V_40 == 0 ) {
F_25 ( V_5 ) ;
V_40 = F_35 ( V_9 , V_5 , & V_5 -> V_42 ) ;
}
if ( V_40 != 0 )
F_40 ( V_9 , V_5 ) ;
else
V_5 -> V_14 = V_16 ;
return V_40 ;
}
void F_40 ( const struct V_8 * V_9 , struct V_4 * V_5 )
{
struct V_76 * V_77 ;
struct V_66 * V_79 ;
struct V_66 * V_68 ;
const struct V_17 * V_39 ;
F_12 ( F_2 ( V_5 ) ) ;
F_12 ( V_81 <= V_5 -> V_14 && V_5 -> V_14 < V_83 ) ;
F_8 ( F_5 ( V_5 ) ) ;
V_77 = & V_5 -> V_42 ;
F_26 (link, temp, &set->cls_todo, cill_linkage) {
F_11 ( & V_79 -> V_70 ) ;
if ( V_79 -> V_84 )
V_79 -> V_84 ( V_9 , V_79 ) ;
}
F_26 (link, temp, &set->cls_done, cill_linkage) {
F_11 ( & V_79 -> V_70 ) ;
F_41 ( V_9 , & V_79 -> V_80 ) ;
if ( V_79 -> V_84 )
V_79 -> V_84 ( V_9 , V_79 ) ;
}
F_42 (scan, io) {
if ( V_39 -> V_24 -> V_25 [ V_5 -> V_6 ] . V_85 )
V_39 -> V_24 -> V_25 [ V_5 -> V_6 ] . V_85 ( V_9 , V_39 ) ;
}
V_5 -> V_14 = V_83 ;
F_12 ( ! F_4 ( V_9 ) -> V_86 [ V_87 ] . V_88 ) ;
}
int F_43 ( const struct V_8 * V_9 , struct V_4 * V_5 )
{
const struct V_17 * V_39 ;
int V_40 ;
F_8 ( F_2 ( V_5 ) ) ;
F_8 ( V_5 -> V_14 == V_47 || V_5 -> V_14 == V_89 ) ;
F_8 ( F_5 ( V_5 ) ) ;
V_40 = 0 ;
F_39 (scan, io) {
if ( ! V_39 -> V_24 -> V_25 [ V_5 -> V_6 ] . V_90 )
continue;
V_40 = V_39 -> V_24 -> V_25 [ V_5 -> V_6 ] . V_90 ( V_9 ,
V_39 ) ;
if ( V_40 != 0 )
break;
}
if ( V_40 == 0 )
V_5 -> V_14 = V_81 ;
return V_40 ;
}
void F_44 ( const struct V_8 * V_9 , struct V_4 * V_5 )
{
const struct V_17 * V_39 ;
F_8 ( F_2 ( V_5 ) ) ;
F_8 ( V_5 -> V_14 == V_83 ) ;
F_8 ( F_5 ( V_5 ) ) ;
F_42 (scan, io) {
if ( V_39 -> V_24 -> V_25 [ V_5 -> V_6 ] . V_91 )
V_39 -> V_24 -> V_25 [ V_5 -> V_6 ] . V_91 ( V_9 , V_39 ) ;
}
V_5 -> V_14 = V_89 ;
}
static void F_45 ( const struct V_8 * V_9 , struct V_4 * V_5 ,
T_2 V_92 )
{
const struct V_17 * V_39 ;
F_8 ( V_5 -> V_6 == V_2 || V_5 -> V_6 == V_29 ||
V_92 == 0 ) ;
F_8 ( F_2 ( V_5 ) ) ;
F_8 ( F_5 ( V_5 ) ) ;
V_5 -> V_54 . V_55 . V_59 += V_92 ;
V_5 -> V_54 . V_55 . V_60 -= V_92 ;
F_42 (scan, io) {
if ( V_39 -> V_24 -> V_25 [ V_5 -> V_6 ] . V_93 )
V_39 -> V_24 -> V_25 [ V_5 -> V_6 ] . V_93 ( V_9 , V_39 ,
V_92 ) ;
}
}
int F_46 ( const struct V_8 * V_9 , struct V_4 * V_5 ,
struct V_66 * V_79 )
{
int V_40 ;
if ( F_31 ( & V_5 -> V_42 , & V_79 -> V_69 ) ) {
V_40 = 1 ;
} else {
F_47 ( & V_79 -> V_70 , & V_5 -> V_42 . V_43 ) ;
V_40 = 0 ;
}
return V_40 ;
}
static void F_48 ( const struct V_8 * V_9 ,
struct V_66 * V_79 )
{
F_49 ( V_79 ) ;
}
int F_50 ( const struct V_8 * V_9 , struct V_4 * V_5 ,
struct V_61 * V_94 )
{
struct V_66 * V_79 ;
int V_40 ;
V_79 = F_51 ( sizeof( * V_79 ) , V_95 ) ;
if ( V_79 ) {
V_79 -> V_69 = * V_94 ;
V_79 -> V_84 = F_48 ;
V_40 = F_46 ( V_9 , V_5 , V_79 ) ;
if ( V_40 )
V_79 -> V_84 ( V_9 , V_79 ) ;
} else {
V_40 = - V_96 ;
}
return V_40 ;
}
int F_52 ( const struct V_8 * V_9 , struct V_4 * V_5 )
{
const struct V_17 * V_39 ;
int V_40 = 0 ;
F_8 ( F_2 ( V_5 ) ) ;
F_8 ( V_5 -> V_14 == V_16 ) ;
F_8 ( F_5 ( V_5 ) ) ;
V_5 -> V_14 = V_15 ;
F_39 (scan, io) {
if ( ! V_39 -> V_24 -> V_25 [ V_5 -> V_6 ] . V_97 )
continue;
V_40 = V_39 -> V_24 -> V_25 [ V_5 -> V_6 ] . V_97 ( V_9 , V_39 ) ;
if ( V_40 != 0 )
break;
}
if ( V_40 >= 0 )
V_40 = 0 ;
return V_40 ;
}
void F_53 ( const struct V_8 * V_9 , struct V_4 * V_5 )
{
const struct V_17 * V_39 ;
F_8 ( F_2 ( V_5 ) ) ;
F_8 ( V_5 -> V_14 == V_15 ) ;
F_8 ( F_5 ( V_5 ) ) ;
F_42 (scan, io) {
if ( V_39 -> V_24 -> V_25 [ V_5 -> V_6 ] . V_98 )
V_39 -> V_24 -> V_25 [ V_5 -> V_6 ] . V_98 ( V_9 , V_39 ) ;
}
V_5 -> V_14 = V_99 ;
}
static const struct V_100 *
F_54 ( const struct V_17 * V_101 , struct V_102 * V_103 )
{
const struct V_100 * V_18 ;
V_18 = F_55 ( V_103 , V_101 -> V_104 -> V_52 . V_105 -> V_106 ) ;
F_8 ( V_18 ) ;
return V_18 ;
}
int F_56 ( const struct V_8 * V_9 , struct V_4 * V_5 ,
struct V_102 * V_103 )
{
const struct V_17 * V_39 ;
struct V_107 * V_108 ;
int V_40 = 0 ;
F_8 ( V_5 -> V_6 == V_2 || V_5 -> V_6 == V_30 ) ;
F_8 ( F_57 ( V_103 , V_5 ) ) ;
F_8 ( V_5 -> V_14 == V_15 || V_5 -> V_14 == V_16 ) ;
F_8 ( F_5 ( V_5 ) ) ;
V_108 = & V_5 -> V_109 ;
F_58 ( V_108 ) ;
F_39 (scan, io) {
if ( V_39 -> V_24 -> V_110 ) {
const struct V_100 * V_18 ;
V_18 = F_54 ( V_39 , V_103 ) ;
F_8 ( V_18 ) ;
V_40 = V_39 -> V_24 -> V_110 ( V_9 , V_39 , V_18 ) ;
if ( V_40 != 0 )
break;
}
}
if ( V_40 == 0 && V_108 -> V_111 . V_112 > 0 )
V_40 = F_59 ( V_9 , V_5 , V_113 , V_108 ) ;
F_60 ( V_9 , V_5 , & V_108 -> V_111 ) ;
F_61 ( V_9 , V_108 ) ;
return V_40 ;
}
int F_62 ( const struct V_8 * V_9 , struct V_4 * V_5 ,
struct V_114 * V_108 , int V_115 , int V_116 ,
T_3 V_117 )
{
const struct V_17 * V_39 ;
int V_40 = 0 ;
F_39 (scan, io) {
if ( ! V_39 -> V_24 -> V_118 )
continue;
V_40 = V_39 -> V_24 -> V_118 ( V_9 , V_39 , V_108 ,
V_115 , V_116 , V_117 ) ;
if ( V_40 != 0 )
break;
}
return V_40 ;
}
int F_59 ( const struct V_8 * V_9 , struct V_4 * V_5 ,
enum V_119 V_120 , struct V_107 * V_108 )
{
const struct V_17 * V_39 ;
int V_40 = 0 ;
F_39 (scan, io) {
if ( ! V_39 -> V_24 -> V_121 )
continue;
V_40 = V_39 -> V_24 -> V_121 ( V_9 , V_39 , V_120 , V_108 ) ;
if ( V_40 != 0 )
break;
}
F_12 ( F_6 ( V_40 != 0 , F_9 ( & V_108 -> V_122 . V_123 ) ) ) ;
return V_40 ;
}
int F_63 ( const struct V_8 * V_9 , struct V_4 * V_5 ,
enum V_119 V_36 , struct V_107 * V_108 ,
long V_124 )
{
struct V_125 * V_126 = & F_4 ( V_9 ) -> V_127 ;
struct V_102 * V_128 ;
int V_129 ;
F_64 (pg, &queue->c2_qin) {
F_12 ( ! V_128 -> V_130 ) ;
V_128 -> V_130 = V_126 ;
}
F_65 ( V_126 , V_108 -> V_111 . V_112 , & V_131 ) ;
V_129 = F_59 ( V_9 , V_5 , V_36 , V_108 ) ;
if ( V_129 == 0 ) {
F_64 (pg, &queue->c2_qin) {
V_128 -> V_130 = NULL ;
F_66 ( V_9 , V_126 , 1 ) ;
}
V_129 = F_67 ( V_9 , V_126 , V_124 ) ;
F_68 ( V_9 , V_5 , & V_108 -> V_122 ) ;
} else {
F_12 ( F_9 ( & V_108 -> V_122 . V_123 ) ) ;
F_64 (pg, &queue->c2_qin)
V_128 -> V_130 = NULL ;
}
return V_129 ;
}
int F_69 ( const struct V_8 * V_9 , struct V_4 * V_5 )
{
int V_40 = 0 ;
F_8 ( F_2 ( V_5 ) ) ;
do {
T_2 V_92 ;
V_5 -> V_132 = 0 ;
V_40 = F_43 ( V_9 , V_5 ) ;
if ( V_40 == 0 ) {
V_92 = V_5 -> V_133 ;
V_40 = F_38 ( V_9 , V_5 ) ;
if ( V_40 == 0 ) {
V_40 = F_52 ( V_9 , V_5 ) ;
F_53 ( V_9 , V_5 ) ;
F_40 ( V_9 , V_5 ) ;
F_45 ( V_9 , V_5 , V_5 -> V_133 - V_92 ) ;
}
}
F_44 ( V_9 , V_5 ) ;
} while ( V_40 == 0 && V_5 -> V_132 );
if ( V_40 == 0 )
V_40 = V_5 -> V_134 ;
return V_40 < 0 ? V_40 : 0 ;
}
void F_70 ( struct V_4 * V_5 , struct V_17 * V_18 ,
struct V_37 * V_38 ,
const struct V_135 * V_136 )
{
struct V_137 * V_138 = & V_18 -> V_23 ;
F_12 ( ( ! V_138 -> V_22 && ! V_138 -> V_139 ) ||
F_9 ( V_138 ) ) ;
F_71 ( V_138 , & V_5 -> V_21 ) ;
V_18 -> V_27 = V_5 ;
V_18 -> V_104 = V_38 ;
V_18 -> V_24 = V_136 ;
}
void F_72 ( struct V_114 * V_140 )
{
V_140 -> V_112 = 0 ;
F_15 ( & V_140 -> V_123 ) ;
V_140 -> V_141 = V_142 ;
}
void F_73 ( struct V_114 * V_140 , struct V_102 * V_103 )
{
F_12 ( V_103 -> V_143 ) ;
F_8 ( V_140 -> V_141 == V_142 ) ;
F_12 ( F_9 ( & V_103 -> V_144 ) ) ;
F_71 ( & V_103 -> V_144 , & V_140 -> V_123 ) ;
++ V_140 -> V_112 ;
F_74 ( & V_103 -> V_145 , & V_103 -> V_146 , L_3 , V_140 ) ;
F_75 ( V_103 ) ;
}
void F_76 ( const struct V_8 * V_9 , struct V_114 * V_140 ,
struct V_102 * V_103 )
{
F_12 ( V_140 -> V_112 > 0 ) ;
F_12 ( F_77 ( V_9 , V_103 ) ) ;
F_8 ( V_140 -> V_141 == V_142 ) ;
F_11 ( & V_103 -> V_144 ) ;
-- V_140 -> V_112 ;
F_78 ( & V_103 -> V_145 , & V_103 -> V_146 , L_3 , V_140 ) ;
F_79 ( V_9 , V_103 ) ;
}
void F_80 ( struct V_114 * V_147 , struct V_114 * V_148 ,
struct V_102 * V_103 )
{
F_12 ( V_148 -> V_112 > 0 ) ;
F_8 ( V_147 -> V_141 == V_142 ) ;
F_8 ( V_148 -> V_141 == V_142 ) ;
F_27 ( & V_103 -> V_144 , & V_147 -> V_123 ) ;
-- V_148 -> V_112 ;
++ V_147 -> V_112 ;
F_81 ( & V_103 -> V_145 , & V_103 -> V_146 , L_3 ,
V_148 , V_147 ) ;
}
void F_82 ( struct V_114 * V_147 , struct V_114 * V_148 ,
struct V_102 * V_103 )
{
F_12 ( V_148 -> V_112 > 0 ) ;
F_8 ( V_147 -> V_141 == V_142 ) ;
F_8 ( V_148 -> V_141 == V_142 ) ;
F_37 ( & V_103 -> V_144 , & V_147 -> V_123 ) ;
-- V_148 -> V_112 ;
++ V_147 -> V_112 ;
F_81 ( & V_103 -> V_145 , & V_103 -> V_146 , L_3 ,
V_148 , V_147 ) ;
}
void F_83 ( struct V_114 * V_149 , struct V_114 * V_150 )
{
struct V_102 * V_103 ;
struct V_102 * V_151 ;
F_8 ( V_149 -> V_141 == V_142 ) ;
F_8 ( V_150 -> V_141 == V_142 ) ;
F_84 (page, tmp, list)
F_80 ( V_150 , V_149 , V_103 ) ;
}
void F_60 ( const struct V_8 * V_9 ,
struct V_4 * V_5 , struct V_114 * V_140 )
{
struct V_102 * V_103 ;
struct V_102 * V_68 ;
F_8 ( V_140 -> V_141 == V_142 ) ;
F_84 (page, temp, plist) {
F_12 ( V_140 -> V_112 > 0 ) ;
F_11 ( & V_103 -> V_144 ) ;
-- V_140 -> V_112 ;
F_85 ( V_9 , V_5 , V_103 ) ;
F_78 ( & V_103 -> V_145 , & V_103 -> V_146 , L_3 ,
V_140 ) ;
F_79 ( V_9 , V_103 ) ;
}
}
void F_86 ( const struct V_8 * V_9 , struct V_114 * V_140 )
{
struct V_102 * V_103 ;
struct V_102 * V_68 ;
F_8 ( V_140 -> V_141 == V_142 ) ;
F_84 (page, temp, plist)
F_76 ( V_9 , V_140 , V_103 ) ;
F_12 ( V_140 -> V_112 == 0 ) ;
}
static void F_68 ( const struct V_8 * V_9 ,
struct V_4 * V_5 , struct V_114 * V_140 )
{
struct V_102 * V_103 ;
F_8 ( V_140 -> V_141 == V_142 ) ;
F_64 (page, plist)
F_87 ( V_9 , V_5 , V_103 ) ;
}
static void F_88 ( const struct V_8 * V_9 , struct V_4 * V_5 ,
struct V_114 * V_140 )
{
struct V_102 * V_103 ;
F_8 ( V_140 -> V_141 == V_142 ) ;
F_64 (page, plist)
F_89 ( V_9 , V_5 , V_103 ) ;
}
void F_58 ( struct V_107 * V_108 )
{
F_72 ( & V_108 -> V_111 ) ;
F_72 ( & V_108 -> V_122 ) ;
}
void F_90 ( const struct V_8 * V_9 ,
struct V_4 * V_5 , struct V_107 * V_108 )
{
F_60 ( V_9 , V_5 , & V_108 -> V_111 ) ;
F_60 ( V_9 , V_5 , & V_108 -> V_122 ) ;
}
void F_91 ( const struct V_8 * V_9 ,
struct V_4 * V_5 , struct V_107 * V_108 )
{
F_88 ( V_9 , V_5 , & V_108 -> V_111 ) ;
F_88 ( V_9 , V_5 , & V_108 -> V_122 ) ;
}
void F_61 ( const struct V_8 * V_9 , struct V_107 * V_108 )
{
F_86 ( V_9 , & V_108 -> V_122 ) ;
F_86 ( V_9 , & V_108 -> V_111 ) ;
}
void F_92 ( struct V_107 * V_108 , struct V_102 * V_103 )
{
F_58 ( V_108 ) ;
F_73 ( & V_108 -> V_111 , V_103 ) ;
}
struct V_4 * F_93 ( struct V_4 * V_5 )
{
while ( V_5 -> V_12 )
V_5 = V_5 -> V_12 ;
return V_5 ;
}
void F_94 ( struct V_152 * V_153 , struct V_154 * V_18 ,
struct V_155 * V_156 ,
const struct V_157 * V_136 )
{
F_71 ( & V_18 -> V_158 , & V_153 -> V_159 ) ;
V_18 -> V_160 = V_156 ;
V_18 -> V_161 = V_136 ;
V_18 -> V_162 = V_153 ;
}
static void F_95 ( const struct V_8 * V_9 , struct V_152 * V_153 )
{
unsigned V_163 ;
F_12 ( F_9 ( & V_153 -> V_164 ) ) ;
F_12 ( V_153 -> V_165 == 0 ) ;
F_8 ( F_9 ( & V_153 -> V_159 ) ) ;
F_8 ( F_96 ( V_153 -> V_166 > 0 , V_153 -> V_167 ) ) ;
if ( V_153 -> V_167 ) {
for ( V_163 = 0 ; V_163 < V_153 -> V_166 ; ++ V_163 ) {
struct V_37 * V_38 = V_153 -> V_167 [ V_163 ] . V_168 ;
if ( V_38 ) {
F_97 ( & V_38 -> V_52 ,
& V_153 -> V_167 [ V_163 ] . V_169 ,
L_4 , V_153 ) ;
F_98 ( V_9 , V_38 ) ;
}
}
F_49 ( V_153 -> V_167 ) ;
}
F_49 ( V_153 ) ;
}
static int F_99 ( const struct V_8 * V_9 , struct V_152 * V_153 ,
struct V_102 * V_103 )
{
struct V_155 * V_156 ;
struct V_100 * V_18 ;
int V_40 ;
V_40 = 0 ;
F_32 (slice, &page->cp_layers, cpl_linkage) {
V_156 = F_100 ( V_18 -> V_170 -> V_52 . V_105 ) ;
if ( V_156 -> V_171 -> V_172 ) {
V_40 = V_156 -> V_171 -> V_172 ( V_9 , V_156 , V_153 ) ;
if ( V_40 != 0 )
break;
}
}
return V_40 ;
}
void F_101 ( const struct V_8 * V_9 , struct V_152 * V_153 , int V_129 )
{
struct V_154 * V_18 ;
while ( ! F_9 ( & V_153 -> V_159 ) ) {
V_18 = F_102 ( V_153 -> V_159 . V_22 ,
struct V_154 , V_158 ) ;
F_11 ( & V_18 -> V_158 ) ;
if ( V_18 -> V_161 -> V_173 )
V_18 -> V_161 -> V_173 ( V_9 , V_18 , V_129 ) ;
}
F_95 ( V_9 , V_153 ) ;
}
struct V_152 * F_103 ( const struct V_8 * V_9 , struct V_102 * V_103 ,
enum V_119 V_120 , int V_174 )
{
struct V_152 * V_153 ;
F_8 ( V_174 > 0 ) ;
V_153 = F_51 ( sizeof( * V_153 ) , V_95 ) ;
if ( V_153 ) {
int V_40 ;
V_153 -> V_175 = V_120 ;
F_15 ( & V_153 -> V_164 ) ;
F_15 ( & V_153 -> V_159 ) ;
V_153 -> V_167 = F_104 ( V_174 , sizeof( V_153 -> V_167 [ 0 ] ) ,
V_95 ) ;
if ( V_153 -> V_167 ) {
V_153 -> V_166 = V_174 ;
V_40 = F_99 ( V_9 , V_153 , V_103 ) ;
} else {
V_40 = - V_96 ;
}
if ( V_40 != 0 ) {
F_101 ( V_9 , V_153 , V_40 ) ;
V_153 = F_105 ( V_40 ) ;
}
} else {
V_153 = F_105 ( - V_96 ) ;
}
return V_153 ;
}
void F_106 ( const struct V_8 * V_9 ,
struct V_152 * V_153 , struct V_102 * V_103 )
{
struct V_37 * V_38 ;
struct V_176 * V_177 ;
unsigned int V_163 ;
F_12 ( F_9 ( & V_103 -> V_178 ) ) ;
F_12 ( ! V_103 -> V_179 ) ;
F_107 ( V_180 , V_9 , V_103 , L_5 ,
V_153 , V_153 -> V_175 , V_153 -> V_165 ) ;
F_71 ( & V_103 -> V_178 , & V_153 -> V_164 ) ;
++ V_153 -> V_165 ;
V_103 -> V_179 = V_153 ;
V_38 = F_18 ( V_103 -> V_181 ) ;
for ( V_163 = 0 , V_177 = V_153 -> V_167 ; V_38 != V_177 -> V_168 ; ++ V_163 , ++ V_177 ) {
if ( ! V_177 -> V_168 ) {
V_177 -> V_168 = V_38 ;
F_108 ( V_38 ) ;
F_109 ( & V_38 -> V_52 , & V_177 -> V_169 ,
L_4 , V_153 ) ;
break;
}
}
F_12 ( V_163 < V_153 -> V_166 ) ;
}
void F_110 ( const struct V_8 * V_9 , struct V_102 * V_103 )
{
struct V_152 * V_153 = V_103 -> V_179 ;
F_12 ( ! F_9 ( & V_103 -> V_178 ) ) ;
F_12 ( V_153 -> V_165 > 0 ) ;
F_11 ( & V_103 -> V_178 ) ;
-- V_153 -> V_165 ;
V_103 -> V_179 = NULL ;
}
int F_111 ( const struct V_8 * V_9 , struct V_152 * V_153 )
{
unsigned int V_163 ;
int V_40 ;
const struct V_154 * V_18 ;
for ( V_163 = 0 ; V_163 < V_153 -> V_166 ; ++ V_163 )
F_12 ( V_153 -> V_167 [ V_163 ] . V_168 ) ;
V_40 = 0 ;
F_32 (slice, &req->crq_layers, crs_linkage) {
if ( V_18 -> V_161 -> V_182 ) {
V_40 = V_18 -> V_161 -> V_182 ( V_9 , V_18 ) ;
if ( V_40 != 0 )
break;
}
}
return V_40 ;
}
void F_112 ( const struct V_8 * V_9 , struct V_152 * V_153 ,
struct V_183 * V_184 , T_4 V_185 )
{
const struct V_154 * V_18 ;
struct V_102 * V_103 ;
unsigned int V_163 ;
F_12 ( ! F_9 ( & V_153 -> V_164 ) ) ;
V_103 = F_102 ( V_153 -> V_164 . V_139 , struct V_102 , V_178 ) ;
for ( V_163 = 0 ; V_163 < V_153 -> V_166 ; ++ V_163 ) {
F_32 (slice, &req->crq_layers, crs_linkage) {
const struct V_100 * V_39 ;
const struct V_37 * V_38 ;
V_39 = F_55 ( V_103 ,
V_18 -> V_160 -> V_186 . V_106 ) ;
V_38 = V_39 -> V_170 ;
if ( V_18 -> V_161 -> V_187 )
V_18 -> V_161 -> V_187 ( V_9 , V_18 , V_38 ,
V_184 + V_163 , V_185 ) ;
}
}
}
void V_131 ( const struct V_8 * V_9 , struct V_125 * V_126 )
{
F_113 ( & V_126 -> V_188 ) ;
F_114 ( & V_126 -> V_189 , 0 ) ;
}
void F_65 ( struct V_125 * V_126 , int V_190 ,
void (* F_115)( const struct V_8 * , struct V_125 * ) )
{
memset ( V_126 , 0 , sizeof( * V_126 ) ) ;
F_116 ( & V_126 -> V_188 ) ;
F_114 ( & V_126 -> V_191 , V_190 ) ;
F_114 ( & V_126 -> V_189 , V_190 > 0 ) ;
V_126 -> V_192 = 0 ;
V_126 -> V_193 = F_115 ;
F_12 ( F_115 ) ;
}
int F_67 ( const struct V_8 * V_9 , struct V_125 * V_126 ,
long V_124 )
{
struct V_194 V_195 = F_117 ( F_118 ( V_124 ) ,
NULL , NULL , NULL ) ;
int V_129 ;
F_12 ( V_124 >= 0 ) ;
V_129 = F_119 ( V_126 -> V_188 ,
F_120 ( & V_126 -> V_191 ) == 0 ,
& V_195 ) ;
if ( V_129 < 0 ) {
F_121 ( L_6 ,
V_129 , F_120 ( & V_126 -> V_191 ) ) ;
V_195 = (struct V_194 ) { 0 } ;
( void ) F_119 ( V_126 -> V_188 ,
F_120 ( & V_126 -> V_191 ) == 0 ,
& V_195 ) ;
} else {
V_129 = V_126 -> V_192 ;
}
F_12 ( F_120 ( & V_126 -> V_191 ) == 0 ) ;
while ( F_122 ( F_120 ( & V_126 -> V_189 ) != 0 ) ) {
F_123 () ;
}
return V_129 ;
}
void F_66 ( const struct V_8 * V_9 , struct V_125 * V_126 ,
int V_196 )
{
if ( V_126 -> V_192 == 0 && V_196 < 0 )
V_126 -> V_192 = V_196 ;
F_12 ( F_120 ( & V_126 -> V_191 ) > 0 ) ;
if ( F_124 ( & V_126 -> V_191 ) ) {
F_12 ( V_126 -> V_193 ) ;
V_126 -> V_193 ( V_9 , V_126 ) ;
}
}
