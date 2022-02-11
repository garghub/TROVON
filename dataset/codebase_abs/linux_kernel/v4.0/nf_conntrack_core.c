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
return F_12 ( V_24 , V_25 ) ;
}
static T_1 F_13 ( T_1 V_24 , const struct V_5 * V_5 )
{
return F_11 ( V_24 , V_5 -> V_8 . V_26 ) ;
}
static T_3 F_14 ( const struct V_11 * V_12 ,
T_2 V_13 , unsigned int V_25 )
{
return F_11 ( F_9 ( V_12 , V_13 ) , V_25 ) ;
}
static inline T_3 F_15 ( const struct V_5 * V_5 , T_2 V_13 ,
const struct V_11 * V_12 )
{
return F_14 ( V_12 , V_13 , V_5 -> V_8 . V_26 ) ;
}
bool
F_16 ( const struct V_27 * V_28 ,
unsigned int V_29 ,
unsigned int V_30 ,
T_4 V_31 ,
T_5 V_23 ,
struct V_11 * V_12 ,
const struct V_32 * V_33 ,
const struct V_34 * V_35 )
{
memset ( V_12 , 0 , sizeof( * V_12 ) ) ;
V_12 -> V_15 . V_31 = V_31 ;
if ( V_33 -> V_36 ( V_28 , V_29 , V_12 ) == 0 )
return false ;
V_12 -> V_16 . V_23 = V_23 ;
V_12 -> V_16 . V_37 = V_38 ;
return V_35 -> V_36 ( V_28 , V_30 , V_12 ) ;
}
bool F_17 ( const struct V_27 * V_28 , unsigned int V_29 ,
T_4 V_31 , struct V_11 * V_12 )
{
struct V_32 * V_33 ;
struct V_34 * V_35 ;
unsigned int V_39 ;
T_5 V_23 ;
int V_40 ;
F_18 () ;
V_33 = F_19 ( V_31 ) ;
V_40 = V_33 -> V_41 ( V_28 , V_29 , & V_39 , & V_23 ) ;
if ( V_40 != V_42 ) {
F_20 () ;
return false ;
}
V_35 = F_21 ( V_31 , V_23 ) ;
V_40 = F_16 ( V_28 , V_29 , V_39 , V_31 , V_23 , V_12 ,
V_33 , V_35 ) ;
F_20 () ;
return V_40 ;
}
bool
F_22 ( struct V_11 * V_43 ,
const struct V_11 * V_44 ,
const struct V_32 * V_33 ,
const struct V_34 * V_35 )
{
memset ( V_43 , 0 , sizeof( * V_43 ) ) ;
V_43 -> V_15 . V_31 = V_44 -> V_15 . V_31 ;
if ( V_33 -> V_45 ( V_43 , V_44 ) == 0 )
return false ;
V_43 -> V_16 . V_37 = ! V_44 -> V_16 . V_37 ;
V_43 -> V_16 . V_23 = V_44 -> V_16 . V_23 ;
return V_35 -> V_45 ( V_43 , V_44 ) ;
}
static void
F_23 ( struct V_46 * V_8 )
{
F_24 ( L_1 , V_8 ) ;
F_25 ( & V_8 -> V_47 [ V_38 ] . V_48 ) ;
F_25 ( & V_8 -> V_47 [ V_49 ] . V_48 ) ;
F_26 ( V_8 ) ;
}
static void F_27 ( struct V_46 * V_8 )
{
struct V_50 * V_51 ;
V_8 -> V_52 = F_28 () ;
V_51 = F_29 ( F_30 ( V_8 ) -> V_8 . V_53 , V_8 -> V_52 ) ;
F_4 ( & V_51 -> V_54 ) ;
F_31 ( & V_8 -> V_47 [ V_38 ] . V_48 ,
& V_51 -> V_55 ) ;
F_2 ( & V_51 -> V_54 ) ;
}
static void F_32 ( struct V_46 * V_8 )
{
struct V_50 * V_51 ;
V_8 -> V_52 = F_28 () ;
V_51 = F_29 ( F_30 ( V_8 ) -> V_8 . V_53 , V_8 -> V_52 ) ;
F_4 ( & V_51 -> V_54 ) ;
F_31 ( & V_8 -> V_47 [ V_38 ] . V_48 ,
& V_51 -> V_56 ) ;
F_2 ( & V_51 -> V_54 ) ;
}
static void F_33 ( struct V_46 * V_8 )
{
struct V_50 * V_51 ;
V_51 = F_29 ( F_30 ( V_8 ) -> V_8 . V_53 , V_8 -> V_52 ) ;
F_4 ( & V_51 -> V_54 ) ;
F_34 ( F_35 ( & V_8 -> V_47 [ V_38 ] . V_48 ) ) ;
F_25 ( & V_8 -> V_47 [ V_38 ] . V_48 ) ;
F_2 ( & V_51 -> V_54 ) ;
}
static void
F_36 ( struct V_57 * V_58 )
{
struct V_46 * V_8 = (struct V_46 * ) V_58 ;
struct V_5 * V_5 = F_30 ( V_8 ) ;
struct V_34 * V_35 ;
F_24 ( L_2 , V_8 ) ;
F_37 ( F_38 ( & V_58 -> V_59 ) == 0 ) ;
F_37 ( ! F_39 ( & V_8 -> V_60 ) ) ;
F_18 () ;
V_35 = F_21 ( F_40 ( V_8 ) , F_41 ( V_8 ) ) ;
if ( V_35 && V_35 -> V_61 )
V_35 -> V_61 ( V_8 ) ;
F_20 () ;
F_42 () ;
F_26 ( V_8 ) ;
F_33 ( V_8 ) ;
F_43 ( V_5 , V_62 ) ;
F_44 () ;
if ( V_8 -> V_63 )
F_45 ( V_8 -> V_63 ) ;
F_24 ( L_3 , V_8 ) ;
F_46 ( V_8 ) ;
}
static void F_47 ( struct V_46 * V_8 )
{
struct V_5 * V_5 = F_30 ( V_8 ) ;
unsigned int V_24 , V_64 ;
T_2 V_13 = F_48 ( V_8 ) ;
unsigned int V_6 ;
F_49 ( V_8 ) ;
F_42 () ;
do {
V_6 = F_50 ( & V_5 -> V_8 . V_9 ) ;
V_24 = F_15 ( V_5 , V_13 ,
& V_8 -> V_47 [ V_38 ] . V_12 ) ;
V_64 = F_15 ( V_5 , V_13 ,
& V_8 -> V_47 [ V_49 ] . V_12 ) ;
} while ( F_3 ( V_5 , V_24 , V_64 , V_6 ) );
F_23 ( V_8 ) ;
F_1 ( V_24 , V_64 ) ;
F_27 ( V_8 ) ;
F_43 ( V_5 , V_65 ) ;
F_44 () ;
}
bool F_51 ( struct V_46 * V_8 , T_1 V_66 , int V_67 )
{
struct V_68 * V_69 ;
V_69 = F_52 ( V_8 ) ;
if ( V_69 && V_69 -> V_70 == 0 )
V_69 -> V_70 = F_53 () ;
if ( F_54 ( V_8 ) )
goto V_62;
if ( F_55 ( V_71 , V_8 ,
V_66 , V_67 ) < 0 ) {
F_47 ( V_8 ) ;
F_56 ( F_30 ( V_8 ) ) ;
return false ;
}
F_57 ( F_30 ( V_8 ) ) ;
F_58 ( V_72 , & V_8 -> V_73 ) ;
V_62:
F_47 ( V_8 ) ;
F_45 ( V_8 ) ;
return true ;
}
static void F_59 ( unsigned long V_74 )
{
F_51 ( (struct V_46 * ) V_74 , 0 , 0 ) ;
}
static inline bool
F_60 ( struct V_75 * V_76 ,
const struct V_11 * V_12 ,
T_2 V_13 )
{
struct V_46 * V_8 = F_61 ( V_76 ) ;
return F_62 ( V_12 , & V_76 -> V_12 ) &&
F_48 ( V_8 ) == V_13 &&
F_63 ( V_8 ) ;
}
static struct V_75 *
F_64 ( struct V_5 * V_5 , T_2 V_13 ,
const struct V_11 * V_12 , T_1 V_24 )
{
struct V_75 * V_76 ;
struct V_77 * V_14 ;
unsigned int V_78 = F_13 ( V_24 , V_5 ) ;
F_42 () ;
V_79:
F_65 (h, n, &net->ct.hash[bucket], hnnode) {
if ( F_60 ( V_76 , V_12 , V_13 ) ) {
F_43 ( V_5 , V_80 ) ;
F_44 () ;
return V_76 ;
}
F_43 ( V_5 , V_81 ) ;
}
if ( F_66 ( V_14 ) != V_78 ) {
F_43 ( V_5 , V_82 ) ;
goto V_79;
}
F_44 () ;
return NULL ;
}
static struct V_75 *
F_67 ( struct V_5 * V_5 , T_2 V_13 ,
const struct V_11 * V_12 , T_1 V_24 )
{
struct V_75 * V_76 ;
struct V_46 * V_8 ;
F_18 () ;
V_79:
V_76 = F_64 ( V_5 , V_13 , V_12 , V_24 ) ;
if ( V_76 ) {
V_8 = F_61 ( V_76 ) ;
if ( F_68 ( F_54 ( V_8 ) ||
! F_69 ( & V_8 -> V_83 . V_59 ) ) )
V_76 = NULL ;
else {
if ( F_68 ( ! F_60 ( V_76 , V_12 , V_13 ) ) ) {
F_45 ( V_8 ) ;
goto V_79;
}
}
}
F_20 () ;
return V_76 ;
}
struct V_75 *
F_70 ( struct V_5 * V_5 , T_2 V_13 ,
const struct V_11 * V_12 )
{
return F_67 ( V_5 , V_13 , V_12 ,
F_9 ( V_12 , V_13 ) ) ;
}
static void F_71 ( struct V_46 * V_8 ,
unsigned int V_24 ,
unsigned int V_64 )
{
struct V_5 * V_5 = F_30 ( V_8 ) ;
F_72 ( & V_8 -> V_47 [ V_38 ] . V_48 ,
& V_5 -> V_8 . V_24 [ V_24 ] ) ;
F_72 ( & V_8 -> V_47 [ V_49 ] . V_48 ,
& V_5 -> V_8 . V_24 [ V_64 ] ) ;
}
int
F_73 ( struct V_46 * V_8 )
{
struct V_5 * V_5 = F_30 ( V_8 ) ;
unsigned int V_24 , V_64 ;
struct V_75 * V_76 ;
struct V_77 * V_14 ;
T_2 V_13 ;
unsigned int V_6 ;
V_13 = F_48 ( V_8 ) ;
F_42 () ;
do {
V_6 = F_50 ( & V_5 -> V_8 . V_9 ) ;
V_24 = F_15 ( V_5 , V_13 ,
& V_8 -> V_47 [ V_38 ] . V_12 ) ;
V_64 = F_15 ( V_5 , V_13 ,
& V_8 -> V_47 [ V_49 ] . V_12 ) ;
} while ( F_3 ( V_5 , V_24 , V_64 , V_6 ) );
F_74 (h, n, &net->ct.hash[hash], hnnode)
if ( F_62 ( & V_8 -> V_47 [ V_38 ] . V_12 ,
& V_76 -> V_12 ) &&
V_13 == F_48 ( F_61 ( V_76 ) ) )
goto V_84;
F_74 (h, n, &net->ct.hash[reply_hash], hnnode)
if ( F_62 ( & V_8 -> V_47 [ V_49 ] . V_12 ,
& V_76 -> V_12 ) &&
V_13 == F_48 ( F_61 ( V_76 ) ) )
goto V_84;
F_75 ( & V_8 -> V_60 ) ;
F_76 () ;
F_77 ( & V_8 -> V_83 . V_59 , 2 ) ;
F_71 ( V_8 , V_24 , V_64 ) ;
F_1 ( V_24 , V_64 ) ;
F_43 ( V_5 , V_85 ) ;
F_44 () ;
return 0 ;
V_84:
F_1 ( V_24 , V_64 ) ;
F_43 ( V_5 , V_86 ) ;
F_44 () ;
return - V_87 ;
}
void F_78 ( struct V_5 * V_5 , struct V_46 * V_88 )
{
struct V_50 * V_51 ;
F_79 ( V_89 , & V_88 -> V_73 ) ;
F_79 ( V_90 , & V_88 -> V_73 ) ;
F_80 ( & V_88 -> V_83 ) ;
F_42 () ;
V_88 -> V_52 = F_28 () ;
V_51 = F_29 ( F_30 ( V_88 ) -> V_8 . V_53 , V_88 -> V_52 ) ;
F_4 ( & V_51 -> V_54 ) ;
F_72 ( & V_88 -> V_47 [ V_38 ] . V_48 ,
& V_51 -> V_88 ) ;
F_81 ( & V_51 -> V_54 ) ;
}
int
F_82 ( struct V_27 * V_28 )
{
unsigned int V_24 , V_64 ;
struct V_75 * V_76 ;
struct V_46 * V_8 ;
struct V_91 * V_92 ;
struct V_68 * V_69 ;
struct V_77 * V_14 ;
enum V_93 V_94 ;
struct V_5 * V_5 ;
T_2 V_13 ;
unsigned int V_6 ;
V_8 = F_83 ( V_28 , & V_94 ) ;
V_5 = F_30 ( V_8 ) ;
if ( F_84 ( V_94 ) != V_38 )
return V_42 ;
V_13 = F_48 ( V_8 ) ;
F_42 () ;
do {
V_6 = F_50 ( & V_5 -> V_8 . V_9 ) ;
V_24 = * ( unsigned long * ) & V_8 -> V_47 [ V_49 ] . V_48 . V_95 ;
V_24 = F_13 ( V_24 , V_5 ) ;
V_64 = F_15 ( V_5 , V_13 ,
& V_8 -> V_47 [ V_49 ] . V_12 ) ;
} while ( F_3 ( V_5 , V_24 , V_64 , V_6 ) );
F_37 ( ! F_63 ( V_8 ) ) ;
F_24 ( L_4 , V_8 ) ;
F_33 ( V_8 ) ;
if ( F_68 ( F_54 ( V_8 ) ) )
goto V_84;
F_74 (h, n, &net->ct.hash[hash], hnnode)
if ( F_62 ( & V_8 -> V_47 [ V_38 ] . V_12 ,
& V_76 -> V_12 ) &&
V_13 == F_48 ( F_61 ( V_76 ) ) )
goto V_84;
F_74 (h, n, &net->ct.hash[reply_hash], hnnode)
if ( F_62 ( & V_8 -> V_47 [ V_49 ] . V_12 ,
& V_76 -> V_12 ) &&
V_13 == F_48 ( F_61 ( V_76 ) ) )
goto V_84;
V_8 -> V_60 . V_96 += V_97 ;
F_75 ( & V_8 -> V_60 ) ;
F_85 ( & V_8 -> V_83 . V_59 ) ;
V_8 -> V_73 |= V_98 ;
V_69 = F_52 ( V_8 ) ;
if ( V_69 ) {
if ( V_28 -> V_69 . V_99 == 0 )
F_86 ( V_28 ) ;
V_69 -> V_100 = F_87 ( V_28 -> V_69 ) ;
}
F_71 ( V_8 , V_24 , V_64 ) ;
F_1 ( V_24 , V_64 ) ;
F_43 ( V_5 , V_85 ) ;
F_44 () ;
V_92 = F_88 ( V_8 ) ;
if ( V_92 && V_92 -> V_101 )
F_89 ( V_102 , V_8 ) ;
F_89 ( F_90 ( V_8 ) ?
V_103 : V_104 , V_8 ) ;
return V_42 ;
V_84:
F_27 ( V_8 ) ;
F_1 ( V_24 , V_64 ) ;
F_43 ( V_5 , V_86 ) ;
F_44 () ;
return V_105 ;
}
int
F_91 ( const struct V_11 * V_12 ,
const struct V_46 * V_106 )
{
struct V_5 * V_5 = F_30 ( V_106 ) ;
struct V_75 * V_76 ;
struct V_77 * V_14 ;
struct V_46 * V_8 ;
T_2 V_13 = F_48 ( V_106 ) ;
unsigned int V_24 = F_15 ( V_5 , V_13 , V_12 ) ;
F_92 () ;
F_65 (h, n, &net->ct.hash[hash], hnnode) {
V_8 = F_61 ( V_76 ) ;
if ( V_8 != V_106 &&
F_62 ( V_12 , & V_76 -> V_12 ) &&
F_48 ( V_8 ) == V_13 ) {
F_43 ( V_5 , V_80 ) ;
F_93 () ;
return 1 ;
}
F_43 ( V_5 , V_81 ) ;
}
F_93 () ;
return 0 ;
}
static T_6 int F_94 ( struct V_5 * V_5 , unsigned int V_107 )
{
struct V_75 * V_76 ;
struct V_46 * V_8 = NULL , * V_108 ;
struct V_77 * V_14 ;
unsigned int V_10 = 0 , V_109 = 0 ;
int V_110 = 0 ;
unsigned int V_24 , V_6 ;
T_7 * V_111 ;
F_42 () ;
V_112:
V_6 = F_50 ( & V_5 -> V_8 . V_9 ) ;
V_24 = F_13 ( V_107 , V_5 ) ;
for (; V_10 < V_5 -> V_8 . V_26 ; V_10 ++ ) {
V_111 = & V_4 [ V_24 % V_3 ] ;
F_4 ( V_111 ) ;
if ( F_6 ( & V_5 -> V_8 . V_9 , V_6 ) ) {
F_2 ( V_111 ) ;
goto V_112;
}
F_65 (h, n, &net->ct.hash[hash],
hnnode) {
V_108 = F_61 ( V_76 ) ;
if ( ! F_95 ( V_113 , & V_108 -> V_73 ) &&
! F_54 ( V_108 ) &&
F_69 ( & V_108 -> V_83 . V_59 ) ) {
V_8 = V_108 ;
break;
}
V_109 ++ ;
}
V_24 = ( V_24 + 1 ) % V_5 -> V_8 . V_26 ;
F_2 ( V_111 ) ;
if ( V_8 || V_109 >= V_114 )
break;
}
F_44 () ;
if ( ! V_8 )
return V_110 ;
if ( F_96 ( & V_8 -> V_60 ) ) {
if ( F_51 ( V_8 , 0 , 0 ) ) {
V_110 = 1 ;
F_97 ( V_5 , F_94 ) ;
}
}
F_45 ( V_8 ) ;
return V_110 ;
}
void F_98 ( void )
{
unsigned int rand ;
do {
F_99 ( & rand , sizeof( rand ) ) ;
} while ( ! rand );
F_100 ( & V_18 , 0 , rand ) ;
}
static struct V_46 *
F_101 ( struct V_5 * V_5 , T_2 V_13 ,
const struct V_11 * V_44 ,
const struct V_11 * V_115 ,
T_8 V_116 , T_1 V_24 )
{
struct V_46 * V_8 ;
if ( F_68 ( ! V_18 ) ) {
F_98 () ;
V_24 = F_9 ( V_44 , V_13 ) ;
}
F_85 ( & V_5 -> V_8 . V_117 ) ;
if ( V_118 &&
F_68 ( F_38 ( & V_5 -> V_8 . V_117 ) > V_118 ) ) {
if ( ! F_94 ( V_5 , V_24 ) ) {
F_102 ( & V_5 -> V_8 . V_117 ) ;
F_103 ( L_5 ) ;
return F_104 ( - V_119 ) ;
}
}
V_8 = F_105 ( V_5 -> V_8 . V_120 , V_116 ) ;
if ( V_8 == NULL ) {
F_102 ( & V_5 -> V_8 . V_117 ) ;
return F_104 ( - V_119 ) ;
}
F_106 ( & V_8 -> V_54 ) ;
V_8 -> V_47 [ V_38 ] . V_12 = * V_44 ;
V_8 -> V_47 [ V_38 ] . V_48 . V_95 = NULL ;
V_8 -> V_47 [ V_49 ] . V_12 = * V_115 ;
* ( unsigned long * ) ( & V_8 -> V_47 [ V_49 ] . V_48 . V_95 ) = V_24 ;
V_8 -> V_73 = 0 ;
F_107 ( & V_8 -> V_60 , F_59 , ( unsigned long ) V_8 ) ;
F_108 ( & V_8 -> V_121 , V_5 ) ;
memset ( & V_8 -> V_122 [ 0 ] , 0 ,
F_109 ( struct V_46 , V_123 ) -
F_109 ( struct V_46 , V_122 [ 0 ] ) ) ;
#ifdef F_110
if ( V_13 ) {
struct V_124 * F_48 ;
F_48 = F_111 ( V_8 , V_125 , V_126 ) ;
if ( ! F_48 )
goto V_127;
F_48 -> V_128 = V_13 ;
}
#endif
F_77 ( & V_8 -> V_83 . V_59 , 0 ) ;
return V_8 ;
#ifdef F_110
V_127:
F_102 ( & V_5 -> V_8 . V_117 ) ;
F_112 ( V_5 -> V_8 . V_120 , V_8 ) ;
return F_104 ( - V_119 ) ;
#endif
}
struct V_46 * F_113 ( struct V_5 * V_5 , T_2 V_13 ,
const struct V_11 * V_44 ,
const struct V_11 * V_115 ,
T_8 V_116 )
{
return F_101 ( V_5 , V_13 , V_44 , V_115 , V_116 , 0 ) ;
}
void F_46 ( struct V_46 * V_8 )
{
struct V_5 * V_5 = F_30 ( V_8 ) ;
F_37 ( F_38 ( & V_8 -> V_83 . V_59 ) == 0 ) ;
F_114 ( V_8 ) ;
F_115 ( V_8 ) ;
F_112 ( V_5 -> V_8 . V_120 , V_8 ) ;
F_116 () ;
F_102 ( & V_5 -> V_8 . V_117 ) ;
}
static struct V_75 *
F_117 ( struct V_5 * V_5 , struct V_46 * V_88 ,
const struct V_11 * V_12 ,
struct V_32 * V_33 ,
struct V_34 * V_35 ,
struct V_27 * V_28 ,
unsigned int V_30 , T_1 V_24 )
{
struct V_46 * V_8 ;
struct V_91 * V_92 ;
struct V_11 V_129 ;
struct V_130 * V_131 ;
struct V_132 * exp = NULL ;
T_2 V_13 = V_88 ? F_48 ( V_88 ) : V_133 ;
struct V_134 * V_135 ;
unsigned int * V_136 ;
if ( ! F_22 ( & V_129 , V_12 , V_33 , V_35 ) ) {
F_24 ( L_6 ) ;
return NULL ;
}
V_8 = F_101 ( V_5 , V_13 , V_12 , & V_129 , V_126 ,
V_24 ) ;
if ( F_118 ( V_8 ) )
return (struct V_75 * ) V_8 ;
if ( V_88 && F_119 ( V_88 ) ) {
F_120 ( V_8 ) ;
F_121 ( V_8 ) ;
}
V_135 = V_88 ? F_122 ( V_88 ) : NULL ;
if ( V_135 )
V_136 = F_123 ( V_135 ) ;
else
V_136 = V_35 -> V_137 ( V_5 ) ;
if ( ! V_35 -> V_138 ( V_8 , V_28 , V_30 , V_136 ) ) {
F_46 ( V_8 ) ;
F_24 ( L_7 ) ;
return NULL ;
}
if ( V_135 )
F_124 ( V_8 , V_135 -> V_60 , V_126 ) ;
F_125 ( V_8 , V_126 ) ;
F_126 ( V_8 , V_126 ) ;
F_127 ( V_8 ) ;
V_131 = V_88 ? F_128 ( V_88 ) : NULL ;
F_129 ( V_8 , V_131 ? V_131 -> V_139 : 0 ,
V_131 ? V_131 -> V_140 : 0 ,
V_126 ) ;
F_42 () ;
if ( V_5 -> V_8 . V_141 ) {
F_4 ( & V_142 ) ;
exp = F_130 ( V_5 , V_13 , V_12 ) ;
if ( exp ) {
F_24 ( L_8 ,
V_8 , exp ) ;
F_79 ( V_143 , & V_8 -> V_73 ) ;
V_8 -> V_63 = exp -> V_63 ;
if ( exp -> V_101 ) {
V_92 = F_131 ( V_8 , exp -> V_101 ,
V_126 ) ;
if ( V_92 )
F_132 ( V_92 -> V_101 , exp -> V_101 ) ;
}
#ifdef F_133
V_8 -> V_144 = exp -> V_63 -> V_144 ;
#endif
#ifdef F_134
V_8 -> V_145 = exp -> V_63 -> V_145 ;
#endif
F_43 ( V_5 , V_146 ) ;
}
F_2 ( & V_142 ) ;
}
if ( ! exp ) {
F_135 ( V_8 , V_88 , V_126 ) ;
F_43 ( V_5 , V_138 ) ;
}
F_80 ( & V_8 -> V_83 ) ;
F_32 ( V_8 ) ;
F_44 () ;
if ( exp ) {
if ( exp -> V_147 )
exp -> V_147 ( V_8 , exp ) ;
F_136 ( exp ) ;
}
return & V_8 -> V_47 [ V_38 ] ;
}
static inline struct V_46 *
F_137 ( struct V_5 * V_5 , struct V_46 * V_88 ,
struct V_27 * V_28 ,
unsigned int V_30 ,
T_4 V_31 ,
T_5 V_23 ,
struct V_32 * V_33 ,
struct V_34 * V_35 ,
int * V_148 ,
enum V_93 * V_94 )
{
struct V_11 V_12 ;
struct V_75 * V_76 ;
struct V_46 * V_8 ;
T_2 V_13 = V_88 ? F_48 ( V_88 ) : V_133 ;
T_1 V_24 ;
if ( ! F_16 ( V_28 , F_138 ( V_28 ) ,
V_30 , V_31 , V_23 , & V_12 , V_33 ,
V_35 ) ) {
F_24 ( L_9 ) ;
return NULL ;
}
V_24 = F_9 ( & V_12 , V_13 ) ;
V_76 = F_67 ( V_5 , V_13 , & V_12 , V_24 ) ;
if ( ! V_76 ) {
V_76 = F_117 ( V_5 , V_88 , & V_12 , V_33 , V_35 ,
V_28 , V_30 , V_24 ) ;
if ( ! V_76 )
return NULL ;
if ( F_118 ( V_76 ) )
return ( void * ) V_76 ;
}
V_8 = F_61 ( V_76 ) ;
if ( F_139 ( V_76 ) == V_49 ) {
* V_94 = V_149 ;
* V_148 = 1 ;
} else {
if ( F_95 ( V_150 , & V_8 -> V_73 ) ) {
F_24 ( L_10 , V_8 ) ;
* V_94 = V_151 ;
} else if ( F_95 ( V_143 , & V_8 -> V_73 ) ) {
F_24 ( L_11 ,
V_8 ) ;
* V_94 = V_152 ;
} else {
F_24 ( L_12 , V_8 ) ;
* V_94 = V_153 ;
}
* V_148 = 0 ;
}
V_28 -> V_58 = & V_8 -> V_83 ;
V_28 -> V_154 = * V_94 ;
return V_8 ;
}
unsigned int
F_140 ( struct V_5 * V_5 , T_5 V_155 , unsigned int V_156 ,
struct V_27 * V_28 )
{
struct V_46 * V_8 , * V_88 = NULL ;
enum V_93 V_94 ;
struct V_32 * V_33 ;
struct V_34 * V_35 ;
unsigned int * V_136 ;
unsigned int V_30 ;
T_5 V_23 ;
int V_148 = 0 ;
int V_40 ;
if ( V_28 -> V_58 ) {
V_88 = (struct V_46 * ) V_28 -> V_58 ;
if ( ! F_141 ( V_88 ) ) {
F_97 ( V_5 , V_157 ) ;
return V_42 ;
}
V_28 -> V_58 = NULL ;
}
V_33 = F_19 ( V_155 ) ;
V_40 = V_33 -> V_41 ( V_28 , F_138 ( V_28 ) ,
& V_30 , & V_23 ) ;
if ( V_40 <= 0 ) {
F_24 ( L_13 ) ;
F_97 ( V_5 , error ) ;
F_97 ( V_5 , V_158 ) ;
V_40 = - V_40 ;
goto V_84;
}
V_35 = F_21 ( V_155 , V_23 ) ;
if ( V_35 -> error != NULL ) {
V_40 = V_35 -> error ( V_5 , V_88 , V_28 , V_30 , & V_94 ,
V_155 , V_156 ) ;
if ( V_40 <= 0 ) {
F_97 ( V_5 , error ) ;
F_97 ( V_5 , V_158 ) ;
V_40 = - V_40 ;
goto V_84;
}
if ( V_28 -> V_58 )
goto V_84;
}
V_8 = F_137 ( V_5 , V_88 , V_28 , V_30 , V_155 , V_23 ,
V_33 , V_35 , & V_148 , & V_94 ) ;
if ( ! V_8 ) {
F_97 ( V_5 , V_158 ) ;
V_40 = V_42 ;
goto V_84;
}
if ( F_118 ( V_8 ) ) {
F_97 ( V_5 , V_159 ) ;
V_40 = V_105 ;
goto V_84;
}
F_37 ( V_28 -> V_58 ) ;
V_136 = F_142 ( V_5 , V_8 , V_35 ) ;
V_40 = V_35 -> V_160 ( V_8 , V_28 , V_30 , V_94 , V_155 , V_156 , V_136 ) ;
if ( V_40 <= 0 ) {
F_24 ( L_14 ) ;
F_143 ( V_28 -> V_58 ) ;
V_28 -> V_58 = NULL ;
F_97 ( V_5 , V_158 ) ;
if ( V_40 == - V_105 )
F_97 ( V_5 , V_159 ) ;
V_40 = - V_40 ;
goto V_84;
}
if ( V_148 && ! F_144 ( V_150 , & V_8 -> V_73 ) )
F_89 ( V_161 , V_8 ) ;
V_84:
if ( V_88 ) {
if ( V_40 == V_162 )
V_28 -> V_58 = (struct V_57 * ) V_88 ;
else
F_45 ( V_88 ) ;
}
return V_40 ;
}
bool F_145 ( struct V_11 * V_43 ,
const struct V_11 * V_44 )
{
bool V_40 ;
F_18 () ;
V_40 = F_22 ( V_43 , V_44 ,
F_19 ( V_44 -> V_15 . V_31 ) ,
F_21 ( V_44 -> V_15 . V_31 ,
V_44 -> V_16 . V_23 ) ) ;
F_20 () ;
return V_40 ;
}
void F_146 ( struct V_46 * V_8 ,
const struct V_11 * V_163 )
{
struct V_91 * V_92 = F_88 ( V_8 ) ;
F_37 ( ! F_63 ( V_8 ) ) ;
F_24 ( L_15 , V_8 ) ;
F_147 ( V_163 ) ;
V_8 -> V_47 [ V_49 ] . V_12 = * V_163 ;
if ( V_8 -> V_63 || ( V_92 && ! F_148 ( & V_92 -> V_164 ) ) )
return;
F_18 () ;
F_135 ( V_8 , NULL , V_126 ) ;
F_20 () ;
}
void F_149 ( struct V_46 * V_8 ,
enum V_93 V_94 ,
const struct V_27 * V_28 ,
unsigned long V_165 ,
int V_166 )
{
F_37 ( V_8 -> V_60 . V_167 == ( unsigned long ) V_8 ) ;
F_37 ( V_28 ) ;
if ( F_95 ( V_168 , & V_8 -> V_73 ) )
goto V_169;
if ( ! F_63 ( V_8 ) ) {
V_8 -> V_60 . V_96 = V_165 ;
} else {
unsigned long V_170 = V_97 + V_165 ;
if ( V_170 - V_8 -> V_60 . V_96 >= V_171 )
F_150 ( & V_8 -> V_60 , V_170 ) ;
}
V_169:
if ( V_166 ) {
struct V_172 * V_169 ;
V_169 = F_151 ( V_8 ) ;
if ( V_169 ) {
struct V_173 * V_174 = V_169 -> V_174 ;
F_152 ( & V_174 [ F_84 ( V_94 ) ] . V_175 ) ;
F_153 ( V_28 -> V_176 , & V_174 [ F_84 ( V_94 ) ] . V_177 ) ;
}
}
}
bool F_154 ( struct V_46 * V_8 ,
enum V_93 V_94 ,
const struct V_27 * V_28 ,
int V_166 )
{
if ( V_166 ) {
struct V_172 * V_169 ;
V_169 = F_151 ( V_8 ) ;
if ( V_169 ) {
struct V_173 * V_174 = V_169 -> V_174 ;
F_152 ( & V_174 [ F_84 ( V_94 ) ] . V_175 ) ;
F_153 ( V_28 -> V_176 - F_138 ( V_28 ) ,
& V_174 [ F_84 ( V_94 ) ] . V_177 ) ;
}
}
if ( F_96 ( & V_8 -> V_60 ) ) {
V_8 -> V_60 . V_178 ( ( unsigned long ) V_8 ) ;
return true ;
}
return false ;
}
int F_155 ( struct V_27 * V_28 ,
const struct V_11 * V_12 )
{
if ( F_156 ( V_28 , V_179 , V_12 -> V_15 . V_21 . V_180 . V_181 ) ||
F_156 ( V_28 , V_182 , V_12 -> V_16 . V_21 . V_180 . V_181 ) )
goto V_183;
return 0 ;
V_183:
return - 1 ;
}
int F_157 ( struct V_184 * V_185 [] ,
struct V_11 * V_186 )
{
if ( ! V_185 [ V_179 ] || ! V_185 [ V_182 ] )
return - V_187 ;
V_186 -> V_15 . V_21 . V_180 . V_181 = F_158 ( V_185 [ V_179 ] ) ;
V_186 -> V_16 . V_21 . V_180 . V_181 = F_158 ( V_185 [ V_182 ] ) ;
return 0 ;
}
int F_159 ( void )
{
return F_160 ( V_188 , V_189 + 1 ) ;
}
static void F_161 ( struct V_27 * V_190 , const struct V_27 * V_28 )
{
struct V_46 * V_8 ;
enum V_93 V_94 ;
V_8 = F_83 ( V_28 , & V_94 ) ;
if ( F_84 ( V_94 ) == V_38 )
V_94 = V_191 ;
else
V_94 = V_152 ;
V_190 -> V_58 = & V_8 -> V_83 ;
V_190 -> V_154 = V_94 ;
F_80 ( V_190 -> V_58 ) ;
}
static struct V_46 *
F_162 ( struct V_5 * V_5 , int (* F_163)( struct V_46 * V_10 , void * V_167 ) ,
void * V_167 , unsigned int * V_78 )
{
struct V_75 * V_76 ;
struct V_46 * V_8 ;
struct V_77 * V_14 ;
int V_52 ;
T_7 * V_111 ;
for (; * V_78 < V_5 -> V_8 . V_26 ; ( * V_78 ) ++ ) {
V_111 = & V_4 [ * V_78 % V_3 ] ;
F_42 () ;
F_4 ( V_111 ) ;
if ( * V_78 < V_5 -> V_8 . V_26 ) {
F_74 (h, n, &net->ct.hash[*bucket], hnnode) {
if ( F_139 ( V_76 ) != V_38 )
continue;
V_8 = F_61 ( V_76 ) ;
if ( F_163 ( V_8 , V_167 ) )
goto V_80;
}
}
F_2 ( V_111 ) ;
F_44 () ;
}
F_164 (cpu) {
struct V_50 * V_51 = F_29 ( V_5 -> V_8 . V_53 , V_52 ) ;
F_165 ( & V_51 -> V_54 ) ;
F_74 (h, n, &pcpu->unconfirmed, hnnode) {
V_8 = F_61 ( V_76 ) ;
if ( F_163 ( V_8 , V_167 ) )
F_58 ( V_72 , & V_8 -> V_73 ) ;
}
F_81 ( & V_51 -> V_54 ) ;
}
return NULL ;
V_80:
F_85 ( & V_8 -> V_83 . V_59 ) ;
F_2 ( V_111 ) ;
F_44 () ;
return V_8 ;
}
void F_166 ( struct V_5 * V_5 ,
int (* F_163)( struct V_46 * V_10 , void * V_167 ) ,
void * V_167 , T_1 V_66 , int V_67 )
{
struct V_46 * V_8 ;
unsigned int V_78 = 0 ;
while ( ( V_8 = F_162 ( V_5 , F_163 , V_167 , & V_78 ) ) != NULL ) {
if ( F_96 ( & V_8 -> V_60 ) )
F_51 ( V_8 , V_66 , V_67 ) ;
F_45 ( V_8 ) ;
}
}
static int F_167 ( struct V_46 * V_10 , void * V_167 )
{
return 1 ;
}
void F_168 ( void * V_24 , unsigned int V_25 )
{
if ( F_169 ( V_24 ) )
F_170 ( V_24 ) ;
else
F_171 ( ( unsigned long ) V_24 ,
F_172 ( sizeof( struct V_192 ) * V_25 ) ) ;
}
static int F_173 ( void )
{
int V_109 = 0 , V_52 ;
F_164 (cpu) {
struct V_46 * V_8 = & F_174 ( V_193 , V_52 ) ;
V_109 += F_38 ( & V_8 -> V_83 . V_59 ) - 1 ;
}
return V_109 ;
}
void F_175 ( void )
{
F_176 ( V_194 , NULL ) ;
}
void F_177 ( void )
{
F_176 ( V_195 , NULL ) ;
while ( F_173 () > 0 )
F_178 () ;
#ifdef F_110
F_179 ( & V_196 ) ;
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
F_190 ( V_197 ) ;
F_191 ( & V_5 -> V_198 , & V_197 ) ;
F_192 ( & V_197 ) ;
}
void F_192 ( struct V_199 * V_200 )
{
int V_201 ;
struct V_5 * V_5 ;
F_193 () ;
V_202:
V_201 = 0 ;
F_194 (net, net_exit_list, exit_list) {
F_166 ( V_5 , F_167 , NULL , 0 , 0 ) ;
if ( F_38 ( & V_5 -> V_8 . V_117 ) != 0 )
V_201 = 1 ;
}
if ( V_201 ) {
F_178 () ;
goto V_202;
}
F_194 (net, net_exit_list, exit_list) {
F_168 ( V_5 -> V_8 . V_24 , V_5 -> V_8 . V_26 ) ;
F_195 ( V_5 ) ;
F_196 ( V_5 ) ;
F_197 ( V_5 ) ;
F_198 ( V_5 ) ;
F_199 ( V_5 ) ;
F_200 ( V_5 ) ;
F_201 ( V_5 -> V_8 . V_120 ) ;
F_202 ( V_5 -> V_8 . V_203 ) ;
F_203 ( V_5 -> V_8 . V_204 ) ;
F_203 ( V_5 -> V_8 . V_53 ) ;
}
}
void * F_204 ( unsigned int * V_205 , int V_206 )
{
struct V_207 * V_24 ;
unsigned int V_208 , V_10 ;
T_9 V_209 ;
F_205 ( sizeof( struct V_207 ) != sizeof( struct V_192 ) ) ;
V_208 = * V_205 = F_206 ( * V_205 , V_210 / sizeof( struct V_207 ) ) ;
V_209 = V_208 * sizeof( struct V_207 ) ;
V_24 = ( void * ) F_207 ( V_211 | V_212 | V_213 ,
F_172 ( V_209 ) ) ;
if ( ! V_24 ) {
F_208 ( V_214 L_16 ) ;
V_24 = F_209 ( V_209 ) ;
}
if ( V_24 && V_206 )
for ( V_10 = 0 ; V_10 < V_208 ; V_10 ++ )
F_210 ( & V_24 [ V_10 ] , V_10 ) ;
return V_24 ;
}
int F_211 ( const char * V_215 , struct V_216 * V_217 )
{
int V_10 , V_78 , V_218 ;
unsigned int V_219 , V_220 ;
struct V_207 * V_24 , * V_221 ;
struct V_75 * V_76 ;
struct V_46 * V_8 ;
if ( V_222 -> V_223 -> V_224 != & V_225 )
return - V_226 ;
if ( ! V_227 )
return F_212 ( V_215 , V_217 ) ;
V_218 = F_213 ( V_215 , 0 , & V_219 ) ;
if ( V_218 )
return V_218 ;
if ( ! V_219 )
return - V_187 ;
V_24 = F_204 ( & V_219 , 1 ) ;
if ( ! V_24 )
return - V_119 ;
F_42 () ;
F_7 () ;
F_214 ( & V_225 . V_8 . V_9 ) ;
for ( V_10 = 0 ; V_10 < V_225 . V_8 . V_26 ; V_10 ++ ) {
while ( ! F_215 ( & V_225 . V_8 . V_24 [ V_10 ] ) ) {
V_76 = F_216 ( V_225 . V_8 . V_24 [ V_10 ] . V_228 ,
struct V_75 , V_48 ) ;
V_8 = F_61 ( V_76 ) ;
F_25 ( & V_76 -> V_48 ) ;
V_78 = F_14 ( & V_76 -> V_12 , F_48 ( V_8 ) ,
V_219 ) ;
F_72 ( & V_76 -> V_48 , & V_24 [ V_78 ] ) ;
}
}
V_220 = V_225 . V_8 . V_26 ;
V_221 = V_225 . V_8 . V_24 ;
V_225 . V_8 . V_26 = V_227 = V_219 ;
V_225 . V_8 . V_24 = V_24 ;
F_217 ( & V_225 . V_8 . V_9 ) ;
F_8 () ;
F_44 () ;
F_168 ( V_221 , V_220 ) ;
return 0 ;
}
void F_218 ( unsigned long V_229 )
{
int V_52 ;
F_164 (cpu)
F_174 ( V_193 , V_52 ) . V_73 |= V_229 ;
}
int F_219 ( void )
{
int V_230 = 8 ;
int V_10 , V_40 , V_52 ;
for ( V_10 = 0 ; V_10 < V_3 ; V_10 ++ )
F_106 ( & V_4 [ V_10 ] ) ;
if ( ! V_227 ) {
V_227
= ( ( ( V_231 << V_232 ) / 16384 )
/ sizeof( struct V_192 ) ) ;
if ( V_231 > ( 4 * ( 1024 * 1024 * 1024 / V_210 ) ) )
V_227 = 65536 ;
else if ( V_231 > ( 1024 * 1024 * 1024 / V_210 ) )
V_227 = 16384 ;
if ( V_227 < 32 )
V_227 = 32 ;
V_230 = 4 ;
}
V_118 = V_230 * V_227 ;
F_208 ( V_233 L_17 ,
V_234 , V_227 ,
V_118 ) ;
V_40 = F_220 () ;
if ( V_40 < 0 )
goto V_235;
V_40 = F_221 () ;
if ( V_40 < 0 )
goto V_236;
V_40 = F_222 () ;
if ( V_40 < 0 )
goto V_237;
V_40 = F_223 () ;
if ( V_40 < 0 )
goto V_238;
V_40 = F_224 () ;
if ( V_40 < 0 )
goto V_239;
V_40 = F_225 () ;
if ( V_40 < 0 )
goto V_240;
V_40 = F_226 () ;
if ( V_40 < 0 )
goto V_241;
V_40 = F_227 () ;
if ( V_40 < 0 )
goto V_242;
#ifdef F_110
V_40 = F_228 ( & V_196 ) ;
if ( V_40 < 0 )
goto V_243;
#endif
V_40 = F_229 () ;
if ( V_40 < 0 )
goto V_244;
F_164 (cpu) {
struct V_46 * V_8 = & F_174 ( V_193 , V_52 ) ;
F_108 ( & V_8 -> V_121 , & V_225 ) ;
F_77 ( & V_8 -> V_83 . V_59 , 1 ) ;
}
F_218 ( V_98 | V_245 ) ;
return 0 ;
V_244:
#ifdef F_110
F_179 ( & V_196 ) ;
V_243:
#endif
F_181 () ;
V_242:
F_182 () ;
V_241:
F_183 () ;
V_240:
F_184 () ;
V_239:
F_185 () ;
V_238:
F_186 () ;
V_237:
F_187 () ;
V_236:
F_188 () ;
V_235:
return V_40 ;
}
void F_230 ( void )
{
F_176 ( V_194 , F_161 ) ;
F_176 ( V_195 , F_36 ) ;
}
int F_231 ( struct V_5 * V_5 )
{
int V_40 = - V_119 ;
int V_52 ;
F_77 ( & V_5 -> V_8 . V_117 , 0 ) ;
F_232 ( & V_5 -> V_8 . V_9 ) ;
V_5 -> V_8 . V_53 = F_233 ( struct V_50 ) ;
if ( ! V_5 -> V_8 . V_53 )
goto V_246;
F_164 (cpu) {
struct V_50 * V_51 = F_29 ( V_5 -> V_8 . V_53 , V_52 ) ;
F_106 ( & V_51 -> V_54 ) ;
F_210 ( & V_51 -> V_56 , V_247 ) ;
F_210 ( & V_51 -> V_55 , V_248 ) ;
F_210 ( & V_51 -> V_88 , V_249 ) ;
}
V_5 -> V_8 . V_204 = F_233 ( struct V_250 ) ;
if ( ! V_5 -> V_8 . V_204 )
goto V_251;
V_5 -> V_8 . V_203 = F_234 ( V_211 , L_18 , V_5 ) ;
if ( ! V_5 -> V_8 . V_203 )
goto V_252;
V_5 -> V_8 . V_120 = F_235 ( V_5 -> V_8 . V_203 ,
sizeof( struct V_46 ) , 0 ,
V_253 , NULL ) ;
if ( ! V_5 -> V_8 . V_120 ) {
F_208 ( V_254 L_19 ) ;
goto V_255;
}
V_5 -> V_8 . V_26 = V_227 ;
V_5 -> V_8 . V_24 = F_204 ( & V_5 -> V_8 . V_26 , 1 ) ;
if ( ! V_5 -> V_8 . V_24 ) {
F_208 ( V_254 L_20 ) ;
goto V_256;
}
V_40 = F_236 ( V_5 ) ;
if ( V_40 < 0 )
goto V_235;
V_40 = F_237 ( V_5 ) ;
if ( V_40 < 0 )
goto V_236;
V_40 = F_238 ( V_5 ) ;
if ( V_40 < 0 )
goto V_237;
V_40 = F_239 ( V_5 ) ;
if ( V_40 < 0 )
goto V_238;
V_40 = F_240 ( V_5 ) ;
if ( V_40 < 0 )
goto V_240;
V_40 = F_241 ( V_5 ) ;
if ( V_40 < 0 )
goto V_244;
return 0 ;
V_244:
F_196 ( V_5 ) ;
V_240:
F_197 ( V_5 ) ;
V_238:
F_198 ( V_5 ) ;
V_237:
F_199 ( V_5 ) ;
V_236:
F_200 ( V_5 ) ;
V_235:
F_168 ( V_5 -> V_8 . V_24 , V_5 -> V_8 . V_26 ) ;
V_256:
F_201 ( V_5 -> V_8 . V_120 ) ;
V_255:
F_202 ( V_5 -> V_8 . V_203 ) ;
V_252:
F_203 ( V_5 -> V_8 . V_204 ) ;
V_251:
F_203 ( V_5 -> V_8 . V_53 ) ;
V_246:
return V_40 ;
}
