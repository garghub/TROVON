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
T_1 V_38 = 0 ;
T_2 V_39 ;
int V_40 = 0 ;
int V_41 ;
if ( ! V_22 )
return - V_42 ;
V_41 = F_15 ( V_29 , V_30 , V_22 , V_43 ,
NULL ) ;
if ( V_41 < 0 )
return V_41 ;
if ( ! V_29 [ V_44 ] )
return - V_42 ;
V_36 = F_16 ( V_29 [ V_44 ] ) ;
V_37 = F_17 ( V_27 , V_36 -> V_45 , V_4 , V_25 ) ;
if ( V_37 && V_25 )
return 0 ;
switch ( V_36 -> V_46 ) {
case V_16 :
break;
case V_17 :
if ( ! V_29 [ V_47 ] ) {
V_40 = - V_42 ;
goto V_48;
}
V_39 = F_18 ( F_19 ( V_29 [ V_47 ] ) ) ;
if ( V_29 [ V_49 ] )
V_38 = F_20 ( V_29 [ V_49 ] ) ;
if ( V_29 [ V_50 ] &&
V_29 [ V_51 ] ) {
T_3 V_52 ;
T_3 V_53 ;
V_52 = F_21 ( V_29 [ V_50 ] ) ;
V_53 = F_21 ( V_29 [ V_51 ] ) ;
V_34 = F_22 ( V_52 , V_53 , 0 , 0 ,
V_38 , V_54 ,
V_39 , 0 ) ;
} else if ( V_29 [ V_55 ] &&
V_29 [ V_56 ] ) {
struct V_57 V_52 ;
struct V_57 V_53 ;
V_52 = F_23 ( V_29 [ V_55 ] ) ;
V_53 = F_23 ( V_29 [ V_56 ] ) ;
V_34 = F_24 ( & V_52 , & V_53 , 0 , 0 , V_38 ,
0 , V_54 ,
V_39 , 0 ) ;
}
if ( ! V_34 ) {
V_40 = - V_42 ;
goto V_48;
}
V_34 -> V_58 . V_59 . V_60 |= V_61 ;
break;
default:
goto V_48;
}
if ( ! V_37 ) {
V_40 = F_25 ( V_27 , V_36 -> V_45 , V_23 , V_4 ,
& V_62 , V_25 , true ) ;
if ( V_40 )
return V_40 ;
V_40 = V_63 ;
} else {
F_26 ( * V_4 , V_25 ) ;
if ( ! V_24 )
return - V_64 ;
}
V_8 = F_2 ( * V_4 ) ;
F_27 () ;
V_32 = F_28 ( sizeof( * V_32 ) , V_65 ) ;
if ( F_29 ( ! V_32 ) ) {
if ( V_40 == V_63 )
F_26 ( * V_4 , V_25 ) ;
return - V_66 ;
}
V_31 = F_30 ( V_8 -> V_10 ) ;
V_32 -> V_11 = V_36 -> V_11 ;
V_32 -> V_15 = V_36 -> V_46 ;
V_32 -> V_18 = V_34 ;
F_31 ( V_8 -> V_10 , V_32 ) ;
if ( V_31 )
F_32 ( V_31 , V_67 ) ;
if ( V_40 == V_63 )
F_33 ( V_27 , * V_4 ) ;
return V_40 ;
V_48:
if ( V_37 )
F_26 ( * V_4 , V_25 ) ;
return V_40 ;
}
static void F_34 ( struct V_3 * V_4 , int V_25 )
{
struct V_7 * V_8 = F_2 ( V_4 ) ;
struct V_9 * V_10 ;
V_10 = F_35 ( V_8 -> V_10 , 1 ) ;
if ( V_10 -> V_15 == V_17 )
F_36 ( & V_10 -> V_18 -> V_19 ) ;
F_32 ( V_10 , V_67 ) ;
}
static int F_37 ( struct V_1 * V_2 ,
const struct V_68 * V_69 )
{
unsigned short V_70 = F_38 ( V_69 ) ;
if ( V_70 == V_71 ) {
T_3 V_52 = V_69 -> V_72 . V_58 . V_73 . V_74 ;
T_3 V_53 = V_69 -> V_72 . V_58 . V_73 . V_19 ;
if ( ! F_39 ( V_2 , V_50 , V_52 ) &&
! F_39 ( V_2 , V_51 , V_53 ) )
return 0 ;
}
if ( V_70 == V_75 ) {
const struct V_57 * V_76 = & V_69 -> V_72 . V_58 . V_77 . V_74 ;
const struct V_57 * V_78 = & V_69 -> V_72 . V_58 . V_77 . V_19 ;
if ( ! F_40 ( V_2 ,
V_55 , V_76 ) &&
! F_40 ( V_2 ,
V_56 , V_78 ) )
return 0 ;
}
return - V_42 ;
}
static int F_41 ( struct V_1 * V_2 , struct V_3 * V_4 ,
int V_25 , int V_79 )
{
unsigned char * V_80 = F_42 ( V_2 ) ;
struct V_7 * V_8 = F_2 ( V_4 ) ;
struct V_9 * V_10 ;
struct V_35 V_81 = {
. V_45 = V_8 -> V_82 ,
. V_83 = V_8 -> V_84 - V_79 ,
. V_85 = V_8 -> V_86 - V_25 ,
} ;
struct V_87 V_88 ;
V_10 = F_30 ( V_8 -> V_10 ) ;
V_81 . V_46 = V_10 -> V_15 ;
V_81 . V_11 = V_10 -> V_11 ;
if ( F_43 ( V_2 , V_44 , sizeof( V_81 ) , & V_81 ) )
goto V_89;
if ( V_10 -> V_15 == V_17 ) {
struct V_90 * V_72 =
& V_10 -> V_18 -> V_58 . V_59 . V_72 ;
T_3 V_39 = F_44 ( V_72 -> V_91 ) ;
if ( F_45 ( V_2 , V_47 , V_39 ) ||
F_37 ( V_2 ,
& V_10 -> V_18 -> V_58 . V_59 ) ||
F_46 ( V_2 , V_49 , V_72 -> V_92 ) )
goto V_89;
}
F_47 ( & V_88 , & V_8 -> V_12 ) ;
if ( F_48 ( V_2 , V_93 , sizeof( V_88 ) ,
& V_88 , V_94 ) )
goto V_89;
return V_2 -> V_95 ;
V_89:
F_49 ( V_2 , V_80 ) ;
return - 1 ;
}
static int F_50 ( struct V_20 * V_20 , struct V_1 * V_2 ,
struct V_96 * V_97 , int type ,
const struct V_98 * V_99 )
{
struct V_26 * V_27 = F_14 ( V_20 , V_28 ) ;
return F_51 ( V_27 , V_2 , V_97 , type , V_99 ) ;
}
static int F_52 ( struct V_20 * V_20 , struct V_3 * * V_4 , T_4 V_45 )
{
struct V_26 * V_27 = F_14 ( V_20 , V_28 ) ;
return F_53 ( V_27 , V_4 , V_45 ) ;
}
static T_5 int F_54 ( struct V_20 * V_20 )
{
struct V_26 * V_27 = F_14 ( V_20 , V_28 ) ;
return F_55 ( V_27 , & V_62 , V_100 ) ;
}
static void T_6 F_56 ( struct V_20 * V_20 )
{
struct V_26 * V_27 = F_14 ( V_20 , V_28 ) ;
F_57 ( V_27 ) ;
}
static int T_7 F_58 ( void )
{
return F_59 ( & V_62 , & V_101 ) ;
}
static void T_8 F_60 ( void )
{
F_61 ( & V_62 , & V_101 ) ;
}
