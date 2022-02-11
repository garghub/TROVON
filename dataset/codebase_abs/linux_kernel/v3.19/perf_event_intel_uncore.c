T_1 F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 , char * V_5 )
{
struct V_6 * V_7 =
F_2 ( V_4 , struct V_6 , V_4 ) ;
return sprintf ( V_5 , L_1 , V_7 -> V_8 ) ;
}
struct V_9 * F_3 ( struct V_10 * V_7 )
{
return F_2 ( V_7 -> V_11 , struct V_9 , V_11 ) ;
}
struct V_12 * F_4 ( struct V_9 * V_11 , int V_13 )
{
struct V_12 * V_14 ;
V_14 = * F_5 ( V_11 -> V_14 , V_13 ) ;
if ( V_14 )
return V_14 ;
F_6 ( & V_15 ) ;
if ( * F_5 ( V_11 -> V_14 , V_13 ) )
goto V_16;
F_7 (box, &pmu->box_list, list) {
if ( V_14 -> V_17 == F_8 ( V_13 ) ) {
F_9 ( & V_14 -> V_18 ) ;
* F_5 ( V_11 -> V_14 , V_13 ) = V_14 ;
break;
}
}
V_16:
F_10 ( & V_15 ) ;
return * F_5 ( V_11 -> V_14 , V_13 ) ;
}
struct V_12 * F_11 ( struct V_10 * V_7 )
{
return F_4 ( F_3 ( V_7 ) , F_12 () ) ;
}
T_2 F_13 ( struct V_12 * V_14 , struct V_10 * V_7 )
{
T_2 V_19 ;
F_14 ( V_7 -> V_20 . V_21 , V_19 ) ;
return V_19 ;
}
struct V_22 *
F_15 ( struct V_12 * V_14 , struct V_10 * V_7 )
{
struct V_23 * V_24 ;
struct V_25 * V_26 = & V_7 -> V_20 . V_27 ;
struct V_25 * V_28 = & V_7 -> V_20 . V_29 ;
unsigned long V_30 ;
bool V_31 = false ;
if ( V_26 -> V_32 == V_33 ||
( ! F_16 ( V_14 ) && V_26 -> V_34 ) )
return NULL ;
V_24 = & V_14 -> V_35 [ V_26 -> V_32 ] ;
F_17 ( & V_24 -> V_36 , V_30 ) ;
if ( ! F_18 ( & V_24 -> V_37 ) ||
( V_24 -> V_38 == V_26 -> V_8 && V_24 -> V_39 == V_28 -> V_8 ) ) {
F_9 ( & V_24 -> V_37 ) ;
V_24 -> V_38 = V_26 -> V_8 ;
V_24 -> V_39 = V_28 -> V_8 ;
V_31 = true ;
}
F_19 ( & V_24 -> V_36 , V_30 ) ;
if ( V_31 ) {
if ( ! F_16 ( V_14 ) )
V_26 -> V_34 = 1 ;
return NULL ;
}
return & V_40 ;
}
void F_20 ( struct V_12 * V_14 , struct V_10 * V_7 )
{
struct V_23 * V_24 ;
struct V_25 * V_26 = & V_7 -> V_20 . V_27 ;
if ( F_16 ( V_14 ) || ! V_26 -> V_34 )
return;
V_24 = & V_14 -> V_35 [ V_26 -> V_32 ] ;
F_21 ( & V_24 -> V_37 ) ;
V_26 -> V_34 = 0 ;
}
T_2 F_22 ( struct V_12 * V_14 , int V_32 )
{
struct V_23 * V_24 ;
unsigned long V_30 ;
T_2 V_8 ;
V_24 = & V_14 -> V_35 [ V_32 ] ;
F_17 ( & V_24 -> V_36 , V_30 ) ;
V_8 = V_24 -> V_8 ;
F_19 ( & V_24 -> V_36 , V_30 ) ;
return V_8 ;
}
static void F_23 ( struct V_12 * V_14 , struct V_10 * V_7 , int V_32 )
{
struct V_41 * V_42 = & V_7 -> V_20 ;
V_42 -> V_32 = V_32 ;
V_42 -> V_43 = ++ V_14 -> V_44 [ V_32 ] ;
if ( V_42 -> V_32 == V_45 ) {
V_42 -> V_21 = F_24 ( V_14 ) ;
V_42 -> V_46 = F_25 ( V_14 ) ;
return;
}
V_42 -> V_46 = F_26 ( V_14 , V_42 -> V_32 ) ;
V_42 -> V_21 = F_27 ( V_14 , V_42 -> V_32 ) ;
}
void F_28 ( struct V_12 * V_14 , struct V_10 * V_7 )
{
T_2 V_47 , V_48 , V_49 ;
int V_50 ;
if ( V_7 -> V_20 . V_32 >= V_45 )
V_50 = 64 - F_29 ( V_14 ) ;
else
V_50 = 64 - F_30 ( V_14 ) ;
V_51:
V_47 = F_31 ( & V_7 -> V_20 . V_47 ) ;
V_48 = F_32 ( V_14 , V_7 ) ;
if ( F_33 ( & V_7 -> V_20 . V_47 , V_48 ) != V_47 )
goto V_51;
V_49 = ( V_48 << V_50 ) - ( V_47 << V_50 ) ;
V_49 >>= V_50 ;
F_34 ( V_49 , & V_7 -> V_19 ) ;
}
static enum V_52 F_35 ( struct V_53 * V_53 )
{
struct V_12 * V_14 ;
struct V_10 * V_7 ;
unsigned long V_30 ;
int V_54 ;
V_14 = F_2 ( V_53 , struct V_12 , V_53 ) ;
if ( ! V_14 -> V_55 || V_14 -> V_13 != F_12 () )
return V_56 ;
F_36 ( V_30 ) ;
F_7 (event, &box->active_list, active_entry) {
F_28 ( V_14 , V_7 ) ;
}
F_37 (bit, box->active_mask, UNCORE_PMC_IDX_MAX)
F_28 ( V_14 , V_14 -> V_57 [ V_54 ] ) ;
F_38 ( V_30 ) ;
F_39 ( V_53 , F_40 ( V_14 -> V_58 ) ) ;
return V_59 ;
}
void F_41 ( struct V_12 * V_14 )
{
F_42 ( & V_14 -> V_53 ,
F_40 ( V_14 -> V_58 ) , 0 ,
V_60 , 0 ) ;
}
void F_43 ( struct V_12 * V_14 )
{
F_44 ( & V_14 -> V_53 ) ;
}
static void F_45 ( struct V_12 * V_14 )
{
F_46 ( & V_14 -> V_53 , V_61 , V_62 ) ;
V_14 -> V_53 . V_63 = F_35 ;
}
static struct V_12 * F_47 ( struct V_64 * type , int V_65 )
{
struct V_12 * V_14 ;
int V_66 , V_67 ;
V_67 = sizeof( * V_14 ) + type -> V_68 * sizeof( struct V_23 ) ;
V_14 = F_48 ( V_67 , V_69 , V_65 ) ;
if ( ! V_14 )
return NULL ;
for ( V_66 = 0 ; V_66 < type -> V_68 ; V_66 ++ )
F_49 ( & V_14 -> V_35 [ V_66 ] . V_36 ) ;
F_45 ( V_14 ) ;
F_50 ( & V_14 -> V_18 , 1 ) ;
V_14 -> V_13 = - 1 ;
V_14 -> V_17 = - 1 ;
V_14 -> V_58 = V_70 ;
F_51 ( & V_14 -> V_71 ) ;
return V_14 ;
}
static bool F_52 ( struct V_10 * V_7 )
{
return V_7 -> V_11 -> V_72 == V_73 ;
}
static int
F_53 ( struct V_12 * V_14 , struct V_10 * V_74 , bool V_75 )
{
struct V_10 * V_7 ;
int V_76 , V_77 ;
V_77 = V_14 -> V_11 -> type -> V_78 ;
if ( V_14 -> V_11 -> type -> V_79 )
V_77 ++ ;
if ( V_14 -> V_80 >= V_77 )
return - V_81 ;
V_76 = V_14 -> V_80 ;
if ( F_52 ( V_74 ) ) {
V_14 -> V_82 [ V_76 ] = V_74 ;
V_76 ++ ;
}
if ( ! V_75 )
return V_76 ;
F_7 (event, &leader->sibling_list, group_entry) {
if ( ! F_52 ( V_7 ) ||
V_7 -> V_83 <= V_84 )
continue;
if ( V_76 >= V_77 )
return - V_81 ;
V_14 -> V_82 [ V_76 ] = V_7 ;
V_76 ++ ;
}
return V_76 ;
}
static struct V_22 *
F_54 ( struct V_12 * V_14 , struct V_10 * V_7 )
{
struct V_64 * type = V_14 -> V_11 -> type ;
struct V_22 * V_85 ;
if ( type -> V_86 -> V_87 ) {
V_85 = type -> V_86 -> V_87 ( V_14 , V_7 ) ;
if ( V_85 )
return V_85 ;
}
if ( V_7 -> V_4 . V_8 == V_88 )
return & V_89 ;
if ( type -> V_90 ) {
F_55 (c, type->constraints) {
if ( ( V_7 -> V_20 . V_8 & V_85 -> V_91 ) == V_85 -> V_92 )
return V_85 ;
}
}
return & type -> V_93 ;
}
static void F_56 ( struct V_12 * V_14 , struct V_10 * V_7 )
{
if ( V_14 -> V_11 -> type -> V_86 -> V_94 )
V_14 -> V_11 -> type -> V_86 -> V_94 ( V_14 , V_7 ) ;
}
static int F_57 ( struct V_12 * V_14 , int V_95 [] , int V_76 )
{
unsigned long V_96 [ F_58 ( V_97 ) ] ;
struct V_22 * V_85 ;
int V_66 , V_98 , V_99 , V_100 = 0 ;
struct V_41 * V_42 ;
F_59 ( V_96 , V_97 ) ;
for ( V_66 = 0 , V_98 = V_97 , V_99 = 0 ; V_66 < V_76 ; V_66 ++ ) {
V_42 = & V_14 -> V_82 [ V_66 ] -> V_20 ;
V_85 = F_54 ( V_14 , V_14 -> V_82 [ V_66 ] ) ;
V_42 -> V_101 = V_85 ;
V_98 = F_60 ( V_98 , V_85 -> V_102 ) ;
V_99 = F_61 ( V_99 , V_85 -> V_102 ) ;
}
for ( V_66 = 0 ; V_66 < V_76 ; V_66 ++ ) {
V_42 = & V_14 -> V_82 [ V_66 ] -> V_20 ;
V_85 = V_42 -> V_101 ;
if ( V_42 -> V_32 == - 1 )
break;
if ( ! F_62 ( V_42 -> V_32 , V_85 -> V_103 ) )
break;
if ( F_62 ( V_42 -> V_32 , V_96 ) )
break;
F_63 ( V_42 -> V_32 , V_96 ) ;
if ( V_95 )
V_95 [ V_66 ] = V_42 -> V_32 ;
}
if ( V_66 != V_76 )
V_100 = F_64 ( V_14 -> V_82 , V_76 ,
V_98 , V_99 , V_95 ) ;
if ( ! V_95 || V_100 ) {
for ( V_66 = 0 ; V_66 < V_76 ; V_66 ++ )
F_56 ( V_14 , V_14 -> V_82 [ V_66 ] ) ;
}
return V_100 ? - V_81 : 0 ;
}
static void F_65 ( struct V_10 * V_7 , int V_30 )
{
struct V_12 * V_14 = F_11 ( V_7 ) ;
int V_32 = V_7 -> V_20 . V_32 ;
if ( F_66 ( ! ( V_7 -> V_20 . V_83 & V_104 ) ) )
return;
if ( F_66 ( V_32 == - 1 || V_32 >= V_97 ) )
return;
V_7 -> V_20 . V_83 = 0 ;
V_14 -> V_57 [ V_32 ] = V_7 ;
V_14 -> V_55 ++ ;
F_63 ( V_32 , V_14 -> V_105 ) ;
F_67 ( & V_7 -> V_20 . V_47 , F_32 ( V_14 , V_7 ) ) ;
F_68 ( V_14 , V_7 ) ;
if ( V_14 -> V_55 == 1 ) {
F_69 ( V_14 ) ;
F_41 ( V_14 ) ;
}
}
static void F_70 ( struct V_10 * V_7 , int V_30 )
{
struct V_12 * V_14 = F_11 ( V_7 ) ;
struct V_41 * V_42 = & V_7 -> V_20 ;
if ( F_71 ( V_42 -> V_32 , V_14 -> V_105 ) ) {
F_72 ( V_14 , V_7 ) ;
V_14 -> V_55 -- ;
V_14 -> V_57 [ V_42 -> V_32 ] = NULL ;
F_66 ( V_42 -> V_83 & V_104 ) ;
V_42 -> V_83 |= V_104 ;
if ( V_14 -> V_55 == 0 ) {
F_73 ( V_14 ) ;
F_43 ( V_14 ) ;
}
}
if ( ( V_30 & V_106 ) && ! ( V_42 -> V_83 & V_107 ) ) {
F_28 ( V_14 , V_7 ) ;
V_42 -> V_83 |= V_107 ;
}
}
static int F_74 ( struct V_10 * V_7 , int V_30 )
{
struct V_12 * V_14 = F_11 ( V_7 ) ;
struct V_41 * V_42 = & V_7 -> V_20 ;
int V_95 [ V_97 ] ;
int V_66 , V_76 , V_100 ;
if ( ! V_14 )
return - V_108 ;
V_100 = V_76 = F_53 ( V_14 , V_7 , false ) ;
if ( V_100 < 0 )
return V_100 ;
V_42 -> V_83 = V_107 | V_104 ;
if ( ! ( V_30 & V_109 ) )
V_42 -> V_83 |= V_110 ;
V_100 = F_57 ( V_14 , V_95 , V_76 ) ;
if ( V_100 )
return V_100 ;
for ( V_66 = 0 ; V_66 < V_14 -> V_80 ; V_66 ++ ) {
V_7 = V_14 -> V_82 [ V_66 ] ;
V_42 = & V_7 -> V_20 ;
if ( V_42 -> V_32 == V_95 [ V_66 ] &&
V_42 -> V_43 == V_14 -> V_44 [ V_95 [ V_66 ] ] )
continue;
if ( V_42 -> V_83 & V_104 )
V_42 -> V_83 |= V_110 ;
F_70 ( V_7 , V_106 ) ;
}
for ( V_66 = 0 ; V_66 < V_76 ; V_66 ++ ) {
V_7 = V_14 -> V_82 [ V_66 ] ;
V_42 = & V_7 -> V_20 ;
if ( V_42 -> V_32 != V_95 [ V_66 ] ||
V_42 -> V_43 != V_14 -> V_44 [ V_95 [ V_66 ] ] )
F_23 ( V_14 , V_7 , V_95 [ V_66 ] ) ;
else if ( V_66 < V_14 -> V_80 )
continue;
if ( V_42 -> V_83 & V_110 )
continue;
F_65 ( V_7 , 0 ) ;
}
V_14 -> V_80 = V_76 ;
return 0 ;
}
static void F_75 ( struct V_10 * V_7 , int V_30 )
{
struct V_12 * V_14 = F_11 ( V_7 ) ;
int V_66 ;
F_70 ( V_7 , V_106 ) ;
for ( V_66 = 0 ; V_66 < V_14 -> V_80 ; V_66 ++ ) {
if ( V_7 == V_14 -> V_82 [ V_66 ] ) {
F_56 ( V_14 , V_7 ) ;
while ( ++ V_66 < V_14 -> V_80 )
V_14 -> V_82 [ V_66 - 1 ] = V_14 -> V_82 [ V_66 ] ;
-- V_14 -> V_80 ;
break;
}
}
V_7 -> V_20 . V_32 = - 1 ;
V_7 -> V_20 . V_43 = ~ 0ULL ;
}
void F_76 ( struct V_10 * V_7 )
{
struct V_12 * V_14 = F_11 ( V_7 ) ;
F_28 ( V_14 , V_7 ) ;
}
static int F_77 ( struct V_9 * V_11 ,
struct V_10 * V_7 )
{
struct V_10 * V_74 = V_7 -> V_111 ;
struct V_12 * V_112 ;
int V_100 = - V_81 , V_76 ;
V_112 = F_47 ( V_11 -> type , V_113 ) ;
if ( ! V_112 )
return - V_114 ;
V_112 -> V_11 = V_11 ;
V_76 = F_53 ( V_112 , V_74 , true ) ;
if ( V_76 < 0 )
goto V_16;
V_112 -> V_80 = V_76 ;
V_76 = F_53 ( V_112 , V_7 , false ) ;
if ( V_76 < 0 )
goto V_16;
V_112 -> V_80 = V_76 ;
V_100 = F_57 ( V_112 , NULL , V_76 ) ;
V_16:
F_78 ( V_112 ) ;
return V_100 ;
}
static int V_73 ( struct V_10 * V_7 )
{
struct V_9 * V_11 ;
struct V_12 * V_14 ;
struct V_41 * V_42 = & V_7 -> V_20 ;
int V_100 ;
if ( V_7 -> V_4 . type != V_7 -> V_11 -> type )
return - V_115 ;
V_11 = F_3 ( V_7 ) ;
if ( V_11 -> V_116 < 0 )
return - V_115 ;
if ( V_7 -> V_4 . V_117 || V_7 -> V_4 . V_118 ||
V_7 -> V_4 . V_119 || V_7 -> V_4 . V_120 )
return - V_81 ;
if ( V_42 -> V_121 )
return - V_81 ;
if ( V_7 -> V_13 < 0 )
return - V_81 ;
V_14 = F_4 ( V_11 , V_7 -> V_13 ) ;
if ( ! V_14 || V_14 -> V_13 < 0 )
return - V_81 ;
V_7 -> V_13 = V_14 -> V_13 ;
V_7 -> V_20 . V_32 = - 1 ;
V_7 -> V_20 . V_43 = ~ 0ULL ;
V_7 -> V_20 . V_27 . V_32 = V_33 ;
V_7 -> V_20 . V_29 . V_32 = V_33 ;
if ( V_7 -> V_4 . V_8 == V_88 ) {
if ( ! V_11 -> type -> V_79 )
return - V_81 ;
if ( V_11 -> type -> V_122 && V_11 -> V_123 > 0 )
return - V_81 ;
V_42 -> V_8 = 0ULL ;
} else {
V_42 -> V_8 = V_7 -> V_4 . V_8 & V_11 -> type -> V_124 ;
if ( V_11 -> type -> V_86 -> V_125 ) {
V_100 = V_11 -> type -> V_86 -> V_125 ( V_14 , V_7 ) ;
if ( V_100 )
return V_100 ;
}
}
if ( V_7 -> V_111 != V_7 )
V_100 = F_77 ( V_11 , V_7 ) ;
else
V_100 = 0 ;
return V_100 ;
}
static T_1 F_79 ( struct V_126 * V_127 ,
struct V_128 * V_4 , char * V_5 )
{
return F_80 ( true , V_5 , & V_129 ) ;
}
static int F_81 ( struct V_9 * V_11 )
{
int V_100 ;
if ( ! V_11 -> type -> V_11 ) {
V_11 -> V_11 = (struct V_11 ) {
. V_130 = V_11 -> type -> V_130 ,
. V_131 = V_132 ,
. V_72 = V_73 ,
. V_133 = F_74 ,
. V_134 = F_75 ,
. V_135 = F_65 ,
. V_136 = F_70 ,
. V_137 = F_76 ,
} ;
} else {
V_11 -> V_11 = * V_11 -> type -> V_11 ;
V_11 -> V_11 . V_130 = V_11 -> type -> V_130 ;
}
if ( V_11 -> type -> V_138 == 1 ) {
if ( strlen ( V_11 -> type -> V_139 ) > 0 )
sprintf ( V_11 -> V_139 , L_2 , V_11 -> type -> V_139 ) ;
else
sprintf ( V_11 -> V_139 , L_3 ) ;
} else {
sprintf ( V_11 -> V_139 , L_4 , V_11 -> type -> V_139 ,
V_11 -> V_123 ) ;
}
V_100 = F_82 ( & V_11 -> V_11 , V_11 -> V_139 , - 1 ) ;
return V_100 ;
}
static void T_3 F_83 ( struct V_64 * type )
{
int V_66 ;
for ( V_66 = 0 ; V_66 < type -> V_138 ; V_66 ++ )
F_84 ( type -> V_140 [ V_66 ] . V_14 ) ;
F_78 ( type -> V_140 ) ;
type -> V_140 = NULL ;
F_78 ( type -> V_141 ) ;
type -> V_141 = NULL ;
}
static void T_3 F_85 ( struct V_64 * * V_142 )
{
int V_66 ;
for ( V_66 = 0 ; V_142 [ V_66 ] ; V_66 ++ )
F_83 ( V_142 [ V_66 ] ) ;
}
static int T_3 F_86 ( struct V_64 * type )
{
struct V_9 * V_140 ;
struct V_143 * V_144 ;
struct V_145 * * V_146 ;
int V_66 , V_147 ;
V_140 = F_87 ( sizeof( * V_140 ) * type -> V_138 , V_69 ) ;
if ( ! V_140 )
return - V_114 ;
type -> V_140 = V_140 ;
type -> V_93 = (struct V_22 )
F_88 ( 0 , ( 1ULL << type -> V_78 ) - 1 ,
0 , type -> V_78 , 0 , 0 ) ;
for ( V_66 = 0 ; V_66 < type -> V_138 ; V_66 ++ ) {
V_140 [ V_66 ] . V_116 = - 1 ;
V_140 [ V_66 ] . V_123 = V_66 ;
V_140 [ V_66 ] . type = type ;
F_51 ( & V_140 [ V_66 ] . V_148 ) ;
V_140 [ V_66 ] . V_14 = F_89 ( struct V_12 * ) ;
if ( ! V_140 [ V_66 ] . V_14 )
goto V_149;
}
if ( type -> V_150 ) {
V_66 = 0 ;
while ( type -> V_150 [ V_66 ] . V_4 . V_4 . V_139 )
V_66 ++ ;
V_144 = F_87 ( sizeof( struct V_145 * ) * ( V_66 + 1 ) +
sizeof( * V_144 ) , V_69 ) ;
if ( ! V_144 )
goto V_149;
V_146 = (struct V_145 * * ) ( V_144 + 1 ) ;
V_144 -> V_139 = L_5 ;
V_144 -> V_146 = V_146 ;
for ( V_147 = 0 ; V_147 < V_66 ; V_147 ++ )
V_146 [ V_147 ] = & type -> V_150 [ V_147 ] . V_4 . V_4 ;
type -> V_141 = V_144 ;
}
type -> V_151 = & V_152 ;
return 0 ;
V_149:
F_83 ( type ) ;
return - V_114 ;
}
static int T_3 F_90 ( struct V_64 * * V_142 )
{
int V_66 , V_100 ;
for ( V_66 = 0 ; V_142 [ V_66 ] ; V_66 ++ ) {
V_100 = F_86 ( V_142 [ V_66 ] ) ;
if ( V_100 )
goto V_149;
}
return 0 ;
V_149:
while ( -- V_66 >= 0 )
F_83 ( V_142 [ V_66 ] ) ;
return V_100 ;
}
static int F_91 ( struct V_153 * V_154 , const struct V_155 * V_156 )
{
struct V_9 * V_11 ;
struct V_12 * V_14 ;
struct V_64 * type ;
int V_17 ;
bool V_157 = false ;
V_17 = V_158 [ V_154 -> V_159 -> V_160 ] ;
if ( V_17 < 0 )
return - V_108 ;
if ( F_92 ( V_156 -> V_161 ) == V_162 ) {
int V_32 = F_93 ( V_156 -> V_161 ) ;
V_163 [ V_17 ] [ V_32 ] = V_154 ;
F_94 ( V_154 , NULL ) ;
return 0 ;
}
type = V_164 [ F_92 ( V_156 -> V_161 ) ] ;
V_14 = F_47 ( type , V_113 ) ;
if ( ! V_14 )
return - V_114 ;
V_11 = & type -> V_140 [ F_93 ( V_156 -> V_161 ) ] ;
if ( V_11 -> V_116 < 0 )
V_11 -> V_116 = V_154 -> V_165 ;
else
F_66 ( V_11 -> V_116 != V_154 -> V_165 ) ;
V_14 -> V_17 = V_17 ;
V_14 -> V_153 = V_154 ;
V_14 -> V_11 = V_11 ;
F_94 ( V_154 , V_14 ) ;
F_6 ( & V_15 ) ;
if ( F_95 ( & V_11 -> V_148 ) )
V_157 = true ;
F_96 ( & V_14 -> V_166 , & V_11 -> V_148 ) ;
F_10 ( & V_15 ) ;
if ( V_157 )
F_81 ( V_11 ) ;
return 0 ;
}
static void F_97 ( struct V_153 * V_154 )
{
struct V_12 * V_14 = F_98 ( V_154 ) ;
struct V_9 * V_11 ;
int V_66 , V_13 , V_17 = V_158 [ V_154 -> V_159 -> V_160 ] ;
bool V_167 = false ;
V_14 = F_98 ( V_154 ) ;
if ( ! V_14 ) {
for ( V_66 = 0 ; V_66 < V_168 ; V_66 ++ ) {
if ( V_163 [ V_17 ] [ V_66 ] == V_154 ) {
V_163 [ V_17 ] [ V_66 ] = NULL ;
break;
}
}
F_66 ( V_66 >= V_168 ) ;
return;
}
V_11 = V_14 -> V_11 ;
if ( F_66 ( V_17 != V_14 -> V_17 ) )
return;
F_94 ( V_154 , NULL ) ;
F_6 ( & V_15 ) ;
F_99 ( & V_14 -> V_166 ) ;
if ( F_95 ( & V_11 -> V_148 ) )
V_167 = true ;
F_10 ( & V_15 ) ;
F_100 (cpu) {
if ( * F_5 ( V_11 -> V_14 , V_13 ) == V_14 ) {
* F_5 ( V_11 -> V_14 , V_13 ) = NULL ;
F_21 ( & V_14 -> V_18 ) ;
}
}
F_66 ( F_18 ( & V_14 -> V_18 ) != 1 ) ;
F_78 ( V_14 ) ;
if ( V_167 )
F_101 ( & V_11 -> V_11 ) ;
}
static int T_3 F_102 ( void )
{
int V_100 ;
switch ( V_169 . V_170 ) {
case 45 :
V_100 = F_103 () ;
break;
case 62 :
V_100 = F_104 () ;
break;
case 63 :
V_100 = F_105 () ;
break;
case 42 :
V_100 = F_106 () ;
break;
case 58 :
V_100 = F_107 () ;
break;
case 60 :
case 69 :
V_100 = F_108 () ;
break;
default:
return 0 ;
}
if ( V_100 )
return V_100 ;
V_100 = F_90 ( V_164 ) ;
if ( V_100 )
return V_100 ;
V_171 -> V_172 = F_91 ;
V_171 -> remove = F_97 ;
V_100 = F_109 ( V_171 ) ;
if ( V_100 == 0 )
V_173 = true ;
else
F_85 ( V_164 ) ;
return V_100 ;
}
static void T_3 F_110 ( void )
{
if ( V_173 ) {
V_173 = false ;
F_111 ( V_171 ) ;
F_85 ( V_164 ) ;
}
}
static void F_112 ( void )
{
struct V_12 * V_14 ;
while ( ! F_95 ( & V_174 ) ) {
V_14 = F_113 ( V_174 . V_175 ,
struct V_12 , V_166 ) ;
F_99 ( & V_14 -> V_166 ) ;
F_78 ( V_14 ) ;
}
}
static void F_114 ( int V_13 )
{
struct V_64 * type ;
struct V_9 * V_11 ;
struct V_12 * V_14 ;
int V_66 , V_147 ;
for ( V_66 = 0 ; V_176 [ V_66 ] ; V_66 ++ ) {
type = V_176 [ V_66 ] ;
for ( V_147 = 0 ; V_147 < type -> V_138 ; V_147 ++ ) {
V_11 = & type -> V_140 [ V_147 ] ;
V_14 = * F_5 ( V_11 -> V_14 , V_13 ) ;
* F_5 ( V_11 -> V_14 , V_13 ) = NULL ;
if ( V_14 && F_115 ( & V_14 -> V_18 ) )
F_116 ( & V_14 -> V_166 , & V_174 ) ;
}
}
}
static int F_117 ( int V_13 )
{
struct V_64 * type ;
struct V_9 * V_11 ;
struct V_12 * V_14 , * V_177 ;
int V_66 , V_147 , V_178 , V_17 ;
V_17 = F_8 ( V_13 ) ;
for ( V_66 = 0 ; V_176 [ V_66 ] ; V_66 ++ ) {
type = V_176 [ V_66 ] ;
for ( V_147 = 0 ; V_147 < type -> V_138 ; V_147 ++ ) {
V_11 = & type -> V_140 [ V_147 ] ;
V_14 = * F_5 ( V_11 -> V_14 , V_13 ) ;
if ( V_14 && V_14 -> V_17 >= 0 )
continue;
F_118 (k) {
V_177 = * F_5 ( V_11 -> V_14 , V_178 ) ;
if ( V_177 && V_177 -> V_17 == V_17 ) {
F_9 ( & V_177 -> V_18 ) ;
* F_5 ( V_11 -> V_14 , V_13 ) = V_177 ;
if ( V_14 ) {
F_116 ( & V_14 -> V_166 ,
& V_174 ) ;
V_14 = NULL ;
}
break;
}
}
if ( V_14 )
V_14 -> V_17 = V_17 ;
}
}
return 0 ;
}
static int F_119 ( int V_13 , int V_17 )
{
struct V_64 * type ;
struct V_9 * V_11 ;
struct V_12 * V_14 ;
int V_66 , V_147 ;
for ( V_66 = 0 ; V_176 [ V_66 ] ; V_66 ++ ) {
type = V_176 [ V_66 ] ;
for ( V_147 = 0 ; V_147 < type -> V_138 ; V_147 ++ ) {
V_11 = & type -> V_140 [ V_147 ] ;
if ( V_11 -> V_116 < 0 )
V_11 -> V_116 = V_147 ;
V_14 = F_47 ( type , F_120 ( V_13 ) ) ;
if ( ! V_14 )
return - V_114 ;
V_14 -> V_11 = V_11 ;
V_14 -> V_17 = V_17 ;
* F_5 ( V_11 -> V_14 , V_13 ) = V_14 ;
}
}
return 0 ;
}
static void
F_121 ( struct V_64 * * V_179 , int V_180 , int V_181 )
{
struct V_64 * type ;
struct V_9 * V_11 ;
struct V_12 * V_14 ;
int V_66 , V_147 ;
for ( V_66 = 0 ; V_179 [ V_66 ] ; V_66 ++ ) {
type = V_179 [ V_66 ] ;
for ( V_147 = 0 ; V_147 < type -> V_138 ; V_147 ++ ) {
V_11 = & type -> V_140 [ V_147 ] ;
if ( V_180 < 0 )
V_14 = F_4 ( V_11 , V_181 ) ;
else
V_14 = F_4 ( V_11 , V_180 ) ;
if ( ! V_14 )
continue;
if ( V_180 < 0 ) {
F_66 ( V_14 -> V_13 != - 1 ) ;
V_14 -> V_13 = V_181 ;
continue;
}
F_66 ( V_14 -> V_13 != V_180 ) ;
if ( V_181 >= 0 ) {
F_43 ( V_14 ) ;
F_122 ( & V_11 -> V_11 ,
V_180 , V_181 ) ;
V_14 -> V_13 = V_181 ;
} else {
V_14 -> V_13 = - 1 ;
}
}
}
}
static void F_123 ( int V_13 )
{
int V_66 , V_17 , V_182 ;
if ( ! F_124 ( V_13 , & V_129 ) )
return;
V_17 = F_8 ( V_13 ) ;
V_182 = - 1 ;
F_118 (i) {
if ( V_66 == V_13 )
continue;
if ( V_17 == F_8 ( V_66 ) ) {
V_182 = V_66 ;
break;
}
}
if ( V_182 >= 0 )
F_125 ( V_182 , & V_129 ) ;
F_121 ( V_176 , V_13 , V_182 ) ;
F_121 ( V_164 , V_13 , V_182 ) ;
}
static void F_126 ( int V_13 )
{
int V_66 , V_17 ;
V_17 = F_8 ( V_13 ) ;
F_127 (i, &uncore_cpu_mask) {
if ( V_17 == F_8 ( V_66 ) )
return;
}
F_125 ( V_13 , & V_129 ) ;
F_121 ( V_176 , - 1 , V_13 ) ;
F_121 ( V_164 , - 1 , V_13 ) ;
}
static int F_128 ( struct V_183 * V_184 ,
unsigned long V_185 , void * V_186 )
{
unsigned int V_13 = ( long ) V_186 ;
switch ( V_185 & ~ V_187 ) {
case V_188 :
F_119 ( V_13 , - 1 ) ;
break;
case V_189 :
F_117 ( V_13 ) ;
break;
case V_190 :
case V_191 :
F_114 ( V_13 ) ;
break;
case V_192 :
case V_193 :
F_112 () ;
break;
default:
break;
}
switch ( V_185 & ~ V_187 ) {
case V_194 :
case V_189 :
F_126 ( V_13 ) ;
break;
case V_195 :
F_123 ( V_13 ) ;
break;
default:
break;
}
return V_196 ;
}
static void T_3 F_129 ( void * V_197 )
{
F_117 ( F_12 () ) ;
}
static int T_3 F_130 ( void )
{
int V_100 ;
switch ( V_169 . V_170 ) {
case 26 :
case 30 :
case 37 :
case 44 :
F_131 () ;
break;
case 42 :
case 58 :
F_132 () ;
break;
case 45 :
F_133 () ;
break;
case 46 :
case 47 :
F_134 () ;
break;
case 62 :
F_135 () ;
break;
case 63 :
F_136 () ;
break;
default:
return 0 ;
}
V_100 = F_90 ( V_176 ) ;
if ( V_100 )
return V_100 ;
return 0 ;
}
static int T_3 F_137 ( void )
{
struct V_9 * V_11 ;
struct V_64 * type ;
int V_66 , V_147 ;
for ( V_66 = 0 ; V_176 [ V_66 ] ; V_66 ++ ) {
type = V_176 [ V_66 ] ;
for ( V_147 = 0 ; V_147 < type -> V_138 ; V_147 ++ ) {
V_11 = & type -> V_140 [ V_147 ] ;
F_81 ( V_11 ) ;
}
}
return 0 ;
}
static void T_3 F_138 ( void )
{
int V_13 ;
if ( ! F_139 ( & V_129 ) )
return;
F_140 () ;
F_118 (cpu) {
int V_66 , V_17 = F_8 ( V_13 ) ;
F_127 (i, &uncore_cpu_mask) {
if ( V_17 == F_8 ( V_66 ) ) {
V_17 = - 1 ;
break;
}
}
if ( V_17 < 0 )
continue;
F_119 ( V_13 , V_17 ) ;
F_126 ( V_13 ) ;
}
F_141 ( F_129 , NULL , 1 ) ;
F_142 ( & V_198 ) ;
F_143 () ;
}
static int T_3 F_144 ( void )
{
int V_100 ;
if ( V_169 . V_199 != V_200 )
return - V_108 ;
if ( V_201 )
return - V_108 ;
V_100 = F_102 () ;
if ( V_100 )
goto V_149;
V_100 = F_130 () ;
if ( V_100 ) {
F_110 () ;
goto V_149;
}
F_138 () ;
F_137 () ;
return 0 ;
V_149:
return V_100 ;
}
