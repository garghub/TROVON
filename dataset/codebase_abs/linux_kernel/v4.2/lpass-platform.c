static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_5 * V_6 = V_2 -> V_7 ;
int V_8 ;
F_2 ( V_2 , & V_9 ) ;
V_4 -> V_10 = V_9 . V_11 ;
V_8 = F_3 ( V_4 ,
V_12 ) ;
if ( V_8 < 0 ) {
F_4 ( V_6 -> V_13 , L_1 ,
V_14 , V_8 ) ;
return - V_15 ;
}
F_5 ( V_2 , & V_2 -> V_16 ) ;
return 0 ;
}
static int F_6 ( struct V_1 * V_2 ,
struct V_17 * V_18 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
struct V_19 * V_20 = F_7 ( V_6 ) ;
struct V_21 * V_22 =
F_8 ( V_6 -> V_23 ) ;
struct V_24 * V_25 = V_22 -> V_26 ;
T_1 V_27 = F_9 ( V_18 ) ;
unsigned int V_28 = F_10 ( V_18 ) ;
unsigned int V_29 ;
int V_30 ;
int V_8 , V_31 = V_20 -> V_32 + V_25 -> V_33 ;
V_30 = F_11 ( V_27 ) ;
if ( V_30 < 0 ) {
F_4 ( V_6 -> V_13 , L_2 ,
V_14 , V_30 ) ;
return V_30 ;
}
V_29 = V_34 |
F_12 ( V_31 ) |
V_35 ;
switch ( V_30 ) {
case 16 :
switch ( V_28 ) {
case 1 :
case 2 :
V_29 |= V_36 ;
break;
case 4 :
V_29 |= V_37 ;
break;
case 6 :
V_29 |= V_38 ;
break;
case 8 :
V_29 |= V_39 ;
break;
default:
F_4 ( V_6 -> V_13 , L_3 ,
V_14 , V_30 , V_28 ) ;
return - V_15 ;
}
break;
case 24 :
case 32 :
switch ( V_28 ) {
case 1 :
V_29 |= V_36 ;
break;
case 2 :
V_29 |= V_37 ;
break;
case 4 :
V_29 |= V_39 ;
break;
case 6 :
V_29 |= V_40 ;
break;
case 8 :
V_29 |= V_41 ;
break;
default:
F_4 ( V_6 -> V_13 , L_3 ,
V_14 , V_30 , V_28 ) ;
return - V_15 ;
}
break;
default:
F_4 ( V_6 -> V_13 , L_3 ,
V_14 , V_30 , V_28 ) ;
return - V_15 ;
}
V_8 = F_13 ( V_22 -> V_42 ,
F_14 ( V_25 , V_20 -> V_43 ) , V_29 ) ;
if ( V_8 ) {
F_4 ( V_6 -> V_13 , L_4 ,
V_14 , V_8 ) ;
return V_8 ;
}
return 0 ;
}
static int F_15 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
struct V_19 * V_20 = F_7 ( V_6 ) ;
struct V_21 * V_22 =
F_8 ( V_6 -> V_23 ) ;
struct V_24 * V_25 = V_22 -> V_26 ;
int V_8 ;
V_8 = F_13 ( V_22 -> V_42 ,
F_14 ( V_25 , V_20 -> V_43 ) , 0 ) ;
if ( V_8 )
F_4 ( V_6 -> V_13 , L_4 ,
V_14 , V_8 ) ;
return V_8 ;
}
static int F_16 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_5 * V_6 = V_2 -> V_7 ;
struct V_19 * V_20 = F_7 ( V_6 ) ;
struct V_21 * V_22 =
F_8 ( V_6 -> V_23 ) ;
struct V_24 * V_25 = V_22 -> V_26 ;
int V_8 , V_44 = V_20 -> V_43 ;
V_8 = F_13 ( V_22 -> V_42 ,
F_17 ( V_25 , V_44 ) ,
V_4 -> V_45 ) ;
if ( V_8 ) {
F_4 ( V_6 -> V_13 , L_5 ,
V_14 , V_8 ) ;
return V_8 ;
}
V_8 = F_13 ( V_22 -> V_42 ,
F_18 ( V_25 , V_44 ) ,
( F_19 ( V_2 ) >> 2 ) - 1 ) ;
if ( V_8 ) {
F_4 ( V_6 -> V_13 , L_6 ,
V_14 , V_8 ) ;
return V_8 ;
}
V_8 = F_13 ( V_22 -> V_42 ,
F_20 ( V_25 , V_44 ) ,
( F_21 ( V_2 ) >> 2 ) - 1 ) ;
if ( V_8 ) {
F_4 ( V_6 -> V_13 , L_7 ,
V_14 , V_8 ) ;
return V_8 ;
}
V_8 = F_22 ( V_22 -> V_42 ,
F_14 ( V_25 , V_44 ) ,
V_46 , V_47 ) ;
if ( V_8 ) {
F_4 ( V_6 -> V_13 , L_4 ,
V_14 , V_8 ) ;
return V_8 ;
}
return 0 ;
}
static int F_23 ( struct V_1 * V_2 ,
int V_48 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
struct V_19 * V_20 = F_7 ( V_6 ) ;
struct V_21 * V_22 =
F_8 ( V_6 -> V_23 ) ;
struct V_24 * V_25 = V_22 -> V_26 ;
int V_8 , V_44 = V_20 -> V_43 ;
switch ( V_48 ) {
case V_49 :
case V_50 :
case V_51 :
V_8 = F_13 ( V_22 -> V_42 ,
F_24 ( V_25 , V_52 ) ,
F_25 ( V_44 ) ) ;
if ( V_8 ) {
F_4 ( V_6 -> V_13 , L_8 ,
V_14 , V_8 ) ;
return V_8 ;
}
V_8 = F_22 ( V_22 -> V_42 ,
F_26 ( V_25 , V_52 ) ,
F_25 ( V_44 ) ,
F_25 ( V_44 ) ) ;
if ( V_8 ) {
F_4 ( V_6 -> V_13 , L_9 ,
V_14 , V_8 ) ;
return V_8 ;
}
V_8 = F_22 ( V_22 -> V_42 ,
F_14 ( V_25 , V_44 ) ,
V_46 ,
V_47 ) ;
if ( V_8 ) {
F_4 ( V_6 -> V_13 , L_4 ,
V_14 , V_8 ) ;
return V_8 ;
}
break;
case V_53 :
case V_54 :
case V_55 :
V_8 = F_22 ( V_22 -> V_42 ,
F_14 ( V_25 , V_44 ) ,
V_46 ,
V_56 ) ;
if ( V_8 ) {
F_4 ( V_6 -> V_13 , L_4 ,
V_14 , V_8 ) ;
return V_8 ;
}
V_8 = F_22 ( V_22 -> V_42 ,
F_26 ( V_25 , V_52 ) ,
F_25 ( V_44 ) , 0 ) ;
if ( V_8 ) {
F_4 ( V_6 -> V_13 , L_9 ,
V_14 , V_8 ) ;
return V_8 ;
}
break;
}
return 0 ;
}
static T_2 F_27 (
struct V_1 * V_2 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
struct V_19 * V_20 = F_7 ( V_6 ) ;
struct V_21 * V_22 =
F_8 ( V_6 -> V_23 ) ;
struct V_24 * V_25 = V_22 -> V_26 ;
unsigned int V_57 , V_58 ;
int V_8 , V_44 = V_20 -> V_43 ;
V_8 = F_28 ( V_22 -> V_42 ,
F_17 ( V_25 , V_44 ) , & V_57 ) ;
if ( V_8 ) {
F_4 ( V_6 -> V_13 , L_10 ,
V_14 , V_8 ) ;
return V_8 ;
}
V_8 = F_28 ( V_22 -> V_42 ,
F_29 ( V_25 , V_44 ) , & V_58 ) ;
if ( V_8 ) {
F_4 ( V_6 -> V_13 , L_11 ,
V_14 , V_8 ) ;
return V_8 ;
}
return F_30 ( V_2 -> V_4 , V_58 - V_57 ) ;
}
static int F_31 ( struct V_1 * V_2 ,
struct V_59 * V_60 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
return F_32 ( V_2 -> V_61 -> V_62 -> V_13 , V_60 ,
V_4 -> V_63 , V_4 -> V_45 ,
V_4 -> V_10 ) ;
}
static T_3 F_33 (
struct V_1 * V_2 ,
struct V_21 * V_22 ,
int V_64 , T_4 V_65 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
struct V_24 * V_25 = V_22 -> V_26 ;
T_3 V_8 = V_66 ;
int V_67 ;
if ( V_65 & F_34 ( V_64 ) ) {
V_67 = F_13 ( V_22 -> V_42 ,
F_24 ( V_25 , V_52 ) ,
F_34 ( V_64 ) ) ;
if ( V_67 ) {
F_4 ( V_6 -> V_13 , L_8 ,
V_14 , V_67 ) ;
return V_66 ;
}
F_35 ( V_2 ) ;
V_8 = V_68 ;
}
if ( V_65 & F_36 ( V_64 ) ) {
V_67 = F_13 ( V_22 -> V_42 ,
F_24 ( V_25 , V_52 ) ,
F_36 ( V_64 ) ) ;
if ( V_67 ) {
F_4 ( V_6 -> V_13 , L_8 ,
V_14 , V_67 ) ;
return V_66 ;
}
F_37 ( V_6 -> V_13 , L_12 , V_14 ) ;
F_38 ( V_2 , V_69 ) ;
V_8 = V_68 ;
}
if ( V_65 & F_39 ( V_64 ) ) {
V_67 = F_13 ( V_22 -> V_42 ,
F_24 ( V_25 , V_52 ) ,
F_39 ( V_64 ) ) ;
if ( V_67 ) {
F_4 ( V_6 -> V_13 , L_8 ,
V_14 , V_67 ) ;
return V_66 ;
}
F_4 ( V_6 -> V_13 , L_13 , V_14 ) ;
F_38 ( V_2 , V_70 ) ;
V_8 = V_68 ;
}
return V_8 ;
}
static T_3 F_40 ( int V_71 , void * V_72 )
{
struct V_21 * V_22 = V_72 ;
struct V_24 * V_25 = V_22 -> V_26 ;
unsigned int V_73 ;
int V_67 , V_64 ;
V_67 = F_28 ( V_22 -> V_42 ,
F_41 ( V_25 , V_52 ) , & V_73 ) ;
if ( V_67 ) {
F_42 ( L_14 ,
V_14 , V_67 ) ;
return V_66 ;
}
for ( V_64 = 0 ; V_64 < V_74 ; V_64 ++ ) {
if ( V_73 & F_25 ( V_64 ) && V_22 -> V_2 [ V_64 ] ) {
V_67 = F_33 (
V_22 -> V_2 [ V_64 ] ,
V_22 , V_64 , V_73 ) ;
if ( V_67 != V_68 )
return V_67 ;
}
}
return V_68 ;
}
static int F_43 ( struct V_1 * V_2 ,
struct V_5 * V_6 )
{
struct V_75 * V_76 = & V_2 -> V_16 ;
T_5 V_77 = V_9 . V_11 ;
V_76 -> V_13 . type = V_78 ;
V_76 -> V_13 . V_13 = V_6 -> V_13 ;
V_76 -> V_7 = NULL ;
V_76 -> V_79 = F_44 ( V_6 -> V_13 , V_77 , & V_76 -> V_80 ,
V_81 ) ;
if ( ! V_76 -> V_79 ) {
F_4 ( V_6 -> V_13 , L_15 ,
V_14 ) ;
return - V_82 ;
}
V_76 -> V_83 = V_77 ;
return 0 ;
}
static void F_45 ( struct V_1 * V_2 ,
struct V_5 * V_6 )
{
struct V_75 * V_76 = & V_2 -> V_16 ;
if ( V_76 -> V_79 ) {
F_46 ( V_6 -> V_13 , V_76 -> V_83 , V_76 -> V_79 ,
V_76 -> V_80 ) ;
}
V_76 -> V_79 = NULL ;
}
static int F_47 ( struct V_5 * V_6 )
{
struct V_84 * V_61 = V_6 -> V_61 ;
struct V_1 * V_2 =
V_61 -> V_85 [ V_86 ] . V_2 ;
struct V_87 * V_88 = V_6 -> V_88 ;
struct V_21 * V_22 =
F_8 ( V_6 -> V_23 ) ;
struct V_24 * V_25 = V_22 -> V_26 ;
int V_8 ;
struct V_19 * V_72 ;
V_72 = F_48 ( V_6 -> V_13 , sizeof( * V_72 ) , V_81 ) ;
if ( ! V_72 )
return - V_82 ;
if ( V_25 -> V_89 )
V_72 -> V_43 = V_25 -> V_89 ( V_22 ) ;
if ( F_49 ( V_72 -> V_43 ) )
return V_72 -> V_43 ;
V_22 -> V_2 [ V_72 -> V_43 ] = V_2 ;
V_72 -> V_32 = V_88 -> V_90 -> V_91 ;
F_50 ( V_6 , V_72 ) ;
V_6 -> V_13 -> V_92 = F_51 ( 32 ) ;
V_6 -> V_13 -> V_93 = & V_6 -> V_13 -> V_92 ;
V_8 = F_43 ( V_2 , V_6 ) ;
if ( V_8 )
return V_8 ;
V_8 = F_13 ( V_22 -> V_42 ,
F_14 ( V_25 , V_72 -> V_43 ) , 0 ) ;
if ( V_8 ) {
F_4 ( V_6 -> V_13 , L_4 ,
V_14 , V_8 ) ;
goto V_94;
}
return 0 ;
V_94:
F_45 ( V_2 , V_6 ) ;
return V_8 ;
}
static void F_52 ( struct V_84 * V_61 )
{
struct V_1 * V_2 =
V_61 -> V_85 [ V_86 ] . V_2 ;
struct V_5 * V_6 = V_2 -> V_7 ;
struct V_21 * V_22 =
F_8 ( V_6 -> V_23 ) ;
struct V_19 * V_72 = F_7 ( V_6 ) ;
struct V_24 * V_25 = V_22 -> V_26 ;
V_22 -> V_2 [ V_72 -> V_43 ] = NULL ;
if ( V_25 -> V_95 )
V_25 -> V_95 ( V_22 , V_72 -> V_43 ) ;
F_45 ( V_2 , V_6 ) ;
}
int F_53 ( struct V_96 * V_97 )
{
struct V_21 * V_22 = F_54 ( V_97 ) ;
struct V_24 * V_25 = V_22 -> V_26 ;
int V_8 ;
V_22 -> V_98 = F_55 ( V_97 , L_16 ) ;
if ( V_22 -> V_98 < 0 ) {
F_4 ( & V_97 -> V_13 , L_17 ,
V_14 , V_22 -> V_98 ) ;
return - V_99 ;
}
V_8 = F_13 ( V_22 -> V_42 ,
F_26 ( V_25 , V_52 ) , 0 ) ;
if ( V_8 ) {
F_4 ( & V_97 -> V_13 , L_9 ,
V_14 , V_8 ) ;
return V_8 ;
}
V_8 = F_56 ( & V_97 -> V_13 , V_22 -> V_98 ,
F_40 , V_100 ,
L_16 , V_22 ) ;
if ( V_8 ) {
F_4 ( & V_97 -> V_13 , L_18 ,
V_14 , V_8 ) ;
return V_8 ;
}
return F_57 ( & V_97 -> V_13 ,
& V_101 ) ;
}
