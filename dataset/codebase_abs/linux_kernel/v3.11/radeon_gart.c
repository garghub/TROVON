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
unsigned V_64 , V_65 ;
T_2 * V_66 ;
int V_15 ;
if ( V_44 == NULL ) {
return - V_35 ;
}
if ( V_44 -> V_52 != NULL ) {
return 0 ;
}
V_67:
V_64 = F_38 ( V_2 ) ;
V_15 = F_62 ( V_2 , & V_2 -> V_40 . V_49 ,
& V_44 -> V_52 , V_64 ,
V_50 , false ) ;
if ( V_15 == - V_8 ) {
V_15 = F_58 ( V_2 , V_44 ) ;
if ( V_15 )
return V_15 ;
goto V_67;
} else if ( V_15 ) {
return V_15 ;
}
V_44 -> V_68 = F_63 ( V_44 -> V_52 ) ;
V_66 = F_64 ( V_44 -> V_52 ) ;
memset ( V_66 , 0 , V_64 ) ;
V_65 = F_37 ( V_2 ) * sizeof( struct V_69 * ) ;
V_44 -> V_56 = F_65 ( V_65 , V_70 ) ;
if ( V_44 -> V_56 == NULL ) {
F_30 ( L_6 ) ;
F_48 ( V_2 , & V_44 -> V_52 , V_44 -> V_55 ) ;
return - V_8 ;
}
return 0 ;
}
void F_66 ( struct V_1 * V_2 , struct V_43 * V_44 )
{
F_47 ( & V_44 -> V_54 ) ;
F_67 ( & V_44 -> V_54 , & V_2 -> V_40 . V_63 ) ;
}
struct V_71 * F_68 ( struct V_1 * V_2 ,
struct V_43 * V_44 , int V_72 )
{
struct V_71 * V_73 [ V_74 ] = {} ;
unsigned V_75 [ 2 ] = {} ;
unsigned V_24 ;
if ( V_44 -> V_55 && V_44 -> V_55 == V_2 -> V_40 . V_61 [ V_44 -> V_76 ] )
return NULL ;
F_54 ( & V_44 -> V_77 ) ;
for ( V_24 = 1 ; V_24 < V_2 -> V_40 . V_78 ; ++ V_24 ) {
struct V_71 * V_55 = V_2 -> V_40 . V_61 [ V_24 ] ;
if ( V_55 == NULL ) {
V_44 -> V_76 = V_24 ;
return NULL ;
}
if ( F_69 ( V_55 , V_73 [ V_55 -> V_72 ] ) ) {
V_73 [ V_55 -> V_72 ] = V_55 ;
V_75 [ V_55 -> V_72 == V_72 ? 0 : 1 ] = V_24 ;
}
}
for ( V_24 = 0 ; V_24 < 2 ; ++ V_24 ) {
if ( V_75 [ V_24 ] ) {
V_44 -> V_76 = V_75 [ V_24 ] ;
return V_2 -> V_40 . V_61 [ V_75 [ V_24 ] ] ;
}
}
F_70 () ;
return NULL ;
}
void F_71 ( struct V_1 * V_2 ,
struct V_43 * V_44 ,
struct V_71 * V_55 )
{
F_54 ( & V_2 -> V_40 . V_61 [ V_44 -> V_76 ] ) ;
V_2 -> V_40 . V_61 [ V_44 -> V_76 ] = F_72 ( V_55 ) ;
F_54 ( & V_44 -> V_55 ) ;
V_44 -> V_55 = F_72 ( V_55 ) ;
}
struct V_45 * F_73 ( struct V_43 * V_44 ,
struct V_79 * V_80 )
{
struct V_45 * V_46 ;
F_45 (bo_va, &bo->va, bo_list) {
if ( V_46 -> V_44 == V_44 ) {
return V_46 ;
}
}
return NULL ;
}
struct V_45 * F_74 ( struct V_1 * V_2 ,
struct V_43 * V_44 ,
struct V_79 * V_80 )
{
struct V_45 * V_46 ;
V_46 = F_65 ( sizeof( struct V_45 ) , V_70 ) ;
if ( V_46 == NULL ) {
return NULL ;
}
V_46 -> V_44 = V_44 ;
V_46 -> V_80 = V_80 ;
V_46 -> V_81 = 0 ;
V_46 -> V_82 = 0 ;
V_46 -> V_83 = 0 ;
V_46 -> V_53 = false ;
V_46 -> V_84 = 1 ;
F_75 ( & V_46 -> V_85 ) ;
F_75 ( & V_46 -> V_86 ) ;
F_51 ( & V_44 -> V_59 ) ;
F_76 ( & V_46 -> V_86 , & V_44 -> V_87 ) ;
F_67 ( & V_46 -> V_85 , & V_80 -> V_87 ) ;
F_53 ( & V_44 -> V_59 ) ;
return V_46 ;
}
int F_77 ( struct V_1 * V_2 ,
struct V_45 * V_46 ,
T_1 V_81 ,
T_4 V_83 )
{
T_1 V_47 = F_78 ( V_46 -> V_80 ) ;
T_1 V_82 , V_88 = 0 ;
struct V_43 * V_44 = V_46 -> V_44 ;
struct V_45 * V_57 ;
struct V_89 * V_90 ;
unsigned V_91 ;
if ( V_81 ) {
V_82 = V_81 + V_47 ;
if ( V_81 >= V_82 ) {
return - V_35 ;
}
V_91 = V_82 / V_28 ;
if ( V_91 > V_2 -> V_40 . V_41 ) {
F_42 ( V_2 -> V_51 , L_7 ,
V_91 , V_2 -> V_40 . V_41 ) ;
return - V_35 ;
}
} else {
V_82 = V_91 = 0 ;
}
F_51 ( & V_44 -> V_59 ) ;
V_90 = & V_44 -> V_87 ;
V_88 = 0 ;
F_45 (tmp, &vm->va, vm_list) {
if ( V_46 == V_57 ) {
continue;
}
if ( V_81 >= V_88 && V_82 <= V_57 -> V_81 ) {
break;
}
if ( V_82 > V_57 -> V_81 && V_81 < V_57 -> V_82 ) {
F_42 ( V_2 -> V_51 , L_8 ,
V_46 -> V_80 , ( unsigned ) V_46 -> V_81 , V_57 -> V_80 ,
( unsigned ) V_57 -> V_81 , ( unsigned ) V_57 -> V_82 ) ;
F_53 ( & V_44 -> V_59 ) ;
return - V_35 ;
}
V_88 = V_57 -> V_82 ;
V_90 = & V_57 -> V_86 ;
}
V_46 -> V_81 = V_81 ;
V_46 -> V_82 = V_82 ;
V_46 -> V_83 = V_83 ;
V_46 -> V_53 = false ;
F_79 ( & V_46 -> V_86 , V_90 ) ;
F_53 ( & V_44 -> V_59 ) ;
return 0 ;
}
T_1 F_80 ( struct V_1 * V_2 , T_1 V_31 )
{
T_1 V_92 ;
V_92 = V_2 -> V_5 . V_29 [ V_31 >> V_14 ] ;
V_92 |= V_31 & ( ~ V_93 ) ;
return V_92 ;
}
static int F_81 ( struct V_1 * V_2 ,
struct V_43 * V_44 ,
struct V_94 * V_95 ,
T_1 V_96 , T_1 V_97 )
{
static const T_4 V_98 = V_99 * 8 ;
T_1 V_100 = ~ 0 , V_101 = ~ 0 ;
unsigned V_102 = 0 ;
T_1 V_103 ;
int V_15 ;
V_96 = ( V_96 / V_28 ) >> V_42 ;
V_97 = ( V_97 / V_28 ) >> V_42 ;
for ( V_103 = V_96 ; V_103 <= V_97 ; ++ V_103 ) {
T_1 V_104 , V_105 ;
if ( V_44 -> V_56 [ V_103 ] )
continue;
V_67:
V_15 = F_62 ( V_2 , & V_2 -> V_40 . V_49 ,
& V_44 -> V_56 [ V_103 ] ,
V_99 * 8 ,
V_28 , false ) ;
if ( V_15 == - V_8 ) {
V_15 = F_58 ( V_2 , V_44 ) ;
if ( V_15 )
return V_15 ;
goto V_67;
} else if ( V_15 ) {
return V_15 ;
}
V_104 = V_44 -> V_68 + V_103 * 8 ;
V_105 = F_63 ( V_44 -> V_56 [ V_103 ] ) ;
if ( ( ( V_100 + 8 * V_102 ) != V_104 ) ||
( ( V_101 + V_98 * V_102 ) != V_105 ) ) {
if ( V_102 ) {
F_82 ( V_2 , V_95 , V_100 ,
V_101 , V_102 , V_98 ,
V_106 ) ;
}
V_102 = 1 ;
V_100 = V_104 ;
V_101 = V_105 ;
} else {
++ V_102 ;
}
}
if ( V_102 ) {
F_82 ( V_2 , V_95 , V_100 , V_101 , V_102 ,
V_98 , V_106 ) ;
}
return 0 ;
}
static void F_83 ( struct V_1 * V_2 ,
struct V_43 * V_44 ,
struct V_94 * V_95 ,
T_1 V_96 , T_1 V_97 ,
T_1 V_107 , T_4 V_83 )
{
static const T_1 V_108 = V_99 - 1 ;
T_1 V_109 = ~ 0 , V_110 = ~ 0 ;
unsigned V_102 = 0 ;
T_1 V_31 ;
V_96 = V_96 / V_28 ;
V_97 = V_97 / V_28 ;
for ( V_31 = V_96 ; V_31 < V_97 ; ) {
T_1 V_103 = V_31 >> V_42 ;
unsigned V_111 ;
T_1 V_112 ;
if ( ( V_31 & ~ V_108 ) == ( V_97 & ~ V_108 ) )
V_111 = V_97 - V_31 ;
else
V_111 = V_99 - ( V_31 & V_108 ) ;
V_112 = F_63 ( V_44 -> V_56 [ V_103 ] ) ;
V_112 += ( V_31 & V_108 ) * 8 ;
if ( ( V_109 + 8 * V_102 ) != V_112 ) {
if ( V_102 ) {
F_82 ( V_2 , V_95 , V_109 ,
V_110 , V_102 ,
V_28 ,
V_83 ) ;
}
V_102 = V_111 ;
V_109 = V_112 ;
V_110 = V_107 ;
} else {
V_102 += V_111 ;
}
V_31 += V_111 ;
V_107 += V_111 * V_28 ;
}
if ( V_102 ) {
F_82 ( V_2 , V_95 , V_109 ,
V_110 , V_102 ,
V_28 , V_83 ) ;
}
}
int F_84 ( struct V_1 * V_2 ,
struct V_43 * V_44 ,
struct V_79 * V_80 ,
struct V_113 * V_114 )
{
unsigned V_115 = V_2 -> V_116 -> V_44 . V_117 ;
struct V_94 V_95 ;
struct V_45 * V_46 ;
unsigned V_111 , V_118 , V_119 ;
T_1 V_31 ;
int V_15 ;
if ( V_44 -> V_52 == NULL )
return 0 ;
V_46 = F_73 ( V_44 , V_80 ) ;
if ( V_46 == NULL ) {
F_42 ( V_2 -> V_51 , L_9 , V_80 , V_44 ) ;
return - V_35 ;
}
if ( ! V_46 -> V_81 ) {
F_42 ( V_2 -> V_51 , L_10 ,
V_80 , V_44 ) ;
return - V_35 ;
}
if ( ( V_46 -> V_53 && V_114 ) || ( ! V_46 -> V_53 && V_114 == NULL ) )
return 0 ;
V_46 -> V_83 &= ~ V_106 ;
V_46 -> V_83 &= ~ V_120 ;
if ( V_114 ) {
V_31 = V_114 -> V_96 << V_14 ;
if ( V_114 -> V_121 != V_122 ) {
V_46 -> V_83 |= V_106 ;
V_46 -> V_53 = true ;
}
if ( V_114 -> V_121 == V_123 ) {
V_46 -> V_83 |= V_120 ;
} else {
V_31 += V_2 -> V_40 . V_124 ;
}
} else {
V_31 = 0 ;
V_46 -> V_53 = false ;
}
V_111 = F_85 ( V_80 ) ;
V_118 = ( V_111 >> V_42 ) + 2 ;
V_119 = 64 ;
if ( V_42 > 11 )
V_119 += ( V_111 >> 11 ) * 4 ;
else
V_119 += ( V_111 >> V_42 ) * 4 ;
V_119 += V_111 * 2 ;
V_119 += ( V_118 >> 11 ) * 4 ;
V_119 += V_118 * 2 ;
if ( V_119 > 0xfffff )
return - V_8 ;
V_15 = F_86 ( V_2 , V_115 , & V_95 , NULL , V_119 * 4 ) ;
V_95 . V_125 = 0 ;
V_15 = F_81 ( V_2 , V_44 , & V_95 , V_46 -> V_81 , V_46 -> V_82 ) ;
if ( V_15 ) {
F_87 ( V_2 , & V_95 ) ;
return V_15 ;
}
F_83 ( V_2 , V_44 , & V_95 , V_46 -> V_81 , V_46 -> V_82 ,
V_31 , V_46 -> V_83 ) ;
F_88 ( & V_95 , V_44 -> V_55 ) ;
V_15 = F_89 ( V_2 , & V_95 , NULL ) ;
if ( V_15 ) {
F_87 ( V_2 , & V_95 ) ;
return V_15 ;
}
F_54 ( & V_44 -> V_55 ) ;
V_44 -> V_55 = F_72 ( V_95 . V_55 ) ;
F_87 ( V_2 , & V_95 ) ;
F_54 ( & V_44 -> V_77 ) ;
return 0 ;
}
int F_90 ( struct V_1 * V_2 ,
struct V_45 * V_46 )
{
int V_15 = 0 ;
F_51 ( & V_2 -> V_40 . V_58 ) ;
F_51 ( & V_46 -> V_44 -> V_59 ) ;
if ( V_46 -> V_81 ) {
V_15 = F_84 ( V_2 , V_46 -> V_44 , V_46 -> V_80 , NULL ) ;
}
F_53 ( & V_2 -> V_40 . V_58 ) ;
F_91 ( & V_46 -> V_86 ) ;
F_53 ( & V_46 -> V_44 -> V_59 ) ;
F_91 ( & V_46 -> V_85 ) ;
F_49 ( V_46 ) ;
return V_15 ;
}
void F_92 ( struct V_1 * V_2 ,
struct V_79 * V_80 )
{
struct V_45 * V_46 ;
F_45 (bo_va, &bo->va, bo_list) {
V_46 -> V_53 = false ;
}
}
void F_93 ( struct V_1 * V_2 , struct V_43 * V_44 )
{
V_44 -> V_76 = 0 ;
V_44 -> V_55 = NULL ;
F_94 ( & V_44 -> V_59 ) ;
F_75 ( & V_44 -> V_54 ) ;
F_75 ( & V_44 -> V_87 ) ;
}
void F_95 ( struct V_1 * V_2 , struct V_43 * V_44 )
{
struct V_45 * V_46 , * V_57 ;
int V_15 ;
F_51 ( & V_2 -> V_40 . V_58 ) ;
F_51 ( & V_44 -> V_59 ) ;
F_46 ( V_2 , V_44 ) ;
F_53 ( & V_2 -> V_40 . V_58 ) ;
if ( ! F_59 ( & V_44 -> V_87 ) ) {
F_42 ( V_2 -> V_51 , L_11 ) ;
}
F_52 (bo_va, tmp, &vm->va, vm_list) {
F_47 ( & V_46 -> V_86 ) ;
V_15 = F_11 ( V_46 -> V_80 , false ) ;
if ( ! V_15 ) {
F_47 ( & V_46 -> V_85 ) ;
F_14 ( V_46 -> V_80 ) ;
F_49 ( V_46 ) ;
}
}
F_54 ( & V_44 -> V_55 ) ;
F_54 ( & V_44 -> V_77 ) ;
F_53 ( & V_44 -> V_59 ) ;
}
