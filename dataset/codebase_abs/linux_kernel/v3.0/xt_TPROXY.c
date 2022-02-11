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
static struct V_1 *
F_12 ( struct V_7 * V_8 , T_1 V_13 , T_2 V_17 ,
struct V_1 * V_2 )
{
const struct V_18 * V_19 = F_13 ( V_8 ) ;
struct V_20 V_21 , * V_22 ;
V_22 = F_14 ( V_8 , F_15 ( V_8 ) , sizeof( V_21 ) , & V_21 ) ;
if ( V_22 == NULL ) {
F_5 ( F_4 ( V_2 ) ) ;
return NULL ;
}
if ( V_22 -> V_23 && ! V_22 -> V_24 && ! V_22 -> V_25 && ! V_22 -> V_26 ) {
struct V_1 * V_27 ;
V_27 = F_16 ( F_17 ( V_8 -> V_14 ) , V_19 -> V_28 ,
V_19 -> V_29 , V_13 ? V_13 : V_19 -> V_10 ,
V_22 -> V_30 , V_17 ? V_17 : V_22 -> V_31 ,
V_8 -> V_14 , V_32 ) ;
if ( V_27 ) {
F_18 ( F_4 ( V_2 ) , & V_33 ) ;
F_5 ( F_4 ( V_2 ) ) ;
V_2 = V_27 ;
}
}
return V_2 ;
}
static unsigned int
F_19 ( struct V_7 * V_8 , T_1 V_13 , T_2 V_17 ,
T_3 V_34 , T_3 V_35 )
{
const struct V_18 * V_19 = F_13 ( V_8 ) ;
struct V_36 V_21 , * V_22 ;
struct V_1 * V_2 ;
V_22 = F_14 ( V_8 , F_15 ( V_8 ) , sizeof( V_21 ) , & V_21 ) ;
if ( V_22 == NULL )
return V_37 ;
V_2 = F_16 ( F_17 ( V_8 -> V_14 ) , V_19 -> V_28 ,
V_19 -> V_29 , V_19 -> V_10 ,
V_22 -> V_30 , V_22 -> V_31 ,
V_8 -> V_14 , V_38 ) ;
V_13 = F_6 ( V_8 , V_13 , V_19 -> V_10 ) ;
if ( ! V_17 )
V_17 = V_22 -> V_31 ;
if ( V_2 && V_2 -> V_3 == V_4 )
V_2 = F_12 ( V_8 , V_13 , V_17 , V_2 ) ;
else if ( ! V_2 )
V_2 = F_16 ( F_17 ( V_8 -> V_14 ) , V_19 -> V_28 ,
V_19 -> V_29 , V_13 ,
V_22 -> V_30 , V_17 ,
V_8 -> V_14 , V_32 ) ;
if ( V_2 && F_1 ( V_2 ) ) {
V_8 -> V_39 = ( V_8 -> V_39 & ~ V_34 ) ^ V_35 ;
F_20 ( L_1 ,
V_19 -> V_28 , & V_19 -> V_10 , F_21 ( V_22 -> V_31 ) ,
& V_13 , F_21 ( V_17 ) , V_8 -> V_39 ) ;
F_22 ( V_8 , V_2 ) ;
return V_40 ;
}
F_20 ( L_2 ,
V_19 -> V_28 , & V_19 -> V_29 , F_21 ( V_22 -> V_30 ) ,
& V_19 -> V_10 , F_21 ( V_22 -> V_31 ) , V_8 -> V_39 ) ;
return V_37 ;
}
static unsigned int
F_23 ( struct V_7 * V_8 , const struct V_41 * V_42 )
{
const struct V_43 * V_44 = V_42 -> V_45 ;
return F_19 ( V_8 , V_44 -> V_13 , V_44 -> V_17 , V_44 -> V_34 , V_44 -> V_35 ) ;
}
static unsigned int
F_24 ( struct V_7 * V_8 , const struct V_41 * V_42 )
{
const struct V_46 * V_44 = V_42 -> V_45 ;
return F_19 ( V_8 , V_44 -> V_13 . V_47 , V_44 -> V_17 , V_44 -> V_34 , V_44 -> V_35 ) ;
}
static inline const struct V_48 *
F_25 ( struct V_7 * V_8 , const struct V_48 * V_9 ,
const struct V_48 * V_10 )
{
struct V_49 * V_12 ;
struct V_50 * V_15 ;
struct V_48 * V_13 ;
if ( ! F_26 ( V_9 ) )
return V_9 ;
V_13 = NULL ;
F_7 () ;
V_12 = F_27 ( V_8 -> V_14 ) ;
if ( V_12 )
F_28 (ifa, &indev->addr_list, if_list) {
if ( V_15 -> V_51 & ( V_52 | V_53 ) )
continue;
V_13 = & V_15 -> V_54 ;
break;
}
F_11 () ;
return V_13 ? V_13 : V_10 ;
}
static struct V_1 *
F_29 ( struct V_7 * V_8 , int V_55 , int V_56 ,
const struct V_41 * V_42 ,
struct V_1 * V_2 )
{
const struct V_57 * V_19 = F_30 ( V_8 ) ;
struct V_20 V_21 , * V_22 ;
const struct V_46 * V_44 = V_42 -> V_45 ;
V_22 = F_14 ( V_8 , V_56 , sizeof( V_21 ) , & V_21 ) ;
if ( V_22 == NULL ) {
F_5 ( F_4 ( V_2 ) ) ;
return NULL ;
}
if ( V_22 -> V_23 && ! V_22 -> V_24 && ! V_22 -> V_25 && ! V_22 -> V_26 ) {
struct V_1 * V_27 ;
V_27 = F_31 ( F_17 ( V_8 -> V_14 ) , V_55 ,
& V_19 -> V_29 ,
F_25 ( V_8 , & V_44 -> V_13 . V_58 , & V_19 -> V_10 ) ,
V_22 -> V_30 ,
V_44 -> V_17 ? V_44 -> V_17 : V_22 -> V_31 ,
V_8 -> V_14 , V_32 ) ;
if ( V_27 ) {
F_18 ( F_4 ( V_2 ) , & V_33 ) ;
F_5 ( F_4 ( V_2 ) ) ;
V_2 = V_27 ;
}
}
return V_2 ;
}
static unsigned int
F_32 ( struct V_7 * V_8 , const struct V_41 * V_42 )
{
const struct V_57 * V_19 = F_30 ( V_8 ) ;
const struct V_46 * V_44 = V_42 -> V_45 ;
struct V_36 V_21 , * V_22 ;
struct V_1 * V_2 ;
const struct V_48 * V_13 ;
T_2 V_17 ;
int V_56 ;
int V_55 ;
V_55 = F_33 ( V_8 , & V_56 , - 1 , NULL ) ;
if ( V_55 < 0 ) {
F_20 ( L_3 ) ;
return V_37 ;
}
V_22 = F_14 ( V_8 , V_56 , sizeof( V_21 ) , & V_21 ) ;
if ( V_22 == NULL ) {
F_20 ( L_4 ) ;
return V_37 ;
}
V_2 = F_31 ( F_17 ( V_8 -> V_14 ) , V_55 ,
& V_19 -> V_29 , & V_19 -> V_10 ,
V_22 -> V_30 , V_22 -> V_31 ,
V_42 -> V_59 , V_38 ) ;
V_13 = F_25 ( V_8 , & V_44 -> V_13 . V_58 , & V_19 -> V_10 ) ;
V_17 = V_44 -> V_17 ? V_44 -> V_17 : V_22 -> V_31 ;
if ( V_2 && V_2 -> V_3 == V_4 )
V_2 = F_29 ( V_8 , V_55 , V_56 , V_42 , V_2 ) ;
else if ( ! V_2 )
V_2 = F_31 ( F_17 ( V_8 -> V_14 ) , V_55 ,
& V_19 -> V_29 , V_13 ,
V_22 -> V_30 , V_17 ,
V_42 -> V_59 , V_32 ) ;
if ( V_2 && F_1 ( V_2 ) ) {
V_8 -> V_39 = ( V_8 -> V_39 & ~ V_44 -> V_34 ) ^ V_44 -> V_35 ;
F_20 ( L_5 ,
V_55 , & V_19 -> V_29 , F_21 ( V_22 -> V_30 ) ,
V_13 , F_21 ( V_17 ) , V_8 -> V_39 ) ;
F_22 ( V_8 , V_2 ) ;
return V_40 ;
}
F_20 ( L_6 ,
V_55 , & V_19 -> V_29 , F_21 ( V_22 -> V_30 ) ,
& V_19 -> V_10 , F_21 ( V_22 -> V_31 ) , V_8 -> V_39 ) ;
return V_37 ;
}
static int F_34 ( const struct V_60 * V_42 )
{
const struct V_61 * V_62 = V_42 -> V_63 ;
if ( ( V_62 -> V_64 == V_65 || V_62 -> V_64 == V_66 )
&& ! ( V_62 -> V_51 & V_67 ) )
return 0 ;
F_35 ( L_7
L_8 ) ;
return - V_68 ;
}
static int F_36 ( const struct V_60 * V_42 )
{
const struct V_69 * V_62 = V_42 -> V_63 ;
if ( ( V_62 -> V_64 == V_65 || V_62 -> V_64 == V_66 )
&& ! ( V_62 -> V_70 & V_71 ) )
return 0 ;
F_35 ( L_7
L_8 ) ;
return - V_68 ;
}
static int T_4 F_37 ( void )
{
F_38 () ;
#ifdef F_39
F_40 () ;
#endif
return F_41 ( V_72 , F_42 ( V_72 ) ) ;
}
static void T_5 F_43 ( void )
{
F_44 ( V_72 , F_42 ( V_72 ) ) ;
}
