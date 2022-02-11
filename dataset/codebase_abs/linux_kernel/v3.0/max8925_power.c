static int F_1 ( struct V_1 * V_2 , int V_3 )
{
struct V_4 * V_5 = V_2 -> V_5 ;
if ( V_3 ) {
if ( V_2 -> V_6 )
V_2 -> V_6 ( 1 ) ;
F_2 ( V_2 -> V_7 , V_8 , 1 << 7 , 0 ) ;
} else {
F_2 ( V_2 -> V_7 , V_8 , 1 << 7 , 1 << 7 ) ;
if ( V_2 -> V_6 )
V_2 -> V_6 ( 0 ) ;
}
F_3 ( V_5 -> V_9 , L_1 , ( V_3 ) ? L_2
: L_3 ) ;
return 0 ;
}
static T_1 F_4 ( int V_10 , void * V_11 )
{
struct V_1 * V_2 = (struct V_1 * ) V_11 ;
struct V_4 * V_5 = V_2 -> V_5 ;
switch ( V_10 - V_5 -> V_12 ) {
case V_13 :
V_2 -> V_14 = 1 ;
F_1 ( V_2 , 1 ) ;
F_3 ( V_5 -> V_9 , L_4 ) ;
break;
case V_15 :
V_2 -> V_14 = 0 ;
F_1 ( V_2 , 0 ) ;
F_3 ( V_5 -> V_9 , L_5 ) ;
break;
case V_16 :
V_2 -> V_17 = 1 ;
F_1 ( V_2 , 1 ) ;
F_3 ( V_5 -> V_9 , L_6 ) ;
break;
case V_18 :
V_2 -> V_17 = 0 ;
F_1 ( V_2 , 0 ) ;
F_3 ( V_5 -> V_9 , L_7 ) ;
break;
case V_19 :
F_3 ( V_5 -> V_9 , L_8 ) ;
case V_20 :
F_3 ( V_5 -> V_9 , L_9 ) ;
F_1 ( V_2 , 0 ) ;
break;
case V_21 :
F_3 ( V_5 -> V_9 , L_10 ) ;
break;
case V_22 :
F_5 ( V_5 -> V_9 , L_11 ) ;
break;
case V_23 :
F_3 ( V_5 -> V_9 , L_12 ) ;
break;
case V_24 :
F_1 ( V_2 , 0 ) ;
F_3 ( V_5 -> V_9 , L_13 ) ;
break;
case V_25 :
F_3 ( V_5 -> V_9 , L_14 ) ;
break;
case V_26 :
F_1 ( V_2 , 0 ) ;
F_3 ( V_5 -> V_9 , L_15 ) ;
break;
case V_27 :
F_1 ( V_2 , 0 ) ;
F_3 ( V_5 -> V_9 , L_16 ) ;
break;
}
return V_28 ;
}
static int F_6 ( struct V_1 * V_2 , int type )
{
unsigned char V_29 [ 2 ] = { 0 , 0 } ;
int V_30 = 0 , V_31 ;
switch ( type ) {
case V_32 :
V_30 = V_33 ;
break;
case V_34 :
V_30 = V_35 ;
break;
case V_36 :
V_30 = V_37 ;
break;
case V_38 :
V_30 = V_39 ;
break;
default:
return - V_40 ;
}
F_7 ( V_2 -> V_41 , V_30 , 2 , V_29 ) ;
V_31 = ( V_29 [ 0 ] << 4 ) | ( V_29 [ 1 ] >> 4 ) ;
return V_31 ;
}
static int F_8 ( struct V_42 * V_43 ,
enum V_44 V_45 ,
union V_46 * V_47 )
{
struct V_1 * V_2 = F_9 ( V_43 -> V_9 -> V_48 ) ;
int V_31 = 0 ;
switch ( V_45 ) {
case V_49 :
V_47 -> V_50 = V_2 -> V_14 ;
break;
case V_51 :
if ( V_2 -> V_14 ) {
V_31 = F_6 ( V_2 , V_32 ) ;
if ( V_31 >= 0 ) {
V_47 -> V_50 = V_31 << 1 ;
goto V_52;
}
}
V_31 = - V_53 ;
break;
default:
V_31 = - V_54 ;
break;
}
V_52:
return V_31 ;
}
static int F_10 ( struct V_42 * V_43 ,
enum V_44 V_45 ,
union V_46 * V_47 )
{
struct V_1 * V_2 = F_9 ( V_43 -> V_9 -> V_48 ) ;
int V_31 = 0 ;
switch ( V_45 ) {
case V_49 :
V_47 -> V_50 = V_2 -> V_17 ;
break;
case V_51 :
if ( V_2 -> V_17 ) {
V_31 = F_6 ( V_2 , V_32 ) ;
if ( V_31 >= 0 ) {
V_47 -> V_50 = V_31 << 1 ;
goto V_52;
}
}
V_31 = - V_53 ;
break;
default:
V_31 = - V_54 ;
break;
}
V_52:
return V_31 ;
}
static int F_11 ( struct V_42 * V_43 ,
enum V_44 V_45 ,
union V_46 * V_47 )
{
struct V_1 * V_2 = F_9 ( V_43 -> V_9 -> V_48 ) ;
long long int V_55 = 0 ;
int V_31 = 0 ;
switch ( V_45 ) {
case V_49 :
V_47 -> V_50 = V_2 -> V_56 ;
break;
case V_51 :
if ( V_2 -> V_56 ) {
V_31 = F_6 ( V_2 , V_36 ) ;
if ( V_31 >= 0 ) {
V_47 -> V_50 = V_31 << 1 ;
V_31 = 0 ;
break;
}
}
V_31 = - V_53 ;
break;
case V_57 :
if ( V_2 -> V_56 ) {
V_31 = F_6 ( V_2 , V_38 ) ;
if ( V_31 >= 0 ) {
V_55 = ( long long int ) V_31 * 6250 / 4096 - 3125 ;
V_31 = ( int ) V_55 ;
V_47 -> V_50 = 0 ;
if ( V_31 > 0 )
V_47 -> V_50 = V_31 ;
V_31 = 0 ;
break;
}
}
V_31 = - V_53 ;
break;
case V_58 :
if ( ! V_2 -> V_56 ) {
V_31 = - V_53 ;
break;
}
V_31 = F_12 ( V_2 -> V_7 , V_59 ) ;
V_31 = ( V_31 & V_60 ) >> 2 ;
switch ( V_31 ) {
case 1 :
V_47 -> V_50 = V_61 ;
break;
case 0 :
case 2 :
V_47 -> V_50 = V_62 ;
break;
case 3 :
V_47 -> V_50 = V_63 ;
break;
}
V_31 = 0 ;
break;
case V_64 :
if ( ! V_2 -> V_56 ) {
V_31 = - V_53 ;
break;
}
V_31 = F_12 ( V_2 -> V_7 , V_59 ) ;
if ( V_2 -> V_17 || V_2 -> V_14 ) {
V_47 -> V_50 = V_65 ;
if ( V_31 & V_66 )
V_47 -> V_50 = V_67 ;
} else
V_47 -> V_50 = V_68 ;
V_31 = 0 ;
break;
default:
V_31 = - V_54 ;
break;
}
return V_31 ;
}
static T_2 int F_13 ( struct V_4 * V_5 ,
struct V_1 * V_2 )
{
int V_31 ;
F_14 ( V_20 , L_17 ) ;
F_14 ( V_15 , L_18 ) ;
F_14 ( V_13 , L_19 ) ;
F_14 ( V_69 , L_20 ) ;
F_14 ( V_18 , L_21 ) ;
F_14 ( V_16 , L_22 ) ;
F_14 ( V_21 , L_23 ) ;
F_14 ( V_19 , L_24 ) ;
F_14 ( V_23 , L_25 ) ;
F_14 ( V_22 , L_26 ) ;
F_14 ( V_27 , L_27 ) ;
F_14 ( V_24 , L_28 ) ;
F_14 ( V_25 , L_29 ) ;
F_14 ( V_26 , L_30 ) ;
V_2 -> V_14 = 0 ;
V_2 -> V_17 = 0 ;
V_2 -> V_56 = 0 ;
V_31 = F_12 ( V_2 -> V_7 , V_59 ) ;
if ( V_31 >= 0 ) {
if ( V_2 -> V_70 )
V_2 -> V_56 = ( V_31 & V_71 ) ? 0 : 1 ;
else
V_2 -> V_56 = 1 ;
if ( V_31 & V_72 )
V_2 -> V_14 = 1 ;
else
V_2 -> V_14 = 0 ;
}
F_2 ( V_2 -> V_7 , V_8 , 1 << 7 , 1 << 7 ) ;
F_2 ( V_2 -> V_7 , V_8 , 3 << 5 ,
V_2 -> V_73 << 5 ) ;
F_2 ( V_2 -> V_7 , V_8 , 7 , V_2 -> V_74 ) ;
return 0 ;
}
static T_3 int F_15 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = V_2 -> V_5 ;
int V_10 ;
V_10 = V_5 -> V_12 + V_20 ;
for (; V_10 <= V_5 -> V_12 + V_26 ; V_10 ++ )
F_16 ( V_10 , V_2 ) ;
return 0 ;
}
static T_2 int F_17 ( struct V_75 * V_76 )
{
struct V_4 * V_5 = F_9 ( V_76 -> V_9 . V_48 ) ;
struct V_77 * V_78 = NULL ;
struct V_1 * V_2 ;
int V_31 ;
V_78 = V_76 -> V_9 . V_79 ;
if ( ! V_78 ) {
F_18 ( & V_76 -> V_9 , L_31
L_32 ) ;
return - V_40 ;
}
V_2 = F_19 ( sizeof( struct V_1 ) , V_80 ) ;
if ( ! V_2 )
return - V_81 ;
V_2 -> V_5 = V_5 ;
V_2 -> V_7 = V_5 -> V_82 ;
V_2 -> V_41 = V_5 -> V_41 ;
F_20 ( V_76 , V_2 ) ;
V_2 -> V_83 . V_84 = L_33 ;
V_2 -> V_83 . type = V_85 ;
V_2 -> V_83 . V_86 = V_87 ;
V_2 -> V_83 . V_88 = F_21 ( V_87 ) ;
V_2 -> V_83 . V_89 = F_8 ;
V_31 = F_22 ( & V_76 -> V_9 , & V_2 -> V_83 ) ;
if ( V_31 )
goto V_52;
V_2 -> V_83 . V_9 -> V_48 = & V_76 -> V_9 ;
V_2 -> V_90 . V_84 = L_34 ;
V_2 -> V_90 . type = V_91 ;
V_2 -> V_90 . V_86 = V_92 ;
V_2 -> V_90 . V_88 = F_21 ( V_92 ) ;
V_2 -> V_90 . V_89 = F_10 ;
V_31 = F_22 ( & V_76 -> V_9 , & V_2 -> V_90 ) ;
if ( V_31 )
goto V_93;
V_2 -> V_90 . V_9 -> V_48 = & V_76 -> V_9 ;
V_2 -> V_94 . V_84 = L_35 ;
V_2 -> V_94 . type = V_95 ;
V_2 -> V_94 . V_86 = V_96 ;
V_2 -> V_94 . V_88 = F_21 ( V_96 ) ;
V_2 -> V_94 . V_89 = F_11 ;
V_31 = F_22 ( & V_76 -> V_9 , & V_2 -> V_94 ) ;
if ( V_31 )
goto V_97;
V_2 -> V_94 . V_9 -> V_48 = & V_76 -> V_9 ;
V_2 -> V_70 = V_78 -> V_70 ;
V_2 -> V_73 = V_78 -> V_73 ;
V_2 -> V_74 = V_78 -> V_74 ;
V_2 -> V_6 = V_78 -> V_6 ;
F_13 ( V_5 , V_2 ) ;
return 0 ;
V_97:
F_23 ( & V_2 -> V_94 ) ;
V_93:
F_23 ( & V_2 -> V_83 ) ;
V_52:
F_24 ( V_2 ) ;
return V_31 ;
}
static T_3 int F_25 ( struct V_75 * V_76 )
{
struct V_1 * V_2 = F_26 ( V_76 ) ;
if ( V_2 ) {
F_23 ( & V_2 -> V_83 ) ;
F_23 ( & V_2 -> V_90 ) ;
F_23 ( & V_2 -> V_94 ) ;
F_15 ( V_2 ) ;
F_24 ( V_2 ) ;
}
return 0 ;
}
static int T_4 F_27 ( void )
{
return F_28 ( & V_98 ) ;
}
static void T_5 F_29 ( void )
{
F_30 ( & V_98 ) ;
}
