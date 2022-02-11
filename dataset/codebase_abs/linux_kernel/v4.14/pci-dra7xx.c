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
V_27 | V_28 ) ;
F_3 ( V_10 ,
V_29 ,
V_28 | V_27 ) ;
}
static void F_15 ( struct V_1 * V_10 )
{
F_3 ( V_10 , V_30 ,
V_31 ) ;
F_3 ( V_10 , V_32 ,
V_31 ) ;
}
static void F_16 ( struct V_1 * V_10 )
{
F_15 ( V_10 ) ;
F_14 ( V_10 ) ;
}
static int F_17 ( struct V_33 * V_34 )
{
struct V_8 * V_9 = F_18 ( V_34 ) ;
struct V_1 * V_10 = F_7 ( V_9 ) ;
F_19 ( V_34 ) ;
F_9 ( V_9 ) ;
F_20 ( V_9 ) ;
F_21 ( V_34 ) ;
F_16 ( V_10 ) ;
return 0 ;
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
V_10 -> V_35 = F_27 ( V_45 , V_47 ,
& V_48 , V_34 ) ;
if ( ! V_10 -> V_35 ) {
F_11 ( V_17 , L_3 ) ;
return - V_46 ;
}
return 0 ;
}
static T_4 F_28 ( int V_37 , void * V_49 )
{
struct V_1 * V_10 = V_49 ;
struct V_8 * V_9 = V_10 -> V_9 ;
struct V_33 * V_34 = & V_9 -> V_34 ;
T_1 V_11 ;
V_11 = F_1 ( V_10 , V_26 ) ;
switch ( V_11 ) {
case V_28 :
F_29 ( V_34 ) ;
break;
case V_50 :
case V_51 :
case V_52 :
case V_53 :
F_30 ( F_31 ( V_10 -> V_35 ,
F_32 ( V_11 ) ) ) ;
break;
}
F_3 ( V_10 , V_26 , V_11 ) ;
return V_54 ;
}
static T_4 F_33 ( int V_37 , void * V_49 )
{
struct V_1 * V_10 = V_49 ;
struct V_8 * V_9 = V_10 -> V_9 ;
struct V_16 * V_17 = V_9 -> V_17 ;
struct V_55 * V_56 = & V_9 -> V_56 ;
T_1 V_11 ;
V_11 = F_1 ( V_10 , V_30 ) ;
if ( V_11 & V_57 )
F_34 ( V_17 , L_4 ) ;
if ( V_11 & V_58 )
F_34 ( V_17 , L_5 ) ;
if ( V_11 & V_59 )
F_34 ( V_17 , L_6 ) ;
if ( V_11 & V_60 )
F_34 ( V_17 , L_7 ) ;
if ( V_11 & V_61 )
F_34 ( V_17 , L_8 ) ;
if ( V_11 & V_62 )
F_34 ( V_17 , L_9 ) ;
if ( V_11 & V_63 )
F_34 ( V_17 ,
L_10 ) ;
if ( V_11 & V_64 )
F_34 ( V_17 ,
L_11 ) ;
if ( V_11 & V_65 )
F_34 ( V_17 , L_12 ) ;
if ( V_11 & V_66 )
F_34 ( V_17 , L_13 ) ;
if ( V_11 & V_67 ) {
if ( V_10 -> V_68 == V_69 )
F_35 ( V_56 ) ;
F_34 ( V_17 , L_14 ) ;
}
if ( V_11 & V_70 )
F_34 ( V_17 , L_15 ) ;
if ( V_11 & V_71 )
F_34 ( V_17 , L_16 ) ;
F_3 ( V_10 , V_30 , V_11 ) ;
return V_54 ;
}
static void F_36 ( struct V_8 * V_9 , enum V_72 V_73 )
{
T_1 V_11 ;
V_11 = V_74 + ( 4 * V_73 ) ;
F_37 ( V_9 , V_11 , 0x0 ) ;
F_38 ( V_9 , V_11 , 0x0 ) ;
}
static void F_39 ( struct V_55 * V_56 )
{
struct V_8 * V_9 = F_40 ( V_56 ) ;
struct V_1 * V_10 = F_7 ( V_9 ) ;
enum V_72 V_73 ;
for ( V_73 = V_75 ; V_73 <= V_76 ; V_73 ++ )
F_36 ( V_9 , V_73 ) ;
F_15 ( V_10 ) ;
}
static void F_41 ( struct V_1 * V_10 )
{
F_3 ( V_10 , V_77 , 0x1 ) ;
F_42 ( 1 ) ;
F_3 ( V_10 , V_78 , 0x1 ) ;
}
static void F_43 ( struct V_1 * V_10 ,
T_5 V_79 )
{
T_1 V_11 ;
V_11 = ( V_79 - 1 ) << V_80 ;
V_11 |= V_81 ;
F_3 ( V_10 , V_82 , V_11 ) ;
}
static int F_44 ( struct V_55 * V_56 ,
enum V_83 type , T_5 V_79 )
{
struct V_8 * V_9 = F_40 ( V_56 ) ;
struct V_1 * V_10 = F_7 ( V_9 ) ;
switch ( type ) {
case V_84 :
F_41 ( V_10 ) ;
break;
case V_85 :
F_43 ( V_10 , V_79 ) ;
break;
default:
F_11 ( V_9 -> V_17 , L_17 ) ;
}
return 0 ;
}
static int T_6 F_45 ( struct V_1 * V_10 ,
struct V_86 * V_87 )
{
int V_88 ;
struct V_55 * V_56 ;
struct V_89 * V_90 ;
struct V_16 * V_17 = & V_87 -> V_17 ;
struct V_8 * V_9 = V_10 -> V_9 ;
V_56 = & V_9 -> V_56 ;
V_56 -> V_91 = & V_92 ;
V_90 = F_46 ( V_87 , V_93 , L_18 ) ;
V_9 -> V_21 = F_47 ( V_17 , V_90 -> V_94 , F_48 ( V_90 ) ) ;
if ( ! V_9 -> V_21 )
return - V_95 ;
V_90 = F_46 ( V_87 , V_93 , L_19 ) ;
V_9 -> V_96 = F_47 ( V_17 , V_90 -> V_94 , F_48 ( V_90 ) ) ;
if ( ! V_9 -> V_96 )
return - V_95 ;
V_90 = F_46 ( V_87 , V_93 , L_20 ) ;
if ( ! V_90 )
return - V_97 ;
V_56 -> V_98 = V_90 -> V_94 ;
V_56 -> V_99 = F_48 ( V_90 ) ;
V_88 = F_49 ( V_56 ) ;
if ( V_88 ) {
F_11 ( V_17 , L_21 ) ;
return V_88 ;
}
return 0 ;
}
static int T_6 F_50 ( struct V_1 * V_10 ,
struct V_86 * V_87 )
{
int V_88 ;
struct V_8 * V_9 = V_10 -> V_9 ;
struct V_33 * V_34 = & V_9 -> V_34 ;
struct V_16 * V_17 = V_9 -> V_17 ;
struct V_89 * V_90 ;
V_34 -> V_37 = F_51 ( V_87 , 1 ) ;
if ( V_34 -> V_37 < 0 ) {
F_11 ( V_17 , L_22 ) ;
return V_34 -> V_37 ;
}
V_88 = F_52 ( V_17 , V_34 -> V_37 , F_28 ,
V_100 | V_101 ,
L_23 , V_10 ) ;
if ( V_88 ) {
F_11 ( V_17 , L_24 ) ;
return V_88 ;
}
V_88 = F_25 ( V_34 ) ;
if ( V_88 < 0 )
return V_88 ;
V_90 = F_46 ( V_87 , V_93 , L_25 ) ;
V_9 -> V_21 = F_47 ( V_17 , V_90 -> V_94 , F_48 ( V_90 ) ) ;
if ( ! V_9 -> V_21 )
return - V_95 ;
V_88 = F_53 ( V_34 ) ;
if ( V_88 ) {
F_11 ( V_17 , L_26 ) ;
return V_88 ;
}
return 0 ;
}
static void F_54 ( struct V_1 * V_10 )
{
int V_102 = V_10 -> V_102 ;
while ( V_102 -- ) {
F_55 ( V_10 -> V_103 [ V_102 ] ) ;
F_56 ( V_10 -> V_103 [ V_102 ] ) ;
}
}
static int F_57 ( struct V_1 * V_10 )
{
int V_102 = V_10 -> V_102 ;
int V_88 ;
int V_104 ;
for ( V_104 = 0 ; V_104 < V_102 ; V_104 ++ ) {
V_88 = F_58 ( V_10 -> V_103 [ V_104 ] ) ;
if ( V_88 < 0 )
goto V_105;
V_88 = F_59 ( V_10 -> V_103 [ V_104 ] ) ;
if ( V_88 < 0 ) {
F_56 ( V_10 -> V_103 [ V_104 ] ) ;
goto V_105;
}
}
return 0 ;
V_105:
while ( -- V_104 >= 0 ) {
F_55 ( V_10 -> V_103 [ V_104 ] ) ;
F_56 ( V_10 -> V_103 [ V_104 ] ) ;
}
return V_88 ;
}
static int F_60 ( struct V_16 * V_17 )
{
int V_88 ;
struct V_42 * V_106 = V_17 -> V_44 ;
struct V_107 args ;
struct V_108 * V_108 ;
V_108 = F_61 ( V_106 ,
L_27 ) ;
if ( F_62 ( V_108 ) ) {
F_34 ( V_17 , L_28 ) ;
return - V_97 ;
}
V_88 = F_63 ( V_106 , L_27 ,
2 , 0 , & args ) ;
if ( V_88 ) {
F_11 ( V_17 , L_29 ) ;
return V_88 ;
}
V_88 = F_64 ( V_108 , args . args [ 0 ] , args . args [ 1 ] ,
args . args [ 1 ] ) ;
if ( V_88 )
F_11 ( V_17 , L_30 ) ;
F_65 ( args . V_106 ) ;
return V_88 ;
}
static int T_6 F_66 ( struct V_86 * V_87 )
{
T_1 V_11 ;
int V_88 ;
int V_37 ;
int V_104 ;
int V_102 ;
struct V_103 * * V_103 ;
void T_7 * V_4 ;
struct V_89 * V_90 ;
struct V_8 * V_9 ;
struct V_33 * V_34 ;
struct V_1 * V_10 ;
struct V_16 * V_17 = & V_87 -> V_17 ;
struct V_42 * V_106 = V_17 -> V_44 ;
char V_109 [ 10 ] ;
struct V_110 * V_111 ;
const struct V_112 * V_113 ;
const struct V_114 * V_115 ;
enum V_116 V_68 ;
V_113 = F_67 ( F_68 ( V_117 ) , V_17 ) ;
if ( ! V_113 )
return - V_97 ;
V_115 = (struct V_114 * ) V_113 -> V_115 ;
V_68 = (enum V_116 ) V_115 -> V_68 ;
V_10 = F_69 ( V_17 , sizeof( * V_10 ) , V_118 ) ;
if ( ! V_10 )
return - V_95 ;
V_9 = F_69 ( V_17 , sizeof( * V_9 ) , V_118 ) ;
if ( ! V_9 )
return - V_95 ;
V_9 -> V_17 = V_17 ;
V_9 -> V_91 = & V_119 ;
V_34 = & V_9 -> V_34 ;
V_34 -> V_91 = & V_120 ;
V_37 = F_51 ( V_87 , 0 ) ;
if ( V_37 < 0 ) {
F_11 ( V_17 , L_31 , V_37 ) ;
return V_37 ;
}
V_90 = F_46 ( V_87 , V_93 , L_32 ) ;
V_4 = F_70 ( V_17 , V_90 -> V_94 , F_48 ( V_90 ) ) ;
if ( ! V_4 )
return - V_95 ;
V_102 = F_71 ( V_106 , L_33 ) ;
if ( V_102 < 0 ) {
F_11 ( V_17 , L_34 ) ;
return V_102 ;
}
V_103 = F_69 ( V_17 , sizeof( * V_103 ) * V_102 , V_118 ) ;
if ( ! V_103 )
return - V_95 ;
for ( V_104 = 0 ; V_104 < V_102 ; V_104 ++ ) {
snprintf ( V_109 , sizeof( V_109 ) , L_35 , V_104 ) ;
V_103 [ V_104 ] = F_72 ( V_17 , V_109 ) ;
if ( F_62 ( V_103 [ V_104 ] ) )
return F_73 ( V_103 [ V_104 ] ) ;
}
V_10 -> V_4 = V_4 ;
V_10 -> V_103 = V_103 ;
V_10 -> V_9 = V_9 ;
V_10 -> V_102 = V_102 ;
V_88 = F_57 ( V_10 ) ;
if ( V_88 ) {
F_11 ( V_17 , L_36 ) ;
return V_88 ;
}
F_74 ( V_87 , V_10 ) ;
F_75 ( V_17 ) ;
V_88 = F_76 ( V_17 ) ;
if ( V_88 < 0 ) {
F_11 ( V_17 , L_37 ) ;
goto V_121;
}
V_111 = F_77 ( V_17 , NULL , V_122 ) ;
if ( F_62 ( V_111 ) ) {
V_88 = F_73 ( V_111 ) ;
F_11 ( & V_87 -> V_17 , L_38 , V_88 ) ;
goto V_123;
}
V_11 = F_1 ( V_10 , V_14 ) ;
V_11 &= ~ V_15 ;
F_3 ( V_10 , V_14 , V_11 ) ;
V_10 -> V_20 = F_78 ( V_106 ) ;
if ( V_10 -> V_20 < 0 || V_10 -> V_20 > 2 )
V_10 -> V_20 = 2 ;
switch ( V_68 ) {
case V_124 :
F_3 ( V_10 , V_125 ,
V_126 ) ;
V_88 = F_50 ( V_10 , V_87 ) ;
if ( V_88 < 0 )
goto V_123;
break;
case V_69 :
F_3 ( V_10 , V_125 ,
V_127 ) ;
V_88 = F_60 ( V_17 ) ;
if ( V_88 )
goto V_123;
V_88 = F_45 ( V_10 , V_87 ) ;
if ( V_88 < 0 )
goto V_123;
break;
default:
F_11 ( V_17 , L_39 , V_68 ) ;
}
V_10 -> V_68 = V_68 ;
V_88 = F_52 ( V_17 , V_37 , F_33 ,
V_100 , L_40 , V_10 ) ;
if ( V_88 ) {
F_11 ( V_17 , L_24 ) ;
goto V_123;
}
return 0 ;
V_123:
F_79 ( V_17 ) ;
V_121:
F_80 ( V_17 ) ;
F_54 ( V_10 ) ;
return V_88 ;
}
static int F_81 ( struct V_16 * V_17 )
{
struct V_1 * V_10 = F_82 ( V_17 ) ;
struct V_8 * V_9 = V_10 -> V_9 ;
T_1 V_128 ;
if ( V_10 -> V_68 != V_124 )
return 0 ;
V_128 = F_83 ( V_9 , V_129 ) ;
V_128 &= ~ V_130 ;
F_38 ( V_9 , V_129 , V_128 ) ;
return 0 ;
}
static int F_84 ( struct V_16 * V_17 )
{
struct V_1 * V_10 = F_82 ( V_17 ) ;
struct V_8 * V_9 = V_10 -> V_9 ;
T_1 V_128 ;
if ( V_10 -> V_68 != V_124 )
return 0 ;
V_128 = F_83 ( V_9 , V_129 ) ;
V_128 |= V_130 ;
F_38 ( V_9 , V_129 , V_128 ) ;
return 0 ;
}
static int F_85 ( struct V_16 * V_17 )
{
struct V_1 * V_10 = F_82 ( V_17 ) ;
F_54 ( V_10 ) ;
return 0 ;
}
static int F_86 ( struct V_16 * V_17 )
{
struct V_1 * V_10 = F_82 ( V_17 ) ;
int V_88 ;
V_88 = F_57 ( V_10 ) ;
if ( V_88 ) {
F_11 ( V_17 , L_36 ) ;
return V_88 ;
}
return 0 ;
}
