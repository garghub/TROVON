static bool F_1 ( struct V_1 * V_2 )
{
switch ( V_2 -> V_3 ) {
case V_4 :
if ( F_2 ( V_2 ) -> V_5 )
return true ;
break;
case V_6 :
if ( F_3 ( F_4 ( V_2 ) ) -> V_7 )
return true ;
break;
default:
if ( F_5 ( V_2 ) -> V_8 )
return true ;
}
F_6 ( V_2 ) ;
return false ;
}
static inline T_1
F_7 ( struct V_9 * V_10 , T_1 V_11 , T_1 V_12 )
{
struct V_13 * V_14 ;
T_1 V_15 ;
if ( V_11 )
return V_11 ;
V_15 = 0 ;
F_8 () ;
V_14 = F_9 ( V_10 -> V_16 ) ;
F_10 (indev) {
V_15 = V_17 -> V_18 ;
break;
} F_11 ( V_14 ) ;
F_12 () ;
return V_15 ? V_15 : V_12 ;
}
static inline struct V_1 *
F_13 ( struct V_19 * V_19 , const T_2 V_20 ,
const T_1 V_21 , const T_1 V_12 ,
const T_3 V_22 , const T_3 V_23 ,
const struct V_24 * V_25 ,
const enum V_26 V_27 )
{
struct V_1 * V_2 ;
switch ( V_20 ) {
case V_28 :
switch ( V_27 ) {
case V_29 :
V_2 = F_14 ( V_19 , & V_30 ,
V_21 , V_22 ,
V_12 , V_23 ,
V_25 -> V_31 ) ;
break;
case V_32 :
V_2 = F_15 ( V_19 , & V_30 ,
V_21 , V_22 , V_12 , V_23 ,
V_25 -> V_31 ) ;
break;
default:
F_16 () ;
}
break;
case V_33 :
V_2 = F_17 ( V_19 , V_21 , V_22 , V_12 , V_23 ,
V_25 -> V_31 ) ;
if ( V_2 ) {
int V_34 = ( V_2 -> V_3 == V_35 ) ;
int V_36 = ( F_5 ( V_2 ) -> V_37 == 0 ) ;
if ( ( V_27 == V_32 && ( ! V_34 || V_36 ) ) ||
( V_27 == V_29 && V_34 ) ) {
F_18 ( V_2 ) ;
V_2 = NULL ;
}
}
break;
default:
F_19 ( 1 ) ;
V_2 = NULL ;
}
F_20 ( L_1 ,
V_20 , F_21 ( V_21 ) , F_22 ( V_22 ) , F_21 ( V_12 ) , F_22 ( V_23 ) , V_27 , V_2 ) ;
return V_2 ;
}
static inline struct V_1 *
F_23 ( struct V_19 * V_19 , const T_2 V_20 ,
const struct V_38 * V_21 , const struct V_38 * V_12 ,
const T_3 V_22 , const T_3 V_23 ,
const struct V_24 * V_25 ,
const enum V_26 V_27 )
{
struct V_1 * V_2 ;
switch ( V_20 ) {
case V_28 :
switch ( V_27 ) {
case V_29 :
V_2 = F_24 ( V_19 , & V_30 ,
V_21 , V_22 ,
V_12 , F_22 ( V_23 ) ,
V_25 -> V_31 ) ;
break;
case V_32 :
V_2 = F_25 ( V_19 , & V_30 ,
V_21 , V_22 , V_12 , F_22 ( V_23 ) ,
V_25 -> V_31 ) ;
break;
default:
F_16 () ;
}
break;
case V_33 :
V_2 = F_26 ( V_19 , V_21 , V_22 , V_12 , V_23 ,
V_25 -> V_31 ) ;
if ( V_2 ) {
int V_34 = ( V_2 -> V_3 == V_35 ) ;
int V_36 = F_27 ( & V_2 -> V_39 ) ;
if ( ( V_27 == V_32 && ( ! V_34 || V_36 ) ) ||
( V_27 == V_29 && V_34 ) ) {
F_18 ( V_2 ) ;
V_2 = NULL ;
}
}
break;
default:
F_19 ( 1 ) ;
V_2 = NULL ;
}
F_20 ( L_2 ,
V_20 , V_21 , F_22 ( V_22 ) , V_12 , F_22 ( V_23 ) , V_27 , V_2 ) ;
return V_2 ;
}
static struct V_1 *
F_28 ( struct V_19 * V_19 , struct V_9 * V_10 ,
T_1 V_15 , T_3 V_40 , struct V_1 * V_2 )
{
const struct V_41 * V_42 = F_29 ( V_10 ) ;
struct V_43 V_44 , * V_45 ;
V_45 = F_30 ( V_10 , F_31 ( V_10 ) , sizeof( V_44 ) , & V_44 ) ;
if ( V_45 == NULL ) {
F_32 ( F_2 ( V_2 ) ) ;
return NULL ;
}
if ( V_45 -> V_46 && ! V_45 -> V_47 && ! V_45 -> V_48 && ! V_45 -> V_49 ) {
struct V_1 * V_50 ;
V_50 = F_13 ( V_19 , V_42 -> V_20 ,
V_42 -> V_21 , V_15 ? V_15 : V_42 -> V_12 ,
V_45 -> V_51 , V_40 ? V_40 : V_45 -> V_52 ,
V_10 -> V_16 , V_29 ) ;
if ( V_50 ) {
F_33 ( F_2 ( V_2 ) ) ;
V_2 = V_50 ;
}
}
return V_2 ;
}
static void
F_34 ( struct V_9 * V_10 , struct V_1 * V_2 )
{
F_35 ( V_10 ) ;
V_10 -> V_2 = V_2 ;
V_10 -> V_53 = V_54 ;
}
static unsigned int
F_36 ( struct V_19 * V_19 , struct V_9 * V_10 , T_1 V_15 , T_3 V_40 ,
T_4 V_55 , T_4 V_56 )
{
const struct V_41 * V_42 = F_29 ( V_10 ) ;
struct V_57 V_44 , * V_45 ;
struct V_1 * V_2 ;
V_45 = F_30 ( V_10 , F_31 ( V_10 ) , sizeof( V_44 ) , & V_44 ) ;
if ( V_45 == NULL )
return V_58 ;
V_2 = F_13 ( V_19 , V_42 -> V_20 ,
V_42 -> V_21 , V_42 -> V_12 ,
V_45 -> V_51 , V_45 -> V_52 ,
V_10 -> V_16 , V_32 ) ;
V_15 = F_7 ( V_10 , V_15 , V_42 -> V_12 ) ;
if ( ! V_40 )
V_40 = V_45 -> V_52 ;
if ( V_2 && V_2 -> V_3 == V_4 )
V_2 = F_28 ( V_19 , V_10 , V_15 , V_40 , V_2 ) ;
else if ( ! V_2 )
V_2 = F_13 ( V_19 , V_42 -> V_20 ,
V_42 -> V_21 , V_15 ,
V_45 -> V_51 , V_40 ,
V_10 -> V_16 , V_29 ) ;
if ( V_2 && F_1 ( V_2 ) ) {
V_10 -> V_59 = ( V_10 -> V_59 & ~ V_55 ) ^ V_56 ;
F_20 ( L_3 ,
V_42 -> V_20 , & V_42 -> V_12 , F_22 ( V_45 -> V_52 ) ,
& V_15 , F_22 ( V_40 ) , V_10 -> V_59 ) ;
F_34 ( V_10 , V_2 ) ;
return V_60 ;
}
F_20 ( L_4 ,
V_42 -> V_20 , & V_42 -> V_21 , F_22 ( V_45 -> V_51 ) ,
& V_42 -> V_12 , F_22 ( V_45 -> V_52 ) , V_10 -> V_59 ) ;
return V_58 ;
}
static unsigned int
F_37 ( struct V_9 * V_10 , const struct V_61 * V_62 )
{
const struct V_63 * V_64 = V_62 -> V_65 ;
return F_36 ( V_62 -> V_19 , V_10 , V_64 -> V_15 , V_64 -> V_40 , V_64 -> V_55 , V_64 -> V_56 ) ;
}
static unsigned int
F_38 ( struct V_9 * V_10 , const struct V_61 * V_62 )
{
const struct V_66 * V_64 = V_62 -> V_65 ;
return F_36 ( V_62 -> V_19 , V_10 , V_64 -> V_15 . V_67 , V_64 -> V_40 , V_64 -> V_55 , V_64 -> V_56 ) ;
}
static inline const struct V_38 *
F_39 ( struct V_9 * V_10 , const struct V_38 * V_11 ,
const struct V_38 * V_12 )
{
struct V_68 * V_14 ;
struct V_69 * V_17 ;
struct V_38 * V_15 ;
if ( ! F_27 ( V_11 ) )
return V_11 ;
V_15 = NULL ;
F_8 () ;
V_14 = F_40 ( V_10 -> V_16 ) ;
if ( V_14 )
F_41 (ifa, &indev->addr_list, if_list) {
if ( V_17 -> V_70 & ( V_71 | V_72 ) )
continue;
V_15 = & V_17 -> V_73 ;
break;
}
F_12 () ;
return V_15 ? V_15 : V_12 ;
}
static struct V_1 *
F_42 ( struct V_9 * V_10 , int V_74 , int V_75 ,
const struct V_61 * V_62 ,
struct V_1 * V_2 )
{
const struct V_76 * V_42 = F_43 ( V_10 ) ;
struct V_43 V_44 , * V_45 ;
const struct V_66 * V_64 = V_62 -> V_65 ;
V_45 = F_30 ( V_10 , V_75 , sizeof( V_44 ) , & V_44 ) ;
if ( V_45 == NULL ) {
F_32 ( F_2 ( V_2 ) ) ;
return NULL ;
}
if ( V_45 -> V_46 && ! V_45 -> V_47 && ! V_45 -> V_48 && ! V_45 -> V_49 ) {
struct V_1 * V_50 ;
V_50 = F_23 ( V_62 -> V_19 , V_74 ,
& V_42 -> V_21 ,
F_39 ( V_10 , & V_64 -> V_15 . V_77 , & V_42 -> V_12 ) ,
V_45 -> V_51 ,
V_64 -> V_40 ? V_64 -> V_40 : V_45 -> V_52 ,
V_10 -> V_16 , V_29 ) ;
if ( V_50 ) {
F_33 ( F_2 ( V_2 ) ) ;
V_2 = V_50 ;
}
}
return V_2 ;
}
static unsigned int
F_44 ( struct V_9 * V_10 , const struct V_61 * V_62 )
{
const struct V_76 * V_42 = F_43 ( V_10 ) ;
const struct V_66 * V_64 = V_62 -> V_65 ;
struct V_57 V_44 , * V_45 ;
struct V_1 * V_2 ;
const struct V_38 * V_15 ;
T_3 V_40 ;
int V_75 = 0 ;
int V_74 ;
V_74 = F_45 ( V_10 , & V_75 , - 1 , NULL , NULL ) ;
if ( V_74 < 0 ) {
F_20 ( L_5 ) ;
return V_58 ;
}
V_45 = F_30 ( V_10 , V_75 , sizeof( V_44 ) , & V_44 ) ;
if ( V_45 == NULL ) {
F_20 ( L_6 ) ;
return V_58 ;
}
V_2 = F_23 ( V_62 -> V_19 , V_74 ,
& V_42 -> V_21 , & V_42 -> V_12 ,
V_45 -> V_51 , V_45 -> V_52 ,
V_62 -> V_25 , V_32 ) ;
V_15 = F_39 ( V_10 , & V_64 -> V_15 . V_77 , & V_42 -> V_12 ) ;
V_40 = V_64 -> V_40 ? V_64 -> V_40 : V_45 -> V_52 ;
if ( V_2 && V_2 -> V_3 == V_4 )
V_2 = F_42 ( V_10 , V_74 , V_75 , V_62 , V_2 ) ;
else if ( ! V_2 )
V_2 = F_23 ( V_62 -> V_19 , V_74 ,
& V_42 -> V_21 , V_15 ,
V_45 -> V_51 , V_40 ,
V_62 -> V_25 , V_29 ) ;
if ( V_2 && F_1 ( V_2 ) ) {
V_10 -> V_59 = ( V_10 -> V_59 & ~ V_64 -> V_55 ) ^ V_64 -> V_56 ;
F_20 ( L_7 ,
V_74 , & V_42 -> V_21 , F_22 ( V_45 -> V_51 ) ,
V_15 , F_22 ( V_40 ) , V_10 -> V_59 ) ;
F_34 ( V_10 , V_2 ) ;
return V_60 ;
}
F_20 ( L_8 ,
V_74 , & V_42 -> V_21 , F_22 ( V_45 -> V_51 ) ,
& V_42 -> V_12 , F_22 ( V_45 -> V_52 ) , V_10 -> V_59 ) ;
return V_58 ;
}
static int F_46 ( const struct V_78 * V_62 )
{
const struct V_79 * V_80 = V_62 -> V_81 ;
if ( ( V_80 -> V_82 == V_28 || V_80 -> V_82 == V_33 ) &&
! ( V_80 -> V_83 & V_84 ) )
return 0 ;
F_47 ( L_9
L_10 ) ;
return - V_85 ;
}
static int F_48 ( const struct V_78 * V_62 )
{
const struct V_86 * V_80 = V_62 -> V_81 ;
if ( ( V_80 -> V_82 == V_28 || V_80 -> V_82 == V_33 )
&& ! ( V_80 -> V_83 & V_87 ) )
return 0 ;
F_47 ( L_9
L_10 ) ;
return - V_85 ;
}
static int T_5 F_49 ( void )
{
F_50 () ;
#ifdef F_51
F_52 () ;
#endif
return F_53 ( V_88 , F_54 ( V_88 ) ) ;
}
static void T_6 F_55 ( void )
{
F_56 ( V_88 , F_54 ( V_88 ) ) ;
}
