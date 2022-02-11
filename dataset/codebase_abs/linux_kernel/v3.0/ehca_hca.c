static unsigned int F_1 ( unsigned int V_1 )
{
return F_2 (unsigned int, value, INT_MAX) ;
}
int F_3 ( struct V_2 * V_3 , struct V_4 * V_5 )
{
int V_6 , V_7 = 0 ;
struct V_8 * V_9 = F_4 ( V_3 , struct V_8 ,
V_2 ) ;
struct V_10 * V_11 ;
static const T_1 V_12 [] = {
V_13 , V_14 ,
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
} ;
V_11 = F_5 ( V_35 ) ;
if ( ! V_11 ) {
F_6 ( & V_9 -> V_2 , L_1 ) ;
return - V_36 ;
}
if ( F_7 ( V_9 -> V_37 , V_11 ) != V_38 ) {
F_6 ( & V_9 -> V_2 , L_2 ) ;
V_7 = - V_39 ;
goto V_40;
}
memset ( V_5 , 0 , sizeof( struct V_4 ) ) ;
V_5 -> V_41 = V_9 -> V_42 ;
V_5 -> V_43 = V_11 -> V_44 ;
V_5 -> V_45 = V_11 -> V_45 ;
V_5 -> V_46 = V_11 -> V_46 >> 8 ;
V_5 -> V_47 = V_11 -> V_47 >> 16 ;
V_5 -> V_44 = V_11 -> V_44 ;
V_5 -> V_48 = F_1 ( V_11 -> V_48 ) ;
V_5 -> V_49 = F_1 ( V_11 -> V_50 ) ;
V_5 -> V_51 = F_1 ( V_11 -> V_51 ) ;
V_5 -> V_52 = F_1 ( V_11 -> V_52 ) ;
V_5 -> V_53 = F_1 ( V_11 -> V_53 ) ;
V_5 -> V_54 = F_1 ( V_11 -> V_54 ) ;
V_5 -> V_55 = F_1 ( V_11 -> V_55 ) ;
V_5 -> V_56 = F_1 ( V_11 -> V_56 ) ;
V_5 -> V_57 = F_1 ( V_11 -> V_57 ) ;
V_5 -> V_58 = F_1 ( V_11 -> V_58 ) ;
V_5 -> V_59 = F_1 ( V_11 -> V_60 ) ;
V_5 -> V_61 = F_1 ( V_11 -> V_62 ) ;
V_5 -> V_63 = F_1 ( V_11 -> V_55 ) ;
V_5 -> V_64 = F_1 ( V_11 -> V_65 ) ;
V_5 -> V_66 = F_1 ( V_11 -> V_67 ) ;
V_5 -> V_68 = F_1 ( V_11 -> V_69 ) ;
V_5 -> V_70 = F_1 ( V_11 -> V_71 ) ;
V_5 -> V_72 = F_1 ( V_11 -> V_73 ) ;
if ( F_8 ( V_74 , V_9 -> V_75 ) ) {
V_5 -> V_76 = F_1 ( V_5 -> V_48 ) ;
V_5 -> V_77 = F_1 ( V_5 -> V_49 ) ;
V_5 -> V_78 = 3 ;
}
V_5 -> V_79 = 16 ;
V_5 -> V_80 = V_11 -> V_80 ?
F_2 ( V_81 , V_11 -> V_80 , 255 ) : 12 ;
V_5 -> V_82 = F_1 ( V_11 -> V_82 ) ;
V_5 -> V_83 = F_1 ( V_11 -> V_83 ) ;
V_5 -> V_84 = F_1 ( V_11 -> V_84 ) ;
V_5 -> V_85 = F_1 ( V_11 -> V_85 ) ;
V_5 -> V_86
= F_1 ( V_11 -> V_86 ) ;
V_5 -> V_87 = V_88 |
V_89 | V_90 ;
for ( V_6 = 0 ; V_6 < F_9 ( V_12 ) ; V_6 += 2 )
if ( V_11 -> V_91 & V_12 [ V_6 + 1 ] )
V_5 -> V_87 |= V_12 [ V_6 ] ;
V_40:
F_10 ( V_11 ) ;
return V_7 ;
}
static enum V_92 F_11 ( struct V_8 * V_9 , T_1 V_93 )
{
switch ( V_93 ) {
case 0x1 :
return V_94 ;
case 0x2 :
return V_95 ;
case 0x3 :
return V_96 ;
case 0x4 :
return V_97 ;
case 0x5 :
return V_98 ;
default:
F_6 ( & V_9 -> V_2 , L_3 ,
V_93 ) ;
return 0 ;
}
}
static V_81 F_12 ( struct V_8 * V_9 , T_1 V_99 )
{
switch ( V_99 ) {
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
F_6 ( & V_9 -> V_2 , L_4 ,
V_99 ) ;
return 0 ;
}
}
int F_13 ( struct V_2 * V_3 ,
V_81 V_100 , struct V_101 * V_5 )
{
int V_7 = 0 ;
T_2 V_102 ;
struct V_8 * V_9 = F_4 ( V_3 , struct V_8 ,
V_2 ) ;
struct V_103 * V_11 ;
V_11 = F_5 ( V_35 ) ;
if ( ! V_11 ) {
F_6 ( & V_9 -> V_2 , L_1 ) ;
return - V_36 ;
}
V_102 = F_14 ( V_9 -> V_37 , V_100 , V_11 ) ;
if ( V_102 != V_38 ) {
F_6 ( & V_9 -> V_2 , L_5 ) ;
V_7 = - V_39 ;
goto V_104;
}
memset ( V_5 , 0 , sizeof( struct V_101 ) ) ;
V_5 -> V_105 = V_5 -> V_106 = F_11 ( V_9 , V_11 -> V_106 ) ;
V_5 -> V_107 = V_11 -> V_108 ;
V_5 -> V_109 = V_11 -> V_109 ;
if ( V_11 -> V_110 )
V_5 -> V_110 = V_11 -> V_110 ;
else
V_5 -> V_110 = 0x1 << 31 ;
V_5 -> V_111 = V_11 -> V_111 ;
V_5 -> V_112 = V_11 -> V_112 ;
V_5 -> V_113 = V_11 -> V_113 ;
V_5 -> V_114 = V_11 -> V_114 ;
V_5 -> V_115 = V_11 -> V_115 ;
V_5 -> V_116 = V_11 -> V_116 ;
V_5 -> V_117 = V_11 -> V_117 ;
V_5 -> V_118 = V_11 -> V_118 ;
V_5 -> V_119 = V_11 -> V_119 ;
V_5 -> V_120 = F_12 ( V_9 , V_11 -> V_99 ) ;
if ( V_11 -> V_121 && V_11 -> V_122 ) {
V_5 -> V_123 = V_11 -> V_124 ;
V_5 -> V_121 = V_11 -> V_123 ;
V_5 -> V_125 = V_11 -> V_122 ;
V_5 -> V_126 = V_11 -> V_127 ;
} else {
V_5 -> V_123 = 5 ;
V_5 -> V_121 = V_11 -> V_121 ;
V_5 -> V_125 = V_128 ;
V_5 -> V_126 = 0x1 ;
}
V_104:
F_10 ( V_11 ) ;
return V_7 ;
}
int F_15 ( struct V_8 * V_9 ,
V_81 V_100 , struct V_129 * V_130 )
{
int V_7 = 0 ;
T_2 V_102 ;
struct V_103 * V_11 ;
V_11 = F_5 ( V_131 ) ;
if ( ! V_11 ) {
F_6 ( & V_9 -> V_2 , L_1 ) ;
return - V_36 ;
}
V_102 = F_14 ( V_9 -> V_37 , V_100 , V_11 ) ;
if ( V_102 != V_38 ) {
F_6 ( & V_9 -> V_2 , L_5 ) ;
V_7 = - V_39 ;
goto V_132;
}
memset ( V_130 , 0 , sizeof( struct V_129 ) ) ;
V_130 -> V_114 = V_11 -> V_114 ;
V_130 -> V_116 = V_11 -> V_116 ;
V_130 -> V_117 = V_11 -> V_117 ;
V_130 -> V_115 = V_11 -> V_115 ;
V_130 -> V_113 = V_11 -> V_113 ;
memcpy ( V_130 -> V_133 , V_11 -> V_134 , sizeof( V_130 -> V_133 ) ) ;
V_132:
F_10 ( V_11 ) ;
return V_7 ;
}
int F_16 ( struct V_2 * V_3 , V_81 V_100 , T_3 V_135 , T_3 * V_136 )
{
int V_7 = 0 ;
T_2 V_102 ;
struct V_8 * V_9 ;
struct V_103 * V_11 ;
V_9 = F_4 ( V_3 , struct V_8 , V_2 ) ;
if ( V_135 > 16 ) {
F_6 ( & V_9 -> V_2 , L_6 , V_135 ) ;
return - V_39 ;
}
V_11 = F_5 ( V_35 ) ;
if ( ! V_11 ) {
F_6 ( & V_9 -> V_2 , L_1 ) ;
return - V_36 ;
}
V_102 = F_14 ( V_9 -> V_37 , V_100 , V_11 ) ;
if ( V_102 != V_38 ) {
F_6 ( & V_9 -> V_2 , L_5 ) ;
V_7 = - V_39 ;
goto V_137;
}
memcpy ( V_136 , & V_11 -> V_134 + V_135 , sizeof( T_3 ) ) ;
V_137:
F_10 ( V_11 ) ;
return V_7 ;
}
int F_17 ( struct V_2 * V_3 , V_81 V_100 ,
int V_135 , union V_138 * V_139 )
{
int V_7 = 0 ;
T_2 V_102 ;
struct V_8 * V_9 = F_4 ( V_3 , struct V_8 ,
V_2 ) ;
struct V_103 * V_11 ;
if ( V_135 < 0 || V_135 > 255 ) {
F_6 ( & V_9 -> V_2 , L_6 , V_135 ) ;
return - V_39 ;
}
V_11 = F_5 ( V_35 ) ;
if ( ! V_11 ) {
F_6 ( & V_9 -> V_2 , L_1 ) ;
return - V_36 ;
}
V_102 = F_14 ( V_9 -> V_37 , V_100 , V_11 ) ;
if ( V_102 != V_38 ) {
F_6 ( & V_9 -> V_2 , L_5 ) ;
V_7 = - V_39 ;
goto V_140;
}
memcpy ( & V_139 -> V_141 [ 0 ] , & V_11 -> V_142 , sizeof( T_2 ) ) ;
memcpy ( & V_139 -> V_141 [ 8 ] , & V_11 -> V_143 [ V_135 ] , sizeof( T_2 ) ) ;
V_140:
F_10 ( V_11 ) ;
return V_7 ;
}
int F_18 ( struct V_2 * V_3 ,
V_81 V_100 , int V_144 ,
struct V_145 * V_5 )
{
int V_7 = 0 ;
struct V_8 * V_9 ;
struct V_103 * V_11 ;
T_1 V_146 ;
T_2 V_147 ;
V_9 = F_4 ( V_3 , struct V_8 , V_2 ) ;
if ( ( V_5 -> V_148 | V_5 -> V_149 )
& ~ V_150 ) {
F_6 ( & V_9 -> V_2 , L_7
L_8 , V_5 -> V_148 ,
V_5 -> V_149 , V_150 ) ;
return - V_39 ;
}
if ( F_19 ( & V_9 -> V_151 ) )
return - V_152 ;
V_11 = F_5 ( V_35 ) ;
if ( ! V_11 ) {
F_6 ( & V_9 -> V_2 , L_1 ) ;
V_7 = - V_36 ;
goto V_153;
}
V_147 = F_14 ( V_9 -> V_37 , V_100 , V_11 ) ;
if ( V_147 != V_38 ) {
F_6 ( & V_9 -> V_2 , L_5 ) ;
V_7 = - V_39 ;
goto V_154;
}
V_146 = ( V_11 -> V_108 | V_5 -> V_148 )
& ~ V_5 -> V_149 ;
V_147 = F_20 ( V_9 -> V_37 , V_100 ,
V_146 , V_5 -> V_155 , V_144 ) ;
if ( V_147 != V_38 ) {
F_6 ( & V_9 -> V_2 , L_9 ,
V_147 ) ;
V_7 = - V_39 ;
}
V_154:
F_10 ( V_11 ) ;
V_153:
F_21 ( & V_9 -> V_151 ) ;
return V_7 ;
}
