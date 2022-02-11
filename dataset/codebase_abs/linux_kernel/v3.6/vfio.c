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
int V_15 , V_16 ;
V_17:
if ( F_11 ( F_12 ( & V_8 . V_18 , V_6 ) == 0 ) )
return - V_7 ;
V_15 = F_13 ( & V_8 . V_18 , V_14 , 1 , & V_16 ) ;
if ( V_15 == - V_19 )
goto V_17;
if ( V_15 || V_16 > V_20 ) {
if ( V_16 > V_20 )
F_14 ( & V_8 . V_18 , V_16 ) ;
return - V_21 ;
}
return V_16 ;
}
static void F_15 ( int V_16 )
{
F_14 ( & V_8 . V_18 , V_16 ) ;
}
static void F_16 ( struct V_22 * V_23 )
{
F_17 ( & V_23 -> V_24 ) ;
}
static void F_18 ( struct V_24 * V_24 )
{
struct V_22 * V_23 ;
V_23 = F_19 ( V_24 , struct V_22 , V_24 ) ;
F_6 ( V_23 ) ;
}
static void F_20 ( struct V_22 * V_23 )
{
F_21 ( & V_23 -> V_24 , F_18 ) ;
}
static struct V_13 * F_22 ( struct V_25 * V_25 )
{
struct V_13 * V_14 , * V_5 ;
struct V_26 * V_27 ;
int V_15 , V_16 ;
V_14 = F_2 ( sizeof( * V_14 ) , V_6 ) ;
if ( ! V_14 )
return F_23 ( - V_7 ) ;
F_24 ( & V_14 -> V_24 ) ;
F_25 ( & V_14 -> V_28 ) ;
F_26 ( & V_14 -> V_29 ) ;
F_27 ( & V_14 -> V_30 , 0 ) ;
V_14 -> V_25 = V_25 ;
V_14 -> V_31 . V_32 = V_33 ;
V_15 = F_28 ( V_25 , & V_14 -> V_31 ) ;
if ( V_15 ) {
F_6 ( V_14 ) ;
return F_23 ( V_15 ) ;
}
F_3 ( & V_8 . V_34 ) ;
V_16 = F_10 ( V_14 ) ;
if ( V_16 < 0 ) {
F_5 ( & V_8 . V_34 ) ;
F_6 ( V_14 ) ;
return F_23 ( V_16 ) ;
}
F_4 (tmp, &vfio.group_list, vfio_next) {
if ( V_5 -> V_25 == V_25 ) {
F_29 ( V_5 ) ;
F_15 ( V_16 ) ;
F_5 ( & V_8 . V_34 ) ;
F_6 ( V_14 ) ;
return V_5 ;
}
}
V_27 = F_30 ( V_8 . V_35 , NULL , F_31 ( F_32 ( V_8 . V_36 ) , V_16 ) ,
V_14 , L_1 , F_33 ( V_25 ) ) ;
if ( F_34 ( V_27 ) ) {
F_15 ( V_16 ) ;
F_5 ( & V_8 . V_34 ) ;
F_6 ( V_14 ) ;
return (struct V_13 * ) V_27 ;
}
V_14 -> V_16 = V_16 ;
V_14 -> V_27 = V_27 ;
F_7 ( & V_14 -> V_11 , & V_8 . V_37 ) ;
F_5 ( & V_8 . V_34 ) ;
return V_14 ;
}
static void F_35 ( struct V_24 * V_24 )
{
struct V_13 * V_14 = F_19 ( V_24 , struct V_13 , V_24 ) ;
F_36 ( ! F_37 ( & V_14 -> V_28 ) ) ;
F_38 ( V_8 . V_35 , F_31 ( F_32 ( V_8 . V_36 ) , V_14 -> V_16 ) ) ;
F_9 ( & V_14 -> V_11 ) ;
F_15 ( V_14 -> V_16 ) ;
F_5 ( & V_8 . V_34 ) ;
F_39 ( V_14 -> V_25 , & V_14 -> V_31 ) ;
F_6 ( V_14 ) ;
}
static void F_40 ( struct V_13 * V_14 )
{
F_41 ( & V_14 -> V_24 , F_35 , & V_8 . V_34 ) ;
}
static void F_29 ( struct V_13 * V_14 )
{
F_17 ( & V_14 -> V_24 ) ;
}
static struct V_13 * F_42 ( struct V_13 * V_14 )
{
struct V_13 * V_38 = V_14 ;
F_3 ( & V_8 . V_34 ) ;
F_4 (group, &vfio.group_list, vfio_next) {
if ( V_14 == V_38 ) {
F_29 ( V_14 ) ;
F_5 ( & V_8 . V_34 ) ;
return V_14 ;
}
}
F_5 ( & V_8 . V_34 ) ;
return NULL ;
}
static
struct V_13 * F_43 ( struct V_25 * V_25 )
{
struct V_13 * V_14 ;
F_3 ( & V_8 . V_34 ) ;
F_4 (group, &vfio.group_list, vfio_next) {
if ( V_14 -> V_25 == V_25 ) {
F_29 ( V_14 ) ;
F_5 ( & V_8 . V_34 ) ;
return V_14 ;
}
}
F_5 ( & V_8 . V_34 ) ;
return NULL ;
}
static struct V_13 * F_44 ( int V_16 )
{
struct V_13 * V_14 ;
F_3 ( & V_8 . V_34 ) ;
V_14 = F_45 ( & V_8 . V_18 , V_16 ) ;
if ( ! V_14 ) {
F_5 ( & V_8 . V_34 ) ;
return NULL ;
}
F_29 ( V_14 ) ;
F_5 ( & V_8 . V_34 ) ;
return V_14 ;
}
static
struct V_39 * F_46 ( struct V_13 * V_14 ,
struct V_26 * V_27 ,
const struct V_40 * V_2 ,
void * V_41 )
{
struct V_39 * V_26 ;
int V_15 ;
V_26 = F_2 ( sizeof( * V_26 ) , V_6 ) ;
if ( ! V_26 )
return F_23 ( - V_7 ) ;
F_24 ( & V_26 -> V_24 ) ;
V_26 -> V_27 = V_27 ;
V_26 -> V_14 = V_14 ;
V_26 -> V_2 = V_2 ;
V_26 -> V_41 = V_41 ;
V_15 = F_47 ( V_27 , V_26 ) ;
if ( V_15 ) {
F_6 ( V_26 ) ;
return F_23 ( V_15 ) ;
}
F_29 ( V_14 ) ;
F_3 ( & V_14 -> V_29 ) ;
F_7 ( & V_26 -> V_42 , & V_14 -> V_28 ) ;
F_5 ( & V_14 -> V_29 ) ;
return V_26 ;
}
static void F_48 ( struct V_24 * V_24 )
{
struct V_39 * V_26 = F_19 ( V_24 ,
struct V_39 , V_24 ) ;
struct V_13 * V_14 = V_26 -> V_14 ;
F_9 ( & V_26 -> V_42 ) ;
F_5 ( & V_14 -> V_29 ) ;
F_47 ( V_26 -> V_27 , NULL ) ;
F_6 ( V_26 ) ;
F_49 ( & V_8 . V_43 ) ;
}
static void F_50 ( struct V_39 * V_26 )
{
struct V_13 * V_14 = V_26 -> V_14 ;
F_41 ( & V_26 -> V_24 , F_48 , & V_14 -> V_29 ) ;
F_40 ( V_14 ) ;
}
static void F_51 ( struct V_39 * V_26 )
{
F_29 ( V_26 -> V_14 ) ;
F_17 ( & V_26 -> V_24 ) ;
}
static struct V_39 * F_52 ( struct V_13 * V_14 ,
struct V_26 * V_27 )
{
struct V_39 * V_26 ;
F_3 ( & V_14 -> V_29 ) ;
F_4 (device, &group->device_list, group_next) {
if ( V_26 -> V_27 == V_27 ) {
F_51 ( V_26 ) ;
F_5 ( & V_14 -> V_29 ) ;
return V_26 ;
}
}
F_5 ( & V_14 -> V_29 ) ;
return NULL ;
}
static bool F_53 ( struct V_44 * V_45 )
{
int V_46 ;
for ( V_46 = 0 ; V_46 < F_54 ( V_47 ) ; V_46 ++ ) {
if ( ! strcmp ( V_45 -> V_48 , V_47 [ V_46 ] ) )
return true ;
}
return false ;
}
static int F_55 ( struct V_26 * V_27 , void * V_49 )
{
struct V_13 * V_14 = V_49 ;
struct V_39 * V_26 ;
if ( ! V_27 -> V_4 || F_53 ( V_27 -> V_4 ) )
return 0 ;
V_26 = F_52 ( V_14 , V_27 ) ;
if ( V_26 ) {
F_50 ( V_26 ) ;
return 0 ;
}
return - V_10 ;
}
static int F_56 ( struct V_13 * V_14 , struct V_26 * V_27 )
{
struct V_39 * V_26 ;
V_26 = F_52 ( V_14 , V_27 ) ;
if ( F_57 ( V_26 ) ) {
F_50 ( V_26 ) ;
return 0 ;
}
if ( ! F_58 ( & V_14 -> V_30 ) )
return 0 ;
F_59 ( L_2 , F_60 ( V_27 ) ,
F_33 ( V_14 -> V_25 ) ) ;
return 0 ;
}
static int F_61 ( struct V_13 * V_14 , struct V_26 * V_27 )
{
struct V_39 * V_26 ;
V_26 = F_52 ( V_14 , V_27 ) ;
if ( F_62 ( ! V_26 ) )
return 0 ;
F_59 ( L_3 , F_60 ( V_27 ) ,
F_33 ( V_14 -> V_25 ) ) ;
F_50 ( V_26 ) ;
return 0 ;
}
static int F_63 ( struct V_13 * V_14 , struct V_26 * V_27 )
{
if ( ! F_58 ( & V_14 -> V_30 ) )
return 0 ;
return F_55 ( V_27 , V_14 ) ;
}
static int V_33 ( struct V_50 * V_31 ,
unsigned long V_51 , void * V_49 )
{
struct V_13 * V_14 = F_19 ( V_31 , struct V_13 , V_31 ) ;
struct V_26 * V_27 = V_49 ;
V_14 = F_42 ( V_14 ) ;
if ( F_36 ( ! V_14 ) )
return V_52 ;
switch ( V_51 ) {
case V_53 :
F_56 ( V_14 , V_27 ) ;
break;
case V_54 :
F_61 ( V_14 , V_27 ) ;
break;
case V_55 :
F_64 ( L_4 ,
V_56 , F_60 ( V_27 ) ,
F_33 ( V_14 -> V_25 ) ) ;
break;
case V_57 :
F_64 ( L_5 ,
V_56 , F_60 ( V_27 ) ,
F_33 ( V_14 -> V_25 ) , V_27 -> V_4 -> V_48 ) ;
F_65 ( F_63 ( V_14 , V_27 ) ) ;
break;
case V_58 :
F_64 ( L_6 ,
V_56 , F_60 ( V_27 ) ,
F_33 ( V_14 -> V_25 ) , V_27 -> V_4 -> V_48 ) ;
break;
case V_59 :
F_64 ( L_7 ,
V_56 , F_60 ( V_27 ) ,
F_33 ( V_14 -> V_25 ) ) ;
break;
}
F_40 ( V_14 ) ;
return V_52 ;
}
int F_66 ( struct V_26 * V_27 ,
const struct V_40 * V_2 , void * V_41 )
{
struct V_25 * V_25 ;
struct V_13 * V_14 ;
struct V_39 * V_26 ;
V_25 = F_67 ( V_27 ) ;
if ( ! V_25 )
return - V_10 ;
V_14 = F_43 ( V_25 ) ;
if ( ! V_14 ) {
V_14 = F_22 ( V_25 ) ;
if ( F_34 ( V_14 ) ) {
F_68 ( V_25 ) ;
return F_69 ( V_14 ) ;
}
}
V_26 = F_52 ( V_14 , V_27 ) ;
if ( V_26 ) {
F_59 ( 1 , L_8 ,
F_60 ( V_27 ) , F_33 ( V_25 ) ) ;
F_50 ( V_26 ) ;
F_40 ( V_14 ) ;
F_68 ( V_25 ) ;
return - V_60 ;
}
V_26 = F_46 ( V_14 , V_27 , V_2 , V_41 ) ;
if ( F_34 ( V_26 ) ) {
F_40 ( V_14 ) ;
F_68 ( V_25 ) ;
return F_69 ( V_26 ) ;
}
F_40 ( V_14 ) ;
return 0 ;
}
static bool F_70 ( struct V_26 * V_27 )
{
struct V_25 * V_25 ;
struct V_13 * V_14 ;
struct V_39 * V_26 ;
V_25 = F_67 ( V_27 ) ;
if ( ! V_25 )
return false ;
V_14 = F_43 ( V_25 ) ;
if ( ! V_14 ) {
F_68 ( V_25 ) ;
return false ;
}
V_26 = F_52 ( V_14 , V_27 ) ;
if ( ! V_26 ) {
F_40 ( V_14 ) ;
F_68 ( V_25 ) ;
return false ;
}
F_50 ( V_26 ) ;
F_40 ( V_14 ) ;
F_68 ( V_25 ) ;
return true ;
}
void * F_71 ( struct V_26 * V_27 )
{
struct V_39 * V_26 = F_72 ( V_27 ) ;
struct V_13 * V_14 = V_26 -> V_14 ;
struct V_25 * V_25 = V_14 -> V_25 ;
void * V_41 = V_26 -> V_41 ;
F_50 ( V_26 ) ;
F_73 ( V_8 . V_43 , ! F_70 ( V_27 ) ) ;
F_68 ( V_25 ) ;
return V_41 ;
}
static long F_74 ( struct V_22 * V_23 ,
unsigned long V_61 )
{
struct V_3 * V_4 = V_23 -> V_62 ;
long V_15 = 0 ;
switch ( V_61 ) {
default:
if ( ! V_4 ) {
F_3 ( & V_8 . V_9 ) ;
F_4 (driver, &vfio.iommu_drivers_list,
vfio_next) {
if ( ! F_75 ( V_4 -> V_2 -> V_63 ) )
continue;
V_15 = V_4 -> V_2 -> V_64 ( NULL ,
V_65 ,
V_61 ) ;
F_76 ( V_4 -> V_2 -> V_63 ) ;
if ( V_15 > 0 )
break;
}
F_5 ( & V_8 . V_9 ) ;
} else
V_15 = V_4 -> V_2 -> V_64 ( V_23 -> V_66 ,
V_65 , V_61 ) ;
}
return V_15 ;
}
static int F_77 ( struct V_22 * V_23 ,
struct V_3 * V_4 ,
void * V_49 )
{
struct V_13 * V_14 ;
int V_15 = - V_67 ;
F_4 (group, &container->group_list, container_next) {
V_15 = V_4 -> V_2 -> V_68 ( V_49 , V_14 -> V_25 ) ;
if ( V_15 )
goto V_69;
}
return V_15 ;
V_69:
F_78 (group, &container->group_list,
container_next) {
V_4 -> V_2 -> V_70 ( V_49 , V_14 -> V_25 ) ;
}
return V_15 ;
}
static long F_79 ( struct V_22 * V_23 ,
unsigned long V_61 )
{
struct V_3 * V_4 ;
long V_15 = - V_67 ;
F_3 ( & V_23 -> V_34 ) ;
if ( F_37 ( & V_23 -> V_37 ) || V_23 -> V_62 ) {
F_5 ( & V_23 -> V_34 ) ;
return - V_10 ;
}
F_3 ( & V_8 . V_9 ) ;
F_4 (driver, &vfio.iommu_drivers_list, vfio_next) {
void * V_49 ;
if ( ! F_75 ( V_4 -> V_2 -> V_63 ) )
continue;
if ( V_4 -> V_2 -> V_64 ( NULL , V_65 , V_61 ) <= 0 ) {
F_76 ( V_4 -> V_2 -> V_63 ) ;
continue;
}
F_5 ( & V_8 . V_9 ) ;
V_49 = V_4 -> V_2 -> V_71 ( V_61 ) ;
if ( F_34 ( V_49 ) ) {
V_15 = F_69 ( V_49 ) ;
F_76 ( V_4 -> V_2 -> V_63 ) ;
goto V_72;
}
V_15 = F_77 ( V_23 , V_4 , V_49 ) ;
if ( ! V_15 ) {
V_23 -> V_62 = V_4 ;
V_23 -> V_66 = V_49 ;
} else {
V_4 -> V_2 -> V_73 ( V_49 ) ;
F_76 ( V_4 -> V_2 -> V_63 ) ;
}
goto V_72;
}
F_5 ( & V_8 . V_9 ) ;
V_72:
F_5 ( & V_23 -> V_34 ) ;
return V_15 ;
}
static long F_80 ( struct V_74 * V_75 ,
unsigned int V_76 , unsigned long V_61 )
{
struct V_22 * V_23 = V_75 -> V_77 ;
struct V_3 * V_4 ;
void * V_49 ;
long V_15 = - V_10 ;
if ( ! V_23 )
return V_15 ;
V_4 = V_23 -> V_62 ;
V_49 = V_23 -> V_66 ;
switch ( V_76 ) {
case V_78 :
V_15 = V_79 ;
break;
case V_65 :
V_15 = F_74 ( V_23 , V_61 ) ;
break;
case V_80 :
V_15 = F_79 ( V_23 , V_61 ) ;
break;
default:
if ( V_4 )
V_15 = V_4 -> V_2 -> V_64 ( V_49 , V_76 , V_61 ) ;
}
return V_15 ;
}
static long F_81 ( struct V_74 * V_75 ,
unsigned int V_76 , unsigned long V_61 )
{
V_61 = ( unsigned long ) F_82 ( V_61 ) ;
return F_80 ( V_75 , V_76 , V_61 ) ;
}
static int F_83 ( struct V_81 * V_81 , struct V_74 * V_75 )
{
struct V_22 * V_23 ;
V_23 = F_2 ( sizeof( * V_23 ) , V_6 ) ;
if ( ! V_23 )
return - V_7 ;
F_25 ( & V_23 -> V_37 ) ;
F_26 ( & V_23 -> V_34 ) ;
F_24 ( & V_23 -> V_24 ) ;
V_75 -> V_77 = V_23 ;
return 0 ;
}
static int F_84 ( struct V_81 * V_81 , struct V_74 * V_75 )
{
struct V_22 * V_23 = V_75 -> V_77 ;
V_75 -> V_77 = NULL ;
F_20 ( V_23 ) ;
return 0 ;
}
static T_1 F_85 ( struct V_74 * V_75 , char T_2 * V_82 ,
T_3 V_83 , T_4 * V_84 )
{
struct V_22 * V_23 = V_75 -> V_77 ;
struct V_3 * V_4 = V_23 -> V_62 ;
if ( F_11 ( ! V_4 || ! V_4 -> V_2 -> V_85 ) )
return - V_10 ;
return V_4 -> V_2 -> V_85 ( V_23 -> V_66 , V_82 , V_83 , V_84 ) ;
}
static T_1 F_86 ( struct V_74 * V_75 , const char T_2 * V_82 ,
T_3 V_83 , T_4 * V_84 )
{
struct V_22 * V_23 = V_75 -> V_77 ;
struct V_3 * V_4 = V_23 -> V_62 ;
if ( F_11 ( ! V_4 || ! V_4 -> V_2 -> V_86 ) )
return - V_10 ;
return V_4 -> V_2 -> V_86 ( V_23 -> V_66 , V_82 , V_83 , V_84 ) ;
}
static int F_87 ( struct V_74 * V_75 , struct V_87 * V_88 )
{
struct V_22 * V_23 = V_75 -> V_77 ;
struct V_3 * V_4 = V_23 -> V_62 ;
if ( F_11 ( ! V_4 || ! V_4 -> V_2 -> V_89 ) )
return - V_10 ;
return V_4 -> V_2 -> V_89 ( V_23 -> V_66 , V_88 ) ;
}
static void F_88 ( struct V_13 * V_14 )
{
struct V_22 * V_23 = V_14 -> V_23 ;
struct V_3 * V_4 ;
F_3 ( & V_23 -> V_34 ) ;
V_4 = V_23 -> V_62 ;
if ( V_4 )
V_4 -> V_2 -> V_70 ( V_23 -> V_66 ,
V_14 -> V_25 ) ;
V_14 -> V_23 = NULL ;
F_9 ( & V_14 -> V_90 ) ;
if ( V_4 && F_37 ( & V_23 -> V_37 ) ) {
V_4 -> V_2 -> V_73 ( V_23 -> V_66 ) ;
F_76 ( V_4 -> V_2 -> V_63 ) ;
V_23 -> V_62 = NULL ;
V_23 -> V_66 = NULL ;
}
F_5 ( & V_23 -> V_34 ) ;
F_20 ( V_23 ) ;
}
static int F_89 ( struct V_13 * V_14 )
{
int V_91 = F_90 ( & V_14 -> V_30 , 1 , 0 ) ;
if ( ! V_91 )
return - V_10 ;
if ( V_91 != 1 )
return - V_60 ;
F_88 ( V_14 ) ;
return 0 ;
}
static void F_91 ( struct V_13 * V_14 )
{
if ( 0 == F_92 ( & V_14 -> V_30 ) )
F_88 ( V_14 ) ;
}
static int F_93 ( struct V_13 * V_14 , int V_92 )
{
struct V_74 * V_75 ;
struct V_22 * V_23 ;
struct V_3 * V_4 ;
int V_15 = 0 ;
if ( F_58 ( & V_14 -> V_30 ) )
return - V_10 ;
V_75 = F_94 ( V_92 ) ;
if ( ! V_75 )
return - V_93 ;
if ( V_75 -> V_94 != & V_95 ) {
F_95 ( V_75 ) ;
return - V_10 ;
}
V_23 = V_75 -> V_77 ;
F_36 ( ! V_23 ) ;
F_3 ( & V_23 -> V_34 ) ;
V_4 = V_23 -> V_62 ;
if ( V_4 ) {
V_15 = V_4 -> V_2 -> V_68 ( V_23 -> V_66 ,
V_14 -> V_25 ) ;
if ( V_15 )
goto V_96;
}
V_14 -> V_23 = V_23 ;
F_7 ( & V_14 -> V_90 , & V_23 -> V_37 ) ;
F_16 ( V_23 ) ;
F_96 ( & V_14 -> V_30 ) ;
V_96:
F_5 ( & V_23 -> V_34 ) ;
F_95 ( V_75 ) ;
return V_15 ;
}
static bool F_97 ( struct V_13 * V_14 )
{
return ( F_98 ( V_14 -> V_25 ,
V_14 , F_55 ) == 0 ) ;
}
static int F_99 ( struct V_13 * V_14 , char * V_82 )
{
struct V_39 * V_26 ;
struct V_74 * V_75 ;
int V_15 = - V_67 ;
if ( 0 == F_58 ( & V_14 -> V_30 ) ||
! V_14 -> V_23 -> V_62 || ! F_97 ( V_14 ) )
return - V_10 ;
F_3 ( & V_14 -> V_29 ) ;
F_4 (device, &group->device_list, group_next) {
if ( strcmp ( F_60 ( V_26 -> V_27 ) , V_82 ) )
continue;
V_15 = V_26 -> V_2 -> V_71 ( V_26 -> V_41 ) ;
if ( V_15 )
break;
V_15 = F_100 () ;
if ( V_15 < 0 ) {
V_26 -> V_2 -> V_73 ( V_26 -> V_41 ) ;
break;
}
V_75 = F_101 ( L_9 , & V_97 ,
V_26 , V_98 ) ;
if ( F_34 ( V_75 ) ) {
F_102 ( V_15 ) ;
V_15 = F_69 ( V_75 ) ;
V_26 -> V_2 -> V_73 ( V_26 -> V_41 ) ;
break;
}
V_75 -> V_99 |= ( V_100 | V_101 | V_102 ) ;
F_51 ( V_26 ) ;
F_96 ( & V_14 -> V_30 ) ;
F_103 ( V_15 , V_75 ) ;
break;
}
F_5 ( & V_14 -> V_29 ) ;
return V_15 ;
}
static long F_104 ( struct V_74 * V_75 ,
unsigned int V_76 , unsigned long V_61 )
{
struct V_13 * V_14 = V_75 -> V_77 ;
long V_15 = - V_103 ;
switch ( V_76 ) {
case V_104 :
{
struct V_105 V_106 ;
unsigned long V_107 ;
V_107 = F_105 ( struct V_105 , V_108 ) ;
if ( F_106 ( & V_106 , ( void T_2 * ) V_61 , V_107 ) )
return - V_109 ;
if ( V_106 . V_110 < V_107 )
return - V_10 ;
V_106 . V_108 = 0 ;
if ( F_97 ( V_14 ) )
V_106 . V_108 |= V_111 ;
if ( V_14 -> V_23 )
V_106 . V_108 |= V_112 ;
if ( F_107 ( ( void T_2 * ) V_61 , & V_106 , V_107 ) )
return - V_109 ;
V_15 = 0 ;
break;
}
case V_113 :
{
int V_114 ;
if ( F_108 ( V_114 , ( int T_2 * ) V_61 ) )
return - V_109 ;
if ( V_114 < 0 )
return - V_10 ;
V_15 = F_93 ( V_14 , V_114 ) ;
break;
}
case V_115 :
V_15 = F_89 ( V_14 ) ;
break;
case V_116 :
{
char * V_82 ;
V_82 = F_109 ( ( const char T_2 * ) V_61 , V_117 ) ;
if ( F_34 ( V_82 ) )
return F_69 ( V_82 ) ;
V_15 = F_99 ( V_14 , V_82 ) ;
F_6 ( V_82 ) ;
break;
}
}
return V_15 ;
}
static long F_110 ( struct V_74 * V_75 ,
unsigned int V_76 , unsigned long V_61 )
{
V_61 = ( unsigned long ) F_82 ( V_61 ) ;
return F_104 ( V_75 , V_76 , V_61 ) ;
}
static int F_111 ( struct V_81 * V_81 , struct V_74 * V_75 )
{
struct V_13 * V_14 ;
V_14 = F_44 ( F_112 ( V_81 ) ) ;
if ( ! V_14 )
return - V_67 ;
if ( V_14 -> V_23 ) {
F_40 ( V_14 ) ;
return - V_60 ;
}
V_75 -> V_77 = V_14 ;
return 0 ;
}
static int F_113 ( struct V_81 * V_81 , struct V_74 * V_75 )
{
struct V_13 * V_14 = V_75 -> V_77 ;
V_75 -> V_77 = NULL ;
F_91 ( V_14 ) ;
F_40 ( V_14 ) ;
return 0 ;
}
static int F_114 ( struct V_81 * V_81 , struct V_74 * V_75 )
{
struct V_39 * V_26 = V_75 -> V_77 ;
V_26 -> V_2 -> V_73 ( V_26 -> V_41 ) ;
F_91 ( V_26 -> V_14 ) ;
F_50 ( V_26 ) ;
return 0 ;
}
static long F_115 ( struct V_74 * V_75 ,
unsigned int V_76 , unsigned long V_61 )
{
struct V_39 * V_26 = V_75 -> V_77 ;
if ( F_11 ( ! V_26 -> V_2 -> V_64 ) )
return - V_10 ;
return V_26 -> V_2 -> V_64 ( V_26 -> V_41 , V_76 , V_61 ) ;
}
static T_1 F_116 ( struct V_74 * V_75 , char T_2 * V_82 ,
T_3 V_83 , T_4 * V_84 )
{
struct V_39 * V_26 = V_75 -> V_77 ;
if ( F_11 ( ! V_26 -> V_2 -> V_85 ) )
return - V_10 ;
return V_26 -> V_2 -> V_85 ( V_26 -> V_41 , V_82 , V_83 , V_84 ) ;
}
static T_1 F_117 ( struct V_74 * V_75 ,
const char T_2 * V_82 ,
T_3 V_83 , T_4 * V_84 )
{
struct V_39 * V_26 = V_75 -> V_77 ;
if ( F_11 ( ! V_26 -> V_2 -> V_86 ) )
return - V_10 ;
return V_26 -> V_2 -> V_86 ( V_26 -> V_41 , V_82 , V_83 , V_84 ) ;
}
static int F_118 ( struct V_74 * V_75 , struct V_87 * V_88 )
{
struct V_39 * V_26 = V_75 -> V_77 ;
if ( F_11 ( ! V_26 -> V_2 -> V_89 ) )
return - V_10 ;
return V_26 -> V_2 -> V_89 ( V_26 -> V_41 , V_88 ) ;
}
static long F_119 ( struct V_74 * V_75 ,
unsigned int V_76 , unsigned long V_61 )
{
V_61 = ( unsigned long ) F_82 ( V_61 ) ;
return F_115 ( V_75 , V_76 , V_61 ) ;
}
static char * F_120 ( struct V_26 * V_27 , T_5 * V_118 )
{
return F_121 ( V_6 , L_10 , F_60 ( V_27 ) ) ;
}
static int T_6 F_122 ( void )
{
int V_15 ;
F_123 ( & V_8 . V_18 ) ;
F_26 ( & V_8 . V_34 ) ;
F_26 ( & V_8 . V_9 ) ;
F_25 ( & V_8 . V_37 ) ;
F_25 ( & V_8 . V_12 ) ;
F_124 ( & V_8 . V_43 ) ;
V_8 . V_35 = F_125 ( V_119 , L_11 ) ;
if ( F_34 ( V_8 . V_35 ) ) {
V_15 = F_69 ( V_8 . V_35 ) ;
goto V_120;
}
V_8 . V_35 -> V_121 = F_120 ;
V_15 = F_126 ( & V_8 . V_36 , 0 , V_20 , L_11 ) ;
if ( V_15 )
goto V_122;
F_127 ( & V_8 . V_123 , & V_95 ) ;
V_15 = F_128 ( & V_8 . V_123 , V_8 . V_36 , 1 ) ;
if ( V_15 )
goto V_124;
V_8 . V_27 = F_30 ( V_8 . V_35 , NULL , V_8 . V_36 , NULL , L_11 ) ;
if ( F_34 ( V_8 . V_27 ) ) {
V_15 = F_69 ( V_8 . V_27 ) ;
goto V_125;
}
F_127 ( & V_8 . V_126 , & V_127 ) ;
V_15 = F_128 ( & V_8 . V_126 ,
F_31 ( F_32 ( V_8 . V_36 ) , 1 ) , V_20 - 1 ) ;
if ( V_15 )
goto V_128;
F_129 ( V_129 L_12 V_130 L_13 ) ;
F_130 ( L_14 ) ;
return 0 ;
V_128:
F_38 ( V_8 . V_35 , V_8 . V_36 ) ;
V_125:
F_131 ( & V_8 . V_123 ) ;
V_124:
F_132 ( V_8 . V_36 , V_20 ) ;
V_122:
F_133 ( V_8 . V_35 ) ;
V_8 . V_35 = NULL ;
V_120:
return V_15 ;
}
static void T_7 F_134 ( void )
{
F_36 ( ! F_37 ( & V_8 . V_37 ) ) ;
F_135 ( & V_8 . V_18 ) ;
F_131 ( & V_8 . V_126 ) ;
F_38 ( V_8 . V_35 , V_8 . V_36 ) ;
F_131 ( & V_8 . V_123 ) ;
F_132 ( V_8 . V_36 , V_20 ) ;
F_133 ( V_8 . V_35 ) ;
V_8 . V_35 = NULL ;
}
