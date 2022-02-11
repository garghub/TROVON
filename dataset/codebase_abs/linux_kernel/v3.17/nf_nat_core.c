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
F_21 ( const struct V_40 * V_40 , T_2 V_41 ,
const struct V_42 * V_21 )
{
unsigned int V_43 ;
V_43 = F_22 ( ( V_44 * ) & V_21 -> V_22 , sizeof( V_21 -> V_22 ) / sizeof( V_44 ) ,
V_21 -> V_30 . V_5 ^ V_41 ^ V_45 ) ;
return ( ( V_46 ) V_43 * V_40 -> V_13 . V_47 ) >> 32 ;
}
int
F_23 ( const struct V_42 * V_21 ,
const struct V_12 * V_48 )
{
struct V_42 V_49 ;
F_24 ( & V_49 , V_21 ) ;
return F_25 ( & V_49 , V_48 ) ;
}
static int F_26 ( const struct V_1 * V_11 ,
const struct V_4 * V_50 ,
const struct V_42 * V_21 ,
const struct V_51 * V_52 )
{
if ( V_52 -> V_53 & V_54 &&
! V_11 -> F_26 ( V_21 , V_52 ) )
return 0 ;
if ( ! ( V_52 -> V_53 & V_55 ) ||
V_50 -> F_26 ( V_21 , V_56 ,
& V_52 -> V_57 , & V_52 -> V_58 ) )
return 1 ;
return 0 ;
}
static inline int
F_27 ( const struct V_12 * V_13 ,
const struct V_42 * V_21 )
{
const struct V_42 * V_59 ;
V_59 = & V_13 -> V_19 [ V_20 ] . V_21 ;
return ( V_59 -> V_30 . V_5 == V_21 -> V_30 . V_5 &&
F_28 ( & V_59 -> V_22 . V_60 , & V_21 -> V_22 . V_60 ) &&
V_59 -> V_22 . V_61 . V_62 == V_21 -> V_22 . V_61 . V_62 ) ;
}
static int
F_29 ( struct V_40 * V_40 , T_2 V_41 ,
const struct V_1 * V_11 ,
const struct V_4 * V_50 ,
const struct V_42 * V_21 ,
struct V_42 * V_63 ,
const struct V_51 * V_52 )
{
unsigned int V_64 = F_21 ( V_40 , V_41 , V_21 ) ;
const struct V_65 * V_66 ;
const struct V_12 * V_13 ;
F_30 (nat, &net->ct.nat_bysource[h], bysource) {
V_13 = V_66 -> V_13 ;
if ( F_27 ( V_13 , V_21 ) && F_31 ( V_13 ) == V_41 ) {
F_24 ( V_63 ,
& V_13 -> V_19 [ V_67 ] . V_21 ) ;
V_63 -> V_30 = V_21 -> V_30 ;
if ( F_26 ( V_11 , V_50 , V_63 , V_52 ) )
return 1 ;
}
}
return 0 ;
}
static void
F_32 ( T_2 V_41 , struct V_42 * V_21 ,
const struct V_51 * V_52 ,
const struct V_12 * V_13 ,
enum V_68 V_69 )
{
union V_70 * V_71 ;
unsigned int V_72 , V_73 ;
V_44 V_74 , V_75 , V_76 , V_77 ;
bool V_78 ;
if ( ! ( V_52 -> V_53 & V_54 ) )
return;
if ( V_69 == V_56 )
V_71 = & V_21 -> V_22 . V_60 ;
else
V_71 = & V_21 -> V_30 . V_60 ;
if ( F_28 ( & V_52 -> V_79 , & V_52 -> V_80 ) ) {
* V_71 = V_52 -> V_79 ;
return;
}
if ( F_33 ( V_13 ) == V_81 )
V_73 = sizeof( V_71 -> V_82 ) / sizeof( V_44 ) - 1 ;
else
V_73 = sizeof( V_71 -> V_83 ) / sizeof( V_44 ) - 1 ;
V_76 = F_22 ( ( V_44 * ) & V_21 -> V_22 . V_60 , sizeof( V_21 -> V_22 . V_60 ) / sizeof( V_44 ) ,
V_52 -> V_53 & V_84 ?
0 : ( V_85 V_44 ) V_21 -> V_30 . V_60 . V_62 [ V_73 ] ^ V_41 ) ;
V_78 = false ;
for ( V_72 = 0 ; V_72 <= V_73 ; V_72 ++ ) {
if ( ! V_78 ) {
V_74 = F_34 ( ( V_85 V_86 ) V_52 -> V_79 . V_62 [ V_72 ] ) ;
V_75 = F_34 ( ( V_85 V_86 ) V_52 -> V_80 . V_62 [ V_72 ] ) ;
V_77 = V_75 - V_74 + 1 ;
} else {
V_74 = 0 ;
V_77 = ~ 0 ;
}
V_71 -> V_62 [ V_72 ] = ( V_85 V_87 )
F_35 ( V_74 + ( ( ( V_46 ) V_76 * V_77 ) >> 32 ) ) ;
if ( V_71 -> V_62 [ V_72 ] != V_52 -> V_80 . V_62 [ V_72 ] )
V_78 = true ;
if ( ! ( V_52 -> V_53 & V_84 ) )
V_76 ^= ( V_85 V_44 ) V_21 -> V_30 . V_60 . V_62 [ V_72 ] ;
}
}
static void
F_36 ( struct V_42 * V_21 ,
const struct V_42 * V_88 ,
const struct V_51 * V_52 ,
struct V_12 * V_13 ,
enum V_68 V_69 )
{
const struct V_1 * V_11 ;
const struct V_4 * V_50 ;
struct V_40 * V_40 = F_37 ( V_13 ) ;
T_2 V_41 = F_31 ( V_13 ) ;
F_6 () ;
V_11 = F_1 ( V_88 -> V_22 . V_23 ) ;
V_50 = F_3 ( V_88 -> V_22 . V_23 ,
V_88 -> V_30 . V_5 ) ;
if ( V_69 == V_56 &&
! ( V_52 -> V_53 & V_89 ) ) {
if ( F_26 ( V_11 , V_50 , V_88 , V_52 ) ) {
if ( ! F_23 ( V_88 , V_13 ) ) {
* V_21 = * V_88 ;
goto V_24;
}
} else if ( F_29 ( V_40 , V_41 , V_11 , V_50 ,
V_88 , V_21 , V_52 ) ) {
F_38 ( L_1 ) ;
if ( ! F_23 ( V_21 , V_13 ) )
goto V_24;
}
}
* V_21 = * V_88 ;
F_32 ( V_41 , V_21 , V_52 , V_13 , V_69 ) ;
if ( ! ( V_52 -> V_53 & V_89 ) ) {
if ( V_52 -> V_53 & V_55 ) {
if ( V_50 -> F_26 ( V_21 , V_69 ,
& V_52 -> V_57 ,
& V_52 -> V_58 ) &&
( V_52 -> V_57 . V_62 == V_52 -> V_58 . V_62 ||
! F_23 ( V_21 , V_13 ) ) )
goto V_24;
} else if ( ! F_23 ( V_21 , V_13 ) ) {
goto V_24;
}
}
V_50 -> V_90 ( V_11 , V_21 , V_52 , V_69 , V_13 ) ;
V_24:
F_8 () ;
}
struct V_65 * F_39 ( struct V_12 * V_13 )
{
struct V_65 * V_66 = F_40 ( V_13 ) ;
if ( V_66 )
return V_66 ;
if ( ! F_41 ( V_13 ) )
V_66 = F_42 ( V_13 , V_91 , V_38 ) ;
return V_66 ;
}
unsigned int
F_43 ( struct V_12 * V_13 ,
const struct V_51 * V_52 ,
enum V_68 V_69 )
{
struct V_40 * V_40 = F_37 ( V_13 ) ;
struct V_42 V_92 , V_93 ;
struct V_65 * V_66 ;
V_66 = F_39 ( V_13 ) ;
if ( V_66 == NULL )
return V_94 ;
F_44 ( V_69 == V_56 ||
V_69 == V_95 ) ;
F_45 ( F_46 ( V_13 , V_69 ) ) ;
F_24 ( & V_92 ,
& V_13 -> V_19 [ V_67 ] . V_21 ) ;
F_36 ( & V_93 , & V_92 , V_52 , V_13 , V_69 ) ;
if ( ! F_47 ( & V_93 , & V_92 ) ) {
struct V_42 V_49 ;
F_24 ( & V_49 , & V_93 ) ;
F_48 ( V_13 , & V_49 ) ;
if ( V_69 == V_56 )
V_13 -> V_96 |= V_26 ;
else
V_13 -> V_96 |= V_25 ;
if ( F_49 ( V_13 ) )
F_50 ( V_13 ) ;
}
if ( V_69 == V_56 ) {
unsigned int V_97 ;
V_97 = F_21 ( V_40 , F_31 ( V_13 ) ,
& V_13 -> V_19 [ V_20 ] . V_21 ) ;
F_51 ( & V_98 ) ;
V_66 = F_40 ( V_13 ) ;
V_66 -> V_13 = V_13 ;
F_52 ( & V_66 -> V_99 ,
& V_40 -> V_13 . V_100 [ V_97 ] ) ;
F_53 ( & V_98 ) ;
}
if ( V_69 == V_95 )
V_13 -> V_96 |= V_101 ;
else
V_13 -> V_96 |= V_102 ;
return V_94 ;
}
static unsigned int
F_54 ( struct V_12 * V_13 , enum V_68 V_103 )
{
union V_70 V_82 =
( V_103 == V_56 ?
V_13 -> V_19 [ V_67 ] . V_21 . V_30 . V_60 :
V_13 -> V_19 [ V_67 ] . V_21 . V_22 . V_60 ) ;
struct V_51 V_52 = {
. V_53 = V_54 ,
. V_79 = V_82 ,
. V_80 = V_82 ,
} ;
return F_43 ( V_13 , & V_52 , V_103 ) ;
}
unsigned int
F_55 ( struct V_12 * V_13 , unsigned int V_104 )
{
return F_54 ( V_13 , F_56 ( V_104 ) ) ;
}
unsigned int F_57 ( struct V_12 * V_13 ,
enum V_14 V_15 ,
unsigned int V_104 ,
struct V_7 * V_8 )
{
const struct V_1 * V_11 ;
const struct V_4 * V_50 ;
enum V_16 V_17 = F_7 ( V_15 ) ;
unsigned long V_18 ;
enum V_68 V_105 = F_56 ( V_104 ) ;
if ( V_105 == V_56 )
V_18 = V_26 ;
else
V_18 = V_25 ;
if ( V_17 == V_67 )
V_18 ^= V_106 ;
if ( V_13 -> V_96 & V_18 ) {
struct V_42 V_107 ;
F_24 ( & V_107 , & V_13 -> V_19 [ ! V_17 ] . V_21 ) ;
V_11 = F_1 ( V_107 . V_22 . V_23 ) ;
V_50 = F_3 ( V_107 . V_22 . V_23 ,
V_107 . V_30 . V_5 ) ;
if ( ! V_11 -> V_108 ( V_8 , 0 , V_50 , & V_107 , V_105 ) )
return V_109 ;
}
return V_94 ;
}
static int F_58 ( struct V_12 * V_72 , void * V_110 )
{
const struct V_111 * V_112 = V_110 ;
struct V_65 * V_66 = F_40 ( V_72 ) ;
if ( ! V_66 )
return 0 ;
if ( ( V_112 -> V_11 && F_33 ( V_72 ) != V_112 -> V_11 ) ||
( V_112 -> V_50 && F_59 ( V_72 ) != V_112 -> V_50 ) )
return 0 ;
return V_72 -> V_96 & V_106 ? 1 : 0 ;
}
static int V_111 ( struct V_12 * V_13 , void * V_110 )
{
struct V_65 * V_66 = F_40 ( V_13 ) ;
if ( F_58 ( V_13 , V_110 ) )
return 1 ;
if ( ! V_66 || ! V_66 -> V_13 )
return 0 ;
if ( ! F_60 ( & V_13 -> V_113 ) )
return 1 ;
F_51 ( & V_98 ) ;
F_61 ( & V_66 -> V_99 ) ;
V_13 -> V_96 &= ~ V_114 ;
V_66 -> V_13 = NULL ;
F_53 ( & V_98 ) ;
F_62 ( & V_13 -> V_113 ) ;
return 0 ;
}
static void F_63 ( T_1 V_11 , T_1 V_50 )
{
struct V_111 V_112 = {
. V_11 = V_11 ,
. V_50 = V_50 ,
} ;
struct V_40 * V_40 ;
F_64 () ;
F_65 (net)
F_66 ( V_40 , F_58 , & V_112 , 0 , 0 ) ;
F_67 () ;
}
static void F_68 ( T_1 V_11 )
{
struct V_111 V_112 = {
. V_11 = V_11 ,
} ;
struct V_40 * V_40 ;
F_64 () ;
F_65 (net)
F_66 ( V_40 , F_58 , & V_112 , 0 , 0 ) ;
F_67 () ;
}
int F_69 ( T_1 V_11 , const struct V_4 * V_50 )
{
const struct V_4 * * V_115 ;
unsigned int V_72 ;
int V_116 = 0 ;
F_70 ( & V_117 ) ;
if ( V_6 [ V_11 ] == NULL ) {
V_115 = F_71 ( V_118 * sizeof( struct V_4 * ) ,
V_119 ) ;
if ( V_115 == NULL ) {
V_116 = - V_39 ;
goto V_24;
}
for ( V_72 = 0 ; V_72 < V_118 ; V_72 ++ )
F_72 ( V_115 [ V_72 ] , & V_120 ) ;
F_73 () ;
V_6 [ V_11 ] = V_115 ;
}
if ( F_74 (
V_6 [ V_11 ] [ V_50 -> V_50 ] ,
F_75 ( & V_117 )
) != & V_120 ) {
V_116 = - V_121 ;
goto V_24;
}
F_72 ( V_6 [ V_11 ] [ V_50 -> V_50 ] , V_50 ) ;
V_24:
F_76 ( & V_117 ) ;
return V_116 ;
}
void F_77 ( T_1 V_11 , const struct V_4 * V_50 )
{
F_70 ( & V_117 ) ;
F_72 ( V_6 [ V_11 ] [ V_50 -> V_50 ] ,
& V_120 ) ;
F_76 ( & V_117 ) ;
F_78 () ;
F_63 ( V_11 , V_50 -> V_50 ) ;
}
int F_79 ( const struct V_1 * V_11 )
{
int V_31 ;
V_31 = F_80 ( V_11 -> V_11 ) ;
if ( V_31 < 0 )
return V_31 ;
F_70 ( & V_117 ) ;
F_72 ( V_6 [ V_11 -> V_11 ] [ V_122 ] ,
& V_123 ) ;
F_72 ( V_6 [ V_11 -> V_11 ] [ V_124 ] ,
& V_125 ) ;
F_76 ( & V_117 ) ;
F_72 ( V_3 [ V_11 -> V_11 ] , V_11 ) ;
return 0 ;
}
void F_81 ( const struct V_1 * V_11 )
{
F_70 ( & V_117 ) ;
F_72 ( V_3 [ V_11 -> V_11 ] , NULL ) ;
F_76 ( & V_117 ) ;
F_78 () ;
F_68 ( V_11 -> V_11 ) ;
F_82 ( V_11 -> V_11 ) ;
}
static void F_83 ( struct V_12 * V_13 )
{
struct V_65 * V_66 = F_84 ( V_13 , V_91 ) ;
if ( V_66 == NULL || V_66 -> V_13 == NULL )
return;
F_44 ( V_66 -> V_13 -> V_96 & V_102 ) ;
F_51 ( & V_98 ) ;
F_61 ( & V_66 -> V_99 ) ;
F_53 ( & V_98 ) ;
}
static void F_85 ( void * V_126 , void * V_127 )
{
struct V_65 * V_128 = V_126 ;
struct V_65 * V_129 = V_127 ;
struct V_12 * V_13 = V_129 -> V_13 ;
if ( ! V_13 || ! ( V_13 -> V_96 & V_102 ) )
return;
F_51 ( & V_98 ) ;
F_86 ( & V_129 -> V_99 , & V_128 -> V_99 ) ;
F_53 ( & V_98 ) ;
}
static int F_87 ( struct V_130 * V_131 ,
const struct V_12 * V_13 ,
struct V_51 * V_52 )
{
struct V_130 * V_132 [ V_133 + 1 ] ;
const struct V_4 * V_50 ;
int V_31 ;
V_31 = F_88 ( V_132 , V_133 , V_131 , V_134 ) ;
if ( V_31 < 0 )
return V_31 ;
V_50 = F_3 ( F_33 ( V_13 ) , F_59 ( V_13 ) ) ;
if ( V_50 -> V_135 )
V_31 = V_50 -> V_135 ( V_132 , V_52 ) ;
return V_31 ;
}
static int
F_89 ( const struct V_130 * V_66 ,
const struct V_12 * V_13 , struct V_51 * V_52 ,
const struct V_1 * V_11 )
{
struct V_130 * V_132 [ V_136 + 1 ] ;
int V_31 ;
memset ( V_52 , 0 , sizeof( * V_52 ) ) ;
V_31 = F_88 ( V_132 , V_136 , V_66 , V_137 ) ;
if ( V_31 < 0 )
return V_31 ;
V_31 = V_11 -> V_135 ( V_132 , V_52 ) ;
if ( V_31 < 0 )
return V_31 ;
if ( ! V_132 [ V_138 ] )
return 0 ;
return F_87 ( V_132 [ V_138 ] , V_13 , V_52 ) ;
}
static int
F_90 ( struct V_12 * V_13 ,
enum V_68 V_103 ,
const struct V_130 * V_131 )
{
struct V_51 V_52 ;
const struct V_1 * V_11 ;
int V_31 ;
if ( F_91 ( F_46 ( V_13 , V_103 ) ) )
return - V_139 ;
V_11 = F_1 ( F_33 ( V_13 ) ) ;
if ( V_11 == NULL )
return - V_140 ;
if ( V_131 == NULL )
return F_54 ( V_13 , V_103 ) ;
V_31 = F_89 ( V_131 , V_13 , & V_52 , V_11 ) ;
if ( V_31 < 0 )
return V_31 ;
return F_43 ( V_13 , & V_52 , V_103 ) ;
}
static int
F_90 ( struct V_12 * V_13 ,
enum V_68 V_103 ,
const struct V_130 * V_131 )
{
return - V_141 ;
}
static int T_3 F_92 ( struct V_40 * V_40 )
{
V_40 -> V_13 . V_47 = V_40 -> V_13 . V_142 ;
V_40 -> V_13 . V_100 = F_93 ( & V_40 -> V_13 . V_47 , 0 ) ;
if ( ! V_40 -> V_13 . V_100 )
return - V_39 ;
return 0 ;
}
static void T_4 F_94 ( struct V_40 * V_40 )
{
struct V_111 V_112 = {} ;
F_66 ( V_40 , V_111 , & V_112 , 0 , 0 ) ;
F_78 () ;
F_95 ( V_40 -> V_13 . V_100 , V_40 -> V_13 . V_47 ) ;
}
static int T_5 F_96 ( void )
{
int V_116 ;
V_116 = F_97 ( & V_143 ) ;
if ( V_116 < 0 ) {
F_98 ( V_144 L_2 ) ;
return V_116 ;
}
V_116 = F_99 ( & V_145 ) ;
if ( V_116 < 0 )
goto V_146;
F_100 ( & V_147 ) ;
F_101 ( V_114 ) ;
F_45 ( V_148 != NULL ) ;
F_72 ( V_148 ,
F_90 ) ;
#ifdef F_102
F_45 ( V_149 != NULL ) ;
F_72 ( V_149 , F_4 ) ;
#endif
return 0 ;
V_146:
F_103 ( & V_143 ) ;
return V_116 ;
}
static void T_6 F_104 ( void )
{
unsigned int V_72 ;
F_105 ( & V_145 ) ;
F_103 ( & V_143 ) ;
F_106 ( & V_147 ) ;
F_72 ( V_148 , NULL ) ;
#ifdef F_102
F_72 ( V_149 , NULL ) ;
#endif
for ( V_72 = 0 ; V_72 < V_150 ; V_72 ++ )
F_107 ( V_6 [ V_72 ] ) ;
F_108 () ;
}
