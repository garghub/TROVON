static int T_1 F_1 ( void )
{
int V_1 , V_2 , V_3 ;
int V_4 ;
V_3 = F_2 ( V_5 ) - 2 * V_6 - 1 ;
V_2 = F_2 ( V_7 ) - V_6 - 1 ;
for ( V_1 = 0 ; V_1 < F_3 ( V_8 , V_9 ) ; V_1 ++ , V_2 ++ , V_3 ++ ) {
V_7 [ V_2 ] . V_10 = V_11 [ V_1 ] ;
V_7 [ V_2 ] . V_12 = V_13 [ V_1 ] ;
V_7 [ V_2 ] . V_14 = V_15 ;
V_5 [ V_3 ] . V_10 = V_11 [ V_1 ] ;
V_5 [ V_3 ] . V_12 = V_13 [ V_1 ] ;
V_5 [ V_3 ] . V_14 = V_15 ;
}
V_2 = F_2 ( V_16 ) - V_6 - 1 ;
for ( V_1 = 0 ; V_1 < F_3 ( V_17 , V_18 ) ; V_1 ++ , V_2 ++ , V_3 ++ ) {
V_16 [ V_2 ] . V_10 = V_19 [ V_1 ] ;
V_16 [ V_2 ] . V_12 = V_20 [ V_1 ] ;
V_16 [ V_2 ] . V_14 = V_15 ;
V_5 [ V_3 ] . V_10 = V_19 [ V_1 ] ;
V_5 [ V_3 ] . V_12 = V_20 [ V_1 ] ;
V_5 [ V_3 ] . V_14 = V_15 ;
}
V_4 = F_4 ( & V_21 ) ;
if ( V_4 )
goto V_22;
V_4 = F_4 ( & V_23 ) ;
if ( V_4 )
goto V_24;
V_4 = F_5 ( & V_25 ) ;
if ( V_4 )
goto V_26;
F_6 (KERN_INFO KBUILD_MODNAME L_1 TI_DRIVER_VERSION L_2
TI_DRIVER_DESC L_3 ) ;
return 0 ;
V_26:
F_7 ( & V_23 ) ;
V_24:
F_7 ( & V_21 ) ;
V_22:
return V_4 ;
}
static void T_2 F_8 ( void )
{
F_9 ( & V_25 ) ;
F_7 ( & V_21 ) ;
F_7 ( & V_23 ) ;
}
static int F_10 ( struct V_27 * V_28 )
{
struct V_29 * V_30 ;
struct V_31 * V_32 ;
struct V_33 * V_34 = V_28 -> V_34 ;
int V_35 ;
int V_1 ;
F_11 ( L_4 ,
V_36 , F_12 ( V_34 -> V_37 . V_12 ) ,
V_34 -> V_37 . V_38 ,
V_34 -> V_39 -> V_40 . V_41 ) ;
V_30 = F_13 ( sizeof( struct V_29 ) , V_42 ) ;
if ( V_30 == NULL ) {
F_14 ( & V_34 -> V_34 , L_5 , V_36 ) ;
return - V_43 ;
}
F_15 ( & V_30 -> V_44 ) ;
V_30 -> V_45 = V_28 ;
F_16 ( V_28 , V_30 ) ;
if ( F_17 ( V_28 -> V_46 , V_7 ) )
V_30 -> V_47 = 1 ;
F_11 ( L_6 , V_36 ,
V_30 -> V_47 ? L_7 : L_8 ) ;
if ( V_34 -> V_37 . V_38 == 1 ) {
if ( ( V_35 = F_18 ( V_30 ) ) != 0 )
goto V_48;
if ( V_30 -> V_47 ) {
F_19 ( 100 ) ;
F_20 ( V_34 ) ;
}
V_35 = - V_49 ;
goto V_48;
}
if ( V_34 -> V_39 -> V_40 . V_41 == V_50 ) {
V_35 = F_21 ( V_34 , V_51 ) ;
V_35 = V_35 ? V_35 : - V_49 ;
goto V_48;
}
for ( V_1 = 0 ; V_1 < V_28 -> V_52 ; ++ V_1 ) {
V_32 = F_13 ( sizeof( struct V_31 ) , V_42 ) ;
if ( V_32 == NULL ) {
F_14 ( & V_34 -> V_34 , L_5 , V_36 ) ;
V_35 = - V_43 ;
goto V_53;
}
F_22 ( & V_32 -> V_54 ) ;
V_32 -> V_55 = ( V_1 == 0 ?
V_56 : V_57 ) ;
V_32 -> V_58 = V_59 ;
F_23 ( & V_32 -> V_60 ) ;
F_23 ( & V_32 -> V_61 ) ;
if ( F_24 ( & V_32 -> V_62 , V_63 ,
V_42 ) ) {
F_14 ( & V_34 -> V_34 , L_5 , V_36 ) ;
F_25 ( V_32 ) ;
V_35 = - V_43 ;
goto V_53;
}
V_32 -> V_64 = V_28 -> V_65 [ V_1 ] ;
V_32 -> V_66 = V_30 ;
F_26 ( V_28 -> V_65 [ V_1 ] , V_32 ) ;
V_32 -> V_67 = 0 ;
}
return 0 ;
V_53:
for ( -- V_1 ; V_1 >= 0 ; -- V_1 ) {
V_32 = F_27 ( V_28 -> V_65 [ V_1 ] ) ;
F_28 ( & V_32 -> V_62 ) ;
F_25 ( V_32 ) ;
F_26 ( V_28 -> V_65 [ V_1 ] , NULL ) ;
}
V_48:
F_25 ( V_30 ) ;
F_16 ( V_28 , NULL ) ;
return V_35 ;
}
static void F_29 ( struct V_27 * V_28 )
{
int V_1 ;
struct V_29 * V_30 = F_30 ( V_28 ) ;
struct V_31 * V_32 ;
F_11 ( L_9 , V_36 ) ;
for ( V_1 = 0 ; V_1 < V_28 -> V_52 ; ++ V_1 ) {
V_32 = F_27 ( V_28 -> V_65 [ V_1 ] ) ;
if ( V_32 ) {
F_28 ( & V_32 -> V_62 ) ;
F_25 ( V_32 ) ;
}
}
F_25 ( V_30 ) ;
}
static int F_31 ( struct V_68 * V_69 , struct V_70 * V_65 )
{
struct V_31 * V_32 = F_27 ( V_65 ) ;
struct V_29 * V_30 ;
struct V_33 * V_34 ;
struct V_71 * V_71 ;
int V_72 ;
int V_35 ;
T_3 V_73 = ( V_74 ) ( V_75 |
V_76 |
( V_77 << 2 ) ) ;
F_11 ( L_10 , V_36 , V_65 -> V_78 ) ;
if ( V_32 == NULL )
return - V_49 ;
V_34 = V_65 -> V_28 -> V_34 ;
V_30 = V_32 -> V_66 ;
if ( F_32 ( & V_30 -> V_44 ) )
return - V_79 ;
V_72 = V_65 -> V_78 - V_65 -> V_28 -> V_80 ;
memset ( & ( V_32 -> V_81 ) , 0x00 , sizeof( V_32 -> V_81 ) ) ;
V_32 -> V_82 = 0 ;
V_32 -> V_83 |= ( V_84 | V_85 ) ;
if ( V_30 -> V_86 == 0 ) {
F_11 ( L_11 , V_36 ) ;
V_71 = V_30 -> V_45 -> V_65 [ 0 ] -> V_87 ;
if ( ! V_71 ) {
F_14 ( & V_65 -> V_34 , L_12 ,
V_36 ) ;
V_35 = - V_88 ;
goto V_89;
}
V_71 -> V_90 = V_91 ;
V_71 -> V_92 = V_30 ;
V_71 -> V_34 = V_34 ;
V_35 = F_33 ( V_71 , V_42 ) ;
if ( V_35 ) {
F_14 ( & V_65 -> V_34 ,
L_13 ,
V_36 , V_35 ) ;
goto V_89;
}
}
if ( V_69 )
F_34 ( V_69 , V_65 , V_69 -> V_93 ) ;
F_11 ( L_14 , V_36 ) ;
V_35 = F_35 ( V_30 , V_94 ,
( V_74 ) ( V_95 + V_72 ) , V_73 , NULL , 0 ) ;
if ( V_35 ) {
F_14 ( & V_65 -> V_34 , L_15 ,
V_36 , V_35 ) ;
goto V_96;
}
F_11 ( L_16 , V_36 ) ;
V_35 = F_35 ( V_30 , V_97 ,
( V_74 ) ( V_95 + V_72 ) , 0 , NULL , 0 ) ;
if ( V_35 ) {
F_14 ( & V_65 -> V_34 , L_17 ,
V_36 , V_35 ) ;
goto V_96;
}
F_11 ( L_18 , V_36 ) ;
V_35 = F_35 ( V_30 , V_98 ,
( V_74 ) ( V_95 + V_72 ) , V_99 , NULL , 0 ) ;
if ( V_35 ) {
F_14 ( & V_65 -> V_34 , L_19 ,
V_36 , V_35 ) ;
goto V_96;
}
V_35 = F_35 ( V_30 , V_98 ,
( V_74 ) ( V_95 + V_72 ) , V_100 , NULL , 0 ) ;
if ( V_35 ) {
F_14 ( & V_65 -> V_34 , L_20 ,
V_36 , V_35 ) ;
goto V_96;
}
F_36 ( V_34 , V_65 -> V_101 -> V_102 ) ;
F_36 ( V_34 , V_65 -> V_103 -> V_102 ) ;
if ( V_69 )
F_34 ( V_69 , V_65 , V_69 -> V_93 ) ;
F_11 ( L_21 , V_36 ) ;
V_35 = F_35 ( V_30 , V_94 ,
( V_74 ) ( V_95 + V_72 ) , V_73 , NULL , 0 ) ;
if ( V_35 ) {
F_14 ( & V_65 -> V_34 , L_22 ,
V_36 , V_35 ) ;
goto V_96;
}
F_11 ( L_23 , V_36 ) ;
V_35 = F_35 ( V_30 , V_97 ,
( V_74 ) ( V_95 + V_72 ) , 0 , NULL , 0 ) ;
if ( V_35 ) {
F_14 ( & V_65 -> V_34 , L_24 ,
V_36 , V_35 ) ;
goto V_96;
}
F_11 ( L_25 , V_36 ) ;
V_71 = V_65 -> V_103 ;
if ( ! V_71 ) {
F_14 ( & V_65 -> V_34 , L_26 , V_36 ) ;
V_35 = - V_88 ;
goto V_96;
}
V_32 -> V_104 = V_105 ;
V_71 -> V_90 = V_106 ;
V_71 -> V_92 = V_32 ;
V_71 -> V_34 = V_34 ;
V_35 = F_33 ( V_71 , V_42 ) ;
if ( V_35 ) {
F_14 ( & V_65 -> V_34 , L_27 ,
V_36 , V_35 ) ;
goto V_96;
}
V_32 -> V_107 = 1 ;
++ V_30 -> V_86 ;
goto V_89;
V_96:
if ( V_30 -> V_86 == 0 )
F_37 ( V_65 -> V_28 -> V_65 [ 0 ] -> V_87 ) ;
V_89:
F_38 ( & V_30 -> V_44 ) ;
F_11 ( L_28 , V_36 , V_35 ) ;
return V_35 ;
}
static void F_39 ( struct V_70 * V_65 )
{
struct V_29 * V_30 ;
struct V_31 * V_32 ;
int V_72 ;
int V_35 ;
int V_108 ;
F_11 ( L_10 , V_36 , V_65 -> V_78 ) ;
V_30 = F_30 ( V_65 -> V_28 ) ;
V_32 = F_27 ( V_65 ) ;
if ( V_30 == NULL || V_32 == NULL )
return;
V_32 -> V_107 = 0 ;
F_40 ( V_32 , ( V_32 -> V_58 * V_109 ) / 100 , 1 ) ;
F_37 ( V_65 -> V_103 ) ;
F_37 ( V_65 -> V_101 ) ;
V_32 -> V_110 = 0 ;
V_72 = V_65 -> V_78 - V_65 -> V_28 -> V_80 ;
F_11 ( L_29 , V_36 ) ;
V_35 = F_35 ( V_30 , V_111 ,
( V_74 ) ( V_95 + V_72 ) , 0 , NULL , 0 ) ;
if ( V_35 )
F_14 ( & V_65 -> V_34 ,
L_30
, V_36 , V_35 ) ;
V_108 = ! F_32 ( & V_30 -> V_44 ) ;
-- V_32 -> V_66 -> V_86 ;
if ( V_32 -> V_66 -> V_86 <= 0 ) {
F_37 ( V_65 -> V_28 -> V_65 [ 0 ] -> V_87 ) ;
V_32 -> V_66 -> V_86 = 0 ;
}
if ( V_108 )
F_38 ( & V_30 -> V_44 ) ;
F_11 ( L_31 , V_36 ) ;
}
static int F_41 ( struct V_68 * V_69 , struct V_70 * V_65 ,
const unsigned char * V_112 , int V_113 )
{
struct V_31 * V_32 = F_27 ( V_65 ) ;
F_11 ( L_10 , V_36 , V_65 -> V_78 ) ;
if ( V_113 == 0 ) {
F_11 ( L_32 , V_36 ) ;
return 0 ;
}
if ( V_32 == NULL || ! V_32 -> V_107 )
return - V_49 ;
V_113 = F_42 ( & V_32 -> V_62 , V_112 , V_113 ,
& V_32 -> V_54 ) ;
F_43 ( V_32 ) ;
return V_113 ;
}
static int F_44 ( struct V_68 * V_69 )
{
struct V_70 * V_65 = V_69 -> V_114 ;
struct V_31 * V_32 = F_27 ( V_65 ) ;
int V_115 = 0 ;
unsigned long V_116 ;
F_11 ( L_10 , V_36 , V_65 -> V_78 ) ;
if ( V_32 == NULL )
return 0 ;
F_45 ( & V_32 -> V_54 , V_116 ) ;
V_115 = F_46 ( & V_32 -> V_62 ) ;
F_47 ( & V_32 -> V_54 , V_116 ) ;
F_11 ( L_33 , V_36 , V_115 ) ;
return V_115 ;
}
static int F_48 ( struct V_68 * V_69 )
{
struct V_70 * V_65 = V_69 -> V_114 ;
struct V_31 * V_32 = F_27 ( V_65 ) ;
int V_117 = 0 ;
unsigned long V_116 ;
F_11 ( L_10 , V_36 , V_65 -> V_78 ) ;
if ( V_32 == NULL )
return 0 ;
F_45 ( & V_32 -> V_54 , V_116 ) ;
V_117 = F_49 ( & V_32 -> V_62 ) ;
F_47 ( & V_32 -> V_54 , V_116 ) ;
F_11 ( L_33 , V_36 , V_117 ) ;
return V_117 ;
}
static void F_50 ( struct V_68 * V_69 )
{
struct V_70 * V_65 = V_69 -> V_114 ;
struct V_31 * V_32 = F_27 ( V_65 ) ;
F_11 ( L_10 , V_36 , V_65 -> V_78 ) ;
if ( V_32 == NULL )
return;
if ( F_51 ( V_69 ) || F_52 ( V_69 ) )
F_53 ( V_32 , V_69 ) ;
}
static void F_54 ( struct V_68 * V_69 )
{
struct V_70 * V_65 = V_69 -> V_114 ;
struct V_31 * V_32 = F_27 ( V_65 ) ;
int V_35 ;
F_11 ( L_10 , V_36 , V_65 -> V_78 ) ;
if ( V_32 == NULL )
return;
if ( F_51 ( V_69 ) || F_52 ( V_69 ) ) {
V_35 = F_55 ( V_32 , V_69 ) ;
if ( V_35 )
F_14 ( & V_65 -> V_34 , L_34 ,
V_36 , V_35 ) ;
}
}
static int F_56 ( struct V_68 * V_69 ,
struct V_118 * V_119 )
{
struct V_70 * V_65 = V_69 -> V_114 ;
struct V_31 * V_32 = F_27 ( V_65 ) ;
struct V_120 V_121 = V_32 -> V_81 ;
F_11 ( L_35 ,
V_36 , V_65 -> V_78 ,
V_121 . V_122 , V_121 . V_123 ) ;
V_119 -> V_124 = V_121 . V_124 ;
V_119 -> V_125 = V_121 . V_125 ;
V_119 -> V_126 = V_121 . V_126 ;
V_119 -> V_127 = V_121 . V_127 ;
V_119 -> V_122 = V_121 . V_122 ;
V_119 -> V_123 = V_121 . V_123 ;
V_119 -> V_128 = V_121 . V_128 ;
V_119 -> V_129 = V_121 . V_129 ;
V_119 -> V_130 = V_121 . V_130 ;
V_119 -> V_131 = V_121 . V_131 ;
V_119 -> V_132 = V_121 . V_132 ;
return 0 ;
}
static int F_57 ( struct V_68 * V_69 ,
unsigned int V_133 , unsigned long V_134 )
{
struct V_70 * V_65 = V_69 -> V_114 ;
struct V_31 * V_32 = F_27 ( V_65 ) ;
struct V_120 V_121 ;
struct V_120 V_135 ;
F_11 ( L_36 , V_36 , V_65 -> V_78 , V_133 ) ;
if ( V_32 == NULL )
return - V_49 ;
switch ( V_133 ) {
case V_136 :
F_11 ( L_37 , V_36 , V_65 -> V_78 ) ;
return F_58 ( V_32 ,
(struct V_137 V_138 * ) V_134 ) ;
case V_139 :
F_11 ( L_38 , V_36 , V_65 -> V_78 ) ;
return F_59 ( V_69 , V_32 ,
(struct V_137 V_138 * ) V_134 ) ;
case V_140 :
F_11 ( L_39 , V_36 , V_65 -> V_78 ) ;
V_135 = V_32 -> V_81 ;
while ( 1 ) {
F_60 ( & V_32 -> V_60 ) ;
if ( F_61 ( V_141 ) )
return - V_79 ;
V_121 = V_32 -> V_81 ;
if ( V_121 . V_126 == V_135 . V_126 && V_121 . V_125 == V_135 . V_125 &&
V_121 . V_127 == V_135 . V_127 && V_121 . V_124 == V_135 . V_124 )
return - V_142 ;
if ( ( ( V_134 & V_143 ) && ( V_121 . V_126 != V_135 . V_126 ) ) ||
( ( V_134 & V_144 ) && ( V_121 . V_125 != V_135 . V_125 ) ) ||
( ( V_134 & V_145 ) && ( V_121 . V_127 != V_135 . V_127 ) ) ||
( ( V_134 & V_146 ) && ( V_121 . V_124 != V_135 . V_124 ) ) )
return 0 ;
V_135 = V_121 ;
}
break;
}
return - V_147 ;
}
static void F_34 ( struct V_68 * V_69 ,
struct V_70 * V_65 , struct V_148 * V_149 )
{
struct V_31 * V_32 = F_27 ( V_65 ) ;
struct V_150 * V_151 ;
T_4 V_152 , V_153 ;
int V_154 ;
int V_35 ;
int V_72 = V_65 -> V_78 - V_65 -> V_28 -> V_80 ;
unsigned int V_155 ;
F_11 ( L_10 , V_36 , V_65 -> V_78 ) ;
V_152 = V_69 -> V_93 -> V_156 ;
V_153 = V_69 -> V_93 -> V_157 ;
F_11 ( L_40 , V_36 , V_152 , V_153 ) ;
F_11 ( L_41 , V_36 ,
V_149 -> V_156 , V_149 -> V_157 ) ;
if ( V_32 == NULL )
return;
V_151 = F_62 ( sizeof( * V_151 ) , V_42 ) ;
if ( ! V_151 ) {
F_14 ( & V_65 -> V_34 , L_5 , V_36 ) ;
return;
}
V_151 -> V_158 = 0 ;
V_151 -> V_158 |= V_159 ;
V_151 -> V_158 |= V_160 ;
V_151 -> V_161 = ( V_74 ) ( V_32 -> V_67 ) ;
switch ( V_152 & V_162 ) {
case V_163 :
V_151 -> V_164 = V_165 ;
break;
case V_166 :
V_151 -> V_164 = V_167 ;
break;
case V_168 :
V_151 -> V_164 = V_169 ;
break;
default:
case V_170 :
V_151 -> V_164 = V_171 ;
break;
}
V_69 -> V_93 -> V_156 &= ~ V_172 ;
if ( V_152 & V_173 ) {
if ( V_152 & V_174 ) {
V_151 -> V_158 |= V_175 ;
V_151 -> V_176 = V_177 ;
} else {
V_151 -> V_158 |= V_175 ;
V_151 -> V_176 = V_178 ;
}
} else {
V_151 -> V_158 &= ~ V_175 ;
V_151 -> V_176 = V_179 ;
}
if ( V_152 & V_180 )
V_151 -> V_181 = V_182 ;
else
V_151 -> V_181 = V_183 ;
if ( V_152 & V_184 ) {
if ( ( V_152 & V_185 ) != V_186 )
V_151 -> V_158 |= V_187 ;
V_151 -> V_158 |= V_188 ;
} else {
V_69 -> V_189 = 0 ;
F_55 ( V_32 , V_69 ) ;
}
if ( F_51 ( V_69 ) || F_63 ( V_69 ) ) {
V_151 -> V_190 = F_64 ( V_69 ) ;
V_151 -> V_191 = F_65 ( V_69 ) ;
if ( F_51 ( V_69 ) )
V_151 -> V_158 |= V_192 ;
else
F_55 ( V_32 , V_69 ) ;
if ( F_63 ( V_69 ) )
V_151 -> V_158 |= V_193 ;
}
V_154 = F_66 ( V_69 ) ;
if ( ! V_154 )
V_154 = 9600 ;
if ( V_32 -> V_66 -> V_47 )
V_151 -> V_194 = ( T_3 ) ( ( 923077 + V_154 / 2 ) / V_154 ) ;
else
V_151 -> V_194 = ( T_3 ) ( ( 461538 + V_154 / 2 ) / V_154 ) ;
if ( ( V_152 & V_185 ) != V_186 )
F_67 ( V_69 , V_154 , V_154 ) ;
F_11 ( L_42 ,
V_36 , V_154 , V_151 -> V_194 , V_151 -> V_158 , V_151 -> V_164 , V_151 -> V_176 , V_151 -> V_181 , V_151 -> V_190 , V_151 -> V_191 , V_151 -> V_161 ) ;
F_68 ( & V_151 -> V_194 ) ;
F_68 ( & V_151 -> V_158 ) ;
V_35 = F_35 ( V_32 -> V_66 , V_195 ,
( V_74 ) ( V_95 + V_72 ) , 0 , ( V_74 * ) V_151 ,
sizeof( * V_151 ) ) ;
if ( V_35 )
F_14 ( & V_65 -> V_34 , L_43 ,
V_36 , V_72 , V_35 ) ;
V_155 = V_32 -> V_83 ;
if ( ( V_152 & V_185 ) == V_186 )
V_155 &= ~ ( V_85 | V_84 ) ;
V_35 = F_69 ( V_32 , V_155 ) ;
if ( V_35 )
F_14 ( & V_65 -> V_34 ,
L_44 ,
V_36 , V_72 , V_35 ) ;
F_25 ( V_151 ) ;
}
static int F_70 ( struct V_68 * V_69 )
{
struct V_70 * V_65 = V_69 -> V_114 ;
struct V_31 * V_32 = F_27 ( V_65 ) ;
unsigned int V_196 ;
unsigned int V_197 ;
unsigned int V_155 ;
unsigned long V_116 ;
F_11 ( L_10 , V_36 , V_65 -> V_78 ) ;
if ( V_32 == NULL )
return - V_49 ;
F_45 ( & V_32 -> V_54 , V_116 ) ;
V_197 = V_32 -> V_82 ;
V_155 = V_32 -> V_83 ;
F_47 ( & V_32 -> V_54 , V_116 ) ;
V_196 = ( ( V_155 & V_85 ) ? V_198 : 0 )
| ( ( V_155 & V_84 ) ? V_199 : 0 )
| ( ( V_155 & V_200 ) ? V_201 : 0 )
| ( ( V_197 & V_202 ) ? V_146 : 0 )
| ( ( V_197 & V_203 ) ? V_204 : 0 )
| ( ( V_197 & V_205 ) ? V_206 : 0 )
| ( ( V_197 & V_207 ) ? V_144 : 0 ) ;
F_11 ( L_45 , V_36 , V_196 ) ;
return V_196 ;
}
static int F_71 ( struct V_68 * V_69 ,
unsigned int V_208 , unsigned int V_209 )
{
struct V_70 * V_65 = V_69 -> V_114 ;
struct V_31 * V_32 = F_27 ( V_65 ) ;
unsigned int V_155 ;
unsigned long V_116 ;
F_11 ( L_10 , V_36 , V_65 -> V_78 ) ;
if ( V_32 == NULL )
return - V_49 ;
F_45 ( & V_32 -> V_54 , V_116 ) ;
V_155 = V_32 -> V_83 ;
if ( V_208 & V_199 )
V_155 |= V_84 ;
if ( V_208 & V_198 )
V_155 |= V_85 ;
if ( V_208 & V_201 )
V_155 |= V_200 ;
if ( V_209 & V_199 )
V_155 &= ~ V_84 ;
if ( V_209 & V_198 )
V_155 &= ~ V_85 ;
if ( V_209 & V_201 )
V_155 &= ~ V_200 ;
F_47 ( & V_32 -> V_54 , V_116 ) ;
return F_69 ( V_32 , V_155 ) ;
}
static void F_72 ( struct V_68 * V_69 , int V_210 )
{
struct V_70 * V_65 = V_69 -> V_114 ;
struct V_31 * V_32 = F_27 ( V_65 ) ;
int V_35 ;
F_11 ( L_46 , V_36 , V_210 ) ;
if ( V_32 == NULL )
return;
F_40 ( V_32 , ( V_32 -> V_58 * V_109 ) / 100 , 0 ) ;
V_35 = F_73 ( V_32 -> V_66 ,
V_32 -> V_55 + V_211 ,
V_212 , V_210 == - 1 ? V_212 : 0 ) ;
if ( V_35 )
F_11 ( L_47 , V_36 , V_35 ) ;
}
static void V_91 ( struct V_71 * V_71 )
{
struct V_29 * V_30 = V_71 -> V_92 ;
struct V_70 * V_65 ;
struct V_27 * V_28 = V_30 -> V_45 ;
struct V_31 * V_32 ;
struct V_213 * V_34 = & V_71 -> V_34 -> V_34 ;
unsigned char * V_112 = V_71 -> V_214 ;
int V_215 = V_71 -> V_216 ;
int V_72 ;
int V_217 ;
int V_35 = V_71 -> V_35 ;
int V_218 ;
V_74 V_197 ;
F_11 ( L_9 , V_36 ) ;
switch ( V_35 ) {
case 0 :
break;
case - V_219 :
case - V_220 :
case - V_221 :
F_11 ( L_48 , V_36 , V_35 ) ;
V_30 -> V_222 = 1 ;
return;
default:
F_14 ( V_34 , L_49 ,
V_36 , V_35 ) ;
V_30 -> V_222 = 1 ;
goto exit;
}
if ( V_215 != 2 ) {
F_11 ( L_50 , V_36 , V_215 ) ;
goto exit;
}
if ( V_112 [ 0 ] == V_223 ) {
F_14 ( V_34 , L_51 , V_36 , V_112 [ 1 ] ) ;
goto exit;
}
V_72 = F_74 ( V_112 [ 0 ] ) ;
V_217 = F_75 ( V_112 [ 0 ] ) ;
F_11 ( L_52 ,
V_36 , V_72 , V_217 , V_112 [ 1 ] ) ;
if ( V_72 >= V_28 -> V_52 ) {
F_14 ( V_34 , L_53 ,
V_36 , V_72 ) ;
goto exit;
}
V_65 = V_28 -> V_65 [ V_72 ] ;
V_32 = F_27 ( V_65 ) ;
if ( ! V_32 )
goto exit;
switch ( V_217 ) {
case V_224 :
F_14 ( V_34 , L_54 ,
V_36 , V_72 , V_112 [ 1 ] ) ;
break;
case V_225 :
V_197 = V_112 [ 1 ] ;
F_11 ( L_55 , V_36 , V_72 , V_197 ) ;
F_76 ( V_32 , V_197 ) ;
break;
default:
F_14 ( V_34 , L_56 ,
V_36 , V_112 [ 1 ] ) ;
break;
}
exit:
V_218 = F_33 ( V_71 , V_226 ) ;
if ( V_218 )
F_14 ( V_34 , L_57 ,
V_36 , V_218 ) ;
}
static void V_106 ( struct V_71 * V_71 )
{
struct V_31 * V_32 = V_71 -> V_92 ;
struct V_70 * V_65 = V_32 -> V_64 ;
struct V_213 * V_34 = & V_71 -> V_34 -> V_34 ;
int V_35 = V_71 -> V_35 ;
int V_218 = 0 ;
struct V_68 * V_69 ;
F_11 ( L_9 , V_36 ) ;
switch ( V_35 ) {
case 0 :
break;
case - V_219 :
case - V_220 :
case - V_221 :
F_11 ( L_48 , V_36 , V_35 ) ;
V_32 -> V_66 -> V_222 = 1 ;
F_77 ( & V_32 -> V_61 ) ;
return;
default:
F_14 ( V_34 , L_49 ,
V_36 , V_35 ) ;
V_32 -> V_66 -> V_222 = 1 ;
F_77 ( & V_32 -> V_61 ) ;
}
if ( V_35 == - V_227 )
goto exit;
if ( V_35 ) {
F_14 ( V_34 , L_58 , V_36 ) ;
return;
}
V_69 = F_78 ( & V_65 -> V_65 ) ;
if ( V_69 ) {
if ( V_71 -> V_216 ) {
F_79 ( V_228 , V_34 , V_36 ,
V_71 -> V_216 , V_71 -> V_214 ) ;
if ( ! V_32 -> V_107 )
F_11 ( L_59 ,
V_36 ) ;
else
F_80 ( & V_71 -> V_34 -> V_34 , V_69 ,
V_71 -> V_214 ,
V_71 -> V_216 ) ;
F_81 ( & V_32 -> V_54 ) ;
V_32 -> V_81 . V_122 += V_71 -> V_216 ;
F_82 ( & V_32 -> V_54 ) ;
}
F_83 ( V_69 ) ;
}
exit:
F_81 ( & V_32 -> V_54 ) ;
if ( V_32 -> V_104 == V_105 ) {
V_71 -> V_34 = V_65 -> V_28 -> V_34 ;
V_218 = F_33 ( V_71 , V_226 ) ;
} else if ( V_32 -> V_104 == V_229 ) {
V_32 -> V_104 = V_230 ;
}
F_82 ( & V_32 -> V_54 ) ;
if ( V_218 )
F_14 ( V_34 , L_60 ,
V_36 , V_218 ) ;
}
static void F_84 ( struct V_71 * V_71 )
{
struct V_31 * V_32 = V_71 -> V_92 ;
struct V_70 * V_65 = V_32 -> V_64 ;
struct V_213 * V_34 = & V_71 -> V_34 -> V_34 ;
int V_35 = V_71 -> V_35 ;
F_11 ( L_10 , V_36 , V_65 -> V_78 ) ;
V_32 -> V_110 = 0 ;
switch ( V_35 ) {
case 0 :
break;
case - V_219 :
case - V_220 :
case - V_221 :
F_11 ( L_48 , V_36 , V_35 ) ;
V_32 -> V_66 -> V_222 = 1 ;
F_77 ( & V_32 -> V_61 ) ;
return;
default:
F_14 ( V_34 , L_49 ,
V_36 , V_35 ) ;
V_32 -> V_66 -> V_222 = 1 ;
F_77 ( & V_32 -> V_61 ) ;
}
F_43 ( V_32 ) ;
}
static void F_80 ( struct V_213 * V_34 , struct V_68 * V_69 ,
unsigned char * V_112 , int V_215 )
{
int V_231 ;
do {
V_231 = F_85 ( V_69 , V_112 , V_215 ) ;
if ( V_231 < V_215 ) {
F_14 ( V_34 , L_61 ,
V_36 , V_215 - V_231 ) ;
if ( V_231 == 0 )
break;
}
F_86 ( V_69 ) ;
V_112 += V_231 ;
V_215 -= V_231 ;
} while ( V_215 > 0 );
}
static void F_43 ( struct V_31 * V_32 )
{
int V_113 , V_196 ;
struct V_70 * V_65 = V_32 -> V_64 ;
struct V_68 * V_69 = F_78 ( & V_65 -> V_65 ) ;
unsigned long V_116 ;
F_11 ( L_10 , V_36 , V_65 -> V_78 ) ;
F_45 ( & V_32 -> V_54 , V_116 ) ;
if ( V_32 -> V_110 )
goto V_232;
V_113 = F_87 ( & V_32 -> V_62 ,
V_65 -> V_101 -> V_214 ,
V_65 -> V_233 ) ;
if ( V_113 == 0 )
goto V_232;
V_32 -> V_110 = 1 ;
F_47 ( & V_32 -> V_54 , V_116 ) ;
F_79 ( V_228 , & V_65 -> V_34 , V_36 , V_113 ,
V_65 -> V_101 -> V_214 ) ;
F_88 ( V_65 -> V_101 , V_65 -> V_28 -> V_34 ,
F_89 ( V_65 -> V_28 -> V_34 ,
V_65 -> V_234 ) ,
V_65 -> V_101 -> V_214 , V_113 ,
F_84 , V_32 ) ;
V_196 = F_33 ( V_65 -> V_101 , V_226 ) ;
if ( V_196 ) {
F_14 ( & V_65 -> V_34 , L_62 ,
V_36 , V_196 ) ;
V_32 -> V_110 = 0 ;
} else {
F_45 ( & V_32 -> V_54 , V_116 ) ;
V_32 -> V_81 . V_123 += V_113 ;
F_47 ( & V_32 -> V_54 , V_116 ) ;
}
if ( V_69 )
F_90 ( V_69 ) ;
F_83 ( V_69 ) ;
F_77 ( & V_32 -> V_61 ) ;
return;
V_232:
F_47 ( & V_32 -> V_54 , V_116 ) ;
F_83 ( V_69 ) ;
return;
}
static int F_69 ( struct V_31 * V_32 , unsigned int V_155 )
{
unsigned long V_116 ;
int V_35 ;
V_35 = F_73 ( V_32 -> V_66 ,
V_32 -> V_55 + V_235 ,
V_84 | V_85 | V_200 , V_155 ) ;
F_45 ( & V_32 -> V_54 , V_116 ) ;
if ( ! V_35 )
V_32 -> V_83 = V_155 ;
F_47 ( & V_32 -> V_54 , V_116 ) ;
return V_35 ;
}
static int F_91 ( struct V_31 * V_32 )
{
int V_236 , V_35 ;
struct V_29 * V_30 = V_32 -> V_66 ;
struct V_70 * V_65 = V_32 -> V_64 ;
int V_72 = V_65 -> V_78 - V_65 -> V_28 -> V_80 ;
struct V_237 * V_112 ;
F_11 ( L_10 , V_36 , V_65 -> V_78 ) ;
V_236 = sizeof( struct V_237 ) ;
V_112 = F_62 ( V_236 , V_42 ) ;
if ( ! V_112 ) {
F_14 ( & V_65 -> V_34 , L_5 , V_36 ) ;
return - V_43 ;
}
V_35 = F_92 ( V_30 , V_238 ,
( V_74 ) ( V_95 + V_72 ) , 0 , ( V_74 * ) V_112 , V_236 ) ;
if ( V_35 ) {
F_14 ( & V_65 -> V_34 ,
L_63 ,
V_36 , V_35 ) ;
goto V_239;
}
F_11 ( L_64 , V_36 , V_112 -> V_240 ) ;
V_32 -> V_241 = V_112 -> V_240 ;
V_239:
F_25 ( V_112 ) ;
return V_35 ;
}
static int F_58 ( struct V_31 * V_32 ,
struct V_137 V_138 * V_242 )
{
struct V_70 * V_65 = V_32 -> V_64 ;
struct V_137 V_243 ;
if ( ! V_242 )
return - V_244 ;
memset ( & V_243 , 0 , sizeof( V_243 ) ) ;
V_243 . type = V_245 ;
V_243 . line = V_65 -> V_28 -> V_80 ;
V_243 . V_65 = V_65 -> V_78 - V_65 -> V_28 -> V_80 ;
V_243 . V_116 = V_32 -> V_246 ;
V_243 . V_247 = V_63 ;
V_243 . V_248 = V_32 -> V_66 -> V_47 ? 921600 : 460800 ;
V_243 . V_59 = V_32 -> V_58 ;
if ( F_93 ( V_242 , & V_243 , sizeof( * V_242 ) ) )
return - V_244 ;
return 0 ;
}
static int F_59 ( struct V_68 * V_69 , struct V_31 * V_32 ,
struct V_137 V_138 * V_249 )
{
struct V_137 V_250 ;
if ( F_94 ( & V_250 , V_249 , sizeof( V_250 ) ) )
return - V_244 ;
V_32 -> V_246 = V_250 . V_116 & V_251 ;
V_32 -> V_58 = V_250 . V_59 ;
return 0 ;
}
static void F_76 ( struct V_31 * V_32 , V_74 V_197 )
{
struct V_120 * V_119 ;
struct V_68 * V_69 ;
unsigned long V_116 ;
F_11 ( L_65 , V_36 , V_197 ) ;
if ( V_197 & V_252 ) {
F_45 ( & V_32 -> V_54 , V_116 ) ;
V_119 = & V_32 -> V_81 ;
if ( V_197 & V_253 )
V_119 -> V_124 ++ ;
if ( V_197 & V_254 )
V_119 -> V_125 ++ ;
if ( V_197 & V_255 )
V_119 -> V_127 ++ ;
if ( V_197 & V_256 )
V_119 -> V_126 ++ ;
F_77 ( & V_32 -> V_60 ) ;
F_47 ( & V_32 -> V_54 , V_116 ) ;
}
V_32 -> V_82 = V_197 & V_257 ;
V_69 = F_78 ( & V_32 -> V_64 -> V_65 ) ;
if ( V_69 && F_52 ( V_69 ) ) {
if ( V_197 & V_202 ) {
V_69 -> V_189 = 0 ;
F_90 ( V_69 ) ;
} else {
V_69 -> V_189 = 1 ;
}
}
F_83 ( V_69 ) ;
}
static void F_40 ( struct V_31 * V_32 , unsigned long V_258 , int V_259 )
{
struct V_29 * V_30 = V_32 -> V_66 ;
struct V_70 * V_65 = V_32 -> V_64 ;
T_5 V_260 ;
F_11 ( L_10 , V_36 , V_65 -> V_78 ) ;
F_95 ( & V_32 -> V_54 ) ;
V_30 -> V_222 = 0 ;
F_96 ( & V_260 , V_141 ) ;
F_97 ( & V_32 -> V_61 , & V_260 ) ;
for (; ; ) {
F_98 ( V_261 ) ;
if ( F_49 ( & V_32 -> V_62 ) == 0
|| V_258 == 0 || F_61 ( V_141 )
|| V_30 -> V_222
|| V_65 -> V_28 -> V_262 )
break;
F_99 ( & V_32 -> V_54 ) ;
V_258 = F_100 ( V_258 ) ;
F_95 ( & V_32 -> V_54 ) ;
}
F_98 ( V_263 ) ;
F_101 ( & V_32 -> V_61 , & V_260 ) ;
if ( V_259 )
F_102 ( & V_32 -> V_62 ) ;
F_99 ( & V_32 -> V_54 ) ;
F_103 ( & V_65 -> V_28 -> V_264 ) ;
V_258 += V_265 ;
V_32 -> V_241 &= ~ V_266 ;
while ( ( long ) ( V_265 - V_258 ) < 0 && ! F_61 ( V_141 )
&& ! ( V_32 -> V_241 & V_266 ) && ! V_30 -> V_222
&& ! V_65 -> V_28 -> V_262 ) {
if ( F_91 ( V_32 ) )
break;
F_38 ( & V_65 -> V_28 -> V_264 ) ;
F_19 ( 20 ) ;
F_103 ( & V_65 -> V_28 -> V_264 ) ;
}
F_38 ( & V_65 -> V_28 -> V_264 ) ;
}
static void F_53 ( struct V_31 * V_32 , struct V_68 * V_69 )
{
unsigned long V_116 ;
F_45 ( & V_32 -> V_54 , V_116 ) ;
if ( V_32 -> V_104 == V_105 )
V_32 -> V_104 = V_229 ;
F_47 ( & V_32 -> V_54 , V_116 ) ;
}
static int F_55 ( struct V_31 * V_32 , struct V_68 * V_69 )
{
struct V_71 * V_71 ;
int V_35 = 0 ;
unsigned long V_116 ;
F_45 ( & V_32 -> V_54 , V_116 ) ;
if ( V_32 -> V_104 == V_230 ) {
V_32 -> V_104 = V_105 ;
V_71 = V_32 -> V_64 -> V_103 ;
F_47 ( & V_32 -> V_54 , V_116 ) ;
V_71 -> V_90 = V_106 ;
V_71 -> V_92 = V_32 ;
V_71 -> V_34 = V_32 -> V_64 -> V_28 -> V_34 ;
V_35 = F_33 ( V_71 , V_42 ) ;
} else {
V_32 -> V_104 = V_105 ;
F_47 ( & V_32 -> V_54 , V_116 ) ;
}
return V_35 ;
}
static int F_35 ( struct V_29 * V_30 , V_74 V_267 ,
T_3 V_268 , T_3 V_269 , V_74 * V_112 , int V_236 )
{
int V_35 ;
V_35 = F_104 ( V_30 -> V_45 -> V_34 ,
F_105 ( V_30 -> V_45 -> V_34 , 0 ) , V_267 ,
( V_270 | V_271 | V_272 ) ,
V_269 , V_268 , V_112 , V_236 , 1000 ) ;
if ( V_35 == V_236 )
V_35 = 0 ;
if ( V_35 > 0 )
V_35 = - V_273 ;
return V_35 ;
}
static int F_92 ( struct V_29 * V_30 , V_74 V_267 ,
T_3 V_268 , T_3 V_269 , V_74 * V_112 , int V_236 )
{
int V_35 ;
V_35 = F_104 ( V_30 -> V_45 -> V_34 ,
F_106 ( V_30 -> V_45 -> V_34 , 0 ) , V_267 ,
( V_270 | V_271 | V_274 ) ,
V_269 , V_268 , V_112 , V_236 , 1000 ) ;
if ( V_35 == V_236 )
V_35 = 0 ;
if ( V_35 > 0 )
V_35 = - V_273 ;
return V_35 ;
}
static int F_73 ( struct V_29 * V_30 , unsigned long V_275 ,
V_74 V_276 , V_74 V_277 )
{
int V_35 ;
unsigned int V_236 ;
struct V_278 * V_112 ;
struct V_213 * V_34 = & V_30 -> V_45 -> V_34 -> V_34 ;
F_11 ( L_66 ,
V_36 , V_275 , V_276 , V_277 ) ;
V_236 = sizeof( struct V_278 ) + 2 ;
V_112 = F_62 ( V_236 , V_42 ) ;
if ( ! V_112 ) {
F_14 ( V_34 , L_5 , V_36 ) ;
return - V_43 ;
}
V_112 -> V_279 = V_280 ;
V_112 -> V_281 = V_282 ;
V_112 -> V_283 = 1 ;
V_112 -> V_284 = F_107 ( V_275 >> 16 ) ;
V_112 -> V_285 = F_107 ( V_275 ) ;
V_112 -> V_286 [ 0 ] = V_276 ;
V_112 -> V_286 [ 1 ] = V_277 ;
V_35 = F_35 ( V_30 , V_287 , V_288 , 0 ,
( V_74 * ) V_112 , V_236 ) ;
if ( V_35 < 0 )
F_14 ( V_34 , L_67 , V_36 , V_35 ) ;
F_25 ( V_112 ) ;
return V_35 ;
}
static int F_108 ( struct V_33 * V_34 , int V_102 ,
T_6 * V_289 , int V_236 )
{
int V_290 ;
T_6 V_291 = 0 ;
int V_292 ;
struct V_293 * V_294 ;
int V_35 = 0 ;
int V_295 ;
for ( V_290 = sizeof( struct V_293 ) ; V_290 < V_236 ; V_290 ++ )
V_291 = ( V_74 ) ( V_291 + V_289 [ V_290 ] ) ;
V_294 = (struct V_293 * ) V_289 ;
V_294 -> V_296 = F_109 ( ( T_3 ) ( V_236
- sizeof( struct V_293 ) ) ) ;
V_294 -> V_297 = V_291 ;
F_11 ( L_68 , V_36 ) ;
for ( V_290 = 0 ; V_290 < V_236 ; V_290 += V_292 ) {
V_295 = F_3 ( V_236 - V_290 , V_298 ) ;
V_35 = F_110 ( V_34 , V_102 , V_289 + V_290 , V_295 ,
& V_292 , 1000 ) ;
if ( V_35 )
break;
}
return V_35 ;
}
static int F_18 ( struct V_29 * V_30 )
{
int V_35 ;
int V_299 ;
V_74 * V_289 ;
struct V_33 * V_34 = V_30 -> V_45 -> V_34 ;
unsigned int V_102 = F_89 ( V_34 ,
V_30 -> V_45 -> V_65 [ 0 ] -> V_234 ) ;
const struct V_300 * V_301 ;
char V_302 [ 32 ] ;
F_11 ( L_69 , V_36 ) ;
sprintf ( V_302 , L_70 , V_34 -> V_37 . V_10 ,
V_34 -> V_37 . V_12 ) ;
if ( ( V_35 = F_111 ( & V_301 , V_302 , & V_34 -> V_34 ) ) != 0 ) {
V_302 [ 0 ] = '\0' ;
if ( V_34 -> V_37 . V_10 == V_303 ) {
switch ( V_34 -> V_37 . V_12 ) {
case V_304 :
strcpy ( V_302 , L_71 ) ;
break;
case V_305 :
strcpy ( V_302 , L_72 ) ;
break;
case V_306 :
strcpy ( V_302 , L_73 ) ;
break;
case V_307 :
strcpy ( V_302 , L_74 ) ;
break;
case V_308 :
strcpy ( V_302 , L_75 ) ;
break;
case V_309 :
strcpy ( V_302 , L_75 ) ;
break; }
}
if ( V_302 [ 0 ] == '\0' ) {
if ( V_30 -> V_47 )
strcpy ( V_302 , L_76 ) ;
else
strcpy ( V_302 , L_77 ) ;
}
V_35 = F_111 ( & V_301 , V_302 , & V_34 -> V_34 ) ;
}
if ( V_35 ) {
F_14 ( & V_34 -> V_34 , L_78 , V_36 ) ;
return - V_220 ;
}
if ( V_301 -> V_236 > V_310 ) {
F_14 ( & V_34 -> V_34 , L_79 , V_36 , V_301 -> V_236 ) ;
F_112 ( V_301 ) ;
return - V_220 ;
}
V_299 = V_310 + sizeof( struct V_293 ) ;
V_289 = F_62 ( V_299 , V_42 ) ;
if ( V_289 ) {
memcpy ( V_289 , V_301 -> V_112 , V_301 -> V_236 ) ;
memset ( V_289 + V_301 -> V_236 , 0xff , V_299 - V_301 -> V_236 ) ;
V_35 = F_108 ( V_34 , V_102 , V_289 , V_301 -> V_236 ) ;
F_25 ( V_289 ) ;
} else {
F_11 ( L_80 , V_36 ) ;
V_35 = - V_43 ;
}
F_112 ( V_301 ) ;
if ( V_35 ) {
F_14 ( & V_34 -> V_34 , L_81 ,
V_36 , V_35 ) ;
return V_35 ;
}
F_11 ( L_82 , V_36 ) ;
return 0 ;
}
