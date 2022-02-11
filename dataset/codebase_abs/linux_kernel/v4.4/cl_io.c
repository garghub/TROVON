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
( V_5 -> V_14 == V_16 && V_11 != NULL ) ) ;
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
if ( V_18 -> V_24 -> V_25 [ V_5 -> V_6 ] . V_26 != NULL )
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
if ( V_39 -> V_46 -> V_47 != NULL ) {
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
if ( V_20 -> V_10 == NULL )
V_20 -> V_10 = V_5 ;
return F_14 ( V_9 , V_5 , V_36 , V_38 ) ;
}
int F_19 ( const struct V_8 * V_9 , struct V_4 * V_5 ,
enum V_1 V_36 , struct V_37 * V_38 )
{
struct V_19 * V_20 = F_4 ( V_9 ) ;
F_12 ( V_38 == F_18 ( V_38 ) ) ;
F_12 ( V_20 -> V_10 == NULL ) ;
V_20 -> V_10 = V_5 ;
return F_14 ( V_9 , V_5 , V_36 , V_38 ) ;
}
int F_20 ( const struct V_8 * V_9 , struct V_4 * V_5 ,
enum V_1 V_36 , T_1 V_49 , T_2 V_50 )
{
F_8 ( V_36 == V_2 || V_36 == V_29 ) ;
F_8 ( V_5 -> V_51 != NULL ) ;
F_21 ( V_52 , V_9 , & V_5 -> V_51 -> V_53 ,
L_1 ,
V_36 , ( V_54 ) V_49 , ( V_54 ) V_49 + V_50 ,
V_5 -> V_55 . V_56 . V_57 , V_5 -> V_55 . V_58 . V_59 ) ;
V_5 -> V_55 . V_56 . V_60 = V_49 ;
V_5 -> V_55 . V_56 . V_61 = V_50 ;
return F_19 ( V_9 , V_5 , V_36 , V_5 -> V_51 ) ;
}
static inline const struct V_62 *
F_22 ( const struct V_63 * V_64 )
{
return F_23 ( & V_64 -> V_65 -> V_53 ) ;
}
static int F_24 ( const struct V_63 * V_66 ,
const struct V_63 * V_67 )
{
return F_25 ( F_22 ( V_66 ) , F_22 ( V_67 ) ) ? :
F_26 ( V_66 -> V_68 , V_67 -> V_68 ) ;
}
static int F_27 ( const struct V_63 * V_66 ,
const struct V_63 * V_67 )
{
int V_69 ;
V_69 = F_25 ( F_22 ( V_66 ) , F_22 ( V_67 ) ) ;
if ( V_69 )
return V_69 ;
if ( V_66 -> V_70 < V_67 -> V_68 )
return - 1 ;
if ( V_66 -> V_68 > V_66 -> V_70 )
return 1 ;
return 0 ;
}
static void F_28 ( struct V_63 * V_66 ,
const struct V_63 * V_67 )
{
V_66 -> V_68 = F_29 ( V_66 -> V_68 , V_67 -> V_68 ) ;
V_66 -> V_70 = F_30 ( V_66 -> V_70 , V_67 -> V_70 ) ;
if ( V_67 -> V_71 == V_72 && V_66 -> V_71 != V_72 )
V_66 -> V_71 = V_72 ;
if ( V_67 -> V_71 == V_73 && V_66 -> V_71 != V_73 )
V_66 -> V_71 = V_73 ;
}
static void F_31 ( struct V_4 * V_5 )
{
int V_74 = 0 ;
do {
struct V_75 * V_76 ;
struct V_75 * V_22 ;
struct V_75 * V_77 ;
V_74 = 1 ;
V_22 = NULL ;
F_32 (curr, temp,
&io->ci_lockset.cls_todo,
cill_linkage) {
if ( V_22 != NULL ) {
switch ( F_24 ( & V_22 -> V_78 ,
& V_76 -> V_78 ) ) {
case 0 :
default:
F_13 () ;
case 1 :
F_33 ( & V_76 -> V_79 ,
& V_22 -> V_79 ) ;
V_74 = 0 ;
continue;
case - 1 :
break;
}
}
V_22 = V_76 ;
}
} while ( ! V_74 );
}
int F_34 ( const struct V_80 * V_81 ,
const struct V_63 * V_82 )
{
struct V_75 * V_39 ;
F_35 (scan, queue, cill_linkage) {
if ( F_36 ( & V_39 -> V_78 , V_82 ) )
return 1 ;
}
return 0 ;
}
static int F_37 ( const struct V_80 * V_81 ,
const struct V_63 * V_82 )
{
struct V_75 * V_39 ;
F_35 (scan, queue, cill_linkage) {
if ( F_27 ( & V_39 -> V_78 , V_82 ) )
continue;
F_28 ( & V_39 -> V_78 , V_82 ) ;
F_38 ( V_52 , L_2 ,
V_39 -> V_78 . V_71 , V_39 -> V_78 . V_68 ,
V_39 -> V_78 . V_70 ) ;
return 1 ;
}
return 0 ;
}
static int F_39 ( const struct V_83 * V_84 ,
const struct V_63 * V_82 )
{
return F_34 ( & V_84 -> V_44 , V_82 ) ||
F_34 ( & V_84 -> V_45 , V_82 ) ;
}
static int F_40 ( const struct V_83 * V_84 ,
const struct V_63 * V_82 )
{
return F_37 ( & V_84 -> V_43 , V_82 ) ||
F_39 ( V_84 , V_82 ) ;
}
static int F_41 ( const struct V_8 * V_9 ,
struct V_4 * V_5 , struct V_83 * V_84 ,
struct V_75 * V_85 )
{
struct V_86 * V_87 ;
int V_40 ;
V_87 = F_42 ( V_9 , V_5 , & V_85 -> V_78 , L_3 , V_5 ) ;
if ( ! F_43 ( V_87 ) ) {
V_85 -> V_88 = V_87 ;
F_44 ( & V_85 -> V_79 , & V_84 -> V_44 ) ;
if ( ! ( V_85 -> V_78 . V_89 & V_90 ) ) {
V_40 = F_45 ( V_9 , V_87 ) ;
if ( V_40 == 0 )
F_44 ( & V_85 -> V_79 ,
& V_84 -> V_45 ) ;
} else
V_40 = 0 ;
} else
V_40 = F_46 ( V_87 ) ;
return V_40 ;
}
static void F_47 ( const struct V_8 * V_9 , struct V_4 * V_5 ,
struct V_75 * V_85 )
{
struct V_86 * V_87 = V_85 -> V_88 ;
F_11 ( & V_85 -> V_79 ) ;
if ( V_87 != NULL ) {
F_48 ( V_9 , V_87 , L_3 , V_5 ) ;
V_85 -> V_88 = NULL ;
}
if ( V_85 -> V_91 != NULL )
V_85 -> V_91 ( V_9 , V_85 ) ;
}
static int F_49 ( const struct V_8 * V_9 , struct V_4 * V_5 ,
struct V_83 * V_84 )
{
struct V_75 * V_85 ;
struct V_75 * V_77 ;
struct V_86 * V_87 ;
int V_40 ;
V_40 = 0 ;
F_32 (link, temp, &set->cls_todo, cill_linkage) {
if ( ! F_39 ( V_84 , & V_85 -> V_78 ) ) {
V_40 = F_41 ( V_9 , V_5 , V_84 , V_85 ) ;
if ( V_40 != 0 )
break;
} else
F_47 ( V_9 , V_5 , V_85 ) ;
}
if ( V_40 == 0 ) {
F_32 (link, temp,
&set->cls_curr, cill_linkage) {
V_87 = V_85 -> V_88 ;
V_40 = F_45 ( V_9 , V_87 ) ;
if ( V_40 == 0 )
F_44 ( & V_85 -> V_79 ,
& V_84 -> V_45 ) ;
else
break;
}
}
return V_40 ;
}
int F_50 ( const struct V_8 * V_9 , struct V_4 * V_5 )
{
const struct V_17 * V_39 ;
int V_40 = 0 ;
F_8 ( F_2 ( V_5 ) ) ;
F_8 ( V_5 -> V_14 == V_92 ) ;
F_8 ( F_5 ( V_5 ) ) ;
F_51 (scan, io) {
if ( V_39 -> V_24 -> V_25 [ V_5 -> V_6 ] . V_93 == NULL )
continue;
V_40 = V_39 -> V_24 -> V_25 [ V_5 -> V_6 ] . V_93 ( V_9 , V_39 ) ;
if ( V_40 != 0 )
break;
}
if ( V_40 == 0 ) {
F_31 ( V_5 ) ;
V_40 = F_49 ( V_9 , V_5 , & V_5 -> V_42 ) ;
}
if ( V_40 != 0 )
F_52 ( V_9 , V_5 ) ;
else
V_5 -> V_14 = V_16 ;
return V_40 ;
}
void F_52 ( const struct V_8 * V_9 , struct V_4 * V_5 )
{
struct V_83 * V_84 ;
struct V_75 * V_85 ;
struct V_75 * V_77 ;
const struct V_17 * V_39 ;
F_12 ( F_2 ( V_5 ) ) ;
F_12 ( V_92 <= V_5 -> V_14 && V_5 -> V_14 < V_94 ) ;
F_8 ( F_5 ( V_5 ) ) ;
V_84 = & V_5 -> V_42 ;
F_32 (link, temp, &set->cls_todo, cill_linkage)
F_47 ( V_9 , V_5 , V_85 ) ;
F_32 (link, temp, &set->cls_curr, cill_linkage)
F_47 ( V_9 , V_5 , V_85 ) ;
F_32 (link, temp, &set->cls_done, cill_linkage) {
F_53 ( V_9 , V_85 -> V_88 ) ;
F_47 ( V_9 , V_5 , V_85 ) ;
}
F_54 (scan, io) {
if ( V_39 -> V_24 -> V_25 [ V_5 -> V_6 ] . V_95 != NULL )
V_39 -> V_24 -> V_25 [ V_5 -> V_6 ] . V_95 ( V_9 , V_39 ) ;
}
V_5 -> V_14 = V_94 ;
F_12 ( ! F_4 ( V_9 ) -> V_96 [ V_97 ] . V_98 ) ;
}
int F_55 ( const struct V_8 * V_9 , struct V_4 * V_5 )
{
const struct V_17 * V_39 ;
int V_40 ;
F_8 ( F_2 ( V_5 ) ) ;
F_8 ( V_5 -> V_14 == V_48 || V_5 -> V_14 == V_99 ) ;
F_8 ( F_5 ( V_5 ) ) ;
V_40 = 0 ;
F_51 (scan, io) {
if ( V_39 -> V_24 -> V_25 [ V_5 -> V_6 ] . V_100 == NULL )
continue;
V_40 = V_39 -> V_24 -> V_25 [ V_5 -> V_6 ] . V_100 ( V_9 ,
V_39 ) ;
if ( V_40 != 0 )
break;
}
if ( V_40 == 0 )
V_5 -> V_14 = V_92 ;
return V_40 ;
}
void F_56 ( const struct V_8 * V_9 , struct V_4 * V_5 )
{
const struct V_17 * V_39 ;
F_8 ( F_2 ( V_5 ) ) ;
F_8 ( V_5 -> V_14 == V_94 ) ;
F_8 ( F_5 ( V_5 ) ) ;
F_54 (scan, io) {
if ( V_39 -> V_24 -> V_25 [ V_5 -> V_6 ] . V_101 != NULL )
V_39 -> V_24 -> V_25 [ V_5 -> V_6 ] . V_101 ( V_9 , V_39 ) ;
}
V_5 -> V_14 = V_99 ;
}
static void F_57 ( const struct V_8 * V_9 , struct V_4 * V_5 ,
T_2 V_102 )
{
const struct V_17 * V_39 ;
F_8 ( V_5 -> V_6 == V_2 || V_5 -> V_6 == V_29 ||
V_102 == 0 ) ;
F_8 ( F_2 ( V_5 ) ) ;
F_8 ( F_5 ( V_5 ) ) ;
V_5 -> V_55 . V_56 . V_60 += V_102 ;
V_5 -> V_55 . V_56 . V_61 -= V_102 ;
F_54 (scan, io) {
if ( V_39 -> V_24 -> V_25 [ V_5 -> V_6 ] . V_103 != NULL )
V_39 -> V_24 -> V_25 [ V_5 -> V_6 ] . V_103 ( V_9 , V_39 ,
V_102 ) ;
}
}
int F_58 ( const struct V_8 * V_9 , struct V_4 * V_5 ,
struct V_75 * V_85 )
{
int V_40 ;
if ( F_40 ( & V_5 -> V_42 , & V_85 -> V_78 ) )
V_40 = 1 ;
else {
F_59 ( & V_85 -> V_79 , & V_5 -> V_42 . V_43 ) ;
V_40 = 0 ;
}
return V_40 ;
}
static void F_60 ( const struct V_8 * V_9 ,
struct V_75 * V_85 )
{
F_61 ( V_85 ) ;
}
int F_62 ( const struct V_8 * V_9 , struct V_4 * V_5 ,
struct V_63 * V_64 )
{
struct V_75 * V_85 ;
int V_40 ;
V_85 = F_63 ( sizeof( * V_85 ) , V_104 ) ;
if ( V_85 != NULL ) {
V_85 -> V_78 = * V_64 ;
V_85 -> V_91 = F_60 ;
V_40 = F_58 ( V_9 , V_5 , V_85 ) ;
if ( V_40 )
V_85 -> V_91 ( V_9 , V_85 ) ;
} else
V_40 = - V_105 ;
return V_40 ;
}
int F_64 ( const struct V_8 * V_9 , struct V_4 * V_5 )
{
const struct V_17 * V_39 ;
int V_40 = 0 ;
F_8 ( F_2 ( V_5 ) ) ;
F_8 ( V_5 -> V_14 == V_16 ) ;
F_8 ( F_5 ( V_5 ) ) ;
V_5 -> V_14 = V_15 ;
F_51 (scan, io) {
if ( V_39 -> V_24 -> V_25 [ V_5 -> V_6 ] . V_106 == NULL )
continue;
V_40 = V_39 -> V_24 -> V_25 [ V_5 -> V_6 ] . V_106 ( V_9 , V_39 ) ;
if ( V_40 != 0 )
break;
}
if ( V_40 >= 0 )
V_40 = 0 ;
return V_40 ;
}
void F_65 ( const struct V_8 * V_9 , struct V_4 * V_5 )
{
const struct V_17 * V_39 ;
F_8 ( F_2 ( V_5 ) ) ;
F_8 ( V_5 -> V_14 == V_15 ) ;
F_8 ( F_5 ( V_5 ) ) ;
F_54 (scan, io) {
if ( V_39 -> V_24 -> V_25 [ V_5 -> V_6 ] . V_107 != NULL )
V_39 -> V_24 -> V_25 [ V_5 -> V_6 ] . V_107 ( V_9 , V_39 ) ;
}
V_5 -> V_14 = V_108 ;
}
static const struct V_109 *
F_66 ( const struct V_17 * V_110 , struct V_111 * V_112 )
{
const struct V_109 * V_18 ;
V_18 = F_67 ( V_112 , V_110 -> V_113 -> V_53 . V_114 -> V_115 ) ;
F_8 ( V_18 != NULL ) ;
return V_18 ;
}
static int F_68 ( const struct V_111 * V_112 , const struct V_4 * V_5 )
{
int V_40 = 1 ;
T_1 V_116 ;
T_1 V_117 ;
T_3 V_118 ;
V_118 = V_112 -> V_119 ;
switch ( V_5 -> V_6 ) {
case V_2 :
case V_29 :
if ( ! F_69 ( V_5 ) ) {
const struct V_120 * V_121 = & ( V_5 -> V_55 . V_56 ) ;
V_116 = F_70 ( V_112 -> V_122 , V_118 ) ;
V_117 = F_70 ( V_112 -> V_122 , V_118 + 1 ) ;
V_40 = V_121 -> V_60 < V_117 &&
V_116 < V_121 -> V_60 + V_121 -> V_61 ;
}
break;
case V_30 :
V_40 = V_5 -> V_55 . V_123 . V_124 == V_118 ;
break;
default:
F_13 () ;
}
return V_40 ;
}
int F_71 ( const struct V_8 * V_9 , struct V_4 * V_5 ,
struct V_111 * V_112 )
{
const struct V_17 * V_39 ;
struct V_125 * V_81 ;
int V_40 = 0 ;
F_8 ( V_5 -> V_6 == V_2 || V_5 -> V_6 == V_30 ) ;
F_8 ( F_72 ( V_112 , V_5 ) ) ;
F_8 ( V_5 -> V_14 == V_15 || V_5 -> V_14 == V_16 ) ;
F_8 ( F_68 ( V_112 , V_5 ) ) ;
F_8 ( F_5 ( V_5 ) ) ;
V_81 = & V_5 -> V_126 ;
F_73 ( V_81 ) ;
F_51 (scan, io) {
if ( V_39 -> V_24 -> V_127 != NULL ) {
const struct V_109 * V_18 ;
V_18 = F_66 ( V_39 , V_112 ) ;
F_8 ( V_18 != NULL ) ;
V_40 = V_39 -> V_24 -> V_127 ( V_9 , V_39 , V_18 ) ;
if ( V_40 != 0 )
break;
}
}
if ( V_40 == 0 )
V_40 = F_74 ( V_9 , V_5 , V_128 , V_81 ) ;
F_75 ( V_9 , V_5 , & V_81 -> V_129 ) ;
F_76 ( V_9 , V_81 ) ;
return V_40 ;
}
int F_77 ( const struct V_8 * V_9 , struct V_4 * V_5 ,
struct V_111 * V_112 , unsigned V_130 , unsigned V_131 )
{
const struct V_17 * V_39 ;
int V_40 = 0 ;
F_8 ( V_5 -> V_6 == V_29 ) ;
F_8 ( F_72 ( V_112 , V_5 ) ) ;
F_8 ( V_5 -> V_14 == V_15 || V_5 -> V_14 == V_16 ) ;
F_8 ( F_5 ( V_5 ) ) ;
F_12 ( F_68 ( V_112 , V_5 ) ) ;
F_54 (scan, io) {
if ( V_39 -> V_24 -> V_132 != NULL ) {
const struct V_109 * V_18 ;
V_18 = F_66 ( V_39 , V_112 ) ;
V_40 = V_39 -> V_24 -> V_132 ( V_9 , V_39 ,
V_18 ,
V_130 , V_131 ) ;
if ( V_40 != 0 )
break;
}
}
return V_40 ;
}
int F_78 ( const struct V_8 * V_9 , struct V_4 * V_5 ,
struct V_111 * V_112 , unsigned V_130 , unsigned V_131 )
{
const struct V_17 * V_39 ;
int V_40 = 0 ;
F_8 ( V_5 -> V_6 == V_29 ) ;
F_8 ( V_5 -> V_14 == V_15 || V_5 -> V_14 == V_16 ) ;
F_8 ( F_5 ( V_5 ) ) ;
F_12 ( F_72 ( V_112 , V_5 ) || V_112 -> V_133 != NULL ) ;
F_12 ( F_68 ( V_112 , V_5 ) ) ;
F_51 (scan, io) {
if ( V_39 -> V_24 -> V_134 != NULL ) {
const struct V_109 * V_18 ;
V_18 = F_66 ( V_39 , V_112 ) ;
V_40 = V_39 -> V_24 -> V_134 ( V_9 , V_39 ,
V_18 ,
V_130 , V_131 ) ;
if ( V_40 != 0 )
break;
}
}
F_8 ( V_40 <= 0 ) ;
return V_40 ;
}
int F_74 ( const struct V_8 * V_9 , struct V_4 * V_5 ,
enum V_135 V_136 , struct V_125 * V_81 )
{
const struct V_17 * V_39 ;
int V_40 = 0 ;
F_8 ( V_136 < F_79 ( V_39 -> V_24 -> V_137 ) ) ;
F_51 (scan, io) {
if ( V_39 -> V_24 -> V_137 [ V_136 ] . V_138 == NULL )
continue;
V_40 = V_39 -> V_24 -> V_137 [ V_136 ] . V_138 ( V_9 , V_39 , V_136 ,
V_81 ) ;
if ( V_40 != 0 )
break;
}
F_12 ( F_6 ( V_40 != 0 , F_9 ( & V_81 -> V_139 . V_140 ) ) ) ;
return V_40 ;
}
int F_80 ( const struct V_8 * V_9 , struct V_4 * V_5 ,
enum V_135 V_36 , struct V_125 * V_81 ,
long V_141 )
{
struct V_142 * V_143 = & F_4 ( V_9 ) -> V_144 ;
struct V_111 * V_145 ;
int V_146 ;
F_81 (pg, &queue->c2_qin) {
F_12 ( V_145 -> V_147 == NULL ) ;
V_145 -> V_147 = V_143 ;
}
F_82 ( V_143 , V_81 -> V_129 . V_148 ) ;
V_146 = F_74 ( V_9 , V_5 , V_36 , V_81 ) ;
if ( V_146 == 0 ) {
F_81 (pg, &queue->c2_qin) {
V_145 -> V_147 = NULL ;
F_83 ( V_143 , 1 ) ;
}
V_146 = F_84 ( V_9 , V_5 , & V_81 -> V_139 ,
V_143 , V_141 ) ;
} else {
F_12 ( F_9 ( & V_81 -> V_139 . V_140 ) ) ;
F_81 (pg, &queue->c2_qin)
V_145 -> V_147 = NULL ;
}
return V_146 ;
}
static int F_85 ( const struct V_8 * V_9 , struct V_4 * V_5 ,
struct V_149 * V_81 )
{
struct V_111 * V_112 ;
int V_40 = 0 ;
F_86 ( L_4 ) ;
F_81 (page, queue) {
int V_146 ;
F_8 ( F_68 ( V_112 , V_5 ) ) ;
V_146 = F_87 ( V_9 , V_112 ) ;
V_40 = V_40 ? : V_146 ;
}
return V_40 ;
}
int F_88 ( const struct V_8 * V_9 , struct V_4 * V_5 )
{
int V_40 = 0 ;
F_8 ( F_2 ( V_5 ) ) ;
do {
T_2 V_102 ;
V_5 -> V_150 = 0 ;
V_40 = F_55 ( V_9 , V_5 ) ;
if ( V_40 == 0 ) {
V_102 = V_5 -> V_151 ;
V_40 = F_50 ( V_9 , V_5 ) ;
if ( V_40 == 0 ) {
V_40 = F_64 ( V_9 , V_5 ) ;
F_65 ( V_9 , V_5 ) ;
F_52 ( V_9 , V_5 ) ;
F_57 ( V_9 , V_5 , V_5 -> V_151 - V_102 ) ;
}
}
F_56 ( V_9 , V_5 ) ;
} while ( V_40 == 0 && V_5 -> V_150 );
if ( V_40 == 0 )
V_40 = V_5 -> V_152 ;
return V_40 < 0 ? V_40 : 0 ;
}
void F_89 ( struct V_4 * V_5 , struct V_17 * V_18 ,
struct V_37 * V_38 ,
const struct V_153 * V_154 )
{
struct V_80 * V_155 = & V_18 -> V_23 ;
F_12 ( ( V_155 -> V_22 == NULL && V_155 -> V_156 == NULL ) ||
F_9 ( V_155 ) ) ;
F_90 ( V_155 , & V_5 -> V_21 ) ;
V_18 -> V_27 = V_5 ;
V_18 -> V_113 = V_38 ;
V_18 -> V_24 = V_154 ;
}
void F_91 ( struct V_149 * V_157 )
{
V_157 -> V_148 = 0 ;
F_15 ( & V_157 -> V_140 ) ;
V_157 -> V_158 = V_159 ;
}
void F_92 ( struct V_149 * V_157 , struct V_111 * V_112 )
{
F_12 ( V_112 -> V_160 != NULL ) ;
F_8 ( V_157 -> V_158 == V_159 ) ;
F_93 () ;
F_94 ( & V_112 -> V_161 ) ;
F_95 () ;
F_12 ( F_9 ( & V_112 -> V_162 ) ) ;
F_90 ( & V_112 -> V_162 , & V_157 -> V_140 ) ;
++ V_157 -> V_148 ;
F_96 ( & V_112 -> V_163 , & V_112 -> V_164 , L_5 , V_157 ) ;
F_97 ( V_112 ) ;
}
static void F_98 ( const struct V_8 * V_9 ,
struct V_149 * V_157 , struct V_111 * V_112 )
{
F_12 ( V_157 -> V_148 > 0 ) ;
F_8 ( V_157 -> V_158 == V_159 ) ;
F_11 ( & V_112 -> V_162 ) ;
F_93 () ;
F_99 ( & V_112 -> V_161 ) ;
F_95 () ;
-- V_157 -> V_148 ;
F_100 ( & V_112 -> V_163 , & V_112 -> V_164 , L_5 , V_157 ) ;
F_101 ( V_9 , V_112 ) ;
}
void F_102 ( struct V_149 * V_165 , struct V_149 * V_166 ,
struct V_111 * V_112 )
{
F_12 ( V_166 -> V_148 > 0 ) ;
F_8 ( V_165 -> V_158 == V_159 ) ;
F_8 ( V_166 -> V_158 == V_159 ) ;
F_33 ( & V_112 -> V_162 , & V_165 -> V_140 ) ;
-- V_166 -> V_148 ;
++ V_165 -> V_148 ;
F_103 ( & V_112 -> V_163 , & V_112 -> V_164 , L_5 ,
V_166 , V_165 ) ;
}
void F_104 ( struct V_149 * V_167 , struct V_149 * V_168 )
{
struct V_111 * V_112 ;
struct V_111 * V_169 ;
F_8 ( V_167 -> V_158 == V_159 ) ;
F_8 ( V_168 -> V_158 == V_159 ) ;
F_105 (page, tmp, list)
F_102 ( V_168 , V_167 , V_112 ) ;
}
void F_75 ( const struct V_8 * V_9 ,
struct V_4 * V_5 , struct V_149 * V_157 )
{
struct V_111 * V_112 ;
struct V_111 * V_77 ;
F_8 ( V_157 -> V_158 == V_159 ) ;
F_105 (page, temp, plist) {
F_12 ( V_157 -> V_148 > 0 ) ;
F_11 ( & V_112 -> V_162 ) ;
F_93 () ;
F_99 ( & V_112 -> V_161 ) ;
F_95 () ;
-- V_157 -> V_148 ;
F_106 ( V_9 , V_5 , V_112 ) ;
F_100 ( & V_112 -> V_163 , & V_112 -> V_164 , L_5 ,
V_157 ) ;
F_101 ( V_9 , V_112 ) ;
}
}
static void F_107 ( const struct V_8 * V_9 ,
struct V_149 * V_157 )
{
struct V_111 * V_112 ;
struct V_111 * V_77 ;
F_8 ( V_157 -> V_158 == V_159 ) ;
F_105 (page, temp, plist)
F_98 ( V_9 , V_157 , V_112 ) ;
F_12 ( V_157 -> V_148 == 0 ) ;
}
static void F_108 ( const struct V_8 * V_9 ,
struct V_4 * V_5 , struct V_149 * V_157 )
{
struct V_111 * V_112 ;
F_8 ( V_157 -> V_158 == V_159 ) ;
F_81 (page, plist)
F_109 ( V_9 , V_5 , V_112 ) ;
}
static void F_110 ( const struct V_8 * V_9 , struct V_4 * V_5 ,
struct V_149 * V_157 )
{
struct V_111 * V_112 ;
F_8 ( V_157 -> V_158 == V_159 ) ;
F_81 (page, plist)
F_111 ( V_9 , V_5 , V_112 ) ;
}
void F_73 ( struct V_125 * V_81 )
{
F_91 ( & V_81 -> V_129 ) ;
F_91 ( & V_81 -> V_139 ) ;
}
void F_112 ( struct V_125 * V_81 , struct V_111 * V_112 )
{
F_92 ( & V_81 -> V_129 , V_112 ) ;
}
void F_113 ( const struct V_8 * V_9 ,
struct V_4 * V_5 , struct V_125 * V_81 )
{
F_75 ( V_9 , V_5 , & V_81 -> V_129 ) ;
F_75 ( V_9 , V_5 , & V_81 -> V_139 ) ;
}
void F_114 ( const struct V_8 * V_9 ,
struct V_4 * V_5 , struct V_125 * V_81 )
{
F_110 ( V_9 , V_5 , & V_81 -> V_129 ) ;
F_110 ( V_9 , V_5 , & V_81 -> V_139 ) ;
}
void F_76 ( const struct V_8 * V_9 , struct V_125 * V_81 )
{
F_107 ( V_9 , & V_81 -> V_139 ) ;
F_107 ( V_9 , & V_81 -> V_129 ) ;
}
void F_115 ( struct V_125 * V_81 , struct V_111 * V_112 )
{
F_73 ( V_81 ) ;
F_112 ( V_81 , V_112 ) ;
}
struct V_4 * F_116 ( struct V_4 * V_5 )
{
while ( V_5 -> V_12 != NULL )
V_5 = V_5 -> V_12 ;
return V_5 ;
}
void F_117 ( struct V_170 * V_171 , struct V_172 * V_18 ,
struct V_173 * V_174 ,
const struct V_175 * V_154 )
{
F_90 ( & V_18 -> V_176 , & V_171 -> V_177 ) ;
V_18 -> V_178 = V_174 ;
V_18 -> V_179 = V_154 ;
V_18 -> V_180 = V_171 ;
}
static void F_118 ( const struct V_8 * V_9 , struct V_170 * V_171 )
{
unsigned V_181 ;
F_12 ( F_9 ( & V_171 -> V_182 ) ) ;
F_12 ( V_171 -> V_183 == 0 ) ;
F_8 ( F_9 ( & V_171 -> V_177 ) ) ;
F_8 ( F_119 ( V_171 -> V_184 > 0 , V_171 -> V_185 != NULL ) ) ;
if ( V_171 -> V_185 != NULL ) {
for ( V_181 = 0 ; V_181 < V_171 -> V_184 ; ++ V_181 ) {
struct V_37 * V_38 = V_171 -> V_185 [ V_181 ] . V_186 ;
if ( V_38 != NULL ) {
F_120 ( & V_38 -> V_53 ,
& V_171 -> V_185 [ V_181 ] . V_187 ,
L_6 , V_171 ) ;
F_121 ( V_9 , V_38 ) ;
}
}
F_61 ( V_171 -> V_185 ) ;
}
F_61 ( V_171 ) ;
}
static int F_122 ( const struct V_8 * V_9 , struct V_170 * V_171 ,
struct V_111 * V_112 )
{
struct V_173 * V_174 ;
struct V_109 * V_18 ;
int V_40 ;
V_40 = 0 ;
V_112 = F_123 ( V_112 ) ;
do {
F_35 (slice, &page->cp_layers, cpl_linkage) {
V_174 = F_124 ( V_18 -> V_188 -> V_53 . V_114 ) ;
if ( V_174 -> V_189 -> V_190 != NULL ) {
V_40 = V_174 -> V_189 -> V_190 ( V_9 ,
V_174 , V_171 ) ;
if ( V_40 != 0 )
break;
}
}
V_112 = V_112 -> V_191 ;
} while ( V_112 != NULL && V_40 == 0 );
return V_40 ;
}
void F_125 ( const struct V_8 * V_9 , struct V_170 * V_171 , int V_146 )
{
struct V_172 * V_18 ;
while ( ! F_9 ( & V_171 -> V_177 ) ) {
V_18 = F_126 ( V_171 -> V_177 . V_22 ,
struct V_172 , V_176 ) ;
F_11 ( & V_18 -> V_176 ) ;
if ( V_18 -> V_179 -> V_192 != NULL )
V_18 -> V_179 -> V_192 ( V_9 , V_18 , V_146 ) ;
}
F_118 ( V_9 , V_171 ) ;
}
struct V_170 * F_127 ( const struct V_8 * V_9 , struct V_111 * V_112 ,
enum V_135 V_136 , int V_193 )
{
struct V_170 * V_171 ;
F_8 ( V_193 > 0 ) ;
V_171 = F_63 ( sizeof( * V_171 ) , V_104 ) ;
if ( V_171 != NULL ) {
int V_40 ;
V_171 -> V_194 = V_136 ;
F_15 ( & V_171 -> V_182 ) ;
F_15 ( & V_171 -> V_177 ) ;
V_171 -> V_185 = F_128 ( V_193 , sizeof( V_171 -> V_185 [ 0 ] ) ,
V_104 ) ;
if ( V_171 -> V_185 != NULL ) {
V_171 -> V_184 = V_193 ;
V_40 = F_122 ( V_9 , V_171 , V_112 ) ;
} else
V_40 = - V_105 ;
if ( V_40 != 0 ) {
F_125 ( V_9 , V_171 , V_40 ) ;
V_171 = F_129 ( V_40 ) ;
}
} else
V_171 = F_129 ( - V_105 ) ;
return V_171 ;
}
void F_130 ( const struct V_8 * V_9 ,
struct V_170 * V_171 , struct V_111 * V_112 )
{
struct V_37 * V_38 ;
struct V_195 * V_196 ;
int V_181 ;
V_112 = F_123 ( V_112 ) ;
F_12 ( F_9 ( & V_112 -> V_197 ) ) ;
F_12 ( V_112 -> V_198 == NULL ) ;
F_131 ( V_199 , V_9 , V_112 , L_7 ,
V_171 , V_171 -> V_194 , V_171 -> V_183 ) ;
F_90 ( & V_112 -> V_197 , & V_171 -> V_182 ) ;
++ V_171 -> V_183 ;
V_112 -> V_198 = V_171 ;
V_38 = F_18 ( V_112 -> V_122 ) ;
for ( V_181 = 0 , V_196 = V_171 -> V_185 ; V_38 != V_196 -> V_186 ; ++ V_181 , ++ V_196 ) {
if ( V_196 -> V_186 == NULL ) {
V_196 -> V_186 = V_38 ;
F_132 ( V_38 ) ;
F_133 ( & V_38 -> V_53 , & V_196 -> V_187 ,
L_6 , V_171 ) ;
break;
}
}
F_12 ( V_181 < V_171 -> V_184 ) ;
}
void F_134 ( const struct V_8 * V_9 , struct V_111 * V_112 )
{
struct V_170 * V_171 = V_112 -> V_198 ;
V_112 = F_123 ( V_112 ) ;
F_12 ( ! F_9 ( & V_112 -> V_197 ) ) ;
F_12 ( V_171 -> V_183 > 0 ) ;
F_11 ( & V_112 -> V_197 ) ;
-- V_171 -> V_183 ;
V_112 -> V_198 = NULL ;
}
int F_135 ( const struct V_8 * V_9 , struct V_170 * V_171 )
{
int V_181 ;
int V_40 ;
const struct V_172 * V_18 ;
for ( V_181 = 0 ; V_181 < V_171 -> V_184 ; ++ V_181 )
F_12 ( V_171 -> V_185 [ V_181 ] . V_186 != NULL ) ;
V_40 = 0 ;
F_35 (slice, &req->crq_layers, crs_linkage) {
if ( V_18 -> V_179 -> V_200 != NULL ) {
V_40 = V_18 -> V_179 -> V_200 ( V_9 , V_18 ) ;
if ( V_40 != 0 )
break;
}
}
return V_40 ;
}
void F_136 ( const struct V_8 * V_9 , struct V_170 * V_171 ,
struct V_201 * V_202 , T_4 V_203 )
{
const struct V_172 * V_18 ;
struct V_111 * V_112 ;
int V_181 ;
F_12 ( ! F_9 ( & V_171 -> V_182 ) ) ;
V_112 = F_126 ( V_171 -> V_182 . V_156 , struct V_111 , V_197 ) ;
for ( V_181 = 0 ; V_181 < V_171 -> V_184 ; ++ V_181 ) {
F_35 (slice, &req->crq_layers, crs_linkage) {
const struct V_109 * V_39 ;
const struct V_37 * V_38 ;
V_39 = F_67 ( V_112 ,
V_18 -> V_178 -> V_204 . V_115 ) ;
F_12 ( V_39 != NULL ) ;
V_38 = V_39 -> V_188 ;
if ( V_18 -> V_179 -> V_205 != NULL )
V_18 -> V_179 -> V_205 ( V_9 , V_18 , V_38 ,
V_202 + V_181 , V_203 ) ;
}
}
}
void F_82 ( struct V_142 * V_143 , int V_206 )
{
F_137 ( & V_143 -> V_207 ) ;
F_138 ( & V_143 -> V_208 , V_206 ) ;
F_138 ( & V_143 -> V_209 , V_206 > 0 ) ;
V_143 -> V_210 = 0 ;
}
int F_84 ( const struct V_8 * V_9 , struct V_4 * V_5 ,
struct V_149 * V_81 , struct V_142 * V_143 ,
long V_141 )
{
struct V_211 V_212 = F_139 ( F_140 ( V_141 ) ,
NULL , NULL , NULL ) ;
int V_146 ;
F_12 ( V_141 >= 0 ) ;
V_146 = F_141 ( V_143 -> V_207 ,
F_142 ( & V_143 -> V_208 ) == 0 ,
& V_212 ) ;
if ( V_146 < 0 ) {
F_86 ( L_8 ,
V_146 , F_142 ( & V_143 -> V_208 ) ) ;
( void ) F_85 ( V_9 , V_5 , V_81 ) ;
V_212 = (struct V_211 ) { 0 } ;
( void ) F_141 ( V_143 -> V_207 ,
F_142 ( & V_143 -> V_208 ) == 0 ,
& V_212 ) ;
} else {
V_146 = V_143 -> V_210 ;
}
F_12 ( F_142 ( & V_143 -> V_208 ) == 0 ) ;
F_108 ( V_9 , V_5 , V_81 ) ;
while ( F_143 ( F_142 ( & V_143 -> V_209 ) != 0 ) ) {
F_144 () ;
}
F_145 ( V_143 , 0x5a , sizeof( * V_143 ) ) ;
return V_146 ;
}
void F_83 ( struct V_142 * V_143 , int V_213 )
{
if ( V_143 -> V_210 == 0 && V_213 < 0 )
V_143 -> V_210 = V_213 ;
F_12 ( F_142 ( & V_143 -> V_208 ) > 0 ) ;
if ( F_146 ( & V_143 -> V_208 ) ) {
F_147 ( & V_143 -> V_207 ) ;
F_138 ( & V_143 -> V_209 , 0 ) ;
}
}
