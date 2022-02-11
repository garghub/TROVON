int F_1 ( struct V_1 * V_2 )
{
void * V_3 ;
V_3 = F_2 ( V_2 -> V_4 , V_2 -> V_5 . V_6 ,
& V_2 -> V_5 . V_7 ) ;
if ( V_3 == NULL ) {
return - V_8 ;
}
#ifdef F_3
if ( V_2 -> V_9 == V_10 || V_2 -> V_9 == V_11 ||
V_2 -> V_9 == V_12 || V_2 -> V_9 == V_13 ) {
F_4 ( ( unsigned long ) V_3 ,
V_2 -> V_5 . V_6 >> V_14 ) ;
}
#endif
V_2 -> V_5 . V_3 = V_3 ;
memset ( ( void * ) V_2 -> V_5 . V_3 , 0 , V_2 -> V_5 . V_6 ) ;
return 0 ;
}
void F_5 ( struct V_1 * V_2 )
{
if ( V_2 -> V_5 . V_3 == NULL ) {
return;
}
#ifdef F_3
if ( V_2 -> V_9 == V_10 || V_2 -> V_9 == V_11 ||
V_2 -> V_9 == V_12 || V_2 -> V_9 == V_13 ) {
F_6 ( ( unsigned long ) V_2 -> V_5 . V_3 ,
V_2 -> V_5 . V_6 >> V_14 ) ;
}
#endif
F_7 ( V_2 -> V_4 , V_2 -> V_5 . V_6 ,
( void * ) V_2 -> V_5 . V_3 ,
V_2 -> V_5 . V_7 ) ;
V_2 -> V_5 . V_3 = NULL ;
V_2 -> V_5 . V_7 = 0 ;
}
int F_8 ( struct V_1 * V_2 )
{
int V_15 ;
if ( V_2 -> V_5 . V_16 == NULL ) {
V_15 = F_9 ( V_2 , V_2 -> V_5 . V_6 ,
V_17 , true , V_18 ,
NULL , & V_2 -> V_5 . V_16 ) ;
if ( V_15 ) {
return V_15 ;
}
}
return 0 ;
}
int F_10 ( struct V_1 * V_2 )
{
T_1 V_19 ;
int V_15 ;
V_15 = F_11 ( V_2 -> V_5 . V_16 , false ) ;
if ( F_12 ( V_15 != 0 ) )
return V_15 ;
V_15 = F_13 ( V_2 -> V_5 . V_16 ,
V_18 , & V_19 ) ;
if ( V_15 ) {
F_14 ( V_2 -> V_5 . V_16 ) ;
return V_15 ;
}
V_15 = F_15 ( V_2 -> V_5 . V_16 , & V_2 -> V_5 . V_3 ) ;
if ( V_15 )
F_16 ( V_2 -> V_5 . V_16 ) ;
F_14 ( V_2 -> V_5 . V_16 ) ;
V_2 -> V_5 . V_7 = V_19 ;
return V_15 ;
}
void F_17 ( struct V_1 * V_2 )
{
int V_15 ;
if ( V_2 -> V_5 . V_16 == NULL ) {
return;
}
V_15 = F_11 ( V_2 -> V_5 . V_16 , false ) ;
if ( F_18 ( V_15 == 0 ) ) {
F_19 ( V_2 -> V_5 . V_16 ) ;
F_16 ( V_2 -> V_5 . V_16 ) ;
F_14 ( V_2 -> V_5 . V_16 ) ;
V_2 -> V_5 . V_3 = NULL ;
}
}
void F_20 ( struct V_1 * V_2 )
{
if ( V_2 -> V_5 . V_16 == NULL ) {
return;
}
F_21 ( & V_2 -> V_5 . V_16 ) ;
}
void F_22 ( struct V_1 * V_2 , unsigned V_20 ,
int V_21 )
{
unsigned V_22 ;
unsigned V_23 ;
int V_24 , V_25 ;
T_2 V_26 ;
if ( ! V_2 -> V_5 . V_27 ) {
F_23 ( 1 , L_1 ) ;
return;
}
V_22 = V_20 / V_28 ;
V_23 = V_22 / ( V_17 / V_28 ) ;
for ( V_24 = 0 ; V_24 < V_21 ; V_24 ++ , V_23 ++ ) {
if ( V_2 -> V_5 . V_21 [ V_23 ] ) {
V_2 -> V_5 . V_21 [ V_23 ] = NULL ;
V_2 -> V_5 . V_29 [ V_23 ] = V_2 -> V_30 . V_31 ;
V_26 = V_2 -> V_5 . V_29 [ V_23 ] ;
for ( V_25 = 0 ; V_25 < ( V_17 / V_28 ) ; V_25 ++ , V_22 ++ ) {
if ( V_2 -> V_5 . V_3 ) {
F_24 ( V_2 , V_22 , V_26 ) ;
}
V_26 += V_28 ;
}
}
}
F_25 () ;
F_26 ( V_2 ) ;
}
int F_27 ( struct V_1 * V_2 , unsigned V_20 ,
int V_21 , struct V_32 * * V_33 , T_3 * V_34 )
{
unsigned V_22 ;
unsigned V_23 ;
T_1 V_26 ;
int V_24 , V_25 ;
if ( ! V_2 -> V_5 . V_27 ) {
F_23 ( 1 , L_2 ) ;
return - V_35 ;
}
V_22 = V_20 / V_28 ;
V_23 = V_22 / ( V_17 / V_28 ) ;
for ( V_24 = 0 ; V_24 < V_21 ; V_24 ++ , V_23 ++ ) {
V_2 -> V_5 . V_29 [ V_23 ] = V_34 [ V_24 ] ;
V_2 -> V_5 . V_21 [ V_23 ] = V_33 [ V_24 ] ;
if ( V_2 -> V_5 . V_3 ) {
V_26 = V_2 -> V_5 . V_29 [ V_23 ] ;
for ( V_25 = 0 ; V_25 < ( V_17 / V_28 ) ; V_25 ++ , V_22 ++ ) {
F_24 ( V_2 , V_22 , V_26 ) ;
V_26 += V_28 ;
}
}
}
F_25 () ;
F_26 ( V_2 ) ;
return 0 ;
}
void F_28 ( struct V_1 * V_2 )
{
int V_24 , V_25 , V_22 ;
T_2 V_26 ;
if ( ! V_2 -> V_5 . V_3 ) {
return;
}
for ( V_24 = 0 , V_22 = 0 ; V_24 < V_2 -> V_5 . V_36 ; V_24 ++ ) {
V_26 = V_2 -> V_5 . V_29 [ V_24 ] ;
for ( V_25 = 0 ; V_25 < ( V_17 / V_28 ) ; V_25 ++ , V_22 ++ ) {
F_24 ( V_2 , V_22 , V_26 ) ;
V_26 += V_28 ;
}
}
F_25 () ;
F_26 ( V_2 ) ;
}
int F_29 ( struct V_1 * V_2 )
{
int V_15 , V_24 ;
if ( V_2 -> V_5 . V_21 ) {
return 0 ;
}
if ( V_17 < V_28 ) {
F_30 ( L_3 ) ;
return - V_35 ;
}
V_15 = F_31 ( V_2 ) ;
if ( V_15 )
return V_15 ;
V_2 -> V_5 . V_36 = V_2 -> V_37 . V_38 / V_17 ;
V_2 -> V_5 . V_39 = V_2 -> V_37 . V_38 / V_28 ;
F_32 ( L_4 ,
V_2 -> V_5 . V_36 , V_2 -> V_5 . V_39 ) ;
V_2 -> V_5 . V_21 = F_33 ( sizeof( void * ) * V_2 -> V_5 . V_36 ) ;
if ( V_2 -> V_5 . V_21 == NULL ) {
F_34 ( V_2 ) ;
return - V_8 ;
}
V_2 -> V_5 . V_29 = F_33 ( sizeof( T_3 ) *
V_2 -> V_5 . V_36 ) ;
if ( V_2 -> V_5 . V_29 == NULL ) {
F_34 ( V_2 ) ;
return - V_8 ;
}
for ( V_24 = 0 ; V_24 < V_2 -> V_5 . V_36 ; V_24 ++ ) {
V_2 -> V_5 . V_29 [ V_24 ] = V_2 -> V_30 . V_31 ;
}
return 0 ;
}
void F_34 ( struct V_1 * V_2 )
{
if ( V_2 -> V_5 . V_21 && V_2 -> V_5 . V_29 && V_2 -> V_5 . V_27 ) {
F_22 ( V_2 , 0 , V_2 -> V_5 . V_36 ) ;
}
V_2 -> V_5 . V_27 = false ;
F_35 ( V_2 -> V_5 . V_21 ) ;
F_35 ( V_2 -> V_5 . V_29 ) ;
V_2 -> V_5 . V_21 = NULL ;
V_2 -> V_5 . V_29 = NULL ;
F_36 ( V_2 ) ;
}
static unsigned F_37 ( struct V_1 * V_2 )
{
return V_2 -> V_40 . V_41 >> V_42 ;
}
static unsigned F_38 ( struct V_1 * V_2 )
{
return F_39 ( F_37 ( V_2 ) * 8 ) ;
}
int F_40 ( struct V_1 * V_2 )
{
struct V_43 * V_44 ;
struct V_45 * V_46 ;
int V_15 ;
unsigned V_47 ;
if ( ! V_2 -> V_40 . V_48 ) {
V_47 = F_38 ( V_2 ) ;
V_47 += V_2 -> V_40 . V_41 * 8 ;
V_47 *= 2 ;
V_15 = F_41 ( V_2 , & V_2 -> V_40 . V_49 ,
F_39 ( V_47 ) ,
V_50 ,
V_18 ) ;
if ( V_15 ) {
F_42 ( V_2 -> V_51 , L_5 ,
( V_2 -> V_40 . V_41 * 8 ) >> 10 ) ;
return V_15 ;
}
V_15 = F_43 ( V_2 ) ;
if ( V_15 )
return V_15 ;
V_2 -> V_40 . V_48 = true ;
V_15 = F_44 ( V_2 , & V_2 -> V_40 . V_49 ) ;
if ( V_15 )
return V_15 ;
}
F_45 (vm, &rdev->vm_manager.lru_vm, list) {
if ( V_44 -> V_52 == NULL )
continue;
F_45 (bo_va, &vm->va, vm_list) {
V_46 -> V_53 = false ;
}
}
return 0 ;
}
static void F_46 ( struct V_1 * V_2 ,
struct V_43 * V_44 )
{
struct V_45 * V_46 ;
int V_24 ;
if ( ! V_44 -> V_52 )
return;
F_47 ( & V_44 -> V_54 ) ;
F_48 ( V_2 , & V_44 -> V_52 , V_44 -> V_55 ) ;
F_45 (bo_va, &vm->va, vm_list) {
V_46 -> V_53 = false ;
}
if ( V_44 -> V_56 == NULL )
return;
for ( V_24 = 0 ; V_24 < F_37 ( V_2 ) ; V_24 ++ )
F_48 ( V_2 , & V_44 -> V_56 [ V_24 ] , V_44 -> V_55 ) ;
F_49 ( V_44 -> V_56 ) ;
}
void F_50 ( struct V_1 * V_2 )
{
struct V_43 * V_44 , * V_57 ;
int V_24 ;
if ( ! V_2 -> V_40 . V_48 )
return;
F_51 ( & V_2 -> V_40 . V_58 ) ;
F_52 (vm, tmp, &rdev->vm_manager.lru_vm, list) {
F_51 ( & V_44 -> V_59 ) ;
F_46 ( V_2 , V_44 ) ;
F_53 ( & V_44 -> V_59 ) ;
}
for ( V_24 = 0 ; V_24 < V_60 ; ++ V_24 ) {
F_54 ( & V_2 -> V_40 . V_61 [ V_24 ] ) ;
}
F_55 ( V_2 ) ;
F_53 ( & V_2 -> V_40 . V_58 ) ;
F_56 ( V_2 , & V_2 -> V_40 . V_49 ) ;
F_57 ( V_2 , & V_2 -> V_40 . V_49 ) ;
V_2 -> V_40 . V_48 = false ;
}
static int F_58 ( struct V_1 * V_2 , struct V_43 * V_44 )
{
struct V_43 * V_62 ;
if ( F_59 ( & V_2 -> V_40 . V_63 ) )
return - V_8 ;
V_62 = F_60 ( & V_2 -> V_40 . V_63 ,
struct V_43 , V_54 ) ;
if ( V_62 == V_44 )
return - V_8 ;
F_51 ( & V_62 -> V_59 ) ;
F_46 ( V_2 , V_62 ) ;
F_53 ( & V_62 -> V_59 ) ;
return 0 ;
}
int F_61 ( struct V_1 * V_2 , struct V_43 * V_44 )
{
unsigned V_64 , V_65 , V_66 ;
struct V_67 V_68 ;
int V_15 ;
if ( V_44 == NULL ) {
return - V_35 ;
}
if ( V_44 -> V_52 != NULL ) {
return 0 ;
}
V_64 = F_38 ( V_2 ) ;
V_65 = F_37 ( V_2 ) ;
V_69:
V_15 = F_62 ( V_2 , & V_2 -> V_40 . V_49 ,
& V_44 -> V_52 , V_64 ,
V_50 , false ) ;
if ( V_15 == - V_8 ) {
V_15 = F_58 ( V_2 , V_44 ) ;
if ( V_15 )
return V_15 ;
goto V_69;
} else if ( V_15 ) {
return V_15 ;
}
V_44 -> V_70 = F_63 ( V_44 -> V_52 ) ;
V_15 = F_64 ( V_2 , V_71 , & V_68 ,
NULL , V_65 * 2 + 64 ) ;
if ( V_15 ) {
F_48 ( V_2 , & V_44 -> V_52 , V_44 -> V_55 ) ;
return V_15 ;
}
V_68 . V_72 = 0 ;
F_65 ( V_2 , & V_68 , V_44 -> V_70 ,
0 , V_65 , 0 , 0 ) ;
F_66 ( V_68 . V_73 , V_44 -> V_55 ) ;
V_15 = F_67 ( V_2 , & V_68 , NULL ) ;
if ( V_15 ) {
F_68 ( V_2 , & V_68 ) ;
F_48 ( V_2 , & V_44 -> V_52 , V_44 -> V_55 ) ;
return V_15 ;
}
F_54 ( & V_44 -> V_55 ) ;
V_44 -> V_55 = F_69 ( V_68 . V_55 ) ;
F_68 ( V_2 , & V_68 ) ;
F_54 ( & V_44 -> V_74 ) ;
V_66 = F_37 ( V_2 ) * sizeof( struct V_75 * ) ;
V_44 -> V_56 = F_70 ( V_66 , V_76 ) ;
if ( V_44 -> V_56 == NULL ) {
F_30 ( L_6 ) ;
F_48 ( V_2 , & V_44 -> V_52 , V_44 -> V_55 ) ;
return - V_8 ;
}
return 0 ;
}
void F_71 ( struct V_1 * V_2 , struct V_43 * V_44 )
{
F_47 ( & V_44 -> V_54 ) ;
F_72 ( & V_44 -> V_54 , & V_2 -> V_40 . V_63 ) ;
}
struct V_77 * F_73 ( struct V_1 * V_2 ,
struct V_43 * V_44 , int V_78 )
{
struct V_77 * V_79 [ V_80 ] = {} ;
unsigned V_81 [ 2 ] = {} ;
unsigned V_24 ;
if ( V_44 -> V_55 && V_44 -> V_55 == V_2 -> V_40 . V_61 [ V_44 -> V_82 ] )
return NULL ;
F_54 ( & V_44 -> V_74 ) ;
for ( V_24 = 1 ; V_24 < V_2 -> V_40 . V_83 ; ++ V_24 ) {
struct V_77 * V_55 = V_2 -> V_40 . V_61 [ V_24 ] ;
if ( V_55 == NULL ) {
V_44 -> V_82 = V_24 ;
return NULL ;
}
if ( F_74 ( V_55 , V_79 [ V_55 -> V_78 ] ) ) {
V_79 [ V_55 -> V_78 ] = V_55 ;
V_81 [ V_55 -> V_78 == V_78 ? 0 : 1 ] = V_24 ;
}
}
for ( V_24 = 0 ; V_24 < 2 ; ++ V_24 ) {
if ( V_81 [ V_24 ] ) {
V_44 -> V_82 = V_81 [ V_24 ] ;
F_75 ( V_44 -> V_82 , V_78 ) ;
return V_2 -> V_40 . V_61 [ V_81 [ V_24 ] ] ;
}
}
F_76 () ;
return NULL ;
}
void F_77 ( struct V_1 * V_2 ,
struct V_43 * V_44 ,
struct V_77 * V_55 )
{
F_54 ( & V_2 -> V_40 . V_61 [ V_44 -> V_82 ] ) ;
V_2 -> V_40 . V_61 [ V_44 -> V_82 ] = F_69 ( V_55 ) ;
F_54 ( & V_44 -> V_55 ) ;
V_44 -> V_55 = F_69 ( V_55 ) ;
}
struct V_45 * F_78 ( struct V_43 * V_44 ,
struct V_84 * V_85 )
{
struct V_45 * V_46 ;
F_45 (bo_va, &bo->va, bo_list) {
if ( V_46 -> V_44 == V_44 ) {
return V_46 ;
}
}
return NULL ;
}
struct V_45 * F_79 ( struct V_1 * V_2 ,
struct V_43 * V_44 ,
struct V_84 * V_85 )
{
struct V_45 * V_46 ;
V_46 = F_70 ( sizeof( struct V_45 ) , V_76 ) ;
if ( V_46 == NULL ) {
return NULL ;
}
V_46 -> V_44 = V_44 ;
V_46 -> V_85 = V_85 ;
V_46 -> V_86 = 0 ;
V_46 -> V_87 = 0 ;
V_46 -> V_88 = 0 ;
V_46 -> V_53 = false ;
V_46 -> V_89 = 1 ;
F_80 ( & V_46 -> V_90 ) ;
F_80 ( & V_46 -> V_91 ) ;
F_51 ( & V_44 -> V_59 ) ;
F_81 ( & V_46 -> V_91 , & V_44 -> V_92 ) ;
F_72 ( & V_46 -> V_90 , & V_85 -> V_92 ) ;
F_53 ( & V_44 -> V_59 ) ;
return V_46 ;
}
int F_82 ( struct V_1 * V_2 ,
struct V_45 * V_46 ,
T_1 V_86 ,
T_4 V_88 )
{
T_1 V_47 = F_83 ( V_46 -> V_85 ) ;
T_1 V_87 , V_93 = 0 ;
struct V_43 * V_44 = V_46 -> V_44 ;
struct V_45 * V_57 ;
struct V_94 * V_95 ;
unsigned V_96 ;
if ( V_86 ) {
V_87 = V_86 + V_47 ;
if ( V_86 >= V_87 ) {
return - V_35 ;
}
V_96 = V_87 / V_28 ;
if ( V_96 > V_2 -> V_40 . V_41 ) {
F_42 ( V_2 -> V_51 , L_7 ,
V_96 , V_2 -> V_40 . V_41 ) ;
return - V_35 ;
}
} else {
V_87 = V_96 = 0 ;
}
F_51 ( & V_44 -> V_59 ) ;
V_95 = & V_44 -> V_92 ;
V_93 = 0 ;
F_45 (tmp, &vm->va, vm_list) {
if ( V_46 == V_57 ) {
continue;
}
if ( V_86 >= V_93 && V_87 <= V_57 -> V_86 ) {
break;
}
if ( V_87 > V_57 -> V_86 && V_86 < V_57 -> V_87 ) {
F_42 ( V_2 -> V_51 , L_8 ,
V_46 -> V_85 , ( unsigned ) V_46 -> V_86 , V_57 -> V_85 ,
( unsigned ) V_57 -> V_86 , ( unsigned ) V_57 -> V_87 ) ;
F_53 ( & V_44 -> V_59 ) ;
return - V_35 ;
}
V_93 = V_57 -> V_87 ;
V_95 = & V_57 -> V_91 ;
}
V_46 -> V_86 = V_86 ;
V_46 -> V_87 = V_87 ;
V_46 -> V_88 = V_88 ;
V_46 -> V_53 = false ;
F_84 ( & V_46 -> V_91 , V_95 ) ;
F_53 ( & V_44 -> V_59 ) ;
return 0 ;
}
T_1 F_85 ( struct V_1 * V_2 , T_1 V_31 )
{
T_1 V_97 ;
V_97 = V_2 -> V_5 . V_29 [ V_31 >> V_14 ] ;
V_97 |= V_31 & ( ~ V_98 ) ;
return V_97 ;
}
static T_4 F_86 ( T_4 V_88 )
{
T_4 V_99 = 0 ;
V_99 |= ( V_88 & V_100 ) ? V_101 : 0 ;
V_99 |= ( V_88 & V_102 ) ? V_103 : 0 ;
V_99 |= ( V_88 & V_104 ) ? V_105 : 0 ;
if ( V_88 & V_106 ) {
V_99 |= V_107 ;
V_99 |= ( V_88 & V_108 ) ? V_109 : 0 ;
}
return V_99 ;
}
static int F_87 ( struct V_1 * V_2 ,
struct V_43 * V_44 ,
struct V_67 * V_68 ,
T_1 V_110 , T_1 V_111 )
{
static const T_4 V_112 = V_113 * 8 ;
T_1 V_114 = ~ 0 , V_115 = ~ 0 ;
unsigned V_116 = 0 ;
T_1 V_117 ;
int V_15 ;
V_110 = ( V_110 / V_28 ) >> V_42 ;
V_111 = ( V_111 / V_28 ) >> V_42 ;
for ( V_117 = V_110 ; V_117 <= V_111 ; ++ V_117 ) {
T_1 V_118 , V_119 ;
if ( V_44 -> V_56 [ V_117 ] )
continue;
V_69:
V_15 = F_62 ( V_2 , & V_2 -> V_40 . V_49 ,
& V_44 -> V_56 [ V_117 ] ,
V_113 * 8 ,
V_28 , false ) ;
if ( V_15 == - V_8 ) {
V_15 = F_58 ( V_2 , V_44 ) ;
if ( V_15 )
return V_15 ;
goto V_69;
} else if ( V_15 ) {
return V_15 ;
}
V_118 = V_44 -> V_70 + V_117 * 8 ;
V_119 = F_63 ( V_44 -> V_56 [ V_117 ] ) ;
if ( ( ( V_114 + 8 * V_116 ) != V_118 ) ||
( ( V_115 + V_112 * V_116 ) != V_119 ) ) {
if ( V_116 ) {
F_65 ( V_2 , V_68 , V_114 ,
V_115 , V_116 , V_112 ,
V_101 ) ;
V_116 *= V_113 ;
F_65 ( V_2 , V_68 , V_115 , 0 ,
V_116 , 0 , 0 ) ;
}
V_116 = 1 ;
V_114 = V_118 ;
V_115 = V_119 ;
} else {
++ V_116 ;
}
}
if ( V_116 ) {
F_65 ( V_2 , V_68 , V_114 , V_115 , V_116 ,
V_112 , V_101 ) ;
V_116 *= V_113 ;
F_65 ( V_2 , V_68 , V_115 , 0 ,
V_116 , 0 , 0 ) ;
}
return 0 ;
}
static void F_88 ( struct V_1 * V_2 ,
struct V_43 * V_44 ,
struct V_67 * V_68 ,
T_1 V_110 , T_1 V_111 ,
T_1 V_120 , T_4 V_88 )
{
static const T_1 V_121 = V_113 - 1 ;
T_1 V_122 = ~ 0 , V_123 = ~ 0 ;
unsigned V_116 = 0 ;
T_1 V_31 ;
V_110 = V_110 / V_28 ;
V_111 = V_111 / V_28 ;
for ( V_31 = V_110 ; V_31 < V_111 ; ) {
T_1 V_117 = V_31 >> V_42 ;
unsigned V_124 ;
T_1 V_125 ;
if ( ( V_31 & ~ V_121 ) == ( V_111 & ~ V_121 ) )
V_124 = V_111 - V_31 ;
else
V_124 = V_113 - ( V_31 & V_121 ) ;
V_125 = F_63 ( V_44 -> V_56 [ V_117 ] ) ;
V_125 += ( V_31 & V_121 ) * 8 ;
if ( ( V_122 + 8 * V_116 ) != V_125 ) {
if ( V_116 ) {
F_65 ( V_2 , V_68 , V_122 ,
V_123 , V_116 ,
V_28 ,
V_88 ) ;
}
V_116 = V_124 ;
V_122 = V_125 ;
V_123 = V_120 ;
} else {
V_116 += V_124 ;
}
V_31 += V_124 ;
V_120 += V_124 * V_28 ;
}
if ( V_116 ) {
F_65 ( V_2 , V_68 , V_122 ,
V_123 , V_116 ,
V_28 , V_88 ) ;
}
}
int F_89 ( struct V_1 * V_2 ,
struct V_43 * V_44 ,
struct V_84 * V_85 ,
struct V_126 * V_127 )
{
struct V_67 V_68 ;
struct V_45 * V_46 ;
unsigned V_124 , V_128 , V_129 ;
T_1 V_31 ;
int V_15 ;
if ( V_44 -> V_52 == NULL )
return 0 ;
V_46 = F_78 ( V_44 , V_85 ) ;
if ( V_46 == NULL ) {
F_42 ( V_2 -> V_51 , L_9 , V_85 , V_44 ) ;
return - V_35 ;
}
if ( ! V_46 -> V_86 ) {
F_42 ( V_2 -> V_51 , L_10 ,
V_85 , V_44 ) ;
return - V_35 ;
}
if ( ( V_46 -> V_53 && V_127 ) || ( ! V_46 -> V_53 && V_127 == NULL ) )
return 0 ;
V_46 -> V_88 &= ~ V_100 ;
V_46 -> V_88 &= ~ V_106 ;
if ( V_127 ) {
V_31 = V_127 -> V_110 << V_14 ;
if ( V_127 -> V_130 != V_131 ) {
V_46 -> V_88 |= V_100 ;
V_46 -> V_53 = true ;
}
if ( V_127 -> V_130 == V_132 ) {
V_46 -> V_88 |= V_106 ;
} else {
V_31 += V_2 -> V_40 . V_133 ;
}
} else {
V_31 = 0 ;
V_46 -> V_53 = false ;
}
F_90 ( V_46 ) ;
V_124 = F_91 ( V_85 ) ;
V_128 = ( V_124 >> V_42 ) + 2 ;
V_129 = 64 ;
if ( V_42 > 11 )
V_129 += ( V_124 >> 11 ) * 4 ;
else
V_129 += ( V_124 >> V_42 ) * 4 ;
V_129 += V_124 * 2 ;
V_129 += ( V_128 >> 11 ) * 4 ;
V_129 += V_128 * 2 ;
V_129 += V_128 * 2 * V_113 ;
if ( V_129 > 0xfffff )
return - V_8 ;
V_15 = F_64 ( V_2 , V_71 , & V_68 , NULL , V_129 * 4 ) ;
if ( V_15 )
return V_15 ;
V_68 . V_72 = 0 ;
V_15 = F_87 ( V_2 , V_44 , & V_68 , V_46 -> V_86 , V_46 -> V_87 ) ;
if ( V_15 ) {
F_68 ( V_2 , & V_68 ) ;
return V_15 ;
}
F_88 ( V_2 , V_44 , & V_68 , V_46 -> V_86 , V_46 -> V_87 ,
V_31 , F_86 ( V_46 -> V_88 ) ) ;
F_66 ( V_68 . V_73 , V_44 -> V_55 ) ;
V_15 = F_67 ( V_2 , & V_68 , NULL ) ;
if ( V_15 ) {
F_68 ( V_2 , & V_68 ) ;
return V_15 ;
}
F_54 ( & V_44 -> V_55 ) ;
V_44 -> V_55 = F_69 ( V_68 . V_55 ) ;
F_68 ( V_2 , & V_68 ) ;
F_54 ( & V_44 -> V_74 ) ;
return 0 ;
}
int F_92 ( struct V_1 * V_2 ,
struct V_45 * V_46 )
{
int V_15 = 0 ;
F_51 ( & V_2 -> V_40 . V_58 ) ;
F_51 ( & V_46 -> V_44 -> V_59 ) ;
if ( V_46 -> V_86 ) {
V_15 = F_89 ( V_2 , V_46 -> V_44 , V_46 -> V_85 , NULL ) ;
}
F_53 ( & V_2 -> V_40 . V_58 ) ;
F_93 ( & V_46 -> V_91 ) ;
F_53 ( & V_46 -> V_44 -> V_59 ) ;
F_93 ( & V_46 -> V_90 ) ;
F_49 ( V_46 ) ;
return V_15 ;
}
void F_94 ( struct V_1 * V_2 ,
struct V_84 * V_85 )
{
struct V_45 * V_46 ;
F_45 (bo_va, &bo->va, bo_list) {
V_46 -> V_53 = false ;
}
}
void F_95 ( struct V_1 * V_2 , struct V_43 * V_44 )
{
V_44 -> V_82 = 0 ;
V_44 -> V_55 = NULL ;
F_96 ( & V_44 -> V_59 ) ;
F_80 ( & V_44 -> V_54 ) ;
F_80 ( & V_44 -> V_92 ) ;
}
void F_97 ( struct V_1 * V_2 , struct V_43 * V_44 )
{
struct V_45 * V_46 , * V_57 ;
int V_15 ;
F_51 ( & V_2 -> V_40 . V_58 ) ;
F_51 ( & V_44 -> V_59 ) ;
F_46 ( V_2 , V_44 ) ;
F_53 ( & V_2 -> V_40 . V_58 ) ;
if ( ! F_59 ( & V_44 -> V_92 ) ) {
F_42 ( V_2 -> V_51 , L_11 ) ;
}
F_52 (bo_va, tmp, &vm->va, vm_list) {
F_47 ( & V_46 -> V_91 ) ;
V_15 = F_11 ( V_46 -> V_85 , false ) ;
if ( ! V_15 ) {
F_47 ( & V_46 -> V_90 ) ;
F_14 ( V_46 -> V_85 ) ;
F_49 ( V_46 ) ;
}
}
F_54 ( & V_44 -> V_55 ) ;
F_54 ( & V_44 -> V_74 ) ;
F_53 ( & V_44 -> V_59 ) ;
}
