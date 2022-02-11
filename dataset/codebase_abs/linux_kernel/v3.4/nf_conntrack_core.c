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
if ( ! F_26 ( V_18 ) ) {
F_27 ( F_28 ( & V_18 -> V_40 [ V_31 ] . V_41 ) ) ;
F_16 ( & V_18 -> V_40 [ V_31 ] . V_41 ) ;
}
F_29 ( V_17 , V_49 ) ;
F_30 ( & V_48 ) ;
if ( V_18 -> V_50 )
F_31 ( V_18 -> V_50 ) ;
F_15 ( L_3 , V_18 ) ;
F_32 ( V_18 ) ;
}
void F_33 ( struct V_39 * V_18 )
{
struct V_17 * V_17 = F_19 ( V_18 ) ;
F_34 ( V_18 ) ;
F_25 ( & V_48 ) ;
F_29 ( V_17 , V_51 ) ;
F_14 ( V_18 ) ;
F_30 ( & V_48 ) ;
}
static void F_35 ( unsigned long V_52 )
{
struct V_39 * V_18 = ( void * ) V_52 ;
struct V_17 * V_17 = F_19 ( V_18 ) ;
if ( F_36 ( V_53 , V_18 ) < 0 ) {
V_18 -> V_46 . V_54 = V_55 +
( F_37 () % V_17 -> V_18 . V_56 ) ;
F_38 ( & V_18 -> V_46 ) ;
return;
}
F_39 ( V_57 , & V_18 -> V_58 ) ;
F_40 ( & V_48 ) ;
F_41 ( & V_18 -> V_40 [ V_31 ] . V_41 ) ;
F_42 ( & V_48 ) ;
F_31 ( V_18 ) ;
}
void F_43 ( struct V_39 * V_18 )
{
struct V_17 * V_17 = F_19 ( V_18 ) ;
F_25 ( & V_48 ) ;
F_44 ( & V_18 -> V_40 [ V_31 ] . V_41 ,
& V_17 -> V_18 . V_59 ) ;
F_30 ( & V_48 ) ;
F_45 ( & V_18 -> V_46 , F_35 , ( unsigned long ) V_18 ) ;
V_18 -> V_46 . V_54 = V_55 +
( F_37 () % V_17 -> V_18 . V_56 ) ;
F_38 ( & V_18 -> V_46 ) ;
}
static void F_46 ( unsigned long V_52 )
{
struct V_39 * V_18 = ( void * ) V_52 ;
struct V_60 * V_61 ;
V_61 = F_47 ( V_18 ) ;
if ( V_61 && V_61 -> V_62 == 0 )
V_61 -> V_62 = F_48 ( F_49 () ) ;
if ( ! F_50 ( V_57 , & V_18 -> V_58 ) &&
F_51 ( F_36 ( V_53 , V_18 ) < 0 ) ) {
F_33 ( V_18 ) ;
F_43 ( V_18 ) ;
return;
}
F_39 ( V_57 , & V_18 -> V_58 ) ;
F_33 ( V_18 ) ;
F_31 ( V_18 ) ;
}
static struct V_63 *
F_52 ( struct V_17 * V_17 , T_2 V_3 ,
const struct V_1 * V_2 , T_1 V_14 )
{
struct V_63 * V_64 ;
struct V_65 * V_4 ;
unsigned int V_66 = F_4 ( V_14 , V_17 ) ;
F_53 () ;
V_67:
F_54 (h, n, &net->ct.hash[bucket], hnnode) {
if ( F_55 ( V_2 , & V_64 -> V_2 ) &&
F_56 ( F_57 ( V_64 ) ) == V_3 ) {
F_29 ( V_17 , V_68 ) ;
F_58 () ;
return V_64 ;
}
F_29 ( V_17 , V_69 ) ;
}
if ( F_59 ( V_4 ) != V_66 ) {
F_29 ( V_17 , V_70 ) ;
goto V_67;
}
F_58 () ;
return NULL ;
}
struct V_63 *
F_60 ( struct V_17 * V_17 , T_2 V_3 ,
const struct V_1 * V_2 )
{
return F_52 ( V_17 , V_3 , V_2 ,
F_1 ( V_2 , V_3 ) ) ;
}
static struct V_63 *
F_61 ( struct V_17 * V_17 , T_2 V_3 ,
const struct V_1 * V_2 , T_1 V_14 )
{
struct V_63 * V_64 ;
struct V_39 * V_18 ;
F_9 () ;
V_67:
V_64 = F_52 ( V_17 , V_3 , V_2 , V_14 ) ;
if ( V_64 ) {
V_18 = F_57 ( V_64 ) ;
if ( F_51 ( F_62 ( V_18 ) ||
! F_63 ( & V_18 -> V_71 . V_45 ) ) )
V_64 = NULL ;
else {
if ( F_51 ( ! F_55 ( V_2 , & V_64 -> V_2 ) ||
F_56 ( V_18 ) != V_3 ) ) {
F_31 ( V_18 ) ;
goto V_67;
}
}
}
F_11 () ;
return V_64 ;
}
struct V_63 *
F_64 ( struct V_17 * V_17 , T_2 V_3 ,
const struct V_1 * V_2 )
{
return F_61 ( V_17 , V_3 , V_2 ,
F_1 ( V_2 , V_3 ) ) ;
}
static void F_65 ( struct V_39 * V_18 ,
unsigned int V_14 ,
unsigned int V_72 )
{
struct V_17 * V_17 = F_19 ( V_18 ) ;
F_66 ( & V_18 -> V_40 [ V_31 ] . V_41 ,
& V_17 -> V_18 . V_14 [ V_14 ] ) ;
F_66 ( & V_18 -> V_40 [ V_42 ] . V_41 ,
& V_17 -> V_18 . V_14 [ V_72 ] ) ;
}
int
F_67 ( struct V_39 * V_18 )
{
struct V_17 * V_17 = F_19 ( V_18 ) ;
unsigned int V_14 , V_72 ;
struct V_63 * V_64 ;
struct V_65 * V_4 ;
T_2 V_3 ;
V_3 = F_56 ( V_18 ) ;
V_14 = F_6 ( V_17 , V_3 ,
& V_18 -> V_40 [ V_31 ] . V_2 ) ;
V_72 = F_6 ( V_17 , V_3 ,
& V_18 -> V_40 [ V_42 ] . V_2 ) ;
F_25 ( & V_48 ) ;
F_68 (h, n, &net->ct.hash[hash], hnnode)
if ( F_55 ( & V_18 -> V_40 [ V_31 ] . V_2 ,
& V_64 -> V_2 ) &&
V_3 == F_56 ( F_57 ( V_64 ) ) )
goto V_73;
F_68 (h, n, &net->ct.hash[repl_hash], hnnode)
if ( F_55 ( & V_18 -> V_40 [ V_42 ] . V_2 ,
& V_64 -> V_2 ) &&
V_3 == F_56 ( F_57 ( V_64 ) ) )
goto V_73;
F_38 ( & V_18 -> V_46 ) ;
F_69 ( & V_18 -> V_71 ) ;
F_65 ( V_18 , V_14 , V_72 ) ;
F_29 ( V_17 , V_74 ) ;
F_30 ( & V_48 ) ;
return 0 ;
V_73:
F_29 ( V_17 , V_75 ) ;
F_30 ( & V_48 ) ;
return - V_76 ;
}
int
F_70 ( struct V_20 * V_21 )
{
unsigned int V_14 , V_72 ;
struct V_63 * V_64 ;
struct V_39 * V_18 ;
struct V_77 * V_78 ;
struct V_60 * V_61 ;
struct V_65 * V_4 ;
enum V_79 V_80 ;
struct V_17 * V_17 ;
T_2 V_3 ;
V_18 = F_71 ( V_21 , & V_80 ) ;
V_17 = F_19 ( V_18 ) ;
if ( F_72 ( V_80 ) != V_31 )
return V_35 ;
V_3 = F_56 ( V_18 ) ;
V_14 = * ( unsigned long * ) & V_18 -> V_40 [ V_42 ] . V_41 . V_81 ;
V_14 = F_4 ( V_14 , V_17 ) ;
V_72 = F_6 ( V_17 , V_3 ,
& V_18 -> V_40 [ V_42 ] . V_2 ) ;
F_20 ( ! F_26 ( V_18 ) ) ;
F_15 ( L_4 , V_18 ) ;
F_25 ( & V_48 ) ;
if ( F_51 ( F_62 ( V_18 ) ) ) {
F_30 ( & V_48 ) ;
return V_35 ;
}
F_68 (h, n, &net->ct.hash[hash], hnnode)
if ( F_55 ( & V_18 -> V_40 [ V_31 ] . V_2 ,
& V_64 -> V_2 ) &&
V_3 == F_56 ( F_57 ( V_64 ) ) )
goto V_73;
F_68 (h, n, &net->ct.hash[repl_hash], hnnode)
if ( F_55 ( & V_18 -> V_40 [ V_42 ] . V_2 ,
& V_64 -> V_2 ) &&
V_3 == F_56 ( F_57 ( V_64 ) ) )
goto V_73;
F_16 ( & V_18 -> V_40 [ V_31 ] . V_41 ) ;
V_18 -> V_46 . V_54 += V_55 ;
F_38 ( & V_18 -> V_46 ) ;
F_73 ( & V_18 -> V_71 . V_45 ) ;
V_18 -> V_58 |= V_82 ;
V_61 = F_47 ( V_18 ) ;
if ( V_61 ) {
if ( V_21 -> V_61 . V_83 == 0 )
F_74 ( (struct V_20 * ) V_21 ) ;
V_61 -> V_84 = F_48 ( V_21 -> V_61 ) ;
}
F_65 ( V_18 , V_14 , V_72 ) ;
F_29 ( V_17 , V_74 ) ;
F_30 ( & V_48 ) ;
V_78 = F_75 ( V_18 ) ;
if ( V_78 && V_78 -> V_85 )
F_76 ( V_86 , V_18 ) ;
F_76 ( F_77 ( V_18 ) ?
V_87 : V_88 , V_18 ) ;
return V_35 ;
V_73:
F_29 ( V_17 , V_75 ) ;
F_30 ( & V_48 ) ;
return V_89 ;
}
int
F_78 ( const struct V_1 * V_2 ,
const struct V_39 * V_90 )
{
struct V_17 * V_17 = F_19 ( V_90 ) ;
struct V_63 * V_64 ;
struct V_65 * V_4 ;
struct V_39 * V_18 ;
T_2 V_3 = F_56 ( V_90 ) ;
unsigned int V_14 = F_6 ( V_17 , V_3 , V_2 ) ;
F_79 () ;
F_54 (h, n, &net->ct.hash[hash], hnnode) {
V_18 = F_57 ( V_64 ) ;
if ( V_18 != V_90 &&
F_55 ( V_2 , & V_64 -> V_2 ) &&
F_56 ( V_18 ) == V_3 ) {
F_29 ( V_17 , V_68 ) ;
F_80 () ;
return 1 ;
}
F_29 ( V_17 , V_69 ) ;
}
F_80 () ;
return 0 ;
}
static T_6 int F_81 ( struct V_17 * V_17 , unsigned int V_14 )
{
struct V_63 * V_64 ;
struct V_39 * V_18 = NULL , * V_91 ;
struct V_65 * V_4 ;
unsigned int V_92 , V_93 = 0 ;
int V_94 = 0 ;
F_9 () ;
for ( V_92 = 0 ; V_92 < V_17 -> V_18 . V_19 ; V_92 ++ ) {
F_54 (h, n, &net->ct.hash[hash],
hnnode) {
V_91 = F_57 ( V_64 ) ;
if ( ! F_50 ( V_95 , & V_91 -> V_58 ) )
V_18 = V_91 ;
V_93 ++ ;
}
if ( V_18 != NULL ) {
if ( F_82 ( ! F_62 ( V_18 ) &&
F_63 ( & V_18 -> V_71 . V_45 ) ) )
break;
else
V_18 = NULL ;
}
if ( V_93 >= V_96 )
break;
V_14 = ( V_14 + 1 ) % V_17 -> V_18 . V_19 ;
}
F_11 () ;
if ( ! V_18 )
return V_94 ;
if ( F_83 ( & V_18 -> V_46 ) ) {
F_46 ( ( unsigned long ) V_18 ) ;
if ( F_50 ( V_57 , & V_18 -> V_58 ) ) {
V_94 = 1 ;
F_84 ( V_17 , F_81 ) ;
}
}
F_31 ( V_18 ) ;
return V_94 ;
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
const struct V_1 * V_97 ,
T_7 V_98 , T_1 V_14 )
{
struct V_39 * V_18 ;
if ( F_51 ( ! V_8 ) ) {
F_85 () ;
V_14 = F_1 ( V_37 , V_3 ) ;
}
F_73 ( & V_17 -> V_18 . V_99 ) ;
if ( V_100 &&
F_51 ( F_21 ( & V_17 -> V_18 . V_99 ) > V_100 ) ) {
if ( ! F_81 ( V_17 , F_4 ( V_14 , V_17 ) ) ) {
F_89 ( & V_17 -> V_18 . V_99 ) ;
if ( F_90 () )
F_91 ( V_101
L_5
L_6 ) ;
return F_92 ( - V_102 ) ;
}
}
V_18 = F_93 ( V_17 -> V_18 . V_103 , V_98 ) ;
if ( V_18 == NULL ) {
F_89 ( & V_17 -> V_18 . V_99 ) ;
return F_92 ( - V_102 ) ;
}
memset ( & V_18 -> V_40 [ V_104 ] , 0 ,
F_94 ( struct V_39 , V_105 ) -
F_94 ( struct V_39 , V_40 [ V_104 ] ) ) ;
F_95 ( & V_18 -> V_106 ) ;
V_18 -> V_40 [ V_31 ] . V_2 = * V_37 ;
V_18 -> V_40 [ V_31 ] . V_41 . V_81 = NULL ;
V_18 -> V_40 [ V_42 ] . V_2 = * V_97 ;
* ( unsigned long * ) ( & V_18 -> V_40 [ V_42 ] . V_41 . V_81 ) = V_14 ;
F_45 ( & V_18 -> V_46 , F_46 , ( unsigned long ) V_18 ) ;
F_96 ( & V_18 -> V_107 , V_17 ) ;
#ifdef F_97
if ( V_3 ) {
struct V_108 * F_56 ;
F_56 = F_98 ( V_18 , V_109 , V_110 ) ;
if ( ! F_56 )
goto V_111;
F_56 -> V_112 = V_3 ;
}
#endif
F_99 () ;
F_100 ( & V_18 -> V_71 . V_45 , 1 ) ;
return V_18 ;
#ifdef F_97
V_111:
F_89 ( & V_17 -> V_18 . V_99 ) ;
F_101 ( V_17 -> V_18 . V_103 , V_18 ) ;
return F_92 ( - V_102 ) ;
#endif
}
struct V_39 * F_102 ( struct V_17 * V_17 , T_2 V_3 ,
const struct V_1 * V_37 ,
const struct V_1 * V_97 ,
T_7 V_98 )
{
return F_88 ( V_17 , V_3 , V_37 , V_97 , V_98 , 0 ) ;
}
void F_32 ( struct V_39 * V_18 )
{
struct V_17 * V_17 = F_19 ( V_18 ) ;
F_103 ( V_18 ) ;
F_89 ( & V_17 -> V_18 . V_99 ) ;
F_104 ( V_18 ) ;
F_101 ( V_17 -> V_18 . V_103 , V_18 ) ;
}
static struct V_63 *
F_105 ( struct V_17 * V_17 , struct V_39 * V_113 ,
const struct V_1 * V_2 ,
struct V_25 * V_26 ,
struct V_27 * V_28 ,
struct V_20 * V_21 ,
unsigned int V_23 , T_1 V_14 )
{
struct V_39 * V_18 ;
struct V_77 * V_78 ;
struct V_1 V_114 ;
struct V_115 * V_116 ;
struct V_117 * exp ;
T_2 V_3 = V_113 ? F_56 ( V_113 ) : V_118 ;
struct V_119 * V_120 ;
unsigned int * V_121 ;
if ( ! F_13 ( & V_114 , V_2 , V_26 , V_28 ) ) {
F_15 ( L_7 ) ;
return NULL ;
}
V_18 = F_88 ( V_17 , V_3 , V_2 , & V_114 , V_110 ,
V_14 ) ;
if ( F_106 ( V_18 ) )
return (struct V_63 * ) V_18 ;
V_120 = V_113 ? F_107 ( V_113 ) : NULL ;
if ( V_120 )
V_121 = F_108 ( V_120 ) ;
else
V_121 = V_28 -> V_122 ( V_17 ) ;
if ( ! V_28 -> V_123 ( V_18 , V_21 , V_23 , V_121 ) ) {
F_32 ( V_18 ) ;
F_15 ( L_8 ) ;
return NULL ;
}
if ( V_120 )
F_109 ( V_18 , V_120 -> V_46 , V_110 ) ;
F_110 ( V_18 , V_110 ) ;
F_111 ( V_18 , V_110 ) ;
V_116 = V_113 ? F_112 ( V_113 ) : NULL ;
F_113 ( V_18 , V_116 ? V_116 -> V_124 : 0 ,
V_116 ? V_116 -> V_125 : 0 ,
V_110 ) ;
F_25 ( & V_48 ) ;
exp = F_114 ( V_17 , V_3 , V_2 ) ;
if ( exp ) {
F_15 ( L_9 ,
V_18 , exp ) ;
F_115 ( V_126 , & V_18 -> V_58 ) ;
V_18 -> V_50 = exp -> V_50 ;
if ( exp -> V_85 ) {
V_78 = F_116 ( V_18 , V_110 ) ;
if ( V_78 )
F_117 ( V_78 -> V_85 , exp -> V_85 ) ;
}
#ifdef F_118
V_18 -> V_127 = exp -> V_50 -> V_127 ;
#endif
#ifdef F_119
V_18 -> V_128 = exp -> V_50 -> V_128 ;
#endif
F_69 ( & V_18 -> V_50 -> V_71 ) ;
F_29 ( V_17 , V_129 ) ;
} else {
F_120 ( V_18 , V_113 , V_110 ) ;
F_29 ( V_17 , V_123 ) ;
}
F_66 ( & V_18 -> V_40 [ V_31 ] . V_41 ,
& V_17 -> V_18 . V_130 ) ;
F_30 ( & V_48 ) ;
if ( exp ) {
if ( exp -> V_131 )
exp -> V_131 ( V_18 , exp ) ;
F_121 ( exp ) ;
}
return & V_18 -> V_40 [ V_31 ] ;
}
static inline struct V_39 *
F_122 ( struct V_17 * V_17 , struct V_39 * V_113 ,
struct V_20 * V_21 ,
unsigned int V_23 ,
T_4 V_24 ,
T_5 V_13 ,
struct V_25 * V_26 ,
struct V_27 * V_28 ,
int * V_132 ,
enum V_79 * V_80 )
{
struct V_1 V_2 ;
struct V_63 * V_64 ;
struct V_39 * V_18 ;
T_2 V_3 = V_113 ? F_56 ( V_113 ) : V_118 ;
T_1 V_14 ;
if ( ! F_7 ( V_21 , F_123 ( V_21 ) ,
V_23 , V_24 , V_13 , & V_2 , V_26 ,
V_28 ) ) {
F_15 ( L_10 ) ;
return NULL ;
}
V_14 = F_1 ( & V_2 , V_3 ) ;
V_64 = F_61 ( V_17 , V_3 , & V_2 , V_14 ) ;
if ( ! V_64 ) {
V_64 = F_105 ( V_17 , V_113 , & V_2 , V_26 , V_28 ,
V_21 , V_23 , V_14 ) ;
if ( ! V_64 )
return NULL ;
if ( F_106 ( V_64 ) )
return ( void * ) V_64 ;
}
V_18 = F_57 ( V_64 ) ;
if ( F_124 ( V_64 ) == V_42 ) {
* V_80 = V_133 ;
* V_132 = 1 ;
} else {
if ( F_50 ( V_134 , & V_18 -> V_58 ) ) {
F_15 ( L_11 , V_18 ) ;
* V_80 = V_135 ;
} else if ( F_50 ( V_126 , & V_18 -> V_58 ) ) {
F_15 ( L_12 ,
V_18 ) ;
* V_80 = V_136 ;
} else {
F_15 ( L_13 , V_18 ) ;
* V_80 = V_137 ;
}
* V_132 = 0 ;
}
V_21 -> V_44 = & V_18 -> V_71 ;
V_21 -> V_138 = * V_80 ;
return V_18 ;
}
unsigned int
F_125 ( struct V_17 * V_17 , T_5 V_139 , unsigned int V_140 ,
struct V_20 * V_21 )
{
struct V_39 * V_18 , * V_113 = NULL ;
enum V_79 V_80 ;
struct V_25 * V_26 ;
struct V_27 * V_28 ;
struct V_119 * V_120 ;
unsigned int * V_121 ;
unsigned int V_23 ;
T_5 V_13 ;
int V_132 = 0 ;
int V_33 ;
if ( V_21 -> V_44 ) {
V_113 = (struct V_39 * ) V_21 -> V_44 ;
if ( ! F_126 ( V_113 ) ) {
F_84 ( V_17 , V_141 ) ;
return V_35 ;
}
V_21 -> V_44 = NULL ;
}
V_26 = F_10 ( V_139 ) ;
V_33 = V_26 -> V_34 ( V_21 , F_123 ( V_21 ) ,
& V_23 , & V_13 ) ;
if ( V_33 <= 0 ) {
F_15 ( L_14 ) ;
F_84 ( V_17 , error ) ;
F_84 ( V_17 , V_142 ) ;
V_33 = - V_33 ;
goto V_73;
}
V_28 = F_12 ( V_139 , V_13 ) ;
if ( V_28 -> error != NULL ) {
V_33 = V_28 -> error ( V_17 , V_113 , V_21 , V_23 , & V_80 ,
V_139 , V_140 ) ;
if ( V_33 <= 0 ) {
F_84 ( V_17 , error ) ;
F_84 ( V_17 , V_142 ) ;
V_33 = - V_33 ;
goto V_73;
}
if ( V_21 -> V_44 )
goto V_73;
}
V_18 = F_122 ( V_17 , V_113 , V_21 , V_23 , V_139 , V_13 ,
V_26 , V_28 , & V_132 , & V_80 ) ;
if ( ! V_18 ) {
F_84 ( V_17 , V_142 ) ;
V_33 = V_35 ;
goto V_73;
}
if ( F_106 ( V_18 ) ) {
F_84 ( V_17 , V_143 ) ;
V_33 = V_89 ;
goto V_73;
}
F_20 ( V_21 -> V_44 ) ;
V_120 = F_107 ( V_18 ) ;
if ( V_120 )
V_121 = F_108 ( V_120 ) ;
else
V_121 = V_28 -> V_122 ( V_17 ) ;
V_33 = V_28 -> V_144 ( V_18 , V_21 , V_23 , V_80 , V_139 , V_140 , V_121 ) ;
if ( V_33 <= 0 ) {
F_15 ( L_15 ) ;
F_127 ( V_21 -> V_44 ) ;
V_21 -> V_44 = NULL ;
F_84 ( V_17 , V_142 ) ;
if ( V_33 == - V_89 )
F_84 ( V_17 , V_143 ) ;
V_33 = - V_33 ;
goto V_73;
}
if ( V_132 && ! F_128 ( V_134 , & V_18 -> V_58 ) )
F_76 ( V_145 , V_18 ) ;
V_73:
if ( V_113 ) {
if ( V_33 == V_146 )
V_21 -> V_44 = (struct V_43 * ) V_113 ;
else
F_31 ( V_113 ) ;
}
return V_33 ;
}
bool F_129 ( struct V_1 * V_36 ,
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
void F_130 ( struct V_39 * V_18 ,
const struct V_1 * V_147 )
{
struct V_77 * V_78 = F_75 ( V_18 ) ;
F_20 ( ! F_26 ( V_18 ) ) ;
F_15 ( L_16 , V_18 ) ;
F_131 ( V_147 ) ;
V_18 -> V_40 [ V_42 ] . V_2 = * V_147 ;
if ( V_18 -> V_50 || ( V_78 && ! F_132 ( & V_78 -> V_148 ) ) )
return;
F_9 () ;
F_120 ( V_18 , NULL , V_110 ) ;
F_11 () ;
}
void F_133 ( struct V_39 * V_18 ,
enum V_79 V_80 ,
const struct V_20 * V_21 ,
unsigned long V_149 ,
int V_150 )
{
F_20 ( V_18 -> V_46 . V_151 == ( unsigned long ) V_18 ) ;
F_20 ( V_21 ) ;
if ( F_50 ( V_152 , & V_18 -> V_58 ) )
goto V_153;
if ( ! F_26 ( V_18 ) ) {
V_18 -> V_46 . V_54 = V_149 ;
} else {
unsigned long V_154 = V_55 + V_149 ;
if ( V_154 - V_18 -> V_46 . V_54 >= V_155 )
F_134 ( & V_18 -> V_46 , V_154 ) ;
}
V_153:
if ( V_150 ) {
struct V_156 * V_153 ;
V_153 = F_135 ( V_18 ) ;
if ( V_153 ) {
F_136 ( & V_153 [ F_72 ( V_80 ) ] . V_157 ) ;
F_137 ( V_21 -> V_158 , & V_153 [ F_72 ( V_80 ) ] . V_159 ) ;
}
}
}
bool F_138 ( struct V_39 * V_18 ,
enum V_79 V_80 ,
const struct V_20 * V_21 ,
int V_150 )
{
if ( V_150 ) {
struct V_156 * V_153 ;
V_153 = F_135 ( V_18 ) ;
if ( V_153 ) {
F_136 ( & V_153 [ F_72 ( V_80 ) ] . V_157 ) ;
F_137 ( V_21 -> V_158 - F_123 ( V_21 ) ,
& V_153 [ F_72 ( V_80 ) ] . V_159 ) ;
}
}
if ( F_83 ( & V_18 -> V_46 ) ) {
V_18 -> V_46 . V_160 ( ( unsigned long ) V_18 ) ;
return true ;
}
return false ;
}
int F_139 ( struct V_20 * V_21 ,
const struct V_1 * V_2 )
{
F_140 ( V_21 , V_161 , V_2 -> V_5 . V_11 . V_162 . V_163 ) ;
F_140 ( V_21 , V_164 , V_2 -> V_6 . V_11 . V_162 . V_163 ) ;
return 0 ;
V_165:
return - 1 ;
}
int F_141 ( struct V_166 * V_167 [] ,
struct V_1 * V_168 )
{
if ( ! V_167 [ V_161 ] || ! V_167 [ V_164 ] )
return - V_169 ;
V_168 -> V_5 . V_11 . V_162 . V_163 = F_142 ( V_167 [ V_161 ] ) ;
V_168 -> V_6 . V_11 . V_162 . V_163 = F_142 ( V_167 [ V_164 ] ) ;
return 0 ;
}
int F_143 ( void )
{
return F_144 ( V_170 , V_171 + 1 ) ;
}
static void F_145 ( struct V_20 * V_172 , struct V_20 * V_21 )
{
struct V_39 * V_18 ;
enum V_79 V_80 ;
V_18 = F_71 ( V_21 , & V_80 ) ;
if ( F_72 ( V_80 ) == V_31 )
V_80 = V_173 ;
else
V_80 = V_136 ;
V_172 -> V_44 = & V_18 -> V_71 ;
V_172 -> V_138 = V_80 ;
F_69 ( V_172 -> V_44 ) ;
}
static struct V_39 *
F_146 ( struct V_17 * V_17 , int (* F_147)( struct V_39 * V_92 , void * V_151 ) ,
void * V_151 , unsigned int * V_66 )
{
struct V_63 * V_64 ;
struct V_39 * V_18 ;
struct V_65 * V_4 ;
F_25 ( & V_48 ) ;
for (; * V_66 < V_17 -> V_18 . V_19 ; ( * V_66 ) ++ ) {
F_68 (h, n, &net->ct.hash[*bucket], hnnode) {
V_18 = F_57 ( V_64 ) ;
if ( F_147 ( V_18 , V_151 ) )
goto V_68;
}
}
F_68 (h, n, &net->ct.unconfirmed, hnnode) {
V_18 = F_57 ( V_64 ) ;
if ( F_147 ( V_18 , V_151 ) )
F_39 ( V_57 , & V_18 -> V_58 ) ;
}
F_30 ( & V_48 ) ;
return NULL ;
V_68:
F_73 ( & V_18 -> V_71 . V_45 ) ;
F_30 ( & V_48 ) ;
return V_18 ;
}
void F_148 ( struct V_17 * V_17 ,
int (* F_147)( struct V_39 * V_92 , void * V_151 ) ,
void * V_151 )
{
struct V_39 * V_18 ;
unsigned int V_66 = 0 ;
while ( ( V_18 = F_146 ( V_17 , F_147 , V_151 , & V_66 ) ) != NULL ) {
if ( F_83 ( & V_18 -> V_46 ) )
F_46 ( ( unsigned long ) V_18 ) ;
F_31 ( V_18 ) ;
}
}
static int F_149 ( struct V_39 * V_92 , void * V_151 )
{
struct V_174 * V_175 = (struct V_174 * ) V_151 ;
struct V_60 * V_61 ;
V_61 = F_47 ( V_92 ) ;
if ( V_61 && V_61 -> V_62 == 0 )
V_61 -> V_62 = F_48 ( F_49 () ) ;
if ( F_150 ( V_53 , V_92 ,
V_175 -> V_176 , V_175 -> V_177 ) < 0 )
return 1 ;
F_39 ( V_57 , & V_92 -> V_58 ) ;
return 1 ;
}
static int F_151 ( struct V_39 * V_92 , void * V_151 )
{
return 1 ;
}
void F_152 ( void * V_14 , unsigned int V_15 )
{
if ( F_153 ( V_14 ) )
F_154 ( V_14 ) ;
else
F_155 ( ( unsigned long ) V_14 ,
F_156 ( sizeof( struct V_178 ) * V_15 ) ) ;
}
void F_157 ( struct V_17 * V_17 , T_1 V_176 , int V_177 )
{
struct V_174 V_175 = {
. V_176 = V_176 ,
. V_177 = V_177 ,
} ;
F_148 ( V_17 , F_149 , & V_175 ) ;
}
static void F_158 ( struct V_17 * V_17 )
{
struct V_63 * V_64 ;
struct V_39 * V_18 ;
struct V_65 * V_4 ;
F_25 ( & V_48 ) ;
F_68 (h, n, &net->ct.dying, hnnode) {
V_18 = F_57 ( V_64 ) ;
F_159 ( V_18 ) ;
}
F_30 ( & V_48 ) ;
}
static int F_160 ( void )
{
int V_93 = 0 , V_179 ;
F_161 (cpu) {
struct V_39 * V_18 = & F_162 ( V_180 , V_179 ) ;
V_93 += F_21 ( & V_18 -> V_71 . V_45 ) - 1 ;
}
return V_93 ;
}
static void F_163 ( void )
{
while ( F_160 () > 0 )
F_164 () ;
F_165 () ;
F_166 () ;
#ifdef F_97
F_167 ( & V_181 ) ;
#endif
}
static void F_168 ( struct V_17 * V_17 )
{
V_182:
F_148 ( V_17 , F_151 , NULL ) ;
F_158 ( V_17 ) ;
if ( F_21 ( & V_17 -> V_18 . V_99 ) != 0 ) {
F_164 () ;
goto V_182;
}
F_152 ( V_17 -> V_18 . V_14 , V_17 -> V_18 . V_19 ) ;
F_169 ( V_17 ) ;
F_170 ( V_17 ) ;
F_171 ( V_17 ) ;
F_172 ( V_17 ) ;
F_173 ( V_17 ) ;
F_174 ( V_17 -> V_18 . V_103 ) ;
F_175 ( V_17 -> V_18 . V_183 ) ;
F_176 ( V_17 -> V_18 . V_184 ) ;
}
void F_177 ( struct V_17 * V_17 )
{
if ( F_178 ( V_17 , & V_185 ) )
F_179 ( V_186 , NULL ) ;
F_180 () ;
F_168 ( V_17 ) ;
if ( F_178 ( V_17 , & V_185 ) ) {
F_179 ( V_187 , NULL ) ;
F_163 () ;
}
}
void * F_181 ( unsigned int * V_188 , int V_189 )
{
struct V_190 * V_14 ;
unsigned int V_191 , V_92 ;
T_8 V_192 ;
F_182 ( sizeof( struct V_190 ) != sizeof( struct V_178 ) ) ;
V_191 = * V_188 = F_183 ( * V_188 , V_193 / sizeof( struct V_190 ) ) ;
V_192 = V_191 * sizeof( struct V_190 ) ;
V_14 = ( void * ) F_184 ( V_194 | V_195 | V_196 ,
F_156 ( V_192 ) ) ;
if ( ! V_14 ) {
F_91 ( V_101 L_17 ) ;
V_14 = F_185 ( V_192 ) ;
}
if ( V_14 && V_189 )
for ( V_92 = 0 ; V_92 < V_191 ; V_92 ++ )
F_186 ( & V_14 [ V_92 ] , V_92 ) ;
return V_14 ;
}
int F_187 ( const char * V_197 , struct V_198 * V_199 )
{
int V_92 , V_66 ;
unsigned int V_200 , V_201 ;
struct V_190 * V_14 , * V_202 ;
struct V_63 * V_64 ;
struct V_39 * V_18 ;
if ( V_203 -> V_204 -> V_205 != & V_185 )
return - V_206 ;
if ( ! V_207 )
return F_188 ( V_197 , V_199 ) ;
V_200 = F_189 ( V_197 , NULL , 0 ) ;
if ( ! V_200 )
return - V_169 ;
V_14 = F_181 ( & V_200 , 1 ) ;
if ( ! V_14 )
return - V_102 ;
F_25 ( & V_48 ) ;
for ( V_92 = 0 ; V_92 < V_185 . V_18 . V_19 ; V_92 ++ ) {
while ( ! F_190 ( & V_185 . V_18 . V_14 [ V_92 ] ) ) {
V_64 = F_191 ( V_185 . V_18 . V_14 [ V_92 ] . V_208 ,
struct V_63 , V_41 ) ;
V_18 = F_57 ( V_64 ) ;
F_16 ( & V_64 -> V_41 ) ;
V_66 = F_5 ( & V_64 -> V_2 , F_56 ( V_18 ) ,
V_200 ) ;
F_66 ( & V_64 -> V_41 , & V_14 [ V_66 ] ) ;
}
}
V_201 = V_185 . V_18 . V_19 ;
V_202 = V_185 . V_18 . V_14 ;
V_185 . V_18 . V_19 = V_207 = V_200 ;
V_185 . V_18 . V_14 = V_14 ;
F_30 ( & V_48 ) ;
F_152 ( V_202 , V_201 ) ;
return 0 ;
}
void F_192 ( unsigned long V_209 )
{
int V_179 ;
F_161 (cpu)
F_162 ( V_180 , V_179 ) . V_58 |= V_209 ;
}
static int F_193 ( void )
{
int V_210 = 8 ;
int V_33 , V_179 ;
if ( ! V_207 ) {
V_207
= ( ( ( V_211 << V_212 ) / 16384 )
/ sizeof( struct V_178 ) ) ;
if ( V_211 > ( 1024 * 1024 * 1024 / V_193 ) )
V_207 = 16384 ;
if ( V_207 < 32 )
V_207 = 32 ;
V_210 = 4 ;
}
V_100 = V_210 * V_207 ;
F_91 ( V_213 L_18 ,
V_214 , V_207 ,
V_100 ) ;
V_33 = F_194 () ;
if ( V_33 < 0 )
goto V_215;
V_33 = F_195 () ;
if ( V_33 < 0 )
goto V_216;
#ifdef F_97
V_33 = F_196 ( & V_181 ) ;
if ( V_33 < 0 )
goto V_217;
#endif
F_161 (cpu) {
struct V_39 * V_18 = & F_162 ( V_180 , V_179 ) ;
F_96 ( & V_18 -> V_107 , & V_185 ) ;
F_100 ( & V_18 -> V_71 . V_45 , 1 ) ;
}
F_192 ( V_82 | V_218 ) ;
return 0 ;
#ifdef F_97
V_217:
F_165 () ;
#endif
V_216:
F_166 () ;
V_215:
return V_33 ;
}
static int F_197 ( struct V_17 * V_17 )
{
int V_33 ;
F_100 ( & V_17 -> V_18 . V_99 , 0 ) ;
F_186 ( & V_17 -> V_18 . V_130 , V_219 ) ;
F_186 ( & V_17 -> V_18 . V_59 , V_220 ) ;
V_17 -> V_18 . V_184 = F_198 ( struct V_221 ) ;
if ( ! V_17 -> V_18 . V_184 ) {
V_33 = - V_102 ;
goto V_222;
}
V_17 -> V_18 . V_183 = F_199 ( V_194 , L_19 , V_17 ) ;
if ( ! V_17 -> V_18 . V_183 ) {
V_33 = - V_102 ;
goto V_223;
}
V_17 -> V_18 . V_103 = F_200 ( V_17 -> V_18 . V_183 ,
sizeof( struct V_39 ) , 0 ,
V_224 , NULL ) ;
if ( ! V_17 -> V_18 . V_103 ) {
F_91 ( V_225 L_20 ) ;
V_33 = - V_102 ;
goto V_226;
}
V_17 -> V_18 . V_19 = V_207 ;
V_17 -> V_18 . V_14 = F_181 ( & V_17 -> V_18 . V_19 , 1 ) ;
if ( ! V_17 -> V_18 . V_14 ) {
V_33 = - V_102 ;
F_91 ( V_225 L_21 ) ;
goto V_227;
}
V_33 = F_201 ( V_17 ) ;
if ( V_33 < 0 )
goto V_228;
V_33 = F_202 ( V_17 ) ;
if ( V_33 < 0 )
goto V_229;
V_33 = F_203 ( V_17 ) ;
if ( V_33 < 0 )
goto V_230;
V_33 = F_204 ( V_17 ) ;
if ( V_33 < 0 )
goto V_231;
V_33 = F_205 ( V_17 ) ;
if ( V_33 < 0 )
goto V_232;
return 0 ;
V_232:
F_170 ( V_17 ) ;
V_231:
F_171 ( V_17 ) ;
V_230:
F_172 ( V_17 ) ;
V_229:
F_173 ( V_17 ) ;
V_228:
F_152 ( V_17 -> V_18 . V_14 , V_17 -> V_18 . V_19 ) ;
V_227:
F_174 ( V_17 -> V_18 . V_103 ) ;
V_226:
F_175 ( V_17 -> V_18 . V_183 ) ;
V_223:
F_176 ( V_17 -> V_18 . V_184 ) ;
V_222:
return V_33 ;
}
int F_206 ( struct V_17 * V_17 )
{
int V_33 ;
if ( F_178 ( V_17 , & V_185 ) ) {
V_33 = F_193 () ;
if ( V_33 < 0 )
goto V_233;
}
V_33 = F_197 ( V_17 ) ;
if ( V_33 < 0 )
goto V_234;
if ( F_178 ( V_17 , & V_185 ) ) {
F_179 ( V_186 , F_145 ) ;
F_179 ( V_187 , F_18 ) ;
F_179 ( V_235 , NULL ) ;
}
return 0 ;
V_234:
if ( F_178 ( V_17 , & V_185 ) )
F_163 () ;
V_233:
return V_33 ;
}
