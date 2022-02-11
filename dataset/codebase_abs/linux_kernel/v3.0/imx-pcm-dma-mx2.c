static void F_1 ( void * V_1 )
{
struct V_2 * V_3 = (struct V_2 * ) V_1 ;
struct V_4 * V_5 = V_3 -> V_5 ;
struct V_6 * V_7 = V_5 -> V_8 ;
V_7 -> V_9 += V_7 -> V_10 ;
V_7 -> V_9 %= V_7 -> V_10 * V_7 -> V_11 ;
F_2 ( V_3 ) ;
}
static bool F_3 ( struct V_12 * V_13 , void * V_14 )
{
struct V_6 * V_7 = V_14 ;
if ( ! F_4 ( V_13 ) )
return false ;
V_13 -> V_15 = & V_7 -> V_16 ;
return true ;
}
static int F_5 ( struct V_2 * V_3 ,
struct V_17 * V_18 )
{
struct V_19 * V_20 = V_3 -> V_8 ;
struct V_21 * V_22 ;
struct V_4 * V_5 = V_3 -> V_5 ;
struct V_6 * V_7 = V_5 -> V_8 ;
struct V_23 V_24 ;
T_1 V_25 ;
enum V_26 V_27 ;
int V_28 ;
V_22 = F_6 ( V_20 -> V_29 , V_3 ) ;
V_7 -> V_16 . V_30 = V_31 ;
V_7 -> V_16 . V_32 = V_33 ;
V_7 -> V_16 . V_34 = V_22 -> V_35 ;
F_7 ( V_25 ) ;
F_8 ( V_36 , V_25 ) ;
V_7 -> V_12 = F_9 ( V_25 , F_3 , V_7 ) ;
if ( ! V_7 -> V_12 )
return - V_37 ;
switch ( F_10 ( V_18 ) ) {
case V_38 :
V_27 = V_39 ;
break;
case V_40 :
case V_41 :
V_27 = V_42 ;
break;
default:
return 0 ;
}
if ( V_3 -> V_43 == V_44 ) {
V_24 . V_45 = V_46 ;
V_24 . V_47 = V_22 -> V_48 ;
V_24 . V_49 = V_27 ;
V_24 . V_50 = V_22 -> V_51 * V_27 ;
} else {
V_24 . V_45 = V_52 ;
V_24 . V_53 = V_22 -> V_48 ;
V_24 . V_54 = V_27 ;
V_24 . V_55 = V_22 -> V_51 * V_27 ;
}
V_28 = F_11 ( V_7 -> V_12 , & V_24 ) ;
if ( V_28 )
return V_28 ;
return 0 ;
}
static int F_12 ( struct V_2 * V_3 ,
struct V_17 * V_18 )
{
struct V_19 * V_20 = V_3 -> V_8 ;
struct V_4 * V_5 = V_3 -> V_5 ;
struct V_6 * V_7 = V_5 -> V_8 ;
unsigned long V_48 ;
struct V_12 * V_13 ;
struct V_21 * V_22 ;
int V_28 ;
V_22 = F_6 ( V_20 -> V_29 , V_3 ) ;
V_28 = F_5 ( V_3 , V_18 ) ;
if ( V_28 )
return V_28 ;
V_13 = V_7 -> V_12 ;
V_7 -> V_56 = F_13 ( V_18 ) ;
V_7 -> V_11 = F_14 ( V_18 ) ;
V_7 -> V_10 = F_15 ( V_18 ) ;
V_7 -> V_9 = 0 ;
V_7 -> V_57 = V_58 / ( F_16 ( V_18 ) /
F_17 ( V_18 ) ) ;
F_18 ( V_3 , & V_3 -> V_59 ) ;
V_48 = V_5 -> V_48 ;
V_7 -> V_60 = ( unsigned int * ) V_3 -> V_59 . V_61 ;
V_7 -> V_62 = V_13 -> V_63 -> V_64 ( V_13 , V_48 ,
V_7 -> V_10 * V_7 -> V_11 ,
V_7 -> V_10 ,
V_3 -> V_43 == V_44 ?
V_46 : V_52 ) ;
if ( ! V_7 -> V_62 ) {
F_19 ( & V_13 -> V_65 -> V_63 , L_1 ) ;
return - V_37 ;
}
V_7 -> V_62 -> V_66 = F_1 ;
V_7 -> V_62 -> V_67 = V_3 ;
return 0 ;
}
static int F_20 ( struct V_2 * V_3 )
{
struct V_4 * V_5 = V_3 -> V_5 ;
struct V_6 * V_7 = V_5 -> V_8 ;
if ( V_7 -> V_12 ) {
F_21 ( V_7 -> V_12 ) ;
V_7 -> V_12 = NULL ;
}
return 0 ;
}
static int F_22 ( struct V_2 * V_3 )
{
struct V_19 * V_20 = V_3 -> V_8 ;
struct V_21 * V_22 ;
V_22 = F_6 ( V_20 -> V_29 , V_3 ) ;
return 0 ;
}
static int F_23 ( struct V_2 * V_3 , int V_68 )
{
struct V_4 * V_5 = V_3 -> V_5 ;
struct V_6 * V_7 = V_5 -> V_8 ;
switch ( V_68 ) {
case V_69 :
case V_70 :
case V_71 :
F_24 ( V_7 -> V_62 ) ;
break;
case V_72 :
case V_73 :
case V_74 :
F_25 ( V_7 -> V_12 ) ;
break;
default:
return - V_37 ;
}
return 0 ;
}
static T_2 F_26 ( struct V_2 * V_3 )
{
struct V_4 * V_5 = V_3 -> V_5 ;
struct V_6 * V_7 = V_5 -> V_8 ;
F_27 ( L_2 , V_75 , V_7 -> V_9 ,
F_28 ( V_3 -> V_5 , V_7 -> V_9 ) ) ;
return F_28 ( V_3 -> V_5 , V_7 -> V_9 ) ;
}
static int F_29 ( struct V_2 * V_3 )
{
struct V_4 * V_5 = V_3 -> V_5 ;
struct V_6 * V_7 ;
int V_28 ;
V_7 = F_30 ( sizeof( * V_7 ) , V_76 ) ;
if ( V_7 == NULL )
return - V_77 ;
V_5 -> V_8 = V_7 ;
V_28 = F_31 ( V_3 -> V_5 ,
V_78 ) ;
if ( V_28 < 0 ) {
F_32 ( V_7 ) ;
return V_28 ;
}
F_33 ( V_3 , & V_79 ) ;
return 0 ;
}
static int F_34 ( struct V_2 * V_3 )
{
struct V_4 * V_5 = V_3 -> V_5 ;
struct V_6 * V_7 = V_5 -> V_8 ;
F_32 ( V_7 ) ;
return 0 ;
}
static int T_3 F_35 ( struct V_80 * V_81 )
{
struct V_82 * V_83 = F_36 ( V_81 ) ;
V_83 -> V_84 . V_51 = 6 ;
V_83 -> V_85 . V_51 = 4 ;
return F_37 ( & V_81 -> V_65 , & V_86 ) ;
}
static int T_4 F_38 ( struct V_80 * V_81 )
{
F_39 ( & V_81 -> V_65 ) ;
return 0 ;
}
static int T_5 F_40 ( void )
{
return F_41 ( & V_87 ) ;
}
static void T_6 F_42 ( void )
{
F_43 ( & V_87 ) ;
}
