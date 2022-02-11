struct V_1 * F_1 ( struct V_2 * V_2 , struct V_3 * V_4 ,
int V_5 , T_1 V_6 )
{
struct V_7 V_8 = {
. V_9 = V_6 ,
. V_5 = V_10 ,
} ;
F_2 ( V_2 , F_3 ( V_4 ) ) ;
F_4 ( V_2 -> V_11 . V_12 ,
F_3 ( V_4 ) , V_5 , & V_8 ) ;
if ( V_8 . V_13 )
return V_8 . V_13 ;
F_5 ( & V_2 -> V_11 . V_14 -> V_15 ) ;
return & V_2 -> V_11 . V_14 -> V_15 ;
}
static int F_6 ( struct V_16 * V_17 , struct V_18 * V_19 ,
int V_5 , struct V_7 * V_8 )
{
struct V_3 * V_20 = & V_19 -> V_21 . V_22 ;
struct V_23 * V_24 = NULL ;
struct V_25 * V_26 ;
struct V_2 * V_2 = V_17 -> V_27 ;
T_1 V_6 = V_8 -> V_9 ;
int V_28 = 0 ;
T_2 V_29 ;
switch ( V_17 -> V_30 ) {
case V_31 :
break;
case V_32 :
V_28 = - V_33 ;
V_24 = V_2 -> V_11 . V_14 ;
goto V_34;
default:
case V_35 :
V_28 = - V_36 ;
V_24 = V_2 -> V_11 . V_37 ;
goto V_34;
case V_38 :
V_28 = - V_39 ;
V_24 = V_2 -> V_11 . V_40 ;
goto V_34;
}
V_29 = F_7 ( V_17 , V_8 ) ;
V_26 = F_8 ( V_2 , V_29 ) ;
if ( ! V_26 ) {
V_28 = - V_41 ;
goto V_42;
}
V_24 = V_6 ( V_2 , V_26 , V_20 , V_5 ) ;
if ( V_24 != V_2 -> V_11 . V_14 ) {
struct V_43 * V_44 = (struct V_43 * ) V_17 ;
if ( ( V_17 -> V_5 & V_45 ) &&
V_44 -> V_46 . V_47 && ! ( V_5 & V_48 ) ) {
struct V_49 V_50 ;
if ( F_9 ( V_2 ,
F_10 ( & V_24 -> V_15 ) -> V_51 ,
& V_20 -> V_52 ,
F_11 ( V_5 ) ,
& V_50 ) )
goto V_53;
if ( ! F_12 ( & V_50 , & V_44 -> V_46 . V_54 ,
V_44 -> V_46 . V_47 ) )
goto V_53;
V_20 -> V_50 = V_50 ;
}
V_28 = V_24 -> V_15 . error ;
if ( V_28 != - V_41 )
goto V_42;
}
V_53:
F_13 ( V_24 ) ;
V_28 = - V_41 ;
V_24 = NULL ;
goto V_42;
V_34:
F_5 ( & V_24 -> V_15 ) ;
V_42:
V_8 -> V_13 = V_24 ;
return V_28 ;
}
static bool F_14 ( struct V_16 * V_17 , struct V_7 * V_8 )
{
struct V_23 * V_24 = (struct V_23 * ) V_8 -> V_13 ;
struct V_55 * V_51 = NULL ;
if ( V_24 -> V_56 )
V_51 = V_24 -> V_56 -> V_51 ;
if ( V_24 -> V_57 . V_47 <= V_17 -> V_58 )
goto V_59;
if ( V_17 -> V_60 != - 1 && V_51 && V_51 -> V_61 == V_17 -> V_60 )
goto V_59;
return false ;
V_59:
F_13 ( V_24 ) ;
return true ;
}
static int F_15 ( struct V_16 * V_17 , struct V_18 * V_62 , int V_5 )
{
struct V_43 * V_44 = (struct V_43 * ) V_17 ;
struct V_3 * V_4 = & V_62 -> V_21 . V_22 ;
if ( V_44 -> V_15 . V_47 &&
! F_12 ( & V_4 -> V_52 , & V_44 -> V_15 . V_54 , V_44 -> V_15 . V_47 ) )
return 0 ;
if ( V_44 -> V_46 . V_47 ) {
if ( V_5 & V_48 ) {
if ( ! F_12 ( & V_4 -> V_50 , & V_44 -> V_46 . V_54 ,
V_44 -> V_46 . V_47 ) )
return 0 ;
} else if ( ! ( V_44 -> V_63 . V_5 & V_45 ) )
return 0 ;
}
if ( V_44 -> V_64 && V_44 -> V_64 != F_16 ( V_4 -> V_65 ) )
return 0 ;
return 1 ;
}
static int F_17 ( struct V_16 * V_17 , struct V_66 * V_67 ,
struct V_68 * V_69 ,
struct V_70 * * V_71 )
{
int V_28 = - V_36 ;
struct V_2 * V_2 = F_18 ( V_67 -> V_72 ) ;
struct V_43 * V_73 = (struct V_43 * ) V_17 ;
if ( V_17 -> V_30 == V_31 && ! V_17 -> V_74 ) {
if ( V_17 -> V_26 == V_75 )
goto V_76;
if ( F_19 ( V_2 , V_17 -> V_26 ) == NULL ) {
V_28 = - V_77 ;
goto V_76;
}
}
if ( V_69 -> V_78 )
V_73 -> V_46 . V_54 = F_20 ( V_71 [ V_79 ] ) ;
if ( V_69 -> V_80 )
V_73 -> V_15 . V_54 = F_20 ( V_71 [ V_81 ] ) ;
V_73 -> V_46 . V_47 = V_69 -> V_78 ;
V_73 -> V_15 . V_47 = V_69 -> V_80 ;
V_73 -> V_64 = V_69 -> V_82 ;
V_28 = 0 ;
V_76:
return V_28 ;
}
static int F_21 ( struct V_16 * V_17 , struct V_68 * V_69 ,
struct V_70 * * V_71 )
{
struct V_43 * V_73 = (struct V_43 * ) V_17 ;
if ( V_69 -> V_78 && ( V_73 -> V_46 . V_47 != V_69 -> V_78 ) )
return 0 ;
if ( V_69 -> V_80 && ( V_73 -> V_15 . V_47 != V_69 -> V_80 ) )
return 0 ;
if ( V_69 -> V_82 && ( V_73 -> V_64 != V_69 -> V_82 ) )
return 0 ;
if ( V_69 -> V_78 &&
F_22 ( V_71 [ V_79 ] , & V_73 -> V_46 . V_54 , sizeof( struct V_49 ) ) )
return 0 ;
if ( V_69 -> V_80 &&
F_22 ( V_71 [ V_81 ] , & V_73 -> V_15 . V_54 , sizeof( struct V_49 ) ) )
return 0 ;
return 1 ;
}
static int F_23 ( struct V_16 * V_17 , struct V_66 * V_67 ,
struct V_68 * V_69 )
{
struct V_43 * V_73 = (struct V_43 * ) V_17 ;
V_69 -> V_80 = V_73 -> V_15 . V_47 ;
V_69 -> V_78 = V_73 -> V_46 . V_47 ;
V_69 -> V_82 = V_73 -> V_64 ;
if ( ( V_73 -> V_15 . V_47 &&
F_24 ( V_67 , V_81 , & V_73 -> V_15 . V_54 ) ) ||
( V_73 -> V_46 . V_47 &&
F_24 ( V_67 , V_79 , & V_73 -> V_46 . V_54 ) ) )
goto V_83;
return 0 ;
V_83:
return - V_77 ;
}
static T_3 F_25 ( struct V_16 * V_17 )
{
return F_26 ( 16 )
+ F_26 ( 16 ) ;
}
static int T_4 F_27 ( struct V_2 * V_2 )
{
struct V_84 * V_85 ;
int V_28 = - V_86 ;
V_85 = F_28 ( & V_87 , V_2 ) ;
if ( F_29 ( V_85 ) )
return F_30 ( V_85 ) ;
V_28 = F_31 ( V_85 , 0 , V_88 , 0 ) ;
if ( V_28 )
goto V_89;
V_28 = F_31 ( V_85 , 0x7FFE , V_90 , 0 ) ;
if ( V_28 )
goto V_89;
V_2 -> V_11 . V_12 = V_85 ;
V_42:
return V_28 ;
V_89:
F_32 ( V_85 ) ;
goto V_42;
}
static void T_5 F_33 ( struct V_2 * V_2 )
{
F_34 () ;
F_32 ( V_2 -> V_11 . V_12 ) ;
F_35 () ;
}
int T_6 F_36 ( void )
{
return F_37 ( & V_91 ) ;
}
void F_38 ( void )
{
F_39 ( & V_91 ) ;
}
