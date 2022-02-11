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
struct V_15 * V_16 = F_16 ( V_3 -> V_3 . V_4 ) ;
if ( V_16 -> V_17 )
return - V_18 ;
return F_14 ( V_3 ) ;
}
static int F_17 ( struct V_1 * V_3 )
{
struct V_5 * V_5 = F_10 ( V_3 -> V_3 . V_4 ) ;
unsigned long V_6 ;
T_1 V_9 ;
F_4 ( & V_5 -> V_7 , V_6 ) ;
V_9 = F_11 ( V_5 -> V_8 + V_11 ) ;
V_9 &= ~ V_19 ;
V_9 |= V_20 ;
F_12 ( V_9 , V_5 -> V_8 + V_11 ) ;
F_8 ( & V_5 -> V_7 , V_6 ) ;
return 0 ;
}
static int F_18 ( struct V_1 * V_3 )
{
struct V_5 * V_5 = F_10 ( V_3 -> V_3 . V_4 ) ;
unsigned long V_6 ;
T_1 V_9 ;
F_4 ( & V_5 -> V_7 , V_6 ) ;
V_9 = F_11 ( V_5 -> V_8 + V_11 ) ;
V_9 &= ~ V_19 ;
V_9 |= V_21 ;
F_12 ( V_9 , V_5 -> V_8 + V_11 ) ;
F_8 ( & V_5 -> V_7 , V_6 ) ;
return 0 ;
}
int F_19 ( struct V_1 * V_22 , bool V_23 )
{
struct V_1 * V_3 = F_2 ( V_22 -> V_3 . V_4 ) ;
struct V_5 * V_5 = F_3 ( V_3 ) ;
T_2 V_10 ;
unsigned long V_6 ;
F_4 ( & V_5 -> V_7 , V_6 ) ;
V_10 = F_20 ( V_5 -> V_8 + V_13 ) ;
if ( V_23 )
V_10 |= V_24 ;
else
V_10 &= ~ V_24 ;
F_21 ( V_10 , V_5 -> V_8 + V_13 ) ;
F_8 ( & V_5 -> V_7 , V_6 ) ;
return 0 ;
}
int F_22 ( struct V_1 * V_22 ,
const struct V_25 * V_26 ) {
struct V_1 * V_3 = F_2 ( V_22 -> V_3 . V_4 ) ;
struct V_5 * V_5 = F_3 ( V_3 ) ;
unsigned long V_6 ;
F_4 ( & V_5 -> V_7 , V_6 ) ;
F_23 ( V_26 -> V_27 , V_5 -> V_8 + V_28 + 0 ) ;
F_23 ( V_26 -> V_27 >> 16 , V_5 -> V_8 + V_28 + 2 ) ;
F_8 ( & V_5 -> V_7 , V_6 ) ;
return 0 ;
}
static int F_24 ( struct V_1 * V_29 )
{
struct V_1 * V_3 = F_2 ( V_29 -> V_3 . V_4 ) ;
struct V_5 * V_5 = F_3 ( V_3 ) ;
F_25 ( V_5 -> V_8 + 0x200 , 0 ,
V_30 [ 0 ] . V_31 & 0xfffe ) ;
return 0 ;
}
static int F_26 ( struct V_1 * V_29 )
{
struct V_1 * V_3 = F_2 ( V_29 -> V_3 . V_4 ) ;
struct V_5 * V_5 = F_3 ( V_3 ) ;
F_27 ( V_5 -> V_8 + 0x200 , 0 ,
V_30 [ 0 ] . V_31 & 0xfffe ) ;
return 0 ;
}
static void F_28 ( struct V_1 * V_29 , int V_32 )
{
struct V_1 * V_3 = F_2 ( V_29 -> V_3 . V_4 ) ;
struct V_5 * V_5 = F_3 ( V_3 ) ;
F_29 ( V_5 -> V_8 + 0x200 , 0 , V_32 ) ;
}
static void F_30 ( struct V_1 * V_29 , int V_32 )
{
struct V_1 * V_3 = F_2 ( V_29 -> V_3 . V_4 ) ;
struct V_5 * V_5 = F_3 ( V_3 ) ;
F_31 ( V_5 -> V_8 + 0x200 , 0 , V_32 ) ;
}
static int F_32 ( struct V_33 * V_34 ,
unsigned V_35 )
{
struct V_5 * V_5 = F_33 ( V_34 , struct V_5 , V_36 ) ;
return ! ! ( F_13 ( V_5 -> V_8 + F_34 ( V_35 / 8 ) )
& F_35 ( V_35 ) ) ;
}
static void F_36 ( struct V_33 * V_34 ,
unsigned V_35 , int V_37 )
{
struct V_5 * V_5 = F_33 ( V_34 , struct V_5 , V_36 ) ;
T_2 V_38 ;
V_38 = F_13 ( V_5 -> V_8 + F_34 ( V_35 / 8 ) ) ;
if ( V_37 )
V_38 |= F_35 ( V_35 ) ;
else
V_38 &= ~ F_35 ( V_35 ) ;
F_6 ( V_38 , V_5 -> V_8 + F_34 ( V_35 / 8 ) ) ;
}
static void F_37 ( struct V_33 * V_34 ,
unsigned V_35 , int V_37 )
{
struct V_5 * V_5 = F_33 ( V_34 , struct V_5 , V_36 ) ;
unsigned long V_6 ;
F_4 ( & V_5 -> V_7 , V_6 ) ;
F_36 ( V_34 , V_35 , V_37 ) ;
F_8 ( & V_5 -> V_7 , V_6 ) ;
}
static int F_38 ( struct V_33 * V_34 ,
unsigned V_35 )
{
struct V_5 * V_5 = F_33 ( V_34 , struct V_5 , V_36 ) ;
unsigned long V_6 ;
T_2 V_39 ;
F_4 ( & V_5 -> V_7 , V_6 ) ;
V_39 = F_13 ( V_5 -> V_8 + F_39 ( V_35 / 8 ) ) ;
V_39 &= ~ F_35 ( V_35 ) ;
F_6 ( V_39 , V_5 -> V_8 + F_39 ( V_35 / 8 ) ) ;
F_8 ( & V_5 -> V_7 , V_6 ) ;
return 0 ;
}
static int F_40 ( struct V_33 * V_34 ,
unsigned V_35 , int V_37 )
{
struct V_5 * V_5 = F_33 ( V_34 , struct V_5 , V_36 ) ;
unsigned long V_6 ;
T_2 V_39 ;
F_4 ( & V_5 -> V_7 , V_6 ) ;
F_36 ( V_34 , V_35 , V_37 ) ;
V_39 = F_13 ( V_5 -> V_8 + F_39 ( V_35 / 8 ) ) ;
V_39 |= F_35 ( V_35 ) ;
F_6 ( V_39 , V_5 -> V_8 + F_39 ( V_35 / 8 ) ) ;
F_8 ( & V_5 -> V_7 , V_6 ) ;
return 0 ;
}
static int F_41 ( struct V_5 * V_5 , int V_40 )
{
V_5 -> V_36 . V_41 = L_2 ;
V_5 -> V_36 . V_42 = V_40 ;
V_5 -> V_36 . V_43 = 16 ;
V_5 -> V_36 . V_44 = F_37 ;
V_5 -> V_36 . V_45 = F_32 ;
V_5 -> V_36 . V_46 = F_38 ;
V_5 -> V_36 . V_47 = F_40 ;
return F_42 ( & V_5 -> V_36 ) ;
}
static void F_43 ( struct V_48 * V_49 )
{
struct V_5 * V_5 = F_44 ( V_49 ) ;
unsigned int V_50 ;
unsigned int V_51 , V_52 ;
V_52 = V_5 -> V_52 ;
while ( ( V_50 = F_13 ( V_5 -> V_8 + V_53 ) &
~ F_13 ( V_5 -> V_8 + V_54 ) ) )
for ( V_51 = 0 ; V_51 < V_55 ; V_51 ++ ) {
if ( V_50 & ( 1 << V_51 ) )
F_45 ( V_52 + V_51 ) ;
}
}
static void F_46 ( struct V_56 * V_57 )
{
}
static void F_47 ( struct V_56 * V_57 )
{
struct V_5 * V_5 = F_48 ( V_57 ) ;
unsigned long V_6 ;
T_2 V_58 ;
F_4 ( & V_5 -> V_7 , V_6 ) ;
V_58 = F_13 ( V_5 -> V_8 + V_54 ) ;
V_58 |= 1 << ( V_57 -> V_59 - V_5 -> V_52 ) ;
F_6 ( V_58 , V_5 -> V_8 + V_54 ) ;
F_8 ( & V_5 -> V_7 , V_6 ) ;
}
static void F_49 ( struct V_56 * V_57 )
{
struct V_5 * V_5 = F_48 ( V_57 ) ;
unsigned long V_6 ;
T_2 V_58 ;
F_4 ( & V_5 -> V_7 , V_6 ) ;
V_58 = F_13 ( V_5 -> V_8 + V_54 ) ;
V_58 &= ~ ( 1 << ( V_57 -> V_59 - V_5 -> V_52 ) ) ;
F_6 ( V_58 , V_5 -> V_8 + V_54 ) ;
F_8 ( & V_5 -> V_7 , V_6 ) ;
}
static void F_50 ( struct V_1 * V_3 )
{
struct V_5 * V_5 = F_3 ( V_3 ) ;
unsigned int V_59 , V_52 ;
V_52 = V_5 -> V_52 ;
for ( V_59 = V_52 ; V_59 < V_52 + V_55 ; V_59 ++ ) {
F_51 ( V_59 , & V_60 , V_61 ) ;
F_52 ( V_59 , V_5 ) ;
F_53 ( V_59 , V_62 | V_63 ) ;
}
F_54 ( V_5 -> V_59 , V_64 ) ;
F_55 ( V_5 -> V_59 , F_43 ,
V_5 ) ;
}
static void F_56 ( struct V_1 * V_3 )
{
struct V_5 * V_5 = F_3 ( V_3 ) ;
unsigned int V_59 , V_52 ;
F_55 ( V_5 -> V_59 , NULL , NULL ) ;
V_52 = V_5 -> V_52 ;
for ( V_59 = V_52 ; V_59 < V_52 + V_55 ; V_59 ++ ) {
F_57 ( V_59 , V_62 | V_63 ) ;
F_58 ( V_59 , NULL ) ;
F_52 ( V_59 , NULL ) ;
}
}
static int F_59 ( struct V_1 * V_3 )
{
struct V_15 * V_16 = F_16 ( & V_3 -> V_3 ) ;
struct V_5 * V_5 ;
struct V_65 * V_66 , * V_67 ;
int V_68 ;
V_66 = F_60 ( V_3 , V_69 , 0 ) ;
if ( ! V_66 )
return - V_70 ;
V_5 = F_61 ( sizeof *V_5 , V_71 ) ;
if ( ! V_5 ) {
V_68 = - V_72 ;
goto V_73;
}
F_62 ( & V_5 -> V_7 ) ;
F_63 ( V_3 , V_5 ) ;
V_68 = F_64 ( V_3 , 0 ) ;
if ( V_68 >= 0 )
V_5 -> V_59 = V_68 ;
else
goto V_74;
V_5 -> V_66 = V_66 ;
V_5 -> V_52 = V_16 -> V_52 ;
V_5 -> V_75 = F_65 ( & V_3 -> V_3 , L_3 ) ;
if ( F_66 ( V_5 -> V_75 ) ) {
V_68 = F_67 ( V_5 -> V_75 ) ;
goto V_76;
}
V_67 = & V_5 -> V_67 ;
V_67 -> V_77 = L_4 ;
V_67 -> V_31 = V_66 -> V_31 ;
V_67 -> V_78 = V_66 -> V_31 + 0xff ;
V_67 -> V_6 = V_69 ;
V_68 = F_68 ( V_66 , V_67 ) ;
if ( V_68 )
goto V_79;
V_5 -> V_8 = F_69 ( V_67 -> V_31 , F_70 ( V_67 ) ) ;
if ( ! V_5 -> V_8 ) {
V_68 = - V_72 ;
goto V_80;
}
V_68 = F_71 ( V_5 -> V_75 ) ;
if ( V_68 )
goto V_81;
V_68 = V_16 -> V_82 ( V_3 ) ;
if ( V_68 )
goto V_83;
F_21 ( 0 , V_5 -> V_8 + V_13 ) ;
F_23 ( V_16 -> V_84 , V_5 -> V_8 + V_85 ) ;
F_23 ( V_86 | V_87 ,
V_5 -> V_8 + V_11 ) ;
F_23 ( V_88 | V_89 | V_90 |
V_91 | V_92 | V_93 |
F_72 ( 15 ) , V_5 -> V_8 + V_94 ) ;
F_23 ( V_16 -> V_95 , V_5 -> V_8 + V_96 ) ;
F_21 ( 0 , V_5 -> V_8 + V_97 ) ;
F_21 ( 0xbf , V_5 -> V_8 + V_54 ) ;
F_73 ( V_98 L_5 ,
F_13 ( V_5 -> V_8 + V_99 ) ,
( unsigned long ) V_66 -> V_31 , V_5 -> V_59 ) ;
V_5 -> V_36 . V_42 = - 1 ;
if ( V_16 -> V_40 >= 0 ) {
V_68 = F_41 ( V_5 , V_16 -> V_40 ) ;
if ( V_68 )
goto V_100;
}
F_50 ( V_3 ) ;
if ( V_16 -> V_101 ) {
V_68 = V_16 -> V_101 ( V_3 ) ;
if ( V_68 )
goto V_102;
}
V_103 [ V_104 ] . V_105 = V_16 -> V_106 ;
V_103 [ V_104 ] . V_107 =
sizeof( * V_16 -> V_106 ) ;
V_103 [ V_108 ] . V_105 = V_16 -> V_109 ;
V_103 [ V_108 ] . V_107 = sizeof( * V_16 -> V_109 ) ;
V_68 = F_74 ( & V_3 -> V_3 , V_3 -> V_110 ,
V_103 , F_75 ( V_103 ) ,
V_66 , V_16 -> V_52 , NULL ) ;
if ( ! V_68 )
return 0 ;
if ( V_16 -> V_111 )
V_16 -> V_111 ( V_3 ) ;
V_102:
F_56 ( V_3 ) ;
V_100:
if ( V_5 -> V_36 . V_42 != - 1 )
F_76 ( & V_5 -> V_36 ) ;
V_16 -> V_112 ( V_3 ) ;
V_83:
F_77 ( V_5 -> V_75 ) ;
V_81:
F_78 ( V_5 -> V_8 ) ;
V_80:
F_79 ( & V_5 -> V_67 ) ;
V_79:
F_80 ( V_5 -> V_75 ) ;
V_74:
V_76:
F_81 ( V_5 ) ;
V_73:
return V_68 ;
}
static int F_82 ( struct V_1 * V_3 )
{
struct V_15 * V_16 = F_16 ( & V_3 -> V_3 ) ;
struct V_5 * V_5 = F_3 ( V_3 ) ;
int V_68 ;
F_83 ( & V_3 -> V_3 ) ;
if ( V_16 -> V_111 )
V_16 -> V_111 ( V_3 ) ;
F_56 ( V_3 ) ;
if ( V_5 -> V_36 . V_42 != - 1 )
F_76 ( & V_5 -> V_36 ) ;
V_68 = V_16 -> V_112 ( V_3 ) ;
F_77 ( V_5 -> V_75 ) ;
F_78 ( V_5 -> V_8 ) ;
F_79 ( & V_5 -> V_67 ) ;
F_80 ( V_5 -> V_75 ) ;
F_81 ( V_5 ) ;
return V_68 ;
}
static int F_84 ( struct V_1 * V_3 , T_3 V_32 )
{
struct V_15 * V_16 = F_16 ( & V_3 -> V_3 ) ;
struct V_5 * V_5 = F_3 ( V_3 ) ;
int V_51 , V_68 ;
V_5 -> V_113 . V_9 = F_85 ( V_5 -> V_8 + V_11 ) ;
V_5 -> V_113 . V_10 = F_20 ( V_5 -> V_8 + V_13 ) ;
for ( V_51 = 0 ; V_51 < 3 ; V_51 ++ ) {
V_5 -> V_113 . V_114 [ V_51 ] =
F_20 ( V_5 -> V_8 + F_34 ( V_51 ) ) ;
V_5 -> V_113 . V_115 [ V_51 ] =
F_20 ( V_5 -> V_8 + F_39 ( V_51 ) ) ;
V_5 -> V_113 . V_116 [ V_51 ] =
F_20 ( V_5 -> V_8 + F_7 ( V_51 ) ) ;
}
V_68 = V_16 -> V_117 ( V_3 ) ;
F_77 ( V_5 -> V_75 ) ;
return V_68 ;
}
static int F_86 ( struct V_1 * V_3 )
{
struct V_15 * V_16 = F_16 ( & V_3 -> V_3 ) ;
struct V_5 * V_5 = F_3 ( V_3 ) ;
int V_68 ;
int V_51 ;
F_71 ( V_5 -> V_75 ) ;
V_68 = V_16 -> V_118 ( V_3 ) ;
if ( V_68 )
return V_68 ;
if ( ! V_16 -> V_17 )
return 0 ;
F_21 ( V_5 -> V_113 . V_10 , V_5 -> V_8 + V_13 ) ;
F_23 ( V_16 -> V_84 , V_5 -> V_8 + V_85 ) ;
F_23 ( V_5 -> V_113 . V_9 , V_5 -> V_8 + V_11 ) ;
F_23 ( V_88 | V_89 | V_90 |
V_91 | V_92 | V_93 |
F_72 ( 15 ) , V_5 -> V_8 + V_94 ) ;
F_23 ( V_16 -> V_95 , V_5 -> V_8 + V_96 ) ;
F_21 ( 0 , V_5 -> V_8 + V_97 ) ;
F_21 ( 0xbf , V_5 -> V_8 + V_54 ) ;
for ( V_51 = 0 ; V_51 < 3 ; V_51 ++ ) {
F_21 ( V_5 -> V_113 . V_114 [ V_51 ] ,
V_5 -> V_8 + F_34 ( V_51 ) ) ;
F_21 ( V_5 -> V_113 . V_115 [ V_51 ] ,
V_5 -> V_8 + F_39 ( V_51 ) ) ;
F_21 ( V_5 -> V_113 . V_116 [ V_51 ] ,
V_5 -> V_8 + F_7 ( V_51 ) ) ;
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
