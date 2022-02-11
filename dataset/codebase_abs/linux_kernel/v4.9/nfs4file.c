static int
F_1 ( struct V_1 * V_1 , struct V_2 * V_3 )
{
struct V_4 * V_5 ;
struct V_6 * V_6 = F_2 ( V_3 ) ;
struct V_6 * V_7 = NULL ;
struct V_1 * V_8 ;
unsigned V_9 = V_3 -> V_10 ;
struct V_11 V_12 ;
int V_13 ;
F_3 ( L_1 , V_6 ) ;
V_13 = F_4 ( V_9 ) ;
if ( V_13 )
return V_13 ;
if ( ( V_9 & V_14 ) == 3 )
V_9 -- ;
V_9 &= ~ ( V_15 | V_16 ) ;
V_7 = F_5 ( V_6 ) ;
V_8 = F_6 ( V_7 ) ;
V_5 = F_7 ( F_2 ( V_3 ) , V_3 -> V_17 ) ;
V_13 = F_8 ( V_5 ) ;
if ( F_9 ( V_5 ) )
goto V_18;
V_12 . V_19 = V_20 ;
if ( V_9 & V_21 ) {
V_12 . V_19 |= V_22 ;
V_12 . V_23 = 0 ;
F_10 ( V_1 -> V_24 ) ;
}
V_1 = F_11 ( V_8 ) -> F_12 ( V_8 , V_5 , V_9 , & V_12 , NULL ) ;
if ( F_9 ( V_1 ) ) {
V_13 = F_8 ( V_1 ) ;
switch ( V_13 ) {
case - V_25 :
case - V_26 :
case - V_27 :
case - V_28 :
case - V_29 :
goto V_30;
default:
goto V_31;
}
}
if ( V_1 != F_6 ( V_6 ) )
goto V_31;
F_13 ( V_6 , F_14 ( V_8 ) ) ;
F_15 ( V_3 , V_5 ) ;
F_16 ( V_1 , V_3 ) ;
V_13 = 0 ;
V_30:
F_17 ( V_5 ) ;
V_18:
F_18 ( V_7 ) ;
return V_13 ;
V_31:
F_19 ( V_6 ) ;
V_13 = - V_32 ;
goto V_30;
}
static int
F_20 ( struct V_2 * V_2 , T_1 V_33 )
{
struct V_1 * V_1 = F_21 ( V_2 ) ;
F_3 ( L_2 , V_2 ) ;
F_22 ( V_1 , V_34 ) ;
if ( ( V_2 -> V_17 & V_35 ) == 0 )
return 0 ;
if ( ! F_23 ( V_1 ) )
return F_24 ( V_2 -> V_36 ) ;
return F_25 ( V_2 , 0 ) ;
}
static T_2 F_26 ( struct V_2 * V_37 , T_3 V_38 ,
struct V_2 * V_39 , T_3 V_40 ,
T_4 V_41 , unsigned int V_42 )
{
if ( F_21 ( V_37 ) == F_21 ( V_39 ) )
return - V_43 ;
return F_27 ( V_37 , V_38 , V_39 , V_40 , V_41 ) ;
}
static T_3 F_28 ( struct V_2 * V_44 , T_3 V_45 , int V_46 )
{
T_3 V_47 ;
switch ( V_46 ) {
case V_48 :
case V_49 :
V_47 = F_29 ( V_44 , V_45 , V_46 ) ;
if ( V_47 != - V_50 )
return V_47 ;
default:
return F_30 ( V_44 , V_45 , V_46 ) ;
}
}
static long F_31 ( struct V_2 * V_44 , int V_51 , T_3 V_45 , T_3 V_52 )
{
struct V_1 * V_1 = F_21 ( V_44 ) ;
long V_47 ;
if ( ! F_32 ( V_1 -> V_53 ) )
return - V_54 ;
if ( ( V_51 != 0 ) && ( V_51 != ( V_55 | V_56 ) ) )
return - V_54 ;
V_47 = F_33 ( V_1 , V_45 + V_52 ) ;
if ( V_47 < 0 )
return V_47 ;
if ( V_51 & V_55 )
return F_34 ( V_44 , V_45 , V_52 ) ;
return F_35 ( V_44 , V_45 , V_52 ) ;
}
static int F_36 ( struct V_2 * V_57 , T_3 V_58 ,
struct V_2 * V_59 , T_3 V_60 , T_5 V_41 )
{
struct V_1 * V_61 = F_21 ( V_59 ) ;
struct V_62 * V_63 = F_37 ( V_61 ) ;
struct V_1 * V_64 = F_21 ( V_57 ) ;
unsigned int V_65 = V_63 -> V_66 ;
bool V_67 = false ;
int V_47 ;
V_47 = - V_43 ;
if ( V_65 ) {
if ( ! F_38 ( V_58 , V_65 ) || ! F_38 ( V_60 , V_65 ) )
goto V_18;
if ( ! F_38 ( V_41 , V_65 ) && F_39 ( V_64 ) != ( V_58 + V_41 ) )
goto V_18;
}
if ( V_64 == V_61 )
V_67 = true ;
if ( V_67 ) {
F_40 ( V_64 ) ;
} else if ( V_61 < V_64 ) {
F_41 ( V_61 , V_68 ) ;
F_41 ( V_64 , V_69 ) ;
} else {
F_41 ( V_64 , V_68 ) ;
F_41 ( V_61 , V_69 ) ;
}
V_47 = F_42 ( V_64 ) ;
if ( V_47 )
goto V_70;
V_47 = F_42 ( V_61 ) ;
if ( V_47 )
goto V_70;
V_47 = F_43 ( V_57 , V_59 , V_58 , V_60 , V_41 ) ;
if ( ! V_47 )
F_44 ( & V_61 -> V_71 , V_60 , V_60 + V_41 - 1 ) ;
V_70:
if ( V_67 ) {
F_45 ( V_64 ) ;
} else if ( V_61 < V_64 ) {
F_45 ( V_64 ) ;
F_45 ( V_61 ) ;
} else {
F_45 ( V_61 ) ;
F_45 ( V_64 ) ;
}
V_18:
return V_47 ;
}
