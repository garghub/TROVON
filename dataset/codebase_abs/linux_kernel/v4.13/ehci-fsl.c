static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 ;
struct V_5 * V_6 ;
struct V_7 * V_8 ;
int V_9 ;
int V_10 ;
F_2 ( L_1 ) ;
V_4 = F_3 ( & V_2 -> V_11 ) ;
if ( ! V_4 ) {
F_4 ( & V_2 -> V_11 ,
L_2 , F_5 ( & V_2 -> V_11 ) ) ;
return - V_12 ;
}
if ( ! ( ( V_4 -> V_13 == V_14 ) ||
( V_4 -> V_13 == V_15 ) ||
( V_4 -> V_13 == V_16 ) ) ) {
F_4 ( & V_2 -> V_11 ,
L_3 ,
F_5 ( & V_2 -> V_11 ) ) ;
return - V_12 ;
}
V_8 = F_6 ( V_2 , V_17 , 0 ) ;
if ( ! V_8 ) {
F_4 ( & V_2 -> V_11 ,
L_4 ,
F_5 ( & V_2 -> V_11 ) ) ;
return - V_12 ;
}
V_9 = V_8 -> V_18 ;
V_6 = F_7 ( & V_19 , V_2 -> V_11 . V_20 ,
& V_2 -> V_11 , F_5 ( & V_2 -> V_11 ) , NULL ) ;
if ( ! V_6 ) {
V_10 = - V_21 ;
goto V_22;
}
V_8 = F_6 ( V_2 , V_23 , 0 ) ;
V_6 -> V_24 = F_8 ( & V_2 -> V_11 , V_8 ) ;
if ( F_9 ( V_6 -> V_24 ) ) {
V_10 = F_10 ( V_6 -> V_24 ) ;
goto V_25;
}
V_6 -> V_26 = V_8 -> V_18 ;
V_6 -> V_27 = F_11 ( V_8 ) ;
V_4 -> V_24 = V_6 -> V_24 ;
if ( V_4 -> V_28 )
V_6 -> V_28 = V_4 -> V_28 ;
if ( V_4 -> V_29 && V_4 -> V_29 ( V_2 ) ) {
V_10 = - V_12 ;
goto V_25;
}
if ( V_4 -> V_30 && V_4 -> V_31 < V_32 )
F_12 ( V_6 -> V_24 + V_33 ,
V_34 , 0x4 ) ;
if ( V_4 -> V_35 ) {
F_12 ( V_6 -> V_24 + V_33 ,
V_34 , V_36 ) ;
F_13 ( V_37 , V_6 -> V_24 + V_38 ) ;
}
V_10 = F_14 ( V_6 , V_9 , V_39 ) ;
if ( V_10 != 0 )
goto V_25;
F_15 ( V_6 -> V_40 . V_41 ) ;
#ifdef F_16
if ( V_4 -> V_13 == V_16 ) {
struct V_42 * V_43 = F_17 ( V_6 ) ;
V_6 -> V_44 = F_18 ( V_45 ) ;
F_19 ( & V_2 -> V_11 , L_5 ,
V_6 , V_43 , V_6 -> V_44 ) ;
if ( ! F_20 ( V_6 -> V_44 ) ) {
V_10 = F_21 ( V_6 -> V_44 -> V_46 ,
& F_22 ( V_43 ) -> V_40 ) ;
if ( V_10 ) {
F_23 ( V_6 -> V_44 ) ;
goto V_25;
}
} else {
F_4 ( & V_2 -> V_11 , L_6 ) ;
V_10 = - V_12 ;
goto V_25;
}
}
#endif
return V_10 ;
V_25:
F_24 ( V_6 ) ;
V_22:
F_4 ( & V_2 -> V_11 , L_7 , F_5 ( & V_2 -> V_11 ) , V_10 ) ;
if ( V_4 -> exit )
V_4 -> exit ( V_2 ) ;
return V_10 ;
}
static int F_25 ( struct V_5 * V_6 ,
enum V_47 V_48 ,
unsigned int V_49 )
{
T_1 V_50 ;
struct V_42 * V_43 = F_17 ( V_6 ) ;
void T_2 * V_51 = V_6 -> V_24 ;
struct V_52 * V_11 = V_6 -> V_40 . V_41 ;
struct V_3 * V_4 = F_3 ( V_11 ) ;
if ( V_4 -> V_31 < 0 ) {
F_26 ( V_6 -> V_40 . V_41 , L_8 ) ;
return - V_12 ;
}
V_50 = F_27 ( V_43 , & V_43 -> V_24 -> V_53 [ V_49 ] ) ;
V_50 &= ~ ( V_54 | V_55 ) ;
switch ( V_48 ) {
case V_56 :
if ( V_4 -> V_30 && V_4 -> V_31 ) {
F_28 ( V_51 + V_33 ,
V_34 | V_57 ) ;
F_12 ( V_51 + V_33 ,
V_34 ,
V_58 | V_59 ) ;
}
V_50 |= V_60 ;
break;
case V_61 :
V_50 |= V_62 ;
break;
case V_63 :
V_50 |= V_55 ;
case V_64 :
case V_65 :
if ( V_4 -> V_30 && V_4 -> V_31 ) {
F_12 ( V_51 + V_33 ,
V_34 , V_57 ) ;
F_29 ( V_66 ) ;
}
if ( V_4 -> V_30 )
F_12 ( V_51 + V_33 ,
V_34 ,
V_36 ) ;
V_50 |= V_37 ;
break;
case V_67 :
break;
}
if ( V_4 -> V_68 ) {
if ( ! ( F_30 ( V_51 + V_33 ) &
V_69 ) ) {
F_26 ( V_6 -> V_40 . V_41 ,
L_9 ) ;
return - V_70 ;
}
}
F_31 ( V_43 , V_50 , & V_43 -> V_24 -> V_53 [ V_49 ] ) ;
if ( V_48 != V_56 && V_4 -> V_30 )
F_12 ( V_51 + V_33 ,
V_34 , V_59 ) ;
return 0 ;
}
static int F_32 ( struct V_42 * V_43 )
{
struct V_5 * V_6 = F_22 ( V_43 ) ;
struct V_3 * V_4 ;
void T_2 * V_51 = V_6 -> V_24 ;
V_4 = F_3 ( V_6 -> V_40 . V_41 ) ;
if ( V_4 -> V_30 ) {
F_33 ( 0x0 | V_71 ,
V_51 + V_72 ) ;
F_33 ( 0x80000000 | V_71 ,
V_51 + V_73 ) ;
}
if ( V_4 -> V_74 == 1 )
V_43 -> V_75 = 1 ;
if ( V_4 -> V_76 == 1 )
V_43 -> V_77 = 1 ;
if ( ( V_4 -> V_13 == V_14 ) ||
( V_4 -> V_13 == V_16 ) )
if ( F_25 ( V_6 , V_4 -> V_48 , 0 ) )
return - V_70 ;
if ( V_4 -> V_13 == V_15 ) {
unsigned int V_78 , V_79 , V_80 ;
V_80 = F_34 ( V_81 ) ;
V_78 = V_80 >> 16 ;
V_79 = ( V_80 >> 4 ) & 0xf ;
if ( ( V_79 == 1 ) && ( V_78 >= 0x8050 ) && ( V_78 <= 0x8055 ) )
V_43 -> V_82 = 1 ;
if ( V_4 -> V_83 & V_84 )
if ( F_25 ( V_6 , V_4 -> V_48 , 0 ) )
return - V_70 ;
if ( V_4 -> V_83 & V_85 )
if ( F_25 ( V_6 , V_4 -> V_48 , 1 ) )
return - V_70 ;
}
if ( V_4 -> V_30 ) {
#ifdef F_35
F_33 ( 0x00000008 , V_51 + V_86 ) ;
F_33 ( 0x00000080 , V_51 + V_87 ) ;
#else
F_33 ( 0x0000000c , V_51 + V_86 ) ;
F_33 ( 0x00000040 , V_51 + V_87 ) ;
#endif
F_33 ( 0x00000001 , V_51 + V_88 ) ;
}
return 0 ;
}
static int F_36 ( struct V_42 * V_43 )
{
if ( F_32 ( V_43 ) )
return - V_70 ;
return 0 ;
}
static int F_37 ( struct V_5 * V_6 )
{
struct V_42 * V_43 = F_17 ( V_6 ) ;
int V_10 ;
struct V_3 * V_4 ;
struct V_52 * V_11 ;
V_11 = V_6 -> V_40 . V_41 ;
V_4 = F_3 ( V_6 -> V_40 . V_41 ) ;
V_43 -> V_89 = V_4 -> V_89 ;
V_43 -> V_90 = V_4 -> V_90 ;
V_43 -> V_91 = V_6 -> V_24 + 0x100 ;
#ifdef F_38
V_43 -> V_92 = 1 ;
#endif
V_6 -> V_93 = 1 ;
V_10 = F_39 ( V_6 ) ;
if ( V_10 )
return V_10 ;
if ( F_40 ( V_11 -> V_20 -> V_94 ,
L_10 ) ) {
F_31 ( V_43 , V_95 ,
V_6 -> V_24 + V_96 ) ;
}
V_10 = F_36 ( V_43 ) ;
return V_10 ;
}
static int F_41 ( struct V_52 * V_11 )
{
struct V_5 * V_6 = F_42 ( V_11 ) ;
struct V_42 * V_43 = F_17 ( V_6 ) ;
struct V_3 * V_4 = F_3 ( V_11 ) ;
T_1 V_97 ;
#ifdef F_43
T_1 V_98 = F_27 ( V_43 , V_6 -> V_24 + V_99 ) ;
V_98 &= V_100 ;
V_97 = F_27 ( V_43 , V_6 -> V_24 + 0x140 ) ;
F_19 ( V_11 , L_11
L_12 , V_4 -> V_101 ,
V_4 -> V_102 , V_98 , V_97 ) ;
#endif
if ( V_4 -> V_101 ) {
F_19 ( V_11 , L_13 ) ;
V_4 -> V_102 = 1 ;
return 0 ;
}
F_19 ( V_11 , L_14 ) ;
V_43 -> V_103 = V_104 ;
V_11 -> V_105 . V_106 = V_107 ;
F_44 ( V_108 , & V_6 -> V_109 ) ;
V_97 = F_27 ( V_43 , & V_43 -> V_24 -> V_110 ) ;
V_97 &= ~ V_111 ;
F_31 ( V_43 , V_97 , & V_43 -> V_24 -> V_110 ) ;
V_4 -> V_112 = F_27 ( V_43 , & V_43 -> V_24 -> V_110 ) ;
V_4 -> V_112 &= ~ V_111 ;
V_4 -> V_113 = F_27 ( V_43 , & V_43 -> V_24 -> V_114 ) ;
V_4 -> V_115 = F_27 ( V_43 , & V_43 -> V_24 -> V_116 ) ;
V_4 -> V_117 = F_27 ( V_43 , & V_43 -> V_24 -> V_118 ) ;
V_4 -> V_119 = F_27 ( V_43 , & V_43 -> V_24 -> V_120 ) ;
V_4 -> V_121 = F_27 ( V_43 , & V_43 -> V_24 -> V_122 ) ;
V_4 -> V_123 = F_27 ( V_43 , & V_43 -> V_24 -> V_124 ) ;
V_4 -> V_125 =
F_27 ( V_43 , & V_43 -> V_24 -> V_126 ) ;
V_4 -> V_127 = F_27 ( V_43 , & V_43 -> V_24 -> V_53 [ 0 ] ) ;
V_4 -> V_128 = F_27 ( V_43 ,
V_6 -> V_24 + V_129 ) ;
V_4 -> V_127 &= F_45 ( V_43 , ~ V_130 ) ;
V_4 -> V_101 = 1 ;
V_97 = F_27 ( V_43 , & V_43 -> V_24 -> V_53 [ 0 ] ) ;
V_97 &= ~ V_131 ;
F_31 ( V_43 , V_97 , & V_43 -> V_24 -> V_53 [ 0 ] ) ;
return 0 ;
}
static int F_46 ( struct V_52 * V_11 )
{
struct V_5 * V_6 = F_42 ( V_11 ) ;
struct V_42 * V_43 = F_17 ( V_6 ) ;
struct V_3 * V_4 = F_3 ( V_11 ) ;
T_1 V_97 ;
F_19 ( V_11 , L_15 ,
V_4 -> V_101 , V_4 -> V_102 ) ;
if ( V_4 -> V_102 ) {
F_19 ( V_11 , L_13 ) ;
V_4 -> V_102 = 0 ;
return 0 ;
}
if ( ! V_4 -> V_101 ) {
F_19 ( V_11 , L_16 ) ;
return 0 ;
}
V_4 -> V_101 = 0 ;
F_19 ( V_11 , L_17 ) ;
V_97 = V_132 | ( V_4 -> V_133 ? V_134 : 0 ) ;
F_31 ( V_43 , V_97 , V_6 -> V_24 + V_99 ) ;
F_31 ( V_43 , V_4 -> V_128 ,
V_6 -> V_24 + V_129 ) ;
F_31 ( V_43 , V_135 | V_136 ,
V_6 -> V_24 + V_137 ) ;
F_31 ( V_43 , V_95 , V_6 -> V_24 + V_96 ) ;
F_31 ( V_43 , V_4 -> V_112 , & V_43 -> V_24 -> V_110 ) ;
F_31 ( V_43 , V_4 -> V_115 , & V_43 -> V_24 -> V_116 ) ;
F_31 ( V_43 , V_4 -> V_117 , & V_43 -> V_24 -> V_118 ) ;
F_31 ( V_43 , V_4 -> V_119 , & V_43 -> V_24 -> V_120 ) ;
F_31 ( V_43 , V_4 -> V_121 , & V_43 -> V_24 -> V_122 ) ;
F_31 ( V_43 , V_4 -> V_123 , & V_43 -> V_24 -> V_124 ) ;
F_31 ( V_43 , V_4 -> V_125 ,
& V_43 -> V_24 -> V_126 ) ;
F_31 ( V_43 , V_4 -> V_127 , & V_43 -> V_24 -> V_53 [ 0 ] ) ;
F_47 ( V_108 , & V_6 -> V_109 ) ;
V_43 -> V_103 = V_138 ;
V_11 -> V_105 . V_106 = V_139 ;
V_97 = F_27 ( V_43 , & V_43 -> V_24 -> V_110 ) ;
V_97 |= V_111 ;
F_31 ( V_43 , V_97 , & V_43 -> V_24 -> V_110 ) ;
F_48 ( V_6 ) ;
return 0 ;
}
static inline int F_41 ( struct V_52 * V_11 )
{
return 0 ;
}
static inline int F_46 ( struct V_52 * V_11 )
{
return 0 ;
}
static struct V_140 * F_49 ( struct V_5 * V_6 )
{
struct V_42 * V_43 = F_17 ( V_6 ) ;
return F_50 ( V_43 , struct V_140 , V_43 ) ;
}
static int F_51 ( struct V_52 * V_11 )
{
struct V_5 * V_6 = F_42 ( V_11 ) ;
struct V_140 * V_140 = F_49 ( V_6 ) ;
void T_2 * V_51 = V_6 -> V_24 ;
if ( F_40 ( V_11 -> V_20 -> V_94 ,
L_10 ) ) {
return F_41 ( V_11 ) ;
}
F_52 ( F_17 ( V_6 ) ,
F_53 ( V_11 ) ) ;
if ( ! F_54 () )
return 0 ;
V_140 -> V_141 = F_30 ( V_51 + V_33 ) ;
return 0 ;
}
static int F_55 ( struct V_52 * V_11 )
{
struct V_5 * V_6 = F_42 ( V_11 ) ;
struct V_140 * V_140 = F_49 ( V_6 ) ;
struct V_42 * V_43 = F_17 ( V_6 ) ;
void T_2 * V_51 = V_6 -> V_24 ;
if ( F_40 ( V_11 -> V_20 -> V_94 ,
L_10 ) ) {
return F_46 ( V_11 ) ;
}
F_56 ( V_43 ) ;
if ( ! F_54 () )
return 0 ;
F_57 ( V_6 -> V_40 . V_142 ) ;
F_33 ( V_140 -> V_141 , V_51 + V_33 ) ;
F_58 ( V_43 ) ;
F_36 ( V_43 ) ;
return 0 ;
}
static int F_59 ( struct V_52 * V_11 )
{
struct V_5 * V_6 = F_42 ( V_11 ) ;
F_57 ( V_6 -> V_40 . V_142 ) ;
return 0 ;
}
static int F_60 ( struct V_5 * V_6 , unsigned V_143 )
{
struct V_42 * V_43 = F_17 ( V_6 ) ;
T_1 V_114 ;
if ( ! V_143 )
return - V_70 ;
V_143 -- ;
V_114 = F_61 ( & V_43 -> V_24 -> V_53 [ V_143 ] ) ;
if ( ! ( V_114 & V_144 ) )
return - V_12 ;
if ( F_62 ( V_43 ) ) {
F_13 ( V_145 |
( V_114 & ~ ( V_146 | V_147 | V_148 ) ) ,
& V_43 -> V_24 -> V_53 [ V_143 ] ) ;
} else {
F_13 ( V_145 , & V_43 -> V_24 -> V_53 [ V_143 ] ) ;
}
return 0 ;
}
static int F_63 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_3 ( & V_2 -> V_11 ) ;
struct V_5 * V_6 = F_64 ( V_2 ) ;
if ( ! F_20 ( V_6 -> V_44 ) ) {
F_21 ( V_6 -> V_44 -> V_46 , NULL ) ;
F_23 ( V_6 -> V_44 ) ;
}
F_65 ( V_6 ) ;
if ( V_4 -> exit )
V_4 -> exit ( V_2 ) ;
F_24 ( V_6 ) ;
return 0 ;
}
static int T_3 F_66 ( void )
{
if ( F_67 () )
return - V_12 ;
F_68 ( V_149 L_18 V_150 L_19 ) ;
F_69 ( & V_19 , & V_151 ) ;
V_19 . V_152 =
L_20 ;
V_19 . V_153 = F_60 ;
return F_70 ( & V_154 ) ;
}
static void T_4 F_71 ( void )
{
F_72 ( & V_154 ) ;
}
