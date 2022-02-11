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
L_1 ,
V_30 , V_16 ) ;
return V_16 ;
}
V_21 -> V_17 = V_17 ;
F_7 ( V_2 , & V_31 ) ;
V_4 -> V_32 = V_31 . V_33 ;
V_16 = F_8 ( V_4 ,
V_34 ) ;
if ( V_16 < 0 ) {
F_6 ( V_6 -> V_22 , L_2 ,
V_30 , V_16 ) ;
return - V_35 ;
}
F_9 ( V_2 , & V_2 -> V_36 ) ;
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
if ( V_14 -> V_37 )
V_14 -> V_37 ( V_11 , V_21 -> V_17 ) ;
return 0 ;
}
static int F_11 ( struct V_1 * V_2 ,
struct V_38 * V_39 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
struct V_10 * V_11 =
F_2 ( V_6 -> V_12 ) ;
struct V_3 * V_40 = V_2 -> V_4 ;
struct V_20 * V_41 = V_40 -> V_7 ;
struct V_13 * V_14 = V_11 -> V_15 ;
T_1 V_42 = F_12 ( V_39 ) ;
unsigned int V_43 = F_13 ( V_39 ) ;
unsigned int V_44 ;
int V_45 , V_18 = V_2 -> V_19 ;
int V_46 ;
int V_16 , V_47 = V_41 -> V_25 + V_14 -> V_48 ;
V_45 = V_41 -> V_17 ;
V_46 = F_14 ( V_42 ) ;
if ( V_46 < 0 ) {
F_6 ( V_6 -> V_22 , L_3 ,
V_30 , V_46 ) ;
return V_46 ;
}
V_44 = V_49 |
F_15 ( V_47 ) |
V_50 ;
switch ( V_46 ) {
case 16 :
switch ( V_43 ) {
case 1 :
case 2 :
V_44 |= V_51 ;
break;
case 4 :
V_44 |= V_52 ;
break;
case 6 :
V_44 |= V_53 ;
break;
case 8 :
V_44 |= V_54 ;
break;
default:
F_6 ( V_6 -> V_22 , L_4 ,
V_30 , V_46 , V_43 ) ;
return - V_35 ;
}
break;
case 24 :
case 32 :
switch ( V_43 ) {
case 1 :
V_44 |= V_51 ;
break;
case 2 :
V_44 |= V_52 ;
break;
case 4 :
V_44 |= V_54 ;
break;
case 6 :
V_44 |= V_55 ;
break;
case 8 :
V_44 |= V_56 ;
break;
default:
F_6 ( V_6 -> V_22 , L_4 ,
V_30 , V_46 , V_43 ) ;
return - V_35 ;
}
break;
default:
F_6 ( V_6 -> V_22 , L_4 ,
V_30 , V_46 , V_43 ) ;
return - V_35 ;
}
V_16 = F_4 ( V_11 -> V_29 ,
F_5 ( V_14 , V_45 , V_18 ) , V_44 ) ;
if ( V_16 ) {
F_6 ( V_6 -> V_22 , L_1 ,
V_30 , V_16 ) ;
return V_16 ;
}
return 0 ;
}
static int F_16 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
struct V_10 * V_11 =
F_2 ( V_6 -> V_12 ) ;
struct V_3 * V_40 = V_2 -> V_4 ;
struct V_20 * V_41 = V_40 -> V_7 ;
struct V_13 * V_14 = V_11 -> V_15 ;
unsigned int V_57 ;
int V_16 ;
V_57 = F_5 ( V_14 , V_41 -> V_17 , V_2 -> V_19 ) ;
V_16 = F_4 ( V_11 -> V_29 , V_57 , 0 ) ;
if ( V_16 )
F_6 ( V_6 -> V_22 , L_1 ,
V_30 , V_16 ) ;
return V_16 ;
}
static int F_17 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_5 * V_6 = V_2 -> V_7 ;
struct V_10 * V_11 =
F_2 ( V_6 -> V_12 ) ;
struct V_3 * V_40 = V_2 -> V_4 ;
struct V_20 * V_41 = V_40 -> V_7 ;
struct V_13 * V_14 = V_11 -> V_15 ;
int V_16 , V_45 , V_18 = V_2 -> V_19 ;
V_45 = V_41 -> V_17 ;
V_16 = F_4 ( V_11 -> V_29 ,
F_18 ( V_14 , V_45 , V_18 ) ,
V_4 -> V_58 ) ;
if ( V_16 ) {
F_6 ( V_6 -> V_22 , L_5 ,
V_30 , V_16 ) ;
return V_16 ;
}
V_16 = F_4 ( V_11 -> V_29 ,
F_19 ( V_14 , V_45 , V_18 ) ,
( F_20 ( V_2 ) >> 2 ) - 1 ) ;
if ( V_16 ) {
F_6 ( V_6 -> V_22 , L_6 ,
V_30 , V_16 ) ;
return V_16 ;
}
V_16 = F_4 ( V_11 -> V_29 ,
F_21 ( V_14 , V_45 , V_18 ) ,
( F_22 ( V_2 ) >> 2 ) - 1 ) ;
if ( V_16 ) {
F_6 ( V_6 -> V_22 , L_7 ,
V_30 , V_16 ) ;
return V_16 ;
}
V_16 = F_23 ( V_11 -> V_29 ,
F_5 ( V_14 , V_45 , V_18 ) ,
V_59 , V_60 ) ;
if ( V_16 ) {
F_6 ( V_6 -> V_22 , L_1 ,
V_30 , V_16 ) ;
return V_16 ;
}
return 0 ;
}
static int F_24 ( struct V_1 * V_2 ,
int V_61 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
struct V_10 * V_11 =
F_2 ( V_6 -> V_12 ) ;
struct V_3 * V_40 = V_2 -> V_4 ;
struct V_20 * V_41 = V_40 -> V_7 ;
struct V_13 * V_14 = V_11 -> V_15 ;
int V_16 , V_45 , V_18 = V_2 -> V_19 ;
V_45 = V_41 -> V_17 ;
switch ( V_61 ) {
case V_62 :
case V_63 :
case V_64 :
V_16 = F_4 ( V_11 -> V_29 ,
F_25 ( V_14 , V_65 ) ,
F_26 ( V_45 ) ) ;
if ( V_16 ) {
F_6 ( V_6 -> V_22 , L_8 ,
V_30 , V_16 ) ;
return V_16 ;
}
V_16 = F_23 ( V_11 -> V_29 ,
F_27 ( V_14 , V_65 ) ,
F_26 ( V_45 ) ,
F_26 ( V_45 ) ) ;
if ( V_16 ) {
F_6 ( V_6 -> V_22 , L_9 ,
V_30 , V_16 ) ;
return V_16 ;
}
V_16 = F_23 ( V_11 -> V_29 ,
F_5 ( V_14 , V_45 , V_18 ) ,
V_59 ,
V_60 ) ;
if ( V_16 ) {
F_6 ( V_6 -> V_22 , L_1 ,
V_30 , V_16 ) ;
return V_16 ;
}
break;
case V_66 :
case V_67 :
case V_68 :
V_16 = F_23 ( V_11 -> V_29 ,
F_5 ( V_14 , V_45 , V_18 ) ,
V_59 ,
V_69 ) ;
if ( V_16 ) {
F_6 ( V_6 -> V_22 , L_1 ,
V_30 , V_16 ) ;
return V_16 ;
}
V_16 = F_23 ( V_11 -> V_29 ,
F_27 ( V_14 , V_65 ) ,
F_26 ( V_45 ) , 0 ) ;
if ( V_16 ) {
F_6 ( V_6 -> V_22 , L_9 ,
V_30 , V_16 ) ;
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
struct V_3 * V_40 = V_2 -> V_4 ;
struct V_20 * V_41 = V_40 -> V_7 ;
struct V_13 * V_14 = V_11 -> V_15 ;
unsigned int V_70 , V_71 ;
int V_16 , V_45 , V_18 = V_2 -> V_19 ;
V_45 = V_41 -> V_17 ;
V_16 = F_29 ( V_11 -> V_29 ,
F_18 ( V_14 , V_45 , V_18 ) , & V_70 ) ;
if ( V_16 ) {
F_6 ( V_6 -> V_22 , L_10 ,
V_30 , V_16 ) ;
return V_16 ;
}
V_16 = F_29 ( V_11 -> V_29 ,
F_30 ( V_14 , V_45 , V_18 ) , & V_71 ) ;
if ( V_16 ) {
F_6 ( V_6 -> V_22 , L_11 ,
V_30 , V_16 ) ;
return V_16 ;
}
return F_31 ( V_2 -> V_4 , V_71 - V_70 ) ;
}
static int F_32 ( struct V_1 * V_2 ,
struct V_72 * V_73 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
return F_33 ( V_2 -> V_74 -> V_75 -> V_22 , V_73 ,
V_4 -> V_76 , V_4 -> V_58 ,
V_4 -> V_32 ) ;
}
static T_3 F_34 (
struct V_1 * V_2 ,
struct V_10 * V_11 ,
int V_77 , T_4 V_78 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
struct V_13 * V_14 = V_11 -> V_15 ;
T_3 V_16 = V_79 ;
int V_80 ;
if ( V_78 & F_35 ( V_77 ) ) {
V_80 = F_4 ( V_11 -> V_29 ,
F_25 ( V_14 , V_65 ) ,
F_35 ( V_77 ) ) ;
if ( V_80 ) {
F_6 ( V_6 -> V_22 , L_8 ,
V_30 , V_80 ) ;
return V_79 ;
}
F_36 ( V_2 ) ;
V_16 = V_81 ;
}
if ( V_78 & F_37 ( V_77 ) ) {
V_80 = F_4 ( V_11 -> V_29 ,
F_25 ( V_14 , V_65 ) ,
F_37 ( V_77 ) ) ;
if ( V_80 ) {
F_6 ( V_6 -> V_22 , L_8 ,
V_30 , V_80 ) ;
return V_79 ;
}
F_38 ( V_6 -> V_22 , L_12 , V_30 ) ;
F_39 ( V_2 , V_82 ) ;
V_16 = V_81 ;
}
if ( V_78 & F_40 ( V_77 ) ) {
V_80 = F_4 ( V_11 -> V_29 ,
F_25 ( V_14 , V_65 ) ,
F_40 ( V_77 ) ) ;
if ( V_80 ) {
F_6 ( V_6 -> V_22 , L_8 ,
V_30 , V_80 ) ;
return V_79 ;
}
F_6 ( V_6 -> V_22 , L_13 , V_30 ) ;
F_39 ( V_2 , V_83 ) ;
V_16 = V_81 ;
}
return V_16 ;
}
static T_3 F_41 ( int V_84 , void * V_21 )
{
struct V_10 * V_11 = V_21 ;
struct V_13 * V_14 = V_11 -> V_15 ;
unsigned int V_85 ;
int V_80 , V_77 ;
V_80 = F_29 ( V_11 -> V_29 ,
F_42 ( V_14 , V_65 ) , & V_85 ) ;
if ( V_80 ) {
F_43 ( L_14 ,
V_30 , V_80 ) ;
return V_79 ;
}
for ( V_77 = 0 ; V_77 < V_86 ; V_77 ++ ) {
if ( V_85 & F_26 ( V_77 ) && V_11 -> V_2 [ V_77 ] ) {
V_80 = F_34 (
V_11 -> V_2 [ V_77 ] ,
V_11 , V_77 , V_85 ) ;
if ( V_80 != V_81 )
return V_80 ;
}
}
return V_81 ;
}
static int F_44 ( struct V_5 * V_6 )
{
struct V_87 * V_74 = V_6 -> V_74 ;
struct V_1 * V_88 , * V_89 ;
int V_16 = - V_35 ;
T_5 V_90 = V_31 . V_33 ;
V_88 = V_74 -> V_91 [ V_92 ] . V_2 ;
if ( V_88 ) {
V_16 = F_45 ( V_93 ,
V_6 -> V_12 -> V_22 ,
V_90 , & V_88 -> V_36 ) ;
if ( V_16 ) {
F_6 ( V_6 -> V_22 , L_15 ) ;
return V_16 ;
}
}
V_89 = V_74 -> V_91 [ V_94 ] . V_2 ;
if ( V_89 ) {
V_16 = F_45 ( V_93 ,
V_6 -> V_12 -> V_22 ,
V_90 , & V_89 -> V_36 ) ;
if ( V_16 ) {
F_6 ( V_6 -> V_22 , L_15 ) ;
if ( V_88 )
F_46 ( & V_88 -> V_36 ) ;
return V_16 ;
}
}
return 0 ;
}
static void F_47 ( struct V_87 * V_74 )
{
struct V_1 * V_2 ;
int V_95 ;
for ( V_95 = 0 ; V_95 < F_48 ( V_74 -> V_91 ) ; V_95 ++ ) {
V_2 = V_74 -> V_91 [ V_95 ] . V_2 ;
if ( V_2 ) {
F_46 ( & V_2 -> V_36 ) ;
V_2 -> V_36 . V_96 = NULL ;
V_2 -> V_36 . V_97 = 0 ;
}
}
}
int F_49 ( struct V_98 * V_99 )
{
struct V_10 * V_11 = F_50 ( V_99 ) ;
struct V_13 * V_14 = V_11 -> V_15 ;
int V_16 ;
V_11 -> V_100 = F_51 ( V_99 , L_16 ) ;
if ( V_11 -> V_100 < 0 ) {
F_6 ( & V_99 -> V_22 , L_17 ,
V_30 , V_11 -> V_100 ) ;
return - V_101 ;
}
V_16 = F_4 ( V_11 -> V_29 ,
F_27 ( V_14 , V_65 ) , 0 ) ;
if ( V_16 ) {
F_6 ( & V_99 -> V_22 , L_9 ,
V_30 , V_16 ) ;
return V_16 ;
}
V_16 = F_52 ( & V_99 -> V_22 , V_11 -> V_100 ,
F_41 , V_102 ,
L_16 , V_11 ) ;
if ( V_16 ) {
F_6 ( & V_99 -> V_22 , L_18 ,
V_30 , V_16 ) ;
return V_16 ;
}
return F_53 ( & V_99 -> V_22 ,
& V_103 ) ;
}
