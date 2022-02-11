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
if ( V_44 -> V_82 && V_44 -> V_82 == V_2 -> V_40 . V_61 [ V_44 -> V_83 ] )
return NULL ;
F_54 ( & V_44 -> V_74 ) ;
for ( V_24 = 1 ; V_24 < V_2 -> V_40 . V_84 ; ++ V_24 ) {
struct V_77 * V_55 = V_2 -> V_40 . V_61 [ V_24 ] ;
if ( V_55 == NULL ) {
V_44 -> V_83 = V_24 ;
F_74 ( V_44 -> V_83 , V_78 ) ;
return NULL ;
}
if ( F_75 ( V_55 , V_79 [ V_55 -> V_78 ] ) ) {
V_79 [ V_55 -> V_78 ] = V_55 ;
V_81 [ V_55 -> V_78 == V_78 ? 0 : 1 ] = V_24 ;
}
}
for ( V_24 = 0 ; V_24 < 2 ; ++ V_24 ) {
if ( V_81 [ V_24 ] ) {
V_44 -> V_83 = V_81 [ V_24 ] ;
F_74 ( V_44 -> V_83 , V_78 ) ;
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
F_54 ( & V_2 -> V_40 . V_61 [ V_44 -> V_83 ] ) ;
V_2 -> V_40 . V_61 [ V_44 -> V_83 ] = F_69 ( V_55 ) ;
F_54 ( & V_44 -> V_55 ) ;
V_44 -> V_55 = F_69 ( V_55 ) ;
F_54 ( & V_44 -> V_82 ) ;
V_44 -> V_82 = F_69 ( V_55 ) ;
}
struct V_45 * F_78 ( struct V_43 * V_44 ,
struct V_85 * V_86 )
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
struct V_85 * V_86 )
{
struct V_45 * V_46 ;
V_46 = F_70 ( sizeof( struct V_45 ) , V_76 ) ;
if ( V_46 == NULL ) {
return NULL ;
}
V_46 -> V_44 = V_44 ;
V_46 -> V_86 = V_86 ;
V_46 -> V_87 = 0 ;
V_46 -> V_88 = 0 ;
V_46 -> V_89 = 0 ;
V_46 -> V_53 = false ;
V_46 -> V_90 = 1 ;
F_80 ( & V_46 -> V_91 ) ;
F_80 ( & V_46 -> V_92 ) ;
F_51 ( & V_44 -> V_59 ) ;
F_81 ( & V_46 -> V_92 , & V_44 -> V_93 ) ;
F_72 ( & V_46 -> V_91 , & V_86 -> V_93 ) ;
F_53 ( & V_44 -> V_59 ) ;
return V_46 ;
}
int F_82 ( struct V_1 * V_2 ,
struct V_45 * V_46 ,
T_1 V_87 ,
T_4 V_89 )
{
T_1 V_47 = F_83 ( V_46 -> V_86 ) ;
T_1 V_88 , V_94 = 0 ;
struct V_43 * V_44 = V_46 -> V_44 ;
struct V_45 * V_57 ;
struct V_95 * V_96 ;
unsigned V_97 ;
if ( V_87 ) {
V_88 = V_87 + V_47 ;
if ( V_87 >= V_88 ) {
return - V_35 ;
}
V_97 = V_88 / V_28 ;
if ( V_97 > V_2 -> V_40 . V_41 ) {
F_42 ( V_2 -> V_51 , L_7 ,
V_97 , V_2 -> V_40 . V_41 ) ;
return - V_35 ;
}
} else {
V_88 = V_97 = 0 ;
}
F_51 ( & V_44 -> V_59 ) ;
V_96 = & V_44 -> V_93 ;
V_94 = 0 ;
F_45 (tmp, &vm->va, vm_list) {
if ( V_46 == V_57 ) {
continue;
}
if ( V_87 >= V_94 && V_88 <= V_57 -> V_87 ) {
break;
}
if ( V_88 > V_57 -> V_87 && V_87 < V_57 -> V_88 ) {
F_42 ( V_2 -> V_51 , L_8 ,
V_46 -> V_86 , ( unsigned ) V_46 -> V_87 , V_57 -> V_86 ,
( unsigned ) V_57 -> V_87 , ( unsigned ) V_57 -> V_88 ) ;
F_53 ( & V_44 -> V_59 ) ;
return - V_35 ;
}
V_94 = V_57 -> V_88 ;
V_96 = & V_57 -> V_92 ;
}
V_46 -> V_87 = V_87 ;
V_46 -> V_88 = V_88 ;
V_46 -> V_89 = V_89 ;
V_46 -> V_53 = false ;
F_84 ( & V_46 -> V_92 , V_96 ) ;
F_53 ( & V_44 -> V_59 ) ;
return 0 ;
}
T_1 F_85 ( struct V_1 * V_2 , T_1 V_31 )
{
T_1 V_98 ;
V_98 = V_2 -> V_5 . V_29 [ V_31 >> V_14 ] ;
V_98 |= V_31 & ( ~ V_99 ) ;
return V_98 ;
}
static T_4 F_86 ( T_4 V_89 )
{
T_4 V_100 = 0 ;
V_100 |= ( V_89 & V_101 ) ? V_102 : 0 ;
V_100 |= ( V_89 & V_103 ) ? V_104 : 0 ;
V_100 |= ( V_89 & V_105 ) ? V_106 : 0 ;
if ( V_89 & V_107 ) {
V_100 |= V_108 ;
V_100 |= ( V_89 & V_109 ) ? V_110 : 0 ;
}
return V_100 ;
}
static int F_87 ( struct V_1 * V_2 ,
struct V_43 * V_44 ,
struct V_67 * V_68 ,
T_1 V_111 , T_1 V_112 )
{
static const T_4 V_113 = V_114 * 8 ;
T_1 V_115 = ~ 0 , V_116 = ~ 0 ;
unsigned V_117 = 0 ;
T_1 V_118 ;
int V_15 ;
V_111 = ( V_111 / V_28 ) >> V_42 ;
V_112 = ( V_112 / V_28 ) >> V_42 ;
for ( V_118 = V_111 ; V_118 <= V_112 ; ++ V_118 ) {
T_1 V_119 , V_120 ;
if ( V_44 -> V_56 [ V_118 ] )
continue;
V_69:
V_15 = F_62 ( V_2 , & V_2 -> V_40 . V_49 ,
& V_44 -> V_56 [ V_118 ] ,
V_114 * 8 ,
V_28 , false ) ;
if ( V_15 == - V_8 ) {
V_15 = F_58 ( V_2 , V_44 ) ;
if ( V_15 )
return V_15 ;
goto V_69;
} else if ( V_15 ) {
return V_15 ;
}
V_119 = V_44 -> V_70 + V_118 * 8 ;
V_120 = F_63 ( V_44 -> V_56 [ V_118 ] ) ;
if ( ( ( V_115 + 8 * V_117 ) != V_119 ) ||
( ( V_116 + V_113 * V_117 ) != V_120 ) ) {
if ( V_117 ) {
F_65 ( V_2 , V_68 , V_115 ,
V_116 , V_117 , V_113 ,
V_102 ) ;
V_117 *= V_114 ;
F_65 ( V_2 , V_68 , V_116 , 0 ,
V_117 , 0 , 0 ) ;
}
V_117 = 1 ;
V_115 = V_119 ;
V_116 = V_120 ;
} else {
++ V_117 ;
}
}
if ( V_117 ) {
F_65 ( V_2 , V_68 , V_115 , V_116 , V_117 ,
V_113 , V_102 ) ;
V_117 *= V_114 ;
F_65 ( V_2 , V_68 , V_116 , 0 ,
V_117 , 0 , 0 ) ;
}
return 0 ;
}
static void F_88 ( struct V_1 * V_2 ,
struct V_43 * V_44 ,
struct V_67 * V_68 ,
T_1 V_111 , T_1 V_112 ,
T_1 V_121 , T_4 V_89 )
{
static const T_1 V_122 = V_114 - 1 ;
T_1 V_123 = ~ 0 , V_124 = ~ 0 ;
unsigned V_117 = 0 ;
T_1 V_31 ;
V_111 = V_111 / V_28 ;
V_112 = V_112 / V_28 ;
for ( V_31 = V_111 ; V_31 < V_112 ; ) {
T_1 V_118 = V_31 >> V_42 ;
unsigned V_125 ;
T_1 V_126 ;
if ( ( V_31 & ~ V_122 ) == ( V_112 & ~ V_122 ) )
V_125 = V_112 - V_31 ;
else
V_125 = V_114 - ( V_31 & V_122 ) ;
V_126 = F_63 ( V_44 -> V_56 [ V_118 ] ) ;
V_126 += ( V_31 & V_122 ) * 8 ;
if ( ( V_123 + 8 * V_117 ) != V_126 ) {
if ( V_117 ) {
F_65 ( V_2 , V_68 , V_123 ,
V_124 , V_117 ,
V_28 ,
V_89 ) ;
}
V_117 = V_125 ;
V_123 = V_126 ;
V_124 = V_121 ;
} else {
V_117 += V_125 ;
}
V_31 += V_125 ;
V_121 += V_125 * V_28 ;
}
if ( V_117 ) {
F_65 ( V_2 , V_68 , V_123 ,
V_124 , V_117 ,
V_28 , V_89 ) ;
}
}
int F_89 ( struct V_1 * V_2 ,
struct V_43 * V_44 ,
struct V_85 * V_86 ,
struct V_127 * V_128 )
{
struct V_67 V_68 ;
struct V_45 * V_46 ;
unsigned V_125 , V_129 , V_130 ;
T_1 V_31 ;
int V_15 ;
if ( V_44 -> V_52 == NULL )
return 0 ;
V_46 = F_78 ( V_44 , V_86 ) ;
if ( V_46 == NULL ) {
F_42 ( V_2 -> V_51 , L_9 , V_86 , V_44 ) ;
return - V_35 ;
}
if ( ! V_46 -> V_87 ) {
F_42 ( V_2 -> V_51 , L_10 ,
V_86 , V_44 ) ;
return - V_35 ;
}
if ( ( V_46 -> V_53 && V_128 ) || ( ! V_46 -> V_53 && V_128 == NULL ) )
return 0 ;
V_46 -> V_89 &= ~ V_101 ;
V_46 -> V_89 &= ~ V_107 ;
if ( V_128 ) {
V_31 = V_128 -> V_111 << V_14 ;
if ( V_128 -> V_131 != V_132 ) {
V_46 -> V_89 |= V_101 ;
V_46 -> V_53 = true ;
}
if ( V_128 -> V_131 == V_133 ) {
V_46 -> V_89 |= V_107 ;
} else {
V_31 += V_2 -> V_40 . V_134 ;
}
} else {
V_31 = 0 ;
V_46 -> V_53 = false ;
}
F_90 ( V_46 ) ;
V_125 = F_91 ( V_86 ) ;
V_129 = ( V_125 >> V_42 ) + 2 ;
V_130 = 64 ;
if ( V_42 > 11 )
V_130 += ( V_125 >> 11 ) * 4 ;
else
V_130 += ( V_125 >> V_42 ) * 4 ;
V_130 += V_125 * 2 ;
V_130 += ( V_129 >> 11 ) * 4 ;
V_130 += V_129 * 2 ;
V_130 += V_129 * 2 * V_114 ;
if ( V_130 > 0xfffff )
return - V_8 ;
V_15 = F_64 ( V_2 , V_71 , & V_68 , NULL , V_130 * 4 ) ;
if ( V_15 )
return V_15 ;
V_68 . V_72 = 0 ;
V_15 = F_87 ( V_2 , V_44 , & V_68 , V_46 -> V_87 , V_46 -> V_88 ) ;
if ( V_15 ) {
F_68 ( V_2 , & V_68 ) ;
return V_15 ;
}
F_88 ( V_2 , V_44 , & V_68 , V_46 -> V_87 , V_46 -> V_88 ,
V_31 , F_86 ( V_46 -> V_89 ) ) ;
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
if ( V_46 -> V_87 ) {
V_15 = F_89 ( V_2 , V_46 -> V_44 , V_46 -> V_86 , NULL ) ;
}
F_53 ( & V_2 -> V_40 . V_58 ) ;
F_93 ( & V_46 -> V_92 ) ;
F_53 ( & V_46 -> V_44 -> V_59 ) ;
F_93 ( & V_46 -> V_91 ) ;
F_49 ( V_46 ) ;
return V_15 ;
}
void F_94 ( struct V_1 * V_2 ,
struct V_85 * V_86 )
{
struct V_45 * V_46 ;
F_45 (bo_va, &bo->va, bo_list) {
V_46 -> V_53 = false ;
}
}
void F_95 ( struct V_1 * V_2 , struct V_43 * V_44 )
{
V_44 -> V_83 = 0 ;
V_44 -> V_55 = NULL ;
V_44 -> V_74 = NULL ;
V_44 -> V_82 = NULL ;
F_96 ( & V_44 -> V_59 ) ;
F_80 ( & V_44 -> V_54 ) ;
F_80 ( & V_44 -> V_93 ) ;
}
void F_97 ( struct V_1 * V_2 , struct V_43 * V_44 )
{
struct V_45 * V_46 , * V_57 ;
int V_15 ;
F_51 ( & V_2 -> V_40 . V_58 ) ;
F_51 ( & V_44 -> V_59 ) ;
F_46 ( V_2 , V_44 ) ;
F_53 ( & V_2 -> V_40 . V_58 ) ;
if ( ! F_59 ( & V_44 -> V_93 ) ) {
F_42 ( V_2 -> V_51 , L_11 ) ;
}
F_52 (bo_va, tmp, &vm->va, vm_list) {
F_47 ( & V_46 -> V_92 ) ;
V_15 = F_11 ( V_46 -> V_86 , false ) ;
if ( ! V_15 ) {
F_47 ( & V_46 -> V_91 ) ;
F_14 ( V_46 -> V_86 ) ;
F_49 ( V_46 ) ;
}
}
F_54 ( & V_44 -> V_55 ) ;
F_54 ( & V_44 -> V_74 ) ;
F_54 ( & V_44 -> V_82 ) ;
F_53 ( & V_44 -> V_59 ) ;
}
