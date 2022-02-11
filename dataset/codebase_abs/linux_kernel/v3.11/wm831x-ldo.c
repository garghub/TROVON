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
static int F_4 ( struct V_8 * V_9 ,
int V_14 , int V_15 )
{
int V_16 , V_17 ;
if ( V_14 < 900000 )
V_17 = 0 ;
else if ( V_14 < 1700000 )
V_17 = ( ( V_14 - 900000 ) / 50000 ) ;
else
V_17 = ( ( V_14 - 1700000 ) / 100000 )
+ V_11 + 1 ;
V_16 = F_3 ( V_9 , V_17 ) ;
if ( V_16 < V_14 || V_16 > V_15 )
return - V_13 ;
return V_17 ;
}
static int F_5 ( struct V_8 * V_9 ,
int V_18 )
{
struct V_3 * V_4 = F_6 ( V_9 ) ;
struct V_19 * V_19 = V_4 -> V_19 ;
int V_20 , V_21 = V_4 -> V_22 + V_23 ;
V_20 = F_4 ( V_9 , V_18 , V_18 ) ;
if ( V_20 < 0 )
return V_20 ;
return F_7 ( V_19 , V_21 , V_24 , V_20 ) ;
}
static unsigned int F_8 ( struct V_8 * V_9 )
{
struct V_3 * V_4 = F_6 ( V_9 ) ;
struct V_19 * V_19 = V_4 -> V_19 ;
int V_25 = V_4 -> V_22 + V_26 ;
int V_27 = V_4 -> V_22 + V_28 ;
int V_29 ;
V_29 = F_9 ( V_19 , V_27 ) ;
if ( V_29 < 0 )
return V_29 ;
if ( ! ( V_29 & V_30 ) )
return V_31 ;
V_29 = F_9 ( V_19 , V_25 ) ;
if ( V_29 < 0 )
return V_29 ;
if ( V_29 & V_32 )
return V_33 ;
else
return V_34 ;
}
static int F_10 ( struct V_8 * V_9 ,
unsigned int V_35 )
{
struct V_3 * V_4 = F_6 ( V_9 ) ;
struct V_19 * V_19 = V_4 -> V_19 ;
int V_25 = V_4 -> V_22 + V_26 ;
int V_27 = V_4 -> V_22 + V_28 ;
int V_29 ;
switch ( V_35 ) {
case V_31 :
V_29 = F_7 ( V_19 , V_27 ,
V_30 , 0 ) ;
if ( V_29 < 0 )
return V_29 ;
break;
case V_34 :
V_29 = F_7 ( V_19 , V_25 ,
V_32 , 0 ) ;
if ( V_29 < 0 )
return V_29 ;
V_29 = F_7 ( V_19 , V_27 ,
V_30 ,
V_30 ) ;
if ( V_29 < 0 )
return V_29 ;
break;
case V_33 :
V_29 = F_7 ( V_19 , V_25 ,
V_32 ,
V_32 ) ;
if ( V_29 < 0 )
return V_29 ;
V_29 = F_7 ( V_19 , V_27 ,
V_30 ,
V_30 ) ;
if ( V_29 < 0 )
return V_29 ;
break;
default:
return - V_13 ;
}
return 0 ;
}
static int F_11 ( struct V_8 * V_9 )
{
struct V_3 * V_4 = F_6 ( V_9 ) ;
struct V_19 * V_19 = V_4 -> V_19 ;
int V_36 = 1 << F_12 ( V_9 ) ;
int V_29 ;
V_29 = F_9 ( V_19 , V_37 ) ;
if ( V_29 < 0 )
return V_29 ;
if ( ! ( V_29 & V_36 ) )
return V_38 ;
V_29 = F_9 ( V_19 , V_39 ) ;
if ( V_29 < 0 )
return V_29 ;
if ( V_29 & V_36 )
return V_40 ;
V_29 = F_8 ( V_9 ) ;
if ( V_29 < 0 )
return V_29 ;
else
return F_13 ( V_29 ) ;
}
static unsigned int F_14 ( struct V_8 * V_9 ,
int V_41 ,
int V_42 , int V_43 )
{
if ( V_43 < 20000 )
return V_33 ;
if ( V_43 < 50000 )
return V_34 ;
return V_31 ;
}
static int F_15 ( struct V_44 * V_45 )
{
struct V_19 * V_19 = F_16 ( V_45 -> V_46 . V_47 ) ;
struct V_48 * V_49 = V_19 -> V_46 -> V_50 ;
struct V_51 V_52 = { } ;
int V_53 ;
struct V_3 * V_4 ;
struct V_54 * V_55 ;
int V_29 , V_1 ;
if ( V_49 && V_49 -> V_56 )
V_53 = ( V_49 -> V_56 * 10 ) + 1 ;
else
V_53 = 0 ;
V_53 = V_45 -> V_53 - V_53 ;
F_17 ( & V_45 -> V_46 , L_1 , V_53 + 1 ) ;
V_4 = F_18 ( & V_45 -> V_46 , sizeof( struct V_3 ) , V_57 ) ;
if ( V_4 == NULL ) {
F_19 ( & V_45 -> V_46 , L_2 ) ;
return - V_58 ;
}
V_4 -> V_19 = V_19 ;
V_55 = F_20 ( V_45 , V_59 , 0 ) ;
if ( V_55 == NULL ) {
F_19 ( & V_45 -> V_46 , L_3 ) ;
V_29 = - V_13 ;
goto V_60;
}
V_4 -> V_22 = V_55 -> V_61 ;
snprintf ( V_4 -> V_62 , sizeof( V_4 -> V_62 ) , L_4 , V_53 + 1 ) ;
V_4 -> V_63 . V_62 = V_4 -> V_62 ;
snprintf ( V_4 -> V_64 , sizeof( V_4 -> V_64 ) ,
L_5 , V_53 + 1 ) ;
V_4 -> V_63 . V_64 = V_4 -> V_64 ;
V_4 -> V_63 . V_53 = V_53 ;
V_4 -> V_63 . type = V_65 ;
V_4 -> V_63 . V_66 = V_12 + 1 ;
V_4 -> V_63 . V_67 = & V_68 ;
V_4 -> V_63 . V_69 = V_70 ;
V_4 -> V_63 . V_71 = V_4 -> V_22 + V_28 ;
V_4 -> V_63 . V_72 = V_24 ;
V_4 -> V_63 . V_73 = V_74 ;
V_4 -> V_63 . V_75 = 1 << V_53 ;
V_4 -> V_63 . V_76 = V_4 -> V_22 ;
V_4 -> V_63 . V_77 = V_78 ;
V_52 . V_46 = V_45 -> V_46 . V_47 ;
if ( V_49 )
V_52 . V_79 = V_49 -> V_4 [ V_53 ] ;
V_52 . V_80 = V_4 ;
V_52 . V_81 = V_19 -> V_81 ;
V_4 -> V_5 = F_21 ( & V_4 -> V_63 , & V_52 ) ;
if ( F_22 ( V_4 -> V_5 ) ) {
V_29 = F_23 ( V_4 -> V_5 ) ;
F_19 ( V_19 -> V_46 , L_6 ,
V_53 + 1 , V_29 ) ;
goto V_60;
}
V_1 = F_24 ( V_19 , F_25 ( V_45 , L_7 ) ) ;
V_29 = F_26 ( V_1 , NULL , F_1 ,
V_82 , V_4 -> V_62 ,
V_4 ) ;
if ( V_29 != 0 ) {
F_19 ( & V_45 -> V_46 , L_8 ,
V_1 , V_29 ) ;
goto V_83;
}
F_27 ( V_45 , V_4 ) ;
return 0 ;
V_83:
F_28 ( V_4 -> V_5 ) ;
V_60:
return V_29 ;
}
static int F_29 ( struct V_44 * V_45 )
{
struct V_3 * V_4 = F_30 ( V_45 ) ;
F_31 ( F_24 ( V_4 -> V_19 ,
F_25 ( V_45 , L_7 ) ) , V_4 ) ;
F_28 ( V_4 -> V_5 ) ;
return 0 ;
}
static int F_32 ( struct V_8 * V_9 ,
unsigned int V_10 )
{
if ( V_10 <= V_84 )
return 1000000 + ( V_10 * 50000 ) ;
if ( V_10 <= V_85 )
return 1600000 + ( ( V_10 - V_84 )
* 100000 ) ;
return - V_13 ;
}
static int F_33 ( struct V_8 * V_9 ,
int V_14 , int V_15 )
{
int V_16 , V_17 ;
if ( V_14 < 1000000 )
V_17 = 0 ;
else if ( V_14 < 1700000 )
V_17 = ( ( V_14 - 1000000 ) / 50000 ) ;
else
V_17 = ( ( V_14 - 1700000 ) / 100000 )
+ V_84 + 1 ;
V_16 = F_32 ( V_9 , V_17 ) ;
if ( V_16 < V_14 || V_16 > V_15 )
return - V_13 ;
return V_17 ;
}
static int F_34 ( struct V_8 * V_9 ,
int V_18 )
{
struct V_3 * V_4 = F_6 ( V_9 ) ;
struct V_19 * V_19 = V_4 -> V_19 ;
int V_20 , V_21 = V_4 -> V_22 + V_23 ;
V_20 = F_33 ( V_9 , V_18 , V_18 ) ;
if ( V_20 < 0 )
return V_20 ;
return F_7 ( V_19 , V_21 , V_86 , V_20 ) ;
}
static unsigned int F_35 ( struct V_8 * V_9 )
{
struct V_3 * V_4 = F_6 ( V_9 ) ;
struct V_19 * V_19 = V_4 -> V_19 ;
int V_27 = V_4 -> V_22 + V_28 ;
int V_29 ;
V_29 = F_9 ( V_19 , V_27 ) ;
if ( V_29 < 0 )
return 0 ;
if ( V_29 & V_87 )
return V_34 ;
else
return V_31 ;
}
static int F_36 ( struct V_8 * V_9 ,
unsigned int V_35 )
{
struct V_3 * V_4 = F_6 ( V_9 ) ;
struct V_19 * V_19 = V_4 -> V_19 ;
int V_27 = V_4 -> V_22 + V_28 ;
int V_29 ;
switch ( V_35 ) {
case V_31 :
V_29 = F_7 ( V_19 , V_27 , V_87 , 0 ) ;
if ( V_29 < 0 )
return V_29 ;
break;
case V_34 :
V_29 = F_7 ( V_19 , V_27 , V_87 ,
V_87 ) ;
if ( V_29 < 0 )
return V_29 ;
break;
default:
return - V_13 ;
}
return 0 ;
}
static int F_37 ( struct V_8 * V_9 )
{
struct V_3 * V_4 = F_6 ( V_9 ) ;
struct V_19 * V_19 = V_4 -> V_19 ;
int V_36 = 1 << F_12 ( V_9 ) ;
int V_29 ;
V_29 = F_9 ( V_19 , V_37 ) ;
if ( V_29 < 0 )
return V_29 ;
if ( ! ( V_29 & V_36 ) )
return V_38 ;
V_29 = F_9 ( V_19 , V_39 ) ;
if ( V_29 < 0 )
return V_29 ;
if ( V_29 & V_36 )
return V_40 ;
V_29 = F_35 ( V_9 ) ;
if ( V_29 < 0 )
return V_29 ;
else
return F_13 ( V_29 ) ;
}
static int F_38 ( struct V_44 * V_45 )
{
struct V_19 * V_19 = F_16 ( V_45 -> V_46 . V_47 ) ;
struct V_48 * V_49 = V_19 -> V_46 -> V_50 ;
struct V_51 V_52 = { } ;
int V_53 ;
struct V_3 * V_4 ;
struct V_54 * V_55 ;
int V_29 , V_1 ;
if ( V_49 && V_49 -> V_56 )
V_53 = ( V_49 -> V_56 * 10 ) + 1 ;
else
V_53 = 0 ;
V_53 = V_45 -> V_53 - V_53 ;
F_17 ( & V_45 -> V_46 , L_1 , V_53 + 1 ) ;
V_4 = F_18 ( & V_45 -> V_46 , sizeof( struct V_3 ) , V_57 ) ;
if ( V_4 == NULL ) {
F_19 ( & V_45 -> V_46 , L_2 ) ;
return - V_58 ;
}
V_4 -> V_19 = V_19 ;
V_55 = F_20 ( V_45 , V_59 , 0 ) ;
if ( V_55 == NULL ) {
F_19 ( & V_45 -> V_46 , L_3 ) ;
V_29 = - V_13 ;
goto V_60;
}
V_4 -> V_22 = V_55 -> V_61 ;
snprintf ( V_4 -> V_62 , sizeof( V_4 -> V_62 ) , L_4 , V_53 + 1 ) ;
V_4 -> V_63 . V_62 = V_4 -> V_62 ;
snprintf ( V_4 -> V_64 , sizeof( V_4 -> V_64 ) ,
L_5 , V_53 + 1 ) ;
V_4 -> V_63 . V_64 = V_4 -> V_64 ;
V_4 -> V_63 . V_53 = V_53 ;
V_4 -> V_63 . type = V_65 ;
V_4 -> V_63 . V_66 = V_85 + 1 ;
V_4 -> V_63 . V_67 = & V_88 ;
V_4 -> V_63 . V_69 = V_70 ;
V_4 -> V_63 . V_71 = V_4 -> V_22 + V_28 ;
V_4 -> V_63 . V_72 = V_86 ;
V_4 -> V_63 . V_73 = V_74 ;
V_4 -> V_63 . V_75 = 1 << V_53 ;
V_4 -> V_63 . V_76 = V_4 -> V_22 ;
V_4 -> V_63 . V_77 = V_89 ;
V_52 . V_46 = V_45 -> V_46 . V_47 ;
if ( V_49 )
V_52 . V_79 = V_49 -> V_4 [ V_53 ] ;
V_52 . V_80 = V_4 ;
V_52 . V_81 = V_19 -> V_81 ;
V_4 -> V_5 = F_21 ( & V_4 -> V_63 , & V_52 ) ;
if ( F_22 ( V_4 -> V_5 ) ) {
V_29 = F_23 ( V_4 -> V_5 ) ;
F_19 ( V_19 -> V_46 , L_6 ,
V_53 + 1 , V_29 ) ;
goto V_60;
}
V_1 = F_24 ( V_19 , F_25 ( V_45 , L_7 ) ) ;
V_29 = F_26 ( V_1 , NULL , F_1 ,
V_82 , V_4 -> V_62 , V_4 ) ;
if ( V_29 != 0 ) {
F_19 ( & V_45 -> V_46 , L_8 ,
V_1 , V_29 ) ;
goto V_83;
}
F_27 ( V_45 , V_4 ) ;
return 0 ;
V_83:
F_28 ( V_4 -> V_5 ) ;
V_60:
return V_29 ;
}
static int F_39 ( struct V_44 * V_45 )
{
struct V_3 * V_4 = F_30 ( V_45 ) ;
F_31 ( F_24 ( V_4 -> V_19 , F_25 ( V_45 , L_7 ) ) ,
V_4 ) ;
F_28 ( V_4 -> V_5 ) ;
return 0 ;
}
static int F_40 ( struct V_8 * V_9 ,
int V_18 )
{
struct V_3 * V_4 = F_6 ( V_9 ) ;
struct V_19 * V_19 = V_4 -> V_19 ;
int V_20 , V_21 = V_4 -> V_22 + V_90 ;
V_20 = F_41 ( V_9 , V_18 , V_18 ) ;
if ( V_20 < 0 )
return V_20 ;
return F_7 ( V_19 , V_21 , V_91 , V_20 ) ;
}
static int F_42 ( struct V_8 * V_9 )
{
struct V_3 * V_4 = F_6 ( V_9 ) ;
struct V_19 * V_19 = V_4 -> V_19 ;
int V_36 = 1 << F_12 ( V_9 ) ;
int V_29 ;
V_29 = F_9 ( V_19 , V_37 ) ;
if ( V_29 < 0 )
return V_29 ;
if ( V_29 & V_36 )
return V_92 ;
else
return V_38 ;
}
static int F_43 ( struct V_44 * V_45 )
{
struct V_19 * V_19 = F_16 ( V_45 -> V_46 . V_47 ) ;
struct V_48 * V_49 = V_19 -> V_46 -> V_50 ;
struct V_51 V_52 = { } ;
int V_53 ;
struct V_3 * V_4 ;
struct V_54 * V_55 ;
int V_29 ;
if ( V_49 && V_49 -> V_56 )
V_53 = ( V_49 -> V_56 * 10 ) + 1 ;
else
V_53 = 0 ;
V_53 = V_45 -> V_53 - V_53 ;
F_17 ( & V_45 -> V_46 , L_1 , V_53 + 1 ) ;
V_4 = F_18 ( & V_45 -> V_46 , sizeof( struct V_3 ) , V_57 ) ;
if ( V_4 == NULL ) {
F_19 ( & V_45 -> V_46 , L_2 ) ;
return - V_58 ;
}
V_4 -> V_19 = V_19 ;
V_55 = F_20 ( V_45 , V_59 , 0 ) ;
if ( V_55 == NULL ) {
F_19 ( & V_45 -> V_46 , L_3 ) ;
V_29 = - V_13 ;
goto V_60;
}
V_4 -> V_22 = V_55 -> V_61 ;
snprintf ( V_4 -> V_62 , sizeof( V_4 -> V_62 ) , L_4 , V_53 + 1 ) ;
V_4 -> V_63 . V_62 = V_4 -> V_62 ;
snprintf ( V_4 -> V_64 , sizeof( V_4 -> V_64 ) ,
L_5 , V_53 + 1 ) ;
V_4 -> V_63 . V_64 = V_4 -> V_64 ;
V_4 -> V_63 . V_53 = V_53 ;
V_4 -> V_63 . type = V_65 ;
V_4 -> V_63 . V_66 = V_93 + 1 ;
V_4 -> V_63 . V_67 = & V_94 ;
V_4 -> V_63 . V_69 = V_70 ;
V_4 -> V_63 . V_71 = V_4 -> V_22 + V_95 ;
V_4 -> V_63 . V_72 = V_91 ;
V_4 -> V_63 . V_73 = V_74 ;
V_4 -> V_63 . V_75 = 1 << V_53 ;
V_4 -> V_63 . V_14 = 800000 ;
V_4 -> V_63 . V_96 = 50000 ;
V_4 -> V_63 . V_97 = 1000 ;
V_52 . V_46 = V_45 -> V_46 . V_47 ;
if ( V_49 )
V_52 . V_79 = V_49 -> V_4 [ V_53 ] ;
V_52 . V_80 = V_4 ;
V_52 . V_81 = V_19 -> V_81 ;
V_4 -> V_5 = F_21 ( & V_4 -> V_63 , & V_52 ) ;
if ( F_22 ( V_4 -> V_5 ) ) {
V_29 = F_23 ( V_4 -> V_5 ) ;
F_19 ( V_19 -> V_46 , L_6 ,
V_53 + 1 , V_29 ) ;
goto V_60;
}
F_27 ( V_45 , V_4 ) ;
return 0 ;
V_60:
return V_29 ;
}
static int F_44 ( struct V_44 * V_45 )
{
struct V_3 * V_4 = F_30 ( V_45 ) ;
F_28 ( V_4 -> V_5 ) ;
return 0 ;
}
static int T_2 F_45 ( void )
{
int V_29 ;
V_29 = F_46 ( & V_98 ) ;
if ( V_29 != 0 )
F_47 ( L_9 , V_29 ) ;
V_29 = F_46 ( & V_99 ) ;
if ( V_29 != 0 )
F_47 ( L_10 , V_29 ) ;
V_29 = F_46 ( & V_100 ) ;
if ( V_29 != 0 )
F_47 ( L_11 ,
V_29 ) ;
return 0 ;
}
static void T_3 F_48 ( void )
{
F_49 ( & V_100 ) ;
F_49 ( & V_99 ) ;
F_49 ( & V_98 ) ;
}
