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
V_2 -> V_28 . V_83 . V_84 ++ ;
F_21 ( V_2 -> V_16 ) ;
break;
case V_85 :
case V_86 :
case V_87 :
V_64 -> V_77 |= V_88 ;
break;
default:
V_2 -> V_28 . V_69 = V_89 ;
V_64 -> V_77 |= V_78 | V_90 ;
V_2 -> V_28 . V_83 . V_91 ++ ;
break;
}
switch ( V_69 ) {
case V_75 :
case V_80 :
break;
case V_92 :
V_64 -> V_77 |= V_93 ;
V_74 = 1 ;
break;
case V_94 :
V_64 -> V_40 [ 3 ] = V_95 ;
V_73 = 1 ;
break;
case V_96 :
V_64 -> V_40 [ 2 ] |= V_97 ;
V_74 = 1 ;
break;
case V_98 :
V_64 -> V_40 [ 2 ] |= V_99 ;
V_74 = 1 ;
break;
case V_100 :
V_64 -> V_40 [ 2 ] |= V_101 ;
V_73 = 1 ;
break;
case V_102 :
V_64 -> V_40 [ 2 ] |= V_103 ;
V_73 = 1 ;
break;
case V_85 :
V_64 -> V_40 [ 1 ] = V_104 ;
V_68 -> V_105 ++ ;
V_73 = 1 ;
break;
case V_86 :
V_2 -> V_28 . V_69 = V_89 ;
V_64 -> V_40 [ 1 ] = ( V_72 > V_70 ) ?
V_106 :
V_107 ;
V_2 -> V_28 . V_83 . V_108 ++ ;
break;
case V_87 :
V_2 -> V_28 . V_69 = V_109 ;
V_64 -> V_40 [ 1 ] = ( V_72 > V_70 ) ?
V_110 :
V_111 ;
V_2 -> V_28 . V_83 . V_112 ++ ;
break;
default:
F_18 ( V_2 -> V_16 ,
L_4 , V_69 ) ;
break;
}
if ( V_74 ) {
V_64 -> V_40 [ 2 ] |= V_113 ;
V_68 -> V_74 ++ ;
}
if ( V_73 )
V_68 -> V_73 ++ ;
V_64 -> V_40 [ 6 ] = V_72 ;
V_64 -> V_40 [ 7 ] = V_70 ;
V_2 -> V_114 . V_72 = V_72 ;
V_2 -> V_114 . V_70 = V_70 ;
V_68 -> V_115 ++ ;
V_68 -> V_116 += V_64 -> V_117 ;
F_22 ( V_66 ) ;
}
static void F_23 ( struct V_1 * V_2 ,
struct V_62 * V_3 )
{
struct V_63 * V_64 ;
struct V_65 * V_66 ;
struct V_67 * V_68 = & V_2 -> V_16 -> V_68 ;
if ( V_3 -> type == V_118 &&
V_3 -> V_33 == V_119 ) {
F_19 ( V_2 , V_3 ) ;
} else if ( V_3 -> type == V_120 ) {
V_66 = F_24 ( V_2 -> V_16 , & V_64 ) ;
if ( ! V_66 )
return;
V_64 -> V_77 = F_25 ( V_3 -> V_121 ) ;
V_64 -> V_117 = F_26 ( V_3 -> V_122 & 0xF ) ;
if ( V_3 -> V_33 & V_123 )
V_64 -> V_77 |= V_124 ;
if ( V_3 -> V_33 & V_125 )
V_64 -> V_77 |= V_126 ;
else
memcpy ( V_64 -> V_40 , V_3 -> V_40 , V_64 -> V_117 ) ;
V_68 -> V_115 ++ ;
V_68 -> V_116 += V_64 -> V_117 ;
F_22 ( V_66 ) ;
F_27 ( V_2 -> V_16 , V_127 ) ;
} else {
F_18 ( V_2 -> V_16 , L_5 ,
V_3 -> type ) ;
}
}
static void F_28 ( struct V_128 * V_128 )
{
struct V_1 * V_2 = V_128 -> V_129 ;
struct V_15 * V_16 ;
int V_130 ;
int V_131 = 0 ;
V_16 = V_2 -> V_16 ;
if ( ! F_29 ( V_16 ) )
return;
switch ( V_128 -> V_132 ) {
case 0 :
break;
case - V_133 :
case - V_134 :
return;
default:
F_30 ( V_16 , L_6 ,
V_128 -> V_132 ) ;
goto V_135;
}
while ( V_131 < V_128 -> V_5 ) {
struct V_62 * V_3 ;
if ( V_131 + sizeof( struct V_62 ) > V_128 -> V_5 ) {
F_8 ( V_2 -> V_16 , L_7 ) ;
break;
}
V_3 = (struct V_62 * ) ( V_128 -> V_136 + V_131 ) ;
F_23 ( V_2 , V_3 ) ;
V_131 += sizeof( struct V_62 ) ;
}
V_135:
F_31 ( V_128 , V_2 -> V_6 ,
F_5 ( V_2 -> V_6 , V_137 ) ,
V_128 -> V_136 , V_138 ,
F_28 , V_2 ) ;
V_130 = F_32 ( V_128 , V_139 ) ;
if ( V_130 == - V_140 )
F_33 ( V_16 ) ;
else if ( V_130 )
F_8 ( V_16 ,
L_8 , V_130 ) ;
}
static void F_34 ( struct V_128 * V_128 )
{
struct V_141 * V_129 = V_128 -> V_129 ;
struct V_1 * V_2 ;
struct V_15 * V_16 ;
F_35 ( ! V_129 ) ;
V_2 = V_129 -> V_2 ;
V_16 = V_2 -> V_16 ;
F_36 ( V_128 -> V_142 , V_128 -> V_143 ,
V_128 -> V_136 , V_128 -> V_144 ) ;
F_37 ( & V_2 -> V_145 ) ;
if ( ! F_29 ( V_16 ) )
return;
if ( V_128 -> V_132 )
F_30 ( V_16 , L_9 ,
V_128 -> V_132 ) ;
V_16 -> V_68 . V_146 ++ ;
V_16 -> V_68 . V_147 += V_129 -> V_122 ;
F_38 ( V_16 , V_129 -> V_148 ) ;
F_27 ( V_16 , V_149 ) ;
V_129 -> V_148 = V_150 ;
F_39 ( V_16 ) ;
}
static T_5 F_40 ( struct V_65 * V_66 ,
struct V_15 * V_16 )
{
struct V_1 * V_2 = F_17 ( V_16 ) ;
struct V_67 * V_68 = & V_16 -> V_68 ;
struct V_63 * V_64 = (struct V_63 * ) V_66 -> V_40 ;
struct V_151 * V_3 ;
struct V_128 * V_128 ;
struct V_141 * V_129 = NULL ;
T_1 * V_152 ;
int V_153 , V_13 ;
T_6 V_4 = sizeof( struct V_151 ) ;
if ( F_41 ( V_16 , V_66 ) )
return V_154 ;
V_128 = F_42 ( 0 , V_139 ) ;
if ( ! V_128 )
goto V_155;
V_152 = F_43 ( V_2 -> V_6 , V_4 , V_139 ,
& V_128 -> V_144 ) ;
if ( ! V_152 ) {
F_8 ( V_16 , L_10 ) ;
goto V_156;
}
memset ( V_152 , 0 , V_4 ) ;
V_3 = (struct V_151 * ) V_152 ;
V_3 -> V_17 = V_157 ;
V_3 -> V_33 = 0x00 ;
if ( V_64 -> V_77 & V_126 )
V_3 -> V_33 |= V_125 ;
if ( V_64 -> V_77 & V_124 )
V_3 -> V_33 |= V_123 ;
V_3 -> V_121 = F_12 ( V_64 -> V_77 & V_158 ) ;
V_3 -> V_122 = V_64 -> V_117 ;
memcpy ( V_3 -> V_40 , V_64 -> V_40 , V_64 -> V_117 ) ;
V_3 -> V_19 = V_159 ;
for ( V_153 = 0 ; V_153 < V_150 ; V_153 ++ ) {
if ( V_2 -> V_160 [ V_153 ] . V_148 == V_150 ) {
V_129 = & V_2 -> V_160 [ V_153 ] ;
break;
}
}
if ( ! V_129 )
goto V_161;
V_129 -> V_2 = V_2 ;
V_129 -> V_148 = V_153 ;
V_129 -> V_122 = V_64 -> V_117 ;
F_31 ( V_128 , V_2 -> V_6 ,
F_3 ( V_2 -> V_6 , V_162 ) ,
V_152 , V_4 , F_34 , V_129 ) ;
V_128 -> V_163 |= V_164 ;
F_44 ( V_128 , & V_2 -> V_165 ) ;
F_45 ( V_66 , V_16 , V_129 -> V_148 ) ;
F_46 ( & V_2 -> V_145 ) ;
V_13 = F_32 ( V_128 , V_139 ) ;
if ( F_47 ( V_13 ) )
goto V_23;
else if ( F_48 ( & V_2 -> V_145 ) >= V_150 )
F_49 ( V_16 ) ;
F_50 ( V_128 ) ;
return V_154 ;
V_161:
F_36 ( V_2 -> V_6 , V_4 , V_152 , V_128 -> V_144 ) ;
F_50 ( V_128 ) ;
F_18 ( V_16 , L_11 ) ;
return V_166 ;
V_23:
F_51 ( V_16 , V_129 -> V_148 ) ;
F_52 ( V_128 ) ;
F_36 ( V_2 -> V_6 , V_4 , V_152 , V_128 -> V_144 ) ;
F_37 ( & V_2 -> V_145 ) ;
if ( V_13 == - V_140 )
F_33 ( V_16 ) ;
else
F_18 ( V_16 , L_12 , V_13 ) ;
V_156:
F_50 ( V_128 ) ;
V_155:
F_53 ( V_66 ) ;
V_68 -> V_167 ++ ;
return V_154 ;
}
static int F_54 ( const struct V_15 * V_16 ,
struct V_168 * V_114 )
{
struct V_1 * V_2 = F_17 ( V_16 ) ;
V_114 -> V_72 = V_2 -> V_114 . V_72 ;
V_114 -> V_70 = V_2 -> V_114 . V_70 ;
return 0 ;
}
static int F_55 ( struct V_1 * V_2 )
{
struct V_15 * V_16 = V_2 -> V_16 ;
int V_13 , V_153 ;
for ( V_153 = 0 ; V_153 < V_169 ; V_153 ++ ) {
struct V_128 * V_128 = NULL ;
T_1 * V_152 ;
V_128 = F_42 ( 0 , V_170 ) ;
if ( ! V_128 ) {
V_13 = - V_171 ;
break;
}
V_152 = F_43 ( V_2 -> V_6 , V_138 , V_170 ,
& V_128 -> V_144 ) ;
if ( ! V_152 ) {
F_8 ( V_16 , L_10 ) ;
F_50 ( V_128 ) ;
V_13 = - V_171 ;
break;
}
F_31 ( V_128 , V_2 -> V_6 ,
F_5 ( V_2 -> V_6 ,
V_137 ) ,
V_152 , V_138 ,
F_28 , V_2 ) ;
V_128 -> V_163 |= V_164 ;
F_44 ( V_128 , & V_2 -> V_172 ) ;
V_13 = F_32 ( V_128 , V_170 ) ;
if ( V_13 ) {
F_52 ( V_128 ) ;
F_36 ( V_2 -> V_6 , V_138 , V_152 ,
V_128 -> V_144 ) ;
F_50 ( V_128 ) ;
break;
}
F_50 ( V_128 ) ;
}
if ( V_153 == 0 ) {
F_18 ( V_16 , L_13 ) ;
return V_13 ;
}
if ( V_153 < V_169 )
F_18 ( V_16 , L_14 ) ;
V_13 = F_10 ( V_2 ) ;
if ( V_13 )
goto V_23;
V_2 -> V_28 . V_69 = V_76 ;
return 0 ;
V_23:
if ( V_13 == - V_140 )
F_33 ( V_2 -> V_16 ) ;
F_18 ( V_16 , L_15 , V_13 ) ;
return V_13 ;
}
static int F_56 ( struct V_15 * V_16 )
{
struct V_1 * V_2 = F_17 ( V_16 ) ;
int V_13 ;
V_13 = F_57 ( V_16 ) ;
if ( V_13 )
return V_13 ;
F_27 ( V_16 , V_173 ) ;
V_13 = F_55 ( V_2 ) ;
if ( V_13 ) {
if ( V_13 == - V_140 )
F_33 ( V_2 -> V_16 ) ;
F_18 ( V_16 , L_16 ,
V_13 ) ;
F_58 ( V_16 ) ;
return V_13 ;
}
F_59 ( V_16 ) ;
return 0 ;
}
static void F_60 ( struct V_1 * V_2 )
{
int V_153 ;
F_61 ( & V_2 -> V_172 ) ;
F_61 ( & V_2 -> V_165 ) ;
F_62 ( & V_2 -> V_145 , 0 ) ;
for ( V_153 = 0 ; V_153 < V_150 ; V_153 ++ )
V_2 -> V_160 [ V_153 ] . V_148 = V_150 ;
}
static int F_63 ( struct V_15 * V_16 )
{
struct V_1 * V_2 = F_17 ( V_16 ) ;
int V_13 = 0 ;
V_13 = F_13 ( V_2 ) ;
if ( V_13 )
F_18 ( V_16 , L_17 ) ;
V_2 -> V_28 . V_69 = V_174 ;
F_49 ( V_16 ) ;
F_60 ( V_2 ) ;
F_58 ( V_16 ) ;
F_27 ( V_16 , V_175 ) ;
return V_13 ;
}
static int F_64 ( struct V_176 * V_177 ,
const struct V_178 * V_121 )
{
struct V_15 * V_16 ;
struct V_1 * V_2 ;
int V_153 , V_13 = - V_171 ;
T_2 V_179 ;
char V_152 [ 18 ] ;
struct V_180 * V_181 = F_65 ( V_177 ) ;
if ( F_66 ( V_181 , V_181 -> V_182 . V_183 , V_152 ,
sizeof( V_152 ) ) > 0 && strcmp ( V_152 , L_18 ) ) {
F_67 ( & V_181 -> V_142 , L_19 ) ;
return - V_140 ;
}
V_16 = F_68 ( sizeof( struct V_1 ) , V_150 ) ;
if ( ! V_16 ) {
F_69 ( & V_177 -> V_142 , L_20 ) ;
return - V_171 ;
}
V_2 = F_17 ( V_16 ) ;
V_2 -> V_6 = V_181 ;
V_2 -> V_16 = V_16 ;
V_2 -> V_28 . V_69 = V_174 ;
V_2 -> V_28 . clock . V_184 = V_185 ;
V_2 -> V_28 . V_186 = & V_187 ;
V_2 -> V_28 . V_188 = F_16 ;
V_2 -> V_28 . V_189 = F_54 ;
V_2 -> V_28 . V_190 = V_47 |
V_49 |
V_51 ;
V_16 -> V_191 = & V_192 ;
V_16 -> V_33 |= V_193 ;
F_70 ( & V_2 -> V_172 ) ;
F_70 ( & V_2 -> V_165 ) ;
F_62 ( & V_2 -> V_145 , 0 ) ;
for ( V_153 = 0 ; V_153 < V_150 ; V_153 ++ )
V_2 -> V_160 [ V_153 ] . V_148 = V_150 ;
V_2 -> V_22 = F_71 ( sizeof( struct V_10 ) ,
V_170 ) ;
if ( ! V_2 -> V_22 )
goto V_194;
F_72 ( V_177 , V_2 ) ;
F_73 ( V_16 , & V_177 -> V_142 ) ;
F_74 ( & V_2 -> V_21 ) ;
V_13 = F_75 ( V_16 ) ;
if ( V_13 ) {
F_8 ( V_16 ,
L_21 , V_13 ) ;
goto V_195;
}
V_13 = F_14 ( V_2 , & V_179 ) ;
if ( V_13 ) {
F_8 ( V_16 , L_22 ) ;
goto V_196;
} else {
F_30 ( V_16 ,
L_23 ,
( V_179 >> 24 ) & 0xff , ( V_179 >> 16 ) & 0xff ,
( V_179 >> 8 ) & 0xff , V_179 & 0xff ) ;
}
F_76 ( V_16 ) ;
return 0 ;
V_196:
F_77 ( V_2 -> V_16 ) ;
V_195:
F_78 ( V_2 -> V_22 ) ;
V_194:
F_79 ( V_16 ) ;
return V_13 ;
}
static void F_80 ( struct V_176 * V_177 )
{
struct V_1 * V_2 = F_81 ( V_177 ) ;
F_72 ( V_177 , NULL ) ;
if ( V_2 ) {
F_30 ( V_2 -> V_16 , L_24 ) ;
F_77 ( V_2 -> V_16 ) ;
F_79 ( V_2 -> V_16 ) ;
F_60 ( V_2 ) ;
}
}
