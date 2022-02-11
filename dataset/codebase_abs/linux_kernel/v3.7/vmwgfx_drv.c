static void F_1 ( T_1 V_1 )
{
F_2 ( L_1 ) ;
if ( V_1 & V_2 )
F_2 ( L_2 ) ;
if ( V_1 & V_3 )
F_2 ( L_3 ) ;
if ( V_1 & V_4 )
F_2 ( L_4 ) ;
if ( V_1 & V_5 )
F_2 ( L_5 ) ;
if ( V_1 & V_6 )
F_2 ( L_6 ) ;
if ( V_1 & V_7 )
F_2 ( L_7 ) ;
if ( V_1 & V_8 )
F_2 ( L_8 ) ;
if ( V_1 & V_9 )
F_2 ( L_9 ) ;
if ( V_1 & V_10 )
F_2 ( L_10 ) ;
if ( V_1 & V_11 )
F_2 ( L_11 ) ;
if ( V_1 & V_12 )
F_2 ( L_12 ) ;
if ( V_1 & V_13 )
F_2 ( L_13 ) ;
if ( V_1 & V_14 )
F_2 ( L_14 ) ;
if ( V_1 & V_15 )
F_2 ( L_15 ) ;
if ( V_1 & V_16 )
F_2 ( L_16 ) ;
if ( V_1 & V_17 )
F_2 ( L_17 ) ;
}
static void F_3 ( struct V_18 * V_19 )
{
struct V_20 V_21 ;
volatile T_2 * V_22 ;
bool V_23 ;
int V_24 ;
struct V_25 * V_26 = & V_19 -> V_26 ;
struct V_27 * V_28 = V_19 -> V_29 ;
F_4 ( V_28 , false , false , false , 0 ) ;
F_5 ( & V_26 -> V_30 ) ;
V_24 = F_6 ( V_28 , false , false , false ) ;
F_7 ( & V_26 -> V_30 ) ;
if ( F_8 ( V_24 != 0 ) )
( void ) F_9 ( V_19 , false , true , 0 , false ,
10 * V_31 ) ;
V_24 = F_10 ( V_28 , 0 , 1 , & V_21 ) ;
if ( F_11 ( V_24 == 0 ) ) {
V_22 = F_12 ( & V_21 , & V_23 ) ;
V_22 -> V_32 = sizeof( * V_22 ) ;
V_22 -> V_33 = V_34 ;
V_22 -> V_35 = 0xff ;
F_13 ( & V_21 ) ;
} else
F_14 ( L_18 ) ;
F_15 ( V_28 ) ;
}
static int F_16 ( struct V_18 * V_19 )
{
return F_17 ( & V_19 -> V_26 ,
V_36 ,
V_37 ,
& V_38 ,
0 , 0 , false , NULL ,
& V_19 -> V_29 ) ;
}
static int F_18 ( struct V_18 * V_19 )
{
int V_24 ;
V_24 = F_19 ( V_19 , & V_19 -> V_39 ) ;
if ( F_8 ( V_24 != 0 ) ) {
F_14 ( L_19 ) ;
return V_24 ;
}
F_20 ( V_19 -> V_40 ) ;
V_24 = F_16 ( V_19 ) ;
if ( F_8 ( V_24 != 0 ) )
goto V_41;
F_3 ( V_19 ) ;
return 0 ;
V_41:
F_21 ( V_19 -> V_40 ) ;
F_22 ( V_19 , & V_19 -> V_39 ) ;
return V_24 ;
}
static void F_23 ( struct V_18 * V_19 )
{
F_24 ( V_19 -> V_42 != NULL ) ;
F_25 ( & V_19 -> V_29 ) ;
F_21 ( V_19 -> V_40 ) ;
F_22 ( V_19 , & V_19 -> V_39 ) ;
}
int F_26 ( struct V_18 * V_19 ,
bool V_43 )
{
int V_24 = 0 ;
F_27 ( & V_19 -> V_44 ) ;
if ( F_8 ( V_19 -> V_45 ++ == 0 ) ) {
V_24 = F_18 ( V_19 ) ;
if ( F_8 ( V_24 != 0 ) )
-- V_19 -> V_45 ;
} else if ( V_43 ) {
F_27 ( & V_19 -> V_46 ) ;
F_28 ( V_19 , V_47 ,
F_29 ( V_19 , V_47 ) &
~ V_48 ) ;
F_30 ( & V_19 -> V_46 ) ;
}
F_30 ( & V_19 -> V_44 ) ;
return V_24 ;
}
void F_31 ( struct V_18 * V_19 ,
bool V_49 )
{
T_3 V_50 ;
F_27 ( & V_19 -> V_44 ) ;
if ( F_8 ( -- V_19 -> V_45 == 0 ) )
F_23 ( V_19 ) ;
else if ( V_49 ) {
F_27 ( & V_19 -> V_46 ) ;
F_28 ( V_19 , V_47 ,
F_29 ( V_19 , V_47 ) |
V_48 ) ;
F_30 ( & V_19 -> V_46 ) ;
}
V_50 = ( T_3 ) V_19 -> V_45 ;
F_30 ( & V_19 -> V_44 ) ;
F_24 ( V_50 < 0 ) ;
}
static void F_32 ( struct V_18 * V_19 )
{
T_1 V_51 ;
T_1 V_52 ;
V_51 = F_29 ( V_19 , V_53 ) ;
V_52 = F_29 ( V_19 , V_54 ) ;
V_51 = F_33 ( T_1 , V_51 , V_55 ) ;
V_52 = F_33 ( T_1 , V_52 , V_56 ) ;
if ( V_51 > V_19 -> V_57 ||
V_52 > V_19 -> V_58 ) {
V_51 = V_55 ;
V_52 = V_56 ;
}
V_19 -> V_59 = V_51 ;
V_19 -> V_60 = V_52 ;
}
static int F_34 ( struct V_61 * V_62 , unsigned long V_63 )
{
struct V_18 * V_19 ;
int V_24 ;
T_1 V_64 ;
V_19 = F_35 ( sizeof( * V_19 ) , V_65 ) ;
if ( F_8 ( V_19 == NULL ) ) {
F_14 ( L_20 ) ;
return - V_66 ;
}
F_36 ( V_62 -> V_67 ) ;
V_19 -> V_62 = V_62 ;
V_19 -> V_68 = V_63 ;
V_19 -> V_69 = ( T_1 ) - 100 ;
F_37 ( & V_19 -> V_46 ) ;
F_37 ( & V_19 -> V_70 ) ;
F_37 ( & V_19 -> V_44 ) ;
F_38 ( & V_19 -> V_71 ) ;
F_39 ( & V_19 -> V_72 ) ;
F_39 ( & V_19 -> V_73 ) ;
F_39 ( & V_19 -> V_74 ) ;
F_37 ( & V_19 -> V_75 ) ;
F_40 ( & V_19 -> V_76 ) ;
F_40 ( & V_19 -> V_77 ) ;
V_19 -> V_78 = 0 ;
F_41 ( & V_19 -> V_79 , 0 ) ;
F_42 ( & V_19 -> V_80 ) ;
V_19 -> V_81 = 0 ;
V_19 -> V_82 = F_43 ( V_62 -> V_67 , 0 ) ;
V_19 -> V_83 = F_43 ( V_62 -> V_67 , 1 ) ;
V_19 -> V_84 = F_43 ( V_62 -> V_67 , 2 ) ;
V_19 -> V_85 = V_86 ;
F_27 ( & V_19 -> V_46 ) ;
F_28 ( V_19 , V_87 , V_88 ) ;
V_64 = F_29 ( V_19 , V_87 ) ;
if ( V_64 != V_88 ) {
V_24 = - V_89 ;
F_14 ( L_21 , V_64 ) ;
F_30 ( & V_19 -> V_46 ) ;
goto V_90;
}
V_19 -> V_1 = F_29 ( V_19 , V_91 ) ;
V_19 -> V_92 = F_29 ( V_19 , V_93 ) ;
V_19 -> V_94 = F_29 ( V_19 , V_95 ) ;
V_19 -> V_57 = F_29 ( V_19 , V_96 ) ;
V_19 -> V_58 = F_29 ( V_19 , V_97 ) ;
F_32 ( V_19 ) ;
if ( V_19 -> V_1 & V_14 ) {
V_19 -> V_98 =
F_29 ( V_19 ,
V_99 ) ;
V_19 -> V_100 =
F_29 ( V_19 , V_101 ) ;
}
if ( V_19 -> V_1 & V_16 ) {
V_19 -> V_102 =
F_29 ( V_19 , V_103 ) ;
V_19 -> V_104 =
F_29 ( V_19 , V_105 ) ;
V_19 -> V_104 -= V_19 -> V_92 ;
} else {
V_19 -> V_104 = 512 * 1024 * 1024 ;
}
F_30 ( & V_19 -> V_46 ) ;
F_1 ( V_19 -> V_1 ) ;
if ( V_19 -> V_1 & V_14 ) {
F_2 ( L_22 ,
( unsigned ) V_19 -> V_100 ) ;
F_2 ( L_23 ,
( unsigned ) V_19 -> V_98 ) ;
}
if ( V_19 -> V_1 & V_16 ) {
F_2 ( L_24 ,
( unsigned ) V_19 -> V_102 ) ;
F_2 ( L_25 ,
( unsigned ) V_19 -> V_104 / 1024 ) ;
}
F_2 ( L_26 ,
V_19 -> V_83 , V_19 -> V_92 / 1024 ) ;
F_2 ( L_27 ,
V_19 -> V_84 , V_19 -> V_94 / 1024 ) ;
V_24 = F_44 ( V_19 ) ;
if ( F_8 ( V_24 != 0 ) )
goto V_90;
F_45 ( & V_19 -> V_106 ) ;
F_46 ( & V_19 -> V_106 . V_107 , false , V_108 ) ;
V_19 -> V_109 = & V_19 -> V_106 ;
V_24 = F_47 ( & V_19 -> V_26 ,
V_19 -> V_110 . V_111 . V_112 ,
& V_113 , V_114 ,
false ) ;
if ( F_8 ( V_24 != 0 ) ) {
F_14 ( L_28 ) ;
goto V_115;
}
V_24 = F_48 ( & V_19 -> V_26 , V_116 ,
( V_19 -> V_92 >> V_117 ) ) ;
if ( F_8 ( V_24 != 0 ) ) {
F_14 ( L_29 ) ;
goto V_118;
}
V_19 -> V_119 = true ;
if ( F_48 ( & V_19 -> V_26 , V_120 ,
V_19 -> V_100 ) != 0 ) {
F_2 ( L_30
L_31 ) ;
V_19 -> V_119 = false ;
}
V_19 -> V_121 = F_49 ( V_19 -> V_84 ,
V_19 -> V_94 , V_122 ) ;
V_19 -> V_123 = F_50 ( V_19 -> V_84 ,
V_19 -> V_94 ) ;
if ( F_8 ( V_19 -> V_123 == NULL ) ) {
V_24 = - V_66 ;
F_14 ( L_32 ) ;
goto V_124;
}
if ( ! ( V_19 -> V_1 & V_13 ) &&
! ( V_19 -> V_1 & V_11 ) &&
! F_51 ( V_19 ) ) {
V_24 = - V_89 ;
F_14 ( L_33 ) ;
goto V_125;
}
V_19 -> V_126 = F_52
( V_19 -> V_127 . V_112 , 12 ) ;
if ( F_8 ( V_19 -> V_126 == NULL ) ) {
F_14 ( L_34 ) ;
V_24 = - V_66 ;
goto V_125;
}
V_62 -> V_128 = V_19 ;
V_24 = F_53 ( V_62 -> V_67 , L_35 ) ;
V_19 -> V_129 = ( V_24 != 0 ) ;
if ( V_19 -> V_129 ) {
F_2 ( L_36
L_37 ) ;
V_24 = F_54 ( V_62 -> V_67 , 2 , L_38 ) ;
if ( F_8 ( V_24 != 0 ) ) {
F_14 ( L_39 ) ;
goto V_130;
}
}
V_19 -> V_40 = F_55 ( V_19 ) ;
if ( F_8 ( V_19 -> V_40 == NULL ) )
goto V_131;
V_24 = F_26 ( V_19 , true ) ;
if ( F_8 ( V_24 != 0 ) )
goto V_132;
F_56 ( V_19 ) ;
V_24 = F_57 ( V_19 ) ;
if ( F_8 ( V_24 != 0 ) )
goto V_133;
F_58 ( V_19 ) ;
F_2 ( L_40 ,
F_59 ( V_19 ) ?
L_41 : L_42 ) ;
if ( V_19 -> V_85 ) {
F_60 ( V_19 ) ;
} else {
F_61 ( V_19 ) ;
F_31 ( V_19 , true ) ;
}
if ( V_19 -> V_1 & V_12 ) {
V_24 = F_62 ( V_62 ) ;
if ( F_8 ( V_24 != 0 ) ) {
F_14 ( L_43 , V_24 ) ;
goto V_134;
}
}
V_19 -> V_135 . V_136 = V_137 ;
F_63 ( & V_19 -> V_135 ) ;
return 0 ;
V_134:
if ( V_19 -> V_85 )
F_64 ( V_19 ) ;
F_65 ( V_19 ) ;
F_66 ( V_19 ) ;
V_133:
if ( V_19 -> V_85 ) {
F_61 ( V_19 ) ;
F_31 ( V_19 , false ) ;
}
V_132:
F_67 ( V_19 -> V_40 ) ;
V_131:
if ( V_19 -> V_129 )
F_68 ( V_62 -> V_67 , 2 ) ;
else
F_69 ( V_62 -> V_67 ) ;
V_130:
F_70 ( & V_19 -> V_126 ) ;
V_125:
F_71 ( V_19 -> V_123 ) ;
V_124:
F_72 ( V_19 -> V_121 , V_19 -> V_84 ,
V_19 -> V_94 , V_122 ) ;
if ( V_19 -> V_119 )
( void ) F_73 ( & V_19 -> V_26 , V_120 ) ;
( void ) F_73 ( & V_19 -> V_26 , V_116 ) ;
V_118:
( void ) F_74 ( & V_19 -> V_26 ) ;
V_115:
F_75 ( V_19 ) ;
V_90:
F_76 ( & V_19 -> V_73 ) ;
F_76 ( & V_19 -> V_72 ) ;
F_76 ( & V_19 -> V_74 ) ;
F_77 ( V_19 ) ;
return V_24 ;
}
static int F_78 ( struct V_61 * V_62 )
{
struct V_18 * V_19 = F_79 ( V_62 ) ;
F_80 ( & V_19 -> V_135 ) ;
if ( V_19 -> V_138 . V_139 )
F_81 ( V_19 -> V_138 . V_139 ) ;
if ( V_19 -> V_1 & V_12 )
F_82 ( V_19 -> V_62 ) ;
if ( V_19 -> V_85 ) {
F_64 ( V_19 ) ;
F_61 ( V_19 ) ;
F_31 ( V_19 , false ) ;
}
F_66 ( V_19 ) ;
F_65 ( V_19 ) ;
F_67 ( V_19 -> V_40 ) ;
if ( V_19 -> V_129 )
F_68 ( V_62 -> V_67 , 2 ) ;
else
F_69 ( V_62 -> V_67 ) ;
F_70 ( & V_19 -> V_126 ) ;
F_71 ( V_19 -> V_123 ) ;
F_72 ( V_19 -> V_121 , V_19 -> V_84 ,
V_19 -> V_94 , V_122 ) ;
if ( V_19 -> V_119 )
( void ) F_73 ( & V_19 -> V_26 , V_120 ) ;
( void ) F_73 ( & V_19 -> V_26 , V_116 ) ;
( void ) F_74 ( & V_19 -> V_26 ) ;
F_75 ( V_19 ) ;
F_76 ( & V_19 -> V_73 ) ;
F_76 ( & V_19 -> V_72 ) ;
F_76 ( & V_19 -> V_74 ) ;
F_77 ( V_19 ) ;
return 0 ;
}
static void F_83 ( struct V_61 * V_62 ,
struct V_140 * V_141 )
{
struct V_142 * V_143 = V_142 ( V_141 ) ;
struct V_18 * V_19 = F_79 ( V_62 ) ;
F_84 ( V_19 -> V_40 , & V_143 -> V_144 ) ;
}
static void F_85 ( struct V_61 * V_62 ,
struct V_140 * V_141 )
{
struct V_142 * V_143 ;
V_143 = V_142 ( V_141 ) ;
F_86 ( & V_143 -> V_145 ) ;
if ( V_143 -> V_146 )
F_87 ( & V_143 -> V_146 ) ;
F_77 ( V_143 ) ;
}
static int F_88 ( struct V_61 * V_62 , struct V_140 * V_141 )
{
struct V_18 * V_19 = F_79 ( V_62 ) ;
struct V_142 * V_143 ;
int V_24 = - V_66 ;
V_143 = F_35 ( sizeof( * V_143 ) , V_65 ) ;
if ( F_8 ( V_143 == NULL ) )
return V_24 ;
F_42 ( & V_143 -> V_144 ) ;
V_143 -> V_145 = F_89 ( V_19 -> V_126 , 10 ) ;
if ( F_8 ( V_143 -> V_145 == NULL ) )
goto V_147;
V_141 -> V_148 = V_143 ;
V_19 -> V_26 . V_149 = V_62 -> V_149 ;
return 0 ;
V_147:
F_77 ( V_143 ) ;
return V_24 ;
}
static long F_90 ( struct V_150 * V_151 , unsigned int V_152 ,
unsigned long V_153 )
{
struct V_140 * V_141 = V_151 -> V_154 ;
struct V_61 * V_62 = V_141 -> V_155 -> V_62 ;
unsigned int V_156 = F_91 ( V_152 ) ;
if ( ( V_156 >= V_157 ) && ( V_156 < V_158 )
&& ( V_156 < V_157 + V_62 -> V_159 -> V_160 ) ) {
struct V_161 * V_162 =
& V_163 [ V_156 - V_157 ] ;
if ( F_8 ( V_162 -> V_164 != V_152 ) ) {
F_14 ( L_44 ,
V_156 - V_157 ) ;
return - V_165 ;
}
}
return F_92 ( V_151 , V_152 , V_153 ) ;
}
static int F_93 ( struct V_61 * V_62 )
{
struct V_18 * V_19 = F_79 ( V_62 ) ;
V_19 -> V_166 = true ;
return 0 ;
}
static void F_94 ( struct V_61 * V_62 )
{
struct V_18 * V_19 = F_79 ( V_62 ) ;
struct V_167 * V_168 ;
struct V_169 V_170 ;
int V_24 ;
if ( ! V_19 -> V_166 )
return;
V_19 -> V_166 = false ;
V_170 . V_171 = 0 ;
V_170 . V_172 = 0 ;
V_170 . V_173 = NULL ;
V_170 . V_174 = NULL ;
V_170 . V_175 = NULL ;
V_170 . V_176 = 0 ;
F_95 (crtc, &dev->mode_config.crtc_list, head) {
V_170 . V_168 = V_168 ;
V_24 = V_168 -> V_177 -> V_178 ( & V_170 ) ;
F_96 ( V_24 != 0 ) ;
}
}
static void F_45 ( struct V_179 * V_180 )
{
F_97 ( & V_180 -> V_107 ) ;
F_42 ( & V_180 -> V_181 ) ;
F_37 ( & V_180 -> V_182 ) ;
}
static int F_98 ( struct V_61 * V_62 ,
struct V_183 * V_184 )
{
struct V_179 * V_180 ;
V_180 = F_35 ( sizeof( * V_180 ) , V_65 ) ;
if ( F_8 ( V_180 == NULL ) )
return - V_66 ;
F_45 ( V_180 ) ;
F_46 ( & V_180 -> V_107 , true , V_108 ) ;
V_184 -> V_148 = V_180 ;
return 0 ;
}
static void F_99 ( struct V_61 * V_62 ,
struct V_183 * V_184 )
{
struct V_179 * V_180 = V_179 ( V_184 ) ;
V_184 -> V_148 = NULL ;
F_77 ( V_180 ) ;
}
static int F_100 ( struct V_61 * V_62 ,
struct V_140 * V_141 ,
bool V_185 )
{
struct V_18 * V_19 = F_79 ( V_62 ) ;
struct V_142 * V_143 = V_142 ( V_141 ) ;
struct V_179 * V_186 = V_19 -> V_109 ;
struct V_179 * V_180 = V_179 ( V_141 -> V_184 ) ;
int V_24 = 0 ;
if ( ! V_19 -> V_85 ) {
V_24 = F_26 ( V_19 , true ) ;
if ( F_8 ( V_24 != 0 ) )
return V_24 ;
F_56 ( V_19 ) ;
F_27 ( & V_19 -> V_46 ) ;
F_28 ( V_19 , V_187 , 0 ) ;
F_30 ( & V_19 -> V_46 ) ;
}
if ( V_186 ) {
F_24 ( V_186 != & V_19 -> V_106 ) ;
V_24 = F_101 ( & V_186 -> V_107 , false , V_143 -> V_145 ) ;
if ( F_8 ( V_24 != 0 ) )
goto V_188;
F_46 ( & V_186 -> V_107 , true , V_108 ) ;
V_24 = F_102 ( & V_19 -> V_26 , V_116 ) ;
if ( F_8 ( V_24 != 0 ) ) {
F_14 ( L_45
L_46 ) ;
}
V_19 -> V_109 = NULL ;
}
F_46 ( & V_180 -> V_107 , false , V_108 ) ;
if ( ! V_185 ) {
F_103 ( & V_180 -> V_107 ) ;
F_24 ( V_143 -> V_146 != V_141 -> V_184 ) ;
F_87 ( & V_143 -> V_146 ) ;
}
V_19 -> V_109 = V_180 ;
return 0 ;
V_188:
if ( ! V_19 -> V_85 ) {
F_27 ( & V_19 -> V_46 ) ;
F_28 ( V_19 , V_187 , 1 ) ;
F_30 ( & V_19 -> V_46 ) ;
F_61 ( V_19 ) ;
F_31 ( V_19 , true ) ;
}
return V_24 ;
}
static void F_104 ( struct V_61 * V_62 ,
struct V_140 * V_141 ,
bool V_189 )
{
struct V_18 * V_19 = F_79 ( V_62 ) ;
struct V_142 * V_143 = V_142 ( V_141 ) ;
struct V_179 * V_180 = V_179 ( V_141 -> V_184 ) ;
int V_24 ;
V_143 -> V_146 = F_105 ( V_141 -> V_184 ) ;
V_24 = F_101 ( & V_180 -> V_107 , false , V_143 -> V_145 ) ;
F_106 ( V_19 , false , 0 ) ;
if ( F_8 ( ( V_24 != 0 ) ) ) {
F_14 ( L_47 ) ;
F_87 ( & V_143 -> V_146 ) ;
}
F_46 ( & V_180 -> V_107 , true , V_108 ) ;
if ( ! V_19 -> V_85 ) {
V_24 = F_102 ( & V_19 -> V_26 , V_116 ) ;
if ( F_8 ( V_24 != 0 ) )
F_14 ( L_48 ) ;
F_27 ( & V_19 -> V_46 ) ;
F_28 ( V_19 , V_187 , 1 ) ;
F_30 ( & V_19 -> V_46 ) ;
F_61 ( V_19 ) ;
F_31 ( V_19 , true ) ;
}
V_19 -> V_109 = & V_19 -> V_106 ;
F_46 ( & V_19 -> V_106 . V_107 , false , V_108 ) ;
F_103 ( & V_19 -> V_106 . V_107 ) ;
if ( V_19 -> V_85 )
F_107 ( V_19 ) ;
}
static void F_108 ( struct V_190 * V_67 )
{
struct V_61 * V_62 = F_109 ( V_67 ) ;
F_110 ( V_62 ) ;
}
static int V_137 ( struct V_191 * V_192 , unsigned long V_193 ,
void * V_194 )
{
struct V_18 * V_19 =
F_111 ( V_192 , struct V_18 , V_135 ) ;
struct V_179 * V_180 = V_19 -> V_109 ;
switch ( V_193 ) {
case V_195 :
case V_196 :
F_112 ( & V_180 -> V_107 ) ;
F_106 ( V_19 , false , 0 ) ;
F_113 ( & V_19 -> V_26 ) ;
break;
case V_197 :
case V_198 :
case V_199 :
F_114 ( & V_180 -> V_107 ) ;
break;
case V_200 :
break;
default:
break;
}
return 0 ;
}
static int F_115 ( struct V_190 * V_67 , T_4 V_33 )
{
struct V_61 * V_62 = F_109 ( V_67 ) ;
struct V_18 * V_19 = F_79 ( V_62 ) ;
if ( V_19 -> V_45 != 0 ) {
F_2 ( L_49
L_50 ) ;
return - V_201 ;
}
F_116 ( V_67 ) ;
F_117 ( V_67 ) ;
F_118 ( V_67 , V_202 ) ;
return 0 ;
}
static int F_119 ( struct V_190 * V_67 )
{
F_118 ( V_67 , V_203 ) ;
F_120 ( V_67 ) ;
return F_121 ( V_67 ) ;
}
static int F_122 ( struct V_204 * V_205 )
{
struct V_190 * V_67 = F_123 ( V_205 ) ;
struct V_206 V_23 ;
V_23 . V_207 = 0 ;
return F_115 ( V_67 , V_23 ) ;
}
static int F_124 ( struct V_204 * V_205 )
{
struct V_190 * V_67 = F_123 ( V_205 ) ;
return F_119 ( V_67 ) ;
}
static int F_125 ( struct V_204 * V_205 )
{
struct V_190 * V_67 = F_123 ( V_205 ) ;
struct V_61 * V_62 = F_109 ( V_67 ) ;
struct V_18 * V_19 = F_79 ( V_62 ) ;
V_19 -> V_208 = true ;
if ( V_19 -> V_85 )
F_31 ( V_19 , true ) ;
if ( V_19 -> V_45 != 0 ) {
F_2 ( L_49
L_50 ) ;
if ( V_19 -> V_85 )
F_26 ( V_19 , true ) ;
V_19 -> V_208 = false ;
return - V_201 ;
}
return 0 ;
}
static void F_126 ( struct V_204 * V_205 )
{
struct V_190 * V_67 = F_123 ( V_205 ) ;
struct V_61 * V_62 = F_109 ( V_67 ) ;
struct V_18 * V_19 = F_79 ( V_62 ) ;
F_27 ( & V_19 -> V_46 ) ;
F_28 ( V_19 , V_87 , V_88 ) ;
( void ) F_29 ( V_19 , V_87 ) ;
F_30 ( & V_19 -> V_46 ) ;
if ( V_19 -> V_85 )
F_26 ( V_19 , false ) ;
V_19 -> V_208 = false ;
}
static int F_127 ( struct V_190 * V_67 , const struct V_209 * V_210 )
{
return F_128 ( V_67 , V_210 , & V_159 ) ;
}
static int T_5 F_129 ( void )
{
int V_24 ;
V_24 = F_130 ( & V_159 , & V_211 ) ;
if ( V_24 )
F_14 ( L_51 ) ;
return V_24 ;
}
static void T_6 F_131 ( void )
{
F_132 ( & V_159 , & V_211 ) ;
}
