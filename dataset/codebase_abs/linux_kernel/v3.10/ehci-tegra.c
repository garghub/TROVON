static void F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 -> V_5 . V_6 ) ;
F_3 ( V_4 -> V_7 ) ;
F_4 ( V_2 -> V_8 , 0 ) ;
V_4 -> V_9 = 1 ;
}
static void F_5 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 -> V_5 . V_6 ) ;
V_4 -> V_9 = 0 ;
F_4 ( V_2 -> V_8 , 1 ) ;
F_6 ( V_4 -> V_7 ) ;
}
static int F_7 (
struct V_10 * V_11 ,
T_1 T_2 * V_12
)
{
T_1 V_13 ;
unsigned long V_14 ;
int V_15 = 0 ;
int V_16 , V_17 ;
T_1 V_18 ;
F_8 ( & V_11 -> V_19 , V_14 ) ;
V_18 = F_9 ( V_11 , & V_11 -> V_20 -> V_21 ) ;
F_10 ( V_11 , 0 , & V_11 -> V_20 -> V_21 ) ;
F_11 ( & V_11 -> V_19 , V_14 ) ;
for ( V_16 = 0 ; V_16 < 2 ; V_16 ++ ) {
V_13 = F_9 ( V_11 , V_12 ) ;
V_13 |= V_22 ;
F_10 ( V_11 , V_13 , V_12 ) ;
F_12 ( 10 ) ;
V_13 &= ~ V_22 ;
F_10 ( V_11 , V_13 , V_12 ) ;
F_12 ( 1 ) ;
V_17 = 100 ;
do {
F_12 ( 1 ) ;
V_13 = F_9 ( V_11 , V_12 ) ;
} while ( ! ( V_13 & V_23 ) && V_17 -- );
if ( V_13 & V_23 )
break;
}
if ( V_16 == 2 )
V_15 = - V_24 ;
if ( V_13 & V_25 )
F_10 ( V_11 , V_25 , V_12 ) ;
V_13 = F_9 ( V_11 , & V_11 -> V_20 -> V_26 ) ;
F_10 ( V_11 , V_13 , & V_11 -> V_20 -> V_26 ) ;
F_10 ( V_11 , V_18 , & V_11 -> V_20 -> V_21 ) ;
return V_15 ;
}
static int F_13 (
struct V_1 * V_2 ,
T_3 V_27 ,
T_3 V_28 ,
T_3 V_29 ,
char * V_30 ,
T_3 V_31
)
{
struct V_10 * V_11 = F_14 ( V_2 ) ;
struct V_3 * V_4 = F_2 ( V_2 -> V_5 . V_6 ) ;
T_1 T_2 * V_32 ;
T_1 V_13 ;
unsigned long V_14 ;
int V_15 = 0 ;
V_32 = & V_11 -> V_20 -> V_33 [ ( V_29 & 0xff ) - 1 ] ;
F_8 ( & V_11 -> V_19 , V_14 ) ;
if ( V_27 == V_34 ) {
V_13 = F_9 ( V_11 , V_32 ) ;
if ( V_4 -> V_35 && ! ( V_13 & V_36 ) ) {
V_4 -> V_35 = 0 ;
F_15 ( V_2 -> V_8 ) ;
}
}
else if ( V_27 == V_37 && V_28 == V_38 ) {
V_13 = F_9 ( V_11 , V_32 ) ;
if ( ( V_13 & V_23 ) == 0 || ( V_13 & V_22 ) != 0 ) {
V_15 = - V_39 ;
goto V_40;
}
V_13 &= ~ ( V_41 | V_42 ) ;
V_13 |= V_43 | V_44 ;
F_10 ( V_11 , V_13 | V_36 , V_32 ) ;
if ( F_16 ( V_11 , V_32 , V_36 ,
V_36 , 5000 ) )
F_17 ( L_1 , V_45 ) ;
F_18 ( ( V_29 & 0xff ) - 1 , & V_11 -> V_46 ) ;
goto V_40;
}
if ( V_4 -> V_47 &&
( V_27 == V_37 && V_28 == V_48 ) ) {
F_11 ( & V_11 -> V_19 , V_14 ) ;
return F_7 ( V_11 , V_32 ) ;
}
else if ( V_27 == V_49 &&
V_28 == V_38 ) {
V_13 = F_9 ( V_11 , V_32 ) ;
if ( ( V_13 & V_22 ) || ! ( V_13 & V_23 ) ) {
V_15 = - V_39 ;
goto V_40;
}
if ( ! ( V_13 & V_36 ) )
goto V_40;
F_19 ( V_2 -> V_8 ) ;
V_11 -> V_50 [ V_29 - 1 ] = V_51 + F_20 ( 25 ) ;
V_13 &= ~ ( V_41 | V_52 ) ;
F_10 ( V_11 , V_13 | V_53 , V_32 ) ;
F_18 ( V_29 - 1 , & V_11 -> V_54 ) ;
F_11 ( & V_11 -> V_19 , V_14 ) ;
F_21 ( 20 ) ;
F_8 ( & V_11 -> V_19 , V_14 ) ;
if ( F_16 ( V_11 , V_32 , V_53 , 0 , 2000 ) )
F_17 ( L_2 , V_45 ) ;
if ( F_16 ( V_11 , V_32 , V_36 , 0 , 2000 ) )
F_17 ( L_1 , V_45 ) ;
V_11 -> V_50 [ V_29 - 1 ] = 0 ;
F_22 ( V_29 - 1 , & V_11 -> V_54 ) ;
V_4 -> V_35 = 1 ;
goto V_40;
}
F_11 ( & V_11 -> V_19 , V_14 ) ;
return F_23 ( V_2 , V_27 , V_28 , V_29 , V_30 , V_31 ) ;
V_40:
F_11 ( & V_11 -> V_19 , V_14 ) ;
return V_15 ;
}
static void F_24 ( struct V_1 * V_2 )
{
struct V_10 * V_11 = F_14 ( V_2 ) ;
F_25 ( V_11 ) ;
F_10 ( V_11 , V_11 -> V_55 , & V_11 -> V_20 -> V_56 ) ;
F_10 ( V_11 , ( T_1 ) V_11 -> V_57 -> V_58 , & V_11 -> V_20 -> V_59 ) ;
V_11 -> V_60 &= ~ ( V_61 | V_62 | V_63 | V_64 | V_65 ) ;
V_11 -> V_60 |= V_66 ;
F_10 ( V_11 , V_11 -> V_60 , & V_11 -> V_20 -> V_60 ) ;
F_26 ( & V_67 ) ;
F_10 ( V_11 , V_68 , & V_11 -> V_20 -> V_69 ) ;
F_9 ( V_11 , & V_11 -> V_20 -> V_60 ) ;
F_27 ( & V_67 ) ;
}
static void F_28 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 -> V_5 . V_6 ) ;
if ( ! V_4 -> V_9 )
F_1 ( V_2 ) ;
F_29 ( V_2 ) ;
}
static int F_30 ( struct V_1 * V_2 )
{
struct V_10 * V_11 = F_14 ( V_2 ) ;
V_11 -> V_70 = V_2 -> V_20 + 0x100 ;
V_2 -> V_71 = 1 ;
return F_31 ( V_2 ) ;
}
static void F_32 ( struct V_72 * V_72 )
{
struct V_73 * V_13 ;
if ( ! ( V_72 -> V_74 & V_75 ) )
return;
V_13 = F_33 ( V_72 -> V_76 ,
struct V_73 , V_77 ) ;
if ( F_34 ( V_72 ) )
memcpy ( V_13 -> V_78 , V_13 -> V_77 ,
V_72 -> V_79 ) ;
V_72 -> V_76 = V_13 -> V_78 ;
F_35 ( V_13 -> V_80 ) ;
V_72 -> V_74 &= ~ V_75 ;
}
static int F_36 ( struct V_72 * V_72 , T_4 V_81 )
{
struct V_73 * V_13 , * V_80 ;
T_5 V_82 ;
if ( V_72 -> V_83 || V_72 -> V_84 ||
V_72 -> V_79 == 0 ||
! ( ( V_85 ) V_72 -> V_76 & ( V_86 - 1 ) ) )
return 0 ;
V_82 = V_72 -> V_79 +
sizeof( struct V_73 ) + V_86 - 1 ;
V_80 = F_37 ( V_82 , V_81 ) ;
if ( ! V_80 )
return - V_87 ;
V_13 = F_38 ( V_80 + 1 , V_86 ) - 1 ;
V_13 -> V_80 = V_80 ;
V_13 -> V_78 = V_72 -> V_76 ;
if ( F_39 ( V_72 ) )
memcpy ( V_13 -> V_77 , V_72 -> V_76 ,
V_72 -> V_79 ) ;
V_72 -> V_76 = V_13 -> V_77 ;
V_72 -> V_74 |= V_75 ;
return 0 ;
}
static int F_40 ( struct V_1 * V_2 , struct V_72 * V_72 ,
T_4 V_81 )
{
int V_88 ;
V_88 = F_36 ( V_72 , V_81 ) ;
if ( V_88 )
return V_88 ;
V_88 = F_41 ( V_2 , V_72 , V_81 ) ;
if ( V_88 )
F_32 ( V_72 ) ;
return V_88 ;
}
static void F_42 ( struct V_1 * V_2 , struct V_72 * V_72 )
{
F_43 ( V_2 , V_72 ) ;
F_32 ( V_72 ) ;
}
static int F_44 ( struct V_89 * V_90 ,
struct V_91 * V_92 )
{
int V_93 = 0 ;
int V_94 ;
V_94 = V_92 -> V_95 ;
if ( ! F_45 ( V_94 ) )
V_94 = F_46 ( V_90 -> V_96 . V_97 ,
L_3 , 0 ) ;
if ( ! F_45 ( V_94 ) )
return 0 ;
V_93 = F_47 ( V_94 , L_4 ) ;
if ( V_93 ) {
F_48 ( & V_90 -> V_96 , L_5 , V_94 ) ;
return V_93 ;
}
V_93 = F_49 ( V_94 , 1 ) ;
if ( V_93 ) {
F_48 ( & V_90 -> V_96 , L_6 ) ;
return V_93 ;
}
return V_93 ;
}
static int F_50 ( struct V_98 * V_96 )
{
struct V_3 * V_4 =
F_51 ( F_52 ( V_96 ) ) ;
struct V_10 * V_11 = V_4 -> V_11 ;
struct V_1 * V_2 = F_53 ( V_11 ) ;
struct V_99 T_2 * V_100 = V_11 -> V_20 ;
unsigned long V_14 ;
if ( F_54 ( V_51 , V_11 -> V_101 ) )
F_21 ( 10 ) ;
F_55 ( V_11 ) ;
F_8 ( & V_11 -> V_19 , V_14 ) ;
V_4 -> V_102 = ( F_56 ( & V_100 -> V_33 [ 0 ] ) >> 26 ) & 0x3 ;
F_22 ( V_103 , & V_2 -> V_14 ) ;
F_11 ( & V_11 -> V_19 , V_14 ) ;
F_5 ( V_2 ) ;
return 0 ;
}
static int F_57 ( struct V_98 * V_96 )
{
struct V_3 * V_4 =
F_51 ( F_52 ( V_96 ) ) ;
struct V_10 * V_11 = V_4 -> V_11 ;
struct V_1 * V_2 = F_53 ( V_11 ) ;
struct V_99 T_2 * V_100 = V_11 -> V_20 ;
unsigned long V_104 ;
F_18 ( V_103 , & V_2 -> V_14 ) ;
F_1 ( V_2 ) ;
if ( V_4 -> V_102 > V_105 ) {
F_21 ( 10 ) ;
goto V_106;
}
F_58 ( V_2 -> V_8 , V_4 -> V_102 ) ;
F_59 ( V_11 ) ;
V_104 = F_56 ( & V_100 -> V_33 [ 0 ] ) ;
V_104 |= V_107 ;
F_60 ( V_104 , & V_100 -> V_33 [ 0 ] ) ;
F_61 ( 10 ) ;
if ( ! F_56 ( & V_100 -> V_59 ) ) {
V_104 = F_56 ( & V_100 -> V_33 [ 0 ] ) ;
V_104 &= ~ F_62 ( ~ 0 ) ;
if ( V_4 -> V_102 == V_105 )
V_104 |= V_108 ;
else if ( V_4 -> V_102 == V_109 )
V_104 |= F_62 ( 6 ) ;
else if ( V_4 -> V_102 == V_110 )
V_104 |= F_62 ( 7 ) ;
F_60 ( V_104 , & V_100 -> V_33 [ 0 ] ) ;
F_61 ( 10 ) ;
V_104 = F_56 ( & V_100 -> V_33 [ 0 ] ) ;
V_104 &= ~ F_62 ( ~ 0 ) ;
F_60 ( V_104 , & V_100 -> V_33 [ 0 ] ) ;
F_61 ( 10 ) ;
}
if ( F_16 ( V_11 , & V_100 -> V_33 [ 0 ] , V_111 ,
V_111 , 2000 ) ) {
F_17 ( L_7 , V_45 ) ;
goto V_106;
}
if ( F_16 ( V_11 , & V_100 -> V_33 [ 0 ] , V_23 ,
V_23 , 2000 ) ) {
F_17 ( L_8 , V_45 ) ;
goto V_106;
}
V_104 = F_56 ( & V_100 -> V_26 ) ;
V_104 |= V_112 ;
F_60 ( V_104 , & V_100 -> V_26 ) ;
V_104 = F_56 ( & V_100 -> V_33 [ 0 ] ) ;
if ( ( V_104 & V_107 ) && ( V_104 & V_23 ) ) {
V_104 |= V_36 ;
F_60 ( V_104 , & V_100 -> V_33 [ 0 ] ) ;
if ( F_16 ( V_11 , & V_100 -> V_33 [ 0 ] , V_36 ,
V_36 , 1000 ) ) {
F_17 ( L_9 ,
V_45 ) ;
goto V_106;
}
}
F_63 ( V_2 -> V_8 ) ;
goto V_40;
V_106:
if ( V_4 -> V_102 <= V_105 )
F_63 ( V_2 -> V_8 ) ;
F_24 ( V_2 ) ;
V_40:
F_19 ( V_2 -> V_8 ) ;
V_4 -> V_35 = 1 ;
return 0 ;
}
static int F_64 ( struct V_98 * V_96 )
{
struct V_3 * V_4 =
F_51 ( F_52 ( V_96 ) ) ;
struct V_1 * V_2 = F_53 ( V_4 -> V_11 ) ;
int V_113 = 0 ;
if ( F_65 ( V_2 ) )
V_113 = F_50 ( V_96 ) ;
return V_113 ;
}
static int F_66 ( struct V_98 * V_96 )
{
int V_113 ;
V_113 = F_57 ( V_96 ) ;
if ( V_113 == 0 ) {
F_67 ( V_96 ) ;
F_68 ( V_96 ) ;
F_69 ( V_96 ) ;
}
return V_113 ;
}
static int F_70 ( struct V_98 * V_96 )
{
return F_50 ( V_96 ) ;
}
static int F_71 ( struct V_98 * V_96 )
{
return F_57 ( V_96 ) ;
}
static void F_72 ( struct V_114 * V_115 , T_6 V_116 )
{
unsigned long V_104 ;
struct V_1 * V_2 = F_73 ( V_115 -> V_117 -> V_118 ) ;
void T_2 * V_119 = V_2 -> V_20 ;
V_104 = F_56 ( V_119 + V_120 ) & ~ V_121 ;
V_104 &= ~ F_74 ( 3 ) ;
V_104 |= F_74 ( V_116 & 3 ) ;
F_60 ( V_104 , V_119 + V_120 ) ;
}
static void F_75 ( struct V_114 * V_115 , bool V_122 )
{
unsigned long V_104 ;
struct V_1 * V_2 = F_73 ( V_115 -> V_117 -> V_118 ) ;
void T_2 * V_119 = V_2 -> V_20 ;
V_104 = F_56 ( V_119 + V_120 ) & ~ V_121 ;
if ( V_122 )
V_104 |= V_123 ;
else
V_104 &= ~ V_123 ;
F_60 ( V_104 , V_119 + V_120 ) ;
}
static int F_76 ( struct V_89 * V_90 )
{
struct V_124 * V_125 ;
struct V_1 * V_2 ;
struct V_3 * V_4 ;
struct V_91 * V_92 ;
int V_93 = 0 ;
int V_126 ;
int V_127 = V_90 -> V_128 ;
struct V_114 * V_129 ;
V_92 = V_90 -> V_96 . V_130 ;
if ( ! V_92 ) {
F_48 ( & V_90 -> V_96 , L_10 ) ;
return - V_131 ;
}
if ( ! V_90 -> V_96 . V_132 )
V_90 -> V_96 . V_132 = & V_90 -> V_96 . V_133 ;
if ( ! V_90 -> V_96 . V_133 )
V_90 -> V_96 . V_133 = F_77 ( 32 ) ;
F_44 ( V_90 , V_92 ) ;
V_4 = F_78 ( & V_90 -> V_96 , sizeof( struct V_3 ) ,
V_134 ) ;
if ( ! V_4 )
return - V_87 ;
V_2 = F_79 ( & V_135 , & V_90 -> V_96 ,
F_80 ( & V_90 -> V_96 ) ) ;
if ( ! V_2 ) {
F_48 ( & V_90 -> V_96 , L_11 ) ;
return - V_87 ;
}
F_81 ( V_90 , V_4 ) ;
V_4 -> V_7 = F_82 ( & V_90 -> V_96 , NULL ) ;
if ( F_83 ( V_4 -> V_7 ) ) {
F_48 ( & V_90 -> V_96 , L_12 ) ;
V_93 = F_84 ( V_4 -> V_7 ) ;
goto V_136;
}
V_93 = F_3 ( V_4 -> V_7 ) ;
if ( V_93 )
goto V_136;
F_85 ( V_4 -> V_7 ) ;
F_61 ( 1 ) ;
F_86 ( V_4 -> V_7 ) ;
V_4 -> V_47 = F_87 ( V_90 -> V_96 . V_97 ,
L_13 ) ;
V_125 = F_88 ( V_90 , V_137 , 0 ) ;
if ( ! V_125 ) {
F_48 ( & V_90 -> V_96 , L_14 ) ;
V_93 = - V_138 ;
goto V_139;
}
V_2 -> V_140 = V_125 -> V_141 ;
V_2 -> V_142 = F_89 ( V_125 ) ;
V_2 -> V_20 = F_90 ( & V_90 -> V_96 , V_125 -> V_141 , F_89 ( V_125 ) ) ;
if ( ! V_2 -> V_20 ) {
F_48 ( & V_90 -> V_96 , L_15 ) ;
V_93 = - V_87 ;
goto V_139;
}
if ( V_127 < 0 ) {
switch ( V_125 -> V_141 ) {
case V_143 :
V_127 = 0 ;
break;
case V_144 :
V_127 = 1 ;
break;
case V_145 :
V_127 = 2 ;
break;
default:
V_93 = - V_146 ;
F_48 ( & V_90 -> V_96 , L_16 ) ;
goto V_139;
}
}
V_4 -> V_8 = F_91 ( & V_90 -> V_96 , V_127 , V_2 -> V_20 ,
V_92 -> V_147 ,
V_148 ,
F_72 ,
F_75 ) ;
if ( F_83 ( V_4 -> V_8 ) ) {
F_48 ( & V_90 -> V_96 , L_17 ) ;
V_93 = - V_138 ;
goto V_139;
}
V_2 -> V_8 = V_129 = & V_4 -> V_8 -> V_129 ;
F_92 ( V_2 -> V_8 ) ;
V_129 -> V_117 = F_78 ( & V_90 -> V_96 , sizeof( struct V_149 ) ,
V_134 ) ;
if ( ! V_129 -> V_117 ) {
F_48 ( & V_90 -> V_96 , L_18 ) ;
V_93 = - V_87 ;
goto V_139;
}
V_129 -> V_117 -> V_118 = F_93 ( V_2 ) ;
V_93 = F_4 ( V_2 -> V_8 , 0 ) ;
if ( V_93 ) {
F_48 ( & V_90 -> V_96 , L_19 ) ;
goto V_150;
}
V_4 -> V_9 = 1 ;
V_4 -> V_11 = F_14 ( V_2 ) ;
V_126 = F_94 ( V_90 , 0 ) ;
if ( ! V_126 ) {
F_48 ( & V_90 -> V_96 , L_20 ) ;
V_93 = - V_146 ;
goto V_150;
}
if ( V_92 -> V_151 == V_152 ) {
V_4 -> V_153 =
F_95 ( & V_90 -> V_96 , V_154 ) ;
if ( ! F_83 ( V_4 -> V_153 ) )
F_96 ( V_4 -> V_153 -> V_117 , & V_2 -> V_5 ) ;
} else {
V_4 -> V_153 = F_97 ( - V_146 ) ;
}
V_93 = F_98 ( V_2 , V_126 , V_155 ) ;
if ( V_93 ) {
F_48 ( & V_90 -> V_96 , L_21 ) ;
goto V_156;
}
F_68 ( & V_90 -> V_96 ) ;
F_99 ( & V_90 -> V_96 ) ;
F_100 ( & V_90 -> V_96 ) ;
F_69 ( & V_90 -> V_96 ) ;
F_101 ( & V_90 -> V_96 ) ;
return V_93 ;
V_156:
if ( ! F_83 ( V_4 -> V_153 ) )
F_96 ( V_4 -> V_153 -> V_117 , NULL ) ;
V_150:
F_102 ( V_2 -> V_8 ) ;
V_139:
F_6 ( V_4 -> V_7 ) ;
V_136:
F_103 ( V_2 ) ;
return V_93 ;
}
static int F_104 ( struct V_89 * V_90 )
{
struct V_3 * V_4 = F_51 ( V_90 ) ;
struct V_1 * V_2 = F_53 ( V_4 -> V_11 ) ;
F_105 ( & V_90 -> V_96 ) ;
F_67 ( & V_90 -> V_96 ) ;
F_106 ( & V_90 -> V_96 ) ;
if ( ! F_83 ( V_4 -> V_153 ) )
F_96 ( V_4 -> V_153 -> V_117 , NULL ) ;
F_102 ( V_2 -> V_8 ) ;
F_107 ( V_2 ) ;
F_103 ( V_2 ) ;
F_6 ( V_4 -> V_7 ) ;
return 0 ;
}
static void F_108 ( struct V_89 * V_90 )
{
struct V_3 * V_4 = F_51 ( V_90 ) ;
struct V_1 * V_2 = F_53 ( V_4 -> V_11 ) ;
if ( V_2 -> V_157 -> V_158 )
V_2 -> V_157 -> V_158 ( V_2 ) ;
}
