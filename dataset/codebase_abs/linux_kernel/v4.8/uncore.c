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
return V_28 -> V_30 [ F_17 ( V_29 ) ] ;
}
T_2 F_18 ( struct V_26 * V_31 , struct V_32 * V_24 )
{
T_2 V_33 ;
F_19 ( V_24 -> V_34 . V_35 , V_33 ) ;
return V_33 ;
}
struct V_36 *
F_20 ( struct V_26 * V_31 , struct V_32 * V_24 )
{
struct V_37 * V_38 ;
struct V_39 * V_40 = & V_24 -> V_34 . V_41 ;
struct V_39 * V_42 = & V_24 -> V_34 . V_43 ;
unsigned long V_44 ;
bool V_45 = false ;
if ( V_40 -> V_46 == V_47 ||
( ! F_21 ( V_31 ) && V_40 -> V_12 ) )
return NULL ;
V_38 = & V_31 -> V_48 [ V_40 -> V_46 ] ;
F_22 ( & V_38 -> V_49 , V_44 ) ;
if ( ! F_23 ( & V_38 -> V_50 ) ||
( V_38 -> V_51 == V_40 -> V_25 && V_38 -> V_52 == V_42 -> V_25 ) ) {
F_24 ( & V_38 -> V_50 ) ;
V_38 -> V_51 = V_40 -> V_25 ;
V_38 -> V_52 = V_42 -> V_25 ;
V_45 = true ;
}
F_25 ( & V_38 -> V_49 , V_44 ) ;
if ( V_45 ) {
if ( ! F_21 ( V_31 ) )
V_40 -> V_12 = 1 ;
return NULL ;
}
return & V_53 ;
}
void F_26 ( struct V_26 * V_31 , struct V_32 * V_24 )
{
struct V_37 * V_38 ;
struct V_39 * V_40 = & V_24 -> V_34 . V_41 ;
if ( F_21 ( V_31 ) || ! V_40 -> V_12 )
return;
V_38 = & V_31 -> V_48 [ V_40 -> V_46 ] ;
F_27 ( & V_38 -> V_50 ) ;
V_40 -> V_12 = 0 ;
}
T_2 F_28 ( struct V_26 * V_31 , int V_46 )
{
struct V_37 * V_38 ;
unsigned long V_44 ;
T_2 V_25 ;
V_38 = & V_31 -> V_48 [ V_46 ] ;
F_22 ( & V_38 -> V_49 , V_44 ) ;
V_25 = V_38 -> V_25 ;
F_25 ( & V_38 -> V_49 , V_44 ) ;
return V_25 ;
}
static void F_29 ( struct V_26 * V_31 ,
struct V_32 * V_24 , int V_46 )
{
struct V_54 * V_55 = & V_24 -> V_34 ;
V_55 -> V_46 = V_46 ;
V_55 -> V_56 = ++ V_31 -> V_57 [ V_46 ] ;
if ( V_55 -> V_46 == V_58 ) {
V_55 -> V_35 = F_30 ( V_31 ) ;
V_55 -> V_59 = F_31 ( V_31 ) ;
return;
}
V_55 -> V_59 = F_32 ( V_31 , V_55 -> V_46 ) ;
V_55 -> V_35 = F_33 ( V_31 , V_55 -> V_46 ) ;
}
void F_34 ( struct V_26 * V_31 , struct V_32 * V_24 )
{
T_2 V_60 , V_61 , V_62 ;
int V_63 ;
if ( V_24 -> V_34 . V_46 >= V_58 )
V_63 = 64 - F_35 ( V_31 ) ;
else
V_63 = 64 - F_36 ( V_31 ) ;
V_64:
V_60 = F_37 ( & V_24 -> V_34 . V_60 ) ;
V_61 = F_38 ( V_31 , V_24 ) ;
if ( F_39 ( & V_24 -> V_34 . V_60 , V_61 ) != V_60 )
goto V_64;
V_62 = ( V_61 << V_63 ) - ( V_60 << V_63 ) ;
V_62 >>= V_63 ;
F_40 ( V_62 , & V_24 -> V_33 ) ;
}
static enum V_65 F_41 ( struct V_66 * V_66 )
{
struct V_26 * V_31 ;
struct V_32 * V_24 ;
unsigned long V_44 ;
int V_67 ;
V_31 = F_15 ( V_66 , struct V_26 , V_66 ) ;
if ( ! V_31 -> V_68 || V_31 -> V_29 != F_42 () )
return V_69 ;
F_43 ( V_44 ) ;
F_3 (event, &box->active_list, active_entry) {
F_34 ( V_31 , V_24 ) ;
}
F_44 (bit, box->active_mask, UNCORE_PMC_IDX_MAX)
F_34 ( V_31 , V_31 -> V_70 [ V_67 ] ) ;
F_45 ( V_44 ) ;
F_46 ( V_66 , F_47 ( V_31 -> V_71 ) ) ;
return V_72 ;
}
void F_48 ( struct V_26 * V_31 )
{
F_49 ( & V_31 -> V_66 , F_47 ( V_31 -> V_71 ) ,
V_73 ) ;
}
void F_50 ( struct V_26 * V_31 )
{
F_51 ( & V_31 -> V_66 ) ;
}
static void F_52 ( struct V_26 * V_31 )
{
F_53 ( & V_31 -> V_66 , V_74 , V_75 ) ;
V_31 -> V_66 . V_76 = F_41 ;
}
static struct V_26 * F_54 ( struct V_77 * type ,
int V_78 )
{
int V_13 , V_79 , V_80 = type -> V_81 ;
struct V_26 * V_31 ;
V_79 = sizeof( * V_31 ) + V_80 * sizeof( struct V_37 ) ;
V_31 = F_55 ( V_79 , V_16 , V_78 ) ;
if ( ! V_31 )
return NULL ;
for ( V_13 = 0 ; V_13 < V_80 ; V_13 ++ )
F_56 ( & V_31 -> V_48 [ V_13 ] . V_49 ) ;
F_52 ( V_31 ) ;
V_31 -> V_29 = - 1 ;
V_31 -> V_82 = - 1 ;
V_31 -> V_83 = - 1 ;
V_31 -> V_71 = V_84 ;
F_57 ( & V_31 -> V_85 ) ;
return V_31 ;
}
static bool F_58 ( struct V_32 * V_24 )
{
return V_24 -> V_28 -> V_86 == V_87 ;
}
static int
F_59 ( struct V_26 * V_31 , struct V_32 * V_88 ,
bool V_89 )
{
struct V_32 * V_24 ;
int V_90 , V_91 ;
V_91 = V_31 -> V_28 -> type -> V_92 ;
if ( V_31 -> V_28 -> type -> V_93 )
V_91 ++ ;
if ( V_31 -> V_94 >= V_91 )
return - V_95 ;
V_90 = V_31 -> V_94 ;
if ( F_58 ( V_88 ) ) {
V_31 -> V_96 [ V_90 ] = V_88 ;
V_90 ++ ;
}
if ( ! V_89 )
return V_90 ;
F_3 (event, &leader->sibling_list, group_entry) {
if ( ! F_58 ( V_24 ) ||
V_24 -> V_97 <= V_98 )
continue;
if ( V_90 >= V_91 )
return - V_95 ;
V_31 -> V_96 [ V_90 ] = V_24 ;
V_90 ++ ;
}
return V_90 ;
}
static struct V_36 *
F_60 ( struct V_26 * V_31 , struct V_32 * V_24 )
{
struct V_77 * type = V_31 -> V_28 -> type ;
struct V_36 * V_99 ;
if ( type -> V_100 -> V_101 ) {
V_99 = type -> V_100 -> V_101 ( V_31 , V_24 ) ;
if ( V_99 )
return V_99 ;
}
if ( V_24 -> V_21 . V_25 == V_102 )
return & V_103 ;
if ( type -> V_104 ) {
F_61 (c, type->constraints) {
if ( ( V_24 -> V_34 . V_25 & V_99 -> V_105 ) == V_99 -> V_106 )
return V_99 ;
}
}
return & type -> V_107 ;
}
static void F_62 ( struct V_26 * V_31 ,
struct V_32 * V_24 )
{
if ( V_31 -> V_28 -> type -> V_100 -> V_108 )
V_31 -> V_28 -> type -> V_100 -> V_108 ( V_31 , V_24 ) ;
}
static int F_63 ( struct V_26 * V_31 , int V_109 [] , int V_90 )
{
unsigned long V_110 [ F_64 ( V_111 ) ] ;
struct V_36 * V_99 ;
int V_13 , V_112 , V_113 , V_114 = 0 ;
struct V_54 * V_55 ;
F_65 ( V_110 , V_111 ) ;
for ( V_13 = 0 , V_112 = V_111 , V_113 = 0 ; V_13 < V_90 ; V_13 ++ ) {
V_99 = F_60 ( V_31 , V_31 -> V_96 [ V_13 ] ) ;
V_31 -> V_36 [ V_13 ] = V_99 ;
V_112 = F_66 ( V_112 , V_99 -> V_115 ) ;
V_113 = F_67 ( V_113 , V_99 -> V_115 ) ;
}
for ( V_13 = 0 ; V_13 < V_90 ; V_13 ++ ) {
V_55 = & V_31 -> V_96 [ V_13 ] -> V_34 ;
V_99 = V_31 -> V_36 [ V_13 ] ;
if ( V_55 -> V_46 == - 1 )
break;
if ( ! F_68 ( V_55 -> V_46 , V_99 -> V_116 ) )
break;
if ( F_68 ( V_55 -> V_46 , V_110 ) )
break;
F_69 ( V_55 -> V_46 , V_110 ) ;
if ( V_109 )
V_109 [ V_13 ] = V_55 -> V_46 ;
}
if ( V_13 != V_90 )
V_114 = F_70 ( V_31 -> V_36 , V_90 ,
V_112 , V_113 , V_90 , V_109 ) ;
if ( ! V_109 || V_114 ) {
for ( V_13 = 0 ; V_13 < V_90 ; V_13 ++ )
F_62 ( V_31 , V_31 -> V_96 [ V_13 ] ) ;
}
return V_114 ? - V_95 : 0 ;
}
static void F_71 ( struct V_32 * V_24 , int V_44 )
{
struct V_26 * V_31 = F_72 ( V_24 ) ;
int V_46 = V_24 -> V_34 . V_46 ;
if ( F_73 ( ! ( V_24 -> V_34 . V_97 & V_117 ) ) )
return;
if ( F_73 ( V_46 == - 1 || V_46 >= V_111 ) )
return;
V_24 -> V_34 . V_97 = 0 ;
V_31 -> V_70 [ V_46 ] = V_24 ;
V_31 -> V_68 ++ ;
F_69 ( V_46 , V_31 -> V_118 ) ;
F_74 ( & V_24 -> V_34 . V_60 , F_38 ( V_31 , V_24 ) ) ;
F_75 ( V_31 , V_24 ) ;
if ( V_31 -> V_68 == 1 ) {
F_76 ( V_31 ) ;
F_48 ( V_31 ) ;
}
}
static void F_77 ( struct V_32 * V_24 , int V_44 )
{
struct V_26 * V_31 = F_72 ( V_24 ) ;
struct V_54 * V_55 = & V_24 -> V_34 ;
if ( F_78 ( V_55 -> V_46 , V_31 -> V_118 ) ) {
F_79 ( V_31 , V_24 ) ;
V_31 -> V_68 -- ;
V_31 -> V_70 [ V_55 -> V_46 ] = NULL ;
F_73 ( V_55 -> V_97 & V_117 ) ;
V_55 -> V_97 |= V_117 ;
if ( V_31 -> V_68 == 0 ) {
F_80 ( V_31 ) ;
F_50 ( V_31 ) ;
}
}
if ( ( V_44 & V_119 ) && ! ( V_55 -> V_97 & V_120 ) ) {
F_34 ( V_31 , V_24 ) ;
V_55 -> V_97 |= V_120 ;
}
}
static int F_81 ( struct V_32 * V_24 , int V_44 )
{
struct V_26 * V_31 = F_72 ( V_24 ) ;
struct V_54 * V_55 = & V_24 -> V_34 ;
int V_109 [ V_111 ] ;
int V_13 , V_90 , V_114 ;
if ( ! V_31 )
return - V_121 ;
V_114 = V_90 = F_59 ( V_31 , V_24 , false ) ;
if ( V_114 < 0 )
return V_114 ;
V_55 -> V_97 = V_120 | V_117 ;
if ( ! ( V_44 & V_122 ) )
V_55 -> V_97 |= V_123 ;
V_114 = F_63 ( V_31 , V_109 , V_90 ) ;
if ( V_114 )
return V_114 ;
for ( V_13 = 0 ; V_13 < V_31 -> V_94 ; V_13 ++ ) {
V_24 = V_31 -> V_96 [ V_13 ] ;
V_55 = & V_24 -> V_34 ;
if ( V_55 -> V_46 == V_109 [ V_13 ] &&
V_55 -> V_56 == V_31 -> V_57 [ V_109 [ V_13 ] ] )
continue;
if ( V_55 -> V_97 & V_117 )
V_55 -> V_97 |= V_123 ;
F_77 ( V_24 , V_119 ) ;
}
for ( V_13 = 0 ; V_13 < V_90 ; V_13 ++ ) {
V_24 = V_31 -> V_96 [ V_13 ] ;
V_55 = & V_24 -> V_34 ;
if ( V_55 -> V_46 != V_109 [ V_13 ] ||
V_55 -> V_56 != V_31 -> V_57 [ V_109 [ V_13 ] ] )
F_29 ( V_31 , V_24 , V_109 [ V_13 ] ) ;
else if ( V_13 < V_31 -> V_94 )
continue;
if ( V_55 -> V_97 & V_123 )
continue;
F_71 ( V_24 , 0 ) ;
}
V_31 -> V_94 = V_90 ;
return 0 ;
}
static void F_82 ( struct V_32 * V_24 , int V_44 )
{
struct V_26 * V_31 = F_72 ( V_24 ) ;
int V_13 ;
F_77 ( V_24 , V_119 ) ;
for ( V_13 = 0 ; V_13 < V_31 -> V_94 ; V_13 ++ ) {
if ( V_24 == V_31 -> V_96 [ V_13 ] ) {
F_62 ( V_31 , V_24 ) ;
for ( ++ V_13 ; V_13 < V_31 -> V_94 ; V_13 ++ )
V_31 -> V_96 [ V_13 - 1 ] = V_31 -> V_96 [ V_13 ] ;
-- V_31 -> V_94 ;
break;
}
}
V_24 -> V_34 . V_46 = - 1 ;
V_24 -> V_34 . V_56 = ~ 0ULL ;
}
void F_83 ( struct V_32 * V_24 )
{
struct V_26 * V_31 = F_72 ( V_24 ) ;
F_34 ( V_31 , V_24 ) ;
}
static int F_84 ( struct V_27 * V_28 ,
struct V_32 * V_24 )
{
struct V_32 * V_88 = V_24 -> V_124 ;
struct V_26 * V_125 ;
int V_114 = - V_95 , V_90 ;
V_125 = F_54 ( V_28 -> type , V_126 ) ;
if ( ! V_125 )
return - V_127 ;
V_125 -> V_28 = V_28 ;
V_90 = F_59 ( V_125 , V_88 , true ) ;
if ( V_90 < 0 )
goto V_128;
V_125 -> V_94 = V_90 ;
V_90 = F_59 ( V_125 , V_24 , false ) ;
if ( V_90 < 0 )
goto V_128;
V_125 -> V_94 = V_90 ;
V_114 = F_63 ( V_125 , NULL , V_90 ) ;
V_128:
F_9 ( V_125 ) ;
return V_114 ;
}
static int V_87 ( struct V_32 * V_24 )
{
struct V_27 * V_28 ;
struct V_26 * V_31 ;
struct V_54 * V_55 = & V_24 -> V_34 ;
int V_114 ;
if ( V_24 -> V_21 . type != V_24 -> V_28 -> type )
return - V_129 ;
V_28 = F_85 ( V_24 ) ;
if ( V_28 -> V_130 < 0 )
return - V_129 ;
if ( V_24 -> V_21 . V_131 || V_24 -> V_21 . V_132 ||
V_24 -> V_21 . V_133 || V_24 -> V_21 . V_134 )
return - V_95 ;
if ( V_55 -> V_135 )
return - V_95 ;
if ( V_24 -> V_29 < 0 )
return - V_95 ;
V_31 = F_16 ( V_28 , V_24 -> V_29 ) ;
if ( ! V_31 || V_31 -> V_29 < 0 )
return - V_95 ;
V_24 -> V_29 = V_31 -> V_29 ;
V_24 -> V_136 = V_31 ;
V_24 -> V_34 . V_46 = - 1 ;
V_24 -> V_34 . V_56 = ~ 0ULL ;
V_24 -> V_34 . V_41 . V_46 = V_47 ;
V_24 -> V_34 . V_43 . V_46 = V_47 ;
if ( V_24 -> V_21 . V_25 == V_102 ) {
if ( ! V_28 -> type -> V_93 )
return - V_95 ;
if ( V_28 -> type -> V_137 && V_28 -> V_138 > 0 )
return - V_95 ;
V_55 -> V_25 = 0ULL ;
} else {
V_55 -> V_25 = V_24 -> V_21 . V_25 & V_28 -> type -> V_139 ;
if ( V_28 -> type -> V_100 -> V_140 ) {
V_114 = V_28 -> type -> V_100 -> V_140 ( V_31 , V_24 ) ;
if ( V_114 )
return V_114 ;
}
}
if ( V_24 -> V_124 != V_24 )
V_114 = F_84 ( V_28 , V_24 ) ;
else
V_114 = 0 ;
return V_114 ;
}
static T_1 F_86 ( struct V_141 * V_142 ,
struct V_143 * V_21 , char * V_22 )
{
return F_87 ( true , V_22 , & V_144 ) ;
}
static int F_88 ( struct V_27 * V_28 )
{
int V_114 ;
if ( ! V_28 -> type -> V_28 ) {
V_28 -> V_28 = (struct V_28 ) {
. V_145 = V_28 -> type -> V_145 ,
. V_146 = V_147 ,
. V_86 = V_87 ,
. V_148 = F_81 ,
. V_149 = F_82 ,
. V_150 = F_71 ,
. V_151 = F_77 ,
. V_152 = F_83 ,
} ;
} else {
V_28 -> V_28 = * V_28 -> type -> V_28 ;
V_28 -> V_28 . V_145 = V_28 -> type -> V_145 ;
}
if ( V_28 -> type -> V_153 == 1 ) {
if ( strlen ( V_28 -> type -> V_154 ) > 0 )
sprintf ( V_28 -> V_154 , L_2 , V_28 -> type -> V_154 ) ;
else
sprintf ( V_28 -> V_154 , L_3 ) ;
} else {
sprintf ( V_28 -> V_154 , L_4 , V_28 -> type -> V_154 ,
V_28 -> V_138 ) ;
}
V_114 = F_89 ( & V_28 -> V_28 , V_28 -> V_154 , - 1 ) ;
if ( ! V_114 )
V_28 -> V_155 = true ;
return V_114 ;
}
static void F_90 ( struct V_27 * V_28 )
{
if ( ! V_28 -> V_155 )
return;
F_91 ( & V_28 -> V_28 ) ;
V_28 -> V_155 = false ;
}
static void F_92 ( struct V_77 * type , int V_29 )
{
struct V_27 * V_28 = type -> V_156 ;
struct V_26 * V_31 ;
int V_13 , V_157 ;
if ( V_28 ) {
V_157 = F_93 ( V_29 ) ;
for ( V_13 = 0 ; V_13 < type -> V_153 ; V_13 ++ , V_28 ++ ) {
V_31 = V_28 -> V_30 [ V_157 ] ;
if ( V_31 )
F_94 ( V_31 ) ;
}
}
}
static void F_95 ( void * V_158 )
{
struct V_77 * * V_159 ;
for ( V_159 = V_160 ; * V_159 ; V_159 ++ )
F_92 ( * V_159 ++ , F_42 () ) ;
}
static void F_96 ( struct V_27 * V_28 )
{
int V_157 ;
for ( V_157 = 0 ; V_157 < V_161 ; V_157 ++ )
F_9 ( V_28 -> V_30 [ V_157 ] ) ;
F_9 ( V_28 -> V_30 ) ;
}
static void F_97 ( struct V_77 * type )
{
struct V_27 * V_28 = type -> V_156 ;
int V_13 ;
if ( V_28 ) {
for ( V_13 = 0 ; V_13 < type -> V_153 ; V_13 ++ , V_28 ++ ) {
F_90 ( V_28 ) ;
F_96 ( V_28 ) ;
}
F_9 ( type -> V_156 ) ;
type -> V_156 = NULL ;
}
F_9 ( type -> V_162 ) ;
type -> V_162 = NULL ;
}
static void F_98 ( struct V_77 * * V_159 )
{
for (; * V_159 ; V_159 ++ )
F_97 ( * V_159 ) ;
}
static int T_3 F_99 ( struct V_77 * type , bool V_163 )
{
struct V_27 * V_156 ;
struct V_164 * V_165 ;
struct V_166 * * V_167 ;
T_4 V_79 ;
int V_13 , V_168 ;
V_156 = F_100 ( sizeof( * V_156 ) * type -> V_153 , V_16 ) ;
if ( ! V_156 )
return - V_127 ;
V_79 = V_161 * sizeof( struct V_26 * ) ;
for ( V_13 = 0 ; V_13 < type -> V_153 ; V_13 ++ ) {
V_156 [ V_13 ] . V_130 = V_163 ? V_13 : - 1 ;
V_156 [ V_13 ] . V_138 = V_13 ;
V_156 [ V_13 ] . type = type ;
V_156 [ V_13 ] . V_30 = F_100 ( V_79 , V_16 ) ;
if ( ! V_156 [ V_13 ] . V_30 )
return - V_127 ;
}
type -> V_156 = V_156 ;
type -> V_107 = (struct V_36 )
F_101 ( 0 , ( 1ULL << type -> V_92 ) - 1 ,
0 , type -> V_92 , 0 , 0 ) ;
if ( type -> V_169 ) {
for ( V_13 = 0 ; type -> V_169 [ V_13 ] . V_21 . V_21 . V_154 ; V_13 ++ ) ;
V_165 = F_100 ( sizeof( struct V_166 * ) * ( V_13 + 1 ) +
sizeof( * V_165 ) , V_16 ) ;
if ( ! V_165 )
return - V_127 ;
V_167 = (struct V_166 * * ) ( V_165 + 1 ) ;
V_165 -> V_154 = L_5 ;
V_165 -> V_167 = V_167 ;
for ( V_168 = 0 ; V_168 < V_13 ; V_168 ++ )
V_167 [ V_168 ] = & type -> V_169 [ V_168 ] . V_21 . V_21 ;
type -> V_162 = V_165 ;
}
type -> V_170 = & V_171 ;
return 0 ;
}
static int T_3
F_102 ( struct V_77 * * V_159 , bool V_163 )
{
int V_114 ;
for (; * V_159 ; V_159 ++ ) {
V_114 = F_99 ( * V_159 , V_163 ) ;
if ( V_114 )
return V_114 ;
}
return 0 ;
}
static int F_103 ( struct V_172 * V_173 , const struct V_174 * V_175 )
{
struct V_77 * type ;
struct V_27 * V_28 = NULL ;
struct V_26 * V_31 ;
int V_5 , V_157 , V_114 ;
V_5 = F_1 ( V_173 -> V_2 ) ;
if ( V_5 < 0 )
return - V_121 ;
V_157 = F_104 ( V_5 ) ;
if ( V_157 < 0 )
return - V_95 ;
if ( F_105 ( V_175 -> V_176 ) == V_177 ) {
int V_46 = F_106 ( V_175 -> V_176 ) ;
V_178 [ V_157 ] . V_142 [ V_46 ] = V_173 ;
F_107 ( V_173 , NULL ) ;
return 0 ;
}
type = V_179 [ F_105 ( V_175 -> V_176 ) ] ;
if ( V_175 -> V_176 & ~ 0xffff ) {
struct V_180 * V_181 = V_173 -> V_182 ;
const struct V_174 * V_183 = V_181 -> V_184 ;
unsigned int V_185 ;
while ( V_183 && V_183 -> V_186 ) {
if ( ( V_183 -> V_186 == V_173 -> V_186 ) &&
( V_183 -> V_141 == V_173 -> V_141 ) ) {
V_185 = F_108 ( F_109 ( V_183 -> V_176 ) ,
F_110 ( V_183 -> V_176 ) ) ;
if ( V_185 == V_173 -> V_185 ) {
V_28 = & type -> V_156 [ F_106 ( V_183 -> V_176 ) ] ;
break;
}
}
V_183 ++ ;
}
if ( V_28 == NULL )
return - V_121 ;
} else {
V_28 = & type -> V_156 [ F_106 ( V_175 -> V_176 ) ] ;
}
if ( F_73 ( V_28 -> V_30 [ V_157 ] != NULL ) )
return - V_95 ;
V_31 = F_54 ( type , V_126 ) ;
if ( ! V_31 )
return - V_127 ;
if ( V_28 -> V_130 < 0 )
V_28 -> V_130 = V_173 -> V_185 ;
else
F_73 ( V_28 -> V_130 != V_173 -> V_185 ) ;
F_24 ( & V_31 -> V_187 ) ;
V_31 -> V_82 = V_5 ;
V_31 -> V_83 = V_157 ;
V_31 -> V_172 = V_173 ;
V_31 -> V_28 = V_28 ;
F_111 ( V_31 ) ;
F_107 ( V_173 , V_31 ) ;
V_28 -> V_30 [ V_157 ] = V_31 ;
if ( F_112 ( & V_28 -> V_188 ) > 1 )
return 0 ;
V_114 = F_88 ( V_28 ) ;
if ( V_114 ) {
F_107 ( V_173 , NULL ) ;
V_28 -> V_30 [ V_157 ] = NULL ;
F_94 ( V_31 ) ;
F_9 ( V_31 ) ;
}
return V_114 ;
}
static void F_113 ( struct V_172 * V_173 )
{
struct V_26 * V_31 ;
struct V_27 * V_28 ;
int V_13 , V_5 , V_157 ;
V_5 = F_1 ( V_173 -> V_2 ) ;
V_157 = F_104 ( V_5 ) ;
V_31 = F_114 ( V_173 ) ;
if ( ! V_31 ) {
for ( V_13 = 0 ; V_13 < V_189 ; V_13 ++ ) {
if ( V_178 [ V_157 ] . V_142 [ V_13 ] == V_173 ) {
V_178 [ V_157 ] . V_142 [ V_13 ] = NULL ;
break;
}
}
F_73 ( V_13 >= V_189 ) ;
return;
}
V_28 = V_31 -> V_28 ;
if ( F_73 ( V_5 != V_31 -> V_82 ) )
return;
F_107 ( V_173 , NULL ) ;
V_28 -> V_30 [ V_157 ] = NULL ;
if ( F_115 ( & V_28 -> V_188 ) == 0 )
F_90 ( V_28 ) ;
F_94 ( V_31 ) ;
F_9 ( V_31 ) ;
}
static int T_3 F_116 ( void )
{
T_4 V_79 ;
int V_114 ;
V_79 = V_161 * sizeof( struct V_190 ) ;
V_178 = F_100 ( V_79 , V_16 ) ;
if ( ! V_178 ) {
V_114 = - V_127 ;
goto V_191;
}
V_114 = F_102 ( V_179 , false ) ;
if ( V_114 )
goto V_192;
V_193 -> V_194 = F_103 ;
V_193 -> remove = F_113 ;
V_114 = F_117 ( V_193 ) ;
if ( V_114 )
goto V_192;
V_195 = true ;
return 0 ;
V_192:
F_98 ( V_179 ) ;
F_9 ( V_178 ) ;
V_178 = NULL ;
F_6 () ;
V_191:
V_179 = V_196 ;
return V_114 ;
}
static void F_118 ( void )
{
if ( V_195 ) {
V_195 = false ;
F_119 ( V_193 ) ;
F_98 ( V_179 ) ;
F_9 ( V_178 ) ;
F_6 () ;
}
}
static int F_120 ( unsigned int V_29 )
{
struct V_77 * type , * * V_159 = V_160 ;
struct V_27 * V_28 ;
struct V_26 * V_31 ;
int V_13 , V_157 ;
V_157 = F_17 ( V_29 ) ;
for (; * V_159 ; V_159 ++ ) {
type = * V_159 ;
V_28 = type -> V_156 ;
for ( V_13 = 0 ; V_13 < type -> V_153 ; V_13 ++ , V_28 ++ ) {
V_31 = V_28 -> V_30 [ V_157 ] ;
if ( V_31 && F_115 ( & V_31 -> V_187 ) == 0 )
F_94 ( V_31 ) ;
}
}
return 0 ;
}
static int F_121 ( unsigned int V_29 )
{
struct V_77 * type , * * V_159 = V_160 ;
struct V_27 * V_28 ;
struct V_26 * V_31 ;
int V_13 , V_157 , V_197 = 1 ;
if ( V_198 ) {
V_197 = F_122 ( F_123 ( V_29 ) ) ;
}
V_157 = F_17 ( V_29 ) ;
for (; * V_159 ; V_159 ++ ) {
type = * V_159 ;
V_28 = type -> V_156 ;
for ( V_13 = 0 ; V_13 < type -> V_153 ; V_13 ++ , V_28 ++ ) {
V_31 = V_28 -> V_30 [ V_157 ] ;
if ( ! V_31 )
continue;
if ( F_124 ( V_197 , & V_31 -> V_187 ) == V_197 )
F_111 ( V_31 ) ;
}
}
return 0 ;
}
static int F_125 ( unsigned int V_29 )
{
struct V_77 * type , * * V_159 = V_160 ;
struct V_27 * V_28 ;
struct V_26 * V_31 ;
int V_13 , V_157 ;
V_157 = F_17 ( V_29 ) ;
for (; * V_159 ; V_159 ++ ) {
type = * V_159 ;
V_28 = type -> V_156 ;
for ( V_13 = 0 ; V_13 < type -> V_153 ; V_13 ++ , V_28 ++ ) {
if ( V_28 -> V_30 [ V_157 ] )
continue;
V_31 = F_54 ( type , F_126 ( V_29 ) ) ;
if ( ! V_31 )
return - V_127 ;
V_31 -> V_28 = V_28 ;
V_31 -> V_83 = V_157 ;
V_28 -> V_30 [ V_157 ] = V_31 ;
}
}
return 0 ;
}
static void F_127 ( struct V_77 * type , int V_199 ,
int V_200 )
{
struct V_27 * V_28 = type -> V_156 ;
struct V_26 * V_31 ;
int V_13 , V_157 ;
V_157 = F_17 ( V_199 < 0 ? V_200 : V_199 ) ;
for ( V_13 = 0 ; V_13 < type -> V_153 ; V_13 ++ , V_28 ++ ) {
V_31 = V_28 -> V_30 [ V_157 ] ;
if ( ! V_31 )
continue;
if ( V_199 < 0 ) {
F_73 ( V_31 -> V_29 != - 1 ) ;
V_31 -> V_29 = V_200 ;
continue;
}
F_73 ( V_31 -> V_29 != V_199 ) ;
V_31 -> V_29 = - 1 ;
if ( V_200 < 0 )
continue;
F_50 ( V_31 ) ;
F_128 ( & V_28 -> V_28 , V_199 , V_200 ) ;
V_31 -> V_29 = V_200 ;
}
}
static void F_129 ( struct V_77 * * V_201 ,
int V_199 , int V_200 )
{
for (; * V_201 ; V_201 ++ )
F_127 ( * V_201 , V_199 , V_200 ) ;
}
static int F_130 ( unsigned int V_29 )
{
int V_202 ;
if ( ! F_131 ( V_29 , & V_144 ) )
return 0 ;
V_202 = F_132 ( F_123 ( V_29 ) , V_29 ) ;
if ( V_202 < V_203 )
F_133 ( V_202 , & V_144 ) ;
else
V_202 = - 1 ;
F_129 ( V_160 , V_29 , V_202 ) ;
F_129 ( V_179 , V_29 , V_202 ) ;
return 0 ;
}
static int F_134 ( unsigned int V_29 )
{
int V_202 ;
V_202 = F_135 ( & V_144 , F_123 ( V_29 ) ) ;
if ( V_202 < V_203 )
return 0 ;
F_133 ( V_29 , & V_144 ) ;
F_129 ( V_160 , - 1 , V_29 ) ;
F_129 ( V_179 , - 1 , V_29 ) ;
return 0 ;
}
static int T_3 F_136 ( struct V_77 * type )
{
int V_13 , V_114 ;
for ( V_13 = 0 ; V_13 < type -> V_153 ; V_13 ++ ) {
V_114 = F_88 ( & type -> V_156 [ V_13 ] ) ;
if ( V_114 )
return V_114 ;
}
return 0 ;
}
static int T_3 F_137 ( void )
{
struct V_77 * * V_159 = V_160 ;
int V_114 ;
for (; * V_159 ; V_159 ++ ) {
V_114 = F_136 ( * V_159 ) ;
if ( V_114 )
return V_114 ;
}
return 0 ;
}
static int T_3 F_138 ( void )
{
int V_114 ;
V_114 = F_102 ( V_160 , true ) ;
if ( V_114 )
goto V_191;
V_114 = F_137 () ;
if ( V_114 )
goto V_191;
return 0 ;
V_191:
F_98 ( V_160 ) ;
V_160 = V_196 ;
return V_114 ;
}
static int T_3 F_139 ( void )
{
const struct V_204 * V_175 ;
struct V_205 * V_206 ;
int V_207 = 0 , V_208 = 0 , V_114 ;
V_175 = F_140 ( V_209 ) ;
if ( ! V_175 )
return - V_121 ;
if ( F_141 ( V_210 ) )
return - V_121 ;
V_161 = F_142 () ;
V_206 = (struct V_205 * ) V_175 -> V_176 ;
if ( V_206 -> V_211 ) {
V_207 = V_206 -> V_211 () ;
if ( ! V_207 )
V_207 = F_116 () ;
}
if ( V_206 -> V_212 ) {
V_206 -> V_212 () ;
V_208 = F_138 () ;
}
if ( V_208 && V_207 )
return - V_121 ;
if ( ! V_208 ) {
V_114 = F_143 ( V_213 ,
L_6 ,
F_125 , NULL ) ;
if ( V_114 )
goto V_191;
} else {
F_144 ( V_213 ,
L_6 ,
F_125 , NULL ) ;
}
V_198 = 1 ;
F_143 ( V_214 ,
L_7 ,
F_121 , F_120 ) ;
V_198 = 0 ;
F_143 ( V_215 ,
L_8 ,
F_134 , F_130 ) ;
return 0 ;
V_191:
F_145 ( & V_144 , F_95 , NULL , 1 ) ;
F_98 ( V_160 ) ;
F_118 () ;
return V_114 ;
}
static void T_5 F_146 ( void )
{
F_147 ( V_215 ) ;
F_147 ( V_214 ) ;
F_147 ( V_213 ) ;
F_98 ( V_160 ) ;
F_118 () ;
}
