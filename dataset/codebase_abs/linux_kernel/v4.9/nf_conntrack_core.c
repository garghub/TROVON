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
if ( V_30 -> V_76 . V_113 == 0 )
F_112 ( V_30 ) ;
V_76 -> V_114 = F_113 ( V_30 -> V_76 ) ;
}
F_92 ( V_49 , V_26 , V_72 ) ;
F_7 ( V_26 , V_72 ) ;
F_59 () ;
V_108 = F_114 ( V_49 ) ;
if ( V_108 && V_108 -> V_115 )
F_115 ( V_116 , V_49 ) ;
F_115 ( F_116 ( V_49 ) ?
V_117 : V_118 , V_49 ) ;
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
const struct V_48 * V_119 )
{
struct V_8 * V_8 = F_37 ( V_119 ) ;
const struct V_59 * V_60 ;
struct V_80 * V_81 ;
struct V_82 * V_83 ;
unsigned int V_26 , V_86 ;
struct V_84 * V_15 ;
struct V_48 * V_49 ;
V_60 = F_95 ( V_119 ) ;
F_25 () ;
V_87:
F_84 ( & V_83 , & V_86 ) ;
V_26 = F_21 ( V_8 , V_14 , V_86 ) ;
F_85 (h, n, &ct_hash[hash], hnnode) {
V_49 = F_73 ( V_81 ) ;
if ( V_49 == V_119 )
continue;
if ( F_86 ( V_49 ) ) {
F_79 ( V_49 ) ;
continue;
}
if ( F_72 ( V_81 , V_14 , V_60 , V_8 ) ) {
F_89 ( V_8 , V_120 ) ;
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
struct V_82 * V_121 )
{
struct V_80 * V_81 ;
struct V_84 * V_15 ;
unsigned int V_122 = 0 ;
struct V_48 * V_123 ;
F_85 (h, n, head, hnnode) {
V_123 = F_73 ( V_81 ) ;
if ( F_86 ( V_123 ) ) {
F_79 ( V_123 ) ;
continue;
}
if ( F_119 ( V_124 , & V_123 -> V_63 ) ||
! F_78 ( F_37 ( V_123 ) , V_8 ) ||
F_87 ( V_123 ) )
continue;
if ( ! F_80 ( & V_123 -> V_66 . V_67 ) )
continue;
if ( F_78 ( F_37 ( V_123 ) , V_8 ) &&
F_77 ( V_123 ) &&
F_65 ( V_123 , 0 , 0 ) )
V_122 ++ ;
F_60 ( V_123 ) ;
}
return V_122 ;
}
static T_6 int F_120 ( struct V_8 * V_8 , unsigned int V_125 )
{
unsigned int V_12 ;
for ( V_12 = 0 ; V_12 < V_126 ; V_12 ++ ) {
struct V_82 * V_83 ;
unsigned int V_26 , V_86 , V_122 ;
F_25 () ;
F_84 ( & V_83 , & V_86 ) ;
V_26 = F_20 ( V_125 ++ , V_86 ) ;
V_122 = F_118 ( V_8 , & V_83 [ V_26 ] ) ;
F_27 () ;
if ( V_122 ) {
F_121 ( V_8 , F_120 , V_122 ) ;
return true ;
}
}
return false ;
}
static void F_122 ( struct V_127 * V_128 )
{
unsigned int V_12 , V_129 , V_130 = 0 , V_131 = 0 ;
struct V_132 * V_133 ;
unsigned int V_134 , V_135 = 0 ;
unsigned long V_136 ;
V_133 = F_123 ( V_128 , struct V_132 , V_137 . V_128 ) ;
V_129 = V_27 / V_138 ;
V_12 = V_133 -> V_139 ;
do {
struct V_80 * V_81 ;
struct V_82 * V_83 ;
struct V_84 * V_15 ;
unsigned int V_140 ;
struct V_48 * V_123 ;
V_12 ++ ;
F_25 () ;
F_84 ( & V_83 , & V_140 ) ;
if ( V_12 >= V_140 )
V_12 = 0 ;
F_85 (h, n, &ct_hash[i], hnnode) {
V_123 = F_73 ( V_81 ) ;
V_135 ++ ;
if ( F_86 ( V_123 ) ) {
F_79 ( V_123 ) ;
V_131 ++ ;
continue;
}
}
F_27 () ;
F_124 () ;
} while ( ++ V_130 < V_129 &&
V_131 < V_141 );
if ( V_133 -> V_142 )
return;
V_134 = V_135 ? V_131 * 100 / V_135 : 0 ;
if ( V_134 >= 90 || V_131 == V_141 ) {
V_133 -> V_143 = 0 ;
V_136 = 0 ;
} else if ( V_131 ) {
V_133 -> V_143 /= 2U ;
V_136 = F_125 ( 1 ) ;
} else {
if ( V_133 -> V_143 < V_144 )
V_133 -> V_143 += F_125 ( 1 ) ;
V_136 = V_133 -> V_143 ;
}
V_133 -> V_139 = V_12 ;
F_126 ( V_145 , & V_133 -> V_137 , V_136 ) ;
}
static void F_127 ( struct V_132 * V_133 )
{
F_128 ( & V_133 -> V_137 , F_122 ) ;
V_133 -> V_143 = V_144 ;
V_133 -> V_142 = false ;
}
static struct V_48 *
F_129 ( struct V_8 * V_8 ,
const struct V_59 * V_60 ,
const struct V_13 * V_46 ,
const struct V_13 * V_146 ,
T_5 V_147 , T_2 V_26 )
{
struct V_48 * V_49 ;
F_111 ( & V_8 -> V_49 . V_148 ) ;
if ( V_149 &&
F_3 ( F_54 ( & V_8 -> V_49 . V_148 ) > V_149 ) ) {
if ( ! F_120 ( V_8 , V_26 ) ) {
F_130 ( & V_8 -> V_49 . V_148 ) ;
F_131 ( L_5 ) ;
return F_132 ( - V_150 ) ;
}
}
V_49 = F_133 ( V_151 , V_147 ) ;
if ( V_49 == NULL )
goto V_90;
F_134 ( & V_49 -> V_1 ) ;
V_49 -> V_50 [ V_40 ] . V_14 = * V_46 ;
V_49 -> V_50 [ V_40 ] . V_51 . V_109 = NULL ;
V_49 -> V_50 [ V_52 ] . V_14 = * V_146 ;
* ( unsigned long * ) ( & V_49 -> V_50 [ V_52 ] . V_51 . V_109 ) = V_26 ;
V_49 -> V_63 = 0 ;
F_45 ( & V_49 -> V_65 , V_8 ) ;
memset ( & V_49 -> V_152 [ 0 ] , 0 ,
F_135 ( struct V_48 , V_153 ) -
F_135 ( struct V_48 , V_152 [ 0 ] ) ) ;
F_46 ( V_49 , V_60 ) ;
F_47 ( & V_49 -> V_66 . V_67 , 0 ) ;
return V_49 ;
V_90:
F_130 ( & V_8 -> V_49 . V_148 ) ;
return F_132 ( - V_150 ) ;
}
struct V_48 * F_136 ( struct V_8 * V_8 ,
const struct V_59 * V_60 ,
const struct V_13 * V_46 ,
const struct V_13 * V_146 ,
T_5 V_147 )
{
return F_129 ( V_8 , V_60 , V_46 , V_146 , V_147 , 0 ) ;
}
void F_61 ( struct V_48 * V_49 )
{
struct V_8 * V_8 = F_37 ( V_49 ) ;
F_53 ( F_54 ( & V_49 -> V_66 . V_67 ) == 0 ) ;
F_49 ( V_49 ) ;
F_50 ( V_49 ) ;
F_137 ( V_151 , V_49 ) ;
F_138 () ;
F_130 ( & V_8 -> V_49 . V_148 ) ;
}
static struct V_80 *
F_139 ( struct V_8 * V_8 , struct V_48 * V_62 ,
const struct V_13 * V_14 ,
struct V_34 * V_35 ,
struct V_36 * V_37 ,
struct V_29 * V_30 ,
unsigned int V_32 , T_2 V_26 )
{
struct V_48 * V_49 ;
struct V_107 * V_108 ;
struct V_13 V_154 ;
struct V_155 * V_156 ;
struct V_157 * exp = NULL ;
const struct V_59 * V_60 ;
struct V_158 * V_159 ;
struct V_59 V_123 ;
unsigned int * V_160 ;
if ( ! F_29 ( & V_154 , V_14 , V_35 , V_37 ) ) {
F_31 ( L_6 ) ;
return NULL ;
}
V_60 = F_140 ( V_62 , V_30 , & V_123 ) ;
V_49 = F_129 ( V_8 , V_60 , V_14 , & V_154 , V_161 ,
V_26 ) ;
if ( F_141 ( V_49 ) )
return (struct V_80 * ) V_49 ;
if ( ! F_142 ( V_49 , V_62 ) ) {
F_61 ( V_49 ) ;
return F_132 ( - V_150 ) ;
}
V_159 = V_62 ? F_143 ( V_62 ) : NULL ;
if ( V_159 ) {
V_160 = F_144 ( V_159 ) ;
if ( F_3 ( ! V_160 ) )
V_160 = V_37 -> V_162 ( V_8 ) ;
} else {
V_160 = V_37 -> V_162 ( V_8 ) ;
}
if ( ! V_37 -> V_163 ( V_49 , V_30 , V_32 , V_160 ) ) {
F_61 ( V_49 ) ;
F_31 ( L_7 ) ;
return NULL ;
}
if ( V_159 )
F_145 ( V_49 , F_146 ( V_159 -> V_110 ) ,
V_161 ) ;
F_147 ( V_49 , V_161 ) ;
F_148 ( V_49 , V_161 ) ;
F_149 ( V_49 ) ;
V_156 = V_62 ? F_150 ( V_62 ) : NULL ;
F_151 ( V_49 , V_156 ? V_156 -> V_164 : 0 ,
V_156 ? V_156 -> V_165 : 0 ,
V_161 ) ;
F_58 () ;
if ( V_8 -> V_49 . V_166 ) {
F_2 ( & V_167 ) ;
exp = F_152 ( V_8 , V_60 , V_14 ) ;
if ( exp ) {
F_31 ( L_8 ,
V_49 , exp ) ;
F_153 ( V_168 , & V_49 -> V_63 ) ;
V_49 -> V_71 = exp -> V_71 ;
if ( exp -> V_115 ) {
V_108 = F_154 ( V_49 , exp -> V_115 ,
V_161 ) ;
if ( V_108 )
F_155 ( V_108 -> V_115 , exp -> V_115 ) ;
}
#ifdef F_156
V_49 -> V_169 = exp -> V_71 -> V_169 ;
#endif
#ifdef F_157
V_49 -> V_170 = exp -> V_71 -> V_170 ;
#endif
F_98 ( V_8 , V_171 ) ;
}
F_4 ( & V_167 ) ;
}
if ( ! exp )
F_158 ( V_49 , V_62 , V_161 ) ;
F_159 ( & V_49 -> V_66 ) ;
F_39 ( V_49 ) ;
F_59 () ;
if ( exp ) {
if ( exp -> V_172 )
exp -> V_172 ( V_49 , exp ) ;
F_160 ( exp ) ;
}
return & V_49 -> V_50 [ V_40 ] ;
}
static inline struct V_48 *
F_161 ( struct V_8 * V_8 , struct V_48 * V_62 ,
struct V_29 * V_30 ,
unsigned int V_32 ,
T_3 V_33 ,
T_4 V_25 ,
struct V_34 * V_35 ,
struct V_36 * V_37 ,
int * V_173 ,
enum V_94 * V_95 )
{
const struct V_59 * V_60 ;
struct V_13 V_14 ;
struct V_80 * V_81 ;
struct V_59 V_123 ;
struct V_48 * V_49 ;
T_2 V_26 ;
if ( ! F_23 ( V_30 , F_162 ( V_30 ) ,
V_32 , V_33 , V_25 , V_8 , & V_14 , V_35 ,
V_37 ) ) {
F_31 ( L_9 ) ;
return NULL ;
}
V_60 = F_140 ( V_62 , V_30 , & V_123 ) ;
V_26 = F_15 ( & V_14 , V_8 ) ;
V_81 = F_90 ( V_8 , V_60 , & V_14 , V_26 ) ;
if ( ! V_81 ) {
V_81 = F_139 ( V_8 , V_62 , & V_14 , V_35 , V_37 ,
V_30 , V_32 , V_26 ) ;
if ( ! V_81 )
return NULL ;
if ( F_141 ( V_81 ) )
return ( void * ) V_81 ;
}
V_49 = F_73 ( V_81 ) ;
if ( F_76 ( V_81 ) == V_52 ) {
* V_95 = V_174 ;
* V_173 = 1 ;
} else {
if ( F_119 ( V_175 , & V_49 -> V_63 ) ) {
F_31 ( L_10 , V_49 ) ;
* V_95 = V_176 ;
} else if ( F_119 ( V_168 , & V_49 -> V_63 ) ) {
F_31 ( L_11 , V_49 ) ;
* V_95 = V_177 ;
} else {
F_31 ( L_12 , V_49 ) ;
* V_95 = V_178 ;
}
* V_173 = 0 ;
}
V_30 -> V_69 = & V_49 -> V_66 ;
V_30 -> V_179 = * V_95 ;
return V_49 ;
}
unsigned int
F_163 ( struct V_8 * V_8 , T_4 V_180 , unsigned int V_181 ,
struct V_29 * V_30 )
{
struct V_48 * V_49 , * V_62 = NULL ;
enum V_94 V_95 ;
struct V_34 * V_35 ;
struct V_36 * V_37 ;
unsigned int * V_160 ;
unsigned int V_32 ;
T_4 V_25 ;
int V_173 = 0 ;
int V_42 ;
if ( V_30 -> V_69 ) {
V_62 = (struct V_48 * ) V_30 -> V_69 ;
if ( ! F_55 ( V_62 ) ) {
F_89 ( V_8 , V_182 ) ;
return V_44 ;
}
V_30 -> V_69 = NULL ;
}
V_35 = F_26 ( V_180 ) ;
V_42 = V_35 -> V_43 ( V_30 , F_162 ( V_30 ) ,
& V_32 , & V_25 ) ;
if ( V_42 <= 0 ) {
F_31 ( L_13 ) ;
F_89 ( V_8 , error ) ;
F_89 ( V_8 , V_183 ) ;
V_42 = - V_42 ;
goto V_90;
}
V_37 = F_28 ( V_180 , V_25 ) ;
if ( V_37 -> error != NULL ) {
V_42 = V_37 -> error ( V_8 , V_62 , V_30 , V_32 , & V_95 ,
V_180 , V_181 ) ;
if ( V_42 <= 0 ) {
F_89 ( V_8 , error ) ;
F_89 ( V_8 , V_183 ) ;
V_42 = - V_42 ;
goto V_90;
}
if ( V_30 -> V_69 )
goto V_90;
}
V_49 = F_161 ( V_8 , V_62 , V_30 , V_32 , V_180 , V_25 ,
V_35 , V_37 , & V_173 , & V_95 ) ;
if ( ! V_49 ) {
F_89 ( V_8 , V_183 ) ;
V_42 = V_44 ;
goto V_90;
}
if ( F_141 ( V_49 ) ) {
F_89 ( V_8 , V_105 ) ;
V_42 = V_106 ;
goto V_90;
}
F_53 ( V_30 -> V_69 ) ;
V_160 = F_164 ( V_8 , V_49 , V_37 ) ;
V_42 = V_37 -> V_184 ( V_49 , V_30 , V_32 , V_95 , V_180 , V_181 , V_160 ) ;
if ( V_42 <= 0 ) {
F_31 ( L_14 ) ;
F_108 ( V_30 -> V_69 ) ;
V_30 -> V_69 = NULL ;
F_89 ( V_8 , V_183 ) ;
if ( V_42 == - V_106 )
F_89 ( V_8 , V_105 ) ;
V_42 = - V_42 ;
goto V_90;
}
if ( V_173 && ! F_66 ( V_175 , & V_49 -> V_63 ) )
F_115 ( V_185 , V_49 ) ;
V_90:
if ( V_62 ) {
if ( V_42 == V_186 )
V_30 -> V_69 = (struct V_68 * ) V_62 ;
else
F_60 ( V_62 ) ;
}
return V_42 ;
}
bool F_165 ( struct V_13 * V_45 ,
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
void F_166 ( struct V_48 * V_49 ,
const struct V_13 * V_187 )
{
struct V_107 * V_108 = F_114 ( V_49 ) ;
F_53 ( ! F_77 ( V_49 ) ) ;
F_31 ( L_15 , V_49 ) ;
F_167 ( V_187 ) ;
V_49 -> V_50 [ V_52 ] . V_14 = * V_187 ;
if ( V_49 -> V_71 || ( V_108 && ! F_168 ( & V_108 -> V_188 ) ) )
return;
F_25 () ;
F_158 ( V_49 , NULL , V_161 ) ;
F_27 () ;
}
void F_169 ( struct V_48 * V_49 ,
enum V_94 V_95 ,
const struct V_29 * V_30 ,
unsigned long V_189 ,
int V_190 )
{
F_53 ( V_30 ) ;
if ( F_119 ( V_191 , & V_49 -> V_63 ) )
goto V_98;
if ( F_77 ( V_49 ) )
V_189 += V_111 ;
V_49 -> V_110 = V_189 ;
V_98:
if ( V_190 )
F_99 ( V_49 , V_95 , V_30 -> V_96 ) ;
}
bool F_170 ( struct V_48 * V_49 ,
enum V_94 V_95 ,
const struct V_29 * V_30 )
{
F_99 ( V_49 , V_95 , V_30 -> V_96 ) ;
return F_65 ( V_49 , 0 , 0 ) ;
}
int F_171 ( struct V_29 * V_30 ,
const struct V_13 * V_14 )
{
if ( F_172 ( V_30 , V_192 , V_14 -> V_18 . V_23 . V_193 . V_194 ) ||
F_172 ( V_30 , V_195 , V_14 -> V_19 . V_23 . V_193 . V_194 ) )
goto V_196;
return 0 ;
V_196:
return - 1 ;
}
int F_173 ( struct V_197 * V_198 [] ,
struct V_13 * V_199 )
{
if ( ! V_198 [ V_192 ] || ! V_198 [ V_195 ] )
return - V_200 ;
V_199 -> V_18 . V_23 . V_193 . V_194 = F_174 ( V_198 [ V_192 ] ) ;
V_199 -> V_19 . V_23 . V_193 . V_194 = F_174 ( V_198 [ V_195 ] ) ;
return 0 ;
}
int F_175 ( void )
{
return F_176 ( V_201 , V_202 + 1 ) ;
}
static void F_177 ( struct V_29 * V_203 , const struct V_29 * V_30 )
{
struct V_48 * V_49 ;
enum V_94 V_95 ;
V_49 = F_110 ( V_30 , & V_95 ) ;
if ( F_102 ( V_95 ) == V_40 )
V_95 = V_204 ;
else
V_95 = V_177 ;
V_203 -> V_69 = & V_49 -> V_66 ;
V_203 -> V_179 = V_95 ;
F_159 ( V_203 -> V_69 ) ;
}
static struct V_48 *
F_178 ( struct V_8 * V_8 , int (* F_179)( struct V_48 * V_12 , void * V_205 ) ,
void * V_205 , unsigned int * V_85 )
{
struct V_80 * V_81 ;
struct V_48 * V_49 ;
struct V_84 * V_15 ;
int V_55 ;
T_1 * V_206 ;
for (; * V_85 < V_27 ; ( * V_85 ) ++ ) {
V_206 = & V_7 [ * V_85 % V_6 ] ;
F_58 () ;
F_1 ( V_206 ) ;
if ( * V_85 < V_27 ) {
F_96 (h, n, &nf_conntrack_hash[*bucket], hnnode) {
if ( F_76 ( V_81 ) != V_40 )
continue;
V_49 = F_73 ( V_81 ) ;
if ( F_78 ( F_37 ( V_49 ) , V_8 ) &&
F_179 ( V_49 , V_205 ) )
goto V_120;
}
}
F_4 ( V_206 ) ;
F_59 () ;
F_180 () ;
}
F_181 (cpu) {
struct V_53 * V_54 = F_36 ( V_8 -> V_49 . V_56 , V_55 ) ;
F_182 ( & V_54 -> V_1 ) ;
F_96 (h, n, &pcpu->unconfirmed, hnnode) {
V_49 = F_73 ( V_81 ) ;
if ( F_179 ( V_49 , V_205 ) )
F_183 ( V_77 , & V_49 -> V_63 ) ;
}
F_184 ( & V_54 -> V_1 ) ;
F_180 () ;
}
return NULL ;
V_120:
F_111 ( & V_49 -> V_66 . V_67 ) ;
F_4 ( V_206 ) ;
F_59 () ;
return V_49 ;
}
void F_185 ( struct V_8 * V_8 ,
int (* F_179)( struct V_48 * V_12 , void * V_205 ) ,
void * V_205 , T_2 V_73 , int V_74 )
{
struct V_48 * V_49 ;
unsigned int V_85 = 0 ;
F_186 () ;
if ( F_54 ( & V_8 -> V_49 . V_148 ) == 0 )
return;
while ( ( V_49 = F_178 ( V_8 , F_179 , V_205 , & V_85 ) ) != NULL ) {
F_65 ( V_49 , V_73 , V_74 ) ;
F_60 ( V_49 ) ;
F_180 () ;
}
}
static int F_187 ( struct V_48 * V_12 , void * V_205 )
{
return 1 ;
}
void F_188 ( void * V_26 , unsigned int V_28 )
{
if ( F_189 ( V_26 ) )
F_190 ( V_26 ) ;
else
F_191 ( ( unsigned long ) V_26 ,
F_192 ( sizeof( struct V_207 ) * V_28 ) ) ;
}
static int F_193 ( void )
{
int V_208 = 0 , V_55 ;
F_181 (cpu) {
struct V_48 * V_49 = & F_194 ( V_209 , V_55 ) ;
V_208 += F_54 ( & V_49 -> V_66 . V_67 ) - 1 ;
}
return V_208 ;
}
void F_195 ( void )
{
V_132 . V_142 = true ;
F_196 ( V_210 , NULL ) ;
}
void F_197 ( void )
{
F_196 ( V_211 , NULL ) ;
while ( F_193 () > 0 )
F_198 () ;
F_199 ( & V_132 . V_137 ) ;
F_188 ( V_89 , V_27 ) ;
F_200 () ;
F_201 () ;
F_202 () ;
F_203 () ;
F_204 () ;
F_205 () ;
F_206 () ;
F_207 () ;
F_208 () ;
F_209 ( V_151 ) ;
}
void F_210 ( struct V_8 * V_8 )
{
F_211 ( V_212 ) ;
F_212 ( & V_8 -> V_213 , & V_212 ) ;
F_213 ( & V_212 ) ;
}
void F_213 ( struct V_214 * V_215 )
{
int V_216 ;
struct V_8 * V_8 ;
F_214 () ;
V_217:
V_216 = 0 ;
F_215 (net, net_exit_list, exit_list) {
F_185 ( V_8 , F_187 , NULL , 0 , 0 ) ;
if ( F_54 ( & V_8 -> V_49 . V_148 ) != 0 )
V_216 = 1 ;
}
if ( V_216 ) {
F_198 () ;
goto V_217;
}
F_215 (net, net_exit_list, exit_list) {
F_216 ( V_8 ) ;
F_217 ( V_8 ) ;
F_218 ( V_8 ) ;
F_219 ( V_8 ) ;
F_220 ( V_8 ) ;
F_221 ( V_8 ) ;
F_222 ( V_8 -> V_49 . V_218 ) ;
F_222 ( V_8 -> V_49 . V_56 ) ;
}
}
void * F_223 ( unsigned int * V_219 , int V_220 )
{
struct V_82 * V_26 ;
unsigned int V_221 , V_12 ;
T_7 V_222 ;
if ( * V_219 > ( V_223 / sizeof( struct V_82 ) ) )
return NULL ;
F_224 ( sizeof( struct V_82 ) != sizeof( struct V_207 ) ) ;
V_221 = * V_219 = F_225 ( * V_219 , V_224 / sizeof( struct V_82 ) ) ;
if ( V_221 > ( V_223 / sizeof( struct V_82 ) ) )
return NULL ;
V_222 = V_221 * sizeof( struct V_82 ) ;
V_26 = ( void * ) F_226 ( V_225 | V_226 | V_227 ,
F_192 ( V_222 ) ) ;
if ( ! V_26 )
V_26 = F_227 ( V_222 ) ;
if ( V_26 && V_220 )
for ( V_12 = 0 ; V_12 < V_221 ; V_12 ++ )
F_228 ( & V_26 [ V_12 ] , V_12 ) ;
return V_26 ;
}
int F_229 ( unsigned int V_228 )
{
int V_12 , V_85 ;
unsigned int V_229 ;
struct V_82 * V_26 , * V_230 ;
struct V_80 * V_81 ;
struct V_48 * V_49 ;
if ( ! V_228 )
return - V_200 ;
V_26 = F_223 ( & V_228 , 1 ) ;
if ( ! V_26 )
return - V_150 ;
V_229 = V_27 ;
if ( V_229 == V_228 ) {
F_188 ( V_26 , V_228 ) ;
return 0 ;
}
F_58 () ;
F_11 () ;
F_230 ( & V_11 ) ;
for ( V_12 = 0 ; V_12 < V_27 ; V_12 ++ ) {
while ( ! F_231 ( & V_89 [ V_12 ] ) ) {
V_81 = F_232 ( V_89 [ V_12 ] . V_231 ,
struct V_80 , V_51 ) ;
V_49 = F_73 ( V_81 ) ;
F_32 ( & V_81 -> V_51 ) ;
V_85 = F_21 ( F_37 ( V_49 ) ,
& V_81 -> V_14 , V_228 ) ;
F_93 ( & V_81 -> V_51 , & V_26 [ V_85 ] ) ;
}
}
V_229 = V_27 ;
V_230 = V_89 ;
V_89 = V_26 ;
V_27 = V_228 ;
F_233 ( & V_11 ) ;
F_13 () ;
F_59 () ;
F_214 () ;
F_188 ( V_230 , V_229 ) ;
return 0 ;
}
int F_234 ( const char * V_232 , struct V_233 * V_234 )
{
unsigned int V_228 ;
int V_235 ;
if ( V_236 -> V_237 -> V_238 != & V_239 )
return - V_240 ;
if ( ! V_27 )
return F_235 ( V_232 , V_234 ) ;
V_235 = F_236 ( V_232 , 0 , & V_228 ) ;
if ( V_235 )
return V_235 ;
return F_229 ( V_228 ) ;
}
void F_237 ( unsigned long V_241 )
{
int V_55 ;
F_181 (cpu)
F_194 ( V_209 , V_55 ) . V_63 |= V_241 ;
}
int F_238 ( void )
{
int V_242 = 8 ;
int V_42 = - V_150 ;
int V_12 , V_55 ;
F_239 ( & V_11 ) ;
for ( V_12 = 0 ; V_12 < V_6 ; V_12 ++ )
F_134 ( & V_7 [ V_12 ] ) ;
if ( ! V_27 ) {
V_27
= ( ( ( V_243 << V_244 ) / 16384 )
/ sizeof( struct V_207 ) ) ;
if ( V_243 > ( 4 * ( 1024 * 1024 * 1024 / V_224 ) ) )
V_27 = 65536 ;
else if ( V_243 > ( 1024 * 1024 * 1024 / V_224 ) )
V_27 = 16384 ;
if ( V_27 < 32 )
V_27 = 32 ;
V_242 = 4 ;
}
V_89 = F_223 ( & V_27 , 1 ) ;
if ( ! V_89 )
return - V_150 ;
V_149 = V_242 * V_27 ;
V_151 = F_240 ( L_16 ,
sizeof( struct V_48 ) , 0 ,
V_245 | V_246 , NULL ) ;
if ( ! V_151 )
goto V_247;
F_241 ( V_248 L_17 ,
V_249 , V_27 ,
V_149 ) ;
V_42 = F_242 () ;
if ( V_42 < 0 )
goto V_250;
V_42 = F_243 () ;
if ( V_42 < 0 )
goto V_251;
V_42 = F_244 () ;
if ( V_42 < 0 )
goto V_252;
V_42 = F_245 () ;
if ( V_42 < 0 )
goto V_253;
V_42 = F_246 () ;
if ( V_42 < 0 )
goto V_254;
V_42 = F_247 () ;
if ( V_42 < 0 )
goto V_255;
V_42 = F_248 () ;
if ( V_42 < 0 )
goto V_256;
V_42 = F_249 () ;
if ( V_42 < 0 )
goto V_257;
V_42 = F_250 () ;
if ( V_42 < 0 )
goto V_258;
F_181 (cpu) {
struct V_48 * V_49 = & F_194 ( V_209 , V_55 ) ;
F_45 ( & V_49 -> V_65 , & V_239 ) ;
F_47 ( & V_49 -> V_66 . V_67 , 1 ) ;
}
F_237 ( V_112 | V_259 ) ;
F_127 ( & V_132 ) ;
F_126 ( V_145 , & V_132 . V_137 , V_144 ) ;
return 0 ;
V_258:
F_201 () ;
V_257:
F_202 () ;
V_256:
F_203 () ;
V_255:
F_204 () ;
V_254:
F_205 () ;
V_253:
F_206 () ;
V_252:
F_207 () ;
V_251:
F_208 () ;
V_250:
F_209 ( V_151 ) ;
V_247:
F_188 ( V_89 , V_27 ) ;
return V_42 ;
}
void F_251 ( void )
{
F_196 ( V_210 , F_177 ) ;
F_196 ( V_211 , F_52 ) ;
}
int F_252 ( struct V_8 * V_8 )
{
int V_42 = - V_150 ;
int V_55 ;
F_47 ( & V_8 -> V_49 . V_148 , 0 ) ;
V_8 -> V_49 . V_56 = F_253 ( struct V_53 ) ;
if ( ! V_8 -> V_49 . V_56 )
goto V_260;
F_181 (cpu) {
struct V_53 * V_54 = F_36 ( V_8 -> V_49 . V_56 , V_55 ) ;
F_134 ( & V_54 -> V_1 ) ;
F_228 ( & V_54 -> V_58 , V_261 ) ;
F_228 ( & V_54 -> V_57 , V_262 ) ;
}
V_8 -> V_49 . V_218 = F_253 ( struct V_263 ) ;
if ( ! V_8 -> V_49 . V_218 )
goto V_264;
V_42 = F_254 ( V_8 ) ;
if ( V_42 < 0 )
goto V_250;
V_42 = F_255 ( V_8 ) ;
if ( V_42 < 0 )
goto V_251;
V_42 = F_256 ( V_8 ) ;
if ( V_42 < 0 )
goto V_252;
V_42 = F_257 ( V_8 ) ;
if ( V_42 < 0 )
goto V_253;
V_42 = F_258 ( V_8 ) ;
if ( V_42 < 0 )
goto V_255;
V_42 = F_259 ( V_8 ) ;
if ( V_42 < 0 )
goto V_258;
return 0 ;
V_258:
F_217 ( V_8 ) ;
V_255:
F_218 ( V_8 ) ;
V_253:
F_219 ( V_8 ) ;
V_252:
F_220 ( V_8 ) ;
V_251:
F_221 ( V_8 ) ;
V_250:
F_222 ( V_8 -> V_49 . V_218 ) ;
V_264:
F_222 ( V_8 -> V_49 . V_56 ) ;
V_260:
return V_42 ;
}
