static void F_1 ( struct V_1 * V_2 , T_1 V_3 , unsigned long V_4 )
{
F_2 ( V_3 , V_2 -> V_5 + V_4 ) ;
}
static T_1 F_3 ( struct V_1 * V_2 , unsigned long V_4 )
{
return F_4 ( V_2 -> V_5 + V_4 ) ;
}
static unsigned long F_5 ( struct V_1 * V_2 ,
unsigned long V_4 )
{
if ( V_2 -> V_6 )
V_4 += ( V_4 >= V_7 ) ? 0x10 : 0x40 ;
return V_4 ;
}
static void F_6 ( struct V_1 * V_2 , T_1 V_3 ,
unsigned long V_4 )
{
F_2 ( V_3 , V_2 -> V_5 + F_5 ( V_2 , V_4 ) ) ;
}
static T_1 F_7 ( struct V_1 * V_2 , unsigned long V_4 )
{
return F_4 ( V_2 -> V_5 + F_5 ( V_2 , V_4 ) ) ;
}
static void F_8 ( struct V_1 * V_2 , void * V_8 ,
unsigned long V_4 , int V_9 )
{
F_9 ( V_2 -> V_5 + F_5 ( V_2 , V_4 ) , V_8 , V_9 ) ;
}
static void F_10 ( struct V_1 * V_2 , void * V_8 ,
unsigned long V_4 , int V_9 )
{
F_11 ( V_2 -> V_5 + F_5 ( V_2 , V_4 ) , V_8 , V_9 ) ;
}
static void F_12 ( struct V_1 * V_2 , T_1 V_10 )
{
T_1 V_11 = F_7 ( V_2 , V_12 ) ;
V_11 &= ~ V_10 ;
F_6 ( V_2 , V_11 , V_12 ) ;
}
static void F_13 ( struct V_1 * V_2 , T_1 V_10 )
{
T_1 V_11 = F_7 ( V_2 , V_12 ) ;
V_11 |= V_10 ;
F_6 ( V_2 , V_11 , V_12 ) ;
}
static int F_14 ( struct V_1 * V_2 )
{
unsigned long V_13 = V_14 + V_15 ;
T_1 V_3 = F_7 ( V_2 , V_16 ) ;
V_3 |= V_17 | V_18 ;
F_6 ( V_2 , V_3 , V_16 ) ;
while ( F_7 ( V_2 , V_16 ) &
( V_17 | V_18 ) ) {
if ( F_15 ( V_14 , V_13 ) ) {
F_16 ( V_2 -> V_19 , L_1 ) ;
return - V_20 ;
}
F_17 ( 1 ) ;
}
return 0 ;
}
static int F_18 ( struct V_1 * V_2 )
{
T_1 V_3 ;
int V_21 ;
T_2 * V_22 = V_2 -> V_23 ;
T_3 V_24 = V_2 -> V_25 ;
int V_26 ;
V_3 = F_7 ( V_2 , V_27 ) ;
V_21 = ( V_3 & V_28 ) >>
V_29 ;
V_26 = V_24 / V_30 ;
if ( V_26 > V_21 )
V_26 = V_21 ;
F_10 ( V_2 , V_22 , V_31 , V_26 ) ;
V_22 += V_26 * V_30 ;
V_24 -= V_26 * V_30 ;
V_21 -= V_26 ;
if ( V_21 > 0 && V_24 > 0 ) {
F_19 ( V_24 > 3 ) ;
V_3 = F_7 ( V_2 , V_31 ) ;
memcpy ( V_22 , & V_3 , V_24 ) ;
V_24 = 0 ;
V_21 -- ;
}
F_19 ( V_21 > 0 && V_24 > 0 ) ;
V_2 -> V_25 = V_24 ;
V_2 -> V_23 = V_22 ;
return 0 ;
}
static int F_20 ( struct V_1 * V_2 )
{
T_1 V_3 ;
int V_32 ;
T_2 * V_22 = V_2 -> V_23 ;
T_3 V_24 = V_2 -> V_25 ;
int V_26 ;
V_3 = F_7 ( V_2 , V_27 ) ;
V_32 = ( V_3 & V_33 ) >>
V_34 ;
V_26 = V_24 / V_30 ;
if ( V_26 > V_32 )
V_26 = V_32 ;
F_8 ( V_2 , V_22 , V_7 , V_26 ) ;
V_22 += V_26 * V_30 ;
V_24 -= V_26 * V_30 ;
V_32 -= V_26 ;
if ( V_32 > 0 && V_24 > 0 ) {
F_19 ( V_24 > 3 ) ;
memcpy ( & V_3 , V_22 , V_24 ) ;
F_6 ( V_2 , V_3 , V_7 ) ;
V_24 = 0 ;
V_32 -- ;
}
F_19 ( V_32 > 0 && V_24 > 0 ) ;
V_2 -> V_25 = V_24 ;
V_2 -> V_23 = V_22 ;
return 0 ;
}
static void F_21 ( struct V_1 * V_2 )
{
T_1 V_3 = 0 ;
V_3 = F_3 ( V_2 , V_35 ) ;
V_3 |= V_36 ;
V_3 |= V_37 ;
F_1 ( V_2 , V_3 , V_35 ) ;
V_3 = F_3 ( V_2 , V_38 ) ;
V_3 |= V_39 ;
F_1 ( V_2 , V_3 , V_38 ) ;
}
static int F_22 ( struct V_1 * V_2 )
{
T_1 V_3 ;
int V_40 = 0 ;
F_23 ( V_2 -> V_41 ) ;
F_24 ( V_2 -> V_41 ) ;
F_25 ( 2 ) ;
F_26 ( V_2 -> V_41 ) ;
if ( V_2 -> V_6 )
F_21 ( V_2 ) ;
V_3 = V_42 | V_43 |
( 0x2 << V_44 ) ;
F_6 ( V_2 , V_3 , V_45 ) ;
F_6 ( V_2 , 0 , V_12 ) ;
F_27 ( V_2 -> V_41 , V_2 -> V_46 * 8 ) ;
if ( ! V_2 -> V_6 ) {
T_1 V_47 = F_7 ( V_2 , V_48 ) ;
V_47 |= V_49 | V_50 ;
F_6 ( V_2 , V_47 , V_48 ) ;
F_6 ( V_2 , 0xfc , V_51 ) ;
F_6 ( V_2 , 0x00 , V_52 ) ;
}
V_3 = 7 << V_53 |
0 << V_54 ;
F_6 ( V_2 , V_3 , V_16 ) ;
if ( F_14 ( V_2 ) )
V_40 = - V_20 ;
F_28 ( V_2 -> V_41 ) ;
if ( V_2 -> V_55 ) {
V_2 -> V_55 = 0 ;
F_29 ( V_2 -> V_56 ) ;
}
return V_40 ;
}
static T_4 F_30 ( int V_56 , void * V_57 )
{
T_1 V_58 ;
const T_1 V_59 = V_60 | V_61 ;
struct V_1 * V_2 = V_57 ;
V_58 = F_7 ( V_2 , V_62 ) ;
if ( V_58 == 0 ) {
F_16 ( V_2 -> V_19 , L_2 ,
F_7 ( V_2 , V_63 ) ,
F_7 ( V_2 , V_64 ) ,
F_7 ( V_2 , V_45 ) ) ;
V_2 -> V_65 |= V_66 ;
if ( ! V_2 -> V_55 ) {
F_31 ( V_2 -> V_56 ) ;
V_2 -> V_55 = 1 ;
}
F_32 ( & V_2 -> V_67 ) ;
goto V_40;
}
if ( F_33 ( V_58 & V_59 ) ) {
if ( V_58 & V_60 )
V_2 -> V_65 |= V_68 ;
if ( V_58 & V_61 )
V_2 -> V_65 |= V_69 ;
F_32 ( & V_2 -> V_67 ) ;
goto V_40;
}
if ( V_2 -> V_70 && ( V_58 & V_71 ) ) {
if ( V_2 -> V_25 )
F_18 ( V_2 ) ;
else
F_34 () ;
}
if ( ! V_2 -> V_70 && ( V_58 & V_72 ) ) {
if ( V_2 -> V_25 )
F_20 ( V_2 ) ;
else
F_12 ( V_2 , V_72 ) ;
}
if ( ( V_58 & V_73 ) &&
! V_2 -> V_25 )
F_32 ( & V_2 -> V_67 ) ;
F_6 ( V_2 , V_58 , V_62 ) ;
if ( V_2 -> V_6 )
F_1 ( V_2 , V_74 , V_75 ) ;
return V_76 ;
V_40:
F_12 ( V_2 , V_60 | V_61 |
V_73 | V_72 |
V_71 ) ;
F_6 ( V_2 , V_58 , V_62 ) ;
if ( V_2 -> V_6 )
F_1 ( V_2 , V_74 , V_75 ) ;
return V_76 ;
}
static int F_35 ( struct V_1 * V_2 ,
struct V_77 * V_78 , int V_79 )
{
T_1 V_80 ;
T_1 V_11 ;
int V_81 ;
F_14 ( V_2 ) ;
F_6 ( V_2 , 0xFF , V_62 ) ;
if ( V_78 -> V_9 == 0 )
return - V_82 ;
V_2 -> V_23 = V_78 -> V_22 ;
V_2 -> V_25 = V_78 -> V_9 ;
V_2 -> V_65 = V_83 ;
V_2 -> V_70 = ( V_78 -> V_84 & V_85 ) ;
F_36 ( V_2 -> V_67 ) ;
V_80 = ( 0 << V_86 ) |
V_87 |
( V_2 -> V_88 << V_89 ) |
( 1 << V_90 ) ;
F_6 ( V_2 , V_80 , V_7 ) ;
V_80 = V_78 -> V_9 - 1 ;
F_6 ( V_2 , V_80 , V_7 ) ;
V_80 = V_78 -> V_91 << V_92 ;
V_80 |= V_93 ;
if ( ! V_79 )
V_80 |= V_94 ;
if ( V_78 -> V_84 & V_95 )
V_80 |= V_96 ;
if ( V_78 -> V_84 & V_97 )
V_80 |= V_98 ;
if ( V_78 -> V_84 & V_85 )
V_80 |= V_99 ;
F_6 ( V_2 , V_80 , V_7 ) ;
if ( ! ( V_78 -> V_84 & V_85 ) )
F_20 ( V_2 ) ;
V_11 = V_60 | V_61 ;
if ( V_78 -> V_84 & V_85 )
V_11 |= V_71 ;
else if ( V_2 -> V_25 )
V_11 |= V_72 ;
F_13 ( V_2 , V_11 ) ;
F_37 ( V_2 -> V_19 , L_3 ,
F_7 ( V_2 , V_12 ) ) ;
V_81 = F_38 ( & V_2 -> V_67 , V_100 ) ;
F_12 ( V_2 , V_11 ) ;
if ( F_39 ( V_81 == 0 ) ) {
F_40 ( V_2 -> V_19 , L_4 ) ;
F_22 ( V_2 ) ;
return - V_20 ;
}
F_37 ( V_2 -> V_19 , L_5 ,
V_81 , F_41 ( & V_2 -> V_67 ) , V_2 -> V_65 ) ;
if ( F_42 ( V_2 -> V_65 == V_83 ) )
return 0 ;
F_22 ( V_2 ) ;
if ( V_2 -> V_65 == V_68 ) {
if ( V_78 -> V_84 & V_97 )
return 0 ;
return - V_101 ;
}
return - V_102 ;
}
static int F_43 ( struct V_103 * V_104 , struct V_77 V_105 [] ,
int V_106 )
{
struct V_1 * V_2 = F_44 ( V_104 ) ;
int V_107 ;
int V_81 = 0 ;
if ( V_2 -> V_108 )
return - V_109 ;
F_23 ( V_2 -> V_41 ) ;
for ( V_107 = 0 ; V_107 < V_106 ; V_107 ++ ) {
int V_79 = ( V_107 == ( V_106 - 1 ) ) ? 1 : 0 ;
V_81 = F_35 ( V_2 , & V_105 [ V_107 ] , V_79 ) ;
if ( V_81 )
break;
}
F_28 ( V_2 -> V_41 ) ;
return V_81 ? : V_107 ;
}
static T_1 F_45 ( struct V_103 * V_104 )
{
return V_110 ;
}
static int F_46 ( struct V_111 * V_112 )
{
struct V_1 * V_2 ;
struct V_113 * V_114 = V_112 -> V_19 . V_115 ;
struct V_116 * V_117 ;
struct V_116 * V_118 ;
struct V_41 * V_41 ;
struct V_41 * V_119 ;
void * V_5 ;
int V_56 ;
int V_81 = 0 ;
V_117 = F_47 ( V_112 , V_120 , 0 ) ;
if ( ! V_117 ) {
F_40 ( & V_112 -> V_19 , L_6 ) ;
return - V_82 ;
}
V_118 = F_48 ( V_117 -> V_121 , F_49 ( V_117 ) , V_112 -> V_122 ) ;
if ( ! V_118 ) {
F_40 ( & V_112 -> V_19 , L_7 ) ;
return - V_109 ;
}
V_5 = F_50 ( V_118 -> V_121 , F_49 ( V_118 ) ) ;
if ( ! V_5 ) {
F_40 ( & V_112 -> V_19 , L_8 ) ;
return - V_123 ;
}
V_117 = F_47 ( V_112 , V_124 , 0 ) ;
if ( ! V_117 ) {
F_40 ( & V_112 -> V_19 , L_9 ) ;
V_81 = - V_82 ;
goto V_125;
}
V_56 = V_117 -> V_121 ;
V_41 = F_51 ( & V_112 -> V_19 , NULL ) ;
if ( F_52 ( V_41 ) ) {
F_40 ( & V_112 -> V_19 , L_10 ) ;
V_81 = F_53 ( V_41 ) ;
goto V_126;
}
V_119 = F_51 ( & V_112 -> V_19 , L_11 ) ;
if ( F_52 ( V_119 ) ) {
F_40 ( & V_112 -> V_19 , L_12 ) ;
V_81 = F_53 ( V_119 ) ;
goto V_127;
}
V_2 = F_54 ( sizeof( struct V_1 ) , V_128 ) ;
if ( ! V_2 ) {
V_81 = - V_123 ;
goto V_129;
}
V_2 -> V_5 = V_5 ;
V_2 -> V_41 = V_41 ;
V_2 -> V_119 = V_119 ;
V_2 -> V_118 = V_118 ;
V_2 -> V_130 . V_131 = & V_132 ;
V_2 -> V_56 = V_56 ;
V_2 -> V_88 = V_112 -> V_133 ;
V_2 -> V_19 = & V_112 -> V_19 ;
V_2 -> V_46 = V_114 ? V_114 -> V_46 : 100000 ;
if ( V_112 -> V_133 == 3 )
V_2 -> V_6 = 1 ;
F_55 ( & V_2 -> V_67 ) ;
F_56 ( V_112 , V_2 ) ;
V_81 = F_22 ( V_2 ) ;
if ( V_81 ) {
F_40 ( & V_112 -> V_19 , L_13 ) ;
goto V_134;
}
V_81 = F_57 ( V_2 -> V_56 , F_30 , 0 , V_112 -> V_122 , V_2 ) ;
if ( V_81 ) {
F_40 ( & V_112 -> V_19 , L_14 , V_2 -> V_56 ) ;
goto V_134;
}
F_23 ( V_2 -> V_119 ) ;
F_58 ( & V_2 -> V_130 , V_2 ) ;
V_2 -> V_130 . V_135 = V_136 ;
V_2 -> V_130 . V_137 = V_138 ;
F_59 ( V_2 -> V_130 . V_122 , L_15 ,
sizeof( V_2 -> V_130 . V_122 ) ) ;
V_2 -> V_130 . V_131 = & V_132 ;
V_2 -> V_130 . V_19 . V_139 = & V_112 -> V_19 ;
V_2 -> V_130 . V_140 = V_112 -> V_133 ;
V_81 = F_60 ( & V_2 -> V_130 ) ;
if ( V_81 ) {
F_40 ( & V_112 -> V_19 , L_16 ) ;
goto V_141;
}
return 0 ;
V_141:
F_61 ( V_2 -> V_56 , V_2 ) ;
V_134:
F_62 ( V_2 ) ;
V_129:
F_63 ( V_119 ) ;
V_127:
F_63 ( V_41 ) ;
V_126:
F_64 ( V_118 -> V_121 , F_49 ( V_118 ) ) ;
V_125:
F_65 ( V_5 ) ;
return V_81 ;
}
static int F_66 ( struct V_111 * V_112 )
{
struct V_1 * V_2 = F_67 ( V_112 ) ;
F_68 ( & V_2 -> V_130 ) ;
F_61 ( V_2 -> V_56 , V_2 ) ;
F_63 ( V_2 -> V_119 ) ;
F_63 ( V_2 -> V_41 ) ;
F_64 ( V_2 -> V_118 -> V_121 ,
F_49 ( V_2 -> V_118 ) ) ;
F_65 ( V_2 -> V_5 ) ;
F_62 ( V_2 ) ;
return 0 ;
}
static int F_69 ( struct V_111 * V_112 , T_5 V_142 )
{
struct V_1 * V_2 = F_67 ( V_112 ) ;
F_70 ( & V_2 -> V_130 ) ;
V_2 -> V_108 = true ;
F_71 ( & V_2 -> V_130 ) ;
return 0 ;
}
static int F_72 ( struct V_111 * V_112 )
{
struct V_1 * V_2 = F_67 ( V_112 ) ;
int V_81 ;
F_70 ( & V_2 -> V_130 ) ;
V_81 = F_22 ( V_2 ) ;
if ( V_81 ) {
F_71 ( & V_2 -> V_130 ) ;
return V_81 ;
}
V_2 -> V_108 = false ;
F_71 ( & V_2 -> V_130 ) ;
return 0 ;
}
static int T_6 F_73 ( void )
{
return F_74 ( & V_143 ) ;
}
static void T_7 F_75 ( void )
{
F_76 ( & V_143 ) ;
}
