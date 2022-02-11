static struct V_1 * F_1 ( struct V_2 * V_3 )
{
struct V_4 * V_5 = V_3 -> V_6 -> V_7 ;
return F_2 ( F_3 ( V_5 -> V_8 ) ) ;
}
static bool F_4 ( struct V_9 * V_10 )
{
return V_10 -> V_11 && V_10 -> V_12 ;
}
static void F_5 ( struct V_2 * V_3 )
{
struct V_13 * V_13 = F_6 ( V_3 ) ;
F_7 ( V_3 ) ;
F_8 ( V_3 ) ;
F_9 ( V_13 ) ;
}
void F_10 ( struct V_2 * V_3 ,
struct V_14 * V_15 )
{
}
int F_11 ( struct V_2 * V_3 ,
struct V_16 * V_17 , T_1 V_18 )
{
return - V_19 ;
}
static void F_12 ( struct V_2 * V_3 )
{
struct V_20 * V_21 ;
if ( V_3 -> V_10 && V_3 -> V_10 -> V_11 )
F_13 ( V_3 -> V_10 -> V_11 ) ;
F_9 ( F_14 ( V_3 -> V_10 ) ) ;
V_21 = F_15 ( sizeof( * V_21 ) , V_22 ) ;
if ( V_3 -> type == V_23 ) {
V_21 -> V_24 = 0 ;
} else {
V_21 -> V_24 = 1 + F_16 ( V_3 ) ;
}
V_21 -> V_25 . V_3 = V_3 ;
V_3 -> V_10 = & V_21 -> V_25 ;
}
static struct V_9 *
F_17 ( struct V_2 * V_3 )
{
struct V_20 * V_21 ;
if ( F_18 ( ! V_3 -> V_10 ) )
return NULL ;
V_21 = F_19 ( F_14 ( V_3 -> V_10 ) ,
sizeof( * V_21 ) , V_22 ) ;
if ( V_21 && V_21 -> V_25 . V_11 )
F_20 ( V_21 -> V_25 . V_11 ) ;
V_21 -> V_26 = false ;
V_21 -> V_27 = false ;
return & V_21 -> V_25 ;
}
static void F_21 ( struct V_2 * V_3 ,
struct V_9 * V_10 )
{
if ( V_10 -> V_11 )
F_13 ( V_10 -> V_11 ) ;
F_9 ( F_14 ( V_10 ) ) ;
}
static int F_22 ( struct V_2 * V_3 ,
struct V_28 * V_11 ,
const struct V_9 * V_29 )
{
struct V_13 * V_13 = F_6 ( V_3 ) ;
struct V_1 * V_1 = F_1 ( V_3 ) ;
F_23 ( L_1 , V_13 -> V_30 , V_11 -> V_25 . V_31 ) ;
return F_24 ( V_11 , V_1 -> V_31 ) ;
}
static void F_25 ( struct V_2 * V_3 ,
struct V_28 * V_11 ,
const struct V_9 * V_32 )
{
struct V_13 * V_13 = F_6 ( V_3 ) ;
struct V_1 * V_1 = F_1 ( V_3 ) ;
F_23 ( L_2 , V_13 -> V_30 , V_11 -> V_25 . V_31 ) ;
F_26 ( V_11 , V_1 -> V_31 ) ;
}
static int F_27 ( struct V_2 * V_3 ,
struct V_9 * V_10 )
{
struct V_13 * V_13 = F_6 ( V_3 ) ;
struct V_9 * V_32 = V_3 -> V_10 ;
F_23 ( L_3 , V_13 -> V_30 ,
F_4 ( V_32 ) , F_4 ( V_10 ) ) ;
if ( F_4 ( V_10 ) && F_4 ( V_32 ) ) {
bool V_33 = false ;
if ( V_10 -> V_11 -> V_34 != V_32 -> V_11 -> V_34 ) {
F_23 ( L_4 , V_13 -> V_30 ) ;
V_33 = true ;
}
if ( V_10 -> V_35 != V_32 -> V_35 ) {
F_23 ( L_5 , V_13 -> V_30 ) ;
V_33 = true ;
}
if ( F_14 ( V_32 ) -> V_27 ) {
F_23 ( L_6 , V_13 -> V_30 ) ;
V_33 = true ;
}
if ( V_33 ) {
struct V_36 * V_37 =
F_28 ( V_10 -> V_10 , V_10 -> V_12 ) ;
V_37 -> V_26 = true ;
F_14 ( V_10 ) -> V_26 = true ;
}
} else {
F_14 ( V_10 ) -> V_26 = true ;
}
return 0 ;
}
static void F_29 ( struct V_2 * V_3 ,
struct V_9 * V_32 )
{
struct V_13 * V_13 = F_6 ( V_3 ) ;
struct V_9 * V_10 = V_3 -> V_10 ;
F_23 ( L_7 , V_13 -> V_30 ) ;
if ( ! F_4 ( V_10 ) ) {
F_14 ( V_10 ) -> V_27 = true ;
} else if ( F_14 ( V_10 ) -> V_26 ) {
int V_38 ;
F_14 ( V_10 ) -> V_27 = true ;
V_38 = F_30 ( V_3 ,
V_10 -> V_12 , V_10 -> V_11 ,
V_10 -> V_39 , V_10 -> V_40 ,
V_10 -> V_41 , V_10 -> V_42 ,
V_10 -> V_43 , V_10 -> V_44 ,
V_10 -> V_35 , V_10 -> V_45 ) ;
F_18 ( V_38 < 0 ) ;
} else {
unsigned long V_46 ;
F_31 ( & V_13 -> V_47 , V_46 ) ;
F_32 ( V_3 , V_10 -> V_11 ) ;
F_33 ( & V_13 -> V_47 , V_46 ) ;
}
}
static void F_32 ( struct V_2 * V_3 ,
struct V_28 * V_11 )
{
struct V_13 * V_13 = F_6 ( V_3 ) ;
struct V_1 * V_1 = F_1 ( V_3 ) ;
enum V_48 V_49 = V_13 -> V_49 ;
F_34 ( V_1 , F_35 ( V_49 ) ,
F_36 ( V_11 -> V_50 [ 0 ] ) |
F_37 ( V_11 -> V_50 [ 1 ] ) ) ;
F_34 ( V_1 , F_38 ( V_49 ) ,
F_39 ( V_11 -> V_50 [ 2 ] ) |
F_40 ( V_11 -> V_50 [ 3 ] ) ) ;
F_34 ( V_1 , F_41 ( V_49 ) ,
F_42 ( V_11 , V_1 -> V_31 , 0 ) ) ;
F_34 ( V_1 , F_43 ( V_49 ) ,
F_42 ( V_11 , V_1 -> V_31 , 1 ) ) ;
F_34 ( V_1 , F_44 ( V_49 ) ,
F_42 ( V_11 , V_1 -> V_31 , 2 ) ) ;
F_34 ( V_1 , F_45 ( V_49 ) ,
F_42 ( V_11 , V_1 -> V_31 , 3 ) ) ;
V_3 -> V_11 = V_11 ;
}
static void F_46 ( struct V_1 * V_1 , enum V_48 V_49 )
{
T_2 V_51 = F_47 ( V_1 , F_48 ( V_49 ) ) &
~ V_52 ;
F_34 ( V_1 , F_48 ( V_49 ) , V_51 ) ;
}
static void F_49 ( struct V_1 * V_1 , enum V_48 V_49 ,
struct V_53 * V_54 )
{
T_2 V_55 , V_56 = 0 ;
T_2 * V_57 ;
if ( F_50 ( ! V_54 ) )
return;
if ( ( V_54 -> type == V_58 ) || ( V_59 == V_54 -> type ) )
V_56 |= F_51 ( V_60 ) ;
if ( ( V_54 -> type == V_61 ) || ( V_59 == V_54 -> type ) )
V_56 |= F_52 ( V_60 ) ;
V_56 |= V_52 ;
F_34 ( V_1 , F_48 ( V_49 ) , V_56 ) ;
V_57 = V_54 -> V_57 ;
F_34 ( V_1 , F_53 ( V_49 ) ,
F_54 ( V_57 [ 0 ] ) |
F_55 ( V_57 [ 1 ] ) ) ;
F_34 ( V_1 , F_56 ( V_49 ) ,
F_57 ( V_57 [ 2 ] ) |
F_58 ( V_57 [ 3 ] ) ) ;
F_34 ( V_1 , F_59 ( V_49 ) ,
F_60 ( V_57 [ 4 ] ) |
F_61 ( V_57 [ 5 ] ) ) ;
F_34 ( V_1 , F_62 ( V_49 ) ,
F_63 ( V_57 [ 6 ] ) |
F_64 ( V_57 [ 7 ] ) ) ;
F_34 ( V_1 , F_65 ( V_49 ) ,
F_66 ( V_57 [ 8 ] ) ) ;
for ( V_55 = 0 ; V_55 < F_67 ( V_54 -> V_62 ) ; V_55 ++ ) {
T_2 * V_63 = V_54 -> V_63 ;
T_2 * V_64 = V_54 -> V_64 ;
F_34 ( V_1 , F_68 ( V_49 , V_55 ) ,
F_69 ( V_63 [ 2 * V_55 + 1 ] ) |
F_70 ( V_63 [ 2 * V_55 ] ) ) ;
F_34 ( V_1 , F_71 ( V_49 , V_55 ) ,
F_72 ( V_64 [ 2 * V_55 + 1 ] ) |
F_73 ( V_64 [ 2 * V_55 ] ) ) ;
F_34 ( V_1 , F_74 ( V_49 , V_55 ) ,
F_75 ( V_54 -> V_62 [ V_55 ] ) ) ;
F_34 ( V_1 , F_76 ( V_49 , V_55 ) ,
F_77 ( V_54 -> V_65 [ V_55 ] ) ) ;
}
}
static int F_78 ( T_2 V_66 , T_2 V_67 , T_2 * V_68 )
{
T_2 V_69 ;
if ( V_66 == 0 || V_67 == 0 )
return - V_19 ;
if ( V_66 > ( V_67 * V_70 ) )
return - V_71 ;
V_69 = 1 << V_72 ;
* V_68 = F_79 ( V_69 , V_66 , V_67 ) ;
return 0 ;
}
static int F_80 ( T_2 V_34 , T_2 V_66 , T_2 V_73 ,
T_2 V_74 [ 2 ] )
{
T_2 V_75 ;
unsigned int V_76 ;
int V_38 ;
V_38 = F_78 ( V_66 , V_73 , & V_75 ) ;
if ( V_38 )
return V_38 ;
V_76 = F_81 ( V_34 ) ;
V_74 [ 0 ] = V_75 ;
V_74 [ 1 ] = V_75 / V_76 ;
return 0 ;
}
static int F_82 ( T_2 V_34 , T_2 V_66 , T_2 V_73 ,
T_2 V_77 [ 2 ] )
{
T_2 V_78 ;
unsigned int V_79 ;
int V_38 ;
V_38 = F_78 ( V_66 , V_73 , & V_78 ) ;
if ( V_38 )
return V_38 ;
V_79 = F_83 ( V_34 ) ;
V_77 [ 0 ] = V_78 ;
V_77 [ 1 ] = V_78 / V_79 ;
return 0 ;
}
static T_2 F_84 ( T_2 V_66 , T_2 V_73 )
{
T_2 V_80 ;
V_80 = ( V_66 <= V_73 ) ? V_81 : V_82 ;
return V_83 |
F_85 ( V_80 ) |
F_86 ( V_80 ) |
F_87 ( V_80 ) ;
}
static T_2 F_88 ( T_2 V_66 , T_2 V_73 )
{
T_2 V_80 ;
V_80 = ( V_66 <= V_73 ) ? V_81 : V_82 ;
return V_84 |
F_89 ( V_80 ) |
F_90 ( V_80 ) |
F_91 ( V_80 ) ;
}
static int F_30 ( struct V_2 * V_3 ,
struct V_85 * V_12 , struct V_28 * V_11 ,
int V_39 , int V_40 ,
unsigned int V_41 , unsigned int V_42 ,
T_2 V_43 , T_2 V_44 ,
T_2 V_35 , T_2 V_45 )
{
struct V_13 * V_13 = F_6 ( V_3 ) ;
struct V_1 * V_1 = F_1 ( V_3 ) ;
struct V_86 * V_6 = V_1 -> V_6 -> V_6 ;
enum V_48 V_49 = V_13 -> V_49 ;
const struct V_87 * V_88 ;
T_2 V_89 , V_90 = 0 ;
T_2 V_75 [ 2 ] = { 0 ,} , V_78 [ 2 ] = { 0 ,} ;
T_2 V_91 = 0 , V_92 = 0 ;
T_2 V_93 ;
unsigned long V_46 ;
int V_38 ;
V_89 = F_92 ( V_11 -> V_34 ) ;
if ( F_18 ( V_89 > F_93 ( V_49 ) ) )
return - V_19 ;
V_88 = F_94 ( F_95 ( V_11 ) ) ;
V_93 = V_88 -> V_25 . V_34 ;
V_43 = V_43 >> 16 ;
V_44 = V_44 >> 16 ;
V_35 = V_35 >> 16 ;
V_45 = V_45 >> 16 ;
F_23 ( L_8 , V_13 -> V_30 ,
V_11 -> V_25 . V_31 , V_43 , V_44 , V_35 , V_45 ,
V_12 -> V_25 . V_31 , V_39 , V_40 , V_41 , V_42 ) ;
V_38 = F_96 ( V_1 -> V_94 ,
V_13 -> V_49 , V_11 -> V_34 , V_35 ) ;
if ( V_38 )
return V_38 ;
F_97 ( V_1 -> V_94 , V_49 ) ;
if ( ( V_35 != V_41 ) || F_98 ( V_88 ) ) {
V_38 = F_80 ( V_93 , V_35 , V_41 , V_75 ) ;
if ( V_38 ) {
F_99 ( V_6 , L_9 ,
V_35 , V_41 , V_38 ) ;
return V_38 ;
}
V_90 |= F_84 ( V_35 , V_41 ) ;
}
if ( ( V_45 != V_42 ) || F_98 ( V_88 ) ) {
V_38 = F_82 ( V_93 , V_45 , V_42 , V_78 ) ;
if ( V_38 ) {
F_99 ( V_6 , L_10 ,
V_45 , V_42 , V_38 ) ;
return V_38 ;
}
V_90 |= F_88 ( V_45 , V_42 ) ;
}
F_31 ( & V_13 -> V_47 , V_46 ) ;
F_34 ( V_1 , F_100 ( V_49 ) ,
F_101 ( V_11 -> V_95 ) |
F_102 ( V_11 -> V_96 ) ) ;
F_34 ( V_1 , F_103 ( V_49 ) ,
F_104 ( V_35 ) |
F_105 ( V_45 ) ) ;
F_34 ( V_1 , F_106 ( V_49 ) ,
F_107 ( V_43 ) |
F_108 ( V_44 ) ) ;
F_34 ( V_1 , F_109 ( V_49 ) ,
F_110 ( V_41 ) |
F_111 ( V_42 ) ) ;
F_34 ( V_1 , F_112 ( V_49 ) ,
F_113 ( V_39 ) |
F_114 ( V_40 ) ) ;
F_34 ( V_1 , F_115 ( V_49 ) ,
F_116 ( V_88 -> V_97 ) |
F_117 ( V_88 -> V_98 ) |
F_118 ( V_88 -> V_99 ) |
F_119 ( V_88 -> V_100 ) |
F_120 ( V_88 -> V_101 , V_102 ) |
F_121 ( V_88 -> V_103 - 1 ) |
F_122 ( V_88 -> V_104 - 1 ) |
F_120 ( V_88 -> V_105 , V_106 ) |
F_123 ( V_88 -> V_107 ) |
F_124 ( V_88 -> V_108 ) ) ;
F_34 ( V_1 , F_125 ( V_49 ) ,
F_126 ( V_88 -> V_109 [ 0 ] ) |
F_127 ( V_88 -> V_109 [ 1 ] ) |
F_128 ( V_88 -> V_109 [ 2 ] ) |
F_129 ( V_88 -> V_109 [ 3 ] ) ) ;
F_34 ( V_1 , F_130 ( V_49 ) ,
F_131 ( V_110 ) ) ;
F_34 ( V_1 , F_132 ( V_49 ) , 0 ) ;
F_34 ( V_1 , F_133 ( V_49 ) ,
V_75 [ 0 ] ) ;
F_34 ( V_1 , F_134 ( V_49 ) ,
V_78 [ 0 ] ) ;
F_34 ( V_1 , F_135 ( V_49 ) ,
V_75 [ 1 ] ) ;
F_34 ( V_1 , F_136 ( V_49 ) ,
V_78 [ 1 ] ) ;
F_34 ( V_1 , F_137 ( V_49 ) ,
F_138 ( V_92 ) |
F_139 ( V_91 ) ) ;
F_34 ( V_1 , F_140 ( V_49 ) , V_90 ) ;
if ( F_98 ( V_88 ) )
F_49 ( V_1 , V_49 ,
F_141 ( V_58 ) ) ;
else
F_46 ( V_1 , V_49 ) ;
F_32 ( V_3 , V_11 ) ;
F_33 ( & V_13 -> V_47 , V_46 ) ;
return V_38 ;
}
void F_142 ( struct V_2 * V_3 )
{
struct V_1 * V_1 = F_1 ( V_3 ) ;
struct V_13 * V_13 = F_6 ( V_3 ) ;
enum V_48 V_49 = V_13 -> V_49 ;
F_23 ( L_11 , V_13 -> V_30 ) ;
F_143 ( V_1 -> V_94 , V_49 ) ;
F_14 ( V_3 -> V_10 ) -> V_27 = false ;
}
enum V_48 F_144 ( struct V_2 * V_3 )
{
struct V_13 * V_13 = F_6 ( V_3 ) ;
return V_13 -> V_49 ;
}
T_2 F_145 ( struct V_2 * V_3 )
{
struct V_13 * V_13 = F_6 ( V_3 ) ;
return V_13 -> V_111 ;
}
void F_146 ( struct V_2 * V_3 ,
struct V_9 * V_10 )
{
struct V_1 * V_1 = F_1 ( V_3 ) ;
struct V_13 * V_13 = F_6 ( V_3 ) ;
enum V_48 V_49 = V_13 -> V_49 ;
if ( ! F_4 ( V_3 -> V_10 ) ) {
F_23 ( L_12 , V_13 -> V_30 ) ;
F_147 ( V_1 -> V_94 , V_49 ) ;
}
}
struct V_2 * F_148 ( struct V_112 * V_6 ,
enum V_48 V_49 , bool V_113 , T_2 V_114 )
{
struct V_2 * V_3 = NULL ;
struct V_13 * V_13 ;
int V_38 ;
enum V_115 type ;
V_13 = F_15 ( sizeof( * V_13 ) , V_22 ) ;
if ( ! V_13 ) {
V_38 = - V_116 ;
goto V_117;
}
V_3 = & V_13 -> V_25 ;
V_13 -> V_49 = V_49 ;
V_13 -> V_30 = F_149 ( V_49 ) ;
V_13 -> V_118 = F_150 ( V_49 , V_13 -> V_119 ,
F_67 ( V_13 -> V_119 ) ) ;
V_13 -> V_111 = F_151 ( V_49 ) ;
V_13 -> V_114 = V_114 ;
F_152 ( & V_13 -> V_47 ) ;
type = V_113 ? V_23 : V_120 ;
V_38 = F_153 ( V_6 , V_3 , 0xff , & V_121 ,
V_13 -> V_119 , V_13 -> V_118 ,
type ) ;
if ( V_38 )
goto V_117;
F_154 ( V_3 , & V_122 ) ;
F_10 ( V_3 , & V_3 -> V_25 ) ;
return V_3 ;
V_117:
if ( V_3 )
F_5 ( V_3 ) ;
return F_155 ( V_38 ) ;
}
