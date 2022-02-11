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
return F_28 ( V_13 , V_64 -> V_21 ) &&
F_31 ( F_22 ( V_13 ) , V_64 -> V_28 ) &&
F_32 ( V_13 , V_64 -> V_65 , V_20 ) ;
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
V_13 = F_34 ( & V_68 , & V_64 ,
V_69 ) ;
if ( ! V_13 )
return 0 ;
F_25 ( V_67 ,
& V_13 -> V_19 [ V_70 ] . V_21 ) ;
V_67 -> V_31 = V_21 -> V_31 ;
return F_27 ( V_11 , V_48 , V_67 , V_50 ) ;
}
static void
F_35 ( const struct V_66 * V_65 ,
struct V_44 * V_21 ,
const struct V_49 * V_50 ,
const struct V_12 * V_13 ,
enum V_71 V_72 )
{
union V_73 * V_74 ;
unsigned int V_75 , V_76 ;
T_2 V_77 , V_78 , V_79 , V_80 ;
bool V_81 ;
if ( ! ( V_50 -> V_51 & V_52 ) )
return;
if ( V_72 == V_54 )
V_74 = & V_21 -> V_22 . V_57 ;
else
V_74 = & V_21 -> V_31 . V_57 ;
if ( F_29 ( & V_50 -> V_82 , & V_50 -> V_83 ) ) {
* V_74 = V_50 -> V_82 ;
return;
}
if ( F_36 ( V_13 ) == V_84 )
V_76 = sizeof( V_74 -> V_85 ) / sizeof( T_2 ) - 1 ;
else
V_76 = sizeof( V_74 -> V_86 ) / sizeof( T_2 ) - 1 ;
V_79 = F_23 ( ( T_2 * ) & V_21 -> V_22 . V_57 , sizeof( V_21 -> V_22 . V_57 ) / sizeof( T_2 ) ,
V_50 -> V_51 & V_87 ?
0 : ( V_88 T_2 ) V_21 -> V_31 . V_57 . V_59 [ V_76 ] ^ V_65 -> V_89 ) ;
V_81 = false ;
for ( V_75 = 0 ; V_75 <= V_76 ; V_75 ++ ) {
if ( ! V_81 ) {
V_77 = F_37 ( ( V_88 V_90 ) V_50 -> V_82 . V_59 [ V_75 ] ) ;
V_78 = F_37 ( ( V_88 V_90 ) V_50 -> V_83 . V_59 [ V_75 ] ) ;
V_80 = V_78 - V_77 + 1 ;
} else {
V_77 = 0 ;
V_80 = ~ 0 ;
}
V_74 -> V_59 [ V_75 ] = ( V_88 V_91 )
F_38 ( V_77 + F_39 ( V_79 , V_80 ) ) ;
if ( V_74 -> V_59 [ V_75 ] != V_50 -> V_83 . V_59 [ V_75 ] )
V_81 = true ;
if ( ! ( V_50 -> V_51 & V_87 ) )
V_79 ^= ( V_88 T_2 ) V_21 -> V_31 . V_57 . V_59 [ V_75 ] ;
}
}
static void
F_40 ( struct V_44 * V_21 ,
const struct V_44 * V_92 ,
const struct V_49 * V_50 ,
struct V_12 * V_13 ,
enum V_71 V_72 )
{
const struct V_66 * V_65 ;
const struct V_1 * V_11 ;
const struct V_4 * V_48 ;
struct V_28 * V_28 = F_22 ( V_13 ) ;
V_65 = F_41 ( V_13 ) ;
F_6 () ;
V_11 = F_1 ( V_92 -> V_22 . V_23 ) ;
V_48 = F_3 ( V_92 -> V_22 . V_23 ,
V_92 -> V_31 . V_5 ) ;
if ( V_72 == V_54 &&
! ( V_50 -> V_51 & V_93 ) ) {
if ( F_27 ( V_11 , V_48 , V_92 , V_50 ) ) {
if ( ! F_24 ( V_92 , V_13 ) ) {
* V_21 = * V_92 ;
goto V_24;
}
} else if ( F_33 ( V_28 , V_65 , V_11 , V_48 ,
V_92 , V_21 , V_50 ) ) {
F_42 ( L_1 ) ;
if ( ! F_24 ( V_21 , V_13 ) )
goto V_24;
}
}
* V_21 = * V_92 ;
F_35 ( V_65 , V_21 , V_50 , V_13 , V_72 ) ;
if ( ! ( V_50 -> V_51 & V_93 ) ) {
if ( V_50 -> V_51 & V_53 ) {
if ( V_48 -> F_27 ( V_21 , V_72 ,
& V_50 -> V_55 ,
& V_50 -> V_56 ) &&
( V_50 -> V_55 . V_59 == V_50 -> V_56 . V_59 ||
! F_24 ( V_21 , V_13 ) ) )
goto V_24;
} else if ( ! F_24 ( V_21 , V_13 ) ) {
goto V_24;
}
}
V_48 -> V_94 ( V_11 , V_21 , V_50 , V_72 , V_13 ) ;
V_24:
F_8 () ;
}
struct V_95 * F_43 ( struct V_12 * V_13 )
{
struct V_95 * V_96 = F_44 ( V_13 ) ;
if ( V_96 )
return V_96 ;
if ( ! F_45 ( V_13 ) )
V_96 = F_46 ( V_13 , V_97 , V_39 ) ;
return V_96 ;
}
unsigned int
F_47 ( struct V_12 * V_13 ,
const struct V_49 * V_50 ,
enum V_71 V_72 )
{
struct V_44 V_98 , V_99 ;
struct V_95 * V_96 ;
V_96 = F_43 ( V_13 ) ;
if ( V_96 == NULL )
return V_100 ;
F_48 ( V_72 == V_54 ||
V_72 == V_101 ) ;
F_49 ( F_50 ( V_13 , V_72 ) ) ;
F_25 ( & V_98 ,
& V_13 -> V_19 [ V_70 ] . V_21 ) ;
F_40 ( & V_99 , & V_98 , V_50 , V_13 , V_72 ) ;
if ( ! F_51 ( & V_99 , & V_98 ) ) {
struct V_44 V_47 ;
F_25 ( & V_47 , & V_99 ) ;
F_52 ( V_13 , & V_47 ) ;
if ( V_72 == V_54 )
V_13 -> V_102 |= V_26 ;
else
V_13 -> V_102 |= V_25 ;
if ( F_53 ( V_13 ) )
if ( ! F_54 ( V_13 ) )
return V_103 ;
}
if ( V_72 == V_54 ) {
int V_32 ;
V_32 = F_55 ( & V_68 ,
& V_13 -> V_104 ,
V_69 ) ;
if ( V_32 )
return V_103 ;
}
if ( V_72 == V_101 )
V_13 -> V_102 |= V_105 ;
else
V_13 -> V_102 |= V_106 ;
return V_100 ;
}
static unsigned int
F_56 ( struct V_12 * V_13 , enum V_71 V_107 )
{
union V_73 V_85 =
( V_107 == V_54 ?
V_13 -> V_19 [ V_70 ] . V_21 . V_31 . V_57 :
V_13 -> V_19 [ V_70 ] . V_21 . V_22 . V_57 ) ;
struct V_49 V_50 = {
. V_51 = V_52 ,
. V_82 = V_85 ,
. V_83 = V_85 ,
} ;
return F_47 ( V_13 , & V_50 , V_107 ) ;
}
unsigned int
F_57 ( struct V_12 * V_13 , unsigned int V_108 )
{
return F_56 ( V_13 , F_58 ( V_108 ) ) ;
}
unsigned int F_59 ( struct V_12 * V_13 ,
enum V_14 V_15 ,
unsigned int V_108 ,
struct V_7 * V_8 )
{
const struct V_1 * V_11 ;
const struct V_4 * V_48 ;
enum V_16 V_17 = F_7 ( V_15 ) ;
unsigned long V_18 ;
enum V_71 V_109 = F_58 ( V_108 ) ;
if ( V_109 == V_54 )
V_18 = V_26 ;
else
V_18 = V_25 ;
if ( V_17 == V_70 )
V_18 ^= V_110 ;
if ( V_13 -> V_102 & V_18 ) {
struct V_44 V_111 ;
F_25 ( & V_111 , & V_13 -> V_19 [ ! V_17 ] . V_21 ) ;
V_11 = F_1 ( V_111 . V_22 . V_23 ) ;
V_48 = F_3 ( V_111 . V_22 . V_23 ,
V_111 . V_31 . V_5 ) ;
if ( ! V_11 -> V_112 ( V_8 , 0 , V_48 , & V_111 , V_109 ) )
return V_103 ;
}
return V_100 ;
}
static int F_60 ( struct V_12 * V_75 , void * V_41 )
{
const struct V_113 * V_114 = V_41 ;
struct V_95 * V_96 = F_44 ( V_75 ) ;
if ( ! V_96 )
return 0 ;
if ( ( V_114 -> V_11 && F_36 ( V_75 ) != V_114 -> V_11 ) ||
( V_114 -> V_48 && F_61 ( V_75 ) != V_114 -> V_48 ) )
return 0 ;
return V_75 -> V_102 & V_110 ? 1 : 0 ;
}
static int V_113 ( struct V_12 * V_13 , void * V_41 )
{
struct V_95 * V_96 = F_44 ( V_13 ) ;
if ( F_60 ( V_13 , V_41 ) )
return 1 ;
if ( ! V_96 )
return 0 ;
if ( ! F_62 ( & V_13 -> V_115 ) )
return 1 ;
V_13 -> V_102 &= ~ V_116 ;
F_63 ( & V_68 , & V_13 -> V_104 ,
V_69 ) ;
F_64 ( & V_13 -> V_115 ) ;
return 0 ;
}
static void F_65 ( T_1 V_11 , T_1 V_48 )
{
struct V_113 V_114 = {
. V_11 = V_11 ,
. V_48 = V_48 ,
} ;
struct V_28 * V_28 ;
F_66 () ;
F_67 (net)
F_68 ( V_28 , F_60 , & V_114 , 0 , 0 ) ;
F_69 () ;
}
static void F_70 ( T_1 V_11 )
{
struct V_113 V_114 = {
. V_11 = V_11 ,
} ;
struct V_28 * V_28 ;
F_66 () ;
F_67 (net)
F_68 ( V_28 , F_60 , & V_114 , 0 , 0 ) ;
F_69 () ;
}
int F_71 ( T_1 V_11 , const struct V_4 * V_48 )
{
const struct V_4 * * V_117 ;
unsigned int V_75 ;
int V_118 = 0 ;
F_72 ( & V_119 ) ;
if ( V_6 [ V_11 ] == NULL ) {
V_117 = F_73 ( V_120 * sizeof( struct V_4 * ) ,
V_121 ) ;
if ( V_117 == NULL ) {
V_118 = - V_40 ;
goto V_24;
}
for ( V_75 = 0 ; V_75 < V_120 ; V_75 ++ )
F_74 ( V_117 [ V_75 ] , & V_122 ) ;
F_75 () ;
V_6 [ V_11 ] = V_117 ;
}
if ( F_76 (
V_6 [ V_11 ] [ V_48 -> V_48 ] ,
F_77 ( & V_119 )
) != & V_122 ) {
V_118 = - V_123 ;
goto V_24;
}
F_74 ( V_6 [ V_11 ] [ V_48 -> V_48 ] , V_48 ) ;
V_24:
F_78 ( & V_119 ) ;
return V_118 ;
}
void F_79 ( T_1 V_11 , const struct V_4 * V_48 )
{
F_72 ( & V_119 ) ;
F_74 ( V_6 [ V_11 ] [ V_48 -> V_48 ] ,
& V_122 ) ;
F_78 ( & V_119 ) ;
F_80 () ;
F_65 ( V_11 , V_48 -> V_48 ) ;
}
int F_81 ( const struct V_1 * V_11 )
{
int V_32 ;
V_32 = F_82 ( V_11 -> V_11 ) ;
if ( V_32 < 0 )
return V_32 ;
F_72 ( & V_119 ) ;
F_74 ( V_6 [ V_11 -> V_11 ] [ V_124 ] ,
& V_125 ) ;
F_74 ( V_6 [ V_11 -> V_11 ] [ V_126 ] ,
& V_127 ) ;
F_78 ( & V_119 ) ;
F_74 ( V_3 [ V_11 -> V_11 ] , V_11 ) ;
return 0 ;
}
void F_83 ( const struct V_1 * V_11 )
{
F_72 ( & V_119 ) ;
F_74 ( V_3 [ V_11 -> V_11 ] , NULL ) ;
F_78 ( & V_119 ) ;
F_80 () ;
F_70 ( V_11 -> V_11 ) ;
F_84 ( V_11 -> V_11 ) ;
}
static void F_85 ( struct V_12 * V_13 )
{
struct V_95 * V_96 = F_86 ( V_13 , V_97 ) ;
if ( ! V_96 )
return;
F_63 ( & V_68 , & V_13 -> V_104 ,
V_69 ) ;
}
static int F_87 ( struct V_128 * V_129 ,
const struct V_12 * V_13 ,
struct V_49 * V_50 )
{
struct V_128 * V_130 [ V_131 + 1 ] ;
const struct V_4 * V_48 ;
int V_32 ;
V_32 = F_88 ( V_130 , V_131 , V_129 , V_132 ) ;
if ( V_32 < 0 )
return V_32 ;
V_48 = F_3 ( F_36 ( V_13 ) , F_61 ( V_13 ) ) ;
if ( V_48 -> V_133 )
V_32 = V_48 -> V_133 ( V_130 , V_50 ) ;
return V_32 ;
}
static int
F_89 ( const struct V_128 * V_96 ,
const struct V_12 * V_13 , struct V_49 * V_50 ,
const struct V_1 * V_11 )
{
struct V_128 * V_130 [ V_134 + 1 ] ;
int V_32 ;
memset ( V_50 , 0 , sizeof( * V_50 ) ) ;
V_32 = F_88 ( V_130 , V_134 , V_96 , V_135 ) ;
if ( V_32 < 0 )
return V_32 ;
V_32 = V_11 -> V_133 ( V_130 , V_50 ) ;
if ( V_32 < 0 )
return V_32 ;
if ( ! V_130 [ V_136 ] )
return 0 ;
return F_87 ( V_130 [ V_136 ] , V_13 , V_50 ) ;
}
static int
F_90 ( struct V_12 * V_13 ,
enum V_71 V_107 ,
const struct V_128 * V_129 )
{
struct V_49 V_50 ;
const struct V_1 * V_11 ;
int V_32 ;
if ( F_91 ( F_50 ( V_13 , V_107 ) ) )
return - V_137 ;
V_11 = F_1 ( F_36 ( V_13 ) ) ;
if ( V_11 == NULL )
return - V_138 ;
if ( V_129 == NULL )
return F_56 ( V_13 , V_107 ) ;
V_32 = F_89 ( V_129 , V_13 , & V_50 , V_11 ) ;
if ( V_32 < 0 )
return V_32 ;
return F_47 ( V_13 , & V_50 , V_107 ) == V_103 ? - V_40 : 0 ;
}
static int
F_90 ( struct V_12 * V_13 ,
enum V_71 V_107 ,
const struct V_128 * V_129 )
{
return - V_139 ;
}
static void T_3 F_92 ( struct V_28 * V_28 )
{
struct V_113 V_114 = {} ;
F_68 ( V_28 , V_113 , & V_114 , 0 , 0 ) ;
}
static int T_4 F_93 ( void )
{
int V_118 ;
V_118 = F_94 ( & V_68 , & V_69 ) ;
if ( V_118 )
return V_118 ;
V_118 = F_95 ( & V_140 ) ;
if ( V_118 < 0 ) {
F_96 ( & V_68 ) ;
F_97 ( V_141 L_2 ) ;
return V_118 ;
}
V_118 = F_98 ( & V_142 ) ;
if ( V_118 < 0 )
goto V_143;
F_99 ( & V_144 ) ;
F_100 ( V_116 ) ;
F_49 ( V_145 != NULL ) ;
F_74 ( V_145 ,
F_90 ) ;
#ifdef F_101
F_49 ( V_146 != NULL ) ;
F_74 ( V_146 , F_4 ) ;
#endif
return 0 ;
V_143:
F_96 ( & V_68 ) ;
F_102 ( & V_140 ) ;
return V_118 ;
}
static void T_5 F_103 ( void )
{
unsigned int V_75 ;
F_104 ( & V_142 ) ;
F_102 ( & V_140 ) ;
F_105 ( & V_144 ) ;
F_74 ( V_145 , NULL ) ;
#ifdef F_101
F_74 ( V_146 , NULL ) ;
#endif
for ( V_75 = 0 ; V_75 < V_147 ; V_75 ++ )
F_106 ( V_6 [ V_75 ] ) ;
F_96 ( & V_68 ) ;
}
