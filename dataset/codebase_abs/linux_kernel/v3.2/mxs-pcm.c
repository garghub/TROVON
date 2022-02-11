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
struct V_15 * V_16 = V_7 -> V_16 ;
if ( ! F_4 ( V_13 ) )
return false ;
if ( V_13 -> V_17 != V_16 -> V_18 )
return false ;
V_13 -> V_19 = & V_7 -> V_20 ;
return true ;
}
static int F_5 ( struct V_2 * V_3 ,
struct V_21 * V_22 )
{
struct V_23 * V_24 = V_3 -> V_8 ;
struct V_4 * V_5 = V_3 -> V_5 ;
struct V_6 * V_7 = V_5 -> V_8 ;
T_1 V_25 ;
V_7 -> V_16 = F_6 ( V_24 -> V_26 , V_3 ) ;
F_7 ( V_25 ) ;
F_8 ( V_27 , V_25 ) ;
V_7 -> V_20 . V_28 = V_7 -> V_16 -> V_28 ;
V_7 -> V_12 = F_9 ( V_25 , F_3 , V_7 ) ;
if ( ! V_7 -> V_12 )
return - V_29 ;
return 0 ;
}
static int F_10 ( struct V_2 * V_3 ,
struct V_21 * V_22 )
{
struct V_4 * V_5 = V_3 -> V_5 ;
struct V_6 * V_7 = V_5 -> V_8 ;
unsigned long V_30 ;
struct V_12 * V_13 ;
int V_31 ;
V_31 = F_5 ( V_3 , V_22 ) ;
if ( V_31 )
return V_31 ;
V_13 = V_7 -> V_12 ;
V_7 -> V_32 = F_11 ( V_22 ) ;
V_7 -> V_11 = F_12 ( V_22 ) ;
V_7 -> V_10 = F_13 ( V_22 ) ;
V_7 -> V_9 = 0 ;
V_7 -> V_33 = V_34 / ( F_14 ( V_22 ) /
F_15 ( V_22 ) ) ;
F_16 ( V_3 , & V_3 -> V_35 ) ;
V_30 = V_5 -> V_30 ;
V_7 -> V_36 = V_3 -> V_35 . V_37 ;
V_7 -> V_38 = V_13 -> V_39 -> V_40 ( V_13 , V_30 ,
V_7 -> V_10 * V_7 -> V_11 ,
V_7 -> V_10 ,
V_3 -> V_41 == V_42 ?
V_43 : V_44 ) ;
if ( ! V_7 -> V_38 ) {
F_17 ( & V_13 -> V_45 -> V_39 , L_1 ) ;
return - V_29 ;
}
V_7 -> V_38 -> V_46 = F_1 ;
V_7 -> V_38 -> V_47 = V_3 ;
return 0 ;
}
static int F_18 ( struct V_2 * V_3 )
{
struct V_4 * V_5 = V_3 -> V_5 ;
struct V_6 * V_7 = V_5 -> V_8 ;
if ( V_7 -> V_12 ) {
F_19 ( V_7 -> V_12 ) ;
V_7 -> V_12 = NULL ;
}
return 0 ;
}
static int F_20 ( struct V_2 * V_3 , int V_48 )
{
struct V_4 * V_5 = V_3 -> V_5 ;
struct V_6 * V_7 = V_5 -> V_8 ;
switch ( V_48 ) {
case V_49 :
case V_50 :
case V_51 :
F_21 ( V_7 -> V_38 ) ;
break;
case V_52 :
case V_53 :
case V_54 :
F_22 ( V_7 -> V_12 ) ;
break;
default:
return - V_29 ;
}
return 0 ;
}
static T_2 F_23 (
struct V_2 * V_3 )
{
struct V_4 * V_5 = V_3 -> V_5 ;
struct V_6 * V_7 = V_5 -> V_8 ;
return F_24 ( V_3 -> V_5 , V_7 -> V_9 ) ;
}
static int F_25 ( struct V_2 * V_3 )
{
struct V_4 * V_5 = V_3 -> V_5 ;
struct V_6 * V_7 ;
int V_31 ;
V_7 = F_26 ( sizeof( * V_7 ) , V_55 ) ;
if ( V_7 == NULL )
return - V_56 ;
V_5 -> V_8 = V_7 ;
V_31 = F_27 ( V_3 -> V_5 ,
V_57 ) ;
if ( V_31 < 0 ) {
F_28 ( V_7 ) ;
return V_31 ;
}
F_29 ( V_3 , & V_58 ) ;
return 0 ;
}
static int F_30 ( struct V_2 * V_3 )
{
struct V_4 * V_5 = V_3 -> V_5 ;
struct V_6 * V_7 = V_5 -> V_8 ;
F_28 ( V_7 ) ;
return 0 ;
}
static int F_31 ( struct V_2 * V_3 ,
struct V_59 * V_60 )
{
struct V_4 * V_5 = V_3 -> V_5 ;
return F_32 ( V_3 -> V_61 -> V_62 -> V_45 , V_60 ,
V_5 -> V_63 ,
V_5 -> V_30 ,
V_5 -> V_64 ) ;
}
static int F_33 ( struct V_65 * V_61 , int V_41 )
{
struct V_2 * V_3 = V_61 -> V_66 [ V_41 ] . V_3 ;
struct V_67 * V_36 = & V_3 -> V_35 ;
T_3 V_32 = V_58 . V_68 ;
V_36 -> V_45 . type = V_69 ;
V_36 -> V_45 . V_45 = V_61 -> V_62 -> V_45 ;
V_36 -> V_8 = NULL ;
V_36 -> V_37 = F_34 ( V_61 -> V_62 -> V_45 , V_32 ,
& V_36 -> V_70 , V_55 ) ;
if ( ! V_36 -> V_37 )
return - V_56 ;
V_36 -> V_71 = V_32 ;
return 0 ;
}
static int F_35 ( struct V_23 * V_24 )
{
struct V_72 * V_62 = V_24 -> V_62 -> V_72 ;
struct V_65 * V_61 = V_24 -> V_61 ;
int V_31 = 0 ;
if ( ! V_62 -> V_45 -> V_73 )
V_62 -> V_45 -> V_73 = & V_74 ;
if ( ! V_62 -> V_45 -> V_75 )
V_62 -> V_45 -> V_75 = F_36 ( 32 ) ;
if ( V_61 -> V_66 [ V_42 ] . V_3 ) {
V_31 = F_33 ( V_61 ,
V_42 ) ;
if ( V_31 )
goto V_76;
}
if ( V_61 -> V_66 [ V_77 ] . V_3 ) {
V_31 = F_33 ( V_61 ,
V_77 ) ;
if ( V_31 )
goto V_76;
}
V_76:
return V_31 ;
}
static void F_37 ( struct V_65 * V_61 )
{
struct V_2 * V_3 ;
struct V_67 * V_36 ;
int V_41 ;
for ( V_41 = 0 ; V_41 < 2 ; V_41 ++ ) {
V_3 = V_61 -> V_66 [ V_41 ] . V_3 ;
if ( ! V_3 )
continue;
V_36 = & V_3 -> V_35 ;
if ( ! V_36 -> V_37 )
continue;
F_38 ( V_61 -> V_62 -> V_45 , V_36 -> V_71 ,
V_36 -> V_37 , V_36 -> V_70 ) ;
V_36 -> V_37 = NULL ;
}
}
static int T_4 F_39 ( struct V_78 * V_79 )
{
return F_40 ( & V_79 -> V_45 , & V_80 ) ;
}
static int T_5 F_41 ( struct V_78 * V_79 )
{
F_42 ( & V_79 -> V_45 ) ;
return 0 ;
}
static int T_6 F_43 ( void )
{
return F_44 ( & V_81 ) ;
}
static void T_7 F_45 ( void )
{
F_46 ( & V_81 ) ;
}
