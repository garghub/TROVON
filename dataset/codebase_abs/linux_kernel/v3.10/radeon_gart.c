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
F_17 ( V_2 ) ;
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
V_18 ) ;
if ( V_15 ) {
F_42 ( V_2 -> V_50 , L_5 ,
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
if ( V_44 -> V_51 == NULL )
continue;
F_45 (bo_va, &vm->va, vm_list) {
V_46 -> V_52 = false ;
}
}
return 0 ;
}
static void F_46 ( struct V_1 * V_2 ,
struct V_43 * V_44 )
{
struct V_45 * V_46 ;
int V_24 ;
if ( ! V_44 -> V_51 )
return;
F_47 ( & V_44 -> V_53 ) ;
F_48 ( V_2 , & V_44 -> V_51 , V_44 -> V_54 ) ;
F_45 (bo_va, &vm->va, vm_list) {
V_46 -> V_52 = false ;
}
if ( V_44 -> V_55 == NULL )
return;
for ( V_24 = 0 ; V_24 < F_37 ( V_2 ) ; V_24 ++ )
F_48 ( V_2 , & V_44 -> V_55 [ V_24 ] , V_44 -> V_54 ) ;
F_49 ( V_44 -> V_55 ) ;
}
void F_50 ( struct V_1 * V_2 )
{
struct V_43 * V_44 , * V_56 ;
int V_24 ;
if ( ! V_2 -> V_40 . V_48 )
return;
F_51 ( & V_2 -> V_40 . V_57 ) ;
F_52 (vm, tmp, &rdev->vm_manager.lru_vm, list) {
F_51 ( & V_44 -> V_58 ) ;
F_46 ( V_2 , V_44 ) ;
F_53 ( & V_44 -> V_58 ) ;
}
for ( V_24 = 0 ; V_24 < V_59 ; ++ V_24 ) {
F_54 ( & V_2 -> V_40 . V_60 [ V_24 ] ) ;
}
F_55 ( V_2 ) ;
F_53 ( & V_2 -> V_40 . V_57 ) ;
F_56 ( V_2 , & V_2 -> V_40 . V_49 ) ;
F_57 ( V_2 , & V_2 -> V_40 . V_49 ) ;
V_2 -> V_40 . V_48 = false ;
}
static int F_58 ( struct V_1 * V_2 , struct V_43 * V_44 )
{
struct V_43 * V_61 ;
if ( F_59 ( & V_2 -> V_40 . V_62 ) )
return - V_8 ;
V_61 = F_60 ( & V_2 -> V_40 . V_62 ,
struct V_43 , V_53 ) ;
if ( V_61 == V_44 )
return - V_8 ;
F_51 ( & V_61 -> V_58 ) ;
F_46 ( V_2 , V_61 ) ;
F_53 ( & V_61 -> V_58 ) ;
return 0 ;
}
int F_61 ( struct V_1 * V_2 , struct V_43 * V_44 )
{
unsigned V_63 , V_64 ;
T_2 * V_65 ;
int V_15 ;
if ( V_44 == NULL ) {
return - V_35 ;
}
if ( V_44 -> V_51 != NULL ) {
return 0 ;
}
V_66:
V_63 = F_39 ( F_38 ( V_2 ) ) ;
V_15 = F_62 ( V_2 , & V_2 -> V_40 . V_49 ,
& V_44 -> V_51 , V_63 ,
V_28 , false ) ;
if ( V_15 == - V_8 ) {
V_15 = F_58 ( V_2 , V_44 ) ;
if ( V_15 )
return V_15 ;
goto V_66;
} else if ( V_15 ) {
return V_15 ;
}
V_44 -> V_67 = F_63 ( V_44 -> V_51 ) ;
V_65 = F_64 ( V_44 -> V_51 ) ;
memset ( V_65 , 0 , V_63 ) ;
V_64 = F_37 ( V_2 ) * sizeof( struct V_68 * ) ;
V_44 -> V_55 = F_65 ( V_64 , V_69 ) ;
if ( V_44 -> V_55 == NULL ) {
F_30 ( L_6 ) ;
F_48 ( V_2 , & V_44 -> V_51 , V_44 -> V_54 ) ;
return - V_8 ;
}
return 0 ;
}
void F_66 ( struct V_1 * V_2 , struct V_43 * V_44 )
{
F_47 ( & V_44 -> V_53 ) ;
F_67 ( & V_44 -> V_53 , & V_2 -> V_40 . V_62 ) ;
}
struct V_70 * F_68 ( struct V_1 * V_2 ,
struct V_43 * V_44 , int V_71 )
{
struct V_70 * V_72 [ V_73 ] = {} ;
unsigned V_74 [ 2 ] = {} ;
unsigned V_24 ;
if ( V_44 -> V_54 && V_44 -> V_54 == V_2 -> V_40 . V_60 [ V_44 -> V_75 ] )
return NULL ;
F_54 ( & V_44 -> V_76 ) ;
for ( V_24 = 1 ; V_24 < V_2 -> V_40 . V_77 ; ++ V_24 ) {
struct V_70 * V_54 = V_2 -> V_40 . V_60 [ V_24 ] ;
if ( V_54 == NULL ) {
V_44 -> V_75 = V_24 ;
return NULL ;
}
if ( F_69 ( V_54 , V_72 [ V_54 -> V_71 ] ) ) {
V_72 [ V_54 -> V_71 ] = V_54 ;
V_74 [ V_54 -> V_71 == V_71 ? 0 : 1 ] = V_24 ;
}
}
for ( V_24 = 0 ; V_24 < 2 ; ++ V_24 ) {
if ( V_74 [ V_24 ] ) {
V_44 -> V_75 = V_74 [ V_24 ] ;
return V_2 -> V_40 . V_60 [ V_74 [ V_24 ] ] ;
}
}
F_70 () ;
return NULL ;
}
void F_71 ( struct V_1 * V_2 ,
struct V_43 * V_44 ,
struct V_70 * V_54 )
{
F_54 ( & V_2 -> V_40 . V_60 [ V_44 -> V_75 ] ) ;
V_2 -> V_40 . V_60 [ V_44 -> V_75 ] = F_72 ( V_54 ) ;
F_54 ( & V_44 -> V_54 ) ;
V_44 -> V_54 = F_72 ( V_54 ) ;
}
struct V_45 * F_73 ( struct V_43 * V_44 ,
struct V_78 * V_79 )
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
struct V_78 * V_79 )
{
struct V_45 * V_46 ;
V_46 = F_65 ( sizeof( struct V_45 ) , V_69 ) ;
if ( V_46 == NULL ) {
return NULL ;
}
V_46 -> V_44 = V_44 ;
V_46 -> V_79 = V_79 ;
V_46 -> V_80 = 0 ;
V_46 -> V_81 = 0 ;
V_46 -> V_82 = 0 ;
V_46 -> V_52 = false ;
V_46 -> V_83 = 1 ;
F_75 ( & V_46 -> V_84 ) ;
F_75 ( & V_46 -> V_85 ) ;
F_51 ( & V_44 -> V_58 ) ;
F_76 ( & V_46 -> V_85 , & V_44 -> V_86 ) ;
F_67 ( & V_46 -> V_84 , & V_79 -> V_86 ) ;
F_53 ( & V_44 -> V_58 ) ;
return V_46 ;
}
int F_77 ( struct V_1 * V_2 ,
struct V_45 * V_46 ,
T_1 V_80 ,
T_4 V_82 )
{
T_1 V_47 = F_78 ( V_46 -> V_79 ) ;
T_1 V_81 , V_87 = 0 ;
struct V_43 * V_44 = V_46 -> V_44 ;
struct V_45 * V_56 ;
struct V_88 * V_89 ;
unsigned V_90 ;
if ( V_80 ) {
V_81 = V_80 + V_47 ;
if ( V_80 >= V_81 ) {
return - V_35 ;
}
V_90 = V_81 / V_28 ;
if ( V_90 > V_2 -> V_40 . V_41 ) {
F_42 ( V_2 -> V_50 , L_7 ,
V_90 , V_2 -> V_40 . V_41 ) ;
return - V_35 ;
}
} else {
V_81 = V_90 = 0 ;
}
F_51 ( & V_44 -> V_58 ) ;
V_89 = & V_44 -> V_86 ;
V_87 = 0 ;
F_45 (tmp, &vm->va, vm_list) {
if ( V_46 == V_56 ) {
continue;
}
if ( V_80 >= V_87 && V_81 <= V_56 -> V_80 ) {
break;
}
if ( V_81 > V_56 -> V_80 && V_80 < V_56 -> V_81 ) {
F_42 ( V_2 -> V_50 , L_8 ,
V_46 -> V_79 , ( unsigned ) V_46 -> V_80 , V_56 -> V_79 ,
( unsigned ) V_56 -> V_80 , ( unsigned ) V_56 -> V_81 ) ;
F_53 ( & V_44 -> V_58 ) ;
return - V_35 ;
}
V_87 = V_56 -> V_81 ;
V_89 = & V_56 -> V_85 ;
}
V_46 -> V_80 = V_80 ;
V_46 -> V_81 = V_81 ;
V_46 -> V_82 = V_82 ;
V_46 -> V_52 = false ;
F_79 ( & V_46 -> V_85 , V_89 ) ;
F_53 ( & V_44 -> V_58 ) ;
return 0 ;
}
T_1 F_80 ( struct V_1 * V_2 , T_1 V_31 )
{
T_1 V_91 ;
V_91 = V_2 -> V_5 . V_29 [ V_31 >> V_14 ] ;
V_91 |= V_31 & ( ~ V_92 ) ;
return V_91 ;
}
static int F_81 ( struct V_1 * V_2 ,
struct V_43 * V_44 ,
struct V_93 * V_94 ,
T_1 V_95 , T_1 V_96 )
{
static const T_4 V_97 = V_98 * 8 ;
T_1 V_99 = ~ 0 , V_100 = ~ 0 ;
unsigned V_101 = 0 ;
T_1 V_102 ;
int V_15 ;
V_95 = ( V_95 / V_28 ) >> V_42 ;
V_96 = ( V_96 / V_28 ) >> V_42 ;
for ( V_102 = V_95 ; V_102 <= V_96 ; ++ V_102 ) {
T_1 V_103 , V_104 ;
if ( V_44 -> V_55 [ V_102 ] )
continue;
V_66:
V_15 = F_62 ( V_2 , & V_2 -> V_40 . V_49 ,
& V_44 -> V_55 [ V_102 ] ,
V_98 * 8 ,
V_28 , false ) ;
if ( V_15 == - V_8 ) {
V_15 = F_58 ( V_2 , V_44 ) ;
if ( V_15 )
return V_15 ;
goto V_66;
} else if ( V_15 ) {
return V_15 ;
}
V_103 = V_44 -> V_67 + V_102 * 8 ;
V_104 = F_63 ( V_44 -> V_55 [ V_102 ] ) ;
if ( ( ( V_99 + 8 * V_101 ) != V_103 ) ||
( ( V_100 + V_97 * V_101 ) != V_104 ) ) {
if ( V_101 ) {
F_82 ( V_2 , V_94 , V_99 ,
V_100 , V_101 , V_97 ,
V_105 ) ;
}
V_101 = 1 ;
V_99 = V_103 ;
V_100 = V_104 ;
} else {
++ V_101 ;
}
}
if ( V_101 ) {
F_82 ( V_2 , V_94 , V_99 , V_100 , V_101 ,
V_97 , V_105 ) ;
}
return 0 ;
}
static void F_83 ( struct V_1 * V_2 ,
struct V_43 * V_44 ,
struct V_93 * V_94 ,
T_1 V_95 , T_1 V_96 ,
T_1 V_106 , T_4 V_82 )
{
static const T_1 V_107 = V_98 - 1 ;
T_1 V_108 = ~ 0 , V_109 = ~ 0 ;
unsigned V_101 = 0 ;
T_1 V_31 ;
V_95 = V_95 / V_28 ;
V_96 = V_96 / V_28 ;
for ( V_31 = V_95 ; V_31 < V_96 ; ) {
T_1 V_102 = V_31 >> V_42 ;
unsigned V_110 ;
T_1 V_111 ;
if ( ( V_31 & ~ V_107 ) == ( V_96 & ~ V_107 ) )
V_110 = V_96 - V_31 ;
else
V_110 = V_98 - ( V_31 & V_107 ) ;
V_111 = F_63 ( V_44 -> V_55 [ V_102 ] ) ;
V_111 += ( V_31 & V_107 ) * 8 ;
if ( ( V_108 + 8 * V_101 ) != V_111 ) {
if ( V_101 ) {
F_82 ( V_2 , V_94 , V_108 ,
V_109 , V_101 ,
V_28 ,
V_82 ) ;
}
V_101 = V_110 ;
V_108 = V_111 ;
V_109 = V_106 ;
} else {
V_101 += V_110 ;
}
V_31 += V_110 ;
V_106 += V_110 * V_28 ;
}
if ( V_101 ) {
F_82 ( V_2 , V_94 , V_108 ,
V_109 , V_101 ,
V_28 , V_82 ) ;
}
}
int F_84 ( struct V_1 * V_2 ,
struct V_43 * V_44 ,
struct V_78 * V_79 ,
struct V_112 * V_113 )
{
unsigned V_114 = V_2 -> V_115 -> V_44 . V_116 ;
struct V_93 V_94 ;
struct V_45 * V_46 ;
unsigned V_110 , V_117 , V_118 ;
T_1 V_31 ;
int V_15 ;
if ( V_44 -> V_51 == NULL )
return 0 ;
V_46 = F_73 ( V_44 , V_79 ) ;
if ( V_46 == NULL ) {
F_42 ( V_2 -> V_50 , L_9 , V_79 , V_44 ) ;
return - V_35 ;
}
if ( ! V_46 -> V_80 ) {
F_42 ( V_2 -> V_50 , L_10 ,
V_79 , V_44 ) ;
return - V_35 ;
}
if ( ( V_46 -> V_52 && V_113 ) || ( ! V_46 -> V_52 && V_113 == NULL ) )
return 0 ;
V_46 -> V_82 &= ~ V_105 ;
V_46 -> V_82 &= ~ V_119 ;
if ( V_113 ) {
V_31 = V_113 -> V_95 << V_14 ;
if ( V_113 -> V_120 != V_121 ) {
V_46 -> V_82 |= V_105 ;
V_46 -> V_52 = true ;
}
if ( V_113 -> V_120 == V_122 ) {
V_46 -> V_82 |= V_119 ;
} else {
V_31 += V_2 -> V_40 . V_123 ;
}
} else {
V_31 = 0 ;
V_46 -> V_52 = false ;
}
V_110 = F_85 ( V_79 ) ;
V_117 = ( V_110 >> V_42 ) + 2 ;
V_118 = 64 ;
if ( V_42 > 11 )
V_118 += ( V_110 >> 11 ) * 4 ;
else
V_118 += ( V_110 >> V_42 ) * 4 ;
V_118 += V_110 * 2 ;
V_118 += ( V_117 >> 11 ) * 4 ;
V_118 += V_117 * 2 ;
if ( V_118 > 0xfffff )
return - V_8 ;
V_15 = F_86 ( V_2 , V_114 , & V_94 , NULL , V_118 * 4 ) ;
V_94 . V_124 = 0 ;
V_15 = F_81 ( V_2 , V_44 , & V_94 , V_46 -> V_80 , V_46 -> V_81 ) ;
if ( V_15 ) {
F_87 ( V_2 , & V_94 ) ;
return V_15 ;
}
F_83 ( V_2 , V_44 , & V_94 , V_46 -> V_80 , V_46 -> V_81 ,
V_31 , V_46 -> V_82 ) ;
F_88 ( & V_94 , V_44 -> V_54 ) ;
V_15 = F_89 ( V_2 , & V_94 , NULL ) ;
if ( V_15 ) {
F_87 ( V_2 , & V_94 ) ;
return V_15 ;
}
F_54 ( & V_44 -> V_54 ) ;
V_44 -> V_54 = F_72 ( V_94 . V_54 ) ;
F_87 ( V_2 , & V_94 ) ;
F_54 ( & V_44 -> V_76 ) ;
return 0 ;
}
int F_90 ( struct V_1 * V_2 ,
struct V_45 * V_46 )
{
int V_15 = 0 ;
F_51 ( & V_2 -> V_40 . V_57 ) ;
F_51 ( & V_46 -> V_44 -> V_58 ) ;
if ( V_46 -> V_80 ) {
V_15 = F_84 ( V_2 , V_46 -> V_44 , V_46 -> V_79 , NULL ) ;
}
F_53 ( & V_2 -> V_40 . V_57 ) ;
F_91 ( & V_46 -> V_85 ) ;
F_53 ( & V_46 -> V_44 -> V_58 ) ;
F_91 ( & V_46 -> V_84 ) ;
F_49 ( V_46 ) ;
return V_15 ;
}
void F_92 ( struct V_1 * V_2 ,
struct V_78 * V_79 )
{
struct V_45 * V_46 ;
F_45 (bo_va, &bo->va, bo_list) {
V_46 -> V_52 = false ;
}
}
void F_93 ( struct V_1 * V_2 , struct V_43 * V_44 )
{
V_44 -> V_75 = 0 ;
V_44 -> V_54 = NULL ;
F_94 ( & V_44 -> V_58 ) ;
F_75 ( & V_44 -> V_53 ) ;
F_75 ( & V_44 -> V_86 ) ;
}
void F_95 ( struct V_1 * V_2 , struct V_43 * V_44 )
{
struct V_45 * V_46 , * V_56 ;
int V_15 ;
F_51 ( & V_2 -> V_40 . V_57 ) ;
F_51 ( & V_44 -> V_58 ) ;
F_46 ( V_2 , V_44 ) ;
F_53 ( & V_2 -> V_40 . V_57 ) ;
if ( ! F_59 ( & V_44 -> V_86 ) ) {
F_42 ( V_2 -> V_50 , L_11 ) ;
}
F_52 (bo_va, tmp, &vm->va, vm_list) {
F_47 ( & V_46 -> V_85 ) ;
V_15 = F_11 ( V_46 -> V_79 , false ) ;
if ( ! V_15 ) {
F_47 ( & V_46 -> V_84 ) ;
F_14 ( V_46 -> V_79 ) ;
F_49 ( V_46 ) ;
}
}
F_54 ( & V_44 -> V_54 ) ;
F_54 ( & V_44 -> V_76 ) ;
F_53 ( & V_44 -> V_58 ) ;
}
