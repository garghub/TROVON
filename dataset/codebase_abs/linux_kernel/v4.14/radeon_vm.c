static unsigned F_1 ( struct V_1 * V_2 )
{
return V_2 -> V_3 . V_4 >> V_5 ;
}
static unsigned F_2 ( struct V_1 * V_2 )
{
return F_3 ( F_1 ( V_2 ) * 8 ) ;
}
int F_4 ( struct V_1 * V_2 )
{
int V_6 ;
if ( ! V_2 -> V_3 . V_7 ) {
V_6 = F_5 ( V_2 ) ;
if ( V_6 )
return V_6 ;
V_2 -> V_3 . V_7 = true ;
}
return 0 ;
}
void F_6 ( struct V_1 * V_2 )
{
int V_8 ;
if ( ! V_2 -> V_3 . V_7 )
return;
for ( V_8 = 0 ; V_8 < V_9 ; ++ V_8 )
F_7 ( & V_2 -> V_3 . V_10 [ V_8 ] ) ;
F_8 ( V_2 ) ;
V_2 -> V_3 . V_7 = false ;
}
struct V_11 * F_9 ( struct V_1 * V_2 ,
struct V_12 * V_13 ,
struct V_14 * V_15 )
{
struct V_11 * V_16 ;
unsigned V_8 , V_17 ;
V_16 = F_10 ( V_13 -> V_18 + 2 ,
sizeof( struct V_11 ) , V_19 ) ;
if ( ! V_16 )
return NULL ;
V_16 [ 0 ] . V_20 = V_13 -> V_21 ;
V_16 [ 0 ] . V_22 = V_23 ;
V_16 [ 0 ] . V_24 = V_23 ;
V_16 [ 0 ] . V_25 . V_26 = & V_13 -> V_21 -> V_27 ;
V_16 [ 0 ] . V_25 . V_28 = true ;
V_16 [ 0 ] . V_29 = 0 ;
F_11 ( & V_16 [ 0 ] . V_25 . V_15 , V_15 ) ;
for ( V_8 = 0 , V_17 = 1 ; V_8 <= V_13 -> V_18 ; V_8 ++ ) {
if ( ! V_13 -> V_30 [ V_8 ] . V_26 )
continue;
V_16 [ V_17 ] . V_20 = V_13 -> V_30 [ V_8 ] . V_26 ;
V_16 [ V_17 ] . V_22 = V_23 ;
V_16 [ V_17 ] . V_24 = V_23 ;
V_16 [ V_17 ] . V_25 . V_26 = & V_16 [ V_17 ] . V_20 -> V_27 ;
V_16 [ V_17 ] . V_25 . V_28 = true ;
V_16 [ V_17 ] . V_29 = 0 ;
F_11 ( & V_16 [ V_17 ++ ] . V_25 . V_15 , V_15 ) ;
}
return V_16 ;
}
struct V_31 * F_12 ( struct V_1 * V_2 ,
struct V_12 * V_13 , int V_32 )
{
struct V_31 * V_33 [ V_34 ] = {} ;
struct V_35 * V_36 = & V_13 -> V_37 [ V_32 ] ;
unsigned V_38 [ 2 ] = {} ;
unsigned V_8 ;
if ( V_36 -> V_39 && V_36 -> V_40 &&
V_36 -> V_40 == V_2 -> V_3 . V_10 [ V_36 -> V_39 ] )
return NULL ;
V_36 -> V_41 = ~ 0ll ;
for ( V_8 = 1 ; V_8 < V_2 -> V_3 . V_42 ; ++ V_8 ) {
struct V_31 * V_43 = V_2 -> V_3 . V_10 [ V_8 ] ;
if ( V_43 == NULL ) {
V_36 -> V_39 = V_8 ;
F_13 ( V_8 , V_32 ) ;
return NULL ;
}
if ( F_14 ( V_43 , V_33 [ V_43 -> V_32 ] ) ) {
V_33 [ V_43 -> V_32 ] = V_43 ;
V_38 [ V_43 -> V_32 == V_32 ? 0 : 1 ] = V_8 ;
}
}
for ( V_8 = 0 ; V_8 < 2 ; ++ V_8 ) {
if ( V_38 [ V_8 ] ) {
V_36 -> V_39 = V_38 [ V_8 ] ;
F_13 ( V_38 [ V_8 ] , V_32 ) ;
return V_2 -> V_3 . V_10 [ V_38 [ V_8 ] ] ;
}
}
F_15 () ;
return NULL ;
}
void F_16 ( struct V_1 * V_2 ,
struct V_12 * V_13 ,
int V_32 , struct V_31 * V_44 )
{
T_1 V_45 = F_17 ( V_13 -> V_21 ) ;
struct V_35 * V_36 = & V_13 -> V_37 [ V_32 ] ;
if ( V_45 != V_36 -> V_41 || ! V_36 -> V_46 ||
F_14 ( V_36 -> V_46 , V_44 ) ) {
F_18 ( V_45 , V_32 , V_13 -> V_37 [ V_32 ] . V_39 ) ;
F_7 ( & V_36 -> V_46 ) ;
V_36 -> V_46 = F_19 ( V_44 ) ;
V_36 -> V_41 = V_45 ;
F_20 ( V_2 , & V_2 -> V_32 [ V_32 ] ,
V_36 -> V_39 , V_36 -> V_41 ) ;
}
}
void F_21 ( struct V_1 * V_2 ,
struct V_12 * V_13 ,
struct V_31 * V_43 )
{
unsigned V_36 = V_13 -> V_37 [ V_43 -> V_32 ] . V_39 ;
F_7 ( & V_2 -> V_3 . V_10 [ V_36 ] ) ;
V_2 -> V_3 . V_10 [ V_36 ] = F_19 ( V_43 ) ;
F_7 ( & V_13 -> V_37 [ V_43 -> V_32 ] . V_40 ) ;
V_13 -> V_37 [ V_43 -> V_32 ] . V_40 = F_19 ( V_43 ) ;
}
struct V_47 * F_22 ( struct V_12 * V_13 ,
struct V_48 * V_26 )
{
struct V_47 * V_49 ;
F_23 (bo_va, &bo->va, bo_list) {
if ( V_49 -> V_13 == V_13 ) {
return V_49 ;
}
}
return NULL ;
}
struct V_47 * F_24 ( struct V_1 * V_2 ,
struct V_12 * V_13 ,
struct V_48 * V_26 )
{
struct V_47 * V_49 ;
V_49 = F_25 ( sizeof( struct V_47 ) , V_19 ) ;
if ( V_49 == NULL ) {
return NULL ;
}
V_49 -> V_13 = V_13 ;
V_49 -> V_26 = V_26 ;
V_49 -> V_50 . V_51 = 0 ;
V_49 -> V_50 . V_52 = 0 ;
V_49 -> V_53 = 0 ;
V_49 -> V_54 = 1 ;
F_26 ( & V_49 -> V_55 ) ;
F_26 ( & V_49 -> V_56 ) ;
F_27 ( & V_13 -> V_57 ) ;
F_28 ( & V_49 -> V_55 , & V_26 -> V_58 ) ;
F_29 ( & V_13 -> V_57 ) ;
return V_49 ;
}
static void F_30 ( struct V_1 * V_2 ,
struct V_59 * V_60 ,
T_1 V_61 ,
T_1 V_62 , unsigned V_63 ,
T_2 V_64 , T_2 V_53 )
{
F_31 ( V_61 , V_62 , V_63 , V_64 , V_53 ) ;
if ( ( V_53 & V_65 ) == V_65 ) {
T_1 V_66 = V_2 -> V_67 . V_68 + ( V_62 >> 12 ) * 8 ;
F_32 ( V_2 , V_60 , V_61 , V_66 , V_63 ) ;
} else if ( ( V_53 & V_69 ) || ( V_63 < 3 ) ) {
F_33 ( V_2 , V_60 , V_61 , V_62 ,
V_63 , V_64 , V_53 ) ;
} else {
F_34 ( V_2 , V_60 , V_61 , V_62 ,
V_63 , V_64 , V_53 ) ;
}
}
static int F_35 ( struct V_1 * V_2 ,
struct V_48 * V_26 )
{
struct V_59 V_60 ;
unsigned V_70 ;
T_1 V_62 ;
int V_6 ;
V_6 = F_36 ( V_26 , false ) ;
if ( V_6 )
return V_6 ;
V_6 = F_37 ( & V_26 -> V_27 , & V_26 -> V_71 , true , false ) ;
if ( V_6 )
goto V_72;
V_62 = F_17 ( V_26 ) ;
V_70 = F_38 ( V_26 ) / 8 ;
V_6 = F_39 ( V_2 , V_73 , & V_60 , NULL , 256 ) ;
if ( V_6 )
goto V_72;
V_60 . V_74 = 0 ;
F_30 ( V_2 , & V_60 , V_62 , 0 , V_70 , 0 , 0 ) ;
F_40 ( V_2 , & V_60 ) ;
F_41 ( V_60 . V_74 > 64 ) ;
V_6 = F_42 ( V_2 , & V_60 , NULL , false ) ;
if ( V_6 )
goto V_75;
V_60 . V_43 -> V_76 = true ;
F_43 ( V_26 , V_60 . V_43 , false ) ;
V_75:
F_44 ( V_2 , & V_60 ) ;
V_72:
F_45 ( V_26 ) ;
return V_6 ;
}
int F_46 ( struct V_1 * V_2 ,
struct V_47 * V_49 ,
T_1 V_77 ,
T_2 V_53 )
{
T_1 V_78 = F_38 ( V_49 -> V_26 ) ;
struct V_12 * V_13 = V_49 -> V_13 ;
unsigned V_79 , V_80 ;
T_1 V_81 ;
int V_6 ;
if ( V_77 ) {
V_81 = V_77 + V_78 - 1 ;
if ( V_77 >= V_81 ) {
V_6 = - V_82 ;
goto V_72;
}
V_79 = V_81 / V_83 ;
if ( V_79 >= V_2 -> V_3 . V_4 ) {
F_47 ( V_2 -> V_84 , L_1 ,
V_79 , V_2 -> V_3 . V_4 ) ;
V_6 = - V_82 ;
goto V_72;
}
} else {
V_81 = V_79 = 0 ;
}
F_27 ( & V_13 -> V_57 ) ;
V_77 /= V_83 ;
V_81 /= V_83 ;
if ( V_77 || V_81 ) {
struct V_85 * V_50 ;
V_50 = F_48 ( & V_13 -> V_58 , V_77 , V_81 ) ;
if ( V_50 && V_50 != & V_49 -> V_50 ) {
struct V_47 * V_86 ;
V_86 = F_49 ( V_50 , struct V_47 , V_50 ) ;
F_47 ( V_2 -> V_84 , L_2
L_3 , V_49 -> V_26 ,
V_77 , V_86 -> V_26 , V_86 -> V_50 . V_51 , V_86 -> V_50 . V_52 ) ;
F_29 ( & V_13 -> V_57 ) ;
V_6 = - V_82 ;
goto V_72;
}
}
if ( V_49 -> V_50 . V_51 || V_49 -> V_50 . V_52 ) {
struct V_47 * V_86 ;
V_86 = F_25 ( sizeof( struct V_47 ) , V_19 ) ;
if ( ! V_86 ) {
F_29 ( & V_13 -> V_57 ) ;
V_6 = - V_87 ;
goto V_72;
}
V_86 -> V_50 . V_51 = V_49 -> V_50 . V_51 ;
V_86 -> V_50 . V_52 = V_49 -> V_50 . V_52 ;
V_86 -> V_13 = V_13 ;
V_86 -> V_26 = F_50 ( V_49 -> V_26 ) ;
F_51 ( & V_49 -> V_50 , & V_13 -> V_58 ) ;
F_52 ( & V_13 -> V_88 ) ;
V_49 -> V_50 . V_51 = 0 ;
V_49 -> V_50 . V_52 = 0 ;
F_53 ( & V_49 -> V_56 ) ;
F_11 ( & V_86 -> V_56 , & V_13 -> V_89 ) ;
F_54 ( & V_13 -> V_88 ) ;
}
if ( V_77 || V_81 ) {
F_52 ( & V_13 -> V_88 ) ;
V_49 -> V_50 . V_51 = V_77 ;
V_49 -> V_50 . V_52 = V_81 ;
F_11 ( & V_49 -> V_56 , & V_13 -> V_90 ) ;
F_54 ( & V_13 -> V_88 ) ;
F_55 ( & V_49 -> V_50 , & V_13 -> V_58 ) ;
}
V_49 -> V_53 = V_53 ;
V_77 >>= V_5 ;
V_81 >>= V_5 ;
F_56 ( V_81 >= F_1 ( V_2 ) ) ;
if ( V_81 > V_13 -> V_18 )
V_13 -> V_18 = V_81 ;
F_45 ( V_49 -> V_26 ) ;
for ( V_80 = V_77 ; V_80 <= V_81 ; ++ V_80 ) {
struct V_48 * V_91 ;
if ( V_13 -> V_30 [ V_80 ] . V_26 )
continue;
F_29 ( & V_13 -> V_57 ) ;
V_6 = F_57 ( V_2 , V_92 * 8 ,
V_83 , true ,
V_23 , 0 ,
NULL , NULL , & V_91 ) ;
if ( V_6 )
return V_6 ;
V_6 = F_35 ( V_2 , V_91 ) ;
if ( V_6 ) {
F_58 ( & V_91 ) ;
return V_6 ;
}
F_27 ( & V_13 -> V_57 ) ;
if ( V_13 -> V_30 [ V_80 ] . V_26 ) {
F_29 ( & V_13 -> V_57 ) ;
F_58 ( & V_91 ) ;
F_27 ( & V_13 -> V_57 ) ;
continue;
}
V_13 -> V_30 [ V_80 ] . V_62 = 0 ;
V_13 -> V_30 [ V_80 ] . V_26 = V_91 ;
}
F_29 ( & V_13 -> V_57 ) ;
return 0 ;
V_72:
F_45 ( V_49 -> V_26 ) ;
return V_6 ;
}
T_1 F_59 ( struct V_1 * V_2 , T_1 V_62 )
{
T_1 V_93 ;
V_93 = V_2 -> V_67 . V_94 [ V_62 >> V_95 ] ;
V_93 &= ~ V_96 ;
return V_93 ;
}
static T_2 F_60 ( T_2 V_53 )
{
T_2 V_97 = 0 ;
V_97 |= ( V_53 & V_98 ) ? V_99 : 0 ;
V_97 |= ( V_53 & V_100 ) ? V_101 : 0 ;
V_97 |= ( V_53 & V_102 ) ? V_103 : 0 ;
if ( V_53 & V_104 ) {
V_97 |= V_69 ;
V_97 |= ( V_53 & V_105 ) ? V_106 : 0 ;
}
return V_97 ;
}
int F_61 ( struct V_1 * V_2 ,
struct V_12 * V_13 )
{
struct V_48 * V_107 = V_13 -> V_21 ;
T_1 V_45 = F_17 ( V_107 ) ;
T_2 V_64 = V_92 * 8 ;
T_1 V_108 = ~ 0 , V_109 = ~ 0 ;
unsigned V_63 = 0 , V_80 , V_110 ;
struct V_59 V_60 ;
int V_6 ;
V_110 = 64 ;
V_110 += V_13 -> V_18 * 6 ;
if ( V_110 > 0xfffff )
return - V_87 ;
V_6 = F_39 ( V_2 , V_73 , & V_60 , NULL , V_110 * 4 ) ;
if ( V_6 )
return V_6 ;
V_60 . V_74 = 0 ;
for ( V_80 = 0 ; V_80 <= V_13 -> V_18 ; ++ V_80 ) {
struct V_48 * V_26 = V_13 -> V_30 [ V_80 ] . V_26 ;
T_1 V_111 , V_91 ;
if ( V_26 == NULL )
continue;
V_91 = F_17 ( V_26 ) ;
if ( V_13 -> V_30 [ V_80 ] . V_62 == V_91 )
continue;
V_13 -> V_30 [ V_80 ] . V_62 = V_91 ;
V_111 = V_45 + V_80 * 8 ;
if ( ( ( V_108 + 8 * V_63 ) != V_111 ) ||
( ( V_109 + V_64 * V_63 ) != V_91 ) ) {
if ( V_63 ) {
F_30 ( V_2 , & V_60 , V_108 ,
V_109 , V_63 , V_64 ,
V_99 ) ;
}
V_63 = 1 ;
V_108 = V_111 ;
V_109 = V_91 ;
} else {
++ V_63 ;
}
}
if ( V_63 )
F_30 ( V_2 , & V_60 , V_108 , V_109 , V_63 ,
V_64 , V_99 ) ;
if ( V_60 . V_74 != 0 ) {
F_40 ( V_2 , & V_60 ) ;
F_62 ( V_2 , & V_60 . V_112 , V_107 -> V_27 . V_113 , true ) ;
F_41 ( V_60 . V_74 > V_110 ) ;
V_6 = F_42 ( V_2 , & V_60 , NULL , false ) ;
if ( V_6 ) {
F_44 ( V_2 , & V_60 ) ;
return V_6 ;
}
V_60 . V_43 -> V_76 = true ;
F_43 ( V_107 , V_60 . V_43 , false ) ;
}
F_44 ( V_2 , & V_60 ) ;
return 0 ;
}
static void F_63 ( struct V_1 * V_2 ,
struct V_59 * V_60 ,
T_1 V_114 , T_1 V_115 ,
T_1 V_62 , T_2 V_53 )
{
T_1 V_116 = ( ( V_2 -> V_117 == V_118 ) ||
( V_2 -> V_117 == V_119 ) ) ?
V_120 : V_121 ;
T_1 V_122 = ( ( V_2 -> V_117 == V_118 ) ||
( V_2 -> V_117 == V_119 ) ) ? 0x200 : 0x80 ;
T_1 V_123 = F_64 ( V_114 , V_122 ) ;
T_1 V_124 = V_115 & ~ ( V_122 - 1 ) ;
unsigned V_63 ;
if ( ( V_53 & V_69 ) || ! ( V_53 & V_99 ) ||
( V_123 >= V_124 ) ) {
V_63 = ( V_115 - V_114 ) / 8 ;
F_30 ( V_2 , V_60 , V_114 , V_62 , V_63 ,
V_83 , V_53 ) ;
return;
}
if ( V_114 != V_123 ) {
V_63 = ( V_123 - V_114 ) / 8 ;
F_30 ( V_2 , V_60 , V_114 , V_62 , V_63 ,
V_83 , V_53 ) ;
V_62 += V_83 * V_63 ;
}
V_63 = ( V_124 - V_123 ) / 8 ;
F_30 ( V_2 , V_60 , V_123 , V_62 , V_63 ,
V_83 , V_53 | V_116 ) ;
if ( V_124 != V_115 ) {
V_62 += V_83 * V_63 ;
V_63 = ( V_115 - V_124 ) / 8 ;
F_30 ( V_2 , V_60 , V_124 , V_62 , V_63 ,
V_83 , V_53 ) ;
}
}
static int F_65 ( struct V_1 * V_2 ,
struct V_12 * V_13 ,
struct V_59 * V_60 ,
T_1 V_51 , T_1 V_125 ,
T_1 V_126 , T_2 V_53 )
{
T_1 V_127 = V_92 - 1 ;
T_1 V_128 = ~ 0 , V_129 = ~ 0 ;
unsigned V_63 = 0 ;
T_1 V_62 ;
for ( V_62 = V_51 ; V_62 < V_125 ; ) {
T_1 V_80 = V_62 >> V_5 ;
struct V_48 * V_91 = V_13 -> V_30 [ V_80 ] . V_26 ;
unsigned V_130 ;
T_1 V_131 ;
int V_6 ;
F_62 ( V_2 , & V_60 -> V_112 , V_91 -> V_27 . V_113 , true ) ;
V_6 = F_66 ( V_91 -> V_27 . V_113 ) ;
if ( V_6 )
return V_6 ;
if ( ( V_62 & ~ V_127 ) == ( V_125 & ~ V_127 ) )
V_130 = V_125 - V_62 ;
else
V_130 = V_92 - ( V_62 & V_127 ) ;
V_131 = F_17 ( V_91 ) ;
V_131 += ( V_62 & V_127 ) * 8 ;
if ( ( V_128 + 8 * V_63 ) != V_131 ) {
if ( V_63 ) {
F_63 ( V_2 , V_60 , V_128 ,
V_128 + 8 * V_63 ,
V_129 , V_53 ) ;
}
V_63 = V_130 ;
V_128 = V_131 ;
V_129 = V_126 ;
} else {
V_63 += V_130 ;
}
V_62 += V_130 ;
V_126 += V_130 * V_83 ;
}
if ( V_63 ) {
F_63 ( V_2 , V_60 , V_128 ,
V_128 + 8 * V_63 ,
V_129 , V_53 ) ;
}
return 0 ;
}
static void F_67 ( struct V_12 * V_13 ,
T_1 V_51 , T_1 V_125 ,
struct V_31 * V_43 )
{
unsigned V_8 ;
V_51 >>= V_5 ;
V_125 = ( V_125 - 1 ) >> V_5 ;
for ( V_8 = V_51 ; V_8 <= V_125 ; ++ V_8 )
F_43 ( V_13 -> V_30 [ V_8 ] . V_26 , V_43 , true ) ;
}
int F_68 ( struct V_1 * V_2 ,
struct V_47 * V_49 ,
struct V_132 * V_133 )
{
struct V_12 * V_13 = V_49 -> V_13 ;
struct V_59 V_60 ;
unsigned V_130 , V_134 , V_110 ;
T_1 V_62 ;
T_2 V_53 ;
int V_6 ;
if ( ! V_49 -> V_50 . V_51 ) {
F_47 ( V_2 -> V_84 , L_4 ,
V_49 -> V_26 , V_13 ) ;
return - V_82 ;
}
F_52 ( & V_13 -> V_88 ) ;
if ( V_133 ) {
if ( F_69 ( & V_49 -> V_56 ) ) {
F_54 ( & V_13 -> V_88 ) ;
return 0 ;
}
F_53 ( & V_49 -> V_56 ) ;
} else {
F_70 ( & V_49 -> V_56 ) ;
F_11 ( & V_49 -> V_56 , & V_13 -> V_90 ) ;
}
F_54 ( & V_13 -> V_88 ) ;
V_49 -> V_53 &= ~ V_98 ;
V_49 -> V_53 &= ~ V_104 ;
V_49 -> V_53 &= ~ V_105 ;
if ( V_49 -> V_26 && F_71 ( V_49 -> V_26 -> V_27 . V_135 ) )
V_49 -> V_53 &= ~ V_102 ;
if ( V_133 ) {
V_62 = V_133 -> V_51 << V_136 ;
if ( V_133 -> V_137 != V_138 ) {
V_49 -> V_53 |= V_98 ;
}
if ( V_133 -> V_137 == V_139 ) {
V_49 -> V_53 |= V_104 ;
if ( ! ( V_49 -> V_26 -> V_53 & ( V_140 | V_141 ) ) )
V_49 -> V_53 |= V_105 ;
} else {
V_62 += V_2 -> V_3 . V_142 ;
}
} else {
V_62 = 0 ;
}
F_72 ( V_49 ) ;
V_130 = V_49 -> V_50 . V_52 - V_49 -> V_50 . V_51 + 1 ;
V_134 = ( V_130 >> F_73 ( V_5 , 11 ) ) + 1 ;
V_110 = 64 ;
V_53 = F_60 ( V_49 -> V_53 ) ;
if ( ( V_53 & V_65 ) == V_65 ) {
V_110 += V_134 * 7 ;
} else if ( V_53 & V_69 ) {
V_110 += V_134 * 4 ;
V_110 += V_130 * 2 ;
} else {
V_110 += V_134 * 10 ;
V_110 += 2 * 10 ;
}
if ( V_110 > 0xfffff )
return - V_87 ;
V_6 = F_39 ( V_2 , V_73 , & V_60 , NULL , V_110 * 4 ) ;
if ( V_6 )
return V_6 ;
V_60 . V_74 = 0 ;
if ( ! ( V_49 -> V_53 & V_98 ) ) {
unsigned V_8 ;
for ( V_8 = 0 ; V_8 < V_34 ; ++ V_8 )
F_74 ( & V_60 . V_112 , V_13 -> V_37 [ V_8 ] . V_40 ) ;
}
V_6 = F_65 ( V_2 , V_13 , & V_60 , V_49 -> V_50 . V_51 ,
V_49 -> V_50 . V_52 + 1 , V_62 ,
F_60 ( V_49 -> V_53 ) ) ;
if ( V_6 ) {
F_44 ( V_2 , & V_60 ) ;
return V_6 ;
}
F_40 ( V_2 , & V_60 ) ;
F_41 ( V_60 . V_74 > V_110 ) ;
V_6 = F_42 ( V_2 , & V_60 , NULL , false ) ;
if ( V_6 ) {
F_44 ( V_2 , & V_60 ) ;
return V_6 ;
}
V_60 . V_43 -> V_76 = true ;
F_67 ( V_13 , V_49 -> V_50 . V_51 , V_49 -> V_50 . V_52 + 1 , V_60 . V_43 ) ;
F_7 ( & V_49 -> V_143 ) ;
V_49 -> V_143 = F_19 ( V_60 . V_43 ) ;
F_44 ( V_2 , & V_60 ) ;
return 0 ;
}
int F_75 ( struct V_1 * V_2 ,
struct V_12 * V_13 )
{
struct V_47 * V_49 ;
int V_6 = 0 ;
F_52 ( & V_13 -> V_88 ) ;
while ( ! F_69 ( & V_13 -> V_89 ) ) {
V_49 = F_76 ( & V_13 -> V_89 ,
struct V_47 , V_56 ) ;
F_54 ( & V_13 -> V_88 ) ;
V_6 = F_68 ( V_2 , V_49 , NULL ) ;
F_58 ( & V_49 -> V_26 ) ;
F_7 ( & V_49 -> V_143 ) ;
F_52 ( & V_13 -> V_88 ) ;
F_70 ( & V_49 -> V_56 ) ;
F_77 ( V_49 ) ;
if ( V_6 )
break;
}
F_54 ( & V_13 -> V_88 ) ;
return V_6 ;
}
int F_78 ( struct V_1 * V_2 ,
struct V_12 * V_13 )
{
struct V_47 * V_49 ;
int V_6 ;
F_52 ( & V_13 -> V_88 ) ;
while ( ! F_69 ( & V_13 -> V_144 ) ) {
V_49 = F_76 ( & V_13 -> V_144 ,
struct V_47 , V_56 ) ;
F_54 ( & V_13 -> V_88 ) ;
V_6 = F_68 ( V_2 , V_49 , NULL ) ;
if ( V_6 )
return V_6 ;
F_52 ( & V_13 -> V_88 ) ;
}
F_54 ( & V_13 -> V_88 ) ;
return 0 ;
}
void F_79 ( struct V_1 * V_2 ,
struct V_47 * V_49 )
{
struct V_12 * V_13 = V_49 -> V_13 ;
F_70 ( & V_49 -> V_55 ) ;
F_27 ( & V_13 -> V_57 ) ;
if ( V_49 -> V_50 . V_51 || V_49 -> V_50 . V_52 )
F_51 ( & V_49 -> V_50 , & V_13 -> V_58 ) ;
F_52 ( & V_13 -> V_88 ) ;
F_70 ( & V_49 -> V_56 ) ;
if ( V_49 -> V_50 . V_51 || V_49 -> V_50 . V_52 ) {
V_49 -> V_26 = F_50 ( V_49 -> V_26 ) ;
F_11 ( & V_49 -> V_56 , & V_13 -> V_89 ) ;
} else {
F_7 ( & V_49 -> V_143 ) ;
F_77 ( V_49 ) ;
}
F_54 ( & V_13 -> V_88 ) ;
F_29 ( & V_13 -> V_57 ) ;
}
void F_80 ( struct V_1 * V_2 ,
struct V_48 * V_26 )
{
struct V_47 * V_49 ;
F_23 (bo_va, &bo->va, bo_list) {
F_52 ( & V_49 -> V_13 -> V_88 ) ;
if ( F_69 ( & V_49 -> V_56 ) &&
( V_49 -> V_50 . V_51 || V_49 -> V_50 . V_52 ) )
F_11 ( & V_49 -> V_56 , & V_49 -> V_13 -> V_144 ) ;
F_54 ( & V_49 -> V_13 -> V_88 ) ;
}
}
int F_81 ( struct V_1 * V_2 , struct V_12 * V_13 )
{
const unsigned V_145 = F_73 ( V_146 ,
V_92 * 8 ) ;
unsigned V_147 , V_148 , V_149 ;
int V_8 , V_6 ;
V_13 -> V_150 = NULL ;
for ( V_8 = 0 ; V_8 < V_34 ; ++ V_8 ) {
V_13 -> V_37 [ V_8 ] . V_39 = 0 ;
V_13 -> V_37 [ V_8 ] . V_46 = NULL ;
V_13 -> V_37 [ V_8 ] . V_40 = NULL ;
}
F_82 ( & V_13 -> V_57 ) ;
V_13 -> V_58 = V_151 ;
F_83 ( & V_13 -> V_88 ) ;
F_26 ( & V_13 -> V_144 ) ;
F_26 ( & V_13 -> V_89 ) ;
F_26 ( & V_13 -> V_90 ) ;
V_147 = F_2 ( V_2 ) ;
V_148 = F_1 ( V_2 ) ;
V_149 = V_148 * sizeof( struct V_152 ) ;
V_13 -> V_30 = F_25 ( V_149 , V_19 ) ;
if ( V_13 -> V_30 == NULL ) {
F_84 ( L_5 ) ;
return - V_87 ;
}
V_6 = F_57 ( V_2 , V_147 , V_145 , true ,
V_23 , 0 , NULL ,
NULL , & V_13 -> V_21 ) ;
if ( V_6 )
return V_6 ;
V_6 = F_35 ( V_2 , V_13 -> V_21 ) ;
if ( V_6 ) {
F_58 ( & V_13 -> V_21 ) ;
V_13 -> V_21 = NULL ;
return V_6 ;
}
return 0 ;
}
void F_85 ( struct V_1 * V_2 , struct V_12 * V_13 )
{
struct V_47 * V_49 , * V_86 ;
int V_8 , V_6 ;
if ( ! F_86 ( & V_13 -> V_58 . V_153 ) ) {
F_47 ( V_2 -> V_84 , L_6 ) ;
}
F_87 (bo_va, tmp,
&vm->va.rb_root, it.rb) {
F_51 ( & V_49 -> V_50 , & V_13 -> V_58 ) ;
V_6 = F_36 ( V_49 -> V_26 , false ) ;
if ( ! V_6 ) {
F_53 ( & V_49 -> V_55 ) ;
F_45 ( V_49 -> V_26 ) ;
F_7 ( & V_49 -> V_143 ) ;
F_77 ( V_49 ) ;
}
}
F_88 (bo_va, tmp, &vm->freed, vm_status) {
F_58 ( & V_49 -> V_26 ) ;
F_7 ( & V_49 -> V_143 ) ;
F_77 ( V_49 ) ;
}
for ( V_8 = 0 ; V_8 < F_1 ( V_2 ) ; V_8 ++ )
F_58 ( & V_13 -> V_30 [ V_8 ] . V_26 ) ;
F_77 ( V_13 -> V_30 ) ;
F_58 ( & V_13 -> V_21 ) ;
for ( V_8 = 0 ; V_8 < V_34 ; ++ V_8 ) {
F_7 ( & V_13 -> V_37 [ V_8 ] . V_46 ) ;
F_7 ( & V_13 -> V_37 [ V_8 ] . V_40 ) ;
}
F_89 ( & V_13 -> V_57 ) ;
}
