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
V_16 [ 0 ] . V_20 = NULL ;
V_16 [ 0 ] . V_21 = V_13 -> V_22 ;
V_16 [ 0 ] . V_23 = V_24 ;
V_16 [ 0 ] . V_25 = V_24 ;
V_16 [ 0 ] . V_26 . V_27 = & V_13 -> V_22 -> V_28 ;
V_16 [ 0 ] . V_29 = 0 ;
V_16 [ 0 ] . V_30 = 0 ;
F_11 ( & V_16 [ 0 ] . V_26 . V_15 , V_15 ) ;
for ( V_8 = 0 , V_17 = 1 ; V_8 <= V_13 -> V_18 ; V_8 ++ ) {
if ( ! V_13 -> V_31 [ V_8 ] . V_27 )
continue;
V_16 [ V_17 ] . V_20 = NULL ;
V_16 [ V_17 ] . V_21 = V_13 -> V_31 [ V_8 ] . V_27 ;
V_16 [ V_17 ] . V_23 = V_24 ;
V_16 [ V_17 ] . V_25 = V_24 ;
V_16 [ V_17 ] . V_26 . V_27 = & V_16 [ V_17 ] . V_21 -> V_28 ;
V_16 [ V_17 ] . V_29 = 0 ;
V_16 [ V_17 ] . V_30 = 0 ;
F_11 ( & V_16 [ V_17 ++ ] . V_26 . V_15 , V_15 ) ;
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
T_1 V_42 = F_17 ( V_13 -> V_22 ) ;
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
struct V_45 * V_27 )
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
struct V_45 * V_27 )
{
struct V_44 * V_46 ;
V_46 = F_25 ( sizeof( struct V_44 ) , V_19 ) ;
if ( V_46 == NULL ) {
return NULL ;
}
V_46 -> V_13 = V_13 ;
V_46 -> V_27 = V_27 ;
V_46 -> V_47 . V_48 = 0 ;
V_46 -> V_47 . V_49 = 0 ;
V_46 -> V_50 = 0 ;
V_46 -> V_51 = 0 ;
V_46 -> V_52 = 1 ;
F_26 ( & V_46 -> V_53 ) ;
F_26 ( & V_46 -> V_54 ) ;
F_27 ( & V_13 -> V_55 ) ;
F_28 ( & V_46 -> V_53 , & V_27 -> V_56 ) ;
F_29 ( & V_13 -> V_55 ) ;
return V_46 ;
}
static void F_30 ( struct V_1 * V_2 ,
struct V_57 * V_58 ,
T_1 V_59 ,
T_1 V_51 , unsigned V_60 ,
T_2 V_61 , T_2 V_50 )
{
F_31 ( V_59 , V_51 , V_60 , V_61 , V_50 ) ;
if ( ( V_50 & V_62 ) == V_62 ) {
T_1 V_63 = V_2 -> V_64 . V_65 + ( V_51 >> 12 ) * 8 ;
F_32 ( V_2 , V_58 , V_59 , V_63 , V_60 ) ;
} else if ( ( V_50 & V_66 ) || ( V_60 < 3 ) ) {
F_33 ( V_2 , V_58 , V_59 , V_51 ,
V_60 , V_61 , V_50 ) ;
} else {
F_34 ( V_2 , V_58 , V_59 , V_51 ,
V_60 , V_61 , V_50 ) ;
}
}
static int F_35 ( struct V_1 * V_2 ,
struct V_45 * V_27 )
{
struct V_67 V_26 ;
struct V_68 V_69 ;
struct V_14 V_15 ;
struct V_57 V_58 ;
unsigned V_70 ;
T_1 V_51 ;
int V_6 ;
memset ( & V_26 , 0 , sizeof( V_26 ) ) ;
V_26 . V_27 = & V_27 -> V_28 ;
F_26 ( & V_15 ) ;
F_11 ( & V_26 . V_15 , & V_15 ) ;
V_6 = F_36 ( & V_69 , & V_15 ) ;
if ( V_6 )
return V_6 ;
V_6 = F_37 ( & V_27 -> V_28 , & V_27 -> V_71 , true , false ) ;
if ( V_6 )
goto error;
V_51 = F_17 ( V_27 ) ;
V_70 = F_38 ( V_27 ) / 8 ;
V_6 = F_39 ( V_2 , V_72 , & V_58 , NULL , 256 ) ;
if ( V_6 )
goto error;
V_58 . V_73 = 0 ;
F_30 ( V_2 , & V_58 , V_51 , 0 , V_70 , 0 , 0 ) ;
F_40 ( V_2 , & V_58 ) ;
F_41 ( V_58 . V_73 > 64 ) ;
V_6 = F_42 ( V_2 , & V_58 , NULL , false ) ;
if ( V_6 )
goto error;
F_43 ( & V_69 , & V_15 , V_58 . V_41 ) ;
F_44 ( V_2 , & V_58 ) ;
return 0 ;
error:
F_45 ( & V_69 , & V_15 ) ;
return V_6 ;
}
int F_46 ( struct V_1 * V_2 ,
struct V_44 * V_46 ,
T_1 V_74 ,
T_2 V_50 )
{
T_1 V_75 = F_38 ( V_46 -> V_27 ) ;
struct V_12 * V_13 = V_46 -> V_13 ;
unsigned V_76 , V_77 ;
T_1 V_78 ;
int V_6 ;
if ( V_74 ) {
V_78 = V_74 + V_75 ;
if ( V_74 >= V_78 ) {
return - V_79 ;
}
V_76 = V_78 / V_80 ;
if ( V_76 > V_2 -> V_3 . V_4 ) {
F_47 ( V_2 -> V_81 , L_1 ,
V_76 , V_2 -> V_3 . V_4 ) ;
return - V_79 ;
}
} else {
V_78 = V_76 = 0 ;
}
F_27 ( & V_13 -> V_55 ) ;
if ( V_46 -> V_47 . V_48 || V_46 -> V_47 . V_49 ) {
if ( V_46 -> V_51 ) {
struct V_44 * V_82 ;
V_82 = F_25 ( sizeof( struct V_44 ) , V_19 ) ;
if ( ! V_82 ) {
F_29 ( & V_13 -> V_55 ) ;
return - V_83 ;
}
V_82 -> V_47 . V_48 = V_46 -> V_47 . V_48 ;
V_82 -> V_47 . V_49 = V_46 -> V_47 . V_49 ;
V_82 -> V_13 = V_13 ;
V_82 -> V_51 = V_46 -> V_51 ;
V_82 -> V_27 = F_48 ( V_46 -> V_27 ) ;
F_11 ( & V_82 -> V_54 , & V_13 -> V_84 ) ;
}
F_49 ( & V_46 -> V_47 , & V_13 -> V_56 ) ;
V_46 -> V_47 . V_48 = 0 ;
V_46 -> V_47 . V_49 = 0 ;
}
V_74 /= V_80 ;
V_78 /= V_80 ;
if ( V_74 || V_78 ) {
struct V_85 * V_47 ;
V_47 = F_50 ( & V_13 -> V_56 , V_74 , V_78 - 1 ) ;
if ( V_47 ) {
struct V_44 * V_82 ;
V_82 = F_51 ( V_47 , struct V_44 , V_47 ) ;
F_47 ( V_2 -> V_81 , L_2
L_3 , V_46 -> V_27 ,
V_74 , V_82 -> V_27 , V_82 -> V_47 . V_48 , V_82 -> V_47 . V_49 ) ;
F_29 ( & V_13 -> V_55 ) ;
return - V_79 ;
}
V_46 -> V_47 . V_48 = V_74 ;
V_46 -> V_47 . V_49 = V_78 - 1 ;
F_52 ( & V_46 -> V_47 , & V_13 -> V_56 ) ;
}
V_46 -> V_50 = V_50 ;
V_46 -> V_51 = 0 ;
V_74 >>= V_5 ;
V_78 >>= V_5 ;
F_53 ( V_78 >= F_1 ( V_2 ) ) ;
if ( V_78 > V_13 -> V_18 )
V_13 -> V_18 = V_78 ;
F_54 ( V_46 -> V_27 ) ;
for ( V_77 = V_74 ; V_77 <= V_78 ; ++ V_77 ) {
struct V_45 * V_86 ;
if ( V_13 -> V_31 [ V_77 ] . V_27 )
continue;
F_29 ( & V_13 -> V_55 ) ;
V_6 = F_55 ( V_2 , V_87 * 8 ,
V_80 , true ,
V_24 , 0 , NULL , & V_86 ) ;
if ( V_6 )
return V_6 ;
V_6 = F_35 ( V_2 , V_86 ) ;
if ( V_6 ) {
F_56 ( & V_86 ) ;
F_57 ( V_46 -> V_27 , false ) ;
return V_6 ;
}
F_27 ( & V_13 -> V_55 ) ;
if ( V_13 -> V_31 [ V_77 ] . V_27 ) {
F_29 ( & V_13 -> V_55 ) ;
F_56 ( & V_86 ) ;
F_27 ( & V_13 -> V_55 ) ;
continue;
}
V_13 -> V_31 [ V_77 ] . V_51 = 0 ;
V_13 -> V_31 [ V_77 ] . V_27 = V_86 ;
}
F_29 ( & V_13 -> V_55 ) ;
return F_57 ( V_46 -> V_27 , false ) ;
}
T_1 F_58 ( struct V_1 * V_2 , T_1 V_51 )
{
T_1 V_88 ;
V_88 = V_2 -> V_64 . V_89 [ V_51 >> V_90 ] ;
V_88 |= V_51 & ( ~ V_91 ) ;
return V_88 ;
}
static T_2 F_59 ( T_2 V_50 )
{
T_2 V_92 = 0 ;
V_92 |= ( V_50 & V_93 ) ? V_94 : 0 ;
V_92 |= ( V_50 & V_95 ) ? V_96 : 0 ;
V_92 |= ( V_50 & V_97 ) ? V_98 : 0 ;
if ( V_50 & V_99 ) {
V_92 |= V_66 ;
V_92 |= ( V_50 & V_100 ) ? V_101 : 0 ;
}
return V_92 ;
}
int F_60 ( struct V_1 * V_2 ,
struct V_12 * V_13 )
{
struct V_45 * V_102 = V_13 -> V_22 ;
T_1 V_42 = F_17 ( V_102 ) ;
T_2 V_61 = V_87 * 8 ;
T_1 V_103 = ~ 0 , V_104 = ~ 0 ;
unsigned V_60 = 0 , V_77 , V_105 ;
struct V_57 V_58 ;
int V_6 ;
V_105 = 64 ;
V_105 += V_13 -> V_18 * 6 ;
if ( V_105 > 0xfffff )
return - V_83 ;
V_6 = F_39 ( V_2 , V_72 , & V_58 , NULL , V_105 * 4 ) ;
if ( V_6 )
return V_6 ;
V_58 . V_73 = 0 ;
for ( V_77 = 0 ; V_77 <= V_13 -> V_18 ; ++ V_77 ) {
struct V_45 * V_27 = V_13 -> V_31 [ V_77 ] . V_27 ;
T_1 V_106 , V_86 ;
if ( V_27 == NULL )
continue;
V_86 = F_17 ( V_27 ) ;
if ( V_13 -> V_31 [ V_77 ] . V_51 == V_86 )
continue;
V_13 -> V_31 [ V_77 ] . V_51 = V_86 ;
V_106 = V_42 + V_77 * 8 ;
if ( ( ( V_103 + 8 * V_60 ) != V_106 ) ||
( ( V_104 + V_61 * V_60 ) != V_86 ) ) {
if ( V_60 ) {
F_30 ( V_2 , & V_58 , V_103 ,
V_104 , V_60 , V_61 ,
V_94 ) ;
}
V_60 = 1 ;
V_103 = V_106 ;
V_104 = V_86 ;
} else {
++ V_60 ;
}
}
if ( V_60 )
F_30 ( V_2 , & V_58 , V_103 , V_104 , V_60 ,
V_61 , V_94 ) ;
if ( V_58 . V_73 != 0 ) {
F_40 ( V_2 , & V_58 ) ;
F_61 ( V_58 . V_107 , V_102 -> V_28 . V_108 ) ;
F_61 ( V_58 . V_107 , V_13 -> V_37 ) ;
F_41 ( V_58 . V_73 > V_105 ) ;
V_6 = F_42 ( V_2 , & V_58 , NULL , false ) ;
if ( V_6 ) {
F_44 ( V_2 , & V_58 ) ;
return V_6 ;
}
F_7 ( & V_13 -> V_41 ) ;
V_13 -> V_41 = F_21 ( V_58 . V_41 ) ;
F_7 ( & V_13 -> V_39 ) ;
}
F_44 ( V_2 , & V_58 ) ;
return 0 ;
}
static void F_62 ( struct V_1 * V_2 ,
struct V_57 * V_58 ,
T_1 V_109 , T_1 V_110 ,
T_1 V_51 , T_2 V_50 )
{
T_1 V_111 = V_2 -> V_112 == V_113 ?
V_114 : V_115 ;
T_1 V_116 = V_2 -> V_112 == V_113 ? 0x200 : 0x80 ;
T_1 V_117 = F_63 ( V_109 , V_116 ) ;
T_1 V_118 = V_110 & ~ ( V_116 - 1 ) ;
unsigned V_60 ;
if ( ( V_50 & V_66 ) || ! ( V_50 & V_94 ) ||
( V_117 >= V_118 ) ) {
V_60 = ( V_110 - V_109 ) / 8 ;
F_30 ( V_2 , V_58 , V_109 , V_51 , V_60 ,
V_80 , V_50 ) ;
return;
}
if ( V_109 != V_117 ) {
V_60 = ( V_117 - V_109 ) / 8 ;
F_30 ( V_2 , V_58 , V_109 , V_51 , V_60 ,
V_80 , V_50 ) ;
V_51 += V_80 * V_60 ;
}
V_60 = ( V_118 - V_117 ) / 8 ;
F_30 ( V_2 , V_58 , V_117 , V_51 , V_60 ,
V_80 , V_50 | V_111 ) ;
if ( V_118 != V_110 ) {
V_51 += V_80 * V_60 ;
V_60 = ( V_110 - V_118 ) / 8 ;
F_30 ( V_2 , V_58 , V_118 , V_51 , V_60 ,
V_80 , V_50 ) ;
}
}
static void F_64 ( struct V_1 * V_2 ,
struct V_12 * V_13 ,
struct V_57 * V_58 ,
T_1 V_48 , T_1 V_119 ,
T_1 V_120 , T_2 V_50 )
{
T_1 V_121 = V_87 - 1 ;
T_1 V_122 = ~ 0 , V_123 = ~ 0 ;
unsigned V_60 = 0 ;
T_1 V_51 ;
for ( V_51 = V_48 ; V_51 < V_119 ; ) {
T_1 V_77 = V_51 >> V_5 ;
struct V_45 * V_86 = V_13 -> V_31 [ V_77 ] . V_27 ;
unsigned V_124 ;
T_1 V_125 ;
F_61 ( V_58 -> V_107 , V_86 -> V_28 . V_108 ) ;
if ( ( V_51 & ~ V_121 ) == ( V_119 & ~ V_121 ) )
V_124 = V_119 - V_51 ;
else
V_124 = V_87 - ( V_51 & V_121 ) ;
V_125 = F_17 ( V_86 ) ;
V_125 += ( V_51 & V_121 ) * 8 ;
if ( ( V_122 + 8 * V_60 ) != V_125 ) {
if ( V_60 ) {
F_62 ( V_2 , V_58 , V_122 ,
V_122 + 8 * V_60 ,
V_123 , V_50 ) ;
}
V_60 = V_124 ;
V_122 = V_125 ;
V_123 = V_120 ;
} else {
V_60 += V_124 ;
}
V_51 += V_124 ;
V_120 += V_124 * V_80 ;
}
if ( V_60 ) {
F_62 ( V_2 , V_58 , V_122 ,
V_122 + 8 * V_60 ,
V_123 , V_50 ) ;
}
}
int F_65 ( struct V_1 * V_2 ,
struct V_44 * V_46 ,
struct V_126 * V_127 )
{
struct V_12 * V_13 = V_46 -> V_13 ;
struct V_57 V_58 ;
unsigned V_124 , V_128 , V_105 ;
T_1 V_51 ;
T_2 V_50 ;
int V_6 ;
if ( ! V_46 -> V_47 . V_48 ) {
F_47 ( V_2 -> V_81 , L_4 ,
V_46 -> V_27 , V_13 ) ;
return - V_79 ;
}
F_66 ( & V_46 -> V_54 ) ;
V_46 -> V_50 &= ~ V_93 ;
V_46 -> V_50 &= ~ V_99 ;
V_46 -> V_50 &= ~ V_100 ;
if ( V_127 ) {
V_51 = V_127 -> V_48 << V_90 ;
if ( V_127 -> V_129 != V_130 ) {
V_46 -> V_50 |= V_93 ;
}
if ( V_127 -> V_129 == V_131 ) {
V_46 -> V_50 |= V_99 ;
if ( ! ( V_46 -> V_27 -> V_50 & ( V_132 | V_133 ) ) )
V_46 -> V_50 |= V_100 ;
} else {
V_51 += V_2 -> V_3 . V_134 ;
}
} else {
V_51 = 0 ;
}
if ( V_51 == V_46 -> V_51 )
return 0 ;
V_46 -> V_51 = V_51 ;
F_67 ( V_46 ) ;
V_124 = V_46 -> V_47 . V_49 - V_46 -> V_47 . V_48 + 1 ;
V_128 = ( V_124 >> F_68 ( V_5 , 11 ) ) + 1 ;
V_105 = 64 ;
V_50 = F_59 ( V_46 -> V_50 ) ;
if ( ( V_50 & V_62 ) == V_62 ) {
V_105 += V_128 * 7 ;
} else if ( V_50 & V_66 ) {
V_105 += V_128 * 4 ;
V_105 += V_124 * 2 ;
} else {
V_105 += V_128 * 10 ;
V_105 += 2 * 10 ;
}
if ( V_105 > 0xfffff )
return - V_83 ;
V_6 = F_39 ( V_2 , V_72 , & V_58 , NULL , V_105 * 4 ) ;
if ( V_6 )
return V_6 ;
V_58 . V_73 = 0 ;
F_64 ( V_2 , V_13 , & V_58 , V_46 -> V_47 . V_48 ,
V_46 -> V_47 . V_49 + 1 , V_51 ,
F_59 ( V_46 -> V_50 ) ) ;
F_40 ( V_2 , & V_58 ) ;
F_41 ( V_58 . V_73 > V_105 ) ;
F_61 ( V_58 . V_107 , V_13 -> V_41 ) ;
V_6 = F_42 ( V_2 , & V_58 , NULL , false ) ;
if ( V_6 ) {
F_44 ( V_2 , & V_58 ) ;
return V_6 ;
}
F_7 ( & V_13 -> V_41 ) ;
V_13 -> V_41 = F_21 ( V_58 . V_41 ) ;
F_44 ( V_2 , & V_58 ) ;
F_7 ( & V_13 -> V_39 ) ;
return 0 ;
}
int F_69 ( struct V_1 * V_2 ,
struct V_12 * V_13 )
{
struct V_44 * V_46 , * V_82 ;
int V_6 ;
F_70 (bo_va, tmp, &vm->freed, vm_status) {
V_6 = F_65 ( V_2 , V_46 , NULL ) ;
F_56 ( & V_46 -> V_27 ) ;
F_71 ( V_46 ) ;
if ( V_6 )
return V_6 ;
}
return 0 ;
}
int F_72 ( struct V_1 * V_2 ,
struct V_12 * V_13 )
{
struct V_44 * V_46 , * V_82 ;
int V_6 ;
F_70 (bo_va, tmp, &vm->invalidated, vm_status) {
V_6 = F_65 ( V_2 , V_46 , NULL ) ;
if ( V_6 )
return V_6 ;
}
return 0 ;
}
void F_73 ( struct V_1 * V_2 ,
struct V_44 * V_46 )
{
struct V_12 * V_13 = V_46 -> V_13 ;
F_74 ( & V_46 -> V_53 ) ;
F_27 ( & V_13 -> V_55 ) ;
F_49 ( & V_46 -> V_47 , & V_13 -> V_56 ) ;
F_74 ( & V_46 -> V_54 ) ;
if ( V_46 -> V_51 ) {
V_46 -> V_27 = F_48 ( V_46 -> V_27 ) ;
F_11 ( & V_46 -> V_54 , & V_13 -> V_84 ) ;
} else {
F_71 ( V_46 ) ;
}
F_29 ( & V_13 -> V_55 ) ;
}
void F_75 ( struct V_1 * V_2 ,
struct V_45 * V_27 )
{
struct V_44 * V_46 ;
F_23 (bo_va, &bo->va, bo_list) {
if ( V_46 -> V_51 ) {
F_27 ( & V_46 -> V_13 -> V_55 ) ;
F_74 ( & V_46 -> V_54 ) ;
F_11 ( & V_46 -> V_54 , & V_46 -> V_13 -> V_135 ) ;
F_29 ( & V_46 -> V_13 -> V_55 ) ;
}
}
}
int F_76 ( struct V_1 * V_2 , struct V_12 * V_13 )
{
const unsigned V_136 = F_68 ( V_137 ,
V_87 * 8 ) ;
unsigned V_138 , V_139 , V_140 ;
int V_6 ;
V_13 -> V_38 = 0 ;
V_13 -> V_141 = NULL ;
V_13 -> V_41 = NULL ;
V_13 -> V_39 = NULL ;
V_13 -> V_37 = NULL ;
F_77 ( & V_13 -> V_55 ) ;
V_13 -> V_56 = V_142 ;
F_26 ( & V_13 -> V_135 ) ;
F_26 ( & V_13 -> V_84 ) ;
V_138 = F_2 ( V_2 ) ;
V_139 = F_1 ( V_2 ) ;
V_140 = V_139 * sizeof( struct V_143 ) ;
V_13 -> V_31 = F_25 ( V_140 , V_19 ) ;
if ( V_13 -> V_31 == NULL ) {
F_78 ( L_5 ) ;
return - V_83 ;
}
V_6 = F_55 ( V_2 , V_138 , V_136 , true ,
V_24 , 0 , NULL ,
& V_13 -> V_22 ) ;
if ( V_6 )
return V_6 ;
V_6 = F_35 ( V_2 , V_13 -> V_22 ) ;
if ( V_6 ) {
F_56 ( & V_13 -> V_22 ) ;
V_13 -> V_22 = NULL ;
return V_6 ;
}
return 0 ;
}
void F_79 ( struct V_1 * V_2 , struct V_12 * V_13 )
{
struct V_44 * V_46 , * V_82 ;
int V_8 , V_6 ;
if ( ! F_80 ( & V_13 -> V_56 ) ) {
F_47 ( V_2 -> V_81 , L_6 ) ;
}
F_81 (bo_va, tmp, &vm->va, it.rb) {
F_49 ( & V_46 -> V_47 , & V_13 -> V_56 ) ;
V_6 = F_57 ( V_46 -> V_27 , false ) ;
if ( ! V_6 ) {
F_66 ( & V_46 -> V_53 ) ;
F_54 ( V_46 -> V_27 ) ;
F_71 ( V_46 ) ;
}
}
F_70 (bo_va, tmp, &vm->freed, vm_status) {
F_56 ( & V_46 -> V_27 ) ;
F_71 ( V_46 ) ;
}
for ( V_8 = 0 ; V_8 < F_1 ( V_2 ) ; V_8 ++ )
F_56 ( & V_13 -> V_31 [ V_8 ] . V_27 ) ;
F_71 ( V_13 -> V_31 ) ;
F_56 ( & V_13 -> V_22 ) ;
F_7 ( & V_13 -> V_41 ) ;
F_7 ( & V_13 -> V_39 ) ;
F_7 ( & V_13 -> V_37 ) ;
F_82 ( & V_13 -> V_55 ) ;
}
