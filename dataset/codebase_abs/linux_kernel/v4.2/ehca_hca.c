static unsigned int F_1 ( unsigned int V_1 )
{
return F_2 (unsigned int, value, INT_MAX) ;
}
int F_3 ( struct V_2 * V_3 , struct V_4 * V_5 ,
struct V_6 * V_7 )
{
int V_8 , V_9 = 0 ;
struct V_10 * V_11 = F_4 ( V_3 , struct V_10 ,
V_2 ) ;
struct V_12 * V_13 ;
static const T_1 V_14 [] = {
V_15 , V_16 ,
V_17 , V_18 ,
V_19 , V_20 ,
V_21 , V_22 ,
V_23 , V_24 ,
V_25 , V_26 ,
V_27 , V_28 ,
V_29 , V_30 ,
V_31 , V_32 ,
V_33 , V_34 ,
V_35 , V_36 ,
} ;
if ( V_7 -> V_37 || V_7 -> V_38 )
return - V_39 ;
V_13 = F_5 ( V_40 ) ;
if ( ! V_13 ) {
F_6 ( & V_11 -> V_2 , L_1 ) ;
return - V_41 ;
}
if ( F_7 ( V_11 -> V_42 , V_13 ) != V_43 ) {
F_6 ( & V_11 -> V_2 , L_2 ) ;
V_9 = - V_39 ;
goto V_44;
}
memset ( V_5 , 0 , sizeof( struct V_4 ) ) ;
V_5 -> V_45 = V_11 -> V_46 ;
V_5 -> V_47 = V_13 -> V_48 ;
V_5 -> V_49 = V_13 -> V_49 ;
V_5 -> V_50 = V_13 -> V_50 >> 8 ;
V_5 -> V_51 = V_13 -> V_51 >> 16 ;
V_5 -> V_48 = V_13 -> V_48 ;
V_5 -> V_52 = F_1 ( V_13 -> V_52 ) ;
V_5 -> V_53 = F_1 ( V_13 -> V_54 ) ;
V_5 -> V_55 = F_1 ( V_13 -> V_55 ) ;
V_5 -> V_56 = F_1 ( V_13 -> V_56 ) ;
V_5 -> V_57 = F_1 ( V_13 -> V_57 ) ;
V_5 -> V_58 = F_1 ( V_13 -> V_58 ) ;
V_5 -> V_59 = F_1 ( V_13 -> V_59 ) ;
V_5 -> V_60 = F_1 ( V_13 -> V_60 ) ;
V_5 -> V_61 = F_1 ( V_13 -> V_61 ) ;
V_5 -> V_62 = F_1 ( V_13 -> V_62 ) ;
V_5 -> V_63 = F_1 ( V_13 -> V_64 ) ;
V_5 -> V_65 = F_1 ( V_13 -> V_66 ) ;
V_5 -> V_67 = F_1 ( V_13 -> V_59 ) ;
V_5 -> V_68 = F_1 ( V_13 -> V_69 ) ;
V_5 -> V_70 = F_1 ( V_13 -> V_71 ) ;
V_5 -> V_72 = F_1 ( V_13 -> V_73 ) ;
V_5 -> V_74 = F_1 ( V_13 -> V_75 ) ;
V_5 -> V_76 = F_1 ( V_13 -> V_77 ) ;
if ( F_8 ( V_78 , V_11 -> V_79 ) ) {
V_5 -> V_80 = F_1 ( V_5 -> V_52 ) ;
V_5 -> V_81 = F_1 ( V_5 -> V_53 ) ;
V_5 -> V_82 = 3 ;
}
V_5 -> V_83 = 16 ;
V_5 -> V_84 = V_13 -> V_84 ?
F_2 ( V_85 , V_13 -> V_84 , 255 ) : 12 ;
V_5 -> V_86 = F_1 ( V_13 -> V_86 ) ;
V_5 -> V_87 = F_1 ( V_13 -> V_87 ) ;
V_5 -> V_88 = F_1 ( V_13 -> V_88 ) ;
V_5 -> V_89 = F_1 ( V_13 -> V_89 ) ;
V_5 -> V_90
= F_1 ( V_13 -> V_90 ) ;
V_5 -> V_91 = V_92 |
V_93 | V_94 ;
for ( V_8 = 0 ; V_8 < F_9 ( V_14 ) ; V_8 += 2 )
if ( V_13 -> V_95 & V_14 [ V_8 + 1 ] )
V_5 -> V_91 |= V_14 [ V_8 ] ;
V_44:
F_10 ( V_13 ) ;
return V_9 ;
}
static enum V_96 F_11 ( struct V_10 * V_11 , T_1 V_97 )
{
switch ( V_97 ) {
case 0x1 :
return V_98 ;
case 0x2 :
return V_99 ;
case 0x3 :
return V_100 ;
case 0x4 :
return V_101 ;
case 0x5 :
return V_102 ;
default:
F_6 ( & V_11 -> V_2 , L_3 ,
V_97 ) ;
return 0 ;
}
}
static V_85 F_12 ( struct V_10 * V_11 , T_1 V_103 )
{
switch ( V_103 ) {
case 0x1 :
return 1 ;
case 0x2 :
return 2 ;
case 0x3 :
return 4 ;
case 0x4 :
return 8 ;
case 0x5 :
return 15 ;
default:
F_6 ( & V_11 -> V_2 , L_4 ,
V_103 ) ;
return 0 ;
}
}
int F_13 ( struct V_2 * V_3 ,
V_85 V_104 , struct V_105 * V_5 )
{
int V_9 = 0 ;
T_2 V_106 ;
struct V_10 * V_11 = F_4 ( V_3 , struct V_10 ,
V_2 ) ;
struct V_107 * V_13 ;
V_13 = F_5 ( V_40 ) ;
if ( ! V_13 ) {
F_6 ( & V_11 -> V_2 , L_1 ) ;
return - V_41 ;
}
V_106 = F_14 ( V_11 -> V_42 , V_104 , V_13 ) ;
if ( V_106 != V_43 ) {
F_6 ( & V_11 -> V_2 , L_5 ) ;
V_9 = - V_39 ;
goto V_108;
}
memset ( V_5 , 0 , sizeof( struct V_105 ) ) ;
V_5 -> V_109 = V_5 -> V_110 = F_11 ( V_11 , V_13 -> V_110 ) ;
V_5 -> V_111 = V_13 -> V_112 ;
V_5 -> V_113 = V_13 -> V_113 ;
if ( V_13 -> V_114 )
V_5 -> V_114 = V_13 -> V_114 ;
else
V_5 -> V_114 = 0x1 << 31 ;
V_5 -> V_115 = V_13 -> V_115 ;
V_5 -> V_116 = V_13 -> V_116 ;
V_5 -> V_117 = V_13 -> V_117 ;
V_5 -> V_118 = V_13 -> V_118 ;
V_5 -> V_119 = V_13 -> V_119 ;
V_5 -> V_120 = V_13 -> V_120 ;
V_5 -> V_121 = V_13 -> V_121 ;
V_5 -> V_122 = V_13 -> V_122 ;
V_5 -> V_123 = V_13 -> V_123 ;
V_5 -> V_124 = F_12 ( V_11 , V_13 -> V_103 ) ;
if ( V_13 -> V_125 && V_13 -> V_126 ) {
V_5 -> V_127 = V_13 -> V_128 ;
V_5 -> V_125 = V_13 -> V_127 ;
V_5 -> V_129 = V_13 -> V_126 ;
V_5 -> V_130 = V_13 -> V_131 ;
} else {
V_5 -> V_127 = 5 ;
V_5 -> V_125 = V_13 -> V_125 ;
V_5 -> V_129 = V_132 ;
V_5 -> V_130 = V_133 ;
}
V_108:
F_10 ( V_13 ) ;
return V_9 ;
}
int F_15 ( struct V_10 * V_11 ,
V_85 V_104 , struct V_134 * V_135 )
{
int V_9 = 0 ;
T_2 V_106 ;
struct V_107 * V_13 ;
V_13 = F_5 ( V_136 ) ;
if ( ! V_13 ) {
F_6 ( & V_11 -> V_2 , L_1 ) ;
return - V_41 ;
}
V_106 = F_14 ( V_11 -> V_42 , V_104 , V_13 ) ;
if ( V_106 != V_43 ) {
F_6 ( & V_11 -> V_2 , L_5 ) ;
V_9 = - V_39 ;
goto V_137;
}
memset ( V_135 , 0 , sizeof( struct V_134 ) ) ;
V_135 -> V_118 = V_13 -> V_118 ;
V_135 -> V_120 = V_13 -> V_120 ;
V_135 -> V_121 = V_13 -> V_121 ;
V_135 -> V_119 = V_13 -> V_119 ;
V_135 -> V_117 = V_13 -> V_117 ;
memcpy ( V_135 -> V_138 , V_13 -> V_139 , sizeof( V_135 -> V_138 ) ) ;
V_137:
F_10 ( V_13 ) ;
return V_9 ;
}
int F_16 ( struct V_2 * V_3 , V_85 V_104 , T_3 V_140 , T_3 * V_141 )
{
int V_9 = 0 ;
T_2 V_106 ;
struct V_10 * V_11 ;
struct V_107 * V_13 ;
V_11 = F_4 ( V_3 , struct V_10 , V_2 ) ;
if ( V_140 > 16 ) {
F_6 ( & V_11 -> V_2 , L_6 , V_140 ) ;
return - V_39 ;
}
V_13 = F_5 ( V_40 ) ;
if ( ! V_13 ) {
F_6 ( & V_11 -> V_2 , L_1 ) ;
return - V_41 ;
}
V_106 = F_14 ( V_11 -> V_42 , V_104 , V_13 ) ;
if ( V_106 != V_43 ) {
F_6 ( & V_11 -> V_2 , L_5 ) ;
V_9 = - V_39 ;
goto V_142;
}
memcpy ( V_141 , & V_13 -> V_139 + V_140 , sizeof( T_3 ) ) ;
V_142:
F_10 ( V_13 ) ;
return V_9 ;
}
int F_17 ( struct V_2 * V_3 , V_85 V_104 ,
int V_140 , union V_143 * V_144 )
{
int V_9 = 0 ;
T_2 V_106 ;
struct V_10 * V_11 = F_4 ( V_3 , struct V_10 ,
V_2 ) ;
struct V_107 * V_13 ;
if ( V_140 < 0 || V_140 > 255 ) {
F_6 ( & V_11 -> V_2 , L_6 , V_140 ) ;
return - V_39 ;
}
V_13 = F_5 ( V_40 ) ;
if ( ! V_13 ) {
F_6 ( & V_11 -> V_2 , L_1 ) ;
return - V_41 ;
}
V_106 = F_14 ( V_11 -> V_42 , V_104 , V_13 ) ;
if ( V_106 != V_43 ) {
F_6 ( & V_11 -> V_2 , L_5 ) ;
V_9 = - V_39 ;
goto V_145;
}
memcpy ( & V_144 -> V_146 [ 0 ] , & V_13 -> V_147 , sizeof( T_2 ) ) ;
memcpy ( & V_144 -> V_146 [ 8 ] , & V_13 -> V_148 [ V_140 ] , sizeof( T_2 ) ) ;
V_145:
F_10 ( V_13 ) ;
return V_9 ;
}
int F_18 ( struct V_2 * V_3 ,
V_85 V_104 , int V_149 ,
struct V_150 * V_5 )
{
int V_9 = 0 ;
struct V_10 * V_11 ;
struct V_107 * V_13 ;
T_1 V_151 ;
T_2 V_152 ;
V_11 = F_4 ( V_3 , struct V_10 , V_2 ) ;
if ( ( V_5 -> V_153 | V_5 -> V_154 )
& ~ V_155 ) {
F_6 ( & V_11 -> V_2 , L_7
L_8 , V_5 -> V_153 ,
V_5 -> V_154 , V_155 ) ;
return - V_39 ;
}
if ( F_19 ( & V_11 -> V_156 ) )
return - V_157 ;
V_13 = F_5 ( V_40 ) ;
if ( ! V_13 ) {
F_6 ( & V_11 -> V_2 , L_1 ) ;
V_9 = - V_41 ;
goto V_158;
}
V_152 = F_14 ( V_11 -> V_42 , V_104 , V_13 ) ;
if ( V_152 != V_43 ) {
F_6 ( & V_11 -> V_2 , L_5 ) ;
V_9 = - V_39 ;
goto V_159;
}
V_151 = ( V_13 -> V_112 | V_5 -> V_153 )
& ~ V_5 -> V_154 ;
V_152 = F_20 ( V_11 -> V_42 , V_104 ,
V_151 , V_5 -> V_160 , V_149 ) ;
if ( V_152 != V_43 ) {
F_6 ( & V_11 -> V_2 , L_9 ,
V_152 ) ;
V_9 = - V_39 ;
}
V_159:
F_10 ( V_13 ) ;
V_158:
F_21 ( & V_11 -> V_156 ) ;
return V_9 ;
}
