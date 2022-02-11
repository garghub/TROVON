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
V_27 = F_2 ( & ( * V_10 ) -> V_30 , & V_31 ) ;
if ( ! V_27 )
return - V_32 ;
F_3 ( ( V_27 -> V_33 & V_34 ) ) ;
if ( V_5 -> V_35 & V_36 )
V_5 -> V_35 = V_37 ;
V_28 = V_5 -> V_38 ;
if ( V_28 ) {
V_21 . V_39 = V_5 -> V_40 ;
V_5 -> V_38 = 0 ;
V_5 -> V_41 = NULL ;
}
F_3 ( F_4 ( & V_27 -> V_42 ) ) ;
V_25 = F_5 ( V_17 , & V_27 -> V_42 ) ;
if ( F_6 ( V_25 ) ) {
V_29 = F_7 ( V_25 ) ;
goto V_43;
}
V_23 = F_8 ( sizeof( * V_23 ) , V_44 ) ;
if ( ! V_23 ) {
V_29 = - V_45 ;
goto V_43;
}
V_23 -> V_46 = V_27 -> V_42 ;
if ( V_7 ) {
F_3 ( V_5 -> V_35 & V_47 ) ;
V_23 -> V_48 = * V_7 ;
V_23 -> V_49 = V_27 -> V_42 ;
}
V_23 -> V_50 = V_51 ;
F_9 ( V_52 , L_1 V_53 L_2 ,
F_10 ( & V_27 -> V_42 ) , V_25 -> V_54 ) ;
V_29 = F_11 ( V_25 -> V_55 , V_23 , V_2 , V_3 , V_5 ,
V_8 , & V_19 , V_11 , V_12 ) ;
if ( V_29 )
goto V_56;
if ( V_5 -> V_38 != 0 ) {
V_5 -> V_57 =
V_5 -> V_40 ;
V_5 -> V_58 = V_5 -> V_38 ;
}
V_5 -> V_40 = V_21 . V_39 ;
V_5 -> V_38 = V_28 ;
V_56:
F_12 ( V_23 ) ;
V_43:
if ( V_29 && V_28 )
F_13 ( & V_21 , V_28 ) ;
F_14 ( * V_10 ) ;
* V_10 = V_19 ;
return V_29 ;
}
static int F_15 ( struct V_1 * exp , struct V_22 * V_23 ,
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
V_25 = F_16 ( V_17 , V_23 , & V_23 -> V_46 ) ;
if ( F_6 ( V_25 ) )
return F_7 ( V_25 ) ;
if ( ( V_5 -> V_35 & V_59 ) &&
! ( V_5 -> V_60 & V_61 ) ) {
V_23 -> V_49 = V_23 -> V_48 ;
V_29 = F_17 ( exp , & V_23 -> V_48 , V_23 ) ;
if ( V_29 != 0 )
return V_29 ;
}
F_9 ( V_52 , L_3 V_53 L_4 V_53 L_5 ,
F_10 ( & V_23 -> V_46 ) ,
F_10 ( & V_23 -> V_48 ) , V_23 -> V_62 , V_25 -> V_54 ) ;
V_29 = F_11 ( V_25 -> V_55 , V_23 , V_2 , V_3 , V_5 , V_8 ,
V_10 , V_11 , V_12 ) ;
if ( V_29 != 0 )
return V_29 ;
if ( ( V_5 -> V_63 & V_64 ) &&
! ( V_5 -> V_63 & V_65 ) &&
! ( V_5 -> V_63 & V_66 ) )
return V_29 ;
V_27 = F_2 ( & ( * V_10 ) -> V_30 , & V_31 ) ;
if ( ! V_27 )
return - V_32 ;
if ( F_18 ( ! ( V_27 -> V_33 & V_34 ) ) )
return 0 ;
V_29 = F_1 ( exp , V_2 , V_3 , V_5 , & V_23 -> V_46 , V_8 ,
V_10 , V_11 , V_12 ) ;
if ( V_29 != 0 ) {
F_3 ( V_29 < 0 ) ;
F_9 ( V_52 , L_6 V_53 L_7 V_53 L_8 ,
F_19 ( V_5 ) , F_10 ( & V_23 -> V_48 ) ,
F_10 ( & V_23 -> V_46 ) , V_23 -> V_67 ,
V_23 -> V_62 , V_29 ) ;
return V_29 ;
}
return V_29 ;
}
static int F_20 ( struct V_1 * exp ,
struct V_22 * V_23 ,
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
V_25 = F_16 ( V_17 , V_23 , & V_23 -> V_46 ) ;
if ( F_6 ( V_25 ) )
return F_7 ( V_25 ) ;
if ( ! F_4 ( & V_23 -> V_48 ) )
F_21 ( & V_23 -> V_48 ) ;
F_9 ( V_52 , L_9 V_53 L_4 V_53
L_5 , F_10 ( & V_23 -> V_46 ) ,
F_10 ( & V_23 -> V_48 ) ,
V_23 -> V_62 ? V_23 -> V_62 : L_10 ,
V_25 -> V_54 ) ;
V_23 -> V_50 &= ~ V_51 ;
V_29 = F_11 ( V_25 -> V_55 , V_23 , V_2 , V_3 , V_5 ,
V_8 , V_10 , V_11 , V_12 ) ;
if ( V_29 < 0 || ! * V_10 )
return V_29 ;
V_27 = F_2 ( & ( * V_10 ) -> V_30 , & V_31 ) ;
if ( ! V_27 )
return - V_32 ;
if ( F_18 ( ! ( V_27 -> V_33 & V_34 ) ) )
return 0 ;
V_29 = F_1 ( exp , V_2 , V_3 , V_5 , NULL , V_8 , V_10 ,
V_11 , V_12 ) ;
return V_29 ;
}
int F_22 ( struct V_1 * exp , struct V_22 * V_23 ,
void * V_2 , int V_3 , struct V_4 * V_5 ,
int V_8 , struct V_9 * * V_10 ,
T_1 V_11 ,
T_2 V_12 )
{
struct V_13 * V_14 = exp -> V_15 ;
int V_29 ;
F_3 ( F_4 ( & V_23 -> V_46 ) ) ;
F_9 ( V_52 , L_11 V_53 L_12 ,
F_19 ( V_5 ) , V_23 -> V_67 , V_23 -> V_62 ,
F_10 ( & V_23 -> V_46 ) ) ;
V_29 = F_23 ( V_14 ) ;
if ( V_29 )
return V_29 ;
if ( V_5 -> V_35 & ( V_36 | V_37 | V_68 ) )
V_29 = F_20 ( exp , V_23 , V_2 , V_3 , V_5 ,
V_8 , V_10 , V_11 ,
V_12 ) ;
else if ( V_5 -> V_35 & V_47 )
V_29 = F_15 ( exp , V_23 , V_2 , V_3 , V_5 ,
V_8 , V_10 , V_11 ,
V_12 ) ;
else
F_24 () ;
return V_29 ;
}
