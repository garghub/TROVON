int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 ;
int V_5 = - 1 ;
F_2 ( & V_6 ) ;
F_3 (map, &pci2phy_map_head, list) {
if ( V_4 -> V_7 == F_4 ( V_2 ) ) {
V_5 = V_4 -> V_8 [ V_2 -> V_9 ] ;
break;
}
}
F_5 ( & V_6 ) ;
return V_5 ;
}
struct V_3 * F_6 ( int V_7 )
{
struct V_3 * V_4 , * V_10 = NULL ;
int V_11 ;
F_7 ( & V_6 ) ;
V_12:
F_3 (map, &pci2phy_map_head, list) {
if ( V_4 -> V_7 == V_7 )
goto V_13;
}
if ( ! V_10 ) {
F_5 ( & V_6 ) ;
V_10 = F_8 ( sizeof( struct V_3 ) , V_14 ) ;
F_2 ( & V_6 ) ;
if ( ! V_10 )
return NULL ;
goto V_12;
}
V_4 = V_10 ;
V_10 = NULL ;
V_4 -> V_7 = V_7 ;
for ( V_11 = 0 ; V_11 < 256 ; V_11 ++ )
V_4 -> V_8 [ V_11 ] = - 1 ;
F_9 ( & V_4 -> V_15 , & V_16 ) ;
V_13:
F_10 ( V_10 ) ;
return V_4 ;
}
T_1 F_11 ( struct V_17 * V_18 ,
struct V_19 * V_20 , char * V_21 )
{
struct V_22 * V_23 =
F_12 ( V_20 , struct V_22 , V_20 ) ;
return sprintf ( V_21 , L_1 , V_23 -> V_24 ) ;
}
struct V_25 * F_13 ( struct V_26 * V_23 )
{
return F_12 ( V_23 -> V_27 , struct V_25 , V_27 ) ;
}
struct V_28 * F_14 ( struct V_25 * V_27 , int V_29 )
{
struct V_28 * V_30 ;
V_30 = * F_15 ( V_27 -> V_30 , V_29 ) ;
if ( V_30 )
return V_30 ;
F_2 ( & V_31 ) ;
if ( * F_15 ( V_27 -> V_30 , V_29 ) )
goto V_32;
F_3 (box, &pmu->box_list, list) {
if ( V_30 -> V_5 == F_16 ( V_29 ) ) {
F_17 ( & V_30 -> V_33 ) ;
* F_15 ( V_27 -> V_30 , V_29 ) = V_30 ;
break;
}
}
V_32:
F_5 ( & V_31 ) ;
return * F_15 ( V_27 -> V_30 , V_29 ) ;
}
struct V_28 * F_18 ( struct V_26 * V_23 )
{
return F_14 ( F_13 ( V_23 ) , F_19 () ) ;
}
T_2 F_20 ( struct V_28 * V_30 , struct V_26 * V_23 )
{
T_2 V_34 ;
F_21 ( V_23 -> V_35 . V_36 , V_34 ) ;
return V_34 ;
}
struct V_37 *
F_22 ( struct V_28 * V_30 , struct V_26 * V_23 )
{
struct V_38 * V_39 ;
struct V_40 * V_41 = & V_23 -> V_35 . V_42 ;
struct V_40 * V_43 = & V_23 -> V_35 . V_44 ;
unsigned long V_45 ;
bool V_46 = false ;
if ( V_41 -> V_47 == V_48 ||
( ! F_23 ( V_30 ) && V_41 -> V_10 ) )
return NULL ;
V_39 = & V_30 -> V_49 [ V_41 -> V_47 ] ;
F_24 ( & V_39 -> V_50 , V_45 ) ;
if ( ! F_25 ( & V_39 -> V_51 ) ||
( V_39 -> V_52 == V_41 -> V_24 && V_39 -> V_53 == V_43 -> V_24 ) ) {
F_17 ( & V_39 -> V_51 ) ;
V_39 -> V_52 = V_41 -> V_24 ;
V_39 -> V_53 = V_43 -> V_24 ;
V_46 = true ;
}
F_26 ( & V_39 -> V_50 , V_45 ) ;
if ( V_46 ) {
if ( ! F_23 ( V_30 ) )
V_41 -> V_10 = 1 ;
return NULL ;
}
return & V_54 ;
}
void F_27 ( struct V_28 * V_30 , struct V_26 * V_23 )
{
struct V_38 * V_39 ;
struct V_40 * V_41 = & V_23 -> V_35 . V_42 ;
if ( F_23 ( V_30 ) || ! V_41 -> V_10 )
return;
V_39 = & V_30 -> V_49 [ V_41 -> V_47 ] ;
F_28 ( & V_39 -> V_51 ) ;
V_41 -> V_10 = 0 ;
}
T_2 F_29 ( struct V_28 * V_30 , int V_47 )
{
struct V_38 * V_39 ;
unsigned long V_45 ;
T_2 V_24 ;
V_39 = & V_30 -> V_49 [ V_47 ] ;
F_24 ( & V_39 -> V_50 , V_45 ) ;
V_24 = V_39 -> V_24 ;
F_26 ( & V_39 -> V_50 , V_45 ) ;
return V_24 ;
}
static void F_30 ( struct V_28 * V_30 , struct V_26 * V_23 , int V_47 )
{
struct V_55 * V_56 = & V_23 -> V_35 ;
V_56 -> V_47 = V_47 ;
V_56 -> V_57 = ++ V_30 -> V_58 [ V_47 ] ;
if ( V_56 -> V_47 == V_59 ) {
V_56 -> V_36 = F_31 ( V_30 ) ;
V_56 -> V_60 = F_32 ( V_30 ) ;
return;
}
V_56 -> V_60 = F_33 ( V_30 , V_56 -> V_47 ) ;
V_56 -> V_36 = F_34 ( V_30 , V_56 -> V_47 ) ;
}
void F_35 ( struct V_28 * V_30 , struct V_26 * V_23 )
{
T_2 V_61 , V_62 , V_63 ;
int V_64 ;
if ( V_23 -> V_35 . V_47 >= V_59 )
V_64 = 64 - F_36 ( V_30 ) ;
else
V_64 = 64 - F_37 ( V_30 ) ;
V_65:
V_61 = F_38 ( & V_23 -> V_35 . V_61 ) ;
V_62 = F_39 ( V_30 , V_23 ) ;
if ( F_40 ( & V_23 -> V_35 . V_61 , V_62 ) != V_61 )
goto V_65;
V_63 = ( V_62 << V_64 ) - ( V_61 << V_64 ) ;
V_63 >>= V_64 ;
F_41 ( V_63 , & V_23 -> V_34 ) ;
}
static enum V_66 F_42 ( struct V_67 * V_67 )
{
struct V_28 * V_30 ;
struct V_26 * V_23 ;
unsigned long V_45 ;
int V_68 ;
V_30 = F_12 ( V_67 , struct V_28 , V_67 ) ;
if ( ! V_30 -> V_69 || V_30 -> V_29 != F_19 () )
return V_70 ;
F_43 ( V_45 ) ;
F_3 (event, &box->active_list, active_entry) {
F_35 ( V_30 , V_23 ) ;
}
F_44 (bit, box->active_mask, UNCORE_PMC_IDX_MAX)
F_35 ( V_30 , V_30 -> V_71 [ V_68 ] ) ;
F_45 ( V_45 ) ;
F_46 ( V_67 , F_47 ( V_30 -> V_72 ) ) ;
return V_73 ;
}
void F_48 ( struct V_28 * V_30 )
{
F_49 ( & V_30 -> V_67 , F_47 ( V_30 -> V_72 ) ,
V_74 ) ;
}
void F_50 ( struct V_28 * V_30 )
{
F_51 ( & V_30 -> V_67 ) ;
}
static void F_52 ( struct V_28 * V_30 )
{
F_53 ( & V_30 -> V_67 , V_75 , V_76 ) ;
V_30 -> V_67 . V_77 = F_42 ;
}
static struct V_28 * F_54 ( struct V_78 * type , int V_79 )
{
struct V_28 * V_30 ;
int V_11 , V_80 ;
V_80 = sizeof( * V_30 ) + type -> V_81 * sizeof( struct V_38 ) ;
V_30 = F_55 ( V_80 , V_14 , V_79 ) ;
if ( ! V_30 )
return NULL ;
for ( V_11 = 0 ; V_11 < type -> V_81 ; V_11 ++ )
F_56 ( & V_30 -> V_49 [ V_11 ] . V_50 ) ;
F_52 ( V_30 ) ;
F_57 ( & V_30 -> V_33 , 1 ) ;
V_30 -> V_29 = - 1 ;
V_30 -> V_5 = - 1 ;
V_30 -> V_72 = V_82 ;
F_58 ( & V_30 -> V_83 ) ;
return V_30 ;
}
static bool F_59 ( struct V_26 * V_23 )
{
return V_23 -> V_27 -> V_84 == V_85 ;
}
static int
F_60 ( struct V_28 * V_30 , struct V_26 * V_86 , bool V_87 )
{
struct V_26 * V_23 ;
int V_88 , V_89 ;
V_89 = V_30 -> V_27 -> type -> V_90 ;
if ( V_30 -> V_27 -> type -> V_91 )
V_89 ++ ;
if ( V_30 -> V_92 >= V_89 )
return - V_93 ;
V_88 = V_30 -> V_92 ;
if ( F_59 ( V_86 ) ) {
V_30 -> V_94 [ V_88 ] = V_86 ;
V_88 ++ ;
}
if ( ! V_87 )
return V_88 ;
F_3 (event, &leader->sibling_list, group_entry) {
if ( ! F_59 ( V_23 ) ||
V_23 -> V_95 <= V_96 )
continue;
if ( V_88 >= V_89 )
return - V_93 ;
V_30 -> V_94 [ V_88 ] = V_23 ;
V_88 ++ ;
}
return V_88 ;
}
static struct V_37 *
F_61 ( struct V_28 * V_30 , struct V_26 * V_23 )
{
struct V_78 * type = V_30 -> V_27 -> type ;
struct V_37 * V_97 ;
if ( type -> V_98 -> V_99 ) {
V_97 = type -> V_98 -> V_99 ( V_30 , V_23 ) ;
if ( V_97 )
return V_97 ;
}
if ( V_23 -> V_20 . V_24 == V_100 )
return & V_101 ;
if ( type -> V_102 ) {
F_62 (c, type->constraints) {
if ( ( V_23 -> V_35 . V_24 & V_97 -> V_103 ) == V_97 -> V_104 )
return V_97 ;
}
}
return & type -> V_105 ;
}
static void F_63 ( struct V_28 * V_30 , struct V_26 * V_23 )
{
if ( V_30 -> V_27 -> type -> V_98 -> V_106 )
V_30 -> V_27 -> type -> V_98 -> V_106 ( V_30 , V_23 ) ;
}
static int F_64 ( struct V_28 * V_30 , int V_107 [] , int V_88 )
{
unsigned long V_108 [ F_65 ( V_109 ) ] ;
struct V_37 * V_97 ;
int V_11 , V_110 , V_111 , V_112 = 0 ;
struct V_55 * V_56 ;
F_66 ( V_108 , V_109 ) ;
for ( V_11 = 0 , V_110 = V_109 , V_111 = 0 ; V_11 < V_88 ; V_11 ++ ) {
V_97 = F_61 ( V_30 , V_30 -> V_94 [ V_11 ] ) ;
V_30 -> V_37 [ V_11 ] = V_97 ;
V_110 = F_67 ( V_110 , V_97 -> V_113 ) ;
V_111 = F_68 ( V_111 , V_97 -> V_113 ) ;
}
for ( V_11 = 0 ; V_11 < V_88 ; V_11 ++ ) {
V_56 = & V_30 -> V_94 [ V_11 ] -> V_35 ;
V_97 = V_30 -> V_37 [ V_11 ] ;
if ( V_56 -> V_47 == - 1 )
break;
if ( ! F_69 ( V_56 -> V_47 , V_97 -> V_114 ) )
break;
if ( F_69 ( V_56 -> V_47 , V_108 ) )
break;
F_70 ( V_56 -> V_47 , V_108 ) ;
if ( V_107 )
V_107 [ V_11 ] = V_56 -> V_47 ;
}
if ( V_11 != V_88 )
V_112 = F_71 ( V_30 -> V_37 , V_88 ,
V_110 , V_111 , V_88 , V_107 ) ;
if ( ! V_107 || V_112 ) {
for ( V_11 = 0 ; V_11 < V_88 ; V_11 ++ )
F_63 ( V_30 , V_30 -> V_94 [ V_11 ] ) ;
}
return V_112 ? - V_93 : 0 ;
}
static void F_72 ( struct V_26 * V_23 , int V_45 )
{
struct V_28 * V_30 = F_18 ( V_23 ) ;
int V_47 = V_23 -> V_35 . V_47 ;
if ( F_73 ( ! ( V_23 -> V_35 . V_95 & V_115 ) ) )
return;
if ( F_73 ( V_47 == - 1 || V_47 >= V_109 ) )
return;
V_23 -> V_35 . V_95 = 0 ;
V_30 -> V_71 [ V_47 ] = V_23 ;
V_30 -> V_69 ++ ;
F_70 ( V_47 , V_30 -> V_116 ) ;
F_74 ( & V_23 -> V_35 . V_61 , F_39 ( V_30 , V_23 ) ) ;
F_75 ( V_30 , V_23 ) ;
if ( V_30 -> V_69 == 1 ) {
F_76 ( V_30 ) ;
F_48 ( V_30 ) ;
}
}
static void F_77 ( struct V_26 * V_23 , int V_45 )
{
struct V_28 * V_30 = F_18 ( V_23 ) ;
struct V_55 * V_56 = & V_23 -> V_35 ;
if ( F_78 ( V_56 -> V_47 , V_30 -> V_116 ) ) {
F_79 ( V_30 , V_23 ) ;
V_30 -> V_69 -- ;
V_30 -> V_71 [ V_56 -> V_47 ] = NULL ;
F_73 ( V_56 -> V_95 & V_115 ) ;
V_56 -> V_95 |= V_115 ;
if ( V_30 -> V_69 == 0 ) {
F_80 ( V_30 ) ;
F_50 ( V_30 ) ;
}
}
if ( ( V_45 & V_117 ) && ! ( V_56 -> V_95 & V_118 ) ) {
F_35 ( V_30 , V_23 ) ;
V_56 -> V_95 |= V_118 ;
}
}
static int F_81 ( struct V_26 * V_23 , int V_45 )
{
struct V_28 * V_30 = F_18 ( V_23 ) ;
struct V_55 * V_56 = & V_23 -> V_35 ;
int V_107 [ V_109 ] ;
int V_11 , V_88 , V_112 ;
if ( ! V_30 )
return - V_119 ;
V_112 = V_88 = F_60 ( V_30 , V_23 , false ) ;
if ( V_112 < 0 )
return V_112 ;
V_56 -> V_95 = V_118 | V_115 ;
if ( ! ( V_45 & V_120 ) )
V_56 -> V_95 |= V_121 ;
V_112 = F_64 ( V_30 , V_107 , V_88 ) ;
if ( V_112 )
return V_112 ;
for ( V_11 = 0 ; V_11 < V_30 -> V_92 ; V_11 ++ ) {
V_23 = V_30 -> V_94 [ V_11 ] ;
V_56 = & V_23 -> V_35 ;
if ( V_56 -> V_47 == V_107 [ V_11 ] &&
V_56 -> V_57 == V_30 -> V_58 [ V_107 [ V_11 ] ] )
continue;
if ( V_56 -> V_95 & V_115 )
V_56 -> V_95 |= V_121 ;
F_77 ( V_23 , V_117 ) ;
}
for ( V_11 = 0 ; V_11 < V_88 ; V_11 ++ ) {
V_23 = V_30 -> V_94 [ V_11 ] ;
V_56 = & V_23 -> V_35 ;
if ( V_56 -> V_47 != V_107 [ V_11 ] ||
V_56 -> V_57 != V_30 -> V_58 [ V_107 [ V_11 ] ] )
F_30 ( V_30 , V_23 , V_107 [ V_11 ] ) ;
else if ( V_11 < V_30 -> V_92 )
continue;
if ( V_56 -> V_95 & V_121 )
continue;
F_72 ( V_23 , 0 ) ;
}
V_30 -> V_92 = V_88 ;
return 0 ;
}
static void F_82 ( struct V_26 * V_23 , int V_45 )
{
struct V_28 * V_30 = F_18 ( V_23 ) ;
int V_11 ;
F_77 ( V_23 , V_117 ) ;
for ( V_11 = 0 ; V_11 < V_30 -> V_92 ; V_11 ++ ) {
if ( V_23 == V_30 -> V_94 [ V_11 ] ) {
F_63 ( V_30 , V_23 ) ;
while ( ++ V_11 < V_30 -> V_92 )
V_30 -> V_94 [ V_11 - 1 ] = V_30 -> V_94 [ V_11 ] ;
-- V_30 -> V_92 ;
break;
}
}
V_23 -> V_35 . V_47 = - 1 ;
V_23 -> V_35 . V_57 = ~ 0ULL ;
}
void F_83 ( struct V_26 * V_23 )
{
struct V_28 * V_30 = F_18 ( V_23 ) ;
F_35 ( V_30 , V_23 ) ;
}
static int F_84 ( struct V_25 * V_27 ,
struct V_26 * V_23 )
{
struct V_26 * V_86 = V_23 -> V_122 ;
struct V_28 * V_123 ;
int V_112 = - V_93 , V_88 ;
V_123 = F_54 ( V_27 -> type , V_124 ) ;
if ( ! V_123 )
return - V_125 ;
V_123 -> V_27 = V_27 ;
V_88 = F_60 ( V_123 , V_86 , true ) ;
if ( V_88 < 0 )
goto V_32;
V_123 -> V_92 = V_88 ;
V_88 = F_60 ( V_123 , V_23 , false ) ;
if ( V_88 < 0 )
goto V_32;
V_123 -> V_92 = V_88 ;
V_112 = F_64 ( V_123 , NULL , V_88 ) ;
V_32:
F_10 ( V_123 ) ;
return V_112 ;
}
static int V_85 ( struct V_26 * V_23 )
{
struct V_25 * V_27 ;
struct V_28 * V_30 ;
struct V_55 * V_56 = & V_23 -> V_35 ;
int V_112 ;
if ( V_23 -> V_20 . type != V_23 -> V_27 -> type )
return - V_126 ;
V_27 = F_13 ( V_23 ) ;
if ( V_27 -> V_127 < 0 )
return - V_126 ;
if ( V_23 -> V_20 . V_128 || V_23 -> V_20 . V_129 ||
V_23 -> V_20 . V_130 || V_23 -> V_20 . V_131 )
return - V_93 ;
if ( V_56 -> V_132 )
return - V_93 ;
if ( V_23 -> V_29 < 0 )
return - V_93 ;
V_30 = F_14 ( V_27 , V_23 -> V_29 ) ;
if ( ! V_30 || V_30 -> V_29 < 0 )
return - V_93 ;
V_23 -> V_29 = V_30 -> V_29 ;
V_23 -> V_35 . V_47 = - 1 ;
V_23 -> V_35 . V_57 = ~ 0ULL ;
V_23 -> V_35 . V_42 . V_47 = V_48 ;
V_23 -> V_35 . V_44 . V_47 = V_48 ;
if ( V_23 -> V_20 . V_24 == V_100 ) {
if ( ! V_27 -> type -> V_91 )
return - V_93 ;
if ( V_27 -> type -> V_133 && V_27 -> V_134 > 0 )
return - V_93 ;
V_56 -> V_24 = 0ULL ;
} else {
V_56 -> V_24 = V_23 -> V_20 . V_24 & V_27 -> type -> V_135 ;
if ( V_27 -> type -> V_98 -> V_136 ) {
V_112 = V_27 -> type -> V_98 -> V_136 ( V_30 , V_23 ) ;
if ( V_112 )
return V_112 ;
}
}
if ( V_23 -> V_122 != V_23 )
V_112 = F_84 ( V_27 , V_23 ) ;
else
V_112 = 0 ;
return V_112 ;
}
static T_1 F_85 ( struct V_137 * V_138 ,
struct V_139 * V_20 , char * V_21 )
{
return F_86 ( true , V_21 , & V_140 ) ;
}
static int F_87 ( struct V_25 * V_27 )
{
int V_112 ;
if ( ! V_27 -> type -> V_27 ) {
V_27 -> V_27 = (struct V_27 ) {
. V_141 = V_27 -> type -> V_141 ,
. V_142 = V_143 ,
. V_84 = V_85 ,
. V_144 = F_81 ,
. V_145 = F_82 ,
. V_146 = F_72 ,
. V_147 = F_77 ,
. V_148 = F_83 ,
} ;
} else {
V_27 -> V_27 = * V_27 -> type -> V_27 ;
V_27 -> V_27 . V_141 = V_27 -> type -> V_141 ;
}
if ( V_27 -> type -> V_149 == 1 ) {
if ( strlen ( V_27 -> type -> V_150 ) > 0 )
sprintf ( V_27 -> V_150 , L_2 , V_27 -> type -> V_150 ) ;
else
sprintf ( V_27 -> V_150 , L_3 ) ;
} else {
sprintf ( V_27 -> V_150 , L_4 , V_27 -> type -> V_150 ,
V_27 -> V_134 ) ;
}
V_112 = F_88 ( & V_27 -> V_27 , V_27 -> V_150 , - 1 ) ;
return V_112 ;
}
static void T_3 F_89 ( struct V_78 * type )
{
int V_11 ;
for ( V_11 = 0 ; V_11 < type -> V_149 ; V_11 ++ )
F_90 ( type -> V_151 [ V_11 ] . V_30 ) ;
F_10 ( type -> V_151 ) ;
type -> V_151 = NULL ;
F_10 ( type -> V_152 ) ;
type -> V_152 = NULL ;
}
static void T_3 F_91 ( struct V_78 * * V_153 )
{
int V_11 ;
for ( V_11 = 0 ; V_153 [ V_11 ] ; V_11 ++ )
F_89 ( V_153 [ V_11 ] ) ;
}
static int T_3 F_92 ( struct V_78 * type )
{
struct V_25 * V_151 ;
struct V_154 * V_155 ;
struct V_156 * * V_157 ;
int V_11 , V_158 ;
V_151 = F_93 ( sizeof( * V_151 ) * type -> V_149 , V_14 ) ;
if ( ! V_151 )
return - V_125 ;
type -> V_151 = V_151 ;
type -> V_105 = (struct V_37 )
F_94 ( 0 , ( 1ULL << type -> V_90 ) - 1 ,
0 , type -> V_90 , 0 , 0 ) ;
for ( V_11 = 0 ; V_11 < type -> V_149 ; V_11 ++ ) {
V_151 [ V_11 ] . V_127 = - 1 ;
V_151 [ V_11 ] . V_134 = V_11 ;
V_151 [ V_11 ] . type = type ;
F_58 ( & V_151 [ V_11 ] . V_159 ) ;
V_151 [ V_11 ] . V_30 = F_95 ( struct V_28 * ) ;
if ( ! V_151 [ V_11 ] . V_30 )
goto V_160;
}
if ( type -> V_161 ) {
V_11 = 0 ;
while ( type -> V_161 [ V_11 ] . V_20 . V_20 . V_150 )
V_11 ++ ;
V_155 = F_93 ( sizeof( struct V_156 * ) * ( V_11 + 1 ) +
sizeof( * V_155 ) , V_14 ) ;
if ( ! V_155 )
goto V_160;
V_157 = (struct V_156 * * ) ( V_155 + 1 ) ;
V_155 -> V_150 = L_5 ;
V_155 -> V_157 = V_157 ;
for ( V_158 = 0 ; V_158 < V_11 ; V_158 ++ )
V_157 [ V_158 ] = & type -> V_161 [ V_158 ] . V_20 . V_20 ;
type -> V_152 = V_155 ;
}
type -> V_162 = & V_163 ;
return 0 ;
V_160:
F_89 ( type ) ;
return - V_125 ;
}
static int T_3 F_96 ( struct V_78 * * V_153 )
{
int V_11 , V_112 ;
for ( V_11 = 0 ; V_153 [ V_11 ] ; V_11 ++ ) {
V_112 = F_92 ( V_153 [ V_11 ] ) ;
if ( V_112 )
goto V_160;
}
return 0 ;
V_160:
while ( -- V_11 >= 0 )
F_89 ( V_153 [ V_11 ] ) ;
return V_112 ;
}
static int F_97 ( struct V_164 * V_165 , const struct V_166 * V_167 )
{
struct V_25 * V_27 ;
struct V_28 * V_30 ;
struct V_78 * type ;
int V_5 ;
bool V_168 = false ;
V_5 = F_1 ( V_165 -> V_2 ) ;
if ( V_5 < 0 )
return - V_119 ;
if ( F_98 ( V_167 -> V_169 ) == V_170 ) {
int V_47 = F_99 ( V_167 -> V_169 ) ;
V_171 [ V_5 ] [ V_47 ] = V_165 ;
F_100 ( V_165 , NULL ) ;
return 0 ;
}
type = V_172 [ F_98 ( V_167 -> V_169 ) ] ;
V_30 = F_54 ( type , V_124 ) ;
if ( ! V_30 )
return - V_125 ;
V_27 = & type -> V_151 [ F_99 ( V_167 -> V_169 ) ] ;
if ( V_173 . V_174 == 87 )
while ( V_27 -> V_127 >= 0 )
V_27 ++ ;
if ( V_27 -> V_127 < 0 )
V_27 -> V_127 = V_165 -> V_175 ;
else
F_73 ( V_27 -> V_127 != V_165 -> V_175 ) ;
V_30 -> V_5 = V_5 ;
V_30 -> V_164 = V_165 ;
V_30 -> V_27 = V_27 ;
F_101 ( V_30 ) ;
F_100 ( V_165 , V_30 ) ;
F_2 ( & V_31 ) ;
if ( F_102 ( & V_27 -> V_159 ) )
V_168 = true ;
F_9 ( & V_30 -> V_15 , & V_27 -> V_159 ) ;
F_5 ( & V_31 ) ;
if ( V_168 )
F_87 ( V_27 ) ;
return 0 ;
}
static void F_103 ( struct V_164 * V_165 )
{
struct V_28 * V_30 = F_104 ( V_165 ) ;
struct V_25 * V_27 ;
int V_11 , V_29 , V_5 ;
bool V_176 = false ;
V_5 = F_1 ( V_165 -> V_2 ) ;
V_30 = F_104 ( V_165 ) ;
if ( ! V_30 ) {
for ( V_11 = 0 ; V_11 < V_177 ; V_11 ++ ) {
if ( V_171 [ V_5 ] [ V_11 ] == V_165 ) {
V_171 [ V_5 ] [ V_11 ] = NULL ;
break;
}
}
F_73 ( V_11 >= V_177 ) ;
return;
}
V_27 = V_30 -> V_27 ;
if ( F_73 ( V_5 != V_30 -> V_5 ) )
return;
F_100 ( V_165 , NULL ) ;
F_2 ( & V_31 ) ;
F_105 ( & V_30 -> V_15 ) ;
if ( F_102 ( & V_27 -> V_159 ) )
V_176 = true ;
F_5 ( & V_31 ) ;
F_106 (cpu) {
if ( * F_15 ( V_27 -> V_30 , V_29 ) == V_30 ) {
* F_15 ( V_27 -> V_30 , V_29 ) = NULL ;
F_28 ( & V_30 -> V_33 ) ;
}
}
F_73 ( F_25 ( & V_30 -> V_33 ) != 1 ) ;
F_10 ( V_30 ) ;
if ( V_176 )
F_107 ( & V_27 -> V_27 ) ;
}
static int T_3 F_108 ( void )
{
int V_112 ;
switch ( V_173 . V_174 ) {
case 45 :
V_112 = F_109 () ;
break;
case 62 :
V_112 = F_110 () ;
break;
case 63 :
V_112 = F_111 () ;
break;
case 79 :
case 86 :
V_112 = F_112 () ;
break;
case 42 :
V_112 = F_113 () ;
break;
case 58 :
V_112 = F_114 () ;
break;
case 60 :
case 69 :
V_112 = F_115 () ;
break;
case 61 :
V_112 = F_116 () ;
break;
case 87 :
V_112 = F_117 () ;
break;
case 94 :
V_112 = F_118 () ;
break;
default:
return 0 ;
}
if ( V_112 )
return V_112 ;
V_112 = F_96 ( V_172 ) ;
if ( V_112 )
return V_112 ;
V_178 -> V_179 = F_97 ;
V_178 -> remove = F_103 ;
V_112 = F_119 ( V_178 ) ;
if ( V_112 == 0 )
V_180 = true ;
else
F_91 ( V_172 ) ;
return V_112 ;
}
static void T_3 F_120 ( void )
{
if ( V_180 ) {
V_180 = false ;
F_121 ( V_178 ) ;
F_91 ( V_172 ) ;
}
}
static void F_122 ( void )
{
struct V_28 * V_30 ;
while ( ! F_102 ( & V_181 ) ) {
V_30 = F_123 ( V_181 . V_182 ,
struct V_28 , V_15 ) ;
F_105 ( & V_30 -> V_15 ) ;
F_10 ( V_30 ) ;
}
}
static void F_124 ( int V_29 )
{
struct V_78 * type ;
struct V_25 * V_27 ;
struct V_28 * V_30 ;
int V_11 , V_158 ;
for ( V_11 = 0 ; V_183 [ V_11 ] ; V_11 ++ ) {
type = V_183 [ V_11 ] ;
for ( V_158 = 0 ; V_158 < type -> V_149 ; V_158 ++ ) {
V_27 = & type -> V_151 [ V_158 ] ;
V_30 = * F_15 ( V_27 -> V_30 , V_29 ) ;
* F_15 ( V_27 -> V_30 , V_29 ) = NULL ;
if ( V_30 && F_125 ( & V_30 -> V_33 ) )
F_126 ( & V_30 -> V_15 , & V_181 ) ;
}
}
}
static int F_127 ( int V_29 )
{
struct V_78 * type ;
struct V_25 * V_27 ;
struct V_28 * V_30 , * V_184 ;
int V_11 , V_158 , V_185 , V_5 ;
V_5 = F_16 ( V_29 ) ;
for ( V_11 = 0 ; V_183 [ V_11 ] ; V_11 ++ ) {
type = V_183 [ V_11 ] ;
for ( V_158 = 0 ; V_158 < type -> V_149 ; V_158 ++ ) {
V_27 = & type -> V_151 [ V_158 ] ;
V_30 = * F_15 ( V_27 -> V_30 , V_29 ) ;
if ( V_30 && V_30 -> V_5 >= 0 ) {
F_101 ( V_30 ) ;
continue;
}
F_128 (k) {
V_184 = * F_15 ( V_27 -> V_30 , V_185 ) ;
if ( V_184 && V_184 -> V_5 == V_5 ) {
F_17 ( & V_184 -> V_33 ) ;
* F_15 ( V_27 -> V_30 , V_29 ) = V_184 ;
if ( V_30 ) {
F_126 ( & V_30 -> V_15 ,
& V_181 ) ;
V_30 = NULL ;
}
break;
}
}
if ( V_30 ) {
V_30 -> V_5 = V_5 ;
F_101 ( V_30 ) ;
}
}
}
return 0 ;
}
static int F_129 ( int V_29 , int V_5 )
{
struct V_78 * type ;
struct V_25 * V_27 ;
struct V_28 * V_30 ;
int V_11 , V_158 ;
for ( V_11 = 0 ; V_183 [ V_11 ] ; V_11 ++ ) {
type = V_183 [ V_11 ] ;
for ( V_158 = 0 ; V_158 < type -> V_149 ; V_158 ++ ) {
V_27 = & type -> V_151 [ V_158 ] ;
if ( V_27 -> V_127 < 0 )
V_27 -> V_127 = V_158 ;
V_30 = F_54 ( type , F_130 ( V_29 ) ) ;
if ( ! V_30 )
return - V_125 ;
V_30 -> V_27 = V_27 ;
V_30 -> V_5 = V_5 ;
* F_15 ( V_27 -> V_30 , V_29 ) = V_30 ;
}
}
return 0 ;
}
static void
F_131 ( struct V_78 * * V_186 , int V_187 , int V_188 )
{
struct V_78 * type ;
struct V_25 * V_27 ;
struct V_28 * V_30 ;
int V_11 , V_158 ;
for ( V_11 = 0 ; V_186 [ V_11 ] ; V_11 ++ ) {
type = V_186 [ V_11 ] ;
for ( V_158 = 0 ; V_158 < type -> V_149 ; V_158 ++ ) {
V_27 = & type -> V_151 [ V_158 ] ;
if ( V_187 < 0 )
V_30 = F_14 ( V_27 , V_188 ) ;
else
V_30 = F_14 ( V_27 , V_187 ) ;
if ( ! V_30 )
continue;
if ( V_187 < 0 ) {
F_73 ( V_30 -> V_29 != - 1 ) ;
V_30 -> V_29 = V_188 ;
continue;
}
F_73 ( V_30 -> V_29 != V_187 ) ;
if ( V_188 >= 0 ) {
F_50 ( V_30 ) ;
F_132 ( & V_27 -> V_27 ,
V_187 , V_188 ) ;
V_30 -> V_29 = V_188 ;
} else {
V_30 -> V_29 = - 1 ;
}
}
}
}
static void F_133 ( int V_29 )
{
int V_11 , V_5 , V_189 ;
if ( ! F_134 ( V_29 , & V_140 ) )
return;
V_5 = F_16 ( V_29 ) ;
V_189 = - 1 ;
F_128 (i) {
if ( V_11 == V_29 )
continue;
if ( V_5 == F_16 ( V_11 ) ) {
V_189 = V_11 ;
break;
}
}
if ( V_189 >= 0 )
F_135 ( V_189 , & V_140 ) ;
F_131 ( V_183 , V_29 , V_189 ) ;
F_131 ( V_172 , V_29 , V_189 ) ;
}
static void F_136 ( int V_29 )
{
int V_11 , V_5 ;
V_5 = F_16 ( V_29 ) ;
F_137 (i, &uncore_cpu_mask) {
if ( V_5 == F_16 ( V_11 ) )
return;
}
F_135 ( V_29 , & V_140 ) ;
F_131 ( V_183 , - 1 , V_29 ) ;
F_131 ( V_172 , - 1 , V_29 ) ;
}
static int F_138 ( struct V_190 * V_191 ,
unsigned long V_192 , void * V_193 )
{
unsigned int V_29 = ( long ) V_193 ;
switch ( V_192 & ~ V_194 ) {
case V_195 :
F_129 ( V_29 , - 1 ) ;
break;
case V_196 :
F_127 ( V_29 ) ;
break;
case V_197 :
case V_198 :
F_124 ( V_29 ) ;
break;
case V_199 :
case V_200 :
F_122 () ;
break;
default:
break;
}
switch ( V_192 & ~ V_194 ) {
case V_201 :
case V_196 :
F_136 ( V_29 ) ;
break;
case V_202 :
F_133 ( V_29 ) ;
break;
default:
break;
}
return V_203 ;
}
static void T_3 F_139 ( void * V_204 )
{
F_127 ( F_19 () ) ;
}
static int T_3 F_140 ( void )
{
int V_112 ;
switch ( V_173 . V_174 ) {
case 26 :
case 30 :
case 37 :
case 44 :
F_141 () ;
break;
case 42 :
case 58 :
case 60 :
case 69 :
case 70 :
case 61 :
case 71 :
F_142 () ;
break;
case 45 :
F_143 () ;
break;
case 46 :
case 47 :
F_144 () ;
break;
case 62 :
F_145 () ;
break;
case 63 :
F_146 () ;
break;
case 79 :
case 86 :
F_147 () ;
break;
case 87 :
F_148 () ;
break;
default:
return 0 ;
}
V_112 = F_96 ( V_183 ) ;
if ( V_112 )
return V_112 ;
return 0 ;
}
static int T_3 F_149 ( void )
{
struct V_25 * V_27 ;
struct V_78 * type ;
int V_11 , V_158 ;
for ( V_11 = 0 ; V_183 [ V_11 ] ; V_11 ++ ) {
type = V_183 [ V_11 ] ;
for ( V_158 = 0 ; V_158 < type -> V_149 ; V_158 ++ ) {
V_27 = & type -> V_151 [ V_158 ] ;
F_87 ( V_27 ) ;
}
}
return 0 ;
}
static void T_3 F_150 ( void )
{
int V_29 ;
if ( ! F_151 ( & V_140 ) )
return;
F_152 () ;
F_128 (cpu) {
int V_11 , V_5 = F_16 ( V_29 ) ;
F_137 (i, &uncore_cpu_mask) {
if ( V_5 == F_16 ( V_11 ) ) {
V_5 = - 1 ;
break;
}
}
if ( V_5 < 0 )
continue;
F_129 ( V_29 , V_5 ) ;
F_136 ( V_29 ) ;
}
F_153 ( F_139 , NULL , 1 ) ;
F_154 ( & V_205 ) ;
F_155 () ;
}
static int T_3 F_156 ( void )
{
int V_112 ;
if ( V_173 . V_206 != V_207 )
return - V_119 ;
if ( V_208 )
return - V_119 ;
V_112 = F_108 () ;
if ( V_112 )
goto V_160;
V_112 = F_140 () ;
if ( V_112 ) {
F_120 () ;
goto V_160;
}
F_150 () ;
F_149 () ;
return 0 ;
V_160:
return V_112 ;
}
