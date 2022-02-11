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
V_14 = F_8 ( V_10 -> V_16 ) ;
F_9 (indev) {
V_15 = V_17 -> V_18 ;
break;
} F_10 ( V_14 ) ;
return V_15 ? V_15 : V_12 ;
}
static inline struct V_1 *
F_11 ( struct V_19 * V_19 , struct V_9 * V_10 , void * V_20 ,
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
V_2 = F_12 ( V_19 , & V_33 , V_10 ,
F_13 ( V_10 ) +
F_14 ( V_30 ) ,
V_22 , V_23 ,
V_12 , V_24 ,
V_26 -> V_34 , 0 ) ;
if ( V_2 && ! F_15 ( & V_2 -> V_35 ) )
V_2 = NULL ;
break;
case V_36 :
V_2 = F_16 ( V_19 , & V_33 ,
V_22 , V_23 , V_12 , V_24 ,
V_26 -> V_34 ) ;
break;
default:
F_17 () ;
}
break;
case V_37 :
V_2 = F_18 ( V_19 , V_22 , V_23 , V_12 , V_24 ,
V_26 -> V_34 ) ;
if ( V_2 ) {
int V_38 = ( V_2 -> V_3 == V_39 ) ;
int V_40 = ( F_5 ( V_2 ) -> V_41 == 0 ) ;
if ( ( V_28 == V_36 && ( ! V_38 || V_40 ) ) ||
( V_28 == V_32 && V_38 ) ) {
F_19 ( V_2 ) ;
V_2 = NULL ;
}
}
break;
default:
F_20 ( 1 ) ;
V_2 = NULL ;
}
F_21 ( L_1 ,
V_21 , F_22 ( V_22 ) , F_23 ( V_23 ) , F_22 ( V_12 ) , F_23 ( V_24 ) , V_28 , V_2 ) ;
return V_2 ;
}
static inline struct V_1 *
F_24 ( struct V_19 * V_19 , struct V_9 * V_10 , int V_42 , void * V_20 ,
const T_2 V_21 ,
const struct V_43 * V_22 , const struct V_43 * V_12 ,
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
V_2 = F_25 ( V_19 , & V_33 , V_10 ,
V_42 + F_14 ( V_30 ) ,
V_22 , V_23 ,
V_12 , F_23 ( V_24 ) ,
V_26 -> V_34 , 0 ) ;
if ( V_2 && ! F_15 ( & V_2 -> V_35 ) )
V_2 = NULL ;
break;
case V_36 :
V_2 = F_26 ( V_19 , & V_33 ,
V_22 , V_23 , V_12 , F_23 ( V_24 ) ,
V_26 -> V_34 , 0 ) ;
break;
default:
F_17 () ;
}
break;
case V_37 :
V_2 = F_27 ( V_19 , V_22 , V_23 , V_12 , V_24 ,
V_26 -> V_34 ) ;
if ( V_2 ) {
int V_38 = ( V_2 -> V_3 == V_39 ) ;
int V_40 = F_28 ( & V_2 -> V_44 ) ;
if ( ( V_28 == V_36 && ( ! V_38 || V_40 ) ) ||
( V_28 == V_32 && V_38 ) ) {
F_19 ( V_2 ) ;
V_2 = NULL ;
}
}
break;
default:
F_20 ( 1 ) ;
V_2 = NULL ;
}
F_21 ( L_2 ,
V_21 , V_22 , F_23 ( V_23 ) , V_12 , F_23 ( V_24 ) , V_28 , V_2 ) ;
return V_2 ;
}
static struct V_1 *
F_29 ( struct V_19 * V_19 , struct V_9 * V_10 ,
T_1 V_15 , T_3 V_45 , struct V_1 * V_2 )
{
const struct V_46 * V_47 = F_30 ( V_10 ) ;
struct V_29 V_48 , * V_20 ;
V_20 = F_31 ( V_10 , F_13 ( V_10 ) , sizeof( V_48 ) , & V_48 ) ;
if ( V_20 == NULL ) {
F_32 ( F_2 ( V_2 ) ) ;
return NULL ;
}
if ( V_20 -> V_49 && ! V_20 -> V_50 && ! V_20 -> V_51 && ! V_20 -> V_52 ) {
struct V_1 * V_53 ;
V_53 = F_11 ( V_19 , V_10 , V_20 , V_47 -> V_21 ,
V_47 -> V_22 , V_15 ? V_15 : V_47 -> V_12 ,
V_20 -> V_54 , V_45 ? V_45 : V_20 -> V_55 ,
V_10 -> V_16 , V_32 ) ;
if ( V_53 ) {
F_33 ( F_2 ( V_2 ) ) ;
V_2 = V_53 ;
}
}
return V_2 ;
}
static void
F_34 ( struct V_9 * V_10 , struct V_1 * V_2 )
{
F_35 ( V_10 ) ;
V_10 -> V_2 = V_2 ;
V_10 -> V_56 = V_57 ;
}
static unsigned int
F_36 ( struct V_19 * V_19 , struct V_9 * V_10 , T_1 V_15 , T_3 V_45 ,
T_4 V_58 , T_4 V_59 )
{
const struct V_46 * V_47 = F_30 ( V_10 ) ;
struct V_60 V_48 , * V_20 ;
struct V_1 * V_2 ;
V_20 = F_31 ( V_10 , F_13 ( V_10 ) , sizeof( V_48 ) , & V_48 ) ;
if ( V_20 == NULL )
return V_61 ;
V_2 = F_11 ( V_19 , V_10 , V_20 , V_47 -> V_21 ,
V_47 -> V_22 , V_47 -> V_12 ,
V_20 -> V_54 , V_20 -> V_55 ,
V_10 -> V_16 , V_36 ) ;
V_15 = F_7 ( V_10 , V_15 , V_47 -> V_12 ) ;
if ( ! V_45 )
V_45 = V_20 -> V_55 ;
if ( V_2 && V_2 -> V_3 == V_4 )
V_2 = F_29 ( V_19 , V_10 , V_15 , V_45 , V_2 ) ;
else if ( ! V_2 )
V_2 = F_11 ( V_19 , V_10 , V_20 , V_47 -> V_21 ,
V_47 -> V_22 , V_15 ,
V_20 -> V_54 , V_45 ,
V_10 -> V_16 , V_32 ) ;
if ( V_2 && F_1 ( V_2 ) ) {
V_10 -> V_62 = ( V_10 -> V_62 & ~ V_58 ) ^ V_59 ;
F_21 ( L_3 ,
V_47 -> V_21 , & V_47 -> V_12 , F_23 ( V_20 -> V_55 ) ,
& V_15 , F_23 ( V_45 ) , V_10 -> V_62 ) ;
F_34 ( V_10 , V_2 ) ;
return V_63 ;
}
F_21 ( L_4 ,
V_47 -> V_21 , & V_47 -> V_22 , F_23 ( V_20 -> V_54 ) ,
& V_47 -> V_12 , F_23 ( V_20 -> V_55 ) , V_10 -> V_62 ) ;
return V_61 ;
}
static unsigned int
F_37 ( struct V_9 * V_10 , const struct V_64 * V_65 )
{
const struct V_66 * V_67 = V_65 -> V_68 ;
return F_36 ( F_38 ( V_65 ) , V_10 , V_67 -> V_15 , V_67 -> V_45 ,
V_67 -> V_58 , V_67 -> V_59 ) ;
}
static unsigned int
F_39 ( struct V_9 * V_10 , const struct V_64 * V_65 )
{
const struct V_69 * V_67 = V_65 -> V_68 ;
return F_36 ( F_38 ( V_65 ) , V_10 , V_67 -> V_15 . V_70 , V_67 -> V_45 ,
V_67 -> V_58 , V_67 -> V_59 ) ;
}
static inline const struct V_43 *
F_40 ( struct V_9 * V_10 , const struct V_43 * V_11 ,
const struct V_43 * V_12 )
{
struct V_71 * V_14 ;
struct V_72 * V_17 ;
struct V_43 * V_15 ;
if ( ! F_28 ( V_11 ) )
return V_11 ;
V_15 = NULL ;
V_14 = F_41 ( V_10 -> V_16 ) ;
if ( V_14 ) {
F_42 ( & V_14 -> V_73 ) ;
F_43 (ifa, &indev->addr_list, if_list) {
if ( V_17 -> V_74 & ( V_75 | V_76 ) )
continue;
V_15 = & V_17 -> V_77 ;
break;
}
F_44 ( & V_14 -> V_73 ) ;
}
return V_15 ? V_15 : V_12 ;
}
static struct V_1 *
F_45 ( struct V_9 * V_10 , int V_78 , int V_42 ,
const struct V_64 * V_65 ,
struct V_1 * V_2 )
{
const struct V_79 * V_47 = F_46 ( V_10 ) ;
struct V_29 V_48 , * V_20 ;
const struct V_69 * V_67 = V_65 -> V_68 ;
V_20 = F_31 ( V_10 , V_42 , sizeof( V_48 ) , & V_48 ) ;
if ( V_20 == NULL ) {
F_32 ( F_2 ( V_2 ) ) ;
return NULL ;
}
if ( V_20 -> V_49 && ! V_20 -> V_50 && ! V_20 -> V_51 && ! V_20 -> V_52 ) {
struct V_1 * V_53 ;
V_53 = F_24 ( F_38 ( V_65 ) , V_10 , V_42 , V_20 , V_78 ,
& V_47 -> V_22 ,
F_40 ( V_10 , & V_67 -> V_15 . V_80 , & V_47 -> V_12 ) ,
V_20 -> V_54 ,
V_67 -> V_45 ? V_67 -> V_45 : V_20 -> V_55 ,
V_10 -> V_16 , V_32 ) ;
if ( V_53 ) {
F_33 ( F_2 ( V_2 ) ) ;
V_2 = V_53 ;
}
}
return V_2 ;
}
static unsigned int
F_47 ( struct V_9 * V_10 , const struct V_64 * V_65 )
{
const struct V_79 * V_47 = F_46 ( V_10 ) ;
const struct V_69 * V_67 = V_65 -> V_68 ;
struct V_60 V_48 , * V_20 ;
struct V_1 * V_2 ;
const struct V_43 * V_15 ;
T_3 V_45 ;
int V_42 = 0 ;
int V_78 ;
V_78 = F_48 ( V_10 , & V_42 , - 1 , NULL , NULL ) ;
if ( V_78 < 0 ) {
F_21 ( L_5 ) ;
return V_61 ;
}
V_20 = F_31 ( V_10 , V_42 , sizeof( V_48 ) , & V_48 ) ;
if ( V_20 == NULL ) {
F_21 ( L_6 ) ;
return V_61 ;
}
V_2 = F_24 ( F_38 ( V_65 ) , V_10 , V_42 , V_20 , V_78 ,
& V_47 -> V_22 , & V_47 -> V_12 ,
V_20 -> V_54 , V_20 -> V_55 ,
F_49 ( V_65 ) , V_36 ) ;
V_15 = F_40 ( V_10 , & V_67 -> V_15 . V_80 , & V_47 -> V_12 ) ;
V_45 = V_67 -> V_45 ? V_67 -> V_45 : V_20 -> V_55 ;
if ( V_2 && V_2 -> V_3 == V_4 )
V_2 = F_45 ( V_10 , V_78 , V_42 , V_65 , V_2 ) ;
else if ( ! V_2 )
V_2 = F_24 ( F_38 ( V_65 ) , V_10 , V_42 , V_20 ,
V_78 , & V_47 -> V_22 , V_15 ,
V_20 -> V_54 , V_45 ,
F_49 ( V_65 ) , V_32 ) ;
if ( V_2 && F_1 ( V_2 ) ) {
V_10 -> V_62 = ( V_10 -> V_62 & ~ V_67 -> V_58 ) ^ V_67 -> V_59 ;
F_21 ( L_7 ,
V_78 , & V_47 -> V_22 , F_23 ( V_20 -> V_54 ) ,
V_15 , F_23 ( V_45 ) , V_10 -> V_62 ) ;
F_34 ( V_10 , V_2 ) ;
return V_63 ;
}
F_21 ( L_8 ,
V_78 , & V_47 -> V_22 , F_23 ( V_20 -> V_54 ) ,
& V_47 -> V_12 , F_23 ( V_20 -> V_55 ) , V_10 -> V_62 ) ;
return V_61 ;
}
static int F_50 ( const struct V_81 * V_65 )
{
const struct V_82 * V_83 = V_65 -> V_84 ;
int V_85 ;
V_85 = F_51 ( V_65 -> V_19 ) ;
if ( V_85 )
return V_85 ;
if ( ( V_83 -> V_86 == V_31 || V_83 -> V_86 == V_37 ) &&
! ( V_83 -> V_87 & V_88 ) )
return 0 ;
F_52 ( L_9
L_10 ) ;
return - V_89 ;
}
static int F_53 ( const struct V_81 * V_65 )
{
const struct V_90 * V_83 = V_65 -> V_84 ;
int V_85 ;
V_85 = F_54 ( V_65 -> V_19 ) ;
if ( V_85 )
return V_85 ;
if ( ( V_83 -> V_86 == V_31 || V_83 -> V_86 == V_37 )
&& ! ( V_83 -> V_87 & V_91 ) )
return 0 ;
F_52 ( L_9
L_10 ) ;
return - V_89 ;
}
static int T_5 F_55 ( void )
{
return F_56 ( V_92 , F_57 ( V_92 ) ) ;
}
static void T_6 F_58 ( void )
{
F_59 ( V_92 , F_57 ( V_92 ) ) ;
}
