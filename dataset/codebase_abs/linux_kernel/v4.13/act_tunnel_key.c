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
T_1 V_40 ;
int V_41 = 0 ;
int V_42 ;
if ( ! V_22 )
return - V_43 ;
V_42 = F_15 ( V_29 , V_30 , V_22 , V_44 ,
NULL ) ;
if ( V_42 < 0 )
return V_42 ;
if ( ! V_29 [ V_45 ] )
return - V_43 ;
V_36 = F_16 ( V_29 [ V_45 ] ) ;
V_37 = F_17 ( V_27 , V_36 -> V_46 , V_4 , V_25 ) ;
if ( V_37 && V_25 )
return 0 ;
switch ( V_36 -> V_47 ) {
case V_16 :
break;
case V_17 :
if ( ! V_29 [ V_48 ] ) {
V_41 = - V_43 ;
goto V_49;
}
V_39 = F_18 ( F_19 ( V_29 [ V_48 ] ) ) ;
V_40 = V_50 | V_51 ;
if ( V_29 [ V_52 ] &&
F_20 ( V_29 [ V_52 ] ) )
V_40 &= ~ V_51 ;
if ( V_29 [ V_53 ] )
V_38 = F_21 ( V_29 [ V_53 ] ) ;
if ( V_29 [ V_54 ] &&
V_29 [ V_55 ] ) {
T_3 V_56 ;
T_3 V_57 ;
V_56 = F_22 ( V_29 [ V_54 ] ) ;
V_57 = F_22 ( V_29 [ V_55 ] ) ;
V_34 = F_23 ( V_56 , V_57 , 0 , 0 ,
V_38 , V_40 ,
V_39 , 0 ) ;
} else if ( V_29 [ V_58 ] &&
V_29 [ V_59 ] ) {
struct V_60 V_56 ;
struct V_60 V_57 ;
V_56 = F_24 ( V_29 [ V_58 ] ) ;
V_57 = F_24 ( V_29 [ V_59 ] ) ;
V_34 = F_25 ( & V_56 , & V_57 , 0 , 0 , V_38 ,
0 , V_40 ,
V_39 , 0 ) ;
}
if ( ! V_34 ) {
V_41 = - V_43 ;
goto V_49;
}
V_34 -> V_61 . V_62 . V_63 |= V_64 ;
break;
default:
goto V_49;
}
if ( ! V_37 ) {
V_41 = F_26 ( V_27 , V_36 -> V_46 , V_23 , V_4 ,
& V_65 , V_25 , true ) ;
if ( V_41 )
return V_41 ;
V_41 = V_66 ;
} else {
F_27 ( * V_4 , V_25 ) ;
if ( ! V_24 )
return - V_67 ;
}
V_8 = F_2 ( * V_4 ) ;
F_28 () ;
V_32 = F_29 ( sizeof( * V_32 ) , V_68 ) ;
if ( F_30 ( ! V_32 ) ) {
if ( V_41 == V_66 )
F_27 ( * V_4 , V_25 ) ;
return - V_69 ;
}
V_31 = F_31 ( V_8 -> V_10 ) ;
V_32 -> V_11 = V_36 -> V_11 ;
V_32 -> V_15 = V_36 -> V_47 ;
V_32 -> V_18 = V_34 ;
F_32 ( V_8 -> V_10 , V_32 ) ;
if ( V_31 )
F_33 ( V_31 , V_70 ) ;
if ( V_41 == V_66 )
F_34 ( V_27 , * V_4 ) ;
return V_41 ;
V_49:
if ( V_37 )
F_27 ( * V_4 , V_25 ) ;
return V_41 ;
}
static void F_35 ( struct V_3 * V_4 , int V_25 )
{
struct V_7 * V_8 = F_2 ( V_4 ) ;
struct V_9 * V_10 ;
V_10 = F_36 ( V_8 -> V_10 , 1 ) ;
if ( V_10 -> V_15 == V_17 )
F_37 ( & V_10 -> V_18 -> V_19 ) ;
F_33 ( V_10 , V_70 ) ;
}
static int F_38 ( struct V_1 * V_2 ,
const struct V_71 * V_72 )
{
unsigned short V_73 = F_39 ( V_72 ) ;
if ( V_73 == V_74 ) {
T_3 V_56 = V_72 -> V_75 . V_61 . V_76 . V_77 ;
T_3 V_57 = V_72 -> V_75 . V_61 . V_76 . V_19 ;
if ( ! F_40 ( V_2 , V_54 , V_56 ) &&
! F_40 ( V_2 , V_55 , V_57 ) )
return 0 ;
}
if ( V_73 == V_78 ) {
const struct V_60 * V_79 = & V_72 -> V_75 . V_61 . V_80 . V_77 ;
const struct V_60 * V_81 = & V_72 -> V_75 . V_61 . V_80 . V_19 ;
if ( ! F_41 ( V_2 ,
V_58 , V_79 ) &&
! F_41 ( V_2 ,
V_59 , V_81 ) )
return 0 ;
}
return - V_43 ;
}
static int F_42 ( struct V_1 * V_2 , struct V_3 * V_4 ,
int V_25 , int V_82 )
{
unsigned char * V_83 = F_43 ( V_2 ) ;
struct V_7 * V_8 = F_2 ( V_4 ) ;
struct V_9 * V_10 ;
struct V_35 V_84 = {
. V_46 = V_8 -> V_85 ,
. V_86 = V_8 -> V_87 - V_82 ,
. V_88 = V_8 -> V_89 - V_25 ,
} ;
struct V_90 V_91 ;
V_10 = F_31 ( V_8 -> V_10 ) ;
V_84 . V_47 = V_10 -> V_15 ;
V_84 . V_11 = V_10 -> V_11 ;
if ( F_44 ( V_2 , V_45 , sizeof( V_84 ) , & V_84 ) )
goto V_92;
if ( V_10 -> V_15 == V_17 ) {
struct V_93 * V_75 =
& V_10 -> V_18 -> V_61 . V_62 . V_75 ;
T_3 V_39 = F_45 ( V_75 -> V_94 ) ;
if ( F_46 ( V_2 , V_48 , V_39 ) ||
F_38 ( V_2 ,
& V_10 -> V_18 -> V_61 . V_62 ) ||
F_47 ( V_2 , V_53 , V_75 -> V_95 ) ||
F_48 ( V_2 , V_52 ,
! ( V_75 -> V_96 & V_51 ) ) )
goto V_92;
}
F_49 ( & V_91 , & V_8 -> V_12 ) ;
if ( F_50 ( V_2 , V_97 , sizeof( V_91 ) ,
& V_91 , V_98 ) )
goto V_92;
return V_2 -> V_99 ;
V_92:
F_51 ( V_2 , V_83 ) ;
return - 1 ;
}
static int F_52 ( struct V_20 * V_20 , struct V_1 * V_2 ,
struct V_100 * V_101 , int type ,
const struct V_102 * V_103 )
{
struct V_26 * V_27 = F_14 ( V_20 , V_28 ) ;
return F_53 ( V_27 , V_2 , V_101 , type , V_103 ) ;
}
static int F_54 ( struct V_20 * V_20 , struct V_3 * * V_4 , T_4 V_46 )
{
struct V_26 * V_27 = F_14 ( V_20 , V_28 ) ;
return F_55 ( V_27 , V_4 , V_46 ) ;
}
static T_5 int F_56 ( struct V_20 * V_20 )
{
struct V_26 * V_27 = F_14 ( V_20 , V_28 ) ;
return F_57 ( V_27 , & V_65 , V_104 ) ;
}
static void T_6 F_58 ( struct V_20 * V_20 )
{
struct V_26 * V_27 = F_14 ( V_20 , V_28 ) ;
F_59 ( V_27 ) ;
}
static int T_7 F_60 ( void )
{
return F_61 ( & V_65 , & V_105 ) ;
}
static void T_8 F_62 ( void )
{
F_63 ( & V_65 , & V_105 ) ;
}
