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
& V_2 -> V_5 . V_16 ) ;
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
int V_15 ;
V_2 -> V_41 . V_42 = false ;
V_15 = F_38 ( V_2 , & V_2 -> V_41 . V_43 ,
V_2 -> V_41 . V_44 * 8 ,
V_18 ) ;
if ( V_15 ) {
F_39 ( V_2 -> V_45 , L_5 ,
( V_2 -> V_41 . V_44 * 8 ) >> 10 ) ;
return V_15 ;
}
V_15 = V_2 -> V_41 . V_46 -> V_47 ( V_2 ) ;
if ( V_15 == 0 )
V_2 -> V_41 . V_42 = true ;
return V_15 ;
}
static void F_40 ( struct V_1 * V_2 ,
struct V_48 * V_49 )
{
struct V_50 * V_51 ;
if ( V_49 -> V_52 == - 1 ) {
return;
}
if ( V_49 -> V_53 ) {
F_41 ( V_49 -> V_53 , false ) ;
F_42 ( & V_49 -> V_53 ) ;
}
V_2 -> V_41 . V_46 -> V_54 ( V_2 , V_49 ) ;
V_2 -> V_41 . V_55 &= ~ ( 1 << V_49 -> V_52 ) ;
F_43 ( & V_49 -> V_56 ) ;
V_49 -> V_52 = - 1 ;
F_44 ( V_2 , & V_49 -> V_57 ) ;
V_49 -> V_58 = NULL ;
F_45 (bo_va, &vm->va, vm_list) {
V_51 -> V_59 = false ;
}
}
void F_46 ( struct V_1 * V_2 )
{
if ( V_2 -> V_41 . V_43 . V_60 == NULL )
return;
F_47 ( V_2 ) ;
V_2 -> V_41 . V_46 -> V_61 ( V_2 ) ;
F_48 ( V_2 , & V_2 -> V_41 . V_43 ) ;
V_2 -> V_41 . V_42 = false ;
}
int F_49 ( struct V_1 * V_2 )
{
if ( V_2 -> V_41 . V_43 . V_60 == NULL ) {
return - V_35 ;
}
return F_50 ( V_2 , & V_2 -> V_41 . V_43 ) ;
}
int F_47 ( struct V_1 * V_2 )
{
struct V_48 * V_49 , * V_62 ;
F_51 ( & V_2 -> V_63 ) ;
F_52 (vm, tmp, &rdev->vm_manager.lru_vm, list) {
F_40 ( V_2 , V_49 ) ;
}
V_2 -> V_41 . V_46 -> V_61 ( V_2 ) ;
F_53 ( & V_2 -> V_63 ) ;
return F_54 ( V_2 , & V_2 -> V_41 . V_43 ) ;
}
void F_55 ( struct V_1 * V_2 , struct V_48 * V_49 )
{
F_56 ( & V_49 -> V_64 ) ;
F_40 ( V_2 , V_49 ) ;
F_57 ( & V_49 -> V_64 ) ;
}
int F_58 ( struct V_1 * V_2 , struct V_48 * V_49 )
{
struct V_48 * V_65 ;
unsigned V_24 ;
int V_52 = - 1 , V_15 ;
if ( V_49 == NULL ) {
return - V_35 ;
}
if ( V_49 -> V_52 != - 1 ) {
F_43 ( & V_49 -> V_56 ) ;
F_59 ( & V_49 -> V_56 , & V_2 -> V_41 . V_66 ) ;
return 0 ;
}
V_67:
V_15 = F_60 ( V_2 , & V_2 -> V_41 . V_43 , & V_49 -> V_57 ,
F_61 ( V_49 -> V_68 * 8 ) ,
V_28 ) ;
if ( V_15 ) {
if ( F_62 ( & V_2 -> V_41 . V_66 ) ) {
return V_15 ;
}
V_65 = F_63 ( & V_2 -> V_41 . V_66 , struct V_48 , V_56 ) ;
F_55 ( V_2 , V_65 ) ;
goto V_67;
}
V_49 -> V_58 = V_2 -> V_41 . V_43 . V_69 ;
V_49 -> V_58 += ( V_49 -> V_57 . V_20 >> 3 ) ;
V_49 -> V_70 = V_2 -> V_41 . V_43 . V_19 ;
V_49 -> V_70 += V_49 -> V_57 . V_20 ;
memset ( V_49 -> V_58 , 0 , F_61 ( V_49 -> V_68 * 8 ) ) ;
V_71:
for ( V_24 = 0 ; V_24 < V_2 -> V_41 . V_72 ; V_24 ++ ) {
if ( ! ( V_2 -> V_41 . V_55 & ( 1 << V_24 ) ) ) {
V_52 = V_24 ;
break;
}
}
if ( V_52 == - 1 ) {
V_65 = F_63 ( & V_2 -> V_41 . V_66 , struct V_48 , V_56 ) ;
F_55 ( V_2 , V_65 ) ;
goto V_71;
}
V_15 = V_2 -> V_41 . V_46 -> V_73 ( V_2 , V_49 , V_52 ) ;
if ( V_15 ) {
F_44 ( V_2 , & V_49 -> V_57 ) ;
return V_15 ;
}
V_2 -> V_41 . V_55 |= 1 << V_52 ;
V_49 -> V_52 = V_52 ;
F_59 ( & V_49 -> V_56 , & V_2 -> V_41 . V_66 ) ;
return F_64 ( V_2 , V_49 , V_2 -> V_74 . V_43 . V_60 ,
& V_2 -> V_74 . V_43 . V_60 -> V_75 . V_76 ) ;
}
int F_65 ( struct V_1 * V_2 ,
struct V_48 * V_49 ,
struct V_77 * V_60 ,
T_1 V_20 ,
T_4 V_78 )
{
struct V_50 * V_51 , * V_62 ;
struct V_79 * V_80 ;
T_1 V_81 = F_66 ( V_60 ) , V_82 = 0 ;
unsigned V_68 ;
V_51 = F_33 ( sizeof( struct V_50 ) , V_40 ) ;
if ( V_51 == NULL ) {
return - V_8 ;
}
V_51 -> V_49 = V_49 ;
V_51 -> V_60 = V_60 ;
V_51 -> V_83 = V_20 ;
V_51 -> V_84 = V_20 + V_81 ;
V_51 -> V_78 = V_78 ;
V_51 -> V_59 = false ;
F_67 ( & V_51 -> V_85 ) ;
F_67 ( & V_51 -> V_86 ) ;
if ( V_51 -> V_83 >= V_51 -> V_84 ) {
F_35 ( V_51 ) ;
return - V_35 ;
}
V_68 = V_51 -> V_84 / V_28 ;
if ( V_68 > V_2 -> V_41 . V_44 ) {
F_35 ( V_51 ) ;
F_39 ( V_2 -> V_45 , L_6 ,
V_68 , V_2 -> V_41 . V_44 ) ;
return - V_35 ;
}
F_56 ( & V_49 -> V_64 ) ;
if ( V_68 > V_49 -> V_68 ) {
unsigned V_87 = ( ( 32 << 20 ) >> 12 ) - 1 ;
F_51 ( & V_2 -> V_63 ) ;
F_40 ( V_2 , V_49 ) ;
F_53 ( & V_2 -> V_63 ) ;
V_49 -> V_68 = ( V_68 + V_87 ) & ~ V_87 ;
}
V_80 = & V_49 -> V_88 ;
V_82 = 0 ;
F_45 (tmp, &vm->va, vm_list) {
if ( V_51 -> V_83 >= V_82 && V_51 -> V_84 < V_62 -> V_83 ) {
break;
}
if ( V_51 -> V_83 >= V_62 -> V_83 && V_51 -> V_83 < V_62 -> V_84 ) {
F_39 ( V_2 -> V_45 , L_7 ,
V_60 , ( unsigned ) V_51 -> V_83 , V_62 -> V_60 ,
( unsigned ) V_62 -> V_83 , ( unsigned ) V_62 -> V_84 ) ;
F_35 ( V_51 ) ;
F_57 ( & V_49 -> V_64 ) ;
return - V_35 ;
}
V_82 = V_62 -> V_84 ;
V_80 = & V_62 -> V_86 ;
}
F_68 ( & V_51 -> V_86 , V_80 ) ;
F_59 ( & V_51 -> V_85 , & V_60 -> V_88 ) ;
F_57 ( & V_49 -> V_64 ) ;
return 0 ;
}
static T_2 F_69 ( struct V_1 * V_2 ,
struct V_89 * V_76 ,
unsigned V_90 )
{
T_2 V_31 = 0 ;
switch ( V_76 -> V_91 ) {
case V_92 :
V_31 = ( V_76 -> V_93 << V_14 ) ;
V_31 += V_90 * V_28 ;
V_31 += V_2 -> V_41 . V_94 ;
break;
case V_95 :
V_31 = V_76 -> V_93 << V_14 ;
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
int F_64 ( struct V_1 * V_2 ,
struct V_48 * V_49 ,
struct V_77 * V_60 ,
struct V_89 * V_76 )
{
struct V_50 * V_51 ;
unsigned V_97 , V_24 ;
T_1 V_31 = 0 , V_90 ;
T_4 V_78 ;
if ( V_49 -> V_52 == - 1 )
return 0 ; ;
V_51 = V_50 ( V_60 , V_49 ) ;
if ( V_51 == NULL ) {
F_39 ( V_2 -> V_45 , L_8 , V_60 , V_49 ) ;
return - V_35 ;
}
if ( V_51 -> V_59 )
return 0 ;
V_97 = F_70 ( V_60 ) ;
V_51 -> V_78 &= ~ V_98 ;
V_51 -> V_78 &= ~ V_99 ;
if ( V_76 ) {
if ( V_76 -> V_91 != V_100 ) {
V_51 -> V_78 |= V_98 ;
V_51 -> V_59 = true ;
}
if ( V_76 -> V_91 == V_95 ) {
V_51 -> V_78 |= V_99 ;
}
}
V_90 = V_51 -> V_83 / V_28 ;
V_78 = V_2 -> V_41 . V_46 -> V_101 ( V_2 , V_51 -> V_49 , V_51 -> V_78 ) ;
for ( V_24 = 0 , V_31 = 0 ; V_24 < V_97 ; V_24 ++ ) {
if ( V_76 && V_51 -> V_59 ) {
V_31 = F_69 ( V_2 , V_76 , V_24 ) ;
}
V_2 -> V_41 . V_46 -> V_102 ( V_2 , V_51 -> V_49 , V_24 + V_90 , V_31 , V_78 ) ;
}
V_2 -> V_41 . V_46 -> V_103 ( V_2 , V_51 -> V_49 ) ;
return 0 ;
}
int F_71 ( struct V_1 * V_2 ,
struct V_48 * V_49 ,
struct V_77 * V_60 )
{
struct V_50 * V_51 ;
V_51 = V_50 ( V_60 , V_49 ) ;
if ( V_51 == NULL )
return 0 ;
F_56 ( & V_49 -> V_64 ) ;
F_51 ( & V_2 -> V_63 ) ;
F_64 ( V_2 , V_49 , V_60 , NULL ) ;
F_53 ( & V_2 -> V_63 ) ;
F_72 ( & V_51 -> V_86 ) ;
F_57 ( & V_49 -> V_64 ) ;
F_72 ( & V_51 -> V_85 ) ;
F_35 ( V_51 ) ;
return 0 ;
}
void F_73 ( struct V_1 * V_2 ,
struct V_77 * V_60 )
{
struct V_50 * V_51 ;
F_74 ( ! F_75 ( & V_60 -> V_75 . V_104 ) ) ;
F_45 (bo_va, &bo->va, bo_list) {
V_51 -> V_59 = false ;
}
}
int F_76 ( struct V_1 * V_2 , struct V_48 * V_49 )
{
int V_15 ;
V_49 -> V_52 = - 1 ;
V_49 -> V_53 = NULL ;
F_77 ( & V_49 -> V_64 ) ;
F_67 ( & V_49 -> V_56 ) ;
F_67 ( & V_49 -> V_88 ) ;
V_49 -> V_68 = 0 ;
V_15 = F_65 ( V_2 , V_49 , V_2 -> V_74 . V_43 . V_60 , 0 ,
V_105 | V_106 ) ;
return V_15 ;
}
void F_78 ( struct V_1 * V_2 , struct V_48 * V_49 )
{
struct V_50 * V_51 , * V_62 ;
int V_15 ;
F_56 ( & V_49 -> V_64 ) ;
F_51 ( & V_2 -> V_63 ) ;
F_40 ( V_2 , V_49 ) ;
F_53 ( & V_2 -> V_63 ) ;
V_15 = F_11 ( V_2 -> V_74 . V_43 . V_60 , false ) ;
if ( ! V_15 ) {
V_51 = V_50 ( V_2 -> V_74 . V_43 . V_60 , V_49 ) ;
F_43 ( & V_51 -> V_85 ) ;
F_43 ( & V_51 -> V_86 ) ;
F_14 ( V_2 -> V_74 . V_43 . V_60 ) ;
F_35 ( V_51 ) ;
}
if ( ! F_62 ( & V_49 -> V_88 ) ) {
F_39 ( V_2 -> V_45 , L_9 ) ;
}
F_52 (bo_va, tmp, &vm->va, vm_list) {
F_43 ( & V_51 -> V_86 ) ;
V_15 = F_11 ( V_51 -> V_60 , false ) ;
if ( ! V_15 ) {
F_43 ( & V_51 -> V_85 ) ;
F_14 ( V_51 -> V_60 ) ;
F_35 ( V_51 ) ;
}
}
F_57 ( & V_49 -> V_64 ) ;
}
