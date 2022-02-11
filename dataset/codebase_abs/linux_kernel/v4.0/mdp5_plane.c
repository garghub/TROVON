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
struct V_32 * V_11 )
{
struct V_13 * V_13 = F_6 ( V_3 ) ;
struct V_1 * V_1 = F_1 ( V_3 ) ;
F_7 ( L_2 , V_13 -> V_16 , V_11 -> V_29 . V_33 ) ;
return F_26 ( V_11 , V_1 -> V_33 ) ;
}
static void F_27 ( struct V_2 * V_3 ,
struct V_32 * V_11 )
{
struct V_13 * V_13 = F_6 ( V_3 ) ;
struct V_1 * V_1 = F_1 ( V_3 ) ;
F_7 ( L_3 , V_13 -> V_16 , V_11 -> V_29 . V_33 ) ;
F_28 ( V_11 , V_1 -> V_33 ) ;
}
static int F_29 ( struct V_2 * V_3 ,
struct V_9 * V_10 )
{
struct V_13 * V_13 = F_6 ( V_3 ) ;
struct V_9 * V_34 = V_3 -> V_10 ;
F_7 ( L_4 , V_13 -> V_16 ,
F_4 ( V_34 ) , F_4 ( V_10 ) ) ;
if ( F_4 ( V_10 ) && F_4 ( V_34 ) ) {
bool V_35 = false ;
if ( V_10 -> V_11 -> V_36 != V_34 -> V_11 -> V_36 ) {
F_7 ( L_5 , V_13 -> V_16 ) ;
V_35 = true ;
}
if ( V_10 -> V_37 != V_34 -> V_37 ) {
F_7 ( L_6 , V_13 -> V_16 ) ;
V_35 = true ;
}
if ( F_17 ( V_34 ) -> V_31 ) {
F_7 ( L_7 , V_13 -> V_16 ) ;
V_35 = true ;
}
if ( V_35 ) {
struct V_38 * V_39 =
F_30 ( V_10 -> V_10 , V_10 -> V_12 ) ;
V_39 -> V_30 = true ;
F_17 ( V_10 ) -> V_30 = true ;
}
} else {
F_17 ( V_10 ) -> V_30 = true ;
}
return 0 ;
}
static void F_31 ( struct V_2 * V_3 ,
struct V_9 * V_34 )
{
struct V_13 * V_13 = F_6 ( V_3 ) ;
struct V_9 * V_10 = V_3 -> V_10 ;
F_7 ( L_8 , V_13 -> V_16 ) ;
if ( ! F_4 ( V_10 ) ) {
F_17 ( V_10 ) -> V_31 = true ;
F_5 ( V_3 ) ;
} else if ( F_17 ( V_10 ) -> V_30 ) {
int V_40 ;
F_17 ( V_10 ) -> V_31 = true ;
V_40 = F_32 ( V_3 ,
V_10 -> V_12 , V_10 -> V_11 ,
V_10 -> V_41 , V_10 -> V_42 ,
V_10 -> V_43 , V_10 -> V_44 ,
V_10 -> V_45 , V_10 -> V_46 ,
V_10 -> V_37 , V_10 -> V_47 ) ;
F_21 ( V_40 < 0 ) ;
} else {
unsigned long V_48 ;
F_33 ( & V_13 -> V_49 , V_48 ) ;
F_34 ( V_3 , V_10 -> V_11 ) ;
F_35 ( & V_13 -> V_49 , V_48 ) ;
}
}
static void F_34 ( struct V_2 * V_3 ,
struct V_32 * V_11 )
{
struct V_13 * V_13 = F_6 ( V_3 ) ;
struct V_1 * V_1 = F_1 ( V_3 ) ;
enum V_14 V_15 = V_13 -> V_15 ;
F_36 ( V_1 , F_37 ( V_15 ) ,
F_38 ( V_11 -> V_50 [ 0 ] ) |
F_39 ( V_11 -> V_50 [ 1 ] ) ) ;
F_36 ( V_1 , F_40 ( V_15 ) ,
F_41 ( V_11 -> V_50 [ 2 ] ) |
F_42 ( V_11 -> V_50 [ 3 ] ) ) ;
F_36 ( V_1 , F_43 ( V_15 ) ,
F_44 ( V_11 , V_1 -> V_33 , 0 ) ) ;
F_36 ( V_1 , F_45 ( V_15 ) ,
F_44 ( V_11 , V_1 -> V_33 , 1 ) ) ;
F_36 ( V_1 , F_46 ( V_15 ) ,
F_44 ( V_11 , V_1 -> V_33 , 2 ) ) ;
F_36 ( V_1 , F_47 ( V_15 ) ,
F_44 ( V_11 , V_1 -> V_33 , 4 ) ) ;
V_3 -> V_11 = V_11 ;
}
static void F_48 ( struct V_1 * V_1 , enum V_14 V_15 )
{
T_2 V_51 = F_49 ( V_1 , F_50 ( V_15 ) ) &
~ V_52 ;
F_36 ( V_1 , F_50 ( V_15 ) , V_51 ) ;
}
static void F_51 ( struct V_1 * V_1 , enum V_14 V_15 ,
struct V_53 * V_54 )
{
T_2 V_55 , V_56 = 0 ;
T_2 * V_57 ;
if ( F_52 ( ! V_54 ) )
return;
if ( ( V_54 -> type == V_58 ) || ( V_59 == V_54 -> type ) )
V_56 |= F_53 ( V_60 ) ;
if ( ( V_54 -> type == V_61 ) || ( V_59 == V_54 -> type ) )
V_56 |= F_54 ( V_60 ) ;
V_56 |= V_52 ;
F_36 ( V_1 , F_50 ( V_15 ) , V_56 ) ;
V_57 = V_54 -> V_57 ;
F_36 ( V_1 , F_55 ( V_15 ) ,
F_56 ( V_57 [ 0 ] ) |
F_57 ( V_57 [ 1 ] ) ) ;
F_36 ( V_1 , F_58 ( V_15 ) ,
F_59 ( V_57 [ 2 ] ) |
F_60 ( V_57 [ 3 ] ) ) ;
F_36 ( V_1 , F_61 ( V_15 ) ,
F_62 ( V_57 [ 4 ] ) |
F_63 ( V_57 [ 5 ] ) ) ;
F_36 ( V_1 , F_64 ( V_15 ) ,
F_65 ( V_57 [ 6 ] ) |
F_66 ( V_57 [ 7 ] ) ) ;
F_36 ( V_1 , F_67 ( V_15 ) ,
F_68 ( V_57 [ 8 ] ) ) ;
for ( V_55 = 0 ; V_55 < F_69 ( V_54 -> V_62 ) ; V_55 ++ ) {
T_2 * V_63 = V_54 -> V_63 ;
T_2 * V_64 = V_54 -> V_64 ;
F_36 ( V_1 , F_70 ( V_15 , V_55 ) ,
F_71 ( V_63 [ 2 * V_55 + 1 ] ) |
F_72 ( V_63 [ 2 * V_55 ] ) ) ;
F_36 ( V_1 , F_73 ( V_15 , V_55 ) ,
F_74 ( V_64 [ 2 * V_55 + 1 ] ) |
F_75 ( V_64 [ 2 * V_55 ] ) ) ;
F_36 ( V_1 , F_76 ( V_15 , V_55 ) ,
F_77 ( V_54 -> V_62 [ V_55 ] ) ) ;
F_36 ( V_1 , F_78 ( V_15 , V_55 ) ,
F_79 ( V_54 -> V_65 [ V_55 ] ) ) ;
}
}
static int F_80 ( T_2 V_66 , T_2 V_67 , T_2 * V_68 )
{
T_2 V_69 ;
if ( V_66 == 0 || V_67 == 0 )
return - V_23 ;
if ( V_66 > ( V_67 * V_70 ) )
return - V_71 ;
V_69 = 1 << V_72 ;
* V_68 = F_81 ( V_69 , V_66 , V_67 ) ;
return 0 ;
}
static int F_82 ( T_2 V_36 , T_2 V_66 , T_2 V_73 ,
T_2 V_74 [ 2 ] )
{
T_2 V_75 ;
unsigned int V_76 ;
int V_40 ;
V_40 = F_80 ( V_66 , V_73 , & V_75 ) ;
if ( V_40 )
return V_40 ;
V_76 = F_83 ( V_36 ) ;
V_74 [ 0 ] = V_75 ;
V_74 [ 1 ] = V_75 / V_76 ;
return 0 ;
}
static int F_84 ( T_2 V_36 , T_2 V_66 , T_2 V_73 ,
T_2 V_77 [ 2 ] )
{
T_2 V_78 ;
unsigned int V_79 ;
int V_40 ;
V_40 = F_80 ( V_66 , V_73 , & V_78 ) ;
if ( V_40 )
return V_40 ;
V_79 = F_85 ( V_36 ) ;
V_77 [ 0 ] = V_78 ;
V_77 [ 1 ] = V_78 / V_79 ;
return 0 ;
}
static T_2 F_86 ( T_2 V_66 , T_2 V_73 )
{
T_2 V_80 ;
V_80 = ( V_66 <= V_73 ) ? V_81 : V_82 ;
return V_83 |
F_87 ( V_80 ) |
F_88 ( V_80 ) |
F_89 ( V_80 ) ;
}
static T_2 F_90 ( T_2 V_66 , T_2 V_73 )
{
T_2 V_80 ;
V_80 = ( V_66 <= V_73 ) ? V_81 : V_82 ;
return V_84 |
F_91 ( V_80 ) |
F_92 ( V_80 ) |
F_93 ( V_80 ) ;
}
static int F_32 ( struct V_2 * V_3 ,
struct V_85 * V_12 , struct V_32 * V_11 ,
int V_41 , int V_42 ,
unsigned int V_43 , unsigned int V_44 ,
T_2 V_45 , T_2 V_46 ,
T_2 V_37 , T_2 V_47 )
{
struct V_13 * V_13 = F_6 ( V_3 ) ;
struct V_1 * V_1 = F_1 ( V_3 ) ;
struct V_86 * V_6 = V_1 -> V_6 -> V_6 ;
enum V_14 V_15 = V_13 -> V_15 ;
const struct V_87 * V_88 ;
T_2 V_89 , V_90 = 0 ;
T_2 V_75 [ 2 ] = { 0 ,} , V_78 [ 2 ] = { 0 ,} ;
T_2 V_91 = 0 , V_92 = 0 ;
T_2 V_93 ;
unsigned long V_48 ;
int V_40 ;
V_89 = F_94 ( V_11 -> V_36 ) ;
if ( F_21 ( V_89 > F_95 ( V_15 ) ) )
return - V_23 ;
V_88 = F_96 ( F_97 ( V_11 ) ) ;
V_93 = V_88 -> V_29 . V_36 ;
V_45 = V_45 >> 16 ;
V_46 = V_46 >> 16 ;
V_37 = V_37 >> 16 ;
V_47 = V_47 >> 16 ;
F_7 ( L_9 , V_13 -> V_16 ,
V_11 -> V_29 . V_33 , V_45 , V_46 , V_37 , V_47 ,
V_12 -> V_29 . V_33 , V_41 , V_42 , V_43 , V_44 ) ;
V_40 = F_98 ( V_1 -> V_17 ,
V_13 -> V_15 , V_11 -> V_36 , V_37 ) ;
if ( V_40 )
return V_40 ;
F_99 ( V_1 -> V_17 , V_15 ) ;
if ( ( V_37 != V_43 ) || F_100 ( V_88 ) ) {
V_40 = F_82 ( V_93 , V_37 , V_43 , V_75 ) ;
if ( V_40 ) {
F_101 ( V_6 , L_10 ,
V_37 , V_43 , V_40 ) ;
return V_40 ;
}
V_90 |= F_86 ( V_37 , V_43 ) ;
}
if ( ( V_47 != V_44 ) || F_100 ( V_88 ) ) {
V_40 = F_84 ( V_93 , V_47 , V_44 , V_78 ) ;
if ( V_40 ) {
F_101 ( V_6 , L_11 ,
V_47 , V_44 , V_40 ) ;
return V_40 ;
}
V_90 |= F_90 ( V_47 , V_44 ) ;
}
F_33 ( & V_13 -> V_49 , V_48 ) ;
F_36 ( V_1 , F_102 ( V_15 ) ,
F_103 ( V_37 ) |
F_104 ( V_47 ) ) ;
F_36 ( V_1 , F_105 ( V_15 ) ,
F_106 ( V_37 ) |
F_107 ( V_47 ) ) ;
F_36 ( V_1 , F_108 ( V_15 ) ,
F_109 ( V_45 ) |
F_110 ( V_46 ) ) ;
F_36 ( V_1 , F_111 ( V_15 ) ,
F_112 ( V_43 ) |
F_113 ( V_44 ) ) ;
F_36 ( V_1 , F_114 ( V_15 ) ,
F_115 ( V_41 ) |
F_116 ( V_42 ) ) ;
F_36 ( V_1 , F_117 ( V_15 ) ,
F_118 ( V_88 -> V_94 ) |
F_119 ( V_88 -> V_95 ) |
F_120 ( V_88 -> V_96 ) |
F_121 ( V_88 -> V_97 ) |
F_122 ( V_88 -> V_98 , V_99 ) |
F_123 ( V_88 -> V_100 - 1 ) |
F_124 ( V_88 -> V_101 - 1 ) |
F_122 ( V_88 -> V_102 , V_103 ) |
F_125 ( V_88 -> V_104 ) |
F_126 ( V_88 -> V_105 ) ) ;
F_36 ( V_1 , F_127 ( V_15 ) ,
F_128 ( V_88 -> V_106 [ 0 ] ) |
F_129 ( V_88 -> V_106 [ 1 ] ) |
F_130 ( V_88 -> V_106 [ 2 ] ) |
F_131 ( V_88 -> V_106 [ 3 ] ) ) ;
F_36 ( V_1 , F_132 ( V_15 ) ,
F_133 ( V_107 ) ) ;
F_36 ( V_1 , F_134 ( V_15 ) , 0 ) ;
F_36 ( V_1 , F_135 ( V_15 ) ,
V_75 [ 0 ] ) ;
F_36 ( V_1 , F_136 ( V_15 ) ,
V_78 [ 0 ] ) ;
F_36 ( V_1 , F_137 ( V_15 ) ,
V_75 [ 1 ] ) ;
F_36 ( V_1 , F_138 ( V_15 ) ,
V_78 [ 1 ] ) ;
F_36 ( V_1 , F_139 ( V_15 ) ,
F_140 ( V_92 ) |
F_141 ( V_91 ) ) ;
F_36 ( V_1 , F_142 ( V_15 ) , V_90 ) ;
if ( F_100 ( V_88 ) )
F_51 ( V_1 , V_15 ,
F_143 ( V_58 ) ) ;
else
F_48 ( V_1 , V_15 ) ;
F_34 ( V_3 , V_11 ) ;
F_35 ( & V_13 -> V_49 , V_48 ) ;
return V_40 ;
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
return V_13 -> V_108 ;
}
struct V_2 * F_148 ( struct V_109 * V_6 ,
enum V_14 V_15 , bool V_110 , T_2 V_111 )
{
struct V_2 * V_3 = NULL ;
struct V_13 * V_13 ;
int V_40 ;
enum V_112 type ;
V_13 = F_18 ( sizeof( * V_13 ) , V_26 ) ;
if ( ! V_13 ) {
V_40 = - V_113 ;
goto V_114;
}
V_3 = & V_13 -> V_29 ;
V_13 -> V_15 = V_15 ;
V_13 -> V_16 = F_149 ( V_15 ) ;
V_13 -> V_115 = F_150 ( V_15 , V_13 -> V_116 ,
F_69 ( V_13 -> V_116 ) ) ;
V_13 -> V_108 = F_151 ( V_15 ) ;
V_13 -> V_111 = V_111 ;
F_152 ( & V_13 -> V_49 ) ;
type = V_110 ? V_27 : V_117 ;
V_40 = F_153 ( V_6 , V_3 , 0xff , & V_118 ,
V_13 -> V_116 , V_13 -> V_115 ,
type ) ;
if ( V_40 )
goto V_114;
F_154 ( V_3 , & V_119 ) ;
F_13 ( V_3 , & V_3 -> V_29 ) ;
return V_3 ;
V_114:
if ( V_3 )
F_9 ( V_3 ) ;
return F_155 ( V_40 ) ;
}
