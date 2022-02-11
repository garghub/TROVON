static bool F_1 ( const struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 , struct V_3 , V_5 ) ;
if ( V_4 -> V_6 . V_7 || V_4 -> V_8 . V_7 || V_4 -> V_9 )
return false ;
return F_3 ( V_2 ) ;
}
bool F_4 ( const struct V_1 * V_2 )
{
if ( ! F_1 ( V_2 ) || V_2 -> V_10 != V_11 ||
V_2 -> V_12 )
return false ;
if ( V_2 -> V_13 != V_14 && V_2 -> V_13 != V_15 )
return false ;
return true ;
}
int F_5 ( struct V_16 * V_16 , struct V_17 * V_18 )
{
return F_6 ( V_16 , V_18 , V_19 ) ;
}
unsigned int F_7 ( struct V_16 * V_16 )
{
return F_8 ( V_16 , V_19 ) ;
}
struct V_20 * F_9 ( struct V_16 * V_16 , struct V_21 * V_22 ,
int V_23 , T_1 V_24 )
{
if ( V_16 -> V_25 . V_26 ) {
struct V_27 V_28 = {
. V_29 = V_24 ,
. V_23 = V_30 ,
} ;
F_10 ( V_16 , F_11 ( V_22 ) ) ;
F_12 ( V_16 -> V_25 . V_31 ,
F_11 ( V_22 ) , V_23 , & V_28 ) ;
if ( V_28 . V_32 )
return V_28 . V_32 ;
} else {
struct V_33 * V_34 ;
V_34 = V_24 ( V_16 , V_16 -> V_25 . V_35 , V_22 , V_23 ) ;
if ( V_34 != V_16 -> V_25 . V_36 && V_34 -> V_6 . error != - V_37 )
return & V_34 -> V_6 ;
F_13 ( V_34 ) ;
V_34 = V_24 ( V_16 , V_16 -> V_25 . V_38 , V_22 , V_23 ) ;
if ( V_34 -> V_6 . error != - V_37 )
return & V_34 -> V_6 ;
F_13 ( V_34 ) ;
}
F_14 ( & V_16 -> V_25 . V_36 -> V_6 ) ;
return & V_16 -> V_25 . V_36 -> V_6 ;
}
static int F_15 ( struct V_1 * V_2 , struct V_39 * V_40 ,
int V_23 , struct V_27 * V_28 )
{
struct V_21 * V_41 = & V_40 -> V_42 . V_43 ;
struct V_33 * V_34 = NULL ;
struct V_44 * V_13 ;
struct V_16 * V_16 = V_2 -> V_45 ;
T_1 V_24 = V_28 -> V_29 ;
int V_46 = 0 ;
T_2 V_47 ;
switch ( V_2 -> V_10 ) {
case V_11 :
break;
case V_48 :
V_46 = - V_49 ;
V_34 = V_16 -> V_25 . V_36 ;
goto V_50;
default:
case V_51 :
V_46 = - V_52 ;
V_34 = V_16 -> V_25 . V_53 ;
goto V_50;
case V_54 :
V_46 = - V_55 ;
V_34 = V_16 -> V_25 . V_56 ;
goto V_50;
}
V_47 = F_16 ( V_2 , V_28 ) ;
V_13 = F_17 ( V_16 , V_47 ) ;
if ( ! V_13 ) {
V_46 = - V_37 ;
goto V_57;
}
V_34 = V_24 ( V_16 , V_13 , V_41 , V_23 ) ;
if ( V_34 != V_16 -> V_25 . V_36 ) {
struct V_3 * V_4 = (struct V_3 * ) V_2 ;
if ( ( V_2 -> V_23 & V_58 ) &&
V_4 -> V_8 . V_7 && ! ( V_23 & V_59 ) ) {
struct V_60 V_61 ;
if ( F_18 ( V_16 ,
F_19 ( & V_34 -> V_6 ) -> V_62 ,
& V_41 -> V_63 ,
F_20 ( V_23 ) ,
& V_61 ) )
goto V_64;
if ( ! F_21 ( & V_61 , & V_4 -> V_8 . V_65 ,
V_4 -> V_8 . V_7 ) )
goto V_64;
V_41 -> V_61 = V_61 ;
}
V_46 = V_34 -> V_6 . error ;
if ( V_46 != - V_37 )
goto V_57;
}
V_64:
F_13 ( V_34 ) ;
V_46 = - V_37 ;
V_34 = NULL ;
goto V_57;
V_50:
F_14 ( & V_34 -> V_6 ) ;
V_57:
V_28 -> V_32 = V_34 ;
return V_46 ;
}
static bool F_22 ( struct V_1 * V_2 , struct V_27 * V_28 )
{
struct V_33 * V_34 = (struct V_33 * ) V_28 -> V_32 ;
struct V_66 * V_62 = NULL ;
if ( V_34 -> V_67 )
V_62 = V_34 -> V_67 -> V_62 ;
if ( V_34 -> V_68 . V_7 <= V_2 -> V_69 )
goto V_70;
if ( V_2 -> V_71 != - 1 && V_62 && V_62 -> V_72 == V_2 -> V_71 )
goto V_70;
return false ;
V_70:
F_13 ( V_34 ) ;
return true ;
}
static int F_23 ( struct V_1 * V_2 , struct V_39 * V_73 , int V_23 )
{
struct V_3 * V_4 = (struct V_3 * ) V_2 ;
struct V_21 * V_22 = & V_73 -> V_42 . V_43 ;
if ( V_4 -> V_6 . V_7 &&
! F_21 ( & V_22 -> V_63 , & V_4 -> V_6 . V_65 , V_4 -> V_6 . V_7 ) )
return 0 ;
if ( V_4 -> V_8 . V_7 ) {
if ( V_23 & V_59 ) {
if ( ! F_21 ( & V_22 -> V_61 , & V_4 -> V_8 . V_65 ,
V_4 -> V_8 . V_7 ) )
return 0 ;
} else if ( ! ( V_4 -> V_5 . V_23 & V_58 ) )
return 0 ;
}
if ( V_4 -> V_9 && V_4 -> V_9 != F_24 ( V_22 -> V_74 ) )
return 0 ;
return 1 ;
}
static int F_25 ( struct V_1 * V_2 , struct V_75 * V_76 ,
struct V_77 * V_78 ,
struct V_79 * * V_80 )
{
int V_46 = - V_52 ;
struct V_16 * V_16 = F_26 ( V_76 -> V_81 ) ;
struct V_3 * V_82 = (struct V_3 * ) V_2 ;
if ( V_2 -> V_10 == V_11 && ! V_2 -> V_12 ) {
if ( V_2 -> V_13 == V_83 )
goto V_84;
if ( F_27 ( V_16 , V_2 -> V_13 ) == NULL ) {
V_46 = - V_85 ;
goto V_84;
}
}
if ( V_78 -> V_86 )
V_82 -> V_8 . V_65 = F_28 ( V_80 [ V_87 ] ) ;
if ( V_78 -> V_88 )
V_82 -> V_6 . V_65 = F_28 ( V_80 [ V_89 ] ) ;
V_82 -> V_8 . V_7 = V_78 -> V_86 ;
V_82 -> V_6 . V_7 = V_78 -> V_88 ;
V_82 -> V_9 = V_78 -> V_90 ;
V_16 -> V_25 . V_26 = true ;
V_46 = 0 ;
V_84:
return V_46 ;
}
static int F_29 ( struct V_1 * V_2 , struct V_77 * V_78 ,
struct V_79 * * V_80 )
{
struct V_3 * V_82 = (struct V_3 * ) V_2 ;
if ( V_78 -> V_86 && ( V_82 -> V_8 . V_7 != V_78 -> V_86 ) )
return 0 ;
if ( V_78 -> V_88 && ( V_82 -> V_6 . V_7 != V_78 -> V_88 ) )
return 0 ;
if ( V_78 -> V_90 && ( V_82 -> V_9 != V_78 -> V_90 ) )
return 0 ;
if ( V_78 -> V_86 &&
F_30 ( V_80 [ V_87 ] , & V_82 -> V_8 . V_65 , sizeof( struct V_60 ) ) )
return 0 ;
if ( V_78 -> V_88 &&
F_30 ( V_80 [ V_89 ] , & V_82 -> V_6 . V_65 , sizeof( struct V_60 ) ) )
return 0 ;
return 1 ;
}
static int F_31 ( struct V_1 * V_2 , struct V_75 * V_76 ,
struct V_77 * V_78 )
{
struct V_3 * V_82 = (struct V_3 * ) V_2 ;
V_78 -> V_88 = V_82 -> V_6 . V_7 ;
V_78 -> V_86 = V_82 -> V_8 . V_7 ;
V_78 -> V_90 = V_82 -> V_9 ;
if ( ( V_82 -> V_6 . V_7 &&
F_32 ( V_76 , V_89 , & V_82 -> V_6 . V_65 ) ) ||
( V_82 -> V_8 . V_7 &&
F_32 ( V_76 , V_87 , & V_82 -> V_8 . V_65 ) ) )
goto V_91;
return 0 ;
V_91:
return - V_85 ;
}
static T_3 F_33 ( struct V_1 * V_2 )
{
return F_34 ( 16 )
+ F_34 ( 16 ) ;
}
static int T_4 F_35 ( struct V_16 * V_16 )
{
struct V_92 * V_93 ;
int V_46 = - V_94 ;
V_93 = F_36 ( & V_95 , V_16 ) ;
if ( F_37 ( V_93 ) )
return F_38 ( V_93 ) ;
V_46 = F_39 ( V_93 , 0 , V_14 , 0 ) ;
if ( V_46 )
goto V_96;
V_46 = F_39 ( V_93 , 0x7FFE , V_15 , 0 ) ;
if ( V_46 )
goto V_96;
V_16 -> V_25 . V_31 = V_93 ;
V_57:
return V_46 ;
V_96:
F_40 ( V_93 ) ;
goto V_57;
}
static void T_5 F_41 ( struct V_16 * V_16 )
{
F_42 () ;
F_40 ( V_16 -> V_25 . V_31 ) ;
F_43 () ;
}
int T_6 F_44 ( void )
{
return F_45 ( & V_97 ) ;
}
void F_46 ( void )
{
F_47 ( & V_97 ) ;
}
