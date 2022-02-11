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
if ( ! V_39 )
return V_39 ;
if ( V_39 < 0 ) {
V_33 -> V_20 = NULL ;
F_20 ( V_34 ) ;
return V_39 ;
}
F_21 ( V_34 , L_3 , V_39 ) ;
return 0 ;
}
static int F_22 ( struct V_1 * V_2 , struct V_33 * V_34 ,
const struct V_26 * V_15 )
{
int error , V_18 ;
struct V_36 V_37 = { V_2 , V_34 , V_15 } ;
V_18 = F_23 ( & V_34 -> V_34 ) ;
if ( V_18 >= 0 && V_18 != F_24 () ) {
int V_41 ;
F_25 () ;
V_41 = F_26 ( F_27 ( V_18 ) , V_42 ) ;
if ( V_41 < V_43 )
error = F_28 ( V_41 , F_18 , & V_37 ) ;
else
error = F_18 ( & V_37 ) ;
F_29 () ;
} else
error = F_18 ( & V_37 ) ;
return error ;
}
static int
F_30 ( struct V_1 * V_2 , struct V_33 * V_33 )
{
const struct V_26 * V_15 ;
int error = 0 ;
if ( ! V_33 -> V_20 && V_2 -> V_40 ) {
error = - V_32 ;
V_15 = F_16 ( V_2 , V_33 ) ;
if ( V_15 )
error = F_22 ( V_2 , V_33 , V_15 ) ;
if ( error >= 0 )
error = 0 ;
}
return error ;
}
static int F_31 ( struct V_4 * V_34 )
{
int error = 0 ;
struct V_1 * V_2 ;
struct V_33 * V_33 ;
V_2 = F_12 ( V_34 -> V_20 ) ;
V_33 = F_32 ( V_34 ) ;
F_33 ( V_33 ) ;
error = F_30 ( V_2 , V_33 ) ;
if ( error )
F_34 ( V_33 ) ;
return error ;
}
static int F_35 ( struct V_4 * V_34 )
{
struct V_33 * V_33 = F_32 ( V_34 ) ;
struct V_1 * V_2 = V_33 -> V_20 ;
if ( V_2 ) {
if ( V_2 -> remove ) {
F_19 ( V_34 ) ;
V_2 -> remove ( V_33 ) ;
F_36 ( V_34 ) ;
}
V_33 -> V_20 = NULL ;
}
F_20 ( V_34 ) ;
if ( V_33 -> V_44 == V_45 )
V_33 -> V_44 = V_46 ;
F_34 ( V_33 ) ;
return 0 ;
}
static void F_37 ( struct V_4 * V_34 )
{
struct V_33 * V_33 = F_32 ( V_34 ) ;
struct V_1 * V_2 = V_33 -> V_20 ;
F_38 ( V_34 ) ;
if ( V_2 && V_2 -> V_47 )
V_2 -> V_47 ( V_33 ) ;
F_39 ( V_33 ) ;
F_40 ( V_33 ) ;
#ifdef F_41
if ( V_48 && ( V_33 -> V_44 <= V_49 ) )
F_42 ( V_33 ) ;
#endif
}
static int F_43 ( struct V_33 * V_33 )
{
F_44 ( V_33 , V_46 ) ;
if ( V_33 -> V_44 != V_45 ) {
int error = F_45 ( V_33 , V_45 ) ;
if ( error )
return error ;
}
F_46 ( V_33 ) ;
return 0 ;
}
static void F_47 ( struct V_33 * V_33 )
{
F_48 ( V_33 ) ;
F_46 ( V_33 ) ;
F_49 ( V_50 , V_33 ) ;
}
static void F_50 ( struct V_33 * V_33 )
{
if ( V_33 -> V_44 == V_45 )
V_33 -> V_44 = V_46 ;
}
static int F_51 ( struct V_33 * V_33 )
{
int V_12 ;
V_12 = F_52 ( V_33 ) ;
if ( V_33 -> V_51 )
F_53 ( V_33 ) ;
return V_12 ;
}
static int F_54 ( struct V_4 * V_34 , T_4 V_52 )
{
struct V_33 * V_33 = F_32 ( V_34 ) ;
struct V_1 * V_2 = V_33 -> V_20 ;
if ( V_2 && V_2 -> V_53 ) {
T_5 V_54 = V_33 -> V_44 ;
int error ;
error = V_2 -> V_53 ( V_33 , V_52 ) ;
F_55 ( V_2 -> V_53 , error ) ;
if ( error )
return error ;
if ( ! V_33 -> V_55 && V_33 -> V_44 != V_45
&& V_33 -> V_44 != V_46 ) {
F_56 ( V_33 -> V_44 != V_54 ,
L_4 ,
V_2 -> V_53 ) ;
}
}
F_49 ( V_56 , V_33 ) ;
return 0 ;
}
static int F_57 ( struct V_4 * V_34 , T_4 V_52 )
{
struct V_33 * V_33 = F_32 ( V_34 ) ;
struct V_1 * V_2 = V_33 -> V_20 ;
if ( V_2 && V_2 -> V_57 ) {
T_5 V_54 = V_33 -> V_44 ;
int error ;
error = V_2 -> V_57 ( V_33 , V_52 ) ;
F_55 ( V_2 -> V_57 , error ) ;
if ( error )
return error ;
if ( ! V_33 -> V_55 && V_33 -> V_44 != V_45
&& V_33 -> V_44 != V_46 ) {
F_56 ( V_33 -> V_44 != V_54 ,
L_4 ,
V_2 -> V_57 ) ;
return 0 ;
}
}
if ( ! V_33 -> V_55 )
F_58 ( V_33 ) ;
F_50 ( V_33 ) ;
return 0 ;
}
static int F_59 ( struct V_4 * V_34 )
{
struct V_33 * V_33 = F_32 ( V_34 ) ;
struct V_1 * V_2 = V_33 -> V_20 ;
return V_2 && V_2 -> V_58 ?
V_2 -> V_58 ( V_33 ) : 0 ;
}
static int F_60 ( struct V_4 * V_34 )
{
struct V_33 * V_33 = F_32 ( V_34 ) ;
struct V_1 * V_2 = V_33 -> V_20 ;
F_49 ( V_59 , V_33 ) ;
return V_2 && V_2 -> V_60 ?
V_2 -> V_60 ( V_33 ) : F_51 ( V_33 ) ;
}
static void F_61 ( struct V_33 * V_33 )
{
F_49 ( V_59 , V_33 ) ;
if ( ! F_62 ( V_33 ) )
F_63 ( V_33 , V_45 , false ) ;
}
static void F_64 ( struct V_33 * V_33 )
{
if ( ! F_62 ( V_33 ) )
F_65 ( V_33 ) ;
}
static bool F_66 ( struct V_33 * V_33 )
{
struct V_1 * V_2 = V_33 -> V_20 ;
bool V_61 = V_2 && ( V_2 -> V_53 || V_2 -> V_57 || V_2 -> V_60
|| V_2 -> V_58 ) ;
F_67 ( V_61 && V_2 -> V_20 . V_62 , L_5 ,
V_2 -> V_63 , V_33 -> V_3 , V_33 -> V_4 ) ;
return V_61 ;
}
static int F_68 ( struct V_4 * V_34 )
{
struct V_22 * V_2 = V_34 -> V_20 ;
int error = 0 ;
if ( V_34 -> V_64 . V_65 )
F_38 ( V_34 ) ;
if ( V_2 && V_2 -> V_62 && V_2 -> V_62 -> V_66 )
error = V_2 -> V_62 -> V_66 ( V_34 ) ;
return error ;
}
static int F_69 ( struct V_4 * V_34 )
{
struct V_33 * V_33 = F_32 ( V_34 ) ;
const struct V_67 * V_62 = V_34 -> V_20 ? V_34 -> V_20 -> V_62 : NULL ;
if ( F_66 ( V_33 ) )
return F_54 ( V_34 , V_68 ) ;
if ( ! V_62 ) {
F_64 ( V_33 ) ;
goto V_69;
}
F_38 ( V_34 ) ;
V_33 -> V_55 = false ;
if ( V_62 -> V_53 ) {
T_5 V_54 = V_33 -> V_44 ;
int error ;
error = V_62 -> V_53 ( V_34 ) ;
F_55 ( V_62 -> V_53 , error ) ;
if ( error )
return error ;
if ( ! V_33 -> V_55 && V_33 -> V_44 != V_45
&& V_33 -> V_44 != V_46 ) {
F_56 ( V_33 -> V_44 != V_54 ,
L_6 ,
V_62 -> V_53 ) ;
}
}
V_69:
F_49 ( V_56 , V_33 ) ;
return 0 ;
}
static int F_70 ( struct V_4 * V_34 )
{
struct V_33 * V_33 = F_32 ( V_34 ) ;
const struct V_67 * V_62 = V_34 -> V_20 ? V_34 -> V_20 -> V_62 : NULL ;
if ( F_66 ( V_33 ) )
return F_57 ( V_34 , V_68 ) ;
if ( ! V_62 ) {
F_58 ( V_33 ) ;
return 0 ;
}
if ( V_62 -> V_70 ) {
T_5 V_54 = V_33 -> V_44 ;
int error ;
error = V_62 -> V_70 ( V_34 ) ;
F_55 ( V_62 -> V_70 , error ) ;
if ( error )
return error ;
if ( ! V_33 -> V_55 && V_33 -> V_44 != V_45
&& V_33 -> V_44 != V_46 ) {
F_56 ( V_33 -> V_44 != V_54 ,
L_6 ,
V_62 -> V_70 ) ;
return 0 ;
}
}
if ( ! V_33 -> V_55 ) {
F_58 ( V_33 ) ;
if ( ! F_62 ( V_33 ) )
F_71 ( V_33 ) ;
}
F_50 ( V_33 ) ;
if ( V_33 -> V_7 == V_71 )
F_72 ( V_33 , V_72 , 0 ) ;
return 0 ;
}
static int F_73 ( struct V_4 * V_34 )
{
struct V_33 * V_33 = F_32 ( V_34 ) ;
struct V_22 * V_2 = V_34 -> V_20 ;
int error = 0 ;
F_47 ( V_33 ) ;
if ( F_66 ( V_33 ) )
return F_59 ( V_34 ) ;
if ( V_2 && V_2 -> V_62 && V_2 -> V_62 -> V_73 )
error = V_2 -> V_62 -> V_73 ( V_34 ) ;
return error ;
}
static int F_74 ( struct V_4 * V_34 )
{
struct V_33 * V_33 = F_32 ( V_34 ) ;
const struct V_67 * V_62 = V_34 -> V_20 ? V_34 -> V_20 -> V_62 : NULL ;
int error = 0 ;
if ( V_33 -> V_55 )
F_43 ( V_33 ) ;
if ( F_66 ( V_33 ) )
return F_60 ( V_34 ) ;
F_61 ( V_33 ) ;
if ( V_62 ) {
if ( V_62 -> V_60 )
error = V_62 -> V_60 ( V_34 ) ;
} else {
F_51 ( V_33 ) ;
}
return error ;
}
static int F_75 ( struct V_4 * V_34 )
{
struct V_33 * V_33 = F_32 ( V_34 ) ;
const struct V_67 * V_62 = V_34 -> V_20 ? V_34 -> V_20 -> V_62 : NULL ;
if ( F_66 ( V_33 ) )
return F_54 ( V_34 , V_74 ) ;
if ( ! V_62 ) {
F_64 ( V_33 ) ;
return 0 ;
}
F_38 ( V_34 ) ;
V_33 -> V_55 = false ;
if ( V_62 -> V_75 ) {
int error ;
error = V_62 -> V_75 ( V_34 ) ;
F_55 ( V_62 -> V_75 , error ) ;
if ( error )
return error ;
}
if ( V_76 . V_75 )
return V_76 . V_75 ( V_34 ) ;
return 0 ;
}
static int F_76 ( struct V_4 * V_34 )
{
struct V_33 * V_33 = F_32 ( V_34 ) ;
struct V_22 * V_2 = V_34 -> V_20 ;
if ( F_66 ( V_33 ) )
return F_57 ( V_34 , V_74 ) ;
if ( V_2 && V_2 -> V_62 && V_2 -> V_62 -> V_77 ) {
int error ;
error = V_2 -> V_62 -> V_77 ( V_34 ) ;
F_55 ( V_2 -> V_62 -> V_77 , error ) ;
if ( error )
return error ;
}
if ( ! V_33 -> V_55 )
F_58 ( V_33 ) ;
F_50 ( V_33 ) ;
if ( V_76 . V_77 )
return V_76 . V_77 ( V_34 ) ;
return 0 ;
}
static int F_77 ( struct V_4 * V_34 )
{
struct V_33 * V_33 = F_32 ( V_34 ) ;
struct V_22 * V_2 = V_34 -> V_20 ;
int error = 0 ;
if ( V_76 . V_78 ) {
error = V_76 . V_78 ( V_34 ) ;
if ( error )
return error ;
}
if ( F_66 ( V_33 ) )
return F_59 ( V_34 ) ;
F_44 ( V_33 , V_45 ) ;
if ( V_2 && V_2 -> V_62 && V_2 -> V_62 -> V_78 )
error = V_2 -> V_62 -> V_78 ( V_34 ) ;
return error ;
}
static int F_78 ( struct V_4 * V_34 )
{
struct V_33 * V_33 = F_32 ( V_34 ) ;
const struct V_67 * V_62 = V_34 -> V_20 ? V_34 -> V_20 -> V_62 : NULL ;
int error = 0 ;
if ( V_76 . V_79 ) {
error = V_76 . V_79 ( V_34 ) ;
if ( error )
return error ;
}
if ( F_66 ( V_33 ) )
return F_60 ( V_34 ) ;
if ( V_62 ) {
if ( V_62 -> V_79 )
error = V_62 -> V_79 ( V_34 ) ;
} else {
F_51 ( V_33 ) ;
}
V_33 -> V_55 = false ;
return error ;
}
static int F_79 ( struct V_4 * V_34 )
{
struct V_33 * V_33 = F_32 ( V_34 ) ;
const struct V_67 * V_62 = V_34 -> V_20 ? V_34 -> V_20 -> V_62 : NULL ;
if ( F_66 ( V_33 ) )
return F_54 ( V_34 , V_80 ) ;
if ( ! V_62 ) {
F_64 ( V_33 ) ;
goto V_69;
}
F_38 ( V_34 ) ;
V_33 -> V_55 = false ;
if ( V_62 -> V_81 ) {
int error ;
error = V_62 -> V_81 ( V_34 ) ;
F_55 ( V_62 -> V_81 , error ) ;
if ( error )
return error ;
}
V_69:
F_49 ( V_56 , V_33 ) ;
if ( V_76 . V_81 )
return V_76 . V_81 ( V_34 ) ;
return 0 ;
}
static int F_80 ( struct V_4 * V_34 )
{
struct V_33 * V_33 = F_32 ( V_34 ) ;
struct V_22 * V_2 = V_34 -> V_20 ;
if ( F_66 ( F_32 ( V_34 ) ) )
return F_57 ( V_34 , V_80 ) ;
if ( ! V_2 || ! V_2 -> V_62 )
return 0 ;
if ( V_2 -> V_62 -> V_82 ) {
int error ;
error = V_2 -> V_62 -> V_82 ( V_34 ) ;
F_55 ( V_2 -> V_62 -> V_82 , error ) ;
if ( error )
return error ;
}
if ( ! V_33 -> V_55 && ! F_62 ( V_33 ) )
F_71 ( V_33 ) ;
if ( V_33 -> V_7 == V_71 )
F_72 ( V_33 , V_72 , 0 ) ;
if ( V_76 . V_82 )
return V_76 . V_82 ( V_34 ) ;
return 0 ;
}
static int F_81 ( struct V_4 * V_34 )
{
struct V_33 * V_33 = F_32 ( V_34 ) ;
struct V_22 * V_2 = V_34 -> V_20 ;
int error = 0 ;
if ( V_76 . V_83 ) {
error = V_76 . V_83 ( V_34 ) ;
if ( error )
return error ;
}
F_47 ( V_33 ) ;
if ( F_66 ( V_33 ) )
return F_59 ( V_34 ) ;
if ( V_2 && V_2 -> V_62 && V_2 -> V_62 -> V_83 )
error = V_2 -> V_62 -> V_83 ( V_34 ) ;
return error ;
}
static int F_82 ( struct V_4 * V_34 )
{
struct V_33 * V_33 = F_32 ( V_34 ) ;
const struct V_67 * V_62 = V_34 -> V_20 ? V_34 -> V_20 -> V_62 : NULL ;
int error = 0 ;
if ( V_76 . V_84 ) {
error = V_76 . V_84 ( V_34 ) ;
if ( error )
return error ;
}
if ( V_33 -> V_55 )
F_43 ( V_33 ) ;
if ( F_66 ( V_33 ) )
return F_60 ( V_34 ) ;
F_61 ( V_33 ) ;
if ( V_62 ) {
if ( V_62 -> V_84 )
error = V_62 -> V_84 ( V_34 ) ;
} else {
F_51 ( V_33 ) ;
}
return error ;
}
static int F_83 ( struct V_4 * V_34 )
{
struct V_33 * V_33 = F_32 ( V_34 ) ;
const struct V_67 * V_62 = V_34 -> V_20 ? V_34 -> V_20 -> V_62 : NULL ;
T_5 V_54 = V_33 -> V_44 ;
int error ;
if ( ! V_33 -> V_20 )
return 0 ;
if ( ! V_62 || ! V_62 -> V_85 )
return - V_86 ;
V_33 -> V_55 = false ;
V_33 -> V_87 = false ;
error = V_62 -> V_85 ( V_34 ) ;
F_55 ( V_62 -> V_85 , error ) ;
if ( error )
return error ;
if ( ! V_33 -> V_88 )
V_33 -> V_87 = true ;
F_49 ( V_56 , V_33 ) ;
if ( ! V_33 -> V_55 && V_33 -> V_44 != V_45
&& V_33 -> V_44 != V_46 ) {
F_56 ( V_33 -> V_44 != V_54 ,
L_6 ,
V_62 -> V_85 ) ;
return 0 ;
}
if ( ! V_33 -> V_55 ) {
F_58 ( V_33 ) ;
F_84 ( V_33 ) ;
}
return 0 ;
}
static int F_85 ( struct V_4 * V_34 )
{
int V_39 ;
struct V_33 * V_33 = F_32 ( V_34 ) ;
const struct V_67 * V_62 = V_34 -> V_20 ? V_34 -> V_20 -> V_62 : NULL ;
if ( ! V_33 -> V_20 )
return 0 ;
if ( ! V_62 || ! V_62 -> V_89 )
return - V_86 ;
F_43 ( V_33 ) ;
F_49 ( V_50 , V_33 ) ;
F_86 ( V_33 , V_45 , true , false ) ;
F_49 ( V_59 , V_33 ) ;
V_39 = V_62 -> V_89 ( V_34 ) ;
V_33 -> V_90 = false ;
return V_39 ;
}
static int F_87 ( struct V_4 * V_34 )
{
struct V_33 * V_33 = F_32 ( V_34 ) ;
const struct V_67 * V_62 = V_34 -> V_20 ? V_34 -> V_20 -> V_62 : NULL ;
int V_61 = 0 ;
if ( ! V_33 -> V_20 )
return 0 ;
if ( ! V_62 )
return - V_86 ;
if ( V_62 -> V_91 )
V_61 = V_62 -> V_91 ( V_34 ) ;
return V_61 ;
}
int F_88 ( struct V_1 * V_2 , struct V_92 * V_93 ,
const char * V_94 )
{
V_2 -> V_20 . V_63 = V_2 -> V_63 ;
V_2 -> V_20 . V_95 = & V_96 ;
V_2 -> V_20 . V_93 = V_93 ;
V_2 -> V_20 . V_94 = V_94 ;
F_89 ( & V_2 -> V_16 . V_17 ) ;
F_90 ( & V_2 -> V_16 . V_19 ) ;
return F_91 ( & V_2 -> V_20 ) ;
}
void
F_92 ( struct V_1 * V_2 )
{
F_93 ( & V_2 -> V_20 ) ;
F_7 ( V_2 ) ;
}
struct V_1 *
F_94 ( const struct V_33 * V_34 )
{
if ( V_34 -> V_20 )
return V_34 -> V_20 ;
else {
int V_97 ;
for( V_97 = 0 ; V_97 <= V_98 ; V_97 ++ )
if ( V_34 -> V_99 [ V_97 ] . V_100 & V_101 )
return & V_102 ;
}
return NULL ;
}
static int F_95 ( struct V_4 * V_34 , struct V_22 * V_2 )
{
struct V_33 * V_33 = F_32 ( V_34 ) ;
struct V_1 * V_38 ;
const struct V_26 * V_103 ;
if ( ! V_33 -> V_104 )
return 0 ;
V_38 = F_12 ( V_2 ) ;
V_103 = F_16 ( V_38 , V_33 ) ;
if ( V_103 )
return 1 ;
return 0 ;
}
struct V_33 * F_33 ( struct V_33 * V_34 )
{
if ( V_34 )
F_96 ( & V_34 -> V_34 ) ;
return V_34 ;
}
void F_34 ( struct V_33 * V_34 )
{
if ( V_34 )
F_97 ( & V_34 -> V_34 ) ;
}
static int F_98 ( struct V_4 * V_34 , struct V_105 * V_106 )
{
struct V_33 * V_107 ;
if ( ! V_34 )
return - V_32 ;
V_107 = F_32 ( V_34 ) ;
if ( ! V_107 )
return - V_32 ;
if ( F_99 ( V_106 , L_7 , V_107 -> V_7 ) )
return - V_14 ;
if ( F_99 ( V_106 , L_8 , V_107 -> V_3 , V_107 -> V_4 ) )
return - V_14 ;
if ( F_99 ( V_106 , L_9 , V_107 -> V_108 ,
V_107 -> V_109 ) )
return - V_14 ;
if ( F_99 ( V_106 , L_10 , F_100 ( V_107 ) ) )
return - V_14 ;
if ( F_99 ( V_106 , L_11 ,
V_107 -> V_3 , V_107 -> V_4 ,
V_107 -> V_108 , V_107 -> V_109 ,
( V_110 ) ( V_107 -> V_7 >> 16 ) , ( V_110 ) ( V_107 -> V_7 >> 8 ) ,
( V_110 ) ( V_107 -> V_7 ) ) )
return - V_14 ;
return 0 ;
}
static int T_6 F_101 ( void )
{
return F_102 ( & V_96 ) ;
}
