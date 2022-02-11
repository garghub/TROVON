static int F_1 ( struct V_1 * V_2 )
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
static void F_6 ( void )
{
struct V_3 * V_4 , * V_10 ;
F_7 (map, tmp, &pci2phy_map_head, list) {
F_8 ( & V_4 -> V_11 ) ;
F_9 ( V_4 ) ;
}
}
struct V_3 * F_10 ( int V_7 )
{
struct V_3 * V_4 , * V_12 = NULL ;
int V_13 ;
F_11 ( & V_6 ) ;
V_14:
F_3 (map, &pci2phy_map_head, list) {
if ( V_4 -> V_7 == V_7 )
goto V_15;
}
if ( ! V_12 ) {
F_5 ( & V_6 ) ;
V_12 = F_12 ( sizeof( struct V_3 ) , V_16 ) ;
F_2 ( & V_6 ) ;
if ( ! V_12 )
return NULL ;
goto V_14;
}
V_4 = V_12 ;
V_12 = NULL ;
V_4 -> V_7 = V_7 ;
for ( V_13 = 0 ; V_13 < 256 ; V_13 ++ )
V_4 -> V_8 [ V_13 ] = - 1 ;
F_13 ( & V_4 -> V_11 , & V_17 ) ;
V_15:
F_9 ( V_12 ) ;
return V_4 ;
}
T_1 F_14 ( struct V_18 * V_19 ,
struct V_20 * V_21 , char * V_22 )
{
struct V_23 * V_24 =
F_15 ( V_21 , struct V_23 , V_21 ) ;
return sprintf ( V_22 , L_1 , V_24 -> V_25 ) ;
}
struct V_26 * F_16 ( struct V_27 * V_28 , int V_29 )
{
unsigned int V_30 = F_17 ( V_29 ) ;
return V_30 < V_31 ? V_28 -> V_32 [ V_30 ] : NULL ;
}
T_2 F_18 ( struct V_26 * V_33 , struct V_34 * V_24 )
{
T_2 V_35 ;
F_19 ( V_24 -> V_36 . V_37 , V_35 ) ;
return V_35 ;
}
struct V_38 *
F_20 ( struct V_26 * V_33 , struct V_34 * V_24 )
{
struct V_39 * V_40 ;
struct V_41 * V_42 = & V_24 -> V_36 . V_43 ;
struct V_41 * V_44 = & V_24 -> V_36 . V_45 ;
unsigned long V_46 ;
bool V_47 = false ;
if ( V_42 -> V_48 == V_49 ||
( ! F_21 ( V_33 ) && V_42 -> V_12 ) )
return NULL ;
V_40 = & V_33 -> V_50 [ V_42 -> V_48 ] ;
F_22 ( & V_40 -> V_51 , V_46 ) ;
if ( ! F_23 ( & V_40 -> V_52 ) ||
( V_40 -> V_53 == V_42 -> V_25 && V_40 -> V_54 == V_44 -> V_25 ) ) {
F_24 ( & V_40 -> V_52 ) ;
V_40 -> V_53 = V_42 -> V_25 ;
V_40 -> V_54 = V_44 -> V_25 ;
V_47 = true ;
}
F_25 ( & V_40 -> V_51 , V_46 ) ;
if ( V_47 ) {
if ( ! F_21 ( V_33 ) )
V_42 -> V_12 = 1 ;
return NULL ;
}
return & V_55 ;
}
void F_26 ( struct V_26 * V_33 , struct V_34 * V_24 )
{
struct V_39 * V_40 ;
struct V_41 * V_42 = & V_24 -> V_36 . V_43 ;
if ( F_21 ( V_33 ) || ! V_42 -> V_12 )
return;
V_40 = & V_33 -> V_50 [ V_42 -> V_48 ] ;
F_27 ( & V_40 -> V_52 ) ;
V_42 -> V_12 = 0 ;
}
T_2 F_28 ( struct V_26 * V_33 , int V_48 )
{
struct V_39 * V_40 ;
unsigned long V_46 ;
T_2 V_25 ;
V_40 = & V_33 -> V_50 [ V_48 ] ;
F_22 ( & V_40 -> V_51 , V_46 ) ;
V_25 = V_40 -> V_25 ;
F_25 ( & V_40 -> V_51 , V_46 ) ;
return V_25 ;
}
static void F_29 ( struct V_26 * V_33 ,
struct V_34 * V_24 , int V_48 )
{
struct V_56 * V_57 = & V_24 -> V_36 ;
V_57 -> V_48 = V_48 ;
V_57 -> V_58 = ++ V_33 -> V_59 [ V_48 ] ;
if ( V_57 -> V_48 == V_60 ) {
V_57 -> V_37 = F_30 ( V_33 ) ;
V_57 -> V_61 = F_31 ( V_33 ) ;
return;
}
V_57 -> V_61 = F_32 ( V_33 , V_57 -> V_48 ) ;
V_57 -> V_37 = F_33 ( V_33 , V_57 -> V_48 ) ;
}
void F_34 ( struct V_26 * V_33 , struct V_34 * V_24 )
{
T_2 V_62 , V_63 , V_64 ;
int V_65 ;
if ( V_24 -> V_36 . V_48 >= V_60 )
V_65 = 64 - F_35 ( V_33 ) ;
else
V_65 = 64 - F_36 ( V_33 ) ;
V_66:
V_62 = F_37 ( & V_24 -> V_36 . V_62 ) ;
V_63 = F_38 ( V_33 , V_24 ) ;
if ( F_39 ( & V_24 -> V_36 . V_62 , V_63 ) != V_62 )
goto V_66;
V_64 = ( V_63 << V_65 ) - ( V_62 << V_65 ) ;
V_64 >>= V_65 ;
F_40 ( V_64 , & V_24 -> V_35 ) ;
}
static enum V_67 F_41 ( struct V_68 * V_68 )
{
struct V_26 * V_33 ;
struct V_34 * V_24 ;
unsigned long V_46 ;
int V_69 ;
V_33 = F_15 ( V_68 , struct V_26 , V_68 ) ;
if ( ! V_33 -> V_70 || V_33 -> V_29 != F_42 () )
return V_71 ;
F_43 ( V_46 ) ;
F_3 (event, &box->active_list, active_entry) {
F_34 ( V_33 , V_24 ) ;
}
F_44 (bit, box->active_mask, UNCORE_PMC_IDX_MAX)
F_34 ( V_33 , V_33 -> V_72 [ V_69 ] ) ;
F_45 ( V_46 ) ;
F_46 ( V_68 , F_47 ( V_33 -> V_73 ) ) ;
return V_74 ;
}
void F_48 ( struct V_26 * V_33 )
{
F_49 ( & V_33 -> V_68 , F_47 ( V_33 -> V_73 ) ,
V_75 ) ;
}
void F_50 ( struct V_26 * V_33 )
{
F_51 ( & V_33 -> V_68 ) ;
}
static void F_52 ( struct V_26 * V_33 )
{
F_53 ( & V_33 -> V_68 , V_76 , V_77 ) ;
V_33 -> V_68 . V_78 = F_41 ;
}
static struct V_26 * F_54 ( struct V_79 * type ,
int V_80 )
{
int V_13 , V_81 , V_82 = type -> V_83 ;
struct V_26 * V_33 ;
V_81 = sizeof( * V_33 ) + V_82 * sizeof( struct V_39 ) ;
V_33 = F_55 ( V_81 , V_16 , V_80 ) ;
if ( ! V_33 )
return NULL ;
for ( V_13 = 0 ; V_13 < V_82 ; V_13 ++ )
F_56 ( & V_33 -> V_50 [ V_13 ] . V_51 ) ;
F_52 ( V_33 ) ;
V_33 -> V_29 = - 1 ;
V_33 -> V_84 = - 1 ;
V_33 -> V_30 = - 1 ;
V_33 -> V_73 = V_85 ;
F_57 ( & V_33 -> V_86 ) ;
return V_33 ;
}
static bool F_58 ( struct V_26 * V_33 , struct V_34 * V_24 )
{
return & V_33 -> V_28 -> V_28 == V_24 -> V_28 ;
}
static int
F_59 ( struct V_26 * V_33 , struct V_34 * V_87 ,
bool V_88 )
{
struct V_34 * V_24 ;
int V_89 , V_90 ;
V_90 = V_33 -> V_28 -> type -> V_91 ;
if ( V_33 -> V_28 -> type -> V_92 )
V_90 ++ ;
if ( V_33 -> V_93 >= V_90 )
return - V_94 ;
V_89 = V_33 -> V_93 ;
if ( F_58 ( V_33 , V_87 ) ) {
V_33 -> V_95 [ V_89 ] = V_87 ;
V_89 ++ ;
}
if ( ! V_88 )
return V_89 ;
F_3 (event, &leader->sibling_list, group_entry) {
if ( ! F_58 ( V_33 , V_24 ) ||
V_24 -> V_96 <= V_97 )
continue;
if ( V_89 >= V_90 )
return - V_94 ;
V_33 -> V_95 [ V_89 ] = V_24 ;
V_89 ++ ;
}
return V_89 ;
}
static struct V_38 *
F_60 ( struct V_26 * V_33 , struct V_34 * V_24 )
{
struct V_79 * type = V_33 -> V_28 -> type ;
struct V_38 * V_98 ;
if ( type -> V_99 -> V_100 ) {
V_98 = type -> V_99 -> V_100 ( V_33 , V_24 ) ;
if ( V_98 )
return V_98 ;
}
if ( V_24 -> V_21 . V_25 == V_101 )
return & V_102 ;
if ( type -> V_103 ) {
F_61 (c, type->constraints) {
if ( ( V_24 -> V_36 . V_25 & V_98 -> V_104 ) == V_98 -> V_105 )
return V_98 ;
}
}
return & type -> V_106 ;
}
static void F_62 ( struct V_26 * V_33 ,
struct V_34 * V_24 )
{
if ( V_33 -> V_28 -> type -> V_99 -> V_107 )
V_33 -> V_28 -> type -> V_99 -> V_107 ( V_33 , V_24 ) ;
}
static int F_63 ( struct V_26 * V_33 , int V_108 [] , int V_89 )
{
unsigned long V_109 [ F_64 ( V_110 ) ] ;
struct V_38 * V_98 ;
int V_13 , V_111 , V_112 , V_113 = 0 ;
struct V_56 * V_57 ;
F_65 ( V_109 , V_110 ) ;
for ( V_13 = 0 , V_111 = V_110 , V_112 = 0 ; V_13 < V_89 ; V_13 ++ ) {
V_98 = F_60 ( V_33 , V_33 -> V_95 [ V_13 ] ) ;
V_33 -> V_38 [ V_13 ] = V_98 ;
V_111 = F_66 ( V_111 , V_98 -> V_114 ) ;
V_112 = F_67 ( V_112 , V_98 -> V_114 ) ;
}
for ( V_13 = 0 ; V_13 < V_89 ; V_13 ++ ) {
V_57 = & V_33 -> V_95 [ V_13 ] -> V_36 ;
V_98 = V_33 -> V_38 [ V_13 ] ;
if ( V_57 -> V_48 == - 1 )
break;
if ( ! F_68 ( V_57 -> V_48 , V_98 -> V_115 ) )
break;
if ( F_68 ( V_57 -> V_48 , V_109 ) )
break;
F_69 ( V_57 -> V_48 , V_109 ) ;
if ( V_108 )
V_108 [ V_13 ] = V_57 -> V_48 ;
}
if ( V_13 != V_89 )
V_113 = F_70 ( V_33 -> V_38 , V_89 ,
V_111 , V_112 , V_89 , V_108 ) ;
if ( ! V_108 || V_113 ) {
for ( V_13 = 0 ; V_13 < V_89 ; V_13 ++ )
F_62 ( V_33 , V_33 -> V_95 [ V_13 ] ) ;
}
return V_113 ? - V_94 : 0 ;
}
static void F_71 ( struct V_34 * V_24 , int V_46 )
{
struct V_26 * V_33 = F_72 ( V_24 ) ;
int V_48 = V_24 -> V_36 . V_48 ;
if ( F_73 ( ! ( V_24 -> V_36 . V_96 & V_116 ) ) )
return;
if ( F_73 ( V_48 == - 1 || V_48 >= V_110 ) )
return;
V_24 -> V_36 . V_96 = 0 ;
V_33 -> V_72 [ V_48 ] = V_24 ;
V_33 -> V_70 ++ ;
F_69 ( V_48 , V_33 -> V_117 ) ;
F_74 ( & V_24 -> V_36 . V_62 , F_38 ( V_33 , V_24 ) ) ;
F_75 ( V_33 , V_24 ) ;
if ( V_33 -> V_70 == 1 ) {
F_76 ( V_33 ) ;
F_48 ( V_33 ) ;
}
}
static void F_77 ( struct V_34 * V_24 , int V_46 )
{
struct V_26 * V_33 = F_72 ( V_24 ) ;
struct V_56 * V_57 = & V_24 -> V_36 ;
if ( F_78 ( V_57 -> V_48 , V_33 -> V_117 ) ) {
F_79 ( V_33 , V_24 ) ;
V_33 -> V_70 -- ;
V_33 -> V_72 [ V_57 -> V_48 ] = NULL ;
F_73 ( V_57 -> V_96 & V_116 ) ;
V_57 -> V_96 |= V_116 ;
if ( V_33 -> V_70 == 0 ) {
F_80 ( V_33 ) ;
F_50 ( V_33 ) ;
}
}
if ( ( V_46 & V_118 ) && ! ( V_57 -> V_96 & V_119 ) ) {
F_34 ( V_33 , V_24 ) ;
V_57 -> V_96 |= V_119 ;
}
}
static int F_81 ( struct V_34 * V_24 , int V_46 )
{
struct V_26 * V_33 = F_72 ( V_24 ) ;
struct V_56 * V_57 = & V_24 -> V_36 ;
int V_108 [ V_110 ] ;
int V_13 , V_89 , V_113 ;
if ( ! V_33 )
return - V_120 ;
V_113 = V_89 = F_59 ( V_33 , V_24 , false ) ;
if ( V_113 < 0 )
return V_113 ;
V_57 -> V_96 = V_119 | V_116 ;
if ( ! ( V_46 & V_121 ) )
V_57 -> V_96 |= V_122 ;
V_113 = F_63 ( V_33 , V_108 , V_89 ) ;
if ( V_113 )
return V_113 ;
for ( V_13 = 0 ; V_13 < V_33 -> V_93 ; V_13 ++ ) {
V_24 = V_33 -> V_95 [ V_13 ] ;
V_57 = & V_24 -> V_36 ;
if ( V_57 -> V_48 == V_108 [ V_13 ] &&
V_57 -> V_58 == V_33 -> V_59 [ V_108 [ V_13 ] ] )
continue;
if ( V_57 -> V_96 & V_116 )
V_57 -> V_96 |= V_122 ;
F_77 ( V_24 , V_118 ) ;
}
for ( V_13 = 0 ; V_13 < V_89 ; V_13 ++ ) {
V_24 = V_33 -> V_95 [ V_13 ] ;
V_57 = & V_24 -> V_36 ;
if ( V_57 -> V_48 != V_108 [ V_13 ] ||
V_57 -> V_58 != V_33 -> V_59 [ V_108 [ V_13 ] ] )
F_29 ( V_33 , V_24 , V_108 [ V_13 ] ) ;
else if ( V_13 < V_33 -> V_93 )
continue;
if ( V_57 -> V_96 & V_122 )
continue;
F_71 ( V_24 , 0 ) ;
}
V_33 -> V_93 = V_89 ;
return 0 ;
}
static void F_82 ( struct V_34 * V_24 , int V_46 )
{
struct V_26 * V_33 = F_72 ( V_24 ) ;
int V_13 ;
F_77 ( V_24 , V_118 ) ;
for ( V_13 = 0 ; V_13 < V_33 -> V_93 ; V_13 ++ ) {
if ( V_24 == V_33 -> V_95 [ V_13 ] ) {
F_62 ( V_33 , V_24 ) ;
for ( ++ V_13 ; V_13 < V_33 -> V_93 ; V_13 ++ )
V_33 -> V_95 [ V_13 - 1 ] = V_33 -> V_95 [ V_13 ] ;
-- V_33 -> V_93 ;
break;
}
}
V_24 -> V_36 . V_48 = - 1 ;
V_24 -> V_36 . V_58 = ~ 0ULL ;
}
void F_83 ( struct V_34 * V_24 )
{
struct V_26 * V_33 = F_72 ( V_24 ) ;
F_34 ( V_33 , V_24 ) ;
}
static int F_84 ( struct V_27 * V_28 ,
struct V_34 * V_24 )
{
struct V_34 * V_87 = V_24 -> V_123 ;
struct V_26 * V_124 ;
int V_113 = - V_94 , V_89 ;
V_124 = F_54 ( V_28 -> type , V_125 ) ;
if ( ! V_124 )
return - V_126 ;
V_124 -> V_28 = V_28 ;
V_89 = F_59 ( V_124 , V_87 , true ) ;
if ( V_89 < 0 )
goto V_127;
V_124 -> V_93 = V_89 ;
V_89 = F_59 ( V_124 , V_24 , false ) ;
if ( V_89 < 0 )
goto V_127;
V_124 -> V_93 = V_89 ;
V_113 = F_63 ( V_124 , NULL , V_89 ) ;
V_127:
F_9 ( V_124 ) ;
return V_113 ;
}
static int F_85 ( struct V_34 * V_24 )
{
struct V_27 * V_28 ;
struct V_26 * V_33 ;
struct V_56 * V_57 = & V_24 -> V_36 ;
int V_113 ;
if ( V_24 -> V_21 . type != V_24 -> V_28 -> type )
return - V_128 ;
V_28 = F_86 ( V_24 ) ;
if ( V_28 -> V_129 < 0 )
return - V_128 ;
if ( V_24 -> V_21 . V_130 || V_24 -> V_21 . V_131 ||
V_24 -> V_21 . V_132 || V_24 -> V_21 . V_133 )
return - V_94 ;
if ( V_57 -> V_134 )
return - V_94 ;
if ( V_24 -> V_29 < 0 )
return - V_94 ;
V_33 = F_16 ( V_28 , V_24 -> V_29 ) ;
if ( ! V_33 || V_33 -> V_29 < 0 )
return - V_94 ;
V_24 -> V_29 = V_33 -> V_29 ;
V_24 -> V_135 = V_33 ;
V_24 -> V_136 |= V_137 ;
V_24 -> V_36 . V_48 = - 1 ;
V_24 -> V_36 . V_58 = ~ 0ULL ;
V_24 -> V_36 . V_43 . V_48 = V_49 ;
V_24 -> V_36 . V_45 . V_48 = V_49 ;
if ( V_24 -> V_21 . V_25 == V_101 ) {
if ( ! V_28 -> type -> V_92 )
return - V_94 ;
if ( V_28 -> type -> V_138 && V_28 -> V_139 > 0 )
return - V_94 ;
V_57 -> V_25 = 0ULL ;
} else {
V_57 -> V_25 = V_24 -> V_21 . V_25 &
( V_28 -> type -> V_140 | ( ( T_2 ) V_28 -> type -> V_141 << 32 ) ) ;
if ( V_28 -> type -> V_99 -> V_142 ) {
V_113 = V_28 -> type -> V_99 -> V_142 ( V_33 , V_24 ) ;
if ( V_113 )
return V_113 ;
}
}
if ( V_24 -> V_123 != V_24 )
V_113 = F_84 ( V_28 , V_24 ) ;
else
V_113 = 0 ;
return V_113 ;
}
static T_1 F_87 ( struct V_143 * V_144 ,
struct V_145 * V_21 , char * V_22 )
{
return F_88 ( true , V_22 , & V_146 ) ;
}
static int F_89 ( struct V_27 * V_28 )
{
int V_113 ;
if ( ! V_28 -> type -> V_28 ) {
V_28 -> V_28 = (struct V_28 ) {
. V_147 = V_28 -> type -> V_147 ,
. V_148 = V_149 ,
. V_150 = F_85 ,
. V_151 = F_81 ,
. V_152 = F_82 ,
. V_153 = F_71 ,
. V_154 = F_77 ,
. V_155 = F_83 ,
. V_156 = V_157 ,
} ;
} else {
V_28 -> V_28 = * V_28 -> type -> V_28 ;
V_28 -> V_28 . V_147 = V_28 -> type -> V_147 ;
}
if ( V_28 -> type -> V_158 == 1 ) {
if ( strlen ( V_28 -> type -> V_159 ) > 0 )
sprintf ( V_28 -> V_159 , L_2 , V_28 -> type -> V_159 ) ;
else
sprintf ( V_28 -> V_159 , L_3 ) ;
} else {
sprintf ( V_28 -> V_159 , L_4 , V_28 -> type -> V_159 ,
V_28 -> V_139 ) ;
}
V_113 = F_90 ( & V_28 -> V_28 , V_28 -> V_159 , - 1 ) ;
if ( ! V_113 )
V_28 -> V_160 = true ;
return V_113 ;
}
static void F_91 ( struct V_27 * V_28 )
{
if ( ! V_28 -> V_160 )
return;
F_92 ( & V_28 -> V_28 ) ;
V_28 -> V_160 = false ;
}
static void F_93 ( struct V_27 * V_28 )
{
int V_161 ;
for ( V_161 = 0 ; V_161 < V_31 ; V_161 ++ )
F_9 ( V_28 -> V_32 [ V_161 ] ) ;
F_9 ( V_28 -> V_32 ) ;
}
static void F_94 ( struct V_79 * type )
{
struct V_27 * V_28 = type -> V_162 ;
int V_13 ;
if ( V_28 ) {
for ( V_13 = 0 ; V_13 < type -> V_158 ; V_13 ++ , V_28 ++ ) {
F_91 ( V_28 ) ;
F_93 ( V_28 ) ;
}
F_9 ( type -> V_162 ) ;
type -> V_162 = NULL ;
}
F_9 ( type -> V_163 ) ;
type -> V_163 = NULL ;
}
static void F_95 ( struct V_79 * * V_164 )
{
for (; * V_164 ; V_164 ++ )
F_94 ( * V_164 ) ;
}
static int T_3 F_96 ( struct V_79 * type , bool V_165 )
{
struct V_27 * V_162 ;
struct V_166 * V_167 ;
struct V_168 * * V_169 ;
T_4 V_81 ;
int V_13 , V_170 ;
V_162 = F_97 ( sizeof( * V_162 ) * type -> V_158 , V_16 ) ;
if ( ! V_162 )
return - V_126 ;
V_81 = V_31 * sizeof( struct V_26 * ) ;
for ( V_13 = 0 ; V_13 < type -> V_158 ; V_13 ++ ) {
V_162 [ V_13 ] . V_129 = V_165 ? V_13 : - 1 ;
V_162 [ V_13 ] . V_139 = V_13 ;
V_162 [ V_13 ] . type = type ;
V_162 [ V_13 ] . V_32 = F_97 ( V_81 , V_16 ) ;
if ( ! V_162 [ V_13 ] . V_32 )
return - V_126 ;
}
type -> V_162 = V_162 ;
type -> V_106 = (struct V_38 )
F_98 ( 0 , ( 1ULL << type -> V_91 ) - 1 ,
0 , type -> V_91 , 0 , 0 ) ;
if ( type -> V_171 ) {
for ( V_13 = 0 ; type -> V_171 [ V_13 ] . V_21 . V_21 . V_159 ; V_13 ++ ) ;
V_167 = F_97 ( sizeof( struct V_168 * ) * ( V_13 + 1 ) +
sizeof( * V_167 ) , V_16 ) ;
if ( ! V_167 )
return - V_126 ;
V_169 = (struct V_168 * * ) ( V_167 + 1 ) ;
V_167 -> V_159 = L_5 ;
V_167 -> V_169 = V_169 ;
for ( V_170 = 0 ; V_170 < V_13 ; V_170 ++ )
V_169 [ V_170 ] = & type -> V_171 [ V_170 ] . V_21 . V_21 ;
type -> V_163 = V_167 ;
}
type -> V_172 = & V_173 ;
return 0 ;
}
static int T_3
F_99 ( struct V_79 * * V_164 , bool V_165 )
{
int V_113 ;
for (; * V_164 ; V_164 ++ ) {
V_113 = F_96 ( * V_164 , V_165 ) ;
if ( V_113 )
return V_113 ;
}
return 0 ;
}
static int F_100 ( struct V_174 * V_175 , const struct V_176 * V_177 )
{
struct V_79 * type ;
struct V_27 * V_28 = NULL ;
struct V_26 * V_33 ;
int V_5 , V_161 , V_113 ;
V_5 = F_1 ( V_175 -> V_2 ) ;
if ( V_5 < 0 )
return - V_120 ;
V_161 = F_101 ( V_5 ) ;
if ( V_161 < 0 )
return - V_94 ;
if ( F_102 ( V_177 -> V_178 ) == V_179 ) {
int V_48 = F_103 ( V_177 -> V_178 ) ;
V_180 [ V_161 ] . V_144 [ V_48 ] = V_175 ;
F_104 ( V_175 , NULL ) ;
return 0 ;
}
type = V_181 [ F_102 ( V_177 -> V_178 ) ] ;
if ( V_177 -> V_178 & ~ 0xffff ) {
struct V_182 * V_183 = V_175 -> V_184 ;
const struct V_176 * V_185 = V_183 -> V_186 ;
unsigned int V_187 ;
while ( V_185 && V_185 -> V_188 ) {
if ( ( V_185 -> V_188 == V_175 -> V_188 ) &&
( V_185 -> V_143 == V_175 -> V_143 ) ) {
V_187 = F_105 ( F_106 ( V_185 -> V_178 ) ,
F_107 ( V_185 -> V_178 ) ) ;
if ( V_187 == V_175 -> V_187 ) {
V_28 = & type -> V_162 [ F_103 ( V_185 -> V_178 ) ] ;
break;
}
}
V_185 ++ ;
}
if ( V_28 == NULL )
return - V_120 ;
} else {
V_28 = & type -> V_162 [ F_103 ( V_177 -> V_178 ) ] ;
}
if ( F_73 ( V_28 -> V_32 [ V_161 ] != NULL ) )
return - V_94 ;
V_33 = F_54 ( type , V_125 ) ;
if ( ! V_33 )
return - V_126 ;
if ( V_28 -> V_129 < 0 )
V_28 -> V_129 = V_175 -> V_187 ;
else
F_73 ( V_28 -> V_129 != V_175 -> V_187 ) ;
F_24 ( & V_33 -> V_189 ) ;
V_33 -> V_84 = V_5 ;
V_33 -> V_30 = V_161 ;
V_33 -> V_174 = V_175 ;
V_33 -> V_28 = V_28 ;
F_108 ( V_33 ) ;
F_104 ( V_175 , V_33 ) ;
V_28 -> V_32 [ V_161 ] = V_33 ;
if ( F_109 ( & V_28 -> V_190 ) > 1 )
return 0 ;
V_113 = F_89 ( V_28 ) ;
if ( V_113 ) {
F_104 ( V_175 , NULL ) ;
V_28 -> V_32 [ V_161 ] = NULL ;
F_110 ( V_33 ) ;
F_9 ( V_33 ) ;
}
return V_113 ;
}
static void F_111 ( struct V_174 * V_175 )
{
struct V_26 * V_33 ;
struct V_27 * V_28 ;
int V_13 , V_5 , V_161 ;
V_5 = F_1 ( V_175 -> V_2 ) ;
V_161 = F_101 ( V_5 ) ;
V_33 = F_112 ( V_175 ) ;
if ( ! V_33 ) {
for ( V_13 = 0 ; V_13 < V_191 ; V_13 ++ ) {
if ( V_180 [ V_161 ] . V_144 [ V_13 ] == V_175 ) {
V_180 [ V_161 ] . V_144 [ V_13 ] = NULL ;
break;
}
}
F_73 ( V_13 >= V_191 ) ;
return;
}
V_28 = V_33 -> V_28 ;
if ( F_73 ( V_5 != V_33 -> V_84 ) )
return;
F_104 ( V_175 , NULL ) ;
V_28 -> V_32 [ V_161 ] = NULL ;
if ( F_113 ( & V_28 -> V_190 ) == 0 )
F_91 ( V_28 ) ;
F_110 ( V_33 ) ;
F_9 ( V_33 ) ;
}
static int T_3 F_114 ( void )
{
T_4 V_81 ;
int V_113 ;
V_81 = V_31 * sizeof( struct V_192 ) ;
V_180 = F_97 ( V_81 , V_16 ) ;
if ( ! V_180 ) {
V_113 = - V_126 ;
goto V_193;
}
V_113 = F_99 ( V_181 , false ) ;
if ( V_113 )
goto V_194;
V_195 -> V_196 = F_100 ;
V_195 -> remove = F_111 ;
V_113 = F_115 ( V_195 ) ;
if ( V_113 )
goto V_194;
V_197 = true ;
return 0 ;
V_194:
F_95 ( V_181 ) ;
F_9 ( V_180 ) ;
V_180 = NULL ;
F_6 () ;
V_193:
V_181 = V_198 ;
return V_113 ;
}
static void F_116 ( void )
{
if ( V_197 ) {
V_197 = false ;
F_117 ( V_195 ) ;
F_95 ( V_181 ) ;
F_9 ( V_180 ) ;
F_6 () ;
}
}
static void F_118 ( struct V_79 * type , int V_199 ,
int V_200 )
{
struct V_27 * V_28 = type -> V_162 ;
struct V_26 * V_33 ;
int V_13 , V_161 ;
V_161 = F_17 ( V_199 < 0 ? V_200 : V_199 ) ;
for ( V_13 = 0 ; V_13 < type -> V_158 ; V_13 ++ , V_28 ++ ) {
V_33 = V_28 -> V_32 [ V_161 ] ;
if ( ! V_33 )
continue;
if ( V_199 < 0 ) {
F_73 ( V_33 -> V_29 != - 1 ) ;
V_33 -> V_29 = V_200 ;
continue;
}
F_73 ( V_33 -> V_29 != V_199 ) ;
V_33 -> V_29 = - 1 ;
if ( V_200 < 0 )
continue;
F_50 ( V_33 ) ;
F_119 ( & V_28 -> V_28 , V_199 , V_200 ) ;
V_33 -> V_29 = V_200 ;
}
}
static void F_120 ( struct V_79 * * V_201 ,
int V_199 , int V_200 )
{
for (; * V_201 ; V_201 ++ )
F_118 ( * V_201 , V_199 , V_200 ) ;
}
static int F_121 ( unsigned int V_29 )
{
struct V_79 * type , * * V_164 = V_202 ;
struct V_27 * V_28 ;
struct V_26 * V_33 ;
int V_13 , V_161 , V_203 ;
if ( ! F_122 ( V_29 , & V_146 ) )
goto V_204;
V_203 = F_123 ( F_124 ( V_29 ) , V_29 ) ;
if ( V_203 < V_205 )
F_125 ( V_203 , & V_146 ) ;
else
V_203 = - 1 ;
F_120 ( V_202 , V_29 , V_203 ) ;
F_120 ( V_181 , V_29 , V_203 ) ;
V_204:
V_161 = F_17 ( V_29 ) ;
for (; * V_164 ; V_164 ++ ) {
type = * V_164 ;
V_28 = type -> V_162 ;
for ( V_13 = 0 ; V_13 < type -> V_158 ; V_13 ++ , V_28 ++ ) {
V_33 = V_28 -> V_32 [ V_161 ] ;
if ( V_33 && F_113 ( & V_33 -> V_189 ) == 0 )
F_110 ( V_33 ) ;
}
}
return 0 ;
}
static int F_126 ( struct V_79 * * V_164 ,
unsigned int V_161 , unsigned int V_29 )
{
struct V_26 * V_33 , * V_10 ;
struct V_79 * type ;
struct V_27 * V_28 ;
F_127 ( V_206 ) ;
int V_13 ;
for (; * V_164 ; V_164 ++ ) {
type = * V_164 ;
V_28 = type -> V_162 ;
for ( V_13 = 0 ; V_13 < type -> V_158 ; V_13 ++ , V_28 ++ ) {
if ( V_28 -> V_32 [ V_161 ] )
continue;
V_33 = F_54 ( type , F_128 ( V_29 ) ) ;
if ( ! V_33 )
goto V_207;
V_33 -> V_28 = V_28 ;
V_33 -> V_30 = V_161 ;
F_129 ( & V_33 -> V_86 , & V_206 ) ;
}
}
F_7 (box, tmp, &allocated, active_list) {
F_130 ( & V_33 -> V_86 ) ;
V_33 -> V_28 -> V_32 [ V_161 ] = V_33 ;
}
return 0 ;
V_207:
F_7 (box, tmp, &allocated, active_list) {
F_130 ( & V_33 -> V_86 ) ;
F_9 ( V_33 ) ;
}
return - V_126 ;
}
static int F_131 ( unsigned int V_29 )
{
struct V_79 * type , * * V_164 = V_202 ;
struct V_27 * V_28 ;
struct V_26 * V_33 ;
int V_13 , V_113 , V_161 , V_203 ;
V_161 = F_17 ( V_29 ) ;
V_113 = F_126 ( V_164 , V_161 , V_29 ) ;
if ( V_113 )
return V_113 ;
for (; * V_164 ; V_164 ++ ) {
type = * V_164 ;
V_28 = type -> V_162 ;
for ( V_13 = 0 ; V_13 < type -> V_158 ; V_13 ++ , V_28 ++ ) {
V_33 = V_28 -> V_32 [ V_161 ] ;
if ( V_33 && F_109 ( & V_33 -> V_189 ) == 1 )
F_108 ( V_33 ) ;
}
}
V_203 = F_132 ( & V_146 , F_124 ( V_29 ) ) ;
if ( V_203 < V_205 )
return 0 ;
F_125 ( V_29 , & V_146 ) ;
F_120 ( V_202 , - 1 , V_29 ) ;
F_120 ( V_181 , - 1 , V_29 ) ;
return 0 ;
}
static int T_3 F_133 ( struct V_79 * type )
{
int V_13 , V_113 ;
for ( V_13 = 0 ; V_13 < type -> V_158 ; V_13 ++ ) {
V_113 = F_89 ( & type -> V_162 [ V_13 ] ) ;
if ( V_113 )
return V_113 ;
}
return 0 ;
}
static int T_3 F_134 ( void )
{
struct V_79 * * V_164 = V_202 ;
int V_113 ;
for (; * V_164 ; V_164 ++ ) {
V_113 = F_133 ( * V_164 ) ;
if ( V_113 )
return V_113 ;
}
return 0 ;
}
static int T_3 F_135 ( void )
{
int V_113 ;
V_113 = F_99 ( V_202 , true ) ;
if ( V_113 )
goto V_193;
V_113 = F_134 () ;
if ( V_113 )
goto V_193;
return 0 ;
V_193:
F_95 ( V_202 ) ;
V_202 = V_198 ;
return V_113 ;
}
static int T_3 F_136 ( void )
{
const struct V_208 * V_177 ;
struct V_209 * V_210 ;
int V_211 = 0 , V_212 = 0 , V_113 ;
V_177 = F_137 ( V_213 ) ;
if ( ! V_177 )
return - V_120 ;
if ( F_138 ( V_214 ) )
return - V_120 ;
V_31 = F_139 () ;
V_210 = (struct V_209 * ) V_177 -> V_178 ;
if ( V_210 -> V_215 ) {
V_211 = V_210 -> V_215 () ;
if ( ! V_211 )
V_211 = F_114 () ;
}
if ( V_210 -> V_216 ) {
V_210 -> V_216 () ;
V_212 = F_135 () ;
}
if ( V_212 && V_211 )
return - V_120 ;
V_113 = F_140 ( V_217 ,
L_6 ,
F_131 ,
F_121 ) ;
if ( V_113 )
goto V_193;
return 0 ;
V_193:
F_95 ( V_202 ) ;
F_116 () ;
return V_113 ;
}
static void T_5 F_141 ( void )
{
F_142 ( V_217 ) ;
F_95 ( V_202 ) ;
F_116 () ;
}
