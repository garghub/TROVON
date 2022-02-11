static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_5 * V_5 = V_4 -> V_5 ;
int V_6 = 1 << F_3 ( V_2 ) ;
int V_7 ;
V_7 = F_4 ( V_5 , V_8 ) ;
if ( V_7 < 0 )
return V_7 ;
if ( V_7 & V_6 )
return 1 ;
else
return 0 ;
}
static int F_5 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_5 * V_5 = V_4 -> V_5 ;
int V_6 = 1 << F_3 ( V_2 ) ;
return F_6 ( V_5 , V_8 , V_6 , V_6 ) ;
}
static int F_7 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_5 * V_5 = V_4 -> V_5 ;
int V_6 = 1 << F_3 ( V_2 ) ;
return F_6 ( V_5 , V_8 , V_6 , 0 ) ;
}
static unsigned int F_8 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_5 * V_5 = V_4 -> V_5 ;
T_1 V_7 = V_4 -> V_9 + V_10 ;
int V_11 ;
V_11 = F_4 ( V_5 , V_7 ) ;
if ( V_11 < 0 )
return V_11 ;
V_11 = ( V_11 & V_12 ) >> V_13 ;
switch ( V_11 ) {
case V_14 :
return V_15 ;
case V_16 :
return V_17 ;
case V_18 :
return V_19 ;
case V_20 :
return V_21 ;
default:
F_9 () ;
return - V_22 ;
}
}
static int F_10 ( struct V_5 * V_5 , int V_7 ,
unsigned int V_23 )
{
int V_11 ;
switch ( V_23 ) {
case V_15 :
V_11 = V_14 ;
break;
case V_17 :
V_11 = V_16 ;
break;
case V_19 :
V_11 = V_18 ;
break;
case V_21 :
V_11 = V_20 ;
break;
default:
return - V_22 ;
}
return F_6 ( V_5 , V_7 , V_12 ,
V_11 << V_13 ) ;
}
static int F_11 ( struct V_1 * V_2 , unsigned int V_23 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_5 * V_5 = V_4 -> V_5 ;
T_1 V_7 = V_4 -> V_9 + V_10 ;
return F_10 ( V_5 , V_7 , V_23 ) ;
}
static int F_12 ( struct V_1 * V_2 ,
unsigned int V_23 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_5 * V_5 = V_4 -> V_5 ;
T_1 V_7 = V_4 -> V_9 + V_24 ;
return F_10 ( V_5 , V_7 , V_23 ) ;
}
static int F_13 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_5 * V_5 = V_4 -> V_5 ;
int V_25 ;
V_25 = F_4 ( V_5 , V_26 ) ;
if ( V_25 < 0 )
return V_25 ;
if ( V_25 & ( 1 << F_3 ( V_2 ) ) ) {
F_14 ( V_5 -> V_27 , L_1 ,
F_3 ( V_2 ) + 1 ) ;
return V_28 ;
}
if ( F_3 ( V_2 ) < 2 ) {
if ( V_25 & ( V_29 << F_3 ( V_2 ) ) ) {
F_14 ( V_5 -> V_27 , L_2 ,
F_3 ( V_2 ) + 1 ) ;
return V_28 ;
}
if ( V_25 & ( V_30 << F_3 ( V_2 ) ) ) {
F_14 ( V_5 -> V_27 , L_3 ,
F_3 ( V_2 ) + 1 ) ;
return V_28 ;
}
}
V_25 = F_4 ( V_5 , V_31 ) ;
if ( V_25 < 0 )
return V_25 ;
if ( ! ( V_25 & ( 1 << F_3 ( V_2 ) ) ) )
return V_32 ;
return V_33 ;
}
static T_2 F_15 ( int V_34 , void * V_35 )
{
struct V_3 * V_4 = V_35 ;
F_16 ( V_4 -> V_36 ,
V_37 ,
NULL ) ;
return V_38 ;
}
static T_2 F_17 ( int V_34 , void * V_35 )
{
struct V_3 * V_4 = V_35 ;
F_16 ( V_4 -> V_36 ,
V_39 ,
NULL ) ;
return V_38 ;
}
static int F_18 ( struct V_1 * V_2 ,
unsigned V_40 )
{
if ( V_40 <= 0x8 )
return 600000 ;
if ( V_40 <= V_41 )
return 600000 + ( ( V_40 - 0x8 ) * 12500 ) ;
return - V_22 ;
}
static int F_19 ( struct V_1 * V_2 ,
int V_42 , int V_43 )
{
T_1 V_44 ;
if ( V_42 < 600000 )
V_44 = 0 ;
else if ( V_42 <= 1800000 )
V_44 = ( ( V_42 - 600000 ) / 12500 ) + 8 ;
else
return - V_22 ;
if ( F_18 ( V_2 , V_44 ) > V_43 )
return - V_22 ;
return V_44 ;
}
static int F_20 ( struct V_1 * V_2 , int V_45 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
if ( V_45 == V_4 -> V_46 )
return 0 ;
V_4 -> V_46 = V_45 ;
F_21 ( V_4 -> V_47 , V_45 ) ;
return 0 ;
}
static int F_22 ( struct V_1 * V_2 ,
int V_42 , int V_43 , unsigned * V_40 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_5 * V_5 = V_4 -> V_5 ;
int V_48 = V_4 -> V_9 + V_10 ;
int V_49 = V_4 -> V_9 + V_50 ;
int V_44 , V_25 ;
V_44 = F_19 ( V_2 , V_42 , V_43 ) ;
if ( V_44 < 0 )
return V_44 ;
* V_40 = V_44 ;
if ( V_4 -> V_47 && V_4 -> V_51 == V_44 )
return F_20 ( V_2 , 0 ) ;
if ( V_4 -> V_47 && V_4 -> V_52 == V_44 )
return F_20 ( V_2 , 1 ) ;
V_25 = F_6 ( V_5 , V_48 , V_53 , V_44 ) ;
if ( V_25 < 0 )
return V_25 ;
V_4 -> V_51 = V_44 ;
if ( ! V_4 -> V_47 )
return V_25 ;
V_25 = F_20 ( V_2 , 0 ) ;
if ( V_25 < 0 )
return V_25 ;
if ( V_44 > V_4 -> V_52 ) {
V_25 = F_6 ( V_5 , V_49 ,
V_54 ,
V_4 -> V_52 ) ;
if ( V_25 == 0 )
V_4 -> V_52 = V_44 ;
else
F_23 ( V_5 -> V_27 ,
L_4 , V_25 ) ;
}
return 0 ;
}
static int F_24 ( struct V_1 * V_2 ,
int V_55 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_5 * V_5 = V_4 -> V_5 ;
T_1 V_7 = V_4 -> V_9 + V_24 ;
int V_44 ;
V_44 = F_19 ( V_2 , V_55 , V_55 ) ;
if ( V_44 < 0 )
return V_44 ;
return F_6 ( V_5 , V_7 , V_56 , V_44 ) ;
}
static int F_25 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
if ( V_4 -> V_47 && V_4 -> V_46 )
return V_4 -> V_52 ;
else
return V_4 -> V_51 ;
}
static int F_26 ( struct V_1 * V_2 ,
int V_57 , int V_58 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_5 * V_5 = V_4 -> V_5 ;
T_1 V_7 = V_4 -> V_9 + V_59 ;
int V_60 ;
for ( V_60 = 0 ; V_60 < F_27 ( V_61 ) ; V_60 ++ ) {
if ( ( V_57 <= V_61 [ V_60 ] ) &&
( V_61 [ V_60 ] <= V_58 ) )
break;
}
if ( V_60 == F_27 ( V_61 ) )
return - V_22 ;
return F_6 ( V_5 , V_7 , V_62 ,
V_60 << V_63 ) ;
}
static int F_28 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_5 * V_5 = V_4 -> V_5 ;
T_1 V_7 = V_4 -> V_9 + V_59 ;
int V_11 ;
V_11 = F_4 ( V_5 , V_7 ) ;
if ( V_11 < 0 )
return V_11 ;
V_11 = ( V_11 & V_62 ) >> V_63 ;
return V_61 [ V_11 ] ;
}
static T_3 void F_29 ( struct V_3 * V_4 ,
struct V_64 * V_65 )
{
struct V_5 * V_5 = V_4 -> V_5 ;
int V_25 ;
T_1 V_66 ;
if ( ! V_65 || ! V_65 -> V_47 )
return;
V_25 = F_30 ( V_65 -> V_47 , L_5 ) ;
if ( V_25 < 0 ) {
F_31 ( V_5 -> V_27 , L_6 ,
V_4 -> V_67 , V_25 ) ;
return;
}
V_4 -> V_46 = V_65 -> V_68 ;
V_25 = F_32 ( V_65 -> V_47 , V_4 -> V_46 ) ;
if ( V_25 < 0 ) {
F_31 ( V_5 -> V_27 , L_7 ,
V_4 -> V_67 , V_25 ) ;
F_33 ( V_65 -> V_47 ) ;
return;
}
V_4 -> V_47 = V_65 -> V_47 ;
switch ( V_65 -> V_69 ) {
case 1 :
V_66 = 2 << V_70 ;
break;
case 2 :
V_66 = 3 << V_70 ;
break;
default:
F_31 ( V_5 -> V_27 , L_8 ,
V_65 -> V_69 , V_4 -> V_67 ) ;
return;
}
if ( ! V_4 -> V_52 ) {
V_25 = F_6 ( V_5 ,
V_4 -> V_9 + V_50 ,
V_54 , V_4 -> V_51 ) ;
if ( V_25 == 0 )
V_4 -> V_52 = V_4 -> V_51 ;
else
F_23 ( V_5 -> V_27 , L_9 ,
V_25 ) ;
}
V_25 = F_6 ( V_5 , V_4 -> V_9 + V_50 ,
V_71 , V_66 ) ;
if ( V_25 < 0 ) {
F_31 ( V_5 -> V_27 , L_10 ,
V_4 -> V_67 , V_25 ) ;
}
}
static T_3 int F_34 ( struct V_72 * V_73 )
{
struct V_5 * V_5 = F_35 ( V_73 -> V_27 . V_74 ) ;
struct V_75 * V_65 = V_5 -> V_27 -> V_76 ;
int V_77 ;
struct V_3 * V_4 ;
struct V_78 * V_79 ;
int V_25 , V_34 ;
if ( V_65 && V_65 -> V_80 )
V_77 = ( V_65 -> V_80 * 10 ) + 1 ;
else
V_77 = 0 ;
V_77 = V_73 -> V_77 - V_77 ;
F_14 ( & V_73 -> V_27 , L_11 , V_77 + 1 ) ;
if ( V_65 == NULL || V_65 -> V_4 [ V_77 ] == NULL )
return - V_81 ;
V_4 = F_36 ( & V_73 -> V_27 , sizeof( struct V_3 ) ,
V_82 ) ;
if ( V_4 == NULL ) {
F_31 ( & V_73 -> V_27 , L_12 ) ;
return - V_83 ;
}
V_4 -> V_5 = V_5 ;
V_79 = F_37 ( V_73 , V_84 , 0 ) ;
if ( V_79 == NULL ) {
F_31 ( & V_73 -> V_27 , L_13 ) ;
V_25 = - V_22 ;
goto V_85;
}
V_4 -> V_9 = V_79 -> V_86 ;
snprintf ( V_4 -> V_67 , sizeof( V_4 -> V_67 ) , L_14 , V_77 + 1 ) ;
V_4 -> V_87 . V_67 = V_4 -> V_67 ;
V_4 -> V_87 . V_77 = V_77 ;
V_4 -> V_87 . type = V_88 ;
V_4 -> V_87 . V_89 = V_41 + 1 ;
V_4 -> V_87 . V_90 = & V_91 ;
V_4 -> V_87 . V_92 = V_93 ;
V_25 = F_4 ( V_5 , V_4 -> V_9 + V_10 ) ;
if ( V_25 < 0 ) {
F_31 ( V_5 -> V_27 , L_15 , V_25 ) ;
goto V_85;
}
V_4 -> V_51 = V_25 & V_53 ;
V_25 = F_4 ( V_5 , V_4 -> V_9 + V_50 ) ;
if ( V_25 < 0 ) {
F_31 ( V_5 -> V_27 , L_16 , V_25 ) ;
goto V_85;
}
V_4 -> V_52 = V_25 & V_54 ;
if ( V_65 -> V_4 [ V_77 ] )
F_29 ( V_4 , V_65 -> V_4 [ V_77 ] -> V_94 ) ;
V_4 -> V_36 = F_38 ( & V_4 -> V_87 , & V_73 -> V_27 ,
V_65 -> V_4 [ V_77 ] , V_4 , NULL ) ;
if ( F_39 ( V_4 -> V_36 ) ) {
V_25 = F_40 ( V_4 -> V_36 ) ;
F_31 ( V_5 -> V_27 , L_17 ,
V_77 + 1 , V_25 ) ;
goto V_85;
}
V_34 = F_41 ( V_73 , L_18 ) ;
V_25 = F_42 ( V_34 , NULL , F_15 ,
V_95 , V_4 -> V_67 , V_4 ) ;
if ( V_25 != 0 ) {
F_31 ( & V_73 -> V_27 , L_19 ,
V_34 , V_25 ) ;
goto V_96;
}
V_34 = F_41 ( V_73 , L_20 ) ;
V_25 = F_42 ( V_34 , NULL , F_17 ,
V_95 , V_4 -> V_67 , V_4 ) ;
if ( V_25 != 0 ) {
F_31 ( & V_73 -> V_27 , L_21 ,
V_34 , V_25 ) ;
goto V_97;
}
F_43 ( V_73 , V_4 ) ;
return 0 ;
V_97:
F_44 ( F_41 ( V_73 , L_18 ) , V_4 ) ;
V_96:
F_45 ( V_4 -> V_36 ) ;
V_85:
if ( V_4 -> V_47 )
F_33 ( V_4 -> V_47 ) ;
return V_25 ;
}
static T_4 int F_46 ( struct V_72 * V_73 )
{
struct V_3 * V_4 = F_47 ( V_73 ) ;
F_43 ( V_73 , NULL ) ;
F_44 ( F_41 ( V_73 , L_20 ) , V_4 ) ;
F_44 ( F_41 ( V_73 , L_18 ) , V_4 ) ;
F_45 ( V_4 -> V_36 ) ;
if ( V_4 -> V_47 )
F_33 ( V_4 -> V_47 ) ;
return 0 ;
}
static int F_48 ( struct V_1 * V_2 ,
unsigned V_40 )
{
if ( V_40 <= V_98 )
return 850000 + ( V_40 * 25000 ) ;
else
return - V_22 ;
}
static int F_49 ( struct V_1 * V_2 , int V_7 ,
int V_42 , int V_43 , int * V_40 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_5 * V_5 = V_4 -> V_5 ;
T_1 V_44 ;
if ( V_42 <= 34000000 )
V_44 = ( V_42 - 850000 ) / 25000 ;
else
return - V_22 ;
if ( F_48 ( V_2 , V_44 ) > V_43 )
return - V_22 ;
* V_40 = V_44 ;
return F_6 ( V_5 , V_7 , V_99 , V_44 ) ;
}
static int F_50 ( struct V_1 * V_2 ,
int V_42 , int V_43 ,
unsigned * V_40 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
T_1 V_7 = V_4 -> V_9 + V_10 ;
return F_49 ( V_2 , V_7 , V_42 , V_43 ,
V_40 ) ;
}
static int F_51 ( struct V_1 * V_2 ,
int V_55 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
T_1 V_7 = V_4 -> V_9 + V_24 ;
unsigned V_40 ;
return F_49 ( V_2 , V_7 , V_55 , V_55 , & V_40 ) ;
}
static int F_52 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_5 * V_5 = V_4 -> V_5 ;
T_1 V_7 = V_4 -> V_9 + V_10 ;
int V_11 ;
V_11 = F_4 ( V_5 , V_7 ) ;
if ( V_11 < 0 )
return V_11 ;
return V_11 & V_99 ;
}
static T_3 int F_53 ( struct V_72 * V_73 )
{
struct V_5 * V_5 = F_35 ( V_73 -> V_27 . V_74 ) ;
struct V_75 * V_65 = V_5 -> V_27 -> V_76 ;
int V_77 ;
struct V_3 * V_4 ;
struct V_78 * V_79 ;
int V_25 , V_34 ;
if ( V_65 && V_65 -> V_80 )
V_77 = ( V_65 -> V_80 * 10 ) + 1 ;
else
V_77 = 0 ;
V_77 = V_73 -> V_77 - V_77 ;
F_14 ( & V_73 -> V_27 , L_11 , V_77 + 1 ) ;
if ( V_65 == NULL || V_65 -> V_4 [ V_77 ] == NULL )
return - V_81 ;
V_4 = F_36 ( & V_73 -> V_27 , sizeof( struct V_3 ) ,
V_82 ) ;
if ( V_4 == NULL ) {
F_31 ( & V_73 -> V_27 , L_12 ) ;
return - V_83 ;
}
V_4 -> V_5 = V_5 ;
V_79 = F_37 ( V_73 , V_84 , 0 ) ;
if ( V_79 == NULL ) {
F_31 ( & V_73 -> V_27 , L_13 ) ;
V_25 = - V_22 ;
goto V_85;
}
V_4 -> V_9 = V_79 -> V_86 ;
snprintf ( V_4 -> V_67 , sizeof( V_4 -> V_67 ) , L_14 , V_77 + 1 ) ;
V_4 -> V_87 . V_67 = V_4 -> V_67 ;
V_4 -> V_87 . V_77 = V_77 ;
V_4 -> V_87 . type = V_88 ;
V_4 -> V_87 . V_89 = V_98 + 1 ;
V_4 -> V_87 . V_90 = & V_100 ;
V_4 -> V_87 . V_92 = V_93 ;
V_4 -> V_36 = F_38 ( & V_4 -> V_87 , & V_73 -> V_27 ,
V_65 -> V_4 [ V_77 ] , V_4 , NULL ) ;
if ( F_39 ( V_4 -> V_36 ) ) {
V_25 = F_40 ( V_4 -> V_36 ) ;
F_31 ( V_5 -> V_27 , L_17 ,
V_77 + 1 , V_25 ) ;
goto V_85;
}
V_34 = F_41 ( V_73 , L_18 ) ;
V_25 = F_42 ( V_34 , NULL , F_15 ,
V_95 , V_4 -> V_67 , V_4 ) ;
if ( V_25 != 0 ) {
F_31 ( & V_73 -> V_27 , L_19 ,
V_34 , V_25 ) ;
goto V_96;
}
F_43 ( V_73 , V_4 ) ;
return 0 ;
V_96:
F_45 ( V_4 -> V_36 ) ;
V_85:
return V_25 ;
}
static T_4 int F_54 ( struct V_72 * V_73 )
{
struct V_3 * V_4 = F_47 ( V_73 ) ;
F_43 ( V_73 , NULL ) ;
F_44 ( F_41 ( V_73 , L_18 ) , V_4 ) ;
F_45 ( V_4 -> V_36 ) ;
return 0 ;
}
static int F_55 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_5 * V_5 = V_4 -> V_5 ;
int V_25 ;
V_25 = F_4 ( V_5 , V_26 ) ;
if ( V_25 < 0 )
return V_25 ;
if ( V_25 & ( 1 << F_3 ( V_2 ) ) ) {
F_14 ( V_5 -> V_27 , L_1 ,
F_3 ( V_2 ) + 1 ) ;
return V_28 ;
}
V_25 = F_4 ( V_5 , V_31 ) ;
if ( V_25 < 0 )
return V_25 ;
if ( V_25 & ( 1 << F_3 ( V_2 ) ) )
return V_33 ;
else
return V_32 ;
}
static T_3 int F_56 ( struct V_72 * V_73 )
{
struct V_5 * V_5 = F_35 ( V_73 -> V_27 . V_74 ) ;
struct V_75 * V_65 = V_5 -> V_27 -> V_76 ;
int V_77 = V_73 -> V_77 % F_27 ( V_65 -> V_4 ) ;
struct V_3 * V_4 ;
struct V_78 * V_79 ;
int V_25 , V_34 ;
F_14 ( & V_73 -> V_27 , L_11 , V_77 + 1 ) ;
if ( V_65 == NULL || V_65 -> V_4 [ V_77 ] == NULL )
return - V_81 ;
V_4 = F_57 ( sizeof( struct V_3 ) , V_82 ) ;
if ( V_4 == NULL ) {
F_31 ( & V_73 -> V_27 , L_12 ) ;
return - V_83 ;
}
V_4 -> V_5 = V_5 ;
V_79 = F_37 ( V_73 , V_84 , 0 ) ;
if ( V_79 == NULL ) {
F_31 ( & V_73 -> V_27 , L_13 ) ;
V_25 = - V_22 ;
goto V_85;
}
V_4 -> V_9 = V_79 -> V_86 ;
snprintf ( V_4 -> V_67 , sizeof( V_4 -> V_67 ) , L_14 , V_77 + 1 ) ;
V_4 -> V_87 . V_67 = V_4 -> V_67 ;
V_4 -> V_87 . V_77 = V_77 ;
V_4 -> V_87 . type = V_88 ;
V_4 -> V_87 . V_90 = & V_101 ;
V_4 -> V_87 . V_92 = V_93 ;
V_4 -> V_36 = F_38 ( & V_4 -> V_87 , & V_73 -> V_27 ,
V_65 -> V_4 [ V_77 ] , V_4 , NULL ) ;
if ( F_39 ( V_4 -> V_36 ) ) {
V_25 = F_40 ( V_4 -> V_36 ) ;
F_31 ( V_5 -> V_27 , L_17 ,
V_77 + 1 , V_25 ) ;
goto V_85;
}
V_34 = F_41 ( V_73 , L_18 ) ;
V_25 = F_42 ( V_34 , NULL , F_15 ,
V_95 , V_4 -> V_67 ,
V_4 ) ;
if ( V_25 != 0 ) {
F_31 ( & V_73 -> V_27 , L_19 ,
V_34 , V_25 ) ;
goto V_96;
}
F_43 ( V_73 , V_4 ) ;
return 0 ;
V_96:
F_45 ( V_4 -> V_36 ) ;
V_85:
F_58 ( V_4 ) ;
return V_25 ;
}
static T_4 int F_59 ( struct V_72 * V_73 )
{
struct V_3 * V_4 = F_47 ( V_73 ) ;
F_43 ( V_73 , NULL ) ;
F_44 ( F_41 ( V_73 , L_18 ) , V_4 ) ;
F_45 ( V_4 -> V_36 ) ;
F_58 ( V_4 ) ;
return 0 ;
}
static T_3 int F_60 ( struct V_72 * V_73 )
{
struct V_5 * V_5 = F_35 ( V_73 -> V_27 . V_74 ) ;
struct V_75 * V_65 = V_5 -> V_27 -> V_76 ;
int V_77 = V_73 -> V_77 % F_27 ( V_65 -> V_102 ) ;
struct V_3 * V_4 ;
int V_25 ;
F_14 ( & V_73 -> V_27 , L_22 , V_77 + 1 ) ;
if ( V_65 == NULL || V_65 -> V_102 [ V_77 ] == NULL )
return - V_81 ;
V_4 = F_57 ( sizeof( struct V_3 ) , V_82 ) ;
if ( V_4 == NULL ) {
F_31 ( & V_73 -> V_27 , L_12 ) ;
return - V_83 ;
}
V_4 -> V_5 = V_5 ;
snprintf ( V_4 -> V_67 , sizeof( V_4 -> V_67 ) , L_23 , V_77 + 1 ) ;
V_4 -> V_87 . V_67 = V_4 -> V_67 ;
V_4 -> V_87 . V_77 = V_77 + V_103 ;
V_4 -> V_87 . V_90 = & V_104 ;
V_4 -> V_87 . type = V_88 ;
V_4 -> V_87 . V_92 = V_93 ;
V_4 -> V_36 = F_38 ( & V_4 -> V_87 , & V_73 -> V_27 ,
V_65 -> V_102 [ V_77 ] , V_4 , NULL ) ;
if ( F_39 ( V_4 -> V_36 ) ) {
V_25 = F_40 ( V_4 -> V_36 ) ;
F_31 ( V_5 -> V_27 , L_24 ,
V_77 + 1 , V_25 ) ;
goto V_85;
}
F_43 ( V_73 , V_4 ) ;
return 0 ;
V_85:
F_58 ( V_4 ) ;
return V_25 ;
}
static T_4 int F_61 ( struct V_72 * V_73 )
{
struct V_3 * V_4 = F_47 ( V_73 ) ;
F_43 ( V_73 , NULL ) ;
F_45 ( V_4 -> V_36 ) ;
F_58 ( V_4 ) ;
return 0 ;
}
static int T_5 F_62 ( void )
{
int V_25 ;
V_25 = F_63 ( & V_105 ) ;
if ( V_25 != 0 )
F_64 ( L_25 , V_25 ) ;
V_25 = F_63 ( & V_106 ) ;
if ( V_25 != 0 )
F_64 ( L_26 , V_25 ) ;
V_25 = F_63 ( & V_107 ) ;
if ( V_25 != 0 )
F_64 ( L_27 , V_25 ) ;
V_25 = F_63 ( & V_108 ) ;
if ( V_25 != 0 )
F_64 ( L_28 , V_25 ) ;
return 0 ;
}
static void T_6 F_65 ( void )
{
F_66 ( & V_108 ) ;
F_66 ( & V_107 ) ;
F_66 ( & V_106 ) ;
F_66 ( & V_105 ) ;
}
