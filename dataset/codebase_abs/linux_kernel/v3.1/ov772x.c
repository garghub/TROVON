static struct V_1 * F_1 ( const struct V_2 * V_3 )
{
return F_2 ( F_3 ( V_3 ) , struct V_1 ,
V_4 ) ;
}
static int F_4 ( struct V_2 * V_3 ,
const struct V_5 * V_6 )
{
while ( V_6 -> V_7 != 0xff ) {
int V_8 = F_5 ( V_3 ,
V_6 -> V_7 ,
V_6 -> V_9 ) ;
if ( V_8 < 0 )
return V_8 ;
V_6 ++ ;
}
return 0 ;
}
static int F_6 ( struct V_2 * V_3 ,
T_1 V_10 ,
T_1 V_11 ,
T_1 V_12 )
{
T_2 V_13 = F_7 ( V_3 , V_10 ) ;
if ( V_13 < 0 )
return V_13 ;
V_13 &= ~ V_11 ;
V_13 |= V_12 & V_11 ;
return F_5 ( V_3 , V_10 , V_13 ) ;
}
static int F_8 ( struct V_2 * V_3 )
{
int V_8 = F_5 ( V_3 , V_14 , V_15 ) ;
F_9 ( 1 ) ;
return V_8 ;
}
static int F_10 ( struct V_16 * V_17 , int V_18 )
{
struct V_2 * V_3 = F_11 ( V_17 ) ;
struct V_1 * V_19 = F_2 ( V_17 , struct V_1 , V_4 ) ;
if ( ! V_18 ) {
F_6 ( V_3 , V_20 , V_21 , V_21 ) ;
return 0 ;
}
if ( ! V_19 -> V_22 || ! V_19 -> V_23 ) {
F_12 ( & V_3 -> V_24 , L_1 ) ;
return - V_25 ;
}
F_6 ( V_3 , V_20 , V_21 , 0 ) ;
F_13 ( & V_3 -> V_24 , L_2 ,
V_19 -> V_23 -> V_26 , V_19 -> V_22 -> V_27 ) ;
return 0 ;
}
static int F_14 ( struct V_28 * V_29 ,
unsigned long V_30 )
{
return 0 ;
}
static unsigned long F_15 ( struct V_28 * V_29 )
{
struct V_2 * V_3 = F_16 ( F_17 ( V_29 ) ) ;
struct V_1 * V_19 = F_3 ( V_3 ) ;
struct V_31 * V_32 = F_18 ( V_29 ) ;
unsigned long V_30 = V_33 | V_34 |
V_35 | V_36 |
V_37 ;
if ( V_19 -> V_38 -> V_30 & V_39 )
V_30 |= V_40 ;
else
V_30 |= V_41 ;
return F_19 ( V_32 , V_30 ) ;
}
static int F_20 ( struct V_16 * V_17 , struct V_42 * V_43 )
{
struct V_1 * V_19 = F_2 ( V_17 , struct V_1 , V_4 ) ;
switch ( V_43 -> V_44 ) {
case V_45 :
V_43 -> V_9 = V_19 -> V_46 ;
break;
case V_47 :
V_43 -> V_9 = V_19 -> V_48 ;
break;
case V_49 :
V_43 -> V_9 = V_19 -> V_50 ;
break;
}
return 0 ;
}
static int F_21 ( struct V_16 * V_17 , struct V_42 * V_43 )
{
struct V_2 * V_3 = F_11 ( V_17 ) ;
struct V_1 * V_19 = F_2 ( V_17 , struct V_1 , V_4 ) ;
int V_8 = 0 ;
T_1 V_13 ;
switch ( V_43 -> V_44 ) {
case V_45 :
V_13 = V_43 -> V_9 ? V_51 : 0x00 ;
V_19 -> V_46 = V_43 -> V_9 ;
if ( V_19 -> V_38 -> V_30 & V_52 )
V_13 ^= V_51 ;
V_8 = F_6 ( V_3 , V_53 , V_51 , V_13 ) ;
break;
case V_47 :
V_13 = V_43 -> V_9 ? V_54 : 0x00 ;
V_19 -> V_48 = V_43 -> V_9 ;
if ( V_19 -> V_38 -> V_30 & V_55 )
V_13 ^= V_54 ;
V_8 = F_6 ( V_3 , V_53 , V_54 , V_13 ) ;
break;
case V_49 :
if ( ( unsigned ) V_43 -> V_9 > 256 )
V_43 -> V_9 = 256 ;
if ( V_43 -> V_9 == V_19 -> V_50 )
break;
if ( ! V_43 -> V_9 ) {
V_8 = F_6 ( V_3 , V_56 , 0xff , 0xff ) ;
if ( ! V_8 )
V_8 = F_6 ( V_3 , V_57 ,
V_58 , 0 ) ;
} else {
V_13 = 256 - V_43 -> V_9 ;
V_8 = F_6 ( V_3 , V_57 ,
V_58 , V_58 ) ;
if ( ! V_8 )
V_8 = F_6 ( V_3 , V_56 ,
0xff , V_13 ) ;
}
if ( ! V_8 )
V_19 -> V_50 = V_43 -> V_9 ;
break;
}
return V_8 ;
}
static int F_22 ( struct V_16 * V_17 ,
struct V_59 * V_44 )
{
struct V_1 * V_19 = F_2 ( V_17 , struct V_1 , V_4 ) ;
V_44 -> V_60 = V_19 -> V_61 ;
V_44 -> V_62 = 0 ;
return 0 ;
}
static int F_23 ( struct V_16 * V_17 ,
struct V_63 * V_64 )
{
struct V_2 * V_3 = F_11 ( V_17 ) ;
int V_8 ;
V_64 -> V_65 = 1 ;
if ( V_64 -> V_64 > 0xff )
return - V_66 ;
V_8 = F_7 ( V_3 , V_64 -> V_64 ) ;
if ( V_8 < 0 )
return V_8 ;
V_64 -> V_13 = ( V_67 ) V_8 ;
return 0 ;
}
static int F_24 ( struct V_16 * V_17 ,
struct V_63 * V_64 )
{
struct V_2 * V_3 = F_11 ( V_17 ) ;
if ( V_64 -> V_64 > 0xff ||
V_64 -> V_13 > 0xff )
return - V_66 ;
return F_5 ( V_3 , V_64 -> V_64 , V_64 -> V_13 ) ;
}
static const struct V_68 * F_25 ( T_3 V_69 , T_3 V_70 )
{
T_4 V_71 ;
const struct V_68 * V_22 ;
V_71 = abs ( V_69 - V_72 . V_69 ) +
abs ( V_70 - V_72 . V_70 ) ;
V_22 = & V_72 ;
if ( V_71 >
abs ( V_69 - V_73 . V_69 ) +
abs ( V_70 - V_73 . V_70 ) )
V_22 = & V_73 ;
return V_22 ;
}
static int F_26 ( struct V_2 * V_3 , T_3 * V_69 , T_3 * V_70 ,
enum V_74 V_26 )
{
struct V_1 * V_19 = F_1 ( V_3 ) ;
int V_8 = - V_66 ;
T_1 V_13 ;
int V_75 ;
V_19 -> V_23 = NULL ;
for ( V_75 = 0 ; V_75 < F_27 ( V_76 ) ; V_75 ++ ) {
if ( V_26 == V_76 [ V_75 ] . V_26 ) {
V_19 -> V_23 = V_76 + V_75 ;
break;
}
}
if ( ! V_19 -> V_23 )
goto V_77;
V_19 -> V_22 = F_25 ( * V_69 , * V_70 ) ;
F_8 ( V_3 ) ;
if ( V_19 -> V_38 -> V_78 . V_79 & V_80 ) {
V_8 = F_6 ( V_3 , V_81 , V_82 , 0x00 ) ;
if ( V_8 < 0 )
goto V_77;
V_8 = F_6 ( V_3 ,
V_83 , V_84 ,
V_19 -> V_38 -> V_78 . V_85 ) ;
if ( V_8 < 0 )
goto V_77;
V_8 = F_6 ( V_3 ,
V_86 , V_87 ,
V_19 -> V_38 -> V_78 . V_79 ) ;
if ( V_8 < 0 )
goto V_77;
} else if ( V_19 -> V_38 -> V_78 . V_88 > V_19 -> V_38 -> V_78 . V_89 ) {
V_8 = F_6 ( V_3 ,
V_90 , V_91 ,
V_19 -> V_38 -> V_78 . V_88 ) ;
if ( V_8 < 0 )
goto V_77;
V_8 = F_6 ( V_3 ,
V_92 , V_93 ,
V_19 -> V_38 -> V_78 . V_89 ) ;
if ( V_8 < 0 )
goto V_77;
}
V_8 = F_4 ( V_3 , V_19 -> V_22 -> V_94 ) ;
if ( V_8 < 0 )
goto V_77;
V_13 = V_19 -> V_23 -> V_95 ;
if ( V_13 ) {
V_8 = F_6 ( V_3 ,
V_96 , V_97 , V_13 ) ;
if ( V_8 < 0 )
goto V_77;
}
V_13 = V_19 -> V_23 -> V_98 ;
if ( V_19 -> V_38 -> V_30 & V_52 )
V_13 |= V_51 ;
if ( V_19 -> V_38 -> V_30 & V_55 )
V_13 |= V_54 ;
if ( V_19 -> V_46 )
V_13 ^= V_51 ;
if ( V_19 -> V_48 )
V_13 ^= V_54 ;
V_8 = F_6 ( V_3 ,
V_53 , V_99 | V_100 , V_13 ) ;
if ( V_8 < 0 )
goto V_77;
V_13 = V_19 -> V_22 -> V_101 | V_19 -> V_23 -> V_102 ;
V_8 = F_6 ( V_3 ,
V_14 , V_103 | V_104 | V_105 ,
V_13 ) ;
if ( V_8 < 0 )
goto V_77;
if ( V_19 -> V_50 ) {
V_8 = F_6 ( V_3 , V_57 , V_58 , 1 ) ;
if ( ! V_8 )
V_8 = F_6 ( V_3 , V_56 ,
0xff , 256 - V_19 -> V_50 ) ;
if ( V_8 < 0 )
goto V_77;
}
* V_69 = V_19 -> V_22 -> V_69 ;
* V_70 = V_19 -> V_22 -> V_70 ;
return V_8 ;
V_77:
F_8 ( V_3 ) ;
V_19 -> V_22 = NULL ;
V_19 -> V_23 = NULL ;
return V_8 ;
}
static int F_28 ( struct V_16 * V_17 , struct V_106 * V_107 )
{
V_107 -> V_108 . V_109 = 0 ;
V_107 -> V_108 . V_110 = 0 ;
V_107 -> V_108 . V_69 = V_111 ;
V_107 -> V_108 . V_70 = V_112 ;
V_107 -> type = V_113 ;
return 0 ;
}
static int F_29 ( struct V_16 * V_17 , struct V_114 * V_107 )
{
V_107 -> V_115 . V_109 = 0 ;
V_107 -> V_115 . V_110 = 0 ;
V_107 -> V_115 . V_69 = V_111 ;
V_107 -> V_115 . V_70 = V_112 ;
V_107 -> V_116 = V_107 -> V_115 ;
V_107 -> type = V_113 ;
V_107 -> V_117 . V_118 = 1 ;
V_107 -> V_117 . V_119 = 1 ;
return 0 ;
}
static int F_30 ( struct V_16 * V_17 ,
struct V_120 * V_121 )
{
struct V_2 * V_3 = F_11 ( V_17 ) ;
struct V_1 * V_19 = F_2 ( V_17 , struct V_1 , V_4 ) ;
if ( ! V_19 -> V_22 || ! V_19 -> V_23 ) {
T_3 V_69 = V_111 , V_70 = V_112 ;
int V_8 = F_26 ( V_3 , & V_69 , & V_70 ,
V_122 ) ;
if ( V_8 < 0 )
return V_8 ;
}
V_121 -> V_69 = V_19 -> V_22 -> V_69 ;
V_121 -> V_70 = V_19 -> V_22 -> V_70 ;
V_121 -> V_26 = V_19 -> V_23 -> V_26 ;
V_121 -> V_123 = V_19 -> V_23 -> V_123 ;
V_121 -> V_124 = V_125 ;
return 0 ;
}
static int F_31 ( struct V_16 * V_17 ,
struct V_120 * V_121 )
{
struct V_2 * V_3 = F_11 ( V_17 ) ;
struct V_1 * V_19 = F_2 ( V_17 , struct V_1 , V_4 ) ;
int V_8 = F_26 ( V_3 , & V_121 -> V_69 , & V_121 -> V_70 ,
V_121 -> V_26 ) ;
if ( ! V_8 )
V_121 -> V_123 = V_19 -> V_23 -> V_123 ;
return V_8 ;
}
static int F_32 ( struct V_16 * V_17 ,
struct V_120 * V_121 )
{
struct V_1 * V_19 = F_2 ( V_17 , struct V_1 , V_4 ) ;
const struct V_68 * V_22 ;
int V_75 ;
V_22 = F_25 ( V_121 -> V_69 , V_121 -> V_70 ) ;
V_121 -> V_69 = V_22 -> V_69 ;
V_121 -> V_70 = V_22 -> V_70 ;
V_121 -> V_124 = V_125 ;
for ( V_75 = 0 ; V_75 < F_27 ( V_76 ) ; V_75 ++ )
if ( V_121 -> V_26 == V_76 [ V_75 ] . V_26 )
break;
if ( V_75 == F_27 ( V_76 ) ) {
if ( V_19 -> V_23 ) {
V_121 -> V_123 = V_19 -> V_23 -> V_123 ;
V_121 -> V_26 = V_19 -> V_23 -> V_26 ;
} else {
V_121 -> V_123 = V_76 [ 0 ] . V_123 ;
V_121 -> V_26 = V_76 [ 0 ] . V_26 ;
}
} else {
V_121 -> V_123 = V_76 [ V_75 ] . V_123 ;
}
return 0 ;
}
static int F_33 ( struct V_28 * V_29 ,
struct V_2 * V_3 )
{
struct V_1 * V_19 = F_1 ( V_3 ) ;
T_1 V_126 , V_127 ;
const char * V_128 ;
F_34 ( ! V_29 -> V_129 ||
F_35 ( V_29 -> V_129 ) -> V_130 != V_29 -> V_131 ) ;
V_126 = F_7 ( V_3 , V_132 ) ;
V_127 = F_7 ( V_3 , V_133 ) ;
switch ( F_36 ( V_126 , V_127 ) ) {
case V_134 :
V_128 = L_3 ;
V_19 -> V_61 = V_135 ;
break;
case V_136 :
V_128 = L_4 ;
V_19 -> V_61 = V_137 ;
break;
default:
F_12 ( & V_3 -> V_24 ,
L_5 , V_126 , V_127 ) ;
return - V_138 ;
}
F_37 ( & V_3 -> V_24 ,
L_6 ,
V_128 ,
V_126 ,
V_127 ,
F_7 ( V_3 , V_139 ) ,
F_7 ( V_3 , V_140 ) ) ;
return 0 ;
}
static int F_38 ( struct V_16 * V_17 , unsigned int V_141 ,
enum V_74 * V_26 )
{
if ( V_141 >= F_27 ( V_76 ) )
return - V_66 ;
* V_26 = V_76 [ V_141 ] . V_26 ;
return 0 ;
}
static int F_39 ( struct V_2 * V_3 ,
const struct V_142 * V_143 )
{
struct V_1 * V_19 ;
struct V_28 * V_29 = V_3 -> V_24 . V_144 ;
struct V_145 * V_146 = F_40 ( V_3 -> V_24 . V_129 ) ;
struct V_31 * V_32 ;
int V_8 ;
if ( ! V_29 ) {
F_12 ( & V_3 -> V_24 , L_7 ) ;
return - V_66 ;
}
V_32 = F_18 ( V_29 ) ;
if ( ! V_32 || ! V_32 -> V_19 )
return - V_66 ;
if ( ! F_41 ( V_146 , V_147 ) ) {
F_12 ( & V_146 -> V_24 ,
L_8
L_9 ) ;
return - V_148 ;
}
V_19 = F_42 ( sizeof( * V_19 ) , V_149 ) ;
if ( ! V_19 )
return - V_150 ;
V_19 -> V_38 = V_32 -> V_19 ;
F_43 ( & V_19 -> V_4 , V_3 , & V_151 ) ;
V_29 -> V_152 = & V_153 ;
V_8 = F_33 ( V_29 , V_3 ) ;
if ( V_8 ) {
V_29 -> V_152 = NULL ;
F_44 ( V_19 ) ;
}
return V_8 ;
}
static int F_45 ( struct V_2 * V_3 )
{
struct V_1 * V_19 = F_1 ( V_3 ) ;
struct V_28 * V_29 = V_3 -> V_24 . V_144 ;
V_29 -> V_152 = NULL ;
F_44 ( V_19 ) ;
return 0 ;
}
static int T_5 F_46 ( void )
{
return F_47 ( & V_154 ) ;
}
static void T_6 F_48 ( void )
{
F_49 ( & V_154 ) ;
}
