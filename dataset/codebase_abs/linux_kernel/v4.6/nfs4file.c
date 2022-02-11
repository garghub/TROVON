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
static T_2 F_26 ( struct V_2 * V_36 , T_2 V_37 , int V_38 )
{
T_2 V_39 ;
switch ( V_38 ) {
case V_40 :
case V_41 :
V_39 = F_27 ( V_36 , V_37 , V_38 ) ;
if ( V_39 != - V_42 )
return V_39 ;
default:
return F_28 ( V_36 , V_37 , V_38 ) ;
}
}
static long F_29 ( struct V_2 * V_36 , int V_43 , T_2 V_37 , T_2 V_44 )
{
struct V_1 * V_1 = F_21 ( V_36 ) ;
long V_39 ;
if ( ! F_30 ( V_1 -> V_45 ) )
return - V_46 ;
if ( ( V_43 != 0 ) && ( V_43 != ( V_47 | V_48 ) ) )
return - V_46 ;
V_39 = F_31 ( V_1 , V_37 + V_44 ) ;
if ( V_39 < 0 )
return V_39 ;
if ( V_43 & V_47 )
return F_32 ( V_36 , V_37 , V_44 ) ;
return F_33 ( V_36 , V_37 , V_44 ) ;
}
static int F_34 ( struct V_2 * V_49 , T_2 V_50 ,
struct V_2 * V_51 , T_2 V_52 , T_3 V_53 )
{
struct V_1 * V_54 = F_21 ( V_51 ) ;
struct V_55 * V_56 = F_35 ( V_54 ) ;
struct V_1 * V_57 = F_21 ( V_49 ) ;
unsigned int V_58 = V_56 -> V_59 ;
bool V_60 = false ;
int V_39 ;
V_39 = - V_61 ;
if ( V_58 ) {
if ( ! F_36 ( V_50 , V_58 ) || ! F_36 ( V_52 , V_58 ) )
goto V_18;
if ( ! F_36 ( V_53 , V_58 ) && F_37 ( V_57 ) != ( V_50 + V_53 ) )
goto V_18;
}
if ( V_57 == V_54 )
V_60 = true ;
if ( V_60 ) {
F_38 ( V_57 ) ;
} else if ( V_54 < V_57 ) {
F_39 ( V_54 , V_62 ) ;
F_39 ( V_57 , V_63 ) ;
} else {
F_39 ( V_57 , V_62 ) ;
F_39 ( V_54 , V_63 ) ;
}
V_39 = F_10 ( V_57 ) ;
if ( V_39 )
goto V_64;
V_39 = F_10 ( V_54 ) ;
if ( V_39 )
goto V_64;
V_39 = F_40 ( V_49 , V_51 , V_50 , V_52 , V_53 ) ;
if ( ! V_39 )
F_41 ( & V_54 -> V_65 , V_52 , V_52 + V_53 - 1 ) ;
V_64:
if ( V_60 ) {
F_42 ( V_57 ) ;
} else if ( V_54 < V_57 ) {
F_42 ( V_57 ) ;
F_42 ( V_54 ) ;
} else {
F_42 ( V_54 ) ;
F_42 ( V_57 ) ;
}
V_18:
return V_39 ;
}
