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
F_6 ( & V_2 -> V_20 ) ;
V_12 = F_7 ( & V_2 -> V_20 ) ;
F_8 ( & V_2 -> V_20 ) ;
return V_12 ;
}
static void F_9 ( struct V_1 * V_2 )
{
struct V_10 * V_11 , * V_21 ;
F_3 ( & V_2 -> V_16 . V_17 ) ;
F_10 (dynid, n, &drv->dynids.list, node) {
F_11 ( & V_11 -> V_18 ) ;
F_12 ( V_11 ) ;
}
F_5 ( & V_2 -> V_16 . V_17 ) ;
}
static T_1
F_13 ( struct V_22 * V_20 , const char * V_23 , T_2 V_24 )
{
struct V_1 * V_25 = F_14 ( V_20 ) ;
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
F_15 ( struct V_22 * V_20 , const char * V_23 , T_2 V_24 )
{
struct V_10 * V_11 , * V_21 ;
struct V_1 * V_25 = F_14 ( V_20 ) ;
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
F_10 (dynid, n, &pdrv->dynids.list, node) {
struct V_26 * V_15 = & V_11 -> V_15 ;
if ( ( V_15 -> V_3 == V_3 ) &&
( V_15 -> V_4 == V_4 ) &&
( V_5 == V_29 || V_15 -> V_5 == V_5 ) &&
( V_6 == V_29 || V_15 -> V_6 == V_6 ) &&
! ( ( V_15 -> V_7 ^ V_7 ) & V_8 ) ) {
F_11 ( & V_11 -> V_18 ) ;
F_12 ( V_11 ) ;
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
F_16 ( struct V_1 * V_2 )
{
int error = 0 ;
if ( V_2 -> V_33 != NULL )
error = F_17 ( & V_2 -> V_20 , & V_34 ) ;
return error ;
}
static void F_18 ( struct V_1 * V_2 )
{
F_19 ( & V_2 -> V_20 , & V_34 ) ;
}
static int
F_20 ( struct V_1 * V_2 )
{
int error = 0 ;
if ( V_2 -> V_33 != NULL )
error = F_17 ( & V_2 -> V_20 , & V_35 ) ;
return error ;
}
static void F_21 ( struct V_1 * V_2 )
{
F_19 ( & V_2 -> V_20 , & V_35 ) ;
}
static inline int F_16 ( struct V_1 * V_2 )
{
return 0 ;
}
static inline void F_18 ( struct V_1 * V_2 ) {}
static inline int F_20 ( struct V_1 * V_2 )
{
return 0 ;
}
static inline void F_21 ( struct V_1 * V_2 ) {}
const struct V_26 * F_22 ( const struct V_26 * V_27 ,
struct V_36 * V_37 )
{
if ( V_27 ) {
while ( V_27 -> V_3 || V_27 -> V_5 || V_27 -> V_8 ) {
if ( F_23 ( V_27 , V_37 ) )
return V_27 ;
V_27 ++ ;
}
}
return NULL ;
}
static const struct V_26 * F_24 ( struct V_1 * V_2 ,
struct V_36 * V_37 )
{
struct V_10 * V_11 ;
F_3 ( & V_2 -> V_16 . V_17 ) ;
F_25 (dynid, &drv->dynids.list, node) {
if ( F_23 ( & V_11 -> V_15 , V_37 ) ) {
F_5 ( & V_2 -> V_16 . V_17 ) ;
return & V_11 -> V_15 ;
}
}
F_5 ( & V_2 -> V_16 . V_17 ) ;
return F_22 ( V_2 -> V_28 , V_37 ) ;
}
static long F_26 ( void * V_38 )
{
struct V_39 * V_40 = V_38 ;
struct V_4 * V_37 = & V_40 -> V_37 -> V_37 ;
int V_41 ;
F_27 ( V_37 ) ;
F_28 ( V_37 ) ;
F_29 ( V_37 ) ;
V_41 = V_40 -> V_2 -> V_33 ( V_40 -> V_37 , V_40 -> V_15 ) ;
if ( V_41 ) {
F_30 ( V_37 ) ;
F_31 ( V_37 ) ;
F_32 ( V_37 ) ;
}
return V_41 ;
}
static int F_33 ( struct V_1 * V_2 , struct V_36 * V_37 ,
const struct V_26 * V_15 )
{
int error , V_18 ;
struct V_39 V_40 = { V_2 , V_37 , V_15 } ;
V_18 = F_34 ( & V_37 -> V_37 ) ;
if ( V_18 >= 0 ) {
int V_42 ;
F_35 () ;
V_42 = F_36 ( F_37 ( V_18 ) , V_43 ) ;
if ( V_42 < V_44 )
error = F_38 ( V_42 , F_26 , & V_40 ) ;
else
error = F_26 ( & V_40 ) ;
F_39 () ;
} else
error = F_26 ( & V_40 ) ;
return error ;
}
static int
F_40 ( struct V_1 * V_2 , struct V_36 * V_36 )
{
const struct V_26 * V_15 ;
int error = 0 ;
if ( ! V_36 -> V_20 && V_2 -> V_33 ) {
error = - V_32 ;
V_15 = F_24 ( V_2 , V_36 ) ;
if ( V_15 )
error = F_33 ( V_2 , V_36 , V_15 ) ;
if ( error >= 0 ) {
V_36 -> V_20 = V_2 ;
error = 0 ;
}
}
return error ;
}
static int F_41 ( struct V_4 * V_37 )
{
int error = 0 ;
struct V_1 * V_2 ;
struct V_36 * V_36 ;
V_2 = F_14 ( V_37 -> V_20 ) ;
V_36 = F_42 ( V_37 ) ;
F_43 ( V_36 ) ;
error = F_40 ( V_2 , V_36 ) ;
if ( error )
F_44 ( V_36 ) ;
return error ;
}
static int F_45 ( struct V_4 * V_37 )
{
struct V_36 * V_36 = F_42 ( V_37 ) ;
struct V_1 * V_2 = V_36 -> V_20 ;
if ( V_2 ) {
if ( V_2 -> remove ) {
F_46 ( V_37 ) ;
V_2 -> remove ( V_36 ) ;
F_32 ( V_37 ) ;
}
V_36 -> V_20 = NULL ;
}
F_30 ( V_37 ) ;
F_31 ( V_37 ) ;
F_32 ( V_37 ) ;
if ( V_36 -> V_45 == V_46 )
V_36 -> V_45 = V_47 ;
F_44 ( V_36 ) ;
return 0 ;
}
static void F_47 ( struct V_4 * V_37 )
{
struct V_36 * V_36 = F_42 ( V_37 ) ;
struct V_1 * V_2 = V_36 -> V_20 ;
if ( V_2 && V_2 -> V_48 )
V_2 -> V_48 ( V_36 ) ;
F_48 ( V_36 ) ;
F_49 ( V_36 ) ;
}
static int F_50 ( struct V_36 * V_36 )
{
F_51 ( V_36 , V_47 ) ;
if ( V_36 -> V_45 != V_46 ) {
int error = F_52 ( V_36 , V_46 ) ;
if ( error )
return error ;
}
F_53 ( V_36 ) ;
return 0 ;
}
static void F_54 ( struct V_36 * V_36 )
{
F_50 ( V_36 ) ;
F_55 ( V_49 , V_36 ) ;
}
static void F_56 ( struct V_36 * V_36 )
{
if ( V_36 -> V_45 == V_46 )
V_36 -> V_45 = V_47 ;
}
static int F_57 ( struct V_36 * V_36 )
{
int V_12 ;
V_12 = F_58 ( V_36 ) ;
if ( V_36 -> V_50 )
F_59 ( V_36 ) ;
return V_12 ;
}
static int F_60 ( struct V_4 * V_37 , T_4 V_51 )
{
struct V_36 * V_36 = F_42 ( V_37 ) ;
struct V_1 * V_2 = V_36 -> V_20 ;
if ( V_2 && V_2 -> V_52 ) {
T_5 V_53 = V_36 -> V_45 ;
int error ;
error = V_2 -> V_52 ( V_36 , V_51 ) ;
F_61 ( V_2 -> V_52 , error ) ;
if ( error )
return error ;
if ( ! V_36 -> V_54 && V_36 -> V_45 != V_46
&& V_36 -> V_45 != V_47 ) {
F_62 ( V_36 -> V_45 != V_53 ,
L_3 ,
V_2 -> V_52 ) ;
}
}
F_55 ( V_55 , V_36 ) ;
return 0 ;
}
static int F_63 ( struct V_4 * V_37 , T_4 V_51 )
{
struct V_36 * V_36 = F_42 ( V_37 ) ;
struct V_1 * V_2 = V_36 -> V_20 ;
if ( V_2 && V_2 -> V_56 ) {
T_5 V_53 = V_36 -> V_45 ;
int error ;
error = V_2 -> V_56 ( V_36 , V_51 ) ;
F_61 ( V_2 -> V_56 , error ) ;
if ( error )
return error ;
if ( ! V_36 -> V_54 && V_36 -> V_45 != V_46
&& V_36 -> V_45 != V_47 ) {
F_62 ( V_36 -> V_45 != V_53 ,
L_3 ,
V_2 -> V_56 ) ;
return 0 ;
}
}
if ( ! V_36 -> V_54 )
F_64 ( V_36 ) ;
F_56 ( V_36 ) ;
return 0 ;
}
static int F_65 ( struct V_4 * V_37 )
{
struct V_36 * V_36 = F_42 ( V_37 ) ;
struct V_1 * V_2 = V_36 -> V_20 ;
return V_2 && V_2 -> V_57 ?
V_2 -> V_57 ( V_36 ) : 0 ;
}
static int F_66 ( struct V_4 * V_37 )
{
struct V_36 * V_36 = F_42 ( V_37 ) ;
struct V_1 * V_2 = V_36 -> V_20 ;
F_55 ( V_58 , V_36 ) ;
return V_2 && V_2 -> V_59 ?
V_2 -> V_59 ( V_36 ) : F_57 ( V_36 ) ;
}
static void F_67 ( struct V_36 * V_36 )
{
F_55 ( V_58 , V_36 ) ;
if ( ! F_68 ( V_36 ) )
F_69 ( V_36 , V_46 , false ) ;
}
static void F_70 ( struct V_36 * V_36 )
{
if ( ! F_68 ( V_36 ) )
F_71 ( V_36 ) ;
}
static bool F_72 ( struct V_36 * V_36 )
{
struct V_1 * V_2 = V_36 -> V_20 ;
bool V_60 = V_2 && ( V_2 -> V_52 || V_2 -> V_56 || V_2 -> V_59
|| V_2 -> V_57 ) ;
F_73 ( V_60 && V_2 -> V_20 . V_61 ) ;
return V_60 ;
}
static int F_74 ( struct V_4 * V_37 )
{
struct V_22 * V_2 = V_37 -> V_20 ;
int error = 0 ;
F_46 ( V_37 ) ;
if ( V_2 && V_2 -> V_61 && V_2 -> V_61 -> V_62 )
error = V_2 -> V_61 -> V_62 ( V_37 ) ;
return error ;
}
static void F_75 ( struct V_4 * V_37 )
{
struct V_22 * V_2 = V_37 -> V_20 ;
if ( V_2 && V_2 -> V_61 && V_2 -> V_61 -> V_63 )
V_2 -> V_61 -> V_63 ( V_37 ) ;
F_76 ( V_37 ) ;
}
static int F_77 ( struct V_4 * V_37 )
{
struct V_36 * V_36 = F_42 ( V_37 ) ;
const struct V_64 * V_61 = V_37 -> V_20 ? V_37 -> V_20 -> V_61 : NULL ;
if ( F_72 ( V_36 ) )
return F_60 ( V_37 , V_65 ) ;
if ( ! V_61 ) {
F_70 ( V_36 ) ;
goto V_66;
}
if ( V_61 -> V_52 ) {
T_5 V_53 = V_36 -> V_45 ;
int error ;
error = V_61 -> V_52 ( V_37 ) ;
F_61 ( V_61 -> V_52 , error ) ;
if ( error )
return error ;
if ( ! V_36 -> V_54 && V_36 -> V_45 != V_46
&& V_36 -> V_45 != V_47 ) {
F_62 ( V_36 -> V_45 != V_53 ,
L_4 ,
V_61 -> V_52 ) ;
}
}
V_66:
F_55 ( V_55 , V_36 ) ;
return 0 ;
}
static int F_78 ( struct V_4 * V_37 )
{
struct V_36 * V_36 = F_42 ( V_37 ) ;
const struct V_64 * V_61 = V_37 -> V_20 ? V_37 -> V_20 -> V_61 : NULL ;
if ( F_72 ( V_36 ) )
return F_63 ( V_37 , V_65 ) ;
if ( ! V_61 ) {
F_64 ( V_36 ) ;
return 0 ;
}
if ( V_61 -> V_67 ) {
T_5 V_53 = V_36 -> V_45 ;
int error ;
error = V_61 -> V_67 ( V_37 ) ;
F_61 ( V_61 -> V_67 , error ) ;
if ( error )
return error ;
if ( ! V_36 -> V_54 && V_36 -> V_45 != V_46
&& V_36 -> V_45 != V_47 ) {
F_62 ( V_36 -> V_45 != V_53 ,
L_4 ,
V_61 -> V_67 ) ;
return 0 ;
}
}
if ( ! V_36 -> V_54 ) {
F_64 ( V_36 ) ;
if ( ! F_68 ( V_36 ) )
F_79 ( V_36 ) ;
}
F_56 ( V_36 ) ;
return 0 ;
}
static int F_80 ( struct V_4 * V_37 )
{
struct V_36 * V_36 = F_42 ( V_37 ) ;
struct V_22 * V_2 = V_37 -> V_20 ;
int error = 0 ;
F_54 ( V_36 ) ;
if ( F_72 ( V_36 ) )
return F_65 ( V_37 ) ;
if ( V_2 && V_2 -> V_61 && V_2 -> V_61 -> V_68 )
error = V_2 -> V_61 -> V_68 ( V_37 ) ;
return error ;
}
static int F_81 ( struct V_4 * V_37 )
{
struct V_36 * V_36 = F_42 ( V_37 ) ;
const struct V_64 * V_61 = V_37 -> V_20 ? V_37 -> V_20 -> V_61 : NULL ;
int error = 0 ;
if ( V_36 -> V_54 )
F_50 ( V_36 ) ;
if ( F_72 ( V_36 ) )
return F_66 ( V_37 ) ;
F_67 ( V_36 ) ;
if ( V_61 ) {
if ( V_61 -> V_59 )
error = V_61 -> V_59 ( V_37 ) ;
} else {
F_57 ( V_36 ) ;
}
return error ;
}
static int F_82 ( struct V_4 * V_37 )
{
struct V_36 * V_36 = F_42 ( V_37 ) ;
const struct V_64 * V_61 = V_37 -> V_20 ? V_37 -> V_20 -> V_61 : NULL ;
if ( F_72 ( V_36 ) )
return F_60 ( V_37 , V_69 ) ;
if ( ! V_61 ) {
F_70 ( V_36 ) ;
return 0 ;
}
if ( V_61 -> V_70 ) {
int error ;
error = V_61 -> V_70 ( V_37 ) ;
F_61 ( V_61 -> V_70 , error ) ;
if ( error )
return error ;
}
return 0 ;
}
static int F_83 ( struct V_4 * V_37 )
{
struct V_36 * V_36 = F_42 ( V_37 ) ;
struct V_22 * V_2 = V_37 -> V_20 ;
if ( F_72 ( V_36 ) )
return F_63 ( V_37 , V_69 ) ;
if ( V_2 && V_2 -> V_61 && V_2 -> V_61 -> V_71 ) {
int error ;
error = V_2 -> V_61 -> V_71 ( V_37 ) ;
F_61 ( V_2 -> V_61 -> V_71 , error ) ;
if ( error )
return error ;
}
if ( ! V_36 -> V_54 )
F_64 ( V_36 ) ;
F_56 ( V_36 ) ;
return 0 ;
}
static int F_84 ( struct V_4 * V_37 )
{
struct V_36 * V_36 = F_42 ( V_37 ) ;
struct V_22 * V_2 = V_37 -> V_20 ;
int error = 0 ;
if ( F_72 ( V_36 ) )
return F_65 ( V_37 ) ;
F_51 ( V_36 , V_46 ) ;
if ( V_2 && V_2 -> V_61 && V_2 -> V_61 -> V_72 )
error = V_2 -> V_61 -> V_72 ( V_37 ) ;
return error ;
}
static int F_85 ( struct V_4 * V_37 )
{
struct V_36 * V_36 = F_42 ( V_37 ) ;
const struct V_64 * V_61 = V_37 -> V_20 ? V_37 -> V_20 -> V_61 : NULL ;
int error = 0 ;
if ( F_72 ( V_36 ) )
return F_66 ( V_37 ) ;
if ( V_61 ) {
if ( V_61 -> V_73 )
error = V_61 -> V_73 ( V_37 ) ;
} else {
F_57 ( V_36 ) ;
}
V_36 -> V_54 = false ;
return error ;
}
static int F_86 ( struct V_4 * V_37 )
{
struct V_36 * V_36 = F_42 ( V_37 ) ;
const struct V_64 * V_61 = V_37 -> V_20 ? V_37 -> V_20 -> V_61 : NULL ;
if ( F_72 ( V_36 ) )
return F_60 ( V_37 , V_74 ) ;
if ( ! V_61 ) {
F_70 ( V_36 ) ;
goto V_66;
}
if ( V_61 -> V_75 ) {
int error ;
error = V_61 -> V_75 ( V_37 ) ;
F_61 ( V_61 -> V_75 , error ) ;
if ( error )
return error ;
}
V_66:
F_55 ( V_55 , V_36 ) ;
return 0 ;
}
static int F_87 ( struct V_4 * V_37 )
{
struct V_36 * V_36 = F_42 ( V_37 ) ;
struct V_22 * V_2 = V_37 -> V_20 ;
if ( F_72 ( F_42 ( V_37 ) ) )
return F_63 ( V_37 , V_74 ) ;
if ( ! V_2 || ! V_2 -> V_61 )
return 0 ;
if ( V_2 -> V_61 -> V_76 ) {
int error ;
error = V_2 -> V_61 -> V_76 ( V_37 ) ;
F_61 ( V_2 -> V_61 -> V_76 , error ) ;
if ( error )
return error ;
}
if ( ! V_36 -> V_54 && ! F_68 ( V_36 ) )
F_79 ( V_36 ) ;
return 0 ;
}
static int F_88 ( struct V_4 * V_37 )
{
struct V_36 * V_36 = F_42 ( V_37 ) ;
struct V_22 * V_2 = V_37 -> V_20 ;
int error = 0 ;
F_54 ( V_36 ) ;
if ( F_72 ( V_36 ) )
return F_65 ( V_37 ) ;
if ( V_2 && V_2 -> V_61 && V_2 -> V_61 -> V_77 )
error = V_2 -> V_61 -> V_77 ( V_37 ) ;
return error ;
}
static int F_89 ( struct V_4 * V_37 )
{
struct V_36 * V_36 = F_42 ( V_37 ) ;
const struct V_64 * V_61 = V_37 -> V_20 ? V_37 -> V_20 -> V_61 : NULL ;
int error = 0 ;
if ( V_36 -> V_54 )
F_50 ( V_36 ) ;
if ( F_72 ( V_36 ) )
return F_66 ( V_37 ) ;
F_67 ( V_36 ) ;
if ( V_61 ) {
if ( V_61 -> V_78 )
error = V_61 -> V_78 ( V_37 ) ;
} else {
F_57 ( V_36 ) ;
}
return error ;
}
static int F_90 ( struct V_4 * V_37 )
{
struct V_36 * V_36 = F_42 ( V_37 ) ;
const struct V_64 * V_61 = V_37 -> V_20 ? V_37 -> V_20 -> V_61 : NULL ;
T_5 V_53 = V_36 -> V_45 ;
int error ;
if ( ! V_61 || ! V_61 -> V_79 )
return - V_80 ;
error = V_61 -> V_79 ( V_37 ) ;
F_61 ( V_61 -> V_79 , error ) ;
if ( error )
return error ;
F_55 ( V_55 , V_36 ) ;
if ( ! V_36 -> V_54 && V_36 -> V_45 != V_46
&& V_36 -> V_45 != V_47 ) {
F_62 ( V_36 -> V_45 != V_53 ,
L_4 ,
V_61 -> V_79 ) ;
return 0 ;
}
if ( ! V_36 -> V_54 )
F_64 ( V_36 ) ;
F_91 ( V_36 ) ;
return 0 ;
}
static int F_92 ( struct V_4 * V_37 )
{
struct V_36 * V_36 = F_42 ( V_37 ) ;
const struct V_64 * V_61 = V_37 -> V_20 ? V_37 -> V_20 -> V_61 : NULL ;
if ( ! V_61 || ! V_61 -> V_81 )
return - V_80 ;
F_54 ( V_36 ) ;
F_93 ( V_36 , V_46 , true , false ) ;
F_55 ( V_58 , V_36 ) ;
return V_61 -> V_81 ( V_37 ) ;
}
static int F_94 ( struct V_4 * V_37 )
{
const struct V_64 * V_61 = V_37 -> V_20 ? V_37 -> V_20 -> V_61 : NULL ;
if ( ! V_61 )
return - V_80 ;
if ( V_61 -> V_82 ) {
int V_60 = V_61 -> V_82 ( V_37 ) ;
if ( V_60 )
return V_60 ;
}
F_95 ( V_37 ) ;
return 0 ;
}
int F_96 ( struct V_1 * V_2 , struct V_83 * V_84 ,
const char * V_85 )
{
int error ;
V_2 -> V_20 . V_86 = V_2 -> V_86 ;
V_2 -> V_20 . V_87 = & V_88 ;
V_2 -> V_20 . V_84 = V_84 ;
V_2 -> V_20 . V_85 = V_85 ;
F_97 ( & V_2 -> V_16 . V_17 ) ;
F_98 ( & V_2 -> V_16 . V_19 ) ;
error = F_99 ( & V_2 -> V_20 ) ;
if ( error )
goto V_89;
error = F_16 ( V_2 ) ;
if ( error )
goto V_90;
error = F_20 ( V_2 ) ;
if ( error )
goto V_91;
V_89:
return error ;
V_91:
F_18 ( V_2 ) ;
V_90:
F_100 ( & V_2 -> V_20 ) ;
goto V_89;
}
void
F_101 ( struct V_1 * V_2 )
{
F_21 ( V_2 ) ;
F_18 ( V_2 ) ;
F_100 ( & V_2 -> V_20 ) ;
F_9 ( V_2 ) ;
}
struct V_1 *
F_102 ( const struct V_36 * V_37 )
{
if ( V_37 -> V_20 )
return V_37 -> V_20 ;
else {
int V_92 ;
for( V_92 = 0 ; V_92 <= V_93 ; V_92 ++ )
if ( V_37 -> V_94 [ V_92 ] . V_95 & V_96 )
return & V_97 ;
}
return NULL ;
}
static int F_103 ( struct V_4 * V_37 , struct V_22 * V_2 )
{
struct V_36 * V_36 = F_42 ( V_37 ) ;
struct V_1 * V_98 = F_14 ( V_2 ) ;
const struct V_26 * V_99 ;
V_99 = F_24 ( V_98 , V_36 ) ;
if ( V_99 )
return 1 ;
return 0 ;
}
struct V_36 * F_43 ( struct V_36 * V_37 )
{
if ( V_37 )
F_104 ( & V_37 -> V_37 ) ;
return V_37 ;
}
void F_44 ( struct V_36 * V_37 )
{
if ( V_37 )
F_105 ( & V_37 -> V_37 ) ;
}
int F_106 ( struct V_4 * V_37 , struct V_100 * V_101 )
{
return - V_32 ;
}
static int T_6 F_107 ( void )
{
return F_108 ( & V_88 ) ;
}
