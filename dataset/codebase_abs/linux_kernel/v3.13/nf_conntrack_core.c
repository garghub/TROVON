static T_1 F_1 ( const struct V_1 * V_2 , T_2 V_3 )
{
unsigned int V_4 ;
V_4 = ( sizeof( V_2 -> V_5 ) + sizeof( V_2 -> V_6 . V_7 ) ) / sizeof( T_1 ) ;
return F_2 ( ( T_1 * ) V_2 , V_4 , V_3 ^ V_8 ^
( ( ( V_9 V_10 ) V_2 -> V_6 . V_11 . V_12 << 16 ) |
V_2 -> V_6 . V_13 ) ) ;
}
static T_1 F_3 ( T_1 V_14 , unsigned int V_15 )
{
return ( ( V_16 ) V_14 * V_15 ) >> 32 ;
}
static T_1 F_4 ( T_1 V_14 , const struct V_17 * V_17 )
{
return F_3 ( V_14 , V_17 -> V_18 . V_19 ) ;
}
static T_3 F_5 ( const struct V_1 * V_2 ,
T_2 V_3 , unsigned int V_15 )
{
return F_3 ( F_1 ( V_2 , V_3 ) , V_15 ) ;
}
static inline T_3 F_6 ( const struct V_17 * V_17 , T_2 V_3 ,
const struct V_1 * V_2 )
{
return F_5 ( V_2 , V_3 , V_17 -> V_18 . V_19 ) ;
}
bool
F_7 ( const struct V_20 * V_21 ,
unsigned int V_22 ,
unsigned int V_23 ,
T_4 V_24 ,
T_5 V_13 ,
struct V_1 * V_2 ,
const struct V_25 * V_26 ,
const struct V_27 * V_28 )
{
memset ( V_2 , 0 , sizeof( * V_2 ) ) ;
V_2 -> V_5 . V_24 = V_24 ;
if ( V_26 -> V_29 ( V_21 , V_22 , V_2 ) == 0 )
return false ;
V_2 -> V_6 . V_13 = V_13 ;
V_2 -> V_6 . V_30 = V_31 ;
return V_28 -> V_29 ( V_21 , V_23 , V_2 ) ;
}
bool F_8 ( const struct V_20 * V_21 , unsigned int V_22 ,
T_4 V_24 , struct V_1 * V_2 )
{
struct V_25 * V_26 ;
struct V_27 * V_28 ;
unsigned int V_32 ;
T_5 V_13 ;
int V_33 ;
F_9 () ;
V_26 = F_10 ( V_24 ) ;
V_33 = V_26 -> V_34 ( V_21 , V_22 , & V_32 , & V_13 ) ;
if ( V_33 != V_35 ) {
F_11 () ;
return false ;
}
V_28 = F_12 ( V_24 , V_13 ) ;
V_33 = F_7 ( V_21 , V_22 , V_32 , V_24 , V_13 , V_2 ,
V_26 , V_28 ) ;
F_11 () ;
return V_33 ;
}
bool
F_13 ( struct V_1 * V_36 ,
const struct V_1 * V_37 ,
const struct V_25 * V_26 ,
const struct V_27 * V_28 )
{
memset ( V_36 , 0 , sizeof( * V_36 ) ) ;
V_36 -> V_5 . V_24 = V_37 -> V_5 . V_24 ;
if ( V_26 -> V_38 ( V_36 , V_37 ) == 0 )
return false ;
V_36 -> V_6 . V_30 = ! V_37 -> V_6 . V_30 ;
V_36 -> V_6 . V_13 = V_37 -> V_6 . V_13 ;
return V_28 -> V_38 ( V_36 , V_37 ) ;
}
static void
F_14 ( struct V_39 * V_18 )
{
F_15 ( L_1 , V_18 ) ;
F_16 ( & V_18 -> V_40 [ V_31 ] . V_41 ) ;
F_16 ( & V_18 -> V_40 [ V_42 ] . V_41 ) ;
F_17 ( V_18 ) ;
}
static void
F_18 ( struct V_43 * V_44 )
{
struct V_39 * V_18 = (struct V_39 * ) V_44 ;
struct V_17 * V_17 = F_19 ( V_18 ) ;
struct V_27 * V_28 ;
F_15 ( L_2 , V_18 ) ;
F_20 ( F_21 ( & V_44 -> V_45 ) == 0 ) ;
F_20 ( ! F_22 ( & V_18 -> V_46 ) ) ;
F_9 () ;
V_28 = F_12 ( F_23 ( V_18 ) , F_24 ( V_18 ) ) ;
if ( V_28 && V_28 -> V_47 )
V_28 -> V_47 ( V_18 ) ;
F_11 () ;
F_25 ( & V_48 ) ;
F_17 ( V_18 ) ;
F_26 ( F_27 ( & V_18 -> V_40 [ V_31 ] . V_41 ) ) ;
F_16 ( & V_18 -> V_40 [ V_31 ] . V_41 ) ;
F_28 ( V_17 , V_49 ) ;
F_29 ( & V_48 ) ;
if ( V_18 -> V_50 )
F_30 ( V_18 -> V_50 ) ;
F_15 ( L_3 , V_18 ) ;
F_31 ( V_18 ) ;
}
static void F_32 ( struct V_39 * V_18 )
{
struct V_17 * V_17 = F_19 ( V_18 ) ;
F_33 ( V_18 ) ;
F_25 ( & V_48 ) ;
F_28 ( V_17 , V_51 ) ;
F_14 ( V_18 ) ;
F_34 ( & V_18 -> V_40 [ V_31 ] . V_41 ,
& V_17 -> V_18 . V_52 ) ;
F_29 ( & V_48 ) ;
}
static void F_35 ( unsigned long V_53 )
{
struct V_39 * V_18 = ( void * ) V_53 ;
struct V_17 * V_17 = F_19 ( V_18 ) ;
struct V_54 * V_55 = F_36 ( V_18 ) ;
F_26 ( V_55 == NULL ) ;
if ( F_37 ( V_56 , V_18 ) < 0 ) {
V_55 -> V_46 . V_57 = V_58 +
( F_38 () % V_17 -> V_18 . V_59 ) ;
F_39 ( & V_55 -> V_46 ) ;
return;
}
F_40 ( V_60 , & V_18 -> V_61 ) ;
F_30 ( V_18 ) ;
}
static void F_41 ( struct V_39 * V_18 )
{
struct V_17 * V_17 = F_19 ( V_18 ) ;
struct V_54 * V_55 = F_36 ( V_18 ) ;
F_26 ( V_55 == NULL ) ;
F_42 ( & V_55 -> V_46 , F_35 , ( unsigned long ) V_18 ) ;
V_55 -> V_46 . V_57 = V_58 +
( F_38 () % V_17 -> V_18 . V_59 ) ;
F_39 ( & V_55 -> V_46 ) ;
}
bool F_43 ( struct V_39 * V_18 , T_1 V_62 , int V_63 )
{
struct V_64 * V_65 ;
V_65 = F_44 ( V_18 ) ;
if ( V_65 && V_65 -> V_66 == 0 )
V_65 -> V_66 = F_45 ( F_46 () ) ;
if ( ! F_47 ( V_18 ) &&
F_48 ( F_49 ( V_56 , V_18 ,
V_62 , V_63 ) < 0 ) ) {
F_32 ( V_18 ) ;
F_41 ( V_18 ) ;
return false ;
}
F_40 ( V_60 , & V_18 -> V_61 ) ;
F_32 ( V_18 ) ;
F_30 ( V_18 ) ;
return true ;
}
static void F_50 ( unsigned long V_53 )
{
F_43 ( (struct V_39 * ) V_53 , 0 , 0 ) ;
}
static struct V_67 *
F_51 ( struct V_17 * V_17 , T_2 V_3 ,
const struct V_1 * V_2 , T_1 V_14 )
{
struct V_67 * V_68 ;
struct V_69 * V_4 ;
unsigned int V_70 = F_4 ( V_14 , V_17 ) ;
F_52 () ;
V_71:
F_53 (h, n, &net->ct.hash[bucket], hnnode) {
if ( F_54 ( V_2 , & V_68 -> V_2 ) &&
F_55 ( F_56 ( V_68 ) ) == V_3 ) {
F_28 ( V_17 , V_72 ) ;
F_57 () ;
return V_68 ;
}
F_28 ( V_17 , V_73 ) ;
}
if ( F_58 ( V_4 ) != V_70 ) {
F_28 ( V_17 , V_74 ) ;
goto V_71;
}
F_57 () ;
return NULL ;
}
struct V_67 *
F_59 ( struct V_17 * V_17 , T_2 V_3 ,
const struct V_1 * V_2 )
{
return F_51 ( V_17 , V_3 , V_2 ,
F_1 ( V_2 , V_3 ) ) ;
}
static struct V_67 *
F_60 ( struct V_17 * V_17 , T_2 V_3 ,
const struct V_1 * V_2 , T_1 V_14 )
{
struct V_67 * V_68 ;
struct V_39 * V_18 ;
F_9 () ;
V_71:
V_68 = F_51 ( V_17 , V_3 , V_2 , V_14 ) ;
if ( V_68 ) {
V_18 = F_56 ( V_68 ) ;
if ( F_48 ( F_47 ( V_18 ) ||
! F_61 ( & V_18 -> V_75 . V_45 ) ) )
V_68 = NULL ;
else {
if ( F_48 ( ! F_54 ( V_2 , & V_68 -> V_2 ) ||
F_55 ( V_18 ) != V_3 ) ) {
F_30 ( V_18 ) ;
goto V_71;
}
}
}
F_11 () ;
return V_68 ;
}
struct V_67 *
F_62 ( struct V_17 * V_17 , T_2 V_3 ,
const struct V_1 * V_2 )
{
return F_60 ( V_17 , V_3 , V_2 ,
F_1 ( V_2 , V_3 ) ) ;
}
static void F_63 ( struct V_39 * V_18 ,
unsigned int V_14 ,
unsigned int V_76 )
{
struct V_17 * V_17 = F_19 ( V_18 ) ;
F_64 ( & V_18 -> V_40 [ V_31 ] . V_41 ,
& V_17 -> V_18 . V_14 [ V_14 ] ) ;
F_64 ( & V_18 -> V_40 [ V_42 ] . V_41 ,
& V_17 -> V_18 . V_14 [ V_76 ] ) ;
}
int
F_65 ( struct V_39 * V_18 )
{
struct V_17 * V_17 = F_19 ( V_18 ) ;
unsigned int V_14 , V_76 ;
struct V_67 * V_68 ;
struct V_69 * V_4 ;
T_2 V_3 ;
V_3 = F_55 ( V_18 ) ;
V_14 = F_6 ( V_17 , V_3 ,
& V_18 -> V_40 [ V_31 ] . V_2 ) ;
V_76 = F_6 ( V_17 , V_3 ,
& V_18 -> V_40 [ V_42 ] . V_2 ) ;
F_25 ( & V_48 ) ;
F_66 (h, n, &net->ct.hash[hash], hnnode)
if ( F_54 ( & V_18 -> V_40 [ V_31 ] . V_2 ,
& V_68 -> V_2 ) &&
V_3 == F_55 ( F_56 ( V_68 ) ) )
goto V_77;
F_66 (h, n, &net->ct.hash[repl_hash], hnnode)
if ( F_54 ( & V_18 -> V_40 [ V_42 ] . V_2 ,
& V_68 -> V_2 ) &&
V_3 == F_55 ( F_56 ( V_68 ) ) )
goto V_77;
F_39 ( & V_18 -> V_46 ) ;
F_67 ( & V_18 -> V_75 ) ;
F_63 ( V_18 , V_14 , V_76 ) ;
F_28 ( V_17 , V_78 ) ;
F_29 ( & V_48 ) ;
return 0 ;
V_77:
F_28 ( V_17 , V_79 ) ;
F_29 ( & V_48 ) ;
return - V_80 ;
}
int
F_68 ( struct V_20 * V_21 )
{
unsigned int V_14 , V_76 ;
struct V_67 * V_68 ;
struct V_39 * V_18 ;
struct V_81 * V_82 ;
struct V_64 * V_65 ;
struct V_69 * V_4 ;
enum V_83 V_84 ;
struct V_17 * V_17 ;
T_2 V_3 ;
V_18 = F_69 ( V_21 , & V_84 ) ;
V_17 = F_19 ( V_18 ) ;
if ( F_70 ( V_84 ) != V_31 )
return V_35 ;
V_3 = F_55 ( V_18 ) ;
V_14 = * ( unsigned long * ) & V_18 -> V_40 [ V_42 ] . V_41 . V_85 ;
V_14 = F_4 ( V_14 , V_17 ) ;
V_76 = F_6 ( V_17 , V_3 ,
& V_18 -> V_40 [ V_42 ] . V_2 ) ;
F_20 ( ! F_71 ( V_18 ) ) ;
F_15 ( L_4 , V_18 ) ;
F_25 ( & V_48 ) ;
if ( F_48 ( F_47 ( V_18 ) ) ) {
F_29 ( & V_48 ) ;
return V_35 ;
}
F_66 (h, n, &net->ct.hash[hash], hnnode)
if ( F_54 ( & V_18 -> V_40 [ V_31 ] . V_2 ,
& V_68 -> V_2 ) &&
V_3 == F_55 ( F_56 ( V_68 ) ) )
goto V_77;
F_66 (h, n, &net->ct.hash[repl_hash], hnnode)
if ( F_54 ( & V_18 -> V_40 [ V_42 ] . V_2 ,
& V_68 -> V_2 ) &&
V_3 == F_55 ( F_56 ( V_68 ) ) )
goto V_77;
F_16 ( & V_18 -> V_40 [ V_31 ] . V_41 ) ;
V_18 -> V_46 . V_57 += V_58 ;
F_39 ( & V_18 -> V_46 ) ;
F_72 ( & V_18 -> V_75 . V_45 ) ;
V_18 -> V_61 |= V_86 ;
V_65 = F_44 ( V_18 ) ;
if ( V_65 ) {
if ( V_21 -> V_65 . V_87 == 0 )
F_73 ( V_21 ) ;
V_65 -> V_88 = F_45 ( V_21 -> V_65 ) ;
}
F_63 ( V_18 , V_14 , V_76 ) ;
F_28 ( V_17 , V_78 ) ;
F_29 ( & V_48 ) ;
V_82 = F_74 ( V_18 ) ;
if ( V_82 && V_82 -> V_89 )
F_75 ( V_90 , V_18 ) ;
F_75 ( F_76 ( V_18 ) ?
V_91 : V_92 , V_18 ) ;
return V_35 ;
V_77:
F_28 ( V_17 , V_79 ) ;
F_29 ( & V_48 ) ;
return V_93 ;
}
int
F_77 ( const struct V_1 * V_2 ,
const struct V_39 * V_94 )
{
struct V_17 * V_17 = F_19 ( V_94 ) ;
struct V_67 * V_68 ;
struct V_69 * V_4 ;
struct V_39 * V_18 ;
T_2 V_3 = F_55 ( V_94 ) ;
unsigned int V_14 = F_6 ( V_17 , V_3 , V_2 ) ;
F_78 () ;
F_53 (h, n, &net->ct.hash[hash], hnnode) {
V_18 = F_56 ( V_68 ) ;
if ( V_18 != V_94 &&
F_54 ( V_2 , & V_68 -> V_2 ) &&
F_55 ( V_18 ) == V_3 ) {
F_28 ( V_17 , V_72 ) ;
F_79 () ;
return 1 ;
}
F_28 ( V_17 , V_73 ) ;
}
F_79 () ;
return 0 ;
}
static T_6 int F_80 ( struct V_17 * V_17 , unsigned int V_14 )
{
struct V_67 * V_68 ;
struct V_39 * V_18 = NULL , * V_95 ;
struct V_69 * V_4 ;
unsigned int V_96 , V_97 = 0 ;
int V_98 = 0 ;
F_9 () ;
for ( V_96 = 0 ; V_96 < V_17 -> V_18 . V_19 ; V_96 ++ ) {
F_53 (h, n, &net->ct.hash[hash],
hnnode) {
V_95 = F_56 ( V_68 ) ;
if ( ! F_81 ( V_99 , & V_95 -> V_61 ) )
V_18 = V_95 ;
V_97 ++ ;
}
if ( V_18 != NULL ) {
if ( F_82 ( ! F_47 ( V_18 ) &&
F_61 ( & V_18 -> V_75 . V_45 ) ) )
break;
else
V_18 = NULL ;
}
if ( V_97 >= V_100 )
break;
V_14 = ( V_14 + 1 ) % V_17 -> V_18 . V_19 ;
}
F_11 () ;
if ( ! V_18 )
return V_98 ;
if ( F_83 ( & V_18 -> V_46 ) ) {
if ( F_43 ( V_18 , 0 , 0 ) ) {
V_98 = 1 ;
F_84 ( V_17 , F_80 ) ;
}
}
F_30 ( V_18 ) ;
return V_98 ;
}
void F_85 ( void )
{
unsigned int rand ;
do {
F_86 ( & rand , sizeof( rand ) ) ;
} while ( ! rand );
F_87 ( & V_8 , 0 , rand ) ;
}
static struct V_39 *
F_88 ( struct V_17 * V_17 , T_2 V_3 ,
const struct V_1 * V_37 ,
const struct V_1 * V_101 ,
T_7 V_102 , T_1 V_14 )
{
struct V_39 * V_18 ;
if ( F_48 ( ! V_8 ) ) {
F_85 () ;
V_14 = F_1 ( V_37 , V_3 ) ;
}
F_72 ( & V_17 -> V_18 . V_103 ) ;
if ( V_104 &&
F_48 ( F_21 ( & V_17 -> V_18 . V_103 ) > V_104 ) ) {
if ( ! F_80 ( V_17 , F_4 ( V_14 , V_17 ) ) ) {
F_89 ( & V_17 -> V_18 . V_103 ) ;
F_90 ( L_5 ) ;
return F_91 ( - V_105 ) ;
}
}
V_18 = F_92 ( V_17 -> V_18 . V_106 , V_102 ) ;
if ( V_18 == NULL ) {
F_89 ( & V_17 -> V_18 . V_103 ) ;
return F_91 ( - V_105 ) ;
}
memset ( & V_18 -> V_40 [ V_107 ] , 0 ,
F_93 ( struct V_39 , V_108 ) -
F_93 ( struct V_39 , V_40 [ V_107 ] ) ) ;
F_94 ( & V_18 -> V_109 ) ;
V_18 -> V_40 [ V_31 ] . V_2 = * V_37 ;
V_18 -> V_40 [ V_31 ] . V_41 . V_85 = NULL ;
V_18 -> V_40 [ V_42 ] . V_2 = * V_101 ;
* ( unsigned long * ) ( & V_18 -> V_40 [ V_42 ] . V_41 . V_85 ) = V_14 ;
F_42 ( & V_18 -> V_46 , F_50 , ( unsigned long ) V_18 ) ;
F_95 ( & V_18 -> V_110 , V_17 ) ;
#ifdef F_96
if ( V_3 ) {
struct V_111 * F_55 ;
F_55 = F_97 ( V_18 , V_112 , V_113 ) ;
if ( ! F_55 )
goto V_114;
F_55 -> V_115 = V_3 ;
}
#endif
F_98 () ;
F_99 ( & V_18 -> V_75 . V_45 , 1 ) ;
return V_18 ;
#ifdef F_96
V_114:
F_89 ( & V_17 -> V_18 . V_103 ) ;
F_100 ( V_17 -> V_18 . V_106 , V_18 ) ;
return F_91 ( - V_105 ) ;
#endif
}
struct V_39 * F_101 ( struct V_17 * V_17 , T_2 V_3 ,
const struct V_1 * V_37 ,
const struct V_1 * V_101 ,
T_7 V_102 )
{
return F_88 ( V_17 , V_3 , V_37 , V_101 , V_102 , 0 ) ;
}
void F_31 ( struct V_39 * V_18 )
{
struct V_17 * V_17 = F_19 ( V_18 ) ;
F_102 ( V_18 ) ;
F_103 ( V_18 ) ;
F_100 ( V_17 -> V_18 . V_106 , V_18 ) ;
F_104 () ;
F_89 ( & V_17 -> V_18 . V_103 ) ;
}
static struct V_67 *
F_105 ( struct V_17 * V_17 , struct V_39 * V_116 ,
const struct V_1 * V_2 ,
struct V_25 * V_26 ,
struct V_27 * V_28 ,
struct V_20 * V_21 ,
unsigned int V_23 , T_1 V_14 )
{
struct V_39 * V_18 ;
struct V_81 * V_82 ;
struct V_1 V_117 ;
struct V_54 * V_55 ;
struct V_118 * exp ;
T_2 V_3 = V_116 ? F_55 ( V_116 ) : V_119 ;
struct V_120 * V_121 ;
unsigned int * V_122 ;
if ( ! F_13 ( & V_117 , V_2 , V_26 , V_28 ) ) {
F_15 ( L_6 ) ;
return NULL ;
}
V_18 = F_88 ( V_17 , V_3 , V_2 , & V_117 , V_113 ,
V_14 ) ;
if ( F_106 ( V_18 ) )
return (struct V_67 * ) V_18 ;
if ( V_116 && F_107 ( V_116 ) ) {
F_108 ( V_18 ) ;
F_109 ( V_18 ) ;
}
V_121 = V_116 ? F_110 ( V_116 ) : NULL ;
if ( V_121 )
V_122 = F_111 ( V_121 ) ;
else
V_122 = V_28 -> V_123 ( V_17 ) ;
if ( ! V_28 -> V_124 ( V_18 , V_21 , V_23 , V_122 ) ) {
F_31 ( V_18 ) ;
F_15 ( L_7 ) ;
return NULL ;
}
if ( V_121 )
F_112 ( V_18 , V_121 -> V_46 , V_113 ) ;
F_113 ( V_18 , V_113 ) ;
F_114 ( V_18 , V_113 ) ;
F_115 ( V_18 ) ;
V_55 = V_116 ? F_36 ( V_116 ) : NULL ;
F_116 ( V_18 , V_55 ? V_55 -> V_125 : 0 ,
V_55 ? V_55 -> V_126 : 0 ,
V_113 ) ;
F_25 ( & V_48 ) ;
exp = F_117 ( V_17 , V_3 , V_2 ) ;
if ( exp ) {
F_15 ( L_8 ,
V_18 , exp ) ;
F_118 ( V_127 , & V_18 -> V_61 ) ;
V_18 -> V_50 = exp -> V_50 ;
if ( exp -> V_89 ) {
V_82 = F_119 ( V_18 , exp -> V_89 ,
V_113 ) ;
if ( V_82 )
F_120 ( V_82 -> V_89 , exp -> V_89 ) ;
}
#ifdef F_121
V_18 -> V_128 = exp -> V_50 -> V_128 ;
#endif
#ifdef F_122
V_18 -> V_129 = exp -> V_50 -> V_129 ;
#endif
F_67 ( & V_18 -> V_50 -> V_75 ) ;
F_28 ( V_17 , V_130 ) ;
} else {
F_123 ( V_18 , V_116 , V_113 ) ;
F_28 ( V_17 , V_124 ) ;
}
F_64 ( & V_18 -> V_40 [ V_31 ] . V_41 ,
& V_17 -> V_18 . V_131 ) ;
F_29 ( & V_48 ) ;
if ( exp ) {
if ( exp -> V_132 )
exp -> V_132 ( V_18 , exp ) ;
F_124 ( exp ) ;
}
return & V_18 -> V_40 [ V_31 ] ;
}
static inline struct V_39 *
F_125 ( struct V_17 * V_17 , struct V_39 * V_116 ,
struct V_20 * V_21 ,
unsigned int V_23 ,
T_4 V_24 ,
T_5 V_13 ,
struct V_25 * V_26 ,
struct V_27 * V_28 ,
int * V_133 ,
enum V_83 * V_84 )
{
struct V_1 V_2 ;
struct V_67 * V_68 ;
struct V_39 * V_18 ;
T_2 V_3 = V_116 ? F_55 ( V_116 ) : V_119 ;
T_1 V_14 ;
if ( ! F_7 ( V_21 , F_126 ( V_21 ) ,
V_23 , V_24 , V_13 , & V_2 , V_26 ,
V_28 ) ) {
F_15 ( L_9 ) ;
return NULL ;
}
V_14 = F_1 ( & V_2 , V_3 ) ;
V_68 = F_60 ( V_17 , V_3 , & V_2 , V_14 ) ;
if ( ! V_68 ) {
V_68 = F_105 ( V_17 , V_116 , & V_2 , V_26 , V_28 ,
V_21 , V_23 , V_14 ) ;
if ( ! V_68 )
return NULL ;
if ( F_106 ( V_68 ) )
return ( void * ) V_68 ;
}
V_18 = F_56 ( V_68 ) ;
if ( F_127 ( V_68 ) == V_42 ) {
* V_84 = V_134 ;
* V_133 = 1 ;
} else {
if ( F_81 ( V_135 , & V_18 -> V_61 ) ) {
F_15 ( L_10 , V_18 ) ;
* V_84 = V_136 ;
} else if ( F_81 ( V_127 , & V_18 -> V_61 ) ) {
F_15 ( L_11 ,
V_18 ) ;
* V_84 = V_137 ;
} else {
F_15 ( L_12 , V_18 ) ;
* V_84 = V_138 ;
}
* V_133 = 0 ;
}
V_21 -> V_44 = & V_18 -> V_75 ;
V_21 -> V_139 = * V_84 ;
return V_18 ;
}
unsigned int
F_128 ( struct V_17 * V_17 , T_5 V_140 , unsigned int V_141 ,
struct V_20 * V_21 )
{
struct V_39 * V_18 , * V_116 = NULL ;
enum V_83 V_84 ;
struct V_25 * V_26 ;
struct V_27 * V_28 ;
unsigned int * V_122 ;
unsigned int V_23 ;
T_5 V_13 ;
int V_133 = 0 ;
int V_33 ;
if ( V_21 -> V_44 ) {
V_116 = (struct V_39 * ) V_21 -> V_44 ;
if ( ! F_129 ( V_116 ) ) {
F_84 ( V_17 , V_142 ) ;
return V_35 ;
}
V_21 -> V_44 = NULL ;
}
V_26 = F_10 ( V_140 ) ;
V_33 = V_26 -> V_34 ( V_21 , F_126 ( V_21 ) ,
& V_23 , & V_13 ) ;
if ( V_33 <= 0 ) {
F_15 ( L_13 ) ;
F_84 ( V_17 , error ) ;
F_84 ( V_17 , V_143 ) ;
V_33 = - V_33 ;
goto V_77;
}
V_28 = F_12 ( V_140 , V_13 ) ;
if ( V_28 -> error != NULL ) {
V_33 = V_28 -> error ( V_17 , V_116 , V_21 , V_23 , & V_84 ,
V_140 , V_141 ) ;
if ( V_33 <= 0 ) {
F_84 ( V_17 , error ) ;
F_84 ( V_17 , V_143 ) ;
V_33 = - V_33 ;
goto V_77;
}
if ( V_21 -> V_44 )
goto V_77;
}
V_18 = F_125 ( V_17 , V_116 , V_21 , V_23 , V_140 , V_13 ,
V_26 , V_28 , & V_133 , & V_84 ) ;
if ( ! V_18 ) {
F_84 ( V_17 , V_143 ) ;
V_33 = V_35 ;
goto V_77;
}
if ( F_106 ( V_18 ) ) {
F_84 ( V_17 , V_144 ) ;
V_33 = V_93 ;
goto V_77;
}
F_20 ( V_21 -> V_44 ) ;
V_122 = F_130 ( V_17 , V_18 , V_28 ) ;
V_33 = V_28 -> V_145 ( V_18 , V_21 , V_23 , V_84 , V_140 , V_141 , V_122 ) ;
if ( V_33 <= 0 ) {
F_15 ( L_14 ) ;
F_131 ( V_21 -> V_44 ) ;
V_21 -> V_44 = NULL ;
F_84 ( V_17 , V_143 ) ;
if ( V_33 == - V_93 )
F_84 ( V_17 , V_144 ) ;
V_33 = - V_33 ;
goto V_77;
}
if ( V_133 && ! F_132 ( V_135 , & V_18 -> V_61 ) )
F_75 ( V_146 , V_18 ) ;
V_77:
if ( V_116 ) {
if ( V_33 == V_147 )
V_21 -> V_44 = (struct V_43 * ) V_116 ;
else
F_30 ( V_116 ) ;
}
return V_33 ;
}
bool F_133 ( struct V_1 * V_36 ,
const struct V_1 * V_37 )
{
bool V_33 ;
F_9 () ;
V_33 = F_13 ( V_36 , V_37 ,
F_10 ( V_37 -> V_5 . V_24 ) ,
F_12 ( V_37 -> V_5 . V_24 ,
V_37 -> V_6 . V_13 ) ) ;
F_11 () ;
return V_33 ;
}
void F_134 ( struct V_39 * V_18 ,
const struct V_1 * V_148 )
{
struct V_81 * V_82 = F_74 ( V_18 ) ;
F_20 ( ! F_71 ( V_18 ) ) ;
F_15 ( L_15 , V_18 ) ;
F_135 ( V_148 ) ;
V_18 -> V_40 [ V_42 ] . V_2 = * V_148 ;
if ( V_18 -> V_50 || ( V_82 && ! F_136 ( & V_82 -> V_149 ) ) )
return;
F_9 () ;
F_123 ( V_18 , NULL , V_113 ) ;
F_11 () ;
}
void F_137 ( struct V_39 * V_18 ,
enum V_83 V_84 ,
const struct V_20 * V_21 ,
unsigned long V_150 ,
int V_151 )
{
F_20 ( V_18 -> V_46 . V_152 == ( unsigned long ) V_18 ) ;
F_20 ( V_21 ) ;
if ( F_81 ( V_153 , & V_18 -> V_61 ) )
goto V_154;
if ( ! F_71 ( V_18 ) ) {
V_18 -> V_46 . V_57 = V_150 ;
} else {
unsigned long V_155 = V_58 + V_150 ;
if ( V_155 - V_18 -> V_46 . V_57 >= V_156 )
F_138 ( & V_18 -> V_46 , V_155 ) ;
}
V_154:
if ( V_151 ) {
struct V_157 * V_154 ;
V_154 = F_139 ( V_18 ) ;
if ( V_154 ) {
struct V_158 * V_159 = V_154 -> V_159 ;
F_140 ( & V_159 [ F_70 ( V_84 ) ] . V_160 ) ;
F_141 ( V_21 -> V_161 , & V_159 [ F_70 ( V_84 ) ] . V_162 ) ;
}
}
}
bool F_142 ( struct V_39 * V_18 ,
enum V_83 V_84 ,
const struct V_20 * V_21 ,
int V_151 )
{
if ( V_151 ) {
struct V_157 * V_154 ;
V_154 = F_139 ( V_18 ) ;
if ( V_154 ) {
struct V_158 * V_159 = V_154 -> V_159 ;
F_140 ( & V_159 [ F_70 ( V_84 ) ] . V_160 ) ;
F_141 ( V_21 -> V_161 - F_126 ( V_21 ) ,
& V_159 [ F_70 ( V_84 ) ] . V_162 ) ;
}
}
if ( F_83 ( & V_18 -> V_46 ) ) {
V_18 -> V_46 . V_163 ( ( unsigned long ) V_18 ) ;
return true ;
}
return false ;
}
int F_143 ( struct V_20 * V_21 ,
const struct V_1 * V_2 )
{
if ( F_144 ( V_21 , V_164 , V_2 -> V_5 . V_11 . V_165 . V_166 ) ||
F_144 ( V_21 , V_167 , V_2 -> V_6 . V_11 . V_165 . V_166 ) )
goto V_168;
return 0 ;
V_168:
return - 1 ;
}
int F_145 ( struct V_169 * V_170 [] ,
struct V_1 * V_171 )
{
if ( ! V_170 [ V_164 ] || ! V_170 [ V_167 ] )
return - V_172 ;
V_171 -> V_5 . V_11 . V_165 . V_166 = F_146 ( V_170 [ V_164 ] ) ;
V_171 -> V_6 . V_11 . V_165 . V_166 = F_146 ( V_170 [ V_167 ] ) ;
return 0 ;
}
int F_147 ( void )
{
return F_148 ( V_173 , V_174 + 1 ) ;
}
static void F_149 ( struct V_20 * V_175 , const struct V_20 * V_21 )
{
struct V_39 * V_18 ;
enum V_83 V_84 ;
V_18 = F_69 ( V_21 , & V_84 ) ;
if ( F_70 ( V_84 ) == V_31 )
V_84 = V_176 ;
else
V_84 = V_137 ;
V_175 -> V_44 = & V_18 -> V_75 ;
V_175 -> V_139 = V_84 ;
F_67 ( V_175 -> V_44 ) ;
}
static struct V_39 *
F_150 ( struct V_17 * V_17 , int (* F_151)( struct V_39 * V_96 , void * V_152 ) ,
void * V_152 , unsigned int * V_70 )
{
struct V_67 * V_68 ;
struct V_39 * V_18 ;
struct V_69 * V_4 ;
F_25 ( & V_48 ) ;
for (; * V_70 < V_17 -> V_18 . V_19 ; ( * V_70 ) ++ ) {
F_66 (h, n, &net->ct.hash[*bucket], hnnode) {
if ( F_127 ( V_68 ) != V_31 )
continue;
V_18 = F_56 ( V_68 ) ;
if ( F_151 ( V_18 , V_152 ) )
goto V_72;
}
}
F_66 (h, n, &net->ct.unconfirmed, hnnode) {
V_18 = F_56 ( V_68 ) ;
if ( F_151 ( V_18 , V_152 ) )
F_40 ( V_60 , & V_18 -> V_61 ) ;
}
F_29 ( & V_48 ) ;
return NULL ;
V_72:
F_72 ( & V_18 -> V_75 . V_45 ) ;
F_29 ( & V_48 ) ;
return V_18 ;
}
void F_152 ( struct V_17 * V_17 ,
int (* F_151)( struct V_39 * V_96 , void * V_152 ) ,
void * V_152 , T_1 V_62 , int V_63 )
{
struct V_39 * V_18 ;
unsigned int V_70 = 0 ;
while ( ( V_18 = F_150 ( V_17 , F_151 , V_152 , & V_70 ) ) != NULL ) {
if ( F_83 ( & V_18 -> V_46 ) )
F_43 ( V_18 , V_62 , V_63 ) ;
F_30 ( V_18 ) ;
}
}
static int F_153 ( struct V_39 * V_96 , void * V_152 )
{
return 1 ;
}
void F_154 ( void * V_14 , unsigned int V_15 )
{
if ( F_155 ( V_14 ) )
F_156 ( V_14 ) ;
else
F_157 ( ( unsigned long ) V_14 ,
F_158 ( sizeof( struct V_177 ) * V_15 ) ) ;
}
void F_159 ( struct V_17 * V_17 , T_1 V_62 , int V_63 )
{
F_152 ( V_17 , F_153 , NULL , V_62 , V_63 ) ;
}
static void F_160 ( struct V_17 * V_17 )
{
struct V_67 * V_68 ;
struct V_39 * V_18 ;
struct V_69 * V_4 ;
F_25 ( & V_48 ) ;
F_66 (h, n, &net->ct.dying, hnnode) {
V_18 = F_56 ( V_68 ) ;
F_161 ( V_18 ) ;
}
F_29 ( & V_48 ) ;
}
static int F_162 ( void )
{
int V_97 = 0 , V_178 ;
F_163 (cpu) {
struct V_39 * V_18 = & F_164 ( V_179 , V_178 ) ;
V_97 += F_21 ( & V_18 -> V_75 . V_45 ) - 1 ;
}
return V_97 ;
}
void F_165 ( void )
{
F_166 ( V_180 , NULL ) ;
}
void F_167 ( void )
{
F_166 ( V_181 , NULL ) ;
while ( F_162 () > 0 )
F_168 () ;
#ifdef F_96
F_169 ( & V_182 ) ;
#endif
F_170 () ;
F_171 () ;
F_172 () ;
F_173 () ;
F_174 () ;
F_175 () ;
F_176 () ;
F_177 () ;
F_178 () ;
}
void F_179 ( struct V_17 * V_17 )
{
F_180 ( V_183 ) ;
F_181 ( & V_17 -> V_184 , & V_183 ) ;
F_182 ( & V_183 ) ;
}
void F_182 ( struct V_185 * V_186 )
{
int V_187 ;
struct V_17 * V_17 ;
F_183 () ;
V_188:
V_187 = 0 ;
F_184 (net, net_exit_list, exit_list) {
F_152 ( V_17 , F_153 , NULL , 0 , 0 ) ;
F_160 ( V_17 ) ;
if ( F_21 ( & V_17 -> V_18 . V_103 ) != 0 )
V_187 = 1 ;
}
if ( V_187 ) {
F_168 () ;
goto V_188;
}
F_184 (net, net_exit_list, exit_list) {
F_154 ( V_17 -> V_18 . V_14 , V_17 -> V_18 . V_19 ) ;
F_185 ( V_17 ) ;
F_186 ( V_17 ) ;
F_187 ( V_17 ) ;
F_188 ( V_17 ) ;
F_189 ( V_17 ) ;
F_190 ( V_17 ) ;
F_191 ( V_17 -> V_18 . V_106 ) ;
F_192 ( V_17 -> V_18 . V_189 ) ;
F_193 ( V_17 -> V_18 . V_190 ) ;
}
}
void * F_194 ( unsigned int * V_191 , int V_192 )
{
struct V_193 * V_14 ;
unsigned int V_194 , V_96 ;
T_8 V_195 ;
F_195 ( sizeof( struct V_193 ) != sizeof( struct V_177 ) ) ;
V_194 = * V_191 = F_196 ( * V_191 , V_196 / sizeof( struct V_193 ) ) ;
V_195 = V_194 * sizeof( struct V_193 ) ;
V_14 = ( void * ) F_197 ( V_197 | V_198 | V_199 ,
F_158 ( V_195 ) ) ;
if ( ! V_14 ) {
F_198 ( V_200 L_16 ) ;
V_14 = F_199 ( V_195 ) ;
}
if ( V_14 && V_192 )
for ( V_96 = 0 ; V_96 < V_194 ; V_96 ++ )
F_200 ( & V_14 [ V_96 ] , V_96 ) ;
return V_14 ;
}
int F_201 ( const char * V_201 , struct V_202 * V_203 )
{
int V_96 , V_70 , V_204 ;
unsigned int V_205 , V_206 ;
struct V_193 * V_14 , * V_207 ;
struct V_67 * V_68 ;
struct V_39 * V_18 ;
if ( V_208 -> V_209 -> V_210 != & V_211 )
return - V_212 ;
if ( ! V_213 )
return F_202 ( V_201 , V_203 ) ;
V_204 = F_203 ( V_201 , 0 , & V_205 ) ;
if ( V_204 )
return V_204 ;
if ( ! V_205 )
return - V_172 ;
V_14 = F_194 ( & V_205 , 1 ) ;
if ( ! V_14 )
return - V_105 ;
F_25 ( & V_48 ) ;
for ( V_96 = 0 ; V_96 < V_211 . V_18 . V_19 ; V_96 ++ ) {
while ( ! F_204 ( & V_211 . V_18 . V_14 [ V_96 ] ) ) {
V_68 = F_205 ( V_211 . V_18 . V_14 [ V_96 ] . V_214 ,
struct V_67 , V_41 ) ;
V_18 = F_56 ( V_68 ) ;
F_16 ( & V_68 -> V_41 ) ;
V_70 = F_5 ( & V_68 -> V_2 , F_55 ( V_18 ) ,
V_205 ) ;
F_64 ( & V_68 -> V_41 , & V_14 [ V_70 ] ) ;
}
}
V_206 = V_211 . V_18 . V_19 ;
V_207 = V_211 . V_18 . V_14 ;
V_211 . V_18 . V_19 = V_213 = V_205 ;
V_211 . V_18 . V_14 = V_14 ;
F_29 ( & V_48 ) ;
F_154 ( V_207 , V_206 ) ;
return 0 ;
}
void F_206 ( unsigned long V_215 )
{
int V_178 ;
F_163 (cpu)
F_164 ( V_179 , V_178 ) . V_61 |= V_215 ;
}
int F_207 ( void )
{
int V_216 = 8 ;
int V_33 , V_178 ;
if ( ! V_213 ) {
V_213
= ( ( ( V_217 << V_218 ) / 16384 )
/ sizeof( struct V_177 ) ) ;
if ( V_217 > ( 1024 * 1024 * 1024 / V_196 ) )
V_213 = 16384 ;
if ( V_213 < 32 )
V_213 = 32 ;
V_216 = 4 ;
}
V_104 = V_216 * V_213 ;
F_198 ( V_219 L_17 ,
V_220 , V_213 ,
V_104 ) ;
V_33 = F_208 () ;
if ( V_33 < 0 )
goto V_221;
V_33 = F_209 () ;
if ( V_33 < 0 )
goto V_222;
V_33 = F_210 () ;
if ( V_33 < 0 )
goto V_223;
V_33 = F_211 () ;
if ( V_33 < 0 )
goto V_224;
V_33 = F_212 () ;
if ( V_33 < 0 )
goto V_225;
V_33 = F_213 () ;
if ( V_33 < 0 )
goto V_226;
V_33 = F_214 () ;
if ( V_33 < 0 )
goto V_227;
V_33 = F_215 () ;
if ( V_33 < 0 )
goto V_228;
#ifdef F_96
V_33 = F_216 ( & V_182 ) ;
if ( V_33 < 0 )
goto V_229;
#endif
V_33 = F_217 () ;
if ( V_33 < 0 )
goto V_230;
F_163 (cpu) {
struct V_39 * V_18 = & F_164 ( V_179 , V_178 ) ;
F_95 ( & V_18 -> V_110 , & V_211 ) ;
F_99 ( & V_18 -> V_75 . V_45 , 1 ) ;
}
F_206 ( V_86 | V_231 ) ;
return 0 ;
V_230:
#ifdef F_96
F_169 ( & V_182 ) ;
V_229:
#endif
F_171 () ;
V_228:
F_172 () ;
V_227:
F_173 () ;
V_226:
F_174 () ;
V_225:
F_175 () ;
V_224:
F_176 () ;
V_223:
F_177 () ;
V_222:
F_178 () ;
V_221:
return V_33 ;
}
void F_218 ( void )
{
F_166 ( V_180 , F_149 ) ;
F_166 ( V_181 , F_18 ) ;
}
int F_219 ( struct V_17 * V_17 )
{
int V_33 ;
F_99 ( & V_17 -> V_18 . V_103 , 0 ) ;
F_200 ( & V_17 -> V_18 . V_131 , V_232 ) ;
F_200 ( & V_17 -> V_18 . V_52 , V_233 ) ;
F_200 ( & V_17 -> V_18 . V_116 , V_234 ) ;
V_17 -> V_18 . V_190 = F_220 ( struct V_235 ) ;
if ( ! V_17 -> V_18 . V_190 ) {
V_33 = - V_105 ;
goto V_236;
}
V_17 -> V_18 . V_189 = F_221 ( V_197 , L_18 , V_17 ) ;
if ( ! V_17 -> V_18 . V_189 ) {
V_33 = - V_105 ;
goto V_237;
}
V_17 -> V_18 . V_106 = F_222 ( V_17 -> V_18 . V_189 ,
sizeof( struct V_39 ) , 0 ,
V_238 , NULL ) ;
if ( ! V_17 -> V_18 . V_106 ) {
F_198 ( V_239 L_19 ) ;
V_33 = - V_105 ;
goto V_240;
}
V_17 -> V_18 . V_19 = V_213 ;
V_17 -> V_18 . V_14 = F_194 ( & V_17 -> V_18 . V_19 , 1 ) ;
if ( ! V_17 -> V_18 . V_14 ) {
V_33 = - V_105 ;
F_198 ( V_239 L_20 ) ;
goto V_241;
}
V_33 = F_223 ( V_17 ) ;
if ( V_33 < 0 )
goto V_221;
V_33 = F_224 ( V_17 ) ;
if ( V_33 < 0 )
goto V_222;
V_33 = F_225 ( V_17 ) ;
if ( V_33 < 0 )
goto V_223;
V_33 = F_226 ( V_17 ) ;
if ( V_33 < 0 )
goto V_224;
V_33 = F_227 ( V_17 ) ;
if ( V_33 < 0 )
goto V_226;
V_33 = F_228 ( V_17 ) ;
if ( V_33 < 0 )
goto V_230;
return 0 ;
V_230:
F_186 ( V_17 ) ;
V_226:
F_187 ( V_17 ) ;
V_224:
F_188 ( V_17 ) ;
V_223:
F_189 ( V_17 ) ;
V_222:
F_190 ( V_17 ) ;
V_221:
F_154 ( V_17 -> V_18 . V_14 , V_17 -> V_18 . V_19 ) ;
V_241:
F_191 ( V_17 -> V_18 . V_106 ) ;
V_240:
F_192 ( V_17 -> V_18 . V_189 ) ;
V_237:
F_193 ( V_17 -> V_18 . V_190 ) ;
V_236:
return V_33 ;
}
