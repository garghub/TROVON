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
const struct V_26 * F_14 ( const struct V_26 * V_27 ,
struct V_33 * V_34 )
{
if ( V_27 ) {
while ( V_27 -> V_3 || V_27 -> V_5 || V_27 -> V_8 ) {
if ( F_15 ( V_27 , V_34 ) )
return V_27 ;
V_27 ++ ;
}
}
return NULL ;
}
static const struct V_26 * F_16 ( struct V_1 * V_2 ,
struct V_33 * V_34 )
{
struct V_10 * V_11 ;
F_3 ( & V_2 -> V_16 . V_17 ) ;
F_17 (dynid, &drv->dynids.list, node) {
if ( F_15 ( & V_11 -> V_15 , V_34 ) ) {
F_5 ( & V_2 -> V_16 . V_17 ) ;
return & V_11 -> V_15 ;
}
}
F_5 ( & V_2 -> V_16 . V_17 ) ;
return F_14 ( V_2 -> V_28 , V_34 ) ;
}
static long F_18 ( void * V_35 )
{
struct V_36 * V_37 = V_35 ;
struct V_33 * V_33 = V_37 -> V_34 ;
struct V_1 * V_38 = V_37 -> V_2 ;
struct V_4 * V_34 = & V_33 -> V_34 ;
int V_39 ;
F_19 ( V_34 ) ;
V_33 -> V_20 = V_38 ;
V_39 = V_38 -> V_40 ( V_33 , V_37 -> V_15 ) ;
if ( V_39 ) {
V_33 -> V_20 = NULL ;
F_20 ( V_34 ) ;
}
return V_39 ;
}
static int F_21 ( struct V_1 * V_2 , struct V_33 * V_34 ,
const struct V_26 * V_15 )
{
int error , V_18 ;
struct V_36 V_37 = { V_2 , V_34 , V_15 } ;
V_18 = F_22 ( & V_34 -> V_34 ) ;
if ( V_18 >= 0 ) {
int V_41 ;
F_23 () ;
V_41 = F_24 ( F_25 ( V_18 ) , V_42 ) ;
if ( V_41 < V_43 )
error = F_26 ( V_41 , F_18 , & V_37 ) ;
else
error = F_18 ( & V_37 ) ;
F_27 () ;
} else
error = F_18 ( & V_37 ) ;
return error ;
}
static int
F_28 ( struct V_1 * V_2 , struct V_33 * V_33 )
{
const struct V_26 * V_15 ;
int error = 0 ;
if ( ! V_33 -> V_20 && V_2 -> V_40 ) {
error = - V_32 ;
V_15 = F_16 ( V_2 , V_33 ) ;
if ( V_15 )
error = F_21 ( V_2 , V_33 , V_15 ) ;
if ( error >= 0 )
error = 0 ;
}
return error ;
}
static int F_29 ( struct V_4 * V_34 )
{
int error = 0 ;
struct V_1 * V_2 ;
struct V_33 * V_33 ;
V_2 = F_12 ( V_34 -> V_20 ) ;
V_33 = F_30 ( V_34 ) ;
F_31 ( V_33 ) ;
error = F_28 ( V_2 , V_33 ) ;
if ( error )
F_32 ( V_33 ) ;
return error ;
}
static int F_33 ( struct V_4 * V_34 )
{
struct V_33 * V_33 = F_30 ( V_34 ) ;
struct V_1 * V_2 = V_33 -> V_20 ;
if ( V_2 ) {
if ( V_2 -> remove ) {
F_19 ( V_34 ) ;
V_2 -> remove ( V_33 ) ;
F_34 ( V_34 ) ;
}
V_33 -> V_20 = NULL ;
}
F_20 ( V_34 ) ;
if ( V_33 -> V_44 == V_45 )
V_33 -> V_44 = V_46 ;
F_32 ( V_33 ) ;
return 0 ;
}
static void F_35 ( struct V_4 * V_34 )
{
struct V_33 * V_33 = F_30 ( V_34 ) ;
struct V_1 * V_2 = V_33 -> V_20 ;
F_36 ( V_34 ) ;
if ( V_2 && V_2 -> V_47 )
V_2 -> V_47 ( V_33 ) ;
F_37 ( V_33 ) ;
F_38 ( V_33 ) ;
if ( V_33 -> V_44 <= V_48 )
F_39 ( V_33 ) ;
}
static int F_40 ( struct V_33 * V_33 )
{
F_41 ( V_33 , V_46 ) ;
if ( V_33 -> V_44 != V_45 ) {
int error = F_42 ( V_33 , V_45 ) ;
if ( error )
return error ;
}
F_43 ( V_33 ) ;
return 0 ;
}
static void F_44 ( struct V_33 * V_33 )
{
F_45 ( V_33 ) ;
F_43 ( V_33 ) ;
F_46 ( V_49 , V_33 ) ;
}
static void F_47 ( struct V_33 * V_33 )
{
if ( V_33 -> V_44 == V_45 )
V_33 -> V_44 = V_46 ;
}
static int F_48 ( struct V_33 * V_33 )
{
int V_12 ;
V_12 = F_49 ( V_33 ) ;
if ( V_33 -> V_50 )
F_50 ( V_33 ) ;
return V_12 ;
}
static int F_51 ( struct V_4 * V_34 , T_4 V_51 )
{
struct V_33 * V_33 = F_30 ( V_34 ) ;
struct V_1 * V_2 = V_33 -> V_20 ;
if ( V_2 && V_2 -> V_52 ) {
T_5 V_53 = V_33 -> V_44 ;
int error ;
error = V_2 -> V_52 ( V_33 , V_51 ) ;
F_52 ( V_2 -> V_52 , error ) ;
if ( error )
return error ;
if ( ! V_33 -> V_54 && V_33 -> V_44 != V_45
&& V_33 -> V_44 != V_46 ) {
F_53 ( V_33 -> V_44 != V_53 ,
L_3 ,
V_2 -> V_52 ) ;
}
}
F_46 ( V_55 , V_33 ) ;
return 0 ;
}
static int F_54 ( struct V_4 * V_34 , T_4 V_51 )
{
struct V_33 * V_33 = F_30 ( V_34 ) ;
struct V_1 * V_2 = V_33 -> V_20 ;
if ( V_2 && V_2 -> V_56 ) {
T_5 V_53 = V_33 -> V_44 ;
int error ;
error = V_2 -> V_56 ( V_33 , V_51 ) ;
F_52 ( V_2 -> V_56 , error ) ;
if ( error )
return error ;
if ( ! V_33 -> V_54 && V_33 -> V_44 != V_45
&& V_33 -> V_44 != V_46 ) {
F_53 ( V_33 -> V_44 != V_53 ,
L_3 ,
V_2 -> V_56 ) ;
return 0 ;
}
}
if ( ! V_33 -> V_54 )
F_55 ( V_33 ) ;
F_47 ( V_33 ) ;
return 0 ;
}
static int F_56 ( struct V_4 * V_34 )
{
struct V_33 * V_33 = F_30 ( V_34 ) ;
struct V_1 * V_2 = V_33 -> V_20 ;
return V_2 && V_2 -> V_57 ?
V_2 -> V_57 ( V_33 ) : 0 ;
}
static int F_57 ( struct V_4 * V_34 )
{
struct V_33 * V_33 = F_30 ( V_34 ) ;
struct V_1 * V_2 = V_33 -> V_20 ;
F_46 ( V_58 , V_33 ) ;
return V_2 && V_2 -> V_59 ?
V_2 -> V_59 ( V_33 ) : F_48 ( V_33 ) ;
}
static void F_58 ( struct V_33 * V_33 )
{
F_46 ( V_58 , V_33 ) ;
if ( ! F_59 ( V_33 ) )
F_60 ( V_33 , V_45 , false ) ;
}
static void F_61 ( struct V_33 * V_33 )
{
if ( ! F_59 ( V_33 ) )
F_62 ( V_33 ) ;
}
static bool F_63 ( struct V_33 * V_33 )
{
struct V_1 * V_2 = V_33 -> V_20 ;
bool V_60 = V_2 && ( V_2 -> V_52 || V_2 -> V_56 || V_2 -> V_59
|| V_2 -> V_57 ) ;
F_64 ( V_60 && V_2 -> V_20 . V_61 , L_4 ,
V_2 -> V_62 , V_33 -> V_3 , V_33 -> V_4 ) ;
return V_60 ;
}
static int F_65 ( struct V_4 * V_34 )
{
struct V_22 * V_2 = V_34 -> V_20 ;
int error = 0 ;
F_36 ( V_34 ) ;
if ( V_2 && V_2 -> V_61 && V_2 -> V_61 -> V_63 )
error = V_2 -> V_61 -> V_63 ( V_34 ) ;
return error ;
}
static void F_66 ( struct V_4 * V_34 )
{
struct V_22 * V_2 = V_34 -> V_20 ;
if ( V_2 && V_2 -> V_61 && V_2 -> V_61 -> V_64 )
V_2 -> V_61 -> V_64 ( V_34 ) ;
}
static int F_67 ( struct V_4 * V_34 )
{
struct V_33 * V_33 = F_30 ( V_34 ) ;
const struct V_65 * V_61 = V_34 -> V_20 ? V_34 -> V_20 -> V_61 : NULL ;
if ( F_63 ( V_33 ) )
return F_51 ( V_34 , V_66 ) ;
if ( ! V_61 ) {
F_61 ( V_33 ) ;
goto V_67;
}
V_33 -> V_54 = false ;
if ( V_61 -> V_52 ) {
T_5 V_53 = V_33 -> V_44 ;
int error ;
error = V_61 -> V_52 ( V_34 ) ;
F_52 ( V_61 -> V_52 , error ) ;
if ( error )
return error ;
if ( ! V_33 -> V_54 && V_33 -> V_44 != V_45
&& V_33 -> V_44 != V_46 ) {
F_53 ( V_33 -> V_44 != V_53 ,
L_5 ,
V_61 -> V_52 ) ;
}
}
V_67:
F_46 ( V_55 , V_33 ) ;
return 0 ;
}
static int F_68 ( struct V_4 * V_34 )
{
struct V_33 * V_33 = F_30 ( V_34 ) ;
const struct V_65 * V_61 = V_34 -> V_20 ? V_34 -> V_20 -> V_61 : NULL ;
if ( F_63 ( V_33 ) )
return F_54 ( V_34 , V_66 ) ;
if ( ! V_61 ) {
F_55 ( V_33 ) ;
return 0 ;
}
if ( V_61 -> V_68 ) {
T_5 V_53 = V_33 -> V_44 ;
int error ;
error = V_61 -> V_68 ( V_34 ) ;
F_52 ( V_61 -> V_68 , error ) ;
if ( error )
return error ;
if ( ! V_33 -> V_54 && V_33 -> V_44 != V_45
&& V_33 -> V_44 != V_46 ) {
F_53 ( V_33 -> V_44 != V_53 ,
L_5 ,
V_61 -> V_68 ) ;
return 0 ;
}
}
if ( ! V_33 -> V_54 ) {
F_55 ( V_33 ) ;
if ( ! F_59 ( V_33 ) )
F_69 ( V_33 ) ;
}
F_47 ( V_33 ) ;
if ( V_33 -> V_7 == V_69 )
F_70 ( V_33 , V_70 , 0 ) ;
return 0 ;
}
static int F_71 ( struct V_4 * V_34 )
{
struct V_33 * V_33 = F_30 ( V_34 ) ;
struct V_22 * V_2 = V_34 -> V_20 ;
int error = 0 ;
F_44 ( V_33 ) ;
if ( F_63 ( V_33 ) )
return F_56 ( V_34 ) ;
if ( V_2 && V_2 -> V_61 && V_2 -> V_61 -> V_71 )
error = V_2 -> V_61 -> V_71 ( V_34 ) ;
return error ;
}
static int F_72 ( struct V_4 * V_34 )
{
struct V_33 * V_33 = F_30 ( V_34 ) ;
const struct V_65 * V_61 = V_34 -> V_20 ? V_34 -> V_20 -> V_61 : NULL ;
int error = 0 ;
if ( V_33 -> V_54 )
F_40 ( V_33 ) ;
if ( F_63 ( V_33 ) )
return F_57 ( V_34 ) ;
F_58 ( V_33 ) ;
if ( V_61 ) {
if ( V_61 -> V_59 )
error = V_61 -> V_59 ( V_34 ) ;
} else {
F_48 ( V_33 ) ;
}
return error ;
}
static int F_73 ( struct V_4 * V_34 )
{
struct V_33 * V_33 = F_30 ( V_34 ) ;
const struct V_65 * V_61 = V_34 -> V_20 ? V_34 -> V_20 -> V_61 : NULL ;
if ( F_63 ( V_33 ) )
return F_51 ( V_34 , V_72 ) ;
if ( ! V_61 ) {
F_61 ( V_33 ) ;
return 0 ;
}
V_33 -> V_54 = false ;
if ( V_61 -> V_73 ) {
int error ;
error = V_61 -> V_73 ( V_34 ) ;
F_52 ( V_61 -> V_73 , error ) ;
if ( error )
return error ;
}
if ( V_74 . V_73 )
return V_74 . V_73 ( V_34 ) ;
return 0 ;
}
static int F_74 ( struct V_4 * V_34 )
{
struct V_33 * V_33 = F_30 ( V_34 ) ;
struct V_22 * V_2 = V_34 -> V_20 ;
if ( F_63 ( V_33 ) )
return F_54 ( V_34 , V_72 ) ;
if ( V_2 && V_2 -> V_61 && V_2 -> V_61 -> V_75 ) {
int error ;
error = V_2 -> V_61 -> V_75 ( V_34 ) ;
F_52 ( V_2 -> V_61 -> V_75 , error ) ;
if ( error )
return error ;
}
if ( ! V_33 -> V_54 )
F_55 ( V_33 ) ;
F_47 ( V_33 ) ;
if ( V_74 . V_75 )
return V_74 . V_75 ( V_34 ) ;
return 0 ;
}
static int F_75 ( struct V_4 * V_34 )
{
struct V_33 * V_33 = F_30 ( V_34 ) ;
struct V_22 * V_2 = V_34 -> V_20 ;
int error = 0 ;
if ( V_74 . V_76 ) {
error = V_74 . V_76 ( V_34 ) ;
if ( error )
return error ;
}
if ( F_63 ( V_33 ) )
return F_56 ( V_34 ) ;
F_41 ( V_33 , V_45 ) ;
if ( V_2 && V_2 -> V_61 && V_2 -> V_61 -> V_76 )
error = V_2 -> V_61 -> V_76 ( V_34 ) ;
return error ;
}
static int F_76 ( struct V_4 * V_34 )
{
struct V_33 * V_33 = F_30 ( V_34 ) ;
const struct V_65 * V_61 = V_34 -> V_20 ? V_34 -> V_20 -> V_61 : NULL ;
int error = 0 ;
if ( V_74 . V_77 ) {
error = V_74 . V_77 ( V_34 ) ;
if ( error )
return error ;
}
if ( F_63 ( V_33 ) )
return F_57 ( V_34 ) ;
if ( V_61 ) {
if ( V_61 -> V_77 )
error = V_61 -> V_77 ( V_34 ) ;
} else {
F_48 ( V_33 ) ;
}
V_33 -> V_54 = false ;
return error ;
}
static int F_77 ( struct V_4 * V_34 )
{
struct V_33 * V_33 = F_30 ( V_34 ) ;
const struct V_65 * V_61 = V_34 -> V_20 ? V_34 -> V_20 -> V_61 : NULL ;
if ( F_63 ( V_33 ) )
return F_51 ( V_34 , V_78 ) ;
if ( ! V_61 ) {
F_61 ( V_33 ) ;
goto V_67;
}
V_33 -> V_54 = false ;
if ( V_61 -> V_79 ) {
int error ;
error = V_61 -> V_79 ( V_34 ) ;
F_52 ( V_61 -> V_79 , error ) ;
if ( error )
return error ;
}
V_67:
F_46 ( V_55 , V_33 ) ;
if ( V_74 . V_79 )
return V_74 . V_79 ( V_34 ) ;
return 0 ;
}
static int F_78 ( struct V_4 * V_34 )
{
struct V_33 * V_33 = F_30 ( V_34 ) ;
struct V_22 * V_2 = V_34 -> V_20 ;
if ( F_63 ( F_30 ( V_34 ) ) )
return F_54 ( V_34 , V_78 ) ;
if ( ! V_2 || ! V_2 -> V_61 )
return 0 ;
if ( V_2 -> V_61 -> V_80 ) {
int error ;
error = V_2 -> V_61 -> V_80 ( V_34 ) ;
F_52 ( V_2 -> V_61 -> V_80 , error ) ;
if ( error )
return error ;
}
if ( ! V_33 -> V_54 && ! F_59 ( V_33 ) )
F_69 ( V_33 ) ;
if ( V_33 -> V_7 == V_69 )
F_70 ( V_33 , V_70 , 0 ) ;
if ( V_74 . V_80 )
return V_74 . V_80 ( V_34 ) ;
return 0 ;
}
static int F_79 ( struct V_4 * V_34 )
{
struct V_33 * V_33 = F_30 ( V_34 ) ;
struct V_22 * V_2 = V_34 -> V_20 ;
int error = 0 ;
if ( V_74 . V_81 ) {
error = V_74 . V_81 ( V_34 ) ;
if ( error )
return error ;
}
F_44 ( V_33 ) ;
if ( F_63 ( V_33 ) )
return F_56 ( V_34 ) ;
if ( V_2 && V_2 -> V_61 && V_2 -> V_61 -> V_81 )
error = V_2 -> V_61 -> V_81 ( V_34 ) ;
return error ;
}
static int F_80 ( struct V_4 * V_34 )
{
struct V_33 * V_33 = F_30 ( V_34 ) ;
const struct V_65 * V_61 = V_34 -> V_20 ? V_34 -> V_20 -> V_61 : NULL ;
int error = 0 ;
if ( V_74 . V_82 ) {
error = V_74 . V_82 ( V_34 ) ;
if ( error )
return error ;
}
if ( V_33 -> V_54 )
F_40 ( V_33 ) ;
if ( F_63 ( V_33 ) )
return F_57 ( V_34 ) ;
F_58 ( V_33 ) ;
if ( V_61 ) {
if ( V_61 -> V_82 )
error = V_61 -> V_82 ( V_34 ) ;
} else {
F_48 ( V_33 ) ;
}
return error ;
}
static int F_81 ( struct V_4 * V_34 )
{
struct V_33 * V_33 = F_30 ( V_34 ) ;
const struct V_65 * V_61 = V_34 -> V_20 ? V_34 -> V_20 -> V_61 : NULL ;
T_5 V_53 = V_33 -> V_44 ;
int error ;
if ( ! V_33 -> V_20 )
return 0 ;
if ( ! V_61 || ! V_61 -> V_83 )
return - V_84 ;
V_33 -> V_54 = false ;
V_33 -> V_85 = false ;
error = V_61 -> V_83 ( V_34 ) ;
F_52 ( V_61 -> V_83 , error ) ;
if ( error )
return error ;
if ( ! V_33 -> V_86 )
V_33 -> V_85 = true ;
F_46 ( V_55 , V_33 ) ;
if ( ! V_33 -> V_54 && V_33 -> V_44 != V_45
&& V_33 -> V_44 != V_46 ) {
F_53 ( V_33 -> V_44 != V_53 ,
L_5 ,
V_61 -> V_83 ) ;
return 0 ;
}
if ( ! V_33 -> V_54 ) {
F_55 ( V_33 ) ;
F_82 ( V_33 ) ;
}
return 0 ;
}
static int F_83 ( struct V_4 * V_34 )
{
int V_39 ;
struct V_33 * V_33 = F_30 ( V_34 ) ;
const struct V_65 * V_61 = V_34 -> V_20 ? V_34 -> V_20 -> V_61 : NULL ;
if ( ! V_33 -> V_20 )
return 0 ;
if ( ! V_61 || ! V_61 -> V_87 )
return - V_84 ;
F_40 ( V_33 ) ;
F_46 ( V_49 , V_33 ) ;
F_84 ( V_33 , V_45 , true , false ) ;
F_46 ( V_58 , V_33 ) ;
V_39 = V_61 -> V_87 ( V_34 ) ;
V_33 -> V_88 = false ;
return V_39 ;
}
static int F_85 ( struct V_4 * V_34 )
{
struct V_33 * V_33 = F_30 ( V_34 ) ;
const struct V_65 * V_61 = V_34 -> V_20 ? V_34 -> V_20 -> V_61 : NULL ;
int V_60 = 0 ;
if ( ! V_33 -> V_20 )
return 0 ;
if ( ! V_61 )
return - V_84 ;
if ( V_61 -> V_89 )
V_60 = V_61 -> V_89 ( V_34 ) ;
return V_60 ;
}
int F_86 ( struct V_1 * V_2 , struct V_90 * V_91 ,
const char * V_92 )
{
V_2 -> V_20 . V_62 = V_2 -> V_62 ;
V_2 -> V_20 . V_93 = & V_94 ;
V_2 -> V_20 . V_91 = V_91 ;
V_2 -> V_20 . V_92 = V_92 ;
F_87 ( & V_2 -> V_16 . V_17 ) ;
F_88 ( & V_2 -> V_16 . V_19 ) ;
return F_89 ( & V_2 -> V_20 ) ;
}
void
F_90 ( struct V_1 * V_2 )
{
F_91 ( & V_2 -> V_20 ) ;
F_7 ( V_2 ) ;
}
struct V_1 *
F_92 ( const struct V_33 * V_34 )
{
if ( V_34 -> V_20 )
return V_34 -> V_20 ;
else {
int V_95 ;
for( V_95 = 0 ; V_95 <= V_96 ; V_95 ++ )
if ( V_34 -> V_97 [ V_95 ] . V_98 & V_99 )
return & V_100 ;
}
return NULL ;
}
static int F_93 ( struct V_4 * V_34 , struct V_22 * V_2 )
{
struct V_33 * V_33 = F_30 ( V_34 ) ;
struct V_1 * V_38 ;
const struct V_26 * V_101 ;
if ( ! V_33 -> V_102 )
return 0 ;
V_38 = F_12 ( V_2 ) ;
V_101 = F_16 ( V_38 , V_33 ) ;
if ( V_101 )
return 1 ;
return 0 ;
}
struct V_33 * F_31 ( struct V_33 * V_34 )
{
if ( V_34 )
F_94 ( & V_34 -> V_34 ) ;
return V_34 ;
}
void F_32 ( struct V_33 * V_34 )
{
if ( V_34 )
F_95 ( & V_34 -> V_34 ) ;
}
static int F_96 ( struct V_4 * V_34 , struct V_103 * V_104 )
{
struct V_33 * V_105 ;
if ( ! V_34 )
return - V_32 ;
V_105 = F_30 ( V_34 ) ;
if ( ! V_105 )
return - V_32 ;
if ( F_97 ( V_104 , L_6 , V_105 -> V_7 ) )
return - V_14 ;
if ( F_97 ( V_104 , L_7 , V_105 -> V_3 , V_105 -> V_4 ) )
return - V_14 ;
if ( F_97 ( V_104 , L_8 , V_105 -> V_106 ,
V_105 -> V_107 ) )
return - V_14 ;
if ( F_97 ( V_104 , L_9 , F_98 ( V_105 ) ) )
return - V_14 ;
if ( F_97 ( V_104 , L_10 ,
V_105 -> V_3 , V_105 -> V_4 ,
V_105 -> V_106 , V_105 -> V_107 ,
( V_108 ) ( V_105 -> V_7 >> 16 ) , ( V_108 ) ( V_105 -> V_7 >> 8 ) ,
( V_108 ) ( V_105 -> V_7 ) ) )
return - V_14 ;
return 0 ;
}
static int T_6 F_99 ( void )
{
return F_100 ( & V_94 ) ;
}
