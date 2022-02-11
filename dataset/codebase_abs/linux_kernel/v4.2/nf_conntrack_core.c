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
struct V_46 * F_36 ( struct V_5 * V_5 , T_2 V_13 , T_6 V_57 )
{
struct V_46 * V_58 ;
V_58 = F_37 ( sizeof( * V_58 ) , V_57 ) ;
if ( V_58 == NULL )
return NULL ;
V_58 -> V_59 = V_60 ;
F_38 ( & V_58 -> V_61 , V_5 ) ;
#ifdef F_39
if ( V_13 ) {
struct V_62 * V_63 ;
V_63 = F_40 ( V_58 , V_64 , V_57 ) ;
if ( ! V_63 )
goto V_65;
V_63 -> V_66 = V_13 ;
}
#endif
F_41 ( & V_58 -> V_67 . V_68 , 0 ) ;
return V_58 ;
#ifdef F_39
V_65:
F_42 ( V_58 ) ;
return NULL ;
#endif
}
static void F_43 ( struct V_46 * V_58 )
{
F_44 ( V_58 ) ;
F_45 ( V_58 ) ;
F_42 ( V_58 ) ;
}
static void
F_46 ( struct V_69 * V_70 )
{
struct V_46 * V_8 = (struct V_46 * ) V_70 ;
struct V_5 * V_5 = F_30 ( V_8 ) ;
struct V_34 * V_35 ;
F_24 ( L_2 , V_8 ) ;
F_47 ( F_48 ( & V_70 -> V_68 ) == 0 ) ;
F_47 ( ! F_49 ( & V_8 -> V_71 ) ) ;
if ( F_50 ( F_51 ( V_8 ) ) ) {
F_43 ( V_8 ) ;
return;
}
F_18 () ;
V_35 = F_21 ( F_52 ( V_8 ) , F_53 ( V_8 ) ) ;
if ( V_35 && V_35 -> V_72 )
V_35 -> V_72 ( V_8 ) ;
F_20 () ;
F_54 () ;
F_26 ( V_8 ) ;
F_33 ( V_8 ) ;
F_55 ( V_5 , V_73 ) ;
F_56 () ;
if ( V_8 -> V_74 )
F_57 ( V_8 -> V_74 ) ;
F_24 ( L_3 , V_8 ) ;
F_58 ( V_8 ) ;
}
static void F_59 ( struct V_46 * V_8 )
{
struct V_5 * V_5 = F_30 ( V_8 ) ;
unsigned int V_24 , V_75 ;
T_2 V_13 = V_63 ( V_8 ) ;
unsigned int V_6 ;
F_60 ( V_8 ) ;
F_54 () ;
do {
V_6 = F_61 ( & V_5 -> V_8 . V_9 ) ;
V_24 = F_15 ( V_5 , V_13 ,
& V_8 -> V_47 [ V_38 ] . V_12 ) ;
V_75 = F_15 ( V_5 , V_13 ,
& V_8 -> V_47 [ V_49 ] . V_12 ) ;
} while ( F_3 ( V_5 , V_24 , V_75 , V_6 ) );
F_23 ( V_8 ) ;
F_1 ( V_24 , V_75 ) ;
F_27 ( V_8 ) ;
F_55 ( V_5 , V_76 ) ;
F_56 () ;
}
bool F_62 ( struct V_46 * V_8 , T_1 V_77 , int V_78 )
{
struct V_79 * V_80 ;
V_80 = F_63 ( V_8 ) ;
if ( V_80 && V_80 -> V_81 == 0 )
V_80 -> V_81 = F_64 () ;
if ( F_65 ( V_8 ) )
goto V_73;
if ( F_66 ( V_82 , V_8 ,
V_77 , V_78 ) < 0 ) {
F_59 ( V_8 ) ;
F_67 ( F_30 ( V_8 ) ) ;
return false ;
}
F_68 ( F_30 ( V_8 ) ) ;
F_69 ( V_83 , & V_8 -> V_59 ) ;
V_73:
F_59 ( V_8 ) ;
F_57 ( V_8 ) ;
return true ;
}
static void F_70 ( unsigned long V_84 )
{
F_62 ( (struct V_46 * ) V_84 , 0 , 0 ) ;
}
static inline bool
F_71 ( struct V_85 * V_86 ,
const struct V_11 * V_12 ,
T_2 V_13 )
{
struct V_46 * V_8 = F_72 ( V_86 ) ;
return F_73 ( V_12 , & V_86 -> V_12 ) &&
V_63 ( V_8 ) == V_13 &&
F_74 ( V_8 ) ;
}
static struct V_85 *
F_75 ( struct V_5 * V_5 , T_2 V_13 ,
const struct V_11 * V_12 , T_1 V_24 )
{
struct V_85 * V_86 ;
struct V_87 * V_14 ;
unsigned int V_88 = F_13 ( V_24 , V_5 ) ;
F_54 () ;
V_89:
F_76 (h, n, &net->ct.hash[bucket], hnnode) {
if ( F_71 ( V_86 , V_12 , V_13 ) ) {
F_55 ( V_5 , V_90 ) ;
F_56 () ;
return V_86 ;
}
F_55 ( V_5 , V_91 ) ;
}
if ( F_77 ( V_14 ) != V_88 ) {
F_55 ( V_5 , V_92 ) ;
goto V_89;
}
F_56 () ;
return NULL ;
}
static struct V_85 *
F_78 ( struct V_5 * V_5 , T_2 V_13 ,
const struct V_11 * V_12 , T_1 V_24 )
{
struct V_85 * V_86 ;
struct V_46 * V_8 ;
F_18 () ;
V_89:
V_86 = F_75 ( V_5 , V_13 , V_12 , V_24 ) ;
if ( V_86 ) {
V_8 = F_72 ( V_86 ) ;
if ( F_50 ( F_65 ( V_8 ) ||
! F_79 ( & V_8 -> V_67 . V_68 ) ) )
V_86 = NULL ;
else {
if ( F_50 ( ! F_71 ( V_86 , V_12 , V_13 ) ) ) {
F_57 ( V_8 ) ;
goto V_89;
}
}
}
F_20 () ;
return V_86 ;
}
struct V_85 *
F_80 ( struct V_5 * V_5 , T_2 V_13 ,
const struct V_11 * V_12 )
{
return F_78 ( V_5 , V_13 , V_12 ,
F_9 ( V_12 , V_13 ) ) ;
}
static void F_81 ( struct V_46 * V_8 ,
unsigned int V_24 ,
unsigned int V_75 )
{
struct V_5 * V_5 = F_30 ( V_8 ) ;
F_82 ( & V_8 -> V_47 [ V_38 ] . V_48 ,
& V_5 -> V_8 . V_24 [ V_24 ] ) ;
F_82 ( & V_8 -> V_47 [ V_49 ] . V_48 ,
& V_5 -> V_8 . V_24 [ V_75 ] ) ;
}
int
F_83 ( struct V_46 * V_8 )
{
struct V_5 * V_5 = F_30 ( V_8 ) ;
unsigned int V_24 , V_75 ;
struct V_85 * V_86 ;
struct V_87 * V_14 ;
T_2 V_13 ;
unsigned int V_6 ;
V_13 = V_63 ( V_8 ) ;
F_54 () ;
do {
V_6 = F_61 ( & V_5 -> V_8 . V_9 ) ;
V_24 = F_15 ( V_5 , V_13 ,
& V_8 -> V_47 [ V_38 ] . V_12 ) ;
V_75 = F_15 ( V_5 , V_13 ,
& V_8 -> V_47 [ V_49 ] . V_12 ) ;
} while ( F_3 ( V_5 , V_24 , V_75 , V_6 ) );
F_84 (h, n, &net->ct.hash[hash], hnnode)
if ( F_73 ( & V_8 -> V_47 [ V_38 ] . V_12 ,
& V_86 -> V_12 ) &&
V_13 == V_63 ( F_72 ( V_86 ) ) )
goto V_93;
F_84 (h, n, &net->ct.hash[reply_hash], hnnode)
if ( F_73 ( & V_8 -> V_47 [ V_49 ] . V_12 ,
& V_86 -> V_12 ) &&
V_13 == V_63 ( F_72 ( V_86 ) ) )
goto V_93;
F_85 ( & V_8 -> V_71 ) ;
F_86 () ;
F_41 ( & V_8 -> V_67 . V_68 , 2 ) ;
F_81 ( V_8 , V_24 , V_75 ) ;
F_1 ( V_24 , V_75 ) ;
F_55 ( V_5 , V_94 ) ;
F_56 () ;
return 0 ;
V_93:
F_1 ( V_24 , V_75 ) ;
F_55 ( V_5 , V_95 ) ;
F_56 () ;
return - V_96 ;
}
int
F_87 ( struct V_27 * V_28 )
{
unsigned int V_24 , V_75 ;
struct V_85 * V_86 ;
struct V_46 * V_8 ;
struct V_97 * V_98 ;
struct V_79 * V_80 ;
struct V_87 * V_14 ;
enum V_99 V_100 ;
struct V_5 * V_5 ;
T_2 V_13 ;
unsigned int V_6 ;
V_8 = F_88 ( V_28 , & V_100 ) ;
V_5 = F_30 ( V_8 ) ;
if ( F_89 ( V_100 ) != V_38 )
return V_42 ;
V_13 = V_63 ( V_8 ) ;
F_54 () ;
do {
V_6 = F_61 ( & V_5 -> V_8 . V_9 ) ;
V_24 = * ( unsigned long * ) & V_8 -> V_47 [ V_49 ] . V_48 . V_101 ;
V_24 = F_13 ( V_24 , V_5 ) ;
V_75 = F_15 ( V_5 , V_13 ,
& V_8 -> V_47 [ V_49 ] . V_12 ) ;
} while ( F_3 ( V_5 , V_24 , V_75 , V_6 ) );
F_47 ( ! F_74 ( V_8 ) ) ;
F_24 ( L_4 , V_8 ) ;
F_33 ( V_8 ) ;
if ( F_50 ( F_65 ( V_8 ) ) )
goto V_93;
F_84 (h, n, &net->ct.hash[hash], hnnode)
if ( F_73 ( & V_8 -> V_47 [ V_38 ] . V_12 ,
& V_86 -> V_12 ) &&
V_13 == V_63 ( F_72 ( V_86 ) ) )
goto V_93;
F_84 (h, n, &net->ct.hash[reply_hash], hnnode)
if ( F_73 ( & V_8 -> V_47 [ V_49 ] . V_12 ,
& V_86 -> V_12 ) &&
V_13 == V_63 ( F_72 ( V_86 ) ) )
goto V_93;
V_8 -> V_71 . V_102 += V_103 ;
F_85 ( & V_8 -> V_71 ) ;
F_90 ( & V_8 -> V_67 . V_68 ) ;
V_8 -> V_59 |= V_104 ;
V_80 = F_63 ( V_8 ) ;
if ( V_80 ) {
if ( V_28 -> V_80 . V_105 == 0 )
F_91 ( V_28 ) ;
V_80 -> V_106 = F_92 ( V_28 -> V_80 ) ;
}
F_81 ( V_8 , V_24 , V_75 ) ;
F_1 ( V_24 , V_75 ) ;
F_55 ( V_5 , V_94 ) ;
F_56 () ;
V_98 = F_93 ( V_8 ) ;
if ( V_98 && V_98 -> V_107 )
F_94 ( V_108 , V_8 ) ;
F_94 ( F_95 ( V_8 ) ?
V_109 : V_110 , V_8 ) ;
return V_42 ;
V_93:
F_27 ( V_8 ) ;
F_1 ( V_24 , V_75 ) ;
F_55 ( V_5 , V_95 ) ;
F_56 () ;
return V_111 ;
}
int
F_96 ( const struct V_11 * V_12 ,
const struct V_46 * V_112 )
{
struct V_5 * V_5 = F_30 ( V_112 ) ;
struct V_85 * V_86 ;
struct V_87 * V_14 ;
struct V_46 * V_8 ;
T_2 V_13 = V_63 ( V_112 ) ;
unsigned int V_24 = F_15 ( V_5 , V_13 , V_12 ) ;
F_97 () ;
F_76 (h, n, &net->ct.hash[hash], hnnode) {
V_8 = F_72 ( V_86 ) ;
if ( V_8 != V_112 &&
F_73 ( V_12 , & V_86 -> V_12 ) &&
V_63 ( V_8 ) == V_13 ) {
F_55 ( V_5 , V_90 ) ;
F_98 () ;
return 1 ;
}
F_55 ( V_5 , V_91 ) ;
}
F_98 () ;
return 0 ;
}
static T_7 int F_99 ( struct V_5 * V_5 , unsigned int V_113 )
{
struct V_85 * V_86 ;
struct V_46 * V_8 = NULL , * V_114 ;
struct V_87 * V_14 ;
unsigned int V_10 = 0 , V_115 = 0 ;
int V_116 = 0 ;
unsigned int V_24 , V_6 ;
T_8 * V_117 ;
F_54 () ;
V_118:
V_6 = F_61 ( & V_5 -> V_8 . V_9 ) ;
V_24 = F_13 ( V_113 , V_5 ) ;
for (; V_10 < V_5 -> V_8 . V_26 ; V_10 ++ ) {
V_117 = & V_4 [ V_24 % V_3 ] ;
F_4 ( V_117 ) ;
if ( F_6 ( & V_5 -> V_8 . V_9 , V_6 ) ) {
F_2 ( V_117 ) ;
goto V_118;
}
F_76 (h, n, &net->ct.hash[hash],
hnnode) {
V_114 = F_72 ( V_86 ) ;
if ( ! F_100 ( V_119 , & V_114 -> V_59 ) &&
! F_65 ( V_114 ) &&
F_79 ( & V_114 -> V_67 . V_68 ) ) {
V_8 = V_114 ;
break;
}
V_115 ++ ;
}
V_24 = ( V_24 + 1 ) % V_5 -> V_8 . V_26 ;
F_2 ( V_117 ) ;
if ( V_8 || V_115 >= V_120 )
break;
}
F_56 () ;
if ( ! V_8 )
return V_116 ;
if ( F_101 ( & V_8 -> V_71 ) ) {
if ( F_62 ( V_8 , 0 , 0 ) ) {
V_116 = 1 ;
F_102 ( V_5 , F_99 ) ;
}
}
F_57 ( V_8 ) ;
return V_116 ;
}
void F_103 ( void )
{
unsigned int rand ;
do {
F_104 ( & rand , sizeof( rand ) ) ;
} while ( ! rand );
F_105 ( & V_18 , 0 , rand ) ;
}
static struct V_46 *
F_106 ( struct V_5 * V_5 , T_2 V_13 ,
const struct V_11 * V_44 ,
const struct V_11 * V_121 ,
T_6 V_122 , T_1 V_24 )
{
struct V_46 * V_8 ;
if ( F_50 ( ! V_18 ) ) {
F_103 () ;
V_24 = F_9 ( V_44 , V_13 ) ;
}
F_90 ( & V_5 -> V_8 . V_123 ) ;
if ( V_124 &&
F_50 ( F_48 ( & V_5 -> V_8 . V_123 ) > V_124 ) ) {
if ( ! F_99 ( V_5 , V_24 ) ) {
F_107 ( & V_5 -> V_8 . V_123 ) ;
F_108 ( L_5 ) ;
return F_109 ( - V_125 ) ;
}
}
V_8 = F_110 ( V_5 -> V_8 . V_126 , V_122 ) ;
if ( V_8 == NULL ) {
F_107 ( & V_5 -> V_8 . V_123 ) ;
return F_109 ( - V_125 ) ;
}
F_111 ( & V_8 -> V_54 ) ;
V_8 -> V_47 [ V_38 ] . V_12 = * V_44 ;
V_8 -> V_47 [ V_38 ] . V_48 . V_101 = NULL ;
V_8 -> V_47 [ V_49 ] . V_12 = * V_121 ;
* ( unsigned long * ) ( & V_8 -> V_47 [ V_49 ] . V_48 . V_101 ) = V_24 ;
V_8 -> V_59 = 0 ;
F_112 ( & V_8 -> V_71 , F_70 , ( unsigned long ) V_8 ) ;
F_38 ( & V_8 -> V_61 , V_5 ) ;
memset ( & V_8 -> V_127 [ 0 ] , 0 ,
F_113 ( struct V_46 , V_128 ) -
F_113 ( struct V_46 , V_127 [ 0 ] ) ) ;
#ifdef F_39
if ( V_13 ) {
struct V_62 * V_63 ;
V_63 = F_40 ( V_8 , V_64 , V_129 ) ;
if ( ! V_63 )
goto V_65;
V_63 -> V_66 = V_13 ;
}
#endif
F_41 ( & V_8 -> V_67 . V_68 , 0 ) ;
return V_8 ;
#ifdef F_39
V_65:
F_107 ( & V_5 -> V_8 . V_123 ) ;
F_114 ( V_5 -> V_8 . V_126 , V_8 ) ;
return F_109 ( - V_125 ) ;
#endif
}
struct V_46 * F_115 ( struct V_5 * V_5 , T_2 V_13 ,
const struct V_11 * V_44 ,
const struct V_11 * V_121 ,
T_6 V_122 )
{
return F_106 ( V_5 , V_13 , V_44 , V_121 , V_122 , 0 ) ;
}
void F_58 ( struct V_46 * V_8 )
{
struct V_5 * V_5 = F_30 ( V_8 ) ;
F_47 ( F_48 ( & V_8 -> V_67 . V_68 ) == 0 ) ;
F_44 ( V_8 ) ;
F_45 ( V_8 ) ;
F_114 ( V_5 -> V_8 . V_126 , V_8 ) ;
F_116 () ;
F_107 ( & V_5 -> V_8 . V_123 ) ;
}
static struct V_85 *
F_117 ( struct V_5 * V_5 , struct V_46 * V_58 ,
const struct V_11 * V_12 ,
struct V_32 * V_33 ,
struct V_34 * V_35 ,
struct V_27 * V_28 ,
unsigned int V_30 , T_1 V_24 )
{
struct V_46 * V_8 ;
struct V_97 * V_98 ;
struct V_11 V_130 ;
struct V_131 * V_132 ;
struct V_133 * exp = NULL ;
T_2 V_13 = V_58 ? V_63 ( V_58 ) : V_134 ;
struct V_135 * V_136 ;
unsigned int * V_137 ;
if ( ! F_22 ( & V_130 , V_12 , V_33 , V_35 ) ) {
F_24 ( L_6 ) ;
return NULL ;
}
V_8 = F_106 ( V_5 , V_13 , V_12 , & V_130 , V_129 ,
V_24 ) ;
if ( F_118 ( V_8 ) )
return (struct V_85 * ) V_8 ;
if ( V_58 && F_119 ( V_58 ) ) {
F_120 ( V_8 ) ;
F_121 ( V_8 ) ;
}
V_136 = V_58 ? F_122 ( V_58 ) : NULL ;
if ( V_136 )
V_137 = F_123 ( V_136 ) ;
else
V_137 = V_35 -> V_138 ( V_5 ) ;
if ( ! V_35 -> V_139 ( V_8 , V_28 , V_30 , V_137 ) ) {
F_58 ( V_8 ) ;
F_24 ( L_7 ) ;
return NULL ;
}
if ( V_136 )
F_124 ( V_8 , V_136 -> V_71 , V_129 ) ;
F_125 ( V_8 , V_129 ) ;
F_126 ( V_8 , V_129 ) ;
F_127 ( V_8 ) ;
V_132 = V_58 ? F_128 ( V_58 ) : NULL ;
F_129 ( V_8 , V_132 ? V_132 -> V_140 : 0 ,
V_132 ? V_132 -> V_141 : 0 ,
V_129 ) ;
F_54 () ;
if ( V_5 -> V_8 . V_142 ) {
F_4 ( & V_143 ) ;
exp = F_130 ( V_5 , V_13 , V_12 ) ;
if ( exp ) {
F_24 ( L_8 ,
V_8 , exp ) ;
F_131 ( V_144 , & V_8 -> V_59 ) ;
V_8 -> V_74 = exp -> V_74 ;
if ( exp -> V_107 ) {
V_98 = F_132 ( V_8 , exp -> V_107 ,
V_129 ) ;
if ( V_98 )
F_133 ( V_98 -> V_107 , exp -> V_107 ) ;
}
#ifdef F_134
V_8 -> V_145 = exp -> V_74 -> V_145 ;
#endif
#ifdef F_135
V_8 -> V_146 = exp -> V_74 -> V_146 ;
#endif
F_55 ( V_5 , V_147 ) ;
}
F_2 ( & V_143 ) ;
}
if ( ! exp ) {
F_136 ( V_8 , V_58 , V_129 ) ;
F_55 ( V_5 , V_139 ) ;
}
F_137 ( & V_8 -> V_67 ) ;
F_32 ( V_8 ) ;
F_56 () ;
if ( exp ) {
if ( exp -> V_148 )
exp -> V_148 ( V_8 , exp ) ;
F_138 ( exp ) ;
}
return & V_8 -> V_47 [ V_38 ] ;
}
static inline struct V_46 *
F_139 ( struct V_5 * V_5 , struct V_46 * V_58 ,
struct V_27 * V_28 ,
unsigned int V_30 ,
T_4 V_31 ,
T_5 V_23 ,
struct V_32 * V_33 ,
struct V_34 * V_35 ,
int * V_149 ,
enum V_99 * V_100 )
{
struct V_11 V_12 ;
struct V_85 * V_86 ;
struct V_46 * V_8 ;
T_2 V_13 = V_58 ? V_63 ( V_58 ) : V_134 ;
T_1 V_24 ;
if ( ! F_16 ( V_28 , F_140 ( V_28 ) ,
V_30 , V_31 , V_23 , & V_12 , V_33 ,
V_35 ) ) {
F_24 ( L_9 ) ;
return NULL ;
}
V_24 = F_9 ( & V_12 , V_13 ) ;
V_86 = F_78 ( V_5 , V_13 , & V_12 , V_24 ) ;
if ( ! V_86 ) {
V_86 = F_117 ( V_5 , V_58 , & V_12 , V_33 , V_35 ,
V_28 , V_30 , V_24 ) ;
if ( ! V_86 )
return NULL ;
if ( F_118 ( V_86 ) )
return ( void * ) V_86 ;
}
V_8 = F_72 ( V_86 ) ;
if ( F_141 ( V_86 ) == V_49 ) {
* V_100 = V_150 ;
* V_149 = 1 ;
} else {
if ( F_100 ( V_151 , & V_8 -> V_59 ) ) {
F_24 ( L_10 , V_8 ) ;
* V_100 = V_152 ;
} else if ( F_100 ( V_144 , & V_8 -> V_59 ) ) {
F_24 ( L_11 ,
V_8 ) ;
* V_100 = V_153 ;
} else {
F_24 ( L_12 , V_8 ) ;
* V_100 = V_154 ;
}
* V_149 = 0 ;
}
V_28 -> V_70 = & V_8 -> V_67 ;
V_28 -> V_155 = * V_100 ;
return V_8 ;
}
unsigned int
F_142 ( struct V_5 * V_5 , T_5 V_156 , unsigned int V_157 ,
struct V_27 * V_28 )
{
struct V_46 * V_8 , * V_58 = NULL ;
enum V_99 V_100 ;
struct V_32 * V_33 ;
struct V_34 * V_35 ;
unsigned int * V_137 ;
unsigned int V_30 ;
T_5 V_23 ;
int V_149 = 0 ;
int V_40 ;
if ( V_28 -> V_70 ) {
V_58 = (struct V_46 * ) V_28 -> V_70 ;
if ( ! F_51 ( V_58 ) ) {
F_102 ( V_5 , V_158 ) ;
return V_42 ;
}
V_28 -> V_70 = NULL ;
}
V_33 = F_19 ( V_156 ) ;
V_40 = V_33 -> V_41 ( V_28 , F_140 ( V_28 ) ,
& V_30 , & V_23 ) ;
if ( V_40 <= 0 ) {
F_24 ( L_13 ) ;
F_102 ( V_5 , error ) ;
F_102 ( V_5 , V_159 ) ;
V_40 = - V_40 ;
goto V_93;
}
V_35 = F_21 ( V_156 , V_23 ) ;
if ( V_35 -> error != NULL ) {
V_40 = V_35 -> error ( V_5 , V_58 , V_28 , V_30 , & V_100 ,
V_156 , V_157 ) ;
if ( V_40 <= 0 ) {
F_102 ( V_5 , error ) ;
F_102 ( V_5 , V_159 ) ;
V_40 = - V_40 ;
goto V_93;
}
if ( V_28 -> V_70 )
goto V_93;
}
V_8 = F_139 ( V_5 , V_58 , V_28 , V_30 , V_156 , V_23 ,
V_33 , V_35 , & V_149 , & V_100 ) ;
if ( ! V_8 ) {
F_102 ( V_5 , V_159 ) ;
V_40 = V_42 ;
goto V_93;
}
if ( F_118 ( V_8 ) ) {
F_102 ( V_5 , V_160 ) ;
V_40 = V_111 ;
goto V_93;
}
F_47 ( V_28 -> V_70 ) ;
V_137 = F_143 ( V_5 , V_8 , V_35 ) ;
V_40 = V_35 -> V_161 ( V_8 , V_28 , V_30 , V_100 , V_156 , V_157 , V_137 ) ;
if ( V_40 <= 0 ) {
F_24 ( L_14 ) ;
F_144 ( V_28 -> V_70 ) ;
V_28 -> V_70 = NULL ;
F_102 ( V_5 , V_159 ) ;
if ( V_40 == - V_111 )
F_102 ( V_5 , V_160 ) ;
V_40 = - V_40 ;
goto V_93;
}
if ( V_149 && ! F_145 ( V_151 , & V_8 -> V_59 ) )
F_94 ( V_162 , V_8 ) ;
V_93:
if ( V_58 ) {
if ( V_40 == V_163 )
V_28 -> V_70 = (struct V_69 * ) V_58 ;
else
F_57 ( V_58 ) ;
}
return V_40 ;
}
bool F_146 ( struct V_11 * V_43 ,
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
void F_147 ( struct V_46 * V_8 ,
const struct V_11 * V_164 )
{
struct V_97 * V_98 = F_93 ( V_8 ) ;
F_47 ( ! F_74 ( V_8 ) ) ;
F_24 ( L_15 , V_8 ) ;
F_148 ( V_164 ) ;
V_8 -> V_47 [ V_49 ] . V_12 = * V_164 ;
if ( V_8 -> V_74 || ( V_98 && ! F_149 ( & V_98 -> V_165 ) ) )
return;
F_18 () ;
F_136 ( V_8 , NULL , V_129 ) ;
F_20 () ;
}
void F_150 ( struct V_46 * V_8 ,
enum V_99 V_100 ,
const struct V_27 * V_28 ,
unsigned long V_166 ,
int V_167 )
{
F_47 ( V_8 -> V_71 . V_168 == ( unsigned long ) V_8 ) ;
F_47 ( V_28 ) ;
if ( F_100 ( V_169 , & V_8 -> V_59 ) )
goto V_170;
if ( ! F_74 ( V_8 ) ) {
V_8 -> V_71 . V_102 = V_166 ;
} else {
unsigned long V_171 = V_103 + V_166 ;
if ( V_171 - V_8 -> V_71 . V_102 >= V_172 )
F_151 ( & V_8 -> V_71 , V_171 ) ;
}
V_170:
if ( V_167 ) {
struct V_173 * V_170 ;
V_170 = F_152 ( V_8 ) ;
if ( V_170 ) {
struct V_174 * V_175 = V_170 -> V_175 ;
F_153 ( & V_175 [ F_89 ( V_100 ) ] . V_176 ) ;
F_154 ( V_28 -> V_177 , & V_175 [ F_89 ( V_100 ) ] . V_178 ) ;
}
}
}
bool F_155 ( struct V_46 * V_8 ,
enum V_99 V_100 ,
const struct V_27 * V_28 ,
int V_167 )
{
if ( V_167 ) {
struct V_173 * V_170 ;
V_170 = F_152 ( V_8 ) ;
if ( V_170 ) {
struct V_174 * V_175 = V_170 -> V_175 ;
F_153 ( & V_175 [ F_89 ( V_100 ) ] . V_176 ) ;
F_154 ( V_28 -> V_177 - F_140 ( V_28 ) ,
& V_175 [ F_89 ( V_100 ) ] . V_178 ) ;
}
}
if ( F_101 ( & V_8 -> V_71 ) ) {
V_8 -> V_71 . V_179 ( ( unsigned long ) V_8 ) ;
return true ;
}
return false ;
}
int F_156 ( struct V_27 * V_28 ,
const struct V_11 * V_12 )
{
if ( F_157 ( V_28 , V_180 , V_12 -> V_15 . V_21 . V_181 . V_182 ) ||
F_157 ( V_28 , V_183 , V_12 -> V_16 . V_21 . V_181 . V_182 ) )
goto V_184;
return 0 ;
V_184:
return - 1 ;
}
int F_158 ( struct V_185 * V_186 [] ,
struct V_11 * V_187 )
{
if ( ! V_186 [ V_180 ] || ! V_186 [ V_183 ] )
return - V_188 ;
V_187 -> V_15 . V_21 . V_181 . V_182 = F_159 ( V_186 [ V_180 ] ) ;
V_187 -> V_16 . V_21 . V_181 . V_182 = F_159 ( V_186 [ V_183 ] ) ;
return 0 ;
}
int F_160 ( void )
{
return F_161 ( V_189 , V_190 + 1 ) ;
}
static void F_162 ( struct V_27 * V_191 , const struct V_27 * V_28 )
{
struct V_46 * V_8 ;
enum V_99 V_100 ;
V_8 = F_88 ( V_28 , & V_100 ) ;
if ( F_89 ( V_100 ) == V_38 )
V_100 = V_192 ;
else
V_100 = V_153 ;
V_191 -> V_70 = & V_8 -> V_67 ;
V_191 -> V_155 = V_100 ;
F_137 ( V_191 -> V_70 ) ;
}
static struct V_46 *
F_163 ( struct V_5 * V_5 , int (* F_164)( struct V_46 * V_10 , void * V_168 ) ,
void * V_168 , unsigned int * V_88 )
{
struct V_85 * V_86 ;
struct V_46 * V_8 ;
struct V_87 * V_14 ;
int V_52 ;
T_8 * V_117 ;
for (; * V_88 < V_5 -> V_8 . V_26 ; ( * V_88 ) ++ ) {
V_117 = & V_4 [ * V_88 % V_3 ] ;
F_54 () ;
F_4 ( V_117 ) ;
if ( * V_88 < V_5 -> V_8 . V_26 ) {
F_84 (h, n, &net->ct.hash[*bucket], hnnode) {
if ( F_141 ( V_86 ) != V_38 )
continue;
V_8 = F_72 ( V_86 ) ;
if ( F_164 ( V_8 , V_168 ) )
goto V_90;
}
}
F_2 ( V_117 ) ;
F_56 () ;
}
F_165 (cpu) {
struct V_50 * V_51 = F_29 ( V_5 -> V_8 . V_53 , V_52 ) ;
F_166 ( & V_51 -> V_54 ) ;
F_84 (h, n, &pcpu->unconfirmed, hnnode) {
V_8 = F_72 ( V_86 ) ;
if ( F_164 ( V_8 , V_168 ) )
F_69 ( V_83 , & V_8 -> V_59 ) ;
}
F_167 ( & V_51 -> V_54 ) ;
}
return NULL ;
V_90:
F_90 ( & V_8 -> V_67 . V_68 ) ;
F_2 ( V_117 ) ;
F_56 () ;
return V_8 ;
}
void F_168 ( struct V_5 * V_5 ,
int (* F_164)( struct V_46 * V_10 , void * V_168 ) ,
void * V_168 , T_1 V_77 , int V_78 )
{
struct V_46 * V_8 ;
unsigned int V_88 = 0 ;
while ( ( V_8 = F_163 ( V_5 , F_164 , V_168 , & V_88 ) ) != NULL ) {
if ( F_101 ( & V_8 -> V_71 ) )
F_62 ( V_8 , V_77 , V_78 ) ;
F_57 ( V_8 ) ;
}
}
static int F_169 ( struct V_46 * V_10 , void * V_168 )
{
return 1 ;
}
void F_170 ( void * V_24 , unsigned int V_25 )
{
if ( F_171 ( V_24 ) )
F_172 ( V_24 ) ;
else
F_173 ( ( unsigned long ) V_24 ,
F_174 ( sizeof( struct V_193 ) * V_25 ) ) ;
}
static int F_175 ( void )
{
int V_115 = 0 , V_52 ;
F_165 (cpu) {
struct V_46 * V_8 = & F_176 ( V_194 , V_52 ) ;
V_115 += F_48 ( & V_8 -> V_67 . V_68 ) - 1 ;
}
return V_115 ;
}
void F_177 ( void )
{
F_178 ( V_195 , NULL ) ;
}
void F_179 ( void )
{
F_178 ( V_196 , NULL ) ;
while ( F_175 () > 0 )
F_180 () ;
#ifdef F_39
F_181 ( & V_197 ) ;
#endif
F_182 () ;
F_183 () ;
F_184 () ;
F_185 () ;
F_186 () ;
F_187 () ;
F_188 () ;
F_189 () ;
F_190 () ;
}
void F_191 ( struct V_5 * V_5 )
{
F_192 ( V_198 ) ;
F_193 ( & V_5 -> V_199 , & V_198 ) ;
F_194 ( & V_198 ) ;
}
void F_194 ( struct V_200 * V_201 )
{
int V_202 ;
struct V_5 * V_5 ;
F_195 () ;
V_203:
V_202 = 0 ;
F_196 (net, net_exit_list, exit_list) {
F_168 ( V_5 , F_169 , NULL , 0 , 0 ) ;
if ( F_48 ( & V_5 -> V_8 . V_123 ) != 0 )
V_202 = 1 ;
}
if ( V_202 ) {
F_180 () ;
goto V_203;
}
F_196 (net, net_exit_list, exit_list) {
F_170 ( V_5 -> V_8 . V_24 , V_5 -> V_8 . V_26 ) ;
F_197 ( V_5 ) ;
F_198 ( V_5 ) ;
F_199 ( V_5 ) ;
F_200 ( V_5 ) ;
F_201 ( V_5 ) ;
F_202 ( V_5 ) ;
F_203 ( V_5 -> V_8 . V_126 ) ;
F_42 ( V_5 -> V_8 . V_204 ) ;
F_204 ( V_5 -> V_8 . V_205 ) ;
F_204 ( V_5 -> V_8 . V_53 ) ;
}
}
void * F_205 ( unsigned int * V_206 , int V_207 )
{
struct V_208 * V_24 ;
unsigned int V_209 , V_10 ;
T_9 V_210 ;
F_206 ( sizeof( struct V_208 ) != sizeof( struct V_193 ) ) ;
V_209 = * V_206 = F_207 ( * V_206 , V_211 / sizeof( struct V_208 ) ) ;
V_210 = V_209 * sizeof( struct V_208 ) ;
V_24 = ( void * ) F_208 ( V_212 | V_213 | V_214 ,
F_174 ( V_210 ) ) ;
if ( ! V_24 )
V_24 = F_209 ( V_210 ) ;
if ( V_24 && V_207 )
for ( V_10 = 0 ; V_10 < V_209 ; V_10 ++ )
F_210 ( & V_24 [ V_10 ] , V_10 ) ;
return V_24 ;
}
int F_211 ( const char * V_215 , struct V_216 * V_217 )
{
int V_10 , V_88 , V_218 ;
unsigned int V_219 , V_220 ;
struct V_208 * V_24 , * V_221 ;
struct V_85 * V_86 ;
struct V_46 * V_8 ;
if ( V_222 -> V_223 -> V_224 != & V_225 )
return - V_226 ;
if ( ! V_227 )
return F_212 ( V_215 , V_217 ) ;
V_218 = F_213 ( V_215 , 0 , & V_219 ) ;
if ( V_218 )
return V_218 ;
if ( ! V_219 )
return - V_188 ;
V_24 = F_205 ( & V_219 , 1 ) ;
if ( ! V_24 )
return - V_125 ;
F_54 () ;
F_7 () ;
F_214 ( & V_225 . V_8 . V_9 ) ;
for ( V_10 = 0 ; V_10 < V_225 . V_8 . V_26 ; V_10 ++ ) {
while ( ! F_215 ( & V_225 . V_8 . V_24 [ V_10 ] ) ) {
V_86 = F_216 ( V_225 . V_8 . V_24 [ V_10 ] . V_228 ,
struct V_85 , V_48 ) ;
V_8 = F_72 ( V_86 ) ;
F_25 ( & V_86 -> V_48 ) ;
V_88 = F_14 ( & V_86 -> V_12 , V_63 ( V_8 ) ,
V_219 ) ;
F_82 ( & V_86 -> V_48 , & V_24 [ V_88 ] ) ;
}
}
V_220 = V_225 . V_8 . V_26 ;
V_221 = V_225 . V_8 . V_24 ;
V_225 . V_8 . V_26 = V_227 = V_219 ;
V_225 . V_8 . V_24 = V_24 ;
F_217 ( & V_225 . V_8 . V_9 ) ;
F_8 () ;
F_56 () ;
F_170 ( V_221 , V_220 ) ;
return 0 ;
}
void F_218 ( unsigned long V_229 )
{
int V_52 ;
F_165 (cpu)
F_176 ( V_194 , V_52 ) . V_59 |= V_229 ;
}
int F_219 ( void )
{
int V_230 = 8 ;
int V_10 , V_40 , V_52 ;
for ( V_10 = 0 ; V_10 < V_3 ; V_10 ++ )
F_111 ( & V_4 [ V_10 ] ) ;
if ( ! V_227 ) {
V_227
= ( ( ( V_231 << V_232 ) / 16384 )
/ sizeof( struct V_193 ) ) ;
if ( V_231 > ( 4 * ( 1024 * 1024 * 1024 / V_211 ) ) )
V_227 = 65536 ;
else if ( V_231 > ( 1024 * 1024 * 1024 / V_211 ) )
V_227 = 16384 ;
if ( V_227 < 32 )
V_227 = 32 ;
V_230 = 4 ;
}
V_124 = V_230 * V_227 ;
F_220 ( V_233 L_16 ,
V_234 , V_227 ,
V_124 ) ;
V_40 = F_221 () ;
if ( V_40 < 0 )
goto V_235;
V_40 = F_222 () ;
if ( V_40 < 0 )
goto V_236;
V_40 = F_223 () ;
if ( V_40 < 0 )
goto V_237;
V_40 = F_224 () ;
if ( V_40 < 0 )
goto V_238;
V_40 = F_225 () ;
if ( V_40 < 0 )
goto V_239;
V_40 = F_226 () ;
if ( V_40 < 0 )
goto V_240;
V_40 = F_227 () ;
if ( V_40 < 0 )
goto V_241;
V_40 = F_228 () ;
if ( V_40 < 0 )
goto V_242;
#ifdef F_39
V_40 = F_229 ( & V_197 ) ;
if ( V_40 < 0 )
goto V_243;
#endif
V_40 = F_230 () ;
if ( V_40 < 0 )
goto V_244;
F_165 (cpu) {
struct V_46 * V_8 = & F_176 ( V_194 , V_52 ) ;
F_38 ( & V_8 -> V_61 , & V_225 ) ;
F_41 ( & V_8 -> V_67 . V_68 , 1 ) ;
}
F_218 ( V_104 | V_245 ) ;
return 0 ;
V_244:
#ifdef F_39
F_181 ( & V_197 ) ;
V_243:
#endif
F_183 () ;
V_242:
F_184 () ;
V_241:
F_185 () ;
V_240:
F_186 () ;
V_239:
F_187 () ;
V_238:
F_188 () ;
V_237:
F_189 () ;
V_236:
F_190 () ;
V_235:
return V_40 ;
}
void F_231 ( void )
{
F_178 ( V_195 , F_162 ) ;
F_178 ( V_196 , F_46 ) ;
}
int F_232 ( struct V_5 * V_5 )
{
int V_40 = - V_125 ;
int V_52 ;
F_41 ( & V_5 -> V_8 . V_123 , 0 ) ;
F_233 ( & V_5 -> V_8 . V_9 ) ;
V_5 -> V_8 . V_53 = F_234 ( struct V_50 ) ;
if ( ! V_5 -> V_8 . V_53 )
goto V_246;
F_165 (cpu) {
struct V_50 * V_51 = F_29 ( V_5 -> V_8 . V_53 , V_52 ) ;
F_111 ( & V_51 -> V_54 ) ;
F_210 ( & V_51 -> V_56 , V_247 ) ;
F_210 ( & V_51 -> V_55 , V_248 ) ;
}
V_5 -> V_8 . V_205 = F_234 ( struct V_249 ) ;
if ( ! V_5 -> V_8 . V_205 )
goto V_250;
V_5 -> V_8 . V_204 = F_235 ( V_212 , L_17 , V_5 ) ;
if ( ! V_5 -> V_8 . V_204 )
goto V_251;
V_5 -> V_8 . V_126 = F_236 ( V_5 -> V_8 . V_204 ,
sizeof( struct V_46 ) , 0 ,
V_252 , NULL ) ;
if ( ! V_5 -> V_8 . V_126 ) {
F_220 ( V_253 L_18 ) ;
goto V_254;
}
V_5 -> V_8 . V_26 = V_227 ;
V_5 -> V_8 . V_24 = F_205 ( & V_5 -> V_8 . V_26 , 1 ) ;
if ( ! V_5 -> V_8 . V_24 ) {
F_220 ( V_253 L_19 ) ;
goto V_255;
}
V_40 = F_237 ( V_5 ) ;
if ( V_40 < 0 )
goto V_235;
V_40 = F_238 ( V_5 ) ;
if ( V_40 < 0 )
goto V_236;
V_40 = F_239 ( V_5 ) ;
if ( V_40 < 0 )
goto V_237;
V_40 = F_240 ( V_5 ) ;
if ( V_40 < 0 )
goto V_238;
V_40 = F_241 ( V_5 ) ;
if ( V_40 < 0 )
goto V_240;
V_40 = F_242 ( V_5 ) ;
if ( V_40 < 0 )
goto V_244;
return 0 ;
V_244:
F_198 ( V_5 ) ;
V_240:
F_199 ( V_5 ) ;
V_238:
F_200 ( V_5 ) ;
V_237:
F_201 ( V_5 ) ;
V_236:
F_202 ( V_5 ) ;
V_235:
F_170 ( V_5 -> V_8 . V_24 , V_5 -> V_8 . V_26 ) ;
V_255:
F_203 ( V_5 -> V_8 . V_126 ) ;
V_254:
F_42 ( V_5 -> V_8 . V_204 ) ;
V_251:
F_204 ( V_5 -> V_8 . V_205 ) ;
V_250:
F_204 ( V_5 -> V_8 . V_53 ) ;
V_246:
return V_40 ;
}
