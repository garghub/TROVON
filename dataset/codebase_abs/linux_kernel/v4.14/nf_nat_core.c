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
V_2 = F_6 ( V_13 ) ;
V_11 = F_1 ( V_2 ) ;
if ( V_11 == NULL )
return;
V_17 = F_7 ( V_15 ) ;
if ( V_17 == V_19 )
V_18 = V_20 ;
else
V_18 = V_21 ;
V_11 -> V_22 ( V_8 , V_13 , V_17 , V_18 , V_10 ) ;
}
int F_8 ( struct V_23 * V_23 , struct V_7 * V_8 , unsigned int V_2 )
{
struct V_9 V_10 ;
unsigned int V_24 ;
struct V_25 * V_26 ;
int V_27 ;
V_27 = F_9 ( V_8 , & V_10 , V_2 ) ;
if ( V_27 < 0 )
return V_27 ;
V_26 = F_10 ( V_8 ) ;
if ( V_26 -> V_28 )
V_26 = ( (struct V_29 * ) V_26 ) -> V_30 ;
F_11 ( V_26 ) ;
V_26 = F_12 ( V_23 , V_26 , & V_10 , V_8 -> V_31 , 0 ) ;
if ( F_13 ( V_26 ) )
return F_14 ( V_26 ) ;
F_15 ( V_8 ) ;
F_16 ( V_8 , V_26 ) ;
V_24 = F_10 ( V_8 ) -> V_32 -> V_33 ;
if ( F_17 ( V_8 ) < V_24 &&
F_18 ( V_8 , V_24 - F_17 ( V_8 ) , 0 , V_34 ) )
return - V_35 ;
return 0 ;
}
static unsigned int
F_19 ( const struct V_23 * V_36 , const struct V_37 * V_38 )
{
unsigned int V_39 ;
F_20 ( & V_40 , sizeof( V_40 ) ) ;
V_39 = F_21 ( ( V_41 * ) & V_38 -> V_42 , sizeof( V_38 -> V_42 ) / sizeof( V_41 ) ,
V_38 -> V_26 . V_5 ^ V_40 ^ F_22 ( V_36 ) ) ;
return F_23 ( V_39 , V_43 ) ;
}
int
F_24 ( const struct V_37 * V_38 ,
const struct V_12 * V_44 )
{
struct V_37 V_45 ;
F_25 ( & V_45 , V_38 ) ;
return F_26 ( & V_45 , V_44 ) ;
}
static int F_27 ( const struct V_1 * V_11 ,
const struct V_4 * V_46 ,
const struct V_37 * V_38 ,
const struct V_47 * V_48 )
{
if ( V_48 -> V_49 & V_50 &&
! V_11 -> F_27 ( V_38 , V_48 ) )
return 0 ;
if ( ! ( V_48 -> V_49 & V_51 ) ||
V_46 -> F_27 ( V_38 , V_52 ,
& V_48 -> V_53 , & V_48 -> V_54 ) )
return 1 ;
return 0 ;
}
static inline int
F_28 ( const struct V_12 * V_13 ,
const struct V_37 * V_38 )
{
const struct V_37 * V_55 ;
V_55 = & V_13 -> V_56 [ V_19 ] . V_38 ;
return ( V_55 -> V_26 . V_5 == V_38 -> V_26 . V_5 &&
F_29 ( & V_55 -> V_42 . V_57 , & V_38 -> V_42 . V_57 ) &&
V_55 -> V_42 . V_58 . V_59 == V_38 -> V_42 . V_58 . V_59 ) ;
}
static int
F_30 ( struct V_23 * V_23 ,
const struct V_60 * V_61 ,
const struct V_1 * V_11 ,
const struct V_4 * V_46 ,
const struct V_37 * V_38 ,
struct V_37 * V_62 ,
const struct V_47 * V_48 )
{
unsigned int V_63 = F_19 ( V_23 , V_38 ) ;
const struct V_12 * V_13 ;
F_31 (ct, &nf_nat_bysource[h], nat_bysource) {
if ( F_28 ( V_13 , V_38 ) &&
F_32 ( V_23 , F_33 ( V_13 ) ) &&
F_34 ( V_13 , V_61 , V_19 ) ) {
F_25 ( V_62 ,
& V_13 -> V_56 [ V_64 ] . V_38 ) ;
V_62 -> V_26 = V_38 -> V_26 ;
if ( F_27 ( V_11 , V_46 , V_62 , V_48 ) )
return 1 ;
}
}
return 0 ;
}
static void
F_35 ( const struct V_60 * V_61 ,
struct V_37 * V_38 ,
const struct V_47 * V_48 ,
const struct V_12 * V_13 ,
enum V_65 V_66 )
{
union V_67 * V_68 ;
unsigned int V_69 , V_70 ;
V_41 V_71 , V_72 , V_73 , V_74 ;
bool V_75 ;
if ( ! ( V_48 -> V_49 & V_50 ) )
return;
if ( V_66 == V_52 )
V_68 = & V_38 -> V_42 . V_57 ;
else
V_68 = & V_38 -> V_26 . V_57 ;
if ( F_29 ( & V_48 -> V_76 , & V_48 -> V_77 ) ) {
* V_68 = V_48 -> V_76 ;
return;
}
if ( F_6 ( V_13 ) == V_78 )
V_70 = sizeof( V_68 -> V_79 ) / sizeof( V_41 ) - 1 ;
else
V_70 = sizeof( V_68 -> V_80 ) / sizeof( V_41 ) - 1 ;
V_73 = F_21 ( ( V_41 * ) & V_38 -> V_42 . V_57 , sizeof( V_38 -> V_42 . V_57 ) / sizeof( V_41 ) ,
V_48 -> V_49 & V_81 ?
0 : ( V_82 V_41 ) V_38 -> V_26 . V_57 . V_59 [ V_70 ] ^ V_61 -> V_83 ) ;
V_75 = false ;
for ( V_69 = 0 ; V_69 <= V_70 ; V_69 ++ ) {
if ( ! V_75 ) {
V_71 = F_36 ( ( V_82 V_84 ) V_48 -> V_76 . V_59 [ V_69 ] ) ;
V_72 = F_36 ( ( V_82 V_84 ) V_48 -> V_77 . V_59 [ V_69 ] ) ;
V_74 = V_72 - V_71 + 1 ;
} else {
V_71 = 0 ;
V_74 = ~ 0 ;
}
V_68 -> V_59 [ V_69 ] = ( V_82 V_85 )
F_37 ( V_71 + F_23 ( V_73 , V_74 ) ) ;
if ( V_68 -> V_59 [ V_69 ] != V_48 -> V_77 . V_59 [ V_69 ] )
V_75 = true ;
if ( ! ( V_48 -> V_49 & V_81 ) )
V_73 ^= ( V_82 V_41 ) V_38 -> V_26 . V_57 . V_59 [ V_69 ] ;
}
}
static void
F_38 ( struct V_37 * V_38 ,
const struct V_37 * V_86 ,
const struct V_47 * V_48 ,
struct V_12 * V_13 ,
enum V_65 V_66 )
{
const struct V_60 * V_61 ;
const struct V_1 * V_11 ;
const struct V_4 * V_46 ;
struct V_23 * V_23 = F_33 ( V_13 ) ;
V_61 = F_39 ( V_13 ) ;
F_40 () ;
V_11 = F_1 ( V_86 -> V_42 . V_87 ) ;
V_46 = F_3 ( V_86 -> V_42 . V_87 ,
V_86 -> V_26 . V_5 ) ;
if ( V_66 == V_52 &&
! ( V_48 -> V_49 & V_88 ) ) {
if ( F_27 ( V_11 , V_46 , V_86 , V_48 ) ) {
if ( ! F_24 ( V_86 , V_13 ) ) {
* V_38 = * V_86 ;
goto V_89;
}
} else if ( F_30 ( V_23 , V_61 , V_11 , V_46 ,
V_86 , V_38 , V_48 ) ) {
F_41 ( L_1 ) ;
if ( ! F_24 ( V_38 , V_13 ) )
goto V_89;
}
}
* V_38 = * V_86 ;
F_35 ( V_61 , V_38 , V_48 , V_13 , V_66 ) ;
if ( ! ( V_48 -> V_49 & V_88 ) ) {
if ( V_48 -> V_49 & V_51 ) {
if ( V_46 -> F_27 ( V_38 , V_66 ,
& V_48 -> V_53 ,
& V_48 -> V_54 ) &&
( V_48 -> V_53 . V_59 == V_48 -> V_54 . V_59 ||
! F_24 ( V_38 , V_13 ) ) )
goto V_89;
} else if ( ! F_24 ( V_38 , V_13 ) ) {
goto V_89;
}
}
V_46 -> V_90 ( V_11 , V_38 , V_48 , V_66 , V_13 ) ;
V_89:
F_42 () ;
}
struct V_91 * F_43 ( struct V_12 * V_13 )
{
struct V_91 * V_92 = F_44 ( V_13 ) ;
if ( V_92 )
return V_92 ;
if ( ! F_45 ( V_13 ) )
V_92 = F_46 ( V_13 , V_93 , V_34 ) ;
return V_92 ;
}
unsigned int
F_47 ( struct V_12 * V_13 ,
const struct V_47 * V_48 ,
enum V_65 V_66 )
{
struct V_23 * V_23 = F_33 ( V_13 ) ;
struct V_37 V_94 , V_95 ;
if ( F_45 ( V_13 ) )
return V_96 ;
F_48 ( V_66 != V_52 &&
V_66 != V_97 ) ;
if ( F_48 ( F_49 ( V_13 , V_66 ) ) )
return V_98 ;
F_25 ( & V_94 ,
& V_13 -> V_56 [ V_64 ] . V_38 ) ;
F_38 ( & V_95 , & V_94 , V_48 , V_13 , V_66 ) ;
if ( ! F_50 ( & V_95 , & V_94 ) ) {
struct V_37 V_45 ;
F_25 ( & V_45 , & V_95 ) ;
F_51 ( V_13 , & V_45 ) ;
if ( V_66 == V_52 )
V_13 -> V_99 |= V_21 ;
else
V_13 -> V_99 |= V_20 ;
if ( F_52 ( V_13 ) && ! F_53 ( V_13 ) )
if ( ! F_54 ( V_13 ) )
return V_98 ;
}
if ( V_66 == V_52 ) {
unsigned int V_100 ;
T_2 * V_101 ;
V_100 = F_19 ( V_23 ,
& V_13 -> V_56 [ V_19 ] . V_38 ) ;
V_101 = & V_102 [ V_100 % V_103 ] ;
F_55 ( V_101 ) ;
F_56 ( & V_13 -> V_104 ,
& V_105 [ V_100 ] ) ;
F_57 ( V_101 ) ;
}
if ( V_66 == V_97 )
V_13 -> V_99 |= V_106 ;
else
V_13 -> V_99 |= V_107 ;
return V_96 ;
}
static unsigned int
F_58 ( struct V_12 * V_13 , enum V_65 V_108 )
{
union V_67 V_79 =
( V_108 == V_52 ?
V_13 -> V_56 [ V_64 ] . V_38 . V_26 . V_57 :
V_13 -> V_56 [ V_64 ] . V_38 . V_42 . V_57 ) ;
struct V_47 V_48 = {
. V_49 = V_50 ,
. V_76 = V_79 ,
. V_77 = V_79 ,
} ;
return F_47 ( V_13 , & V_48 , V_108 ) ;
}
unsigned int
F_59 ( struct V_12 * V_13 , unsigned int V_109 )
{
return F_58 ( V_13 , F_60 ( V_109 ) ) ;
}
unsigned int F_61 ( struct V_12 * V_13 ,
enum V_14 V_15 ,
unsigned int V_109 ,
struct V_7 * V_8 )
{
const struct V_1 * V_11 ;
const struct V_4 * V_46 ;
enum V_16 V_17 = F_7 ( V_15 ) ;
unsigned long V_18 ;
enum V_65 V_110 = F_60 ( V_109 ) ;
if ( V_110 == V_52 )
V_18 = V_21 ;
else
V_18 = V_20 ;
if ( V_17 == V_64 )
V_18 ^= V_111 ;
if ( V_13 -> V_99 & V_18 ) {
struct V_37 V_112 ;
F_25 ( & V_112 , & V_13 -> V_56 [ ! V_17 ] . V_38 ) ;
V_11 = F_1 ( V_112 . V_42 . V_87 ) ;
V_46 = F_3 ( V_112 . V_42 . V_87 ,
V_112 . V_26 . V_5 ) ;
if ( ! V_11 -> V_113 ( V_8 , 0 , V_46 , & V_112 , V_110 ) )
return V_98 ;
}
return V_96 ;
}
static int F_62 ( struct V_12 * V_69 , void * V_114 )
{
const struct V_115 * V_116 = V_114 ;
if ( ( V_116 -> V_11 && F_6 ( V_69 ) != V_116 -> V_11 ) ||
( V_116 -> V_46 && F_63 ( V_69 ) != V_116 -> V_46 ) )
return 0 ;
return V_69 -> V_99 & V_111 ? 1 : 0 ;
}
static void F_64 ( struct V_12 * V_13 )
{
unsigned int V_63 ;
V_63 = F_19 ( F_33 ( V_13 ) , & V_13 -> V_56 [ V_19 ] . V_38 ) ;
F_55 ( & V_102 [ V_63 % V_103 ] ) ;
F_65 ( & V_13 -> V_104 ) ;
F_57 ( & V_102 [ V_63 % V_103 ] ) ;
}
static int V_115 ( struct V_12 * V_13 , void * V_114 )
{
if ( F_62 ( V_13 , V_114 ) )
return 1 ;
if ( ( V_13 -> V_99 & V_107 ) == 0 )
return 0 ;
F_66 ( V_117 , & V_13 -> V_99 ) ;
F_64 ( V_13 ) ;
return 0 ;
}
static void F_67 ( T_1 V_11 , T_1 V_46 )
{
struct V_115 V_116 = {
. V_11 = V_11 ,
. V_46 = V_46 ,
} ;
F_68 ( F_62 , & V_116 ) ;
}
static void F_69 ( T_1 V_11 )
{
struct V_115 V_116 = {
. V_11 = V_11 ,
} ;
F_68 ( F_62 , & V_116 ) ;
}
int F_70 ( T_1 V_11 , const struct V_4 * V_46 )
{
const struct V_4 * * V_118 ;
unsigned int V_69 ;
int V_119 = 0 ;
F_71 ( & V_120 ) ;
if ( V_6 [ V_11 ] == NULL ) {
V_118 = F_72 ( V_121 * sizeof( struct V_4 * ) ,
V_122 ) ;
if ( V_118 == NULL ) {
V_119 = - V_35 ;
goto V_89;
}
for ( V_69 = 0 ; V_69 < V_121 ; V_69 ++ )
F_73 ( V_118 [ V_69 ] , & V_123 ) ;
F_74 () ;
V_6 [ V_11 ] = V_118 ;
}
if ( F_75 (
V_6 [ V_11 ] [ V_46 -> V_46 ] ,
F_76 ( & V_120 )
) != & V_123 ) {
V_119 = - V_124 ;
goto V_89;
}
F_73 ( V_6 [ V_11 ] [ V_46 -> V_46 ] , V_46 ) ;
V_89:
F_77 ( & V_120 ) ;
return V_119 ;
}
void F_78 ( T_1 V_11 , const struct V_4 * V_46 )
{
F_71 ( & V_120 ) ;
F_73 ( V_6 [ V_11 ] [ V_46 -> V_46 ] ,
& V_123 ) ;
F_77 ( & V_120 ) ;
F_79 () ;
F_67 ( V_11 , V_46 -> V_46 ) ;
}
int F_80 ( const struct V_1 * V_11 )
{
int V_27 ;
V_27 = F_81 ( V_11 -> V_11 ) ;
if ( V_27 < 0 )
return V_27 ;
F_71 ( & V_120 ) ;
F_73 ( V_6 [ V_11 -> V_11 ] [ V_125 ] ,
& V_126 ) ;
F_73 ( V_6 [ V_11 -> V_11 ] [ V_127 ] ,
& V_128 ) ;
#ifdef F_82
F_73 ( V_6 [ V_11 -> V_11 ] [ V_129 ] ,
& V_130 ) ;
#endif
#ifdef F_83
F_73 ( V_6 [ V_11 -> V_11 ] [ V_131 ] ,
& V_132 ) ;
#endif
#ifdef F_84
F_73 ( V_6 [ V_11 -> V_11 ] [ V_133 ] ,
& V_134 ) ;
#endif
F_77 ( & V_120 ) ;
F_73 ( V_3 [ V_11 -> V_11 ] , V_11 ) ;
return 0 ;
}
void F_85 ( const struct V_1 * V_11 )
{
F_71 ( & V_120 ) ;
F_73 ( V_3 [ V_11 -> V_11 ] , NULL ) ;
F_77 ( & V_120 ) ;
F_79 () ;
F_69 ( V_11 -> V_11 ) ;
F_86 ( V_11 -> V_11 ) ;
}
static void F_87 ( struct V_12 * V_13 )
{
if ( V_13 -> V_99 & V_107 )
F_64 ( V_13 ) ;
}
static int F_88 ( struct V_135 * V_136 ,
const struct V_12 * V_13 ,
struct V_47 * V_48 )
{
struct V_135 * V_137 [ V_138 + 1 ] ;
const struct V_4 * V_46 ;
int V_27 ;
V_27 = F_89 ( V_137 , V_138 , V_136 ,
V_139 , NULL ) ;
if ( V_27 < 0 )
return V_27 ;
V_46 = F_3 ( F_6 ( V_13 ) , F_63 ( V_13 ) ) ;
if ( V_46 -> V_140 )
V_27 = V_46 -> V_140 ( V_137 , V_48 ) ;
return V_27 ;
}
static int
F_90 ( const struct V_135 * V_92 ,
const struct V_12 * V_13 , struct V_47 * V_48 ,
const struct V_1 * V_11 )
{
struct V_135 * V_137 [ V_141 + 1 ] ;
int V_27 ;
memset ( V_48 , 0 , sizeof( * V_48 ) ) ;
V_27 = F_89 ( V_137 , V_141 , V_92 , V_142 , NULL ) ;
if ( V_27 < 0 )
return V_27 ;
V_27 = V_11 -> V_140 ( V_137 , V_48 ) ;
if ( V_27 < 0 )
return V_27 ;
if ( ! V_137 [ V_143 ] )
return 0 ;
return F_88 ( V_137 [ V_143 ] , V_13 , V_48 ) ;
}
static int
F_91 ( struct V_12 * V_13 ,
enum V_65 V_108 ,
const struct V_135 * V_136 )
{
struct V_47 V_48 ;
const struct V_1 * V_11 ;
int V_27 ;
if ( F_92 ( F_49 ( V_13 , V_108 ) ) )
return - V_144 ;
V_11 = F_1 ( F_6 ( V_13 ) ) ;
if ( V_11 == NULL )
return - V_145 ;
if ( V_136 == NULL )
return F_58 ( V_13 , V_108 ) == V_98 ? - V_35 : 0 ;
V_27 = F_90 ( V_136 , V_13 , & V_48 , V_11 ) ;
if ( V_27 < 0 )
return V_27 ;
return F_47 ( V_13 , & V_48 , V_108 ) == V_98 ? - V_35 : 0 ;
}
static int
F_91 ( struct V_12 * V_13 ,
enum V_65 V_108 ,
const struct V_135 * V_136 )
{
return - V_146 ;
}
static int T_3 F_93 ( void )
{
int V_119 , V_69 ;
V_43 = V_147 ;
if ( V_43 < V_103 )
V_43 = V_103 ;
V_105 = F_94 ( & V_43 , 0 ) ;
if ( ! V_105 )
return - V_35 ;
V_119 = F_95 ( & V_148 ) ;
if ( V_119 < 0 ) {
F_96 ( V_105 , V_43 ) ;
F_97 ( V_149 L_2 ) ;
return V_119 ;
}
for ( V_69 = 0 ; V_69 < V_103 ; V_69 ++ )
F_98 ( & V_102 [ V_69 ] ) ;
F_99 ( & V_150 ) ;
F_100 ( V_151 != NULL ) ;
F_73 ( V_151 ,
F_91 ) ;
#ifdef F_101
F_100 ( V_152 != NULL ) ;
F_73 ( V_152 , F_4 ) ;
#endif
return 0 ;
}
static void T_4 F_102 ( void )
{
struct V_115 V_116 = {} ;
unsigned int V_69 ;
F_68 ( V_115 , & V_116 ) ;
F_103 ( & V_148 ) ;
F_104 ( & V_150 ) ;
F_73 ( V_151 , NULL ) ;
#ifdef F_101
F_73 ( V_152 , NULL ) ;
#endif
F_79 () ;
for ( V_69 = 0 ; V_69 < V_153 ; V_69 ++ )
F_105 ( V_6 [ V_69 ] ) ;
F_106 () ;
F_96 ( V_105 , V_43 ) ;
}
