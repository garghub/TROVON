int F_1 ( struct V_1 * V_2 ,
unsigned int V_3 , unsigned int V_4 ,
unsigned int V_5 , unsigned int V_6 ,
unsigned int V_7 , unsigned int V_8 ,
unsigned long V_9 )
{
struct V_10 * V_11 ;
V_11 = F_2 ( sizeof( * V_11 ) , V_12 ) ;
if ( ! V_11 )
return - V_13 ;
V_11 -> V_14 . V_3 = V_3 ;
V_11 -> V_14 . V_4 = V_4 ;
V_11 -> V_14 . V_5 = V_5 ;
V_11 -> V_14 . V_6 = V_6 ;
V_11 -> V_14 . V_7 = V_7 ;
V_11 -> V_14 . V_8 = V_8 ;
V_11 -> V_14 . V_9 = V_9 ;
F_3 ( & V_2 -> V_15 . V_16 ) ;
F_4 ( & V_11 -> V_17 , & V_2 -> V_15 . V_18 ) ;
F_5 ( & V_2 -> V_15 . V_16 ) ;
return F_6 ( & V_2 -> V_19 ) ;
}
static void F_7 ( struct V_1 * V_2 )
{
struct V_10 * V_11 , * V_20 ;
F_3 ( & V_2 -> V_15 . V_16 ) ;
F_8 (dynid, n, &drv->dynids.list, node) {
F_9 ( & V_11 -> V_17 ) ;
F_10 ( V_11 ) ;
}
F_5 ( & V_2 -> V_15 . V_16 ) ;
}
static T_1 F_11 ( struct V_21 * V_19 , const char * V_22 ,
T_2 V_23 )
{
struct V_1 * V_24 = F_12 ( V_19 ) ;
const struct V_25 * V_26 = V_24 -> V_27 ;
T_3 V_3 , V_4 , V_5 = V_28 ,
V_6 = V_28 , V_7 = 0 , V_8 = 0 ;
unsigned long V_9 = 0 ;
int V_29 = 0 ;
int V_30 = 0 ;
V_29 = sscanf ( V_22 , L_1 ,
& V_3 , & V_4 , & V_5 , & V_6 ,
& V_7 , & V_8 , & V_9 ) ;
if ( V_29 < 2 )
return - V_31 ;
if ( V_29 != 7 ) {
struct V_32 * V_33 = F_2 ( sizeof( * V_33 ) , V_12 ) ;
if ( ! V_33 )
return - V_13 ;
V_33 -> V_3 = V_3 ;
V_33 -> V_4 = V_4 ;
V_33 -> V_34 = V_5 ;
V_33 -> V_35 = V_6 ;
V_33 -> V_7 = V_7 ;
if ( F_13 ( V_24 -> V_27 , V_33 ) )
V_30 = - V_36 ;
F_10 ( V_33 ) ;
if ( V_30 )
return V_30 ;
}
if ( V_26 ) {
V_30 = - V_31 ;
while ( V_26 -> V_3 || V_26 -> V_5 || V_26 -> V_8 ) {
if ( V_9 == V_26 -> V_9 ) {
V_30 = 0 ;
break;
}
V_26 ++ ;
}
if ( V_30 )
return V_30 ;
}
V_30 = F_1 ( V_24 , V_3 , V_4 , V_5 , V_6 ,
V_7 , V_8 , V_9 ) ;
if ( V_30 )
return V_30 ;
return V_23 ;
}
static T_1 F_14 ( struct V_21 * V_19 , const char * V_22 ,
T_2 V_23 )
{
struct V_10 * V_11 , * V_20 ;
struct V_1 * V_24 = F_12 ( V_19 ) ;
T_3 V_3 , V_4 , V_5 = V_28 ,
V_6 = V_28 , V_7 = 0 , V_8 = 0 ;
int V_29 = 0 ;
T_2 V_30 = - V_37 ;
V_29 = sscanf ( V_22 , L_2 ,
& V_3 , & V_4 , & V_5 , & V_6 ,
& V_7 , & V_8 ) ;
if ( V_29 < 2 )
return - V_31 ;
F_3 ( & V_24 -> V_15 . V_16 ) ;
F_8 (dynid, n, &pdrv->dynids.list, node) {
struct V_25 * V_14 = & V_11 -> V_14 ;
if ( ( V_14 -> V_3 == V_3 ) &&
( V_14 -> V_4 == V_4 ) &&
( V_5 == V_28 || V_14 -> V_5 == V_5 ) &&
( V_6 == V_28 || V_14 -> V_6 == V_6 ) &&
! ( ( V_14 -> V_7 ^ V_7 ) & V_8 ) ) {
F_9 ( & V_11 -> V_17 ) ;
F_10 ( V_11 ) ;
V_30 = V_23 ;
break;
}
}
F_5 ( & V_24 -> V_15 . V_16 ) ;
return V_30 ;
}
const struct V_25 * F_13 ( const struct V_25 * V_26 ,
struct V_32 * V_38 )
{
if ( V_26 ) {
while ( V_26 -> V_3 || V_26 -> V_5 || V_26 -> V_8 ) {
if ( F_15 ( V_26 , V_38 ) )
return V_26 ;
V_26 ++ ;
}
}
return NULL ;
}
static const struct V_25 * F_16 ( struct V_1 * V_2 ,
struct V_32 * V_38 )
{
struct V_10 * V_11 ;
const struct V_25 * V_39 = NULL ;
if ( V_38 -> V_40 && strcmp ( V_38 -> V_40 , V_2 -> V_41 ) )
return NULL ;
F_3 ( & V_2 -> V_15 . V_16 ) ;
F_17 (dynid, &drv->dynids.list, node) {
if ( F_15 ( & V_11 -> V_14 , V_38 ) ) {
V_39 = & V_11 -> V_14 ;
break;
}
}
F_5 ( & V_2 -> V_15 . V_16 ) ;
if ( ! V_39 )
V_39 = F_13 ( V_2 -> V_27 , V_38 ) ;
if ( ! V_39 && V_38 -> V_40 )
V_39 = & V_42 ;
return V_39 ;
}
static long F_18 ( void * V_43 )
{
struct V_44 * V_45 = V_43 ;
struct V_32 * V_32 = V_45 -> V_38 ;
struct V_1 * V_46 = V_45 -> V_2 ;
struct V_4 * V_38 = & V_32 -> V_38 ;
int V_47 ;
F_19 ( V_38 ) ;
V_32 -> V_19 = V_46 ;
V_47 = V_46 -> V_48 ( V_32 , V_45 -> V_14 ) ;
if ( ! V_47 )
return V_47 ;
if ( V_47 < 0 ) {
V_32 -> V_19 = NULL ;
F_20 ( V_38 ) ;
return V_47 ;
}
F_21 ( V_38 , L_3 , V_47 ) ;
return 0 ;
}
static int F_22 ( struct V_1 * V_2 , struct V_32 * V_38 ,
const struct V_25 * V_14 )
{
int error , V_17 ;
struct V_44 V_45 = { V_2 , V_38 , V_14 } ;
V_17 = F_23 ( & V_38 -> V_38 ) ;
if ( V_17 >= 0 && V_17 != F_24 () ) {
int V_49 ;
F_25 () ;
V_49 = F_26 ( F_27 ( V_17 ) , V_50 ) ;
if ( V_49 < V_51 )
error = F_28 ( V_49 , F_18 , & V_45 ) ;
else
error = F_18 ( & V_45 ) ;
F_29 () ;
} else
error = F_18 ( & V_45 ) ;
return error ;
}
static int F_30 ( struct V_1 * V_2 , struct V_32 * V_32 )
{
const struct V_25 * V_14 ;
int error = 0 ;
if ( ! V_32 -> V_19 && V_2 -> V_48 ) {
error = - V_37 ;
V_14 = F_16 ( V_2 , V_32 ) ;
if ( V_14 )
error = F_22 ( V_2 , V_32 , V_14 ) ;
}
return error ;
}
int __weak F_31 ( struct V_32 * V_38 )
{
return 0 ;
}
void __weak F_32 ( struct V_32 * V_38 )
{
}
static inline bool F_33 ( struct V_32 * V_33 )
{
return ( ! V_33 -> V_52 || V_33 -> V_53 -> V_54 -> V_55 ) ;
}
static inline bool F_33 ( struct V_32 * V_33 )
{
return true ;
}
static int F_34 ( struct V_4 * V_38 )
{
int error ;
struct V_32 * V_32 = F_35 ( V_38 ) ;
struct V_1 * V_2 = F_12 ( V_38 -> V_19 ) ;
error = F_31 ( V_32 ) ;
if ( error < 0 )
return error ;
F_36 ( V_32 ) ;
if ( F_33 ( V_32 ) ) {
error = F_30 ( V_2 , V_32 ) ;
if ( error ) {
F_32 ( V_32 ) ;
F_37 ( V_32 ) ;
}
}
return error ;
}
static int F_38 ( struct V_4 * V_38 )
{
struct V_32 * V_32 = F_35 ( V_38 ) ;
struct V_1 * V_2 = V_32 -> V_19 ;
if ( V_2 ) {
if ( V_2 -> remove ) {
F_19 ( V_38 ) ;
V_2 -> remove ( V_32 ) ;
F_39 ( V_38 ) ;
}
F_32 ( V_32 ) ;
V_32 -> V_19 = NULL ;
}
F_20 ( V_38 ) ;
if ( V_32 -> V_56 == V_57 )
V_32 -> V_56 = V_58 ;
F_37 ( V_32 ) ;
return 0 ;
}
static void F_40 ( struct V_4 * V_38 )
{
struct V_32 * V_32 = F_35 ( V_38 ) ;
struct V_1 * V_2 = V_32 -> V_19 ;
F_41 ( V_38 ) ;
if ( V_2 && V_2 -> V_59 )
V_2 -> V_59 ( V_32 ) ;
if ( V_60 && ( V_32 -> V_56 <= V_61 ) )
F_42 ( V_32 ) ;
}
static int F_43 ( struct V_32 * V_32 )
{
F_44 ( V_32 , V_58 ) ;
if ( V_32 -> V_56 != V_57 ) {
int error = F_45 ( V_32 , V_57 ) ;
if ( error )
return error ;
}
F_46 ( V_32 ) ;
return 0 ;
}
static void F_47 ( struct V_32 * V_32 )
{
F_48 ( V_32 ) ;
F_46 ( V_32 ) ;
F_49 ( V_62 , V_32 ) ;
}
static void F_50 ( struct V_32 * V_32 )
{
if ( V_32 -> V_56 == V_57 )
V_32 -> V_56 = V_58 ;
}
static int F_51 ( struct V_32 * V_32 )
{
int V_30 ;
V_30 = F_52 ( V_32 ) ;
if ( V_32 -> V_63 )
F_53 ( V_32 ) ;
return V_30 ;
}
static int F_54 ( struct V_4 * V_38 , T_4 V_64 )
{
struct V_32 * V_32 = F_35 ( V_38 ) ;
struct V_1 * V_2 = V_32 -> V_19 ;
if ( V_2 && V_2 -> V_65 ) {
T_5 V_66 = V_32 -> V_56 ;
int error ;
error = V_2 -> V_65 ( V_32 , V_64 ) ;
F_55 ( V_2 -> V_65 , error ) ;
if ( error )
return error ;
if ( ! V_32 -> V_67 && V_32 -> V_56 != V_57
&& V_32 -> V_56 != V_58 ) {
F_56 ( V_32 -> V_56 != V_66 ,
L_4 ,
V_2 -> V_65 ) ;
}
}
F_49 ( V_68 , V_32 ) ;
return 0 ;
}
static int F_57 ( struct V_4 * V_38 , T_4 V_64 )
{
struct V_32 * V_32 = F_35 ( V_38 ) ;
struct V_1 * V_2 = V_32 -> V_19 ;
if ( V_2 && V_2 -> V_69 ) {
T_5 V_66 = V_32 -> V_56 ;
int error ;
error = V_2 -> V_69 ( V_32 , V_64 ) ;
F_55 ( V_2 -> V_69 , error ) ;
if ( error )
return error ;
if ( ! V_32 -> V_67 && V_32 -> V_56 != V_57
&& V_32 -> V_56 != V_58 ) {
F_56 ( V_32 -> V_56 != V_66 ,
L_4 ,
V_2 -> V_69 ) ;
goto V_70;
}
}
if ( ! V_32 -> V_67 )
F_58 ( V_32 ) ;
F_50 ( V_32 ) ;
V_70:
F_49 ( V_71 , V_32 ) ;
return 0 ;
}
static int F_59 ( struct V_4 * V_38 )
{
struct V_32 * V_32 = F_35 ( V_38 ) ;
struct V_1 * V_2 = V_32 -> V_19 ;
return V_2 && V_2 -> V_72 ?
V_2 -> V_72 ( V_32 ) : 0 ;
}
static int F_60 ( struct V_4 * V_38 )
{
struct V_32 * V_32 = F_35 ( V_38 ) ;
struct V_1 * V_2 = V_32 -> V_19 ;
F_49 ( V_73 , V_32 ) ;
return V_2 && V_2 -> V_74 ?
V_2 -> V_74 ( V_32 ) : F_51 ( V_32 ) ;
}
static void F_61 ( struct V_32 * V_32 )
{
F_49 ( V_73 , V_32 ) ;
if ( ! F_62 ( V_32 ) )
F_63 ( V_32 , V_57 , false ) ;
}
static void F_64 ( struct V_32 * V_32 )
{
if ( ! F_62 ( V_32 ) )
F_65 ( V_32 ) ;
}
static bool F_66 ( struct V_32 * V_32 )
{
struct V_1 * V_2 = V_32 -> V_19 ;
bool V_75 = V_2 && ( V_2 -> V_65 || V_2 -> V_69 || V_2 -> V_74
|| V_2 -> V_72 ) ;
F_67 ( V_75 && V_2 -> V_19 . V_76 , L_5 ,
V_2 -> V_41 , V_32 -> V_3 , V_32 -> V_4 ) ;
return V_75 ;
}
static int F_68 ( struct V_4 * V_38 )
{
struct V_21 * V_2 = V_38 -> V_19 ;
if ( V_38 -> V_77 . V_78 )
F_41 ( V_38 ) ;
if ( V_2 && V_2 -> V_76 && V_2 -> V_76 -> V_79 ) {
int error = V_2 -> V_76 -> V_79 ( V_38 ) ;
if ( error )
return error ;
}
return F_69 ( F_35 ( V_38 ) ) ;
}
static void F_70 ( struct V_4 * V_38 )
{
struct V_32 * V_32 = F_35 ( V_38 ) ;
F_71 ( V_32 ) ;
F_72 ( V_38 ) ;
if ( V_38 -> V_77 . V_80 && F_73 () ) {
T_5 V_81 = V_32 -> V_56 ;
F_44 ( V_32 , V_32 -> V_56 ) ;
if ( V_32 -> V_56 < V_81 )
F_74 ( V_38 ) ;
}
}
static int F_75 ( struct V_4 * V_38 )
{
struct V_32 * V_32 = F_35 ( V_38 ) ;
const struct V_82 * V_76 = V_38 -> V_19 ? V_38 -> V_19 -> V_76 : NULL ;
if ( F_66 ( V_32 ) )
return F_54 ( V_38 , V_83 ) ;
if ( ! V_76 ) {
F_64 ( V_32 ) ;
goto V_70;
}
F_41 ( V_38 ) ;
V_32 -> V_67 = false ;
if ( V_76 -> V_65 ) {
T_5 V_66 = V_32 -> V_56 ;
int error ;
error = V_76 -> V_65 ( V_38 ) ;
F_55 ( V_76 -> V_65 , error ) ;
if ( error )
return error ;
if ( ! V_32 -> V_67 && V_32 -> V_56 != V_57
&& V_32 -> V_56 != V_58 ) {
F_56 ( V_32 -> V_56 != V_66 ,
L_6 ,
V_76 -> V_65 ) ;
}
}
V_70:
F_49 ( V_68 , V_32 ) ;
return 0 ;
}
static int F_76 ( struct V_4 * V_38 )
{
struct V_32 * V_32 = F_35 ( V_38 ) ;
const struct V_82 * V_76 = V_38 -> V_19 ? V_38 -> V_19 -> V_76 : NULL ;
if ( F_66 ( V_32 ) )
return F_57 ( V_38 , V_83 ) ;
if ( ! V_76 ) {
F_58 ( V_32 ) ;
goto V_70;
}
if ( V_76 -> V_84 ) {
T_5 V_66 = V_32 -> V_56 ;
int error ;
error = V_76 -> V_84 ( V_38 ) ;
F_55 ( V_76 -> V_84 , error ) ;
if ( error )
return error ;
if ( ! V_32 -> V_67 && V_32 -> V_56 != V_57
&& V_32 -> V_56 != V_58 ) {
F_56 ( V_32 -> V_56 != V_66 ,
L_6 ,
V_76 -> V_84 ) ;
goto V_70;
}
}
if ( ! V_32 -> V_67 ) {
F_58 ( V_32 ) ;
if ( F_77 ( V_32 ) )
F_78 ( V_32 ) ;
}
F_50 ( V_32 ) ;
if ( V_32 -> V_7 == V_85 )
F_79 ( V_32 , V_86 , 0 ) ;
V_70:
F_49 ( V_71 , V_32 ) ;
return 0 ;
}
static int F_80 ( struct V_4 * V_38 )
{
struct V_32 * V_32 = F_35 ( V_38 ) ;
struct V_21 * V_2 = V_38 -> V_19 ;
int error = 0 ;
F_47 ( V_32 ) ;
if ( F_66 ( V_32 ) )
return F_59 ( V_38 ) ;
if ( V_2 && V_2 -> V_76 && V_2 -> V_76 -> V_87 )
error = V_2 -> V_76 -> V_87 ( V_38 ) ;
return error ;
}
static int F_81 ( struct V_4 * V_38 )
{
struct V_32 * V_32 = F_35 ( V_38 ) ;
const struct V_82 * V_76 = V_38 -> V_19 ? V_38 -> V_19 -> V_76 : NULL ;
int error = 0 ;
if ( V_32 -> V_67 )
F_43 ( V_32 ) ;
if ( F_66 ( V_32 ) )
return F_60 ( V_38 ) ;
F_61 ( V_32 ) ;
if ( V_76 ) {
if ( V_76 -> V_74 )
error = V_76 -> V_74 ( V_38 ) ;
} else {
F_51 ( V_32 ) ;
}
return error ;
}
static int F_82 ( struct V_4 * V_38 )
{
struct V_32 * V_32 = F_35 ( V_38 ) ;
const struct V_82 * V_76 = V_38 -> V_19 ? V_38 -> V_19 -> V_76 : NULL ;
if ( F_66 ( V_32 ) )
return F_54 ( V_38 , V_88 ) ;
if ( ! V_76 ) {
F_64 ( V_32 ) ;
return 0 ;
}
F_41 ( V_38 ) ;
V_32 -> V_67 = false ;
if ( V_76 -> V_89 ) {
int error ;
error = V_76 -> V_89 ( V_38 ) ;
F_55 ( V_76 -> V_89 , error ) ;
if ( error )
return error ;
}
if ( V_90 . V_89 )
return V_90 . V_89 ( V_38 ) ;
return 0 ;
}
static int F_83 ( struct V_4 * V_38 )
{
struct V_32 * V_32 = F_35 ( V_38 ) ;
struct V_21 * V_2 = V_38 -> V_19 ;
if ( F_66 ( V_32 ) )
return F_57 ( V_38 , V_88 ) ;
if ( V_2 && V_2 -> V_76 && V_2 -> V_76 -> V_91 ) {
int error ;
error = V_2 -> V_76 -> V_91 ( V_38 ) ;
F_55 ( V_2 -> V_76 -> V_91 , error ) ;
if ( error )
return error ;
}
if ( ! V_32 -> V_67 )
F_58 ( V_32 ) ;
F_50 ( V_32 ) ;
if ( V_90 . V_91 )
return V_90 . V_91 ( V_38 ) ;
return 0 ;
}
static int F_84 ( struct V_4 * V_38 )
{
struct V_32 * V_32 = F_35 ( V_38 ) ;
struct V_21 * V_2 = V_38 -> V_19 ;
int error = 0 ;
if ( V_90 . V_92 ) {
error = V_90 . V_92 ( V_38 ) ;
if ( error )
return error ;
}
if ( F_66 ( V_32 ) )
return F_59 ( V_38 ) ;
F_44 ( V_32 , V_57 ) ;
if ( V_2 && V_2 -> V_76 && V_2 -> V_76 -> V_92 )
error = V_2 -> V_76 -> V_92 ( V_38 ) ;
return error ;
}
static int F_85 ( struct V_4 * V_38 )
{
struct V_32 * V_32 = F_35 ( V_38 ) ;
const struct V_82 * V_76 = V_38 -> V_19 ? V_38 -> V_19 -> V_76 : NULL ;
int error = 0 ;
if ( V_90 . V_93 ) {
error = V_90 . V_93 ( V_38 ) ;
if ( error )
return error ;
}
if ( F_66 ( V_32 ) )
return F_60 ( V_38 ) ;
if ( V_76 ) {
if ( V_76 -> V_93 )
error = V_76 -> V_93 ( V_38 ) ;
} else {
F_51 ( V_32 ) ;
}
V_32 -> V_67 = false ;
return error ;
}
static int F_86 ( struct V_4 * V_38 )
{
struct V_32 * V_32 = F_35 ( V_38 ) ;
const struct V_82 * V_76 = V_38 -> V_19 ? V_38 -> V_19 -> V_76 : NULL ;
if ( F_66 ( V_32 ) )
return F_54 ( V_38 , V_94 ) ;
if ( ! V_76 ) {
F_64 ( V_32 ) ;
goto V_70;
}
F_41 ( V_38 ) ;
V_32 -> V_67 = false ;
if ( V_76 -> V_95 ) {
int error ;
error = V_76 -> V_95 ( V_38 ) ;
F_55 ( V_76 -> V_95 , error ) ;
if ( error )
return error ;
}
V_70:
F_49 ( V_68 , V_32 ) ;
if ( V_90 . V_95 )
return V_90 . V_95 ( V_38 ) ;
return 0 ;
}
static int F_87 ( struct V_4 * V_38 )
{
struct V_32 * V_32 = F_35 ( V_38 ) ;
struct V_21 * V_2 = V_38 -> V_19 ;
if ( F_66 ( F_35 ( V_38 ) ) )
return F_57 ( V_38 , V_94 ) ;
if ( ! V_2 || ! V_2 -> V_76 ) {
F_49 ( V_71 , V_32 ) ;
return 0 ;
}
if ( V_2 -> V_76 -> V_96 ) {
int error ;
error = V_2 -> V_76 -> V_96 ( V_38 ) ;
F_55 ( V_2 -> V_76 -> V_96 , error ) ;
if ( error )
return error ;
}
if ( ! V_32 -> V_67 && ! F_62 ( V_32 ) )
F_78 ( V_32 ) ;
if ( V_32 -> V_7 == V_85 )
F_79 ( V_32 , V_86 , 0 ) ;
F_49 ( V_71 , V_32 ) ;
if ( V_90 . V_96 )
return V_90 . V_96 ( V_38 ) ;
return 0 ;
}
static int F_88 ( struct V_4 * V_38 )
{
struct V_32 * V_32 = F_35 ( V_38 ) ;
struct V_21 * V_2 = V_38 -> V_19 ;
int error = 0 ;
if ( V_90 . V_97 ) {
error = V_90 . V_97 ( V_38 ) ;
if ( error )
return error ;
}
F_47 ( V_32 ) ;
if ( F_66 ( V_32 ) )
return F_59 ( V_38 ) ;
if ( V_2 && V_2 -> V_76 && V_2 -> V_76 -> V_97 )
error = V_2 -> V_76 -> V_97 ( V_38 ) ;
return error ;
}
static int F_89 ( struct V_4 * V_38 )
{
struct V_32 * V_32 = F_35 ( V_38 ) ;
const struct V_82 * V_76 = V_38 -> V_19 ? V_38 -> V_19 -> V_76 : NULL ;
int error = 0 ;
if ( V_90 . V_98 ) {
error = V_90 . V_98 ( V_38 ) ;
if ( error )
return error ;
}
if ( V_32 -> V_67 )
F_43 ( V_32 ) ;
if ( F_66 ( V_32 ) )
return F_60 ( V_38 ) ;
F_61 ( V_32 ) ;
if ( V_76 ) {
if ( V_76 -> V_98 )
error = V_76 -> V_98 ( V_38 ) ;
} else {
F_51 ( V_32 ) ;
}
return error ;
}
static int F_90 ( struct V_4 * V_38 )
{
struct V_32 * V_32 = F_35 ( V_38 ) ;
const struct V_82 * V_76 = V_38 -> V_19 ? V_38 -> V_19 -> V_76 : NULL ;
T_5 V_66 = V_32 -> V_56 ;
int error ;
if ( ! V_32 -> V_19 )
return 0 ;
if ( ! V_76 || ! V_76 -> V_99 )
return - V_100 ;
V_32 -> V_67 = false ;
error = V_76 -> V_99 ( V_38 ) ;
if ( error ) {
if ( error == - V_101 || error == - V_102 )
F_91 ( V_38 , L_7 ,
V_76 -> V_99 , error ) ;
else
F_92 ( V_38 , L_8 ,
V_76 -> V_99 , error ) ;
return error ;
}
F_49 ( V_68 , V_32 ) ;
if ( ! V_32 -> V_67 && V_32 -> V_56 != V_57
&& V_32 -> V_56 != V_58 ) {
F_56 ( V_32 -> V_56 != V_66 ,
L_6 ,
V_76 -> V_99 ) ;
return 0 ;
}
if ( ! V_32 -> V_67 ) {
F_58 ( V_32 ) ;
F_93 ( V_32 ) ;
}
return 0 ;
}
static int F_94 ( struct V_4 * V_38 )
{
int V_47 ;
struct V_32 * V_32 = F_35 ( V_38 ) ;
const struct V_82 * V_76 = V_38 -> V_19 ? V_38 -> V_19 -> V_76 : NULL ;
if ( ! V_32 -> V_19 )
return 0 ;
if ( ! V_76 || ! V_76 -> V_103 )
return - V_100 ;
F_43 ( V_32 ) ;
F_49 ( V_62 , V_32 ) ;
F_95 ( V_32 , V_57 , true , false ) ;
F_49 ( V_73 , V_32 ) ;
V_47 = V_76 -> V_103 ( V_38 ) ;
V_32 -> V_104 = false ;
return V_47 ;
}
static int F_96 ( struct V_4 * V_38 )
{
struct V_32 * V_32 = F_35 ( V_38 ) ;
const struct V_82 * V_76 = V_38 -> V_19 ? V_38 -> V_19 -> V_76 : NULL ;
int V_75 = 0 ;
if ( ! V_32 -> V_19 )
return 0 ;
if ( ! V_76 )
return - V_100 ;
if ( V_76 -> V_105 )
V_75 = V_76 -> V_105 ( V_38 ) ;
return V_75 ;
}
int F_97 ( struct V_1 * V_2 , struct V_106 * V_107 ,
const char * V_108 )
{
V_2 -> V_19 . V_41 = V_2 -> V_41 ;
V_2 -> V_19 . V_109 = & V_110 ;
V_2 -> V_19 . V_107 = V_107 ;
V_2 -> V_19 . V_108 = V_108 ;
F_98 ( & V_2 -> V_15 . V_16 ) ;
F_99 ( & V_2 -> V_15 . V_18 ) ;
return F_100 ( & V_2 -> V_19 ) ;
}
void F_101 ( struct V_1 * V_2 )
{
F_102 ( & V_2 -> V_19 ) ;
F_7 ( V_2 ) ;
}
struct V_1 * F_103 ( const struct V_32 * V_38 )
{
if ( V_38 -> V_19 )
return V_38 -> V_19 ;
else {
int V_111 ;
for ( V_111 = 0 ; V_111 <= V_112 ; V_111 ++ )
if ( V_38 -> V_113 [ V_111 ] . V_114 & V_115 )
return & V_116 ;
}
return NULL ;
}
static int F_104 ( struct V_4 * V_38 , struct V_21 * V_2 )
{
struct V_32 * V_32 = F_35 ( V_38 ) ;
struct V_1 * V_46 ;
const struct V_25 * V_39 ;
if ( ! V_32 -> V_117 )
return 0 ;
V_46 = F_12 ( V_2 ) ;
V_39 = F_16 ( V_46 , V_32 ) ;
if ( V_39 )
return 1 ;
return 0 ;
}
struct V_32 * F_36 ( struct V_32 * V_38 )
{
if ( V_38 )
F_105 ( & V_38 -> V_38 ) ;
return V_38 ;
}
void F_37 ( struct V_32 * V_38 )
{
if ( V_38 )
F_106 ( & V_38 -> V_38 ) ;
}
static int F_107 ( struct V_4 * V_38 , struct V_118 * V_119 )
{
struct V_32 * V_33 ;
if ( ! V_38 )
return - V_37 ;
V_33 = F_35 ( V_38 ) ;
if ( F_108 ( V_119 , L_9 , V_33 -> V_7 ) )
return - V_13 ;
if ( F_108 ( V_119 , L_10 , V_33 -> V_3 , V_33 -> V_4 ) )
return - V_13 ;
if ( F_108 ( V_119 , L_11 , V_33 -> V_34 ,
V_33 -> V_35 ) )
return - V_13 ;
if ( F_108 ( V_119 , L_12 , F_109 ( V_33 ) ) )
return - V_13 ;
if ( F_108 ( V_119 , L_13 ,
V_33 -> V_3 , V_33 -> V_4 ,
V_33 -> V_34 , V_33 -> V_35 ,
( V_120 ) ( V_33 -> V_7 >> 16 ) , ( V_120 ) ( V_33 -> V_7 >> 8 ) ,
( V_120 ) ( V_33 -> V_7 ) ) )
return - V_13 ;
return 0 ;
}
static int F_110 ( struct V_4 * V_38 )
{
return F_111 ( F_35 ( V_38 ) ) ;
}
static int T_6 F_112 ( void )
{
return F_113 ( & V_110 ) ;
}
