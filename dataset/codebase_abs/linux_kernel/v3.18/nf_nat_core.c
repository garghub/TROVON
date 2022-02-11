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
return F_23 ( V_43 , V_40 -> V_13 . V_46 ) ;
}
int
F_24 ( const struct V_42 * V_21 ,
const struct V_12 * V_47 )
{
struct V_42 V_48 ;
F_25 ( & V_48 , V_21 ) ;
return F_26 ( & V_48 , V_47 ) ;
}
static int F_27 ( const struct V_1 * V_11 ,
const struct V_4 * V_49 ,
const struct V_42 * V_21 ,
const struct V_50 * V_51 )
{
if ( V_51 -> V_52 & V_53 &&
! V_11 -> F_27 ( V_21 , V_51 ) )
return 0 ;
if ( ! ( V_51 -> V_52 & V_54 ) ||
V_49 -> F_27 ( V_21 , V_55 ,
& V_51 -> V_56 , & V_51 -> V_57 ) )
return 1 ;
return 0 ;
}
static inline int
F_28 ( const struct V_12 * V_13 ,
const struct V_42 * V_21 )
{
const struct V_42 * V_58 ;
V_58 = & V_13 -> V_19 [ V_20 ] . V_21 ;
return ( V_58 -> V_30 . V_5 == V_21 -> V_30 . V_5 &&
F_29 ( & V_58 -> V_22 . V_59 , & V_21 -> V_22 . V_59 ) &&
V_58 -> V_22 . V_60 . V_61 == V_21 -> V_22 . V_60 . V_61 ) ;
}
static int
F_30 ( struct V_40 * V_40 , T_2 V_41 ,
const struct V_1 * V_11 ,
const struct V_4 * V_49 ,
const struct V_42 * V_21 ,
struct V_42 * V_62 ,
const struct V_50 * V_51 )
{
unsigned int V_63 = F_21 ( V_40 , V_41 , V_21 ) ;
const struct V_64 * V_65 ;
const struct V_12 * V_13 ;
F_31 (nat, &net->ct.nat_bysource[h], bysource) {
V_13 = V_65 -> V_13 ;
if ( F_28 ( V_13 , V_21 ) && F_32 ( V_13 ) == V_41 ) {
F_25 ( V_62 ,
& V_13 -> V_19 [ V_66 ] . V_21 ) ;
V_62 -> V_30 = V_21 -> V_30 ;
if ( F_27 ( V_11 , V_49 , V_62 , V_51 ) )
return 1 ;
}
}
return 0 ;
}
static void
F_33 ( T_2 V_41 , struct V_42 * V_21 ,
const struct V_50 * V_51 ,
const struct V_12 * V_13 ,
enum V_67 V_68 )
{
union V_69 * V_70 ;
unsigned int V_71 , V_72 ;
V_44 V_73 , V_74 , V_75 , V_76 ;
bool V_77 ;
if ( ! ( V_51 -> V_52 & V_53 ) )
return;
if ( V_68 == V_55 )
V_70 = & V_21 -> V_22 . V_59 ;
else
V_70 = & V_21 -> V_30 . V_59 ;
if ( F_29 ( & V_51 -> V_78 , & V_51 -> V_79 ) ) {
* V_70 = V_51 -> V_78 ;
return;
}
if ( F_34 ( V_13 ) == V_80 )
V_72 = sizeof( V_70 -> V_81 ) / sizeof( V_44 ) - 1 ;
else
V_72 = sizeof( V_70 -> V_82 ) / sizeof( V_44 ) - 1 ;
V_75 = F_22 ( ( V_44 * ) & V_21 -> V_22 . V_59 , sizeof( V_21 -> V_22 . V_59 ) / sizeof( V_44 ) ,
V_51 -> V_52 & V_83 ?
0 : ( V_84 V_44 ) V_21 -> V_30 . V_59 . V_61 [ V_72 ] ^ V_41 ) ;
V_77 = false ;
for ( V_71 = 0 ; V_71 <= V_72 ; V_71 ++ ) {
if ( ! V_77 ) {
V_73 = F_35 ( ( V_84 V_85 ) V_51 -> V_78 . V_61 [ V_71 ] ) ;
V_74 = F_35 ( ( V_84 V_85 ) V_51 -> V_79 . V_61 [ V_71 ] ) ;
V_76 = V_74 - V_73 + 1 ;
} else {
V_73 = 0 ;
V_76 = ~ 0 ;
}
V_70 -> V_61 [ V_71 ] = ( V_84 V_86 )
F_36 ( V_73 + F_23 ( V_75 , V_76 ) ) ;
if ( V_70 -> V_61 [ V_71 ] != V_51 -> V_79 . V_61 [ V_71 ] )
V_77 = true ;
if ( ! ( V_51 -> V_52 & V_83 ) )
V_75 ^= ( V_84 V_44 ) V_21 -> V_30 . V_59 . V_61 [ V_71 ] ;
}
}
static void
F_37 ( struct V_42 * V_21 ,
const struct V_42 * V_87 ,
const struct V_50 * V_51 ,
struct V_12 * V_13 ,
enum V_67 V_68 )
{
const struct V_1 * V_11 ;
const struct V_4 * V_49 ;
struct V_40 * V_40 = F_38 ( V_13 ) ;
T_2 V_41 = F_32 ( V_13 ) ;
F_6 () ;
V_11 = F_1 ( V_87 -> V_22 . V_23 ) ;
V_49 = F_3 ( V_87 -> V_22 . V_23 ,
V_87 -> V_30 . V_5 ) ;
if ( V_68 == V_55 &&
! ( V_51 -> V_52 & V_88 ) ) {
if ( F_27 ( V_11 , V_49 , V_87 , V_51 ) ) {
if ( ! F_24 ( V_87 , V_13 ) ) {
* V_21 = * V_87 ;
goto V_24;
}
} else if ( F_30 ( V_40 , V_41 , V_11 , V_49 ,
V_87 , V_21 , V_51 ) ) {
F_39 ( L_1 ) ;
if ( ! F_24 ( V_21 , V_13 ) )
goto V_24;
}
}
* V_21 = * V_87 ;
F_33 ( V_41 , V_21 , V_51 , V_13 , V_68 ) ;
if ( ! ( V_51 -> V_52 & V_88 ) ) {
if ( V_51 -> V_52 & V_54 ) {
if ( V_49 -> F_27 ( V_21 , V_68 ,
& V_51 -> V_56 ,
& V_51 -> V_57 ) &&
( V_51 -> V_56 . V_61 == V_51 -> V_57 . V_61 ||
! F_24 ( V_21 , V_13 ) ) )
goto V_24;
} else if ( ! F_24 ( V_21 , V_13 ) ) {
goto V_24;
}
}
V_49 -> V_89 ( V_11 , V_21 , V_51 , V_68 , V_13 ) ;
V_24:
F_8 () ;
}
struct V_64 * F_40 ( struct V_12 * V_13 )
{
struct V_64 * V_65 = F_41 ( V_13 ) ;
if ( V_65 )
return V_65 ;
if ( ! F_42 ( V_13 ) )
V_65 = F_43 ( V_13 , V_90 , V_38 ) ;
return V_65 ;
}
unsigned int
F_44 ( struct V_12 * V_13 ,
const struct V_50 * V_51 ,
enum V_67 V_68 )
{
struct V_40 * V_40 = F_38 ( V_13 ) ;
struct V_42 V_91 , V_92 ;
struct V_64 * V_65 ;
V_65 = F_40 ( V_13 ) ;
if ( V_65 == NULL )
return V_93 ;
F_45 ( V_68 == V_55 ||
V_68 == V_94 ) ;
F_46 ( F_47 ( V_13 , V_68 ) ) ;
F_25 ( & V_91 ,
& V_13 -> V_19 [ V_66 ] . V_21 ) ;
F_37 ( & V_92 , & V_91 , V_51 , V_13 , V_68 ) ;
if ( ! F_48 ( & V_92 , & V_91 ) ) {
struct V_42 V_48 ;
F_25 ( & V_48 , & V_92 ) ;
F_49 ( V_13 , & V_48 ) ;
if ( V_68 == V_55 )
V_13 -> V_95 |= V_26 ;
else
V_13 -> V_95 |= V_25 ;
if ( F_50 ( V_13 ) )
F_51 ( V_13 ) ;
}
if ( V_68 == V_55 ) {
unsigned int V_96 ;
V_96 = F_21 ( V_40 , F_32 ( V_13 ) ,
& V_13 -> V_19 [ V_20 ] . V_21 ) ;
F_52 ( & V_97 ) ;
V_65 = F_41 ( V_13 ) ;
V_65 -> V_13 = V_13 ;
F_53 ( & V_65 -> V_98 ,
& V_40 -> V_13 . V_99 [ V_96 ] ) ;
F_54 ( & V_97 ) ;
}
if ( V_68 == V_94 )
V_13 -> V_95 |= V_100 ;
else
V_13 -> V_95 |= V_101 ;
return V_93 ;
}
static unsigned int
F_55 ( struct V_12 * V_13 , enum V_67 V_102 )
{
union V_69 V_81 =
( V_102 == V_55 ?
V_13 -> V_19 [ V_66 ] . V_21 . V_30 . V_59 :
V_13 -> V_19 [ V_66 ] . V_21 . V_22 . V_59 ) ;
struct V_50 V_51 = {
. V_52 = V_53 ,
. V_78 = V_81 ,
. V_79 = V_81 ,
} ;
return F_44 ( V_13 , & V_51 , V_102 ) ;
}
unsigned int
F_56 ( struct V_12 * V_13 , unsigned int V_103 )
{
return F_55 ( V_13 , F_57 ( V_103 ) ) ;
}
unsigned int F_58 ( struct V_12 * V_13 ,
enum V_14 V_15 ,
unsigned int V_103 ,
struct V_7 * V_8 )
{
const struct V_1 * V_11 ;
const struct V_4 * V_49 ;
enum V_16 V_17 = F_7 ( V_15 ) ;
unsigned long V_18 ;
enum V_67 V_104 = F_57 ( V_103 ) ;
if ( V_104 == V_55 )
V_18 = V_26 ;
else
V_18 = V_25 ;
if ( V_17 == V_66 )
V_18 ^= V_105 ;
if ( V_13 -> V_95 & V_18 ) {
struct V_42 V_106 ;
F_25 ( & V_106 , & V_13 -> V_19 [ ! V_17 ] . V_21 ) ;
V_11 = F_1 ( V_106 . V_22 . V_23 ) ;
V_49 = F_3 ( V_106 . V_22 . V_23 ,
V_106 . V_30 . V_5 ) ;
if ( ! V_11 -> V_107 ( V_8 , 0 , V_49 , & V_106 , V_104 ) )
return V_108 ;
}
return V_93 ;
}
static int F_59 ( struct V_12 * V_71 , void * V_109 )
{
const struct V_110 * V_111 = V_109 ;
struct V_64 * V_65 = F_41 ( V_71 ) ;
if ( ! V_65 )
return 0 ;
if ( ( V_111 -> V_11 && F_34 ( V_71 ) != V_111 -> V_11 ) ||
( V_111 -> V_49 && F_60 ( V_71 ) != V_111 -> V_49 ) )
return 0 ;
return V_71 -> V_95 & V_105 ? 1 : 0 ;
}
static int V_110 ( struct V_12 * V_13 , void * V_109 )
{
struct V_64 * V_65 = F_41 ( V_13 ) ;
if ( F_59 ( V_13 , V_109 ) )
return 1 ;
if ( ! V_65 || ! V_65 -> V_13 )
return 0 ;
if ( ! F_61 ( & V_13 -> V_112 ) )
return 1 ;
F_52 ( & V_97 ) ;
F_62 ( & V_65 -> V_98 ) ;
V_13 -> V_95 &= ~ V_113 ;
V_65 -> V_13 = NULL ;
F_54 ( & V_97 ) ;
F_63 ( & V_13 -> V_112 ) ;
return 0 ;
}
static void F_64 ( T_1 V_11 , T_1 V_49 )
{
struct V_110 V_111 = {
. V_11 = V_11 ,
. V_49 = V_49 ,
} ;
struct V_40 * V_40 ;
F_65 () ;
F_66 (net)
F_67 ( V_40 , F_59 , & V_111 , 0 , 0 ) ;
F_68 () ;
}
static void F_69 ( T_1 V_11 )
{
struct V_110 V_111 = {
. V_11 = V_11 ,
} ;
struct V_40 * V_40 ;
F_65 () ;
F_66 (net)
F_67 ( V_40 , F_59 , & V_111 , 0 , 0 ) ;
F_68 () ;
}
int F_70 ( T_1 V_11 , const struct V_4 * V_49 )
{
const struct V_4 * * V_114 ;
unsigned int V_71 ;
int V_115 = 0 ;
F_71 ( & V_116 ) ;
if ( V_6 [ V_11 ] == NULL ) {
V_114 = F_72 ( V_117 * sizeof( struct V_4 * ) ,
V_118 ) ;
if ( V_114 == NULL ) {
V_115 = - V_39 ;
goto V_24;
}
for ( V_71 = 0 ; V_71 < V_117 ; V_71 ++ )
F_73 ( V_114 [ V_71 ] , & V_119 ) ;
F_74 () ;
V_6 [ V_11 ] = V_114 ;
}
if ( F_75 (
V_6 [ V_11 ] [ V_49 -> V_49 ] ,
F_76 ( & V_116 )
) != & V_119 ) {
V_115 = - V_120 ;
goto V_24;
}
F_73 ( V_6 [ V_11 ] [ V_49 -> V_49 ] , V_49 ) ;
V_24:
F_77 ( & V_116 ) ;
return V_115 ;
}
void F_78 ( T_1 V_11 , const struct V_4 * V_49 )
{
F_71 ( & V_116 ) ;
F_73 ( V_6 [ V_11 ] [ V_49 -> V_49 ] ,
& V_119 ) ;
F_77 ( & V_116 ) ;
F_79 () ;
F_64 ( V_11 , V_49 -> V_49 ) ;
}
int F_80 ( const struct V_1 * V_11 )
{
int V_31 ;
V_31 = F_81 ( V_11 -> V_11 ) ;
if ( V_31 < 0 )
return V_31 ;
F_71 ( & V_116 ) ;
F_73 ( V_6 [ V_11 -> V_11 ] [ V_121 ] ,
& V_122 ) ;
F_73 ( V_6 [ V_11 -> V_11 ] [ V_123 ] ,
& V_124 ) ;
F_77 ( & V_116 ) ;
F_73 ( V_3 [ V_11 -> V_11 ] , V_11 ) ;
return 0 ;
}
void F_82 ( const struct V_1 * V_11 )
{
F_71 ( & V_116 ) ;
F_73 ( V_3 [ V_11 -> V_11 ] , NULL ) ;
F_77 ( & V_116 ) ;
F_79 () ;
F_69 ( V_11 -> V_11 ) ;
F_83 ( V_11 -> V_11 ) ;
}
static void F_84 ( struct V_12 * V_13 )
{
struct V_64 * V_65 = F_85 ( V_13 , V_90 ) ;
if ( V_65 == NULL || V_65 -> V_13 == NULL )
return;
F_45 ( V_65 -> V_13 -> V_95 & V_101 ) ;
F_52 ( & V_97 ) ;
F_62 ( & V_65 -> V_98 ) ;
F_54 ( & V_97 ) ;
}
static void F_86 ( void * V_125 , void * V_126 )
{
struct V_64 * V_127 = V_125 ;
struct V_64 * V_128 = V_126 ;
struct V_12 * V_13 = V_128 -> V_13 ;
if ( ! V_13 || ! ( V_13 -> V_95 & V_101 ) )
return;
F_52 ( & V_97 ) ;
F_87 ( & V_128 -> V_98 , & V_127 -> V_98 ) ;
F_54 ( & V_97 ) ;
}
static int F_88 ( struct V_129 * V_130 ,
const struct V_12 * V_13 ,
struct V_50 * V_51 )
{
struct V_129 * V_131 [ V_132 + 1 ] ;
const struct V_4 * V_49 ;
int V_31 ;
V_31 = F_89 ( V_131 , V_132 , V_130 , V_133 ) ;
if ( V_31 < 0 )
return V_31 ;
V_49 = F_3 ( F_34 ( V_13 ) , F_60 ( V_13 ) ) ;
if ( V_49 -> V_134 )
V_31 = V_49 -> V_134 ( V_131 , V_51 ) ;
return V_31 ;
}
static int
F_90 ( const struct V_129 * V_65 ,
const struct V_12 * V_13 , struct V_50 * V_51 ,
const struct V_1 * V_11 )
{
struct V_129 * V_131 [ V_135 + 1 ] ;
int V_31 ;
memset ( V_51 , 0 , sizeof( * V_51 ) ) ;
V_31 = F_89 ( V_131 , V_135 , V_65 , V_136 ) ;
if ( V_31 < 0 )
return V_31 ;
V_31 = V_11 -> V_134 ( V_131 , V_51 ) ;
if ( V_31 < 0 )
return V_31 ;
if ( ! V_131 [ V_137 ] )
return 0 ;
return F_88 ( V_131 [ V_137 ] , V_13 , V_51 ) ;
}
static int
F_91 ( struct V_12 * V_13 ,
enum V_67 V_102 ,
const struct V_129 * V_130 )
{
struct V_50 V_51 ;
const struct V_1 * V_11 ;
int V_31 ;
if ( F_92 ( F_47 ( V_13 , V_102 ) ) )
return - V_138 ;
V_11 = F_1 ( F_34 ( V_13 ) ) ;
if ( V_11 == NULL )
return - V_139 ;
if ( V_130 == NULL )
return F_55 ( V_13 , V_102 ) ;
V_31 = F_90 ( V_130 , V_13 , & V_51 , V_11 ) ;
if ( V_31 < 0 )
return V_31 ;
return F_44 ( V_13 , & V_51 , V_102 ) ;
}
static int
F_91 ( struct V_12 * V_13 ,
enum V_67 V_102 ,
const struct V_129 * V_130 )
{
return - V_140 ;
}
static int T_3 F_93 ( struct V_40 * V_40 )
{
V_40 -> V_13 . V_46 = V_40 -> V_13 . V_141 ;
V_40 -> V_13 . V_99 = F_94 ( & V_40 -> V_13 . V_46 , 0 ) ;
if ( ! V_40 -> V_13 . V_99 )
return - V_39 ;
return 0 ;
}
static void T_4 F_95 ( struct V_40 * V_40 )
{
struct V_110 V_111 = {} ;
F_67 ( V_40 , V_110 , & V_111 , 0 , 0 ) ;
F_79 () ;
F_96 ( V_40 -> V_13 . V_99 , V_40 -> V_13 . V_46 ) ;
}
static int T_5 F_97 ( void )
{
int V_115 ;
V_115 = F_98 ( & V_142 ) ;
if ( V_115 < 0 ) {
F_99 ( V_143 L_2 ) ;
return V_115 ;
}
V_115 = F_100 ( & V_144 ) ;
if ( V_115 < 0 )
goto V_145;
F_101 ( & V_146 ) ;
F_102 ( V_113 ) ;
F_46 ( V_147 != NULL ) ;
F_73 ( V_147 ,
F_91 ) ;
#ifdef F_103
F_46 ( V_148 != NULL ) ;
F_73 ( V_148 , F_4 ) ;
#endif
return 0 ;
V_145:
F_104 ( & V_142 ) ;
return V_115 ;
}
static void T_6 F_105 ( void )
{
unsigned int V_71 ;
F_106 ( & V_144 ) ;
F_104 ( & V_142 ) ;
F_107 ( & V_146 ) ;
F_73 ( V_147 , NULL ) ;
#ifdef F_103
F_73 ( V_148 , NULL ) ;
#endif
for ( V_71 = 0 ; V_71 < V_149 ; V_71 ++ )
F_108 ( V_6 [ V_71 ] ) ;
F_109 () ;
}
