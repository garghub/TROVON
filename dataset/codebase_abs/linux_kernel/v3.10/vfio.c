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
V_14 -> V_22 = V_22 ;
V_14 -> V_23 . V_30 = V_31 ;
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
V_25 = F_30 ( V_8 . V_32 , NULL , F_31 ( F_32 ( V_8 . V_33 ) , V_17 ) ,
V_14 , L_1 , F_33 ( V_22 ) ) ;
if ( F_34 ( V_25 ) ) {
F_12 ( V_17 ) ;
F_20 ( V_14 ) ;
return (struct V_13 * ) V_25 ;
}
V_14 -> V_17 = V_17 ;
V_14 -> V_25 = V_25 ;
F_7 ( & V_14 -> V_11 , & V_8 . V_34 ) ;
F_5 ( & V_8 . V_21 ) ;
return V_14 ;
}
static void F_35 ( struct V_20 * V_20 )
{
struct V_13 * V_14 = F_17 ( V_20 , struct V_13 , V_20 ) ;
F_36 ( ! F_37 ( & V_14 -> V_27 ) ) ;
F_38 ( V_8 . V_32 , F_31 ( F_32 ( V_8 . V_33 ) , V_14 -> V_17 ) ) ;
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
struct V_13 * V_35 = V_14 ;
F_3 ( & V_8 . V_21 ) ;
F_4 (group, &vfio.group_list, vfio_next) {
if ( V_14 == V_35 ) {
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
struct V_36 * F_45 ( struct V_13 * V_14 ,
struct V_24 * V_25 ,
const struct V_37 * V_2 ,
void * V_38 )
{
struct V_36 * V_24 ;
int V_26 ;
V_24 = F_2 ( sizeof( * V_24 ) , V_6 ) ;
if ( ! V_24 )
return F_23 ( - V_7 ) ;
F_24 ( & V_24 -> V_20 ) ;
V_24 -> V_25 = V_25 ;
V_24 -> V_14 = V_14 ;
V_24 -> V_2 = V_2 ;
V_24 -> V_38 = V_38 ;
V_26 = F_46 ( V_25 , V_24 ) ;
if ( V_26 ) {
F_6 ( V_24 ) ;
return F_23 ( V_26 ) ;
}
F_29 ( V_14 ) ;
F_3 ( & V_14 -> V_28 ) ;
F_7 ( & V_24 -> V_39 , & V_14 -> V_27 ) ;
F_5 ( & V_14 -> V_28 ) ;
return V_24 ;
}
static void F_47 ( struct V_20 * V_20 )
{
struct V_36 * V_24 = F_17 ( V_20 ,
struct V_36 , V_20 ) ;
struct V_13 * V_14 = V_24 -> V_14 ;
F_9 ( & V_24 -> V_39 ) ;
F_5 ( & V_14 -> V_28 ) ;
F_46 ( V_24 -> V_25 , NULL ) ;
F_6 ( V_24 ) ;
F_48 ( & V_8 . V_40 ) ;
}
void F_49 ( struct V_36 * V_24 )
{
struct V_13 * V_14 = V_24 -> V_14 ;
F_40 ( & V_24 -> V_20 , F_47 , & V_14 -> V_28 ) ;
F_39 ( V_14 ) ;
}
static void F_50 ( struct V_36 * V_24 )
{
F_29 ( V_24 -> V_14 ) ;
F_15 ( & V_24 -> V_20 ) ;
}
static struct V_36 * F_51 ( struct V_13 * V_14 ,
struct V_24 * V_25 )
{
struct V_36 * V_24 ;
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
static bool F_52 ( struct V_41 * V_42 )
{
int V_43 ;
for ( V_43 = 0 ; V_43 < F_53 ( V_44 ) ; V_43 ++ ) {
if ( ! strcmp ( V_42 -> V_45 , V_44 [ V_43 ] ) )
return true ;
}
return false ;
}
static int F_54 ( struct V_24 * V_25 , void * V_46 )
{
struct V_13 * V_14 = V_46 ;
struct V_36 * V_24 ;
struct V_41 * V_42 = F_55 ( V_25 -> V_4 ) ;
if ( ! V_42 || F_52 ( V_42 ) )
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
struct V_36 * V_24 ;
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
struct V_36 * V_24 ;
V_24 = F_51 ( V_14 , V_25 ) ;
if ( F_62 ( ! V_24 ) )
return 0 ;
F_59 ( L_3 , F_60 ( V_25 ) ,
F_33 ( V_14 -> V_22 ) ) ;
F_49 ( V_24 ) ;
return 0 ;
}
static int F_63 ( struct V_13 * V_14 , struct V_24 * V_25 )
{
if ( ! F_58 ( & V_14 -> V_29 ) )
return 0 ;
return F_54 ( V_25 , V_14 ) ;
}
static int V_31 ( struct V_47 * V_23 ,
unsigned long V_48 , void * V_46 )
{
struct V_13 * V_14 = F_17 ( V_23 , struct V_13 , V_23 ) ;
struct V_24 * V_25 = V_46 ;
V_14 = F_41 ( V_14 ) ;
if ( F_36 ( ! V_14 ) )
return V_49 ;
switch ( V_48 ) {
case V_50 :
F_56 ( V_14 , V_25 ) ;
break;
case V_51 :
F_61 ( V_14 , V_25 ) ;
break;
case V_52 :
F_64 ( L_4 ,
V_53 , F_60 ( V_25 ) ,
F_33 ( V_14 -> V_22 ) ) ;
break;
case V_54 :
F_64 ( L_5 ,
V_53 , F_60 ( V_25 ) ,
F_33 ( V_14 -> V_22 ) , V_25 -> V_4 -> V_45 ) ;
F_65 ( F_63 ( V_14 , V_25 ) ) ;
break;
case V_55 :
F_64 ( L_6 ,
V_53 , F_60 ( V_25 ) ,
F_33 ( V_14 -> V_22 ) , V_25 -> V_4 -> V_45 ) ;
break;
case V_56 :
F_64 ( L_7 ,
V_53 , F_60 ( V_25 ) ,
F_33 ( V_14 -> V_22 ) ) ;
break;
}
F_39 ( V_14 ) ;
return V_49 ;
}
int F_66 ( struct V_24 * V_25 ,
const struct V_37 * V_2 , void * V_38 )
{
struct V_22 * V_22 ;
struct V_13 * V_14 ;
struct V_36 * V_24 ;
V_22 = F_67 ( V_25 ) ;
if ( ! V_22 )
return - V_10 ;
V_14 = F_42 ( V_22 ) ;
if ( ! V_14 ) {
V_14 = F_22 ( V_22 ) ;
if ( F_34 ( V_14 ) ) {
F_68 ( V_22 ) ;
return F_69 ( V_14 ) ;
}
}
V_24 = F_51 ( V_14 , V_25 ) ;
if ( V_24 ) {
F_59 ( 1 , L_8 ,
F_60 ( V_25 ) , F_33 ( V_22 ) ) ;
F_49 ( V_24 ) ;
F_39 ( V_14 ) ;
F_68 ( V_22 ) ;
return - V_57 ;
}
V_24 = F_45 ( V_14 , V_25 , V_2 , V_38 ) ;
if ( F_34 ( V_24 ) ) {
F_39 ( V_14 ) ;
F_68 ( V_22 ) ;
return F_69 ( V_24 ) ;
}
F_39 ( V_14 ) ;
return 0 ;
}
struct V_36 * F_70 ( struct V_24 * V_25 )
{
struct V_36 * V_24 = F_71 ( V_25 ) ;
F_50 ( V_24 ) ;
return V_24 ;
}
void * F_72 ( struct V_36 * V_24 )
{
return V_24 -> V_38 ;
}
static bool F_73 ( struct V_13 * V_14 , struct V_24 * V_25 )
{
struct V_36 * V_24 ;
V_24 = F_51 ( V_14 , V_25 ) ;
if ( ! V_24 )
return false ;
F_49 ( V_24 ) ;
return true ;
}
void * F_74 ( struct V_24 * V_25 )
{
struct V_36 * V_24 = F_71 ( V_25 ) ;
struct V_13 * V_14 = V_24 -> V_14 ;
struct V_22 * V_22 = V_14 -> V_22 ;
void * V_38 = V_24 -> V_38 ;
F_29 ( V_14 ) ;
F_49 ( V_24 ) ;
F_75 ( V_8 . V_40 , ! F_73 ( V_14 , V_25 ) ) ;
F_39 ( V_14 ) ;
F_68 ( V_22 ) ;
return V_38 ;
}
static long F_76 ( struct V_18 * V_19 ,
unsigned long V_58 )
{
struct V_3 * V_4 ;
long V_26 = 0 ;
F_77 ( & V_19 -> V_21 ) ;
V_4 = V_19 -> V_59 ;
switch ( V_58 ) {
default:
if ( ! V_4 ) {
F_3 ( & V_8 . V_9 ) ;
F_4 (driver, &vfio.iommu_drivers_list,
vfio_next) {
if ( ! F_78 ( V_4 -> V_2 -> V_60 ) )
continue;
V_26 = V_4 -> V_2 -> V_61 ( NULL ,
V_62 ,
V_58 ) ;
F_79 ( V_4 -> V_2 -> V_60 ) ;
if ( V_26 > 0 )
break;
}
F_5 ( & V_8 . V_9 ) ;
} else
V_26 = V_4 -> V_2 -> V_61 ( V_19 -> V_63 ,
V_62 , V_58 ) ;
}
F_80 ( & V_19 -> V_21 ) ;
return V_26 ;
}
static int F_81 ( struct V_18 * V_19 ,
struct V_3 * V_4 ,
void * V_46 )
{
struct V_13 * V_14 ;
int V_26 = - V_64 ;
F_4 (group, &container->group_list, container_next) {
V_26 = V_4 -> V_2 -> V_65 ( V_46 , V_14 -> V_22 ) ;
if ( V_26 )
goto V_66;
}
return V_26 ;
V_66:
F_82 (group, &container->group_list,
container_next) {
V_4 -> V_2 -> V_67 ( V_46 , V_14 -> V_22 ) ;
}
return V_26 ;
}
static long F_83 ( struct V_18 * V_19 ,
unsigned long V_58 )
{
struct V_3 * V_4 ;
long V_26 = - V_64 ;
F_84 ( & V_19 -> V_21 ) ;
if ( F_37 ( & V_19 -> V_34 ) || V_19 -> V_59 ) {
F_85 ( & V_19 -> V_21 ) ;
return - V_10 ;
}
F_3 ( & V_8 . V_9 ) ;
F_4 (driver, &vfio.iommu_drivers_list, vfio_next) {
void * V_46 ;
if ( ! F_78 ( V_4 -> V_2 -> V_60 ) )
continue;
if ( V_4 -> V_2 -> V_61 ( NULL , V_62 , V_58 ) <= 0 ) {
F_79 ( V_4 -> V_2 -> V_60 ) ;
continue;
}
F_5 ( & V_8 . V_9 ) ;
V_46 = V_4 -> V_2 -> V_68 ( V_58 ) ;
if ( F_34 ( V_46 ) ) {
V_26 = F_69 ( V_46 ) ;
F_79 ( V_4 -> V_2 -> V_60 ) ;
goto V_69;
}
V_26 = F_81 ( V_19 , V_4 , V_46 ) ;
if ( ! V_26 ) {
V_19 -> V_59 = V_4 ;
V_19 -> V_63 = V_46 ;
} else {
V_4 -> V_2 -> V_70 ( V_46 ) ;
F_79 ( V_4 -> V_2 -> V_60 ) ;
}
goto V_69;
}
F_5 ( & V_8 . V_9 ) ;
V_69:
F_85 ( & V_19 -> V_21 ) ;
return V_26 ;
}
static long F_86 ( struct V_71 * V_72 ,
unsigned int V_73 , unsigned long V_58 )
{
struct V_18 * V_19 = V_72 -> V_74 ;
struct V_3 * V_4 ;
void * V_46 ;
long V_26 = - V_10 ;
if ( ! V_19 )
return V_26 ;
switch ( V_73 ) {
case V_75 :
V_26 = V_76 ;
break;
case V_62 :
V_26 = F_76 ( V_19 , V_58 ) ;
break;
case V_77 :
V_26 = F_83 ( V_19 , V_58 ) ;
break;
default:
F_77 ( & V_19 -> V_21 ) ;
V_4 = V_19 -> V_59 ;
V_46 = V_19 -> V_63 ;
if ( V_4 )
V_26 = V_4 -> V_2 -> V_61 ( V_46 , V_73 , V_58 ) ;
F_80 ( & V_19 -> V_21 ) ;
}
return V_26 ;
}
static long F_87 ( struct V_71 * V_72 ,
unsigned int V_73 , unsigned long V_58 )
{
V_58 = ( unsigned long ) F_88 ( V_58 ) ;
return F_86 ( V_72 , V_73 , V_58 ) ;
}
static int F_89 ( struct V_78 * V_78 , struct V_71 * V_72 )
{
struct V_18 * V_19 ;
V_19 = F_2 ( sizeof( * V_19 ) , V_6 ) ;
if ( ! V_19 )
return - V_7 ;
F_25 ( & V_19 -> V_34 ) ;
F_90 ( & V_19 -> V_21 ) ;
F_24 ( & V_19 -> V_20 ) ;
V_72 -> V_74 = V_19 ;
return 0 ;
}
static int F_91 ( struct V_78 * V_78 , struct V_71 * V_72 )
{
struct V_18 * V_19 = V_72 -> V_74 ;
V_72 -> V_74 = NULL ;
F_18 ( V_19 ) ;
return 0 ;
}
static T_1 F_92 ( struct V_71 * V_72 , char T_2 * V_79 ,
T_3 V_80 , T_4 * V_81 )
{
struct V_18 * V_19 = V_72 -> V_74 ;
struct V_3 * V_4 ;
T_1 V_26 = - V_10 ;
F_77 ( & V_19 -> V_21 ) ;
V_4 = V_19 -> V_59 ;
if ( F_62 ( V_4 && V_4 -> V_2 -> V_82 ) )
V_26 = V_4 -> V_2 -> V_82 ( V_19 -> V_63 ,
V_79 , V_80 , V_81 ) ;
F_80 ( & V_19 -> V_21 ) ;
return V_26 ;
}
static T_1 F_93 ( struct V_71 * V_72 , const char T_2 * V_79 ,
T_3 V_80 , T_4 * V_81 )
{
struct V_18 * V_19 = V_72 -> V_74 ;
struct V_3 * V_4 ;
T_1 V_26 = - V_10 ;
F_77 ( & V_19 -> V_21 ) ;
V_4 = V_19 -> V_59 ;
if ( F_62 ( V_4 && V_4 -> V_2 -> V_83 ) )
V_26 = V_4 -> V_2 -> V_83 ( V_19 -> V_63 ,
V_79 , V_80 , V_81 ) ;
F_80 ( & V_19 -> V_21 ) ;
return V_26 ;
}
static int F_94 ( struct V_71 * V_72 , struct V_84 * V_85 )
{
struct V_18 * V_19 = V_72 -> V_74 ;
struct V_3 * V_4 ;
int V_26 = - V_10 ;
F_77 ( & V_19 -> V_21 ) ;
V_4 = V_19 -> V_59 ;
if ( F_62 ( V_4 && V_4 -> V_2 -> V_86 ) )
V_26 = V_4 -> V_2 -> V_86 ( V_19 -> V_63 , V_85 ) ;
F_80 ( & V_19 -> V_21 ) ;
return V_26 ;
}
static void F_95 ( struct V_13 * V_14 )
{
struct V_18 * V_19 = V_14 -> V_19 ;
struct V_3 * V_4 ;
F_84 ( & V_19 -> V_21 ) ;
V_4 = V_19 -> V_59 ;
if ( V_4 )
V_4 -> V_2 -> V_67 ( V_19 -> V_63 ,
V_14 -> V_22 ) ;
V_14 -> V_19 = NULL ;
F_9 ( & V_14 -> V_87 ) ;
if ( V_4 && F_37 ( & V_19 -> V_34 ) ) {
V_4 -> V_2 -> V_70 ( V_19 -> V_63 ) ;
F_79 ( V_4 -> V_2 -> V_60 ) ;
V_19 -> V_59 = NULL ;
V_19 -> V_63 = NULL ;
}
F_85 ( & V_19 -> V_21 ) ;
F_18 ( V_19 ) ;
}
static int F_96 ( struct V_13 * V_14 )
{
int V_88 = F_97 ( & V_14 -> V_29 , 1 , 0 ) ;
if ( ! V_88 )
return - V_10 ;
if ( V_88 != 1 )
return - V_57 ;
F_95 ( V_14 ) ;
return 0 ;
}
static void F_98 ( struct V_13 * V_14 )
{
if ( 0 == F_99 ( & V_14 -> V_29 ) )
F_95 ( V_14 ) ;
}
static int F_100 ( struct V_13 * V_14 , int V_89 )
{
struct V_90 V_91 ;
struct V_18 * V_19 ;
struct V_3 * V_4 ;
int V_26 = 0 ;
if ( F_58 ( & V_14 -> V_29 ) )
return - V_10 ;
V_91 = F_101 ( V_89 ) ;
if ( ! V_91 . V_71 )
return - V_92 ;
if ( V_91 . V_71 -> V_93 != & V_94 ) {
F_102 ( V_91 ) ;
return - V_10 ;
}
V_19 = V_91 . V_71 -> V_74 ;
F_36 ( ! V_19 ) ;
F_84 ( & V_19 -> V_21 ) ;
V_4 = V_19 -> V_59 ;
if ( V_4 ) {
V_26 = V_4 -> V_2 -> V_65 ( V_19 -> V_63 ,
V_14 -> V_22 ) ;
if ( V_26 )
goto V_95;
}
V_14 -> V_19 = V_19 ;
F_7 ( & V_14 -> V_87 , & V_19 -> V_34 ) ;
F_14 ( V_19 ) ;
F_103 ( & V_14 -> V_29 ) ;
V_95:
F_85 ( & V_19 -> V_21 ) ;
F_102 ( V_91 ) ;
return V_26 ;
}
static bool F_104 ( struct V_13 * V_14 )
{
return ( F_105 ( V_14 -> V_22 ,
V_14 , F_54 ) == 0 ) ;
}
static int F_106 ( struct V_13 * V_14 , char * V_79 )
{
struct V_36 * V_24 ;
struct V_71 * V_72 ;
int V_26 = - V_64 ;
if ( 0 == F_58 ( & V_14 -> V_29 ) ||
! V_14 -> V_19 -> V_59 || ! F_104 ( V_14 ) )
return - V_10 ;
F_3 ( & V_14 -> V_28 ) ;
F_4 (device, &group->device_list, group_next) {
if ( strcmp ( F_60 ( V_24 -> V_25 ) , V_79 ) )
continue;
V_26 = V_24 -> V_2 -> V_68 ( V_24 -> V_38 ) ;
if ( V_26 )
break;
V_26 = F_107 () ;
if ( V_26 < 0 ) {
V_24 -> V_2 -> V_70 ( V_24 -> V_38 ) ;
break;
}
V_72 = F_108 ( L_9 , & V_96 ,
V_24 , V_97 ) ;
if ( F_34 ( V_72 ) ) {
F_109 ( V_26 ) ;
V_26 = F_69 ( V_72 ) ;
V_24 -> V_2 -> V_70 ( V_24 -> V_38 ) ;
break;
}
V_72 -> V_98 |= ( V_99 | V_100 | V_101 ) ;
F_50 ( V_24 ) ;
F_103 ( & V_14 -> V_29 ) ;
F_110 ( V_26 , V_72 ) ;
break;
}
F_5 ( & V_14 -> V_28 ) ;
return V_26 ;
}
static long F_111 ( struct V_71 * V_72 ,
unsigned int V_73 , unsigned long V_58 )
{
struct V_13 * V_14 = V_72 -> V_74 ;
long V_26 = - V_102 ;
switch ( V_73 ) {
case V_103 :
{
struct V_104 V_105 ;
unsigned long V_106 ;
V_106 = F_112 ( struct V_104 , V_107 ) ;
if ( F_113 ( & V_105 , ( void T_2 * ) V_58 , V_106 ) )
return - V_108 ;
if ( V_105 . V_109 < V_106 )
return - V_10 ;
V_105 . V_107 = 0 ;
if ( F_104 ( V_14 ) )
V_105 . V_107 |= V_110 ;
if ( V_14 -> V_19 )
V_105 . V_107 |= V_111 ;
if ( F_114 ( ( void T_2 * ) V_58 , & V_105 , V_106 ) )
return - V_108 ;
V_26 = 0 ;
break;
}
case V_112 :
{
int V_90 ;
if ( F_115 ( V_90 , ( int T_2 * ) V_58 ) )
return - V_108 ;
if ( V_90 < 0 )
return - V_10 ;
V_26 = F_100 ( V_14 , V_90 ) ;
break;
}
case V_113 :
V_26 = F_96 ( V_14 ) ;
break;
case V_114 :
{
char * V_79 ;
V_79 = F_116 ( ( const char T_2 * ) V_58 , V_115 ) ;
if ( F_34 ( V_79 ) )
return F_69 ( V_79 ) ;
V_26 = F_106 ( V_14 , V_79 ) ;
F_6 ( V_79 ) ;
break;
}
}
return V_26 ;
}
static long F_117 ( struct V_71 * V_72 ,
unsigned int V_73 , unsigned long V_58 )
{
V_58 = ( unsigned long ) F_88 ( V_58 ) ;
return F_111 ( V_72 , V_73 , V_58 ) ;
}
static int F_118 ( struct V_78 * V_78 , struct V_71 * V_72 )
{
struct V_13 * V_14 ;
V_14 = F_43 ( F_119 ( V_78 ) ) ;
if ( ! V_14 )
return - V_64 ;
if ( V_14 -> V_19 ) {
F_39 ( V_14 ) ;
return - V_57 ;
}
V_72 -> V_74 = V_14 ;
return 0 ;
}
static int F_120 ( struct V_78 * V_78 , struct V_71 * V_72 )
{
struct V_13 * V_14 = V_72 -> V_74 ;
V_72 -> V_74 = NULL ;
F_98 ( V_14 ) ;
F_39 ( V_14 ) ;
return 0 ;
}
static int F_121 ( struct V_78 * V_78 , struct V_71 * V_72 )
{
struct V_36 * V_24 = V_72 -> V_74 ;
V_24 -> V_2 -> V_70 ( V_24 -> V_38 ) ;
F_98 ( V_24 -> V_14 ) ;
F_49 ( V_24 ) ;
return 0 ;
}
static long F_122 ( struct V_71 * V_72 ,
unsigned int V_73 , unsigned long V_58 )
{
struct V_36 * V_24 = V_72 -> V_74 ;
if ( F_123 ( ! V_24 -> V_2 -> V_61 ) )
return - V_10 ;
return V_24 -> V_2 -> V_61 ( V_24 -> V_38 , V_73 , V_58 ) ;
}
static T_1 F_124 ( struct V_71 * V_72 , char T_2 * V_79 ,
T_3 V_80 , T_4 * V_81 )
{
struct V_36 * V_24 = V_72 -> V_74 ;
if ( F_123 ( ! V_24 -> V_2 -> V_82 ) )
return - V_10 ;
return V_24 -> V_2 -> V_82 ( V_24 -> V_38 , V_79 , V_80 , V_81 ) ;
}
static T_1 F_125 ( struct V_71 * V_72 ,
const char T_2 * V_79 ,
T_3 V_80 , T_4 * V_81 )
{
struct V_36 * V_24 = V_72 -> V_74 ;
if ( F_123 ( ! V_24 -> V_2 -> V_83 ) )
return - V_10 ;
return V_24 -> V_2 -> V_83 ( V_24 -> V_38 , V_79 , V_80 , V_81 ) ;
}
static int F_126 ( struct V_71 * V_72 , struct V_84 * V_85 )
{
struct V_36 * V_24 = V_72 -> V_74 ;
if ( F_123 ( ! V_24 -> V_2 -> V_86 ) )
return - V_10 ;
return V_24 -> V_2 -> V_86 ( V_24 -> V_38 , V_85 ) ;
}
static long F_127 ( struct V_71 * V_72 ,
unsigned int V_73 , unsigned long V_58 )
{
V_58 = ( unsigned long ) F_88 ( V_58 ) ;
return F_122 ( V_72 , V_73 , V_58 ) ;
}
static char * F_128 ( struct V_24 * V_25 , T_5 * V_116 )
{
if ( V_116 && ( F_129 ( V_25 -> V_33 ) == 0 ) )
* V_116 = V_117 | V_118 ;
return F_130 ( V_6 , L_10 , F_60 ( V_25 ) ) ;
}
static int T_6 F_131 ( void )
{
int V_26 ;
F_132 ( & V_8 . V_15 ) ;
F_26 ( & V_8 . V_21 ) ;
F_26 ( & V_8 . V_9 ) ;
F_25 ( & V_8 . V_34 ) ;
F_25 ( & V_8 . V_12 ) ;
F_133 ( & V_8 . V_40 ) ;
V_8 . V_32 = F_134 ( V_119 , L_11 ) ;
if ( F_34 ( V_8 . V_32 ) ) {
V_26 = F_69 ( V_8 . V_32 ) ;
goto V_120;
}
V_8 . V_32 -> V_121 = F_128 ;
V_26 = F_135 ( & V_8 . V_33 , 0 , V_16 , L_11 ) ;
if ( V_26 )
goto V_122;
F_136 ( & V_8 . V_123 , & V_94 ) ;
V_26 = F_137 ( & V_8 . V_123 , V_8 . V_33 , 1 ) ;
if ( V_26 )
goto V_124;
V_8 . V_25 = F_30 ( V_8 . V_32 , NULL , V_8 . V_33 , NULL , L_11 ) ;
if ( F_34 ( V_8 . V_25 ) ) {
V_26 = F_69 ( V_8 . V_25 ) ;
goto V_125;
}
F_136 ( & V_8 . V_126 , & V_127 ) ;
V_26 = F_137 ( & V_8 . V_126 ,
F_31 ( F_32 ( V_8 . V_33 ) , 1 ) , V_16 - 1 ) ;
if ( V_26 )
goto V_128;
F_138 ( V_129 L_12 V_130 L_13 ) ;
F_139 ( L_14 ) ;
return 0 ;
V_128:
F_38 ( V_8 . V_32 , V_8 . V_33 ) ;
V_125:
F_140 ( & V_8 . V_123 ) ;
V_124:
F_141 ( V_8 . V_33 , V_16 ) ;
V_122:
F_142 ( V_8 . V_32 ) ;
V_8 . V_32 = NULL ;
V_120:
return V_26 ;
}
static void T_7 F_143 ( void )
{
F_36 ( ! F_37 ( & V_8 . V_34 ) ) ;
F_144 ( & V_8 . V_15 ) ;
F_140 ( & V_8 . V_126 ) ;
F_38 ( V_8 . V_32 , V_8 . V_33 ) ;
F_140 ( & V_8 . V_123 ) ;
F_141 ( V_8 . V_33 , V_16 ) ;
F_142 ( V_8 . V_32 ) ;
V_8 . V_32 = NULL ;
}
