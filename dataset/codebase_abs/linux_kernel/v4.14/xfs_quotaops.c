static void
F_1 (
struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_5 * V_6 ,
T_1 V_7 )
{
struct V_8 * V_9 = V_4 -> V_10 ;
bool V_11 = false ;
V_2 -> V_7 = V_7 ;
if ( ! V_6 && V_7 == V_12 )
return;
if ( ! V_6 ) {
if ( F_2 ( V_4 , NULL , V_7 , 0 , 0 , & V_6 ) )
return;
V_11 = true ;
}
V_2 -> V_13 |= V_14 ;
V_2 -> V_15 = V_6 -> V_16 . V_17 ;
V_2 -> V_18 = V_6 -> V_16 . V_19 ;
V_2 -> V_20 = V_9 -> V_21 ;
V_2 -> V_22 = V_9 -> V_23 ;
V_2 -> V_24 = V_9 -> V_25 ;
V_2 -> V_26 = V_9 -> V_27 ;
V_2 -> V_28 = V_9 -> V_29 ;
V_2 -> V_30 = V_9 -> V_31 ;
if ( V_11 )
F_3 ( V_6 ) ;
}
static int
F_4 (
struct V_32 * V_33 ,
struct V_34 * V_35 )
{
struct V_3 * V_4 = F_5 ( V_33 ) ;
struct V_8 * V_9 = V_4 -> V_10 ;
memset ( V_35 , 0 , sizeof( * V_35 ) ) ;
if ( ! F_6 ( V_4 ) )
return 0 ;
V_35 -> V_36 = V_9 -> V_37 ;
if ( F_7 ( V_4 ) )
V_35 -> V_38 [ V_39 ] . V_13 |= V_40 ;
if ( F_8 ( V_4 ) )
V_35 -> V_38 [ V_39 ] . V_13 |= V_41 ;
if ( F_9 ( V_4 ) )
V_35 -> V_38 [ V_42 ] . V_13 |= V_40 ;
if ( F_10 ( V_4 ) )
V_35 -> V_38 [ V_42 ] . V_13 |= V_41 ;
if ( F_11 ( V_4 ) )
V_35 -> V_38 [ V_43 ] . V_13 |= V_40 ;
if ( F_12 ( V_4 ) )
V_35 -> V_38 [ V_43 ] . V_13 |= V_41 ;
F_1 ( & V_35 -> V_38 [ V_39 ] , V_4 , V_9 -> V_44 ,
V_4 -> V_45 . V_46 ) ;
F_1 ( & V_35 -> V_38 [ V_42 ] , V_4 , V_9 -> V_47 ,
V_4 -> V_45 . V_48 ) ;
F_1 ( & V_35 -> V_38 [ V_43 ] , V_4 , V_9 -> V_49 ,
V_4 -> V_45 . V_50 ) ;
return 0 ;
}
STATIC int
F_13 ( int type )
{
switch ( type ) {
case V_39 :
return V_51 ;
case V_42 :
return V_52 ;
default:
return V_53 ;
}
}
static int
F_14 (
struct V_32 * V_33 ,
int type ,
struct V_54 * V_55 )
{
struct V_3 * V_4 = F_5 ( V_33 ) ;
struct V_56 V_57 ;
if ( F_15 ( V_33 ) )
return - V_58 ;
if ( ! F_6 ( V_4 ) )
return - V_59 ;
if ( ! F_16 ( V_4 ) )
return - V_60 ;
if ( V_55 -> V_61 & ~ V_62 )
return - V_63 ;
if ( ( V_55 -> V_61 & V_62 ) == 0 )
return 0 ;
V_57 . V_64 = V_55 -> V_61 ;
V_57 . V_65 = V_55 -> V_66 ;
V_57 . V_67 = V_55 -> V_68 ;
V_57 . V_69 = V_55 -> V_70 ;
V_57 . V_71 = V_55 -> V_72 ;
V_57 . V_73 = V_55 -> V_74 ;
V_57 . V_75 = V_55 -> V_76 ;
return F_17 ( V_4 , 0 , F_13 ( type ) , & V_57 ) ;
}
static unsigned int
F_18 ( unsigned int V_77 )
{
unsigned int V_13 = 0 ;
if ( V_77 & V_78 )
V_13 |= V_79 ;
if ( V_77 & V_80 )
V_13 |= V_81 ;
if ( V_77 & V_82 )
V_13 |= V_83 ;
if ( V_77 & V_84 )
V_13 |= V_85 ;
if ( V_77 & V_86 )
V_13 |= V_87 ;
if ( V_77 & V_88 )
V_13 |= V_89 ;
return V_13 ;
}
STATIC int
F_19 (
struct V_32 * V_33 ,
unsigned int V_77 )
{
struct V_3 * V_4 = F_5 ( V_33 ) ;
if ( F_15 ( V_33 ) )
return - V_58 ;
if ( ! F_6 ( V_4 ) )
return - V_59 ;
return F_20 ( V_4 , F_18 ( V_77 ) ) ;
}
STATIC int
F_21 (
struct V_32 * V_33 ,
unsigned int V_77 )
{
struct V_3 * V_4 = F_5 ( V_33 ) ;
if ( F_15 ( V_33 ) )
return - V_58 ;
if ( ! F_6 ( V_4 ) )
return - V_59 ;
if ( ! F_16 ( V_4 ) )
return - V_63 ;
return F_22 ( V_4 , F_18 ( V_77 ) ) ;
}
STATIC int
F_23 (
struct V_32 * V_33 ,
unsigned int V_77 )
{
struct V_3 * V_4 = F_5 ( V_33 ) ;
unsigned int V_13 = 0 ;
if ( F_15 ( V_33 ) )
return - V_58 ;
if ( F_16 ( V_4 ) )
return - V_63 ;
if ( V_77 & V_90 )
V_13 |= V_51 ;
if ( V_77 & V_91 )
V_13 |= V_52 ;
if ( V_77 & V_92 )
V_13 |= V_53 ;
return F_24 ( V_4 , V_13 ) ;
}
STATIC int
F_25 (
struct V_32 * V_33 ,
struct V_93 V_94 ,
struct V_56 * V_95 )
{
struct V_3 * V_4 = F_5 ( V_33 ) ;
T_2 V_96 ;
if ( ! F_6 ( V_4 ) )
return - V_59 ;
if ( ! F_16 ( V_4 ) )
return - V_60 ;
V_96 = F_26 ( & V_97 , V_94 ) ;
return F_27 ( V_4 , & V_96 ,
F_13 ( V_94 . type ) , V_95 , 0 ) ;
}
STATIC int
F_28 (
struct V_32 * V_33 ,
struct V_93 * V_94 ,
struct V_56 * V_95 )
{
int V_98 ;
struct V_3 * V_4 = F_5 ( V_33 ) ;
T_2 V_96 ;
if ( ! F_6 ( V_4 ) )
return - V_59 ;
if ( ! F_16 ( V_4 ) )
return - V_60 ;
V_96 = F_26 ( & V_97 , * V_94 ) ;
V_98 = F_27 ( V_4 , & V_96 ,
F_13 ( V_94 -> type ) , V_95 ,
V_99 ) ;
if ( V_98 )
return V_98 ;
* V_94 = F_29 ( F_30 () , V_94 -> type , V_96 ) ;
return 0 ;
}
STATIC int
F_31 (
struct V_32 * V_33 ,
struct V_93 V_94 ,
struct V_56 * V_95 )
{
struct V_3 * V_4 = F_5 ( V_33 ) ;
if ( F_15 ( V_33 ) )
return - V_58 ;
if ( ! F_6 ( V_4 ) )
return - V_59 ;
if ( ! F_16 ( V_4 ) )
return - V_60 ;
return F_17 ( V_4 , F_26 ( & V_97 , V_94 ) ,
F_13 ( V_94 . type ) , V_95 ) ;
}
