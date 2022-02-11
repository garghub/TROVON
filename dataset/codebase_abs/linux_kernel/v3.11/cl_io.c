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
V_21 ;
while ( ! F_9 ( & V_5 -> V_22 ) ) {
V_18 = F_10 ( V_5 -> V_22 . V_23 , struct V_17 ,
V_24 ) ;
F_11 ( & V_18 -> V_24 ) ;
if ( V_18 -> V_25 -> V_26 [ V_5 -> V_6 ] . V_27 != NULL )
V_18 -> V_25 -> V_26 [ V_5 -> V_6 ] . V_27 ( V_9 , V_18 ) ;
V_18 -> V_28 = NULL ;
}
V_5 -> V_14 = V_29 ;
V_20 = F_4 ( V_9 ) ;
if ( V_20 -> V_10 == V_5 )
V_20 -> V_10 = NULL ;
switch( V_5 -> V_6 ) {
case V_2 :
case V_30 :
break;
case V_31 :
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
EXIT ;
}
static int F_14 ( const struct V_8 * V_9 , struct V_4 * V_5 ,
enum V_1 V_37 , struct V_38 * V_39 )
{
struct V_38 * V_40 ;
int V_41 ;
F_8 ( V_5 -> V_14 == V_42 || V_5 -> V_14 == V_29 ) ;
F_8 ( F_1 ( V_37 ) ) ;
F_8 ( F_5 ( V_5 ) ) ;
V_21 ;
V_5 -> V_6 = V_37 ;
F_15 ( & V_5 -> V_43 . V_44 ) ;
F_15 ( & V_5 -> V_43 . V_45 ) ;
F_15 ( & V_5 -> V_43 . V_46 ) ;
F_15 ( & V_5 -> V_22 ) ;
V_41 = 0 ;
F_16 (scan, obj) {
if ( V_40 -> V_47 -> V_48 != NULL ) {
V_41 = V_40 -> V_47 -> V_48 ( V_9 , V_40 , V_5 ) ;
if ( V_41 != 0 )
break;
}
}
if ( V_41 == 0 )
V_5 -> V_14 = V_49 ;
RETURN ( V_41 ) ;
}
int F_17 ( const struct V_8 * V_9 , struct V_4 * V_5 ,
enum V_1 V_37 , struct V_38 * V_39 )
{
struct V_19 * V_20 = F_4 ( V_9 ) ;
F_12 ( V_39 != F_18 ( V_39 ) ) ;
if ( V_20 -> V_10 == NULL )
V_20 -> V_10 = V_5 ;
return F_14 ( V_9 , V_5 , V_37 , V_39 ) ;
}
int F_19 ( const struct V_8 * V_9 , struct V_4 * V_5 ,
enum V_1 V_37 , struct V_38 * V_39 )
{
struct V_19 * V_20 = F_4 ( V_9 ) ;
F_12 ( V_39 == F_18 ( V_39 ) ) ;
F_12 ( V_20 -> V_10 == NULL ) ;
V_20 -> V_10 = V_5 ;
return F_14 ( V_9 , V_5 , V_37 , V_39 ) ;
}
int F_20 ( const struct V_8 * V_9 , struct V_4 * V_5 ,
enum V_1 V_37 , T_1 V_50 , T_2 V_51 )
{
F_8 ( V_37 == V_2 || V_37 == V_30 ) ;
F_8 ( V_5 -> V_52 != NULL ) ;
V_21 ;
F_21 ( V_53 , V_9 , & V_5 -> V_52 -> V_54 ,
L_1 V_55 L_2 V_55 L_3 ,
V_37 , ( V_56 ) V_50 , ( V_56 ) V_50 + V_51 ,
V_5 -> V_57 . V_58 . V_59 , V_5 -> V_57 . V_60 . V_61 ) ;
V_5 -> V_57 . V_58 . V_62 = V_50 ;
V_5 -> V_57 . V_58 . V_63 = V_51 ;
RETURN ( F_19 ( V_9 , V_5 , V_37 , V_5 -> V_52 ) ) ;
}
static inline const struct V_64 *
F_22 ( const struct V_65 * V_66 )
{
return F_23 ( & V_66 -> V_67 -> V_54 ) ;
}
static int F_24 ( const struct V_65 * V_68 ,
const struct V_65 * V_69 )
{
return F_25 ( F_22 ( V_68 ) , F_22 ( V_69 ) ) ? :
F_26 ( V_68 -> V_70 , V_69 -> V_70 ) ;
}
static int F_27 ( const struct V_65 * V_68 ,
const struct V_65 * V_69 )
{
int V_71 ;
V_71 = F_25 ( F_22 ( V_68 ) , F_22 ( V_69 ) ) ;
if ( V_71 )
return V_71 ;
if ( V_68 -> V_72 < V_69 -> V_70 )
return - 1 ;
if ( V_68 -> V_70 > V_68 -> V_72 )
return 1 ;
return 0 ;
}
static void F_28 ( struct V_65 * V_68 ,
const struct V_65 * V_69 )
{
V_68 -> V_70 = F_29 ( V_68 -> V_70 , V_69 -> V_70 ) ;
V_68 -> V_72 = F_30 ( V_68 -> V_72 , V_69 -> V_72 ) ;
if ( V_69 -> V_73 == V_74 && V_68 -> V_73 != V_74 )
V_68 -> V_73 = V_74 ;
if ( V_69 -> V_73 == V_75 && V_68 -> V_73 != V_75 )
V_68 -> V_73 = V_75 ;
}
static void F_31 ( struct V_4 * V_5 )
{
int V_76 = 0 ;
V_21 ;
do {
struct V_77 * V_78 ;
struct V_77 * V_23 ;
struct V_77 * V_79 ;
V_76 = 1 ;
V_23 = NULL ;
F_32 (curr, temp,
&io->ci_lockset.cls_todo,
cill_linkage) {
if ( V_23 != NULL ) {
switch ( F_24 ( & V_23 -> V_80 ,
& V_78 -> V_80 ) ) {
case 0 :
default:
F_13 () ;
case + 1 :
F_33 ( & V_78 -> V_81 ,
& V_23 -> V_81 ) ;
V_76 = 0 ;
continue;
case - 1 :
break;
}
}
V_23 = V_78 ;
}
} while ( ! V_76 );
EXIT ;
}
int F_34 ( const struct V_82 * V_83 ,
const struct V_65 * V_84 )
{
struct V_77 * V_40 ;
V_21 ;
F_35 (scan, queue, cill_linkage) {
if ( F_36 ( & V_40 -> V_80 , V_84 ) )
RETURN ( + 1 ) ;
}
RETURN ( 0 ) ;
}
static int F_37 ( const struct V_82 * V_83 ,
const struct V_65 * V_84 )
{
struct V_77 * V_40 ;
V_21 ;
F_35 (scan, queue, cill_linkage) {
if ( F_27 ( & V_40 -> V_80 , V_84 ) )
continue;
F_28 ( & V_40 -> V_80 , V_84 ) ;
F_38 ( V_53 , L_4 ,
V_40 -> V_80 . V_73 , V_40 -> V_80 . V_70 ,
V_40 -> V_80 . V_72 ) ;
RETURN ( + 1 ) ;
}
RETURN ( 0 ) ;
}
static int F_39 ( const struct V_85 * V_86 ,
const struct V_65 * V_84 )
{
return F_34 ( & V_86 -> V_45 , V_84 ) ||
F_34 ( & V_86 -> V_46 , V_84 ) ;
}
static int F_40 ( const struct V_85 * V_86 ,
const struct V_65 * V_84 )
{
return F_37 ( & V_86 -> V_44 , V_84 ) ||
F_39 ( V_86 , V_84 ) ;
}
static int F_41 ( const struct V_8 * V_9 ,
struct V_4 * V_5 , struct V_85 * V_86 ,
struct V_77 * V_87 )
{
struct V_88 * V_89 ;
int V_41 ;
V_21 ;
V_89 = F_42 ( V_9 , V_5 , & V_87 -> V_80 , L_5 , V_5 ) ;
if ( ! F_43 ( V_89 ) ) {
V_87 -> V_90 = V_89 ;
F_44 ( & V_87 -> V_81 , & V_86 -> V_45 ) ;
if ( ! ( V_87 -> V_80 . V_91 & V_92 ) ) {
V_41 = F_45 ( V_9 , V_89 ) ;
if ( V_41 == 0 )
F_44 ( & V_87 -> V_81 ,
& V_86 -> V_46 ) ;
} else
V_41 = 0 ;
} else
V_41 = F_46 ( V_89 ) ;
RETURN ( V_41 ) ;
}
static void F_47 ( const struct V_8 * V_9 , struct V_4 * V_5 ,
struct V_77 * V_87 )
{
struct V_88 * V_89 = V_87 -> V_90 ;
V_21 ;
F_11 ( & V_87 -> V_81 ) ;
if ( V_89 != NULL ) {
F_48 ( V_9 , V_89 , L_5 , V_5 ) ;
V_87 -> V_90 = NULL ;
}
if ( V_87 -> V_93 != NULL )
V_87 -> V_93 ( V_9 , V_87 ) ;
EXIT ;
}
static int F_49 ( const struct V_8 * V_9 , struct V_4 * V_5 ,
struct V_85 * V_86 )
{
struct V_77 * V_87 ;
struct V_77 * V_79 ;
struct V_88 * V_89 ;
int V_41 ;
V_21 ;
V_41 = 0 ;
F_32 (link, temp, &set->cls_todo, cill_linkage) {
if ( ! F_39 ( V_86 , & V_87 -> V_80 ) ) {
V_41 = F_41 ( V_9 , V_5 , V_86 , V_87 ) ;
if ( V_41 != 0 )
break;
} else
F_47 ( V_9 , V_5 , V_87 ) ;
}
if ( V_41 == 0 ) {
F_32 (link, temp,
&set->cls_curr, cill_linkage) {
V_89 = V_87 -> V_90 ;
V_41 = F_45 ( V_9 , V_89 ) ;
if ( V_41 == 0 )
F_44 ( & V_87 -> V_81 ,
& V_86 -> V_46 ) ;
else
break;
}
}
RETURN ( V_41 ) ;
}
int F_50 ( const struct V_8 * V_9 , struct V_4 * V_5 )
{
const struct V_17 * V_40 ;
int V_41 = 0 ;
F_8 ( F_2 ( V_5 ) ) ;
F_8 ( V_5 -> V_14 == V_94 ) ;
F_8 ( F_5 ( V_5 ) ) ;
V_21 ;
F_51 (scan, io) {
if ( V_40 -> V_25 -> V_26 [ V_5 -> V_6 ] . V_95 == NULL )
continue;
V_41 = V_40 -> V_25 -> V_26 [ V_5 -> V_6 ] . V_95 ( V_9 , V_40 ) ;
if ( V_41 != 0 )
break;
}
if ( V_41 == 0 ) {
F_31 ( V_5 ) ;
V_41 = F_49 ( V_9 , V_5 , & V_5 -> V_43 ) ;
}
if ( V_41 != 0 )
F_52 ( V_9 , V_5 ) ;
else
V_5 -> V_14 = V_16 ;
RETURN ( V_41 ) ;
}
void F_52 ( const struct V_8 * V_9 , struct V_4 * V_5 )
{
struct V_85 * V_86 ;
struct V_77 * V_87 ;
struct V_77 * V_79 ;
const struct V_17 * V_40 ;
F_12 ( F_2 ( V_5 ) ) ;
F_12 ( V_94 <= V_5 -> V_14 && V_5 -> V_14 < V_96 ) ;
F_8 ( F_5 ( V_5 ) ) ;
V_21 ;
V_86 = & V_5 -> V_43 ;
F_32 (link, temp, &set->cls_todo, cill_linkage)
F_47 ( V_9 , V_5 , V_87 ) ;
F_32 (link, temp, &set->cls_curr, cill_linkage)
F_47 ( V_9 , V_5 , V_87 ) ;
F_32 (link, temp, &set->cls_done, cill_linkage) {
F_53 ( V_9 , V_87 -> V_90 ) ;
F_47 ( V_9 , V_5 , V_87 ) ;
}
F_54 (scan, io) {
if ( V_40 -> V_25 -> V_26 [ V_5 -> V_6 ] . V_97 != NULL )
V_40 -> V_25 -> V_26 [ V_5 -> V_6 ] . V_97 ( V_9 , V_40 ) ;
}
V_5 -> V_14 = V_96 ;
F_12 ( ! F_4 ( V_9 ) -> V_98 [ V_99 ] . V_100 ) ;
EXIT ;
}
int F_55 ( const struct V_8 * V_9 , struct V_4 * V_5 )
{
const struct V_17 * V_40 ;
int V_41 ;
F_8 ( F_2 ( V_5 ) ) ;
F_8 ( V_5 -> V_14 == V_49 || V_5 -> V_14 == V_101 ) ;
F_8 ( F_5 ( V_5 ) ) ;
V_21 ;
V_41 = 0 ;
F_51 (scan, io) {
if ( V_40 -> V_25 -> V_26 [ V_5 -> V_6 ] . V_102 == NULL )
continue;
V_41 = V_40 -> V_25 -> V_26 [ V_5 -> V_6 ] . V_102 ( V_9 ,
V_40 ) ;
if ( V_41 != 0 )
break;
}
if ( V_41 == 0 )
V_5 -> V_14 = V_94 ;
RETURN ( V_41 ) ;
}
void F_56 ( const struct V_8 * V_9 , struct V_4 * V_5 )
{
const struct V_17 * V_40 ;
F_8 ( F_2 ( V_5 ) ) ;
F_8 ( V_5 -> V_14 == V_96 ) ;
F_8 ( F_5 ( V_5 ) ) ;
V_21 ;
F_54 (scan, io) {
if ( V_40 -> V_25 -> V_26 [ V_5 -> V_6 ] . V_103 != NULL )
V_40 -> V_25 -> V_26 [ V_5 -> V_6 ] . V_103 ( V_9 , V_40 ) ;
}
V_5 -> V_14 = V_101 ;
EXIT ;
}
void F_57 ( const struct V_8 * V_9 , struct V_4 * V_5 , T_2 V_104 )
{
const struct V_17 * V_40 ;
F_8 ( V_5 -> V_6 == V_2 || V_5 -> V_6 == V_30 ||
V_104 == 0 ) ;
F_8 ( F_2 ( V_5 ) ) ;
F_8 ( F_5 ( V_5 ) ) ;
V_21 ;
V_5 -> V_57 . V_58 . V_62 += V_104 ;
V_5 -> V_57 . V_58 . V_63 -= V_104 ;
F_54 (scan, io) {
if ( V_40 -> V_25 -> V_26 [ V_5 -> V_6 ] . V_105 != NULL )
V_40 -> V_25 -> V_26 [ V_5 -> V_6 ] . V_105 ( V_9 , V_40 ,
V_104 ) ;
}
EXIT ;
}
int F_58 ( const struct V_8 * V_9 , struct V_4 * V_5 ,
struct V_77 * V_87 )
{
int V_41 ;
V_21 ;
if ( F_40 ( & V_5 -> V_43 , & V_87 -> V_80 ) )
V_41 = + 1 ;
else {
F_59 ( & V_87 -> V_81 , & V_5 -> V_43 . V_44 ) ;
V_41 = 0 ;
}
RETURN ( V_41 ) ;
}
static void F_60 ( const struct V_8 * V_9 ,
struct V_77 * V_87 )
{
F_61 ( V_87 ) ;
}
int F_62 ( const struct V_8 * V_9 , struct V_4 * V_5 ,
struct V_65 * V_66 )
{
struct V_77 * V_87 ;
int V_41 ;
V_21 ;
F_63 ( V_87 ) ;
if ( V_87 != NULL ) {
V_87 -> V_80 = * V_66 ;
V_87 -> V_93 = F_60 ;
V_41 = F_58 ( V_9 , V_5 , V_87 ) ;
if ( V_41 )
V_87 -> V_93 ( V_9 , V_87 ) ;
} else
V_41 = - V_106 ;
RETURN ( V_41 ) ;
}
int F_64 ( const struct V_8 * V_9 , struct V_4 * V_5 )
{
const struct V_17 * V_40 ;
int V_41 = 0 ;
F_8 ( F_2 ( V_5 ) ) ;
F_8 ( V_5 -> V_14 == V_16 ) ;
F_8 ( F_5 ( V_5 ) ) ;
V_21 ;
V_5 -> V_14 = V_15 ;
F_51 (scan, io) {
if ( V_40 -> V_25 -> V_26 [ V_5 -> V_6 ] . V_107 == NULL )
continue;
V_41 = V_40 -> V_25 -> V_26 [ V_5 -> V_6 ] . V_107 ( V_9 , V_40 ) ;
if ( V_41 != 0 )
break;
}
if ( V_41 >= 0 )
V_41 = 0 ;
RETURN ( V_41 ) ;
}
void F_65 ( const struct V_8 * V_9 , struct V_4 * V_5 )
{
const struct V_17 * V_40 ;
F_8 ( F_2 ( V_5 ) ) ;
F_8 ( V_5 -> V_14 == V_15 ) ;
F_8 ( F_5 ( V_5 ) ) ;
V_21 ;
F_54 (scan, io) {
if ( V_40 -> V_25 -> V_26 [ V_5 -> V_6 ] . V_108 != NULL )
V_40 -> V_25 -> V_26 [ V_5 -> V_6 ] . V_108 ( V_9 , V_40 ) ;
}
V_5 -> V_14 = V_109 ;
EXIT ;
}
static const struct V_110 *
F_66 ( const struct V_17 * V_111 , struct V_112 * V_113 )
{
const struct V_110 * V_18 ;
V_18 = F_67 ( V_113 , V_111 -> V_114 -> V_54 . V_115 -> V_116 ) ;
F_8 ( V_18 != NULL ) ;
return V_18 ;
}
static int F_68 ( const struct V_112 * V_113 , const struct V_4 * V_5 )
{
int V_41 = 1 ;
T_1 V_117 ;
T_1 V_118 ;
T_3 V_119 ;
V_119 = V_113 -> V_120 ;
switch ( V_5 -> V_6 ) {
case V_2 :
case V_30 :
if ( ! F_69 ( V_5 ) ) {
const struct V_121 * V_122 = & ( V_5 -> V_57 . V_58 ) ;
V_117 = F_70 ( V_113 -> V_123 , V_119 ) ;
V_118 = F_70 ( V_113 -> V_123 , V_119 + 1 ) ;
V_41 = V_122 -> V_62 < V_118 &&
V_117 < V_122 -> V_62 + V_122 -> V_63 ;
}
break;
case V_31 :
V_41 = V_5 -> V_57 . V_124 . V_125 == V_119 ;
break;
default:
F_13 () ;
}
return V_41 ;
}
int F_71 ( const struct V_8 * V_9 , struct V_4 * V_5 ,
struct V_112 * V_113 )
{
const struct V_17 * V_40 ;
struct V_126 * V_83 ;
int V_41 = 0 ;
F_8 ( V_5 -> V_6 == V_2 || V_5 -> V_6 == V_31 ) ;
F_8 ( F_72 ( V_113 , V_5 ) ) ;
F_8 ( V_5 -> V_14 == V_15 || V_5 -> V_14 == V_16 ) ;
F_8 ( F_68 ( V_113 , V_5 ) ) ;
F_8 ( F_5 ( V_5 ) ) ;
V_21 ;
V_83 = & V_5 -> V_127 ;
F_73 ( V_83 ) ;
F_51 (scan, io) {
if ( V_40 -> V_25 -> V_128 != NULL ) {
const struct V_110 * V_18 ;
V_18 = F_66 ( V_40 , V_113 ) ;
F_8 ( V_18 != NULL ) ;
V_41 = V_40 -> V_25 -> V_128 ( V_9 , V_40 , V_18 ) ;
if ( V_41 != 0 )
break;
}
}
if ( V_41 == 0 )
V_41 = F_74 ( V_9 , V_5 , V_129 , V_83 ) ;
F_75 ( V_9 , V_5 , & V_83 -> V_130 ) ;
F_76 ( V_9 , V_83 ) ;
RETURN ( V_41 ) ;
}
int F_77 ( const struct V_8 * V_9 , struct V_4 * V_5 ,
struct V_112 * V_113 , unsigned V_131 , unsigned V_132 )
{
const struct V_17 * V_40 ;
int V_41 = 0 ;
F_8 ( V_5 -> V_6 == V_30 ) ;
F_8 ( F_72 ( V_113 , V_5 ) ) ;
F_8 ( V_5 -> V_14 == V_15 || V_5 -> V_14 == V_16 ) ;
F_8 ( F_5 ( V_5 ) ) ;
F_12 ( F_68 ( V_113 , V_5 ) ) ;
V_21 ;
F_54 (scan, io) {
if ( V_40 -> V_25 -> V_133 != NULL ) {
const struct V_110 * V_18 ;
V_18 = F_66 ( V_40 , V_113 ) ;
V_41 = V_40 -> V_25 -> V_133 ( V_9 , V_40 ,
V_18 ,
V_131 , V_132 ) ;
if ( V_41 != 0 )
break;
}
}
RETURN ( V_41 ) ;
}
int F_78 ( const struct V_8 * V_9 , struct V_4 * V_5 ,
struct V_112 * V_113 , unsigned V_131 , unsigned V_132 )
{
const struct V_17 * V_40 ;
int V_41 = 0 ;
F_8 ( V_5 -> V_6 == V_30 ) ;
F_8 ( V_5 -> V_14 == V_15 || V_5 -> V_14 == V_16 ) ;
F_8 ( F_5 ( V_5 ) ) ;
F_12 ( F_72 ( V_113 , V_5 ) || V_113 -> V_134 != NULL ) ;
F_12 ( F_68 ( V_113 , V_5 ) ) ;
V_21 ;
F_51 (scan, io) {
if ( V_40 -> V_25 -> V_135 != NULL ) {
const struct V_110 * V_18 ;
V_18 = F_66 ( V_40 , V_113 ) ;
V_41 = V_40 -> V_25 -> V_135 ( V_9 , V_40 ,
V_18 ,
V_131 , V_132 ) ;
if ( V_41 != 0 )
break;
}
}
F_8 ( V_41 <= 0 ) ;
RETURN ( V_41 ) ;
}
int F_74 ( const struct V_8 * V_9 , struct V_4 * V_5 ,
enum V_136 V_137 , struct V_126 * V_83 )
{
const struct V_17 * V_40 ;
int V_41 = 0 ;
F_8 ( V_137 < F_79 ( V_40 -> V_25 -> V_138 ) ) ;
V_21 ;
F_51 (scan, io) {
if ( V_40 -> V_25 -> V_138 [ V_137 ] . V_139 == NULL )
continue;
V_41 = V_40 -> V_25 -> V_138 [ V_137 ] . V_139 ( V_9 , V_40 , V_137 ,
V_83 ) ;
if ( V_41 != 0 )
break;
}
F_12 ( F_6 ( V_41 != 0 , F_9 ( & V_83 -> V_140 . V_141 ) ) ) ;
RETURN ( V_41 ) ;
}
int F_80 ( const struct V_8 * V_9 , struct V_4 * V_5 ,
enum V_136 V_37 , struct V_126 * V_83 ,
long V_142 )
{
struct V_143 * V_144 = & F_4 ( V_9 ) -> V_145 ;
struct V_112 * V_146 ;
int V_147 ;
F_81 (pg, &queue->c2_qin) {
F_12 ( V_146 -> V_148 == NULL ) ;
V_146 -> V_148 = V_144 ;
}
F_82 ( V_144 , V_83 -> V_130 . V_149 ) ;
V_147 = F_74 ( V_9 , V_5 , V_37 , V_83 ) ;
if ( V_147 == 0 ) {
F_81 (pg, &queue->c2_qin) {
V_146 -> V_148 = NULL ;
F_83 ( V_144 , + 1 ) ;
}
V_147 = F_84 ( V_9 , V_5 , & V_83 -> V_140 ,
V_144 , V_142 ) ;
} else {
F_12 ( F_9 ( & V_83 -> V_140 . V_141 ) ) ;
F_81 (pg, &queue->c2_qin)
V_146 -> V_148 = NULL ;
}
return V_147 ;
}
int F_85 ( const struct V_8 * V_9 , struct V_4 * V_5 ,
struct V_150 * V_83 )
{
struct V_112 * V_113 ;
int V_41 = 0 ;
F_86 ( L_6 ) ;
F_81 (page, queue) {
int V_147 ;
F_8 ( F_68 ( V_113 , V_5 ) ) ;
V_147 = F_87 ( V_9 , V_113 ) ;
V_41 = V_41 ? : V_147 ;
}
return V_41 ;
}
int F_88 ( const struct V_8 * V_9 , struct V_4 * V_5 )
{
int V_41 = 0 ;
F_8 ( F_2 ( V_5 ) ) ;
V_21 ;
do {
T_2 V_104 ;
V_5 -> V_151 = 0 ;
V_41 = F_55 ( V_9 , V_5 ) ;
if ( V_41 == 0 ) {
V_104 = V_5 -> V_152 ;
V_41 = F_50 ( V_9 , V_5 ) ;
if ( V_41 == 0 ) {
V_41 = F_64 ( V_9 , V_5 ) ;
F_65 ( V_9 , V_5 ) ;
F_52 ( V_9 , V_5 ) ;
F_57 ( V_9 , V_5 , V_5 -> V_152 - V_104 ) ;
}
}
F_56 ( V_9 , V_5 ) ;
} while ( V_41 == 0 && V_5 -> V_151 );
if ( V_41 == 0 )
V_41 = V_5 -> V_153 ;
RETURN ( V_41 < 0 ? V_41 : 0 ) ;
}
void F_89 ( struct V_4 * V_5 , struct V_17 * V_18 ,
struct V_38 * V_39 ,
const struct V_154 * V_155 )
{
struct V_82 * V_156 = & V_18 -> V_24 ;
F_12 ( ( V_156 -> V_23 == NULL && V_156 -> V_157 == NULL ) ||
F_9 ( V_156 ) ) ;
V_21 ;
F_90 ( V_156 , & V_5 -> V_22 ) ;
V_18 -> V_28 = V_5 ;
V_18 -> V_114 = V_39 ;
V_18 -> V_25 = V_155 ;
EXIT ;
}
void F_91 ( struct V_150 * V_158 )
{
V_21 ;
V_158 -> V_149 = 0 ;
F_15 ( & V_158 -> V_141 ) ;
V_158 -> V_159 = V_160 ;
EXIT ;
}
void F_92 ( struct V_150 * V_158 , struct V_112 * V_113 )
{
V_21 ;
F_12 ( V_113 -> V_161 != NULL ) ;
F_8 ( V_158 -> V_159 == V_160 ) ;
F_93 () ;
F_94 ( & V_113 -> V_162 ) ;
F_95 () ;
F_12 ( F_9 ( & V_113 -> V_163 ) ) ;
F_90 ( & V_113 -> V_163 , & V_158 -> V_141 ) ;
++ V_158 -> V_149 ;
V_113 -> V_164 = F_96 ( & V_113 -> V_165 , L_7 , V_158 ) ;
F_97 ( V_113 ) ;
EXIT ;
}
void F_98 ( const struct V_8 * V_9 ,
struct V_150 * V_158 , struct V_112 * V_113 )
{
F_12 ( V_158 -> V_149 > 0 ) ;
F_8 ( V_158 -> V_159 == V_160 ) ;
V_21 ;
F_11 ( & V_113 -> V_163 ) ;
F_93 () ;
F_99 ( & V_113 -> V_162 ) ;
F_95 () ;
-- V_158 -> V_149 ;
F_100 ( & V_113 -> V_165 , V_113 -> V_164 , L_7 , V_158 ) ;
F_101 ( V_9 , V_113 ) ;
EXIT ;
}
void F_102 ( struct V_150 * V_166 , struct V_150 * V_167 ,
struct V_112 * V_113 )
{
F_12 ( V_167 -> V_149 > 0 ) ;
F_8 ( V_166 -> V_159 == V_160 ) ;
F_8 ( V_167 -> V_159 == V_160 ) ;
V_21 ;
F_33 ( & V_113 -> V_163 , & V_166 -> V_141 ) ;
-- V_167 -> V_149 ;
++ V_166 -> V_149 ;
F_103 ( & V_113 -> V_165 ,
V_113 -> V_164 , L_7 , V_167 , V_166 ) ;
EXIT ;
}
void F_104 ( struct V_150 * V_168 , struct V_150 * V_169 )
{
struct V_112 * V_113 ;
struct V_112 * V_170 ;
F_8 ( V_168 -> V_159 == V_160 ) ;
F_8 ( V_169 -> V_159 == V_160 ) ;
V_21 ;
F_105 (page, tmp, list)
F_102 ( V_169 , V_168 , V_113 ) ;
EXIT ;
}
void F_75 ( const struct V_8 * V_9 ,
struct V_4 * V_5 , struct V_150 * V_158 )
{
struct V_112 * V_113 ;
struct V_112 * V_79 ;
F_8 ( V_158 -> V_159 == V_160 ) ;
V_21 ;
F_105 (page, temp, plist) {
F_12 ( V_158 -> V_149 > 0 ) ;
F_11 ( & V_113 -> V_163 ) ;
F_93 () ;
F_99 ( & V_113 -> V_162 ) ;
F_95 () ;
-- V_158 -> V_149 ;
F_106 ( V_9 , V_5 , V_113 ) ;
F_107 ( & V_113 -> V_165 , L_7 , V_158 ) ;
F_101 ( V_9 , V_113 ) ;
}
EXIT ;
}
void F_108 ( const struct V_8 * V_9 , struct V_150 * V_158 )
{
struct V_112 * V_113 ;
struct V_112 * V_79 ;
F_8 ( V_158 -> V_159 == V_160 ) ;
V_21 ;
F_105 (page, temp, plist)
F_98 ( V_9 , V_158 , V_113 ) ;
F_12 ( V_158 -> V_149 == 0 ) ;
EXIT ;
}
int F_109 ( const struct V_8 * V_9 ,
struct V_4 * V_5 , struct V_150 * V_158 )
{
struct V_112 * V_113 ;
struct V_112 * V_79 ;
T_3 V_171 = 0 ;
int V_41 ;
F_8 ( V_158 -> V_159 == V_160 ) ;
V_21 ;
V_41 = 0 ;
F_105 (page, temp, plist) {
F_12 ( V_171 <= V_113 -> V_120 ) ;
V_171 = V_113 -> V_120 ;
if ( F_110 ( V_9 , V_5 , V_113 ) == 0 )
V_41 = V_41 ? : V_113 -> V_172 ;
else
F_98 ( V_9 , V_158 , V_113 ) ;
}
RETURN ( V_41 ) ;
}
void F_111 ( const struct V_8 * V_9 ,
struct V_4 * V_5 , struct V_150 * V_158 )
{
struct V_112 * V_113 ;
F_8 ( V_158 -> V_159 == V_160 ) ;
F_81 (page, plist)
F_112 ( V_9 , V_5 , V_113 ) ;
}
void F_113 ( const struct V_8 * V_9 , struct V_4 * V_5 ,
struct V_150 * V_158 )
{
struct V_112 * V_113 ;
F_8 ( V_158 -> V_159 == V_160 ) ;
V_21 ;
F_81 (page, plist)
F_114 ( V_9 , V_5 , V_113 ) ;
EXIT ;
}
int F_115 ( const struct V_8 * V_9 , struct V_4 * V_5 ,
struct V_150 * V_158 )
{
struct V_112 * V_113 ;
int V_41 ;
F_8 ( V_158 -> V_159 == V_160 ) ;
V_21 ;
V_41 = 0 ;
F_81 (page, plist) {
V_41 = F_116 ( V_9 , V_5 , V_113 ) ;
if ( V_41 != 0 )
break;
}
RETURN ( V_41 ) ;
}
void F_73 ( struct V_126 * V_83 )
{
V_21 ;
F_91 ( & V_83 -> V_130 ) ;
F_91 ( & V_83 -> V_140 ) ;
EXIT ;
}
void F_117 ( struct V_126 * V_83 , struct V_112 * V_113 )
{
V_21 ;
F_92 ( & V_83 -> V_130 , V_113 ) ;
EXIT ;
}
void F_118 ( const struct V_8 * V_9 ,
struct V_4 * V_5 , struct V_126 * V_83 )
{
V_21 ;
F_75 ( V_9 , V_5 , & V_83 -> V_130 ) ;
F_75 ( V_9 , V_5 , & V_83 -> V_140 ) ;
EXIT ;
}
void F_119 ( const struct V_8 * V_9 ,
struct V_4 * V_5 , struct V_126 * V_83 )
{
V_21 ;
F_113 ( V_9 , V_5 , & V_83 -> V_130 ) ;
F_113 ( V_9 , V_5 , & V_83 -> V_140 ) ;
EXIT ;
}
void F_120 ( const struct V_8 * V_9 ,
struct V_4 * V_5 , struct V_126 * V_83 )
{
F_111 ( V_9 , V_5 , & V_83 -> V_130 ) ;
F_111 ( V_9 , V_5 , & V_83 -> V_140 ) ;
}
void F_76 ( const struct V_8 * V_9 , struct V_126 * V_83 )
{
V_21 ;
F_108 ( V_9 , & V_83 -> V_140 ) ;
F_108 ( V_9 , & V_83 -> V_130 ) ;
EXIT ;
}
void F_121 ( struct V_126 * V_83 , struct V_112 * V_113 )
{
V_21 ;
F_73 ( V_83 ) ;
F_117 ( V_83 , V_113 ) ;
EXIT ;
}
struct V_4 * F_122 ( struct V_4 * V_5 )
{
V_21 ;
while ( V_5 -> V_12 != NULL )
V_5 = V_5 -> V_12 ;
RETURN ( V_5 ) ;
}
void F_123 ( const struct V_8 * V_9 , void * V_173 ,
T_4 V_174 , const struct V_4 * V_5 )
{
}
void F_124 ( struct V_175 * V_176 , struct V_177 * V_18 ,
struct V_178 * V_179 ,
const struct V_180 * V_155 )
{
V_21 ;
F_90 ( & V_18 -> V_181 , & V_176 -> V_182 ) ;
V_18 -> V_183 = V_179 ;
V_18 -> V_184 = V_155 ;
V_18 -> V_185 = V_176 ;
EXIT ;
}
static void F_125 ( const struct V_8 * V_9 , struct V_175 * V_176 )
{
unsigned V_186 ;
F_12 ( F_9 ( & V_176 -> V_187 ) ) ;
F_12 ( V_176 -> V_188 == 0 ) ;
F_8 ( F_9 ( & V_176 -> V_182 ) ) ;
F_8 ( F_126 ( V_176 -> V_189 > 0 , V_176 -> V_190 != NULL ) ) ;
V_21 ;
if ( V_176 -> V_190 != NULL ) {
for ( V_186 = 0 ; V_186 < V_176 -> V_189 ; ++ V_186 ) {
struct V_38 * V_39 = V_176 -> V_190 [ V_186 ] . V_191 ;
if ( V_39 != NULL ) {
F_127 ( & V_39 -> V_54 ,
V_176 -> V_190 [ V_186 ] . V_192 ,
L_8 , V_176 ) ;
F_128 ( V_9 , V_39 ) ;
}
}
F_129 ( V_176 -> V_190 , V_176 -> V_189 * sizeof V_176 -> V_190 [ 0 ] ) ;
}
F_61 ( V_176 ) ;
EXIT ;
}
static int F_130 ( const struct V_8 * V_9 , struct V_175 * V_176 ,
struct V_112 * V_113 )
{
struct V_178 * V_179 ;
struct V_110 * V_18 ;
int V_41 ;
V_21 ;
V_41 = 0 ;
V_113 = F_131 ( V_113 ) ;
do {
F_35 (slice, &page->cp_layers, cpl_linkage) {
V_179 = F_132 ( V_18 -> V_193 -> V_54 . V_115 ) ;
if ( V_179 -> V_194 -> V_195 != NULL ) {
V_41 = V_179 -> V_194 -> V_195 ( V_9 ,
V_179 , V_176 ) ;
if ( V_41 != 0 )
break;
}
}
V_113 = V_113 -> V_196 ;
} while ( V_113 != NULL && V_41 == 0 );
RETURN ( V_41 ) ;
}
void F_133 ( const struct V_8 * V_9 , struct V_175 * V_176 , int V_147 )
{
struct V_177 * V_18 ;
V_21 ;
while ( ! F_9 ( & V_176 -> V_182 ) ) {
V_18 = F_134 ( V_176 -> V_182 . V_23 ,
struct V_177 , V_181 ) ;
F_11 ( & V_18 -> V_181 ) ;
if ( V_18 -> V_184 -> V_197 != NULL )
V_18 -> V_184 -> V_197 ( V_9 , V_18 , V_147 ) ;
}
F_125 ( V_9 , V_176 ) ;
EXIT ;
}
struct V_175 * F_135 ( const struct V_8 * V_9 , struct V_112 * V_113 ,
enum V_136 V_137 , int V_198 )
{
struct V_175 * V_176 ;
F_8 ( V_198 > 0 ) ;
V_21 ;
F_63 ( V_176 ) ;
if ( V_176 != NULL ) {
int V_41 ;
F_136 ( V_176 -> V_190 , V_198 * sizeof V_176 -> V_190 [ 0 ] ) ;
if ( V_176 -> V_190 != NULL ) {
V_176 -> V_189 = V_198 ;
V_176 -> V_199 = V_137 ;
F_15 ( & V_176 -> V_187 ) ;
F_15 ( & V_176 -> V_182 ) ;
V_41 = F_130 ( V_9 , V_176 , V_113 ) ;
} else
V_41 = - V_106 ;
if ( V_41 != 0 ) {
F_133 ( V_9 , V_176 , V_41 ) ;
V_176 = F_137 ( V_41 ) ;
}
} else
V_176 = F_137 ( - V_106 ) ;
RETURN ( V_176 ) ;
}
void F_138 ( const struct V_8 * V_9 ,
struct V_175 * V_176 , struct V_112 * V_113 )
{
struct V_38 * V_39 ;
struct V_200 * V_201 ;
int V_186 ;
V_21 ;
V_113 = F_131 ( V_113 ) ;
F_12 ( F_9 ( & V_113 -> V_202 ) ) ;
F_12 ( V_113 -> V_203 == NULL ) ;
F_139 ( V_204 , V_9 , V_113 , L_9 ,
V_176 , V_176 -> V_199 , V_176 -> V_188 ) ;
F_90 ( & V_113 -> V_202 , & V_176 -> V_187 ) ;
++ V_176 -> V_188 ;
V_113 -> V_203 = V_176 ;
V_39 = F_18 ( V_113 -> V_123 ) ;
for ( V_186 = 0 , V_201 = V_176 -> V_190 ; V_39 != V_201 -> V_191 ; ++ V_186 , ++ V_201 ) {
if ( V_201 -> V_191 == NULL ) {
V_201 -> V_191 = V_39 ;
F_140 ( V_39 ) ;
V_201 -> V_192 = F_141 ( & V_39 -> V_54 ,
L_8 , V_176 ) ;
break;
}
}
F_12 ( V_186 < V_176 -> V_189 ) ;
EXIT ;
}
void F_142 ( const struct V_8 * V_9 , struct V_112 * V_113 )
{
struct V_175 * V_176 = V_113 -> V_203 ;
V_21 ;
V_113 = F_131 ( V_113 ) ;
F_12 ( ! F_9 ( & V_113 -> V_202 ) ) ;
F_12 ( V_176 -> V_188 > 0 ) ;
F_11 ( & V_113 -> V_202 ) ;
-- V_176 -> V_188 ;
V_113 -> V_203 = NULL ;
EXIT ;
}
int F_143 ( const struct V_8 * V_9 , struct V_175 * V_176 )
{
int V_186 ;
int V_41 ;
const struct V_177 * V_18 ;
V_21 ;
for ( V_186 = 0 ; V_186 < V_176 -> V_189 ; ++ V_186 )
F_12 ( V_176 -> V_190 [ V_186 ] . V_191 != NULL ) ;
V_41 = 0 ;
F_35 (slice, &req->crq_layers, crs_linkage) {
if ( V_18 -> V_184 -> V_205 != NULL ) {
V_41 = V_18 -> V_184 -> V_205 ( V_9 , V_18 ) ;
if ( V_41 != 0 )
break;
}
}
RETURN ( V_41 ) ;
}
void F_144 ( const struct V_8 * V_9 , struct V_175 * V_176 ,
struct V_206 * V_207 , T_5 V_208 )
{
const struct V_177 * V_18 ;
struct V_112 * V_113 ;
int V_186 ;
F_12 ( ! F_9 ( & V_176 -> V_187 ) ) ;
V_21 ;
V_113 = F_134 ( V_176 -> V_187 . V_157 , struct V_112 , V_202 ) ;
for ( V_186 = 0 ; V_186 < V_176 -> V_189 ; ++ V_186 ) {
F_35 (slice, &req->crq_layers, crs_linkage) {
const struct V_110 * V_40 ;
const struct V_38 * V_39 ;
V_40 = F_67 ( V_113 ,
V_18 -> V_183 -> V_209 . V_116 ) ;
F_12 ( V_40 != NULL ) ;
V_39 = V_40 -> V_193 ;
if ( V_18 -> V_184 -> V_210 != NULL )
V_18 -> V_184 -> V_210 ( V_9 , V_18 , V_39 ,
V_207 + V_186 , V_208 ) ;
}
}
EXIT ;
}
void F_82 ( struct V_143 * V_144 , int V_211 )
{
V_21 ;
F_145 ( & V_144 -> V_212 ) ;
F_146 ( & V_144 -> V_213 , V_211 ) ;
F_146 ( & V_144 -> V_214 , V_211 > 0 ) ;
V_144 -> V_215 = 0 ;
EXIT ;
}
int F_84 ( const struct V_8 * V_9 , struct V_4 * V_5 ,
struct V_150 * V_83 , struct V_143 * V_144 ,
long V_142 )
{
struct V_216 V_217 = F_147 ( F_148 ( V_142 ) ,
NULL , NULL , NULL ) ;
int V_147 ;
V_21 ;
F_12 ( V_142 >= 0 ) ;
V_147 = F_149 ( V_144 -> V_212 ,
F_150 ( & V_144 -> V_213 ) == 0 ,
& V_217 ) ;
if ( V_147 < 0 ) {
F_86 ( L_10
L_11 ,
V_147 , F_150 ( & V_144 -> V_213 ) ) ;
( void ) F_85 ( V_9 , V_5 , V_83 ) ;
V_217 = (struct V_216 ) { 0 } ;
( void ) F_149 ( V_144 -> V_212 ,
F_150 ( & V_144 -> V_213 ) == 0 ,
& V_217 ) ;
} else {
V_147 = V_144 -> V_215 ;
}
F_12 ( F_150 ( & V_144 -> V_213 ) == 0 ) ;
F_111 ( V_9 , V_5 , V_83 ) ;
while ( F_151 ( F_150 ( & V_144 -> V_214 ) != 0 ) ) {
F_152 () ;
}
F_153 ( V_144 , 0x5a , sizeof *V_144 ) ;
RETURN ( V_147 ) ;
}
void F_83 ( struct V_143 * V_144 , int V_218 )
{
V_21 ;
if ( V_144 -> V_215 == 0 && V_218 < 0 )
V_144 -> V_215 = V_218 ;
F_12 ( F_150 ( & V_144 -> V_213 ) > 0 ) ;
if ( F_154 ( & V_144 -> V_213 ) ) {
F_155 ( & V_144 -> V_212 ) ;
F_146 ( & V_144 -> V_214 , 0 ) ;
}
EXIT ;
}
