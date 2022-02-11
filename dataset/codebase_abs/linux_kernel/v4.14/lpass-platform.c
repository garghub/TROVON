static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_5 * V_6 = V_2 -> V_7 ;
struct V_8 * V_9 = V_6 -> V_9 ;
struct V_10 * V_11 =
F_2 ( V_6 -> V_12 ) ;
struct V_13 * V_14 = V_11 -> V_15 ;
int V_16 , V_17 , V_18 = V_2 -> V_19 ;
struct V_20 * V_21 ;
V_21 = F_3 ( V_6 -> V_22 , sizeof( * V_21 ) , V_23 ) ;
if ( ! V_21 )
return - V_24 ;
V_21 -> V_25 = V_9 -> V_26 -> V_27 ;
V_4 -> V_7 = V_21 ;
V_17 = 0 ;
if ( V_14 -> V_28 )
V_17 = V_14 -> V_28 ( V_11 , V_18 ) ;
else
V_17 = 0 ;
if ( V_17 < 0 )
return V_17 ;
V_11 -> V_2 [ V_17 ] = V_2 ;
V_16 = F_4 ( V_11 -> V_29 ,
F_5 ( V_14 , V_17 , V_18 ) , 0 ) ;
if ( V_16 ) {
F_6 ( V_6 -> V_22 ,
L_1 , V_16 ) ;
return V_16 ;
}
V_21 -> V_17 = V_17 ;
F_7 ( V_2 , & V_30 ) ;
V_4 -> V_31 = V_30 . V_32 ;
V_16 = F_8 ( V_4 ,
V_33 ) ;
if ( V_16 < 0 ) {
F_6 ( V_6 -> V_22 , L_2 ,
V_16 ) ;
return - V_34 ;
}
F_9 ( V_2 , & V_2 -> V_35 ) ;
return 0 ;
}
static int F_10 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_5 * V_6 = V_2 -> V_7 ;
struct V_10 * V_11 =
F_2 ( V_6 -> V_12 ) ;
struct V_13 * V_14 = V_11 -> V_15 ;
struct V_20 * V_21 ;
V_21 = V_4 -> V_7 ;
V_14 = V_11 -> V_15 ;
V_11 -> V_2 [ V_21 -> V_17 ] = NULL ;
if ( V_14 -> V_36 )
V_14 -> V_36 ( V_11 , V_21 -> V_17 ) ;
return 0 ;
}
static int F_11 ( struct V_1 * V_2 ,
struct V_37 * V_38 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
struct V_10 * V_11 =
F_2 ( V_6 -> V_12 ) ;
struct V_3 * V_39 = V_2 -> V_4 ;
struct V_20 * V_40 = V_39 -> V_7 ;
struct V_13 * V_14 = V_11 -> V_15 ;
T_1 V_41 = F_12 ( V_38 ) ;
unsigned int V_42 = F_13 ( V_38 ) ;
unsigned int V_43 ;
int V_44 , V_18 = V_2 -> V_19 ;
int V_45 ;
int V_16 , V_46 = V_40 -> V_25 + V_14 -> V_47 ;
V_44 = V_40 -> V_17 ;
V_45 = F_14 ( V_41 ) ;
if ( V_45 < 0 ) {
F_6 ( V_6 -> V_22 , L_3 ,
V_45 ) ;
return V_45 ;
}
V_43 = V_48 |
F_15 ( V_46 ) |
V_49 ;
switch ( V_45 ) {
case 16 :
switch ( V_42 ) {
case 1 :
case 2 :
V_43 |= V_50 ;
break;
case 4 :
V_43 |= V_51 ;
break;
case 6 :
V_43 |= V_52 ;
break;
case 8 :
V_43 |= V_53 ;
break;
default:
F_6 ( V_6 -> V_22 ,
L_4 ,
V_45 , V_42 ) ;
return - V_34 ;
}
break;
case 24 :
case 32 :
switch ( V_42 ) {
case 1 :
V_43 |= V_50 ;
break;
case 2 :
V_43 |= V_51 ;
break;
case 4 :
V_43 |= V_53 ;
break;
case 6 :
V_43 |= V_54 ;
break;
case 8 :
V_43 |= V_55 ;
break;
default:
F_6 ( V_6 -> V_22 ,
L_4 ,
V_45 , V_42 ) ;
return - V_34 ;
}
break;
default:
F_6 ( V_6 -> V_22 , L_4 ,
V_45 , V_42 ) ;
return - V_34 ;
}
V_16 = F_4 ( V_11 -> V_29 ,
F_5 ( V_14 , V_44 , V_18 ) , V_43 ) ;
if ( V_16 ) {
F_6 ( V_6 -> V_22 , L_1 ,
V_16 ) ;
return V_16 ;
}
return 0 ;
}
static int F_16 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
struct V_10 * V_11 =
F_2 ( V_6 -> V_12 ) ;
struct V_3 * V_39 = V_2 -> V_4 ;
struct V_20 * V_40 = V_39 -> V_7 ;
struct V_13 * V_14 = V_11 -> V_15 ;
unsigned int V_56 ;
int V_16 ;
V_56 = F_5 ( V_14 , V_40 -> V_17 , V_2 -> V_19 ) ;
V_16 = F_4 ( V_11 -> V_29 , V_56 , 0 ) ;
if ( V_16 )
F_6 ( V_6 -> V_22 , L_1 ,
V_16 ) ;
return V_16 ;
}
static int F_17 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_5 * V_6 = V_2 -> V_7 ;
struct V_10 * V_11 =
F_2 ( V_6 -> V_12 ) ;
struct V_3 * V_39 = V_2 -> V_4 ;
struct V_20 * V_40 = V_39 -> V_7 ;
struct V_13 * V_14 = V_11 -> V_15 ;
int V_16 , V_44 , V_18 = V_2 -> V_19 ;
V_44 = V_40 -> V_17 ;
V_16 = F_4 ( V_11 -> V_29 ,
F_18 ( V_14 , V_44 , V_18 ) ,
V_4 -> V_57 ) ;
if ( V_16 ) {
F_6 ( V_6 -> V_22 , L_5 ,
V_16 ) ;
return V_16 ;
}
V_16 = F_4 ( V_11 -> V_29 ,
F_19 ( V_14 , V_44 , V_18 ) ,
( F_20 ( V_2 ) >> 2 ) - 1 ) ;
if ( V_16 ) {
F_6 ( V_6 -> V_22 , L_6 ,
V_16 ) ;
return V_16 ;
}
V_16 = F_4 ( V_11 -> V_29 ,
F_21 ( V_14 , V_44 , V_18 ) ,
( F_22 ( V_2 ) >> 2 ) - 1 ) ;
if ( V_16 ) {
F_6 ( V_6 -> V_22 , L_7 ,
V_16 ) ;
return V_16 ;
}
V_16 = F_23 ( V_11 -> V_29 ,
F_5 ( V_14 , V_44 , V_18 ) ,
V_58 , V_59 ) ;
if ( V_16 ) {
F_6 ( V_6 -> V_22 , L_1 ,
V_16 ) ;
return V_16 ;
}
return 0 ;
}
static int F_24 ( struct V_1 * V_2 ,
int V_60 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
struct V_10 * V_11 =
F_2 ( V_6 -> V_12 ) ;
struct V_3 * V_39 = V_2 -> V_4 ;
struct V_20 * V_40 = V_39 -> V_7 ;
struct V_13 * V_14 = V_11 -> V_15 ;
int V_16 , V_44 , V_18 = V_2 -> V_19 ;
V_44 = V_40 -> V_17 ;
switch ( V_60 ) {
case V_61 :
case V_62 :
case V_63 :
V_16 = F_4 ( V_11 -> V_29 ,
F_25 ( V_14 , V_64 ) ,
F_26 ( V_44 ) ) ;
if ( V_16 ) {
F_6 ( V_6 -> V_22 ,
L_8 , V_16 ) ;
return V_16 ;
}
V_16 = F_23 ( V_11 -> V_29 ,
F_27 ( V_14 , V_64 ) ,
F_26 ( V_44 ) ,
F_26 ( V_44 ) ) ;
if ( V_16 ) {
F_6 ( V_6 -> V_22 ,
L_9 , V_16 ) ;
return V_16 ;
}
V_16 = F_23 ( V_11 -> V_29 ,
F_5 ( V_14 , V_44 , V_18 ) ,
V_58 ,
V_59 ) ;
if ( V_16 ) {
F_6 ( V_6 -> V_22 ,
L_1 , V_16 ) ;
return V_16 ;
}
break;
case V_65 :
case V_66 :
case V_67 :
V_16 = F_23 ( V_11 -> V_29 ,
F_5 ( V_14 , V_44 , V_18 ) ,
V_58 ,
V_68 ) ;
if ( V_16 ) {
F_6 ( V_6 -> V_22 ,
L_1 , V_16 ) ;
return V_16 ;
}
V_16 = F_23 ( V_11 -> V_29 ,
F_27 ( V_14 , V_64 ) ,
F_26 ( V_44 ) , 0 ) ;
if ( V_16 ) {
F_6 ( V_6 -> V_22 ,
L_9 , V_16 ) ;
return V_16 ;
}
break;
}
return 0 ;
}
static T_2 F_28 (
struct V_1 * V_2 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
struct V_10 * V_11 =
F_2 ( V_6 -> V_12 ) ;
struct V_3 * V_39 = V_2 -> V_4 ;
struct V_20 * V_40 = V_39 -> V_7 ;
struct V_13 * V_14 = V_11 -> V_15 ;
unsigned int V_69 , V_70 ;
int V_16 , V_44 , V_18 = V_2 -> V_19 ;
V_44 = V_40 -> V_17 ;
V_16 = F_29 ( V_11 -> V_29 ,
F_18 ( V_14 , V_44 , V_18 ) , & V_69 ) ;
if ( V_16 ) {
F_6 ( V_6 -> V_22 ,
L_10 , V_16 ) ;
return V_16 ;
}
V_16 = F_29 ( V_11 -> V_29 ,
F_30 ( V_14 , V_44 , V_18 ) , & V_70 ) ;
if ( V_16 ) {
F_6 ( V_6 -> V_22 ,
L_11 , V_16 ) ;
return V_16 ;
}
return F_31 ( V_2 -> V_4 , V_70 - V_69 ) ;
}
static int F_32 ( struct V_1 * V_2 ,
struct V_71 * V_72 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
return F_33 ( V_2 -> V_73 -> V_74 -> V_22 , V_72 ,
V_4 -> V_75 , V_4 -> V_57 ,
V_4 -> V_31 ) ;
}
static T_3 F_34 (
struct V_1 * V_2 ,
struct V_10 * V_11 ,
int V_76 , T_4 V_77 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
struct V_13 * V_14 = V_11 -> V_15 ;
T_3 V_16 = V_78 ;
int V_79 ;
if ( V_77 & F_35 ( V_76 ) ) {
V_79 = F_4 ( V_11 -> V_29 ,
F_25 ( V_14 , V_64 ) ,
F_35 ( V_76 ) ) ;
if ( V_79 ) {
F_6 ( V_6 -> V_22 ,
L_8 , V_79 ) ;
return V_78 ;
}
F_36 ( V_2 ) ;
V_16 = V_80 ;
}
if ( V_77 & F_37 ( V_76 ) ) {
V_79 = F_4 ( V_11 -> V_29 ,
F_25 ( V_14 , V_64 ) ,
F_37 ( V_76 ) ) ;
if ( V_79 ) {
F_6 ( V_6 -> V_22 ,
L_8 , V_79 ) ;
return V_78 ;
}
F_38 ( V_6 -> V_22 , L_12 ) ;
F_39 ( V_2 , V_81 ) ;
V_16 = V_80 ;
}
if ( V_77 & F_40 ( V_76 ) ) {
V_79 = F_4 ( V_11 -> V_29 ,
F_25 ( V_14 , V_64 ) ,
F_40 ( V_76 ) ) ;
if ( V_79 ) {
F_6 ( V_6 -> V_22 ,
L_8 , V_79 ) ;
return V_78 ;
}
F_6 ( V_6 -> V_22 , L_13 ) ;
F_39 ( V_2 , V_82 ) ;
V_16 = V_80 ;
}
return V_16 ;
}
static T_3 F_41 ( int V_83 , void * V_21 )
{
struct V_10 * V_11 = V_21 ;
struct V_13 * V_14 = V_11 -> V_15 ;
unsigned int V_84 ;
int V_79 , V_76 ;
V_79 = F_29 ( V_11 -> V_29 ,
F_42 ( V_14 , V_64 ) , & V_84 ) ;
if ( V_79 ) {
F_43 ( L_14 , V_79 ) ;
return V_78 ;
}
for ( V_76 = 0 ; V_76 < V_85 ; V_76 ++ ) {
if ( V_84 & F_26 ( V_76 ) && V_11 -> V_2 [ V_76 ] ) {
V_79 = F_34 (
V_11 -> V_2 [ V_76 ] ,
V_11 , V_76 , V_84 ) ;
if ( V_79 != V_80 )
return V_79 ;
}
}
return V_80 ;
}
static int F_44 ( struct V_5 * V_6 )
{
struct V_86 * V_73 = V_6 -> V_73 ;
struct V_1 * V_87 , * V_88 ;
int V_16 = - V_34 ;
T_5 V_89 = V_30 . V_32 ;
V_87 = V_73 -> V_90 [ V_91 ] . V_2 ;
if ( V_87 ) {
V_16 = F_45 ( V_92 ,
V_6 -> V_12 -> V_22 ,
V_89 , & V_87 -> V_35 ) ;
if ( V_16 ) {
F_6 ( V_6 -> V_22 , L_15 ) ;
return V_16 ;
}
}
V_88 = V_73 -> V_90 [ V_93 ] . V_2 ;
if ( V_88 ) {
V_16 = F_45 ( V_92 ,
V_6 -> V_12 -> V_22 ,
V_89 , & V_88 -> V_35 ) ;
if ( V_16 ) {
F_6 ( V_6 -> V_22 , L_15 ) ;
if ( V_87 )
F_46 ( & V_87 -> V_35 ) ;
return V_16 ;
}
}
return 0 ;
}
static void F_47 ( struct V_86 * V_73 )
{
struct V_1 * V_2 ;
int V_94 ;
for ( V_94 = 0 ; V_94 < F_48 ( V_73 -> V_90 ) ; V_94 ++ ) {
V_2 = V_73 -> V_90 [ V_94 ] . V_2 ;
if ( V_2 ) {
F_46 ( & V_2 -> V_35 ) ;
V_2 -> V_35 . V_95 = NULL ;
V_2 -> V_35 . V_96 = 0 ;
}
}
}
int F_49 ( struct V_97 * V_98 )
{
struct V_10 * V_11 = F_50 ( V_98 ) ;
struct V_13 * V_14 = V_11 -> V_15 ;
int V_16 ;
V_11 -> V_99 = F_51 ( V_98 , L_16 ) ;
if ( V_11 -> V_99 < 0 ) {
F_6 ( & V_98 -> V_22 , L_17 ,
V_11 -> V_99 ) ;
return - V_100 ;
}
V_16 = F_4 ( V_11 -> V_29 ,
F_27 ( V_14 , V_64 ) , 0 ) ;
if ( V_16 ) {
F_6 ( & V_98 -> V_22 , L_9 , V_16 ) ;
return V_16 ;
}
V_16 = F_52 ( & V_98 -> V_22 , V_11 -> V_99 ,
F_41 , V_101 ,
L_16 , V_11 ) ;
if ( V_16 ) {
F_6 ( & V_98 -> V_22 , L_18 , V_16 ) ;
return V_16 ;
}
return F_53 ( & V_98 -> V_22 ,
& V_102 ) ;
}
