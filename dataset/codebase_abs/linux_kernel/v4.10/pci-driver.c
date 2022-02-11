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
if ( error >= 0 )
error = 0 ;
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
static int F_33 ( struct V_4 * V_38 )
{
int error ;
struct V_32 * V_32 = F_34 ( V_38 ) ;
struct V_1 * V_2 = F_12 ( V_38 -> V_19 ) ;
error = F_31 ( V_32 ) ;
if ( error < 0 )
return error ;
F_35 ( V_32 ) ;
error = F_30 ( V_2 , V_32 ) ;
if ( error ) {
F_32 ( V_32 ) ;
F_36 ( V_32 ) ;
}
return error ;
}
static int F_37 ( struct V_4 * V_38 )
{
struct V_32 * V_32 = F_34 ( V_38 ) ;
struct V_1 * V_2 = V_32 -> V_19 ;
if ( V_2 ) {
if ( V_2 -> remove ) {
F_19 ( V_38 ) ;
V_2 -> remove ( V_32 ) ;
F_38 ( V_38 ) ;
}
F_32 ( V_32 ) ;
V_32 -> V_19 = NULL ;
}
F_20 ( V_38 ) ;
if ( V_32 -> V_52 == V_53 )
V_32 -> V_52 = V_54 ;
F_36 ( V_32 ) ;
return 0 ;
}
static void F_39 ( struct V_4 * V_38 )
{
struct V_32 * V_32 = F_34 ( V_38 ) ;
struct V_1 * V_2 = V_32 -> V_19 ;
F_40 ( V_38 ) ;
if ( V_2 && V_2 -> V_55 )
V_2 -> V_55 ( V_32 ) ;
F_41 ( V_32 ) ;
F_42 ( V_32 ) ;
if ( V_56 && ( V_32 -> V_52 <= V_57 ) )
F_43 ( V_32 ) ;
}
static int F_44 ( struct V_32 * V_32 )
{
F_45 ( V_32 , V_54 ) ;
if ( V_32 -> V_52 != V_53 ) {
int error = F_46 ( V_32 , V_53 ) ;
if ( error )
return error ;
}
F_47 ( V_32 ) ;
return 0 ;
}
static void F_48 ( struct V_32 * V_32 )
{
F_49 ( V_32 ) ;
F_47 ( V_32 ) ;
F_50 ( V_58 , V_32 ) ;
}
static void F_51 ( struct V_32 * V_32 )
{
if ( V_32 -> V_52 == V_53 )
V_32 -> V_52 = V_54 ;
}
static int F_52 ( struct V_32 * V_32 )
{
int V_30 ;
V_30 = F_53 ( V_32 ) ;
if ( V_32 -> V_59 )
F_54 ( V_32 ) ;
return V_30 ;
}
static int F_55 ( struct V_4 * V_38 , T_4 V_60 )
{
struct V_32 * V_32 = F_34 ( V_38 ) ;
struct V_1 * V_2 = V_32 -> V_19 ;
if ( V_2 && V_2 -> V_61 ) {
T_5 V_62 = V_32 -> V_52 ;
int error ;
error = V_2 -> V_61 ( V_32 , V_60 ) ;
F_56 ( V_2 -> V_61 , error ) ;
if ( error )
return error ;
if ( ! V_32 -> V_63 && V_32 -> V_52 != V_53
&& V_32 -> V_52 != V_54 ) {
F_57 ( V_32 -> V_52 != V_62 ,
L_4 ,
V_2 -> V_61 ) ;
}
}
F_50 ( V_64 , V_32 ) ;
return 0 ;
}
static int F_58 ( struct V_4 * V_38 , T_4 V_60 )
{
struct V_32 * V_32 = F_34 ( V_38 ) ;
struct V_1 * V_2 = V_32 -> V_19 ;
if ( V_2 && V_2 -> V_65 ) {
T_5 V_62 = V_32 -> V_52 ;
int error ;
error = V_2 -> V_65 ( V_32 , V_60 ) ;
F_56 ( V_2 -> V_65 , error ) ;
if ( error )
return error ;
if ( ! V_32 -> V_63 && V_32 -> V_52 != V_53
&& V_32 -> V_52 != V_54 ) {
F_57 ( V_32 -> V_52 != V_62 ,
L_4 ,
V_2 -> V_65 ) ;
goto V_66;
}
}
if ( ! V_32 -> V_63 )
F_59 ( V_32 ) ;
F_51 ( V_32 ) ;
V_66:
F_50 ( V_67 , V_32 ) ;
return 0 ;
}
static int F_60 ( struct V_4 * V_38 )
{
struct V_32 * V_32 = F_34 ( V_38 ) ;
struct V_1 * V_2 = V_32 -> V_19 ;
return V_2 && V_2 -> V_68 ?
V_2 -> V_68 ( V_32 ) : 0 ;
}
static int F_61 ( struct V_4 * V_38 )
{
struct V_32 * V_32 = F_34 ( V_38 ) ;
struct V_1 * V_2 = V_32 -> V_19 ;
F_50 ( V_69 , V_32 ) ;
return V_2 && V_2 -> V_70 ?
V_2 -> V_70 ( V_32 ) : F_52 ( V_32 ) ;
}
static void F_62 ( struct V_32 * V_32 )
{
F_50 ( V_69 , V_32 ) ;
if ( ! F_63 ( V_32 ) )
F_64 ( V_32 , V_53 , false ) ;
}
static void F_65 ( struct V_32 * V_32 )
{
if ( ! F_63 ( V_32 ) )
F_66 ( V_32 ) ;
}
static bool F_67 ( struct V_32 * V_32 )
{
struct V_1 * V_2 = V_32 -> V_19 ;
bool V_71 = V_2 && ( V_2 -> V_61 || V_2 -> V_65 || V_2 -> V_70
|| V_2 -> V_68 ) ;
F_68 ( V_71 && V_2 -> V_19 . V_72 , L_5 ,
V_2 -> V_41 , V_32 -> V_3 , V_32 -> V_4 ) ;
return V_71 ;
}
static int F_69 ( struct V_4 * V_38 )
{
struct V_21 * V_2 = V_38 -> V_19 ;
if ( V_38 -> V_73 . V_74 )
F_40 ( V_38 ) ;
if ( V_2 && V_2 -> V_72 && V_2 -> V_72 -> V_75 ) {
int error = V_2 -> V_72 -> V_75 ( V_38 ) ;
if ( error )
return error ;
}
return F_70 ( F_34 ( V_38 ) ) ;
}
static void F_71 ( struct V_4 * V_38 )
{
struct V_32 * V_32 = F_34 ( V_38 ) ;
F_72 ( V_32 ) ;
F_73 ( V_38 ) ;
if ( V_38 -> V_73 . V_76 && F_74 () ) {
T_5 V_77 = V_32 -> V_52 ;
F_45 ( V_32 , V_32 -> V_52 ) ;
if ( V_32 -> V_52 < V_77 )
F_75 ( V_38 ) ;
}
}
static int F_76 ( struct V_4 * V_38 )
{
struct V_32 * V_32 = F_34 ( V_38 ) ;
const struct V_78 * V_72 = V_38 -> V_19 ? V_38 -> V_19 -> V_72 : NULL ;
if ( F_67 ( V_32 ) )
return F_55 ( V_38 , V_79 ) ;
if ( ! V_72 ) {
F_65 ( V_32 ) ;
goto V_66;
}
F_40 ( V_38 ) ;
V_32 -> V_63 = false ;
if ( V_72 -> V_61 ) {
T_5 V_62 = V_32 -> V_52 ;
int error ;
error = V_72 -> V_61 ( V_38 ) ;
F_56 ( V_72 -> V_61 , error ) ;
if ( error )
return error ;
if ( ! V_32 -> V_63 && V_32 -> V_52 != V_53
&& V_32 -> V_52 != V_54 ) {
F_57 ( V_32 -> V_52 != V_62 ,
L_6 ,
V_72 -> V_61 ) ;
}
}
V_66:
F_50 ( V_64 , V_32 ) ;
return 0 ;
}
static int F_77 ( struct V_4 * V_38 )
{
struct V_32 * V_32 = F_34 ( V_38 ) ;
const struct V_78 * V_72 = V_38 -> V_19 ? V_38 -> V_19 -> V_72 : NULL ;
if ( F_67 ( V_32 ) )
return F_58 ( V_38 , V_79 ) ;
if ( ! V_72 ) {
F_59 ( V_32 ) ;
goto V_66;
}
if ( V_72 -> V_80 ) {
T_5 V_62 = V_32 -> V_52 ;
int error ;
error = V_72 -> V_80 ( V_38 ) ;
F_56 ( V_72 -> V_80 , error ) ;
if ( error )
return error ;
if ( ! V_32 -> V_63 && V_32 -> V_52 != V_53
&& V_32 -> V_52 != V_54 ) {
F_57 ( V_32 -> V_52 != V_62 ,
L_6 ,
V_72 -> V_80 ) ;
goto V_66;
}
}
if ( ! V_32 -> V_63 ) {
F_59 ( V_32 ) ;
if ( F_78 ( V_32 ) )
F_79 ( V_32 ) ;
}
F_51 ( V_32 ) ;
if ( V_32 -> V_7 == V_81 )
F_80 ( V_32 , V_82 , 0 ) ;
V_66:
F_50 ( V_67 , V_32 ) ;
return 0 ;
}
static int F_81 ( struct V_4 * V_38 )
{
struct V_32 * V_32 = F_34 ( V_38 ) ;
struct V_21 * V_2 = V_38 -> V_19 ;
int error = 0 ;
F_48 ( V_32 ) ;
if ( F_67 ( V_32 ) )
return F_60 ( V_38 ) ;
if ( V_2 && V_2 -> V_72 && V_2 -> V_72 -> V_83 )
error = V_2 -> V_72 -> V_83 ( V_38 ) ;
return error ;
}
static int F_82 ( struct V_4 * V_38 )
{
struct V_32 * V_32 = F_34 ( V_38 ) ;
const struct V_78 * V_72 = V_38 -> V_19 ? V_38 -> V_19 -> V_72 : NULL ;
int error = 0 ;
if ( V_32 -> V_63 )
F_44 ( V_32 ) ;
if ( F_67 ( V_32 ) )
return F_61 ( V_38 ) ;
F_62 ( V_32 ) ;
if ( V_72 ) {
if ( V_72 -> V_70 )
error = V_72 -> V_70 ( V_38 ) ;
} else {
F_52 ( V_32 ) ;
}
return error ;
}
static int F_83 ( struct V_4 * V_38 )
{
struct V_32 * V_32 = F_34 ( V_38 ) ;
const struct V_78 * V_72 = V_38 -> V_19 ? V_38 -> V_19 -> V_72 : NULL ;
if ( F_67 ( V_32 ) )
return F_55 ( V_38 , V_84 ) ;
if ( ! V_72 ) {
F_65 ( V_32 ) ;
return 0 ;
}
F_40 ( V_38 ) ;
V_32 -> V_63 = false ;
if ( V_72 -> V_85 ) {
int error ;
error = V_72 -> V_85 ( V_38 ) ;
F_56 ( V_72 -> V_85 , error ) ;
if ( error )
return error ;
}
if ( V_86 . V_85 )
return V_86 . V_85 ( V_38 ) ;
return 0 ;
}
static int F_84 ( struct V_4 * V_38 )
{
struct V_32 * V_32 = F_34 ( V_38 ) ;
struct V_21 * V_2 = V_38 -> V_19 ;
if ( F_67 ( V_32 ) )
return F_58 ( V_38 , V_84 ) ;
if ( V_2 && V_2 -> V_72 && V_2 -> V_72 -> V_87 ) {
int error ;
error = V_2 -> V_72 -> V_87 ( V_38 ) ;
F_56 ( V_2 -> V_72 -> V_87 , error ) ;
if ( error )
return error ;
}
if ( ! V_32 -> V_63 )
F_59 ( V_32 ) ;
F_51 ( V_32 ) ;
if ( V_86 . V_87 )
return V_86 . V_87 ( V_38 ) ;
return 0 ;
}
static int F_85 ( struct V_4 * V_38 )
{
struct V_32 * V_32 = F_34 ( V_38 ) ;
struct V_21 * V_2 = V_38 -> V_19 ;
int error = 0 ;
if ( V_86 . V_88 ) {
error = V_86 . V_88 ( V_38 ) ;
if ( error )
return error ;
}
if ( F_67 ( V_32 ) )
return F_60 ( V_38 ) ;
F_45 ( V_32 , V_53 ) ;
if ( V_2 && V_2 -> V_72 && V_2 -> V_72 -> V_88 )
error = V_2 -> V_72 -> V_88 ( V_38 ) ;
return error ;
}
static int F_86 ( struct V_4 * V_38 )
{
struct V_32 * V_32 = F_34 ( V_38 ) ;
const struct V_78 * V_72 = V_38 -> V_19 ? V_38 -> V_19 -> V_72 : NULL ;
int error = 0 ;
if ( V_86 . V_89 ) {
error = V_86 . V_89 ( V_38 ) ;
if ( error )
return error ;
}
if ( F_67 ( V_32 ) )
return F_61 ( V_38 ) ;
if ( V_72 ) {
if ( V_72 -> V_89 )
error = V_72 -> V_89 ( V_38 ) ;
} else {
F_52 ( V_32 ) ;
}
V_32 -> V_63 = false ;
return error ;
}
static int F_87 ( struct V_4 * V_38 )
{
struct V_32 * V_32 = F_34 ( V_38 ) ;
const struct V_78 * V_72 = V_38 -> V_19 ? V_38 -> V_19 -> V_72 : NULL ;
if ( F_67 ( V_32 ) )
return F_55 ( V_38 , V_90 ) ;
if ( ! V_72 ) {
F_65 ( V_32 ) ;
goto V_66;
}
F_40 ( V_38 ) ;
V_32 -> V_63 = false ;
if ( V_72 -> V_91 ) {
int error ;
error = V_72 -> V_91 ( V_38 ) ;
F_56 ( V_72 -> V_91 , error ) ;
if ( error )
return error ;
}
V_66:
F_50 ( V_64 , V_32 ) ;
if ( V_86 . V_91 )
return V_86 . V_91 ( V_38 ) ;
return 0 ;
}
static int F_88 ( struct V_4 * V_38 )
{
struct V_32 * V_32 = F_34 ( V_38 ) ;
struct V_21 * V_2 = V_38 -> V_19 ;
if ( F_67 ( F_34 ( V_38 ) ) )
return F_58 ( V_38 , V_90 ) ;
if ( ! V_2 || ! V_2 -> V_72 ) {
F_50 ( V_67 , V_32 ) ;
return 0 ;
}
if ( V_2 -> V_72 -> V_92 ) {
int error ;
error = V_2 -> V_72 -> V_92 ( V_38 ) ;
F_56 ( V_2 -> V_72 -> V_92 , error ) ;
if ( error )
return error ;
}
if ( ! V_32 -> V_63 && ! F_63 ( V_32 ) )
F_79 ( V_32 ) ;
if ( V_32 -> V_7 == V_81 )
F_80 ( V_32 , V_82 , 0 ) ;
F_50 ( V_67 , V_32 ) ;
if ( V_86 . V_92 )
return V_86 . V_92 ( V_38 ) ;
return 0 ;
}
static int F_89 ( struct V_4 * V_38 )
{
struct V_32 * V_32 = F_34 ( V_38 ) ;
struct V_21 * V_2 = V_38 -> V_19 ;
int error = 0 ;
if ( V_86 . V_93 ) {
error = V_86 . V_93 ( V_38 ) ;
if ( error )
return error ;
}
F_48 ( V_32 ) ;
if ( F_67 ( V_32 ) )
return F_60 ( V_38 ) ;
if ( V_2 && V_2 -> V_72 && V_2 -> V_72 -> V_93 )
error = V_2 -> V_72 -> V_93 ( V_38 ) ;
return error ;
}
static int F_90 ( struct V_4 * V_38 )
{
struct V_32 * V_32 = F_34 ( V_38 ) ;
const struct V_78 * V_72 = V_38 -> V_19 ? V_38 -> V_19 -> V_72 : NULL ;
int error = 0 ;
if ( V_86 . V_94 ) {
error = V_86 . V_94 ( V_38 ) ;
if ( error )
return error ;
}
if ( V_32 -> V_63 )
F_44 ( V_32 ) ;
if ( F_67 ( V_32 ) )
return F_61 ( V_38 ) ;
F_62 ( V_32 ) ;
if ( V_72 ) {
if ( V_72 -> V_94 )
error = V_72 -> V_94 ( V_38 ) ;
} else {
F_52 ( V_32 ) ;
}
return error ;
}
static int F_91 ( struct V_4 * V_38 )
{
struct V_32 * V_32 = F_34 ( V_38 ) ;
const struct V_78 * V_72 = V_38 -> V_19 ? V_38 -> V_19 -> V_72 : NULL ;
T_5 V_62 = V_32 -> V_52 ;
int error ;
if ( ! V_32 -> V_19 )
return 0 ;
if ( ! V_72 || ! V_72 -> V_95 )
return - V_96 ;
V_32 -> V_63 = false ;
error = V_72 -> V_95 ( V_38 ) ;
if ( error ) {
if ( error == - V_97 || error == - V_98 )
F_92 ( V_38 , L_7 ,
V_72 -> V_95 , error ) ;
else
F_93 ( V_38 , L_8 ,
V_72 -> V_95 , error ) ;
return error ;
}
F_50 ( V_64 , V_32 ) ;
if ( ! V_32 -> V_63 && V_32 -> V_52 != V_53
&& V_32 -> V_52 != V_54 ) {
F_57 ( V_32 -> V_52 != V_62 ,
L_6 ,
V_72 -> V_95 ) ;
return 0 ;
}
if ( ! V_32 -> V_63 ) {
F_59 ( V_32 ) ;
F_94 ( V_32 ) ;
}
return 0 ;
}
static int F_95 ( struct V_4 * V_38 )
{
int V_47 ;
struct V_32 * V_32 = F_34 ( V_38 ) ;
const struct V_78 * V_72 = V_38 -> V_19 ? V_38 -> V_19 -> V_72 : NULL ;
if ( ! V_32 -> V_19 )
return 0 ;
if ( ! V_72 || ! V_72 -> V_99 )
return - V_96 ;
F_44 ( V_32 ) ;
F_50 ( V_58 , V_32 ) ;
F_96 ( V_32 , V_53 , true , false ) ;
F_50 ( V_69 , V_32 ) ;
V_47 = V_72 -> V_99 ( V_38 ) ;
V_32 -> V_100 = false ;
return V_47 ;
}
static int F_97 ( struct V_4 * V_38 )
{
struct V_32 * V_32 = F_34 ( V_38 ) ;
const struct V_78 * V_72 = V_38 -> V_19 ? V_38 -> V_19 -> V_72 : NULL ;
int V_71 = 0 ;
if ( ! V_32 -> V_19 )
return 0 ;
if ( ! V_72 )
return - V_96 ;
if ( V_72 -> V_101 )
V_71 = V_72 -> V_101 ( V_38 ) ;
return V_71 ;
}
int F_98 ( struct V_1 * V_2 , struct V_102 * V_103 ,
const char * V_104 )
{
V_2 -> V_19 . V_41 = V_2 -> V_41 ;
V_2 -> V_19 . V_105 = & V_106 ;
V_2 -> V_19 . V_103 = V_103 ;
V_2 -> V_19 . V_104 = V_104 ;
F_99 ( & V_2 -> V_15 . V_16 ) ;
F_100 ( & V_2 -> V_15 . V_18 ) ;
return F_101 ( & V_2 -> V_19 ) ;
}
void F_102 ( struct V_1 * V_2 )
{
F_103 ( & V_2 -> V_19 ) ;
F_7 ( V_2 ) ;
}
struct V_1 * F_104 ( const struct V_32 * V_38 )
{
if ( V_38 -> V_19 )
return V_38 -> V_19 ;
else {
int V_107 ;
for ( V_107 = 0 ; V_107 <= V_108 ; V_107 ++ )
if ( V_38 -> V_109 [ V_107 ] . V_110 & V_111 )
return & V_112 ;
}
return NULL ;
}
static int F_105 ( struct V_4 * V_38 , struct V_21 * V_2 )
{
struct V_32 * V_32 = F_34 ( V_38 ) ;
struct V_1 * V_46 ;
const struct V_25 * V_39 ;
if ( ! V_32 -> V_113 )
return 0 ;
V_46 = F_12 ( V_2 ) ;
V_39 = F_16 ( V_46 , V_32 ) ;
if ( V_39 )
return 1 ;
return 0 ;
}
struct V_32 * F_35 ( struct V_32 * V_38 )
{
if ( V_38 )
F_106 ( & V_38 -> V_38 ) ;
return V_38 ;
}
void F_36 ( struct V_32 * V_38 )
{
if ( V_38 )
F_107 ( & V_38 -> V_38 ) ;
}
static int F_108 ( struct V_4 * V_38 , struct V_114 * V_115 )
{
struct V_32 * V_33 ;
if ( ! V_38 )
return - V_37 ;
V_33 = F_34 ( V_38 ) ;
if ( F_109 ( V_115 , L_9 , V_33 -> V_7 ) )
return - V_13 ;
if ( F_109 ( V_115 , L_10 , V_33 -> V_3 , V_33 -> V_4 ) )
return - V_13 ;
if ( F_109 ( V_115 , L_11 , V_33 -> V_34 ,
V_33 -> V_35 ) )
return - V_13 ;
if ( F_109 ( V_115 , L_12 , F_110 ( V_33 ) ) )
return - V_13 ;
if ( F_109 ( V_115 , L_13 ,
V_33 -> V_3 , V_33 -> V_4 ,
V_33 -> V_34 , V_33 -> V_35 ,
( V_116 ) ( V_33 -> V_7 >> 16 ) , ( V_116 ) ( V_33 -> V_7 >> 8 ) ,
( V_116 ) ( V_33 -> V_7 ) ) )
return - V_13 ;
return 0 ;
}
static int T_6 F_111 ( void )
{
return F_112 ( & V_106 ) ;
}
