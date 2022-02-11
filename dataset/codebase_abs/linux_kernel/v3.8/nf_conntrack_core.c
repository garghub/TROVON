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
void F_32 ( struct V_39 * V_18 )
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
void F_41 ( struct V_39 * V_18 )
{
struct V_17 * V_17 = F_19 ( V_18 ) ;
struct V_54 * V_55 = F_36 ( V_18 ) ;
F_26 ( V_55 == NULL ) ;
F_42 ( & V_55 -> V_46 , F_35 , ( unsigned long ) V_18 ) ;
V_55 -> V_46 . V_57 = V_58 +
( F_38 () % V_17 -> V_18 . V_59 ) ;
F_39 ( & V_55 -> V_46 ) ;
}
static void F_43 ( unsigned long V_53 )
{
struct V_39 * V_18 = ( void * ) V_53 ;
struct V_62 * V_63 ;
V_63 = F_44 ( V_18 ) ;
if ( V_63 && V_63 -> V_64 == 0 )
V_63 -> V_64 = F_45 ( F_46 () ) ;
if ( ! F_47 ( V_60 , & V_18 -> V_61 ) &&
F_48 ( F_37 ( V_56 , V_18 ) < 0 ) ) {
F_32 ( V_18 ) ;
F_41 ( V_18 ) ;
return;
}
F_40 ( V_60 , & V_18 -> V_61 ) ;
F_32 ( V_18 ) ;
F_30 ( V_18 ) ;
}
static struct V_65 *
F_49 ( struct V_17 * V_17 , T_2 V_3 ,
const struct V_1 * V_2 , T_1 V_14 )
{
struct V_65 * V_66 ;
struct V_67 * V_4 ;
unsigned int V_68 = F_4 ( V_14 , V_17 ) ;
F_50 () ;
V_69:
F_51 (h, n, &net->ct.hash[bucket], hnnode) {
if ( F_52 ( V_2 , & V_66 -> V_2 ) &&
F_53 ( F_54 ( V_66 ) ) == V_3 ) {
F_28 ( V_17 , V_70 ) ;
F_55 () ;
return V_66 ;
}
F_28 ( V_17 , V_71 ) ;
}
if ( F_56 ( V_4 ) != V_68 ) {
F_28 ( V_17 , V_72 ) ;
goto V_69;
}
F_55 () ;
return NULL ;
}
struct V_65 *
F_57 ( struct V_17 * V_17 , T_2 V_3 ,
const struct V_1 * V_2 )
{
return F_49 ( V_17 , V_3 , V_2 ,
F_1 ( V_2 , V_3 ) ) ;
}
static struct V_65 *
F_58 ( struct V_17 * V_17 , T_2 V_3 ,
const struct V_1 * V_2 , T_1 V_14 )
{
struct V_65 * V_66 ;
struct V_39 * V_18 ;
F_9 () ;
V_69:
V_66 = F_49 ( V_17 , V_3 , V_2 , V_14 ) ;
if ( V_66 ) {
V_18 = F_54 ( V_66 ) ;
if ( F_48 ( F_59 ( V_18 ) ||
! F_60 ( & V_18 -> V_73 . V_45 ) ) )
V_66 = NULL ;
else {
if ( F_48 ( ! F_52 ( V_2 , & V_66 -> V_2 ) ||
F_53 ( V_18 ) != V_3 ) ) {
F_30 ( V_18 ) ;
goto V_69;
}
}
}
F_11 () ;
return V_66 ;
}
struct V_65 *
F_61 ( struct V_17 * V_17 , T_2 V_3 ,
const struct V_1 * V_2 )
{
return F_58 ( V_17 , V_3 , V_2 ,
F_1 ( V_2 , V_3 ) ) ;
}
static void F_62 ( struct V_39 * V_18 ,
unsigned int V_14 ,
unsigned int V_74 )
{
struct V_17 * V_17 = F_19 ( V_18 ) ;
F_63 ( & V_18 -> V_40 [ V_31 ] . V_41 ,
& V_17 -> V_18 . V_14 [ V_14 ] ) ;
F_63 ( & V_18 -> V_40 [ V_42 ] . V_41 ,
& V_17 -> V_18 . V_14 [ V_74 ] ) ;
}
int
F_64 ( struct V_39 * V_18 )
{
struct V_17 * V_17 = F_19 ( V_18 ) ;
unsigned int V_14 , V_74 ;
struct V_65 * V_66 ;
struct V_67 * V_4 ;
T_2 V_3 ;
V_3 = F_53 ( V_18 ) ;
V_14 = F_6 ( V_17 , V_3 ,
& V_18 -> V_40 [ V_31 ] . V_2 ) ;
V_74 = F_6 ( V_17 , V_3 ,
& V_18 -> V_40 [ V_42 ] . V_2 ) ;
F_25 ( & V_48 ) ;
F_65 (h, n, &net->ct.hash[hash], hnnode)
if ( F_52 ( & V_18 -> V_40 [ V_31 ] . V_2 ,
& V_66 -> V_2 ) &&
V_3 == F_53 ( F_54 ( V_66 ) ) )
goto V_75;
F_65 (h, n, &net->ct.hash[repl_hash], hnnode)
if ( F_52 ( & V_18 -> V_40 [ V_42 ] . V_2 ,
& V_66 -> V_2 ) &&
V_3 == F_53 ( F_54 ( V_66 ) ) )
goto V_75;
F_39 ( & V_18 -> V_46 ) ;
F_66 ( & V_18 -> V_73 ) ;
F_62 ( V_18 , V_14 , V_74 ) ;
F_28 ( V_17 , V_76 ) ;
F_29 ( & V_48 ) ;
return 0 ;
V_75:
F_28 ( V_17 , V_77 ) ;
F_29 ( & V_48 ) ;
return - V_78 ;
}
int
F_67 ( struct V_20 * V_21 )
{
unsigned int V_14 , V_74 ;
struct V_65 * V_66 ;
struct V_39 * V_18 ;
struct V_79 * V_80 ;
struct V_62 * V_63 ;
struct V_67 * V_4 ;
enum V_81 V_82 ;
struct V_17 * V_17 ;
T_2 V_3 ;
V_18 = F_68 ( V_21 , & V_82 ) ;
V_17 = F_19 ( V_18 ) ;
if ( F_69 ( V_82 ) != V_31 )
return V_35 ;
V_3 = F_53 ( V_18 ) ;
V_14 = * ( unsigned long * ) & V_18 -> V_40 [ V_42 ] . V_41 . V_83 ;
V_14 = F_4 ( V_14 , V_17 ) ;
V_74 = F_6 ( V_17 , V_3 ,
& V_18 -> V_40 [ V_42 ] . V_2 ) ;
F_20 ( ! F_70 ( V_18 ) ) ;
F_15 ( L_4 , V_18 ) ;
F_25 ( & V_48 ) ;
if ( F_48 ( F_59 ( V_18 ) ) ) {
F_29 ( & V_48 ) ;
return V_35 ;
}
F_65 (h, n, &net->ct.hash[hash], hnnode)
if ( F_52 ( & V_18 -> V_40 [ V_31 ] . V_2 ,
& V_66 -> V_2 ) &&
V_3 == F_53 ( F_54 ( V_66 ) ) )
goto V_75;
F_65 (h, n, &net->ct.hash[repl_hash], hnnode)
if ( F_52 ( & V_18 -> V_40 [ V_42 ] . V_2 ,
& V_66 -> V_2 ) &&
V_3 == F_53 ( F_54 ( V_66 ) ) )
goto V_75;
F_16 ( & V_18 -> V_40 [ V_31 ] . V_41 ) ;
V_18 -> V_46 . V_57 += V_58 ;
F_39 ( & V_18 -> V_46 ) ;
F_71 ( & V_18 -> V_73 . V_45 ) ;
V_18 -> V_61 |= V_84 ;
V_63 = F_44 ( V_18 ) ;
if ( V_63 ) {
if ( V_21 -> V_63 . V_85 == 0 )
F_72 ( V_21 ) ;
V_63 -> V_86 = F_45 ( V_21 -> V_63 ) ;
}
F_62 ( V_18 , V_14 , V_74 ) ;
F_28 ( V_17 , V_76 ) ;
F_29 ( & V_48 ) ;
V_80 = F_73 ( V_18 ) ;
if ( V_80 && V_80 -> V_87 )
F_74 ( V_88 , V_18 ) ;
F_74 ( F_75 ( V_18 ) ?
V_89 : V_90 , V_18 ) ;
return V_35 ;
V_75:
F_28 ( V_17 , V_77 ) ;
F_29 ( & V_48 ) ;
return V_91 ;
}
int
F_76 ( const struct V_1 * V_2 ,
const struct V_39 * V_92 )
{
struct V_17 * V_17 = F_19 ( V_92 ) ;
struct V_65 * V_66 ;
struct V_67 * V_4 ;
struct V_39 * V_18 ;
T_2 V_3 = F_53 ( V_92 ) ;
unsigned int V_14 = F_6 ( V_17 , V_3 , V_2 ) ;
F_77 () ;
F_51 (h, n, &net->ct.hash[hash], hnnode) {
V_18 = F_54 ( V_66 ) ;
if ( V_18 != V_92 &&
F_52 ( V_2 , & V_66 -> V_2 ) &&
F_53 ( V_18 ) == V_3 ) {
F_28 ( V_17 , V_70 ) ;
F_78 () ;
return 1 ;
}
F_28 ( V_17 , V_71 ) ;
}
F_78 () ;
return 0 ;
}
static T_6 int F_79 ( struct V_17 * V_17 , unsigned int V_14 )
{
struct V_65 * V_66 ;
struct V_39 * V_18 = NULL , * V_93 ;
struct V_67 * V_4 ;
unsigned int V_94 , V_95 = 0 ;
int V_96 = 0 ;
F_9 () ;
for ( V_94 = 0 ; V_94 < V_17 -> V_18 . V_19 ; V_94 ++ ) {
F_51 (h, n, &net->ct.hash[hash],
hnnode) {
V_93 = F_54 ( V_66 ) ;
if ( ! F_47 ( V_97 , & V_93 -> V_61 ) )
V_18 = V_93 ;
V_95 ++ ;
}
if ( V_18 != NULL ) {
if ( F_80 ( ! F_59 ( V_18 ) &&
F_60 ( & V_18 -> V_73 . V_45 ) ) )
break;
else
V_18 = NULL ;
}
if ( V_95 >= V_98 )
break;
V_14 = ( V_14 + 1 ) % V_17 -> V_18 . V_19 ;
}
F_11 () ;
if ( ! V_18 )
return V_96 ;
if ( F_81 ( & V_18 -> V_46 ) ) {
F_43 ( ( unsigned long ) V_18 ) ;
if ( F_47 ( V_60 , & V_18 -> V_61 ) ) {
V_96 = 1 ;
F_82 ( V_17 , F_79 ) ;
}
}
F_30 ( V_18 ) ;
return V_96 ;
}
void F_83 ( void )
{
unsigned int rand ;
do {
F_84 ( & rand , sizeof( rand ) ) ;
} while ( ! rand );
F_85 ( & V_8 , 0 , rand ) ;
}
static struct V_39 *
F_86 ( struct V_17 * V_17 , T_2 V_3 ,
const struct V_1 * V_37 ,
const struct V_1 * V_99 ,
T_7 V_100 , T_1 V_14 )
{
struct V_39 * V_18 ;
if ( F_48 ( ! V_8 ) ) {
F_83 () ;
V_14 = F_1 ( V_37 , V_3 ) ;
}
F_71 ( & V_17 -> V_18 . V_101 ) ;
if ( V_102 &&
F_48 ( F_21 ( & V_17 -> V_18 . V_101 ) > V_102 ) ) {
if ( ! F_79 ( V_17 , F_4 ( V_14 , V_17 ) ) ) {
F_87 ( & V_17 -> V_18 . V_101 ) ;
F_88 ( L_5 ) ;
return F_89 ( - V_103 ) ;
}
}
V_18 = F_90 ( V_17 -> V_18 . V_104 , V_100 ) ;
if ( V_18 == NULL ) {
F_87 ( & V_17 -> V_18 . V_101 ) ;
return F_89 ( - V_103 ) ;
}
memset ( & V_18 -> V_40 [ V_105 ] , 0 ,
F_91 ( struct V_39 , V_106 ) -
F_91 ( struct V_39 , V_40 [ V_105 ] ) ) ;
F_92 ( & V_18 -> V_107 ) ;
V_18 -> V_40 [ V_31 ] . V_2 = * V_37 ;
V_18 -> V_40 [ V_31 ] . V_41 . V_83 = NULL ;
V_18 -> V_40 [ V_42 ] . V_2 = * V_99 ;
* ( unsigned long * ) ( & V_18 -> V_40 [ V_42 ] . V_41 . V_83 ) = V_14 ;
F_42 ( & V_18 -> V_46 , F_43 , ( unsigned long ) V_18 ) ;
F_93 ( & V_18 -> V_108 , V_17 ) ;
#ifdef F_94
if ( V_3 ) {
struct V_109 * F_53 ;
F_53 = F_95 ( V_18 , V_110 , V_111 ) ;
if ( ! F_53 )
goto V_112;
F_53 -> V_113 = V_3 ;
}
#endif
F_96 () ;
F_97 ( & V_18 -> V_73 . V_45 , 1 ) ;
return V_18 ;
#ifdef F_94
V_112:
F_87 ( & V_17 -> V_18 . V_101 ) ;
F_98 ( V_17 -> V_18 . V_104 , V_18 ) ;
return F_89 ( - V_103 ) ;
#endif
}
struct V_39 * F_99 ( struct V_17 * V_17 , T_2 V_3 ,
const struct V_1 * V_37 ,
const struct V_1 * V_99 ,
T_7 V_100 )
{
return F_86 ( V_17 , V_3 , V_37 , V_99 , V_100 , 0 ) ;
}
void F_31 ( struct V_39 * V_18 )
{
struct V_17 * V_17 = F_19 ( V_18 ) ;
F_100 ( V_18 ) ;
F_87 ( & V_17 -> V_18 . V_101 ) ;
F_101 ( V_18 ) ;
F_98 ( V_17 -> V_18 . V_104 , V_18 ) ;
}
static struct V_65 *
F_102 ( struct V_17 * V_17 , struct V_39 * V_114 ,
const struct V_1 * V_2 ,
struct V_25 * V_26 ,
struct V_27 * V_28 ,
struct V_20 * V_21 ,
unsigned int V_23 , T_1 V_14 )
{
struct V_39 * V_18 ;
struct V_79 * V_80 ;
struct V_1 V_115 ;
struct V_54 * V_55 ;
struct V_116 * exp ;
T_2 V_3 = V_114 ? F_53 ( V_114 ) : V_117 ;
struct V_118 * V_119 ;
unsigned int * V_120 ;
if ( ! F_13 ( & V_115 , V_2 , V_26 , V_28 ) ) {
F_15 ( L_6 ) ;
return NULL ;
}
V_18 = F_86 ( V_17 , V_3 , V_2 , & V_115 , V_111 ,
V_14 ) ;
if ( F_103 ( V_18 ) )
return (struct V_65 * ) V_18 ;
V_119 = V_114 ? F_104 ( V_114 ) : NULL ;
if ( V_119 )
V_120 = F_105 ( V_119 ) ;
else
V_120 = V_28 -> V_121 ( V_17 ) ;
if ( ! V_28 -> V_122 ( V_18 , V_21 , V_23 , V_120 ) ) {
F_31 ( V_18 ) ;
F_15 ( L_7 ) ;
return NULL ;
}
if ( V_119 )
F_106 ( V_18 , V_119 -> V_46 , V_111 ) ;
F_107 ( V_18 , V_111 ) ;
F_108 ( V_18 , V_111 ) ;
V_55 = V_114 ? F_36 ( V_114 ) : NULL ;
F_109 ( V_18 , V_55 ? V_55 -> V_123 : 0 ,
V_55 ? V_55 -> V_124 : 0 ,
V_111 ) ;
F_25 ( & V_48 ) ;
exp = F_110 ( V_17 , V_3 , V_2 ) ;
if ( exp ) {
F_15 ( L_8 ,
V_18 , exp ) ;
F_111 ( V_125 , & V_18 -> V_61 ) ;
V_18 -> V_50 = exp -> V_50 ;
if ( exp -> V_87 ) {
V_80 = F_112 ( V_18 , exp -> V_87 ,
V_111 ) ;
if ( V_80 )
F_113 ( V_80 -> V_87 , exp -> V_87 ) ;
}
#ifdef F_114
V_18 -> V_126 = exp -> V_50 -> V_126 ;
#endif
#ifdef F_115
V_18 -> V_127 = exp -> V_50 -> V_127 ;
#endif
F_66 ( & V_18 -> V_50 -> V_73 ) ;
F_28 ( V_17 , V_128 ) ;
} else {
F_116 ( V_18 , V_114 , V_111 ) ;
F_28 ( V_17 , V_122 ) ;
}
F_63 ( & V_18 -> V_40 [ V_31 ] . V_41 ,
& V_17 -> V_18 . V_129 ) ;
F_29 ( & V_48 ) ;
if ( exp ) {
if ( exp -> V_130 )
exp -> V_130 ( V_18 , exp ) ;
F_117 ( exp ) ;
}
return & V_18 -> V_40 [ V_31 ] ;
}
static inline struct V_39 *
F_118 ( struct V_17 * V_17 , struct V_39 * V_114 ,
struct V_20 * V_21 ,
unsigned int V_23 ,
T_4 V_24 ,
T_5 V_13 ,
struct V_25 * V_26 ,
struct V_27 * V_28 ,
int * V_131 ,
enum V_81 * V_82 )
{
struct V_1 V_2 ;
struct V_65 * V_66 ;
struct V_39 * V_18 ;
T_2 V_3 = V_114 ? F_53 ( V_114 ) : V_117 ;
T_1 V_14 ;
if ( ! F_7 ( V_21 , F_119 ( V_21 ) ,
V_23 , V_24 , V_13 , & V_2 , V_26 ,
V_28 ) ) {
F_15 ( L_9 ) ;
return NULL ;
}
V_14 = F_1 ( & V_2 , V_3 ) ;
V_66 = F_58 ( V_17 , V_3 , & V_2 , V_14 ) ;
if ( ! V_66 ) {
V_66 = F_102 ( V_17 , V_114 , & V_2 , V_26 , V_28 ,
V_21 , V_23 , V_14 ) ;
if ( ! V_66 )
return NULL ;
if ( F_103 ( V_66 ) )
return ( void * ) V_66 ;
}
V_18 = F_54 ( V_66 ) ;
if ( F_120 ( V_66 ) == V_42 ) {
* V_82 = V_132 ;
* V_131 = 1 ;
} else {
if ( F_47 ( V_133 , & V_18 -> V_61 ) ) {
F_15 ( L_10 , V_18 ) ;
* V_82 = V_134 ;
} else if ( F_47 ( V_125 , & V_18 -> V_61 ) ) {
F_15 ( L_11 ,
V_18 ) ;
* V_82 = V_135 ;
} else {
F_15 ( L_12 , V_18 ) ;
* V_82 = V_136 ;
}
* V_131 = 0 ;
}
V_21 -> V_44 = & V_18 -> V_73 ;
V_21 -> V_137 = * V_82 ;
return V_18 ;
}
unsigned int
F_121 ( struct V_17 * V_17 , T_5 V_138 , unsigned int V_139 ,
struct V_20 * V_21 )
{
struct V_39 * V_18 , * V_114 = NULL ;
enum V_81 V_82 ;
struct V_25 * V_26 ;
struct V_27 * V_28 ;
unsigned int * V_120 ;
unsigned int V_23 ;
T_5 V_13 ;
int V_131 = 0 ;
int V_33 ;
if ( V_21 -> V_44 ) {
V_114 = (struct V_39 * ) V_21 -> V_44 ;
if ( ! F_122 ( V_114 ) ) {
F_82 ( V_17 , V_140 ) ;
return V_35 ;
}
V_21 -> V_44 = NULL ;
}
V_26 = F_10 ( V_138 ) ;
V_33 = V_26 -> V_34 ( V_21 , F_119 ( V_21 ) ,
& V_23 , & V_13 ) ;
if ( V_33 <= 0 ) {
F_15 ( L_13 ) ;
F_82 ( V_17 , error ) ;
F_82 ( V_17 , V_141 ) ;
V_33 = - V_33 ;
goto V_75;
}
V_28 = F_12 ( V_138 , V_13 ) ;
if ( V_28 -> error != NULL ) {
V_33 = V_28 -> error ( V_17 , V_114 , V_21 , V_23 , & V_82 ,
V_138 , V_139 ) ;
if ( V_33 <= 0 ) {
F_82 ( V_17 , error ) ;
F_82 ( V_17 , V_141 ) ;
V_33 = - V_33 ;
goto V_75;
}
if ( V_21 -> V_44 )
goto V_75;
}
V_18 = F_118 ( V_17 , V_114 , V_21 , V_23 , V_138 , V_13 ,
V_26 , V_28 , & V_131 , & V_82 ) ;
if ( ! V_18 ) {
F_82 ( V_17 , V_141 ) ;
V_33 = V_35 ;
goto V_75;
}
if ( F_103 ( V_18 ) ) {
F_82 ( V_17 , V_142 ) ;
V_33 = V_91 ;
goto V_75;
}
F_20 ( V_21 -> V_44 ) ;
V_120 = F_123 ( V_17 , V_18 , V_28 ) ;
V_33 = V_28 -> V_143 ( V_18 , V_21 , V_23 , V_82 , V_138 , V_139 , V_120 ) ;
if ( V_33 <= 0 ) {
F_15 ( L_14 ) ;
F_124 ( V_21 -> V_44 ) ;
V_21 -> V_44 = NULL ;
F_82 ( V_17 , V_141 ) ;
if ( V_33 == - V_91 )
F_82 ( V_17 , V_142 ) ;
V_33 = - V_33 ;
goto V_75;
}
if ( V_131 && ! F_125 ( V_133 , & V_18 -> V_61 ) )
F_74 ( V_144 , V_18 ) ;
V_75:
if ( V_114 ) {
if ( V_33 == V_145 )
V_21 -> V_44 = (struct V_43 * ) V_114 ;
else
F_30 ( V_114 ) ;
}
return V_33 ;
}
bool F_126 ( struct V_1 * V_36 ,
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
void F_127 ( struct V_39 * V_18 ,
const struct V_1 * V_146 )
{
struct V_79 * V_80 = F_73 ( V_18 ) ;
F_20 ( ! F_70 ( V_18 ) ) ;
F_15 ( L_15 , V_18 ) ;
F_128 ( V_146 ) ;
V_18 -> V_40 [ V_42 ] . V_2 = * V_146 ;
if ( V_18 -> V_50 || ( V_80 && ! F_129 ( & V_80 -> V_147 ) ) )
return;
F_9 () ;
F_116 ( V_18 , NULL , V_111 ) ;
F_11 () ;
}
void F_130 ( struct V_39 * V_18 ,
enum V_81 V_82 ,
const struct V_20 * V_21 ,
unsigned long V_148 ,
int V_149 )
{
F_20 ( V_18 -> V_46 . V_150 == ( unsigned long ) V_18 ) ;
F_20 ( V_21 ) ;
if ( F_47 ( V_151 , & V_18 -> V_61 ) )
goto V_152;
if ( ! F_70 ( V_18 ) ) {
V_18 -> V_46 . V_57 = V_148 ;
} else {
unsigned long V_153 = V_58 + V_148 ;
if ( V_153 - V_18 -> V_46 . V_57 >= V_154 )
F_131 ( & V_18 -> V_46 , V_153 ) ;
}
V_152:
if ( V_149 ) {
struct V_155 * V_152 ;
V_152 = F_132 ( V_18 ) ;
if ( V_152 ) {
F_133 ( & V_152 [ F_69 ( V_82 ) ] . V_156 ) ;
F_134 ( V_21 -> V_157 , & V_152 [ F_69 ( V_82 ) ] . V_158 ) ;
}
}
}
bool F_135 ( struct V_39 * V_18 ,
enum V_81 V_82 ,
const struct V_20 * V_21 ,
int V_149 )
{
if ( V_149 ) {
struct V_155 * V_152 ;
V_152 = F_132 ( V_18 ) ;
if ( V_152 ) {
F_133 ( & V_152 [ F_69 ( V_82 ) ] . V_156 ) ;
F_134 ( V_21 -> V_157 - F_119 ( V_21 ) ,
& V_152 [ F_69 ( V_82 ) ] . V_158 ) ;
}
}
if ( F_81 ( & V_18 -> V_46 ) ) {
V_18 -> V_46 . V_159 ( ( unsigned long ) V_18 ) ;
return true ;
}
return false ;
}
int F_136 ( struct V_20 * V_21 ,
const struct V_1 * V_2 )
{
if ( F_137 ( V_21 , V_160 , V_2 -> V_5 . V_11 . V_161 . V_162 ) ||
F_137 ( V_21 , V_163 , V_2 -> V_6 . V_11 . V_161 . V_162 ) )
goto V_164;
return 0 ;
V_164:
return - 1 ;
}
int F_138 ( struct V_165 * V_166 [] ,
struct V_1 * V_167 )
{
if ( ! V_166 [ V_160 ] || ! V_166 [ V_163 ] )
return - V_168 ;
V_167 -> V_5 . V_11 . V_161 . V_162 = F_139 ( V_166 [ V_160 ] ) ;
V_167 -> V_6 . V_11 . V_161 . V_162 = F_139 ( V_166 [ V_163 ] ) ;
return 0 ;
}
int F_140 ( void )
{
return F_141 ( V_169 , V_170 + 1 ) ;
}
static void F_142 ( struct V_20 * V_171 , struct V_20 * V_21 )
{
struct V_39 * V_18 ;
enum V_81 V_82 ;
V_18 = F_68 ( V_21 , & V_82 ) ;
if ( F_69 ( V_82 ) == V_31 )
V_82 = V_172 ;
else
V_82 = V_135 ;
V_171 -> V_44 = & V_18 -> V_73 ;
V_171 -> V_137 = V_82 ;
F_66 ( V_171 -> V_44 ) ;
}
static struct V_39 *
F_143 ( struct V_17 * V_17 , int (* F_144)( struct V_39 * V_94 , void * V_150 ) ,
void * V_150 , unsigned int * V_68 )
{
struct V_65 * V_66 ;
struct V_39 * V_18 ;
struct V_67 * V_4 ;
F_25 ( & V_48 ) ;
for (; * V_68 < V_17 -> V_18 . V_19 ; ( * V_68 ) ++ ) {
F_65 (h, n, &net->ct.hash[*bucket], hnnode) {
if ( F_120 ( V_66 ) != V_31 )
continue;
V_18 = F_54 ( V_66 ) ;
if ( F_144 ( V_18 , V_150 ) )
goto V_70;
}
}
F_65 (h, n, &net->ct.unconfirmed, hnnode) {
V_18 = F_54 ( V_66 ) ;
if ( F_144 ( V_18 , V_150 ) )
F_40 ( V_60 , & V_18 -> V_61 ) ;
}
F_29 ( & V_48 ) ;
return NULL ;
V_70:
F_71 ( & V_18 -> V_73 . V_45 ) ;
F_29 ( & V_48 ) ;
return V_18 ;
}
void F_145 ( struct V_17 * V_17 ,
int (* F_144)( struct V_39 * V_94 , void * V_150 ) ,
void * V_150 )
{
struct V_39 * V_18 ;
unsigned int V_68 = 0 ;
while ( ( V_18 = F_143 ( V_17 , F_144 , V_150 , & V_68 ) ) != NULL ) {
if ( F_81 ( & V_18 -> V_46 ) )
F_43 ( ( unsigned long ) V_18 ) ;
F_30 ( V_18 ) ;
}
}
static int F_146 ( struct V_39 * V_94 , void * V_150 )
{
struct V_173 * V_174 = (struct V_173 * ) V_150 ;
struct V_62 * V_63 ;
V_63 = F_44 ( V_94 ) ;
if ( V_63 && V_63 -> V_64 == 0 )
V_63 -> V_64 = F_45 ( F_46 () ) ;
if ( F_147 ( V_56 , V_94 ,
V_174 -> V_175 , V_174 -> V_176 ) < 0 )
return 1 ;
F_40 ( V_60 , & V_94 -> V_61 ) ;
return 1 ;
}
static int F_148 ( struct V_39 * V_94 , void * V_150 )
{
return 1 ;
}
void F_149 ( void * V_14 , unsigned int V_15 )
{
if ( F_150 ( V_14 ) )
F_151 ( V_14 ) ;
else
F_152 ( ( unsigned long ) V_14 ,
F_153 ( sizeof( struct V_177 ) * V_15 ) ) ;
}
void F_154 ( struct V_17 * V_17 , T_1 V_175 , int V_176 )
{
struct V_173 V_174 = {
. V_175 = V_175 ,
. V_176 = V_176 ,
} ;
F_145 ( V_17 , F_146 , & V_174 ) ;
}
static void F_155 ( struct V_17 * V_17 )
{
struct V_65 * V_66 ;
struct V_39 * V_18 ;
struct V_67 * V_4 ;
F_25 ( & V_48 ) ;
F_65 (h, n, &net->ct.dying, hnnode) {
V_18 = F_54 ( V_66 ) ;
F_156 ( V_18 ) ;
}
F_29 ( & V_48 ) ;
}
static int F_157 ( void )
{
int V_95 = 0 , V_178 ;
F_158 (cpu) {
struct V_39 * V_18 = & F_159 ( V_179 , V_178 ) ;
V_95 += F_21 ( & V_18 -> V_73 . V_45 ) - 1 ;
}
return V_95 ;
}
static void F_160 ( void )
{
while ( F_157 () > 0 )
F_161 () ;
#ifdef F_94
F_162 ( & V_180 ) ;
#endif
}
static void F_163 ( struct V_17 * V_17 )
{
V_181:
F_145 ( V_17 , F_148 , NULL ) ;
F_155 ( V_17 ) ;
if ( F_21 ( & V_17 -> V_18 . V_101 ) != 0 ) {
F_161 () ;
goto V_181;
}
F_149 ( V_17 -> V_18 . V_14 , V_17 -> V_18 . V_19 ) ;
F_164 ( V_17 ) ;
F_165 ( V_17 ) ;
F_166 ( V_17 ) ;
F_167 ( V_17 ) ;
F_168 ( V_17 ) ;
F_169 ( V_17 ) ;
F_170 ( V_17 -> V_18 . V_104 ) ;
F_171 ( V_17 -> V_18 . V_182 ) ;
F_172 ( V_17 -> V_18 . V_183 ) ;
}
void F_173 ( struct V_17 * V_17 )
{
if ( F_174 ( V_17 , & V_184 ) )
F_175 ( V_185 , NULL ) ;
F_176 () ;
F_177 ( V_17 ) ;
F_163 ( V_17 ) ;
}
void F_178 ( void )
{
F_175 ( V_186 , NULL ) ;
F_160 () ;
}
void * F_179 ( unsigned int * V_187 , int V_188 )
{
struct V_189 * V_14 ;
unsigned int V_190 , V_94 ;
T_8 V_191 ;
F_180 ( sizeof( struct V_189 ) != sizeof( struct V_177 ) ) ;
V_190 = * V_187 = F_181 ( * V_187 , V_192 / sizeof( struct V_189 ) ) ;
V_191 = V_190 * sizeof( struct V_189 ) ;
V_14 = ( void * ) F_182 ( V_193 | V_194 | V_195 ,
F_153 ( V_191 ) ) ;
if ( ! V_14 ) {
F_183 ( V_196 L_16 ) ;
V_14 = F_184 ( V_191 ) ;
}
if ( V_14 && V_188 )
for ( V_94 = 0 ; V_94 < V_190 ; V_94 ++ )
F_185 ( & V_14 [ V_94 ] , V_94 ) ;
return V_14 ;
}
int F_186 ( const char * V_197 , struct V_198 * V_199 )
{
int V_94 , V_68 , V_200 ;
unsigned int V_201 , V_202 ;
struct V_189 * V_14 , * V_203 ;
struct V_65 * V_66 ;
struct V_39 * V_18 ;
if ( V_204 -> V_205 -> V_206 != & V_184 )
return - V_207 ;
if ( ! V_208 )
return F_187 ( V_197 , V_199 ) ;
V_200 = F_188 ( V_197 , 0 , & V_201 ) ;
if ( V_200 )
return V_200 ;
if ( ! V_201 )
return - V_168 ;
V_14 = F_179 ( & V_201 , 1 ) ;
if ( ! V_14 )
return - V_103 ;
F_25 ( & V_48 ) ;
for ( V_94 = 0 ; V_94 < V_184 . V_18 . V_19 ; V_94 ++ ) {
while ( ! F_189 ( & V_184 . V_18 . V_14 [ V_94 ] ) ) {
V_66 = F_190 ( V_184 . V_18 . V_14 [ V_94 ] . V_209 ,
struct V_65 , V_41 ) ;
V_18 = F_54 ( V_66 ) ;
F_16 ( & V_66 -> V_41 ) ;
V_68 = F_5 ( & V_66 -> V_2 , F_53 ( V_18 ) ,
V_201 ) ;
F_63 ( & V_66 -> V_41 , & V_14 [ V_68 ] ) ;
}
}
V_202 = V_184 . V_18 . V_19 ;
V_203 = V_184 . V_18 . V_14 ;
V_184 . V_18 . V_19 = V_208 = V_201 ;
V_184 . V_18 . V_14 = V_14 ;
F_29 ( & V_48 ) ;
F_149 ( V_203 , V_202 ) ;
return 0 ;
}
void F_191 ( unsigned long V_210 )
{
int V_178 ;
F_158 (cpu)
F_159 ( V_179 , V_178 ) . V_61 |= V_210 ;
}
static int F_192 ( void )
{
int V_211 = 8 ;
int V_33 , V_178 ;
if ( ! V_208 ) {
V_208
= ( ( ( V_212 << V_213 ) / 16384 )
/ sizeof( struct V_177 ) ) ;
if ( V_212 > ( 1024 * 1024 * 1024 / V_192 ) )
V_208 = 16384 ;
if ( V_208 < 32 )
V_208 = 32 ;
V_211 = 4 ;
}
V_102 = V_211 * V_208 ;
F_183 ( V_214 L_17 ,
V_215 , V_208 ,
V_102 ) ;
#ifdef F_94
V_33 = F_193 ( & V_180 ) ;
if ( V_33 < 0 )
goto V_216;
#endif
F_158 (cpu) {
struct V_39 * V_18 = & F_159 ( V_179 , V_178 ) ;
F_93 ( & V_18 -> V_108 , & V_184 ) ;
F_97 ( & V_18 -> V_73 . V_45 , 1 ) ;
}
F_191 ( V_84 | V_217 ) ;
return 0 ;
#ifdef F_94
V_216:
#endif
return V_33 ;
}
static int F_194 ( struct V_17 * V_17 )
{
int V_33 ;
F_97 ( & V_17 -> V_18 . V_101 , 0 ) ;
F_185 ( & V_17 -> V_18 . V_129 , V_218 ) ;
F_185 ( & V_17 -> V_18 . V_52 , V_219 ) ;
F_185 ( & V_17 -> V_18 . V_114 , V_220 ) ;
V_17 -> V_18 . V_183 = F_195 ( struct V_221 ) ;
if ( ! V_17 -> V_18 . V_183 ) {
V_33 = - V_103 ;
goto V_222;
}
V_17 -> V_18 . V_182 = F_196 ( V_193 , L_18 , V_17 ) ;
if ( ! V_17 -> V_18 . V_182 ) {
V_33 = - V_103 ;
goto V_223;
}
V_17 -> V_18 . V_104 = F_197 ( V_17 -> V_18 . V_182 ,
sizeof( struct V_39 ) , 0 ,
V_224 , NULL ) ;
if ( ! V_17 -> V_18 . V_104 ) {
F_183 ( V_225 L_19 ) ;
V_33 = - V_103 ;
goto V_226;
}
V_17 -> V_18 . V_19 = V_208 ;
V_17 -> V_18 . V_14 = F_179 ( & V_17 -> V_18 . V_19 , 1 ) ;
if ( ! V_17 -> V_18 . V_14 ) {
V_33 = - V_103 ;
F_183 ( V_225 L_20 ) ;
goto V_227;
}
V_33 = F_198 ( V_17 ) ;
if ( V_33 < 0 )
goto V_228;
V_33 = F_199 ( V_17 ) ;
if ( V_33 < 0 )
goto V_229;
V_33 = F_200 ( V_17 ) ;
if ( V_33 < 0 )
goto V_230;
V_33 = F_201 ( V_17 ) ;
if ( V_33 < 0 )
goto V_231;
V_33 = F_202 ( V_17 ) ;
if ( V_33 < 0 )
goto V_232;
V_33 = F_203 ( V_17 ) ;
if ( V_33 < 0 )
goto V_233;
return 0 ;
V_233:
F_165 ( V_17 ) ;
V_232:
F_166 ( V_17 ) ;
V_231:
F_167 ( V_17 ) ;
V_230:
F_168 ( V_17 ) ;
V_229:
F_169 ( V_17 ) ;
V_228:
F_149 ( V_17 -> V_18 . V_14 , V_17 -> V_18 . V_19 ) ;
V_227:
F_170 ( V_17 -> V_18 . V_104 ) ;
V_226:
F_171 ( V_17 -> V_18 . V_182 ) ;
V_223:
F_172 ( V_17 -> V_18 . V_183 ) ;
V_222:
return V_33 ;
}
int F_204 ( struct V_17 * V_17 )
{
int V_33 ;
if ( F_174 ( V_17 , & V_184 ) ) {
V_33 = F_192 () ;
if ( V_33 < 0 )
goto V_234;
}
V_33 = F_205 ( V_17 ) ;
if ( V_33 < 0 )
goto V_235;
V_33 = F_194 ( V_17 ) ;
if ( V_33 < 0 )
goto V_236;
if ( F_174 ( V_17 , & V_184 ) ) {
F_175 ( V_185 , F_142 ) ;
F_175 ( V_186 , F_18 ) ;
F_175 ( V_237 , NULL ) ;
}
return 0 ;
V_236:
F_177 ( V_17 ) ;
V_235:
if ( F_174 ( V_17 , & V_184 ) )
F_160 () ;
V_234:
return V_33 ;
}
