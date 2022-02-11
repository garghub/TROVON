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
sizeof( struct V_11 ) ) ;
if ( ! V_16 )
return NULL ;
V_16 [ 0 ] . V_19 = NULL ;
V_16 [ 0 ] . V_20 = V_13 -> V_21 ;
V_16 [ 0 ] . V_22 = V_23 ;
V_16 [ 0 ] . V_24 = V_23 ;
V_16 [ 0 ] . V_25 . V_26 = & V_13 -> V_21 -> V_27 ;
V_16 [ 0 ] . V_25 . V_28 = false ;
V_16 [ 0 ] . V_29 = 0 ;
V_16 [ 0 ] . V_30 = 0 ;
F_11 ( & V_16 [ 0 ] . V_25 . V_15 , V_15 ) ;
for ( V_8 = 0 , V_17 = 1 ; V_8 <= V_13 -> V_18 ; V_8 ++ ) {
if ( ! V_13 -> V_31 [ V_8 ] . V_26 )
continue;
V_16 [ V_17 ] . V_19 = NULL ;
V_16 [ V_17 ] . V_20 = V_13 -> V_31 [ V_8 ] . V_26 ;
V_16 [ V_17 ] . V_22 = V_23 ;
V_16 [ V_17 ] . V_24 = V_23 ;
V_16 [ V_17 ] . V_25 . V_26 = & V_16 [ V_17 ] . V_20 -> V_27 ;
V_16 [ V_17 ] . V_25 . V_28 = false ;
V_16 [ V_17 ] . V_29 = 0 ;
V_16 [ V_17 ] . V_30 = 0 ;
F_11 ( & V_16 [ V_17 ++ ] . V_25 . V_15 , V_15 ) ;
}
return V_16 ;
}
struct V_32 * F_12 ( struct V_1 * V_2 ,
struct V_12 * V_13 , int V_33 )
{
struct V_32 * V_34 [ V_35 ] = {} ;
unsigned V_36 [ 2 ] = {} ;
unsigned V_8 ;
if ( V_13 -> V_37 && V_13 -> V_37 == V_2 -> V_3 . V_10 [ V_13 -> V_38 ] )
return NULL ;
F_7 ( & V_13 -> V_39 ) ;
for ( V_8 = 1 ; V_8 < V_2 -> V_3 . V_40 ; ++ V_8 ) {
struct V_32 * V_41 = V_2 -> V_3 . V_10 [ V_8 ] ;
if ( V_41 == NULL ) {
V_13 -> V_38 = V_8 ;
F_13 ( V_13 -> V_38 , V_33 ) ;
return NULL ;
}
if ( F_14 ( V_41 , V_34 [ V_41 -> V_33 ] ) ) {
V_34 [ V_41 -> V_33 ] = V_41 ;
V_36 [ V_41 -> V_33 == V_33 ? 0 : 1 ] = V_8 ;
}
}
for ( V_8 = 0 ; V_8 < 2 ; ++ V_8 ) {
if ( V_36 [ V_8 ] ) {
V_13 -> V_38 = V_36 [ V_8 ] ;
F_13 ( V_13 -> V_38 , V_33 ) ;
return V_2 -> V_3 . V_10 [ V_36 [ V_8 ] ] ;
}
}
F_15 () ;
return NULL ;
}
void F_16 ( struct V_1 * V_2 ,
struct V_12 * V_13 ,
int V_33 )
{
T_1 V_42 = F_17 ( V_13 -> V_21 ) ;
if ( ! V_13 -> V_39 || V_42 != V_13 -> V_43 ) {
F_18 ( V_42 , V_33 , V_13 -> V_38 ) ;
V_13 -> V_43 = V_42 ;
F_19 ( V_2 , V_33 , V_13 ) ;
}
}
void F_20 ( struct V_1 * V_2 ,
struct V_12 * V_13 ,
struct V_32 * V_41 )
{
F_7 ( & V_13 -> V_41 ) ;
V_13 -> V_41 = F_21 ( V_41 ) ;
F_7 ( & V_2 -> V_3 . V_10 [ V_13 -> V_38 ] ) ;
V_2 -> V_3 . V_10 [ V_13 -> V_38 ] = F_21 ( V_41 ) ;
F_7 ( & V_13 -> V_37 ) ;
V_13 -> V_37 = F_21 ( V_41 ) ;
if ( ! V_13 -> V_39 )
V_13 -> V_39 = F_21 ( V_41 ) ;
}
struct V_44 * F_22 ( struct V_12 * V_13 ,
struct V_45 * V_26 )
{
struct V_44 * V_46 ;
F_23 (bo_va, &bo->va, bo_list) {
if ( V_46 -> V_13 == V_13 ) {
return V_46 ;
}
}
return NULL ;
}
struct V_44 * F_24 ( struct V_1 * V_2 ,
struct V_12 * V_13 ,
struct V_45 * V_26 )
{
struct V_44 * V_46 ;
V_46 = F_25 ( sizeof( struct V_44 ) , V_47 ) ;
if ( V_46 == NULL ) {
return NULL ;
}
V_46 -> V_13 = V_13 ;
V_46 -> V_26 = V_26 ;
V_46 -> V_48 . V_49 = 0 ;
V_46 -> V_48 . V_50 = 0 ;
V_46 -> V_51 = 0 ;
V_46 -> V_52 = 0 ;
V_46 -> V_53 = 1 ;
F_26 ( & V_46 -> V_54 ) ;
F_26 ( & V_46 -> V_55 ) ;
F_27 ( & V_13 -> V_56 ) ;
F_28 ( & V_46 -> V_54 , & V_26 -> V_57 ) ;
F_29 ( & V_13 -> V_56 ) ;
return V_46 ;
}
static void F_30 ( struct V_1 * V_2 ,
struct V_58 * V_59 ,
T_1 V_60 ,
T_1 V_52 , unsigned V_61 ,
T_2 V_62 , T_2 V_51 )
{
F_31 ( V_60 , V_52 , V_61 , V_62 , V_51 ) ;
if ( ( V_51 & V_63 ) == V_63 ) {
T_1 V_64 = V_2 -> V_65 . V_66 + ( V_52 >> 12 ) * 8 ;
F_32 ( V_2 , V_59 , V_60 , V_64 , V_61 ) ;
} else if ( ( V_51 & V_67 ) || ( V_61 < 3 ) ) {
F_33 ( V_2 , V_59 , V_60 , V_52 ,
V_61 , V_62 , V_51 ) ;
} else {
F_34 ( V_2 , V_59 , V_60 , V_52 ,
V_61 , V_62 , V_51 ) ;
}
}
static int F_35 ( struct V_1 * V_2 ,
struct V_45 * V_26 )
{
struct V_68 V_25 ;
struct V_69 V_70 ;
struct V_14 V_15 ;
struct V_58 V_59 ;
unsigned V_71 ;
T_1 V_52 ;
int V_6 ;
memset ( & V_25 , 0 , sizeof( V_25 ) ) ;
V_25 . V_26 = & V_26 -> V_27 ;
V_25 . V_28 = false ;
F_26 ( & V_15 ) ;
F_11 ( & V_25 . V_15 , & V_15 ) ;
V_6 = F_36 ( & V_70 , & V_15 , true ) ;
if ( V_6 )
return V_6 ;
V_6 = F_37 ( & V_26 -> V_27 , & V_26 -> V_72 , true , false ) ;
if ( V_6 )
goto error;
V_52 = F_17 ( V_26 ) ;
V_71 = F_38 ( V_26 ) / 8 ;
V_6 = F_39 ( V_2 , V_73 , & V_59 , NULL , 256 ) ;
if ( V_6 )
goto error;
V_59 . V_74 = 0 ;
F_30 ( V_2 , & V_59 , V_52 , 0 , V_71 , 0 , 0 ) ;
F_40 ( V_2 , & V_59 ) ;
F_41 ( V_59 . V_74 > 64 ) ;
V_6 = F_42 ( V_2 , & V_59 , NULL , false ) ;
if ( V_6 )
goto error;
F_43 ( & V_70 , & V_15 , & V_59 . V_41 -> V_75 ) ;
F_44 ( V_2 , & V_59 ) ;
return 0 ;
error:
F_45 ( & V_70 , & V_15 ) ;
return V_6 ;
}
int F_46 ( struct V_1 * V_2 ,
struct V_44 * V_46 ,
T_1 V_76 ,
T_2 V_51 )
{
T_1 V_77 = F_38 ( V_46 -> V_26 ) ;
struct V_12 * V_13 = V_46 -> V_13 ;
unsigned V_78 , V_79 ;
T_1 V_80 ;
int V_6 ;
if ( V_76 ) {
V_80 = V_76 + V_77 ;
if ( V_76 >= V_80 ) {
return - V_81 ;
}
V_78 = V_80 / V_82 ;
if ( V_78 > V_2 -> V_3 . V_4 ) {
F_47 ( V_2 -> V_83 , L_1 ,
V_78 , V_2 -> V_3 . V_4 ) ;
return - V_81 ;
}
} else {
V_80 = V_78 = 0 ;
}
F_27 ( & V_13 -> V_56 ) ;
if ( V_46 -> V_48 . V_49 || V_46 -> V_48 . V_50 ) {
if ( V_46 -> V_52 ) {
struct V_44 * V_84 ;
V_84 = F_25 ( sizeof( struct V_44 ) , V_47 ) ;
if ( ! V_84 ) {
F_29 ( & V_13 -> V_56 ) ;
return - V_85 ;
}
V_84 -> V_48 . V_49 = V_46 -> V_48 . V_49 ;
V_84 -> V_48 . V_50 = V_46 -> V_48 . V_50 ;
V_84 -> V_13 = V_13 ;
V_84 -> V_52 = V_46 -> V_52 ;
V_84 -> V_26 = F_48 ( V_46 -> V_26 ) ;
F_11 ( & V_84 -> V_55 , & V_13 -> V_86 ) ;
}
F_49 ( & V_46 -> V_48 , & V_13 -> V_57 ) ;
V_46 -> V_48 . V_49 = 0 ;
V_46 -> V_48 . V_50 = 0 ;
}
V_76 /= V_82 ;
V_80 /= V_82 ;
if ( V_76 || V_80 ) {
struct V_87 * V_48 ;
V_48 = F_50 ( & V_13 -> V_57 , V_76 , V_80 - 1 ) ;
if ( V_48 ) {
struct V_44 * V_84 ;
V_84 = F_51 ( V_48 , struct V_44 , V_48 ) ;
F_47 ( V_2 -> V_83 , L_2
L_3 , V_46 -> V_26 ,
V_76 , V_84 -> V_26 , V_84 -> V_48 . V_49 , V_84 -> V_48 . V_50 ) ;
F_29 ( & V_13 -> V_56 ) ;
return - V_81 ;
}
V_46 -> V_48 . V_49 = V_76 ;
V_46 -> V_48 . V_50 = V_80 - 1 ;
F_52 ( & V_46 -> V_48 , & V_13 -> V_57 ) ;
}
V_46 -> V_51 = V_51 ;
V_46 -> V_52 = 0 ;
V_76 >>= V_5 ;
V_80 >>= V_5 ;
F_53 ( V_80 >= F_1 ( V_2 ) ) ;
if ( V_80 > V_13 -> V_18 )
V_13 -> V_18 = V_80 ;
F_54 ( V_46 -> V_26 ) ;
for ( V_79 = V_76 ; V_79 <= V_80 ; ++ V_79 ) {
struct V_45 * V_88 ;
if ( V_13 -> V_31 [ V_79 ] . V_26 )
continue;
F_29 ( & V_13 -> V_56 ) ;
V_6 = F_55 ( V_2 , V_89 * 8 ,
V_82 , true ,
V_23 , 0 ,
NULL , NULL , & V_88 ) ;
if ( V_6 )
return V_6 ;
V_6 = F_35 ( V_2 , V_88 ) ;
if ( V_6 ) {
F_56 ( & V_88 ) ;
F_57 ( V_46 -> V_26 , false ) ;
return V_6 ;
}
F_27 ( & V_13 -> V_56 ) ;
if ( V_13 -> V_31 [ V_79 ] . V_26 ) {
F_29 ( & V_13 -> V_56 ) ;
F_56 ( & V_88 ) ;
F_27 ( & V_13 -> V_56 ) ;
continue;
}
V_13 -> V_31 [ V_79 ] . V_52 = 0 ;
V_13 -> V_31 [ V_79 ] . V_26 = V_88 ;
}
F_29 ( & V_13 -> V_56 ) ;
return F_57 ( V_46 -> V_26 , false ) ;
}
T_1 F_58 ( struct V_1 * V_2 , T_1 V_52 )
{
T_1 V_90 ;
V_90 = V_2 -> V_65 . V_91 [ V_52 >> V_92 ] ;
V_90 |= V_52 & ( ~ V_93 ) ;
return V_90 ;
}
static T_2 F_59 ( T_2 V_51 )
{
T_2 V_94 = 0 ;
V_94 |= ( V_51 & V_95 ) ? V_96 : 0 ;
V_94 |= ( V_51 & V_97 ) ? V_98 : 0 ;
V_94 |= ( V_51 & V_99 ) ? V_100 : 0 ;
if ( V_51 & V_101 ) {
V_94 |= V_67 ;
V_94 |= ( V_51 & V_102 ) ? V_103 : 0 ;
}
return V_94 ;
}
int F_60 ( struct V_1 * V_2 ,
struct V_12 * V_13 )
{
struct V_45 * V_104 = V_13 -> V_21 ;
T_1 V_42 = F_17 ( V_104 ) ;
T_2 V_62 = V_89 * 8 ;
T_1 V_105 = ~ 0 , V_106 = ~ 0 ;
unsigned V_61 = 0 , V_79 , V_107 ;
struct V_58 V_59 ;
int V_6 ;
V_107 = 64 ;
V_107 += V_13 -> V_18 * 6 ;
if ( V_107 > 0xfffff )
return - V_85 ;
V_6 = F_39 ( V_2 , V_73 , & V_59 , NULL , V_107 * 4 ) ;
if ( V_6 )
return V_6 ;
V_59 . V_74 = 0 ;
for ( V_79 = 0 ; V_79 <= V_13 -> V_18 ; ++ V_79 ) {
struct V_45 * V_26 = V_13 -> V_31 [ V_79 ] . V_26 ;
T_1 V_108 , V_88 ;
if ( V_26 == NULL )
continue;
V_88 = F_17 ( V_26 ) ;
if ( V_13 -> V_31 [ V_79 ] . V_52 == V_88 )
continue;
V_13 -> V_31 [ V_79 ] . V_52 = V_88 ;
V_108 = V_42 + V_79 * 8 ;
if ( ( ( V_105 + 8 * V_61 ) != V_108 ) ||
( ( V_106 + V_62 * V_61 ) != V_88 ) ) {
if ( V_61 ) {
F_30 ( V_2 , & V_59 , V_105 ,
V_106 , V_61 , V_62 ,
V_96 ) ;
}
V_61 = 1 ;
V_105 = V_108 ;
V_106 = V_88 ;
} else {
++ V_61 ;
}
}
if ( V_61 )
F_30 ( V_2 , & V_59 , V_105 , V_106 , V_61 ,
V_62 , V_96 ) ;
if ( V_59 . V_74 != 0 ) {
F_40 ( V_2 , & V_59 ) ;
F_61 ( V_2 , V_59 . V_109 , V_104 -> V_27 . V_110 , false ) ;
F_62 ( V_59 . V_109 , V_13 -> V_37 ) ;
F_41 ( V_59 . V_74 > V_107 ) ;
V_6 = F_42 ( V_2 , & V_59 , NULL , false ) ;
if ( V_6 ) {
F_44 ( V_2 , & V_59 ) ;
return V_6 ;
}
F_7 ( & V_13 -> V_41 ) ;
V_13 -> V_41 = F_21 ( V_59 . V_41 ) ;
F_7 ( & V_13 -> V_39 ) ;
}
F_44 ( V_2 , & V_59 ) ;
return 0 ;
}
static void F_63 ( struct V_1 * V_2 ,
struct V_58 * V_59 ,
T_1 V_111 , T_1 V_112 ,
T_1 V_52 , T_2 V_51 )
{
T_1 V_113 = V_2 -> V_114 == V_115 ?
V_116 : V_117 ;
T_1 V_118 = V_2 -> V_114 == V_115 ? 0x200 : 0x80 ;
T_1 V_119 = F_64 ( V_111 , V_118 ) ;
T_1 V_120 = V_112 & ~ ( V_118 - 1 ) ;
unsigned V_61 ;
if ( ( V_51 & V_67 ) || ! ( V_51 & V_96 ) ||
( V_119 >= V_120 ) ) {
V_61 = ( V_112 - V_111 ) / 8 ;
F_30 ( V_2 , V_59 , V_111 , V_52 , V_61 ,
V_82 , V_51 ) ;
return;
}
if ( V_111 != V_119 ) {
V_61 = ( V_119 - V_111 ) / 8 ;
F_30 ( V_2 , V_59 , V_111 , V_52 , V_61 ,
V_82 , V_51 ) ;
V_52 += V_82 * V_61 ;
}
V_61 = ( V_120 - V_119 ) / 8 ;
F_30 ( V_2 , V_59 , V_119 , V_52 , V_61 ,
V_82 , V_51 | V_113 ) ;
if ( V_120 != V_112 ) {
V_52 += V_82 * V_61 ;
V_61 = ( V_112 - V_120 ) / 8 ;
F_30 ( V_2 , V_59 , V_120 , V_52 , V_61 ,
V_82 , V_51 ) ;
}
}
static void F_65 ( struct V_1 * V_2 ,
struct V_12 * V_13 ,
struct V_58 * V_59 ,
T_1 V_49 , T_1 V_121 ,
T_1 V_122 , T_2 V_51 )
{
T_1 V_123 = V_89 - 1 ;
T_1 V_124 = ~ 0 , V_125 = ~ 0 ;
unsigned V_61 = 0 ;
T_1 V_52 ;
for ( V_52 = V_49 ; V_52 < V_121 ; ) {
T_1 V_79 = V_52 >> V_5 ;
struct V_45 * V_88 = V_13 -> V_31 [ V_79 ] . V_26 ;
unsigned V_126 ;
T_1 V_127 ;
F_61 ( V_2 , V_59 -> V_109 , V_88 -> V_27 . V_110 , false ) ;
if ( ( V_52 & ~ V_123 ) == ( V_121 & ~ V_123 ) )
V_126 = V_121 - V_52 ;
else
V_126 = V_89 - ( V_52 & V_123 ) ;
V_127 = F_17 ( V_88 ) ;
V_127 += ( V_52 & V_123 ) * 8 ;
if ( ( V_124 + 8 * V_61 ) != V_127 ) {
if ( V_61 ) {
F_63 ( V_2 , V_59 , V_124 ,
V_124 + 8 * V_61 ,
V_125 , V_51 ) ;
}
V_61 = V_126 ;
V_124 = V_127 ;
V_125 = V_122 ;
} else {
V_61 += V_126 ;
}
V_52 += V_126 ;
V_122 += V_126 * V_82 ;
}
if ( V_61 ) {
F_63 ( V_2 , V_59 , V_124 ,
V_124 + 8 * V_61 ,
V_125 , V_51 ) ;
}
}
int F_66 ( struct V_1 * V_2 ,
struct V_44 * V_46 ,
struct V_128 * V_129 )
{
struct V_12 * V_13 = V_46 -> V_13 ;
struct V_58 V_59 ;
unsigned V_126 , V_130 , V_107 ;
T_1 V_52 ;
T_2 V_51 ;
int V_6 ;
if ( ! V_46 -> V_48 . V_49 ) {
F_47 ( V_2 -> V_83 , L_4 ,
V_46 -> V_26 , V_13 ) ;
return - V_81 ;
}
F_67 ( & V_46 -> V_55 ) ;
V_46 -> V_51 &= ~ V_95 ;
V_46 -> V_51 &= ~ V_101 ;
V_46 -> V_51 &= ~ V_102 ;
if ( V_46 -> V_26 && F_68 ( V_46 -> V_26 -> V_27 . V_131 ) )
V_46 -> V_51 &= ~ V_99 ;
if ( V_129 ) {
V_52 = V_129 -> V_49 << V_92 ;
if ( V_129 -> V_132 != V_133 ) {
V_46 -> V_51 |= V_95 ;
}
if ( V_129 -> V_132 == V_134 ) {
V_46 -> V_51 |= V_101 ;
if ( ! ( V_46 -> V_26 -> V_51 & ( V_135 | V_136 ) ) )
V_46 -> V_51 |= V_102 ;
} else {
V_52 += V_2 -> V_3 . V_137 ;
}
} else {
V_52 = 0 ;
}
if ( V_52 == V_46 -> V_52 )
return 0 ;
V_46 -> V_52 = V_52 ;
F_69 ( V_46 ) ;
V_126 = V_46 -> V_48 . V_50 - V_46 -> V_48 . V_49 + 1 ;
V_130 = ( V_126 >> F_70 ( V_5 , 11 ) ) + 1 ;
V_107 = 64 ;
V_51 = F_59 ( V_46 -> V_51 ) ;
if ( ( V_51 & V_63 ) == V_63 ) {
V_107 += V_130 * 7 ;
} else if ( V_51 & V_67 ) {
V_107 += V_130 * 4 ;
V_107 += V_126 * 2 ;
} else {
V_107 += V_130 * 10 ;
V_107 += 2 * 10 ;
}
if ( V_107 > 0xfffff )
return - V_85 ;
V_6 = F_39 ( V_2 , V_73 , & V_59 , NULL , V_107 * 4 ) ;
if ( V_6 )
return V_6 ;
V_59 . V_74 = 0 ;
F_65 ( V_2 , V_13 , & V_59 , V_46 -> V_48 . V_49 ,
V_46 -> V_48 . V_50 + 1 , V_52 ,
F_59 ( V_46 -> V_51 ) ) ;
F_40 ( V_2 , & V_59 ) ;
F_41 ( V_59 . V_74 > V_107 ) ;
F_62 ( V_59 . V_109 , V_13 -> V_41 ) ;
V_6 = F_42 ( V_2 , & V_59 , NULL , false ) ;
if ( V_6 ) {
F_44 ( V_2 , & V_59 ) ;
return V_6 ;
}
F_7 ( & V_13 -> V_41 ) ;
V_13 -> V_41 = F_21 ( V_59 . V_41 ) ;
F_44 ( V_2 , & V_59 ) ;
F_7 ( & V_13 -> V_39 ) ;
return 0 ;
}
int F_71 ( struct V_1 * V_2 ,
struct V_12 * V_13 )
{
struct V_44 * V_46 , * V_84 ;
int V_6 ;
F_72 (bo_va, tmp, &vm->freed, vm_status) {
V_6 = F_66 ( V_2 , V_46 , NULL ) ;
F_56 ( & V_46 -> V_26 ) ;
F_73 ( V_46 ) ;
if ( V_6 )
return V_6 ;
}
return 0 ;
}
int F_74 ( struct V_1 * V_2 ,
struct V_12 * V_13 )
{
struct V_44 * V_46 , * V_84 ;
int V_6 ;
F_72 (bo_va, tmp, &vm->invalidated, vm_status) {
V_6 = F_66 ( V_2 , V_46 , NULL ) ;
if ( V_6 )
return V_6 ;
}
return 0 ;
}
void F_75 ( struct V_1 * V_2 ,
struct V_44 * V_46 )
{
struct V_12 * V_13 = V_46 -> V_13 ;
F_76 ( & V_46 -> V_54 ) ;
F_27 ( & V_13 -> V_56 ) ;
F_49 ( & V_46 -> V_48 , & V_13 -> V_57 ) ;
F_76 ( & V_46 -> V_55 ) ;
if ( V_46 -> V_52 ) {
V_46 -> V_26 = F_48 ( V_46 -> V_26 ) ;
F_11 ( & V_46 -> V_55 , & V_13 -> V_86 ) ;
} else {
F_73 ( V_46 ) ;
}
F_29 ( & V_13 -> V_56 ) ;
}
void F_77 ( struct V_1 * V_2 ,
struct V_45 * V_26 )
{
struct V_44 * V_46 ;
F_23 (bo_va, &bo->va, bo_list) {
if ( V_46 -> V_52 ) {
F_27 ( & V_46 -> V_13 -> V_56 ) ;
F_76 ( & V_46 -> V_55 ) ;
F_11 ( & V_46 -> V_55 , & V_46 -> V_13 -> V_138 ) ;
F_29 ( & V_46 -> V_13 -> V_56 ) ;
}
}
}
int F_78 ( struct V_1 * V_2 , struct V_12 * V_13 )
{
const unsigned V_139 = F_70 ( V_140 ,
V_89 * 8 ) ;
unsigned V_141 , V_142 , V_143 ;
int V_6 ;
V_13 -> V_38 = 0 ;
V_13 -> V_144 = NULL ;
V_13 -> V_41 = NULL ;
V_13 -> V_39 = NULL ;
V_13 -> V_37 = NULL ;
F_79 ( & V_13 -> V_56 ) ;
V_13 -> V_57 = V_145 ;
F_26 ( & V_13 -> V_138 ) ;
F_26 ( & V_13 -> V_86 ) ;
V_141 = F_2 ( V_2 ) ;
V_142 = F_1 ( V_2 ) ;
V_143 = V_142 * sizeof( struct V_146 ) ;
V_13 -> V_31 = F_25 ( V_143 , V_47 ) ;
if ( V_13 -> V_31 == NULL ) {
F_80 ( L_5 ) ;
return - V_85 ;
}
V_6 = F_55 ( V_2 , V_141 , V_139 , true ,
V_23 , 0 , NULL ,
NULL , & V_13 -> V_21 ) ;
if ( V_6 )
return V_6 ;
V_6 = F_35 ( V_2 , V_13 -> V_21 ) ;
if ( V_6 ) {
F_56 ( & V_13 -> V_21 ) ;
V_13 -> V_21 = NULL ;
return V_6 ;
}
return 0 ;
}
void F_81 ( struct V_1 * V_2 , struct V_12 * V_13 )
{
struct V_44 * V_46 , * V_84 ;
int V_8 , V_6 ;
if ( ! F_82 ( & V_13 -> V_57 ) ) {
F_47 ( V_2 -> V_83 , L_6 ) ;
}
F_83 (bo_va, tmp, &vm->va, it.rb) {
F_49 ( & V_46 -> V_48 , & V_13 -> V_57 ) ;
V_6 = F_57 ( V_46 -> V_26 , false ) ;
if ( ! V_6 ) {
F_67 ( & V_46 -> V_54 ) ;
F_54 ( V_46 -> V_26 ) ;
F_73 ( V_46 ) ;
}
}
F_72 (bo_va, tmp, &vm->freed, vm_status) {
F_56 ( & V_46 -> V_26 ) ;
F_73 ( V_46 ) ;
}
for ( V_8 = 0 ; V_8 < F_1 ( V_2 ) ; V_8 ++ )
F_56 ( & V_13 -> V_31 [ V_8 ] . V_26 ) ;
F_73 ( V_13 -> V_31 ) ;
F_56 ( & V_13 -> V_21 ) ;
F_7 ( & V_13 -> V_41 ) ;
F_7 ( & V_13 -> V_39 ) ;
F_7 ( & V_13 -> V_37 ) ;
F_84 ( & V_13 -> V_56 ) ;
}
