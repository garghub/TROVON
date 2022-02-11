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
void F_6 ( struct V_6 * V_7 , struct V_8 * V_21 )
{
unsigned V_22 ;
for ( V_22 = 0 ; V_22 <= V_7 -> V_23 ; ++ V_22 ) {
struct V_10 * V_11 = & V_7 -> V_24 [ V_22 ] . V_11 ;
if ( ! V_11 -> V_12 )
continue;
F_5 ( & V_11 -> V_15 . V_20 , V_21 ) ;
}
}
void F_7 ( struct V_1 * V_2 ,
struct V_6 * V_7 )
{
struct V_25 * V_26 = V_2 -> V_27 . V_28 . V_26 ;
unsigned V_22 ;
F_8 ( & V_26 -> V_29 ) ;
for ( V_22 = 0 ; V_22 <= V_7 -> V_23 ; ++ V_22 ) {
struct V_10 * V_11 = & V_7 -> V_24 [ V_22 ] . V_11 ;
if ( ! V_11 -> V_12 )
continue;
F_9 ( & V_11 -> V_12 -> V_17 ) ;
}
F_10 ( & V_26 -> V_29 ) ;
}
int F_11 ( struct V_6 * V_7 , struct V_30 * V_31 ,
struct V_32 * V_33 , struct V_34 * V_34 ,
unsigned * V_35 , T_1 * V_36 )
{
T_1 V_37 = F_12 ( V_7 -> V_13 ) ;
struct V_1 * V_2 = V_31 -> V_2 ;
struct V_34 * V_38 = V_33 -> V_39 ;
struct V_40 * V_41 ;
unsigned V_22 = V_31 -> V_42 ;
int V_43 ;
F_13 ( & V_2 -> V_3 . V_44 ) ;
do {
struct V_34 * V_45 ;
V_41 = V_7 -> V_46 [ V_22 ++ ] ;
if ( V_22 == V_47 )
V_22 = 0 ;
if ( ! V_41 )
continue;
if ( F_14 ( & V_41 -> V_48 ) != V_7 -> V_49 )
continue;
if ( V_37 != V_41 -> V_50 )
continue;
if ( V_41 -> V_51 != V_31 &&
( ! V_41 -> V_52 || ! F_15 ( V_41 -> V_52 ) ) )
continue;
V_45 = V_41 -> V_53 ;
if ( V_38 && ( ! V_45 || F_16 ( V_38 , V_45 ) ) )
continue;
if ( V_41 -> V_51 == V_31 ) {
V_43 = F_17 ( V_31 -> V_2 , V_33 ,
V_41 -> V_54 ) ;
if ( V_43 )
goto error;
}
V_43 = F_17 ( V_31 -> V_2 , & V_41 -> V_55 , V_34 ) ;
if ( V_43 )
goto error;
F_18 ( & V_41 -> V_56 , & V_2 -> V_3 . V_57 ) ;
V_7 -> V_46 [ V_31 -> V_42 ] = V_41 ;
* V_35 = V_41 - V_2 -> V_3 . V_46 ;
* V_36 = V_58 ;
F_19 ( V_7 , V_31 -> V_42 , * V_35 , * V_36 ) ;
F_20 ( & V_2 -> V_3 . V_44 ) ;
return 0 ;
} while ( V_22 != V_31 -> V_42 );
V_41 = F_21 ( & V_2 -> V_3 . V_57 ,
struct V_40 ,
V_56 ) ;
if ( ! F_22 ( & V_41 -> V_55 ) ) {
struct V_8 * V_20 = & V_2 -> V_3 . V_57 ;
struct V_40 * V_59 ;
F_23 (id, tmp, &adev->vm_manager.ids_lru,
list) {
if ( F_22 ( & V_41 -> V_55 ) ) {
F_24 ( & V_41 -> V_56 , V_20 ) ;
V_20 = & V_41 -> V_56 ;
}
}
V_41 = F_21 ( & V_2 -> V_3 . V_57 ,
struct V_40 ,
V_56 ) ;
}
V_43 = F_25 ( V_33 , & V_41 -> V_55 , V_34 ) ;
if ( V_43 )
goto error;
F_26 ( V_41 -> V_54 ) ;
V_41 -> V_54 = F_27 ( V_34 ) ;
F_26 ( V_41 -> V_52 ) ;
V_41 -> V_52 = NULL ;
F_26 ( V_41 -> V_53 ) ;
V_41 -> V_53 = F_27 ( V_38 ) ;
V_41 -> V_50 = V_37 ;
F_18 ( & V_41 -> V_56 , & V_2 -> V_3 . V_57 ) ;
V_41 -> V_51 = V_31 ;
F_28 ( & V_41 -> V_48 , V_7 -> V_49 ) ;
V_7 -> V_46 [ V_31 -> V_42 ] = V_41 ;
* V_35 = V_41 - V_2 -> V_3 . V_46 ;
* V_36 = V_37 ;
F_19 ( V_7 , V_31 -> V_42 , * V_35 , * V_36 ) ;
error:
F_20 ( & V_2 -> V_3 . V_44 ) ;
return V_43 ;
}
int F_29 ( struct V_30 * V_31 ,
unsigned V_35 , T_1 V_37 ,
T_2 V_60 , T_2 V_61 ,
T_2 V_62 , T_2 V_63 ,
T_2 V_64 , T_2 V_65 )
{
struct V_1 * V_2 = V_31 -> V_2 ;
struct V_40 * V_41 = & V_2 -> V_3 . V_46 [ V_35 ] ;
bool V_66 = V_31 -> V_67 -> V_68 && (
V_41 -> V_60 != V_60 ||
V_41 -> V_61 != V_61 ||
V_41 -> V_62 != V_62 ||
V_41 -> V_63 != V_63 ||
V_41 -> V_64 != V_64 ||
V_41 -> V_65 != V_65 ) ;
int V_43 ;
if ( V_31 -> V_67 -> V_69 && (
V_37 != V_58 || V_66 ||
V_31 -> type == V_70 ) )
F_30 ( V_31 ) ;
if ( V_31 -> V_67 -> V_71 &&
V_37 != V_58 ) {
struct V_34 * V_34 ;
F_31 ( V_37 , V_31 -> V_42 , V_35 ) ;
F_32 ( V_31 , V_35 , V_37 ) ;
F_13 ( & V_2 -> V_3 . V_44 ) ;
if ( ( V_41 -> V_50 == V_37 ) && ( V_41 -> V_51 == V_31 ) ) {
V_43 = F_33 ( V_31 , & V_34 ) ;
if ( V_43 ) {
F_20 ( & V_2 -> V_3 . V_44 ) ;
return V_43 ;
}
F_26 ( V_41 -> V_52 ) ;
V_41 -> V_52 = V_34 ;
}
F_20 ( & V_2 -> V_3 . V_44 ) ;
}
if ( V_66 ) {
V_41 -> V_60 = V_60 ;
V_41 -> V_61 = V_61 ;
V_41 -> V_62 = V_62 ;
V_41 -> V_63 = V_63 ;
V_41 -> V_64 = V_64 ;
V_41 -> V_65 = V_65 ;
F_34 ( V_31 , V_35 ,
V_60 , V_61 ,
V_62 , V_63 ,
V_64 , V_65 ) ;
}
return 0 ;
}
void F_35 ( struct V_1 * V_2 , unsigned V_35 )
{
struct V_40 * V_41 = & V_2 -> V_3 . V_46 [ V_35 ] ;
V_41 -> V_60 = 0 ;
V_41 -> V_61 = 0 ;
V_41 -> V_62 = 0 ;
V_41 -> V_63 = 0 ;
V_41 -> V_64 = 0 ;
V_41 -> V_65 = 0 ;
}
struct V_72 * F_36 ( struct V_6 * V_7 ,
struct V_73 * V_16 )
{
struct V_72 * V_74 ;
F_37 (bo_va, &bo->va, bo_list) {
if ( V_74 -> V_7 == V_7 ) {
return V_74 ;
}
}
return NULL ;
}
static void F_38 ( struct V_1 * V_2 ,
struct V_75
* V_76 ,
T_1 V_77 , T_1 V_78 ,
unsigned V_79 , T_2 V_80 ,
T_2 V_81 )
{
F_39 ( V_77 , V_78 , V_79 , V_80 , V_81 ) ;
if ( V_76 -> V_82 ) {
F_40 ( V_2 , V_76 -> V_83 ,
V_77 , ( V_76 -> V_82 + ( V_78 >> 12 ) * 8 ) , V_79 ) ;
} else if ( V_76 -> V_84 ) {
F_41 ( V_2 , V_76 -> V_83 ,
V_76 -> V_84 ,
V_77 , V_78 , V_79 , V_80 , V_81 ) ;
} else if ( V_79 < 3 ) {
F_41 ( V_2 , V_76 -> V_83 , NULL , V_77 , V_78 ,
V_79 , V_80 , V_81 ) ;
} else {
F_42 ( V_2 , V_76 -> V_83 , V_77 , V_78 ,
V_79 , V_80 , V_81 ) ;
}
}
static int F_43 ( struct V_1 * V_2 ,
struct V_6 * V_7 ,
struct V_73 * V_16 )
{
struct V_30 * V_31 ;
struct V_34 * V_34 = NULL ;
struct V_85 * V_86 ;
struct V_75 V_76 ;
unsigned V_87 ;
T_1 V_78 ;
int V_43 ;
memset ( & V_76 , 0 , sizeof( V_76 ) ) ;
V_31 = F_44 ( V_7 -> V_88 . V_89 , struct V_30 , V_89 ) ;
V_43 = F_45 ( V_16 -> V_17 . V_90 ) ;
if ( V_43 )
return V_43 ;
V_43 = F_46 ( & V_16 -> V_17 , & V_16 -> V_91 , true , false ) ;
if ( V_43 )
goto error;
V_78 = F_12 ( V_16 ) ;
V_87 = F_47 ( V_16 ) / 8 ;
V_43 = F_48 ( V_2 , 64 , & V_86 ) ;
if ( V_43 )
goto error;
V_76 . V_83 = & V_86 -> V_92 [ 0 ] ;
F_38 ( V_2 , & V_76 , V_78 , 0 , V_87 ,
0 , 0 ) ;
F_49 ( V_31 , & V_86 -> V_92 [ 0 ] ) ;
F_50 ( V_86 -> V_92 [ 0 ] . V_93 > 64 ) ;
V_43 = F_51 ( V_86 , V_31 , & V_7 -> V_88 ,
V_94 , & V_34 ) ;
if ( V_43 )
goto V_95;
F_52 ( V_16 , V_34 , true ) ;
F_26 ( V_34 ) ;
return 0 ;
V_95:
F_53 ( V_86 ) ;
error:
return V_43 ;
}
T_1 F_54 ( const T_3 * V_84 , T_1 V_78 )
{
T_1 V_96 ;
if ( V_84 ) {
V_96 = V_84 [ V_78 >> V_97 ] ;
V_96 |= V_78 & ( ~ V_98 ) ;
} else {
V_96 = V_78 ;
}
V_96 &= 0xFFFFFFFFFFFFF000ULL ;
return V_96 ;
}
int F_55 ( struct V_1 * V_2 ,
struct V_6 * V_7 )
{
struct V_30 * V_31 ;
struct V_73 * V_99 = V_7 -> V_13 ;
T_1 V_37 = F_12 ( V_99 ) ;
T_2 V_80 = V_100 * 8 ;
T_1 V_101 = ~ 0 , V_102 = ~ 0 ;
unsigned V_79 = 0 , V_103 , V_104 ;
struct V_85 * V_86 ;
struct V_75 V_76 ;
struct V_34 * V_34 = NULL ;
int V_43 ;
memset ( & V_76 , 0 , sizeof( V_76 ) ) ;
V_31 = F_44 ( V_7 -> V_88 . V_89 , struct V_30 , V_89 ) ;
V_104 = 64 ;
V_104 += V_7 -> V_23 * 6 ;
V_43 = F_48 ( V_2 , V_104 * 4 , & V_86 ) ;
if ( V_43 )
return V_43 ;
V_76 . V_83 = & V_86 -> V_92 [ 0 ] ;
for ( V_103 = 0 ; V_103 <= V_7 -> V_23 ; ++ V_103 ) {
struct V_73 * V_16 = V_7 -> V_24 [ V_103 ] . V_11 . V_12 ;
T_1 V_105 , V_106 ;
if ( V_16 == NULL )
continue;
V_106 = F_12 ( V_16 ) ;
if ( V_7 -> V_24 [ V_103 ] . V_78 == V_106 )
continue;
V_7 -> V_24 [ V_103 ] . V_78 = V_106 ;
V_105 = V_37 + V_103 * 8 ;
if ( ( ( V_101 + 8 * V_79 ) != V_105 ) ||
( ( V_102 + V_80 * V_79 ) != V_106 ) ) {
if ( V_79 ) {
F_38 ( V_2 , & V_76 ,
V_101 , V_102 ,
V_79 , V_80 ,
V_107 ) ;
}
V_79 = 1 ;
V_101 = V_105 ;
V_102 = V_106 ;
} else {
++ V_79 ;
}
}
if ( V_79 )
F_38 ( V_2 , & V_76 ,
V_101 , V_102 ,
V_79 , V_80 , V_107 ) ;
if ( V_76 . V_83 -> V_93 != 0 ) {
F_49 ( V_31 , V_76 . V_83 ) ;
F_56 ( V_2 , & V_86 -> V_33 , V_99 -> V_17 . V_90 ,
V_94 ) ;
F_50 ( V_76 . V_83 -> V_93 > V_104 ) ;
V_43 = F_51 ( V_86 , V_31 , & V_7 -> V_88 ,
V_94 , & V_34 ) ;
if ( V_43 )
goto V_95;
F_52 ( V_99 , V_34 , true ) ;
F_26 ( V_7 -> V_108 ) ;
V_7 -> V_108 = F_27 ( V_34 ) ;
F_26 ( V_34 ) ;
} else {
F_53 ( V_86 ) ;
}
return 0 ;
V_95:
F_53 ( V_86 ) ;
return V_43 ;
}
static void F_57 ( struct V_1 * V_2 ,
struct V_75
* V_76 ,
T_1 V_109 , T_1 V_110 ,
T_1 V_78 , T_2 V_81 )
{
T_1 V_111 = V_112 ;
T_1 V_113 = 0x80 ;
T_1 V_114 = F_58 ( V_109 , V_113 ) ;
T_1 V_115 = V_110 & ~ ( V_113 - 1 ) ;
unsigned V_79 ;
if ( V_109 == V_110 )
return;
if ( V_76 -> V_82 || V_76 -> V_84 ||
! ( V_81 & V_107 ) || ( V_114 >= V_115 ) ) {
V_79 = ( V_110 - V_109 ) / 8 ;
F_38 ( V_2 , V_76 , V_109 ,
V_78 , V_79 , V_116 ,
V_81 ) ;
return;
}
if ( V_109 != V_114 ) {
V_79 = ( V_114 - V_109 ) / 8 ;
F_38 ( V_2 , V_76 , V_109 , V_78 ,
V_79 , V_116 , V_81 ) ;
V_78 += V_116 * V_79 ;
}
V_79 = ( V_115 - V_114 ) / 8 ;
F_38 ( V_2 , V_76 , V_114 , V_78 , V_79 ,
V_116 , V_81 | V_111 ) ;
if ( V_115 != V_110 ) {
V_78 += V_116 * V_79 ;
V_79 = ( V_110 - V_115 ) / 8 ;
F_38 ( V_2 , V_76 , V_115 , V_78 ,
V_79 , V_116 , V_81 ) ;
}
}
static void F_59 ( struct V_1 * V_2 ,
struct V_75
* V_76 ,
struct V_6 * V_7 ,
T_1 V_117 , T_1 V_118 ,
T_1 V_119 , T_2 V_81 )
{
const T_1 V_120 = V_100 - 1 ;
T_1 V_121 = ~ 0 , V_122 = ~ 0 , V_123 = ~ 0 ;
T_1 V_78 ;
for ( V_78 = V_117 ; V_78 < V_118 ; ) {
T_1 V_103 = V_78 >> V_5 ;
struct V_73 * V_106 = V_7 -> V_24 [ V_103 ] . V_11 . V_12 ;
unsigned V_124 ;
T_1 V_109 ;
if ( ( V_78 & ~ V_120 ) == ( V_118 & ~ V_120 ) )
V_124 = V_118 - V_78 ;
else
V_124 = V_100 - ( V_78 & V_120 ) ;
V_109 = F_12 ( V_106 ) ;
V_109 += ( V_78 & V_120 ) * 8 ;
if ( V_122 != V_109 ) {
F_57 ( V_2 , V_76 ,
V_121 , V_122 ,
V_123 , V_81 ) ;
V_121 = V_109 ;
V_122 = V_109 + 8 * V_124 ;
V_123 = V_119 ;
} else {
V_122 += 8 * V_124 ;
}
V_78 += V_124 ;
V_119 += V_124 * V_116 ;
}
F_57 ( V_2 , V_76 , V_121 ,
V_122 , V_123 , V_81 ) ;
}
static int F_60 ( struct V_1 * V_2 ,
T_1 V_82 ,
T_3 * V_84 ,
struct V_6 * V_7 ,
T_1 V_117 , T_1 V_125 ,
T_2 V_81 , T_1 V_78 ,
struct V_34 * * V_34 )
{
struct V_30 * V_31 ;
void * V_48 = V_94 ;
unsigned V_124 , V_126 , V_104 ;
struct V_85 * V_86 ;
struct V_75 V_76 ;
struct V_34 * V_127 = NULL ;
int V_43 ;
V_31 = F_44 ( V_7 -> V_88 . V_89 , struct V_30 , V_89 ) ;
memset ( & V_76 , 0 , sizeof( V_76 ) ) ;
V_76 . V_82 = V_82 ;
V_76 . V_84 = V_84 ;
if ( ! ( V_81 & V_107 ) )
V_48 = V_128 ;
V_124 = V_125 - V_117 + 1 ;
V_126 = ( V_124 >> F_61 ( V_5 , 11 ) ) + 1 ;
V_104 = 64 ;
if ( V_76 . V_82 ) {
V_104 += V_126 * 7 ;
} else if ( V_76 . V_84 ) {
V_104 += V_126 * 4 ;
V_104 += V_124 * 2 ;
} else {
V_104 += V_126 * 10 ;
V_104 += 2 * 10 ;
}
V_43 = F_48 ( V_2 , V_104 * 4 , & V_86 ) ;
if ( V_43 )
return V_43 ;
V_76 . V_83 = & V_86 -> V_92 [ 0 ] ;
V_43 = F_56 ( V_2 , & V_86 -> V_33 , V_7 -> V_13 -> V_17 . V_90 ,
V_48 ) ;
if ( V_43 )
goto V_95;
V_43 = F_45 ( V_7 -> V_13 -> V_17 . V_90 ) ;
if ( V_43 )
goto V_95;
F_59 ( V_2 , & V_76 , V_7 , V_117 ,
V_125 + 1 , V_78 , V_81 ) ;
F_49 ( V_31 , V_76 . V_83 ) ;
F_50 ( V_76 . V_83 -> V_93 > V_104 ) ;
V_43 = F_51 ( V_86 , V_31 , & V_7 -> V_88 ,
V_94 , & V_127 ) ;
if ( V_43 )
goto V_95;
F_52 ( V_7 -> V_13 , V_127 , true ) ;
if ( V_34 ) {
F_26 ( * V_34 ) ;
* V_34 = F_27 ( V_127 ) ;
}
F_26 ( V_127 ) ;
return 0 ;
V_95:
F_53 ( V_86 ) ;
return V_43 ;
}
static int F_62 ( struct V_1 * V_2 ,
T_2 V_129 ,
T_3 * V_84 ,
struct V_6 * V_7 ,
struct V_130 * V_131 ,
T_2 V_81 , T_1 V_78 ,
struct V_34 * * V_34 )
{
const T_1 V_132 = 64ULL * 1024ULL * 1024ULL / V_116 ;
T_1 V_82 = 0 , V_117 = V_131 -> V_133 . V_117 ;
int V_43 ;
if ( ! ( V_131 -> V_81 & V_134 ) )
V_81 &= ~ V_134 ;
if ( ! ( V_131 -> V_81 & V_135 ) )
V_81 &= ~ V_135 ;
F_63 ( V_131 ) ;
if ( V_84 ) {
if ( V_81 == V_129 )
V_82 = V_2 -> V_136 . V_137 + ( V_78 >> 12 ) * 8 ;
V_78 = 0 ;
}
V_78 += V_131 -> V_138 ;
if ( ! V_84 || V_82 )
return F_60 ( V_2 , V_82 , V_84 , V_7 ,
V_117 , V_131 -> V_133 . V_125 ,
V_81 , V_78 , V_34 ) ;
while ( V_117 != V_131 -> V_133 . V_125 + 1 ) {
T_1 V_125 ;
V_125 = F_61 ( ( T_1 ) V_131 -> V_133 . V_125 , V_117 + V_132 - 1 ) ;
V_43 = F_60 ( V_2 , V_82 , V_84 , V_7 ,
V_117 , V_125 , V_81 , V_78 ,
V_34 ) ;
if ( V_43 )
return V_43 ;
V_117 = V_125 + 1 ;
V_78 += V_132 * V_116 ;
}
return 0 ;
}
int F_64 ( struct V_1 * V_2 ,
struct V_72 * V_74 ,
struct V_139 * V_140 )
{
struct V_6 * V_7 = V_74 -> V_7 ;
struct V_130 * V_131 ;
T_3 * V_84 = NULL ;
T_2 V_129 , V_81 ;
T_1 V_78 ;
int V_43 ;
if ( V_140 ) {
struct V_141 * V_142 ;
V_78 = ( V_143 ) V_140 -> V_117 << V_97 ;
switch ( V_140 -> V_144 ) {
case V_145 :
V_142 = F_44 ( V_74 -> V_16 -> V_17 . V_142 , struct
V_141 , V_142 ) ;
V_84 = V_142 -> V_146 ;
break;
case V_147 :
V_78 += V_2 -> V_3 . V_148 ;
break;
default:
break;
}
} else {
V_78 = 0 ;
}
V_81 = F_65 ( V_2 , V_74 -> V_16 -> V_17 . V_142 , V_140 ) ;
V_129 = ( V_2 == V_74 -> V_16 -> V_2 ) ? V_81 : 0 ;
F_8 ( & V_7 -> V_149 ) ;
if ( ! F_66 ( & V_74 -> V_150 ) )
F_67 ( & V_74 -> V_151 , & V_74 -> V_152 ) ;
F_10 ( & V_7 -> V_149 ) ;
F_37 (mapping, &bo_va->invalids, list) {
V_43 = F_62 ( V_2 , V_129 , V_84 , V_7 ,
V_131 , V_81 , V_78 ,
& V_74 -> V_153 ) ;
if ( V_43 )
return V_43 ;
}
if ( F_68 () ) {
F_37 (mapping, &bo_va->valids, list)
F_69 ( V_131 ) ;
F_37 (mapping, &bo_va->invalids, list)
F_69 ( V_131 ) ;
}
F_8 ( & V_7 -> V_149 ) ;
F_67 ( & V_74 -> V_152 , & V_74 -> V_151 ) ;
F_70 ( & V_74 -> V_150 ) ;
if ( ! V_140 )
F_5 ( & V_74 -> V_150 , & V_7 -> V_154 ) ;
F_10 ( & V_7 -> V_149 ) ;
return 0 ;
}
int F_71 ( struct V_1 * V_2 ,
struct V_6 * V_7 )
{
struct V_130 * V_131 ;
int V_43 ;
while ( ! F_66 ( & V_7 -> V_155 ) ) {
V_131 = F_21 ( & V_7 -> V_155 ,
struct V_130 , V_56 ) ;
F_72 ( & V_131 -> V_56 ) ;
V_43 = F_62 ( V_2 , 0 , NULL , V_7 , V_131 ,
0 , 0 , NULL ) ;
F_73 ( V_131 ) ;
if ( V_43 )
return V_43 ;
}
return 0 ;
}
int F_74 ( struct V_1 * V_2 ,
struct V_6 * V_7 , struct V_32 * V_33 )
{
struct V_72 * V_74 = NULL ;
int V_43 = 0 ;
F_8 ( & V_7 -> V_149 ) ;
while ( ! F_66 ( & V_7 -> V_156 ) ) {
V_74 = F_21 ( & V_7 -> V_156 ,
struct V_72 , V_150 ) ;
F_10 ( & V_7 -> V_149 ) ;
V_43 = F_64 ( V_2 , V_74 , NULL ) ;
if ( V_43 )
return V_43 ;
F_8 ( & V_7 -> V_149 ) ;
}
F_10 ( & V_7 -> V_149 ) ;
if ( V_74 )
V_43 = F_17 ( V_2 , V_33 , V_74 -> V_153 ) ;
return V_43 ;
}
struct V_72 * F_75 ( struct V_1 * V_2 ,
struct V_6 * V_7 ,
struct V_73 * V_16 )
{
struct V_72 * V_74 ;
V_74 = F_76 ( sizeof( struct V_72 ) , V_157 ) ;
if ( V_74 == NULL ) {
return NULL ;
}
V_74 -> V_7 = V_7 ;
V_74 -> V_16 = V_16 ;
V_74 -> V_158 = 1 ;
F_77 ( & V_74 -> V_159 ) ;
F_77 ( & V_74 -> V_151 ) ;
F_77 ( & V_74 -> V_152 ) ;
F_77 ( & V_74 -> V_150 ) ;
F_78 ( & V_74 -> V_159 , & V_16 -> V_160 ) ;
return V_74 ;
}
int F_79 ( struct V_1 * V_2 ,
struct V_72 * V_74 ,
T_1 V_161 , T_1 V_138 ,
T_1 V_162 , T_2 V_81 )
{
struct V_130 * V_131 ;
struct V_6 * V_7 = V_74 -> V_7 ;
struct V_163 * V_133 ;
unsigned V_164 , V_103 ;
T_1 V_165 ;
int V_43 ;
if ( V_161 & V_166 || V_138 & V_166 ||
V_162 == 0 || V_162 & V_166 )
return - V_167 ;
V_165 = V_161 + V_162 - 1 ;
if ( ( V_161 >= V_165 ) || ( V_138 + V_162 > F_47 ( V_74 -> V_16 ) ) )
return - V_167 ;
V_164 = V_165 / V_116 ;
if ( V_164 >= V_2 -> V_3 . V_4 ) {
F_80 ( V_2 -> V_168 , L_1 ,
V_164 , V_2 -> V_3 . V_4 ) ;
return - V_167 ;
}
V_161 /= V_116 ;
V_165 /= V_116 ;
V_133 = F_81 ( & V_7 -> V_160 , V_161 , V_165 ) ;
if ( V_133 ) {
struct V_130 * V_59 ;
V_59 = F_44 ( V_133 , struct V_130 , V_133 ) ;
F_80 ( V_2 -> V_168 , L_2
L_3 , V_74 -> V_16 , V_161 , V_165 ,
V_59 -> V_133 . V_117 , V_59 -> V_133 . V_125 + 1 ) ;
V_43 = - V_167 ;
goto error;
}
V_131 = F_82 ( sizeof( * V_131 ) , V_157 ) ;
if ( ! V_131 ) {
V_43 = - V_169 ;
goto error;
}
F_77 ( & V_131 -> V_56 ) ;
V_131 -> V_133 . V_117 = V_161 ;
V_131 -> V_133 . V_125 = V_165 ;
V_131 -> V_138 = V_138 ;
V_131 -> V_81 = V_81 ;
F_5 ( & V_131 -> V_56 , & V_74 -> V_152 ) ;
F_83 ( & V_131 -> V_133 , & V_7 -> V_160 ) ;
V_161 >>= V_5 ;
V_165 >>= V_5 ;
F_84 ( V_165 >= F_1 ( V_2 ) ) ;
if ( V_165 > V_7 -> V_23 )
V_7 -> V_23 = V_165 ;
for ( V_103 = V_161 ; V_103 <= V_165 ; ++ V_103 ) {
struct V_170 * V_90 = V_7 -> V_13 -> V_17 . V_90 ;
struct V_10 * V_11 ;
struct V_73 * V_106 ;
V_11 = & V_7 -> V_24 [ V_103 ] . V_11 ;
if ( V_11 -> V_12 )
continue;
V_43 = F_85 ( V_2 , V_100 * 8 ,
V_116 , true ,
V_171 ,
V_172 ,
NULL , V_90 , & V_106 ) ;
if ( V_43 )
goto V_95;
V_106 -> V_173 = F_86 ( V_7 -> V_13 ) ;
V_43 = F_43 ( V_2 , V_7 , V_106 ) ;
if ( V_43 ) {
F_87 ( & V_106 ) ;
goto V_95;
}
V_11 -> V_12 = V_106 ;
V_11 -> V_14 = 0 ;
V_11 -> V_15 . V_16 = & V_11 -> V_12 -> V_17 ;
V_11 -> V_15 . V_18 = true ;
V_11 -> V_19 = NULL ;
V_7 -> V_24 [ V_103 ] . V_78 = 0 ;
}
return 0 ;
V_95:
F_72 ( & V_131 -> V_56 ) ;
F_88 ( & V_131 -> V_133 , & V_7 -> V_160 ) ;
F_89 ( V_74 , V_131 ) ;
F_73 ( V_131 ) ;
error:
return V_43 ;
}
int F_90 ( struct V_1 * V_2 ,
struct V_72 * V_74 ,
T_1 V_161 )
{
struct V_130 * V_131 ;
struct V_6 * V_7 = V_74 -> V_7 ;
bool V_174 = true ;
V_161 /= V_116 ;
F_37 (mapping, &bo_va->valids, list) {
if ( V_131 -> V_133 . V_117 == V_161 )
break;
}
if ( & V_131 -> V_56 == & V_74 -> V_151 ) {
V_174 = false ;
F_37 (mapping, &bo_va->invalids, list) {
if ( V_131 -> V_133 . V_117 == V_161 )
break;
}
if ( & V_131 -> V_56 == & V_74 -> V_152 )
return - V_175 ;
}
F_72 ( & V_131 -> V_56 ) ;
F_88 ( & V_131 -> V_133 , & V_7 -> V_160 ) ;
F_89 ( V_74 , V_131 ) ;
if ( V_174 )
F_5 ( & V_131 -> V_56 , & V_7 -> V_155 ) ;
else
F_73 ( V_131 ) ;
return 0 ;
}
void F_91 ( struct V_1 * V_2 ,
struct V_72 * V_74 )
{
struct V_130 * V_131 , * V_176 ;
struct V_6 * V_7 = V_74 -> V_7 ;
F_72 ( & V_74 -> V_159 ) ;
F_8 ( & V_7 -> V_149 ) ;
F_72 ( & V_74 -> V_150 ) ;
F_10 ( & V_7 -> V_149 ) ;
F_23 (mapping, next, &bo_va->valids, list) {
F_72 ( & V_131 -> V_56 ) ;
F_88 ( & V_131 -> V_133 , & V_7 -> V_160 ) ;
F_89 ( V_74 , V_131 ) ;
F_5 ( & V_131 -> V_56 , & V_7 -> V_155 ) ;
}
F_23 (mapping, next, &bo_va->invalids, list) {
F_72 ( & V_131 -> V_56 ) ;
F_88 ( & V_131 -> V_133 , & V_7 -> V_160 ) ;
F_73 ( V_131 ) ;
}
F_26 ( V_74 -> V_153 ) ;
F_73 ( V_74 ) ;
}
void F_92 ( struct V_1 * V_2 ,
struct V_73 * V_16 )
{
struct V_72 * V_74 ;
F_37 (bo_va, &bo->va, bo_list) {
F_8 ( & V_74 -> V_7 -> V_149 ) ;
if ( F_66 ( & V_74 -> V_150 ) )
F_5 ( & V_74 -> V_150 , & V_74 -> V_7 -> V_156 ) ;
F_10 ( & V_74 -> V_7 -> V_149 ) ;
}
}
int F_93 ( struct V_1 * V_2 , struct V_6 * V_7 )
{
const unsigned V_177 = F_61 ( V_178 ,
V_100 * 8 ) ;
unsigned V_179 , V_180 ;
unsigned V_181 ;
struct V_30 * V_31 ;
struct V_182 * V_183 ;
int V_22 , V_43 ;
for ( V_22 = 0 ; V_22 < V_47 ; ++ V_22 )
V_7 -> V_46 [ V_22 ] = NULL ;
V_7 -> V_160 = V_184 ;
V_7 -> V_49 = F_94 ( & V_2 -> V_3 . V_185 ) ;
F_95 ( & V_7 -> V_149 ) ;
F_77 ( & V_7 -> V_156 ) ;
F_77 ( & V_7 -> V_154 ) ;
F_77 ( & V_7 -> V_155 ) ;
V_179 = F_2 ( V_2 ) ;
V_180 = F_1 ( V_2 ) ;
V_7 -> V_24 = F_96 ( V_180 , sizeof( struct V_186 ) ) ;
if ( V_7 -> V_24 == NULL ) {
F_97 ( L_4 ) ;
return - V_169 ;
}
V_181 = F_98 ( & V_2 -> V_3 . V_187 ) ;
V_181 %= V_2 -> V_3 . V_188 ;
V_31 = V_2 -> V_3 . V_189 [ V_181 ] ;
V_183 = & V_31 -> V_89 . V_190 [ V_191 ] ;
V_43 = F_99 ( & V_31 -> V_89 , & V_7 -> V_88 ,
V_183 , V_192 ) ;
if ( V_43 )
return V_43 ;
V_7 -> V_108 = NULL ;
V_43 = F_85 ( V_2 , V_179 , V_177 , true ,
V_171 ,
V_172 ,
NULL , NULL , & V_7 -> V_13 ) ;
if ( V_43 )
goto V_193;
V_43 = F_100 ( V_7 -> V_13 , false ) ;
if ( V_43 )
goto V_194;
V_43 = F_43 ( V_2 , V_7 , V_7 -> V_13 ) ;
F_101 ( V_7 -> V_13 ) ;
if ( V_43 )
goto V_194;
return 0 ;
V_194:
F_87 ( & V_7 -> V_13 ) ;
V_7 -> V_13 = NULL ;
V_193:
F_102 ( & V_31 -> V_89 , & V_7 -> V_88 ) ;
return V_43 ;
}
void F_103 ( struct V_1 * V_2 , struct V_6 * V_7 )
{
struct V_130 * V_131 , * V_59 ;
int V_22 ;
F_102 ( V_7 -> V_88 . V_89 , & V_7 -> V_88 ) ;
if ( ! F_104 ( & V_7 -> V_160 ) ) {
F_80 ( V_2 -> V_168 , L_5 ) ;
}
F_105 (mapping, tmp, &vm->va, it.rb) {
F_72 ( & V_131 -> V_56 ) ;
F_88 ( & V_131 -> V_133 , & V_7 -> V_160 ) ;
F_73 ( V_131 ) ;
}
F_23 (mapping, tmp, &vm->freed, list) {
F_72 ( & V_131 -> V_56 ) ;
F_73 ( V_131 ) ;
}
for ( V_22 = 0 ; V_22 < F_1 ( V_2 ) ; V_22 ++ )
F_87 ( & V_7 -> V_24 [ V_22 ] . V_11 . V_12 ) ;
F_106 ( V_7 -> V_24 ) ;
F_87 ( & V_7 -> V_13 ) ;
F_26 ( V_7 -> V_108 ) ;
}
void F_107 ( struct V_1 * V_2 )
{
unsigned V_22 ;
F_77 ( & V_2 -> V_3 . V_57 ) ;
for ( V_22 = 1 ; V_22 < V_2 -> V_3 . V_195 ; ++ V_22 ) {
F_35 ( V_2 , V_22 ) ;
F_108 ( & V_2 -> V_3 . V_46 [ V_22 ] . V_55 ) ;
F_78 ( & V_2 -> V_3 . V_46 [ V_22 ] . V_56 ,
& V_2 -> V_3 . V_57 ) ;
}
F_109 ( & V_2 -> V_3 . V_187 , 0 ) ;
F_28 ( & V_2 -> V_3 . V_185 , 0 ) ;
}
void F_110 ( struct V_1 * V_2 )
{
unsigned V_22 ;
for ( V_22 = 0 ; V_22 < V_196 ; ++ V_22 ) {
struct V_40 * V_41 = & V_2 -> V_3 . V_46 [ V_22 ] ;
F_26 ( V_2 -> V_3 . V_46 [ V_22 ] . V_54 ) ;
F_111 ( & V_2 -> V_3 . V_46 [ V_22 ] . V_55 ) ;
F_26 ( V_41 -> V_53 ) ;
}
}
