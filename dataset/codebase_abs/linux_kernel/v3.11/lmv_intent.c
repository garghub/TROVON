static int F_1 ( struct V_1 * exp , void * V_2 ,
int V_3 , struct V_4 * V_5 ,
const struct V_6 * V_7 , int V_8 ,
struct V_9 * * V_10 ,
T_1 V_11 ,
T_2 V_12 )
{
struct V_13 * V_14 = exp -> V_15 ;
struct V_16 * V_17 = & V_14 -> V_18 . V_17 ;
struct V_9 * V_19 = NULL ;
struct V_20 V_21 ;
struct V_22 * V_23 ;
struct V_24 * V_25 ;
struct V_26 * V_27 ;
int V_28 ;
int V_29 = 0 ;
V_30 ;
V_27 = F_2 ( & ( * V_10 ) -> V_31 , & V_32 ) ;
if ( V_27 == NULL )
RETURN ( - V_33 ) ;
F_3 ( ( V_27 -> V_34 & V_35 ) ) ;
if ( V_5 -> V_36 & V_37 )
V_5 -> V_36 = V_38 ;
V_28 = V_5 -> V_39 . V_40 . V_41 ;
if ( V_28 ) {
V_21 . V_42 = V_5 -> V_39 . V_40 . V_43 ;
V_5 -> V_39 . V_40 . V_41 = 0 ;
V_5 -> V_39 . V_40 . V_44 = NULL ;
}
F_3 ( F_4 ( & V_27 -> V_45 ) ) ;
V_25 = F_5 ( V_17 , & V_27 -> V_45 ) ;
if ( F_6 ( V_25 ) )
GOTO ( V_46 , V_29 = F_7 ( V_25 ) ) ;
F_8 ( V_23 ) ;
if ( V_23 == NULL )
GOTO ( V_46 , V_29 = - V_47 ) ;
V_23 -> V_48 = V_27 -> V_45 ;
if ( V_7 != NULL ) {
F_3 ( V_5 -> V_36 & V_49 ) ;
V_23 -> V_50 = * V_7 ;
V_23 -> V_51 = V_27 -> V_45 ;
}
V_23 -> V_52 = V_53 ;
F_9 ( V_54 , L_1 V_55 L_2 ,
F_10 ( & V_27 -> V_45 ) , V_25 -> V_56 ) ;
V_5 -> V_39 . V_40 . V_57 &= ~ V_58 ;
V_29 = F_11 ( V_25 -> V_59 , V_23 , V_2 , V_3 , V_5 ,
V_8 , & V_19 , V_11 , V_12 ) ;
if ( V_29 )
GOTO ( V_60 , V_29 ) ;
if ( V_5 -> V_39 . V_40 . V_41 != 0 ) {
V_5 -> V_39 . V_40 . V_61 =
V_5 -> V_39 . V_40 . V_43 ;
V_5 -> V_39 . V_40 . V_62 = V_5 -> V_39 . V_40 . V_41 ;
}
V_5 -> V_39 . V_40 . V_43 = V_21 . V_42 ;
V_5 -> V_39 . V_40 . V_41 = V_28 ;
EXIT ;
V_60:
F_12 ( V_23 ) ;
V_46:
if ( V_29 && V_28 )
F_13 ( & V_21 , V_28 ) ;
F_14 ( * V_10 ) ;
* V_10 = V_19 ;
return V_29 ;
}
int F_15 ( struct V_1 * exp , struct V_22 * V_23 ,
void * V_2 , int V_3 , struct V_4 * V_5 ,
int V_8 , struct V_9 * * V_10 ,
T_1 V_11 ,
T_2 V_12 )
{
struct V_13 * V_14 = exp -> V_15 ;
struct V_16 * V_17 = & V_14 -> V_18 . V_17 ;
struct V_24 * V_25 ;
struct V_26 * V_27 ;
int V_29 ;
V_30 ;
V_25 = F_16 ( V_17 , V_23 , & V_23 -> V_48 ) ;
if ( F_6 ( V_25 ) )
RETURN ( F_7 ( V_25 ) ) ;
if ( ( V_5 -> V_36 & V_63 ) &&
! ( V_5 -> V_64 & V_65 ) ) {
V_23 -> V_51 = V_23 -> V_50 ;
V_29 = F_17 ( exp , & V_23 -> V_50 , V_23 ) ;
if ( V_29 != 0 )
RETURN ( V_29 ) ;
}
F_9 ( V_54 , L_3 V_55 L_4 V_55 L_5
L_6 , F_10 ( & V_23 -> V_48 ) ,
F_10 ( & V_23 -> V_50 ) , V_23 -> V_66 , V_25 -> V_56 ) ;
V_29 = F_11 ( V_25 -> V_59 , V_23 , V_2 , V_3 , V_5 , V_8 ,
V_10 , V_11 , V_12 ) ;
if ( V_29 != 0 )
RETURN ( V_29 ) ;
if ( ( V_5 -> V_39 . V_40 . V_57 & V_67 ) &&
! ( V_5 -> V_39 . V_40 . V_57 & V_68 ) &&
! ( V_5 -> V_39 . V_40 . V_57 & V_69 ) )
RETURN ( V_29 ) ;
V_27 = F_2 ( & ( * V_10 ) -> V_31 , & V_32 ) ;
if ( V_27 == NULL )
RETURN ( - V_33 ) ;
if ( F_18 ( ! ( V_27 -> V_34 & V_35 ) ) )
RETURN ( 0 ) ;
V_29 = F_1 ( exp , V_2 , V_3 , V_5 , & V_23 -> V_48 , V_8 ,
V_10 , V_11 , V_12 ) ;
if ( V_29 != 0 ) {
F_3 ( V_29 < 0 ) ;
F_9 ( V_54 , L_7 V_55 L_8 V_55 L_9
L_10 , F_19 ( V_5 ) , F_10 ( & V_23 -> V_50 ) ,
F_10 ( & V_23 -> V_48 ) , V_23 -> V_70 ,
V_23 -> V_66 , V_29 ) ;
RETURN ( V_29 ) ;
}
RETURN ( V_29 ) ;
}
int F_20 ( struct V_1 * exp , struct V_22 * V_23 ,
void * V_2 , int V_3 , struct V_4 * V_5 ,
int V_8 , struct V_9 * * V_10 ,
T_1 V_11 ,
T_2 V_12 )
{
struct V_13 * V_14 = exp -> V_15 ;
struct V_16 * V_17 = & V_14 -> V_18 . V_17 ;
struct V_24 * V_25 = NULL ;
struct V_26 * V_27 ;
int V_29 = 0 ;
V_30 ;
V_25 = F_16 ( V_17 , V_23 , & V_23 -> V_48 ) ;
if ( F_6 ( V_25 ) )
RETURN ( F_7 ( V_25 ) ) ;
if ( ! F_4 ( & V_23 -> V_50 ) )
F_21 ( & V_23 -> V_50 ) ;
F_9 ( V_54 , L_11 V_55 L_4 V_55
L_12 , F_10 ( & V_23 -> V_48 ) ,
F_10 ( & V_23 -> V_50 ) ,
V_23 -> V_66 ? V_23 -> V_66 : L_13 ,
V_25 -> V_56 ) ;
V_23 -> V_52 &= ~ V_53 ;
V_29 = F_11 ( V_25 -> V_59 , V_23 , V_2 , V_3 , V_5 ,
V_8 , V_10 , V_11 , V_12 ) ;
if ( V_29 < 0 || * V_10 == NULL )
RETURN ( V_29 ) ;
V_27 = F_2 ( & ( * V_10 ) -> V_31 , & V_32 ) ;
if ( V_27 == NULL )
RETURN ( - V_33 ) ;
if ( F_18 ( ! ( V_27 -> V_34 & V_35 ) ) )
RETURN ( 0 ) ;
V_29 = F_1 ( exp , V_2 , V_3 , V_5 , NULL , V_8 , V_10 ,
V_11 , V_12 ) ;
RETURN ( V_29 ) ;
}
int F_22 ( struct V_1 * exp , struct V_22 * V_23 ,
void * V_2 , int V_3 , struct V_4 * V_5 ,
int V_8 , struct V_9 * * V_10 ,
T_1 V_11 ,
T_2 V_12 )
{
struct V_13 * V_14 = exp -> V_15 ;
int V_29 ;
V_30 ;
F_3 ( V_5 != NULL ) ;
F_3 ( F_4 ( & V_23 -> V_48 ) ) ;
F_9 ( V_54 , L_14 V_55 L_15 ,
F_19 ( V_5 ) , V_23 -> V_70 , V_23 -> V_66 ,
F_10 ( & V_23 -> V_48 ) ) ;
V_29 = F_23 ( V_14 ) ;
if ( V_29 )
RETURN ( V_29 ) ;
if ( V_5 -> V_36 & ( V_37 | V_38 | V_71 ) )
V_29 = F_20 ( exp , V_23 , V_2 , V_3 , V_5 ,
V_8 , V_10 , V_11 ,
V_12 ) ;
else if ( V_5 -> V_36 & V_49 )
V_29 = F_15 ( exp , V_23 , V_2 , V_3 , V_5 ,
V_8 , V_10 , V_11 ,
V_12 ) ;
else
F_24 () ;
RETURN ( V_29 ) ;
}
