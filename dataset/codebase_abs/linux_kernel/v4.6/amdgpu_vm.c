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
struct V_38 * V_39 = & V_7 -> V_40 [ V_31 -> V_41 ] ;
struct V_34 * V_42 = V_33 -> V_43 ;
int V_44 ;
F_13 ( & V_2 -> V_3 . V_45 ) ;
if ( V_39 -> V_46 ) {
struct V_34 * V_47 = V_39 -> V_48 ;
bool V_49 ;
long V_50 ;
if ( ! V_47 )
V_49 = true ;
else if ( ! V_42 )
V_49 = false ;
else
V_49 = F_14 ( V_42 , V_47 ) ;
V_50 = F_15 ( & V_39 -> V_46 -> V_50 ) ;
if ( ! V_49 && V_50 == ( long ) V_39 &&
V_37 == V_39 -> V_51 ) {
V_44 = F_16 ( V_31 -> V_2 , V_33 ,
V_39 -> V_46 -> V_52 ) ;
if ( V_44 ) {
F_17 ( & V_2 -> V_3 . V_45 ) ;
return V_44 ;
}
F_18 ( V_39 -> V_46 -> V_52 ) ;
V_39 -> V_46 -> V_52 = F_19 ( V_34 ) ;
F_20 ( & V_39 -> V_46 -> V_53 ,
& V_2 -> V_3 . V_54 ) ;
* V_35 = V_39 -> V_46 - V_2 -> V_3 . V_40 ;
* V_36 = V_55 ;
F_21 ( V_7 , V_31 -> V_41 , * V_35 ,
* V_36 ) ;
F_17 ( & V_2 -> V_3 . V_45 ) ;
return 0 ;
}
}
V_39 -> V_46 = F_22 ( & V_2 -> V_3 . V_54 ,
struct V_56 ,
V_53 ) ;
V_44 = F_16 ( V_31 -> V_2 , V_33 , V_39 -> V_46 -> V_52 ) ;
if ( ! V_44 ) {
F_18 ( V_39 -> V_46 -> V_52 ) ;
V_39 -> V_46 -> V_52 = F_19 ( V_34 ) ;
F_18 ( V_39 -> V_48 ) ;
V_39 -> V_48 = F_19 ( V_42 ) ;
V_39 -> V_51 = V_37 ;
F_20 ( & V_39 -> V_46 -> V_53 , & V_2 -> V_3 . V_54 ) ;
F_23 ( & V_39 -> V_46 -> V_50 , ( long ) V_39 ) ;
* V_35 = V_39 -> V_46 - V_2 -> V_3 . V_40 ;
* V_36 = V_37 ;
F_21 ( V_7 , V_31 -> V_41 , * V_35 , * V_36 ) ;
}
F_17 ( & V_2 -> V_3 . V_45 ) ;
return V_44 ;
}
void F_24 ( struct V_30 * V_31 ,
unsigned V_35 , T_1 V_37 ,
T_2 V_57 , T_2 V_58 ,
T_2 V_59 , T_2 V_60 ,
T_2 V_61 , T_2 V_62 )
{
struct V_1 * V_2 = V_31 -> V_2 ;
struct V_56 * V_46 = & V_2 -> V_3 . V_40 [ V_35 ] ;
bool V_63 = V_31 -> V_64 -> V_65 && (
V_46 -> V_57 != V_57 ||
V_46 -> V_58 != V_58 ||
V_46 -> V_59 != V_59 ||
V_46 -> V_60 != V_60 ||
V_46 -> V_61 != V_61 ||
V_46 -> V_62 != V_62 ) ;
if ( V_31 -> V_64 -> V_66 && (
V_37 != V_55 || V_63 ) )
F_25 ( V_31 ) ;
if ( V_37 != V_55 ) {
F_26 ( V_37 , V_31 -> V_41 , V_35 ) ;
F_27 ( V_31 , V_35 , V_37 ) ;
}
if ( V_63 ) {
V_46 -> V_57 = V_57 ;
V_46 -> V_58 = V_58 ;
V_46 -> V_59 = V_59 ;
V_46 -> V_60 = V_60 ;
V_46 -> V_61 = V_61 ;
V_46 -> V_62 = V_62 ;
F_28 ( V_31 , V_35 ,
V_57 , V_58 ,
V_59 , V_60 ,
V_61 , V_62 ) ;
}
}
void F_29 ( struct V_1 * V_2 , unsigned V_35 )
{
struct V_56 * V_46 = & V_2 -> V_3 . V_40 [ V_35 ] ;
V_46 -> V_57 = 0 ;
V_46 -> V_58 = 0 ;
V_46 -> V_59 = 0 ;
V_46 -> V_60 = 0 ;
V_46 -> V_61 = 0 ;
V_46 -> V_62 = 0 ;
}
struct V_67 * F_30 ( struct V_6 * V_7 ,
struct V_68 * V_16 )
{
struct V_67 * V_69 ;
F_31 (bo_va, &bo->va, bo_list) {
if ( V_69 -> V_7 == V_7 ) {
return V_69 ;
}
}
return NULL ;
}
static void F_32 ( struct V_1 * V_2 ,
struct V_70 * V_71 ,
T_2 V_72 ,
struct V_73 * V_74 ,
T_1 V_75 , T_1 V_76 ,
unsigned V_77 , T_2 V_78 ,
T_2 V_79 )
{
F_33 ( V_75 , V_76 , V_77 , V_78 , V_79 ) ;
if ( ( V_71 == & V_2 -> V_80 ) && ( V_79 == V_72 ) ) {
T_1 V_81 = V_71 -> V_82 + ( V_76 >> 12 ) * 8 ;
F_34 ( V_2 , V_74 , V_75 , V_81 , V_77 ) ;
} else if ( V_71 ) {
T_3 * V_83 = V_71 -> V_83 ;
F_35 ( V_2 , V_74 , V_83 , V_75 , V_76 ,
V_77 , V_78 , V_79 ) ;
} else if ( V_77 < 3 ) {
F_35 ( V_2 , V_74 , NULL , V_75 , V_76 ,
V_77 , V_78 , V_79 ) ;
} else {
F_36 ( V_2 , V_74 , V_75 , V_76 ,
V_77 , V_78 , V_79 ) ;
}
}
static int F_37 ( struct V_1 * V_2 ,
struct V_6 * V_7 ,
struct V_68 * V_16 )
{
struct V_30 * V_31 ;
struct V_34 * V_34 = NULL ;
struct V_84 * V_85 ;
unsigned V_86 ;
T_1 V_76 ;
int V_44 ;
V_31 = F_38 ( V_7 -> V_87 . V_88 , struct V_30 , V_88 ) ;
V_44 = F_39 ( V_16 -> V_17 . V_89 ) ;
if ( V_44 )
return V_44 ;
V_44 = F_40 ( & V_16 -> V_17 , & V_16 -> V_90 , true , false ) ;
if ( V_44 )
goto error;
V_76 = F_12 ( V_16 ) ;
V_86 = F_41 ( V_16 ) / 8 ;
V_44 = F_42 ( V_2 , 64 , & V_85 ) ;
if ( V_44 )
goto error;
F_32 ( V_2 , NULL , 0 , & V_85 -> V_91 [ 0 ] , V_76 , 0 , V_86 ,
0 , 0 ) ;
F_43 ( V_31 , & V_85 -> V_91 [ 0 ] ) ;
F_44 ( V_85 -> V_91 [ 0 ] . V_92 > 64 ) ;
V_44 = F_45 ( V_85 , V_31 , & V_7 -> V_87 ,
V_93 , & V_34 ) ;
if ( V_44 )
goto V_94;
F_46 ( V_16 , V_34 , true ) ;
F_18 ( V_34 ) ;
return 0 ;
V_94:
F_47 ( V_85 ) ;
error:
return V_44 ;
}
T_1 F_48 ( const T_3 * V_83 , T_1 V_76 )
{
T_1 V_95 ;
if ( V_83 ) {
V_95 = V_83 [ V_76 >> V_96 ] ;
V_95 |= V_76 & ( ~ V_97 ) ;
} else {
V_95 = V_76 ;
}
V_95 &= 0xFFFFFFFFFFFFF000ULL ;
return V_95 ;
}
int F_49 ( struct V_1 * V_2 ,
struct V_6 * V_7 )
{
struct V_30 * V_31 ;
struct V_68 * V_98 = V_7 -> V_13 ;
T_1 V_37 = F_12 ( V_98 ) ;
T_2 V_78 = V_99 * 8 ;
T_1 V_100 = ~ 0 , V_101 = ~ 0 ;
unsigned V_77 = 0 , V_102 , V_103 ;
struct V_84 * V_85 ;
struct V_73 * V_74 ;
struct V_34 * V_34 = NULL ;
int V_44 ;
V_31 = F_38 ( V_7 -> V_87 . V_88 , struct V_30 , V_88 ) ;
V_103 = 64 ;
V_103 += V_7 -> V_23 * 6 ;
V_44 = F_42 ( V_2 , V_103 * 4 , & V_85 ) ;
if ( V_44 )
return V_44 ;
V_74 = & V_85 -> V_91 [ 0 ] ;
for ( V_102 = 0 ; V_102 <= V_7 -> V_23 ; ++ V_102 ) {
struct V_68 * V_16 = V_7 -> V_24 [ V_102 ] . V_11 . V_12 ;
T_1 V_104 , V_105 ;
if ( V_16 == NULL )
continue;
V_105 = F_12 ( V_16 ) ;
if ( V_7 -> V_24 [ V_102 ] . V_76 == V_105 )
continue;
V_7 -> V_24 [ V_102 ] . V_76 = V_105 ;
V_104 = V_37 + V_102 * 8 ;
if ( ( ( V_100 + 8 * V_77 ) != V_104 ) ||
( ( V_101 + V_78 * V_77 ) != V_105 ) ) {
if ( V_77 ) {
F_32 ( V_2 , NULL , 0 , V_74 ,
V_100 , V_101 ,
V_77 , V_78 ,
V_106 ) ;
}
V_77 = 1 ;
V_100 = V_104 ;
V_101 = V_105 ;
} else {
++ V_77 ;
}
}
if ( V_77 )
F_32 ( V_2 , NULL , 0 , V_74 , V_100 , V_101 ,
V_77 , V_78 , V_106 ) ;
if ( V_74 -> V_92 != 0 ) {
F_43 ( V_31 , V_74 ) ;
F_50 ( V_2 , & V_85 -> V_33 , V_98 -> V_17 . V_89 ,
V_93 ) ;
F_44 ( V_74 -> V_92 > V_103 ) ;
V_44 = F_45 ( V_85 , V_31 , & V_7 -> V_87 ,
V_93 , & V_34 ) ;
if ( V_44 )
goto V_94;
F_46 ( V_98 , V_34 , true ) ;
F_18 ( V_7 -> V_107 ) ;
V_7 -> V_107 = F_19 ( V_34 ) ;
F_18 ( V_34 ) ;
} else {
F_47 ( V_85 ) ;
}
return 0 ;
V_94:
F_47 ( V_85 ) ;
return V_44 ;
}
static void F_51 ( struct V_1 * V_2 ,
struct V_70 * V_71 ,
T_2 V_72 ,
struct V_73 * V_74 ,
T_1 V_108 , T_1 V_109 ,
T_1 V_76 , T_2 V_79 )
{
T_1 V_110 = V_111 ;
T_1 V_112 = 0x80 ;
T_1 V_113 = F_52 ( V_108 , V_112 ) ;
T_1 V_114 = V_109 & ~ ( V_112 - 1 ) ;
unsigned V_77 ;
if ( V_108 == V_109 )
return;
if ( V_71 || ! ( V_79 & V_106 ) || ( V_113 >= V_114 ) ) {
V_77 = ( V_109 - V_108 ) / 8 ;
F_32 ( V_2 , V_71 , V_72 , V_74 , V_108 ,
V_76 , V_77 , V_115 ,
V_79 ) ;
return;
}
if ( V_108 != V_113 ) {
V_77 = ( V_113 - V_108 ) / 8 ;
F_32 ( V_2 , NULL , 0 , V_74 , V_108 , V_76 ,
V_77 , V_115 , V_79 ) ;
V_76 += V_115 * V_77 ;
}
V_77 = ( V_114 - V_113 ) / 8 ;
F_32 ( V_2 , NULL , 0 , V_74 , V_113 , V_76 , V_77 ,
V_115 , V_79 | V_110 ) ;
if ( V_114 != V_109 ) {
V_76 += V_115 * V_77 ;
V_77 = ( V_109 - V_114 ) / 8 ;
F_32 ( V_2 , NULL , 0 , V_74 , V_114 , V_76 ,
V_77 , V_115 , V_79 ) ;
}
}
static void F_53 ( struct V_1 * V_2 ,
struct V_70 * V_71 ,
T_2 V_72 ,
struct V_6 * V_7 ,
struct V_73 * V_74 ,
T_1 V_116 , T_1 V_117 ,
T_1 V_118 , T_2 V_79 )
{
const T_1 V_119 = V_99 - 1 ;
T_1 V_120 = ~ 0 , V_121 = ~ 0 , V_122 = ~ 0 ;
T_1 V_76 ;
for ( V_76 = V_116 ; V_76 < V_117 ; ) {
T_1 V_102 = V_76 >> V_5 ;
struct V_68 * V_105 = V_7 -> V_24 [ V_102 ] . V_11 . V_12 ;
unsigned V_123 ;
T_1 V_108 ;
if ( ( V_76 & ~ V_119 ) == ( V_117 & ~ V_119 ) )
V_123 = V_117 - V_76 ;
else
V_123 = V_99 - ( V_76 & V_119 ) ;
V_108 = F_12 ( V_105 ) ;
V_108 += ( V_76 & V_119 ) * 8 ;
if ( V_121 != V_108 ) {
F_51 ( V_2 , V_71 , V_72 , V_74 ,
V_120 , V_121 ,
V_122 , V_79 ) ;
V_120 = V_108 ;
V_121 = V_108 + 8 * V_123 ;
V_122 = V_118 ;
} else {
V_121 += 8 * V_123 ;
}
V_76 += V_123 ;
V_118 += V_123 * V_115 ;
}
F_51 ( V_2 , V_71 , V_72 , V_74 ,
V_120 , V_121 ,
V_122 , V_79 ) ;
}
static int F_54 ( struct V_1 * V_2 ,
struct V_70 * V_71 ,
T_2 V_72 ,
struct V_6 * V_7 ,
T_1 V_116 , T_1 V_124 ,
T_2 V_79 , T_1 V_76 ,
struct V_34 * * V_34 )
{
struct V_30 * V_31 ;
void * V_50 = V_93 ;
unsigned V_123 , V_125 , V_103 ;
struct V_84 * V_85 ;
struct V_73 * V_74 ;
struct V_34 * V_126 = NULL ;
int V_44 ;
V_31 = F_38 ( V_7 -> V_87 . V_88 , struct V_30 , V_88 ) ;
if ( ! ( V_79 & V_106 ) )
V_50 = V_127 ;
V_123 = V_124 - V_116 + 1 ;
V_125 = ( V_123 >> F_55 ( V_5 , 11 ) ) + 1 ;
V_103 = 64 ;
if ( ( V_71 == & V_2 -> V_80 ) && ( V_79 == V_72 ) ) {
V_103 += V_125 * 7 ;
} else if ( V_71 ) {
V_103 += V_125 * 4 ;
V_103 += V_123 * 2 ;
} else {
V_103 += V_125 * 10 ;
V_103 += 2 * 10 ;
}
V_44 = F_42 ( V_2 , V_103 * 4 , & V_85 ) ;
if ( V_44 )
return V_44 ;
V_74 = & V_85 -> V_91 [ 0 ] ;
V_44 = F_50 ( V_2 , & V_85 -> V_33 , V_7 -> V_13 -> V_17 . V_89 ,
V_50 ) ;
if ( V_44 )
goto V_94;
V_44 = F_39 ( V_7 -> V_13 -> V_17 . V_89 ) ;
if ( V_44 )
goto V_94;
F_53 ( V_2 , V_71 , V_72 , V_7 , V_74 , V_116 , V_124 + 1 ,
V_76 , V_79 ) ;
F_43 ( V_31 , V_74 ) ;
F_44 ( V_74 -> V_92 > V_103 ) ;
V_44 = F_45 ( V_85 , V_31 , & V_7 -> V_87 ,
V_93 , & V_126 ) ;
if ( V_44 )
goto V_94;
F_46 ( V_7 -> V_13 , V_126 , true ) ;
if ( V_34 ) {
F_18 ( * V_34 ) ;
* V_34 = F_19 ( V_126 ) ;
}
F_18 ( V_126 ) ;
return 0 ;
V_94:
F_47 ( V_85 ) ;
return V_44 ;
}
static int F_56 ( struct V_1 * V_2 ,
struct V_70 * V_71 ,
T_2 V_72 ,
struct V_6 * V_7 ,
struct V_128 * V_129 ,
T_1 V_76 , struct V_34 * * V_34 )
{
const T_1 V_130 = 64ULL * 1024ULL * 1024ULL / V_115 ;
T_1 V_116 = V_129 -> V_131 . V_116 ;
T_2 V_79 = V_72 ;
int V_44 ;
if ( ! ( V_129 -> V_79 & V_132 ) )
V_79 &= ~ V_132 ;
if ( ! ( V_129 -> V_79 & V_133 ) )
V_79 &= ~ V_133 ;
F_57 ( V_129 ) ;
V_76 += V_129 -> V_134 ;
if ( ! V_71 || ( ( V_71 == & V_2 -> V_80 ) && ( V_79 == V_72 ) ) )
return F_54 ( V_2 , V_71 , V_72 , V_7 ,
V_116 , V_129 -> V_131 . V_124 ,
V_79 , V_76 , V_34 ) ;
while ( V_116 != V_129 -> V_131 . V_124 + 1 ) {
T_1 V_124 ;
V_124 = F_55 ( ( T_1 ) V_129 -> V_131 . V_124 , V_116 + V_130 - 1 ) ;
V_44 = F_54 ( V_2 , V_71 , V_72 , V_7 ,
V_116 , V_124 , V_79 , V_76 ,
V_34 ) ;
if ( V_44 )
return V_44 ;
V_116 = V_124 + 1 ;
V_76 += V_130 * V_115 ;
}
return 0 ;
}
int F_58 ( struct V_1 * V_2 ,
struct V_67 * V_69 ,
struct V_135 * V_136 )
{
struct V_6 * V_7 = V_69 -> V_7 ;
struct V_128 * V_129 ;
struct V_70 * V_71 = NULL ;
T_2 V_79 ;
T_1 V_76 ;
int V_44 ;
if ( V_136 ) {
V_76 = ( V_137 ) V_136 -> V_116 << V_96 ;
switch ( V_136 -> V_138 ) {
case V_139 :
V_71 = & V_69 -> V_16 -> V_2 -> V_80 ;
break;
case V_140 :
V_76 += V_2 -> V_3 . V_141 ;
break;
default:
break;
}
} else {
V_76 = 0 ;
}
V_79 = F_59 ( V_2 , V_69 -> V_16 -> V_17 . V_142 , V_136 ) ;
F_8 ( & V_7 -> V_143 ) ;
if ( ! F_60 ( & V_69 -> V_144 ) )
F_61 ( & V_69 -> V_145 , & V_69 -> V_146 ) ;
F_10 ( & V_7 -> V_143 ) ;
F_31 (mapping, &bo_va->invalids, list) {
V_44 = F_56 ( V_2 , V_71 , V_79 , V_7 , V_129 , V_76 ,
& V_69 -> V_147 ) ;
if ( V_44 )
return V_44 ;
}
if ( F_62 () ) {
F_31 (mapping, &bo_va->valids, list)
F_63 ( V_129 ) ;
F_31 (mapping, &bo_va->invalids, list)
F_63 ( V_129 ) ;
}
F_8 ( & V_7 -> V_143 ) ;
F_61 ( & V_69 -> V_146 , & V_69 -> V_145 ) ;
F_64 ( & V_69 -> V_144 ) ;
if ( ! V_136 )
F_5 ( & V_69 -> V_144 , & V_7 -> V_148 ) ;
F_10 ( & V_7 -> V_143 ) ;
return 0 ;
}
int F_65 ( struct V_1 * V_2 ,
struct V_6 * V_7 )
{
struct V_128 * V_129 ;
int V_44 ;
while ( ! F_60 ( & V_7 -> V_149 ) ) {
V_129 = F_22 ( & V_7 -> V_149 ,
struct V_128 , V_53 ) ;
F_66 ( & V_129 -> V_53 ) ;
V_44 = F_56 ( V_2 , NULL , 0 , V_7 , V_129 ,
0 , NULL ) ;
F_67 ( V_129 ) ;
if ( V_44 )
return V_44 ;
}
return 0 ;
}
int F_68 ( struct V_1 * V_2 ,
struct V_6 * V_7 , struct V_32 * V_33 )
{
struct V_67 * V_69 = NULL ;
int V_44 = 0 ;
F_8 ( & V_7 -> V_143 ) ;
while ( ! F_60 ( & V_7 -> V_150 ) ) {
V_69 = F_22 ( & V_7 -> V_150 ,
struct V_67 , V_144 ) ;
F_10 ( & V_7 -> V_143 ) ;
V_44 = F_58 ( V_2 , V_69 , NULL ) ;
if ( V_44 )
return V_44 ;
F_8 ( & V_7 -> V_143 ) ;
}
F_10 ( & V_7 -> V_143 ) ;
if ( V_69 )
V_44 = F_16 ( V_2 , V_33 , V_69 -> V_147 ) ;
return V_44 ;
}
struct V_67 * F_69 ( struct V_1 * V_2 ,
struct V_6 * V_7 ,
struct V_68 * V_16 )
{
struct V_67 * V_69 ;
V_69 = F_70 ( sizeof( struct V_67 ) , V_151 ) ;
if ( V_69 == NULL ) {
return NULL ;
}
V_69 -> V_7 = V_7 ;
V_69 -> V_16 = V_16 ;
V_69 -> V_152 = 1 ;
F_71 ( & V_69 -> V_153 ) ;
F_71 ( & V_69 -> V_145 ) ;
F_71 ( & V_69 -> V_146 ) ;
F_71 ( & V_69 -> V_144 ) ;
F_72 ( & V_69 -> V_153 , & V_16 -> V_154 ) ;
return V_69 ;
}
int F_73 ( struct V_1 * V_2 ,
struct V_67 * V_69 ,
T_1 V_155 , T_1 V_134 ,
T_1 V_156 , T_2 V_79 )
{
struct V_128 * V_129 ;
struct V_6 * V_7 = V_69 -> V_7 ;
struct V_157 * V_131 ;
unsigned V_158 , V_102 ;
T_1 V_159 ;
int V_44 ;
if ( V_155 & V_160 || V_134 & V_160 ||
V_156 == 0 || V_156 & V_160 )
return - V_161 ;
V_159 = V_155 + V_156 - 1 ;
if ( ( V_155 >= V_159 ) || ( V_134 + V_156 > F_41 ( V_69 -> V_16 ) ) )
return - V_161 ;
V_158 = V_159 / V_115 ;
if ( V_158 >= V_2 -> V_3 . V_4 ) {
F_74 ( V_2 -> V_162 , L_1 ,
V_158 , V_2 -> V_3 . V_4 ) ;
return - V_161 ;
}
V_155 /= V_115 ;
V_159 /= V_115 ;
V_131 = F_75 ( & V_7 -> V_154 , V_155 , V_159 ) ;
if ( V_131 ) {
struct V_128 * V_163 ;
V_163 = F_38 ( V_131 , struct V_128 , V_131 ) ;
F_74 ( V_2 -> V_162 , L_2
L_3 , V_69 -> V_16 , V_155 , V_159 ,
V_163 -> V_131 . V_116 , V_163 -> V_131 . V_124 + 1 ) ;
V_44 = - V_161 ;
goto error;
}
V_129 = F_76 ( sizeof( * V_129 ) , V_151 ) ;
if ( ! V_129 ) {
V_44 = - V_164 ;
goto error;
}
F_71 ( & V_129 -> V_53 ) ;
V_129 -> V_131 . V_116 = V_155 ;
V_129 -> V_131 . V_124 = V_159 ;
V_129 -> V_134 = V_134 ;
V_129 -> V_79 = V_79 ;
F_5 ( & V_129 -> V_53 , & V_69 -> V_146 ) ;
F_77 ( & V_129 -> V_131 , & V_7 -> V_154 ) ;
V_155 >>= V_5 ;
V_159 >>= V_5 ;
F_78 ( V_159 >= F_1 ( V_2 ) ) ;
if ( V_159 > V_7 -> V_23 )
V_7 -> V_23 = V_159 ;
for ( V_102 = V_155 ; V_102 <= V_159 ; ++ V_102 ) {
struct V_165 * V_89 = V_7 -> V_13 -> V_17 . V_89 ;
struct V_10 * V_11 ;
struct V_68 * V_105 ;
V_11 = & V_7 -> V_24 [ V_102 ] . V_11 ;
if ( V_11 -> V_12 )
continue;
V_44 = F_79 ( V_2 , V_99 * 8 ,
V_115 , true ,
V_166 ,
V_167 ,
NULL , V_89 , & V_105 ) ;
if ( V_44 )
goto V_94;
V_105 -> V_168 = F_80 ( V_7 -> V_13 ) ;
V_44 = F_37 ( V_2 , V_7 , V_105 ) ;
if ( V_44 ) {
F_81 ( & V_105 ) ;
goto V_94;
}
V_11 -> V_12 = V_105 ;
V_11 -> V_14 = 0 ;
V_11 -> V_15 . V_16 = & V_11 -> V_12 -> V_17 ;
V_11 -> V_15 . V_18 = true ;
V_11 -> V_19 = NULL ;
V_7 -> V_24 [ V_102 ] . V_76 = 0 ;
}
return 0 ;
V_94:
F_66 ( & V_129 -> V_53 ) ;
F_82 ( & V_129 -> V_131 , & V_7 -> V_154 ) ;
F_83 ( V_69 , V_129 ) ;
F_67 ( V_129 ) ;
error:
return V_44 ;
}
int F_84 ( struct V_1 * V_2 ,
struct V_67 * V_69 ,
T_1 V_155 )
{
struct V_128 * V_129 ;
struct V_6 * V_7 = V_69 -> V_7 ;
bool V_169 = true ;
V_155 /= V_115 ;
F_31 (mapping, &bo_va->valids, list) {
if ( V_129 -> V_131 . V_116 == V_155 )
break;
}
if ( & V_129 -> V_53 == & V_69 -> V_145 ) {
V_169 = false ;
F_31 (mapping, &bo_va->invalids, list) {
if ( V_129 -> V_131 . V_116 == V_155 )
break;
}
if ( & V_129 -> V_53 == & V_69 -> V_146 )
return - V_170 ;
}
F_66 ( & V_129 -> V_53 ) ;
F_82 ( & V_129 -> V_131 , & V_7 -> V_154 ) ;
F_83 ( V_69 , V_129 ) ;
if ( V_169 )
F_5 ( & V_129 -> V_53 , & V_7 -> V_149 ) ;
else
F_67 ( V_129 ) ;
return 0 ;
}
void F_85 ( struct V_1 * V_2 ,
struct V_67 * V_69 )
{
struct V_128 * V_129 , * V_171 ;
struct V_6 * V_7 = V_69 -> V_7 ;
F_66 ( & V_69 -> V_153 ) ;
F_8 ( & V_7 -> V_143 ) ;
F_66 ( & V_69 -> V_144 ) ;
F_10 ( & V_7 -> V_143 ) ;
F_86 (mapping, next, &bo_va->valids, list) {
F_66 ( & V_129 -> V_53 ) ;
F_82 ( & V_129 -> V_131 , & V_7 -> V_154 ) ;
F_83 ( V_69 , V_129 ) ;
F_5 ( & V_129 -> V_53 , & V_7 -> V_149 ) ;
}
F_86 (mapping, next, &bo_va->invalids, list) {
F_66 ( & V_129 -> V_53 ) ;
F_82 ( & V_129 -> V_131 , & V_7 -> V_154 ) ;
F_67 ( V_129 ) ;
}
F_18 ( V_69 -> V_147 ) ;
F_67 ( V_69 ) ;
}
void F_87 ( struct V_1 * V_2 ,
struct V_68 * V_16 )
{
struct V_67 * V_69 ;
F_31 (bo_va, &bo->va, bo_list) {
F_8 ( & V_69 -> V_7 -> V_143 ) ;
if ( F_60 ( & V_69 -> V_144 ) )
F_5 ( & V_69 -> V_144 , & V_69 -> V_7 -> V_150 ) ;
F_10 ( & V_69 -> V_7 -> V_143 ) ;
}
}
int F_88 ( struct V_1 * V_2 , struct V_6 * V_7 )
{
const unsigned V_172 = F_55 ( V_173 ,
V_99 * 8 ) ;
unsigned V_174 , V_175 ;
unsigned V_176 ;
struct V_30 * V_31 ;
struct V_177 * V_178 ;
int V_22 , V_44 ;
for ( V_22 = 0 ; V_22 < V_179 ; ++ V_22 ) {
V_7 -> V_40 [ V_22 ] . V_46 = NULL ;
V_7 -> V_40 [ V_22 ] . V_48 = NULL ;
}
V_7 -> V_154 = V_180 ;
F_89 ( & V_7 -> V_143 ) ;
F_71 ( & V_7 -> V_150 ) ;
F_71 ( & V_7 -> V_148 ) ;
F_71 ( & V_7 -> V_149 ) ;
V_174 = F_2 ( V_2 ) ;
V_175 = F_1 ( V_2 ) ;
V_7 -> V_24 = F_90 ( V_175 , sizeof( struct V_181 ) ) ;
if ( V_7 -> V_24 == NULL ) {
F_91 ( L_4 ) ;
return - V_164 ;
}
V_176 = F_92 ( & V_2 -> V_3 . V_182 ) ;
V_176 %= V_2 -> V_3 . V_183 ;
V_31 = V_2 -> V_3 . V_184 [ V_176 ] ;
V_178 = & V_31 -> V_88 . V_185 [ V_186 ] ;
V_44 = F_93 ( & V_31 -> V_88 , & V_7 -> V_87 ,
V_178 , V_187 ) ;
if ( V_44 )
return V_44 ;
V_7 -> V_107 = NULL ;
V_44 = F_79 ( V_2 , V_174 , V_172 , true ,
V_166 ,
V_167 ,
NULL , NULL , & V_7 -> V_13 ) ;
if ( V_44 )
goto V_188;
V_44 = F_94 ( V_7 -> V_13 , false ) ;
if ( V_44 )
goto V_189;
V_44 = F_37 ( V_2 , V_7 , V_7 -> V_13 ) ;
F_95 ( V_7 -> V_13 ) ;
if ( V_44 )
goto V_189;
return 0 ;
V_189:
F_81 ( & V_7 -> V_13 ) ;
V_7 -> V_13 = NULL ;
V_188:
F_96 ( & V_31 -> V_88 , & V_7 -> V_87 ) ;
return V_44 ;
}
void F_97 ( struct V_1 * V_2 , struct V_6 * V_7 )
{
struct V_128 * V_129 , * V_163 ;
int V_22 ;
F_96 ( V_7 -> V_87 . V_88 , & V_7 -> V_87 ) ;
if ( ! F_98 ( & V_7 -> V_154 ) ) {
F_74 ( V_2 -> V_162 , L_5 ) ;
}
F_99 (mapping, tmp, &vm->va, it.rb) {
F_66 ( & V_129 -> V_53 ) ;
F_82 ( & V_129 -> V_131 , & V_7 -> V_154 ) ;
F_67 ( V_129 ) ;
}
F_86 (mapping, tmp, &vm->freed, list) {
F_66 ( & V_129 -> V_53 ) ;
F_67 ( V_129 ) ;
}
for ( V_22 = 0 ; V_22 < F_1 ( V_2 ) ; V_22 ++ )
F_81 ( & V_7 -> V_24 [ V_22 ] . V_11 . V_12 ) ;
F_100 ( V_7 -> V_24 ) ;
F_81 ( & V_7 -> V_13 ) ;
F_18 ( V_7 -> V_107 ) ;
for ( V_22 = 0 ; V_22 < V_179 ; ++ V_22 ) {
struct V_38 * V_39 = & V_7 -> V_40 [ V_22 ] ;
if ( V_39 -> V_46 )
F_101 ( & V_39 -> V_46 -> V_50 ,
( long ) V_39 , 0 ) ;
F_18 ( V_39 -> V_48 ) ;
}
}
void F_102 ( struct V_1 * V_2 )
{
unsigned V_22 ;
F_71 ( & V_2 -> V_3 . V_54 ) ;
for ( V_22 = 1 ; V_22 < V_2 -> V_3 . V_190 ; ++ V_22 ) {
F_29 ( V_2 , V_22 ) ;
F_72 ( & V_2 -> V_3 . V_40 [ V_22 ] . V_53 ,
& V_2 -> V_3 . V_54 ) ;
}
F_103 ( & V_2 -> V_3 . V_182 , 0 ) ;
}
void F_104 ( struct V_1 * V_2 )
{
unsigned V_22 ;
for ( V_22 = 0 ; V_22 < V_191 ; ++ V_22 )
F_18 ( V_2 -> V_3 . V_40 [ V_22 ] . V_52 ) ;
}
