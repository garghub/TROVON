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
static int F_20 ( struct V_1 * V_2 ,
int V_42 , int V_43 )
{
T_1 V_44 ;
if ( V_43 < 600000 || V_43 > 1800000 )
return - V_22 ;
V_44 = ( ( V_43 - 600000 ) / 12500 ) + 8 ;
if ( F_18 ( V_2 , V_44 ) < V_42 ||
F_18 ( V_2 , V_44 ) < V_43 )
return - V_22 ;
return V_44 ;
}
static int F_21 ( struct V_1 * V_2 , int V_45 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
if ( V_45 == V_4 -> V_46 )
return 0 ;
V_4 -> V_46 = V_45 ;
F_22 ( V_4 -> V_47 , V_45 ) ;
return 0 ;
}
static int F_23 ( struct V_1 * V_2 ,
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
return F_21 ( V_2 , 0 ) ;
if ( V_4 -> V_47 && V_4 -> V_52 == V_44 )
return F_21 ( V_2 , 1 ) ;
V_25 = F_6 ( V_5 , V_48 , V_53 , V_44 ) ;
if ( V_25 < 0 )
return V_25 ;
V_4 -> V_51 = V_44 ;
if ( ! V_4 -> V_47 )
return V_25 ;
V_25 = F_21 ( V_2 , 0 ) ;
if ( V_25 < 0 )
return V_25 ;
V_44 = F_20 ( V_2 , V_42 , V_43 ) ;
if ( V_44 < 0 ) {
F_24 ( V_44 < 0 ) ;
return 0 ;
}
if ( V_44 == V_4 -> V_51 )
return 0 ;
V_25 = F_6 ( V_5 , V_49 , V_54 , V_44 ) ;
if ( V_25 == 0 )
V_4 -> V_52 = V_44 ;
else
F_25 ( V_5 -> V_27 , L_4 ,
V_25 ) ;
return 0 ;
}
static int F_26 ( struct V_1 * V_2 ,
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
static int F_27 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
if ( V_4 -> V_47 && V_4 -> V_46 )
return V_4 -> V_52 ;
else
return V_4 -> V_51 ;
}
static int F_28 ( struct V_1 * V_2 ,
int V_57 , int V_58 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_5 * V_5 = V_4 -> V_5 ;
T_1 V_7 = V_4 -> V_9 + V_59 ;
int V_60 ;
for ( V_60 = 0 ; V_60 < F_29 ( V_61 ) ; V_60 ++ ) {
if ( V_58 <= V_61 [ V_60 ] )
break;
}
if ( V_60 == F_29 ( V_61 ) )
return - V_22 ;
return F_6 ( V_5 , V_7 , V_62 , V_60 ) ;
}
static int F_30 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_5 * V_5 = V_4 -> V_5 ;
T_1 V_7 = V_4 -> V_9 + V_59 ;
int V_11 ;
V_11 = F_4 ( V_5 , V_7 ) ;
if ( V_11 < 0 )
return V_11 ;
return V_61 [ V_11 & V_62 ] ;
}
static T_3 void F_31 ( struct V_3 * V_4 ,
struct V_63 * V_64 )
{
struct V_5 * V_5 = V_4 -> V_5 ;
int V_25 ;
T_1 V_65 ;
if ( ! V_64 || ! V_64 -> V_47 )
return;
switch ( V_64 -> V_66 ) {
case 1 :
V_65 = 2 << V_67 ;
break;
case 2 :
V_65 = 3 << V_67 ;
break;
default:
F_32 ( V_5 -> V_27 , L_5 ,
V_64 -> V_66 , V_4 -> V_68 ) ;
return;
}
V_25 = F_6 ( V_5 , V_4 -> V_9 + V_50 ,
V_69 , V_65 ) ;
if ( V_25 < 0 ) {
F_32 ( V_5 -> V_27 , L_6 ,
V_4 -> V_68 , V_25 ) ;
return;
}
V_25 = F_33 ( V_64 -> V_47 , L_7 ) ;
if ( V_25 < 0 ) {
F_32 ( V_5 -> V_27 , L_8 ,
V_4 -> V_68 , V_25 ) ;
return;
}
V_4 -> V_46 = V_64 -> V_70 ;
V_25 = F_34 ( V_64 -> V_47 , V_4 -> V_46 ) ;
if ( V_25 < 0 ) {
F_32 ( V_5 -> V_27 , L_9 ,
V_4 -> V_68 , V_25 ) ;
F_35 ( V_64 -> V_47 ) ;
return;
}
V_4 -> V_47 = V_64 -> V_47 ;
}
static T_3 int F_36 ( struct V_71 * V_72 )
{
struct V_5 * V_5 = F_37 ( V_72 -> V_27 . V_73 ) ;
struct V_74 * V_64 = V_5 -> V_27 -> V_75 ;
int V_76 = V_72 -> V_76 % F_29 ( V_64 -> V_4 ) ;
struct V_3 * V_4 ;
struct V_77 * V_78 ;
int V_25 , V_34 ;
F_14 ( & V_72 -> V_27 , L_10 , V_76 + 1 ) ;
if ( V_64 == NULL || V_64 -> V_4 [ V_76 ] == NULL )
return - V_79 ;
V_4 = F_38 ( sizeof( struct V_3 ) , V_80 ) ;
if ( V_4 == NULL ) {
F_32 ( & V_72 -> V_27 , L_11 ) ;
return - V_81 ;
}
V_4 -> V_5 = V_5 ;
V_78 = F_39 ( V_72 , V_82 , 0 ) ;
if ( V_78 == NULL ) {
F_32 ( & V_72 -> V_27 , L_12 ) ;
V_25 = - V_22 ;
goto V_83;
}
V_4 -> V_9 = V_78 -> V_84 ;
snprintf ( V_4 -> V_68 , sizeof( V_4 -> V_68 ) , L_13 , V_76 + 1 ) ;
V_4 -> V_85 . V_68 = V_4 -> V_68 ;
V_4 -> V_85 . V_76 = V_76 ;
V_4 -> V_85 . type = V_86 ;
V_4 -> V_85 . V_87 = V_41 + 1 ;
V_4 -> V_85 . V_88 = & V_89 ;
V_4 -> V_85 . V_90 = V_91 ;
V_25 = F_4 ( V_5 , V_4 -> V_9 + V_10 ) ;
if ( V_25 < 0 ) {
F_32 ( V_5 -> V_27 , L_14 , V_25 ) ;
goto V_83;
}
V_4 -> V_51 = V_25 & V_53 ;
V_25 = F_4 ( V_5 , V_4 -> V_9 + V_10 ) ;
if ( V_25 < 0 ) {
F_32 ( V_5 -> V_27 , L_15 , V_25 ) ;
goto V_83;
}
V_4 -> V_52 = V_25 & V_54 ;
if ( V_64 -> V_4 [ V_76 ] )
F_31 ( V_4 , V_64 -> V_4 [ V_76 ] -> V_92 ) ;
V_4 -> V_36 = F_40 ( & V_4 -> V_85 , & V_72 -> V_27 ,
V_64 -> V_4 [ V_76 ] , V_4 ) ;
if ( F_41 ( V_4 -> V_36 ) ) {
V_25 = F_42 ( V_4 -> V_36 ) ;
F_32 ( V_5 -> V_27 , L_16 ,
V_76 + 1 , V_25 ) ;
goto V_83;
}
V_34 = F_43 ( V_72 , L_17 ) ;
V_25 = F_44 ( V_34 , NULL , F_15 ,
V_93 , V_4 -> V_68 , V_4 ) ;
if ( V_25 != 0 ) {
F_32 ( & V_72 -> V_27 , L_18 ,
V_34 , V_25 ) ;
goto V_94;
}
V_34 = F_43 ( V_72 , L_19 ) ;
V_25 = F_44 ( V_34 , NULL , F_17 ,
V_93 , V_4 -> V_68 , V_4 ) ;
if ( V_25 != 0 ) {
F_32 ( & V_72 -> V_27 , L_20 ,
V_34 , V_25 ) ;
goto V_95;
}
F_45 ( V_72 , V_4 ) ;
return 0 ;
V_95:
F_46 ( F_43 ( V_72 , L_17 ) , V_4 ) ;
V_94:
F_47 ( V_4 -> V_36 ) ;
V_83:
if ( V_4 -> V_47 )
F_35 ( V_4 -> V_47 ) ;
F_48 ( V_4 ) ;
return V_25 ;
}
static T_4 int F_49 ( struct V_71 * V_72 )
{
struct V_3 * V_4 = F_50 ( V_72 ) ;
F_45 ( V_72 , NULL ) ;
F_46 ( F_43 ( V_72 , L_19 ) , V_4 ) ;
F_46 ( F_43 ( V_72 , L_17 ) , V_4 ) ;
F_47 ( V_4 -> V_36 ) ;
if ( V_4 -> V_47 )
F_35 ( V_4 -> V_47 ) ;
F_48 ( V_4 ) ;
return 0 ;
}
static int F_51 ( struct V_1 * V_2 ,
unsigned V_40 )
{
if ( V_40 <= V_96 )
return 850000 + ( V_40 * 25000 ) ;
else
return - V_22 ;
}
static int F_52 ( struct V_1 * V_2 , int V_7 ,
int V_42 , int V_43 , int * V_40 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_5 * V_5 = V_4 -> V_5 ;
T_1 V_44 ;
if ( V_42 <= 34000000 )
V_44 = ( V_42 - 850000 ) / 25000 ;
else
return - V_22 ;
if ( F_51 ( V_2 , V_44 ) > V_43 )
return - V_22 ;
* V_40 = V_44 ;
return F_6 ( V_5 , V_7 , V_97 , V_44 ) ;
}
static int F_53 ( struct V_1 * V_2 ,
int V_42 , int V_43 ,
unsigned * V_40 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
T_1 V_7 = V_4 -> V_9 + V_10 ;
return F_52 ( V_2 , V_7 , V_42 , V_43 ,
V_40 ) ;
}
static int F_54 ( struct V_1 * V_2 ,
int V_55 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
T_1 V_7 = V_4 -> V_9 + V_24 ;
unsigned V_40 ;
return F_52 ( V_2 , V_7 , V_55 , V_55 , & V_40 ) ;
}
static int F_55 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_5 * V_5 = V_4 -> V_5 ;
T_1 V_7 = V_4 -> V_9 + V_10 ;
int V_11 ;
V_11 = F_4 ( V_5 , V_7 ) ;
if ( V_11 < 0 )
return V_11 ;
return V_11 & V_97 ;
}
static T_3 int F_56 ( struct V_71 * V_72 )
{
struct V_5 * V_5 = F_37 ( V_72 -> V_27 . V_73 ) ;
struct V_74 * V_64 = V_5 -> V_27 -> V_75 ;
int V_76 = V_72 -> V_76 % F_29 ( V_64 -> V_4 ) ;
struct V_3 * V_4 ;
struct V_77 * V_78 ;
int V_25 , V_34 ;
F_14 ( & V_72 -> V_27 , L_10 , V_76 + 1 ) ;
if ( V_64 == NULL || V_64 -> V_4 [ V_76 ] == NULL )
return - V_79 ;
V_4 = F_38 ( sizeof( struct V_3 ) , V_80 ) ;
if ( V_4 == NULL ) {
F_32 ( & V_72 -> V_27 , L_11 ) ;
return - V_81 ;
}
V_4 -> V_5 = V_5 ;
V_78 = F_39 ( V_72 , V_82 , 0 ) ;
if ( V_78 == NULL ) {
F_32 ( & V_72 -> V_27 , L_12 ) ;
V_25 = - V_22 ;
goto V_83;
}
V_4 -> V_9 = V_78 -> V_84 ;
snprintf ( V_4 -> V_68 , sizeof( V_4 -> V_68 ) , L_13 , V_76 + 1 ) ;
V_4 -> V_85 . V_68 = V_4 -> V_68 ;
V_4 -> V_85 . V_76 = V_76 ;
V_4 -> V_85 . type = V_86 ;
V_4 -> V_85 . V_87 = V_96 + 1 ;
V_4 -> V_85 . V_88 = & V_98 ;
V_4 -> V_85 . V_90 = V_91 ;
V_4 -> V_36 = F_40 ( & V_4 -> V_85 , & V_72 -> V_27 ,
V_64 -> V_4 [ V_76 ] , V_4 ) ;
if ( F_41 ( V_4 -> V_36 ) ) {
V_25 = F_42 ( V_4 -> V_36 ) ;
F_32 ( V_5 -> V_27 , L_16 ,
V_76 + 1 , V_25 ) ;
goto V_83;
}
V_34 = F_43 ( V_72 , L_17 ) ;
V_25 = F_44 ( V_34 , NULL , F_15 ,
V_93 , V_4 -> V_68 , V_4 ) ;
if ( V_25 != 0 ) {
F_32 ( & V_72 -> V_27 , L_18 ,
V_34 , V_25 ) ;
goto V_94;
}
F_45 ( V_72 , V_4 ) ;
return 0 ;
V_94:
F_47 ( V_4 -> V_36 ) ;
V_83:
F_48 ( V_4 ) ;
return V_25 ;
}
static T_4 int F_57 ( struct V_71 * V_72 )
{
struct V_3 * V_4 = F_50 ( V_72 ) ;
F_45 ( V_72 , NULL ) ;
F_46 ( F_43 ( V_72 , L_17 ) , V_4 ) ;
F_47 ( V_4 -> V_36 ) ;
F_48 ( V_4 ) ;
return 0 ;
}
static int F_58 ( struct V_1 * V_2 )
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
static T_3 int F_59 ( struct V_71 * V_72 )
{
struct V_5 * V_5 = F_37 ( V_72 -> V_27 . V_73 ) ;
struct V_74 * V_64 = V_5 -> V_27 -> V_75 ;
int V_76 = V_72 -> V_76 % F_29 ( V_64 -> V_4 ) ;
struct V_3 * V_4 ;
struct V_77 * V_78 ;
int V_25 , V_34 ;
F_14 ( & V_72 -> V_27 , L_10 , V_76 + 1 ) ;
if ( V_64 == NULL || V_64 -> V_4 [ V_76 ] == NULL )
return - V_79 ;
V_4 = F_38 ( sizeof( struct V_3 ) , V_80 ) ;
if ( V_4 == NULL ) {
F_32 ( & V_72 -> V_27 , L_11 ) ;
return - V_81 ;
}
V_4 -> V_5 = V_5 ;
V_78 = F_39 ( V_72 , V_82 , 0 ) ;
if ( V_78 == NULL ) {
F_32 ( & V_72 -> V_27 , L_12 ) ;
V_25 = - V_22 ;
goto V_83;
}
V_4 -> V_9 = V_78 -> V_84 ;
snprintf ( V_4 -> V_68 , sizeof( V_4 -> V_68 ) , L_13 , V_76 + 1 ) ;
V_4 -> V_85 . V_68 = V_4 -> V_68 ;
V_4 -> V_85 . V_76 = V_76 ;
V_4 -> V_85 . type = V_86 ;
V_4 -> V_85 . V_88 = & V_99 ;
V_4 -> V_85 . V_90 = V_91 ;
V_4 -> V_36 = F_40 ( & V_4 -> V_85 , & V_72 -> V_27 ,
V_64 -> V_4 [ V_76 ] , V_4 ) ;
if ( F_41 ( V_4 -> V_36 ) ) {
V_25 = F_42 ( V_4 -> V_36 ) ;
F_32 ( V_5 -> V_27 , L_16 ,
V_76 + 1 , V_25 ) ;
goto V_83;
}
V_34 = F_43 ( V_72 , L_17 ) ;
V_25 = F_44 ( V_34 , NULL , F_15 ,
V_93 , V_4 -> V_68 ,
V_4 ) ;
if ( V_25 != 0 ) {
F_32 ( & V_72 -> V_27 , L_18 ,
V_34 , V_25 ) ;
goto V_94;
}
F_45 ( V_72 , V_4 ) ;
return 0 ;
V_94:
F_47 ( V_4 -> V_36 ) ;
V_83:
F_48 ( V_4 ) ;
return V_25 ;
}
static T_4 int F_60 ( struct V_71 * V_72 )
{
struct V_3 * V_4 = F_50 ( V_72 ) ;
F_45 ( V_72 , NULL ) ;
F_46 ( F_43 ( V_72 , L_17 ) , V_4 ) ;
F_47 ( V_4 -> V_36 ) ;
F_48 ( V_4 ) ;
return 0 ;
}
static T_3 int F_61 ( struct V_71 * V_72 )
{
struct V_5 * V_5 = F_37 ( V_72 -> V_27 . V_73 ) ;
struct V_74 * V_64 = V_5 -> V_27 -> V_75 ;
int V_76 = V_72 -> V_76 % F_29 ( V_64 -> V_100 ) ;
struct V_3 * V_4 ;
int V_25 ;
F_14 ( & V_72 -> V_27 , L_21 , V_76 + 1 ) ;
if ( V_64 == NULL || V_64 -> V_100 [ V_76 ] == NULL )
return - V_79 ;
V_4 = F_38 ( sizeof( struct V_3 ) , V_80 ) ;
if ( V_4 == NULL ) {
F_32 ( & V_72 -> V_27 , L_11 ) ;
return - V_81 ;
}
V_4 -> V_5 = V_5 ;
snprintf ( V_4 -> V_68 , sizeof( V_4 -> V_68 ) , L_22 , V_76 + 1 ) ;
V_4 -> V_85 . V_68 = V_4 -> V_68 ;
V_4 -> V_85 . V_76 = V_76 + V_101 ;
V_4 -> V_85 . V_88 = & V_102 ;
V_4 -> V_85 . type = V_86 ;
V_4 -> V_85 . V_90 = V_91 ;
V_4 -> V_36 = F_40 ( & V_4 -> V_85 , & V_72 -> V_27 ,
V_64 -> V_100 [ V_76 ] , V_4 ) ;
if ( F_41 ( V_4 -> V_36 ) ) {
V_25 = F_42 ( V_4 -> V_36 ) ;
F_32 ( V_5 -> V_27 , L_23 ,
V_76 + 1 , V_25 ) ;
goto V_83;
}
F_45 ( V_72 , V_4 ) ;
return 0 ;
V_83:
F_48 ( V_4 ) ;
return V_25 ;
}
static T_4 int F_62 ( struct V_71 * V_72 )
{
struct V_3 * V_4 = F_50 ( V_72 ) ;
F_45 ( V_72 , NULL ) ;
F_47 ( V_4 -> V_36 ) ;
F_48 ( V_4 ) ;
return 0 ;
}
static int T_5 F_63 ( void )
{
int V_25 ;
V_25 = F_64 ( & V_103 ) ;
if ( V_25 != 0 )
F_65 ( L_24 , V_25 ) ;
V_25 = F_64 ( & V_104 ) ;
if ( V_25 != 0 )
F_65 ( L_25 , V_25 ) ;
V_25 = F_64 ( & V_105 ) ;
if ( V_25 != 0 )
F_65 ( L_26 , V_25 ) ;
V_25 = F_64 ( & V_106 ) ;
if ( V_25 != 0 )
F_65 ( L_27 , V_25 ) ;
return 0 ;
}
static void T_6 F_66 ( void )
{
F_67 ( & V_106 ) ;
F_67 ( & V_105 ) ;
F_67 ( & V_104 ) ;
F_67 ( & V_103 ) ;
}
