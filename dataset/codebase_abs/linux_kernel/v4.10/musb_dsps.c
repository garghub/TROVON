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
void F_26 ( struct V_1 * V_1 , int V_56 )
{
T_2 V_57 ;
struct V_8 * V_9 = F_11 ( V_1 -> V_4 -> V_7 ) ;
const struct V_10 * V_11 = V_9 -> V_11 ;
V_57 = ( 1 << V_56 ) << V_11 -> V_19 ;
F_4 ( V_1 -> V_13 , V_11 -> V_58 , V_57 ) ;
}
static T_4 F_27 ( int V_59 , void * V_60 )
{
struct V_1 * V_1 = V_60 ;
void T_1 * V_12 = V_1 -> V_13 ;
struct V_2 * V_3 = V_1 -> V_4 ;
struct V_8 * V_9 = F_11 ( V_3 -> V_7 ) ;
const struct V_10 * V_11 = V_9 -> V_11 ;
unsigned long V_51 ;
T_4 V_61 = V_62 ;
T_2 V_57 , V_63 ;
F_21 ( & V_1 -> V_54 , V_51 ) ;
V_57 = F_28 ( V_12 , V_11 -> V_58 ) ;
V_1 -> V_64 = ( V_57 & V_11 -> V_36 ) >> V_11 -> V_19 ;
V_1 -> V_65 = ( V_57 & V_11 -> V_35 ) >> V_11 -> V_17 ;
if ( V_57 )
F_4 ( V_12 , V_11 -> V_58 , V_57 ) ;
V_63 = F_28 ( V_12 , V_11 -> V_66 ) ;
if ( ! V_63 && ! V_57 )
goto V_67;
V_1 -> V_68 = ( V_63 & V_11 -> V_20 ) >> V_11 -> V_49 ;
if ( V_63 )
F_4 ( V_12 , V_11 -> V_66 , V_63 ) ;
F_13 ( V_1 -> V_4 , L_4 ,
V_63 , V_57 ) ;
if ( V_63 & ( ( 1 << V_11 -> V_69 ) << V_11 -> V_49 ) ) {
int V_69 = F_28 ( V_12 , V_11 -> V_70 ) ;
void T_1 * V_37 = V_1 -> V_37 ;
T_3 V_40 = F_12 ( V_37 , V_38 ) ;
int V_52 ;
V_52 = V_1 -> V_68 & V_48 ;
if ( V_52 ) {
V_1 -> V_68 &= ~ V_48 ;
V_1 -> V_24 -> V_25 -> V_26 = V_47 ;
F_5 ( & V_9 -> V_30 , V_31 +
F_6 ( V_11 -> V_32 ) ) ;
F_29 ( L_5 ) ;
} else if ( V_69 ) {
F_16 ( V_1 ) ;
V_1 -> V_24 -> V_25 -> V_71 = 1 ;
V_1 -> V_24 -> V_25 -> V_26 = V_42 ;
F_5 ( & V_9 -> V_30 , V_31 +
F_6 ( V_11 -> V_32 ) ) ;
} else {
V_1 -> V_72 = 0 ;
F_15 ( V_1 ) ;
V_1 -> V_24 -> V_25 -> V_71 = 0 ;
V_1 -> V_24 -> V_25 -> V_26 = V_27 ;
}
F_13 ( V_1 -> V_4 , L_6 ,
V_69 ? L_7 : L_8 ,
F_14 ( V_1 -> V_24 -> V_25 -> V_26 ) ,
V_52 ? L_9 : L_10 ,
V_40 ) ;
V_61 = V_73 ;
}
if ( V_1 -> V_65 || V_1 -> V_64 || V_1 -> V_68 )
V_61 |= F_30 ( V_1 ) ;
switch ( V_1 -> V_24 -> V_25 -> V_26 ) {
case V_27 :
case V_43 :
F_5 ( & V_9 -> V_30 , V_31 +
F_6 ( V_11 -> V_32 ) ) ;
break;
default:
break;
}
V_67:
F_23 ( & V_1 -> V_54 , V_51 ) ;
return V_61 ;
}
static int F_31 ( struct V_1 * V_1 , struct V_8 * V_9 )
{
struct V_74 * V_75 ;
struct V_74 * V_76 ;
char V_77 [ 128 ] ;
sprintf ( V_77 , L_11 , F_32 ( V_1 -> V_4 ) ) ;
V_75 = F_33 ( V_77 , NULL ) ;
if ( ! V_75 )
return - V_78 ;
V_9 -> V_79 = V_75 ;
V_9 -> V_80 . V_81 = V_82 ;
V_9 -> V_80 . V_83 = F_34 ( V_82 ) ;
V_9 -> V_80 . V_84 = V_1 -> V_13 ;
V_76 = F_35 ( L_12 , V_85 , V_75 , & V_9 -> V_80 ) ;
if ( ! V_76 ) {
F_36 ( V_75 ) ;
return - V_78 ;
}
return 0 ;
}
static int F_37 ( struct V_1 * V_1 )
{
struct V_2 * V_3 = V_1 -> V_4 ;
struct V_8 * V_9 = F_11 ( V_3 -> V_7 ) ;
struct V_5 * V_7 = F_2 ( V_3 -> V_7 ) ;
const struct V_10 * V_11 = V_9 -> V_11 ;
void T_1 * V_12 ;
struct V_86 * V_87 ;
T_2 V_88 , V_89 ;
int V_61 ;
V_87 = F_38 ( V_7 , V_90 , L_13 ) ;
V_12 = F_39 ( V_3 , V_87 ) ;
if ( F_40 ( V_12 ) )
return F_41 ( V_12 ) ;
V_1 -> V_13 = V_12 ;
V_1 -> V_24 = F_42 ( V_3 -> V_7 , L_14 , 0 ) ;
if ( F_40 ( V_1 -> V_24 ) )
return F_41 ( V_1 -> V_24 ) ;
V_1 -> V_91 = F_43 ( V_3 -> V_7 , L_15 ) ;
V_88 = F_28 ( V_12 , V_11 -> V_92 ) ;
if ( ! V_88 )
return - V_93 ;
F_44 ( V_1 -> V_24 ) ;
if ( F_40 ( V_1 -> V_91 ) ) {
V_1 -> V_91 = NULL ;
} else {
V_61 = F_45 ( V_1 -> V_91 ) ;
if ( V_61 < 0 )
return V_61 ;
V_61 = F_46 ( V_1 -> V_91 ) ;
if ( V_61 ) {
F_47 ( V_1 -> V_91 ) ;
return V_61 ;
}
}
F_48 ( & V_9 -> V_30 , F_17 , ( unsigned long ) V_1 ) ;
F_4 ( V_12 , V_11 -> V_94 , ( 1 << V_11 -> V_95 ) ) ;
V_1 -> V_96 = F_27 ;
V_89 = F_28 ( V_12 , V_11 -> V_97 ) ;
V_89 &= ~ ( 1 << V_11 -> V_98 ) ;
F_4 ( V_1 -> V_13 , V_11 -> V_97 , V_89 ) ;
V_89 = F_12 ( V_1 -> V_37 , V_99 ) ;
if ( V_89 & V_100 ) {
V_9 -> V_101 = true ;
V_89 |= V_102 ;
F_9 ( V_1 -> V_37 , V_99 , V_89 ) ;
}
F_5 ( & V_9 -> V_30 , V_31 +
F_6 ( V_9 -> V_11 -> V_32 ) ) ;
return F_31 ( V_1 , V_9 ) ;
}
static int F_49 ( struct V_1 * V_1 )
{
struct V_2 * V_3 = V_1 -> V_4 ;
struct V_8 * V_9 = F_11 ( V_3 -> V_7 ) ;
F_8 ( & V_9 -> V_30 ) ;
F_50 ( V_1 -> V_24 ) ;
F_51 ( V_1 -> V_91 ) ;
F_47 ( V_1 -> V_91 ) ;
F_36 ( V_9 -> V_79 ) ;
return 0 ;
}
static int F_52 ( struct V_1 * V_1 , T_3 V_103 )
{
struct V_2 * V_3 = V_1 -> V_4 ;
struct V_8 * V_9 = F_11 ( V_3 -> V_7 ) ;
const struct V_10 * V_11 = V_9 -> V_11 ;
void T_1 * V_13 = V_1 -> V_13 ;
T_2 V_104 ;
V_104 = F_28 ( V_13 , V_11 -> V_103 ) ;
switch ( V_103 ) {
case V_105 :
V_104 &= ~ ( 1 << V_11 -> V_106 ) ;
V_104 |= ( 1 << V_11 -> V_107 ) ;
F_4 ( V_13 , V_11 -> V_103 , V_104 ) ;
F_4 ( V_13 , V_11 -> V_97 , 0x02 ) ;
break;
case V_108 :
V_104 |= ( 1 << V_11 -> V_106 ) ;
V_104 |= ( 1 << V_11 -> V_107 ) ;
F_4 ( V_13 , V_11 -> V_103 , V_104 ) ;
break;
case V_109 :
F_4 ( V_13 , V_11 -> V_97 , 0x02 ) ;
break;
default:
F_19 ( V_9 -> V_3 , L_16 , V_103 ) ;
return - V_110 ;
}
return 0 ;
}
static bool F_53 ( struct V_1 * V_1 )
{
T_3 V_111 ;
bool V_112 = false ;
V_111 = F_12 ( V_1 -> V_37 , V_99 ) ;
F_13 ( V_1 -> V_4 , L_17 ,
V_111 ) ;
F_13 ( V_1 -> V_4 , L_18 ,
V_111 & V_113 ? L_19 : L_20 ) ;
if ( V_111 & V_113 ) {
int V_114 = 10 ;
V_111 = F_12 ( V_1 -> V_37 , V_99 ) ;
V_111 |= V_115 ;
F_9 ( V_1 -> V_37 , V_99 , V_111 ) ;
F_13 ( V_1 -> V_4 , L_21 ) ;
do {
V_111 = F_12 ( V_1 -> V_37 , V_99 ) ;
F_54 ( 1 ) ;
} while ( ( V_111 & V_113 ) && V_114 -- );
if ( V_111 & V_113 ) {
F_13 ( V_1 -> V_4 , L_22 ,
V_111 ) ;
V_112 = true ;
}
} else {
V_112 = true ;
}
return V_112 ;
}
static int F_55 ( struct V_1 * V_1 )
{
struct V_2 * V_3 = V_1 -> V_4 ;
struct V_8 * V_9 = F_11 ( V_3 -> V_7 ) ;
int V_112 = 0 ;
if ( V_9 -> V_101 )
V_112 = F_53 ( V_1 ) ;
else
V_112 = 1 ;
return V_112 ? 0 : - V_116 ;
}
static void F_56 ( struct V_117 * V_118 , T_5 V_119 , T_3 * V_120 )
{
void T_1 * V_121 = V_118 -> V_121 ;
if ( V_119 >= 4 ) {
F_57 ( V_121 , V_120 , V_119 >> 2 ) ;
V_120 += V_119 & ~ 0x03 ;
V_119 &= 0x03 ;
}
if ( V_119 > 0 ) {
T_2 V_89 = F_28 ( V_121 , 0 ) ;
memcpy ( V_120 , & V_89 , V_119 ) ;
}
}
static int F_58 ( struct V_122 * V_123 , const char * V_124 )
{
int V_61 ;
T_2 V_89 ;
V_61 = F_59 ( V_123 , V_124 , & V_89 ) ;
if ( V_61 )
return 0 ;
return V_89 ;
}
static int F_60 ( struct V_2 * V_3 )
{
enum V_125 V_103 ;
V_103 = F_61 ( V_3 ) ;
switch ( V_103 ) {
case V_126 :
return V_127 ;
case V_128 :
return V_129 ;
case V_130 :
case V_131 :
default:
return V_29 ;
}
}
static int F_62 ( struct V_8 * V_9 ,
struct V_5 * V_7 )
{
struct V_132 V_133 ;
struct V_86 V_134 [ 2 ] ;
struct V_86 * V_135 ;
struct V_2 * V_3 = & V_7 -> V_3 ;
struct V_136 * V_137 ;
struct V_5 * V_1 ;
struct V_122 * V_123 = V_7 -> V_3 . V_138 ;
int V_61 , V_89 ;
memset ( V_134 , 0 , sizeof( V_134 ) ) ;
V_135 = F_38 ( V_7 , V_90 , L_23 ) ;
if ( ! V_135 ) {
F_19 ( V_3 , L_24 ) ;
return - V_110 ;
}
V_134 [ 0 ] = * V_135 ;
V_135 = F_38 ( V_7 , V_139 , L_23 ) ;
if ( ! V_135 ) {
F_19 ( V_3 , L_25 ) ;
return - V_110 ;
}
V_134 [ 1 ] = * V_135 ;
V_1 = F_63 ( L_26 , V_140 ) ;
if ( ! V_1 ) {
F_19 ( V_3 , L_27 ) ;
return - V_78 ;
}
V_1 -> V_3 . V_7 = V_3 ;
V_1 -> V_3 . V_141 = & V_142 ;
V_1 -> V_3 . V_143 = V_142 ;
V_9 -> V_1 = V_1 ;
V_61 = F_64 ( V_1 , V_134 ,
F_34 ( V_134 ) ) ;
if ( V_61 ) {
F_19 ( V_3 , L_28 ) ;
goto V_52;
}
V_137 = F_65 ( & V_7 -> V_3 , sizeof( * V_137 ) , V_144 ) ;
if ( ! V_137 ) {
V_61 = - V_78 ;
goto V_52;
}
V_133 . V_137 = V_137 ;
V_133 . V_145 = & V_146 ;
V_137 -> V_147 = F_58 ( V_123 , L_29 ) ;
V_137 -> V_148 = F_58 ( V_123 , L_30 ) ;
V_137 -> V_149 = 1 ;
V_133 . V_103 = F_60 ( V_3 ) ;
V_133 . V_150 = F_58 ( V_123 , L_31 ) / 2 ;
V_61 = F_59 ( V_123 , L_32 , & V_89 ) ;
if ( ! V_61 && V_89 )
V_137 -> V_151 = true ;
V_137 -> V_152 = F_66 ( & V_7 -> V_3 ) ;
switch ( V_137 -> V_152 ) {
case V_153 :
case V_154 :
break;
case V_155 :
F_67 ( V_3 , L_33
L_34 ) ;
default:
V_137 -> V_152 = V_156 ;
}
V_61 = F_68 ( V_1 , & V_133 , sizeof( V_133 ) ) ;
if ( V_61 ) {
F_19 ( V_3 , L_35 ) ;
goto V_52;
}
V_61 = F_69 ( V_1 ) ;
if ( V_61 ) {
F_19 ( V_3 , L_36 ) ;
goto V_52;
}
return 0 ;
V_52:
F_70 ( V_1 ) ;
return V_61 ;
}
static int F_71 ( struct V_5 * V_6 )
{
const struct V_157 * V_158 ;
const struct V_10 * V_11 ;
struct V_8 * V_9 ;
int V_61 ;
if ( ! strcmp ( V_6 -> V_159 , L_26 ) )
return - V_93 ;
V_158 = F_72 ( V_160 , V_6 -> V_3 . V_138 ) ;
if ( ! V_158 ) {
F_19 ( & V_6 -> V_3 , L_37 ) ;
return - V_110 ;
}
V_11 = V_158 -> V_161 ;
if ( F_73 ( V_6 -> V_3 . V_138 , L_38 ) )
V_146 . V_162 = F_56 ;
V_9 = F_65 ( & V_6 -> V_3 , sizeof( * V_9 ) , V_144 ) ;
if ( ! V_9 )
return - V_78 ;
V_9 -> V_3 = & V_6 -> V_3 ;
V_9 -> V_11 = V_11 ;
F_74 ( V_6 , V_9 ) ;
F_75 ( & V_6 -> V_3 ) ;
V_61 = F_62 ( V_9 , V_6 ) ;
if ( V_61 )
goto V_52;
return 0 ;
V_52:
F_76 ( & V_6 -> V_3 ) ;
return V_61 ;
}
static int F_77 ( struct V_5 * V_6 )
{
struct V_8 * V_9 = F_3 ( V_6 ) ;
F_78 ( V_9 -> V_1 ) ;
F_76 ( & V_6 -> V_3 ) ;
return 0 ;
}
static int F_79 ( struct V_2 * V_3 )
{
struct V_8 * V_9 = F_11 ( V_3 ) ;
const struct V_10 * V_11 = V_9 -> V_11 ;
struct V_1 * V_1 = F_3 ( V_9 -> V_1 ) ;
void T_1 * V_163 ;
F_8 ( & V_9 -> V_30 ) ;
if ( ! V_1 )
return 0 ;
V_163 = V_1 -> V_13 ;
V_9 -> V_164 . V_94 = F_28 ( V_163 , V_11 -> V_94 ) ;
V_9 -> V_164 . V_57 = F_28 ( V_163 , V_11 -> V_22 ) ;
V_9 -> V_164 . V_165 = F_28 ( V_163 , V_11 -> V_23 ) ;
V_9 -> V_164 . V_97 = F_28 ( V_163 , V_11 -> V_97 ) ;
V_9 -> V_164 . V_103 = F_28 ( V_163 , V_11 -> V_103 ) ;
V_9 -> V_164 . V_166 = F_28 ( V_163 , V_11 -> V_166 ) ;
V_9 -> V_164 . V_167 = F_28 ( V_163 , V_11 -> V_167 ) ;
return 0 ;
}
static int F_80 ( struct V_2 * V_3 )
{
struct V_8 * V_9 = F_11 ( V_3 ) ;
const struct V_10 * V_11 = V_9 -> V_11 ;
struct V_1 * V_1 = F_3 ( V_9 -> V_1 ) ;
void T_1 * V_163 ;
if ( ! V_1 )
return 0 ;
V_163 = V_1 -> V_13 ;
F_4 ( V_163 , V_11 -> V_94 , V_9 -> V_164 . V_94 ) ;
F_4 ( V_163 , V_11 -> V_22 , V_9 -> V_164 . V_57 ) ;
F_4 ( V_163 , V_11 -> V_23 , V_9 -> V_164 . V_165 ) ;
F_4 ( V_163 , V_11 -> V_97 , V_9 -> V_164 . V_97 ) ;
F_4 ( V_163 , V_11 -> V_103 , V_9 -> V_164 . V_103 ) ;
F_4 ( V_163 , V_11 -> V_166 , V_9 -> V_164 . V_166 ) ;
F_4 ( V_163 , V_11 -> V_167 , V_9 -> V_164 . V_167 ) ;
if ( V_1 -> V_24 -> V_25 -> V_26 == V_27 &&
V_1 -> V_28 == V_29 )
F_5 ( & V_9 -> V_30 , V_31 +
F_6 ( V_11 -> V_32 ) ) ;
return 0 ;
}
