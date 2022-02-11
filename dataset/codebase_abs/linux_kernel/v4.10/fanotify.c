static bool F_1 ( struct V_1 * V_2 ,
struct V_1 * V_3 )
{
struct V_4 * V_5 , * V_6 ;
F_2 ( L_1 , V_7 , V_2 , V_3 ) ;
V_5 = F_3 ( V_2 ) ;
V_6 = F_3 ( V_3 ) ;
if ( V_2 -> V_8 == V_3 -> V_8 && V_5 -> V_9 == V_6 -> V_9 &&
V_5 -> V_10 . V_11 == V_6 -> V_10 . V_11 &&
V_5 -> V_10 . V_12 == V_6 -> V_10 . V_12 )
return true ;
return false ;
}
static int F_4 ( struct V_13 * V_14 , struct V_1 * V_15 )
{
struct V_1 * V_16 ;
bool V_17 = false ;
F_2 ( L_2 , V_7 , V_14 , V_15 ) ;
#ifdef F_5
if ( V_15 -> V_18 & V_19 )
return 0 ;
#endif
F_6 (test_event, list, list) {
if ( F_1 ( V_16 , V_15 ) ) {
V_17 = true ;
break;
}
}
if ( ! V_17 )
return 0 ;
V_16 -> V_18 |= V_15 -> V_18 ;
return 1 ;
}
static int F_7 ( struct V_20 * V_21 ,
struct V_22 * V_15 )
{
int V_23 ;
F_2 ( L_3 , V_7 , V_21 , V_15 ) ;
F_8 ( V_21 -> V_24 . V_25 , V_15 -> V_26 ) ;
switch ( V_15 -> V_26 ) {
case V_27 :
V_23 = 0 ;
break;
case V_28 :
default:
V_23 = - V_29 ;
}
V_15 -> V_26 = 0 ;
F_2 ( L_4 , V_7 ,
V_21 , V_15 , V_23 ) ;
return V_23 ;
}
static bool F_9 ( struct V_30 * V_31 ,
struct V_30 * V_32 ,
T_1 V_33 ,
const void * V_34 , int V_35 )
{
T_2 V_36 , V_37 ;
const struct V_10 * V_10 = V_34 ;
F_2 ( L_5
L_6 , V_7 , V_31 , V_32 ,
V_33 , V_34 , V_35 ) ;
if ( V_35 != V_38 )
return false ;
if ( ! F_10 ( V_10 -> V_12 ) &&
! F_11 ( V_10 -> V_12 ) )
return false ;
if ( V_31 && V_32 ) {
V_36 = ( V_32 -> V_18 | V_31 -> V_18 ) ;
V_37 = ( V_32 -> V_39 | V_31 -> V_39 ) ;
} else if ( V_31 ) {
if ( ( V_33 & V_40 ) &&
! ( V_31 -> V_18 & V_40 ) )
return false ;
V_36 = V_31 -> V_18 ;
V_37 = V_31 -> V_39 ;
} else if ( V_32 ) {
V_36 = V_32 -> V_18 ;
V_37 = V_32 -> V_39 ;
} else {
F_12 () ;
}
if ( F_13 ( V_10 -> V_12 ) &&
! ( V_36 & V_41 & ~ V_37 ) )
return false ;
if ( V_33 & V_42 & V_36 &
~ V_37 )
return true ;
return false ;
}
struct V_4 * F_14 ( struct V_8 * V_8 , T_1 V_18 ,
const struct V_10 * V_10 )
{
struct V_4 * V_15 ;
#ifdef F_5
if ( V_18 & V_19 ) {
struct V_22 * V_43 ;
V_43 = F_15 ( V_44 ,
V_45 ) ;
if ( ! V_43 )
return NULL ;
V_15 = & V_43 -> V_46 ;
V_43 -> V_26 = 0 ;
goto V_47;
}
#endif
V_15 = F_15 ( V_48 , V_45 ) ;
if ( ! V_15 )
return NULL ;
V_47: T_3
V_49 ( & V_15 -> V_50 , V_8 , V_18 ) ;
V_15 -> V_9 = F_16 ( F_17 ( V_51 ) ) ;
if ( V_10 ) {
V_15 -> V_10 = * V_10 ;
F_18 ( & V_15 -> V_10 ) ;
} else {
V_15 -> V_10 . V_11 = NULL ;
V_15 -> V_10 . V_12 = NULL ;
}
return V_15 ;
}
static int F_19 ( struct V_20 * V_21 ,
struct V_8 * V_8 ,
struct V_30 * V_31 ,
struct V_30 * V_52 ,
T_1 V_18 , const void * V_34 , int V_35 ,
const unsigned char * V_53 , T_1 V_54 )
{
int V_23 = 0 ;
struct V_4 * V_15 ;
struct V_1 * V_55 ;
F_20 ( V_56 != V_57 ) ;
F_20 ( V_58 != V_59 ) ;
F_20 ( V_60 != V_61 ) ;
F_20 ( V_62 != V_63 ) ;
F_20 ( V_64 != V_65 ) ;
F_20 ( V_66 != V_40 ) ;
F_20 ( V_67 != V_68 ) ;
F_20 ( V_69 != V_70 ) ;
F_20 ( V_71 != V_72 ) ;
F_20 ( V_73 != V_41 ) ;
if ( ! F_9 ( V_31 , V_52 , V_18 , V_34 ,
V_35 ) )
return 0 ;
F_2 ( L_7 , V_7 , V_21 , V_8 ,
V_18 ) ;
V_15 = F_14 ( V_8 , V_18 , V_34 ) ;
if ( F_21 ( ! V_15 ) )
return - V_74 ;
V_55 = & V_15 -> V_50 ;
V_23 = F_22 ( V_21 , V_55 , F_4 ) ;
if ( V_23 ) {
F_23 ( V_23 == 1 && V_18 & V_19 ) ;
F_24 ( V_21 , V_55 ) ;
return 0 ;
}
#ifdef F_5
if ( V_18 & V_19 ) {
V_23 = F_7 ( V_21 , F_25 ( V_55 ) ) ;
F_24 ( V_21 , V_55 ) ;
}
#endif
return V_23 ;
}
static void F_26 ( struct V_20 * V_21 )
{
struct V_75 * V_76 ;
V_76 = V_21 -> V_24 . V_76 ;
F_27 ( & V_76 -> V_77 ) ;
F_28 ( V_76 ) ;
}
static void F_29 ( struct V_1 * V_55 )
{
struct V_4 * V_15 ;
V_15 = F_3 ( V_55 ) ;
F_30 ( & V_15 -> V_10 ) ;
F_31 ( V_15 -> V_9 ) ;
#ifdef F_5
if ( V_55 -> V_18 & V_19 ) {
F_32 ( V_44 ,
F_25 ( V_55 ) ) ;
return;
}
#endif
F_32 ( V_48 , V_15 ) ;
}
