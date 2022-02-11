static int F_1 ( int V_1 )
{
int V_2 ;
switch ( V_1 ) {
case 16 :
V_2 = V_3 ;
break;
case 32 :
V_2 = V_4 ;
break;
default:
V_2 = - V_5 ;
break;
}
return V_2 ;
}
static int F_2 ( struct V_6 * V_7 ,
struct V_8 * V_9 )
{
struct V_10 * V_11 = V_7 -> V_11 ;
struct V_12 * V_13 = V_7 -> V_14 ;
struct V_15 * V_16 ;
struct V_17 V_18 ;
struct V_19 * V_20 ;
int V_21 = 0 ;
V_16 = F_3 ( V_13 -> V_22 , V_7 ) ;
if ( ! V_16 )
return 0 ;
F_4 ( V_7 , & V_7 -> V_23 ) ;
V_11 -> V_24 = F_5 ( V_9 ) ;
V_20 = F_6 ( V_7 ) ;
if ( ! V_20 )
return - V_5 ;
V_21 = F_7 ( V_7 , V_9 , & V_18 ) ;
if ( V_21 )
return V_21 ;
if ( V_16 -> V_25 ) {
int V_2 = F_1 ( V_16 -> V_25 ) ;
if ( V_7 -> V_26 == V_27 )
V_18 . V_28 = V_2 ;
else
V_18 . V_29 = V_2 ;
}
V_18 . V_30 = V_16 -> V_31 ;
V_18 . V_32 = V_16 -> V_31 ;
V_18 . V_33 = V_16 -> V_34 ;
V_18 . V_35 = V_16 -> V_34 ;
return F_8 ( V_20 , & V_18 ) ;
}
static int F_9 ( struct V_6 * V_7 )
{
F_4 ( V_7 , NULL ) ;
return 0 ;
}
static int F_10 ( struct V_6 * V_7 , int V_36 )
{
struct V_12 * V_13 = V_7 -> V_14 ;
struct V_15 * V_16 ;
int V_37 = 0 ;
V_16 = F_3 ( V_13 -> V_22 , V_7 ) ;
switch ( V_36 ) {
case V_38 :
case V_39 :
case V_40 :
if ( V_16 -> V_41 )
V_16 -> V_41 ( V_7 ) ;
break;
case V_42 :
case V_43 :
case V_44 :
break;
default:
V_37 = - V_5 ;
}
if ( V_37 == 0 )
V_37 = F_11 ( V_7 , V_36 ) ;
return V_37 ;
}
static T_1 F_12 ( struct V_6 * V_7 )
{
T_1 V_45 ;
if ( F_13 () )
V_45 = F_14 ( V_7 ) ;
else
V_45 = F_15 ( V_7 ) ;
return V_45 ;
}
static int F_16 ( struct V_6 * V_7 )
{
struct V_12 * V_13 = V_7 -> V_14 ;
struct V_15 * V_16 ;
F_17 ( V_7 , & V_46 ) ;
V_16 = F_3 ( V_13 -> V_22 , V_7 ) ;
return F_18 ( V_7 , V_47 ,
& V_16 -> V_48 ) ;
}
static int F_19 ( struct V_6 * V_7 )
{
F_20 ( V_7 ) ;
return 0 ;
}
static int F_21 ( struct V_6 * V_7 ,
struct V_49 * V_50 )
{
struct V_10 * V_11 = V_7 -> V_11 ;
return F_22 ( V_7 -> V_51 -> V_52 -> V_53 , V_50 ,
V_11 -> V_54 ,
V_11 -> V_55 ,
V_11 -> V_24 ) ;
}
static int F_23 ( struct V_56 * V_51 ,
int V_26 )
{
struct V_6 * V_7 = V_51 -> V_57 [ V_26 ] . V_7 ;
struct V_58 * V_59 = & V_7 -> V_23 ;
T_2 V_60 = V_46 . V_61 ;
V_59 -> V_53 . type = V_62 ;
V_59 -> V_53 . V_53 = V_51 -> V_52 -> V_53 ;
V_59 -> V_14 = NULL ;
V_59 -> V_63 = F_24 ( V_51 -> V_52 -> V_53 , V_60 ,
& V_59 -> V_64 , V_65 ) ;
if ( ! V_59 -> V_63 )
return - V_66 ;
V_59 -> V_67 = V_60 ;
return 0 ;
}
static void F_25 ( struct V_56 * V_51 )
{
struct V_6 * V_7 ;
struct V_58 * V_59 ;
int V_26 ;
for ( V_26 = 0 ; V_26 < 2 ; V_26 ++ ) {
V_7 = V_51 -> V_57 [ V_26 ] . V_7 ;
if ( ! V_7 )
continue;
V_59 = & V_7 -> V_23 ;
if ( ! V_59 -> V_63 )
continue;
F_26 ( V_51 -> V_52 -> V_53 , V_59 -> V_67 ,
V_59 -> V_63 , V_59 -> V_64 ) ;
V_59 -> V_63 = NULL ;
}
}
static int F_27 ( struct V_12 * V_13 )
{
struct V_68 * V_52 = V_13 -> V_52 -> V_68 ;
struct V_56 * V_51 = V_13 -> V_51 ;
int V_37 = 0 ;
if ( ! V_52 -> V_53 -> V_69 )
V_52 -> V_53 -> V_69 = & V_70 ;
if ( ! V_52 -> V_53 -> V_71 )
V_52 -> V_53 -> V_71 = F_28 ( 64 ) ;
if ( V_51 -> V_57 [ V_27 ] . V_7 ) {
V_37 = F_23 ( V_51 ,
V_27 ) ;
if ( V_37 )
goto V_72;
}
if ( V_51 -> V_57 [ V_73 ] . V_7 ) {
V_37 = F_23 ( V_51 ,
V_73 ) ;
if ( V_37 )
goto V_72;
}
V_72:
if ( V_37 )
F_25 ( V_51 ) ;
return V_37 ;
}
static int F_29 ( struct V_74 * V_75 )
{
return F_30 ( & V_75 -> V_53 ,
& V_76 ) ;
}
static int F_31 ( struct V_74 * V_75 )
{
F_32 ( & V_75 -> V_53 ) ;
return 0 ;
}
