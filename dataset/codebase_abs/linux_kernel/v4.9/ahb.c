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
V_18 = & V_9 -> V_19 -> V_18 ;
V_9 -> V_20 = F_13 ( V_18 , L_2 ) ;
if ( F_14 ( V_9 -> V_20 ) ) {
F_15 ( V_3 , L_3 ,
F_16 ( V_9 -> V_20 ) ) ;
return V_9 -> V_20 ? F_16 ( V_9 -> V_20 ) : - V_21 ;
}
V_9 -> V_22 = F_13 ( V_18 , L_4 ) ;
if ( F_14 ( V_9 -> V_22 ) ) {
F_15 ( V_3 , L_5 ,
F_16 ( V_9 -> V_22 ) ) ;
return V_9 -> V_22 ? F_16 ( V_9 -> V_22 ) : - V_21 ;
}
V_9 -> V_23 = F_13 ( V_18 , L_6 ) ;
if ( F_14 ( V_9 -> V_23 ) ) {
F_15 ( V_3 , L_7 ,
F_16 ( V_9 -> V_23 ) ) ;
return V_9 -> V_23 ? F_16 ( V_9 -> V_23 ) : - V_21 ;
}
return 0 ;
}
static void F_17 ( struct V_2 * V_3 )
{
struct V_1 * V_9 = F_1 ( V_3 ) ;
V_9 -> V_20 = NULL ;
V_9 -> V_22 = NULL ;
V_9 -> V_23 = NULL ;
}
static int F_18 ( struct V_2 * V_3 )
{
struct V_1 * V_9 = F_1 ( V_3 ) ;
struct V_17 * V_18 ;
int V_24 ;
V_18 = & V_9 -> V_19 -> V_18 ;
if ( F_14 ( V_9 -> V_20 ) ||
F_14 ( V_9 -> V_22 ) ||
F_14 ( V_9 -> V_23 ) ) {
F_15 ( V_3 , L_8 ) ;
V_24 = - V_25 ;
goto V_26;
}
V_24 = F_19 ( V_9 -> V_20 ) ;
if ( V_24 ) {
F_15 ( V_3 , L_9 , V_24 ) ;
goto V_26;
}
V_24 = F_19 ( V_9 -> V_22 ) ;
if ( V_24 ) {
F_15 ( V_3 , L_10 , V_24 ) ;
goto V_27;
}
V_24 = F_19 ( V_9 -> V_23 ) ;
if ( V_24 ) {
F_15 ( V_3 , L_11 , V_24 ) ;
goto V_28;
}
return 0 ;
V_28:
F_20 ( V_9 -> V_22 ) ;
V_27:
F_20 ( V_9 -> V_20 ) ;
V_26:
return V_24 ;
}
static void F_21 ( struct V_2 * V_3 )
{
struct V_1 * V_9 = F_1 ( V_3 ) ;
if ( ! F_14 ( V_9 -> V_20 ) )
F_20 ( V_9 -> V_20 ) ;
if ( ! F_14 ( V_9 -> V_22 ) )
F_20 ( V_9 -> V_22 ) ;
if ( ! F_14 ( V_9 -> V_23 ) )
F_20 ( V_9 -> V_23 ) ;
}
static int F_22 ( struct V_2 * V_3 )
{
struct V_1 * V_9 = F_1 ( V_3 ) ;
struct V_17 * V_18 ;
V_18 = & V_9 -> V_19 -> V_18 ;
V_9 -> V_29 = F_23 ( V_18 , L_12 ) ;
if ( F_24 ( V_9 -> V_29 ) ) {
F_15 ( V_3 , L_13 ,
F_16 ( V_9 -> V_29 ) ) ;
return F_16 ( V_9 -> V_29 ) ;
}
V_9 -> V_30 = F_23 ( V_18 , L_14 ) ;
if ( F_24 ( V_9 -> V_30 ) ) {
F_15 ( V_3 , L_15 ,
F_16 ( V_9 -> V_30 ) ) ;
return F_16 ( V_9 -> V_30 ) ;
}
V_9 -> V_31 = F_23 ( V_18 , L_16 ) ;
if ( F_24 ( V_9 -> V_31 ) ) {
F_15 ( V_3 , L_17 ,
F_16 ( V_9 -> V_31 ) ) ;
return F_16 ( V_9 -> V_31 ) ;
}
V_9 -> V_32 = F_23 ( V_18 , L_18 ) ;
if ( F_24 ( V_9 -> V_32 ) ) {
F_15 ( V_3 , L_19 ,
F_16 ( V_9 -> V_32 ) ) ;
return F_16 ( V_9 -> V_32 ) ;
}
V_9 -> V_33 = F_23 ( V_18 , L_20 ) ;
if ( F_24 ( V_9 -> V_33 ) ) {
F_15 ( V_3 , L_21 ,
F_16 ( V_9 -> V_33 ) ) ;
return F_16 ( V_9 -> V_33 ) ;
}
return 0 ;
}
static void F_25 ( struct V_2 * V_3 )
{
struct V_1 * V_9 = F_1 ( V_3 ) ;
V_9 -> V_29 = NULL ;
V_9 -> V_30 = NULL ;
V_9 -> V_31 = NULL ;
V_9 -> V_32 = NULL ;
V_9 -> V_33 = NULL ;
}
static int F_26 ( struct V_2 * V_3 )
{
struct V_1 * V_9 = F_1 ( V_3 ) ;
int V_24 ;
if ( F_14 ( V_9 -> V_30 ) ||
F_14 ( V_9 -> V_31 ) ||
F_14 ( V_9 -> V_32 ) ||
F_14 ( V_9 -> V_33 ) ) {
F_15 ( V_3 , L_22 ) ;
return - V_34 ;
}
V_24 = F_27 ( V_9 -> V_30 ) ;
if ( V_24 ) {
F_15 ( V_3 , L_23 , V_24 ) ;
return V_24 ;
}
V_24 = F_27 ( V_9 -> V_31 ) ;
if ( V_24 ) {
F_15 ( V_3 , L_24 , V_24 ) ;
return V_24 ;
}
V_24 = F_27 ( V_9 -> V_32 ) ;
if ( V_24 ) {
F_15 ( V_3 , L_25 , V_24 ) ;
return V_24 ;
}
V_24 = F_27 ( V_9 -> V_33 ) ;
if ( V_24 ) {
F_15 ( V_3 , L_26 , V_24 ) ;
return V_24 ;
}
return 0 ;
}
static void F_28 ( struct V_2 * V_3 , T_1 V_35 ,
T_1 V_36 )
{
unsigned long V_37 ;
T_1 V_38 ;
V_38 = F_8 ( V_3 , V_35 ) ;
V_38 |= V_39 ;
F_7 ( V_3 , V_35 , V_38 ) ;
V_37 = V_40 + F_29 ( V_41 ) ;
do {
V_38 = F_8 ( V_3 , V_36 ) ;
if ( V_38 & V_42 )
break;
F_30 ( 1 ) ;
} while ( F_31 ( V_40 , V_37 ) );
if ( ! ( V_38 & V_42 ) ) {
F_15 ( V_3 , L_27 , V_38 ) ;
return;
}
F_32 ( V_3 , V_43 , L_28 ) ;
}
static void F_33 ( struct V_2 * V_3 )
{
struct V_1 * V_9 = F_1 ( V_3 ) ;
T_1 V_44 , V_45 , V_35 , V_36 ;
T_1 V_38 ;
int V_24 ;
if ( F_14 ( V_9 -> V_29 ) ||
F_14 ( V_9 -> V_30 ) ||
F_14 ( V_9 -> V_31 ) ||
F_14 ( V_9 -> V_32 ) ||
F_14 ( V_9 -> V_33 ) ) {
F_15 ( V_3 , L_22 ) ;
return;
}
V_44 = F_4 ( V_3 , V_46 ) ;
switch ( V_44 ) {
case 0 :
V_45 = V_47 ;
V_35 = V_48 ;
V_36 = V_49 ;
break;
case 1 :
V_45 = V_50 ;
V_35 = V_51 ;
V_36 = V_52 ;
break;
default:
F_15 ( V_3 , L_29 ,
V_44 ) ;
return;
}
F_28 ( V_3 , V_35 , V_36 ) ;
V_38 = F_8 ( V_3 , V_45 ) ;
V_38 |= V_53 ;
F_7 ( V_3 , V_45 , V_38 ) ;
V_24 = F_34 ( V_9 -> V_29 ) ;
if ( V_24 )
F_15 ( V_3 , L_30 , V_24 ) ;
F_35 ( 1 ) ;
V_24 = F_34 ( V_9 -> V_30 ) ;
if ( V_24 )
F_15 ( V_3 , L_31 , V_24 ) ;
F_35 ( 1 ) ;
V_24 = F_34 ( V_9 -> V_31 ) ;
if ( V_24 )
F_15 ( V_3 , L_32 , V_24 ) ;
F_35 ( 1 ) ;
V_24 = F_34 ( V_9 -> V_32 ) ;
if ( V_24 )
F_15 ( V_3 , L_33 , V_24 ) ;
F_35 ( 1 ) ;
V_24 = F_34 ( V_9 -> V_33 ) ;
if ( V_24 )
F_15 ( V_3 , L_34 , V_24 ) ;
F_35 ( 10 ) ;
V_38 = F_8 ( V_3 , V_35 ) ;
V_38 &= ~ V_39 ;
F_7 ( V_3 , V_35 , V_38 ) ;
V_38 = F_8 ( V_3 , V_45 ) ;
V_38 &= ~ V_53 ;
F_7 ( V_3 , V_45 , V_38 ) ;
V_24 = F_27 ( V_9 -> V_29 ) ;
if ( V_24 )
F_15 ( V_3 , L_35 , V_24 ) ;
F_32 ( V_3 , V_43 , L_36 , V_44 ) ;
}
static T_2 F_36 ( int V_54 , void * V_55 )
{
struct V_2 * V_3 = V_55 ;
if ( ! F_37 ( V_3 ) )
return V_56 ;
F_38 ( V_3 ) ;
F_39 ( V_3 ) ;
F_40 ( & V_3 -> V_57 ) ;
return V_58 ;
}
static int F_41 ( struct V_2 * V_3 )
{
struct V_4 * V_59 = F_42 ( V_3 ) ;
struct V_1 * V_9 = F_1 ( V_3 ) ;
int V_24 ;
V_24 = F_43 ( V_9 -> V_54 ,
F_36 ,
V_60 , L_37 , V_3 ) ;
if ( V_24 ) {
F_11 ( V_3 , L_38 ,
V_9 -> V_54 , V_24 ) ;
return V_24 ;
}
V_59 -> V_61 = V_62 ;
return 0 ;
}
static void F_44 ( struct V_2 * V_3 )
{
struct V_1 * V_9 = F_1 ( V_3 ) ;
F_45 ( V_9 -> V_54 , V_3 ) ;
}
static void F_46 ( struct V_2 * V_3 )
{
F_47 ( V_3 ) ;
F_38 ( V_3 ) ;
}
static int F_48 ( struct V_2 * V_3 )
{
struct V_1 * V_9 = F_1 ( V_3 ) ;
struct V_63 * V_19 ;
struct V_17 * V_18 ;
struct V_64 * V_65 ;
int V_24 ;
V_19 = V_9 -> V_19 ;
V_18 = & V_19 -> V_18 ;
V_65 = F_49 ( V_19 , V_66 , 0 ) ;
if ( ! V_65 ) {
F_15 ( V_3 , L_39 ) ;
V_24 = - V_67 ;
goto V_26;
}
V_9 -> V_10 = F_50 ( & V_19 -> V_18 , V_65 ) ;
if ( F_24 ( V_9 -> V_10 ) ) {
F_15 ( V_3 , L_40 ) ;
V_24 = F_16 ( V_9 -> V_10 ) ;
goto V_26;
}
V_9 -> V_68 = F_51 ( V_65 ) ;
V_9 -> V_11 = F_52 ( V_69 ,
V_70 ) ;
if ( ! V_9 -> V_11 ) {
F_15 ( V_3 , L_41 ) ;
V_24 = - V_71 ;
goto V_72;
}
V_9 -> V_12 = F_52 ( V_73 ,
V_74 ) ;
if ( ! V_9 -> V_12 ) {
F_15 ( V_3 , L_42 ) ;
V_24 = - V_71 ;
goto V_75;
}
V_24 = F_53 ( & V_19 -> V_18 , F_54 ( 32 ) ) ;
if ( V_24 ) {
F_15 ( V_3 , L_43 , V_24 ) ;
goto V_76;
}
V_24 = F_55 ( & V_19 -> V_18 , F_54 ( 32 ) ) ;
if ( V_24 ) {
F_15 ( V_3 , L_44 ,
V_24 ) ;
goto V_76;
}
V_24 = F_12 ( V_3 ) ;
if ( V_24 )
goto V_76;
V_24 = F_22 ( V_3 ) ;
if ( V_24 )
goto V_77;
V_9 -> V_54 = F_56 ( V_19 , L_45 ) ;
if ( V_9 -> V_54 < 0 ) {
F_15 ( V_3 , L_46 , V_9 -> V_54 ) ;
V_24 = V_9 -> V_54 ;
goto V_77;
}
F_32 ( V_3 , V_78 , L_47 , V_9 -> V_54 ) ;
F_32 ( V_3 , V_78 , L_48 ,
V_9 -> V_10 , V_9 -> V_68 ,
V_9 -> V_11 , V_9 -> V_12 ) ;
return 0 ;
V_77:
F_17 ( V_3 ) ;
V_76:
F_57 ( V_9 -> V_12 ) ;
V_75:
V_9 -> V_12 = NULL ;
F_57 ( V_9 -> V_11 ) ;
V_72:
V_9 -> V_11 = NULL ;
F_58 ( & V_19 -> V_18 , V_9 -> V_10 ) ;
V_26:
V_9 -> V_10 = NULL ;
return V_24 ;
}
static void F_59 ( struct V_2 * V_3 )
{
struct V_1 * V_9 = F_1 ( V_3 ) ;
struct V_17 * V_18 ;
V_18 = & V_9 -> V_19 -> V_18 ;
if ( V_9 -> V_10 )
F_58 ( V_18 , V_9 -> V_10 ) ;
if ( V_9 -> V_11 )
F_57 ( V_9 -> V_11 ) ;
if ( V_9 -> V_12 )
F_57 ( V_9 -> V_12 ) ;
V_9 -> V_10 = NULL ;
V_9 -> V_11 = NULL ;
V_9 -> V_12 = NULL ;
F_17 ( V_3 ) ;
F_25 ( V_3 ) ;
}
static int F_60 ( struct V_2 * V_3 )
{
T_1 V_38 ;
int V_24 ;
V_24 = F_18 ( V_3 ) ;
if ( V_24 ) {
F_15 ( V_3 , L_49 ) ;
return V_24 ;
}
V_38 = F_6 ( V_3 , V_79 ) ;
F_2 ( V_3 , V_80 , V_38 ) ;
V_24 = F_26 ( V_3 ) ;
if ( V_24 )
goto V_81;
F_46 ( V_3 ) ;
F_2 ( V_3 , V_82 , V_83 ) ;
V_24 = F_61 ( V_3 ) ;
if ( V_24 )
goto V_84;
return 0 ;
V_84:
F_33 ( V_3 ) ;
V_81:
F_21 ( V_3 ) ;
return V_24 ;
}
static int F_62 ( struct V_2 * V_3 )
{
int V_24 ;
F_33 ( V_3 ) ;
F_21 ( V_3 ) ;
V_24 = F_60 ( V_3 ) ;
if ( V_24 )
return V_24 ;
return 0 ;
}
static int F_63 ( struct V_2 * V_3 )
{
T_1 V_13 , V_38 ;
V_13 = V_85 | V_86 ;
V_38 = F_4 ( V_3 , V_13 ) ;
V_38 |= V_87 ;
F_2 ( V_3 , V_13 , V_38 ) ;
return 0 ;
}
static int F_64 ( struct V_2 * V_3 )
{
F_32 ( V_3 , V_78 , L_50 ) ;
F_65 ( V_3 ) ;
F_66 ( V_3 ) ;
F_67 ( V_3 ) ;
return 0 ;
}
static void F_68 ( struct V_2 * V_3 )
{
struct V_1 * V_9 = F_1 ( V_3 ) ;
F_32 ( V_3 , V_78 , L_51 ) ;
F_46 ( V_3 ) ;
F_69 ( V_9 -> V_54 ) ;
F_70 ( V_3 ) ;
F_71 ( & V_3 -> V_57 ) ;
F_72 ( & V_3 -> V_57 ) ;
}
static int F_73 ( struct V_2 * V_3 )
{
int V_24 ;
F_32 ( V_3 , V_78 , L_52 ) ;
V_24 = F_62 ( V_3 ) ;
if ( V_24 ) {
F_15 ( V_3 , L_53 , V_24 ) ;
goto V_26;
}
V_24 = F_74 ( V_3 ) ;
if ( V_24 ) {
F_15 ( V_3 , L_54 , V_24 ) ;
goto V_26;
}
V_24 = F_75 ( V_3 ) ;
if ( V_24 ) {
F_15 ( V_3 , L_55 , V_24 ) ;
goto V_88;
}
V_24 = F_63 ( V_3 ) ;
if ( V_24 ) {
F_15 ( V_3 , L_56 , V_24 ) ;
goto V_88;
}
F_76 ( & V_3 -> V_57 ) ;
return 0 ;
V_88:
F_77 ( V_3 ) ;
V_26:
return V_24 ;
}
static int F_78 ( struct V_63 * V_19 )
{
struct V_2 * V_3 ;
struct V_1 * V_9 ;
struct V_4 * V_59 ;
const struct V_89 * V_90 ;
enum V_91 V_15 ;
T_3 V_92 ;
int V_24 ;
T_1 V_93 ;
V_90 = F_79 ( V_94 , & V_19 -> V_18 ) ;
if ( ! V_90 ) {
F_80 ( & V_19 -> V_18 , L_57 ) ;
return - V_34 ;
}
V_15 = (enum V_91 ) V_90 -> V_95 ;
V_92 = sizeof( * V_59 ) + sizeof( * V_9 ) ;
V_3 = F_81 ( V_92 , & V_19 -> V_18 , V_96 ,
V_15 , & V_97 ) ;
if ( ! V_3 ) {
F_80 ( & V_19 -> V_18 , L_58 ) ;
return - V_71 ;
}
F_32 ( V_3 , V_78 , L_59 ) ;
V_59 = F_42 ( V_3 ) ;
V_9 = F_1 ( V_3 ) ;
V_9 -> V_19 = V_19 ;
F_82 ( V_19 , V_3 ) ;
V_24 = F_48 ( V_3 ) ;
if ( V_24 )
goto V_98;
V_3 -> V_99 = 0 ;
V_59 -> V_10 = V_9 -> V_10 ;
V_59 -> V_68 = V_9 -> V_68 ;
V_59 -> V_3 = V_3 ;
V_59 -> V_100 = & V_101 ;
V_24 = F_83 ( V_3 ) ;
if ( V_24 ) {
F_15 ( V_3 , L_60 , V_24 ) ;
goto V_102;
}
F_84 ( V_3 ) ;
V_24 = F_41 ( V_3 ) ;
if ( V_24 )
goto V_103;
V_24 = F_60 ( V_3 ) ;
if ( V_24 )
goto V_104;
F_77 ( V_3 ) ;
V_93 = F_9 ( V_3 , V_105 ) ;
if ( V_93 == 0xffffffff ) {
F_15 ( V_3 , L_61 ) ;
V_24 = - V_21 ;
goto V_106;
}
V_24 = F_85 ( V_3 , V_93 ) ;
if ( V_24 ) {
F_15 ( V_3 , L_62 , V_24 ) ;
goto V_106;
}
return 0 ;
V_106:
F_33 ( V_3 ) ;
F_21 ( V_3 ) ;
V_104:
F_44 ( V_3 ) ;
V_103:
F_86 ( V_3 ) ;
V_102:
F_59 ( V_3 ) ;
V_98:
F_87 ( V_3 ) ;
F_82 ( V_19 , NULL ) ;
return V_24 ;
}
static int F_88 ( struct V_63 * V_19 )
{
struct V_2 * V_3 = F_89 ( V_19 ) ;
struct V_1 * V_9 ;
if ( ! V_3 )
return - V_34 ;
V_9 = F_1 ( V_3 ) ;
if ( ! V_9 )
return - V_34 ;
F_32 ( V_3 , V_43 , L_63 ) ;
F_90 ( V_3 ) ;
F_46 ( V_3 ) ;
F_44 ( V_3 ) ;
F_91 ( V_3 ) ;
F_33 ( V_3 ) ;
F_21 ( V_3 ) ;
F_59 ( V_3 ) ;
F_87 ( V_3 ) ;
F_82 ( V_19 , NULL ) ;
return 0 ;
}
int F_92 ( void )
{
int V_24 ;
V_24 = F_93 ( & V_107 ) ;
if ( V_24 )
F_94 ( V_108 L_64 ,
V_24 ) ;
return V_24 ;
}
void F_95 ( void )
{
F_96 ( & V_107 ) ;
}
