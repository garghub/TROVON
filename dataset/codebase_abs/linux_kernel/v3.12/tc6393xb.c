static int F_1 ( struct V_1 * V_2 )
{
struct V_1 * V_3 = F_2 ( V_2 -> V_3 . V_4 ) ;
struct V_5 * V_5 = F_3 ( V_3 ) ;
unsigned long V_6 ;
F_4 ( & V_5 -> V_7 , V_6 ) ;
F_5 ( & V_3 -> V_3 , L_1 ) ;
F_6 ( 0xff , V_5 -> V_8 + F_7 ( 1 ) ) ;
F_8 ( & V_5 -> V_7 , V_6 ) ;
return 0 ;
}
static int F_9 ( struct V_1 * V_3 )
{
struct V_5 * V_5 = F_10 ( V_3 -> V_3 . V_4 ) ;
unsigned long V_6 ;
T_1 V_9 ;
T_2 V_10 ;
F_4 ( & V_5 -> V_7 , V_6 ) ;
V_9 = F_11 ( V_5 -> V_8 + V_11 ) ;
V_9 |= V_12 ;
F_12 ( V_9 , V_5 -> V_8 + V_11 ) ;
V_10 = F_13 ( V_5 -> V_8 + V_13 ) ;
V_10 |= V_14 ;
F_6 ( V_10 , V_5 -> V_8 + V_13 ) ;
F_8 ( & V_5 -> V_7 , V_6 ) ;
return 0 ;
}
static int F_14 ( struct V_1 * V_3 )
{
struct V_5 * V_5 = F_10 ( V_3 -> V_3 . V_4 ) ;
unsigned long V_6 ;
T_1 V_9 ;
T_2 V_10 ;
F_4 ( & V_5 -> V_7 , V_6 ) ;
V_10 = F_13 ( V_5 -> V_8 + V_13 ) ;
V_10 &= ~ V_14 ;
F_6 ( V_10 , V_5 -> V_8 + V_13 ) ;
V_9 = F_11 ( V_5 -> V_8 + V_11 ) ;
V_9 &= ~ V_12 ;
F_12 ( V_9 , V_5 -> V_8 + V_11 ) ;
F_8 ( & V_5 -> V_7 , V_6 ) ;
return 0 ;
}
static int F_15 ( struct V_1 * V_3 )
{
struct V_5 * V_5 = F_10 ( V_3 -> V_3 . V_4 ) ;
unsigned long V_6 ;
T_1 V_9 ;
F_4 ( & V_5 -> V_7 , V_6 ) ;
V_9 = F_11 ( V_5 -> V_8 + V_11 ) ;
V_9 &= ~ V_15 ;
V_9 |= V_16 ;
F_12 ( V_9 , V_5 -> V_8 + V_11 ) ;
F_8 ( & V_5 -> V_7 , V_6 ) ;
return 0 ;
}
static int F_16 ( struct V_1 * V_3 )
{
struct V_5 * V_5 = F_10 ( V_3 -> V_3 . V_4 ) ;
unsigned long V_6 ;
T_1 V_9 ;
F_4 ( & V_5 -> V_7 , V_6 ) ;
V_9 = F_11 ( V_5 -> V_8 + V_11 ) ;
V_9 &= ~ V_15 ;
V_9 |= V_17 ;
F_12 ( V_9 , V_5 -> V_8 + V_11 ) ;
F_8 ( & V_5 -> V_7 , V_6 ) ;
return 0 ;
}
int F_17 ( struct V_1 * V_18 , bool V_19 )
{
struct V_1 * V_3 = F_2 ( V_18 -> V_3 . V_4 ) ;
struct V_5 * V_5 = F_3 ( V_3 ) ;
T_2 V_10 ;
unsigned long V_6 ;
F_4 ( & V_5 -> V_7 , V_6 ) ;
V_10 = F_18 ( V_5 -> V_8 + V_13 ) ;
if ( V_19 )
V_10 |= V_20 ;
else
V_10 &= ~ V_20 ;
F_19 ( V_10 , V_5 -> V_8 + V_13 ) ;
F_8 ( & V_5 -> V_7 , V_6 ) ;
return 0 ;
}
int F_20 ( struct V_1 * V_18 ,
const struct V_21 * V_22 ) {
struct V_1 * V_3 = F_2 ( V_18 -> V_3 . V_4 ) ;
struct V_5 * V_5 = F_3 ( V_3 ) ;
unsigned long V_6 ;
F_4 ( & V_5 -> V_7 , V_6 ) ;
F_21 ( V_22 -> V_23 , V_5 -> V_8 + V_24 + 0 ) ;
F_21 ( V_22 -> V_23 >> 16 , V_5 -> V_8 + V_24 + 2 ) ;
F_8 ( & V_5 -> V_7 , V_6 ) ;
return 0 ;
}
static int F_22 ( struct V_1 * V_25 )
{
struct V_1 * V_3 = F_2 ( V_25 -> V_3 . V_4 ) ;
struct V_5 * V_5 = F_3 ( V_3 ) ;
F_23 ( V_5 -> V_8 + 0x200 , 0 ,
V_26 [ 0 ] . V_27 & 0xfffe ) ;
return 0 ;
}
static int F_24 ( struct V_1 * V_25 )
{
struct V_1 * V_3 = F_2 ( V_25 -> V_3 . V_4 ) ;
struct V_5 * V_5 = F_3 ( V_3 ) ;
F_25 ( V_5 -> V_8 + 0x200 , 0 ,
V_26 [ 0 ] . V_27 & 0xfffe ) ;
return 0 ;
}
static void F_26 ( struct V_1 * V_25 , int V_28 )
{
struct V_1 * V_3 = F_2 ( V_25 -> V_3 . V_4 ) ;
struct V_5 * V_5 = F_3 ( V_3 ) ;
F_27 ( V_5 -> V_8 + 0x200 , 0 , V_28 ) ;
}
static void F_28 ( struct V_1 * V_25 , int V_28 )
{
struct V_1 * V_3 = F_2 ( V_25 -> V_3 . V_4 ) ;
struct V_5 * V_5 = F_3 ( V_3 ) ;
F_29 ( V_5 -> V_8 + 0x200 , 0 , V_28 ) ;
}
static int F_30 ( struct V_29 * V_30 ,
unsigned V_31 )
{
struct V_5 * V_5 = F_31 ( V_30 , struct V_5 , V_32 ) ;
return F_13 ( V_5 -> V_8 + F_32 ( V_31 / 8 ) )
& F_33 ( V_31 ) ;
}
static void F_34 ( struct V_29 * V_30 ,
unsigned V_31 , int V_33 )
{
struct V_5 * V_5 = F_31 ( V_30 , struct V_5 , V_32 ) ;
T_2 V_34 ;
V_34 = F_13 ( V_5 -> V_8 + F_32 ( V_31 / 8 ) ) ;
if ( V_33 )
V_34 |= F_33 ( V_31 ) ;
else
V_34 &= ~ F_33 ( V_31 ) ;
F_6 ( V_34 , V_5 -> V_8 + F_32 ( V_31 / 8 ) ) ;
}
static void F_35 ( struct V_29 * V_30 ,
unsigned V_31 , int V_33 )
{
struct V_5 * V_5 = F_31 ( V_30 , struct V_5 , V_32 ) ;
unsigned long V_6 ;
F_4 ( & V_5 -> V_7 , V_6 ) ;
F_34 ( V_30 , V_31 , V_33 ) ;
F_8 ( & V_5 -> V_7 , V_6 ) ;
}
static int F_36 ( struct V_29 * V_30 ,
unsigned V_31 )
{
struct V_5 * V_5 = F_31 ( V_30 , struct V_5 , V_32 ) ;
unsigned long V_6 ;
T_2 V_35 ;
F_4 ( & V_5 -> V_7 , V_6 ) ;
V_35 = F_13 ( V_5 -> V_8 + F_37 ( V_31 / 8 ) ) ;
V_35 &= ~ F_33 ( V_31 ) ;
F_6 ( V_35 , V_5 -> V_8 + F_37 ( V_31 / 8 ) ) ;
F_8 ( & V_5 -> V_7 , V_6 ) ;
return 0 ;
}
static int F_38 ( struct V_29 * V_30 ,
unsigned V_31 , int V_33 )
{
struct V_5 * V_5 = F_31 ( V_30 , struct V_5 , V_32 ) ;
unsigned long V_6 ;
T_2 V_35 ;
F_4 ( & V_5 -> V_7 , V_6 ) ;
F_34 ( V_30 , V_31 , V_33 ) ;
V_35 = F_13 ( V_5 -> V_8 + F_37 ( V_31 / 8 ) ) ;
V_35 |= F_33 ( V_31 ) ;
F_6 ( V_35 , V_5 -> V_8 + F_37 ( V_31 / 8 ) ) ;
F_8 ( & V_5 -> V_7 , V_6 ) ;
return 0 ;
}
static int F_39 ( struct V_5 * V_5 , int V_36 )
{
V_5 -> V_32 . V_37 = L_2 ;
V_5 -> V_32 . V_38 = V_36 ;
V_5 -> V_32 . V_39 = 16 ;
V_5 -> V_32 . V_40 = F_35 ;
V_5 -> V_32 . V_41 = F_30 ;
V_5 -> V_32 . V_42 = F_36 ;
V_5 -> V_32 . V_43 = F_38 ;
return F_40 ( & V_5 -> V_32 ) ;
}
static void
F_41 ( unsigned int V_44 , struct V_45 * V_46 )
{
struct V_5 * V_5 = F_42 ( V_44 ) ;
unsigned int V_47 ;
unsigned int V_48 , V_49 ;
V_49 = V_5 -> V_49 ;
while ( ( V_47 = F_13 ( V_5 -> V_8 + V_50 ) &
~ F_13 ( V_5 -> V_8 + V_51 ) ) )
for ( V_48 = 0 ; V_48 < V_52 ; V_48 ++ ) {
if ( V_47 & ( 1 << V_48 ) )
F_43 ( V_49 + V_48 ) ;
}
}
static void F_44 ( struct V_53 * V_54 )
{
}
static void F_45 ( struct V_53 * V_54 )
{
struct V_5 * V_5 = F_46 ( V_54 ) ;
unsigned long V_6 ;
T_2 V_55 ;
F_4 ( & V_5 -> V_7 , V_6 ) ;
V_55 = F_13 ( V_5 -> V_8 + V_51 ) ;
V_55 |= 1 << ( V_54 -> V_44 - V_5 -> V_49 ) ;
F_6 ( V_55 , V_5 -> V_8 + V_51 ) ;
F_8 ( & V_5 -> V_7 , V_6 ) ;
}
static void F_47 ( struct V_53 * V_54 )
{
struct V_5 * V_5 = F_46 ( V_54 ) ;
unsigned long V_6 ;
T_2 V_55 ;
F_4 ( & V_5 -> V_7 , V_6 ) ;
V_55 = F_13 ( V_5 -> V_8 + V_51 ) ;
V_55 &= ~ ( 1 << ( V_54 -> V_44 - V_5 -> V_49 ) ) ;
F_6 ( V_55 , V_5 -> V_8 + V_51 ) ;
F_8 ( & V_5 -> V_7 , V_6 ) ;
}
static void F_48 ( struct V_1 * V_3 )
{
struct V_5 * V_5 = F_3 ( V_3 ) ;
unsigned int V_44 , V_49 ;
V_49 = V_5 -> V_49 ;
for ( V_44 = V_49 ; V_44 < V_49 + V_52 ; V_44 ++ ) {
F_49 ( V_44 , & V_56 , V_57 ) ;
F_50 ( V_44 , V_5 ) ;
F_51 ( V_44 , V_58 | V_59 ) ;
}
F_52 ( V_5 -> V_44 , V_60 ) ;
F_53 ( V_5 -> V_44 , V_5 ) ;
F_54 ( V_5 -> V_44 , F_41 ) ;
}
static void F_55 ( struct V_1 * V_3 )
{
struct V_5 * V_5 = F_3 ( V_3 ) ;
unsigned int V_44 , V_49 ;
F_54 ( V_5 -> V_44 , NULL ) ;
F_53 ( V_5 -> V_44 , NULL ) ;
V_49 = V_5 -> V_49 ;
for ( V_44 = V_49 ; V_44 < V_49 + V_52 ; V_44 ++ ) {
F_51 ( V_44 , 0 ) ;
F_56 ( V_44 , NULL ) ;
F_50 ( V_44 , NULL ) ;
}
}
static int F_57 ( struct V_1 * V_3 )
{
struct V_61 * V_62 = F_58 ( & V_3 -> V_3 ) ;
struct V_5 * V_5 ;
struct V_63 * V_64 , * V_65 ;
int V_66 , V_67 ;
V_64 = F_59 ( V_3 , V_68 , 0 ) ;
if ( ! V_64 )
return - V_69 ;
V_5 = F_60 ( sizeof *V_5 , V_70 ) ;
if ( ! V_5 ) {
V_66 = - V_71 ;
goto V_72;
}
F_61 ( & V_5 -> V_7 ) ;
F_62 ( V_3 , V_5 ) ;
V_66 = F_63 ( V_3 , 0 ) ;
if ( V_66 >= 0 )
V_5 -> V_44 = V_66 ;
else
goto V_73;
V_5 -> V_64 = V_64 ;
V_5 -> V_49 = V_62 -> V_49 ;
V_5 -> V_74 = F_64 ( & V_3 -> V_3 , L_3 ) ;
if ( F_65 ( V_5 -> V_74 ) ) {
V_66 = F_66 ( V_5 -> V_74 ) ;
goto V_75;
}
V_65 = & V_5 -> V_65 ;
V_65 -> V_76 = L_4 ;
V_65 -> V_27 = V_64 -> V_27 ;
V_65 -> V_77 = V_64 -> V_27 + 0xff ;
V_65 -> V_6 = V_68 ;
V_66 = F_67 ( V_64 , V_65 ) ;
if ( V_66 )
goto V_78;
V_5 -> V_8 = F_68 ( V_65 -> V_27 , F_69 ( V_65 ) ) ;
if ( ! V_5 -> V_8 ) {
V_66 = - V_71 ;
goto V_79;
}
V_66 = F_70 ( V_5 -> V_74 ) ;
if ( V_66 )
goto V_80;
V_66 = V_62 -> V_81 ( V_3 ) ;
if ( V_66 )
goto V_82;
F_19 ( 0 , V_5 -> V_8 + V_13 ) ;
F_21 ( V_62 -> V_83 , V_5 -> V_8 + V_84 ) ;
F_21 ( V_85 | V_86 ,
V_5 -> V_8 + V_11 ) ;
F_21 ( V_87 | V_88 | V_89 |
V_90 | V_91 | V_92 |
F_71 ( 15 ) , V_5 -> V_8 + V_93 ) ;
F_21 ( V_62 -> V_94 , V_5 -> V_8 + V_95 ) ;
F_19 ( 0 , V_5 -> V_8 + V_96 ) ;
F_19 ( 0xbf , V_5 -> V_8 + V_51 ) ;
F_72 ( V_97 L_5 ,
F_13 ( V_5 -> V_8 + V_98 ) ,
( unsigned long ) V_64 -> V_27 , V_5 -> V_44 ) ;
V_5 -> V_32 . V_38 = - 1 ;
if ( V_62 -> V_36 >= 0 ) {
V_66 = F_39 ( V_5 , V_62 -> V_36 ) ;
if ( V_66 )
goto V_99;
}
F_48 ( V_3 ) ;
if ( V_62 -> V_100 ) {
V_66 = V_62 -> V_100 ( V_3 ) ;
if ( V_66 )
goto V_101;
}
V_102 [ V_103 ] . V_104 = V_62 -> V_105 ;
V_102 [ V_103 ] . V_106 =
sizeof( * V_62 -> V_105 ) ;
V_102 [ V_107 ] . V_104 = V_62 -> V_108 ;
V_102 [ V_107 ] . V_106 = sizeof( * V_62 -> V_108 ) ;
V_66 = F_73 ( & V_3 -> V_3 , V_3 -> V_109 ,
V_102 , F_74 ( V_102 ) ,
V_64 , V_62 -> V_49 , NULL ) ;
if ( ! V_66 )
return 0 ;
if ( V_62 -> V_110 )
V_62 -> V_110 ( V_3 ) ;
V_101:
F_55 ( V_3 ) ;
V_99:
if ( V_5 -> V_32 . V_38 != - 1 )
V_67 = F_75 ( & V_5 -> V_32 ) ;
V_62 -> V_111 ( V_3 ) ;
V_82:
F_76 ( V_5 -> V_74 ) ;
V_80:
F_77 ( V_5 -> V_8 ) ;
V_79:
F_78 ( & V_5 -> V_65 ) ;
V_78:
F_79 ( V_5 -> V_74 ) ;
V_73:
V_75:
F_80 ( V_5 ) ;
V_72:
return V_66 ;
}
static int F_81 ( struct V_1 * V_3 )
{
struct V_61 * V_62 = F_58 ( & V_3 -> V_3 ) ;
struct V_5 * V_5 = F_3 ( V_3 ) ;
int V_66 ;
F_82 ( & V_3 -> V_3 ) ;
if ( V_62 -> V_110 )
V_62 -> V_110 ( V_3 ) ;
F_55 ( V_3 ) ;
if ( V_5 -> V_32 . V_38 != - 1 ) {
V_66 = F_75 ( & V_5 -> V_32 ) ;
if ( V_66 ) {
F_83 ( & V_3 -> V_3 , L_6 , V_66 ) ;
return V_66 ;
}
}
V_66 = V_62 -> V_111 ( V_3 ) ;
F_76 ( V_5 -> V_74 ) ;
F_77 ( V_5 -> V_8 ) ;
F_78 ( & V_5 -> V_65 ) ;
F_79 ( V_5 -> V_74 ) ;
F_80 ( V_5 ) ;
return V_66 ;
}
static int F_84 ( struct V_1 * V_3 , T_3 V_28 )
{
struct V_61 * V_62 = F_58 ( & V_3 -> V_3 ) ;
struct V_5 * V_5 = F_3 ( V_3 ) ;
int V_48 , V_66 ;
V_5 -> V_112 . V_9 = F_85 ( V_5 -> V_8 + V_11 ) ;
V_5 -> V_112 . V_10 = F_18 ( V_5 -> V_8 + V_13 ) ;
for ( V_48 = 0 ; V_48 < 3 ; V_48 ++ ) {
V_5 -> V_112 . V_113 [ V_48 ] =
F_18 ( V_5 -> V_8 + F_32 ( V_48 ) ) ;
V_5 -> V_112 . V_114 [ V_48 ] =
F_18 ( V_5 -> V_8 + F_37 ( V_48 ) ) ;
V_5 -> V_112 . V_115 [ V_48 ] =
F_18 ( V_5 -> V_8 + F_7 ( V_48 ) ) ;
}
V_66 = V_62 -> V_116 ( V_3 ) ;
F_76 ( V_5 -> V_74 ) ;
return V_66 ;
}
static int F_86 ( struct V_1 * V_3 )
{
struct V_61 * V_62 = F_58 ( & V_3 -> V_3 ) ;
struct V_5 * V_5 = F_3 ( V_3 ) ;
int V_66 ;
int V_48 ;
F_70 ( V_5 -> V_74 ) ;
V_66 = V_62 -> V_117 ( V_3 ) ;
if ( V_66 )
return V_66 ;
if ( ! V_62 -> V_118 )
return 0 ;
F_19 ( V_5 -> V_112 . V_10 , V_5 -> V_8 + V_13 ) ;
F_21 ( V_62 -> V_83 , V_5 -> V_8 + V_84 ) ;
F_21 ( V_5 -> V_112 . V_9 , V_5 -> V_8 + V_11 ) ;
F_21 ( V_87 | V_88 | V_89 |
V_90 | V_91 | V_92 |
F_71 ( 15 ) , V_5 -> V_8 + V_93 ) ;
F_21 ( V_62 -> V_94 , V_5 -> V_8 + V_95 ) ;
F_19 ( 0 , V_5 -> V_8 + V_96 ) ;
F_19 ( 0xbf , V_5 -> V_8 + V_51 ) ;
for ( V_48 = 0 ; V_48 < 3 ; V_48 ++ ) {
F_19 ( V_5 -> V_112 . V_113 [ V_48 ] ,
V_5 -> V_8 + F_32 ( V_48 ) ) ;
F_19 ( V_5 -> V_112 . V_114 [ V_48 ] ,
V_5 -> V_8 + F_37 ( V_48 ) ) ;
F_19 ( V_5 -> V_112 . V_115 [ V_48 ] ,
V_5 -> V_8 + F_7 ( V_48 ) ) ;
}
return 0 ;
}
static int T_4 F_87 ( void )
{
return F_88 ( & V_119 ) ;
}
static void T_5 F_89 ( void )
{
F_90 ( & V_119 ) ;
}
