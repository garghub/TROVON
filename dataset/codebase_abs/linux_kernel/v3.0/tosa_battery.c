static unsigned long F_1 ( struct V_1 * V_2 )
{
unsigned long V_3 = 0 ;
if ( V_2 -> V_4 < 0 || V_2 -> V_5 < 0 )
return 0 ;
F_2 ( & V_6 ) ;
F_3 ( V_2 -> V_4 , 1 ) ;
F_4 ( 5 ) ;
V_3 = F_5 ( F_6 ( V_2 -> V_7 . V_8 -> V_9 ) ,
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
V_3 = F_5 ( F_6 ( V_2 -> V_7 . V_8 -> V_9 ) ,
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
struct V_1 * V_2 = F_10 ( V_7 , struct V_1 , V_7 ) ;
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
F_16 ( L_1 , F_12 ( F_17 ( V_39 ) ) ) ;
F_14 ( & V_38 ) ;
return V_41 ;
}
static void F_18 ( struct V_1 * V_2 )
{
int V_42 ;
struct V_14 * V_7 = & V_2 -> V_7 ;
F_2 ( & V_2 -> V_43 ) ;
V_42 = V_2 -> V_25 ;
if ( V_2 -> V_20 && ! V_2 -> V_20 ( V_2 ) ) {
F_19 ( V_44 L_2 , V_7 -> V_45 ) ;
V_2 -> V_25 = V_46 ;
V_2 -> V_30 = - 1 ;
} else if ( F_20 ( V_7 ) ) {
if ( V_2 -> V_25 == V_47 ) {
F_3 ( V_2 -> V_48 , 0 ) ;
F_21 ( 15 ) ;
}
if ( F_12 ( V_2 -> V_49 ) ) {
if ( V_42 == V_50 ||
V_2 -> V_30 == - 1 )
V_2 -> V_30 = F_1 ( V_2 ) ;
F_3 ( V_2 -> V_48 , 1 ) ;
V_2 -> V_25 = V_51 ;
} else {
F_3 ( V_2 -> V_48 , 0 ) ;
V_2 -> V_25 = V_50 ;
}
} else {
F_3 ( V_2 -> V_48 , 1 ) ;
V_2 -> V_25 = V_47 ;
}
if ( V_42 != V_2 -> V_25 )
F_22 ( V_7 ) ;
F_7 ( & V_2 -> V_43 ) ;
}
static void F_23 ( struct V_52 * V_53 )
{
F_18 ( & V_54 ) ;
F_18 ( & V_55 ) ;
}
static int F_24 ( struct V_56 * V_8 , T_2 V_57 )
{
F_25 ( & V_38 ) ;
return 0 ;
}
static int F_26 ( struct V_56 * V_8 )
{
F_14 ( & V_38 ) ;
return 0 ;
}
static int T_3 F_27 ( struct V_56 * V_8 )
{
int V_19 ;
int V_58 ;
if ( ! F_28 () )
return - V_22 ;
for ( V_58 = 0 ; V_58 < F_29 ( V_59 ) ; V_58 ++ ) {
V_19 = F_30 ( V_59 [ V_58 ] . V_60 , V_59 [ V_58 ] . V_45 ) ;
if ( V_19 ) {
V_58 -- ;
goto V_61;
}
if ( V_59 [ V_58 ] . V_62 )
V_19 = F_31 ( V_59 [ V_58 ] . V_60 ,
V_59 [ V_58 ] . V_3 ) ;
else
V_19 = F_32 ( V_59 [ V_58 ] . V_60 ) ;
if ( V_19 )
goto V_61;
}
F_33 ( & V_54 . V_43 ) ;
F_33 ( & V_55 . V_43 ) ;
F_34 ( & V_38 , F_23 ) ;
V_19 = F_35 ( & V_8 -> V_8 , & V_54 . V_7 ) ;
if ( V_19 )
goto V_63;
V_19 = F_35 ( & V_8 -> V_8 , & V_55 . V_7 ) ;
if ( V_19 )
goto V_64;
V_19 = F_35 ( & V_8 -> V_8 , & V_65 . V_7 ) ;
if ( V_19 )
goto V_66;
V_19 = F_36 ( F_37 ( V_67 ) ,
F_15 ,
V_68 | V_69 ,
L_3 , & V_54 ) ;
if ( V_19 )
goto V_70;
V_19 = F_36 ( F_37 ( V_71 ) ,
F_15 ,
V_68 | V_69 ,
L_4 , & V_55 ) ;
if ( V_19 )
goto V_72;
V_19 = F_36 ( F_37 ( V_37 ) ,
F_15 ,
V_68 | V_69 ,
L_5 , & V_55 ) ;
if ( ! V_19 ) {
F_14 ( & V_38 ) ;
return 0 ;
}
F_38 ( F_37 ( V_71 ) , & V_55 ) ;
V_72:
F_38 ( F_37 ( V_67 ) , & V_54 ) ;
V_70:
F_39 ( & V_65 . V_7 ) ;
V_66:
F_39 ( & V_55 . V_7 ) ;
V_64:
F_39 ( & V_54 . V_7 ) ;
V_63:
F_40 ( & V_38 ) ;
V_58 -- ;
V_61:
for (; V_58 >= 0 ; V_58 -- )
F_41 ( V_59 [ V_58 ] . V_60 ) ;
return V_19 ;
}
static int T_4 F_42 ( struct V_56 * V_8 )
{
int V_58 ;
F_38 ( F_37 ( V_37 ) , & V_55 ) ;
F_38 ( F_37 ( V_71 ) , & V_55 ) ;
F_38 ( F_37 ( V_67 ) , & V_54 ) ;
F_39 ( & V_65 . V_7 ) ;
F_39 ( & V_55 . V_7 ) ;
F_39 ( & V_54 . V_7 ) ;
F_40 ( & V_38 ) ;
for ( V_58 = F_29 ( V_59 ) - 1 ; V_58 >= 0 ; V_58 -- )
F_41 ( V_59 [ V_58 ] . V_60 ) ;
return 0 ;
}
static int T_5 F_43 ( void )
{
return F_44 ( & V_73 ) ;
}
static void T_6 F_45 ( void )
{
F_46 ( & V_73 ) ;
}
