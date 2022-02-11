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
struct V_48 * V_62 , * V_63 ;
if ( V_64 <= V_65 ) {
V_62 = F_44 ( sizeof( * V_62 ) + V_65 , V_61 ) ;
if ( ! V_62 )
return NULL ;
V_63 = V_62 ;
V_62 = (struct V_48 * ) F_45 ( ( unsigned long ) V_63 ) ;
if ( V_62 != V_63 ) {
V_62 = (struct V_48 * ) F_45 ( ( unsigned long ) V_63 ) ;
V_62 -> V_66 . V_67 = ( char * ) V_62 - ( char * ) V_63 ;
}
} else {
V_62 = F_44 ( sizeof( * V_62 ) , V_61 ) ;
if ( ! V_62 )
return NULL ;
}
V_62 -> V_68 = V_69 ;
F_46 ( & V_62 -> V_70 , V_8 ) ;
F_47 ( V_62 , V_60 ) ;
F_48 ( & V_62 -> V_71 . V_72 , 0 ) ;
return V_62 ;
}
void F_49 ( struct V_48 * V_62 )
{
F_50 ( V_62 ) ;
F_51 ( V_62 ) ;
if ( V_64 <= V_65 )
F_52 ( ( char * ) V_62 - V_62 -> V_66 . V_67 ) ;
else
F_52 ( V_62 ) ;
}
static void
F_53 ( struct V_73 * V_74 )
{
struct V_48 * V_49 = (struct V_48 * ) V_74 ;
struct V_36 * V_37 ;
F_31 ( L_2 , V_49 ) ;
F_54 ( F_55 ( & V_74 -> V_72 ) == 0 ) ;
if ( F_3 ( F_56 ( V_49 ) ) ) {
F_49 ( V_49 ) ;
return;
}
F_25 () ;
V_37 = F_28 ( F_57 ( V_49 ) , F_58 ( V_49 ) ) ;
if ( V_37 -> V_75 )
V_37 -> V_75 ( V_49 ) ;
F_27 () ;
F_59 () ;
F_33 ( V_49 ) ;
F_40 ( V_49 ) ;
F_60 () ;
if ( V_49 -> V_76 )
F_61 ( V_49 -> V_76 ) ;
F_31 ( L_3 , V_49 ) ;
F_62 ( V_49 ) ;
}
static void F_63 ( struct V_48 * V_49 )
{
struct V_8 * V_8 = F_37 ( V_49 ) ;
unsigned int V_26 , V_77 ;
unsigned int V_9 ;
F_64 ( V_49 ) ;
F_59 () ;
do {
V_9 = F_65 ( & V_11 ) ;
V_26 = F_22 ( V_8 ,
& V_49 -> V_50 [ V_40 ] . V_14 ) ;
V_77 = F_22 ( V_8 ,
& V_49 -> V_50 [ V_52 ] . V_14 ) ;
} while ( F_8 ( V_8 , V_26 , V_77 , V_9 ) );
F_30 ( V_49 ) ;
F_7 ( V_26 , V_77 ) ;
F_34 ( V_49 ) ;
F_60 () ;
}
bool F_66 ( struct V_48 * V_49 , T_2 V_78 , int V_79 )
{
struct V_80 * V_81 ;
if ( F_67 ( V_82 , & V_49 -> V_68 ) )
return false ;
V_81 = F_68 ( V_49 ) ;
if ( V_81 && V_81 -> V_83 == 0 )
V_81 -> V_83 = F_69 () ;
if ( F_70 ( V_84 , V_49 ,
V_78 , V_79 ) < 0 ) {
F_63 ( V_49 ) ;
F_71 ( F_37 ( V_49 ) ) ;
return false ;
}
F_72 ( F_37 ( V_49 ) ) ;
F_63 ( V_49 ) ;
F_61 ( V_49 ) ;
return true ;
}
static inline bool
F_73 ( struct V_85 * V_86 ,
const struct V_13 * V_14 ,
const struct V_59 * V_60 ,
const struct V_8 * V_8 )
{
struct V_48 * V_49 = F_74 ( V_86 ) ;
return F_75 ( V_14 , & V_86 -> V_14 ) &&
F_76 ( V_49 , V_60 , F_77 ( V_86 ) ) &&
F_78 ( V_49 ) &&
F_79 ( V_8 , F_37 ( V_49 ) ) ;
}
static void F_80 ( struct V_48 * V_49 )
{
if ( ! F_81 ( & V_49 -> V_71 . V_72 ) )
return;
if ( F_82 ( V_49 ) )
F_83 ( V_49 ) ;
F_61 ( V_49 ) ;
}
static struct V_85 *
F_84 ( struct V_8 * V_8 , const struct V_59 * V_60 ,
const struct V_13 * V_14 , T_2 V_26 )
{
struct V_85 * V_86 ;
struct V_87 * V_88 ;
struct V_89 * V_15 ;
unsigned int V_90 , V_91 ;
V_92:
F_85 ( & V_88 , & V_91 ) ;
V_90 = F_20 ( V_26 , V_91 ) ;
F_86 (h, n, &ct_hash[bucket], hnnode) {
struct V_48 * V_49 ;
V_49 = F_74 ( V_86 ) ;
if ( F_87 ( V_49 ) ) {
F_80 ( V_49 ) ;
continue;
}
if ( F_88 ( V_49 ) )
continue;
if ( F_73 ( V_86 , V_14 , V_60 , V_8 ) )
return V_86 ;
}
if ( F_89 ( V_15 ) != V_90 ) {
F_90 ( V_8 , V_93 ) ;
goto V_92;
}
return NULL ;
}
static struct V_85 *
F_91 ( struct V_8 * V_8 , const struct V_59 * V_60 ,
const struct V_13 * V_14 , T_2 V_26 )
{
struct V_85 * V_86 ;
struct V_48 * V_49 ;
F_25 () ;
V_92:
V_86 = F_84 ( V_8 , V_60 , V_14 , V_26 ) ;
if ( V_86 ) {
V_49 = F_74 ( V_86 ) ;
if ( F_3 ( F_88 ( V_49 ) ||
! F_81 ( & V_49 -> V_71 . V_72 ) ) )
V_86 = NULL ;
else {
if ( F_3 ( ! F_73 ( V_86 , V_14 , V_60 , V_8 ) ) ) {
F_61 ( V_49 ) ;
goto V_92;
}
}
}
F_27 () ;
return V_86 ;
}
struct V_85 *
F_92 ( struct V_8 * V_8 , const struct V_59 * V_60 ,
const struct V_13 * V_14 )
{
return F_91 ( V_8 , V_60 , V_14 ,
F_15 ( V_14 , V_8 ) ) ;
}
static void F_93 ( struct V_48 * V_49 ,
unsigned int V_26 ,
unsigned int V_77 )
{
F_94 ( & V_49 -> V_50 [ V_40 ] . V_51 ,
& V_94 [ V_26 ] ) ;
F_94 ( & V_49 -> V_50 [ V_52 ] . V_51 ,
& V_94 [ V_77 ] ) ;
}
int
F_95 ( struct V_48 * V_49 )
{
const struct V_59 * V_60 ;
struct V_8 * V_8 = F_37 ( V_49 ) ;
unsigned int V_26 , V_77 ;
struct V_85 * V_86 ;
struct V_89 * V_15 ;
unsigned int V_9 ;
V_60 = F_96 ( V_49 ) ;
F_59 () ;
do {
V_9 = F_65 ( & V_11 ) ;
V_26 = F_22 ( V_8 ,
& V_49 -> V_50 [ V_40 ] . V_14 ) ;
V_77 = F_22 ( V_8 ,
& V_49 -> V_50 [ V_52 ] . V_14 ) ;
} while ( F_8 ( V_8 , V_26 , V_77 , V_9 ) );
F_97 (h, n, &nf_conntrack_hash[hash], hnnode)
if ( F_73 ( V_86 , & V_49 -> V_50 [ V_40 ] . V_14 ,
V_60 , V_8 ) )
goto V_95;
F_97 (h, n, &nf_conntrack_hash[reply_hash], hnnode)
if ( F_73 ( V_86 , & V_49 -> V_50 [ V_52 ] . V_14 ,
V_60 , V_8 ) )
goto V_95;
F_98 () ;
F_48 ( & V_49 -> V_71 . V_72 , 2 ) ;
F_93 ( V_49 , V_26 , V_77 ) ;
F_7 ( V_26 , V_77 ) ;
F_99 ( V_8 , V_96 ) ;
F_60 () ;
return 0 ;
V_95:
F_7 ( V_26 , V_77 ) ;
F_99 ( V_8 , V_97 ) ;
F_60 () ;
return - V_98 ;
}
static inline void F_100 ( struct V_48 * V_49 ,
enum V_99 V_100 ,
unsigned int V_101 )
{
struct V_102 * V_103 ;
V_103 = F_101 ( V_49 ) ;
if ( V_103 ) {
struct V_104 * V_105 = V_103 -> V_105 ;
F_102 ( & V_105 [ F_103 ( V_100 ) ] . V_106 ) ;
F_104 ( V_101 , & V_105 [ F_103 ( V_100 ) ] . V_107 ) ;
}
}
static void F_105 ( struct V_48 * V_49 , enum V_99 V_100 ,
const struct V_48 * V_108 )
{
struct V_102 * V_103 ;
V_103 = F_101 ( V_108 ) ;
if ( V_103 ) {
struct V_104 * V_105 = V_103 -> V_105 ;
unsigned int V_107 ;
V_107 = F_106 ( & V_105 [ F_103 ( V_100 ) ] . V_107 ) ;
F_100 ( V_49 , V_100 , V_107 ) ;
}
}
static int F_107 ( struct V_8 * V_8 , struct V_29 * V_30 ,
enum V_99 V_100 ,
struct V_85 * V_86 )
{
struct V_48 * V_49 = F_74 ( V_86 ) ;
struct V_36 * V_37 ;
V_37 = F_28 ( F_57 ( V_49 ) , F_58 ( V_49 ) ) ;
if ( V_37 -> V_109 &&
! F_108 ( V_49 ) &&
! F_88 ( V_49 ) &&
F_81 ( & V_49 -> V_71 . V_72 ) ) {
enum V_99 V_110 ;
struct V_48 * V_108 = F_109 ( V_30 , & V_110 ) ;
F_105 ( V_49 , V_100 , V_108 ) ;
F_110 ( & V_108 -> V_71 ) ;
F_111 ( V_30 , V_49 , V_110 ) ;
return V_44 ;
}
F_99 ( V_8 , V_111 ) ;
return V_112 ;
}
int
F_112 ( struct V_29 * V_30 )
{
const struct V_59 * V_60 ;
unsigned int V_26 , V_77 ;
struct V_85 * V_86 ;
struct V_48 * V_49 ;
struct V_113 * V_114 ;
struct V_80 * V_81 ;
struct V_89 * V_15 ;
enum V_99 V_100 ;
struct V_8 * V_8 ;
unsigned int V_9 ;
int V_42 = V_112 ;
V_49 = F_109 ( V_30 , & V_100 ) ;
V_8 = F_37 ( V_49 ) ;
if ( F_103 ( V_100 ) != V_40 )
return V_44 ;
V_60 = F_96 ( V_49 ) ;
F_59 () ;
do {
V_9 = F_65 ( & V_11 ) ;
V_26 = * ( unsigned long * ) & V_49 -> V_50 [ V_52 ] . V_51 . V_115 ;
V_26 = F_19 ( V_26 ) ;
V_77 = F_22 ( V_8 ,
& V_49 -> V_50 [ V_52 ] . V_14 ) ;
} while ( F_8 ( V_8 , V_26 , V_77 , V_9 ) );
F_54 ( ! F_78 ( V_49 ) ) ;
F_31 ( L_4 , V_49 ) ;
F_40 ( V_49 ) ;
if ( F_3 ( F_88 ( V_49 ) ) ) {
F_34 ( V_49 ) ;
goto V_57;
}
F_97 (h, n, &nf_conntrack_hash[hash], hnnode)
if ( F_73 ( V_86 , & V_49 -> V_50 [ V_40 ] . V_14 ,
V_60 , V_8 ) )
goto V_95;
F_97 (h, n, &nf_conntrack_hash[reply_hash], hnnode)
if ( F_73 ( V_86 , & V_49 -> V_50 [ V_52 ] . V_14 ,
V_60 , V_8 ) )
goto V_95;
V_49 -> V_116 += V_117 ;
F_113 ( & V_49 -> V_71 . V_72 ) ;
V_49 -> V_68 |= V_118 ;
V_81 = F_68 ( V_49 ) ;
if ( V_81 ) {
if ( V_30 -> V_81 == 0 )
F_114 ( V_30 ) ;
V_81 -> V_119 = F_115 ( V_30 -> V_81 ) ;
}
F_93 ( V_49 , V_26 , V_77 ) ;
F_7 ( V_26 , V_77 ) ;
F_60 () ;
V_114 = F_116 ( V_49 ) ;
if ( V_114 && V_114 -> V_120 )
F_117 ( V_121 , V_49 ) ;
F_117 ( F_118 ( V_49 ) ?
V_122 : V_123 , V_49 ) ;
return V_44 ;
V_95:
F_34 ( V_49 ) ;
V_42 = F_107 ( V_8 , V_30 , V_100 , V_86 ) ;
V_57:
F_7 ( V_26 , V_77 ) ;
F_99 ( V_8 , V_97 ) ;
F_60 () ;
return V_42 ;
}
int
F_119 ( const struct V_13 * V_14 ,
const struct V_48 * V_124 )
{
struct V_8 * V_8 = F_37 ( V_124 ) ;
const struct V_59 * V_60 ;
struct V_85 * V_86 ;
struct V_87 * V_88 ;
unsigned int V_26 , V_91 ;
struct V_89 * V_15 ;
struct V_48 * V_49 ;
V_60 = F_96 ( V_124 ) ;
F_25 () ;
V_92:
F_85 ( & V_88 , & V_91 ) ;
V_26 = F_21 ( V_8 , V_14 , V_91 ) ;
F_86 (h, n, &ct_hash[hash], hnnode) {
V_49 = F_74 ( V_86 ) ;
if ( V_49 == V_124 )
continue;
if ( F_87 ( V_49 ) ) {
F_80 ( V_49 ) ;
continue;
}
if ( F_73 ( V_86 , V_14 , V_60 , V_8 ) ) {
F_90 ( V_8 , V_125 ) ;
F_27 () ;
return 1 ;
}
}
if ( F_89 ( V_15 ) != V_26 ) {
F_90 ( V_8 , V_93 ) ;
goto V_92;
}
F_27 () ;
return 0 ;
}
static unsigned int F_120 ( struct V_8 * V_8 ,
struct V_87 * V_126 )
{
struct V_85 * V_86 ;
struct V_89 * V_15 ;
unsigned int V_127 = 0 ;
struct V_48 * V_128 ;
F_86 (h, n, head, hnnode) {
V_128 = F_74 ( V_86 ) ;
if ( F_87 ( V_128 ) ) {
F_80 ( V_128 ) ;
continue;
}
if ( F_121 ( V_129 , & V_128 -> V_68 ) ||
! F_79 ( F_37 ( V_128 ) , V_8 ) ||
F_88 ( V_128 ) )
continue;
if ( ! F_81 ( & V_128 -> V_71 . V_72 ) )
continue;
if ( F_79 ( F_37 ( V_128 ) , V_8 ) &&
F_78 ( V_128 ) &&
F_66 ( V_128 , 0 , 0 ) )
V_127 ++ ;
F_61 ( V_128 ) ;
}
return V_127 ;
}
static T_6 int F_122 ( struct V_8 * V_8 , unsigned int V_130 )
{
unsigned int V_12 ;
for ( V_12 = 0 ; V_12 < V_131 ; V_12 ++ ) {
struct V_87 * V_88 ;
unsigned int V_26 , V_91 , V_127 ;
F_25 () ;
F_85 ( & V_88 , & V_91 ) ;
V_26 = F_20 ( V_130 ++ , V_91 ) ;
V_127 = F_120 ( V_8 , & V_88 [ V_26 ] ) ;
F_27 () ;
if ( V_127 ) {
F_123 ( V_8 , F_122 , V_127 ) ;
return true ;
}
}
return false ;
}
static void F_124 ( struct V_132 * V_133 )
{
unsigned int V_134 = F_125 ( V_135 / V_136 , 1u ) ;
unsigned int V_12 , V_137 , V_138 = 0 , V_139 = 0 ;
struct V_140 * V_141 ;
unsigned int V_142 , V_143 = 0 ;
unsigned long V_144 ;
V_141 = F_126 ( V_133 , struct V_140 , V_145 . V_133 ) ;
V_137 = V_27 / V_136 ;
V_12 = V_141 -> V_146 ;
do {
struct V_85 * V_86 ;
struct V_87 * V_88 ;
struct V_89 * V_15 ;
unsigned int V_147 ;
struct V_48 * V_128 ;
V_12 ++ ;
F_25 () ;
F_85 ( & V_88 , & V_147 ) ;
if ( V_12 >= V_147 )
V_12 = 0 ;
F_86 (h, n, &ct_hash[i], hnnode) {
V_128 = F_74 ( V_86 ) ;
V_143 ++ ;
if ( F_87 ( V_128 ) ) {
F_80 ( V_128 ) ;
V_139 ++ ;
continue;
}
}
F_27 () ;
F_127 () ;
} while ( ++ V_138 < V_137 );
if ( V_141 -> V_148 )
return;
V_142 = V_143 ? V_139 * 100 / V_143 : 0 ;
if ( V_142 > V_149 ) {
V_141 -> V_150 = V_134 ;
} else {
unsigned int F_125 = V_151 / V_136 ;
F_128 ( ( V_151 / V_136 ) == 0 ) ;
V_141 -> V_150 += V_134 ;
if ( V_141 -> V_150 > F_125 )
V_141 -> V_150 = F_125 ;
}
V_144 = V_141 -> V_150 ;
V_141 -> V_146 = V_12 ;
F_129 ( V_152 , & V_141 -> V_145 , V_144 ) ;
}
static void F_130 ( struct V_140 * V_141 )
{
F_131 ( & V_141 -> V_145 , F_124 ) ;
V_141 -> V_150 = V_135 ;
V_141 -> V_148 = false ;
}
static struct V_48 *
F_132 ( struct V_8 * V_8 ,
const struct V_59 * V_60 ,
const struct V_13 * V_46 ,
const struct V_13 * V_153 ,
T_5 V_154 , T_2 V_26 )
{
struct V_48 * V_49 ;
F_113 ( & V_8 -> V_49 . V_155 ) ;
if ( V_156 &&
F_3 ( F_55 ( & V_8 -> V_49 . V_155 ) > V_156 ) ) {
if ( ! F_122 ( V_8 , V_26 ) ) {
F_133 ( & V_8 -> V_49 . V_155 ) ;
F_134 ( L_5 ) ;
return F_135 ( - V_157 ) ;
}
}
V_49 = F_136 ( V_158 , V_154 ) ;
if ( V_49 == NULL )
goto V_95;
F_137 ( & V_49 -> V_1 ) ;
V_49 -> V_50 [ V_40 ] . V_14 = * V_46 ;
V_49 -> V_50 [ V_40 ] . V_51 . V_115 = NULL ;
V_49 -> V_50 [ V_52 ] . V_14 = * V_153 ;
* ( unsigned long * ) ( & V_49 -> V_50 [ V_52 ] . V_51 . V_115 ) = V_26 ;
V_49 -> V_68 = 0 ;
F_46 ( & V_49 -> V_70 , V_8 ) ;
memset ( & V_49 -> V_159 [ 0 ] , 0 ,
F_138 ( struct V_48 , V_66 ) -
F_138 ( struct V_48 , V_159 [ 0 ] ) ) ;
F_47 ( V_49 , V_60 ) ;
F_48 ( & V_49 -> V_71 . V_72 , 0 ) ;
return V_49 ;
V_95:
F_133 ( & V_8 -> V_49 . V_155 ) ;
return F_135 ( - V_157 ) ;
}
struct V_48 * F_139 ( struct V_8 * V_8 ,
const struct V_59 * V_60 ,
const struct V_13 * V_46 ,
const struct V_13 * V_153 ,
T_5 V_154 )
{
return F_132 ( V_8 , V_60 , V_46 , V_153 , V_154 , 0 ) ;
}
void F_62 ( struct V_48 * V_49 )
{
struct V_8 * V_8 = F_37 ( V_49 ) ;
F_54 ( F_55 ( & V_49 -> V_71 . V_72 ) == 0 ) ;
F_50 ( V_49 ) ;
F_51 ( V_49 ) ;
F_140 ( V_158 , V_49 ) ;
F_141 () ;
F_133 ( & V_8 -> V_49 . V_155 ) ;
}
static struct V_85 *
F_142 ( struct V_8 * V_8 , struct V_48 * V_62 ,
const struct V_13 * V_14 ,
struct V_34 * V_35 ,
struct V_36 * V_37 ,
struct V_29 * V_30 ,
unsigned int V_32 , T_2 V_26 )
{
struct V_48 * V_49 ;
struct V_113 * V_114 ;
struct V_13 V_160 ;
struct V_161 * V_162 ;
struct V_163 * exp = NULL ;
const struct V_59 * V_60 ;
struct V_164 * V_165 ;
struct V_59 V_128 ;
unsigned int * V_166 ;
if ( ! F_29 ( & V_160 , V_14 , V_35 , V_37 ) ) {
F_31 ( L_6 ) ;
return NULL ;
}
V_60 = F_143 ( V_62 , V_30 , & V_128 ) ;
V_49 = F_132 ( V_8 , V_60 , V_14 , & V_160 , V_167 ,
V_26 ) ;
if ( F_144 ( V_49 ) )
return (struct V_85 * ) V_49 ;
if ( ! F_145 ( V_49 , V_62 ) ) {
F_62 ( V_49 ) ;
return F_135 ( - V_157 ) ;
}
V_165 = V_62 ? F_146 ( V_62 ) : NULL ;
if ( V_165 ) {
V_166 = F_147 ( V_165 ) ;
if ( F_3 ( ! V_166 ) )
V_166 = V_37 -> V_168 ( V_8 ) ;
} else {
V_166 = V_37 -> V_168 ( V_8 ) ;
}
if ( ! V_37 -> V_169 ( V_49 , V_30 , V_32 , V_166 ) ) {
F_62 ( V_49 ) ;
F_31 ( L_7 ) ;
return NULL ;
}
if ( V_165 )
F_148 ( V_49 , F_149 ( V_165 -> V_116 ) ,
V_167 ) ;
F_150 ( V_49 , V_167 ) ;
F_151 ( V_49 , V_167 ) ;
F_152 ( V_49 ) ;
V_162 = V_62 ? F_153 ( V_62 ) : NULL ;
F_154 ( V_49 , V_162 ? V_162 -> V_170 : 0 ,
V_162 ? V_162 -> V_171 : 0 ,
V_167 ) ;
F_59 () ;
if ( V_8 -> V_49 . V_172 ) {
F_2 ( & V_173 ) ;
exp = F_155 ( V_8 , V_60 , V_14 ) ;
if ( exp ) {
F_31 ( L_8 ,
V_49 , exp ) ;
F_156 ( V_174 , & V_49 -> V_68 ) ;
V_49 -> V_76 = exp -> V_76 ;
if ( exp -> V_120 ) {
V_114 = F_157 ( V_49 , exp -> V_120 ,
V_167 ) ;
if ( V_114 )
F_158 ( V_114 -> V_120 , exp -> V_120 ) ;
}
#ifdef F_159
V_49 -> V_175 = exp -> V_76 -> V_175 ;
#endif
#ifdef F_160
V_49 -> V_176 = exp -> V_76 -> V_176 ;
#endif
F_99 ( V_8 , V_177 ) ;
}
F_4 ( & V_173 ) ;
}
if ( ! exp )
F_161 ( V_49 , V_62 , V_167 ) ;
F_162 ( & V_49 -> V_71 ) ;
F_39 ( V_49 ) ;
F_60 () ;
if ( exp ) {
if ( exp -> V_178 )
exp -> V_178 ( V_49 , exp ) ;
F_163 ( exp ) ;
}
return & V_49 -> V_50 [ V_40 ] ;
}
static inline struct V_48 *
F_164 ( struct V_8 * V_8 , struct V_48 * V_62 ,
struct V_29 * V_30 ,
unsigned int V_32 ,
T_3 V_33 ,
T_4 V_25 ,
struct V_34 * V_35 ,
struct V_36 * V_37 ,
int * V_179 ,
enum V_99 * V_100 )
{
const struct V_59 * V_60 ;
struct V_13 V_14 ;
struct V_85 * V_86 ;
struct V_59 V_128 ;
struct V_48 * V_49 ;
T_2 V_26 ;
if ( ! F_23 ( V_30 , F_165 ( V_30 ) ,
V_32 , V_33 , V_25 , V_8 , & V_14 , V_35 ,
V_37 ) ) {
F_31 ( L_9 ) ;
return NULL ;
}
V_60 = F_143 ( V_62 , V_30 , & V_128 ) ;
V_26 = F_15 ( & V_14 , V_8 ) ;
V_86 = F_91 ( V_8 , V_60 , & V_14 , V_26 ) ;
if ( ! V_86 ) {
V_86 = F_142 ( V_8 , V_62 , & V_14 , V_35 , V_37 ,
V_30 , V_32 , V_26 ) ;
if ( ! V_86 )
return NULL ;
if ( F_144 ( V_86 ) )
return ( void * ) V_86 ;
}
V_49 = F_74 ( V_86 ) ;
if ( F_77 ( V_86 ) == V_52 ) {
* V_100 = V_180 ;
* V_179 = 1 ;
} else {
if ( F_121 ( V_181 , & V_49 -> V_68 ) ) {
F_31 ( L_10 , V_49 ) ;
* V_100 = V_182 ;
} else if ( F_121 ( V_174 , & V_49 -> V_68 ) ) {
F_31 ( L_11 , V_49 ) ;
* V_100 = V_183 ;
} else {
F_31 ( L_12 , V_49 ) ;
* V_100 = V_184 ;
}
* V_179 = 0 ;
}
F_111 ( V_30 , V_49 , * V_100 ) ;
return V_49 ;
}
unsigned int
F_166 ( struct V_8 * V_8 , T_4 V_185 , unsigned int V_186 ,
struct V_29 * V_30 )
{
struct V_48 * V_49 , * V_62 ;
enum V_99 V_100 ;
struct V_34 * V_35 ;
struct V_36 * V_37 ;
unsigned int * V_166 ;
unsigned int V_32 ;
T_4 V_25 ;
int V_179 = 0 ;
int V_42 ;
V_62 = F_109 ( V_30 , & V_100 ) ;
if ( V_62 ) {
if ( ! F_56 ( V_62 ) ) {
F_90 ( V_8 , V_187 ) ;
return V_44 ;
}
V_30 -> V_188 = 0 ;
}
V_35 = F_26 ( V_185 ) ;
V_42 = V_35 -> V_43 ( V_30 , F_165 ( V_30 ) ,
& V_32 , & V_25 ) ;
if ( V_42 <= 0 ) {
F_31 ( L_13 ) ;
F_90 ( V_8 , error ) ;
F_90 ( V_8 , V_189 ) ;
V_42 = - V_42 ;
goto V_95;
}
V_37 = F_28 ( V_185 , V_25 ) ;
if ( V_37 -> error != NULL ) {
V_42 = V_37 -> error ( V_8 , V_62 , V_30 , V_32 , V_185 , V_186 ) ;
if ( V_42 <= 0 ) {
F_90 ( V_8 , error ) ;
F_90 ( V_8 , V_189 ) ;
V_42 = - V_42 ;
goto V_95;
}
if ( V_30 -> V_188 )
goto V_95;
}
V_190:
V_49 = F_164 ( V_8 , V_62 , V_30 , V_32 , V_185 , V_25 ,
V_35 , V_37 , & V_179 , & V_100 ) ;
if ( ! V_49 ) {
F_90 ( V_8 , V_189 ) ;
V_42 = V_44 ;
goto V_95;
}
if ( F_144 ( V_49 ) ) {
F_90 ( V_8 , V_111 ) ;
V_42 = V_112 ;
goto V_95;
}
F_54 ( F_167 ( V_30 ) ) ;
V_166 = F_168 ( V_8 , V_49 , V_37 ) ;
V_42 = V_37 -> V_191 ( V_49 , V_30 , V_32 , V_100 , V_185 , V_186 , V_166 ) ;
if ( V_42 <= 0 ) {
F_31 ( L_14 ) ;
F_110 ( & V_49 -> V_71 ) ;
V_30 -> V_188 = 0 ;
F_90 ( V_8 , V_189 ) ;
if ( V_42 == - V_112 )
F_90 ( V_8 , V_111 ) ;
if ( V_42 == - V_192 )
goto V_190;
V_42 = - V_42 ;
goto V_95;
}
if ( V_179 && ! F_67 ( V_181 , & V_49 -> V_68 ) )
F_117 ( V_193 , V_49 ) ;
V_95:
if ( V_62 )
F_61 ( V_62 ) ;
return V_42 ;
}
bool F_169 ( struct V_13 * V_45 ,
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
void F_170 ( struct V_48 * V_49 ,
const struct V_13 * V_194 )
{
struct V_113 * V_114 = F_116 ( V_49 ) ;
F_54 ( ! F_78 ( V_49 ) ) ;
F_31 ( L_15 , V_49 ) ;
F_171 ( V_194 ) ;
V_49 -> V_50 [ V_52 ] . V_14 = * V_194 ;
if ( V_49 -> V_76 || ( V_114 && ! F_172 ( & V_114 -> V_195 ) ) )
return;
F_25 () ;
F_161 ( V_49 , NULL , V_167 ) ;
F_27 () ;
}
void F_173 ( struct V_48 * V_49 ,
enum V_99 V_100 ,
const struct V_29 * V_30 ,
unsigned long V_196 ,
int V_197 )
{
F_54 ( V_30 ) ;
if ( F_121 ( V_198 , & V_49 -> V_68 ) )
goto V_103;
if ( F_78 ( V_49 ) )
V_196 += V_117 ;
V_49 -> V_116 = V_196 ;
V_103:
if ( V_197 )
F_100 ( V_49 , V_100 , V_30 -> V_101 ) ;
}
bool F_174 ( struct V_48 * V_49 ,
enum V_99 V_100 ,
const struct V_29 * V_30 )
{
F_100 ( V_49 , V_100 , V_30 -> V_101 ) ;
return F_66 ( V_49 , 0 , 0 ) ;
}
int F_175 ( struct V_29 * V_30 ,
const struct V_13 * V_14 )
{
if ( F_176 ( V_30 , V_199 , V_14 -> V_18 . V_23 . V_200 . V_201 ) ||
F_176 ( V_30 , V_202 , V_14 -> V_19 . V_23 . V_200 . V_201 ) )
goto V_203;
return 0 ;
V_203:
return - 1 ;
}
int F_177 ( struct V_204 * V_205 [] ,
struct V_13 * V_206 )
{
if ( ! V_205 [ V_199 ] || ! V_205 [ V_202 ] )
return - V_207 ;
V_206 -> V_18 . V_23 . V_200 . V_201 = F_178 ( V_205 [ V_199 ] ) ;
V_206 -> V_19 . V_23 . V_200 . V_201 = F_178 ( V_205 [ V_202 ] ) ;
return 0 ;
}
int F_179 ( void )
{
return F_180 ( V_208 , V_209 + 1 ) ;
}
static void F_181 ( struct V_29 * V_210 , const struct V_29 * V_30 )
{
struct V_48 * V_49 ;
enum V_99 V_100 ;
V_49 = F_109 ( V_30 , & V_100 ) ;
if ( F_103 ( V_100 ) == V_40 )
V_100 = V_211 ;
else
V_100 = V_183 ;
F_111 ( V_210 , V_49 , V_100 ) ;
F_162 ( F_167 ( V_210 ) ) ;
}
static struct V_48 *
F_182 ( struct V_8 * V_8 , int (* F_183)( struct V_48 * V_12 , void * V_212 ) ,
void * V_212 , unsigned int * V_90 )
{
struct V_85 * V_86 ;
struct V_48 * V_49 ;
struct V_89 * V_15 ;
int V_55 ;
T_1 * V_213 ;
for (; * V_90 < V_27 ; ( * V_90 ) ++ ) {
V_213 = & V_7 [ * V_90 % V_6 ] ;
F_59 () ;
F_1 ( V_213 ) ;
if ( * V_90 < V_27 ) {
F_97 (h, n, &nf_conntrack_hash[*bucket], hnnode) {
if ( F_77 ( V_86 ) != V_40 )
continue;
V_49 = F_74 ( V_86 ) ;
if ( F_79 ( F_37 ( V_49 ) , V_8 ) &&
F_183 ( V_49 , V_212 ) )
goto V_125;
}
}
F_4 ( V_213 ) ;
F_60 () ;
F_184 () ;
}
F_185 (cpu) {
struct V_53 * V_54 = F_36 ( V_8 -> V_49 . V_56 , V_55 ) ;
F_186 ( & V_54 -> V_1 ) ;
F_97 (h, n, &pcpu->unconfirmed, hnnode) {
V_49 = F_74 ( V_86 ) ;
if ( F_183 ( V_49 , V_212 ) )
F_187 ( V_82 , & V_49 -> V_68 ) ;
}
F_188 ( & V_54 -> V_1 ) ;
F_184 () ;
}
return NULL ;
V_125:
F_113 ( & V_49 -> V_71 . V_72 ) ;
F_4 ( V_213 ) ;
F_60 () ;
return V_49 ;
}
void F_189 ( struct V_8 * V_8 ,
int (* F_183)( struct V_48 * V_12 , void * V_212 ) ,
void * V_212 , T_2 V_78 , int V_79 )
{
struct V_48 * V_49 ;
unsigned int V_90 = 0 ;
F_190 () ;
if ( F_55 ( & V_8 -> V_49 . V_155 ) == 0 )
return;
while ( ( V_49 = F_182 ( V_8 , F_183 , V_212 , & V_90 ) ) != NULL ) {
F_66 ( V_49 , V_78 , V_79 ) ;
F_61 ( V_49 ) ;
F_184 () ;
}
}
static int F_191 ( struct V_48 * V_12 , void * V_212 )
{
return 1 ;
}
void F_192 ( void * V_26 , unsigned int V_28 )
{
if ( F_193 ( V_26 ) )
F_194 ( V_26 ) ;
else
F_195 ( ( unsigned long ) V_26 ,
F_196 ( sizeof( struct V_214 ) * V_28 ) ) ;
}
static int F_197 ( void )
{
int V_215 = 0 , V_55 ;
F_185 (cpu) {
struct V_48 * V_49 = & F_198 ( V_216 , V_55 ) ;
V_215 += F_55 ( & V_49 -> V_71 . V_72 ) - 1 ;
}
return V_215 ;
}
void F_199 ( void )
{
V_140 . V_148 = true ;
F_200 ( V_217 , NULL ) ;
}
void F_201 ( void )
{
F_200 ( V_218 , NULL ) ;
while ( F_197 () > 0 )
F_202 () ;
F_203 ( & V_140 . V_145 ) ;
F_192 ( V_94 , V_27 ) ;
F_204 () ;
F_205 () ;
F_206 () ;
F_207 () ;
F_208 () ;
F_209 () ;
F_210 () ;
F_211 () ;
F_212 () ;
F_213 ( V_158 ) ;
}
void F_214 ( struct V_8 * V_8 )
{
F_215 ( V_219 ) ;
F_216 ( & V_8 -> V_220 , & V_219 ) ;
F_217 ( & V_219 ) ;
}
void F_217 ( struct V_221 * V_222 )
{
int V_223 ;
struct V_8 * V_8 ;
F_218 () ;
V_224:
V_223 = 0 ;
F_219 (net, net_exit_list, exit_list) {
F_189 ( V_8 , F_191 , NULL , 0 , 0 ) ;
if ( F_55 ( & V_8 -> V_49 . V_155 ) != 0 )
V_223 = 1 ;
}
if ( V_223 ) {
F_202 () ;
goto V_224;
}
F_219 (net, net_exit_list, exit_list) {
F_220 ( V_8 ) ;
F_221 ( V_8 ) ;
F_222 ( V_8 ) ;
F_223 ( V_8 ) ;
F_224 ( V_8 ) ;
F_225 ( V_8 ) ;
F_226 ( V_8 -> V_49 . V_225 ) ;
F_226 ( V_8 -> V_49 . V_56 ) ;
}
}
void * F_227 ( unsigned int * V_226 , int V_227 )
{
struct V_87 * V_26 ;
unsigned int V_228 , V_12 ;
T_7 V_229 ;
if ( * V_226 > ( V_230 / sizeof( struct V_87 ) ) )
return NULL ;
F_128 ( sizeof( struct V_87 ) != sizeof( struct V_214 ) ) ;
V_228 = * V_226 = F_228 ( * V_226 , V_231 / sizeof( struct V_87 ) ) ;
if ( V_228 > ( V_230 / sizeof( struct V_87 ) ) )
return NULL ;
V_229 = V_228 * sizeof( struct V_87 ) ;
V_26 = ( void * ) F_229 ( V_232 | V_233 | V_234 ,
F_196 ( V_229 ) ) ;
if ( ! V_26 )
V_26 = F_230 ( V_229 ) ;
if ( V_26 && V_227 )
for ( V_12 = 0 ; V_12 < V_228 ; V_12 ++ )
F_231 ( & V_26 [ V_12 ] , V_12 ) ;
return V_26 ;
}
int F_232 ( unsigned int V_235 )
{
int V_12 , V_90 ;
unsigned int V_236 ;
struct V_87 * V_26 , * V_237 ;
struct V_85 * V_86 ;
struct V_48 * V_49 ;
if ( ! V_235 )
return - V_207 ;
V_26 = F_227 ( & V_235 , 1 ) ;
if ( ! V_26 )
return - V_157 ;
V_236 = V_27 ;
if ( V_236 == V_235 ) {
F_192 ( V_26 , V_235 ) ;
return 0 ;
}
F_59 () ;
F_11 () ;
F_233 ( & V_11 ) ;
for ( V_12 = 0 ; V_12 < V_27 ; V_12 ++ ) {
while ( ! F_234 ( & V_94 [ V_12 ] ) ) {
V_86 = F_235 ( V_94 [ V_12 ] . V_238 ,
struct V_85 , V_51 ) ;
V_49 = F_74 ( V_86 ) ;
F_32 ( & V_86 -> V_51 ) ;
V_90 = F_21 ( F_37 ( V_49 ) ,
& V_86 -> V_14 , V_235 ) ;
F_94 ( & V_86 -> V_51 , & V_26 [ V_90 ] ) ;
}
}
V_236 = V_27 ;
V_237 = V_94 ;
V_94 = V_26 ;
V_27 = V_235 ;
F_236 ( & V_11 ) ;
F_13 () ;
F_60 () ;
F_218 () ;
F_192 ( V_237 , V_236 ) ;
return 0 ;
}
int F_237 ( const char * V_239 , struct V_240 * V_241 )
{
unsigned int V_235 ;
int V_242 ;
if ( V_243 -> V_244 -> V_245 != & V_246 )
return - V_247 ;
if ( ! V_27 )
return F_238 ( V_239 , V_241 ) ;
V_242 = F_239 ( V_239 , 0 , & V_235 ) ;
if ( V_242 )
return V_242 ;
return F_232 ( V_235 ) ;
}
void F_240 ( unsigned long V_248 )
{
int V_55 ;
F_185 (cpu)
F_198 ( V_216 , V_55 ) . V_68 |= V_248 ;
}
int F_241 ( void )
{
int V_249 = 8 ;
int V_42 = - V_157 ;
int V_12 , V_55 ;
F_242 ( & V_11 ) ;
for ( V_12 = 0 ; V_12 < V_6 ; V_12 ++ )
F_137 ( & V_7 [ V_12 ] ) ;
if ( ! V_27 ) {
V_27
= ( ( ( V_250 << V_251 ) / 16384 )
/ sizeof( struct V_214 ) ) ;
if ( V_250 > ( 4 * ( 1024 * 1024 * 1024 / V_231 ) ) )
V_27 = 65536 ;
else if ( V_250 > ( 1024 * 1024 * 1024 / V_231 ) )
V_27 = 16384 ;
if ( V_27 < 32 )
V_27 = 32 ;
V_249 = 4 ;
}
V_94 = F_227 ( & V_27 , 1 ) ;
if ( ! V_94 )
return - V_157 ;
V_156 = V_249 * V_27 ;
V_158 = F_243 ( L_16 ,
sizeof( struct V_48 ) ,
V_65 + 1 ,
V_252 | V_253 , NULL ) ;
if ( ! V_158 )
goto V_254;
F_244 ( V_255 L_17 ,
V_256 , V_27 ,
V_156 ) ;
V_42 = F_245 () ;
if ( V_42 < 0 )
goto V_257;
V_42 = F_246 () ;
if ( V_42 < 0 )
goto V_258;
V_42 = F_247 () ;
if ( V_42 < 0 )
goto V_259;
V_42 = F_248 () ;
if ( V_42 < 0 )
goto V_260;
V_42 = F_249 () ;
if ( V_42 < 0 )
goto V_261;
V_42 = F_250 () ;
if ( V_42 < 0 )
goto V_262;
V_42 = F_251 () ;
if ( V_42 < 0 )
goto V_263;
V_42 = F_252 () ;
if ( V_42 < 0 )
goto V_264;
V_42 = F_253 () ;
if ( V_42 < 0 )
goto V_265;
F_185 (cpu) {
struct V_48 * V_49 = & F_198 ( V_216 , V_55 ) ;
F_46 ( & V_49 -> V_70 , & V_246 ) ;
F_48 ( & V_49 -> V_71 . V_72 , 1 ) ;
}
F_240 ( V_118 | V_266 ) ;
F_130 ( & V_140 ) ;
F_129 ( V_152 , & V_140 . V_145 , V_135 ) ;
return 0 ;
V_265:
F_205 () ;
V_264:
F_206 () ;
V_263:
F_207 () ;
V_262:
F_208 () ;
V_261:
F_209 () ;
V_260:
F_210 () ;
V_259:
F_211 () ;
V_258:
F_212 () ;
V_257:
F_213 ( V_158 ) ;
V_254:
F_192 ( V_94 , V_27 ) ;
return V_42 ;
}
void F_254 ( void )
{
F_200 ( V_217 , F_181 ) ;
F_200 ( V_218 , F_53 ) ;
}
int F_255 ( struct V_8 * V_8 )
{
int V_42 = - V_157 ;
int V_55 ;
F_48 ( & V_8 -> V_49 . V_155 , 0 ) ;
V_8 -> V_49 . V_56 = F_256 ( struct V_53 ) ;
if ( ! V_8 -> V_49 . V_56 )
goto V_267;
F_185 (cpu) {
struct V_53 * V_54 = F_36 ( V_8 -> V_49 . V_56 , V_55 ) ;
F_137 ( & V_54 -> V_1 ) ;
F_231 ( & V_54 -> V_58 , V_268 ) ;
F_231 ( & V_54 -> V_57 , V_269 ) ;
}
V_8 -> V_49 . V_225 = F_256 ( struct V_270 ) ;
if ( ! V_8 -> V_49 . V_225 )
goto V_271;
V_42 = F_257 ( V_8 ) ;
if ( V_42 < 0 )
goto V_257;
V_42 = F_258 ( V_8 ) ;
if ( V_42 < 0 )
goto V_258;
V_42 = F_259 ( V_8 ) ;
if ( V_42 < 0 )
goto V_259;
V_42 = F_260 ( V_8 ) ;
if ( V_42 < 0 )
goto V_260;
V_42 = F_261 ( V_8 ) ;
if ( V_42 < 0 )
goto V_262;
V_42 = F_262 ( V_8 ) ;
if ( V_42 < 0 )
goto V_265;
return 0 ;
V_265:
F_221 ( V_8 ) ;
V_262:
F_222 ( V_8 ) ;
V_260:
F_223 ( V_8 ) ;
V_259:
F_224 ( V_8 ) ;
V_258:
F_225 ( V_8 ) ;
V_257:
F_226 ( V_8 -> V_49 . V_225 ) ;
V_271:
F_226 ( V_8 -> V_49 . V_56 ) ;
V_267:
return V_42 ;
}
