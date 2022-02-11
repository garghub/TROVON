int F_1 ( const struct V_1 * V_2 )
{
struct V_3 * V_4 , * V_5 ;
V_4 = F_2 ( sizeof( * V_4 ) , V_6 ) ;
if ( ! V_4 )
return - V_7 ;
V_4 -> V_2 = V_2 ;
F_3 ( & V_8 . V_9 ) ;
F_4 (tmp, &vfio.iommu_drivers_list, vfio_next) {
if ( V_5 -> V_2 == V_2 ) {
F_5 ( & V_8 . V_9 ) ;
F_6 ( V_4 ) ;
return - V_10 ;
}
}
F_7 ( & V_4 -> V_11 , & V_8 . V_12 ) ;
F_5 ( & V_8 . V_9 ) ;
return 0 ;
}
void F_8 ( const struct V_1 * V_2 )
{
struct V_3 * V_4 ;
F_3 ( & V_8 . V_9 ) ;
F_4 (driver, &vfio.iommu_drivers_list, vfio_next) {
if ( V_4 -> V_2 == V_2 ) {
F_9 ( & V_4 -> V_11 ) ;
F_5 ( & V_8 . V_9 ) ;
F_6 ( V_4 ) ;
return;
}
}
F_5 ( & V_8 . V_9 ) ;
}
static int F_10 ( struct V_13 * V_14 )
{
return F_11 ( & V_8 . V_15 , V_14 , 1 , V_16 + 1 , V_6 ) ;
}
static void F_12 ( int V_17 )
{
F_13 ( & V_8 . V_15 , V_17 ) ;
}
static void F_14 ( struct V_18 * V_19 )
{
F_15 ( & V_19 -> V_20 ) ;
}
static void F_16 ( struct V_20 * V_20 )
{
struct V_18 * V_19 ;
V_19 = F_17 ( V_20 , struct V_18 , V_20 ) ;
F_6 ( V_19 ) ;
}
static void F_18 ( struct V_18 * V_19 )
{
F_19 ( & V_19 -> V_20 , F_16 ) ;
}
static void F_20 ( struct V_13 * V_14 )
{
F_5 ( & V_8 . V_21 ) ;
F_21 ( V_14 -> V_22 , & V_14 -> V_23 ) ;
F_6 ( V_14 ) ;
}
static struct V_13 * F_22 ( struct V_22 * V_22 )
{
struct V_13 * V_14 , * V_5 ;
struct V_24 * V_25 ;
int V_26 , V_17 ;
V_14 = F_2 ( sizeof( * V_14 ) , V_6 ) ;
if ( ! V_14 )
return F_23 ( - V_7 ) ;
F_24 ( & V_14 -> V_20 ) ;
F_25 ( & V_14 -> V_27 ) ;
F_26 ( & V_14 -> V_28 ) ;
F_27 ( & V_14 -> V_29 , 0 ) ;
F_27 ( & V_14 -> V_30 , 0 ) ;
V_14 -> V_22 = V_22 ;
V_14 -> V_23 . V_31 = V_32 ;
V_26 = F_28 ( V_22 , & V_14 -> V_23 ) ;
if ( V_26 ) {
F_6 ( V_14 ) ;
return F_23 ( V_26 ) ;
}
F_3 ( & V_8 . V_21 ) ;
V_17 = F_10 ( V_14 ) ;
if ( V_17 < 0 ) {
F_20 ( V_14 ) ;
return F_23 ( V_17 ) ;
}
F_4 (tmp, &vfio.group_list, vfio_next) {
if ( V_5 -> V_22 == V_22 ) {
F_29 ( V_5 ) ;
F_12 ( V_17 ) ;
F_20 ( V_14 ) ;
return V_5 ;
}
}
V_25 = F_30 ( V_8 . V_33 , NULL , F_31 ( F_32 ( V_8 . V_34 ) , V_17 ) ,
V_14 , L_1 , F_33 ( V_22 ) ) ;
if ( F_34 ( V_25 ) ) {
F_12 ( V_17 ) ;
F_20 ( V_14 ) ;
return (struct V_13 * ) V_25 ;
}
V_14 -> V_17 = V_17 ;
V_14 -> V_25 = V_25 ;
F_7 ( & V_14 -> V_11 , & V_8 . V_35 ) ;
F_5 ( & V_8 . V_21 ) ;
return V_14 ;
}
static void F_35 ( struct V_20 * V_20 )
{
struct V_13 * V_14 = F_17 ( V_20 , struct V_13 , V_20 ) ;
F_36 ( ! F_37 ( & V_14 -> V_27 ) ) ;
F_38 ( V_8 . V_33 , F_31 ( F_32 ( V_8 . V_34 ) , V_14 -> V_17 ) ) ;
F_9 ( & V_14 -> V_11 ) ;
F_12 ( V_14 -> V_17 ) ;
F_20 ( V_14 ) ;
}
static void F_39 ( struct V_13 * V_14 )
{
F_40 ( & V_14 -> V_20 , F_35 , & V_8 . V_21 ) ;
}
static void F_29 ( struct V_13 * V_14 )
{
F_15 ( & V_14 -> V_20 ) ;
}
static struct V_13 * F_41 ( struct V_13 * V_14 )
{
struct V_13 * V_36 = V_14 ;
F_3 ( & V_8 . V_21 ) ;
F_4 (group, &vfio.group_list, vfio_next) {
if ( V_14 == V_36 ) {
F_29 ( V_14 ) ;
F_5 ( & V_8 . V_21 ) ;
return V_14 ;
}
}
F_5 ( & V_8 . V_21 ) ;
return NULL ;
}
static
struct V_13 * F_42 ( struct V_22 * V_22 )
{
struct V_13 * V_14 ;
F_3 ( & V_8 . V_21 ) ;
F_4 (group, &vfio.group_list, vfio_next) {
if ( V_14 -> V_22 == V_22 ) {
F_29 ( V_14 ) ;
F_5 ( & V_8 . V_21 ) ;
return V_14 ;
}
}
F_5 ( & V_8 . V_21 ) ;
return NULL ;
}
static struct V_13 * F_43 ( int V_17 )
{
struct V_13 * V_14 ;
F_3 ( & V_8 . V_21 ) ;
V_14 = F_44 ( & V_8 . V_15 , V_17 ) ;
if ( ! V_14 ) {
F_5 ( & V_8 . V_21 ) ;
return NULL ;
}
F_29 ( V_14 ) ;
F_5 ( & V_8 . V_21 ) ;
return V_14 ;
}
static
struct V_37 * F_45 ( struct V_13 * V_14 ,
struct V_24 * V_25 ,
const struct V_38 * V_2 ,
void * V_39 )
{
struct V_37 * V_24 ;
int V_26 ;
V_24 = F_2 ( sizeof( * V_24 ) , V_6 ) ;
if ( ! V_24 )
return F_23 ( - V_7 ) ;
F_24 ( & V_24 -> V_20 ) ;
V_24 -> V_25 = V_25 ;
V_24 -> V_14 = V_14 ;
V_24 -> V_2 = V_2 ;
V_24 -> V_39 = V_39 ;
V_26 = F_46 ( V_25 , V_24 ) ;
if ( V_26 ) {
F_6 ( V_24 ) ;
return F_23 ( V_26 ) ;
}
F_29 ( V_14 ) ;
F_3 ( & V_14 -> V_28 ) ;
F_7 ( & V_24 -> V_40 , & V_14 -> V_27 ) ;
F_5 ( & V_14 -> V_28 ) ;
return V_24 ;
}
static void F_47 ( struct V_20 * V_20 )
{
struct V_37 * V_24 = F_17 ( V_20 ,
struct V_37 , V_20 ) ;
struct V_13 * V_14 = V_24 -> V_14 ;
F_9 ( & V_24 -> V_40 ) ;
F_5 ( & V_14 -> V_28 ) ;
F_46 ( V_24 -> V_25 , NULL ) ;
F_6 ( V_24 ) ;
F_48 ( & V_8 . V_41 ) ;
}
void F_49 ( struct V_37 * V_24 )
{
struct V_13 * V_14 = V_24 -> V_14 ;
F_40 ( & V_24 -> V_20 , F_47 , & V_14 -> V_28 ) ;
F_39 ( V_14 ) ;
}
static void F_50 ( struct V_37 * V_24 )
{
F_29 ( V_24 -> V_14 ) ;
F_15 ( & V_24 -> V_20 ) ;
}
static struct V_37 * F_51 ( struct V_13 * V_14 ,
struct V_24 * V_25 )
{
struct V_37 * V_24 ;
F_3 ( & V_14 -> V_28 ) ;
F_4 (device, &group->device_list, group_next) {
if ( V_24 -> V_25 == V_25 ) {
F_50 ( V_24 ) ;
F_5 ( & V_14 -> V_28 ) ;
return V_24 ;
}
}
F_5 ( & V_14 -> V_28 ) ;
return NULL ;
}
static bool F_52 ( struct V_42 * V_43 )
{
int V_44 ;
for ( V_44 = 0 ; V_44 < F_53 ( V_45 ) ; V_44 ++ ) {
if ( ! strcmp ( V_43 -> V_46 , V_45 [ V_44 ] ) )
return true ;
}
return false ;
}
static int F_54 ( struct V_24 * V_25 , void * V_47 )
{
struct V_13 * V_14 = V_47 ;
struct V_37 * V_24 ;
struct V_42 * V_43 = F_55 ( V_25 -> V_4 ) ;
if ( ! V_43 || F_52 ( V_43 ) )
return 0 ;
V_24 = F_51 ( V_14 , V_25 ) ;
if ( V_24 ) {
F_49 ( V_24 ) ;
return 0 ;
}
return - V_10 ;
}
static int F_56 ( struct V_13 * V_14 , struct V_24 * V_25 )
{
struct V_37 * V_24 ;
V_24 = F_51 ( V_14 , V_25 ) ;
if ( F_57 ( V_24 ) ) {
F_49 ( V_24 ) ;
return 0 ;
}
if ( ! F_58 ( & V_14 -> V_29 ) )
return 0 ;
F_59 ( L_2 , F_60 ( V_25 ) ,
F_33 ( V_14 -> V_22 ) ) ;
return 0 ;
}
static int F_61 ( struct V_13 * V_14 , struct V_24 * V_25 )
{
if ( ! F_58 ( & V_14 -> V_29 ) )
return 0 ;
return F_54 ( V_25 , V_14 ) ;
}
static int V_32 ( struct V_48 * V_23 ,
unsigned long V_49 , void * V_47 )
{
struct V_13 * V_14 = F_17 ( V_23 , struct V_13 , V_23 ) ;
struct V_24 * V_25 = V_47 ;
V_14 = F_41 ( V_14 ) ;
if ( ! V_14 )
return V_50 ;
switch ( V_49 ) {
case V_51 :
F_56 ( V_14 , V_25 ) ;
break;
case V_52 :
break;
case V_53 :
F_62 ( L_3 ,
V_54 , F_60 ( V_25 ) ,
F_33 ( V_14 -> V_22 ) ) ;
break;
case V_55 :
F_62 ( L_4 ,
V_54 , F_60 ( V_25 ) ,
F_33 ( V_14 -> V_22 ) , V_25 -> V_4 -> V_46 ) ;
F_63 ( F_61 ( V_14 , V_25 ) ) ;
break;
case V_56 :
F_62 ( L_5 ,
V_54 , F_60 ( V_25 ) ,
F_33 ( V_14 -> V_22 ) , V_25 -> V_4 -> V_46 ) ;
break;
case V_57 :
F_62 ( L_6 ,
V_54 , F_60 ( V_25 ) ,
F_33 ( V_14 -> V_22 ) ) ;
break;
}
F_39 ( V_14 ) ;
return V_50 ;
}
int F_64 ( struct V_24 * V_25 ,
const struct V_38 * V_2 , void * V_39 )
{
struct V_22 * V_22 ;
struct V_13 * V_14 ;
struct V_37 * V_24 ;
V_22 = F_65 ( V_25 ) ;
if ( ! V_22 )
return - V_10 ;
V_14 = F_42 ( V_22 ) ;
if ( ! V_14 ) {
V_14 = F_22 ( V_22 ) ;
if ( F_34 ( V_14 ) ) {
F_66 ( V_22 ) ;
return F_67 ( V_14 ) ;
}
}
V_24 = F_51 ( V_14 , V_25 ) ;
if ( V_24 ) {
F_59 ( 1 , L_7 ,
F_60 ( V_25 ) , F_33 ( V_22 ) ) ;
F_49 ( V_24 ) ;
F_39 ( V_14 ) ;
F_66 ( V_22 ) ;
return - V_58 ;
}
V_24 = F_45 ( V_14 , V_25 , V_2 , V_39 ) ;
if ( F_34 ( V_24 ) ) {
F_39 ( V_14 ) ;
F_66 ( V_22 ) ;
return F_67 ( V_24 ) ;
}
F_39 ( V_14 ) ;
return 0 ;
}
struct V_37 * F_68 ( struct V_24 * V_25 )
{
struct V_37 * V_24 = F_69 ( V_25 ) ;
F_50 ( V_24 ) ;
return V_24 ;
}
void * F_70 ( struct V_37 * V_24 )
{
return V_24 -> V_39 ;
}
static bool F_71 ( struct V_13 * V_14 , struct V_24 * V_25 )
{
struct V_37 * V_24 ;
V_24 = F_51 ( V_14 , V_25 ) ;
if ( ! V_24 )
return false ;
F_49 ( V_24 ) ;
return true ;
}
void * F_72 ( struct V_24 * V_25 )
{
struct V_37 * V_24 = F_69 ( V_25 ) ;
struct V_13 * V_14 = V_24 -> V_14 ;
struct V_22 * V_22 = V_14 -> V_22 ;
void * V_39 = V_24 -> V_39 ;
F_29 ( V_14 ) ;
F_49 ( V_24 ) ;
F_73 ( V_8 . V_41 , ! F_71 ( V_14 , V_25 ) ) ;
F_39 ( V_14 ) ;
F_66 ( V_22 ) ;
return V_39 ;
}
static long F_74 ( struct V_18 * V_19 ,
unsigned long V_59 )
{
struct V_3 * V_4 ;
long V_26 = 0 ;
F_75 ( & V_19 -> V_21 ) ;
V_4 = V_19 -> V_60 ;
switch ( V_59 ) {
default:
if ( ! V_4 ) {
F_3 ( & V_8 . V_9 ) ;
F_4 (driver, &vfio.iommu_drivers_list,
vfio_next) {
if ( ! F_76 ( V_4 -> V_2 -> V_61 ) )
continue;
V_26 = V_4 -> V_2 -> V_62 ( NULL ,
V_63 ,
V_59 ) ;
F_77 ( V_4 -> V_2 -> V_61 ) ;
if ( V_26 > 0 )
break;
}
F_5 ( & V_8 . V_9 ) ;
} else
V_26 = V_4 -> V_2 -> V_62 ( V_19 -> V_64 ,
V_63 , V_59 ) ;
}
F_78 ( & V_19 -> V_21 ) ;
return V_26 ;
}
static int F_79 ( struct V_18 * V_19 ,
struct V_3 * V_4 ,
void * V_47 )
{
struct V_13 * V_14 ;
int V_26 = - V_65 ;
F_4 (group, &container->group_list, container_next) {
V_26 = V_4 -> V_2 -> V_66 ( V_47 , V_14 -> V_22 ) ;
if ( V_26 )
goto V_67;
}
return V_26 ;
V_67:
F_80 (group, &container->group_list,
container_next) {
V_4 -> V_2 -> V_68 ( V_47 , V_14 -> V_22 ) ;
}
return V_26 ;
}
static long F_81 ( struct V_18 * V_19 ,
unsigned long V_59 )
{
struct V_3 * V_4 ;
long V_26 = - V_65 ;
F_82 ( & V_19 -> V_21 ) ;
if ( F_37 ( & V_19 -> V_35 ) || V_19 -> V_60 ) {
F_83 ( & V_19 -> V_21 ) ;
return - V_10 ;
}
F_3 ( & V_8 . V_9 ) ;
F_4 (driver, &vfio.iommu_drivers_list, vfio_next) {
void * V_47 ;
if ( ! F_76 ( V_4 -> V_2 -> V_61 ) )
continue;
if ( V_4 -> V_2 -> V_62 ( NULL , V_63 , V_59 ) <= 0 ) {
F_77 ( V_4 -> V_2 -> V_61 ) ;
continue;
}
F_5 ( & V_8 . V_9 ) ;
V_47 = V_4 -> V_2 -> V_69 ( V_59 ) ;
if ( F_34 ( V_47 ) ) {
V_26 = F_67 ( V_47 ) ;
F_77 ( V_4 -> V_2 -> V_61 ) ;
goto V_70;
}
V_26 = F_79 ( V_19 , V_4 , V_47 ) ;
if ( ! V_26 ) {
V_19 -> V_60 = V_4 ;
V_19 -> V_64 = V_47 ;
} else {
V_4 -> V_2 -> V_71 ( V_47 ) ;
F_77 ( V_4 -> V_2 -> V_61 ) ;
}
goto V_70;
}
F_5 ( & V_8 . V_9 ) ;
V_70:
F_83 ( & V_19 -> V_21 ) ;
return V_26 ;
}
static long F_84 ( struct V_72 * V_73 ,
unsigned int V_74 , unsigned long V_59 )
{
struct V_18 * V_19 = V_73 -> V_75 ;
struct V_3 * V_4 ;
void * V_47 ;
long V_26 = - V_10 ;
if ( ! V_19 )
return V_26 ;
switch ( V_74 ) {
case V_76 :
V_26 = V_77 ;
break;
case V_63 :
V_26 = F_74 ( V_19 , V_59 ) ;
break;
case V_78 :
V_26 = F_81 ( V_19 , V_59 ) ;
break;
default:
F_75 ( & V_19 -> V_21 ) ;
V_4 = V_19 -> V_60 ;
V_47 = V_19 -> V_64 ;
if ( V_4 )
V_26 = V_4 -> V_2 -> V_62 ( V_47 , V_74 , V_59 ) ;
F_78 ( & V_19 -> V_21 ) ;
}
return V_26 ;
}
static long F_85 ( struct V_72 * V_73 ,
unsigned int V_74 , unsigned long V_59 )
{
V_59 = ( unsigned long ) F_86 ( V_59 ) ;
return F_84 ( V_73 , V_74 , V_59 ) ;
}
static int F_87 ( struct V_79 * V_79 , struct V_72 * V_73 )
{
struct V_18 * V_19 ;
V_19 = F_2 ( sizeof( * V_19 ) , V_6 ) ;
if ( ! V_19 )
return - V_7 ;
F_25 ( & V_19 -> V_35 ) ;
F_88 ( & V_19 -> V_21 ) ;
F_24 ( & V_19 -> V_20 ) ;
V_73 -> V_75 = V_19 ;
return 0 ;
}
static int F_89 ( struct V_79 * V_79 , struct V_72 * V_73 )
{
struct V_18 * V_19 = V_73 -> V_75 ;
V_73 -> V_75 = NULL ;
F_18 ( V_19 ) ;
return 0 ;
}
static T_1 F_90 ( struct V_72 * V_73 , char T_2 * V_80 ,
T_3 V_81 , T_4 * V_82 )
{
struct V_18 * V_19 = V_73 -> V_75 ;
struct V_3 * V_4 ;
T_1 V_26 = - V_10 ;
F_75 ( & V_19 -> V_21 ) ;
V_4 = V_19 -> V_60 ;
if ( F_91 ( V_4 && V_4 -> V_2 -> V_83 ) )
V_26 = V_4 -> V_2 -> V_83 ( V_19 -> V_64 ,
V_80 , V_81 , V_82 ) ;
F_78 ( & V_19 -> V_21 ) ;
return V_26 ;
}
static T_1 F_92 ( struct V_72 * V_73 , const char T_2 * V_80 ,
T_3 V_81 , T_4 * V_82 )
{
struct V_18 * V_19 = V_73 -> V_75 ;
struct V_3 * V_4 ;
T_1 V_26 = - V_10 ;
F_75 ( & V_19 -> V_21 ) ;
V_4 = V_19 -> V_60 ;
if ( F_91 ( V_4 && V_4 -> V_2 -> V_84 ) )
V_26 = V_4 -> V_2 -> V_84 ( V_19 -> V_64 ,
V_80 , V_81 , V_82 ) ;
F_78 ( & V_19 -> V_21 ) ;
return V_26 ;
}
static int F_93 ( struct V_72 * V_73 , struct V_85 * V_86 )
{
struct V_18 * V_19 = V_73 -> V_75 ;
struct V_3 * V_4 ;
int V_26 = - V_10 ;
F_75 ( & V_19 -> V_21 ) ;
V_4 = V_19 -> V_60 ;
if ( F_91 ( V_4 && V_4 -> V_2 -> V_87 ) )
V_26 = V_4 -> V_2 -> V_87 ( V_19 -> V_64 , V_86 ) ;
F_78 ( & V_19 -> V_21 ) ;
return V_26 ;
}
static void F_94 ( struct V_13 * V_14 )
{
struct V_18 * V_19 = V_14 -> V_19 ;
struct V_3 * V_4 ;
F_82 ( & V_19 -> V_21 ) ;
V_4 = V_19 -> V_60 ;
if ( V_4 )
V_4 -> V_2 -> V_68 ( V_19 -> V_64 ,
V_14 -> V_22 ) ;
V_14 -> V_19 = NULL ;
F_9 ( & V_14 -> V_88 ) ;
if ( V_4 && F_37 ( & V_19 -> V_35 ) ) {
V_4 -> V_2 -> V_71 ( V_19 -> V_64 ) ;
F_77 ( V_4 -> V_2 -> V_61 ) ;
V_19 -> V_60 = NULL ;
V_19 -> V_64 = NULL ;
}
F_83 ( & V_19 -> V_21 ) ;
F_18 ( V_19 ) ;
}
static int F_95 ( struct V_13 * V_14 )
{
int V_89 = F_96 ( & V_14 -> V_29 , 1 , 0 ) ;
if ( ! V_89 )
return - V_10 ;
if ( V_89 != 1 )
return - V_58 ;
F_94 ( V_14 ) ;
return 0 ;
}
static void F_97 ( struct V_13 * V_14 )
{
if ( 0 == F_98 ( & V_14 -> V_29 ) )
F_94 ( V_14 ) ;
}
static int F_99 ( struct V_13 * V_14 , int V_90 )
{
struct V_91 V_92 ;
struct V_18 * V_19 ;
struct V_3 * V_4 ;
int V_26 = 0 ;
if ( F_58 ( & V_14 -> V_29 ) )
return - V_10 ;
V_92 = F_100 ( V_90 ) ;
if ( ! V_92 . V_72 )
return - V_93 ;
if ( V_92 . V_72 -> V_94 != & V_95 ) {
F_101 ( V_92 ) ;
return - V_10 ;
}
V_19 = V_92 . V_72 -> V_75 ;
F_36 ( ! V_19 ) ;
F_82 ( & V_19 -> V_21 ) ;
V_4 = V_19 -> V_60 ;
if ( V_4 ) {
V_26 = V_4 -> V_2 -> V_66 ( V_19 -> V_64 ,
V_14 -> V_22 ) ;
if ( V_26 )
goto V_96;
}
V_14 -> V_19 = V_19 ;
F_7 ( & V_14 -> V_88 , & V_19 -> V_35 ) ;
F_14 ( V_19 ) ;
F_102 ( & V_14 -> V_29 ) ;
V_96:
F_83 ( & V_19 -> V_21 ) ;
F_101 ( V_92 ) ;
return V_26 ;
}
static bool F_103 ( struct V_13 * V_14 )
{
return ( F_104 ( V_14 -> V_22 ,
V_14 , F_54 ) == 0 ) ;
}
static int F_105 ( struct V_13 * V_14 , char * V_80 )
{
struct V_37 * V_24 ;
struct V_72 * V_73 ;
int V_26 = - V_65 ;
if ( 0 == F_58 ( & V_14 -> V_29 ) ||
! V_14 -> V_19 -> V_60 || ! F_103 ( V_14 ) )
return - V_10 ;
F_3 ( & V_14 -> V_28 ) ;
F_4 (device, &group->device_list, group_next) {
if ( strcmp ( F_60 ( V_24 -> V_25 ) , V_80 ) )
continue;
V_26 = V_24 -> V_2 -> V_69 ( V_24 -> V_39 ) ;
if ( V_26 )
break;
V_26 = F_106 () ;
if ( V_26 < 0 ) {
V_24 -> V_2 -> V_71 ( V_24 -> V_39 ) ;
break;
}
V_73 = F_107 ( L_8 , & V_97 ,
V_24 , V_98 ) ;
if ( F_34 ( V_73 ) ) {
F_108 ( V_26 ) ;
V_26 = F_67 ( V_73 ) ;
V_24 -> V_2 -> V_71 ( V_24 -> V_39 ) ;
break;
}
V_73 -> V_99 |= ( V_100 | V_101 | V_102 ) ;
F_50 ( V_24 ) ;
F_102 ( & V_14 -> V_29 ) ;
F_109 ( V_26 , V_73 ) ;
break;
}
F_5 ( & V_14 -> V_28 ) ;
return V_26 ;
}
static long F_110 ( struct V_72 * V_73 ,
unsigned int V_74 , unsigned long V_59 )
{
struct V_13 * V_14 = V_73 -> V_75 ;
long V_26 = - V_103 ;
switch ( V_74 ) {
case V_104 :
{
struct V_105 V_106 ;
unsigned long V_107 ;
V_107 = F_111 ( struct V_105 , V_108 ) ;
if ( F_112 ( & V_106 , ( void T_2 * ) V_59 , V_107 ) )
return - V_109 ;
if ( V_106 . V_110 < V_107 )
return - V_10 ;
V_106 . V_108 = 0 ;
if ( F_103 ( V_14 ) )
V_106 . V_108 |= V_111 ;
if ( V_14 -> V_19 )
V_106 . V_108 |= V_112 ;
if ( F_113 ( ( void T_2 * ) V_59 , & V_106 , V_107 ) )
return - V_109 ;
V_26 = 0 ;
break;
}
case V_113 :
{
int V_91 ;
if ( F_114 ( V_91 , ( int T_2 * ) V_59 ) )
return - V_109 ;
if ( V_91 < 0 )
return - V_10 ;
V_26 = F_99 ( V_14 , V_91 ) ;
break;
}
case V_114 :
V_26 = F_95 ( V_14 ) ;
break;
case V_115 :
{
char * V_80 ;
V_80 = F_115 ( ( const char T_2 * ) V_59 , V_116 ) ;
if ( F_34 ( V_80 ) )
return F_67 ( V_80 ) ;
V_26 = F_105 ( V_14 , V_80 ) ;
F_6 ( V_80 ) ;
break;
}
}
return V_26 ;
}
static long F_116 ( struct V_72 * V_73 ,
unsigned int V_74 , unsigned long V_59 )
{
V_59 = ( unsigned long ) F_86 ( V_59 ) ;
return F_110 ( V_73 , V_74 , V_59 ) ;
}
static int F_117 ( struct V_79 * V_79 , struct V_72 * V_73 )
{
struct V_13 * V_14 ;
int V_30 ;
V_14 = F_43 ( F_118 ( V_79 ) ) ;
if ( ! V_14 )
return - V_65 ;
V_30 = F_96 ( & V_14 -> V_30 , 0 , 1 ) ;
if ( V_30 ) {
F_39 ( V_14 ) ;
return - V_58 ;
}
if ( V_14 -> V_19 ) {
F_119 ( & V_14 -> V_30 ) ;
F_39 ( V_14 ) ;
return - V_58 ;
}
V_73 -> V_75 = V_14 ;
return 0 ;
}
static int F_120 ( struct V_79 * V_79 , struct V_72 * V_73 )
{
struct V_13 * V_14 = V_73 -> V_75 ;
V_73 -> V_75 = NULL ;
F_97 ( V_14 ) ;
F_119 ( & V_14 -> V_30 ) ;
F_39 ( V_14 ) ;
return 0 ;
}
static int F_121 ( struct V_79 * V_79 , struct V_72 * V_73 )
{
struct V_37 * V_24 = V_73 -> V_75 ;
V_24 -> V_2 -> V_71 ( V_24 -> V_39 ) ;
F_97 ( V_24 -> V_14 ) ;
F_49 ( V_24 ) ;
return 0 ;
}
static long F_122 ( struct V_72 * V_73 ,
unsigned int V_74 , unsigned long V_59 )
{
struct V_37 * V_24 = V_73 -> V_75 ;
if ( F_123 ( ! V_24 -> V_2 -> V_62 ) )
return - V_10 ;
return V_24 -> V_2 -> V_62 ( V_24 -> V_39 , V_74 , V_59 ) ;
}
static T_1 F_124 ( struct V_72 * V_73 , char T_2 * V_80 ,
T_3 V_81 , T_4 * V_82 )
{
struct V_37 * V_24 = V_73 -> V_75 ;
if ( F_123 ( ! V_24 -> V_2 -> V_83 ) )
return - V_10 ;
return V_24 -> V_2 -> V_83 ( V_24 -> V_39 , V_80 , V_81 , V_82 ) ;
}
static T_1 F_125 ( struct V_72 * V_73 ,
const char T_2 * V_80 ,
T_3 V_81 , T_4 * V_82 )
{
struct V_37 * V_24 = V_73 -> V_75 ;
if ( F_123 ( ! V_24 -> V_2 -> V_84 ) )
return - V_10 ;
return V_24 -> V_2 -> V_84 ( V_24 -> V_39 , V_80 , V_81 , V_82 ) ;
}
static int F_126 ( struct V_72 * V_73 , struct V_85 * V_86 )
{
struct V_37 * V_24 = V_73 -> V_75 ;
if ( F_123 ( ! V_24 -> V_2 -> V_87 ) )
return - V_10 ;
return V_24 -> V_2 -> V_87 ( V_24 -> V_39 , V_86 ) ;
}
static long F_127 ( struct V_72 * V_73 ,
unsigned int V_74 , unsigned long V_59 )
{
V_59 = ( unsigned long ) F_86 ( V_59 ) ;
return F_122 ( V_73 , V_74 , V_59 ) ;
}
static char * F_128 ( struct V_24 * V_25 , T_5 * V_117 )
{
if ( V_117 && ( F_129 ( V_25 -> V_34 ) == 0 ) )
* V_117 = V_118 | V_119 ;
return F_130 ( V_6 , L_9 , F_60 ( V_25 ) ) ;
}
static int T_6 F_131 ( void )
{
int V_26 ;
F_132 ( & V_8 . V_15 ) ;
F_26 ( & V_8 . V_21 ) ;
F_26 ( & V_8 . V_9 ) ;
F_25 ( & V_8 . V_35 ) ;
F_25 ( & V_8 . V_12 ) ;
F_133 ( & V_8 . V_41 ) ;
V_8 . V_33 = F_134 ( V_120 , L_10 ) ;
if ( F_34 ( V_8 . V_33 ) ) {
V_26 = F_67 ( V_8 . V_33 ) ;
goto V_121;
}
V_8 . V_33 -> V_122 = F_128 ;
V_26 = F_135 ( & V_8 . V_34 , 0 , V_16 , L_10 ) ;
if ( V_26 )
goto V_123;
F_136 ( & V_8 . V_124 , & V_95 ) ;
V_26 = F_137 ( & V_8 . V_124 , V_8 . V_34 , 1 ) ;
if ( V_26 )
goto V_125;
V_8 . V_25 = F_30 ( V_8 . V_33 , NULL , V_8 . V_34 , NULL , L_10 ) ;
if ( F_34 ( V_8 . V_25 ) ) {
V_26 = F_67 ( V_8 . V_25 ) ;
goto V_126;
}
F_136 ( & V_8 . V_127 , & V_128 ) ;
V_26 = F_137 ( & V_8 . V_127 ,
F_31 ( F_32 ( V_8 . V_34 ) , 1 ) , V_16 - 1 ) ;
if ( V_26 )
goto V_129;
F_138 ( V_130 L_11 V_131 L_12 ) ;
F_139 ( L_13 ) ;
F_139 ( L_14 ) ;
return 0 ;
V_129:
F_38 ( V_8 . V_33 , V_8 . V_34 ) ;
V_126:
F_140 ( & V_8 . V_124 ) ;
V_125:
F_141 ( V_8 . V_34 , V_16 ) ;
V_123:
F_142 ( V_8 . V_33 ) ;
V_8 . V_33 = NULL ;
V_121:
return V_26 ;
}
static void T_7 F_143 ( void )
{
F_36 ( ! F_37 ( & V_8 . V_35 ) ) ;
F_144 ( & V_8 . V_15 ) ;
F_140 ( & V_8 . V_127 ) ;
F_38 ( V_8 . V_33 , V_8 . V_34 ) ;
F_140 ( & V_8 . V_124 ) ;
F_141 ( V_8 . V_34 , V_16 ) ;
F_142 ( V_8 . V_33 ) ;
V_8 . V_33 = NULL ;
}
