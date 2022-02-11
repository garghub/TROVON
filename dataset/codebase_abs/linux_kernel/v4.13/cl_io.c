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
case V_30 :
break;
case V_31 :
break;
case V_32 :
F_12 ( ! V_5 -> V_33 ) ;
break;
case V_34 :
case V_7 :
F_12 ( F_6 ( V_5 -> V_35 || ! V_5 -> V_36 ,
! V_5 -> V_33 ) ) ;
break;
default:
F_13 () ;
}
}
static int F_14 ( const struct V_8 * V_9 , struct V_4 * V_5 ,
enum V_1 V_37 , struct V_38 * V_39 )
{
struct V_38 * V_40 ;
int V_41 ;
F_8 ( V_5 -> V_14 == V_42 || V_5 -> V_14 == V_28 ) ;
F_8 ( F_1 ( V_37 ) ) ;
F_8 ( F_5 ( V_5 ) ) ;
V_5 -> V_6 = V_37 ;
F_15 ( & V_5 -> V_43 . V_44 ) ;
F_15 ( & V_5 -> V_43 . V_45 ) ;
F_15 ( & V_5 -> V_21 ) ;
V_41 = 0 ;
F_16 (scan, obj) {
if ( V_40 -> V_46 -> V_47 ) {
V_41 = V_40 -> V_46 -> V_47 ( V_9 , V_40 , V_5 ) ;
if ( V_41 != 0 )
break;
}
}
if ( V_41 == 0 )
V_5 -> V_14 = V_48 ;
return V_41 ;
}
int F_17 ( const struct V_8 * V_9 , struct V_4 * V_5 ,
enum V_1 V_37 , struct V_38 * V_39 )
{
struct V_19 * V_20 = F_4 ( V_9 ) ;
F_12 ( V_39 != F_18 ( V_39 ) ) ;
if ( ! V_20 -> V_10 )
V_20 -> V_10 = V_5 ;
return F_14 ( V_9 , V_5 , V_37 , V_39 ) ;
}
int F_19 ( const struct V_8 * V_9 , struct V_4 * V_5 ,
enum V_1 V_37 , struct V_38 * V_39 )
{
struct V_19 * V_20 = F_4 ( V_9 ) ;
F_12 ( V_39 == F_18 ( V_39 ) ) ;
F_12 ( ! V_20 -> V_10 ) ;
V_20 -> V_10 = V_5 ;
return F_14 ( V_9 , V_5 , V_37 , V_39 ) ;
}
int F_20 ( const struct V_8 * V_9 , struct V_4 * V_5 ,
enum V_1 V_37 , T_1 V_49 , T_2 V_50 )
{
F_8 ( V_37 == V_2 || V_37 == V_29 ) ;
F_8 ( V_5 -> V_51 ) ;
F_21 ( V_52 , V_9 , & V_5 -> V_51 -> V_53 ,
L_1 ,
V_37 , ( V_54 ) V_49 , ( V_54 ) V_49 + V_50 ,
V_5 -> V_55 . V_56 . V_57 , V_5 -> V_55 . V_58 . V_59 ) ;
V_5 -> V_55 . V_56 . V_60 = V_49 ;
V_5 -> V_55 . V_56 . V_61 = V_50 ;
return F_19 ( V_9 , V_5 , V_37 , V_5 -> V_51 ) ;
}
static int F_22 ( const struct V_62 * V_63 ,
const struct V_62 * V_64 )
{
return F_23 ( F_24 ( & V_63 -> V_65 -> V_53 ) ,
F_24 ( & V_64 -> V_65 -> V_53 ) ) ;
}
static void F_25 ( struct V_4 * V_5 )
{
int V_66 = 0 ;
do {
struct V_67 * V_68 ;
struct V_67 * V_22 ;
struct V_67 * V_69 ;
V_66 = 1 ;
V_22 = NULL ;
F_26 (curr, temp,
&io->ci_lockset.cls_todo,
cill_linkage) {
if ( V_22 ) {
switch ( F_22 ( & V_22 -> V_70 ,
& V_68 -> V_70 ) ) {
case 0 :
default:
F_13 () ;
case 1 :
F_27 ( & V_68 -> V_71 ,
& V_22 -> V_71 ) ;
V_66 = 0 ;
continue;
case - 1 :
break;
}
}
V_22 = V_68 ;
}
} while ( ! V_66 );
}
static void F_28 ( struct V_62 * V_63 ,
const struct V_62 * V_64 )
{
V_63 -> V_72 = F_29 ( V_63 -> V_72 , V_64 -> V_72 ) ;
V_63 -> V_73 = F_30 ( V_63 -> V_73 , V_64 -> V_73 ) ;
if ( V_64 -> V_74 == V_75 && V_63 -> V_74 != V_75 )
V_63 -> V_74 = V_75 ;
if ( V_64 -> V_74 == V_76 && V_63 -> V_74 != V_76 )
V_63 -> V_74 = V_76 ;
}
static int F_31 ( const struct V_77 * V_78 ,
const struct V_62 * V_79 )
{
struct V_67 * V_40 ;
F_32 (scan, &set->cls_todo, cill_linkage) {
if ( ! F_33 ( V_40 -> V_70 . V_65 , V_79 -> V_65 ) )
continue;
F_28 ( & V_40 -> V_70 , V_79 ) ;
F_34 ( V_52 , L_2 ,
V_40 -> V_70 . V_74 , V_40 -> V_70 . V_72 ,
V_40 -> V_70 . V_73 ) ;
return 1 ;
}
return 0 ;
}
static int F_35 ( const struct V_8 * V_9 , struct V_4 * V_5 ,
struct V_77 * V_78 )
{
struct V_67 * V_80 ;
struct V_67 * V_69 ;
int V_41 ;
V_41 = 0 ;
F_26 (link, temp, &set->cls_todo, cill_linkage) {
V_41 = F_36 ( V_9 , V_5 , & V_80 -> V_81 ) ;
if ( V_41 < 0 )
break;
F_37 ( & V_80 -> V_71 , & V_78 -> V_45 ) ;
}
return V_41 ;
}
int F_38 ( const struct V_8 * V_9 , struct V_4 * V_5 )
{
const struct V_17 * V_40 ;
int V_41 = 0 ;
F_8 ( F_2 ( V_5 ) ) ;
F_8 ( V_5 -> V_14 == V_82 ) ;
F_8 ( F_5 ( V_5 ) ) ;
F_39 (scan, io) {
if ( ! V_40 -> V_24 -> V_25 [ V_5 -> V_6 ] . V_83 )
continue;
V_41 = V_40 -> V_24 -> V_25 [ V_5 -> V_6 ] . V_83 ( V_9 , V_40 ) ;
if ( V_41 != 0 )
break;
}
if ( V_41 == 0 ) {
F_25 ( V_5 ) ;
V_41 = F_35 ( V_9 , V_5 , & V_5 -> V_43 ) ;
}
if ( V_41 != 0 )
F_40 ( V_9 , V_5 ) ;
else
V_5 -> V_14 = V_16 ;
return V_41 ;
}
void F_40 ( const struct V_8 * V_9 , struct V_4 * V_5 )
{
struct V_77 * V_78 ;
struct V_67 * V_80 ;
struct V_67 * V_69 ;
const struct V_17 * V_40 ;
F_12 ( F_2 ( V_5 ) ) ;
F_12 ( V_82 <= V_5 -> V_14 && V_5 -> V_14 < V_84 ) ;
F_8 ( F_5 ( V_5 ) ) ;
V_78 = & V_5 -> V_43 ;
F_26 (link, temp, &set->cls_todo, cill_linkage) {
F_11 ( & V_80 -> V_71 ) ;
if ( V_80 -> V_85 )
V_80 -> V_85 ( V_9 , V_80 ) ;
}
F_26 (link, temp, &set->cls_done, cill_linkage) {
F_11 ( & V_80 -> V_71 ) ;
F_41 ( V_9 , & V_80 -> V_81 ) ;
if ( V_80 -> V_85 )
V_80 -> V_85 ( V_9 , V_80 ) ;
}
F_42 (scan, io) {
if ( V_40 -> V_24 -> V_25 [ V_5 -> V_6 ] . V_86 )
V_40 -> V_24 -> V_25 [ V_5 -> V_6 ] . V_86 ( V_9 , V_40 ) ;
}
V_5 -> V_14 = V_84 ;
}
int F_43 ( const struct V_8 * V_9 , struct V_4 * V_5 )
{
const struct V_17 * V_40 ;
int V_41 ;
F_8 ( F_2 ( V_5 ) ) ;
F_8 ( V_5 -> V_14 == V_48 || V_5 -> V_14 == V_87 ) ;
F_8 ( F_5 ( V_5 ) ) ;
V_41 = 0 ;
F_39 (scan, io) {
if ( ! V_40 -> V_24 -> V_25 [ V_5 -> V_6 ] . V_88 )
continue;
V_41 = V_40 -> V_24 -> V_25 [ V_5 -> V_6 ] . V_88 ( V_9 ,
V_40 ) ;
if ( V_41 != 0 )
break;
}
if ( V_41 == 0 )
V_5 -> V_14 = V_82 ;
return V_41 ;
}
void F_44 ( const struct V_8 * V_9 , struct V_4 * V_5 )
{
const struct V_17 * V_40 ;
F_8 ( F_2 ( V_5 ) ) ;
F_8 ( V_5 -> V_14 == V_84 ) ;
F_8 ( F_5 ( V_5 ) ) ;
F_42 (scan, io) {
if ( V_40 -> V_24 -> V_25 [ V_5 -> V_6 ] . V_89 )
V_40 -> V_24 -> V_25 [ V_5 -> V_6 ] . V_89 ( V_9 , V_40 ) ;
}
V_5 -> V_14 = V_87 ;
}
static void F_45 ( const struct V_8 * V_9 , struct V_4 * V_5 ,
T_2 V_90 )
{
const struct V_17 * V_40 ;
F_8 ( V_5 -> V_6 == V_2 || V_5 -> V_6 == V_29 ||
V_90 == 0 ) ;
F_8 ( F_2 ( V_5 ) ) ;
F_8 ( F_5 ( V_5 ) ) ;
V_5 -> V_55 . V_56 . V_60 += V_90 ;
V_5 -> V_55 . V_56 . V_61 -= V_90 ;
F_42 (scan, io) {
if ( V_40 -> V_24 -> V_25 [ V_5 -> V_6 ] . V_91 )
V_40 -> V_24 -> V_25 [ V_5 -> V_6 ] . V_91 ( V_9 , V_40 ,
V_90 ) ;
}
}
int F_46 ( const struct V_8 * V_9 , struct V_4 * V_5 ,
struct V_67 * V_80 )
{
int V_41 ;
if ( F_31 ( & V_5 -> V_43 , & V_80 -> V_70 ) ) {
V_41 = 1 ;
} else {
F_47 ( & V_80 -> V_71 , & V_5 -> V_43 . V_44 ) ;
V_41 = 0 ;
}
return V_41 ;
}
static void F_48 ( const struct V_8 * V_9 ,
struct V_67 * V_80 )
{
F_49 ( V_80 ) ;
}
int F_50 ( const struct V_8 * V_9 , struct V_4 * V_5 ,
struct V_62 * V_92 )
{
struct V_67 * V_80 ;
int V_41 ;
V_80 = F_51 ( sizeof( * V_80 ) , V_93 ) ;
if ( V_80 ) {
V_80 -> V_70 = * V_92 ;
V_80 -> V_85 = F_48 ;
V_41 = F_46 ( V_9 , V_5 , V_80 ) ;
if ( V_41 )
V_80 -> V_85 ( V_9 , V_80 ) ;
} else {
V_41 = - V_94 ;
}
return V_41 ;
}
int F_52 ( const struct V_8 * V_9 , struct V_4 * V_5 )
{
const struct V_17 * V_40 ;
int V_41 = 0 ;
F_8 ( F_2 ( V_5 ) ) ;
F_8 ( V_5 -> V_14 == V_16 ) ;
F_8 ( F_5 ( V_5 ) ) ;
V_5 -> V_14 = V_15 ;
F_39 (scan, io) {
if ( ! V_40 -> V_24 -> V_25 [ V_5 -> V_6 ] . V_95 )
continue;
V_41 = V_40 -> V_24 -> V_25 [ V_5 -> V_6 ] . V_95 ( V_9 , V_40 ) ;
if ( V_41 != 0 )
break;
}
if ( V_41 >= 0 )
V_41 = 0 ;
return V_41 ;
}
void F_53 ( const struct V_8 * V_9 , struct V_4 * V_5 )
{
const struct V_17 * V_40 ;
F_8 ( F_2 ( V_5 ) ) ;
F_8 ( V_5 -> V_14 == V_15 ) ;
F_8 ( F_5 ( V_5 ) ) ;
F_42 (scan, io) {
if ( V_40 -> V_24 -> V_25 [ V_5 -> V_6 ] . V_96 )
V_40 -> V_24 -> V_25 [ V_5 -> V_6 ] . V_96 ( V_9 , V_40 ) ;
}
V_5 -> V_14 = V_97 ;
}
int F_54 ( const struct V_8 * V_9 , struct V_4 * V_5 ,
T_3 V_98 , struct V_99 * V_100 )
{
const struct V_17 * V_40 ;
int V_41 = 0 ;
F_8 ( V_5 -> V_6 == V_2 || V_5 -> V_6 == V_31 ) ;
F_8 ( V_5 -> V_14 == V_15 || V_5 -> V_14 == V_16 ) ;
F_8 ( F_5 ( V_5 ) ) ;
F_39 (scan, io) {
if ( ! V_40 -> V_24 -> V_101 )
continue;
V_41 = V_40 -> V_24 -> V_101 ( V_9 , V_40 , V_98 , V_100 ) ;
if ( V_41 )
break;
}
return V_41 > 0 ? 0 : V_41 ;
}
int F_55 ( const struct V_8 * V_9 , struct V_4 * V_5 ,
struct V_102 * V_103 , int V_104 , int V_105 ,
T_4 V_106 )
{
const struct V_17 * V_40 ;
int V_41 = 0 ;
F_39 (scan, io) {
if ( ! V_40 -> V_24 -> V_107 )
continue;
V_41 = V_40 -> V_24 -> V_107 ( V_9 , V_40 , V_103 ,
V_104 , V_105 , V_106 ) ;
if ( V_41 != 0 )
break;
}
return V_41 ;
}
int F_56 ( const struct V_8 * V_9 , struct V_4 * V_5 ,
enum V_108 V_109 , struct V_110 * V_103 )
{
const struct V_17 * V_40 ;
int V_41 = 0 ;
F_39 (scan, io) {
if ( ! V_40 -> V_24 -> V_111 )
continue;
V_41 = V_40 -> V_24 -> V_111 ( V_9 , V_40 , V_109 , V_103 ) ;
if ( V_41 != 0 )
break;
}
F_12 ( F_6 ( V_41 != 0 , F_9 ( & V_103 -> V_112 . V_113 ) ) ) ;
return V_41 ;
}
int F_57 ( const struct V_8 * V_9 , struct V_4 * V_5 ,
enum V_108 V_37 , struct V_110 * V_103 ,
long V_114 )
{
struct V_115 * V_116 = & F_4 ( V_9 ) -> V_117 ;
struct V_118 * V_119 ;
int V_120 ;
F_58 (pg, &queue->c2_qin) {
F_12 ( ! V_119 -> V_121 ) ;
V_119 -> V_121 = V_116 ;
}
F_59 ( V_116 , V_103 -> V_122 . V_123 , & V_124 ) ;
V_120 = F_56 ( V_9 , V_5 , V_37 , V_103 ) ;
if ( V_120 == 0 ) {
F_58 (pg, &queue->c2_qin) {
V_119 -> V_121 = NULL ;
F_60 ( V_9 , V_116 , 1 ) ;
}
V_120 = F_61 ( V_9 , V_116 , V_114 ) ;
F_62 ( V_9 , V_5 , & V_103 -> V_112 ) ;
} else {
F_12 ( F_9 ( & V_103 -> V_112 . V_113 ) ) ;
F_58 (pg, &queue->c2_qin)
V_119 -> V_121 = NULL ;
}
return V_120 ;
}
int F_63 ( const struct V_8 * V_9 , struct V_4 * V_5 )
{
int V_41 = 0 ;
F_8 ( F_2 ( V_5 ) ) ;
do {
T_2 V_90 ;
V_5 -> V_125 = 0 ;
V_41 = F_43 ( V_9 , V_5 ) ;
if ( V_41 == 0 ) {
V_90 = V_5 -> V_126 ;
V_41 = F_38 ( V_9 , V_5 ) ;
if ( V_41 == 0 ) {
V_41 = F_52 ( V_9 , V_5 ) ;
F_53 ( V_9 , V_5 ) ;
F_40 ( V_9 , V_5 ) ;
F_45 ( V_9 , V_5 , V_5 -> V_126 - V_90 ) ;
}
}
F_44 ( V_9 , V_5 ) ;
} while ( V_41 == 0 && V_5 -> V_125 );
if ( V_41 == 0 )
V_41 = V_5 -> V_127 ;
return V_41 < 0 ? V_41 : 0 ;
}
void F_64 ( struct V_4 * V_5 , struct V_17 * V_18 ,
struct V_38 * V_39 ,
const struct V_128 * V_129 )
{
struct V_130 * V_131 = & V_18 -> V_23 ;
F_12 ( ( ! V_131 -> V_22 && ! V_131 -> V_132 ) ||
F_9 ( V_131 ) ) ;
F_65 ( V_131 , & V_5 -> V_21 ) ;
V_18 -> V_27 = V_5 ;
V_18 -> V_133 = V_39 ;
V_18 -> V_24 = V_129 ;
}
void F_66 ( struct V_102 * V_134 )
{
V_134 -> V_123 = 0 ;
F_15 ( & V_134 -> V_113 ) ;
V_134 -> V_135 = V_136 ;
}
void F_67 ( struct V_102 * V_134 , struct V_118 * V_137 )
{
F_12 ( V_137 -> V_138 ) ;
F_8 ( V_134 -> V_135 == V_136 ) ;
F_12 ( F_9 ( & V_137 -> V_139 ) ) ;
F_65 ( & V_137 -> V_139 , & V_134 -> V_113 ) ;
++ V_134 -> V_123 ;
F_68 ( & V_137 -> V_140 , & V_137 -> V_141 , L_3 , V_134 ) ;
F_69 ( V_137 ) ;
}
void F_70 ( const struct V_8 * V_9 , struct V_102 * V_134 ,
struct V_118 * V_137 )
{
F_12 ( V_134 -> V_123 > 0 ) ;
F_12 ( F_71 ( V_9 , V_137 ) ) ;
F_8 ( V_134 -> V_135 == V_136 ) ;
F_11 ( & V_137 -> V_139 ) ;
-- V_134 -> V_123 ;
F_72 ( & V_137 -> V_140 , & V_137 -> V_141 , L_3 , V_134 ) ;
F_73 ( V_9 , V_137 ) ;
}
void F_74 ( struct V_102 * V_142 , struct V_102 * V_143 ,
struct V_118 * V_137 )
{
F_12 ( V_143 -> V_123 > 0 ) ;
F_8 ( V_142 -> V_135 == V_136 ) ;
F_8 ( V_143 -> V_135 == V_136 ) ;
F_27 ( & V_137 -> V_139 , & V_142 -> V_113 ) ;
-- V_143 -> V_123 ;
++ V_142 -> V_123 ;
F_75 ( & V_137 -> V_140 , & V_137 -> V_141 , L_3 ,
V_143 , V_142 ) ;
}
void F_76 ( struct V_102 * V_142 , struct V_102 * V_143 ,
struct V_118 * V_137 )
{
F_12 ( V_143 -> V_123 > 0 ) ;
F_8 ( V_142 -> V_135 == V_136 ) ;
F_8 ( V_143 -> V_135 == V_136 ) ;
F_37 ( & V_137 -> V_139 , & V_142 -> V_113 ) ;
-- V_143 -> V_123 ;
++ V_142 -> V_123 ;
F_75 ( & V_137 -> V_140 , & V_137 -> V_141 , L_3 ,
V_143 , V_142 ) ;
}
void F_77 ( struct V_102 * V_144 , struct V_102 * V_145 )
{
struct V_118 * V_137 ;
struct V_118 * V_146 ;
F_8 ( V_144 -> V_135 == V_136 ) ;
F_8 ( V_145 -> V_135 == V_136 ) ;
F_78 (page, tmp, list)
F_74 ( V_145 , V_144 , V_137 ) ;
}
void F_79 ( const struct V_8 * V_9 ,
struct V_4 * V_5 , struct V_102 * V_134 )
{
struct V_118 * V_137 ;
struct V_118 * V_69 ;
F_8 ( V_134 -> V_135 == V_136 ) ;
F_78 (page, temp, plist) {
F_12 ( V_134 -> V_123 > 0 ) ;
F_11 ( & V_137 -> V_139 ) ;
-- V_134 -> V_123 ;
F_80 ( V_9 , V_5 , V_137 ) ;
F_72 ( & V_137 -> V_140 , & V_137 -> V_141 , L_3 ,
V_134 ) ;
F_73 ( V_9 , V_137 ) ;
}
}
void F_81 ( const struct V_8 * V_9 , struct V_102 * V_134 )
{
struct V_118 * V_137 ;
struct V_118 * V_69 ;
F_8 ( V_134 -> V_135 == V_136 ) ;
F_78 (page, temp, plist)
F_70 ( V_9 , V_134 , V_137 ) ;
F_12 ( V_134 -> V_123 == 0 ) ;
}
static void F_62 ( const struct V_8 * V_9 ,
struct V_4 * V_5 , struct V_102 * V_134 )
{
struct V_118 * V_137 ;
F_8 ( V_134 -> V_135 == V_136 ) ;
F_58 (page, plist)
F_82 ( V_9 , V_5 , V_137 ) ;
}
static void F_83 ( const struct V_8 * V_9 , struct V_4 * V_5 ,
struct V_102 * V_134 )
{
struct V_118 * V_137 ;
F_8 ( V_134 -> V_135 == V_136 ) ;
F_58 (page, plist)
F_84 ( V_9 , V_5 , V_137 ) ;
}
void F_85 ( struct V_110 * V_103 )
{
F_66 ( & V_103 -> V_122 ) ;
F_66 ( & V_103 -> V_112 ) ;
}
void F_86 ( const struct V_8 * V_9 ,
struct V_4 * V_5 , struct V_110 * V_103 )
{
F_79 ( V_9 , V_5 , & V_103 -> V_122 ) ;
F_79 ( V_9 , V_5 , & V_103 -> V_112 ) ;
}
void F_87 ( const struct V_8 * V_9 ,
struct V_4 * V_5 , struct V_110 * V_103 )
{
F_83 ( V_9 , V_5 , & V_103 -> V_122 ) ;
F_83 ( V_9 , V_5 , & V_103 -> V_112 ) ;
}
void F_88 ( const struct V_8 * V_9 , struct V_110 * V_103 )
{
F_81 ( V_9 , & V_103 -> V_112 ) ;
F_81 ( V_9 , & V_103 -> V_122 ) ;
}
void F_89 ( struct V_110 * V_103 , struct V_118 * V_137 )
{
F_85 ( V_103 ) ;
F_67 ( & V_103 -> V_122 , V_137 ) ;
}
struct V_4 * F_90 ( struct V_4 * V_5 )
{
while ( V_5 -> V_12 )
V_5 = V_5 -> V_12 ;
return V_5 ;
}
void F_91 ( const struct V_8 * V_9 , struct V_38 * V_39 ,
struct V_147 * V_148 )
{
struct V_38 * V_40 ;
F_16 (scan, obj) {
if ( V_40 -> V_46 -> V_149 )
V_40 -> V_46 -> V_149 ( V_9 , V_40 , V_148 ) ;
}
}
void V_124 ( const struct V_8 * V_9 , struct V_115 * V_116 )
{
F_92 ( & V_116 -> V_150 ) ;
F_93 ( & V_116 -> V_151 , 0 ) ;
}
void F_59 ( struct V_115 * V_116 , int V_152 ,
void (* F_94)( const struct V_8 * , struct V_115 * ) )
{
memset ( V_116 , 0 , sizeof( * V_116 ) ) ;
F_95 ( & V_116 -> V_150 ) ;
F_93 ( & V_116 -> V_153 , V_152 ) ;
F_93 ( & V_116 -> V_151 , V_152 > 0 ) ;
V_116 -> V_154 = 0 ;
V_116 -> V_155 = F_94 ;
F_12 ( F_94 ) ;
}
int F_61 ( const struct V_8 * V_9 , struct V_115 * V_116 ,
long V_114 )
{
struct V_156 V_157 = F_96 ( F_97 ( V_114 ) ,
NULL , NULL , NULL ) ;
int V_120 ;
F_12 ( V_114 >= 0 ) ;
V_120 = F_98 ( V_116 -> V_150 ,
F_99 ( & V_116 -> V_153 ) == 0 ,
& V_157 ) ;
if ( V_120 < 0 ) {
F_100 ( L_4 ,
V_120 , F_99 ( & V_116 -> V_153 ) ) ;
V_157 = (struct V_156 ) { 0 } ;
( void ) F_98 ( V_116 -> V_150 ,
F_99 ( & V_116 -> V_153 ) == 0 ,
& V_157 ) ;
} else {
V_120 = V_116 -> V_154 ;
}
F_12 ( F_99 ( & V_116 -> V_153 ) == 0 ) ;
while ( F_101 ( F_99 ( & V_116 -> V_151 ) != 0 ) )
F_102 () ;
return V_120 ;
}
void F_60 ( const struct V_8 * V_9 , struct V_115 * V_116 ,
int V_158 )
{
if ( V_116 -> V_154 == 0 && V_158 < 0 )
V_116 -> V_154 = V_158 ;
F_12 ( F_99 ( & V_116 -> V_153 ) > 0 ) ;
if ( F_103 ( & V_116 -> V_153 ) ) {
F_12 ( V_116 -> V_155 ) ;
V_116 -> V_155 ( V_9 , V_116 ) ;
}
}
