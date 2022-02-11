static inline int
F_1 ( struct V_1 * V_2 )
{
return ( V_2 - V_2 -> V_3 -> V_4 ) ;
}
static inline int
F_2 ( struct V_5 * V_6 )
{
return ( V_6 - V_6 -> V_7 -> V_8 ) ;
}
static inline T_1
F_3 ( struct V_9 * V_10 , T_2 V_11 )
{
return ( V_10 -> V_12 | V_11 ) ;
}
static inline T_1
F_4 ( T_1 V_13 )
{
return V_13 & ~ V_14 ;
}
static inline T_2
F_5 ( T_1 V_13 )
{
return ( T_2 ) ( V_13 & V_14 ) ;
}
static inline struct V_15 *
F_6 ( struct V_16 * V_17 )
{
return F_7 ( V_17 , struct V_15 ,
V_18 ) ;
}
static inline struct V_5 *
F_8 ( struct V_19 * V_20 )
{
return F_7 ( V_20 , struct V_5 , V_21 ) ;
}
static inline T_3
F_9 ( struct V_22 * V_23 , void * V_24 , T_4 V_25 ,
enum V_26 V_27 )
{
return V_23 ? F_10 ( V_23 , V_24 , V_25 , V_27 ) : ( T_3 ) 0L ;
}
static inline int
F_11 ( struct V_22 * V_23 , T_3 V_28 )
{
return V_23 ? F_12 ( V_23 , V_28 ) : 0 ;
}
static inline void
F_13 ( struct V_22 * V_23 , T_3 V_29 , T_4 V_25 ,
enum V_26 V_27 )
{
if ( V_23 )
F_14 ( V_23 , V_29 , V_25 , V_27 ) ;
}
static inline void
F_15 ( struct V_22 * V_23 , T_3 V_29 , T_4 V_25 ,
enum V_26 V_27 )
{
if ( V_23 )
F_16 ( V_23 , V_29 , V_25 , V_27 ) ;
}
static inline void
F_17 ( struct V_22 * V_23 , T_3 V_29 , T_4 V_25 ,
enum V_26 V_27 )
{
if ( V_23 )
F_18 ( V_23 , V_29 , V_25 , V_27 ) ;
}
static int
F_19 ( struct V_30 * V_31 , int V_32 )
{
struct V_30 * V_33 ;
int V_34 ;
F_20 ( V_32 == 0 || V_31 [ 0 ] . V_35 == 0 ) ;
F_21 (sg, s, nents, i) {
V_33 -> V_36 = 0L ;
#ifdef F_22
V_33 -> V_37 = V_33 -> V_35 ;
#endif
}
return V_32 ;
}
static inline int
F_23 ( struct V_22 * V_23 , struct V_30 * V_31 , int V_32 ,
enum V_26 V_27 )
{
return V_23 ? F_24 ( V_23 , V_31 , V_32 , V_27 ) : F_19 ( V_31 , V_32 ) ;
}
static inline void
F_25 ( struct V_22 * V_23 , struct V_30 * V_31 , int V_32 ,
enum V_26 V_27 )
{
if ( V_23 )
F_26 ( V_23 , V_31 , V_32 , V_27 ) ;
}
static int
F_27 ( struct V_15 * V_3 )
{
struct V_1 * V_4 ;
int V_34 ;
V_4 = F_28 ( V_38 , sizeof( struct V_1 ) ,
V_39 ) ;
if ( ! V_4 )
return - V_40 ;
V_3 -> V_4 = V_4 ;
for ( V_34 = 0 ; V_34 < V_38 ; V_4 ++ , V_34 ++ ) {
F_29 ( & V_4 -> V_41 , V_42 ) ;
V_4 -> V_3 = V_3 ;
F_30 ( & V_4 -> V_43 , & V_3 -> V_43 ) ;
V_4 -> V_44 = F_28 ( 2 , V_45 ,
V_39 ) ;
if ( ! V_4 -> V_44 )
goto V_46;
V_4 -> V_47 = V_4 -> V_44 + V_45 ;
V_4 -> V_48 = F_9 ( V_3 -> V_23 , V_4 -> V_47 ,
V_45 ,
V_49 ) ;
if ( F_11 ( V_3 -> V_23 , V_4 -> V_48 ) )
goto V_46;
}
return 0 ;
V_46:
F_31 ( V_4 -> V_44 ) ;
F_32 ( & V_4 -> V_43 ) ;
for ( V_4 -- , V_34 -- ; V_34 >= 0 ; V_4 -- , V_34 -- ) {
F_13 ( V_3 -> V_23 , V_4 -> V_48 ,
V_45 , V_49 ) ;
F_31 ( V_4 -> V_44 ) ;
F_32 ( & V_4 -> V_43 ) ;
}
F_31 ( V_4 ) ;
return - V_50 ;
}
static void
F_33 ( struct V_15 * V_3 )
{
struct V_1 * V_4 = V_3 -> V_4 ;
int V_34 ;
for ( V_34 = 0 ; V_34 < V_38 ; V_4 ++ , V_34 ++ ) {
F_13 ( V_3 -> V_23 ,
V_4 -> V_48 , V_45 ,
V_49 ) ;
F_31 ( V_4 -> V_44 ) ;
F_32 ( & V_4 -> V_43 ) ;
}
F_31 ( V_3 -> V_4 ) ;
}
static struct V_1 *
F_34 ( struct V_15 * V_3 )
{
struct V_1 * V_4 ;
unsigned long V_51 ;
F_35 ( & V_3 -> V_52 , V_51 ) ;
V_4 = F_36 ( & V_3 -> V_43 ,
struct V_1 , V_43 ) ;
if ( V_4 )
F_37 ( & V_4 -> V_43 , & V_3 -> V_53 ) ;
F_38 ( & V_3 -> V_52 , V_51 ) ;
return V_4 ;
}
static void
F_39 ( struct V_15 * V_3 ,
struct V_1 * V_4 )
{
unsigned long V_51 ;
F_35 ( & V_3 -> V_52 , V_51 ) ;
F_40 ( & V_4 -> V_43 , & V_3 -> V_43 ) ;
F_38 ( & V_3 -> V_52 , V_51 ) ;
}
static void
F_41 ( struct V_15 * V_3 ,
struct V_54 * V_7 )
{
struct V_5 * V_8 = V_7 -> V_8 ;
int V_34 ;
for ( V_34 = 0 ; V_34 < V_7 -> V_55 ; V_8 ++ , V_34 ++ ) {
F_29 ( & V_8 -> V_41 , V_56 ) ;
F_29 ( & V_8 -> V_57 , V_58 ) ;
V_8 -> V_3 = V_3 ;
V_8 -> V_7 = V_7 ;
V_8 -> V_59 = false ;
V_8 -> abort = false ;
V_8 -> V_60 = false ;
V_8 -> V_61 = NULL ;
F_30 ( & V_8 -> V_62 , & V_7 -> V_63 ) ;
F_42 ( & V_8 -> V_64 ) ;
V_8 -> V_48 = F_9 ( V_3 -> V_23 , & V_8 -> V_65 ,
sizeof( V_8 -> V_65 ) , V_49 ) ;
if ( F_11 ( V_3 -> V_23 , V_8 -> V_48 ) ) {
F_32 ( & V_8 -> V_62 ) ;
for ( V_8 -- , V_34 -- ; V_34 >= 0 ; V_8 -- , V_34 -- ) {
F_13 ( V_3 -> V_23 , V_8 -> V_48 ,
sizeof( V_8 -> V_65 ) ,
V_49 ) ;
V_8 -> V_48 = 0L ;
F_32 ( & V_8 -> V_62 ) ;
}
return;
}
}
}
static void
F_43 ( struct V_15 * V_3 ,
struct V_54 * V_7 )
{
struct V_5 * V_8 = V_7 -> V_8 ;
int V_34 ;
for ( V_34 = 0 ; V_34 < V_7 -> V_55 ; V_8 ++ , V_34 ++ ) {
if ( V_8 -> V_48 )
F_13 ( V_3 -> V_23 , V_8 -> V_48 ,
sizeof( V_8 -> V_65 ) , V_49 ) ;
}
}
static struct V_5 *
F_44 ( struct V_54 * V_7 )
{
struct V_5 * V_8 ;
F_45 ( & V_7 -> V_66 ) ;
V_8 = F_36 ( & V_7 -> V_63 ,
struct V_5 , V_62 ) ;
if ( V_8 ) {
F_32 ( & V_8 -> V_62 ) ;
V_8 -> V_59 = true ;
}
return V_8 ;
}
static void
F_46 ( struct V_15 * V_3 ,
struct V_54 * V_7 ,
struct V_67 * V_61 )
{
struct V_5 * V_8 = V_61 -> V_68 ;
V_61 -> V_69 = V_7 -> V_11 ?
( ( V_7 -> V_11 - 1 ) % V_3 -> V_70 -> V_71 ) : 0 ;
if ( V_3 -> V_70 -> V_72 & V_73 )
F_47 ( V_7 -> V_74 , V_7 -> V_75 , & V_8 -> V_41 ) ;
else
F_48 ( V_3 , V_8 ) ;
}
static void
F_49 ( struct V_54 * V_7 ,
struct V_5 * V_8 )
{
struct V_67 * V_61 = V_8 -> V_61 ;
struct V_15 * V_3 = V_8 -> V_3 ;
struct V_76 * V_77 ;
unsigned long V_51 ;
F_15 ( V_3 -> V_23 , V_8 -> V_48 ,
sizeof( V_8 -> V_65 ) , V_49 ) ;
V_61 -> V_68 = NULL ;
V_8 -> V_59 = false ;
V_8 -> abort = false ;
V_8 -> V_60 = false ;
V_8 -> V_78 = false ;
V_8 -> V_61 = NULL ;
V_3 -> V_70 -> V_79 ( & V_3 -> V_18 , V_61 ) ;
F_35 ( & V_7 -> V_66 , V_51 ) ;
V_77 = F_36 ( & V_7 -> V_80 ,
struct V_76 , V_81 ) ;
if ( ! V_77 ) {
F_30 ( & V_8 -> V_62 , & V_8 -> V_7 -> V_63 ) ;
F_38 ( & V_7 -> V_66 , V_51 ) ;
F_50 ( V_7 ) ;
return;
}
F_32 ( & V_77 -> V_81 ) ;
V_61 = V_77 -> V_82 ;
F_30 ( & V_77 -> V_81 , & V_7 -> V_83 ) ;
F_38 ( & V_7 -> V_66 , V_51 ) ;
memcpy ( & V_8 -> V_84 , V_61 -> V_85 , V_61 -> V_86 ) ;
V_61 -> V_85 = NULL ;
V_61 -> V_86 = 0 ;
V_61 -> V_68 = V_8 ;
V_8 -> V_61 = V_61 ;
V_8 -> V_59 = true ;
V_3 -> V_70 -> V_87 ( & V_3 -> V_18 , V_61 ) ;
F_46 ( V_3 , V_7 , V_61 ) ;
}
static int
F_51 ( struct V_15 * V_3 , int V_11 )
{
int V_74 , V_88 , V_89 ;
if ( V_3 -> V_70 -> V_71 == 1 )
return V_90 ;
V_88 = ! V_11 ? 0 : ( V_11 - 1 ) % F_52 () ;
for ( V_74 = 0 , V_89 = 0 ; ; ) {
if ( F_53 ( V_74 ) ) {
if ( V_89 == V_88 )
break;
V_89 ++ ;
}
V_74 = ( V_74 + 1 ) % F_54 () ;
}
return V_74 ;
}
static struct V_54 *
F_55 ( struct V_9 * V_10 ,
T_2 V_11 , T_2 V_55 )
{
struct V_54 * V_7 ;
unsigned long V_51 ;
int V_91 ;
if ( V_11 >= V_92 )
return NULL ;
V_7 = F_56 ( ( sizeof( * V_7 ) +
( sizeof( struct V_5 ) * V_55 ) ) ,
V_39 ) ;
if ( ! V_7 )
return NULL ;
if ( ! F_57 ( V_10 ) )
goto V_93;
V_7 -> V_75 = F_58 ( L_1 , 0 , 0 ,
V_10 -> V_3 -> V_18 . V_94 ,
V_10 -> V_95 , V_11 ) ;
if ( ! V_7 -> V_75 )
goto V_96;
V_7 -> V_8 = (struct V_5 * ) & V_7 [ 1 ] ;
V_7 -> V_11 = V_11 ;
V_7 -> V_55 = V_55 ;
V_7 -> V_10 = V_10 ;
V_7 -> V_97 = V_10 -> V_3 -> V_97 ;
V_7 -> V_74 = F_51 ( V_10 -> V_3 , V_11 ) ;
F_59 ( & V_7 -> V_63 ) ;
F_59 ( & V_7 -> V_83 ) ;
F_59 ( & V_7 -> V_80 ) ;
F_60 ( & V_7 -> V_98 , 0 ) ;
F_60 ( & V_7 -> V_99 , 0 ) ;
F_60 ( & V_7 -> V_100 , 1 ) ;
F_60 ( & V_7 -> V_101 , 0 ) ;
F_42 ( & V_7 -> V_66 ) ;
F_61 ( & V_7 -> V_102 ) ;
F_41 ( V_10 -> V_3 , V_7 ) ;
V_91 = F_62 ( & V_7 -> V_103 ) ;
if ( V_91 )
goto V_104;
F_20 ( V_10 -> V_105 [ V_11 ] ) ;
F_35 ( & V_10 -> V_3 -> V_52 , V_51 ) ;
V_10 -> V_105 [ V_11 ] = V_7 ;
F_38 ( & V_10 -> V_3 -> V_52 , V_51 ) ;
return V_7 ;
V_104:
F_43 ( V_10 -> V_3 , V_7 ) ;
F_63 ( V_7 -> V_75 ) ;
V_96:
F_64 ( V_10 ) ;
V_93:
F_31 ( V_7 ) ;
return NULL ;
}
static void
F_65 ( struct V_106 * V_102 )
{
struct V_54 * V_7 =
F_7 ( V_102 , struct V_54 , V_102 ) ;
unsigned long V_51 ;
F_35 ( & V_7 -> V_10 -> V_3 -> V_52 , V_51 ) ;
V_7 -> V_10 -> V_105 [ V_7 -> V_11 ] = NULL ;
F_38 ( & V_7 -> V_10 -> V_3 -> V_52 , V_51 ) ;
F_43 ( V_7 -> V_10 -> V_3 , V_7 ) ;
F_64 ( V_7 -> V_10 ) ;
F_63 ( V_7 -> V_75 ) ;
F_31 ( V_7 ) ;
}
static void
F_50 ( struct V_54 * V_7 )
{
F_66 ( & V_7 -> V_102 , F_65 ) ;
}
static int
F_67 ( struct V_54 * V_7 )
{
return F_68 ( & V_7 -> V_102 ) ;
}
static void
F_69 ( struct V_54 * V_7 )
{
struct V_15 * V_3 = V_7 -> V_10 -> V_3 ;
struct V_5 * V_8 = V_7 -> V_8 ;
struct V_76 * V_77 , * V_107 ;
unsigned long V_51 ;
int V_34 , V_78 ;
bool V_108 ;
V_108 = F_70 ( & V_7 -> V_98 , 0 ) ;
F_35 ( & V_7 -> V_66 , V_51 ) ;
for ( V_34 = 0 ; V_34 < V_7 -> V_55 ; V_8 ++ , V_34 ++ ) {
if ( V_8 -> V_59 ) {
F_71 ( & V_8 -> V_64 ) ;
V_8 -> abort = true ;
V_78 = V_8 -> V_78 ;
F_72 ( & V_8 -> V_64 ) ;
if ( V_78 ) {
F_71 ( & V_8 -> V_64 ) ;
V_8 -> V_60 = true ;
F_72 ( & V_8 -> V_64 ) ;
V_3 -> V_70 -> V_109 (
& V_3 -> V_18 , V_8 -> V_61 ) ;
}
}
}
F_73 (deferfcp, tempptr, &queue->avail_defer_list,
req_list) {
F_32 ( & V_77 -> V_81 ) ;
F_31 ( V_77 ) ;
}
for (; ; ) {
V_77 = F_36 ( & V_7 -> V_80 ,
struct V_76 , V_81 ) ;
if ( ! V_77 )
break;
F_32 ( & V_77 -> V_81 ) ;
F_38 ( & V_7 -> V_66 , V_51 ) ;
V_3 -> V_70 -> V_87 ( & V_3 -> V_18 ,
V_77 -> V_82 ) ;
V_3 -> V_70 -> V_109 ( & V_3 -> V_18 ,
V_77 -> V_82 ) ;
V_3 -> V_70 -> V_79 ( & V_3 -> V_18 ,
V_77 -> V_82 ) ;
F_31 ( V_77 ) ;
F_35 ( & V_7 -> V_66 , V_51 ) ;
}
F_38 ( & V_7 -> V_66 , V_51 ) ;
F_74 ( V_7 -> V_75 ) ;
if ( V_108 )
F_75 ( & V_7 -> V_103 ) ;
F_50 ( V_7 ) ;
}
static struct V_54 *
F_76 ( struct V_15 * V_3 ,
T_1 V_110 )
{
struct V_9 * V_10 ;
struct V_54 * V_7 ;
T_1 V_12 = F_4 ( V_110 ) ;
T_2 V_11 = F_5 ( V_110 ) ;
unsigned long V_51 ;
F_35 ( & V_3 -> V_52 , V_51 ) ;
F_77 (assoc, &tgtport->assoc_list, a_list) {
if ( V_12 == V_10 -> V_12 ) {
V_7 = V_10 -> V_105 [ V_11 ] ;
if ( V_7 &&
( ! F_78 ( & V_7 -> V_98 ) ||
! F_67 ( V_7 ) ) )
V_7 = NULL ;
F_38 ( & V_3 -> V_52 , V_51 ) ;
return V_7 ;
}
}
F_38 ( & V_3 -> V_52 , V_51 ) ;
return NULL ;
}
static struct V_9 *
F_79 ( struct V_15 * V_3 )
{
struct V_9 * V_10 , * V_111 ;
unsigned long V_51 ;
T_1 V_112 ;
int V_88 ;
bool V_113 = true ;
V_10 = F_56 ( sizeof( * V_10 ) , V_39 ) ;
if ( ! V_10 )
return NULL ;
V_88 = F_80 ( & V_3 -> V_114 , 0 , 0 , V_39 ) ;
if ( V_88 < 0 )
goto V_115;
if ( ! F_81 ( V_3 ) )
goto V_116;
V_10 -> V_3 = V_3 ;
V_10 -> V_95 = V_88 ;
F_59 ( & V_10 -> V_117 ) ;
F_61 ( & V_10 -> V_102 ) ;
while ( V_113 ) {
F_82 ( & V_112 , sizeof( V_112 ) - V_118 ) ;
V_112 = V_112 << V_119 ;
F_35 ( & V_3 -> V_52 , V_51 ) ;
V_113 = false ;
F_77 (tmpassoc, &tgtport->assoc_list, a_list)
if ( V_112 == V_111 -> V_12 ) {
V_113 = true ;
break;
}
if ( ! V_113 ) {
V_10 -> V_12 = V_112 ;
F_30 ( & V_10 -> V_117 , & V_3 -> V_120 ) ;
}
F_38 ( & V_3 -> V_52 , V_51 ) ;
}
return V_10 ;
V_116:
F_83 ( & V_3 -> V_114 , V_88 ) ;
V_115:
F_31 ( V_10 ) ;
return NULL ;
}
static void
F_84 ( struct V_106 * V_102 )
{
struct V_9 * V_10 =
F_7 ( V_102 , struct V_9 , V_102 ) ;
struct V_15 * V_3 = V_10 -> V_3 ;
unsigned long V_51 ;
F_35 ( & V_3 -> V_52 , V_51 ) ;
F_32 ( & V_10 -> V_117 ) ;
F_38 ( & V_3 -> V_52 , V_51 ) ;
F_83 ( & V_3 -> V_114 , V_10 -> V_95 ) ;
F_31 ( V_10 ) ;
F_85 ( V_3 ) ;
}
static void
F_64 ( struct V_9 * V_10 )
{
F_66 ( & V_10 -> V_102 , F_84 ) ;
}
static int
F_57 ( struct V_9 * V_10 )
{
return F_68 ( & V_10 -> V_102 ) ;
}
static void
F_86 ( struct V_9 * V_10 )
{
struct V_15 * V_3 = V_10 -> V_3 ;
struct V_54 * V_7 ;
unsigned long V_51 ;
int V_34 ;
F_35 ( & V_3 -> V_52 , V_51 ) ;
for ( V_34 = V_92 - 1 ; V_34 >= 0 ; V_34 -- ) {
V_7 = V_10 -> V_105 [ V_34 ] ;
if ( V_7 ) {
if ( ! F_67 ( V_7 ) )
continue;
F_38 ( & V_3 -> V_52 , V_51 ) ;
F_69 ( V_7 ) ;
F_50 ( V_7 ) ;
F_35 ( & V_3 -> V_52 , V_51 ) ;
}
}
F_38 ( & V_3 -> V_52 , V_51 ) ;
F_64 ( V_10 ) ;
}
static struct V_9 *
F_87 ( struct V_15 * V_3 ,
T_1 V_12 )
{
struct V_9 * V_10 ;
struct V_9 * V_91 = NULL ;
unsigned long V_51 ;
F_35 ( & V_3 -> V_52 , V_51 ) ;
F_77 (assoc, &tgtport->assoc_list, a_list) {
if ( V_12 == V_10 -> V_12 ) {
V_91 = V_10 ;
F_57 ( V_10 ) ;
break;
}
}
F_38 ( & V_3 -> V_52 , V_51 ) ;
return V_91 ;
}
int
F_88 ( struct V_121 * V_122 ,
struct V_123 * V_124 ,
struct V_22 * V_23 ,
struct V_16 * * V_125 )
{
struct V_15 * V_126 ;
unsigned long V_51 ;
int V_91 , V_88 ;
if ( ! V_124 -> V_127 || ! V_124 -> V_128 ||
! V_124 -> V_109 ||
! V_124 -> V_79 || ! V_124 -> V_129 ||
! V_124 -> V_71 || ! V_124 -> V_130 ||
! V_124 -> V_131 || ! V_124 -> V_132 ) {
V_91 = - V_133 ;
goto V_134;
}
V_126 = F_56 ( ( sizeof( * V_126 ) + V_124 -> V_135 ) ,
V_39 ) ;
if ( ! V_126 ) {
V_91 = - V_40 ;
goto V_134;
}
V_88 = F_80 ( & V_136 , 0 , 0 , V_39 ) ;
if ( V_88 < 0 ) {
V_91 = - V_137 ;
goto V_138;
}
if ( ! F_89 ( V_23 ) && V_23 ) {
V_91 = - V_139 ;
goto V_116;
}
V_126 -> V_18 . V_140 = V_122 -> V_140 ;
V_126 -> V_18 . V_141 = V_122 -> V_141 ;
V_126 -> V_18 . V_142 = & V_126 [ 1 ] ;
V_126 -> V_18 . V_143 = V_122 -> V_143 ;
V_126 -> V_18 . V_94 = V_88 ;
F_59 ( & V_126 -> V_144 ) ;
V_126 -> V_23 = V_23 ;
V_126 -> V_70 = V_124 ;
F_42 ( & V_126 -> V_52 ) ;
F_59 ( & V_126 -> V_43 ) ;
F_59 ( & V_126 -> V_53 ) ;
F_59 ( & V_126 -> V_120 ) ;
F_61 ( & V_126 -> V_102 ) ;
F_90 ( & V_126 -> V_114 ) ;
V_91 = F_27 ( V_126 ) ;
if ( V_91 ) {
V_91 = - V_40 ;
goto V_145;
}
F_35 ( & V_146 , V_51 ) ;
F_30 ( & V_126 -> V_144 , & V_147 ) ;
F_38 ( & V_146 , V_51 ) ;
* V_125 = & V_126 -> V_18 ;
return 0 ;
V_145:
F_91 ( V_23 ) ;
V_116:
F_83 ( & V_136 , V_88 ) ;
V_138:
F_31 ( V_126 ) ;
V_134:
* V_125 = NULL ;
return V_91 ;
}
static void
F_92 ( struct V_106 * V_102 )
{
struct V_15 * V_3 =
F_7 ( V_102 , struct V_15 , V_102 ) ;
struct V_22 * V_23 = V_3 -> V_23 ;
unsigned long V_51 ;
F_35 ( & V_146 , V_51 ) ;
F_32 ( & V_3 -> V_144 ) ;
F_38 ( & V_146 , V_51 ) ;
F_33 ( V_3 ) ;
V_3 -> V_70 -> V_129 ( & V_3 -> V_18 ) ;
F_83 ( & V_136 ,
V_3 -> V_18 . V_94 ) ;
F_93 ( & V_3 -> V_114 ) ;
F_31 ( V_3 ) ;
F_91 ( V_23 ) ;
}
static void
F_85 ( struct V_15 * V_3 )
{
F_66 ( & V_3 -> V_102 , F_92 ) ;
}
static int
F_81 ( struct V_15 * V_3 )
{
return F_68 ( & V_3 -> V_102 ) ;
}
static void
F_94 ( struct V_15 * V_3 )
{
struct V_9 * V_10 , * V_148 ;
unsigned long V_51 ;
F_35 ( & V_3 -> V_52 , V_51 ) ;
F_73 (assoc, next,
&tgtport->assoc_list, a_list) {
if ( ! F_57 ( V_10 ) )
continue;
F_38 ( & V_3 -> V_52 , V_51 ) ;
F_86 ( V_10 ) ;
F_64 ( V_10 ) ;
F_35 ( & V_3 -> V_52 , V_51 ) ;
}
F_38 ( & V_3 -> V_52 , V_51 ) ;
}
static void
F_95 ( struct V_149 * V_150 )
{
struct V_15 * V_3 , * V_148 ;
struct V_9 * V_10 ;
struct V_54 * V_7 ;
unsigned long V_51 ;
bool V_151 = false ;
F_35 ( & V_146 , V_51 ) ;
F_73 (tgtport, next, &nvmet_fc_target_list,
tgt_list) {
if ( ! F_81 ( V_3 ) )
continue;
F_38 ( & V_146 , V_51 ) ;
F_35 ( & V_3 -> V_52 , V_51 ) ;
F_77 (assoc, &tgtport->assoc_list, a_list) {
V_7 = V_10 -> V_105 [ 0 ] ;
if ( V_7 && V_7 -> V_103 . V_150 == V_150 ) {
if ( F_57 ( V_10 ) )
V_151 = true ;
break;
}
}
F_38 ( & V_3 -> V_52 , V_51 ) ;
F_85 ( V_3 ) ;
if ( V_151 ) {
F_86 ( V_10 ) ;
F_64 ( V_10 ) ;
return;
}
F_35 ( & V_146 , V_51 ) ;
}
F_38 ( & V_146 , V_51 ) ;
}
int
F_96 ( struct V_16 * V_152 )
{
struct V_15 * V_3 = F_6 ( V_152 ) ;
F_94 ( V_3 ) ;
F_85 ( V_3 ) ;
return 0 ;
}
static void
F_97 ( void * V_153 , T_5 V_154 , T_6 V_155 , T_5 V_156 )
{
struct V_157 * V_158 = V_153 ;
V_158 -> V_159 . V_154 = V_154 ;
V_158 -> V_160 = V_155 ;
V_158 -> V_161 . V_162 = F_98 ( V_163 ) ;
V_158 -> V_161 . V_155 =
F_99 ( sizeof( struct V_164 ) ) ;
V_158 -> V_161 . V_159 . V_154 = V_156 ;
}
static int
F_100 ( void * V_153 , T_2 V_165 , T_5 V_154 ,
T_5 V_166 , T_5 V_167 , T_5 V_168 )
{
struct V_169 * V_170 = V_153 ;
F_97 ( V_153 , V_163 ,
F_99 ( sizeof( struct V_169 ) ) ,
V_154 ) ;
V_170 -> V_170 . V_162 = F_98 ( V_171 ) ;
V_170 -> V_170 . V_155 = F_99 ( sizeof( struct V_172 ) ) ;
V_170 -> V_170 . V_173 = V_166 ;
V_170 -> V_170 . V_174 = V_167 ;
V_170 -> V_170 . V_168 = V_168 ;
return sizeof( struct V_169 ) ;
}
static void
F_101 ( struct V_15 * V_3 ,
struct V_1 * V_4 )
{
struct V_175 * V_161 =
(struct V_175 * ) V_4 -> V_44 ;
struct V_176 * V_158 =
(struct V_176 * ) V_4 -> V_47 ;
struct V_54 * V_7 ;
int V_91 = 0 ;
memset ( V_158 , 0 , sizeof( * V_158 ) ) ;
if ( V_4 -> V_177 < V_178 )
V_91 = V_179 ;
else if ( F_102 ( V_161 -> V_160 ) <
V_180 )
V_91 = V_181 ;
else if ( V_161 -> V_182 . V_162 !=
F_98 ( V_183 ) )
V_91 = V_184 ;
else if ( F_102 ( V_161 -> V_182 . V_155 ) <
V_185 )
V_91 = V_186 ;
else if ( ! V_161 -> V_182 . V_187 ||
( F_103 ( V_161 -> V_182 . V_187 ) >=
F_103 ( V_161 -> V_182 . V_55 ) ) )
V_91 = V_188 ;
else {
V_4 -> V_10 = F_79 ( V_3 ) ;
if ( ! V_4 -> V_10 )
V_91 = V_189 ;
else {
V_7 = F_55 ( V_4 -> V_10 , 0 ,
F_103 ( V_161 -> V_182 . V_55 ) ) ;
if ( ! V_7 )
V_91 = V_190 ;
}
}
if ( V_91 ) {
F_104 ( V_3 -> V_23 ,
L_2 ,
V_191 [ V_91 ] ) ;
V_4 -> V_192 -> V_86 = F_100 ( V_158 ,
V_45 , V_161 -> V_159 . V_154 ,
V_193 ,
V_194 , 0 ) ;
return;
}
V_7 -> V_187 = F_103 ( V_161 -> V_182 . V_187 ) ;
F_60 ( & V_7 -> V_98 , 1 ) ;
V_7 -> V_195 = 0 ;
V_4 -> V_192 -> V_86 = sizeof( * V_158 ) ;
F_97 ( V_158 , V_196 ,
F_99 (
sizeof( struct V_176 ) ) ,
V_197 ) ;
V_158 -> V_198 . V_162 = F_98 ( V_199 ) ;
V_158 -> V_198 . V_155 =
F_99 (
sizeof( struct V_200 ) ) ;
V_158 -> V_198 . V_12 =
F_105 ( F_3 ( V_4 -> V_10 , 0 ) ) ;
V_158 -> V_201 . V_162 = F_98 ( V_202 ) ;
V_158 -> V_201 . V_155 =
F_99 (
sizeof( struct V_203 ) ) ;
V_158 -> V_201 . V_110 = V_158 -> V_198 . V_12 ;
}
static void
F_106 ( struct V_15 * V_3 ,
struct V_1 * V_4 )
{
struct V_204 * V_161 =
(struct V_204 * ) V_4 -> V_44 ;
struct V_205 * V_158 =
(struct V_205 * ) V_4 -> V_47 ;
struct V_54 * V_7 ;
int V_91 = 0 ;
memset ( V_158 , 0 , sizeof( * V_158 ) ) ;
if ( V_4 -> V_177 < sizeof( struct V_204 ) )
V_91 = V_206 ;
else if ( V_161 -> V_160 !=
F_99 (
sizeof( struct V_204 ) ) )
V_91 = V_207 ;
else if ( V_161 -> V_198 . V_162 != F_98 ( V_199 ) )
V_91 = V_208 ;
else if ( V_161 -> V_198 . V_155 !=
F_99 (
sizeof( struct V_200 ) ) )
V_91 = V_209 ;
else if ( V_161 -> V_210 . V_162 !=
F_98 ( V_211 ) )
V_91 = V_212 ;
else if ( V_161 -> V_210 . V_155 !=
F_99 (
sizeof( struct V_213 ) ) )
V_91 = V_214 ;
else if ( ! V_161 -> V_210 . V_187 ||
( F_103 ( V_161 -> V_210 . V_187 ) >=
F_103 ( V_161 -> V_210 . V_55 ) ) )
V_91 = V_188 ;
else {
V_4 -> V_10 = F_87 ( V_3 ,
F_107 ( V_161 -> V_198 . V_12 ) ) ;
if ( ! V_4 -> V_10 )
V_91 = V_215 ;
else {
V_7 = F_55 ( V_4 -> V_10 ,
F_103 ( V_161 -> V_210 . V_11 ) ,
F_103 ( V_161 -> V_210 . V_55 ) ) ;
if ( ! V_7 )
V_91 = V_190 ;
F_64 ( V_4 -> V_10 ) ;
}
}
if ( V_91 ) {
F_104 ( V_3 -> V_23 ,
L_3 ,
V_191 [ V_91 ] ) ;
V_4 -> V_192 -> V_86 = F_100 ( V_158 ,
V_45 , V_161 -> V_159 . V_154 ,
( V_91 == V_215 ) ?
V_216 :
V_193 ,
V_194 , 0 ) ;
return;
}
V_7 -> V_187 = F_103 ( V_161 -> V_210 . V_187 ) ;
F_60 ( & V_7 -> V_98 , 1 ) ;
V_7 -> V_195 = 0 ;
V_4 -> V_192 -> V_86 = sizeof( * V_158 ) ;
F_97 ( V_158 , V_196 ,
F_99 ( sizeof( struct V_205 ) ) ,
V_217 ) ;
V_158 -> V_201 . V_162 = F_98 ( V_202 ) ;
V_158 -> V_201 . V_155 =
F_99 (
sizeof( struct V_203 ) ) ;
V_158 -> V_201 . V_110 =
F_105 ( F_3 ( V_4 -> V_10 ,
F_103 ( V_161 -> V_210 . V_11 ) ) ) ;
}
static void
F_108 ( struct V_15 * V_3 ,
struct V_1 * V_4 )
{
struct V_218 * V_161 =
(struct V_218 * ) V_4 -> V_44 ;
struct V_219 * V_158 =
(struct V_219 * ) V_4 -> V_47 ;
struct V_54 * V_7 = NULL ;
struct V_9 * V_10 ;
int V_91 = 0 ;
bool V_220 = false ;
memset ( V_158 , 0 , sizeof( * V_158 ) ) ;
if ( V_4 -> V_177 < sizeof( struct V_218 ) )
V_91 = V_221 ;
else if ( V_161 -> V_160 !=
F_99 (
sizeof( struct V_218 ) ) )
V_91 = V_222 ;
else if ( V_161 -> V_198 . V_162 != F_98 ( V_199 ) )
V_91 = V_208 ;
else if ( V_161 -> V_198 . V_155 !=
F_99 (
sizeof( struct V_200 ) ) )
V_91 = V_209 ;
else if ( V_161 -> V_223 . V_162 !=
F_98 ( V_224 ) )
V_91 = V_225 ;
else if ( V_161 -> V_223 . V_155 !=
F_99 (
sizeof( struct V_226 ) ) )
V_91 = V_227 ;
else if ( ( V_161 -> V_223 . V_228 != V_229 ) &&
( V_161 -> V_223 . V_228 != V_230 ) )
V_91 = V_231 ;
else {
V_10 = F_87 ( V_3 ,
F_107 ( V_161 -> V_198 . V_12 ) ) ;
V_4 -> V_10 = V_10 ;
if ( V_10 ) {
if ( V_161 -> V_223 . V_228 ==
V_230 ) {
V_7 = F_76 ( V_3 ,
F_107 (
V_161 -> V_223 . V_232 ) ) ;
if ( ! V_7 ) {
F_64 ( V_10 ) ;
V_91 = V_233 ;
}
}
} else
V_91 = V_215 ;
}
if ( V_91 ) {
F_104 ( V_3 -> V_23 ,
L_4 ,
V_191 [ V_91 ] ) ;
V_4 -> V_192 -> V_86 = F_100 ( V_158 ,
V_45 , V_161 -> V_159 . V_154 ,
( V_91 == V_215 ) ?
V_216 :
( V_91 == V_233 ) ?
V_234 :
V_193 ,
V_194 , 0 ) ;
return;
}
V_4 -> V_192 -> V_86 = sizeof( * V_158 ) ;
F_97 ( V_158 , V_196 ,
F_99 (
sizeof( struct V_219 ) ) ,
V_235 ) ;
if ( V_7 ) {
int V_11 = V_7 -> V_11 ;
F_69 ( V_7 ) ;
F_50 ( V_7 ) ;
if ( ! V_11 )
V_220 = true ;
}
F_64 ( V_4 -> V_10 ) ;
if ( V_220 )
F_86 ( V_4 -> V_10 ) ;
}
static void
F_109 ( struct V_236 * V_192 )
{
struct V_1 * V_4 = V_192 -> V_68 ;
struct V_15 * V_3 = V_4 -> V_3 ;
F_15 ( V_3 -> V_23 , V_4 -> V_48 ,
V_45 , V_49 ) ;
F_39 ( V_3 , V_4 ) ;
F_85 ( V_3 ) ;
}
static void
F_110 ( struct V_15 * V_3 ,
struct V_1 * V_4 )
{
int V_91 ;
F_17 ( V_3 -> V_23 , V_4 -> V_48 ,
V_45 , V_49 ) ;
V_91 = V_3 -> V_70 -> V_127 ( & V_3 -> V_18 , V_4 -> V_192 ) ;
if ( V_91 )
F_109 ( V_4 -> V_192 ) ;
}
static void
F_111 ( struct V_15 * V_3 ,
struct V_1 * V_4 )
{
struct V_237 * V_159 =
(struct V_237 * ) V_4 -> V_44 ;
V_4 -> V_192 -> V_68 = V_4 ;
V_4 -> V_192 -> V_47 = V_4 -> V_47 ;
V_4 -> V_192 -> V_48 = V_4 -> V_48 ;
V_4 -> V_192 -> V_238 = F_109 ;
V_4 -> V_192 -> V_86 = 0 ;
V_4 -> V_10 = NULL ;
switch ( V_159 -> V_154 ) {
case V_197 :
F_101 ( V_3 , V_4 ) ;
break;
case V_217 :
F_106 ( V_3 , V_4 ) ;
break;
case V_235 :
F_108 ( V_3 , V_4 ) ;
break;
default:
V_4 -> V_192 -> V_86 = F_100 ( V_4 -> V_47 ,
V_45 , V_159 -> V_154 ,
V_239 , V_194 , 0 ) ;
}
F_110 ( V_3 , V_4 ) ;
}
static void
V_42 ( struct V_240 * V_41 )
{
struct V_1 * V_4 =
F_7 ( V_41 , struct V_1 , V_41 ) ;
struct V_15 * V_3 = V_4 -> V_3 ;
F_111 ( V_3 , V_4 ) ;
}
int
F_112 ( struct V_16 * V_152 ,
struct V_236 * V_192 ,
void * V_241 , T_7 V_242 )
{
struct V_15 * V_3 = F_6 ( V_152 ) ;
struct V_1 * V_4 ;
if ( V_242 > V_45 )
return - V_243 ;
if ( ! F_81 ( V_3 ) )
return - V_244 ;
V_4 = F_34 ( V_3 ) ;
if ( ! V_4 ) {
F_85 ( V_3 ) ;
return - V_245 ;
}
V_4 -> V_192 = V_192 ;
V_4 -> V_61 = NULL ;
memcpy ( V_4 -> V_44 , V_241 , V_242 ) ;
V_4 -> V_177 = V_242 ;
F_113 ( & V_4 -> V_41 ) ;
return 0 ;
}
static int
F_114 ( struct V_5 * V_8 )
{
struct V_30 * V_31 ;
struct V_246 * V_246 ;
unsigned int V_247 ;
T_7 V_248 , V_35 ;
int V_34 = 0 ;
V_35 = V_8 -> V_249 ;
V_247 = F_115 ( V_35 , V_250 ) ;
V_31 = F_116 ( V_247 , sizeof( struct V_30 ) , V_39 ) ;
if ( ! V_31 )
goto V_251;
F_117 ( V_31 , V_247 ) ;
while ( V_35 ) {
V_248 = F_118 ( T_7 , V_35 , V_250 ) ;
V_246 = F_119 ( V_39 ) ;
if ( ! V_246 )
goto V_252;
F_120 ( & V_31 [ V_34 ] , V_246 , V_248 , 0 ) ;
V_35 -= V_248 ;
V_34 ++ ;
}
V_8 -> V_253 = V_31 ;
V_8 -> V_254 = V_247 ;
V_8 -> V_254 = F_23 ( V_8 -> V_3 -> V_23 , V_31 , V_247 ,
( ( V_8 -> V_255 == V_256 ) ?
V_257 : V_49 ) ) ;
return 0 ;
V_252:
while ( V_34 > 0 ) {
V_34 -- ;
F_121 ( F_122 ( & V_31 [ V_34 ] ) ) ;
}
F_31 ( V_31 ) ;
V_8 -> V_253 = NULL ;
V_8 -> V_254 = 0 ;
V_251:
return V_258 ;
}
static void
F_123 ( struct V_5 * V_8 )
{
struct V_30 * V_31 ;
int V_259 ;
if ( ! V_8 -> V_253 || ! V_8 -> V_254 )
return;
F_25 ( V_8 -> V_3 -> V_23 , V_8 -> V_253 , V_8 -> V_254 ,
( ( V_8 -> V_255 == V_256 ) ?
V_257 : V_49 ) ) ;
F_21 (fod->data_sg, sg, fod->data_sg_cnt, count)
F_121 ( F_122 ( V_31 ) ) ;
F_31 ( V_8 -> V_253 ) ;
V_8 -> V_253 = NULL ;
V_8 -> V_254 = 0 ;
}
static bool
F_124 ( struct V_54 * V_260 , T_7 V_195 )
{
T_7 V_99 , V_261 ;
V_99 = F_78 ( & V_260 -> V_99 ) % V_260 -> V_55 ;
V_261 = ( V_99 < V_195 ) ? ( V_99 + V_260 -> V_55 - V_195 ) : ( V_99 - V_195 ) ;
return ( ( V_261 * 10 ) >= ( ( ( T_7 ) ( V_260 -> V_55 - 1 ) * 9 ) ) ) ;
}
static void
F_125 ( struct V_15 * V_3 ,
struct V_5 * V_8 )
{
struct V_262 * V_263 = & V_8 -> V_65 ;
struct V_264 * V_265 = & V_8 -> V_84 . V_265 . V_266 ;
struct V_267 * V_268 = & V_263 -> V_268 ;
T_7 * V_269 = ( T_7 * ) V_268 ;
bool V_270 = false ;
T_7 V_100 , V_271 , V_272 ;
if ( V_8 -> V_61 -> V_273 == V_274 )
V_272 = V_8 -> V_249 ;
else
V_272 = V_8 -> V_275 ;
V_271 = F_126 ( & V_8 -> V_7 -> V_101 ) ;
if ( ! ( V_271 % V_8 -> V_7 -> V_187 ) ||
V_265 -> V_276 == V_277 ||
V_272 != V_8 -> V_249 ||
( F_127 ( V_268 -> V_278 ) & 0xFFFE ) || V_269 [ 0 ] || V_269 [ 1 ] ||
( V_265 -> V_51 & ( V_279 | V_280 ) ) ||
F_124 ( V_8 -> V_7 , F_127 ( V_268 -> V_281 ) ) )
V_270 = true ;
V_8 -> V_61 -> V_85 = V_263 ;
V_8 -> V_61 -> V_48 = V_8 -> V_48 ;
if ( ! V_270 ) {
memset ( V_263 , 0 , V_282 ) ;
V_8 -> V_61 -> V_86 = V_282 ;
} else {
V_263 -> V_283 = F_128 ( sizeof( * V_263 ) / sizeof( T_7 ) ) ;
V_100 = F_126 ( & V_8 -> V_7 -> V_100 ) ;
V_263 -> V_100 = F_98 ( V_100 ) ;
V_263 -> V_284 = F_98 ( V_272 ) ;
V_8 -> V_61 -> V_86 = sizeof( * V_263 ) ;
}
F_17 ( V_3 -> V_23 , V_8 -> V_48 ,
sizeof( V_8 -> V_65 ) , V_49 ) ;
}
static void
F_129 ( struct V_15 * V_3 ,
struct V_5 * V_8 )
{
struct V_67 * V_61 = V_8 -> V_61 ;
F_123 ( V_8 ) ;
if ( ! V_8 -> V_60 )
V_3 -> V_70 -> V_109 ( & V_3 -> V_18 , V_61 ) ;
F_49 ( V_8 -> V_7 , V_8 ) ;
}
static void
F_130 ( struct V_15 * V_3 ,
struct V_5 * V_8 )
{
int V_91 ;
V_8 -> V_61 -> V_273 = V_285 ;
V_8 -> V_61 -> V_286 = 0 ;
F_125 ( V_3 , V_8 ) ;
V_91 = V_3 -> V_70 -> V_128 ( & V_3 -> V_18 , V_8 -> V_61 ) ;
if ( V_91 )
F_129 ( V_3 , V_8 ) ;
}
static void
F_131 ( struct V_15 * V_3 ,
struct V_5 * V_8 , T_5 V_273 )
{
struct V_67 * V_61 = V_8 -> V_61 ;
struct V_30 * V_31 , * V_287 ;
unsigned long V_51 ;
T_7 V_288 , V_289 ;
int V_91 ;
V_61 -> V_273 = V_273 ;
V_61 -> V_275 = V_8 -> V_275 ;
V_61 -> V_286 = V_290 ;
V_288 = F_118 ( T_7 , ( V_291 * 1024 ) ,
( V_8 -> V_249 - V_8 -> V_275 ) ) ;
V_288 = F_118 ( T_7 , V_288 , V_292 * V_250 ) ;
V_288 = F_118 ( T_7 , V_288 , V_8 -> V_3 -> V_70 -> V_130
* V_250 ) ;
V_61 -> V_293 = V_288 ;
V_61 -> V_294 = 0 ;
V_61 -> V_295 = 0 ;
V_61 -> V_86 = 0 ;
V_61 -> V_296 = 0 ;
V_287 = V_8 -> V_297 ;
V_289 = V_8 -> V_298 ;
for ( V_31 = V_61 -> V_31 ; V_288 ; V_31 ++ ) {
* V_31 = * V_287 ;
if ( V_289 ) {
V_31 -> V_275 += V_289 ;
V_31 -> V_35 -= V_289 ;
V_31 -> V_36 += V_289 ;
V_289 = 0 ;
}
if ( V_288 < V_31 -> V_35 ) {
V_31 -> V_35 = V_288 ;
V_8 -> V_297 = V_287 ;
V_8 -> V_298 += V_288 ;
} else if ( V_288 == V_31 -> V_35 ) {
V_8 -> V_298 = 0 ;
V_8 -> V_297 = F_132 ( V_287 ) ;
} else {
V_8 -> V_298 = 0 ;
V_287 = F_132 ( V_287 ) ;
}
V_288 -= V_31 -> V_35 ;
V_61 -> V_296 ++ ;
}
if ( ( V_273 == V_299 ) &&
( ( V_8 -> V_275 + V_61 -> V_293 ) == V_8 -> V_249 ) &&
( V_3 -> V_70 -> V_72 & V_300 ) ) {
V_61 -> V_273 = V_274 ;
F_125 ( V_3 , V_8 ) ;
}
V_91 = V_3 -> V_70 -> V_128 ( & V_3 -> V_18 , V_8 -> V_61 ) ;
if ( V_91 ) {
V_8 -> abort = true ;
if ( V_273 == V_301 ) {
F_35 ( & V_8 -> V_64 , V_51 ) ;
V_8 -> V_78 = false ;
F_38 ( & V_8 -> V_64 , V_51 ) ;
F_133 ( & V_8 -> V_21 ,
V_302 ) ;
} else {
V_61 -> V_295 = V_91 ;
V_61 -> V_294 = 0 ;
F_134 ( V_8 -> V_61 ) ;
}
}
}
static inline bool
F_135 ( struct V_5 * V_8 , bool abort )
{
struct V_67 * V_61 = V_8 -> V_61 ;
struct V_15 * V_3 = V_8 -> V_3 ;
if ( abort ) {
if ( V_61 -> V_273 == V_301 ) {
F_133 ( & V_8 -> V_21 ,
V_302 ) ;
return true ;
}
F_129 ( V_3 , V_8 ) ;
return true ;
}
return false ;
}
static void
F_136 ( struct V_5 * V_8 )
{
struct V_67 * V_61 = V_8 -> V_61 ;
struct V_15 * V_3 = V_8 -> V_3 ;
unsigned long V_51 ;
bool abort ;
F_35 ( & V_8 -> V_64 , V_51 ) ;
abort = V_8 -> abort ;
V_8 -> V_78 = false ;
F_38 ( & V_8 -> V_64 , V_51 ) ;
switch ( V_61 -> V_273 ) {
case V_301 :
if ( F_135 ( V_8 , abort ) )
return;
if ( V_61 -> V_295 ||
V_61 -> V_294 != V_61 -> V_293 ) {
F_71 ( & V_8 -> V_64 ) ;
V_8 -> abort = true ;
F_72 ( & V_8 -> V_64 ) ;
F_133 ( & V_8 -> V_21 ,
V_302 ) ;
return;
}
V_8 -> V_275 += V_61 -> V_294 ;
if ( V_8 -> V_275 != V_8 -> V_249 ) {
F_35 ( & V_8 -> V_64 , V_51 ) ;
V_8 -> V_78 = true ;
F_38 ( & V_8 -> V_64 , V_51 ) ;
F_131 ( V_3 , V_8 ,
V_301 ) ;
return;
}
V_8 -> V_21 . V_303 ( & V_8 -> V_21 ) ;
break;
case V_299 :
case V_274 :
if ( F_135 ( V_8 , abort ) )
return;
if ( V_61 -> V_295 ||
V_61 -> V_294 != V_61 -> V_293 ) {
F_129 ( V_3 , V_8 ) ;
return;
}
if ( V_61 -> V_273 == V_274 ) {
F_123 ( V_8 ) ;
F_49 ( V_8 -> V_7 , V_8 ) ;
return;
}
V_8 -> V_275 += V_61 -> V_294 ;
if ( V_8 -> V_275 != V_8 -> V_249 ) {
F_131 ( V_3 , V_8 ,
V_299 ) ;
return;
}
F_123 ( V_8 ) ;
F_130 ( V_3 , V_8 ) ;
break;
case V_285 :
if ( F_135 ( V_8 , abort ) )
return;
F_49 ( V_8 -> V_7 , V_8 ) ;
break;
default:
break;
}
}
static void
V_58 ( struct V_240 * V_41 )
{
struct V_5 * V_8 =
F_7 ( V_41 , struct V_5 , V_57 ) ;
F_136 ( V_8 ) ;
}
static void
F_134 ( struct V_67 * V_61 )
{
struct V_5 * V_8 = V_61 -> V_68 ;
struct V_54 * V_7 = V_8 -> V_7 ;
if ( V_8 -> V_3 -> V_70 -> V_72 & V_304 )
F_47 ( V_7 -> V_74 , V_7 -> V_75 , & V_8 -> V_57 ) ;
else
F_136 ( V_8 ) ;
}
static void
F_137 ( struct V_15 * V_3 ,
struct V_5 * V_8 , int V_278 )
{
struct V_264 * V_265 = & V_8 -> V_84 . V_265 . V_266 ;
struct V_267 * V_268 = & V_8 -> V_65 . V_268 ;
unsigned long V_51 ;
bool abort ;
F_35 ( & V_8 -> V_64 , V_51 ) ;
abort = V_8 -> abort ;
F_38 ( & V_8 -> V_64 , V_51 ) ;
if ( ! V_278 )
V_8 -> V_7 -> V_195 = V_268 -> V_281 ;
if ( abort ) {
F_129 ( V_3 , V_8 ) ;
return;
}
if ( V_278 ) {
memset ( V_268 , 0 , sizeof( * V_268 ) ) ;
V_268 -> V_281 = V_8 -> V_7 -> V_195 ;
V_268 -> V_305 = F_138 ( V_8 -> V_7 -> V_11 ) ;
V_268 -> V_306 = V_265 -> V_306 ;
V_268 -> V_278 = F_138 ( V_278 ) ;
} else {
if ( ( V_8 -> V_255 == V_307 ) && ( V_8 -> V_254 ) ) {
F_131 ( V_3 , V_8 ,
V_299 ) ;
return;
}
}
F_123 ( V_8 ) ;
F_130 ( V_3 , V_8 ) ;
}
static void
F_139 ( struct V_19 * V_20 )
{
struct V_5 * V_8 = F_8 ( V_20 ) ;
struct V_15 * V_3 = V_8 -> V_3 ;
F_137 ( V_3 , V_8 , 0 ) ;
}
static void
F_48 ( struct V_15 * V_3 ,
struct V_5 * V_8 )
{
struct V_308 * V_309 = & V_8 -> V_84 ;
int V_91 ;
V_8 -> V_61 -> V_238 = F_134 ;
V_8 -> V_249 = F_102 ( V_309 -> V_310 ) ;
if ( V_309 -> V_51 & V_311 ) {
V_8 -> V_255 = V_256 ;
if ( ! F_140 ( & V_309 -> V_265 ) )
goto V_312;
} else if ( V_309 -> V_51 & V_313 ) {
V_8 -> V_255 = V_307 ;
if ( F_140 ( & V_309 -> V_265 ) )
goto V_312;
} else {
V_8 -> V_255 = V_314 ;
if ( V_8 -> V_249 )
goto V_312;
}
V_8 -> V_21 . V_315 = & V_8 -> V_84 . V_265 ;
V_8 -> V_21 . V_316 = & V_8 -> V_65 . V_268 ;
V_8 -> V_21 . V_97 = V_8 -> V_7 -> V_97 ;
V_8 -> V_21 . V_303 = NULL ;
memset ( & V_8 -> V_65 , 0 , sizeof( V_8 -> V_65 ) ) ;
V_8 -> V_253 = NULL ;
V_8 -> V_254 = 0 ;
V_91 = F_141 ( & V_8 -> V_21 ,
& V_8 -> V_7 -> V_317 ,
& V_8 -> V_7 -> V_103 ,
& V_318 ) ;
if ( ! V_91 ) {
return;
}
F_142 ( & V_8 -> V_7 -> V_99 ) ;
if ( V_8 -> V_249 ) {
V_91 = F_114 ( V_8 ) ;
if ( V_91 ) {
F_133 ( & V_8 -> V_21 , V_91 ) ;
return;
}
}
V_8 -> V_21 . V_31 = V_8 -> V_253 ;
V_8 -> V_21 . V_296 = V_8 -> V_254 ;
V_8 -> V_275 = 0 ;
V_8 -> V_297 = V_8 -> V_253 ;
V_8 -> V_298 = 0 ;
if ( V_8 -> V_255 == V_256 ) {
F_131 ( V_3 , V_8 , V_301 ) ;
return;
}
V_8 -> V_21 . V_303 ( & V_8 -> V_21 ) ;
return;
V_312:
F_129 ( V_3 , V_8 ) ;
}
static void
V_56 ( struct V_240 * V_41 )
{
struct V_5 * V_8 =
F_7 ( V_41 , struct V_5 , V_41 ) ;
struct V_15 * V_3 = V_8 -> V_3 ;
F_48 ( V_3 , V_8 ) ;
}
int
F_143 ( struct V_16 * V_152 ,
struct V_67 * V_61 ,
void * V_84 , T_7 V_319 )
{
struct V_15 * V_3 = F_6 ( V_152 ) ;
struct V_308 * V_309 = V_84 ;
struct V_54 * V_7 ;
struct V_5 * V_8 ;
struct V_76 * V_77 ;
unsigned long V_51 ;
if ( ( V_319 != sizeof( * V_309 ) ) ||
( V_309 -> V_320 != V_321 ) ||
( V_309 -> V_322 != V_323 ) ||
( F_103 ( V_309 -> V_283 ) != ( sizeof( * V_309 ) / 4 ) ) )
return - V_324 ;
V_7 = F_76 ( V_3 ,
F_107 ( V_309 -> V_110 ) ) ;
if ( ! V_7 )
return - V_325 ;
F_35 ( & V_7 -> V_66 , V_51 ) ;
V_8 = F_44 ( V_7 ) ;
if ( V_8 ) {
F_38 ( & V_7 -> V_66 , V_51 ) ;
V_61 -> V_68 = V_8 ;
V_8 -> V_61 = V_61 ;
memcpy ( & V_8 -> V_84 , V_84 , V_319 ) ;
F_46 ( V_3 , V_7 , V_61 ) ;
return 0 ;
}
if ( ! V_3 -> V_70 -> V_87 ) {
F_38 ( & V_7 -> V_66 , V_51 ) ;
F_50 ( V_7 ) ;
return - V_245 ;
}
V_77 = F_36 ( & V_7 -> V_83 ,
struct V_76 , V_81 ) ;
if ( V_77 ) {
F_32 ( & V_77 -> V_81 ) ;
} else {
F_38 ( & V_7 -> V_66 , V_51 ) ;
V_77 = F_144 ( sizeof( * V_77 ) , V_39 ) ;
if ( ! V_77 ) {
F_50 ( V_7 ) ;
return - V_40 ;
}
F_35 ( & V_7 -> V_66 , V_51 ) ;
}
V_61 -> V_85 = V_84 ;
V_61 -> V_86 = V_319 ;
V_77 -> V_82 = V_61 ;
F_30 ( & V_77 -> V_81 , & V_7 -> V_80 ) ;
F_38 ( & V_7 -> V_66 , V_51 ) ;
return - V_326 ;
}
void
F_145 ( struct V_16 * V_152 ,
struct V_67 * V_61 )
{
struct V_5 * V_8 = V_61 -> V_68 ;
struct V_54 * V_7 ;
unsigned long V_51 ;
if ( ! V_8 || V_8 -> V_61 != V_61 )
return;
V_7 = V_8 -> V_7 ;
F_35 ( & V_7 -> V_66 , V_51 ) ;
if ( V_8 -> V_59 ) {
F_71 ( & V_8 -> V_64 ) ;
V_8 -> abort = true ;
V_8 -> V_60 = true ;
F_72 ( & V_8 -> V_64 ) ;
}
F_38 ( & V_7 -> V_66 , V_51 ) ;
}
static int
F_146 ( T_8 * V_327 , T_1 * V_328 )
{
T_1 V_329 ;
if ( F_147 ( V_327 , & V_329 ) )
return - V_133 ;
* V_328 = V_329 ;
return 0 ;
}
static int
F_148 ( struct V_330 * V_331 , char * V_153 , T_4 V_332 )
{
char V_333 [ 2 + V_334 + 1 ] ;
T_8 V_335 = { V_333 , & V_333 [ sizeof( V_333 ) - 1 ] } ;
int V_336 , V_337 ;
if ( F_149 ( V_153 , V_332 ) == V_338 &&
! strncmp ( V_153 , L_5 , V_339 ) &&
! strncmp ( & V_153 [ V_340 ] ,
L_6 , V_339 ) ) {
V_336 = V_339 ;
V_337 = V_340 +
V_339 ;
} else if ( ( F_149 ( V_153 , V_332 ) == V_341 &&
! strncmp ( V_153 , L_7 , V_342 ) &&
! strncmp ( & V_153 [ V_343 ] ,
L_8 , V_342 ) ) ) {
V_336 = V_342 ;
V_337 = V_343 + V_342 ;
} else
goto V_344;
V_333 [ 0 ] = '0' ;
V_333 [ 1 ] = 'x' ;
V_333 [ 2 + V_334 ] = 0 ;
memcpy ( & V_333 [ 2 ] , & V_153 [ V_336 ] , V_334 ) ;
if ( F_146 ( & V_335 , & V_331 -> V_345 ) )
goto V_344;
memcpy ( & V_333 [ 2 ] , & V_153 [ V_337 ] , V_334 ) ;
if ( F_146 ( & V_335 , & V_331 -> V_346 ) )
goto V_344;
return 0 ;
V_344:
F_150 ( L_9 , V_347 ) ;
return - V_133 ;
}
static int
F_151 ( struct V_348 * V_97 )
{
struct V_15 * V_3 ;
struct V_330 V_331 = { 0L , 0L } ;
unsigned long V_51 ;
int V_91 ;
if ( ( V_97 -> V_349 . V_350 != V_351 ) ||
( V_97 -> V_349 . V_352 != V_353 ) )
return - V_133 ;
V_91 = F_148 ( & V_331 , V_97 -> V_349 . V_331 ,
sizeof( V_97 -> V_349 . V_331 ) ) ;
if ( V_91 )
return V_91 ;
V_91 = - V_354 ;
F_35 ( & V_146 , V_51 ) ;
F_77 (tgtport, &nvmet_fc_target_list, tgt_list) {
if ( ( V_3 -> V_18 . V_140 == V_331 . V_345 ) &&
( V_3 -> V_18 . V_141 == V_331 . V_346 ) ) {
if ( ! V_3 -> V_97 ) {
V_3 -> V_97 = V_97 ;
V_97 -> V_355 = V_3 ;
F_81 ( V_3 ) ;
V_91 = 0 ;
} else
V_91 = - V_356 ;
break;
}
}
F_38 ( & V_146 , V_51 ) ;
return V_91 ;
}
static void
F_152 ( struct V_348 * V_97 )
{
struct V_15 * V_3 = V_97 -> V_355 ;
unsigned long V_51 ;
F_35 ( & V_146 , V_51 ) ;
if ( V_3 -> V_97 == V_97 ) {
F_85 ( V_3 ) ;
V_3 -> V_97 = NULL ;
}
F_38 ( & V_146 , V_51 ) ;
}
static int T_9 F_153 ( void )
{
return F_154 ( & V_318 ) ;
}
static void T_10 F_155 ( void )
{
if ( ! F_156 ( & V_147 ) )
F_150 ( L_10 , V_347 ) ;
F_157 ( & V_318 ) ;
F_93 ( & V_136 ) ;
}
