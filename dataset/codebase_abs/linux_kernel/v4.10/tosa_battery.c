static unsigned long F_1 ( struct V_1 * V_2 )
{
unsigned long V_3 = 0 ;
if ( V_2 -> V_4 < 0 || V_2 -> V_5 < 0 )
return 0 ;
F_2 ( & V_6 ) ;
F_3 ( V_2 -> V_4 , 1 ) ;
F_4 ( 5 ) ;
V_3 = F_5 ( F_6 ( V_2 -> V_7 -> V_8 . V_9 ) ,
V_2 -> V_5 ) ;
F_3 ( V_2 -> V_4 , 0 ) ;
F_7 ( & V_6 ) ;
V_3 = V_3 * 1000000 / V_2 -> V_10 ;
return V_3 ;
}
static unsigned long F_8 ( struct V_1 * V_2 )
{
unsigned long V_3 = 0 ;
if ( V_2 -> V_11 < 0 || V_2 -> V_12 < 0 )
return 0 ;
F_2 ( & V_6 ) ;
F_3 ( V_2 -> V_11 , 1 ) ;
F_4 ( 5 ) ;
V_3 = F_5 ( F_6 ( V_2 -> V_7 -> V_8 . V_9 ) ,
V_2 -> V_12 ) ;
F_3 ( V_2 -> V_11 , 0 ) ;
F_7 ( & V_6 ) ;
V_3 = V_3 * 10000 / V_2 -> V_13 ;
return V_3 ;
}
static int F_9 ( struct V_14 * V_7 ,
enum V_15 V_16 ,
union V_17 * V_18 )
{
int V_19 = 0 ;
struct V_1 * V_2 = F_10 ( V_7 ) ;
if ( V_2 -> V_20 && ! V_2 -> V_20 ( V_2 )
&& V_16 != V_21 ) {
return - V_22 ;
}
switch ( V_16 ) {
case V_23 :
V_18 -> V_24 = V_2 -> V_25 ;
break;
case V_26 :
V_18 -> V_24 = V_2 -> V_27 ;
break;
case V_28 :
V_18 -> V_24 = F_1 ( V_2 ) ;
break;
case V_29 :
if ( V_2 -> V_30 == - 1 )
V_18 -> V_24 = V_2 -> V_31 ;
else
V_18 -> V_24 = V_2 -> V_30 ;
break;
case V_32 :
V_18 -> V_24 = V_2 -> V_31 ;
break;
case V_33 :
V_18 -> V_24 = V_2 -> V_34 ;
break;
case V_35 :
V_18 -> V_24 = F_8 ( V_2 ) ;
break;
case V_21 :
V_18 -> V_24 = V_2 -> V_20 ? V_2 -> V_20 ( V_2 ) : 1 ;
break;
default:
V_19 = - V_36 ;
break;
}
return V_19 ;
}
static bool F_11 ( struct V_1 * V_2 )
{
return F_12 ( V_37 ) == 0 ;
}
static void F_13 ( struct V_14 * V_7 )
{
F_14 ( & V_38 ) ;
}
static T_1 F_15 ( int V_39 , void * V_40 )
{
F_16 ( L_1 ) ;
F_14 ( & V_38 ) ;
return V_41 ;
}
static void F_17 ( struct V_1 * V_2 )
{
int V_42 ;
struct V_14 * V_7 = V_2 -> V_7 ;
F_2 ( & V_2 -> V_43 ) ;
V_42 = V_2 -> V_25 ;
if ( V_2 -> V_20 && ! V_2 -> V_20 ( V_2 ) ) {
F_18 ( V_44 L_2 , V_7 -> V_45 -> V_46 ) ;
V_2 -> V_25 = V_47 ;
V_2 -> V_30 = - 1 ;
} else if ( F_19 ( V_7 ) ) {
if ( V_2 -> V_25 == V_48 ) {
F_3 ( V_2 -> V_49 , 0 ) ;
F_20 ( 15 ) ;
}
if ( F_12 ( V_2 -> V_50 ) ) {
if ( V_42 == V_51 ||
V_2 -> V_30 == - 1 )
V_2 -> V_30 = F_1 ( V_2 ) ;
F_3 ( V_2 -> V_49 , 1 ) ;
V_2 -> V_25 = V_52 ;
} else {
F_3 ( V_2 -> V_49 , 0 ) ;
V_2 -> V_25 = V_51 ;
}
} else {
F_3 ( V_2 -> V_49 , 1 ) ;
V_2 -> V_25 = V_48 ;
}
if ( V_42 != V_2 -> V_25 )
F_21 ( V_7 ) ;
F_7 ( & V_2 -> V_43 ) ;
}
static void F_22 ( struct V_53 * V_54 )
{
F_17 ( & V_55 ) ;
F_17 ( & V_56 ) ;
}
static int F_23 ( struct V_57 * V_8 , T_2 V_58 )
{
F_24 ( & V_38 ) ;
return 0 ;
}
static int F_25 ( struct V_57 * V_8 )
{
F_14 ( & V_38 ) ;
return 0 ;
}
static int F_26 ( struct V_57 * V_8 )
{
int V_19 ;
struct V_59 V_60 = {} ,
V_61 = {} ,
V_62 = {} ;
if ( ! F_27 () )
return - V_22 ;
V_19 = F_28 ( V_63 , F_29 ( V_63 ) ) ;
if ( V_19 )
return V_19 ;
F_30 ( & V_55 . V_43 ) ;
F_30 ( & V_56 . V_43 ) ;
F_31 ( & V_38 , F_22 ) ;
V_60 . V_64 = & V_55 ;
V_55 . V_7 = F_32 ( & V_8 -> V_8 ,
& V_65 ,
& V_60 ) ;
if ( F_33 ( V_55 . V_7 ) ) {
V_19 = F_34 ( V_55 . V_7 ) ;
goto V_66;
}
V_61 . V_64 = & V_56 ;
V_56 . V_7 = F_32 ( & V_8 -> V_8 ,
& V_67 ,
& V_61 ) ;
if ( F_33 ( V_56 . V_7 ) ) {
V_19 = F_34 ( V_56 . V_7 ) ;
goto V_68;
}
V_62 . V_64 = & V_69 ;
V_69 . V_7 = F_32 ( & V_8 -> V_8 , & V_70 ,
& V_62 ) ;
if ( F_33 ( V_69 . V_7 ) ) {
V_19 = F_34 ( V_69 . V_7 ) ;
goto V_71;
}
V_19 = F_35 ( F_36 ( V_72 ) ,
F_15 ,
V_73 | V_74 ,
L_3 , & V_55 ) ;
if ( V_19 )
goto V_75;
V_19 = F_35 ( F_36 ( V_76 ) ,
F_15 ,
V_73 | V_74 ,
L_4 , & V_56 ) ;
if ( V_19 )
goto V_77;
V_19 = F_35 ( F_36 ( V_37 ) ,
F_15 ,
V_73 | V_74 ,
L_5 , & V_56 ) ;
if ( ! V_19 ) {
F_14 ( & V_38 ) ;
return 0 ;
}
F_37 ( F_36 ( V_76 ) , & V_56 ) ;
V_77:
F_37 ( F_36 ( V_72 ) , & V_55 ) ;
V_75:
F_38 ( V_69 . V_7 ) ;
V_71:
F_38 ( V_56 . V_7 ) ;
V_68:
F_38 ( V_55 . V_7 ) ;
V_66:
F_39 ( & V_38 ) ;
F_40 ( V_63 , F_29 ( V_63 ) ) ;
return V_19 ;
}
static int F_41 ( struct V_57 * V_8 )
{
F_37 ( F_36 ( V_37 ) , & V_56 ) ;
F_37 ( F_36 ( V_76 ) , & V_56 ) ;
F_37 ( F_36 ( V_72 ) , & V_55 ) ;
F_38 ( V_69 . V_7 ) ;
F_38 ( V_56 . V_7 ) ;
F_38 ( V_55 . V_7 ) ;
F_39 ( & V_38 ) ;
F_40 ( V_63 , F_29 ( V_63 ) ) ;
return 0 ;
}
