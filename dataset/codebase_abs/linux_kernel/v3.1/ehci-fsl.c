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
goto V_32;
}
if ( V_6 -> V_35 )
F_11 ( V_8 -> V_30 + V_36 , 0x4 ) ;
V_12 = F_12 ( V_8 , V_11 , V_37 | V_38 ) ;
if ( V_12 != 0 )
goto V_39;
#ifdef F_13
if ( V_6 -> V_16 == V_19 ) {
struct V_40 * V_41 = F_14 ( V_8 ) ;
V_41 -> V_42 = F_15 () ;
F_9 ( & V_4 -> V_13 , L_8 ,
V_8 , V_41 , V_41 -> V_42 ) ;
if ( V_41 -> V_42 ) {
V_12 = F_16 ( V_41 -> V_42 ,
& F_17 ( V_41 ) -> V_43 ) ;
if ( V_12 ) {
if ( V_41 -> V_42 )
F_18 ( V_41 -> V_42 -> V_13 ) ;
goto V_39;
}
} else {
F_3 ( & V_4 -> V_13 , L_9 ) ;
V_12 = - V_15 ;
goto V_39;
}
}
#endif
return V_12 ;
V_39:
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
struct V_40 * V_41 = F_14 ( V_8 ) ;
if ( V_41 -> V_42 ) {
F_16 ( V_41 -> V_42 , NULL ) ;
F_18 ( V_41 -> V_42 -> V_13 ) ;
}
F_23 ( V_8 ) ;
if ( V_6 -> exit )
V_6 -> exit ( V_4 ) ;
F_19 ( V_8 -> V_30 ) ;
F_20 ( V_8 -> V_26 , V_8 -> V_27 ) ;
F_21 ( V_8 ) ;
}
static void F_24 ( struct V_40 * V_41 ,
enum V_44 V_45 ,
unsigned int V_46 )
{
T_1 V_47 ;
V_47 = F_25 ( V_41 , & V_41 -> V_30 -> V_48 [ V_46 ] ) ;
V_47 &= ~ ( V_49 | V_50 ) ;
switch ( V_45 ) {
case V_51 :
V_47 |= V_52 ;
break;
case V_53 :
V_47 |= V_54 ;
break;
case V_55 :
V_47 |= V_50 ;
case V_56 :
V_47 |= V_57 ;
break;
case V_58 :
break;
}
F_26 ( V_41 , V_47 , & V_41 -> V_30 -> V_48 [ V_46 ] ) ;
}
static void F_27 ( struct V_40 * V_41 )
{
struct V_7 * V_8 = F_17 ( V_41 ) ;
struct V_5 * V_6 ;
void T_2 * V_59 = V_8 -> V_30 ;
T_1 V_60 ;
V_6 = V_8 -> V_43 . V_61 -> V_14 ;
if ( V_6 -> V_35 ) {
V_60 = F_28 ( V_59 + V_36 ) ;
F_29 ( V_59 + V_36 , V_60 | 0x00000004 ) ;
F_29 ( V_59 + V_62 , 0x0000001b ) ;
}
#if F_30 ( V_63 ) && ! F_30 ( V_64 )
F_29 ( V_59 + V_62 , 0x0 | V_65 ) ;
F_29 ( V_59 + V_66 , 0x80000000 | V_65 ) ;
#endif
if ( ( V_6 -> V_16 == V_17 ) ||
( V_6 -> V_16 == V_19 ) )
F_24 ( V_41 , V_6 -> V_45 , 0 ) ;
if ( V_6 -> V_16 == V_18 ) {
unsigned int V_67 , V_68 , V_69 ;
V_69 = F_31 ( V_70 ) ;
V_67 = V_69 >> 16 ;
V_68 = ( V_69 >> 4 ) & 0xf ;
if ( ( V_68 == 1 ) && ( V_67 >= 0x8050 ) && ( V_67 <= 0x8055 ) )
V_41 -> V_71 = 1 ;
if ( V_6 -> V_72 & V_73 )
F_24 ( V_41 , V_6 -> V_45 , 0 ) ;
if ( V_6 -> V_72 & V_74 )
F_24 ( V_41 , V_6 -> V_45 , 1 ) ;
}
if ( V_6 -> V_35 ) {
#ifdef F_32
F_29 ( V_59 + V_75 , 0x00000008 ) ;
F_29 ( V_59 + V_76 , 0x00000080 ) ;
#else
F_29 ( V_59 + V_75 , 0x0000000c ) ;
F_29 ( V_59 + V_76 , 0x00000040 ) ;
#endif
F_29 ( V_59 + V_77 , 0x00000001 ) ;
}
}
static int F_33 ( struct V_40 * V_41 )
{
F_27 ( V_41 ) ;
F_34 ( V_41 , 0 ) ;
return 0 ;
}
static int F_35 ( struct V_7 * V_8 )
{
struct V_40 * V_41 = F_14 ( V_8 ) ;
int V_12 ;
struct V_5 * V_6 ;
V_6 = V_8 -> V_43 . V_61 -> V_14 ;
V_41 -> V_78 = V_6 -> V_78 ;
V_41 -> V_79 = V_6 -> V_79 ;
V_41 -> V_80 = V_8 -> V_30 + 0x100 ;
V_41 -> V_30 = V_8 -> V_30 + 0x100 +
F_36 ( V_41 , F_25 ( V_41 , & V_41 -> V_80 -> V_81 ) ) ;
F_37 ( V_41 , L_11 ) ;
F_38 ( V_41 , L_11 ) ;
V_41 -> V_82 = F_25 ( V_41 , & V_41 -> V_80 -> V_82 ) ;
V_8 -> V_83 = 1 ;
V_12 = F_39 ( V_41 ) ;
if ( V_12 )
return V_12 ;
V_12 = F_40 ( V_8 ) ;
if ( V_12 )
return V_12 ;
V_41 -> V_84 = 0x20 ;
F_41 ( V_41 ) ;
V_12 = F_33 ( V_41 ) ;
return V_12 ;
}
static int F_42 ( struct V_85 * V_13 )
{
struct V_7 * V_8 = F_43 ( V_13 ) ;
struct V_40 * V_41 = F_14 ( V_8 ) ;
struct V_5 * V_6 = V_13 -> V_14 ;
T_1 V_86 ;
#ifdef F_44
T_1 V_87 = F_25 ( V_41 , V_8 -> V_30 + V_88 ) ;
V_87 &= V_89 ;
V_86 = F_25 ( V_41 , V_8 -> V_30 + 0x140 ) ;
F_9 ( V_13 , L_12
L_13 , V_6 -> V_90 ,
V_6 -> V_91 , V_87 , V_86 ) ;
#endif
if ( V_6 -> V_90 ) {
F_9 ( V_13 , L_14 ) ;
V_6 -> V_91 = 1 ;
return 0 ;
}
F_9 ( V_13 , L_15 ) ;
V_8 -> V_92 = V_93 ;
V_13 -> V_94 . V_95 = V_96 ;
F_45 ( V_97 , & V_8 -> V_98 ) ;
V_86 = F_25 ( V_41 , & V_41 -> V_30 -> V_99 ) ;
V_86 &= ~ V_100 ;
F_26 ( V_41 , V_86 , & V_41 -> V_30 -> V_99 ) ;
V_6 -> V_101 = F_25 ( V_41 , & V_41 -> V_30 -> V_99 ) ;
V_6 -> V_101 &= ~ V_100 ;
V_6 -> V_102 = F_25 ( V_41 , & V_41 -> V_30 -> V_103 ) ;
V_6 -> V_104 = F_25 ( V_41 , & V_41 -> V_30 -> V_105 ) ;
V_6 -> V_106 = F_25 ( V_41 , & V_41 -> V_30 -> V_107 ) ;
V_6 -> V_108 = F_25 ( V_41 , & V_41 -> V_30 -> V_109 ) ;
V_6 -> V_110 = F_25 ( V_41 , & V_41 -> V_30 -> V_111 ) ;
V_6 -> V_112 = F_25 ( V_41 , & V_41 -> V_30 -> V_113 ) ;
V_6 -> V_114 =
F_25 ( V_41 , & V_41 -> V_30 -> V_115 ) ;
V_6 -> V_116 = F_25 ( V_41 , & V_41 -> V_30 -> V_48 [ 0 ] ) ;
V_6 -> V_117 = F_25 ( V_41 ,
V_8 -> V_30 + V_118 ) ;
V_6 -> V_116 &= F_46 ( V_41 , ~ V_119 ) ;
V_6 -> V_90 = 1 ;
V_86 = F_25 ( V_41 , & V_41 -> V_30 -> V_48 [ 0 ] ) ;
V_86 &= ~ V_120 ;
F_26 ( V_41 , V_86 , & V_41 -> V_30 -> V_48 [ 0 ] ) ;
return 0 ;
}
static int F_47 ( struct V_85 * V_13 )
{
struct V_7 * V_8 = F_43 ( V_13 ) ;
struct V_40 * V_41 = F_14 ( V_8 ) ;
struct V_5 * V_6 = V_13 -> V_14 ;
T_1 V_86 ;
F_9 ( V_13 , L_16 ,
V_6 -> V_90 , V_6 -> V_91 ) ;
if ( V_6 -> V_91 ) {
F_9 ( V_13 , L_14 ) ;
V_6 -> V_91 = 0 ;
return 0 ;
}
if ( ! V_6 -> V_90 ) {
F_9 ( V_13 , L_17 ) ;
return 0 ;
}
V_6 -> V_90 = 0 ;
F_9 ( V_13 , L_18 ) ;
V_86 = V_121 | ( V_6 -> V_122 ? V_123 : 0 ) ;
F_26 ( V_41 , V_86 , V_8 -> V_30 + V_88 ) ;
F_26 ( V_41 , V_6 -> V_117 ,
V_8 -> V_30 + V_118 ) ;
F_26 ( V_41 , V_124 | V_125 ,
V_8 -> V_30 + V_126 ) ;
F_26 ( V_41 , V_6 -> V_101 , & V_41 -> V_30 -> V_99 ) ;
F_26 ( V_41 , V_6 -> V_104 , & V_41 -> V_30 -> V_105 ) ;
F_26 ( V_41 , V_6 -> V_106 , & V_41 -> V_30 -> V_107 ) ;
F_26 ( V_41 , V_6 -> V_108 , & V_41 -> V_30 -> V_109 ) ;
F_26 ( V_41 , V_6 -> V_110 , & V_41 -> V_30 -> V_111 ) ;
F_26 ( V_41 , V_6 -> V_112 , & V_41 -> V_30 -> V_113 ) ;
F_26 ( V_41 , V_6 -> V_114 ,
& V_41 -> V_30 -> V_115 ) ;
F_26 ( V_41 , V_6 -> V_116 , & V_41 -> V_30 -> V_48 [ 0 ] ) ;
F_48 ( V_97 , & V_8 -> V_98 ) ;
V_8 -> V_92 = V_127 ;
V_13 -> V_94 . V_95 = V_128 ;
V_86 = F_25 ( V_41 , & V_41 -> V_30 -> V_99 ) ;
V_86 |= V_100 ;
F_26 ( V_41 , V_86 , & V_41 -> V_30 -> V_99 ) ;
F_49 ( V_8 ) ;
return 0 ;
}
static inline int F_42 ( struct V_85 * V_13 )
{
return 0 ;
}
static inline int F_47 ( struct V_85 * V_13 )
{
return 0 ;
}
static struct V_129 * F_50 ( struct V_7 * V_8 )
{
struct V_40 * V_41 = F_14 ( V_8 ) ;
return F_51 ( V_41 , struct V_129 , V_41 ) ;
}
static int F_52 ( struct V_85 * V_13 )
{
struct V_7 * V_8 = F_43 ( V_13 ) ;
struct V_129 * V_129 = F_50 ( V_8 ) ;
void T_2 * V_59 = V_8 -> V_30 ;
if ( F_53 ( V_13 -> V_130 -> V_131 ,
L_19 ) ) {
return F_42 ( V_13 ) ;
}
F_54 ( F_14 ( V_8 ) ,
F_55 ( V_13 ) ) ;
if ( ! F_56 () )
return 0 ;
V_129 -> V_132 = F_28 ( V_59 + V_36 ) ;
return 0 ;
}
static int F_57 ( struct V_85 * V_13 )
{
struct V_7 * V_8 = F_43 ( V_13 ) ;
struct V_129 * V_129 = F_50 ( V_8 ) ;
struct V_40 * V_41 = F_14 ( V_8 ) ;
void T_2 * V_59 = V_8 -> V_30 ;
if ( F_53 ( V_13 -> V_130 -> V_131 ,
L_19 ) ) {
return F_47 ( V_13 ) ;
}
F_58 ( V_41 ) ;
if ( ! F_56 () )
return 0 ;
F_59 ( V_8 -> V_43 . V_133 ) ;
F_29 ( V_59 + V_36 , V_129 -> V_132 ) ;
F_41 ( V_41 ) ;
F_33 ( V_41 ) ;
return 0 ;
}
static int F_60 ( struct V_85 * V_13 )
{
struct V_7 * V_8 = F_43 ( V_13 ) ;
F_59 ( V_8 -> V_43 . V_133 ) ;
return 0 ;
}
static int F_61 ( struct V_7 * V_8 , unsigned V_134 )
{
struct V_40 * V_41 = F_14 ( V_8 ) ;
T_1 V_103 ;
if ( ! V_134 )
return - V_135 ;
V_134 -- ;
V_103 = F_62 ( & V_41 -> V_30 -> V_48 [ V_134 ] ) ;
if ( ! ( V_103 & V_136 ) )
return - V_15 ;
if ( F_63 ( V_41 ) ) {
F_64 ( V_137 |
( V_103 & ~ ( V_138 | V_139 | V_140 ) ) ,
& V_41 -> V_30 -> V_48 [ V_134 ] ) ;
} else {
F_64 ( V_137 , & V_41 -> V_30 -> V_48 [ V_134 ] ) ;
}
return 0 ;
}
static int F_65 ( struct V_3 * V_4 )
{
if ( F_66 () )
return - V_15 ;
return F_1 ( & V_141 , V_4 ) ;
}
static int F_67 ( struct V_3 * V_4 )
{
struct V_7 * V_8 = F_68 ( V_4 ) ;
F_22 ( V_8 , V_4 ) ;
return 0 ;
}
