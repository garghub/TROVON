static int F_1 ( struct V_1 * V_2 , T_1 V_3 , T_1 V_4 )
{
return F_2 ( V_2 -> V_5 , V_3 , V_4 ) ;
}
static int F_3 ( struct V_1 * V_2 , T_1 V_3 , T_1 V_6 , T_1 V_4 )
{
int V_7 ;
T_1 V_8 ;
V_7 = F_4 ( V_2 -> V_5 , V_3 ) ;
if ( V_7 < 0 ) {
F_5 ( V_2 -> V_9 , L_1 , V_3 ) ;
return V_7 ;
}
V_8 = ( T_1 ) V_7 ;
V_8 &= ~ V_6 ;
V_8 |= V_4 & V_6 ;
return F_1 ( V_2 , V_3 , V_8 ) ;
}
static bool F_6 ( struct V_1 * V_2 , T_1 V_10 )
{
T_1 V_11 , V_12 ;
switch ( V_2 -> V_13 ) {
case V_14 :
case V_15 :
case V_16 :
case V_17 :
V_11 = V_18 ;
V_12 = V_19 ;
break;
case V_20 :
V_11 = V_21 ;
V_12 = V_22 ;
break;
case V_23 :
V_11 = V_24 ;
V_12 = V_25 ;
break;
default:
return false ;
}
return ( V_10 >= V_11 && V_10 <= V_12 ) ;
}
static int F_7 ( struct V_1 * V_2 )
{
return F_3 ( V_2 , V_26 , V_27 ,
V_28 ) ;
}
static int F_8 ( struct V_1 * V_2 )
{
return F_3 ( V_2 , V_26 , V_27 ,
V_29 ) ;
}
static int F_9 ( struct V_1 * V_2 )
{
T_1 V_30 , V_10 ;
int V_31 , V_7 ;
struct V_32 * V_33 = V_2 -> V_34 ;
switch ( V_2 -> V_13 ) {
case V_14 ... V_20 :
V_2 -> V_35 = & V_36 ;
break;
case V_23 :
V_2 -> V_35 = & V_37 ;
break;
default:
return - V_38 ;
}
if ( V_2 -> V_35 -> V_39 ) {
V_7 = V_2 -> V_35 -> V_39 ( V_2 ) ;
if ( V_7 ) {
F_5 ( V_2 -> V_9 , L_2 , V_7 ) ;
goto V_40;
}
}
V_30 = V_33 -> V_41 ;
V_7 = F_1 ( V_2 , V_2 -> V_35 -> V_42 , V_30 ) ;
if ( V_7 )
goto V_40;
V_30 = V_33 -> V_43 ;
V_7 = F_1 ( V_2 , V_2 -> V_35 -> V_44 , V_30 ) ;
if ( V_7 )
goto V_40;
if ( V_33 -> V_45 && V_33 -> V_46 ) {
for ( V_31 = 0 ; V_31 < V_33 -> V_46 ; V_31 ++ ) {
V_10 = V_33 -> V_47 [ V_31 ] . V_10 ;
V_30 = V_33 -> V_47 [ V_31 ] . V_30 ;
if ( ! F_6 ( V_2 , V_10 ) )
continue;
V_7 = F_1 ( V_2 , V_10 , V_30 ) ;
if ( V_7 )
goto V_40;
}
}
if ( V_2 -> V_35 -> V_48 ) {
V_7 = V_2 -> V_35 -> V_48 ( V_2 ) ;
if ( V_7 ) {
F_5 ( V_2 -> V_9 , L_3 , V_7 ) ;
goto V_40;
}
}
return 0 ;
V_40:
return V_7 ;
}
static void F_10 ( struct V_1 * V_2 , int V_49 , int V_50 )
{
unsigned int V_51 = V_2 -> V_34 -> V_52 ;
unsigned int V_53 = V_49 * V_51 / V_50 ;
struct V_54 * V_55 ;
if ( ! V_2 -> V_55 ) {
V_55 = F_11 ( V_2 -> V_9 , V_2 -> V_56 ) ;
if ( F_12 ( V_55 ) )
return;
V_2 -> V_55 = V_55 ;
}
F_13 ( V_2 -> V_55 , V_53 , V_51 ) ;
if ( V_53 )
F_14 ( V_2 -> V_55 ) ;
else
F_15 ( V_2 -> V_55 ) ;
}
static int F_16 ( struct V_57 * V_58 )
{
struct V_1 * V_2 = F_17 ( V_58 ) ;
enum V_59 V_60 = V_2 -> V_34 -> V_60 ;
if ( V_58 -> V_61 . V_62 & V_63 )
V_58 -> V_61 . V_64 = 0 ;
if ( V_60 == V_65 ) {
int V_49 = V_58 -> V_61 . V_64 ;
int V_50 = V_58 -> V_61 . V_66 ;
F_10 ( V_2 , V_49 , V_50 ) ;
} else if ( V_60 == V_67 ) {
T_1 V_30 = V_58 -> V_61 . V_64 ;
F_1 ( V_2 , V_2 -> V_35 -> V_42 , V_30 ) ;
}
return 0 ;
}
static int F_18 ( struct V_57 * V_58 )
{
return V_58 -> V_61 . V_64 ;
}
static int F_19 ( struct V_1 * V_2 )
{
struct V_57 * V_58 ;
struct V_68 V_61 ;
struct V_32 * V_34 = V_2 -> V_34 ;
char * V_69 = V_34 -> V_69 ? : V_70 ;
V_61 . type = V_71 ;
V_61 . V_66 = V_72 ;
if ( V_34 -> V_41 > V_61 . V_66 )
V_34 -> V_41 = V_61 . V_66 ;
V_61 . V_64 = V_34 -> V_41 ;
V_58 = F_20 ( V_69 , V_2 -> V_9 , V_2 ,
& V_73 , & V_61 ) ;
if ( F_12 ( V_58 ) )
return F_21 ( V_58 ) ;
V_2 -> V_58 = V_58 ;
return 0 ;
}
static void F_22 ( struct V_1 * V_2 )
{
if ( V_2 -> V_58 )
F_23 ( V_2 -> V_58 ) ;
}
static T_2 F_24 ( struct V_74 * V_9 ,
struct V_75 * V_76 , char * V_77 )
{
struct V_1 * V_2 = F_25 ( V_9 ) ;
return F_26 ( V_77 , V_78 , L_4 , V_2 -> V_56 ) ;
}
static T_2 F_27 ( struct V_74 * V_9 ,
struct V_75 * V_76 , char * V_77 )
{
struct V_1 * V_2 = F_25 ( V_9 ) ;
enum V_59 V_60 = V_2 -> V_34 -> V_60 ;
char * V_79 = NULL ;
if ( V_60 == V_65 )
V_79 = L_5 ;
else if ( V_60 == V_67 )
V_79 = L_6 ;
return F_26 ( V_77 , V_78 , L_4 , V_79 ) ;
}
static int F_28 ( struct V_80 * V_81 , const struct V_82 * V_83 )
{
struct V_1 * V_2 ;
struct V_32 * V_34 = V_81 -> V_9 . V_84 ;
enum V_59 V_60 ;
int V_7 ;
if ( ! V_34 ) {
F_5 ( & V_81 -> V_9 , L_7 ) ;
return - V_38 ;
}
if ( ! F_29 ( V_81 -> V_85 , V_86 ) )
return - V_87 ;
V_2 = F_30 ( & V_81 -> V_9 , sizeof( struct V_1 ) , V_88 ) ;
if ( ! V_2 )
return - V_89 ;
V_60 = V_34 -> V_60 ;
V_2 -> V_5 = V_81 ;
V_2 -> V_9 = & V_81 -> V_9 ;
V_2 -> V_34 = V_34 ;
V_2 -> V_56 = V_83 -> V_69 ;
V_2 -> V_13 = V_83 -> V_90 ;
F_31 ( V_81 , V_2 ) ;
V_7 = F_9 ( V_2 ) ;
if ( V_7 ) {
F_5 ( V_2 -> V_9 , L_8 , V_7 ) ;
goto V_91;
}
V_7 = F_19 ( V_2 ) ;
if ( V_7 ) {
F_5 ( V_2 -> V_9 ,
L_9 , V_7 ) ;
goto V_91;
}
V_7 = F_32 ( & V_2 -> V_9 -> V_92 , & V_93 ) ;
if ( V_7 ) {
F_5 ( V_2 -> V_9 , L_10 , V_7 ) ;
goto V_94;
}
F_33 ( V_2 -> V_58 ) ;
return 0 ;
V_94:
F_22 ( V_2 ) ;
V_91:
return V_7 ;
}
static int F_34 ( struct V_80 * V_81 )
{
struct V_1 * V_2 = F_35 ( V_81 ) ;
V_2 -> V_58 -> V_61 . V_64 = 0 ;
F_33 ( V_2 -> V_58 ) ;
F_36 ( & V_2 -> V_9 -> V_92 , & V_93 ) ;
F_22 ( V_2 ) ;
return 0 ;
}
