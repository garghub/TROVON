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
F_10 ( V_1 ) ;
}
V_1 = F_11 ( V_8 ) -> F_12 ( V_8 , V_5 , V_9 , & V_12 , NULL ) ;
if ( F_9 ( V_1 ) ) {
V_13 = F_8 ( V_1 ) ;
switch ( V_13 ) {
case - V_24 :
case - V_25 :
case - V_26 :
case - V_27 :
case - V_28 :
goto V_29;
default:
goto V_30;
}
}
if ( V_1 != F_6 ( V_6 ) )
goto V_30;
F_13 ( V_6 , F_14 ( V_8 ) ) ;
F_15 ( V_3 , V_5 ) ;
F_16 ( V_1 , V_3 ) ;
V_13 = 0 ;
V_29:
F_17 ( V_5 ) ;
V_18:
F_18 ( V_7 ) ;
return V_13 ;
V_30:
F_19 ( V_6 ) ;
V_13 = - V_31 ;
goto V_29;
}
static int
F_20 ( struct V_2 * V_2 , T_1 V_32 )
{
struct V_1 * V_1 = F_21 ( V_2 ) ;
F_3 ( L_2 , V_2 ) ;
F_22 ( V_1 , V_33 ) ;
if ( ( V_2 -> V_17 & V_34 ) == 0 )
return 0 ;
if ( ! F_23 ( V_1 ) )
return F_24 ( V_2 -> V_35 ) ;
return F_25 ( V_2 , 0 ) ;
}
static T_2 F_26 ( struct V_2 * V_36 , T_3 V_37 ,
struct V_2 * V_38 , T_3 V_39 ,
T_4 V_40 , unsigned int V_41 )
{
struct V_1 * V_42 = F_21 ( V_36 ) ;
struct V_1 * V_43 = F_21 ( V_38 ) ;
int V_44 ;
if ( V_42 == V_43 )
return - V_45 ;
V_44 = F_10 ( V_42 ) ;
if ( V_44 )
return V_44 ;
V_44 = F_10 ( V_43 ) ;
if ( V_44 )
return V_44 ;
return F_27 ( V_36 , V_37 , V_38 , V_39 , V_40 ) ;
}
static T_3 F_28 ( struct V_2 * V_46 , T_3 V_47 , int V_48 )
{
T_3 V_44 ;
switch ( V_48 ) {
case V_49 :
case V_50 :
V_44 = F_29 ( V_46 , V_47 , V_48 ) ;
if ( V_44 != - V_51 )
return V_44 ;
default:
return F_30 ( V_46 , V_47 , V_48 ) ;
}
}
static long F_31 ( struct V_2 * V_46 , int V_52 , T_3 V_47 , T_3 V_53 )
{
struct V_1 * V_1 = F_21 ( V_46 ) ;
long V_44 ;
if ( ! F_32 ( V_1 -> V_54 ) )
return - V_55 ;
if ( ( V_52 != 0 ) && ( V_52 != ( V_56 | V_57 ) ) )
return - V_55 ;
V_44 = F_33 ( V_1 , V_47 + V_53 ) ;
if ( V_44 < 0 )
return V_44 ;
if ( V_52 & V_56 )
return F_34 ( V_46 , V_47 , V_53 ) ;
return F_35 ( V_46 , V_47 , V_53 ) ;
}
static int F_36 ( struct V_2 * V_58 , T_3 V_59 ,
struct V_2 * V_60 , T_3 V_61 , T_5 V_40 )
{
struct V_1 * V_62 = F_21 ( V_60 ) ;
struct V_63 * V_64 = F_37 ( V_62 ) ;
struct V_1 * V_65 = F_21 ( V_58 ) ;
unsigned int V_66 = V_64 -> V_67 ;
bool V_68 = false ;
int V_44 ;
V_44 = - V_45 ;
if ( V_66 ) {
if ( ! F_38 ( V_59 , V_66 ) || ! F_38 ( V_61 , V_66 ) )
goto V_18;
if ( ! F_38 ( V_40 , V_66 ) && F_39 ( V_65 ) != ( V_59 + V_40 ) )
goto V_18;
}
if ( V_65 == V_62 )
V_68 = true ;
if ( V_68 ) {
F_40 ( V_65 ) ;
} else if ( V_62 < V_65 ) {
F_41 ( V_62 , V_69 ) ;
F_41 ( V_65 , V_70 ) ;
} else {
F_41 ( V_65 , V_69 ) ;
F_41 ( V_62 , V_70 ) ;
}
V_44 = F_10 ( V_65 ) ;
if ( V_44 )
goto V_71;
V_44 = F_10 ( V_62 ) ;
if ( V_44 )
goto V_71;
V_44 = F_42 ( V_58 , V_60 , V_59 , V_61 , V_40 ) ;
if ( ! V_44 )
F_43 ( & V_62 -> V_72 , V_61 , V_61 + V_40 - 1 ) ;
V_71:
if ( V_68 ) {
F_44 ( V_65 ) ;
} else if ( V_62 < V_65 ) {
F_44 ( V_65 ) ;
F_44 ( V_62 ) ;
} else {
F_44 ( V_62 ) ;
F_44 ( V_65 ) ;
}
V_18:
return V_44 ;
}
