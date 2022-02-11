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
struct V_1 * V_2 = F_11 ( V_14 , struct V_1 , V_14 ) ;
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
struct V_13 * V_14 = & V_2 -> V_14 ;
F_2 ( & V_2 -> V_42 ) ;
V_41 = V_2 -> V_25 ;
if ( V_2 -> V_20 && ! V_2 -> V_20 ( V_2 ) ) {
F_17 ( V_43 L_2 , V_14 -> V_44 ) ;
V_2 -> V_25 = V_45 ;
V_2 -> V_30 = - 1 ;
} else if ( F_18 ( V_14 ) ) {
if ( V_2 -> V_25 == V_46 ) {
F_3 ( V_2 -> V_47 , 1 ) ;
F_19 ( 15 ) ;
}
if ( F_20 ( V_2 -> V_48 ) ) {
if ( V_41 == V_49 ||
V_2 -> V_30 == - 1 )
V_2 -> V_30 = F_1 ( V_2 ) ;
F_3 ( V_2 -> V_47 , 0 ) ;
V_2 -> V_25 = V_50 ;
} else {
F_3 ( V_2 -> V_47 , 1 ) ;
V_2 -> V_25 = V_49 ;
}
} else {
F_3 ( V_2 -> V_47 , 0 ) ;
V_2 -> V_25 = V_46 ;
}
if ( V_41 != V_2 -> V_25 )
F_21 ( V_14 ) ;
F_8 ( & V_2 -> V_42 ) ;
}
static void F_22 ( struct V_51 * V_52 )
{
F_16 ( & V_53 ) ;
}
static int F_23 ( struct V_54 * V_55 )
{
F_24 ( & V_37 ) ;
if ( F_25 ( & V_55 -> V_7 -> V_55 ) &&
V_53 . V_25 == V_49 )
V_56 = ! F_26 ( F_27 ( V_57 ) ) ;
else
V_56 = 0 ;
return 0 ;
}
static int F_28 ( struct V_54 * V_55 )
{
if ( V_56 )
F_29 ( F_27 ( V_57 ) ) ;
F_13 ( & V_37 ) ;
return 0 ;
}
static int F_30 ( struct V_54 * V_55 )
{
int V_19 ;
if ( ! F_31 () )
return - V_22 ;
V_7 = V_55 -> V_7 ;
V_19 = F_32 ( V_58 ,
F_33 ( V_58 ) ) ;
if ( V_19 )
return V_19 ;
F_34 ( & V_53 . V_42 ) ;
F_35 ( & V_37 , F_22 ) ;
V_19 = F_36 ( & V_55 -> V_7 -> V_55 , & V_53 . V_14 ) ;
if ( V_19 )
goto V_59;
V_19 = F_36 ( & V_55 -> V_7 -> V_55 , & V_60 . V_14 ) ;
if ( V_19 )
goto V_61;
V_19 = F_37 ( F_27 ( V_57 ) ,
F_14 ,
V_62 | V_63 ,
L_3 , & V_53 ) ;
if ( V_19 )
goto V_64;
F_38 ( & V_7 -> V_55 , 1 ) ;
F_13 ( & V_37 ) ;
return 0 ;
V_64:
F_39 ( & V_60 . V_14 ) ;
V_61:
F_39 ( & V_53 . V_14 ) ;
V_59:
F_40 ( & V_37 ) ;
F_41 ( V_58 , F_33 ( V_58 ) ) ;
return V_19 ;
}
static void F_42 ( struct V_54 * V_55 )
{
F_43 ( F_27 ( V_57 ) , & V_53 ) ;
F_39 ( & V_60 . V_14 ) ;
F_39 ( & V_53 . V_14 ) ;
F_40 ( & V_37 ) ;
F_41 ( V_58 , F_33 ( V_58 ) ) ;
}
static int T_2 F_44 ( void )
{
return F_45 ( & V_65 ) ;
}
static void T_3 F_46 ( void )
{
F_47 ( & V_65 ) ;
}
