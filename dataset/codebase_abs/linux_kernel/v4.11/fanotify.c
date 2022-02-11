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
F_2 ( L_2 , V_7 , V_14 , V_15 ) ;
#ifdef F_5
if ( V_15 -> V_17 & V_18 )
return 0 ;
#endif
F_6 (test_event, list, list) {
if ( F_1 ( V_16 , V_15 ) ) {
V_16 -> V_17 |= V_15 -> V_17 ;
return 1 ;
}
}
return 0 ;
}
static int F_7 ( struct V_19 * V_20 ,
struct V_21 * V_15 )
{
int V_22 ;
F_2 ( L_3 , V_7 , V_20 , V_15 ) ;
F_8 ( V_20 -> V_23 . V_24 , V_15 -> V_25 ) ;
switch ( V_15 -> V_25 ) {
case V_26 :
V_22 = 0 ;
break;
case V_27 :
default:
V_22 = - V_28 ;
}
V_15 -> V_25 = 0 ;
F_2 ( L_4 , V_7 ,
V_20 , V_15 , V_22 ) ;
return V_22 ;
}
static bool F_9 ( struct V_29 * V_30 ,
struct V_29 * V_31 ,
T_1 V_32 ,
const void * V_33 , int V_34 )
{
T_2 V_35 , V_36 ;
const struct V_10 * V_10 = V_33 ;
F_2 ( L_5
L_6 , V_7 , V_30 , V_31 ,
V_32 , V_33 , V_34 ) ;
if ( V_34 != V_37 )
return false ;
if ( ! F_10 ( V_10 -> V_12 ) &&
! F_11 ( V_10 -> V_12 ) )
return false ;
if ( V_30 && V_31 ) {
V_35 = ( V_31 -> V_17 | V_30 -> V_17 ) ;
V_36 = ( V_31 -> V_38 | V_30 -> V_38 ) ;
} else if ( V_30 ) {
if ( ( V_32 & V_39 ) &&
! ( V_30 -> V_17 & V_39 ) )
return false ;
V_35 = V_30 -> V_17 ;
V_36 = V_30 -> V_38 ;
} else if ( V_31 ) {
V_35 = V_31 -> V_17 ;
V_36 = V_31 -> V_38 ;
} else {
F_12 () ;
}
if ( F_13 ( V_10 -> V_12 ) &&
! ( V_35 & V_40 & ~ V_36 ) )
return false ;
if ( V_32 & V_41 & V_35 &
~ V_36 )
return true ;
return false ;
}
struct V_4 * F_14 ( struct V_8 * V_8 , T_1 V_17 ,
const struct V_10 * V_10 )
{
struct V_4 * V_15 ;
#ifdef F_5
if ( V_17 & V_18 ) {
struct V_21 * V_42 ;
V_42 = F_15 ( V_43 ,
V_44 ) ;
if ( ! V_42 )
return NULL ;
V_15 = & V_42 -> V_45 ;
V_42 -> V_25 = 0 ;
goto V_46;
}
#endif
V_15 = F_15 ( V_47 , V_44 ) ;
if ( ! V_15 )
return NULL ;
V_46: T_3
V_48 ( & V_15 -> V_49 , V_8 , V_17 ) ;
V_15 -> V_9 = F_16 ( F_17 ( V_50 ) ) ;
if ( V_10 ) {
V_15 -> V_10 = * V_10 ;
F_18 ( & V_15 -> V_10 ) ;
} else {
V_15 -> V_10 . V_11 = NULL ;
V_15 -> V_10 . V_12 = NULL ;
}
return V_15 ;
}
static int F_19 ( struct V_19 * V_20 ,
struct V_8 * V_8 ,
struct V_29 * V_30 ,
struct V_29 * V_51 ,
T_1 V_17 , const void * V_33 , int V_34 ,
const unsigned char * V_52 , T_1 V_53 )
{
int V_22 = 0 ;
struct V_4 * V_15 ;
struct V_1 * V_54 ;
F_20 ( V_55 != V_56 ) ;
F_20 ( V_57 != V_58 ) ;
F_20 ( V_59 != V_60 ) ;
F_20 ( V_61 != V_62 ) ;
F_20 ( V_63 != V_64 ) ;
F_20 ( V_65 != V_39 ) ;
F_20 ( V_66 != V_67 ) ;
F_20 ( V_68 != V_69 ) ;
F_20 ( V_70 != V_71 ) ;
F_20 ( V_72 != V_40 ) ;
if ( ! F_9 ( V_30 , V_51 , V_17 , V_33 ,
V_34 ) )
return 0 ;
F_2 ( L_7 , V_7 , V_20 , V_8 ,
V_17 ) ;
V_15 = F_14 ( V_8 , V_17 , V_33 ) ;
if ( F_21 ( ! V_15 ) )
return - V_73 ;
V_54 = & V_15 -> V_49 ;
V_22 = F_22 ( V_20 , V_54 , F_4 ) ;
if ( V_22 ) {
F_23 ( V_22 == 1 && V_17 & V_18 ) ;
F_24 ( V_20 , V_54 ) ;
return 0 ;
}
#ifdef F_5
if ( V_17 & V_18 ) {
V_22 = F_7 ( V_20 , F_25 ( V_54 ) ) ;
F_24 ( V_20 , V_54 ) ;
}
#endif
return V_22 ;
}
static void F_26 ( struct V_19 * V_20 )
{
struct V_74 * V_75 ;
V_75 = V_20 -> V_23 . V_75 ;
F_27 ( & V_75 -> V_76 ) ;
F_28 ( V_75 ) ;
}
static void F_29 ( struct V_1 * V_54 )
{
struct V_4 * V_15 ;
V_15 = F_3 ( V_54 ) ;
F_30 ( & V_15 -> V_10 ) ;
F_31 ( V_15 -> V_9 ) ;
#ifdef F_5
if ( V_54 -> V_17 & V_18 ) {
F_32 ( V_43 ,
F_25 ( V_54 ) ) ;
return;
}
#endif
F_32 ( V_47 , V_15 ) ;
}
