static void F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
F_2 ( V_2 -> V_5 ) ;
if ( V_4 -> V_6 ) {
F_3 ( V_4 ) ;
F_4 ( V_4 ) ;
}
}
static void F_5 ( struct V_7 * V_8 )
{
struct V_1 * V_2 = V_8 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_4 ;
F_6 ( V_4 , V_8 -> V_9 ) ;
F_7 ( & V_8 -> V_10 ) ;
F_8 ( V_4 , V_8 ) ;
}
static void F_9 ( struct V_1 * V_2 )
{
struct V_7 * V_8 , * V_11 ;
F_10 (port, tmp, &pcie->ports, list) {
F_11 ( V_8 -> V_12 ) ;
F_12 ( V_8 -> V_12 ) ;
F_2 ( V_8 -> V_13 ) ;
F_2 ( V_8 -> V_14 ) ;
F_2 ( V_8 -> V_15 ) ;
F_2 ( V_8 -> V_16 ) ;
F_2 ( V_8 -> V_17 ) ;
F_2 ( V_8 -> V_18 ) ;
F_5 ( V_8 ) ;
}
F_1 ( V_2 ) ;
}
static int F_13 ( struct V_7 * V_8 )
{
T_1 V_19 ;
int V_20 ;
V_20 = F_14 ( V_8 -> V_9 + V_21 , V_19 ,
! ( V_19 & V_22 ) , 10 ,
100 * V_23 ) ;
if ( V_20 )
return V_24 ;
if ( F_15 ( V_8 -> V_9 + V_21 ) & V_25 )
return V_24 ;
return V_26 ;
}
static int F_16 ( struct V_7 * V_8 , T_1 V_27 , T_1 V_28 ,
int V_29 , int V_30 , T_1 * V_19 )
{
T_1 V_11 ;
F_17 ( F_18 ( V_31 , V_32 ) ,
V_8 -> V_9 + V_33 ) ;
F_17 ( F_19 ( V_29 , V_30 ) , V_8 -> V_9 + V_34 ) ;
F_17 ( F_20 ( V_29 , F_21 ( V_28 ) , F_22 ( V_28 ) , V_27 ) ,
V_8 -> V_9 + V_35 ) ;
V_11 = F_15 ( V_8 -> V_9 + V_21 ) ;
V_11 |= V_22 ;
F_17 ( V_11 , V_8 -> V_9 + V_21 ) ;
if ( F_13 ( V_8 ) )
return V_24 ;
* V_19 = F_15 ( V_8 -> V_9 + V_36 ) ;
if ( V_30 == 1 )
* V_19 = ( * V_19 >> ( 8 * ( V_29 & 3 ) ) ) & 0xff ;
else if ( V_30 == 2 )
* V_19 = ( * V_19 >> ( 8 * ( V_29 & 3 ) ) ) & 0xffff ;
return V_26 ;
}
static int F_23 ( struct V_7 * V_8 , T_1 V_27 , T_1 V_28 ,
int V_29 , int V_30 , T_1 V_19 )
{
F_17 ( F_18 ( V_31 , V_37 ) ,
V_8 -> V_9 + V_33 ) ;
F_17 ( F_19 ( V_29 , V_30 ) , V_8 -> V_9 + V_34 ) ;
F_17 ( F_20 ( V_29 , F_21 ( V_28 ) , F_22 ( V_28 ) , V_27 ) ,
V_8 -> V_9 + V_35 ) ;
V_19 = V_19 << 8 * ( V_29 & 3 ) ;
F_17 ( V_19 , V_8 -> V_9 + V_38 ) ;
V_19 = F_15 ( V_8 -> V_9 + V_21 ) ;
V_19 |= V_22 ;
F_17 ( V_19 , V_8 -> V_9 + V_21 ) ;
return F_13 ( V_8 ) ;
}
static struct V_7 * F_24 ( struct V_39 * V_27 ,
unsigned int V_28 )
{
struct V_1 * V_2 = V_27 -> V_40 ;
struct V_7 * V_8 ;
F_25 (port, &pcie->ports, list)
if ( V_8 -> V_41 == F_22 ( V_28 ) )
return V_8 ;
return NULL ;
}
static int F_26 ( struct V_39 * V_27 , unsigned int V_28 ,
int V_29 , int V_30 , T_1 * V_19 )
{
struct V_7 * V_8 ;
T_1 V_42 = V_27 -> V_43 ;
int V_44 ;
V_8 = F_24 ( V_27 , V_28 ) ;
if ( ! V_8 ) {
* V_19 = ~ 0 ;
return V_45 ;
}
V_44 = F_16 ( V_8 , V_42 , V_28 , V_29 , V_30 , V_19 ) ;
if ( V_44 )
* V_19 = ~ 0 ;
return V_44 ;
}
static int F_27 ( struct V_39 * V_27 , unsigned int V_28 ,
int V_29 , int V_30 , T_1 V_19 )
{
struct V_7 * V_8 ;
T_1 V_42 = V_27 -> V_43 ;
V_8 = F_24 ( V_27 , V_28 ) ;
if ( ! V_8 )
return V_45 ;
return F_23 ( V_8 , V_42 , V_28 , V_29 , V_30 , V_19 ) ;
}
static int F_28 ( struct V_7 * V_8 )
{
struct V_1 * V_2 = V_8 -> V_2 ;
struct V_46 * V_47 = & V_2 -> V_47 ;
T_1 V_19 ;
T_2 V_30 ;
int V_20 ;
if ( V_2 -> V_9 ) {
V_19 = F_15 ( V_2 -> V_9 + V_48 ) ;
V_19 |= F_29 ( V_8 -> V_41 ) |
F_30 ( V_8 -> V_41 ) ;
F_17 ( V_19 , V_2 -> V_9 + V_48 ) ;
}
F_17 ( 0 , V_8 -> V_9 + V_49 ) ;
F_17 ( V_50 , V_8 -> V_9 + V_49 ) ;
V_19 = F_15 ( V_8 -> V_9 + V_49 ) ;
V_19 |= V_51 | V_52 | V_53 |
V_54 | V_55 ;
F_17 ( V_19 , V_8 -> V_9 + V_49 ) ;
V_20 = F_31 ( V_8 -> V_9 + V_56 , V_19 ,
! ! ( V_19 & V_57 ) , 20 ,
100 * V_23 ) ;
if ( V_20 )
return - V_58 ;
V_19 = F_15 ( V_8 -> V_9 + V_59 ) ;
V_19 &= ~ V_60 ;
F_17 ( V_19 , V_8 -> V_9 + V_59 ) ;
V_30 = V_47 -> V_61 - V_47 -> V_62 ;
V_19 = F_32 ( V_47 -> V_62 ) | F_33 ( F_34 ( V_30 ) ) ;
F_17 ( V_19 , V_8 -> V_9 + V_63 ) ;
V_19 = F_35 ( V_47 -> V_62 ) ;
F_17 ( V_19 , V_8 -> V_9 + V_64 ) ;
V_19 = F_34 ( 0xffffffff ) | V_65 ;
F_17 ( V_19 , V_8 -> V_9 + V_66 ) ;
return 0 ;
}
static int F_36 ( struct V_7 * V_8 )
{
int V_67 ;
V_67 = F_37 ( V_8 -> V_68 , V_69 ) ;
if ( V_67 < V_69 )
F_38 ( V_67 , V_8 -> V_68 ) ;
else
return - V_70 ;
return V_67 ;
}
static void F_39 ( struct V_7 * V_8 , unsigned long V_71 )
{
F_40 ( V_71 , V_8 -> V_68 ) ;
}
static int F_41 ( struct V_72 * V_73 ,
struct V_74 * V_75 , struct V_76 * V_77 )
{
struct V_7 * V_8 ;
struct V_78 V_79 ;
unsigned int V_80 ;
int V_71 ;
T_3 V_81 ;
V_8 = F_24 ( V_75 -> V_27 , V_75 -> V_28 ) ;
if ( ! V_8 )
return - V_82 ;
V_71 = F_36 ( V_8 ) ;
if ( V_71 < 0 )
return V_71 ;
V_80 = F_42 ( V_8 -> V_83 , V_71 ) ;
if ( ! V_80 ) {
F_39 ( V_8 , V_71 ) ;
return - V_82 ;
}
V_73 -> V_4 = & V_75 -> V_4 ;
F_43 ( V_80 , V_77 ) ;
V_81 = F_44 ( V_8 -> V_9 + V_84 ) ;
V_79 . V_85 = 0 ;
V_79 . V_86 = F_32 ( V_81 ) ;
V_79 . V_87 = V_71 ;
F_45 ( V_80 , & V_79 ) ;
return 0 ;
}
static void F_46 ( struct V_72 * V_73 , unsigned int V_80 )
{
struct V_74 * V_75 = F_47 ( V_73 -> V_4 ) ;
struct V_88 * V_89 = F_48 ( V_80 ) ;
T_4 V_71 = F_49 ( V_89 ) ;
struct V_7 * V_8 ;
V_8 = F_24 ( V_75 -> V_27 , V_75 -> V_28 ) ;
if ( ! V_8 )
return;
F_50 ( V_80 ) ;
F_39 ( V_8 , V_71 ) ;
}
static int F_51 ( struct V_90 * V_91 , unsigned int V_80 ,
T_4 V_71 )
{
F_52 ( V_80 , & V_92 , V_93 ) ;
F_53 ( V_80 , V_91 -> V_94 ) ;
return 0 ;
}
static void F_54 ( struct V_7 * V_8 )
{
T_1 V_19 ;
T_3 V_81 ;
V_81 = F_44 ( V_8 -> V_9 + V_84 ) ;
V_19 = F_32 ( V_81 ) ;
F_17 ( V_19 , V_8 -> V_9 + V_95 ) ;
V_19 = F_15 ( V_8 -> V_9 + V_59 ) ;
V_19 &= ~ V_96 ;
F_17 ( V_19 , V_8 -> V_9 + V_59 ) ;
}
static int F_55 ( struct V_90 * V_91 , unsigned int V_80 ,
T_4 V_71 )
{
F_52 ( V_80 , & V_97 , V_93 ) ;
F_53 ( V_80 , V_91 -> V_94 ) ;
return 0 ;
}
static int F_56 ( struct V_7 * V_8 ,
struct V_98 * V_99 )
{
struct V_3 * V_4 = V_8 -> V_2 -> V_4 ;
struct V_98 * V_100 ;
V_100 = F_57 ( V_99 , NULL ) ;
if ( ! V_100 ) {
F_58 ( V_4 , L_1 ) ;
return - V_101 ;
}
V_8 -> V_90 = F_59 ( V_100 , V_102 ,
& V_103 , V_8 ) ;
if ( ! V_8 -> V_90 ) {
F_58 ( V_4 , L_2 ) ;
return - V_101 ;
}
if ( F_60 ( V_104 ) ) {
V_8 -> V_83 = F_59 ( V_99 , V_69 ,
& V_105 ,
& V_106 ) ;
if ( ! V_8 -> V_83 ) {
F_58 ( V_4 , L_3 ) ;
return - V_101 ;
}
F_54 ( V_8 ) ;
}
return 0 ;
}
static T_5 F_61 ( int V_80 , void * V_87 )
{
struct V_7 * V_8 = (struct V_7 * ) V_87 ;
unsigned long V_107 ;
T_1 V_108 ;
T_1 V_109 = V_110 ;
while ( ( V_107 = F_15 ( V_8 -> V_9 + V_111 ) ) & V_60 ) {
F_62 (bit, &status, PCI_NUM_INTX + INTX_SHIFT) {
F_17 ( 1 << V_109 , V_8 -> V_9 + V_111 ) ;
V_108 = F_63 ( V_8 -> V_90 ,
V_109 - V_110 ) ;
F_64 ( V_108 ) ;
}
}
if ( F_60 ( V_104 ) ) {
while ( ( V_107 = F_15 ( V_8 -> V_9 + V_111 ) ) & V_112 ) {
unsigned long V_113 ;
while ( ( V_113 = F_15 ( V_8 -> V_9 + V_114 ) ) ) {
F_65 (bit, &imsi_status, MTK_MSI_IRQS_NUM) {
F_17 ( 1 << V_109 , V_8 -> V_9 + V_114 ) ;
V_108 = F_63 ( V_8 -> V_83 , V_109 ) ;
F_64 ( V_108 ) ;
}
}
F_17 ( V_112 , V_8 -> V_9 + V_111 ) ;
}
}
return V_115 ;
}
static int F_66 ( struct V_7 * V_8 ,
struct V_98 * V_99 )
{
struct V_1 * V_2 = V_8 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_116 * V_75 = F_67 ( V_4 ) ;
int V_20 , V_80 ;
V_80 = F_68 ( V_75 , V_8 -> V_41 ) ;
V_20 = F_69 ( V_4 , V_80 , F_61 ,
V_117 , L_4 , V_8 ) ;
if ( V_20 ) {
F_58 ( V_4 , L_5 , V_80 ) ;
return V_20 ;
}
V_20 = F_56 ( V_8 , V_99 ) ;
if ( V_20 ) {
F_58 ( V_4 , L_6 ) ;
return V_20 ;
}
return 0 ;
}
static void T_6 * F_70 ( struct V_39 * V_27 ,
unsigned int V_28 , int V_29 )
{
struct V_1 * V_2 = V_27 -> V_40 ;
F_17 ( F_71 ( V_29 , F_21 ( V_28 ) , F_22 ( V_28 ) ,
V_27 -> V_43 ) , V_2 -> V_9 + V_118 ) ;
return V_2 -> V_9 + V_119 + ( V_29 & 3 ) ;
}
static int F_72 ( struct V_7 * V_8 )
{
struct V_1 * V_2 = V_8 -> V_2 ;
T_1 V_120 = F_21 ( V_8 -> V_41 << 3 ) ;
T_1 V_41 = F_22 ( V_8 -> V_41 << 3 ) ;
T_1 V_19 ;
int V_20 ;
V_19 = F_15 ( V_2 -> V_9 + V_121 ) ;
V_19 |= F_73 ( V_8 -> V_41 ) ;
F_17 ( V_19 , V_2 -> V_9 + V_121 ) ;
V_19 = F_15 ( V_2 -> V_9 + V_121 ) ;
V_19 &= ~ F_73 ( V_8 -> V_41 ) ;
F_17 ( V_19 , V_2 -> V_9 + V_121 ) ;
V_20 = F_31 ( V_8 -> V_9 + V_122 , V_19 ,
! ! ( V_19 & V_123 ) , 20 ,
100 * V_23 ) ;
if ( V_20 )
return - V_58 ;
V_19 = F_15 ( V_2 -> V_9 + V_124 ) ;
V_19 |= F_74 ( V_8 -> V_41 ) ;
F_17 ( V_19 , V_2 -> V_9 + V_124 ) ;
F_17 ( V_125 | V_126 ,
V_8 -> V_9 + V_127 ) ;
F_17 ( V_128 | V_129 , V_8 -> V_9 + V_130 ) ;
F_17 ( F_71 ( V_131 , V_120 , V_41 , 0 ) ,
V_2 -> V_9 + V_118 ) ;
V_19 = F_15 ( V_2 -> V_9 + V_119 ) ;
V_19 &= ~ V_132 ;
V_19 |= F_75 ( 0x806c ) ;
F_17 ( F_71 ( V_131 , V_120 , V_41 , 0 ) ,
V_2 -> V_9 + V_118 ) ;
F_17 ( V_19 , V_2 -> V_9 + V_119 ) ;
F_17 ( F_71 ( V_133 , V_120 , V_41 , 0 ) ,
V_2 -> V_9 + V_118 ) ;
V_19 = F_15 ( V_2 -> V_9 + V_119 ) ;
V_19 &= ~ V_134 ;
V_19 |= F_76 ( 0x50 ) ;
F_17 ( F_71 ( V_133 , V_120 , V_41 , 0 ) ,
V_2 -> V_9 + V_118 ) ;
F_17 ( V_19 , V_2 -> V_9 + V_119 ) ;
return 0 ;
}
static void F_77 ( struct V_7 * V_8 )
{
struct V_1 * V_2 = V_8 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_4 ;
int V_20 ;
V_20 = F_78 ( V_8 -> V_18 ) ;
if ( V_20 ) {
F_58 ( V_4 , L_7 , V_8 -> V_41 ) ;
goto V_135;
}
V_20 = F_78 ( V_8 -> V_17 ) ;
if ( V_20 ) {
F_58 ( V_4 , L_8 , V_8 -> V_41 ) ;
goto V_136;
}
V_20 = F_78 ( V_8 -> V_16 ) ;
if ( V_20 ) {
F_58 ( V_4 , L_9 , V_8 -> V_41 ) ;
goto V_137;
}
V_20 = F_78 ( V_8 -> V_15 ) ;
if ( V_20 ) {
F_58 ( V_4 , L_10 , V_8 -> V_41 ) ;
goto V_138;
}
V_20 = F_78 ( V_8 -> V_14 ) ;
if ( V_20 ) {
F_58 ( V_4 , L_11 , V_8 -> V_41 ) ;
goto V_139;
}
V_20 = F_78 ( V_8 -> V_13 ) ;
if ( V_20 ) {
F_58 ( V_4 , L_12 , V_8 -> V_41 ) ;
goto V_140;
}
F_79 ( V_8 -> V_141 ) ;
F_80 ( V_8 -> V_141 ) ;
V_20 = F_81 ( V_8 -> V_12 ) ;
if ( V_20 ) {
F_58 ( V_4 , L_13 , V_8 -> V_41 ) ;
goto V_142;
}
V_20 = F_82 ( V_8 -> V_12 ) ;
if ( V_20 ) {
F_58 ( V_4 , L_14 , V_8 -> V_41 ) ;
goto V_143;
}
if ( ! V_2 -> V_144 -> V_145 ( V_8 ) )
return;
F_83 ( V_4 , L_15 , V_8 -> V_41 ) ;
F_11 ( V_8 -> V_12 ) ;
V_143:
F_12 ( V_8 -> V_12 ) ;
V_142:
F_2 ( V_8 -> V_13 ) ;
V_140:
F_2 ( V_8 -> V_14 ) ;
V_139:
F_2 ( V_8 -> V_15 ) ;
V_138:
F_2 ( V_8 -> V_16 ) ;
V_137:
F_2 ( V_8 -> V_17 ) ;
V_136:
F_2 ( V_8 -> V_18 ) ;
V_135:
F_5 ( V_8 ) ;
}
static int F_84 ( struct V_1 * V_2 ,
struct V_98 * V_99 ,
int V_41 )
{
struct V_7 * V_8 ;
struct V_46 * V_146 ;
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_116 * V_75 = F_67 ( V_4 ) ;
char V_147 [ 10 ] ;
int V_20 ;
V_8 = F_85 ( V_4 , sizeof( * V_8 ) , V_148 ) ;
if ( ! V_8 )
return - V_149 ;
V_20 = F_86 ( V_99 , L_16 , & V_8 -> V_150 ) ;
if ( V_20 ) {
F_58 ( V_4 , L_17 ) ;
return V_20 ;
}
snprintf ( V_147 , sizeof( V_147 ) , L_18 , V_41 ) ;
V_146 = F_87 ( V_75 , V_151 , V_147 ) ;
V_8 -> V_9 = F_88 ( V_4 , V_146 ) ;
if ( F_89 ( V_8 -> V_9 ) ) {
F_58 ( V_4 , L_19 , V_41 ) ;
return F_90 ( V_8 -> V_9 ) ;
}
snprintf ( V_147 , sizeof( V_147 ) , L_20 , V_41 ) ;
V_8 -> V_18 = F_91 ( V_4 , V_147 ) ;
if ( F_89 ( V_8 -> V_18 ) ) {
F_58 ( V_4 , L_21 , V_41 ) ;
return F_90 ( V_8 -> V_18 ) ;
}
snprintf ( V_147 , sizeof( V_147 ) , L_22 , V_41 ) ;
V_8 -> V_17 = F_91 ( V_4 , V_147 ) ;
if ( F_89 ( V_8 -> V_17 ) ) {
if ( F_90 ( V_8 -> V_17 ) == - V_152 )
return - V_152 ;
V_8 -> V_17 = NULL ;
}
snprintf ( V_147 , sizeof( V_147 ) , L_23 , V_41 ) ;
V_8 -> V_15 = F_91 ( V_4 , V_147 ) ;
if ( F_89 ( V_8 -> V_15 ) ) {
if ( F_90 ( V_8 -> V_15 ) == - V_152 )
return - V_152 ;
V_8 -> V_15 = NULL ;
}
snprintf ( V_147 , sizeof( V_147 ) , L_24 , V_41 ) ;
V_8 -> V_16 = F_91 ( V_4 , V_147 ) ;
if ( F_89 ( V_8 -> V_16 ) ) {
if ( F_90 ( V_8 -> V_16 ) == - V_152 )
return - V_152 ;
V_8 -> V_16 = NULL ;
}
snprintf ( V_147 , sizeof( V_147 ) , L_25 , V_41 ) ;
V_8 -> V_14 = F_91 ( V_4 , V_147 ) ;
if ( F_89 ( V_8 -> V_14 ) ) {
if ( F_90 ( V_8 -> V_14 ) == - V_152 )
return - V_152 ;
V_8 -> V_14 = NULL ;
}
snprintf ( V_147 , sizeof( V_147 ) , L_26 , V_41 ) ;
V_8 -> V_13 = F_91 ( V_4 , V_147 ) ;
if ( F_89 ( V_8 -> V_13 ) ) {
if ( F_90 ( V_8 -> V_13 ) == - V_152 )
return - V_152 ;
V_8 -> V_13 = NULL ;
}
snprintf ( V_147 , sizeof( V_147 ) , L_27 , V_41 ) ;
V_8 -> V_141 = F_92 ( V_4 , V_147 ) ;
if ( F_90 ( V_8 -> V_141 ) == - V_152 )
return F_90 ( V_8 -> V_141 ) ;
snprintf ( V_147 , sizeof( V_147 ) , L_28 , V_41 ) ;
V_8 -> V_12 = F_93 ( V_4 , V_147 ) ;
if ( F_89 ( V_8 -> V_12 ) )
return F_90 ( V_8 -> V_12 ) ;
V_8 -> V_41 = V_41 ;
V_8 -> V_2 = V_2 ;
if ( V_2 -> V_144 -> V_153 ) {
V_20 = V_2 -> V_144 -> V_153 ( V_8 , V_99 ) ;
if ( V_20 )
return V_20 ;
}
F_94 ( & V_8 -> V_10 ) ;
F_95 ( & V_8 -> V_10 , & V_2 -> V_154 ) ;
return 0 ;
}
static int F_96 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_116 * V_75 = F_67 ( V_4 ) ;
struct V_46 * V_146 ;
int V_20 ;
V_146 = F_87 ( V_75 , V_151 , L_29 ) ;
if ( V_146 ) {
V_2 -> V_9 = F_88 ( V_4 , V_146 ) ;
if ( F_89 ( V_2 -> V_9 ) ) {
F_58 ( V_4 , L_30 ) ;
return F_90 ( V_2 -> V_9 ) ;
}
}
V_2 -> V_5 = F_91 ( V_4 , L_31 ) ;
if ( F_89 ( V_2 -> V_5 ) ) {
if ( F_90 ( V_2 -> V_5 ) == - V_152 )
return - V_152 ;
V_2 -> V_5 = NULL ;
}
if ( V_4 -> V_6 ) {
F_97 ( V_4 ) ;
F_98 ( V_4 ) ;
}
V_20 = F_78 ( V_2 -> V_5 ) ;
if ( V_20 ) {
F_58 ( V_4 , L_32 ) ;
goto V_155;
}
return 0 ;
V_155:
if ( V_4 -> V_6 ) {
F_3 ( V_4 ) ;
F_4 ( V_4 ) ;
}
return V_20 ;
}
static int F_99 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_98 * V_99 = V_4 -> V_156 , * V_157 ;
struct V_158 V_159 ;
struct V_160 V_161 ;
struct V_46 V_162 ;
struct V_7 * V_8 , * V_11 ;
int V_20 ;
if ( F_100 ( & V_159 , V_99 ) ) {
F_58 ( V_4 , L_33 ) ;
return - V_82 ;
}
F_101 (&parser, &range) {
V_20 = F_102 ( & V_161 , V_99 , & V_162 ) ;
if ( V_20 < 0 )
return V_20 ;
switch ( V_162 . V_163 & V_164 ) {
case V_165 :
V_2 -> V_166 . V_167 = V_162 . V_62 - V_161 . V_168 ;
memcpy ( & V_2 -> V_169 , & V_162 , sizeof( V_162 ) ) ;
V_2 -> V_169 . V_147 = V_99 -> V_170 ;
V_2 -> V_167 . V_62 = V_161 . V_171 ;
V_2 -> V_167 . V_61 = V_161 . V_171 + V_161 . V_30 - 1 ;
V_2 -> V_167 . V_163 = V_151 ;
V_2 -> V_167 . V_147 = L_34 ;
memcpy ( & V_162 , & V_2 -> V_167 , sizeof( V_162 ) ) ;
break;
case V_151 :
V_2 -> V_166 . V_47 = V_162 . V_62 - V_161 . V_168 ;
memcpy ( & V_2 -> V_47 , & V_162 , sizeof( V_162 ) ) ;
V_2 -> V_47 . V_147 = L_35 ;
break;
}
}
V_20 = F_103 ( V_99 , & V_2 -> V_172 ) ;
if ( V_20 < 0 ) {
F_58 ( V_4 , L_36 , V_20 ) ;
V_2 -> V_172 . V_147 = V_99 -> V_147 ;
V_2 -> V_172 . V_62 = 0 ;
V_2 -> V_172 . V_61 = 0xff ;
V_2 -> V_172 . V_163 = V_173 ;
}
F_104 (node, child) {
int V_41 ;
V_20 = F_105 ( V_157 ) ;
if ( V_20 < 0 ) {
F_58 ( V_4 , L_37 , V_20 ) ;
return V_20 ;
}
V_41 = F_22 ( V_20 ) ;
V_20 = F_84 ( V_2 , V_157 , V_41 ) ;
if ( V_20 )
return V_20 ;
}
V_20 = F_96 ( V_2 ) ;
if ( V_20 )
return V_20 ;
F_10 (port, tmp, &pcie->ports, list)
F_77 ( V_8 ) ;
if ( F_106 ( & V_2 -> V_154 ) )
F_1 ( V_2 ) ;
return 0 ;
}
static int F_107 ( struct V_1 * V_2 )
{
struct V_174 * V_175 = F_108 ( V_2 ) ;
struct V_176 * V_177 = & V_175 -> V_177 ;
struct V_3 * V_4 = V_2 -> V_4 ;
int V_20 ;
F_109 ( V_177 , & V_2 -> V_169 , V_2 -> V_166 . V_167 ) ;
F_109 ( V_177 , & V_2 -> V_47 , V_2 -> V_166 . V_47 ) ;
F_110 ( V_177 , & V_2 -> V_172 ) ;
V_20 = F_111 ( V_4 , V_177 ) ;
if ( V_20 < 0 )
return V_20 ;
F_112 ( & V_2 -> V_169 , V_2 -> V_167 . V_62 ) ;
return 0 ;
}
static int F_113 ( struct V_174 * V_175 )
{
struct V_1 * V_2 = F_114 ( V_175 ) ;
struct V_39 * V_157 ;
int V_20 ;
V_175 -> V_178 = V_2 -> V_172 . V_62 ;
V_175 -> V_4 . V_179 = V_2 -> V_4 ;
V_175 -> V_180 = V_2 -> V_144 -> V_180 ;
V_175 -> V_181 = V_182 ;
V_175 -> V_183 = V_184 ;
V_175 -> V_40 = V_2 ;
if ( F_60 ( V_104 ) && V_2 -> V_144 -> V_185 )
V_175 -> V_67 = & V_106 ;
V_20 = F_115 ( V_175 ) ;
if ( V_20 < 0 )
return V_20 ;
F_116 ( V_175 -> V_27 ) ;
F_117 ( V_175 -> V_27 ) ;
F_25 (child, &host->bus->children, node)
F_118 ( V_157 ) ;
F_119 ( V_175 -> V_27 ) ;
return 0 ;
}
static int F_120 ( struct V_116 * V_75 )
{
struct V_3 * V_4 = & V_75 -> V_4 ;
struct V_1 * V_2 ;
struct V_174 * V_175 ;
int V_20 ;
V_175 = F_121 ( V_4 , sizeof( * V_2 ) ) ;
if ( ! V_175 )
return - V_149 ;
V_2 = F_114 ( V_175 ) ;
V_2 -> V_4 = V_4 ;
V_2 -> V_144 = F_122 ( V_4 ) ;
F_123 ( V_75 , V_2 ) ;
F_94 ( & V_2 -> V_154 ) ;
V_20 = F_99 ( V_2 ) ;
if ( V_20 )
return V_20 ;
V_20 = F_107 ( V_2 ) ;
if ( V_20 )
goto V_186;
V_20 = F_113 ( V_175 ) ;
if ( V_20 )
goto V_186;
return 0 ;
V_186:
if ( ! F_106 ( & V_2 -> V_154 ) )
F_9 ( V_2 ) ;
return V_20 ;
}
