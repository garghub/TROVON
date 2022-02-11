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
int F_9 ( struct V_28 * V_28 , struct V_7 * V_8 , unsigned int V_2 )
{
struct V_9 V_10 ;
unsigned int V_29 ;
struct V_30 * V_31 ;
int V_32 ;
V_32 = F_10 ( V_8 , & V_10 , V_2 ) ;
if ( V_32 < 0 )
return V_32 ;
V_31 = F_11 ( V_8 ) ;
if ( V_31 -> V_33 )
V_31 = ( (struct V_34 * ) V_31 ) -> V_35 ;
F_12 ( V_31 ) ;
V_31 = F_13 ( V_28 , V_31 , & V_10 , V_8 -> V_36 , 0 ) ;
if ( F_14 ( V_31 ) )
return F_15 ( V_31 ) ;
F_16 ( V_8 ) ;
F_17 ( V_8 , V_31 ) ;
V_29 = F_11 ( V_8 ) -> V_37 -> V_38 ;
if ( F_18 ( V_8 ) < V_29 &&
F_19 ( V_8 , V_29 - F_18 ( V_8 ) , 0 , V_39 ) )
return - V_40 ;
return 0 ;
}
static inline unsigned int
F_20 ( const struct V_28 * V_41 , const struct V_42 * V_21 )
{
unsigned int V_43 ;
F_21 ( & V_44 , sizeof( V_44 ) ) ;
V_43 = F_22 ( ( V_45 * ) & V_21 -> V_22 , sizeof( V_21 -> V_22 ) / sizeof( V_45 ) ,
V_21 -> V_31 . V_5 ^ V_44 ^ F_23 ( V_41 ) ) ;
return F_24 ( V_43 , V_46 ) ;
}
int
F_25 ( const struct V_42 * V_21 ,
const struct V_12 * V_47 )
{
struct V_42 V_48 ;
F_26 ( & V_48 , V_21 ) ;
return F_27 ( & V_48 , V_47 ) ;
}
static int F_28 ( const struct V_1 * V_11 ,
const struct V_4 * V_49 ,
const struct V_42 * V_21 ,
const struct V_50 * V_51 )
{
if ( V_51 -> V_52 & V_53 &&
! V_11 -> F_28 ( V_21 , V_51 ) )
return 0 ;
if ( ! ( V_51 -> V_52 & V_54 ) ||
V_49 -> F_28 ( V_21 , V_55 ,
& V_51 -> V_56 , & V_51 -> V_57 ) )
return 1 ;
return 0 ;
}
static inline int
F_29 ( const struct V_12 * V_13 ,
const struct V_42 * V_21 )
{
const struct V_42 * V_58 ;
V_58 = & V_13 -> V_19 [ V_20 ] . V_21 ;
return ( V_58 -> V_31 . V_5 == V_21 -> V_31 . V_5 &&
F_30 ( & V_58 -> V_22 . V_59 , & V_21 -> V_22 . V_59 ) &&
V_58 -> V_22 . V_60 . V_61 == V_21 -> V_22 . V_60 . V_61 ) ;
}
static int
F_31 ( struct V_28 * V_28 ,
const struct V_62 * V_63 ,
const struct V_1 * V_11 ,
const struct V_4 * V_49 ,
const struct V_42 * V_21 ,
struct V_42 * V_64 ,
const struct V_50 * V_51 )
{
unsigned int V_65 = F_20 ( V_28 , V_21 ) ;
const struct V_66 * V_67 ;
const struct V_12 * V_13 ;
F_32 (nat, &nf_nat_bysource[h], bysource) {
V_13 = V_67 -> V_13 ;
if ( F_29 ( V_13 , V_21 ) &&
F_33 ( V_28 , F_34 ( V_13 ) ) &&
F_35 ( V_13 , V_63 , V_20 ) ) {
F_26 ( V_64 ,
& V_13 -> V_19 [ V_68 ] . V_21 ) ;
V_64 -> V_31 = V_21 -> V_31 ;
if ( F_28 ( V_11 , V_49 , V_64 , V_51 ) )
return 1 ;
}
}
return 0 ;
}
static void
F_36 ( const struct V_62 * V_63 ,
struct V_42 * V_21 ,
const struct V_50 * V_51 ,
const struct V_12 * V_13 ,
enum V_69 V_70 )
{
union V_71 * V_72 ;
unsigned int V_73 , V_74 ;
V_45 V_75 , V_76 , V_77 , V_78 ;
bool V_79 ;
if ( ! ( V_51 -> V_52 & V_53 ) )
return;
if ( V_70 == V_55 )
V_72 = & V_21 -> V_22 . V_59 ;
else
V_72 = & V_21 -> V_31 . V_59 ;
if ( F_30 ( & V_51 -> V_80 , & V_51 -> V_81 ) ) {
* V_72 = V_51 -> V_80 ;
return;
}
if ( F_37 ( V_13 ) == V_82 )
V_74 = sizeof( V_72 -> V_83 ) / sizeof( V_45 ) - 1 ;
else
V_74 = sizeof( V_72 -> V_84 ) / sizeof( V_45 ) - 1 ;
V_77 = F_22 ( ( V_45 * ) & V_21 -> V_22 . V_59 , sizeof( V_21 -> V_22 . V_59 ) / sizeof( V_45 ) ,
V_51 -> V_52 & V_85 ?
0 : ( V_86 V_45 ) V_21 -> V_31 . V_59 . V_61 [ V_74 ] ^ V_63 -> V_87 ) ;
V_79 = false ;
for ( V_73 = 0 ; V_73 <= V_74 ; V_73 ++ ) {
if ( ! V_79 ) {
V_75 = F_38 ( ( V_86 V_88 ) V_51 -> V_80 . V_61 [ V_73 ] ) ;
V_76 = F_38 ( ( V_86 V_88 ) V_51 -> V_81 . V_61 [ V_73 ] ) ;
V_78 = V_76 - V_75 + 1 ;
} else {
V_75 = 0 ;
V_78 = ~ 0 ;
}
V_72 -> V_61 [ V_73 ] = ( V_86 V_89 )
F_39 ( V_75 + F_24 ( V_77 , V_78 ) ) ;
if ( V_72 -> V_61 [ V_73 ] != V_51 -> V_81 . V_61 [ V_73 ] )
V_79 = true ;
if ( ! ( V_51 -> V_52 & V_85 ) )
V_77 ^= ( V_86 V_45 ) V_21 -> V_31 . V_59 . V_61 [ V_73 ] ;
}
}
static void
F_40 ( struct V_42 * V_21 ,
const struct V_42 * V_90 ,
const struct V_50 * V_51 ,
struct V_12 * V_13 ,
enum V_69 V_70 )
{
const struct V_62 * V_63 ;
const struct V_1 * V_11 ;
const struct V_4 * V_49 ;
struct V_28 * V_28 = F_34 ( V_13 ) ;
V_63 = F_41 ( V_13 ) ;
F_6 () ;
V_11 = F_1 ( V_90 -> V_22 . V_23 ) ;
V_49 = F_3 ( V_90 -> V_22 . V_23 ,
V_90 -> V_31 . V_5 ) ;
if ( V_70 == V_55 &&
! ( V_51 -> V_52 & V_91 ) ) {
if ( F_28 ( V_11 , V_49 , V_90 , V_51 ) ) {
if ( ! F_25 ( V_90 , V_13 ) ) {
* V_21 = * V_90 ;
goto V_24;
}
} else if ( F_31 ( V_28 , V_63 , V_11 , V_49 ,
V_90 , V_21 , V_51 ) ) {
F_42 ( L_1 ) ;
if ( ! F_25 ( V_21 , V_13 ) )
goto V_24;
}
}
* V_21 = * V_90 ;
F_36 ( V_63 , V_21 , V_51 , V_13 , V_70 ) ;
if ( ! ( V_51 -> V_52 & V_91 ) ) {
if ( V_51 -> V_52 & V_54 ) {
if ( V_49 -> F_28 ( V_21 , V_70 ,
& V_51 -> V_56 ,
& V_51 -> V_57 ) &&
( V_51 -> V_56 . V_61 == V_51 -> V_57 . V_61 ||
! F_25 ( V_21 , V_13 ) ) )
goto V_24;
} else if ( ! F_25 ( V_21 , V_13 ) ) {
goto V_24;
}
}
V_49 -> V_92 ( V_11 , V_21 , V_51 , V_70 , V_13 ) ;
V_24:
F_8 () ;
}
struct V_66 * F_43 ( struct V_12 * V_13 )
{
struct V_66 * V_67 = F_44 ( V_13 ) ;
if ( V_67 )
return V_67 ;
if ( ! F_45 ( V_13 ) )
V_67 = F_46 ( V_13 , V_93 , V_39 ) ;
return V_67 ;
}
unsigned int
F_47 ( struct V_12 * V_13 ,
const struct V_50 * V_51 ,
enum V_69 V_70 )
{
struct V_28 * V_28 = F_34 ( V_13 ) ;
struct V_42 V_94 , V_95 ;
struct V_66 * V_67 ;
V_67 = F_43 ( V_13 ) ;
if ( V_67 == NULL )
return V_96 ;
F_48 ( V_70 == V_55 ||
V_70 == V_97 ) ;
F_49 ( F_50 ( V_13 , V_70 ) ) ;
F_26 ( & V_94 ,
& V_13 -> V_19 [ V_68 ] . V_21 ) ;
F_40 ( & V_95 , & V_94 , V_51 , V_13 , V_70 ) ;
if ( ! F_51 ( & V_95 , & V_94 ) ) {
struct V_42 V_48 ;
F_26 ( & V_48 , & V_95 ) ;
F_52 ( V_13 , & V_48 ) ;
if ( V_70 == V_55 )
V_13 -> V_98 |= V_26 ;
else
V_13 -> V_98 |= V_25 ;
if ( F_53 ( V_13 ) )
F_54 ( V_13 ) ;
}
if ( V_70 == V_55 ) {
unsigned int V_99 ;
V_99 = F_20 ( V_28 ,
& V_13 -> V_19 [ V_20 ] . V_21 ) ;
F_55 ( & V_100 ) ;
V_67 = F_44 ( V_13 ) ;
V_67 -> V_13 = V_13 ;
F_56 ( & V_67 -> V_101 ,
& V_102 [ V_99 ] ) ;
F_57 ( & V_100 ) ;
}
if ( V_70 == V_97 )
V_13 -> V_98 |= V_103 ;
else
V_13 -> V_98 |= V_104 ;
return V_96 ;
}
static unsigned int
F_58 ( struct V_12 * V_13 , enum V_69 V_105 )
{
union V_71 V_83 =
( V_105 == V_55 ?
V_13 -> V_19 [ V_68 ] . V_21 . V_31 . V_59 :
V_13 -> V_19 [ V_68 ] . V_21 . V_22 . V_59 ) ;
struct V_50 V_51 = {
. V_52 = V_53 ,
. V_80 = V_83 ,
. V_81 = V_83 ,
} ;
return F_47 ( V_13 , & V_51 , V_105 ) ;
}
unsigned int
F_59 ( struct V_12 * V_13 , unsigned int V_106 )
{
return F_58 ( V_13 , F_60 ( V_106 ) ) ;
}
unsigned int F_61 ( struct V_12 * V_13 ,
enum V_14 V_15 ,
unsigned int V_106 ,
struct V_7 * V_8 )
{
const struct V_1 * V_11 ;
const struct V_4 * V_49 ;
enum V_16 V_17 = F_7 ( V_15 ) ;
unsigned long V_18 ;
enum V_69 V_107 = F_60 ( V_106 ) ;
if ( V_107 == V_55 )
V_18 = V_26 ;
else
V_18 = V_25 ;
if ( V_17 == V_68 )
V_18 ^= V_108 ;
if ( V_13 -> V_98 & V_18 ) {
struct V_42 V_109 ;
F_26 ( & V_109 , & V_13 -> V_19 [ ! V_17 ] . V_21 ) ;
V_11 = F_1 ( V_109 . V_22 . V_23 ) ;
V_49 = F_3 ( V_109 . V_22 . V_23 ,
V_109 . V_31 . V_5 ) ;
if ( ! V_11 -> V_110 ( V_8 , 0 , V_49 , & V_109 , V_107 ) )
return V_111 ;
}
return V_96 ;
}
static int F_62 ( struct V_12 * V_73 , void * V_112 )
{
const struct V_113 * V_114 = V_112 ;
struct V_66 * V_67 = F_44 ( V_73 ) ;
if ( ! V_67 )
return 0 ;
if ( ( V_114 -> V_11 && F_37 ( V_73 ) != V_114 -> V_11 ) ||
( V_114 -> V_49 && F_63 ( V_73 ) != V_114 -> V_49 ) )
return 0 ;
return V_73 -> V_98 & V_108 ? 1 : 0 ;
}
static int V_113 ( struct V_12 * V_13 , void * V_112 )
{
struct V_66 * V_67 = F_44 ( V_13 ) ;
if ( F_62 ( V_13 , V_112 ) )
return 1 ;
if ( ! V_67 || ! V_67 -> V_13 )
return 0 ;
if ( ! F_64 ( & V_13 -> V_115 ) )
return 1 ;
F_55 ( & V_100 ) ;
F_65 ( & V_67 -> V_101 ) ;
V_13 -> V_98 &= ~ V_116 ;
V_67 -> V_13 = NULL ;
F_57 ( & V_100 ) ;
F_66 ( & V_13 -> V_115 ) ;
return 0 ;
}
static void F_67 ( T_1 V_11 , T_1 V_49 )
{
struct V_113 V_114 = {
. V_11 = V_11 ,
. V_49 = V_49 ,
} ;
struct V_28 * V_28 ;
F_68 () ;
F_69 (net)
F_70 ( V_28 , F_62 , & V_114 , 0 , 0 ) ;
F_71 () ;
}
static void F_72 ( T_1 V_11 )
{
struct V_113 V_114 = {
. V_11 = V_11 ,
} ;
struct V_28 * V_28 ;
F_68 () ;
F_69 (net)
F_70 ( V_28 , F_62 , & V_114 , 0 , 0 ) ;
F_71 () ;
}
int F_73 ( T_1 V_11 , const struct V_4 * V_49 )
{
const struct V_4 * * V_117 ;
unsigned int V_73 ;
int V_118 = 0 ;
F_74 ( & V_119 ) ;
if ( V_6 [ V_11 ] == NULL ) {
V_117 = F_75 ( V_120 * sizeof( struct V_4 * ) ,
V_121 ) ;
if ( V_117 == NULL ) {
V_118 = - V_40 ;
goto V_24;
}
for ( V_73 = 0 ; V_73 < V_120 ; V_73 ++ )
F_76 ( V_117 [ V_73 ] , & V_122 ) ;
F_77 () ;
V_6 [ V_11 ] = V_117 ;
}
if ( F_78 (
V_6 [ V_11 ] [ V_49 -> V_49 ] ,
F_79 ( & V_119 )
) != & V_122 ) {
V_118 = - V_123 ;
goto V_24;
}
F_76 ( V_6 [ V_11 ] [ V_49 -> V_49 ] , V_49 ) ;
V_24:
F_80 ( & V_119 ) ;
return V_118 ;
}
void F_81 ( T_1 V_11 , const struct V_4 * V_49 )
{
F_74 ( & V_119 ) ;
F_76 ( V_6 [ V_11 ] [ V_49 -> V_49 ] ,
& V_122 ) ;
F_80 ( & V_119 ) ;
F_82 () ;
F_67 ( V_11 , V_49 -> V_49 ) ;
}
int F_83 ( const struct V_1 * V_11 )
{
int V_32 ;
V_32 = F_84 ( V_11 -> V_11 ) ;
if ( V_32 < 0 )
return V_32 ;
F_74 ( & V_119 ) ;
F_76 ( V_6 [ V_11 -> V_11 ] [ V_124 ] ,
& V_125 ) ;
F_76 ( V_6 [ V_11 -> V_11 ] [ V_126 ] ,
& V_127 ) ;
F_80 ( & V_119 ) ;
F_76 ( V_3 [ V_11 -> V_11 ] , V_11 ) ;
return 0 ;
}
void F_85 ( const struct V_1 * V_11 )
{
F_74 ( & V_119 ) ;
F_76 ( V_3 [ V_11 -> V_11 ] , NULL ) ;
F_80 ( & V_119 ) ;
F_82 () ;
F_72 ( V_11 -> V_11 ) ;
F_86 ( V_11 -> V_11 ) ;
}
static void F_87 ( struct V_12 * V_13 )
{
struct V_66 * V_67 = F_88 ( V_13 , V_93 ) ;
if ( V_67 == NULL || V_67 -> V_13 == NULL )
return;
F_48 ( V_67 -> V_13 -> V_98 & V_104 ) ;
F_55 ( & V_100 ) ;
F_65 ( & V_67 -> V_101 ) ;
F_57 ( & V_100 ) ;
}
static void F_89 ( void * V_128 , void * V_129 )
{
struct V_66 * V_130 = V_128 ;
struct V_66 * V_131 = V_129 ;
struct V_12 * V_13 = V_131 -> V_13 ;
if ( ! V_13 || ! ( V_13 -> V_98 & V_104 ) )
return;
F_55 ( & V_100 ) ;
F_90 ( & V_131 -> V_101 , & V_130 -> V_101 ) ;
F_57 ( & V_100 ) ;
}
static int F_91 ( struct V_132 * V_133 ,
const struct V_12 * V_13 ,
struct V_50 * V_51 )
{
struct V_132 * V_134 [ V_135 + 1 ] ;
const struct V_4 * V_49 ;
int V_32 ;
V_32 = F_92 ( V_134 , V_135 , V_133 , V_136 ) ;
if ( V_32 < 0 )
return V_32 ;
V_49 = F_3 ( F_37 ( V_13 ) , F_63 ( V_13 ) ) ;
if ( V_49 -> V_137 )
V_32 = V_49 -> V_137 ( V_134 , V_51 ) ;
return V_32 ;
}
static int
F_93 ( const struct V_132 * V_67 ,
const struct V_12 * V_13 , struct V_50 * V_51 ,
const struct V_1 * V_11 )
{
struct V_132 * V_134 [ V_138 + 1 ] ;
int V_32 ;
memset ( V_51 , 0 , sizeof( * V_51 ) ) ;
V_32 = F_92 ( V_134 , V_138 , V_67 , V_139 ) ;
if ( V_32 < 0 )
return V_32 ;
V_32 = V_11 -> V_137 ( V_134 , V_51 ) ;
if ( V_32 < 0 )
return V_32 ;
if ( ! V_134 [ V_140 ] )
return 0 ;
return F_91 ( V_134 [ V_140 ] , V_13 , V_51 ) ;
}
static int
F_94 ( struct V_12 * V_13 ,
enum V_69 V_105 ,
const struct V_132 * V_133 )
{
struct V_50 V_51 ;
const struct V_1 * V_11 ;
int V_32 ;
if ( F_95 ( F_50 ( V_13 , V_105 ) ) )
return - V_141 ;
V_11 = F_1 ( F_37 ( V_13 ) ) ;
if ( V_11 == NULL )
return - V_142 ;
if ( V_133 == NULL )
return F_58 ( V_13 , V_105 ) ;
V_32 = F_93 ( V_133 , V_13 , & V_51 , V_11 ) ;
if ( V_32 < 0 )
return V_32 ;
return F_47 ( V_13 , & V_51 , V_105 ) ;
}
static int
F_94 ( struct V_12 * V_13 ,
enum V_69 V_105 ,
const struct V_132 * V_133 )
{
return - V_143 ;
}
static void T_2 F_96 ( struct V_28 * V_28 )
{
struct V_113 V_114 = {} ;
F_70 ( V_28 , V_113 , & V_114 , 0 , 0 ) ;
}
static int T_3 F_97 ( void )
{
int V_118 ;
V_46 = V_144 ;
V_102 = F_98 ( & V_46 , 0 ) ;
if ( ! V_102 )
return - V_40 ;
V_118 = F_99 ( & V_145 ) ;
if ( V_118 < 0 ) {
F_100 ( V_102 , V_46 ) ;
F_101 ( V_146 L_2 ) ;
return V_118 ;
}
V_118 = F_102 ( & V_147 ) ;
if ( V_118 < 0 )
goto V_148;
F_103 ( & V_149 ) ;
F_104 ( V_116 ) ;
F_49 ( V_150 != NULL ) ;
F_76 ( V_150 ,
F_94 ) ;
#ifdef F_105
F_49 ( V_151 != NULL ) ;
F_76 ( V_151 , F_4 ) ;
#endif
return 0 ;
V_148:
F_100 ( V_102 , V_46 ) ;
F_106 ( & V_145 ) ;
return V_118 ;
}
static void T_4 F_107 ( void )
{
unsigned int V_73 ;
F_108 ( & V_147 ) ;
F_106 ( & V_145 ) ;
F_109 ( & V_149 ) ;
F_76 ( V_150 , NULL ) ;
#ifdef F_105
F_76 ( V_151 , NULL ) ;
#endif
for ( V_73 = 0 ; V_73 < V_152 ; V_73 ++ )
F_110 ( V_6 [ V_73 ] ) ;
F_111 () ;
F_100 ( V_102 , V_46 ) ;
}
