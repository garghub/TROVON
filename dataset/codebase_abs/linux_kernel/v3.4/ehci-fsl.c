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
V_40 -> V_41 = F_15 () ;
F_9 ( & V_4 -> V_13 , L_8 ,
V_8 , V_40 , V_40 -> V_41 ) ;
if ( V_40 -> V_41 ) {
V_12 = F_16 ( V_40 -> V_41 -> V_42 ,
& F_17 ( V_40 ) -> V_43 ) ;
if ( V_12 ) {
if ( V_40 -> V_41 )
F_18 ( V_40 -> V_41 -> V_13 ) ;
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
F_19 ( V_8 -> V_30 ) ;
V_32:
F_20 ( V_8 -> V_26 , V_8 -> V_27 ) ;
V_25:
F_21 ( V_8 ) ;
V_23:
F_3 ( & V_4 -> V_13 , L_10 , F_4 ( & V_4 -> V_13 ) , V_12 ) ;
if ( V_6 -> exit )
V_6 -> exit ( V_4 ) ;
return V_12 ;
}
static void F_22 ( struct V_7 * V_8 ,
struct V_3 * V_4 )
{
struct V_5 * V_6 = V_4 -> V_13 . V_14 ;
struct V_39 * V_40 = F_14 ( V_8 ) ;
if ( V_40 -> V_41 ) {
F_16 ( V_40 -> V_41 -> V_42 , NULL ) ;
F_18 ( V_40 -> V_41 -> V_13 ) ;
}
F_23 ( V_8 ) ;
if ( V_6 -> exit )
V_6 -> exit ( V_4 ) ;
F_19 ( V_8 -> V_30 ) ;
F_20 ( V_8 -> V_26 , V_8 -> V_27 ) ;
F_21 ( V_8 ) ;
}
static void F_24 ( struct V_39 * V_40 ,
enum V_44 V_45 ,
unsigned int V_46 )
{
T_1 V_47 ;
struct V_7 * V_8 = F_17 ( V_40 ) ;
void T_2 * V_48 = V_8 -> V_30 ;
struct V_5 * V_6 ;
V_6 = V_8 -> V_43 . V_49 -> V_14 ;
V_47 = F_25 ( V_40 , & V_40 -> V_30 -> V_50 [ V_46 ] ) ;
V_47 &= ~ ( V_51 | V_52 ) ;
switch ( V_45 ) {
case V_53 :
V_47 |= V_54 ;
break;
case V_55 :
V_47 |= V_56 ;
break;
case V_57 :
V_47 |= V_52 ;
case V_58 :
if ( V_6 -> V_36 )
F_11 ( V_48 + V_37 ,
V_59 ) ;
V_47 |= V_60 ;
break;
case V_61 :
break;
}
F_26 ( V_40 , V_47 , & V_40 -> V_30 -> V_50 [ V_46 ] ) ;
}
static void F_27 ( struct V_39 * V_40 )
{
struct V_7 * V_8 = F_17 ( V_40 ) ;
struct V_5 * V_6 ;
void T_2 * V_48 = V_8 -> V_30 ;
T_1 V_62 ;
V_6 = V_8 -> V_43 . V_49 -> V_14 ;
if ( V_6 -> V_36 ) {
V_62 = F_28 ( V_48 + V_37 ) ;
F_29 ( V_48 + V_37 , V_62 | 0x00000004 ) ;
F_29 ( V_48 + V_63 , 0x0 | V_64 ) ;
F_29 ( V_48 + V_65 , 0x80000000 | V_64 ) ;
}
if ( ( V_6 -> V_16 == V_17 ) ||
( V_6 -> V_16 == V_19 ) )
F_24 ( V_40 , V_6 -> V_45 , 0 ) ;
if ( V_6 -> V_16 == V_18 ) {
unsigned int V_66 , V_67 , V_68 ;
V_68 = F_30 ( V_69 ) ;
V_66 = V_68 >> 16 ;
V_67 = ( V_68 >> 4 ) & 0xf ;
if ( ( V_67 == 1 ) && ( V_66 >= 0x8050 ) && ( V_66 <= 0x8055 ) )
V_40 -> V_70 = 1 ;
if ( V_6 -> V_71 & V_72 )
F_24 ( V_40 , V_6 -> V_45 , 0 ) ;
if ( V_6 -> V_71 & V_73 )
F_24 ( V_40 , V_6 -> V_45 , 1 ) ;
}
if ( V_6 -> V_36 ) {
#ifdef F_31
F_29 ( V_48 + V_74 , 0x00000008 ) ;
F_29 ( V_48 + V_75 , 0x00000080 ) ;
#else
F_29 ( V_48 + V_74 , 0x0000000c ) ;
F_29 ( V_48 + V_75 , 0x00000040 ) ;
#endif
F_29 ( V_48 + V_76 , 0x00000001 ) ;
}
}
static int F_32 ( struct V_39 * V_40 )
{
F_27 ( V_40 ) ;
F_33 ( V_40 , 0 ) ;
return 0 ;
}
static int F_34 ( struct V_7 * V_8 )
{
struct V_39 * V_40 = F_14 ( V_8 ) ;
int V_12 ;
struct V_5 * V_6 ;
struct V_77 * V_13 ;
V_13 = V_8 -> V_43 . V_49 ;
V_6 = V_8 -> V_43 . V_49 -> V_14 ;
V_40 -> V_78 = V_6 -> V_78 ;
V_40 -> V_79 = V_6 -> V_79 ;
V_40 -> V_80 = V_8 -> V_30 + 0x100 ;
V_40 -> V_30 = V_8 -> V_30 + 0x100 +
F_35 ( V_40 , F_25 ( V_40 , & V_40 -> V_80 -> V_81 ) ) ;
F_36 ( V_40 , L_11 ) ;
F_37 ( V_40 , L_11 ) ;
V_40 -> V_82 = F_25 ( V_40 , & V_40 -> V_80 -> V_82 ) ;
V_8 -> V_83 = 1 ;
V_12 = F_38 ( V_40 ) ;
if ( V_12 )
return V_12 ;
V_12 = F_39 ( V_8 ) ;
if ( V_12 )
return V_12 ;
V_40 -> V_84 = 0x20 ;
F_40 ( V_40 ) ;
if ( F_41 ( V_13 -> V_85 -> V_86 ,
L_12 ) ) {
F_26 ( V_40 , V_87 ,
V_8 -> V_30 + V_88 ) ;
}
V_12 = F_32 ( V_40 ) ;
return V_12 ;
}
static int F_42 ( struct V_77 * V_13 )
{
struct V_7 * V_8 = F_43 ( V_13 ) ;
struct V_39 * V_40 = F_14 ( V_8 ) ;
struct V_5 * V_6 = V_13 -> V_14 ;
T_1 V_89 ;
#ifdef F_44
T_1 V_90 = F_25 ( V_40 , V_8 -> V_30 + V_91 ) ;
V_90 &= V_92 ;
V_89 = F_25 ( V_40 , V_8 -> V_30 + 0x140 ) ;
F_9 ( V_13 , L_13
L_14 , V_6 -> V_93 ,
V_6 -> V_94 , V_90 , V_89 ) ;
#endif
if ( V_6 -> V_93 ) {
F_9 ( V_13 , L_15 ) ;
V_6 -> V_94 = 1 ;
return 0 ;
}
F_9 ( V_13 , L_16 ) ;
V_40 -> V_95 = V_96 ;
V_13 -> V_97 . V_98 = V_99 ;
F_45 ( V_100 , & V_8 -> V_101 ) ;
V_89 = F_25 ( V_40 , & V_40 -> V_30 -> V_102 ) ;
V_89 &= ~ V_103 ;
F_26 ( V_40 , V_89 , & V_40 -> V_30 -> V_102 ) ;
V_6 -> V_104 = F_25 ( V_40 , & V_40 -> V_30 -> V_102 ) ;
V_6 -> V_104 &= ~ V_103 ;
V_6 -> V_105 = F_25 ( V_40 , & V_40 -> V_30 -> V_106 ) ;
V_6 -> V_107 = F_25 ( V_40 , & V_40 -> V_30 -> V_108 ) ;
V_6 -> V_109 = F_25 ( V_40 , & V_40 -> V_30 -> V_110 ) ;
V_6 -> V_111 = F_25 ( V_40 , & V_40 -> V_30 -> V_112 ) ;
V_6 -> V_113 = F_25 ( V_40 , & V_40 -> V_30 -> V_114 ) ;
V_6 -> V_115 = F_25 ( V_40 , & V_40 -> V_30 -> V_116 ) ;
V_6 -> V_117 =
F_25 ( V_40 , & V_40 -> V_30 -> V_118 ) ;
V_6 -> V_119 = F_25 ( V_40 , & V_40 -> V_30 -> V_50 [ 0 ] ) ;
V_6 -> V_120 = F_25 ( V_40 ,
V_8 -> V_30 + V_121 ) ;
V_6 -> V_119 &= F_46 ( V_40 , ~ V_122 ) ;
V_6 -> V_93 = 1 ;
V_89 = F_25 ( V_40 , & V_40 -> V_30 -> V_50 [ 0 ] ) ;
V_89 &= ~ V_123 ;
F_26 ( V_40 , V_89 , & V_40 -> V_30 -> V_50 [ 0 ] ) ;
return 0 ;
}
static int F_47 ( struct V_77 * V_13 )
{
struct V_7 * V_8 = F_43 ( V_13 ) ;
struct V_39 * V_40 = F_14 ( V_8 ) ;
struct V_5 * V_6 = V_13 -> V_14 ;
T_1 V_89 ;
F_9 ( V_13 , L_17 ,
V_6 -> V_93 , V_6 -> V_94 ) ;
if ( V_6 -> V_94 ) {
F_9 ( V_13 , L_15 ) ;
V_6 -> V_94 = 0 ;
return 0 ;
}
if ( ! V_6 -> V_93 ) {
F_9 ( V_13 , L_18 ) ;
return 0 ;
}
V_6 -> V_93 = 0 ;
F_9 ( V_13 , L_19 ) ;
V_89 = V_124 | ( V_6 -> V_125 ? V_126 : 0 ) ;
F_26 ( V_40 , V_89 , V_8 -> V_30 + V_91 ) ;
F_26 ( V_40 , V_6 -> V_120 ,
V_8 -> V_30 + V_121 ) ;
F_26 ( V_40 , V_127 | V_128 ,
V_8 -> V_30 + V_129 ) ;
F_26 ( V_40 , V_87 , V_8 -> V_30 + V_88 ) ;
F_26 ( V_40 , V_6 -> V_104 , & V_40 -> V_30 -> V_102 ) ;
F_26 ( V_40 , V_6 -> V_107 , & V_40 -> V_30 -> V_108 ) ;
F_26 ( V_40 , V_6 -> V_109 , & V_40 -> V_30 -> V_110 ) ;
F_26 ( V_40 , V_6 -> V_111 , & V_40 -> V_30 -> V_112 ) ;
F_26 ( V_40 , V_6 -> V_113 , & V_40 -> V_30 -> V_114 ) ;
F_26 ( V_40 , V_6 -> V_115 , & V_40 -> V_30 -> V_116 ) ;
F_26 ( V_40 , V_6 -> V_117 ,
& V_40 -> V_30 -> V_118 ) ;
F_26 ( V_40 , V_6 -> V_119 , & V_40 -> V_30 -> V_50 [ 0 ] ) ;
F_48 ( V_100 , & V_8 -> V_101 ) ;
V_40 -> V_95 = V_130 ;
V_13 -> V_97 . V_98 = V_131 ;
V_89 = F_25 ( V_40 , & V_40 -> V_30 -> V_102 ) ;
V_89 |= V_103 ;
F_26 ( V_40 , V_89 , & V_40 -> V_30 -> V_102 ) ;
F_49 ( V_8 ) ;
return 0 ;
}
static inline int F_42 ( struct V_77 * V_13 )
{
return 0 ;
}
static inline int F_47 ( struct V_77 * V_13 )
{
return 0 ;
}
static struct V_132 * F_50 ( struct V_7 * V_8 )
{
struct V_39 * V_40 = F_14 ( V_8 ) ;
return F_51 ( V_40 , struct V_132 , V_40 ) ;
}
static int F_52 ( struct V_77 * V_13 )
{
struct V_7 * V_8 = F_43 ( V_13 ) ;
struct V_132 * V_132 = F_50 ( V_8 ) ;
void T_2 * V_48 = V_8 -> V_30 ;
if ( F_41 ( V_13 -> V_85 -> V_86 ,
L_12 ) ) {
return F_42 ( V_13 ) ;
}
F_53 ( F_14 ( V_8 ) ,
F_54 ( V_13 ) ) ;
if ( ! F_55 () )
return 0 ;
V_132 -> V_133 = F_28 ( V_48 + V_37 ) ;
return 0 ;
}
static int F_56 ( struct V_77 * V_13 )
{
struct V_7 * V_8 = F_43 ( V_13 ) ;
struct V_132 * V_132 = F_50 ( V_8 ) ;
struct V_39 * V_40 = F_14 ( V_8 ) ;
void T_2 * V_48 = V_8 -> V_30 ;
if ( F_41 ( V_13 -> V_85 -> V_86 ,
L_12 ) ) {
return F_47 ( V_13 ) ;
}
F_57 ( V_40 ) ;
if ( ! F_55 () )
return 0 ;
F_58 ( V_8 -> V_43 . V_134 ) ;
F_29 ( V_48 + V_37 , V_132 -> V_133 ) ;
F_40 ( V_40 ) ;
F_32 ( V_40 ) ;
return 0 ;
}
static int F_59 ( struct V_77 * V_13 )
{
struct V_7 * V_8 = F_43 ( V_13 ) ;
F_58 ( V_8 -> V_43 . V_134 ) ;
return 0 ;
}
static int F_60 ( struct V_7 * V_8 , unsigned V_135 )
{
struct V_39 * V_40 = F_14 ( V_8 ) ;
T_1 V_106 ;
if ( ! V_135 )
return - V_136 ;
V_135 -- ;
V_106 = F_61 ( & V_40 -> V_30 -> V_50 [ V_135 ] ) ;
if ( ! ( V_106 & V_137 ) )
return - V_15 ;
if ( F_62 ( V_40 ) ) {
F_63 ( V_138 |
( V_106 & ~ ( V_139 | V_140 | V_141 ) ) ,
& V_40 -> V_30 -> V_50 [ V_135 ] ) ;
} else {
F_63 ( V_138 , & V_40 -> V_30 -> V_50 [ V_135 ] ) ;
}
return 0 ;
}
static int F_64 ( struct V_3 * V_4 )
{
if ( F_65 () )
return - V_15 ;
return F_1 ( & V_142 , V_4 ) ;
}
static int F_66 ( struct V_3 * V_4 )
{
struct V_7 * V_8 = F_67 ( V_4 ) ;
F_22 ( V_8 , V_4 ) ;
return 0 ;
}
