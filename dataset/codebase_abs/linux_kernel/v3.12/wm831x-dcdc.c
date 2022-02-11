static unsigned int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_5 * V_5 = V_4 -> V_5 ;
T_1 V_6 = V_4 -> V_7 + V_8 ;
int V_9 ;
V_9 = F_3 ( V_5 , V_6 ) ;
if ( V_9 < 0 )
return V_9 ;
V_9 = ( V_9 & V_10 ) >> V_11 ;
switch ( V_9 ) {
case V_12 :
return V_13 ;
case V_14 :
return V_15 ;
case V_16 :
return V_17 ;
case V_18 :
return V_19 ;
default:
F_4 () ;
return - V_20 ;
}
}
static int F_5 ( struct V_5 * V_5 , int V_6 ,
unsigned int V_21 )
{
int V_9 ;
switch ( V_21 ) {
case V_13 :
V_9 = V_12 ;
break;
case V_15 :
V_9 = V_14 ;
break;
case V_17 :
V_9 = V_16 ;
break;
case V_19 :
V_9 = V_18 ;
break;
default:
return - V_20 ;
}
return F_6 ( V_5 , V_6 , V_10 ,
V_9 << V_11 ) ;
}
static int F_7 ( struct V_1 * V_2 , unsigned int V_21 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_5 * V_5 = V_4 -> V_5 ;
T_1 V_6 = V_4 -> V_7 + V_8 ;
return F_5 ( V_5 , V_6 , V_21 ) ;
}
static int F_8 ( struct V_1 * V_2 ,
unsigned int V_21 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_5 * V_5 = V_4 -> V_5 ;
T_1 V_6 = V_4 -> V_7 + V_22 ;
return F_5 ( V_5 , V_6 , V_21 ) ;
}
static int F_9 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_5 * V_5 = V_4 -> V_5 ;
int V_23 ;
V_23 = F_3 ( V_5 , V_24 ) ;
if ( V_23 < 0 )
return V_23 ;
if ( V_23 & ( 1 << F_10 ( V_2 ) ) ) {
F_11 ( V_5 -> V_25 , L_1 ,
F_10 ( V_2 ) + 1 ) ;
return V_26 ;
}
if ( F_10 ( V_2 ) < 2 ) {
if ( V_23 & ( V_27 << F_10 ( V_2 ) ) ) {
F_11 ( V_5 -> V_25 , L_2 ,
F_10 ( V_2 ) + 1 ) ;
return V_26 ;
}
if ( V_23 & ( V_28 << F_10 ( V_2 ) ) ) {
F_11 ( V_5 -> V_25 , L_3 ,
F_10 ( V_2 ) + 1 ) ;
return V_26 ;
}
}
V_23 = F_3 ( V_5 , V_29 ) ;
if ( V_23 < 0 )
return V_23 ;
if ( ! ( V_23 & ( 1 << F_10 ( V_2 ) ) ) )
return V_30 ;
return V_31 ;
}
static T_2 F_12 ( int V_32 , void * V_33 )
{
struct V_3 * V_4 = V_33 ;
F_13 ( V_4 -> V_34 ,
V_35 ,
NULL ) ;
return V_36 ;
}
static T_2 F_14 ( int V_32 , void * V_33 )
{
struct V_3 * V_4 = V_33 ;
F_13 ( V_4 -> V_34 ,
V_37 ,
NULL ) ;
return V_36 ;
}
static int F_15 ( struct V_1 * V_2 ,
unsigned V_38 )
{
if ( V_38 <= 0x8 )
return 600000 ;
if ( V_38 <= V_39 )
return 600000 + ( ( V_38 - 0x8 ) * 12500 ) ;
return - V_20 ;
}
static int F_16 ( struct V_1 * V_2 ,
int V_40 , int V_41 )
{
T_1 V_42 ;
if ( V_40 < 600000 )
V_42 = 0 ;
else if ( V_40 <= 1800000 )
V_42 = F_17 ( V_40 - 600000 , 12500 ) + 8 ;
else
return - V_20 ;
if ( F_15 ( V_2 , V_42 ) > V_41 )
return - V_20 ;
return V_42 ;
}
static int F_18 ( struct V_1 * V_2 , int V_43 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
if ( V_43 == V_4 -> V_44 )
return 0 ;
V_4 -> V_44 = V_43 ;
F_19 ( V_4 -> V_45 , V_43 ) ;
return 0 ;
}
static int F_20 ( struct V_1 * V_2 ,
unsigned V_42 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_5 * V_5 = V_4 -> V_5 ;
int V_46 = V_4 -> V_7 + V_8 ;
int V_47 = V_4 -> V_7 + V_48 ;
int V_23 ;
if ( V_4 -> V_45 && V_4 -> V_49 == V_42 )
return F_18 ( V_2 , 0 ) ;
if ( V_4 -> V_45 && V_4 -> V_50 == V_42 )
return F_18 ( V_2 , 1 ) ;
V_23 = F_6 ( V_5 , V_46 , V_51 , V_42 ) ;
if ( V_23 < 0 )
return V_23 ;
V_4 -> V_49 = V_42 ;
if ( ! V_4 -> V_45 )
return V_23 ;
V_23 = F_18 ( V_2 , 0 ) ;
if ( V_23 < 0 )
return V_23 ;
if ( V_42 > V_4 -> V_50 ) {
V_23 = F_6 ( V_5 , V_47 ,
V_52 ,
V_42 ) ;
if ( V_23 == 0 )
V_4 -> V_50 = V_42 ;
else
F_21 ( V_5 -> V_25 ,
L_4 , V_23 ) ;
}
return 0 ;
}
static int F_22 ( struct V_1 * V_2 ,
int V_53 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_5 * V_5 = V_4 -> V_5 ;
T_1 V_6 = V_4 -> V_7 + V_22 ;
int V_42 ;
V_42 = F_16 ( V_2 , V_53 , V_53 ) ;
if ( V_42 < 0 )
return V_42 ;
return F_6 ( V_5 , V_6 , V_54 , V_42 ) ;
}
static int F_23 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
if ( V_4 -> V_45 && V_4 -> V_44 )
return V_4 -> V_50 ;
else
return V_4 -> V_49 ;
}
static int F_24 ( struct V_1 * V_2 ,
int V_55 , int V_56 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_5 * V_5 = V_4 -> V_5 ;
T_1 V_6 = V_4 -> V_7 + V_57 ;
int V_58 ;
for ( V_58 = F_25 ( V_59 ) - 1 ; V_58 >= 0 ; V_58 -- ) {
if ( ( V_55 <= V_59 [ V_58 ] ) &&
( V_59 [ V_58 ] <= V_56 ) )
return F_6 ( V_5 , V_6 ,
V_60 ,
V_58 << V_61 ) ;
}
return - V_20 ;
}
static int F_26 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_5 * V_5 = V_4 -> V_5 ;
T_1 V_6 = V_4 -> V_7 + V_57 ;
int V_9 ;
V_9 = F_3 ( V_5 , V_6 ) ;
if ( V_9 < 0 )
return V_9 ;
V_9 = ( V_9 & V_60 ) >> V_61 ;
return V_59 [ V_9 ] ;
}
static void F_27 ( struct V_3 * V_4 ,
struct V_62 * V_63 )
{
struct V_5 * V_5 = V_4 -> V_5 ;
int V_23 ;
T_1 V_64 ;
if ( ! V_63 || ! V_63 -> V_45 )
return;
V_4 -> V_44 = V_63 -> V_65 ;
V_23 = F_28 ( V_63 -> V_45 ,
V_4 -> V_44 ? V_66 : 0 ,
L_5 ) ;
if ( V_23 < 0 ) {
F_29 ( V_5 -> V_25 , L_6 ,
V_4 -> V_67 , V_23 ) ;
return;
}
V_4 -> V_45 = V_63 -> V_45 ;
switch ( V_63 -> V_68 ) {
case 1 :
V_64 = 2 << V_69 ;
break;
case 2 :
V_64 = 3 << V_69 ;
break;
default:
F_29 ( V_5 -> V_25 , L_7 ,
V_63 -> V_68 , V_4 -> V_67 ) ;
return;
}
if ( ! V_4 -> V_50 ) {
V_23 = F_6 ( V_5 ,
V_4 -> V_7 + V_48 ,
V_52 , V_4 -> V_49 ) ;
if ( V_23 == 0 )
V_4 -> V_50 = V_4 -> V_49 ;
else
F_21 ( V_5 -> V_25 , L_8 ,
V_23 ) ;
}
V_23 = F_6 ( V_5 , V_4 -> V_7 + V_48 ,
V_70 , V_64 ) ;
if ( V_23 < 0 ) {
F_29 ( V_5 -> V_25 , L_9 ,
V_4 -> V_67 , V_23 ) ;
}
}
static int F_30 ( struct V_71 * V_72 )
{
struct V_5 * V_5 = F_31 ( V_72 -> V_25 . V_73 ) ;
struct V_74 * V_63 = F_32 ( V_5 -> V_25 ) ;
struct V_75 V_76 = { } ;
int V_77 ;
struct V_3 * V_4 ;
struct V_78 * V_79 ;
int V_23 , V_32 ;
if ( V_63 && V_63 -> V_80 )
V_77 = ( V_63 -> V_80 * 10 ) + 1 ;
else
V_77 = 0 ;
V_77 = V_72 -> V_77 - V_77 ;
F_11 ( & V_72 -> V_25 , L_10 , V_77 + 1 ) ;
V_4 = F_33 ( & V_72 -> V_25 , sizeof( struct V_3 ) ,
V_81 ) ;
if ( V_4 == NULL ) {
F_29 ( & V_72 -> V_25 , L_11 ) ;
return - V_82 ;
}
V_4 -> V_5 = V_5 ;
V_79 = F_34 ( V_72 , V_83 , 0 ) ;
if ( V_79 == NULL ) {
F_29 ( & V_72 -> V_25 , L_12 ) ;
V_23 = - V_20 ;
goto V_84;
}
V_4 -> V_7 = V_79 -> V_85 ;
snprintf ( V_4 -> V_67 , sizeof( V_4 -> V_67 ) , L_13 , V_77 + 1 ) ;
V_4 -> V_86 . V_67 = V_4 -> V_67 ;
snprintf ( V_4 -> V_87 , sizeof( V_4 -> V_87 ) ,
L_14 , V_77 + 1 ) ;
V_4 -> V_86 . V_87 = V_4 -> V_87 ;
V_4 -> V_86 . V_77 = V_77 ;
V_4 -> V_86 . type = V_88 ;
V_4 -> V_86 . V_89 = V_39 + 1 ;
V_4 -> V_86 . V_90 = & V_91 ;
V_4 -> V_86 . V_92 = V_93 ;
V_4 -> V_86 . V_94 = V_95 ;
V_4 -> V_86 . V_96 = 1 << V_77 ;
V_23 = F_3 ( V_5 , V_4 -> V_7 + V_8 ) ;
if ( V_23 < 0 ) {
F_29 ( V_5 -> V_25 , L_15 , V_23 ) ;
goto V_84;
}
V_4 -> V_49 = V_23 & V_51 ;
V_23 = F_3 ( V_5 , V_4 -> V_7 + V_48 ) ;
if ( V_23 < 0 ) {
F_29 ( V_5 -> V_25 , L_16 , V_23 ) ;
goto V_84;
}
V_4 -> V_50 = V_23 & V_52 ;
if ( V_63 && V_63 -> V_4 [ V_77 ] )
F_27 ( V_4 , V_63 -> V_4 [ V_77 ] -> V_97 ) ;
V_76 . V_25 = V_72 -> V_25 . V_73 ;
if ( V_63 )
V_76 . V_98 = V_63 -> V_4 [ V_77 ] ;
V_76 . V_97 = V_4 ;
V_76 . V_99 = V_5 -> V_99 ;
V_4 -> V_34 = F_35 ( & V_4 -> V_86 , & V_76 ) ;
if ( F_36 ( V_4 -> V_34 ) ) {
V_23 = F_37 ( V_4 -> V_34 ) ;
F_29 ( V_5 -> V_25 , L_17 ,
V_77 + 1 , V_23 ) ;
goto V_84;
}
V_32 = F_38 ( V_5 , F_39 ( V_72 , L_18 ) ) ;
V_23 = F_40 ( V_32 , NULL , F_12 ,
V_100 , V_4 -> V_67 , V_4 ) ;
if ( V_23 != 0 ) {
F_29 ( & V_72 -> V_25 , L_19 ,
V_32 , V_23 ) ;
goto V_101;
}
V_32 = F_38 ( V_5 , F_39 ( V_72 , L_20 ) ) ;
V_23 = F_40 ( V_32 , NULL , F_14 ,
V_100 , V_4 -> V_67 , V_4 ) ;
if ( V_23 != 0 ) {
F_29 ( & V_72 -> V_25 , L_21 ,
V_32 , V_23 ) ;
goto V_102;
}
F_41 ( V_72 , V_4 ) ;
return 0 ;
V_102:
F_42 ( F_38 ( V_5 , F_39 ( V_72 , L_18 ) ) ,
V_4 ) ;
V_101:
F_43 ( V_4 -> V_34 ) ;
V_84:
if ( V_4 -> V_45 )
F_44 ( V_4 -> V_45 ) ;
return V_23 ;
}
static int F_45 ( struct V_71 * V_72 )
{
struct V_3 * V_4 = F_46 ( V_72 ) ;
struct V_5 * V_5 = V_4 -> V_5 ;
F_42 ( F_38 ( V_5 , F_39 ( V_72 , L_20 ) ) ,
V_4 ) ;
F_42 ( F_38 ( V_5 , F_39 ( V_72 , L_18 ) ) ,
V_4 ) ;
F_43 ( V_4 -> V_34 ) ;
if ( V_4 -> V_45 )
F_44 ( V_4 -> V_45 ) ;
return 0 ;
}
static int F_47 ( struct V_1 * V_2 , int V_53 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_5 * V_5 = V_4 -> V_5 ;
T_1 V_6 = V_4 -> V_7 + V_22 ;
int V_103 ;
V_103 = F_48 ( V_2 , V_53 , V_53 ) ;
if ( V_103 < 0 )
return V_103 ;
return F_6 ( V_5 , V_6 , V_104 , V_103 ) ;
}
static int F_49 ( struct V_71 * V_72 )
{
struct V_5 * V_5 = F_31 ( V_72 -> V_25 . V_73 ) ;
struct V_74 * V_63 = F_32 ( V_5 -> V_25 ) ;
struct V_75 V_76 = { } ;
int V_77 ;
struct V_3 * V_4 ;
struct V_78 * V_79 ;
int V_23 , V_32 ;
if ( V_63 && V_63 -> V_80 )
V_77 = ( V_63 -> V_80 * 10 ) + 1 ;
else
V_77 = 0 ;
V_77 = V_72 -> V_77 - V_77 ;
F_11 ( & V_72 -> V_25 , L_10 , V_77 + 1 ) ;
V_4 = F_33 ( & V_72 -> V_25 , sizeof( struct V_3 ) ,
V_81 ) ;
if ( V_4 == NULL ) {
F_29 ( & V_72 -> V_25 , L_11 ) ;
return - V_82 ;
}
V_4 -> V_5 = V_5 ;
V_79 = F_34 ( V_72 , V_83 , 0 ) ;
if ( V_79 == NULL ) {
F_29 ( & V_72 -> V_25 , L_12 ) ;
V_23 = - V_20 ;
goto V_84;
}
V_4 -> V_7 = V_79 -> V_85 ;
snprintf ( V_4 -> V_67 , sizeof( V_4 -> V_67 ) , L_13 , V_77 + 1 ) ;
V_4 -> V_86 . V_67 = V_4 -> V_67 ;
snprintf ( V_4 -> V_87 , sizeof( V_4 -> V_87 ) ,
L_14 , V_77 + 1 ) ;
V_4 -> V_86 . V_87 = V_4 -> V_87 ;
V_4 -> V_86 . V_77 = V_77 ;
V_4 -> V_86 . type = V_88 ;
V_4 -> V_86 . V_89 = V_105 + 1 ;
V_4 -> V_86 . V_90 = & V_106 ;
V_4 -> V_86 . V_92 = V_93 ;
V_4 -> V_86 . V_107 = V_4 -> V_7 + V_8 ;
V_4 -> V_86 . V_108 = V_104 ;
V_4 -> V_86 . V_94 = V_95 ;
V_4 -> V_86 . V_96 = 1 << V_77 ;
V_4 -> V_86 . V_40 = 850000 ;
V_4 -> V_86 . V_109 = 25000 ;
V_76 . V_25 = V_72 -> V_25 . V_73 ;
if ( V_63 )
V_76 . V_98 = V_63 -> V_4 [ V_77 ] ;
V_76 . V_97 = V_4 ;
V_76 . V_99 = V_5 -> V_99 ;
V_4 -> V_34 = F_35 ( & V_4 -> V_86 , & V_76 ) ;
if ( F_36 ( V_4 -> V_34 ) ) {
V_23 = F_37 ( V_4 -> V_34 ) ;
F_29 ( V_5 -> V_25 , L_17 ,
V_77 + 1 , V_23 ) ;
goto V_84;
}
V_32 = F_38 ( V_5 , F_39 ( V_72 , L_18 ) ) ;
V_23 = F_40 ( V_32 , NULL , F_12 ,
V_100 , V_4 -> V_67 , V_4 ) ;
if ( V_23 != 0 ) {
F_29 ( & V_72 -> V_25 , L_19 ,
V_32 , V_23 ) ;
goto V_101;
}
F_41 ( V_72 , V_4 ) ;
return 0 ;
V_101:
F_43 ( V_4 -> V_34 ) ;
V_84:
return V_23 ;
}
static int F_50 ( struct V_71 * V_72 )
{
struct V_3 * V_4 = F_46 ( V_72 ) ;
F_42 ( F_38 ( V_4 -> V_5 , F_39 ( V_72 , L_18 ) ) ,
V_4 ) ;
F_43 ( V_4 -> V_34 ) ;
return 0 ;
}
static int F_51 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_5 * V_5 = V_4 -> V_5 ;
int V_23 ;
V_23 = F_3 ( V_5 , V_24 ) ;
if ( V_23 < 0 )
return V_23 ;
if ( V_23 & ( 1 << F_10 ( V_2 ) ) ) {
F_11 ( V_5 -> V_25 , L_1 ,
F_10 ( V_2 ) + 1 ) ;
return V_26 ;
}
V_23 = F_3 ( V_5 , V_29 ) ;
if ( V_23 < 0 )
return V_23 ;
if ( V_23 & ( 1 << F_10 ( V_2 ) ) )
return V_31 ;
else
return V_30 ;
}
static int F_52 ( struct V_71 * V_72 )
{
struct V_5 * V_5 = F_31 ( V_72 -> V_25 . V_73 ) ;
struct V_74 * V_63 = F_32 ( V_5 -> V_25 ) ;
struct V_75 V_76 = { } ;
int V_77 = V_72 -> V_77 % F_25 ( V_63 -> V_4 ) ;
struct V_3 * V_4 ;
struct V_78 * V_79 ;
int V_23 , V_32 ;
F_11 ( & V_72 -> V_25 , L_10 , V_77 + 1 ) ;
if ( V_63 == NULL || V_63 -> V_4 [ V_77 ] == NULL )
return - V_110 ;
V_4 = F_33 ( & V_72 -> V_25 , sizeof( struct V_3 ) , V_81 ) ;
if ( V_4 == NULL ) {
F_29 ( & V_72 -> V_25 , L_11 ) ;
return - V_82 ;
}
V_4 -> V_5 = V_5 ;
V_79 = F_34 ( V_72 , V_83 , 0 ) ;
if ( V_79 == NULL ) {
F_29 ( & V_72 -> V_25 , L_12 ) ;
V_23 = - V_20 ;
goto V_84;
}
V_4 -> V_7 = V_79 -> V_85 ;
snprintf ( V_4 -> V_67 , sizeof( V_4 -> V_67 ) , L_13 , V_77 + 1 ) ;
V_4 -> V_86 . V_67 = V_4 -> V_67 ;
V_4 -> V_86 . V_77 = V_77 ;
V_4 -> V_86 . type = V_88 ;
V_4 -> V_86 . V_90 = & V_111 ;
V_4 -> V_86 . V_92 = V_93 ;
V_4 -> V_86 . V_94 = V_95 ;
V_4 -> V_86 . V_96 = 1 << V_77 ;
V_76 . V_25 = V_72 -> V_25 . V_73 ;
if ( V_63 )
V_76 . V_98 = V_63 -> V_4 [ V_77 ] ;
V_76 . V_97 = V_4 ;
V_76 . V_99 = V_5 -> V_99 ;
V_4 -> V_34 = F_35 ( & V_4 -> V_86 , & V_76 ) ;
if ( F_36 ( V_4 -> V_34 ) ) {
V_23 = F_37 ( V_4 -> V_34 ) ;
F_29 ( V_5 -> V_25 , L_17 ,
V_77 + 1 , V_23 ) ;
goto V_84;
}
V_32 = F_38 ( V_5 , F_39 ( V_72 , L_18 ) ) ;
V_23 = F_40 ( V_32 , NULL , F_12 ,
V_100 , V_4 -> V_67 ,
V_4 ) ;
if ( V_23 != 0 ) {
F_29 ( & V_72 -> V_25 , L_19 ,
V_32 , V_23 ) ;
goto V_101;
}
F_41 ( V_72 , V_4 ) ;
return 0 ;
V_101:
F_43 ( V_4 -> V_34 ) ;
V_84:
return V_23 ;
}
static int F_53 ( struct V_71 * V_72 )
{
struct V_3 * V_4 = F_46 ( V_72 ) ;
F_42 ( F_38 ( V_4 -> V_5 , F_39 ( V_72 , L_18 ) ) ,
V_4 ) ;
F_43 ( V_4 -> V_34 ) ;
return 0 ;
}
static int F_54 ( struct V_71 * V_72 )
{
struct V_5 * V_5 = F_31 ( V_72 -> V_25 . V_73 ) ;
struct V_74 * V_63 = F_32 ( V_5 -> V_25 ) ;
struct V_75 V_76 = { } ;
int V_77 = V_72 -> V_77 % F_25 ( V_63 -> V_112 ) ;
struct V_3 * V_4 ;
int V_23 ;
F_11 ( & V_72 -> V_25 , L_22 , V_77 + 1 ) ;
V_4 = F_33 ( & V_72 -> V_25 , sizeof( struct V_3 ) , V_81 ) ;
if ( V_4 == NULL ) {
F_29 ( & V_72 -> V_25 , L_11 ) ;
return - V_82 ;
}
V_4 -> V_5 = V_5 ;
snprintf ( V_4 -> V_67 , sizeof( V_4 -> V_67 ) , L_23 , V_77 + 1 ) ;
V_4 -> V_86 . V_67 = V_4 -> V_67 ;
V_4 -> V_86 . V_77 = V_77 + V_113 ;
V_4 -> V_86 . V_90 = & V_114 ;
V_4 -> V_86 . type = V_88 ;
V_4 -> V_86 . V_92 = V_93 ;
V_4 -> V_86 . V_94 = V_95 ;
V_4 -> V_86 . V_96 = 1 << V_4 -> V_86 . V_77 ;
V_76 . V_25 = V_72 -> V_25 . V_73 ;
if ( V_63 )
V_76 . V_98 = V_63 -> V_112 [ V_77 ] ;
V_76 . V_97 = V_4 ;
V_76 . V_99 = V_5 -> V_99 ;
V_4 -> V_34 = F_35 ( & V_4 -> V_86 , & V_76 ) ;
if ( F_36 ( V_4 -> V_34 ) ) {
V_23 = F_37 ( V_4 -> V_34 ) ;
F_29 ( V_5 -> V_25 , L_24 ,
V_77 + 1 , V_23 ) ;
goto V_84;
}
F_41 ( V_72 , V_4 ) ;
return 0 ;
V_84:
return V_23 ;
}
static int F_55 ( struct V_71 * V_72 )
{
struct V_3 * V_4 = F_46 ( V_72 ) ;
F_43 ( V_4 -> V_34 ) ;
return 0 ;
}
static int T_3 F_56 ( void )
{
int V_23 ;
V_23 = F_57 ( & V_115 ) ;
if ( V_23 != 0 )
F_58 ( L_25 , V_23 ) ;
V_23 = F_57 ( & V_116 ) ;
if ( V_23 != 0 )
F_58 ( L_26 , V_23 ) ;
V_23 = F_57 ( & V_117 ) ;
if ( V_23 != 0 )
F_58 ( L_27 , V_23 ) ;
V_23 = F_57 ( & V_118 ) ;
if ( V_23 != 0 )
F_58 ( L_28 , V_23 ) ;
return 0 ;
}
static void T_4 F_59 ( void )
{
F_60 ( & V_118 ) ;
F_60 ( & V_117 ) ;
F_60 ( & V_116 ) ;
F_60 ( & V_115 ) ;
}
