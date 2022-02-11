static int F_1 ( struct V_1 * V_2 , int V_3 ,
struct V_4 * V_5 )
{
struct V_6 * V_7 = F_2 ( V_5 ) ;
unsigned int V_8 , V_9 ;
if ( V_2 -> V_10 == V_11 )
V_8 = V_12 ;
else
V_8 = V_13 ;
switch ( V_3 ) {
case V_14 :
case V_15 :
case V_16 :
V_9 = V_8 ;
break;
case V_17 :
case V_18 :
case V_19 :
V_9 = 0 ;
break;
default:
return - V_20 ;
}
F_3 ( V_7 -> V_21 , V_22 , V_8 , V_9 ) ;
return 0 ;
}
static int F_4 ( struct V_1 * V_2 ,
struct V_23 * V_24 , struct V_4 * V_5 )
{
struct V_6 * V_7 = F_2 ( V_5 ) ;
unsigned int V_25 , V_26 ;
unsigned int V_27 ;
V_27 = F_5 ( V_24 ) * V_28 ;
V_26 = V_28 / 2 - 1 ;
V_25 = F_6 ( F_7 ( V_7 -> V_29 ) , V_27 ) / 2 - 1 ;
F_8 ( V_7 -> V_21 , V_30 , ( V_26 << 16 ) |
V_25 ) ;
return 0 ;
}
static int F_9 ( struct V_1 * V_2 ,
struct V_4 * V_5 )
{
struct V_6 * V_7 = F_2 ( V_5 ) ;
T_1 V_8 ;
int V_31 ;
if ( V_2 -> V_10 == V_11 )
V_8 = V_32 ;
else
V_8 = V_33 ;
F_8 ( V_7 -> V_21 , V_34 , V_8 ) ;
V_31 = F_10 ( V_2 -> V_35 , 0 ,
V_36 ,
& V_7 -> V_37 ) ;
if ( V_31 )
return V_31 ;
return F_11 ( V_7 -> V_29 ) ;
}
static void F_12 ( struct V_1 * V_2 ,
struct V_4 * V_5 )
{
struct V_6 * V_7 = F_2 ( V_5 ) ;
F_13 ( V_7 -> V_29 ) ;
}
static int F_14 ( struct V_4 * V_5 )
{
struct V_6 * V_7 = F_2 ( V_5 ) ;
F_15 ( V_5 , & V_7 -> V_38 ,
& V_7 -> V_39 ) ;
return 0 ;
}
static int F_16 ( struct V_40 * V_41 )
{
struct V_42 * V_43 ;
struct V_6 * V_7 ;
void T_2 * V_44 ;
int V_31 ;
V_7 = F_17 ( & V_41 -> V_45 , sizeof( * V_7 ) , V_46 ) ;
if ( ! V_7 )
return - V_47 ;
F_18 ( V_41 , V_7 ) ;
V_43 = F_19 ( V_41 , V_48 , 0 ) ;
V_44 = F_20 ( & V_41 -> V_45 , V_43 ) ;
if ( F_21 ( V_44 ) )
return F_22 ( V_44 ) ;
V_7 -> V_21 = F_23 ( & V_41 -> V_45 , V_44 ,
& V_49 ) ;
if ( F_21 ( V_7 -> V_21 ) )
return F_22 ( V_7 -> V_21 ) ;
V_7 -> V_50 = F_24 ( & V_41 -> V_45 , L_1 ) ;
if ( F_21 ( V_7 -> V_50 ) )
return F_22 ( V_7 -> V_50 ) ;
V_7 -> V_29 = F_24 ( & V_41 -> V_45 , L_2 ) ;
if ( F_21 ( V_7 -> V_29 ) )
return F_22 ( V_7 -> V_29 ) ;
V_31 = F_11 ( V_7 -> V_50 ) ;
if ( V_31 )
return V_31 ;
V_7 -> V_38 . V_51 = V_43 -> V_52 + V_53 ;
V_7 -> V_38 . V_54 = 4 ;
V_7 -> V_38 . V_55 = 1 ;
V_7 -> V_39 . V_51 = V_43 -> V_52 + V_56 ;
V_7 -> V_39 . V_54 = 4 ;
V_7 -> V_39 . V_55 = 1 ;
V_7 -> V_57 . V_58 = F_7 ( V_7 -> V_29 ) / 2 / V_28 ;
V_7 -> V_57 . V_59 = 1 ;
V_7 -> V_57 . V_60 = 1 ;
V_7 -> V_57 . V_61 = 64 ;
V_7 -> V_37 . V_62 = & V_7 -> V_57 ;
V_7 -> V_37 . V_63 = 1 ;
F_8 ( V_7 -> V_21 , V_34 , V_64 ) ;
V_31 = F_25 ( & V_41 -> V_45 , & V_65 ,
& V_66 , 1 ) ;
if ( V_31 )
goto V_67;
V_31 = F_26 ( & V_41 -> V_45 , NULL , 0 ) ;
if ( V_31 )
goto V_67;
return 0 ;
V_67:
F_13 ( V_7 -> V_50 ) ;
return V_31 ;
}
static int F_27 ( struct V_40 * V_41 )
{
struct V_6 * V_7 = F_28 ( V_41 ) ;
F_13 ( V_7 -> V_50 ) ;
return 0 ;
}
