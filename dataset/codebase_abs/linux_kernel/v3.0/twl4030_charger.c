static int F_1 ( T_1 V_1 , T_1 V_2 , T_1 V_3 , T_1 V_4 )
{
T_1 V_5 = 0 ;
int V_6 ;
V_6 = F_2 ( V_1 , & V_5 , V_4 ) ;
if ( V_6 )
return V_6 ;
V_5 &= ~ V_2 ;
V_5 |= V_3 ;
return F_3 ( V_1 , V_5 , V_4 ) ;
}
static int F_4 ( T_1 V_4 , T_1 * V_5 )
{
return F_2 ( V_7 , V_5 , V_4 ) ;
}
static int F_5 ( T_1 V_2 , T_1 V_3 )
{
return F_1 ( V_8 , 0 ,
V_9 | V_10 | V_3 ,
V_11 ) ;
}
static int F_6 ( T_1 V_4 )
{
int V_6 , V_12 ;
T_1 V_5 ;
V_6 = F_4 ( V_4 + 1 , & V_5 ) ;
if ( V_6 )
return V_6 ;
V_12 = ( int ) ( V_5 & 0x03 ) << 8 ;
V_6 = F_4 ( V_4 , & V_5 ) ;
if ( V_6 )
return V_6 ;
return V_12 | V_5 ;
}
static int F_7 ( struct V_13 * V_14 )
{
int V_6 ;
T_1 V_15 ;
V_6 = F_2 ( V_8 , & V_15 ,
V_16 ) ;
if ( V_6 < 0 )
return 0 ;
F_8 ( V_14 -> V_17 , L_1 , V_15 ) ;
if ( ( V_15 & V_18 ) && ! ( V_15 & V_19 ) )
return 1 ;
return 0 ;
}
static int F_9 ( struct V_13 * V_14 , bool V_20 )
{
int V_6 ;
if ( V_20 ) {
if ( ! F_7 ( V_14 ) )
return - V_21 ;
if ( ! V_22 ) {
F_10 ( V_14 -> V_17 , L_2 ) ;
return - V_23 ;
}
V_6 = F_5 ( 0 , V_24 ) ;
if ( V_6 < 0 )
return V_6 ;
V_6 = F_1 ( V_7 , 0 ,
V_25 , V_26 ) ;
} else {
V_6 = F_5 ( V_24 , 0 ) ;
}
return V_6 ;
}
static int F_11 ( bool V_20 )
{
int V_6 ;
if ( V_20 )
V_6 = F_5 ( 0 , V_27 ) ;
else
V_6 = F_5 ( V_27 , 0 ) ;
return V_6 ;
}
static T_2 F_12 ( int V_28 , void * V_29 )
{
struct V_13 * V_14 = V_29 ;
F_8 ( V_14 -> V_17 , L_3 ) ;
F_13 ( & V_14 -> V_30 ) ;
F_13 ( & V_14 -> V_31 ) ;
return V_32 ;
}
static T_2 F_14 ( int V_28 , void * V_29 )
{
struct V_13 * V_14 = V_29 ;
T_1 V_33 , V_34 ;
int V_6 ;
V_6 = F_2 ( V_35 , & V_33 ,
V_36 ) ;
if ( V_6 < 0 )
return V_32 ;
V_6 = F_2 ( V_35 , & V_34 ,
V_37 ) ;
if ( V_6 < 0 )
return V_32 ;
F_8 ( V_14 -> V_17 , L_4 , V_34 , V_33 ) ;
if ( V_33 & ( V_38 | V_39 ) ) {
F_13 ( & V_14 -> V_30 ) ;
F_13 ( & V_14 -> V_31 ) ;
}
if ( V_33 & ( V_40 | V_41 ) )
F_10 ( V_14 -> V_17 , L_5 ) ;
if ( V_33 & V_42 )
F_15 ( V_14 -> V_17 , L_6 ) ;
if ( V_34 & V_43 )
F_15 ( V_14 -> V_17 , L_7 ) ;
if ( V_34 & V_44 )
F_15 ( V_14 -> V_17 , L_8 ) ;
if ( V_34 & V_45 )
F_15 ( V_14 -> V_17 , L_9 ) ;
return V_32 ;
}
static void F_16 ( struct V_46 * V_47 )
{
struct V_13 * V_14 = F_17 ( V_47 , struct V_13 , V_48 ) ;
switch ( V_14 -> V_49 ) {
case V_50 :
case V_51 :
F_9 ( V_14 , true ) ;
break;
case V_52 :
F_9 ( V_14 , false ) ;
break;
}
}
static int F_18 ( struct V_53 * V_54 , unsigned long V_5 ,
void * V_55 )
{
struct V_13 * V_14 = F_17 ( V_54 , struct V_13 , V_56 ) ;
F_8 ( V_14 -> V_17 , L_10 , V_5 ) ;
V_14 -> V_49 = V_5 ;
F_19 ( & V_14 -> V_48 ) ;
return V_57 ;
}
static int F_20 ( void )
{
int V_58 ;
int V_6 ;
T_1 V_59 ;
V_58 = F_6 ( V_60 ) ;
if ( V_58 < 0 )
return V_58 ;
V_6 = F_4 ( V_61 , & V_59 ) ;
if ( V_6 )
return V_6 ;
V_6 = ( V_58 * 16618 - 850 * 10000 ) / 10 ;
if ( V_59 & V_62 )
V_6 *= 2 ;
return V_6 ;
}
static int F_21 ( struct V_13 * V_14 )
{
int V_6 ;
T_1 V_63 ;
V_6 = F_4 ( V_64 , & V_63 ) ;
if ( V_6 ) {
F_22 ( L_11 ) ;
return V_6 ;
}
F_8 ( V_14 -> V_17 , L_12 , V_63 ) ;
return V_63 ;
}
static int F_23 ( int V_63 )
{
V_63 &= V_65 ;
if ( V_66 <= V_63 && V_63 <= V_67 )
return V_68 ;
else if ( V_69 <= V_63 &&
V_63 <= V_70 )
return V_71 ;
else
return V_72 ;
}
static int F_24 ( struct V_73 * V_74 ,
enum V_75 V_76 ,
union V_77 * V_5 )
{
struct V_13 * V_14 = F_25 ( V_74 -> V_17 -> V_78 ) ;
int V_79 ;
int V_63 ;
int V_6 ;
V_63 = F_21 ( V_14 ) ;
if ( V_63 < 0 )
return V_63 ;
if ( V_74 -> type == V_80 )
V_79 = V_63 & V_81 ;
else
V_79 = V_63 & V_82 ;
switch ( V_76 ) {
case V_83 :
if ( V_79 )
V_5 -> V_84 = F_23 ( V_63 ) ;
else
V_5 -> V_84 = V_72 ;
break;
case V_85 :
if ( ! V_79 )
return - V_86 ;
if ( V_74 -> type == V_80 ) {
V_6 = F_6 ( V_87 ) ;
if ( V_6 < 0 )
return V_6 ;
V_5 -> V_84 = V_6 * 6843 ;
} else {
V_6 = F_6 ( V_88 ) ;
if ( V_6 < 0 )
return V_6 ;
V_5 -> V_84 = V_6 * 9775 ;
}
break;
case V_89 :
if ( ! V_79 )
return - V_86 ;
V_6 = F_20 () ;
if ( V_6 < 0 )
return V_6 ;
V_5 -> V_84 = V_6 ;
break;
case V_90 :
V_5 -> V_84 = V_79 &&
F_23 ( V_63 ) !=
V_72 ;
break;
default:
return - V_91 ;
}
return 0 ;
}
static int T_3 F_26 ( struct V_92 * V_93 )
{
struct V_13 * V_14 ;
int V_6 ;
int V_4 ;
V_14 = F_27 ( sizeof( * V_14 ) , V_94 ) ;
if ( V_14 == NULL )
return - V_95 ;
V_14 -> V_17 = & V_93 -> V_17 ;
V_14 -> V_96 = F_28 ( V_93 , 0 ) ;
V_14 -> V_97 = F_28 ( V_93 , 1 ) ;
F_29 ( V_93 , V_14 ) ;
V_14 -> V_30 . V_98 = L_13 ;
V_14 -> V_30 . type = V_99 ;
V_14 -> V_30 . V_100 = V_101 ;
V_14 -> V_30 . V_102 = F_30 ( V_101 ) ;
V_14 -> V_30 . V_103 = F_24 ;
V_6 = F_31 ( & V_93 -> V_17 , & V_14 -> V_30 ) ;
if ( V_6 ) {
F_32 ( & V_93 -> V_17 , L_14 , V_6 ) ;
goto V_104;
}
V_14 -> V_31 . V_98 = L_15 ;
V_14 -> V_31 . type = V_80 ;
V_14 -> V_31 . V_100 = V_101 ;
V_14 -> V_31 . V_102 = F_30 ( V_101 ) ;
V_14 -> V_31 . V_103 = F_24 ;
V_6 = F_31 ( & V_93 -> V_17 , & V_14 -> V_31 ) ;
if ( V_6 ) {
F_32 ( & V_93 -> V_17 , L_16 , V_6 ) ;
goto V_105;
}
V_6 = F_33 ( V_14 -> V_96 , NULL ,
F_12 , 0 , V_93 -> V_98 , V_14 ) ;
if ( V_6 < 0 ) {
F_32 ( & V_93 -> V_17 , L_17 ,
V_14 -> V_96 , V_6 ) ;
goto V_106;
}
V_6 = F_33 ( V_14 -> V_97 , NULL ,
F_14 , 0 , V_93 -> V_98 , V_14 ) ;
if ( V_6 < 0 ) {
F_32 ( & V_93 -> V_17 , L_17 ,
V_14 -> V_97 , V_6 ) ;
goto V_107;
}
F_34 ( & V_14 -> V_48 , F_16 ) ;
V_14 -> V_108 = F_35 () ;
if ( V_14 -> V_108 != NULL ) {
V_14 -> V_56 . V_109 = F_18 ;
F_36 ( V_14 -> V_108 , & V_14 -> V_56 ) ;
}
V_4 = ~ ( V_38 | V_39 | V_40 |
V_41 | V_42 ) ;
V_6 = F_3 ( V_35 , V_4 ,
V_110 ) ;
if ( V_6 < 0 ) {
F_32 ( & V_93 -> V_17 , L_18 , V_6 ) ;
goto V_111;
}
V_4 = ~ ( V_43 | V_44 | V_45 ) ;
V_6 = F_3 ( V_35 , V_4 ,
V_112 ) ;
if ( V_6 < 0 )
F_10 ( & V_93 -> V_17 , L_18 , V_6 ) ;
F_11 ( true ) ;
F_9 ( V_14 , true ) ;
return 0 ;
V_111:
if ( V_14 -> V_108 != NULL ) {
F_37 ( V_14 -> V_108 , & V_14 -> V_56 ) ;
F_38 ( V_14 -> V_108 ) ;
}
F_39 ( V_14 -> V_97 , V_14 ) ;
V_107:
F_39 ( V_14 -> V_96 , V_14 ) ;
V_106:
F_40 ( & V_14 -> V_31 ) ;
V_105:
F_40 ( & V_14 -> V_30 ) ;
V_104:
F_29 ( V_93 , NULL ) ;
F_41 ( V_14 ) ;
return V_6 ;
}
static int T_4 F_42 ( struct V_92 * V_93 )
{
struct V_13 * V_14 = F_43 ( V_93 ) ;
F_11 ( false ) ;
F_9 ( V_14 , false ) ;
F_3 ( V_35 , 0xff ,
V_110 ) ;
F_3 ( V_35 , 0xff ,
V_112 ) ;
if ( V_14 -> V_108 != NULL ) {
F_37 ( V_14 -> V_108 , & V_14 -> V_56 ) ;
F_38 ( V_14 -> V_108 ) ;
}
F_39 ( V_14 -> V_97 , V_14 ) ;
F_39 ( V_14 -> V_96 , V_14 ) ;
F_40 ( & V_14 -> V_31 ) ;
F_40 ( & V_14 -> V_30 ) ;
F_29 ( V_93 , NULL ) ;
F_41 ( V_14 ) ;
return 0 ;
}
static int T_3 F_44 ( void )
{
return F_45 ( & V_113 , F_26 ) ;
}
static void T_4 F_46 ( void )
{
F_47 ( & V_113 ) ;
}
