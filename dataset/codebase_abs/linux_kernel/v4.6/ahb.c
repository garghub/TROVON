static inline struct V_1 * F_1 ( struct V_2 * V_3 )
{
return & ( (struct V_4 * ) V_3 -> V_5 ) -> V_6 [ 0 ] ;
}
static void F_2 ( struct V_2 * V_3 , T_1 V_7 , T_1 V_8 )
{
struct V_1 * V_9 = F_1 ( V_3 ) ;
F_3 ( V_8 , V_9 -> V_10 + V_7 ) ;
}
static T_1 F_4 ( struct V_2 * V_3 , T_1 V_7 )
{
struct V_1 * V_9 = F_1 ( V_3 ) ;
return F_5 ( V_9 -> V_10 + V_7 ) ;
}
static T_1 F_6 ( struct V_2 * V_3 , T_1 V_7 )
{
struct V_1 * V_9 = F_1 ( V_3 ) ;
return F_5 ( V_9 -> V_11 + V_7 ) ;
}
static void F_7 ( struct V_2 * V_3 , T_1 V_7 , T_1 V_8 )
{
struct V_1 * V_9 = F_1 ( V_3 ) ;
F_3 ( V_8 , V_9 -> V_12 + V_7 ) ;
}
static T_1 F_8 ( struct V_2 * V_3 , T_1 V_7 )
{
struct V_1 * V_9 = F_1 ( V_3 ) ;
return F_5 ( V_9 -> V_12 + V_7 ) ;
}
static T_1 F_9 ( struct V_2 * V_3 , T_1 V_13 )
{
return F_4 ( V_3 , V_14 + V_13 ) ;
}
static int F_10 ( struct V_2 * V_3 )
{
if ( V_3 -> V_15 == V_16 )
return 1 ;
F_11 ( V_3 , L_1 ) ;
return 1 ;
}
static int F_12 ( struct V_2 * V_3 )
{
struct V_1 * V_9 = F_1 ( V_3 ) ;
struct V_17 * V_18 ;
int V_19 ;
V_18 = & V_9 -> V_20 -> V_18 ;
V_9 -> V_21 = F_13 ( V_18 , L_2 ) ;
if ( F_14 ( V_9 -> V_21 ) ) {
F_15 ( V_3 , L_3 ,
F_16 ( V_9 -> V_21 ) ) ;
V_19 = V_9 -> V_21 ? F_16 ( V_9 -> V_21 ) : - V_22 ;
goto V_23;
}
V_9 -> V_24 = F_13 ( V_18 , L_4 ) ;
if ( F_14 ( V_9 -> V_24 ) ) {
F_15 ( V_3 , L_5 ,
F_16 ( V_9 -> V_24 ) ) ;
V_19 = V_9 -> V_24 ? F_16 ( V_9 -> V_24 ) : - V_22 ;
goto V_25;
}
V_9 -> V_26 = F_13 ( V_18 , L_6 ) ;
if ( F_14 ( V_9 -> V_26 ) ) {
F_15 ( V_3 , L_7 ,
F_16 ( V_9 -> V_26 ) ) ;
V_19 = V_9 -> V_26 ? F_16 ( V_9 -> V_26 ) : - V_22 ;
goto V_27;
}
return 0 ;
V_27:
F_17 ( V_9 -> V_24 ) ;
V_25:
F_17 ( V_9 -> V_21 ) ;
V_23:
return V_19 ;
}
static void F_18 ( struct V_2 * V_3 )
{
struct V_1 * V_9 = F_1 ( V_3 ) ;
if ( ! F_14 ( V_9 -> V_21 ) )
F_17 ( V_9 -> V_21 ) ;
if ( ! F_14 ( V_9 -> V_24 ) )
F_17 ( V_9 -> V_24 ) ;
if ( ! F_14 ( V_9 -> V_26 ) )
F_17 ( V_9 -> V_26 ) ;
V_9 -> V_21 = NULL ;
V_9 -> V_24 = NULL ;
V_9 -> V_26 = NULL ;
}
static int F_19 ( struct V_2 * V_3 )
{
struct V_1 * V_9 = F_1 ( V_3 ) ;
struct V_17 * V_18 ;
int V_19 ;
V_18 = & V_9 -> V_20 -> V_18 ;
if ( F_14 ( V_9 -> V_21 ) ||
F_14 ( V_9 -> V_24 ) ||
F_14 ( V_9 -> V_26 ) ) {
F_15 ( V_3 , L_8 ) ;
V_19 = - V_28 ;
goto V_23;
}
V_19 = F_20 ( V_9 -> V_21 ) ;
if ( V_19 ) {
F_15 ( V_3 , L_9 , V_19 ) ;
goto V_23;
}
V_19 = F_20 ( V_9 -> V_24 ) ;
if ( V_19 ) {
F_15 ( V_3 , L_10 , V_19 ) ;
goto V_29;
}
V_19 = F_20 ( V_9 -> V_26 ) ;
if ( V_19 ) {
F_15 ( V_3 , L_11 , V_19 ) ;
goto V_30;
}
return 0 ;
V_30:
F_21 ( V_9 -> V_24 ) ;
V_29:
F_21 ( V_9 -> V_21 ) ;
V_23:
return V_19 ;
}
static void F_22 ( struct V_2 * V_3 )
{
struct V_1 * V_9 = F_1 ( V_3 ) ;
if ( ! F_14 ( V_9 -> V_21 ) )
F_21 ( V_9 -> V_21 ) ;
if ( ! F_14 ( V_9 -> V_24 ) )
F_21 ( V_9 -> V_24 ) ;
if ( ! F_14 ( V_9 -> V_26 ) )
F_21 ( V_9 -> V_26 ) ;
}
static int F_23 ( struct V_2 * V_3 )
{
struct V_1 * V_9 = F_1 ( V_3 ) ;
struct V_17 * V_18 ;
int V_19 ;
V_18 = & V_9 -> V_20 -> V_18 ;
V_9 -> V_31 = F_24 ( V_18 , L_12 ) ;
if ( F_14 ( V_9 -> V_31 ) ) {
F_15 ( V_3 , L_13 ,
F_16 ( V_9 -> V_31 ) ) ;
V_19 = V_9 -> V_31 ?
F_16 ( V_9 -> V_31 ) : - V_22 ;
goto V_23;
}
V_9 -> V_32 = F_24 ( V_18 , L_14 ) ;
if ( F_14 ( V_9 -> V_32 ) ) {
F_15 ( V_3 , L_15 ,
F_16 ( V_9 -> V_32 ) ) ;
V_19 = V_9 -> V_32 ?
F_16 ( V_9 -> V_32 ) : - V_22 ;
goto V_33;
}
V_9 -> V_34 = F_24 ( V_18 , L_16 ) ;
if ( F_14 ( V_9 -> V_34 ) ) {
F_15 ( V_3 , L_17 ,
F_16 ( V_9 -> V_34 ) ) ;
V_19 = V_9 -> V_34 ?
F_16 ( V_9 -> V_34 ) : - V_22 ;
goto V_35;
}
V_9 -> V_36 = F_24 ( V_18 , L_18 ) ;
if ( F_14 ( V_9 -> V_36 ) ) {
F_15 ( V_3 , L_19 ,
F_16 ( V_9 -> V_36 ) ) ;
V_19 = V_9 -> V_36 ?
F_16 ( V_9 -> V_36 ) : - V_22 ;
goto V_37;
}
V_9 -> V_38 = F_24 ( V_18 , L_20 ) ;
if ( F_14 ( V_9 -> V_38 ) ) {
F_15 ( V_3 , L_21 ,
F_16 ( V_9 -> V_38 ) ) ;
V_19 = V_9 -> V_38 ?
F_16 ( V_9 -> V_38 ) : - V_22 ;
goto V_39;
}
return 0 ;
V_39:
F_25 ( V_9 -> V_36 ) ;
V_37:
F_25 ( V_9 -> V_34 ) ;
V_35:
F_25 ( V_9 -> V_32 ) ;
V_33:
F_25 ( V_9 -> V_31 ) ;
V_23:
return V_19 ;
}
static void F_26 ( struct V_2 * V_3 )
{
struct V_1 * V_9 = F_1 ( V_3 ) ;
if ( ! F_14 ( V_9 -> V_31 ) )
F_25 ( V_9 -> V_31 ) ;
if ( ! F_14 ( V_9 -> V_32 ) )
F_25 ( V_9 -> V_32 ) ;
if ( ! F_14 ( V_9 -> V_34 ) )
F_25 ( V_9 -> V_34 ) ;
if ( ! F_14 ( V_9 -> V_36 ) )
F_25 ( V_9 -> V_36 ) ;
if ( ! F_14 ( V_9 -> V_38 ) )
F_25 ( V_9 -> V_38 ) ;
V_9 -> V_31 = NULL ;
V_9 -> V_32 = NULL ;
V_9 -> V_34 = NULL ;
V_9 -> V_36 = NULL ;
V_9 -> V_38 = NULL ;
}
static int F_27 ( struct V_2 * V_3 )
{
struct V_1 * V_9 = F_1 ( V_3 ) ;
int V_19 ;
if ( F_14 ( V_9 -> V_32 ) ||
F_14 ( V_9 -> V_34 ) ||
F_14 ( V_9 -> V_36 ) ||
F_14 ( V_9 -> V_38 ) ) {
F_15 ( V_3 , L_22 ) ;
return - V_40 ;
}
V_19 = F_28 ( V_9 -> V_32 ) ;
if ( V_19 ) {
F_15 ( V_3 , L_23 , V_19 ) ;
return V_19 ;
}
V_19 = F_28 ( V_9 -> V_34 ) ;
if ( V_19 ) {
F_15 ( V_3 , L_24 , V_19 ) ;
return V_19 ;
}
V_19 = F_28 ( V_9 -> V_36 ) ;
if ( V_19 ) {
F_15 ( V_3 , L_25 , V_19 ) ;
return V_19 ;
}
V_19 = F_28 ( V_9 -> V_38 ) ;
if ( V_19 ) {
F_15 ( V_3 , L_26 , V_19 ) ;
return V_19 ;
}
return 0 ;
}
static void F_29 ( struct V_2 * V_3 , T_1 V_41 ,
T_1 V_42 )
{
unsigned long V_43 ;
T_1 V_44 ;
V_44 = F_8 ( V_3 , V_41 ) ;
V_44 |= V_45 ;
F_7 ( V_3 , V_41 , V_44 ) ;
V_43 = V_46 + F_30 ( V_47 ) ;
do {
V_44 = F_8 ( V_3 , V_42 ) ;
if ( V_44 & V_48 )
break;
F_31 ( 1 ) ;
} while ( F_32 ( V_46 , V_43 ) );
if ( ! ( V_44 & V_48 ) ) {
F_15 ( V_3 , L_27 , V_44 ) ;
return;
}
F_33 ( V_3 , V_49 , L_28 ) ;
}
static void F_34 ( struct V_2 * V_3 )
{
struct V_1 * V_9 = F_1 ( V_3 ) ;
T_1 V_50 , V_51 , V_41 , V_42 ;
T_1 V_44 ;
int V_19 ;
if ( F_14 ( V_9 -> V_31 ) ||
F_14 ( V_9 -> V_32 ) ||
F_14 ( V_9 -> V_34 ) ||
F_14 ( V_9 -> V_36 ) ||
F_14 ( V_9 -> V_38 ) ) {
F_15 ( V_3 , L_22 ) ;
return;
}
V_50 = F_4 ( V_3 , V_52 ) ;
switch ( V_50 ) {
case 0 :
V_51 = V_53 ;
V_41 = V_54 ;
V_42 = V_55 ;
break;
case 1 :
V_51 = V_56 ;
V_41 = V_57 ;
V_42 = V_58 ;
break;
default:
F_15 ( V_3 , L_29 ,
V_50 ) ;
return;
}
F_29 ( V_3 , V_41 , V_42 ) ;
V_44 = F_8 ( V_3 , V_51 ) ;
V_44 |= V_59 ;
F_7 ( V_3 , V_51 , V_44 ) ;
V_19 = F_35 ( V_9 -> V_31 ) ;
if ( V_19 )
F_15 ( V_3 , L_30 , V_19 ) ;
F_36 ( 1 ) ;
V_19 = F_35 ( V_9 -> V_32 ) ;
if ( V_19 )
F_15 ( V_3 , L_31 , V_19 ) ;
F_36 ( 1 ) ;
V_19 = F_35 ( V_9 -> V_34 ) ;
if ( V_19 )
F_15 ( V_3 , L_32 , V_19 ) ;
F_36 ( 1 ) ;
V_19 = F_35 ( V_9 -> V_36 ) ;
if ( V_19 )
F_15 ( V_3 , L_33 , V_19 ) ;
F_36 ( 1 ) ;
V_19 = F_35 ( V_9 -> V_38 ) ;
if ( V_19 )
F_15 ( V_3 , L_34 , V_19 ) ;
F_36 ( 10 ) ;
V_44 = F_8 ( V_3 , V_41 ) ;
V_44 &= ~ V_45 ;
F_7 ( V_3 , V_41 , V_44 ) ;
V_44 = F_8 ( V_3 , V_51 ) ;
V_44 &= ~ V_59 ;
F_7 ( V_3 , V_51 , V_44 ) ;
V_19 = F_28 ( V_9 -> V_31 ) ;
if ( V_19 )
F_15 ( V_3 , L_35 , V_19 ) ;
F_33 ( V_3 , V_49 , L_36 , V_50 ) ;
}
static T_2 F_37 ( int V_60 , void * V_61 )
{
struct V_2 * V_3 = V_61 ;
struct V_4 * V_62 = F_38 ( V_3 ) ;
if ( ! F_39 ( V_3 ) )
return V_63 ;
F_40 ( V_3 ) ;
F_41 ( & V_62 -> V_64 ) ;
return V_65 ;
}
static int F_42 ( struct V_2 * V_3 )
{
struct V_1 * V_9 = F_1 ( V_3 ) ;
int V_19 ;
V_19 = F_43 ( V_9 -> V_60 ,
F_37 ,
V_66 , L_37 , V_3 ) ;
if ( V_19 ) {
F_11 ( V_3 , L_38 ,
V_9 -> V_60 , V_19 ) ;
return V_19 ;
}
return 0 ;
}
static void F_44 ( struct V_2 * V_3 )
{
struct V_1 * V_9 = F_1 ( V_3 ) ;
F_45 ( V_9 -> V_60 , V_3 ) ;
}
static void F_46 ( struct V_2 * V_3 )
{
F_47 ( V_3 ) ;
F_40 ( V_3 ) ;
}
static int F_48 ( struct V_2 * V_3 )
{
struct V_1 * V_9 = F_1 ( V_3 ) ;
struct V_67 * V_20 ;
struct V_17 * V_18 ;
struct V_68 * V_69 ;
int V_19 ;
V_20 = V_9 -> V_20 ;
V_18 = & V_20 -> V_18 ;
V_69 = F_49 ( V_20 , V_70 , 0 ) ;
if ( ! V_69 ) {
F_15 ( V_3 , L_39 ) ;
V_19 = - V_71 ;
goto V_23;
}
V_9 -> V_10 = F_50 ( & V_20 -> V_18 , V_69 ) ;
if ( F_51 ( V_9 -> V_10 ) ) {
F_15 ( V_3 , L_40 ) ;
V_19 = F_16 ( V_9 -> V_10 ) ;
goto V_23;
}
V_9 -> V_72 = F_52 ( V_69 ) ;
V_9 -> V_11 = F_53 ( V_73 ,
V_74 ) ;
if ( ! V_9 -> V_11 ) {
F_15 ( V_3 , L_41 ) ;
V_19 = - V_75 ;
goto V_76;
}
V_9 -> V_12 = F_53 ( V_77 ,
V_78 ) ;
if ( ! V_9 -> V_12 ) {
F_15 ( V_3 , L_42 ) ;
V_19 = - V_75 ;
goto V_79;
}
V_19 = F_54 ( & V_20 -> V_18 , F_55 ( 32 ) ) ;
if ( V_19 ) {
F_15 ( V_3 , L_43 , V_19 ) ;
goto V_80;
}
V_19 = F_56 ( & V_20 -> V_18 , F_55 ( 32 ) ) ;
if ( V_19 ) {
F_15 ( V_3 , L_44 ,
V_19 ) ;
goto V_80;
}
V_19 = F_12 ( V_3 ) ;
if ( V_19 )
goto V_80;
V_19 = F_23 ( V_3 ) ;
if ( V_19 )
goto V_81;
V_9 -> V_60 = F_57 ( V_20 , L_45 ) ;
if ( V_9 -> V_60 < 0 ) {
F_15 ( V_3 , L_46 , V_9 -> V_60 ) ;
goto V_81;
}
F_33 ( V_3 , V_82 , L_47 , V_9 -> V_60 ) ;
F_33 ( V_3 , V_82 , L_48 ,
V_9 -> V_10 , V_9 -> V_72 ,
V_9 -> V_11 , V_9 -> V_12 ) ;
return 0 ;
V_81:
F_18 ( V_3 ) ;
V_80:
F_58 ( V_9 -> V_12 ) ;
V_79:
V_9 -> V_12 = NULL ;
F_58 ( V_9 -> V_11 ) ;
V_76:
V_9 -> V_11 = NULL ;
F_59 ( & V_20 -> V_18 , V_9 -> V_10 ) ;
V_23:
V_9 -> V_10 = NULL ;
return V_19 ;
}
static void F_60 ( struct V_2 * V_3 )
{
struct V_1 * V_9 = F_1 ( V_3 ) ;
struct V_17 * V_18 ;
V_18 = & V_9 -> V_20 -> V_18 ;
if ( V_9 -> V_10 )
F_59 ( V_18 , V_9 -> V_10 ) ;
if ( V_9 -> V_11 )
F_58 ( V_9 -> V_11 ) ;
if ( V_9 -> V_12 )
F_58 ( V_9 -> V_12 ) ;
V_9 -> V_10 = NULL ;
V_9 -> V_11 = NULL ;
V_9 -> V_12 = NULL ;
F_18 ( V_3 ) ;
F_26 ( V_3 ) ;
}
static int F_61 ( struct V_2 * V_3 )
{
T_1 V_44 ;
int V_19 ;
V_19 = F_19 ( V_3 ) ;
if ( V_19 ) {
F_15 ( V_3 , L_49 ) ;
return V_19 ;
}
V_44 = F_6 ( V_3 , V_83 ) ;
F_2 ( V_3 , V_84 , V_44 ) ;
V_19 = F_27 ( V_3 ) ;
if ( V_19 )
goto V_85;
F_46 ( V_3 ) ;
F_2 ( V_3 , V_86 , V_87 ) ;
V_19 = F_62 ( V_3 ) ;
if ( V_19 )
goto V_88;
return 0 ;
V_88:
F_34 ( V_3 ) ;
V_85:
F_22 ( V_3 ) ;
return V_19 ;
}
static int F_63 ( struct V_2 * V_3 )
{
int V_19 ;
F_34 ( V_3 ) ;
F_22 ( V_3 ) ;
V_19 = F_61 ( V_3 ) ;
if ( V_19 )
return V_19 ;
return 0 ;
}
static int F_64 ( struct V_2 * V_3 )
{
T_1 V_13 , V_44 ;
V_13 = V_89 | V_90 ;
V_44 = F_4 ( V_3 , V_13 ) ;
V_44 |= V_91 ;
F_2 ( V_3 , V_13 , V_44 ) ;
return 0 ;
}
static int F_65 ( struct V_2 * V_3 )
{
F_33 ( V_3 , V_82 , L_50 ) ;
F_66 ( V_3 ) ;
F_67 ( V_3 ) ;
F_68 ( V_3 ) ;
return 0 ;
}
static void F_69 ( struct V_2 * V_3 )
{
struct V_1 * V_9 = F_1 ( V_3 ) ;
F_33 ( V_3 , V_82 , L_51 ) ;
F_46 ( V_3 ) ;
F_70 ( V_9 -> V_60 ) ;
F_71 ( V_3 ) ;
}
static int F_72 ( struct V_2 * V_3 )
{
int V_19 ;
F_33 ( V_3 , V_82 , L_52 ) ;
V_19 = F_63 ( V_3 ) ;
if ( V_19 ) {
F_15 ( V_3 , L_53 , V_19 ) ;
goto V_23;
}
V_19 = F_73 ( V_3 ) ;
if ( V_19 ) {
F_15 ( V_3 , L_54 , V_19 ) ;
goto V_23;
}
V_19 = F_74 ( V_3 ) ;
if ( V_19 ) {
F_15 ( V_3 , L_55 , V_19 ) ;
goto V_92;
}
V_19 = F_64 ( V_3 ) ;
if ( V_19 ) {
F_15 ( V_3 , L_56 , V_19 ) ;
goto V_92;
}
return 0 ;
V_92:
F_75 ( V_3 ) ;
V_23:
return V_19 ;
}
static int F_76 ( struct V_67 * V_20 )
{
struct V_2 * V_3 ;
struct V_1 * V_9 ;
struct V_4 * V_62 ;
const struct V_93 * V_94 ;
enum V_95 V_15 ;
T_3 V_96 ;
int V_19 ;
T_1 V_97 ;
V_94 = F_77 ( V_98 , & V_20 -> V_18 ) ;
if ( ! V_94 ) {
F_78 ( & V_20 -> V_18 , L_57 ) ;
return - V_40 ;
}
V_15 = (enum V_95 ) V_94 -> V_99 ;
V_96 = sizeof( * V_62 ) + sizeof( * V_9 ) ;
V_3 = F_79 ( V_96 , & V_20 -> V_18 , V_100 ,
V_15 , & V_101 ) ;
if ( ! V_3 ) {
F_78 ( & V_20 -> V_18 , L_58 ) ;
return - V_75 ;
}
F_33 ( V_3 , V_82 , L_59 ) ;
V_62 = F_38 ( V_3 ) ;
V_9 = F_1 ( V_3 ) ;
V_9 -> V_20 = V_20 ;
F_80 ( V_20 , V_3 ) ;
V_19 = F_48 ( V_3 ) ;
if ( V_19 )
goto V_102;
V_3 -> V_103 = 0 ;
V_62 -> V_10 = V_9 -> V_10 ;
V_62 -> V_72 = V_9 -> V_72 ;
V_62 -> V_3 = V_3 ;
V_62 -> V_104 = & V_105 ;
V_19 = F_81 ( V_3 ) ;
if ( V_19 ) {
F_15 ( V_3 , L_60 , V_19 ) ;
goto V_106;
}
F_82 ( V_3 ) ;
V_19 = F_42 ( V_3 ) ;
if ( V_19 )
goto V_107;
V_19 = F_61 ( V_3 ) ;
if ( V_19 )
goto V_108;
F_75 ( V_3 ) ;
V_97 = F_9 ( V_3 , V_109 ) ;
if ( V_97 == 0xffffffff ) {
F_15 ( V_3 , L_61 ) ;
goto V_110;
}
V_19 = F_83 ( V_3 , V_97 ) ;
if ( V_19 ) {
F_15 ( V_3 , L_62 , V_19 ) ;
goto V_110;
}
return 0 ;
V_110:
F_34 ( V_3 ) ;
F_22 ( V_3 ) ;
V_108:
F_44 ( V_3 ) ;
V_107:
F_84 ( V_3 ) ;
V_106:
F_60 ( V_3 ) ;
V_102:
F_85 ( V_3 ) ;
F_80 ( V_20 , NULL ) ;
return V_19 ;
}
static int F_86 ( struct V_67 * V_20 )
{
struct V_2 * V_3 = F_87 ( V_20 ) ;
struct V_1 * V_9 ;
if ( ! V_3 )
return - V_40 ;
V_9 = F_1 ( V_3 ) ;
if ( ! V_9 )
return - V_40 ;
F_33 ( V_3 , V_49 , L_63 ) ;
F_88 ( V_3 ) ;
F_46 ( V_3 ) ;
F_44 ( V_3 ) ;
F_89 ( V_3 ) ;
F_34 ( V_3 ) ;
F_22 ( V_3 ) ;
F_60 ( V_3 ) ;
F_85 ( V_3 ) ;
F_80 ( V_20 , NULL ) ;
return 0 ;
}
int F_90 ( void )
{
int V_19 ;
F_91 ( V_111 L_64 ) ;
V_19 = F_92 ( & V_112 ) ;
if ( V_19 )
F_91 ( V_111 L_65 ,
V_19 ) ;
return V_19 ;
}
void F_93 ( void )
{
F_94 ( & V_112 ) ;
}
