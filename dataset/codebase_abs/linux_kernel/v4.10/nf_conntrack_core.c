void F_1 ( T_1 * V_1 ) __acquires( V_1 )
{
F_2 ( V_1 ) ;
while ( F_3 ( V_2 ) ) {
F_4 ( V_1 ) ;
F_5 () ;
F_6 ( & V_3 ) ;
F_2 ( V_1 ) ;
}
}
static void F_7 ( unsigned int V_4 , unsigned int V_5 )
{
V_4 %= V_6 ;
V_5 %= V_6 ;
F_4 ( & V_7 [ V_4 ] ) ;
if ( V_4 != V_5 )
F_4 ( & V_7 [ V_5 ] ) ;
}
static bool F_8 ( struct V_8 * V_8 , unsigned int V_4 ,
unsigned int V_5 , unsigned int V_9 )
{
V_4 %= V_6 ;
V_5 %= V_6 ;
if ( V_4 <= V_5 ) {
F_1 ( & V_7 [ V_4 ] ) ;
if ( V_4 != V_5 )
F_9 ( & V_7 [ V_5 ] ,
V_10 ) ;
} else {
F_1 ( & V_7 [ V_5 ] ) ;
F_9 ( & V_7 [ V_4 ] ,
V_10 ) ;
}
if ( F_10 ( & V_11 , V_9 ) ) {
F_7 ( V_4 , V_5 ) ;
return true ;
}
return false ;
}
static void F_11 ( void )
{
int V_12 ;
F_2 ( & V_3 ) ;
V_2 = true ;
F_12 () ;
for ( V_12 = 0 ; V_12 < V_6 ; V_12 ++ ) {
F_6 ( & V_7 [ V_12 ] ) ;
}
}
static void F_13 ( void )
{
F_14 ( & V_2 , false ) ;
F_4 ( & V_3 ) ;
}
static T_2 F_15 ( const struct V_13 * V_14 ,
const struct V_8 * V_8 )
{
unsigned int V_15 ;
T_2 V_16 ;
F_16 ( & V_17 , sizeof( V_17 ) ) ;
V_16 = V_17 ^ F_17 ( V_8 ) ;
V_15 = ( sizeof( V_14 -> V_18 ) + sizeof( V_14 -> V_19 . V_20 ) ) / sizeof( T_2 ) ;
return F_18 ( ( T_2 * ) V_14 , V_15 , V_16 ^
( ( ( V_21 V_22 ) V_14 -> V_19 . V_23 . V_24 << 16 ) |
V_14 -> V_19 . V_25 ) ) ;
}
static T_2 F_19 ( T_2 V_26 )
{
return F_20 ( V_26 , V_27 ) ;
}
static T_2 F_21 ( const struct V_8 * V_8 ,
const struct V_13 * V_14 ,
unsigned int V_28 )
{
return F_20 ( F_15 ( V_14 , V_8 ) , V_28 ) ;
}
static T_2 F_22 ( const struct V_8 * V_8 ,
const struct V_13 * V_14 )
{
return F_19 ( F_15 ( V_14 , V_8 ) ) ;
}
bool
F_23 ( const struct V_29 * V_30 ,
unsigned int V_31 ,
unsigned int V_32 ,
T_3 V_33 ,
T_4 V_25 ,
struct V_8 * V_8 ,
struct V_13 * V_14 ,
const struct V_34 * V_35 ,
const struct V_36 * V_37 )
{
memset ( V_14 , 0 , sizeof( * V_14 ) ) ;
V_14 -> V_18 . V_33 = V_33 ;
if ( V_35 -> V_38 ( V_30 , V_31 , V_14 ) == 0 )
return false ;
V_14 -> V_19 . V_25 = V_25 ;
V_14 -> V_19 . V_39 = V_40 ;
return V_37 -> V_38 ( V_30 , V_32 , V_8 , V_14 ) ;
}
bool F_24 ( const struct V_29 * V_30 , unsigned int V_31 ,
T_3 V_33 ,
struct V_8 * V_8 , struct V_13 * V_14 )
{
struct V_34 * V_35 ;
struct V_36 * V_37 ;
unsigned int V_41 ;
T_4 V_25 ;
int V_42 ;
F_25 () ;
V_35 = F_26 ( V_33 ) ;
V_42 = V_35 -> V_43 ( V_30 , V_31 , & V_41 , & V_25 ) ;
if ( V_42 != V_44 ) {
F_27 () ;
return false ;
}
V_37 = F_28 ( V_33 , V_25 ) ;
V_42 = F_23 ( V_30 , V_31 , V_41 , V_33 , V_25 , V_8 , V_14 ,
V_35 , V_37 ) ;
F_27 () ;
return V_42 ;
}
bool
F_29 ( struct V_13 * V_45 ,
const struct V_13 * V_46 ,
const struct V_34 * V_35 ,
const struct V_36 * V_37 )
{
memset ( V_45 , 0 , sizeof( * V_45 ) ) ;
V_45 -> V_18 . V_33 = V_46 -> V_18 . V_33 ;
if ( V_35 -> V_47 ( V_45 , V_46 ) == 0 )
return false ;
V_45 -> V_19 . V_39 = ! V_46 -> V_19 . V_39 ;
V_45 -> V_19 . V_25 = V_46 -> V_19 . V_25 ;
return V_37 -> V_47 ( V_45 , V_46 ) ;
}
static void
F_30 ( struct V_48 * V_49 )
{
F_31 ( L_1 , V_49 ) ;
F_32 ( & V_49 -> V_50 [ V_40 ] . V_51 ) ;
F_32 ( & V_49 -> V_50 [ V_52 ] . V_51 ) ;
F_33 ( V_49 ) ;
}
static void F_34 ( struct V_48 * V_49 )
{
struct V_53 * V_54 ;
V_49 -> V_55 = F_35 () ;
V_54 = F_36 ( F_37 ( V_49 ) -> V_49 . V_56 , V_49 -> V_55 ) ;
F_2 ( & V_54 -> V_1 ) ;
F_38 ( & V_49 -> V_50 [ V_40 ] . V_51 ,
& V_54 -> V_57 ) ;
F_4 ( & V_54 -> V_1 ) ;
}
static void F_39 ( struct V_48 * V_49 )
{
struct V_53 * V_54 ;
V_49 -> V_55 = F_35 () ;
V_54 = F_36 ( F_37 ( V_49 ) -> V_49 . V_56 , V_49 -> V_55 ) ;
F_2 ( & V_54 -> V_1 ) ;
F_38 ( & V_49 -> V_50 [ V_40 ] . V_51 ,
& V_54 -> V_58 ) ;
F_4 ( & V_54 -> V_1 ) ;
}
static void F_40 ( struct V_48 * V_49 )
{
struct V_53 * V_54 ;
V_54 = F_36 ( F_37 ( V_49 ) -> V_49 . V_56 , V_49 -> V_55 ) ;
F_2 ( & V_54 -> V_1 ) ;
F_41 ( F_42 ( & V_49 -> V_50 [ V_40 ] . V_51 ) ) ;
F_32 ( & V_49 -> V_50 [ V_40 ] . V_51 ) ;
F_4 ( & V_54 -> V_1 ) ;
}
struct V_48 * F_43 ( struct V_8 * V_8 ,
const struct V_59 * V_60 ,
T_5 V_61 )
{
struct V_48 * V_62 ;
V_62 = F_44 ( sizeof( * V_62 ) , V_61 ) ;
if ( V_62 == NULL )
return NULL ;
V_62 -> V_63 = V_64 ;
F_45 ( & V_62 -> V_65 , V_8 ) ;
F_46 ( V_62 , V_60 ) ;
F_47 ( & V_62 -> V_66 . V_67 , 0 ) ;
return V_62 ;
}
void F_48 ( struct V_48 * V_62 )
{
F_49 ( V_62 ) ;
F_50 ( V_62 ) ;
F_51 ( V_62 ) ;
}
static void
F_52 ( struct V_68 * V_69 )
{
struct V_48 * V_49 = (struct V_48 * ) V_69 ;
struct V_36 * V_37 ;
F_31 ( L_2 , V_49 ) ;
F_53 ( F_54 ( & V_69 -> V_67 ) == 0 ) ;
if ( F_3 ( F_55 ( V_49 ) ) ) {
F_48 ( V_49 ) ;
return;
}
F_25 () ;
V_37 = F_28 ( F_56 ( V_49 ) , F_57 ( V_49 ) ) ;
if ( V_37 -> V_70 )
V_37 -> V_70 ( V_49 ) ;
F_27 () ;
F_58 () ;
F_33 ( V_49 ) ;
F_40 ( V_49 ) ;
F_59 () ;
if ( V_49 -> V_71 )
F_60 ( V_49 -> V_71 ) ;
F_31 ( L_3 , V_49 ) ;
F_61 ( V_49 ) ;
}
static void F_62 ( struct V_48 * V_49 )
{
struct V_8 * V_8 = F_37 ( V_49 ) ;
unsigned int V_26 , V_72 ;
unsigned int V_9 ;
F_63 ( V_49 ) ;
F_58 () ;
do {
V_9 = F_64 ( & V_11 ) ;
V_26 = F_22 ( V_8 ,
& V_49 -> V_50 [ V_40 ] . V_14 ) ;
V_72 = F_22 ( V_8 ,
& V_49 -> V_50 [ V_52 ] . V_14 ) ;
} while ( F_8 ( V_8 , V_26 , V_72 , V_9 ) );
F_30 ( V_49 ) ;
F_7 ( V_26 , V_72 ) ;
F_34 ( V_49 ) ;
F_59 () ;
}
bool F_65 ( struct V_48 * V_49 , T_2 V_73 , int V_74 )
{
struct V_75 * V_76 ;
if ( F_66 ( V_77 , & V_49 -> V_63 ) )
return false ;
V_76 = F_67 ( V_49 ) ;
if ( V_76 && V_76 -> V_78 == 0 )
V_76 -> V_78 = F_68 () ;
if ( F_69 ( V_79 , V_49 ,
V_73 , V_74 ) < 0 ) {
F_62 ( V_49 ) ;
F_70 ( F_37 ( V_49 ) ) ;
return false ;
}
F_71 ( F_37 ( V_49 ) ) ;
F_62 ( V_49 ) ;
F_60 ( V_49 ) ;
return true ;
}
static inline bool
F_72 ( struct V_80 * V_81 ,
const struct V_13 * V_14 ,
const struct V_59 * V_60 ,
const struct V_8 * V_8 )
{
struct V_48 * V_49 = F_73 ( V_81 ) ;
return F_74 ( V_14 , & V_81 -> V_14 ) &&
F_75 ( V_49 , V_60 , F_76 ( V_81 ) ) &&
F_77 ( V_49 ) &&
F_78 ( V_8 , F_37 ( V_49 ) ) ;
}
static void F_79 ( struct V_48 * V_49 )
{
if ( ! F_80 ( & V_49 -> V_66 . V_67 ) )
return;
if ( F_81 ( V_49 ) )
F_82 ( V_49 ) ;
F_60 ( V_49 ) ;
}
static struct V_80 *
F_83 ( struct V_8 * V_8 , const struct V_59 * V_60 ,
const struct V_13 * V_14 , T_2 V_26 )
{
struct V_80 * V_81 ;
struct V_82 * V_83 ;
struct V_84 * V_15 ;
unsigned int V_85 , V_86 ;
V_87:
F_84 ( & V_83 , & V_86 ) ;
V_85 = F_20 ( V_26 , V_86 ) ;
F_85 (h, n, &ct_hash[bucket], hnnode) {
struct V_48 * V_49 ;
V_49 = F_73 ( V_81 ) ;
if ( F_86 ( V_49 ) ) {
F_79 ( V_49 ) ;
continue;
}
if ( F_87 ( V_49 ) )
continue;
if ( F_72 ( V_81 , V_14 , V_60 , V_8 ) )
return V_81 ;
}
if ( F_88 ( V_15 ) != V_85 ) {
F_89 ( V_8 , V_88 ) ;
goto V_87;
}
return NULL ;
}
static struct V_80 *
F_90 ( struct V_8 * V_8 , const struct V_59 * V_60 ,
const struct V_13 * V_14 , T_2 V_26 )
{
struct V_80 * V_81 ;
struct V_48 * V_49 ;
F_25 () ;
V_87:
V_81 = F_83 ( V_8 , V_60 , V_14 , V_26 ) ;
if ( V_81 ) {
V_49 = F_73 ( V_81 ) ;
if ( F_3 ( F_87 ( V_49 ) ||
! F_80 ( & V_49 -> V_66 . V_67 ) ) )
V_81 = NULL ;
else {
if ( F_3 ( ! F_72 ( V_81 , V_14 , V_60 , V_8 ) ) ) {
F_60 ( V_49 ) ;
goto V_87;
}
}
}
F_27 () ;
return V_81 ;
}
struct V_80 *
F_91 ( struct V_8 * V_8 , const struct V_59 * V_60 ,
const struct V_13 * V_14 )
{
return F_90 ( V_8 , V_60 , V_14 ,
F_15 ( V_14 , V_8 ) ) ;
}
static void F_92 ( struct V_48 * V_49 ,
unsigned int V_26 ,
unsigned int V_72 )
{
F_93 ( & V_49 -> V_50 [ V_40 ] . V_51 ,
& V_89 [ V_26 ] ) ;
F_93 ( & V_49 -> V_50 [ V_52 ] . V_51 ,
& V_89 [ V_72 ] ) ;
}
int
F_94 ( struct V_48 * V_49 )
{
const struct V_59 * V_60 ;
struct V_8 * V_8 = F_37 ( V_49 ) ;
unsigned int V_26 , V_72 ;
struct V_80 * V_81 ;
struct V_84 * V_15 ;
unsigned int V_9 ;
V_60 = F_95 ( V_49 ) ;
F_58 () ;
do {
V_9 = F_64 ( & V_11 ) ;
V_26 = F_22 ( V_8 ,
& V_49 -> V_50 [ V_40 ] . V_14 ) ;
V_72 = F_22 ( V_8 ,
& V_49 -> V_50 [ V_52 ] . V_14 ) ;
} while ( F_8 ( V_8 , V_26 , V_72 , V_9 ) );
F_96 (h, n, &nf_conntrack_hash[hash], hnnode)
if ( F_72 ( V_81 , & V_49 -> V_50 [ V_40 ] . V_14 ,
V_60 , V_8 ) )
goto V_90;
F_96 (h, n, &nf_conntrack_hash[reply_hash], hnnode)
if ( F_72 ( V_81 , & V_49 -> V_50 [ V_52 ] . V_14 ,
V_60 , V_8 ) )
goto V_90;
F_97 () ;
F_47 ( & V_49 -> V_66 . V_67 , 2 ) ;
F_92 ( V_49 , V_26 , V_72 ) ;
F_7 ( V_26 , V_72 ) ;
F_98 ( V_8 , V_91 ) ;
F_59 () ;
return 0 ;
V_90:
F_7 ( V_26 , V_72 ) ;
F_98 ( V_8 , V_92 ) ;
F_59 () ;
return - V_93 ;
}
static inline void F_99 ( struct V_48 * V_49 ,
enum V_94 V_95 ,
unsigned int V_96 )
{
struct V_97 * V_98 ;
V_98 = F_100 ( V_49 ) ;
if ( V_98 ) {
struct V_99 * V_100 = V_98 -> V_100 ;
F_101 ( & V_100 [ F_102 ( V_95 ) ] . V_101 ) ;
F_103 ( V_96 , & V_100 [ F_102 ( V_95 ) ] . V_102 ) ;
}
}
static void F_104 ( struct V_48 * V_49 , enum V_94 V_95 ,
const struct V_48 * V_103 )
{
struct V_97 * V_98 ;
V_98 = F_100 ( V_103 ) ;
if ( V_98 ) {
struct V_99 * V_100 = V_98 -> V_100 ;
unsigned int V_102 ;
V_102 = F_105 ( & V_100 [ F_102 ( V_95 ) ] . V_102 ) ;
F_99 ( V_49 , V_95 , V_102 ) ;
}
}
static int F_106 ( struct V_8 * V_8 , struct V_29 * V_30 ,
enum V_94 V_95 ,
struct V_80 * V_81 )
{
struct V_48 * V_49 = F_73 ( V_81 ) ;
struct V_36 * V_37 ;
V_37 = F_28 ( F_56 ( V_49 ) , F_57 ( V_49 ) ) ;
if ( V_37 -> V_104 &&
! F_107 ( V_49 ) &&
! F_87 ( V_49 ) &&
F_80 ( & V_49 -> V_66 . V_67 ) ) {
F_104 ( V_49 , V_95 , (struct V_48 * ) V_30 -> V_69 ) ;
F_108 ( V_30 -> V_69 ) ;
V_30 -> V_69 = & V_49 -> V_66 ;
return V_44 ;
}
F_98 ( V_8 , V_105 ) ;
return V_106 ;
}
int
F_109 ( struct V_29 * V_30 )
{
const struct V_59 * V_60 ;
unsigned int V_26 , V_72 ;
struct V_80 * V_81 ;
struct V_48 * V_49 ;
struct V_107 * V_108 ;
struct V_75 * V_76 ;
struct V_84 * V_15 ;
enum V_94 V_95 ;
struct V_8 * V_8 ;
unsigned int V_9 ;
int V_42 = V_106 ;
V_49 = F_110 ( V_30 , & V_95 ) ;
V_8 = F_37 ( V_49 ) ;
if ( F_102 ( V_95 ) != V_40 )
return V_44 ;
V_60 = F_95 ( V_49 ) ;
F_58 () ;
do {
V_9 = F_64 ( & V_11 ) ;
V_26 = * ( unsigned long * ) & V_49 -> V_50 [ V_52 ] . V_51 . V_109 ;
V_26 = F_19 ( V_26 ) ;
V_72 = F_22 ( V_8 ,
& V_49 -> V_50 [ V_52 ] . V_14 ) ;
} while ( F_8 ( V_8 , V_26 , V_72 , V_9 ) );
F_53 ( ! F_77 ( V_49 ) ) ;
F_31 ( L_4 , V_49 ) ;
F_40 ( V_49 ) ;
if ( F_3 ( F_87 ( V_49 ) ) ) {
F_34 ( V_49 ) ;
goto V_57;
}
F_96 (h, n, &nf_conntrack_hash[hash], hnnode)
if ( F_72 ( V_81 , & V_49 -> V_50 [ V_40 ] . V_14 ,
V_60 , V_8 ) )
goto V_90;
F_96 (h, n, &nf_conntrack_hash[reply_hash], hnnode)
if ( F_72 ( V_81 , & V_49 -> V_50 [ V_52 ] . V_14 ,
V_60 , V_8 ) )
goto V_90;
V_49 -> V_110 += V_111 ;
F_111 ( & V_49 -> V_66 . V_67 ) ;
V_49 -> V_63 |= V_112 ;
V_76 = F_67 ( V_49 ) ;
if ( V_76 ) {
if ( V_30 -> V_76 == 0 )
F_112 ( V_30 ) ;
V_76 -> V_113 = F_113 ( V_30 -> V_76 ) ;
}
F_92 ( V_49 , V_26 , V_72 ) ;
F_7 ( V_26 , V_72 ) ;
F_59 () ;
V_108 = F_114 ( V_49 ) ;
if ( V_108 && V_108 -> V_114 )
F_115 ( V_115 , V_49 ) ;
F_115 ( F_116 ( V_49 ) ?
V_116 : V_117 , V_49 ) ;
return V_44 ;
V_90:
F_34 ( V_49 ) ;
V_42 = F_106 ( V_8 , V_30 , V_95 , V_81 ) ;
V_57:
F_7 ( V_26 , V_72 ) ;
F_98 ( V_8 , V_92 ) ;
F_59 () ;
return V_42 ;
}
int
F_117 ( const struct V_13 * V_14 ,
const struct V_48 * V_118 )
{
struct V_8 * V_8 = F_37 ( V_118 ) ;
const struct V_59 * V_60 ;
struct V_80 * V_81 ;
struct V_82 * V_83 ;
unsigned int V_26 , V_86 ;
struct V_84 * V_15 ;
struct V_48 * V_49 ;
V_60 = F_95 ( V_118 ) ;
F_25 () ;
V_87:
F_84 ( & V_83 , & V_86 ) ;
V_26 = F_21 ( V_8 , V_14 , V_86 ) ;
F_85 (h, n, &ct_hash[hash], hnnode) {
V_49 = F_73 ( V_81 ) ;
if ( V_49 == V_118 )
continue;
if ( F_86 ( V_49 ) ) {
F_79 ( V_49 ) ;
continue;
}
if ( F_72 ( V_81 , V_14 , V_60 , V_8 ) ) {
F_89 ( V_8 , V_119 ) ;
F_27 () ;
return 1 ;
}
}
if ( F_88 ( V_15 ) != V_26 ) {
F_89 ( V_8 , V_88 ) ;
goto V_87;
}
F_27 () ;
return 0 ;
}
static unsigned int F_118 ( struct V_8 * V_8 ,
struct V_82 * V_120 )
{
struct V_80 * V_81 ;
struct V_84 * V_15 ;
unsigned int V_121 = 0 ;
struct V_48 * V_122 ;
F_85 (h, n, head, hnnode) {
V_122 = F_73 ( V_81 ) ;
if ( F_86 ( V_122 ) ) {
F_79 ( V_122 ) ;
continue;
}
if ( F_119 ( V_123 , & V_122 -> V_63 ) ||
! F_78 ( F_37 ( V_122 ) , V_8 ) ||
F_87 ( V_122 ) )
continue;
if ( ! F_80 ( & V_122 -> V_66 . V_67 ) )
continue;
if ( F_78 ( F_37 ( V_122 ) , V_8 ) &&
F_77 ( V_122 ) &&
F_65 ( V_122 , 0 , 0 ) )
V_121 ++ ;
F_60 ( V_122 ) ;
}
return V_121 ;
}
static T_6 int F_120 ( struct V_8 * V_8 , unsigned int V_124 )
{
unsigned int V_12 ;
for ( V_12 = 0 ; V_12 < V_125 ; V_12 ++ ) {
struct V_82 * V_83 ;
unsigned int V_26 , V_86 , V_121 ;
F_25 () ;
F_84 ( & V_83 , & V_86 ) ;
V_26 = F_20 ( V_124 ++ , V_86 ) ;
V_121 = F_118 ( V_8 , & V_83 [ V_26 ] ) ;
F_27 () ;
if ( V_121 ) {
F_121 ( V_8 , F_120 , V_121 ) ;
return true ;
}
}
return false ;
}
static void F_122 ( struct V_126 * V_127 )
{
unsigned int V_128 = F_123 ( V_129 / V_130 , 1u ) ;
unsigned int V_12 , V_131 , V_132 = 0 , V_133 = 0 ;
struct V_134 * V_135 ;
unsigned int V_136 , V_137 = 0 ;
unsigned long V_138 ;
V_135 = F_124 ( V_127 , struct V_134 , V_139 . V_127 ) ;
V_131 = V_27 / V_130 ;
V_12 = V_135 -> V_140 ;
do {
struct V_80 * V_81 ;
struct V_82 * V_83 ;
struct V_84 * V_15 ;
unsigned int V_141 ;
struct V_48 * V_122 ;
V_12 ++ ;
F_25 () ;
F_84 ( & V_83 , & V_141 ) ;
if ( V_12 >= V_141 )
V_12 = 0 ;
F_85 (h, n, &ct_hash[i], hnnode) {
V_122 = F_73 ( V_81 ) ;
V_137 ++ ;
if ( F_86 ( V_122 ) ) {
F_79 ( V_122 ) ;
V_133 ++ ;
continue;
}
}
F_27 () ;
F_125 () ;
} while ( ++ V_132 < V_131 );
if ( V_135 -> V_142 )
return;
V_136 = V_137 ? V_133 * 100 / V_137 : 0 ;
if ( V_136 > V_143 ) {
V_135 -> V_144 = V_128 ;
} else {
unsigned int F_123 = V_145 / V_130 ;
F_126 ( ( V_145 / V_130 ) == 0 ) ;
V_135 -> V_144 += V_128 ;
if ( V_135 -> V_144 > F_123 )
V_135 -> V_144 = F_123 ;
}
V_138 = V_135 -> V_144 ;
V_135 -> V_140 = V_12 ;
F_127 ( V_146 , & V_135 -> V_139 , V_138 ) ;
}
static void F_128 ( struct V_134 * V_135 )
{
F_129 ( & V_135 -> V_139 , F_122 ) ;
V_135 -> V_144 = V_129 ;
V_135 -> V_142 = false ;
}
static struct V_48 *
F_130 ( struct V_8 * V_8 ,
const struct V_59 * V_60 ,
const struct V_13 * V_46 ,
const struct V_13 * V_147 ,
T_5 V_148 , T_2 V_26 )
{
struct V_48 * V_49 ;
F_111 ( & V_8 -> V_49 . V_149 ) ;
if ( V_150 &&
F_3 ( F_54 ( & V_8 -> V_49 . V_149 ) > V_150 ) ) {
if ( ! F_120 ( V_8 , V_26 ) ) {
F_131 ( & V_8 -> V_49 . V_149 ) ;
F_132 ( L_5 ) ;
return F_133 ( - V_151 ) ;
}
}
V_49 = F_134 ( V_152 , V_148 ) ;
if ( V_49 == NULL )
goto V_90;
F_135 ( & V_49 -> V_1 ) ;
V_49 -> V_50 [ V_40 ] . V_14 = * V_46 ;
V_49 -> V_50 [ V_40 ] . V_51 . V_109 = NULL ;
V_49 -> V_50 [ V_52 ] . V_14 = * V_147 ;
* ( unsigned long * ) ( & V_49 -> V_50 [ V_52 ] . V_51 . V_109 ) = V_26 ;
V_49 -> V_63 = 0 ;
F_45 ( & V_49 -> V_65 , V_8 ) ;
memset ( & V_49 -> V_153 [ 0 ] , 0 ,
F_136 ( struct V_48 , V_154 ) -
F_136 ( struct V_48 , V_153 [ 0 ] ) ) ;
F_46 ( V_49 , V_60 ) ;
F_47 ( & V_49 -> V_66 . V_67 , 0 ) ;
return V_49 ;
V_90:
F_131 ( & V_8 -> V_49 . V_149 ) ;
return F_133 ( - V_151 ) ;
}
struct V_48 * F_137 ( struct V_8 * V_8 ,
const struct V_59 * V_60 ,
const struct V_13 * V_46 ,
const struct V_13 * V_147 ,
T_5 V_148 )
{
return F_130 ( V_8 , V_60 , V_46 , V_147 , V_148 , 0 ) ;
}
void F_61 ( struct V_48 * V_49 )
{
struct V_8 * V_8 = F_37 ( V_49 ) ;
F_53 ( F_54 ( & V_49 -> V_66 . V_67 ) == 0 ) ;
F_49 ( V_49 ) ;
F_50 ( V_49 ) ;
F_138 ( V_152 , V_49 ) ;
F_139 () ;
F_131 ( & V_8 -> V_49 . V_149 ) ;
}
static struct V_80 *
F_140 ( struct V_8 * V_8 , struct V_48 * V_62 ,
const struct V_13 * V_14 ,
struct V_34 * V_35 ,
struct V_36 * V_37 ,
struct V_29 * V_30 ,
unsigned int V_32 , T_2 V_26 )
{
struct V_48 * V_49 ;
struct V_107 * V_108 ;
struct V_13 V_155 ;
struct V_156 * V_157 ;
struct V_158 * exp = NULL ;
const struct V_59 * V_60 ;
struct V_159 * V_160 ;
struct V_59 V_122 ;
unsigned int * V_161 ;
if ( ! F_29 ( & V_155 , V_14 , V_35 , V_37 ) ) {
F_31 ( L_6 ) ;
return NULL ;
}
V_60 = F_141 ( V_62 , V_30 , & V_122 ) ;
V_49 = F_130 ( V_8 , V_60 , V_14 , & V_155 , V_162 ,
V_26 ) ;
if ( F_142 ( V_49 ) )
return (struct V_80 * ) V_49 ;
if ( ! F_143 ( V_49 , V_62 ) ) {
F_61 ( V_49 ) ;
return F_133 ( - V_151 ) ;
}
V_160 = V_62 ? F_144 ( V_62 ) : NULL ;
if ( V_160 ) {
V_161 = F_145 ( V_160 ) ;
if ( F_3 ( ! V_161 ) )
V_161 = V_37 -> V_163 ( V_8 ) ;
} else {
V_161 = V_37 -> V_163 ( V_8 ) ;
}
if ( ! V_37 -> V_164 ( V_49 , V_30 , V_32 , V_161 ) ) {
F_61 ( V_49 ) ;
F_31 ( L_7 ) ;
return NULL ;
}
if ( V_160 )
F_146 ( V_49 , F_147 ( V_160 -> V_110 ) ,
V_162 ) ;
F_148 ( V_49 , V_162 ) ;
F_149 ( V_49 , V_162 ) ;
F_150 ( V_49 ) ;
V_157 = V_62 ? F_151 ( V_62 ) : NULL ;
F_152 ( V_49 , V_157 ? V_157 -> V_165 : 0 ,
V_157 ? V_157 -> V_166 : 0 ,
V_162 ) ;
F_58 () ;
if ( V_8 -> V_49 . V_167 ) {
F_2 ( & V_168 ) ;
exp = F_153 ( V_8 , V_60 , V_14 ) ;
if ( exp ) {
F_31 ( L_8 ,
V_49 , exp ) ;
F_154 ( V_169 , & V_49 -> V_63 ) ;
V_49 -> V_71 = exp -> V_71 ;
if ( exp -> V_114 ) {
V_108 = F_155 ( V_49 , exp -> V_114 ,
V_162 ) ;
if ( V_108 )
F_156 ( V_108 -> V_114 , exp -> V_114 ) ;
}
#ifdef F_157
V_49 -> V_170 = exp -> V_71 -> V_170 ;
#endif
#ifdef F_158
V_49 -> V_171 = exp -> V_71 -> V_171 ;
#endif
F_98 ( V_8 , V_172 ) ;
}
F_4 ( & V_168 ) ;
}
if ( ! exp )
F_159 ( V_49 , V_62 , V_162 ) ;
F_160 ( & V_49 -> V_66 ) ;
F_39 ( V_49 ) ;
F_59 () ;
if ( exp ) {
if ( exp -> V_173 )
exp -> V_173 ( V_49 , exp ) ;
F_161 ( exp ) ;
}
return & V_49 -> V_50 [ V_40 ] ;
}
static inline struct V_48 *
F_162 ( struct V_8 * V_8 , struct V_48 * V_62 ,
struct V_29 * V_30 ,
unsigned int V_32 ,
T_3 V_33 ,
T_4 V_25 ,
struct V_34 * V_35 ,
struct V_36 * V_37 ,
int * V_174 ,
enum V_94 * V_95 )
{
const struct V_59 * V_60 ;
struct V_13 V_14 ;
struct V_80 * V_81 ;
struct V_59 V_122 ;
struct V_48 * V_49 ;
T_2 V_26 ;
if ( ! F_23 ( V_30 , F_163 ( V_30 ) ,
V_32 , V_33 , V_25 , V_8 , & V_14 , V_35 ,
V_37 ) ) {
F_31 ( L_9 ) ;
return NULL ;
}
V_60 = F_141 ( V_62 , V_30 , & V_122 ) ;
V_26 = F_15 ( & V_14 , V_8 ) ;
V_81 = F_90 ( V_8 , V_60 , & V_14 , V_26 ) ;
if ( ! V_81 ) {
V_81 = F_140 ( V_8 , V_62 , & V_14 , V_35 , V_37 ,
V_30 , V_32 , V_26 ) ;
if ( ! V_81 )
return NULL ;
if ( F_142 ( V_81 ) )
return ( void * ) V_81 ;
}
V_49 = F_73 ( V_81 ) ;
if ( F_76 ( V_81 ) == V_52 ) {
* V_95 = V_175 ;
* V_174 = 1 ;
} else {
if ( F_119 ( V_176 , & V_49 -> V_63 ) ) {
F_31 ( L_10 , V_49 ) ;
* V_95 = V_177 ;
} else if ( F_119 ( V_169 , & V_49 -> V_63 ) ) {
F_31 ( L_11 , V_49 ) ;
* V_95 = V_178 ;
} else {
F_31 ( L_12 , V_49 ) ;
* V_95 = V_179 ;
}
* V_174 = 0 ;
}
V_30 -> V_69 = & V_49 -> V_66 ;
V_30 -> V_180 = * V_95 ;
return V_49 ;
}
unsigned int
F_164 ( struct V_8 * V_8 , T_4 V_181 , unsigned int V_182 ,
struct V_29 * V_30 )
{
struct V_48 * V_49 , * V_62 = NULL ;
enum V_94 V_95 ;
struct V_34 * V_35 ;
struct V_36 * V_37 ;
unsigned int * V_161 ;
unsigned int V_32 ;
T_4 V_25 ;
int V_174 = 0 ;
int V_42 ;
if ( V_30 -> V_69 ) {
V_62 = (struct V_48 * ) V_30 -> V_69 ;
if ( ! F_55 ( V_62 ) ) {
F_89 ( V_8 , V_183 ) ;
return V_44 ;
}
V_30 -> V_69 = NULL ;
}
V_35 = F_26 ( V_181 ) ;
V_42 = V_35 -> V_43 ( V_30 , F_163 ( V_30 ) ,
& V_32 , & V_25 ) ;
if ( V_42 <= 0 ) {
F_31 ( L_13 ) ;
F_89 ( V_8 , error ) ;
F_89 ( V_8 , V_184 ) ;
V_42 = - V_42 ;
goto V_90;
}
V_37 = F_28 ( V_181 , V_25 ) ;
if ( V_37 -> error != NULL ) {
V_42 = V_37 -> error ( V_8 , V_62 , V_30 , V_32 , & V_95 ,
V_181 , V_182 ) ;
if ( V_42 <= 0 ) {
F_89 ( V_8 , error ) ;
F_89 ( V_8 , V_184 ) ;
V_42 = - V_42 ;
goto V_90;
}
if ( V_30 -> V_69 )
goto V_90;
}
V_185:
V_49 = F_162 ( V_8 , V_62 , V_30 , V_32 , V_181 , V_25 ,
V_35 , V_37 , & V_174 , & V_95 ) ;
if ( ! V_49 ) {
F_89 ( V_8 , V_184 ) ;
V_42 = V_44 ;
goto V_90;
}
if ( F_142 ( V_49 ) ) {
F_89 ( V_8 , V_105 ) ;
V_42 = V_106 ;
goto V_90;
}
F_53 ( V_30 -> V_69 ) ;
V_161 = F_165 ( V_8 , V_49 , V_37 ) ;
V_42 = V_37 -> V_186 ( V_49 , V_30 , V_32 , V_95 , V_181 , V_182 , V_161 ) ;
if ( V_42 <= 0 ) {
F_31 ( L_14 ) ;
F_108 ( V_30 -> V_69 ) ;
V_30 -> V_69 = NULL ;
F_89 ( V_8 , V_184 ) ;
if ( V_42 == - V_106 )
F_89 ( V_8 , V_105 ) ;
if ( V_42 == - V_187 )
goto V_185;
V_42 = - V_42 ;
goto V_90;
}
if ( V_174 && ! F_66 ( V_176 , & V_49 -> V_63 ) )
F_115 ( V_188 , V_49 ) ;
V_90:
if ( V_62 )
F_60 ( V_62 ) ;
return V_42 ;
}
bool F_166 ( struct V_13 * V_45 ,
const struct V_13 * V_46 )
{
bool V_42 ;
F_25 () ;
V_42 = F_29 ( V_45 , V_46 ,
F_26 ( V_46 -> V_18 . V_33 ) ,
F_28 ( V_46 -> V_18 . V_33 ,
V_46 -> V_19 . V_25 ) ) ;
F_27 () ;
return V_42 ;
}
void F_167 ( struct V_48 * V_49 ,
const struct V_13 * V_189 )
{
struct V_107 * V_108 = F_114 ( V_49 ) ;
F_53 ( ! F_77 ( V_49 ) ) ;
F_31 ( L_15 , V_49 ) ;
F_168 ( V_189 ) ;
V_49 -> V_50 [ V_52 ] . V_14 = * V_189 ;
if ( V_49 -> V_71 || ( V_108 && ! F_169 ( & V_108 -> V_190 ) ) )
return;
F_25 () ;
F_159 ( V_49 , NULL , V_162 ) ;
F_27 () ;
}
void F_170 ( struct V_48 * V_49 ,
enum V_94 V_95 ,
const struct V_29 * V_30 ,
unsigned long V_191 ,
int V_192 )
{
F_53 ( V_30 ) ;
if ( F_119 ( V_193 , & V_49 -> V_63 ) )
goto V_98;
if ( F_77 ( V_49 ) )
V_191 += V_111 ;
V_49 -> V_110 = V_191 ;
V_98:
if ( V_192 )
F_99 ( V_49 , V_95 , V_30 -> V_96 ) ;
}
bool F_171 ( struct V_48 * V_49 ,
enum V_94 V_95 ,
const struct V_29 * V_30 )
{
F_99 ( V_49 , V_95 , V_30 -> V_96 ) ;
return F_65 ( V_49 , 0 , 0 ) ;
}
int F_172 ( struct V_29 * V_30 ,
const struct V_13 * V_14 )
{
if ( F_173 ( V_30 , V_194 , V_14 -> V_18 . V_23 . V_195 . V_196 ) ||
F_173 ( V_30 , V_197 , V_14 -> V_19 . V_23 . V_195 . V_196 ) )
goto V_198;
return 0 ;
V_198:
return - 1 ;
}
int F_174 ( struct V_199 * V_200 [] ,
struct V_13 * V_201 )
{
if ( ! V_200 [ V_194 ] || ! V_200 [ V_197 ] )
return - V_202 ;
V_201 -> V_18 . V_23 . V_195 . V_196 = F_175 ( V_200 [ V_194 ] ) ;
V_201 -> V_19 . V_23 . V_195 . V_196 = F_175 ( V_200 [ V_197 ] ) ;
return 0 ;
}
int F_176 ( void )
{
return F_177 ( V_203 , V_204 + 1 ) ;
}
static void F_178 ( struct V_29 * V_205 , const struct V_29 * V_30 )
{
struct V_48 * V_49 ;
enum V_94 V_95 ;
V_49 = F_110 ( V_30 , & V_95 ) ;
if ( F_102 ( V_95 ) == V_40 )
V_95 = V_206 ;
else
V_95 = V_178 ;
V_205 -> V_69 = & V_49 -> V_66 ;
V_205 -> V_180 = V_95 ;
F_160 ( V_205 -> V_69 ) ;
}
static struct V_48 *
F_179 ( struct V_8 * V_8 , int (* F_180)( struct V_48 * V_12 , void * V_207 ) ,
void * V_207 , unsigned int * V_85 )
{
struct V_80 * V_81 ;
struct V_48 * V_49 ;
struct V_84 * V_15 ;
int V_55 ;
T_1 * V_208 ;
for (; * V_85 < V_27 ; ( * V_85 ) ++ ) {
V_208 = & V_7 [ * V_85 % V_6 ] ;
F_58 () ;
F_1 ( V_208 ) ;
if ( * V_85 < V_27 ) {
F_96 (h, n, &nf_conntrack_hash[*bucket], hnnode) {
if ( F_76 ( V_81 ) != V_40 )
continue;
V_49 = F_73 ( V_81 ) ;
if ( F_78 ( F_37 ( V_49 ) , V_8 ) &&
F_180 ( V_49 , V_207 ) )
goto V_119;
}
}
F_4 ( V_208 ) ;
F_59 () ;
F_181 () ;
}
F_182 (cpu) {
struct V_53 * V_54 = F_36 ( V_8 -> V_49 . V_56 , V_55 ) ;
F_183 ( & V_54 -> V_1 ) ;
F_96 (h, n, &pcpu->unconfirmed, hnnode) {
V_49 = F_73 ( V_81 ) ;
if ( F_180 ( V_49 , V_207 ) )
F_184 ( V_77 , & V_49 -> V_63 ) ;
}
F_185 ( & V_54 -> V_1 ) ;
F_181 () ;
}
return NULL ;
V_119:
F_111 ( & V_49 -> V_66 . V_67 ) ;
F_4 ( V_208 ) ;
F_59 () ;
return V_49 ;
}
void F_186 ( struct V_8 * V_8 ,
int (* F_180)( struct V_48 * V_12 , void * V_207 ) ,
void * V_207 , T_2 V_73 , int V_74 )
{
struct V_48 * V_49 ;
unsigned int V_85 = 0 ;
F_187 () ;
if ( F_54 ( & V_8 -> V_49 . V_149 ) == 0 )
return;
while ( ( V_49 = F_179 ( V_8 , F_180 , V_207 , & V_85 ) ) != NULL ) {
F_65 ( V_49 , V_73 , V_74 ) ;
F_60 ( V_49 ) ;
F_181 () ;
}
}
static int F_188 ( struct V_48 * V_12 , void * V_207 )
{
return 1 ;
}
void F_189 ( void * V_26 , unsigned int V_28 )
{
if ( F_190 ( V_26 ) )
F_191 ( V_26 ) ;
else
F_192 ( ( unsigned long ) V_26 ,
F_193 ( sizeof( struct V_209 ) * V_28 ) ) ;
}
static int F_194 ( void )
{
int V_210 = 0 , V_55 ;
F_182 (cpu) {
struct V_48 * V_49 = & F_195 ( V_211 , V_55 ) ;
V_210 += F_54 ( & V_49 -> V_66 . V_67 ) - 1 ;
}
return V_210 ;
}
void F_196 ( void )
{
V_134 . V_142 = true ;
F_197 ( V_212 , NULL ) ;
}
void F_198 ( void )
{
F_197 ( V_213 , NULL ) ;
while ( F_194 () > 0 )
F_199 () ;
F_200 ( & V_134 . V_139 ) ;
F_189 ( V_89 , V_27 ) ;
F_201 () ;
F_202 () ;
F_203 () ;
F_204 () ;
F_205 () ;
F_206 () ;
F_207 () ;
F_208 () ;
F_209 () ;
F_210 ( V_152 ) ;
}
void F_211 ( struct V_8 * V_8 )
{
F_212 ( V_214 ) ;
F_213 ( & V_8 -> V_215 , & V_214 ) ;
F_214 ( & V_214 ) ;
}
void F_214 ( struct V_216 * V_217 )
{
int V_218 ;
struct V_8 * V_8 ;
F_215 () ;
V_219:
V_218 = 0 ;
F_216 (net, net_exit_list, exit_list) {
F_186 ( V_8 , F_188 , NULL , 0 , 0 ) ;
if ( F_54 ( & V_8 -> V_49 . V_149 ) != 0 )
V_218 = 1 ;
}
if ( V_218 ) {
F_199 () ;
goto V_219;
}
F_216 (net, net_exit_list, exit_list) {
F_217 ( V_8 ) ;
F_218 ( V_8 ) ;
F_219 ( V_8 ) ;
F_220 ( V_8 ) ;
F_221 ( V_8 ) ;
F_222 ( V_8 ) ;
F_223 ( V_8 -> V_49 . V_220 ) ;
F_223 ( V_8 -> V_49 . V_56 ) ;
}
}
void * F_224 ( unsigned int * V_221 , int V_222 )
{
struct V_82 * V_26 ;
unsigned int V_223 , V_12 ;
T_7 V_224 ;
if ( * V_221 > ( V_225 / sizeof( struct V_82 ) ) )
return NULL ;
F_126 ( sizeof( struct V_82 ) != sizeof( struct V_209 ) ) ;
V_223 = * V_221 = F_225 ( * V_221 , V_226 / sizeof( struct V_82 ) ) ;
if ( V_223 > ( V_225 / sizeof( struct V_82 ) ) )
return NULL ;
V_224 = V_223 * sizeof( struct V_82 ) ;
V_26 = ( void * ) F_226 ( V_227 | V_228 | V_229 ,
F_193 ( V_224 ) ) ;
if ( ! V_26 )
V_26 = F_227 ( V_224 ) ;
if ( V_26 && V_222 )
for ( V_12 = 0 ; V_12 < V_223 ; V_12 ++ )
F_228 ( & V_26 [ V_12 ] , V_12 ) ;
return V_26 ;
}
int F_229 ( unsigned int V_230 )
{
int V_12 , V_85 ;
unsigned int V_231 ;
struct V_82 * V_26 , * V_232 ;
struct V_80 * V_81 ;
struct V_48 * V_49 ;
if ( ! V_230 )
return - V_202 ;
V_26 = F_224 ( & V_230 , 1 ) ;
if ( ! V_26 )
return - V_151 ;
V_231 = V_27 ;
if ( V_231 == V_230 ) {
F_189 ( V_26 , V_230 ) ;
return 0 ;
}
F_58 () ;
F_11 () ;
F_230 ( & V_11 ) ;
for ( V_12 = 0 ; V_12 < V_27 ; V_12 ++ ) {
while ( ! F_231 ( & V_89 [ V_12 ] ) ) {
V_81 = F_232 ( V_89 [ V_12 ] . V_233 ,
struct V_80 , V_51 ) ;
V_49 = F_73 ( V_81 ) ;
F_32 ( & V_81 -> V_51 ) ;
V_85 = F_21 ( F_37 ( V_49 ) ,
& V_81 -> V_14 , V_230 ) ;
F_93 ( & V_81 -> V_51 , & V_26 [ V_85 ] ) ;
}
}
V_231 = V_27 ;
V_232 = V_89 ;
V_89 = V_26 ;
V_27 = V_230 ;
F_233 ( & V_11 ) ;
F_13 () ;
F_59 () ;
F_215 () ;
F_189 ( V_232 , V_231 ) ;
return 0 ;
}
int F_234 ( const char * V_234 , struct V_235 * V_236 )
{
unsigned int V_230 ;
int V_237 ;
if ( V_238 -> V_239 -> V_240 != & V_241 )
return - V_242 ;
if ( ! V_27 )
return F_235 ( V_234 , V_236 ) ;
V_237 = F_236 ( V_234 , 0 , & V_230 ) ;
if ( V_237 )
return V_237 ;
return F_229 ( V_230 ) ;
}
void F_237 ( unsigned long V_243 )
{
int V_55 ;
F_182 (cpu)
F_195 ( V_211 , V_55 ) . V_63 |= V_243 ;
}
int F_238 ( void )
{
int V_244 = 8 ;
int V_42 = - V_151 ;
int V_12 , V_55 ;
F_239 ( & V_11 ) ;
for ( V_12 = 0 ; V_12 < V_6 ; V_12 ++ )
F_135 ( & V_7 [ V_12 ] ) ;
if ( ! V_27 ) {
V_27
= ( ( ( V_245 << V_246 ) / 16384 )
/ sizeof( struct V_209 ) ) ;
if ( V_245 > ( 4 * ( 1024 * 1024 * 1024 / V_226 ) ) )
V_27 = 65536 ;
else if ( V_245 > ( 1024 * 1024 * 1024 / V_226 ) )
V_27 = 16384 ;
if ( V_27 < 32 )
V_27 = 32 ;
V_244 = 4 ;
}
V_89 = F_224 ( & V_27 , 1 ) ;
if ( ! V_89 )
return - V_151 ;
V_150 = V_244 * V_27 ;
V_152 = F_240 ( L_16 ,
sizeof( struct V_48 ) , 0 ,
V_247 | V_248 , NULL ) ;
if ( ! V_152 )
goto V_249;
F_241 ( V_250 L_17 ,
V_251 , V_27 ,
V_150 ) ;
V_42 = F_242 () ;
if ( V_42 < 0 )
goto V_252;
V_42 = F_243 () ;
if ( V_42 < 0 )
goto V_253;
V_42 = F_244 () ;
if ( V_42 < 0 )
goto V_254;
V_42 = F_245 () ;
if ( V_42 < 0 )
goto V_255;
V_42 = F_246 () ;
if ( V_42 < 0 )
goto V_256;
V_42 = F_247 () ;
if ( V_42 < 0 )
goto V_257;
V_42 = F_248 () ;
if ( V_42 < 0 )
goto V_258;
V_42 = F_249 () ;
if ( V_42 < 0 )
goto V_259;
V_42 = F_250 () ;
if ( V_42 < 0 )
goto V_260;
F_182 (cpu) {
struct V_48 * V_49 = & F_195 ( V_211 , V_55 ) ;
F_45 ( & V_49 -> V_65 , & V_241 ) ;
F_47 ( & V_49 -> V_66 . V_67 , 1 ) ;
}
F_237 ( V_112 | V_261 ) ;
F_128 ( & V_134 ) ;
F_127 ( V_146 , & V_134 . V_139 , V_129 ) ;
return 0 ;
V_260:
F_202 () ;
V_259:
F_203 () ;
V_258:
F_204 () ;
V_257:
F_205 () ;
V_256:
F_206 () ;
V_255:
F_207 () ;
V_254:
F_208 () ;
V_253:
F_209 () ;
V_252:
F_210 ( V_152 ) ;
V_249:
F_189 ( V_89 , V_27 ) ;
return V_42 ;
}
void F_251 ( void )
{
F_197 ( V_212 , F_178 ) ;
F_197 ( V_213 , F_52 ) ;
}
int F_252 ( struct V_8 * V_8 )
{
int V_42 = - V_151 ;
int V_55 ;
F_47 ( & V_8 -> V_49 . V_149 , 0 ) ;
V_8 -> V_49 . V_56 = F_253 ( struct V_53 ) ;
if ( ! V_8 -> V_49 . V_56 )
goto V_262;
F_182 (cpu) {
struct V_53 * V_54 = F_36 ( V_8 -> V_49 . V_56 , V_55 ) ;
F_135 ( & V_54 -> V_1 ) ;
F_228 ( & V_54 -> V_58 , V_263 ) ;
F_228 ( & V_54 -> V_57 , V_264 ) ;
}
V_8 -> V_49 . V_220 = F_253 ( struct V_265 ) ;
if ( ! V_8 -> V_49 . V_220 )
goto V_266;
V_42 = F_254 ( V_8 ) ;
if ( V_42 < 0 )
goto V_252;
V_42 = F_255 ( V_8 ) ;
if ( V_42 < 0 )
goto V_253;
V_42 = F_256 ( V_8 ) ;
if ( V_42 < 0 )
goto V_254;
V_42 = F_257 ( V_8 ) ;
if ( V_42 < 0 )
goto V_255;
V_42 = F_258 ( V_8 ) ;
if ( V_42 < 0 )
goto V_257;
V_42 = F_259 ( V_8 ) ;
if ( V_42 < 0 )
goto V_260;
return 0 ;
V_260:
F_218 ( V_8 ) ;
V_257:
F_219 ( V_8 ) ;
V_255:
F_220 ( V_8 ) ;
V_254:
F_221 ( V_8 ) ;
V_253:
F_222 ( V_8 ) ;
V_252:
F_223 ( V_8 -> V_49 . V_220 ) ;
V_266:
F_223 ( V_8 -> V_49 . V_56 ) ;
V_262:
return V_42 ;
}
