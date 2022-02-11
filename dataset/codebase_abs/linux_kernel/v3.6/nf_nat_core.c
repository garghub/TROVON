static inline const struct V_1 *
F_1 ( T_1 V_2 )
{
return F_2 ( V_3 [ V_2 ] ) ;
}
static inline unsigned int
F_3 ( const struct V_4 * V_4 , T_2 V_5 ,
const struct V_6 * V_7 )
{
unsigned int V_8 ;
V_8 = F_4 ( ( V_9 V_10 ) V_7 -> V_11 . V_12 . V_13 ,
( V_9 V_10 ) V_7 -> V_11 . V_14 . V_15 ^ V_5 ,
V_7 -> V_16 . V_2 , V_17 ) ;
return ( ( V_18 ) V_8 * V_4 -> V_19 . V_20 ) >> 32 ;
}
int
F_5 ( const struct V_6 * V_7 ,
const struct V_21 * V_22 )
{
struct V_6 V_23 ;
F_6 ( & V_23 , V_7 ) ;
return F_7 ( & V_23 , V_22 ) ;
}
static int
F_8 ( const struct V_6 * V_7 ,
const struct V_24 * V_25 )
{
const struct V_1 * V_26 ;
int V_27 = 0 ;
if ( V_25 -> V_28 & V_29 ) {
if ( F_9 ( V_7 -> V_11 . V_12 . V_13 ) < F_9 ( V_25 -> V_30 ) ||
F_9 ( V_7 -> V_11 . V_12 . V_13 ) > F_9 ( V_25 -> V_31 ) )
return 0 ;
}
F_10 () ;
V_26 = F_1 ( V_7 -> V_16 . V_2 ) ;
if ( ! ( V_25 -> V_28 & V_32 ) ||
V_26 -> F_8 ( V_7 , V_33 ,
& V_25 -> V_34 , & V_25 -> V_35 ) )
V_27 = 1 ;
F_11 () ;
return V_27 ;
}
static inline int
F_12 ( const struct V_21 * V_36 ,
const struct V_6 * V_7 )
{
const struct V_6 * V_37 ;
V_37 = & V_36 -> V_38 [ V_39 ] . V_7 ;
return ( V_37 -> V_16 . V_2 == V_7 -> V_16 . V_2 &&
V_37 -> V_11 . V_12 . V_13 == V_7 -> V_11 . V_12 . V_13 &&
V_37 -> V_11 . V_14 . V_15 == V_7 -> V_11 . V_14 . V_15 ) ;
}
static int
F_13 ( struct V_4 * V_4 , T_2 V_5 ,
const struct V_6 * V_7 ,
struct V_6 * V_40 ,
const struct V_24 * V_25 )
{
unsigned int V_41 = F_3 ( V_4 , V_5 , V_7 ) ;
const struct V_42 * V_43 ;
const struct V_21 * V_36 ;
const struct V_44 * V_45 ;
F_10 () ;
F_14 (nat, n, &net->ipv4.nat_bysource[h], bysource) {
V_36 = V_43 -> V_36 ;
if ( F_12 ( V_36 , V_7 ) && F_15 ( V_36 ) == V_5 ) {
F_6 ( V_40 ,
& V_36 -> V_38 [ V_46 ] . V_7 ) ;
V_40 -> V_16 = V_7 -> V_16 ;
if ( F_8 ( V_40 , V_25 ) ) {
F_11 () ;
return 1 ;
}
}
}
F_11 () ;
return 0 ;
}
static void
F_16 ( T_2 V_5 , struct V_6 * V_7 ,
const struct V_24 * V_25 ,
const struct V_21 * V_36 ,
enum V_47 V_48 )
{
T_3 * V_49 ;
T_4 V_50 , V_51 , V_52 ;
if ( ! ( V_25 -> V_28 & V_29 ) )
return;
if ( V_48 == V_33 )
V_49 = & V_7 -> V_11 . V_12 . V_13 ;
else
V_49 = & V_7 -> V_16 . V_12 . V_13 ;
if ( V_25 -> V_30 == V_25 -> V_31 ) {
* V_49 = V_25 -> V_30 ;
return;
}
V_50 = F_9 ( V_25 -> V_30 ) ;
V_51 = F_9 ( V_25 -> V_31 ) ;
V_52 = F_17 ( ( V_9 V_10 ) V_7 -> V_11 . V_12 . V_13 ,
V_25 -> V_28 & V_53 ?
0 : ( V_9 V_10 ) V_7 -> V_16 . V_12 . V_13 ^ V_5 , 0 ) ;
V_52 = ( ( V_18 ) V_52 * ( V_51 - V_50 + 1 ) ) >> 32 ;
* V_49 = F_18 ( V_50 + V_52 ) ;
}
static void
F_19 ( struct V_6 * V_7 ,
const struct V_6 * V_54 ,
const struct V_24 * V_25 ,
struct V_21 * V_36 ,
enum V_47 V_48 )
{
struct V_4 * V_4 = F_20 ( V_36 ) ;
const struct V_1 * V_26 ;
T_2 V_5 = F_15 ( V_36 ) ;
if ( V_48 == V_33 &&
! ( V_25 -> V_28 & V_55 ) ) {
if ( F_8 ( V_54 , V_25 ) ) {
if ( ! F_5 ( V_54 , V_36 ) ) {
* V_7 = * V_54 ;
return;
}
} else if ( F_13 ( V_4 , V_5 , V_54 , V_7 ,
V_25 ) ) {
F_21 ( L_1 ) ;
if ( ! F_5 ( V_7 , V_36 ) )
return;
}
}
* V_7 = * V_54 ;
F_16 ( V_5 , V_7 , V_25 , V_36 , V_48 ) ;
F_10 () ;
V_26 = F_1 ( V_54 -> V_16 . V_2 ) ;
if ( ! ( V_25 -> V_28 & V_55 ) ) {
if ( V_25 -> V_28 & V_32 ) {
if ( V_26 -> F_8 ( V_7 , V_48 , & V_25 -> V_34 ,
& V_25 -> V_35 ) &&
( V_25 -> V_34 . V_15 == V_25 -> V_35 . V_15 ||
! F_5 ( V_7 , V_36 ) ) )
goto V_56;
} else if ( ! F_5 ( V_7 , V_36 ) ) {
goto V_56;
}
}
V_26 -> V_57 ( V_7 , V_25 , V_48 , V_36 ) ;
V_56:
F_11 () ;
}
unsigned int
F_22 ( struct V_21 * V_36 ,
const struct V_24 * V_25 ,
enum V_47 V_48 )
{
struct V_4 * V_4 = F_20 ( V_36 ) ;
struct V_6 V_58 , V_59 ;
struct V_42 * V_43 ;
V_43 = F_23 ( V_36 ) ;
if ( ! V_43 ) {
V_43 = F_24 ( V_36 , V_60 , V_61 ) ;
if ( V_43 == NULL ) {
F_21 ( L_2 ) ;
return V_62 ;
}
}
F_25 ( V_48 == V_33 ||
V_48 == V_63 ) ;
F_26 ( F_27 ( V_36 , V_48 ) ) ;
F_6 ( & V_58 ,
& V_36 -> V_38 [ V_46 ] . V_7 ) ;
F_19 ( & V_59 , & V_58 , V_25 , V_36 , V_48 ) ;
if ( ! F_28 ( & V_59 , & V_58 ) ) {
struct V_6 V_23 ;
F_6 ( & V_23 , & V_59 ) ;
F_29 ( V_36 , & V_23 ) ;
if ( V_48 == V_33 )
V_36 -> V_64 |= V_65 ;
else
V_36 -> V_64 |= V_66 ;
}
if ( V_48 == V_33 ) {
unsigned int V_67 ;
V_67 = F_3 ( V_4 , F_15 ( V_36 ) ,
& V_36 -> V_38 [ V_39 ] . V_7 ) ;
F_30 ( & V_68 ) ;
V_43 = F_23 ( V_36 ) ;
V_43 -> V_36 = V_36 ;
F_31 ( & V_43 -> V_69 ,
& V_4 -> V_19 . V_70 [ V_67 ] ) ;
F_32 ( & V_68 ) ;
}
if ( V_48 == V_63 )
V_36 -> V_64 |= V_71 ;
else
V_36 -> V_64 |= V_72 ;
return V_62 ;
}
static bool
F_33 ( T_5 V_26 ,
struct V_73 * V_74 ,
unsigned int V_75 ,
const struct V_6 * V_76 ,
enum V_47 V_48 )
{
struct V_77 * V_78 ;
const struct V_1 * V_79 ;
if ( ! F_34 ( V_74 , V_75 + sizeof( * V_78 ) ) )
return false ;
V_78 = ( void * ) V_74 -> V_80 + V_75 ;
V_79 = F_1 ( V_26 ) ;
if ( ! V_79 -> F_33 ( V_74 , V_75 , V_76 , V_48 ) )
return false ;
V_78 = ( void * ) V_74 -> V_80 + V_75 ;
if ( V_48 == V_33 ) {
F_35 ( & V_78 -> V_81 , V_78 -> V_82 , V_76 -> V_11 . V_12 . V_13 ) ;
V_78 -> V_82 = V_76 -> V_11 . V_12 . V_13 ;
} else {
F_35 ( & V_78 -> V_81 , V_78 -> V_83 , V_76 -> V_16 . V_12 . V_13 ) ;
V_78 -> V_83 = V_76 -> V_16 . V_12 . V_13 ;
}
return true ;
}
unsigned int F_36 ( struct V_21 * V_36 ,
enum V_84 V_85 ,
unsigned int V_86 ,
struct V_73 * V_74 )
{
enum V_87 V_88 = F_37 ( V_85 ) ;
unsigned long V_89 ;
enum V_47 V_90 = F_38 ( V_86 ) ;
if ( V_90 == V_33 )
V_89 = V_65 ;
else
V_89 = V_66 ;
if ( V_88 == V_46 )
V_89 ^= V_91 ;
if ( V_36 -> V_64 & V_89 ) {
struct V_6 V_76 ;
F_6 ( & V_76 , & V_36 -> V_38 [ ! V_88 ] . V_7 ) ;
if ( ! F_33 ( V_76 . V_16 . V_2 , V_74 , 0 , & V_76 , V_90 ) )
return V_92 ;
}
return V_62 ;
}
int F_39 ( struct V_21 * V_36 ,
enum V_84 V_85 ,
unsigned int V_86 ,
struct V_73 * V_74 )
{
struct {
struct V_93 V_94 ;
struct V_77 V_13 ;
} * V_95 ;
struct V_6 V_76 ;
int V_96 = F_40 ( V_74 ) ;
enum V_87 V_88 = F_37 ( V_85 ) ;
unsigned long V_89 ;
enum V_47 V_97 = F_38 ( V_86 ) ;
if ( ! F_34 ( V_74 , V_96 + sizeof( * V_95 ) ) )
return 0 ;
V_95 = ( void * ) V_74 -> V_80 + V_96 ;
if ( F_41 ( V_74 , V_86 , V_96 , 0 ) )
return 0 ;
F_25 ( V_74 -> V_98 == V_99 ||
V_74 -> V_98 == V_100 ) ;
if ( V_95 -> V_94 . type == V_101 ) {
if ( ( V_36 -> V_64 & V_102 ) != V_102 )
return 0 ;
if ( V_36 -> V_64 & V_91 )
return 0 ;
}
if ( V_97 == V_33 )
V_89 = V_65 ;
else
V_89 = V_66 ;
if ( V_88 == V_46 )
V_89 ^= V_91 ;
if ( ! ( V_36 -> V_64 & V_89 ) )
return 1 ;
F_21 ( L_3
L_4 , V_74 , V_97 ,
V_88 == V_39 ? L_5 : L_6 ) ;
if ( ! F_33 ( V_95 -> V_13 . V_103 , V_74 , V_96 + sizeof( V_95 -> V_94 ) ,
& V_36 -> V_38 [ ! V_88 ] . V_7 , ! V_97 ) )
return 0 ;
if ( V_74 -> V_104 != V_105 ) {
V_95 = ( void * ) V_74 -> V_80 + V_96 ;
V_95 -> V_94 . V_106 = 0 ;
V_95 -> V_94 . V_106 =
F_42 ( F_43 ( V_74 , V_96 ,
V_74 -> V_107 - V_96 , 0 ) ) ;
}
F_6 ( & V_76 , & V_36 -> V_38 [ ! V_88 ] . V_7 ) ;
if ( ! F_33 ( 0 , V_74 , 0 , & V_76 , V_97 ) )
return 0 ;
return 1 ;
}
int F_44 ( const struct V_1 * V_26 )
{
int V_27 = 0 ;
F_30 ( & V_68 ) ;
if ( F_45 (
V_3 [ V_26 -> V_2 ] ,
F_46 ( & V_68 )
) != & V_108 ) {
V_27 = - V_109 ;
goto V_56;
}
F_47 ( V_3 [ V_26 -> V_2 ] , V_26 ) ;
V_56:
F_32 ( & V_68 ) ;
return V_27 ;
}
void F_48 ( const struct V_1 * V_26 )
{
F_30 ( & V_68 ) ;
F_47 ( V_3 [ V_26 -> V_2 ] ,
& V_108 ) ;
F_32 ( & V_68 ) ;
F_49 () ;
}
static void F_50 ( struct V_21 * V_36 )
{
struct V_42 * V_43 = F_51 ( V_36 , V_60 ) ;
if ( V_43 == NULL || V_43 -> V_36 == NULL )
return;
F_25 ( V_43 -> V_36 -> V_64 & V_72 ) ;
F_30 ( & V_68 ) ;
F_52 ( & V_43 -> V_69 ) ;
F_32 ( & V_68 ) ;
}
static void F_53 ( void * V_110 , void * V_111 )
{
struct V_42 * V_112 = V_110 ;
struct V_42 * V_113 = V_111 ;
struct V_21 * V_36 = V_113 -> V_36 ;
if ( ! V_36 || ! ( V_36 -> V_64 & V_72 ) )
return;
F_30 ( & V_68 ) ;
F_54 ( & V_113 -> V_69 , & V_112 -> V_69 ) ;
F_32 ( & V_68 ) ;
}
static int F_55 ( struct V_114 * V_115 ,
const struct V_21 * V_36 ,
struct V_24 * V_25 )
{
struct V_114 * V_116 [ V_117 + 1 ] ;
const struct V_1 * V_118 ;
int V_119 ;
V_119 = F_56 ( V_116 , V_117 , V_115 , V_120 ) ;
if ( V_119 < 0 )
return V_119 ;
F_10 () ;
V_118 = F_1 ( F_57 ( V_36 ) ) ;
if ( V_118 -> V_121 )
V_119 = V_118 -> V_121 ( V_116 , V_25 ) ;
F_11 () ;
return V_119 ;
}
static int
F_58 ( const struct V_114 * V_43 ,
const struct V_21 * V_36 , struct V_24 * V_25 )
{
struct V_114 * V_116 [ V_122 + 1 ] ;
int V_119 ;
memset ( V_25 , 0 , sizeof( * V_25 ) ) ;
V_119 = F_56 ( V_116 , V_122 , V_43 , V_123 ) ;
if ( V_119 < 0 )
return V_119 ;
if ( V_116 [ V_124 ] )
V_25 -> V_30 = F_59 ( V_116 [ V_124 ] ) ;
if ( ! V_116 [ V_125 ] )
V_25 -> V_31 = V_25 -> V_30 ;
else
V_25 -> V_31 = F_59 ( V_116 [ V_125 ] ) ;
if ( V_25 -> V_30 )
V_25 -> V_28 |= V_29 ;
if ( ! V_116 [ V_126 ] )
return 0 ;
V_119 = F_55 ( V_116 [ V_126 ] , V_36 , V_25 ) ;
if ( V_119 < 0 )
return V_119 ;
return 0 ;
}
static int
F_60 ( struct V_21 * V_36 ,
enum V_47 V_97 ,
const struct V_114 * V_115 )
{
struct V_24 V_25 ;
if ( F_58 ( V_115 , V_36 , & V_25 ) < 0 )
return - V_127 ;
if ( F_27 ( V_36 , V_97 ) )
return - V_128 ;
return F_22 ( V_36 , & V_25 , V_97 ) ;
}
static int
F_60 ( struct V_21 * V_36 ,
enum V_47 V_97 ,
const struct V_114 * V_115 )
{
return - V_129 ;
}
static int T_6 F_61 ( struct V_4 * V_4 )
{
V_4 -> V_19 . V_20 = V_4 -> V_36 . V_130 ;
V_4 -> V_19 . V_70 = F_62 ( & V_4 -> V_19 . V_20 , 0 ) ;
if ( ! V_4 -> V_19 . V_70 )
return - V_131 ;
return 0 ;
}
static int F_63 ( struct V_21 * V_132 , void * V_80 )
{
struct V_42 * V_43 = F_23 ( V_132 ) ;
if ( ! V_43 )
return 0 ;
memset ( V_43 , 0 , sizeof( * V_43 ) ) ;
V_132 -> V_64 &= ~ ( V_91 | V_102 | V_133 ) ;
return 0 ;
}
static void T_7 F_64 ( struct V_4 * V_4 )
{
F_65 ( V_4 , & F_63 , NULL ) ;
F_49 () ;
F_66 ( V_4 -> V_19 . V_70 , V_4 -> V_19 . V_20 ) ;
}
static int T_8 F_67 ( void )
{
T_9 V_132 ;
int V_27 ;
F_68 () ;
V_27 = F_69 ( & V_134 ) ;
if ( V_27 < 0 ) {
F_70 ( V_135 L_7 ) ;
return V_27 ;
}
V_27 = F_71 ( & V_136 ) ;
if ( V_27 < 0 )
goto V_137;
F_30 ( & V_68 ) ;
for ( V_132 = 0 ; V_132 < V_138 ; V_132 ++ )
F_47 ( V_3 [ V_132 ] , & V_108 ) ;
F_47 ( V_3 [ V_139 ] , & V_140 ) ;
F_47 ( V_3 [ V_141 ] , & V_142 ) ;
F_47 ( V_3 [ V_143 ] , & V_144 ) ;
F_32 ( & V_68 ) ;
F_72 ( V_102 ) ;
V_145 = F_73 ( ( T_5 ) V_146 ) ;
F_74 ( & V_147 ) ;
F_26 ( V_148 != NULL ) ;
F_47 ( V_148 , V_149 ) ;
F_26 ( V_150 != NULL ) ;
F_47 ( V_150 ,
F_60 ) ;
F_26 ( V_151 != NULL ) ;
F_47 ( V_151 , V_152 ) ;
F_47 ( V_153 , & V_154 ) ;
return 0 ;
V_137:
F_75 ( & V_134 ) ;
return V_27 ;
}
static void T_10 F_76 ( void )
{
F_77 ( & V_136 ) ;
F_78 ( V_145 ) ;
F_75 ( & V_134 ) ;
F_79 ( & V_147 ) ;
F_47 ( V_148 , NULL ) ;
F_47 ( V_150 , NULL ) ;
F_47 ( V_151 , NULL ) ;
F_47 ( V_153 , NULL ) ;
F_80 () ;
}
