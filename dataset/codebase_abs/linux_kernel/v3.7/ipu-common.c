static inline T_1 F_1 ( struct V_1 * V_2 , unsigned V_3 )
{
return F_2 ( V_2 -> V_4 + V_3 ) ;
}
static inline void F_3 ( struct V_1 * V_2 , T_1 V_5 , unsigned V_3 )
{
F_4 ( V_5 , V_2 -> V_4 + V_3 ) ;
}
static inline T_1 F_5 ( struct V_1 * V_2 , unsigned V_3 )
{
return F_2 ( V_2 -> V_6 + V_3 ) ;
}
static inline void F_6 ( struct V_1 * V_2 , T_1 V_5 ,
unsigned V_3 )
{
F_4 ( V_5 , V_2 -> V_6 + V_3 ) ;
}
void F_7 ( struct V_1 * V_2 )
{
T_1 V_7 ;
V_7 = F_1 ( V_2 , V_8 ) ;
V_7 |= 0x8 ;
F_3 ( V_2 , V_7 , V_8 ) ;
}
struct V_9 T_2 * F_8 ( struct V_10 * V_11 )
{
struct V_1 * V_2 = V_11 -> V_2 ;
return V_2 -> V_12 + V_11 -> V_13 ;
}
void F_9 ( struct V_10 * V_11 )
{
struct V_1 * V_2 = V_11 -> V_2 ;
struct V_9 T_2 * V_14 = F_8 ( V_11 ) ;
T_1 V_7 ;
if ( V_2 -> V_15 == V_16 )
F_10 ( V_14 , V_17 , 1 ) ;
V_7 = F_5 ( V_2 , F_11 ( V_11 -> V_13 ) ) ;
V_7 |= 1 << ( V_11 -> V_13 % 32 ) ;
F_6 ( V_2 , V_7 , F_11 ( V_11 -> V_13 ) ) ;
}
void F_10 ( struct V_9 T_2 * V_18 , T_1 V_19 , T_1 V_20 )
{
T_1 V_21 = ( V_19 >> 8 ) % 160 ;
T_1 V_22 = V_19 & 0xff ;
T_1 V_23 = ( V_19 >> 8 ) / 160 ;
T_1 V_24 = V_21 / 32 ;
T_1 V_25 = V_21 % 32 ;
T_1 V_26 = ( 1 << V_22 ) - 1 ;
T_1 V_7 ;
F_12 ( L_1 , V_27 , V_23 , V_21 , V_22 ) ;
V_7 = F_2 ( & V_18 -> V_23 [ V_23 ] . V_28 [ V_24 ] ) ;
V_7 &= ~ ( V_26 << V_25 ) ;
V_7 |= V_20 << V_25 ;
F_4 ( V_7 , & V_18 -> V_23 [ V_23 ] . V_28 [ V_24 ] ) ;
if ( ( V_21 + V_22 - 1 ) / 32 > V_24 ) {
V_7 = F_2 ( & V_18 -> V_23 [ V_23 ] . V_28 [ V_24 + 1 ] ) ;
V_7 &= ~ ( V_26 >> ( V_25 ? ( 32 - V_25 ) : 0 ) ) ;
V_7 |= V_20 >> ( V_25 ? ( 32 - V_25 ) : 0 ) ;
F_4 ( V_7 , & V_18 -> V_23 [ V_23 ] . V_28 [ V_24 + 1 ] ) ;
}
}
T_1 F_13 ( struct V_9 T_2 * V_18 , T_1 V_19 )
{
T_1 V_21 = ( V_19 >> 8 ) % 160 ;
T_1 V_22 = V_19 & 0xff ;
T_1 V_23 = ( V_19 >> 8 ) / 160 ;
T_1 V_24 = V_21 / 32 ;
T_1 V_25 = V_21 % 32 ;
T_1 V_26 = ( 1 << V_22 ) - 1 ;
T_1 V_7 = 0 ;
F_12 ( L_1 , V_27 , V_23 , V_21 , V_22 ) ;
V_7 = ( F_2 ( & V_18 -> V_23 [ V_23 ] . V_28 [ V_24 ] ) >> V_25 ) & V_26 ;
if ( ( V_21 + V_22 - 1 ) / 32 > V_24 ) {
T_1 V_29 ;
V_29 = F_2 ( & V_18 -> V_23 [ V_23 ] . V_28 [ V_24 + 1 ] ) ;
V_29 &= V_26 >> ( V_25 ? ( 32 - V_25 ) : 0 ) ;
V_7 |= V_29 << ( V_25 ? ( 32 - V_25 ) : 0 ) ;
}
return V_7 ;
}
int F_14 ( struct V_9 T_2 * V_14 ,
struct V_30 * V_31 )
{
int V_32 = 0 , V_33 = 0 , V_34 , V_35 , V_36 , V_37 ;
V_34 = V_31 -> V_38 - V_31 -> V_39 . V_40 - V_31 -> V_39 . V_3 ;
V_35 = V_31 -> V_38 - V_31 -> V_41 . V_40 - V_31 -> V_41 . V_3 ;
V_36 = V_31 -> V_38 - V_31 -> V_42 . V_40 - V_31 -> V_42 . V_3 ;
V_37 = V_31 -> V_38 - V_31 -> V_43 . V_40 - V_31 -> V_43 . V_3 ;
F_10 ( V_14 , V_44 , V_31 -> V_39 . V_40 - 1 ) ;
F_10 ( V_14 , V_45 , V_34 ) ;
F_10 ( V_14 , V_46 , V_31 -> V_41 . V_40 - 1 ) ;
F_10 ( V_14 , V_47 , V_35 ) ;
F_10 ( V_14 , V_48 , V_31 -> V_42 . V_40 - 1 ) ;
F_10 ( V_14 , V_49 , V_36 ) ;
if ( V_31 -> V_43 . V_40 ) {
F_10 ( V_14 , V_50 ,
V_31 -> V_43 . V_40 - 1 ) ;
F_10 ( V_14 , V_51 , V_37 ) ;
} else {
F_10 ( V_14 , V_50 , 7 ) ;
F_10 ( V_14 , V_51 ,
V_31 -> V_38 ) ;
}
switch ( V_31 -> V_38 ) {
case 32 :
V_32 = 0 ;
V_33 = 15 ;
break;
case 24 :
V_32 = 1 ;
V_33 = 19 ;
break;
case 16 :
V_32 = 3 ;
V_33 = 31 ;
break;
case 8 :
V_32 = 5 ;
V_33 = 63 ;
break;
default:
return - V_52 ;
}
F_10 ( V_14 , V_53 , V_32 ) ;
F_10 ( V_14 , V_54 , V_33 ) ;
F_10 ( V_14 , V_55 , 7 ) ;
return 0 ;
}
int F_15 ( struct V_9 T_2 * V_14 ,
int V_56 )
{
int V_32 = 0 , V_33 = 0 ;
switch ( V_56 ) {
case 32 :
V_32 = 0 ;
V_33 = 15 ;
break;
case 24 :
V_32 = 1 ;
V_33 = 19 ;
break;
case 16 :
V_32 = 3 ;
V_33 = 31 ;
break;
case 8 :
V_32 = 5 ;
V_33 = 63 ;
break;
default:
return - V_52 ;
}
F_10 ( V_14 , V_53 , V_32 ) ;
F_10 ( V_14 , V_54 , V_33 ) ;
F_10 ( V_14 , V_55 , 6 ) ;
return 0 ;
}
void F_16 ( struct V_9 T_2 * V_14 ,
T_1 V_57 , int V_58 , int V_59 , int V_60 )
{
switch ( V_57 ) {
case V_61 :
F_10 ( V_14 , V_62 , ( V_58 / 2 ) - 1 ) ;
F_10 ( V_14 , V_63 , V_59 / 8 ) ;
F_10 ( V_14 , V_64 , V_60 / 8 ) ;
break;
}
}
void F_17 ( struct V_9 T_2 * V_14 , T_1 V_57 ,
int V_58 , int V_65 )
{
int V_59 , V_60 ;
int V_66 = 0 ;
switch ( V_57 ) {
case V_61 :
V_66 = V_58 / 2 ;
V_59 = V_58 * V_65 ;
V_60 = V_59 + ( V_66 * V_65 / 2 ) ;
F_16 ( V_14 , V_61 , V_58 ,
V_59 , V_60 ) ;
break;
}
}
int F_18 ( struct V_9 T_2 * V_67 , T_1 V_68 )
{
switch ( V_68 ) {
case V_61 :
F_10 ( V_67 , V_55 , 2 ) ;
F_10 ( V_67 , V_54 , 63 ) ;
break;
case V_69 :
F_10 ( V_67 , V_53 , 3 ) ;
F_10 ( V_67 , V_55 , 0xA ) ;
F_10 ( V_67 , V_54 , 31 ) ;
break;
case V_70 :
F_10 ( V_67 , V_53 , 3 ) ;
F_10 ( V_67 , V_55 , 0x8 ) ;
F_10 ( V_67 , V_54 , 31 ) ;
break;
case V_71 :
F_14 ( V_67 , & V_72 ) ;
break;
case V_73 :
F_14 ( V_67 , & V_74 ) ;
break;
case V_75 :
F_14 ( V_67 , & V_76 ) ;
break;
case V_77 :
F_14 ( V_67 , & V_78 ) ;
break;
case V_79 :
F_14 ( V_67 , & V_80 ) ;
break;
default:
return - V_52 ;
}
return 0 ;
}
int F_19 ( struct V_9 T_2 * V_67 ,
struct V_81 * V_82 )
{
struct V_83 * V_84 = & V_82 -> V_84 ;
int V_85 , V_59 , V_60 ;
F_12 ( L_2 ,
V_27 , V_84 -> V_56 , V_84 -> V_65 ,
V_84 -> V_86 ) ;
F_20 ( V_67 , V_82 -> V_87 . V_56 ,
V_82 -> V_87 . V_65 ) ;
F_21 ( V_67 , V_84 -> V_86 ) ;
F_18 ( V_67 , V_84 -> V_68 ) ;
switch ( V_84 -> V_68 ) {
case V_61 :
V_85 = F_22 ( V_84 , V_82 -> V_87 . V_88 , V_82 -> V_87 . V_89 ) ;
V_59 = F_23 ( V_84 , V_82 -> V_87 . V_88 ,
V_82 -> V_87 . V_89 ) - V_85 ;
V_60 = F_24 ( V_84 , V_82 -> V_87 . V_88 ,
V_82 -> V_87 . V_89 ) - V_85 ;
F_16 ( V_67 , V_84 -> V_68 ,
V_84 -> V_86 , V_59 , V_60 ) ;
F_25 ( V_67 , 0 , V_82 -> V_90 + V_85 ) ;
break;
case V_69 :
F_25 ( V_67 , 0 , V_82 -> V_90 +
V_82 -> V_87 . V_88 * 2 +
V_82 -> V_87 . V_89 * V_82 -> V_84 . V_86 ) ;
break;
case V_71 :
case V_75 :
F_25 ( V_67 , 0 , V_82 -> V_90 +
V_82 -> V_87 . V_88 * 4 +
V_82 -> V_87 . V_89 * V_82 -> V_84 . V_86 ) ;
break;
case V_73 :
F_25 ( V_67 , 0 , V_82 -> V_90 +
V_82 -> V_87 . V_88 * 2 +
V_82 -> V_87 . V_89 * V_82 -> V_84 . V_86 ) ;
break;
case V_77 :
case V_79 :
F_25 ( V_67 , 0 , V_82 -> V_90 +
V_82 -> V_87 . V_88 * 3 +
V_82 -> V_87 . V_89 * V_82 -> V_84 . V_86 ) ;
break;
default:
return - V_52 ;
}
return 0 ;
}
enum V_91 F_26 ( T_1 V_68 )
{
switch ( V_68 ) {
case V_61 :
case V_69 :
case V_92 :
return V_93 ;
case V_71 :
case V_75 :
case V_77 :
case V_79 :
case V_73 :
return V_94 ;
default:
return V_95 ;
}
}
struct V_10 * F_27 ( struct V_1 * V_2 , unsigned V_13 )
{
struct V_10 * V_11 ;
F_28 ( V_2 -> V_96 , L_3 , V_27 , V_13 ) ;
if ( V_13 > 63 )
return F_29 ( - V_97 ) ;
F_30 ( & V_2 -> V_98 ) ;
V_11 = & V_2 -> V_11 [ V_13 ] ;
if ( V_11 -> V_99 ) {
V_11 = F_29 ( - V_100 ) ;
goto V_101;
}
V_11 -> V_99 = 1 ;
V_11 -> V_13 = V_13 ;
V_101:
F_31 ( & V_2 -> V_98 ) ;
return V_11 ;
}
void F_32 ( struct V_10 * V_11 )
{
struct V_1 * V_2 = V_11 -> V_2 ;
F_28 ( V_2 -> V_96 , L_3 , V_27 , V_11 -> V_13 ) ;
F_30 ( & V_2 -> V_98 ) ;
V_11 -> V_99 = 0 ;
F_31 ( & V_2 -> V_98 ) ;
}
void F_33 ( struct V_10 * V_11 ,
bool V_102 )
{
struct V_1 * V_2 = V_11 -> V_2 ;
unsigned long V_103 ;
T_1 V_104 ;
F_34 ( & V_2 -> V_105 , V_103 ) ;
V_104 = F_1 ( V_2 , F_35 ( V_11 -> V_13 ) ) ;
if ( V_102 )
V_104 |= F_36 ( V_11 -> V_13 ) ;
else
V_104 &= ~ F_36 ( V_11 -> V_13 ) ;
F_3 ( V_2 , V_104 , F_35 ( V_11 -> V_13 ) ) ;
F_37 ( & V_2 -> V_105 , V_103 ) ;
}
int F_38 ( struct V_1 * V_2 , T_1 V_26 )
{
unsigned long V_106 ;
T_1 V_7 ;
F_34 ( & V_2 -> V_105 , V_106 ) ;
V_7 = F_1 ( V_2 , V_107 ) ;
if ( V_26 & V_108 )
V_7 |= V_109 ;
if ( V_26 & V_110 )
V_7 |= V_111 ;
F_3 ( V_2 , V_7 , V_107 ) ;
V_7 = F_1 ( V_2 , V_112 ) ;
V_7 |= V_26 ;
F_3 ( V_2 , V_7 , V_112 ) ;
F_37 ( & V_2 -> V_105 , V_106 ) ;
return 0 ;
}
int F_39 ( struct V_1 * V_2 , T_1 V_26 )
{
unsigned long V_106 ;
T_1 V_7 ;
F_34 ( & V_2 -> V_105 , V_106 ) ;
V_7 = F_1 ( V_2 , V_112 ) ;
V_7 &= ~ V_26 ;
F_3 ( V_2 , V_7 , V_112 ) ;
V_7 = F_1 ( V_2 , V_107 ) ;
if ( V_26 & V_108 )
V_7 &= ~ V_109 ;
if ( V_26 & V_110 )
V_7 &= ~ V_111 ;
F_3 ( V_2 , V_7 , V_107 ) ;
F_37 ( & V_2 -> V_105 , V_106 ) ;
return 0 ;
}
void F_40 ( struct V_10 * V_11 , T_1 V_113 )
{
struct V_1 * V_2 = V_11 -> V_2 ;
unsigned int V_114 = V_11 -> V_13 ;
unsigned long V_103 ;
F_34 ( & V_2 -> V_105 , V_103 ) ;
if ( V_113 == 0 )
F_3 ( V_2 , F_36 ( V_114 ) , F_41 ( V_114 ) ) ;
else
F_3 ( V_2 , F_36 ( V_114 ) , F_42 ( V_114 ) ) ;
F_37 ( & V_2 -> V_105 , V_103 ) ;
}
int F_43 ( struct V_10 * V_11 )
{
struct V_1 * V_2 = V_11 -> V_2 ;
T_1 V_7 ;
unsigned long V_103 ;
F_34 ( & V_2 -> V_105 , V_103 ) ;
V_7 = F_5 ( V_2 , F_44 ( V_11 -> V_13 ) ) ;
V_7 |= F_36 ( V_11 -> V_13 ) ;
F_6 ( V_2 , V_7 , F_44 ( V_11 -> V_13 ) ) ;
F_37 ( & V_2 -> V_105 , V_103 ) ;
return 0 ;
}
int F_45 ( struct V_10 * V_11 )
{
struct V_1 * V_2 = V_11 -> V_2 ;
T_1 V_7 ;
unsigned long V_103 ;
unsigned long V_115 ;
V_115 = V_116 + F_46 ( 50 ) ;
while ( F_5 ( V_2 , F_47 ( V_11 -> V_13 ) ) &
F_36 ( V_11 -> V_13 ) ) {
if ( F_48 ( V_116 , V_115 ) ) {
F_49 ( V_2 -> V_96 , L_4 ,
V_11 -> V_13 ) ;
break;
}
F_50 () ;
}
F_34 ( & V_2 -> V_105 , V_103 ) ;
V_7 = F_5 ( V_2 , F_44 ( V_11 -> V_13 ) ) ;
V_7 &= ~ F_36 ( V_11 -> V_13 ) ;
F_6 ( V_2 , V_7 , F_44 ( V_11 -> V_13 ) ) ;
F_3 ( V_2 , 0xf0000000 , V_117 ) ;
if ( F_1 ( V_2 , F_41 ( V_11 -> V_13 ) ) &
F_36 ( V_11 -> V_13 ) ) {
F_3 ( V_2 , F_36 ( V_11 -> V_13 ) ,
F_41 ( V_11 -> V_13 ) ) ;
}
if ( F_1 ( V_2 , F_42 ( V_11 -> V_13 ) ) &
F_36 ( V_11 -> V_13 ) ) {
F_3 ( V_2 , F_36 ( V_11 -> V_13 ) ,
F_42 ( V_11 -> V_13 ) ) ;
}
F_3 ( V_2 , 0x0 , V_117 ) ;
V_7 = F_1 ( V_2 , F_35 ( V_11 -> V_13 ) ) ;
V_7 &= ~ F_36 ( V_11 -> V_13 ) ;
F_3 ( V_2 , V_7 , F_35 ( V_11 -> V_13 ) ) ;
F_37 ( & V_2 -> V_105 , V_103 ) ;
return 0 ;
}
static int F_51 ( struct V_1 * V_2 )
{
unsigned long V_115 ;
F_3 ( V_2 , 0x807FFFFF , V_118 ) ;
V_115 = V_116 + F_46 ( 1000 ) ;
while ( F_1 ( V_2 , V_118 ) & 0x80000000 ) {
if ( F_48 ( V_116 , V_115 ) )
return - V_119 ;
F_50 () ;
}
F_52 ( 300 ) ;
return 0 ;
}
static int F_53 ( struct V_1 * V_2 ,
struct V_120 * V_121 , unsigned long V_122 ,
struct V_123 * V_124 )
{
char * V_125 ;
int V_126 ;
struct V_127 * V_96 = & V_121 -> V_96 ;
const struct V_128 * V_129 = V_2 -> V_129 ;
V_126 = F_54 ( V_2 , V_96 , 0 , V_122 + V_129 -> V_130 ,
V_108 , V_124 ) ;
if ( V_126 ) {
V_125 = L_5 ;
goto V_131;
}
V_126 = F_54 ( V_2 , V_96 , 1 , V_122 + V_129 -> V_132 ,
V_110 , V_124 ) ;
if ( V_126 ) {
V_125 = L_6 ;
goto V_133;
}
V_126 = F_55 ( V_2 , V_96 , V_122 + V_129 -> V_134 +
V_135 , V_122 + V_129 -> V_136 ) ;
if ( V_126 ) {
V_125 = L_7 ;
goto V_137;
}
V_126 = F_56 ( V_2 , V_96 , V_122 +
V_129 -> V_134 + V_138 , V_124 ) ;
if ( V_126 ) {
V_125 = L_8 ;
goto V_139;
}
V_126 = F_57 ( V_2 , V_96 , V_122 + V_129 -> V_140 ) ;
if ( V_126 ) {
V_125 = L_9 ;
goto V_141;
}
return 0 ;
V_141:
F_58 ( V_2 ) ;
V_139:
F_59 ( V_2 ) ;
V_137:
F_60 ( V_2 , 1 ) ;
V_133:
F_60 ( V_2 , 0 ) ;
V_131:
F_61 ( & V_121 -> V_96 , L_10 , V_125 , V_126 ) ;
return V_126 ;
}
static void F_62 ( struct V_1 * V_2 , const int * V_142 , int V_143 )
{
unsigned long V_144 ;
int V_24 , V_21 , V_145 ;
for ( V_24 = 0 ; V_24 < V_143 ; V_24 ++ ) {
V_144 = F_1 ( V_2 , F_63 ( V_142 [ V_24 ] ) ) ;
V_144 &= F_1 ( V_2 , F_64 ( V_142 [ V_24 ] ) ) ;
V_145 = V_2 -> V_146 + V_142 [ V_24 ] * 32 ;
F_65 (bit, &status, 32 )
F_66 ( V_145 + V_21 ) ;
}
}
static void F_67 ( unsigned int V_147 , struct V_148 * V_149 )
{
struct V_1 * V_2 = F_68 ( V_149 ) ;
const int V_150 [] = { 0 , 1 , 2 , 3 , 10 , 11 , 12 , 13 , 14 } ;
struct V_151 * V_152 = F_69 ( V_147 ) ;
F_70 ( V_152 , V_149 ) ;
F_62 ( V_2 , V_150 , F_71 ( V_150 ) ) ;
F_72 ( V_152 , V_149 ) ;
}
static void F_73 ( unsigned int V_147 , struct V_148 * V_149 )
{
struct V_1 * V_2 = F_68 ( V_149 ) ;
const int V_150 [] = { 4 , 5 , 8 , 9 } ;
struct V_151 * V_152 = F_69 ( V_147 ) ;
F_70 ( V_152 , V_149 ) ;
F_62 ( V_2 , V_150 , F_71 ( V_150 ) ) ;
F_72 ( V_152 , V_149 ) ;
}
static void F_74 ( struct V_153 * V_154 )
{
struct V_1 * V_2 = F_75 ( V_154 ) ;
unsigned int V_147 = V_154 -> V_147 - V_2 -> V_146 ;
F_3 ( V_2 , 1 << ( V_147 % 32 ) , F_63 ( V_147 / 32 ) ) ;
}
static void F_76 ( struct V_153 * V_154 )
{
struct V_1 * V_2 = F_75 ( V_154 ) ;
unsigned int V_147 = V_154 -> V_147 - V_2 -> V_146 ;
unsigned long V_103 ;
T_1 V_104 ;
F_34 ( & V_2 -> V_105 , V_103 ) ;
V_104 = F_1 ( V_2 , F_64 ( V_147 / 32 ) ) ;
V_104 |= 1 << ( V_147 % 32 ) ;
F_3 ( V_2 , V_104 , F_64 ( V_147 / 32 ) ) ;
F_37 ( & V_2 -> V_105 , V_103 ) ;
}
static void F_77 ( struct V_153 * V_154 )
{
struct V_1 * V_2 = F_75 ( V_154 ) ;
unsigned int V_147 = V_154 -> V_147 - V_2 -> V_146 ;
unsigned long V_103 ;
T_1 V_104 ;
F_34 ( & V_2 -> V_105 , V_103 ) ;
V_104 = F_1 ( V_2 , F_64 ( V_147 / 32 ) ) ;
V_104 &= ~ ( 1 << ( V_147 % 32 ) ) ;
F_3 ( V_2 , V_104 , F_64 ( V_147 / 32 ) ) ;
F_37 ( & V_2 -> V_105 , V_103 ) ;
}
int F_78 ( struct V_1 * V_2 , struct V_10 * V_11 ,
enum V_155 V_156 )
{
return V_2 -> V_146 + V_156 + V_11 -> V_13 ;
}
static void F_79 ( struct V_1 * V_2 )
{
F_80 ( V_2 ) ;
F_58 ( V_2 ) ;
F_59 ( V_2 ) ;
F_60 ( V_2 , 1 ) ;
F_60 ( V_2 , 0 ) ;
}
static int F_81 ( struct V_127 * V_96 , void * V_157 )
{
struct V_120 * V_121 = F_82 ( V_96 ) ;
F_83 ( V_121 ) ;
return 0 ;
}
static void F_84 ( struct V_120 * V_121 )
{
F_85 ( & V_121 -> V_96 , NULL , F_81 ) ;
}
static int F_86 ( struct V_127 * V_96 ,
const struct V_158 * V_104 )
{
struct V_120 * V_121 ;
V_121 = F_87 ( V_96 , V_104 -> V_159 , V_160 ++ ,
& V_104 -> V_161 , sizeof( struct V_158 ) ) ;
return V_121 ? 0 : - V_52 ;
}
static int F_88 ( struct V_1 * V_2 )
{
int V_126 ;
int V_24 ;
for ( V_24 = 0 ; V_24 < F_71 ( V_162 ) ; V_24 ++ ) {
const struct V_158 * V_104 = & V_162 [ V_24 ] ;
V_126 = F_86 ( V_2 -> V_96 , V_104 ) ;
if ( V_126 )
goto V_163;
}
return 0 ;
V_163:
F_84 ( F_82 ( V_2 -> V_96 ) ) ;
return V_126 ;
}
static int F_89 ( struct V_1 * V_2 )
{
int V_24 ;
V_2 -> V_146 = F_90 ( - 1 , 0 , V_164 , 0 ) ;
if ( V_2 -> V_146 < 0 )
return V_2 -> V_146 ;
for ( V_24 = V_2 -> V_146 ; V_24 < V_2 -> V_146 + V_164 ; V_24 ++ ) {
F_91 ( V_24 , & V_165 , V_166 ) ;
F_92 ( V_24 , V_167 ) ;
F_93 ( V_24 , V_2 ) ;
}
F_94 ( V_2 -> V_168 , F_67 ) ;
F_95 ( V_2 -> V_168 , V_2 ) ;
F_94 ( V_2 -> V_169 , F_73 ) ;
F_95 ( V_2 -> V_169 , V_2 ) ;
return 0 ;
}
static void F_96 ( struct V_1 * V_2 )
{
int V_24 ;
F_94 ( V_2 -> V_169 , NULL ) ;
F_95 ( V_2 -> V_169 , NULL ) ;
F_94 ( V_2 -> V_168 , NULL ) ;
F_95 ( V_2 -> V_168 , NULL ) ;
for ( V_24 = V_2 -> V_146 ; V_24 < V_2 -> V_146 + V_164 ; V_24 ++ ) {
F_92 ( V_24 , 0 ) ;
F_97 ( V_24 , NULL ) ;
F_93 ( V_24 , NULL ) ;
}
F_98 ( V_2 -> V_146 , V_164 ) ;
}
static int T_3 F_99 ( struct V_120 * V_121 )
{
const struct V_170 * V_171 =
F_100 ( V_172 , & V_121 -> V_96 ) ;
struct V_1 * V_2 ;
struct V_173 * V_174 ;
unsigned long V_122 ;
int V_24 , V_126 , V_168 , V_169 ;
const struct V_128 * V_129 ;
V_129 = V_171 -> V_28 ;
F_101 ( & V_121 -> V_96 , L_11 , V_129 -> V_159 ) ;
V_168 = F_102 ( V_121 , 0 ) ;
V_169 = F_102 ( V_121 , 1 ) ;
V_174 = F_103 ( V_121 , V_175 , 0 ) ;
F_101 ( & V_121 -> V_96 , L_12 ,
V_168 , V_169 ) ;
if ( ! V_174 || V_168 < 0 || V_169 < 0 )
return - V_97 ;
V_122 = V_174 -> V_176 ;
V_2 = F_104 ( & V_121 -> V_96 , sizeof( * V_2 ) , V_177 ) ;
if ( ! V_2 )
return - V_97 ;
for ( V_24 = 0 ; V_24 < 64 ; V_24 ++ )
V_2 -> V_11 [ V_24 ] . V_2 = V_2 ;
V_2 -> V_129 = V_129 ;
V_2 -> V_15 = V_129 -> type ;
F_105 ( & V_2 -> V_105 ) ;
F_106 ( & V_2 -> V_98 ) ;
F_101 ( & V_121 -> V_96 , L_13 ,
V_122 + V_129 -> V_134 ) ;
F_101 ( & V_121 -> V_96 , L_14 ,
V_122 + V_129 -> V_134 + V_178 ) ;
F_101 ( & V_121 -> V_96 , L_15 ,
V_122 + V_129 -> V_179 ) ;
F_101 ( & V_121 -> V_96 , L_16 ,
V_122 + V_129 -> V_130 ) ;
F_101 ( & V_121 -> V_96 , L_17 ,
V_122 + V_129 -> V_132 ) ;
F_101 ( & V_121 -> V_96 , L_18 ,
V_122 + V_129 -> V_140 ) ;
F_101 ( & V_121 -> V_96 , L_19 ,
V_122 + V_129 -> V_180 ) ;
F_101 ( & V_121 -> V_96 , L_20 ,
V_122 + V_129 -> V_134 + V_135 ) ;
F_101 ( & V_121 -> V_96 , L_21 ,
V_122 + V_129 -> V_134 + V_181 ) ;
F_101 ( & V_121 -> V_96 , L_22 ,
V_122 + V_129 -> V_134 + V_138 ) ;
F_101 ( & V_121 -> V_96 , L_23 ,
V_122 + V_129 -> V_182 ) ;
V_2 -> V_4 = F_107 ( & V_121 -> V_96 ,
V_122 + V_129 -> V_134 , V_183 ) ;
V_2 -> V_6 = F_107 ( & V_121 -> V_96 ,
V_122 + V_129 -> V_134 + V_178 ,
V_183 ) ;
V_2 -> V_12 = F_107 ( & V_121 -> V_96 ,
V_122 + V_129 -> V_179 , V_183 ) ;
if ( ! V_2 -> V_4 || ! V_2 -> V_6 || ! V_2 -> V_12 ) {
V_126 = - V_184 ;
goto V_185;
}
V_2 -> V_123 = F_108 ( & V_121 -> V_96 , L_24 ) ;
if ( F_109 ( V_2 -> V_123 ) ) {
V_126 = F_110 ( V_2 -> V_123 ) ;
F_61 ( & V_121 -> V_96 , L_25 , V_126 ) ;
goto V_186;
}
F_111 ( V_121 , V_2 ) ;
F_112 ( V_2 -> V_123 ) ;
V_2 -> V_96 = & V_121 -> V_96 ;
V_2 -> V_168 = V_168 ;
V_2 -> V_169 = V_169 ;
V_126 = F_89 ( V_2 ) ;
if ( V_126 )
goto V_187;
F_51 ( V_2 ) ;
F_3 ( V_2 , 0x00400000L | ( V_188 << 18 ) ,
V_107 ) ;
V_126 = F_53 ( V_2 , V_121 , V_122 , V_2 -> V_123 ) ;
if ( V_126 )
goto V_189;
V_126 = F_88 ( V_2 ) ;
if ( V_126 ) {
F_61 ( & V_121 -> V_96 , L_26 ,
V_126 ) ;
goto V_190;
}
return 0 ;
V_190:
F_79 ( V_2 ) ;
V_189:
F_96 ( V_2 ) ;
V_187:
F_113 ( V_2 -> V_123 ) ;
V_186:
V_185:
return V_126 ;
}
static int T_4 F_114 ( struct V_120 * V_121 )
{
struct V_1 * V_2 = F_115 ( V_121 ) ;
struct V_173 * V_174 ;
V_174 = F_103 ( V_121 , V_175 , 0 ) ;
F_84 ( V_121 ) ;
F_79 ( V_2 ) ;
F_96 ( V_2 ) ;
F_113 ( V_2 -> V_123 ) ;
return 0 ;
}
