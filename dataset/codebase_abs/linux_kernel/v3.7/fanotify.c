static bool F_1 ( struct V_1 * V_2 , struct V_1 * V_3 )
{
F_2 ( L_1 , V_4 , V_2 , V_3 ) ;
if ( V_2 -> V_5 == V_3 -> V_5 &&
V_2 -> V_6 == V_3 -> V_6 &&
V_2 -> V_7 == V_3 -> V_7 ) {
switch ( V_2 -> V_6 ) {
case ( V_8 ) :
if ( ( V_2 -> V_9 . V_10 == V_3 -> V_9 . V_10 ) &&
( V_2 -> V_9 . V_11 == V_3 -> V_9 . V_11 ) )
return true ;
break;
case ( V_12 ) :
return true ;
default:
F_3 () ;
} ;
}
return false ;
}
static struct V_1 * F_4 ( struct V_13 * V_14 ,
struct V_1 * V_15 )
{
struct V_16 * V_17 ;
struct V_1 * V_18 = NULL ;
struct V_1 * V_19 ;
F_2 ( L_2 , V_4 , V_14 , V_15 ) ;
F_5 (test_holder, list, event_list) {
if ( F_1 ( V_17 -> V_15 , V_15 ) ) {
V_18 = V_17 -> V_15 ;
break;
}
}
if ( ! V_18 )
return NULL ;
F_6 ( V_18 ) ;
if ( V_18 -> V_20 == V_15 -> V_20 )
return V_18 ;
if ( F_7 ( & V_18 -> V_21 ) == 2 ) {
V_18 -> V_20 |= V_15 -> V_20 ;
return V_18 ;
}
V_19 = F_8 ( V_18 ) ;
F_9 ( V_18 ) ;
if ( F_10 ( ! V_19 ) )
return F_11 ( - V_22 ) ;
V_19 -> V_20 = ( V_18 -> V_20 | V_15 -> V_20 ) ;
F_12 ( V_17 , V_19 ) ;
return V_19 ;
}
static int F_13 ( struct V_23 * V_24 ,
struct V_1 * V_15 )
{
int V_25 ;
F_2 ( L_3 , V_4 , V_24 , V_15 ) ;
F_14 ( V_24 -> V_26 . V_27 , V_15 -> V_28 ||
F_7 ( & V_24 -> V_26 . V_29 ) ) ;
if ( ! V_15 -> V_28 )
return 0 ;
F_15 ( & V_15 -> V_30 ) ;
switch ( V_15 -> V_28 ) {
case V_31 :
V_25 = 0 ;
break;
case V_32 :
default:
V_25 = - V_33 ;
}
V_15 -> V_28 = 0 ;
F_16 ( & V_15 -> V_30 ) ;
F_2 ( L_4 , V_4 ,
V_24 , V_15 , V_25 ) ;
return V_25 ;
}
static int F_17 ( struct V_23 * V_24 ,
struct V_34 * V_35 ,
struct V_34 * V_36 ,
struct V_1 * V_15 )
{
int V_25 = 0 ;
struct V_1 * V_37 = NULL ;
F_18 ( V_38 != V_39 ) ;
F_18 ( V_40 != V_41 ) ;
F_18 ( V_42 != V_43 ) ;
F_18 ( V_44 != V_45 ) ;
F_18 ( V_46 != V_47 ) ;
F_18 ( V_48 != V_49 ) ;
F_18 ( V_50 != V_51 ) ;
F_18 ( V_52 != V_53 ) ;
F_18 ( V_54 != V_55 ) ;
F_18 ( V_56 != V_57 ) ;
F_2 ( L_3 , V_4 , V_24 , V_15 ) ;
V_37 = F_19 ( V_24 , V_15 , NULL , F_4 ) ;
if ( F_20 ( V_37 ) )
return F_21 ( V_37 ) ;
#ifdef F_22
if ( V_15 -> V_20 & V_58 ) {
if ( V_37 )
V_15 = V_37 ;
V_25 = F_13 ( V_24 , V_15 ) ;
}
#endif
if ( V_37 )
F_9 ( V_37 ) ;
return V_25 ;
}
static bool F_23 ( struct V_23 * V_24 ,
struct V_59 * V_5 ,
struct V_34 * V_35 ,
struct V_34 * V_60 ,
T_1 V_61 , void * V_62 , int V_6 )
{
T_1 V_63 , V_64 ;
struct V_9 * V_9 = V_62 ;
F_2 ( L_5
L_6 , V_4 , V_24 , V_5 ,
V_35 , V_60 , V_61 , V_62 , V_6 ) ;
if ( V_6 != V_8 )
return false ;
if ( ! F_24 ( V_9 -> V_11 -> V_65 -> V_66 ) &&
! F_25 ( V_9 -> V_11 -> V_65 -> V_66 ) )
return false ;
if ( V_35 && V_60 ) {
V_63 = ( V_60 -> V_20 | V_35 -> V_20 ) ;
V_64 = ( V_60 -> V_67 | V_35 -> V_67 ) ;
} else if ( V_35 ) {
if ( ( V_61 & V_49 ) &&
! ( V_35 -> V_20 & V_49 ) )
return false ;
V_63 = V_35 -> V_20 ;
V_64 = V_35 -> V_67 ;
} else if ( V_60 ) {
V_63 = V_60 -> V_20 ;
V_64 = V_60 -> V_67 ;
} else {
F_3 () ;
}
if ( F_25 ( V_9 -> V_11 -> V_65 -> V_66 ) &&
( V_64 & V_57 ) )
return false ;
if ( V_61 & V_63 & ~ V_64 )
return true ;
return false ;
}
static void F_26 ( struct V_23 * V_24 )
{
struct V_68 * V_69 ;
V_69 = V_24 -> V_26 . V_69 ;
F_27 ( & V_69 -> V_70 ) ;
F_28 ( V_69 ) ;
}
