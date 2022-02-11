static unsigned F_1 ( struct V_1 * V_2 )
{
return V_2 -> V_3 . V_4 >> V_5 ;
}
static unsigned F_2 ( struct V_1 * V_2 )
{
return F_3 ( F_1 ( V_2 ) * 8 ) ;
}
struct V_6 * F_4 ( struct V_1 * V_2 ,
struct V_7 * V_8 ,
struct V_9 * V_10 )
{
struct V_6 * V_11 ;
unsigned V_12 , V_13 ;
F_5 ( & V_8 -> V_14 ) ;
V_11 = F_6 ( V_8 -> V_15 + 2 ,
sizeof( struct V_6 ) ) ;
if ( ! V_11 ) {
F_7 ( & V_8 -> V_14 ) ;
return NULL ;
}
V_11 [ 0 ] . V_16 = V_8 -> V_17 ;
V_11 [ 0 ] . V_18 = V_19 ;
V_11 [ 0 ] . V_20 = V_19 ;
V_11 [ 0 ] . V_21 = 0 ;
V_11 [ 0 ] . V_22 . V_23 = & V_8 -> V_17 -> V_24 ;
V_11 [ 0 ] . V_22 . V_25 = true ;
F_8 ( & V_11 [ 0 ] . V_22 . V_10 , V_10 ) ;
for ( V_12 = 0 , V_13 = 1 ; V_12 <= V_8 -> V_15 ; V_12 ++ ) {
if ( ! V_8 -> V_26 [ V_12 ] . V_23 )
continue;
V_11 [ V_13 ] . V_16 = V_8 -> V_26 [ V_12 ] . V_23 ;
V_11 [ V_13 ] . V_18 = V_19 ;
V_11 [ V_13 ] . V_20 = V_19 ;
V_11 [ V_13 ] . V_21 = 0 ;
V_11 [ V_13 ] . V_22 . V_23 = & V_11 [ V_13 ] . V_16 -> V_24 ;
V_11 [ V_13 ] . V_22 . V_25 = true ;
F_8 ( & V_11 [ V_13 ++ ] . V_22 . V_10 , V_10 ) ;
}
F_7 ( & V_8 -> V_14 ) ;
return V_11 ;
}
int F_9 ( struct V_7 * V_8 , struct V_27 * V_28 ,
struct V_29 * V_30 )
{
struct V_31 * V_32 [ V_33 ] = {} ;
struct V_34 * V_35 = & V_8 -> V_36 [ V_28 -> V_13 ] ;
struct V_1 * V_2 = V_28 -> V_2 ;
unsigned V_37 [ 2 ] = {} ;
unsigned V_12 ;
if ( V_35 -> V_38 && V_35 -> V_39 &&
V_35 -> V_39 == V_2 -> V_3 . V_40 [ V_35 -> V_38 ] )
return 0 ;
V_35 -> V_41 = ~ 0ll ;
for ( V_12 = 1 ; V_12 < V_2 -> V_3 . V_42 ; ++ V_12 ) {
struct V_31 * V_43 = V_2 -> V_3 . V_40 [ V_12 ] ;
if ( V_43 == NULL ) {
V_35 -> V_38 = V_12 ;
F_10 ( V_12 , V_28 -> V_13 ) ;
return 0 ;
}
if ( F_11 ( V_43 , V_32 [ V_43 -> V_28 -> V_13 ] ) ) {
V_32 [ V_43 -> V_28 -> V_13 ] = V_43 ;
V_37 [ V_43 -> V_28 == V_28 ? 0 : 1 ] = V_12 ;
}
}
for ( V_12 = 0 ; V_12 < 2 ; ++ V_12 ) {
if ( V_37 [ V_12 ] ) {
struct V_31 * V_43 ;
V_43 = V_2 -> V_3 . V_40 [ V_37 [ V_12 ] ] ;
V_35 -> V_38 = V_37 [ V_12 ] ;
F_10 ( V_37 [ V_12 ] , V_28 -> V_13 ) ;
return F_12 ( V_28 -> V_2 , V_30 , & V_43 -> V_44 ) ;
}
}
F_13 () ;
return - V_45 ;
}
void F_14 ( struct V_27 * V_28 ,
struct V_7 * V_8 ,
struct V_43 * V_46 )
{
T_1 V_47 = F_15 ( V_8 -> V_17 ) ;
struct V_34 * V_35 = & V_8 -> V_36 [ V_28 -> V_13 ] ;
struct V_43 * V_48 = V_35 -> V_48 ;
bool V_49 = false ;
if ( V_48 && V_46 ) {
F_16 ( V_48 -> V_50 != V_46 -> V_50 ) ;
V_49 = ( V_46 -> V_51 - V_48 -> V_51 <=
V_52 ) ? true : false ;
}
if ( V_47 != V_35 -> V_41 || ! V_48 ||
V_49 ) {
F_17 ( V_47 , V_28 -> V_13 , V_35 -> V_38 ) ;
if ( V_49 ) {
V_35 -> V_48 = F_18 ( V_46 ) ;
F_19 ( V_48 ) ;
}
if ( ! V_48 )
V_35 -> V_48 = F_18 ( V_46 ) ;
V_35 -> V_41 = V_47 ;
F_20 ( V_28 , V_35 -> V_38 , V_35 -> V_41 ) ;
}
}
void F_21 ( struct V_1 * V_2 ,
struct V_7 * V_8 ,
struct V_31 * V_43 )
{
unsigned V_53 = V_43 -> V_28 -> V_13 ;
unsigned V_35 = V_8 -> V_36 [ V_53 ] . V_38 ;
F_22 ( & V_2 -> V_3 . V_40 [ V_35 ] ) ;
V_2 -> V_3 . V_40 [ V_35 ] = F_23 ( V_43 ) ;
F_22 ( & V_8 -> V_36 [ V_53 ] . V_39 ) ;
V_8 -> V_36 [ V_53 ] . V_39 = F_23 ( V_43 ) ;
}
struct V_54 * F_24 ( struct V_7 * V_8 ,
struct V_55 * V_23 )
{
struct V_54 * V_56 ;
F_25 (bo_va, &bo->va, bo_list) {
if ( V_56 -> V_8 == V_8 ) {
return V_56 ;
}
}
return NULL ;
}
static void F_26 ( struct V_1 * V_2 ,
struct V_57 * V_58 ,
T_1 V_59 , T_1 V_60 ,
unsigned V_61 , T_2 V_62 ,
T_2 V_63 , T_2 V_64 )
{
F_27 ( V_59 , V_60 , V_61 , V_62 , V_63 ) ;
if ( ( V_63 & V_65 ) && ( V_63 == V_64 ) ) {
T_1 V_66 = V_2 -> V_67 . V_68 + ( V_60 >> 12 ) * 8 ;
F_28 ( V_2 , V_58 , V_59 , V_66 , V_61 ) ;
} else if ( ( V_63 & V_65 ) || ( V_61 < 3 ) ) {
F_29 ( V_2 , V_58 , V_59 , V_60 ,
V_61 , V_62 , V_63 ) ;
} else {
F_30 ( V_2 , V_58 , V_59 , V_60 ,
V_61 , V_62 , V_63 ) ;
}
}
int F_31 ( struct V_69 * V_70 )
{
int V_12 ;
for ( V_12 = 0 ; V_12 < V_70 -> V_71 ; V_12 ++ )
F_32 ( V_70 -> V_2 , & V_70 -> V_72 [ V_12 ] ) ;
F_33 ( V_70 -> V_72 ) ;
return 0 ;
}
static int F_34 ( struct V_1 * V_2 ,
struct V_55 * V_23 )
{
struct V_27 * V_28 = V_2 -> V_3 . V_73 ;
struct V_43 * V_43 = NULL ;
struct V_57 * V_58 ;
unsigned V_74 ;
T_1 V_60 ;
int V_75 ;
V_75 = F_35 ( V_23 , false ) ;
if ( V_75 )
return V_75 ;
V_75 = F_36 ( V_23 -> V_24 . V_76 ) ;
if ( V_75 )
return V_75 ;
V_75 = F_37 ( & V_23 -> V_24 , & V_23 -> V_77 , true , false ) ;
if ( V_75 )
goto V_78;
V_60 = F_15 ( V_23 ) ;
V_74 = F_38 ( V_23 ) / 8 ;
V_58 = F_39 ( sizeof( struct V_57 ) , V_79 ) ;
if ( ! V_58 )
goto V_78;
V_75 = F_40 ( V_28 , NULL , V_74 * 2 + 64 , V_58 ) ;
if ( V_75 )
goto V_80;
V_58 -> V_81 = 0 ;
F_26 ( V_2 , V_58 , V_60 , 0 , V_74 , 0 , 0 , 0 ) ;
F_41 ( V_2 , V_58 ) ;
F_42 ( V_58 -> V_81 > 64 ) ;
V_75 = F_43 ( V_2 , V_28 , V_58 , 1 ,
& F_31 ,
V_82 ,
& V_43 ) ;
if ( ! V_75 )
F_44 ( V_23 , V_43 , true ) ;
F_19 ( V_43 ) ;
if ( V_83 ) {
F_45 ( V_23 ) ;
return 0 ;
}
V_80:
F_32 ( V_2 , V_58 ) ;
F_33 ( V_58 ) ;
V_78:
F_45 ( V_23 ) ;
return V_75 ;
}
T_1 F_46 ( struct V_1 * V_2 , T_1 V_60 )
{
T_1 V_84 ;
V_84 = V_2 -> V_67 . V_85 [ V_60 >> V_86 ] ;
V_84 |= V_60 & ( ~ V_87 ) ;
return V_84 ;
}
int F_47 ( struct V_1 * V_2 ,
struct V_7 * V_8 )
{
struct V_27 * V_28 = V_2 -> V_3 . V_73 ;
struct V_55 * V_88 = V_8 -> V_17 ;
T_1 V_47 = F_15 ( V_88 ) ;
T_2 V_62 = V_89 * 8 ;
T_1 V_90 = ~ 0 , V_91 = ~ 0 ;
unsigned V_61 = 0 , V_92 , V_93 ;
struct V_57 * V_58 ;
struct V_43 * V_43 = NULL ;
int V_75 ;
V_93 = 64 ;
V_93 += V_8 -> V_15 * 6 ;
if ( V_93 > 0xfffff )
return - V_94 ;
V_58 = F_39 ( sizeof( struct V_57 ) , V_79 ) ;
if ( ! V_58 )
return - V_94 ;
V_75 = F_40 ( V_28 , NULL , V_93 * 4 , V_58 ) ;
if ( V_75 ) {
F_33 ( V_58 ) ;
return V_75 ;
}
V_58 -> V_81 = 0 ;
for ( V_92 = 0 ; V_92 <= V_8 -> V_15 ; ++ V_92 ) {
struct V_55 * V_23 = V_8 -> V_26 [ V_92 ] . V_23 ;
T_1 V_95 , V_96 ;
if ( V_23 == NULL )
continue;
V_96 = F_15 ( V_23 ) ;
if ( V_8 -> V_26 [ V_92 ] . V_60 == V_96 )
continue;
V_8 -> V_26 [ V_92 ] . V_60 = V_96 ;
V_95 = V_47 + V_92 * 8 ;
if ( ( ( V_90 + 8 * V_61 ) != V_95 ) ||
( ( V_91 + V_62 * V_61 ) != V_96 ) ) {
if ( V_61 ) {
F_26 ( V_2 , V_58 , V_90 ,
V_91 , V_61 , V_62 ,
V_97 , 0 ) ;
}
V_61 = 1 ;
V_90 = V_95 ;
V_91 = V_96 ;
} else {
++ V_61 ;
}
}
if ( V_61 )
F_26 ( V_2 , V_58 , V_90 , V_91 , V_61 ,
V_62 , V_97 , 0 ) ;
if ( V_58 -> V_81 != 0 ) {
F_41 ( V_2 , V_58 ) ;
F_48 ( V_2 , & V_58 -> V_30 , V_88 -> V_24 . V_76 , V_82 ) ;
F_42 ( V_58 -> V_81 > V_93 ) ;
V_75 = F_43 ( V_2 , V_28 , V_58 , 1 ,
& F_31 ,
V_82 ,
& V_43 ) ;
if ( V_75 )
goto V_80;
F_44 ( V_88 , V_43 , true ) ;
F_19 ( V_8 -> V_98 ) ;
V_8 -> V_98 = F_18 ( V_43 ) ;
F_19 ( V_43 ) ;
}
if ( ! V_83 || V_58 -> V_81 == 0 ) {
F_32 ( V_2 , V_58 ) ;
F_33 ( V_58 ) ;
}
return 0 ;
V_80:
F_32 ( V_2 , V_58 ) ;
F_33 ( V_58 ) ;
return V_75 ;
}
static void F_49 ( struct V_1 * V_2 ,
struct V_57 * V_58 ,
T_1 V_99 , T_1 V_100 ,
T_1 V_60 , T_2 V_63 ,
T_2 V_64 )
{
T_1 V_101 = V_102 ;
T_1 V_103 = 0x80 ;
T_1 V_104 = F_50 ( V_99 , V_103 ) ;
T_1 V_105 = V_100 & ~ ( V_103 - 1 ) ;
unsigned V_61 ;
if ( ( V_63 & V_65 ) || ! ( V_63 & V_97 ) ||
( V_104 >= V_105 ) ) {
V_61 = ( V_100 - V_99 ) / 8 ;
F_26 ( V_2 , V_58 , V_99 , V_60 , V_61 ,
V_106 , V_63 , V_64 ) ;
return;
}
if ( V_99 != V_104 ) {
V_61 = ( V_104 - V_99 ) / 8 ;
F_26 ( V_2 , V_58 , V_99 , V_60 , V_61 ,
V_106 , V_63 , V_64 ) ;
V_60 += V_106 * V_61 ;
}
V_61 = ( V_105 - V_104 ) / 8 ;
F_26 ( V_2 , V_58 , V_104 , V_60 , V_61 ,
V_106 , V_63 | V_101 ,
V_64 ) ;
if ( V_105 != V_100 ) {
V_60 += V_106 * V_61 ;
V_61 = ( V_100 - V_105 ) / 8 ;
F_26 ( V_2 , V_58 , V_105 , V_60 , V_61 ,
V_106 , V_63 , V_64 ) ;
}
}
static int F_51 ( struct V_1 * V_2 ,
struct V_7 * V_8 ,
struct V_57 * V_58 ,
T_1 V_107 , T_1 V_108 ,
T_1 V_109 , T_2 V_63 ,
T_2 V_64 )
{
T_1 V_110 = V_89 - 1 ;
T_1 V_111 = ~ 0 , V_112 = ~ 0 ;
void * V_113 = V_82 ;
unsigned V_61 = 0 ;
T_1 V_60 ;
if ( ! ( V_63 & V_97 ) )
V_113 = V_114 ;
for ( V_60 = V_107 ; V_60 < V_108 ; ) {
T_1 V_92 = V_60 >> V_5 ;
struct V_55 * V_96 = V_8 -> V_26 [ V_92 ] . V_23 ;
unsigned V_115 ;
T_1 V_116 ;
int V_75 ;
F_48 ( V_2 , & V_58 -> V_30 , V_96 -> V_24 . V_76 , V_113 ) ;
V_75 = F_36 ( V_96 -> V_24 . V_76 ) ;
if ( V_75 )
return V_75 ;
if ( ( V_60 & ~ V_110 ) == ( V_108 & ~ V_110 ) )
V_115 = V_108 - V_60 ;
else
V_115 = V_89 - ( V_60 & V_110 ) ;
V_116 = F_15 ( V_96 ) ;
V_116 += ( V_60 & V_110 ) * 8 ;
if ( ( V_111 + 8 * V_61 ) != V_116 ) {
if ( V_61 ) {
F_49 ( V_2 , V_58 , V_111 ,
V_111 + 8 * V_61 ,
V_112 , V_63 ,
V_64 ) ;
}
V_61 = V_115 ;
V_111 = V_116 ;
V_112 = V_109 ;
} else {
V_61 += V_115 ;
}
V_60 += V_115 ;
V_109 += V_115 * V_106 ;
}
if ( V_61 ) {
F_49 ( V_2 , V_58 , V_111 ,
V_111 + 8 * V_61 ,
V_112 , V_63 , V_64 ) ;
}
return 0 ;
}
static int F_52 ( struct V_1 * V_2 ,
struct V_7 * V_8 ,
struct V_117 * V_118 ,
T_1 V_60 , T_2 V_64 ,
struct V_43 * * V_43 )
{
struct V_27 * V_28 = V_2 -> V_3 . V_73 ;
unsigned V_115 , V_119 , V_93 ;
T_2 V_63 = V_64 ;
struct V_57 * V_58 ;
struct V_43 * V_120 = NULL ;
int V_75 ;
if ( ! ( V_118 -> V_63 & V_121 ) )
V_63 &= ~ V_121 ;
if ( ! ( V_118 -> V_63 & V_122 ) )
V_63 &= ~ V_122 ;
F_53 ( V_118 ) ;
V_115 = V_118 -> V_123 . V_124 - V_118 -> V_123 . V_107 + 1 ;
V_119 = ( V_115 >> F_54 ( V_5 , 11 ) ) + 1 ;
V_93 = 64 ;
if ( ( V_63 & V_65 ) && ( V_63 == V_64 ) ) {
V_93 += V_119 * 7 ;
} else if ( V_63 & V_65 ) {
V_93 += V_119 * 4 ;
V_93 += V_115 * 2 ;
} else {
V_93 += V_119 * 10 ;
V_93 += 2 * 10 ;
}
if ( V_93 > 0xfffff )
return - V_94 ;
V_58 = F_39 ( sizeof( struct V_57 ) , V_79 ) ;
if ( ! V_58 )
return - V_94 ;
V_75 = F_40 ( V_28 , NULL , V_93 * 4 , V_58 ) ;
if ( V_75 ) {
F_33 ( V_58 ) ;
return V_75 ;
}
V_58 -> V_81 = 0 ;
V_75 = F_51 ( V_2 , V_8 , V_58 , V_118 -> V_123 . V_107 ,
V_118 -> V_123 . V_124 + 1 , V_60 + V_118 -> V_125 ,
V_63 , V_64 ) ;
if ( V_75 ) {
F_32 ( V_2 , V_58 ) ;
F_33 ( V_58 ) ;
return V_75 ;
}
F_41 ( V_2 , V_58 ) ;
F_42 ( V_58 -> V_81 > V_93 ) ;
V_75 = F_43 ( V_2 , V_28 , V_58 , 1 ,
& F_31 ,
V_82 ,
& V_120 ) ;
if ( V_75 )
goto V_80;
F_44 ( V_8 -> V_17 , V_120 , true ) ;
if ( V_43 ) {
F_19 ( * V_43 ) ;
* V_43 = F_18 ( V_120 ) ;
}
F_19 ( V_120 ) ;
if ( ! V_83 ) {
F_32 ( V_2 , V_58 ) ;
F_33 ( V_58 ) ;
}
return 0 ;
V_80:
F_32 ( V_2 , V_58 ) ;
F_33 ( V_58 ) ;
return V_75 ;
}
int F_55 ( struct V_1 * V_2 ,
struct V_54 * V_56 ,
struct V_126 * V_127 )
{
struct V_7 * V_8 = V_56 -> V_8 ;
struct V_117 * V_118 ;
T_2 V_63 ;
T_1 V_60 ;
int V_75 ;
if ( V_127 ) {
V_60 = ( V_128 ) V_127 -> V_107 << V_86 ;
if ( V_127 -> V_129 != V_130 )
V_60 += V_2 -> V_3 . V_131 ;
} else {
V_60 = 0 ;
}
V_63 = F_56 ( V_2 , V_56 -> V_23 -> V_24 . V_132 , V_127 ) ;
F_57 ( & V_8 -> V_133 ) ;
if ( ! F_58 ( & V_56 -> V_134 ) )
F_59 ( & V_56 -> V_135 , & V_56 -> V_136 ) ;
F_60 ( & V_8 -> V_133 ) ;
F_25 (mapping, &bo_va->invalids, list) {
V_75 = F_52 ( V_2 , V_8 , V_118 , V_60 ,
V_63 , & V_56 -> V_137 ) ;
if ( V_75 )
return V_75 ;
}
F_57 ( & V_8 -> V_133 ) ;
F_59 ( & V_56 -> V_136 , & V_56 -> V_135 ) ;
F_61 ( & V_56 -> V_134 ) ;
if ( ! V_127 )
F_8 ( & V_56 -> V_134 , & V_8 -> V_138 ) ;
F_60 ( & V_8 -> V_133 ) ;
return 0 ;
}
int F_62 ( struct V_1 * V_2 ,
struct V_7 * V_8 )
{
struct V_117 * V_118 ;
int V_75 ;
while ( ! F_58 ( & V_8 -> V_139 ) ) {
V_118 = F_63 ( & V_8 -> V_139 ,
struct V_117 , V_11 ) ;
F_64 ( & V_118 -> V_11 ) ;
V_75 = F_52 ( V_2 , V_8 , V_118 , 0 , 0 , NULL ) ;
F_33 ( V_118 ) ;
if ( V_75 )
return V_75 ;
}
return 0 ;
}
int F_65 ( struct V_1 * V_2 ,
struct V_7 * V_8 , struct V_29 * V_30 )
{
struct V_54 * V_56 = NULL ;
int V_75 = 0 ;
F_57 ( & V_8 -> V_133 ) ;
while ( ! F_58 ( & V_8 -> V_140 ) ) {
V_56 = F_63 ( & V_8 -> V_140 ,
struct V_54 , V_134 ) ;
F_60 ( & V_8 -> V_133 ) ;
V_75 = F_55 ( V_2 , V_56 , NULL ) ;
if ( V_75 )
return V_75 ;
F_57 ( & V_8 -> V_133 ) ;
}
F_60 ( & V_8 -> V_133 ) ;
if ( V_56 )
V_75 = F_12 ( V_2 , V_30 , V_56 -> V_137 ) ;
return V_75 ;
}
struct V_54 * F_66 ( struct V_1 * V_2 ,
struct V_7 * V_8 ,
struct V_55 * V_23 )
{
struct V_54 * V_56 ;
V_56 = F_39 ( sizeof( struct V_54 ) , V_79 ) ;
if ( V_56 == NULL ) {
return NULL ;
}
V_56 -> V_8 = V_8 ;
V_56 -> V_23 = V_23 ;
V_56 -> V_141 = 1 ;
F_67 ( & V_56 -> V_142 ) ;
F_67 ( & V_56 -> V_135 ) ;
F_67 ( & V_56 -> V_136 ) ;
F_67 ( & V_56 -> V_134 ) ;
F_5 ( & V_8 -> V_14 ) ;
F_68 ( & V_56 -> V_142 , & V_23 -> V_143 ) ;
F_7 ( & V_8 -> V_14 ) ;
return V_56 ;
}
int F_69 ( struct V_1 * V_2 ,
struct V_54 * V_56 ,
T_1 V_144 , T_1 V_125 ,
T_1 V_145 , T_2 V_63 )
{
struct V_117 * V_118 ;
struct V_7 * V_8 = V_56 -> V_8 ;
struct V_146 * V_123 ;
unsigned V_147 , V_92 ;
T_1 V_148 ;
int V_75 ;
if ( V_144 & V_149 || V_125 & V_149 ||
V_145 == 0 || V_145 & V_149 ) {
F_45 ( V_56 -> V_23 ) ;
return - V_45 ;
}
V_148 = V_144 + V_145 ;
if ( ( V_144 >= V_148 ) || ( V_125 + V_145 > F_38 ( V_56 -> V_23 ) ) ) {
F_45 ( V_56 -> V_23 ) ;
return - V_45 ;
}
V_147 = V_148 / V_106 ;
if ( V_147 > V_2 -> V_3 . V_4 ) {
F_70 ( V_2 -> V_150 , L_1 ,
V_147 , V_2 -> V_3 . V_4 ) ;
F_45 ( V_56 -> V_23 ) ;
return - V_45 ;
}
F_5 ( & V_8 -> V_14 ) ;
V_144 /= V_106 ;
V_148 /= V_106 ;
V_123 = F_71 ( & V_8 -> V_143 , V_144 , V_148 - 1 ) ;
if ( V_123 ) {
struct V_117 * V_151 ;
V_151 = F_72 ( V_123 , struct V_117 , V_123 ) ;
F_70 ( V_2 -> V_150 , L_2
L_3 , V_56 -> V_23 , V_144 , V_148 ,
V_151 -> V_123 . V_107 , V_151 -> V_123 . V_124 + 1 ) ;
F_45 ( V_56 -> V_23 ) ;
V_75 = - V_45 ;
goto V_152;
}
V_118 = F_73 ( sizeof( * V_118 ) , V_79 ) ;
if ( ! V_118 ) {
F_45 ( V_56 -> V_23 ) ;
V_75 = - V_94 ;
goto V_152;
}
F_67 ( & V_118 -> V_11 ) ;
V_118 -> V_123 . V_107 = V_144 ;
V_118 -> V_123 . V_124 = V_148 - 1 ;
V_118 -> V_125 = V_125 ;
V_118 -> V_63 = V_63 ;
F_8 ( & V_118 -> V_11 , & V_56 -> V_136 ) ;
F_74 ( & V_118 -> V_123 , & V_8 -> V_143 ) ;
F_75 ( V_56 , V_118 ) ;
V_144 >>= V_5 ;
V_148 >>= V_5 ;
F_16 ( V_148 >= F_1 ( V_2 ) ) ;
if ( V_148 > V_8 -> V_15 )
V_8 -> V_15 = V_148 ;
F_45 ( V_56 -> V_23 ) ;
for ( V_92 = V_144 ; V_92 <= V_148 ; ++ V_92 ) {
struct V_153 * V_76 = V_8 -> V_17 -> V_24 . V_76 ;
struct V_55 * V_96 ;
if ( V_8 -> V_26 [ V_92 ] . V_23 )
continue;
F_7 ( & V_8 -> V_14 ) ;
F_76 ( & V_76 -> V_154 , NULL ) ;
V_75 = F_77 ( V_2 , V_89 * 8 ,
V_106 , true ,
V_19 ,
V_155 ,
NULL , V_76 , & V_96 ) ;
F_78 ( & V_76 -> V_154 ) ;
if ( V_75 )
goto V_80;
V_75 = F_34 ( V_2 , V_96 ) ;
if ( V_75 ) {
F_79 ( & V_96 ) ;
goto V_80;
}
F_5 ( & V_8 -> V_14 ) ;
if ( V_8 -> V_26 [ V_92 ] . V_23 ) {
F_7 ( & V_8 -> V_14 ) ;
F_79 ( & V_96 ) ;
F_5 ( & V_8 -> V_14 ) ;
continue;
}
V_8 -> V_26 [ V_92 ] . V_60 = 0 ;
V_8 -> V_26 [ V_92 ] . V_23 = V_96 ;
}
F_7 ( & V_8 -> V_14 ) ;
return 0 ;
V_80:
F_5 ( & V_8 -> V_14 ) ;
F_64 ( & V_118 -> V_11 ) ;
F_80 ( & V_118 -> V_123 , & V_8 -> V_143 ) ;
F_81 ( V_56 , V_118 ) ;
F_33 ( V_118 ) ;
V_152:
F_7 ( & V_8 -> V_14 ) ;
return V_75 ;
}
int F_82 ( struct V_1 * V_2 ,
struct V_54 * V_56 ,
T_1 V_144 )
{
struct V_117 * V_118 ;
struct V_7 * V_8 = V_56 -> V_8 ;
bool V_156 = true ;
V_144 /= V_106 ;
F_25 (mapping, &bo_va->valids, list) {
if ( V_118 -> V_123 . V_107 == V_144 )
break;
}
if ( & V_118 -> V_11 == & V_56 -> V_135 ) {
V_156 = false ;
F_25 (mapping, &bo_va->invalids, list) {
if ( V_118 -> V_123 . V_107 == V_144 )
break;
}
if ( & V_118 -> V_11 == & V_56 -> V_136 ) {
F_45 ( V_56 -> V_23 ) ;
return - V_157 ;
}
}
F_5 ( & V_8 -> V_14 ) ;
F_64 ( & V_118 -> V_11 ) ;
F_80 ( & V_118 -> V_123 , & V_8 -> V_143 ) ;
F_81 ( V_56 , V_118 ) ;
if ( V_156 )
F_8 ( & V_118 -> V_11 , & V_8 -> V_139 ) ;
else
F_33 ( V_118 ) ;
F_7 ( & V_8 -> V_14 ) ;
F_45 ( V_56 -> V_23 ) ;
return 0 ;
}
void F_83 ( struct V_1 * V_2 ,
struct V_54 * V_56 )
{
struct V_117 * V_118 , * V_158 ;
struct V_7 * V_8 = V_56 -> V_8 ;
F_64 ( & V_56 -> V_142 ) ;
F_5 ( & V_8 -> V_14 ) ;
F_57 ( & V_8 -> V_133 ) ;
F_64 ( & V_56 -> V_134 ) ;
F_60 ( & V_8 -> V_133 ) ;
F_84 (mapping, next, &bo_va->valids, list) {
F_64 ( & V_118 -> V_11 ) ;
F_80 ( & V_118 -> V_123 , & V_8 -> V_143 ) ;
F_81 ( V_56 , V_118 ) ;
F_8 ( & V_118 -> V_11 , & V_8 -> V_139 ) ;
}
F_84 (mapping, next, &bo_va->invalids, list) {
F_64 ( & V_118 -> V_11 ) ;
F_80 ( & V_118 -> V_123 , & V_8 -> V_143 ) ;
F_33 ( V_118 ) ;
}
F_19 ( V_56 -> V_137 ) ;
F_33 ( V_56 ) ;
F_7 ( & V_8 -> V_14 ) ;
}
void F_85 ( struct V_1 * V_2 ,
struct V_55 * V_23 )
{
struct V_54 * V_56 ;
F_25 (bo_va, &bo->va, bo_list) {
F_57 ( & V_56 -> V_8 -> V_133 ) ;
if ( F_58 ( & V_56 -> V_134 ) )
F_8 ( & V_56 -> V_134 , & V_56 -> V_8 -> V_140 ) ;
F_60 ( & V_56 -> V_8 -> V_133 ) ;
}
}
int F_86 ( struct V_1 * V_2 , struct V_7 * V_8 )
{
const unsigned V_159 = F_54 ( V_160 ,
V_89 * 8 ) ;
unsigned V_161 , V_162 , V_163 ;
int V_12 , V_75 ;
for ( V_12 = 0 ; V_12 < V_33 ; ++ V_12 ) {
V_8 -> V_36 [ V_12 ] . V_38 = 0 ;
V_8 -> V_36 [ V_12 ] . V_48 = NULL ;
V_8 -> V_36 [ V_12 ] . V_39 = NULL ;
}
F_87 ( & V_8 -> V_14 ) ;
V_8 -> V_143 = V_164 ;
F_88 ( & V_8 -> V_133 ) ;
F_67 ( & V_8 -> V_140 ) ;
F_67 ( & V_8 -> V_138 ) ;
F_67 ( & V_8 -> V_139 ) ;
V_161 = F_2 ( V_2 ) ;
V_162 = F_1 ( V_2 ) ;
V_163 = V_162 * sizeof( struct V_165 ) ;
V_8 -> V_26 = F_39 ( V_163 , V_79 ) ;
if ( V_8 -> V_26 == NULL ) {
F_89 ( L_4 ) ;
return - V_94 ;
}
V_8 -> V_98 = NULL ;
V_75 = F_77 ( V_2 , V_161 , V_159 , true ,
V_19 ,
V_155 ,
NULL , NULL , & V_8 -> V_17 ) ;
if ( V_75 )
return V_75 ;
V_75 = F_34 ( V_2 , V_8 -> V_17 ) ;
if ( V_75 ) {
F_79 ( & V_8 -> V_17 ) ;
V_8 -> V_17 = NULL ;
return V_75 ;
}
return 0 ;
}
void F_90 ( struct V_1 * V_2 , struct V_7 * V_8 )
{
struct V_117 * V_118 , * V_151 ;
int V_12 ;
if ( ! F_91 ( & V_8 -> V_143 ) ) {
F_70 ( V_2 -> V_150 , L_5 ) ;
}
F_92 (mapping, tmp, &vm->va, it.rb) {
F_64 ( & V_118 -> V_11 ) ;
F_80 ( & V_118 -> V_123 , & V_8 -> V_143 ) ;
F_33 ( V_118 ) ;
}
F_84 (mapping, tmp, &vm->freed, list) {
F_64 ( & V_118 -> V_11 ) ;
F_33 ( V_118 ) ;
}
for ( V_12 = 0 ; V_12 < F_1 ( V_2 ) ; V_12 ++ )
F_79 ( & V_8 -> V_26 [ V_12 ] . V_23 ) ;
F_33 ( V_8 -> V_26 ) ;
F_79 ( & V_8 -> V_17 ) ;
F_19 ( V_8 -> V_98 ) ;
for ( V_12 = 0 ; V_12 < V_33 ; ++ V_12 ) {
F_19 ( V_8 -> V_36 [ V_12 ] . V_48 ) ;
F_22 ( & V_8 -> V_36 [ V_12 ] . V_39 ) ;
}
F_93 ( & V_8 -> V_14 ) ;
}
