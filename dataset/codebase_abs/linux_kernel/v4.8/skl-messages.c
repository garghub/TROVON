static int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 , T_1 V_5 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
struct V_8 * V_9 = F_3 ( V_7 ) ;
if ( ! V_9 )
return - V_10 ;
return V_9 -> V_11 -> V_12 ( V_9 , V_13 , V_5 , V_4 ) ;
}
static int F_4 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
struct V_8 * V_9 = F_3 ( V_7 ) ;
if ( ! V_9 )
return - V_10 ;
V_9 -> V_11 -> V_14 ( V_9 , V_4 ) ;
return 0 ;
}
static void F_5 ( struct V_15 * V_16 , bool V_17 )
{
struct V_18 V_19 ;
struct V_20 V_21 = { 0 } ;
V_19 . V_22 = V_23 ;
V_19 . V_17 = V_17 ;
V_21 . V_24 = V_25 ;
V_21 . V_26 = sizeof( V_19 ) ;
F_6 ( & V_16 -> V_27 , & V_21 , ( V_28 * ) & V_19 ) ;
}
static int F_7 ( struct V_1 * V_2 , unsigned int V_5 ,
int V_29 , int V_17 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
struct V_8 * V_9 = F_3 ( V_7 ) ;
struct V_30 * V_31 = F_8 ( V_9 ,
V_32 , V_29 ) ;
struct V_33 * V_34 ;
if ( ! V_31 )
return - V_35 ;
V_34 = F_9 ( V_31 ) ;
F_10 ( V_7 , V_17 , V_31 -> V_36 ) ;
F_11 ( V_7 , V_34 , V_5 ) ;
return 0 ;
}
static int F_12 ( struct V_1 * V_2 , unsigned int V_37 ,
unsigned int V_5 , struct V_3 * V_4 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
struct V_8 * V_9 = F_3 ( V_7 ) ;
struct V_33 * V_34 ;
struct V_30 * V_31 ;
struct V_38 V_39 ;
int V_40 ;
if ( ! V_9 )
return - V_10 ;
memset ( & V_39 , 0 , sizeof( V_39 ) ) ;
V_39 . V_31 = V_32 ;
V_34 = F_13 ( V_7 , & V_39 ,
V_41 ) ;
if ( ! V_34 )
return - V_10 ;
V_31 = V_30 ( V_34 ) ;
V_40 = F_14 ( V_31 , V_37 , V_5 , V_4 ) ;
if ( V_40 < 0 )
return V_40 ;
F_7 ( V_2 , V_5 , V_31 -> V_29 , true ) ;
return V_31 -> V_29 ;
}
static int F_15 ( struct V_1 * V_2 , bool V_42 , int V_29 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
struct V_30 * V_31 ;
struct V_8 * V_9 = F_3 ( V_7 ) ;
if ( ! V_9 )
return - V_10 ;
V_31 = F_8 ( V_9 ,
V_32 , V_29 ) ;
if ( ! V_31 )
return - V_35 ;
F_16 ( V_31 , V_42 ) ;
return 0 ;
}
static int F_17 ( struct V_1 * V_2 ,
struct V_3 * V_4 , int V_29 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
struct V_30 * V_31 ;
struct V_33 * V_34 ;
struct V_8 * V_9 = F_3 ( V_7 ) ;
if ( ! V_9 )
return - V_10 ;
V_31 = F_8 ( V_9 ,
V_32 , V_29 ) ;
if ( ! V_31 )
return - V_35 ;
V_34 = F_9 ( V_31 ) ;
F_7 ( V_2 , 0 , V_29 , false ) ;
F_18 ( V_34 , V_41 ) ;
F_19 ( V_31 , V_4 ) ;
return 0 ;
}
static struct V_43 F_20 ( void )
{
struct V_43 V_44 ;
memset ( & V_44 , 0 , sizeof( struct V_43 ) ) ;
V_44 . V_45 = F_1 ;
V_44 . V_46 = F_4 ;
return V_44 ;
}
static struct V_43 F_21 ( void )
{
struct V_43 V_44 ;
memset ( & V_44 , 0 , sizeof( V_44 ) ) ;
V_44 . V_45 = F_1 ;
V_44 . V_46 = F_4 ;
V_44 . V_47 = F_12 ;
V_44 . V_48 = F_15 ;
V_44 . V_49 = F_17 ;
return V_44 ;
}
static int F_22 ( int V_50 )
{
int V_51 ;
for ( V_51 = 0 ; V_51 < F_23 ( V_52 ) ; V_51 ++ ) {
if ( V_52 [ V_51 ] . V_53 == V_50 )
return V_51 ;
}
return - V_35 ;
}
int F_24 ( struct V_54 * V_54 )
{
void T_2 * V_55 ;
struct V_6 * V_7 = & V_54 -> V_7 ;
struct V_8 * V_9 = F_3 ( V_7 ) ;
struct V_43 V_44 ;
int V_56 = V_9 -> V_56 ;
int V_40 , V_36 ;
F_25 ( & V_54 -> V_7 , true ) ;
F_26 ( & V_54 -> V_7 , true ) ;
V_55 = F_27 ( V_54 -> V_57 , 4 ) ;
if ( V_55 == NULL ) {
F_28 ( V_9 -> V_2 , L_1 ) ;
return - V_58 ;
}
V_36 = F_22 ( V_54 -> V_57 -> V_1 ) ;
if ( V_36 < 0 )
return - V_35 ;
V_44 = V_52 [ V_36 ] . V_44 () ;
V_40 = V_52 [ V_36 ] . F_29 ( V_9 -> V_2 , V_55 , V_56 ,
V_54 -> V_59 , V_44 , & V_54 -> V_15 ) ;
if ( V_40 < 0 )
return V_40 ;
F_5 ( V_54 -> V_15 , false ) ;
F_30 ( V_9 -> V_2 , L_2 , V_40 ) ;
return V_40 ;
}
int F_31 ( struct V_54 * V_54 )
{
struct V_6 * V_7 = & V_54 -> V_7 ;
struct V_8 * V_9 = F_3 ( V_7 ) ;
struct V_15 * V_16 = V_54 -> V_15 ;
int V_36 ;
F_26 ( & V_54 -> V_7 , false ) ;
V_36 = F_22 ( V_54 -> V_57 -> V_1 ) ;
if ( V_36 < 0 )
return - V_60 ;
V_52 [ V_36 ] . V_49 ( V_9 -> V_2 , V_16 ) ;
if ( V_16 -> V_61 -> V_62 . V_63 )
F_32 ( V_16 -> V_61 -> V_62 . V_63 ) ;
return 0 ;
}
int F_33 ( struct V_54 * V_54 )
{
struct V_15 * V_16 = V_54 -> V_15 ;
int V_40 ;
if ( ! V_54 -> V_7 . V_64 )
return 0 ;
V_40 = F_34 ( V_16 -> V_61 ) ;
if ( V_40 < 0 )
return V_40 ;
F_26 ( & V_54 -> V_7 , false ) ;
F_25 ( & V_54 -> V_7 , false ) ;
return 0 ;
}
int F_35 ( struct V_54 * V_54 )
{
struct V_15 * V_16 = V_54 -> V_15 ;
int V_40 ;
if ( ! V_54 -> V_7 . V_64 )
return 0 ;
F_25 ( & V_54 -> V_7 , true ) ;
F_26 ( & V_54 -> V_7 , true ) ;
V_40 = F_36 ( V_16 -> V_61 ) ;
if ( V_40 < 0 )
return V_40 ;
F_5 ( V_54 -> V_15 , false ) ;
return V_40 ;
}
enum V_65 F_37 ( int V_66 )
{
switch ( V_66 ) {
case 8 :
return V_67 ;
case 16 :
return V_68 ;
case 24 :
return V_69 ;
case 32 :
return V_70 ;
default:
return V_71 ;
}
}
static void F_38 ( struct V_15 * V_16 ,
struct V_72 * V_73 ,
struct V_74 * V_75 )
{
struct V_76 * V_37 = & V_73 -> V_77 [ 0 ] ;
V_75 -> V_78 . V_79 = ( V_80 ) V_37 -> V_81 ;
V_75 -> V_78 . V_82 = V_37 -> V_82 ;
V_75 -> V_78 . V_83 = V_37 -> V_83 ;
V_75 -> V_78 . V_84 = V_37 -> V_84 ;
V_75 -> V_78 . V_85 = V_37 -> V_85 ;
F_30 ( V_16 -> V_2 , L_3 ,
V_37 -> V_83 , V_37 -> V_84 ,
V_37 -> V_85 ) ;
V_75 -> V_78 . V_86 = V_37 -> V_87 ;
V_75 -> V_78 . V_88 = V_37 -> V_89 ;
V_75 -> V_90 = V_73 -> V_91 ;
V_75 -> V_92 = V_73 -> V_92 ;
V_75 -> V_93 = V_73 -> V_93 ;
V_75 -> V_94 = V_73 -> V_95 ;
}
static void F_39 ( struct V_72 * V_73 ,
struct V_96 * V_97 )
{
if ( V_73 -> V_98 . V_99 == 0 )
return;
memcpy ( V_97 -> V_100 . V_101 ,
V_73 -> V_98 . V_102 ,
V_73 -> V_98 . V_99 ) ;
V_97 -> V_100 . V_103 =
( V_73 -> V_98 . V_99 ) / 4 ;
}
static V_28 F_40 ( struct V_15 * V_16 ,
struct V_72 * V_73 )
{
union V_104 V_105 = { 0 } ;
union V_106 V_107 = { 0 } ;
struct V_108 * V_66 = V_73 -> V_109 -> V_110 ;
switch ( V_73 -> V_111 ) {
case V_112 :
V_105 . V_113 . V_114 =
( V_115 == V_73 -> V_116 ) ?
V_117 :
V_118 ;
V_105 . V_113 . V_119 = V_66 -> V_120 +
( V_73 -> V_121 << 3 ) ;
break;
case V_122 :
V_105 . V_113 . V_114 =
( V_115 == V_73 -> V_116 ) ?
V_117 :
V_118 ;
V_107 . V_123 . V_124 = V_73 -> V_125 ;
V_107 . V_123 . V_126 = V_73 -> V_121 ;
V_105 . V_113 . V_119 = V_107 . V_127 ;
break;
case V_128 :
V_105 . V_113 . V_114 = V_129 ;
V_105 . V_113 . V_119 = V_73 -> V_121 +
( V_73 -> V_125 ) ;
break;
case V_130 :
V_105 . V_113 . V_114 =
( V_115 == V_73 -> V_116 ) ?
V_131 :
V_132 ;
V_105 . V_113 . V_119 = V_66 -> V_133 ;
break;
case V_134 :
V_105 . V_113 . V_114 =
( V_115 == V_73 -> V_116 ) ?
V_135 :
V_136 ;
V_105 . V_113 . V_119 = V_66 -> V_120 ;
break;
default:
V_105 . V_127 = 0xFFFFFFFF ;
break;
}
return V_105 . V_127 ;
}
static void F_41 ( struct V_15 * V_16 ,
struct V_72 * V_73 ,
struct V_96 * V_97 )
{
V_97 -> V_100 . V_105 = F_40 ( V_16 , V_73 ) ;
if ( V_97 -> V_100 . V_105 == V_137 ) {
V_97 -> V_138 = 0 ;
return;
}
if ( V_115 == V_73 -> V_116 )
V_97 -> V_100 . V_139 = 2 * V_73 -> V_93 ;
else
V_97 -> V_100 . V_139 = 2 * V_73 -> V_92 ;
V_97 -> V_138 = 0 ;
V_97 -> V_100 . V_103 = 0 ;
F_39 ( V_73 , V_97 ) ;
}
int F_42 ( struct V_15 * V_16 , struct V_72 * V_73 )
{
struct V_140 * V_141 ;
struct V_142 V_143 ;
struct V_20 V_21 = { 0 } ;
int V_144 = 0 ;
if ( V_73 -> V_98 . V_99 == sizeof( V_143 ) )
return 0 ;
V_21 . V_24 = V_145 ;
V_21 . V_26 = sizeof( struct V_140 ) +
V_73 -> V_98 . V_99 ;
V_141 = F_43 ( V_21 . V_26 , V_146 ) ;
if ( V_141 == NULL )
return - V_147 ;
V_141 -> V_105 = F_40 ( V_16 , V_73 ) ;
V_141 -> V_103 = sizeof( V_143 ) / 4 ;
memcpy ( V_141 -> V_101 , V_73 -> V_98 . V_102 ,
V_73 -> V_98 . V_99 ) ;
V_144 = F_6 ( & V_16 -> V_27 , & V_21 , ( V_28 * ) V_141 ) ;
F_44 ( V_141 ) ;
return V_144 ;
}
static void F_45 ( struct V_15 * V_16 ,
struct V_72 * V_73 ,
struct V_148 * V_149 )
{
struct V_76 * V_37 = & V_73 -> V_149 [ 0 ] ;
V_149 -> V_79 = ( V_80 ) V_37 -> V_81 ;
V_149 -> V_82 = V_37 -> V_82 ;
V_149 -> V_83 = V_37 -> V_83 ;
V_149 -> V_84 = V_37 -> V_84 ;
V_149 -> V_85 = V_37 -> V_85 ;
V_149 -> V_86 = V_37 -> V_87 ;
V_149 -> V_88 = V_37 -> V_89 ;
V_149 -> V_150 = V_37 -> V_150 ;
F_30 ( V_16 -> V_2 , L_4 ,
V_149 -> V_79 , V_37 -> V_82 , V_37 -> V_83 ) ;
}
static void F_46 ( struct V_15 * V_16 ,
struct V_72 * V_73 ,
struct V_151 * V_152 )
{
struct V_76 * V_153 = & V_73 -> V_149 [ 0 ] ;
F_38 ( V_16 , V_73 ,
(struct V_74 * ) V_152 ) ;
V_152 -> V_154 = V_153 -> V_82 ;
}
static void F_47 ( struct V_15 * V_16 ,
struct V_72 * V_73 ,
struct V_155 * V_156 )
{
struct V_76 * V_153 = & V_73 -> V_149 [ 0 ] ;
int V_51 = 0 ;
F_38 ( V_16 , V_73 ,
(struct V_74 * ) V_156 ) ;
V_156 -> V_157 = V_153 -> V_85 ;
V_156 -> V_158 = 0x0 ;
for ( V_51 = 0 ; V_51 < V_159 ; V_51 ++ )
V_156 -> V_160 [ V_51 ] = 0xDEADBEEF ;
}
static void F_48 ( struct V_15 * V_16 ,
struct V_72 * V_73 ,
struct V_96 * V_97 )
{
struct V_148 * V_149 = & V_97 -> V_149 ;
struct V_74 * V_75 = (struct V_74 * ) V_97 ;
F_38 ( V_16 , V_73 , V_75 ) ;
F_45 ( V_16 , V_73 , V_149 ) ;
F_41 ( V_16 , V_73 , V_97 ) ;
}
static void F_49 ( struct V_15 * V_16 ,
struct V_72 * V_73 ,
struct V_161 * V_162 )
{
struct V_74 * V_75 = (struct V_74 * ) V_162 ;
F_38 ( V_16 , V_73 , V_75 ) ;
if ( V_73 -> V_98 . V_99 == 0 )
return;
memcpy ( V_162 -> V_66 ,
V_73 -> V_98 . V_102 ,
V_73 -> V_98 . V_99 ) ;
}
static void F_50 ( struct V_15 * V_16 ,
struct V_72 * V_73 ,
struct V_163 * V_164 )
{
struct V_148 * V_149 = & V_164 -> V_149 ;
struct V_74 * V_75 =
(struct V_74 * ) V_164 ;
F_38 ( V_16 , V_73 , V_75 ) ;
F_45 ( V_16 , V_73 , V_149 ) ;
}
static T_3 F_51 ( struct V_15 * V_16 ,
struct V_72 * V_73 )
{
T_3 V_165 ;
switch ( V_73 -> V_166 ) {
case V_167 :
V_165 = sizeof( struct V_96 ) ;
V_165 += V_73 -> V_98 . V_99 ;
return V_165 ;
case V_168 :
return sizeof( struct V_151 ) ;
case V_169 :
return sizeof( struct V_155 ) ;
case V_170 :
V_165 = sizeof( struct V_74 ) ;
V_165 += V_73 -> V_98 . V_99 ;
return V_165 ;
case V_171 :
return sizeof( struct V_163 ) ;
default:
return sizeof( struct V_74 ) ;
}
return 0 ;
}
static int F_52 ( struct V_15 * V_16 ,
struct V_72 * V_172 ,
T_3 * V_173 ,
void * * V_174 )
{
T_3 V_165 ;
V_165 = F_51 ( V_16 , V_172 ) ;
* V_174 = F_43 ( V_165 , V_146 ) ;
if ( NULL == * V_174 )
return - V_147 ;
* V_173 = V_165 ;
switch ( V_172 -> V_166 ) {
case V_167 :
F_48 ( V_16 , V_172 , * V_174 ) ;
break;
case V_168 :
F_46 ( V_16 , V_172 , * V_174 ) ;
break;
case V_169 :
F_47 ( V_16 , V_172 , * V_174 ) ;
break;
case V_170 :
F_49 ( V_16 , V_172 , * V_174 ) ;
break;
case V_171 :
F_50 ( V_16 , V_172 , * V_174 ) ;
break;
default:
F_38 ( V_16 , V_172 , * V_174 ) ;
break;
}
F_30 ( V_16 -> V_2 , L_5 ,
V_172 -> V_53 . V_175 , V_165 ) ;
F_53 ( L_6 , V_176 , 8 , 4 ,
* V_174 , V_165 , false ) ;
return 0 ;
}
static int F_54 ( struct V_177 * V_178 ,
struct V_179 V_53 , int V_180 )
{
int V_51 ;
for ( V_51 = 0 ; V_51 < V_180 ; V_51 ++ ) {
if ( V_178 [ V_51 ] . V_53 . V_175 == V_53 . V_175 &&
V_178 [ V_51 ] . V_53 . V_181 == V_53 . V_181 )
return V_51 ;
}
return - V_35 ;
}
static int F_55 ( struct V_177 * V_178 ,
struct V_72 * V_182 , int V_180 )
{
int V_51 ;
struct V_179 V_53 = V_182 -> V_53 ;
for ( V_51 = 0 ; V_51 < V_180 ; V_51 ++ ) {
if ( V_178 [ V_51 ] . V_183 ) {
if ( ! V_178 [ V_51 ] . V_184 &&
V_178 [ V_51 ] . V_185 == V_186 ) {
V_178 [ V_51 ] . V_184 = true ;
V_178 [ V_51 ] . V_53 . V_175 = V_53 . V_175 ;
V_178 [ V_51 ] . V_53 . V_181 = V_53 . V_181 ;
V_178 [ V_51 ] . V_187 = V_182 ;
return V_51 ;
}
} else {
if ( V_178 [ V_51 ] . V_53 . V_175 == V_53 . V_175 &&
V_178 [ V_51 ] . V_53 . V_181 == V_53 . V_181 &&
V_178 [ V_51 ] . V_185 == V_186 ) {
V_178 [ V_51 ] . V_187 = V_182 ;
return V_51 ;
}
}
}
return - V_35 ;
}
static void F_56 ( struct V_177 * V_178 , int V_188 )
{
if ( V_178 [ V_188 ] . V_183 ) {
V_178 [ V_188 ] . V_184 = false ;
V_178 [ V_188 ] . V_53 . V_175 = 0 ;
V_178 [ V_188 ] . V_53 . V_181 = 0 ;
}
V_178 [ V_188 ] . V_185 = V_186 ;
V_178 [ V_188 ] . V_187 = NULL ;
}
static void F_57 ( struct V_177 * V_178 , int V_180 ,
struct V_72 * V_189 )
{
int V_51 ;
bool V_190 = false ;
for ( V_51 = 0 ; V_51 < V_180 ; V_51 ++ ) {
if ( V_178 [ V_51 ] . V_185 == V_186 )
continue;
V_190 = true ;
break;
}
if ( ! V_190 )
V_189 -> V_191 = V_192 ;
return;
}
int F_58 ( struct V_15 * V_16 ,
struct V_72 * V_73 )
{
T_3 V_173 = 0 ;
void * V_174 = NULL ;
int V_40 ;
struct V_193 V_21 ;
F_30 ( V_16 -> V_2 , L_7 , V_194 ,
V_73 -> V_53 . V_175 , V_73 -> V_53 . V_181 ) ;
if ( V_73 -> V_109 -> V_195 != V_196 ) {
F_28 ( V_16 -> V_2 , L_8 ,
V_73 -> V_109 -> V_195 , V_73 -> V_109 -> V_197 ) ;
return - V_60 ;
}
V_40 = F_52 ( V_16 , V_73 ,
& V_173 , & V_174 ) ;
if ( V_40 < 0 ) {
F_28 ( V_16 -> V_2 , L_9 , V_40 ) ;
return V_40 ;
}
V_21 . V_175 = V_73 -> V_53 . V_175 ;
V_21 . V_181 = V_73 -> V_53 . V_181 ;
V_21 . V_198 = V_73 -> V_109 -> V_197 ;
V_21 . V_26 = V_173 ;
V_21 . V_199 = V_73 -> V_199 ;
V_40 = F_59 ( & V_16 -> V_27 , & V_21 , V_174 ) ;
if ( V_40 < 0 ) {
F_28 ( V_16 -> V_2 , L_10 , V_40 ) ;
F_44 ( V_174 ) ;
return V_40 ;
}
V_73 -> V_191 = V_200 ;
F_44 ( V_174 ) ;
return V_40 ;
}
static void F_60 ( struct V_15 * V_16 , struct V_72
* V_201 , struct V_72 * V_202 )
{
F_30 ( V_16 -> V_2 , L_11 ,
V_194 , V_201 -> V_53 . V_175 , V_201 -> V_53 . V_181 ) ;
F_30 ( V_16 -> V_2 , L_12 , V_194 ,
V_202 -> V_53 . V_175 , V_202 -> V_53 . V_181 ) ;
F_30 ( V_16 -> V_2 , L_13 ,
V_201 -> V_191 , V_202 -> V_191 ) ;
}
int F_61 ( struct V_15 * V_16 ,
struct V_72 * V_203 ,
struct V_72 * V_204 )
{
int V_40 ;
struct V_205 V_21 ;
struct V_179 V_206 = V_203 -> V_53 ;
struct V_179 V_207 = V_204 -> V_53 ;
int V_208 = V_204 -> V_209 ;
int V_210 = V_203 -> V_211 ;
int V_212 , V_213 , V_214 , V_215 ;
F_60 ( V_16 , V_203 , V_204 ) ;
V_212 = F_54 ( V_203 -> V_216 , V_207 , V_210 ) ;
if ( V_212 < 0 )
return 0 ;
V_21 . V_217 = V_212 ;
V_213 = F_54 ( V_204 -> V_218 , V_206 , V_208 ) ;
if ( V_213 < 0 )
return 0 ;
V_21 . V_219 = V_213 ;
V_214 = V_203 -> V_216 [ V_212 ] . V_185 ;
V_215 = V_204 -> V_218 [ V_213 ] . V_185 ;
if ( V_214 != V_220 ||
V_215 != V_220 )
return 0 ;
V_21 . V_175 = V_203 -> V_53 . V_175 ;
V_21 . V_181 = V_203 -> V_53 . V_181 ;
V_21 . V_221 = V_204 -> V_53 . V_175 ;
V_21 . V_222 = V_204 -> V_53 . V_181 ;
V_21 . V_223 = false ;
V_40 = F_62 ( & V_16 -> V_27 , & V_21 ) ;
if ( ! V_40 ) {
F_56 ( V_203 -> V_216 , V_212 ) ;
F_56 ( V_204 -> V_218 , V_213 ) ;
F_57 ( V_203 -> V_216 , V_210 , V_203 ) ;
}
return V_40 ;
}
int F_63 ( struct V_15 * V_16 ,
struct V_72 * V_203 ,
struct V_72 * V_204 )
{
int V_40 ;
struct V_205 V_21 ;
int V_208 = V_204 -> V_209 ;
int V_210 = V_203 -> V_211 ;
int V_212 , V_213 ;
F_60 ( V_16 , V_203 , V_204 ) ;
if ( V_203 -> V_191 < V_200 ||
V_204 -> V_191 < V_200 )
return 0 ;
V_212 = F_55 ( V_203 -> V_216 , V_204 , V_210 ) ;
if ( V_212 < 0 )
return - V_35 ;
V_21 . V_217 = V_212 ;
V_213 = F_55 ( V_204 -> V_218 , V_203 , V_208 ) ;
if ( V_213 < 0 ) {
F_56 ( V_203 -> V_216 , V_212 ) ;
return - V_35 ;
}
V_21 . V_219 = V_213 ;
F_30 ( V_16 -> V_2 , L_14 ,
V_21 . V_217 , V_21 . V_219 ) ;
V_21 . V_175 = V_203 -> V_53 . V_175 ;
V_21 . V_181 = V_203 -> V_53 . V_181 ;
V_21 . V_221 = V_204 -> V_53 . V_175 ;
V_21 . V_222 = V_204 -> V_53 . V_181 ;
V_21 . V_223 = true ;
V_40 = F_62 ( & V_16 -> V_27 , & V_21 ) ;
if ( ! V_40 ) {
V_203 -> V_191 = V_224 ;
V_203 -> V_216 [ V_212 ] . V_185 = V_220 ;
V_204 -> V_218 [ V_213 ] . V_185 = V_220 ;
} else {
F_56 ( V_203 -> V_216 , V_212 ) ;
F_56 ( V_204 -> V_218 , V_213 ) ;
}
return V_40 ;
}
static int F_64 ( struct V_15 * V_16 , struct V_225 * V_109 ,
enum V_226 V_195 )
{
F_30 ( V_16 -> V_2 , L_15 , V_194 , V_195 ) ;
return F_65 ( & V_16 -> V_27 , V_109 -> V_197 , V_195 ) ;
}
int F_66 ( struct V_15 * V_16 , struct V_225 * V_109 )
{
int V_40 ;
F_30 ( V_16 -> V_2 , L_16 , V_194 , V_109 -> V_197 ) ;
V_40 = F_67 ( & V_16 -> V_27 , V_109 -> V_227 ,
V_109 -> V_228 , V_109 -> V_197 ) ;
if ( V_40 < 0 ) {
F_28 ( V_16 -> V_2 , L_17 ) ;
return V_40 ;
}
V_109 -> V_195 = V_196 ;
return 0 ;
}
int F_68 ( struct V_15 * V_16 , struct V_225 * V_109 )
{
int V_40 ;
F_30 ( V_16 -> V_2 , L_18 , V_194 , V_109 -> V_197 ) ;
if ( V_109 -> V_195 > V_229 ) {
V_40 = F_64 ( V_16 , V_109 , V_230 ) ;
if ( V_40 < 0 ) {
F_28 ( V_16 -> V_2 , L_19 ) ;
return V_40 ;
}
V_109 -> V_195 = V_231 ;
}
if ( V_109 -> V_195 < V_196 )
return 0 ;
V_40 = F_69 ( & V_16 -> V_27 , V_109 -> V_197 ) ;
if ( V_40 < 0 ) {
F_28 ( V_16 -> V_2 , L_20 ) ;
return V_40 ;
}
V_109 -> V_195 = V_232 ;
return V_40 ;
}
int F_70 ( struct V_15 * V_16 , struct V_225 * V_109 )
{
int V_40 ;
F_30 ( V_16 -> V_2 , L_18 , V_194 , V_109 -> V_197 ) ;
if ( V_109 -> V_195 < V_196 )
return 0 ;
V_40 = F_64 ( V_16 , V_109 , V_230 ) ;
if ( V_40 < 0 ) {
F_28 ( V_16 -> V_2 , L_21 ) ;
return V_40 ;
}
V_109 -> V_195 = V_231 ;
V_40 = F_64 ( V_16 , V_109 , V_233 ) ;
if ( V_40 < 0 ) {
F_28 ( V_16 -> V_2 , L_22 ) ;
return V_40 ;
}
V_109 -> V_195 = V_229 ;
return 0 ;
}
int F_71 ( struct V_15 * V_16 , struct V_225 * V_109 )
{
int V_40 ;
F_30 ( V_16 -> V_2 , L_23 , V_194 , V_109 -> V_197 ) ;
if ( V_109 -> V_195 < V_231 )
return 0 ;
V_40 = F_64 ( V_16 , V_109 , V_230 ) ;
if ( V_40 < 0 ) {
F_30 ( V_16 -> V_2 , L_24 ) ;
return V_40 ;
}
V_109 -> V_195 = V_231 ;
return 0 ;
}
int F_72 ( struct V_15 * V_16 , struct V_225 * V_109 )
{
int V_40 ;
if ( V_109 -> V_195 < V_231 )
return 0 ;
V_40 = F_64 ( V_16 , V_109 , V_234 ) ;
if ( V_40 < 0 ) {
F_30 ( V_16 -> V_2 , L_25 , V_40 ) ;
return V_40 ;
}
V_109 -> V_195 = V_235 ;
return 0 ;
}
int F_73 ( struct V_15 * V_16 , V_28 * V_66 , int V_5 ,
V_28 V_236 , struct V_72 * V_189 )
{
struct V_20 V_21 ;
V_21 . V_175 = V_189 -> V_53 . V_175 ;
V_21 . V_181 = V_189 -> V_53 . V_181 ;
V_21 . V_26 = V_5 ;
V_21 . V_24 = V_236 ;
return F_6 ( & V_16 -> V_27 , & V_21 , V_66 ) ;
}
int F_74 ( struct V_15 * V_16 , V_28 * V_66 , int V_5 ,
V_28 V_236 , struct V_72 * V_189 )
{
struct V_20 V_21 ;
V_21 . V_175 = V_189 -> V_53 . V_175 ;
V_21 . V_181 = V_189 -> V_53 . V_181 ;
V_21 . V_26 = V_5 ;
V_21 . V_24 = V_236 ;
return F_75 ( & V_16 -> V_27 , & V_21 , V_66 ) ;
}
