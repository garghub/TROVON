static struct V_1 * F_1 ( struct V_2 * V_3 )
{
struct V_4 * V_5 = V_3 -> V_6 -> V_7 ;
return F_2 ( F_3 ( V_5 -> V_8 ) ) ;
}
static bool F_4 ( struct V_9 * V_10 )
{
return V_10 -> V_11 && V_10 -> V_12 ;
}
static int F_5 ( struct V_2 * V_3 )
{
struct V_13 * V_13 = F_6 ( V_3 ) ;
struct V_1 * V_1 = F_1 ( V_3 ) ;
enum V_14 V_15 = V_13 -> V_15 ;
F_7 ( L_1 , V_13 -> V_16 ) ;
if ( V_1 ) {
F_8 ( V_1 -> V_17 , V_15 ) ;
}
return 0 ;
}
static void F_9 ( struct V_2 * V_3 )
{
struct V_13 * V_13 = F_6 ( V_3 ) ;
F_10 ( V_3 ) ;
F_11 ( V_3 ) ;
F_12 ( V_13 ) ;
}
void F_13 ( struct V_2 * V_3 ,
struct V_18 * V_19 )
{
}
int F_14 ( struct V_2 * V_3 ,
struct V_20 * V_21 , T_1 V_22 )
{
return - V_23 ;
}
static void F_15 ( struct V_2 * V_3 )
{
struct V_24 * V_25 ;
if ( V_3 -> V_10 && V_3 -> V_10 -> V_11 )
F_16 ( V_3 -> V_10 -> V_11 ) ;
F_12 ( F_17 ( V_3 -> V_10 ) ) ;
V_25 = F_18 ( sizeof( * V_25 ) , V_26 ) ;
if ( V_3 -> type == V_27 ) {
V_25 -> V_28 = 0 ;
} else {
V_25 -> V_28 = 1 + F_19 ( V_3 ) ;
}
V_25 -> V_29 . V_3 = V_3 ;
V_3 -> V_10 = & V_25 -> V_29 ;
}
static struct V_9 *
F_20 ( struct V_2 * V_3 )
{
struct V_24 * V_25 ;
if ( F_21 ( ! V_3 -> V_10 ) )
return NULL ;
V_25 = F_22 ( F_17 ( V_3 -> V_10 ) ,
sizeof( * V_25 ) , V_26 ) ;
if ( V_25 && V_25 -> V_29 . V_11 )
F_23 ( V_25 -> V_29 . V_11 ) ;
V_25 -> V_30 = false ;
V_25 -> V_31 = false ;
return & V_25 -> V_29 ;
}
static void F_24 ( struct V_2 * V_3 ,
struct V_9 * V_10 )
{
if ( V_10 -> V_11 )
F_16 ( V_10 -> V_11 ) ;
F_12 ( F_17 ( V_10 ) ) ;
}
static int F_25 ( struct V_2 * V_3 ,
struct V_32 * V_11 ,
const struct V_9 * V_33 )
{
struct V_13 * V_13 = F_6 ( V_3 ) ;
struct V_1 * V_1 = F_1 ( V_3 ) ;
F_7 ( L_2 , V_13 -> V_16 , V_11 -> V_29 . V_34 ) ;
return F_26 ( V_11 , V_1 -> V_34 ) ;
}
static void F_27 ( struct V_2 * V_3 ,
struct V_32 * V_11 ,
const struct V_9 * V_35 )
{
struct V_13 * V_13 = F_6 ( V_3 ) ;
struct V_1 * V_1 = F_1 ( V_3 ) ;
F_7 ( L_3 , V_13 -> V_16 , V_11 -> V_29 . V_34 ) ;
F_28 ( V_11 , V_1 -> V_34 ) ;
}
static int F_29 ( struct V_2 * V_3 ,
struct V_9 * V_10 )
{
struct V_13 * V_13 = F_6 ( V_3 ) ;
struct V_9 * V_35 = V_3 -> V_10 ;
F_7 ( L_4 , V_13 -> V_16 ,
F_4 ( V_35 ) , F_4 ( V_10 ) ) ;
if ( F_4 ( V_10 ) && F_4 ( V_35 ) ) {
bool V_36 = false ;
if ( V_10 -> V_11 -> V_37 != V_35 -> V_11 -> V_37 ) {
F_7 ( L_5 , V_13 -> V_16 ) ;
V_36 = true ;
}
if ( V_10 -> V_38 != V_35 -> V_38 ) {
F_7 ( L_6 , V_13 -> V_16 ) ;
V_36 = true ;
}
if ( F_17 ( V_35 ) -> V_31 ) {
F_7 ( L_7 , V_13 -> V_16 ) ;
V_36 = true ;
}
if ( V_36 ) {
struct V_39 * V_40 =
F_30 ( V_10 -> V_10 , V_10 -> V_12 ) ;
V_40 -> V_30 = true ;
F_17 ( V_10 ) -> V_30 = true ;
}
} else {
F_17 ( V_10 ) -> V_30 = true ;
}
return 0 ;
}
static void F_31 ( struct V_2 * V_3 ,
struct V_9 * V_35 )
{
struct V_13 * V_13 = F_6 ( V_3 ) ;
struct V_9 * V_10 = V_3 -> V_10 ;
F_7 ( L_8 , V_13 -> V_16 ) ;
if ( ! F_4 ( V_10 ) ) {
F_17 ( V_10 ) -> V_31 = true ;
F_5 ( V_3 ) ;
} else if ( F_17 ( V_10 ) -> V_30 ) {
int V_41 ;
F_17 ( V_10 ) -> V_31 = true ;
V_41 = F_32 ( V_3 ,
V_10 -> V_12 , V_10 -> V_11 ,
V_10 -> V_42 , V_10 -> V_43 ,
V_10 -> V_44 , V_10 -> V_45 ,
V_10 -> V_46 , V_10 -> V_47 ,
V_10 -> V_38 , V_10 -> V_48 ) ;
F_21 ( V_41 < 0 ) ;
} else {
unsigned long V_49 ;
F_33 ( & V_13 -> V_50 , V_49 ) ;
F_34 ( V_3 , V_10 -> V_11 ) ;
F_35 ( & V_13 -> V_50 , V_49 ) ;
}
}
static void F_34 ( struct V_2 * V_3 ,
struct V_32 * V_11 )
{
struct V_13 * V_13 = F_6 ( V_3 ) ;
struct V_1 * V_1 = F_1 ( V_3 ) ;
enum V_14 V_15 = V_13 -> V_15 ;
F_36 ( V_1 , F_37 ( V_15 ) ,
F_38 ( V_11 -> V_51 [ 0 ] ) |
F_39 ( V_11 -> V_51 [ 1 ] ) ) ;
F_36 ( V_1 , F_40 ( V_15 ) ,
F_41 ( V_11 -> V_51 [ 2 ] ) |
F_42 ( V_11 -> V_51 [ 3 ] ) ) ;
F_36 ( V_1 , F_43 ( V_15 ) ,
F_44 ( V_11 , V_1 -> V_34 , 0 ) ) ;
F_36 ( V_1 , F_45 ( V_15 ) ,
F_44 ( V_11 , V_1 -> V_34 , 1 ) ) ;
F_36 ( V_1 , F_46 ( V_15 ) ,
F_44 ( V_11 , V_1 -> V_34 , 2 ) ) ;
F_36 ( V_1 , F_47 ( V_15 ) ,
F_44 ( V_11 , V_1 -> V_34 , 3 ) ) ;
V_3 -> V_11 = V_11 ;
}
static void F_48 ( struct V_1 * V_1 , enum V_14 V_15 )
{
T_2 V_52 = F_49 ( V_1 , F_50 ( V_15 ) ) &
~ V_53 ;
F_36 ( V_1 , F_50 ( V_15 ) , V_52 ) ;
}
static void F_51 ( struct V_1 * V_1 , enum V_14 V_15 ,
struct V_54 * V_55 )
{
T_2 V_56 , V_57 = 0 ;
T_2 * V_58 ;
if ( F_52 ( ! V_55 ) )
return;
if ( ( V_55 -> type == V_59 ) || ( V_60 == V_55 -> type ) )
V_57 |= F_53 ( V_61 ) ;
if ( ( V_55 -> type == V_62 ) || ( V_60 == V_55 -> type ) )
V_57 |= F_54 ( V_61 ) ;
V_57 |= V_53 ;
F_36 ( V_1 , F_50 ( V_15 ) , V_57 ) ;
V_58 = V_55 -> V_58 ;
F_36 ( V_1 , F_55 ( V_15 ) ,
F_56 ( V_58 [ 0 ] ) |
F_57 ( V_58 [ 1 ] ) ) ;
F_36 ( V_1 , F_58 ( V_15 ) ,
F_59 ( V_58 [ 2 ] ) |
F_60 ( V_58 [ 3 ] ) ) ;
F_36 ( V_1 , F_61 ( V_15 ) ,
F_62 ( V_58 [ 4 ] ) |
F_63 ( V_58 [ 5 ] ) ) ;
F_36 ( V_1 , F_64 ( V_15 ) ,
F_65 ( V_58 [ 6 ] ) |
F_66 ( V_58 [ 7 ] ) ) ;
F_36 ( V_1 , F_67 ( V_15 ) ,
F_68 ( V_58 [ 8 ] ) ) ;
for ( V_56 = 0 ; V_56 < F_69 ( V_55 -> V_63 ) ; V_56 ++ ) {
T_2 * V_64 = V_55 -> V_64 ;
T_2 * V_65 = V_55 -> V_65 ;
F_36 ( V_1 , F_70 ( V_15 , V_56 ) ,
F_71 ( V_64 [ 2 * V_56 + 1 ] ) |
F_72 ( V_64 [ 2 * V_56 ] ) ) ;
F_36 ( V_1 , F_73 ( V_15 , V_56 ) ,
F_74 ( V_65 [ 2 * V_56 + 1 ] ) |
F_75 ( V_65 [ 2 * V_56 ] ) ) ;
F_36 ( V_1 , F_76 ( V_15 , V_56 ) ,
F_77 ( V_55 -> V_63 [ V_56 ] ) ) ;
F_36 ( V_1 , F_78 ( V_15 , V_56 ) ,
F_79 ( V_55 -> V_66 [ V_56 ] ) ) ;
}
}
static int F_80 ( T_2 V_67 , T_2 V_68 , T_2 * V_69 )
{
T_2 V_70 ;
if ( V_67 == 0 || V_68 == 0 )
return - V_23 ;
if ( V_67 > ( V_68 * V_71 ) )
return - V_72 ;
V_70 = 1 << V_73 ;
* V_69 = F_81 ( V_70 , V_67 , V_68 ) ;
return 0 ;
}
static int F_82 ( T_2 V_37 , T_2 V_67 , T_2 V_74 ,
T_2 V_75 [ 2 ] )
{
T_2 V_76 ;
unsigned int V_77 ;
int V_41 ;
V_41 = F_80 ( V_67 , V_74 , & V_76 ) ;
if ( V_41 )
return V_41 ;
V_77 = F_83 ( V_37 ) ;
V_75 [ 0 ] = V_76 ;
V_75 [ 1 ] = V_76 / V_77 ;
return 0 ;
}
static int F_84 ( T_2 V_37 , T_2 V_67 , T_2 V_74 ,
T_2 V_78 [ 2 ] )
{
T_2 V_79 ;
unsigned int V_80 ;
int V_41 ;
V_41 = F_80 ( V_67 , V_74 , & V_79 ) ;
if ( V_41 )
return V_41 ;
V_80 = F_85 ( V_37 ) ;
V_78 [ 0 ] = V_79 ;
V_78 [ 1 ] = V_79 / V_80 ;
return 0 ;
}
static T_2 F_86 ( T_2 V_67 , T_2 V_74 )
{
T_2 V_81 ;
V_81 = ( V_67 <= V_74 ) ? V_82 : V_83 ;
return V_84 |
F_87 ( V_81 ) |
F_88 ( V_81 ) |
F_89 ( V_81 ) ;
}
static T_2 F_90 ( T_2 V_67 , T_2 V_74 )
{
T_2 V_81 ;
V_81 = ( V_67 <= V_74 ) ? V_82 : V_83 ;
return V_85 |
F_91 ( V_81 ) |
F_92 ( V_81 ) |
F_93 ( V_81 ) ;
}
static int F_32 ( struct V_2 * V_3 ,
struct V_86 * V_12 , struct V_32 * V_11 ,
int V_42 , int V_43 ,
unsigned int V_44 , unsigned int V_45 ,
T_2 V_46 , T_2 V_47 ,
T_2 V_38 , T_2 V_48 )
{
struct V_13 * V_13 = F_6 ( V_3 ) ;
struct V_1 * V_1 = F_1 ( V_3 ) ;
struct V_87 * V_6 = V_1 -> V_6 -> V_6 ;
enum V_14 V_15 = V_13 -> V_15 ;
const struct V_88 * V_89 ;
T_2 V_90 , V_91 = 0 ;
T_2 V_76 [ 2 ] = { 0 ,} , V_79 [ 2 ] = { 0 ,} ;
T_2 V_92 = 0 , V_93 = 0 ;
T_2 V_94 ;
unsigned long V_49 ;
int V_41 ;
V_90 = F_94 ( V_11 -> V_37 ) ;
if ( F_21 ( V_90 > F_95 ( V_15 ) ) )
return - V_23 ;
V_89 = F_96 ( F_97 ( V_11 ) ) ;
V_94 = V_89 -> V_29 . V_37 ;
V_46 = V_46 >> 16 ;
V_47 = V_47 >> 16 ;
V_38 = V_38 >> 16 ;
V_48 = V_48 >> 16 ;
F_7 ( L_9 , V_13 -> V_16 ,
V_11 -> V_29 . V_34 , V_46 , V_47 , V_38 , V_48 ,
V_12 -> V_29 . V_34 , V_42 , V_43 , V_44 , V_45 ) ;
V_41 = F_98 ( V_1 -> V_17 ,
V_13 -> V_15 , V_11 -> V_37 , V_38 ) ;
if ( V_41 )
return V_41 ;
F_99 ( V_1 -> V_17 , V_15 ) ;
if ( ( V_38 != V_44 ) || F_100 ( V_89 ) ) {
V_41 = F_82 ( V_94 , V_38 , V_44 , V_76 ) ;
if ( V_41 ) {
F_101 ( V_6 , L_10 ,
V_38 , V_44 , V_41 ) ;
return V_41 ;
}
V_91 |= F_86 ( V_38 , V_44 ) ;
}
if ( ( V_48 != V_45 ) || F_100 ( V_89 ) ) {
V_41 = F_84 ( V_94 , V_48 , V_45 , V_79 ) ;
if ( V_41 ) {
F_101 ( V_6 , L_11 ,
V_48 , V_45 , V_41 ) ;
return V_41 ;
}
V_91 |= F_90 ( V_48 , V_45 ) ;
}
F_33 ( & V_13 -> V_50 , V_49 ) ;
F_36 ( V_1 , F_102 ( V_15 ) ,
F_103 ( V_11 -> V_95 ) |
F_104 ( V_11 -> V_96 ) ) ;
F_36 ( V_1 , F_105 ( V_15 ) ,
F_106 ( V_38 ) |
F_107 ( V_48 ) ) ;
F_36 ( V_1 , F_108 ( V_15 ) ,
F_109 ( V_46 ) |
F_110 ( V_47 ) ) ;
F_36 ( V_1 , F_111 ( V_15 ) ,
F_112 ( V_44 ) |
F_113 ( V_45 ) ) ;
F_36 ( V_1 , F_114 ( V_15 ) ,
F_115 ( V_42 ) |
F_116 ( V_43 ) ) ;
F_36 ( V_1 , F_117 ( V_15 ) ,
F_118 ( V_89 -> V_97 ) |
F_119 ( V_89 -> V_98 ) |
F_120 ( V_89 -> V_99 ) |
F_121 ( V_89 -> V_100 ) |
F_122 ( V_89 -> V_101 , V_102 ) |
F_123 ( V_89 -> V_103 - 1 ) |
F_124 ( V_89 -> V_104 - 1 ) |
F_122 ( V_89 -> V_105 , V_106 ) |
F_125 ( V_89 -> V_107 ) |
F_126 ( V_89 -> V_108 ) ) ;
F_36 ( V_1 , F_127 ( V_15 ) ,
F_128 ( V_89 -> V_109 [ 0 ] ) |
F_129 ( V_89 -> V_109 [ 1 ] ) |
F_130 ( V_89 -> V_109 [ 2 ] ) |
F_131 ( V_89 -> V_109 [ 3 ] ) ) ;
F_36 ( V_1 , F_132 ( V_15 ) ,
F_133 ( V_110 ) ) ;
F_36 ( V_1 , F_134 ( V_15 ) , 0 ) ;
F_36 ( V_1 , F_135 ( V_15 ) ,
V_76 [ 0 ] ) ;
F_36 ( V_1 , F_136 ( V_15 ) ,
V_79 [ 0 ] ) ;
F_36 ( V_1 , F_137 ( V_15 ) ,
V_76 [ 1 ] ) ;
F_36 ( V_1 , F_138 ( V_15 ) ,
V_79 [ 1 ] ) ;
F_36 ( V_1 , F_139 ( V_15 ) ,
F_140 ( V_93 ) |
F_141 ( V_92 ) ) ;
F_36 ( V_1 , F_142 ( V_15 ) , V_91 ) ;
if ( F_100 ( V_89 ) )
F_51 ( V_1 , V_15 ,
F_143 ( V_59 ) ) ;
else
F_48 ( V_1 , V_15 ) ;
F_34 ( V_3 , V_11 ) ;
F_35 ( & V_13 -> V_50 , V_49 ) ;
return V_41 ;
}
void F_144 ( struct V_2 * V_3 )
{
struct V_1 * V_1 = F_1 ( V_3 ) ;
struct V_13 * V_13 = F_6 ( V_3 ) ;
enum V_14 V_15 = V_13 -> V_15 ;
F_7 ( L_12 , V_13 -> V_16 ) ;
F_145 ( V_1 -> V_17 , V_15 ) ;
F_17 ( V_3 -> V_10 ) -> V_31 = false ;
}
enum V_14 F_146 ( struct V_2 * V_3 )
{
struct V_13 * V_13 = F_6 ( V_3 ) ;
return V_13 -> V_15 ;
}
T_2 F_147 ( struct V_2 * V_3 )
{
struct V_13 * V_13 = F_6 ( V_3 ) ;
return V_13 -> V_111 ;
}
struct V_2 * F_148 ( struct V_112 * V_6 ,
enum V_14 V_15 , bool V_113 , T_2 V_114 )
{
struct V_2 * V_3 = NULL ;
struct V_13 * V_13 ;
int V_41 ;
enum V_115 type ;
V_13 = F_18 ( sizeof( * V_13 ) , V_26 ) ;
if ( ! V_13 ) {
V_41 = - V_116 ;
goto V_117;
}
V_3 = & V_13 -> V_29 ;
V_13 -> V_15 = V_15 ;
V_13 -> V_16 = F_149 ( V_15 ) ;
V_13 -> V_118 = F_150 ( V_15 , V_13 -> V_119 ,
F_69 ( V_13 -> V_119 ) ) ;
V_13 -> V_111 = F_151 ( V_15 ) ;
V_13 -> V_114 = V_114 ;
F_152 ( & V_13 -> V_50 ) ;
type = V_113 ? V_27 : V_120 ;
V_41 = F_153 ( V_6 , V_3 , 0xff , & V_121 ,
V_13 -> V_119 , V_13 -> V_118 ,
type ) ;
if ( V_41 )
goto V_117;
F_154 ( V_3 , & V_122 ) ;
F_13 ( V_3 , & V_3 -> V_29 ) ;
return V_3 ;
V_117:
if ( V_3 )
F_9 ( V_3 ) ;
return F_155 ( V_41 ) ;
}
