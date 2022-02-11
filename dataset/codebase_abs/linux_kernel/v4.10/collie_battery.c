static unsigned long F_1 ( struct V_1 * V_2 )
{
unsigned long V_3 = 0 ;
if ( V_2 -> V_4 < 0 || V_2 -> V_5 < 0 )
return 0 ;
F_2 ( & V_6 ) ;
F_3 ( V_2 -> V_4 , 1 ) ;
F_4 ( 5 ) ;
F_5 ( V_7 ) ;
V_3 = F_6 ( V_7 , V_2 -> V_5 , V_8 ) ;
F_7 ( V_7 ) ;
F_3 ( V_2 -> V_4 , 0 ) ;
F_8 ( & V_6 ) ;
V_3 = V_3 * 1000000 / V_2 -> V_9 ;
return V_3 ;
}
static unsigned long F_9 ( struct V_1 * V_2 )
{
unsigned long V_3 = 0 ;
if ( V_2 -> V_10 < 0 || V_2 -> V_11 < 0 )
return 0 ;
F_2 ( & V_6 ) ;
F_3 ( V_2 -> V_10 , 1 ) ;
F_4 ( 5 ) ;
F_5 ( V_7 ) ;
V_3 = F_6 ( V_7 , V_2 -> V_11 , V_8 ) ;
F_7 ( V_7 ) ;
F_3 ( V_2 -> V_10 , 0 ) ;
F_8 ( & V_6 ) ;
V_3 = V_3 * 10000 / V_2 -> V_12 ;
return V_3 ;
}
static int F_10 ( struct V_13 * V_14 ,
enum V_15 V_16 ,
union V_17 * V_18 )
{
int V_19 = 0 ;
struct V_1 * V_2 = F_11 ( V_14 ) ;
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
V_18 -> V_24 = F_9 ( V_2 ) ;
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
static void F_12 ( struct V_13 * V_14 )
{
F_13 ( & V_37 ) ;
}
static T_1 F_14 ( int V_38 , void * V_39 )
{
F_15 ( L_1 ) ;
F_13 ( & V_37 ) ;
return V_40 ;
}
static void F_16 ( struct V_1 * V_2 )
{
int V_41 ;
struct V_13 * V_14 = V_2 -> V_14 ;
F_2 ( & V_2 -> V_42 ) ;
V_41 = V_2 -> V_25 ;
if ( V_2 -> V_20 && ! V_2 -> V_20 ( V_2 ) ) {
F_17 ( V_43 L_2 , V_14 -> V_44 -> V_45 ) ;
V_2 -> V_25 = V_46 ;
V_2 -> V_30 = - 1 ;
} else if ( F_18 ( V_14 ) ) {
if ( V_2 -> V_25 == V_47 ) {
F_3 ( V_2 -> V_48 , 1 ) ;
F_19 ( 15 ) ;
}
if ( F_20 ( V_2 -> V_49 ) ) {
if ( V_41 == V_50 ||
V_2 -> V_30 == - 1 )
V_2 -> V_30 = F_1 ( V_2 ) ;
F_3 ( V_2 -> V_48 , 0 ) ;
V_2 -> V_25 = V_51 ;
} else {
F_3 ( V_2 -> V_48 , 1 ) ;
V_2 -> V_25 = V_50 ;
}
} else {
F_3 ( V_2 -> V_48 , 0 ) ;
V_2 -> V_25 = V_47 ;
}
if ( V_41 != V_2 -> V_25 )
F_21 ( V_14 ) ;
F_8 ( & V_2 -> V_42 ) ;
}
static void F_22 ( struct V_52 * V_53 )
{
F_16 ( & V_54 ) ;
}
static int F_23 ( struct V_55 * V_56 )
{
F_24 ( & V_37 ) ;
if ( F_25 ( & V_56 -> V_7 -> V_56 ) &&
V_54 . V_25 == V_50 )
V_57 = ! F_26 ( F_27 ( V_58 ) ) ;
else
V_57 = 0 ;
return 0 ;
}
static int F_28 ( struct V_55 * V_56 )
{
if ( V_57 )
F_29 ( F_27 ( V_58 ) ) ;
F_13 ( & V_37 ) ;
return 0 ;
}
static int F_30 ( struct V_55 * V_56 )
{
int V_19 ;
struct V_59 V_60 = {} , V_61 = {} ;
if ( ! F_31 () )
return - V_22 ;
V_7 = V_56 -> V_7 ;
V_19 = F_32 ( V_62 ,
F_33 ( V_62 ) ) ;
if ( V_19 )
return V_19 ;
F_34 ( & V_54 . V_42 ) ;
F_35 ( & V_37 , F_22 ) ;
V_60 . V_63 = & V_54 ;
V_54 . V_14 = F_36 ( & V_56 -> V_7 -> V_56 ,
& V_64 ,
& V_60 ) ;
if ( F_37 ( V_54 . V_14 ) ) {
V_19 = F_38 ( V_54 . V_14 ) ;
goto V_65;
}
V_61 . V_63 = & V_66 ;
V_66 . V_14 = F_36 ( & V_56 -> V_7 -> V_56 ,
& V_67 ,
& V_61 ) ;
if ( F_37 ( V_66 . V_14 ) ) {
V_19 = F_38 ( V_66 . V_14 ) ;
goto V_68;
}
V_19 = F_39 ( F_27 ( V_58 ) ,
F_14 ,
V_69 | V_70 ,
L_3 , & V_54 ) ;
if ( V_19 )
goto V_71;
F_40 ( & V_7 -> V_56 , 1 ) ;
F_13 ( & V_37 ) ;
return 0 ;
V_71:
F_41 ( V_66 . V_14 ) ;
V_68:
F_41 ( V_54 . V_14 ) ;
V_65:
F_42 ( & V_37 ) ;
F_43 ( V_62 , F_33 ( V_62 ) ) ;
return V_19 ;
}
static void F_44 ( struct V_55 * V_56 )
{
F_45 ( F_27 ( V_58 ) , & V_54 ) ;
F_41 ( V_66 . V_14 ) ;
F_41 ( V_54 . V_14 ) ;
F_42 ( & V_37 ) ;
F_43 ( V_62 , F_33 ( V_62 ) ) ;
}
static int T_2 F_46 ( void )
{
return F_47 ( & V_72 ) ;
}
static void T_3 F_48 ( void )
{
F_49 ( & V_72 ) ;
}
