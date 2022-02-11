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
F_46 ( V_48 , V_33 ) ;
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
if ( V_33 -> V_49 )
F_50 ( V_33 ) ;
return V_12 ;
}
static int F_51 ( struct V_4 * V_34 , T_4 V_50 )
{
struct V_33 * V_33 = F_30 ( V_34 ) ;
struct V_1 * V_2 = V_33 -> V_20 ;
if ( V_2 && V_2 -> V_51 ) {
T_5 V_52 = V_33 -> V_44 ;
int error ;
error = V_2 -> V_51 ( V_33 , V_50 ) ;
F_52 ( V_2 -> V_51 , error ) ;
if ( error )
return error ;
if ( ! V_33 -> V_53 && V_33 -> V_44 != V_45
&& V_33 -> V_44 != V_46 ) {
F_53 ( V_33 -> V_44 != V_52 ,
L_3 ,
V_2 -> V_51 ) ;
}
}
F_46 ( V_54 , V_33 ) ;
return 0 ;
}
static int F_54 ( struct V_4 * V_34 , T_4 V_50 )
{
struct V_33 * V_33 = F_30 ( V_34 ) ;
struct V_1 * V_2 = V_33 -> V_20 ;
if ( V_2 && V_2 -> V_55 ) {
T_5 V_52 = V_33 -> V_44 ;
int error ;
error = V_2 -> V_55 ( V_33 , V_50 ) ;
F_52 ( V_2 -> V_55 , error ) ;
if ( error )
return error ;
if ( ! V_33 -> V_53 && V_33 -> V_44 != V_45
&& V_33 -> V_44 != V_46 ) {
F_53 ( V_33 -> V_44 != V_52 ,
L_3 ,
V_2 -> V_55 ) ;
return 0 ;
}
}
if ( ! V_33 -> V_53 )
F_55 ( V_33 ) ;
F_47 ( V_33 ) ;
return 0 ;
}
static int F_56 ( struct V_4 * V_34 )
{
struct V_33 * V_33 = F_30 ( V_34 ) ;
struct V_1 * V_2 = V_33 -> V_20 ;
return V_2 && V_2 -> V_56 ?
V_2 -> V_56 ( V_33 ) : 0 ;
}
static int F_57 ( struct V_4 * V_34 )
{
struct V_33 * V_33 = F_30 ( V_34 ) ;
struct V_1 * V_2 = V_33 -> V_20 ;
F_46 ( V_57 , V_33 ) ;
return V_2 && V_2 -> V_58 ?
V_2 -> V_58 ( V_33 ) : F_48 ( V_33 ) ;
}
static void F_58 ( struct V_33 * V_33 )
{
F_46 ( V_57 , V_33 ) ;
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
bool V_59 = V_2 && ( V_2 -> V_51 || V_2 -> V_55 || V_2 -> V_58
|| V_2 -> V_56 ) ;
F_64 ( V_59 && V_2 -> V_20 . V_60 , L_4 ,
V_2 -> V_61 , V_33 -> V_3 , V_33 -> V_4 ) ;
return V_59 ;
}
static int F_65 ( struct V_4 * V_34 )
{
struct V_22 * V_2 = V_34 -> V_20 ;
int error = 0 ;
F_36 ( V_34 ) ;
if ( V_2 && V_2 -> V_60 && V_2 -> V_60 -> V_62 )
error = V_2 -> V_60 -> V_62 ( V_34 ) ;
return error ;
}
static void F_66 ( struct V_4 * V_34 )
{
struct V_22 * V_2 = V_34 -> V_20 ;
if ( V_2 && V_2 -> V_60 && V_2 -> V_60 -> V_63 )
V_2 -> V_60 -> V_63 ( V_34 ) ;
}
static int F_67 ( struct V_4 * V_34 )
{
struct V_33 * V_33 = F_30 ( V_34 ) ;
const struct V_64 * V_60 = V_34 -> V_20 ? V_34 -> V_20 -> V_60 : NULL ;
if ( F_63 ( V_33 ) )
return F_51 ( V_34 , V_65 ) ;
if ( ! V_60 ) {
F_61 ( V_33 ) ;
goto V_66;
}
if ( V_60 -> V_51 ) {
T_5 V_52 = V_33 -> V_44 ;
int error ;
error = V_60 -> V_51 ( V_34 ) ;
F_52 ( V_60 -> V_51 , error ) ;
if ( error )
return error ;
if ( ! V_33 -> V_53 && V_33 -> V_44 != V_45
&& V_33 -> V_44 != V_46 ) {
F_53 ( V_33 -> V_44 != V_52 ,
L_5 ,
V_60 -> V_51 ) ;
}
}
V_66:
F_46 ( V_54 , V_33 ) ;
return 0 ;
}
static int F_68 ( struct V_4 * V_34 )
{
struct V_33 * V_33 = F_30 ( V_34 ) ;
const struct V_64 * V_60 = V_34 -> V_20 ? V_34 -> V_20 -> V_60 : NULL ;
if ( F_63 ( V_33 ) )
return F_54 ( V_34 , V_65 ) ;
if ( ! V_60 ) {
F_55 ( V_33 ) ;
return 0 ;
}
if ( V_60 -> V_67 ) {
T_5 V_52 = V_33 -> V_44 ;
int error ;
error = V_60 -> V_67 ( V_34 ) ;
F_52 ( V_60 -> V_67 , error ) ;
if ( error )
return error ;
if ( ! V_33 -> V_53 && V_33 -> V_44 != V_45
&& V_33 -> V_44 != V_46 ) {
F_53 ( V_33 -> V_44 != V_52 ,
L_5 ,
V_60 -> V_67 ) ;
return 0 ;
}
}
if ( ! V_33 -> V_53 ) {
F_55 ( V_33 ) ;
if ( ! F_59 ( V_33 ) )
F_69 ( V_33 ) ;
}
F_47 ( V_33 ) ;
if ( V_33 -> V_7 == V_68 )
F_70 ( V_33 , V_69 , 0 ) ;
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
if ( V_2 && V_2 -> V_60 && V_2 -> V_60 -> V_70 )
error = V_2 -> V_60 -> V_70 ( V_34 ) ;
return error ;
}
static int F_72 ( struct V_4 * V_34 )
{
struct V_33 * V_33 = F_30 ( V_34 ) ;
const struct V_64 * V_60 = V_34 -> V_20 ? V_34 -> V_20 -> V_60 : NULL ;
int error = 0 ;
if ( V_33 -> V_53 )
F_40 ( V_33 ) ;
if ( F_63 ( V_33 ) )
return F_57 ( V_34 ) ;
F_58 ( V_33 ) ;
if ( V_60 ) {
if ( V_60 -> V_58 )
error = V_60 -> V_58 ( V_34 ) ;
} else {
F_48 ( V_33 ) ;
}
return error ;
}
static int F_73 ( struct V_4 * V_34 )
{
struct V_33 * V_33 = F_30 ( V_34 ) ;
const struct V_64 * V_60 = V_34 -> V_20 ? V_34 -> V_20 -> V_60 : NULL ;
if ( F_63 ( V_33 ) )
return F_51 ( V_34 , V_71 ) ;
if ( ! V_60 ) {
F_61 ( V_33 ) ;
return 0 ;
}
if ( V_60 -> V_72 ) {
int error ;
error = V_60 -> V_72 ( V_34 ) ;
F_52 ( V_60 -> V_72 , error ) ;
if ( error )
return error ;
}
return 0 ;
}
static int F_74 ( struct V_4 * V_34 )
{
struct V_33 * V_33 = F_30 ( V_34 ) ;
struct V_22 * V_2 = V_34 -> V_20 ;
if ( F_63 ( V_33 ) )
return F_54 ( V_34 , V_71 ) ;
if ( V_2 && V_2 -> V_60 && V_2 -> V_60 -> V_73 ) {
int error ;
error = V_2 -> V_60 -> V_73 ( V_34 ) ;
F_52 ( V_2 -> V_60 -> V_73 , error ) ;
if ( error )
return error ;
}
if ( ! V_33 -> V_53 )
F_55 ( V_33 ) ;
F_47 ( V_33 ) ;
return 0 ;
}
static int F_75 ( struct V_4 * V_34 )
{
struct V_33 * V_33 = F_30 ( V_34 ) ;
struct V_22 * V_2 = V_34 -> V_20 ;
int error = 0 ;
if ( F_63 ( V_33 ) )
return F_56 ( V_34 ) ;
F_41 ( V_33 , V_45 ) ;
if ( V_2 && V_2 -> V_60 && V_2 -> V_60 -> V_74 )
error = V_2 -> V_60 -> V_74 ( V_34 ) ;
return error ;
}
static int F_76 ( struct V_4 * V_34 )
{
struct V_33 * V_33 = F_30 ( V_34 ) ;
const struct V_64 * V_60 = V_34 -> V_20 ? V_34 -> V_20 -> V_60 : NULL ;
int error = 0 ;
if ( F_63 ( V_33 ) )
return F_57 ( V_34 ) ;
if ( V_60 ) {
if ( V_60 -> V_75 )
error = V_60 -> V_75 ( V_34 ) ;
} else {
F_48 ( V_33 ) ;
}
V_33 -> V_53 = false ;
return error ;
}
static int F_77 ( struct V_4 * V_34 )
{
struct V_33 * V_33 = F_30 ( V_34 ) ;
const struct V_64 * V_60 = V_34 -> V_20 ? V_34 -> V_20 -> V_60 : NULL ;
if ( F_63 ( V_33 ) )
return F_51 ( V_34 , V_76 ) ;
if ( ! V_60 ) {
F_61 ( V_33 ) ;
goto V_66;
}
if ( V_60 -> V_77 ) {
int error ;
error = V_60 -> V_77 ( V_34 ) ;
F_52 ( V_60 -> V_77 , error ) ;
if ( error )
return error ;
}
V_66:
F_46 ( V_54 , V_33 ) ;
return 0 ;
}
static int F_78 ( struct V_4 * V_34 )
{
struct V_33 * V_33 = F_30 ( V_34 ) ;
struct V_22 * V_2 = V_34 -> V_20 ;
if ( F_63 ( F_30 ( V_34 ) ) )
return F_54 ( V_34 , V_76 ) ;
if ( ! V_2 || ! V_2 -> V_60 )
return 0 ;
if ( V_2 -> V_60 -> V_78 ) {
int error ;
error = V_2 -> V_60 -> V_78 ( V_34 ) ;
F_52 ( V_2 -> V_60 -> V_78 , error ) ;
if ( error )
return error ;
}
if ( ! V_33 -> V_53 && ! F_59 ( V_33 ) )
F_69 ( V_33 ) ;
if ( V_33 -> V_7 == V_68 )
F_70 ( V_33 , V_69 , 0 ) ;
return 0 ;
}
static int F_79 ( struct V_4 * V_34 )
{
struct V_33 * V_33 = F_30 ( V_34 ) ;
struct V_22 * V_2 = V_34 -> V_20 ;
int error = 0 ;
F_44 ( V_33 ) ;
if ( F_63 ( V_33 ) )
return F_56 ( V_34 ) ;
if ( V_2 && V_2 -> V_60 && V_2 -> V_60 -> V_79 )
error = V_2 -> V_60 -> V_79 ( V_34 ) ;
return error ;
}
static int F_80 ( struct V_4 * V_34 )
{
struct V_33 * V_33 = F_30 ( V_34 ) ;
const struct V_64 * V_60 = V_34 -> V_20 ? V_34 -> V_20 -> V_60 : NULL ;
int error = 0 ;
if ( V_33 -> V_53 )
F_40 ( V_33 ) ;
if ( F_63 ( V_33 ) )
return F_57 ( V_34 ) ;
F_58 ( V_33 ) ;
if ( V_60 ) {
if ( V_60 -> V_80 )
error = V_60 -> V_80 ( V_34 ) ;
} else {
F_48 ( V_33 ) ;
}
return error ;
}
static int F_81 ( struct V_4 * V_34 )
{
struct V_33 * V_33 = F_30 ( V_34 ) ;
const struct V_64 * V_60 = V_34 -> V_20 ? V_34 -> V_20 -> V_60 : NULL ;
T_5 V_52 = V_33 -> V_44 ;
int error ;
if ( ! V_33 -> V_20 )
return 0 ;
if ( ! V_60 || ! V_60 -> V_81 )
return - V_82 ;
V_33 -> V_83 = false ;
error = V_60 -> V_81 ( V_34 ) ;
F_52 ( V_60 -> V_81 , error ) ;
if ( error )
return error ;
if ( ! V_33 -> V_84 )
V_33 -> V_83 = true ;
F_46 ( V_54 , V_33 ) ;
if ( ! V_33 -> V_53 && V_33 -> V_44 != V_45
&& V_33 -> V_44 != V_46 ) {
F_53 ( V_33 -> V_44 != V_52 ,
L_5 ,
V_60 -> V_81 ) ;
return 0 ;
}
if ( ! V_33 -> V_53 ) {
F_55 ( V_33 ) ;
F_82 ( V_33 ) ;
}
return 0 ;
}
static int F_83 ( struct V_4 * V_34 )
{
int V_39 ;
struct V_33 * V_33 = F_30 ( V_34 ) ;
const struct V_64 * V_60 = V_34 -> V_20 ? V_34 -> V_20 -> V_60 : NULL ;
if ( ! V_33 -> V_20 )
return 0 ;
if ( ! V_60 || ! V_60 -> V_85 )
return - V_82 ;
F_40 ( V_33 ) ;
F_46 ( V_48 , V_33 ) ;
F_84 ( V_33 , V_45 , true , false ) ;
F_46 ( V_57 , V_33 ) ;
V_39 = V_60 -> V_85 ( V_34 ) ;
V_33 -> V_86 = false ;
return V_39 ;
}
static int F_85 ( struct V_4 * V_34 )
{
struct V_33 * V_33 = F_30 ( V_34 ) ;
const struct V_64 * V_60 = V_34 -> V_20 ? V_34 -> V_20 -> V_60 : NULL ;
if ( ! V_33 -> V_20 )
goto V_87;
if ( ! V_60 )
return - V_82 ;
if ( V_60 -> V_88 ) {
int V_59 = V_60 -> V_88 ( V_34 ) ;
if ( V_59 )
return V_59 ;
}
V_87:
F_86 ( V_34 ) ;
return 0 ;
}
int F_87 ( struct V_1 * V_2 , struct V_89 * V_90 ,
const char * V_91 )
{
V_2 -> V_20 . V_61 = V_2 -> V_61 ;
V_2 -> V_20 . V_92 = & V_93 ;
V_2 -> V_20 . V_90 = V_90 ;
V_2 -> V_20 . V_91 = V_91 ;
F_88 ( & V_2 -> V_16 . V_17 ) ;
F_89 ( & V_2 -> V_16 . V_19 ) ;
return F_90 ( & V_2 -> V_20 ) ;
}
void
F_91 ( struct V_1 * V_2 )
{
F_92 ( & V_2 -> V_20 ) ;
F_7 ( V_2 ) ;
}
struct V_1 *
F_93 ( const struct V_33 * V_34 )
{
if ( V_34 -> V_20 )
return V_34 -> V_20 ;
else {
int V_94 ;
for( V_94 = 0 ; V_94 <= V_95 ; V_94 ++ )
if ( V_34 -> V_96 [ V_94 ] . V_97 & V_98 )
return & V_99 ;
}
return NULL ;
}
static int F_94 ( struct V_4 * V_34 , struct V_22 * V_2 )
{
struct V_33 * V_33 = F_30 ( V_34 ) ;
struct V_1 * V_38 = F_12 ( V_2 ) ;
const struct V_26 * V_100 ;
V_100 = F_16 ( V_38 , V_33 ) ;
if ( V_100 )
return 1 ;
return 0 ;
}
struct V_33 * F_31 ( struct V_33 * V_34 )
{
if ( V_34 )
F_95 ( & V_34 -> V_34 ) ;
return V_34 ;
}
void F_32 ( struct V_33 * V_34 )
{
if ( V_34 )
F_96 ( & V_34 -> V_34 ) ;
}
static int F_97 ( struct V_4 * V_34 , struct V_101 * V_102 )
{
struct V_33 * V_103 ;
if ( ! V_34 )
return - V_32 ;
V_103 = F_30 ( V_34 ) ;
if ( ! V_103 )
return - V_32 ;
if ( F_98 ( V_102 , L_6 , V_103 -> V_7 ) )
return - V_14 ;
if ( F_98 ( V_102 , L_7 , V_103 -> V_3 , V_103 -> V_4 ) )
return - V_14 ;
if ( F_98 ( V_102 , L_8 , V_103 -> V_104 ,
V_103 -> V_105 ) )
return - V_14 ;
if ( F_98 ( V_102 , L_9 , F_99 ( V_103 ) ) )
return - V_14 ;
if ( F_98 ( V_102 , L_10 ,
V_103 -> V_3 , V_103 -> V_4 ,
V_103 -> V_104 , V_103 -> V_105 ,
( V_106 ) ( V_103 -> V_7 >> 16 ) , ( V_106 ) ( V_103 -> V_7 >> 8 ) ,
( V_106 ) ( V_103 -> V_7 ) ) )
return - V_14 ;
return 0 ;
}
static int T_6 F_100 ( void )
{
return F_101 ( & V_93 ) ;
}
