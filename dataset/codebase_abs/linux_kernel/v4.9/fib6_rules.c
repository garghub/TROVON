struct V_1 * F_1 ( struct V_2 * V_2 , struct V_3 * V_4 ,
int V_5 , T_1 V_6 )
{
struct V_7 * V_8 ;
struct V_9 V_10 = {
. V_11 = V_6 ,
. V_5 = V_12 ,
} ;
F_2 ( V_2 , F_3 ( V_4 ) ) ;
F_4 ( V_2 -> V_13 . V_14 ,
F_3 ( V_4 ) , V_5 , & V_10 ) ;
V_8 = V_10 . V_15 ;
if ( ! V_8 ) {
F_5 ( & V_2 -> V_13 . V_16 -> V_17 ) ;
return & V_2 -> V_13 . V_16 -> V_17 ;
}
if ( V_8 -> V_18 & V_19 &&
V_8 -> V_17 . error == - V_20 ) {
F_6 ( V_8 ) ;
V_8 = V_2 -> V_13 . V_16 ;
F_5 ( & V_8 -> V_17 ) ;
}
return & V_8 -> V_17 ;
}
static int F_7 ( struct V_21 * V_22 , struct V_23 * V_24 ,
int V_5 , struct V_9 * V_10 )
{
struct V_3 * V_25 = & V_24 -> V_26 . V_27 ;
struct V_7 * V_8 = NULL ;
struct V_28 * V_29 ;
struct V_2 * V_2 = V_22 -> V_30 ;
T_1 V_6 = V_10 -> V_11 ;
int V_31 = 0 ;
T_2 V_32 ;
switch ( V_22 -> V_33 ) {
case V_34 :
break;
case V_35 :
V_31 = - V_36 ;
V_8 = V_2 -> V_13 . V_16 ;
goto V_37;
default:
case V_38 :
V_31 = - V_39 ;
V_8 = V_2 -> V_13 . V_40 ;
goto V_37;
case V_41 :
V_31 = - V_42 ;
V_8 = V_2 -> V_13 . V_43 ;
goto V_37;
}
V_32 = F_8 ( V_22 , V_10 ) ;
V_29 = F_9 ( V_2 , V_32 ) ;
if ( ! V_29 ) {
V_31 = - V_20 ;
goto V_44;
}
V_8 = V_6 ( V_2 , V_29 , V_25 , V_5 ) ;
if ( V_8 != V_2 -> V_13 . V_16 ) {
struct V_45 * V_46 = (struct V_45 * ) V_22 ;
if ( ( V_22 -> V_5 & V_47 ) &&
V_46 -> V_48 . V_49 && ! ( V_5 & V_50 ) ) {
struct V_51 V_52 ;
if ( F_10 ( V_2 ,
F_11 ( & V_8 -> V_17 ) -> V_53 ,
& V_25 -> V_54 ,
F_12 ( V_5 ) ,
& V_52 ) )
goto V_55;
if ( ! F_13 ( & V_52 , & V_46 -> V_48 . V_56 ,
V_46 -> V_48 . V_49 ) )
goto V_55;
V_25 -> V_52 = V_52 ;
}
V_31 = V_8 -> V_17 . error ;
goto V_44;
}
V_55:
F_6 ( V_8 ) ;
V_31 = - V_20 ;
V_8 = NULL ;
goto V_44;
V_37:
F_5 ( & V_8 -> V_17 ) ;
V_44:
V_10 -> V_15 = V_8 ;
return V_31 ;
}
static bool F_14 ( struct V_21 * V_22 , struct V_9 * V_10 )
{
struct V_7 * V_8 = (struct V_7 * ) V_10 -> V_15 ;
struct V_57 * V_53 = NULL ;
if ( V_8 -> V_58 )
V_53 = V_8 -> V_58 -> V_53 ;
if ( V_8 -> V_59 . V_49 <= V_22 -> V_60 )
goto V_61;
if ( V_22 -> V_62 != - 1 && V_53 && V_53 -> V_63 == V_22 -> V_62 )
goto V_61;
return false ;
V_61:
F_6 ( V_8 ) ;
return true ;
}
static int F_15 ( struct V_21 * V_22 , struct V_23 * V_64 , int V_5 )
{
struct V_45 * V_46 = (struct V_45 * ) V_22 ;
struct V_3 * V_4 = & V_64 -> V_26 . V_27 ;
if ( V_46 -> V_17 . V_49 &&
! F_13 ( & V_4 -> V_54 , & V_46 -> V_17 . V_56 , V_46 -> V_17 . V_49 ) )
return 0 ;
if ( V_46 -> V_48 . V_49 ) {
if ( V_5 & V_50 ) {
if ( ! F_13 ( & V_4 -> V_52 , & V_46 -> V_48 . V_56 ,
V_46 -> V_48 . V_49 ) )
return 0 ;
} else if ( ! ( V_46 -> V_65 . V_5 & V_47 ) )
return 0 ;
}
if ( V_46 -> V_66 && V_46 -> V_66 != F_16 ( V_4 -> V_67 ) )
return 0 ;
return 1 ;
}
static int F_17 ( struct V_21 * V_22 , struct V_68 * V_69 ,
struct V_70 * V_71 ,
struct V_72 * * V_73 )
{
int V_31 = - V_39 ;
struct V_2 * V_2 = F_18 ( V_69 -> V_74 ) ;
struct V_45 * V_75 = (struct V_45 * ) V_22 ;
if ( V_22 -> V_33 == V_34 && ! V_22 -> V_76 ) {
if ( V_22 -> V_29 == V_77 )
goto V_78;
if ( F_19 ( V_2 , V_22 -> V_29 ) == NULL ) {
V_31 = - V_79 ;
goto V_78;
}
}
if ( V_71 -> V_80 )
V_75 -> V_48 . V_56 = F_20 ( V_73 [ V_81 ] ) ;
if ( V_71 -> V_82 )
V_75 -> V_17 . V_56 = F_20 ( V_73 [ V_83 ] ) ;
V_75 -> V_48 . V_49 = V_71 -> V_80 ;
V_75 -> V_17 . V_49 = V_71 -> V_82 ;
V_75 -> V_66 = V_71 -> V_84 ;
V_31 = 0 ;
V_78:
return V_31 ;
}
static int F_21 ( struct V_21 * V_22 , struct V_70 * V_71 ,
struct V_72 * * V_73 )
{
struct V_45 * V_75 = (struct V_45 * ) V_22 ;
if ( V_71 -> V_80 && ( V_75 -> V_48 . V_49 != V_71 -> V_80 ) )
return 0 ;
if ( V_71 -> V_82 && ( V_75 -> V_17 . V_49 != V_71 -> V_82 ) )
return 0 ;
if ( V_71 -> V_84 && ( V_75 -> V_66 != V_71 -> V_84 ) )
return 0 ;
if ( V_71 -> V_80 &&
F_22 ( V_73 [ V_81 ] , & V_75 -> V_48 . V_56 , sizeof( struct V_51 ) ) )
return 0 ;
if ( V_71 -> V_82 &&
F_22 ( V_73 [ V_83 ] , & V_75 -> V_17 . V_56 , sizeof( struct V_51 ) ) )
return 0 ;
return 1 ;
}
static int F_23 ( struct V_21 * V_22 , struct V_68 * V_69 ,
struct V_70 * V_71 )
{
struct V_45 * V_75 = (struct V_45 * ) V_22 ;
V_71 -> V_82 = V_75 -> V_17 . V_49 ;
V_71 -> V_80 = V_75 -> V_48 . V_49 ;
V_71 -> V_84 = V_75 -> V_66 ;
if ( ( V_75 -> V_17 . V_49 &&
F_24 ( V_69 , V_83 , & V_75 -> V_17 . V_56 ) ) ||
( V_75 -> V_48 . V_49 &&
F_24 ( V_69 , V_81 , & V_75 -> V_48 . V_56 ) ) )
goto V_85;
return 0 ;
V_85:
return - V_79 ;
}
static T_3 F_25 ( struct V_21 * V_22 )
{
return F_26 ( 16 )
+ F_26 ( 16 ) ;
}
static int T_4 F_27 ( struct V_2 * V_2 )
{
struct V_86 * V_87 ;
int V_31 = - V_88 ;
V_87 = F_28 ( & V_89 , V_2 ) ;
if ( F_29 ( V_87 ) )
return F_30 ( V_87 ) ;
V_31 = F_31 ( V_87 , 0 , V_90 , 0 ) ;
if ( V_31 )
goto V_91;
V_31 = F_31 ( V_87 , 0x7FFE , V_92 , 0 ) ;
if ( V_31 )
goto V_91;
V_2 -> V_13 . V_14 = V_87 ;
V_44:
return V_31 ;
V_91:
F_32 ( V_87 ) ;
goto V_44;
}
static void T_5 F_33 ( struct V_2 * V_2 )
{
F_34 () ;
F_32 ( V_2 -> V_13 . V_14 ) ;
F_35 () ;
}
int T_6 F_36 ( void )
{
return F_37 ( & V_93 ) ;
}
void F_38 ( void )
{
F_39 ( & V_93 ) ;
}
