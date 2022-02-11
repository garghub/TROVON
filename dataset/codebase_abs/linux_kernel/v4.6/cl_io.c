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
F_15 ( & V_5 -> V_42 . V_45 ) ;
F_15 ( & V_5 -> V_21 ) ;
V_40 = 0 ;
F_16 (scan, obj) {
if ( V_39 -> V_46 -> V_47 ) {
V_40 = V_39 -> V_46 -> V_47 ( V_9 , V_39 , V_5 ) ;
if ( V_40 != 0 )
break;
}
}
if ( V_40 == 0 )
V_5 -> V_14 = V_48 ;
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
enum V_1 V_36 , T_1 V_49 , T_2 V_50 )
{
F_8 ( V_36 == V_2 || V_36 == V_29 ) ;
F_8 ( V_5 -> V_51 ) ;
F_21 ( V_52 , V_9 , & V_5 -> V_51 -> V_53 ,
L_1 ,
V_36 , ( V_54 ) V_49 , ( V_54 ) V_49 + V_50 ,
V_5 -> V_55 . V_56 . V_57 , V_5 -> V_55 . V_58 . V_59 ) ;
V_5 -> V_55 . V_56 . V_60 = V_49 ;
V_5 -> V_55 . V_56 . V_61 = V_50 ;
return F_19 ( V_9 , V_5 , V_36 , V_5 -> V_51 ) ;
}
static int F_22 ( const struct V_62 * V_63 ,
const struct V_62 * V_64 )
{
return F_23 ( F_24 ( & V_63 -> V_65 -> V_53 ) ,
F_24 ( & V_64 -> V_65 -> V_53 ) ) ? :
F_25 ( V_63 -> V_66 , V_64 -> V_66 ) ;
}
static int F_26 ( const struct V_62 * V_63 ,
const struct V_62 * V_64 )
{
int V_67 ;
V_67 = F_23 ( F_24 ( & V_63 -> V_65 -> V_53 ) ,
F_24 ( & V_64 -> V_65 -> V_53 ) ) ;
if ( V_67 )
return V_67 ;
if ( V_63 -> V_68 < V_64 -> V_66 )
return - 1 ;
if ( V_63 -> V_66 > V_63 -> V_68 )
return 1 ;
return 0 ;
}
static void F_27 ( struct V_62 * V_63 ,
const struct V_62 * V_64 )
{
V_63 -> V_66 = F_28 ( V_63 -> V_66 , V_64 -> V_66 ) ;
V_63 -> V_68 = F_29 ( V_63 -> V_68 , V_64 -> V_68 ) ;
if ( V_64 -> V_69 == V_70 && V_63 -> V_69 != V_70 )
V_63 -> V_69 = V_70 ;
if ( V_64 -> V_69 == V_71 && V_63 -> V_69 != V_71 )
V_63 -> V_69 = V_71 ;
}
static void F_30 ( struct V_4 * V_5 )
{
int V_72 = 0 ;
do {
struct V_73 * V_74 ;
struct V_73 * V_22 ;
struct V_73 * V_75 ;
V_72 = 1 ;
V_22 = NULL ;
F_31 (curr, temp,
&io->ci_lockset.cls_todo,
cill_linkage) {
if ( V_22 ) {
switch ( F_22 ( & V_22 -> V_76 ,
& V_74 -> V_76 ) ) {
case 0 :
default:
F_13 () ;
case 1 :
F_32 ( & V_74 -> V_77 ,
& V_22 -> V_77 ) ;
V_72 = 0 ;
continue;
case - 1 :
break;
}
}
V_22 = V_74 ;
}
} while ( ! V_72 );
}
int F_33 ( const struct V_78 * V_79 ,
const struct V_62 * V_80 )
{
struct V_73 * V_39 ;
F_34 (scan, queue, cill_linkage) {
if ( F_35 ( & V_39 -> V_76 , V_80 ) )
return 1 ;
}
return 0 ;
}
static int F_36 ( const struct V_78 * V_79 ,
const struct V_62 * V_80 )
{
struct V_73 * V_39 ;
F_34 (scan, queue, cill_linkage) {
if ( F_26 ( & V_39 -> V_76 , V_80 ) )
continue;
F_27 ( & V_39 -> V_76 , V_80 ) ;
F_37 ( V_52 , L_2 ,
V_39 -> V_76 . V_69 , V_39 -> V_76 . V_66 ,
V_39 -> V_76 . V_68 ) ;
return 1 ;
}
return 0 ;
}
static int F_38 ( const struct V_81 * V_82 ,
const struct V_62 * V_80 )
{
return F_33 ( & V_82 -> V_44 , V_80 ) ||
F_33 ( & V_82 -> V_45 , V_80 ) ;
}
static int F_39 ( const struct V_81 * V_82 ,
const struct V_62 * V_80 )
{
return F_36 ( & V_82 -> V_43 , V_80 ) ||
F_38 ( V_82 , V_80 ) ;
}
static int F_40 ( const struct V_8 * V_9 ,
struct V_4 * V_5 , struct V_81 * V_82 ,
struct V_73 * V_83 )
{
struct V_84 * V_85 ;
int V_40 ;
V_85 = F_41 ( V_9 , V_5 , & V_83 -> V_76 , L_3 , V_5 ) ;
if ( ! F_42 ( V_85 ) ) {
V_83 -> V_86 = V_85 ;
F_43 ( & V_83 -> V_77 , & V_82 -> V_44 ) ;
if ( ! ( V_83 -> V_76 . V_87 & V_88 ) ) {
V_40 = F_44 ( V_9 , V_85 ) ;
if ( V_40 == 0 )
F_43 ( & V_83 -> V_77 , & V_82 -> V_45 ) ;
} else
V_40 = 0 ;
} else
V_40 = F_45 ( V_85 ) ;
return V_40 ;
}
static void F_46 ( const struct V_8 * V_9 , struct V_4 * V_5 ,
struct V_73 * V_83 )
{
struct V_84 * V_85 = V_83 -> V_86 ;
F_11 ( & V_83 -> V_77 ) ;
if ( V_85 ) {
F_47 ( V_9 , V_85 , L_3 , V_5 ) ;
V_83 -> V_86 = NULL ;
}
if ( V_83 -> V_89 )
V_83 -> V_89 ( V_9 , V_83 ) ;
}
static int F_48 ( const struct V_8 * V_9 , struct V_4 * V_5 ,
struct V_81 * V_82 )
{
struct V_73 * V_83 ;
struct V_73 * V_75 ;
struct V_84 * V_85 ;
int V_40 ;
V_40 = 0 ;
F_31 (link, temp, &set->cls_todo, cill_linkage) {
if ( ! F_38 ( V_82 , & V_83 -> V_76 ) ) {
V_40 = F_40 ( V_9 , V_5 , V_82 , V_83 ) ;
if ( V_40 != 0 )
break;
} else
F_46 ( V_9 , V_5 , V_83 ) ;
}
if ( V_40 == 0 ) {
F_31 (link, temp,
&set->cls_curr, cill_linkage) {
V_85 = V_83 -> V_86 ;
V_40 = F_44 ( V_9 , V_85 ) ;
if ( V_40 == 0 )
F_43 ( & V_83 -> V_77 , & V_82 -> V_45 ) ;
else
break;
}
}
return V_40 ;
}
int F_49 ( const struct V_8 * V_9 , struct V_4 * V_5 )
{
const struct V_17 * V_39 ;
int V_40 = 0 ;
F_8 ( F_2 ( V_5 ) ) ;
F_8 ( V_5 -> V_14 == V_90 ) ;
F_8 ( F_5 ( V_5 ) ) ;
F_50 (scan, io) {
if ( ! V_39 -> V_24 -> V_25 [ V_5 -> V_6 ] . V_91 )
continue;
V_40 = V_39 -> V_24 -> V_25 [ V_5 -> V_6 ] . V_91 ( V_9 , V_39 ) ;
if ( V_40 != 0 )
break;
}
if ( V_40 == 0 ) {
F_30 ( V_5 ) ;
V_40 = F_48 ( V_9 , V_5 , & V_5 -> V_42 ) ;
}
if ( V_40 != 0 )
F_51 ( V_9 , V_5 ) ;
else
V_5 -> V_14 = V_16 ;
return V_40 ;
}
void F_51 ( const struct V_8 * V_9 , struct V_4 * V_5 )
{
struct V_81 * V_82 ;
struct V_73 * V_83 ;
struct V_73 * V_75 ;
const struct V_17 * V_39 ;
F_12 ( F_2 ( V_5 ) ) ;
F_12 ( V_90 <= V_5 -> V_14 && V_5 -> V_14 < V_92 ) ;
F_8 ( F_5 ( V_5 ) ) ;
V_82 = & V_5 -> V_42 ;
F_31 (link, temp, &set->cls_todo, cill_linkage)
F_46 ( V_9 , V_5 , V_83 ) ;
F_31 (link, temp, &set->cls_curr, cill_linkage)
F_46 ( V_9 , V_5 , V_83 ) ;
F_31 (link, temp, &set->cls_done, cill_linkage) {
F_52 ( V_9 , V_83 -> V_86 ) ;
F_46 ( V_9 , V_5 , V_83 ) ;
}
F_53 (scan, io) {
if ( V_39 -> V_24 -> V_25 [ V_5 -> V_6 ] . V_93 )
V_39 -> V_24 -> V_25 [ V_5 -> V_6 ] . V_93 ( V_9 , V_39 ) ;
}
V_5 -> V_14 = V_92 ;
F_12 ( ! F_4 ( V_9 ) -> V_94 [ V_95 ] . V_96 ) ;
}
int F_54 ( const struct V_8 * V_9 , struct V_4 * V_5 )
{
const struct V_17 * V_39 ;
int V_40 ;
F_8 ( F_2 ( V_5 ) ) ;
F_8 ( V_5 -> V_14 == V_48 || V_5 -> V_14 == V_97 ) ;
F_8 ( F_5 ( V_5 ) ) ;
V_40 = 0 ;
F_50 (scan, io) {
if ( ! V_39 -> V_24 -> V_25 [ V_5 -> V_6 ] . V_98 )
continue;
V_40 = V_39 -> V_24 -> V_25 [ V_5 -> V_6 ] . V_98 ( V_9 ,
V_39 ) ;
if ( V_40 != 0 )
break;
}
if ( V_40 == 0 )
V_5 -> V_14 = V_90 ;
return V_40 ;
}
void F_55 ( const struct V_8 * V_9 , struct V_4 * V_5 )
{
const struct V_17 * V_39 ;
F_8 ( F_2 ( V_5 ) ) ;
F_8 ( V_5 -> V_14 == V_92 ) ;
F_8 ( F_5 ( V_5 ) ) ;
F_53 (scan, io) {
if ( V_39 -> V_24 -> V_25 [ V_5 -> V_6 ] . V_99 )
V_39 -> V_24 -> V_25 [ V_5 -> V_6 ] . V_99 ( V_9 , V_39 ) ;
}
V_5 -> V_14 = V_97 ;
}
static void F_56 ( const struct V_8 * V_9 , struct V_4 * V_5 ,
T_2 V_100 )
{
const struct V_17 * V_39 ;
F_8 ( V_5 -> V_6 == V_2 || V_5 -> V_6 == V_29 ||
V_100 == 0 ) ;
F_8 ( F_2 ( V_5 ) ) ;
F_8 ( F_5 ( V_5 ) ) ;
V_5 -> V_55 . V_56 . V_60 += V_100 ;
V_5 -> V_55 . V_56 . V_61 -= V_100 ;
F_53 (scan, io) {
if ( V_39 -> V_24 -> V_25 [ V_5 -> V_6 ] . V_101 )
V_39 -> V_24 -> V_25 [ V_5 -> V_6 ] . V_101 ( V_9 , V_39 ,
V_100 ) ;
}
}
int F_57 ( const struct V_8 * V_9 , struct V_4 * V_5 ,
struct V_73 * V_83 )
{
int V_40 ;
if ( F_39 ( & V_5 -> V_42 , & V_83 -> V_76 ) )
V_40 = 1 ;
else {
F_58 ( & V_83 -> V_77 , & V_5 -> V_42 . V_43 ) ;
V_40 = 0 ;
}
return V_40 ;
}
static void F_59 ( const struct V_8 * V_9 ,
struct V_73 * V_83 )
{
F_60 ( V_83 ) ;
}
int F_61 ( const struct V_8 * V_9 , struct V_4 * V_5 ,
struct V_62 * V_102 )
{
struct V_73 * V_83 ;
int V_40 ;
V_83 = F_62 ( sizeof( * V_83 ) , V_103 ) ;
if ( V_83 ) {
V_83 -> V_76 = * V_102 ;
V_83 -> V_89 = F_59 ;
V_40 = F_57 ( V_9 , V_5 , V_83 ) ;
if ( V_40 )
V_83 -> V_89 ( V_9 , V_83 ) ;
} else
V_40 = - V_104 ;
return V_40 ;
}
int F_63 ( const struct V_8 * V_9 , struct V_4 * V_5 )
{
const struct V_17 * V_39 ;
int V_40 = 0 ;
F_8 ( F_2 ( V_5 ) ) ;
F_8 ( V_5 -> V_14 == V_16 ) ;
F_8 ( F_5 ( V_5 ) ) ;
V_5 -> V_14 = V_15 ;
F_50 (scan, io) {
if ( ! V_39 -> V_24 -> V_25 [ V_5 -> V_6 ] . V_105 )
continue;
V_40 = V_39 -> V_24 -> V_25 [ V_5 -> V_6 ] . V_105 ( V_9 , V_39 ) ;
if ( V_40 != 0 )
break;
}
if ( V_40 >= 0 )
V_40 = 0 ;
return V_40 ;
}
void F_64 ( const struct V_8 * V_9 , struct V_4 * V_5 )
{
const struct V_17 * V_39 ;
F_8 ( F_2 ( V_5 ) ) ;
F_8 ( V_5 -> V_14 == V_15 ) ;
F_8 ( F_5 ( V_5 ) ) ;
F_53 (scan, io) {
if ( V_39 -> V_24 -> V_25 [ V_5 -> V_6 ] . V_106 )
V_39 -> V_24 -> V_25 [ V_5 -> V_6 ] . V_106 ( V_9 , V_39 ) ;
}
V_5 -> V_14 = V_107 ;
}
static const struct V_108 *
F_65 ( const struct V_17 * V_109 , struct V_110 * V_111 )
{
const struct V_108 * V_18 ;
V_18 = F_66 ( V_111 , V_109 -> V_112 -> V_53 . V_113 -> V_114 ) ;
F_8 ( V_18 ) ;
return V_18 ;
}
static int F_67 ( const struct V_110 * V_111 , const struct V_4 * V_5 )
{
int V_40 = 1 ;
T_1 V_115 ;
T_1 V_116 ;
T_3 V_117 ;
V_117 = V_111 -> V_118 ;
switch ( V_5 -> V_6 ) {
case V_2 :
case V_29 :
if ( ! F_68 ( V_5 ) ) {
const struct V_119 * V_120 = & ( V_5 -> V_55 . V_56 ) ;
V_115 = F_69 ( V_111 -> V_121 , V_117 ) ;
V_116 = F_69 ( V_111 -> V_121 , V_117 + 1 ) ;
V_40 = V_120 -> V_60 < V_116 &&
V_115 < V_120 -> V_60 + V_120 -> V_61 ;
}
break;
case V_30 :
V_40 = V_5 -> V_55 . V_122 . V_123 == V_117 ;
break;
default:
F_13 () ;
}
return V_40 ;
}
int F_70 ( const struct V_8 * V_9 , struct V_4 * V_5 ,
struct V_110 * V_111 )
{
const struct V_17 * V_39 ;
struct V_124 * V_79 ;
int V_40 = 0 ;
F_8 ( V_5 -> V_6 == V_2 || V_5 -> V_6 == V_30 ) ;
F_8 ( F_71 ( V_111 , V_5 ) ) ;
F_8 ( V_5 -> V_14 == V_15 || V_5 -> V_14 == V_16 ) ;
F_8 ( F_67 ( V_111 , V_5 ) ) ;
F_8 ( F_5 ( V_5 ) ) ;
V_79 = & V_5 -> V_125 ;
F_72 ( V_79 ) ;
F_50 (scan, io) {
if ( V_39 -> V_24 -> V_126 ) {
const struct V_108 * V_18 ;
V_18 = F_65 ( V_39 , V_111 ) ;
F_8 ( V_18 ) ;
V_40 = V_39 -> V_24 -> V_126 ( V_9 , V_39 , V_18 ) ;
if ( V_40 != 0 )
break;
}
}
if ( V_40 == 0 )
V_40 = F_73 ( V_9 , V_5 , V_127 , V_79 ) ;
F_74 ( V_9 , V_5 , & V_79 -> V_128 ) ;
F_75 ( V_9 , V_79 ) ;
return V_40 ;
}
int F_76 ( const struct V_8 * V_9 , struct V_4 * V_5 ,
struct V_110 * V_111 , unsigned V_129 , unsigned V_130 )
{
const struct V_17 * V_39 ;
int V_40 = 0 ;
F_8 ( V_5 -> V_6 == V_29 ) ;
F_8 ( F_71 ( V_111 , V_5 ) ) ;
F_8 ( V_5 -> V_14 == V_15 || V_5 -> V_14 == V_16 ) ;
F_8 ( F_5 ( V_5 ) ) ;
F_12 ( F_67 ( V_111 , V_5 ) ) ;
F_53 (scan, io) {
if ( V_39 -> V_24 -> V_131 ) {
const struct V_108 * V_18 ;
V_18 = F_65 ( V_39 , V_111 ) ;
V_40 = V_39 -> V_24 -> V_131 ( V_9 , V_39 ,
V_18 ,
V_129 , V_130 ) ;
if ( V_40 != 0 )
break;
}
}
return V_40 ;
}
int F_77 ( const struct V_8 * V_9 , struct V_4 * V_5 ,
struct V_110 * V_111 , unsigned V_129 , unsigned V_130 )
{
const struct V_17 * V_39 ;
int V_40 = 0 ;
F_8 ( V_5 -> V_6 == V_29 ) ;
F_8 ( V_5 -> V_14 == V_15 || V_5 -> V_14 == V_16 ) ;
F_8 ( F_5 ( V_5 ) ) ;
F_12 ( F_71 ( V_111 , V_5 ) || V_111 -> V_132 ) ;
F_12 ( F_67 ( V_111 , V_5 ) ) ;
F_50 (scan, io) {
if ( V_39 -> V_24 -> V_133 ) {
const struct V_108 * V_18 ;
V_18 = F_65 ( V_39 , V_111 ) ;
V_40 = V_39 -> V_24 -> V_133 ( V_9 , V_39 ,
V_18 ,
V_129 , V_130 ) ;
if ( V_40 != 0 )
break;
}
}
F_8 ( V_40 <= 0 ) ;
return V_40 ;
}
int F_73 ( const struct V_8 * V_9 , struct V_4 * V_5 ,
enum V_134 V_135 , struct V_124 * V_79 )
{
const struct V_17 * V_39 ;
int V_40 = 0 ;
F_8 ( V_135 < F_78 ( V_39 -> V_24 -> V_136 ) ) ;
F_50 (scan, io) {
if ( ! V_39 -> V_24 -> V_136 [ V_135 ] . V_137 )
continue;
V_40 = V_39 -> V_24 -> V_136 [ V_135 ] . V_137 ( V_9 , V_39 , V_135 ,
V_79 ) ;
if ( V_40 != 0 )
break;
}
F_12 ( F_6 ( V_40 != 0 , F_9 ( & V_79 -> V_138 . V_139 ) ) ) ;
return V_40 ;
}
int F_79 ( const struct V_8 * V_9 , struct V_4 * V_5 ,
enum V_134 V_36 , struct V_124 * V_79 ,
long V_140 )
{
struct V_141 * V_142 = & F_4 ( V_9 ) -> V_143 ;
struct V_110 * V_144 ;
int V_145 ;
F_80 (pg, &queue->c2_qin) {
F_12 ( ! V_144 -> V_146 ) ;
V_144 -> V_146 = V_142 ;
}
F_81 ( V_142 , V_79 -> V_128 . V_147 ) ;
V_145 = F_73 ( V_9 , V_5 , V_36 , V_79 ) ;
if ( V_145 == 0 ) {
F_80 (pg, &queue->c2_qin) {
V_144 -> V_146 = NULL ;
F_82 ( V_142 , 1 ) ;
}
V_145 = F_83 ( V_9 , V_5 , & V_79 -> V_138 ,
V_142 , V_140 ) ;
} else {
F_12 ( F_9 ( & V_79 -> V_138 . V_139 ) ) ;
F_80 (pg, &queue->c2_qin)
V_144 -> V_146 = NULL ;
}
return V_145 ;
}
static int F_84 ( const struct V_8 * V_9 , struct V_4 * V_5 ,
struct V_148 * V_79 )
{
struct V_110 * V_111 ;
int V_40 = 0 ;
F_85 ( L_4 ) ;
F_80 (page, queue) {
int V_145 ;
F_8 ( F_67 ( V_111 , V_5 ) ) ;
V_145 = F_86 ( V_9 , V_111 ) ;
V_40 = V_40 ? : V_145 ;
}
return V_40 ;
}
int F_87 ( const struct V_8 * V_9 , struct V_4 * V_5 )
{
int V_40 = 0 ;
F_8 ( F_2 ( V_5 ) ) ;
do {
T_2 V_100 ;
V_5 -> V_149 = 0 ;
V_40 = F_54 ( V_9 , V_5 ) ;
if ( V_40 == 0 ) {
V_100 = V_5 -> V_150 ;
V_40 = F_49 ( V_9 , V_5 ) ;
if ( V_40 == 0 ) {
V_40 = F_63 ( V_9 , V_5 ) ;
F_64 ( V_9 , V_5 ) ;
F_51 ( V_9 , V_5 ) ;
F_56 ( V_9 , V_5 , V_5 -> V_150 - V_100 ) ;
}
}
F_55 ( V_9 , V_5 ) ;
} while ( V_40 == 0 && V_5 -> V_149 );
if ( V_40 == 0 )
V_40 = V_5 -> V_151 ;
return V_40 < 0 ? V_40 : 0 ;
}
void F_88 ( struct V_4 * V_5 , struct V_17 * V_18 ,
struct V_37 * V_38 ,
const struct V_152 * V_153 )
{
struct V_78 * V_154 = & V_18 -> V_23 ;
F_12 ( ( ! V_154 -> V_22 && ! V_154 -> V_155 ) ||
F_9 ( V_154 ) ) ;
F_89 ( V_154 , & V_5 -> V_21 ) ;
V_18 -> V_27 = V_5 ;
V_18 -> V_112 = V_38 ;
V_18 -> V_24 = V_153 ;
}
void F_90 ( struct V_148 * V_156 )
{
V_156 -> V_147 = 0 ;
F_15 ( & V_156 -> V_139 ) ;
V_156 -> V_157 = V_158 ;
}
void F_91 ( struct V_148 * V_156 , struct V_110 * V_111 )
{
F_12 ( V_111 -> V_159 ) ;
F_8 ( V_156 -> V_157 == V_158 ) ;
F_92 () ;
F_93 ( & V_111 -> V_160 ) ;
F_94 () ;
F_12 ( F_9 ( & V_111 -> V_161 ) ) ;
F_89 ( & V_111 -> V_161 , & V_156 -> V_139 ) ;
++ V_156 -> V_147 ;
F_95 ( & V_111 -> V_162 , & V_111 -> V_163 , L_5 , V_156 ) ;
F_96 ( V_111 ) ;
}
static void F_97 ( const struct V_8 * V_9 ,
struct V_148 * V_156 , struct V_110 * V_111 )
{
F_12 ( V_156 -> V_147 > 0 ) ;
F_8 ( V_156 -> V_157 == V_158 ) ;
F_11 ( & V_111 -> V_161 ) ;
F_92 () ;
F_98 ( & V_111 -> V_160 ) ;
F_94 () ;
-- V_156 -> V_147 ;
F_99 ( & V_111 -> V_162 , & V_111 -> V_163 , L_5 , V_156 ) ;
F_100 ( V_9 , V_111 ) ;
}
void F_101 ( struct V_148 * V_164 , struct V_148 * V_165 ,
struct V_110 * V_111 )
{
F_12 ( V_165 -> V_147 > 0 ) ;
F_8 ( V_164 -> V_157 == V_158 ) ;
F_8 ( V_165 -> V_157 == V_158 ) ;
F_32 ( & V_111 -> V_161 , & V_164 -> V_139 ) ;
-- V_165 -> V_147 ;
++ V_164 -> V_147 ;
F_102 ( & V_111 -> V_162 , & V_111 -> V_163 , L_5 ,
V_165 , V_164 ) ;
}
void F_103 ( struct V_148 * V_166 , struct V_148 * V_167 )
{
struct V_110 * V_111 ;
struct V_110 * V_168 ;
F_8 ( V_166 -> V_157 == V_158 ) ;
F_8 ( V_167 -> V_157 == V_158 ) ;
F_104 (page, tmp, list)
F_101 ( V_167 , V_166 , V_111 ) ;
}
void F_74 ( const struct V_8 * V_9 ,
struct V_4 * V_5 , struct V_148 * V_156 )
{
struct V_110 * V_111 ;
struct V_110 * V_75 ;
F_8 ( V_156 -> V_157 == V_158 ) ;
F_104 (page, temp, plist) {
F_12 ( V_156 -> V_147 > 0 ) ;
F_11 ( & V_111 -> V_161 ) ;
F_92 () ;
F_98 ( & V_111 -> V_160 ) ;
F_94 () ;
-- V_156 -> V_147 ;
F_105 ( V_9 , V_5 , V_111 ) ;
F_99 ( & V_111 -> V_162 , & V_111 -> V_163 , L_5 ,
V_156 ) ;
F_100 ( V_9 , V_111 ) ;
}
}
static void F_106 ( const struct V_8 * V_9 ,
struct V_148 * V_156 )
{
struct V_110 * V_111 ;
struct V_110 * V_75 ;
F_8 ( V_156 -> V_157 == V_158 ) ;
F_104 (page, temp, plist)
F_97 ( V_9 , V_156 , V_111 ) ;
F_12 ( V_156 -> V_147 == 0 ) ;
}
static void F_107 ( const struct V_8 * V_9 ,
struct V_4 * V_5 , struct V_148 * V_156 )
{
struct V_110 * V_111 ;
F_8 ( V_156 -> V_157 == V_158 ) ;
F_80 (page, plist)
F_108 ( V_9 , V_5 , V_111 ) ;
}
static void F_109 ( const struct V_8 * V_9 , struct V_4 * V_5 ,
struct V_148 * V_156 )
{
struct V_110 * V_111 ;
F_8 ( V_156 -> V_157 == V_158 ) ;
F_80 (page, plist)
F_110 ( V_9 , V_5 , V_111 ) ;
}
void F_72 ( struct V_124 * V_79 )
{
F_90 ( & V_79 -> V_128 ) ;
F_90 ( & V_79 -> V_138 ) ;
}
void F_111 ( const struct V_8 * V_9 ,
struct V_4 * V_5 , struct V_124 * V_79 )
{
F_74 ( V_9 , V_5 , & V_79 -> V_128 ) ;
F_74 ( V_9 , V_5 , & V_79 -> V_138 ) ;
}
void F_112 ( const struct V_8 * V_9 ,
struct V_4 * V_5 , struct V_124 * V_79 )
{
F_109 ( V_9 , V_5 , & V_79 -> V_128 ) ;
F_109 ( V_9 , V_5 , & V_79 -> V_138 ) ;
}
void F_75 ( const struct V_8 * V_9 , struct V_124 * V_79 )
{
F_106 ( V_9 , & V_79 -> V_138 ) ;
F_106 ( V_9 , & V_79 -> V_128 ) ;
}
void F_113 ( struct V_124 * V_79 , struct V_110 * V_111 )
{
F_72 ( V_79 ) ;
F_91 ( & V_79 -> V_128 , V_111 ) ;
}
struct V_4 * F_114 ( struct V_4 * V_5 )
{
while ( V_5 -> V_12 )
V_5 = V_5 -> V_12 ;
return V_5 ;
}
void F_115 ( struct V_169 * V_170 , struct V_171 * V_18 ,
struct V_172 * V_173 ,
const struct V_174 * V_153 )
{
F_89 ( & V_18 -> V_175 , & V_170 -> V_176 ) ;
V_18 -> V_177 = V_173 ;
V_18 -> V_178 = V_153 ;
V_18 -> V_179 = V_170 ;
}
static void F_116 ( const struct V_8 * V_9 , struct V_169 * V_170 )
{
unsigned V_180 ;
F_12 ( F_9 ( & V_170 -> V_181 ) ) ;
F_12 ( V_170 -> V_182 == 0 ) ;
F_8 ( F_9 ( & V_170 -> V_176 ) ) ;
F_8 ( F_117 ( V_170 -> V_183 > 0 , V_170 -> V_184 ) ) ;
if ( V_170 -> V_184 ) {
for ( V_180 = 0 ; V_180 < V_170 -> V_183 ; ++ V_180 ) {
struct V_37 * V_38 = V_170 -> V_184 [ V_180 ] . V_185 ;
if ( V_38 ) {
F_118 ( & V_38 -> V_53 ,
& V_170 -> V_184 [ V_180 ] . V_186 ,
L_6 , V_170 ) ;
F_119 ( V_9 , V_38 ) ;
}
}
F_60 ( V_170 -> V_184 ) ;
}
F_60 ( V_170 ) ;
}
static int F_120 ( const struct V_8 * V_9 , struct V_169 * V_170 ,
struct V_110 * V_111 )
{
struct V_172 * V_173 ;
struct V_108 * V_18 ;
int V_40 ;
V_40 = 0 ;
V_111 = F_121 ( V_111 ) ;
do {
F_34 (slice, &page->cp_layers, cpl_linkage) {
V_173 = F_122 ( V_18 -> V_187 -> V_53 . V_113 ) ;
if ( V_173 -> V_188 -> V_189 ) {
V_40 = V_173 -> V_188 -> V_189 ( V_9 ,
V_173 , V_170 ) ;
if ( V_40 != 0 )
break;
}
}
V_111 = V_111 -> V_190 ;
} while ( V_111 && V_40 == 0 );
return V_40 ;
}
void F_123 ( const struct V_8 * V_9 , struct V_169 * V_170 , int V_145 )
{
struct V_171 * V_18 ;
while ( ! F_9 ( & V_170 -> V_176 ) ) {
V_18 = F_124 ( V_170 -> V_176 . V_22 ,
struct V_171 , V_175 ) ;
F_11 ( & V_18 -> V_175 ) ;
if ( V_18 -> V_178 -> V_191 )
V_18 -> V_178 -> V_191 ( V_9 , V_18 , V_145 ) ;
}
F_116 ( V_9 , V_170 ) ;
}
struct V_169 * F_125 ( const struct V_8 * V_9 , struct V_110 * V_111 ,
enum V_134 V_135 , int V_192 )
{
struct V_169 * V_170 ;
F_8 ( V_192 > 0 ) ;
V_170 = F_62 ( sizeof( * V_170 ) , V_103 ) ;
if ( V_170 ) {
int V_40 ;
V_170 -> V_193 = V_135 ;
F_15 ( & V_170 -> V_181 ) ;
F_15 ( & V_170 -> V_176 ) ;
V_170 -> V_184 = F_126 ( V_192 , sizeof( V_170 -> V_184 [ 0 ] ) ,
V_103 ) ;
if ( V_170 -> V_184 ) {
V_170 -> V_183 = V_192 ;
V_40 = F_120 ( V_9 , V_170 , V_111 ) ;
} else
V_40 = - V_104 ;
if ( V_40 != 0 ) {
F_123 ( V_9 , V_170 , V_40 ) ;
V_170 = F_127 ( V_40 ) ;
}
} else
V_170 = F_127 ( - V_104 ) ;
return V_170 ;
}
void F_128 ( const struct V_8 * V_9 ,
struct V_169 * V_170 , struct V_110 * V_111 )
{
struct V_37 * V_38 ;
struct V_194 * V_195 ;
int V_180 ;
V_111 = F_121 ( V_111 ) ;
F_12 ( F_9 ( & V_111 -> V_196 ) ) ;
F_12 ( ! V_111 -> V_197 ) ;
F_129 ( V_198 , V_9 , V_111 , L_7 ,
V_170 , V_170 -> V_193 , V_170 -> V_182 ) ;
F_89 ( & V_111 -> V_196 , & V_170 -> V_181 ) ;
++ V_170 -> V_182 ;
V_111 -> V_197 = V_170 ;
V_38 = F_18 ( V_111 -> V_121 ) ;
for ( V_180 = 0 , V_195 = V_170 -> V_184 ; V_38 != V_195 -> V_185 ; ++ V_180 , ++ V_195 ) {
if ( ! V_195 -> V_185 ) {
V_195 -> V_185 = V_38 ;
F_130 ( V_38 ) ;
F_131 ( & V_38 -> V_53 , & V_195 -> V_186 ,
L_6 , V_170 ) ;
break;
}
}
F_12 ( V_180 < V_170 -> V_183 ) ;
}
void F_132 ( const struct V_8 * V_9 , struct V_110 * V_111 )
{
struct V_169 * V_170 = V_111 -> V_197 ;
V_111 = F_121 ( V_111 ) ;
F_12 ( ! F_9 ( & V_111 -> V_196 ) ) ;
F_12 ( V_170 -> V_182 > 0 ) ;
F_11 ( & V_111 -> V_196 ) ;
-- V_170 -> V_182 ;
V_111 -> V_197 = NULL ;
}
int F_133 ( const struct V_8 * V_9 , struct V_169 * V_170 )
{
int V_180 ;
int V_40 ;
const struct V_171 * V_18 ;
for ( V_180 = 0 ; V_180 < V_170 -> V_183 ; ++ V_180 )
F_12 ( V_170 -> V_184 [ V_180 ] . V_185 ) ;
V_40 = 0 ;
F_34 (slice, &req->crq_layers, crs_linkage) {
if ( V_18 -> V_178 -> V_199 ) {
V_40 = V_18 -> V_178 -> V_199 ( V_9 , V_18 ) ;
if ( V_40 != 0 )
break;
}
}
return V_40 ;
}
void F_134 ( const struct V_8 * V_9 , struct V_169 * V_170 ,
struct V_200 * V_201 , T_4 V_202 )
{
const struct V_171 * V_18 ;
struct V_110 * V_111 ;
int V_180 ;
F_12 ( ! F_9 ( & V_170 -> V_181 ) ) ;
V_111 = F_124 ( V_170 -> V_181 . V_155 , struct V_110 , V_196 ) ;
for ( V_180 = 0 ; V_180 < V_170 -> V_183 ; ++ V_180 ) {
F_34 (slice, &req->crq_layers, crs_linkage) {
const struct V_108 * V_39 ;
const struct V_37 * V_38 ;
V_39 = F_66 ( V_111 ,
V_18 -> V_177 -> V_203 . V_114 ) ;
V_38 = V_39 -> V_187 ;
if ( V_18 -> V_178 -> V_204 )
V_18 -> V_178 -> V_204 ( V_9 , V_18 , V_38 ,
V_201 + V_180 , V_202 ) ;
}
}
}
void F_81 ( struct V_141 * V_142 , int V_205 )
{
F_135 ( & V_142 -> V_206 ) ;
F_136 ( & V_142 -> V_207 , V_205 ) ;
F_136 ( & V_142 -> V_208 , V_205 > 0 ) ;
V_142 -> V_209 = 0 ;
}
int F_83 ( const struct V_8 * V_9 , struct V_4 * V_5 ,
struct V_148 * V_79 , struct V_141 * V_142 ,
long V_140 )
{
struct V_210 V_211 = F_137 ( F_138 ( V_140 ) ,
NULL , NULL , NULL ) ;
int V_145 ;
F_12 ( V_140 >= 0 ) ;
V_145 = F_139 ( V_142 -> V_206 ,
F_140 ( & V_142 -> V_207 ) == 0 ,
& V_211 ) ;
if ( V_145 < 0 ) {
F_85 ( L_8 ,
V_145 , F_140 ( & V_142 -> V_207 ) ) ;
( void ) F_84 ( V_9 , V_5 , V_79 ) ;
V_211 = (struct V_210 ) { 0 } ;
( void ) F_139 ( V_142 -> V_206 ,
F_140 ( & V_142 -> V_207 ) == 0 ,
& V_211 ) ;
} else {
V_145 = V_142 -> V_209 ;
}
F_12 ( F_140 ( & V_142 -> V_207 ) == 0 ) ;
F_107 ( V_9 , V_5 , V_79 ) ;
while ( F_141 ( F_140 ( & V_142 -> V_208 ) != 0 ) ) {
F_142 () ;
}
F_143 ( V_142 , 0x5a , sizeof( * V_142 ) ) ;
return V_145 ;
}
void F_82 ( struct V_141 * V_142 , int V_212 )
{
if ( V_142 -> V_209 == 0 && V_212 < 0 )
V_142 -> V_209 = V_212 ;
F_12 ( F_140 ( & V_142 -> V_207 ) > 0 ) ;
if ( F_144 ( & V_142 -> V_207 ) ) {
F_145 ( & V_142 -> V_206 ) ;
F_136 ( & V_142 -> V_208 , 0 ) ;
}
}
