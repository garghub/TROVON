static int F_1 ( struct V_1 * V_2 )
{
struct V_3 T_1 * V_4 = V_2 -> V_5 ;
T_2 V_6 , V_7 ;
int V_8 ;
int V_9 ;
if ( ! V_2 -> V_10 )
return 0 ;
V_6 = F_2 ( & V_4 -> V_11 ) ;
V_6 &= ~ V_12 ;
F_3 ( V_6 , & V_4 -> V_11 ) ;
for ( V_9 = 0 ; V_9 < V_2 -> V_13 ; V_9 ++ ) {
V_6 = F_2 ( & V_4 -> V_14 [ V_9 ] ) ;
V_6 &= ~ ( V_15 | V_16 ) ;
V_6 |= V_17 ;
F_3 ( V_6 , & V_4 -> V_14 [ V_9 ] ) ;
}
for ( V_9 = 0 ; V_9 < V_2 -> V_18 ; V_9 ++ ) {
V_6 = F_2 ( & V_4 -> V_19 [ V_9 ] ) ;
V_6 &= ~ ( V_20 | V_21 ) ;
V_6 |= V_22 ;
F_3 ( V_6 , & V_4 -> V_19 [ V_9 ] ) ;
}
V_7 = V_23 | V_24 |
V_25 | V_26 ;
V_8 = F_4 ( & V_4 -> V_27 , V_6 ,
( V_7 == ( V_6 & V_7 ) ) , 100 , 20000 ) ;
if ( V_8 ) {
F_5 ( V_2 -> V_28 , L_1 , V_6 ) ;
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
if ( ! V_2 -> V_10 )
return 0 ;
for ( V_9 = 0 ; V_9 < V_2 -> V_13 ; V_9 ++ ) {
V_6 = F_2 ( & V_4 -> V_14 [ V_9 ] ) ;
V_6 |= V_15 ;
F_3 ( V_6 , & V_4 -> V_14 [ V_9 ] ) ;
}
for ( V_9 = 0 ; V_9 < V_2 -> V_18 ; V_9 ++ ) {
V_6 = F_2 ( & V_4 -> V_19 [ V_9 ] ) ;
V_6 |= V_20 ;
F_3 ( V_6 , & V_4 -> V_19 [ V_9 ] ) ;
}
V_6 = F_2 ( & V_4 -> V_11 ) ;
V_6 |= V_12 ;
F_3 ( V_6 , & V_4 -> V_11 ) ;
V_8 = F_4 ( & V_4 -> V_27 , V_6 ,
( V_6 & V_29 ) , 100 , 100000 ) ;
if ( V_8 ) {
F_5 ( V_2 -> V_28 , L_2 ) ;
return V_8 ;
}
return 0 ;
}
static int F_7 ( struct V_1 * V_2 )
{
struct V_3 T_1 * V_4 = V_2 -> V_5 ;
T_2 V_6 ;
if ( ! V_2 -> V_10 )
return 0 ;
V_6 = F_2 ( & V_4 -> V_30 ) ;
V_6 |= V_31 ;
F_3 ( V_6 , & V_4 -> V_30 ) ;
F_8 ( 1 ) ;
V_6 = F_2 ( & V_4 -> V_30 ) ;
V_6 &= ~ V_31 ;
F_3 ( V_6 , & V_4 -> V_30 ) ;
V_6 = F_2 ( & V_4 -> V_32 ) ;
V_6 |= V_33 ;
F_3 ( V_6 , & V_4 -> V_32 ) ;
V_6 = F_2 ( & V_4 -> V_34 ) ;
V_2 -> V_13 = F_9 ( V_6 ) ;
V_2 -> V_18 = F_10 ( V_6 ) ;
F_11 ( V_2 -> V_28 , L_3 , V_35 ,
V_2 -> V_18 , V_2 -> V_13 ) ;
return F_1 ( V_2 ) ;
}
static int F_12 ( struct V_1 * V_2 )
{
int V_8 ;
V_8 = F_13 ( V_2 -> V_36 ) ;
if ( V_8 ) {
F_5 ( V_2 -> V_28 , L_4 ) ;
goto V_37;
}
V_8 = F_13 ( V_2 -> V_38 ) ;
if ( V_8 ) {
F_5 ( V_2 -> V_28 , L_5 ) ;
goto V_39;
}
if ( V_2 -> V_40 ) {
V_8 = F_13 ( V_2 -> V_41 ) ;
if ( V_8 ) {
F_5 ( V_2 -> V_28 , L_6 ) ;
goto V_42;
}
V_8 = F_13 ( V_2 -> V_43 ) ;
if ( V_8 ) {
F_5 ( V_2 -> V_28 , L_7 ) ;
goto V_44;
}
}
return 0 ;
V_44:
F_14 ( V_2 -> V_41 ) ;
V_42:
F_14 ( V_2 -> V_38 ) ;
V_39:
F_14 ( V_2 -> V_36 ) ;
V_37:
return - V_45 ;
}
static void F_15 ( struct V_1 * V_2 )
{
if ( V_2 -> V_40 ) {
F_14 ( V_2 -> V_43 ) ;
F_14 ( V_2 -> V_41 ) ;
}
F_14 ( V_2 -> V_38 ) ;
F_14 ( V_2 -> V_36 ) ;
}
static void F_16 ( struct V_1 * V_2 )
{
T_2 V_46 ;
struct V_47 * V_48 = V_2 -> V_48 ;
F_17 ( V_48 , V_49 , & V_46 ) ;
V_46 &= ~ V_50 ;
V_46 &= ~ ( F_18 ( 0xf ) ) ;
V_46 |= F_18 ( 0x8 ) ;
F_19 ( V_48 , V_49 , V_46 ) ;
F_19 ( V_48 , V_49 , V_46 | V_51 ) ;
F_17 ( V_48 , V_49 , & V_46 ) ;
F_11 ( V_2 -> V_28 , L_8 ,
V_35 , V_46 ) ;
}
static void F_20 ( struct V_1 * V_2 )
{
T_2 V_46 ;
F_17 ( V_2 -> V_48 , V_49 , & V_46 ) ;
V_46 &= ~ V_51 ;
F_19 ( V_2 -> V_48 , V_49 , V_46 ) ;
}
static void F_21 ( struct V_1 * V_2 )
{
T_2 V_46 ;
struct V_47 * V_48 = V_2 -> V_48 ;
F_17 ( V_48 , V_49 , & V_46 ) ;
V_46 &= ~ V_52 ;
V_46 &= ~ ( F_22 ( 0xf ) ) ;
V_46 |= F_22 ( 0x8 ) ;
F_19 ( V_48 , V_49 , V_46 ) ;
F_17 ( V_48 , V_49 , & V_46 ) ;
F_19 ( V_48 , V_49 , V_46 | V_53 ) ;
F_17 ( V_48 , V_54 , & V_46 ) ;
V_46 &= ~ ( F_23 ( 0xf ) ) ;
V_46 |= F_23 ( 0x8 ) ;
F_19 ( V_48 , V_54 , V_46 ) ;
F_19 ( V_48 , V_54 , V_46 | V_55 ) ;
}
static void F_24 ( struct V_1 * V_2 )
{
T_2 V_46 ;
struct V_47 * V_48 = V_2 -> V_48 ;
F_17 ( V_48 , V_49 , & V_46 ) ;
V_46 &= ~ V_53 ;
F_19 ( V_48 , V_49 , V_46 ) ;
F_17 ( V_48 , V_54 , & V_46 ) ;
V_46 &= ~ V_55 ;
F_19 ( V_48 , V_54 , V_46 ) ;
}
static void F_25 ( struct V_1 * V_2 )
{
if ( V_2 -> V_40 == V_56 )
F_16 ( V_2 ) ;
else if ( V_2 -> V_40 == V_57 )
F_21 ( V_2 ) ;
}
static void F_26 ( struct V_1 * V_2 )
{
if ( V_2 -> V_40 == V_56 )
F_20 ( V_2 ) ;
else if ( V_2 -> V_40 == V_57 )
F_24 ( V_2 ) ;
}
static int F_27 ( struct V_1 * V_2 ,
struct V_58 * V_59 )
{
struct V_60 * V_28 = V_2 -> V_28 ;
F_28 ( V_59 , L_9 , & V_2 -> V_40 ) ;
if ( ! V_2 -> V_40 )
return 0 ;
V_2 -> V_41 = F_29 ( V_28 , L_10 ) ;
if ( F_30 ( V_2 -> V_41 ) ) {
F_5 ( V_28 , L_11 ) ;
return F_31 ( V_2 -> V_41 ) ;
}
V_2 -> V_43 = F_29 ( V_28 , L_12 ) ;
if ( F_30 ( V_2 -> V_43 ) ) {
F_5 ( V_28 , L_13 ) ;
return F_31 ( V_2 -> V_43 ) ;
}
V_2 -> V_48 = F_32 ( V_59 ,
L_14 ) ;
if ( F_30 ( V_2 -> V_48 ) ) {
F_5 ( V_28 , L_15 ) ;
return F_31 ( V_2 -> V_48 ) ;
}
return 0 ;
}
static int F_33 ( struct V_1 * V_2 )
{
int V_9 ;
int V_8 ;
for ( V_9 = 0 ; V_9 < V_2 -> V_61 ; V_9 ++ ) {
V_8 = F_34 ( V_2 -> V_62 [ V_9 ] ) ;
if ( V_8 )
goto V_63;
}
return 0 ;
V_63:
for (; V_9 > 0 ; V_9 -- )
F_35 ( V_2 -> V_62 [ V_9 - 1 ] ) ;
return V_8 ;
}
static int F_36 ( struct V_1 * V_2 )
{
int V_9 ;
for ( V_9 = 0 ; V_9 < V_2 -> V_61 ; V_9 ++ )
F_35 ( V_2 -> V_62 [ V_9 ] ) ;
return 0 ;
}
static int F_37 ( struct V_1 * V_2 )
{
int V_9 ;
int V_8 ;
for ( V_9 = 0 ; V_9 < V_2 -> V_61 ; V_9 ++ ) {
V_8 = F_38 ( V_2 -> V_62 [ V_9 ] ) ;
if ( V_8 )
goto V_64;
}
return 0 ;
V_64:
for (; V_9 > 0 ; V_9 -- )
F_39 ( V_2 -> V_62 [ V_9 - 1 ] ) ;
return V_8 ;
}
static void F_40 ( struct V_1 * V_2 )
{
unsigned int V_9 ;
for ( V_9 = 0 ; V_9 < V_2 -> V_61 ; V_9 ++ )
F_39 ( V_2 -> V_62 [ V_9 ] ) ;
}
static int F_41 ( struct V_1 * V_2 )
{
int V_8 ;
V_8 = F_42 ( V_2 -> V_65 ) ;
if ( V_8 ) {
F_5 ( V_2 -> V_28 , L_16 ) ;
return V_8 ;
}
V_8 = F_42 ( V_2 -> V_66 ) ;
if ( V_8 ) {
F_5 ( V_2 -> V_28 , L_17 ) ;
F_43 ( V_2 -> V_65 ) ;
return V_8 ;
}
return 0 ;
}
static void F_44 ( struct V_1 * V_2 )
{
F_43 ( V_2 -> V_65 ) ;
F_43 ( V_2 -> V_66 ) ;
}
static void F_45 ( struct V_60 * V_28 , struct V_67 * V_68 )
{
struct V_69 * V_70 = F_46 ( V_68 ) ;
struct V_1 * V_2 = F_47 ( V_70 ) ;
V_68 -> V_71 |= V_72 ;
V_68 -> V_71 |= V_73 ;
V_68 -> V_71 |= V_74 ;
if ( V_2 -> V_75 )
V_68 -> V_71 |= V_76 ;
}
static int F_48 ( struct V_69 * V_70 )
{
struct V_67 * V_68 = F_49 ( V_70 ) ;
struct V_1 * V_2 = F_47 ( V_70 ) ;
int V_8 ;
if ( F_50 ( V_70 ) ) {
V_8 = F_7 ( V_2 ) ;
if ( V_8 )
return V_8 ;
}
V_8 = F_51 ( V_70 , F_45 ) ;
if ( V_8 )
return V_8 ;
if ( F_50 ( V_70 ) ) {
V_2 -> V_13 = V_68 -> V_77 ;
V_2 -> V_18 = V_68 -> V_78 ;
V_8 = F_52 ( V_2 ) ;
if ( V_8 )
return V_8 ;
}
return V_8 ;
}
static int F_53 ( struct V_79 * V_80 )
{
struct V_60 * V_28 = & V_80 -> V_28 ;
struct V_58 * V_81 = V_28 -> V_82 ;
struct V_1 * V_2 ;
const struct V_83 * V_84 ;
struct V_67 * V_68 ;
struct V_85 * V_86 ;
struct V_69 * V_70 ;
struct V_87 * V_87 ;
int V_88 ;
int V_8 = - V_89 ;
int V_90 ;
if ( F_54 () )
return - V_89 ;
V_84 = & V_91 ;
V_2 = F_55 ( V_28 , sizeof( * V_2 ) , V_92 ) ;
if ( ! V_2 )
return - V_93 ;
V_2 -> V_28 = V_28 ;
V_2 -> V_65 = F_56 ( V_28 , L_18 ) ;
if ( F_30 ( V_2 -> V_65 ) ) {
F_5 ( V_28 , L_19 ) ;
return F_31 ( V_2 -> V_65 ) ;
}
V_2 -> V_66 = F_56 ( V_28 , L_20 ) ;
if ( F_30 ( V_2 -> V_66 ) ) {
F_5 ( V_28 , L_21 ) ;
return F_31 ( V_2 -> V_66 ) ;
}
V_2 -> V_38 = F_29 ( V_28 , L_22 ) ;
if ( F_30 ( V_2 -> V_38 ) ) {
F_5 ( V_28 , L_23 ) ;
return F_31 ( V_2 -> V_38 ) ;
}
V_2 -> V_36 = F_29 ( V_28 , L_24 ) ;
if ( F_30 ( V_2 -> V_36 ) ) {
if ( F_31 ( V_2 -> V_36 ) == - V_94 )
return - V_94 ;
V_2 -> V_36 = NULL ;
}
V_2 -> V_75 = F_57 ( V_81 , L_25 ) ;
V_8 = F_27 ( V_2 , V_81 ) ;
if ( V_8 )
return V_8 ;
V_2 -> V_61 = F_58 ( V_81 ,
L_26 , L_27 ) ;
if ( V_2 -> V_61 > 0 ) {
V_2 -> V_62 = F_59 ( V_28 , V_2 -> V_61 ,
sizeof( * V_2 -> V_62 ) , V_92 ) ;
if ( ! V_2 -> V_62 )
return - V_93 ;
} else {
V_2 -> V_61 = 0 ;
}
F_60 ( V_28 ) ;
F_61 ( V_28 ) ;
F_62 ( V_28 ) ;
V_8 = F_41 ( V_2 ) ;
if ( V_8 )
goto V_95;
V_8 = F_12 ( V_2 ) ;
if ( V_8 )
goto V_96;
V_90 = F_63 ( V_80 , 0 ) ;
if ( V_90 < 0 ) {
V_8 = V_90 ;
goto V_97;
}
V_8 = F_64 ( V_28 , F_65 ( 32 ) ) ;
if ( V_8 )
goto V_97;
if ( ! V_28 -> V_98 )
V_28 -> V_98 = & V_28 -> V_99 ;
else
F_66 ( V_28 , F_65 ( 32 ) ) ;
V_70 = F_67 ( V_84 , V_28 , F_68 ( V_28 ) ) ;
if ( ! V_70 ) {
V_8 = - V_93 ;
goto V_97;
}
V_2 -> V_70 = F_69 ( V_80 ) ;
F_70 ( V_80 , V_2 ) ;
V_86 = F_71 ( V_80 , V_100 , L_28 ) ;
V_70 -> V_101 = F_72 ( V_28 , V_86 ) ;
if ( F_30 ( V_70 -> V_101 ) ) {
V_8 = F_31 ( V_70 -> V_101 ) ;
goto V_102;
}
V_70 -> V_103 = V_86 -> V_104 ;
V_70 -> V_105 = F_73 ( V_86 ) ;
V_86 = F_71 ( V_80 , V_100 , L_29 ) ;
if ( V_86 ) {
V_2 -> V_5 = F_72 ( V_28 , V_86 ) ;
if ( F_30 ( V_2 -> V_5 ) ) {
V_8 = F_31 ( V_2 -> V_5 ) ;
goto V_102;
}
V_2 -> V_10 = true ;
} else {
V_2 -> V_10 = false ;
}
for ( V_88 = 0 ; V_88 < V_2 -> V_61 ; V_88 ++ ) {
V_87 = F_74 ( V_28 , V_81 , V_88 ) ;
if ( F_30 ( V_87 ) ) {
V_8 = F_31 ( V_87 ) ;
goto V_102;
}
V_2 -> V_62 [ V_88 ] = V_87 ;
}
V_8 = F_33 ( V_2 ) ;
if ( V_8 )
goto V_102;
V_8 = F_37 ( V_2 ) ;
if ( V_8 )
goto V_106;
F_75 ( V_28 , true ) ;
V_68 = F_49 ( V_70 ) ;
V_68 -> V_107 = V_70 ;
V_68 -> V_108 = F_76 ( V_84 , V_28 ,
F_68 ( V_28 ) , V_70 ) ;
if ( ! V_68 -> V_108 ) {
V_8 = - V_93 ;
goto V_109;
}
V_8 = F_77 ( V_70 , V_90 , V_110 ) ;
if ( V_8 )
goto V_111;
if ( F_78 ( V_68 -> V_112 ) >= 4 )
V_68 -> V_108 -> V_113 = 1 ;
V_8 = F_77 ( V_68 -> V_108 , V_90 , V_110 ) ;
if ( V_8 )
goto V_114;
return 0 ;
V_114:
F_79 ( V_70 ) ;
V_111:
F_80 ( V_2 ) ;
F_81 ( V_68 -> V_108 ) ;
V_109:
F_40 ( V_2 ) ;
F_75 ( V_28 , false ) ;
V_106:
F_36 ( V_2 ) ;
V_102:
F_81 ( V_70 ) ;
V_97:
F_15 ( V_2 ) ;
V_96:
F_44 ( V_2 ) ;
V_95:
F_82 ( V_28 ) ;
F_83 ( V_28 ) ;
return V_8 ;
}
static int F_84 ( struct V_79 * V_28 )
{
struct V_1 * V_2 = F_69 ( V_28 ) ;
struct V_69 * V_70 = V_2 -> V_70 ;
struct V_67 * V_68 = F_49 ( V_70 ) ;
F_79 ( V_68 -> V_108 ) ;
F_40 ( V_2 ) ;
F_36 ( V_2 ) ;
F_75 ( & V_28 -> V_28 , false ) ;
F_79 ( V_70 ) ;
F_81 ( V_68 -> V_108 ) ;
F_81 ( V_70 ) ;
F_80 ( V_2 ) ;
F_15 ( V_2 ) ;
F_44 ( V_2 ) ;
F_82 ( & V_28 -> V_28 ) ;
F_83 ( & V_28 -> V_28 ) ;
return 0 ;
}
static int T_3 F_85 ( struct V_60 * V_28 )
{
struct V_1 * V_2 = F_86 ( V_28 ) ;
struct V_69 * V_70 = V_2 -> V_70 ;
struct V_67 * V_68 = F_49 ( V_70 ) ;
F_87 ( V_68 , L_30 , V_35 ) ;
F_88 ( V_115 , & V_70 -> V_116 ) ;
F_89 ( & V_70 -> V_117 ) ;
F_88 ( V_115 , & V_68 -> V_108 -> V_116 ) ;
F_89 ( & V_68 -> V_108 -> V_117 ) ;
F_6 ( V_2 ) ;
F_40 ( V_2 ) ;
F_15 ( V_2 ) ;
F_25 ( V_2 ) ;
return 0 ;
}
static int T_3 F_90 ( struct V_60 * V_28 )
{
struct V_1 * V_2 = F_86 ( V_28 ) ;
struct V_69 * V_70 = V_2 -> V_70 ;
struct V_67 * V_68 = F_49 ( V_70 ) ;
F_26 ( V_2 ) ;
F_12 ( V_2 ) ;
F_37 ( V_2 ) ;
F_1 ( V_2 ) ;
F_87 ( V_68 , L_31 , V_35 ) ;
F_91 ( V_115 , & V_70 -> V_116 ) ;
F_92 ( V_70 ) ;
F_91 ( V_115 , & V_68 -> V_108 -> V_116 ) ;
F_92 ( V_68 -> V_108 ) ;
return 0 ;
}
static int T_4 F_93 ( void )
{
F_94 ( & V_91 , & V_118 ) ;
return F_95 ( & V_119 ) ;
}
static void T_5 F_96 ( void )
{
F_97 ( & V_119 ) ;
}
