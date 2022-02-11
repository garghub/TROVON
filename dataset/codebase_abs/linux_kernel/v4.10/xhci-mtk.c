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
if ( V_2 -> V_38 ) {
V_8 = F_13 ( V_2 -> V_39 ) ;
if ( V_8 ) {
F_5 ( V_2 -> V_28 , L_5 ) ;
goto V_40;
}
V_8 = F_13 ( V_2 -> V_41 ) ;
if ( V_8 ) {
F_5 ( V_2 -> V_28 , L_6 ) ;
goto V_42;
}
}
return 0 ;
V_42:
F_14 ( V_2 -> V_39 ) ;
V_40:
F_14 ( V_2 -> V_36 ) ;
V_37:
return - V_43 ;
}
static void F_15 ( struct V_1 * V_2 )
{
if ( V_2 -> V_38 ) {
F_14 ( V_2 -> V_41 ) ;
F_14 ( V_2 -> V_39 ) ;
}
F_14 ( V_2 -> V_36 ) ;
}
static void F_16 ( struct V_1 * V_2 )
{
T_2 V_44 ;
struct V_45 * V_46 = V_2 -> V_46 ;
F_17 ( V_46 , V_47 , & V_44 ) ;
V_44 &= ~ V_48 ;
V_44 &= ~ ( F_18 ( 0xf ) ) ;
V_44 |= F_18 ( 0x8 ) ;
F_19 ( V_46 , V_47 , V_44 ) ;
F_19 ( V_46 , V_47 , V_44 | V_49 ) ;
F_17 ( V_46 , V_47 , & V_44 ) ;
F_11 ( V_2 -> V_28 , L_7 ,
V_35 , V_44 ) ;
}
static void F_20 ( struct V_1 * V_2 )
{
T_2 V_44 ;
F_17 ( V_2 -> V_46 , V_47 , & V_44 ) ;
V_44 &= ~ V_49 ;
F_19 ( V_2 -> V_46 , V_47 , V_44 ) ;
}
static void F_21 ( struct V_1 * V_2 )
{
T_2 V_44 ;
struct V_45 * V_46 = V_2 -> V_46 ;
F_17 ( V_46 , V_47 , & V_44 ) ;
V_44 &= ~ V_50 ;
V_44 &= ~ ( F_22 ( 0xf ) ) ;
V_44 |= F_22 ( 0x8 ) ;
F_19 ( V_46 , V_47 , V_44 ) ;
F_17 ( V_46 , V_47 , & V_44 ) ;
F_19 ( V_46 , V_47 , V_44 | V_51 ) ;
F_17 ( V_46 , V_52 , & V_44 ) ;
V_44 &= ~ ( F_23 ( 0xf ) ) ;
V_44 |= F_23 ( 0x8 ) ;
F_19 ( V_46 , V_52 , V_44 ) ;
F_19 ( V_46 , V_52 , V_44 | V_53 ) ;
}
static void F_24 ( struct V_1 * V_2 )
{
T_2 V_44 ;
struct V_45 * V_46 = V_2 -> V_46 ;
F_17 ( V_46 , V_47 , & V_44 ) ;
V_44 &= ~ V_51 ;
F_19 ( V_46 , V_47 , V_44 ) ;
F_17 ( V_46 , V_52 , & V_44 ) ;
V_44 &= ~ V_53 ;
F_19 ( V_46 , V_52 , V_44 ) ;
}
static void F_25 ( struct V_1 * V_2 )
{
if ( V_2 -> V_38 == V_54 )
F_16 ( V_2 ) ;
else if ( V_2 -> V_38 == V_55 )
F_21 ( V_2 ) ;
}
static void F_26 ( struct V_1 * V_2 )
{
if ( V_2 -> V_38 == V_54 )
F_20 ( V_2 ) ;
else if ( V_2 -> V_38 == V_55 )
F_24 ( V_2 ) ;
}
static int F_27 ( struct V_1 * V_2 ,
struct V_56 * V_57 )
{
struct V_58 * V_28 = V_2 -> V_28 ;
F_28 ( V_57 , L_8 , & V_2 -> V_38 ) ;
if ( ! V_2 -> V_38 )
return 0 ;
V_2 -> V_39 = F_29 ( V_28 , L_9 ) ;
if ( F_30 ( V_2 -> V_39 ) ) {
F_5 ( V_28 , L_10 ) ;
return F_31 ( V_2 -> V_39 ) ;
}
V_2 -> V_41 = F_29 ( V_28 , L_11 ) ;
if ( F_30 ( V_2 -> V_41 ) ) {
F_5 ( V_28 , L_12 ) ;
return F_31 ( V_2 -> V_41 ) ;
}
V_2 -> V_46 = F_32 ( V_57 ,
L_13 ) ;
if ( F_30 ( V_2 -> V_46 ) ) {
F_5 ( V_28 , L_14 ) ;
return F_31 ( V_2 -> V_46 ) ;
}
return 0 ;
}
static int F_33 ( struct V_1 * V_2 )
{
int V_9 ;
int V_8 ;
for ( V_9 = 0 ; V_9 < V_2 -> V_59 ; V_9 ++ ) {
V_8 = F_34 ( V_2 -> V_60 [ V_9 ] ) ;
if ( V_8 )
goto V_61;
}
return 0 ;
V_61:
for (; V_9 > 0 ; V_9 -- )
F_35 ( V_2 -> V_60 [ V_9 - 1 ] ) ;
return V_8 ;
}
static int F_36 ( struct V_1 * V_2 )
{
int V_9 ;
for ( V_9 = 0 ; V_9 < V_2 -> V_59 ; V_9 ++ )
F_35 ( V_2 -> V_60 [ V_9 ] ) ;
return 0 ;
}
static int F_37 ( struct V_1 * V_2 )
{
int V_9 ;
int V_8 ;
for ( V_9 = 0 ; V_9 < V_2 -> V_59 ; V_9 ++ ) {
V_8 = F_38 ( V_2 -> V_60 [ V_9 ] ) ;
if ( V_8 )
goto V_62;
}
return 0 ;
V_62:
for (; V_9 > 0 ; V_9 -- )
F_39 ( V_2 -> V_60 [ V_9 - 1 ] ) ;
return V_8 ;
}
static void F_40 ( struct V_1 * V_2 )
{
unsigned int V_9 ;
for ( V_9 = 0 ; V_9 < V_2 -> V_59 ; V_9 ++ )
F_39 ( V_2 -> V_60 [ V_9 ] ) ;
}
static int F_41 ( struct V_1 * V_2 )
{
int V_8 ;
V_8 = F_42 ( V_2 -> V_63 ) ;
if ( V_8 ) {
F_5 ( V_2 -> V_28 , L_15 ) ;
return V_8 ;
}
V_8 = F_42 ( V_2 -> V_64 ) ;
if ( V_8 ) {
F_5 ( V_2 -> V_28 , L_16 ) ;
F_43 ( V_2 -> V_63 ) ;
return V_8 ;
}
return 0 ;
}
static void F_44 ( struct V_1 * V_2 )
{
F_43 ( V_2 -> V_63 ) ;
F_43 ( V_2 -> V_64 ) ;
}
static void F_45 ( struct V_58 * V_28 , struct V_65 * V_66 )
{
struct V_67 * V_68 = F_46 ( V_66 ) ;
struct V_1 * V_2 = F_47 ( V_68 ) ;
V_66 -> V_69 |= V_70 ;
V_66 -> V_69 |= V_71 ;
V_66 -> V_69 |= V_72 ;
if ( V_2 -> V_73 )
V_66 -> V_69 |= V_74 ;
}
static int F_48 ( struct V_67 * V_68 )
{
struct V_65 * V_66 = F_49 ( V_68 ) ;
struct V_1 * V_2 = F_47 ( V_68 ) ;
int V_8 ;
if ( F_50 ( V_68 ) ) {
V_8 = F_7 ( V_2 ) ;
if ( V_8 )
return V_8 ;
}
V_8 = F_51 ( V_68 , F_45 ) ;
if ( V_8 )
return V_8 ;
if ( F_50 ( V_68 ) ) {
V_2 -> V_13 = V_66 -> V_75 ;
V_2 -> V_18 = V_66 -> V_76 ;
V_8 = F_52 ( V_2 ) ;
if ( V_8 )
return V_8 ;
}
return V_8 ;
}
static int F_53 ( struct V_77 * V_78 )
{
struct V_58 * V_28 = & V_78 -> V_28 ;
struct V_56 * V_79 = V_28 -> V_80 ;
struct V_1 * V_2 ;
const struct V_81 * V_82 ;
struct V_65 * V_66 ;
struct V_83 * V_84 ;
struct V_67 * V_68 ;
struct V_85 * V_85 ;
int V_86 ;
int V_8 = - V_87 ;
int V_88 ;
if ( F_54 () )
return - V_87 ;
V_82 = & V_89 ;
V_2 = F_55 ( V_28 , sizeof( * V_2 ) , V_90 ) ;
if ( ! V_2 )
return - V_91 ;
V_2 -> V_28 = V_28 ;
V_2 -> V_63 = F_56 ( V_28 , L_17 ) ;
if ( F_30 ( V_2 -> V_63 ) ) {
F_5 ( V_28 , L_18 ) ;
return F_31 ( V_2 -> V_63 ) ;
}
V_2 -> V_64 = F_56 ( V_28 , L_19 ) ;
if ( F_30 ( V_2 -> V_64 ) ) {
F_5 ( V_28 , L_20 ) ;
return F_31 ( V_2 -> V_64 ) ;
}
V_2 -> V_36 = F_29 ( V_28 , L_21 ) ;
if ( F_30 ( V_2 -> V_36 ) ) {
F_5 ( V_28 , L_22 ) ;
return F_31 ( V_2 -> V_36 ) ;
}
V_2 -> V_73 = F_57 ( V_79 , L_23 ) ;
V_8 = F_27 ( V_2 , V_79 ) ;
if ( V_8 )
return V_8 ;
V_2 -> V_59 = F_58 ( V_79 ,
L_24 , L_25 ) ;
if ( V_2 -> V_59 > 0 ) {
V_2 -> V_60 = F_59 ( V_28 , V_2 -> V_59 ,
sizeof( * V_2 -> V_60 ) , V_90 ) ;
if ( ! V_2 -> V_60 )
return - V_91 ;
} else {
V_2 -> V_59 = 0 ;
}
F_60 ( V_28 ) ;
F_61 ( V_28 ) ;
F_62 ( V_28 ) ;
V_8 = F_41 ( V_2 ) ;
if ( V_8 )
goto V_92;
V_8 = F_12 ( V_2 ) ;
if ( V_8 )
goto V_93;
V_88 = F_63 ( V_78 , 0 ) ;
if ( V_88 < 0 ) {
V_8 = V_88 ;
goto V_94;
}
V_8 = F_64 ( V_28 , F_65 ( 32 ) ) ;
if ( V_8 )
goto V_94;
if ( ! V_28 -> V_95 )
V_28 -> V_95 = & V_28 -> V_96 ;
else
F_66 ( V_28 , F_65 ( 32 ) ) ;
V_68 = F_67 ( V_82 , V_28 , F_68 ( V_28 ) ) ;
if ( ! V_68 ) {
V_8 = - V_91 ;
goto V_94;
}
V_2 -> V_68 = F_69 ( V_78 ) ;
F_70 ( V_78 , V_2 ) ;
V_84 = F_71 ( V_78 , V_97 , L_26 ) ;
V_68 -> V_98 = F_72 ( V_28 , V_84 ) ;
if ( F_30 ( V_68 -> V_98 ) ) {
V_8 = F_31 ( V_68 -> V_98 ) ;
goto V_99;
}
V_68 -> V_100 = V_84 -> V_101 ;
V_68 -> V_102 = F_73 ( V_84 ) ;
V_84 = F_71 ( V_78 , V_97 , L_27 ) ;
if ( V_84 ) {
V_2 -> V_5 = F_72 ( V_28 , V_84 ) ;
if ( F_30 ( V_2 -> V_5 ) ) {
V_8 = F_31 ( V_2 -> V_5 ) ;
goto V_99;
}
V_2 -> V_10 = true ;
} else {
V_2 -> V_10 = false ;
}
for ( V_86 = 0 ; V_86 < V_2 -> V_59 ; V_86 ++ ) {
V_85 = F_74 ( V_28 , V_79 , V_86 ) ;
if ( F_30 ( V_85 ) ) {
V_8 = F_31 ( V_85 ) ;
goto V_99;
}
V_2 -> V_60 [ V_86 ] = V_85 ;
}
V_8 = F_33 ( V_2 ) ;
if ( V_8 )
goto V_99;
V_8 = F_37 ( V_2 ) ;
if ( V_8 )
goto V_103;
F_75 ( V_28 , true ) ;
V_66 = F_49 ( V_68 ) ;
V_66 -> V_104 = V_68 ;
V_66 -> V_105 = F_76 ( V_82 , V_28 ,
F_68 ( V_28 ) , V_68 ) ;
if ( ! V_66 -> V_105 ) {
V_8 = - V_91 ;
goto V_106;
}
if ( F_77 ( V_66 -> V_107 ) >= 4 )
V_66 -> V_105 -> V_108 = 1 ;
V_8 = F_78 ( V_68 , V_88 , V_109 ) ;
if ( V_8 )
goto V_110;
V_8 = F_78 ( V_66 -> V_105 , V_88 , V_109 ) ;
if ( V_8 )
goto V_111;
return 0 ;
V_111:
F_79 ( V_68 ) ;
V_110:
F_80 ( V_2 ) ;
F_81 ( V_66 -> V_105 ) ;
V_106:
F_40 ( V_2 ) ;
F_75 ( V_28 , false ) ;
V_103:
F_36 ( V_2 ) ;
V_99:
F_81 ( V_68 ) ;
V_94:
F_15 ( V_2 ) ;
V_93:
F_44 ( V_2 ) ;
V_92:
F_82 ( V_28 ) ;
F_83 ( V_28 ) ;
return V_8 ;
}
static int F_84 ( struct V_77 * V_28 )
{
struct V_1 * V_2 = F_69 ( V_28 ) ;
struct V_67 * V_68 = V_2 -> V_68 ;
struct V_65 * V_66 = F_49 ( V_68 ) ;
F_79 ( V_66 -> V_105 ) ;
F_40 ( V_2 ) ;
F_36 ( V_2 ) ;
F_75 ( & V_28 -> V_28 , false ) ;
F_79 ( V_68 ) ;
F_81 ( V_66 -> V_105 ) ;
F_81 ( V_68 ) ;
F_80 ( V_2 ) ;
F_15 ( V_2 ) ;
F_44 ( V_2 ) ;
F_82 ( & V_28 -> V_28 ) ;
F_83 ( & V_28 -> V_28 ) ;
return 0 ;
}
static int T_3 F_85 ( struct V_58 * V_28 )
{
struct V_1 * V_2 = F_86 ( V_28 ) ;
struct V_67 * V_68 = V_2 -> V_68 ;
struct V_65 * V_66 = F_49 ( V_68 ) ;
F_87 ( V_66 , L_28 , V_35 ) ;
F_88 ( V_112 , & V_68 -> V_113 ) ;
F_89 ( & V_68 -> V_114 ) ;
F_88 ( V_112 , & V_66 -> V_105 -> V_113 ) ;
F_89 ( & V_66 -> V_105 -> V_114 ) ;
F_6 ( V_2 ) ;
F_40 ( V_2 ) ;
F_15 ( V_2 ) ;
F_25 ( V_2 ) ;
return 0 ;
}
static int T_3 F_90 ( struct V_58 * V_28 )
{
struct V_1 * V_2 = F_86 ( V_28 ) ;
struct V_67 * V_68 = V_2 -> V_68 ;
struct V_65 * V_66 = F_49 ( V_68 ) ;
F_26 ( V_2 ) ;
F_12 ( V_2 ) ;
F_37 ( V_2 ) ;
F_1 ( V_2 ) ;
F_87 ( V_66 , L_29 , V_35 ) ;
F_91 ( V_112 , & V_68 -> V_113 ) ;
F_92 ( V_68 ) ;
F_91 ( V_112 , & V_66 -> V_105 -> V_113 ) ;
F_92 ( V_66 -> V_105 ) ;
return 0 ;
}
static int T_4 F_93 ( void )
{
F_94 ( & V_89 , & V_115 ) ;
return F_95 ( & V_116 ) ;
}
static void T_5 F_96 ( void )
{
F_97 ( & V_116 ) ;
}
