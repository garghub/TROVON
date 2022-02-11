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
static inline bool
F_51 ( struct V_67 * V_68 ,
const struct V_1 * V_2 ,
T_2 V_3 )
{
struct V_39 * V_18 = F_52 ( V_68 ) ;
return F_53 ( V_2 , & V_68 -> V_2 ) &&
F_54 ( V_18 ) == V_3 &&
F_55 ( V_18 ) ;
}
static struct V_67 *
F_56 ( struct V_17 * V_17 , T_2 V_3 ,
const struct V_1 * V_2 , T_1 V_14 )
{
struct V_67 * V_68 ;
struct V_69 * V_4 ;
unsigned int V_70 = F_4 ( V_14 , V_17 ) ;
F_57 () ;
V_71:
F_58 (h, n, &net->ct.hash[bucket], hnnode) {
if ( F_51 ( V_68 , V_2 , V_3 ) ) {
F_28 ( V_17 , V_72 ) ;
F_59 () ;
return V_68 ;
}
F_28 ( V_17 , V_73 ) ;
}
if ( F_60 ( V_4 ) != V_70 ) {
F_28 ( V_17 , V_74 ) ;
goto V_71;
}
F_59 () ;
return NULL ;
}
static struct V_67 *
F_61 ( struct V_17 * V_17 , T_2 V_3 ,
const struct V_1 * V_2 , T_1 V_14 )
{
struct V_67 * V_68 ;
struct V_39 * V_18 ;
F_9 () ;
V_71:
V_68 = F_56 ( V_17 , V_3 , V_2 , V_14 ) ;
if ( V_68 ) {
V_18 = F_52 ( V_68 ) ;
if ( F_48 ( F_47 ( V_18 ) ||
! F_62 ( & V_18 -> V_75 . V_45 ) ) )
V_68 = NULL ;
else {
if ( F_48 ( ! F_51 ( V_68 , V_2 , V_3 ) ) ) {
F_30 ( V_18 ) ;
goto V_71;
}
}
}
F_11 () ;
return V_68 ;
}
struct V_67 *
F_63 ( struct V_17 * V_17 , T_2 V_3 ,
const struct V_1 * V_2 )
{
return F_61 ( V_17 , V_3 , V_2 ,
F_1 ( V_2 , V_3 ) ) ;
}
static void F_64 ( struct V_39 * V_18 ,
unsigned int V_14 ,
unsigned int V_76 )
{
struct V_17 * V_17 = F_19 ( V_18 ) ;
F_65 ( & V_18 -> V_40 [ V_31 ] . V_41 ,
& V_17 -> V_18 . V_14 [ V_14 ] ) ;
F_65 ( & V_18 -> V_40 [ V_42 ] . V_41 ,
& V_17 -> V_18 . V_14 [ V_76 ] ) ;
}
int
F_66 ( struct V_39 * V_18 )
{
struct V_17 * V_17 = F_19 ( V_18 ) ;
unsigned int V_14 , V_76 ;
struct V_67 * V_68 ;
struct V_69 * V_4 ;
T_2 V_3 ;
V_3 = F_54 ( V_18 ) ;
V_14 = F_6 ( V_17 , V_3 ,
& V_18 -> V_40 [ V_31 ] . V_2 ) ;
V_76 = F_6 ( V_17 , V_3 ,
& V_18 -> V_40 [ V_42 ] . V_2 ) ;
F_25 ( & V_48 ) ;
F_67 (h, n, &net->ct.hash[hash], hnnode)
if ( F_53 ( & V_18 -> V_40 [ V_31 ] . V_2 ,
& V_68 -> V_2 ) &&
V_3 == F_54 ( F_52 ( V_68 ) ) )
goto V_77;
F_67 (h, n, &net->ct.hash[repl_hash], hnnode)
if ( F_53 ( & V_18 -> V_40 [ V_42 ] . V_2 ,
& V_68 -> V_2 ) &&
V_3 == F_54 ( F_52 ( V_68 ) ) )
goto V_77;
F_39 ( & V_18 -> V_46 ) ;
F_68 () ;
F_69 ( & V_18 -> V_75 . V_45 , 2 ) ;
F_64 ( V_18 , V_14 , V_76 ) ;
F_28 ( V_17 , V_78 ) ;
F_29 ( & V_48 ) ;
return 0 ;
V_77:
F_28 ( V_17 , V_79 ) ;
F_29 ( & V_48 ) ;
return - V_80 ;
}
void F_70 ( struct V_17 * V_17 , struct V_39 * V_81 )
{
F_71 ( V_82 , & V_81 -> V_61 ) ;
F_71 ( V_83 , & V_81 -> V_61 ) ;
F_72 ( & V_81 -> V_75 ) ;
F_25 ( & V_48 ) ;
F_65 ( & V_81 -> V_40 [ V_31 ] . V_41 ,
& V_17 -> V_18 . V_81 ) ;
F_29 ( & V_48 ) ;
}
int
F_73 ( struct V_20 * V_21 )
{
unsigned int V_14 , V_76 ;
struct V_67 * V_68 ;
struct V_39 * V_18 ;
struct V_84 * V_85 ;
struct V_64 * V_65 ;
struct V_69 * V_4 ;
enum V_86 V_87 ;
struct V_17 * V_17 ;
T_2 V_3 ;
V_18 = F_74 ( V_21 , & V_87 ) ;
V_17 = F_19 ( V_18 ) ;
if ( F_75 ( V_87 ) != V_31 )
return V_35 ;
V_3 = F_54 ( V_18 ) ;
V_14 = * ( unsigned long * ) & V_18 -> V_40 [ V_42 ] . V_41 . V_88 ;
V_14 = F_4 ( V_14 , V_17 ) ;
V_76 = F_6 ( V_17 , V_3 ,
& V_18 -> V_40 [ V_42 ] . V_2 ) ;
F_20 ( ! F_55 ( V_18 ) ) ;
F_15 ( L_4 , V_18 ) ;
F_25 ( & V_48 ) ;
if ( F_48 ( F_47 ( V_18 ) ) ) {
F_29 ( & V_48 ) ;
return V_35 ;
}
F_67 (h, n, &net->ct.hash[hash], hnnode)
if ( F_53 ( & V_18 -> V_40 [ V_31 ] . V_2 ,
& V_68 -> V_2 ) &&
V_3 == F_54 ( F_52 ( V_68 ) ) )
goto V_77;
F_67 (h, n, &net->ct.hash[repl_hash], hnnode)
if ( F_53 ( & V_18 -> V_40 [ V_42 ] . V_2 ,
& V_68 -> V_2 ) &&
V_3 == F_54 ( F_52 ( V_68 ) ) )
goto V_77;
F_16 ( & V_18 -> V_40 [ V_31 ] . V_41 ) ;
V_18 -> V_46 . V_57 += V_58 ;
F_39 ( & V_18 -> V_46 ) ;
F_76 ( & V_18 -> V_75 . V_45 ) ;
V_18 -> V_61 |= V_89 ;
V_65 = F_44 ( V_18 ) ;
if ( V_65 ) {
if ( V_21 -> V_65 . V_90 == 0 )
F_77 ( V_21 ) ;
V_65 -> V_91 = F_45 ( V_21 -> V_65 ) ;
}
F_64 ( V_18 , V_14 , V_76 ) ;
F_28 ( V_17 , V_78 ) ;
F_29 ( & V_48 ) ;
V_85 = F_78 ( V_18 ) ;
if ( V_85 && V_85 -> V_92 )
F_79 ( V_93 , V_18 ) ;
F_79 ( F_80 ( V_18 ) ?
V_94 : V_95 , V_18 ) ;
return V_35 ;
V_77:
F_28 ( V_17 , V_79 ) ;
F_29 ( & V_48 ) ;
return V_96 ;
}
int
F_81 ( const struct V_1 * V_2 ,
const struct V_39 * V_97 )
{
struct V_17 * V_17 = F_19 ( V_97 ) ;
struct V_67 * V_68 ;
struct V_69 * V_4 ;
struct V_39 * V_18 ;
T_2 V_3 = F_54 ( V_97 ) ;
unsigned int V_14 = F_6 ( V_17 , V_3 , V_2 ) ;
F_82 () ;
F_58 (h, n, &net->ct.hash[hash], hnnode) {
V_18 = F_52 ( V_68 ) ;
if ( V_18 != V_97 &&
F_53 ( V_2 , & V_68 -> V_2 ) &&
F_54 ( V_18 ) == V_3 ) {
F_28 ( V_17 , V_72 ) ;
F_83 () ;
return 1 ;
}
F_28 ( V_17 , V_73 ) ;
}
F_83 () ;
return 0 ;
}
static T_6 int F_84 ( struct V_17 * V_17 , unsigned int V_14 )
{
struct V_67 * V_68 ;
struct V_39 * V_18 = NULL , * V_98 ;
struct V_69 * V_4 ;
unsigned int V_99 , V_100 = 0 ;
int V_101 = 0 ;
F_9 () ;
for ( V_99 = 0 ; V_99 < V_17 -> V_18 . V_19 ; V_99 ++ ) {
F_58 (h, n, &net->ct.hash[hash],
hnnode) {
V_98 = F_52 ( V_68 ) ;
if ( ! F_85 ( V_102 , & V_98 -> V_61 ) )
V_18 = V_98 ;
V_100 ++ ;
}
if ( V_18 != NULL ) {
if ( F_86 ( ! F_47 ( V_18 ) &&
F_62 ( & V_18 -> V_75 . V_45 ) ) )
break;
else
V_18 = NULL ;
}
if ( V_100 >= V_103 )
break;
V_14 = ( V_14 + 1 ) % V_17 -> V_18 . V_19 ;
}
F_11 () ;
if ( ! V_18 )
return V_101 ;
if ( F_87 ( & V_18 -> V_46 ) ) {
if ( F_43 ( V_18 , 0 , 0 ) ) {
V_101 = 1 ;
F_88 ( V_17 , F_84 ) ;
}
}
F_30 ( V_18 ) ;
return V_101 ;
}
void F_89 ( void )
{
unsigned int rand ;
do {
F_90 ( & rand , sizeof( rand ) ) ;
} while ( ! rand );
F_91 ( & V_8 , 0 , rand ) ;
}
static struct V_39 *
F_92 ( struct V_17 * V_17 , T_2 V_3 ,
const struct V_1 * V_37 ,
const struct V_1 * V_104 ,
T_7 V_105 , T_1 V_14 )
{
struct V_39 * V_18 ;
if ( F_48 ( ! V_8 ) ) {
F_89 () ;
V_14 = F_1 ( V_37 , V_3 ) ;
}
F_76 ( & V_17 -> V_18 . V_106 ) ;
if ( V_107 &&
F_48 ( F_21 ( & V_17 -> V_18 . V_106 ) > V_107 ) ) {
if ( ! F_84 ( V_17 , F_4 ( V_14 , V_17 ) ) ) {
F_93 ( & V_17 -> V_18 . V_106 ) ;
F_94 ( L_5 ) ;
return F_95 ( - V_108 ) ;
}
}
V_18 = F_96 ( V_17 -> V_18 . V_109 , V_105 ) ;
if ( V_18 == NULL ) {
F_93 ( & V_17 -> V_18 . V_106 ) ;
return F_95 ( - V_108 ) ;
}
memset ( & V_18 -> V_40 [ V_110 ] , 0 ,
F_97 ( struct V_39 , V_111 ) -
F_97 ( struct V_39 , V_40 [ V_110 ] ) ) ;
F_98 ( & V_18 -> V_112 ) ;
V_18 -> V_40 [ V_31 ] . V_2 = * V_37 ;
V_18 -> V_40 [ V_31 ] . V_41 . V_88 = NULL ;
V_18 -> V_40 [ V_42 ] . V_2 = * V_104 ;
* ( unsigned long * ) ( & V_18 -> V_40 [ V_42 ] . V_41 . V_88 ) = V_14 ;
F_42 ( & V_18 -> V_46 , F_50 , ( unsigned long ) V_18 ) ;
F_99 ( & V_18 -> V_113 , V_17 ) ;
#ifdef F_100
if ( V_3 ) {
struct V_114 * F_54 ;
F_54 = F_101 ( V_18 , V_115 , V_116 ) ;
if ( ! F_54 )
goto V_117;
F_54 -> V_118 = V_3 ;
}
#endif
F_69 ( & V_18 -> V_75 . V_45 , 0 ) ;
return V_18 ;
#ifdef F_100
V_117:
F_93 ( & V_17 -> V_18 . V_106 ) ;
F_102 ( V_17 -> V_18 . V_109 , V_18 ) ;
return F_95 ( - V_108 ) ;
#endif
}
struct V_39 * F_103 ( struct V_17 * V_17 , T_2 V_3 ,
const struct V_1 * V_37 ,
const struct V_1 * V_104 ,
T_7 V_105 )
{
return F_92 ( V_17 , V_3 , V_37 , V_104 , V_105 , 0 ) ;
}
void F_31 ( struct V_39 * V_18 )
{
struct V_17 * V_17 = F_19 ( V_18 ) ;
F_20 ( F_21 ( & V_18 -> V_75 . V_45 ) == 0 ) ;
F_104 ( V_18 ) ;
F_105 ( V_18 ) ;
F_102 ( V_17 -> V_18 . V_109 , V_18 ) ;
F_106 () ;
F_93 ( & V_17 -> V_18 . V_106 ) ;
}
static struct V_67 *
F_107 ( struct V_17 * V_17 , struct V_39 * V_81 ,
const struct V_1 * V_2 ,
struct V_25 * V_26 ,
struct V_27 * V_28 ,
struct V_20 * V_21 ,
unsigned int V_23 , T_1 V_14 )
{
struct V_39 * V_18 ;
struct V_84 * V_85 ;
struct V_1 V_119 ;
struct V_54 * V_55 ;
struct V_120 * exp ;
T_2 V_3 = V_81 ? F_54 ( V_81 ) : V_121 ;
struct V_122 * V_123 ;
unsigned int * V_124 ;
if ( ! F_13 ( & V_119 , V_2 , V_26 , V_28 ) ) {
F_15 ( L_6 ) ;
return NULL ;
}
V_18 = F_92 ( V_17 , V_3 , V_2 , & V_119 , V_116 ,
V_14 ) ;
if ( F_108 ( V_18 ) )
return (struct V_67 * ) V_18 ;
if ( V_81 && F_109 ( V_81 ) ) {
F_110 ( V_18 ) ;
F_111 ( V_18 ) ;
}
V_123 = V_81 ? F_112 ( V_81 ) : NULL ;
if ( V_123 )
V_124 = F_113 ( V_123 ) ;
else
V_124 = V_28 -> V_125 ( V_17 ) ;
if ( ! V_28 -> V_126 ( V_18 , V_21 , V_23 , V_124 ) ) {
F_31 ( V_18 ) ;
F_15 ( L_7 ) ;
return NULL ;
}
if ( V_123 )
F_114 ( V_18 , V_123 -> V_46 , V_116 ) ;
F_115 ( V_18 , V_116 ) ;
F_116 ( V_18 , V_116 ) ;
F_117 ( V_18 ) ;
V_55 = V_81 ? F_36 ( V_81 ) : NULL ;
F_118 ( V_18 , V_55 ? V_55 -> V_127 : 0 ,
V_55 ? V_55 -> V_128 : 0 ,
V_116 ) ;
F_25 ( & V_48 ) ;
exp = F_119 ( V_17 , V_3 , V_2 ) ;
if ( exp ) {
F_15 ( L_8 ,
V_18 , exp ) ;
F_71 ( V_129 , & V_18 -> V_61 ) ;
V_18 -> V_50 = exp -> V_50 ;
if ( exp -> V_92 ) {
V_85 = F_120 ( V_18 , exp -> V_92 ,
V_116 ) ;
if ( V_85 )
F_121 ( V_85 -> V_92 , exp -> V_92 ) ;
}
#ifdef F_122
V_18 -> V_130 = exp -> V_50 -> V_130 ;
#endif
#ifdef F_123
V_18 -> V_131 = exp -> V_50 -> V_131 ;
#endif
F_72 ( & V_18 -> V_50 -> V_75 ) ;
F_28 ( V_17 , V_132 ) ;
} else {
F_124 ( V_18 , V_81 , V_116 ) ;
F_28 ( V_17 , V_126 ) ;
}
F_72 ( & V_18 -> V_75 ) ;
F_65 ( & V_18 -> V_40 [ V_31 ] . V_41 ,
& V_17 -> V_18 . V_133 ) ;
F_29 ( & V_48 ) ;
if ( exp ) {
if ( exp -> V_134 )
exp -> V_134 ( V_18 , exp ) ;
F_125 ( exp ) ;
}
return & V_18 -> V_40 [ V_31 ] ;
}
static inline struct V_39 *
F_126 ( struct V_17 * V_17 , struct V_39 * V_81 ,
struct V_20 * V_21 ,
unsigned int V_23 ,
T_4 V_24 ,
T_5 V_13 ,
struct V_25 * V_26 ,
struct V_27 * V_28 ,
int * V_135 ,
enum V_86 * V_87 )
{
struct V_1 V_2 ;
struct V_67 * V_68 ;
struct V_39 * V_18 ;
T_2 V_3 = V_81 ? F_54 ( V_81 ) : V_121 ;
T_1 V_14 ;
if ( ! F_7 ( V_21 , F_127 ( V_21 ) ,
V_23 , V_24 , V_13 , & V_2 , V_26 ,
V_28 ) ) {
F_15 ( L_9 ) ;
return NULL ;
}
V_14 = F_1 ( & V_2 , V_3 ) ;
V_68 = F_61 ( V_17 , V_3 , & V_2 , V_14 ) ;
if ( ! V_68 ) {
V_68 = F_107 ( V_17 , V_81 , & V_2 , V_26 , V_28 ,
V_21 , V_23 , V_14 ) ;
if ( ! V_68 )
return NULL ;
if ( F_108 ( V_68 ) )
return ( void * ) V_68 ;
}
V_18 = F_52 ( V_68 ) ;
if ( F_128 ( V_68 ) == V_42 ) {
* V_87 = V_136 ;
* V_135 = 1 ;
} else {
if ( F_85 ( V_137 , & V_18 -> V_61 ) ) {
F_15 ( L_10 , V_18 ) ;
* V_87 = V_138 ;
} else if ( F_85 ( V_129 , & V_18 -> V_61 ) ) {
F_15 ( L_11 ,
V_18 ) ;
* V_87 = V_139 ;
} else {
F_15 ( L_12 , V_18 ) ;
* V_87 = V_140 ;
}
* V_135 = 0 ;
}
V_21 -> V_44 = & V_18 -> V_75 ;
V_21 -> V_141 = * V_87 ;
return V_18 ;
}
unsigned int
F_129 ( struct V_17 * V_17 , T_5 V_142 , unsigned int V_143 ,
struct V_20 * V_21 )
{
struct V_39 * V_18 , * V_81 = NULL ;
enum V_86 V_87 ;
struct V_25 * V_26 ;
struct V_27 * V_28 ;
unsigned int * V_124 ;
unsigned int V_23 ;
T_5 V_13 ;
int V_135 = 0 ;
int V_33 ;
if ( V_21 -> V_44 ) {
V_81 = (struct V_39 * ) V_21 -> V_44 ;
if ( ! F_130 ( V_81 ) ) {
F_88 ( V_17 , V_144 ) ;
return V_35 ;
}
V_21 -> V_44 = NULL ;
}
V_26 = F_10 ( V_142 ) ;
V_33 = V_26 -> V_34 ( V_21 , F_127 ( V_21 ) ,
& V_23 , & V_13 ) ;
if ( V_33 <= 0 ) {
F_15 ( L_13 ) ;
F_88 ( V_17 , error ) ;
F_88 ( V_17 , V_145 ) ;
V_33 = - V_33 ;
goto V_77;
}
V_28 = F_12 ( V_142 , V_13 ) ;
if ( V_28 -> error != NULL ) {
V_33 = V_28 -> error ( V_17 , V_81 , V_21 , V_23 , & V_87 ,
V_142 , V_143 ) ;
if ( V_33 <= 0 ) {
F_88 ( V_17 , error ) ;
F_88 ( V_17 , V_145 ) ;
V_33 = - V_33 ;
goto V_77;
}
if ( V_21 -> V_44 )
goto V_77;
}
V_18 = F_126 ( V_17 , V_81 , V_21 , V_23 , V_142 , V_13 ,
V_26 , V_28 , & V_135 , & V_87 ) ;
if ( ! V_18 ) {
F_88 ( V_17 , V_145 ) ;
V_33 = V_35 ;
goto V_77;
}
if ( F_108 ( V_18 ) ) {
F_88 ( V_17 , V_146 ) ;
V_33 = V_96 ;
goto V_77;
}
F_20 ( V_21 -> V_44 ) ;
V_124 = F_131 ( V_17 , V_18 , V_28 ) ;
V_33 = V_28 -> V_147 ( V_18 , V_21 , V_23 , V_87 , V_142 , V_143 , V_124 ) ;
if ( V_33 <= 0 ) {
F_15 ( L_14 ) ;
F_132 ( V_21 -> V_44 ) ;
V_21 -> V_44 = NULL ;
F_88 ( V_17 , V_145 ) ;
if ( V_33 == - V_96 )
F_88 ( V_17 , V_146 ) ;
V_33 = - V_33 ;
goto V_77;
}
if ( V_135 && ! F_133 ( V_137 , & V_18 -> V_61 ) )
F_79 ( V_148 , V_18 ) ;
V_77:
if ( V_81 ) {
if ( V_33 == V_149 )
V_21 -> V_44 = (struct V_43 * ) V_81 ;
else
F_30 ( V_81 ) ;
}
return V_33 ;
}
bool F_134 ( struct V_1 * V_36 ,
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
void F_135 ( struct V_39 * V_18 ,
const struct V_1 * V_150 )
{
struct V_84 * V_85 = F_78 ( V_18 ) ;
F_20 ( ! F_55 ( V_18 ) ) ;
F_15 ( L_15 , V_18 ) ;
F_136 ( V_150 ) ;
V_18 -> V_40 [ V_42 ] . V_2 = * V_150 ;
if ( V_18 -> V_50 || ( V_85 && ! F_137 ( & V_85 -> V_151 ) ) )
return;
F_9 () ;
F_124 ( V_18 , NULL , V_116 ) ;
F_11 () ;
}
void F_138 ( struct V_39 * V_18 ,
enum V_86 V_87 ,
const struct V_20 * V_21 ,
unsigned long V_152 ,
int V_153 )
{
F_20 ( V_18 -> V_46 . V_154 == ( unsigned long ) V_18 ) ;
F_20 ( V_21 ) ;
if ( F_85 ( V_155 , & V_18 -> V_61 ) )
goto V_156;
if ( ! F_55 ( V_18 ) ) {
V_18 -> V_46 . V_57 = V_152 ;
} else {
unsigned long V_157 = V_58 + V_152 ;
if ( V_157 - V_18 -> V_46 . V_57 >= V_158 )
F_139 ( & V_18 -> V_46 , V_157 ) ;
}
V_156:
if ( V_153 ) {
struct V_159 * V_156 ;
V_156 = F_140 ( V_18 ) ;
if ( V_156 ) {
struct V_160 * V_161 = V_156 -> V_161 ;
F_141 ( & V_161 [ F_75 ( V_87 ) ] . V_162 ) ;
F_142 ( V_21 -> V_163 , & V_161 [ F_75 ( V_87 ) ] . V_164 ) ;
}
}
}
bool F_143 ( struct V_39 * V_18 ,
enum V_86 V_87 ,
const struct V_20 * V_21 ,
int V_153 )
{
if ( V_153 ) {
struct V_159 * V_156 ;
V_156 = F_140 ( V_18 ) ;
if ( V_156 ) {
struct V_160 * V_161 = V_156 -> V_161 ;
F_141 ( & V_161 [ F_75 ( V_87 ) ] . V_162 ) ;
F_142 ( V_21 -> V_163 - F_127 ( V_21 ) ,
& V_161 [ F_75 ( V_87 ) ] . V_164 ) ;
}
}
if ( F_87 ( & V_18 -> V_46 ) ) {
V_18 -> V_46 . V_165 ( ( unsigned long ) V_18 ) ;
return true ;
}
return false ;
}
int F_144 ( struct V_20 * V_21 ,
const struct V_1 * V_2 )
{
if ( F_145 ( V_21 , V_166 , V_2 -> V_5 . V_11 . V_167 . V_168 ) ||
F_145 ( V_21 , V_169 , V_2 -> V_6 . V_11 . V_167 . V_168 ) )
goto V_170;
return 0 ;
V_170:
return - 1 ;
}
int F_146 ( struct V_171 * V_172 [] ,
struct V_1 * V_173 )
{
if ( ! V_172 [ V_166 ] || ! V_172 [ V_169 ] )
return - V_174 ;
V_173 -> V_5 . V_11 . V_167 . V_168 = F_147 ( V_172 [ V_166 ] ) ;
V_173 -> V_6 . V_11 . V_167 . V_168 = F_147 ( V_172 [ V_169 ] ) ;
return 0 ;
}
int F_148 ( void )
{
return F_149 ( V_175 , V_176 + 1 ) ;
}
static void F_150 ( struct V_20 * V_177 , const struct V_20 * V_21 )
{
struct V_39 * V_18 ;
enum V_86 V_87 ;
V_18 = F_74 ( V_21 , & V_87 ) ;
if ( F_75 ( V_87 ) == V_31 )
V_87 = V_178 ;
else
V_87 = V_139 ;
V_177 -> V_44 = & V_18 -> V_75 ;
V_177 -> V_141 = V_87 ;
F_72 ( V_177 -> V_44 ) ;
}
static struct V_39 *
F_151 ( struct V_17 * V_17 , int (* F_152)( struct V_39 * V_99 , void * V_154 ) ,
void * V_154 , unsigned int * V_70 )
{
struct V_67 * V_68 ;
struct V_39 * V_18 ;
struct V_69 * V_4 ;
F_25 ( & V_48 ) ;
for (; * V_70 < V_17 -> V_18 . V_19 ; ( * V_70 ) ++ ) {
F_67 (h, n, &net->ct.hash[*bucket], hnnode) {
if ( F_128 ( V_68 ) != V_31 )
continue;
V_18 = F_52 ( V_68 ) ;
if ( F_152 ( V_18 , V_154 ) )
goto V_72;
}
}
F_67 (h, n, &net->ct.unconfirmed, hnnode) {
V_18 = F_52 ( V_68 ) ;
if ( F_152 ( V_18 , V_154 ) )
F_40 ( V_60 , & V_18 -> V_61 ) ;
}
F_29 ( & V_48 ) ;
return NULL ;
V_72:
F_76 ( & V_18 -> V_75 . V_45 ) ;
F_29 ( & V_48 ) ;
return V_18 ;
}
void F_153 ( struct V_17 * V_17 ,
int (* F_152)( struct V_39 * V_99 , void * V_154 ) ,
void * V_154 , T_1 V_62 , int V_63 )
{
struct V_39 * V_18 ;
unsigned int V_70 = 0 ;
while ( ( V_18 = F_151 ( V_17 , F_152 , V_154 , & V_70 ) ) != NULL ) {
if ( F_87 ( & V_18 -> V_46 ) )
F_43 ( V_18 , V_62 , V_63 ) ;
F_30 ( V_18 ) ;
}
}
static int F_154 ( struct V_39 * V_99 , void * V_154 )
{
return 1 ;
}
void F_155 ( void * V_14 , unsigned int V_15 )
{
if ( F_156 ( V_14 ) )
F_157 ( V_14 ) ;
else
F_158 ( ( unsigned long ) V_14 ,
F_159 ( sizeof( struct V_179 ) * V_15 ) ) ;
}
void F_160 ( struct V_17 * V_17 , T_1 V_62 , int V_63 )
{
F_153 ( V_17 , F_154 , NULL , V_62 , V_63 ) ;
}
static void F_161 ( struct V_17 * V_17 )
{
struct V_67 * V_68 ;
struct V_39 * V_18 ;
struct V_69 * V_4 ;
F_25 ( & V_48 ) ;
F_67 (h, n, &net->ct.dying, hnnode) {
V_18 = F_52 ( V_68 ) ;
F_162 ( V_18 ) ;
}
F_29 ( & V_48 ) ;
}
static int F_163 ( void )
{
int V_100 = 0 , V_180 ;
F_164 (cpu) {
struct V_39 * V_18 = & F_165 ( V_181 , V_180 ) ;
V_100 += F_21 ( & V_18 -> V_75 . V_45 ) - 1 ;
}
return V_100 ;
}
void F_166 ( void )
{
F_167 ( V_182 , NULL ) ;
}
void F_168 ( void )
{
F_167 ( V_183 , NULL ) ;
while ( F_163 () > 0 )
F_169 () ;
#ifdef F_100
F_170 ( & V_184 ) ;
#endif
F_171 () ;
F_172 () ;
F_173 () ;
F_174 () ;
F_175 () ;
F_176 () ;
F_177 () ;
F_178 () ;
F_179 () ;
}
void F_180 ( struct V_17 * V_17 )
{
F_181 ( V_185 ) ;
F_182 ( & V_17 -> V_186 , & V_185 ) ;
F_183 ( & V_185 ) ;
}
void F_183 ( struct V_187 * V_188 )
{
int V_189 ;
struct V_17 * V_17 ;
F_184 () ;
V_190:
V_189 = 0 ;
F_185 (net, net_exit_list, exit_list) {
F_153 ( V_17 , F_154 , NULL , 0 , 0 ) ;
F_161 ( V_17 ) ;
if ( F_21 ( & V_17 -> V_18 . V_106 ) != 0 )
V_189 = 1 ;
}
if ( V_189 ) {
F_169 () ;
goto V_190;
}
F_185 (net, net_exit_list, exit_list) {
F_155 ( V_17 -> V_18 . V_14 , V_17 -> V_18 . V_19 ) ;
F_186 ( V_17 ) ;
F_187 ( V_17 ) ;
F_188 ( V_17 ) ;
F_189 ( V_17 ) ;
F_190 ( V_17 ) ;
F_191 ( V_17 ) ;
F_192 ( V_17 -> V_18 . V_109 ) ;
F_193 ( V_17 -> V_18 . V_191 ) ;
F_194 ( V_17 -> V_18 . V_192 ) ;
}
}
void * F_195 ( unsigned int * V_193 , int V_194 )
{
struct V_195 * V_14 ;
unsigned int V_196 , V_99 ;
T_8 V_197 ;
F_196 ( sizeof( struct V_195 ) != sizeof( struct V_179 ) ) ;
V_196 = * V_193 = F_197 ( * V_193 , V_198 / sizeof( struct V_195 ) ) ;
V_197 = V_196 * sizeof( struct V_195 ) ;
V_14 = ( void * ) F_198 ( V_199 | V_200 | V_201 ,
F_159 ( V_197 ) ) ;
if ( ! V_14 ) {
F_199 ( V_202 L_16 ) ;
V_14 = F_200 ( V_197 ) ;
}
if ( V_14 && V_194 )
for ( V_99 = 0 ; V_99 < V_196 ; V_99 ++ )
F_201 ( & V_14 [ V_99 ] , V_99 ) ;
return V_14 ;
}
int F_202 ( const char * V_203 , struct V_204 * V_205 )
{
int V_99 , V_70 , V_206 ;
unsigned int V_207 , V_208 ;
struct V_195 * V_14 , * V_209 ;
struct V_67 * V_68 ;
struct V_39 * V_18 ;
if ( V_210 -> V_211 -> V_212 != & V_213 )
return - V_214 ;
if ( ! V_215 )
return F_203 ( V_203 , V_205 ) ;
V_206 = F_204 ( V_203 , 0 , & V_207 ) ;
if ( V_206 )
return V_206 ;
if ( ! V_207 )
return - V_174 ;
V_14 = F_195 ( & V_207 , 1 ) ;
if ( ! V_14 )
return - V_108 ;
F_25 ( & V_48 ) ;
for ( V_99 = 0 ; V_99 < V_213 . V_18 . V_19 ; V_99 ++ ) {
while ( ! F_205 ( & V_213 . V_18 . V_14 [ V_99 ] ) ) {
V_68 = F_206 ( V_213 . V_18 . V_14 [ V_99 ] . V_216 ,
struct V_67 , V_41 ) ;
V_18 = F_52 ( V_68 ) ;
F_16 ( & V_68 -> V_41 ) ;
V_70 = F_5 ( & V_68 -> V_2 , F_54 ( V_18 ) ,
V_207 ) ;
F_65 ( & V_68 -> V_41 , & V_14 [ V_70 ] ) ;
}
}
V_208 = V_213 . V_18 . V_19 ;
V_209 = V_213 . V_18 . V_14 ;
V_213 . V_18 . V_19 = V_215 = V_207 ;
V_213 . V_18 . V_14 = V_14 ;
F_29 ( & V_48 ) ;
F_155 ( V_209 , V_208 ) ;
return 0 ;
}
void F_207 ( unsigned long V_217 )
{
int V_180 ;
F_164 (cpu)
F_165 ( V_181 , V_180 ) . V_61 |= V_217 ;
}
int F_208 ( void )
{
int V_218 = 8 ;
int V_33 , V_180 ;
if ( ! V_215 ) {
V_215
= ( ( ( V_219 << V_220 ) / 16384 )
/ sizeof( struct V_179 ) ) ;
if ( V_219 > ( 1024 * 1024 * 1024 / V_198 ) )
V_215 = 16384 ;
if ( V_215 < 32 )
V_215 = 32 ;
V_218 = 4 ;
}
V_107 = V_218 * V_215 ;
F_199 ( V_221 L_17 ,
V_222 , V_215 ,
V_107 ) ;
V_33 = F_209 () ;
if ( V_33 < 0 )
goto V_223;
V_33 = F_210 () ;
if ( V_33 < 0 )
goto V_224;
V_33 = F_211 () ;
if ( V_33 < 0 )
goto V_225;
V_33 = F_212 () ;
if ( V_33 < 0 )
goto V_226;
V_33 = F_213 () ;
if ( V_33 < 0 )
goto V_227;
V_33 = F_214 () ;
if ( V_33 < 0 )
goto V_228;
V_33 = F_215 () ;
if ( V_33 < 0 )
goto V_229;
V_33 = F_216 () ;
if ( V_33 < 0 )
goto V_230;
#ifdef F_100
V_33 = F_217 ( & V_184 ) ;
if ( V_33 < 0 )
goto V_231;
#endif
V_33 = F_218 () ;
if ( V_33 < 0 )
goto V_232;
F_164 (cpu) {
struct V_39 * V_18 = & F_165 ( V_181 , V_180 ) ;
F_99 ( & V_18 -> V_113 , & V_213 ) ;
F_69 ( & V_18 -> V_75 . V_45 , 1 ) ;
}
F_207 ( V_89 | V_233 ) ;
return 0 ;
V_232:
#ifdef F_100
F_170 ( & V_184 ) ;
V_231:
#endif
F_172 () ;
V_230:
F_173 () ;
V_229:
F_174 () ;
V_228:
F_175 () ;
V_227:
F_176 () ;
V_226:
F_177 () ;
V_225:
F_178 () ;
V_224:
F_179 () ;
V_223:
return V_33 ;
}
void F_219 ( void )
{
F_167 ( V_182 , F_150 ) ;
F_167 ( V_183 , F_18 ) ;
}
int F_220 ( struct V_17 * V_17 )
{
int V_33 ;
F_69 ( & V_17 -> V_18 . V_106 , 0 ) ;
F_201 ( & V_17 -> V_18 . V_133 , V_234 ) ;
F_201 ( & V_17 -> V_18 . V_52 , V_235 ) ;
F_201 ( & V_17 -> V_18 . V_81 , V_236 ) ;
V_17 -> V_18 . V_192 = F_221 ( struct V_237 ) ;
if ( ! V_17 -> V_18 . V_192 ) {
V_33 = - V_108 ;
goto V_238;
}
V_17 -> V_18 . V_191 = F_222 ( V_199 , L_18 , V_17 ) ;
if ( ! V_17 -> V_18 . V_191 ) {
V_33 = - V_108 ;
goto V_239;
}
V_17 -> V_18 . V_109 = F_223 ( V_17 -> V_18 . V_191 ,
sizeof( struct V_39 ) , 0 ,
V_240 , NULL ) ;
if ( ! V_17 -> V_18 . V_109 ) {
F_199 ( V_241 L_19 ) ;
V_33 = - V_108 ;
goto V_242;
}
V_17 -> V_18 . V_19 = V_215 ;
V_17 -> V_18 . V_14 = F_195 ( & V_17 -> V_18 . V_19 , 1 ) ;
if ( ! V_17 -> V_18 . V_14 ) {
V_33 = - V_108 ;
F_199 ( V_241 L_20 ) ;
goto V_243;
}
V_33 = F_224 ( V_17 ) ;
if ( V_33 < 0 )
goto V_223;
V_33 = F_225 ( V_17 ) ;
if ( V_33 < 0 )
goto V_224;
V_33 = F_226 ( V_17 ) ;
if ( V_33 < 0 )
goto V_225;
V_33 = F_227 ( V_17 ) ;
if ( V_33 < 0 )
goto V_226;
V_33 = F_228 ( V_17 ) ;
if ( V_33 < 0 )
goto V_228;
V_33 = F_229 ( V_17 ) ;
if ( V_33 < 0 )
goto V_232;
return 0 ;
V_232:
F_187 ( V_17 ) ;
V_228:
F_188 ( V_17 ) ;
V_226:
F_189 ( V_17 ) ;
V_225:
F_190 ( V_17 ) ;
V_224:
F_191 ( V_17 ) ;
V_223:
F_155 ( V_17 -> V_18 . V_14 , V_17 -> V_18 . V_19 ) ;
V_243:
F_192 ( V_17 -> V_18 . V_109 ) ;
V_242:
F_193 ( V_17 -> V_18 . V_191 ) ;
V_239:
F_194 ( V_17 -> V_18 . V_192 ) ;
V_238:
return V_33 ;
}
