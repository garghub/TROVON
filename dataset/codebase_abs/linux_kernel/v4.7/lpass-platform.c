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
int V_30 , V_31 = V_2 -> V_32 ;
int V_33 ;
int V_8 , V_34 = V_20 -> V_35 + V_25 -> V_36 ;
if ( V_31 == V_37 )
V_30 = V_20 -> V_38 ;
else
V_30 = V_20 -> V_39 ;
V_33 = F_11 ( V_27 ) ;
if ( V_33 < 0 ) {
F_4 ( V_6 -> V_13 , L_2 ,
V_14 , V_33 ) ;
return V_33 ;
}
V_29 = V_40 |
F_12 ( V_34 ) |
V_41 ;
switch ( V_33 ) {
case 16 :
switch ( V_28 ) {
case 1 :
case 2 :
V_29 |= V_42 ;
break;
case 4 :
V_29 |= V_43 ;
break;
case 6 :
V_29 |= V_44 ;
break;
case 8 :
V_29 |= V_45 ;
break;
default:
F_4 ( V_6 -> V_13 , L_3 ,
V_14 , V_33 , V_28 ) ;
return - V_15 ;
}
break;
case 24 :
case 32 :
switch ( V_28 ) {
case 1 :
V_29 |= V_42 ;
break;
case 2 :
V_29 |= V_43 ;
break;
case 4 :
V_29 |= V_45 ;
break;
case 6 :
V_29 |= V_46 ;
break;
case 8 :
V_29 |= V_47 ;
break;
default:
F_4 ( V_6 -> V_13 , L_3 ,
V_14 , V_33 , V_28 ) ;
return - V_15 ;
}
break;
default:
F_4 ( V_6 -> V_13 , L_3 ,
V_14 , V_33 , V_28 ) ;
return - V_15 ;
}
V_8 = F_13 ( V_22 -> V_48 ,
F_14 ( V_25 , V_30 , V_31 ) , V_29 ) ;
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
unsigned int V_49 ;
int V_8 ;
if ( V_2 -> V_32 == V_37 )
V_49 = F_16 ( V_25 , V_20 -> V_38 ) ;
else
V_49 = F_17 ( V_25 , V_20 -> V_39 ) ;
V_8 = F_13 ( V_22 -> V_48 , V_49 , 0 ) ;
if ( V_8 )
F_4 ( V_6 -> V_13 , L_4 ,
V_14 , V_8 ) ;
return V_8 ;
}
static int F_18 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_5 * V_6 = V_2 -> V_7 ;
struct V_19 * V_20 = F_7 ( V_6 ) ;
struct V_21 * V_22 =
F_8 ( V_6 -> V_23 ) ;
struct V_24 * V_25 = V_22 -> V_26 ;
int V_8 , V_30 , V_31 = V_2 -> V_32 ;
if ( V_31 == V_37 )
V_30 = V_20 -> V_38 ;
else
V_30 = V_20 -> V_39 ;
V_8 = F_13 ( V_22 -> V_48 ,
F_19 ( V_25 , V_30 , V_31 ) ,
V_4 -> V_50 ) ;
if ( V_8 ) {
F_4 ( V_6 -> V_13 , L_5 ,
V_14 , V_8 ) ;
return V_8 ;
}
V_8 = F_13 ( V_22 -> V_48 ,
F_20 ( V_25 , V_30 , V_31 ) ,
( F_21 ( V_2 ) >> 2 ) - 1 ) ;
if ( V_8 ) {
F_4 ( V_6 -> V_13 , L_6 ,
V_14 , V_8 ) ;
return V_8 ;
}
V_8 = F_13 ( V_22 -> V_48 ,
F_22 ( V_25 , V_30 , V_31 ) ,
( F_23 ( V_2 ) >> 2 ) - 1 ) ;
if ( V_8 ) {
F_4 ( V_6 -> V_13 , L_7 ,
V_14 , V_8 ) ;
return V_8 ;
}
V_8 = F_24 ( V_22 -> V_48 ,
F_14 ( V_25 , V_30 , V_31 ) ,
V_51 , V_52 ) ;
if ( V_8 ) {
F_4 ( V_6 -> V_13 , L_4 ,
V_14 , V_8 ) ;
return V_8 ;
}
return 0 ;
}
static int F_25 ( struct V_1 * V_2 ,
int V_53 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
struct V_19 * V_20 = F_7 ( V_6 ) ;
struct V_21 * V_22 =
F_8 ( V_6 -> V_23 ) ;
struct V_24 * V_25 = V_22 -> V_26 ;
int V_8 , V_30 , V_31 = V_2 -> V_32 ;
if ( V_31 == V_37 )
V_30 = V_20 -> V_38 ;
else
V_30 = V_20 -> V_39 ;
switch ( V_53 ) {
case V_54 :
case V_55 :
case V_56 :
V_8 = F_13 ( V_22 -> V_48 ,
F_26 ( V_25 , V_57 ) ,
F_27 ( V_30 ) ) ;
if ( V_8 ) {
F_4 ( V_6 -> V_13 , L_8 ,
V_14 , V_8 ) ;
return V_8 ;
}
V_8 = F_24 ( V_22 -> V_48 ,
F_28 ( V_25 , V_57 ) ,
F_27 ( V_30 ) ,
F_27 ( V_30 ) ) ;
if ( V_8 ) {
F_4 ( V_6 -> V_13 , L_9 ,
V_14 , V_8 ) ;
return V_8 ;
}
V_8 = F_24 ( V_22 -> V_48 ,
F_14 ( V_25 , V_30 , V_31 ) ,
V_51 ,
V_52 ) ;
if ( V_8 ) {
F_4 ( V_6 -> V_13 , L_4 ,
V_14 , V_8 ) ;
return V_8 ;
}
break;
case V_58 :
case V_59 :
case V_60 :
V_8 = F_24 ( V_22 -> V_48 ,
F_14 ( V_25 , V_30 , V_31 ) ,
V_51 ,
V_61 ) ;
if ( V_8 ) {
F_4 ( V_6 -> V_13 , L_4 ,
V_14 , V_8 ) ;
return V_8 ;
}
V_8 = F_24 ( V_22 -> V_48 ,
F_28 ( V_25 , V_57 ) ,
F_27 ( V_30 ) , 0 ) ;
if ( V_8 ) {
F_4 ( V_6 -> V_13 , L_9 ,
V_14 , V_8 ) ;
return V_8 ;
}
break;
}
return 0 ;
}
static T_2 F_29 (
struct V_1 * V_2 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
struct V_19 * V_20 = F_7 ( V_6 ) ;
struct V_21 * V_22 =
F_8 ( V_6 -> V_23 ) ;
struct V_24 * V_25 = V_22 -> V_26 ;
unsigned int V_62 , V_63 ;
int V_8 , V_30 , V_31 = V_2 -> V_32 ;
if ( V_31 == V_37 )
V_30 = V_20 -> V_38 ;
else
V_30 = V_20 -> V_39 ;
V_8 = F_30 ( V_22 -> V_48 ,
F_19 ( V_25 , V_30 , V_31 ) , & V_62 ) ;
if ( V_8 ) {
F_4 ( V_6 -> V_13 , L_10 ,
V_14 , V_8 ) ;
return V_8 ;
}
V_8 = F_30 ( V_22 -> V_48 ,
F_31 ( V_25 , V_30 , V_31 ) , & V_63 ) ;
if ( V_8 ) {
F_4 ( V_6 -> V_13 , L_11 ,
V_14 , V_8 ) ;
return V_8 ;
}
return F_32 ( V_2 -> V_4 , V_63 - V_62 ) ;
}
static int F_33 ( struct V_1 * V_2 ,
struct V_64 * V_65 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
return F_34 ( V_2 -> V_66 -> V_67 -> V_13 , V_65 ,
V_4 -> V_68 , V_4 -> V_50 ,
V_4 -> V_10 ) ;
}
static T_3 F_35 (
struct V_1 * V_2 ,
struct V_21 * V_22 ,
int V_69 , T_4 V_70 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
struct V_24 * V_25 = V_22 -> V_26 ;
T_3 V_8 = V_71 ;
int V_72 ;
if ( V_70 & F_36 ( V_69 ) ) {
V_72 = F_13 ( V_22 -> V_48 ,
F_26 ( V_25 , V_57 ) ,
F_36 ( V_69 ) ) ;
if ( V_72 ) {
F_4 ( V_6 -> V_13 , L_8 ,
V_14 , V_72 ) ;
return V_71 ;
}
F_37 ( V_2 ) ;
V_8 = V_73 ;
}
if ( V_70 & F_38 ( V_69 ) ) {
V_72 = F_13 ( V_22 -> V_48 ,
F_26 ( V_25 , V_57 ) ,
F_38 ( V_69 ) ) ;
if ( V_72 ) {
F_4 ( V_6 -> V_13 , L_8 ,
V_14 , V_72 ) ;
return V_71 ;
}
F_39 ( V_6 -> V_13 , L_12 , V_14 ) ;
F_40 ( V_2 , V_74 ) ;
V_8 = V_73 ;
}
if ( V_70 & F_41 ( V_69 ) ) {
V_72 = F_13 ( V_22 -> V_48 ,
F_26 ( V_25 , V_57 ) ,
F_41 ( V_69 ) ) ;
if ( V_72 ) {
F_4 ( V_6 -> V_13 , L_8 ,
V_14 , V_72 ) ;
return V_71 ;
}
F_4 ( V_6 -> V_13 , L_13 , V_14 ) ;
F_40 ( V_2 , V_75 ) ;
V_8 = V_73 ;
}
return V_8 ;
}
static T_3 F_42 ( int V_76 , void * V_77 )
{
struct V_21 * V_22 = V_77 ;
struct V_24 * V_25 = V_22 -> V_26 ;
unsigned int V_78 ;
int V_72 , V_69 ;
V_72 = F_30 ( V_22 -> V_48 ,
F_43 ( V_25 , V_57 ) , & V_78 ) ;
if ( V_72 ) {
F_44 ( L_14 ,
V_14 , V_72 ) ;
return V_71 ;
}
for ( V_69 = 0 ; V_69 < V_79 ; V_69 ++ ) {
if ( V_78 & F_27 ( V_69 ) && V_22 -> V_2 [ V_69 ] ) {
V_72 = F_35 (
V_22 -> V_2 [ V_69 ] ,
V_22 , V_69 , V_78 ) ;
if ( V_72 != V_73 )
return V_72 ;
}
}
return V_73 ;
}
static int F_45 ( struct V_5 * V_6 )
{
struct V_80 * V_66 = V_6 -> V_66 ;
struct V_1 * V_81 , * V_82 ;
struct V_83 * V_84 = V_6 -> V_84 ;
struct V_21 * V_22 =
F_8 ( V_6 -> V_23 ) ;
struct V_24 * V_25 = V_22 -> V_26 ;
int V_8 = - V_15 ;
struct V_19 * V_77 ;
T_5 V_85 = V_9 . V_11 ;
V_77 = F_46 ( V_6 -> V_13 , sizeof( * V_77 ) , V_86 ) ;
if ( ! V_77 )
return - V_87 ;
V_77 -> V_35 = V_84 -> V_88 -> V_89 ;
F_47 ( V_6 , V_77 ) ;
V_81 = V_66 -> V_90 [ V_37 ] . V_2 ;
if ( V_81 ) {
if ( V_25 -> V_91 )
V_77 -> V_38 = V_25 -> V_91 ( V_22 ,
V_37 ) ;
if ( V_77 -> V_38 < 0 )
return V_77 -> V_38 ;
V_22 -> V_2 [ V_77 -> V_38 ] = V_81 ;
V_8 = F_48 ( V_92 ,
V_6 -> V_23 -> V_13 ,
V_85 , & V_81 -> V_16 ) ;
if ( V_8 )
goto V_93;
V_8 = F_13 ( V_22 -> V_48 ,
F_16 ( V_25 , V_77 -> V_38 ) , 0 ) ;
if ( V_8 ) {
F_4 ( V_6 -> V_13 ,
L_4 ,
V_14 , V_8 ) ;
goto V_94;
}
}
V_82 = V_66 -> V_90 [ V_95 ] . V_2 ;
if ( V_82 ) {
if ( V_25 -> V_91 )
V_77 -> V_39 = V_25 -> V_91 ( V_22 ,
V_95 ) ;
if ( V_77 -> V_39 < 0 ) {
V_8 = V_77 -> V_39 ;
goto V_94;
}
V_22 -> V_2 [ V_77 -> V_39 ] = V_82 ;
V_8 = F_48 ( V_92 ,
V_6 -> V_23 -> V_13 ,
V_85 , & V_82 -> V_16 ) ;
if ( V_8 )
goto V_94;
V_8 = F_13 ( V_22 -> V_48 ,
F_17 ( V_25 , V_77 -> V_39 ) , 0 ) ;
if ( V_8 ) {
F_4 ( V_6 -> V_13 ,
L_15 ,
V_14 , V_8 ) ;
goto V_96;
}
}
return 0 ;
V_96:
if ( V_82 )
F_49 ( & V_82 -> V_16 ) ;
V_94:
if ( V_81 )
F_49 ( & V_81 -> V_16 ) ;
V_93:
F_4 ( V_6 -> V_13 , L_16 ) ;
return V_8 ;
}
static void F_50 ( struct V_80 * V_66 )
{
struct V_5 * V_97 ;
struct V_21 * V_22 ;
struct V_19 * V_77 ;
struct V_24 * V_25 ;
struct V_1 * V_2 ;
int V_30 , V_98 ;
for ( V_98 = 0 ; V_98 < F_51 ( V_66 -> V_90 ) ; V_98 ++ ) {
V_2 = V_66 -> V_90 [ V_98 ] . V_2 ;
if ( V_2 ) {
V_97 = V_2 -> V_7 ;
V_77 = F_7 ( V_97 ) ;
V_22 = F_8 ( V_97 -> V_23 ) ;
V_30 = ( V_2 -> V_32 == V_37 )
? V_77 -> V_38
: V_77 -> V_39 ;
V_25 = V_22 -> V_26 ;
V_22 -> V_2 [ V_30 ] = NULL ;
if ( V_25 -> V_99 )
V_25 -> V_99 ( V_22 , V_30 ) ;
F_49 ( & V_2 -> V_16 ) ;
V_2 -> V_16 . V_100 = NULL ;
V_2 -> V_16 . V_101 = 0 ;
}
}
}
int F_52 ( struct V_102 * V_103 )
{
struct V_21 * V_22 = F_53 ( V_103 ) ;
struct V_24 * V_25 = V_22 -> V_26 ;
int V_8 ;
V_22 -> V_104 = F_54 ( V_103 , L_17 ) ;
if ( V_22 -> V_104 < 0 ) {
F_4 ( & V_103 -> V_13 , L_18 ,
V_14 , V_22 -> V_104 ) ;
return - V_105 ;
}
V_8 = F_13 ( V_22 -> V_48 ,
F_28 ( V_25 , V_57 ) , 0 ) ;
if ( V_8 ) {
F_4 ( & V_103 -> V_13 , L_9 ,
V_14 , V_8 ) ;
return V_8 ;
}
V_8 = F_55 ( & V_103 -> V_13 , V_22 -> V_104 ,
F_42 , V_106 ,
L_17 , V_22 ) ;
if ( V_8 ) {
F_4 ( & V_103 -> V_13 , L_19 ,
V_14 , V_8 ) ;
return V_8 ;
}
return F_56 ( & V_103 -> V_13 ,
& V_107 ) ;
}
