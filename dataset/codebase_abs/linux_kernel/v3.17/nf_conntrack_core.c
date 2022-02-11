static void F_1 ( unsigned int V_1 , unsigned int V_2 )
{
V_1 %= V_3 ;
V_2 %= V_3 ;
F_2 ( & V_4 [ V_1 ] ) ;
if ( V_1 != V_2 )
F_2 ( & V_4 [ V_2 ] ) ;
}
static bool F_3 ( struct V_5 * V_5 , unsigned int V_1 ,
unsigned int V_2 , unsigned int V_6 )
{
V_1 %= V_3 ;
V_2 %= V_3 ;
if ( V_1 <= V_2 ) {
F_4 ( & V_4 [ V_1 ] ) ;
if ( V_1 != V_2 )
F_5 ( & V_4 [ V_2 ] ,
V_7 ) ;
} else {
F_4 ( & V_4 [ V_2 ] ) ;
F_5 ( & V_4 [ V_1 ] ,
V_7 ) ;
}
if ( F_6 ( & V_5 -> V_8 . V_9 , V_6 ) ) {
F_1 ( V_1 , V_2 ) ;
return true ;
}
return false ;
}
static void F_7 ( void )
{
int V_10 ;
for ( V_10 = 0 ; V_10 < V_3 ; V_10 ++ )
F_5 ( & V_4 [ V_10 ] , V_10 ) ;
}
static void F_8 ( void )
{
int V_10 ;
for ( V_10 = 0 ; V_10 < V_3 ; V_10 ++ )
F_2 ( & V_4 [ V_10 ] ) ;
}
static T_1 F_9 ( const struct V_11 * V_12 , T_2 V_13 )
{
unsigned int V_14 ;
V_14 = ( sizeof( V_12 -> V_15 ) + sizeof( V_12 -> V_16 . V_17 ) ) / sizeof( T_1 ) ;
return F_10 ( ( T_1 * ) V_12 , V_14 , V_13 ^ V_18 ^
( ( ( V_19 V_20 ) V_12 -> V_16 . V_21 . V_22 << 16 ) |
V_12 -> V_16 . V_23 ) ) ;
}
static T_1 F_11 ( T_1 V_24 , unsigned int V_25 )
{
return ( ( V_26 ) V_24 * V_25 ) >> 32 ;
}
static T_1 F_12 ( T_1 V_24 , const struct V_5 * V_5 )
{
return F_11 ( V_24 , V_5 -> V_8 . V_27 ) ;
}
static T_3 F_13 ( const struct V_11 * V_12 ,
T_2 V_13 , unsigned int V_25 )
{
return F_11 ( F_9 ( V_12 , V_13 ) , V_25 ) ;
}
static inline T_3 F_14 ( const struct V_5 * V_5 , T_2 V_13 ,
const struct V_11 * V_12 )
{
return F_13 ( V_12 , V_13 , V_5 -> V_8 . V_27 ) ;
}
bool
F_15 ( const struct V_28 * V_29 ,
unsigned int V_30 ,
unsigned int V_31 ,
T_4 V_32 ,
T_5 V_23 ,
struct V_11 * V_12 ,
const struct V_33 * V_34 ,
const struct V_35 * V_36 )
{
memset ( V_12 , 0 , sizeof( * V_12 ) ) ;
V_12 -> V_15 . V_32 = V_32 ;
if ( V_34 -> V_37 ( V_29 , V_30 , V_12 ) == 0 )
return false ;
V_12 -> V_16 . V_23 = V_23 ;
V_12 -> V_16 . V_38 = V_39 ;
return V_36 -> V_37 ( V_29 , V_31 , V_12 ) ;
}
bool F_16 ( const struct V_28 * V_29 , unsigned int V_30 ,
T_4 V_32 , struct V_11 * V_12 )
{
struct V_33 * V_34 ;
struct V_35 * V_36 ;
unsigned int V_40 ;
T_5 V_23 ;
int V_41 ;
F_17 () ;
V_34 = F_18 ( V_32 ) ;
V_41 = V_34 -> V_42 ( V_29 , V_30 , & V_40 , & V_23 ) ;
if ( V_41 != V_43 ) {
F_19 () ;
return false ;
}
V_36 = F_20 ( V_32 , V_23 ) ;
V_41 = F_15 ( V_29 , V_30 , V_40 , V_32 , V_23 , V_12 ,
V_34 , V_36 ) ;
F_19 () ;
return V_41 ;
}
bool
F_21 ( struct V_11 * V_44 ,
const struct V_11 * V_45 ,
const struct V_33 * V_34 ,
const struct V_35 * V_36 )
{
memset ( V_44 , 0 , sizeof( * V_44 ) ) ;
V_44 -> V_15 . V_32 = V_45 -> V_15 . V_32 ;
if ( V_34 -> V_46 ( V_44 , V_45 ) == 0 )
return false ;
V_44 -> V_16 . V_38 = ! V_45 -> V_16 . V_38 ;
V_44 -> V_16 . V_23 = V_45 -> V_16 . V_23 ;
return V_36 -> V_46 ( V_44 , V_45 ) ;
}
static void
F_22 ( struct V_47 * V_8 )
{
F_23 ( L_1 , V_8 ) ;
F_24 ( & V_8 -> V_48 [ V_39 ] . V_49 ) ;
F_24 ( & V_8 -> V_48 [ V_50 ] . V_49 ) ;
F_25 ( V_8 ) ;
}
static void F_26 ( struct V_47 * V_8 )
{
struct V_51 * V_52 ;
V_8 -> V_53 = F_27 () ;
V_52 = F_28 ( F_29 ( V_8 ) -> V_8 . V_54 , V_8 -> V_53 ) ;
F_4 ( & V_52 -> V_55 ) ;
F_30 ( & V_8 -> V_48 [ V_39 ] . V_49 ,
& V_52 -> V_56 ) ;
F_2 ( & V_52 -> V_55 ) ;
}
static void F_31 ( struct V_47 * V_8 )
{
struct V_51 * V_52 ;
V_8 -> V_53 = F_27 () ;
V_52 = F_28 ( F_29 ( V_8 ) -> V_8 . V_54 , V_8 -> V_53 ) ;
F_4 ( & V_52 -> V_55 ) ;
F_30 ( & V_8 -> V_48 [ V_39 ] . V_49 ,
& V_52 -> V_57 ) ;
F_2 ( & V_52 -> V_55 ) ;
}
static void F_32 ( struct V_47 * V_8 )
{
struct V_51 * V_52 ;
V_52 = F_28 ( F_29 ( V_8 ) -> V_8 . V_54 , V_8 -> V_53 ) ;
F_4 ( & V_52 -> V_55 ) ;
F_33 ( F_34 ( & V_8 -> V_48 [ V_39 ] . V_49 ) ) ;
F_24 ( & V_8 -> V_48 [ V_39 ] . V_49 ) ;
F_2 ( & V_52 -> V_55 ) ;
}
static void
F_35 ( struct V_58 * V_59 )
{
struct V_47 * V_8 = (struct V_47 * ) V_59 ;
struct V_5 * V_5 = F_29 ( V_8 ) ;
struct V_35 * V_36 ;
F_23 ( L_2 , V_8 ) ;
F_36 ( F_37 ( & V_59 -> V_60 ) == 0 ) ;
F_36 ( ! F_38 ( & V_8 -> V_61 ) ) ;
F_17 () ;
V_36 = F_20 ( F_39 ( V_8 ) , F_40 ( V_8 ) ) ;
if ( V_36 && V_36 -> V_62 )
V_36 -> V_62 ( V_8 ) ;
F_19 () ;
F_41 () ;
F_25 ( V_8 ) ;
F_32 ( V_8 ) ;
F_42 ( V_5 , V_63 ) ;
F_43 () ;
if ( V_8 -> V_64 )
F_44 ( V_8 -> V_64 ) ;
F_23 ( L_3 , V_8 ) ;
F_45 ( V_8 ) ;
}
static void F_46 ( struct V_47 * V_8 )
{
struct V_5 * V_5 = F_29 ( V_8 ) ;
unsigned int V_24 , V_65 ;
T_2 V_13 = F_47 ( V_8 ) ;
unsigned int V_6 ;
F_48 ( V_8 ) ;
F_41 () ;
do {
V_6 = F_49 ( & V_5 -> V_8 . V_9 ) ;
V_24 = F_14 ( V_5 , V_13 ,
& V_8 -> V_48 [ V_39 ] . V_12 ) ;
V_65 = F_14 ( V_5 , V_13 ,
& V_8 -> V_48 [ V_50 ] . V_12 ) ;
} while ( F_3 ( V_5 , V_24 , V_65 , V_6 ) );
F_22 ( V_8 ) ;
F_1 ( V_24 , V_65 ) ;
F_26 ( V_8 ) ;
F_42 ( V_5 , V_66 ) ;
F_43 () ;
}
bool F_50 ( struct V_47 * V_8 , T_1 V_67 , int V_68 )
{
struct V_69 * V_70 ;
V_70 = F_51 ( V_8 ) ;
if ( V_70 && V_70 -> V_71 == 0 )
V_70 -> V_71 = F_52 ( F_53 () ) ;
if ( F_54 ( V_8 ) )
goto V_63;
if ( F_55 ( V_72 , V_8 ,
V_67 , V_68 ) < 0 ) {
F_46 ( V_8 ) ;
F_56 ( F_29 ( V_8 ) ) ;
return false ;
}
F_57 ( F_29 ( V_8 ) ) ;
F_58 ( V_73 , & V_8 -> V_74 ) ;
V_63:
F_46 ( V_8 ) ;
F_44 ( V_8 ) ;
return true ;
}
static void F_59 ( unsigned long V_75 )
{
F_50 ( (struct V_47 * ) V_75 , 0 , 0 ) ;
}
static inline bool
F_60 ( struct V_76 * V_77 ,
const struct V_11 * V_12 ,
T_2 V_13 )
{
struct V_47 * V_8 = F_61 ( V_77 ) ;
return F_62 ( V_12 , & V_77 -> V_12 ) &&
F_47 ( V_8 ) == V_13 &&
F_63 ( V_8 ) ;
}
static struct V_76 *
F_64 ( struct V_5 * V_5 , T_2 V_13 ,
const struct V_11 * V_12 , T_1 V_24 )
{
struct V_76 * V_77 ;
struct V_78 * V_14 ;
unsigned int V_79 = F_12 ( V_24 , V_5 ) ;
F_41 () ;
V_80:
F_65 (h, n, &net->ct.hash[bucket], hnnode) {
if ( F_60 ( V_77 , V_12 , V_13 ) ) {
F_42 ( V_5 , V_81 ) ;
F_43 () ;
return V_77 ;
}
F_42 ( V_5 , V_82 ) ;
}
if ( F_66 ( V_14 ) != V_79 ) {
F_42 ( V_5 , V_83 ) ;
goto V_80;
}
F_43 () ;
return NULL ;
}
static struct V_76 *
F_67 ( struct V_5 * V_5 , T_2 V_13 ,
const struct V_11 * V_12 , T_1 V_24 )
{
struct V_76 * V_77 ;
struct V_47 * V_8 ;
F_17 () ;
V_80:
V_77 = F_64 ( V_5 , V_13 , V_12 , V_24 ) ;
if ( V_77 ) {
V_8 = F_61 ( V_77 ) ;
if ( F_68 ( F_54 ( V_8 ) ||
! F_69 ( & V_8 -> V_84 . V_60 ) ) )
V_77 = NULL ;
else {
if ( F_68 ( ! F_60 ( V_77 , V_12 , V_13 ) ) ) {
F_44 ( V_8 ) ;
goto V_80;
}
}
}
F_19 () ;
return V_77 ;
}
struct V_76 *
F_70 ( struct V_5 * V_5 , T_2 V_13 ,
const struct V_11 * V_12 )
{
return F_67 ( V_5 , V_13 , V_12 ,
F_9 ( V_12 , V_13 ) ) ;
}
static void F_71 ( struct V_47 * V_8 ,
unsigned int V_24 ,
unsigned int V_65 )
{
struct V_5 * V_5 = F_29 ( V_8 ) ;
F_72 ( & V_8 -> V_48 [ V_39 ] . V_49 ,
& V_5 -> V_8 . V_24 [ V_24 ] ) ;
F_72 ( & V_8 -> V_48 [ V_50 ] . V_49 ,
& V_5 -> V_8 . V_24 [ V_65 ] ) ;
}
int
F_73 ( struct V_47 * V_8 )
{
struct V_5 * V_5 = F_29 ( V_8 ) ;
unsigned int V_24 , V_65 ;
struct V_76 * V_77 ;
struct V_78 * V_14 ;
T_2 V_13 ;
unsigned int V_6 ;
V_13 = F_47 ( V_8 ) ;
F_41 () ;
do {
V_6 = F_49 ( & V_5 -> V_8 . V_9 ) ;
V_24 = F_14 ( V_5 , V_13 ,
& V_8 -> V_48 [ V_39 ] . V_12 ) ;
V_65 = F_14 ( V_5 , V_13 ,
& V_8 -> V_48 [ V_50 ] . V_12 ) ;
} while ( F_3 ( V_5 , V_24 , V_65 , V_6 ) );
F_74 (h, n, &net->ct.hash[hash], hnnode)
if ( F_62 ( & V_8 -> V_48 [ V_39 ] . V_12 ,
& V_77 -> V_12 ) &&
V_13 == F_47 ( F_61 ( V_77 ) ) )
goto V_85;
F_74 (h, n, &net->ct.hash[reply_hash], hnnode)
if ( F_62 ( & V_8 -> V_48 [ V_50 ] . V_12 ,
& V_77 -> V_12 ) &&
V_13 == F_47 ( F_61 ( V_77 ) ) )
goto V_85;
F_75 ( & V_8 -> V_61 ) ;
F_76 () ;
F_77 ( & V_8 -> V_84 . V_60 , 2 ) ;
F_71 ( V_8 , V_24 , V_65 ) ;
F_1 ( V_24 , V_65 ) ;
F_42 ( V_5 , V_86 ) ;
F_43 () ;
return 0 ;
V_85:
F_1 ( V_24 , V_65 ) ;
F_42 ( V_5 , V_87 ) ;
F_43 () ;
return - V_88 ;
}
void F_78 ( struct V_5 * V_5 , struct V_47 * V_89 )
{
struct V_51 * V_52 ;
F_79 ( V_90 , & V_89 -> V_74 ) ;
F_79 ( V_91 , & V_89 -> V_74 ) ;
F_80 ( & V_89 -> V_84 ) ;
F_41 () ;
V_89 -> V_53 = F_27 () ;
V_52 = F_28 ( F_29 ( V_89 ) -> V_8 . V_54 , V_89 -> V_53 ) ;
F_4 ( & V_52 -> V_55 ) ;
F_72 ( & V_89 -> V_48 [ V_39 ] . V_49 ,
& V_52 -> V_89 ) ;
F_81 ( & V_52 -> V_55 ) ;
}
int
F_82 ( struct V_28 * V_29 )
{
unsigned int V_24 , V_65 ;
struct V_76 * V_77 ;
struct V_47 * V_8 ;
struct V_92 * V_93 ;
struct V_69 * V_70 ;
struct V_78 * V_14 ;
enum V_94 V_95 ;
struct V_5 * V_5 ;
T_2 V_13 ;
unsigned int V_6 ;
V_8 = F_83 ( V_29 , & V_95 ) ;
V_5 = F_29 ( V_8 ) ;
if ( F_84 ( V_95 ) != V_39 )
return V_43 ;
V_13 = F_47 ( V_8 ) ;
F_41 () ;
do {
V_6 = F_49 ( & V_5 -> V_8 . V_9 ) ;
V_24 = * ( unsigned long * ) & V_8 -> V_48 [ V_50 ] . V_49 . V_96 ;
V_24 = F_12 ( V_24 , V_5 ) ;
V_65 = F_14 ( V_5 , V_13 ,
& V_8 -> V_48 [ V_50 ] . V_12 ) ;
} while ( F_3 ( V_5 , V_24 , V_65 , V_6 ) );
F_36 ( ! F_63 ( V_8 ) ) ;
F_23 ( L_4 , V_8 ) ;
if ( F_68 ( F_54 ( V_8 ) ) ) {
F_1 ( V_24 , V_65 ) ;
F_43 () ;
return V_43 ;
}
F_74 (h, n, &net->ct.hash[hash], hnnode)
if ( F_62 ( & V_8 -> V_48 [ V_39 ] . V_12 ,
& V_77 -> V_12 ) &&
V_13 == F_47 ( F_61 ( V_77 ) ) )
goto V_85;
F_74 (h, n, &net->ct.hash[reply_hash], hnnode)
if ( F_62 ( & V_8 -> V_48 [ V_50 ] . V_12 ,
& V_77 -> V_12 ) &&
V_13 == F_47 ( F_61 ( V_77 ) ) )
goto V_85;
F_32 ( V_8 ) ;
V_8 -> V_61 . V_97 += V_98 ;
F_75 ( & V_8 -> V_61 ) ;
F_85 ( & V_8 -> V_84 . V_60 ) ;
V_8 -> V_74 |= V_99 ;
V_70 = F_51 ( V_8 ) ;
if ( V_70 ) {
if ( V_29 -> V_70 . V_100 == 0 )
F_86 ( V_29 ) ;
V_70 -> V_101 = F_52 ( V_29 -> V_70 ) ;
}
F_71 ( V_8 , V_24 , V_65 ) ;
F_1 ( V_24 , V_65 ) ;
F_42 ( V_5 , V_86 ) ;
F_43 () ;
V_93 = F_87 ( V_8 ) ;
if ( V_93 && V_93 -> V_102 )
F_88 ( V_103 , V_8 ) ;
F_88 ( F_89 ( V_8 ) ?
V_104 : V_105 , V_8 ) ;
return V_43 ;
V_85:
F_1 ( V_24 , V_65 ) ;
F_42 ( V_5 , V_87 ) ;
F_43 () ;
return V_106 ;
}
int
F_90 ( const struct V_11 * V_12 ,
const struct V_47 * V_107 )
{
struct V_5 * V_5 = F_29 ( V_107 ) ;
struct V_76 * V_77 ;
struct V_78 * V_14 ;
struct V_47 * V_8 ;
T_2 V_13 = F_47 ( V_107 ) ;
unsigned int V_24 = F_14 ( V_5 , V_13 , V_12 ) ;
F_91 () ;
F_65 (h, n, &net->ct.hash[hash], hnnode) {
V_8 = F_61 ( V_77 ) ;
if ( V_8 != V_107 &&
F_62 ( V_12 , & V_77 -> V_12 ) &&
F_47 ( V_8 ) == V_13 ) {
F_42 ( V_5 , V_81 ) ;
F_92 () ;
return 1 ;
}
F_42 ( V_5 , V_82 ) ;
}
F_92 () ;
return 0 ;
}
static T_6 int F_93 ( struct V_5 * V_5 , unsigned int V_108 )
{
struct V_76 * V_77 ;
struct V_47 * V_8 = NULL , * V_109 ;
struct V_78 * V_14 ;
unsigned int V_10 = 0 , V_110 = 0 ;
int V_111 = 0 ;
unsigned int V_24 , V_6 ;
T_7 * V_112 ;
F_41 () ;
V_113:
V_6 = F_49 ( & V_5 -> V_8 . V_9 ) ;
V_24 = F_12 ( V_108 , V_5 ) ;
for (; V_10 < V_5 -> V_8 . V_27 ; V_10 ++ ) {
V_112 = & V_4 [ V_24 % V_3 ] ;
F_4 ( V_112 ) ;
if ( F_6 ( & V_5 -> V_8 . V_9 , V_6 ) ) {
F_2 ( V_112 ) ;
goto V_113;
}
F_65 (h, n, &net->ct.hash[hash],
hnnode) {
V_109 = F_61 ( V_77 ) ;
if ( ! F_94 ( V_114 , & V_109 -> V_74 ) &&
! F_54 ( V_109 ) &&
F_69 ( & V_109 -> V_84 . V_60 ) ) {
V_8 = V_109 ;
break;
}
V_110 ++ ;
}
V_24 = ( V_24 + 1 ) % V_5 -> V_8 . V_27 ;
F_2 ( V_112 ) ;
if ( V_8 || V_110 >= V_115 )
break;
}
F_43 () ;
if ( ! V_8 )
return V_111 ;
if ( F_95 ( & V_8 -> V_61 ) ) {
if ( F_50 ( V_8 , 0 , 0 ) ) {
V_111 = 1 ;
F_96 ( V_5 , F_93 ) ;
}
}
F_44 ( V_8 ) ;
return V_111 ;
}
void F_97 ( void )
{
unsigned int rand ;
do {
F_98 ( & rand , sizeof( rand ) ) ;
} while ( ! rand );
F_99 ( & V_18 , 0 , rand ) ;
}
static struct V_47 *
F_100 ( struct V_5 * V_5 , T_2 V_13 ,
const struct V_11 * V_45 ,
const struct V_11 * V_116 ,
T_8 V_117 , T_1 V_24 )
{
struct V_47 * V_8 ;
if ( F_68 ( ! V_18 ) ) {
F_97 () ;
V_24 = F_9 ( V_45 , V_13 ) ;
}
F_85 ( & V_5 -> V_8 . V_118 ) ;
if ( V_119 &&
F_68 ( F_37 ( & V_5 -> V_8 . V_118 ) > V_119 ) ) {
if ( ! F_93 ( V_5 , V_24 ) ) {
F_101 ( & V_5 -> V_8 . V_118 ) ;
F_102 ( L_5 ) ;
return F_103 ( - V_120 ) ;
}
}
V_8 = F_104 ( V_5 -> V_8 . V_121 , V_117 ) ;
if ( V_8 == NULL ) {
F_101 ( & V_5 -> V_8 . V_118 ) ;
return F_103 ( - V_120 ) ;
}
memset ( & V_8 -> V_48 [ V_122 ] , 0 ,
F_105 ( struct V_47 , V_123 ) -
F_105 ( struct V_47 , V_48 [ V_122 ] ) ) ;
F_106 ( & V_8 -> V_55 ) ;
V_8 -> V_48 [ V_39 ] . V_12 = * V_45 ;
V_8 -> V_48 [ V_39 ] . V_49 . V_96 = NULL ;
V_8 -> V_48 [ V_50 ] . V_12 = * V_116 ;
* ( unsigned long * ) ( & V_8 -> V_48 [ V_50 ] . V_49 . V_96 ) = V_24 ;
F_107 ( & V_8 -> V_61 , F_59 , ( unsigned long ) V_8 ) ;
F_108 ( & V_8 -> V_124 , V_5 ) ;
#ifdef F_109
if ( V_13 ) {
struct V_125 * F_47 ;
F_47 = F_110 ( V_8 , V_126 , V_127 ) ;
if ( ! F_47 )
goto V_128;
F_47 -> V_129 = V_13 ;
}
#endif
F_77 ( & V_8 -> V_84 . V_60 , 0 ) ;
return V_8 ;
#ifdef F_109
V_128:
F_101 ( & V_5 -> V_8 . V_118 ) ;
F_111 ( V_5 -> V_8 . V_121 , V_8 ) ;
return F_103 ( - V_120 ) ;
#endif
}
struct V_47 * F_112 ( struct V_5 * V_5 , T_2 V_13 ,
const struct V_11 * V_45 ,
const struct V_11 * V_116 ,
T_8 V_117 )
{
return F_100 ( V_5 , V_13 , V_45 , V_116 , V_117 , 0 ) ;
}
void F_45 ( struct V_47 * V_8 )
{
struct V_5 * V_5 = F_29 ( V_8 ) ;
F_36 ( F_37 ( & V_8 -> V_84 . V_60 ) == 0 ) ;
F_113 ( V_8 ) ;
F_114 ( V_8 ) ;
F_111 ( V_5 -> V_8 . V_121 , V_8 ) ;
F_115 () ;
F_101 ( & V_5 -> V_8 . V_118 ) ;
}
static struct V_76 *
F_116 ( struct V_5 * V_5 , struct V_47 * V_89 ,
const struct V_11 * V_12 ,
struct V_33 * V_34 ,
struct V_35 * V_36 ,
struct V_28 * V_29 ,
unsigned int V_31 , T_1 V_24 )
{
struct V_47 * V_8 ;
struct V_92 * V_93 ;
struct V_11 V_130 ;
struct V_131 * V_132 ;
struct V_133 * exp = NULL ;
T_2 V_13 = V_89 ? F_47 ( V_89 ) : V_134 ;
struct V_135 * V_136 ;
unsigned int * V_137 ;
if ( ! F_21 ( & V_130 , V_12 , V_34 , V_36 ) ) {
F_23 ( L_6 ) ;
return NULL ;
}
V_8 = F_100 ( V_5 , V_13 , V_12 , & V_130 , V_127 ,
V_24 ) ;
if ( F_117 ( V_8 ) )
return (struct V_76 * ) V_8 ;
if ( V_89 && F_118 ( V_89 ) ) {
F_119 ( V_8 ) ;
F_120 ( V_8 ) ;
}
V_136 = V_89 ? F_121 ( V_89 ) : NULL ;
if ( V_136 )
V_137 = F_122 ( V_136 ) ;
else
V_137 = V_36 -> V_138 ( V_5 ) ;
if ( ! V_36 -> V_139 ( V_8 , V_29 , V_31 , V_137 ) ) {
F_45 ( V_8 ) ;
F_23 ( L_7 ) ;
return NULL ;
}
if ( V_136 )
F_123 ( V_8 , V_136 -> V_61 , V_127 ) ;
F_124 ( V_8 , V_127 ) ;
F_125 ( V_8 , V_127 ) ;
F_126 ( V_8 ) ;
V_132 = V_89 ? F_127 ( V_89 ) : NULL ;
F_128 ( V_8 , V_132 ? V_132 -> V_140 : 0 ,
V_132 ? V_132 -> V_141 : 0 ,
V_127 ) ;
F_41 () ;
if ( V_5 -> V_8 . V_142 ) {
F_4 ( & V_143 ) ;
exp = F_129 ( V_5 , V_13 , V_12 ) ;
if ( exp ) {
F_23 ( L_8 ,
V_8 , exp ) ;
F_79 ( V_144 , & V_8 -> V_74 ) ;
V_8 -> V_64 = exp -> V_64 ;
if ( exp -> V_102 ) {
V_93 = F_130 ( V_8 , exp -> V_102 ,
V_127 ) ;
if ( V_93 )
F_131 ( V_93 -> V_102 , exp -> V_102 ) ;
}
#ifdef F_132
V_8 -> V_145 = exp -> V_64 -> V_145 ;
#endif
#ifdef F_133
V_8 -> V_146 = exp -> V_64 -> V_146 ;
#endif
F_42 ( V_5 , V_147 ) ;
}
F_2 ( & V_143 ) ;
}
if ( ! exp ) {
F_134 ( V_8 , V_89 , V_127 ) ;
F_42 ( V_5 , V_139 ) ;
}
F_80 ( & V_8 -> V_84 ) ;
F_31 ( V_8 ) ;
F_43 () ;
if ( exp ) {
if ( exp -> V_148 )
exp -> V_148 ( V_8 , exp ) ;
F_135 ( exp ) ;
}
return & V_8 -> V_48 [ V_39 ] ;
}
static inline struct V_47 *
F_136 ( struct V_5 * V_5 , struct V_47 * V_89 ,
struct V_28 * V_29 ,
unsigned int V_31 ,
T_4 V_32 ,
T_5 V_23 ,
struct V_33 * V_34 ,
struct V_35 * V_36 ,
int * V_149 ,
enum V_94 * V_95 )
{
struct V_11 V_12 ;
struct V_76 * V_77 ;
struct V_47 * V_8 ;
T_2 V_13 = V_89 ? F_47 ( V_89 ) : V_134 ;
T_1 V_24 ;
if ( ! F_15 ( V_29 , F_137 ( V_29 ) ,
V_31 , V_32 , V_23 , & V_12 , V_34 ,
V_36 ) ) {
F_23 ( L_9 ) ;
return NULL ;
}
V_24 = F_9 ( & V_12 , V_13 ) ;
V_77 = F_67 ( V_5 , V_13 , & V_12 , V_24 ) ;
if ( ! V_77 ) {
V_77 = F_116 ( V_5 , V_89 , & V_12 , V_34 , V_36 ,
V_29 , V_31 , V_24 ) ;
if ( ! V_77 )
return NULL ;
if ( F_117 ( V_77 ) )
return ( void * ) V_77 ;
}
V_8 = F_61 ( V_77 ) ;
if ( F_138 ( V_77 ) == V_50 ) {
* V_95 = V_150 ;
* V_149 = 1 ;
} else {
if ( F_94 ( V_151 , & V_8 -> V_74 ) ) {
F_23 ( L_10 , V_8 ) ;
* V_95 = V_152 ;
} else if ( F_94 ( V_144 , & V_8 -> V_74 ) ) {
F_23 ( L_11 ,
V_8 ) ;
* V_95 = V_153 ;
} else {
F_23 ( L_12 , V_8 ) ;
* V_95 = V_154 ;
}
* V_149 = 0 ;
}
V_29 -> V_59 = & V_8 -> V_84 ;
V_29 -> V_155 = * V_95 ;
return V_8 ;
}
unsigned int
F_139 ( struct V_5 * V_5 , T_5 V_156 , unsigned int V_157 ,
struct V_28 * V_29 )
{
struct V_47 * V_8 , * V_89 = NULL ;
enum V_94 V_95 ;
struct V_33 * V_34 ;
struct V_35 * V_36 ;
unsigned int * V_137 ;
unsigned int V_31 ;
T_5 V_23 ;
int V_149 = 0 ;
int V_41 ;
if ( V_29 -> V_59 ) {
V_89 = (struct V_47 * ) V_29 -> V_59 ;
if ( ! F_140 ( V_89 ) ) {
F_96 ( V_5 , V_158 ) ;
return V_43 ;
}
V_29 -> V_59 = NULL ;
}
V_34 = F_18 ( V_156 ) ;
V_41 = V_34 -> V_42 ( V_29 , F_137 ( V_29 ) ,
& V_31 , & V_23 ) ;
if ( V_41 <= 0 ) {
F_23 ( L_13 ) ;
F_96 ( V_5 , error ) ;
F_96 ( V_5 , V_159 ) ;
V_41 = - V_41 ;
goto V_85;
}
V_36 = F_20 ( V_156 , V_23 ) ;
if ( V_36 -> error != NULL ) {
V_41 = V_36 -> error ( V_5 , V_89 , V_29 , V_31 , & V_95 ,
V_156 , V_157 ) ;
if ( V_41 <= 0 ) {
F_96 ( V_5 , error ) ;
F_96 ( V_5 , V_159 ) ;
V_41 = - V_41 ;
goto V_85;
}
if ( V_29 -> V_59 )
goto V_85;
}
V_8 = F_136 ( V_5 , V_89 , V_29 , V_31 , V_156 , V_23 ,
V_34 , V_36 , & V_149 , & V_95 ) ;
if ( ! V_8 ) {
F_96 ( V_5 , V_159 ) ;
V_41 = V_43 ;
goto V_85;
}
if ( F_117 ( V_8 ) ) {
F_96 ( V_5 , V_160 ) ;
V_41 = V_106 ;
goto V_85;
}
F_36 ( V_29 -> V_59 ) ;
V_137 = F_141 ( V_5 , V_8 , V_36 ) ;
V_41 = V_36 -> V_161 ( V_8 , V_29 , V_31 , V_95 , V_156 , V_157 , V_137 ) ;
if ( V_41 <= 0 ) {
F_23 ( L_14 ) ;
F_142 ( V_29 -> V_59 ) ;
V_29 -> V_59 = NULL ;
F_96 ( V_5 , V_159 ) ;
if ( V_41 == - V_106 )
F_96 ( V_5 , V_160 ) ;
V_41 = - V_41 ;
goto V_85;
}
if ( V_149 && ! F_143 ( V_151 , & V_8 -> V_74 ) )
F_88 ( V_162 , V_8 ) ;
V_85:
if ( V_89 ) {
if ( V_41 == V_163 )
V_29 -> V_59 = (struct V_58 * ) V_89 ;
else
F_44 ( V_89 ) ;
}
return V_41 ;
}
bool F_144 ( struct V_11 * V_44 ,
const struct V_11 * V_45 )
{
bool V_41 ;
F_17 () ;
V_41 = F_21 ( V_44 , V_45 ,
F_18 ( V_45 -> V_15 . V_32 ) ,
F_20 ( V_45 -> V_15 . V_32 ,
V_45 -> V_16 . V_23 ) ) ;
F_19 () ;
return V_41 ;
}
void F_145 ( struct V_47 * V_8 ,
const struct V_11 * V_164 )
{
struct V_92 * V_93 = F_87 ( V_8 ) ;
F_36 ( ! F_63 ( V_8 ) ) ;
F_23 ( L_15 , V_8 ) ;
F_146 ( V_164 ) ;
V_8 -> V_48 [ V_50 ] . V_12 = * V_164 ;
if ( V_8 -> V_64 || ( V_93 && ! F_147 ( & V_93 -> V_165 ) ) )
return;
F_17 () ;
F_134 ( V_8 , NULL , V_127 ) ;
F_19 () ;
}
void F_148 ( struct V_47 * V_8 ,
enum V_94 V_95 ,
const struct V_28 * V_29 ,
unsigned long V_166 ,
int V_167 )
{
F_36 ( V_8 -> V_61 . V_168 == ( unsigned long ) V_8 ) ;
F_36 ( V_29 ) ;
if ( F_94 ( V_169 , & V_8 -> V_74 ) )
goto V_170;
if ( ! F_63 ( V_8 ) ) {
V_8 -> V_61 . V_97 = V_166 ;
} else {
unsigned long V_171 = V_98 + V_166 ;
if ( V_171 - V_8 -> V_61 . V_97 >= V_172 )
F_149 ( & V_8 -> V_61 , V_171 ) ;
}
V_170:
if ( V_167 ) {
struct V_173 * V_170 ;
V_170 = F_150 ( V_8 ) ;
if ( V_170 ) {
struct V_174 * V_175 = V_170 -> V_175 ;
F_151 ( & V_175 [ F_84 ( V_95 ) ] . V_176 ) ;
F_152 ( V_29 -> V_177 , & V_175 [ F_84 ( V_95 ) ] . V_178 ) ;
}
}
}
bool F_153 ( struct V_47 * V_8 ,
enum V_94 V_95 ,
const struct V_28 * V_29 ,
int V_167 )
{
if ( V_167 ) {
struct V_173 * V_170 ;
V_170 = F_150 ( V_8 ) ;
if ( V_170 ) {
struct V_174 * V_175 = V_170 -> V_175 ;
F_151 ( & V_175 [ F_84 ( V_95 ) ] . V_176 ) ;
F_152 ( V_29 -> V_177 - F_137 ( V_29 ) ,
& V_175 [ F_84 ( V_95 ) ] . V_178 ) ;
}
}
if ( F_95 ( & V_8 -> V_61 ) ) {
V_8 -> V_61 . V_179 ( ( unsigned long ) V_8 ) ;
return true ;
}
return false ;
}
int F_154 ( struct V_28 * V_29 ,
const struct V_11 * V_12 )
{
if ( F_155 ( V_29 , V_180 , V_12 -> V_15 . V_21 . V_181 . V_182 ) ||
F_155 ( V_29 , V_183 , V_12 -> V_16 . V_21 . V_181 . V_182 ) )
goto V_184;
return 0 ;
V_184:
return - 1 ;
}
int F_156 ( struct V_185 * V_186 [] ,
struct V_11 * V_187 )
{
if ( ! V_186 [ V_180 ] || ! V_186 [ V_183 ] )
return - V_188 ;
V_187 -> V_15 . V_21 . V_181 . V_182 = F_157 ( V_186 [ V_180 ] ) ;
V_187 -> V_16 . V_21 . V_181 . V_182 = F_157 ( V_186 [ V_183 ] ) ;
return 0 ;
}
int F_158 ( void )
{
return F_159 ( V_189 , V_190 + 1 ) ;
}
static void F_160 ( struct V_28 * V_191 , const struct V_28 * V_29 )
{
struct V_47 * V_8 ;
enum V_94 V_95 ;
V_8 = F_83 ( V_29 , & V_95 ) ;
if ( F_84 ( V_95 ) == V_39 )
V_95 = V_192 ;
else
V_95 = V_153 ;
V_191 -> V_59 = & V_8 -> V_84 ;
V_191 -> V_155 = V_95 ;
F_80 ( V_191 -> V_59 ) ;
}
static struct V_47 *
F_161 ( struct V_5 * V_5 , int (* F_162)( struct V_47 * V_10 , void * V_168 ) ,
void * V_168 , unsigned int * V_79 )
{
struct V_76 * V_77 ;
struct V_47 * V_8 ;
struct V_78 * V_14 ;
int V_53 ;
T_7 * V_112 ;
for (; * V_79 < V_5 -> V_8 . V_27 ; ( * V_79 ) ++ ) {
V_112 = & V_4 [ * V_79 % V_3 ] ;
F_41 () ;
F_4 ( V_112 ) ;
if ( * V_79 < V_5 -> V_8 . V_27 ) {
F_74 (h, n, &net->ct.hash[*bucket], hnnode) {
if ( F_138 ( V_77 ) != V_39 )
continue;
V_8 = F_61 ( V_77 ) ;
if ( F_162 ( V_8 , V_168 ) )
goto V_81;
}
}
F_2 ( V_112 ) ;
F_43 () ;
}
F_163 (cpu) {
struct V_51 * V_52 = F_28 ( V_5 -> V_8 . V_54 , V_53 ) ;
F_164 ( & V_52 -> V_55 ) ;
F_74 (h, n, &pcpu->unconfirmed, hnnode) {
V_8 = F_61 ( V_77 ) ;
if ( F_162 ( V_8 , V_168 ) )
F_58 ( V_73 , & V_8 -> V_74 ) ;
}
F_81 ( & V_52 -> V_55 ) ;
}
return NULL ;
V_81:
F_85 ( & V_8 -> V_84 . V_60 ) ;
F_2 ( V_112 ) ;
F_43 () ;
return V_8 ;
}
void F_165 ( struct V_5 * V_5 ,
int (* F_162)( struct V_47 * V_10 , void * V_168 ) ,
void * V_168 , T_1 V_67 , int V_68 )
{
struct V_47 * V_8 ;
unsigned int V_79 = 0 ;
while ( ( V_8 = F_161 ( V_5 , F_162 , V_168 , & V_79 ) ) != NULL ) {
if ( F_95 ( & V_8 -> V_61 ) )
F_50 ( V_8 , V_67 , V_68 ) ;
F_44 ( V_8 ) ;
}
}
static int F_166 ( struct V_47 * V_10 , void * V_168 )
{
return 1 ;
}
void F_167 ( void * V_24 , unsigned int V_25 )
{
if ( F_168 ( V_24 ) )
F_169 ( V_24 ) ;
else
F_170 ( ( unsigned long ) V_24 ,
F_171 ( sizeof( struct V_193 ) * V_25 ) ) ;
}
void F_172 ( struct V_5 * V_5 , T_1 V_67 , int V_68 )
{
F_165 ( V_5 , F_166 , NULL , V_67 , V_68 ) ;
}
static int F_173 ( void )
{
int V_110 = 0 , V_53 ;
F_163 (cpu) {
struct V_47 * V_8 = & F_174 ( V_194 , V_53 ) ;
V_110 += F_37 ( & V_8 -> V_84 . V_60 ) - 1 ;
}
return V_110 ;
}
void F_175 ( void )
{
F_176 ( V_195 , NULL ) ;
}
void F_177 ( void )
{
F_176 ( V_196 , NULL ) ;
while ( F_173 () > 0 )
F_178 () ;
#ifdef F_109
F_179 ( & V_197 ) ;
#endif
F_180 () ;
F_181 () ;
F_182 () ;
F_183 () ;
F_184 () ;
F_185 () ;
F_186 () ;
F_187 () ;
F_188 () ;
}
void F_189 ( struct V_5 * V_5 )
{
F_190 ( V_198 ) ;
F_191 ( & V_5 -> V_199 , & V_198 ) ;
F_192 ( & V_198 ) ;
}
void F_192 ( struct V_200 * V_201 )
{
int V_202 ;
struct V_5 * V_5 ;
F_193 () ;
V_203:
V_202 = 0 ;
F_194 (net, net_exit_list, exit_list) {
F_165 ( V_5 , F_166 , NULL , 0 , 0 ) ;
if ( F_37 ( & V_5 -> V_8 . V_118 ) != 0 )
V_202 = 1 ;
}
if ( V_202 ) {
F_178 () ;
goto V_203;
}
F_194 (net, net_exit_list, exit_list) {
F_167 ( V_5 -> V_8 . V_24 , V_5 -> V_8 . V_27 ) ;
F_195 ( V_5 ) ;
F_196 ( V_5 ) ;
F_197 ( V_5 ) ;
F_198 ( V_5 ) ;
F_199 ( V_5 ) ;
F_200 ( V_5 ) ;
F_201 ( V_5 -> V_8 . V_121 ) ;
F_202 ( V_5 -> V_8 . V_204 ) ;
F_203 ( V_5 -> V_8 . V_205 ) ;
F_203 ( V_5 -> V_8 . V_54 ) ;
}
}
void * F_204 ( unsigned int * V_206 , int V_207 )
{
struct V_208 * V_24 ;
unsigned int V_209 , V_10 ;
T_9 V_210 ;
F_205 ( sizeof( struct V_208 ) != sizeof( struct V_193 ) ) ;
V_209 = * V_206 = F_206 ( * V_206 , V_211 / sizeof( struct V_208 ) ) ;
V_210 = V_209 * sizeof( struct V_208 ) ;
V_24 = ( void * ) F_207 ( V_212 | V_213 | V_214 ,
F_171 ( V_210 ) ) ;
if ( ! V_24 ) {
F_208 ( V_215 L_16 ) ;
V_24 = F_209 ( V_210 ) ;
}
if ( V_24 && V_207 )
for ( V_10 = 0 ; V_10 < V_209 ; V_10 ++ )
F_210 ( & V_24 [ V_10 ] , V_10 ) ;
return V_24 ;
}
int F_211 ( const char * V_216 , struct V_217 * V_218 )
{
int V_10 , V_79 , V_219 ;
unsigned int V_220 , V_221 ;
struct V_208 * V_24 , * V_222 ;
struct V_76 * V_77 ;
struct V_47 * V_8 ;
if ( V_223 -> V_224 -> V_225 != & V_226 )
return - V_227 ;
if ( ! V_228 )
return F_212 ( V_216 , V_218 ) ;
V_219 = F_213 ( V_216 , 0 , & V_220 ) ;
if ( V_219 )
return V_219 ;
if ( ! V_220 )
return - V_188 ;
V_24 = F_204 ( & V_220 , 1 ) ;
if ( ! V_24 )
return - V_120 ;
F_41 () ;
F_7 () ;
F_214 ( & V_226 . V_8 . V_9 ) ;
for ( V_10 = 0 ; V_10 < V_226 . V_8 . V_27 ; V_10 ++ ) {
while ( ! F_215 ( & V_226 . V_8 . V_24 [ V_10 ] ) ) {
V_77 = F_216 ( V_226 . V_8 . V_24 [ V_10 ] . V_229 ,
struct V_76 , V_49 ) ;
V_8 = F_61 ( V_77 ) ;
F_24 ( & V_77 -> V_49 ) ;
V_79 = F_13 ( & V_77 -> V_12 , F_47 ( V_8 ) ,
V_220 ) ;
F_72 ( & V_77 -> V_49 , & V_24 [ V_79 ] ) ;
}
}
V_221 = V_226 . V_8 . V_27 ;
V_222 = V_226 . V_8 . V_24 ;
V_226 . V_8 . V_27 = V_228 = V_220 ;
V_226 . V_8 . V_24 = V_24 ;
F_217 ( & V_226 . V_8 . V_9 ) ;
F_8 () ;
F_43 () ;
F_167 ( V_222 , V_221 ) ;
return 0 ;
}
void F_218 ( unsigned long V_230 )
{
int V_53 ;
F_163 (cpu)
F_174 ( V_194 , V_53 ) . V_74 |= V_230 ;
}
int F_219 ( void )
{
int V_231 = 8 ;
int V_10 , V_41 , V_53 ;
for ( V_10 = 0 ; V_10 < V_3 ; V_10 ++ )
F_106 ( & V_4 [ V_10 ] ) ;
if ( ! V_228 ) {
V_228
= ( ( ( V_232 << V_233 ) / 16384 )
/ sizeof( struct V_193 ) ) ;
if ( V_232 > ( 1024 * 1024 * 1024 / V_211 ) )
V_228 = 16384 ;
if ( V_228 < 32 )
V_228 = 32 ;
V_231 = 4 ;
}
V_119 = V_231 * V_228 ;
F_208 ( V_234 L_17 ,
V_235 , V_228 ,
V_119 ) ;
V_41 = F_220 () ;
if ( V_41 < 0 )
goto V_236;
V_41 = F_221 () ;
if ( V_41 < 0 )
goto V_237;
V_41 = F_222 () ;
if ( V_41 < 0 )
goto V_238;
V_41 = F_223 () ;
if ( V_41 < 0 )
goto V_239;
V_41 = F_224 () ;
if ( V_41 < 0 )
goto V_240;
V_41 = F_225 () ;
if ( V_41 < 0 )
goto V_241;
V_41 = F_226 () ;
if ( V_41 < 0 )
goto V_242;
V_41 = F_227 () ;
if ( V_41 < 0 )
goto V_243;
#ifdef F_109
V_41 = F_228 ( & V_197 ) ;
if ( V_41 < 0 )
goto V_244;
#endif
V_41 = F_229 () ;
if ( V_41 < 0 )
goto V_245;
F_163 (cpu) {
struct V_47 * V_8 = & F_174 ( V_194 , V_53 ) ;
F_108 ( & V_8 -> V_124 , & V_226 ) ;
F_77 ( & V_8 -> V_84 . V_60 , 1 ) ;
}
F_218 ( V_99 | V_246 ) ;
return 0 ;
V_245:
#ifdef F_109
F_179 ( & V_197 ) ;
V_244:
#endif
F_181 () ;
V_243:
F_182 () ;
V_242:
F_183 () ;
V_241:
F_184 () ;
V_240:
F_185 () ;
V_239:
F_186 () ;
V_238:
F_187 () ;
V_237:
F_188 () ;
V_236:
return V_41 ;
}
void F_230 ( void )
{
F_176 ( V_195 , F_160 ) ;
F_176 ( V_196 , F_35 ) ;
}
int F_231 ( struct V_5 * V_5 )
{
int V_41 = - V_120 ;
int V_53 ;
F_77 ( & V_5 -> V_8 . V_118 , 0 ) ;
F_232 ( & V_5 -> V_8 . V_9 ) ;
V_5 -> V_8 . V_54 = F_233 ( struct V_51 ) ;
if ( ! V_5 -> V_8 . V_54 )
goto V_247;
F_163 (cpu) {
struct V_51 * V_52 = F_28 ( V_5 -> V_8 . V_54 , V_53 ) ;
F_106 ( & V_52 -> V_55 ) ;
F_210 ( & V_52 -> V_57 , V_248 ) ;
F_210 ( & V_52 -> V_56 , V_249 ) ;
F_210 ( & V_52 -> V_89 , V_250 ) ;
}
V_5 -> V_8 . V_205 = F_233 ( struct V_251 ) ;
if ( ! V_5 -> V_8 . V_205 )
goto V_252;
V_5 -> V_8 . V_204 = F_234 ( V_212 , L_18 , V_5 ) ;
if ( ! V_5 -> V_8 . V_204 )
goto V_253;
V_5 -> V_8 . V_121 = F_235 ( V_5 -> V_8 . V_204 ,
sizeof( struct V_47 ) , 0 ,
V_254 , NULL ) ;
if ( ! V_5 -> V_8 . V_121 ) {
F_208 ( V_255 L_19 ) ;
goto V_256;
}
V_5 -> V_8 . V_27 = V_228 ;
V_5 -> V_8 . V_24 = F_204 ( & V_5 -> V_8 . V_27 , 1 ) ;
if ( ! V_5 -> V_8 . V_24 ) {
F_208 ( V_255 L_20 ) ;
goto V_257;
}
V_41 = F_236 ( V_5 ) ;
if ( V_41 < 0 )
goto V_236;
V_41 = F_237 ( V_5 ) ;
if ( V_41 < 0 )
goto V_237;
V_41 = F_238 ( V_5 ) ;
if ( V_41 < 0 )
goto V_238;
V_41 = F_239 ( V_5 ) ;
if ( V_41 < 0 )
goto V_239;
V_41 = F_240 ( V_5 ) ;
if ( V_41 < 0 )
goto V_241;
V_41 = F_241 ( V_5 ) ;
if ( V_41 < 0 )
goto V_245;
return 0 ;
V_245:
F_196 ( V_5 ) ;
V_241:
F_197 ( V_5 ) ;
V_239:
F_198 ( V_5 ) ;
V_238:
F_199 ( V_5 ) ;
V_237:
F_200 ( V_5 ) ;
V_236:
F_167 ( V_5 -> V_8 . V_24 , V_5 -> V_8 . V_27 ) ;
V_257:
F_201 ( V_5 -> V_8 . V_121 ) ;
V_256:
F_202 ( V_5 -> V_8 . V_204 ) ;
V_253:
F_203 ( V_5 -> V_8 . V_205 ) ;
V_252:
F_203 ( V_5 -> V_8 . V_54 ) ;
V_247:
return V_41 ;
}
