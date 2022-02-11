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
case V_26 :
V_11 = V_27 ;
V_12 = V_28 ;
break;
default:
return false ;
}
return V_10 >= V_11 && V_10 <= V_12 ;
}
static int F_7 ( struct V_1 * V_2 )
{
return F_3 ( V_2 , V_29 , V_30 ,
V_31 ) ;
}
static int F_8 ( struct V_1 * V_2 )
{
return F_3 ( V_2 , V_29 , V_30 ,
V_32 ) ;
}
static int F_9 ( struct V_1 * V_2 )
{
T_1 V_33 , V_10 ;
int V_34 , V_7 ;
struct V_35 * V_36 = V_2 -> V_37 ;
switch ( V_2 -> V_13 ) {
case V_14 :
case V_15 :
case V_16 :
case V_17 :
case V_20 :
V_2 -> V_38 = & V_39 ;
break;
case V_23 :
case V_26 :
V_2 -> V_38 = & V_40 ;
break;
default:
return - V_41 ;
}
if ( V_2 -> V_38 -> V_42 ) {
V_7 = V_2 -> V_38 -> V_42 ( V_2 ) ;
if ( V_7 ) {
F_5 ( V_2 -> V_9 , L_2 , V_7 ) ;
goto V_43;
}
}
V_33 = V_36 -> V_44 ;
V_7 = F_1 ( V_2 , V_2 -> V_38 -> V_45 , V_33 ) ;
if ( V_7 )
goto V_43;
V_33 = V_36 -> V_46 ;
V_7 = F_1 ( V_2 , V_2 -> V_38 -> V_47 , V_33 ) ;
if ( V_7 )
goto V_43;
if ( V_36 -> V_48 > 0 ) {
for ( V_34 = 0 ; V_34 < V_36 -> V_48 ; V_34 ++ ) {
V_10 = V_36 -> V_49 [ V_34 ] . V_10 ;
V_33 = V_36 -> V_49 [ V_34 ] . V_33 ;
if ( ! F_6 ( V_2 , V_10 ) )
continue;
V_7 = F_1 ( V_2 , V_10 , V_33 ) ;
if ( V_7 )
goto V_43;
}
}
if ( V_2 -> V_38 -> V_50 ) {
V_7 = V_2 -> V_38 -> V_50 ( V_2 ) ;
if ( V_7 ) {
F_5 ( V_2 -> V_9 , L_3 , V_7 ) ;
goto V_43;
}
}
return 0 ;
V_43:
return V_7 ;
}
static void F_10 ( struct V_1 * V_2 , int V_51 , int V_52 )
{
unsigned int V_53 = V_2 -> V_37 -> V_54 ;
unsigned int V_55 = V_51 * V_53 / V_52 ;
struct V_56 * V_57 ;
if ( ! V_2 -> V_57 ) {
V_57 = F_11 ( V_2 -> V_9 , V_2 -> V_58 ) ;
if ( F_12 ( V_57 ) )
return;
V_2 -> V_57 = V_57 ;
}
F_13 ( V_2 -> V_57 , V_55 , V_53 ) ;
if ( V_55 )
F_14 ( V_2 -> V_57 ) ;
else
F_15 ( V_2 -> V_57 ) ;
}
static int F_16 ( struct V_59 * V_60 )
{
struct V_1 * V_2 = F_17 ( V_60 ) ;
int V_61 = V_60 -> V_62 . V_61 ;
if ( V_60 -> V_62 . V_63 & ( V_64 | V_65 ) )
V_61 = 0 ;
if ( V_2 -> V_66 == V_67 )
F_10 ( V_2 , V_61 , V_60 -> V_62 . V_68 ) ;
else if ( V_2 -> V_66 == V_69 )
F_1 ( V_2 , V_2 -> V_38 -> V_45 , ( T_1 ) V_61 ) ;
return 0 ;
}
static int F_18 ( struct V_1 * V_2 )
{
struct V_59 * V_60 ;
struct V_70 V_62 ;
struct V_35 * V_37 = V_2 -> V_37 ;
const char * V_71 = V_37 -> V_71 ? : V_72 ;
V_62 . type = V_73 ;
V_62 . V_68 = V_74 ;
if ( V_37 -> V_44 > V_62 . V_68 )
V_37 -> V_44 = V_62 . V_68 ;
V_62 . V_61 = V_37 -> V_44 ;
V_60 = F_19 ( V_2 -> V_9 , V_71 , V_2 -> V_9 , V_2 ,
& V_75 , & V_62 ) ;
if ( F_12 ( V_60 ) )
return F_20 ( V_60 ) ;
V_2 -> V_60 = V_60 ;
return 0 ;
}
static T_2 F_21 ( struct V_76 * V_9 ,
struct V_77 * V_78 , char * V_79 )
{
struct V_1 * V_2 = F_22 ( V_9 ) ;
return F_23 ( V_79 , V_80 , L_4 , V_2 -> V_58 ) ;
}
static T_2 F_24 ( struct V_76 * V_9 ,
struct V_77 * V_78 , char * V_79 )
{
struct V_1 * V_2 = F_22 ( V_9 ) ;
char * V_81 = NULL ;
if ( V_2 -> V_66 == V_67 )
V_81 = L_5 ;
else if ( V_2 -> V_66 == V_69 )
V_81 = L_6 ;
return F_23 ( V_79 , V_80 , L_4 , V_81 ) ;
}
static int F_25 ( struct V_1 * V_2 )
{
struct V_76 * V_9 = V_2 -> V_9 ;
struct V_82 * V_83 = V_9 -> V_84 ;
struct V_35 * V_37 ;
int V_85 ;
if ( ! V_83 ) {
F_5 ( V_9 , L_7 ) ;
return - V_41 ;
}
V_37 = F_26 ( V_9 , sizeof( * V_37 ) , V_86 ) ;
if ( ! V_37 )
return - V_87 ;
F_27 ( V_83 , L_8 , & V_37 -> V_71 ) ;
F_28 ( V_83 , L_9 , & V_37 -> V_46 ) ;
F_28 ( V_83 , L_10 , & V_37 -> V_44 ) ;
F_29 ( V_83 , L_11 , & V_37 -> V_54 ) ;
V_85 = F_30 ( V_83 ) ;
if ( V_85 > 0 ) {
struct V_88 * V_89 ;
struct V_82 * V_90 ;
int V_34 = 0 ;
V_89 = F_26 ( V_9 , sizeof( * V_89 ) * V_85 , V_86 ) ;
if ( ! V_89 )
return - V_87 ;
F_31 (node, child) {
F_28 ( V_90 , L_12 , & V_89 [ V_34 ] . V_10 ) ;
F_28 ( V_90 , L_13 , & V_89 [ V_34 ] . V_33 ) ;
V_34 ++ ;
}
V_37 -> V_48 = V_85 ;
V_37 -> V_49 = & V_89 [ 0 ] ;
}
V_2 -> V_37 = V_37 ;
return 0 ;
}
static int F_25 ( struct V_1 * V_2 )
{
return - V_41 ;
}
static int F_32 ( struct V_91 * V_92 , const struct V_93 * V_94 )
{
struct V_1 * V_2 ;
int V_7 ;
if ( ! F_33 ( V_92 -> V_95 , V_96 ) )
return - V_97 ;
V_2 = F_26 ( & V_92 -> V_9 , sizeof( struct V_1 ) , V_86 ) ;
if ( ! V_2 )
return - V_87 ;
V_2 -> V_5 = V_92 ;
V_2 -> V_9 = & V_92 -> V_9 ;
V_2 -> V_58 = V_94 -> V_71 ;
V_2 -> V_13 = V_94 -> V_98 ;
V_2 -> V_37 = F_34 ( & V_92 -> V_9 ) ;
if ( ! V_2 -> V_37 ) {
V_7 = F_25 ( V_2 ) ;
if ( V_7 < 0 )
return V_7 ;
}
if ( V_2 -> V_37 -> V_54 > 0 )
V_2 -> V_66 = V_67 ;
else
V_2 -> V_66 = V_69 ;
V_2 -> V_99 = F_35 ( V_2 -> V_9 , L_14 ) ;
if ( F_12 ( V_2 -> V_99 ) ) {
if ( F_20 ( V_2 -> V_99 ) == - V_100 )
return - V_100 ;
V_2 -> V_99 = NULL ;
}
if ( V_2 -> V_99 ) {
V_7 = F_36 ( V_2 -> V_99 ) ;
if ( V_7 < 0 ) {
F_5 ( & V_92 -> V_9 , L_15 , V_7 ) ;
return V_7 ;
}
}
F_37 ( V_92 , V_2 ) ;
V_7 = F_9 ( V_2 ) ;
if ( V_7 ) {
F_5 ( V_2 -> V_9 , L_16 , V_7 ) ;
return V_7 ;
}
V_7 = F_18 ( V_2 ) ;
if ( V_7 ) {
F_5 ( V_2 -> V_9 ,
L_17 , V_7 ) ;
return V_7 ;
}
V_7 = F_38 ( & V_2 -> V_9 -> V_101 , & V_102 ) ;
if ( V_7 ) {
F_5 ( V_2 -> V_9 , L_18 , V_7 ) ;
return V_7 ;
}
F_39 ( V_2 -> V_60 ) ;
return 0 ;
}
static int F_40 ( struct V_91 * V_92 )
{
struct V_1 * V_2 = F_41 ( V_92 ) ;
V_2 -> V_60 -> V_62 . V_61 = 0 ;
F_39 ( V_2 -> V_60 ) ;
if ( V_2 -> V_99 )
F_42 ( V_2 -> V_99 ) ;
F_43 ( & V_2 -> V_9 -> V_101 , & V_102 ) ;
return 0 ;
}
