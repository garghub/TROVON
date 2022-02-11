static void F_1 ( struct V_1 * V_1 )
{
struct V_2 * V_3 = V_1 -> V_4 ;
struct V_5 * V_6 = F_2 ( V_3 -> V_7 ) ;
struct V_8 * V_9 = F_3 ( V_6 ) ;
const struct V_10 * V_11 = V_9 -> V_11 ;
void T_1 * V_12 = V_1 -> V_13 ;
T_2 V_14 , V_15 ;
V_14 = ( ( V_1 -> V_14 & V_11 -> V_16 ) << V_11 -> V_17 ) |
( ( V_1 -> V_14 & V_11 -> V_18 ) << V_11 -> V_19 ) ;
V_15 = ( V_11 -> V_20 & ~ V_21 ) ;
F_4 ( V_12 , V_11 -> V_22 , V_14 ) ;
F_4 ( V_12 , V_11 -> V_23 , V_15 ) ;
if ( V_1 -> V_24 -> V_25 -> V_26 == V_27 &&
V_1 -> V_28 == V_29 )
F_5 ( & V_9 -> V_30 , V_31 +
F_6 ( V_11 -> V_32 ) ) ;
}
static void F_7 ( struct V_1 * V_1 )
{
struct V_2 * V_3 = V_1 -> V_4 ;
struct V_5 * V_6 = F_2 ( V_3 -> V_7 ) ;
struct V_8 * V_9 = F_3 ( V_6 ) ;
const struct V_10 * V_11 = V_9 -> V_11 ;
void T_1 * V_12 = V_1 -> V_13 ;
F_4 ( V_12 , V_11 -> V_33 , V_11 -> V_20 ) ;
F_4 ( V_12 , V_11 -> V_34 ,
V_11 -> V_35 | V_11 -> V_36 ) ;
F_8 ( & V_9 -> V_30 ) ;
F_9 ( V_1 -> V_37 , V_38 , 0 ) ;
}
static int F_10 ( struct V_1 * V_1 , void * V_39 )
{
void T_1 * V_37 = V_1 -> V_37 ;
struct V_2 * V_3 = V_1 -> V_4 ;
struct V_8 * V_9 = F_11 ( V_3 -> V_7 ) ;
const struct V_10 * V_11 = V_9 -> V_11 ;
T_3 V_40 ;
int V_41 = 0 ;
V_40 = F_12 ( V_37 , V_38 ) ;
F_13 ( V_1 -> V_4 , L_1 , V_40 ,
F_14 ( V_1 -> V_24 -> V_25 -> V_26 ) ) ;
switch ( V_1 -> V_24 -> V_25 -> V_26 ) {
case V_42 :
F_5 ( & V_9 -> V_30 , V_31 +
F_6 ( V_11 -> V_32 ) ) ;
break;
case V_43 :
F_9 ( V_1 -> V_37 , V_38 , 0 ) ;
V_41 = 1 ;
case V_44 :
case V_27 :
if ( V_40 & V_45 ) {
V_1 -> V_24 -> V_25 -> V_26 = V_27 ;
F_15 ( V_1 ) ;
} else {
V_1 -> V_24 -> V_25 -> V_26 = V_44 ;
F_16 ( V_1 ) ;
}
if ( ! ( V_40 & V_46 ) && ! V_41 )
F_9 ( V_37 , V_38 , V_46 ) ;
F_5 ( & V_9 -> V_30 , V_31 +
F_6 ( V_11 -> V_32 ) ) ;
break;
case V_47 :
V_1 -> V_24 -> V_25 -> V_26 = V_42 ;
F_4 ( V_1 -> V_13 , V_11 -> V_23 ,
V_48 << V_11 -> V_49 ) ;
break;
default:
break;
}
return 0 ;
}
static void F_17 ( unsigned long V_50 )
{
struct V_1 * V_1 = ( void * ) V_50 ;
struct V_2 * V_3 = V_1 -> V_4 ;
unsigned long V_51 ;
int V_52 ;
V_52 = F_18 ( V_3 ) ;
if ( ( V_52 != - V_53 ) && V_52 < 0 ) {
F_19 ( V_3 , L_2 , V_52 ) ;
F_20 ( V_3 ) ;
return;
}
F_21 ( & V_1 -> V_54 , V_51 ) ;
V_52 = F_22 ( V_1 , F_10 , NULL ) ;
if ( V_52 < 0 )
F_19 ( V_3 , L_3 , V_55 , V_52 ) ;
F_23 ( & V_1 -> V_54 , V_51 ) ;
F_24 ( V_3 ) ;
F_25 ( V_3 ) ;
}
static T_4 F_26 ( int V_56 , void * V_57 )
{
struct V_1 * V_1 = V_57 ;
void T_1 * V_12 = V_1 -> V_13 ;
struct V_2 * V_3 = V_1 -> V_4 ;
struct V_8 * V_9 = F_11 ( V_3 -> V_7 ) ;
const struct V_10 * V_11 = V_9 -> V_11 ;
unsigned long V_51 ;
T_4 V_58 = V_59 ;
T_2 V_60 , V_61 ;
F_21 ( & V_1 -> V_54 , V_51 ) ;
V_60 = F_27 ( V_12 , V_11 -> V_62 ) ;
V_1 -> V_63 = ( V_60 & V_11 -> V_36 ) >> V_11 -> V_19 ;
V_1 -> V_64 = ( V_60 & V_11 -> V_35 ) >> V_11 -> V_17 ;
if ( V_60 )
F_4 ( V_12 , V_11 -> V_62 , V_60 ) ;
V_61 = F_27 ( V_12 , V_11 -> V_65 ) ;
if ( ! V_61 && ! V_60 )
goto V_66;
V_1 -> V_67 = ( V_61 & V_11 -> V_20 ) >> V_11 -> V_49 ;
if ( V_61 )
F_4 ( V_12 , V_11 -> V_65 , V_61 ) ;
F_13 ( V_1 -> V_4 , L_4 ,
V_61 , V_60 ) ;
if ( V_61 & ( ( 1 << V_11 -> V_68 ) << V_11 -> V_49 ) ) {
int V_68 = F_27 ( V_12 , V_11 -> V_69 ) ;
void T_1 * V_37 = V_1 -> V_37 ;
T_3 V_40 = F_12 ( V_37 , V_38 ) ;
int V_52 ;
V_52 = V_1 -> V_67 & V_48 ;
if ( V_52 ) {
V_1 -> V_67 &= ~ V_48 ;
V_1 -> V_24 -> V_25 -> V_26 = V_47 ;
F_5 ( & V_9 -> V_30 , V_31 +
F_6 ( V_11 -> V_32 ) ) ;
F_28 ( L_5 ) ;
} else if ( V_68 ) {
F_16 ( V_1 ) ;
V_1 -> V_24 -> V_25 -> V_70 = 1 ;
V_1 -> V_24 -> V_25 -> V_26 = V_42 ;
F_5 ( & V_9 -> V_30 , V_31 +
F_6 ( V_11 -> V_32 ) ) ;
} else {
V_1 -> V_71 = 0 ;
F_15 ( V_1 ) ;
V_1 -> V_24 -> V_25 -> V_70 = 0 ;
V_1 -> V_24 -> V_25 -> V_26 = V_27 ;
}
F_13 ( V_1 -> V_4 , L_6 ,
V_68 ? L_7 : L_8 ,
F_14 ( V_1 -> V_24 -> V_25 -> V_26 ) ,
V_52 ? L_9 : L_10 ,
V_40 ) ;
V_58 = V_72 ;
}
if ( V_1 -> V_64 || V_1 -> V_63 || V_1 -> V_67 )
V_58 |= F_29 ( V_1 ) ;
switch ( V_1 -> V_24 -> V_25 -> V_26 ) {
case V_27 :
case V_43 :
F_5 ( & V_9 -> V_30 , V_31 +
F_6 ( V_11 -> V_32 ) ) ;
break;
default:
break;
}
V_66:
F_23 ( & V_1 -> V_54 , V_51 ) ;
return V_58 ;
}
static int F_30 ( struct V_1 * V_1 , struct V_8 * V_9 )
{
struct V_73 * V_74 ;
struct V_73 * V_75 ;
char V_76 [ 128 ] ;
sprintf ( V_76 , L_11 , F_31 ( V_1 -> V_4 ) ) ;
V_74 = F_32 ( V_76 , NULL ) ;
if ( ! V_74 )
return - V_77 ;
V_9 -> V_78 = V_74 ;
V_9 -> V_79 . V_80 = V_81 ;
V_9 -> V_79 . V_82 = F_33 ( V_81 ) ;
V_9 -> V_79 . V_83 = V_1 -> V_13 ;
V_75 = F_34 ( L_12 , V_84 , V_74 , & V_9 -> V_79 ) ;
if ( ! V_75 ) {
F_35 ( V_74 ) ;
return - V_77 ;
}
return 0 ;
}
static int F_36 ( struct V_1 * V_1 )
{
struct V_2 * V_3 = V_1 -> V_4 ;
struct V_8 * V_9 = F_11 ( V_3 -> V_7 ) ;
struct V_5 * V_7 = F_2 ( V_3 -> V_7 ) ;
const struct V_10 * V_11 = V_9 -> V_11 ;
void T_1 * V_12 ;
struct V_85 * V_86 ;
T_2 V_87 , V_88 ;
int V_58 ;
V_86 = F_37 ( V_7 , V_89 , L_13 ) ;
V_12 = F_38 ( V_3 , V_86 ) ;
if ( F_39 ( V_12 ) )
return F_40 ( V_12 ) ;
V_1 -> V_13 = V_12 ;
V_1 -> V_24 = F_41 ( V_3 -> V_7 , L_14 , 0 ) ;
if ( F_39 ( V_1 -> V_24 ) )
return F_40 ( V_1 -> V_24 ) ;
V_1 -> V_90 = F_42 ( V_3 -> V_7 , L_15 ) ;
V_87 = F_27 ( V_12 , V_11 -> V_91 ) ;
if ( ! V_87 )
return - V_92 ;
F_43 ( V_1 -> V_24 ) ;
if ( F_39 ( V_1 -> V_90 ) ) {
V_1 -> V_90 = NULL ;
} else {
V_58 = F_44 ( V_1 -> V_90 ) ;
if ( V_58 < 0 )
return V_58 ;
V_58 = F_45 ( V_1 -> V_90 ) ;
if ( V_58 ) {
F_46 ( V_1 -> V_90 ) ;
return V_58 ;
}
}
F_47 ( & V_9 -> V_30 , F_17 , ( unsigned long ) V_1 ) ;
F_4 ( V_12 , V_11 -> V_93 , ( 1 << V_11 -> V_94 ) ) ;
V_1 -> V_95 = F_26 ;
V_88 = F_27 ( V_12 , V_11 -> V_96 ) ;
V_88 &= ~ ( 1 << V_11 -> V_97 ) ;
F_4 ( V_1 -> V_13 , V_11 -> V_96 , V_88 ) ;
V_88 = F_12 ( V_1 -> V_37 , V_98 ) ;
if ( V_88 & V_99 ) {
V_9 -> V_100 = true ;
V_88 |= V_101 ;
F_9 ( V_1 -> V_37 , V_98 , V_88 ) ;
}
F_5 ( & V_9 -> V_30 , V_31 +
F_6 ( V_9 -> V_11 -> V_32 ) ) ;
return F_30 ( V_1 , V_9 ) ;
}
static int F_48 ( struct V_1 * V_1 )
{
struct V_2 * V_3 = V_1 -> V_4 ;
struct V_8 * V_9 = F_11 ( V_3 -> V_7 ) ;
F_8 ( & V_9 -> V_30 ) ;
F_49 ( V_1 -> V_24 ) ;
F_50 ( V_1 -> V_90 ) ;
F_46 ( V_1 -> V_90 ) ;
F_35 ( V_9 -> V_78 ) ;
return 0 ;
}
static int F_51 ( struct V_1 * V_1 , T_3 V_102 )
{
struct V_2 * V_3 = V_1 -> V_4 ;
struct V_8 * V_9 = F_11 ( V_3 -> V_7 ) ;
const struct V_10 * V_11 = V_9 -> V_11 ;
void T_1 * V_13 = V_1 -> V_13 ;
T_2 V_103 ;
V_103 = F_27 ( V_13 , V_11 -> V_102 ) ;
switch ( V_102 ) {
case V_104 :
V_103 &= ~ ( 1 << V_11 -> V_105 ) ;
V_103 |= ( 1 << V_11 -> V_106 ) ;
F_4 ( V_13 , V_11 -> V_102 , V_103 ) ;
F_4 ( V_13 , V_11 -> V_96 , 0x02 ) ;
break;
case V_107 :
V_103 |= ( 1 << V_11 -> V_105 ) ;
V_103 |= ( 1 << V_11 -> V_106 ) ;
F_4 ( V_13 , V_11 -> V_102 , V_103 ) ;
break;
case V_108 :
F_4 ( V_13 , V_11 -> V_96 , 0x02 ) ;
break;
default:
F_19 ( V_9 -> V_3 , L_16 , V_102 ) ;
return - V_109 ;
}
return 0 ;
}
static bool F_52 ( struct V_1 * V_1 )
{
T_3 V_110 ;
bool V_111 = false ;
V_110 = F_12 ( V_1 -> V_37 , V_98 ) ;
F_13 ( V_1 -> V_4 , L_17 ,
V_110 ) ;
F_13 ( V_1 -> V_4 , L_18 ,
V_110 & V_112 ? L_19 : L_20 ) ;
if ( V_110 & V_112 ) {
int V_113 = 10 ;
V_110 = F_12 ( V_1 -> V_37 , V_98 ) ;
V_110 |= V_114 ;
F_9 ( V_1 -> V_37 , V_98 , V_110 ) ;
F_13 ( V_1 -> V_4 , L_21 ) ;
do {
V_110 = F_12 ( V_1 -> V_37 , V_98 ) ;
F_53 ( 1 ) ;
} while ( ( V_110 & V_112 ) && V_113 -- );
if ( V_110 & V_112 ) {
F_13 ( V_1 -> V_4 , L_22 ,
V_110 ) ;
V_111 = true ;
}
} else {
V_111 = true ;
}
return V_111 ;
}
static int F_54 ( struct V_1 * V_1 )
{
struct V_2 * V_3 = V_1 -> V_4 ;
struct V_8 * V_9 = F_11 ( V_3 -> V_7 ) ;
int V_111 = 0 ;
if ( V_9 -> V_100 )
V_111 = F_52 ( V_1 ) ;
else
V_111 = 1 ;
return V_111 ? 0 : - V_115 ;
}
static void F_55 ( struct V_116 * V_117 , T_5 V_118 , T_3 * V_119 )
{
void T_1 * V_120 = V_117 -> V_120 ;
if ( V_118 >= 4 ) {
F_56 ( V_120 , V_119 , V_118 >> 2 ) ;
V_119 += V_118 & ~ 0x03 ;
V_118 &= 0x03 ;
}
if ( V_118 > 0 ) {
T_2 V_88 = F_27 ( V_120 , 0 ) ;
memcpy ( V_119 , & V_88 , V_118 ) ;
}
}
static int F_57 ( struct V_121 * V_122 , const char * V_123 )
{
int V_58 ;
T_2 V_88 ;
V_58 = F_58 ( V_122 , V_123 , & V_88 ) ;
if ( V_58 )
return 0 ;
return V_88 ;
}
static int F_59 ( struct V_2 * V_3 )
{
enum V_124 V_102 ;
V_102 = F_60 ( V_3 ) ;
switch ( V_102 ) {
case V_125 :
return V_126 ;
case V_127 :
return V_128 ;
case V_129 :
case V_130 :
default:
return V_29 ;
}
}
static int F_61 ( struct V_8 * V_9 ,
struct V_5 * V_7 )
{
struct V_131 V_132 ;
struct V_85 V_133 [ 2 ] ;
struct V_85 * V_134 ;
struct V_2 * V_3 = & V_7 -> V_3 ;
struct V_135 * V_136 ;
struct V_5 * V_1 ;
struct V_121 * V_122 = V_7 -> V_3 . V_137 ;
int V_58 , V_88 ;
memset ( V_133 , 0 , sizeof( V_133 ) ) ;
V_134 = F_37 ( V_7 , V_89 , L_23 ) ;
if ( ! V_134 ) {
F_19 ( V_3 , L_24 ) ;
return - V_109 ;
}
V_133 [ 0 ] = * V_134 ;
V_134 = F_37 ( V_7 , V_138 , L_23 ) ;
if ( ! V_134 ) {
F_19 ( V_3 , L_25 ) ;
return - V_109 ;
}
V_133 [ 1 ] = * V_134 ;
V_1 = F_62 ( L_26 , V_139 ) ;
if ( ! V_1 ) {
F_19 ( V_3 , L_27 ) ;
return - V_77 ;
}
V_1 -> V_3 . V_7 = V_3 ;
V_1 -> V_3 . V_140 = & V_141 ;
V_1 -> V_3 . V_142 = V_141 ;
V_9 -> V_1 = V_1 ;
V_58 = F_63 ( V_1 , V_133 ,
F_33 ( V_133 ) ) ;
if ( V_58 ) {
F_19 ( V_3 , L_28 ) ;
goto V_52;
}
V_136 = F_64 ( & V_7 -> V_3 , sizeof( * V_136 ) , V_143 ) ;
if ( ! V_136 ) {
V_58 = - V_77 ;
goto V_52;
}
V_132 . V_136 = V_136 ;
V_132 . V_144 = & V_145 ;
V_136 -> V_146 = F_57 ( V_122 , L_29 ) ;
V_136 -> V_147 = F_57 ( V_122 , L_30 ) ;
V_136 -> V_148 = 1 ;
V_132 . V_102 = F_59 ( V_3 ) ;
V_132 . V_149 = F_57 ( V_122 , L_31 ) / 2 ;
V_58 = F_58 ( V_122 , L_32 , & V_88 ) ;
if ( ! V_58 && V_88 )
V_136 -> V_150 = true ;
V_136 -> V_151 = F_65 ( & V_7 -> V_3 ) ;
switch ( V_136 -> V_151 ) {
case V_152 :
case V_153 :
break;
case V_154 :
F_66 ( V_3 , L_33
L_34 ) ;
default:
V_136 -> V_151 = V_155 ;
}
V_58 = F_67 ( V_1 , & V_132 , sizeof( V_132 ) ) ;
if ( V_58 ) {
F_19 ( V_3 , L_35 ) ;
goto V_52;
}
V_58 = F_68 ( V_1 ) ;
if ( V_58 ) {
F_19 ( V_3 , L_36 ) ;
goto V_52;
}
return 0 ;
V_52:
F_69 ( V_1 ) ;
return V_58 ;
}
static int F_70 ( struct V_5 * V_6 )
{
const struct V_156 * V_157 ;
const struct V_10 * V_11 ;
struct V_8 * V_9 ;
int V_58 ;
if ( ! strcmp ( V_6 -> V_158 , L_26 ) )
return - V_92 ;
V_157 = F_71 ( V_159 , V_6 -> V_3 . V_137 ) ;
if ( ! V_157 ) {
F_19 ( & V_6 -> V_3 , L_37 ) ;
return - V_109 ;
}
V_11 = V_157 -> V_160 ;
if ( F_72 ( V_6 -> V_3 . V_137 , L_38 ) )
V_145 . V_161 = F_55 ;
V_9 = F_64 ( & V_6 -> V_3 , sizeof( * V_9 ) , V_143 ) ;
if ( ! V_9 )
return - V_77 ;
V_9 -> V_3 = & V_6 -> V_3 ;
V_9 -> V_11 = V_11 ;
F_73 ( V_6 , V_9 ) ;
F_74 ( & V_6 -> V_3 ) ;
V_58 = F_61 ( V_9 , V_6 ) ;
if ( V_58 )
goto V_52;
return 0 ;
V_52:
F_75 ( & V_6 -> V_3 ) ;
return V_58 ;
}
static int F_76 ( struct V_5 * V_6 )
{
struct V_8 * V_9 = F_3 ( V_6 ) ;
F_77 ( V_9 -> V_1 ) ;
F_75 ( & V_6 -> V_3 ) ;
return 0 ;
}
static int F_78 ( struct V_2 * V_3 )
{
struct V_8 * V_9 = F_11 ( V_3 ) ;
const struct V_10 * V_11 = V_9 -> V_11 ;
struct V_1 * V_1 = F_3 ( V_9 -> V_1 ) ;
void T_1 * V_162 ;
F_8 ( & V_9 -> V_30 ) ;
if ( ! V_1 )
return 0 ;
V_162 = V_1 -> V_13 ;
V_9 -> V_163 . V_93 = F_27 ( V_162 , V_11 -> V_93 ) ;
V_9 -> V_163 . V_60 = F_27 ( V_162 , V_11 -> V_22 ) ;
V_9 -> V_163 . V_164 = F_27 ( V_162 , V_11 -> V_23 ) ;
V_9 -> V_163 . V_96 = F_27 ( V_162 , V_11 -> V_96 ) ;
V_9 -> V_163 . V_102 = F_27 ( V_162 , V_11 -> V_102 ) ;
V_9 -> V_163 . V_165 = F_27 ( V_162 , V_11 -> V_165 ) ;
V_9 -> V_163 . V_166 = F_27 ( V_162 , V_11 -> V_166 ) ;
return 0 ;
}
static int F_79 ( struct V_2 * V_3 )
{
struct V_8 * V_9 = F_11 ( V_3 ) ;
const struct V_10 * V_11 = V_9 -> V_11 ;
struct V_1 * V_1 = F_3 ( V_9 -> V_1 ) ;
void T_1 * V_162 ;
if ( ! V_1 )
return 0 ;
V_162 = V_1 -> V_13 ;
F_4 ( V_162 , V_11 -> V_93 , V_9 -> V_163 . V_93 ) ;
F_4 ( V_162 , V_11 -> V_22 , V_9 -> V_163 . V_60 ) ;
F_4 ( V_162 , V_11 -> V_23 , V_9 -> V_163 . V_164 ) ;
F_4 ( V_162 , V_11 -> V_96 , V_9 -> V_163 . V_96 ) ;
F_4 ( V_162 , V_11 -> V_102 , V_9 -> V_163 . V_102 ) ;
F_4 ( V_162 , V_11 -> V_165 , V_9 -> V_163 . V_165 ) ;
F_4 ( V_162 , V_11 -> V_166 , V_9 -> V_163 . V_166 ) ;
if ( V_1 -> V_24 -> V_25 -> V_26 == V_27 &&
V_1 -> V_28 == V_29 )
F_5 ( & V_9 -> V_30 , V_31 +
F_6 ( V_11 -> V_32 ) ) ;
return 0 ;
}
