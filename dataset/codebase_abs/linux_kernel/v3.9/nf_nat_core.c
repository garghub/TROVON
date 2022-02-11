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
if ( F_10 ( V_8 , & V_10 , V_2 ) < 0 )
return - 1 ;
V_30 = F_11 ( V_8 ) ;
if ( V_30 -> V_31 )
V_30 = ( (struct V_32 * ) V_30 ) -> V_33 ;
F_12 ( V_30 ) ;
V_30 = F_13 ( F_14 ( V_30 -> V_34 ) , V_30 , & V_10 , V_8 -> V_35 , 0 ) ;
if ( F_15 ( V_30 ) )
return - 1 ;
F_16 ( V_8 ) ;
F_17 ( V_8 , V_30 ) ;
V_28 = F_11 ( V_8 ) -> V_34 -> V_36 ;
if ( F_18 ( V_8 ) < V_28 &&
F_19 ( V_8 , V_28 - F_18 ( V_8 ) , 0 , V_37 ) )
return - 1 ;
return 0 ;
}
static inline unsigned int
F_20 ( const struct V_38 * V_38 , T_2 V_39 ,
const struct V_40 * V_21 )
{
unsigned int V_41 ;
V_41 = F_21 ( ( V_42 * ) & V_21 -> V_22 , sizeof( V_21 -> V_22 ) / sizeof( V_42 ) ,
V_21 -> V_30 . V_5 ^ V_39 ^ V_43 ) ;
return ( ( V_44 ) V_41 * V_38 -> V_13 . V_45 ) >> 32 ;
}
int
F_22 ( const struct V_40 * V_21 ,
const struct V_12 * V_46 )
{
struct V_40 V_47 ;
F_23 ( & V_47 , V_21 ) ;
return F_24 ( & V_47 , V_46 ) ;
}
static int F_25 ( const struct V_1 * V_11 ,
const struct V_4 * V_48 ,
const struct V_40 * V_21 ,
const struct V_49 * V_50 )
{
if ( V_50 -> V_51 & V_52 &&
! V_11 -> F_25 ( V_21 , V_50 ) )
return 0 ;
if ( ! ( V_50 -> V_51 & V_53 ) ||
V_48 -> F_25 ( V_21 , V_54 ,
& V_50 -> V_55 , & V_50 -> V_56 ) )
return 1 ;
return 0 ;
}
static inline int
F_26 ( const struct V_12 * V_13 ,
const struct V_40 * V_21 )
{
const struct V_40 * V_57 ;
V_57 = & V_13 -> V_19 [ V_20 ] . V_21 ;
return ( V_57 -> V_30 . V_5 == V_21 -> V_30 . V_5 &&
F_27 ( & V_57 -> V_22 . V_58 , & V_21 -> V_22 . V_58 ) &&
V_57 -> V_22 . V_59 . V_60 == V_21 -> V_22 . V_59 . V_60 ) ;
}
static int
F_28 ( struct V_38 * V_38 , T_2 V_39 ,
const struct V_1 * V_11 ,
const struct V_4 * V_48 ,
const struct V_40 * V_21 ,
struct V_40 * V_61 ,
const struct V_49 * V_50 )
{
unsigned int V_62 = F_20 ( V_38 , V_39 , V_21 ) ;
const struct V_63 * V_64 ;
const struct V_12 * V_13 ;
F_29 (nat, &net->ct.nat_bysource[h], bysource) {
V_13 = V_64 -> V_13 ;
if ( F_26 ( V_13 , V_21 ) && F_30 ( V_13 ) == V_39 ) {
F_23 ( V_61 ,
& V_13 -> V_19 [ V_65 ] . V_21 ) ;
V_61 -> V_30 = V_21 -> V_30 ;
if ( F_25 ( V_11 , V_48 , V_61 , V_50 ) )
return 1 ;
}
}
return 0 ;
}
static void
F_31 ( T_2 V_39 , struct V_40 * V_21 ,
const struct V_49 * V_50 ,
const struct V_12 * V_13 ,
enum V_66 V_67 )
{
union V_68 * V_69 ;
unsigned int V_70 , V_71 ;
V_42 V_72 , V_73 , V_74 , V_75 ;
bool V_76 ;
if ( ! ( V_50 -> V_51 & V_52 ) )
return;
if ( V_67 == V_54 )
V_69 = & V_21 -> V_22 . V_58 ;
else
V_69 = & V_21 -> V_30 . V_58 ;
if ( F_27 ( & V_50 -> V_77 , & V_50 -> V_78 ) ) {
* V_69 = V_50 -> V_77 ;
return;
}
if ( F_32 ( V_13 ) == V_79 )
V_71 = sizeof( V_69 -> V_80 ) / sizeof( V_42 ) - 1 ;
else
V_71 = sizeof( V_69 -> V_81 ) / sizeof( V_42 ) - 1 ;
V_74 = F_21 ( ( V_42 * ) & V_21 -> V_22 . V_58 , sizeof( V_21 -> V_22 . V_58 ) / sizeof( V_42 ) ,
V_50 -> V_51 & V_82 ?
0 : ( V_83 V_42 ) V_21 -> V_30 . V_58 . V_60 [ V_71 ] ^ V_39 ) ;
V_76 = false ;
for ( V_70 = 0 ; V_70 <= V_71 ; V_70 ++ ) {
if ( ! V_76 ) {
V_72 = F_33 ( ( V_83 V_84 ) V_50 -> V_77 . V_60 [ V_70 ] ) ;
V_73 = F_33 ( ( V_83 V_84 ) V_50 -> V_78 . V_60 [ V_70 ] ) ;
V_75 = V_73 - V_72 + 1 ;
} else {
V_72 = 0 ;
V_75 = ~ 0 ;
}
V_69 -> V_60 [ V_70 ] = ( V_83 V_85 )
F_34 ( V_72 + ( ( ( V_44 ) V_74 * V_75 ) >> 32 ) ) ;
if ( V_69 -> V_60 [ V_70 ] != V_50 -> V_78 . V_60 [ V_70 ] )
V_76 = true ;
if ( ! ( V_50 -> V_51 & V_82 ) )
V_74 ^= ( V_83 V_42 ) V_21 -> V_30 . V_58 . V_60 [ V_70 ] ;
}
}
static void
F_35 ( struct V_40 * V_21 ,
const struct V_40 * V_86 ,
const struct V_49 * V_50 ,
struct V_12 * V_13 ,
enum V_66 V_67 )
{
const struct V_1 * V_11 ;
const struct V_4 * V_48 ;
struct V_38 * V_38 = F_36 ( V_13 ) ;
T_2 V_39 = F_30 ( V_13 ) ;
F_6 () ;
V_11 = F_1 ( V_86 -> V_22 . V_23 ) ;
V_48 = F_3 ( V_86 -> V_22 . V_23 ,
V_86 -> V_30 . V_5 ) ;
if ( V_67 == V_54 &&
! ( V_50 -> V_51 & V_87 ) ) {
if ( F_25 ( V_11 , V_48 , V_86 , V_50 ) ) {
if ( ! F_22 ( V_86 , V_13 ) ) {
* V_21 = * V_86 ;
goto V_24;
}
} else if ( F_28 ( V_38 , V_39 , V_11 , V_48 ,
V_86 , V_21 , V_50 ) ) {
F_37 ( L_1 ) ;
if ( ! F_22 ( V_21 , V_13 ) )
goto V_24;
}
}
* V_21 = * V_86 ;
F_31 ( V_39 , V_21 , V_50 , V_13 , V_67 ) ;
if ( ! ( V_50 -> V_51 & V_87 ) ) {
if ( V_50 -> V_51 & V_53 ) {
if ( V_48 -> F_25 ( V_21 , V_67 ,
& V_50 -> V_55 ,
& V_50 -> V_56 ) &&
( V_50 -> V_55 . V_60 == V_50 -> V_56 . V_60 ||
! F_22 ( V_21 , V_13 ) ) )
goto V_24;
} else if ( ! F_22 ( V_21 , V_13 ) ) {
goto V_24;
}
}
V_48 -> V_88 ( V_11 , V_21 , V_50 , V_67 , V_13 ) ;
V_24:
F_8 () ;
}
unsigned int
F_38 ( struct V_12 * V_13 ,
const struct V_49 * V_50 ,
enum V_66 V_67 )
{
struct V_38 * V_38 = F_36 ( V_13 ) ;
struct V_40 V_89 , V_90 ;
struct V_63 * V_64 ;
V_64 = F_39 ( V_13 ) ;
if ( ! V_64 ) {
V_64 = F_40 ( V_13 , V_91 , V_37 ) ;
if ( V_64 == NULL ) {
F_37 ( L_2 ) ;
return V_92 ;
}
}
F_41 ( V_67 == V_54 ||
V_67 == V_93 ) ;
F_42 ( F_43 ( V_13 , V_67 ) ) ;
F_23 ( & V_89 ,
& V_13 -> V_19 [ V_65 ] . V_21 ) ;
F_35 ( & V_90 , & V_89 , V_50 , V_13 , V_67 ) ;
if ( ! F_44 ( & V_90 , & V_89 ) ) {
struct V_40 V_47 ;
F_23 ( & V_47 , & V_90 ) ;
F_45 ( V_13 , & V_47 ) ;
if ( V_67 == V_54 )
V_13 -> V_94 |= V_26 ;
else
V_13 -> V_94 |= V_25 ;
}
if ( V_67 == V_54 ) {
unsigned int V_95 ;
V_95 = F_20 ( V_38 , F_30 ( V_13 ) ,
& V_13 -> V_19 [ V_20 ] . V_21 ) ;
F_46 ( & V_96 ) ;
V_64 = F_39 ( V_13 ) ;
V_64 -> V_13 = V_13 ;
F_47 ( & V_64 -> V_97 ,
& V_38 -> V_13 . V_98 [ V_95 ] ) ;
F_48 ( & V_96 ) ;
}
if ( V_67 == V_93 )
V_13 -> V_94 |= V_99 ;
else
V_13 -> V_94 |= V_100 ;
return V_92 ;
}
unsigned int F_49 ( struct V_12 * V_13 ,
enum V_14 V_15 ,
unsigned int V_101 ,
struct V_7 * V_8 )
{
const struct V_1 * V_11 ;
const struct V_4 * V_48 ;
enum V_16 V_17 = F_7 ( V_15 ) ;
unsigned long V_18 ;
enum V_66 V_102 = F_50 ( V_101 ) ;
if ( V_102 == V_54 )
V_18 = V_26 ;
else
V_18 = V_25 ;
if ( V_17 == V_65 )
V_18 ^= V_103 ;
if ( V_13 -> V_94 & V_18 ) {
struct V_40 V_104 ;
F_23 ( & V_104 , & V_13 -> V_19 [ ! V_17 ] . V_21 ) ;
V_11 = F_1 ( V_104 . V_22 . V_23 ) ;
V_48 = F_3 ( V_104 . V_22 . V_23 ,
V_104 . V_30 . V_5 ) ;
if ( ! V_11 -> V_105 ( V_8 , 0 , V_48 , & V_104 , V_102 ) )
return V_106 ;
}
return V_92 ;
}
static int F_51 ( struct V_12 * V_70 , void * V_107 )
{
const struct V_108 * V_109 = V_107 ;
struct V_63 * V_64 = F_39 ( V_70 ) ;
if ( ! V_64 )
return 0 ;
if ( ( V_109 -> V_11 && F_32 ( V_70 ) != V_109 -> V_11 ) ||
( V_109 -> V_48 && F_52 ( V_70 ) != V_109 -> V_48 ) )
return 0 ;
return V_70 -> V_94 & V_103 ? 1 : 0 ;
}
static void F_53 ( T_1 V_11 , T_1 V_48 )
{
struct V_108 V_109 = {
. V_11 = V_11 ,
. V_48 = V_48 ,
} ;
struct V_38 * V_38 ;
F_54 () ;
F_55 (net)
F_56 ( V_38 , F_51 , & V_109 ) ;
F_57 () ;
}
static void F_58 ( T_1 V_11 )
{
struct V_108 V_109 = {
. V_11 = V_11 ,
} ;
struct V_38 * V_38 ;
F_54 () ;
F_55 (net)
F_56 ( V_38 , F_51 , & V_109 ) ;
F_57 () ;
}
int F_59 ( T_1 V_11 , const struct V_4 * V_48 )
{
const struct V_4 * * V_110 ;
unsigned int V_70 ;
int V_111 = 0 ;
F_60 ( & V_112 ) ;
if ( V_6 [ V_11 ] == NULL ) {
V_110 = F_61 ( V_113 * sizeof( struct V_4 * ) ,
V_114 ) ;
if ( V_110 == NULL ) {
V_111 = - V_115 ;
goto V_24;
}
for ( V_70 = 0 ; V_70 < V_113 ; V_70 ++ )
F_62 ( V_110 [ V_70 ] , & V_116 ) ;
F_63 () ;
V_6 [ V_11 ] = V_110 ;
}
if ( F_64 (
V_6 [ V_11 ] [ V_48 -> V_48 ] ,
F_65 ( & V_112 )
) != & V_116 ) {
V_111 = - V_117 ;
goto V_24;
}
F_62 ( V_6 [ V_11 ] [ V_48 -> V_48 ] , V_48 ) ;
V_24:
F_66 ( & V_112 ) ;
return V_111 ;
}
void F_67 ( T_1 V_11 , const struct V_4 * V_48 )
{
F_60 ( & V_112 ) ;
F_62 ( V_6 [ V_11 ] [ V_48 -> V_48 ] ,
& V_116 ) ;
F_66 ( & V_112 ) ;
F_68 () ;
F_53 ( V_11 , V_48 -> V_48 ) ;
}
int F_69 ( const struct V_1 * V_11 )
{
int V_118 ;
V_118 = F_70 ( V_11 -> V_11 ) ;
if ( V_118 < 0 )
return V_118 ;
F_60 ( & V_112 ) ;
F_62 ( V_6 [ V_11 -> V_11 ] [ V_119 ] ,
& V_120 ) ;
F_62 ( V_6 [ V_11 -> V_11 ] [ V_121 ] ,
& V_122 ) ;
F_66 ( & V_112 ) ;
F_62 ( V_3 [ V_11 -> V_11 ] , V_11 ) ;
return 0 ;
}
void F_71 ( const struct V_1 * V_11 )
{
F_60 ( & V_112 ) ;
F_62 ( V_3 [ V_11 -> V_11 ] , NULL ) ;
F_66 ( & V_112 ) ;
F_68 () ;
F_58 ( V_11 -> V_11 ) ;
F_72 ( V_11 -> V_11 ) ;
}
static void F_73 ( struct V_12 * V_13 )
{
struct V_63 * V_64 = F_74 ( V_13 , V_91 ) ;
if ( V_64 == NULL || V_64 -> V_13 == NULL )
return;
F_41 ( V_64 -> V_13 -> V_94 & V_100 ) ;
F_46 ( & V_96 ) ;
F_75 ( & V_64 -> V_97 ) ;
F_48 ( & V_96 ) ;
}
static void F_76 ( void * V_123 , void * V_124 )
{
struct V_63 * V_125 = V_123 ;
struct V_63 * V_126 = V_124 ;
struct V_12 * V_13 = V_126 -> V_13 ;
if ( ! V_13 || ! ( V_13 -> V_94 & V_100 ) )
return;
F_46 ( & V_96 ) ;
F_77 ( & V_126 -> V_97 , & V_125 -> V_97 ) ;
F_48 ( & V_96 ) ;
}
static int F_78 ( struct V_127 * V_128 ,
const struct V_12 * V_13 ,
struct V_49 * V_50 )
{
struct V_127 * V_129 [ V_130 + 1 ] ;
const struct V_4 * V_48 ;
int V_118 ;
V_118 = F_79 ( V_129 , V_130 , V_128 , V_131 ) ;
if ( V_118 < 0 )
return V_118 ;
V_48 = F_3 ( F_32 ( V_13 ) , F_52 ( V_13 ) ) ;
if ( V_48 -> V_132 )
V_118 = V_48 -> V_132 ( V_129 , V_50 ) ;
return V_118 ;
}
static int
F_80 ( const struct V_127 * V_64 ,
const struct V_12 * V_13 , struct V_49 * V_50 )
{
const struct V_1 * V_11 ;
struct V_127 * V_129 [ V_133 + 1 ] ;
int V_118 ;
memset ( V_50 , 0 , sizeof( * V_50 ) ) ;
V_118 = F_79 ( V_129 , V_133 , V_64 , V_134 ) ;
if ( V_118 < 0 )
return V_118 ;
F_6 () ;
V_11 = F_1 ( F_32 ( V_13 ) ) ;
if ( V_11 == NULL ) {
V_118 = - V_135 ;
goto V_24;
}
V_118 = V_11 -> V_132 ( V_129 , V_50 ) ;
if ( V_118 < 0 )
goto V_24;
if ( ! V_129 [ V_136 ] )
goto V_24;
V_118 = F_78 ( V_129 [ V_136 ] , V_13 , V_50 ) ;
V_24:
F_8 () ;
return V_118 ;
}
static int
F_81 ( struct V_12 * V_13 ,
enum V_66 V_137 ,
const struct V_127 * V_128 )
{
struct V_49 V_50 ;
int V_118 ;
V_118 = F_80 ( V_128 , V_13 , & V_50 ) ;
if ( V_118 < 0 )
return V_118 ;
if ( F_43 ( V_13 , V_137 ) )
return - V_138 ;
return F_38 ( V_13 , & V_50 , V_137 ) ;
}
static int
F_81 ( struct V_12 * V_13 ,
enum V_66 V_137 ,
const struct V_127 * V_128 )
{
return - V_139 ;
}
static int T_3 F_82 ( struct V_38 * V_38 )
{
V_38 -> V_13 . V_45 = V_38 -> V_13 . V_140 ;
V_38 -> V_13 . V_98 = F_83 ( & V_38 -> V_13 . V_45 , 0 ) ;
if ( ! V_38 -> V_13 . V_98 )
return - V_115 ;
return 0 ;
}
static void T_4 F_84 ( struct V_38 * V_38 )
{
struct V_108 V_109 = {} ;
F_56 ( V_38 , & F_51 , & V_109 ) ;
F_68 () ;
F_85 ( V_38 -> V_13 . V_98 , V_38 -> V_13 . V_45 ) ;
}
static int T_5 F_86 ( void )
{
int V_111 ;
V_111 = F_87 ( & V_141 ) ;
if ( V_111 < 0 ) {
F_88 ( V_142 L_3 ) ;
return V_111 ;
}
V_111 = F_89 ( & V_143 ) ;
if ( V_111 < 0 )
goto V_144;
F_90 ( & V_145 ) ;
F_91 ( V_146 ) ;
F_42 ( V_147 != NULL ) ;
F_62 ( V_147 , V_148 ) ;
F_42 ( V_149 != NULL ) ;
F_62 ( V_149 ,
F_81 ) ;
F_42 ( V_150 != NULL ) ;
F_62 ( V_150 , V_151 ) ;
F_62 ( V_152 , & V_153 ) ;
#ifdef F_92
F_42 ( V_154 != NULL ) ;
F_62 ( V_154 , F_4 ) ;
#endif
return 0 ;
V_144:
F_93 ( & V_141 ) ;
return V_111 ;
}
static void T_6 F_94 ( void )
{
unsigned int V_70 ;
F_95 ( & V_143 ) ;
F_93 ( & V_141 ) ;
F_96 ( & V_145 ) ;
F_62 ( V_147 , NULL ) ;
F_62 ( V_149 , NULL ) ;
F_62 ( V_150 , NULL ) ;
F_62 ( V_152 , NULL ) ;
#ifdef F_92
F_62 ( V_154 , NULL ) ;
#endif
for ( V_70 = 0 ; V_70 < V_155 ; V_70 ++ )
F_97 ( V_6 [ V_70 ] ) ;
F_98 () ;
}
