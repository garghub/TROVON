static bool F_1 ( struct V_1 * V_2 , struct V_1 * V_3 )
{
if ( ( V_2 -> V_4 == V_3 -> V_4 ) &&
( V_2 -> V_5 == V_3 -> V_5 ) &&
( V_2 -> V_6 == V_3 -> V_6 ) &&
( V_2 -> V_7 == V_3 -> V_7 ) ) {
switch ( V_2 -> V_6 ) {
case ( V_8 ) :
if ( ! V_2 -> V_7 ||
! strcmp ( V_2 -> V_9 , V_3 -> V_9 ) )
return true ;
break;
case ( V_10 ) :
if ( ( V_2 -> V_11 . V_12 == V_3 -> V_11 . V_12 ) &&
( V_2 -> V_11 . V_13 == V_3 -> V_11 . V_13 ) )
return true ;
break;
case ( V_14 ) :
if ( V_2 -> V_4 & V_15 )
return true ;
else if ( V_2 -> V_4 & V_16 )
return false ;
return true ;
} ;
}
return false ;
}
static struct V_1 * F_2 ( struct V_17 * V_18 ,
struct V_1 * V_19 )
{
struct V_20 * V_21 ;
struct V_1 * V_22 ;
F_3 ( & V_19 -> V_23 ) ;
V_21 = F_4 ( V_18 -> V_24 , struct V_20 , V_25 ) ;
V_22 = V_21 -> V_19 ;
if ( F_1 ( V_22 , V_19 ) )
F_5 ( V_22 ) ;
else
V_22 = NULL ;
F_6 ( & V_19 -> V_23 ) ;
return V_22 ;
}
static int F_7 ( struct V_26 * V_27 ,
struct V_28 * V_29 ,
struct V_28 * V_30 ,
struct V_1 * V_19 )
{
struct V_31 * V_32 ;
struct V_33 * V_5 ;
struct V_34 * V_35 ;
struct V_36 * V_37 ;
struct V_1 * V_38 ;
int V_39 , V_40 = 0 ;
F_8 ( V_30 ) ;
F_9 ( L_1 , V_41 , V_27 ,
V_19 , V_19 -> V_5 , V_19 -> V_4 ) ;
V_5 = V_19 -> V_5 ;
V_32 = F_10 ( V_29 , struct V_31 ,
V_42 ) ;
V_39 = V_32 -> V_39 ;
V_35 = F_11 ( V_43 , V_44 ) ;
if ( F_12 ( ! V_35 ) )
return - V_45 ;
V_37 = & V_35 -> V_46 ;
V_37 -> V_27 = V_27 ;
V_35 -> V_39 = V_39 ;
V_38 = F_13 ( V_27 , V_19 , V_37 , F_2 ) ;
if ( V_38 ) {
F_14 ( V_37 ) ;
if ( ! F_15 ( V_38 ) )
F_16 ( V_38 ) ;
else
V_40 = F_17 ( V_38 ) ;
}
if ( V_29 -> V_4 & V_47 )
F_18 ( V_29 ) ;
return V_40 ;
}
static void F_19 ( struct V_28 * V_42 , struct V_26 * V_27 )
{
F_20 ( V_42 , V_27 ) ;
}
static bool F_21 ( struct V_26 * V_27 , struct V_33 * V_33 ,
struct V_28 * V_29 ,
struct V_28 * V_30 ,
T_1 V_4 , void * V_48 , int V_6 )
{
if ( ( V_29 -> V_4 & V_49 ) &&
( V_6 == V_10 ) ) {
struct V_11 * V_11 = V_48 ;
if ( F_22 ( V_11 -> V_13 ) )
return false ;
}
return true ;
}
static int F_23 ( int V_50 , void * V_51 , void * V_48 )
{
struct V_28 * V_42 ;
struct V_31 * V_32 ;
static bool V_52 = false ;
if ( V_52 )
return 0 ;
V_52 = true ;
V_42 = V_51 ;
V_32 = F_10 ( V_42 , struct V_31 , V_42 ) ;
F_24 ( 1 , L_2
L_3 , V_50 , V_51 , V_48 ) ;
if ( V_42 )
F_25 ( V_53 L_4 ,
V_42 -> V_27 , V_42 -> V_54 . V_33 , V_32 -> V_39 ) ;
return 0 ;
}
static void F_26 ( struct V_26 * V_27 )
{
F_27 ( & V_27 -> V_55 . V_56 , F_23 , V_27 ) ;
F_28 ( & V_27 -> V_55 . V_56 ) ;
F_29 ( & V_27 -> V_55 . V_56 ) ;
F_30 ( & V_27 -> V_55 . V_57 -> V_58 ) ;
F_31 ( V_27 -> V_55 . V_57 ) ;
}
void F_14 ( struct V_36 * V_37 )
{
struct V_34 * V_35 ;
V_35 = F_10 ( V_37 , struct V_34 ,
V_46 ) ;
F_32 ( V_43 , V_35 ) ;
}
