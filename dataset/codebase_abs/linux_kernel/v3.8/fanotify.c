static bool F_1 ( struct V_1 * V_2 , struct V_1 * V_3 )
{
F_2 ( L_1 , V_4 , V_2 , V_3 ) ;
if ( V_2 -> V_5 == V_3 -> V_5 &&
V_2 -> V_6 == V_3 -> V_6 &&
V_2 -> V_7 == V_3 -> V_7 ) {
switch ( V_2 -> V_6 ) {
case ( V_8 ) :
#ifdef F_3
if ( ( V_2 -> V_9 & V_10 ) &&
( V_3 -> V_9 & V_10 ) )
return false ;
#endif
if ( ( V_2 -> V_11 . V_12 == V_3 -> V_11 . V_12 ) &&
( V_2 -> V_11 . V_13 == V_3 -> V_11 . V_13 ) )
return true ;
break;
case ( V_14 ) :
return true ;
default:
F_4 () ;
} ;
}
return false ;
}
static struct V_1 * F_5 ( struct V_15 * V_16 ,
struct V_1 * V_17 )
{
struct V_18 * V_19 ;
struct V_1 * V_20 = NULL ;
struct V_1 * V_21 ;
F_2 ( L_2 , V_4 , V_16 , V_17 ) ;
F_6 (test_holder, list, event_list) {
if ( F_1 ( V_19 -> V_17 , V_17 ) ) {
V_20 = V_19 -> V_17 ;
break;
}
}
if ( ! V_20 )
return NULL ;
F_7 ( V_20 ) ;
if ( V_20 -> V_9 == V_17 -> V_9 )
return V_20 ;
if ( F_8 ( & V_20 -> V_22 ) == 2 ) {
V_20 -> V_9 |= V_17 -> V_9 ;
return V_20 ;
}
V_21 = F_9 ( V_20 ) ;
F_10 ( V_20 ) ;
if ( F_11 ( ! V_21 ) )
return F_12 ( - V_23 ) ;
V_21 -> V_9 = ( V_20 -> V_9 | V_17 -> V_9 ) ;
F_13 ( V_19 , V_21 ) ;
return V_21 ;
}
static int F_14 ( struct V_24 * V_25 ,
struct V_1 * V_17 )
{
int V_26 ;
F_2 ( L_3 , V_4 , V_25 , V_17 ) ;
F_15 ( V_25 -> V_27 . V_28 , V_17 -> V_29 ||
F_8 ( & V_25 -> V_27 . V_30 ) ) ;
if ( ! V_17 -> V_29 )
return 0 ;
F_16 ( & V_17 -> V_31 ) ;
switch ( V_17 -> V_29 ) {
case V_32 :
V_26 = 0 ;
break;
case V_33 :
default:
V_26 = - V_34 ;
}
V_17 -> V_29 = 0 ;
F_17 ( & V_17 -> V_31 ) ;
F_2 ( L_4 , V_4 ,
V_25 , V_17 , V_26 ) ;
return V_26 ;
}
static int F_18 ( struct V_24 * V_25 ,
struct V_35 * V_36 ,
struct V_35 * V_37 ,
struct V_1 * V_17 )
{
int V_26 = 0 ;
struct V_1 * V_38 = NULL ;
F_19 ( V_39 != V_40 ) ;
F_19 ( V_41 != V_42 ) ;
F_19 ( V_43 != V_44 ) ;
F_19 ( V_45 != V_46 ) ;
F_19 ( V_47 != V_48 ) ;
F_19 ( V_49 != V_50 ) ;
F_19 ( V_51 != V_52 ) ;
F_19 ( V_53 != V_54 ) ;
F_19 ( V_55 != V_56 ) ;
F_19 ( V_57 != V_58 ) ;
F_2 ( L_3 , V_4 , V_25 , V_17 ) ;
V_38 = F_20 ( V_25 , V_17 , NULL , F_5 ) ;
if ( F_21 ( V_38 ) )
return F_22 ( V_38 ) ;
#ifdef F_3
if ( V_17 -> V_9 & V_10 ) {
if ( V_38 )
V_17 = V_38 ;
V_26 = F_14 ( V_25 , V_17 ) ;
}
#endif
if ( V_38 )
F_10 ( V_38 ) ;
return V_26 ;
}
static bool F_23 ( struct V_24 * V_25 ,
struct V_59 * V_5 ,
struct V_35 * V_36 ,
struct V_35 * V_60 ,
T_1 V_61 , void * V_62 , int V_6 )
{
T_1 V_63 , V_64 ;
struct V_11 * V_11 = V_62 ;
F_2 ( L_5
L_6 , V_4 , V_25 , V_5 ,
V_36 , V_60 , V_61 , V_62 , V_6 ) ;
if ( V_6 != V_8 )
return false ;
if ( ! F_24 ( V_11 -> V_13 -> V_65 -> V_66 ) &&
! F_25 ( V_11 -> V_13 -> V_65 -> V_66 ) )
return false ;
if ( V_36 && V_60 ) {
V_63 = ( V_60 -> V_9 | V_36 -> V_9 ) ;
V_64 = ( V_60 -> V_67 | V_36 -> V_67 ) ;
} else if ( V_36 ) {
if ( ( V_61 & V_50 ) &&
! ( V_36 -> V_9 & V_50 ) )
return false ;
V_63 = V_36 -> V_9 ;
V_64 = V_36 -> V_67 ;
} else if ( V_60 ) {
V_63 = V_60 -> V_9 ;
V_64 = V_60 -> V_67 ;
} else {
F_4 () ;
}
if ( F_25 ( V_11 -> V_13 -> V_65 -> V_66 ) &&
( V_64 & V_58 ) )
return false ;
if ( V_61 & V_63 & ~ V_64 )
return true ;
return false ;
}
static void F_26 ( struct V_24 * V_25 )
{
struct V_68 * V_69 ;
V_69 = V_25 -> V_27 . V_69 ;
F_27 ( & V_69 -> V_70 ) ;
F_28 ( V_69 ) ;
}
