struct V_1 * F_1 ( struct V_2 * V_2 , struct V_3 * V_4 ,
int V_5 , T_1 V_6 )
{
struct V_7 * V_8 ;
struct V_9 V_10 = {
. V_11 = V_6 ,
. V_5 = V_12 ,
} ;
F_2 ( V_2 -> V_13 . V_14 ,
F_3 ( V_4 ) , V_5 , & V_10 ) ;
V_8 = V_10 . V_15 ;
if ( ! V_8 ) {
F_4 ( & V_2 -> V_13 . V_16 -> V_17 ) ;
return & V_2 -> V_13 . V_16 -> V_17 ;
}
if ( V_8 -> V_18 & V_19 &&
V_8 -> V_17 . error == - V_20 ) {
F_5 ( V_8 ) ;
V_8 = V_2 -> V_13 . V_16 ;
F_4 ( & V_8 -> V_17 ) ;
}
return & V_8 -> V_17 ;
}
static int F_6 ( struct V_21 * V_22 , struct V_23 * V_24 ,
int V_5 , struct V_9 * V_10 )
{
struct V_3 * V_25 = & V_24 -> V_26 . V_27 ;
struct V_7 * V_8 = NULL ;
struct V_28 * V_29 ;
struct V_2 * V_2 = V_22 -> V_30 ;
T_1 V_6 = V_10 -> V_11 ;
int V_31 = 0 ;
switch ( V_22 -> V_32 ) {
case V_33 :
break;
case V_34 :
V_31 = - V_35 ;
V_8 = V_2 -> V_13 . V_16 ;
goto V_36;
default:
case V_37 :
V_31 = - V_38 ;
V_8 = V_2 -> V_13 . V_39 ;
goto V_36;
case V_40 :
V_31 = - V_41 ;
V_8 = V_2 -> V_13 . V_42 ;
goto V_36;
}
V_29 = F_7 ( V_2 , V_22 -> V_29 ) ;
if ( ! V_29 ) {
V_31 = - V_20 ;
goto V_43;
}
V_8 = V_6 ( V_2 , V_29 , V_25 , V_5 ) ;
if ( V_8 != V_2 -> V_13 . V_16 ) {
struct V_44 * V_45 = (struct V_44 * ) V_22 ;
if ( ( V_22 -> V_5 & V_46 ) &&
V_45 -> V_47 . V_48 && ! ( V_5 & V_49 ) ) {
struct V_50 V_51 ;
if ( F_8 ( V_2 ,
F_9 ( & V_8 -> V_17 ) -> V_52 ,
& V_25 -> V_53 ,
F_10 ( V_5 ) ,
& V_51 ) )
goto V_54;
if ( ! F_11 ( & V_51 , & V_45 -> V_47 . V_55 ,
V_45 -> V_47 . V_48 ) )
goto V_54;
V_25 -> V_51 = V_51 ;
}
V_31 = V_8 -> V_17 . error ;
goto V_43;
}
V_54:
F_5 ( V_8 ) ;
V_31 = - V_20 ;
V_8 = NULL ;
goto V_43;
V_36:
F_4 ( & V_8 -> V_17 ) ;
V_43:
V_10 -> V_15 = V_8 ;
return V_31 ;
}
static bool F_12 ( struct V_21 * V_22 , struct V_9 * V_10 )
{
struct V_7 * V_8 = (struct V_7 * ) V_10 -> V_15 ;
struct V_56 * V_52 = NULL ;
if ( V_8 -> V_57 )
V_52 = V_8 -> V_57 -> V_52 ;
if ( V_8 -> V_58 . V_48 <= V_22 -> V_59 )
goto V_60;
if ( V_22 -> V_61 != - 1 && V_52 && V_52 -> V_62 == V_22 -> V_61 )
goto V_60;
return false ;
V_60:
F_5 ( V_8 ) ;
return true ;
}
static int F_13 ( struct V_21 * V_22 , struct V_23 * V_63 , int V_5 )
{
struct V_44 * V_45 = (struct V_44 * ) V_22 ;
struct V_3 * V_4 = & V_63 -> V_26 . V_27 ;
if ( V_45 -> V_17 . V_48 &&
! F_11 ( & V_4 -> V_53 , & V_45 -> V_17 . V_55 , V_45 -> V_17 . V_48 ) )
return 0 ;
if ( V_45 -> V_47 . V_48 ) {
if ( V_5 & V_49 ) {
if ( ! F_11 ( & V_4 -> V_51 , & V_45 -> V_47 . V_55 ,
V_45 -> V_47 . V_48 ) )
return 0 ;
} else if ( ! ( V_45 -> V_64 . V_5 & V_46 ) )
return 0 ;
}
if ( V_45 -> V_65 && V_45 -> V_65 != F_14 ( V_4 -> V_66 ) )
return 0 ;
return 1 ;
}
static int F_15 ( struct V_21 * V_22 , struct V_67 * V_68 ,
struct V_69 * V_70 ,
struct V_71 * * V_72 )
{
int V_31 = - V_38 ;
struct V_2 * V_2 = F_16 ( V_68 -> V_73 ) ;
struct V_44 * V_74 = (struct V_44 * ) V_22 ;
if ( V_22 -> V_32 == V_33 ) {
if ( V_22 -> V_29 == V_75 )
goto V_76;
if ( F_17 ( V_2 , V_22 -> V_29 ) == NULL ) {
V_31 = - V_77 ;
goto V_76;
}
}
if ( V_70 -> V_78 )
V_74 -> V_47 . V_55 = F_18 ( V_72 [ V_79 ] ) ;
if ( V_70 -> V_80 )
V_74 -> V_17 . V_55 = F_18 ( V_72 [ V_81 ] ) ;
V_74 -> V_47 . V_48 = V_70 -> V_78 ;
V_74 -> V_17 . V_48 = V_70 -> V_80 ;
V_74 -> V_65 = V_70 -> V_82 ;
V_31 = 0 ;
V_76:
return V_31 ;
}
static int F_19 ( struct V_21 * V_22 , struct V_69 * V_70 ,
struct V_71 * * V_72 )
{
struct V_44 * V_74 = (struct V_44 * ) V_22 ;
if ( V_70 -> V_78 && ( V_74 -> V_47 . V_48 != V_70 -> V_78 ) )
return 0 ;
if ( V_70 -> V_80 && ( V_74 -> V_17 . V_48 != V_70 -> V_80 ) )
return 0 ;
if ( V_70 -> V_82 && ( V_74 -> V_65 != V_70 -> V_82 ) )
return 0 ;
if ( V_70 -> V_78 &&
F_20 ( V_72 [ V_79 ] , & V_74 -> V_47 . V_55 , sizeof( struct V_50 ) ) )
return 0 ;
if ( V_70 -> V_80 &&
F_20 ( V_72 [ V_81 ] , & V_74 -> V_17 . V_55 , sizeof( struct V_50 ) ) )
return 0 ;
return 1 ;
}
static int F_21 ( struct V_21 * V_22 , struct V_67 * V_68 ,
struct V_69 * V_70 )
{
struct V_44 * V_74 = (struct V_44 * ) V_22 ;
V_70 -> V_80 = V_74 -> V_17 . V_48 ;
V_70 -> V_78 = V_74 -> V_47 . V_48 ;
V_70 -> V_82 = V_74 -> V_65 ;
if ( ( V_74 -> V_17 . V_48 &&
F_22 ( V_68 , V_81 , & V_74 -> V_17 . V_55 ) ) ||
( V_74 -> V_47 . V_48 &&
F_22 ( V_68 , V_79 , & V_74 -> V_47 . V_55 ) ) )
goto V_83;
return 0 ;
V_83:
return - V_77 ;
}
static T_2 F_23 ( struct V_21 * V_22 )
{
return F_24 ( 16 )
+ F_24 ( 16 ) ;
}
static int T_3 F_25 ( struct V_2 * V_2 )
{
struct V_84 * V_85 ;
int V_31 = - V_86 ;
V_85 = F_26 ( & V_87 , V_2 ) ;
if ( F_27 ( V_85 ) )
return F_28 ( V_85 ) ;
V_31 = F_29 ( V_85 , 0 , V_88 , 0 ) ;
if ( V_31 )
goto V_89;
V_31 = F_29 ( V_85 , 0x7FFE , V_90 , 0 ) ;
if ( V_31 )
goto V_89;
V_2 -> V_13 . V_14 = V_85 ;
V_43:
return V_31 ;
V_89:
F_30 ( V_85 ) ;
goto V_43;
}
static void T_4 F_31 ( struct V_2 * V_2 )
{
F_32 () ;
F_30 ( V_2 -> V_13 . V_14 ) ;
F_33 () ;
}
int T_5 F_34 ( void )
{
return F_35 ( & V_91 ) ;
}
void F_36 ( void )
{
F_37 ( & V_91 ) ;
}
