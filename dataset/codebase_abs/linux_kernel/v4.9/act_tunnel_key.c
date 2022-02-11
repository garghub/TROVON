static int F_1 ( struct V_1 * V_2 , const struct V_3 * V_4 ,
struct V_5 * V_6 )
{
struct V_7 * V_8 = F_2 ( V_4 ) ;
struct V_9 * V_10 ;
int V_11 ;
F_3 () ;
V_10 = F_4 ( V_8 -> V_10 ) ;
F_5 ( & V_8 -> V_12 ) ;
F_6 ( F_7 ( V_8 -> V_13 . V_14 ) , V_2 ) ;
V_11 = V_10 -> V_11 ;
switch ( V_10 -> V_15 ) {
case V_16 :
F_8 ( V_2 ) ;
break;
case V_17 :
F_8 ( V_2 ) ;
F_9 ( V_2 , F_10 ( & V_10 -> V_18 -> V_19 ) ) ;
break;
default:
F_11 ( 1 , L_1 ,
V_10 -> V_15 ) ;
break;
}
F_12 () ;
return V_11 ;
}
static int F_13 ( struct V_20 * V_20 , struct V_21 * V_22 ,
struct V_21 * V_23 , struct V_3 * * V_4 ,
int V_24 , int V_25 )
{
struct V_26 * V_27 = F_14 ( V_20 , V_28 ) ;
struct V_21 * V_29 [ V_30 + 1 ] ;
struct V_9 * V_31 ;
struct V_9 * V_32 ;
struct V_33 * V_34 = NULL ;
struct V_35 * V_36 ;
struct V_7 * V_8 ;
bool V_37 = false ;
T_1 V_38 ;
int V_39 = 0 ;
int V_40 ;
if ( ! V_22 )
return - V_41 ;
V_40 = F_15 ( V_29 , V_30 , V_22 , V_42 ) ;
if ( V_40 < 0 )
return V_40 ;
if ( ! V_29 [ V_43 ] )
return - V_41 ;
V_36 = F_16 ( V_29 [ V_43 ] ) ;
V_37 = F_17 ( V_27 , V_36 -> V_44 , V_4 , V_25 ) ;
if ( V_37 && V_25 )
return 0 ;
switch ( V_36 -> V_45 ) {
case V_16 :
break;
case V_17 :
if ( ! V_29 [ V_46 ] ) {
V_39 = - V_41 ;
goto V_47;
}
V_38 = F_18 ( F_19 ( V_29 [ V_46 ] ) ) ;
if ( V_29 [ V_48 ] &&
V_29 [ V_49 ] ) {
T_2 V_50 ;
T_2 V_51 ;
V_50 = F_20 ( V_29 [ V_48 ] ) ;
V_51 = F_20 ( V_29 [ V_49 ] ) ;
V_34 = F_21 ( V_50 , V_51 , 0 , 0 ,
V_52 , V_38 , 0 ) ;
} else if ( V_29 [ V_53 ] &&
V_29 [ V_54 ] ) {
struct V_55 V_50 ;
struct V_55 V_51 ;
V_50 = F_22 ( V_29 [ V_53 ] ) ;
V_51 = F_22 ( V_29 [ V_54 ] ) ;
V_34 = F_23 ( & V_50 , & V_51 , 0 , 0 , 0 ,
V_52 , V_38 , 0 ) ;
}
if ( ! V_34 ) {
V_39 = - V_41 ;
goto V_47;
}
V_34 -> V_56 . V_57 . V_58 |= V_59 ;
break;
default:
goto V_47;
}
if ( ! V_37 ) {
V_39 = F_24 ( V_27 , V_36 -> V_44 , V_23 , V_4 ,
& V_60 , V_25 , true ) ;
if ( V_39 )
return V_39 ;
V_39 = V_61 ;
} else {
F_25 ( * V_4 , V_25 ) ;
if ( ! V_24 )
return - V_62 ;
}
V_8 = F_2 ( * V_4 ) ;
F_26 () ;
V_32 = F_27 ( sizeof( * V_32 ) , V_63 ) ;
if ( F_28 ( ! V_32 ) ) {
if ( V_39 == V_61 )
F_25 ( * V_4 , V_25 ) ;
return - V_64 ;
}
V_31 = F_29 ( V_8 -> V_10 ) ;
V_32 -> V_11 = V_36 -> V_11 ;
V_32 -> V_15 = V_36 -> V_45 ;
V_32 -> V_18 = V_34 ;
F_30 ( V_8 -> V_10 , V_32 ) ;
if ( V_31 )
F_31 ( V_31 , V_65 ) ;
if ( V_39 == V_61 )
F_32 ( V_27 , * V_4 ) ;
return V_39 ;
V_47:
if ( V_37 )
F_25 ( * V_4 , V_25 ) ;
return V_39 ;
}
static void F_33 ( struct V_3 * V_4 , int V_25 )
{
struct V_7 * V_8 = F_2 ( V_4 ) ;
struct V_9 * V_10 ;
V_10 = F_34 ( V_8 -> V_10 , 1 ) ;
if ( V_10 -> V_15 == V_17 )
F_35 ( & V_10 -> V_18 -> V_19 ) ;
F_31 ( V_10 , V_65 ) ;
}
static int F_36 ( struct V_1 * V_2 ,
const struct V_66 * V_67 )
{
unsigned short V_68 = F_37 ( V_67 ) ;
if ( V_68 == V_69 ) {
T_2 V_50 = V_67 -> V_70 . V_56 . V_71 . V_72 ;
T_2 V_51 = V_67 -> V_70 . V_56 . V_71 . V_19 ;
if ( ! F_38 ( V_2 , V_48 , V_50 ) &&
! F_38 ( V_2 , V_49 , V_51 ) )
return 0 ;
}
if ( V_68 == V_73 ) {
const struct V_55 * V_74 = & V_67 -> V_70 . V_56 . V_75 . V_72 ;
const struct V_55 * V_76 = & V_67 -> V_70 . V_56 . V_75 . V_19 ;
if ( ! F_39 ( V_2 ,
V_53 , V_74 ) &&
! F_39 ( V_2 ,
V_54 , V_76 ) )
return 0 ;
}
return - V_41 ;
}
static int F_40 ( struct V_1 * V_2 , struct V_3 * V_4 ,
int V_25 , int V_77 )
{
unsigned char * V_78 = F_41 ( V_2 ) ;
struct V_7 * V_8 = F_2 ( V_4 ) ;
struct V_9 * V_10 ;
struct V_35 V_79 = {
. V_44 = V_8 -> V_80 ,
. V_81 = V_8 -> V_82 - V_77 ,
. V_83 = V_8 -> V_84 - V_25 ,
} ;
struct V_85 V_86 ;
V_10 = F_29 ( V_8 -> V_10 ) ;
V_79 . V_45 = V_10 -> V_15 ;
V_79 . V_11 = V_10 -> V_11 ;
if ( F_42 ( V_2 , V_43 , sizeof( V_79 ) , & V_79 ) )
goto V_87;
if ( V_10 -> V_15 == V_17 ) {
struct V_88 * V_70 =
& V_10 -> V_18 -> V_56 . V_57 . V_70 ;
T_2 V_38 = F_43 ( V_70 -> V_89 ) ;
if ( F_44 ( V_2 , V_46 , V_38 ) ||
F_36 ( V_2 ,
& V_10 -> V_18 -> V_56 . V_57 ) )
goto V_87;
}
F_45 ( & V_86 , & V_8 -> V_12 ) ;
if ( F_46 ( V_2 , V_90 , sizeof( V_86 ) ,
& V_86 , V_91 ) )
goto V_87;
return V_2 -> V_92 ;
V_87:
F_47 ( V_2 , V_78 ) ;
return - 1 ;
}
static int F_48 ( struct V_20 * V_20 , struct V_1 * V_2 ,
struct V_93 * V_94 , int type ,
const struct V_95 * V_96 )
{
struct V_26 * V_27 = F_14 ( V_20 , V_28 ) ;
return F_49 ( V_27 , V_2 , V_94 , type , V_96 ) ;
}
static int F_50 ( struct V_20 * V_20 , struct V_3 * * V_4 , T_3 V_44 )
{
struct V_26 * V_27 = F_14 ( V_20 , V_28 ) ;
return F_51 ( V_27 , V_4 , V_44 ) ;
}
static T_4 int F_52 ( struct V_20 * V_20 )
{
struct V_26 * V_27 = F_14 ( V_20 , V_28 ) ;
return F_53 ( V_27 , & V_60 , V_97 ) ;
}
static void T_5 F_54 ( struct V_20 * V_20 )
{
struct V_26 * V_27 = F_14 ( V_20 , V_28 ) ;
F_55 ( V_27 ) ;
}
static int T_6 F_56 ( void )
{
return F_57 ( & V_60 , & V_98 ) ;
}
static void T_7 F_58 ( void )
{
F_59 ( & V_60 , & V_98 ) ;
}
