static int F_1 ( struct V_1 * V_2 )
{
struct V_3 T_1 * V_4 = V_2 -> V_5 ;
T_2 V_6 , V_7 ;
int V_8 ;
int V_9 ;
V_6 = F_2 ( & V_4 -> V_10 ) ;
V_6 &= ~ V_11 ;
F_3 ( V_6 , & V_4 -> V_10 ) ;
for ( V_9 = 0 ; V_9 < V_2 -> V_12 ; V_9 ++ ) {
V_6 = F_2 ( & V_4 -> V_13 [ V_9 ] ) ;
V_6 &= ~ ( V_14 | V_15 ) ;
V_6 |= V_16 ;
F_3 ( V_6 , & V_4 -> V_13 [ V_9 ] ) ;
}
for ( V_9 = 0 ; V_9 < V_2 -> V_17 ; V_9 ++ ) {
V_6 = F_2 ( & V_4 -> V_18 [ V_9 ] ) ;
V_6 &= ~ ( V_19 | V_20 ) ;
V_6 |= V_21 ;
F_3 ( V_6 , & V_4 -> V_18 [ V_9 ] ) ;
}
V_7 = V_22 | V_23 |
V_24 | V_25 ;
V_8 = F_4 ( & V_4 -> V_26 , V_6 ,
( V_7 == ( V_6 & V_7 ) ) , 100 , 20000 ) ;
if ( V_8 ) {
F_5 ( V_2 -> V_27 , L_1 , V_6 ) ;
return V_8 ;
}
return 0 ;
}
static int F_6 ( struct V_1 * V_2 )
{
struct V_3 T_1 * V_4 = V_2 -> V_5 ;
T_2 V_6 ;
int V_8 ;
int V_9 ;
for ( V_9 = 0 ; V_9 < V_2 -> V_12 ; V_9 ++ ) {
V_6 = F_2 ( & V_4 -> V_13 [ V_9 ] ) ;
V_6 |= V_14 ;
F_3 ( V_6 , & V_4 -> V_13 [ V_9 ] ) ;
}
for ( V_9 = 0 ; V_9 < V_2 -> V_17 ; V_9 ++ ) {
V_6 = F_2 ( & V_4 -> V_18 [ V_9 ] ) ;
V_6 |= V_19 ;
F_3 ( V_6 , & V_4 -> V_18 [ V_9 ] ) ;
}
V_6 = F_2 ( & V_4 -> V_10 ) ;
V_6 |= V_11 ;
F_3 ( V_6 , & V_4 -> V_10 ) ;
V_8 = F_4 ( & V_4 -> V_26 , V_6 ,
( V_6 & V_28 ) , 100 , 100000 ) ;
if ( V_8 ) {
F_5 ( V_2 -> V_27 , L_2 ) ;
return V_8 ;
}
return 0 ;
}
static int F_7 ( struct V_1 * V_2 )
{
struct V_3 T_1 * V_4 = V_2 -> V_5 ;
T_2 V_6 ;
V_6 = F_2 ( & V_4 -> V_29 ) ;
V_6 |= V_30 ;
F_3 ( V_6 , & V_4 -> V_29 ) ;
F_8 ( 1 ) ;
V_6 = F_2 ( & V_4 -> V_29 ) ;
V_6 &= ~ V_30 ;
F_3 ( V_6 , & V_4 -> V_29 ) ;
V_6 = F_2 ( & V_4 -> V_31 ) ;
V_6 |= V_32 ;
F_3 ( V_6 , & V_4 -> V_31 ) ;
V_6 = F_2 ( & V_4 -> V_33 ) ;
V_2 -> V_12 = F_9 ( V_6 ) ;
V_2 -> V_17 = F_10 ( V_6 ) ;
F_11 ( V_2 -> V_27 , L_3 , V_34 ,
V_2 -> V_17 , V_2 -> V_12 ) ;
return F_1 ( V_2 ) ;
}
static int F_12 ( struct V_1 * V_2 )
{
int V_8 ;
V_8 = F_13 ( V_2 -> V_35 ) ;
if ( V_8 ) {
F_5 ( V_2 -> V_27 , L_4 ) ;
goto V_36;
}
if ( V_2 -> V_37 ) {
V_8 = F_13 ( V_2 -> V_38 ) ;
if ( V_8 ) {
F_5 ( V_2 -> V_27 , L_5 ) ;
goto V_39;
}
V_8 = F_13 ( V_2 -> V_40 ) ;
if ( V_8 ) {
F_5 ( V_2 -> V_27 , L_6 ) ;
goto V_41;
}
}
return 0 ;
V_41:
F_14 ( V_2 -> V_38 ) ;
V_39:
F_14 ( V_2 -> V_35 ) ;
V_36:
return - V_42 ;
}
static void F_15 ( struct V_1 * V_2 )
{
if ( V_2 -> V_37 ) {
F_14 ( V_2 -> V_40 ) ;
F_14 ( V_2 -> V_38 ) ;
}
F_14 ( V_2 -> V_35 ) ;
}
static void F_16 ( struct V_1 * V_2 )
{
T_2 V_43 ;
struct V_44 * V_45 = V_2 -> V_45 ;
F_17 ( V_45 , V_46 , & V_43 ) ;
V_43 &= ~ V_47 ;
V_43 &= ~ ( F_18 ( 0xf ) ) ;
V_43 |= F_18 ( 0x8 ) ;
F_19 ( V_45 , V_46 , V_43 ) ;
F_19 ( V_45 , V_46 , V_43 | V_48 ) ;
F_17 ( V_45 , V_46 , & V_43 ) ;
F_11 ( V_2 -> V_27 , L_7 ,
V_34 , V_43 ) ;
}
static void F_20 ( struct V_1 * V_2 )
{
T_2 V_43 ;
F_17 ( V_2 -> V_45 , V_46 , & V_43 ) ;
V_43 &= ~ V_48 ;
F_19 ( V_2 -> V_45 , V_46 , V_43 ) ;
}
static void F_21 ( struct V_1 * V_2 )
{
T_2 V_43 ;
struct V_44 * V_45 = V_2 -> V_45 ;
F_17 ( V_45 , V_46 , & V_43 ) ;
V_43 &= ~ V_49 ;
V_43 &= ~ ( F_22 ( 0xf ) ) ;
V_43 |= F_22 ( 0x8 ) ;
F_19 ( V_45 , V_46 , V_43 ) ;
F_17 ( V_45 , V_46 , & V_43 ) ;
F_19 ( V_45 , V_46 , V_43 | V_50 ) ;
F_17 ( V_45 , V_51 , & V_43 ) ;
V_43 &= ~ ( F_23 ( 0xf ) ) ;
V_43 |= F_23 ( 0x8 ) ;
F_19 ( V_45 , V_51 , V_43 ) ;
F_19 ( V_45 , V_51 , V_43 | V_52 ) ;
}
static void F_24 ( struct V_1 * V_2 )
{
T_2 V_43 ;
struct V_44 * V_45 = V_2 -> V_45 ;
F_17 ( V_45 , V_46 , & V_43 ) ;
V_43 &= ~ V_50 ;
F_19 ( V_45 , V_46 , V_43 ) ;
F_17 ( V_45 , V_51 , & V_43 ) ;
V_43 &= ~ V_52 ;
F_19 ( V_45 , V_51 , V_43 ) ;
}
static void F_25 ( struct V_1 * V_2 )
{
if ( V_2 -> V_37 == V_53 )
F_16 ( V_2 ) ;
else if ( V_2 -> V_37 == V_54 )
F_21 ( V_2 ) ;
}
static void F_26 ( struct V_1 * V_2 )
{
if ( V_2 -> V_37 == V_53 )
F_20 ( V_2 ) ;
else if ( V_2 -> V_37 == V_54 )
F_24 ( V_2 ) ;
}
static int F_27 ( struct V_1 * V_2 ,
struct V_55 * V_56 )
{
struct V_57 * V_27 = V_2 -> V_27 ;
F_28 ( V_56 , L_8 , & V_2 -> V_37 ) ;
if ( ! V_2 -> V_37 )
return 0 ;
V_2 -> V_38 = F_29 ( V_27 , L_9 ) ;
if ( F_30 ( V_2 -> V_38 ) ) {
F_5 ( V_27 , L_10 ) ;
return F_31 ( V_2 -> V_38 ) ;
}
V_2 -> V_40 = F_29 ( V_27 , L_11 ) ;
if ( F_30 ( V_2 -> V_40 ) ) {
F_5 ( V_27 , L_12 ) ;
return F_31 ( V_2 -> V_40 ) ;
}
V_2 -> V_45 = F_32 ( V_56 ,
L_13 ) ;
if ( F_30 ( V_2 -> V_45 ) ) {
F_5 ( V_27 , L_14 ) ;
return F_31 ( V_2 -> V_45 ) ;
}
return 0 ;
}
static int F_33 ( struct V_1 * V_2 )
{
int V_9 ;
int V_8 ;
for ( V_9 = 0 ; V_9 < V_2 -> V_58 ; V_9 ++ ) {
V_8 = F_34 ( V_2 -> V_59 [ V_9 ] ) ;
if ( V_8 )
goto V_60;
}
return 0 ;
V_60:
for (; V_9 > 0 ; V_9 -- )
F_35 ( V_2 -> V_59 [ V_9 - 1 ] ) ;
return V_8 ;
}
static int F_36 ( struct V_1 * V_2 )
{
int V_9 ;
for ( V_9 = 0 ; V_9 < V_2 -> V_58 ; V_9 ++ )
F_35 ( V_2 -> V_59 [ V_9 ] ) ;
return 0 ;
}
static int F_37 ( struct V_1 * V_2 )
{
int V_9 ;
int V_8 ;
for ( V_9 = 0 ; V_9 < V_2 -> V_58 ; V_9 ++ ) {
V_8 = F_38 ( V_2 -> V_59 [ V_9 ] ) ;
if ( V_8 )
goto V_61;
}
return 0 ;
V_61:
for (; V_9 > 0 ; V_9 -- )
F_39 ( V_2 -> V_59 [ V_9 - 1 ] ) ;
return V_8 ;
}
static void F_40 ( struct V_1 * V_2 )
{
unsigned int V_9 ;
for ( V_9 = 0 ; V_9 < V_2 -> V_58 ; V_9 ++ )
F_39 ( V_2 -> V_59 [ V_9 ] ) ;
}
static int F_41 ( struct V_1 * V_2 )
{
int V_8 ;
V_8 = F_42 ( V_2 -> V_62 ) ;
if ( V_8 ) {
F_5 ( V_2 -> V_27 , L_15 ) ;
return V_8 ;
}
V_8 = F_42 ( V_2 -> V_63 ) ;
if ( V_8 ) {
F_5 ( V_2 -> V_27 , L_16 ) ;
F_43 ( V_2 -> V_62 ) ;
return V_8 ;
}
return 0 ;
}
static void F_44 ( struct V_1 * V_2 )
{
F_43 ( V_2 -> V_62 ) ;
F_43 ( V_2 -> V_63 ) ;
}
static void F_45 ( struct V_57 * V_27 , struct V_64 * V_65 )
{
struct V_66 * V_67 = F_46 ( V_65 ) ;
struct V_1 * V_2 = F_47 ( V_67 ) ;
V_65 -> V_68 |= V_69 ;
V_65 -> V_68 |= V_70 ;
V_65 -> V_68 |= V_71 ;
if ( V_2 -> V_72 )
V_65 -> V_68 |= V_73 ;
}
static int F_48 ( struct V_66 * V_67 )
{
struct V_1 * V_2 = F_47 ( V_67 ) ;
int V_8 ;
if ( F_49 ( V_67 ) ) {
V_8 = F_7 ( V_2 ) ;
if ( V_8 )
return V_8 ;
V_8 = F_50 ( V_2 ) ;
if ( V_8 )
return V_8 ;
}
return F_51 ( V_67 , F_45 ) ;
}
static int F_52 ( struct V_74 * V_75 )
{
struct V_57 * V_27 = & V_75 -> V_27 ;
struct V_55 * V_76 = V_27 -> V_77 ;
struct V_1 * V_2 ;
const struct V_78 * V_79 ;
struct V_64 * V_65 ;
struct V_80 * V_81 ;
struct V_66 * V_67 ;
struct V_82 * V_82 ;
int V_83 ;
int V_8 = - V_84 ;
int V_85 ;
if ( F_53 () )
return - V_84 ;
V_79 = & V_86 ;
V_2 = F_54 ( V_27 , sizeof( * V_2 ) , V_87 ) ;
if ( ! V_2 )
return - V_88 ;
V_2 -> V_27 = V_27 ;
V_2 -> V_62 = F_55 ( V_27 , L_17 ) ;
if ( F_30 ( V_2 -> V_62 ) ) {
F_5 ( V_27 , L_18 ) ;
return F_31 ( V_2 -> V_62 ) ;
}
V_2 -> V_63 = F_55 ( V_27 , L_19 ) ;
if ( F_30 ( V_2 -> V_63 ) ) {
F_5 ( V_27 , L_20 ) ;
return F_31 ( V_2 -> V_63 ) ;
}
V_2 -> V_35 = F_29 ( V_27 , L_21 ) ;
if ( F_30 ( V_2 -> V_35 ) ) {
F_5 ( V_27 , L_22 ) ;
return F_31 ( V_2 -> V_35 ) ;
}
V_2 -> V_72 = F_56 ( V_76 , L_23 ) ;
V_8 = F_27 ( V_2 , V_76 ) ;
if ( V_8 )
return V_8 ;
V_2 -> V_58 = F_57 ( V_76 ,
L_24 , L_25 ) ;
if ( V_2 -> V_58 > 0 ) {
V_2 -> V_59 = F_58 ( V_27 , V_2 -> V_58 ,
sizeof( * V_2 -> V_59 ) , V_87 ) ;
if ( ! V_2 -> V_59 )
return - V_88 ;
} else {
V_2 -> V_58 = 0 ;
}
F_59 ( V_27 ) ;
F_60 ( V_27 ) ;
F_61 ( V_27 ) ;
V_8 = F_41 ( V_2 ) ;
if ( V_8 )
goto V_89;
V_8 = F_12 ( V_2 ) ;
if ( V_8 )
goto V_90;
V_85 = F_62 ( V_75 , 0 ) ;
if ( V_85 < 0 )
goto V_91;
V_8 = F_63 ( V_27 , F_64 ( 32 ) ) ;
if ( V_8 )
goto V_91;
if ( ! V_27 -> V_92 )
V_27 -> V_92 = & V_27 -> V_93 ;
else
F_65 ( V_27 , F_64 ( 32 ) ) ;
V_67 = F_66 ( V_79 , V_27 , F_67 ( V_27 ) ) ;
if ( ! V_67 ) {
V_8 = - V_88 ;
goto V_91;
}
V_2 -> V_67 = F_68 ( V_75 ) ;
F_69 ( V_75 , V_2 ) ;
V_81 = F_70 ( V_75 , V_94 , 0 ) ;
V_67 -> V_95 = F_71 ( V_27 , V_81 ) ;
if ( F_30 ( V_67 -> V_95 ) ) {
V_8 = F_31 ( V_67 -> V_95 ) ;
goto V_96;
}
V_67 -> V_97 = V_81 -> V_98 ;
V_67 -> V_99 = F_72 ( V_81 ) ;
V_81 = F_70 ( V_75 , V_94 , 1 ) ;
V_2 -> V_5 = F_71 ( V_27 , V_81 ) ;
if ( F_30 ( V_2 -> V_5 ) ) {
V_8 = F_31 ( V_2 -> V_5 ) ;
goto V_96;
}
for ( V_83 = 0 ; V_83 < V_2 -> V_58 ; V_83 ++ ) {
V_82 = F_73 ( V_27 , V_76 , V_83 ) ;
if ( F_30 ( V_82 ) ) {
V_8 = F_31 ( V_82 ) ;
goto V_96;
}
V_2 -> V_59 [ V_83 ] = V_82 ;
}
V_8 = F_33 ( V_2 ) ;
if ( V_8 )
goto V_96;
V_8 = F_37 ( V_2 ) ;
if ( V_8 )
goto V_100;
F_74 ( V_27 , true ) ;
V_65 = F_75 ( V_67 ) ;
V_65 -> V_101 = V_67 ;
V_65 -> V_102 = F_76 ( V_79 , V_27 ,
F_67 ( V_27 ) , V_67 ) ;
if ( ! V_65 -> V_102 ) {
V_8 = - V_88 ;
goto V_103;
}
if ( F_77 ( V_65 -> V_104 ) >= 4 )
V_65 -> V_102 -> V_105 = 1 ;
V_8 = F_78 ( V_67 , V_85 , V_106 ) ;
if ( V_8 )
goto V_107;
V_8 = F_78 ( V_65 -> V_102 , V_85 , V_106 ) ;
if ( V_8 )
goto V_108;
return 0 ;
V_108:
F_79 ( V_67 ) ;
V_107:
F_80 ( V_2 ) ;
F_81 ( V_65 -> V_102 ) ;
V_103:
F_40 ( V_2 ) ;
F_74 ( V_27 , false ) ;
V_100:
F_36 ( V_2 ) ;
V_96:
F_81 ( V_67 ) ;
V_91:
F_15 ( V_2 ) ;
V_90:
F_44 ( V_2 ) ;
V_89:
F_82 ( V_27 ) ;
F_83 ( V_27 ) ;
return V_8 ;
}
static int F_84 ( struct V_74 * V_27 )
{
struct V_1 * V_2 = F_68 ( V_27 ) ;
struct V_66 * V_67 = V_2 -> V_67 ;
struct V_64 * V_65 = F_75 ( V_67 ) ;
F_79 ( V_65 -> V_102 ) ;
F_40 ( V_2 ) ;
F_36 ( V_2 ) ;
F_74 ( & V_27 -> V_27 , false ) ;
F_79 ( V_67 ) ;
F_81 ( V_65 -> V_102 ) ;
F_81 ( V_67 ) ;
F_80 ( V_2 ) ;
F_15 ( V_2 ) ;
F_44 ( V_2 ) ;
F_82 ( & V_27 -> V_27 ) ;
F_83 ( & V_27 -> V_27 ) ;
return 0 ;
}
static int F_85 ( struct V_57 * V_27 )
{
struct V_1 * V_2 = F_86 ( V_27 ) ;
struct V_66 * V_67 = V_2 -> V_67 ;
struct V_64 * V_65 = F_75 ( V_67 ) ;
F_87 ( V_65 , L_26 , V_34 ) ;
F_88 ( V_109 , & V_67 -> V_110 ) ;
F_89 ( & V_67 -> V_111 ) ;
F_88 ( V_109 , & V_65 -> V_102 -> V_110 ) ;
F_89 ( & V_65 -> V_102 -> V_111 ) ;
F_6 ( V_2 ) ;
F_40 ( V_2 ) ;
F_15 ( V_2 ) ;
F_25 ( V_2 ) ;
return 0 ;
}
static int F_90 ( struct V_57 * V_27 )
{
struct V_1 * V_2 = F_86 ( V_27 ) ;
struct V_66 * V_67 = V_2 -> V_67 ;
struct V_64 * V_65 = F_75 ( V_67 ) ;
F_26 ( V_2 ) ;
F_12 ( V_2 ) ;
F_37 ( V_2 ) ;
F_1 ( V_2 ) ;
F_87 ( V_65 , L_27 , V_34 ) ;
F_91 ( V_109 , & V_67 -> V_110 ) ;
F_92 ( V_67 ) ;
F_91 ( V_109 , & V_65 -> V_102 -> V_110 ) ;
F_92 ( V_65 -> V_102 ) ;
return 0 ;
}
static int T_3 F_93 ( void )
{
F_94 ( & V_86 , & V_112 ) ;
return F_95 ( & V_113 ) ;
}
static void T_4 F_96 ( void )
{
F_97 ( & V_113 ) ;
}
