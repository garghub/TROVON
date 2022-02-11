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
static void F_40 ( struct V_1 * V_2 ,
struct V_96
* V_97 ,
T_1 V_98 , T_1 V_99 ,
unsigned V_100 , T_3 V_101 ,
T_3 V_102 )
{
F_41 ( V_98 , V_99 , V_100 , V_101 , V_102 ) ;
if ( V_97 -> V_103 ) {
F_42 ( V_2 , V_97 -> V_104 ,
V_98 , ( V_97 -> V_103 + ( V_99 >> 12 ) * 8 ) , V_100 ) ;
} else if ( V_97 -> V_105 ) {
F_43 ( V_2 , V_97 -> V_104 ,
V_97 -> V_105 ,
V_98 , V_99 , V_100 , V_101 , V_102 ) ;
} else if ( V_100 < 3 ) {
F_43 ( V_2 , V_97 -> V_104 , NULL , V_98 , V_99 ,
V_100 , V_101 , V_102 ) ;
} else {
F_44 ( V_2 , V_97 -> V_104 , V_98 , V_99 ,
V_100 , V_101 , V_102 ) ;
}
}
static int F_45 ( struct V_1 * V_2 ,
struct V_6 * V_7 ,
struct V_94 * V_16 )
{
struct V_36 * V_37 ;
struct V_40 * V_40 = NULL ;
struct V_41 * V_42 ;
struct V_96 V_97 ;
unsigned V_106 ;
T_1 V_99 ;
int V_49 ;
memset ( & V_97 , 0 , sizeof( V_97 ) ) ;
V_37 = F_46 ( V_7 -> V_107 . V_108 , struct V_36 , V_108 ) ;
V_49 = F_47 ( V_16 -> V_17 . V_109 ) ;
if ( V_49 )
return V_49 ;
V_49 = F_48 ( & V_16 -> V_17 , & V_16 -> V_110 , true , false ) ;
if ( V_49 )
goto error;
V_99 = F_49 ( V_16 ) ;
V_106 = F_50 ( V_16 ) / 8 ;
V_49 = F_51 ( V_2 , 64 , & V_42 ) ;
if ( V_49 )
goto error;
V_97 . V_104 = & V_42 -> V_111 [ 0 ] ;
F_40 ( V_2 , & V_97 , V_99 , 0 , V_106 ,
0 , 0 ) ;
F_52 ( V_37 , & V_42 -> V_111 [ 0 ] ) ;
F_53 ( V_42 -> V_111 [ 0 ] . V_112 > 64 ) ;
V_49 = F_54 ( V_42 , V_37 , & V_7 -> V_107 ,
V_113 , & V_40 ) ;
if ( V_49 )
goto V_114;
F_55 ( V_16 , V_40 , true ) ;
F_21 ( V_40 ) ;
return 0 ;
V_114:
F_56 ( V_42 ) ;
error:
return V_49 ;
}
T_1 F_57 ( const T_4 * V_105 , T_1 V_99 )
{
T_1 V_115 ;
if ( V_105 ) {
V_115 = V_105 [ V_99 >> V_116 ] ;
V_115 |= V_99 & ( ~ V_117 ) ;
} else {
V_115 = V_99 ;
}
V_115 &= 0xFFFFFFFFFFFFF000ULL ;
return V_115 ;
}
int F_58 ( struct V_1 * V_2 ,
struct V_6 * V_7 )
{
struct V_36 * V_37 ;
struct V_94 * V_118 = V_7 -> V_13 ;
T_1 V_119 = F_49 ( V_118 ) ;
T_3 V_101 = V_120 * 8 ;
T_1 V_121 = ~ 0 , V_122 = ~ 0 ;
unsigned V_100 = 0 , V_123 , V_124 ;
struct V_41 * V_42 ;
struct V_96 V_97 ;
struct V_40 * V_40 = NULL ;
int V_49 ;
memset ( & V_97 , 0 , sizeof( V_97 ) ) ;
V_37 = F_46 ( V_7 -> V_107 . V_108 , struct V_36 , V_108 ) ;
V_124 = 64 ;
V_124 += V_7 -> V_25 * 6 ;
V_49 = F_51 ( V_2 , V_124 * 4 , & V_42 ) ;
if ( V_49 )
return V_49 ;
V_97 . V_104 = & V_42 -> V_111 [ 0 ] ;
for ( V_123 = 0 ; V_123 <= V_7 -> V_25 ; ++ V_123 ) {
struct V_94 * V_16 = V_7 -> V_26 [ V_123 ] . V_11 . V_12 ;
T_1 V_125 , V_126 ;
if ( V_16 == NULL )
continue;
V_126 = F_49 ( V_16 ) ;
if ( V_7 -> V_26 [ V_123 ] . V_99 == V_126 )
continue;
V_7 -> V_26 [ V_123 ] . V_99 = V_126 ;
V_125 = V_119 + V_123 * 8 ;
if ( ( ( V_121 + 8 * V_100 ) != V_125 ) ||
( ( V_122 + V_101 * V_100 ) != V_126 ) ) {
if ( V_100 ) {
F_40 ( V_2 , & V_97 ,
V_121 , V_122 ,
V_100 , V_101 ,
V_127 ) ;
}
V_100 = 1 ;
V_121 = V_125 ;
V_122 = V_126 ;
} else {
++ V_100 ;
}
}
if ( V_100 )
F_40 ( V_2 , & V_97 ,
V_121 , V_122 ,
V_100 , V_101 , V_127 ) ;
if ( V_97 . V_104 -> V_112 != 0 ) {
F_52 ( V_37 , V_97 . V_104 ) ;
F_59 ( V_2 , & V_42 -> V_39 , V_118 -> V_17 . V_109 ,
V_113 ) ;
F_53 ( V_97 . V_104 -> V_112 > V_124 ) ;
V_49 = F_54 ( V_42 , V_37 , & V_7 -> V_107 ,
V_113 , & V_40 ) ;
if ( V_49 )
goto V_114;
F_55 ( V_118 , V_40 , true ) ;
F_21 ( V_7 -> V_128 ) ;
V_7 -> V_128 = F_19 ( V_40 ) ;
F_21 ( V_40 ) ;
} else {
F_56 ( V_42 ) ;
}
return 0 ;
V_114:
F_56 ( V_42 ) ;
return V_49 ;
}
static void F_60 ( struct V_1 * V_2 ,
struct V_96
* V_97 ,
T_1 V_129 , T_1 V_130 ,
T_1 V_99 , T_3 V_102 )
{
T_1 V_131 = V_132 ;
T_1 V_133 = 0x80 ;
T_1 V_134 = F_61 ( V_129 , V_133 ) ;
T_1 V_135 = V_130 & ~ ( V_133 - 1 ) ;
unsigned V_100 ;
if ( V_129 == V_130 )
return;
if ( V_97 -> V_103 || V_97 -> V_105 ||
! ( V_102 & V_127 ) || ( V_134 >= V_135 ) ) {
V_100 = ( V_130 - V_129 ) / 8 ;
F_40 ( V_2 , V_97 , V_129 ,
V_99 , V_100 , V_136 ,
V_102 ) ;
return;
}
if ( V_129 != V_134 ) {
V_100 = ( V_134 - V_129 ) / 8 ;
F_40 ( V_2 , V_97 , V_129 , V_99 ,
V_100 , V_136 , V_102 ) ;
V_99 += V_136 * V_100 ;
}
V_100 = ( V_135 - V_134 ) / 8 ;
F_40 ( V_2 , V_97 , V_134 , V_99 , V_100 ,
V_136 , V_102 | V_131 ) ;
if ( V_135 != V_130 ) {
V_99 += V_136 * V_100 ;
V_100 = ( V_130 - V_135 ) / 8 ;
F_40 ( V_2 , V_97 , V_135 , V_99 ,
V_100 , V_136 , V_102 ) ;
}
}
static void F_62 ( struct V_1 * V_2 ,
struct V_96
* V_97 ,
struct V_6 * V_7 ,
T_1 V_137 , T_1 V_138 ,
T_1 V_139 , T_3 V_102 )
{
const T_1 V_140 = V_120 - 1 ;
T_1 V_141 , V_142 , V_143 ;
T_1 V_99 ;
T_1 V_123 ;
struct V_94 * V_126 ;
unsigned V_144 ;
T_1 V_145 ;
V_99 = V_137 ;
V_123 = V_99 >> V_5 ;
V_126 = V_7 -> V_26 [ V_123 ] . V_11 . V_12 ;
if ( ( V_99 & ~ V_140 ) == ( V_138 & ~ V_140 ) )
V_144 = V_138 - V_99 ;
else
V_144 = V_120 - ( V_99 & V_140 ) ;
V_141 = F_49 ( V_126 ) ;
V_141 += ( V_99 & V_140 ) * 8 ;
V_142 = V_141 + 8 * V_144 ;
V_143 = V_139 ;
V_99 += V_144 ;
V_139 += V_144 * V_136 ;
while ( V_99 < V_138 ) {
V_123 = V_99 >> V_5 ;
V_126 = V_7 -> V_26 [ V_123 ] . V_11 . V_12 ;
if ( ( V_99 & ~ V_140 ) == ( V_138 & ~ V_140 ) )
V_144 = V_138 - V_99 ;
else
V_144 = V_120 - ( V_99 & V_140 ) ;
V_145 = F_49 ( V_126 ) ;
V_145 += ( V_99 & V_140 ) * 8 ;
if ( V_142 == V_145 ) {
V_142 += 8 * V_144 ;
} else {
F_60 ( V_2 , V_97 ,
V_141 , V_142 ,
V_143 , V_102 ) ;
V_141 = V_145 ;
V_142 = V_145 + 8 * V_144 ;
V_143 = V_139 ;
}
V_99 += V_144 ;
V_139 += V_144 * V_136 ;
}
F_60 ( V_2 , V_97 , V_141 ,
V_142 , V_143 , V_102 ) ;
}
static int F_63 ( struct V_1 * V_2 ,
struct V_40 * V_146 ,
T_1 V_103 ,
T_4 * V_105 ,
struct V_6 * V_7 ,
T_1 V_137 , T_1 V_147 ,
T_3 V_102 , T_1 V_99 ,
struct V_40 * * V_40 )
{
struct V_36 * V_37 ;
void * V_66 = V_113 ;
unsigned V_144 , V_148 , V_124 ;
struct V_41 * V_42 ;
struct V_96 V_97 ;
struct V_40 * V_149 = NULL ;
int V_49 ;
V_37 = F_46 ( V_7 -> V_107 . V_108 , struct V_36 , V_108 ) ;
memset ( & V_97 , 0 , sizeof( V_97 ) ) ;
V_97 . V_103 = V_103 ;
V_97 . V_105 = V_105 ;
if ( ! ( V_102 & V_127 ) )
V_66 = V_150 ;
V_144 = V_147 - V_137 + 1 ;
V_148 = ( V_144 >> F_64 ( V_5 , 11 ) ) + 1 ;
V_124 = 64 ;
if ( V_97 . V_103 ) {
V_124 += V_148 * 7 ;
} else if ( V_97 . V_105 ) {
V_124 += V_148 * 4 ;
V_124 += V_144 * 2 ;
} else {
V_124 += V_148 * 10 ;
V_124 += 2 * 10 ;
}
V_49 = F_51 ( V_2 , V_124 * 4 , & V_42 ) ;
if ( V_49 )
return V_49 ;
V_97 . V_104 = & V_42 -> V_111 [ 0 ] ;
V_49 = F_23 ( V_2 , & V_42 -> V_39 , V_146 ) ;
if ( V_49 )
goto V_114;
V_49 = F_59 ( V_2 , & V_42 -> V_39 , V_7 -> V_13 -> V_17 . V_109 ,
V_66 ) ;
if ( V_49 )
goto V_114;
V_49 = F_47 ( V_7 -> V_13 -> V_17 . V_109 ) ;
if ( V_49 )
goto V_114;
F_62 ( V_2 , & V_97 , V_7 , V_137 ,
V_147 + 1 , V_99 , V_102 ) ;
F_52 ( V_37 , V_97 . V_104 ) ;
F_53 ( V_97 . V_104 -> V_112 > V_124 ) ;
V_49 = F_54 ( V_42 , V_37 , & V_7 -> V_107 ,
V_113 , & V_149 ) ;
if ( V_49 )
goto V_114;
F_55 ( V_7 -> V_13 , V_149 , true ) ;
if ( V_40 ) {
F_21 ( * V_40 ) ;
* V_40 = F_19 ( V_149 ) ;
}
F_21 ( V_149 ) ;
return 0 ;
V_114:
F_56 ( V_42 ) ;
return V_49 ;
}
static int F_65 ( struct V_1 * V_2 ,
struct V_40 * V_146 ,
T_3 V_151 ,
T_4 * V_105 ,
struct V_6 * V_7 ,
struct V_152 * V_153 ,
T_3 V_102 , T_1 V_99 ,
struct V_40 * * V_40 )
{
const T_1 V_154 = 64ULL * 1024ULL * 1024ULL / V_136 ;
T_1 V_103 = 0 , V_137 = V_153 -> V_155 . V_137 ;
int V_49 ;
if ( ! ( V_153 -> V_102 & V_156 ) )
V_102 &= ~ V_156 ;
if ( ! ( V_153 -> V_102 & V_157 ) )
V_102 &= ~ V_157 ;
F_66 ( V_153 ) ;
if ( V_105 ) {
if ( V_102 == V_151 )
V_103 = V_2 -> V_158 . V_159 + ( V_99 >> 12 ) * 8 ;
V_99 = 0 ;
}
V_99 += V_153 -> V_160 ;
if ( ! V_105 || V_103 )
return F_63 ( V_2 , V_146 ,
V_103 , V_105 , V_7 ,
V_137 , V_153 -> V_155 . V_147 ,
V_102 , V_99 , V_40 ) ;
while ( V_137 != V_153 -> V_155 . V_147 + 1 ) {
T_1 V_147 ;
V_147 = F_64 ( ( T_1 ) V_153 -> V_155 . V_147 , V_137 + V_154 - 1 ) ;
V_49 = F_63 ( V_2 , V_146 ,
V_103 , V_105 , V_7 ,
V_137 , V_147 , V_102 , V_99 ,
V_40 ) ;
if ( V_49 )
return V_49 ;
V_137 = V_147 + 1 ;
V_99 += V_154 * V_136 ;
}
return 0 ;
}
int F_67 ( struct V_1 * V_2 ,
struct V_93 * V_95 ,
struct V_161 * V_162 )
{
struct V_6 * V_7 = V_95 -> V_7 ;
struct V_152 * V_153 ;
T_4 * V_105 = NULL ;
T_3 V_151 , V_102 ;
struct V_40 * V_146 ;
T_1 V_99 ;
int V_49 ;
if ( V_162 ) {
struct V_163 * V_164 ;
V_99 = ( T_2 ) V_162 -> V_137 << V_116 ;
switch ( V_162 -> V_165 ) {
case V_166 :
V_164 = F_46 ( V_95 -> V_16 -> V_17 . V_164 , struct
V_163 , V_164 ) ;
V_105 = V_164 -> V_167 ;
break;
case V_168 :
V_99 += V_2 -> V_3 . V_169 ;
break;
default:
break;
}
V_146 = F_68 ( V_95 -> V_16 -> V_17 . V_109 ) ;
} else {
V_99 = 0 ;
V_146 = NULL ;
}
V_102 = F_69 ( V_2 , V_95 -> V_16 -> V_17 . V_164 , V_162 ) ;
V_151 = ( V_2 == V_95 -> V_16 -> V_2 ) ? V_102 : 0 ;
F_9 ( & V_7 -> V_170 ) ;
if ( ! F_70 ( & V_95 -> V_171 ) )
F_71 ( & V_95 -> V_172 , & V_95 -> V_173 ) ;
F_11 ( & V_7 -> V_170 ) ;
F_17 (mapping, &bo_va->invalids, list) {
V_49 = F_65 ( V_2 , V_146 ,
V_151 , V_105 , V_7 ,
V_153 , V_102 , V_99 ,
& V_95 -> V_174 ) ;
if ( V_49 )
return V_49 ;
}
if ( F_72 () ) {
F_17 (mapping, &bo_va->valids, list)
F_73 ( V_153 ) ;
F_17 (mapping, &bo_va->invalids, list)
F_73 ( V_153 ) ;
}
F_9 ( & V_7 -> V_170 ) ;
F_71 ( & V_95 -> V_173 , & V_95 -> V_172 ) ;
F_74 ( & V_95 -> V_171 ) ;
if ( ! V_162 )
F_5 ( & V_95 -> V_171 , & V_7 -> V_175 ) ;
F_11 ( & V_7 -> V_170 ) ;
return 0 ;
}
int F_75 ( struct V_1 * V_2 ,
struct V_6 * V_7 )
{
struct V_152 * V_153 ;
int V_49 ;
while ( ! F_70 ( & V_7 -> V_176 ) ) {
V_153 = F_76 ( & V_7 -> V_176 ,
struct V_152 , V_55 ) ;
F_77 ( & V_153 -> V_55 ) ;
V_49 = F_65 ( V_2 , NULL , 0 , NULL , V_7 , V_153 ,
0 , 0 , NULL ) ;
F_22 ( V_153 ) ;
if ( V_49 )
return V_49 ;
}
return 0 ;
}
int F_78 ( struct V_1 * V_2 ,
struct V_6 * V_7 , struct V_38 * V_39 )
{
struct V_93 * V_95 = NULL ;
int V_49 = 0 ;
F_9 ( & V_7 -> V_170 ) ;
while ( ! F_70 ( & V_7 -> V_177 ) ) {
V_95 = F_76 ( & V_7 -> V_177 ,
struct V_93 , V_171 ) ;
F_11 ( & V_7 -> V_170 ) ;
V_49 = F_67 ( V_2 , V_95 , NULL ) ;
if ( V_49 )
return V_49 ;
F_9 ( & V_7 -> V_170 ) ;
}
F_11 ( & V_7 -> V_170 ) ;
if ( V_95 )
V_49 = F_23 ( V_2 , V_39 , V_95 -> V_174 ) ;
return V_49 ;
}
struct V_93 * F_79 ( struct V_1 * V_2 ,
struct V_6 * V_7 ,
struct V_94 * V_16 )
{
struct V_93 * V_95 ;
V_95 = F_80 ( sizeof( struct V_93 ) , V_51 ) ;
if ( V_95 == NULL ) {
return NULL ;
}
V_95 -> V_7 = V_7 ;
V_95 -> V_16 = V_16 ;
V_95 -> V_178 = 1 ;
F_81 ( & V_95 -> V_179 ) ;
F_81 ( & V_95 -> V_172 ) ;
F_81 ( & V_95 -> V_173 ) ;
F_81 ( & V_95 -> V_171 ) ;
F_82 ( & V_95 -> V_179 , & V_16 -> V_180 ) ;
return V_95 ;
}
int F_83 ( struct V_1 * V_2 ,
struct V_93 * V_95 ,
T_1 V_181 , T_1 V_160 ,
T_1 V_182 , T_3 V_102 )
{
struct V_152 * V_153 ;
struct V_6 * V_7 = V_95 -> V_7 ;
struct V_183 * V_155 ;
unsigned V_184 , V_123 ;
T_1 V_185 ;
int V_49 ;
if ( V_181 & V_186 || V_160 & V_186 ||
V_182 == 0 || V_182 & V_186 )
return - V_187 ;
V_185 = V_181 + V_182 - 1 ;
if ( ( V_181 >= V_185 ) || ( V_160 + V_182 > F_50 ( V_95 -> V_16 ) ) )
return - V_187 ;
V_184 = V_185 / V_136 ;
if ( V_184 >= V_2 -> V_3 . V_4 ) {
F_84 ( V_2 -> V_188 , L_1 ,
V_184 , V_2 -> V_3 . V_4 ) ;
return - V_187 ;
}
V_181 /= V_136 ;
V_185 /= V_136 ;
V_155 = F_85 ( & V_7 -> V_180 , V_181 , V_185 ) ;
if ( V_155 ) {
struct V_152 * V_189 ;
V_189 = F_46 ( V_155 , struct V_152 , V_155 ) ;
F_84 ( V_2 -> V_188 , L_2
L_3 , V_95 -> V_16 , V_181 , V_185 ,
V_189 -> V_155 . V_137 , V_189 -> V_155 . V_147 + 1 ) ;
V_49 = - V_187 ;
goto error;
}
V_153 = F_86 ( sizeof( * V_153 ) , V_51 ) ;
if ( ! V_153 ) {
V_49 = - V_52 ;
goto error;
}
F_81 ( & V_153 -> V_55 ) ;
V_153 -> V_155 . V_137 = V_181 ;
V_153 -> V_155 . V_147 = V_185 ;
V_153 -> V_160 = V_160 ;
V_153 -> V_102 = V_102 ;
F_5 ( & V_153 -> V_55 , & V_95 -> V_173 ) ;
F_87 ( & V_153 -> V_155 , & V_7 -> V_180 ) ;
V_181 >>= V_5 ;
V_185 >>= V_5 ;
F_88 ( V_185 >= F_1 ( V_2 ) ) ;
if ( V_185 > V_7 -> V_25 )
V_7 -> V_25 = V_185 ;
for ( V_123 = V_181 ; V_123 <= V_185 ; ++ V_123 ) {
struct V_190 * V_109 = V_7 -> V_13 -> V_17 . V_109 ;
struct V_10 * V_11 ;
struct V_94 * V_126 ;
V_11 = & V_7 -> V_26 [ V_123 ] . V_11 ;
if ( V_11 -> V_12 )
continue;
V_49 = F_89 ( V_2 , V_120 * 8 ,
V_136 , true ,
V_191 ,
V_192 ,
NULL , V_109 , & V_126 ) ;
if ( V_49 )
goto V_114;
V_126 -> V_193 = F_90 ( V_7 -> V_13 ) ;
V_49 = F_45 ( V_2 , V_7 , V_126 ) ;
if ( V_49 ) {
F_91 ( & V_126 ) ;
goto V_114;
}
V_11 -> V_12 = V_126 ;
V_11 -> V_14 = 0 ;
V_11 -> V_15 . V_16 = & V_11 -> V_12 -> V_17 ;
V_11 -> V_15 . V_18 = true ;
V_11 -> V_19 = NULL ;
V_7 -> V_26 [ V_123 ] . V_99 = 0 ;
}
return 0 ;
V_114:
F_77 ( & V_153 -> V_55 ) ;
F_92 ( & V_153 -> V_155 , & V_7 -> V_180 ) ;
F_93 ( V_95 , V_153 ) ;
F_22 ( V_153 ) ;
error:
return V_49 ;
}
int F_94 ( struct V_1 * V_2 ,
struct V_93 * V_95 ,
T_1 V_181 )
{
struct V_152 * V_153 ;
struct V_6 * V_7 = V_95 -> V_7 ;
bool V_194 = true ;
V_181 /= V_136 ;
F_17 (mapping, &bo_va->valids, list) {
if ( V_153 -> V_155 . V_137 == V_181 )
break;
}
if ( & V_153 -> V_55 == & V_95 -> V_172 ) {
V_194 = false ;
F_17 (mapping, &bo_va->invalids, list) {
if ( V_153 -> V_155 . V_137 == V_181 )
break;
}
if ( & V_153 -> V_55 == & V_95 -> V_173 )
return - V_195 ;
}
F_77 ( & V_153 -> V_55 ) ;
F_92 ( & V_153 -> V_155 , & V_7 -> V_180 ) ;
F_93 ( V_95 , V_153 ) ;
if ( V_194 )
F_5 ( & V_153 -> V_55 , & V_7 -> V_176 ) ;
else
F_22 ( V_153 ) ;
return 0 ;
}
void F_95 ( struct V_1 * V_2 ,
struct V_93 * V_95 )
{
struct V_152 * V_153 , * V_196 ;
struct V_6 * V_7 = V_95 -> V_7 ;
F_77 ( & V_95 -> V_179 ) ;
F_9 ( & V_7 -> V_170 ) ;
F_77 ( & V_95 -> V_171 ) ;
F_11 ( & V_7 -> V_170 ) ;
F_96 (mapping, next, &bo_va->valids, list) {
F_77 ( & V_153 -> V_55 ) ;
F_92 ( & V_153 -> V_155 , & V_7 -> V_180 ) ;
F_93 ( V_95 , V_153 ) ;
F_5 ( & V_153 -> V_55 , & V_7 -> V_176 ) ;
}
F_96 (mapping, next, &bo_va->invalids, list) {
F_77 ( & V_153 -> V_55 ) ;
F_92 ( & V_153 -> V_155 , & V_7 -> V_180 ) ;
F_22 ( V_153 ) ;
}
F_21 ( V_95 -> V_174 ) ;
F_22 ( V_95 ) ;
}
void F_97 ( struct V_1 * V_2 ,
struct V_94 * V_16 )
{
struct V_93 * V_95 ;
F_17 (bo_va, &bo->va, bo_list) {
F_9 ( & V_95 -> V_7 -> V_170 ) ;
if ( F_70 ( & V_95 -> V_171 ) )
F_5 ( & V_95 -> V_171 , & V_95 -> V_7 -> V_177 ) ;
F_11 ( & V_95 -> V_7 -> V_170 ) ;
}
}
int F_98 ( struct V_1 * V_2 , struct V_6 * V_7 )
{
const unsigned V_197 = F_64 ( V_198 ,
V_120 * 8 ) ;
unsigned V_199 , V_200 ;
unsigned V_201 ;
struct V_36 * V_37 ;
struct V_202 * V_203 ;
int V_23 , V_49 ;
for ( V_23 = 0 ; V_23 < V_65 ; ++ V_23 )
V_7 -> V_64 [ V_23 ] = NULL ;
V_7 -> V_180 = V_204 ;
V_7 -> V_67 = F_99 ( & V_2 -> V_3 . V_205 ) ;
F_100 ( & V_7 -> V_170 ) ;
F_81 ( & V_7 -> V_177 ) ;
F_81 ( & V_7 -> V_175 ) ;
F_81 ( & V_7 -> V_176 ) ;
V_199 = F_2 ( V_2 ) ;
V_200 = F_1 ( V_2 ) ;
V_7 -> V_26 = F_101 ( V_200 , sizeof( struct V_206 ) ) ;
if ( V_7 -> V_26 == NULL ) {
F_102 ( L_4 ) ;
return - V_52 ;
}
V_201 = F_103 ( & V_2 -> V_3 . V_207 ) ;
V_201 %= V_2 -> V_3 . V_208 ;
V_37 = V_2 -> V_3 . V_209 [ V_201 ] ;
V_203 = & V_37 -> V_108 . V_210 [ V_211 ] ;
V_49 = F_104 ( & V_37 -> V_108 , & V_7 -> V_107 ,
V_203 , V_212 ) ;
if ( V_49 )
goto V_213;
V_7 -> V_128 = NULL ;
V_49 = F_89 ( V_2 , V_199 , V_197 , true ,
V_191 ,
V_192 ,
NULL , NULL , & V_7 -> V_13 ) ;
if ( V_49 )
goto V_214;
V_49 = F_105 ( V_7 -> V_13 , false ) ;
if ( V_49 )
goto V_215;
V_49 = F_45 ( V_2 , V_7 , V_7 -> V_13 ) ;
F_106 ( V_7 -> V_13 ) ;
if ( V_49 )
goto V_215;
V_7 -> V_24 = F_7 ( & V_2 -> V_22 ) ;
return 0 ;
V_215:
F_91 ( & V_7 -> V_13 ) ;
V_7 -> V_13 = NULL ;
V_214:
F_107 ( & V_37 -> V_108 , & V_7 -> V_107 ) ;
V_213:
F_108 ( V_7 -> V_26 ) ;
return V_49 ;
}
void F_109 ( struct V_1 * V_2 , struct V_6 * V_7 )
{
struct V_152 * V_153 , * V_189 ;
int V_23 ;
F_107 ( V_7 -> V_107 . V_108 , & V_7 -> V_107 ) ;
if ( ! F_110 ( & V_7 -> V_180 ) ) {
F_84 ( V_2 -> V_188 , L_5 ) ;
}
F_111 (mapping, tmp, &vm->va, it.rb) {
F_77 ( & V_153 -> V_55 ) ;
F_92 ( & V_153 -> V_155 , & V_7 -> V_180 ) ;
F_22 ( V_153 ) ;
}
F_96 (mapping, tmp, &vm->freed, list) {
F_77 ( & V_153 -> V_55 ) ;
F_22 ( V_153 ) ;
}
for ( V_23 = 0 ; V_23 < F_1 ( V_2 ) ; V_23 ++ )
F_91 ( & V_7 -> V_26 [ V_23 ] . V_11 . V_12 ) ;
F_108 ( V_7 -> V_26 ) ;
F_91 ( & V_7 -> V_13 ) ;
F_21 ( V_7 -> V_128 ) ;
}
void F_112 ( struct V_1 * V_2 )
{
unsigned V_23 ;
F_81 ( & V_2 -> V_3 . V_56 ) ;
for ( V_23 = 1 ; V_23 < V_2 -> V_3 . V_50 ; ++ V_23 ) {
F_38 ( V_2 , V_23 ) ;
F_113 ( & V_2 -> V_3 . V_64 [ V_23 ] . V_54 ) ;
F_82 ( & V_2 -> V_3 . V_64 [ V_23 ] . V_55 ,
& V_2 -> V_3 . V_56 ) ;
}
V_2 -> V_3 . V_43 = F_114 ( V_65 ) ;
for ( V_23 = 0 ; V_23 < V_65 ; ++ V_23 )
V_2 -> V_3 . V_57 [ V_23 ] = 0 ;
F_115 ( & V_2 -> V_3 . V_207 , 0 ) ;
F_29 ( & V_2 -> V_3 . V_205 , 0 ) ;
}
void F_116 ( struct V_1 * V_2 )
{
unsigned V_23 ;
for ( V_23 = 0 ; V_23 < V_216 ; ++ V_23 ) {
struct V_32 * V_33 = & V_2 -> V_3 . V_64 [ V_23 ] ;
F_21 ( V_2 -> V_3 . V_64 [ V_23 ] . V_74 ) ;
F_117 ( & V_2 -> V_3 . V_64 [ V_23 ] . V_54 ) ;
F_21 ( V_33 -> V_72 ) ;
}
}
