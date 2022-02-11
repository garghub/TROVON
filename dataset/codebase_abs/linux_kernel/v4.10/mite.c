static unsigned int F_1 ( unsigned int V_1 )
{
return ( F_2 ( V_1 ) - 1 ) & 0x1f ;
}
static unsigned int F_3 ( unsigned int V_2 )
{
unsigned int V_3 = 0 ;
if ( V_2 )
V_3 = 1 + F_2 ( V_2 ) ;
if ( V_3 > 0x7 )
V_3 = 0x7 ;
return F_4 ( V_3 ) ;
}
static unsigned int F_5 ( unsigned int V_4 )
{
return F_6 ( ( V_4 & 0x3 ) | 0x4 ) ;
}
static unsigned int F_7 ( struct V_5 * V_5 , unsigned int V_6 )
{
unsigned int V_7 = F_8 ( V_5 -> V_8 + F_9 ( V_6 ) ) ;
unsigned int V_9 = ( V_7 >> 16 ) & 0xff ;
unsigned int V_10 = V_7 & 0xff ;
return V_9 + V_10 ;
}
static T_1 F_10 ( struct V_11 * V_12 )
{
struct V_5 * V_5 = V_12 -> V_5 ;
return F_8 ( V_5 -> V_8 + F_11 ( V_12 -> V_6 ) ) ;
}
T_1 F_12 ( struct V_11 * V_12 )
{
struct V_5 * V_5 = V_12 -> V_5 ;
return F_8 ( V_5 -> V_8 + F_9 ( V_12 -> V_6 ) ) & 0xff ;
}
static T_1 F_13 ( struct V_11 * V_12 )
{
T_1 V_13 ;
V_13 = F_10 ( V_12 ) ;
return V_13 - F_12 ( V_12 ) ;
}
static T_1 F_14 ( struct V_11 * V_12 )
{
T_1 V_14 ;
V_14 = F_12 ( V_12 ) ;
return F_10 ( V_12 ) - V_14 ;
}
static T_1 F_15 ( struct V_11 * V_12 )
{
T_1 V_13 ;
V_13 = F_10 ( V_12 ) ;
return V_13 + F_12 ( V_12 ) ;
}
static T_1 F_16 ( struct V_11 * V_12 )
{
T_1 V_14 ;
V_14 = F_12 ( V_12 ) ;
return F_10 ( V_12 ) + V_14 ;
}
static void F_17 ( struct V_11 * V_12 ,
struct V_15 * V_16 )
{
struct V_17 * V_18 = V_16 -> V_18 ;
int V_19 ;
unsigned int V_20 , V_21 ;
V_21 = V_18 -> V_22 ;
F_18 ( V_16 , V_18 -> V_23 ) ;
V_20 = F_13 ( V_12 ) ;
if ( ( int ) ( F_14 ( V_12 ) -
V_21 ) > 0 ) {
F_19 ( V_16 -> V_24 -> V_25 ,
L_1 ) ;
V_18 -> V_26 |= V_27 ;
return;
}
V_19 = V_20 - V_18 -> V_28 ;
if ( V_19 > 0 ) {
F_20 ( V_16 , V_19 ) ;
F_21 ( V_16 , V_19 ) ;
V_18 -> V_26 |= V_29 ;
}
}
static void F_22 ( struct V_11 * V_12 ,
struct V_15 * V_16 )
{
struct V_17 * V_18 = V_16 -> V_18 ;
struct V_30 * V_31 = & V_18 -> V_31 ;
T_1 V_32 = V_31 -> V_33 * F_23 ( V_16 ) ;
unsigned int V_21 = V_18 -> V_34 ;
T_1 V_35 , V_36 ;
int V_19 ;
bool V_37 = ( V_31 -> V_38 == V_39 && V_32 != 0 ) ;
F_24 ( V_16 , V_18 -> V_23 ) ;
V_36 = F_15 ( V_12 ) ;
if ( V_31 -> V_38 == V_40 && ( int ) ( V_36 - V_32 ) > 0 )
V_36 = V_32 ;
V_35 = F_16 ( V_12 ) ;
if ( V_31 -> V_38 == V_40 && ( int ) ( V_35 - V_32 ) > 0 )
V_35 = V_32 ;
if ( ( ! V_37 || V_32 > V_21 ) &&
( ( int ) ( V_35 - V_21 ) > 0 ) ) {
F_19 ( V_16 -> V_24 -> V_25 , L_2 ) ;
V_18 -> V_26 |= V_27 ;
return;
}
if ( V_37 ) {
return;
}
V_19 = V_36 - V_18 -> V_41 ;
if ( V_19 > 0 ) {
F_25 ( V_16 , V_19 ) ;
V_18 -> V_26 |= V_29 ;
}
}
void F_26 ( struct V_11 * V_12 , struct V_15 * V_16 )
{
if ( V_12 -> V_42 == V_43 )
F_17 ( V_12 , V_16 ) ;
else
F_22 ( V_12 , V_16 ) ;
}
static unsigned int F_27 ( struct V_11 * V_12 )
{
struct V_5 * V_5 = V_12 -> V_5 ;
unsigned int V_44 ;
unsigned long V_45 ;
F_28 ( & V_5 -> V_46 , V_45 ) ;
V_44 = F_8 ( V_5 -> V_8 + F_29 ( V_12 -> V_6 ) ) ;
if ( V_44 & V_47 ) {
V_12 -> V_48 = 1 ;
F_30 ( V_49 ,
V_5 -> V_8 + F_31 ( V_12 -> V_6 ) ) ;
}
F_32 () ;
F_33 ( & V_5 -> V_46 , V_45 ) ;
return V_44 ;
}
void F_34 ( struct V_11 * V_12 ,
struct V_15 * V_16 ,
bool V_50 )
{
struct V_5 * V_5 = V_12 -> V_5 ;
unsigned int V_44 ;
V_44 = F_27 ( V_12 ) ;
if ( V_44 & V_51 ) {
F_30 ( V_52 , V_5 -> V_8 + F_31 ( V_12 -> V_6 ) ) ;
V_50 = true ;
}
if ( V_50 )
F_26 ( V_12 , V_16 ) ;
if ( V_44 & V_53 ) {
F_35 ( V_16 -> V_24 -> V_25 ,
L_3 , V_44 ) ;
V_16 -> V_18 -> V_26 |= V_54 ;
}
}
int F_36 ( struct V_11 * V_12 )
{
struct V_5 * V_5 = V_12 -> V_5 ;
unsigned long V_45 ;
int V_48 ;
F_27 ( V_12 ) ;
F_28 ( & V_5 -> V_46 , V_45 ) ;
V_48 = V_12 -> V_48 ;
F_33 ( & V_5 -> V_46 , V_45 ) ;
return V_48 ;
}
static void F_37 ( struct V_11 * V_12 )
{
F_30 ( V_55 | V_56 ,
V_12 -> V_5 -> V_8 + F_31 ( V_12 -> V_6 ) ) ;
}
void F_38 ( struct V_11 * V_12 )
{
struct V_5 * V_5 = V_12 -> V_5 ;
unsigned long V_45 ;
F_39 () ;
F_28 ( & V_5 -> V_46 , V_45 ) ;
V_12 -> V_48 = 0 ;
F_30 ( V_57 , V_5 -> V_8 + F_31 ( V_12 -> V_6 ) ) ;
F_32 () ;
F_33 ( & V_5 -> V_46 , V_45 ) ;
}
void F_40 ( struct V_11 * V_12 )
{
struct V_5 * V_5 = V_12 -> V_5 ;
F_30 ( V_58 , V_5 -> V_8 + F_31 ( V_12 -> V_6 ) ) ;
}
void F_41 ( struct V_11 * V_12 ,
unsigned int V_59 , unsigned int V_60 )
{
struct V_5 * V_5 = V_12 -> V_5 ;
unsigned int V_61 , V_62 , V_63 , V_64 ;
F_37 ( V_12 ) ;
V_61 = V_65 | V_66 | V_67 |
V_68 ;
V_61 |= V_69 ;
if ( V_60 == 32 && V_59 == 16 ) {
V_61 |= V_70 | V_71 ;
}
if ( V_12 -> V_42 == V_43 )
V_61 |= V_72 ;
F_30 ( V_61 , V_5 -> V_8 + F_42 ( V_12 -> V_6 ) ) ;
V_62 = F_3 ( 64 ) | V_73 ;
switch ( V_60 ) {
case 8 :
V_62 |= V_74 ;
break;
case 16 :
V_62 |= V_75 ;
break;
case 32 :
V_62 |= V_76 ;
break;
default:
F_43 ( L_4 ) ;
break;
}
F_30 ( V_62 , V_5 -> V_8 + F_44 ( V_12 -> V_6 ) ) ;
V_63 = F_3 ( 64 ) | V_73 ;
V_63 |= V_77 | V_78 | F_5 ( V_12 -> V_6 ) ;
switch ( V_59 ) {
case 8 :
V_63 |= V_74 ;
break;
case 16 :
V_63 |= V_75 ;
break;
case 32 :
V_63 |= V_76 ;
break;
default:
F_43 ( L_5 ) ;
break;
}
F_30 ( V_63 , V_5 -> V_8 + F_45 ( V_12 -> V_6 ) ) ;
F_30 ( 0 , V_5 -> V_8 + F_11 ( V_12 -> V_6 ) ) ;
V_64 = F_3 ( 64 ) | V_73 | V_76 ;
F_30 ( V_64 , V_5 -> V_8 + F_46 ( V_12 -> V_6 ) ) ;
F_30 ( V_12 -> V_79 -> V_80 ,
V_5 -> V_8 + F_47 ( V_12 -> V_6 ) ) ;
}
static struct V_11 * F_48 ( struct V_5 * V_5 ,
struct V_81 * V_79 ,
unsigned int V_82 ,
unsigned int V_83 )
{
struct V_11 * V_12 = NULL ;
unsigned long V_45 ;
int V_84 ;
F_28 ( & V_5 -> V_46 , V_45 ) ;
for ( V_84 = V_82 ; V_84 <= V_83 ; ++ V_84 ) {
V_12 = & V_5 -> V_85 [ V_84 ] ;
if ( ! V_12 -> V_79 ) {
V_12 -> V_79 = V_79 ;
break;
}
V_12 = NULL ;
}
F_33 ( & V_5 -> V_46 , V_45 ) ;
return V_12 ;
}
struct V_11 * F_49 ( struct V_5 * V_5 ,
struct V_81 * V_79 ,
unsigned int V_82 ,
unsigned int V_83 )
{
return F_48 ( V_5 , V_79 , V_82 , V_83 ) ;
}
struct V_11 * F_50 ( struct V_5 * V_5 ,
struct V_81 * V_79 )
{
return F_48 ( V_5 , V_79 , 0 , V_5 -> V_86 - 1 ) ;
}
void F_51 ( struct V_11 * V_12 )
{
struct V_5 * V_5 = V_12 -> V_5 ;
unsigned long V_45 ;
F_28 ( & V_5 -> V_46 , V_45 ) ;
if ( V_12 -> V_79 ) {
F_40 ( V_12 ) ;
F_37 ( V_12 ) ;
F_30 ( V_87 | V_88 |
V_89 | V_90 |
V_91 | V_92 |
V_93 | V_94 ,
V_5 -> V_8 + F_42 ( V_12 -> V_6 ) ) ;
V_12 -> V_79 = NULL ;
F_32 () ;
}
F_33 ( & V_5 -> V_46 , V_45 ) ;
}
int F_52 ( struct V_81 * V_79 ,
struct V_15 * V_16 ,
unsigned int V_20 )
{
struct V_17 * V_18 = V_16 -> V_18 ;
struct V_95 * V_96 = NULL ;
unsigned int V_97 = V_20 >> V_98 ;
unsigned int V_99 = V_20 % V_100 ;
int V_84 ;
F_53 ( V_16 -> V_24 -> V_25 ,
L_6 , V_20 ) ;
if ( ( V_97 + ( V_99 > 0 ? 1 : 0 ) ) > V_79 -> V_101 ) {
F_35 ( V_16 -> V_24 -> V_25 ,
L_7 ) ;
return - V_102 ;
}
for ( V_84 = 0 ; V_84 < V_97 ; ++ V_84 ) {
V_96 = & V_79 -> V_103 [ V_84 ] ;
V_96 -> V_19 = F_54 ( V_100 ) ;
V_96 -> V_104 = F_54 ( V_18 -> V_105 -> V_106 [ V_84 ] . V_80 ) ;
V_96 -> V_107 = F_54 ( V_79 -> V_80 +
( V_84 + 1 ) * sizeof( * V_96 ) ) ;
}
if ( V_99 > 0 ) {
V_96 = & V_79 -> V_103 [ V_84 ] ;
V_96 -> V_19 = F_54 ( V_99 ) ;
V_96 -> V_104 = F_54 ( V_18 -> V_105 -> V_106 [ V_84 ] . V_80 ) ;
}
V_96 -> V_107 = F_54 ( V_79 -> V_80 ) ;
F_55 () ;
return 0 ;
}
static void F_56 ( struct V_81 * V_79 )
{
struct V_95 * V_103 = V_79 -> V_103 ;
if ( V_103 ) {
F_57 ( V_79 -> V_108 ,
V_79 -> V_101 * sizeof( * V_103 ) ,
V_103 , V_79 -> V_80 ) ;
V_79 -> V_103 = NULL ;
V_79 -> V_80 = 0 ;
V_79 -> V_101 = 0 ;
}
}
int F_58 ( struct V_81 * V_79 , struct V_15 * V_16 )
{
struct V_17 * V_18 = V_16 -> V_18 ;
struct V_95 * V_103 ;
unsigned int V_101 ;
F_56 ( V_79 ) ;
if ( V_18 -> V_23 == 0 )
return 0 ;
V_101 = V_18 -> V_23 >> V_98 ;
V_103 = F_59 ( V_79 -> V_108 ,
V_101 * sizeof( * V_103 ) ,
& V_79 -> V_80 , V_109 ) ;
if ( ! V_103 ) {
F_35 ( V_16 -> V_24 -> V_25 ,
L_8 ) ;
return - V_102 ;
}
V_79 -> V_103 = V_103 ;
V_79 -> V_101 = V_101 ;
return F_52 ( V_79 , V_16 , V_101 << V_98 ) ;
}
struct V_81 * F_60 ( struct V_5 * V_5 )
{
struct V_81 * V_79 ;
V_79 = F_61 ( sizeof( * V_79 ) , V_109 ) ;
if ( ! V_79 )
return NULL ;
V_79 -> V_108 = F_62 ( & V_5 -> V_110 -> V_111 ) ;
if ( ! V_79 -> V_108 ) {
F_63 ( V_79 ) ;
return NULL ;
}
V_79 -> V_101 = 0 ;
V_79 -> V_103 = NULL ;
V_79 -> V_80 = 0 ;
return V_79 ;
}
void F_64 ( struct V_81 * V_79 )
{
if ( V_79 ) {
F_56 ( V_79 ) ;
F_65 ( V_79 -> V_108 ) ;
F_63 ( V_79 ) ;
}
}
static int F_66 ( struct V_112 * V_111 , struct V_5 * V_5 ,
bool V_113 )
{
T_2 V_114 ;
unsigned long V_115 ;
int V_84 ;
T_1 V_116 ;
unsigned int V_117 ;
unsigned int V_118 ;
F_67 ( V_5 -> V_110 ) ;
V_5 -> V_8 = F_68 ( V_5 -> V_110 , 0 ) ;
if ( ! V_5 -> V_8 )
return - V_102 ;
V_111 -> V_8 = F_68 ( V_5 -> V_110 , 1 ) ;
if ( ! V_111 -> V_8 )
return - V_102 ;
V_114 = F_69 ( V_5 -> V_110 , 1 ) ;
V_115 = F_70 ( V_5 -> V_110 , 1 ) ;
if ( V_113 ) {
F_30 ( 0 , V_5 -> V_8 + V_119 ) ;
F_53 ( V_111 -> V_25 ,
L_9 ) ;
F_30 ( V_114 | V_120 |
F_1 ( V_115 ) ,
V_5 -> V_8 + V_121 ) ;
F_30 ( 0 , V_5 -> V_8 + V_122 ) ;
} else {
F_30 ( V_114 | V_120 , V_5 -> V_8 + V_119 ) ;
}
V_117 = F_8 ( V_5 -> V_8 + V_123 ) ;
V_117 |= V_124 ;
F_30 ( V_117 , V_5 -> V_8 + V_123 ) ;
V_116 = F_8 ( V_5 -> V_8 + V_125 ) ;
V_5 -> V_86 = F_71 ( V_116 ) ;
if ( V_5 -> V_86 > V_126 ) {
F_19 ( V_111 -> V_25 ,
L_10 ,
V_5 -> V_86 , V_126 ) ;
V_5 -> V_86 = V_126 ;
}
V_118 = F_72 ( V_116 ) ;
if ( V_118 )
V_118 = F_73 ( V_118 ) ;
F_53 ( V_111 -> V_25 ,
L_11 ,
F_74 ( V_116 ) , F_75 ( V_116 ) ,
F_76 ( V_116 ) , F_77 ( V_116 ) ) ;
F_53 ( V_111 -> V_25 ,
L_12 ,
F_71 ( V_116 ) , V_118 ,
F_78 ( V_116 ) , F_79 ( V_116 ) ) ;
for ( V_84 = 0 ; V_84 < V_5 -> V_86 ; V_84 ++ ) {
F_30 ( V_55 , V_5 -> V_8 + F_31 ( V_84 ) ) ;
F_30 ( V_87 | V_88 | V_89 |
V_90 | V_91 | V_92 |
V_93 | V_94 ,
V_5 -> V_8 + F_42 ( V_84 ) ) ;
}
V_5 -> V_127 = F_7 ( V_5 , 0 ) ;
F_53 ( V_111 -> V_25 , L_13 , V_5 -> V_127 ) ;
return 0 ;
}
struct V_5 * F_80 ( struct V_112 * V_111 , bool V_113 )
{
struct V_128 * V_110 = F_81 ( V_111 ) ;
struct V_5 * V_5 ;
unsigned int V_84 ;
int V_129 ;
V_5 = F_82 ( sizeof( * V_5 ) , V_109 ) ;
if ( ! V_5 )
return NULL ;
F_83 ( & V_5 -> V_46 ) ;
V_5 -> V_110 = V_110 ;
for ( V_84 = 0 ; V_84 < V_126 ; ++ V_84 ) {
V_5 -> V_85 [ V_84 ] . V_5 = V_5 ;
V_5 -> V_85 [ V_84 ] . V_6 = V_84 ;
V_5 -> V_85 [ V_84 ] . V_48 = 1 ;
}
V_129 = F_66 ( V_111 , V_5 , V_113 ) ;
if ( V_129 ) {
if ( V_5 -> V_8 )
F_84 ( V_5 -> V_8 ) ;
F_63 ( V_5 ) ;
return NULL ;
}
return V_5 ;
}
void F_85 ( struct V_5 * V_5 )
{
if ( ! V_5 )
return;
if ( V_5 -> V_8 )
F_84 ( V_5 -> V_8 ) ;
F_63 ( V_5 ) ;
}
static int T_3 F_86 ( void )
{
return 0 ;
}
static void T_4 F_87 ( void )
{
}
