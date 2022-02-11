static inline struct V_1 *
F_1 ( struct V_2 * V_3 )
{
return F_2 ( V_3 , struct V_1 ,
V_3 ) ;
}
static inline struct V_1 *
F_3 ( struct V_4 * V_5 )
{
return F_2 ( V_5 , struct V_1 ,
V_5 ) ;
}
static int F_4 ( struct V_1 * V_6 ,
struct V_7 * V_8 )
{
struct V_9 V_10 ;
T_1 V_11 [ 17 ] ;
int V_12 , V_13 ;
V_13 = F_5 ( & V_10 , V_8 , false ) ;
if ( V_13 < 0 ) {
F_6 ( L_1 ) ;
return V_13 ;
}
V_13 = F_7 ( & V_10 , V_11 , sizeof( V_11 ) ) ;
if ( V_13 < 0 ) {
F_6 ( L_2 ) ;
return V_13 ;
}
for ( V_12 = 0 ; V_12 < sizeof( V_11 ) ; V_12 ++ )
F_8 ( V_11 [ V_12 ] , V_6 -> V_14 + F_9 ( V_12 ) ) ;
return 0 ;
}
static int F_10 ( struct V_2 * V_3 ,
struct V_15 * V_16 ,
struct V_17 * V_18 )
{
struct V_7 * V_8 = & V_16 -> V_8 ;
if ( V_8 -> V_19 & V_20 )
return - V_21 ;
return 0 ;
}
static void F_11 ( struct V_2 * V_3 )
{
struct V_1 * V_6 = F_1 ( V_3 ) ;
struct V_22 * V_23 = F_12 ( V_3 -> V_23 ) ;
struct V_24 * V_25 = V_23 -> V_25 ;
T_2 V_26 ;
F_13 ( L_3 ) ;
V_26 = F_14 ( V_6 -> V_14 + V_27 ) ;
V_26 &= ~ V_28 ;
F_15 ( V_26 , V_6 -> V_14 + V_27 ) ;
F_16 ( V_25 , 1 ) ;
}
static void F_17 ( struct V_2 * V_3 )
{
struct V_7 * V_8 = & V_3 -> V_23 -> V_29 -> V_30 ;
struct V_1 * V_6 = F_1 ( V_3 ) ;
struct V_22 * V_23 = F_12 ( V_3 -> V_23 ) ;
struct V_24 * V_25 = V_23 -> V_25 ;
T_2 V_26 = 0 ;
F_13 ( L_4 ) ;
F_18 ( V_25 , 1 ) ;
F_4 ( V_6 , V_8 ) ;
V_26 |= F_19 ( 0 , V_31 ) ;
V_26 |= F_19 ( 1 , V_32 ) ;
F_15 ( V_26 , V_6 -> V_14 + F_20 ( 0 ) ) ;
V_26 = V_28 ;
if ( V_6 -> V_33 )
V_26 |= V_34 ;
F_15 ( V_26 , V_6 -> V_14 + V_27 ) ;
}
static void F_21 ( struct V_2 * V_3 ,
struct V_7 * V_8 ,
struct V_7 * V_30 )
{
struct V_1 * V_6 = F_1 ( V_3 ) ;
struct V_22 * V_23 = F_12 ( V_3 -> V_23 ) ;
struct V_24 * V_25 = V_23 -> V_25 ;
unsigned int V_35 , V_36 ;
T_2 V_26 ;
F_22 ( V_25 , V_8 ) ;
F_23 ( V_25 , 1 , V_3 ) ;
F_24 ( V_25 -> V_37 , V_8 -> V_38 * 1000 ) ;
F_24 ( V_6 -> V_39 , V_8 -> V_38 * 1000 ) ;
F_24 ( V_6 -> V_40 , V_8 -> V_38 * 1000 ) ;
F_15 ( V_41 ,
V_6 -> V_14 + V_42 ) ;
F_15 ( F_25 ( V_8 -> V_43 ) |
F_26 ( V_8 -> V_44 ) ,
V_6 -> V_14 + V_45 ) ;
V_35 = V_8 -> V_46 - V_8 -> V_47 ;
V_36 = V_8 -> V_48 - V_8 -> V_49 ;
F_15 ( F_25 ( V_35 ) | F_26 ( V_36 ) ,
V_6 -> V_14 + V_50 ) ;
V_35 = V_8 -> V_47 - V_8 -> V_43 ;
V_36 = V_8 -> V_49 - V_8 -> V_44 ;
F_15 ( F_25 ( V_35 ) | F_26 ( V_36 ) ,
V_6 -> V_14 + V_51 ) ;
V_35 = V_8 -> V_52 - V_8 -> V_47 ;
V_36 = V_8 -> V_53 - V_8 -> V_49 ;
F_15 ( F_25 ( V_35 ) | F_26 ( V_36 ) ,
V_6 -> V_14 + V_54 ) ;
V_26 = V_55 ;
if ( V_8 -> V_19 & V_56 )
V_26 |= V_57 ;
if ( V_8 -> V_19 & V_58 )
V_26 |= V_59 ;
F_15 ( V_26 , V_6 -> V_14 + V_60 ) ;
}
static int F_27 ( struct V_4 * V_5 )
{
struct V_1 * V_6 = F_3 ( V_5 ) ;
struct V_61 * V_61 ;
int V_13 ;
V_61 = F_28 ( V_5 , V_6 -> V_62 ) ;
if ( ! V_61 )
return 0 ;
V_6 -> V_33 = F_29 ( V_61 ) ;
F_13 ( L_5 ,
V_6 -> V_33 ? L_6 : L_7 ) ;
F_30 ( V_5 , V_61 ) ;
F_31 ( V_6 -> V_63 , V_61 ) ;
V_13 = F_32 ( V_5 , V_61 ) ;
F_33 ( V_61 ) ;
return V_13 ;
}
static enum V_64
F_34 ( struct V_4 * V_5 , bool V_65 )
{
struct V_1 * V_6 = F_3 ( V_5 ) ;
unsigned long V_66 ;
if ( F_35 ( V_6 -> V_14 + V_67 , V_66 ,
V_66 & V_68 ,
0 , 500000 ) ) {
F_36 ( V_6 -> V_63 ) ;
return V_69 ;
}
return V_70 ;
}
static bool F_37 ( struct V_71 * V_72 )
{
struct V_1 * V_6 = F_38 ( V_72 ) ;
return F_14 ( V_6 -> V_14 + V_73 ) & V_74 ;
}
static void F_39 ( struct V_71 * V_72 )
{
struct V_1 * V_6 = F_38 ( V_72 ) ;
F_15 ( V_75 , V_6 -> V_14 + V_73 ) ;
}
static void F_40 ( struct V_71 * V_72 )
{
struct V_1 * V_6 = F_38 ( V_72 ) ;
F_15 ( 0 , V_6 -> V_14 + V_73 ) ;
}
static int F_41 ( struct V_76 * V_77 , struct V_76 * V_78 ,
void * V_79 )
{
struct V_80 * V_81 = F_42 ( V_77 ) ;
struct V_82 * V_83 = V_79 ;
struct V_84 * V_85 = V_83 -> V_86 ;
struct V_1 * V_6 ;
struct V_87 * V_88 ;
T_2 V_66 ;
int V_13 ;
V_6 = F_43 ( V_77 , sizeof( * V_6 ) , V_89 ) ;
if ( ! V_6 )
return - V_90 ;
F_44 ( V_77 , V_6 ) ;
V_6 -> V_77 = V_77 ;
V_6 -> V_85 = V_85 ;
V_88 = F_45 ( V_81 , V_91 , 0 ) ;
V_6 -> V_14 = F_46 ( V_77 , V_88 ) ;
if ( F_47 ( V_6 -> V_14 ) ) {
F_48 ( V_77 , L_8 ) ;
return F_49 ( V_6 -> V_14 ) ;
}
V_6 -> V_92 = F_50 ( V_77 , L_9 ) ;
if ( F_47 ( V_6 -> V_92 ) ) {
F_48 ( V_77 , L_10 ) ;
return F_49 ( V_6 -> V_92 ) ;
}
F_51 ( V_6 -> V_92 ) ;
V_6 -> V_39 = F_50 ( V_77 , L_11 ) ;
if ( F_47 ( V_6 -> V_39 ) ) {
F_48 ( V_77 , L_12 ) ;
V_13 = F_49 ( V_6 -> V_39 ) ;
goto V_93;
}
F_51 ( V_6 -> V_39 ) ;
V_6 -> V_94 = F_50 ( V_77 , L_13 ) ;
if ( F_47 ( V_6 -> V_94 ) ) {
F_48 ( V_77 , L_14 ) ;
V_13 = F_49 ( V_6 -> V_94 ) ;
goto V_95;
}
V_6 -> V_96 = F_50 ( V_77 , L_15 ) ;
if ( F_47 ( V_6 -> V_96 ) ) {
F_48 ( V_77 , L_16 ) ;
V_13 = F_49 ( V_6 -> V_96 ) ;
goto V_95;
}
V_13 = F_52 ( V_6 ) ;
if ( V_13 ) {
F_48 ( V_77 , L_17 ) ;
goto V_95;
}
F_15 ( V_97 , V_6 -> V_14 + V_98 ) ;
F_15 ( V_99 | V_100 |
V_101 | V_102 |
V_103 | V_104 |
V_105 | V_106 ,
V_6 -> V_14 + V_107 ) ;
V_66 = F_14 ( V_6 -> V_14 + V_108 ) ;
V_66 &= V_109 ;
V_66 |= F_53 ( 6 ) |
F_54 ( 2 ) |
V_110 |
V_111 |
V_112 |
V_113 |
V_114 |
V_115 ;
F_15 ( V_66 , V_6 -> V_14 + V_108 ) ;
V_66 = F_14 ( V_6 -> V_14 + V_116 ) ;
V_66 &= V_117 ;
V_66 |= F_55 ( 8 ) | F_56 ( 7 ) |
F_57 ( 15 ) | F_58 ( 7 ) |
F_59 ( 4 ) | V_118 |
V_119 | V_120 |
V_121 | V_122 |
V_123 ;
F_15 ( V_66 , V_6 -> V_14 + V_116 ) ;
V_13 = F_60 ( V_77 , V_6 ) ;
if ( V_13 ) {
F_48 ( V_77 , L_18 ) ;
goto V_95;
}
F_61 ( & V_6 -> V_3 ,
& V_124 ) ;
V_13 = F_62 ( V_83 ,
& V_6 -> V_3 ,
& V_125 ,
V_126 ,
NULL ) ;
if ( V_13 ) {
F_48 ( V_77 , L_19 ) ;
goto V_127;
}
V_6 -> V_3 . V_128 = F_63 ( V_83 ,
V_77 -> V_129 ) ;
if ( ! V_6 -> V_3 . V_128 ) {
V_13 = - V_130 ;
goto V_127;
}
#ifdef F_64
V_6 -> V_63 = F_65 ( & V_131 ,
V_6 , L_20 , V_132 | V_133 |
V_134 | V_135 ) ;
V_13 = F_66 ( V_6 -> V_63 ) ;
if ( V_13 < 0 )
goto V_136;
F_15 ( F_14 ( V_6 -> V_14 + V_73 ) & ~ V_137 ,
V_6 -> V_14 + V_73 ) ;
#endif
F_67 ( & V_6 -> V_5 ,
& V_138 ) ;
V_13 = F_68 ( V_83 , & V_6 -> V_5 ,
& V_139 ,
V_140 ) ;
if ( V_13 ) {
F_48 ( V_77 ,
L_21 ) ;
goto V_136;
}
V_6 -> V_5 . V_141 = V_142 |
V_143 ;
V_13 = F_69 ( V_6 -> V_63 , V_77 ) ;
if ( V_13 < 0 )
goto V_136;
F_70 ( & V_6 -> V_5 , & V_6 -> V_3 ) ;
return 0 ;
V_136:
F_71 ( V_6 -> V_63 ) ;
F_72 ( & V_6 -> V_3 ) ;
V_127:
F_73 ( V_6 -> V_62 ) ;
V_95:
F_74 ( V_6 -> V_39 ) ;
V_93:
F_74 ( V_6 -> V_92 ) ;
return V_13 ;
}
static void F_75 ( struct V_76 * V_77 , struct V_76 * V_78 ,
void * V_79 )
{
struct V_1 * V_6 = F_76 ( V_77 ) ;
F_77 ( V_6 -> V_63 ) ;
F_78 ( & V_6 -> V_5 ) ;
F_72 ( & V_6 -> V_3 ) ;
F_73 ( V_6 -> V_62 ) ;
F_74 ( V_6 -> V_39 ) ;
F_74 ( V_6 -> V_92 ) ;
}
static int F_79 ( struct V_80 * V_81 )
{
return F_80 ( & V_81 -> V_77 , & V_144 ) ;
}
static int F_81 ( struct V_80 * V_81 )
{
F_82 ( & V_81 -> V_77 , & V_144 ) ;
return 0 ;
}
