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
void F_67 ( struct V_39 * V_18 )
{
struct V_17 * V_17 = F_19 ( V_18 ) ;
unsigned int V_14 , V_72 ;
T_2 V_3 ;
V_3 = F_56 ( V_18 ) ;
V_14 = F_6 ( V_17 , V_3 , & V_18 -> V_40 [ V_31 ] . V_2 ) ;
V_72 = F_6 ( V_17 , V_3 , & V_18 -> V_40 [ V_42 ] . V_2 ) ;
F_65 ( V_18 , V_14 , V_72 ) ;
}
int
F_68 ( struct V_20 * V_21 )
{
unsigned int V_14 , V_72 ;
struct V_63 * V_64 ;
struct V_39 * V_18 ;
struct V_73 * V_74 ;
struct V_60 * V_61 ;
struct V_65 * V_4 ;
enum V_75 V_76 ;
struct V_17 * V_17 ;
T_2 V_3 ;
V_18 = F_69 ( V_21 , & V_76 ) ;
V_17 = F_19 ( V_18 ) ;
if ( F_70 ( V_76 ) != V_31 )
return V_35 ;
V_3 = F_56 ( V_18 ) ;
V_14 = * ( unsigned long * ) & V_18 -> V_40 [ V_42 ] . V_41 . V_77 ;
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
F_71 (h, n, &net->ct.hash[hash], hnnode)
if ( F_55 ( & V_18 -> V_40 [ V_31 ] . V_2 ,
& V_64 -> V_2 ) &&
V_3 == F_56 ( F_57 ( V_64 ) ) )
goto V_78;
F_71 (h, n, &net->ct.hash[repl_hash], hnnode)
if ( F_55 ( & V_18 -> V_40 [ V_42 ] . V_2 ,
& V_64 -> V_2 ) &&
V_3 == F_56 ( F_57 ( V_64 ) ) )
goto V_78;
F_16 ( & V_18 -> V_40 [ V_31 ] . V_41 ) ;
V_18 -> V_46 . V_54 += V_55 ;
F_38 ( & V_18 -> V_46 ) ;
F_72 ( & V_18 -> V_71 . V_45 ) ;
V_18 -> V_58 |= V_79 ;
V_61 = F_47 ( V_18 ) ;
if ( V_61 ) {
if ( V_21 -> V_61 . V_80 == 0 )
F_73 ( (struct V_20 * ) V_21 ) ;
V_61 -> V_81 = F_48 ( V_21 -> V_61 ) ;
}
F_65 ( V_18 , V_14 , V_72 ) ;
F_29 ( V_17 , V_82 ) ;
F_30 ( & V_48 ) ;
V_74 = F_74 ( V_18 ) ;
if ( V_74 && V_74 -> V_83 )
F_75 ( V_84 , V_18 ) ;
F_75 ( F_76 ( V_18 ) ?
V_85 : V_86 , V_18 ) ;
return V_35 ;
V_78:
F_29 ( V_17 , V_87 ) ;
F_30 ( & V_48 ) ;
return V_88 ;
}
int
F_77 ( const struct V_1 * V_2 ,
const struct V_39 * V_89 )
{
struct V_17 * V_17 = F_19 ( V_89 ) ;
struct V_63 * V_64 ;
struct V_65 * V_4 ;
struct V_39 * V_18 ;
T_2 V_3 = F_56 ( V_89 ) ;
unsigned int V_14 = F_6 ( V_17 , V_3 , V_2 ) ;
F_78 () ;
F_54 (h, n, &net->ct.hash[hash], hnnode) {
V_18 = F_57 ( V_64 ) ;
if ( V_18 != V_89 &&
F_55 ( V_2 , & V_64 -> V_2 ) &&
F_56 ( V_18 ) == V_3 ) {
F_29 ( V_17 , V_68 ) ;
F_79 () ;
return 1 ;
}
F_29 ( V_17 , V_69 ) ;
}
F_79 () ;
return 0 ;
}
static T_6 int F_80 ( struct V_17 * V_17 , unsigned int V_14 )
{
struct V_63 * V_64 ;
struct V_39 * V_18 = NULL , * V_90 ;
struct V_65 * V_4 ;
unsigned int V_91 , V_92 = 0 ;
int V_93 = 0 ;
F_9 () ;
for ( V_91 = 0 ; V_91 < V_17 -> V_18 . V_19 ; V_91 ++ ) {
F_54 (h, n, &net->ct.hash[hash],
hnnode) {
V_90 = F_57 ( V_64 ) ;
if ( ! F_50 ( V_94 , & V_90 -> V_58 ) )
V_18 = V_90 ;
V_92 ++ ;
}
if ( V_18 != NULL ) {
if ( F_81 ( ! F_62 ( V_18 ) &&
F_63 ( & V_18 -> V_71 . V_45 ) ) )
break;
else
V_18 = NULL ;
}
if ( V_92 >= V_95 )
break;
V_14 = ( V_14 + 1 ) % V_17 -> V_18 . V_19 ;
}
F_11 () ;
if ( ! V_18 )
return V_93 ;
if ( F_82 ( & V_18 -> V_46 ) ) {
F_46 ( ( unsigned long ) V_18 ) ;
V_93 = 1 ;
F_83 ( V_17 , F_80 ) ;
}
F_31 ( V_18 ) ;
return V_93 ;
}
void F_84 ( void )
{
unsigned int rand ;
do {
F_85 ( & rand , sizeof( rand ) ) ;
} while ( ! rand );
F_86 ( & V_8 , 0 , rand ) ;
}
static struct V_39 *
F_87 ( struct V_17 * V_17 , T_2 V_3 ,
const struct V_1 * V_37 ,
const struct V_1 * V_96 ,
T_7 V_97 , T_1 V_14 )
{
struct V_39 * V_18 ;
if ( F_51 ( ! V_8 ) ) {
F_84 () ;
V_14 = F_1 ( V_37 , V_3 ) ;
}
F_72 ( & V_17 -> V_18 . V_98 ) ;
if ( V_99 &&
F_51 ( F_21 ( & V_17 -> V_18 . V_98 ) > V_99 ) ) {
if ( ! F_80 ( V_17 , F_4 ( V_14 , V_17 ) ) ) {
F_88 ( & V_17 -> V_18 . V_98 ) ;
if ( F_89 () )
F_90 ( V_100
L_5
L_6 ) ;
return F_91 ( - V_101 ) ;
}
}
V_18 = F_92 ( V_17 -> V_18 . V_102 , V_97 ) ;
if ( V_18 == NULL ) {
F_15 ( L_7 ) ;
F_88 ( & V_17 -> V_18 . V_98 ) ;
return F_91 ( - V_101 ) ;
}
memset ( & V_18 -> V_40 [ V_103 ] , 0 ,
F_93 ( struct V_39 , V_104 ) -
F_93 ( struct V_39 , V_40 [ V_103 ] ) ) ;
F_94 ( & V_18 -> V_105 ) ;
V_18 -> V_40 [ V_31 ] . V_2 = * V_37 ;
V_18 -> V_40 [ V_31 ] . V_41 . V_77 = NULL ;
V_18 -> V_40 [ V_42 ] . V_2 = * V_96 ;
* ( unsigned long * ) ( & V_18 -> V_40 [ V_42 ] . V_41 . V_77 ) = V_14 ;
F_45 ( & V_18 -> V_46 , F_46 , ( unsigned long ) V_18 ) ;
F_95 ( & V_18 -> V_106 , V_17 ) ;
#ifdef F_96
if ( V_3 ) {
struct V_107 * F_56 ;
F_56 = F_97 ( V_18 , V_108 , V_109 ) ;
if ( ! F_56 )
goto V_110;
F_56 -> V_111 = V_3 ;
}
#endif
F_98 () ;
F_99 ( & V_18 -> V_71 . V_45 , 1 ) ;
return V_18 ;
#ifdef F_96
V_110:
F_100 ( V_17 -> V_18 . V_102 , V_18 ) ;
return F_91 ( - V_101 ) ;
#endif
}
struct V_39 * F_101 ( struct V_17 * V_17 , T_2 V_3 ,
const struct V_1 * V_37 ,
const struct V_1 * V_96 ,
T_7 V_97 )
{
return F_87 ( V_17 , V_3 , V_37 , V_96 , V_97 , 0 ) ;
}
void F_32 ( struct V_39 * V_18 )
{
struct V_17 * V_17 = F_19 ( V_18 ) ;
F_102 ( V_18 ) ;
F_88 ( & V_17 -> V_18 . V_98 ) ;
F_103 ( V_18 ) ;
F_100 ( V_17 -> V_18 . V_102 , V_18 ) ;
}
static struct V_63 *
F_104 ( struct V_17 * V_17 , struct V_39 * V_112 ,
const struct V_1 * V_2 ,
struct V_25 * V_26 ,
struct V_27 * V_28 ,
struct V_20 * V_21 ,
unsigned int V_23 , T_1 V_14 )
{
struct V_39 * V_18 ;
struct V_73 * V_74 ;
struct V_1 V_113 ;
struct V_114 * V_115 ;
struct V_116 * exp ;
T_2 V_3 = V_112 ? F_56 ( V_112 ) : V_117 ;
if ( ! F_13 ( & V_113 , V_2 , V_26 , V_28 ) ) {
F_15 ( L_8 ) ;
return NULL ;
}
V_18 = F_87 ( V_17 , V_3 , V_2 , & V_113 , V_109 ,
V_14 ) ;
if ( F_105 ( V_18 ) ) {
F_15 ( L_9 ) ;
return (struct V_63 * ) V_18 ;
}
if ( ! V_28 -> V_118 ( V_18 , V_21 , V_23 ) ) {
F_32 ( V_18 ) ;
F_15 ( L_10 ) ;
return NULL ;
}
F_106 ( V_18 , V_109 ) ;
F_107 ( V_18 , V_109 ) ;
V_115 = V_112 ? F_108 ( V_112 ) : NULL ;
F_109 ( V_18 , V_115 ? V_115 -> V_119 : 0 ,
V_115 ? V_115 -> V_120 : 0 ,
V_109 ) ;
F_25 ( & V_48 ) ;
exp = F_110 ( V_17 , V_3 , V_2 ) ;
if ( exp ) {
F_15 ( L_11 ,
V_18 , exp ) ;
F_111 ( V_121 , & V_18 -> V_58 ) ;
V_18 -> V_50 = exp -> V_50 ;
if ( exp -> V_83 ) {
V_74 = F_112 ( V_18 , V_109 ) ;
if ( V_74 )
F_113 ( V_74 -> V_83 , exp -> V_83 ) ;
}
#ifdef F_114
V_18 -> V_122 = exp -> V_50 -> V_122 ;
#endif
#ifdef F_115
V_18 -> V_123 = exp -> V_50 -> V_123 ;
#endif
F_116 ( & V_18 -> V_50 -> V_71 ) ;
F_29 ( V_17 , V_124 ) ;
} else {
F_117 ( V_18 , V_112 , V_109 ) ;
F_29 ( V_17 , V_118 ) ;
}
F_66 ( & V_18 -> V_40 [ V_31 ] . V_41 ,
& V_17 -> V_18 . V_125 ) ;
F_30 ( & V_48 ) ;
if ( exp ) {
if ( exp -> V_126 )
exp -> V_126 ( V_18 , exp ) ;
F_118 ( exp ) ;
}
return & V_18 -> V_40 [ V_31 ] ;
}
static inline struct V_39 *
F_119 ( struct V_17 * V_17 , struct V_39 * V_112 ,
struct V_20 * V_21 ,
unsigned int V_23 ,
T_4 V_24 ,
T_5 V_13 ,
struct V_25 * V_26 ,
struct V_27 * V_28 ,
int * V_127 ,
enum V_75 * V_76 )
{
struct V_1 V_2 ;
struct V_63 * V_64 ;
struct V_39 * V_18 ;
T_2 V_3 = V_112 ? F_56 ( V_112 ) : V_117 ;
T_1 V_14 ;
if ( ! F_7 ( V_21 , F_120 ( V_21 ) ,
V_23 , V_24 , V_13 , & V_2 , V_26 ,
V_28 ) ) {
F_15 ( L_12 ) ;
return NULL ;
}
V_14 = F_1 ( & V_2 , V_3 ) ;
V_64 = F_61 ( V_17 , V_3 , & V_2 , V_14 ) ;
if ( ! V_64 ) {
V_64 = F_104 ( V_17 , V_112 , & V_2 , V_26 , V_28 ,
V_21 , V_23 , V_14 ) ;
if ( ! V_64 )
return NULL ;
if ( F_105 ( V_64 ) )
return ( void * ) V_64 ;
}
V_18 = F_57 ( V_64 ) ;
if ( F_121 ( V_64 ) == V_42 ) {
* V_76 = V_128 ;
* V_127 = 1 ;
} else {
if ( F_50 ( V_129 , & V_18 -> V_58 ) ) {
F_15 ( L_13 , V_18 ) ;
* V_76 = V_130 ;
} else if ( F_50 ( V_121 , & V_18 -> V_58 ) ) {
F_15 ( L_14 ,
V_18 ) ;
* V_76 = V_131 ;
} else {
F_15 ( L_15 , V_18 ) ;
* V_76 = V_132 ;
}
* V_127 = 0 ;
}
V_21 -> V_44 = & V_18 -> V_71 ;
V_21 -> V_133 = * V_76 ;
return V_18 ;
}
unsigned int
F_122 ( struct V_17 * V_17 , T_5 V_134 , unsigned int V_135 ,
struct V_20 * V_21 )
{
struct V_39 * V_18 , * V_112 = NULL ;
enum V_75 V_76 ;
struct V_25 * V_26 ;
struct V_27 * V_28 ;
unsigned int V_23 ;
T_5 V_13 ;
int V_127 = 0 ;
int V_33 ;
if ( V_21 -> V_44 ) {
V_112 = (struct V_39 * ) V_21 -> V_44 ;
if ( ! F_123 ( V_112 ) ) {
F_83 ( V_17 , V_136 ) ;
return V_35 ;
}
V_21 -> V_44 = NULL ;
}
V_26 = F_10 ( V_134 ) ;
V_33 = V_26 -> V_34 ( V_21 , F_120 ( V_21 ) ,
& V_23 , & V_13 ) ;
if ( V_33 <= 0 ) {
F_15 ( L_16 ) ;
F_83 ( V_17 , error ) ;
F_83 ( V_17 , V_137 ) ;
V_33 = - V_33 ;
goto V_78;
}
V_28 = F_12 ( V_134 , V_13 ) ;
if ( V_28 -> error != NULL ) {
V_33 = V_28 -> error ( V_17 , V_112 , V_21 , V_23 , & V_76 ,
V_134 , V_135 ) ;
if ( V_33 <= 0 ) {
F_83 ( V_17 , error ) ;
F_83 ( V_17 , V_137 ) ;
V_33 = - V_33 ;
goto V_78;
}
if ( V_21 -> V_44 )
goto V_78;
}
V_18 = F_119 ( V_17 , V_112 , V_21 , V_23 , V_134 , V_13 ,
V_26 , V_28 , & V_127 , & V_76 ) ;
if ( ! V_18 ) {
F_83 ( V_17 , V_137 ) ;
V_33 = V_35 ;
goto V_78;
}
if ( F_105 ( V_18 ) ) {
F_83 ( V_17 , V_138 ) ;
V_33 = V_88 ;
goto V_78;
}
F_20 ( V_21 -> V_44 ) ;
V_33 = V_28 -> V_139 ( V_18 , V_21 , V_23 , V_76 , V_134 , V_135 ) ;
if ( V_33 <= 0 ) {
F_15 ( L_17 ) ;
F_124 ( V_21 -> V_44 ) ;
V_21 -> V_44 = NULL ;
F_83 ( V_17 , V_137 ) ;
if ( V_33 == - V_88 )
F_83 ( V_17 , V_138 ) ;
V_33 = - V_33 ;
goto V_78;
}
if ( V_127 && ! F_125 ( V_129 , & V_18 -> V_58 ) )
F_75 ( V_140 , V_18 ) ;
V_78:
if ( V_112 ) {
if ( V_33 == V_141 )
V_21 -> V_44 = (struct V_43 * ) V_112 ;
else
F_31 ( V_112 ) ;
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
const struct V_1 * V_142 )
{
struct V_73 * V_74 = F_74 ( V_18 ) ;
F_20 ( ! F_26 ( V_18 ) ) ;
F_15 ( L_18 , V_18 ) ;
F_128 ( V_142 ) ;
V_18 -> V_40 [ V_42 ] . V_2 = * V_142 ;
if ( V_18 -> V_50 || ( V_74 && ! F_129 ( & V_74 -> V_143 ) ) )
return;
F_9 () ;
F_117 ( V_18 , NULL , V_109 ) ;
F_11 () ;
}
void F_130 ( struct V_39 * V_18 ,
enum V_75 V_76 ,
const struct V_20 * V_21 ,
unsigned long V_144 ,
int V_145 )
{
F_20 ( V_18 -> V_46 . V_146 == ( unsigned long ) V_18 ) ;
F_20 ( V_21 ) ;
if ( F_50 ( V_147 , & V_18 -> V_58 ) )
goto V_148;
if ( ! F_26 ( V_18 ) ) {
V_18 -> V_46 . V_54 = V_144 ;
} else {
unsigned long V_149 = V_55 + V_144 ;
if ( V_149 - V_18 -> V_46 . V_54 >= V_150 )
F_131 ( & V_18 -> V_46 , V_149 ) ;
}
V_148:
if ( V_145 ) {
struct V_151 * V_148 ;
V_148 = F_132 ( V_18 ) ;
if ( V_148 ) {
F_25 ( & V_18 -> V_105 ) ;
V_148 [ F_70 ( V_76 ) ] . V_152 ++ ;
V_148 [ F_70 ( V_76 ) ] . V_153 += V_21 -> V_154 ;
F_30 ( & V_18 -> V_105 ) ;
}
}
}
bool F_133 ( struct V_39 * V_18 ,
enum V_75 V_76 ,
const struct V_20 * V_21 ,
int V_145 )
{
if ( V_145 ) {
struct V_151 * V_148 ;
V_148 = F_132 ( V_18 ) ;
if ( V_148 ) {
F_25 ( & V_18 -> V_105 ) ;
V_148 [ F_70 ( V_76 ) ] . V_152 ++ ;
V_148 [ F_70 ( V_76 ) ] . V_153 +=
V_21 -> V_154 - F_120 ( V_21 ) ;
F_30 ( & V_18 -> V_105 ) ;
}
}
if ( F_82 ( & V_18 -> V_46 ) ) {
V_18 -> V_46 . V_155 ( ( unsigned long ) V_18 ) ;
return true ;
}
return false ;
}
int F_134 ( struct V_20 * V_21 ,
const struct V_1 * V_2 )
{
F_135 ( V_21 , V_156 , V_2 -> V_5 . V_11 . V_157 . V_158 ) ;
F_135 ( V_21 , V_159 , V_2 -> V_6 . V_11 . V_157 . V_158 ) ;
return 0 ;
V_160:
return - 1 ;
}
int F_136 ( struct V_161 * V_162 [] ,
struct V_1 * V_163 )
{
if ( ! V_162 [ V_156 ] || ! V_162 [ V_159 ] )
return - V_164 ;
V_163 -> V_5 . V_11 . V_157 . V_158 = F_137 ( V_162 [ V_156 ] ) ;
V_163 -> V_6 . V_11 . V_157 . V_158 = F_137 ( V_162 [ V_159 ] ) ;
return 0 ;
}
int F_138 ( void )
{
return F_139 ( V_165 , V_166 + 1 ) ;
}
static void F_140 ( struct V_20 * V_167 , struct V_20 * V_21 )
{
struct V_39 * V_18 ;
enum V_75 V_76 ;
V_18 = F_69 ( V_21 , & V_76 ) ;
if ( F_70 ( V_76 ) == V_31 )
V_76 = V_168 ;
else
V_76 = V_131 ;
V_167 -> V_44 = & V_18 -> V_71 ;
V_167 -> V_133 = V_76 ;
F_116 ( V_167 -> V_44 ) ;
}
static struct V_39 *
F_141 ( struct V_17 * V_17 , int (* F_142)( struct V_39 * V_91 , void * V_146 ) ,
void * V_146 , unsigned int * V_66 )
{
struct V_63 * V_64 ;
struct V_39 * V_18 ;
struct V_65 * V_4 ;
F_25 ( & V_48 ) ;
for (; * V_66 < V_17 -> V_18 . V_19 ; ( * V_66 ) ++ ) {
F_71 (h, n, &net->ct.hash[*bucket], hnnode) {
V_18 = F_57 ( V_64 ) ;
if ( F_142 ( V_18 , V_146 ) )
goto V_68;
}
}
F_71 (h, n, &net->ct.unconfirmed, hnnode) {
V_18 = F_57 ( V_64 ) ;
if ( F_142 ( V_18 , V_146 ) )
F_39 ( V_57 , & V_18 -> V_58 ) ;
}
F_30 ( & V_48 ) ;
return NULL ;
V_68:
F_72 ( & V_18 -> V_71 . V_45 ) ;
F_30 ( & V_48 ) ;
return V_18 ;
}
void F_143 ( struct V_17 * V_17 ,
int (* F_142)( struct V_39 * V_91 , void * V_146 ) ,
void * V_146 )
{
struct V_39 * V_18 ;
unsigned int V_66 = 0 ;
while ( ( V_18 = F_141 ( V_17 , F_142 , V_146 , & V_66 ) ) != NULL ) {
if ( F_82 ( & V_18 -> V_46 ) )
F_46 ( ( unsigned long ) V_18 ) ;
F_31 ( V_18 ) ;
}
}
static int F_144 ( struct V_39 * V_91 , void * V_146 )
{
struct V_169 * V_170 = (struct V_169 * ) V_146 ;
struct V_60 * V_61 ;
V_61 = F_47 ( V_91 ) ;
if ( V_61 && V_61 -> V_62 == 0 )
V_61 -> V_62 = F_48 ( F_49 () ) ;
if ( F_145 ( V_53 , V_91 ,
V_170 -> V_171 , V_170 -> V_172 ) < 0 )
return 1 ;
F_39 ( V_57 , & V_91 -> V_58 ) ;
return 1 ;
}
static int F_146 ( struct V_39 * V_91 , void * V_146 )
{
return 1 ;
}
void F_147 ( void * V_14 , unsigned int V_15 )
{
if ( F_148 ( V_14 ) )
F_149 ( V_14 ) ;
else
F_150 ( ( unsigned long ) V_14 ,
F_151 ( sizeof( struct V_173 ) * V_15 ) ) ;
}
void F_152 ( struct V_17 * V_17 , T_1 V_171 , int V_172 )
{
struct V_169 V_170 = {
. V_171 = V_171 ,
. V_172 = V_172 ,
} ;
F_143 ( V_17 , F_144 , & V_170 ) ;
}
static void F_153 ( struct V_17 * V_17 )
{
struct V_63 * V_64 ;
struct V_39 * V_18 ;
struct V_65 * V_4 ;
F_25 ( & V_48 ) ;
F_71 (h, n, &net->ct.dying, hnnode) {
V_18 = F_57 ( V_64 ) ;
F_154 ( V_18 ) ;
}
F_30 ( & V_48 ) ;
}
static int F_155 ( void )
{
int V_92 = 0 , V_174 ;
F_156 (cpu) {
struct V_39 * V_18 = & F_157 ( V_175 , V_174 ) ;
V_92 += F_21 ( & V_18 -> V_71 . V_45 ) - 1 ;
}
return V_92 ;
}
static void F_158 ( void )
{
while ( F_155 () > 0 )
F_159 () ;
F_160 () ;
F_161 () ;
#ifdef F_96
F_162 ( & V_176 ) ;
#endif
}
static void F_163 ( struct V_17 * V_17 )
{
V_177:
F_143 ( V_17 , F_146 , NULL ) ;
F_153 ( V_17 ) ;
if ( F_21 ( & V_17 -> V_18 . V_98 ) != 0 ) {
F_159 () ;
goto V_177;
}
F_147 ( V_17 -> V_18 . V_14 , V_17 -> V_18 . V_19 ) ;
F_164 ( V_17 ) ;
F_165 ( V_17 ) ;
F_166 ( V_17 ) ;
F_167 ( V_17 ) ;
F_168 ( V_17 -> V_18 . V_102 ) ;
F_169 ( V_17 -> V_18 . V_178 ) ;
F_170 ( V_17 -> V_18 . V_179 ) ;
}
void F_171 ( struct V_17 * V_17 )
{
if ( F_172 ( V_17 , & V_180 ) )
F_113 ( V_181 , NULL ) ;
F_173 () ;
F_163 ( V_17 ) ;
if ( F_172 ( V_17 , & V_180 ) ) {
F_113 ( V_182 , NULL ) ;
F_158 () ;
}
}
void * F_174 ( unsigned int * V_183 , int V_184 )
{
struct V_185 * V_14 ;
unsigned int V_186 , V_91 ;
T_8 V_187 ;
F_175 ( sizeof( struct V_185 ) != sizeof( struct V_173 ) ) ;
V_186 = * V_183 = F_176 ( * V_183 , V_188 / sizeof( struct V_185 ) ) ;
V_187 = V_186 * sizeof( struct V_185 ) ;
V_14 = ( void * ) F_177 ( V_189 | V_190 | V_191 ,
F_151 ( V_187 ) ) ;
if ( ! V_14 ) {
F_90 ( V_100 L_19 ) ;
V_14 = F_178 ( V_187 , V_189 | V_192 | V_191 ,
V_193 ) ;
}
if ( V_14 && V_184 )
for ( V_91 = 0 ; V_91 < V_186 ; V_91 ++ )
F_179 ( & V_14 [ V_91 ] , V_91 ) ;
return V_14 ;
}
int F_180 ( const char * V_194 , struct V_195 * V_196 )
{
int V_91 , V_66 ;
unsigned int V_197 , V_198 ;
struct V_185 * V_14 , * V_199 ;
struct V_63 * V_64 ;
struct V_39 * V_18 ;
if ( V_200 -> V_201 -> V_202 != & V_180 )
return - V_203 ;
if ( ! V_204 )
return F_181 ( V_194 , V_196 ) ;
V_197 = F_182 ( V_194 , NULL , 0 ) ;
if ( ! V_197 )
return - V_164 ;
V_14 = F_174 ( & V_197 , 1 ) ;
if ( ! V_14 )
return - V_101 ;
F_25 ( & V_48 ) ;
for ( V_91 = 0 ; V_91 < V_180 . V_18 . V_19 ; V_91 ++ ) {
while ( ! F_183 ( & V_180 . V_18 . V_14 [ V_91 ] ) ) {
V_64 = F_184 ( V_180 . V_18 . V_14 [ V_91 ] . V_205 ,
struct V_63 , V_41 ) ;
V_18 = F_57 ( V_64 ) ;
F_16 ( & V_64 -> V_41 ) ;
V_66 = F_5 ( & V_64 -> V_2 , F_56 ( V_18 ) ,
V_197 ) ;
F_66 ( & V_64 -> V_41 , & V_14 [ V_66 ] ) ;
}
}
V_198 = V_180 . V_18 . V_19 ;
V_199 = V_180 . V_18 . V_14 ;
V_180 . V_18 . V_19 = V_204 = V_197 ;
V_180 . V_18 . V_14 = V_14 ;
F_30 ( & V_48 ) ;
F_147 ( V_199 , V_198 ) ;
return 0 ;
}
void F_185 ( unsigned long V_206 )
{
int V_174 ;
F_156 (cpu)
F_157 ( V_175 , V_174 ) . V_58 |= V_206 ;
}
static int F_186 ( void )
{
int V_207 = 8 ;
int V_33 , V_174 ;
if ( ! V_204 ) {
V_204
= ( ( ( V_208 << V_209 ) / 16384 )
/ sizeof( struct V_173 ) ) ;
if ( V_208 > ( 1024 * 1024 * 1024 / V_188 ) )
V_204 = 16384 ;
if ( V_204 < 32 )
V_204 = 32 ;
V_207 = 4 ;
}
V_99 = V_207 * V_204 ;
F_90 ( V_210 L_20 ,
V_211 , V_204 ,
V_99 ) ;
V_33 = F_187 () ;
if ( V_33 < 0 )
goto V_212;
V_33 = F_188 () ;
if ( V_33 < 0 )
goto V_213;
#ifdef F_96
V_33 = F_189 ( & V_176 ) ;
if ( V_33 < 0 )
goto V_214;
#endif
F_156 (cpu) {
struct V_39 * V_18 = & F_157 ( V_175 , V_174 ) ;
F_95 ( & V_18 -> V_106 , & V_180 ) ;
F_99 ( & V_18 -> V_71 . V_45 , 1 ) ;
}
F_185 ( V_79 | V_215 ) ;
return 0 ;
#ifdef F_96
V_214:
F_160 () ;
#endif
V_213:
F_161 () ;
V_212:
return V_33 ;
}
static int F_190 ( struct V_17 * V_17 )
{
int V_33 ;
F_99 ( & V_17 -> V_18 . V_98 , 0 ) ;
F_179 ( & V_17 -> V_18 . V_125 , V_216 ) ;
F_179 ( & V_17 -> V_18 . V_59 , V_217 ) ;
V_17 -> V_18 . V_179 = F_191 ( struct V_218 ) ;
if ( ! V_17 -> V_18 . V_179 ) {
V_33 = - V_101 ;
goto V_219;
}
V_17 -> V_18 . V_178 = F_192 ( V_189 , L_21 , V_17 ) ;
if ( ! V_17 -> V_18 . V_178 ) {
V_33 = - V_101 ;
goto V_220;
}
V_17 -> V_18 . V_102 = F_193 ( V_17 -> V_18 . V_178 ,
sizeof( struct V_39 ) , 0 ,
V_221 , NULL ) ;
if ( ! V_17 -> V_18 . V_102 ) {
F_90 ( V_222 L_22 ) ;
V_33 = - V_101 ;
goto V_223;
}
V_17 -> V_18 . V_19 = V_204 ;
V_17 -> V_18 . V_14 = F_174 ( & V_17 -> V_18 . V_19 , 1 ) ;
if ( ! V_17 -> V_18 . V_14 ) {
V_33 = - V_101 ;
F_90 ( V_222 L_23 ) ;
goto V_224;
}
V_33 = F_194 ( V_17 ) ;
if ( V_33 < 0 )
goto V_225;
V_33 = F_195 ( V_17 ) ;
if ( V_33 < 0 )
goto V_226;
V_33 = F_196 ( V_17 ) ;
if ( V_33 < 0 )
goto V_227;
V_33 = F_197 ( V_17 ) ;
if ( V_33 < 0 )
goto V_228;
return 0 ;
V_228:
F_165 ( V_17 ) ;
V_227:
F_166 ( V_17 ) ;
V_226:
F_167 ( V_17 ) ;
V_225:
F_147 ( V_17 -> V_18 . V_14 , V_17 -> V_18 . V_19 ) ;
V_224:
F_168 ( V_17 -> V_18 . V_102 ) ;
V_223:
F_169 ( V_17 -> V_18 . V_178 ) ;
V_220:
F_170 ( V_17 -> V_18 . V_179 ) ;
V_219:
return V_33 ;
}
int F_198 ( struct V_17 * V_17 )
{
int V_33 ;
if ( F_172 ( V_17 , & V_180 ) ) {
V_33 = F_186 () ;
if ( V_33 < 0 )
goto V_229;
}
V_33 = F_190 ( V_17 ) ;
if ( V_33 < 0 )
goto V_230;
if ( F_172 ( V_17 , & V_180 ) ) {
F_113 ( V_181 , F_140 ) ;
F_113 ( V_182 , F_18 ) ;
F_113 ( V_231 , NULL ) ;
}
return 0 ;
V_230:
if ( F_172 ( V_17 , & V_180 ) )
F_158 () ;
V_229:
return V_33 ;
}
