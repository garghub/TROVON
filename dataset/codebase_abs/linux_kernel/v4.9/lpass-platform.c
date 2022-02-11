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
if ( V_18 == V_31 )
V_21 -> V_32 = V_17 ;
else
V_21 -> V_33 = V_17 ;
F_7 ( V_2 , & V_34 ) ;
V_4 -> V_35 = V_34 . V_36 ;
V_16 = F_8 ( V_4 ,
V_37 ) ;
if ( V_16 < 0 ) {
F_6 ( V_6 -> V_22 , L_2 ,
V_30 , V_16 ) ;
return - V_38 ;
}
F_9 ( V_2 , & V_2 -> V_39 ) ;
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
int V_17 , V_18 = V_2 -> V_19 ;
V_21 = V_4 -> V_7 ;
V_14 = V_11 -> V_15 ;
if ( V_18 == V_31 )
V_17 = V_21 -> V_32 ;
else
V_17 = V_21 -> V_33 ;
V_11 -> V_2 [ V_17 ] = NULL ;
if ( V_14 -> V_40 )
V_14 -> V_40 ( V_11 , V_17 ) ;
return 0 ;
}
static int F_11 ( struct V_1 * V_2 ,
struct V_41 * V_42 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
struct V_10 * V_11 =
F_2 ( V_6 -> V_12 ) ;
struct V_3 * V_43 = V_2 -> V_4 ;
struct V_20 * V_44 = V_43 -> V_7 ;
struct V_13 * V_14 = V_11 -> V_15 ;
T_1 V_45 = F_12 ( V_42 ) ;
unsigned int V_46 = F_13 ( V_42 ) ;
unsigned int V_47 ;
int V_48 , V_18 = V_2 -> V_19 ;
int V_49 ;
int V_16 , V_50 = V_44 -> V_25 + V_14 -> V_51 ;
if ( V_18 == V_31 )
V_48 = V_44 -> V_32 ;
else
V_48 = V_44 -> V_33 ;
V_49 = F_14 ( V_45 ) ;
if ( V_49 < 0 ) {
F_6 ( V_6 -> V_22 , L_3 ,
V_30 , V_49 ) ;
return V_49 ;
}
V_47 = V_52 |
F_15 ( V_50 ) |
V_53 ;
switch ( V_49 ) {
case 16 :
switch ( V_46 ) {
case 1 :
case 2 :
V_47 |= V_54 ;
break;
case 4 :
V_47 |= V_55 ;
break;
case 6 :
V_47 |= V_56 ;
break;
case 8 :
V_47 |= V_57 ;
break;
default:
F_6 ( V_6 -> V_22 , L_4 ,
V_30 , V_49 , V_46 ) ;
return - V_38 ;
}
break;
case 24 :
case 32 :
switch ( V_46 ) {
case 1 :
V_47 |= V_54 ;
break;
case 2 :
V_47 |= V_55 ;
break;
case 4 :
V_47 |= V_57 ;
break;
case 6 :
V_47 |= V_58 ;
break;
case 8 :
V_47 |= V_59 ;
break;
default:
F_6 ( V_6 -> V_22 , L_4 ,
V_30 , V_49 , V_46 ) ;
return - V_38 ;
}
break;
default:
F_6 ( V_6 -> V_22 , L_4 ,
V_30 , V_49 , V_46 ) ;
return - V_38 ;
}
V_16 = F_4 ( V_11 -> V_29 ,
F_5 ( V_14 , V_48 , V_18 ) , V_47 ) ;
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
struct V_3 * V_43 = V_2 -> V_4 ;
struct V_20 * V_44 = V_43 -> V_7 ;
struct V_13 * V_14 = V_11 -> V_15 ;
unsigned int V_60 ;
int V_16 ;
if ( V_2 -> V_19 == V_31 )
V_60 = F_17 ( V_14 , V_44 -> V_32 ) ;
else
V_60 = F_18 ( V_14 , V_44 -> V_33 ) ;
V_16 = F_4 ( V_11 -> V_29 , V_60 , 0 ) ;
if ( V_16 )
F_6 ( V_6 -> V_22 , L_1 ,
V_30 , V_16 ) ;
return V_16 ;
}
static int F_19 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_5 * V_6 = V_2 -> V_7 ;
struct V_10 * V_11 =
F_2 ( V_6 -> V_12 ) ;
struct V_3 * V_43 = V_2 -> V_4 ;
struct V_20 * V_44 = V_43 -> V_7 ;
struct V_13 * V_14 = V_11 -> V_15 ;
int V_16 , V_48 , V_18 = V_2 -> V_19 ;
if ( V_18 == V_31 )
V_48 = V_44 -> V_32 ;
else
V_48 = V_44 -> V_33 ;
V_16 = F_4 ( V_11 -> V_29 ,
F_20 ( V_14 , V_48 , V_18 ) ,
V_4 -> V_61 ) ;
if ( V_16 ) {
F_6 ( V_6 -> V_22 , L_5 ,
V_30 , V_16 ) ;
return V_16 ;
}
V_16 = F_4 ( V_11 -> V_29 ,
F_21 ( V_14 , V_48 , V_18 ) ,
( F_22 ( V_2 ) >> 2 ) - 1 ) ;
if ( V_16 ) {
F_6 ( V_6 -> V_22 , L_6 ,
V_30 , V_16 ) ;
return V_16 ;
}
V_16 = F_4 ( V_11 -> V_29 ,
F_23 ( V_14 , V_48 , V_18 ) ,
( F_24 ( V_2 ) >> 2 ) - 1 ) ;
if ( V_16 ) {
F_6 ( V_6 -> V_22 , L_7 ,
V_30 , V_16 ) ;
return V_16 ;
}
V_16 = F_25 ( V_11 -> V_29 ,
F_5 ( V_14 , V_48 , V_18 ) ,
V_62 , V_63 ) ;
if ( V_16 ) {
F_6 ( V_6 -> V_22 , L_1 ,
V_30 , V_16 ) ;
return V_16 ;
}
return 0 ;
}
static int F_26 ( struct V_1 * V_2 ,
int V_64 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
struct V_10 * V_11 =
F_2 ( V_6 -> V_12 ) ;
struct V_3 * V_43 = V_2 -> V_4 ;
struct V_20 * V_44 = V_43 -> V_7 ;
struct V_13 * V_14 = V_11 -> V_15 ;
int V_16 , V_48 , V_18 = V_2 -> V_19 ;
if ( V_18 == V_31 )
V_48 = V_44 -> V_32 ;
else
V_48 = V_44 -> V_33 ;
switch ( V_64 ) {
case V_65 :
case V_66 :
case V_67 :
V_16 = F_4 ( V_11 -> V_29 ,
F_27 ( V_14 , V_68 ) ,
F_28 ( V_48 ) ) ;
if ( V_16 ) {
F_6 ( V_6 -> V_22 , L_8 ,
V_30 , V_16 ) ;
return V_16 ;
}
V_16 = F_25 ( V_11 -> V_29 ,
F_29 ( V_14 , V_68 ) ,
F_28 ( V_48 ) ,
F_28 ( V_48 ) ) ;
if ( V_16 ) {
F_6 ( V_6 -> V_22 , L_9 ,
V_30 , V_16 ) ;
return V_16 ;
}
V_16 = F_25 ( V_11 -> V_29 ,
F_5 ( V_14 , V_48 , V_18 ) ,
V_62 ,
V_63 ) ;
if ( V_16 ) {
F_6 ( V_6 -> V_22 , L_1 ,
V_30 , V_16 ) ;
return V_16 ;
}
break;
case V_69 :
case V_70 :
case V_71 :
V_16 = F_25 ( V_11 -> V_29 ,
F_5 ( V_14 , V_48 , V_18 ) ,
V_62 ,
V_72 ) ;
if ( V_16 ) {
F_6 ( V_6 -> V_22 , L_1 ,
V_30 , V_16 ) ;
return V_16 ;
}
V_16 = F_25 ( V_11 -> V_29 ,
F_29 ( V_14 , V_68 ) ,
F_28 ( V_48 ) , 0 ) ;
if ( V_16 ) {
F_6 ( V_6 -> V_22 , L_9 ,
V_30 , V_16 ) ;
return V_16 ;
}
break;
}
return 0 ;
}
static T_2 F_30 (
struct V_1 * V_2 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
struct V_10 * V_11 =
F_2 ( V_6 -> V_12 ) ;
struct V_3 * V_43 = V_2 -> V_4 ;
struct V_20 * V_44 = V_43 -> V_7 ;
struct V_13 * V_14 = V_11 -> V_15 ;
unsigned int V_73 , V_74 ;
int V_16 , V_48 , V_18 = V_2 -> V_19 ;
if ( V_18 == V_31 )
V_48 = V_44 -> V_32 ;
else
V_48 = V_44 -> V_33 ;
V_16 = F_31 ( V_11 -> V_29 ,
F_20 ( V_14 , V_48 , V_18 ) , & V_73 ) ;
if ( V_16 ) {
F_6 ( V_6 -> V_22 , L_10 ,
V_30 , V_16 ) ;
return V_16 ;
}
V_16 = F_31 ( V_11 -> V_29 ,
F_32 ( V_14 , V_48 , V_18 ) , & V_74 ) ;
if ( V_16 ) {
F_6 ( V_6 -> V_22 , L_11 ,
V_30 , V_16 ) ;
return V_16 ;
}
return F_33 ( V_2 -> V_4 , V_74 - V_73 ) ;
}
static int F_34 ( struct V_1 * V_2 ,
struct V_75 * V_76 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
return F_35 ( V_2 -> V_77 -> V_78 -> V_22 , V_76 ,
V_4 -> V_79 , V_4 -> V_61 ,
V_4 -> V_35 ) ;
}
static T_3 F_36 (
struct V_1 * V_2 ,
struct V_10 * V_11 ,
int V_80 , T_4 V_81 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
struct V_13 * V_14 = V_11 -> V_15 ;
T_3 V_16 = V_82 ;
int V_83 ;
if ( V_81 & F_37 ( V_80 ) ) {
V_83 = F_4 ( V_11 -> V_29 ,
F_27 ( V_14 , V_68 ) ,
F_37 ( V_80 ) ) ;
if ( V_83 ) {
F_6 ( V_6 -> V_22 , L_8 ,
V_30 , V_83 ) ;
return V_82 ;
}
F_38 ( V_2 ) ;
V_16 = V_84 ;
}
if ( V_81 & F_39 ( V_80 ) ) {
V_83 = F_4 ( V_11 -> V_29 ,
F_27 ( V_14 , V_68 ) ,
F_39 ( V_80 ) ) ;
if ( V_83 ) {
F_6 ( V_6 -> V_22 , L_8 ,
V_30 , V_83 ) ;
return V_82 ;
}
F_40 ( V_6 -> V_22 , L_12 , V_30 ) ;
F_41 ( V_2 , V_85 ) ;
V_16 = V_84 ;
}
if ( V_81 & F_42 ( V_80 ) ) {
V_83 = F_4 ( V_11 -> V_29 ,
F_27 ( V_14 , V_68 ) ,
F_42 ( V_80 ) ) ;
if ( V_83 ) {
F_6 ( V_6 -> V_22 , L_8 ,
V_30 , V_83 ) ;
return V_82 ;
}
F_6 ( V_6 -> V_22 , L_13 , V_30 ) ;
F_41 ( V_2 , V_86 ) ;
V_16 = V_84 ;
}
return V_16 ;
}
static T_3 F_43 ( int V_87 , void * V_21 )
{
struct V_10 * V_11 = V_21 ;
struct V_13 * V_14 = V_11 -> V_15 ;
unsigned int V_88 ;
int V_83 , V_80 ;
V_83 = F_31 ( V_11 -> V_29 ,
F_44 ( V_14 , V_68 ) , & V_88 ) ;
if ( V_83 ) {
F_45 ( L_14 ,
V_30 , V_83 ) ;
return V_82 ;
}
for ( V_80 = 0 ; V_80 < V_89 ; V_80 ++ ) {
if ( V_88 & F_28 ( V_80 ) && V_11 -> V_2 [ V_80 ] ) {
V_83 = F_36 (
V_11 -> V_2 [ V_80 ] ,
V_11 , V_80 , V_88 ) ;
if ( V_83 != V_84 )
return V_83 ;
}
}
return V_84 ;
}
static int F_46 ( struct V_5 * V_6 )
{
struct V_90 * V_77 = V_6 -> V_77 ;
struct V_1 * V_91 , * V_92 ;
int V_16 = - V_38 ;
T_5 V_93 = V_34 . V_36 ;
V_91 = V_77 -> V_94 [ V_31 ] . V_2 ;
if ( V_91 ) {
V_16 = F_47 ( V_95 ,
V_6 -> V_12 -> V_22 ,
V_93 , & V_91 -> V_39 ) ;
if ( V_16 ) {
F_6 ( V_6 -> V_22 , L_15 ) ;
return V_16 ;
}
}
V_92 = V_77 -> V_94 [ V_96 ] . V_2 ;
if ( V_92 ) {
V_16 = F_47 ( V_95 ,
V_6 -> V_12 -> V_22 ,
V_93 , & V_92 -> V_39 ) ;
if ( V_16 ) {
F_6 ( V_6 -> V_22 , L_15 ) ;
if ( V_91 )
F_48 ( & V_91 -> V_39 ) ;
return V_16 ;
}
}
return 0 ;
}
static void F_49 ( struct V_90 * V_77 )
{
struct V_1 * V_2 ;
int V_97 ;
for ( V_97 = 0 ; V_97 < F_50 ( V_77 -> V_94 ) ; V_97 ++ ) {
V_2 = V_77 -> V_94 [ V_97 ] . V_2 ;
if ( V_2 ) {
F_48 ( & V_2 -> V_39 ) ;
V_2 -> V_39 . V_98 = NULL ;
V_2 -> V_39 . V_99 = 0 ;
}
}
}
int F_51 ( struct V_100 * V_101 )
{
struct V_10 * V_11 = F_52 ( V_101 ) ;
struct V_13 * V_14 = V_11 -> V_15 ;
int V_16 ;
V_11 -> V_102 = F_53 ( V_101 , L_16 ) ;
if ( V_11 -> V_102 < 0 ) {
F_6 ( & V_101 -> V_22 , L_17 ,
V_30 , V_11 -> V_102 ) ;
return - V_103 ;
}
V_16 = F_4 ( V_11 -> V_29 ,
F_29 ( V_14 , V_68 ) , 0 ) ;
if ( V_16 ) {
F_6 ( & V_101 -> V_22 , L_9 ,
V_30 , V_16 ) ;
return V_16 ;
}
V_16 = F_54 ( & V_101 -> V_22 , V_11 -> V_102 ,
F_43 , V_104 ,
L_16 , V_11 ) ;
if ( V_16 ) {
F_6 ( & V_101 -> V_22 , L_18 ,
V_30 , V_16 ) ;
return V_16 ;
}
return F_55 ( & V_101 -> V_22 ,
& V_105 ) ;
}
