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
if ( ! V_13 -> V_39 || true || V_42 != V_13 -> V_43 ) {
V_13 -> V_43 = V_42 ;
F_18 ( V_2 , V_33 , V_13 ) ;
}
}
void F_19 ( struct V_1 * V_2 ,
struct V_12 * V_13 ,
struct V_32 * V_41 )
{
F_7 ( & V_13 -> V_41 ) ;
V_13 -> V_41 = F_20 ( V_41 ) ;
F_7 ( & V_2 -> V_3 . V_10 [ V_13 -> V_38 ] ) ;
V_2 -> V_3 . V_10 [ V_13 -> V_38 ] = F_20 ( V_41 ) ;
F_7 ( & V_13 -> V_37 ) ;
V_13 -> V_37 = F_20 ( V_41 ) ;
if ( ! V_13 -> V_39 )
V_13 -> V_39 = F_20 ( V_41 ) ;
}
struct V_44 * F_21 ( struct V_12 * V_13 ,
struct V_45 * V_27 )
{
struct V_44 * V_46 ;
F_22 (bo_va, &bo->va, bo_list) {
if ( V_46 -> V_13 == V_13 ) {
return V_46 ;
}
}
return NULL ;
}
struct V_44 * F_23 ( struct V_1 * V_2 ,
struct V_12 * V_13 ,
struct V_45 * V_27 )
{
struct V_44 * V_46 ;
V_46 = F_24 ( sizeof( struct V_44 ) , V_19 ) ;
if ( V_46 == NULL ) {
return NULL ;
}
V_46 -> V_13 = V_13 ;
V_46 -> V_27 = V_27 ;
V_46 -> V_47 = 0 ;
V_46 -> V_48 = 0 ;
V_46 -> V_49 = 0 ;
V_46 -> V_50 = false ;
V_46 -> V_51 = 1 ;
F_25 ( & V_46 -> V_52 ) ;
F_25 ( & V_46 -> V_53 ) ;
F_25 ( & V_46 -> V_54 ) ;
F_26 ( & V_13 -> V_55 ) ;
F_11 ( & V_46 -> V_53 , & V_13 -> V_56 ) ;
F_27 ( & V_46 -> V_52 , & V_27 -> V_56 ) ;
F_28 ( & V_13 -> V_55 ) ;
return V_46 ;
}
static int F_29 ( struct V_1 * V_2 ,
struct V_45 * V_27 )
{
struct V_57 V_26 ;
struct V_58 V_59 ;
struct V_14 V_15 ;
struct V_60 V_61 ;
unsigned V_62 ;
T_1 V_63 ;
int V_6 ;
memset ( & V_26 , 0 , sizeof( V_26 ) ) ;
V_26 . V_27 = & V_27 -> V_28 ;
F_25 ( & V_15 ) ;
F_11 ( & V_26 . V_15 , & V_15 ) ;
V_6 = F_30 ( & V_59 , & V_15 ) ;
if ( V_6 )
return V_6 ;
V_6 = F_31 ( & V_27 -> V_28 , & V_27 -> V_64 , true , false ) ;
if ( V_6 )
goto error;
V_63 = F_17 ( V_27 ) ;
V_62 = F_32 ( V_27 ) / 8 ;
V_6 = F_33 ( V_2 , V_65 , & V_61 ,
NULL , V_62 * 2 + 64 ) ;
if ( V_6 )
goto error;
V_61 . V_66 = 0 ;
F_34 ( V_2 , & V_61 , V_63 , 0 , V_62 , 0 , 0 ) ;
V_6 = F_35 ( V_2 , & V_61 , NULL ) ;
if ( V_6 )
goto error;
F_36 ( & V_59 , & V_15 , V_61 . V_41 ) ;
F_37 ( V_2 , & V_61 ) ;
return 0 ;
error:
F_38 ( & V_59 , & V_15 ) ;
return V_6 ;
}
int F_39 ( struct V_1 * V_2 ,
struct V_44 * V_46 ,
T_1 V_47 ,
T_2 V_49 )
{
T_1 V_67 = F_32 ( V_46 -> V_27 ) ;
T_1 V_48 , V_68 = 0 ;
struct V_12 * V_13 = V_46 -> V_13 ;
struct V_44 * V_69 ;
struct V_14 * V_15 ;
unsigned V_70 , V_71 ;
int V_6 ;
if ( V_47 ) {
V_48 = V_47 + V_67 ;
if ( V_47 >= V_48 ) {
return - V_72 ;
}
V_70 = V_48 / V_73 ;
if ( V_70 > V_2 -> V_3 . V_4 ) {
F_40 ( V_2 -> V_74 , L_1 ,
V_70 , V_2 -> V_3 . V_4 ) ;
return - V_72 ;
}
} else {
V_48 = V_70 = 0 ;
}
F_26 ( & V_13 -> V_55 ) ;
V_15 = & V_13 -> V_56 ;
V_68 = 0 ;
F_22 (tmp, &vm->va, vm_list) {
if ( V_46 == V_69 ) {
continue;
}
if ( V_47 >= V_68 && V_48 <= V_69 -> V_47 ) {
break;
}
if ( V_48 > V_69 -> V_47 && V_47 < V_69 -> V_48 ) {
F_40 ( V_2 -> V_74 , L_2 ,
V_46 -> V_27 , ( unsigned ) V_46 -> V_47 , V_69 -> V_27 ,
( unsigned ) V_69 -> V_47 , ( unsigned ) V_69 -> V_48 ) ;
F_28 ( & V_13 -> V_55 ) ;
return - V_72 ;
}
V_68 = V_69 -> V_48 ;
V_15 = & V_69 -> V_53 ;
}
if ( V_46 -> V_47 ) {
V_69 = F_24 ( sizeof( struct V_44 ) , V_19 ) ;
if ( ! V_69 ) {
F_28 ( & V_13 -> V_55 ) ;
return - V_75 ;
}
V_69 -> V_47 = V_46 -> V_47 ;
V_69 -> V_48 = V_46 -> V_48 ;
V_69 -> V_13 = V_13 ;
F_11 ( & V_69 -> V_54 , & V_13 -> V_76 ) ;
}
V_46 -> V_47 = V_47 ;
V_46 -> V_48 = V_48 ;
V_46 -> V_49 = V_49 ;
V_46 -> V_50 = false ;
F_41 ( & V_46 -> V_53 , V_15 ) ;
V_47 = ( V_47 / V_73 ) >> V_5 ;
V_48 = ( V_48 / V_73 ) >> V_5 ;
F_42 ( V_48 >= F_1 ( V_2 ) ) ;
if ( V_48 > V_13 -> V_18 )
V_13 -> V_18 = V_48 ;
F_43 ( V_46 -> V_27 ) ;
for ( V_71 = V_47 ; V_71 <= V_48 ; ++ V_71 ) {
struct V_45 * V_77 ;
if ( V_13 -> V_31 [ V_71 ] . V_27 )
continue;
F_28 ( & V_13 -> V_55 ) ;
V_6 = F_44 ( V_2 , V_78 * 8 ,
V_73 , true ,
V_24 , NULL , & V_77 ) ;
if ( V_6 )
return V_6 ;
V_6 = F_29 ( V_2 , V_77 ) ;
if ( V_6 ) {
F_45 ( & V_77 ) ;
F_46 ( V_46 -> V_27 , false ) ;
return V_6 ;
}
F_26 ( & V_13 -> V_55 ) ;
if ( V_13 -> V_31 [ V_71 ] . V_27 ) {
F_28 ( & V_13 -> V_55 ) ;
F_45 ( & V_77 ) ;
F_26 ( & V_13 -> V_55 ) ;
continue;
}
V_13 -> V_31 [ V_71 ] . V_63 = 0 ;
V_13 -> V_31 [ V_71 ] . V_27 = V_77 ;
}
F_28 ( & V_13 -> V_55 ) ;
return F_46 ( V_46 -> V_27 , false ) ;
}
T_1 F_47 ( struct V_1 * V_2 , T_1 V_63 )
{
T_1 V_79 ;
V_79 = V_2 -> V_80 . V_81 [ V_63 >> V_82 ] ;
V_79 |= V_63 & ( ~ V_83 ) ;
return V_79 ;
}
static T_2 F_48 ( T_2 V_49 )
{
T_2 V_84 = 0 ;
V_84 |= ( V_49 & V_85 ) ? V_86 : 0 ;
V_84 |= ( V_49 & V_87 ) ? V_88 : 0 ;
V_84 |= ( V_49 & V_89 ) ? V_90 : 0 ;
if ( V_49 & V_91 ) {
V_84 |= V_92 ;
V_84 |= ( V_49 & V_93 ) ? V_94 : 0 ;
}
return V_84 ;
}
int F_49 ( struct V_1 * V_2 ,
struct V_12 * V_13 )
{
struct V_45 * V_95 = V_13 -> V_22 ;
T_1 V_42 = F_17 ( V_95 ) ;
T_2 V_96 = V_78 * 8 ;
T_1 V_97 = ~ 0 , V_98 = ~ 0 ;
unsigned V_99 = 0 , V_71 , V_100 ;
struct V_60 V_61 ;
int V_6 ;
V_100 = 64 ;
V_100 += V_13 -> V_18 * 16 ;
if ( V_100 > 0xfffff )
return - V_75 ;
V_6 = F_33 ( V_2 , V_65 , & V_61 , NULL , V_100 * 4 ) ;
if ( V_6 )
return V_6 ;
V_61 . V_66 = 0 ;
for ( V_71 = 0 ; V_71 <= V_13 -> V_18 ; ++ V_71 ) {
struct V_45 * V_27 = V_13 -> V_31 [ V_71 ] . V_27 ;
T_1 V_101 , V_77 ;
if ( V_27 == NULL )
continue;
V_77 = F_17 ( V_27 ) ;
if ( V_13 -> V_31 [ V_71 ] . V_63 == V_77 )
continue;
V_13 -> V_31 [ V_71 ] . V_63 = V_77 ;
V_101 = V_42 + V_71 * 8 ;
if ( ( ( V_97 + 8 * V_99 ) != V_101 ) ||
( ( V_98 + V_96 * V_99 ) != V_77 ) ) {
if ( V_99 ) {
F_34 ( V_2 , & V_61 , V_97 ,
V_98 , V_99 , V_96 ,
V_86 ) ;
}
V_99 = 1 ;
V_97 = V_101 ;
V_98 = V_77 ;
} else {
++ V_99 ;
}
}
if ( V_99 )
F_34 ( V_2 , & V_61 , V_97 , V_98 , V_99 ,
V_96 , V_86 ) ;
if ( V_61 . V_66 != 0 ) {
F_50 ( V_61 . V_102 , V_95 -> V_28 . V_103 ) ;
F_50 ( V_61 . V_102 , V_13 -> V_37 ) ;
V_6 = F_35 ( V_2 , & V_61 , NULL ) ;
if ( V_6 ) {
F_37 ( V_2 , & V_61 ) ;
return V_6 ;
}
F_7 ( & V_13 -> V_41 ) ;
V_13 -> V_41 = F_20 ( V_61 . V_41 ) ;
F_7 ( & V_13 -> V_39 ) ;
}
F_37 ( V_2 , & V_61 ) ;
return 0 ;
}
static void F_51 ( struct V_1 * V_2 ,
struct V_60 * V_61 ,
T_1 V_104 , T_1 V_105 ,
T_1 V_63 , T_2 V_49 )
{
T_1 V_106 = V_2 -> V_107 == V_108 ?
V_109 : V_110 ;
T_1 V_111 = V_2 -> V_107 == V_108 ? 0x200 : 0x80 ;
T_1 V_112 = F_52 ( V_104 , V_111 ) ;
T_1 V_113 = V_105 & ~ ( V_111 - 1 ) ;
unsigned V_99 ;
if ( ( V_49 & V_92 ) || ! ( V_49 & V_86 ) ||
( V_112 >= V_113 ) ) {
V_99 = ( V_105 - V_104 ) / 8 ;
F_34 ( V_2 , V_61 , V_104 , V_63 , V_99 ,
V_73 , V_49 ) ;
return;
}
if ( V_104 != V_112 ) {
V_99 = ( V_112 - V_104 ) / 8 ;
F_34 ( V_2 , V_61 , V_104 , V_63 , V_99 ,
V_73 , V_49 ) ;
V_63 += V_73 * V_99 ;
}
V_99 = ( V_113 - V_112 ) / 8 ;
F_34 ( V_2 , V_61 , V_112 , V_63 , V_99 ,
V_73 , V_49 | V_106 ) ;
if ( V_113 != V_105 ) {
V_63 += V_73 * V_99 ;
V_99 = ( V_105 - V_113 ) / 8 ;
F_34 ( V_2 , V_61 , V_113 , V_63 , V_99 ,
V_73 , V_49 ) ;
}
}
static void F_53 ( struct V_1 * V_2 ,
struct V_12 * V_13 ,
struct V_60 * V_61 ,
T_1 V_114 , T_1 V_115 ,
T_1 V_116 , T_2 V_49 )
{
T_1 V_117 = V_78 - 1 ;
T_1 V_118 = ~ 0 , V_119 = ~ 0 ;
unsigned V_99 = 0 ;
T_1 V_63 ;
V_114 = V_114 / V_73 ;
V_115 = V_115 / V_73 ;
for ( V_63 = V_114 ; V_63 < V_115 ; ) {
T_1 V_71 = V_63 >> V_5 ;
struct V_45 * V_77 = V_13 -> V_31 [ V_71 ] . V_27 ;
unsigned V_120 ;
T_1 V_121 ;
F_50 ( V_61 -> V_102 , V_77 -> V_28 . V_103 ) ;
if ( ( V_63 & ~ V_117 ) == ( V_115 & ~ V_117 ) )
V_120 = V_115 - V_63 ;
else
V_120 = V_78 - ( V_63 & V_117 ) ;
V_121 = F_17 ( V_77 ) ;
V_121 += ( V_63 & V_117 ) * 8 ;
if ( ( V_118 + 8 * V_99 ) != V_121 ) {
if ( V_99 ) {
F_51 ( V_2 , V_61 , V_118 ,
V_118 + 8 * V_99 ,
V_119 , V_49 ) ;
}
V_99 = V_120 ;
V_118 = V_121 ;
V_119 = V_116 ;
} else {
V_99 += V_120 ;
}
V_63 += V_120 ;
V_116 += V_120 * V_73 ;
}
if ( V_99 ) {
F_51 ( V_2 , V_61 , V_118 ,
V_118 + 8 * V_99 ,
V_119 , V_49 ) ;
}
}
int F_54 ( struct V_1 * V_2 ,
struct V_44 * V_46 ,
struct V_122 * V_123 )
{
struct V_12 * V_13 = V_46 -> V_13 ;
struct V_60 V_61 ;
unsigned V_120 , V_100 ;
T_1 V_63 ;
int V_6 ;
if ( ! V_46 -> V_47 ) {
F_40 ( V_2 -> V_74 , L_3 ,
V_46 -> V_27 , V_13 ) ;
return - V_72 ;
}
if ( ( V_46 -> V_50 && V_123 ) || ( ! V_46 -> V_50 && V_123 == NULL ) )
return 0 ;
V_46 -> V_49 &= ~ V_85 ;
V_46 -> V_49 &= ~ V_91 ;
if ( V_123 ) {
V_63 = V_123 -> V_114 << V_82 ;
if ( V_123 -> V_124 != V_125 ) {
V_46 -> V_49 |= V_85 ;
V_46 -> V_50 = true ;
}
if ( V_123 -> V_124 == V_126 ) {
V_46 -> V_49 |= V_91 ;
} else {
V_63 += V_2 -> V_3 . V_127 ;
}
} else {
V_63 = 0 ;
V_46 -> V_50 = false ;
}
F_55 ( V_46 ) ;
V_120 = ( V_46 -> V_48 - V_46 -> V_47 ) / V_73 ;
V_100 = 64 ;
if ( V_5 > 11 )
V_100 += ( V_120 >> 11 ) * 4 ;
else
V_100 += ( V_120 >> V_5 ) * 4 ;
V_100 += V_120 * 2 ;
if ( V_100 > 0xfffff )
return - V_75 ;
V_6 = F_33 ( V_2 , V_65 , & V_61 , NULL , V_100 * 4 ) ;
if ( V_6 )
return V_6 ;
V_61 . V_66 = 0 ;
F_53 ( V_2 , V_13 , & V_61 , V_46 -> V_47 , V_46 -> V_48 ,
V_63 , F_48 ( V_46 -> V_49 ) ) ;
F_50 ( V_61 . V_102 , V_13 -> V_41 ) ;
V_6 = F_35 ( V_2 , & V_61 , NULL ) ;
if ( V_6 ) {
F_37 ( V_2 , & V_61 ) ;
return V_6 ;
}
F_7 ( & V_13 -> V_41 ) ;
V_13 -> V_41 = F_20 ( V_61 . V_41 ) ;
F_37 ( V_2 , & V_61 ) ;
F_7 ( & V_13 -> V_39 ) ;
return 0 ;
}
int F_56 ( struct V_1 * V_2 ,
struct V_12 * V_13 )
{
struct V_44 * V_46 , * V_69 ;
int V_6 ;
F_57 (bo_va, tmp, &vm->freed, vm_status) {
F_58 ( & V_46 -> V_54 ) ;
V_6 = F_54 ( V_2 , V_46 , NULL ) ;
F_59 ( V_46 ) ;
if ( V_6 )
return V_6 ;
}
return 0 ;
}
void F_60 ( struct V_1 * V_2 ,
struct V_44 * V_46 )
{
struct V_12 * V_13 = V_46 -> V_13 ;
F_58 ( & V_46 -> V_52 ) ;
F_26 ( & V_13 -> V_55 ) ;
F_58 ( & V_46 -> V_53 ) ;
if ( V_46 -> V_47 ) {
V_46 -> V_27 = NULL ;
F_11 ( & V_46 -> V_54 , & V_13 -> V_76 ) ;
} else {
F_59 ( V_46 ) ;
}
F_28 ( & V_13 -> V_55 ) ;
}
void F_61 ( struct V_1 * V_2 ,
struct V_45 * V_27 )
{
struct V_44 * V_46 ;
F_22 (bo_va, &bo->va, bo_list) {
V_46 -> V_50 = false ;
}
}
int F_62 ( struct V_1 * V_2 , struct V_12 * V_13 )
{
const unsigned V_128 = F_63 ( V_129 ,
V_78 * 8 ) ;
unsigned V_130 , V_131 , V_132 ;
int V_6 ;
V_13 -> V_38 = 0 ;
V_13 -> V_133 = NULL ;
V_13 -> V_41 = NULL ;
V_13 -> V_39 = NULL ;
V_13 -> V_37 = NULL ;
F_64 ( & V_13 -> V_55 ) ;
F_25 ( & V_13 -> V_56 ) ;
F_25 ( & V_13 -> V_76 ) ;
V_130 = F_2 ( V_2 ) ;
V_131 = F_1 ( V_2 ) ;
V_132 = V_131 * sizeof( struct V_134 ) ;
V_13 -> V_31 = F_24 ( V_132 , V_19 ) ;
if ( V_13 -> V_31 == NULL ) {
F_65 ( L_4 ) ;
return - V_75 ;
}
V_6 = F_44 ( V_2 , V_130 , V_128 , true ,
V_24 , NULL ,
& V_13 -> V_22 ) ;
if ( V_6 )
return V_6 ;
V_6 = F_29 ( V_2 , V_13 -> V_22 ) ;
if ( V_6 ) {
F_45 ( & V_13 -> V_22 ) ;
V_13 -> V_22 = NULL ;
return V_6 ;
}
return 0 ;
}
void F_66 ( struct V_1 * V_2 , struct V_12 * V_13 )
{
struct V_44 * V_46 , * V_69 ;
int V_8 , V_6 ;
if ( ! F_67 ( & V_13 -> V_56 ) ) {
F_40 ( V_2 -> V_74 , L_5 ) ;
}
F_57 (bo_va, tmp, &vm->va, vm_list) {
F_68 ( & V_46 -> V_53 ) ;
V_6 = F_46 ( V_46 -> V_27 , false ) ;
if ( ! V_6 ) {
F_68 ( & V_46 -> V_52 ) ;
F_43 ( V_46 -> V_27 ) ;
F_59 ( V_46 ) ;
}
}
F_57 (bo_va, tmp, &vm->freed, vm_status)
F_59 ( V_46 ) ;
for ( V_8 = 0 ; V_8 < F_1 ( V_2 ) ; V_8 ++ )
F_45 ( & V_13 -> V_31 [ V_8 ] . V_27 ) ;
F_59 ( V_13 -> V_31 ) ;
F_45 ( & V_13 -> V_22 ) ;
F_7 ( & V_13 -> V_41 ) ;
F_7 ( & V_13 -> V_39 ) ;
F_7 ( & V_13 -> V_37 ) ;
F_69 ( & V_13 -> V_55 ) ;
}
