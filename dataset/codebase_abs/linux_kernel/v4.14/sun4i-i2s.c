static int F_1 ( struct V_1 * V_2 ,
unsigned int V_3 ,
unsigned int V_4 )
{
int div = V_3 / V_4 / 2 ;
int V_5 ;
for ( V_5 = 0 ; V_5 < F_2 ( V_6 ) ; V_5 ++ ) {
const struct V_7 * V_8 = & V_6 [ V_5 ] ;
if ( V_8 -> div == div )
return V_8 -> V_9 ;
}
return - V_10 ;
}
static int F_3 ( struct V_1 * V_2 ,
unsigned int V_3 ,
unsigned int V_11 ,
unsigned int V_12 )
{
int div = V_11 / V_12 / V_3 ;
int V_5 ;
for ( V_5 = 0 ; V_5 < F_2 ( V_13 ) ; V_5 ++ ) {
const struct V_7 * V_14 = & V_13 [ V_5 ] ;
if ( V_14 -> div == div )
return V_14 -> V_9 ;
}
return - V_10 ;
}
static bool F_4 ( unsigned int V_15 )
{
int V_5 ;
for ( V_5 = 0 ; V_5 < F_2 ( V_16 ) ; V_5 ++ )
if ( V_16 [ V_5 ] == V_15 )
return true ;
return false ;
}
static int F_5 ( struct V_1 * V_2 ,
unsigned int V_17 ,
unsigned int V_4 )
{
unsigned int V_3 , V_18 ;
int V_19 , V_20 ;
int V_21 ;
switch ( V_17 ) {
case 176400 :
case 88200 :
case 44100 :
case 22050 :
case 11025 :
V_18 = 22579200 ;
break;
case 192000 :
case 128000 :
case 96000 :
case 64000 :
case 48000 :
case 32000 :
case 24000 :
case 16000 :
case 12000 :
case 8000 :
V_18 = 24576000 ;
break;
default:
return - V_10 ;
}
V_21 = F_6 ( V_2 -> V_22 , V_18 ) ;
if ( V_21 )
return V_21 ;
V_3 = V_2 -> V_23 / V_17 ;
if ( ! F_4 ( V_3 ) )
return - V_10 ;
V_19 = F_1 ( V_2 , V_3 ,
V_4 ) ;
if ( V_19 < 0 )
return - V_10 ;
V_20 = F_3 ( V_2 , V_3 ,
V_18 , V_17 ) ;
if ( V_20 < 0 )
return - V_10 ;
V_19 += V_2 -> V_24 -> V_25 ;
V_20 += V_2 -> V_24 -> V_26 ;
F_7 ( V_2 -> V_27 , V_28 ,
F_8 ( V_19 ) |
F_9 ( V_20 ) ) ;
F_10 ( V_2 -> V_29 , 1 ) ;
if ( V_2 -> V_24 -> V_30 )
F_11 ( V_2 -> V_27 , V_31 ,
V_32 ,
F_12 ( 32 ) ) ;
return 0 ;
}
static int F_13 ( struct V_33 * V_34 ,
struct V_35 * V_36 ,
struct V_37 * V_38 )
{
struct V_1 * V_2 = F_14 ( V_38 ) ;
int V_39 , V_40 , V_41 ;
T_1 V_42 ;
V_41 = F_15 ( V_36 ) ;
if ( V_41 != 2 )
return - V_10 ;
if ( V_2 -> V_24 -> V_43 ) {
F_11 ( V_2 -> V_27 , V_44 ,
V_45 ,
F_16 ( V_41 ) ) ;
F_11 ( V_2 -> V_27 , V_44 ,
V_46 ,
F_17 ( V_41 ) ) ;
}
F_10 ( V_2 -> V_47 , 0x76543210 ) ;
F_10 ( V_2 -> V_48 , 0x00003210 ) ;
F_10 ( V_2 -> V_49 ,
F_18 ( F_15 ( V_36 ) ) ) ;
F_10 ( V_2 -> V_50 ,
F_18 ( F_15 ( V_36 ) ) ) ;
if ( V_2 -> V_24 -> V_51 )
F_11 ( V_2 -> V_27 , V_52 ,
V_53 ,
F_19 ( V_41 ) ) ;
switch ( F_20 ( V_36 ) ) {
case 16 :
V_42 = V_54 ;
break;
default:
return - V_10 ;
}
V_2 -> V_55 . V_56 = V_42 ;
switch ( F_21 ( V_36 ) ) {
case 16 :
V_39 = 0 ;
V_40 = 0 ;
break;
default:
return - V_10 ;
}
F_10 ( V_2 -> V_57 ,
V_40 + V_2 -> V_24 -> V_58 ) ;
F_10 ( V_2 -> V_59 ,
V_39 + V_2 -> V_24 -> V_58 ) ;
return F_5 ( V_2 , F_22 ( V_36 ) ,
F_21 ( V_36 ) ) ;
}
static int F_23 ( struct V_37 * V_38 , unsigned int V_60 )
{
struct V_1 * V_2 = F_14 ( V_38 ) ;
T_1 V_9 ;
T_1 V_61 = 0 ;
T_1 V_62 = V_63 ;
T_1 V_64 = V_63 ;
switch ( V_60 & V_65 ) {
case V_66 :
V_9 = V_67 ;
V_61 = 1 ;
break;
case V_68 :
V_9 = V_69 ;
break;
case V_70 :
V_9 = V_71 ;
break;
default:
return - V_10 ;
}
if ( V_2 -> V_24 -> V_72 ) {
if ( V_61 > 0 )
V_9 ++ ;
F_11 ( V_2 -> V_27 , V_52 ,
V_73 ,
F_24 ( V_61 ) ) ;
}
F_10 ( V_2 -> V_74 , V_9 ) ;
switch ( V_60 & V_75 ) {
case V_76 :
V_62 = V_77 ;
V_64 = V_77 ;
break;
case V_78 :
V_62 = V_77 ;
break;
case V_79 :
V_64 = V_77 ;
break;
case V_80 :
break;
default:
return - V_10 ;
}
F_10 ( V_2 -> V_81 , V_62 ) ;
F_10 ( V_2 -> V_82 , V_64 ) ;
if ( V_2 -> V_24 -> V_83 ) {
switch ( V_60 & V_84 ) {
case V_85 :
V_9 = V_86 ;
break;
case V_87 :
V_9 = V_88 ;
break;
default:
return - V_10 ;
}
F_11 ( V_2 -> V_27 , V_89 ,
V_90 ,
V_9 ) ;
} else {
switch ( V_60 & V_84 ) {
case V_85 :
V_9 = V_91 |
V_92 ;
break;
case V_87 :
V_9 = 0 ;
break;
default:
return - V_10 ;
}
F_11 ( V_2 -> V_27 , V_89 ,
V_91 |
V_92 ,
V_9 ) ;
}
F_11 ( V_2 -> V_27 , V_93 ,
V_94 |
V_95 ,
F_25 ( 1 ) |
F_26 ( 1 ) ) ;
return 0 ;
}
static void F_27 ( struct V_1 * V_2 )
{
F_11 ( V_2 -> V_27 , V_93 ,
V_96 ,
V_96 ) ;
F_7 ( V_2 -> V_27 , V_97 , 0 ) ;
F_11 ( V_2 -> V_27 , V_89 ,
V_98 ,
V_98 ) ;
F_11 ( V_2 -> V_27 , V_99 ,
V_100 ,
V_100 ) ;
}
static void F_28 ( struct V_1 * V_2 )
{
F_11 ( V_2 -> V_27 , V_93 ,
V_101 ,
V_101 ) ;
F_7 ( V_2 -> V_27 , V_102 , 0 ) ;
F_11 ( V_2 -> V_27 , V_89 ,
V_103 ,
V_103 ) ;
F_11 ( V_2 -> V_27 , V_99 ,
V_104 ,
V_104 ) ;
}
static void F_29 ( struct V_1 * V_2 )
{
F_11 ( V_2 -> V_27 , V_89 ,
V_98 ,
0 ) ;
F_11 ( V_2 -> V_27 , V_99 ,
V_100 ,
0 ) ;
}
static void F_30 ( struct V_1 * V_2 )
{
F_11 ( V_2 -> V_27 , V_89 ,
V_103 ,
0 ) ;
F_11 ( V_2 -> V_27 , V_99 ,
V_104 ,
0 ) ;
}
static int F_31 ( struct V_33 * V_34 , int V_105 ,
struct V_37 * V_38 )
{
struct V_1 * V_2 = F_14 ( V_38 ) ;
switch ( V_105 ) {
case V_106 :
case V_107 :
case V_108 :
if ( V_34 -> V_109 == V_110 )
F_28 ( V_2 ) ;
else
F_27 ( V_2 ) ;
break;
case V_111 :
case V_112 :
case V_113 :
if ( V_34 -> V_109 == V_110 )
F_30 ( V_2 ) ;
else
F_29 ( V_2 ) ;
break;
default:
return - V_10 ;
}
return 0 ;
}
static int F_32 ( struct V_33 * V_34 ,
struct V_37 * V_38 )
{
struct V_1 * V_2 = F_14 ( V_38 ) ;
F_11 ( V_2 -> V_27 , V_89 ,
V_114 , V_114 ) ;
F_11 ( V_2 -> V_27 , V_89 ,
V_115 ,
F_33 ( 0 ) ) ;
return F_34 ( V_2 -> V_22 ) ;
}
static void F_35 ( struct V_33 * V_34 ,
struct V_37 * V_38 )
{
struct V_1 * V_2 = F_14 ( V_38 ) ;
F_36 ( V_2 -> V_22 ) ;
F_11 ( V_2 -> V_27 , V_89 ,
V_115 , 0 ) ;
F_11 ( V_2 -> V_27 , V_89 ,
V_114 , 0 ) ;
}
static int F_37 ( struct V_37 * V_38 , int V_116 ,
unsigned int V_117 , int V_118 )
{
struct V_1 * V_2 = F_14 ( V_38 ) ;
if ( V_116 != 0 )
return - V_10 ;
V_2 -> V_23 = V_117 ;
return 0 ;
}
static int F_38 ( struct V_37 * V_38 )
{
struct V_1 * V_2 = F_14 ( V_38 ) ;
F_39 ( V_38 ,
& V_2 -> V_55 ,
& V_2 -> V_119 ) ;
F_40 ( V_38 , V_2 ) ;
return 0 ;
}
static bool F_41 ( struct V_120 * V_121 , unsigned int V_122 )
{
switch ( V_122 ) {
case V_123 :
return false ;
default:
return true ;
}
}
static bool F_42 ( struct V_120 * V_121 , unsigned int V_122 )
{
switch ( V_122 ) {
case V_124 :
case V_125 :
return false ;
default:
return true ;
}
}
static bool F_43 ( struct V_120 * V_121 , unsigned int V_122 )
{
switch ( V_122 ) {
case V_124 :
case V_126 :
case V_97 :
case V_102 :
return true ;
default:
return false ;
}
}
static bool F_44 ( struct V_120 * V_121 , unsigned int V_122 )
{
switch ( V_122 ) {
case V_127 :
return false ;
default:
return true ;
}
}
static bool F_45 ( struct V_120 * V_121 , unsigned int V_122 )
{
if ( V_122 == V_128 )
return true ;
if ( V_122 == V_127 )
return false ;
return F_43 ( V_121 , V_122 ) ;
}
static int F_46 ( struct V_120 * V_121 )
{
struct V_1 * V_2 = F_47 ( V_121 ) ;
int V_21 ;
V_21 = F_34 ( V_2 -> V_129 ) ;
if ( V_21 ) {
F_48 ( V_121 , L_1 ) ;
return V_21 ;
}
F_49 ( V_2 -> V_27 , false ) ;
F_50 ( V_2 -> V_27 ) ;
V_21 = F_51 ( V_2 -> V_27 ) ;
if ( V_21 ) {
F_48 ( V_121 , L_2 ) ;
goto V_130;
}
return 0 ;
V_130:
F_36 ( V_2 -> V_129 ) ;
return V_21 ;
}
static int F_52 ( struct V_120 * V_121 )
{
struct V_1 * V_2 = F_47 ( V_121 ) ;
F_49 ( V_2 -> V_27 , true ) ;
F_36 ( V_2 -> V_129 ) ;
return 0 ;
}
static int F_53 ( struct V_120 * V_121 ,
struct V_1 * V_2 )
{
V_2 -> V_29 =
F_54 ( V_121 , V_2 -> V_27 ,
V_2 -> V_24 -> V_29 ) ;
if ( F_55 ( V_2 -> V_29 ) )
return F_56 ( V_2 -> V_29 ) ;
V_2 -> V_57 =
F_54 ( V_121 , V_2 -> V_27 ,
V_2 -> V_24 -> V_57 ) ;
if ( F_55 ( V_2 -> V_57 ) )
return F_56 ( V_2 -> V_57 ) ;
V_2 -> V_59 =
F_54 ( V_121 , V_2 -> V_27 ,
V_2 -> V_24 -> V_59 ) ;
if ( F_55 ( V_2 -> V_59 ) )
return F_56 ( V_2 -> V_59 ) ;
V_2 -> V_81 =
F_54 ( V_121 , V_2 -> V_27 ,
V_2 -> V_24 -> V_81 ) ;
if ( F_55 ( V_2 -> V_81 ) )
return F_56 ( V_2 -> V_81 ) ;
V_2 -> V_82 =
F_54 ( V_121 , V_2 -> V_27 ,
V_2 -> V_24 -> V_82 ) ;
if ( F_55 ( V_2 -> V_82 ) )
return F_56 ( V_2 -> V_82 ) ;
V_2 -> V_74 =
F_54 ( V_121 , V_2 -> V_27 ,
V_2 -> V_24 -> V_74 ) ;
if ( F_55 ( V_2 -> V_74 ) )
return F_56 ( V_2 -> V_74 ) ;
V_2 -> V_47 =
F_54 ( V_121 , V_2 -> V_27 ,
V_2 -> V_24 -> V_47 ) ;
if ( F_55 ( V_2 -> V_47 ) )
return F_56 ( V_2 -> V_47 ) ;
V_2 -> V_48 =
F_54 ( V_121 , V_2 -> V_27 ,
V_2 -> V_24 -> V_48 ) ;
if ( F_55 ( V_2 -> V_48 ) )
return F_56 ( V_2 -> V_48 ) ;
V_2 -> V_49 =
F_54 ( V_121 , V_2 -> V_27 ,
V_2 -> V_24 -> V_49 ) ;
if ( F_55 ( V_2 -> V_49 ) )
return F_56 ( V_2 -> V_49 ) ;
V_2 -> V_50 =
F_54 ( V_121 , V_2 -> V_27 ,
V_2 -> V_24 -> V_50 ) ;
return F_57 ( V_2 -> V_50 ) ;
}
static int F_58 ( struct V_131 * V_132 )
{
struct V_1 * V_2 ;
struct V_133 * V_134 ;
void T_2 * V_135 ;
int V_136 , V_21 ;
V_2 = F_59 ( & V_132 -> V_121 , sizeof( * V_2 ) , V_137 ) ;
if ( ! V_2 )
return - V_138 ;
F_60 ( V_132 , V_2 ) ;
V_134 = F_61 ( V_132 , V_139 , 0 ) ;
V_135 = F_62 ( & V_132 -> V_121 , V_134 ) ;
if ( F_55 ( V_135 ) )
return F_56 ( V_135 ) ;
V_136 = F_63 ( V_132 , 0 ) ;
if ( V_136 < 0 ) {
F_48 ( & V_132 -> V_121 , L_3 ) ;
return V_136 ;
}
V_2 -> V_24 = F_64 ( & V_132 -> V_121 ) ;
if ( ! V_2 -> V_24 ) {
F_48 ( & V_132 -> V_121 , L_4 ) ;
return - V_140 ;
}
V_2 -> V_129 = F_65 ( & V_132 -> V_121 , L_5 ) ;
if ( F_55 ( V_2 -> V_129 ) ) {
F_48 ( & V_132 -> V_121 , L_6 ) ;
return F_56 ( V_2 -> V_129 ) ;
}
V_2 -> V_27 = F_66 ( & V_132 -> V_121 , V_135 ,
V_2 -> V_24 -> V_141 ) ;
if ( F_55 ( V_2 -> V_27 ) ) {
F_48 ( & V_132 -> V_121 , L_7 ) ;
return F_56 ( V_2 -> V_27 ) ;
}
V_2 -> V_22 = F_65 ( & V_132 -> V_121 , L_8 ) ;
if ( F_55 ( V_2 -> V_22 ) ) {
F_48 ( & V_132 -> V_121 , L_9 ) ;
return F_56 ( V_2 -> V_22 ) ;
}
if ( V_2 -> V_24 -> V_142 ) {
V_2 -> V_143 = F_67 ( & V_132 -> V_121 , NULL ) ;
if ( F_55 ( V_2 -> V_143 ) ) {
F_48 ( & V_132 -> V_121 , L_10 ) ;
return F_56 ( V_2 -> V_143 ) ;
}
}
if ( ! F_55 ( V_2 -> V_143 ) ) {
V_21 = F_68 ( V_2 -> V_143 ) ;
if ( V_21 ) {
F_48 ( & V_132 -> V_121 ,
L_11 ) ;
return - V_10 ;
}
}
V_2 -> V_55 . V_144 = V_134 -> V_145 +
V_2 -> V_24 -> V_146 ;
V_2 -> V_55 . V_147 = 8 ;
V_2 -> V_119 . V_144 = V_134 -> V_145 + V_124 ;
V_2 -> V_119 . V_147 = 8 ;
F_69 ( & V_132 -> V_121 ) ;
if ( ! F_70 ( & V_132 -> V_121 ) ) {
V_21 = F_46 ( & V_132 -> V_121 ) ;
if ( V_21 )
goto V_148;
}
V_21 = F_71 ( & V_132 -> V_121 ,
& V_149 ,
& V_150 , 1 ) ;
if ( V_21 ) {
F_48 ( & V_132 -> V_121 , L_12 ) ;
goto V_151;
}
V_21 = F_72 ( & V_132 -> V_121 , NULL , 0 ) ;
if ( V_21 ) {
F_48 ( & V_132 -> V_121 , L_13 ) ;
goto V_151;
}
V_21 = F_53 ( & V_132 -> V_121 , V_2 ) ;
if ( V_21 ) {
F_48 ( & V_132 -> V_121 , L_14 ) ;
goto V_151;
}
return 0 ;
V_151:
if ( ! F_73 ( & V_132 -> V_121 ) )
F_52 ( & V_132 -> V_121 ) ;
V_148:
F_74 ( & V_132 -> V_121 ) ;
if ( ! F_55 ( V_2 -> V_143 ) )
F_75 ( V_2 -> V_143 ) ;
return V_21 ;
}
static int F_76 ( struct V_131 * V_132 )
{
struct V_1 * V_2 = F_47 ( & V_132 -> V_121 ) ;
F_77 ( & V_132 -> V_121 ) ;
F_74 ( & V_132 -> V_121 ) ;
if ( ! F_73 ( & V_132 -> V_121 ) )
F_52 ( & V_132 -> V_121 ) ;
if ( ! F_55 ( V_2 -> V_143 ) )
F_75 ( V_2 -> V_143 ) ;
return 0 ;
}
