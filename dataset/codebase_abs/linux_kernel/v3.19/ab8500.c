static int F_1 ( struct V_1 * V_2 )
{
int V_3 ;
struct V_4 * V_5 = F_2 ( V_2 ) ;
if ( V_5 == NULL ) {
F_3 ( F_4 ( V_2 ) , L_1 ) ;
return - V_6 ;
}
V_3 = F_5 ( V_5 -> V_7 ,
V_5 -> V_8 , V_5 -> V_9 ,
V_5 -> V_10 , V_5 -> V_11 ) ;
if ( V_3 < 0 ) {
F_3 ( F_4 ( V_2 ) ,
L_2 ) ;
return V_3 ;
}
F_6 ( F_4 ( V_2 ) ,
L_3 ,
V_5 -> V_12 . V_13 , V_5 -> V_8 , V_5 -> V_9 ,
V_5 -> V_10 , V_5 -> V_11 ) ;
return V_3 ;
}
static int F_7 ( struct V_1 * V_2 )
{
int V_3 ;
struct V_4 * V_5 = F_2 ( V_2 ) ;
if ( V_5 == NULL ) {
F_3 ( F_4 ( V_2 ) , L_1 ) ;
return - V_6 ;
}
V_3 = F_5 ( V_5 -> V_7 ,
V_5 -> V_8 , V_5 -> V_9 ,
V_5 -> V_10 , 0x0 ) ;
if ( V_3 < 0 ) {
F_3 ( F_4 ( V_2 ) ,
L_4 ) ;
return V_3 ;
}
F_6 ( F_4 ( V_2 ) ,
L_5 ,
V_5 -> V_12 . V_13 , V_5 -> V_8 , V_5 -> V_9 ,
V_5 -> V_10 , 0x0 ) ;
return V_3 ;
}
static int F_8 ( struct V_1 * V_2 )
{
int V_3 ;
struct V_4 * V_5 = F_2 ( V_2 ) ;
T_1 V_14 ;
if ( V_5 == NULL ) {
F_3 ( F_4 ( V_2 ) , L_1 ) ;
return - V_6 ;
}
V_3 = F_9 ( V_5 -> V_7 ,
V_5 -> V_8 , V_5 -> V_9 , & V_14 ) ;
if ( V_3 < 0 ) {
F_3 ( F_4 ( V_2 ) ,
L_6 , V_5 -> V_9 ) ;
return V_3 ;
}
F_6 ( F_4 ( V_2 ) ,
L_7
L_8 ,
V_5 -> V_12 . V_13 , V_5 -> V_8 , V_5 -> V_9 ,
V_5 -> V_10 , V_14 ) ;
if ( V_14 & V_5 -> V_10 )
return 1 ;
else
return 0 ;
}
static unsigned int F_10 (
struct V_1 * V_2 , int V_15 ,
int V_16 , int V_17 )
{
unsigned int V_18 ;
struct V_4 * V_5 = F_2 ( V_2 ) ;
if ( V_5 == NULL ) {
F_3 ( F_4 ( V_2 ) , L_1 ) ;
return - V_6 ;
}
if ( V_17 <= V_5 -> V_19 )
V_18 = V_20 ;
else
V_18 = V_21 ;
return V_18 ;
}
static int F_11 ( struct V_1 * V_2 ,
unsigned int V_18 )
{
int V_3 = 0 ;
T_1 V_22 , V_23 , V_24 , V_25 ;
bool V_26 = false ;
struct V_4 * V_5 = F_2 ( V_2 ) ;
if ( V_5 == NULL ) {
F_3 ( F_4 ( V_2 ) , L_1 ) ;
return - V_6 ;
}
if ( V_5 -> V_27 ) {
V_22 = V_5 -> V_28 ;
V_23 = V_5 -> V_29 ;
V_24 = V_5 -> V_27 ;
} else {
V_22 = V_5 -> V_8 ;
V_23 = V_5 -> V_9 ;
V_24 = V_5 -> V_10 ;
}
if ( V_5 -> V_30 )
F_12 ( & V_31 ) ;
switch ( V_18 ) {
case V_21 :
if ( V_5 -> V_30 )
V_26 = false ;
if ( V_5 -> V_27 )
V_25 = V_5 -> V_32 ;
else
V_25 = V_5 -> V_33 ;
break;
case V_20 :
if ( V_5 -> V_30 ) {
struct V_4 * V_34 ;
V_34 = V_5 -> V_30 -> V_34 ;
if ( ! V_34 -> V_30 -> V_26 ) {
V_5 -> V_30 -> V_26 = true ;
goto V_35;
}
V_26 = true ;
}
if ( V_5 -> V_27 )
V_25 = V_5 -> V_36 ;
else
V_25 = V_5 -> V_37 ;
break;
default:
V_3 = - V_6 ;
goto V_35;
}
if ( V_5 -> V_27 || F_8 ( V_2 ) ) {
V_3 = F_5 ( V_5 -> V_7 ,
V_22 , V_23 , V_24 , V_25 ) ;
if ( V_3 < 0 ) {
F_3 ( F_4 ( V_2 ) ,
L_9 ) ;
goto V_35;
}
F_6 ( F_4 ( V_2 ) ,
L_10
L_11 ,
V_5 -> V_12 . V_13 , V_22 , V_23 ,
V_24 , V_25 ) ;
}
if ( ! V_5 -> V_27 )
V_5 -> V_11 = V_25 ;
if ( V_5 -> V_30 )
V_5 -> V_30 -> V_26 = V_26 ;
V_35:
if ( V_5 -> V_30 )
F_13 ( & V_31 ) ;
return V_3 ;
}
static unsigned int F_14 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
int V_3 ;
T_1 V_25 ;
T_1 V_38 ;
T_1 V_39 ;
if ( V_5 == NULL ) {
F_3 ( F_4 ( V_2 ) , L_1 ) ;
return - V_6 ;
}
if ( V_5 -> V_30 ) {
if ( V_5 -> V_30 -> V_26 )
return V_20 ;
else
return V_21 ;
}
if ( V_5 -> V_27 ) {
V_3 = F_9 ( V_5 -> V_7 ,
V_5 -> V_28 , V_5 -> V_29 , & V_25 ) ;
V_25 = V_25 & V_5 -> V_27 ;
V_38 = V_5 -> V_32 ;
V_39 = V_5 -> V_36 ;
} else {
V_25 = V_5 -> V_11 ;
V_38 = V_5 -> V_33 ;
V_39 = V_5 -> V_37 ;
}
if ( V_25 == V_38 )
V_3 = V_21 ;
else if ( V_25 == V_39 )
V_3 = V_20 ;
else
V_3 = - V_6 ;
return V_3 ;
}
static int F_15 ( struct V_1 * V_2 )
{
int V_3 , V_40 ;
struct V_4 * V_5 = F_2 ( V_2 ) ;
T_1 V_14 ;
if ( V_5 == NULL ) {
F_3 ( F_4 ( V_2 ) , L_1 ) ;
return - V_6 ;
}
V_40 = F_16 ( V_5 -> V_41 ) - 1 ;
V_3 = F_9 ( V_5 -> V_7 ,
V_5 -> V_42 , V_5 -> V_43 , & V_14 ) ;
if ( V_3 < 0 ) {
F_3 ( F_4 ( V_2 ) ,
L_12 ) ;
return V_3 ;
}
F_6 ( F_4 ( V_2 ) ,
L_13
L_14 ,
V_5 -> V_12 . V_13 , V_5 -> V_42 ,
V_5 -> V_43 , V_5 -> V_41 ,
V_40 , V_14 ) ;
return ( V_14 & V_5 -> V_41 ) >> V_40 ;
}
static int F_17 ( struct V_1 * V_2 )
{
int V_3 , V_40 ;
struct V_4 * V_5 = F_2 ( V_2 ) ;
T_1 V_14 , V_44 ;
if ( V_5 == NULL ) {
F_3 ( F_4 ( V_2 ) , L_1 ) ;
return - V_6 ;
}
V_3 = F_9 ( V_5 -> V_7 ,
V_5 -> V_45 . V_42 ,
V_5 -> V_45 . V_43 , & V_44 ) ;
if ( V_3 < 0 ) {
F_3 ( F_4 ( V_2 ) ,
L_15 ) ;
return V_3 ;
}
F_6 ( F_4 ( V_2 ) ,
L_16 ,
V_5 -> V_12 . V_13 , V_5 -> V_45 . V_42 ,
V_5 -> V_45 . V_43 ,
V_5 -> V_45 . V_41 , V_44 ) ;
if ( V_44 & V_5 -> V_45 . V_41 )
return V_5 -> V_45 . V_46 ;
V_3 = F_9 ( V_5 -> V_7 ,
V_5 -> V_42 , V_5 -> V_43 , & V_14 ) ;
if ( V_3 < 0 ) {
F_3 ( F_4 ( V_2 ) ,
L_12 ) ;
return V_3 ;
}
F_6 ( F_4 ( V_2 ) ,
L_17 ,
V_5 -> V_12 . V_13 , V_5 -> V_42 , V_5 -> V_43 ,
V_5 -> V_41 , V_14 ) ;
V_40 = F_16 ( V_5 -> V_41 ) - 1 ;
return ( V_14 & V_5 -> V_41 ) >> V_40 ;
}
static int F_18 ( struct V_1 * V_2 ,
unsigned V_47 )
{
int V_3 , V_40 ;
struct V_4 * V_5 = F_2 ( V_2 ) ;
T_1 V_14 ;
if ( V_5 == NULL ) {
F_3 ( F_4 ( V_2 ) , L_1 ) ;
return - V_6 ;
}
V_40 = F_16 ( V_5 -> V_41 ) - 1 ;
V_14 = ( T_1 ) V_47 << V_40 ;
V_3 = F_5 ( V_5 -> V_7 ,
V_5 -> V_42 , V_5 -> V_43 ,
V_5 -> V_41 , V_14 ) ;
if ( V_3 < 0 )
F_3 ( F_4 ( V_2 ) ,
L_18 ) ;
F_6 ( F_4 ( V_2 ) ,
L_19
L_8 ,
V_5 -> V_12 . V_13 , V_5 -> V_42 , V_5 -> V_43 ,
V_5 -> V_41 , V_14 ) ;
return V_3 ;
}
static int F_19 ( struct V_1 * V_2 ,
unsigned V_47 )
{
int V_3 ;
struct V_4 * V_5 = F_2 ( V_2 ) ;
T_1 V_14 , V_44 ;
if ( V_5 == NULL ) {
F_3 ( F_4 ( V_2 ) , L_1 ) ;
return - V_6 ;
}
if ( V_47 < V_5 -> V_45 . V_46 ) {
int V_40 = F_16 ( V_5 -> V_41 ) - 1 ;
V_14 = ( T_1 ) V_47 << V_40 ;
V_3 = F_5 ( V_5 -> V_7 ,
V_5 -> V_42 , V_5 -> V_43 ,
V_5 -> V_41 , V_14 ) ;
if ( V_3 < 0 ) {
F_3 ( F_4 ( V_2 ) ,
L_18 ) ;
return V_3 ;
}
F_6 ( F_4 ( V_2 ) ,
L_20 ,
V_5 -> V_12 . V_13 , V_5 -> V_42 , V_5 -> V_43 ,
V_5 -> V_41 , V_14 ) ;
V_44 = 0 ;
} else {
V_44 = V_5 -> V_45 . V_41 ;
}
V_3 = F_5 ( V_5 -> V_7 ,
V_5 -> V_45 . V_42 ,
V_5 -> V_45 . V_43 ,
V_5 -> V_45 . V_41 ,
V_44 ) ;
if ( V_3 < 0 ) {
F_3 ( F_4 ( V_2 ) ,
L_21 ) ;
return V_3 ;
}
F_6 ( F_4 ( V_2 ) ,
L_22 ,
V_5 -> V_12 . V_13 , V_5 -> V_45 . V_42 ,
V_5 -> V_45 . V_43 ,
V_5 -> V_45 . V_41 , V_44 ) ;
return 0 ;
}
static void F_20 ( struct V_48 * V_48 )
{
if ( F_21 ( V_48 ) ) {
V_49 . V_5 = V_50 ;
V_49 . V_51 = F_22 ( V_50 ) ;
V_49 . V_52 = V_53 ;
V_49 . V_54 = V_55 ;
V_49 . V_56 = V_57 ;
V_49 . V_58 = F_22 ( V_57 ) ;
} else if ( F_23 ( V_48 ) ) {
V_49 . V_5 = V_59 ;
V_49 . V_51 = F_22 ( V_59 ) ;
V_49 . V_52 = V_60 ;
V_49 . V_54 = V_61 ;
V_49 . V_56 = V_62 ;
V_49 . V_58 = F_22 ( V_62 ) ;
} else if ( F_24 ( V_48 ) ) {
V_49 . V_5 = V_63 ;
V_49 . V_51 = F_22 ( V_63 ) ;
V_49 . V_52 = V_64 ;
V_49 . V_54 = V_65 ;
V_49 . V_56 = V_66 ;
V_49 . V_58 = F_22 ( V_66 ) ;
} else {
V_49 . V_5 = V_4 ;
V_49 . V_51 = F_22 ( V_4 ) ;
V_49 . V_52 = V_67 ;
V_49 . V_54 = V_68 ;
V_49 . V_56 = V_69 ;
V_49 . V_58 = F_22 ( V_69 ) ;
}
}
static int F_25 ( struct V_70 * V_71 ,
struct V_72 * V_73 ,
int V_74 , struct V_75 * V_76 )
{
struct V_48 * V_48 = F_26 ( V_71 -> V_7 . V_77 ) ;
struct V_4 * V_5 = NULL ;
struct V_78 V_79 = { } ;
V_5 = & V_49 . V_5 [ V_74 ] ;
V_5 -> V_7 = & V_71 -> V_7 ;
V_79 . V_7 = & V_71 -> V_7 ;
V_79 . V_73 = V_73 ;
V_79 . V_80 = V_5 ;
V_79 . V_81 = V_76 ;
if ( F_27 ( V_48 ) ) {
if ( V_5 -> V_12 . V_74 == V_82 ) {
V_5 -> V_12 . V_83 =
F_22 ( V_84 ) ;
V_5 -> V_12 . V_85 = V_84 ;
V_5 -> V_41 = 0xf ;
}
}
V_5 -> V_86 = F_28 ( & V_71 -> V_7 , & V_5 -> V_12 ,
& V_79 ) ;
if ( F_29 ( V_5 -> V_86 ) ) {
F_3 ( & V_71 -> V_7 , L_23 ,
V_5 -> V_12 . V_13 ) ;
return F_30 ( V_5 -> V_86 ) ;
}
return 0 ;
}
static int F_31 ( struct V_70 * V_71 )
{
struct V_48 * V_48 = F_26 ( V_71 -> V_7 . V_77 ) ;
struct V_75 * V_76 = V_71 -> V_7 . V_81 ;
struct V_87 * V_56 ;
int V_88 , V_89 ;
if ( ! V_48 ) {
F_3 ( & V_71 -> V_7 , L_24 ) ;
return - V_6 ;
}
F_20 ( V_48 ) ;
V_88 = V_87 ( & V_71 -> V_7 , V_76 ,
V_49 . V_56 ,
V_49 . V_58 ) ;
if ( V_88 < 0 ) {
F_3 ( & V_71 -> V_7 ,
L_25 , V_88 ) ;
return V_88 ;
}
V_56 = V_49 . V_56 ;
for ( V_89 = 0 ; V_89 < V_49 . V_51 ; V_89 ++ ) {
V_88 = F_25 ( V_71 , V_56 [ V_89 ] . V_73 , V_89 ,
V_56 [ V_89 ] . V_81 ) ;
if ( V_88 )
return V_88 ;
}
return 0 ;
}
static int T_2 F_32 ( void )
{
int V_3 ;
V_3 = F_33 ( & V_90 ) ;
if ( V_3 != 0 )
F_34 ( L_26 , V_3 ) ;
return V_3 ;
}
static void T_3 F_35 ( void )
{
F_36 ( & V_90 ) ;
}
