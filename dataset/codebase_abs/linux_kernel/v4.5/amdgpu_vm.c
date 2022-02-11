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
V_11 -> V_14 = V_15 ;
V_11 -> V_16 = V_15 ;
V_11 -> V_17 = 0 ;
V_11 -> V_18 . V_19 = & V_7 -> V_13 -> V_20 ;
V_11 -> V_18 . V_21 = true ;
F_5 ( & V_11 -> V_18 . V_22 , V_9 ) ;
}
void F_6 ( struct V_6 * V_7 , struct V_8 * V_23 )
{
unsigned V_24 ;
for ( V_24 = 0 ; V_24 <= V_7 -> V_25 ; ++ V_24 ) {
struct V_10 * V_11 = & V_7 -> V_26 [ V_24 ] . V_11 ;
if ( ! V_11 -> V_12 )
continue;
F_5 ( & V_11 -> V_18 . V_22 , V_23 ) ;
}
}
void F_7 ( struct V_1 * V_2 ,
struct V_6 * V_7 )
{
struct V_27 * V_28 = V_2 -> V_29 . V_30 . V_28 ;
unsigned V_24 ;
F_8 ( & V_28 -> V_31 ) ;
for ( V_24 = 0 ; V_24 <= V_7 -> V_25 ; ++ V_24 ) {
struct V_10 * V_11 = & V_7 -> V_26 [ V_24 ] . V_11 ;
if ( ! V_11 -> V_12 )
continue;
F_9 ( & V_11 -> V_12 -> V_20 ) ;
}
F_10 ( & V_28 -> V_31 ) ;
}
int F_11 ( struct V_6 * V_7 , struct V_32 * V_33 ,
struct V_34 * V_35 )
{
struct V_36 * V_37 [ V_38 ] = {} ;
struct V_39 * V_40 = & V_7 -> V_41 [ V_33 -> V_42 ] ;
struct V_1 * V_2 = V_33 -> V_2 ;
unsigned V_43 [ 2 ] = {} ;
unsigned V_24 ;
if ( V_40 -> V_44 ) {
unsigned V_44 = V_40 -> V_44 ;
long V_45 ;
V_45 = F_12 ( & V_2 -> V_3 . V_41 [ V_44 ] . V_45 ) ;
if ( V_45 == ( long ) V_7 ) {
F_13 ( V_40 -> V_44 , V_33 -> V_42 ) ;
return 0 ;
}
}
V_40 -> V_46 = ~ 0ll ;
for ( V_24 = 1 ; V_24 < V_2 -> V_3 . V_47 ; ++ V_24 ) {
struct V_36 * V_36 = V_2 -> V_3 . V_41 [ V_24 ] . V_48 ;
struct V_32 * V_49 ;
if ( V_36 == NULL ) {
V_40 -> V_44 = V_24 ;
F_13 ( V_24 , V_33 -> V_42 ) ;
return 0 ;
}
V_49 = F_14 ( V_36 ) ;
if ( V_37 [ V_49 -> V_42 ] == NULL ||
F_15 ( V_37 [ V_49 -> V_42 ] , V_36 ) ) {
V_37 [ V_49 -> V_42 ] = V_36 ;
V_43 [ V_49 == V_33 ? 0 : 1 ] = V_24 ;
}
}
for ( V_24 = 0 ; V_24 < 2 ; ++ V_24 ) {
if ( V_43 [ V_24 ] ) {
struct V_36 * V_36 ;
V_36 = V_2 -> V_3 . V_41 [ V_43 [ V_24 ] ] . V_48 ;
V_40 -> V_44 = V_43 [ V_24 ] ;
F_13 ( V_43 [ V_24 ] , V_33 -> V_42 ) ;
return F_16 ( V_33 -> V_2 , V_35 , V_36 ) ;
}
}
F_17 () ;
return - V_50 ;
}
void F_18 ( struct V_32 * V_33 ,
struct V_6 * V_7 ,
struct V_36 * V_51 )
{
T_1 V_52 = F_19 ( V_7 -> V_13 ) ;
struct V_39 * V_40 = & V_7 -> V_41 [ V_33 -> V_42 ] ;
struct V_36 * V_53 = V_40 -> V_53 ;
bool V_54 ;
if ( ! V_53 )
V_54 = true ;
else if ( ! V_51 )
V_54 = false ;
else
V_54 = F_15 ( V_51 , V_53 ) ;
if ( V_52 != V_40 -> V_46 || V_54 ) {
F_20 ( V_52 , V_33 -> V_42 , V_40 -> V_44 ) ;
if ( V_54 ) {
V_40 -> V_53 = F_21 ( V_51 ) ;
F_22 ( V_53 ) ;
}
V_40 -> V_46 = V_52 ;
F_23 ( V_33 , V_40 -> V_44 , V_40 -> V_46 ) ;
}
}
void F_24 ( struct V_1 * V_2 ,
struct V_6 * V_7 ,
struct V_36 * V_36 )
{
struct V_32 * V_33 = F_14 ( V_36 ) ;
unsigned V_40 = V_7 -> V_41 [ V_33 -> V_42 ] . V_44 ;
F_22 ( V_2 -> V_3 . V_41 [ V_40 ] . V_48 ) ;
V_2 -> V_3 . V_41 [ V_40 ] . V_48 = F_21 ( V_36 ) ;
F_25 ( & V_2 -> V_3 . V_41 [ V_40 ] . V_45 , ( long ) V_7 ) ;
}
struct V_55 * F_26 ( struct V_6 * V_7 ,
struct V_56 * V_19 )
{
struct V_55 * V_57 ;
F_27 (bo_va, &bo->va, bo_list) {
if ( V_57 -> V_7 == V_7 ) {
return V_57 ;
}
}
return NULL ;
}
static void F_28 ( struct V_1 * V_2 ,
struct V_58 * V_59 ,
T_1 V_60 , T_1 V_61 ,
unsigned V_62 , T_2 V_63 ,
T_2 V_64 , T_2 V_65 )
{
F_29 ( V_60 , V_61 , V_62 , V_63 , V_64 ) ;
if ( ( V_64 & V_66 ) && ( V_64 == V_65 ) ) {
T_1 V_67 = V_2 -> V_68 . V_69 + ( V_61 >> 12 ) * 8 ;
F_30 ( V_2 , V_59 , V_60 , V_67 , V_62 ) ;
} else if ( ( V_64 & V_66 ) || ( V_62 < 3 ) ) {
F_31 ( V_2 , V_59 , V_60 , V_61 ,
V_62 , V_63 , V_64 ) ;
} else {
F_32 ( V_2 , V_59 , V_60 , V_61 ,
V_62 , V_63 , V_64 ) ;
}
}
int F_33 ( struct V_70 * V_71 )
{
int V_24 ;
for ( V_24 = 0 ; V_24 < V_71 -> V_72 ; V_24 ++ )
F_34 ( V_71 -> V_2 , & V_71 -> V_73 [ V_24 ] ) ;
F_35 ( V_71 -> V_73 ) ;
return 0 ;
}
static int F_36 ( struct V_1 * V_2 ,
struct V_56 * V_19 )
{
struct V_32 * V_33 = V_2 -> V_3 . V_74 ;
struct V_36 * V_36 = NULL ;
struct V_58 * V_59 ;
unsigned V_75 ;
T_1 V_61 ;
int V_76 ;
V_76 = F_37 ( V_19 -> V_20 . V_77 ) ;
if ( V_76 )
return V_76 ;
V_76 = F_38 ( & V_19 -> V_20 , & V_19 -> V_78 , true , false ) ;
if ( V_76 )
goto error;
V_61 = F_19 ( V_19 ) ;
V_75 = F_39 ( V_19 ) / 8 ;
V_59 = F_40 ( sizeof( struct V_58 ) , V_79 ) ;
if ( ! V_59 )
goto error;
V_76 = F_41 ( V_33 , NULL , V_75 * 2 + 64 , V_59 ) ;
if ( V_76 )
goto V_80;
V_59 -> V_81 = 0 ;
F_28 ( V_2 , V_59 , V_61 , 0 , V_75 , 0 , 0 , 0 ) ;
F_42 ( V_2 , V_59 ) ;
F_43 ( V_59 -> V_81 > 64 ) ;
V_76 = F_44 ( V_2 , V_33 , V_59 , 1 ,
& F_33 ,
V_82 ,
& V_36 ) ;
if ( ! V_76 )
F_45 ( V_19 , V_36 , true ) ;
F_22 ( V_36 ) ;
if ( V_83 )
return 0 ;
V_80:
F_34 ( V_2 , V_59 ) ;
F_35 ( V_59 ) ;
error:
return V_76 ;
}
T_1 F_46 ( struct V_1 * V_2 , T_1 V_61 )
{
T_1 V_84 ;
V_84 = V_2 -> V_68 . V_85 [ V_61 >> V_86 ] ;
V_84 |= V_61 & ( ~ V_87 ) ;
return V_84 ;
}
int F_47 ( struct V_1 * V_2 ,
struct V_6 * V_7 )
{
struct V_32 * V_33 = V_2 -> V_3 . V_74 ;
struct V_56 * V_88 = V_7 -> V_13 ;
T_1 V_52 = F_19 ( V_88 ) ;
T_2 V_63 = V_89 * 8 ;
T_1 V_90 = ~ 0 , V_91 = ~ 0 ;
unsigned V_62 = 0 , V_92 , V_93 ;
struct V_58 * V_59 ;
struct V_36 * V_36 = NULL ;
int V_76 ;
V_93 = 64 ;
V_93 += V_7 -> V_25 * 6 ;
if ( V_93 > 0xfffff )
return - V_94 ;
V_59 = F_40 ( sizeof( struct V_58 ) , V_79 ) ;
if ( ! V_59 )
return - V_94 ;
V_76 = F_41 ( V_33 , NULL , V_93 * 4 , V_59 ) ;
if ( V_76 ) {
F_35 ( V_59 ) ;
return V_76 ;
}
V_59 -> V_81 = 0 ;
for ( V_92 = 0 ; V_92 <= V_7 -> V_25 ; ++ V_92 ) {
struct V_56 * V_19 = V_7 -> V_26 [ V_92 ] . V_11 . V_12 ;
T_1 V_95 , V_96 ;
if ( V_19 == NULL )
continue;
V_96 = F_19 ( V_19 ) ;
if ( V_7 -> V_26 [ V_92 ] . V_61 == V_96 )
continue;
V_7 -> V_26 [ V_92 ] . V_61 = V_96 ;
V_95 = V_52 + V_92 * 8 ;
if ( ( ( V_90 + 8 * V_62 ) != V_95 ) ||
( ( V_91 + V_63 * V_62 ) != V_96 ) ) {
if ( V_62 ) {
F_28 ( V_2 , V_59 , V_90 ,
V_91 , V_62 , V_63 ,
V_97 , 0 ) ;
}
V_62 = 1 ;
V_90 = V_95 ;
V_91 = V_96 ;
} else {
++ V_62 ;
}
}
if ( V_62 )
F_28 ( V_2 , V_59 , V_90 , V_91 , V_62 ,
V_63 , V_97 , 0 ) ;
if ( V_59 -> V_81 != 0 ) {
F_42 ( V_2 , V_59 ) ;
F_48 ( V_2 , & V_59 -> V_35 , V_88 -> V_20 . V_77 , V_82 ) ;
F_43 ( V_59 -> V_81 > V_93 ) ;
V_76 = F_44 ( V_2 , V_33 , V_59 , 1 ,
& F_33 ,
V_82 ,
& V_36 ) ;
if ( V_76 )
goto V_80;
F_45 ( V_88 , V_36 , true ) ;
F_22 ( V_7 -> V_98 ) ;
V_7 -> V_98 = F_21 ( V_36 ) ;
F_22 ( V_36 ) ;
}
if ( ! V_83 || V_59 -> V_81 == 0 ) {
F_34 ( V_2 , V_59 ) ;
F_35 ( V_59 ) ;
}
return 0 ;
V_80:
F_34 ( V_2 , V_59 ) ;
F_35 ( V_59 ) ;
return V_76 ;
}
static void F_49 ( struct V_1 * V_2 ,
struct V_58 * V_59 ,
T_1 V_99 , T_1 V_100 ,
T_1 V_61 , T_2 V_64 ,
T_2 V_65 )
{
T_1 V_101 = V_102 ;
T_1 V_103 = 0x80 ;
T_1 V_104 = F_50 ( V_99 , V_103 ) ;
T_1 V_105 = V_100 & ~ ( V_103 - 1 ) ;
unsigned V_62 ;
if ( ( V_64 & V_66 ) || ! ( V_64 & V_97 ) ||
( V_104 >= V_105 ) ) {
V_62 = ( V_100 - V_99 ) / 8 ;
F_28 ( V_2 , V_59 , V_99 , V_61 , V_62 ,
V_106 , V_64 , V_65 ) ;
return;
}
if ( V_99 != V_104 ) {
V_62 = ( V_104 - V_99 ) / 8 ;
F_28 ( V_2 , V_59 , V_99 , V_61 , V_62 ,
V_106 , V_64 , V_65 ) ;
V_61 += V_106 * V_62 ;
}
V_62 = ( V_105 - V_104 ) / 8 ;
F_28 ( V_2 , V_59 , V_104 , V_61 , V_62 ,
V_106 , V_64 | V_101 ,
V_65 ) ;
if ( V_105 != V_100 ) {
V_61 += V_106 * V_62 ;
V_62 = ( V_100 - V_105 ) / 8 ;
F_28 ( V_2 , V_59 , V_105 , V_61 , V_62 ,
V_106 , V_64 , V_65 ) ;
}
}
static int F_51 ( struct V_1 * V_2 ,
struct V_6 * V_7 ,
struct V_58 * V_59 ,
T_1 V_107 , T_1 V_108 ,
T_1 V_109 , T_2 V_64 ,
T_2 V_65 )
{
T_1 V_110 = V_89 - 1 ;
T_1 V_111 = ~ 0 , V_112 = ~ 0 ;
void * V_45 = V_82 ;
unsigned V_62 = 0 ;
T_1 V_61 ;
if ( ! ( V_64 & V_97 ) )
V_45 = V_113 ;
for ( V_61 = V_107 ; V_61 < V_108 ; ) {
T_1 V_92 = V_61 >> V_5 ;
struct V_56 * V_96 = V_7 -> V_26 [ V_92 ] . V_11 . V_12 ;
unsigned V_114 ;
T_1 V_115 ;
int V_76 ;
F_48 ( V_2 , & V_59 -> V_35 , V_96 -> V_20 . V_77 , V_45 ) ;
V_76 = F_37 ( V_96 -> V_20 . V_77 ) ;
if ( V_76 )
return V_76 ;
if ( ( V_61 & ~ V_110 ) == ( V_108 & ~ V_110 ) )
V_114 = V_108 - V_61 ;
else
V_114 = V_89 - ( V_61 & V_110 ) ;
V_115 = F_19 ( V_96 ) ;
V_115 += ( V_61 & V_110 ) * 8 ;
if ( ( V_111 + 8 * V_62 ) != V_115 ) {
if ( V_62 ) {
F_49 ( V_2 , V_59 , V_111 ,
V_111 + 8 * V_62 ,
V_112 , V_64 ,
V_65 ) ;
}
V_62 = V_114 ;
V_111 = V_115 ;
V_112 = V_109 ;
} else {
V_62 += V_114 ;
}
V_61 += V_114 ;
V_109 += V_114 * V_106 ;
}
if ( V_62 ) {
F_49 ( V_2 , V_59 , V_111 ,
V_111 + 8 * V_62 ,
V_112 , V_64 , V_65 ) ;
}
return 0 ;
}
static int F_52 ( struct V_1 * V_2 ,
struct V_6 * V_7 ,
struct V_116 * V_117 ,
T_1 V_61 , T_2 V_65 ,
struct V_36 * * V_36 )
{
struct V_32 * V_33 = V_2 -> V_3 . V_74 ;
unsigned V_114 , V_118 , V_93 ;
T_2 V_64 = V_65 ;
struct V_58 * V_59 ;
struct V_36 * V_119 = NULL ;
int V_76 ;
if ( ! ( V_117 -> V_64 & V_120 ) )
V_64 &= ~ V_120 ;
if ( ! ( V_117 -> V_64 & V_121 ) )
V_64 &= ~ V_121 ;
F_53 ( V_117 ) ;
V_114 = V_117 -> V_122 . V_123 - V_117 -> V_122 . V_107 + 1 ;
V_118 = ( V_114 >> F_54 ( V_5 , 11 ) ) + 1 ;
V_93 = 64 ;
if ( ( V_64 & V_66 ) && ( V_64 == V_65 ) ) {
V_93 += V_118 * 7 ;
} else if ( V_64 & V_66 ) {
V_93 += V_118 * 4 ;
V_93 += V_114 * 2 ;
} else {
V_93 += V_118 * 10 ;
V_93 += 2 * 10 ;
}
if ( V_93 > 0xfffff )
return - V_94 ;
V_59 = F_40 ( sizeof( struct V_58 ) , V_79 ) ;
if ( ! V_59 )
return - V_94 ;
V_76 = F_41 ( V_33 , NULL , V_93 * 4 , V_59 ) ;
if ( V_76 ) {
F_35 ( V_59 ) ;
return V_76 ;
}
V_59 -> V_81 = 0 ;
V_76 = F_51 ( V_2 , V_7 , V_59 , V_117 -> V_122 . V_107 ,
V_117 -> V_122 . V_123 + 1 , V_61 + V_117 -> V_124 ,
V_64 , V_65 ) ;
if ( V_76 ) {
F_34 ( V_2 , V_59 ) ;
F_35 ( V_59 ) ;
return V_76 ;
}
F_42 ( V_2 , V_59 ) ;
F_43 ( V_59 -> V_81 > V_93 ) ;
V_76 = F_44 ( V_2 , V_33 , V_59 , 1 ,
& F_33 ,
V_82 ,
& V_119 ) ;
if ( V_76 )
goto V_80;
F_45 ( V_7 -> V_13 , V_119 , true ) ;
if ( V_36 ) {
F_22 ( * V_36 ) ;
* V_36 = F_21 ( V_119 ) ;
}
F_22 ( V_119 ) ;
if ( ! V_83 ) {
F_34 ( V_2 , V_59 ) ;
F_35 ( V_59 ) ;
}
return 0 ;
V_80:
F_34 ( V_2 , V_59 ) ;
F_35 ( V_59 ) ;
return V_76 ;
}
int F_55 ( struct V_1 * V_2 ,
struct V_55 * V_57 ,
struct V_125 * V_126 )
{
struct V_6 * V_7 = V_57 -> V_7 ;
struct V_116 * V_117 ;
T_2 V_64 ;
T_1 V_61 ;
int V_76 ;
if ( V_126 ) {
V_61 = ( V_127 ) V_126 -> V_107 << V_86 ;
if ( V_126 -> V_128 != V_129 )
V_61 += V_2 -> V_3 . V_130 ;
} else {
V_61 = 0 ;
}
V_64 = F_56 ( V_2 , V_57 -> V_19 -> V_20 . V_131 , V_126 ) ;
F_8 ( & V_7 -> V_132 ) ;
if ( ! F_57 ( & V_57 -> V_133 ) )
F_58 ( & V_57 -> V_134 , & V_57 -> V_135 ) ;
F_10 ( & V_7 -> V_132 ) ;
F_27 (mapping, &bo_va->invalids, list) {
V_76 = F_52 ( V_2 , V_7 , V_117 , V_61 ,
V_64 , & V_57 -> V_136 ) ;
if ( V_76 )
return V_76 ;
}
if ( F_59 () ) {
F_27 (mapping, &bo_va->valids, list)
F_60 ( V_117 ) ;
F_27 (mapping, &bo_va->invalids, list)
F_60 ( V_117 ) ;
}
F_8 ( & V_7 -> V_132 ) ;
F_58 ( & V_57 -> V_135 , & V_57 -> V_134 ) ;
F_61 ( & V_57 -> V_133 ) ;
if ( ! V_126 )
F_5 ( & V_57 -> V_133 , & V_7 -> V_137 ) ;
F_10 ( & V_7 -> V_132 ) ;
return 0 ;
}
int F_62 ( struct V_1 * V_2 ,
struct V_6 * V_7 )
{
struct V_116 * V_117 ;
int V_76 ;
F_8 ( & V_7 -> V_138 ) ;
while ( ! F_57 ( & V_7 -> V_139 ) ) {
V_117 = F_63 ( & V_7 -> V_139 ,
struct V_116 , V_140 ) ;
F_64 ( & V_117 -> V_140 ) ;
F_10 ( & V_7 -> V_138 ) ;
V_76 = F_52 ( V_2 , V_7 , V_117 , 0 , 0 , NULL ) ;
F_35 ( V_117 ) ;
if ( V_76 )
return V_76 ;
F_8 ( & V_7 -> V_138 ) ;
}
F_10 ( & V_7 -> V_138 ) ;
return 0 ;
}
int F_65 ( struct V_1 * V_2 ,
struct V_6 * V_7 , struct V_34 * V_35 )
{
struct V_55 * V_57 = NULL ;
int V_76 = 0 ;
F_8 ( & V_7 -> V_132 ) ;
while ( ! F_57 ( & V_7 -> V_141 ) ) {
V_57 = F_63 ( & V_7 -> V_141 ,
struct V_55 , V_133 ) ;
F_10 ( & V_7 -> V_132 ) ;
F_66 ( & V_57 -> V_142 ) ;
V_76 = F_55 ( V_2 , V_57 , NULL ) ;
F_67 ( & V_57 -> V_142 ) ;
if ( V_76 )
return V_76 ;
F_8 ( & V_7 -> V_132 ) ;
}
F_10 ( & V_7 -> V_132 ) ;
if ( V_57 )
V_76 = F_16 ( V_2 , V_35 , V_57 -> V_136 ) ;
return V_76 ;
}
struct V_55 * F_68 ( struct V_1 * V_2 ,
struct V_6 * V_7 ,
struct V_56 * V_19 )
{
struct V_55 * V_57 ;
V_57 = F_40 ( sizeof( struct V_55 ) , V_79 ) ;
if ( V_57 == NULL ) {
return NULL ;
}
V_57 -> V_7 = V_7 ;
V_57 -> V_19 = V_19 ;
V_57 -> V_143 = 1 ;
F_69 ( & V_57 -> V_144 ) ;
F_69 ( & V_57 -> V_134 ) ;
F_69 ( & V_57 -> V_135 ) ;
F_69 ( & V_57 -> V_133 ) ;
F_70 ( & V_57 -> V_142 ) ;
F_71 ( & V_57 -> V_144 , & V_19 -> V_145 ) ;
return V_57 ;
}
int F_72 ( struct V_1 * V_2 ,
struct V_55 * V_57 ,
T_1 V_146 , T_1 V_124 ,
T_1 V_147 , T_2 V_64 )
{
struct V_116 * V_117 ;
struct V_6 * V_7 = V_57 -> V_7 ;
struct V_148 * V_122 ;
unsigned V_149 , V_92 ;
T_1 V_150 ;
int V_76 ;
if ( V_146 & V_151 || V_124 & V_151 ||
V_147 == 0 || V_147 & V_151 )
return - V_50 ;
V_150 = V_146 + V_147 - 1 ;
if ( ( V_146 >= V_150 ) || ( V_124 + V_147 > F_39 ( V_57 -> V_19 ) ) )
return - V_50 ;
V_149 = V_150 / V_106 ;
if ( V_149 >= V_2 -> V_3 . V_4 ) {
F_73 ( V_2 -> V_152 , L_1 ,
V_149 , V_2 -> V_3 . V_4 ) ;
return - V_50 ;
}
V_146 /= V_106 ;
V_150 /= V_106 ;
F_8 ( & V_7 -> V_153 ) ;
V_122 = F_74 ( & V_7 -> V_145 , V_146 , V_150 ) ;
F_10 ( & V_7 -> V_153 ) ;
if ( V_122 ) {
struct V_116 * V_154 ;
V_154 = F_75 ( V_122 , struct V_116 , V_122 ) ;
F_73 ( V_2 -> V_152 , L_2
L_3 , V_57 -> V_19 , V_146 , V_150 ,
V_154 -> V_122 . V_107 , V_154 -> V_122 . V_123 + 1 ) ;
V_76 = - V_50 ;
goto error;
}
V_117 = F_76 ( sizeof( * V_117 ) , V_79 ) ;
if ( ! V_117 ) {
V_76 = - V_94 ;
goto error;
}
F_69 ( & V_117 -> V_140 ) ;
V_117 -> V_122 . V_107 = V_146 ;
V_117 -> V_122 . V_123 = V_150 ;
V_117 -> V_124 = V_124 ;
V_117 -> V_64 = V_64 ;
F_66 ( & V_57 -> V_142 ) ;
F_5 ( & V_117 -> V_140 , & V_57 -> V_135 ) ;
F_67 ( & V_57 -> V_142 ) ;
F_8 ( & V_7 -> V_153 ) ;
F_77 ( & V_117 -> V_122 , & V_7 -> V_145 ) ;
F_10 ( & V_7 -> V_153 ) ;
F_78 ( V_57 , V_117 ) ;
V_146 >>= V_5 ;
V_150 >>= V_5 ;
F_79 ( V_150 >= F_1 ( V_2 ) ) ;
if ( V_150 > V_7 -> V_25 )
V_7 -> V_25 = V_150 ;
for ( V_92 = V_146 ; V_92 <= V_150 ; ++ V_92 ) {
struct V_155 * V_77 = V_7 -> V_13 -> V_20 . V_77 ;
struct V_10 * V_11 ;
struct V_56 * V_96 ;
V_11 = & V_7 -> V_26 [ V_92 ] . V_11 ;
if ( V_11 -> V_12 )
continue;
V_76 = F_80 ( V_2 , V_89 * 8 ,
V_106 , true ,
V_15 ,
V_156 ,
NULL , V_77 , & V_96 ) ;
if ( V_76 )
goto V_80;
V_96 -> V_157 = F_81 ( V_7 -> V_13 ) ;
V_76 = F_36 ( V_2 , V_96 ) ;
if ( V_76 ) {
F_82 ( & V_96 ) ;
goto V_80;
}
V_11 -> V_12 = V_96 ;
V_11 -> V_14 = V_15 ;
V_11 -> V_16 = V_15 ;
V_11 -> V_17 = 0 ;
V_11 -> V_18 . V_19 = & V_11 -> V_12 -> V_20 ;
V_11 -> V_18 . V_21 = true ;
V_7 -> V_26 [ V_92 ] . V_61 = 0 ;
}
return 0 ;
V_80:
F_64 ( & V_117 -> V_140 ) ;
F_8 ( & V_7 -> V_153 ) ;
F_83 ( & V_117 -> V_122 , & V_7 -> V_145 ) ;
F_10 ( & V_7 -> V_153 ) ;
F_84 ( V_57 , V_117 ) ;
F_35 ( V_117 ) ;
error:
return V_76 ;
}
int F_85 ( struct V_1 * V_2 ,
struct V_55 * V_57 ,
T_1 V_146 )
{
struct V_116 * V_117 ;
struct V_6 * V_7 = V_57 -> V_7 ;
bool V_158 = true ;
V_146 /= V_106 ;
F_66 ( & V_57 -> V_142 ) ;
F_27 (mapping, &bo_va->valids, list) {
if ( V_117 -> V_122 . V_107 == V_146 )
break;
}
if ( & V_117 -> V_140 == & V_57 -> V_134 ) {
V_158 = false ;
F_27 (mapping, &bo_va->invalids, list) {
if ( V_117 -> V_122 . V_107 == V_146 )
break;
}
if ( & V_117 -> V_140 == & V_57 -> V_135 ) {
F_67 ( & V_57 -> V_142 ) ;
return - V_159 ;
}
}
F_67 ( & V_57 -> V_142 ) ;
F_64 ( & V_117 -> V_140 ) ;
F_8 ( & V_7 -> V_153 ) ;
F_83 ( & V_117 -> V_122 , & V_7 -> V_145 ) ;
F_10 ( & V_7 -> V_153 ) ;
F_84 ( V_57 , V_117 ) ;
if ( V_158 ) {
F_8 ( & V_7 -> V_138 ) ;
F_5 ( & V_117 -> V_140 , & V_7 -> V_139 ) ;
F_10 ( & V_7 -> V_138 ) ;
} else {
F_35 ( V_117 ) ;
}
return 0 ;
}
void F_86 ( struct V_1 * V_2 ,
struct V_55 * V_57 )
{
struct V_116 * V_117 , * V_160 ;
struct V_6 * V_7 = V_57 -> V_7 ;
F_64 ( & V_57 -> V_144 ) ;
F_8 ( & V_7 -> V_132 ) ;
F_64 ( & V_57 -> V_133 ) ;
F_10 ( & V_7 -> V_132 ) ;
F_87 (mapping, next, &bo_va->valids, list) {
F_64 ( & V_117 -> V_140 ) ;
F_8 ( & V_7 -> V_153 ) ;
F_83 ( & V_117 -> V_122 , & V_7 -> V_145 ) ;
F_10 ( & V_7 -> V_153 ) ;
F_84 ( V_57 , V_117 ) ;
F_8 ( & V_7 -> V_138 ) ;
F_5 ( & V_117 -> V_140 , & V_7 -> V_139 ) ;
F_10 ( & V_7 -> V_138 ) ;
}
F_87 (mapping, next, &bo_va->invalids, list) {
F_64 ( & V_117 -> V_140 ) ;
F_8 ( & V_7 -> V_153 ) ;
F_83 ( & V_117 -> V_122 , & V_7 -> V_145 ) ;
F_10 ( & V_7 -> V_153 ) ;
F_35 ( V_117 ) ;
}
F_22 ( V_57 -> V_136 ) ;
F_88 ( & V_57 -> V_142 ) ;
F_35 ( V_57 ) ;
}
void F_89 ( struct V_1 * V_2 ,
struct V_56 * V_19 )
{
struct V_55 * V_57 ;
F_27 (bo_va, &bo->va, bo_list) {
F_8 ( & V_57 -> V_7 -> V_132 ) ;
if ( F_57 ( & V_57 -> V_133 ) )
F_5 ( & V_57 -> V_133 , & V_57 -> V_7 -> V_141 ) ;
F_10 ( & V_57 -> V_7 -> V_132 ) ;
}
}
int F_90 ( struct V_1 * V_2 , struct V_6 * V_7 )
{
const unsigned V_161 = F_54 ( V_162 ,
V_89 * 8 ) ;
unsigned V_163 , V_164 ;
int V_24 , V_76 ;
for ( V_24 = 0 ; V_24 < V_38 ; ++ V_24 ) {
V_7 -> V_41 [ V_24 ] . V_44 = 0 ;
V_7 -> V_41 [ V_24 ] . V_53 = NULL ;
}
V_7 -> V_145 = V_165 ;
F_91 ( & V_7 -> V_132 ) ;
F_69 ( & V_7 -> V_141 ) ;
F_69 ( & V_7 -> V_137 ) ;
F_69 ( & V_7 -> V_139 ) ;
F_91 ( & V_7 -> V_153 ) ;
F_91 ( & V_7 -> V_138 ) ;
V_163 = F_2 ( V_2 ) ;
V_164 = F_1 ( V_2 ) ;
V_7 -> V_26 = F_92 ( V_164 , sizeof( struct V_166 ) ) ;
if ( V_7 -> V_26 == NULL ) {
F_93 ( L_4 ) ;
return - V_94 ;
}
V_7 -> V_98 = NULL ;
V_76 = F_80 ( V_2 , V_163 , V_161 , true ,
V_15 ,
V_156 ,
NULL , NULL , & V_7 -> V_13 ) ;
if ( V_76 )
return V_76 ;
V_76 = F_94 ( V_7 -> V_13 , false ) ;
if ( V_76 ) {
F_82 ( & V_7 -> V_13 ) ;
V_7 -> V_13 = NULL ;
return V_76 ;
}
V_76 = F_36 ( V_2 , V_7 -> V_13 ) ;
F_95 ( V_7 -> V_13 ) ;
if ( V_76 ) {
F_82 ( & V_7 -> V_13 ) ;
V_7 -> V_13 = NULL ;
return V_76 ;
}
return 0 ;
}
void F_96 ( struct V_1 * V_2 , struct V_6 * V_7 )
{
struct V_116 * V_117 , * V_154 ;
int V_24 ;
if ( ! F_97 ( & V_7 -> V_145 ) ) {
F_73 ( V_2 -> V_152 , L_5 ) ;
}
F_98 (mapping, tmp, &vm->va, it.rb) {
F_64 ( & V_117 -> V_140 ) ;
F_83 ( & V_117 -> V_122 , & V_7 -> V_145 ) ;
F_35 ( V_117 ) ;
}
F_87 (mapping, tmp, &vm->freed, list) {
F_64 ( & V_117 -> V_140 ) ;
F_35 ( V_117 ) ;
}
for ( V_24 = 0 ; V_24 < F_1 ( V_2 ) ; V_24 ++ )
F_82 ( & V_7 -> V_26 [ V_24 ] . V_11 . V_12 ) ;
F_99 ( V_7 -> V_26 ) ;
F_82 ( & V_7 -> V_13 ) ;
F_22 ( V_7 -> V_98 ) ;
for ( V_24 = 0 ; V_24 < V_38 ; ++ V_24 ) {
unsigned V_44 = V_7 -> V_41 [ V_24 ] . V_44 ;
F_100 ( & V_2 -> V_3 . V_41 [ V_44 ] . V_45 ,
( long ) V_7 , 0 ) ;
F_22 ( V_7 -> V_41 [ V_24 ] . V_53 ) ;
}
}
void F_101 ( struct V_1 * V_2 )
{
unsigned V_24 ;
for ( V_24 = 0 ; V_24 < V_167 ; ++ V_24 )
F_22 ( V_2 -> V_3 . V_41 [ V_24 ] . V_48 ) ;
}
