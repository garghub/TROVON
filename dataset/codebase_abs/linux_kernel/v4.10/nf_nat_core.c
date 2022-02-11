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
static T_2 F_20 ( const void * V_41 , T_2 V_42 , T_2 V_43 )
{
const struct V_44 * V_45 ;
const struct V_12 * V_13 = V_41 ;
V_45 = & V_13 -> V_19 [ V_20 ] . V_21 ;
V_43 ^= F_21 ( F_22 ( V_13 ) ) ;
return F_23 ( ( const T_2 * ) & V_45 -> V_22 , sizeof( V_45 -> V_22 ) / sizeof( T_2 ) ,
V_45 -> V_31 . V_5 ^ V_43 ) ;
}
int
F_24 ( const struct V_44 * V_21 ,
const struct V_12 * V_46 )
{
struct V_44 V_47 ;
F_25 ( & V_47 , V_21 ) ;
return F_26 ( & V_47 , V_46 ) ;
}
static int F_27 ( const struct V_1 * V_11 ,
const struct V_4 * V_48 ,
const struct V_44 * V_21 ,
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
const struct V_44 * V_21 )
{
const struct V_44 * V_45 ;
V_45 = & V_13 -> V_19 [ V_20 ] . V_21 ;
return ( V_45 -> V_31 . V_5 == V_21 -> V_31 . V_5 &&
F_29 ( & V_45 -> V_22 . V_57 , & V_21 -> V_22 . V_57 ) &&
V_45 -> V_22 . V_58 . V_59 == V_21 -> V_22 . V_58 . V_59 ) ;
}
static int F_30 ( struct V_60 * V_61 ,
const void * V_62 )
{
const struct V_63 * V_64 = V_61 -> V_64 ;
const struct V_12 * V_13 = V_62 ;
if ( ! F_28 ( V_13 , V_64 -> V_21 ) ||
! F_31 ( F_22 ( V_13 ) , V_64 -> V_28 ) ||
! F_32 ( V_13 , V_64 -> V_65 , V_20 ) )
return 1 ;
return 0 ;
}
static int
F_33 ( struct V_28 * V_28 ,
const struct V_66 * V_65 ,
const struct V_1 * V_11 ,
const struct V_4 * V_48 ,
const struct V_44 * V_21 ,
struct V_44 * V_67 ,
const struct V_49 * V_50 )
{
const struct V_12 * V_13 ;
struct V_63 V_64 = {
. V_28 = V_28 ,
. V_21 = V_21 ,
. V_65 = V_65
} ;
struct V_68 * V_69 ;
V_69 = F_34 ( & V_70 , & V_64 ,
V_71 ) ;
if ( ! V_69 )
return 0 ;
V_13 = F_35 ( V_69 , F_36 ( * V_13 ) , V_72 ) ;
F_25 ( V_67 ,
& V_13 -> V_19 [ V_73 ] . V_21 ) ;
V_67 -> V_31 = V_21 -> V_31 ;
return F_27 ( V_11 , V_48 , V_67 , V_50 ) ;
}
static void
F_37 ( const struct V_66 * V_65 ,
struct V_44 * V_21 ,
const struct V_49 * V_50 ,
const struct V_12 * V_13 ,
enum V_74 V_75 )
{
union V_76 * V_77 ;
unsigned int V_78 , V_79 ;
T_2 V_80 , V_81 , V_82 , V_83 ;
bool V_84 ;
if ( ! ( V_50 -> V_51 & V_52 ) )
return;
if ( V_75 == V_54 )
V_77 = & V_21 -> V_22 . V_57 ;
else
V_77 = & V_21 -> V_31 . V_57 ;
if ( F_29 ( & V_50 -> V_85 , & V_50 -> V_86 ) ) {
* V_77 = V_50 -> V_85 ;
return;
}
if ( F_38 ( V_13 ) == V_87 )
V_79 = sizeof( V_77 -> V_88 ) / sizeof( T_2 ) - 1 ;
else
V_79 = sizeof( V_77 -> V_89 ) / sizeof( T_2 ) - 1 ;
V_82 = F_23 ( ( T_2 * ) & V_21 -> V_22 . V_57 , sizeof( V_21 -> V_22 . V_57 ) / sizeof( T_2 ) ,
V_50 -> V_51 & V_90 ?
0 : ( V_91 T_2 ) V_21 -> V_31 . V_57 . V_59 [ V_79 ] ^ V_65 -> V_92 ) ;
V_84 = false ;
for ( V_78 = 0 ; V_78 <= V_79 ; V_78 ++ ) {
if ( ! V_84 ) {
V_80 = F_39 ( ( V_91 V_93 ) V_50 -> V_85 . V_59 [ V_78 ] ) ;
V_81 = F_39 ( ( V_91 V_93 ) V_50 -> V_86 . V_59 [ V_78 ] ) ;
V_83 = V_81 - V_80 + 1 ;
} else {
V_80 = 0 ;
V_83 = ~ 0 ;
}
V_77 -> V_59 [ V_78 ] = ( V_91 V_94 )
F_40 ( V_80 + F_41 ( V_82 , V_83 ) ) ;
if ( V_77 -> V_59 [ V_78 ] != V_50 -> V_86 . V_59 [ V_78 ] )
V_84 = true ;
if ( ! ( V_50 -> V_51 & V_90 ) )
V_82 ^= ( V_91 T_2 ) V_21 -> V_31 . V_57 . V_59 [ V_78 ] ;
}
}
static void
F_42 ( struct V_44 * V_21 ,
const struct V_44 * V_95 ,
const struct V_49 * V_50 ,
struct V_12 * V_13 ,
enum V_74 V_75 )
{
const struct V_66 * V_65 ;
const struct V_1 * V_11 ;
const struct V_4 * V_48 ;
struct V_28 * V_28 = F_22 ( V_13 ) ;
V_65 = F_43 ( V_13 ) ;
F_6 () ;
V_11 = F_1 ( V_95 -> V_22 . V_23 ) ;
V_48 = F_3 ( V_95 -> V_22 . V_23 ,
V_95 -> V_31 . V_5 ) ;
if ( V_75 == V_54 &&
! ( V_50 -> V_51 & V_96 ) ) {
if ( F_27 ( V_11 , V_48 , V_95 , V_50 ) ) {
if ( ! F_24 ( V_95 , V_13 ) ) {
* V_21 = * V_95 ;
goto V_24;
}
} else if ( F_33 ( V_28 , V_65 , V_11 , V_48 ,
V_95 , V_21 , V_50 ) ) {
F_44 ( L_1 ) ;
if ( ! F_24 ( V_21 , V_13 ) )
goto V_24;
}
}
* V_21 = * V_95 ;
F_37 ( V_65 , V_21 , V_50 , V_13 , V_75 ) ;
if ( ! ( V_50 -> V_51 & V_96 ) ) {
if ( V_50 -> V_51 & V_53 ) {
if ( V_48 -> F_27 ( V_21 , V_75 ,
& V_50 -> V_55 ,
& V_50 -> V_56 ) &&
( V_50 -> V_55 . V_59 == V_50 -> V_56 . V_59 ||
! F_24 ( V_21 , V_13 ) ) )
goto V_24;
} else if ( ! F_24 ( V_21 , V_13 ) ) {
goto V_24;
}
}
V_48 -> V_97 ( V_11 , V_21 , V_50 , V_75 , V_13 ) ;
V_24:
F_8 () ;
}
struct V_98 * F_45 ( struct V_12 * V_13 )
{
struct V_98 * V_99 = F_46 ( V_13 ) ;
if ( V_99 )
return V_99 ;
if ( ! F_47 ( V_13 ) )
V_99 = F_48 ( V_13 , V_100 , V_39 ) ;
return V_99 ;
}
unsigned int
F_49 ( struct V_12 * V_13 ,
const struct V_49 * V_50 ,
enum V_74 V_75 )
{
struct V_44 V_101 , V_102 ;
struct V_98 * V_99 ;
V_99 = F_45 ( V_13 ) ;
if ( V_99 == NULL )
return V_103 ;
F_50 ( V_75 == V_54 ||
V_75 == V_104 ) ;
F_51 ( F_52 ( V_13 , V_75 ) ) ;
F_25 ( & V_101 ,
& V_13 -> V_19 [ V_73 ] . V_21 ) ;
F_42 ( & V_102 , & V_101 , V_50 , V_13 , V_75 ) ;
if ( ! F_53 ( & V_102 , & V_101 ) ) {
struct V_44 V_47 ;
F_25 ( & V_47 , & V_102 ) ;
F_54 ( V_13 , & V_47 ) ;
if ( V_75 == V_54 )
V_13 -> V_105 |= V_26 ;
else
V_13 -> V_105 |= V_25 ;
if ( F_55 ( V_13 ) )
if ( ! F_56 ( V_13 ) )
return V_106 ;
}
if ( V_75 == V_54 ) {
struct V_63 V_64 = {
. V_28 = F_22 ( V_13 ) ,
. V_21 = & V_13 -> V_19 [ V_20 ] . V_21 ,
. V_65 = F_43 ( V_13 ) ,
} ;
int V_32 ;
V_32 = F_57 ( & V_70 ,
& V_64 ,
& V_13 -> V_72 ,
V_71 ) ;
if ( V_32 )
return V_106 ;
}
if ( V_75 == V_104 )
V_13 -> V_105 |= V_107 ;
else
V_13 -> V_105 |= V_108 ;
return V_103 ;
}
static unsigned int
F_58 ( struct V_12 * V_13 , enum V_74 V_109 )
{
union V_76 V_88 =
( V_109 == V_54 ?
V_13 -> V_19 [ V_73 ] . V_21 . V_31 . V_57 :
V_13 -> V_19 [ V_73 ] . V_21 . V_22 . V_57 ) ;
struct V_49 V_50 = {
. V_51 = V_52 ,
. V_85 = V_88 ,
. V_86 = V_88 ,
} ;
return F_49 ( V_13 , & V_50 , V_109 ) ;
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
const struct V_4 * V_48 ;
enum V_16 V_17 = F_7 ( V_15 ) ;
unsigned long V_18 ;
enum V_74 V_111 = F_60 ( V_110 ) ;
if ( V_111 == V_54 )
V_18 = V_26 ;
else
V_18 = V_25 ;
if ( V_17 == V_73 )
V_18 ^= V_112 ;
if ( V_13 -> V_105 & V_18 ) {
struct V_44 V_113 ;
F_25 ( & V_113 , & V_13 -> V_19 [ ! V_17 ] . V_21 ) ;
V_11 = F_1 ( V_113 . V_22 . V_23 ) ;
V_48 = F_3 ( V_113 . V_22 . V_23 ,
V_113 . V_31 . V_5 ) ;
if ( ! V_11 -> V_114 ( V_8 , 0 , V_48 , & V_113 , V_111 ) )
return V_106 ;
}
return V_103 ;
}
static int F_62 ( struct V_12 * V_78 , void * V_41 )
{
const struct V_115 * V_116 = V_41 ;
struct V_98 * V_99 = F_46 ( V_78 ) ;
if ( ! V_99 )
return 0 ;
if ( ( V_116 -> V_11 && F_38 ( V_78 ) != V_116 -> V_11 ) ||
( V_116 -> V_48 && F_63 ( V_78 ) != V_116 -> V_48 ) )
return 0 ;
return V_78 -> V_105 & V_112 ? 1 : 0 ;
}
static int V_115 ( struct V_12 * V_13 , void * V_41 )
{
struct V_98 * V_99 = F_46 ( V_13 ) ;
if ( F_62 ( V_13 , V_41 ) )
return 1 ;
if ( ! V_99 )
return 0 ;
V_13 -> V_105 &= ~ V_117 ;
F_64 ( & V_70 , & V_13 -> V_72 ,
V_71 ) ;
return 0 ;
}
static void F_65 ( T_1 V_11 , T_1 V_48 )
{
struct V_115 V_116 = {
. V_11 = V_11 ,
. V_48 = V_48 ,
} ;
struct V_28 * V_28 ;
F_66 () ;
F_67 (net)
F_68 ( V_28 , F_62 , & V_116 , 0 , 0 ) ;
F_69 () ;
}
static void F_70 ( T_1 V_11 )
{
struct V_115 V_116 = {
. V_11 = V_11 ,
} ;
struct V_28 * V_28 ;
F_66 () ;
F_67 (net)
F_68 ( V_28 , F_62 , & V_116 , 0 , 0 ) ;
F_69 () ;
}
int F_71 ( T_1 V_11 , const struct V_4 * V_48 )
{
const struct V_4 * * V_118 ;
unsigned int V_78 ;
int V_119 = 0 ;
F_72 ( & V_120 ) ;
if ( V_6 [ V_11 ] == NULL ) {
V_118 = F_73 ( V_121 * sizeof( struct V_4 * ) ,
V_122 ) ;
if ( V_118 == NULL ) {
V_119 = - V_40 ;
goto V_24;
}
for ( V_78 = 0 ; V_78 < V_121 ; V_78 ++ )
F_74 ( V_118 [ V_78 ] , & V_123 ) ;
F_75 () ;
V_6 [ V_11 ] = V_118 ;
}
if ( F_76 (
V_6 [ V_11 ] [ V_48 -> V_48 ] ,
F_77 ( & V_120 )
) != & V_123 ) {
V_119 = - V_124 ;
goto V_24;
}
F_74 ( V_6 [ V_11 ] [ V_48 -> V_48 ] , V_48 ) ;
V_24:
F_78 ( & V_120 ) ;
return V_119 ;
}
void F_79 ( T_1 V_11 , const struct V_4 * V_48 )
{
F_72 ( & V_120 ) ;
F_74 ( V_6 [ V_11 ] [ V_48 -> V_48 ] ,
& V_123 ) ;
F_78 ( & V_120 ) ;
F_80 () ;
F_65 ( V_11 , V_48 -> V_48 ) ;
}
int F_81 ( const struct V_1 * V_11 )
{
int V_32 ;
V_32 = F_82 ( V_11 -> V_11 ) ;
if ( V_32 < 0 )
return V_32 ;
F_72 ( & V_120 ) ;
F_74 ( V_6 [ V_11 -> V_11 ] [ V_125 ] ,
& V_126 ) ;
F_74 ( V_6 [ V_11 -> V_11 ] [ V_127 ] ,
& V_128 ) ;
#ifdef F_83
F_74 ( V_6 [ V_11 -> V_11 ] [ V_129 ] ,
& V_130 ) ;
#endif
#ifdef F_84
F_74 ( V_6 [ V_11 -> V_11 ] [ V_131 ] ,
& V_132 ) ;
#endif
#ifdef F_85
F_74 ( V_6 [ V_11 -> V_11 ] [ V_133 ] ,
& V_134 ) ;
#endif
F_78 ( & V_120 ) ;
F_74 ( V_3 [ V_11 -> V_11 ] , V_11 ) ;
return 0 ;
}
void F_86 ( const struct V_1 * V_11 )
{
F_72 ( & V_120 ) ;
F_74 ( V_3 [ V_11 -> V_11 ] , NULL ) ;
F_78 ( & V_120 ) ;
F_80 () ;
F_70 ( V_11 -> V_11 ) ;
F_87 ( V_11 -> V_11 ) ;
}
static void F_88 ( struct V_12 * V_13 )
{
struct V_98 * V_99 = F_89 ( V_13 , V_100 ) ;
if ( ! V_99 )
return;
F_64 ( & V_70 , & V_13 -> V_72 ,
V_71 ) ;
}
static int F_90 ( struct V_135 * V_136 ,
const struct V_12 * V_13 ,
struct V_49 * V_50 )
{
struct V_135 * V_137 [ V_138 + 1 ] ;
const struct V_4 * V_48 ;
int V_32 ;
V_32 = F_91 ( V_137 , V_138 , V_136 , V_139 ) ;
if ( V_32 < 0 )
return V_32 ;
V_48 = F_3 ( F_38 ( V_13 ) , F_63 ( V_13 ) ) ;
if ( V_48 -> V_140 )
V_32 = V_48 -> V_140 ( V_137 , V_50 ) ;
return V_32 ;
}
static int
F_92 ( const struct V_135 * V_99 ,
const struct V_12 * V_13 , struct V_49 * V_50 ,
const struct V_1 * V_11 )
{
struct V_135 * V_137 [ V_141 + 1 ] ;
int V_32 ;
memset ( V_50 , 0 , sizeof( * V_50 ) ) ;
V_32 = F_91 ( V_137 , V_141 , V_99 , V_142 ) ;
if ( V_32 < 0 )
return V_32 ;
V_32 = V_11 -> V_140 ( V_137 , V_50 ) ;
if ( V_32 < 0 )
return V_32 ;
if ( ! V_137 [ V_143 ] )
return 0 ;
return F_90 ( V_137 [ V_143 ] , V_13 , V_50 ) ;
}
static int
F_93 ( struct V_12 * V_13 ,
enum V_74 V_109 ,
const struct V_135 * V_136 )
{
struct V_49 V_50 ;
const struct V_1 * V_11 ;
int V_32 ;
if ( F_94 ( F_52 ( V_13 , V_109 ) ) )
return - V_144 ;
V_11 = F_1 ( F_38 ( V_13 ) ) ;
if ( V_11 == NULL )
return - V_145 ;
if ( V_136 == NULL )
return F_58 ( V_13 , V_109 ) ;
V_32 = F_92 ( V_136 , V_13 , & V_50 , V_11 ) ;
if ( V_32 < 0 )
return V_32 ;
return F_49 ( V_13 , & V_50 , V_109 ) == V_106 ? - V_40 : 0 ;
}
static int
F_93 ( struct V_12 * V_13 ,
enum V_74 V_109 ,
const struct V_135 * V_136 )
{
return - V_146 ;
}
static void T_3 F_95 ( struct V_28 * V_28 )
{
struct V_115 V_116 = {} ;
F_68 ( V_28 , V_115 , & V_116 , 0 , 0 ) ;
}
static int T_4 F_96 ( void )
{
int V_119 ;
V_119 = F_97 ( & V_70 , & V_71 ) ;
if ( V_119 )
return V_119 ;
V_119 = F_98 ( & V_147 ) ;
if ( V_119 < 0 ) {
F_99 ( & V_70 ) ;
F_100 ( V_148 L_2 ) ;
return V_119 ;
}
V_119 = F_101 ( & V_149 ) ;
if ( V_119 < 0 )
goto V_150;
F_102 ( & V_151 ) ;
F_103 ( V_117 ) ;
F_51 ( V_152 != NULL ) ;
F_74 ( V_152 ,
F_93 ) ;
#ifdef F_104
F_51 ( V_153 != NULL ) ;
F_74 ( V_153 , F_4 ) ;
#endif
return 0 ;
V_150:
F_99 ( & V_70 ) ;
F_105 ( & V_147 ) ;
return V_119 ;
}
static void T_5 F_106 ( void )
{
unsigned int V_78 ;
F_107 ( & V_149 ) ;
F_105 ( & V_147 ) ;
F_108 ( & V_151 ) ;
F_74 ( V_152 , NULL ) ;
#ifdef F_104
F_74 ( V_153 , NULL ) ;
#endif
for ( V_78 = 0 ; V_78 < V_154 ; V_78 ++ )
F_109 ( V_6 [ V_78 ] ) ;
F_99 ( & V_70 ) ;
}
