static int F_1 ( const struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_5 * V_6 ;
struct V_7 * V_8 ;
struct V_9 * V_10 ;
int V_11 ;
int V_12 ;
F_2 ( L_1 ) ;
V_6 = (struct V_5 * ) V_4 -> V_13 . V_14 ;
if ( ! V_6 ) {
F_3 ( & V_4 -> V_13 ,
L_2 , F_4 ( & V_4 -> V_13 ) ) ;
return - V_15 ;
}
if ( ! ( ( V_6 -> V_16 == V_17 ) ||
( V_6 -> V_16 == V_18 ) ||
( V_6 -> V_16 == V_19 ) ) ) {
F_3 ( & V_4 -> V_13 ,
L_3 ,
F_4 ( & V_4 -> V_13 ) ) ;
return - V_15 ;
}
V_10 = F_5 ( V_4 , V_20 , 0 ) ;
if ( ! V_10 ) {
F_3 ( & V_4 -> V_13 ,
L_4 ,
F_4 ( & V_4 -> V_13 ) ) ;
return - V_15 ;
}
V_11 = V_10 -> V_21 ;
V_8 = F_6 ( V_2 , & V_4 -> V_13 , F_4 ( & V_4 -> V_13 ) ) ;
if ( ! V_8 ) {
V_12 = - V_22 ;
goto V_23;
}
V_10 = F_5 ( V_4 , V_24 , 0 ) ;
if ( ! V_10 ) {
F_3 ( & V_4 -> V_13 ,
L_5 ,
F_4 ( & V_4 -> V_13 ) ) ;
V_12 = - V_15 ;
goto V_25;
}
V_8 -> V_26 = V_10 -> V_21 ;
V_8 -> V_27 = F_7 ( V_10 ) ;
if ( ! F_8 ( V_8 -> V_26 , V_8 -> V_27 ,
V_2 -> V_28 ) ) {
F_9 ( & V_4 -> V_13 , L_6 ) ;
V_12 = - V_29 ;
goto V_25;
}
V_8 -> V_30 = F_10 ( V_8 -> V_26 , V_8 -> V_27 ) ;
if ( V_8 -> V_30 == NULL ) {
F_9 ( & V_4 -> V_13 , L_7 ) ;
V_12 = - V_31 ;
goto V_32;
}
V_6 -> V_30 = V_8 -> V_30 ;
if ( V_6 -> V_33 )
V_8 -> V_33 = V_6 -> V_33 ;
if ( V_6 -> V_34 && V_6 -> V_34 ( V_4 ) ) {
V_12 = - V_15 ;
goto V_35;
}
if ( V_6 -> V_36 )
F_11 ( V_8 -> V_30 + V_37 , 0x4 ) ;
V_12 = F_12 ( V_8 , V_11 , V_38 ) ;
if ( V_12 != 0 )
goto V_35;
#ifdef F_13
if ( V_6 -> V_16 == V_19 ) {
struct V_39 * V_40 = F_14 ( V_8 ) ;
V_8 -> V_41 = F_15 ( V_42 ) ;
F_9 ( & V_4 -> V_13 , L_8 ,
V_8 , V_40 , V_8 -> V_41 ) ;
if ( ! F_16 ( V_8 -> V_41 ) ) {
V_12 = F_17 ( V_8 -> V_41 -> V_43 ,
& F_18 ( V_40 ) -> V_44 ) ;
if ( V_12 ) {
F_19 ( V_8 -> V_41 ) ;
goto V_35;
}
} else {
F_3 ( & V_4 -> V_13 , L_9 ) ;
V_12 = - V_15 ;
goto V_35;
}
}
#endif
return V_12 ;
V_35:
F_20 ( V_8 -> V_30 ) ;
V_32:
F_21 ( V_8 -> V_26 , V_8 -> V_27 ) ;
V_25:
F_22 ( V_8 ) ;
V_23:
F_3 ( & V_4 -> V_13 , L_10 , F_4 ( & V_4 -> V_13 ) , V_12 ) ;
if ( V_6 -> exit )
V_6 -> exit ( V_4 ) ;
return V_12 ;
}
static void F_23 ( struct V_7 * V_8 ,
struct V_3 * V_4 )
{
struct V_5 * V_6 = V_4 -> V_13 . V_14 ;
if ( ! F_16 ( V_8 -> V_41 ) ) {
F_17 ( V_8 -> V_41 -> V_43 , NULL ) ;
F_19 ( V_8 -> V_41 ) ;
}
F_24 ( V_8 ) ;
if ( V_6 -> exit )
V_6 -> exit ( V_4 ) ;
F_20 ( V_8 -> V_30 ) ;
F_21 ( V_8 -> V_26 , V_8 -> V_27 ) ;
F_22 ( V_8 ) ;
}
static void F_25 ( struct V_7 * V_8 ,
enum V_45 V_46 ,
unsigned int V_47 )
{
T_1 V_48 , V_49 ;
struct V_39 * V_40 = F_14 ( V_8 ) ;
void T_2 * V_50 = V_8 -> V_30 ;
struct V_51 * V_13 = V_8 -> V_44 . V_52 ;
struct V_5 * V_6 = V_13 -> V_14 ;
if ( V_6 -> V_53 < 0 ) {
F_26 ( V_8 -> V_44 . V_52 , L_11 ) ;
return;
}
V_48 = F_27 ( V_40 , & V_40 -> V_30 -> V_54 [ V_47 ] ) ;
V_48 &= ~ ( V_55 | V_56 ) ;
switch ( V_46 ) {
case V_57 :
if ( V_6 -> V_53 ) {
V_49 = F_28 ( V_50 + V_37 ) ;
F_29 ( V_50 + V_37 , V_49 |
V_58 | V_59 ) ;
}
V_48 |= V_60 ;
break;
case V_61 :
V_48 |= V_62 ;
break;
case V_63 :
V_48 |= V_56 ;
case V_64 :
if ( V_6 -> V_53 ) {
V_49 = F_28 ( V_50 + V_37 ) ;
F_29 ( V_50 + V_37 , V_49 |
V_65 | V_58 ) ;
F_30 ( V_66 ) ;
}
if ( V_6 -> V_36 )
F_11 ( V_50 + V_37 ,
V_67 ) ;
V_48 |= V_68 ;
break;
case V_69 :
break;
}
F_31 ( V_40 , V_48 , & V_40 -> V_30 -> V_54 [ V_47 ] ) ;
}
static void F_32 ( struct V_39 * V_40 )
{
struct V_7 * V_8 = F_18 ( V_40 ) ;
struct V_5 * V_6 ;
void T_2 * V_50 = V_8 -> V_30 ;
T_1 V_49 ;
V_6 = V_8 -> V_44 . V_52 -> V_14 ;
if ( V_6 -> V_36 ) {
V_49 = F_28 ( V_50 + V_37 ) ;
F_29 ( V_50 + V_37 , V_49 | 0x00000004 ) ;
F_29 ( V_50 + V_70 , 0x0 | V_71 ) ;
F_29 ( V_50 + V_72 , 0x80000000 | V_71 ) ;
}
if ( ( V_6 -> V_16 == V_17 ) ||
( V_6 -> V_16 == V_19 ) )
F_25 ( V_8 , V_6 -> V_46 , 0 ) ;
if ( V_6 -> V_16 == V_18 ) {
unsigned int V_73 , V_74 , V_75 ;
V_75 = F_33 ( V_76 ) ;
V_73 = V_75 >> 16 ;
V_74 = ( V_75 >> 4 ) & 0xf ;
if ( ( V_74 == 1 ) && ( V_73 >= 0x8050 ) && ( V_73 <= 0x8055 ) )
V_40 -> V_77 = 1 ;
if ( V_6 -> V_78 & V_79 )
F_25 ( V_8 , V_6 -> V_46 , 0 ) ;
if ( V_6 -> V_78 & V_80 )
F_25 ( V_8 , V_6 -> V_46 , 1 ) ;
}
if ( V_6 -> V_36 ) {
#ifdef F_34
F_29 ( V_50 + V_81 , 0x00000008 ) ;
F_29 ( V_50 + V_82 , 0x00000080 ) ;
#else
F_29 ( V_50 + V_81 , 0x0000000c ) ;
F_29 ( V_50 + V_82 , 0x00000040 ) ;
#endif
F_29 ( V_50 + V_83 , 0x00000001 ) ;
}
}
static int F_35 ( struct V_39 * V_40 )
{
F_32 ( V_40 ) ;
F_36 ( V_40 , 0 ) ;
return 0 ;
}
static int F_37 ( struct V_7 * V_8 )
{
struct V_39 * V_40 = F_14 ( V_8 ) ;
int V_12 ;
struct V_5 * V_6 ;
struct V_51 * V_13 ;
V_13 = V_8 -> V_44 . V_52 ;
V_6 = V_8 -> V_44 . V_52 -> V_14 ;
V_40 -> V_84 = V_6 -> V_84 ;
V_40 -> V_85 = V_6 -> V_85 ;
V_40 -> V_86 = V_8 -> V_30 + 0x100 ;
V_8 -> V_87 = 1 ;
V_12 = F_38 ( V_8 ) ;
if ( V_12 )
return V_12 ;
if ( F_39 ( V_13 -> V_88 -> V_89 ,
L_12 ) ) {
F_31 ( V_40 , V_90 ,
V_8 -> V_30 + V_91 ) ;
}
V_12 = F_35 ( V_40 ) ;
return V_12 ;
}
static int F_40 ( struct V_51 * V_13 )
{
struct V_7 * V_8 = F_41 ( V_13 ) ;
struct V_39 * V_40 = F_14 ( V_8 ) ;
struct V_5 * V_6 = V_13 -> V_14 ;
T_1 V_92 ;
#ifdef F_42
T_1 V_93 = F_27 ( V_40 , V_8 -> V_30 + V_94 ) ;
V_93 &= V_95 ;
V_92 = F_27 ( V_40 , V_8 -> V_30 + 0x140 ) ;
F_9 ( V_13 , L_13
L_14 , V_6 -> V_96 ,
V_6 -> V_97 , V_93 , V_92 ) ;
#endif
if ( V_6 -> V_96 ) {
F_9 ( V_13 , L_15 ) ;
V_6 -> V_97 = 1 ;
return 0 ;
}
F_9 ( V_13 , L_16 ) ;
V_40 -> V_98 = V_99 ;
V_13 -> V_100 . V_101 = V_102 ;
F_43 ( V_103 , & V_8 -> V_104 ) ;
V_92 = F_27 ( V_40 , & V_40 -> V_30 -> V_105 ) ;
V_92 &= ~ V_106 ;
F_31 ( V_40 , V_92 , & V_40 -> V_30 -> V_105 ) ;
V_6 -> V_107 = F_27 ( V_40 , & V_40 -> V_30 -> V_105 ) ;
V_6 -> V_107 &= ~ V_106 ;
V_6 -> V_108 = F_27 ( V_40 , & V_40 -> V_30 -> V_109 ) ;
V_6 -> V_110 = F_27 ( V_40 , & V_40 -> V_30 -> V_111 ) ;
V_6 -> V_112 = F_27 ( V_40 , & V_40 -> V_30 -> V_113 ) ;
V_6 -> V_114 = F_27 ( V_40 , & V_40 -> V_30 -> V_115 ) ;
V_6 -> V_116 = F_27 ( V_40 , & V_40 -> V_30 -> V_117 ) ;
V_6 -> V_118 = F_27 ( V_40 , & V_40 -> V_30 -> V_119 ) ;
V_6 -> V_120 =
F_27 ( V_40 , & V_40 -> V_30 -> V_121 ) ;
V_6 -> V_122 = F_27 ( V_40 , & V_40 -> V_30 -> V_54 [ 0 ] ) ;
V_6 -> V_123 = F_27 ( V_40 ,
V_8 -> V_30 + V_124 ) ;
V_6 -> V_122 &= F_44 ( V_40 , ~ V_125 ) ;
V_6 -> V_96 = 1 ;
V_92 = F_27 ( V_40 , & V_40 -> V_30 -> V_54 [ 0 ] ) ;
V_92 &= ~ V_126 ;
F_31 ( V_40 , V_92 , & V_40 -> V_30 -> V_54 [ 0 ] ) ;
return 0 ;
}
static int F_45 ( struct V_51 * V_13 )
{
struct V_7 * V_8 = F_41 ( V_13 ) ;
struct V_39 * V_40 = F_14 ( V_8 ) ;
struct V_5 * V_6 = V_13 -> V_14 ;
T_1 V_92 ;
F_9 ( V_13 , L_17 ,
V_6 -> V_96 , V_6 -> V_97 ) ;
if ( V_6 -> V_97 ) {
F_9 ( V_13 , L_15 ) ;
V_6 -> V_97 = 0 ;
return 0 ;
}
if ( ! V_6 -> V_96 ) {
F_9 ( V_13 , L_18 ) ;
return 0 ;
}
V_6 -> V_96 = 0 ;
F_9 ( V_13 , L_19 ) ;
V_92 = V_127 | ( V_6 -> V_128 ? V_129 : 0 ) ;
F_31 ( V_40 , V_92 , V_8 -> V_30 + V_94 ) ;
F_31 ( V_40 , V_6 -> V_123 ,
V_8 -> V_30 + V_124 ) ;
F_31 ( V_40 , V_130 | V_131 ,
V_8 -> V_30 + V_132 ) ;
F_31 ( V_40 , V_90 , V_8 -> V_30 + V_91 ) ;
F_31 ( V_40 , V_6 -> V_107 , & V_40 -> V_30 -> V_105 ) ;
F_31 ( V_40 , V_6 -> V_110 , & V_40 -> V_30 -> V_111 ) ;
F_31 ( V_40 , V_6 -> V_112 , & V_40 -> V_30 -> V_113 ) ;
F_31 ( V_40 , V_6 -> V_114 , & V_40 -> V_30 -> V_115 ) ;
F_31 ( V_40 , V_6 -> V_116 , & V_40 -> V_30 -> V_117 ) ;
F_31 ( V_40 , V_6 -> V_118 , & V_40 -> V_30 -> V_119 ) ;
F_31 ( V_40 , V_6 -> V_120 ,
& V_40 -> V_30 -> V_121 ) ;
F_31 ( V_40 , V_6 -> V_122 , & V_40 -> V_30 -> V_54 [ 0 ] ) ;
F_46 ( V_103 , & V_8 -> V_104 ) ;
V_40 -> V_98 = V_133 ;
V_13 -> V_100 . V_101 = V_134 ;
V_92 = F_27 ( V_40 , & V_40 -> V_30 -> V_105 ) ;
V_92 |= V_106 ;
F_31 ( V_40 , V_92 , & V_40 -> V_30 -> V_105 ) ;
F_47 ( V_8 ) ;
return 0 ;
}
static inline int F_40 ( struct V_51 * V_13 )
{
return 0 ;
}
static inline int F_45 ( struct V_51 * V_13 )
{
return 0 ;
}
static struct V_135 * F_48 ( struct V_7 * V_8 )
{
struct V_39 * V_40 = F_14 ( V_8 ) ;
return F_49 ( V_40 , struct V_135 , V_40 ) ;
}
static int F_50 ( struct V_51 * V_13 )
{
struct V_7 * V_8 = F_41 ( V_13 ) ;
struct V_135 * V_135 = F_48 ( V_8 ) ;
void T_2 * V_50 = V_8 -> V_30 ;
if ( F_39 ( V_13 -> V_88 -> V_89 ,
L_12 ) ) {
return F_40 ( V_13 ) ;
}
F_51 ( F_14 ( V_8 ) ,
F_52 ( V_13 ) ) ;
if ( ! F_53 () )
return 0 ;
V_135 -> V_136 = F_28 ( V_50 + V_37 ) ;
return 0 ;
}
static int F_54 ( struct V_51 * V_13 )
{
struct V_7 * V_8 = F_41 ( V_13 ) ;
struct V_135 * V_135 = F_48 ( V_8 ) ;
struct V_39 * V_40 = F_14 ( V_8 ) ;
void T_2 * V_50 = V_8 -> V_30 ;
if ( F_39 ( V_13 -> V_88 -> V_89 ,
L_12 ) ) {
return F_45 ( V_13 ) ;
}
F_55 ( V_40 ) ;
if ( ! F_53 () )
return 0 ;
F_56 ( V_8 -> V_44 . V_137 ) ;
F_29 ( V_50 + V_37 , V_135 -> V_136 ) ;
F_57 ( V_40 ) ;
F_35 ( V_40 ) ;
return 0 ;
}
static int F_58 ( struct V_51 * V_13 )
{
struct V_7 * V_8 = F_41 ( V_13 ) ;
F_56 ( V_8 -> V_44 . V_137 ) ;
return 0 ;
}
static int F_59 ( struct V_7 * V_8 , unsigned V_138 )
{
struct V_39 * V_40 = F_14 ( V_8 ) ;
T_1 V_109 ;
if ( ! V_138 )
return - V_139 ;
V_138 -- ;
V_109 = F_60 ( & V_40 -> V_30 -> V_54 [ V_138 ] ) ;
if ( ! ( V_109 & V_140 ) )
return - V_15 ;
if ( F_61 ( V_40 ) ) {
F_62 ( V_141 |
( V_109 & ~ ( V_142 | V_143 | V_144 ) ) ,
& V_40 -> V_30 -> V_54 [ V_138 ] ) ;
} else {
F_62 ( V_141 , & V_40 -> V_30 -> V_54 [ V_138 ] ) ;
}
return 0 ;
}
static int F_63 ( struct V_3 * V_4 )
{
if ( F_64 () )
return - V_15 ;
return F_1 ( & V_145 , V_4 ) ;
}
static int F_65 ( struct V_3 * V_4 )
{
struct V_7 * V_8 = F_66 ( V_4 ) ;
F_23 ( V_8 , V_4 ) ;
return 0 ;
}
