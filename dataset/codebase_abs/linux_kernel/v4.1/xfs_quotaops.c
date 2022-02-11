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
if ( V_33 -> V_58 & V_59 )
return - V_60 ;
if ( ! F_6 ( V_4 ) )
return - V_61 ;
if ( ! F_15 ( V_4 ) )
return - V_62 ;
if ( V_55 -> V_63 & ~ V_64 )
return - V_65 ;
if ( ( V_55 -> V_63 & V_64 ) == 0 )
return 0 ;
V_57 . V_66 = V_55 -> V_63 ;
V_57 . V_67 = V_55 -> V_68 ;
V_57 . V_69 = V_55 -> V_70 ;
V_57 . V_71 = V_55 -> V_72 ;
V_57 . V_73 = V_55 -> V_74 ;
V_57 . V_75 = V_55 -> V_76 ;
V_57 . V_77 = V_55 -> V_78 ;
return F_16 ( V_4 , 0 , F_13 ( type ) , & V_57 ) ;
}
static unsigned int
F_17 ( unsigned int V_79 )
{
unsigned int V_13 = 0 ;
if ( V_79 & V_80 )
V_13 |= V_81 ;
if ( V_79 & V_82 )
V_13 |= V_83 ;
if ( V_79 & V_84 )
V_13 |= V_85 ;
if ( V_79 & V_86 )
V_13 |= V_87 ;
if ( V_79 & V_88 )
V_13 |= V_89 ;
if ( V_79 & V_90 )
V_13 |= V_91 ;
return V_13 ;
}
STATIC int
F_18 (
struct V_32 * V_33 ,
unsigned int V_79 )
{
struct V_3 * V_4 = F_5 ( V_33 ) ;
if ( V_33 -> V_58 & V_59 )
return - V_60 ;
if ( ! F_6 ( V_4 ) )
return - V_61 ;
return F_19 ( V_4 , F_17 ( V_79 ) ) ;
}
STATIC int
F_20 (
struct V_32 * V_33 ,
unsigned int V_79 )
{
struct V_3 * V_4 = F_5 ( V_33 ) ;
if ( V_33 -> V_58 & V_59 )
return - V_60 ;
if ( ! F_6 ( V_4 ) )
return - V_61 ;
if ( ! F_15 ( V_4 ) )
return - V_65 ;
return F_21 ( V_4 , F_17 ( V_79 ) ) ;
}
STATIC int
F_22 (
struct V_32 * V_33 ,
unsigned int V_79 )
{
struct V_3 * V_4 = F_5 ( V_33 ) ;
unsigned int V_13 = 0 ;
if ( V_33 -> V_58 & V_59 )
return - V_60 ;
if ( F_15 ( V_4 ) )
return - V_65 ;
if ( V_79 & V_92 )
V_13 |= V_51 ;
if ( V_79 & V_93 )
V_13 |= V_52 ;
if ( V_79 & V_94 )
V_13 |= V_53 ;
return F_23 ( V_4 , V_13 ) ;
}
STATIC int
F_24 (
struct V_32 * V_33 ,
struct V_95 V_96 ,
struct V_56 * V_97 )
{
struct V_3 * V_4 = F_5 ( V_33 ) ;
if ( ! F_6 ( V_4 ) )
return - V_61 ;
if ( ! F_15 ( V_4 ) )
return - V_62 ;
return F_25 ( V_4 , F_26 ( & V_98 , V_96 ) ,
F_13 ( V_96 . type ) , V_97 ) ;
}
STATIC int
F_27 (
struct V_32 * V_33 ,
struct V_95 V_96 ,
struct V_56 * V_97 )
{
struct V_3 * V_4 = F_5 ( V_33 ) ;
if ( V_33 -> V_58 & V_59 )
return - V_60 ;
if ( ! F_6 ( V_4 ) )
return - V_61 ;
if ( ! F_15 ( V_4 ) )
return - V_62 ;
return F_16 ( V_4 , F_26 ( & V_98 , V_96 ) ,
F_13 ( V_96 . type ) , V_97 ) ;
}
