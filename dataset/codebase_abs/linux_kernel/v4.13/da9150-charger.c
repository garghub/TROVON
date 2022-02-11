static inline int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
union V_5 * V_6 )
{
V_6 -> V_7 = ( V_4 == V_2 -> V_8 ) ? 1 : 0 ;
return 0 ;
}
static int F_2 ( struct V_1 * V_2 ,
union V_5 * V_6 )
{
int V_9 , V_10 ;
V_10 = F_3 ( V_2 -> V_11 , & V_9 ) ;
if ( V_10 < 0 )
return V_10 ;
V_6 -> V_7 = V_9 * 1000 ;
return 0 ;
}
static int F_4 ( struct V_1 * V_2 ,
union V_5 * V_6 )
{
int V_12 , V_10 ;
V_10 = F_3 ( V_2 -> V_13 , & V_12 ) ;
if ( V_10 < 0 )
return V_10 ;
V_6 -> V_7 = V_12 * 1000 ;
return 0 ;
}
static int F_5 ( struct V_1 * V_2 ,
union V_5 * V_6 )
{
int V_14 , V_10 ;
V_10 = F_3 ( V_2 -> V_15 , & V_14 ) ;
if ( V_10 < 0 )
return V_10 ;
V_6 -> V_7 = V_14 / 100 ;
return 0 ;
}
static int F_6 ( struct V_3 * V_4 ,
enum V_16 V_17 ,
union V_5 * V_6 )
{
struct V_1 * V_2 = F_7 ( V_4 -> V_18 . V_19 ) ;
int V_10 ;
switch ( V_17 ) {
case V_20 :
V_10 = F_1 ( V_2 , V_4 , V_6 ) ;
break;
case V_21 :
V_10 = F_2 ( V_2 , V_6 ) ;
break;
case V_22 :
V_10 = F_4 ( V_2 , V_6 ) ;
break;
case V_23 :
V_10 = F_5 ( V_2 , V_6 ) ;
break;
default:
V_10 = - V_24 ;
break;
}
return V_10 ;
}
static int F_8 ( struct V_1 * V_2 ,
union V_5 * V_6 )
{
T_1 V_25 ;
V_25 = F_9 ( V_2 -> V_26 , V_27 ) ;
if ( ( ( V_25 & V_28 ) == V_29 ) ||
( ( V_25 & V_28 ) == V_30 ) ) {
V_6 -> V_7 = V_31 ;
return 0 ;
}
V_25 = F_9 ( V_2 -> V_26 , V_32 ) ;
switch ( V_25 & V_33 ) {
case V_34 :
case V_35 :
case V_36 :
case V_37 :
V_6 -> V_7 = V_38 ;
break;
case V_39 :
case V_40 :
case V_41 :
case V_42 :
case V_43 :
V_6 -> V_7 = V_44 ;
break;
case V_45 :
V_6 -> V_7 = V_46 ;
break;
default:
V_6 -> V_7 = V_47 ;
break;
}
return 0 ;
}
static int F_10 ( struct V_1 * V_2 ,
union V_5 * V_6 )
{
T_1 V_25 ;
V_25 = F_9 ( V_2 -> V_26 , V_32 ) ;
switch ( V_25 & V_48 ) {
case V_49 :
V_6 -> V_7 = V_50 ;
return 0 ;
case V_51 :
V_6 -> V_7 = V_52 ;
return 0 ;
default:
break;
}
switch ( V_25 & V_33 ) {
case V_34 :
case V_35 :
V_6 -> V_7 = V_53 ;
break;
case V_42 :
V_6 -> V_7 = V_54 ;
break;
default:
V_6 -> V_7 = V_55 ;
break;
}
return 0 ;
}
static int F_11 ( struct V_1 * V_2 ,
union V_5 * V_6 )
{
T_1 V_25 ;
V_25 = F_9 ( V_2 -> V_26 , V_32 ) ;
if ( ( V_25 & V_33 ) == V_43 )
V_6 -> V_7 = 0 ;
else
V_6 -> V_7 = 1 ;
return 0 ;
}
static int F_12 ( struct V_1 * V_2 ,
union V_5 * V_6 )
{
T_1 V_25 ;
V_25 = F_9 ( V_2 -> V_26 , V_32 ) ;
switch ( V_25 & V_33 ) {
case V_36 :
V_6 -> V_7 = V_56 ;
break;
case V_34 :
case V_35 :
case V_37 :
V_6 -> V_7 = V_57 ;
break;
default:
V_6 -> V_7 = V_58 ;
break;
}
return 0 ;
}
static int F_13 ( struct V_1 * V_2 ,
union V_5 * V_6 )
{
T_1 V_25 ;
V_25 = F_9 ( V_2 -> V_26 , V_59 ) ;
V_6 -> V_7 = ( ( V_25 & V_60 ) * 50000 ) + 2500000 ;
return 0 ;
}
static int F_14 ( struct V_1 * V_2 ,
union V_5 * V_6 )
{
int V_9 , V_10 ;
V_10 = F_3 ( V_2 -> V_61 , & V_9 ) ;
if ( V_10 < 0 )
return V_10 ;
V_6 -> V_7 = V_9 * 1000 ;
return 0 ;
}
static int F_15 ( struct V_1 * V_2 ,
union V_5 * V_6 )
{
int V_25 ;
V_25 = F_9 ( V_2 -> V_26 , V_62 ) ;
V_6 -> V_7 = V_25 * 25000 ;
return 0 ;
}
static int F_16 ( struct V_1 * V_2 ,
union V_5 * V_6 )
{
T_1 V_25 ;
V_25 = F_9 ( V_2 -> V_26 , V_63 ) ;
V_6 -> V_7 = ( ( V_25 & V_64 ) * 25000 ) + 3650000 ;
return 0 ;
}
static int F_17 ( struct V_3 * V_4 ,
enum V_16 V_17 ,
union V_5 * V_6 )
{
struct V_1 * V_2 = F_7 ( V_4 -> V_18 . V_19 ) ;
int V_10 ;
switch ( V_17 ) {
case V_65 :
V_10 = F_8 ( V_2 , V_6 ) ;
break;
case V_20 :
V_10 = F_1 ( V_2 , V_4 , V_6 ) ;
break;
case V_66 :
V_10 = F_10 ( V_2 , V_6 ) ;
break;
case V_67 :
V_10 = F_11 ( V_2 , V_6 ) ;
break;
case V_68 :
V_10 = F_12 ( V_2 , V_6 ) ;
break;
case V_69 :
V_10 = F_13 ( V_2 , V_6 ) ;
break;
case V_21 :
V_10 = F_14 ( V_2 , V_6 ) ;
break;
case V_70 :
V_10 = F_15 ( V_2 , V_6 ) ;
break;
case V_71 :
V_10 = F_16 ( V_2 , V_6 ) ;
break;
default:
V_10 = - V_24 ;
break;
}
return V_10 ;
}
static T_2 F_18 ( int V_72 , void * V_73 )
{
struct V_1 * V_2 = V_73 ;
F_19 ( V_2 -> V_74 ) ;
return V_75 ;
}
static T_2 F_20 ( int V_72 , void * V_73 )
{
struct V_1 * V_2 = V_73 ;
F_21 ( V_2 -> V_18 , L_1 ) ;
F_19 ( V_2 -> V_76 ) ;
return V_75 ;
}
static T_2 F_22 ( int V_72 , void * V_73 )
{
struct V_1 * V_2 = V_73 ;
F_21 ( V_2 -> V_18 , L_2 ) ;
F_19 ( V_2 -> V_76 ) ;
F_19 ( V_2 -> V_74 ) ;
return V_75 ;
}
static T_2 F_23 ( int V_72 , void * V_73 )
{
struct V_1 * V_2 = V_73 ;
T_1 V_25 ;
V_25 = F_9 ( V_2 -> V_26 , V_27 ) ;
switch ( V_25 & V_28 ) {
case V_29 :
case V_30 :
V_2 -> V_8 = V_2 -> V_74 ;
break;
case V_77 :
V_2 -> V_8 = V_2 -> V_76 ;
break;
default:
F_24 ( V_2 -> V_18 , L_3 ,
V_25 ) ;
V_2 -> V_8 = NULL ;
break;
}
F_19 ( V_2 -> V_76 ) ;
F_19 ( V_2 -> V_74 ) ;
return V_75 ;
}
static void F_25 ( struct V_78 * V_73 )
{
struct V_1 * V_2 =
F_26 ( V_73 , struct V_1 , V_79 ) ;
switch ( V_2 -> V_80 ) {
case V_81 :
F_27 ( V_2 -> V_26 , V_82 ,
V_83 , V_84 ) ;
break;
case V_85 :
F_19 ( V_2 -> V_76 ) ;
F_19 ( V_2 -> V_74 ) ;
F_27 ( V_2 -> V_26 , V_82 ,
V_83 , V_86 ) ;
break;
}
}
static int F_28 ( struct V_87 * V_88 , unsigned long V_6 ,
void * V_89 )
{
struct V_1 * V_2 =
F_26 ( V_88 , struct V_1 , V_90 ) ;
F_29 ( V_2 -> V_18 , L_4 , V_6 ) ;
V_2 -> V_80 = V_6 ;
F_30 ( & V_2 -> V_79 ) ;
return V_91 ;
}
static int F_31 ( struct V_92 * V_93 ,
T_3 V_94 ,
const char * V_95 )
{
struct V_96 * V_18 = & V_93 -> V_18 ;
struct V_1 * V_2 = F_32 ( V_93 ) ;
int V_72 , V_10 ;
V_72 = F_33 ( V_93 , V_95 ) ;
if ( V_72 < 0 ) {
F_34 ( V_18 , L_5 , V_72 ) ;
return V_72 ;
}
V_10 = F_35 ( V_72 , NULL , V_94 , V_97 , V_95 ,
V_2 ) ;
if ( V_10 )
F_34 ( V_18 , L_6 , V_72 , V_10 ) ;
return V_10 ;
}
static void F_36 ( struct V_92 * V_93 ,
const char * V_95 )
{
struct V_96 * V_18 = & V_93 -> V_18 ;
struct V_1 * V_2 = F_32 ( V_93 ) ;
int V_72 ;
V_72 = F_33 ( V_93 , V_95 ) ;
if ( V_72 < 0 ) {
F_34 ( V_18 , L_5 , V_72 ) ;
return;
}
F_37 ( V_72 , V_2 ) ;
}
static int F_38 ( struct V_92 * V_93 )
{
struct V_96 * V_18 = & V_93 -> V_18 ;
struct V_26 * V_26 = F_7 ( V_18 -> V_19 ) ;
struct V_1 * V_2 ;
T_1 V_25 ;
int V_10 ;
V_2 = F_39 ( V_18 , sizeof( struct V_1 ) , V_98 ) ;
if ( ! V_2 )
return - V_99 ;
F_40 ( V_93 , V_2 ) ;
V_2 -> V_26 = V_26 ;
V_2 -> V_18 = V_18 ;
V_2 -> V_13 = F_41 ( V_18 , L_7 ) ;
if ( F_42 ( V_2 -> V_13 ) ) {
V_10 = F_43 ( V_2 -> V_13 ) ;
goto V_100;
}
V_2 -> V_11 = F_41 ( V_18 , L_8 ) ;
if ( F_42 ( V_2 -> V_11 ) ) {
V_10 = F_43 ( V_2 -> V_11 ) ;
goto V_101;
}
V_2 -> V_15 = F_41 ( V_18 , L_9 ) ;
if ( F_42 ( V_2 -> V_15 ) ) {
V_10 = F_43 ( V_2 -> V_15 ) ;
goto V_102;
}
V_2 -> V_61 = F_41 ( V_18 , L_10 ) ;
if ( F_42 ( V_2 -> V_61 ) ) {
V_10 = F_43 ( V_2 -> V_61 ) ;
goto V_103;
}
V_2 -> V_76 = F_44 ( V_18 , & V_104 , NULL ) ;
if ( F_42 ( V_2 -> V_76 ) ) {
V_10 = F_43 ( V_2 -> V_76 ) ;
goto V_105;
}
V_2 -> V_74 = F_44 ( V_18 , & V_106 , NULL ) ;
if ( F_42 ( V_2 -> V_74 ) ) {
V_10 = F_43 ( V_2 -> V_74 ) ;
goto V_107;
}
V_25 = F_9 ( V_26 , V_27 ) ;
switch ( V_25 & V_28 ) {
case V_29 :
case V_30 :
V_2 -> V_8 = V_2 -> V_74 ;
break;
case V_77 :
V_2 -> V_8 = V_2 -> V_76 ;
break;
default:
F_24 ( V_18 , L_3 , V_25 ) ;
V_2 -> V_8 = NULL ;
break;
}
V_2 -> V_108 = F_45 ( V_18 , V_109 ) ;
if ( ! F_46 ( V_2 -> V_108 ) ) {
F_47 ( & V_2 -> V_79 , F_25 ) ;
V_2 -> V_90 . V_110 = F_28 ;
F_48 ( V_2 -> V_108 , & V_2 -> V_90 ) ;
}
V_10 = F_31 ( V_93 , F_18 ,
L_11 ) ;
if ( V_10 < 0 )
goto V_111;
V_10 = F_31 ( V_93 , F_20 ,
L_12 ) ;
if ( V_10 < 0 )
goto V_112;
V_10 = F_31 ( V_93 , F_22 ,
L_13 ) ;
if ( V_10 < 0 )
goto V_113;
V_10 = F_31 ( V_93 , F_23 ,
L_14 ) ;
if ( V_10 < 0 )
goto V_114;
return 0 ;
V_114:
F_36 ( V_93 , L_13 ) ;
V_113:
F_36 ( V_93 , L_12 ) ;
V_112:
F_36 ( V_93 , L_11 ) ;
V_111:
if ( ! F_46 ( V_2 -> V_108 ) )
F_49 ( V_2 -> V_108 , & V_2 -> V_90 ) ;
V_107:
F_50 ( V_2 -> V_76 ) ;
V_105:
F_51 ( V_2 -> V_61 ) ;
V_103:
F_51 ( V_2 -> V_15 ) ;
V_102:
F_51 ( V_2 -> V_11 ) ;
V_101:
F_51 ( V_2 -> V_13 ) ;
V_100:
return V_10 ;
}
static int F_52 ( struct V_92 * V_93 )
{
struct V_1 * V_2 = F_32 ( V_93 ) ;
int V_72 ;
V_72 = F_33 ( V_93 , L_14 ) ;
F_37 ( V_72 , V_2 ) ;
V_72 = F_33 ( V_93 , L_13 ) ;
F_37 ( V_72 , V_2 ) ;
V_72 = F_33 ( V_93 , L_12 ) ;
F_37 ( V_72 , V_2 ) ;
V_72 = F_33 ( V_93 , L_11 ) ;
F_37 ( V_72 , V_2 ) ;
if ( ! F_46 ( V_2 -> V_108 ) )
F_49 ( V_2 -> V_108 , & V_2 -> V_90 ) ;
F_50 ( V_2 -> V_74 ) ;
F_50 ( V_2 -> V_76 ) ;
F_51 ( V_2 -> V_13 ) ;
F_51 ( V_2 -> V_11 ) ;
F_51 ( V_2 -> V_15 ) ;
F_51 ( V_2 -> V_61 ) ;
return 0 ;
}
