static inline int F_1 ( struct V_1 * V_2 )
{
return V_2 -> V_3 == V_4 ;
}
static inline T_1 F_2 ( T_1 V_5 , struct V_6 * V_7 )
{
V_5 &= 0xffff ;
V_5 >>= 16 - V_7 -> V_8 ;
return V_5 << V_7 -> V_9 ;
}
static int F_3 ( T_1 V_10 , T_1 V_11 , T_1 V_12 , T_1 V_13 ,
T_1 V_14 , struct V_15 * V_16 )
{
struct V_1 * V_2 = V_16 -> V_17 ;
T_1 V_18 , V_19 = 1 ;
#define F_4 ( V_18 , T_2 ) ((((val)<<(width))+0x7FFF-(val))>>16)
if ( V_10 < V_2 -> V_20 ) {
V_18 = ( F_4 ( V_11 , 4 ) << 8 ) |
( F_4 ( V_12 , 4 ) << 4 ) |
F_4 ( V_13 , 4 ) ;
F_5 ( V_18 , V_2 -> V_21 + 0x800 + ( V_10 << 2 ) ) ;
V_19 = 0 ;
}
return V_19 ;
}
static int F_6 ( T_1 V_10 , T_1 V_11 , T_1 V_12 , T_1 V_13 ,
T_1 V_14 , struct V_15 * V_16 )
{
struct V_1 * V_2 = V_16 -> V_17 ;
unsigned int V_18 ;
int V_19 = 1 ;
if ( V_2 -> V_22 ) {
V_11 = 0xffff - V_11 ;
V_12 = 0xffff - V_12 ;
V_13 = 0xffff - V_13 ;
}
if ( V_16 -> V_23 . V_24 )
V_11 = V_12 = V_13 = ( 19595 * V_11 + 38470 * V_12 +
7471 * V_13 ) >> 16 ;
switch ( V_16 -> V_25 . V_26 ) {
case V_27 :
if ( V_10 < 16 ) {
T_3 * V_28 = V_16 -> V_29 ;
V_18 = F_2 ( V_11 , & V_16 -> V_23 . V_11 ) ;
V_18 |= F_2 ( V_12 , & V_16 -> V_23 . V_12 ) ;
V_18 |= F_2 ( V_13 , & V_16 -> V_23 . V_13 ) ;
V_28 [ V_10 ] = V_18 ;
V_19 = 0 ;
}
break;
case V_30 :
case V_31 :
V_19 = F_3 ( V_10 , V_11 , V_12 , V_13 , V_14 , V_16 ) ;
break;
}
return V_19 ;
}
static const struct V_32 * F_7 ( struct V_1 * V_2 )
{
struct V_32 * V_33 ;
int V_34 ;
for ( V_34 = 0 , V_33 = & V_2 -> V_35 [ 0 ] ; V_34 < V_2 -> V_36 ; V_34 ++ , V_33 ++ ) {
if ( ! strcmp ( V_33 -> V_35 . V_37 , V_38 ) )
return V_33 ;
}
return NULL ;
}
static int F_8 ( struct V_39 * V_23 , struct V_15 * V_16 )
{
struct V_1 * V_2 = V_16 -> V_17 ;
struct V_40 * V_41 ;
const struct V_32 * V_42 ;
unsigned long V_43 ;
unsigned long long V_44 ;
T_3 V_45 = 0 ;
if ( V_23 -> V_46 < V_47 )
V_23 -> V_46 = V_47 ;
if ( V_23 -> V_48 < V_49 )
V_23 -> V_48 = V_49 ;
V_42 = F_7 ( V_2 ) ;
if ( ! V_42 )
return - V_50 ;
V_23 -> V_46 = V_42 -> V_35 . V_46 ;
V_23 -> V_48 = V_42 -> V_35 . V_48 ;
V_23 -> V_51 = V_42 -> V_52 ;
V_23 -> V_53 = V_42 -> V_35 . V_53 ;
V_23 -> V_54 = V_42 -> V_35 . V_54 ;
V_23 -> V_55 = V_42 -> V_35 . V_55 ;
V_23 -> V_56 = V_42 -> V_35 . V_56 ;
V_23 -> V_57 = V_42 -> V_35 . V_57 ;
V_23 -> V_58 = V_42 -> V_35 . V_58 ;
V_23 -> V_59 = V_42 -> V_35 . V_59 ;
V_23 -> V_60 = V_42 -> V_35 . V_60 ;
V_23 -> V_61 = F_9 ( V_23 -> V_61 , V_23 -> V_46 ) ;
V_23 -> V_62 = F_9 ( V_23 -> V_62 , V_23 -> V_48 ) ;
F_10 ( L_1 , V_23 -> V_51 ) ;
V_43 = F_11 ( V_2 -> V_63 ) ;
V_44 = V_23 -> V_53 * ( unsigned long long ) V_43 ;
F_12 ( V_44 , 1000000 ) ;
if ( F_12 ( V_44 , 1000000 ) > 500000 )
V_44 ++ ;
V_45 = ( unsigned int ) V_44 ;
if ( -- V_45 > 0x3F ) {
V_45 = 0x3F ;
F_13 ( V_64 L_2 ,
V_43 / V_45 ) ;
}
switch ( V_23 -> V_51 ) {
case 32 :
V_45 |= V_65 ;
V_41 = & V_66 ;
break;
case 16 :
default:
if ( F_1 ( V_2 ) )
V_45 |= V_67 ;
else
V_45 |= V_68 ;
if ( V_42 -> V_45 & V_69 )
V_41 = & V_70 ;
else
V_41 = & V_71 ;
break;
case 8 :
V_45 |= V_72 ;
V_41 = & V_73 ;
break;
}
V_45 |= V_42 -> V_45 & ~ ( 0x3f | ( 7 << 25 ) ) ;
V_2 -> V_45 = V_45 ;
V_23 -> V_11 = V_41 -> V_11 ;
V_23 -> V_12 = V_41 -> V_12 ;
V_23 -> V_13 = V_41 -> V_13 ;
V_23 -> V_74 = V_41 -> V_74 ;
F_10 ( L_3 ,
V_23 -> V_11 . V_8 , V_23 -> V_12 . V_8 , V_23 -> V_13 . V_8 ,
V_23 -> V_74 . V_8 ) ;
F_10 ( L_4 ,
V_23 -> V_11 . V_9 , V_23 -> V_12 . V_9 , V_23 -> V_13 . V_9 ,
V_23 -> V_74 . V_9 ) ;
return 0 ;
}
static int F_14 ( struct V_15 * V_16 )
{
struct V_1 * V_2 = V_16 -> V_17 ;
struct V_39 * V_23 = & V_16 -> V_23 ;
if ( V_23 -> V_51 == 16 || V_23 -> V_51 == 32 )
V_16 -> V_25 . V_26 = V_27 ;
else if ( ! V_2 -> V_75 )
V_16 -> V_25 . V_26 = V_31 ;
else {
V_16 -> V_25 . V_26 = V_30 ;
}
V_16 -> V_25 . V_76 = V_23 -> V_61 * V_23 -> V_51 / 8 ;
V_2 -> V_20 = V_23 -> V_51 == 8 ? 256 : 16 ;
F_15 ( V_23 , V_16 ) ;
return 0 ;
}
static int F_16 ( struct V_77 * V_78 )
{
struct V_1 * V_2 = F_17 ( V_78 ) ;
return F_18 ( V_2 -> V_21 + V_79 ) & 0xFF ;
}
static int F_19 ( struct V_77 * V_78 )
{
struct V_1 * V_2 = F_17 ( V_78 ) ;
int V_80 = V_78 -> V_81 . V_80 ;
if ( V_78 -> V_81 . V_82 != V_83 )
V_80 = 0 ;
if ( V_78 -> V_81 . V_84 != V_83 )
V_80 = 0 ;
V_2 -> V_85 = ( V_2 -> V_85 & ~ 0xFF ) | V_80 ;
if ( V_78 -> V_81 . V_84 != V_83 ) {
F_20 ( V_2 -> V_86 ) ;
F_20 ( V_2 -> V_87 ) ;
F_20 ( V_2 -> V_63 ) ;
}
F_5 ( V_2 -> V_85 , V_2 -> V_21 + V_79 ) ;
if ( V_78 -> V_81 . V_84 != V_83 ) {
F_21 ( V_2 -> V_63 ) ;
F_21 ( V_2 -> V_87 ) ;
F_21 ( V_2 -> V_86 ) ;
}
return 0 ;
}
static void F_22 ( struct V_1 * V_2 )
{
struct V_88 V_81 ;
struct V_77 * V_78 ;
if ( V_2 -> V_78 )
return;
memset ( & V_81 , 0 , sizeof( struct V_88 ) ) ;
V_81 . V_89 = 0xff ;
V_81 . type = V_90 ;
F_5 ( V_2 -> V_85 , V_2 -> V_21 + V_79 ) ;
V_78 = F_23 ( L_5 , & V_2 -> V_91 -> V_92 , V_2 ,
& V_93 , & V_81 ) ;
if ( F_24 ( V_78 ) ) {
F_25 ( & V_2 -> V_91 -> V_92 , L_6 ,
F_26 ( V_78 ) ) ;
return;
}
V_2 -> V_78 = V_78 ;
V_78 -> V_81 . V_82 = V_83 ;
V_78 -> V_81 . V_84 = V_83 ;
V_78 -> V_81 . V_80 = F_16 ( V_78 ) ;
}
static void F_27 ( struct V_1 * V_2 )
{
if ( V_2 -> V_78 )
F_28 ( V_2 -> V_78 ) ;
}
static void F_29 ( struct V_1 * V_2 )
{
if ( V_2 -> V_94 )
return;
F_10 ( L_7 ) ;
F_5 ( V_2 -> V_95 , V_2 -> V_21 + V_96 ) ;
F_5 ( 0x00000000 , V_2 -> V_21 + V_97 ) ;
F_5 ( F_18 ( V_2 -> V_21 + V_98 ) & ~ ( V_99 | V_100 ) ,
V_2 -> V_21 + V_98 ) ;
F_5 ( V_101 , V_2 -> V_21 + V_102 ) ;
F_20 ( V_2 -> V_86 ) ;
F_20 ( V_2 -> V_87 ) ;
F_20 ( V_2 -> V_63 ) ;
V_2 -> V_94 = true ;
if ( V_2 -> V_103 )
V_2 -> V_103 ( 1 ) ;
if ( V_2 -> V_104 )
V_2 -> V_104 ( 1 ) ;
}
static void F_30 ( struct V_1 * V_2 )
{
if ( ! V_2 -> V_94 )
return;
F_10 ( L_8 ) ;
if ( V_2 -> V_103 )
V_2 -> V_103 ( 0 ) ;
if ( V_2 -> V_104 )
V_2 -> V_104 ( 0 ) ;
F_21 ( V_2 -> V_63 ) ;
F_21 ( V_2 -> V_86 ) ;
F_21 ( V_2 -> V_87 ) ;
V_2 -> V_94 = false ;
F_5 ( 0 , V_2 -> V_21 + V_102 ) ;
}
static int F_31 ( int V_105 , struct V_15 * V_16 )
{
struct V_1 * V_2 = V_16 -> V_17 ;
F_10 ( L_9 , V_105 ) ;
switch ( V_105 ) {
case V_106 :
case V_107 :
case V_108 :
case V_109 :
F_30 ( V_2 ) ;
break;
case V_83 :
F_29 ( V_2 ) ;
break;
}
return 0 ;
}
static int F_15 ( struct V_39 * V_23 , struct V_15 * V_16 )
{
struct V_1 * V_2 = V_16 -> V_17 ;
T_3 V_110 = F_1 ( V_2 ) ? V_111 : V_112 ;
F_10 ( L_10 ,
V_23 -> V_46 , V_23 -> V_54 ,
V_23 -> V_55 , V_23 -> V_56 ) ;
F_10 ( L_11 ,
V_23 -> V_48 , V_23 -> V_57 ,
V_23 -> V_58 , V_23 -> V_59 ) ;
#if V_113
if ( V_23 -> V_46 < 16 || V_23 -> V_46 > 1024 )
F_13 ( V_114 L_12 ,
V_16 -> V_25 . V_115 , V_23 -> V_46 ) ;
if ( V_23 -> V_54 < 1 || V_23 -> V_54 > 64 )
F_13 ( V_114 L_13 ,
V_16 -> V_25 . V_115 , V_23 -> V_54 ) ;
if ( V_23 -> V_55 > 255 )
F_13 ( V_114 L_14 ,
V_16 -> V_25 . V_115 , V_23 -> V_55 ) ;
if ( V_23 -> V_56 > 255 )
F_13 ( V_114 L_15 ,
V_16 -> V_25 . V_115 , V_23 -> V_56 ) ;
if ( V_23 -> V_48 < 1 || V_23 -> V_48 > V_110 )
F_13 ( V_114 L_16 ,
V_16 -> V_25 . V_115 , V_23 -> V_48 ) ;
if ( V_23 -> V_57 > 100 )
F_13 ( V_114 L_17 ,
V_16 -> V_25 . V_115 , V_23 -> V_57 ) ;
if ( V_23 -> V_58 > 63 )
F_13 ( V_114 L_18 ,
V_16 -> V_25 . V_115 , V_23 -> V_58 ) ;
if ( V_23 -> V_59 > 255 )
F_13 ( V_114 L_19 ,
V_16 -> V_25 . V_115 , V_23 -> V_59 ) ;
#endif
F_5 ( F_32 ( V_23 -> V_46 * V_23 -> V_51 / 8 / 4 ) ,
V_2 -> V_21 + V_116 ) ;
F_5 ( F_33 ( V_23 -> V_54 - 1 ) |
F_34 ( V_23 -> V_56 - 1 ) |
F_35 ( V_23 -> V_55 - 3 ) ,
V_2 -> V_21 + V_117 ) ;
F_5 ( F_36 ( V_23 -> V_57 ) |
F_37 ( V_23 -> V_59 ) |
F_38 ( V_23 -> V_58 ) ,
V_2 -> V_21 + V_118 ) ;
F_5 ( F_39 ( V_23 -> V_46 ) | ( V_23 -> V_48 & V_110 ) ,
V_2 -> V_21 + V_119 ) ;
F_5 ( V_2 -> V_45 , V_2 -> V_21 + V_120 ) ;
#ifndef F_40
F_5 ( V_2 -> V_85 , V_2 -> V_21 + V_79 ) ;
#endif
F_5 ( V_2 -> V_121 , V_2 -> V_21 + V_122 ) ;
F_5 ( V_2 -> V_123 , V_2 -> V_21 + V_124 ) ;
return 0 ;
}
static int F_41 ( struct V_125 * V_92 , T_4 V_126 )
{
struct V_15 * V_16 = F_42 ( V_92 ) ;
struct V_1 * V_2 = V_16 -> V_17 ;
F_10 ( L_20 , V_127 ) ;
F_30 ( V_2 ) ;
return 0 ;
}
static int F_43 ( struct V_125 * V_92 )
{
struct V_15 * V_16 = F_42 ( V_92 ) ;
struct V_1 * V_2 = V_16 -> V_17 ;
F_10 ( L_20 , V_127 ) ;
F_29 ( V_2 ) ;
return 0 ;
}
static int T_5 F_44 ( struct V_125 * V_91 )
{
struct V_128 * V_129 = V_91 -> V_92 . V_130 ;
struct V_15 * V_16 = F_45 ( & V_91 -> V_92 ) ;
struct V_1 * V_2 = V_16 -> V_17 ;
struct V_32 * V_33 ;
int V_34 ;
F_10 ( L_20 , V_127 ) ;
V_16 -> V_29 = F_46 ( sizeof( T_3 ) * 16 , V_131 ) ;
if ( ! V_16 -> V_29 )
return - V_132 ;
memset ( V_2 , 0 , sizeof( struct V_1 ) ) ;
V_2 -> V_3 = V_91 -> V_133 -> V_134 ;
F_47 ( V_16 -> V_25 . V_115 , V_135 , sizeof( V_16 -> V_25 . V_115 ) ) ;
V_16 -> V_25 . type = V_136 ;
V_16 -> V_25 . V_137 = 0 ;
V_16 -> V_25 . V_138 = 0 ;
V_16 -> V_25 . V_139 = 0 ;
V_16 -> V_25 . V_140 = 0 ;
V_16 -> V_25 . V_141 = V_142 ;
V_16 -> V_23 . V_143 = 0 ;
V_16 -> V_23 . V_144 = V_145 ;
V_16 -> V_23 . V_146 = - 1 ;
V_16 -> V_23 . T_2 = - 1 ;
V_16 -> V_23 . V_147 = 0 ;
V_16 -> V_23 . V_148 = V_149 ;
V_16 -> V_150 = & V_151 ;
V_16 -> V_152 = V_153 |
V_154 ;
V_16 -> V_23 . V_24 = V_129 -> V_155 ;
V_2 -> V_22 = V_129 -> V_22 ;
V_2 -> V_75 = V_129 -> V_75 ;
V_2 -> V_121 = V_129 -> V_121 ;
V_2 -> V_123 = V_129 -> V_123 ;
V_2 -> V_85 = V_129 -> V_85 ;
V_2 -> V_104 = V_129 -> V_104 ;
V_2 -> V_103 = V_129 -> V_103 ;
for ( V_34 = 0 , V_33 = & V_129 -> V_35 [ 0 ] ; V_34 < V_129 -> V_36 ; V_34 ++ , V_33 ++ )
V_16 -> V_25 . V_156 = F_48 ( V_157 , V_16 -> V_25 . V_156 ,
V_33 -> V_35 . V_46 * V_33 -> V_35 . V_48 * V_33 -> V_52 / 8 ) ;
return 0 ;
}
static int T_5 F_49 ( struct V_125 * V_91 )
{
struct V_1 * V_2 ;
struct V_15 * V_16 ;
struct V_128 * V_129 ;
struct V_158 * V_159 ;
int V_19 , V_34 ;
F_50 ( & V_91 -> V_92 , L_21 ) ;
V_159 = F_51 ( V_91 , V_160 , 0 ) ;
if ( ! V_159 )
return - V_161 ;
V_129 = V_91 -> V_92 . V_130 ;
if ( ! V_129 ) {
F_25 ( & V_91 -> V_92 , L_22 ) ;
return - V_132 ;
}
V_16 = F_52 ( sizeof( struct V_1 ) , & V_91 -> V_92 ) ;
if ( ! V_16 )
return - V_132 ;
V_2 = V_16 -> V_17 ;
if ( ! V_38 )
V_38 = V_129 -> V_35 [ 0 ] . V_35 . V_37 ;
F_53 ( V_91 , V_16 ) ;
V_19 = F_44 ( V_91 ) ;
if ( V_19 < 0 )
goto V_162;
V_159 = F_54 ( V_159 -> V_163 , F_55 ( V_159 ) ,
V_164 ) ;
if ( ! V_159 ) {
V_19 = - V_165 ;
goto V_166;
}
V_2 -> V_86 = F_56 ( & V_91 -> V_92 , L_23 ) ;
if ( F_24 ( V_2 -> V_86 ) ) {
V_19 = F_26 ( V_2 -> V_86 ) ;
goto V_167;
}
V_2 -> V_87 = F_56 ( & V_91 -> V_92 , L_24 ) ;
if ( F_24 ( V_2 -> V_87 ) ) {
V_19 = F_26 ( V_2 -> V_87 ) ;
goto V_167;
}
V_2 -> V_63 = F_56 ( & V_91 -> V_92 , L_25 ) ;
if ( F_24 ( V_2 -> V_63 ) ) {
V_19 = F_26 ( V_2 -> V_63 ) ;
goto V_167;
}
V_2 -> V_21 = F_57 ( V_159 -> V_163 , F_55 ( V_159 ) ) ;
if ( V_2 -> V_21 == NULL ) {
F_25 ( & V_91 -> V_92 , L_26 ) ;
V_19 = - V_132 ;
goto V_168;
}
if ( ! V_129 -> V_169 ) {
V_2 -> V_170 = F_58 ( V_16 -> V_25 . V_156 ) ;
V_2 -> V_171 = F_59 ( & V_91 -> V_92 ,
V_2 -> V_170 , & V_2 -> V_172 , V_131 ) ;
if ( ! V_2 -> V_171 ) {
F_25 ( & V_91 -> V_92 , L_27 , V_19 ) ;
V_19 = - V_132 ;
goto V_173;
}
V_16 -> V_174 = V_2 -> V_171 ;
V_2 -> V_175 = V_2 -> V_171 ;
V_2 -> V_95 = V_2 -> V_172 ;
V_16 -> V_25 . V_176 = V_2 -> V_95 ;
} else {
V_2 -> V_171 = V_129 -> V_169 ;
V_2 -> V_172 = V_129 -> V_177 ;
V_16 -> V_174 = V_2 -> V_171 ;
V_2 -> V_175 = V_2 -> V_171 ;
V_2 -> V_95 = V_2 -> V_172 ;
V_16 -> V_25 . V_176 = V_2 -> V_95 ;
}
if ( V_129 -> V_178 ) {
V_19 = V_129 -> V_178 ( V_2 -> V_91 ) ;
if ( V_19 )
goto V_179;
}
V_2 -> V_35 = V_129 -> V_35 ;
V_2 -> V_36 = V_129 -> V_36 ;
F_60 ( & V_16 -> V_180 ) ;
for ( V_34 = 0 ; V_34 < V_129 -> V_36 ; V_34 ++ )
F_61 ( & V_129 -> V_35 [ V_34 ] . V_35 , & V_16 -> V_180 ) ;
F_8 ( & V_16 -> V_23 , V_16 ) ;
V_19 = F_62 ( & V_16 -> V_181 , 1 << V_16 -> V_23 . V_51 , 0 ) ;
if ( V_19 < 0 )
goto V_182;
F_14 ( V_16 ) ;
V_19 = F_63 ( V_16 ) ;
if ( V_19 < 0 ) {
F_25 ( & V_91 -> V_92 , L_28 ) ;
goto V_183;
}
F_29 ( V_2 ) ;
V_2 -> V_91 = V_91 ;
#ifdef F_40
F_22 ( V_2 ) ;
#endif
return 0 ;
V_183:
F_64 ( & V_16 -> V_181 ) ;
V_182:
if ( V_129 -> exit )
V_129 -> exit ( V_2 -> V_91 ) ;
V_179:
if ( ! V_129 -> V_169 )
F_65 ( & V_91 -> V_92 , V_2 -> V_170 , V_2 -> V_171 ,
V_2 -> V_172 ) ;
V_173:
F_66 ( V_2 -> V_21 ) ;
V_168:
V_167:
F_67 ( V_159 -> V_163 , F_55 ( V_159 ) ) ;
V_166:
F_68 ( V_16 -> V_29 ) ;
V_162:
F_53 ( V_91 , NULL ) ;
F_69 ( V_16 ) ;
return V_19 ;
}
static int F_70 ( struct V_125 * V_91 )
{
struct V_128 * V_129 ;
struct V_15 * V_16 = F_42 ( V_91 ) ;
struct V_1 * V_2 = V_16 -> V_17 ;
struct V_158 * V_159 ;
V_159 = F_51 ( V_91 , V_160 , 0 ) ;
F_30 ( V_2 ) ;
#ifdef F_40
F_27 ( V_2 ) ;
#endif
F_71 ( V_16 ) ;
V_129 = V_91 -> V_92 . V_130 ;
if ( V_129 -> exit )
V_129 -> exit ( V_2 -> V_91 ) ;
F_64 ( & V_16 -> V_181 ) ;
F_68 ( V_16 -> V_29 ) ;
F_69 ( V_16 ) ;
F_66 ( V_2 -> V_21 ) ;
F_67 ( V_159 -> V_163 , F_55 ( V_159 ) ) ;
F_53 ( V_91 , NULL ) ;
return 0 ;
}
void F_72 ( struct V_125 * V_92 )
{
struct V_15 * V_16 = F_42 ( V_92 ) ;
struct V_1 * V_2 = V_16 -> V_17 ;
F_30 ( V_2 ) ;
}
static int F_73 ( void )
{
#ifndef F_74
char * V_184 , * V_185 = NULL ;
if ( F_75 ( L_29 , & V_185 ) )
return - V_161 ;
if ( ! V_185 || ! * V_185 )
return 0 ;
while ( ( V_184 = F_76 ( & V_185 , L_30 ) ) != NULL ) {
if ( ! * V_184 )
continue;
else
V_38 = V_184 ;
}
#endif
return 0 ;
}
int T_5 F_77 ( void )
{
int V_19 = F_73 () ;
if ( V_19 < 0 )
return V_19 ;
return F_78 ( & V_186 , F_49 ) ;
}
static void T_6 F_79 ( void )
{
F_80 ( & V_186 ) ;
}
