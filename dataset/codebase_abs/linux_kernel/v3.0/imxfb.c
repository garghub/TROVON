static inline T_1 F_1 ( T_1 V_1 , struct V_2 * V_3 )
{
V_1 &= 0xffff ;
V_1 >>= 16 - V_3 -> V_4 ;
return V_1 << V_3 -> V_5 ;
}
static int F_2 ( T_1 V_6 , T_1 V_7 , T_1 V_8 , T_1 V_9 ,
T_1 V_10 , struct V_11 * V_12 )
{
struct V_13 * V_14 = V_12 -> V_15 ;
T_1 V_16 , V_17 = 1 ;
#define F_3 ( V_16 , T_2 ) ((((val)<<(width))+0x7FFF-(val))>>16)
if ( V_6 < V_14 -> V_18 ) {
V_16 = ( F_3 ( V_7 , 4 ) << 8 ) |
( F_3 ( V_8 , 4 ) << 4 ) |
F_3 ( V_9 , 4 ) ;
F_4 ( V_16 , V_14 -> V_19 + 0x800 + ( V_6 << 2 ) ) ;
V_17 = 0 ;
}
return V_17 ;
}
static int F_5 ( T_1 V_6 , T_1 V_7 , T_1 V_8 , T_1 V_9 ,
T_1 V_10 , struct V_11 * V_12 )
{
struct V_13 * V_14 = V_12 -> V_15 ;
unsigned int V_16 ;
int V_17 = 1 ;
if ( V_14 -> V_20 ) {
V_7 = 0xffff - V_7 ;
V_8 = 0xffff - V_8 ;
V_9 = 0xffff - V_9 ;
}
if ( V_12 -> V_21 . V_22 )
V_7 = V_8 = V_9 = ( 19595 * V_7 + 38470 * V_8 +
7471 * V_9 ) >> 16 ;
switch ( V_12 -> V_23 . V_24 ) {
case V_25 :
if ( V_6 < 16 ) {
T_3 * V_26 = V_12 -> V_27 ;
V_16 = F_1 ( V_7 , & V_12 -> V_21 . V_7 ) ;
V_16 |= F_1 ( V_8 , & V_12 -> V_21 . V_8 ) ;
V_16 |= F_1 ( V_9 , & V_12 -> V_21 . V_9 ) ;
V_26 [ V_6 ] = V_16 ;
V_17 = 0 ;
}
break;
case V_28 :
case V_29 :
V_17 = F_2 ( V_6 , V_7 , V_8 , V_9 , V_10 , V_12 ) ;
break;
}
return V_17 ;
}
static const struct V_30 * F_6 ( struct V_13 * V_14 )
{
struct V_30 * V_31 ;
int V_32 ;
for ( V_32 = 0 , V_31 = & V_14 -> V_33 [ 0 ] ; V_32 < V_14 -> V_34 ; V_32 ++ , V_31 ++ ) {
if ( ! strcmp ( V_31 -> V_33 . V_35 , V_36 ) )
return V_31 ;
}
return NULL ;
}
static int F_7 ( struct V_37 * V_21 , struct V_11 * V_12 )
{
struct V_13 * V_14 = V_12 -> V_15 ;
struct V_38 * V_39 ;
const struct V_30 * V_40 ;
unsigned long V_41 ;
unsigned long long V_42 ;
T_3 V_43 = 0 ;
if ( V_21 -> V_44 < V_45 )
V_21 -> V_44 = V_45 ;
if ( V_21 -> V_46 < V_47 )
V_21 -> V_46 = V_47 ;
V_40 = F_6 ( V_14 ) ;
if ( ! V_40 )
return - V_48 ;
V_21 -> V_44 = V_40 -> V_33 . V_44 ;
V_21 -> V_46 = V_40 -> V_33 . V_46 ;
V_21 -> V_49 = V_40 -> V_50 ;
V_21 -> V_51 = V_40 -> V_33 . V_51 ;
V_21 -> V_52 = V_40 -> V_33 . V_52 ;
V_21 -> V_53 = V_40 -> V_33 . V_53 ;
V_21 -> V_54 = V_40 -> V_33 . V_54 ;
V_21 -> V_55 = V_40 -> V_33 . V_55 ;
V_21 -> V_56 = V_40 -> V_33 . V_56 ;
V_21 -> V_57 = V_40 -> V_33 . V_57 ;
V_21 -> V_58 = V_40 -> V_33 . V_58 ;
V_21 -> V_59 = F_8 ( V_21 -> V_59 , V_21 -> V_44 ) ;
V_21 -> V_60 = F_8 ( V_21 -> V_60 , V_21 -> V_46 ) ;
F_9 ( L_1 , V_21 -> V_49 ) ;
V_41 = F_10 ( V_14 -> V_61 ) ;
V_42 = V_21 -> V_51 * ( unsigned long long ) V_41 ;
F_11 ( V_42 , 1000000 ) ;
if ( F_11 ( V_42 , 1000000 ) > 500000 )
V_42 ++ ;
V_43 = ( unsigned int ) V_42 ;
if ( -- V_43 > 0x3F ) {
V_43 = 0x3F ;
F_12 ( V_62 L_2 ,
V_41 / V_43 ) ;
}
switch ( V_21 -> V_49 ) {
case 32 :
V_43 |= V_63 ;
V_39 = & V_64 ;
break;
case 16 :
default:
if ( F_13 () )
V_43 |= V_65 ;
else
V_43 |= V_66 ;
if ( V_40 -> V_43 & V_67 )
V_39 = & V_68 ;
else
V_39 = & V_69 ;
break;
case 8 :
V_43 |= V_70 ;
V_39 = & V_71 ;
break;
}
V_43 |= V_40 -> V_43 & ~ ( 0x3f | ( 7 << 25 ) ) ;
V_14 -> V_43 = V_43 ;
V_21 -> V_7 = V_39 -> V_7 ;
V_21 -> V_8 = V_39 -> V_8 ;
V_21 -> V_9 = V_39 -> V_9 ;
V_21 -> V_72 = V_39 -> V_72 ;
F_9 ( L_3 ,
V_21 -> V_7 . V_4 , V_21 -> V_8 . V_4 , V_21 -> V_9 . V_4 ,
V_21 -> V_72 . V_4 ) ;
F_9 ( L_4 ,
V_21 -> V_7 . V_5 , V_21 -> V_8 . V_5 , V_21 -> V_9 . V_5 ,
V_21 -> V_72 . V_5 ) ;
return 0 ;
}
static int F_14 ( struct V_11 * V_12 )
{
struct V_13 * V_14 = V_12 -> V_15 ;
struct V_37 * V_21 = & V_12 -> V_21 ;
if ( V_21 -> V_49 == 16 || V_21 -> V_49 == 32 )
V_12 -> V_23 . V_24 = V_25 ;
else if ( ! V_14 -> V_73 )
V_12 -> V_23 . V_24 = V_29 ;
else {
V_12 -> V_23 . V_24 = V_28 ;
}
V_12 -> V_23 . V_74 = V_21 -> V_59 * V_21 -> V_49 / 8 ;
V_14 -> V_18 = V_21 -> V_49 == 8 ? 256 : 16 ;
F_15 ( V_21 , V_12 ) ;
return 0 ;
}
static int F_16 ( struct V_75 * V_76 )
{
struct V_13 * V_14 = F_17 ( V_76 ) ;
return F_18 ( V_14 -> V_19 + V_77 ) & 0xFF ;
}
static int F_19 ( struct V_75 * V_76 )
{
struct V_13 * V_14 = F_17 ( V_76 ) ;
int V_78 = V_76 -> V_79 . V_78 ;
if ( V_76 -> V_79 . V_80 != V_81 )
V_78 = 0 ;
if ( V_76 -> V_79 . V_82 != V_81 )
V_78 = 0 ;
V_14 -> V_83 = ( V_14 -> V_83 & ~ 0xFF ) | V_78 ;
if ( V_76 -> V_79 . V_82 != V_81 )
F_20 ( V_14 -> V_61 ) ;
F_4 ( V_14 -> V_83 , V_14 -> V_19 + V_77 ) ;
if ( V_76 -> V_79 . V_82 != V_81 )
F_21 ( V_14 -> V_61 ) ;
return 0 ;
}
static void F_22 ( struct V_13 * V_14 )
{
struct V_84 V_79 ;
struct V_75 * V_76 ;
if ( V_14 -> V_76 )
return;
memset ( & V_79 , 0 , sizeof( struct V_84 ) ) ;
V_79 . V_85 = 0xff ;
V_79 . type = V_86 ;
F_4 ( V_14 -> V_83 , V_14 -> V_19 + V_77 ) ;
V_76 = F_23 ( L_5 , & V_14 -> V_87 -> V_88 , V_14 ,
& V_89 , & V_79 ) ;
if ( F_24 ( V_76 ) ) {
F_25 ( & V_14 -> V_87 -> V_88 , L_6 ,
F_26 ( V_76 ) ) ;
return;
}
V_14 -> V_76 = V_76 ;
V_76 -> V_79 . V_80 = V_81 ;
V_76 -> V_79 . V_82 = V_81 ;
V_76 -> V_79 . V_78 = F_16 ( V_76 ) ;
}
static void F_27 ( struct V_13 * V_14 )
{
if ( V_14 -> V_76 )
F_28 ( V_14 -> V_76 ) ;
}
static void F_29 ( struct V_13 * V_14 )
{
F_9 ( L_7 ) ;
F_4 ( V_14 -> V_90 , V_14 -> V_19 + V_91 ) ;
F_4 ( 0x00000000 , V_14 -> V_19 + V_92 ) ;
F_4 ( F_18 ( V_14 -> V_19 + V_93 ) & ~ ( V_94 | V_95 ) ,
V_14 -> V_19 + V_93 ) ;
F_4 ( V_96 , V_14 -> V_19 + V_97 ) ;
F_20 ( V_14 -> V_61 ) ;
if ( V_14 -> V_98 )
V_14 -> V_98 ( 1 ) ;
if ( V_14 -> V_99 )
V_14 -> V_99 ( 1 ) ;
}
static void F_30 ( struct V_13 * V_14 )
{
F_9 ( L_8 ) ;
if ( V_14 -> V_98 )
V_14 -> V_98 ( 0 ) ;
if ( V_14 -> V_99 )
V_14 -> V_99 ( 0 ) ;
F_21 ( V_14 -> V_61 ) ;
F_4 ( 0 , V_14 -> V_19 + V_97 ) ;
}
static int F_31 ( int V_100 , struct V_11 * V_12 )
{
struct V_13 * V_14 = V_12 -> V_15 ;
F_9 ( L_9 , V_100 ) ;
switch ( V_100 ) {
case V_101 :
case V_102 :
case V_103 :
case V_104 :
F_30 ( V_14 ) ;
break;
case V_81 :
F_29 ( V_14 ) ;
break;
}
return 0 ;
}
static int F_15 ( struct V_37 * V_21 , struct V_11 * V_12 )
{
struct V_13 * V_14 = V_12 -> V_15 ;
F_9 ( L_10 ,
V_21 -> V_44 , V_21 -> V_52 ,
V_21 -> V_53 , V_21 -> V_54 ) ;
F_9 ( L_11 ,
V_21 -> V_46 , V_21 -> V_55 ,
V_21 -> V_56 , V_21 -> V_57 ) ;
#if V_105
if ( V_21 -> V_44 < 16 || V_21 -> V_44 > 1024 )
F_12 ( V_106 L_12 ,
V_12 -> V_23 . V_107 , V_21 -> V_44 ) ;
if ( V_21 -> V_52 < 1 || V_21 -> V_52 > 64 )
F_12 ( V_106 L_13 ,
V_12 -> V_23 . V_107 , V_21 -> V_52 ) ;
if ( V_21 -> V_53 > 255 )
F_12 ( V_106 L_14 ,
V_12 -> V_23 . V_107 , V_21 -> V_53 ) ;
if ( V_21 -> V_54 > 255 )
F_12 ( V_106 L_15 ,
V_12 -> V_23 . V_107 , V_21 -> V_54 ) ;
if ( V_21 -> V_46 < 1 || V_21 -> V_46 > V_108 )
F_12 ( V_106 L_16 ,
V_12 -> V_23 . V_107 , V_21 -> V_46 ) ;
if ( V_21 -> V_55 > 100 )
F_12 ( V_106 L_17 ,
V_12 -> V_23 . V_107 , V_21 -> V_55 ) ;
if ( V_21 -> V_56 > 63 )
F_12 ( V_106 L_18 ,
V_12 -> V_23 . V_107 , V_21 -> V_56 ) ;
if ( V_21 -> V_57 > 255 )
F_12 ( V_106 L_19 ,
V_12 -> V_23 . V_107 , V_21 -> V_57 ) ;
#endif
F_4 ( F_32 ( V_21 -> V_44 * V_21 -> V_49 / 8 / 4 ) ,
V_14 -> V_19 + V_109 ) ;
F_4 ( F_33 ( V_21 -> V_52 - 1 ) |
F_34 ( V_21 -> V_54 - 1 ) |
F_35 ( V_21 -> V_53 - 3 ) ,
V_14 -> V_19 + V_110 ) ;
F_4 ( F_36 ( V_21 -> V_55 ) |
F_37 ( V_21 -> V_57 ) |
F_38 ( V_21 -> V_56 ) ,
V_14 -> V_19 + V_111 ) ;
F_4 ( F_39 ( V_21 -> V_44 ) | F_40 ( V_21 -> V_46 ) ,
V_14 -> V_19 + V_112 ) ;
F_4 ( V_14 -> V_43 , V_14 -> V_19 + V_113 ) ;
#ifndef F_41
F_4 ( V_14 -> V_83 , V_14 -> V_19 + V_77 ) ;
#endif
F_4 ( V_14 -> V_114 , V_14 -> V_19 + V_115 ) ;
F_4 ( V_14 -> V_116 , V_14 -> V_19 + V_117 ) ;
return 0 ;
}
static int F_42 ( struct V_118 * V_88 , T_4 V_119 )
{
struct V_11 * V_12 = F_43 ( V_88 ) ;
struct V_13 * V_14 = V_12 -> V_15 ;
F_9 ( L_20 , V_120 ) ;
F_30 ( V_14 ) ;
return 0 ;
}
static int F_44 ( struct V_118 * V_88 )
{
struct V_11 * V_12 = F_43 ( V_88 ) ;
struct V_13 * V_14 = V_12 -> V_15 ;
F_9 ( L_20 , V_120 ) ;
F_29 ( V_14 ) ;
return 0 ;
}
static int T_5 F_45 ( struct V_118 * V_87 )
{
struct V_121 * V_122 = V_87 -> V_88 . V_123 ;
struct V_11 * V_12 = F_46 ( & V_87 -> V_88 ) ;
struct V_13 * V_14 = V_12 -> V_15 ;
struct V_30 * V_31 ;
int V_32 ;
F_9 ( L_20 , V_120 ) ;
V_12 -> V_27 = F_47 ( sizeof( T_3 ) * 16 , V_124 ) ;
if ( ! V_12 -> V_27 )
return - V_125 ;
memset ( V_14 , 0 , sizeof( struct V_13 ) ) ;
F_48 ( V_12 -> V_23 . V_107 , V_126 , sizeof( V_12 -> V_23 . V_107 ) ) ;
V_12 -> V_23 . type = V_127 ;
V_12 -> V_23 . V_128 = 0 ;
V_12 -> V_23 . V_129 = 0 ;
V_12 -> V_23 . V_130 = 0 ;
V_12 -> V_23 . V_131 = 0 ;
V_12 -> V_23 . V_132 = V_133 ;
V_12 -> V_21 . V_134 = 0 ;
V_12 -> V_21 . V_135 = V_136 ;
V_12 -> V_21 . V_137 = - 1 ;
V_12 -> V_21 . T_2 = - 1 ;
V_12 -> V_21 . V_138 = 0 ;
V_12 -> V_21 . V_139 = V_140 ;
V_12 -> V_141 = & V_142 ;
V_12 -> V_143 = V_144 |
V_145 ;
V_12 -> V_21 . V_22 = V_122 -> V_146 ;
V_14 -> V_20 = V_122 -> V_20 ;
V_14 -> V_73 = V_122 -> V_73 ;
V_14 -> V_114 = V_122 -> V_114 ;
V_14 -> V_116 = V_122 -> V_116 ;
V_14 -> V_83 = V_122 -> V_83 ;
V_14 -> V_99 = V_122 -> V_99 ;
V_14 -> V_98 = V_122 -> V_98 ;
for ( V_32 = 0 , V_31 = & V_122 -> V_33 [ 0 ] ; V_32 < V_122 -> V_34 ; V_32 ++ , V_31 ++ )
V_12 -> V_23 . V_147 = F_49 ( V_148 , V_12 -> V_23 . V_147 ,
V_31 -> V_33 . V_44 * V_31 -> V_33 . V_46 * V_31 -> V_50 / 8 ) ;
return 0 ;
}
static int T_5 F_50 ( struct V_118 * V_87 )
{
struct V_13 * V_14 ;
struct V_11 * V_12 ;
struct V_121 * V_122 ;
struct V_149 * V_150 ;
int V_17 , V_32 ;
F_51 ( & V_87 -> V_88 , L_21 ) ;
V_150 = F_52 ( V_87 , V_151 , 0 ) ;
if ( ! V_150 )
return - V_152 ;
V_122 = V_87 -> V_88 . V_123 ;
if ( ! V_122 ) {
F_25 ( & V_87 -> V_88 , L_22 ) ;
return - V_125 ;
}
V_12 = F_53 ( sizeof( struct V_13 ) , & V_87 -> V_88 ) ;
if ( ! V_12 )
return - V_125 ;
V_14 = V_12 -> V_15 ;
if ( ! V_36 )
V_36 = V_122 -> V_33 [ 0 ] . V_33 . V_35 ;
F_54 ( V_87 , V_12 ) ;
V_17 = F_45 ( V_87 ) ;
if ( V_17 < 0 )
goto V_153;
V_150 = F_55 ( V_150 -> V_154 , F_56 ( V_150 ) ,
V_155 ) ;
if ( ! V_150 ) {
V_17 = - V_156 ;
goto V_157;
}
V_14 -> V_61 = F_57 ( & V_87 -> V_88 , NULL ) ;
if ( F_24 ( V_14 -> V_61 ) ) {
V_17 = F_26 ( V_14 -> V_61 ) ;
F_25 ( & V_87 -> V_88 , L_23 , V_17 ) ;
goto V_158;
}
V_14 -> V_19 = F_58 ( V_150 -> V_154 , F_56 ( V_150 ) ) ;
if ( V_14 -> V_19 == NULL ) {
F_25 ( & V_87 -> V_88 , L_24 ) ;
goto V_159;
}
if ( ! V_122 -> V_160 ) {
V_14 -> V_161 = F_59 ( V_12 -> V_23 . V_147 ) ;
V_14 -> V_162 = F_60 ( & V_87 -> V_88 ,
V_14 -> V_161 , & V_14 -> V_163 , V_124 ) ;
if ( ! V_14 -> V_162 ) {
F_25 ( & V_87 -> V_88 , L_25 , V_17 ) ;
V_17 = - V_125 ;
goto V_164;
}
V_12 -> V_165 = V_14 -> V_162 ;
V_14 -> V_166 = V_14 -> V_162 ;
V_14 -> V_90 = V_14 -> V_163 ;
V_12 -> V_23 . V_167 = V_14 -> V_90 ;
} else {
V_14 -> V_162 = V_122 -> V_160 ;
V_14 -> V_163 = V_122 -> V_168 ;
V_12 -> V_165 = V_14 -> V_162 ;
V_14 -> V_166 = V_14 -> V_162 ;
V_14 -> V_90 = V_14 -> V_163 ;
V_12 -> V_23 . V_167 = V_14 -> V_90 ;
}
if ( V_122 -> V_169 ) {
V_17 = V_122 -> V_169 ( V_14 -> V_87 ) ;
if ( V_17 )
goto V_170;
}
V_14 -> V_33 = V_122 -> V_33 ;
V_14 -> V_34 = V_122 -> V_34 ;
F_61 ( & V_12 -> V_171 ) ;
for ( V_32 = 0 ; V_32 < V_122 -> V_34 ; V_32 ++ )
F_62 ( & V_122 -> V_33 [ V_32 ] . V_33 , & V_12 -> V_171 ) ;
F_7 ( & V_12 -> V_21 , V_12 ) ;
V_17 = F_63 ( & V_12 -> V_172 , 1 << V_12 -> V_21 . V_49 , 0 ) ;
if ( V_17 < 0 )
goto V_173;
F_14 ( V_12 ) ;
V_17 = F_64 ( V_12 ) ;
if ( V_17 < 0 ) {
F_25 ( & V_87 -> V_88 , L_26 ) ;
goto V_174;
}
F_29 ( V_14 ) ;
V_14 -> V_87 = V_87 ;
#ifdef F_41
F_22 ( V_14 ) ;
#endif
return 0 ;
V_174:
F_65 ( & V_12 -> V_172 ) ;
V_173:
if ( V_122 -> exit )
V_122 -> exit ( V_14 -> V_87 ) ;
V_170:
if ( ! V_122 -> V_160 )
F_66 ( & V_87 -> V_88 , V_14 -> V_161 , V_14 -> V_162 ,
V_14 -> V_163 ) ;
V_164:
F_67 ( V_14 -> V_19 ) ;
V_159:
F_68 ( V_14 -> V_61 ) ;
V_158:
F_69 ( V_150 -> V_154 , F_56 ( V_150 ) ) ;
V_157:
F_70 ( V_12 -> V_27 ) ;
V_153:
F_54 ( V_87 , NULL ) ;
F_71 ( V_12 ) ;
return V_17 ;
}
static int T_6 F_72 ( struct V_118 * V_87 )
{
struct V_121 * V_122 ;
struct V_11 * V_12 = F_43 ( V_87 ) ;
struct V_13 * V_14 = V_12 -> V_15 ;
struct V_149 * V_150 ;
V_150 = F_52 ( V_87 , V_151 , 0 ) ;
F_30 ( V_14 ) ;
#ifdef F_41
F_27 ( V_14 ) ;
#endif
F_73 ( V_12 ) ;
V_122 = V_87 -> V_88 . V_123 ;
if ( V_122 -> exit )
V_122 -> exit ( V_14 -> V_87 ) ;
F_65 ( & V_12 -> V_172 ) ;
F_70 ( V_12 -> V_27 ) ;
F_71 ( V_12 ) ;
F_67 ( V_14 -> V_19 ) ;
F_69 ( V_150 -> V_154 , F_56 ( V_150 ) ) ;
F_21 ( V_14 -> V_61 ) ;
F_68 ( V_14 -> V_61 ) ;
F_54 ( V_87 , NULL ) ;
return 0 ;
}
void F_74 ( struct V_118 * V_88 )
{
struct V_11 * V_12 = F_43 ( V_88 ) ;
struct V_13 * V_14 = V_12 -> V_15 ;
F_30 ( V_14 ) ;
}
static int F_75 ( void )
{
#ifndef F_76
char * V_175 , * V_176 = NULL ;
if ( F_77 ( L_27 , & V_176 ) )
return - V_152 ;
if ( ! V_176 || ! * V_176 )
return 0 ;
while ( ( V_175 = F_78 ( & V_176 , L_28 ) ) != NULL ) {
if ( ! * V_175 )
continue;
else
V_36 = V_175 ;
}
#endif
return 0 ;
}
int T_5 F_79 ( void )
{
int V_17 = F_75 () ;
if ( V_17 < 0 )
return V_17 ;
return F_80 ( & V_177 , F_50 ) ;
}
static void T_7 F_81 ( void )
{
F_82 ( & V_177 ) ;
}
