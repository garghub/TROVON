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
static void F_50 ( unsigned long V_67 )
{
struct V_47 * V_8 = ( void * ) V_67 ;
struct V_5 * V_5 = F_29 ( V_8 ) ;
struct V_68 * V_69 = F_51 ( V_8 ) ;
F_33 ( V_69 == NULL ) ;
if ( F_52 ( V_70 , V_8 ) < 0 ) {
V_69 -> V_61 . V_71 = V_72 +
( F_53 () % V_5 -> V_8 . V_73 ) ;
F_54 ( & V_69 -> V_61 ) ;
return;
}
F_55 ( V_74 , & V_8 -> V_75 ) ;
F_44 ( V_8 ) ;
}
static void F_56 ( struct V_47 * V_8 )
{
struct V_5 * V_5 = F_29 ( V_8 ) ;
struct V_68 * V_69 = F_51 ( V_8 ) ;
F_33 ( V_69 == NULL ) ;
F_57 ( & V_69 -> V_61 , F_50 , ( unsigned long ) V_8 ) ;
V_69 -> V_61 . V_71 = V_72 +
( F_53 () % V_5 -> V_8 . V_73 ) ;
F_54 ( & V_69 -> V_61 ) ;
}
bool F_58 ( struct V_47 * V_8 , T_1 V_76 , int V_77 )
{
struct V_78 * V_79 ;
V_79 = F_59 ( V_8 ) ;
if ( V_79 && V_79 -> V_80 == 0 )
V_79 -> V_80 = F_60 ( F_61 () ) ;
if ( ! F_62 ( V_8 ) &&
F_63 ( F_64 ( V_70 , V_8 ,
V_76 , V_77 ) < 0 ) ) {
F_46 ( V_8 ) ;
F_56 ( V_8 ) ;
return false ;
}
F_55 ( V_74 , & V_8 -> V_75 ) ;
F_46 ( V_8 ) ;
F_44 ( V_8 ) ;
return true ;
}
static void F_65 ( unsigned long V_67 )
{
F_58 ( (struct V_47 * ) V_67 , 0 , 0 ) ;
}
static inline bool
F_66 ( struct V_81 * V_82 ,
const struct V_11 * V_12 ,
T_2 V_13 )
{
struct V_47 * V_8 = F_67 ( V_82 ) ;
return F_68 ( V_12 , & V_82 -> V_12 ) &&
F_47 ( V_8 ) == V_13 &&
F_69 ( V_8 ) ;
}
static struct V_81 *
F_70 ( struct V_5 * V_5 , T_2 V_13 ,
const struct V_11 * V_12 , T_1 V_24 )
{
struct V_81 * V_82 ;
struct V_83 * V_14 ;
unsigned int V_84 = F_12 ( V_24 , V_5 ) ;
F_41 () ;
V_85:
F_71 (h, n, &net->ct.hash[bucket], hnnode) {
if ( F_66 ( V_82 , V_12 , V_13 ) ) {
F_42 ( V_5 , V_86 ) ;
F_43 () ;
return V_82 ;
}
F_42 ( V_5 , V_87 ) ;
}
if ( F_72 ( V_14 ) != V_84 ) {
F_42 ( V_5 , V_88 ) ;
goto V_85;
}
F_43 () ;
return NULL ;
}
static struct V_81 *
F_73 ( struct V_5 * V_5 , T_2 V_13 ,
const struct V_11 * V_12 , T_1 V_24 )
{
struct V_81 * V_82 ;
struct V_47 * V_8 ;
F_17 () ;
V_85:
V_82 = F_70 ( V_5 , V_13 , V_12 , V_24 ) ;
if ( V_82 ) {
V_8 = F_67 ( V_82 ) ;
if ( F_63 ( F_62 ( V_8 ) ||
! F_74 ( & V_8 -> V_89 . V_60 ) ) )
V_82 = NULL ;
else {
if ( F_63 ( ! F_66 ( V_82 , V_12 , V_13 ) ) ) {
F_44 ( V_8 ) ;
goto V_85;
}
}
}
F_19 () ;
return V_82 ;
}
struct V_81 *
F_75 ( struct V_5 * V_5 , T_2 V_13 ,
const struct V_11 * V_12 )
{
return F_73 ( V_5 , V_13 , V_12 ,
F_9 ( V_12 , V_13 ) ) ;
}
static void F_76 ( struct V_47 * V_8 ,
unsigned int V_24 ,
unsigned int V_65 )
{
struct V_5 * V_5 = F_29 ( V_8 ) ;
F_77 ( & V_8 -> V_48 [ V_39 ] . V_49 ,
& V_5 -> V_8 . V_24 [ V_24 ] ) ;
F_77 ( & V_8 -> V_48 [ V_50 ] . V_49 ,
& V_5 -> V_8 . V_24 [ V_65 ] ) ;
}
int
F_78 ( struct V_47 * V_8 )
{
struct V_5 * V_5 = F_29 ( V_8 ) ;
unsigned int V_24 , V_65 ;
struct V_81 * V_82 ;
struct V_83 * V_14 ;
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
F_79 (h, n, &net->ct.hash[hash], hnnode)
if ( F_68 ( & V_8 -> V_48 [ V_39 ] . V_12 ,
& V_82 -> V_12 ) &&
V_13 == F_47 ( F_67 ( V_82 ) ) )
goto V_90;
F_79 (h, n, &net->ct.hash[reply_hash], hnnode)
if ( F_68 ( & V_8 -> V_48 [ V_50 ] . V_12 ,
& V_82 -> V_12 ) &&
V_13 == F_47 ( F_67 ( V_82 ) ) )
goto V_90;
F_54 ( & V_8 -> V_61 ) ;
F_80 () ;
F_81 ( & V_8 -> V_89 . V_60 , 2 ) ;
F_76 ( V_8 , V_24 , V_65 ) ;
F_1 ( V_24 , V_65 ) ;
F_42 ( V_5 , V_91 ) ;
F_43 () ;
return 0 ;
V_90:
F_1 ( V_24 , V_65 ) ;
F_42 ( V_5 , V_92 ) ;
F_43 () ;
return - V_93 ;
}
void F_82 ( struct V_5 * V_5 , struct V_47 * V_94 )
{
struct V_51 * V_52 ;
F_83 ( V_95 , & V_94 -> V_75 ) ;
F_83 ( V_96 , & V_94 -> V_75 ) ;
F_84 ( & V_94 -> V_89 ) ;
F_41 () ;
V_94 -> V_53 = F_27 () ;
V_52 = F_28 ( F_29 ( V_94 ) -> V_8 . V_54 , V_94 -> V_53 ) ;
F_4 ( & V_52 -> V_55 ) ;
F_77 ( & V_94 -> V_48 [ V_39 ] . V_49 ,
& V_52 -> V_94 ) ;
F_85 ( & V_52 -> V_55 ) ;
}
int
F_86 ( struct V_28 * V_29 )
{
unsigned int V_24 , V_65 ;
struct V_81 * V_82 ;
struct V_47 * V_8 ;
struct V_97 * V_98 ;
struct V_78 * V_79 ;
struct V_83 * V_14 ;
enum V_99 V_100 ;
struct V_5 * V_5 ;
T_2 V_13 ;
unsigned int V_6 ;
V_8 = F_87 ( V_29 , & V_100 ) ;
V_5 = F_29 ( V_8 ) ;
if ( F_88 ( V_100 ) != V_39 )
return V_43 ;
V_13 = F_47 ( V_8 ) ;
F_41 () ;
do {
V_6 = F_49 ( & V_5 -> V_8 . V_9 ) ;
V_24 = * ( unsigned long * ) & V_8 -> V_48 [ V_50 ] . V_49 . V_101 ;
V_24 = F_12 ( V_24 , V_5 ) ;
V_65 = F_14 ( V_5 , V_13 ,
& V_8 -> V_48 [ V_50 ] . V_12 ) ;
} while ( F_3 ( V_5 , V_24 , V_65 , V_6 ) );
F_36 ( ! F_69 ( V_8 ) ) ;
F_23 ( L_4 , V_8 ) ;
if ( F_63 ( F_62 ( V_8 ) ) ) {
F_1 ( V_24 , V_65 ) ;
F_43 () ;
return V_43 ;
}
F_79 (h, n, &net->ct.hash[hash], hnnode)
if ( F_68 ( & V_8 -> V_48 [ V_39 ] . V_12 ,
& V_82 -> V_12 ) &&
V_13 == F_47 ( F_67 ( V_82 ) ) )
goto V_90;
F_79 (h, n, &net->ct.hash[reply_hash], hnnode)
if ( F_68 ( & V_8 -> V_48 [ V_50 ] . V_12 ,
& V_82 -> V_12 ) &&
V_13 == F_47 ( F_67 ( V_82 ) ) )
goto V_90;
F_32 ( V_8 ) ;
V_8 -> V_61 . V_71 += V_72 ;
F_54 ( & V_8 -> V_61 ) ;
F_89 ( & V_8 -> V_89 . V_60 ) ;
V_8 -> V_75 |= V_102 ;
V_79 = F_59 ( V_8 ) ;
if ( V_79 ) {
if ( V_29 -> V_79 . V_103 == 0 )
F_90 ( V_29 ) ;
V_79 -> V_104 = F_60 ( V_29 -> V_79 ) ;
}
F_76 ( V_8 , V_24 , V_65 ) ;
F_1 ( V_24 , V_65 ) ;
F_42 ( V_5 , V_91 ) ;
F_43 () ;
V_98 = F_91 ( V_8 ) ;
if ( V_98 && V_98 -> V_105 )
F_92 ( V_106 , V_8 ) ;
F_92 ( F_93 ( V_8 ) ?
V_107 : V_108 , V_8 ) ;
return V_43 ;
V_90:
F_1 ( V_24 , V_65 ) ;
F_42 ( V_5 , V_92 ) ;
F_43 () ;
return V_109 ;
}
int
F_94 ( const struct V_11 * V_12 ,
const struct V_47 * V_110 )
{
struct V_5 * V_5 = F_29 ( V_110 ) ;
struct V_81 * V_82 ;
struct V_83 * V_14 ;
struct V_47 * V_8 ;
T_2 V_13 = F_47 ( V_110 ) ;
unsigned int V_24 = F_14 ( V_5 , V_13 , V_12 ) ;
F_95 () ;
F_71 (h, n, &net->ct.hash[hash], hnnode) {
V_8 = F_67 ( V_82 ) ;
if ( V_8 != V_110 &&
F_68 ( V_12 , & V_82 -> V_12 ) &&
F_47 ( V_8 ) == V_13 ) {
F_42 ( V_5 , V_86 ) ;
F_96 () ;
return 1 ;
}
F_42 ( V_5 , V_87 ) ;
}
F_96 () ;
return 0 ;
}
static T_6 int F_97 ( struct V_5 * V_5 , unsigned int V_111 )
{
struct V_81 * V_82 ;
struct V_47 * V_8 = NULL , * V_112 ;
struct V_83 * V_14 ;
unsigned int V_10 = 0 , V_113 = 0 ;
int V_114 = 0 ;
unsigned int V_24 , V_6 ;
T_7 * V_115 ;
F_41 () ;
V_116:
V_6 = F_49 ( & V_5 -> V_8 . V_9 ) ;
V_24 = F_12 ( V_111 , V_5 ) ;
for (; V_10 < V_5 -> V_8 . V_27 ; V_10 ++ ) {
V_115 = & V_4 [ V_24 % V_3 ] ;
F_4 ( V_115 ) ;
if ( F_6 ( & V_5 -> V_8 . V_9 , V_6 ) ) {
F_2 ( V_115 ) ;
goto V_116;
}
F_71 (h, n, &net->ct.hash[hash],
hnnode) {
V_112 = F_67 ( V_82 ) ;
if ( ! F_98 ( V_117 , & V_112 -> V_75 ) &&
! F_62 ( V_112 ) &&
F_74 ( & V_112 -> V_89 . V_60 ) ) {
V_8 = V_112 ;
break;
}
V_113 ++ ;
}
V_24 = ( V_24 + 1 ) % V_5 -> V_8 . V_27 ;
F_2 ( V_115 ) ;
if ( V_8 || V_113 >= V_118 )
break;
}
F_43 () ;
if ( ! V_8 )
return V_114 ;
if ( F_99 ( & V_8 -> V_61 ) ) {
if ( F_58 ( V_8 , 0 , 0 ) ) {
V_114 = 1 ;
F_100 ( V_5 , F_97 ) ;
}
}
F_44 ( V_8 ) ;
return V_114 ;
}
void F_101 ( void )
{
unsigned int rand ;
do {
F_102 ( & rand , sizeof( rand ) ) ;
} while ( ! rand );
F_103 ( & V_18 , 0 , rand ) ;
}
static struct V_47 *
F_104 ( struct V_5 * V_5 , T_2 V_13 ,
const struct V_11 * V_45 ,
const struct V_11 * V_119 ,
T_8 V_120 , T_1 V_24 )
{
struct V_47 * V_8 ;
if ( F_63 ( ! V_18 ) ) {
F_101 () ;
V_24 = F_9 ( V_45 , V_13 ) ;
}
F_89 ( & V_5 -> V_8 . V_121 ) ;
if ( V_122 &&
F_63 ( F_37 ( & V_5 -> V_8 . V_121 ) > V_122 ) ) {
if ( ! F_97 ( V_5 , V_24 ) ) {
F_105 ( & V_5 -> V_8 . V_121 ) ;
F_106 ( L_5 ) ;
return F_107 ( - V_123 ) ;
}
}
V_8 = F_108 ( V_5 -> V_8 . V_124 , V_120 ) ;
if ( V_8 == NULL ) {
F_105 ( & V_5 -> V_8 . V_121 ) ;
return F_107 ( - V_123 ) ;
}
memset ( & V_8 -> V_48 [ V_125 ] , 0 ,
F_109 ( struct V_47 , V_126 ) -
F_109 ( struct V_47 , V_48 [ V_125 ] ) ) ;
F_110 ( & V_8 -> V_55 ) ;
V_8 -> V_48 [ V_39 ] . V_12 = * V_45 ;
V_8 -> V_48 [ V_39 ] . V_49 . V_101 = NULL ;
V_8 -> V_48 [ V_50 ] . V_12 = * V_119 ;
* ( unsigned long * ) ( & V_8 -> V_48 [ V_50 ] . V_49 . V_101 ) = V_24 ;
F_57 ( & V_8 -> V_61 , F_65 , ( unsigned long ) V_8 ) ;
F_111 ( & V_8 -> V_127 , V_5 ) ;
#ifdef F_112
if ( V_13 ) {
struct V_128 * F_47 ;
F_47 = F_113 ( V_8 , V_129 , V_130 ) ;
if ( ! F_47 )
goto V_131;
F_47 -> V_132 = V_13 ;
}
#endif
F_81 ( & V_8 -> V_89 . V_60 , 0 ) ;
return V_8 ;
#ifdef F_112
V_131:
F_105 ( & V_5 -> V_8 . V_121 ) ;
F_114 ( V_5 -> V_8 . V_124 , V_8 ) ;
return F_107 ( - V_123 ) ;
#endif
}
struct V_47 * F_115 ( struct V_5 * V_5 , T_2 V_13 ,
const struct V_11 * V_45 ,
const struct V_11 * V_119 ,
T_8 V_120 )
{
return F_104 ( V_5 , V_13 , V_45 , V_119 , V_120 , 0 ) ;
}
void F_45 ( struct V_47 * V_8 )
{
struct V_5 * V_5 = F_29 ( V_8 ) ;
F_36 ( F_37 ( & V_8 -> V_89 . V_60 ) == 0 ) ;
F_116 ( V_8 ) ;
F_117 ( V_8 ) ;
F_114 ( V_5 -> V_8 . V_124 , V_8 ) ;
F_118 () ;
F_105 ( & V_5 -> V_8 . V_121 ) ;
}
static struct V_81 *
F_119 ( struct V_5 * V_5 , struct V_47 * V_94 ,
const struct V_11 * V_12 ,
struct V_33 * V_34 ,
struct V_35 * V_36 ,
struct V_28 * V_29 ,
unsigned int V_31 , T_1 V_24 )
{
struct V_47 * V_8 ;
struct V_97 * V_98 ;
struct V_11 V_133 ;
struct V_68 * V_69 ;
struct V_134 * exp = NULL ;
T_2 V_13 = V_94 ? F_47 ( V_94 ) : V_135 ;
struct V_136 * V_137 ;
unsigned int * V_138 ;
if ( ! F_21 ( & V_133 , V_12 , V_34 , V_36 ) ) {
F_23 ( L_6 ) ;
return NULL ;
}
V_8 = F_104 ( V_5 , V_13 , V_12 , & V_133 , V_130 ,
V_24 ) ;
if ( F_120 ( V_8 ) )
return (struct V_81 * ) V_8 ;
if ( V_94 && F_121 ( V_94 ) ) {
F_122 ( V_8 ) ;
F_123 ( V_8 ) ;
}
V_137 = V_94 ? F_124 ( V_94 ) : NULL ;
if ( V_137 )
V_138 = F_125 ( V_137 ) ;
else
V_138 = V_36 -> V_139 ( V_5 ) ;
if ( ! V_36 -> V_140 ( V_8 , V_29 , V_31 , V_138 ) ) {
F_45 ( V_8 ) ;
F_23 ( L_7 ) ;
return NULL ;
}
if ( V_137 )
F_126 ( V_8 , V_137 -> V_61 , V_130 ) ;
F_127 ( V_8 , V_130 ) ;
F_128 ( V_8 , V_130 ) ;
F_129 ( V_8 ) ;
V_69 = V_94 ? F_51 ( V_94 ) : NULL ;
F_130 ( V_8 , V_69 ? V_69 -> V_141 : 0 ,
V_69 ? V_69 -> V_142 : 0 ,
V_130 ) ;
F_41 () ;
if ( V_5 -> V_8 . V_143 ) {
F_4 ( & V_144 ) ;
exp = F_131 ( V_5 , V_13 , V_12 ) ;
if ( exp ) {
F_23 ( L_8 ,
V_8 , exp ) ;
F_83 ( V_145 , & V_8 -> V_75 ) ;
V_8 -> V_64 = exp -> V_64 ;
if ( exp -> V_105 ) {
V_98 = F_132 ( V_8 , exp -> V_105 ,
V_130 ) ;
if ( V_98 )
F_133 ( V_98 -> V_105 , exp -> V_105 ) ;
}
#ifdef F_134
V_8 -> V_146 = exp -> V_64 -> V_146 ;
#endif
#ifdef F_135
V_8 -> V_147 = exp -> V_64 -> V_147 ;
#endif
F_42 ( V_5 , V_148 ) ;
}
F_2 ( & V_144 ) ;
}
if ( ! exp ) {
F_136 ( V_8 , V_94 , V_130 ) ;
F_42 ( V_5 , V_140 ) ;
}
F_84 ( & V_8 -> V_89 ) ;
F_31 ( V_8 ) ;
F_43 () ;
if ( exp ) {
if ( exp -> V_149 )
exp -> V_149 ( V_8 , exp ) ;
F_137 ( exp ) ;
}
return & V_8 -> V_48 [ V_39 ] ;
}
static inline struct V_47 *
F_138 ( struct V_5 * V_5 , struct V_47 * V_94 ,
struct V_28 * V_29 ,
unsigned int V_31 ,
T_4 V_32 ,
T_5 V_23 ,
struct V_33 * V_34 ,
struct V_35 * V_36 ,
int * V_150 ,
enum V_99 * V_100 )
{
struct V_11 V_12 ;
struct V_81 * V_82 ;
struct V_47 * V_8 ;
T_2 V_13 = V_94 ? F_47 ( V_94 ) : V_135 ;
T_1 V_24 ;
if ( ! F_15 ( V_29 , F_139 ( V_29 ) ,
V_31 , V_32 , V_23 , & V_12 , V_34 ,
V_36 ) ) {
F_23 ( L_9 ) ;
return NULL ;
}
V_24 = F_9 ( & V_12 , V_13 ) ;
V_82 = F_73 ( V_5 , V_13 , & V_12 , V_24 ) ;
if ( ! V_82 ) {
V_82 = F_119 ( V_5 , V_94 , & V_12 , V_34 , V_36 ,
V_29 , V_31 , V_24 ) ;
if ( ! V_82 )
return NULL ;
if ( F_120 ( V_82 ) )
return ( void * ) V_82 ;
}
V_8 = F_67 ( V_82 ) ;
if ( F_140 ( V_82 ) == V_50 ) {
* V_100 = V_151 ;
* V_150 = 1 ;
} else {
if ( F_98 ( V_152 , & V_8 -> V_75 ) ) {
F_23 ( L_10 , V_8 ) ;
* V_100 = V_153 ;
} else if ( F_98 ( V_145 , & V_8 -> V_75 ) ) {
F_23 ( L_11 ,
V_8 ) ;
* V_100 = V_154 ;
} else {
F_23 ( L_12 , V_8 ) ;
* V_100 = V_155 ;
}
* V_150 = 0 ;
}
V_29 -> V_59 = & V_8 -> V_89 ;
V_29 -> V_156 = * V_100 ;
return V_8 ;
}
unsigned int
F_141 ( struct V_5 * V_5 , T_5 V_157 , unsigned int V_158 ,
struct V_28 * V_29 )
{
struct V_47 * V_8 , * V_94 = NULL ;
enum V_99 V_100 ;
struct V_33 * V_34 ;
struct V_35 * V_36 ;
unsigned int * V_138 ;
unsigned int V_31 ;
T_5 V_23 ;
int V_150 = 0 ;
int V_41 ;
if ( V_29 -> V_59 ) {
V_94 = (struct V_47 * ) V_29 -> V_59 ;
if ( ! F_142 ( V_94 ) ) {
F_100 ( V_5 , V_159 ) ;
return V_43 ;
}
V_29 -> V_59 = NULL ;
}
V_34 = F_18 ( V_157 ) ;
V_41 = V_34 -> V_42 ( V_29 , F_139 ( V_29 ) ,
& V_31 , & V_23 ) ;
if ( V_41 <= 0 ) {
F_23 ( L_13 ) ;
F_100 ( V_5 , error ) ;
F_100 ( V_5 , V_160 ) ;
V_41 = - V_41 ;
goto V_90;
}
V_36 = F_20 ( V_157 , V_23 ) ;
if ( V_36 -> error != NULL ) {
V_41 = V_36 -> error ( V_5 , V_94 , V_29 , V_31 , & V_100 ,
V_157 , V_158 ) ;
if ( V_41 <= 0 ) {
F_100 ( V_5 , error ) ;
F_100 ( V_5 , V_160 ) ;
V_41 = - V_41 ;
goto V_90;
}
if ( V_29 -> V_59 )
goto V_90;
}
V_8 = F_138 ( V_5 , V_94 , V_29 , V_31 , V_157 , V_23 ,
V_34 , V_36 , & V_150 , & V_100 ) ;
if ( ! V_8 ) {
F_100 ( V_5 , V_160 ) ;
V_41 = V_43 ;
goto V_90;
}
if ( F_120 ( V_8 ) ) {
F_100 ( V_5 , V_161 ) ;
V_41 = V_109 ;
goto V_90;
}
F_36 ( V_29 -> V_59 ) ;
V_138 = F_143 ( V_5 , V_8 , V_36 ) ;
V_41 = V_36 -> V_162 ( V_8 , V_29 , V_31 , V_100 , V_157 , V_158 , V_138 ) ;
if ( V_41 <= 0 ) {
F_23 ( L_14 ) ;
F_144 ( V_29 -> V_59 ) ;
V_29 -> V_59 = NULL ;
F_100 ( V_5 , V_160 ) ;
if ( V_41 == - V_109 )
F_100 ( V_5 , V_161 ) ;
V_41 = - V_41 ;
goto V_90;
}
if ( V_150 && ! F_145 ( V_152 , & V_8 -> V_75 ) )
F_92 ( V_163 , V_8 ) ;
V_90:
if ( V_94 ) {
if ( V_41 == V_164 )
V_29 -> V_59 = (struct V_58 * ) V_94 ;
else
F_44 ( V_94 ) ;
}
return V_41 ;
}
bool F_146 ( struct V_11 * V_44 ,
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
void F_147 ( struct V_47 * V_8 ,
const struct V_11 * V_165 )
{
struct V_97 * V_98 = F_91 ( V_8 ) ;
F_36 ( ! F_69 ( V_8 ) ) ;
F_23 ( L_15 , V_8 ) ;
F_148 ( V_165 ) ;
V_8 -> V_48 [ V_50 ] . V_12 = * V_165 ;
if ( V_8 -> V_64 || ( V_98 && ! F_149 ( & V_98 -> V_166 ) ) )
return;
F_17 () ;
F_136 ( V_8 , NULL , V_130 ) ;
F_19 () ;
}
void F_150 ( struct V_47 * V_8 ,
enum V_99 V_100 ,
const struct V_28 * V_29 ,
unsigned long V_167 ,
int V_168 )
{
F_36 ( V_8 -> V_61 . V_169 == ( unsigned long ) V_8 ) ;
F_36 ( V_29 ) ;
if ( F_98 ( V_170 , & V_8 -> V_75 ) )
goto V_171;
if ( ! F_69 ( V_8 ) ) {
V_8 -> V_61 . V_71 = V_167 ;
} else {
unsigned long V_172 = V_72 + V_167 ;
if ( V_172 - V_8 -> V_61 . V_71 >= V_173 )
F_151 ( & V_8 -> V_61 , V_172 ) ;
}
V_171:
if ( V_168 ) {
struct V_174 * V_171 ;
V_171 = F_152 ( V_8 ) ;
if ( V_171 ) {
struct V_175 * V_176 = V_171 -> V_176 ;
F_153 ( & V_176 [ F_88 ( V_100 ) ] . V_177 ) ;
F_154 ( V_29 -> V_178 , & V_176 [ F_88 ( V_100 ) ] . V_179 ) ;
}
}
}
bool F_155 ( struct V_47 * V_8 ,
enum V_99 V_100 ,
const struct V_28 * V_29 ,
int V_168 )
{
if ( V_168 ) {
struct V_174 * V_171 ;
V_171 = F_152 ( V_8 ) ;
if ( V_171 ) {
struct V_175 * V_176 = V_171 -> V_176 ;
F_153 ( & V_176 [ F_88 ( V_100 ) ] . V_177 ) ;
F_154 ( V_29 -> V_178 - F_139 ( V_29 ) ,
& V_176 [ F_88 ( V_100 ) ] . V_179 ) ;
}
}
if ( F_99 ( & V_8 -> V_61 ) ) {
V_8 -> V_61 . V_180 ( ( unsigned long ) V_8 ) ;
return true ;
}
return false ;
}
int F_156 ( struct V_28 * V_29 ,
const struct V_11 * V_12 )
{
if ( F_157 ( V_29 , V_181 , V_12 -> V_15 . V_21 . V_182 . V_183 ) ||
F_157 ( V_29 , V_184 , V_12 -> V_16 . V_21 . V_182 . V_183 ) )
goto V_185;
return 0 ;
V_185:
return - 1 ;
}
int F_158 ( struct V_186 * V_187 [] ,
struct V_11 * V_188 )
{
if ( ! V_187 [ V_181 ] || ! V_187 [ V_184 ] )
return - V_189 ;
V_188 -> V_15 . V_21 . V_182 . V_183 = F_159 ( V_187 [ V_181 ] ) ;
V_188 -> V_16 . V_21 . V_182 . V_183 = F_159 ( V_187 [ V_184 ] ) ;
return 0 ;
}
int F_160 ( void )
{
return F_161 ( V_190 , V_191 + 1 ) ;
}
static void F_162 ( struct V_28 * V_192 , const struct V_28 * V_29 )
{
struct V_47 * V_8 ;
enum V_99 V_100 ;
V_8 = F_87 ( V_29 , & V_100 ) ;
if ( F_88 ( V_100 ) == V_39 )
V_100 = V_193 ;
else
V_100 = V_154 ;
V_192 -> V_59 = & V_8 -> V_89 ;
V_192 -> V_156 = V_100 ;
F_84 ( V_192 -> V_59 ) ;
}
static struct V_47 *
F_163 ( struct V_5 * V_5 , int (* F_164)( struct V_47 * V_10 , void * V_169 ) ,
void * V_169 , unsigned int * V_84 )
{
struct V_81 * V_82 ;
struct V_47 * V_8 ;
struct V_83 * V_14 ;
int V_53 ;
T_7 * V_115 ;
for (; * V_84 < V_5 -> V_8 . V_27 ; ( * V_84 ) ++ ) {
V_115 = & V_4 [ * V_84 % V_3 ] ;
F_41 () ;
F_4 ( V_115 ) ;
if ( * V_84 < V_5 -> V_8 . V_27 ) {
F_79 (h, n, &net->ct.hash[*bucket], hnnode) {
if ( F_140 ( V_82 ) != V_39 )
continue;
V_8 = F_67 ( V_82 ) ;
if ( F_164 ( V_8 , V_169 ) )
goto V_86;
}
}
F_2 ( V_115 ) ;
F_43 () ;
}
F_165 (cpu) {
struct V_51 * V_52 = F_28 ( V_5 -> V_8 . V_54 , V_53 ) ;
F_166 ( & V_52 -> V_55 ) ;
F_79 (h, n, &pcpu->unconfirmed, hnnode) {
V_8 = F_67 ( V_82 ) ;
if ( F_164 ( V_8 , V_169 ) )
F_55 ( V_74 , & V_8 -> V_75 ) ;
}
F_85 ( & V_52 -> V_55 ) ;
}
return NULL ;
V_86:
F_89 ( & V_8 -> V_89 . V_60 ) ;
F_2 ( V_115 ) ;
F_43 () ;
return V_8 ;
}
void F_167 ( struct V_5 * V_5 ,
int (* F_164)( struct V_47 * V_10 , void * V_169 ) ,
void * V_169 , T_1 V_76 , int V_77 )
{
struct V_47 * V_8 ;
unsigned int V_84 = 0 ;
while ( ( V_8 = F_163 ( V_5 , F_164 , V_169 , & V_84 ) ) != NULL ) {
if ( F_99 ( & V_8 -> V_61 ) )
F_58 ( V_8 , V_76 , V_77 ) ;
F_44 ( V_8 ) ;
}
}
static int F_168 ( struct V_47 * V_10 , void * V_169 )
{
return 1 ;
}
void F_169 ( void * V_24 , unsigned int V_25 )
{
if ( F_170 ( V_24 ) )
F_171 ( V_24 ) ;
else
F_172 ( ( unsigned long ) V_24 ,
F_173 ( sizeof( struct V_194 ) * V_25 ) ) ;
}
void F_174 ( struct V_5 * V_5 , T_1 V_76 , int V_77 )
{
F_167 ( V_5 , F_168 , NULL , V_76 , V_77 ) ;
}
static void F_175 ( struct V_5 * V_5 )
{
struct V_81 * V_82 ;
struct V_47 * V_8 ;
struct V_83 * V_14 ;
int V_53 ;
F_165 (cpu) {
struct V_51 * V_52 = F_28 ( V_5 -> V_8 . V_54 , V_53 ) ;
F_166 ( & V_52 -> V_55 ) ;
F_79 (h, n, &pcpu->dying, hnnode) {
V_8 = F_67 ( V_82 ) ;
F_176 ( V_8 ) ;
}
F_85 ( & V_52 -> V_55 ) ;
}
}
static int F_177 ( void )
{
int V_113 = 0 , V_53 ;
F_165 (cpu) {
struct V_47 * V_8 = & F_178 ( V_195 , V_53 ) ;
V_113 += F_37 ( & V_8 -> V_89 . V_60 ) - 1 ;
}
return V_113 ;
}
void F_179 ( void )
{
F_180 ( V_196 , NULL ) ;
}
void F_181 ( void )
{
F_180 ( V_197 , NULL ) ;
while ( F_177 () > 0 )
F_182 () ;
#ifdef F_112
F_183 ( & V_198 ) ;
#endif
F_184 () ;
F_185 () ;
F_186 () ;
F_187 () ;
F_188 () ;
F_189 () ;
F_190 () ;
F_191 () ;
F_192 () ;
}
void F_193 ( struct V_5 * V_5 )
{
F_194 ( V_199 ) ;
F_195 ( & V_5 -> V_200 , & V_199 ) ;
F_196 ( & V_199 ) ;
}
void F_196 ( struct V_201 * V_202 )
{
int V_203 ;
struct V_5 * V_5 ;
F_197 () ;
V_204:
V_203 = 0 ;
F_198 (net, net_exit_list, exit_list) {
F_167 ( V_5 , F_168 , NULL , 0 , 0 ) ;
F_175 ( V_5 ) ;
if ( F_37 ( & V_5 -> V_8 . V_121 ) != 0 )
V_203 = 1 ;
}
if ( V_203 ) {
F_182 () ;
goto V_204;
}
F_198 (net, net_exit_list, exit_list) {
F_169 ( V_5 -> V_8 . V_24 , V_5 -> V_8 . V_27 ) ;
F_199 ( V_5 ) ;
F_200 ( V_5 ) ;
F_201 ( V_5 ) ;
F_202 ( V_5 ) ;
F_203 ( V_5 ) ;
F_204 ( V_5 ) ;
F_205 ( V_5 -> V_8 . V_124 ) ;
F_206 ( V_5 -> V_8 . V_205 ) ;
F_207 ( V_5 -> V_8 . V_206 ) ;
F_207 ( V_5 -> V_8 . V_54 ) ;
}
}
void * F_208 ( unsigned int * V_207 , int V_208 )
{
struct V_209 * V_24 ;
unsigned int V_210 , V_10 ;
T_9 V_211 ;
F_209 ( sizeof( struct V_209 ) != sizeof( struct V_194 ) ) ;
V_210 = * V_207 = F_210 ( * V_207 , V_212 / sizeof( struct V_209 ) ) ;
V_211 = V_210 * sizeof( struct V_209 ) ;
V_24 = ( void * ) F_211 ( V_213 | V_214 | V_215 ,
F_173 ( V_211 ) ) ;
if ( ! V_24 ) {
F_212 ( V_216 L_16 ) ;
V_24 = F_213 ( V_211 ) ;
}
if ( V_24 && V_208 )
for ( V_10 = 0 ; V_10 < V_210 ; V_10 ++ )
F_214 ( & V_24 [ V_10 ] , V_10 ) ;
return V_24 ;
}
int F_215 ( const char * V_217 , struct V_218 * V_219 )
{
int V_10 , V_84 , V_220 ;
unsigned int V_221 , V_222 ;
struct V_209 * V_24 , * V_223 ;
struct V_81 * V_82 ;
struct V_47 * V_8 ;
if ( V_224 -> V_225 -> V_226 != & V_227 )
return - V_228 ;
if ( ! V_229 )
return F_216 ( V_217 , V_219 ) ;
V_220 = F_217 ( V_217 , 0 , & V_221 ) ;
if ( V_220 )
return V_220 ;
if ( ! V_221 )
return - V_189 ;
V_24 = F_208 ( & V_221 , 1 ) ;
if ( ! V_24 )
return - V_123 ;
F_41 () ;
F_7 () ;
F_218 ( & V_227 . V_8 . V_9 ) ;
for ( V_10 = 0 ; V_10 < V_227 . V_8 . V_27 ; V_10 ++ ) {
while ( ! F_219 ( & V_227 . V_8 . V_24 [ V_10 ] ) ) {
V_82 = F_220 ( V_227 . V_8 . V_24 [ V_10 ] . V_230 ,
struct V_81 , V_49 ) ;
V_8 = F_67 ( V_82 ) ;
F_24 ( & V_82 -> V_49 ) ;
V_84 = F_13 ( & V_82 -> V_12 , F_47 ( V_8 ) ,
V_221 ) ;
F_77 ( & V_82 -> V_49 , & V_24 [ V_84 ] ) ;
}
}
V_222 = V_227 . V_8 . V_27 ;
V_223 = V_227 . V_8 . V_24 ;
V_227 . V_8 . V_27 = V_229 = V_221 ;
V_227 . V_8 . V_24 = V_24 ;
F_221 ( & V_227 . V_8 . V_9 ) ;
F_8 () ;
F_43 () ;
F_169 ( V_223 , V_222 ) ;
return 0 ;
}
void F_222 ( unsigned long V_231 )
{
int V_53 ;
F_165 (cpu)
F_178 ( V_195 , V_53 ) . V_75 |= V_231 ;
}
int F_223 ( void )
{
int V_232 = 8 ;
int V_10 , V_41 , V_53 ;
for ( V_10 = 0 ; V_10 < V_3 ; V_10 ++ )
F_110 ( & V_4 [ V_10 ] ) ;
if ( ! V_229 ) {
V_229
= ( ( ( V_233 << V_234 ) / 16384 )
/ sizeof( struct V_194 ) ) ;
if ( V_233 > ( 1024 * 1024 * 1024 / V_212 ) )
V_229 = 16384 ;
if ( V_229 < 32 )
V_229 = 32 ;
V_232 = 4 ;
}
V_122 = V_232 * V_229 ;
F_212 ( V_235 L_17 ,
V_236 , V_229 ,
V_122 ) ;
V_41 = F_224 () ;
if ( V_41 < 0 )
goto V_237;
V_41 = F_225 () ;
if ( V_41 < 0 )
goto V_238;
V_41 = F_226 () ;
if ( V_41 < 0 )
goto V_239;
V_41 = F_227 () ;
if ( V_41 < 0 )
goto V_240;
V_41 = F_228 () ;
if ( V_41 < 0 )
goto V_241;
V_41 = F_229 () ;
if ( V_41 < 0 )
goto V_242;
V_41 = F_230 () ;
if ( V_41 < 0 )
goto V_243;
V_41 = F_231 () ;
if ( V_41 < 0 )
goto V_244;
#ifdef F_112
V_41 = F_232 ( & V_198 ) ;
if ( V_41 < 0 )
goto V_245;
#endif
V_41 = F_233 () ;
if ( V_41 < 0 )
goto V_246;
F_165 (cpu) {
struct V_47 * V_8 = & F_178 ( V_195 , V_53 ) ;
F_111 ( & V_8 -> V_127 , & V_227 ) ;
F_81 ( & V_8 -> V_89 . V_60 , 1 ) ;
}
F_222 ( V_102 | V_247 ) ;
return 0 ;
V_246:
#ifdef F_112
F_183 ( & V_198 ) ;
V_245:
#endif
F_185 () ;
V_244:
F_186 () ;
V_243:
F_187 () ;
V_242:
F_188 () ;
V_241:
F_189 () ;
V_240:
F_190 () ;
V_239:
F_191 () ;
V_238:
F_192 () ;
V_237:
return V_41 ;
}
void F_234 ( void )
{
F_180 ( V_196 , F_162 ) ;
F_180 ( V_197 , F_35 ) ;
}
int F_235 ( struct V_5 * V_5 )
{
int V_41 = - V_123 ;
int V_53 ;
F_81 ( & V_5 -> V_8 . V_121 , 0 ) ;
F_236 ( & V_5 -> V_8 . V_9 ) ;
V_5 -> V_8 . V_54 = F_237 ( struct V_51 ) ;
if ( ! V_5 -> V_8 . V_54 )
goto V_248;
F_165 (cpu) {
struct V_51 * V_52 = F_28 ( V_5 -> V_8 . V_54 , V_53 ) ;
F_110 ( & V_52 -> V_55 ) ;
F_214 ( & V_52 -> V_57 , V_249 ) ;
F_214 ( & V_52 -> V_56 , V_250 ) ;
F_214 ( & V_52 -> V_94 , V_251 ) ;
}
V_5 -> V_8 . V_206 = F_237 ( struct V_252 ) ;
if ( ! V_5 -> V_8 . V_206 )
goto V_253;
V_5 -> V_8 . V_205 = F_238 ( V_213 , L_18 , V_5 ) ;
if ( ! V_5 -> V_8 . V_205 )
goto V_254;
V_5 -> V_8 . V_124 = F_239 ( V_5 -> V_8 . V_205 ,
sizeof( struct V_47 ) , 0 ,
V_255 , NULL ) ;
if ( ! V_5 -> V_8 . V_124 ) {
F_212 ( V_256 L_19 ) ;
goto V_257;
}
V_5 -> V_8 . V_27 = V_229 ;
V_5 -> V_8 . V_24 = F_208 ( & V_5 -> V_8 . V_27 , 1 ) ;
if ( ! V_5 -> V_8 . V_24 ) {
F_212 ( V_256 L_20 ) ;
goto V_258;
}
V_41 = F_240 ( V_5 ) ;
if ( V_41 < 0 )
goto V_237;
V_41 = F_241 ( V_5 ) ;
if ( V_41 < 0 )
goto V_238;
V_41 = F_242 ( V_5 ) ;
if ( V_41 < 0 )
goto V_239;
V_41 = F_243 ( V_5 ) ;
if ( V_41 < 0 )
goto V_240;
V_41 = F_244 ( V_5 ) ;
if ( V_41 < 0 )
goto V_242;
V_41 = F_245 ( V_5 ) ;
if ( V_41 < 0 )
goto V_246;
return 0 ;
V_246:
F_200 ( V_5 ) ;
V_242:
F_201 ( V_5 ) ;
V_240:
F_202 ( V_5 ) ;
V_239:
F_203 ( V_5 ) ;
V_238:
F_204 ( V_5 ) ;
V_237:
F_169 ( V_5 -> V_8 . V_24 , V_5 -> V_8 . V_27 ) ;
V_258:
F_205 ( V_5 -> V_8 . V_124 ) ;
V_257:
F_206 ( V_5 -> V_8 . V_205 ) ;
V_254:
F_207 ( V_5 -> V_8 . V_206 ) ;
V_253:
F_207 ( V_5 -> V_8 . V_54 ) ;
V_248:
return V_41 ;
}
