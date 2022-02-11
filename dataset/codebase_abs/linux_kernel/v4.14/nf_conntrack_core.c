void F_1 ( T_1 * V_1 ) __acquires( V_1 )
{
F_2 ( V_1 ) ;
if ( F_3 ( F_4 ( & V_2 ) == false ) )
return;
F_5 ( V_1 ) ;
F_2 ( & V_3 ) ;
F_2 ( V_1 ) ;
F_5 ( & V_3 ) ;
}
static void F_6 ( unsigned int V_4 , unsigned int V_5 )
{
V_4 %= V_6 ;
V_5 %= V_6 ;
F_5 ( & V_7 [ V_4 ] ) ;
if ( V_4 != V_5 )
F_5 ( & V_7 [ V_5 ] ) ;
}
static bool F_7 ( struct V_8 * V_8 , unsigned int V_4 ,
unsigned int V_5 , unsigned int V_9 )
{
V_4 %= V_6 ;
V_5 %= V_6 ;
if ( V_4 <= V_5 ) {
F_1 ( & V_7 [ V_4 ] ) ;
if ( V_4 != V_5 )
F_8 ( & V_7 [ V_5 ] ,
V_10 ) ;
} else {
F_1 ( & V_7 [ V_5 ] ) ;
F_8 ( & V_7 [ V_4 ] ,
V_10 ) ;
}
if ( F_9 ( & V_11 , V_9 ) ) {
F_6 ( V_4 , V_5 ) ;
return true ;
}
return false ;
}
static void F_10 ( void )
{
int V_12 ;
F_2 ( & V_3 ) ;
V_2 = true ;
for ( V_12 = 0 ; V_12 < V_6 ; V_12 ++ ) {
F_2 ( & V_7 [ V_12 ] ) ;
F_5 ( & V_7 [ V_12 ] ) ;
}
}
static void F_11 ( void )
{
F_12 ( & V_2 , false ) ;
F_5 ( & V_3 ) ;
}
static T_2 F_13 ( const struct V_13 * V_14 ,
const struct V_8 * V_8 )
{
unsigned int V_15 ;
T_2 V_16 ;
F_14 ( & V_17 , sizeof( V_17 ) ) ;
V_16 = V_17 ^ F_15 ( V_8 ) ;
V_15 = ( sizeof( V_14 -> V_18 ) + sizeof( V_14 -> V_19 . V_20 ) ) / sizeof( T_2 ) ;
return F_16 ( ( T_2 * ) V_14 , V_15 , V_16 ^
( ( ( V_21 V_22 ) V_14 -> V_19 . V_23 . V_24 << 16 ) |
V_14 -> V_19 . V_25 ) ) ;
}
static T_2 F_17 ( T_2 V_26 )
{
return F_18 ( V_26 , V_27 ) ;
}
static T_2 F_19 ( const struct V_8 * V_8 ,
const struct V_13 * V_14 ,
unsigned int V_28 )
{
return F_18 ( F_13 ( V_14 , V_8 ) , V_28 ) ;
}
static T_2 F_20 ( const struct V_8 * V_8 ,
const struct V_13 * V_14 )
{
return F_17 ( F_13 ( V_14 , V_8 ) ) ;
}
bool
F_21 ( const struct V_29 * V_30 ,
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
bool F_22 ( const struct V_29 * V_30 , unsigned int V_31 ,
T_3 V_33 ,
struct V_8 * V_8 , struct V_13 * V_14 )
{
const struct V_34 * V_35 ;
const struct V_36 * V_37 ;
unsigned int V_41 ;
T_4 V_25 ;
int V_42 ;
F_23 () ;
V_35 = F_24 ( V_33 ) ;
V_42 = V_35 -> V_43 ( V_30 , V_31 , & V_41 , & V_25 ) ;
if ( V_42 != V_44 ) {
F_25 () ;
return false ;
}
V_37 = F_26 ( V_33 , V_25 ) ;
V_42 = F_21 ( V_30 , V_31 , V_41 , V_33 , V_25 , V_8 , V_14 ,
V_35 , V_37 ) ;
F_25 () ;
return V_42 ;
}
bool
F_27 ( struct V_13 * V_45 ,
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
F_28 ( struct V_48 * V_49 )
{
F_29 ( L_1 , V_49 ) ;
F_30 ( & V_49 -> V_50 [ V_40 ] . V_51 ) ;
F_30 ( & V_49 -> V_50 [ V_52 ] . V_51 ) ;
F_31 ( V_49 ) ;
}
static void F_32 ( struct V_48 * V_49 )
{
struct V_53 * V_54 ;
V_49 -> V_55 = F_33 () ;
V_54 = F_34 ( F_35 ( V_49 ) -> V_49 . V_56 , V_49 -> V_55 ) ;
F_2 ( & V_54 -> V_1 ) ;
F_36 ( & V_49 -> V_50 [ V_40 ] . V_51 ,
& V_54 -> V_57 ) ;
F_5 ( & V_54 -> V_1 ) ;
}
static void F_37 ( struct V_48 * V_49 )
{
struct V_53 * V_54 ;
V_49 -> V_55 = F_33 () ;
V_54 = F_34 ( F_35 ( V_49 ) -> V_49 . V_56 , V_49 -> V_55 ) ;
F_2 ( & V_54 -> V_1 ) ;
F_36 ( & V_49 -> V_50 [ V_40 ] . V_51 ,
& V_54 -> V_58 ) ;
F_5 ( & V_54 -> V_1 ) ;
}
static void F_38 ( struct V_48 * V_49 )
{
struct V_53 * V_54 ;
V_54 = F_34 ( F_35 ( V_49 ) -> V_49 . V_56 , V_49 -> V_55 ) ;
F_2 ( & V_54 -> V_1 ) ;
F_39 ( F_40 ( & V_49 -> V_50 [ V_40 ] . V_51 ) ) ;
F_30 ( & V_49 -> V_50 [ V_40 ] . V_51 ) ;
F_5 ( & V_54 -> V_1 ) ;
}
struct V_48 * F_41 ( struct V_8 * V_8 ,
const struct V_59 * V_60 ,
T_5 V_61 )
{
struct V_48 * V_62 , * V_63 ;
if ( V_64 <= V_65 ) {
V_62 = F_42 ( sizeof( * V_62 ) + V_65 , V_61 ) ;
if ( ! V_62 )
return NULL ;
V_63 = V_62 ;
V_62 = (struct V_48 * ) F_43 ( ( unsigned long ) V_63 ) ;
if ( V_62 != V_63 ) {
V_62 = (struct V_48 * ) F_43 ( ( unsigned long ) V_63 ) ;
V_62 -> V_66 . V_67 = ( char * ) V_62 - ( char * ) V_63 ;
}
} else {
V_62 = F_42 ( sizeof( * V_62 ) , V_61 ) ;
if ( ! V_62 )
return NULL ;
}
V_62 -> V_68 = V_69 ;
F_44 ( & V_62 -> V_70 , V_8 ) ;
F_45 ( V_62 , V_60 ) ;
F_46 ( & V_62 -> V_71 . V_72 , 0 ) ;
return V_62 ;
}
void F_47 ( struct V_48 * V_62 )
{
F_48 ( V_62 ) ;
F_49 ( V_62 ) ;
if ( V_64 <= V_65 )
F_50 ( ( char * ) V_62 - V_62 -> V_66 . V_67 ) ;
else
F_50 ( V_62 ) ;
}
static void
F_51 ( struct V_73 * V_74 )
{
struct V_48 * V_49 = (struct V_48 * ) V_74 ;
const struct V_36 * V_37 ;
F_29 ( L_2 , V_49 ) ;
F_52 ( F_53 ( & V_74 -> V_72 ) != 0 ) ;
if ( F_54 ( F_55 ( V_49 ) ) ) {
F_47 ( V_49 ) ;
return;
}
V_37 = F_26 ( F_56 ( V_49 ) , F_57 ( V_49 ) ) ;
if ( V_37 -> V_75 )
V_37 -> V_75 ( V_49 ) ;
F_58 () ;
F_31 ( V_49 ) ;
F_38 ( V_49 ) ;
F_59 () ;
if ( V_49 -> V_76 )
F_60 ( V_49 -> V_76 ) ;
F_29 ( L_3 , V_49 ) ;
F_61 ( V_49 ) ;
}
static void F_62 ( struct V_48 * V_49 )
{
struct V_8 * V_8 = F_35 ( V_49 ) ;
unsigned int V_26 , V_77 ;
unsigned int V_9 ;
F_63 ( V_49 ) ;
F_58 () ;
do {
V_9 = F_64 ( & V_11 ) ;
V_26 = F_20 ( V_8 ,
& V_49 -> V_50 [ V_40 ] . V_14 ) ;
V_77 = F_20 ( V_8 ,
& V_49 -> V_50 [ V_52 ] . V_14 ) ;
} while ( F_7 ( V_8 , V_26 , V_77 , V_9 ) );
F_28 ( V_49 ) ;
F_6 ( V_26 , V_77 ) ;
F_32 ( V_49 ) ;
F_59 () ;
}
bool F_65 ( struct V_48 * V_49 , T_2 V_78 , int V_79 )
{
struct V_80 * V_81 ;
if ( F_66 ( V_82 , & V_49 -> V_68 ) )
return false ;
V_81 = F_67 ( V_49 ) ;
if ( V_81 && V_81 -> V_83 == 0 )
V_81 -> V_83 = F_68 () ;
if ( F_69 ( V_84 , V_49 ,
V_78 , V_79 ) < 0 ) {
F_62 ( V_49 ) ;
F_70 ( F_35 ( V_49 ) ) ;
return false ;
}
F_71 ( F_35 ( V_49 ) ) ;
F_62 ( V_49 ) ;
F_60 ( V_49 ) ;
return true ;
}
static inline bool
F_72 ( struct V_85 * V_86 ,
const struct V_13 * V_14 ,
const struct V_59 * V_60 ,
const struct V_8 * V_8 )
{
struct V_48 * V_49 = F_73 ( V_86 ) ;
return F_74 ( V_14 , & V_86 -> V_14 ) &&
F_75 ( V_49 , V_60 , F_76 ( V_86 ) ) &&
F_77 ( V_49 ) &&
F_78 ( V_8 , F_35 ( V_49 ) ) ;
}
static void F_79 ( struct V_48 * V_49 )
{
if ( ! F_80 ( & V_49 -> V_71 . V_72 ) )
return;
if ( F_81 ( V_49 ) )
F_82 ( V_49 ) ;
F_60 ( V_49 ) ;
}
static struct V_85 *
F_83 ( struct V_8 * V_8 , const struct V_59 * V_60 ,
const struct V_13 * V_14 , T_2 V_26 )
{
struct V_85 * V_86 ;
struct V_87 * V_88 ;
struct V_89 * V_15 ;
unsigned int V_90 , V_91 ;
V_92:
F_84 ( & V_88 , & V_91 ) ;
V_90 = F_18 ( V_26 , V_91 ) ;
F_85 (h, n, &ct_hash[bucket], hnnode) {
struct V_48 * V_49 ;
V_49 = F_73 ( V_86 ) ;
if ( F_86 ( V_49 ) ) {
F_79 ( V_49 ) ;
continue;
}
if ( F_87 ( V_49 ) )
continue;
if ( F_72 ( V_86 , V_14 , V_60 , V_8 ) )
return V_86 ;
}
if ( F_88 ( V_15 ) != V_90 ) {
F_89 ( V_8 , V_93 ) ;
goto V_92;
}
return NULL ;
}
static struct V_85 *
F_90 ( struct V_8 * V_8 , const struct V_59 * V_60 ,
const struct V_13 * V_14 , T_2 V_26 )
{
struct V_85 * V_86 ;
struct V_48 * V_49 ;
F_23 () ;
V_92:
V_86 = F_83 ( V_8 , V_60 , V_14 , V_26 ) ;
if ( V_86 ) {
V_49 = F_73 ( V_86 ) ;
if ( F_54 ( F_87 ( V_49 ) ||
! F_80 ( & V_49 -> V_71 . V_72 ) ) )
V_86 = NULL ;
else {
if ( F_54 ( ! F_72 ( V_86 , V_14 , V_60 , V_8 ) ) ) {
F_60 ( V_49 ) ;
goto V_92;
}
}
}
F_25 () ;
return V_86 ;
}
struct V_85 *
F_91 ( struct V_8 * V_8 , const struct V_59 * V_60 ,
const struct V_13 * V_14 )
{
return F_90 ( V_8 , V_60 , V_14 ,
F_13 ( V_14 , V_8 ) ) ;
}
static void F_92 ( struct V_48 * V_49 ,
unsigned int V_26 ,
unsigned int V_77 )
{
F_93 ( & V_49 -> V_50 [ V_40 ] . V_51 ,
& V_94 [ V_26 ] ) ;
F_93 ( & V_49 -> V_50 [ V_52 ] . V_51 ,
& V_94 [ V_77 ] ) ;
}
int
F_94 ( struct V_48 * V_49 )
{
const struct V_59 * V_60 ;
struct V_8 * V_8 = F_35 ( V_49 ) ;
unsigned int V_26 , V_77 ;
struct V_85 * V_86 ;
struct V_89 * V_15 ;
unsigned int V_9 ;
V_60 = F_95 ( V_49 ) ;
F_58 () ;
do {
V_9 = F_64 ( & V_11 ) ;
V_26 = F_20 ( V_8 ,
& V_49 -> V_50 [ V_40 ] . V_14 ) ;
V_77 = F_20 ( V_8 ,
& V_49 -> V_50 [ V_52 ] . V_14 ) ;
} while ( F_7 ( V_8 , V_26 , V_77 , V_9 ) );
F_96 (h, n, &nf_conntrack_hash[hash], hnnode)
if ( F_72 ( V_86 , & V_49 -> V_50 [ V_40 ] . V_14 ,
V_60 , V_8 ) )
goto V_95;
F_96 (h, n, &nf_conntrack_hash[reply_hash], hnnode)
if ( F_72 ( V_86 , & V_49 -> V_50 [ V_52 ] . V_14 ,
V_60 , V_8 ) )
goto V_95;
F_97 () ;
F_46 ( & V_49 -> V_71 . V_72 , 2 ) ;
F_92 ( V_49 , V_26 , V_77 ) ;
F_6 ( V_26 , V_77 ) ;
F_98 ( V_8 , V_96 ) ;
F_59 () ;
return 0 ;
V_95:
F_6 ( V_26 , V_77 ) ;
F_98 ( V_8 , V_97 ) ;
F_59 () ;
return - V_98 ;
}
static inline void F_99 ( struct V_48 * V_49 ,
enum V_99 V_100 ,
unsigned int V_101 )
{
struct V_102 * V_103 ;
V_103 = F_100 ( V_49 ) ;
if ( V_103 ) {
struct V_104 * V_105 = V_103 -> V_105 ;
F_101 ( & V_105 [ F_102 ( V_100 ) ] . V_106 ) ;
F_103 ( V_101 , & V_105 [ F_102 ( V_100 ) ] . V_107 ) ;
}
}
static void F_104 ( struct V_48 * V_49 , enum V_99 V_100 ,
const struct V_48 * V_108 )
{
struct V_102 * V_103 ;
V_103 = F_100 ( V_108 ) ;
if ( V_103 ) {
struct V_104 * V_105 = V_103 -> V_105 ;
unsigned int V_107 ;
V_107 = F_105 ( & V_105 [ F_102 ( V_100 ) ] . V_107 ) ;
F_99 ( V_49 , V_100 , V_107 ) ;
}
}
static int F_106 ( struct V_8 * V_8 , struct V_29 * V_30 ,
enum V_99 V_100 ,
struct V_85 * V_86 )
{
struct V_48 * V_49 = F_73 ( V_86 ) ;
const struct V_36 * V_37 ;
V_37 = F_26 ( F_56 ( V_49 ) , F_57 ( V_49 ) ) ;
if ( V_37 -> V_109 &&
( ( V_49 -> V_68 & V_110 ) == 0 ) &&
! F_87 ( V_49 ) &&
F_80 ( & V_49 -> V_71 . V_72 ) ) {
enum V_99 V_111 ;
struct V_48 * V_108 = F_107 ( V_30 , & V_111 ) ;
F_104 ( V_49 , V_100 , V_108 ) ;
F_108 ( & V_108 -> V_71 ) ;
F_109 ( V_30 , V_49 , V_111 ) ;
return V_44 ;
}
F_98 ( V_8 , V_112 ) ;
return V_113 ;
}
int
F_110 ( struct V_29 * V_30 )
{
const struct V_59 * V_60 ;
unsigned int V_26 , V_77 ;
struct V_85 * V_86 ;
struct V_48 * V_49 ;
struct V_114 * V_115 ;
struct V_80 * V_81 ;
struct V_89 * V_15 ;
enum V_99 V_100 ;
struct V_8 * V_8 ;
unsigned int V_9 ;
int V_42 = V_113 ;
V_49 = F_107 ( V_30 , & V_100 ) ;
V_8 = F_35 ( V_49 ) ;
if ( F_102 ( V_100 ) != V_40 )
return V_44 ;
V_60 = F_95 ( V_49 ) ;
F_58 () ;
do {
V_9 = F_64 ( & V_11 ) ;
V_26 = * ( unsigned long * ) & V_49 -> V_50 [ V_52 ] . V_51 . V_116 ;
V_26 = F_17 ( V_26 ) ;
V_77 = F_20 ( V_8 ,
& V_49 -> V_50 [ V_52 ] . V_14 ) ;
} while ( F_7 ( V_8 , V_26 , V_77 , V_9 ) );
F_52 ( F_77 ( V_49 ) ) ;
F_29 ( L_4 , V_49 ) ;
F_38 ( V_49 ) ;
if ( F_54 ( F_87 ( V_49 ) ) ) {
F_32 ( V_49 ) ;
goto V_57;
}
F_96 (h, n, &nf_conntrack_hash[hash], hnnode)
if ( F_72 ( V_86 , & V_49 -> V_50 [ V_40 ] . V_14 ,
V_60 , V_8 ) )
goto V_95;
F_96 (h, n, &nf_conntrack_hash[reply_hash], hnnode)
if ( F_72 ( V_86 , & V_49 -> V_50 [ V_52 ] . V_14 ,
V_60 , V_8 ) )
goto V_95;
V_49 -> V_117 += V_118 ;
F_111 ( & V_49 -> V_71 . V_72 ) ;
V_49 -> V_68 |= V_119 ;
V_81 = F_67 ( V_49 ) ;
if ( V_81 ) {
if ( V_30 -> V_81 == 0 )
F_112 ( V_30 ) ;
V_81 -> V_120 = F_113 ( V_30 -> V_81 ) ;
}
F_92 ( V_49 , V_26 , V_77 ) ;
F_6 ( V_26 , V_77 ) ;
F_59 () ;
V_115 = F_114 ( V_49 ) ;
if ( V_115 && V_115 -> V_121 )
F_115 ( V_122 , V_49 ) ;
F_115 ( F_116 ( V_49 ) ?
V_123 : V_124 , V_49 ) ;
return V_44 ;
V_95:
F_32 ( V_49 ) ;
V_42 = F_106 ( V_8 , V_30 , V_100 , V_86 ) ;
V_57:
F_6 ( V_26 , V_77 ) ;
F_98 ( V_8 , V_97 ) ;
F_59 () ;
return V_42 ;
}
int
F_117 ( const struct V_13 * V_14 ,
const struct V_48 * V_125 )
{
struct V_8 * V_8 = F_35 ( V_125 ) ;
const struct V_59 * V_60 ;
struct V_85 * V_86 ;
struct V_87 * V_88 ;
unsigned int V_26 , V_91 ;
struct V_89 * V_15 ;
struct V_48 * V_49 ;
V_60 = F_95 ( V_125 ) ;
F_23 () ;
V_92:
F_84 ( & V_88 , & V_91 ) ;
V_26 = F_19 ( V_8 , V_14 , V_91 ) ;
F_85 (h, n, &ct_hash[hash], hnnode) {
V_49 = F_73 ( V_86 ) ;
if ( V_49 == V_125 )
continue;
if ( F_86 ( V_49 ) ) {
F_79 ( V_49 ) ;
continue;
}
if ( F_72 ( V_86 , V_14 , V_60 , V_8 ) ) {
F_89 ( V_8 , V_126 ) ;
F_25 () ;
return 1 ;
}
}
if ( F_88 ( V_15 ) != V_26 ) {
F_89 ( V_8 , V_93 ) ;
goto V_92;
}
F_25 () ;
return 0 ;
}
static unsigned int F_118 ( struct V_8 * V_8 ,
struct V_87 * V_127 )
{
struct V_85 * V_86 ;
struct V_89 * V_15 ;
unsigned int V_128 = 0 ;
struct V_48 * V_129 ;
F_85 (h, n, head, hnnode) {
V_129 = F_73 ( V_86 ) ;
if ( F_86 ( V_129 ) ) {
F_79 ( V_129 ) ;
continue;
}
if ( F_119 ( V_130 , & V_129 -> V_68 ) ||
! F_78 ( F_35 ( V_129 ) , V_8 ) ||
F_87 ( V_129 ) )
continue;
if ( ! F_80 ( & V_129 -> V_71 . V_72 ) )
continue;
if ( F_78 ( F_35 ( V_129 ) , V_8 ) &&
F_77 ( V_129 ) &&
F_65 ( V_129 , 0 , 0 ) )
V_128 ++ ;
F_60 ( V_129 ) ;
}
return V_128 ;
}
static T_6 int F_120 ( struct V_8 * V_8 , unsigned int V_131 )
{
unsigned int V_12 ;
for ( V_12 = 0 ; V_12 < V_132 ; V_12 ++ ) {
struct V_87 * V_88 ;
unsigned int V_26 , V_91 , V_128 ;
F_23 () ;
F_84 ( & V_88 , & V_91 ) ;
V_26 = F_18 ( V_131 ++ , V_91 ) ;
V_128 = F_118 ( V_8 , & V_88 [ V_26 ] ) ;
F_25 () ;
if ( V_128 ) {
F_121 ( V_8 , F_120 , V_128 ) ;
return true ;
}
}
return false ;
}
static bool F_122 ( const struct V_48 * V_49 )
{
return ! F_77 ( V_49 ) || F_87 ( V_49 ) ;
}
static bool F_123 ( const struct V_48 * V_49 )
{
const struct V_36 * V_37 ;
if ( ! F_119 ( V_130 , & V_49 -> V_68 ) )
return true ;
V_37 = F_26 ( F_56 ( V_49 ) , F_57 ( V_49 ) ) ;
if ( V_37 -> V_133 && V_37 -> V_133 ( V_49 ) )
return true ;
return false ;
}
static void F_124 ( struct V_134 * V_135 )
{
unsigned int V_136 = F_125 ( V_137 / V_138 , 1u ) ;
unsigned int V_12 , V_139 , V_140 = 0 , V_141 = 0 ;
unsigned int V_142 = 0 ;
struct V_143 * V_144 ;
unsigned int V_145 , V_146 = 0 ;
unsigned long V_147 ;
V_144 = F_126 ( V_135 , struct V_143 , V_148 . V_135 ) ;
V_139 = V_27 / V_138 ;
V_12 = V_144 -> V_149 ;
if ( V_144 -> F_120 )
V_142 = V_150 / 100u * 95u ;
do {
struct V_85 * V_86 ;
struct V_87 * V_88 ;
struct V_89 * V_15 ;
unsigned int V_151 ;
struct V_48 * V_129 ;
V_12 ++ ;
F_23 () ;
F_84 ( & V_88 , & V_151 ) ;
if ( V_12 >= V_151 )
V_12 = 0 ;
F_85 (h, n, &ct_hash[i], hnnode) {
struct V_8 * V_8 ;
V_129 = F_73 ( V_86 ) ;
V_146 ++ ;
if ( F_86 ( V_129 ) ) {
F_79 ( V_129 ) ;
V_141 ++ ;
continue;
}
if ( V_142 == 0 || F_122 ( V_129 ) )
continue;
V_8 = F_35 ( V_129 ) ;
if ( F_53 ( & V_8 -> V_49 . V_152 ) < V_142 )
continue;
if ( ! F_80 ( & V_129 -> V_71 . V_72 ) )
continue;
if ( F_122 ( V_129 ) ) {
F_60 ( V_129 ) ;
continue;
}
if ( F_123 ( V_129 ) )
F_82 ( V_129 ) ;
F_60 ( V_129 ) ;
}
F_25 () ;
F_127 () ;
} while ( ++ V_140 < V_139 );
if ( V_144 -> V_153 )
return;
V_145 = V_146 ? V_141 * 100 / V_146 : 0 ;
if ( V_145 > V_154 ) {
V_144 -> V_155 = V_136 ;
} else {
unsigned int F_125 = V_156 / V_138 ;
F_128 ( ( V_156 / V_138 ) == 0 ) ;
V_144 -> V_155 += V_136 ;
if ( V_144 -> V_155 > F_125 )
V_144 -> V_155 = F_125 ;
}
V_147 = V_144 -> V_155 ;
V_144 -> V_149 = V_12 ;
V_144 -> F_120 = false ;
F_129 ( V_157 , & V_144 -> V_148 , V_147 ) ;
}
static void F_130 ( struct V_143 * V_144 )
{
F_131 ( & V_144 -> V_148 , F_124 ) ;
V_144 -> V_155 = V_137 ;
V_144 -> V_153 = false ;
}
static struct V_48 *
F_132 ( struct V_8 * V_8 ,
const struct V_59 * V_60 ,
const struct V_13 * V_46 ,
const struct V_13 * V_158 ,
T_5 V_159 , T_2 V_26 )
{
struct V_48 * V_49 ;
F_111 ( & V_8 -> V_49 . V_152 ) ;
if ( V_150 &&
F_54 ( F_53 ( & V_8 -> V_49 . V_152 ) > V_150 ) ) {
if ( ! F_120 ( V_8 , V_26 ) ) {
if ( ! V_143 . F_120 )
V_143 . F_120 = true ;
F_133 ( & V_8 -> V_49 . V_152 ) ;
F_134 ( L_5 ) ;
return F_135 ( - V_160 ) ;
}
}
V_49 = F_136 ( V_161 , V_159 ) ;
if ( V_49 == NULL )
goto V_95;
F_137 ( & V_49 -> V_1 ) ;
V_49 -> V_50 [ V_40 ] . V_14 = * V_46 ;
V_49 -> V_50 [ V_40 ] . V_51 . V_116 = NULL ;
V_49 -> V_50 [ V_52 ] . V_14 = * V_158 ;
* ( unsigned long * ) ( & V_49 -> V_50 [ V_52 ] . V_51 . V_116 ) = V_26 ;
V_49 -> V_68 = 0 ;
F_44 ( & V_49 -> V_70 , V_8 ) ;
memset ( & V_49 -> V_162 [ 0 ] , 0 ,
F_138 ( struct V_48 , V_66 ) -
F_138 ( struct V_48 , V_162 [ 0 ] ) ) ;
F_45 ( V_49 , V_60 ) ;
F_46 ( & V_49 -> V_71 . V_72 , 0 ) ;
return V_49 ;
V_95:
F_133 ( & V_8 -> V_49 . V_152 ) ;
return F_135 ( - V_160 ) ;
}
struct V_48 * F_139 ( struct V_8 * V_8 ,
const struct V_59 * V_60 ,
const struct V_13 * V_46 ,
const struct V_13 * V_158 ,
T_5 V_159 )
{
return F_132 ( V_8 , V_60 , V_46 , V_158 , V_159 , 0 ) ;
}
void F_61 ( struct V_48 * V_49 )
{
struct V_8 * V_8 = F_35 ( V_49 ) ;
F_52 ( F_53 ( & V_49 -> V_71 . V_72 ) != 0 ) ;
F_48 ( V_49 ) ;
F_49 ( V_49 ) ;
F_140 ( V_161 , V_49 ) ;
F_141 () ;
F_133 ( & V_8 -> V_49 . V_152 ) ;
}
int
F_142 ( struct V_8 * V_8 , struct V_48 * V_62 ,
struct V_29 * V_30 ,
unsigned int V_32 ,
T_3 V_33 ,
T_4 V_25 ,
const struct V_34 * V_35 ,
const struct V_36 * V_37 )
{
const struct V_59 * V_60 ;
struct V_13 V_14 ;
struct V_85 * V_86 ;
enum V_99 V_100 ;
struct V_59 V_129 ;
struct V_48 * V_49 ;
T_2 V_26 ;
if ( ! F_21 ( V_30 , F_143 ( V_30 ) ,
V_32 , V_33 , V_25 , V_8 , & V_14 , V_35 ,
V_37 ) ) {
F_29 ( L_6 ) ;
return 0 ;
}
V_60 = F_144 ( V_62 , V_30 , & V_129 ) ;
V_26 = F_13 ( & V_14 , V_8 ) ;
V_86 = F_90 ( V_8 , V_60 , & V_14 , V_26 ) ;
if ( ! V_86 ) {
V_86 = F_145 ( V_8 , V_62 , & V_14 , V_35 , V_37 ,
V_30 , V_32 , V_26 ) ;
if ( ! V_86 )
return 0 ;
if ( F_146 ( V_86 ) )
return F_147 ( V_86 ) ;
}
V_49 = F_73 ( V_86 ) ;
if ( F_76 ( V_86 ) == V_52 ) {
V_100 = V_163 ;
} else {
if ( F_119 ( V_164 , & V_49 -> V_68 ) ) {
F_29 ( L_7 , V_49 ) ;
V_100 = V_165 ;
} else if ( F_119 ( V_166 , & V_49 -> V_68 ) ) {
F_29 ( L_8 , V_49 ) ;
V_100 = V_167 ;
} else {
F_29 ( L_9 , V_49 ) ;
V_100 = V_168 ;
}
}
F_109 ( V_30 , V_49 , V_100 ) ;
return 0 ;
}
unsigned int
F_148 ( struct V_8 * V_8 , T_4 V_169 , unsigned int V_170 ,
struct V_29 * V_30 )
{
const struct V_34 * V_35 ;
const struct V_36 * V_37 ;
struct V_48 * V_49 , * V_62 ;
enum V_99 V_100 ;
unsigned int * V_171 ;
unsigned int V_32 ;
T_4 V_25 ;
int V_42 ;
V_62 = F_107 ( V_30 , & V_100 ) ;
if ( V_62 || V_100 == V_172 ) {
if ( ( V_62 && ! F_55 ( V_62 ) ) ||
V_100 == V_172 ) {
F_89 ( V_8 , V_173 ) ;
return V_44 ;
}
V_30 -> V_174 = 0 ;
}
V_35 = F_24 ( V_169 ) ;
V_42 = V_35 -> V_43 ( V_30 , F_143 ( V_30 ) ,
& V_32 , & V_25 ) ;
if ( V_42 <= 0 ) {
F_29 ( L_10 ) ;
F_89 ( V_8 , error ) ;
F_89 ( V_8 , V_175 ) ;
V_42 = - V_42 ;
goto V_95;
}
V_37 = F_26 ( V_169 , V_25 ) ;
if ( V_37 -> error != NULL ) {
V_42 = V_37 -> error ( V_8 , V_62 , V_30 , V_32 , V_169 , V_170 ) ;
if ( V_42 <= 0 ) {
F_89 ( V_8 , error ) ;
F_89 ( V_8 , V_175 ) ;
V_42 = - V_42 ;
goto V_95;
}
if ( V_30 -> V_174 )
goto V_95;
}
V_176:
V_42 = F_142 ( V_8 , V_62 , V_30 , V_32 , V_169 , V_25 ,
V_35 , V_37 ) ;
if ( V_42 < 0 ) {
F_89 ( V_8 , V_112 ) ;
V_42 = V_113 ;
goto V_95;
}
V_49 = F_107 ( V_30 , & V_100 ) ;
if ( ! V_49 ) {
F_89 ( V_8 , V_175 ) ;
V_42 = V_44 ;
goto V_95;
}
V_171 = F_149 ( V_8 , V_49 , V_37 ) ;
V_42 = V_37 -> V_177 ( V_49 , V_30 , V_32 , V_100 , V_169 , V_171 ) ;
if ( V_42 <= 0 ) {
F_29 ( L_11 ) ;
F_108 ( & V_49 -> V_71 ) ;
V_30 -> V_174 = 0 ;
F_89 ( V_8 , V_175 ) ;
if ( V_42 == - V_113 )
F_89 ( V_8 , V_112 ) ;
if ( V_42 == - V_178 )
goto V_176;
V_42 = - V_42 ;
goto V_95;
}
if ( V_100 == V_163 &&
! F_66 ( V_164 , & V_49 -> V_68 ) )
F_115 ( V_179 , V_49 ) ;
V_95:
if ( V_62 )
F_60 ( V_62 ) ;
return V_42 ;
}
bool F_150 ( struct V_13 * V_45 ,
const struct V_13 * V_46 )
{
bool V_42 ;
F_23 () ;
V_42 = F_27 ( V_45 , V_46 ,
F_24 ( V_46 -> V_18 . V_33 ) ,
F_26 ( V_46 -> V_18 . V_33 ,
V_46 -> V_19 . V_25 ) ) ;
F_25 () ;
return V_42 ;
}
void F_151 ( struct V_48 * V_49 ,
const struct V_13 * V_180 )
{
struct V_114 * V_115 = F_114 ( V_49 ) ;
F_52 ( F_77 ( V_49 ) ) ;
F_29 ( L_12 , V_49 ) ;
F_152 ( V_180 ) ;
V_49 -> V_50 [ V_52 ] . V_14 = * V_180 ;
if ( V_49 -> V_76 || ( V_115 && ! F_153 ( & V_115 -> V_181 ) ) )
return;
F_23 () ;
F_154 ( V_49 , NULL , V_182 ) ;
F_25 () ;
}
void F_155 ( struct V_48 * V_49 ,
enum V_99 V_100 ,
const struct V_29 * V_30 ,
unsigned long V_183 ,
int V_184 )
{
F_52 ( ! V_30 ) ;
if ( F_119 ( V_185 , & V_49 -> V_68 ) )
goto V_103;
if ( F_77 ( V_49 ) )
V_183 += V_118 ;
V_49 -> V_117 = V_183 ;
V_103:
if ( V_184 )
F_99 ( V_49 , V_100 , V_30 -> V_101 ) ;
}
bool F_156 ( struct V_48 * V_49 ,
enum V_99 V_100 ,
const struct V_29 * V_30 )
{
F_99 ( V_49 , V_100 , V_30 -> V_101 ) ;
return F_65 ( V_49 , 0 , 0 ) ;
}
int F_157 ( struct V_29 * V_30 ,
const struct V_13 * V_14 )
{
if ( F_158 ( V_30 , V_186 , V_14 -> V_18 . V_23 . V_187 . V_188 ) ||
F_158 ( V_30 , V_189 , V_14 -> V_19 . V_23 . V_187 . V_188 ) )
goto V_190;
return 0 ;
V_190:
return - 1 ;
}
int F_159 ( struct V_191 * V_192 [] ,
struct V_13 * V_193 )
{
if ( ! V_192 [ V_186 ] || ! V_192 [ V_189 ] )
return - V_194 ;
V_193 -> V_18 . V_23 . V_187 . V_188 = F_160 ( V_192 [ V_186 ] ) ;
V_193 -> V_19 . V_23 . V_187 . V_188 = F_160 ( V_192 [ V_189 ] ) ;
return 0 ;
}
int F_161 ( void )
{
return F_162 ( V_195 , V_196 + 1 ) ;
}
static void F_163 ( struct V_29 * V_197 , const struct V_29 * V_30 )
{
struct V_48 * V_49 ;
enum V_99 V_100 ;
V_49 = F_107 ( V_30 , & V_100 ) ;
if ( F_102 ( V_100 ) == V_40 )
V_100 = V_198 ;
else
V_100 = V_167 ;
F_109 ( V_197 , V_49 , V_100 ) ;
F_164 ( F_165 ( V_197 ) ) ;
}
static struct V_48 *
F_166 ( int (* F_167)( struct V_48 * V_12 , void * V_199 ) ,
void * V_199 , unsigned int * V_90 )
{
struct V_85 * V_86 ;
struct V_48 * V_49 ;
struct V_89 * V_15 ;
T_1 * V_200 ;
for (; * V_90 < V_27 ; ( * V_90 ) ++ ) {
V_200 = & V_7 [ * V_90 % V_6 ] ;
F_58 () ;
F_1 ( V_200 ) ;
if ( * V_90 < V_27 ) {
F_96 (h, n, &nf_conntrack_hash[*bucket], hnnode) {
if ( F_76 ( V_86 ) != V_40 )
continue;
V_49 = F_73 ( V_86 ) ;
if ( F_167 ( V_49 , V_199 ) )
goto V_126;
}
}
F_5 ( V_200 ) ;
F_59 () ;
F_168 () ;
}
return NULL ;
V_126:
F_111 ( & V_49 -> V_71 . V_72 ) ;
F_5 ( V_200 ) ;
F_59 () ;
return V_49 ;
}
static void F_169 ( int (* F_167)( struct V_48 * V_12 , void * V_199 ) ,
void * V_199 , T_2 V_78 , int V_79 )
{
unsigned int V_90 = 0 , V_9 ;
struct V_48 * V_49 ;
F_170 () ;
for (; ; ) {
V_9 = F_64 ( & V_11 ) ;
while ( ( V_49 = F_166 ( F_167 , V_199 , & V_90 ) ) != NULL ) {
F_65 ( V_49 , V_78 , V_79 ) ;
F_60 ( V_49 ) ;
F_168 () ;
}
if ( ! F_9 ( & V_11 , V_9 ) )
break;
V_90 = 0 ;
}
}
static int F_171 ( struct V_48 * V_12 , void * V_199 )
{
struct V_201 * V_202 = V_199 ;
if ( ! F_78 ( V_202 -> V_8 , F_35 ( V_12 ) ) )
return 0 ;
return V_202 -> F_167 ( V_12 , V_202 -> V_199 ) ;
}
static void
F_172 ( struct V_8 * V_8 )
{
int V_55 ;
F_173 (cpu) {
struct V_85 * V_86 ;
struct V_89 * V_15 ;
struct V_53 * V_54 ;
V_54 = F_34 ( V_8 -> V_49 . V_56 , V_55 ) ;
F_174 ( & V_54 -> V_1 ) ;
F_96 (h, n, &pcpu->unconfirmed, hnnode) {
struct V_48 * V_49 ;
V_49 = F_73 ( V_86 ) ;
F_175 ( V_82 , & V_49 -> V_68 ) ;
}
F_176 ( & V_54 -> V_1 ) ;
F_168 () ;
}
}
void F_177 ( struct V_8 * V_8 )
{
F_170 () ;
if ( F_53 ( & V_8 -> V_49 . V_152 ) > 0 ) {
F_172 ( V_8 ) ;
F_178 ( V_8 ) ;
F_179 () ;
}
}
void F_180 ( struct V_8 * V_8 ,
int (* F_167)( struct V_48 * V_12 , void * V_199 ) ,
void * V_199 , T_2 V_78 , int V_79 )
{
struct V_201 V_202 ;
F_170 () ;
if ( F_53 ( & V_8 -> V_49 . V_152 ) == 0 )
return;
V_202 . F_167 = F_167 ;
V_202 . V_199 = V_199 ;
V_202 . V_8 = V_8 ;
F_169 ( F_171 , & V_202 , V_78 , V_79 ) ;
}
void
F_181 ( int (* F_167)( struct V_48 * V_12 , void * V_199 ) , void * V_199 )
{
struct V_8 * V_8 ;
F_182 () ;
F_183 (net) {
if ( F_53 ( & V_8 -> V_49 . V_152 ) == 0 )
continue;
F_172 ( V_8 ) ;
F_178 ( V_8 ) ;
}
F_184 () ;
F_185 () ;
F_179 () ;
F_169 ( F_167 , V_199 , 0 , 0 ) ;
}
static int F_186 ( struct V_48 * V_12 , void * V_199 )
{
return F_78 ( F_35 ( V_12 ) , V_199 ) ;
}
void F_187 ( void * V_26 , unsigned int V_28 )
{
if ( F_188 ( V_26 ) )
F_189 ( V_26 ) ;
else
F_190 ( ( unsigned long ) V_26 ,
F_191 ( sizeof( struct V_203 ) * V_28 ) ) ;
}
void F_192 ( void )
{
V_143 . V_153 = true ;
F_193 ( V_204 , NULL ) ;
}
void F_194 ( void )
{
F_193 ( V_205 , NULL ) ;
F_195 ( & V_143 . V_148 ) ;
F_187 ( V_94 , V_27 ) ;
F_196 () ;
F_197 () ;
F_198 () ;
F_199 () ;
F_200 () ;
F_201 () ;
F_202 () ;
F_203 () ;
F_204 () ;
F_205 ( V_161 ) ;
}
void F_206 ( struct V_8 * V_8 )
{
F_207 ( V_206 ) ;
F_208 ( & V_8 -> V_207 , & V_206 ) ;
F_209 ( & V_206 ) ;
}
void F_209 ( struct V_208 * V_209 )
{
int V_210 ;
struct V_8 * V_8 ;
F_179 () ;
V_211:
V_210 = 0 ;
F_210 (net, net_exit_list, exit_list) {
F_169 ( F_186 , V_8 , 0 , 0 ) ;
if ( F_53 ( & V_8 -> V_49 . V_152 ) != 0 )
V_210 = 1 ;
}
if ( V_210 ) {
F_211 () ;
goto V_211;
}
F_210 (net, net_exit_list, exit_list) {
F_212 ( V_8 ) ;
F_213 ( V_8 ) ;
F_214 ( V_8 ) ;
F_215 ( V_8 ) ;
F_216 ( V_8 ) ;
F_217 ( V_8 ) ;
F_218 ( V_8 -> V_49 . V_212 ) ;
F_218 ( V_8 -> V_49 . V_56 ) ;
}
}
void * F_219 ( unsigned int * V_213 , int V_214 )
{
struct V_87 * V_26 ;
unsigned int V_215 , V_12 ;
T_7 V_216 ;
if ( * V_213 > ( V_217 / sizeof( struct V_87 ) ) )
return NULL ;
F_128 ( sizeof( struct V_87 ) != sizeof( struct V_203 ) ) ;
V_215 = * V_213 = F_220 ( * V_213 , V_218 / sizeof( struct V_87 ) ) ;
if ( V_215 > ( V_217 / sizeof( struct V_87 ) ) )
return NULL ;
V_216 = V_215 * sizeof( struct V_87 ) ;
V_26 = ( void * ) F_221 ( V_219 | V_220 | V_221 ,
F_191 ( V_216 ) ) ;
if ( ! V_26 )
V_26 = F_222 ( V_216 ) ;
if ( V_26 && V_214 )
for ( V_12 = 0 ; V_12 < V_215 ; V_12 ++ )
F_223 ( & V_26 [ V_12 ] , V_12 ) ;
return V_26 ;
}
int F_224 ( unsigned int V_222 )
{
int V_12 , V_90 ;
unsigned int V_223 ;
struct V_87 * V_26 , * V_224 ;
struct V_85 * V_86 ;
struct V_48 * V_49 ;
if ( ! V_222 )
return - V_194 ;
V_26 = F_219 ( & V_222 , 1 ) ;
if ( ! V_26 )
return - V_160 ;
V_223 = V_27 ;
if ( V_223 == V_222 ) {
F_187 ( V_26 , V_222 ) ;
return 0 ;
}
F_58 () ;
F_10 () ;
F_225 ( & V_11 ) ;
for ( V_12 = 0 ; V_12 < V_27 ; V_12 ++ ) {
while ( ! F_226 ( & V_94 [ V_12 ] ) ) {
V_86 = F_227 ( V_94 [ V_12 ] . V_225 ,
struct V_85 , V_51 ) ;
V_49 = F_73 ( V_86 ) ;
F_30 ( & V_86 -> V_51 ) ;
V_90 = F_19 ( F_35 ( V_49 ) ,
& V_86 -> V_14 , V_222 ) ;
F_93 ( & V_86 -> V_51 , & V_26 [ V_90 ] ) ;
}
}
V_223 = V_27 ;
V_224 = V_94 ;
V_94 = V_26 ;
V_27 = V_222 ;
F_228 ( & V_11 ) ;
F_11 () ;
F_59 () ;
F_179 () ;
F_187 ( V_224 , V_223 ) ;
return 0 ;
}
int F_229 ( const char * V_226 , struct V_227 * V_228 )
{
unsigned int V_222 ;
int V_229 ;
if ( V_230 -> V_231 -> V_232 != & V_233 )
return - V_234 ;
if ( ! V_27 )
return F_230 ( V_226 , V_228 ) ;
V_229 = F_231 ( V_226 , 0 , & V_222 ) ;
if ( V_229 )
return V_229 ;
return F_224 ( V_222 ) ;
}
static T_8 unsigned int F_232 ( void )
{
F_128 ( V_235 > 9 ) ;
return sizeof( struct V_236 ) +
sizeof( struct V_114 )
#if F_233 ( V_237 )
+ sizeof( struct V_238 )
#endif
+ sizeof( struct V_239 )
+ sizeof( struct V_102 )
#ifdef F_234
+ sizeof( struct V_240 )
#endif
#ifdef F_235
+ sizeof( struct V_80 )
#endif
#ifdef F_236
+ sizeof( struct V_241 )
#endif
#ifdef F_237
+ sizeof( struct V_242 )
#endif
#if F_233 ( V_243 )
+ sizeof( struct V_244 )
#endif
;
}
int F_238 ( void )
{
int V_245 = 8 ;
int V_42 = - V_160 ;
int V_12 ;
F_128 ( F_232 () > 255u ) ;
F_239 ( & V_11 ) ;
for ( V_12 = 0 ; V_12 < V_6 ; V_12 ++ )
F_137 ( & V_7 [ V_12 ] ) ;
if ( ! V_27 ) {
V_27
= ( ( ( V_246 << V_247 ) / 16384 )
/ sizeof( struct V_203 ) ) ;
if ( V_246 > ( 4 * ( 1024 * 1024 * 1024 / V_218 ) ) )
V_27 = 65536 ;
else if ( V_246 > ( 1024 * 1024 * 1024 / V_218 ) )
V_27 = 16384 ;
if ( V_27 < 32 )
V_27 = 32 ;
V_245 = 4 ;
}
V_94 = F_219 ( & V_27 , 1 ) ;
if ( ! V_94 )
return - V_160 ;
V_150 = V_245 * V_27 ;
V_161 = F_240 ( L_13 ,
sizeof( struct V_48 ) ,
V_65 + 1 ,
V_248 | V_249 , NULL ) ;
if ( ! V_161 )
goto V_250;
F_241 ( V_251 L_14 ,
V_252 , V_27 ,
V_150 ) ;
V_42 = F_242 () ;
if ( V_42 < 0 )
goto V_253;
V_42 = F_243 () ;
if ( V_42 < 0 )
goto V_254;
V_42 = F_244 () ;
if ( V_42 < 0 )
goto V_255;
V_42 = F_245 () ;
if ( V_42 < 0 )
goto V_256;
V_42 = F_246 () ;
if ( V_42 < 0 )
goto V_257;
V_42 = F_247 () ;
if ( V_42 < 0 )
goto V_258;
V_42 = F_248 () ;
if ( V_42 < 0 )
goto V_259;
V_42 = F_249 () ;
if ( V_42 < 0 )
goto V_260;
V_42 = F_250 () ;
if ( V_42 < 0 )
goto V_261;
F_130 ( & V_143 ) ;
F_129 ( V_157 , & V_143 . V_148 , V_137 ) ;
return 0 ;
V_261:
F_197 () ;
V_260:
F_198 () ;
V_259:
F_199 () ;
V_258:
F_200 () ;
V_257:
F_201 () ;
V_256:
F_202 () ;
V_255:
F_203 () ;
V_254:
F_204 () ;
V_253:
F_205 ( V_161 ) ;
V_250:
F_187 ( V_94 , V_27 ) ;
return V_42 ;
}
void F_251 ( void )
{
F_193 ( V_204 , F_163 ) ;
F_193 ( V_205 , F_51 ) ;
}
int F_252 ( struct V_8 * V_8 )
{
int V_42 = - V_160 ;
int V_55 ;
F_128 ( V_172 == V_262 ) ;
F_46 ( & V_8 -> V_49 . V_152 , 0 ) ;
V_8 -> V_49 . V_56 = F_253 ( struct V_53 ) ;
if ( ! V_8 -> V_49 . V_56 )
goto V_263;
F_173 (cpu) {
struct V_53 * V_54 = F_34 ( V_8 -> V_49 . V_56 , V_55 ) ;
F_137 ( & V_54 -> V_1 ) ;
F_223 ( & V_54 -> V_58 , V_264 ) ;
F_223 ( & V_54 -> V_57 , V_265 ) ;
}
V_8 -> V_49 . V_212 = F_253 ( struct V_266 ) ;
if ( ! V_8 -> V_49 . V_212 )
goto V_267;
V_42 = F_254 ( V_8 ) ;
if ( V_42 < 0 )
goto V_253;
V_42 = F_255 ( V_8 ) ;
if ( V_42 < 0 )
goto V_254;
V_42 = F_256 ( V_8 ) ;
if ( V_42 < 0 )
goto V_255;
V_42 = F_257 ( V_8 ) ;
if ( V_42 < 0 )
goto V_256;
V_42 = F_258 ( V_8 ) ;
if ( V_42 < 0 )
goto V_258;
V_42 = F_259 ( V_8 ) ;
if ( V_42 < 0 )
goto V_261;
return 0 ;
V_261:
F_213 ( V_8 ) ;
V_258:
F_214 ( V_8 ) ;
V_256:
F_215 ( V_8 ) ;
V_255:
F_216 ( V_8 ) ;
V_254:
F_217 ( V_8 ) ;
V_253:
F_218 ( V_8 -> V_49 . V_212 ) ;
V_267:
F_218 ( V_8 -> V_49 . V_56 ) ;
V_263:
return V_42 ;
}
