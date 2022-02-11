struct V_1 * F_1 ( struct V_2 * V_2 , struct V_3 * V_4 ,
int V_5 , T_1 V_6 )
{
struct V_7 V_8 = {
. V_9 = V_6 ,
. V_5 = V_10 ,
} ;
F_2 ( V_2 -> V_11 . V_12 ,
F_3 ( V_4 ) , V_5 , & V_8 ) ;
if ( V_8 . V_13 )
return V_8 . V_13 ;
F_4 ( & V_2 -> V_11 . V_14 -> V_15 ) ;
return & V_2 -> V_11 . V_14 -> V_15 ;
}
static int F_5 ( struct V_16 * V_17 , struct V_18 * V_19 ,
int V_5 , struct V_7 * V_8 )
{
struct V_3 * V_20 = & V_19 -> V_21 . V_22 ;
struct V_23 * V_24 = NULL ;
struct V_25 * V_26 ;
struct V_2 * V_2 = V_17 -> V_27 ;
T_1 V_6 = V_8 -> V_9 ;
int V_28 = 0 ;
switch ( V_17 -> V_29 ) {
case V_30 :
break;
case V_31 :
V_28 = - V_32 ;
V_24 = V_2 -> V_11 . V_14 ;
goto V_33;
default:
case V_34 :
V_28 = - V_35 ;
V_24 = V_2 -> V_11 . V_36 ;
goto V_33;
case V_37 :
V_28 = - V_38 ;
V_24 = V_2 -> V_11 . V_39 ;
goto V_33;
}
V_26 = F_6 ( V_2 , V_17 -> V_26 ) ;
if ( ! V_26 ) {
V_28 = - V_40 ;
goto V_41;
}
V_24 = V_6 ( V_2 , V_26 , V_20 , V_5 ) ;
if ( V_24 != V_2 -> V_11 . V_14 ) {
struct V_42 * V_43 = (struct V_42 * ) V_17 ;
if ( ( V_17 -> V_5 & V_44 ) &&
V_43 -> V_45 . V_46 && ! ( V_5 & V_47 ) ) {
struct V_48 V_49 ;
if ( F_7 ( V_2 ,
F_8 ( & V_24 -> V_15 ) -> V_50 ,
& V_20 -> V_51 ,
F_9 ( V_5 ) ,
& V_49 ) )
goto V_52;
if ( ! F_10 ( & V_49 , & V_43 -> V_45 . V_53 ,
V_43 -> V_45 . V_46 ) )
goto V_52;
V_20 -> V_49 = V_49 ;
}
V_28 = V_24 -> V_15 . error ;
goto V_41;
}
V_52:
F_11 ( V_24 ) ;
V_28 = - V_40 ;
V_24 = NULL ;
goto V_41;
V_33:
F_4 ( & V_24 -> V_15 ) ;
V_41:
V_8 -> V_13 = V_24 ;
return V_28 ;
}
static bool F_12 ( struct V_16 * V_17 , struct V_7 * V_8 )
{
struct V_23 * V_24 = (struct V_23 * ) V_8 -> V_13 ;
struct V_54 * V_50 = NULL ;
if ( V_24 -> V_55 )
V_50 = V_24 -> V_55 -> V_50 ;
if ( V_24 -> V_56 . V_46 <= V_17 -> V_57 )
goto V_58;
if ( V_17 -> V_59 != - 1 && V_50 && V_50 -> V_60 == V_17 -> V_59 )
goto V_58;
return false ;
V_58:
F_11 ( V_24 ) ;
return true ;
}
static int F_13 ( struct V_16 * V_17 , struct V_18 * V_61 , int V_5 )
{
struct V_42 * V_43 = (struct V_42 * ) V_17 ;
struct V_3 * V_4 = & V_61 -> V_21 . V_22 ;
if ( V_43 -> V_15 . V_46 &&
! F_10 ( & V_4 -> V_51 , & V_43 -> V_15 . V_53 , V_43 -> V_15 . V_46 ) )
return 0 ;
if ( V_43 -> V_45 . V_46 ) {
if ( V_5 & V_47 ) {
if ( ! F_10 ( & V_4 -> V_49 , & V_43 -> V_45 . V_53 ,
V_43 -> V_45 . V_46 ) )
return 0 ;
} else if ( ! ( V_43 -> V_62 . V_5 & V_44 ) )
return 0 ;
}
if ( V_43 -> V_63 && V_43 -> V_63 != F_14 ( V_4 -> V_64 ) )
return 0 ;
return 1 ;
}
static int F_15 ( struct V_16 * V_17 , struct V_65 * V_66 ,
struct V_67 * V_68 ,
struct V_69 * * V_70 )
{
int V_28 = - V_35 ;
struct V_2 * V_2 = F_16 ( V_66 -> V_71 ) ;
struct V_42 * V_72 = (struct V_42 * ) V_17 ;
if ( V_17 -> V_29 == V_30 ) {
if ( V_17 -> V_26 == V_73 )
goto V_74;
if ( F_17 ( V_2 , V_17 -> V_26 ) == NULL ) {
V_28 = - V_75 ;
goto V_74;
}
}
if ( V_68 -> V_76 )
F_18 ( & V_72 -> V_45 . V_53 , V_70 [ V_77 ] ,
sizeof( struct V_48 ) ) ;
if ( V_68 -> V_78 )
F_18 ( & V_72 -> V_15 . V_53 , V_70 [ V_79 ] ,
sizeof( struct V_48 ) ) ;
V_72 -> V_45 . V_46 = V_68 -> V_76 ;
V_72 -> V_15 . V_46 = V_68 -> V_78 ;
V_72 -> V_63 = V_68 -> V_80 ;
V_28 = 0 ;
V_74:
return V_28 ;
}
static int F_19 ( struct V_16 * V_17 , struct V_67 * V_68 ,
struct V_69 * * V_70 )
{
struct V_42 * V_72 = (struct V_42 * ) V_17 ;
if ( V_68 -> V_76 && ( V_72 -> V_45 . V_46 != V_68 -> V_76 ) )
return 0 ;
if ( V_68 -> V_78 && ( V_72 -> V_15 . V_46 != V_68 -> V_78 ) )
return 0 ;
if ( V_68 -> V_80 && ( V_72 -> V_63 != V_68 -> V_80 ) )
return 0 ;
if ( V_68 -> V_76 &&
F_20 ( V_70 [ V_77 ] , & V_72 -> V_45 . V_53 , sizeof( struct V_48 ) ) )
return 0 ;
if ( V_68 -> V_78 &&
F_20 ( V_70 [ V_79 ] , & V_72 -> V_15 . V_53 , sizeof( struct V_48 ) ) )
return 0 ;
return 1 ;
}
static int F_21 ( struct V_16 * V_17 , struct V_65 * V_66 ,
struct V_67 * V_68 )
{
struct V_42 * V_72 = (struct V_42 * ) V_17 ;
V_68 -> V_78 = V_72 -> V_15 . V_46 ;
V_68 -> V_76 = V_72 -> V_45 . V_46 ;
V_68 -> V_80 = V_72 -> V_63 ;
if ( ( V_72 -> V_15 . V_46 &&
F_22 ( V_66 , V_79 , sizeof( struct V_48 ) ,
& V_72 -> V_15 . V_53 ) ) ||
( V_72 -> V_45 . V_46 &&
F_22 ( V_66 , V_77 , sizeof( struct V_48 ) ,
& V_72 -> V_45 . V_53 ) ) )
goto V_81;
return 0 ;
V_81:
return - V_75 ;
}
static T_2 F_23 ( struct V_82 * V_83 )
{
return 0x3FFF ;
}
static T_3 F_24 ( struct V_16 * V_17 )
{
return F_25 ( 16 )
+ F_25 ( 16 ) ;
}
static int T_4 F_26 ( struct V_2 * V_2 )
{
struct V_82 * V_83 ;
int V_28 = - V_84 ;
V_83 = F_27 ( & V_85 , V_2 ) ;
if ( F_28 ( V_83 ) )
return F_29 ( V_83 ) ;
V_2 -> V_11 . V_12 = V_83 ;
V_28 = F_30 ( V_2 -> V_11 . V_12 , 0 ,
V_86 , 0 ) ;
if ( V_28 )
goto V_87;
V_28 = F_30 ( V_2 -> V_11 . V_12 ,
0x7FFE , V_88 , 0 ) ;
if ( V_28 )
goto V_87;
V_41:
return V_28 ;
V_87:
F_31 ( V_83 ) ;
goto V_41;
}
static void T_5 F_32 ( struct V_2 * V_2 )
{
F_33 () ;
F_31 ( V_2 -> V_11 . V_12 ) ;
F_34 () ;
}
int T_6 F_35 ( void )
{
return F_36 ( & V_89 ) ;
}
void F_37 ( void )
{
F_38 ( & V_89 ) ;
}
