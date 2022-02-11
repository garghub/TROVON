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
F_8 ( V_21 -> V_24 . V_25 , V_15 -> V_26 ||
F_9 ( & V_21 -> V_24 . V_27 ) ) ;
if ( ! V_15 -> V_26 ) {
F_10 ( V_21 , & V_15 -> V_28 . V_29 ) ;
return 0 ;
}
switch ( V_15 -> V_26 ) {
case V_30 :
V_23 = 0 ;
break;
case V_31 :
default:
V_23 = - V_32 ;
}
V_15 -> V_26 = 0 ;
F_2 ( L_4 , V_7 ,
V_21 , V_15 , V_23 ) ;
return V_23 ;
}
static bool F_11 ( struct V_33 * V_34 ,
struct V_33 * V_35 ,
T_1 V_36 ,
void * V_37 , int V_38 )
{
T_2 V_39 , V_40 ;
struct V_10 * V_10 = V_37 ;
F_2 ( L_5
L_6 , V_7 , V_34 , V_35 ,
V_36 , V_37 , V_38 ) ;
if ( V_38 != V_41 )
return false ;
if ( ! F_12 ( V_10 -> V_12 ) &&
! F_13 ( V_10 -> V_12 ) )
return false ;
if ( V_34 && V_35 ) {
V_39 = ( V_35 -> V_18 | V_34 -> V_18 ) ;
V_40 = ( V_35 -> V_42 | V_34 -> V_42 ) ;
} else if ( V_34 ) {
if ( ( V_36 & V_43 ) &&
! ( V_34 -> V_18 & V_43 ) )
return false ;
V_39 = V_34 -> V_18 ;
V_40 = V_34 -> V_42 ;
} else if ( V_35 ) {
V_39 = V_35 -> V_18 ;
V_40 = V_35 -> V_42 ;
} else {
F_14 () ;
}
if ( F_15 ( V_10 -> V_12 ) &&
! ( V_39 & V_44 & ~ V_40 ) )
return false ;
if ( V_36 & V_45 & V_39 &
~ V_40 )
return true ;
return false ;
}
struct V_4 * F_16 ( struct V_8 * V_8 , T_1 V_18 ,
struct V_10 * V_10 )
{
struct V_4 * V_15 ;
#ifdef F_5
if ( V_18 & V_19 ) {
struct V_22 * V_46 ;
V_46 = F_17 ( V_47 ,
V_48 ) ;
if ( ! V_46 )
return NULL ;
V_15 = & V_46 -> V_28 ;
V_46 -> V_26 = 0 ;
goto V_49;
}
#endif
V_15 = F_17 ( V_50 , V_48 ) ;
if ( ! V_15 )
return NULL ;
V_49: T_3
V_51 ( & V_15 -> V_29 , V_8 , V_18 ) ;
V_15 -> V_9 = F_18 ( F_19 ( V_52 ) ) ;
if ( V_10 ) {
V_15 -> V_10 = * V_10 ;
F_20 ( & V_15 -> V_10 ) ;
} else {
V_15 -> V_10 . V_11 = NULL ;
V_15 -> V_10 . V_12 = NULL ;
}
return V_15 ;
}
static int F_21 ( struct V_20 * V_21 ,
struct V_8 * V_8 ,
struct V_33 * V_34 ,
struct V_33 * V_53 ,
T_1 V_18 , void * V_37 , int V_38 ,
const unsigned char * V_54 , T_1 V_55 )
{
int V_23 = 0 ;
struct V_4 * V_15 ;
struct V_1 * V_56 ;
F_22 ( V_57 != V_58 ) ;
F_22 ( V_59 != V_60 ) ;
F_22 ( V_61 != V_62 ) ;
F_22 ( V_63 != V_64 ) ;
F_22 ( V_65 != V_66 ) ;
F_22 ( V_67 != V_43 ) ;
F_22 ( V_68 != V_69 ) ;
F_22 ( V_70 != V_71 ) ;
F_22 ( V_72 != V_73 ) ;
F_22 ( V_74 != V_44 ) ;
if ( ! F_11 ( V_34 , V_53 , V_18 , V_37 ,
V_38 ) )
return 0 ;
F_2 ( L_7 , V_7 , V_21 , V_8 ,
V_18 ) ;
V_15 = F_16 ( V_8 , V_18 , V_37 ) ;
if ( F_23 ( ! V_15 ) )
return - V_75 ;
V_56 = & V_15 -> V_29 ;
V_23 = F_24 ( V_21 , V_56 , F_4 ) ;
if ( V_23 ) {
F_25 ( V_23 == 1 && V_18 & V_19 ) ;
F_26 ( V_21 , V_56 ) ;
return 0 ;
}
#ifdef F_5
if ( V_18 & V_19 ) {
V_23 = F_7 ( V_21 , F_27 ( V_56 ) ) ;
F_26 ( V_21 , V_56 ) ;
}
#endif
return V_23 ;
}
static void F_28 ( struct V_20 * V_21 )
{
struct V_76 * V_77 ;
V_77 = V_21 -> V_24 . V_77 ;
F_29 ( & V_77 -> V_78 ) ;
F_30 ( V_77 ) ;
}
static void F_31 ( struct V_1 * V_56 )
{
struct V_4 * V_15 ;
V_15 = F_3 ( V_56 ) ;
F_32 ( & V_15 -> V_10 ) ;
F_33 ( V_15 -> V_9 ) ;
#ifdef F_5
if ( V_56 -> V_18 & V_19 ) {
F_34 ( V_47 ,
F_27 ( V_56 ) ) ;
return;
}
#endif
F_34 ( V_50 , V_15 ) ;
}
