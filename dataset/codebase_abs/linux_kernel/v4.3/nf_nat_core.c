inline const struct V_1 *
F_1 ( T_1 V_2 )
{
return F_2 ( V_3 [ V_2 ] ) ;
}
inline const struct V_4 *
F_3 ( T_1 V_2 , T_1 V_5 )
{
return F_2 ( V_6 [ V_2 ] [ V_5 ] ) ;
}
static void F_4 ( struct V_7 * V_8 , struct V_9 * V_10 )
{
const struct V_1 * V_11 ;
const struct V_12 * V_13 ;
enum V_14 V_15 ;
enum V_16 V_17 ;
unsigned long V_18 ;
T_1 V_2 ;
V_13 = F_5 ( V_8 , & V_15 ) ;
if ( V_13 == NULL )
return;
V_2 = V_13 -> V_19 [ V_20 ] . V_21 . V_22 . V_23 ;
F_6 () ;
V_11 = F_1 ( V_2 ) ;
if ( V_11 == NULL )
goto V_24;
V_17 = F_7 ( V_15 ) ;
if ( V_17 == V_20 )
V_18 = V_25 ;
else
V_18 = V_26 ;
V_11 -> V_27 ( V_8 , V_13 , V_17 , V_18 , V_10 ) ;
V_24:
F_8 () ;
}
int F_9 ( struct V_7 * V_8 , unsigned int V_2 )
{
struct V_9 V_10 ;
unsigned int V_28 ;
struct V_29 * V_30 ;
int V_31 ;
V_31 = F_10 ( V_8 , & V_10 , V_2 ) ;
if ( V_31 < 0 )
return V_31 ;
V_30 = F_11 ( V_8 ) ;
if ( V_30 -> V_32 )
V_30 = ( (struct V_33 * ) V_30 ) -> V_34 ;
F_12 ( V_30 ) ;
V_30 = F_13 ( F_14 ( V_30 -> V_35 ) , V_30 , & V_10 , V_8 -> V_36 , 0 ) ;
if ( F_15 ( V_30 ) )
return F_16 ( V_30 ) ;
F_17 ( V_8 ) ;
F_18 ( V_8 , V_30 ) ;
V_28 = F_11 ( V_8 ) -> V_35 -> V_37 ;
if ( F_19 ( V_8 ) < V_28 &&
F_20 ( V_8 , V_28 - F_19 ( V_8 ) , 0 , V_38 ) )
return - V_39 ;
return 0 ;
}
static inline unsigned int
F_21 ( const struct V_40 * V_40 , const struct V_41 * V_21 )
{
unsigned int V_42 ;
V_42 = F_22 ( ( V_43 * ) & V_21 -> V_22 , sizeof( V_21 -> V_22 ) / sizeof( V_43 ) ,
V_21 -> V_30 . V_5 ^ V_44 ) ;
return F_23 ( V_42 , V_40 -> V_13 . V_45 ) ;
}
int
F_24 ( const struct V_41 * V_21 ,
const struct V_12 * V_46 )
{
struct V_41 V_47 ;
F_25 ( & V_47 , V_21 ) ;
return F_26 ( & V_47 , V_46 ) ;
}
static int F_27 ( const struct V_1 * V_11 ,
const struct V_4 * V_48 ,
const struct V_41 * V_21 ,
const struct V_49 * V_50 )
{
if ( V_50 -> V_51 & V_52 &&
! V_11 -> F_27 ( V_21 , V_50 ) )
return 0 ;
if ( ! ( V_50 -> V_51 & V_53 ) ||
V_48 -> F_27 ( V_21 , V_54 ,
& V_50 -> V_55 , & V_50 -> V_56 ) )
return 1 ;
return 0 ;
}
static inline int
F_28 ( const struct V_12 * V_13 ,
const struct V_41 * V_21 )
{
const struct V_41 * V_57 ;
V_57 = & V_13 -> V_19 [ V_20 ] . V_21 ;
return ( V_57 -> V_30 . V_5 == V_21 -> V_30 . V_5 &&
F_29 ( & V_57 -> V_22 . V_58 , & V_21 -> V_22 . V_58 ) &&
V_57 -> V_22 . V_59 . V_60 == V_21 -> V_22 . V_59 . V_60 ) ;
}
static int
F_30 ( struct V_40 * V_40 ,
const struct V_61 * V_62 ,
const struct V_1 * V_11 ,
const struct V_4 * V_48 ,
const struct V_41 * V_21 ,
struct V_41 * V_63 ,
const struct V_49 * V_50 )
{
unsigned int V_64 = F_21 ( V_40 , V_21 ) ;
const struct V_65 * V_66 ;
const struct V_12 * V_13 ;
F_31 (nat, &net->ct.nat_bysource[h], bysource) {
V_13 = V_66 -> V_13 ;
if ( F_28 ( V_13 , V_21 ) &&
F_32 ( V_13 , V_62 , V_20 ) ) {
F_25 ( V_63 ,
& V_13 -> V_19 [ V_67 ] . V_21 ) ;
V_63 -> V_30 = V_21 -> V_30 ;
if ( F_27 ( V_11 , V_48 , V_63 , V_50 ) )
return 1 ;
}
}
return 0 ;
}
static void
F_33 ( const struct V_61 * V_62 ,
struct V_41 * V_21 ,
const struct V_49 * V_50 ,
const struct V_12 * V_13 ,
enum V_68 V_69 )
{
union V_70 * V_71 ;
unsigned int V_72 , V_73 ;
V_43 V_74 , V_75 , V_76 , V_77 ;
bool V_78 ;
if ( ! ( V_50 -> V_51 & V_52 ) )
return;
if ( V_69 == V_54 )
V_71 = & V_21 -> V_22 . V_58 ;
else
V_71 = & V_21 -> V_30 . V_58 ;
if ( F_29 ( & V_50 -> V_79 , & V_50 -> V_80 ) ) {
* V_71 = V_50 -> V_79 ;
return;
}
if ( F_34 ( V_13 ) == V_81 )
V_73 = sizeof( V_71 -> V_82 ) / sizeof( V_43 ) - 1 ;
else
V_73 = sizeof( V_71 -> V_83 ) / sizeof( V_43 ) - 1 ;
V_76 = F_22 ( ( V_43 * ) & V_21 -> V_22 . V_58 , sizeof( V_21 -> V_22 . V_58 ) / sizeof( V_43 ) ,
V_50 -> V_51 & V_84 ?
0 : ( V_85 V_43 ) V_21 -> V_30 . V_58 . V_60 [ V_73 ] ^ V_62 -> V_86 ) ;
V_78 = false ;
for ( V_72 = 0 ; V_72 <= V_73 ; V_72 ++ ) {
if ( ! V_78 ) {
V_74 = F_35 ( ( V_85 V_87 ) V_50 -> V_79 . V_60 [ V_72 ] ) ;
V_75 = F_35 ( ( V_85 V_87 ) V_50 -> V_80 . V_60 [ V_72 ] ) ;
V_77 = V_75 - V_74 + 1 ;
} else {
V_74 = 0 ;
V_77 = ~ 0 ;
}
V_71 -> V_60 [ V_72 ] = ( V_85 V_88 )
F_36 ( V_74 + F_23 ( V_76 , V_77 ) ) ;
if ( V_71 -> V_60 [ V_72 ] != V_50 -> V_80 . V_60 [ V_72 ] )
V_78 = true ;
if ( ! ( V_50 -> V_51 & V_84 ) )
V_76 ^= ( V_85 V_43 ) V_21 -> V_30 . V_58 . V_60 [ V_72 ] ;
}
}
static void
F_37 ( struct V_41 * V_21 ,
const struct V_41 * V_89 ,
const struct V_49 * V_50 ,
struct V_12 * V_13 ,
enum V_68 V_69 )
{
const struct V_61 * V_62 ;
const struct V_1 * V_11 ;
const struct V_4 * V_48 ;
struct V_40 * V_40 = F_38 ( V_13 ) ;
V_62 = F_39 ( V_13 ) ;
F_6 () ;
V_11 = F_1 ( V_89 -> V_22 . V_23 ) ;
V_48 = F_3 ( V_89 -> V_22 . V_23 ,
V_89 -> V_30 . V_5 ) ;
if ( V_69 == V_54 &&
! ( V_50 -> V_51 & V_90 ) ) {
if ( F_27 ( V_11 , V_48 , V_89 , V_50 ) ) {
if ( ! F_24 ( V_89 , V_13 ) ) {
* V_21 = * V_89 ;
goto V_24;
}
} else if ( F_30 ( V_40 , V_62 , V_11 , V_48 ,
V_89 , V_21 , V_50 ) ) {
F_40 ( L_1 ) ;
if ( ! F_24 ( V_21 , V_13 ) )
goto V_24;
}
}
* V_21 = * V_89 ;
F_33 ( V_62 , V_21 , V_50 , V_13 , V_69 ) ;
if ( ! ( V_50 -> V_51 & V_90 ) ) {
if ( V_50 -> V_51 & V_53 ) {
if ( V_48 -> F_27 ( V_21 , V_69 ,
& V_50 -> V_55 ,
& V_50 -> V_56 ) &&
( V_50 -> V_55 . V_60 == V_50 -> V_56 . V_60 ||
! F_24 ( V_21 , V_13 ) ) )
goto V_24;
} else if ( ! F_24 ( V_21 , V_13 ) ) {
goto V_24;
}
}
V_48 -> V_91 ( V_11 , V_21 , V_50 , V_69 , V_13 ) ;
V_24:
F_8 () ;
}
struct V_65 * F_41 ( struct V_12 * V_13 )
{
struct V_65 * V_66 = F_42 ( V_13 ) ;
if ( V_66 )
return V_66 ;
if ( ! F_43 ( V_13 ) )
V_66 = F_44 ( V_13 , V_92 , V_38 ) ;
return V_66 ;
}
unsigned int
F_45 ( struct V_12 * V_13 ,
const struct V_49 * V_50 ,
enum V_68 V_69 )
{
struct V_40 * V_40 = F_38 ( V_13 ) ;
struct V_41 V_93 , V_94 ;
struct V_65 * V_66 ;
V_66 = F_41 ( V_13 ) ;
if ( V_66 == NULL )
return V_95 ;
F_46 ( V_69 == V_54 ||
V_69 == V_96 ) ;
F_47 ( F_48 ( V_13 , V_69 ) ) ;
F_25 ( & V_93 ,
& V_13 -> V_19 [ V_67 ] . V_21 ) ;
F_37 ( & V_94 , & V_93 , V_50 , V_13 , V_69 ) ;
if ( ! F_49 ( & V_94 , & V_93 ) ) {
struct V_41 V_47 ;
F_25 ( & V_47 , & V_94 ) ;
F_50 ( V_13 , & V_47 ) ;
if ( V_69 == V_54 )
V_13 -> V_97 |= V_26 ;
else
V_13 -> V_97 |= V_25 ;
if ( F_51 ( V_13 ) )
F_52 ( V_13 ) ;
}
if ( V_69 == V_54 ) {
unsigned int V_98 ;
V_98 = F_21 ( V_40 ,
& V_13 -> V_19 [ V_20 ] . V_21 ) ;
F_53 ( & V_99 ) ;
V_66 = F_42 ( V_13 ) ;
V_66 -> V_13 = V_13 ;
F_54 ( & V_66 -> V_100 ,
& V_40 -> V_13 . V_101 [ V_98 ] ) ;
F_55 ( & V_99 ) ;
}
if ( V_69 == V_96 )
V_13 -> V_97 |= V_102 ;
else
V_13 -> V_97 |= V_103 ;
return V_95 ;
}
static unsigned int
F_56 ( struct V_12 * V_13 , enum V_68 V_104 )
{
union V_70 V_82 =
( V_104 == V_54 ?
V_13 -> V_19 [ V_67 ] . V_21 . V_30 . V_58 :
V_13 -> V_19 [ V_67 ] . V_21 . V_22 . V_58 ) ;
struct V_49 V_50 = {
. V_51 = V_52 ,
. V_79 = V_82 ,
. V_80 = V_82 ,
} ;
return F_45 ( V_13 , & V_50 , V_104 ) ;
}
unsigned int
F_57 ( struct V_12 * V_13 , unsigned int V_105 )
{
return F_56 ( V_13 , F_58 ( V_105 ) ) ;
}
unsigned int F_59 ( struct V_12 * V_13 ,
enum V_14 V_15 ,
unsigned int V_105 ,
struct V_7 * V_8 )
{
const struct V_1 * V_11 ;
const struct V_4 * V_48 ;
enum V_16 V_17 = F_7 ( V_15 ) ;
unsigned long V_18 ;
enum V_68 V_106 = F_58 ( V_105 ) ;
if ( V_106 == V_54 )
V_18 = V_26 ;
else
V_18 = V_25 ;
if ( V_17 == V_67 )
V_18 ^= V_107 ;
if ( V_13 -> V_97 & V_18 ) {
struct V_41 V_108 ;
F_25 ( & V_108 , & V_13 -> V_19 [ ! V_17 ] . V_21 ) ;
V_11 = F_1 ( V_108 . V_22 . V_23 ) ;
V_48 = F_3 ( V_108 . V_22 . V_23 ,
V_108 . V_30 . V_5 ) ;
if ( ! V_11 -> V_109 ( V_8 , 0 , V_48 , & V_108 , V_106 ) )
return V_110 ;
}
return V_95 ;
}
static int F_60 ( struct V_12 * V_72 , void * V_111 )
{
const struct V_112 * V_113 = V_111 ;
struct V_65 * V_66 = F_42 ( V_72 ) ;
if ( ! V_66 )
return 0 ;
if ( ( V_113 -> V_11 && F_34 ( V_72 ) != V_113 -> V_11 ) ||
( V_113 -> V_48 && F_61 ( V_72 ) != V_113 -> V_48 ) )
return 0 ;
return V_72 -> V_97 & V_107 ? 1 : 0 ;
}
static int V_112 ( struct V_12 * V_13 , void * V_111 )
{
struct V_65 * V_66 = F_42 ( V_13 ) ;
if ( F_60 ( V_13 , V_111 ) )
return 1 ;
if ( ! V_66 || ! V_66 -> V_13 )
return 0 ;
if ( ! F_62 ( & V_13 -> V_114 ) )
return 1 ;
F_53 ( & V_99 ) ;
F_63 ( & V_66 -> V_100 ) ;
V_13 -> V_97 &= ~ V_115 ;
V_66 -> V_13 = NULL ;
F_55 ( & V_99 ) ;
F_64 ( & V_13 -> V_114 ) ;
return 0 ;
}
static void F_65 ( T_1 V_11 , T_1 V_48 )
{
struct V_112 V_113 = {
. V_11 = V_11 ,
. V_48 = V_48 ,
} ;
struct V_40 * V_40 ;
F_66 () ;
F_67 (net)
F_68 ( V_40 , F_60 , & V_113 , 0 , 0 ) ;
F_69 () ;
}
static void F_70 ( T_1 V_11 )
{
struct V_112 V_113 = {
. V_11 = V_11 ,
} ;
struct V_40 * V_40 ;
F_66 () ;
F_67 (net)
F_68 ( V_40 , F_60 , & V_113 , 0 , 0 ) ;
F_69 () ;
}
int F_71 ( T_1 V_11 , const struct V_4 * V_48 )
{
const struct V_4 * * V_116 ;
unsigned int V_72 ;
int V_117 = 0 ;
F_72 ( & V_118 ) ;
if ( V_6 [ V_11 ] == NULL ) {
V_116 = F_73 ( V_119 * sizeof( struct V_4 * ) ,
V_120 ) ;
if ( V_116 == NULL ) {
V_117 = - V_39 ;
goto V_24;
}
for ( V_72 = 0 ; V_72 < V_119 ; V_72 ++ )
F_74 ( V_116 [ V_72 ] , & V_121 ) ;
F_75 () ;
V_6 [ V_11 ] = V_116 ;
}
if ( F_76 (
V_6 [ V_11 ] [ V_48 -> V_48 ] ,
F_77 ( & V_118 )
) != & V_121 ) {
V_117 = - V_122 ;
goto V_24;
}
F_74 ( V_6 [ V_11 ] [ V_48 -> V_48 ] , V_48 ) ;
V_24:
F_78 ( & V_118 ) ;
return V_117 ;
}
void F_79 ( T_1 V_11 , const struct V_4 * V_48 )
{
F_72 ( & V_118 ) ;
F_74 ( V_6 [ V_11 ] [ V_48 -> V_48 ] ,
& V_121 ) ;
F_78 ( & V_118 ) ;
F_80 () ;
F_65 ( V_11 , V_48 -> V_48 ) ;
}
int F_81 ( const struct V_1 * V_11 )
{
int V_31 ;
V_31 = F_82 ( V_11 -> V_11 ) ;
if ( V_31 < 0 )
return V_31 ;
F_72 ( & V_118 ) ;
F_74 ( V_6 [ V_11 -> V_11 ] [ V_123 ] ,
& V_124 ) ;
F_74 ( V_6 [ V_11 -> V_11 ] [ V_125 ] ,
& V_126 ) ;
F_78 ( & V_118 ) ;
F_74 ( V_3 [ V_11 -> V_11 ] , V_11 ) ;
return 0 ;
}
void F_83 ( const struct V_1 * V_11 )
{
F_72 ( & V_118 ) ;
F_74 ( V_3 [ V_11 -> V_11 ] , NULL ) ;
F_78 ( & V_118 ) ;
F_80 () ;
F_70 ( V_11 -> V_11 ) ;
F_84 ( V_11 -> V_11 ) ;
}
static void F_85 ( struct V_12 * V_13 )
{
struct V_65 * V_66 = F_86 ( V_13 , V_92 ) ;
if ( V_66 == NULL || V_66 -> V_13 == NULL )
return;
F_46 ( V_66 -> V_13 -> V_97 & V_103 ) ;
F_53 ( & V_99 ) ;
F_63 ( & V_66 -> V_100 ) ;
F_55 ( & V_99 ) ;
}
static void F_87 ( void * V_127 , void * V_128 )
{
struct V_65 * V_129 = V_127 ;
struct V_65 * V_130 = V_128 ;
struct V_12 * V_13 = V_130 -> V_13 ;
if ( ! V_13 || ! ( V_13 -> V_97 & V_103 ) )
return;
F_53 ( & V_99 ) ;
F_88 ( & V_130 -> V_100 , & V_129 -> V_100 ) ;
F_55 ( & V_99 ) ;
}
static int F_89 ( struct V_131 * V_132 ,
const struct V_12 * V_13 ,
struct V_49 * V_50 )
{
struct V_131 * V_133 [ V_134 + 1 ] ;
const struct V_4 * V_48 ;
int V_31 ;
V_31 = F_90 ( V_133 , V_134 , V_132 , V_135 ) ;
if ( V_31 < 0 )
return V_31 ;
V_48 = F_3 ( F_34 ( V_13 ) , F_61 ( V_13 ) ) ;
if ( V_48 -> V_136 )
V_31 = V_48 -> V_136 ( V_133 , V_50 ) ;
return V_31 ;
}
static int
F_91 ( const struct V_131 * V_66 ,
const struct V_12 * V_13 , struct V_49 * V_50 ,
const struct V_1 * V_11 )
{
struct V_131 * V_133 [ V_137 + 1 ] ;
int V_31 ;
memset ( V_50 , 0 , sizeof( * V_50 ) ) ;
V_31 = F_90 ( V_133 , V_137 , V_66 , V_138 ) ;
if ( V_31 < 0 )
return V_31 ;
V_31 = V_11 -> V_136 ( V_133 , V_50 ) ;
if ( V_31 < 0 )
return V_31 ;
if ( ! V_133 [ V_139 ] )
return 0 ;
return F_89 ( V_133 [ V_139 ] , V_13 , V_50 ) ;
}
static int
F_92 ( struct V_12 * V_13 ,
enum V_68 V_104 ,
const struct V_131 * V_132 )
{
struct V_49 V_50 ;
const struct V_1 * V_11 ;
int V_31 ;
if ( F_93 ( F_48 ( V_13 , V_104 ) ) )
return - V_140 ;
V_11 = F_1 ( F_34 ( V_13 ) ) ;
if ( V_11 == NULL )
return - V_141 ;
if ( V_132 == NULL )
return F_56 ( V_13 , V_104 ) ;
V_31 = F_91 ( V_132 , V_13 , & V_50 , V_11 ) ;
if ( V_31 < 0 )
return V_31 ;
return F_45 ( V_13 , & V_50 , V_104 ) ;
}
static int
F_92 ( struct V_12 * V_13 ,
enum V_68 V_104 ,
const struct V_131 * V_132 )
{
return - V_142 ;
}
static int T_2 F_94 ( struct V_40 * V_40 )
{
V_40 -> V_13 . V_45 = V_40 -> V_13 . V_143 ;
V_40 -> V_13 . V_101 = F_95 ( & V_40 -> V_13 . V_45 , 0 ) ;
if ( ! V_40 -> V_13 . V_101 )
return - V_39 ;
return 0 ;
}
static void T_3 F_96 ( struct V_40 * V_40 )
{
struct V_112 V_113 = {} ;
F_68 ( V_40 , V_112 , & V_113 , 0 , 0 ) ;
F_80 () ;
F_97 ( V_40 -> V_13 . V_101 , V_40 -> V_13 . V_45 ) ;
}
static int T_4 F_98 ( void )
{
int V_117 ;
V_117 = F_99 ( & V_144 ) ;
if ( V_117 < 0 ) {
F_100 ( V_145 L_2 ) ;
return V_117 ;
}
V_117 = F_101 ( & V_146 ) ;
if ( V_117 < 0 )
goto V_147;
F_102 ( & V_148 ) ;
F_103 ( V_115 ) ;
F_47 ( V_149 != NULL ) ;
F_74 ( V_149 ,
F_92 ) ;
#ifdef F_104
F_47 ( V_150 != NULL ) ;
F_74 ( V_150 , F_4 ) ;
#endif
return 0 ;
V_147:
F_105 ( & V_144 ) ;
return V_117 ;
}
static void T_5 F_106 ( void )
{
unsigned int V_72 ;
F_107 ( & V_146 ) ;
F_105 ( & V_144 ) ;
F_108 ( & V_148 ) ;
F_74 ( V_149 , NULL ) ;
#ifdef F_104
F_74 ( V_150 , NULL ) ;
#endif
for ( V_72 = 0 ; V_72 < V_151 ; V_72 ++ )
F_109 ( V_6 [ V_72 ] ) ;
F_110 () ;
}
