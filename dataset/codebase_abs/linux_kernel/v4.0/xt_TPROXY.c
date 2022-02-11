static bool F_1 ( struct V_1 * V_2 )
{
if ( V_2 -> V_3 != V_4 ) {
if ( F_2 ( V_2 ) -> V_5 )
return true ;
F_3 ( V_2 ) ;
} else {
if ( F_4 ( V_2 ) -> V_6 )
return true ;
F_5 ( F_4 ( V_2 ) ) ;
}
return false ;
}
static inline T_1
F_6 ( struct V_7 * V_8 , T_1 V_9 , T_1 V_10 )
{
struct V_11 * V_12 ;
T_1 V_13 ;
if ( V_9 )
return V_9 ;
V_13 = 0 ;
F_7 () ;
V_12 = F_8 ( V_8 -> V_14 ) ;
F_9 (indev) {
V_13 = V_15 -> V_16 ;
break;
} F_10 ( V_12 ) ;
F_11 () ;
return V_13 ? V_13 : V_10 ;
}
static inline struct V_1 *
F_12 ( struct V_17 * V_17 , const T_2 V_18 ,
const T_1 V_19 , const T_1 V_10 ,
const T_3 V_20 , const T_3 V_21 ,
const struct V_22 * V_23 ,
const enum V_24 V_25 )
{
struct V_1 * V_2 ;
switch ( V_18 ) {
case V_26 :
switch ( V_25 ) {
case V_27 :
V_2 = F_13 ( V_17 , & V_28 ,
V_19 , V_20 ,
V_10 , V_21 ,
V_23 -> V_29 ) ;
break;
case V_30 :
V_2 = F_14 ( V_17 , & V_28 ,
V_19 , V_20 , V_10 , V_21 ,
V_23 -> V_29 ) ;
break;
default:
F_15 () ;
}
break;
case V_31 :
V_2 = F_16 ( V_17 , V_19 , V_20 , V_10 , V_21 ,
V_23 -> V_29 ) ;
if ( V_2 ) {
int V_32 = ( V_2 -> V_3 == V_33 ) ;
int V_34 = ( F_2 ( V_2 ) -> V_35 == 0 ) ;
if ( ( V_25 == V_30 && ( ! V_32 || V_34 ) ) ||
( V_25 == V_27 && V_32 ) ) {
F_3 ( V_2 ) ;
V_2 = NULL ;
}
}
break;
default:
F_17 ( 1 ) ;
V_2 = NULL ;
}
F_18 ( L_1 ,
V_18 , F_19 ( V_19 ) , F_20 ( V_20 ) , F_19 ( V_10 ) , F_20 ( V_21 ) , V_25 , V_2 ) ;
return V_2 ;
}
static inline struct V_1 *
F_21 ( struct V_17 * V_17 , const T_2 V_18 ,
const struct V_36 * V_19 , const struct V_36 * V_10 ,
const T_3 V_20 , const T_3 V_21 ,
const struct V_22 * V_23 ,
const enum V_24 V_25 )
{
struct V_1 * V_2 ;
switch ( V_18 ) {
case V_26 :
switch ( V_25 ) {
case V_27 :
V_2 = F_22 ( V_17 , & V_28 ,
V_19 , V_20 ,
V_10 , F_20 ( V_21 ) ,
V_23 -> V_29 ) ;
break;
case V_30 :
V_2 = F_23 ( V_17 , & V_28 ,
V_19 , V_20 , V_10 , F_20 ( V_21 ) ,
V_23 -> V_29 ) ;
break;
default:
F_15 () ;
}
break;
case V_31 :
V_2 = F_24 ( V_17 , V_19 , V_20 , V_10 , V_21 ,
V_23 -> V_29 ) ;
if ( V_2 ) {
int V_32 = ( V_2 -> V_3 == V_33 ) ;
int V_34 = F_25 ( & V_2 -> V_37 ) ;
if ( ( V_25 == V_30 && ( ! V_32 || V_34 ) ) ||
( V_25 == V_27 && V_32 ) ) {
F_3 ( V_2 ) ;
V_2 = NULL ;
}
}
break;
default:
F_17 ( 1 ) ;
V_2 = NULL ;
}
F_18 ( L_2 ,
V_18 , V_19 , F_20 ( V_20 ) , V_10 , F_20 ( V_21 ) , V_25 , V_2 ) ;
return V_2 ;
}
static struct V_1 *
F_26 ( struct V_7 * V_8 , T_1 V_13 , T_3 V_38 ,
struct V_1 * V_2 )
{
const struct V_39 * V_40 = F_27 ( V_8 ) ;
struct V_41 V_42 , * V_43 ;
V_43 = F_28 ( V_8 , F_29 ( V_8 ) , sizeof( V_42 ) , & V_42 ) ;
if ( V_43 == NULL ) {
F_5 ( F_4 ( V_2 ) ) ;
return NULL ;
}
if ( V_43 -> V_44 && ! V_43 -> V_45 && ! V_43 -> V_46 && ! V_43 -> V_47 ) {
struct V_1 * V_48 ;
V_48 = F_12 ( F_30 ( V_8 -> V_14 ) , V_40 -> V_18 ,
V_40 -> V_19 , V_13 ? V_13 : V_40 -> V_10 ,
V_43 -> V_49 , V_38 ? V_38 : V_43 -> V_50 ,
V_8 -> V_14 , V_27 ) ;
if ( V_48 ) {
F_31 ( F_4 ( V_2 ) , & V_51 ) ;
F_5 ( F_4 ( V_2 ) ) ;
V_2 = V_48 ;
}
}
return V_2 ;
}
static void
F_32 ( struct V_7 * V_8 , struct V_1 * V_2 )
{
F_33 ( V_8 ) ;
V_8 -> V_2 = V_2 ;
V_8 -> V_52 = V_53 ;
}
static unsigned int
F_34 ( struct V_7 * V_8 , T_1 V_13 , T_3 V_38 ,
T_4 V_54 , T_4 V_55 )
{
const struct V_39 * V_40 = F_27 ( V_8 ) ;
struct V_56 V_42 , * V_43 ;
struct V_1 * V_2 ;
V_43 = F_28 ( V_8 , F_29 ( V_8 ) , sizeof( V_42 ) , & V_42 ) ;
if ( V_43 == NULL )
return V_57 ;
V_2 = F_12 ( F_30 ( V_8 -> V_14 ) , V_40 -> V_18 ,
V_40 -> V_19 , V_40 -> V_10 ,
V_43 -> V_49 , V_43 -> V_50 ,
V_8 -> V_14 , V_30 ) ;
V_13 = F_6 ( V_8 , V_13 , V_40 -> V_10 ) ;
if ( ! V_38 )
V_38 = V_43 -> V_50 ;
if ( V_2 && V_2 -> V_3 == V_4 )
V_2 = F_26 ( V_8 , V_13 , V_38 , V_2 ) ;
else if ( ! V_2 )
V_2 = F_12 ( F_30 ( V_8 -> V_14 ) , V_40 -> V_18 ,
V_40 -> V_19 , V_13 ,
V_43 -> V_49 , V_38 ,
V_8 -> V_14 , V_27 ) ;
if ( V_2 && F_1 ( V_2 ) ) {
V_8 -> V_58 = ( V_8 -> V_58 & ~ V_54 ) ^ V_55 ;
F_18 ( L_3 ,
V_40 -> V_18 , & V_40 -> V_10 , F_20 ( V_43 -> V_50 ) ,
& V_13 , F_20 ( V_38 ) , V_8 -> V_58 ) ;
F_32 ( V_8 , V_2 ) ;
return V_59 ;
}
F_18 ( L_4 ,
V_40 -> V_18 , & V_40 -> V_19 , F_20 ( V_43 -> V_49 ) ,
& V_40 -> V_10 , F_20 ( V_43 -> V_50 ) , V_8 -> V_58 ) ;
return V_57 ;
}
static unsigned int
F_35 ( struct V_7 * V_8 , const struct V_60 * V_61 )
{
const struct V_62 * V_63 = V_61 -> V_64 ;
return F_34 ( V_8 , V_63 -> V_13 , V_63 -> V_38 , V_63 -> V_54 , V_63 -> V_55 ) ;
}
static unsigned int
F_36 ( struct V_7 * V_8 , const struct V_60 * V_61 )
{
const struct V_65 * V_63 = V_61 -> V_64 ;
return F_34 ( V_8 , V_63 -> V_13 . V_66 , V_63 -> V_38 , V_63 -> V_54 , V_63 -> V_55 ) ;
}
static inline const struct V_36 *
F_37 ( struct V_7 * V_8 , const struct V_36 * V_9 ,
const struct V_36 * V_10 )
{
struct V_67 * V_12 ;
struct V_68 * V_15 ;
struct V_36 * V_13 ;
if ( ! F_25 ( V_9 ) )
return V_9 ;
V_13 = NULL ;
F_7 () ;
V_12 = F_38 ( V_8 -> V_14 ) ;
if ( V_12 )
F_39 (ifa, &indev->addr_list, if_list) {
if ( V_15 -> V_69 & ( V_70 | V_71 ) )
continue;
V_13 = & V_15 -> V_72 ;
break;
}
F_11 () ;
return V_13 ? V_13 : V_10 ;
}
static struct V_1 *
F_40 ( struct V_7 * V_8 , int V_73 , int V_74 ,
const struct V_60 * V_61 ,
struct V_1 * V_2 )
{
const struct V_75 * V_40 = F_41 ( V_8 ) ;
struct V_41 V_42 , * V_43 ;
const struct V_65 * V_63 = V_61 -> V_64 ;
V_43 = F_28 ( V_8 , V_74 , sizeof( V_42 ) , & V_42 ) ;
if ( V_43 == NULL ) {
F_5 ( F_4 ( V_2 ) ) ;
return NULL ;
}
if ( V_43 -> V_44 && ! V_43 -> V_45 && ! V_43 -> V_46 && ! V_43 -> V_47 ) {
struct V_1 * V_48 ;
V_48 = F_21 ( F_30 ( V_8 -> V_14 ) , V_73 ,
& V_40 -> V_19 ,
F_37 ( V_8 , & V_63 -> V_13 . V_76 , & V_40 -> V_10 ) ,
V_43 -> V_49 ,
V_63 -> V_38 ? V_63 -> V_38 : V_43 -> V_50 ,
V_8 -> V_14 , V_27 ) ;
if ( V_48 ) {
F_31 ( F_4 ( V_2 ) , & V_51 ) ;
F_5 ( F_4 ( V_2 ) ) ;
V_2 = V_48 ;
}
}
return V_2 ;
}
static unsigned int
F_42 ( struct V_7 * V_8 , const struct V_60 * V_61 )
{
const struct V_75 * V_40 = F_41 ( V_8 ) ;
const struct V_65 * V_63 = V_61 -> V_64 ;
struct V_56 V_42 , * V_43 ;
struct V_1 * V_2 ;
const struct V_36 * V_13 ;
T_3 V_38 ;
int V_74 = 0 ;
int V_73 ;
V_73 = F_43 ( V_8 , & V_74 , - 1 , NULL , NULL ) ;
if ( V_73 < 0 ) {
F_18 ( L_5 ) ;
return V_57 ;
}
V_43 = F_28 ( V_8 , V_74 , sizeof( V_42 ) , & V_42 ) ;
if ( V_43 == NULL ) {
F_18 ( L_6 ) ;
return V_57 ;
}
V_2 = F_21 ( F_30 ( V_8 -> V_14 ) , V_73 ,
& V_40 -> V_19 , & V_40 -> V_10 ,
V_43 -> V_49 , V_43 -> V_50 ,
V_61 -> V_23 , V_30 ) ;
V_13 = F_37 ( V_8 , & V_63 -> V_13 . V_76 , & V_40 -> V_10 ) ;
V_38 = V_63 -> V_38 ? V_63 -> V_38 : V_43 -> V_50 ;
if ( V_2 && V_2 -> V_3 == V_4 )
V_2 = F_40 ( V_8 , V_73 , V_74 , V_61 , V_2 ) ;
else if ( ! V_2 )
V_2 = F_21 ( F_30 ( V_8 -> V_14 ) , V_73 ,
& V_40 -> V_19 , V_13 ,
V_43 -> V_49 , V_38 ,
V_61 -> V_23 , V_27 ) ;
if ( V_2 && F_1 ( V_2 ) ) {
V_8 -> V_58 = ( V_8 -> V_58 & ~ V_63 -> V_54 ) ^ V_63 -> V_55 ;
F_18 ( L_7 ,
V_73 , & V_40 -> V_19 , F_20 ( V_43 -> V_49 ) ,
V_13 , F_20 ( V_38 ) , V_8 -> V_58 ) ;
F_32 ( V_8 , V_2 ) ;
return V_59 ;
}
F_18 ( L_8 ,
V_73 , & V_40 -> V_19 , F_20 ( V_43 -> V_49 ) ,
& V_40 -> V_10 , F_20 ( V_43 -> V_50 ) , V_8 -> V_58 ) ;
return V_57 ;
}
static int F_44 ( const struct V_77 * V_61 )
{
const struct V_78 * V_79 = V_61 -> V_80 ;
if ( ( V_79 -> V_81 == V_26 || V_79 -> V_81 == V_31 ) &&
! ( V_79 -> V_82 & V_83 ) )
return 0 ;
F_45 ( L_9
L_10 ) ;
return - V_84 ;
}
static int F_46 ( const struct V_77 * V_61 )
{
const struct V_85 * V_79 = V_61 -> V_80 ;
if ( ( V_79 -> V_81 == V_26 || V_79 -> V_81 == V_31 )
&& ! ( V_79 -> V_82 & V_86 ) )
return 0 ;
F_45 ( L_9
L_10 ) ;
return - V_84 ;
}
static int T_5 F_47 ( void )
{
F_48 () ;
#ifdef F_49
F_50 () ;
#endif
return F_51 ( V_87 , F_52 ( V_87 ) ) ;
}
static void T_6 F_53 ( void )
{
F_54 ( V_87 , F_52 ( V_87 ) ) ;
}
