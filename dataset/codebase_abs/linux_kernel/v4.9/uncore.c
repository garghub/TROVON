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
static bool F_58 ( struct V_26 * V_31 , struct V_32 * V_24 )
{
return & V_31 -> V_28 -> V_28 == V_24 -> V_28 ;
}
static int
F_59 ( struct V_26 * V_31 , struct V_32 * V_86 ,
bool V_87 )
{
struct V_32 * V_24 ;
int V_88 , V_89 ;
V_89 = V_31 -> V_28 -> type -> V_90 ;
if ( V_31 -> V_28 -> type -> V_91 )
V_89 ++ ;
if ( V_31 -> V_92 >= V_89 )
return - V_93 ;
V_88 = V_31 -> V_92 ;
if ( F_58 ( V_31 , V_86 ) ) {
V_31 -> V_94 [ V_88 ] = V_86 ;
V_88 ++ ;
}
if ( ! V_87 )
return V_88 ;
F_3 (event, &leader->sibling_list, group_entry) {
if ( ! F_58 ( V_31 , V_24 ) ||
V_24 -> V_95 <= V_96 )
continue;
if ( V_88 >= V_89 )
return - V_93 ;
V_31 -> V_94 [ V_88 ] = V_24 ;
V_88 ++ ;
}
return V_88 ;
}
static struct V_36 *
F_60 ( struct V_26 * V_31 , struct V_32 * V_24 )
{
struct V_77 * type = V_31 -> V_28 -> type ;
struct V_36 * V_97 ;
if ( type -> V_98 -> V_99 ) {
V_97 = type -> V_98 -> V_99 ( V_31 , V_24 ) ;
if ( V_97 )
return V_97 ;
}
if ( V_24 -> V_21 . V_25 == V_100 )
return & V_101 ;
if ( type -> V_102 ) {
F_61 (c, type->constraints) {
if ( ( V_24 -> V_34 . V_25 & V_97 -> V_103 ) == V_97 -> V_104 )
return V_97 ;
}
}
return & type -> V_105 ;
}
static void F_62 ( struct V_26 * V_31 ,
struct V_32 * V_24 )
{
if ( V_31 -> V_28 -> type -> V_98 -> V_106 )
V_31 -> V_28 -> type -> V_98 -> V_106 ( V_31 , V_24 ) ;
}
static int F_63 ( struct V_26 * V_31 , int V_107 [] , int V_88 )
{
unsigned long V_108 [ F_64 ( V_109 ) ] ;
struct V_36 * V_97 ;
int V_13 , V_110 , V_111 , V_112 = 0 ;
struct V_54 * V_55 ;
F_65 ( V_108 , V_109 ) ;
for ( V_13 = 0 , V_110 = V_109 , V_111 = 0 ; V_13 < V_88 ; V_13 ++ ) {
V_97 = F_60 ( V_31 , V_31 -> V_94 [ V_13 ] ) ;
V_31 -> V_36 [ V_13 ] = V_97 ;
V_110 = F_66 ( V_110 , V_97 -> V_113 ) ;
V_111 = F_67 ( V_111 , V_97 -> V_113 ) ;
}
for ( V_13 = 0 ; V_13 < V_88 ; V_13 ++ ) {
V_55 = & V_31 -> V_94 [ V_13 ] -> V_34 ;
V_97 = V_31 -> V_36 [ V_13 ] ;
if ( V_55 -> V_46 == - 1 )
break;
if ( ! F_68 ( V_55 -> V_46 , V_97 -> V_114 ) )
break;
if ( F_68 ( V_55 -> V_46 , V_108 ) )
break;
F_69 ( V_55 -> V_46 , V_108 ) ;
if ( V_107 )
V_107 [ V_13 ] = V_55 -> V_46 ;
}
if ( V_13 != V_88 )
V_112 = F_70 ( V_31 -> V_36 , V_88 ,
V_110 , V_111 , V_88 , V_107 ) ;
if ( ! V_107 || V_112 ) {
for ( V_13 = 0 ; V_13 < V_88 ; V_13 ++ )
F_62 ( V_31 , V_31 -> V_94 [ V_13 ] ) ;
}
return V_112 ? - V_93 : 0 ;
}
static void F_71 ( struct V_32 * V_24 , int V_44 )
{
struct V_26 * V_31 = F_72 ( V_24 ) ;
int V_46 = V_24 -> V_34 . V_46 ;
if ( F_73 ( ! ( V_24 -> V_34 . V_95 & V_115 ) ) )
return;
if ( F_73 ( V_46 == - 1 || V_46 >= V_109 ) )
return;
V_24 -> V_34 . V_95 = 0 ;
V_31 -> V_70 [ V_46 ] = V_24 ;
V_31 -> V_68 ++ ;
F_69 ( V_46 , V_31 -> V_116 ) ;
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
if ( F_78 ( V_55 -> V_46 , V_31 -> V_116 ) ) {
F_79 ( V_31 , V_24 ) ;
V_31 -> V_68 -- ;
V_31 -> V_70 [ V_55 -> V_46 ] = NULL ;
F_73 ( V_55 -> V_95 & V_115 ) ;
V_55 -> V_95 |= V_115 ;
if ( V_31 -> V_68 == 0 ) {
F_80 ( V_31 ) ;
F_50 ( V_31 ) ;
}
}
if ( ( V_44 & V_117 ) && ! ( V_55 -> V_95 & V_118 ) ) {
F_34 ( V_31 , V_24 ) ;
V_55 -> V_95 |= V_118 ;
}
}
static int F_81 ( struct V_32 * V_24 , int V_44 )
{
struct V_26 * V_31 = F_72 ( V_24 ) ;
struct V_54 * V_55 = & V_24 -> V_34 ;
int V_107 [ V_109 ] ;
int V_13 , V_88 , V_112 ;
if ( ! V_31 )
return - V_119 ;
V_112 = V_88 = F_59 ( V_31 , V_24 , false ) ;
if ( V_112 < 0 )
return V_112 ;
V_55 -> V_95 = V_118 | V_115 ;
if ( ! ( V_44 & V_120 ) )
V_55 -> V_95 |= V_121 ;
V_112 = F_63 ( V_31 , V_107 , V_88 ) ;
if ( V_112 )
return V_112 ;
for ( V_13 = 0 ; V_13 < V_31 -> V_92 ; V_13 ++ ) {
V_24 = V_31 -> V_94 [ V_13 ] ;
V_55 = & V_24 -> V_34 ;
if ( V_55 -> V_46 == V_107 [ V_13 ] &&
V_55 -> V_56 == V_31 -> V_57 [ V_107 [ V_13 ] ] )
continue;
if ( V_55 -> V_95 & V_115 )
V_55 -> V_95 |= V_121 ;
F_77 ( V_24 , V_117 ) ;
}
for ( V_13 = 0 ; V_13 < V_88 ; V_13 ++ ) {
V_24 = V_31 -> V_94 [ V_13 ] ;
V_55 = & V_24 -> V_34 ;
if ( V_55 -> V_46 != V_107 [ V_13 ] ||
V_55 -> V_56 != V_31 -> V_57 [ V_107 [ V_13 ] ] )
F_29 ( V_31 , V_24 , V_107 [ V_13 ] ) ;
else if ( V_13 < V_31 -> V_92 )
continue;
if ( V_55 -> V_95 & V_121 )
continue;
F_71 ( V_24 , 0 ) ;
}
V_31 -> V_92 = V_88 ;
return 0 ;
}
static void F_82 ( struct V_32 * V_24 , int V_44 )
{
struct V_26 * V_31 = F_72 ( V_24 ) ;
int V_13 ;
F_77 ( V_24 , V_117 ) ;
for ( V_13 = 0 ; V_13 < V_31 -> V_92 ; V_13 ++ ) {
if ( V_24 == V_31 -> V_94 [ V_13 ] ) {
F_62 ( V_31 , V_24 ) ;
for ( ++ V_13 ; V_13 < V_31 -> V_92 ; V_13 ++ )
V_31 -> V_94 [ V_13 - 1 ] = V_31 -> V_94 [ V_13 ] ;
-- V_31 -> V_92 ;
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
struct V_32 * V_86 = V_24 -> V_122 ;
struct V_26 * V_123 ;
int V_112 = - V_93 , V_88 ;
V_123 = F_54 ( V_28 -> type , V_124 ) ;
if ( ! V_123 )
return - V_125 ;
V_123 -> V_28 = V_28 ;
V_88 = F_59 ( V_123 , V_86 , true ) ;
if ( V_88 < 0 )
goto V_126;
V_123 -> V_92 = V_88 ;
V_88 = F_59 ( V_123 , V_24 , false ) ;
if ( V_88 < 0 )
goto V_126;
V_123 -> V_92 = V_88 ;
V_112 = F_63 ( V_123 , NULL , V_88 ) ;
V_126:
F_9 ( V_123 ) ;
return V_112 ;
}
static int F_85 ( struct V_32 * V_24 )
{
struct V_27 * V_28 ;
struct V_26 * V_31 ;
struct V_54 * V_55 = & V_24 -> V_34 ;
int V_112 ;
if ( V_24 -> V_21 . type != V_24 -> V_28 -> type )
return - V_127 ;
V_28 = F_86 ( V_24 ) ;
if ( V_28 -> V_128 < 0 )
return - V_127 ;
if ( V_24 -> V_21 . V_129 || V_24 -> V_21 . V_130 ||
V_24 -> V_21 . V_131 || V_24 -> V_21 . V_132 )
return - V_93 ;
if ( V_55 -> V_133 )
return - V_93 ;
if ( V_24 -> V_29 < 0 )
return - V_93 ;
V_31 = F_16 ( V_28 , V_24 -> V_29 ) ;
if ( ! V_31 || V_31 -> V_29 < 0 )
return - V_93 ;
V_24 -> V_29 = V_31 -> V_29 ;
V_24 -> V_134 = V_31 ;
V_24 -> V_135 |= V_136 ;
V_24 -> V_34 . V_46 = - 1 ;
V_24 -> V_34 . V_56 = ~ 0ULL ;
V_24 -> V_34 . V_41 . V_46 = V_47 ;
V_24 -> V_34 . V_43 . V_46 = V_47 ;
if ( V_24 -> V_21 . V_25 == V_100 ) {
if ( ! V_28 -> type -> V_91 )
return - V_93 ;
if ( V_28 -> type -> V_137 && V_28 -> V_138 > 0 )
return - V_93 ;
V_55 -> V_25 = 0ULL ;
} else {
V_55 -> V_25 = V_24 -> V_21 . V_25 &
( V_28 -> type -> V_139 | ( ( T_2 ) V_28 -> type -> V_140 << 32 ) ) ;
if ( V_28 -> type -> V_98 -> V_141 ) {
V_112 = V_28 -> type -> V_98 -> V_141 ( V_31 , V_24 ) ;
if ( V_112 )
return V_112 ;
}
}
if ( V_24 -> V_122 != V_24 )
V_112 = F_84 ( V_28 , V_24 ) ;
else
V_112 = 0 ;
return V_112 ;
}
static T_1 F_87 ( struct V_142 * V_143 ,
struct V_144 * V_21 , char * V_22 )
{
return F_88 ( true , V_22 , & V_145 ) ;
}
static int F_89 ( struct V_27 * V_28 )
{
int V_112 ;
if ( ! V_28 -> type -> V_28 ) {
V_28 -> V_28 = (struct V_28 ) {
. V_146 = V_28 -> type -> V_146 ,
. V_147 = V_148 ,
. V_149 = F_85 ,
. V_150 = F_81 ,
. V_151 = F_82 ,
. V_152 = F_71 ,
. V_153 = F_77 ,
. V_154 = F_83 ,
} ;
} else {
V_28 -> V_28 = * V_28 -> type -> V_28 ;
V_28 -> V_28 . V_146 = V_28 -> type -> V_146 ;
}
if ( V_28 -> type -> V_155 == 1 ) {
if ( strlen ( V_28 -> type -> V_156 ) > 0 )
sprintf ( V_28 -> V_156 , L_2 , V_28 -> type -> V_156 ) ;
else
sprintf ( V_28 -> V_156 , L_3 ) ;
} else {
sprintf ( V_28 -> V_156 , L_4 , V_28 -> type -> V_156 ,
V_28 -> V_138 ) ;
}
V_112 = F_90 ( & V_28 -> V_28 , V_28 -> V_156 , - 1 ) ;
if ( ! V_112 )
V_28 -> V_157 = true ;
return V_112 ;
}
static void F_91 ( struct V_27 * V_28 )
{
if ( ! V_28 -> V_157 )
return;
F_92 ( & V_28 -> V_28 ) ;
V_28 -> V_157 = false ;
}
static void F_93 ( struct V_77 * type , int V_29 )
{
struct V_27 * V_28 = type -> V_158 ;
struct V_26 * V_31 ;
int V_13 , V_159 ;
if ( V_28 ) {
V_159 = F_94 ( V_29 ) ;
for ( V_13 = 0 ; V_13 < type -> V_155 ; V_13 ++ , V_28 ++ ) {
V_31 = V_28 -> V_30 [ V_159 ] ;
if ( V_31 )
F_95 ( V_31 ) ;
}
}
}
static void F_96 ( void * V_160 )
{
struct V_77 * * V_161 ;
for ( V_161 = V_162 ; * V_161 ; V_161 ++ )
F_93 ( * V_161 ++ , F_42 () ) ;
}
static void F_97 ( struct V_27 * V_28 )
{
int V_159 ;
for ( V_159 = 0 ; V_159 < V_163 ; V_159 ++ )
F_9 ( V_28 -> V_30 [ V_159 ] ) ;
F_9 ( V_28 -> V_30 ) ;
}
static void F_98 ( struct V_77 * type )
{
struct V_27 * V_28 = type -> V_158 ;
int V_13 ;
if ( V_28 ) {
for ( V_13 = 0 ; V_13 < type -> V_155 ; V_13 ++ , V_28 ++ ) {
F_91 ( V_28 ) ;
F_97 ( V_28 ) ;
}
F_9 ( type -> V_158 ) ;
type -> V_158 = NULL ;
}
F_9 ( type -> V_164 ) ;
type -> V_164 = NULL ;
}
static void F_99 ( struct V_77 * * V_161 )
{
for (; * V_161 ; V_161 ++ )
F_98 ( * V_161 ) ;
}
static int T_3 F_100 ( struct V_77 * type , bool V_165 )
{
struct V_27 * V_158 ;
struct V_166 * V_167 ;
struct V_168 * * V_169 ;
T_4 V_79 ;
int V_13 , V_170 ;
V_158 = F_101 ( sizeof( * V_158 ) * type -> V_155 , V_16 ) ;
if ( ! V_158 )
return - V_125 ;
V_79 = V_163 * sizeof( struct V_26 * ) ;
for ( V_13 = 0 ; V_13 < type -> V_155 ; V_13 ++ ) {
V_158 [ V_13 ] . V_128 = V_165 ? V_13 : - 1 ;
V_158 [ V_13 ] . V_138 = V_13 ;
V_158 [ V_13 ] . type = type ;
V_158 [ V_13 ] . V_30 = F_101 ( V_79 , V_16 ) ;
if ( ! V_158 [ V_13 ] . V_30 )
return - V_125 ;
}
type -> V_158 = V_158 ;
type -> V_105 = (struct V_36 )
F_102 ( 0 , ( 1ULL << type -> V_90 ) - 1 ,
0 , type -> V_90 , 0 , 0 ) ;
if ( type -> V_171 ) {
for ( V_13 = 0 ; type -> V_171 [ V_13 ] . V_21 . V_21 . V_156 ; V_13 ++ ) ;
V_167 = F_101 ( sizeof( struct V_168 * ) * ( V_13 + 1 ) +
sizeof( * V_167 ) , V_16 ) ;
if ( ! V_167 )
return - V_125 ;
V_169 = (struct V_168 * * ) ( V_167 + 1 ) ;
V_167 -> V_156 = L_5 ;
V_167 -> V_169 = V_169 ;
for ( V_170 = 0 ; V_170 < V_13 ; V_170 ++ )
V_169 [ V_170 ] = & type -> V_171 [ V_170 ] . V_21 . V_21 ;
type -> V_164 = V_167 ;
}
type -> V_172 = & V_173 ;
return 0 ;
}
static int T_3
F_103 ( struct V_77 * * V_161 , bool V_165 )
{
int V_112 ;
for (; * V_161 ; V_161 ++ ) {
V_112 = F_100 ( * V_161 , V_165 ) ;
if ( V_112 )
return V_112 ;
}
return 0 ;
}
static int F_104 ( struct V_174 * V_175 , const struct V_176 * V_177 )
{
struct V_77 * type ;
struct V_27 * V_28 = NULL ;
struct V_26 * V_31 ;
int V_5 , V_159 , V_112 ;
V_5 = F_1 ( V_175 -> V_2 ) ;
if ( V_5 < 0 )
return - V_119 ;
V_159 = F_105 ( V_5 ) ;
if ( V_159 < 0 )
return - V_93 ;
if ( F_106 ( V_177 -> V_178 ) == V_179 ) {
int V_46 = F_107 ( V_177 -> V_178 ) ;
V_180 [ V_159 ] . V_143 [ V_46 ] = V_175 ;
F_108 ( V_175 , NULL ) ;
return 0 ;
}
type = V_181 [ F_106 ( V_177 -> V_178 ) ] ;
if ( V_177 -> V_178 & ~ 0xffff ) {
struct V_182 * V_183 = V_175 -> V_184 ;
const struct V_176 * V_185 = V_183 -> V_186 ;
unsigned int V_187 ;
while ( V_185 && V_185 -> V_188 ) {
if ( ( V_185 -> V_188 == V_175 -> V_188 ) &&
( V_185 -> V_142 == V_175 -> V_142 ) ) {
V_187 = F_109 ( F_110 ( V_185 -> V_178 ) ,
F_111 ( V_185 -> V_178 ) ) ;
if ( V_187 == V_175 -> V_187 ) {
V_28 = & type -> V_158 [ F_107 ( V_185 -> V_178 ) ] ;
break;
}
}
V_185 ++ ;
}
if ( V_28 == NULL )
return - V_119 ;
} else {
V_28 = & type -> V_158 [ F_107 ( V_177 -> V_178 ) ] ;
}
if ( F_73 ( V_28 -> V_30 [ V_159 ] != NULL ) )
return - V_93 ;
V_31 = F_54 ( type , V_124 ) ;
if ( ! V_31 )
return - V_125 ;
if ( V_28 -> V_128 < 0 )
V_28 -> V_128 = V_175 -> V_187 ;
else
F_73 ( V_28 -> V_128 != V_175 -> V_187 ) ;
F_24 ( & V_31 -> V_189 ) ;
V_31 -> V_82 = V_5 ;
V_31 -> V_83 = V_159 ;
V_31 -> V_174 = V_175 ;
V_31 -> V_28 = V_28 ;
F_112 ( V_31 ) ;
F_108 ( V_175 , V_31 ) ;
V_28 -> V_30 [ V_159 ] = V_31 ;
if ( F_113 ( & V_28 -> V_190 ) > 1 )
return 0 ;
V_112 = F_89 ( V_28 ) ;
if ( V_112 ) {
F_108 ( V_175 , NULL ) ;
V_28 -> V_30 [ V_159 ] = NULL ;
F_95 ( V_31 ) ;
F_9 ( V_31 ) ;
}
return V_112 ;
}
static void F_114 ( struct V_174 * V_175 )
{
struct V_26 * V_31 ;
struct V_27 * V_28 ;
int V_13 , V_5 , V_159 ;
V_5 = F_1 ( V_175 -> V_2 ) ;
V_159 = F_105 ( V_5 ) ;
V_31 = F_115 ( V_175 ) ;
if ( ! V_31 ) {
for ( V_13 = 0 ; V_13 < V_191 ; V_13 ++ ) {
if ( V_180 [ V_159 ] . V_143 [ V_13 ] == V_175 ) {
V_180 [ V_159 ] . V_143 [ V_13 ] = NULL ;
break;
}
}
F_73 ( V_13 >= V_191 ) ;
return;
}
V_28 = V_31 -> V_28 ;
if ( F_73 ( V_5 != V_31 -> V_82 ) )
return;
F_108 ( V_175 , NULL ) ;
V_28 -> V_30 [ V_159 ] = NULL ;
if ( F_116 ( & V_28 -> V_190 ) == 0 )
F_91 ( V_28 ) ;
F_95 ( V_31 ) ;
F_9 ( V_31 ) ;
}
static int T_3 F_117 ( void )
{
T_4 V_79 ;
int V_112 ;
V_79 = V_163 * sizeof( struct V_192 ) ;
V_180 = F_101 ( V_79 , V_16 ) ;
if ( ! V_180 ) {
V_112 = - V_125 ;
goto V_193;
}
V_112 = F_103 ( V_181 , false ) ;
if ( V_112 )
goto V_194;
V_195 -> V_196 = F_104 ;
V_195 -> remove = F_114 ;
V_112 = F_118 ( V_195 ) ;
if ( V_112 )
goto V_194;
V_197 = true ;
return 0 ;
V_194:
F_99 ( V_181 ) ;
F_9 ( V_180 ) ;
V_180 = NULL ;
F_6 () ;
V_193:
V_181 = V_198 ;
return V_112 ;
}
static void F_119 ( void )
{
if ( V_197 ) {
V_197 = false ;
F_120 ( V_195 ) ;
F_99 ( V_181 ) ;
F_9 ( V_180 ) ;
F_6 () ;
}
}
static int F_121 ( unsigned int V_29 )
{
struct V_77 * type , * * V_161 = V_162 ;
struct V_27 * V_28 ;
struct V_26 * V_31 ;
int V_13 , V_159 ;
V_159 = F_17 ( V_29 ) ;
for (; * V_161 ; V_161 ++ ) {
type = * V_161 ;
V_28 = type -> V_158 ;
for ( V_13 = 0 ; V_13 < type -> V_155 ; V_13 ++ , V_28 ++ ) {
V_31 = V_28 -> V_30 [ V_159 ] ;
if ( V_31 && F_116 ( & V_31 -> V_189 ) == 0 )
F_95 ( V_31 ) ;
}
}
return 0 ;
}
static int F_122 ( unsigned int V_29 )
{
struct V_77 * type , * * V_161 = V_162 ;
struct V_27 * V_28 ;
struct V_26 * V_31 ;
int V_13 , V_159 , V_199 = 1 ;
if ( V_200 ) {
V_199 = F_123 ( F_124 ( V_29 ) ) ;
}
V_159 = F_17 ( V_29 ) ;
for (; * V_161 ; V_161 ++ ) {
type = * V_161 ;
V_28 = type -> V_158 ;
for ( V_13 = 0 ; V_13 < type -> V_155 ; V_13 ++ , V_28 ++ ) {
V_31 = V_28 -> V_30 [ V_159 ] ;
if ( ! V_31 )
continue;
if ( F_125 ( V_199 , & V_31 -> V_189 ) == V_199 )
F_112 ( V_31 ) ;
}
}
return 0 ;
}
static int F_126 ( unsigned int V_29 )
{
struct V_77 * type , * * V_161 = V_162 ;
struct V_27 * V_28 ;
struct V_26 * V_31 ;
int V_13 , V_159 ;
V_159 = F_17 ( V_29 ) ;
for (; * V_161 ; V_161 ++ ) {
type = * V_161 ;
V_28 = type -> V_158 ;
for ( V_13 = 0 ; V_13 < type -> V_155 ; V_13 ++ , V_28 ++ ) {
if ( V_28 -> V_30 [ V_159 ] )
continue;
V_31 = F_54 ( type , F_127 ( V_29 ) ) ;
if ( ! V_31 )
return - V_125 ;
V_31 -> V_28 = V_28 ;
V_31 -> V_83 = V_159 ;
V_28 -> V_30 [ V_159 ] = V_31 ;
}
}
return 0 ;
}
static void F_128 ( struct V_77 * type , int V_201 ,
int V_202 )
{
struct V_27 * V_28 = type -> V_158 ;
struct V_26 * V_31 ;
int V_13 , V_159 ;
V_159 = F_17 ( V_201 < 0 ? V_202 : V_201 ) ;
for ( V_13 = 0 ; V_13 < type -> V_155 ; V_13 ++ , V_28 ++ ) {
V_31 = V_28 -> V_30 [ V_159 ] ;
if ( ! V_31 )
continue;
if ( V_201 < 0 ) {
F_73 ( V_31 -> V_29 != - 1 ) ;
V_31 -> V_29 = V_202 ;
continue;
}
F_73 ( V_31 -> V_29 != V_201 ) ;
V_31 -> V_29 = - 1 ;
if ( V_202 < 0 )
continue;
F_50 ( V_31 ) ;
F_129 ( & V_28 -> V_28 , V_201 , V_202 ) ;
V_31 -> V_29 = V_202 ;
}
}
static void F_130 ( struct V_77 * * V_203 ,
int V_201 , int V_202 )
{
for (; * V_203 ; V_203 ++ )
F_128 ( * V_203 , V_201 , V_202 ) ;
}
static int F_131 ( unsigned int V_29 )
{
int V_204 ;
if ( ! F_132 ( V_29 , & V_145 ) )
return 0 ;
V_204 = F_133 ( F_124 ( V_29 ) , V_29 ) ;
if ( V_204 < V_205 )
F_134 ( V_204 , & V_145 ) ;
else
V_204 = - 1 ;
F_130 ( V_162 , V_29 , V_204 ) ;
F_130 ( V_181 , V_29 , V_204 ) ;
return 0 ;
}
static int F_135 ( unsigned int V_29 )
{
int V_204 ;
V_204 = F_136 ( & V_145 , F_124 ( V_29 ) ) ;
if ( V_204 < V_205 )
return 0 ;
F_134 ( V_29 , & V_145 ) ;
F_130 ( V_162 , - 1 , V_29 ) ;
F_130 ( V_181 , - 1 , V_29 ) ;
return 0 ;
}
static int T_3 F_137 ( struct V_77 * type )
{
int V_13 , V_112 ;
for ( V_13 = 0 ; V_13 < type -> V_155 ; V_13 ++ ) {
V_112 = F_89 ( & type -> V_158 [ V_13 ] ) ;
if ( V_112 )
return V_112 ;
}
return 0 ;
}
static int T_3 F_138 ( void )
{
struct V_77 * * V_161 = V_162 ;
int V_112 ;
for (; * V_161 ; V_161 ++ ) {
V_112 = F_137 ( * V_161 ) ;
if ( V_112 )
return V_112 ;
}
return 0 ;
}
static int T_3 F_139 ( void )
{
int V_112 ;
V_112 = F_103 ( V_162 , true ) ;
if ( V_112 )
goto V_193;
V_112 = F_138 () ;
if ( V_112 )
goto V_193;
return 0 ;
V_193:
F_99 ( V_162 ) ;
V_162 = V_198 ;
return V_112 ;
}
static int T_3 F_140 ( void )
{
const struct V_206 * V_177 ;
struct V_207 * V_208 ;
int V_209 = 0 , V_210 = 0 , V_112 ;
V_177 = F_141 ( V_211 ) ;
if ( ! V_177 )
return - V_119 ;
if ( F_142 ( V_212 ) )
return - V_119 ;
V_163 = F_143 () ;
V_208 = (struct V_207 * ) V_177 -> V_178 ;
if ( V_208 -> V_213 ) {
V_209 = V_208 -> V_213 () ;
if ( ! V_209 )
V_209 = F_117 () ;
}
if ( V_208 -> V_214 ) {
V_208 -> V_214 () ;
V_210 = F_139 () ;
}
if ( V_210 && V_209 )
return - V_119 ;
if ( ! V_210 ) {
V_112 = F_144 ( V_215 ,
L_6 ,
F_126 , NULL ) ;
if ( V_112 )
goto V_193;
} else {
F_145 ( V_215 ,
L_6 ,
F_126 , NULL ) ;
}
V_200 = 1 ;
F_144 ( V_216 ,
L_7 ,
F_122 , F_121 ) ;
V_200 = 0 ;
F_144 ( V_217 ,
L_8 ,
F_135 , F_131 ) ;
return 0 ;
V_193:
F_146 ( & V_145 , F_96 , NULL , 1 ) ;
F_99 ( V_162 ) ;
F_119 () ;
return V_112 ;
}
static void T_5 F_147 ( void )
{
F_148 ( V_217 ) ;
F_148 ( V_216 ) ;
F_148 ( V_215 ) ;
F_99 ( V_162 ) ;
F_119 () ;
}
