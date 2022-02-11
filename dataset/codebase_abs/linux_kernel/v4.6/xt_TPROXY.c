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
F_13 ( struct V_19 * V_19 , struct V_9 * V_10 , void * V_20 ,
const T_2 V_21 ,
const T_1 V_22 , const T_1 V_12 ,
const T_3 V_23 , const T_3 V_24 ,
const struct V_25 * V_26 ,
const enum V_27 V_28 )
{
struct V_1 * V_2 ;
struct V_29 * V_30 ;
switch ( V_21 ) {
case V_31 :
switch ( V_28 ) {
case V_32 :
V_30 = V_20 ;
V_2 = F_14 ( V_19 , & V_33 , V_10 ,
F_15 ( V_10 ) +
F_16 ( V_30 ) ,
V_22 , V_23 ,
V_12 , V_24 ,
V_26 -> V_34 ) ;
break;
case V_35 :
V_2 = F_17 ( V_19 , & V_33 ,
V_22 , V_23 , V_12 , V_24 ,
V_26 -> V_34 ) ;
break;
default:
F_18 () ;
}
break;
case V_36 :
V_2 = F_19 ( V_19 , V_22 , V_23 , V_12 , V_24 ,
V_26 -> V_34 ) ;
if ( V_2 ) {
int V_37 = ( V_2 -> V_3 == V_38 ) ;
int V_39 = ( F_5 ( V_2 ) -> V_40 == 0 ) ;
if ( ( V_28 == V_35 && ( ! V_37 || V_39 ) ) ||
( V_28 == V_32 && V_37 ) ) {
F_20 ( V_2 ) ;
V_2 = NULL ;
}
}
break;
default:
F_21 ( 1 ) ;
V_2 = NULL ;
}
F_22 ( L_1 ,
V_21 , F_23 ( V_22 ) , F_24 ( V_23 ) , F_23 ( V_12 ) , F_24 ( V_24 ) , V_28 , V_2 ) ;
return V_2 ;
}
static inline struct V_1 *
F_25 ( struct V_19 * V_19 , struct V_9 * V_10 , int V_41 , void * V_20 ,
const T_2 V_21 ,
const struct V_42 * V_22 , const struct V_42 * V_12 ,
const T_3 V_23 , const T_3 V_24 ,
const struct V_25 * V_26 ,
const enum V_27 V_28 )
{
struct V_1 * V_2 ;
struct V_29 * V_30 ;
switch ( V_21 ) {
case V_31 :
switch ( V_28 ) {
case V_32 :
V_30 = V_20 ;
V_2 = F_26 ( V_19 , & V_33 , V_10 ,
V_41 + F_16 ( V_30 ) ,
V_22 , V_23 ,
V_12 , F_24 ( V_24 ) ,
V_26 -> V_34 ) ;
break;
case V_35 :
V_2 = F_27 ( V_19 , & V_33 ,
V_22 , V_23 , V_12 , F_24 ( V_24 ) ,
V_26 -> V_34 ) ;
break;
default:
F_18 () ;
}
break;
case V_36 :
V_2 = F_28 ( V_19 , V_22 , V_23 , V_12 , V_24 ,
V_26 -> V_34 ) ;
if ( V_2 ) {
int V_37 = ( V_2 -> V_3 == V_38 ) ;
int V_39 = F_29 ( & V_2 -> V_43 ) ;
if ( ( V_28 == V_35 && ( ! V_37 || V_39 ) ) ||
( V_28 == V_32 && V_37 ) ) {
F_20 ( V_2 ) ;
V_2 = NULL ;
}
}
break;
default:
F_21 ( 1 ) ;
V_2 = NULL ;
}
F_22 ( L_2 ,
V_21 , V_22 , F_24 ( V_23 ) , V_12 , F_24 ( V_24 ) , V_28 , V_2 ) ;
return V_2 ;
}
static struct V_1 *
F_30 ( struct V_19 * V_19 , struct V_9 * V_10 ,
T_1 V_15 , T_3 V_44 , struct V_1 * V_2 )
{
const struct V_45 * V_46 = F_31 ( V_10 ) ;
struct V_29 V_47 , * V_20 ;
V_20 = F_32 ( V_10 , F_15 ( V_10 ) , sizeof( V_47 ) , & V_47 ) ;
if ( V_20 == NULL ) {
F_33 ( F_2 ( V_2 ) ) ;
return NULL ;
}
if ( V_20 -> V_48 && ! V_20 -> V_49 && ! V_20 -> V_50 && ! V_20 -> V_51 ) {
struct V_1 * V_52 ;
V_52 = F_13 ( V_19 , V_10 , V_20 , V_46 -> V_21 ,
V_46 -> V_22 , V_15 ? V_15 : V_46 -> V_12 ,
V_20 -> V_53 , V_44 ? V_44 : V_20 -> V_54 ,
V_10 -> V_16 , V_32 ) ;
if ( V_52 ) {
F_34 ( F_2 ( V_2 ) ) ;
V_2 = V_52 ;
}
}
return V_2 ;
}
static void
F_35 ( struct V_9 * V_10 , struct V_1 * V_2 )
{
F_36 ( V_10 ) ;
V_10 -> V_2 = V_2 ;
V_10 -> V_55 = V_56 ;
}
static unsigned int
F_37 ( struct V_19 * V_19 , struct V_9 * V_10 , T_1 V_15 , T_3 V_44 ,
T_4 V_57 , T_4 V_58 )
{
const struct V_45 * V_46 = F_31 ( V_10 ) ;
struct V_59 V_47 , * V_20 ;
struct V_1 * V_2 ;
V_20 = F_32 ( V_10 , F_15 ( V_10 ) , sizeof( V_47 ) , & V_47 ) ;
if ( V_20 == NULL )
return V_60 ;
V_2 = F_13 ( V_19 , V_10 , V_20 , V_46 -> V_21 ,
V_46 -> V_22 , V_46 -> V_12 ,
V_20 -> V_53 , V_20 -> V_54 ,
V_10 -> V_16 , V_35 ) ;
V_15 = F_7 ( V_10 , V_15 , V_46 -> V_12 ) ;
if ( ! V_44 )
V_44 = V_20 -> V_54 ;
if ( V_2 && V_2 -> V_3 == V_4 )
V_2 = F_30 ( V_19 , V_10 , V_15 , V_44 , V_2 ) ;
else if ( ! V_2 )
V_2 = F_13 ( V_19 , V_10 , V_20 , V_46 -> V_21 ,
V_46 -> V_22 , V_15 ,
V_20 -> V_53 , V_44 ,
V_10 -> V_16 , V_32 ) ;
if ( V_2 && F_1 ( V_2 ) ) {
V_10 -> V_61 = ( V_10 -> V_61 & ~ V_57 ) ^ V_58 ;
F_22 ( L_3 ,
V_46 -> V_21 , & V_46 -> V_12 , F_24 ( V_20 -> V_54 ) ,
& V_15 , F_24 ( V_44 ) , V_10 -> V_61 ) ;
F_35 ( V_10 , V_2 ) ;
return V_62 ;
}
F_22 ( L_4 ,
V_46 -> V_21 , & V_46 -> V_22 , F_24 ( V_20 -> V_53 ) ,
& V_46 -> V_12 , F_24 ( V_20 -> V_54 ) , V_10 -> V_61 ) ;
return V_60 ;
}
static unsigned int
F_38 ( struct V_9 * V_10 , const struct V_63 * V_64 )
{
const struct V_65 * V_66 = V_64 -> V_67 ;
return F_37 ( V_64 -> V_19 , V_10 , V_66 -> V_15 , V_66 -> V_44 , V_66 -> V_57 , V_66 -> V_58 ) ;
}
static unsigned int
F_39 ( struct V_9 * V_10 , const struct V_63 * V_64 )
{
const struct V_68 * V_66 = V_64 -> V_67 ;
return F_37 ( V_64 -> V_19 , V_10 , V_66 -> V_15 . V_69 , V_66 -> V_44 , V_66 -> V_57 , V_66 -> V_58 ) ;
}
static inline const struct V_42 *
F_40 ( struct V_9 * V_10 , const struct V_42 * V_11 ,
const struct V_42 * V_12 )
{
struct V_70 * V_14 ;
struct V_71 * V_17 ;
struct V_42 * V_15 ;
if ( ! F_29 ( V_11 ) )
return V_11 ;
V_15 = NULL ;
F_8 () ;
V_14 = F_41 ( V_10 -> V_16 ) ;
if ( V_14 )
F_42 (ifa, &indev->addr_list, if_list) {
if ( V_17 -> V_72 & ( V_73 | V_74 ) )
continue;
V_15 = & V_17 -> V_75 ;
break;
}
F_12 () ;
return V_15 ? V_15 : V_12 ;
}
static struct V_1 *
F_43 ( struct V_9 * V_10 , int V_76 , int V_41 ,
const struct V_63 * V_64 ,
struct V_1 * V_2 )
{
const struct V_77 * V_46 = F_44 ( V_10 ) ;
struct V_29 V_47 , * V_20 ;
const struct V_68 * V_66 = V_64 -> V_67 ;
V_20 = F_32 ( V_10 , V_41 , sizeof( V_47 ) , & V_47 ) ;
if ( V_20 == NULL ) {
F_33 ( F_2 ( V_2 ) ) ;
return NULL ;
}
if ( V_20 -> V_48 && ! V_20 -> V_49 && ! V_20 -> V_50 && ! V_20 -> V_51 ) {
struct V_1 * V_52 ;
V_52 = F_25 ( V_64 -> V_19 , V_10 , V_41 , V_20 , V_76 ,
& V_46 -> V_22 ,
F_40 ( V_10 , & V_66 -> V_15 . V_78 , & V_46 -> V_12 ) ,
V_20 -> V_53 ,
V_66 -> V_44 ? V_66 -> V_44 : V_20 -> V_54 ,
V_10 -> V_16 , V_32 ) ;
if ( V_52 ) {
F_34 ( F_2 ( V_2 ) ) ;
V_2 = V_52 ;
}
}
return V_2 ;
}
static unsigned int
F_45 ( struct V_9 * V_10 , const struct V_63 * V_64 )
{
const struct V_77 * V_46 = F_44 ( V_10 ) ;
const struct V_68 * V_66 = V_64 -> V_67 ;
struct V_59 V_47 , * V_20 ;
struct V_1 * V_2 ;
const struct V_42 * V_15 ;
T_3 V_44 ;
int V_41 = 0 ;
int V_76 ;
V_76 = F_46 ( V_10 , & V_41 , - 1 , NULL , NULL ) ;
if ( V_76 < 0 ) {
F_22 ( L_5 ) ;
return V_60 ;
}
V_20 = F_32 ( V_10 , V_41 , sizeof( V_47 ) , & V_47 ) ;
if ( V_20 == NULL ) {
F_22 ( L_6 ) ;
return V_60 ;
}
V_2 = F_25 ( V_64 -> V_19 , V_10 , V_41 , V_20 , V_76 ,
& V_46 -> V_22 , & V_46 -> V_12 ,
V_20 -> V_53 , V_20 -> V_54 ,
V_64 -> V_26 , V_35 ) ;
V_15 = F_40 ( V_10 , & V_66 -> V_15 . V_78 , & V_46 -> V_12 ) ;
V_44 = V_66 -> V_44 ? V_66 -> V_44 : V_20 -> V_54 ;
if ( V_2 && V_2 -> V_3 == V_4 )
V_2 = F_43 ( V_10 , V_76 , V_41 , V_64 , V_2 ) ;
else if ( ! V_2 )
V_2 = F_25 ( V_64 -> V_19 , V_10 , V_41 , V_20 ,
V_76 , & V_46 -> V_22 , V_15 ,
V_20 -> V_53 , V_44 ,
V_64 -> V_26 , V_32 ) ;
if ( V_2 && F_1 ( V_2 ) ) {
V_10 -> V_61 = ( V_10 -> V_61 & ~ V_66 -> V_57 ) ^ V_66 -> V_58 ;
F_22 ( L_7 ,
V_76 , & V_46 -> V_22 , F_24 ( V_20 -> V_53 ) ,
V_15 , F_24 ( V_44 ) , V_10 -> V_61 ) ;
F_35 ( V_10 , V_2 ) ;
return V_62 ;
}
F_22 ( L_8 ,
V_76 , & V_46 -> V_22 , F_24 ( V_20 -> V_53 ) ,
& V_46 -> V_12 , F_24 ( V_20 -> V_54 ) , V_10 -> V_61 ) ;
return V_60 ;
}
static int F_47 ( const struct V_79 * V_64 )
{
const struct V_80 * V_81 = V_64 -> V_82 ;
if ( ( V_81 -> V_83 == V_31 || V_81 -> V_83 == V_36 ) &&
! ( V_81 -> V_84 & V_85 ) )
return 0 ;
F_48 ( L_9
L_10 ) ;
return - V_86 ;
}
static int F_49 ( const struct V_79 * V_64 )
{
const struct V_87 * V_81 = V_64 -> V_82 ;
if ( ( V_81 -> V_83 == V_31 || V_81 -> V_83 == V_36 )
&& ! ( V_81 -> V_84 & V_88 ) )
return 0 ;
F_48 ( L_9
L_10 ) ;
return - V_86 ;
}
static int T_5 F_50 ( void )
{
F_51 () ;
#ifdef F_52
F_53 () ;
#endif
return F_54 ( V_89 , F_55 ( V_89 ) ) ;
}
static void T_6 F_56 ( void )
{
F_57 ( V_89 , F_55 ( V_89 ) ) ;
}
