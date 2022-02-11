static unsigned F_1 ( struct V_1 * V_2 ,
unsigned V_3 )
{
if ( V_3 == 0 )
return V_2 -> V_4 . V_5 >>
( V_2 -> V_4 . V_6 *
V_2 -> V_4 . V_7 ) ;
else if ( V_3 == V_2 -> V_4 . V_7 )
return F_2 ( V_2 ) ;
else
return 1 << V_2 -> V_4 . V_6 ;
}
static unsigned F_3 ( struct V_1 * V_2 , unsigned V_3 )
{
return F_4 ( F_1 ( V_2 , V_3 ) * 8 ) ;
}
void F_5 ( struct V_8 * V_9 ,
struct V_10 * V_11 ,
struct V_12 * V_13 )
{
V_13 -> V_14 = V_9 -> V_15 . V_16 ;
V_13 -> V_17 = 0 ;
V_13 -> V_18 . V_16 = & V_13 -> V_14 -> V_19 ;
V_13 -> V_18 . V_20 = true ;
V_13 -> V_21 = NULL ;
F_6 ( & V_13 -> V_18 . V_22 , V_11 ) ;
}
static int F_7 ( struct V_23 * V_24 ,
int (* F_8)( void * , struct V_25 * ) ,
void * V_26 )
{
unsigned V_27 ;
int V_28 ;
if ( ! V_24 -> V_29 )
return 0 ;
for ( V_27 = 0 ; V_27 <= V_24 -> V_30 ; ++ V_27 ) {
struct V_23 * V_13 = & V_24 -> V_29 [ V_27 ] ;
if ( ! V_13 -> V_16 )
continue;
V_28 = F_8 ( V_26 , V_13 -> V_16 ) ;
if ( V_28 )
return V_28 ;
V_28 = F_7 ( V_13 , F_8 , V_26 ) ;
if ( V_28 )
return V_28 ;
}
return V_28 ;
}
int F_9 ( struct V_1 * V_2 , struct V_8 * V_9 ,
int (* F_8)( void * V_31 , struct V_25 * V_16 ) ,
void * V_26 )
{
T_1 V_32 ;
V_32 = F_10 ( & V_2 -> V_32 ) ;
if ( V_32 == V_9 -> V_33 )
return 0 ;
return F_7 ( & V_9 -> V_15 , F_8 , V_26 ) ;
}
static void F_11 ( struct V_23 * V_24 )
{
unsigned V_27 ;
if ( ! V_24 -> V_29 )
return;
for ( V_27 = 0 ; V_27 <= V_24 -> V_30 ; ++ V_27 ) {
struct V_23 * V_13 = & V_24 -> V_29 [ V_27 ] ;
if ( ! V_13 -> V_16 )
continue;
F_12 ( & V_13 -> V_16 -> V_19 ) ;
F_11 ( V_13 ) ;
}
}
void F_13 ( struct V_1 * V_2 ,
struct V_8 * V_9 )
{
struct V_34 * V_35 = V_2 -> V_36 . V_37 . V_35 ;
F_14 ( & V_35 -> V_38 ) ;
F_11 ( & V_9 -> V_15 ) ;
F_15 ( & V_35 -> V_38 ) ;
}
static int F_16 ( struct V_1 * V_2 ,
struct V_8 * V_9 ,
struct V_23 * V_24 ,
T_1 V_39 , T_1 V_40 ,
unsigned V_3 )
{
unsigned V_41 = ( V_2 -> V_4 . V_7 - V_3 ) *
V_2 -> V_4 . V_6 ;
unsigned V_42 , V_43 , V_44 ;
int V_28 ;
T_2 V_45 ;
if ( ! V_24 -> V_29 ) {
unsigned V_46 = F_1 ( V_2 , V_3 ) ;
V_24 -> V_29 = F_17 ( V_46 ,
sizeof( struct V_23 ) ,
V_47 | V_48 ) ;
if ( ! V_24 -> V_29 )
return - V_49 ;
memset ( V_24 -> V_29 , 0 , sizeof( struct V_23 ) ) ;
}
V_43 = V_39 >> V_41 ;
V_44 = V_40 >> V_41 ;
if ( V_43 >= F_1 ( V_2 , V_3 ) ||
V_44 >= F_1 ( V_2 , V_3 ) )
return - V_50 ;
if ( V_44 > V_24 -> V_30 )
V_24 -> V_30 = V_44 ;
++ V_3 ;
V_39 = V_39 & ( ( 1 << V_41 ) - 1 ) ;
V_40 = V_40 & ( ( 1 << V_41 ) - 1 ) ;
V_45 = V_51 |
V_52 ;
if ( V_9 -> V_53 )
V_45 |= V_54 ;
else
V_45 |= ( V_55 |
V_56 ) ;
for ( V_42 = V_43 ; V_42 <= V_44 ; ++ V_42 ) {
struct V_57 * V_58 = V_9 -> V_15 . V_16 -> V_19 . V_58 ;
struct V_23 * V_13 = & V_24 -> V_29 [ V_42 ] ;
struct V_25 * V_59 ;
if ( ! V_13 -> V_16 ) {
V_28 = F_18 ( V_2 ,
F_3 ( V_2 , V_3 ) ,
V_60 , true ,
V_61 ,
V_45 ,
NULL , V_58 , & V_59 ) ;
if ( V_28 )
return V_28 ;
V_59 -> V_24 = F_19 ( V_9 -> V_15 . V_16 ) ;
V_13 -> V_16 = V_59 ;
V_13 -> V_62 = 0 ;
}
if ( V_3 < V_2 -> V_4 . V_7 ) {
T_1 V_63 = ( V_42 == V_43 ) ? V_39 : 0 ;
T_1 V_64 = ( V_42 == V_44 ) ? V_40 :
( ( 1 << V_41 ) - 1 ) ;
V_28 = F_16 ( V_2 , V_9 , V_13 , V_63 ,
V_64 , V_3 ) ;
if ( V_28 )
return V_28 ;
}
}
return 0 ;
}
int F_20 ( struct V_1 * V_2 ,
struct V_8 * V_9 ,
T_1 V_39 , T_1 V_65 )
{
T_1 V_66 ;
T_1 V_40 ;
if ( V_39 & V_67 || V_65 & V_67 )
return - V_50 ;
V_40 = V_39 + V_65 - 1 ;
V_66 = V_40 / V_60 ;
if ( V_66 >= V_2 -> V_4 . V_5 ) {
F_21 ( V_2 -> V_68 , L_1 ,
V_66 , V_2 -> V_4 . V_5 ) ;
return - V_50 ;
}
V_39 /= V_60 ;
V_40 /= V_60 ;
return F_16 ( V_2 , V_9 , & V_9 -> V_15 , V_39 , V_40 , 0 ) ;
}
static bool F_22 ( struct V_1 * V_2 ,
struct V_69 * V_70 )
{
return V_70 -> V_71 !=
F_23 ( & V_2 -> V_72 ) ;
}
static bool F_24 ( struct V_8 * V_9 , unsigned V_73 )
{
return ! ! V_9 -> V_74 [ V_73 ] ;
}
static int F_25 ( struct V_8 * V_9 ,
struct V_75 * V_76 ,
struct V_77 * V_78 ,
struct V_79 * V_80 ,
struct V_81 * V_82 )
{
struct V_1 * V_2 = V_76 -> V_2 ;
unsigned V_73 = V_76 -> V_83 -> V_73 ;
T_1 V_84 = V_2 -> V_84 + V_76 -> V_85 ;
struct V_69 * V_70 = V_9 -> V_74 [ V_73 ] ;
struct V_86 * V_87 = & V_2 -> V_4 . V_87 [ V_73 ] ;
struct V_79 * V_88 = V_78 -> V_89 ;
int V_28 = 0 ;
struct V_79 * V_90 , * V_91 ;
bool V_92 = false ;
V_90 = V_70 -> V_93 ;
if ( ( F_22 ( V_2 , V_70 ) ) ||
( F_10 ( & V_70 -> V_94 ) != V_9 -> V_95 ) ||
( V_82 -> V_96 != V_70 -> V_97 ) ||
( V_88 && ( ! V_90 || V_88 -> V_98 != V_90 -> V_98 ||
F_26 ( V_88 , V_90 ) ) ) ||
( ! V_70 -> V_99 || ( V_70 -> V_99 -> V_98 != V_84 &&
! F_27 ( V_70 -> V_99 ) ) ) ) {
V_92 = true ;
V_70 -> V_97 = 0 ;
V_91 = F_28 ( & V_70 -> V_100 , V_76 ) ;
if ( V_91 ) {
V_28 = F_29 ( V_2 , V_78 , V_91 ) ;
return V_28 ;
}
}
V_28 = F_29 ( V_76 -> V_2 , & V_70 -> V_100 , V_80 ) ;
if ( V_28 )
goto V_101;
if ( V_88 && ( ! V_90 || V_88 -> V_98 != V_90 -> V_98 ||
F_26 ( V_88 , V_90 ) ) ) {
F_30 ( V_70 -> V_93 ) ;
V_70 -> V_93 = F_31 ( V_88 ) ;
}
V_70 -> V_97 = V_82 -> V_96 ;
F_32 ( & V_70 -> V_94 , V_9 -> V_95 ) ;
V_82 -> V_102 = V_92 ;
if ( V_92 ) {
F_30 ( V_70 -> V_99 ) ;
V_70 -> V_99 = NULL ;
}
V_82 -> V_103 = V_70 - V_87 -> V_104 ;
F_33 ( V_9 , V_76 , V_82 ) ;
V_101:
return V_28 ;
}
int F_34 ( struct V_8 * V_9 , struct V_75 * V_76 ,
struct V_77 * V_78 , struct V_79 * V_80 ,
struct V_81 * V_82 )
{
struct V_1 * V_2 = V_76 -> V_2 ;
unsigned V_73 = V_76 -> V_83 -> V_73 ;
struct V_86 * V_87 = & V_2 -> V_4 . V_87 [ V_73 ] ;
T_1 V_84 = V_2 -> V_84 + V_76 -> V_85 ;
struct V_79 * V_88 = V_78 -> V_89 ;
struct V_69 * V_70 , * V_105 ;
struct V_79 * * V_106 ;
unsigned V_27 ;
int V_28 = 0 ;
F_35 ( & V_87 -> V_107 ) ;
if ( F_24 ( V_9 , V_73 ) ) {
V_28 = F_25 ( V_9 , V_76 , V_78 , V_80 , V_82 ) ;
F_36 ( & V_87 -> V_107 ) ;
return V_28 ;
}
V_106 = F_37 ( sizeof( void * ) , V_87 -> V_108 , V_47 ) ;
if ( ! V_106 ) {
F_36 ( & V_87 -> V_107 ) ;
return - V_49 ;
}
V_27 = 0 ;
F_38 (idle, &id_mgr->ids_lru, list) {
V_106 [ V_27 ] = F_28 ( & V_105 -> V_100 , V_76 ) ;
if ( ! V_106 [ V_27 ] )
break;
++ V_27 ;
}
if ( & V_105 -> V_109 == & V_87 -> V_110 ) {
T_2 V_84 = V_2 -> V_4 . V_84 + V_76 -> V_85 ;
unsigned V_111 = ++ V_2 -> V_4 . V_111 [ V_76 -> V_85 ] ;
struct V_112 * V_113 ;
unsigned V_114 ;
for ( V_114 = 0 ; V_114 < V_27 ; ++ V_114 )
F_31 ( V_106 [ V_114 ] ) ;
V_113 = F_39 ( V_27 , V_106 , V_84 ,
V_111 , true ) ;
if ( ! V_113 ) {
for ( V_114 = 0 ; V_114 < V_27 ; ++ V_114 )
F_30 ( V_106 [ V_114 ] ) ;
F_40 ( V_106 ) ;
V_28 = - V_49 ;
goto error;
}
V_28 = F_29 ( V_76 -> V_2 , V_78 , & V_113 -> V_115 ) ;
F_30 ( & V_113 -> V_115 ) ;
if ( V_28 )
goto error;
F_36 ( & V_87 -> V_107 ) ;
return 0 ;
}
F_40 ( V_106 ) ;
V_82 -> V_102 = false ;
F_41 (id, &id_mgr->ids_lru, list) {
struct V_79 * V_90 ;
bool V_92 = false ;
if ( F_22 ( V_2 , V_70 ) )
continue;
if ( F_10 ( & V_70 -> V_94 ) != V_9 -> V_95 )
continue;
if ( V_82 -> V_96 != V_70 -> V_97 )
continue;
if ( ! V_70 -> V_99 ||
( V_70 -> V_99 -> V_98 != V_84 &&
! F_27 ( V_70 -> V_99 ) ) )
V_92 = true ;
V_90 = V_70 -> V_93 ;
if ( V_88 && ( ! V_90 || F_26 ( V_88 , V_90 ) ) )
V_92 = true ;
if ( V_2 -> V_116 < V_117 && V_92 )
continue;
V_28 = F_29 ( V_76 -> V_2 , & V_70 -> V_100 , V_80 ) ;
if ( V_28 )
goto error;
if ( V_88 && ( ! V_90 || F_26 ( V_88 , V_90 ) ) ) {
F_30 ( V_70 -> V_93 ) ;
V_70 -> V_93 = F_31 ( V_88 ) ;
}
if ( V_92 )
goto V_92;
else
goto V_118;
} ;
V_70 = V_105 ;
V_28 = F_29 ( V_76 -> V_2 , & V_70 -> V_100 , V_80 ) ;
if ( V_28 )
goto error;
V_70 -> V_97 = V_82 -> V_96 ;
F_30 ( V_70 -> V_93 ) ;
V_70 -> V_93 = F_31 ( V_88 ) ;
F_32 ( & V_70 -> V_94 , V_9 -> V_95 ) ;
V_92:
V_82 -> V_102 = true ;
F_30 ( V_70 -> V_99 ) ;
V_70 -> V_99 = NULL ;
V_118:
F_42 ( & V_70 -> V_109 , & V_87 -> V_110 ) ;
V_82 -> V_103 = V_70 - V_87 -> V_104 ;
F_33 ( V_9 , V_76 , V_82 ) ;
error:
F_36 ( & V_87 -> V_107 ) ;
return V_28 ;
}
static void F_43 ( struct V_1 * V_2 ,
struct V_8 * V_9 ,
unsigned V_73 )
{
struct V_86 * V_87 = & V_2 -> V_4 . V_87 [ V_73 ] ;
F_35 ( & V_87 -> V_107 ) ;
if ( V_9 -> V_74 [ V_73 ] ) {
F_6 ( & V_9 -> V_74 [ V_73 ] -> V_109 ,
& V_87 -> V_110 ) ;
V_9 -> V_74 [ V_73 ] = NULL ;
F_44 ( & V_87 -> V_119 ) ;
}
F_36 ( & V_87 -> V_107 ) ;
}
static int F_45 ( struct V_1 * V_2 ,
struct V_8 * V_9 ,
unsigned V_73 )
{
struct V_86 * V_87 ;
struct V_69 * V_105 ;
int V_28 = 0 ;
V_87 = & V_2 -> V_4 . V_87 [ V_73 ] ;
F_35 ( & V_87 -> V_107 ) ;
if ( V_9 -> V_74 [ V_73 ] )
goto V_120;
if ( F_46 ( & V_87 -> V_119 ) >
V_121 ) {
F_47 ( L_2 ) ;
F_44 ( & V_87 -> V_119 ) ;
V_28 = - V_50 ;
goto V_120;
}
V_105 = F_48 ( & V_87 -> V_110 , struct V_69 , V_109 ) ;
F_49 ( & V_105 -> V_109 ) ;
V_9 -> V_74 [ V_73 ] = V_105 ;
F_36 ( & V_87 -> V_107 ) ;
return 0 ;
V_120:
F_36 ( & V_87 -> V_107 ) ;
return V_28 ;
}
void F_50 ( struct V_1 * V_2 )
{
const struct V_122 * V_123 ;
bool V_124 ;
struct V_75 * V_76 ;
int V_27 ;
V_124 = false ;
V_123 = F_51 ( V_2 , V_125 ) ;
if ( V_123 ) {
if ( V_123 -> V_126 -> V_127 <= 7 )
V_124 = true ;
else if ( V_123 -> V_126 -> V_127 == 8 )
if ( V_2 -> V_128 . V_129 < 673 )
V_124 = true ;
}
for ( V_27 = 0 ; V_27 < V_2 -> V_130 ; V_27 ++ ) {
V_76 = V_2 -> V_131 [ V_27 ] ;
if ( V_76 -> V_83 -> type == V_132 )
V_76 -> V_124 = V_124 ;
else
V_76 -> V_124 = false ;
}
}
bool F_52 ( struct V_75 * V_76 ,
struct V_81 * V_82 )
{
struct V_1 * V_2 = V_76 -> V_2 ;
unsigned V_73 = V_76 -> V_83 -> V_73 ;
struct V_86 * V_87 = & V_2 -> V_4 . V_87 [ V_73 ] ;
struct V_69 * V_70 ;
bool V_133 ;
bool V_134 = V_82 -> V_102 || V_76 -> V_124 ;
if ( V_82 -> V_103 == 0 )
return false ;
V_70 = & V_87 -> V_104 [ V_82 -> V_103 ] ;
V_133 = V_76 -> V_83 -> V_135 && (
V_70 -> V_136 != V_82 -> V_136 ||
V_70 -> V_137 != V_82 -> V_137 ||
V_70 -> V_138 != V_82 -> V_138 ||
V_70 -> V_139 != V_82 -> V_139 ||
V_70 -> V_140 != V_82 -> V_140 ||
V_70 -> V_141 != V_82 -> V_141 ) ;
if ( F_22 ( V_2 , V_70 ) )
return true ;
return V_134 || V_133 ;
}
static bool F_53 ( struct V_1 * V_2 )
{
return ( V_2 -> V_142 . V_143 == V_2 -> V_142 . V_144 ) ;
}
int F_54 ( struct V_75 * V_76 , struct V_81 * V_82 )
{
struct V_1 * V_2 = V_76 -> V_2 ;
unsigned V_73 = V_76 -> V_83 -> V_73 ;
struct V_86 * V_87 = & V_2 -> V_4 . V_87 [ V_73 ] ;
struct V_69 * V_70 = & V_87 -> V_104 [ V_82 -> V_103 ] ;
bool V_133 = V_76 -> V_83 -> V_135 && (
V_70 -> V_136 != V_82 -> V_136 ||
V_70 -> V_137 != V_82 -> V_137 ||
V_70 -> V_138 != V_82 -> V_138 ||
V_70 -> V_139 != V_82 -> V_139 ||
V_70 -> V_140 != V_82 -> V_140 ||
V_70 -> V_141 != V_82 -> V_141 ) ;
bool V_134 = V_82 -> V_102 ;
unsigned V_145 = 0 ;
int V_28 ;
if ( F_22 ( V_2 , V_70 ) ) {
V_133 = true ;
V_134 = true ;
}
if ( ! V_134 && ! V_133 )
return 0 ;
if ( V_76 -> V_83 -> V_146 )
V_145 = F_55 ( V_76 ) ;
if ( V_76 -> V_83 -> V_147 && V_134 ) {
struct V_79 * V_80 ;
F_56 ( V_76 , V_82 -> V_103 , V_82 -> V_96 ) ;
F_57 ( V_76 , V_82 -> V_103 , V_82 -> V_96 ) ;
V_28 = F_58 ( V_76 , & V_80 ) ;
if ( V_28 )
return V_28 ;
F_35 ( & V_87 -> V_107 ) ;
F_30 ( V_70 -> V_99 ) ;
V_70 -> V_99 = V_80 ;
V_70 -> V_71 = F_23 ( & V_2 -> V_72 ) ;
F_36 ( & V_87 -> V_107 ) ;
}
if ( V_76 -> V_83 -> V_135 && V_133 ) {
V_70 -> V_136 = V_82 -> V_136 ;
V_70 -> V_137 = V_82 -> V_137 ;
V_70 -> V_138 = V_82 -> V_138 ;
V_70 -> V_139 = V_82 -> V_139 ;
V_70 -> V_140 = V_82 -> V_140 ;
V_70 -> V_141 = V_82 -> V_141 ;
F_59 ( V_76 , V_82 -> V_103 , V_82 -> V_136 ,
V_82 -> V_137 , V_82 -> V_138 ,
V_82 -> V_139 , V_82 -> V_140 ,
V_82 -> V_141 ) ;
}
if ( V_76 -> V_83 -> V_148 )
F_60 ( V_76 , V_145 ) ;
if ( V_76 -> V_83 -> V_149 ) {
F_61 ( V_76 ) ;
F_61 ( V_76 ) ;
}
return 0 ;
}
void F_62 ( struct V_1 * V_2 , unsigned V_73 ,
unsigned V_150 )
{
struct V_86 * V_87 = & V_2 -> V_4 . V_87 [ V_73 ] ;
struct V_69 * V_70 = & V_87 -> V_104 [ V_150 ] ;
F_32 ( & V_70 -> V_94 , 0 ) ;
V_70 -> V_136 = 0 ;
V_70 -> V_137 = 0 ;
V_70 -> V_138 = 0 ;
V_70 -> V_139 = 0 ;
V_70 -> V_140 = 0 ;
V_70 -> V_141 = 0 ;
}
void F_63 ( struct V_1 * V_2 )
{
unsigned V_27 , V_114 ;
for ( V_27 = 0 ; V_27 < V_151 ; ++ V_27 ) {
struct V_86 * V_87 =
& V_2 -> V_4 . V_87 [ V_27 ] ;
for ( V_114 = 1 ; V_114 < V_87 -> V_108 ; ++ V_114 )
F_62 ( V_2 , V_27 , V_114 ) ;
}
}
struct V_152 * F_64 ( struct V_8 * V_9 ,
struct V_25 * V_16 )
{
struct V_152 * V_153 ;
F_38 (bo_va, &bo->va, bo_list) {
if ( V_153 -> V_9 == V_9 ) {
return V_153 ;
}
}
return NULL ;
}
static void F_65 ( struct V_154 * V_155 ,
T_1 V_156 , T_1 V_62 ,
unsigned V_157 , T_3 V_158 ,
T_1 V_45 )
{
F_66 ( V_156 , V_62 , V_157 , V_158 , V_45 ) ;
if ( V_157 < 3 ) {
F_67 ( V_155 -> V_2 , V_155 -> V_159 , V_156 ,
V_62 | V_45 , V_157 , V_158 ) ;
} else {
F_68 ( V_155 -> V_2 , V_155 -> V_159 , V_156 , V_62 ,
V_157 , V_158 , V_45 ) ;
}
}
static void F_69 ( struct V_154 * V_155 ,
T_1 V_156 , T_1 V_62 ,
unsigned V_157 , T_3 V_158 ,
T_1 V_45 )
{
T_1 V_160 = ( V_155 -> V_160 + ( V_62 >> 12 ) * 8 ) ;
F_70 ( V_156 , V_160 , V_157 ) ;
F_71 ( V_155 -> V_2 , V_155 -> V_159 , V_156 , V_160 , V_157 ) ;
}
static T_1 F_72 ( const T_4 * V_161 , T_1 V_62 )
{
T_1 V_162 ;
V_162 = V_161 [ V_62 >> V_163 ] ;
V_162 |= V_62 & ( ~ V_164 ) ;
V_162 &= 0xFFFFFFFFFFFFF000ULL ;
return V_162 ;
}
static void F_73 ( struct V_154 * V_155 ,
T_1 V_156 , T_1 V_62 ,
unsigned V_157 , T_3 V_158 ,
T_1 V_45 )
{
unsigned int V_27 ;
T_1 V_165 ;
for ( V_27 = 0 ; V_27 < V_157 ; V_27 ++ ) {
V_165 = V_155 -> V_161 ?
F_72 ( V_155 -> V_161 , V_62 ) :
V_62 ;
F_74 ( V_155 -> V_2 , ( void * ) ( V_166 ) V_156 ,
V_27 , V_165 , V_45 ) ;
V_62 += V_158 ;
}
F_75 () ;
F_76 ( V_155 -> V_2 , 0 ) ;
}
static int F_77 ( struct V_1 * V_2 , struct V_25 * V_16 )
{
struct V_77 V_78 ;
int V_28 ;
F_78 ( & V_78 ) ;
F_79 ( V_2 , & V_78 , V_16 -> V_19 . V_58 , V_167 ) ;
V_28 = F_80 ( & V_78 , true ) ;
F_81 ( & V_78 ) ;
return V_28 ;
}
static int F_82 ( struct V_1 * V_2 ,
struct V_8 * V_9 ,
struct V_23 * V_24 ,
unsigned V_3 )
{
struct V_25 * V_168 ;
struct V_75 * V_76 = NULL ;
T_1 V_169 , V_170 = 0 ;
T_3 V_158 = F_3 ( V_2 , V_3 + 1 ) ;
T_1 V_171 = ~ 0 , V_172 = ~ 0 , V_173 = ~ 0 ;
unsigned V_157 = 0 , V_42 , V_174 = 0 ;
struct V_81 * V_82 ;
struct V_154 V_155 ;
struct V_79 * V_80 = NULL ;
int V_28 ;
if ( ! V_24 -> V_29 )
return 0 ;
memset ( & V_155 , 0 , sizeof( V_155 ) ) ;
V_155 . V_2 = V_2 ;
V_168 = V_24 -> V_16 -> V_168 ;
F_83 ( V_9 -> V_53 && V_168 ) ;
if ( V_9 -> V_53 && ! V_168 ) {
V_28 = F_84 ( V_24 -> V_16 , ( void * * ) & V_169 ) ;
if ( V_28 )
return V_28 ;
V_28 = F_77 ( V_2 , V_24 -> V_16 ) ;
if ( F_85 ( V_28 ) ) {
F_86 ( V_24 -> V_16 ) ;
return V_28 ;
}
V_155 . V_175 = F_73 ;
} else {
if ( V_168 ) {
V_28 = F_87 ( & V_168 -> V_19 , & V_168 -> V_19 . V_176 ) ;
if ( V_28 )
return V_28 ;
}
V_76 = F_88 ( V_9 -> V_177 . V_178 , struct V_75 ,
V_178 ) ;
V_174 = 64 ;
V_174 += V_24 -> V_30 * 6 ;
V_169 = F_89 ( V_24 -> V_16 ) ;
if ( V_168 ) {
V_170 = F_89 ( V_168 ) ;
V_174 *= 2 ;
} else {
V_170 = 0 ;
}
V_28 = F_90 ( V_2 , V_174 * 4 , & V_82 ) ;
if ( V_28 )
return V_28 ;
V_155 . V_159 = & V_82 -> V_179 [ 0 ] ;
V_155 . V_175 = F_65 ;
}
for ( V_42 = 0 ; V_42 <= V_24 -> V_30 ; ++ V_42 ) {
struct V_25 * V_16 = V_24 -> V_29 [ V_42 ] . V_16 ;
T_1 V_180 , V_59 ;
if ( V_16 == NULL )
continue;
if ( V_16 -> V_168 ) {
struct V_25 * V_181 = V_16 -> V_168 ;
V_28 = F_87 ( & V_181 -> V_19 ,
& V_181 -> V_19 . V_176 ) ;
if ( V_28 )
return V_28 ;
}
V_59 = F_89 ( V_16 ) ;
V_59 = F_91 ( V_2 , V_59 ) ;
if ( V_24 -> V_29 [ V_42 ] . V_62 == V_59 )
continue;
V_24 -> V_29 [ V_42 ] . V_62 = V_59 ;
V_180 = V_169 + V_42 * 8 ;
if ( ( ( V_171 + 8 * V_157 ) != V_180 ) ||
( ( V_172 + V_158 * V_157 ) != V_59 ) ||
( V_157 == V_182 ) ) {
if ( V_157 ) {
if ( V_168 )
V_155 . V_175 ( & V_155 ,
V_173 ,
V_172 , V_157 ,
V_158 ,
V_183 ) ;
V_155 . V_175 ( & V_155 , V_171 ,
V_172 , V_157 , V_158 ,
V_183 ) ;
}
V_157 = 1 ;
V_171 = V_180 ;
V_173 = V_170 + V_42 * 8 ;
V_172 = V_59 ;
} else {
++ V_157 ;
}
}
if ( V_157 ) {
if ( V_9 -> V_15 . V_16 -> V_168 )
V_155 . V_175 ( & V_155 , V_173 , V_172 ,
V_157 , V_158 , V_183 ) ;
V_155 . V_175 ( & V_155 , V_171 , V_172 ,
V_157 , V_158 , V_183 ) ;
}
if ( V_155 . V_175 == F_73 )
F_86 ( V_24 -> V_16 ) ;
else if ( V_155 . V_159 -> V_184 == 0 ) {
F_92 ( V_82 ) ;
} else {
F_93 ( V_76 , V_155 . V_159 ) ;
F_79 ( V_2 , & V_82 -> V_78 , V_24 -> V_16 -> V_19 . V_58 ,
V_167 ) ;
if ( V_168 )
F_79 ( V_2 , & V_82 -> V_78 , V_168 -> V_19 . V_58 ,
V_167 ) ;
F_83 ( V_155 . V_159 -> V_184 > V_174 ) ;
V_28 = F_94 ( V_82 , V_76 , & V_9 -> V_177 ,
V_167 , & V_80 ) ;
if ( V_28 )
goto V_185;
F_95 ( V_24 -> V_16 , V_80 , true ) ;
F_30 ( V_9 -> V_186 ) ;
V_9 -> V_186 = F_31 ( V_80 ) ;
F_30 ( V_80 ) ;
}
for ( V_42 = 0 ; V_42 <= V_24 -> V_30 ; ++ V_42 ) {
struct V_23 * V_13 = & V_24 -> V_29 [ V_42 ] ;
if ( ! V_13 -> V_16 )
continue;
V_28 = F_82 ( V_2 , V_9 , V_13 , V_3 + 1 ) ;
if ( V_28 )
return V_28 ;
}
return 0 ;
V_185:
F_92 ( V_82 ) ;
return V_28 ;
}
static void F_96 ( struct V_23 * V_24 )
{
unsigned V_42 ;
for ( V_42 = 0 ; V_42 <= V_24 -> V_30 ; ++ V_42 ) {
struct V_23 * V_13 = & V_24 -> V_29 [ V_42 ] ;
if ( ! V_13 -> V_16 )
continue;
V_13 -> V_62 = ~ 0ULL ;
F_96 ( V_13 ) ;
}
}
int F_97 ( struct V_1 * V_2 ,
struct V_8 * V_9 )
{
int V_28 ;
V_28 = F_82 ( V_2 , V_9 , & V_9 -> V_15 , 0 ) ;
if ( V_28 )
F_96 ( & V_9 -> V_15 ) ;
return V_28 ;
}
static struct V_25 * F_98 ( struct V_154 * V_31 ,
T_1 V_62 )
{
struct V_23 * V_13 = & V_31 -> V_9 -> V_15 ;
unsigned V_85 , V_3 = V_31 -> V_2 -> V_4 . V_7 ;
while ( V_13 -> V_29 ) {
V_85 = V_62 >> ( V_31 -> V_2 -> V_4 . V_6 * V_3 -- ) ;
V_85 %= F_99 ( V_13 -> V_16 ) / 8 ;
V_13 = & V_13 -> V_29 [ V_85 ] ;
}
if ( V_3 )
return NULL ;
return V_13 -> V_16 ;
}
static int F_100 ( struct V_154 * V_155 ,
T_1 V_187 , T_1 V_188 ,
T_1 V_189 , T_1 V_45 )
{
struct V_1 * V_2 = V_155 -> V_2 ;
const T_1 V_190 = F_2 ( V_2 ) - 1 ;
T_1 V_62 , V_191 ;
struct V_25 * V_59 ;
unsigned V_192 ;
int V_28 ;
bool V_193 = ( V_155 -> V_175 == F_73 ) ;
for ( V_62 = V_187 ; V_62 < V_188 ; V_62 += V_192 ) {
V_59 = F_98 ( V_155 , V_62 ) ;
if ( ! V_59 ) {
F_101 ( L_3 ) ;
return - V_50 ;
}
if ( V_155 -> V_168 ) {
if ( F_102 ( V_193 ,
L_4 ) )
return 0 ;
if ( ! V_59 -> V_168 )
return 0 ;
V_59 = V_59 -> V_168 ;
}
if ( ( V_62 & ~ V_190 ) == ( V_188 & ~ V_190 ) )
V_192 = V_188 - V_62 ;
else
V_192 = F_2 ( V_2 ) - ( V_62 & V_190 ) ;
if ( V_193 ) {
V_28 = F_84 ( V_59 , ( void * ) & V_191 ) ;
if ( V_28 )
return V_28 ;
} else
V_191 = F_89 ( V_59 ) ;
V_191 += ( V_62 & V_190 ) * 8 ;
V_155 -> V_175 ( V_155 , V_191 , V_189 , V_192 ,
V_60 , V_45 ) ;
V_189 += V_192 * V_60 ;
if ( V_193 )
F_86 ( V_59 ) ;
}
return 0 ;
}
static int F_103 ( struct V_154 * V_155 ,
T_1 V_187 , T_1 V_188 ,
T_1 V_189 , T_1 V_45 )
{
int V_28 ;
T_1 V_194 = F_104 ( V_195 ) ;
T_1 V_196 = 1 << V_195 ;
T_1 V_197 = F_105 ( V_187 , V_196 ) ;
T_1 V_198 = V_188 & ~ ( V_196 - 1 ) ;
if ( V_155 -> V_160 || ! ( V_45 & V_183 ) ||
( V_197 >= V_198 ) )
return F_100 ( V_155 , V_187 , V_188 , V_189 , V_45 ) ;
if ( V_187 != V_197 ) {
V_28 = F_100 ( V_155 , V_187 , V_197 ,
V_189 , V_45 ) ;
if ( V_28 )
return V_28 ;
V_189 += ( V_197 - V_187 ) * V_60 ;
}
V_28 = F_100 ( V_155 , V_197 , V_198 , V_189 ,
V_45 | V_194 ) ;
if ( V_28 )
return V_28 ;
if ( V_198 != V_188 ) {
V_189 += ( V_198 - V_197 ) * V_60 ;
V_28 = F_100 ( V_155 , V_198 , V_188 , V_189 , V_45 ) ;
}
return V_28 ;
}
static int F_106 ( struct V_1 * V_2 ,
struct V_79 * V_199 ,
T_1 V_160 ,
T_4 * V_161 ,
struct V_8 * V_9 ,
T_1 V_187 , T_1 V_200 ,
T_1 V_45 , T_1 V_62 ,
struct V_79 * * V_80 )
{
struct V_75 * V_76 ;
void * V_94 = V_167 ;
unsigned V_192 , V_201 , V_174 ;
struct V_81 * V_82 ;
struct V_154 V_155 ;
struct V_79 * V_202 = NULL ;
int V_28 ;
memset ( & V_155 , 0 , sizeof( V_155 ) ) ;
V_155 . V_2 = V_2 ;
V_155 . V_9 = V_9 ;
V_155 . V_160 = V_160 ;
if ( V_9 -> V_53 ) {
if ( V_161 )
V_155 . V_160 = ~ 0 ;
V_28 = F_77 ( V_2 , V_9 -> V_15 . V_16 ) ;
if ( F_85 ( V_28 ) )
return V_28 ;
V_155 . V_175 = F_73 ;
V_155 . V_161 = V_161 ;
V_155 . V_168 = false ;
return F_103 ( & V_155 , V_187 , V_200 + 1 ,
V_62 , V_45 ) ;
}
V_76 = F_88 ( V_9 -> V_177 . V_178 , struct V_75 , V_178 ) ;
if ( ! ( V_45 & V_183 ) )
V_94 = V_203 ;
V_192 = V_200 - V_187 + 1 ;
V_201 = ( V_192 >> F_107 ( V_2 -> V_4 . V_6 , 11u ) ) + 1 ;
V_174 = 64 ;
if ( V_160 ) {
V_174 += V_201 * 7 ;
V_155 . V_175 = F_69 ;
} else if ( V_161 ) {
V_174 += V_201 * 7 ;
V_174 += V_192 * 2 ;
V_155 . V_175 = F_69 ;
} else {
V_174 += V_201 * 10 ;
V_174 += 2 * 10 ;
V_155 . V_175 = F_65 ;
}
V_28 = F_90 ( V_2 , V_174 * 4 , & V_82 ) ;
if ( V_28 )
return V_28 ;
V_155 . V_159 = & V_82 -> V_179 [ 0 ] ;
if ( ! V_160 && V_161 ) {
T_1 * V_204 ;
unsigned V_27 ;
V_27 = V_174 - V_192 * 2 ;
V_204 = ( T_1 * ) & ( V_82 -> V_179 -> V_205 [ V_27 ] ) ;
V_155 . V_160 = V_82 -> V_179 -> V_206 + V_27 * 4 ;
for ( V_27 = 0 ; V_27 < V_192 ; ++ V_27 ) {
V_204 [ V_27 ] = F_72 ( V_161 , V_62 + V_27 *
V_60 ) ;
V_204 [ V_27 ] |= V_45 ;
}
V_62 = 0 ;
}
V_28 = F_29 ( V_2 , & V_82 -> V_78 , V_199 ) ;
if ( V_28 )
goto V_185;
V_28 = F_79 ( V_2 , & V_82 -> V_78 , V_9 -> V_15 . V_16 -> V_19 . V_58 ,
V_94 ) ;
if ( V_28 )
goto V_185;
V_28 = F_108 ( V_9 -> V_15 . V_16 -> V_19 . V_58 ) ;
if ( V_28 )
goto V_185;
V_155 . V_168 = true ;
V_28 = F_103 ( & V_155 , V_187 , V_200 + 1 , V_62 , V_45 ) ;
if ( V_28 )
goto V_185;
V_155 . V_168 = false ;
V_28 = F_103 ( & V_155 , V_187 , V_200 + 1 , V_62 , V_45 ) ;
if ( V_28 )
goto V_185;
F_93 ( V_76 , V_155 . V_159 ) ;
F_83 ( V_155 . V_159 -> V_184 > V_174 ) ;
V_28 = F_94 ( V_82 , V_76 , & V_9 -> V_177 ,
V_167 , & V_202 ) ;
if ( V_28 )
goto V_185;
F_95 ( V_9 -> V_15 . V_16 , V_202 , true ) ;
F_30 ( * V_80 ) ;
* V_80 = V_202 ;
return 0 ;
V_185:
F_92 ( V_82 ) ;
return V_28 ;
}
static int F_109 ( struct V_1 * V_2 ,
struct V_79 * V_199 ,
T_1 V_207 ,
T_4 * V_161 ,
struct V_8 * V_9 ,
struct V_208 * V_209 ,
T_1 V_45 ,
struct V_210 * V_211 ,
struct V_79 * * V_80 )
{
T_1 V_212 , V_160 = 0 , V_187 = V_209 -> V_187 ;
int V_28 ;
if ( ! ( V_209 -> V_45 & V_213 ) )
V_45 &= ~ V_213 ;
if ( ! ( V_209 -> V_45 & V_214 ) )
V_45 &= ~ V_214 ;
V_45 &= ~ V_215 ;
V_45 |= V_209 -> V_45 & V_215 ;
V_45 &= ~ V_216 ;
V_45 |= ( V_209 -> V_45 & V_216 ) ;
if ( ( V_209 -> V_45 & V_217 ) &&
( V_2 -> V_116 >= V_117 ) ) {
V_45 |= V_217 ;
V_45 &= ~ V_183 ;
}
F_110 ( V_209 ) ;
V_212 = V_209 -> V_218 >> V_163 ;
if ( V_211 ) {
while ( V_212 >= V_211 -> V_65 ) {
V_212 -= V_211 -> V_65 ;
++ V_211 ;
}
}
do {
T_1 V_219 ;
T_1 V_62 , V_200 ;
if ( V_211 ) {
V_62 = V_211 -> V_187 << V_163 ;
V_219 = ( V_211 -> V_65 - V_212 ) *
( V_220 / V_60 ) ;
} else {
V_62 = 0 ;
V_219 = V_221 ;
}
if ( V_161 ) {
if ( V_45 == V_207 )
V_160 = V_2 -> V_222 . V_223 +
( V_62 >> V_224 ) * 8 ;
else
V_219 = F_107 ( V_219 , 16ull * 1024ull ) ;
V_62 = 0 ;
} else if ( V_45 & V_183 ) {
V_62 += V_2 -> V_4 . V_225 ;
}
V_62 += V_212 << V_163 ;
V_200 = F_107 ( ( T_1 ) V_209 -> V_200 , V_187 + V_219 - 1 ) ;
V_28 = F_106 ( V_2 , V_199 ,
V_160 , V_161 , V_9 ,
V_187 , V_200 , V_45 , V_62 ,
V_80 ) ;
if ( V_28 )
return V_28 ;
V_212 += V_200 - V_187 + 1 ;
if ( V_211 && V_211 -> V_65 == V_212 ) {
V_212 = 0 ;
++ V_211 ;
}
V_187 = V_200 + 1 ;
} while ( F_85 ( V_187 != V_209 -> V_200 + 1 ) );
return 0 ;
}
int F_111 ( struct V_1 * V_2 ,
struct V_152 * V_153 ,
bool V_226 )
{
struct V_8 * V_9 = V_153 -> V_9 ;
struct V_208 * V_209 ;
T_4 * V_161 = NULL ;
T_1 V_207 , V_45 ;
struct V_227 * V_176 ;
struct V_210 * V_211 ;
struct V_79 * V_199 ;
int V_28 ;
if ( V_226 || ! V_153 -> V_16 ) {
V_176 = NULL ;
V_211 = NULL ;
V_199 = NULL ;
} else {
struct V_228 * V_229 ;
V_176 = & V_153 -> V_16 -> V_19 . V_176 ;
V_211 = V_176 -> V_230 ;
if ( V_176 -> V_231 == V_232 ) {
V_229 = F_88 ( V_153 -> V_16 -> V_19 . V_229 , struct
V_228 , V_229 ) ;
V_161 = V_229 -> V_233 ;
}
V_199 = F_112 ( V_153 -> V_16 -> V_19 . V_58 ) ;
}
if ( V_153 -> V_16 ) {
V_45 = F_113 ( V_2 , V_153 -> V_16 -> V_19 . V_229 , V_176 ) ;
V_207 = ( F_114 ( V_153 -> V_16 -> V_19 . V_229 ) &&
V_2 == F_115 ( V_153 -> V_16 -> V_19 . V_37 ) ) ?
V_45 : 0 ;
} else {
V_45 = 0x0 ;
V_207 = ~ 0x0 ;
}
F_14 ( & V_9 -> V_234 ) ;
if ( ! F_116 ( & V_153 -> V_235 ) )
F_117 ( & V_153 -> V_236 , & V_153 -> V_237 ) ;
F_15 ( & V_9 -> V_234 ) ;
F_38 (mapping, &bo_va->invalids, list) {
V_28 = F_109 ( V_2 , V_199 ,
V_207 , V_161 , V_9 ,
V_209 , V_45 , V_211 ,
& V_153 -> V_238 ) ;
if ( V_28 )
return V_28 ;
}
if ( F_118 () ) {
F_38 (mapping, &bo_va->valids, list)
F_119 ( V_209 ) ;
F_38 (mapping, &bo_va->invalids, list)
F_119 ( V_209 ) ;
}
F_14 ( & V_9 -> V_234 ) ;
F_117 ( & V_153 -> V_237 , & V_153 -> V_236 ) ;
F_49 ( & V_153 -> V_235 ) ;
if ( V_226 )
F_6 ( & V_153 -> V_235 , & V_9 -> V_239 ) ;
F_15 ( & V_9 -> V_234 ) ;
return 0 ;
}
static void F_120 ( struct V_1 * V_2 )
{
unsigned long V_45 ;
bool V_240 ;
F_121 ( & V_2 -> V_4 . V_241 , V_45 ) ;
V_240 = ! ! F_23 ( & V_2 -> V_4 . V_242 ) ;
V_2 -> V_222 . V_243 -> V_244 ( V_2 , V_240 ) ;
F_122 ( & V_2 -> V_4 . V_241 , V_45 ) ;
}
static void F_123 ( struct V_1 * V_2 )
{
if ( ! V_2 -> V_222 . V_243 -> V_244 )
return;
if ( F_46 ( & V_2 -> V_4 . V_242 ) == 1 )
F_120 ( V_2 ) ;
}
static void F_124 ( struct V_1 * V_2 )
{
if ( F_125 ( & V_2 -> V_4 . V_242 ) == 0 )
F_120 ( V_2 ) ;
}
static void F_126 ( struct V_79 * V_80 , struct V_245 * V_246 )
{
struct V_247 * V_248 = F_88 ( V_246 , struct V_247 , V_248 ) ;
F_124 ( V_248 -> V_2 ) ;
F_40 ( V_248 ) ;
}
static void F_127 ( struct V_1 * V_2 ,
struct V_79 * V_80 )
{
struct V_247 * V_248 ;
if ( ! V_2 -> V_222 . V_243 -> V_244 )
return;
V_248 = F_128 ( sizeof( struct V_247 ) , V_47 ) ;
if ( ! V_248 ) {
if ( V_80 )
F_129 ( V_80 , false ) ;
F_124 ( V_2 ) ;
} else {
V_248 -> V_2 = V_2 ;
if ( ! V_80 || F_130 ( V_80 , & V_248 -> V_248 ,
F_126 ) )
F_126 ( V_80 , & V_248 -> V_248 ) ;
}
}
static void F_131 ( struct V_1 * V_2 ,
struct V_8 * V_9 ,
struct V_208 * V_209 ,
struct V_79 * V_80 )
{
if ( V_209 -> V_45 & V_217 )
F_127 ( V_2 , V_80 ) ;
F_40 ( V_209 ) ;
}
static void F_132 ( struct V_1 * V_2 , struct V_8 * V_9 )
{
struct V_57 * V_58 = V_9 -> V_15 . V_16 -> V_19 . V_58 ;
struct V_79 * V_249 , * * V_20 ;
unsigned V_27 , V_250 ;
int V_28 ;
V_28 = F_133 ( V_58 , & V_249 ,
& V_250 , & V_20 ) ;
if ( V_28 ) {
F_134 ( V_58 , true , false ,
V_251 ) ;
return;
}
F_123 ( V_2 ) ;
F_127 ( V_2 , V_249 ) ;
for ( V_27 = 0 ; V_27 < V_250 ; ++ V_27 ) {
F_123 ( V_2 ) ;
F_127 ( V_2 , V_20 [ V_27 ] ) ;
}
F_40 ( V_20 ) ;
}
int F_135 ( struct V_1 * V_2 ,
struct V_8 * V_9 ,
struct V_79 * * V_80 )
{
struct V_208 * V_209 ;
struct V_79 * V_202 = NULL ;
int V_28 ;
while ( ! F_116 ( & V_9 -> V_252 ) ) {
V_209 = F_48 ( & V_9 -> V_252 ,
struct V_208 , V_109 ) ;
F_136 ( & V_209 -> V_109 ) ;
V_28 = F_106 ( V_2 , NULL , 0 , NULL , V_9 ,
V_209 -> V_187 , V_209 -> V_200 ,
0 , 0 , & V_202 ) ;
F_131 ( V_2 , V_9 , V_209 , V_202 ) ;
if ( V_28 ) {
F_30 ( V_202 ) ;
return V_28 ;
}
}
if ( V_80 && V_202 ) {
F_30 ( * V_80 ) ;
* V_80 = V_202 ;
} else {
F_30 ( V_202 ) ;
}
return 0 ;
}
int F_137 ( struct V_1 * V_2 ,
struct V_8 * V_9 , struct V_77 * V_78 )
{
struct V_152 * V_153 = NULL ;
int V_28 = 0 ;
F_14 ( & V_9 -> V_234 ) ;
while ( ! F_116 ( & V_9 -> V_253 ) ) {
V_153 = F_48 ( & V_9 -> V_253 ,
struct V_152 , V_235 ) ;
F_15 ( & V_9 -> V_234 ) ;
V_28 = F_111 ( V_2 , V_153 , true ) ;
if ( V_28 )
return V_28 ;
F_14 ( & V_9 -> V_234 ) ;
}
F_15 ( & V_9 -> V_234 ) ;
if ( V_153 )
V_28 = F_29 ( V_2 , V_78 , V_153 -> V_238 ) ;
return V_28 ;
}
struct V_152 * F_138 ( struct V_1 * V_2 ,
struct V_8 * V_9 ,
struct V_25 * V_16 )
{
struct V_152 * V_153 ;
V_153 = F_139 ( sizeof( struct V_152 ) , V_47 ) ;
if ( V_153 == NULL ) {
return NULL ;
}
V_153 -> V_9 = V_9 ;
V_153 -> V_16 = V_16 ;
V_153 -> V_254 = 1 ;
F_140 ( & V_153 -> V_255 ) ;
F_140 ( & V_153 -> V_236 ) ;
F_140 ( & V_153 -> V_237 ) ;
F_140 ( & V_153 -> V_235 ) ;
if ( V_16 )
F_141 ( & V_153 -> V_255 , & V_16 -> V_256 ) ;
return V_153 ;
}
int F_142 ( struct V_1 * V_2 ,
struct V_152 * V_153 ,
T_1 V_39 , T_1 V_218 ,
T_1 V_65 , T_1 V_45 )
{
struct V_208 * V_209 , * V_91 ;
struct V_8 * V_9 = V_153 -> V_9 ;
T_1 V_40 ;
if ( V_39 & V_67 || V_218 & V_67 ||
V_65 == 0 || V_65 & V_67 )
return - V_50 ;
V_40 = V_39 + V_65 - 1 ;
if ( V_39 >= V_40 ||
( V_153 -> V_16 && V_218 + V_65 > F_99 ( V_153 -> V_16 ) ) )
return - V_50 ;
V_39 /= V_60 ;
V_40 /= V_60 ;
V_91 = F_143 ( & V_9 -> V_256 , V_39 , V_40 ) ;
if ( V_91 ) {
F_21 ( V_2 -> V_68 , L_5
L_6 , V_153 -> V_16 , V_39 , V_40 ,
V_91 -> V_187 , V_91 -> V_200 + 1 ) ;
return - V_50 ;
}
V_209 = F_128 ( sizeof( * V_209 ) , V_47 ) ;
if ( ! V_209 )
return - V_49 ;
F_140 ( & V_209 -> V_109 ) ;
V_209 -> V_187 = V_39 ;
V_209 -> V_200 = V_40 ;
V_209 -> V_218 = V_218 ;
V_209 -> V_45 = V_45 ;
F_6 ( & V_209 -> V_109 , & V_153 -> V_237 ) ;
F_144 ( V_209 , & V_9 -> V_256 ) ;
if ( V_45 & V_217 )
F_123 ( V_2 ) ;
return 0 ;
}
int F_145 ( struct V_1 * V_2 ,
struct V_152 * V_153 ,
T_1 V_39 , T_1 V_218 ,
T_1 V_65 , T_1 V_45 )
{
struct V_208 * V_209 ;
struct V_8 * V_9 = V_153 -> V_9 ;
T_1 V_40 ;
int V_28 ;
if ( V_39 & V_67 || V_218 & V_67 ||
V_65 == 0 || V_65 & V_67 )
return - V_50 ;
V_40 = V_39 + V_65 - 1 ;
if ( V_39 >= V_40 ||
( V_153 -> V_16 && V_218 + V_65 > F_99 ( V_153 -> V_16 ) ) )
return - V_50 ;
V_209 = F_128 ( sizeof( * V_209 ) , V_47 ) ;
if ( ! V_209 )
return - V_49 ;
V_28 = F_146 ( V_2 , V_153 -> V_9 , V_39 , V_65 ) ;
if ( V_28 ) {
F_40 ( V_209 ) ;
return V_28 ;
}
V_39 /= V_60 ;
V_40 /= V_60 ;
V_209 -> V_187 = V_39 ;
V_209 -> V_200 = V_40 ;
V_209 -> V_218 = V_218 ;
V_209 -> V_45 = V_45 ;
F_6 ( & V_209 -> V_109 , & V_153 -> V_237 ) ;
F_144 ( V_209 , & V_9 -> V_256 ) ;
if ( V_45 & V_217 )
F_123 ( V_2 ) ;
return 0 ;
}
int F_147 ( struct V_1 * V_2 ,
struct V_152 * V_153 ,
T_1 V_39 )
{
struct V_208 * V_209 ;
struct V_8 * V_9 = V_153 -> V_9 ;
bool V_257 = true ;
V_39 /= V_60 ;
F_38 (mapping, &bo_va->valids, list) {
if ( V_209 -> V_187 == V_39 )
break;
}
if ( & V_209 -> V_109 == & V_153 -> V_236 ) {
V_257 = false ;
F_38 (mapping, &bo_va->invalids, list) {
if ( V_209 -> V_187 == V_39 )
break;
}
if ( & V_209 -> V_109 == & V_153 -> V_237 )
return - V_258 ;
}
F_136 ( & V_209 -> V_109 ) ;
F_148 ( V_209 , & V_9 -> V_256 ) ;
F_149 ( V_153 , V_209 ) ;
if ( V_257 )
F_6 ( & V_209 -> V_109 , & V_9 -> V_252 ) ;
else
F_131 ( V_2 , V_9 , V_209 ,
V_153 -> V_238 ) ;
return 0 ;
}
int F_146 ( struct V_1 * V_2 ,
struct V_8 * V_9 ,
T_1 V_39 , T_1 V_65 )
{
struct V_208 * V_259 , * V_260 , * V_91 , * V_261 ;
F_150 ( V_262 ) ;
T_1 V_40 ;
V_40 = V_39 + V_65 - 1 ;
V_39 /= V_60 ;
V_40 /= V_60 ;
V_259 = F_139 ( sizeof( * V_259 ) , V_47 ) ;
if ( ! V_259 )
return - V_49 ;
F_140 ( & V_259 -> V_109 ) ;
V_260 = F_139 ( sizeof( * V_260 ) , V_47 ) ;
if ( ! V_260 ) {
F_40 ( V_259 ) ;
return - V_49 ;
}
F_140 ( & V_260 -> V_109 ) ;
V_91 = F_143 ( & V_9 -> V_256 , V_39 , V_40 ) ;
while ( V_91 ) {
if ( V_91 -> V_187 < V_39 ) {
V_259 -> V_187 = V_91 -> V_187 ;
V_259 -> V_200 = V_39 - 1 ;
V_259 -> V_218 = V_91 -> V_218 ;
V_259 -> V_45 = V_91 -> V_45 ;
F_6 ( & V_259 -> V_109 , & V_91 -> V_109 ) ;
}
if ( V_91 -> V_200 > V_40 ) {
V_260 -> V_187 = V_40 + 1 ;
V_260 -> V_200 = V_91 -> V_200 ;
V_260 -> V_218 = V_91 -> V_218 ;
V_260 -> V_218 += V_260 -> V_187 - V_91 -> V_187 ;
V_260 -> V_45 = V_91 -> V_45 ;
F_6 ( & V_260 -> V_109 , & V_91 -> V_109 ) ;
}
F_136 ( & V_91 -> V_109 ) ;
F_6 ( & V_91 -> V_109 , & V_262 ) ;
V_91 = F_151 ( V_91 , V_39 , V_40 ) ;
}
F_152 (tmp, next, &removed, list) {
F_148 ( V_91 , & V_9 -> V_256 ) ;
F_136 ( & V_91 -> V_109 ) ;
if ( V_91 -> V_187 < V_39 )
V_91 -> V_187 = V_39 ;
if ( V_91 -> V_200 > V_40 )
V_91 -> V_200 = V_40 ;
F_6 ( & V_91 -> V_109 , & V_9 -> V_252 ) ;
F_149 ( NULL , V_91 ) ;
}
if ( ! F_116 ( & V_259 -> V_109 ) ) {
F_144 ( V_259 , & V_9 -> V_256 ) ;
if ( V_259 -> V_45 & V_217 )
F_123 ( V_2 ) ;
} else {
F_40 ( V_259 ) ;
}
if ( ! F_116 ( & V_260 -> V_109 ) ) {
F_144 ( V_260 , & V_9 -> V_256 ) ;
if ( V_260 -> V_45 & V_217 )
F_123 ( V_2 ) ;
} else {
F_40 ( V_260 ) ;
}
return 0 ;
}
void F_153 ( struct V_1 * V_2 ,
struct V_152 * V_153 )
{
struct V_208 * V_209 , * V_261 ;
struct V_8 * V_9 = V_153 -> V_9 ;
F_136 ( & V_153 -> V_255 ) ;
F_14 ( & V_9 -> V_234 ) ;
F_136 ( & V_153 -> V_235 ) ;
F_15 ( & V_9 -> V_234 ) ;
F_152 (mapping, next, &bo_va->valids, list) {
F_136 ( & V_209 -> V_109 ) ;
F_148 ( V_209 , & V_9 -> V_256 ) ;
F_149 ( V_153 , V_209 ) ;
F_6 ( & V_209 -> V_109 , & V_9 -> V_252 ) ;
}
F_152 (mapping, next, &bo_va->invalids, list) {
F_136 ( & V_209 -> V_109 ) ;
F_148 ( V_209 , & V_9 -> V_256 ) ;
F_131 ( V_2 , V_9 , V_209 ,
V_153 -> V_238 ) ;
}
F_30 ( V_153 -> V_238 ) ;
F_40 ( V_153 ) ;
}
void F_154 ( struct V_1 * V_2 ,
struct V_25 * V_16 )
{
struct V_152 * V_153 ;
F_38 (bo_va, &bo->va, bo_list) {
F_14 ( & V_153 -> V_9 -> V_234 ) ;
if ( F_116 ( & V_153 -> V_235 ) )
F_6 ( & V_153 -> V_235 , & V_153 -> V_9 -> V_253 ) ;
F_15 ( & V_153 -> V_9 -> V_234 ) ;
}
}
static T_3 F_155 ( T_1 V_263 )
{
unsigned V_264 = F_156 ( V_263 ) + 18 ;
if ( V_263 <= 8 )
return ( V_264 - 9 ) ;
else
return ( ( V_264 + 3 ) / 2 ) ;
}
void F_157 ( struct V_1 * V_2 , T_1 V_263 )
{
if ( V_265 == - 1 )
V_2 -> V_4 . V_263 = V_263 ;
else
V_2 -> V_4 . V_263 = V_265 ;
if ( V_266 == - 1 )
V_2 -> V_4 . V_6 =
F_155 ( V_2 -> V_4 . V_263 ) ;
else
V_2 -> V_4 . V_6 = V_266 ;
F_158 ( L_7 ,
V_2 -> V_4 . V_263 , V_2 -> V_4 . V_6 ) ;
}
int F_159 ( struct V_1 * V_2 , struct V_8 * V_9 ,
int V_267 )
{
const unsigned V_268 = F_107 ( V_269 ,
F_2 ( V_2 ) * 8 ) ;
unsigned V_270 ;
struct V_75 * V_76 ;
struct V_271 * V_272 ;
int V_28 , V_27 ;
T_2 V_45 ;
V_9 -> V_256 = V_273 ;
V_9 -> V_95 = F_160 ( & V_2 -> V_4 . V_274 ) ;
for ( V_27 = 0 ; V_27 < V_151 ; V_27 ++ )
V_9 -> V_74 [ V_27 ] = NULL ;
F_161 ( & V_9 -> V_234 ) ;
F_140 ( & V_9 -> V_253 ) ;
F_140 ( & V_9 -> V_239 ) ;
F_140 ( & V_9 -> V_252 ) ;
V_270 = F_46 ( & V_2 -> V_4 . V_275 ) ;
V_270 %= V_2 -> V_4 . V_276 ;
V_76 = V_2 -> V_4 . V_277 [ V_270 ] ;
V_272 = & V_76 -> V_178 . V_278 [ V_279 ] ;
V_28 = F_162 ( & V_76 -> V_178 , & V_9 -> V_177 ,
V_272 , V_280 ) ;
if ( V_28 )
return V_28 ;
if ( V_267 == V_281 )
V_9 -> V_53 = ! ! ( V_2 -> V_4 . V_282 &
V_283 ) ;
else
V_9 -> V_53 = ! ! ( V_2 -> V_4 . V_282 &
V_284 ) ;
F_163 ( L_8 ,
V_9 -> V_53 ? L_9 : L_10 ) ;
F_102 ( ( V_9 -> V_53 & ! F_53 ( V_2 ) ) ,
L_11 ) ;
V_9 -> V_186 = NULL ;
V_45 = V_51 |
V_52 ;
if ( V_9 -> V_53 )
V_45 |= V_54 ;
else
V_45 |= ( V_55 |
V_56 ) ;
V_28 = F_18 ( V_2 , F_3 ( V_2 , 0 ) , V_268 , true ,
V_61 ,
V_45 ,
NULL , NULL , & V_9 -> V_15 . V_16 ) ;
if ( V_28 )
goto V_285;
V_28 = F_164 ( V_9 -> V_15 . V_16 , false ) ;
if ( V_28 )
goto V_286;
V_9 -> V_33 = F_10 ( & V_2 -> V_32 ) ;
F_165 ( V_9 -> V_15 . V_16 ) ;
return 0 ;
V_286:
F_166 ( & V_9 -> V_15 . V_16 -> V_168 ) ;
F_166 ( & V_9 -> V_15 . V_16 ) ;
V_9 -> V_15 . V_16 = NULL ;
V_285:
F_167 ( & V_76 -> V_178 , & V_9 -> V_177 ) ;
return V_28 ;
}
static void F_168 ( struct V_23 * V_3 )
{
unsigned V_27 ;
if ( V_3 -> V_16 ) {
F_166 ( & V_3 -> V_16 -> V_168 ) ;
F_166 ( & V_3 -> V_16 ) ;
}
if ( V_3 -> V_29 )
for ( V_27 = 0 ; V_27 <= V_3 -> V_30 ; V_27 ++ )
F_168 ( & V_3 -> V_29 [ V_27 ] ) ;
F_169 ( V_3 -> V_29 ) ;
}
void F_170 ( struct V_1 * V_2 , struct V_8 * V_9 )
{
struct V_208 * V_209 , * V_91 ;
bool V_287 = ! ! V_2 -> V_222 . V_243 -> V_244 ;
int V_27 ;
F_167 ( V_9 -> V_177 . V_178 , & V_9 -> V_177 ) ;
if ( ! F_171 ( & V_9 -> V_256 ) ) {
F_21 ( V_2 -> V_68 , L_12 ) ;
}
F_172 (mapping, tmp, &vm->va, rb) {
F_136 ( & V_209 -> V_109 ) ;
F_148 ( V_209 , & V_9 -> V_256 ) ;
F_40 ( V_209 ) ;
}
F_152 (mapping, tmp, &vm->freed, list) {
if ( V_209 -> V_45 & V_217 && V_287 ) {
F_132 ( V_2 , V_9 ) ;
V_287 = false ;
}
F_136 ( & V_209 -> V_109 ) ;
F_131 ( V_2 , V_9 , V_209 , NULL ) ;
}
F_168 ( & V_9 -> V_15 ) ;
F_30 ( V_9 -> V_186 ) ;
for ( V_27 = 0 ; V_27 < V_151 ; V_27 ++ )
F_43 ( V_2 , V_9 , V_27 ) ;
}
void F_173 ( struct V_1 * V_2 )
{
unsigned V_27 , V_114 ;
for ( V_27 = 0 ; V_27 < V_151 ; ++ V_27 ) {
struct V_86 * V_87 =
& V_2 -> V_4 . V_87 [ V_27 ] ;
F_174 ( & V_87 -> V_107 ) ;
F_140 ( & V_87 -> V_110 ) ;
F_175 ( & V_87 -> V_119 , 0 ) ;
for ( V_114 = 1 ; V_114 < V_87 -> V_108 ; ++ V_114 ) {
F_62 ( V_2 , V_27 , V_114 ) ;
F_78 ( & V_87 -> V_104 [ V_27 ] . V_100 ) ;
F_141 ( & V_87 -> V_104 [ V_114 ] . V_109 , & V_87 -> V_110 ) ;
}
}
V_2 -> V_4 . V_84 =
F_176 ( V_288 ) ;
for ( V_27 = 0 ; V_27 < V_288 ; ++ V_27 )
V_2 -> V_4 . V_111 [ V_27 ] = 0 ;
F_175 ( & V_2 -> V_4 . V_275 , 0 ) ;
F_32 ( & V_2 -> V_4 . V_274 , 0 ) ;
F_161 ( & V_2 -> V_4 . V_241 ) ;
F_175 ( & V_2 -> V_4 . V_242 , 0 ) ;
#ifdef F_177
if ( V_289 == - 1 ) {
if ( F_53 ( V_2 ) )
V_2 -> V_4 . V_282 =
V_283 ;
else
V_2 -> V_4 . V_282 = 0 ;
} else
V_2 -> V_4 . V_282 = V_289 ;
#else
V_2 -> V_4 . V_282 = 0 ;
#endif
}
void F_178 ( struct V_1 * V_2 )
{
unsigned V_27 , V_114 ;
for ( V_27 = 0 ; V_27 < V_151 ; ++ V_27 ) {
struct V_86 * V_87 =
& V_2 -> V_4 . V_87 [ V_27 ] ;
F_179 ( & V_87 -> V_107 ) ;
for ( V_114 = 0 ; V_114 < V_290 ; ++ V_114 ) {
struct V_69 * V_70 = & V_87 -> V_104 [ V_114 ] ;
F_81 ( & V_70 -> V_100 ) ;
F_30 ( V_70 -> V_93 ) ;
F_30 ( V_70 -> V_99 ) ;
}
}
}
int F_180 ( struct V_291 * V_68 , void * V_292 , struct V_293 * V_294 )
{
union V_295 * args = V_292 ;
struct V_1 * V_2 = V_68 -> V_296 ;
struct V_297 * V_298 = V_294 -> V_299 ;
int V_28 ;
switch ( args -> V_300 . V_301 ) {
case V_302 :
V_28 = F_45 ( V_2 , & V_298 -> V_9 ,
V_303 ) ;
if ( V_28 )
return V_28 ;
break;
case V_304 :
F_43 ( V_2 , & V_298 -> V_9 , V_303 ) ;
break;
default:
return - V_50 ;
}
return 0 ;
}
