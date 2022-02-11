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
struct V_4 * V_15 )
{
int V_22 ;
F_2 ( L_3 , V_7 , V_21 , V_15 ) ;
F_8 ( V_21 -> V_23 . V_24 , V_15 -> V_25 ||
F_9 ( & V_21 -> V_23 . V_26 ) ) ;
if ( ! V_15 -> V_25 )
return 0 ;
switch ( V_15 -> V_25 ) {
case V_27 :
V_22 = 0 ;
break;
case V_28 :
default:
V_22 = - V_29 ;
}
V_15 -> V_25 = 0 ;
F_2 ( L_4 , V_7 ,
V_21 , V_15 , V_22 ) ;
return V_22 ;
}
static bool F_10 ( struct V_30 * V_31 ,
struct V_30 * V_32 ,
T_1 V_33 ,
void * V_34 , int V_35 )
{
T_2 V_36 , V_37 ;
struct V_10 * V_10 = V_34 ;
F_2 ( L_5
L_6 , V_7 , V_31 , V_32 ,
V_33 , V_34 , V_35 ) ;
if ( V_35 != V_38 )
return false ;
if ( ! F_11 ( V_10 -> V_12 -> V_39 -> V_40 ) &&
! F_12 ( V_10 -> V_12 -> V_39 -> V_40 ) )
return false ;
if ( V_31 && V_32 ) {
V_36 = ( V_32 -> V_18 | V_31 -> V_18 ) ;
V_37 = ( V_32 -> V_41 | V_31 -> V_41 ) ;
} else if ( V_31 ) {
if ( ( V_33 & V_42 ) &&
! ( V_31 -> V_18 & V_42 ) )
return false ;
V_36 = V_31 -> V_18 ;
V_37 = V_31 -> V_41 ;
} else if ( V_32 ) {
V_36 = V_32 -> V_18 ;
V_37 = V_32 -> V_41 ;
} else {
F_13 () ;
}
if ( F_12 ( V_10 -> V_12 -> V_39 -> V_40 ) &&
( V_37 & V_43 ) )
return false ;
if ( V_33 & V_36 & ~ V_37 )
return true ;
return false ;
}
static int F_14 ( struct V_20 * V_21 ,
struct V_8 * V_8 ,
struct V_30 * V_31 ,
struct V_30 * V_44 ,
T_1 V_18 , void * V_34 , int V_35 ,
const unsigned char * V_45 , T_1 V_46 )
{
int V_22 = 0 ;
struct V_4 * V_15 ;
struct V_1 * V_47 ;
F_15 ( V_48 != V_49 ) ;
F_15 ( V_50 != V_51 ) ;
F_15 ( V_52 != V_53 ) ;
F_15 ( V_54 != V_55 ) ;
F_15 ( V_56 != V_57 ) ;
F_15 ( V_58 != V_42 ) ;
F_15 ( V_59 != V_60 ) ;
F_15 ( V_61 != V_62 ) ;
F_15 ( V_63 != V_64 ) ;
F_15 ( V_65 != V_43 ) ;
if ( ! F_10 ( V_31 , V_44 , V_18 , V_34 ,
V_35 ) )
return 0 ;
F_2 ( L_7 , V_7 , V_21 , V_8 ,
V_18 ) ;
V_15 = F_16 ( V_66 , V_67 ) ;
if ( F_17 ( ! V_15 ) )
return - V_68 ;
V_47 = & V_15 -> V_69 ;
F_18 ( V_47 , V_8 , V_18 ) ;
V_15 -> V_9 = F_19 ( F_20 ( V_70 ) ) ;
if ( V_35 == V_38 ) {
struct V_10 * V_10 = V_34 ;
V_15 -> V_10 = * V_10 ;
F_21 ( & V_15 -> V_10 ) ;
} else {
V_15 -> V_10 . V_11 = NULL ;
V_15 -> V_10 . V_12 = NULL ;
}
#ifdef F_5
V_15 -> V_25 = 0 ;
#endif
V_22 = F_22 ( V_21 , V_47 , F_4 ) ;
if ( V_22 ) {
F_23 ( V_22 == 1 && V_18 & V_19 ) ;
F_24 ( V_21 , V_47 ) ;
return 0 ;
}
#ifdef F_5
if ( V_18 & V_19 ) {
V_22 = F_7 ( V_21 , V_15 ) ;
F_24 ( V_21 , V_47 ) ;
}
#endif
return V_22 ;
}
static void F_25 ( struct V_20 * V_21 )
{
struct V_71 * V_72 ;
V_72 = V_21 -> V_23 . V_72 ;
F_26 ( & V_72 -> V_73 ) ;
F_27 ( V_72 ) ;
}
static void F_28 ( struct V_1 * V_47 )
{
struct V_4 * V_15 ;
V_15 = F_3 ( V_47 ) ;
F_29 ( & V_15 -> V_10 ) ;
F_30 ( V_15 -> V_9 ) ;
F_31 ( V_66 , V_15 ) ;
}
