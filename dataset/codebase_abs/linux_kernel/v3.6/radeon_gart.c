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
V_2 -> V_5 . V_21 = F_33 ( sizeof( void * ) * V_2 -> V_5 . V_36 ,
V_40 ) ;
if ( V_2 -> V_5 . V_21 == NULL ) {
F_34 ( V_2 ) ;
return - V_8 ;
}
V_2 -> V_5 . V_29 = F_33 ( sizeof( T_3 ) *
V_2 -> V_5 . V_36 , V_40 ) ;
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
int F_37 ( struct V_1 * V_2 )
{
struct V_41 * V_42 ;
struct V_43 * V_44 ;
int V_15 ;
if ( ! V_2 -> V_45 . V_46 ) {
V_15 = F_38 ( V_2 , & V_2 -> V_45 . V_47 ,
V_2 -> V_45 . V_48 * 8 * 2 ,
V_18 ) ;
if ( V_15 ) {
F_39 ( V_2 -> V_49 , L_5 ,
( V_2 -> V_45 . V_48 * 8 ) >> 10 ) ;
return V_15 ;
}
V_15 = V_2 -> V_45 . V_50 -> V_51 ( V_2 ) ;
if ( V_15 )
return V_15 ;
V_2 -> V_45 . V_46 = true ;
V_15 = F_40 ( V_2 , & V_2 -> V_45 . V_47 ) ;
if ( V_15 )
return V_15 ;
}
F_41 (vm, &rdev->vm_manager.lru_vm, list) {
if ( V_42 -> V_52 == - 1 )
continue;
F_41 (bo_va, &vm->va, vm_list) {
struct V_53 * V_54 = NULL ;
if ( V_44 -> V_55 )
V_54 = & V_44 -> V_56 -> V_57 . V_54 ;
V_44 -> V_55 = false ;
V_15 = F_42 ( V_2 , V_42 , V_44 -> V_56 , V_54 ) ;
if ( V_15 ) {
F_30 ( L_6 , V_42 -> V_52 ) ;
}
}
V_15 = V_2 -> V_45 . V_50 -> V_58 ( V_2 , V_42 , V_42 -> V_52 ) ;
if ( V_15 ) {
F_30 ( L_7 , V_42 -> V_52 ) ;
}
}
return 0 ;
}
static void F_43 ( struct V_1 * V_2 ,
struct V_41 * V_42 )
{
struct V_43 * V_44 ;
if ( V_42 -> V_52 == - 1 ) {
return;
}
while ( V_42 -> V_59 ) {
int V_15 ;
V_15 = F_44 ( V_42 -> V_59 , false ) ;
if ( V_15 )
F_30 ( L_8 , V_15 ) ;
if ( V_15 == - V_60 ) {
F_45 ( & V_2 -> V_45 . V_61 ) ;
V_15 = F_46 ( V_2 ) ;
F_47 ( & V_2 -> V_45 . V_61 ) ;
if ( ! V_15 )
continue;
}
break;
}
F_48 ( & V_42 -> V_59 ) ;
V_2 -> V_45 . V_50 -> V_62 ( V_2 , V_42 ) ;
V_2 -> V_45 . V_63 &= ~ ( 1 << V_42 -> V_52 ) ;
F_49 ( & V_42 -> V_64 ) ;
V_42 -> V_52 = - 1 ;
F_50 ( V_2 , & V_42 -> V_65 , NULL ) ;
V_42 -> V_66 = NULL ;
F_41 (bo_va, &vm->va, vm_list) {
V_44 -> V_55 = false ;
}
}
void F_51 ( struct V_1 * V_2 )
{
struct V_41 * V_42 , * V_67 ;
if ( ! V_2 -> V_45 . V_46 )
return;
F_47 ( & V_2 -> V_45 . V_61 ) ;
F_52 (vm, tmp, &rdev->vm_manager.lru_vm, list) {
F_43 ( V_2 , V_42 ) ;
}
V_2 -> V_45 . V_50 -> V_68 ( V_2 ) ;
F_45 ( & V_2 -> V_45 . V_61 ) ;
F_53 ( V_2 , & V_2 -> V_45 . V_47 ) ;
F_54 ( V_2 , & V_2 -> V_45 . V_47 ) ;
V_2 -> V_45 . V_46 = false ;
}
void F_55 ( struct V_1 * V_2 , struct V_41 * V_42 )
{
F_47 ( & V_42 -> V_69 ) ;
F_43 ( V_2 , V_42 ) ;
F_45 ( & V_42 -> V_69 ) ;
}
int F_56 ( struct V_1 * V_2 , struct V_41 * V_42 )
{
struct V_41 * V_70 ;
unsigned V_24 ;
int V_52 = - 1 , V_15 ;
if ( V_42 == NULL ) {
return - V_35 ;
}
if ( V_42 -> V_52 != - 1 ) {
F_49 ( & V_42 -> V_64 ) ;
F_57 ( & V_42 -> V_64 , & V_2 -> V_45 . V_71 ) ;
return 0 ;
}
V_72:
V_15 = F_58 ( V_2 , & V_2 -> V_45 . V_47 , & V_42 -> V_65 ,
F_59 ( V_42 -> V_73 * 8 ) ,
V_28 , false ) ;
if ( V_15 ) {
if ( F_60 ( & V_2 -> V_45 . V_71 ) ) {
return V_15 ;
}
V_70 = F_61 ( & V_2 -> V_45 . V_71 , struct V_41 , V_64 ) ;
F_55 ( V_2 , V_70 ) ;
goto V_72;
}
V_42 -> V_66 = F_62 ( V_42 -> V_65 ) ;
V_42 -> V_74 = F_63 ( V_42 -> V_65 ) ;
memset ( V_42 -> V_66 , 0 , F_59 ( V_42 -> V_73 * 8 ) ) ;
V_75:
for ( V_24 = 0 ; V_24 < V_2 -> V_45 . V_76 ; V_24 ++ ) {
if ( ! ( V_2 -> V_45 . V_63 & ( 1 << V_24 ) ) ) {
V_52 = V_24 ;
break;
}
}
if ( V_52 == - 1 ) {
V_70 = F_61 ( & V_2 -> V_45 . V_71 , struct V_41 , V_64 ) ;
F_55 ( V_2 , V_70 ) ;
goto V_75;
}
V_15 = V_2 -> V_45 . V_50 -> V_58 ( V_2 , V_42 , V_52 ) ;
if ( V_15 ) {
F_50 ( V_2 , & V_42 -> V_65 , NULL ) ;
return V_15 ;
}
V_2 -> V_45 . V_63 |= 1 << V_52 ;
V_42 -> V_52 = V_52 ;
F_57 ( & V_42 -> V_64 , & V_2 -> V_45 . V_71 ) ;
return F_42 ( V_2 , V_42 , V_2 -> V_77 . V_56 ,
& V_2 -> V_77 . V_56 -> V_57 . V_54 ) ;
}
int F_64 ( struct V_1 * V_2 ,
struct V_41 * V_42 ,
struct V_78 * V_56 ,
T_1 V_20 ,
T_4 V_79 )
{
struct V_43 * V_44 , * V_67 ;
struct V_80 * V_81 ;
T_1 V_82 = F_65 ( V_56 ) , V_83 = 0 ;
unsigned V_73 ;
V_44 = F_33 ( sizeof( struct V_43 ) , V_40 ) ;
if ( V_44 == NULL ) {
return - V_8 ;
}
V_44 -> V_42 = V_42 ;
V_44 -> V_56 = V_56 ;
V_44 -> V_84 = V_20 ;
V_44 -> V_85 = V_20 + V_82 ;
V_44 -> V_79 = V_79 ;
V_44 -> V_55 = false ;
F_66 ( & V_44 -> V_86 ) ;
F_66 ( & V_44 -> V_87 ) ;
if ( V_44 -> V_84 >= V_44 -> V_85 ) {
F_35 ( V_44 ) ;
return - V_35 ;
}
V_73 = V_44 -> V_85 / V_28 ;
if ( V_73 > V_2 -> V_45 . V_48 ) {
F_35 ( V_44 ) ;
F_39 ( V_2 -> V_49 , L_9 ,
V_73 , V_2 -> V_45 . V_48 ) ;
return - V_35 ;
}
F_47 ( & V_42 -> V_69 ) ;
if ( V_73 > V_42 -> V_73 ) {
F_45 ( & V_42 -> V_69 ) ;
F_47 ( & V_2 -> V_45 . V_61 ) ;
F_47 ( & V_42 -> V_69 ) ;
if ( V_73 > V_42 -> V_73 ) {
unsigned V_88 = ( ( 32 << 20 ) >> 12 ) - 1 ;
F_43 ( V_2 , V_42 ) ;
V_42 -> V_73 = ( V_73 + V_88 ) & ~ V_88 ;
}
F_45 ( & V_2 -> V_45 . V_61 ) ;
}
V_81 = & V_42 -> V_89 ;
V_83 = 0 ;
F_41 (tmp, &vm->va, vm_list) {
if ( V_44 -> V_84 >= V_83 && V_44 -> V_85 < V_67 -> V_84 ) {
break;
}
if ( V_44 -> V_84 >= V_67 -> V_84 && V_44 -> V_84 < V_67 -> V_85 ) {
F_39 ( V_2 -> V_49 , L_10 ,
V_56 , ( unsigned ) V_44 -> V_84 , V_67 -> V_56 ,
( unsigned ) V_67 -> V_84 , ( unsigned ) V_67 -> V_85 ) ;
F_35 ( V_44 ) ;
F_45 ( & V_42 -> V_69 ) ;
return - V_35 ;
}
V_83 = V_67 -> V_85 ;
V_81 = & V_67 -> V_87 ;
}
F_67 ( & V_44 -> V_87 , V_81 ) ;
F_57 ( & V_44 -> V_86 , & V_56 -> V_89 ) ;
F_45 ( & V_42 -> V_69 ) ;
return 0 ;
}
static T_2 F_68 ( struct V_1 * V_2 ,
struct V_53 * V_54 ,
unsigned V_90 )
{
T_2 V_31 = 0 ;
switch ( V_54 -> V_91 ) {
case V_92 :
V_31 = ( V_54 -> V_93 << V_14 ) ;
V_31 += V_90 * V_28 ;
V_31 += V_2 -> V_45 . V_94 ;
break;
case V_95 :
V_31 = V_54 -> V_93 << V_14 ;
V_31 += V_90 * V_28 ;
V_31 = V_31 >> V_14 ;
V_31 = V_2 -> V_5 . V_29 [ V_31 ] ;
V_31 += ( V_90 * V_28 ) & ( ~ V_96 ) ;
break;
default:
break;
}
return V_31 ;
}
int F_42 ( struct V_1 * V_2 ,
struct V_41 * V_42 ,
struct V_78 * V_56 ,
struct V_53 * V_54 )
{
struct V_43 * V_44 ;
unsigned V_97 , V_24 ;
T_1 V_31 = 0 , V_90 ;
T_4 V_79 ;
if ( V_42 -> V_52 == - 1 )
return 0 ;
V_44 = V_43 ( V_56 , V_42 ) ;
if ( V_44 == NULL ) {
F_39 ( V_2 -> V_49 , L_11 , V_56 , V_42 ) ;
return - V_35 ;
}
if ( V_44 -> V_55 && V_54 )
return 0 ;
V_97 = F_69 ( V_56 ) ;
V_44 -> V_79 &= ~ V_98 ;
V_44 -> V_79 &= ~ V_99 ;
if ( V_54 ) {
if ( V_54 -> V_91 != V_100 ) {
V_44 -> V_79 |= V_98 ;
V_44 -> V_55 = true ;
}
if ( V_54 -> V_91 == V_95 ) {
V_44 -> V_79 |= V_99 ;
}
}
V_90 = V_44 -> V_84 / V_28 ;
V_79 = V_2 -> V_45 . V_50 -> V_101 ( V_2 , V_44 -> V_42 , V_44 -> V_79 ) ;
for ( V_24 = 0 , V_31 = 0 ; V_24 < V_97 ; V_24 ++ ) {
if ( V_54 && V_44 -> V_55 ) {
V_31 = F_68 ( V_2 , V_54 , V_24 ) ;
}
V_2 -> V_45 . V_50 -> V_102 ( V_2 , V_44 -> V_42 , V_24 + V_90 , V_31 , V_79 ) ;
}
V_2 -> V_45 . V_50 -> V_103 ( V_2 , V_44 -> V_42 ) ;
return 0 ;
}
int F_70 ( struct V_1 * V_2 ,
struct V_41 * V_42 ,
struct V_78 * V_56 )
{
struct V_43 * V_44 ;
int V_15 ;
V_44 = V_43 ( V_56 , V_42 ) ;
if ( V_44 == NULL )
return 0 ;
while ( V_44 -> V_59 ) {
V_15 = F_44 ( V_44 -> V_59 , false ) ;
if ( V_15 ) {
F_30 ( L_8 , V_15 ) ;
}
if ( V_15 == - V_60 ) {
V_15 = F_46 ( V_2 ) ;
if ( ! V_15 )
continue;
}
break;
}
F_48 ( & V_44 -> V_59 ) ;
F_47 ( & V_2 -> V_45 . V_61 ) ;
F_47 ( & V_42 -> V_69 ) ;
F_42 ( V_2 , V_42 , V_56 , NULL ) ;
F_45 ( & V_2 -> V_45 . V_61 ) ;
F_71 ( & V_44 -> V_87 ) ;
F_45 ( & V_42 -> V_69 ) ;
F_71 ( & V_44 -> V_86 ) ;
F_35 ( V_44 ) ;
return 0 ;
}
void F_72 ( struct V_1 * V_2 ,
struct V_78 * V_56 )
{
struct V_43 * V_44 ;
F_73 ( ! F_74 ( & V_56 -> V_57 . V_104 ) ) ;
F_41 (bo_va, &bo->va, bo_list) {
V_44 -> V_55 = false ;
}
}
int F_75 ( struct V_1 * V_2 , struct V_41 * V_42 )
{
int V_15 ;
V_42 -> V_52 = - 1 ;
V_42 -> V_59 = NULL ;
F_76 ( & V_42 -> V_69 ) ;
F_66 ( & V_42 -> V_64 ) ;
F_66 ( & V_42 -> V_89 ) ;
if ( V_2 -> V_9 >= V_105 )
V_42 -> V_73 = V_2 -> V_45 . V_48 ;
else
V_42 -> V_73 = 0 ;
V_15 = F_64 ( V_2 , V_42 , V_2 -> V_77 . V_56 , 0 ,
V_106 | V_107 ) ;
return V_15 ;
}
void F_77 ( struct V_1 * V_2 , struct V_41 * V_42 )
{
struct V_43 * V_44 , * V_67 ;
int V_15 ;
F_47 ( & V_2 -> V_45 . V_61 ) ;
F_47 ( & V_42 -> V_69 ) ;
F_43 ( V_2 , V_42 ) ;
F_45 ( & V_2 -> V_45 . V_61 ) ;
V_15 = F_11 ( V_2 -> V_77 . V_56 , false ) ;
if ( ! V_15 ) {
V_44 = V_43 ( V_2 -> V_77 . V_56 , V_42 ) ;
F_49 ( & V_44 -> V_86 ) ;
F_49 ( & V_44 -> V_87 ) ;
F_48 ( & V_44 -> V_59 ) ;
F_14 ( V_2 -> V_77 . V_56 ) ;
F_35 ( V_44 ) ;
}
if ( ! F_60 ( & V_42 -> V_89 ) ) {
F_39 ( V_2 -> V_49 , L_12 ) ;
}
F_52 (bo_va, tmp, &vm->va, vm_list) {
F_49 ( & V_44 -> V_87 ) ;
V_15 = F_11 ( V_44 -> V_56 , false ) ;
if ( ! V_15 ) {
F_49 ( & V_44 -> V_86 ) ;
F_48 ( & V_44 -> V_59 ) ;
F_14 ( V_44 -> V_56 ) ;
F_35 ( V_44 ) ;
}
}
F_45 ( & V_42 -> V_69 ) ;
}
