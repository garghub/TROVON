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
V_7 -> V_16 . V_2 , 0 ) ;
return ( ( V_17 ) V_8 * V_4 -> V_18 . V_19 ) >> 32 ;
}
int
F_5 ( const struct V_6 * V_7 ,
const struct V_20 * V_21 )
{
struct V_6 V_22 ;
F_6 ( & V_22 , V_7 ) ;
return F_7 ( & V_22 , V_21 ) ;
}
static int
F_8 ( const struct V_6 * V_7 ,
const struct V_23 * V_24 )
{
const struct V_1 * V_25 ;
int V_26 = 0 ;
if ( V_24 -> V_27 & V_28 ) {
if ( F_9 ( V_7 -> V_11 . V_12 . V_13 ) < F_9 ( V_24 -> V_29 ) ||
F_9 ( V_7 -> V_11 . V_12 . V_13 ) > F_9 ( V_24 -> V_30 ) )
return 0 ;
}
F_10 () ;
V_25 = F_1 ( V_7 -> V_16 . V_2 ) ;
if ( ! ( V_24 -> V_27 & V_31 ) ||
V_25 -> F_8 ( V_7 , V_32 ,
& V_24 -> V_33 , & V_24 -> V_34 ) )
V_26 = 1 ;
F_11 () ;
return V_26 ;
}
static inline int
F_12 ( const struct V_20 * V_35 ,
const struct V_6 * V_7 )
{
const struct V_6 * V_36 ;
V_36 = & V_35 -> V_37 [ V_38 ] . V_7 ;
return ( V_36 -> V_16 . V_2 == V_7 -> V_16 . V_2 &&
V_36 -> V_11 . V_12 . V_13 == V_7 -> V_11 . V_12 . V_13 &&
V_36 -> V_11 . V_14 . V_15 == V_7 -> V_11 . V_14 . V_15 ) ;
}
static int
F_13 ( struct V_4 * V_4 , T_2 V_5 ,
const struct V_6 * V_7 ,
struct V_6 * V_39 ,
const struct V_23 * V_24 )
{
unsigned int V_40 = F_3 ( V_4 , V_5 , V_7 ) ;
const struct V_41 * V_42 ;
const struct V_20 * V_35 ;
const struct V_43 * V_44 ;
F_10 () ;
F_14 (nat, n, &net->ipv4.nat_bysource[h], bysource) {
V_35 = V_42 -> V_35 ;
if ( F_12 ( V_35 , V_7 ) && F_15 ( V_35 ) == V_5 ) {
F_6 ( V_39 ,
& V_35 -> V_37 [ V_45 ] . V_7 ) ;
V_39 -> V_16 = V_7 -> V_16 ;
if ( F_8 ( V_39 , V_24 ) ) {
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
const struct V_23 * V_24 ,
const struct V_20 * V_35 ,
enum V_46 V_47 )
{
T_3 * V_48 ;
T_4 V_49 , V_50 , V_51 ;
if ( ! ( V_24 -> V_27 & V_28 ) )
return;
if ( V_47 == V_32 )
V_48 = & V_7 -> V_11 . V_12 . V_13 ;
else
V_48 = & V_7 -> V_16 . V_12 . V_13 ;
if ( V_24 -> V_29 == V_24 -> V_30 ) {
* V_48 = V_24 -> V_29 ;
return;
}
V_49 = F_9 ( V_24 -> V_29 ) ;
V_50 = F_9 ( V_24 -> V_30 ) ;
V_51 = F_17 ( ( V_9 V_10 ) V_7 -> V_11 . V_12 . V_13 ,
V_24 -> V_27 & V_52 ?
0 : ( V_9 V_10 ) V_7 -> V_16 . V_12 . V_13 ^ V_5 , 0 ) ;
V_51 = ( ( V_17 ) V_51 * ( V_50 - V_49 + 1 ) ) >> 32 ;
* V_48 = F_18 ( V_49 + V_51 ) ;
}
static void
F_19 ( struct V_6 * V_7 ,
const struct V_6 * V_53 ,
const struct V_23 * V_24 ,
struct V_20 * V_35 ,
enum V_46 V_47 )
{
struct V_4 * V_4 = F_20 ( V_35 ) ;
const struct V_1 * V_25 ;
T_2 V_5 = F_15 ( V_35 ) ;
if ( V_47 == V_32 &&
! ( V_24 -> V_27 & V_54 ) ) {
if ( F_8 ( V_53 , V_24 ) ) {
if ( ! F_5 ( V_53 , V_35 ) ) {
* V_7 = * V_53 ;
return;
}
} else if ( F_13 ( V_4 , V_5 , V_53 , V_7 ,
V_24 ) ) {
F_21 ( L_1 ) ;
if ( ! F_5 ( V_7 , V_35 ) )
return;
}
}
* V_7 = * V_53 ;
F_16 ( V_5 , V_7 , V_24 , V_35 , V_47 ) ;
F_10 () ;
V_25 = F_1 ( V_53 -> V_16 . V_2 ) ;
if ( ! ( V_24 -> V_27 & V_54 ) ) {
if ( V_24 -> V_27 & V_31 ) {
if ( V_25 -> F_8 ( V_7 , V_47 , & V_24 -> V_33 ,
& V_24 -> V_34 ) &&
( V_24 -> V_33 . V_15 == V_24 -> V_34 . V_15 ||
! F_5 ( V_7 , V_35 ) ) )
goto V_55;
} else if ( ! F_5 ( V_7 , V_35 ) ) {
goto V_55;
}
}
V_25 -> V_56 ( V_7 , V_24 , V_47 , V_35 ) ;
V_55:
F_11 () ;
}
unsigned int
F_22 ( struct V_20 * V_35 ,
const struct V_23 * V_24 ,
enum V_46 V_47 )
{
struct V_4 * V_4 = F_20 ( V_35 ) ;
struct V_6 V_57 , V_58 ;
struct V_41 * V_42 ;
V_42 = F_23 ( V_35 ) ;
if ( ! V_42 ) {
V_42 = F_24 ( V_35 , V_59 , V_60 ) ;
if ( V_42 == NULL ) {
F_21 ( L_2 ) ;
return V_61 ;
}
}
F_25 ( V_47 == V_32 ||
V_47 == V_62 ) ;
F_26 ( F_27 ( V_35 , V_47 ) ) ;
F_6 ( & V_57 ,
& V_35 -> V_37 [ V_45 ] . V_7 ) ;
F_19 ( & V_58 , & V_57 , V_24 , V_35 , V_47 ) ;
if ( ! F_28 ( & V_58 , & V_57 ) ) {
struct V_6 V_22 ;
F_6 ( & V_22 , & V_58 ) ;
F_29 ( V_35 , & V_22 ) ;
if ( V_47 == V_32 )
V_35 -> V_63 |= V_64 ;
else
V_35 -> V_63 |= V_65 ;
}
if ( V_47 == V_32 ) {
unsigned int V_66 ;
V_66 = F_3 ( V_4 , F_15 ( V_35 ) ,
& V_35 -> V_37 [ V_38 ] . V_7 ) ;
F_30 ( & V_67 ) ;
V_42 = F_23 ( V_35 ) ;
V_42 -> V_35 = V_35 ;
F_31 ( & V_42 -> V_68 ,
& V_4 -> V_18 . V_69 [ V_66 ] ) ;
F_32 ( & V_67 ) ;
}
if ( V_47 == V_62 )
V_35 -> V_63 |= V_70 ;
else
V_35 -> V_63 |= V_71 ;
return V_61 ;
}
static bool
F_33 ( T_5 V_25 ,
struct V_72 * V_73 ,
unsigned int V_74 ,
const struct V_6 * V_75 ,
enum V_46 V_47 )
{
struct V_76 * V_77 ;
const struct V_1 * V_78 ;
if ( ! F_34 ( V_73 , V_74 + sizeof( * V_77 ) ) )
return false ;
V_77 = ( void * ) V_73 -> V_79 + V_74 ;
V_78 = F_1 ( V_25 ) ;
if ( ! V_78 -> F_33 ( V_73 , V_74 , V_75 , V_47 ) )
return false ;
V_77 = ( void * ) V_73 -> V_79 + V_74 ;
if ( V_47 == V_32 ) {
F_35 ( & V_77 -> V_80 , V_77 -> V_81 , V_75 -> V_11 . V_12 . V_13 ) ;
V_77 -> V_81 = V_75 -> V_11 . V_12 . V_13 ;
} else {
F_35 ( & V_77 -> V_80 , V_77 -> V_82 , V_75 -> V_16 . V_12 . V_13 ) ;
V_77 -> V_82 = V_75 -> V_16 . V_12 . V_13 ;
}
return true ;
}
unsigned int F_36 ( struct V_20 * V_35 ,
enum V_83 V_84 ,
unsigned int V_85 ,
struct V_72 * V_73 )
{
enum V_86 V_87 = F_37 ( V_84 ) ;
unsigned long V_88 ;
enum V_46 V_89 = F_38 ( V_85 ) ;
if ( V_89 == V_32 )
V_88 = V_64 ;
else
V_88 = V_65 ;
if ( V_87 == V_45 )
V_88 ^= V_90 ;
if ( V_35 -> V_63 & V_88 ) {
struct V_6 V_75 ;
F_6 ( & V_75 , & V_35 -> V_37 [ ! V_87 ] . V_7 ) ;
if ( ! F_33 ( V_75 . V_16 . V_2 , V_73 , 0 , & V_75 , V_89 ) )
return V_91 ;
}
return V_61 ;
}
int F_39 ( struct V_20 * V_35 ,
enum V_83 V_84 ,
unsigned int V_85 ,
struct V_72 * V_73 )
{
struct {
struct V_92 V_93 ;
struct V_76 V_13 ;
} * V_94 ;
const struct V_95 * V_96 ;
struct V_6 V_97 , V_75 ;
int V_98 = F_40 ( V_73 ) ;
enum V_86 V_87 = F_37 ( V_84 ) ;
unsigned long V_88 ;
enum V_46 V_99 = F_38 ( V_85 ) ;
if ( ! F_34 ( V_73 , V_98 + sizeof( * V_94 ) ) )
return 0 ;
V_94 = ( void * ) V_73 -> V_79 + V_98 ;
if ( F_41 ( V_73 , V_85 , V_98 , 0 ) )
return 0 ;
F_25 ( V_73 -> V_100 == V_101 ||
V_73 -> V_100 == V_102 ) ;
if ( V_94 -> V_93 . type == V_103 ) {
if ( ( V_35 -> V_63 & V_104 ) != V_104 )
return 0 ;
if ( V_35 -> V_63 & V_90 )
return 0 ;
}
if ( V_99 == V_32 )
V_88 = V_64 ;
else
V_88 = V_65 ;
if ( V_87 == V_45 )
V_88 ^= V_90 ;
if ( ! ( V_35 -> V_63 & V_88 ) )
return 1 ;
F_21 ( L_3
L_4 , V_73 , V_99 ,
V_87 == V_38 ? L_5 : L_6 ) ;
V_96 = F_42 ( V_105 , V_94 -> V_13 . V_106 ) ;
if ( ! F_43 ( V_73 , V_98 + sizeof( struct V_92 ) ,
( V_98 +
sizeof( struct V_92 ) + V_94 -> V_13 . V_107 * 4 ) ,
( T_5 ) V_108 , V_94 -> V_13 . V_106 ,
& V_97 , V_109 , V_96 ) )
return 0 ;
if ( ! F_33 ( V_94 -> V_13 . V_106 , V_73 , V_98 + sizeof( V_94 -> V_93 ) ,
& V_35 -> V_37 [ ! V_87 ] . V_7 , ! V_99 ) )
return 0 ;
if ( V_73 -> V_110 != V_111 ) {
V_94 = ( void * ) V_73 -> V_79 + V_98 ;
V_94 -> V_93 . V_112 = 0 ;
V_94 -> V_93 . V_112 =
F_44 ( F_45 ( V_73 , V_98 ,
V_73 -> V_113 - V_98 , 0 ) ) ;
}
F_6 ( & V_75 , & V_35 -> V_37 [ ! V_87 ] . V_7 ) ;
if ( ! F_33 ( 0 , V_73 , 0 , & V_75 , V_99 ) )
return 0 ;
return 1 ;
}
int F_46 ( const struct V_1 * V_25 )
{
int V_26 = 0 ;
F_30 ( & V_67 ) ;
if ( F_47 (
V_3 [ V_25 -> V_2 ] ,
F_48 ( & V_67 )
) != & V_114 ) {
V_26 = - V_115 ;
goto V_55;
}
F_49 ( V_3 [ V_25 -> V_2 ] , V_25 ) ;
V_55:
F_32 ( & V_67 ) ;
return V_26 ;
}
void F_50 ( const struct V_1 * V_25 )
{
F_30 ( & V_67 ) ;
F_49 ( V_3 [ V_25 -> V_2 ] ,
& V_114 ) ;
F_32 ( & V_67 ) ;
F_51 () ;
}
static void F_52 ( struct V_20 * V_35 )
{
struct V_41 * V_42 = F_53 ( V_35 , V_59 ) ;
if ( V_42 == NULL || V_42 -> V_35 == NULL )
return;
F_25 ( V_42 -> V_35 -> V_63 & V_71 ) ;
F_30 ( & V_67 ) ;
F_54 ( & V_42 -> V_68 ) ;
F_32 ( & V_67 ) ;
}
static void F_55 ( void * V_116 , void * V_117 )
{
struct V_41 * V_118 = V_116 ;
struct V_41 * V_119 = V_117 ;
struct V_20 * V_35 = V_119 -> V_35 ;
if ( ! V_35 || ! ( V_35 -> V_63 & V_71 ) )
return;
F_30 ( & V_67 ) ;
F_56 ( & V_119 -> V_68 , & V_118 -> V_68 ) ;
F_32 ( & V_67 ) ;
}
static const struct V_1 *
F_57 ( T_1 V_2 )
{
const struct V_1 * V_78 ;
F_10 () ;
V_78 = F_1 ( V_2 ) ;
if ( ! F_58 ( V_78 -> V_120 ) )
V_78 = & V_114 ;
F_11 () ;
return V_78 ;
}
static void
F_59 ( const struct V_1 * V_78 )
{
F_60 ( V_78 -> V_120 ) ;
}
static int F_61 ( struct V_121 * V_122 ,
const struct V_20 * V_35 ,
struct V_23 * V_24 )
{
struct V_121 * V_123 [ V_124 + 1 ] ;
const struct V_1 * V_125 ;
int V_126 ;
V_126 = F_62 ( V_123 , V_124 , V_122 , V_127 ) ;
if ( V_126 < 0 )
return V_126 ;
V_125 = F_57 ( F_63 ( V_35 ) ) ;
if ( V_125 -> V_128 )
V_126 = V_125 -> V_128 ( V_123 , V_24 ) ;
F_59 ( V_125 ) ;
return V_126 ;
}
static int
F_64 ( const struct V_121 * V_42 ,
const struct V_20 * V_35 , struct V_23 * V_24 )
{
struct V_121 * V_123 [ V_129 + 1 ] ;
int V_126 ;
memset ( V_24 , 0 , sizeof( * V_24 ) ) ;
V_126 = F_62 ( V_123 , V_129 , V_42 , V_130 ) ;
if ( V_126 < 0 )
return V_126 ;
if ( V_123 [ V_131 ] )
V_24 -> V_29 = F_65 ( V_123 [ V_131 ] ) ;
if ( ! V_123 [ V_132 ] )
V_24 -> V_30 = V_24 -> V_29 ;
else
V_24 -> V_30 = F_65 ( V_123 [ V_132 ] ) ;
if ( V_24 -> V_29 )
V_24 -> V_27 |= V_28 ;
if ( ! V_123 [ V_133 ] )
return 0 ;
V_126 = F_61 ( V_123 [ V_133 ] , V_35 , V_24 ) ;
if ( V_126 < 0 )
return V_126 ;
return 0 ;
}
static int
F_66 ( struct V_20 * V_35 ,
enum V_46 V_99 ,
const struct V_121 * V_122 )
{
struct V_23 V_24 ;
if ( F_64 ( V_122 , V_35 , & V_24 ) < 0 )
return - V_134 ;
if ( F_27 ( V_35 , V_99 ) )
return - V_135 ;
return F_22 ( V_35 , & V_24 , V_99 ) ;
}
static int
F_66 ( struct V_20 * V_35 ,
enum V_46 V_99 ,
const struct V_121 * V_122 )
{
return - V_136 ;
}
static int T_6 F_67 ( struct V_4 * V_4 )
{
V_4 -> V_18 . V_19 = V_4 -> V_35 . V_137 ;
V_4 -> V_18 . V_69 = F_68 ( & V_4 -> V_18 . V_19 , 0 ) ;
if ( ! V_4 -> V_18 . V_69 )
return - V_138 ;
return 0 ;
}
static int F_69 ( struct V_20 * V_139 , void * V_79 )
{
struct V_41 * V_42 = F_23 ( V_139 ) ;
if ( ! V_42 )
return 0 ;
memset ( V_42 , 0 , sizeof( * V_42 ) ) ;
V_139 -> V_63 &= ~ ( V_90 | V_104 | V_140 ) ;
return 0 ;
}
static void T_7 F_70 ( struct V_4 * V_4 )
{
F_71 ( V_4 , & F_69 , NULL ) ;
F_51 () ;
F_72 ( V_4 -> V_18 . V_69 , V_4 -> V_18 . V_19 ) ;
}
static int T_8 F_73 ( void )
{
T_9 V_139 ;
int V_26 ;
F_74 () ;
V_26 = F_75 ( & V_141 ) ;
if ( V_26 < 0 ) {
F_76 ( V_142 L_7 ) ;
return V_26 ;
}
V_26 = F_77 ( & V_143 ) ;
if ( V_26 < 0 )
goto V_144;
F_30 ( & V_67 ) ;
for ( V_139 = 0 ; V_139 < V_145 ; V_139 ++ )
F_49 ( V_3 [ V_139 ] , & V_114 ) ;
F_49 ( V_3 [ V_146 ] , & V_147 ) ;
F_49 ( V_3 [ V_148 ] , & V_149 ) ;
F_49 ( V_3 [ V_150 ] , & V_151 ) ;
F_32 ( & V_67 ) ;
F_78 ( V_104 ) ;
V_109 = F_79 ( ( T_5 ) V_108 ) ;
F_26 ( V_152 != NULL ) ;
F_49 ( V_152 , V_153 ) ;
F_26 ( V_154 != NULL ) ;
F_49 ( V_154 ,
F_66 ) ;
F_26 ( V_155 != NULL ) ;
F_49 ( V_155 , V_156 ) ;
return 0 ;
V_144:
F_80 ( & V_141 ) ;
return V_26 ;
}
static void T_10 F_81 ( void )
{
F_82 ( & V_143 ) ;
F_83 ( V_109 ) ;
F_80 ( & V_141 ) ;
F_49 ( V_152 , NULL ) ;
F_49 ( V_154 , NULL ) ;
F_49 ( V_155 , NULL ) ;
F_84 () ;
}
