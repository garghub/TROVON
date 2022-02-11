static unsigned F_1 ( struct V_1 * V_2 )
{
return V_2 -> V_3 . V_4 >> V_5 ;
}
static unsigned F_2 ( struct V_1 * V_2 )
{
return F_3 ( F_1 ( V_2 ) * 8 ) ;
}
void F_4 ( struct V_6 * V_7 ,
struct V_8 * V_9 ,
struct V_10 * V_11 )
{
V_11 -> V_12 = V_7 -> V_13 ;
V_11 -> V_14 = 0 ;
V_11 -> V_15 . V_16 = & V_7 -> V_13 -> V_17 ;
V_11 -> V_15 . V_18 = true ;
V_11 -> V_19 = NULL ;
F_5 ( & V_11 -> V_15 . V_20 , V_9 ) ;
}
void F_6 ( struct V_1 * V_2 , struct V_6 * V_7 ,
struct V_8 * V_21 )
{
T_1 V_22 ;
unsigned V_23 ;
V_22 = F_7 ( & V_2 -> V_22 ) ;
if ( V_22 == V_7 -> V_24 )
return;
for ( V_23 = 0 ; V_23 <= V_7 -> V_25 ; ++ V_23 ) {
struct V_10 * V_11 = & V_7 -> V_26 [ V_23 ] . V_11 ;
if ( ! V_11 -> V_12 )
continue;
F_5 ( & V_11 -> V_15 . V_20 , V_21 ) ;
}
}
void F_8 ( struct V_1 * V_2 ,
struct V_6 * V_7 )
{
struct V_27 * V_28 = V_2 -> V_29 . V_30 . V_28 ;
unsigned V_23 ;
F_9 ( & V_28 -> V_31 ) ;
for ( V_23 = 0 ; V_23 <= V_7 -> V_25 ; ++ V_23 ) {
struct V_10 * V_11 = & V_7 -> V_26 [ V_23 ] . V_11 ;
if ( ! V_11 -> V_12 )
continue;
F_10 ( & V_11 -> V_12 -> V_17 ) ;
}
F_11 ( & V_28 -> V_31 ) ;
}
static bool F_12 ( struct V_1 * V_2 ,
struct V_32 * V_33 )
{
return V_33 -> V_34 !=
F_13 ( & V_2 -> V_35 ) ? true : false ;
}
int F_14 ( struct V_6 * V_7 , struct V_36 * V_37 ,
struct V_38 * V_39 , struct V_40 * V_40 ,
struct V_41 * V_42 )
{
struct V_1 * V_2 = V_37 -> V_2 ;
T_1 V_43 = V_2 -> V_43 + V_37 -> V_44 ;
struct V_40 * V_45 = V_39 -> V_46 ;
struct V_32 * V_33 , * V_47 ;
struct V_40 * * V_48 ;
unsigned V_23 ;
int V_49 = 0 ;
V_48 = F_15 ( sizeof( void * ) , V_2 -> V_3 . V_50 ,
V_51 ) ;
if ( ! V_48 )
return - V_52 ;
F_16 ( & V_2 -> V_3 . V_53 ) ;
V_23 = 0 ;
F_17 (idle, &adev->vm_manager.ids_lru, list) {
V_48 [ V_23 ] = F_18 ( & V_47 -> V_54 , V_37 ) ;
if ( ! V_48 [ V_23 ] )
break;
++ V_23 ;
}
if ( & V_47 -> V_55 == & V_2 -> V_3 . V_56 ) {
T_2 V_43 = V_2 -> V_3 . V_43 + V_37 -> V_44 ;
unsigned V_57 = ++ V_2 -> V_3 . V_57 [ V_37 -> V_44 ] ;
struct V_58 * V_59 ;
unsigned V_60 ;
for ( V_60 = 0 ; V_60 < V_23 ; ++ V_60 )
F_19 ( V_48 [ V_60 ] ) ;
V_59 = F_20 ( V_23 , V_48 , V_43 ,
V_57 , true ) ;
if ( ! V_59 ) {
for ( V_60 = 0 ; V_60 < V_23 ; ++ V_60 )
F_21 ( V_48 [ V_60 ] ) ;
F_22 ( V_48 ) ;
V_49 = - V_52 ;
goto error;
}
V_49 = F_23 ( V_37 -> V_2 , V_39 , & V_59 -> V_61 ) ;
F_21 ( & V_59 -> V_61 ) ;
if ( V_49 )
goto error;
F_24 ( & V_2 -> V_3 . V_53 ) ;
return 0 ;
}
F_22 ( V_48 ) ;
V_42 -> V_62 = true ;
V_23 = V_37 -> V_44 ;
do {
struct V_40 * V_63 ;
V_33 = V_7 -> V_64 [ V_23 ++ ] ;
if ( V_23 == V_65 )
V_23 = 0 ;
if ( ! V_33 )
continue;
if ( F_12 ( V_2 , V_33 ) )
continue;
if ( F_7 ( & V_33 -> V_66 ) != V_7 -> V_67 )
continue;
if ( V_42 -> V_68 != V_33 -> V_69 )
continue;
if ( ! V_33 -> V_70 )
continue;
if ( V_33 -> V_70 -> V_71 != V_43 &&
! F_25 ( V_33 -> V_70 ) )
continue;
V_63 = V_33 -> V_72 ;
if ( V_45 &&
( ! V_63 || F_26 ( V_45 , V_63 ) ) )
continue;
V_49 = F_23 ( V_37 -> V_2 , & V_33 -> V_54 , V_40 ) ;
if ( V_49 )
goto error;
V_33 -> V_34 = F_13 ( & V_2 -> V_35 ) ;
F_27 ( & V_33 -> V_55 , & V_2 -> V_3 . V_56 ) ;
V_7 -> V_64 [ V_37 -> V_44 ] = V_33 ;
V_42 -> V_73 = V_33 - V_2 -> V_3 . V_64 ;
V_42 -> V_62 = false ;
F_28 ( V_7 , V_37 -> V_44 , V_42 ) ;
F_24 ( & V_2 -> V_3 . V_53 ) ;
return 0 ;
} while ( V_23 != V_37 -> V_44 );
V_33 = V_47 ;
V_49 = F_23 ( V_37 -> V_2 , & V_33 -> V_54 , V_40 ) ;
if ( V_49 )
goto error;
F_21 ( V_33 -> V_74 ) ;
V_33 -> V_74 = F_19 ( V_40 ) ;
F_21 ( V_33 -> V_70 ) ;
V_33 -> V_70 = NULL ;
F_21 ( V_33 -> V_72 ) ;
V_33 -> V_72 = F_19 ( V_45 ) ;
V_33 -> V_69 = V_42 -> V_68 ;
V_33 -> V_34 = F_13 ( & V_2 -> V_35 ) ;
F_27 ( & V_33 -> V_55 , & V_2 -> V_3 . V_56 ) ;
F_29 ( & V_33 -> V_66 , V_7 -> V_67 ) ;
V_7 -> V_64 [ V_37 -> V_44 ] = V_33 ;
V_42 -> V_73 = V_33 - V_2 -> V_3 . V_64 ;
F_28 ( V_7 , V_37 -> V_44 , V_42 ) ;
error:
F_24 ( & V_2 -> V_3 . V_53 ) ;
return V_49 ;
}
static bool F_30 ( struct V_36 * V_37 )
{
struct V_1 * V_2 = V_37 -> V_2 ;
const struct V_75 * V_76 ;
if ( V_37 -> type != V_77 )
return false ;
V_76 = F_31 ( V_2 , V_78 ) ;
if ( ! V_76 )
return false ;
if ( V_76 -> V_79 <= 7 ) {
return true ;
} else if ( V_76 -> V_79 == 8 ) {
if ( V_2 -> V_80 . V_81 >= 673 )
return false ;
else
return true ;
}
return false ;
}
int F_32 ( struct V_36 * V_37 , struct V_41 * V_42 )
{
struct V_1 * V_2 = V_37 -> V_2 ;
struct V_32 * V_33 = & V_2 -> V_3 . V_64 [ V_42 -> V_73 ] ;
bool V_82 = V_37 -> V_83 -> V_84 && (
V_33 -> V_85 != V_42 -> V_85 ||
V_33 -> V_86 != V_42 -> V_86 ||
V_33 -> V_87 != V_42 -> V_87 ||
V_33 -> V_88 != V_42 -> V_88 ||
V_33 -> V_89 != V_42 -> V_89 ||
V_33 -> V_90 != V_42 -> V_90 ) ;
int V_49 ;
if ( V_37 -> V_83 -> V_91 && (
V_42 -> V_62 || V_82 ||
F_30 ( V_37 ) ) )
F_33 ( V_37 ) ;
if ( V_37 -> V_83 -> V_92 && ( V_42 -> V_62 ||
F_12 ( V_2 , V_33 ) ) ) {
struct V_40 * V_40 ;
F_34 ( V_42 -> V_68 , V_37 -> V_44 , V_42 -> V_73 ) ;
F_35 ( V_37 , V_42 -> V_73 , V_42 -> V_68 ) ;
V_49 = F_36 ( V_37 , & V_40 ) ;
if ( V_49 )
return V_49 ;
F_16 ( & V_2 -> V_3 . V_53 ) ;
F_21 ( V_33 -> V_70 ) ;
V_33 -> V_70 = V_40 ;
F_24 ( & V_2 -> V_3 . V_53 ) ;
}
if ( V_82 ) {
V_33 -> V_85 = V_42 -> V_85 ;
V_33 -> V_86 = V_42 -> V_86 ;
V_33 -> V_87 = V_42 -> V_87 ;
V_33 -> V_88 = V_42 -> V_88 ;
V_33 -> V_89 = V_42 -> V_89 ;
V_33 -> V_90 = V_42 -> V_90 ;
F_37 ( V_37 , V_42 -> V_73 ,
V_42 -> V_85 , V_42 -> V_86 ,
V_42 -> V_87 , V_42 -> V_88 ,
V_42 -> V_89 , V_42 -> V_90 ) ;
}
return 0 ;
}
void F_38 ( struct V_1 * V_2 , unsigned V_73 )
{
struct V_32 * V_33 = & V_2 -> V_3 . V_64 [ V_73 ] ;
V_33 -> V_85 = 0 ;
V_33 -> V_86 = 0 ;
V_33 -> V_87 = 0 ;
V_33 -> V_88 = 0 ;
V_33 -> V_89 = 0 ;
V_33 -> V_90 = 0 ;
}
struct V_93 * F_39 ( struct V_6 * V_7 ,
struct V_94 * V_16 )
{
struct V_93 * V_95 ;
F_17 (bo_va, &bo->va, bo_list) {
if ( V_95 -> V_7 == V_7 ) {
return V_95 ;
}
}
return NULL ;
}
static void F_40 ( struct V_96 * V_97 ,
T_1 V_98 , T_1 V_99 ,
unsigned V_100 , T_3 V_101 ,
T_3 V_102 )
{
F_41 ( V_98 , V_99 , V_100 , V_101 , V_102 ) ;
if ( V_100 < 3 ) {
F_42 ( V_97 -> V_2 , V_97 -> V_103 , V_98 ,
V_99 | V_102 , V_100 , V_101 ) ;
} else {
F_43 ( V_97 -> V_2 , V_97 -> V_103 , V_98 , V_99 ,
V_100 , V_101 , V_102 ) ;
}
}
static void F_44 ( struct V_96 * V_97 ,
T_1 V_98 , T_1 V_99 ,
unsigned V_100 , T_3 V_101 ,
T_3 V_102 )
{
T_1 V_104 = ( V_97 -> V_104 + ( V_99 >> 12 ) * 8 ) ;
F_45 ( V_98 , V_104 , V_100 ) ;
F_46 ( V_97 -> V_2 , V_97 -> V_103 , V_98 , V_104 , V_100 ) ;
}
static int F_47 ( struct V_1 * V_2 ,
struct V_6 * V_7 ,
struct V_94 * V_16 )
{
struct V_36 * V_37 ;
struct V_40 * V_40 = NULL ;
struct V_41 * V_42 ;
struct V_96 V_97 ;
unsigned V_105 ;
T_1 V_99 ;
int V_49 ;
V_37 = F_48 ( V_7 -> V_106 . V_107 , struct V_36 , V_107 ) ;
V_49 = F_49 ( V_16 -> V_17 . V_108 ) ;
if ( V_49 )
return V_49 ;
V_49 = F_50 ( & V_16 -> V_17 , & V_16 -> V_109 , true , false ) ;
if ( V_49 )
goto error;
V_49 = F_51 ( & V_16 -> V_17 , & V_16 -> V_17 . V_110 ) ;
if ( V_49 )
goto error;
V_99 = F_52 ( V_16 ) ;
V_105 = F_53 ( V_16 ) / 8 ;
V_49 = F_54 ( V_2 , 64 , & V_42 ) ;
if ( V_49 )
goto error;
memset ( & V_97 , 0 , sizeof( V_97 ) ) ;
V_97 . V_2 = V_2 ;
V_97 . V_103 = & V_42 -> V_111 [ 0 ] ;
F_40 ( & V_97 , V_99 , 0 , V_105 , 0 , 0 ) ;
F_55 ( V_37 , & V_42 -> V_111 [ 0 ] ) ;
F_56 ( V_42 -> V_111 [ 0 ] . V_112 > 64 ) ;
V_49 = F_57 ( V_42 , V_37 , & V_7 -> V_106 ,
V_113 , & V_40 ) ;
if ( V_49 )
goto V_114;
F_58 ( V_16 , V_40 , true ) ;
F_21 ( V_40 ) ;
return 0 ;
V_114:
F_59 ( V_42 ) ;
error:
return V_49 ;
}
static T_1 F_60 ( const T_4 * V_115 , T_1 V_99 )
{
T_1 V_116 ;
V_116 = V_115 [ V_99 >> V_117 ] ;
V_116 |= V_99 & ( ~ V_118 ) ;
V_116 &= 0xFFFFFFFFFFFFF000ULL ;
return V_116 ;
}
static int F_61 ( struct V_1 * V_2 ,
struct V_6 * V_7 ,
bool V_119 )
{
struct V_36 * V_37 ;
struct V_94 * V_120 = V_119 ? V_7 -> V_13 -> V_119 :
V_7 -> V_13 ;
T_1 V_121 ;
T_3 V_101 = V_122 * 8 ;
T_1 V_123 = ~ 0 , V_124 = ~ 0 ;
unsigned V_100 = 0 , V_125 , V_126 ;
struct V_41 * V_42 ;
struct V_96 V_97 ;
struct V_40 * V_40 = NULL ;
int V_49 ;
if ( ! V_120 )
return 0 ;
V_49 = F_51 ( & V_120 -> V_17 , & V_120 -> V_17 . V_110 ) ;
if ( V_49 )
return V_49 ;
V_121 = F_52 ( V_120 ) ;
V_37 = F_48 ( V_7 -> V_106 . V_107 , struct V_36 , V_107 ) ;
V_126 = 64 ;
V_126 += V_7 -> V_25 * 6 ;
V_49 = F_54 ( V_2 , V_126 * 4 , & V_42 ) ;
if ( V_49 )
return V_49 ;
memset ( & V_97 , 0 , sizeof( V_97 ) ) ;
V_97 . V_2 = V_2 ;
V_97 . V_103 = & V_42 -> V_111 [ 0 ] ;
for ( V_125 = 0 ; V_125 <= V_7 -> V_25 ; ++ V_125 ) {
struct V_94 * V_16 = V_7 -> V_26 [ V_125 ] . V_11 . V_12 ;
T_1 V_127 , V_128 ;
if ( V_16 == NULL )
continue;
if ( V_16 -> V_119 ) {
struct V_94 * V_119 = V_16 -> V_119 ;
V_49 = F_51 ( & V_119 -> V_17 , & V_119 -> V_17 . V_110 ) ;
if ( V_49 )
return V_49 ;
}
V_128 = F_52 ( V_16 ) ;
if ( ! V_119 ) {
if ( V_7 -> V_26 [ V_125 ] . V_99 == V_128 )
continue;
V_7 -> V_26 [ V_125 ] . V_99 = V_128 ;
} else {
if ( V_7 -> V_26 [ V_125 ] . V_129 == V_128 )
continue;
V_7 -> V_26 [ V_125 ] . V_129 = V_128 ;
}
V_127 = V_121 + V_125 * 8 ;
if ( ( ( V_123 + 8 * V_100 ) != V_127 ) ||
( ( V_124 + V_101 * V_100 ) != V_128 ) ||
( V_100 == V_130 ) ) {
if ( V_100 ) {
F_40 ( & V_97 , V_123 ,
V_124 , V_100 , V_101 ,
V_131 ) ;
}
V_100 = 1 ;
V_123 = V_127 ;
V_124 = V_128 ;
} else {
++ V_100 ;
}
}
if ( V_100 )
F_40 ( & V_97 , V_123 , V_124 ,
V_100 , V_101 , V_131 ) ;
if ( V_97 . V_103 -> V_112 != 0 ) {
F_55 ( V_37 , V_97 . V_103 ) ;
F_62 ( V_2 , & V_42 -> V_39 , V_120 -> V_17 . V_108 ,
V_113 ) ;
F_56 ( V_97 . V_103 -> V_112 > V_126 ) ;
V_49 = F_57 ( V_42 , V_37 , & V_7 -> V_106 ,
V_113 , & V_40 ) ;
if ( V_49 )
goto V_114;
F_58 ( V_120 , V_40 , true ) ;
F_21 ( V_7 -> V_132 ) ;
V_7 -> V_132 = F_19 ( V_40 ) ;
F_21 ( V_40 ) ;
} else {
F_59 ( V_42 ) ;
}
return 0 ;
V_114:
F_59 ( V_42 ) ;
return V_49 ;
}
int F_63 ( struct V_1 * V_2 ,
struct V_6 * V_7 )
{
int V_49 ;
V_49 = F_61 ( V_2 , V_7 , true ) ;
if ( V_49 )
return V_49 ;
return F_61 ( V_2 , V_7 , false ) ;
}
static void F_64 ( struct V_96 * V_97 ,
struct V_6 * V_7 ,
T_1 V_133 , T_1 V_134 ,
T_1 V_135 , T_3 V_102 )
{
const T_1 V_136 = V_122 - 1 ;
T_1 V_137 , V_138 , V_139 ;
T_1 V_99 ;
T_1 V_125 ;
struct V_94 * V_128 ;
unsigned V_140 ;
T_1 V_141 ;
V_99 = V_133 ;
V_125 = V_99 >> V_5 ;
V_128 = V_7 -> V_26 [ V_125 ] . V_11 . V_12 ;
if ( V_97 -> V_119 ) {
if ( ! V_128 -> V_119 )
return;
V_128 = V_7 -> V_26 [ V_125 ] . V_11 . V_12 -> V_119 ;
}
if ( ( V_99 & ~ V_136 ) == ( V_134 & ~ V_136 ) )
V_140 = V_134 - V_99 ;
else
V_140 = V_122 - ( V_99 & V_136 ) ;
V_137 = F_52 ( V_128 ) ;
V_137 += ( V_99 & V_136 ) * 8 ;
V_138 = V_140 ;
V_139 = V_135 ;
V_99 += V_140 ;
V_135 += V_140 * V_142 ;
while ( V_99 < V_134 ) {
V_125 = V_99 >> V_5 ;
V_128 = V_7 -> V_26 [ V_125 ] . V_11 . V_12 ;
if ( V_97 -> V_119 ) {
if ( ! V_128 -> V_119 )
return;
V_128 = V_7 -> V_26 [ V_125 ] . V_11 . V_12 -> V_119 ;
}
if ( ( V_99 & ~ V_136 ) == ( V_134 & ~ V_136 ) )
V_140 = V_134 - V_99 ;
else
V_140 = V_122 - ( V_99 & V_136 ) ;
V_141 = F_52 ( V_128 ) ;
V_141 += ( V_99 & V_136 ) * 8 ;
if ( ( V_137 + 8 * V_138 ) == V_141 &&
( ( V_138 + V_140 ) <= V_130 ) ) {
V_138 += V_140 ;
} else {
V_97 -> V_143 ( V_97 , V_137 , V_139 , V_138 ,
V_142 , V_102 ) ;
V_137 = V_141 ;
V_138 = V_140 ;
V_139 = V_135 ;
}
V_99 += V_140 ;
V_135 += V_140 * V_142 ;
}
V_97 -> V_143 ( V_97 , V_137 , V_139 , V_138 ,
V_142 , V_102 ) ;
}
static void F_65 ( struct V_96 * V_97 ,
struct V_6 * V_7 ,
T_1 V_133 , T_1 V_134 ,
T_1 V_135 , T_3 V_102 )
{
T_1 V_144 = F_66 ( V_145 ) ;
T_1 V_146 = 1 << V_145 ;
T_1 V_147 = F_67 ( V_133 , V_146 ) ;
T_1 V_148 = V_134 & ~ ( V_146 - 1 ) ;
if ( V_97 -> V_104 || ! ( V_102 & V_131 ) ||
( V_147 >= V_148 ) ) {
F_64 ( V_97 , V_7 , V_133 , V_134 , V_135 , V_102 ) ;
return;
}
if ( V_133 != V_147 ) {
F_64 ( V_97 , V_7 , V_133 , V_147 ,
V_135 , V_102 ) ;
V_135 += ( V_147 - V_133 ) * V_142 ;
}
F_64 ( V_97 , V_7 , V_147 , V_148 , V_135 ,
V_102 | V_144 ) ;
if ( V_148 != V_134 ) {
V_135 += ( V_148 - V_147 ) * V_142 ;
F_64 ( V_97 , V_7 , V_148 , V_134 , V_135 , V_102 ) ;
}
}
static int F_68 ( struct V_1 * V_2 ,
struct V_40 * V_149 ,
T_1 V_104 ,
T_4 * V_115 ,
struct V_6 * V_7 ,
T_1 V_133 , T_1 V_150 ,
T_3 V_102 , T_1 V_99 ,
struct V_40 * * V_40 )
{
struct V_36 * V_37 ;
void * V_66 = V_113 ;
unsigned V_140 , V_151 , V_126 ;
struct V_41 * V_42 ;
struct V_96 V_97 ;
struct V_40 * V_152 = NULL ;
int V_49 ;
memset ( & V_97 , 0 , sizeof( V_97 ) ) ;
V_97 . V_2 = V_2 ;
V_97 . V_104 = V_104 ;
V_37 = F_48 ( V_7 -> V_106 . V_107 , struct V_36 , V_107 ) ;
memset ( & V_97 , 0 , sizeof( V_97 ) ) ;
V_97 . V_2 = V_2 ;
V_97 . V_104 = V_104 ;
if ( ! ( V_102 & V_131 ) )
V_66 = V_153 ;
V_140 = V_150 - V_133 + 1 ;
V_151 = ( V_140 >> F_69 ( V_5 , 11 ) ) + 1 ;
V_126 = 64 ;
if ( V_104 ) {
V_126 += V_151 * 7 ;
V_97 . V_143 = F_44 ;
} else if ( V_115 ) {
V_126 += V_151 * 7 ;
V_126 += V_140 * 2 ;
V_97 . V_143 = F_44 ;
} else {
V_126 += V_151 * 10 ;
V_126 += 2 * 10 ;
V_97 . V_143 = F_40 ;
}
V_49 = F_54 ( V_2 , V_126 * 4 , & V_42 ) ;
if ( V_49 )
return V_49 ;
V_97 . V_103 = & V_42 -> V_111 [ 0 ] ;
if ( ! V_104 && V_115 ) {
T_1 * V_154 ;
unsigned V_23 ;
V_23 = V_126 - V_140 * 2 ;
V_154 = ( T_1 * ) & ( V_42 -> V_111 -> V_155 [ V_23 ] ) ;
V_97 . V_104 = V_42 -> V_111 -> V_156 + V_23 * 4 ;
for ( V_23 = 0 ; V_23 < V_140 ; ++ V_23 ) {
V_154 [ V_23 ] = F_60 ( V_115 , V_99 + V_23 *
V_142 ) ;
V_154 [ V_23 ] |= V_102 ;
}
V_99 = 0 ;
}
V_49 = F_23 ( V_2 , & V_42 -> V_39 , V_149 ) ;
if ( V_49 )
goto V_114;
V_49 = F_62 ( V_2 , & V_42 -> V_39 , V_7 -> V_13 -> V_17 . V_108 ,
V_66 ) ;
if ( V_49 )
goto V_114;
V_49 = F_49 ( V_7 -> V_13 -> V_17 . V_108 ) ;
if ( V_49 )
goto V_114;
V_97 . V_119 = true ;
F_65 ( & V_97 , V_7 , V_133 , V_150 + 1 , V_99 , V_102 ) ;
V_97 . V_119 = false ;
F_65 ( & V_97 , V_7 , V_133 , V_150 + 1 , V_99 , V_102 ) ;
F_55 ( V_37 , V_97 . V_103 ) ;
F_56 ( V_97 . V_103 -> V_112 > V_126 ) ;
V_49 = F_57 ( V_42 , V_37 , & V_7 -> V_106 ,
V_113 , & V_152 ) ;
if ( V_49 )
goto V_114;
F_58 ( V_7 -> V_13 , V_152 , true ) ;
if ( V_40 ) {
F_21 ( * V_40 ) ;
* V_40 = F_19 ( V_152 ) ;
}
F_21 ( V_152 ) ;
return 0 ;
V_114:
F_59 ( V_42 ) ;
return V_49 ;
}
static int F_70 ( struct V_1 * V_2 ,
struct V_40 * V_149 ,
T_3 V_157 ,
T_4 * V_115 ,
struct V_6 * V_7 ,
struct V_158 * V_159 ,
T_3 V_102 , T_1 V_99 ,
struct V_40 * * V_40 )
{
const T_1 V_160 = 64ULL * 1024ULL * 1024ULL / V_142 ;
T_1 V_104 = 0 , V_133 = V_159 -> V_161 . V_133 ;
int V_49 ;
if ( ! ( V_159 -> V_102 & V_162 ) )
V_102 &= ~ V_162 ;
if ( ! ( V_159 -> V_102 & V_163 ) )
V_102 &= ~ V_163 ;
F_71 ( V_159 ) ;
if ( V_115 ) {
if ( V_102 == V_157 )
V_104 = V_2 -> V_164 . V_165 + ( V_99 >> 12 ) * 8 ;
V_99 = 0 ;
}
V_99 += V_159 -> V_166 ;
if ( ! V_115 || V_104 )
return F_68 ( V_2 , V_149 ,
V_104 , V_115 , V_7 ,
V_133 , V_159 -> V_161 . V_150 ,
V_102 , V_99 , V_40 ) ;
while ( V_133 != V_159 -> V_161 . V_150 + 1 ) {
T_1 V_150 ;
V_150 = F_69 ( ( T_1 ) V_159 -> V_161 . V_150 , V_133 + V_160 - 1 ) ;
V_49 = F_68 ( V_2 , V_149 ,
V_104 , V_115 , V_7 ,
V_133 , V_150 , V_102 , V_99 ,
V_40 ) ;
if ( V_49 )
return V_49 ;
V_133 = V_150 + 1 ;
V_99 += V_160 * V_142 ;
}
return 0 ;
}
int F_72 ( struct V_1 * V_2 ,
struct V_93 * V_95 ,
bool V_167 )
{
struct V_6 * V_7 = V_95 -> V_7 ;
struct V_158 * V_159 ;
T_4 * V_115 = NULL ;
T_3 V_157 , V_102 ;
struct V_168 * V_110 ;
struct V_40 * V_149 ;
T_1 V_99 ;
int V_49 ;
if ( V_167 ) {
V_110 = NULL ;
V_99 = 0 ;
V_149 = NULL ;
} else {
struct V_169 * V_170 ;
V_110 = & V_95 -> V_16 -> V_17 . V_110 ;
V_99 = ( T_2 ) V_110 -> V_133 << V_117 ;
switch ( V_110 -> V_171 ) {
case V_172 :
V_170 = F_48 ( V_95 -> V_16 -> V_17 . V_170 , struct
V_169 , V_170 ) ;
V_115 = V_170 -> V_173 ;
break;
case V_174 :
V_99 += V_2 -> V_3 . V_175 ;
break;
default:
break;
}
V_149 = F_73 ( V_95 -> V_16 -> V_17 . V_108 ) ;
}
V_102 = F_74 ( V_2 , V_95 -> V_16 -> V_17 . V_170 , V_110 ) ;
V_157 = ( F_75 ( V_95 -> V_16 -> V_17 . V_170 ) &&
V_2 == V_95 -> V_16 -> V_2 ) ? V_102 : 0 ;
F_9 ( & V_7 -> V_176 ) ;
if ( ! F_76 ( & V_95 -> V_177 ) )
F_77 ( & V_95 -> V_178 , & V_95 -> V_179 ) ;
F_11 ( & V_7 -> V_176 ) ;
F_17 (mapping, &bo_va->invalids, list) {
V_49 = F_70 ( V_2 , V_149 ,
V_157 , V_115 , V_7 ,
V_159 , V_102 , V_99 ,
& V_95 -> V_180 ) ;
if ( V_49 )
return V_49 ;
}
if ( F_78 () ) {
F_17 (mapping, &bo_va->valids, list)
F_79 ( V_159 ) ;
F_17 (mapping, &bo_va->invalids, list)
F_79 ( V_159 ) ;
}
F_9 ( & V_7 -> V_176 ) ;
F_77 ( & V_95 -> V_179 , & V_95 -> V_178 ) ;
F_80 ( & V_95 -> V_177 ) ;
if ( V_167 )
F_5 ( & V_95 -> V_177 , & V_7 -> V_181 ) ;
F_11 ( & V_7 -> V_176 ) ;
return 0 ;
}
int F_81 ( struct V_1 * V_2 ,
struct V_6 * V_7 )
{
struct V_158 * V_159 ;
int V_49 ;
while ( ! F_76 ( & V_7 -> V_182 ) ) {
V_159 = F_82 ( & V_7 -> V_182 ,
struct V_158 , V_55 ) ;
F_83 ( & V_159 -> V_55 ) ;
V_49 = F_70 ( V_2 , NULL , 0 , NULL , V_7 , V_159 ,
0 , 0 , NULL ) ;
F_22 ( V_159 ) ;
if ( V_49 )
return V_49 ;
}
return 0 ;
}
int F_84 ( struct V_1 * V_2 ,
struct V_6 * V_7 , struct V_38 * V_39 )
{
struct V_93 * V_95 = NULL ;
int V_49 = 0 ;
F_9 ( & V_7 -> V_176 ) ;
while ( ! F_76 ( & V_7 -> V_183 ) ) {
V_95 = F_82 ( & V_7 -> V_183 ,
struct V_93 , V_177 ) ;
F_11 ( & V_7 -> V_176 ) ;
V_49 = F_72 ( V_2 , V_95 , true ) ;
if ( V_49 )
return V_49 ;
F_9 ( & V_7 -> V_176 ) ;
}
F_11 ( & V_7 -> V_176 ) ;
if ( V_95 )
V_49 = F_23 ( V_2 , V_39 , V_95 -> V_180 ) ;
return V_49 ;
}
struct V_93 * F_85 ( struct V_1 * V_2 ,
struct V_6 * V_7 ,
struct V_94 * V_16 )
{
struct V_93 * V_95 ;
V_95 = F_86 ( sizeof( struct V_93 ) , V_51 ) ;
if ( V_95 == NULL ) {
return NULL ;
}
V_95 -> V_7 = V_7 ;
V_95 -> V_16 = V_16 ;
V_95 -> V_184 = 1 ;
F_87 ( & V_95 -> V_185 ) ;
F_87 ( & V_95 -> V_178 ) ;
F_87 ( & V_95 -> V_179 ) ;
F_87 ( & V_95 -> V_177 ) ;
F_88 ( & V_95 -> V_185 , & V_16 -> V_186 ) ;
return V_95 ;
}
int F_89 ( struct V_1 * V_2 ,
struct V_93 * V_95 ,
T_1 V_187 , T_1 V_166 ,
T_1 V_188 , T_3 V_102 )
{
struct V_158 * V_159 ;
struct V_6 * V_7 = V_95 -> V_7 ;
struct V_189 * V_161 ;
unsigned V_190 , V_125 ;
T_1 V_191 ;
int V_49 ;
if ( V_187 & V_192 || V_166 & V_192 ||
V_188 == 0 || V_188 & V_192 )
return - V_193 ;
V_191 = V_187 + V_188 - 1 ;
if ( ( V_187 >= V_191 ) || ( V_166 + V_188 > F_53 ( V_95 -> V_16 ) ) )
return - V_193 ;
V_190 = V_191 / V_142 ;
if ( V_190 >= V_2 -> V_3 . V_4 ) {
F_90 ( V_2 -> V_194 , L_1 ,
V_190 , V_2 -> V_3 . V_4 ) ;
return - V_193 ;
}
V_187 /= V_142 ;
V_191 /= V_142 ;
V_161 = F_91 ( & V_7 -> V_186 , V_187 , V_191 ) ;
if ( V_161 ) {
struct V_158 * V_195 ;
V_195 = F_48 ( V_161 , struct V_158 , V_161 ) ;
F_90 ( V_2 -> V_194 , L_2
L_3 , V_95 -> V_16 , V_187 , V_191 ,
V_195 -> V_161 . V_133 , V_195 -> V_161 . V_150 + 1 ) ;
V_49 = - V_193 ;
goto error;
}
V_159 = F_92 ( sizeof( * V_159 ) , V_51 ) ;
if ( ! V_159 ) {
V_49 = - V_52 ;
goto error;
}
F_87 ( & V_159 -> V_55 ) ;
V_159 -> V_161 . V_133 = V_187 ;
V_159 -> V_161 . V_150 = V_191 ;
V_159 -> V_166 = V_166 ;
V_159 -> V_102 = V_102 ;
F_5 ( & V_159 -> V_55 , & V_95 -> V_179 ) ;
F_93 ( & V_159 -> V_161 , & V_7 -> V_186 ) ;
V_187 >>= V_5 ;
V_191 >>= V_5 ;
F_94 ( V_191 >= F_1 ( V_2 ) ) ;
if ( V_191 > V_7 -> V_25 )
V_7 -> V_25 = V_191 ;
for ( V_125 = V_187 ; V_125 <= V_191 ; ++ V_125 ) {
struct V_196 * V_108 = V_7 -> V_13 -> V_17 . V_108 ;
struct V_10 * V_11 ;
struct V_94 * V_128 ;
V_11 = & V_7 -> V_26 [ V_125 ] . V_11 ;
if ( V_11 -> V_12 )
continue;
V_49 = F_95 ( V_2 , V_122 * 8 ,
V_142 , true ,
V_197 ,
V_198 |
V_199 ,
NULL , V_108 , & V_128 ) ;
if ( V_49 )
goto V_114;
V_128 -> V_200 = F_96 ( V_7 -> V_13 ) ;
V_49 = F_47 ( V_2 , V_7 , V_128 ) ;
if ( V_49 ) {
F_97 ( & V_128 -> V_119 ) ;
F_97 ( & V_128 ) ;
goto V_114;
}
if ( V_128 -> V_119 ) {
V_49 = F_47 ( V_2 , V_7 , V_128 -> V_119 ) ;
if ( V_49 ) {
F_97 ( & V_128 -> V_119 ) ;
F_97 ( & V_128 ) ;
goto V_114;
}
}
V_11 -> V_12 = V_128 ;
V_11 -> V_14 = 0 ;
V_11 -> V_15 . V_16 = & V_11 -> V_12 -> V_17 ;
V_11 -> V_15 . V_18 = true ;
V_11 -> V_19 = NULL ;
V_7 -> V_26 [ V_125 ] . V_99 = 0 ;
}
return 0 ;
V_114:
F_83 ( & V_159 -> V_55 ) ;
F_98 ( & V_159 -> V_161 , & V_7 -> V_186 ) ;
F_99 ( V_95 , V_159 ) ;
F_22 ( V_159 ) ;
error:
return V_49 ;
}
int F_100 ( struct V_1 * V_2 ,
struct V_93 * V_95 ,
T_1 V_187 )
{
struct V_158 * V_159 ;
struct V_6 * V_7 = V_95 -> V_7 ;
bool V_201 = true ;
V_187 /= V_142 ;
F_17 (mapping, &bo_va->valids, list) {
if ( V_159 -> V_161 . V_133 == V_187 )
break;
}
if ( & V_159 -> V_55 == & V_95 -> V_178 ) {
V_201 = false ;
F_17 (mapping, &bo_va->invalids, list) {
if ( V_159 -> V_161 . V_133 == V_187 )
break;
}
if ( & V_159 -> V_55 == & V_95 -> V_179 )
return - V_202 ;
}
F_83 ( & V_159 -> V_55 ) ;
F_98 ( & V_159 -> V_161 , & V_7 -> V_186 ) ;
F_99 ( V_95 , V_159 ) ;
if ( V_201 )
F_5 ( & V_159 -> V_55 , & V_7 -> V_182 ) ;
else
F_22 ( V_159 ) ;
return 0 ;
}
void F_101 ( struct V_1 * V_2 ,
struct V_93 * V_95 )
{
struct V_158 * V_159 , * V_203 ;
struct V_6 * V_7 = V_95 -> V_7 ;
F_83 ( & V_95 -> V_185 ) ;
F_9 ( & V_7 -> V_176 ) ;
F_83 ( & V_95 -> V_177 ) ;
F_11 ( & V_7 -> V_176 ) ;
F_102 (mapping, next, &bo_va->valids, list) {
F_83 ( & V_159 -> V_55 ) ;
F_98 ( & V_159 -> V_161 , & V_7 -> V_186 ) ;
F_99 ( V_95 , V_159 ) ;
F_5 ( & V_159 -> V_55 , & V_7 -> V_182 ) ;
}
F_102 (mapping, next, &bo_va->invalids, list) {
F_83 ( & V_159 -> V_55 ) ;
F_98 ( & V_159 -> V_161 , & V_7 -> V_186 ) ;
F_22 ( V_159 ) ;
}
F_21 ( V_95 -> V_180 ) ;
F_22 ( V_95 ) ;
}
void F_103 ( struct V_1 * V_2 ,
struct V_94 * V_16 )
{
struct V_93 * V_95 ;
F_17 (bo_va, &bo->va, bo_list) {
F_9 ( & V_95 -> V_7 -> V_176 ) ;
if ( F_76 ( & V_95 -> V_177 ) )
F_5 ( & V_95 -> V_177 , & V_95 -> V_7 -> V_183 ) ;
F_11 ( & V_95 -> V_7 -> V_176 ) ;
}
}
int F_104 ( struct V_1 * V_2 , struct V_6 * V_7 )
{
const unsigned V_204 = F_69 ( V_205 ,
V_122 * 8 ) ;
unsigned V_206 , V_207 ;
unsigned V_208 ;
struct V_36 * V_37 ;
struct V_209 * V_210 ;
int V_23 , V_49 ;
for ( V_23 = 0 ; V_23 < V_65 ; ++ V_23 )
V_7 -> V_64 [ V_23 ] = NULL ;
V_7 -> V_186 = V_211 ;
V_7 -> V_67 = F_105 ( & V_2 -> V_3 . V_212 ) ;
F_106 ( & V_7 -> V_176 ) ;
F_87 ( & V_7 -> V_183 ) ;
F_87 ( & V_7 -> V_181 ) ;
F_87 ( & V_7 -> V_182 ) ;
V_206 = F_2 ( V_2 ) ;
V_207 = F_1 ( V_2 ) ;
V_7 -> V_26 = F_107 ( V_207 , sizeof( struct V_213 ) ) ;
if ( V_7 -> V_26 == NULL ) {
F_108 ( L_4 ) ;
return - V_52 ;
}
V_208 = F_109 ( & V_2 -> V_3 . V_214 ) ;
V_208 %= V_2 -> V_3 . V_215 ;
V_37 = V_2 -> V_3 . V_216 [ V_208 ] ;
V_210 = & V_37 -> V_107 . V_217 [ V_218 ] ;
V_49 = F_110 ( & V_37 -> V_107 , & V_7 -> V_106 ,
V_210 , V_219 ) ;
if ( V_49 )
goto V_220;
V_7 -> V_132 = NULL ;
V_49 = F_95 ( V_2 , V_206 , V_204 , true ,
V_197 ,
V_198 |
V_199 ,
NULL , NULL , & V_7 -> V_13 ) ;
if ( V_49 )
goto V_221;
V_49 = F_111 ( V_7 -> V_13 , false ) ;
if ( V_49 )
goto V_222;
V_49 = F_47 ( V_2 , V_7 , V_7 -> V_13 ) ;
if ( V_49 )
goto V_223;
if ( V_7 -> V_13 -> V_119 ) {
V_49 = F_47 ( V_2 , V_7 , V_7 -> V_13 -> V_119 ) ;
if ( V_49 )
goto V_223;
}
V_7 -> V_24 = F_7 ( & V_2 -> V_22 ) ;
F_112 ( V_7 -> V_13 ) ;
return 0 ;
V_223:
F_112 ( V_7 -> V_13 ) ;
V_222:
F_97 ( & V_7 -> V_13 -> V_119 ) ;
F_97 ( & V_7 -> V_13 ) ;
V_7 -> V_13 = NULL ;
V_221:
F_113 ( & V_37 -> V_107 , & V_7 -> V_106 ) ;
V_220:
F_114 ( V_7 -> V_26 ) ;
return V_49 ;
}
void F_115 ( struct V_1 * V_2 , struct V_6 * V_7 )
{
struct V_158 * V_159 , * V_195 ;
int V_23 ;
F_113 ( V_7 -> V_106 . V_107 , & V_7 -> V_106 ) ;
if ( ! F_116 ( & V_7 -> V_186 ) ) {
F_90 ( V_2 -> V_194 , L_5 ) ;
}
F_117 (mapping, tmp, &vm->va, it.rb) {
F_83 ( & V_159 -> V_55 ) ;
F_98 ( & V_159 -> V_161 , & V_7 -> V_186 ) ;
F_22 ( V_159 ) ;
}
F_102 (mapping, tmp, &vm->freed, list) {
F_83 ( & V_159 -> V_55 ) ;
F_22 ( V_159 ) ;
}
for ( V_23 = 0 ; V_23 < F_1 ( V_2 ) ; V_23 ++ ) {
struct V_94 * V_128 = V_7 -> V_26 [ V_23 ] . V_11 . V_12 ;
if ( ! V_128 )
continue;
F_97 ( & V_128 -> V_119 ) ;
F_97 ( & V_128 ) ;
}
F_114 ( V_7 -> V_26 ) ;
F_97 ( & V_7 -> V_13 -> V_119 ) ;
F_97 ( & V_7 -> V_13 ) ;
F_21 ( V_7 -> V_132 ) ;
}
void F_118 ( struct V_1 * V_2 )
{
unsigned V_23 ;
F_87 ( & V_2 -> V_3 . V_56 ) ;
for ( V_23 = 1 ; V_23 < V_2 -> V_3 . V_50 ; ++ V_23 ) {
F_38 ( V_2 , V_23 ) ;
F_119 ( & V_2 -> V_3 . V_64 [ V_23 ] . V_54 ) ;
F_88 ( & V_2 -> V_3 . V_64 [ V_23 ] . V_55 ,
& V_2 -> V_3 . V_56 ) ;
}
V_2 -> V_3 . V_43 = F_120 ( V_65 ) ;
for ( V_23 = 0 ; V_23 < V_65 ; ++ V_23 )
V_2 -> V_3 . V_57 [ V_23 ] = 0 ;
F_121 ( & V_2 -> V_3 . V_214 , 0 ) ;
F_29 ( & V_2 -> V_3 . V_212 , 0 ) ;
}
void F_122 ( struct V_1 * V_2 )
{
unsigned V_23 ;
for ( V_23 = 0 ; V_23 < V_224 ; ++ V_23 ) {
struct V_32 * V_33 = & V_2 -> V_3 . V_64 [ V_23 ] ;
F_21 ( V_2 -> V_3 . V_64 [ V_23 ] . V_74 ) ;
F_123 ( & V_2 -> V_3 . V_64 [ V_23 ] . V_54 ) ;
F_21 ( V_33 -> V_72 ) ;
F_21 ( V_33 -> V_70 ) ;
}
}
