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
if ( V_33 -> V_45 > 0 ) {
for ( V_31 = 0 ; V_31 < V_33 -> V_45 ; V_31 ++ ) {
V_10 = V_33 -> V_46 [ V_31 ] . V_10 ;
V_30 = V_33 -> V_46 [ V_31 ] . V_30 ;
if ( ! F_6 ( V_2 , V_10 ) )
continue;
V_7 = F_1 ( V_2 , V_10 , V_30 ) ;
if ( V_7 )
goto V_40;
}
}
if ( V_2 -> V_35 -> V_47 ) {
V_7 = V_2 -> V_35 -> V_47 ( V_2 ) ;
if ( V_7 ) {
F_5 ( V_2 -> V_9 , L_3 , V_7 ) ;
goto V_40;
}
}
return 0 ;
V_40:
return V_7 ;
}
static void F_10 ( struct V_1 * V_2 , int V_48 , int V_49 )
{
unsigned int V_50 = V_2 -> V_34 -> V_51 ;
unsigned int V_52 = V_48 * V_50 / V_49 ;
struct V_53 * V_54 ;
if ( ! V_2 -> V_54 ) {
V_54 = F_11 ( V_2 -> V_9 , V_2 -> V_55 ) ;
if ( F_12 ( V_54 ) )
return;
V_2 -> V_54 = V_54 ;
}
F_13 ( V_2 -> V_54 , V_52 , V_50 ) ;
if ( V_52 )
F_14 ( V_2 -> V_54 ) ;
else
F_15 ( V_2 -> V_54 ) ;
}
static int F_16 ( struct V_56 * V_57 )
{
struct V_1 * V_2 = F_17 ( V_57 ) ;
if ( V_57 -> V_58 . V_59 & V_60 )
V_57 -> V_58 . V_61 = 0 ;
if ( V_2 -> V_62 == V_63 ) {
int V_48 = V_57 -> V_58 . V_61 ;
int V_49 = V_57 -> V_58 . V_64 ;
F_10 ( V_2 , V_48 , V_49 ) ;
} else if ( V_2 -> V_62 == V_65 ) {
T_1 V_30 = V_57 -> V_58 . V_61 ;
F_1 ( V_2 , V_2 -> V_35 -> V_42 , V_30 ) ;
}
return 0 ;
}
static int F_18 ( struct V_56 * V_57 )
{
return V_57 -> V_58 . V_61 ;
}
static int F_19 ( struct V_1 * V_2 )
{
struct V_56 * V_57 ;
struct V_66 V_58 ;
struct V_32 * V_34 = V_2 -> V_34 ;
const char * V_67 = V_34 -> V_67 ? : V_68 ;
V_58 . type = V_69 ;
V_58 . V_64 = V_70 ;
if ( V_34 -> V_41 > V_58 . V_64 )
V_34 -> V_41 = V_58 . V_64 ;
V_58 . V_61 = V_34 -> V_41 ;
V_57 = F_20 ( V_67 , V_2 -> V_9 , V_2 ,
& V_71 , & V_58 ) ;
if ( F_12 ( V_57 ) )
return F_21 ( V_57 ) ;
V_2 -> V_57 = V_57 ;
return 0 ;
}
static void F_22 ( struct V_1 * V_2 )
{
if ( V_2 -> V_57 )
F_23 ( V_2 -> V_57 ) ;
}
static T_2 F_24 ( struct V_72 * V_9 ,
struct V_73 * V_74 , char * V_75 )
{
struct V_1 * V_2 = F_25 ( V_9 ) ;
return F_26 ( V_75 , V_76 , L_4 , V_2 -> V_55 ) ;
}
static T_2 F_27 ( struct V_72 * V_9 ,
struct V_73 * V_74 , char * V_75 )
{
struct V_1 * V_2 = F_25 ( V_9 ) ;
char * V_77 = NULL ;
if ( V_2 -> V_62 == V_63 )
V_77 = L_5 ;
else if ( V_2 -> V_62 == V_65 )
V_77 = L_6 ;
return F_26 ( V_75 , V_76 , L_4 , V_77 ) ;
}
static int F_28 ( struct V_72 * V_9 , struct V_78 * V_79 )
{
struct V_32 * V_34 ;
int V_80 ;
if ( ! V_79 ) {
F_5 ( V_9 , L_7 ) ;
return - V_38 ;
}
V_34 = F_29 ( V_9 , sizeof( * V_34 ) , V_81 ) ;
if ( ! V_34 )
return - V_82 ;
F_30 ( V_79 , L_8 , & V_34 -> V_67 ) ;
F_31 ( V_79 , L_9 , & V_34 -> V_43 ) ;
F_31 ( V_79 , L_10 , & V_34 -> V_41 ) ;
F_32 ( V_79 , L_11 , & V_34 -> V_51 ) ;
V_80 = F_33 ( V_79 ) ;
if ( V_80 > 0 ) {
struct V_83 * V_84 ;
struct V_78 * V_85 ;
int V_31 = 0 ;
V_84 = F_29 ( V_9 , sizeof( * V_84 ) * V_80 , V_81 ) ;
if ( ! V_84 )
return - V_82 ;
F_34 (node, child) {
F_31 ( V_85 , L_12 , & V_84 [ V_31 ] . V_10 ) ;
F_31 ( V_85 , L_13 , & V_84 [ V_31 ] . V_30 ) ;
V_31 ++ ;
}
V_34 -> V_45 = V_80 ;
V_34 -> V_46 = & V_84 [ 0 ] ;
}
V_9 -> V_86 = V_34 ;
return 0 ;
}
static int F_28 ( struct V_72 * V_9 , struct V_78 * V_79 )
{
return - V_38 ;
}
static int F_35 ( struct V_87 * V_88 , const struct V_89 * V_90 )
{
struct V_1 * V_2 ;
struct V_32 * V_34 = V_88 -> V_9 . V_86 ;
struct V_78 * V_79 = V_88 -> V_9 . V_91 ;
int V_7 ;
if ( ! V_34 ) {
V_7 = F_28 ( & V_88 -> V_9 , V_79 ) ;
if ( V_7 < 0 )
return V_7 ;
V_34 = V_88 -> V_9 . V_86 ;
}
if ( ! F_36 ( V_88 -> V_92 , V_93 ) )
return - V_94 ;
V_2 = F_29 ( & V_88 -> V_9 , sizeof( struct V_1 ) , V_81 ) ;
if ( ! V_2 )
return - V_82 ;
if ( V_34 -> V_51 > 0 )
V_2 -> V_62 = V_63 ;
else
V_2 -> V_62 = V_65 ;
V_2 -> V_5 = V_88 ;
V_2 -> V_9 = & V_88 -> V_9 ;
V_2 -> V_34 = V_34 ;
V_2 -> V_55 = V_90 -> V_67 ;
V_2 -> V_13 = V_90 -> V_95 ;
F_37 ( V_88 , V_2 ) ;
V_7 = F_9 ( V_2 ) ;
if ( V_7 ) {
F_5 ( V_2 -> V_9 , L_14 , V_7 ) ;
goto V_96;
}
V_7 = F_19 ( V_2 ) ;
if ( V_7 ) {
F_5 ( V_2 -> V_9 ,
L_15 , V_7 ) ;
goto V_96;
}
V_7 = F_38 ( & V_2 -> V_9 -> V_97 , & V_98 ) ;
if ( V_7 ) {
F_5 ( V_2 -> V_9 , L_16 , V_7 ) ;
goto V_99;
}
F_39 ( V_2 -> V_57 ) ;
return 0 ;
V_99:
F_22 ( V_2 ) ;
V_96:
return V_7 ;
}
static int F_40 ( struct V_87 * V_88 )
{
struct V_1 * V_2 = F_41 ( V_88 ) ;
V_2 -> V_57 -> V_58 . V_61 = 0 ;
F_39 ( V_2 -> V_57 ) ;
F_42 ( & V_2 -> V_9 -> V_97 , & V_98 ) ;
F_22 ( V_2 ) ;
return 0 ;
}
