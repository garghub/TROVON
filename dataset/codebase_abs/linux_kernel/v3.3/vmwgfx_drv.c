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
static int F_32 ( struct V_51 * V_52 , unsigned long V_53 )
{
struct V_18 * V_19 ;
int V_24 ;
T_1 V_54 ;
V_19 = F_33 ( sizeof( * V_19 ) , V_55 ) ;
if ( F_8 ( V_19 == NULL ) ) {
F_14 ( L_20 ) ;
return - V_56 ;
}
memset ( V_19 , 0 , sizeof( * V_19 ) ) ;
V_19 -> V_52 = V_52 ;
V_19 -> V_57 = V_53 ;
V_19 -> V_58 = ( T_1 ) - 100 ;
F_34 ( & V_19 -> V_46 ) ;
F_34 ( & V_19 -> V_59 ) ;
F_34 ( & V_19 -> V_44 ) ;
F_35 ( & V_19 -> V_60 ) ;
F_36 ( & V_19 -> V_61 ) ;
F_36 ( & V_19 -> V_62 ) ;
F_36 ( & V_19 -> V_63 ) ;
F_34 ( & V_19 -> V_64 ) ;
F_37 ( & V_19 -> V_65 ) ;
F_37 ( & V_19 -> V_66 ) ;
V_19 -> V_67 = 0 ;
F_38 ( & V_19 -> V_68 , 0 ) ;
F_39 ( & V_19 -> V_69 ) ;
V_19 -> V_70 = 0 ;
V_19 -> V_71 = F_40 ( V_52 -> V_72 , 0 ) ;
V_19 -> V_73 = F_40 ( V_52 -> V_72 , 1 ) ;
V_19 -> V_74 = F_40 ( V_52 -> V_72 , 2 ) ;
V_19 -> V_75 = V_76 ;
F_27 ( & V_19 -> V_46 ) ;
F_28 ( V_19 , V_77 , V_78 ) ;
V_54 = F_29 ( V_19 , V_77 ) ;
if ( V_54 != V_78 ) {
V_24 = - V_79 ;
F_14 ( L_21 , V_54 ) ;
F_30 ( & V_19 -> V_46 ) ;
goto V_80;
}
V_19 -> V_1 = F_29 ( V_19 , V_81 ) ;
V_19 -> V_82 = F_29 ( V_19 , V_83 ) ;
V_19 -> V_84 = F_29 ( V_19 , V_85 ) ;
V_19 -> V_86 = F_29 ( V_19 , V_87 ) ;
V_19 -> V_88 = F_29 ( V_19 , V_89 ) ;
if ( V_19 -> V_1 & V_14 ) {
V_19 -> V_90 =
F_29 ( V_19 ,
V_91 ) ;
V_19 -> V_92 =
F_29 ( V_19 , V_93 ) ;
}
if ( V_19 -> V_1 & V_16 ) {
V_19 -> V_94 =
F_29 ( V_19 , V_95 ) ;
V_19 -> V_96 =
F_29 ( V_19 , V_97 ) ;
V_19 -> V_96 -= V_19 -> V_82 ;
} else {
V_19 -> V_96 = 512 * 1024 * 1024 ;
}
F_30 ( & V_19 -> V_46 ) ;
F_1 ( V_19 -> V_1 ) ;
if ( V_19 -> V_1 & V_14 ) {
F_2 ( L_22 ,
( unsigned ) V_19 -> V_92 ) ;
F_2 ( L_23 ,
( unsigned ) V_19 -> V_90 ) ;
}
if ( V_19 -> V_1 & V_16 ) {
F_2 ( L_24 ,
( unsigned ) V_19 -> V_94 ) ;
F_2 ( L_25 ,
( unsigned ) V_19 -> V_96 / 1024 ) ;
}
F_2 ( L_26 ,
V_19 -> V_73 , V_19 -> V_82 / 1024 ) ;
F_2 ( L_27 ,
V_19 -> V_74 , V_19 -> V_84 / 1024 ) ;
V_24 = F_41 ( V_19 ) ;
if ( F_8 ( V_24 != 0 ) )
goto V_80;
F_42 ( & V_19 -> V_98 ) ;
F_43 ( & V_19 -> V_98 . V_99 , false , V_100 ) ;
V_19 -> V_101 = & V_19 -> V_98 ;
V_24 = F_44 ( & V_19 -> V_26 ,
V_19 -> V_102 . V_103 . V_104 ,
& V_105 , V_106 ,
false ) ;
if ( F_8 ( V_24 != 0 ) ) {
F_14 ( L_28 ) ;
goto V_107;
}
V_24 = F_45 ( & V_19 -> V_26 , V_108 ,
( V_19 -> V_82 >> V_109 ) ) ;
if ( F_8 ( V_24 != 0 ) ) {
F_14 ( L_29 ) ;
goto V_110;
}
V_19 -> V_111 = true ;
if ( F_45 ( & V_19 -> V_26 , V_112 ,
V_19 -> V_92 ) != 0 ) {
F_2 ( L_30
L_31 ) ;
V_19 -> V_111 = false ;
}
V_19 -> V_113 = F_46 ( V_19 -> V_74 ,
V_19 -> V_84 , V_114 ) ;
V_19 -> V_115 = F_47 ( V_19 -> V_74 ,
V_19 -> V_84 ) ;
if ( F_8 ( V_19 -> V_115 == NULL ) ) {
V_24 = - V_56 ;
F_14 ( L_32 ) ;
goto V_116;
}
if ( ! ( V_19 -> V_1 & V_13 ) &&
! ( V_19 -> V_1 & V_11 ) &&
! F_48 ( V_19 ) ) {
V_24 = - V_79 ;
F_14 ( L_33 ) ;
goto V_117;
}
V_19 -> V_118 = F_49
( V_19 -> V_119 . V_104 , 12 ) ;
if ( F_8 ( V_19 -> V_118 == NULL ) ) {
F_14 ( L_34 ) ;
V_24 = - V_56 ;
goto V_117;
}
V_52 -> V_120 = V_19 ;
V_24 = F_50 ( V_52 -> V_72 , L_35 ) ;
V_19 -> V_121 = ( V_24 != 0 ) ;
if ( V_19 -> V_121 ) {
F_2 ( L_36
L_37 ) ;
V_24 = F_51 ( V_52 -> V_72 , 2 , L_38 ) ;
if ( F_8 ( V_24 != 0 ) ) {
F_14 ( L_39 ) ;
goto V_122;
}
}
V_19 -> V_40 = F_52 ( V_19 ) ;
if ( F_8 ( V_19 -> V_40 == NULL ) )
goto V_123;
V_24 = F_26 ( V_19 , true ) ;
if ( F_8 ( V_24 != 0 ) )
goto V_124;
F_53 ( V_19 ) ;
V_24 = F_54 ( V_19 ) ;
if ( F_8 ( V_24 != 0 ) )
goto V_125;
F_55 ( V_19 ) ;
F_2 ( L_40 ,
F_56 ( V_19 ) ?
L_41 : L_42 ) ;
if ( V_19 -> V_75 ) {
F_57 ( V_19 ) ;
} else {
F_58 ( V_19 ) ;
F_31 ( V_19 , true ) ;
}
if ( V_19 -> V_1 & V_12 ) {
V_24 = F_59 ( V_52 ) ;
if ( F_8 ( V_24 != 0 ) ) {
F_14 ( L_43 , V_24 ) ;
goto V_126;
}
}
V_19 -> V_127 . V_128 = V_129 ;
F_60 ( & V_19 -> V_127 ) ;
return 0 ;
V_126:
if ( V_19 -> V_75 )
F_61 ( V_19 ) ;
F_62 ( V_19 ) ;
F_63 ( V_19 ) ;
V_125:
if ( V_19 -> V_75 ) {
F_58 ( V_19 ) ;
F_31 ( V_19 , false ) ;
}
V_124:
F_64 ( V_19 -> V_40 ) ;
V_123:
if ( V_19 -> V_121 )
F_65 ( V_52 -> V_72 , 2 ) ;
else
F_66 ( V_52 -> V_72 ) ;
V_122:
F_67 ( & V_19 -> V_118 ) ;
V_117:
F_68 ( V_19 -> V_115 ) ;
V_116:
F_69 ( V_19 -> V_113 , V_19 -> V_74 ,
V_19 -> V_84 , V_114 ) ;
if ( V_19 -> V_111 )
( void ) F_70 ( & V_19 -> V_26 , V_112 ) ;
( void ) F_70 ( & V_19 -> V_26 , V_108 ) ;
V_110:
( void ) F_71 ( & V_19 -> V_26 ) ;
V_107:
F_72 ( V_19 ) ;
V_80:
F_73 ( & V_19 -> V_62 ) ;
F_73 ( & V_19 -> V_61 ) ;
F_73 ( & V_19 -> V_63 ) ;
F_74 ( V_19 ) ;
return V_24 ;
}
static int F_75 ( struct V_51 * V_52 )
{
struct V_18 * V_19 = F_76 ( V_52 ) ;
F_77 ( & V_19 -> V_127 ) ;
if ( V_19 -> V_130 . V_131 )
F_78 ( V_19 -> V_130 . V_131 ) ;
if ( V_19 -> V_1 & V_12 )
F_79 ( V_19 -> V_52 ) ;
if ( V_19 -> V_75 ) {
F_61 ( V_19 ) ;
F_58 ( V_19 ) ;
F_31 ( V_19 , false ) ;
}
F_63 ( V_19 ) ;
F_62 ( V_19 ) ;
F_64 ( V_19 -> V_40 ) ;
if ( V_19 -> V_121 )
F_65 ( V_52 -> V_72 , 2 ) ;
else
F_66 ( V_52 -> V_72 ) ;
F_67 ( & V_19 -> V_118 ) ;
F_68 ( V_19 -> V_115 ) ;
F_69 ( V_19 -> V_113 , V_19 -> V_74 ,
V_19 -> V_84 , V_114 ) ;
if ( V_19 -> V_111 )
( void ) F_70 ( & V_19 -> V_26 , V_112 ) ;
( void ) F_70 ( & V_19 -> V_26 , V_108 ) ;
( void ) F_71 ( & V_19 -> V_26 ) ;
F_72 ( V_19 ) ;
F_73 ( & V_19 -> V_62 ) ;
F_73 ( & V_19 -> V_61 ) ;
F_73 ( & V_19 -> V_63 ) ;
F_74 ( V_19 ) ;
return 0 ;
}
static void F_80 ( struct V_51 * V_52 ,
struct V_132 * V_133 )
{
struct V_134 * V_135 ;
V_135 = V_134 ( V_133 ) ;
F_81 ( & V_135 -> V_136 ) ;
if ( V_135 -> V_137 )
F_82 ( & V_135 -> V_137 ) ;
F_74 ( V_135 ) ;
}
static int F_83 ( struct V_51 * V_52 , struct V_132 * V_133 )
{
struct V_18 * V_19 = F_76 ( V_52 ) ;
struct V_134 * V_135 ;
int V_24 = - V_56 ;
V_135 = F_33 ( sizeof( * V_135 ) , V_55 ) ;
if ( F_8 ( V_135 == NULL ) )
return V_24 ;
V_135 -> V_136 = F_84 ( V_19 -> V_118 , 10 ) ;
if ( F_8 ( V_135 -> V_136 == NULL ) )
goto V_138;
V_133 -> V_139 = V_135 ;
if ( F_8 ( V_19 -> V_26 . V_140 == NULL ) )
V_19 -> V_26 . V_140 =
V_133 -> V_141 -> V_142 . V_143 -> V_144 -> V_145 ;
return 0 ;
V_138:
F_74 ( V_135 ) ;
return V_24 ;
}
static long F_85 ( struct V_146 * V_141 , unsigned int V_147 ,
unsigned long V_148 )
{
struct V_132 * V_133 = V_141 -> V_149 ;
struct V_51 * V_52 = V_133 -> V_150 -> V_52 ;
unsigned int V_151 = F_86 ( V_147 ) ;
if ( ( V_151 >= V_152 ) && ( V_151 < V_153 )
&& ( V_151 < V_152 + V_52 -> V_154 -> V_155 ) ) {
struct V_156 * V_157 =
& V_158 [ V_151 - V_152 ] ;
if ( F_8 ( V_157 -> V_159 != V_147 ) ) {
F_14 ( L_44 ,
V_151 - V_152 ) ;
return - V_160 ;
}
}
return F_87 ( V_141 , V_147 , V_148 ) ;
}
static int F_88 ( struct V_51 * V_52 )
{
struct V_18 * V_19 = F_76 ( V_52 ) ;
V_19 -> V_161 = true ;
return 0 ;
}
static void F_89 ( struct V_51 * V_52 )
{
struct V_18 * V_19 = F_76 ( V_52 ) ;
struct V_162 * V_163 ;
struct V_164 V_165 ;
int V_24 ;
if ( ! V_19 -> V_161 )
return;
V_19 -> V_161 = false ;
V_165 . V_166 = 0 ;
V_165 . V_167 = 0 ;
V_165 . V_168 = NULL ;
V_165 . V_169 = NULL ;
V_165 . V_170 = NULL ;
V_165 . V_171 = 0 ;
F_90 (crtc, &dev->mode_config.crtc_list, head) {
V_165 . V_163 = V_163 ;
V_24 = V_163 -> V_172 -> V_173 ( & V_165 ) ;
F_91 ( V_24 != 0 ) ;
}
}
static void F_42 ( struct V_174 * V_175 )
{
F_92 ( & V_175 -> V_99 ) ;
F_39 ( & V_175 -> V_176 ) ;
F_34 ( & V_175 -> V_177 ) ;
}
static int F_93 ( struct V_51 * V_52 ,
struct V_178 * V_179 )
{
struct V_174 * V_175 ;
V_175 = F_33 ( sizeof( * V_175 ) , V_55 ) ;
if ( F_8 ( V_175 == NULL ) )
return - V_56 ;
F_42 ( V_175 ) ;
F_43 ( & V_175 -> V_99 , true , V_100 ) ;
V_179 -> V_139 = V_175 ;
return 0 ;
}
static void F_94 ( struct V_51 * V_52 ,
struct V_178 * V_179 )
{
struct V_174 * V_175 = V_174 ( V_179 ) ;
V_179 -> V_139 = NULL ;
F_74 ( V_175 ) ;
}
static int F_95 ( struct V_51 * V_52 ,
struct V_132 * V_133 ,
bool V_180 )
{
struct V_18 * V_19 = F_76 ( V_52 ) ;
struct V_134 * V_135 = V_134 ( V_133 ) ;
struct V_174 * V_181 = V_19 -> V_101 ;
struct V_174 * V_175 = V_174 ( V_133 -> V_179 ) ;
int V_24 = 0 ;
if ( ! V_19 -> V_75 ) {
V_24 = F_26 ( V_19 , true ) ;
if ( F_8 ( V_24 != 0 ) )
return V_24 ;
F_53 ( V_19 ) ;
F_27 ( & V_19 -> V_46 ) ;
F_28 ( V_19 , V_182 , 0 ) ;
F_30 ( & V_19 -> V_46 ) ;
}
if ( V_181 ) {
F_24 ( V_181 != & V_19 -> V_98 ) ;
V_24 = F_96 ( & V_181 -> V_99 , false , V_135 -> V_136 ) ;
if ( F_8 ( V_24 != 0 ) )
goto V_183;
F_43 ( & V_181 -> V_99 , true , V_100 ) ;
V_24 = F_97 ( & V_19 -> V_26 , V_108 ) ;
if ( F_8 ( V_24 != 0 ) ) {
F_14 ( L_45
L_46 ) ;
}
V_19 -> V_101 = NULL ;
}
F_43 ( & V_175 -> V_99 , false , V_100 ) ;
if ( ! V_180 ) {
F_98 ( & V_175 -> V_99 ) ;
F_24 ( V_135 -> V_137 != V_133 -> V_179 ) ;
F_82 ( & V_135 -> V_137 ) ;
}
V_19 -> V_101 = V_175 ;
return 0 ;
V_183:
if ( ! V_19 -> V_75 ) {
F_27 ( & V_19 -> V_46 ) ;
F_28 ( V_19 , V_182 , 1 ) ;
F_30 ( & V_19 -> V_46 ) ;
F_58 ( V_19 ) ;
F_31 ( V_19 , true ) ;
}
return V_24 ;
}
static void F_99 ( struct V_51 * V_52 ,
struct V_132 * V_133 ,
bool V_184 )
{
struct V_18 * V_19 = F_76 ( V_52 ) ;
struct V_134 * V_135 = V_134 ( V_133 ) ;
struct V_174 * V_175 = V_174 ( V_133 -> V_179 ) ;
int V_24 ;
V_135 -> V_137 = F_100 ( V_133 -> V_179 ) ;
V_24 = F_96 ( & V_175 -> V_99 , false , V_135 -> V_136 ) ;
F_101 ( V_19 , false , 0 ) ;
if ( F_8 ( ( V_24 != 0 ) ) ) {
F_14 ( L_47 ) ;
F_82 ( & V_135 -> V_137 ) ;
}
F_43 ( & V_175 -> V_99 , true , V_100 ) ;
if ( ! V_19 -> V_75 ) {
V_24 = F_97 ( & V_19 -> V_26 , V_108 ) ;
if ( F_8 ( V_24 != 0 ) )
F_14 ( L_48 ) ;
F_27 ( & V_19 -> V_46 ) ;
F_28 ( V_19 , V_182 , 1 ) ;
F_30 ( & V_19 -> V_46 ) ;
F_58 ( V_19 ) ;
F_31 ( V_19 , true ) ;
}
V_19 -> V_101 = & V_19 -> V_98 ;
F_43 ( & V_19 -> V_98 . V_99 , false , V_100 ) ;
F_98 ( & V_19 -> V_98 . V_99 ) ;
if ( V_19 -> V_75 )
F_102 ( V_19 ) ;
}
static void F_103 ( struct V_185 * V_72 )
{
struct V_51 * V_52 = F_104 ( V_72 ) ;
F_105 ( V_52 ) ;
}
static int V_129 ( struct V_186 * V_187 , unsigned long V_188 ,
void * V_189 )
{
struct V_18 * V_19 =
F_106 ( V_187 , struct V_18 , V_127 ) ;
struct V_174 * V_175 = V_19 -> V_101 ;
switch ( V_188 ) {
case V_190 :
case V_191 :
F_107 ( & V_175 -> V_99 ) ;
F_101 ( V_19 , false , 0 ) ;
F_108 ( & V_19 -> V_26 ) ;
break;
case V_192 :
case V_193 :
case V_194 :
F_109 ( & V_175 -> V_99 ) ;
break;
case V_195 :
break;
default:
break;
}
return 0 ;
}
static int F_110 ( struct V_185 * V_72 , T_4 V_33 )
{
struct V_51 * V_52 = F_104 ( V_72 ) ;
struct V_18 * V_19 = F_76 ( V_52 ) ;
if ( V_19 -> V_45 != 0 ) {
F_2 ( L_49
L_50 ) ;
return - V_196 ;
}
F_111 ( V_72 ) ;
F_112 ( V_72 ) ;
F_113 ( V_72 , V_197 ) ;
return 0 ;
}
static int F_114 ( struct V_185 * V_72 )
{
F_113 ( V_72 , V_198 ) ;
F_115 ( V_72 ) ;
return F_116 ( V_72 ) ;
}
static int F_117 ( struct V_199 * V_200 )
{
struct V_185 * V_72 = F_118 ( V_200 ) ;
struct V_201 V_23 ;
V_23 . V_202 = 0 ;
return F_110 ( V_72 , V_23 ) ;
}
static int F_119 ( struct V_199 * V_200 )
{
struct V_185 * V_72 = F_118 ( V_200 ) ;
return F_114 ( V_72 ) ;
}
static int F_120 ( struct V_199 * V_200 )
{
struct V_185 * V_72 = F_118 ( V_200 ) ;
struct V_51 * V_52 = F_104 ( V_72 ) ;
struct V_18 * V_19 = F_76 ( V_52 ) ;
V_19 -> V_203 = true ;
if ( V_19 -> V_75 )
F_31 ( V_19 , true ) ;
if ( V_19 -> V_45 != 0 ) {
F_2 ( L_49
L_50 ) ;
if ( V_19 -> V_75 )
F_26 ( V_19 , true ) ;
V_19 -> V_203 = false ;
return - V_196 ;
}
return 0 ;
}
static void F_121 ( struct V_199 * V_200 )
{
struct V_185 * V_72 = F_118 ( V_200 ) ;
struct V_51 * V_52 = F_104 ( V_72 ) ;
struct V_18 * V_19 = F_76 ( V_52 ) ;
if ( V_19 -> V_75 )
F_26 ( V_19 , false ) ;
V_19 -> V_203 = false ;
}
static int F_122 ( struct V_185 * V_72 , const struct V_204 * V_205 )
{
return F_123 ( V_72 , V_205 , & V_154 ) ;
}
static int T_5 F_124 ( void )
{
int V_24 ;
V_24 = F_125 ( & V_154 , & V_206 ) ;
if ( V_24 )
F_14 ( L_51 ) ;
return V_24 ;
}
static void T_6 F_126 ( void )
{
F_127 ( & V_154 , & V_206 ) ;
}
