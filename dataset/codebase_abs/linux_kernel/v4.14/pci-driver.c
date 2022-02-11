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
static bool F_22 ( struct V_32 * V_38 )
{
#ifdef F_23
return V_38 -> V_49 && V_38 -> V_50 -> V_51 ;
#else
return false ;
#endif
}
static int F_24 ( struct V_1 * V_2 , struct V_32 * V_38 ,
const struct V_25 * V_14 )
{
int error , V_17 , V_52 ;
struct V_44 V_45 = { V_2 , V_38 , V_14 } ;
V_17 = F_25 ( & V_38 -> V_38 ) ;
V_38 -> V_51 = 1 ;
F_26 () ;
if ( V_17 < 0 || V_17 >= V_53 || ! F_27 ( V_17 ) ||
F_22 ( V_38 ) )
V_52 = V_54 ;
else
V_52 = F_28 ( F_29 ( V_17 ) , V_55 ) ;
if ( V_52 < V_54 )
error = F_30 ( V_52 , F_18 , & V_45 ) ;
else
error = F_18 ( & V_45 ) ;
V_38 -> V_51 = 0 ;
F_31 () ;
return error ;
}
static int F_32 ( struct V_1 * V_2 , struct V_32 * V_32 )
{
const struct V_25 * V_14 ;
int error = 0 ;
if ( ! V_32 -> V_19 && V_2 -> V_48 ) {
error = - V_37 ;
V_14 = F_16 ( V_2 , V_32 ) ;
if ( V_14 )
error = F_24 ( V_2 , V_32 , V_14 ) ;
}
return error ;
}
int __weak F_33 ( struct V_32 * V_38 )
{
return 0 ;
}
void __weak F_34 ( struct V_32 * V_38 )
{
}
static inline bool F_35 ( struct V_32 * V_33 )
{
return ( ! V_33 -> V_49 || V_33 -> V_50 -> V_56 -> V_57 ) ;
}
static inline bool F_35 ( struct V_32 * V_33 )
{
return true ;
}
static int F_36 ( struct V_4 * V_38 )
{
int error ;
struct V_32 * V_32 = F_37 ( V_38 ) ;
struct V_1 * V_2 = F_12 ( V_38 -> V_19 ) ;
F_38 ( V_32 ) ;
error = F_33 ( V_32 ) ;
if ( error < 0 )
return error ;
F_39 ( V_32 ) ;
if ( F_35 ( V_32 ) ) {
error = F_32 ( V_2 , V_32 ) ;
if ( error ) {
F_34 ( V_32 ) ;
F_40 ( V_32 ) ;
}
}
return error ;
}
static int F_41 ( struct V_4 * V_38 )
{
struct V_32 * V_32 = F_37 ( V_38 ) ;
struct V_1 * V_2 = V_32 -> V_19 ;
if ( V_2 ) {
if ( V_2 -> remove ) {
F_19 ( V_38 ) ;
V_2 -> remove ( V_32 ) ;
F_42 ( V_38 ) ;
}
F_34 ( V_32 ) ;
V_32 -> V_19 = NULL ;
}
F_20 ( V_38 ) ;
if ( V_32 -> V_58 == V_59 )
V_32 -> V_58 = V_60 ;
F_40 ( V_32 ) ;
return 0 ;
}
static void F_43 ( struct V_4 * V_38 )
{
struct V_32 * V_32 = F_37 ( V_38 ) ;
struct V_1 * V_2 = V_32 -> V_19 ;
F_44 ( V_38 ) ;
if ( V_2 && V_2 -> V_61 )
V_2 -> V_61 ( V_32 ) ;
if ( V_62 && ( V_32 -> V_58 <= V_63 ) )
F_45 ( V_32 ) ;
}
static int F_46 ( struct V_32 * V_32 )
{
F_47 ( V_32 , V_60 ) ;
if ( V_32 -> V_58 != V_59 ) {
int error = F_48 ( V_32 , V_59 ) ;
if ( error )
return error ;
}
F_49 ( V_32 ) ;
F_50 ( V_32 ) ;
return 0 ;
}
static void F_51 ( struct V_32 * V_32 )
{
F_52 ( V_32 ) ;
F_49 ( V_32 ) ;
F_50 ( V_32 ) ;
F_53 ( V_64 , V_32 ) ;
}
static void F_54 ( struct V_32 * V_32 )
{
if ( V_32 -> V_58 == V_59 )
V_32 -> V_58 = V_60 ;
}
static int F_55 ( struct V_32 * V_32 )
{
int V_30 ;
V_30 = F_56 ( V_32 ) ;
if ( V_32 -> V_65 )
F_57 ( V_32 ) ;
return V_30 ;
}
static int F_58 ( struct V_4 * V_38 , T_4 V_66 )
{
struct V_32 * V_32 = F_37 ( V_38 ) ;
struct V_1 * V_2 = V_32 -> V_19 ;
if ( V_2 && V_2 -> V_67 ) {
T_5 V_68 = V_32 -> V_58 ;
int error ;
error = V_2 -> V_67 ( V_32 , V_66 ) ;
F_59 ( V_2 -> V_67 , error ) ;
if ( error )
return error ;
if ( ! V_32 -> V_69 && V_32 -> V_58 != V_59
&& V_32 -> V_58 != V_60 ) {
F_60 ( V_32 -> V_58 != V_68 ,
L_4 ,
V_2 -> V_67 ) ;
}
}
F_53 ( V_70 , V_32 ) ;
return 0 ;
}
static int F_61 ( struct V_4 * V_38 , T_4 V_66 )
{
struct V_32 * V_32 = F_37 ( V_38 ) ;
struct V_1 * V_2 = V_32 -> V_19 ;
if ( V_2 && V_2 -> V_71 ) {
T_5 V_68 = V_32 -> V_58 ;
int error ;
error = V_2 -> V_71 ( V_32 , V_66 ) ;
F_59 ( V_2 -> V_71 , error ) ;
if ( error )
return error ;
if ( ! V_32 -> V_69 && V_32 -> V_58 != V_59
&& V_32 -> V_58 != V_60 ) {
F_60 ( V_32 -> V_58 != V_68 ,
L_4 ,
V_2 -> V_71 ) ;
goto V_72;
}
}
if ( ! V_32 -> V_69 )
F_62 ( V_32 ) ;
F_54 ( V_32 ) ;
V_72:
F_53 ( V_73 , V_32 ) ;
return 0 ;
}
static int F_63 ( struct V_4 * V_38 )
{
struct V_32 * V_32 = F_37 ( V_38 ) ;
struct V_1 * V_2 = V_32 -> V_19 ;
return V_2 && V_2 -> V_74 ?
V_2 -> V_74 ( V_32 ) : 0 ;
}
static int F_64 ( struct V_4 * V_38 )
{
struct V_32 * V_32 = F_37 ( V_38 ) ;
struct V_1 * V_2 = V_32 -> V_19 ;
F_53 ( V_75 , V_32 ) ;
return V_2 && V_2 -> V_76 ?
V_2 -> V_76 ( V_32 ) : F_55 ( V_32 ) ;
}
static void F_65 ( struct V_32 * V_32 )
{
F_53 ( V_75 , V_32 ) ;
F_66 ( V_32 , V_59 , false ) ;
}
static void F_67 ( struct V_32 * V_32 )
{
if ( ! F_68 ( V_32 ) )
F_69 ( V_32 ) ;
}
static bool F_70 ( struct V_32 * V_32 )
{
struct V_1 * V_2 = V_32 -> V_19 ;
bool V_77 = V_2 && ( V_2 -> V_67 || V_2 -> V_71 || V_2 -> V_76
|| V_2 -> V_74 ) ;
F_71 ( V_77 && V_2 -> V_19 . V_78 , L_5 ,
V_2 -> V_41 , V_32 -> V_3 , V_32 -> V_4 ) ;
return V_77 ;
}
static int F_72 ( struct V_4 * V_38 )
{
struct V_21 * V_2 = V_38 -> V_19 ;
if ( V_38 -> V_79 . V_80 )
F_44 ( V_38 ) ;
if ( V_2 && V_2 -> V_78 && V_2 -> V_78 -> V_81 ) {
int error = V_2 -> V_78 -> V_81 ( V_38 ) ;
if ( error )
return error ;
}
return F_73 ( F_37 ( V_38 ) ) ;
}
static void F_74 ( struct V_4 * V_38 )
{
struct V_32 * V_32 = F_37 ( V_38 ) ;
F_75 ( V_32 ) ;
F_76 ( V_38 ) ;
if ( V_38 -> V_79 . V_82 && F_77 () ) {
T_5 V_83 = V_32 -> V_58 ;
F_47 ( V_32 , V_32 -> V_58 ) ;
if ( V_32 -> V_58 < V_83 )
F_78 ( V_38 ) ;
}
}
static int F_79 ( struct V_4 * V_38 )
{
struct V_32 * V_32 = F_37 ( V_38 ) ;
const struct V_84 * V_78 = V_38 -> V_19 ? V_38 -> V_19 -> V_78 : NULL ;
if ( F_70 ( V_32 ) )
return F_58 ( V_38 , V_85 ) ;
if ( ! V_78 ) {
F_67 ( V_32 ) ;
goto V_72;
}
F_44 ( V_38 ) ;
V_32 -> V_69 = false ;
if ( V_78 -> V_67 ) {
T_5 V_68 = V_32 -> V_58 ;
int error ;
error = V_78 -> V_67 ( V_38 ) ;
F_59 ( V_78 -> V_67 , error ) ;
if ( error )
return error ;
if ( ! V_32 -> V_69 && V_32 -> V_58 != V_59
&& V_32 -> V_58 != V_60 ) {
F_60 ( V_32 -> V_58 != V_68 ,
L_6 ,
V_78 -> V_67 ) ;
}
}
V_72:
F_53 ( V_70 , V_32 ) ;
return 0 ;
}
static int F_80 ( struct V_4 * V_38 )
{
struct V_32 * V_32 = F_37 ( V_38 ) ;
const struct V_84 * V_78 = V_38 -> V_19 ? V_38 -> V_19 -> V_78 : NULL ;
if ( F_70 ( V_32 ) )
return F_61 ( V_38 , V_85 ) ;
if ( ! V_78 ) {
F_62 ( V_32 ) ;
goto V_72;
}
if ( V_78 -> V_86 ) {
T_5 V_68 = V_32 -> V_58 ;
int error ;
error = V_78 -> V_86 ( V_38 ) ;
F_59 ( V_78 -> V_86 , error ) ;
if ( error )
return error ;
if ( ! V_32 -> V_69 && V_32 -> V_58 != V_59
&& V_32 -> V_58 != V_60 ) {
F_60 ( V_32 -> V_58 != V_68 ,
L_6 ,
V_78 -> V_86 ) ;
goto V_72;
}
}
if ( ! V_32 -> V_69 ) {
F_62 ( V_32 ) ;
if ( F_81 ( V_32 ) )
F_82 ( V_32 ) ;
}
F_54 ( V_32 ) ;
if ( V_32 -> V_7 == V_87 )
F_83 ( V_32 , V_88 , 0 ) ;
V_72:
F_53 ( V_73 , V_32 ) ;
return 0 ;
}
static int F_84 ( struct V_4 * V_38 )
{
struct V_32 * V_32 = F_37 ( V_38 ) ;
struct V_21 * V_2 = V_38 -> V_19 ;
int error = 0 ;
F_51 ( V_32 ) ;
if ( F_70 ( V_32 ) )
return F_63 ( V_38 ) ;
if ( V_2 && V_2 -> V_78 && V_2 -> V_78 -> V_89 )
error = V_2 -> V_78 -> V_89 ( V_38 ) ;
return error ;
}
static int F_85 ( struct V_4 * V_38 )
{
struct V_32 * V_32 = F_37 ( V_38 ) ;
const struct V_84 * V_78 = V_38 -> V_19 ? V_38 -> V_19 -> V_78 : NULL ;
int error = 0 ;
if ( V_32 -> V_69 )
F_46 ( V_32 ) ;
if ( F_70 ( V_32 ) )
return F_64 ( V_38 ) ;
F_65 ( V_32 ) ;
if ( V_78 ) {
if ( V_78 -> V_76 )
error = V_78 -> V_76 ( V_38 ) ;
} else {
F_55 ( V_32 ) ;
}
return error ;
}
static int F_86 ( struct V_4 * V_38 )
{
struct V_32 * V_32 = F_37 ( V_38 ) ;
const struct V_84 * V_78 = V_38 -> V_19 ? V_38 -> V_19 -> V_78 : NULL ;
if ( F_70 ( V_32 ) )
return F_58 ( V_38 , V_90 ) ;
if ( ! V_78 ) {
F_67 ( V_32 ) ;
return 0 ;
}
F_44 ( V_38 ) ;
V_32 -> V_69 = false ;
if ( V_78 -> V_91 ) {
int error ;
error = V_78 -> V_91 ( V_38 ) ;
F_59 ( V_78 -> V_91 , error ) ;
if ( error )
return error ;
}
if ( V_92 . V_91 )
return V_92 . V_91 ( V_38 ) ;
return 0 ;
}
static int F_87 ( struct V_4 * V_38 )
{
struct V_32 * V_32 = F_37 ( V_38 ) ;
struct V_21 * V_2 = V_38 -> V_19 ;
if ( F_70 ( V_32 ) )
return F_61 ( V_38 , V_90 ) ;
if ( V_2 && V_2 -> V_78 && V_2 -> V_78 -> V_93 ) {
int error ;
error = V_2 -> V_78 -> V_93 ( V_38 ) ;
F_59 ( V_2 -> V_78 -> V_93 , error ) ;
if ( error )
return error ;
}
if ( ! V_32 -> V_69 )
F_62 ( V_32 ) ;
F_54 ( V_32 ) ;
if ( V_92 . V_93 )
return V_92 . V_93 ( V_38 ) ;
return 0 ;
}
static int F_88 ( struct V_4 * V_38 )
{
struct V_32 * V_32 = F_37 ( V_38 ) ;
struct V_21 * V_2 = V_38 -> V_19 ;
int error = 0 ;
if ( V_92 . V_94 ) {
error = V_92 . V_94 ( V_38 ) ;
if ( error )
return error ;
}
if ( F_70 ( V_32 ) )
return F_63 ( V_38 ) ;
F_47 ( V_32 , V_59 ) ;
F_49 ( V_32 ) ;
if ( V_2 && V_2 -> V_78 && V_2 -> V_78 -> V_94 )
error = V_2 -> V_78 -> V_94 ( V_38 ) ;
return error ;
}
static int F_89 ( struct V_4 * V_38 )
{
struct V_32 * V_32 = F_37 ( V_38 ) ;
const struct V_84 * V_78 = V_38 -> V_19 ? V_38 -> V_19 -> V_78 : NULL ;
int error = 0 ;
if ( V_92 . V_95 ) {
error = V_92 . V_95 ( V_38 ) ;
if ( error )
return error ;
}
if ( F_70 ( V_32 ) )
return F_64 ( V_38 ) ;
if ( V_78 ) {
if ( V_78 -> V_95 )
error = V_78 -> V_95 ( V_38 ) ;
} else {
F_55 ( V_32 ) ;
}
V_32 -> V_69 = false ;
return error ;
}
static int F_90 ( struct V_4 * V_38 )
{
struct V_32 * V_32 = F_37 ( V_38 ) ;
const struct V_84 * V_78 = V_38 -> V_19 ? V_38 -> V_19 -> V_78 : NULL ;
if ( F_70 ( V_32 ) )
return F_58 ( V_38 , V_96 ) ;
if ( ! V_78 ) {
F_67 ( V_32 ) ;
goto V_72;
}
F_44 ( V_38 ) ;
V_32 -> V_69 = false ;
if ( V_78 -> V_97 ) {
int error ;
error = V_78 -> V_97 ( V_38 ) ;
F_59 ( V_78 -> V_97 , error ) ;
if ( error )
return error ;
}
V_72:
F_53 ( V_70 , V_32 ) ;
if ( V_92 . V_97 )
return V_92 . V_97 ( V_38 ) ;
return 0 ;
}
static int F_91 ( struct V_4 * V_38 )
{
struct V_32 * V_32 = F_37 ( V_38 ) ;
struct V_21 * V_2 = V_38 -> V_19 ;
if ( F_70 ( F_37 ( V_38 ) ) )
return F_61 ( V_38 , V_96 ) ;
if ( ! V_2 || ! V_2 -> V_78 ) {
F_53 ( V_73 , V_32 ) ;
return 0 ;
}
if ( V_2 -> V_78 -> V_98 ) {
int error ;
error = V_2 -> V_78 -> V_98 ( V_38 ) ;
F_59 ( V_2 -> V_78 -> V_98 , error ) ;
if ( error )
return error ;
}
if ( ! V_32 -> V_69 && ! F_68 ( V_32 ) )
F_82 ( V_32 ) ;
if ( V_32 -> V_7 == V_87 )
F_83 ( V_32 , V_88 , 0 ) ;
F_53 ( V_73 , V_32 ) ;
if ( V_92 . V_98 )
return V_92 . V_98 ( V_38 ) ;
return 0 ;
}
static int F_92 ( struct V_4 * V_38 )
{
struct V_32 * V_32 = F_37 ( V_38 ) ;
struct V_21 * V_2 = V_38 -> V_19 ;
int error = 0 ;
if ( V_92 . V_99 ) {
error = V_92 . V_99 ( V_38 ) ;
if ( error )
return error ;
}
F_51 ( V_32 ) ;
if ( F_70 ( V_32 ) )
return F_63 ( V_38 ) ;
if ( V_2 && V_2 -> V_78 && V_2 -> V_78 -> V_99 )
error = V_2 -> V_78 -> V_99 ( V_38 ) ;
return error ;
}
static int F_93 ( struct V_4 * V_38 )
{
struct V_32 * V_32 = F_37 ( V_38 ) ;
const struct V_84 * V_78 = V_38 -> V_19 ? V_38 -> V_19 -> V_78 : NULL ;
int error = 0 ;
if ( V_92 . V_100 ) {
error = V_92 . V_100 ( V_38 ) ;
if ( error )
return error ;
}
if ( V_32 -> V_69 )
F_46 ( V_32 ) ;
if ( F_70 ( V_32 ) )
return F_64 ( V_38 ) ;
F_65 ( V_32 ) ;
if ( V_78 ) {
if ( V_78 -> V_100 )
error = V_78 -> V_100 ( V_38 ) ;
} else {
F_55 ( V_32 ) ;
}
return error ;
}
static int F_94 ( struct V_4 * V_38 )
{
struct V_32 * V_32 = F_37 ( V_38 ) ;
const struct V_84 * V_78 = V_38 -> V_19 ? V_38 -> V_19 -> V_78 : NULL ;
T_5 V_68 = V_32 -> V_58 ;
int error ;
if ( ! V_32 -> V_19 )
return 0 ;
if ( ! V_78 || ! V_78 -> V_101 )
return - V_102 ;
V_32 -> V_69 = false ;
error = V_78 -> V_101 ( V_38 ) ;
if ( error ) {
if ( error == - V_103 || error == - V_104 )
F_95 ( V_38 , L_7 ,
V_78 -> V_101 , error ) ;
else
F_96 ( V_38 , L_8 ,
V_78 -> V_101 , error ) ;
return error ;
}
F_53 ( V_70 , V_32 ) ;
if ( ! V_32 -> V_69 && V_32 -> V_58 != V_59
&& V_32 -> V_58 != V_60 ) {
F_60 ( V_32 -> V_58 != V_68 ,
L_6 ,
V_78 -> V_101 ) ;
return 0 ;
}
if ( ! V_32 -> V_69 ) {
F_62 ( V_32 ) ;
F_97 ( V_32 ) ;
}
return 0 ;
}
static int F_98 ( struct V_4 * V_38 )
{
int V_47 ;
struct V_32 * V_32 = F_37 ( V_38 ) ;
const struct V_84 * V_78 = V_38 -> V_19 ? V_38 -> V_19 -> V_78 : NULL ;
if ( ! V_32 -> V_19 )
return 0 ;
if ( ! V_78 || ! V_78 -> V_105 )
return - V_102 ;
F_46 ( V_32 ) ;
F_53 ( V_64 , V_32 ) ;
F_66 ( V_32 , V_59 , false ) ;
F_53 ( V_75 , V_32 ) ;
V_47 = V_78 -> V_105 ( V_38 ) ;
V_32 -> V_106 = false ;
return V_47 ;
}
static int F_99 ( struct V_4 * V_38 )
{
struct V_32 * V_32 = F_37 ( V_38 ) ;
const struct V_84 * V_78 = V_38 -> V_19 ? V_38 -> V_19 -> V_78 : NULL ;
int V_77 = 0 ;
if ( ! V_32 -> V_19 )
return 0 ;
if ( ! V_78 )
return - V_102 ;
if ( V_78 -> V_107 )
V_77 = V_78 -> V_107 ( V_38 ) ;
return V_77 ;
}
int F_100 ( struct V_1 * V_2 , struct V_108 * V_109 ,
const char * V_110 )
{
V_2 -> V_19 . V_41 = V_2 -> V_41 ;
V_2 -> V_19 . V_111 = & V_112 ;
V_2 -> V_19 . V_109 = V_109 ;
V_2 -> V_19 . V_110 = V_110 ;
V_2 -> V_19 . V_113 = V_2 -> V_113 ;
F_101 ( & V_2 -> V_15 . V_16 ) ;
F_102 ( & V_2 -> V_15 . V_18 ) ;
return F_103 ( & V_2 -> V_19 ) ;
}
void F_104 ( struct V_1 * V_2 )
{
F_105 ( & V_2 -> V_19 ) ;
F_7 ( V_2 ) ;
}
struct V_1 * F_106 ( const struct V_32 * V_38 )
{
if ( V_38 -> V_19 )
return V_38 -> V_19 ;
else {
int V_114 ;
for ( V_114 = 0 ; V_114 <= V_115 ; V_114 ++ )
if ( V_38 -> V_116 [ V_114 ] . V_117 & V_118 )
return & V_119 ;
}
return NULL ;
}
static int F_107 ( struct V_4 * V_38 , struct V_21 * V_2 )
{
struct V_32 * V_32 = F_37 ( V_38 ) ;
struct V_1 * V_46 ;
const struct V_25 * V_39 ;
if ( ! V_32 -> V_120 )
return 0 ;
V_46 = F_12 ( V_2 ) ;
V_39 = F_16 ( V_46 , V_32 ) ;
if ( V_39 )
return 1 ;
return 0 ;
}
struct V_32 * F_39 ( struct V_32 * V_38 )
{
if ( V_38 )
F_108 ( & V_38 -> V_38 ) ;
return V_38 ;
}
void F_40 ( struct V_32 * V_38 )
{
if ( V_38 )
F_109 ( & V_38 -> V_38 ) ;
}
static int F_110 ( struct V_4 * V_38 , struct V_121 * V_122 )
{
struct V_32 * V_33 ;
if ( ! V_38 )
return - V_37 ;
V_33 = F_37 ( V_38 ) ;
if ( F_111 ( V_122 , L_9 , V_33 -> V_7 ) )
return - V_13 ;
if ( F_111 ( V_122 , L_10 , V_33 -> V_3 , V_33 -> V_4 ) )
return - V_13 ;
if ( F_111 ( V_122 , L_11 , V_33 -> V_34 ,
V_33 -> V_35 ) )
return - V_13 ;
if ( F_111 ( V_122 , L_12 , F_112 ( V_33 ) ) )
return - V_13 ;
if ( F_111 ( V_122 , L_13 ,
V_33 -> V_3 , V_33 -> V_4 ,
V_33 -> V_34 , V_33 -> V_35 ,
( V_123 ) ( V_33 -> V_7 >> 16 ) , ( V_123 ) ( V_33 -> V_7 >> 8 ) ,
( V_123 ) ( V_33 -> V_7 ) ) )
return - V_13 ;
return 0 ;
}
static int F_113 ( struct V_4 * V_38 )
{
return F_114 ( F_37 ( V_38 ) ) ;
}
static int T_6 F_115 ( void )
{
return F_116 ( & V_112 ) ;
}
