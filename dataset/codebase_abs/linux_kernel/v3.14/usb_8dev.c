static int F_1 ( struct V_1 * V_2 , T_1 * V_3 , int V_4 )
{
int V_5 ;
return F_2 ( V_2 -> V_6 ,
F_3 ( V_2 -> V_6 , V_7 ) ,
V_3 , V_4 , & V_5 , V_8 ) ;
}
static int F_4 ( struct V_1 * V_2 , T_1 * V_3 , int V_4 ,
int * V_5 )
{
return F_2 ( V_2 -> V_6 ,
F_5 ( V_2 -> V_6 , V_9 ) ,
V_3 , V_4 , V_5 , V_8 ) ;
}
static int F_6 ( struct V_1 * V_2 ,
struct V_10 * V_11 ,
struct V_10 * V_12 )
{
int V_13 ;
int V_14 ;
struct V_15 * V_16 ;
V_16 = V_2 -> V_16 ;
V_11 -> V_17 = V_18 ;
V_11 -> V_19 = V_20 ;
F_7 ( & V_2 -> V_21 ) ;
memcpy ( V_2 -> V_22 , V_11 ,
sizeof( struct V_10 ) ) ;
V_13 = F_1 ( V_2 , V_2 -> V_22 ,
sizeof( struct V_10 ) ) ;
if ( V_13 < 0 ) {
F_8 ( V_16 , L_1 ) ;
goto V_23;
}
V_13 = F_4 ( V_2 , V_2 -> V_22 ,
sizeof( struct V_10 ) ,
& V_14 ) ;
if ( V_13 < 0 ) {
F_8 ( V_16 , L_2 ) ;
goto V_23;
}
memcpy ( V_12 , V_2 -> V_22 , sizeof( struct V_10 ) ) ;
if ( V_12 -> V_17 != V_18 || V_12 -> V_19 != V_20 ||
V_14 != 16 || V_12 -> V_24 != 0 )
V_13 = - V_25 ;
V_23:
F_9 ( & V_2 -> V_21 ) ;
return V_13 ;
}
static int F_10 ( struct V_1 * V_2 )
{
struct V_26 * V_27 = & V_2 -> V_28 . V_29 ;
struct V_10 V_30 ;
struct V_10 V_31 ;
T_2 V_32 = V_2 -> V_28 . V_32 ;
T_2 V_33 = V_34 ;
T_3 V_35 ;
T_4 V_36 ;
memset ( & V_30 , 0 , sizeof( V_30 ) ) ;
V_30 . V_37 = V_38 ;
V_30 . V_24 = V_39 ;
V_30 . V_40 [ 0 ] = V_27 -> V_41 + V_27 -> V_42 ;
V_30 . V_40 [ 1 ] = V_27 -> V_43 ;
V_30 . V_40 [ 2 ] = V_27 -> V_44 ;
V_36 = F_11 ( ( V_45 ) V_27 -> V_46 ) ;
memcpy ( & V_30 . V_40 [ 3 ] , & V_36 , sizeof( V_36 ) ) ;
if ( V_32 & V_47 )
V_33 |= V_48 ;
if ( V_32 & V_49 )
V_33 |= V_50 ;
if ( V_32 & V_51 )
V_33 |= V_52 ;
V_35 = F_12 ( V_33 ) ;
memcpy ( & V_30 . V_40 [ 5 ] , & V_35 , sizeof( V_35 ) ) ;
return F_6 ( V_2 , & V_30 , & V_31 ) ;
}
static int F_13 ( struct V_1 * V_2 )
{
struct V_10 V_31 ;
struct V_10 V_30 = {
. V_53 = 0 ,
. V_37 = V_54 ,
. V_24 = 0 ,
. V_55 = 0
} ;
return F_6 ( V_2 , & V_30 , & V_31 ) ;
}
static int F_14 ( struct V_1 * V_2 , T_2 * V_56 )
{
struct V_10 V_31 ;
struct V_10 V_30 = {
. V_53 = 0 ,
. V_37 = V_57 ,
. V_24 = 0 ,
. V_55 = 0
} ;
int V_13 = F_6 ( V_2 , & V_30 , & V_31 ) ;
if ( V_13 )
return V_13 ;
* V_56 = F_15 ( ( T_3 * ) V_31 . V_40 ) ;
return V_13 ;
}
static int F_16 ( struct V_15 * V_16 , enum V_58 V_59 )
{
struct V_1 * V_2 = F_17 ( V_16 ) ;
int V_13 = 0 ;
switch ( V_59 ) {
case V_60 :
V_13 = F_10 ( V_2 ) ;
if ( V_13 )
F_18 ( V_16 , L_3 ) ;
break;
default:
return - V_61 ;
}
return V_13 ;
}
static void F_19 ( struct V_1 * V_2 ,
struct V_62 * V_3 )
{
struct V_63 * V_64 ;
struct V_65 * V_66 ;
struct V_67 * V_68 = & V_2 -> V_16 -> V_68 ;
T_1 V_69 = V_3 -> V_40 [ 0 ] ;
T_1 V_70 = V_3 -> V_40 [ 1 ] & V_71 ;
T_1 V_72 = V_3 -> V_40 [ 2 ] ;
int V_73 = 0 ;
int V_74 = 0 ;
V_66 = F_20 ( V_2 -> V_16 , & V_64 ) ;
if ( ! V_66 )
return;
switch ( V_69 ) {
case V_75 :
V_2 -> V_28 . V_69 = V_76 ;
V_64 -> V_77 |= V_78 ;
V_64 -> V_40 [ 2 ] = V_79 ;
break;
case V_80 :
V_2 -> V_28 . V_69 = V_81 ;
V_64 -> V_77 |= V_82 ;
F_21 ( V_2 -> V_16 ) ;
break;
case V_83 :
case V_84 :
case V_85 :
V_64 -> V_77 |= V_86 ;
break;
default:
V_2 -> V_28 . V_69 = V_87 ;
V_64 -> V_77 |= V_78 | V_88 ;
V_2 -> V_28 . V_89 . V_90 ++ ;
break;
}
switch ( V_69 ) {
case V_75 :
case V_80 :
break;
case V_91 :
V_64 -> V_77 |= V_92 ;
V_74 = 1 ;
break;
case V_93 :
V_64 -> V_40 [ 2 ] |= V_94 ;
V_64 -> V_40 [ 3 ] |= V_95 |
V_96 ;
V_73 = 1 ;
break;
case V_97 :
V_64 -> V_40 [ 2 ] |= V_98 ;
V_74 = 1 ;
break;
case V_99 :
V_64 -> V_40 [ 2 ] |= V_100 ;
V_74 = 1 ;
break;
case V_101 :
V_64 -> V_40 [ 2 ] |= V_102 ;
V_73 = 1 ;
break;
case V_103 :
V_64 -> V_40 [ 2 ] |= V_104 ;
V_73 = 1 ;
break;
case V_83 :
V_64 -> V_40 [ 1 ] = V_105 ;
V_68 -> V_106 ++ ;
V_73 = 1 ;
break;
case V_84 :
V_2 -> V_28 . V_69 = V_87 ;
V_64 -> V_40 [ 1 ] = ( V_72 > V_70 ) ?
V_107 :
V_108 ;
V_2 -> V_28 . V_89 . V_109 ++ ;
break;
case V_85 :
V_2 -> V_28 . V_69 = V_110 ;
V_64 -> V_40 [ 1 ] = ( V_72 > V_70 ) ?
V_111 :
V_112 ;
V_2 -> V_28 . V_89 . V_113 ++ ;
break;
default:
F_18 ( V_2 -> V_16 ,
L_4 , V_69 ) ;
break;
}
if ( V_74 ) {
V_64 -> V_40 [ 2 ] |= V_114 ;
V_68 -> V_74 ++ ;
}
if ( V_73 )
V_68 -> V_73 ++ ;
V_64 -> V_40 [ 6 ] = V_72 ;
V_64 -> V_40 [ 7 ] = V_70 ;
V_2 -> V_115 . V_72 = V_72 ;
V_2 -> V_115 . V_70 = V_70 ;
F_22 ( V_66 ) ;
V_68 -> V_116 ++ ;
V_68 -> V_117 += V_64 -> V_118 ;
}
static void F_23 ( struct V_1 * V_2 ,
struct V_62 * V_3 )
{
struct V_63 * V_64 ;
struct V_65 * V_66 ;
struct V_67 * V_68 = & V_2 -> V_16 -> V_68 ;
if ( V_3 -> type == V_119 &&
V_3 -> V_33 == V_120 ) {
F_19 ( V_2 , V_3 ) ;
} else if ( V_3 -> type == V_121 ) {
V_66 = F_24 ( V_2 -> V_16 , & V_64 ) ;
if ( ! V_66 )
return;
V_64 -> V_77 = F_25 ( V_3 -> V_122 ) ;
V_64 -> V_118 = F_26 ( V_3 -> V_123 & 0xF ) ;
if ( V_3 -> V_33 & V_124 )
V_64 -> V_77 |= V_125 ;
if ( V_3 -> V_33 & V_126 )
V_64 -> V_77 |= V_127 ;
else
memcpy ( V_64 -> V_40 , V_3 -> V_40 , V_64 -> V_118 ) ;
F_22 ( V_66 ) ;
V_68 -> V_116 ++ ;
V_68 -> V_117 += V_64 -> V_118 ;
F_27 ( V_2 -> V_16 , V_128 ) ;
} else {
F_18 ( V_2 -> V_16 , L_5 ,
V_3 -> type ) ;
}
}
static void F_28 ( struct V_129 * V_129 )
{
struct V_1 * V_2 = V_129 -> V_130 ;
struct V_15 * V_16 ;
int V_131 ;
int V_132 = 0 ;
V_16 = V_2 -> V_16 ;
if ( ! F_29 ( V_16 ) )
return;
switch ( V_129 -> V_133 ) {
case 0 :
break;
case - V_134 :
case - V_135 :
return;
default:
F_30 ( V_16 , L_6 ,
V_129 -> V_133 ) ;
goto V_136;
}
while ( V_132 < V_129 -> V_5 ) {
struct V_62 * V_3 ;
if ( V_132 + sizeof( struct V_62 ) > V_129 -> V_5 ) {
F_8 ( V_2 -> V_16 , L_7 ) ;
break;
}
V_3 = (struct V_62 * ) ( V_129 -> V_137 + V_132 ) ;
F_23 ( V_2 , V_3 ) ;
V_132 += sizeof( struct V_62 ) ;
}
V_136:
F_31 ( V_129 , V_2 -> V_6 ,
F_5 ( V_2 -> V_6 , V_138 ) ,
V_129 -> V_137 , V_139 ,
F_28 , V_2 ) ;
V_131 = F_32 ( V_129 , V_140 ) ;
if ( V_131 == - V_141 )
F_33 ( V_16 ) ;
else if ( V_131 )
F_8 ( V_16 ,
L_8 , V_131 ) ;
}
static void F_34 ( struct V_129 * V_129 )
{
struct V_142 * V_130 = V_129 -> V_130 ;
struct V_1 * V_2 ;
struct V_15 * V_16 ;
F_35 ( ! V_130 ) ;
V_2 = V_130 -> V_2 ;
V_16 = V_2 -> V_16 ;
F_36 ( V_129 -> V_143 , V_129 -> V_144 ,
V_129 -> V_137 , V_129 -> V_145 ) ;
F_37 ( & V_2 -> V_146 ) ;
if ( ! F_29 ( V_16 ) )
return;
if ( V_129 -> V_133 )
F_30 ( V_16 , L_9 ,
V_129 -> V_133 ) ;
V_16 -> V_68 . V_147 ++ ;
V_16 -> V_68 . V_148 += V_130 -> V_123 ;
F_38 ( V_16 , V_130 -> V_149 ) ;
F_27 ( V_16 , V_150 ) ;
V_130 -> V_149 = V_151 ;
F_39 ( V_16 ) ;
}
static T_5 F_40 ( struct V_65 * V_66 ,
struct V_15 * V_16 )
{
struct V_1 * V_2 = F_17 ( V_16 ) ;
struct V_67 * V_68 = & V_16 -> V_68 ;
struct V_63 * V_64 = (struct V_63 * ) V_66 -> V_40 ;
struct V_152 * V_3 ;
struct V_129 * V_129 ;
struct V_142 * V_130 = NULL ;
T_1 * V_153 ;
int V_154 , V_13 ;
T_6 V_4 = sizeof( struct V_152 ) ;
if ( F_41 ( V_16 , V_66 ) )
return V_155 ;
V_129 = F_42 ( 0 , V_140 ) ;
if ( ! V_129 ) {
F_8 ( V_16 , L_10 ) ;
goto V_156;
}
V_153 = F_43 ( V_2 -> V_6 , V_4 , V_140 ,
& V_129 -> V_145 ) ;
if ( ! V_153 ) {
F_8 ( V_16 , L_11 ) ;
goto V_157;
}
memset ( V_153 , 0 , V_4 ) ;
V_3 = (struct V_152 * ) V_153 ;
V_3 -> V_17 = V_158 ;
V_3 -> V_33 = 0x00 ;
if ( V_64 -> V_77 & V_127 )
V_3 -> V_33 |= V_126 ;
if ( V_64 -> V_77 & V_125 )
V_3 -> V_33 |= V_124 ;
V_3 -> V_122 = F_12 ( V_64 -> V_77 & V_159 ) ;
V_3 -> V_123 = V_64 -> V_118 ;
memcpy ( V_3 -> V_40 , V_64 -> V_40 , V_64 -> V_118 ) ;
V_3 -> V_19 = V_160 ;
for ( V_154 = 0 ; V_154 < V_151 ; V_154 ++ ) {
if ( V_2 -> V_161 [ V_154 ] . V_149 == V_151 ) {
V_130 = & V_2 -> V_161 [ V_154 ] ;
break;
}
}
if ( ! V_130 )
goto V_162;
V_130 -> V_2 = V_2 ;
V_130 -> V_149 = V_154 ;
V_130 -> V_123 = V_64 -> V_118 ;
F_31 ( V_129 , V_2 -> V_6 ,
F_3 ( V_2 -> V_6 , V_163 ) ,
V_153 , V_4 , F_34 , V_130 ) ;
V_129 -> V_164 |= V_165 ;
F_44 ( V_129 , & V_2 -> V_166 ) ;
F_45 ( V_66 , V_16 , V_130 -> V_149 ) ;
F_46 ( & V_2 -> V_146 ) ;
V_13 = F_32 ( V_129 , V_140 ) ;
if ( F_47 ( V_13 ) )
goto V_23;
else if ( F_48 ( & V_2 -> V_146 ) >= V_151 )
F_49 ( V_16 ) ;
F_50 ( V_129 ) ;
return V_155 ;
V_162:
F_51 ( V_129 ) ;
F_36 ( V_2 -> V_6 , V_4 , V_153 , V_129 -> V_145 ) ;
F_18 ( V_16 , L_12 ) ;
return V_167 ;
V_23:
F_52 ( V_16 , V_130 -> V_149 ) ;
F_51 ( V_129 ) ;
F_36 ( V_2 -> V_6 , V_4 , V_153 , V_129 -> V_145 ) ;
F_37 ( & V_2 -> V_146 ) ;
if ( V_13 == - V_141 )
F_33 ( V_16 ) ;
else
F_18 ( V_16 , L_13 , V_13 ) ;
V_157:
F_50 ( V_129 ) ;
V_156:
F_53 ( V_66 ) ;
V_68 -> V_168 ++ ;
return V_155 ;
}
static int F_54 ( const struct V_15 * V_16 ,
struct V_169 * V_115 )
{
struct V_1 * V_2 = F_17 ( V_16 ) ;
V_115 -> V_72 = V_2 -> V_115 . V_72 ;
V_115 -> V_70 = V_2 -> V_115 . V_70 ;
return 0 ;
}
static int F_55 ( struct V_1 * V_2 )
{
struct V_15 * V_16 = V_2 -> V_16 ;
int V_13 , V_154 ;
for ( V_154 = 0 ; V_154 < V_170 ; V_154 ++ ) {
struct V_129 * V_129 = NULL ;
T_1 * V_153 ;
V_129 = F_42 ( 0 , V_171 ) ;
if ( ! V_129 ) {
F_8 ( V_16 , L_10 ) ;
V_13 = - V_172 ;
break;
}
V_153 = F_43 ( V_2 -> V_6 , V_139 , V_171 ,
& V_129 -> V_145 ) ;
if ( ! V_153 ) {
F_8 ( V_16 , L_11 ) ;
F_50 ( V_129 ) ;
V_13 = - V_172 ;
break;
}
F_31 ( V_129 , V_2 -> V_6 ,
F_5 ( V_2 -> V_6 ,
V_138 ) ,
V_153 , V_139 ,
F_28 , V_2 ) ;
V_129 -> V_164 |= V_165 ;
F_44 ( V_129 , & V_2 -> V_173 ) ;
V_13 = F_32 ( V_129 , V_171 ) ;
if ( V_13 ) {
F_51 ( V_129 ) ;
F_36 ( V_2 -> V_6 , V_139 , V_153 ,
V_129 -> V_145 ) ;
F_50 ( V_129 ) ;
break;
}
F_50 ( V_129 ) ;
}
if ( V_154 == 0 ) {
F_18 ( V_16 , L_14 ) ;
return V_13 ;
}
if ( V_154 < V_170 )
F_18 ( V_16 , L_15 ) ;
V_13 = F_10 ( V_2 ) ;
if ( V_13 )
goto V_23;
V_2 -> V_28 . V_69 = V_76 ;
return 0 ;
V_23:
if ( V_13 == - V_141 )
F_33 ( V_2 -> V_16 ) ;
F_18 ( V_16 , L_16 , V_13 ) ;
return V_13 ;
}
static int F_56 ( struct V_15 * V_16 )
{
struct V_1 * V_2 = F_17 ( V_16 ) ;
int V_13 ;
V_13 = F_57 ( V_16 ) ;
if ( V_13 )
return V_13 ;
F_27 ( V_16 , V_174 ) ;
V_13 = F_55 ( V_2 ) ;
if ( V_13 ) {
if ( V_13 == - V_141 )
F_33 ( V_2 -> V_16 ) ;
F_18 ( V_16 , L_17 ,
V_13 ) ;
F_58 ( V_16 ) ;
return V_13 ;
}
F_59 ( V_16 ) ;
return 0 ;
}
static void F_60 ( struct V_1 * V_2 )
{
int V_154 ;
F_61 ( & V_2 -> V_173 ) ;
F_61 ( & V_2 -> V_166 ) ;
F_62 ( & V_2 -> V_146 , 0 ) ;
for ( V_154 = 0 ; V_154 < V_151 ; V_154 ++ )
V_2 -> V_161 [ V_154 ] . V_149 = V_151 ;
}
static int F_63 ( struct V_15 * V_16 )
{
struct V_1 * V_2 = F_17 ( V_16 ) ;
int V_13 = 0 ;
V_13 = F_13 ( V_2 ) ;
if ( V_13 )
F_18 ( V_16 , L_18 ) ;
V_2 -> V_28 . V_69 = V_175 ;
F_49 ( V_16 ) ;
F_60 ( V_2 ) ;
F_58 ( V_16 ) ;
F_27 ( V_16 , V_176 ) ;
return V_13 ;
}
static int F_64 ( struct V_177 * V_178 ,
const struct V_179 * V_122 )
{
struct V_15 * V_16 ;
struct V_1 * V_2 ;
int V_154 , V_13 = - V_172 ;
T_2 V_180 ;
char V_153 [ 18 ] ;
struct V_181 * V_182 = F_65 ( V_178 ) ;
if ( F_66 ( V_182 , V_182 -> V_183 . V_184 , V_153 ,
sizeof( V_153 ) ) > 0 && strcmp ( V_153 , L_19 ) ) {
F_67 ( & V_182 -> V_143 , L_20 ) ;
return - V_141 ;
}
V_16 = F_68 ( sizeof( struct V_1 ) , V_151 ) ;
if ( ! V_16 ) {
F_69 ( & V_178 -> V_143 , L_21 ) ;
return - V_172 ;
}
V_2 = F_17 ( V_16 ) ;
V_2 -> V_6 = V_182 ;
V_2 -> V_16 = V_16 ;
V_2 -> V_28 . V_69 = V_175 ;
V_2 -> V_28 . clock . V_185 = V_186 ;
V_2 -> V_28 . V_187 = & V_188 ;
V_2 -> V_28 . V_189 = F_16 ;
V_2 -> V_28 . V_190 = F_54 ;
V_2 -> V_28 . V_191 = V_47 |
V_49 |
V_51 ;
V_16 -> V_192 = & V_193 ;
V_16 -> V_33 |= V_194 ;
F_70 ( & V_2 -> V_173 ) ;
F_70 ( & V_2 -> V_166 ) ;
F_62 ( & V_2 -> V_146 , 0 ) ;
for ( V_154 = 0 ; V_154 < V_151 ; V_154 ++ )
V_2 -> V_161 [ V_154 ] . V_149 = V_151 ;
V_2 -> V_22 = F_71 ( sizeof( struct V_10 ) ,
V_171 ) ;
if ( ! V_2 -> V_22 )
goto V_195;
F_72 ( V_178 , V_2 ) ;
F_73 ( V_16 , & V_178 -> V_143 ) ;
F_74 ( & V_2 -> V_21 ) ;
V_13 = F_75 ( V_16 ) ;
if ( V_13 ) {
F_8 ( V_16 ,
L_22 , V_13 ) ;
goto V_196;
}
V_13 = F_14 ( V_2 , & V_180 ) ;
if ( V_13 ) {
F_8 ( V_16 , L_23 ) ;
goto V_197;
} else {
F_30 ( V_16 ,
L_24 ,
( V_180 >> 24 ) & 0xff , ( V_180 >> 16 ) & 0xff ,
( V_180 >> 8 ) & 0xff , V_180 & 0xff ) ;
}
F_76 ( V_16 ) ;
return 0 ;
V_197:
F_77 ( V_2 -> V_16 ) ;
V_196:
F_78 ( V_2 -> V_22 ) ;
V_195:
F_79 ( V_16 ) ;
return V_13 ;
}
static void F_80 ( struct V_177 * V_178 )
{
struct V_1 * V_2 = F_81 ( V_178 ) ;
F_72 ( V_178 , NULL ) ;
if ( V_2 ) {
F_30 ( V_2 -> V_16 , L_25 ) ;
F_77 ( V_2 -> V_16 ) ;
F_79 ( V_2 -> V_16 ) ;
F_60 ( V_2 ) ;
}
}
