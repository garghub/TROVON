int F_1 ( struct V_1 * V_2 ,
unsigned int V_3 , unsigned int V_4 ,
unsigned int V_5 , unsigned int V_6 ,
unsigned int V_7 , unsigned int V_8 ,
unsigned long V_9 )
{
struct V_10 * V_11 ;
int V_12 ;
V_11 = F_2 ( sizeof( * V_11 ) , V_13 ) ;
if ( ! V_11 )
return - V_14 ;
V_11 -> V_15 . V_3 = V_3 ;
V_11 -> V_15 . V_4 = V_4 ;
V_11 -> V_15 . V_5 = V_5 ;
V_11 -> V_15 . V_6 = V_6 ;
V_11 -> V_15 . V_7 = V_7 ;
V_11 -> V_15 . V_8 = V_8 ;
V_11 -> V_15 . V_9 = V_9 ;
F_3 ( & V_2 -> V_16 . V_17 ) ;
F_4 ( & V_11 -> V_18 , & V_2 -> V_16 . V_19 ) ;
F_5 ( & V_2 -> V_16 . V_17 ) ;
V_12 = F_6 ( & V_2 -> V_20 ) ;
return V_12 ;
}
static void F_7 ( struct V_1 * V_2 )
{
struct V_10 * V_11 , * V_21 ;
F_3 ( & V_2 -> V_16 . V_17 ) ;
F_8 (dynid, n, &drv->dynids.list, node) {
F_9 ( & V_11 -> V_18 ) ;
F_10 ( V_11 ) ;
}
F_5 ( & V_2 -> V_16 . V_17 ) ;
}
static T_1
F_11 ( struct V_22 * V_20 , const char * V_23 , T_2 V_24 )
{
struct V_1 * V_25 = F_12 ( V_20 ) ;
const struct V_26 * V_27 = V_25 -> V_28 ;
T_3 V_3 , V_4 , V_5 = V_29 ,
V_6 = V_29 , V_7 = 0 , V_8 = 0 ;
unsigned long V_9 = 0 ;
int V_30 = 0 ;
int V_12 ;
V_30 = sscanf ( V_23 , L_1 ,
& V_3 , & V_4 , & V_5 , & V_6 ,
& V_7 , & V_8 , & V_9 ) ;
if ( V_30 < 2 )
return - V_31 ;
if ( V_27 ) {
V_12 = - V_31 ;
while ( V_27 -> V_3 || V_27 -> V_5 || V_27 -> V_8 ) {
if ( V_9 == V_27 -> V_9 ) {
V_12 = 0 ;
break;
}
V_27 ++ ;
}
if ( V_12 )
return V_12 ;
}
V_12 = F_1 ( V_25 , V_3 , V_4 , V_5 , V_6 ,
V_7 , V_8 , V_9 ) ;
if ( V_12 )
return V_12 ;
return V_24 ;
}
static T_1
F_13 ( struct V_22 * V_20 , const char * V_23 , T_2 V_24 )
{
struct V_10 * V_11 , * V_21 ;
struct V_1 * V_25 = F_12 ( V_20 ) ;
T_3 V_3 , V_4 , V_5 = V_29 ,
V_6 = V_29 , V_7 = 0 , V_8 = 0 ;
int V_30 = 0 ;
int V_12 = - V_32 ;
V_30 = sscanf ( V_23 , L_2 ,
& V_3 , & V_4 , & V_5 , & V_6 ,
& V_7 , & V_8 ) ;
if ( V_30 < 2 )
return - V_31 ;
F_3 ( & V_25 -> V_16 . V_17 ) ;
F_8 (dynid, n, &pdrv->dynids.list, node) {
struct V_26 * V_15 = & V_11 -> V_15 ;
if ( ( V_15 -> V_3 == V_3 ) &&
( V_15 -> V_4 == V_4 ) &&
( V_5 == V_29 || V_15 -> V_5 == V_5 ) &&
( V_6 == V_29 || V_15 -> V_6 == V_6 ) &&
! ( ( V_15 -> V_7 ^ V_7 ) & V_8 ) ) {
F_9 ( & V_11 -> V_18 ) ;
F_10 ( V_11 ) ;
V_12 = 0 ;
break;
}
}
F_5 ( & V_25 -> V_16 . V_17 ) ;
if ( V_12 )
return V_12 ;
return V_24 ;
}
static int
F_14 ( struct V_1 * V_2 )
{
int error = 0 ;
if ( V_2 -> V_33 != NULL ) {
error = F_15 ( & V_2 -> V_20 , & V_34 ) ;
if ( error == 0 ) {
error = F_15 ( & V_2 -> V_20 ,
& V_35 ) ;
if ( error )
F_16 ( & V_2 -> V_20 ,
& V_34 ) ;
}
}
return error ;
}
static void F_17 ( struct V_1 * V_2 )
{
F_16 ( & V_2 -> V_20 , & V_35 ) ;
F_16 ( & V_2 -> V_20 , & V_34 ) ;
}
static inline int F_14 ( struct V_1 * V_2 )
{
return 0 ;
}
static inline void F_17 ( struct V_1 * V_2 ) {}
const struct V_26 * F_18 ( const struct V_26 * V_27 ,
struct V_36 * V_37 )
{
if ( V_27 ) {
while ( V_27 -> V_3 || V_27 -> V_5 || V_27 -> V_8 ) {
if ( F_19 ( V_27 , V_37 ) )
return V_27 ;
V_27 ++ ;
}
}
return NULL ;
}
static const struct V_26 * F_20 ( struct V_1 * V_2 ,
struct V_36 * V_37 )
{
struct V_10 * V_11 ;
F_3 ( & V_2 -> V_16 . V_17 ) ;
F_21 (dynid, &drv->dynids.list, node) {
if ( F_19 ( & V_11 -> V_15 , V_37 ) ) {
F_5 ( & V_2 -> V_16 . V_17 ) ;
return & V_11 -> V_15 ;
}
}
F_5 ( & V_2 -> V_16 . V_17 ) ;
return F_18 ( V_2 -> V_28 , V_37 ) ;
}
static long F_22 ( void * V_38 )
{
struct V_39 * V_40 = V_38 ;
struct V_4 * V_37 = & V_40 -> V_37 -> V_37 ;
struct V_4 * V_41 = V_37 -> V_41 ;
int V_42 ;
if ( V_41 )
F_23 ( V_41 ) ;
F_24 ( V_37 ) ;
F_25 ( V_37 ) ;
F_26 ( V_37 ) ;
V_42 = V_40 -> V_2 -> V_33 ( V_40 -> V_37 , V_40 -> V_15 ) ;
if ( V_42 ) {
F_27 ( V_37 ) ;
F_28 ( V_37 ) ;
F_29 ( V_37 ) ;
}
if ( V_41 )
F_30 ( V_41 ) ;
return V_42 ;
}
static int F_31 ( struct V_1 * V_2 , struct V_36 * V_37 ,
const struct V_26 * V_15 )
{
int error , V_18 ;
struct V_39 V_40 = { V_2 , V_37 , V_15 } ;
V_18 = F_32 ( & V_37 -> V_37 ) ;
if ( V_18 >= 0 ) {
int V_43 ;
F_33 () ;
V_43 = F_34 ( F_35 ( V_18 ) , V_44 ) ;
if ( V_43 < V_45 )
error = F_36 ( V_43 , F_22 , & V_40 ) ;
else
error = F_22 ( & V_40 ) ;
F_37 () ;
} else
error = F_22 ( & V_40 ) ;
return error ;
}
static int
F_38 ( struct V_1 * V_2 , struct V_36 * V_36 )
{
const struct V_26 * V_15 ;
int error = 0 ;
if ( ! V_36 -> V_20 && V_2 -> V_33 ) {
error = - V_32 ;
V_15 = F_20 ( V_2 , V_36 ) ;
if ( V_15 )
error = F_31 ( V_2 , V_36 , V_15 ) ;
if ( error >= 0 ) {
V_36 -> V_20 = V_2 ;
error = 0 ;
}
}
return error ;
}
static int F_39 ( struct V_4 * V_37 )
{
int error = 0 ;
struct V_1 * V_2 ;
struct V_36 * V_36 ;
V_2 = F_12 ( V_37 -> V_20 ) ;
V_36 = F_40 ( V_37 ) ;
F_41 ( V_36 ) ;
error = F_38 ( V_2 , V_36 ) ;
if ( error )
F_42 ( V_36 ) ;
return error ;
}
static int F_43 ( struct V_4 * V_37 )
{
struct V_36 * V_36 = F_40 ( V_37 ) ;
struct V_1 * V_2 = V_36 -> V_20 ;
if ( V_2 ) {
if ( V_2 -> remove ) {
F_23 ( V_37 ) ;
V_2 -> remove ( V_36 ) ;
F_29 ( V_37 ) ;
}
V_36 -> V_20 = NULL ;
}
F_27 ( V_37 ) ;
F_28 ( V_37 ) ;
F_29 ( V_37 ) ;
if ( V_36 -> V_46 == V_47 )
V_36 -> V_46 = V_48 ;
F_42 ( V_36 ) ;
return 0 ;
}
static void F_44 ( struct V_4 * V_37 )
{
struct V_36 * V_36 = F_40 ( V_37 ) ;
struct V_1 * V_2 = V_36 -> V_20 ;
if ( V_2 && V_2 -> V_49 )
V_2 -> V_49 ( V_36 ) ;
F_45 ( V_36 ) ;
F_46 ( V_36 ) ;
F_47 ( V_36 ) ;
if ( ! F_48 ( V_37 ) )
F_49 ( V_36 , V_48 , false ) ;
}
static int F_50 ( struct V_36 * V_36 )
{
F_51 ( V_36 , V_48 ) ;
if ( V_36 -> V_46 != V_47 ) {
int error = F_52 ( V_36 , V_47 ) ;
if ( error )
return error ;
}
F_53 ( V_36 ) ;
return 0 ;
}
static void F_54 ( struct V_36 * V_36 )
{
F_55 ( V_36 ) ;
F_53 ( V_36 ) ;
F_56 ( V_50 , V_36 ) ;
}
static void F_57 ( struct V_36 * V_36 )
{
if ( V_36 -> V_46 == V_47 )
V_36 -> V_46 = V_48 ;
}
static int F_58 ( struct V_36 * V_36 )
{
int V_12 ;
V_12 = F_59 ( V_36 ) ;
if ( V_36 -> V_51 )
F_60 ( V_36 ) ;
return V_12 ;
}
static int F_61 ( struct V_4 * V_37 , T_4 V_52 )
{
struct V_36 * V_36 = F_40 ( V_37 ) ;
struct V_1 * V_2 = V_36 -> V_20 ;
if ( V_2 && V_2 -> V_53 ) {
T_5 V_54 = V_36 -> V_46 ;
int error ;
error = V_2 -> V_53 ( V_36 , V_52 ) ;
F_62 ( V_2 -> V_53 , error ) ;
if ( error )
return error ;
if ( ! V_36 -> V_55 && V_36 -> V_46 != V_47
&& V_36 -> V_46 != V_48 ) {
F_63 ( V_36 -> V_46 != V_54 ,
L_3 ,
V_2 -> V_53 ) ;
}
}
F_56 ( V_56 , V_36 ) ;
return 0 ;
}
static int F_64 ( struct V_4 * V_37 , T_4 V_52 )
{
struct V_36 * V_36 = F_40 ( V_37 ) ;
struct V_1 * V_2 = V_36 -> V_20 ;
if ( V_2 && V_2 -> V_57 ) {
T_5 V_54 = V_36 -> V_46 ;
int error ;
error = V_2 -> V_57 ( V_36 , V_52 ) ;
F_62 ( V_2 -> V_57 , error ) ;
if ( error )
return error ;
if ( ! V_36 -> V_55 && V_36 -> V_46 != V_47
&& V_36 -> V_46 != V_48 ) {
F_63 ( V_36 -> V_46 != V_54 ,
L_3 ,
V_2 -> V_57 ) ;
return 0 ;
}
}
if ( ! V_36 -> V_55 )
F_65 ( V_36 ) ;
F_57 ( V_36 ) ;
return 0 ;
}
static int F_66 ( struct V_4 * V_37 )
{
struct V_36 * V_36 = F_40 ( V_37 ) ;
struct V_1 * V_2 = V_36 -> V_20 ;
return V_2 && V_2 -> V_58 ?
V_2 -> V_58 ( V_36 ) : 0 ;
}
static int F_67 ( struct V_4 * V_37 )
{
struct V_36 * V_36 = F_40 ( V_37 ) ;
struct V_1 * V_2 = V_36 -> V_20 ;
F_56 ( V_59 , V_36 ) ;
return V_2 && V_2 -> V_60 ?
V_2 -> V_60 ( V_36 ) : F_58 ( V_36 ) ;
}
static void F_68 ( struct V_36 * V_36 )
{
F_56 ( V_59 , V_36 ) ;
if ( ! F_69 ( V_36 ) )
F_49 ( V_36 , V_47 , false ) ;
}
static void F_70 ( struct V_36 * V_36 )
{
if ( ! F_69 ( V_36 ) )
F_71 ( V_36 ) ;
}
static bool F_72 ( struct V_36 * V_36 )
{
struct V_1 * V_2 = V_36 -> V_20 ;
bool V_61 = V_2 && ( V_2 -> V_53 || V_2 -> V_57 || V_2 -> V_60
|| V_2 -> V_58 ) ;
F_73 ( V_61 && V_2 -> V_20 . V_62 , L_4 ,
V_2 -> V_63 , V_36 -> V_3 , V_36 -> V_4 ) ;
return V_61 ;
}
static int F_74 ( struct V_4 * V_37 )
{
struct V_22 * V_2 = V_37 -> V_20 ;
int error = 0 ;
F_24 ( V_37 ) ;
if ( F_75 ( V_37 ) && F_48 ( V_37 ) )
F_76 ( V_37 , 0 ) ;
if ( F_77 () ) {
F_78 ( V_37 ) ;
return - V_64 ;
}
F_79 ( V_37 ) ;
if ( V_2 && V_2 -> V_62 && V_2 -> V_62 -> V_65 )
error = V_2 -> V_62 -> V_65 ( V_37 ) ;
return error ;
}
static void F_80 ( struct V_4 * V_37 )
{
struct V_22 * V_2 = V_37 -> V_20 ;
if ( V_2 && V_2 -> V_62 && V_2 -> V_62 -> V_66 )
V_2 -> V_62 -> V_66 ( V_37 ) ;
F_78 ( V_37 ) ;
}
static int F_81 ( struct V_4 * V_37 )
{
struct V_36 * V_36 = F_40 ( V_37 ) ;
const struct V_67 * V_62 = V_37 -> V_20 ? V_37 -> V_20 -> V_62 : NULL ;
if ( F_72 ( V_36 ) )
return F_61 ( V_37 , V_68 ) ;
if ( ! V_62 ) {
F_70 ( V_36 ) ;
goto V_69;
}
if ( V_62 -> V_53 ) {
T_5 V_54 = V_36 -> V_46 ;
int error ;
error = V_62 -> V_53 ( V_37 ) ;
F_62 ( V_62 -> V_53 , error ) ;
if ( error )
return error ;
if ( ! V_36 -> V_55 && V_36 -> V_46 != V_47
&& V_36 -> V_46 != V_48 ) {
F_63 ( V_36 -> V_46 != V_54 ,
L_5 ,
V_62 -> V_53 ) ;
}
}
V_69:
F_56 ( V_56 , V_36 ) ;
return 0 ;
}
static int F_82 ( struct V_4 * V_37 )
{
struct V_36 * V_36 = F_40 ( V_37 ) ;
const struct V_67 * V_62 = V_37 -> V_20 ? V_37 -> V_20 -> V_62 : NULL ;
if ( F_72 ( V_36 ) )
return F_64 ( V_37 , V_68 ) ;
if ( ! V_62 ) {
F_65 ( V_36 ) ;
return 0 ;
}
if ( V_62 -> V_70 ) {
T_5 V_54 = V_36 -> V_46 ;
int error ;
error = V_62 -> V_70 ( V_37 ) ;
F_62 ( V_62 -> V_70 , error ) ;
if ( error )
return error ;
if ( ! V_36 -> V_55 && V_36 -> V_46 != V_47
&& V_36 -> V_46 != V_48 ) {
F_63 ( V_36 -> V_46 != V_54 ,
L_5 ,
V_62 -> V_70 ) ;
return 0 ;
}
}
if ( ! V_36 -> V_55 ) {
F_65 ( V_36 ) ;
if ( ! F_69 ( V_36 ) )
F_83 ( V_36 ) ;
}
F_57 ( V_36 ) ;
if ( V_36 -> V_7 == V_71 )
F_84 ( V_36 , V_72 , 0 ) ;
return 0 ;
}
static int F_85 ( struct V_4 * V_37 )
{
struct V_36 * V_36 = F_40 ( V_37 ) ;
struct V_22 * V_2 = V_37 -> V_20 ;
int error = 0 ;
F_54 ( V_36 ) ;
if ( F_72 ( V_36 ) )
return F_66 ( V_37 ) ;
if ( V_2 && V_2 -> V_62 && V_2 -> V_62 -> V_73 )
error = V_2 -> V_62 -> V_73 ( V_37 ) ;
return error ;
}
static int F_86 ( struct V_4 * V_37 )
{
struct V_36 * V_36 = F_40 ( V_37 ) ;
const struct V_67 * V_62 = V_37 -> V_20 ? V_37 -> V_20 -> V_62 : NULL ;
int error = 0 ;
if ( V_36 -> V_55 )
F_50 ( V_36 ) ;
if ( F_72 ( V_36 ) )
return F_67 ( V_37 ) ;
F_68 ( V_36 ) ;
if ( V_62 ) {
if ( V_62 -> V_60 )
error = V_62 -> V_60 ( V_37 ) ;
} else {
F_58 ( V_36 ) ;
}
return error ;
}
static int F_87 ( struct V_4 * V_37 )
{
struct V_36 * V_36 = F_40 ( V_37 ) ;
const struct V_67 * V_62 = V_37 -> V_20 ? V_37 -> V_20 -> V_62 : NULL ;
if ( F_72 ( V_36 ) )
return F_61 ( V_37 , V_74 ) ;
if ( ! V_62 ) {
F_70 ( V_36 ) ;
return 0 ;
}
if ( V_62 -> V_75 ) {
int error ;
error = V_62 -> V_75 ( V_37 ) ;
F_62 ( V_62 -> V_75 , error ) ;
if ( error )
return error ;
}
return 0 ;
}
static int F_88 ( struct V_4 * V_37 )
{
struct V_36 * V_36 = F_40 ( V_37 ) ;
struct V_22 * V_2 = V_37 -> V_20 ;
if ( F_72 ( V_36 ) )
return F_64 ( V_37 , V_74 ) ;
if ( V_2 && V_2 -> V_62 && V_2 -> V_62 -> V_76 ) {
int error ;
error = V_2 -> V_62 -> V_76 ( V_37 ) ;
F_62 ( V_2 -> V_62 -> V_76 , error ) ;
if ( error )
return error ;
}
if ( ! V_36 -> V_55 )
F_65 ( V_36 ) ;
F_57 ( V_36 ) ;
return 0 ;
}
static int F_89 ( struct V_4 * V_37 )
{
struct V_36 * V_36 = F_40 ( V_37 ) ;
struct V_22 * V_2 = V_37 -> V_20 ;
int error = 0 ;
if ( F_72 ( V_36 ) )
return F_66 ( V_37 ) ;
F_51 ( V_36 , V_47 ) ;
if ( V_2 && V_2 -> V_62 && V_2 -> V_62 -> V_77 )
error = V_2 -> V_62 -> V_77 ( V_37 ) ;
return error ;
}
static int F_90 ( struct V_4 * V_37 )
{
struct V_36 * V_36 = F_40 ( V_37 ) ;
const struct V_67 * V_62 = V_37 -> V_20 ? V_37 -> V_20 -> V_62 : NULL ;
int error = 0 ;
if ( F_72 ( V_36 ) )
return F_67 ( V_37 ) ;
if ( V_62 ) {
if ( V_62 -> V_78 )
error = V_62 -> V_78 ( V_37 ) ;
} else {
F_58 ( V_36 ) ;
}
V_36 -> V_55 = false ;
return error ;
}
static int F_91 ( struct V_4 * V_37 )
{
struct V_36 * V_36 = F_40 ( V_37 ) ;
const struct V_67 * V_62 = V_37 -> V_20 ? V_37 -> V_20 -> V_62 : NULL ;
if ( F_72 ( V_36 ) )
return F_61 ( V_37 , V_79 ) ;
if ( ! V_62 ) {
F_70 ( V_36 ) ;
goto V_69;
}
if ( V_62 -> V_80 ) {
int error ;
error = V_62 -> V_80 ( V_37 ) ;
F_62 ( V_62 -> V_80 , error ) ;
if ( error )
return error ;
}
V_69:
F_56 ( V_56 , V_36 ) ;
return 0 ;
}
static int F_92 ( struct V_4 * V_37 )
{
struct V_36 * V_36 = F_40 ( V_37 ) ;
struct V_22 * V_2 = V_37 -> V_20 ;
if ( F_72 ( F_40 ( V_37 ) ) )
return F_64 ( V_37 , V_79 ) ;
if ( ! V_2 || ! V_2 -> V_62 )
return 0 ;
if ( V_2 -> V_62 -> V_81 ) {
int error ;
error = V_2 -> V_62 -> V_81 ( V_37 ) ;
F_62 ( V_2 -> V_62 -> V_81 , error ) ;
if ( error )
return error ;
}
if ( ! V_36 -> V_55 && ! F_69 ( V_36 ) )
F_83 ( V_36 ) ;
if ( V_36 -> V_7 == V_71 )
F_84 ( V_36 , V_72 , 0 ) ;
return 0 ;
}
static int F_93 ( struct V_4 * V_37 )
{
struct V_36 * V_36 = F_40 ( V_37 ) ;
struct V_22 * V_2 = V_37 -> V_20 ;
int error = 0 ;
F_54 ( V_36 ) ;
if ( F_72 ( V_36 ) )
return F_66 ( V_37 ) ;
if ( V_2 && V_2 -> V_62 && V_2 -> V_62 -> V_82 )
error = V_2 -> V_62 -> V_82 ( V_37 ) ;
return error ;
}
static int F_94 ( struct V_4 * V_37 )
{
struct V_36 * V_36 = F_40 ( V_37 ) ;
const struct V_67 * V_62 = V_37 -> V_20 ? V_37 -> V_20 -> V_62 : NULL ;
int error = 0 ;
if ( V_36 -> V_55 )
F_50 ( V_36 ) ;
if ( F_72 ( V_36 ) )
return F_67 ( V_37 ) ;
F_68 ( V_36 ) ;
if ( V_62 ) {
if ( V_62 -> V_83 )
error = V_62 -> V_83 ( V_37 ) ;
} else {
F_58 ( V_36 ) ;
}
return error ;
}
static int F_95 ( struct V_4 * V_37 )
{
struct V_36 * V_36 = F_40 ( V_37 ) ;
const struct V_67 * V_62 = V_37 -> V_20 ? V_37 -> V_20 -> V_62 : NULL ;
T_5 V_54 = V_36 -> V_46 ;
int error ;
if ( ! V_62 || ! V_62 -> V_84 )
return - V_85 ;
V_36 -> V_86 = false ;
error = V_62 -> V_84 ( V_37 ) ;
F_62 ( V_62 -> V_84 , error ) ;
if ( error )
return error ;
if ( ! V_36 -> V_87 )
V_36 -> V_86 = true ;
F_56 ( V_56 , V_36 ) ;
if ( ! V_36 -> V_55 && V_36 -> V_46 != V_47
&& V_36 -> V_46 != V_48 ) {
F_63 ( V_36 -> V_46 != V_54 ,
L_5 ,
V_62 -> V_84 ) ;
return 0 ;
}
if ( ! V_36 -> V_55 )
F_65 ( V_36 ) ;
F_96 ( V_36 ) ;
return 0 ;
}
static int F_97 ( struct V_4 * V_37 )
{
int V_42 ;
struct V_36 * V_36 = F_40 ( V_37 ) ;
const struct V_67 * V_62 = V_37 -> V_20 ? V_37 -> V_20 -> V_62 : NULL ;
if ( ! V_62 || ! V_62 -> V_88 )
return - V_85 ;
F_50 ( V_36 ) ;
F_56 ( V_50 , V_36 ) ;
F_98 ( V_36 , V_47 , true , false ) ;
F_56 ( V_59 , V_36 ) ;
V_42 = V_62 -> V_88 ( V_37 ) ;
V_36 -> V_89 = false ;
return V_42 ;
}
static int F_99 ( struct V_4 * V_37 )
{
const struct V_67 * V_62 = V_37 -> V_20 ? V_37 -> V_20 -> V_62 : NULL ;
if ( ! V_62 )
return - V_85 ;
if ( V_62 -> V_90 ) {
int V_61 = V_62 -> V_90 ( V_37 ) ;
if ( V_61 )
return V_61 ;
}
F_100 ( V_37 ) ;
return 0 ;
}
int F_101 ( struct V_1 * V_2 , struct V_91 * V_92 ,
const char * V_93 )
{
int error ;
V_2 -> V_20 . V_63 = V_2 -> V_63 ;
V_2 -> V_20 . V_94 = & V_95 ;
V_2 -> V_20 . V_92 = V_92 ;
V_2 -> V_20 . V_93 = V_93 ;
F_102 ( & V_2 -> V_16 . V_17 ) ;
F_103 ( & V_2 -> V_16 . V_19 ) ;
error = F_104 ( & V_2 -> V_20 ) ;
if ( error )
goto V_96;
error = F_14 ( V_2 ) ;
if ( error )
goto V_97;
V_96:
return error ;
V_97:
F_105 ( & V_2 -> V_20 ) ;
goto V_96;
}
void
F_106 ( struct V_1 * V_2 )
{
F_17 ( V_2 ) ;
F_105 ( & V_2 -> V_20 ) ;
F_7 ( V_2 ) ;
}
struct V_1 *
F_107 ( const struct V_36 * V_37 )
{
if ( V_37 -> V_20 )
return V_37 -> V_20 ;
else {
int V_98 ;
for( V_98 = 0 ; V_98 <= V_99 ; V_98 ++ )
if ( V_37 -> V_100 [ V_98 ] . V_101 & V_102 )
return & V_103 ;
}
return NULL ;
}
static int F_108 ( struct V_4 * V_37 , struct V_22 * V_2 )
{
struct V_36 * V_36 = F_40 ( V_37 ) ;
struct V_1 * V_104 = F_12 ( V_2 ) ;
const struct V_26 * V_105 ;
V_105 = F_20 ( V_104 , V_36 ) ;
if ( V_105 )
return 1 ;
return 0 ;
}
struct V_36 * F_41 ( struct V_36 * V_37 )
{
if ( V_37 )
F_109 ( & V_37 -> V_37 ) ;
return V_37 ;
}
void F_42 ( struct V_36 * V_37 )
{
if ( V_37 )
F_110 ( & V_37 -> V_37 ) ;
}
int F_111 ( struct V_4 * V_37 , struct V_106 * V_107 )
{
return - V_32 ;
}
static int T_6 F_112 ( void )
{
return F_113 ( & V_95 ) ;
}
