static T_1 F_1 ( int V_1 , void * V_2 )
{
struct V_3 * V_4 = V_2 ;
F_2 ( V_4 -> V_5 ,
V_6 ,
NULL ) ;
return V_7 ;
}
static int F_3 ( struct V_8 * V_9 ,
unsigned int V_10 )
{
if ( V_10 <= V_11 )
return 900000 + ( V_10 * 50000 ) ;
if ( V_10 <= V_12 )
return 1600000 + ( ( V_10 - V_11 )
* 100000 ) ;
return - V_13 ;
}
static int F_4 ( struct V_8 * V_9 , int V_14 ,
int V_15 , int V_16 ,
unsigned * V_10 )
{
struct V_3 * V_4 = F_5 ( V_9 ) ;
struct V_17 * V_17 = V_4 -> V_17 ;
int V_18 , V_19 ;
if ( V_15 < 900000 )
V_18 = 0 ;
else if ( V_15 < 1700000 )
V_18 = ( ( V_15 - 900000 ) / 50000 ) ;
else
V_18 = ( ( V_15 - 1700000 ) / 100000 )
+ V_11 + 1 ;
V_19 = F_3 ( V_9 , V_18 ) ;
if ( V_19 < 0 )
return V_19 ;
if ( V_19 < V_15 || V_19 > V_16 )
return - V_13 ;
* V_10 = V_18 ;
return F_6 ( V_17 , V_14 , V_20 , V_18 ) ;
}
static int F_7 ( struct V_8 * V_9 ,
int V_15 , int V_16 ,
unsigned * V_10 )
{
struct V_3 * V_4 = F_5 ( V_9 ) ;
int V_14 = V_4 -> V_21 + V_22 ;
return F_4 ( V_9 , V_14 , V_15 , V_16 ,
V_10 ) ;
}
static int F_8 ( struct V_8 * V_9 ,
int V_23 )
{
struct V_3 * V_4 = F_5 ( V_9 ) ;
int V_14 = V_4 -> V_21 + V_24 ;
unsigned int V_10 ;
return F_4 ( V_9 , V_14 , V_23 , V_23 , & V_10 ) ;
}
static unsigned int F_9 ( struct V_8 * V_9 )
{
struct V_3 * V_4 = F_5 ( V_9 ) ;
struct V_17 * V_17 = V_4 -> V_17 ;
int V_25 = V_4 -> V_21 + V_26 ;
int V_27 = V_4 -> V_21 + V_22 ;
int V_19 ;
V_19 = F_10 ( V_17 , V_27 ) ;
if ( V_19 < 0 )
return V_19 ;
if ( ! ( V_19 & V_28 ) )
return V_29 ;
V_19 = F_10 ( V_17 , V_25 ) ;
if ( V_19 < 0 )
return V_19 ;
if ( V_19 & V_30 )
return V_31 ;
else
return V_32 ;
}
static int F_11 ( struct V_8 * V_9 ,
unsigned int V_33 )
{
struct V_3 * V_4 = F_5 ( V_9 ) ;
struct V_17 * V_17 = V_4 -> V_17 ;
int V_25 = V_4 -> V_21 + V_26 ;
int V_27 = V_4 -> V_21 + V_22 ;
int V_19 ;
switch ( V_33 ) {
case V_29 :
V_19 = F_6 ( V_17 , V_27 ,
V_28 , 0 ) ;
if ( V_19 < 0 )
return V_19 ;
break;
case V_32 :
V_19 = F_6 ( V_17 , V_25 ,
V_30 , 0 ) ;
if ( V_19 < 0 )
return V_19 ;
V_19 = F_6 ( V_17 , V_27 ,
V_28 ,
V_28 ) ;
if ( V_19 < 0 )
return V_19 ;
break;
case V_31 :
V_19 = F_6 ( V_17 , V_25 ,
V_30 ,
V_30 ) ;
if ( V_19 < 0 )
return V_19 ;
V_19 = F_6 ( V_17 , V_27 ,
V_28 ,
V_28 ) ;
if ( V_19 < 0 )
return V_19 ;
break;
default:
return - V_13 ;
}
return 0 ;
}
static int F_12 ( struct V_8 * V_9 )
{
struct V_3 * V_4 = F_5 ( V_9 ) ;
struct V_17 * V_17 = V_4 -> V_17 ;
int V_34 = 1 << F_13 ( V_9 ) ;
int V_19 ;
V_19 = F_10 ( V_17 , V_35 ) ;
if ( V_19 < 0 )
return V_19 ;
if ( ! ( V_19 & V_34 ) )
return V_36 ;
V_19 = F_10 ( V_17 , V_37 ) ;
if ( V_19 & V_34 )
return V_38 ;
V_19 = F_9 ( V_9 ) ;
if ( V_19 < 0 )
return V_19 ;
else
return F_14 ( V_19 ) ;
}
static unsigned int F_15 ( struct V_8 * V_9 ,
int V_39 ,
int V_40 , int V_41 )
{
if ( V_41 < 20000 )
return V_31 ;
if ( V_41 < 50000 )
return V_32 ;
return V_29 ;
}
static T_2 int F_16 ( struct V_42 * V_43 )
{
struct V_17 * V_17 = F_17 ( V_43 -> V_44 . V_45 ) ;
struct V_46 * V_47 = V_17 -> V_44 -> V_48 ;
struct V_49 V_50 = { } ;
int V_51 ;
struct V_3 * V_4 ;
struct V_52 * V_53 ;
int V_19 , V_1 ;
if ( V_47 && V_47 -> V_54 )
V_51 = ( V_47 -> V_54 * 10 ) + 1 ;
else
V_51 = 0 ;
V_51 = V_43 -> V_51 - V_51 ;
F_18 ( & V_43 -> V_44 , L_1 , V_51 + 1 ) ;
V_4 = F_19 ( & V_43 -> V_44 , sizeof( struct V_3 ) , V_55 ) ;
if ( V_4 == NULL ) {
F_20 ( & V_43 -> V_44 , L_2 ) ;
return - V_56 ;
}
V_4 -> V_17 = V_17 ;
V_53 = F_21 ( V_43 , V_57 , 0 ) ;
if ( V_53 == NULL ) {
F_20 ( & V_43 -> V_44 , L_3 ) ;
V_19 = - V_13 ;
goto V_58;
}
V_4 -> V_21 = V_53 -> V_59 ;
snprintf ( V_4 -> V_60 , sizeof( V_4 -> V_60 ) , L_4 , V_51 + 1 ) ;
V_4 -> V_61 . V_60 = V_4 -> V_60 ;
snprintf ( V_4 -> V_62 , sizeof( V_4 -> V_62 ) ,
L_5 , V_51 + 1 ) ;
V_4 -> V_61 . V_62 = V_4 -> V_62 ;
V_4 -> V_61 . V_51 = V_51 ;
V_4 -> V_61 . type = V_63 ;
V_4 -> V_61 . V_64 = V_12 + 1 ;
V_4 -> V_61 . V_65 = & V_66 ;
V_4 -> V_61 . V_67 = V_68 ;
V_4 -> V_61 . V_69 = V_4 -> V_21 + V_22 ;
V_4 -> V_61 . V_70 = V_20 ;
V_4 -> V_61 . V_71 = V_72 ;
V_4 -> V_61 . V_73 = 1 << V_51 ;
V_50 . V_44 = V_43 -> V_44 . V_45 ;
if ( V_47 )
V_50 . V_74 = V_47 -> V_4 [ V_51 ] ;
V_50 . V_75 = V_4 ;
V_50 . V_76 = V_17 -> V_76 ;
V_4 -> V_5 = F_22 ( & V_4 -> V_61 , & V_50 ) ;
if ( F_23 ( V_4 -> V_5 ) ) {
V_19 = F_24 ( V_4 -> V_5 ) ;
F_20 ( V_17 -> V_44 , L_6 ,
V_51 + 1 , V_19 ) ;
goto V_58;
}
V_1 = F_25 ( V_17 , F_26 ( V_43 , L_7 ) ) ;
V_19 = F_27 ( V_1 , NULL , F_1 ,
V_77 , V_4 -> V_60 ,
V_4 ) ;
if ( V_19 != 0 ) {
F_20 ( & V_43 -> V_44 , L_8 ,
V_1 , V_19 ) ;
goto V_78;
}
F_28 ( V_43 , V_4 ) ;
return 0 ;
V_78:
F_29 ( V_4 -> V_5 ) ;
V_58:
return V_19 ;
}
static T_3 int F_30 ( struct V_42 * V_43 )
{
struct V_3 * V_4 = F_31 ( V_43 ) ;
F_28 ( V_43 , NULL ) ;
F_32 ( F_25 ( V_4 -> V_17 ,
F_26 ( V_43 , L_7 ) ) , V_4 ) ;
F_29 ( V_4 -> V_5 ) ;
return 0 ;
}
static int F_33 ( struct V_8 * V_9 ,
unsigned int V_10 )
{
if ( V_10 <= V_79 )
return 1000000 + ( V_10 * 50000 ) ;
if ( V_10 <= V_80 )
return 1600000 + ( ( V_10 - V_79 )
* 100000 ) ;
return - V_13 ;
}
static int F_34 ( struct V_8 * V_9 , int V_14 ,
int V_15 , int V_16 ,
unsigned * V_10 )
{
struct V_3 * V_4 = F_5 ( V_9 ) ;
struct V_17 * V_17 = V_4 -> V_17 ;
int V_18 , V_19 ;
if ( V_15 < 1000000 )
V_18 = 0 ;
else if ( V_15 < 1700000 )
V_18 = ( ( V_15 - 1000000 ) / 50000 ) ;
else
V_18 = ( ( V_15 - 1700000 ) / 100000 )
+ V_79 + 1 ;
V_19 = F_33 ( V_9 , V_18 ) ;
if ( V_19 < 0 )
return V_19 ;
if ( V_19 < V_15 || V_19 > V_16 )
return - V_13 ;
* V_10 = V_18 ;
return F_6 ( V_17 , V_14 , V_81 , V_18 ) ;
}
static int F_35 ( struct V_8 * V_9 ,
int V_15 , int V_16 , unsigned * V_10 )
{
struct V_3 * V_4 = F_5 ( V_9 ) ;
int V_14 = V_4 -> V_21 + V_22 ;
return F_34 ( V_9 , V_14 , V_15 , V_16 ,
V_10 ) ;
}
static int F_36 ( struct V_8 * V_9 ,
int V_23 )
{
struct V_3 * V_4 = F_5 ( V_9 ) ;
int V_14 = V_4 -> V_21 + V_24 ;
unsigned int V_10 ;
return F_34 ( V_9 , V_14 , V_23 , V_23 , & V_10 ) ;
}
static unsigned int F_37 ( struct V_8 * V_9 )
{
struct V_3 * V_4 = F_5 ( V_9 ) ;
struct V_17 * V_17 = V_4 -> V_17 ;
int V_27 = V_4 -> V_21 + V_22 ;
int V_19 ;
V_19 = F_10 ( V_17 , V_27 ) ;
if ( V_19 < 0 )
return 0 ;
if ( V_19 & V_82 )
return V_32 ;
else
return V_29 ;
}
static int F_38 ( struct V_8 * V_9 ,
unsigned int V_33 )
{
struct V_3 * V_4 = F_5 ( V_9 ) ;
struct V_17 * V_17 = V_4 -> V_17 ;
int V_27 = V_4 -> V_21 + V_22 ;
int V_19 ;
switch ( V_33 ) {
case V_29 :
V_19 = F_6 ( V_17 , V_27 , V_82 , 0 ) ;
if ( V_19 < 0 )
return V_19 ;
break;
case V_32 :
V_19 = F_6 ( V_17 , V_27 , V_82 ,
V_82 ) ;
if ( V_19 < 0 )
return V_19 ;
break;
default:
return - V_13 ;
}
return 0 ;
}
static int F_39 ( struct V_8 * V_9 )
{
struct V_3 * V_4 = F_5 ( V_9 ) ;
struct V_17 * V_17 = V_4 -> V_17 ;
int V_34 = 1 << F_13 ( V_9 ) ;
int V_19 ;
V_19 = F_10 ( V_17 , V_35 ) ;
if ( V_19 < 0 )
return V_19 ;
if ( ! ( V_19 & V_34 ) )
return V_36 ;
V_19 = F_10 ( V_17 , V_37 ) ;
if ( V_19 & V_34 )
return V_38 ;
V_19 = F_37 ( V_9 ) ;
if ( V_19 < 0 )
return V_19 ;
else
return F_14 ( V_19 ) ;
}
static T_2 int F_40 ( struct V_42 * V_43 )
{
struct V_17 * V_17 = F_17 ( V_43 -> V_44 . V_45 ) ;
struct V_46 * V_47 = V_17 -> V_44 -> V_48 ;
struct V_49 V_50 = { } ;
int V_51 ;
struct V_3 * V_4 ;
struct V_52 * V_53 ;
int V_19 , V_1 ;
if ( V_47 && V_47 -> V_54 )
V_51 = ( V_47 -> V_54 * 10 ) + 1 ;
else
V_51 = 0 ;
V_51 = V_43 -> V_51 - V_51 ;
F_18 ( & V_43 -> V_44 , L_1 , V_51 + 1 ) ;
V_4 = F_19 ( & V_43 -> V_44 , sizeof( struct V_3 ) , V_55 ) ;
if ( V_4 == NULL ) {
F_20 ( & V_43 -> V_44 , L_2 ) ;
return - V_56 ;
}
V_4 -> V_17 = V_17 ;
V_53 = F_21 ( V_43 , V_57 , 0 ) ;
if ( V_53 == NULL ) {
F_20 ( & V_43 -> V_44 , L_3 ) ;
V_19 = - V_13 ;
goto V_58;
}
V_4 -> V_21 = V_53 -> V_59 ;
snprintf ( V_4 -> V_60 , sizeof( V_4 -> V_60 ) , L_4 , V_51 + 1 ) ;
V_4 -> V_61 . V_60 = V_4 -> V_60 ;
snprintf ( V_4 -> V_62 , sizeof( V_4 -> V_62 ) ,
L_5 , V_51 + 1 ) ;
V_4 -> V_61 . V_62 = V_4 -> V_62 ;
V_4 -> V_61 . V_51 = V_51 ;
V_4 -> V_61 . type = V_63 ;
V_4 -> V_61 . V_64 = V_80 + 1 ;
V_4 -> V_61 . V_65 = & V_83 ;
V_4 -> V_61 . V_67 = V_68 ;
V_4 -> V_61 . V_69 = V_4 -> V_21 + V_22 ;
V_4 -> V_61 . V_70 = V_81 ;
V_4 -> V_61 . V_71 = V_72 ;
V_4 -> V_61 . V_73 = 1 << V_51 ;
V_50 . V_44 = V_43 -> V_44 . V_45 ;
if ( V_47 )
V_50 . V_74 = V_47 -> V_4 [ V_51 ] ;
V_50 . V_75 = V_4 ;
V_50 . V_76 = V_17 -> V_76 ;
V_4 -> V_5 = F_22 ( & V_4 -> V_61 , & V_50 ) ;
if ( F_23 ( V_4 -> V_5 ) ) {
V_19 = F_24 ( V_4 -> V_5 ) ;
F_20 ( V_17 -> V_44 , L_6 ,
V_51 + 1 , V_19 ) ;
goto V_58;
}
V_1 = F_25 ( V_17 , F_26 ( V_43 , L_7 ) ) ;
V_19 = F_27 ( V_1 , NULL , F_1 ,
V_77 , V_4 -> V_60 , V_4 ) ;
if ( V_19 != 0 ) {
F_20 ( & V_43 -> V_44 , L_8 ,
V_1 , V_19 ) ;
goto V_78;
}
F_28 ( V_43 , V_4 ) ;
return 0 ;
V_78:
F_29 ( V_4 -> V_5 ) ;
V_58:
return V_19 ;
}
static T_3 int F_41 ( struct V_42 * V_43 )
{
struct V_3 * V_4 = F_31 ( V_43 ) ;
F_32 ( F_25 ( V_4 -> V_17 , F_26 ( V_43 , L_7 ) ) ,
V_4 ) ;
F_29 ( V_4 -> V_5 ) ;
return 0 ;
}
static int F_42 ( struct V_8 * V_9 ,
int V_14 ,
int V_15 , int V_16 ,
unsigned * V_10 )
{
struct V_3 * V_4 = F_5 ( V_9 ) ;
struct V_17 * V_17 = V_4 -> V_17 ;
int V_18 , V_19 ;
V_18 = ( V_15 - 800000 ) / 50000 ;
V_19 = F_43 ( V_9 , V_18 ) ;
if ( V_19 < 0 )
return V_19 ;
if ( V_19 < V_15 || V_19 > V_16 )
return - V_13 ;
* V_10 = V_18 ;
return F_6 ( V_17 , V_14 , V_84 , V_18 ) ;
}
static int F_44 ( struct V_8 * V_9 ,
int V_15 , int V_16 ,
unsigned * V_10 )
{
struct V_3 * V_4 = F_5 ( V_9 ) ;
int V_14 = V_4 -> V_21 + V_85 ;
return F_42 ( V_9 , V_14 , V_15 , V_16 ,
V_10 ) ;
}
static int F_45 ( struct V_8 * V_9 ,
int V_23 )
{
struct V_3 * V_4 = F_5 ( V_9 ) ;
int V_14 = V_4 -> V_21 + V_86 ;
unsigned V_10 ;
return F_42 ( V_9 , V_14 , V_23 , V_23 , & V_10 ) ;
}
static int F_46 ( struct V_8 * V_9 )
{
struct V_3 * V_4 = F_5 ( V_9 ) ;
struct V_17 * V_17 = V_4 -> V_17 ;
int V_34 = 1 << F_13 ( V_9 ) ;
int V_19 ;
V_19 = F_10 ( V_17 , V_35 ) ;
if ( V_19 < 0 )
return V_19 ;
if ( V_19 & V_34 )
return V_87 ;
else
return V_36 ;
}
static T_2 int F_47 ( struct V_42 * V_43 )
{
struct V_17 * V_17 = F_17 ( V_43 -> V_44 . V_45 ) ;
struct V_46 * V_47 = V_17 -> V_44 -> V_48 ;
struct V_49 V_50 = { } ;
int V_51 ;
struct V_3 * V_4 ;
struct V_52 * V_53 ;
int V_19 ;
if ( V_47 && V_47 -> V_54 )
V_51 = ( V_47 -> V_54 * 10 ) + 1 ;
else
V_51 = 0 ;
V_51 = V_43 -> V_51 - V_51 ;
F_18 ( & V_43 -> V_44 , L_1 , V_51 + 1 ) ;
V_4 = F_19 ( & V_43 -> V_44 , sizeof( struct V_3 ) , V_55 ) ;
if ( V_4 == NULL ) {
F_20 ( & V_43 -> V_44 , L_2 ) ;
return - V_56 ;
}
V_4 -> V_17 = V_17 ;
V_53 = F_21 ( V_43 , V_57 , 0 ) ;
if ( V_53 == NULL ) {
F_20 ( & V_43 -> V_44 , L_3 ) ;
V_19 = - V_13 ;
goto V_58;
}
V_4 -> V_21 = V_53 -> V_59 ;
snprintf ( V_4 -> V_60 , sizeof( V_4 -> V_60 ) , L_4 , V_51 + 1 ) ;
V_4 -> V_61 . V_60 = V_4 -> V_60 ;
snprintf ( V_4 -> V_62 , sizeof( V_4 -> V_62 ) ,
L_5 , V_51 + 1 ) ;
V_4 -> V_61 . V_62 = V_4 -> V_62 ;
V_4 -> V_61 . V_51 = V_51 ;
V_4 -> V_61 . type = V_63 ;
V_4 -> V_61 . V_64 = V_88 + 1 ;
V_4 -> V_61 . V_65 = & V_89 ;
V_4 -> V_61 . V_67 = V_68 ;
V_4 -> V_61 . V_69 = V_4 -> V_21 + V_85 ;
V_4 -> V_61 . V_70 = V_84 ;
V_4 -> V_61 . V_71 = V_72 ;
V_4 -> V_61 . V_73 = 1 << V_51 ;
V_4 -> V_61 . V_15 = 800000 ;
V_4 -> V_61 . V_90 = 50000 ;
V_50 . V_44 = V_43 -> V_44 . V_45 ;
if ( V_47 )
V_50 . V_74 = V_47 -> V_4 [ V_51 ] ;
V_50 . V_75 = V_4 ;
V_50 . V_76 = V_17 -> V_76 ;
V_4 -> V_5 = F_22 ( & V_4 -> V_61 , & V_50 ) ;
if ( F_23 ( V_4 -> V_5 ) ) {
V_19 = F_24 ( V_4 -> V_5 ) ;
F_20 ( V_17 -> V_44 , L_6 ,
V_51 + 1 , V_19 ) ;
goto V_58;
}
F_28 ( V_43 , V_4 ) ;
return 0 ;
V_58:
return V_19 ;
}
static T_3 int F_48 ( struct V_42 * V_43 )
{
struct V_3 * V_4 = F_31 ( V_43 ) ;
F_29 ( V_4 -> V_5 ) ;
return 0 ;
}
static int T_4 F_49 ( void )
{
int V_19 ;
V_19 = F_50 ( & V_91 ) ;
if ( V_19 != 0 )
F_51 ( L_9 , V_19 ) ;
V_19 = F_50 ( & V_92 ) ;
if ( V_19 != 0 )
F_51 ( L_10 , V_19 ) ;
V_19 = F_50 ( & V_93 ) ;
if ( V_19 != 0 )
F_51 ( L_11 ,
V_19 ) ;
return 0 ;
}
static void T_5 F_52 ( void )
{
F_53 ( & V_93 ) ;
F_53 ( & V_92 ) ;
F_53 ( & V_91 ) ;
}
