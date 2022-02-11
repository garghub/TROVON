static int F_1 ( void T_1 * V_1 , T_2 V_2 , bool assert )
{
int V_3 = 10 ;
T_2 V_4 ;
T_2 V_5 ;
V_4 = F_2 ( V_1 + V_6 ) ;
if ( assert )
V_4 |= V_2 ;
else
V_4 &= ~ V_2 ;
F_3 ( V_4 , V_1 + V_6 ) ;
do {
V_5 = F_2 ( V_1 + V_7 ) ;
if ( ( assert ? V_5 : ~ V_5 ) & V_8 )
break;
F_4 ( 100 , 200 ) ;
} while ( -- V_3 );
return V_3 ? 0 : - V_9 ;
}
static int F_5 ( T_3 V_10 , void T_1 * V_1 )
{
T_2 V_4 = V_10 ;
int V_11 ;
F_3 ( V_4 , V_1 + V_6 ) ;
V_11 = F_1 ( V_1 , V_12 , true ) ;
if ( V_11 )
return V_11 ;
V_11 = F_1 ( V_1 , V_12 , false ) ;
if ( V_11 )
return V_11 ;
return 0 ;
}
static int F_6 ( T_3 V_13 , void T_1 * V_1 )
{
T_2 V_4 = V_13 ;
int V_11 ;
F_3 ( V_4 , V_1 + V_6 ) ;
V_11 = F_1 ( V_1 , V_14 , true ) ;
if ( V_11 )
return V_11 ;
V_11 = F_1 ( V_1 , V_14 , false ) ;
if ( V_11 )
return V_11 ;
if ( V_13 & V_15 ) {
V_4 |= V_16 ;
F_3 ( V_4 , V_1 + V_6 ) ;
goto V_17;
}
V_11 = F_1 ( V_1 , V_16 , true ) ;
if ( V_11 )
return V_11 ;
V_11 = F_1 ( V_1 , V_16 , false ) ;
if ( V_11 )
return V_11 ;
V_17:
return 0 ;
}
static int F_7 ( T_3 * V_13 , void T_1 * V_1 )
{
int V_11 ;
V_11 = F_1 ( V_1 , V_18 , true ) ;
if ( V_11 )
return V_11 ;
* V_13 = F_2 ( V_1 + V_7 ) & V_19 ;
V_11 = F_1 ( V_1 , V_18 , false ) ;
if ( V_11 )
return V_11 ;
return 0 ;
}
static int F_8 ( struct V_20 * V_21 )
{
void T_1 * V_1 = V_21 -> V_1 ;
int V_3 = 10 ;
T_3 V_13 ;
int V_11 ;
V_11 = F_5 ( V_22 , V_1 ) ;
if ( V_11 )
return V_11 ;
V_11 = F_6 ( V_15 , V_1 ) ;
if ( V_11 )
return V_11 ;
do {
F_4 ( 100 , 200 ) ;
V_11 = F_5 ( V_23 , V_1 ) ;
if ( V_11 )
return V_11 ;
V_11 = F_7 ( & V_13 , V_1 ) ;
if ( V_11 )
return V_11 ;
if ( V_13 & V_24 )
break;
} while ( -- V_3 );
return V_3 ? 0 : - V_9 ;
}
static int F_9 ( void * V_25 , T_3 V_26 , void T_1 * V_1 )
{
T_3 V_27 , V_28 ;
T_2 V_29 , V_30 ;
const T_2 V_31 = 100 ;
F_5 ( V_32 , V_1 ) ;
F_6 ( V_26 , V_1 ) ;
V_29 = 0 ;
V_30 = 0 ;
V_27 = 0 ;
F_5 ( V_33 , V_1 ) ;
while ( V_29 < 2 ) {
F_7 ( & V_27 , V_1 ) ;
if ( V_27 & 0x400 )
V_29 ++ ;
V_30 ++ ;
if ( V_30 > V_31 ) {
F_10 ( V_25 , L_1 ,
V_31 ) ;
break;
}
}
V_29 = 0 ;
V_30 = 0 ;
V_28 = 0 ;
while ( V_29 < 80 ) {
F_7 ( & V_27 , V_1 ) ;
if ( V_27 & 0x400 ) {
V_28 = V_28 + ( V_27 & 0x3FF ) ;
V_29 ++ ;
}
V_30 ++ ;
if ( V_30 > V_31 ) {
F_10 ( V_25 , L_1 ,
V_31 ) ;
break;
}
}
return ( V_28 * 1000 ) / 80 ;
}
static int F_11 ( void * V_25 , int * V_34 )
{
T_3 V_35 , V_26 , V_36 , V_28 ;
T_2 V_37 , V_38 , V_39 , V_40 ;
int V_41 , V_42 , V_43 ;
struct V_20 * V_21 = F_12 ( V_25 ) ;
void T_1 * V_1 = V_21 -> V_1 ;
V_28 = 0 ;
F_5 ( V_44 , V_1 ) ;
F_6 ( V_28 , V_1 ) ;
F_7 ( & V_28 , V_1 ) ;
if ( ( V_28 & 0xffff ) != 0 )
F_10 ( V_25 , L_2 , V_28 ) ;
F_6 ( 0x5A5A , V_1 ) ;
F_7 ( & V_28 , V_1 ) ;
if ( ( V_28 & 0xffff ) != 0x5A5A )
F_10 ( V_25 , L_2 , V_28 ) ;
F_6 ( 0x1234 , V_1 ) ;
F_7 ( & V_28 , V_1 ) ;
if ( ( V_28 & 0xffff ) != 0x1234 )
F_10 ( V_25 , L_2 , V_28 ) ;
F_5 ( V_45 , V_1 ) ;
F_7 ( & V_35 , V_1 ) ;
F_5 ( V_32 , V_1 ) ;
F_7 ( & V_26 , V_1 ) ;
F_5 ( V_46 , V_1 ) ;
F_7 ( & V_36 , V_1 ) ;
V_37 = ( V_35 >> 2 ) & 0x7FF ;
V_38 = ( V_26 ) & 0x3 ;
V_39 = ( V_36 >> 12 ) & 0x7 ;
V_40 = ( V_26 >> 4 ) ;
V_35 = ( V_35 & 0xE03 ) | ( 512 ) << 2 ;
V_26 = ( V_26 & 0xFFC ) | ( 1 ) ;
V_36 = ( V_36 & 0x8FF ) | ( 4 ) << 12 ;
V_26 = ( V_26 & 0xFEF ) | ( 0 ) << 4 ;
F_5 ( V_45 , V_1 ) ;
F_6 ( V_35 , V_1 ) ;
F_5 ( V_46 , V_1 ) ;
F_6 ( V_36 , V_1 ) ;
V_41 = F_9 ( V_25 , V_26 , V_1 ) ;
V_26 = ( V_26 & 0xFEF ) | ( 1 ) << 4 ;
V_42 = F_9 ( V_25 , V_26 , V_1 ) ;
V_35 = ( V_35 & 0xE03 ) | ( V_37 ) << 2 ;
V_26 = ( V_26 & 0xFFC ) | ( V_38 ) ;
V_36 = ( V_36 & 0x8FF ) | ( V_39 ) << 12 ;
V_26 = ( V_26 & 0xFEF ) | ( V_40 ) << 4 ;
F_5 ( V_45 , V_1 ) ;
F_6 ( V_35 , V_1 ) ;
F_5 ( V_46 , V_1 ) ;
F_6 ( V_36 , V_1 ) ;
F_5 ( V_32 , V_1 ) ;
F_6 ( V_26 , V_1 ) ;
if ( ! ( V_42 / 1000 ) )
V_42 = 1000 ;
V_43 = ( V_42 - V_41 ) / ( V_42 / 1000 ) ;
* V_34 = ( ( - 559 ) * V_43 * V_43 ) / 1000 + ( 1379 ) * V_43 + ( - 458000 ) ;
return 0 ;
}
static T_4 F_13 ( struct V_47 * V_25 ,
struct V_48 * V_49 ,
char * V_50 )
{
unsigned int V_34 = 0 ;
int V_51 ;
V_51 = F_11 ( V_25 , & V_34 ) ;
if ( V_51 < 0 )
return V_51 ;
return sprintf ( V_50 , L_3 , V_34 ) ;
}
static int F_14 ( struct V_20 * V_21 )
{
struct V_52 * V_53 = V_21 -> V_54 ;
struct V_47 * V_25 = & V_53 -> V_55 -> V_25 ;
int V_11 ;
if ( V_53 -> V_56 )
return 0 ;
V_11 = F_15 ( V_21 ) ;
if ( V_11 )
return V_11 ;
V_11 = F_16 ( V_53 -> V_57 ) ;
if ( V_11 < 0 )
goto V_58;
if ( V_53 -> type == V_59 ) {
F_17 ( V_53 -> V_60 , V_61 ,
V_62 |
V_63 |
V_64 |
V_65 |
V_66 |
V_67 |
V_68 |
V_69 |
V_70 |
V_71 ,
V_53 -> V_72 ) ;
F_17 ( V_53 -> V_60 , V_61 ,
V_70 ,
V_70 ) ;
F_4 ( 100 , 200 ) ;
V_11 = F_8 ( V_21 ) ;
if ( V_11 ) {
F_10 ( V_25 , L_4 , V_11 ) ;
goto V_73;
}
}
F_4 ( 1000 , 2000 ) ;
return 0 ;
V_73:
F_18 ( V_53 -> V_57 ) ;
V_58:
F_19 ( V_21 ) ;
return V_11 ;
}
static void F_20 ( struct V_20 * V_21 )
{
struct V_52 * V_53 = V_21 -> V_54 ;
if ( V_53 -> V_56 )
return;
if ( V_53 -> type == V_59 ) {
F_17 ( V_53 -> V_60 , V_61 ,
V_70 ,
! V_70 ) ;
}
F_18 ( V_53 -> V_57 ) ;
F_19 ( V_21 ) ;
}
static void F_21 ( struct V_74 * V_75 )
{
T_2 V_76 ;
struct V_77 * V_25 ;
struct V_78 * V_79 = F_12 ( V_75 -> V_25 ) ;
struct V_20 * V_21 = V_79 -> V_80 ;
void T_1 * V_1 = V_21 -> V_1 ;
struct V_52 * V_53 = V_21 -> V_54 ;
F_22 ( V_75 ) ;
if ( ! ( V_53 -> V_81 ) || V_82 )
return;
V_53 -> V_81 = false ;
F_23 (dev, &ap->link, ENABLED)
return;
V_76 = F_2 ( V_1 + V_6 ) ;
F_3 ( V_76 | V_83 , V_1 + V_6 ) ;
F_20 ( V_21 ) ;
V_53 -> V_56 = true ;
F_24 ( V_75 -> V_25 , L_5 ) ;
F_24 ( V_75 -> V_25 , L_6 V_84 L_7 ) ;
}
static int F_25 ( struct V_85 * V_86 , unsigned int * V_87 ,
unsigned long V_88 )
{
struct V_74 * V_75 = V_86 -> V_75 ;
struct V_78 * V_79 = F_12 ( V_75 -> V_25 ) ;
struct V_20 * V_21 = V_79 -> V_80 ;
struct V_52 * V_53 = V_21 -> V_54 ;
int V_11 = - V_89 ;
if ( V_53 -> type == V_90 )
V_11 = V_91 . V_92 ( V_86 , V_87 , V_88 ) ;
else if ( V_53 -> type == V_59 )
V_11 = V_93 . V_92 ( V_86 , V_87 , V_88 ) ;
return V_11 ;
}
static T_2 F_26 ( struct V_47 * V_25 ,
const struct V_94 * V_95 , T_5 V_96 )
{
struct V_97 * V_98 = V_25 -> V_99 ;
T_2 V_100 = 0 ;
int V_101 , V_102 ;
for ( V_101 = 0 ; V_101 < V_96 ; V_101 ++ , V_95 ++ ) {
T_2 V_103 ;
if ( V_95 -> V_104 == 0 ) {
if ( F_27 ( V_98 , V_95 -> V_105 ) )
V_100 |= V_95 -> V_106 ;
else
V_100 |= V_95 -> V_107 ;
continue;
}
if ( F_28 ( V_98 , V_95 -> V_105 , & V_103 ) ) {
F_24 ( V_25 , L_8 ,
V_95 -> V_105 , V_95 -> V_107 ) ;
V_100 |= V_95 -> V_107 ;
continue;
}
for ( V_102 = 0 ; V_102 < V_95 -> V_104 ; V_102 ++ ) {
if ( V_95 -> V_108 [ V_102 ] . V_109 == V_103 ) {
F_24 ( V_25 , L_9 ,
V_95 -> V_105 , V_103 , V_95 -> V_108 [ V_102 ] . V_100 ) ;
V_100 |= V_95 -> V_108 [ V_102 ] . V_100 ;
break;
}
}
if ( V_102 == V_95 -> V_104 ) {
F_10 ( V_25 , L_10 ,
V_95 -> V_105 ) ;
V_100 |= V_95 -> V_107 ;
}
}
return V_100 ;
}
static int F_29 ( struct V_110 * V_111 )
{
struct V_47 * V_25 = & V_111 -> V_25 ;
const struct V_112 * V_113 ;
struct V_20 * V_21 ;
struct V_52 * V_53 ;
unsigned int V_76 ;
int V_11 ;
V_113 = F_30 ( V_114 , V_25 ) ;
if ( ! V_113 )
return - V_115 ;
V_53 = F_31 ( V_25 , sizeof( * V_53 ) , V_116 ) ;
if ( ! V_53 )
return - V_117 ;
V_53 -> V_55 = V_111 ;
V_53 -> V_56 = false ;
V_53 -> V_81 = true ;
V_53 -> type = (enum V_118 ) V_113 -> V_119 ;
V_53 -> V_120 = F_32 ( V_25 , L_11 ) ;
if ( F_33 ( V_53 -> V_120 ) ) {
F_10 ( V_25 , L_12 ) ;
return F_34 ( V_53 -> V_120 ) ;
}
V_53 -> V_57 = F_32 ( V_25 , L_13 ) ;
if ( F_33 ( V_53 -> V_57 ) ) {
F_10 ( V_25 , L_14 ) ;
return F_34 ( V_53 -> V_57 ) ;
}
V_53 -> V_121 = F_32 ( V_25 , L_15 ) ;
if ( F_33 ( V_53 -> V_121 ) ) {
F_10 ( V_25 , L_16 ) ;
return F_34 ( V_53 -> V_121 ) ;
}
if ( V_53 -> type == V_59 ) {
T_2 V_100 ;
V_53 -> V_60 = F_35 (
L_17 ) ;
if ( F_33 ( V_53 -> V_60 ) ) {
F_10 ( V_25 ,
L_18 ) ;
return F_34 ( V_53 -> V_60 ) ;
}
V_100 = F_26 ( V_25 , V_122 ,
F_36 ( V_122 ) ) ;
V_53 -> V_72 =
V_123 |
V_124 |
V_125 |
V_100 ;
}
V_21 = F_37 ( V_111 ) ;
if ( F_33 ( V_21 ) )
return F_34 ( V_21 ) ;
V_21 -> V_54 = V_53 ;
V_11 = F_16 ( V_53 -> V_120 ) ;
if ( V_11 )
return V_11 ;
if ( V_53 -> type == V_90 &&
F_38 ( V_126 ) ) {
struct V_47 * V_127 ;
V_127 =
F_39 ( V_25 ,
L_19 ,
V_21 ,
V_128 ) ;
if ( F_33 ( V_127 ) ) {
V_11 = F_34 ( V_127 ) ;
goto V_73;
}
F_40 ( V_127 , 0 , V_127 ,
& V_129 ) ;
F_24 ( V_25 , L_20 , F_41 ( V_127 ) ) ;
}
V_11 = F_14 ( V_21 ) ;
if ( V_11 )
goto V_73;
V_76 = F_2 ( V_21 -> V_1 + V_130 ) ;
if ( ! ( V_76 & V_131 ) ) {
V_76 |= V_131 ;
F_3 ( V_76 , V_21 -> V_1 + V_130 ) ;
}
V_76 = F_2 ( V_21 -> V_1 + V_132 ) ;
if ( ! ( V_76 & 0x1 ) ) {
V_76 |= 0x1 ;
F_3 ( V_76 , V_21 -> V_1 + V_132 ) ;
}
V_76 = F_42 ( V_53 -> V_121 ) / 1000 ;
F_3 ( V_76 , V_21 -> V_1 + V_133 ) ;
V_11 = F_43 ( V_111 , V_21 , & V_134 ,
& V_135 ) ;
if ( V_11 )
goto V_136;
return 0 ;
V_136:
F_20 ( V_21 ) ;
V_73:
F_18 ( V_53 -> V_120 ) ;
return V_11 ;
}
static void F_44 ( struct V_78 * V_79 )
{
struct V_20 * V_21 = V_79 -> V_80 ;
struct V_52 * V_53 = V_21 -> V_54 ;
F_20 ( V_21 ) ;
F_18 ( V_53 -> V_120 ) ;
}
static int F_45 ( struct V_47 * V_25 )
{
struct V_78 * V_79 = F_12 ( V_25 ) ;
struct V_20 * V_21 = V_79 -> V_80 ;
int V_11 ;
V_11 = F_46 ( V_25 ) ;
if ( V_11 )
return V_11 ;
F_20 ( V_21 ) ;
return 0 ;
}
static int F_47 ( struct V_47 * V_25 )
{
struct V_78 * V_79 = F_12 ( V_25 ) ;
struct V_20 * V_21 = V_79 -> V_80 ;
int V_11 ;
V_11 = F_14 ( V_21 ) ;
if ( V_11 )
return V_11 ;
return F_48 ( V_25 ) ;
}
