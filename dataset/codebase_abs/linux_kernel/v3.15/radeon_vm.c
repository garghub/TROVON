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
F_26 ( & V_13 -> V_54 ) ;
F_11 ( & V_46 -> V_53 , & V_13 -> V_55 ) ;
F_27 ( & V_46 -> V_52 , & V_27 -> V_55 ) ;
F_28 ( & V_13 -> V_54 ) ;
return V_46 ;
}
static int F_29 ( struct V_1 * V_2 ,
struct V_45 * V_27 )
{
struct V_56 V_26 ;
struct V_57 V_58 ;
struct V_14 V_15 ;
struct V_59 V_60 ;
unsigned V_61 ;
T_1 V_62 ;
int V_6 ;
memset ( & V_26 , 0 , sizeof( V_26 ) ) ;
V_26 . V_27 = & V_27 -> V_28 ;
F_25 ( & V_15 ) ;
F_11 ( & V_26 . V_15 , & V_15 ) ;
V_6 = F_30 ( & V_58 , & V_15 ) ;
if ( V_6 )
return V_6 ;
V_6 = F_31 ( & V_27 -> V_28 , & V_27 -> V_63 , true , false ) ;
if ( V_6 )
goto error;
V_62 = F_17 ( V_27 ) ;
V_61 = F_32 ( V_27 ) / 8 ;
V_6 = F_33 ( V_2 , V_64 , & V_60 ,
NULL , V_61 * 2 + 64 ) ;
if ( V_6 )
goto error;
V_60 . V_65 = 0 ;
F_34 ( V_2 , & V_60 , V_62 , 0 , V_61 , 0 , 0 ) ;
V_6 = F_35 ( V_2 , & V_60 , NULL ) ;
if ( V_6 )
goto error;
F_36 ( & V_58 , & V_15 , V_60 . V_41 ) ;
F_37 ( V_2 , & V_60 ) ;
return 0 ;
error:
F_38 ( & V_58 , & V_15 ) ;
return V_6 ;
}
int F_39 ( struct V_1 * V_2 ,
struct V_44 * V_46 ,
T_1 V_47 ,
T_2 V_49 )
{
T_1 V_66 = F_32 ( V_46 -> V_27 ) ;
T_1 V_48 , V_67 = 0 ;
struct V_12 * V_13 = V_46 -> V_13 ;
struct V_44 * V_68 ;
struct V_14 * V_15 ;
unsigned V_69 , V_70 ;
int V_6 ;
if ( V_47 ) {
V_48 = V_47 + V_66 ;
if ( V_47 >= V_48 ) {
return - V_71 ;
}
V_69 = V_48 / V_72 ;
if ( V_69 > V_2 -> V_3 . V_4 ) {
F_40 ( V_2 -> V_73 , L_1 ,
V_69 , V_2 -> V_3 . V_4 ) ;
return - V_71 ;
}
} else {
V_48 = V_69 = 0 ;
}
F_26 ( & V_13 -> V_54 ) ;
V_15 = & V_13 -> V_55 ;
V_67 = 0 ;
F_22 (tmp, &vm->va, vm_list) {
if ( V_46 == V_68 ) {
continue;
}
if ( V_47 >= V_67 && V_48 <= V_68 -> V_47 ) {
break;
}
if ( V_48 > V_68 -> V_47 && V_47 < V_68 -> V_48 ) {
F_40 ( V_2 -> V_73 , L_2 ,
V_46 -> V_27 , ( unsigned ) V_46 -> V_47 , V_68 -> V_27 ,
( unsigned ) V_68 -> V_47 , ( unsigned ) V_68 -> V_48 ) ;
F_28 ( & V_13 -> V_54 ) ;
return - V_71 ;
}
V_67 = V_68 -> V_48 ;
V_15 = & V_68 -> V_53 ;
}
V_46 -> V_47 = V_47 ;
V_46 -> V_48 = V_48 ;
V_46 -> V_49 = V_49 ;
V_46 -> V_50 = false ;
F_41 ( & V_46 -> V_53 , V_15 ) ;
V_47 = ( V_47 / V_72 ) >> V_5 ;
V_48 = ( V_48 / V_72 ) >> V_5 ;
if ( V_48 > V_13 -> V_18 )
V_13 -> V_18 = V_48 ;
F_42 ( V_46 -> V_27 ) ;
for ( V_70 = V_47 ; V_70 <= V_48 ; ++ V_70 ) {
struct V_45 * V_74 ;
if ( V_13 -> V_31 [ V_70 ] . V_27 )
continue;
F_28 ( & V_13 -> V_54 ) ;
V_6 = F_43 ( V_2 , V_75 * 8 ,
V_72 , false ,
V_24 , NULL , & V_74 ) ;
if ( V_6 )
return V_6 ;
V_6 = F_29 ( V_2 , V_74 ) ;
if ( V_6 ) {
F_44 ( & V_74 ) ;
F_45 ( V_46 -> V_27 , false ) ;
return V_6 ;
}
F_26 ( & V_13 -> V_54 ) ;
if ( V_13 -> V_31 [ V_70 ] . V_27 ) {
F_28 ( & V_13 -> V_54 ) ;
F_44 ( & V_74 ) ;
F_26 ( & V_13 -> V_54 ) ;
continue;
}
V_13 -> V_31 [ V_70 ] . V_62 = 0 ;
V_13 -> V_31 [ V_70 ] . V_27 = V_74 ;
}
F_28 ( & V_13 -> V_54 ) ;
return F_45 ( V_46 -> V_27 , false ) ;
}
T_1 F_46 ( struct V_1 * V_2 , T_1 V_62 )
{
T_1 V_76 ;
V_76 = V_2 -> V_77 . V_78 [ V_62 >> V_79 ] ;
V_76 |= V_62 & ( ~ V_80 ) ;
return V_76 ;
}
static T_2 F_47 ( T_2 V_49 )
{
T_2 V_81 = 0 ;
V_81 |= ( V_49 & V_82 ) ? V_83 : 0 ;
V_81 |= ( V_49 & V_84 ) ? V_85 : 0 ;
V_81 |= ( V_49 & V_86 ) ? V_87 : 0 ;
if ( V_49 & V_88 ) {
V_81 |= V_89 ;
V_81 |= ( V_49 & V_90 ) ? V_91 : 0 ;
}
return V_81 ;
}
int F_48 ( struct V_1 * V_2 ,
struct V_12 * V_13 )
{
static const T_2 V_92 = V_75 * 8 ;
struct V_45 * V_93 = V_13 -> V_22 ;
T_1 V_42 = F_17 ( V_93 ) ;
T_1 V_94 = ~ 0 , V_95 = ~ 0 ;
unsigned V_96 = 0 , V_70 , V_97 ;
struct V_59 V_60 ;
int V_6 ;
V_97 = 64 ;
V_97 += V_13 -> V_18 * 16 ;
if ( V_97 > 0xfffff )
return - V_98 ;
V_6 = F_33 ( V_2 , V_64 , & V_60 , NULL , V_97 * 4 ) ;
if ( V_6 )
return V_6 ;
V_60 . V_65 = 0 ;
for ( V_70 = 0 ; V_70 <= V_13 -> V_18 ; ++ V_70 ) {
struct V_45 * V_27 = V_13 -> V_31 [ V_70 ] . V_27 ;
T_1 V_99 , V_74 ;
if ( V_27 == NULL )
continue;
V_74 = F_17 ( V_27 ) ;
if ( V_13 -> V_31 [ V_70 ] . V_62 == V_74 )
continue;
V_13 -> V_31 [ V_70 ] . V_62 = V_74 ;
V_99 = V_42 + V_70 * 8 ;
if ( ( ( V_94 + 8 * V_96 ) != V_99 ) ||
( ( V_95 + V_92 * V_96 ) != V_74 ) ) {
if ( V_96 ) {
F_34 ( V_2 , & V_60 , V_94 ,
V_95 , V_96 , V_92 ,
V_83 ) ;
}
V_96 = 1 ;
V_94 = V_99 ;
V_95 = V_74 ;
} else {
++ V_96 ;
}
}
if ( V_96 )
F_34 ( V_2 , & V_60 , V_94 , V_95 , V_96 ,
V_92 , V_83 ) ;
if ( V_60 . V_65 != 0 ) {
F_49 ( V_60 . V_100 , V_93 -> V_28 . V_101 ) ;
F_49 ( V_60 . V_100 , V_13 -> V_37 ) ;
V_6 = F_35 ( V_2 , & V_60 , NULL ) ;
if ( V_6 ) {
F_37 ( V_2 , & V_60 ) ;
return V_6 ;
}
F_7 ( & V_13 -> V_41 ) ;
V_13 -> V_41 = F_20 ( V_60 . V_41 ) ;
F_7 ( & V_13 -> V_39 ) ;
}
F_37 ( V_2 , & V_60 ) ;
return 0 ;
}
static void F_50 ( struct V_1 * V_2 ,
struct V_12 * V_13 ,
struct V_59 * V_60 ,
T_1 V_102 , T_1 V_103 ,
T_1 V_104 , T_2 V_49 )
{
static const T_1 V_105 = V_75 - 1 ;
T_1 V_106 = ~ 0 , V_107 = ~ 0 ;
unsigned V_96 = 0 ;
T_1 V_62 ;
V_102 = V_102 / V_72 ;
V_103 = V_103 / V_72 ;
for ( V_62 = V_102 ; V_62 < V_103 ; ) {
T_1 V_70 = V_62 >> V_5 ;
struct V_45 * V_74 = V_13 -> V_31 [ V_70 ] . V_27 ;
unsigned V_108 ;
T_1 V_109 ;
F_49 ( V_60 -> V_100 , V_74 -> V_28 . V_101 ) ;
if ( ( V_62 & ~ V_105 ) == ( V_103 & ~ V_105 ) )
V_108 = V_103 - V_62 ;
else
V_108 = V_75 - ( V_62 & V_105 ) ;
V_109 = F_17 ( V_74 ) ;
V_109 += ( V_62 & V_105 ) * 8 ;
if ( ( V_106 + 8 * V_96 ) != V_109 ) {
if ( V_96 ) {
F_34 ( V_2 , V_60 , V_106 ,
V_107 , V_96 ,
V_72 ,
V_49 ) ;
}
V_96 = V_108 ;
V_106 = V_109 ;
V_107 = V_104 ;
} else {
V_96 += V_108 ;
}
V_62 += V_108 ;
V_104 += V_108 * V_72 ;
}
if ( V_96 ) {
F_34 ( V_2 , V_60 , V_106 ,
V_107 , V_96 ,
V_72 , V_49 ) ;
}
}
int F_51 ( struct V_1 * V_2 ,
struct V_12 * V_13 ,
struct V_45 * V_27 ,
struct V_110 * V_111 )
{
struct V_59 V_60 ;
struct V_44 * V_46 ;
unsigned V_108 , V_97 ;
T_1 V_62 ;
int V_6 ;
V_46 = F_21 ( V_13 , V_27 ) ;
if ( V_46 == NULL ) {
F_40 ( V_2 -> V_73 , L_3 , V_27 , V_13 ) ;
return - V_71 ;
}
if ( ! V_46 -> V_47 ) {
F_40 ( V_2 -> V_73 , L_4 ,
V_27 , V_13 ) ;
return - V_71 ;
}
if ( ( V_46 -> V_50 && V_111 ) || ( ! V_46 -> V_50 && V_111 == NULL ) )
return 0 ;
V_46 -> V_49 &= ~ V_82 ;
V_46 -> V_49 &= ~ V_88 ;
if ( V_111 ) {
V_62 = V_111 -> V_102 << V_79 ;
if ( V_111 -> V_112 != V_113 ) {
V_46 -> V_49 |= V_82 ;
V_46 -> V_50 = true ;
}
if ( V_111 -> V_112 == V_114 ) {
V_46 -> V_49 |= V_88 ;
} else {
V_62 += V_2 -> V_3 . V_115 ;
}
} else {
V_62 = 0 ;
V_46 -> V_50 = false ;
}
F_52 ( V_46 ) ;
V_108 = F_53 ( V_27 ) ;
V_97 = 64 ;
if ( V_5 > 11 )
V_97 += ( V_108 >> 11 ) * 4 ;
else
V_97 += ( V_108 >> V_5 ) * 4 ;
V_97 += V_108 * 2 ;
if ( V_97 > 0xfffff )
return - V_98 ;
V_6 = F_33 ( V_2 , V_64 , & V_60 , NULL , V_97 * 4 ) ;
if ( V_6 )
return V_6 ;
V_60 . V_65 = 0 ;
F_50 ( V_2 , V_13 , & V_60 , V_46 -> V_47 , V_46 -> V_48 ,
V_62 , F_47 ( V_46 -> V_49 ) ) ;
F_49 ( V_60 . V_100 , V_13 -> V_41 ) ;
V_6 = F_35 ( V_2 , & V_60 , NULL ) ;
if ( V_6 ) {
F_37 ( V_2 , & V_60 ) ;
return V_6 ;
}
F_7 ( & V_13 -> V_41 ) ;
V_13 -> V_41 = F_20 ( V_60 . V_41 ) ;
F_37 ( V_2 , & V_60 ) ;
F_7 ( & V_13 -> V_39 ) ;
return 0 ;
}
int F_54 ( struct V_1 * V_2 ,
struct V_44 * V_46 )
{
int V_6 = 0 ;
F_26 ( & V_46 -> V_13 -> V_54 ) ;
if ( V_46 -> V_47 )
V_6 = F_51 ( V_2 , V_46 -> V_13 , V_46 -> V_27 , NULL ) ;
F_55 ( & V_46 -> V_53 ) ;
F_28 ( & V_46 -> V_13 -> V_54 ) ;
F_55 ( & V_46 -> V_52 ) ;
F_56 ( V_46 ) ;
return V_6 ;
}
void F_57 ( struct V_1 * V_2 ,
struct V_45 * V_27 )
{
struct V_44 * V_46 ;
F_22 (bo_va, &bo->va, bo_list) {
V_46 -> V_50 = false ;
}
}
int F_58 ( struct V_1 * V_2 , struct V_12 * V_13 )
{
unsigned V_116 , V_117 , V_118 ;
int V_6 ;
V_13 -> V_38 = 0 ;
V_13 -> V_41 = NULL ;
V_13 -> V_39 = NULL ;
V_13 -> V_37 = NULL ;
F_59 ( & V_13 -> V_54 ) ;
F_25 ( & V_13 -> V_55 ) ;
V_116 = F_2 ( V_2 ) ;
V_117 = F_1 ( V_2 ) ;
V_118 = V_117 * sizeof( struct V_119 ) ;
V_13 -> V_31 = F_24 ( V_118 , V_19 ) ;
if ( V_13 -> V_31 == NULL ) {
F_60 ( L_5 ) ;
return - V_98 ;
}
V_6 = F_43 ( V_2 , V_116 , V_120 , false ,
V_24 , NULL ,
& V_13 -> V_22 ) ;
if ( V_6 )
return V_6 ;
V_6 = F_29 ( V_2 , V_13 -> V_22 ) ;
if ( V_6 ) {
F_44 ( & V_13 -> V_22 ) ;
V_13 -> V_22 = NULL ;
return V_6 ;
}
return 0 ;
}
void F_61 ( struct V_1 * V_2 , struct V_12 * V_13 )
{
struct V_44 * V_46 , * V_68 ;
int V_8 , V_6 ;
if ( ! F_62 ( & V_13 -> V_55 ) ) {
F_40 ( V_2 -> V_73 , L_6 ) ;
}
F_63 (bo_va, tmp, &vm->va, vm_list) {
F_64 ( & V_46 -> V_53 ) ;
V_6 = F_45 ( V_46 -> V_27 , false ) ;
if ( ! V_6 ) {
F_64 ( & V_46 -> V_52 ) ;
F_42 ( V_46 -> V_27 ) ;
F_56 ( V_46 ) ;
}
}
for ( V_8 = 0 ; V_8 < F_1 ( V_2 ) ; V_8 ++ )
F_44 ( & V_13 -> V_31 [ V_8 ] . V_27 ) ;
F_56 ( V_13 -> V_31 ) ;
F_44 ( & V_13 -> V_22 ) ;
F_7 ( & V_13 -> V_41 ) ;
F_7 ( & V_13 -> V_39 ) ;
F_7 ( & V_13 -> V_37 ) ;
F_65 ( & V_13 -> V_54 ) ;
}
