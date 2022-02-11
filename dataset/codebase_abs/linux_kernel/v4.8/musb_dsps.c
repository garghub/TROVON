static void F_1 ( struct V_1 * V_1 , unsigned long V_2 )
{
struct V_3 * V_4 = V_1 -> V_5 ;
struct V_6 * V_7 = F_2 ( V_4 -> V_8 ) ;
if ( V_2 == 0 )
V_2 = V_9 + F_3 ( 3 ) ;
if ( V_1 -> V_10 || ( V_1 -> V_11 == 0 &&
V_1 -> V_12 -> V_13 -> V_14 == V_15 ) ) {
F_4 ( V_1 -> V_5 , L_1 ,
F_5 ( V_1 -> V_12 -> V_13 -> V_14 ) ) ;
F_6 ( & V_7 -> V_16 ) ;
V_7 -> V_17 = V_9 ;
return;
}
if ( V_1 -> V_18 != V_19 )
return;
if ( ! V_1 -> V_20 . V_4 . V_21 )
return;
if ( F_7 ( V_7 -> V_17 , V_2 ) &&
F_8 ( & V_7 -> V_16 ) ) {
F_4 ( V_1 -> V_5 ,
L_2 ) ;
return;
}
V_7 -> V_17 = V_2 ;
F_4 ( V_1 -> V_5 , L_3 ,
F_5 ( V_1 -> V_12 -> V_13 -> V_14 ) ,
F_9 ( V_2 - V_9 ) ) ;
F_10 ( & V_7 -> V_16 , V_2 ) ;
}
static void F_11 ( struct V_1 * V_1 )
{
struct V_3 * V_4 = V_1 -> V_5 ;
struct V_22 * V_23 = F_12 ( V_4 -> V_8 ) ;
struct V_6 * V_7 = F_13 ( V_23 ) ;
const struct V_24 * V_25 = V_7 -> V_25 ;
void T_1 * V_26 = V_1 -> V_27 ;
T_2 V_28 , V_29 ;
V_28 = ( ( V_1 -> V_28 & V_25 -> V_30 ) << V_25 -> V_31 ) |
( ( V_1 -> V_28 & V_25 -> V_32 ) << V_25 -> V_33 ) ;
V_29 = ( V_25 -> V_34 & ~ V_35 ) ;
F_14 ( V_26 , V_25 -> V_36 , V_28 ) ;
F_14 ( V_26 , V_25 -> V_37 , V_29 ) ;
if ( V_1 -> V_12 -> V_13 -> V_14 == V_38 &&
V_1 -> V_18 == V_19 )
F_10 ( & V_7 -> V_16 , V_9 +
F_3 ( V_25 -> V_39 ) ) ;
F_1 ( V_1 , 0 ) ;
}
static void F_15 ( struct V_1 * V_1 )
{
struct V_3 * V_4 = V_1 -> V_5 ;
struct V_22 * V_23 = F_12 ( V_4 -> V_8 ) ;
struct V_6 * V_7 = F_13 ( V_23 ) ;
const struct V_24 * V_25 = V_7 -> V_25 ;
void T_1 * V_26 = V_1 -> V_27 ;
F_14 ( V_26 , V_25 -> V_40 , V_25 -> V_34 ) ;
F_14 ( V_26 , V_25 -> V_41 ,
V_25 -> V_42 | V_25 -> V_43 ) ;
F_16 ( V_1 -> V_44 , V_45 , 0 ) ;
}
static void F_17 ( unsigned long V_46 )
{
struct V_1 * V_1 = ( void * ) V_46 ;
void T_1 * V_44 = V_1 -> V_44 ;
struct V_3 * V_4 = V_1 -> V_5 ;
struct V_6 * V_7 = F_2 ( V_4 -> V_8 ) ;
const struct V_24 * V_25 = V_7 -> V_25 ;
T_3 V_47 ;
unsigned long V_48 ;
int V_49 = 0 ;
V_47 = F_18 ( V_44 , V_45 ) ;
F_4 ( V_1 -> V_5 , L_4 , V_47 ,
F_5 ( V_1 -> V_12 -> V_13 -> V_14 ) ) ;
F_19 ( & V_1 -> V_50 , V_48 ) ;
switch ( V_1 -> V_12 -> V_13 -> V_14 ) {
case V_15 :
F_16 ( V_1 -> V_44 , V_45 , 0 ) ;
V_49 = 1 ;
case V_51 :
case V_38 :
if ( V_47 & V_52 ) {
V_1 -> V_12 -> V_13 -> V_14 = V_38 ;
F_20 ( V_1 ) ;
} else {
V_1 -> V_12 -> V_13 -> V_14 = V_51 ;
F_21 ( V_1 ) ;
}
if ( ! ( V_47 & V_53 ) && ! V_49 )
F_16 ( V_44 , V_45 , V_53 ) ;
F_10 ( & V_7 -> V_16 , V_9 +
F_3 ( V_25 -> V_39 ) ) ;
break;
case V_54 :
V_1 -> V_12 -> V_13 -> V_14 = V_55 ;
F_14 ( V_1 -> V_27 , V_25 -> V_37 ,
V_56 << V_25 -> V_57 ) ;
break;
default:
break;
}
F_22 ( & V_1 -> V_50 , V_48 ) ;
}
static T_4 F_23 ( int V_58 , void * V_59 )
{
struct V_1 * V_1 = V_59 ;
void T_1 * V_26 = V_1 -> V_27 ;
struct V_3 * V_4 = V_1 -> V_5 ;
struct V_6 * V_7 = F_2 ( V_4 -> V_8 ) ;
const struct V_24 * V_25 = V_7 -> V_25 ;
unsigned long V_48 ;
T_4 V_60 = V_61 ;
T_2 V_62 , V_63 ;
F_19 ( & V_1 -> V_50 , V_48 ) ;
V_62 = F_24 ( V_26 , V_25 -> V_64 ) ;
V_1 -> V_65 = ( V_62 & V_25 -> V_43 ) >> V_25 -> V_33 ;
V_1 -> V_66 = ( V_62 & V_25 -> V_42 ) >> V_25 -> V_31 ;
if ( V_62 )
F_14 ( V_26 , V_25 -> V_64 , V_62 ) ;
V_63 = F_24 ( V_26 , V_25 -> V_67 ) ;
if ( ! V_63 && ! V_62 )
goto V_68;
V_1 -> V_69 = ( V_63 & V_25 -> V_34 ) >> V_25 -> V_57 ;
if ( V_63 )
F_14 ( V_26 , V_25 -> V_67 , V_63 ) ;
F_4 ( V_1 -> V_5 , L_5 ,
V_63 , V_62 ) ;
if ( V_63 & ( ( 1 << V_25 -> V_70 ) << V_25 -> V_57 ) ) {
int V_70 = F_24 ( V_26 , V_25 -> V_71 ) ;
void T_1 * V_44 = V_1 -> V_44 ;
T_3 V_47 = F_18 ( V_44 , V_45 ) ;
int V_72 ;
V_72 = V_1 -> V_69 & V_56 ;
if ( V_72 ) {
V_1 -> V_69 &= ~ V_56 ;
V_1 -> V_12 -> V_13 -> V_14 = V_54 ;
F_10 ( & V_7 -> V_16 , V_9 +
F_3 ( V_25 -> V_39 ) ) ;
F_25 ( L_6 ) ;
} else if ( V_70 ) {
F_21 ( V_1 ) ;
V_1 -> V_12 -> V_13 -> V_73 = 1 ;
V_1 -> V_12 -> V_13 -> V_14 = V_55 ;
F_6 ( & V_7 -> V_16 ) ;
} else {
V_1 -> V_10 = 0 ;
F_20 ( V_1 ) ;
V_1 -> V_12 -> V_13 -> V_73 = 0 ;
V_1 -> V_12 -> V_13 -> V_14 = V_38 ;
}
F_4 ( V_1 -> V_5 , L_7 ,
V_70 ? L_8 : L_9 ,
F_5 ( V_1 -> V_12 -> V_13 -> V_14 ) ,
V_72 ? L_10 : L_11 ,
V_47 ) ;
V_60 = V_74 ;
}
if ( V_1 -> V_66 || V_1 -> V_65 || V_1 -> V_69 )
V_60 |= F_26 ( V_1 ) ;
if ( V_1 -> V_12 -> V_13 -> V_14 == V_38 &&
V_1 -> V_18 == V_19 )
F_10 ( & V_7 -> V_16 , V_9 +
F_3 ( V_25 -> V_39 ) ) ;
V_68:
F_22 ( & V_1 -> V_50 , V_48 ) ;
return V_60 ;
}
static int F_27 ( struct V_1 * V_1 , struct V_6 * V_7 )
{
struct V_75 * V_76 ;
struct V_75 * V_77 ;
char V_78 [ 128 ] ;
sprintf ( V_78 , L_12 , F_28 ( V_1 -> V_5 ) ) ;
V_76 = F_29 ( V_78 , NULL ) ;
if ( ! V_76 )
return - V_79 ;
V_7 -> V_80 = V_76 ;
V_7 -> V_81 . V_82 = V_83 ;
V_7 -> V_81 . V_84 = F_30 ( V_83 ) ;
V_7 -> V_81 . V_85 = V_1 -> V_27 ;
V_77 = F_31 ( L_13 , V_86 , V_76 , & V_7 -> V_81 ) ;
if ( ! V_77 ) {
F_32 ( V_76 ) ;
return - V_79 ;
}
return 0 ;
}
static int F_33 ( struct V_1 * V_1 )
{
struct V_3 * V_4 = V_1 -> V_5 ;
struct V_6 * V_7 = F_2 ( V_4 -> V_8 ) ;
struct V_22 * V_8 = F_12 ( V_4 -> V_8 ) ;
const struct V_24 * V_25 = V_7 -> V_25 ;
void T_1 * V_26 ;
struct V_87 * V_88 ;
T_2 V_89 , V_90 ;
int V_60 ;
V_88 = F_34 ( V_8 , V_91 , L_14 ) ;
V_26 = F_35 ( V_4 , V_88 ) ;
if ( F_36 ( V_26 ) )
return F_37 ( V_26 ) ;
V_1 -> V_27 = V_26 ;
V_1 -> V_12 = F_38 ( V_4 -> V_8 , L_15 , 0 ) ;
if ( F_36 ( V_1 -> V_12 ) )
return F_37 ( V_1 -> V_12 ) ;
V_1 -> V_92 = F_39 ( V_4 -> V_8 , L_16 ) ;
V_89 = F_24 ( V_26 , V_25 -> V_93 ) ;
if ( ! V_89 )
return - V_94 ;
F_40 ( V_1 -> V_12 ) ;
if ( F_36 ( V_1 -> V_92 ) ) {
V_1 -> V_92 = NULL ;
} else {
V_60 = F_41 ( V_1 -> V_92 ) ;
if ( V_60 < 0 )
return V_60 ;
V_60 = F_42 ( V_1 -> V_92 ) ;
if ( V_60 ) {
F_43 ( V_1 -> V_92 ) ;
return V_60 ;
}
}
F_44 ( & V_7 -> V_16 , F_17 , ( unsigned long ) V_1 ) ;
F_14 ( V_26 , V_25 -> V_95 , ( 1 << V_25 -> V_96 ) ) ;
V_1 -> V_97 = F_23 ;
V_90 = F_24 ( V_26 , V_25 -> V_98 ) ;
V_90 &= ~ ( 1 << V_25 -> V_99 ) ;
F_14 ( V_1 -> V_27 , V_25 -> V_98 , V_90 ) ;
V_90 = F_18 ( V_1 -> V_44 , V_100 ) ;
if ( V_90 & V_101 ) {
V_7 -> V_102 = true ;
V_90 |= V_103 ;
F_16 ( V_1 -> V_44 , V_100 , V_90 ) ;
}
return F_27 ( V_1 , V_7 ) ;
}
static int F_45 ( struct V_1 * V_1 )
{
struct V_3 * V_4 = V_1 -> V_5 ;
struct V_6 * V_7 = F_2 ( V_4 -> V_8 ) ;
F_46 ( & V_7 -> V_16 ) ;
F_47 ( V_1 -> V_12 ) ;
F_48 ( V_1 -> V_92 ) ;
F_43 ( V_1 -> V_92 ) ;
F_32 ( V_7 -> V_80 ) ;
return 0 ;
}
static int F_49 ( struct V_1 * V_1 , T_3 V_104 )
{
struct V_3 * V_4 = V_1 -> V_5 ;
struct V_6 * V_7 = F_2 ( V_4 -> V_8 ) ;
const struct V_24 * V_25 = V_7 -> V_25 ;
void T_1 * V_27 = V_1 -> V_27 ;
T_2 V_105 ;
V_105 = F_24 ( V_27 , V_25 -> V_104 ) ;
switch ( V_104 ) {
case V_106 :
V_105 &= ~ ( 1 << V_25 -> V_107 ) ;
V_105 |= ( 1 << V_25 -> V_108 ) ;
F_14 ( V_27 , V_25 -> V_104 , V_105 ) ;
F_14 ( V_27 , V_25 -> V_98 , 0x02 ) ;
break;
case V_109 :
V_105 |= ( 1 << V_25 -> V_107 ) ;
V_105 |= ( 1 << V_25 -> V_108 ) ;
F_14 ( V_27 , V_25 -> V_104 , V_105 ) ;
break;
case V_110 :
F_14 ( V_27 , V_25 -> V_98 , 0x02 ) ;
break;
default:
F_50 ( V_7 -> V_4 , L_17 , V_104 ) ;
return - V_111 ;
}
return 0 ;
}
static bool F_51 ( struct V_1 * V_1 )
{
T_3 V_112 ;
bool V_113 = false ;
V_112 = F_18 ( V_1 -> V_44 , V_100 ) ;
F_4 ( V_1 -> V_5 , L_18 ,
V_112 ) ;
F_4 ( V_1 -> V_5 , L_19 ,
V_112 & V_114 ? L_20 : L_21 ) ;
if ( V_112 & V_114 ) {
int V_2 = 10 ;
V_112 = F_18 ( V_1 -> V_44 , V_100 ) ;
V_112 |= V_115 ;
F_16 ( V_1 -> V_44 , V_100 , V_112 ) ;
F_4 ( V_1 -> V_5 , L_22 ) ;
do {
V_112 = F_18 ( V_1 -> V_44 , V_100 ) ;
F_52 ( 1 ) ;
} while ( ( V_112 & V_114 ) && V_2 -- );
if ( V_112 & V_114 ) {
F_4 ( V_1 -> V_5 , L_23 ,
V_112 ) ;
V_113 = true ;
}
} else {
V_113 = true ;
}
return V_113 ;
}
static int F_53 ( struct V_1 * V_1 )
{
struct V_3 * V_4 = V_1 -> V_5 ;
struct V_6 * V_7 = F_2 ( V_4 -> V_8 ) ;
int V_113 = 0 ;
if ( V_7 -> V_102 )
V_113 = F_51 ( V_1 ) ;
else
V_113 = 1 ;
return V_113 ? 0 : - V_116 ;
}
static void F_54 ( struct V_117 * V_118 , T_5 V_119 , T_3 * V_120 )
{
void T_1 * V_121 = V_118 -> V_121 ;
if ( V_119 >= 4 ) {
F_55 ( V_121 , V_120 , V_119 >> 2 ) ;
V_120 += V_119 & ~ 0x03 ;
V_119 &= 0x03 ;
}
if ( V_119 > 0 ) {
T_2 V_90 = F_24 ( V_121 , 0 ) ;
memcpy ( V_120 , & V_90 , V_119 ) ;
}
}
static int F_56 ( struct V_122 * V_123 , const char * V_124 )
{
int V_60 ;
T_2 V_90 ;
V_60 = F_57 ( V_123 , V_124 , & V_90 ) ;
if ( V_60 )
return 0 ;
return V_90 ;
}
static int F_58 ( struct V_3 * V_4 )
{
enum V_125 V_104 ;
V_104 = F_59 ( V_4 ) ;
switch ( V_104 ) {
case V_126 :
return V_127 ;
case V_128 :
return V_129 ;
case V_130 :
case V_131 :
default:
return V_19 ;
}
}
static int F_60 ( struct V_6 * V_7 ,
struct V_22 * V_8 )
{
struct V_132 V_133 ;
struct V_87 V_134 [ 2 ] ;
struct V_87 * V_135 ;
struct V_3 * V_4 = & V_8 -> V_4 ;
struct V_136 * V_137 ;
struct V_22 * V_1 ;
struct V_122 * V_123 = V_8 -> V_4 . V_138 ;
int V_60 , V_90 ;
memset ( V_134 , 0 , sizeof( V_134 ) ) ;
V_135 = F_34 ( V_8 , V_91 , L_24 ) ;
if ( ! V_135 ) {
F_50 ( V_4 , L_25 ) ;
return - V_111 ;
}
V_134 [ 0 ] = * V_135 ;
V_135 = F_34 ( V_8 , V_139 , L_24 ) ;
if ( ! V_135 ) {
F_50 ( V_4 , L_26 ) ;
return - V_111 ;
}
V_134 [ 1 ] = * V_135 ;
V_1 = F_61 ( L_27 , V_140 ) ;
if ( ! V_1 ) {
F_50 ( V_4 , L_28 ) ;
return - V_79 ;
}
V_1 -> V_4 . V_8 = V_4 ;
V_1 -> V_4 . V_141 = & V_142 ;
V_1 -> V_4 . V_143 = V_142 ;
V_7 -> V_1 = V_1 ;
V_60 = F_62 ( V_1 , V_134 ,
F_30 ( V_134 ) ) ;
if ( V_60 ) {
F_50 ( V_4 , L_29 ) ;
goto V_72;
}
V_137 = F_63 ( & V_8 -> V_4 , sizeof( * V_137 ) , V_144 ) ;
if ( ! V_137 ) {
V_60 = - V_79 ;
goto V_72;
}
V_133 . V_137 = V_137 ;
V_133 . V_145 = & V_146 ;
V_137 -> V_147 = F_56 ( V_123 , L_30 ) ;
V_137 -> V_148 = F_56 ( V_123 , L_31 ) ;
V_137 -> V_149 = 1 ;
V_133 . V_104 = F_58 ( V_4 ) ;
V_133 . V_150 = F_56 ( V_123 , L_32 ) / 2 ;
V_60 = F_57 ( V_123 , L_33 , & V_90 ) ;
if ( ! V_60 && V_90 )
V_137 -> V_151 = true ;
V_137 -> V_152 = F_64 ( & V_8 -> V_4 ) ;
switch ( V_137 -> V_152 ) {
case V_153 :
case V_154 :
break;
case V_155 :
F_65 ( V_4 , L_34
L_35 ) ;
default:
V_137 -> V_152 = V_156 ;
}
V_60 = F_66 ( V_1 , & V_133 , sizeof( V_133 ) ) ;
if ( V_60 ) {
F_50 ( V_4 , L_36 ) ;
goto V_72;
}
V_60 = F_67 ( V_1 ) ;
if ( V_60 ) {
F_50 ( V_4 , L_37 ) ;
goto V_72;
}
return 0 ;
V_72:
F_68 ( V_1 ) ;
return V_60 ;
}
static int F_69 ( struct V_22 * V_23 )
{
const struct V_157 * V_158 ;
const struct V_24 * V_25 ;
struct V_6 * V_7 ;
int V_60 ;
if ( ! strcmp ( V_23 -> V_159 , L_27 ) )
return - V_94 ;
V_158 = F_70 ( V_160 , V_23 -> V_4 . V_138 ) ;
if ( ! V_158 ) {
F_50 ( & V_23 -> V_4 , L_38 ) ;
return - V_111 ;
}
V_25 = V_158 -> V_161 ;
if ( F_71 ( V_23 -> V_4 . V_138 , L_39 ) )
V_146 . V_162 = F_54 ;
V_7 = F_63 ( & V_23 -> V_4 , sizeof( * V_7 ) , V_144 ) ;
if ( ! V_7 )
return - V_79 ;
V_7 -> V_4 = & V_23 -> V_4 ;
V_7 -> V_25 = V_25 ;
F_72 ( V_23 , V_7 ) ;
F_73 ( & V_23 -> V_4 ) ;
V_60 = F_74 ( & V_23 -> V_4 ) ;
if ( V_60 < 0 ) {
F_50 ( & V_23 -> V_4 , L_40 ) ;
goto V_163;
}
V_60 = F_60 ( V_7 , V_23 ) ;
if ( V_60 )
goto V_164;
return 0 ;
V_164:
F_75 ( & V_23 -> V_4 ) ;
V_163:
F_76 ( & V_23 -> V_4 ) ;
return V_60 ;
}
static int F_77 ( struct V_22 * V_23 )
{
struct V_6 * V_7 = F_13 ( V_23 ) ;
F_78 ( V_7 -> V_1 ) ;
F_75 ( & V_23 -> V_4 ) ;
F_76 ( & V_23 -> V_4 ) ;
return 0 ;
}
static int F_79 ( struct V_3 * V_4 )
{
struct V_6 * V_7 = F_2 ( V_4 ) ;
const struct V_24 * V_25 = V_7 -> V_25 ;
struct V_1 * V_1 = F_13 ( V_7 -> V_1 ) ;
void T_1 * V_165 ;
F_46 ( & V_7 -> V_16 ) ;
if ( ! V_1 )
return 0 ;
V_165 = V_1 -> V_27 ;
V_7 -> V_166 . V_95 = F_24 ( V_165 , V_25 -> V_95 ) ;
V_7 -> V_166 . V_62 = F_24 ( V_165 , V_25 -> V_36 ) ;
V_7 -> V_166 . V_167 = F_24 ( V_165 , V_25 -> V_37 ) ;
V_7 -> V_166 . V_98 = F_24 ( V_165 , V_25 -> V_98 ) ;
V_7 -> V_166 . V_104 = F_24 ( V_165 , V_25 -> V_104 ) ;
V_7 -> V_166 . V_168 = F_24 ( V_165 , V_25 -> V_168 ) ;
V_7 -> V_166 . V_169 = F_24 ( V_165 , V_25 -> V_169 ) ;
return 0 ;
}
static int F_80 ( struct V_3 * V_4 )
{
struct V_6 * V_7 = F_2 ( V_4 ) ;
const struct V_24 * V_25 = V_7 -> V_25 ;
struct V_1 * V_1 = F_13 ( V_7 -> V_1 ) ;
void T_1 * V_165 ;
if ( ! V_1 )
return 0 ;
V_165 = V_1 -> V_27 ;
F_14 ( V_165 , V_25 -> V_95 , V_7 -> V_166 . V_95 ) ;
F_14 ( V_165 , V_25 -> V_36 , V_7 -> V_166 . V_62 ) ;
F_14 ( V_165 , V_25 -> V_37 , V_7 -> V_166 . V_167 ) ;
F_14 ( V_165 , V_25 -> V_98 , V_7 -> V_166 . V_98 ) ;
F_14 ( V_165 , V_25 -> V_104 , V_7 -> V_166 . V_104 ) ;
F_14 ( V_165 , V_25 -> V_168 , V_7 -> V_166 . V_168 ) ;
F_14 ( V_165 , V_25 -> V_169 , V_7 -> V_166 . V_169 ) ;
if ( V_1 -> V_12 -> V_13 -> V_14 == V_38 &&
V_1 -> V_18 == V_19 )
F_10 ( & V_7 -> V_16 , V_9 +
F_3 ( V_25 -> V_39 ) ) ;
return 0 ;
}
