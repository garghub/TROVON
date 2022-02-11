static inline T_1 F_1 ( struct V_1 * V_2 , T_1 V_3 )
{
return F_2 ( V_2 -> V_4 + V_3 ) ;
}
static inline void F_3 ( struct V_1 * V_2 , T_1 V_3 ,
T_1 V_5 )
{
F_4 ( V_5 , V_2 -> V_4 + V_3 ) ;
}
static T_2 F_5 ( T_2 V_6 )
{
return V_6 & V_7 ;
}
static int F_6 ( struct V_8 * V_9 )
{
struct V_1 * V_10 = F_7 ( V_9 ) ;
T_1 V_11 = F_1 ( V_10 , V_12 ) ;
return ! ! ( V_11 & V_13 ) ;
}
static void F_8 ( struct V_8 * V_9 )
{
struct V_1 * V_10 = F_7 ( V_9 ) ;
T_1 V_11 ;
V_11 = F_1 ( V_10 , V_14 ) ;
V_11 &= ~ V_15 ;
F_3 ( V_10 , V_14 , V_11 ) ;
}
static int F_9 ( struct V_8 * V_9 )
{
struct V_1 * V_10 = F_7 ( V_9 ) ;
struct V_16 * V_17 = V_9 -> V_17 ;
T_1 V_11 ;
T_1 V_18 = V_19 ;
if ( F_10 ( V_9 ) ) {
F_11 ( V_17 , L_1 ) ;
return 0 ;
}
if ( V_10 -> V_20 == 1 ) {
F_12 ( V_9 -> V_21 + V_18 + V_22 ,
4 , & V_11 ) ;
if ( ( V_11 & V_23 ) != V_24 ) {
V_11 &= ~ ( ( T_1 ) V_23 ) ;
V_11 |= V_24 ;
F_13 ( V_9 -> V_21 + V_18 +
V_22 , 4 , V_11 ) ;
}
F_12 ( V_9 -> V_21 + V_18 + V_25 ,
2 , & V_11 ) ;
if ( ( V_11 & V_23 ) != V_24 ) {
V_11 &= ~ ( ( T_1 ) V_23 ) ;
V_11 |= V_24 ;
F_13 ( V_9 -> V_21 + V_18 +
V_25 , 2 , V_11 ) ;
}
}
V_11 = F_1 ( V_10 , V_14 ) ;
V_11 |= V_15 ;
F_3 ( V_10 , V_14 , V_11 ) ;
return 0 ;
}
static void F_14 ( struct V_1 * V_10 )
{
F_3 ( V_10 , V_26 ,
~ V_27 & ~ V_28 ) ;
F_3 ( V_10 ,
V_29 ,
V_28 | V_27 ) ;
}
static void F_15 ( struct V_1 * V_10 )
{
F_3 ( V_10 , V_30 ,
~ V_31 ) ;
F_3 ( V_10 , V_32 ,
V_31 ) ;
}
static void F_16 ( struct V_1 * V_10 )
{
F_15 ( V_10 ) ;
F_14 ( V_10 ) ;
}
static void F_17 ( struct V_33 * V_34 )
{
struct V_8 * V_9 = F_18 ( V_34 ) ;
struct V_1 * V_10 = F_7 ( V_9 ) ;
F_19 ( V_34 ) ;
F_9 ( V_9 ) ;
F_20 ( V_9 ) ;
F_21 ( V_34 ) ;
F_16 ( V_10 ) ;
}
static int F_22 ( struct V_35 * V_36 , unsigned int V_37 ,
T_3 V_38 )
{
F_23 ( V_37 , & V_39 , V_40 ) ;
F_24 ( V_37 , V_36 -> V_41 ) ;
return 0 ;
}
static int F_25 ( struct V_33 * V_34 )
{
struct V_8 * V_9 = F_18 ( V_34 ) ;
struct V_16 * V_17 = V_9 -> V_17 ;
struct V_1 * V_10 = F_7 ( V_9 ) ;
struct V_42 * V_43 = V_17 -> V_44 ;
struct V_42 * V_45 = F_26 ( V_43 , NULL ) ;
if ( ! V_45 ) {
F_11 ( V_17 , L_2 ) ;
return - V_46 ;
}
V_10 -> V_35 = F_27 ( V_45 , 4 ,
& V_47 , V_34 ) ;
if ( ! V_10 -> V_35 ) {
F_11 ( V_17 , L_3 ) ;
return - V_46 ;
}
return 0 ;
}
static T_4 F_28 ( int V_37 , void * V_48 )
{
struct V_1 * V_10 = V_48 ;
struct V_8 * V_9 = V_10 -> V_9 ;
struct V_33 * V_34 = & V_9 -> V_34 ;
T_1 V_11 ;
V_11 = F_1 ( V_10 , V_26 ) ;
switch ( V_11 ) {
case V_28 :
F_29 ( V_34 ) ;
break;
case V_49 :
case V_50 :
case V_51 :
case V_52 :
F_30 ( F_31 ( V_10 -> V_35 ,
F_32 ( V_11 ) ) ) ;
break;
}
F_3 ( V_10 , V_26 , V_11 ) ;
return V_53 ;
}
static T_4 F_33 ( int V_37 , void * V_48 )
{
struct V_1 * V_10 = V_48 ;
struct V_8 * V_9 = V_10 -> V_9 ;
struct V_16 * V_17 = V_9 -> V_17 ;
struct V_54 * V_55 = & V_9 -> V_55 ;
T_1 V_11 ;
V_11 = F_1 ( V_10 , V_30 ) ;
if ( V_11 & V_56 )
F_34 ( V_17 , L_4 ) ;
if ( V_11 & V_57 )
F_34 ( V_17 , L_5 ) ;
if ( V_11 & V_58 )
F_34 ( V_17 , L_6 ) ;
if ( V_11 & V_59 )
F_34 ( V_17 , L_7 ) ;
if ( V_11 & V_60 )
F_34 ( V_17 , L_8 ) ;
if ( V_11 & V_61 )
F_34 ( V_17 , L_9 ) ;
if ( V_11 & V_62 )
F_34 ( V_17 ,
L_10 ) ;
if ( V_11 & V_63 )
F_34 ( V_17 ,
L_11 ) ;
if ( V_11 & V_64 )
F_34 ( V_17 , L_12 ) ;
if ( V_11 & V_65 )
F_34 ( V_17 , L_13 ) ;
if ( V_11 & V_66 ) {
if ( V_10 -> V_67 == V_68 )
F_35 ( V_55 ) ;
F_34 ( V_17 , L_14 ) ;
}
if ( V_11 & V_69 )
F_34 ( V_17 , L_15 ) ;
if ( V_11 & V_70 )
F_34 ( V_17 , L_16 ) ;
F_3 ( V_10 , V_30 , V_11 ) ;
return V_53 ;
}
static void F_36 ( struct V_54 * V_55 )
{
struct V_8 * V_9 = F_37 ( V_55 ) ;
struct V_1 * V_10 = F_7 ( V_9 ) ;
F_15 ( V_10 ) ;
}
static void F_38 ( struct V_1 * V_10 )
{
F_3 ( V_10 , V_71 , 0x1 ) ;
F_39 ( 1 ) ;
F_3 ( V_10 , V_72 , 0x1 ) ;
}
static void F_40 ( struct V_1 * V_10 ,
T_5 V_73 )
{
T_1 V_11 ;
V_11 = ( V_73 - 1 ) << V_74 ;
V_11 |= V_75 ;
F_3 ( V_10 , V_76 , V_11 ) ;
}
static int F_41 ( struct V_54 * V_55 ,
enum V_77 type , T_5 V_73 )
{
struct V_8 * V_9 = F_37 ( V_55 ) ;
struct V_1 * V_10 = F_7 ( V_9 ) ;
switch ( type ) {
case V_78 :
F_38 ( V_10 ) ;
break;
case V_79 :
F_40 ( V_10 , V_73 ) ;
break;
default:
F_11 ( V_9 -> V_17 , L_17 ) ;
}
return 0 ;
}
static int T_6 F_42 ( struct V_1 * V_10 ,
struct V_80 * V_81 )
{
int V_82 ;
struct V_54 * V_55 ;
struct V_83 * V_84 ;
struct V_16 * V_17 = & V_81 -> V_17 ;
struct V_8 * V_9 = V_10 -> V_9 ;
V_55 = & V_9 -> V_55 ;
V_55 -> V_85 = & V_86 ;
V_84 = F_43 ( V_81 , V_87 , L_18 ) ;
V_9 -> V_21 = F_44 ( V_17 , V_84 -> V_88 , F_45 ( V_84 ) ) ;
if ( ! V_9 -> V_21 )
return - V_89 ;
V_84 = F_43 ( V_81 , V_87 , L_19 ) ;
V_9 -> V_90 = F_44 ( V_17 , V_84 -> V_88 , F_45 ( V_84 ) ) ;
if ( ! V_9 -> V_90 )
return - V_89 ;
V_84 = F_43 ( V_81 , V_87 , L_20 ) ;
if ( ! V_84 )
return - V_91 ;
V_55 -> V_92 = V_84 -> V_88 ;
V_55 -> V_93 = F_45 ( V_84 ) ;
V_82 = F_46 ( V_55 ) ;
if ( V_82 ) {
F_11 ( V_17 , L_21 ) ;
return V_82 ;
}
return 0 ;
}
static int T_6 F_47 ( struct V_1 * V_10 ,
struct V_80 * V_81 )
{
int V_82 ;
struct V_8 * V_9 = V_10 -> V_9 ;
struct V_33 * V_34 = & V_9 -> V_34 ;
struct V_16 * V_17 = V_9 -> V_17 ;
struct V_83 * V_84 ;
V_34 -> V_37 = F_48 ( V_81 , 1 ) ;
if ( V_34 -> V_37 < 0 ) {
F_11 ( V_17 , L_22 ) ;
return - V_91 ;
}
V_82 = F_49 ( V_17 , V_34 -> V_37 , F_28 ,
V_94 | V_95 ,
L_23 , V_10 ) ;
if ( V_82 ) {
F_11 ( V_17 , L_24 ) ;
return V_82 ;
}
V_82 = F_25 ( V_34 ) ;
if ( V_82 < 0 )
return V_82 ;
V_84 = F_43 ( V_81 , V_87 , L_25 ) ;
V_9 -> V_21 = F_44 ( V_17 , V_84 -> V_88 , F_45 ( V_84 ) ) ;
if ( ! V_9 -> V_21 )
return - V_89 ;
V_82 = F_50 ( V_34 ) ;
if ( V_82 ) {
F_11 ( V_17 , L_26 ) ;
return V_82 ;
}
return 0 ;
}
static void F_51 ( struct V_1 * V_10 )
{
int V_96 = V_10 -> V_96 ;
while ( V_96 -- ) {
F_52 ( V_10 -> V_97 [ V_96 ] ) ;
F_53 ( V_10 -> V_97 [ V_96 ] ) ;
}
}
static int F_54 ( struct V_1 * V_10 )
{
int V_96 = V_10 -> V_96 ;
int V_82 ;
int V_98 ;
for ( V_98 = 0 ; V_98 < V_96 ; V_98 ++ ) {
V_82 = F_55 ( V_10 -> V_97 [ V_98 ] ) ;
if ( V_82 < 0 )
goto V_99;
V_82 = F_56 ( V_10 -> V_97 [ V_98 ] ) ;
if ( V_82 < 0 ) {
F_53 ( V_10 -> V_97 [ V_98 ] ) ;
goto V_99;
}
}
return 0 ;
V_99:
while ( -- V_98 >= 0 ) {
F_52 ( V_10 -> V_97 [ V_98 ] ) ;
F_53 ( V_10 -> V_97 [ V_98 ] ) ;
}
return V_82 ;
}
static int F_57 ( struct V_16 * V_17 )
{
int V_82 ;
struct V_42 * V_100 = V_17 -> V_44 ;
struct V_101 args ;
struct V_102 * V_102 ;
V_102 = F_58 ( V_100 ,
L_27 ) ;
if ( F_59 ( V_102 ) ) {
F_34 ( V_17 , L_28 ) ;
return - V_91 ;
}
V_82 = F_60 ( V_100 , L_27 ,
2 , 0 , & args ) ;
if ( V_82 ) {
F_11 ( V_17 , L_29 ) ;
return V_82 ;
}
V_82 = F_61 ( V_102 , args . args [ 0 ] , args . args [ 1 ] ,
args . args [ 1 ] ) ;
if ( V_82 )
F_11 ( V_17 , L_30 ) ;
F_62 ( args . V_100 ) ;
return V_82 ;
}
static int T_6 F_63 ( struct V_80 * V_81 )
{
T_1 V_11 ;
int V_82 ;
int V_37 ;
int V_98 ;
int V_96 ;
struct V_97 * * V_97 ;
void T_7 * V_4 ;
struct V_83 * V_84 ;
struct V_8 * V_9 ;
struct V_33 * V_34 ;
struct V_1 * V_10 ;
struct V_16 * V_17 = & V_81 -> V_17 ;
struct V_42 * V_100 = V_17 -> V_44 ;
char V_103 [ 10 ] ;
struct V_104 * V_105 ;
const struct V_106 * V_107 ;
const struct V_108 * V_109 ;
enum V_110 V_67 ;
V_107 = F_64 ( F_65 ( V_111 ) , V_17 ) ;
if ( ! V_107 )
return - V_91 ;
V_109 = (struct V_108 * ) V_107 -> V_109 ;
V_67 = (enum V_110 ) V_109 -> V_67 ;
V_10 = F_66 ( V_17 , sizeof( * V_10 ) , V_112 ) ;
if ( ! V_10 )
return - V_89 ;
V_9 = F_66 ( V_17 , sizeof( * V_9 ) , V_112 ) ;
if ( ! V_9 )
return - V_89 ;
V_9 -> V_17 = V_17 ;
V_9 -> V_85 = & V_113 ;
V_34 = & V_9 -> V_34 ;
V_34 -> V_85 = & V_114 ;
V_37 = F_48 ( V_81 , 0 ) ;
if ( V_37 < 0 ) {
F_11 ( V_17 , L_22 ) ;
return - V_91 ;
}
V_84 = F_43 ( V_81 , V_87 , L_31 ) ;
V_4 = F_67 ( V_17 , V_84 -> V_88 , F_45 ( V_84 ) ) ;
if ( ! V_4 )
return - V_89 ;
V_96 = F_68 ( V_100 , L_32 ) ;
if ( V_96 < 0 ) {
F_11 ( V_17 , L_33 ) ;
return V_96 ;
}
V_97 = F_66 ( V_17 , sizeof( * V_97 ) * V_96 , V_112 ) ;
if ( ! V_97 )
return - V_89 ;
for ( V_98 = 0 ; V_98 < V_96 ; V_98 ++ ) {
snprintf ( V_103 , sizeof( V_103 ) , L_34 , V_98 ) ;
V_97 [ V_98 ] = F_69 ( V_17 , V_103 ) ;
if ( F_59 ( V_97 [ V_98 ] ) )
return F_70 ( V_97 [ V_98 ] ) ;
}
V_10 -> V_4 = V_4 ;
V_10 -> V_97 = V_97 ;
V_10 -> V_9 = V_9 ;
V_10 -> V_96 = V_96 ;
V_82 = F_54 ( V_10 ) ;
if ( V_82 ) {
F_11 ( V_17 , L_35 ) ;
return V_82 ;
}
F_71 ( V_81 , V_10 ) ;
F_72 ( V_17 ) ;
V_82 = F_73 ( V_17 ) ;
if ( V_82 < 0 ) {
F_11 ( V_17 , L_36 ) ;
goto V_115;
}
V_105 = F_74 ( V_17 , NULL , V_116 ) ;
if ( F_59 ( V_105 ) ) {
V_82 = F_70 ( V_105 ) ;
F_11 ( & V_81 -> V_17 , L_37 , V_82 ) ;
goto V_117;
}
V_11 = F_1 ( V_10 , V_14 ) ;
V_11 &= ~ V_15 ;
F_3 ( V_10 , V_14 , V_11 ) ;
V_10 -> V_20 = F_75 ( V_100 ) ;
if ( V_10 -> V_20 < 0 || V_10 -> V_20 > 2 )
V_10 -> V_20 = 2 ;
switch ( V_67 ) {
case V_118 :
F_3 ( V_10 , V_119 ,
V_120 ) ;
V_82 = F_47 ( V_10 , V_81 ) ;
if ( V_82 < 0 )
goto V_117;
break;
case V_68 :
F_3 ( V_10 , V_119 ,
V_121 ) ;
V_82 = F_57 ( V_17 ) ;
if ( V_82 )
goto V_117;
V_82 = F_42 ( V_10 , V_81 ) ;
if ( V_82 < 0 )
goto V_117;
break;
default:
F_11 ( V_17 , L_38 , V_67 ) ;
}
V_10 -> V_67 = V_67 ;
V_82 = F_49 ( V_17 , V_37 , F_33 ,
V_94 , L_39 , V_10 ) ;
if ( V_82 ) {
F_11 ( V_17 , L_24 ) ;
goto V_117;
}
return 0 ;
V_117:
F_76 ( V_17 ) ;
V_115:
F_77 ( V_17 ) ;
F_51 ( V_10 ) ;
return V_82 ;
}
static int F_78 ( struct V_16 * V_17 )
{
struct V_1 * V_10 = F_79 ( V_17 ) ;
struct V_8 * V_9 = V_10 -> V_9 ;
T_1 V_122 ;
if ( V_10 -> V_67 != V_118 )
return 0 ;
V_122 = F_80 ( V_9 , V_123 ) ;
V_122 &= ~ V_124 ;
F_81 ( V_9 , V_123 , V_122 ) ;
return 0 ;
}
static int F_82 ( struct V_16 * V_17 )
{
struct V_1 * V_10 = F_79 ( V_17 ) ;
struct V_8 * V_9 = V_10 -> V_9 ;
T_1 V_122 ;
if ( V_10 -> V_67 != V_118 )
return 0 ;
V_122 = F_80 ( V_9 , V_123 ) ;
V_122 |= V_124 ;
F_81 ( V_9 , V_123 , V_122 ) ;
return 0 ;
}
static int F_83 ( struct V_16 * V_17 )
{
struct V_1 * V_10 = F_79 ( V_17 ) ;
F_51 ( V_10 ) ;
return 0 ;
}
static int F_84 ( struct V_16 * V_17 )
{
struct V_1 * V_10 = F_79 ( V_17 ) ;
int V_82 ;
V_82 = F_54 ( V_10 ) ;
if ( V_82 ) {
F_11 ( V_17 , L_35 ) ;
return V_82 ;
}
return 0 ;
}
