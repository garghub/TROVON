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
static T_2 F_19 ( const void * V_36 , T_2 V_37 , T_2 V_38 )
{
const struct V_39 * V_40 ;
const struct V_12 * V_13 = V_36 ;
V_40 = & V_13 -> V_41 [ V_19 ] . V_42 ;
V_38 ^= F_20 ( F_21 ( V_13 ) ) ;
return F_22 ( ( const T_2 * ) & V_40 -> V_43 , sizeof( V_40 -> V_43 ) / sizeof( T_2 ) ,
V_40 -> V_26 . V_5 ^ V_38 ) ;
}
int
F_23 ( const struct V_39 * V_42 ,
const struct V_12 * V_44 )
{
struct V_39 V_45 ;
F_24 ( & V_45 , V_42 ) ;
return F_25 ( & V_45 , V_44 ) ;
}
static int F_26 ( const struct V_1 * V_11 ,
const struct V_4 * V_46 ,
const struct V_39 * V_42 ,
const struct V_47 * V_48 )
{
if ( V_48 -> V_49 & V_50 &&
! V_11 -> F_26 ( V_42 , V_48 ) )
return 0 ;
if ( ! ( V_48 -> V_49 & V_51 ) ||
V_46 -> F_26 ( V_42 , V_52 ,
& V_48 -> V_53 , & V_48 -> V_54 ) )
return 1 ;
return 0 ;
}
static inline int
F_27 ( const struct V_12 * V_13 ,
const struct V_39 * V_42 )
{
const struct V_39 * V_40 ;
V_40 = & V_13 -> V_41 [ V_19 ] . V_42 ;
return ( V_40 -> V_26 . V_5 == V_42 -> V_26 . V_5 &&
F_28 ( & V_40 -> V_43 . V_55 , & V_42 -> V_43 . V_55 ) &&
V_40 -> V_43 . V_56 . V_57 == V_42 -> V_43 . V_56 . V_57 ) ;
}
static int F_29 ( struct V_58 * V_59 ,
const void * V_60 )
{
const struct V_61 * V_62 = V_59 -> V_62 ;
const struct V_12 * V_13 = V_60 ;
if ( ! F_27 ( V_13 , V_62 -> V_42 ) ||
! F_30 ( F_21 ( V_13 ) , V_62 -> V_23 ) ||
! F_31 ( V_13 , V_62 -> V_63 , V_19 ) )
return 1 ;
return 0 ;
}
static int
F_32 ( struct V_23 * V_23 ,
const struct V_64 * V_63 ,
const struct V_1 * V_11 ,
const struct V_4 * V_46 ,
const struct V_39 * V_42 ,
struct V_39 * V_65 ,
const struct V_47 * V_48 )
{
const struct V_12 * V_13 ;
struct V_61 V_62 = {
. V_23 = V_23 ,
. V_42 = V_42 ,
. V_63 = V_63
} ;
struct V_66 * V_67 ;
V_67 = F_33 ( & V_68 , & V_62 ,
V_69 ) ;
if ( ! V_67 )
return 0 ;
V_13 = F_34 ( V_67 , F_35 ( * V_13 ) , V_70 ) ;
F_24 ( V_65 ,
& V_13 -> V_41 [ V_71 ] . V_42 ) ;
V_65 -> V_26 = V_42 -> V_26 ;
return F_26 ( V_11 , V_46 , V_65 , V_48 ) ;
}
static void
F_36 ( const struct V_64 * V_63 ,
struct V_39 * V_42 ,
const struct V_47 * V_48 ,
const struct V_12 * V_13 ,
enum V_72 V_73 )
{
union V_74 * V_75 ;
unsigned int V_76 , V_77 ;
T_2 V_78 , V_79 , V_80 , V_81 ;
bool V_82 ;
if ( ! ( V_48 -> V_49 & V_50 ) )
return;
if ( V_73 == V_52 )
V_75 = & V_42 -> V_43 . V_55 ;
else
V_75 = & V_42 -> V_26 . V_55 ;
if ( F_28 ( & V_48 -> V_83 , & V_48 -> V_84 ) ) {
* V_75 = V_48 -> V_83 ;
return;
}
if ( F_6 ( V_13 ) == V_85 )
V_77 = sizeof( V_75 -> V_86 ) / sizeof( T_2 ) - 1 ;
else
V_77 = sizeof( V_75 -> V_87 ) / sizeof( T_2 ) - 1 ;
V_80 = F_22 ( ( T_2 * ) & V_42 -> V_43 . V_55 , sizeof( V_42 -> V_43 . V_55 ) / sizeof( T_2 ) ,
V_48 -> V_49 & V_88 ?
0 : ( V_89 T_2 ) V_42 -> V_26 . V_55 . V_57 [ V_77 ] ^ V_63 -> V_90 ) ;
V_82 = false ;
for ( V_76 = 0 ; V_76 <= V_77 ; V_76 ++ ) {
if ( ! V_82 ) {
V_78 = F_37 ( ( V_89 V_91 ) V_48 -> V_83 . V_57 [ V_76 ] ) ;
V_79 = F_37 ( ( V_89 V_91 ) V_48 -> V_84 . V_57 [ V_76 ] ) ;
V_81 = V_79 - V_78 + 1 ;
} else {
V_78 = 0 ;
V_81 = ~ 0 ;
}
V_75 -> V_57 [ V_76 ] = ( V_89 V_92 )
F_38 ( V_78 + F_39 ( V_80 , V_81 ) ) ;
if ( V_75 -> V_57 [ V_76 ] != V_48 -> V_84 . V_57 [ V_76 ] )
V_82 = true ;
if ( ! ( V_48 -> V_49 & V_88 ) )
V_80 ^= ( V_89 T_2 ) V_42 -> V_26 . V_55 . V_57 [ V_76 ] ;
}
}
static void
F_40 ( struct V_39 * V_42 ,
const struct V_39 * V_93 ,
const struct V_47 * V_48 ,
struct V_12 * V_13 ,
enum V_72 V_73 )
{
const struct V_64 * V_63 ;
const struct V_1 * V_11 ;
const struct V_4 * V_46 ;
struct V_23 * V_23 = F_21 ( V_13 ) ;
V_63 = F_41 ( V_13 ) ;
F_42 () ;
V_11 = F_1 ( V_93 -> V_43 . V_94 ) ;
V_46 = F_3 ( V_93 -> V_43 . V_94 ,
V_93 -> V_26 . V_5 ) ;
if ( V_73 == V_52 &&
! ( V_48 -> V_49 & V_95 ) ) {
if ( F_26 ( V_11 , V_46 , V_93 , V_48 ) ) {
if ( ! F_23 ( V_93 , V_13 ) ) {
* V_42 = * V_93 ;
goto V_96;
}
} else if ( F_32 ( V_23 , V_63 , V_11 , V_46 ,
V_93 , V_42 , V_48 ) ) {
F_43 ( L_1 ) ;
if ( ! F_23 ( V_42 , V_13 ) )
goto V_96;
}
}
* V_42 = * V_93 ;
F_36 ( V_63 , V_42 , V_48 , V_13 , V_73 ) ;
if ( ! ( V_48 -> V_49 & V_95 ) ) {
if ( V_48 -> V_49 & V_51 ) {
if ( V_46 -> F_26 ( V_42 , V_73 ,
& V_48 -> V_53 ,
& V_48 -> V_54 ) &&
( V_48 -> V_53 . V_57 == V_48 -> V_54 . V_57 ||
! F_23 ( V_42 , V_13 ) ) )
goto V_96;
} else if ( ! F_23 ( V_42 , V_13 ) ) {
goto V_96;
}
}
V_46 -> V_97 ( V_11 , V_42 , V_48 , V_73 , V_13 ) ;
V_96:
F_44 () ;
}
struct V_98 * F_45 ( struct V_12 * V_13 )
{
struct V_98 * V_99 = F_46 ( V_13 ) ;
if ( V_99 )
return V_99 ;
if ( ! F_47 ( V_13 ) )
V_99 = F_48 ( V_13 , V_100 , V_34 ) ;
return V_99 ;
}
unsigned int
F_49 ( struct V_12 * V_13 ,
const struct V_47 * V_48 ,
enum V_72 V_73 )
{
struct V_39 V_101 , V_102 ;
if ( F_47 ( V_13 ) )
return V_103 ;
F_50 ( V_73 == V_52 ||
V_73 == V_104 ) ;
F_51 ( F_52 ( V_13 , V_73 ) ) ;
F_24 ( & V_101 ,
& V_13 -> V_41 [ V_71 ] . V_42 ) ;
F_40 ( & V_102 , & V_101 , V_48 , V_13 , V_73 ) ;
if ( ! F_53 ( & V_102 , & V_101 ) ) {
struct V_39 V_45 ;
F_24 ( & V_45 , & V_102 ) ;
F_54 ( V_13 , & V_45 ) ;
if ( V_73 == V_52 )
V_13 -> V_105 |= V_21 ;
else
V_13 -> V_105 |= V_20 ;
if ( F_55 ( V_13 ) )
if ( ! F_56 ( V_13 ) )
return V_106 ;
}
if ( V_73 == V_52 ) {
struct V_61 V_62 = {
. V_23 = F_21 ( V_13 ) ,
. V_42 = & V_13 -> V_41 [ V_19 ] . V_42 ,
. V_63 = F_41 ( V_13 ) ,
} ;
int V_27 ;
V_27 = F_57 ( & V_68 ,
& V_62 ,
& V_13 -> V_70 ,
V_69 ) ;
if ( V_27 )
return V_106 ;
}
if ( V_73 == V_104 )
V_13 -> V_105 |= V_107 ;
else
V_13 -> V_105 |= V_108 ;
return V_103 ;
}
static unsigned int
F_58 ( struct V_12 * V_13 , enum V_72 V_109 )
{
union V_74 V_86 =
( V_109 == V_52 ?
V_13 -> V_41 [ V_71 ] . V_42 . V_26 . V_55 :
V_13 -> V_41 [ V_71 ] . V_42 . V_43 . V_55 ) ;
struct V_47 V_48 = {
. V_49 = V_50 ,
. V_83 = V_86 ,
. V_84 = V_86 ,
} ;
return F_49 ( V_13 , & V_48 , V_109 ) ;
}
unsigned int
F_59 ( struct V_12 * V_13 , unsigned int V_110 )
{
return F_58 ( V_13 , F_60 ( V_110 ) ) ;
}
unsigned int F_61 ( struct V_12 * V_13 ,
enum V_14 V_15 ,
unsigned int V_110 ,
struct V_7 * V_8 )
{
const struct V_1 * V_11 ;
const struct V_4 * V_46 ;
enum V_16 V_17 = F_7 ( V_15 ) ;
unsigned long V_18 ;
enum V_72 V_111 = F_60 ( V_110 ) ;
if ( V_111 == V_52 )
V_18 = V_21 ;
else
V_18 = V_20 ;
if ( V_17 == V_71 )
V_18 ^= V_112 ;
if ( V_13 -> V_105 & V_18 ) {
struct V_39 V_113 ;
F_24 ( & V_113 , & V_13 -> V_41 [ ! V_17 ] . V_42 ) ;
V_11 = F_1 ( V_113 . V_43 . V_94 ) ;
V_46 = F_3 ( V_113 . V_43 . V_94 ,
V_113 . V_26 . V_5 ) ;
if ( ! V_11 -> V_114 ( V_8 , 0 , V_46 , & V_113 , V_111 ) )
return V_106 ;
}
return V_103 ;
}
static int F_62 ( struct V_12 * V_76 , void * V_36 )
{
const struct V_115 * V_116 = V_36 ;
if ( ( V_116 -> V_11 && F_6 ( V_76 ) != V_116 -> V_11 ) ||
( V_116 -> V_46 && F_63 ( V_76 ) != V_116 -> V_46 ) )
return 0 ;
return V_76 -> V_105 & V_112 ? 1 : 0 ;
}
static int V_115 ( struct V_12 * V_13 , void * V_36 )
{
if ( F_62 ( V_13 , V_36 ) )
return 1 ;
if ( ( V_13 -> V_105 & V_108 ) == 0 )
return 0 ;
F_64 ( V_117 , & V_13 -> V_105 ) ;
F_65 ( & V_68 , & V_13 -> V_70 ,
V_69 ) ;
return 0 ;
}
static void F_66 ( T_1 V_11 , T_1 V_46 )
{
struct V_115 V_116 = {
. V_11 = V_11 ,
. V_46 = V_46 ,
} ;
struct V_23 * V_23 ;
F_67 () ;
F_68 (net)
F_69 ( V_23 , F_62 , & V_116 , 0 , 0 ) ;
F_70 () ;
}
static void F_71 ( T_1 V_11 )
{
struct V_115 V_116 = {
. V_11 = V_11 ,
} ;
struct V_23 * V_23 ;
F_67 () ;
F_68 (net)
F_69 ( V_23 , F_62 , & V_116 , 0 , 0 ) ;
F_70 () ;
}
int F_72 ( T_1 V_11 , const struct V_4 * V_46 )
{
const struct V_4 * * V_118 ;
unsigned int V_76 ;
int V_119 = 0 ;
F_73 ( & V_120 ) ;
if ( V_6 [ V_11 ] == NULL ) {
V_118 = F_74 ( V_121 * sizeof( struct V_4 * ) ,
V_122 ) ;
if ( V_118 == NULL ) {
V_119 = - V_35 ;
goto V_96;
}
for ( V_76 = 0 ; V_76 < V_121 ; V_76 ++ )
F_75 ( V_118 [ V_76 ] , & V_123 ) ;
F_76 () ;
V_6 [ V_11 ] = V_118 ;
}
if ( F_77 (
V_6 [ V_11 ] [ V_46 -> V_46 ] ,
F_78 ( & V_120 )
) != & V_123 ) {
V_119 = - V_124 ;
goto V_96;
}
F_75 ( V_6 [ V_11 ] [ V_46 -> V_46 ] , V_46 ) ;
V_96:
F_79 ( & V_120 ) ;
return V_119 ;
}
void F_80 ( T_1 V_11 , const struct V_4 * V_46 )
{
F_73 ( & V_120 ) ;
F_75 ( V_6 [ V_11 ] [ V_46 -> V_46 ] ,
& V_123 ) ;
F_79 ( & V_120 ) ;
F_81 () ;
F_66 ( V_11 , V_46 -> V_46 ) ;
}
int F_82 ( const struct V_1 * V_11 )
{
int V_27 ;
V_27 = F_83 ( V_11 -> V_11 ) ;
if ( V_27 < 0 )
return V_27 ;
F_73 ( & V_120 ) ;
F_75 ( V_6 [ V_11 -> V_11 ] [ V_125 ] ,
& V_126 ) ;
F_75 ( V_6 [ V_11 -> V_11 ] [ V_127 ] ,
& V_128 ) ;
#ifdef F_84
F_75 ( V_6 [ V_11 -> V_11 ] [ V_129 ] ,
& V_130 ) ;
#endif
#ifdef F_85
F_75 ( V_6 [ V_11 -> V_11 ] [ V_131 ] ,
& V_132 ) ;
#endif
#ifdef F_86
F_75 ( V_6 [ V_11 -> V_11 ] [ V_133 ] ,
& V_134 ) ;
#endif
F_79 ( & V_120 ) ;
F_75 ( V_3 [ V_11 -> V_11 ] , V_11 ) ;
return 0 ;
}
void F_87 ( const struct V_1 * V_11 )
{
F_73 ( & V_120 ) ;
F_75 ( V_3 [ V_11 -> V_11 ] , NULL ) ;
F_79 ( & V_120 ) ;
F_81 () ;
F_71 ( V_11 -> V_11 ) ;
F_88 ( V_11 -> V_11 ) ;
}
static void F_89 ( struct V_12 * V_13 )
{
if ( V_13 -> V_105 & V_108 )
F_65 ( & V_68 , & V_13 -> V_70 ,
V_69 ) ;
}
static int F_90 ( struct V_135 * V_136 ,
const struct V_12 * V_13 ,
struct V_47 * V_48 )
{
struct V_135 * V_137 [ V_138 + 1 ] ;
const struct V_4 * V_46 ;
int V_27 ;
V_27 = F_91 ( V_137 , V_138 , V_136 ,
V_139 , NULL ) ;
if ( V_27 < 0 )
return V_27 ;
V_46 = F_3 ( F_6 ( V_13 ) , F_63 ( V_13 ) ) ;
if ( V_46 -> V_140 )
V_27 = V_46 -> V_140 ( V_137 , V_48 ) ;
return V_27 ;
}
static int
F_92 ( const struct V_135 * V_99 ,
const struct V_12 * V_13 , struct V_47 * V_48 ,
const struct V_1 * V_11 )
{
struct V_135 * V_137 [ V_141 + 1 ] ;
int V_27 ;
memset ( V_48 , 0 , sizeof( * V_48 ) ) ;
V_27 = F_91 ( V_137 , V_141 , V_99 , V_142 , NULL ) ;
if ( V_27 < 0 )
return V_27 ;
V_27 = V_11 -> V_140 ( V_137 , V_48 ) ;
if ( V_27 < 0 )
return V_27 ;
if ( ! V_137 [ V_143 ] )
return 0 ;
return F_90 ( V_137 [ V_143 ] , V_13 , V_48 ) ;
}
static int
F_93 ( struct V_12 * V_13 ,
enum V_72 V_109 ,
const struct V_135 * V_136 )
{
struct V_47 V_48 ;
const struct V_1 * V_11 ;
int V_27 ;
if ( F_94 ( F_52 ( V_13 , V_109 ) ) )
return - V_144 ;
V_11 = F_1 ( F_6 ( V_13 ) ) ;
if ( V_11 == NULL )
return - V_145 ;
if ( V_136 == NULL )
return F_58 ( V_13 , V_109 ) == V_106 ? - V_35 : 0 ;
V_27 = F_92 ( V_136 , V_13 , & V_48 , V_11 ) ;
if ( V_27 < 0 )
return V_27 ;
return F_49 ( V_13 , & V_48 , V_109 ) == V_106 ? - V_35 : 0 ;
}
static int
F_93 ( struct V_12 * V_13 ,
enum V_72 V_109 ,
const struct V_135 * V_136 )
{
return - V_146 ;
}
static void T_3 F_95 ( struct V_23 * V_23 )
{
struct V_115 V_116 = {} ;
F_69 ( V_23 , V_115 , & V_116 , 0 , 0 ) ;
}
static int T_4 F_96 ( void )
{
int V_119 ;
V_119 = F_97 ( & V_68 , & V_69 ) ;
if ( V_119 )
return V_119 ;
V_119 = F_98 ( & V_147 ) ;
if ( V_119 < 0 ) {
F_99 ( & V_68 ) ;
F_100 ( V_148 L_2 ) ;
return V_119 ;
}
V_119 = F_101 ( & V_149 ) ;
if ( V_119 < 0 )
goto V_150;
F_102 ( & V_151 ) ;
F_51 ( V_152 != NULL ) ;
F_75 ( V_152 ,
F_93 ) ;
#ifdef F_103
F_51 ( V_153 != NULL ) ;
F_75 ( V_153 , F_4 ) ;
#endif
return 0 ;
V_150:
F_99 ( & V_68 ) ;
F_104 ( & V_147 ) ;
return V_119 ;
}
static void T_5 F_105 ( void )
{
unsigned int V_76 ;
F_106 ( & V_149 ) ;
F_104 ( & V_147 ) ;
F_107 ( & V_151 ) ;
F_75 ( V_152 , NULL ) ;
#ifdef F_103
F_75 ( V_153 , NULL ) ;
#endif
F_81 () ;
for ( V_76 = 0 ; V_76 < V_154 ; V_76 ++ )
F_108 ( V_6 [ V_76 ] ) ;
F_99 ( & V_68 ) ;
}
