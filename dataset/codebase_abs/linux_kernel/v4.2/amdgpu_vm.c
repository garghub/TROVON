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
struct V_27 * F_9 ( struct V_28 * V_29 ,
struct V_7 * V_8 )
{
struct V_27 * V_30 [ V_31 ] = {} ;
struct V_32 * V_33 = & V_8 -> V_34 [ V_29 -> V_13 ] ;
struct V_1 * V_2 = V_29 -> V_2 ;
unsigned V_35 [ 2 ] = {} ;
unsigned V_12 ;
if ( V_33 -> V_36 && V_33 -> V_37 &&
V_33 -> V_37 == V_2 -> V_3 . V_38 [ V_33 -> V_36 ] )
return NULL ;
V_33 -> V_39 = ~ 0ll ;
for ( V_12 = 1 ; V_12 < V_2 -> V_3 . V_40 ; ++ V_12 ) {
struct V_27 * V_41 = V_2 -> V_3 . V_38 [ V_12 ] ;
if ( V_41 == NULL ) {
V_33 -> V_36 = V_12 ;
F_10 ( V_12 , V_29 -> V_13 ) ;
return NULL ;
}
if ( F_11 ( V_41 , V_30 [ V_41 -> V_29 -> V_13 ] ) ) {
V_30 [ V_41 -> V_29 -> V_13 ] = V_41 ;
V_35 [ V_41 -> V_29 == V_29 ? 0 : 1 ] = V_12 ;
}
}
for ( V_12 = 0 ; V_12 < 2 ; ++ V_12 ) {
if ( V_35 [ V_12 ] ) {
V_33 -> V_36 = V_35 [ V_12 ] ;
F_10 ( V_35 [ V_12 ] , V_29 -> V_13 ) ;
return V_2 -> V_3 . V_38 [ V_35 [ V_12 ] ] ;
}
}
F_12 () ;
return NULL ;
}
void F_13 ( struct V_28 * V_29 ,
struct V_7 * V_8 ,
struct V_27 * V_42 )
{
T_1 V_43 = F_14 ( V_8 -> V_17 ) ;
struct V_32 * V_33 = & V_8 -> V_34 [ V_29 -> V_13 ] ;
if ( V_43 != V_33 -> V_39 || ! V_33 -> V_44 ||
F_11 ( V_33 -> V_44 , V_42 ) ) {
F_15 ( V_43 , V_29 -> V_13 , V_33 -> V_36 ) ;
F_16 ( & V_33 -> V_44 ) ;
V_33 -> V_44 = F_17 ( V_42 ) ;
V_33 -> V_39 = V_43 ;
F_18 ( V_29 , V_33 -> V_36 , V_33 -> V_39 ) ;
}
}
void F_19 ( struct V_1 * V_2 ,
struct V_7 * V_8 ,
struct V_27 * V_41 )
{
unsigned V_45 = V_41 -> V_29 -> V_13 ;
unsigned V_33 = V_8 -> V_34 [ V_45 ] . V_36 ;
F_16 ( & V_2 -> V_3 . V_38 [ V_33 ] ) ;
V_2 -> V_3 . V_38 [ V_33 ] = F_17 ( V_41 ) ;
F_16 ( & V_8 -> V_34 [ V_45 ] . V_37 ) ;
V_8 -> V_34 [ V_45 ] . V_37 = F_17 ( V_41 ) ;
}
struct V_46 * F_20 ( struct V_7 * V_8 ,
struct V_47 * V_23 )
{
struct V_46 * V_48 ;
F_21 (bo_va, &bo->va, bo_list) {
if ( V_48 -> V_8 == V_8 ) {
return V_48 ;
}
}
return NULL ;
}
static void F_22 ( struct V_1 * V_2 ,
struct V_49 * V_50 ,
T_1 V_51 , T_1 V_52 ,
unsigned V_53 , T_2 V_54 ,
T_2 V_55 , T_2 V_56 )
{
F_23 ( V_51 , V_52 , V_53 , V_54 , V_55 ) ;
if ( ( V_55 & V_57 ) && ( V_55 == V_56 ) ) {
T_1 V_58 = V_2 -> V_59 . V_60 + ( V_52 >> 12 ) * 8 ;
F_24 ( V_2 , V_50 , V_51 , V_58 , V_53 ) ;
} else if ( ( V_55 & V_57 ) || ( V_53 < 3 ) ) {
F_25 ( V_2 , V_50 , V_51 , V_52 ,
V_53 , V_54 , V_55 ) ;
} else {
F_26 ( V_2 , V_50 , V_51 , V_52 ,
V_53 , V_54 , V_55 ) ;
}
}
static int F_27 ( struct V_1 * V_2 ,
struct V_47 * V_23 )
{
struct V_28 * V_29 = V_2 -> V_3 . V_61 ;
struct V_49 V_50 ;
unsigned V_62 ;
T_1 V_52 ;
int V_63 ;
V_63 = F_28 ( V_23 , false ) ;
if ( V_63 )
return V_63 ;
V_63 = F_29 ( V_23 -> V_24 . V_64 ) ;
if ( V_63 )
return V_63 ;
V_63 = F_30 ( & V_23 -> V_24 , & V_23 -> V_65 , true , false ) ;
if ( V_63 )
goto V_66;
V_52 = F_14 ( V_23 ) ;
V_62 = F_31 ( V_23 ) / 8 ;
V_63 = F_32 ( V_29 , NULL , V_62 * 2 + 64 , & V_50 ) ;
if ( V_63 )
goto V_66;
V_50 . V_67 = 0 ;
F_22 ( V_2 , & V_50 , V_52 , 0 , V_62 , 0 , 0 , 0 ) ;
F_33 ( V_2 , & V_50 ) ;
F_34 ( V_50 . V_67 > 64 ) ;
V_63 = F_35 ( V_2 , 1 , & V_50 , V_68 ) ;
if ( V_63 )
goto V_69;
F_36 ( V_23 , V_50 . V_41 , true ) ;
V_69:
F_37 ( V_2 , & V_50 ) ;
V_66:
F_38 ( V_23 ) ;
return V_63 ;
}
T_1 F_39 ( struct V_1 * V_2 , T_1 V_52 )
{
T_1 V_70 ;
V_70 = V_2 -> V_59 . V_71 [ V_52 >> V_72 ] ;
V_70 |= V_52 & ( ~ V_73 ) ;
return V_70 ;
}
int F_40 ( struct V_1 * V_2 ,
struct V_7 * V_8 )
{
struct V_28 * V_29 = V_2 -> V_3 . V_61 ;
struct V_47 * V_74 = V_8 -> V_17 ;
T_1 V_43 = F_14 ( V_74 ) ;
T_2 V_54 = V_75 * 8 ;
T_1 V_76 = ~ 0 , V_77 = ~ 0 ;
unsigned V_53 = 0 , V_78 , V_79 ;
struct V_49 V_50 ;
int V_63 ;
V_79 = 64 ;
V_79 += V_8 -> V_15 * 6 ;
if ( V_79 > 0xfffff )
return - V_80 ;
V_63 = F_32 ( V_29 , NULL , V_79 * 4 , & V_50 ) ;
if ( V_63 )
return V_63 ;
V_50 . V_67 = 0 ;
for ( V_78 = 0 ; V_78 <= V_8 -> V_15 ; ++ V_78 ) {
struct V_47 * V_23 = V_8 -> V_26 [ V_78 ] . V_23 ;
T_1 V_81 , V_82 ;
if ( V_23 == NULL )
continue;
V_82 = F_14 ( V_23 ) ;
if ( V_8 -> V_26 [ V_78 ] . V_52 == V_82 )
continue;
V_8 -> V_26 [ V_78 ] . V_52 = V_82 ;
V_81 = V_43 + V_78 * 8 ;
if ( ( ( V_76 + 8 * V_53 ) != V_81 ) ||
( ( V_77 + V_54 * V_53 ) != V_82 ) ) {
if ( V_53 ) {
F_22 ( V_2 , & V_50 , V_76 ,
V_77 , V_53 , V_54 ,
V_83 , 0 ) ;
}
V_53 = 1 ;
V_76 = V_81 ;
V_77 = V_82 ;
} else {
++ V_53 ;
}
}
if ( V_53 )
F_22 ( V_2 , & V_50 , V_76 , V_77 , V_53 ,
V_54 , V_83 , 0 ) ;
if ( V_50 . V_67 != 0 ) {
F_33 ( V_2 , & V_50 ) ;
F_41 ( V_2 , & V_50 . V_84 , V_74 -> V_24 . V_64 , V_68 ) ;
F_34 ( V_50 . V_67 > V_79 ) ;
V_63 = F_35 ( V_2 , 1 , & V_50 , V_68 ) ;
if ( V_63 ) {
F_37 ( V_2 , & V_50 ) ;
return V_63 ;
}
F_36 ( V_74 , V_50 . V_41 , true ) ;
}
F_37 ( V_2 , & V_50 ) ;
return 0 ;
}
static void F_42 ( struct V_1 * V_2 ,
struct V_49 * V_50 ,
T_1 V_85 , T_1 V_86 ,
T_1 V_52 , T_2 V_55 ,
T_2 V_56 )
{
T_1 V_87 = V_88 ;
T_1 V_89 = 0x80 ;
T_1 V_90 = F_43 ( V_85 , V_89 ) ;
T_1 V_91 = V_86 & ~ ( V_89 - 1 ) ;
unsigned V_53 ;
if ( ( V_55 & V_57 ) || ! ( V_55 & V_83 ) ||
( V_90 >= V_91 ) ) {
V_53 = ( V_86 - V_85 ) / 8 ;
F_22 ( V_2 , V_50 , V_85 , V_52 , V_53 ,
V_92 , V_55 , V_56 ) ;
return;
}
if ( V_85 != V_90 ) {
V_53 = ( V_90 - V_85 ) / 8 ;
F_22 ( V_2 , V_50 , V_85 , V_52 , V_53 ,
V_92 , V_55 , V_56 ) ;
V_52 += V_92 * V_53 ;
}
V_53 = ( V_91 - V_90 ) / 8 ;
F_22 ( V_2 , V_50 , V_90 , V_52 , V_53 ,
V_92 , V_55 | V_87 ,
V_56 ) ;
if ( V_91 != V_86 ) {
V_52 += V_92 * V_53 ;
V_53 = ( V_86 - V_91 ) / 8 ;
F_22 ( V_2 , V_50 , V_91 , V_52 , V_53 ,
V_92 , V_55 , V_56 ) ;
}
}
static int F_44 ( struct V_1 * V_2 ,
struct V_7 * V_8 ,
struct V_49 * V_50 ,
T_1 V_93 , T_1 V_94 ,
T_1 V_95 , T_2 V_55 ,
T_2 V_56 )
{
T_1 V_96 = V_75 - 1 ;
T_1 V_97 = ~ 0 , V_98 = ~ 0 ;
unsigned V_53 = 0 ;
T_1 V_52 ;
for ( V_52 = V_93 ; V_52 < V_94 ; ) {
T_1 V_78 = V_52 >> V_5 ;
struct V_47 * V_82 = V_8 -> V_26 [ V_78 ] . V_23 ;
unsigned V_99 ;
T_1 V_100 ;
int V_63 ;
F_41 ( V_2 , & V_50 -> V_84 , V_82 -> V_24 . V_64 ,
V_68 ) ;
V_63 = F_29 ( V_82 -> V_24 . V_64 ) ;
if ( V_63 )
return V_63 ;
if ( ( V_52 & ~ V_96 ) == ( V_94 & ~ V_96 ) )
V_99 = V_94 - V_52 ;
else
V_99 = V_75 - ( V_52 & V_96 ) ;
V_100 = F_14 ( V_82 ) ;
V_100 += ( V_52 & V_96 ) * 8 ;
if ( ( V_97 + 8 * V_53 ) != V_100 ) {
if ( V_53 ) {
F_42 ( V_2 , V_50 , V_97 ,
V_97 + 8 * V_53 ,
V_98 , V_55 ,
V_56 ) ;
}
V_53 = V_99 ;
V_97 = V_100 ;
V_98 = V_95 ;
} else {
V_53 += V_99 ;
}
V_52 += V_99 ;
V_95 += V_99 * V_92 ;
}
if ( V_53 ) {
F_42 ( V_2 , V_50 , V_97 ,
V_97 + 8 * V_53 ,
V_98 , V_55 , V_56 ) ;
}
return 0 ;
}
static void F_45 ( struct V_7 * V_8 ,
T_1 V_93 , T_1 V_94 ,
struct V_27 * V_41 )
{
unsigned V_12 ;
V_93 >>= V_5 ;
V_94 >>= V_5 ;
for ( V_12 = V_93 ; V_12 <= V_94 ; ++ V_12 )
F_36 ( V_8 -> V_26 [ V_12 ] . V_23 , V_41 , true ) ;
}
static int F_46 ( struct V_1 * V_2 ,
struct V_7 * V_8 ,
struct V_101 * V_102 ,
T_1 V_52 , T_2 V_56 ,
struct V_27 * * V_41 )
{
struct V_28 * V_29 = V_2 -> V_3 . V_61 ;
unsigned V_99 , V_103 , V_79 ;
T_2 V_55 = V_56 ;
struct V_49 V_50 ;
int V_63 ;
if ( ! ( V_102 -> V_55 & V_104 ) )
V_55 &= ~ V_104 ;
if ( ! ( V_102 -> V_55 & V_105 ) )
V_55 &= ~ V_105 ;
F_47 ( V_102 ) ;
V_99 = V_102 -> V_106 . V_107 - V_102 -> V_106 . V_93 + 1 ;
V_103 = ( V_99 >> F_48 ( V_5 , 11 ) ) + 1 ;
V_79 = 64 ;
if ( ( V_55 & V_57 ) && ( V_55 == V_56 ) ) {
V_79 += V_103 * 7 ;
} else if ( V_55 & V_57 ) {
V_79 += V_103 * 4 ;
V_79 += V_99 * 2 ;
} else {
V_79 += V_103 * 10 ;
V_79 += 2 * 10 ;
}
if ( V_79 > 0xfffff )
return - V_80 ;
V_63 = F_32 ( V_29 , NULL , V_79 * 4 , & V_50 ) ;
if ( V_63 )
return V_63 ;
V_50 . V_67 = 0 ;
if ( ! ( V_55 & V_83 ) ) {
unsigned V_12 ;
for ( V_12 = 0 ; V_12 < V_31 ; ++ V_12 ) {
struct V_27 * V_108 = V_8 -> V_34 [ V_12 ] . V_37 ;
F_49 ( & V_50 . V_84 , V_108 ) ;
}
}
V_63 = F_44 ( V_2 , V_8 , & V_50 , V_102 -> V_106 . V_93 ,
V_102 -> V_106 . V_107 + 1 , V_52 + V_102 -> V_109 ,
V_55 , V_56 ) ;
if ( V_63 ) {
F_37 ( V_2 , & V_50 ) ;
return V_63 ;
}
F_33 ( V_2 , & V_50 ) ;
F_34 ( V_50 . V_67 > V_79 ) ;
V_63 = F_35 ( V_2 , 1 , & V_50 , V_68 ) ;
if ( V_63 ) {
F_37 ( V_2 , & V_50 ) ;
return V_63 ;
}
F_45 ( V_8 , V_102 -> V_106 . V_93 ,
V_102 -> V_106 . V_107 + 1 , V_50 . V_41 ) ;
if ( V_41 ) {
F_16 ( V_41 ) ;
* V_41 = F_17 ( V_50 . V_41 ) ;
}
F_37 ( V_2 , & V_50 ) ;
return 0 ;
}
int F_50 ( struct V_1 * V_2 ,
struct V_46 * V_48 ,
struct V_110 * V_111 )
{
struct V_7 * V_8 = V_48 -> V_8 ;
struct V_101 * V_102 ;
T_2 V_55 ;
T_1 V_52 ;
int V_63 ;
if ( V_111 ) {
V_52 = V_111 -> V_93 << V_72 ;
if ( V_111 -> V_112 != V_113 )
V_52 += V_2 -> V_3 . V_114 ;
} else {
V_52 = 0 ;
}
if ( V_52 == V_48 -> V_52 )
return 0 ;
V_55 = F_51 ( V_2 , V_48 -> V_23 -> V_24 . V_115 , V_111 ) ;
F_21 (mapping, &bo_va->mappings, list) {
V_63 = F_46 ( V_2 , V_8 , V_102 , V_52 ,
V_55 , & V_48 -> V_116 ) ;
if ( V_63 )
return V_63 ;
}
V_48 -> V_52 = V_52 ;
F_52 ( & V_8 -> V_117 ) ;
F_53 ( & V_48 -> V_118 ) ;
F_54 ( & V_8 -> V_117 ) ;
return 0 ;
}
int F_55 ( struct V_1 * V_2 ,
struct V_7 * V_8 )
{
struct V_101 * V_102 ;
int V_63 ;
while ( ! F_56 ( & V_8 -> V_119 ) ) {
V_102 = F_57 ( & V_8 -> V_119 ,
struct V_101 , V_11 ) ;
F_58 ( & V_102 -> V_11 ) ;
V_63 = F_46 ( V_2 , V_8 , V_102 , 0 , 0 , NULL ) ;
F_59 ( V_102 ) ;
if ( V_63 )
return V_63 ;
}
return 0 ;
}
int F_60 ( struct V_1 * V_2 ,
struct V_7 * V_8 , struct V_120 * V_84 )
{
struct V_46 * V_48 = NULL ;
int V_63 ;
F_52 ( & V_8 -> V_117 ) ;
while ( ! F_56 ( & V_8 -> V_121 ) ) {
V_48 = F_57 ( & V_8 -> V_121 ,
struct V_46 , V_118 ) ;
F_54 ( & V_8 -> V_117 ) ;
V_63 = F_50 ( V_2 , V_48 , NULL ) ;
if ( V_63 )
return V_63 ;
F_52 ( & V_8 -> V_117 ) ;
}
F_54 ( & V_8 -> V_117 ) ;
if ( V_48 )
F_49 ( V_84 , V_48 -> V_116 ) ;
return 0 ;
}
struct V_46 * F_61 ( struct V_1 * V_2 ,
struct V_7 * V_8 ,
struct V_47 * V_23 )
{
struct V_46 * V_48 ;
V_48 = F_62 ( sizeof( struct V_46 ) , V_122 ) ;
if ( V_48 == NULL ) {
return NULL ;
}
V_48 -> V_8 = V_8 ;
V_48 -> V_23 = V_23 ;
V_48 -> V_52 = 0 ;
V_48 -> V_123 = 1 ;
F_63 ( & V_48 -> V_124 ) ;
F_63 ( & V_48 -> V_125 ) ;
F_63 ( & V_48 -> V_118 ) ;
F_5 ( & V_8 -> V_14 ) ;
F_64 ( & V_48 -> V_124 , & V_23 -> V_126 ) ;
F_7 ( & V_8 -> V_14 ) ;
return V_48 ;
}
int F_65 ( struct V_1 * V_2 ,
struct V_46 * V_48 ,
T_1 V_127 , T_1 V_109 ,
T_1 V_128 , T_2 V_55 )
{
struct V_101 * V_102 ;
struct V_7 * V_8 = V_48 -> V_8 ;
struct V_129 * V_106 ;
unsigned V_130 , V_78 ;
T_1 V_131 ;
int V_63 ;
if ( V_127 & V_132 || V_109 & V_132 ||
V_128 == 0 || V_128 & V_132 ) {
F_38 ( V_48 -> V_23 ) ;
return - V_133 ;
}
V_131 = V_127 + V_128 ;
if ( ( V_127 >= V_131 ) || ( V_109 + V_128 > F_31 ( V_48 -> V_23 ) ) ) {
F_38 ( V_48 -> V_23 ) ;
return - V_133 ;
}
V_130 = V_131 / V_92 ;
if ( V_130 > V_2 -> V_3 . V_4 ) {
F_66 ( V_2 -> V_134 , L_1 ,
V_130 , V_2 -> V_3 . V_4 ) ;
F_38 ( V_48 -> V_23 ) ;
return - V_133 ;
}
F_5 ( & V_8 -> V_14 ) ;
V_127 /= V_92 ;
V_131 /= V_92 ;
V_106 = F_67 ( & V_8 -> V_126 , V_127 , V_131 - 1 ) ;
if ( V_106 ) {
struct V_101 * V_135 ;
V_135 = F_68 ( V_106 , struct V_101 , V_106 ) ;
F_66 ( V_2 -> V_134 , L_2
L_3 , V_48 -> V_23 , V_127 , V_131 ,
V_135 -> V_106 . V_93 , V_135 -> V_106 . V_107 + 1 ) ;
F_38 ( V_48 -> V_23 ) ;
V_63 = - V_133 ;
goto V_136;
}
V_102 = F_69 ( sizeof( * V_102 ) , V_122 ) ;
if ( ! V_102 ) {
F_38 ( V_48 -> V_23 ) ;
V_63 = - V_80 ;
goto V_136;
}
F_63 ( & V_102 -> V_11 ) ;
V_102 -> V_106 . V_93 = V_127 ;
V_102 -> V_106 . V_107 = V_131 - 1 ;
V_102 -> V_109 = V_109 ;
V_102 -> V_55 = V_55 ;
F_8 ( & V_102 -> V_11 , & V_48 -> V_125 ) ;
F_70 ( & V_102 -> V_106 , & V_8 -> V_126 ) ;
F_71 ( V_48 , V_102 ) ;
V_48 -> V_52 = 0 ;
V_127 >>= V_5 ;
V_131 >>= V_5 ;
F_72 ( V_131 >= F_1 ( V_2 ) ) ;
if ( V_131 > V_8 -> V_15 )
V_8 -> V_15 = V_131 ;
F_38 ( V_48 -> V_23 ) ;
for ( V_78 = V_127 ; V_78 <= V_131 ; ++ V_78 ) {
struct V_47 * V_82 ;
if ( V_8 -> V_26 [ V_78 ] . V_23 )
continue;
F_7 ( & V_8 -> V_14 ) ;
V_63 = F_73 ( V_2 , V_75 * 8 ,
V_92 , true ,
V_19 , 0 , NULL , & V_82 ) ;
if ( V_63 )
goto V_69;
V_63 = F_27 ( V_2 , V_82 ) ;
if ( V_63 ) {
F_74 ( & V_82 ) ;
goto V_69;
}
F_5 ( & V_8 -> V_14 ) ;
if ( V_8 -> V_26 [ V_78 ] . V_23 ) {
F_7 ( & V_8 -> V_14 ) ;
F_74 ( & V_82 ) ;
F_5 ( & V_8 -> V_14 ) ;
continue;
}
V_8 -> V_26 [ V_78 ] . V_52 = 0 ;
V_8 -> V_26 [ V_78 ] . V_23 = V_82 ;
}
F_7 ( & V_8 -> V_14 ) ;
return 0 ;
V_69:
F_5 ( & V_8 -> V_14 ) ;
F_58 ( & V_102 -> V_11 ) ;
F_75 ( & V_102 -> V_106 , & V_8 -> V_126 ) ;
F_76 ( V_48 , V_102 ) ;
F_59 ( V_102 ) ;
V_136:
F_7 ( & V_8 -> V_14 ) ;
return V_63 ;
}
int F_77 ( struct V_1 * V_2 ,
struct V_46 * V_48 ,
T_1 V_127 )
{
struct V_101 * V_102 ;
struct V_7 * V_8 = V_48 -> V_8 ;
V_127 /= V_92 ;
F_21 (mapping, &bo_va->mappings, list) {
if ( V_102 -> V_106 . V_93 == V_127 )
break;
}
if ( & V_102 -> V_11 == & V_48 -> V_125 ) {
F_38 ( V_48 -> V_23 ) ;
return - V_137 ;
}
F_5 ( & V_8 -> V_14 ) ;
F_58 ( & V_102 -> V_11 ) ;
F_75 ( & V_102 -> V_106 , & V_8 -> V_126 ) ;
F_76 ( V_48 , V_102 ) ;
if ( V_48 -> V_52 ) {
F_8 ( & V_102 -> V_11 , & V_8 -> V_119 ) ;
} else {
F_59 ( V_102 ) ;
}
F_7 ( & V_8 -> V_14 ) ;
F_38 ( V_48 -> V_23 ) ;
return 0 ;
}
void F_78 ( struct V_1 * V_2 ,
struct V_46 * V_48 )
{
struct V_101 * V_102 , * V_138 ;
struct V_7 * V_8 = V_48 -> V_8 ;
F_58 ( & V_48 -> V_124 ) ;
F_5 ( & V_8 -> V_14 ) ;
F_52 ( & V_8 -> V_117 ) ;
F_58 ( & V_48 -> V_118 ) ;
F_54 ( & V_8 -> V_117 ) ;
F_79 (mapping, next, &bo_va->mappings, list) {
F_58 ( & V_102 -> V_11 ) ;
F_75 ( & V_102 -> V_106 , & V_8 -> V_126 ) ;
F_76 ( V_48 , V_102 ) ;
if ( V_48 -> V_52 )
F_8 ( & V_102 -> V_11 , & V_8 -> V_119 ) ;
else
F_59 ( V_102 ) ;
}
F_16 ( & V_48 -> V_116 ) ;
F_59 ( V_48 ) ;
F_7 ( & V_8 -> V_14 ) ;
}
void F_80 ( struct V_1 * V_2 ,
struct V_47 * V_23 )
{
struct V_46 * V_48 ;
F_21 (bo_va, &bo->va, bo_list) {
if ( V_48 -> V_52 ) {
F_52 ( & V_48 -> V_8 -> V_117 ) ;
F_58 ( & V_48 -> V_118 ) ;
F_8 ( & V_48 -> V_118 , & V_48 -> V_8 -> V_121 ) ;
F_54 ( & V_48 -> V_8 -> V_117 ) ;
}
}
}
int F_81 ( struct V_1 * V_2 , struct V_7 * V_8 )
{
const unsigned V_139 = F_48 ( V_140 ,
V_75 * 8 ) ;
unsigned V_141 , V_142 , V_143 ;
int V_12 , V_63 ;
for ( V_12 = 0 ; V_12 < V_31 ; ++ V_12 ) {
V_8 -> V_34 [ V_12 ] . V_36 = 0 ;
V_8 -> V_34 [ V_12 ] . V_44 = NULL ;
V_8 -> V_34 [ V_12 ] . V_37 = NULL ;
}
F_82 ( & V_8 -> V_14 ) ;
V_8 -> V_126 = V_144 ;
F_83 ( & V_8 -> V_117 ) ;
F_63 ( & V_8 -> V_121 ) ;
F_63 ( & V_8 -> V_119 ) ;
V_141 = F_2 ( V_2 ) ;
V_142 = F_1 ( V_2 ) ;
V_143 = V_142 * sizeof( struct V_145 ) ;
V_8 -> V_26 = F_62 ( V_143 , V_122 ) ;
if ( V_8 -> V_26 == NULL ) {
F_84 ( L_4 ) ;
return - V_80 ;
}
V_63 = F_73 ( V_2 , V_141 , V_139 , true ,
V_19 , 0 ,
NULL , & V_8 -> V_17 ) ;
if ( V_63 )
return V_63 ;
V_63 = F_27 ( V_2 , V_8 -> V_17 ) ;
if ( V_63 ) {
F_74 ( & V_8 -> V_17 ) ;
V_8 -> V_17 = NULL ;
return V_63 ;
}
return 0 ;
}
void F_85 ( struct V_1 * V_2 , struct V_7 * V_8 )
{
struct V_101 * V_102 , * V_135 ;
int V_12 ;
if ( ! F_86 ( & V_8 -> V_126 ) ) {
F_66 ( V_2 -> V_134 , L_5 ) ;
}
F_87 (mapping, tmp, &vm->va, it.rb) {
F_58 ( & V_102 -> V_11 ) ;
F_75 ( & V_102 -> V_106 , & V_8 -> V_126 ) ;
F_59 ( V_102 ) ;
}
F_79 (mapping, tmp, &vm->freed, list) {
F_58 ( & V_102 -> V_11 ) ;
F_59 ( V_102 ) ;
}
for ( V_12 = 0 ; V_12 < F_1 ( V_2 ) ; V_12 ++ )
F_74 ( & V_8 -> V_26 [ V_12 ] . V_23 ) ;
F_59 ( V_8 -> V_26 ) ;
F_74 ( & V_8 -> V_17 ) ;
for ( V_12 = 0 ; V_12 < V_31 ; ++ V_12 ) {
F_16 ( & V_8 -> V_34 [ V_12 ] . V_44 ) ;
F_16 ( & V_8 -> V_34 [ V_12 ] . V_37 ) ;
}
F_88 ( & V_8 -> V_14 ) ;
}
