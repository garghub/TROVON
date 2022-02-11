static struct V_1 *
F_1 ( struct V_2 * V_3 ,
struct V_4 * V_5 ,
T_1 V_6 , T_1 V_7 )
{
struct V_8 * V_9 = V_3 -> V_10 ;
struct V_11 V_12 = { 0 } ;
struct V_13 V_14 = {
. V_6 = V_6 ,
. V_7 = V_7 ,
. V_15 = 0 ,
} ;
struct V_16 * V_17 = NULL ;
struct V_1 * V_18 ;
bool V_19 = false ;
if ( V_6 & V_20 ) {
V_12 . type = V_21 ;
V_12 . V_22 = V_3 -> V_23 . V_24 . V_22 . V_25 ;
} else if ( V_6 & V_26 ) {
V_17 = F_2 ( V_9 , true ) ;
if ( F_3 ( V_17 ) )
return F_4 ( V_17 ) ;
V_12 . type = V_27 ;
V_12 . V_17 = V_17 ;
}
if ( F_5 ( V_3 -> V_23 . V_28 . V_25 ) ) {
V_3 -> V_23 . V_28 . V_25 =
F_6 ( V_3 -> V_23 . V_29 ,
V_30 ,
V_31 ,
V_32 ,
0 , 0 ) ;
if ( F_3 ( V_3 -> V_23 . V_28 . V_25 ) ) {
F_7 ( V_3 -> V_33 ,
L_1 ) ;
V_18 = F_4 ( V_3 -> V_23 . V_28 . V_25 ) ;
goto V_34;
}
V_19 = true ;
}
V_5 -> V_35 = V_36 ;
V_18 = F_8 ( V_3 -> V_23 . V_28 . V_25 , V_5 , & V_14 , & V_12 , 1 ) ;
if ( F_3 ( V_18 ) )
goto V_37;
return V_18 ;
V_37:
if ( V_19 ) {
F_9 ( V_3 -> V_23 . V_28 . V_25 ) ;
V_3 -> V_23 . V_28 . V_25 = NULL ;
}
V_34:
F_10 ( V_9 , V_17 ) ;
return V_18 ;
}
static struct V_1 *
F_11 ( struct V_2 * V_3 ,
struct V_4 * V_5 ,
struct V_38 * V_39 )
{
struct V_40 * V_41 = V_3 -> V_10 -> V_3 . V_42 ;
int V_43 ;
V_43 = F_12 ( V_41 , V_39 ) ;
if ( V_43 )
return F_13 ( V_43 ) ;
return F_14 ( V_41 , V_5 , V_39 ) ;
}
static void F_15 ( struct V_2 * V_3 ,
struct V_44 * V_45 ) {
struct V_46 * V_47 = V_45 -> V_48 . V_47 ;
F_16 ( & V_45 -> V_48 ) ;
if ( F_17 ( V_47 ) ) {
struct V_49 * V_50 ;
V_50 = F_18 ( V_47 , struct V_49 , V_51 ) ;
if ( V_50 -> V_52 ) {
F_19 ( V_3 -> V_10 , V_50 -> V_15 ) ;
F_20 ( V_50 -> V_52 ) ;
}
F_21 ( & V_50 -> V_53 ) ;
F_22 ( V_50 ) ;
}
}
static void F_23 ( struct V_2 * V_3 ,
struct V_44 * V_45 )
{
struct V_40 * V_41 = V_3 -> V_10 -> V_3 . V_42 ;
struct V_16 * V_17 = NULL ;
if ( ! F_3 ( V_45 -> V_18 ) ) {
V_17 = F_24 ( V_45 -> V_18 ) ;
F_25 ( V_45 -> V_18 ) ;
F_10 ( V_3 -> V_10 , V_17 ) ;
}
if ( V_41 && V_41 -> V_54 == V_55 ) {
F_26 ( V_41 , V_45 -> V_39 ) ;
if ( V_45 -> V_39 -> V_6 & V_56 )
F_15 ( V_3 , V_45 ) ;
}
if ( ! F_27 ( V_3 ) && ( V_3 -> V_23 . V_28 . V_25 ) ) {
F_9 ( V_3 -> V_23 . V_28 . V_25 ) ;
V_3 -> V_23 . V_28 . V_25 = NULL ;
}
}
static void F_28 ( struct V_4 * V_5 ,
struct V_57 * V_58 )
{
void * V_59 = F_29 ( V_60 , V_5 -> V_61 ,
V_62 ) ;
void * V_63 = F_29 ( V_60 , V_5 -> V_64 ,
V_62 ) ;
void * V_65 = F_29 ( V_60 , V_5 -> V_61 ,
V_66 ) ;
void * V_67 = F_29 ( V_60 , V_5 -> V_64 ,
V_66 ) ;
F_30 ( V_68 , V_59 , V_69 ) ;
F_31 ( V_68 , V_63 , V_69 , V_70 ) ;
if ( F_32 ( V_58 -> V_71 , V_72 ) ) {
struct V_73 * V_74 =
F_33 ( V_58 -> V_71 ,
V_72 ,
V_58 -> V_74 ) ;
struct V_73 * V_75 =
F_33 ( V_58 -> V_71 ,
V_72 ,
V_58 -> V_75 ) ;
F_31 ( V_76 , V_65 , V_77 ,
F_34 ( V_75 -> V_78 ) ) ;
F_31 ( V_76 , V_67 , V_77 ,
F_34 ( V_74 -> V_78 ) ) ;
}
}
static int F_35 ( struct V_2 * V_3 ,
struct V_4 * V_5 ,
struct V_57 * V_58 )
{
void * V_59 = F_29 ( V_60 , V_5 -> V_61 ,
V_62 ) ;
void * V_63 = F_29 ( V_60 , V_5 -> V_64 ,
V_62 ) ;
struct V_79 * V_80 =
F_33 ( V_58 -> V_71 ,
V_81 ,
V_58 -> V_74 ) ;
if ( F_32 ( V_58 -> V_71 , V_82 ) ) {
struct V_83 * V_74 =
F_33 ( V_58 -> V_71 ,
V_82 ,
V_58 -> V_74 ) ;
struct V_83 * V_75 =
F_33 ( V_58 -> V_71 ,
V_82 ,
V_58 -> V_75 ) ;
if ( F_36 ( & V_75 -> V_84 , 0xff , sizeof( V_75 -> V_84 ) ) )
goto V_85;
if ( F_37 ( V_3 , F_38 ( V_74 -> V_84 ) ) &&
F_39 ( V_3 -> V_10 , V_86 ) )
F_28 ( V_5 , V_58 ) ;
else {
F_40 ( V_3 -> V_33 ,
L_2 , F_38 ( V_74 -> V_84 ) ) ;
return - V_87 ;
}
F_31 ( V_68 , V_59 ,
V_88 , F_41 ( V_75 -> V_84 ) ) ;
F_31 ( V_68 , V_63 ,
V_88 , F_41 ( V_74 -> V_84 ) ) ;
F_31 ( V_68 , V_59 ,
V_89 , F_41 ( V_75 -> V_90 ) ) ;
F_31 ( V_68 , V_63 ,
V_89 , F_41 ( V_74 -> V_90 ) ) ;
} else {
V_85:
F_40 ( V_3 -> V_33 ,
L_3 ) ;
return - V_87 ;
}
if ( V_80 -> V_91 == V_92 ) {
struct V_93 * V_74 =
F_33 ( V_58 -> V_71 ,
V_94 ,
V_58 -> V_74 ) ;
struct V_93 * V_75 =
F_33 ( V_58 -> V_71 ,
V_94 ,
V_58 -> V_75 ) ;
F_31 ( V_68 , V_59 ,
V_95 . V_96 . V_97 ,
F_42 ( V_75 -> V_90 ) ) ;
F_31 ( V_68 , V_63 ,
V_95 . V_96 . V_97 ,
F_42 ( V_74 -> V_90 ) ) ;
F_31 ( V_68 , V_59 ,
V_98 . V_96 . V_97 ,
F_42 ( V_75 -> V_84 ) ) ;
F_31 ( V_68 , V_63 ,
V_98 . V_96 . V_97 ,
F_42 ( V_74 -> V_84 ) ) ;
F_30 ( V_68 , V_59 , V_99 ) ;
F_31 ( V_68 , V_63 , V_99 , V_100 ) ;
}
F_30 ( V_68 , V_59 , V_101 ) ;
F_30 ( V_68 , V_59 , V_102 ) ;
F_43 ( F_29 ( V_68 , V_63 ,
V_101 ) , V_3 -> V_33 -> V_103 ) ;
F_31 ( V_68 , V_59 , V_104 , 1 ) ;
F_31 ( V_68 , V_63 , V_104 , 0 ) ;
return 0 ;
}
static int F_44 ( struct V_2 * V_3 ,
struct V_4 * V_5 ,
struct V_57 * V_58 ,
T_2 * V_105 )
{
void * V_59 = F_29 ( V_60 , V_5 -> V_61 ,
V_62 ) ;
void * V_63 = F_29 ( V_60 , V_5 -> V_64 ,
V_62 ) ;
T_3 V_91 = 0 ;
T_2 V_106 = 0 ;
* V_105 = V_107 ;
if ( V_58 -> V_71 -> V_108 &
~ ( F_45 ( V_109 ) |
F_45 ( V_110 ) |
F_45 ( V_111 ) |
F_45 ( V_112 ) |
F_45 ( V_92 ) |
F_45 ( V_113 ) |
F_45 ( V_114 ) |
F_45 ( V_72 ) |
F_45 ( V_94 ) |
F_45 ( V_115 ) |
F_45 ( V_82 ) |
F_45 ( V_81 ) ) ) {
F_40 ( V_3 -> V_33 , L_4 ,
V_58 -> V_71 -> V_108 ) ;
return - V_87 ;
}
if ( ( F_32 ( V_58 -> V_71 ,
V_94 ) ||
F_32 ( V_58 -> V_71 , V_72 ) ||
F_32 ( V_58 -> V_71 , V_82 ) ) &&
F_32 ( V_58 -> V_71 , V_81 ) ) {
struct V_79 * V_74 =
F_33 ( V_58 -> V_71 ,
V_81 ,
V_58 -> V_74 ) ;
switch ( V_74 -> V_91 ) {
case V_92 :
if ( F_35 ( V_3 , V_5 , V_58 ) )
return - V_87 ;
break;
case V_113 :
F_40 ( V_3 -> V_33 ,
L_5 ) ;
default:
return - V_87 ;
}
V_59 = F_29 ( V_60 , V_5 -> V_61 ,
V_116 ) ;
V_63 = F_29 ( V_60 , V_5 -> V_64 ,
V_116 ) ;
}
if ( F_32 ( V_58 -> V_71 , V_109 ) ) {
struct V_79 * V_74 =
F_33 ( V_58 -> V_71 ,
V_109 ,
V_58 -> V_74 ) ;
struct V_79 * V_75 =
F_33 ( V_58 -> V_71 ,
V_109 ,
V_58 -> V_75 ) ;
V_91 = V_74 -> V_91 ;
if ( V_75 -> V_117 & V_118 ) {
F_31 ( V_68 , V_59 , V_104 , 1 ) ;
F_31 ( V_68 , V_63 , V_104 ,
V_74 -> V_117 & V_118 ) ;
if ( V_74 -> V_117 & V_118 )
* V_105 = V_119 ;
}
}
if ( F_32 ( V_58 -> V_71 , V_110 ) ) {
struct V_120 * V_74 =
F_33 ( V_58 -> V_71 ,
V_110 ,
V_58 -> V_74 ) ;
struct V_120 * V_75 =
F_33 ( V_58 -> V_71 ,
V_110 ,
V_58 -> V_75 ) ;
V_106 = V_74 -> V_106 ;
F_31 ( V_68 , V_59 , V_99 ,
F_41 ( V_75 -> V_121 ) ) ;
F_31 ( V_68 , V_63 , V_99 ,
F_41 ( V_74 -> V_121 ) ) ;
F_31 ( V_68 , V_59 , V_69 ,
V_75 -> V_106 ) ;
F_31 ( V_68 , V_63 , V_69 ,
V_74 -> V_106 ) ;
if ( V_75 -> V_106 )
* V_105 = V_119 ;
}
if ( F_32 ( V_58 -> V_71 , V_111 ) ) {
struct V_122 * V_74 =
F_33 ( V_58 -> V_71 ,
V_111 ,
V_58 -> V_74 ) ;
struct V_122 * V_75 =
F_33 ( V_58 -> V_71 ,
V_111 ,
V_58 -> V_75 ) ;
F_43 ( F_29 ( V_68 , V_59 ,
V_101 ) ,
V_75 -> V_84 ) ;
F_43 ( F_29 ( V_68 , V_63 ,
V_101 ) ,
V_74 -> V_84 ) ;
F_43 ( F_29 ( V_68 , V_59 ,
V_123 ) ,
V_75 -> V_90 ) ;
F_43 ( F_29 ( V_68 , V_63 ,
V_123 ) ,
V_74 -> V_90 ) ;
}
if ( F_32 ( V_58 -> V_71 , V_112 ) ) {
struct V_124 * V_74 =
F_33 ( V_58 -> V_71 ,
V_112 ,
V_58 -> V_74 ) ;
struct V_124 * V_75 =
F_33 ( V_58 -> V_71 ,
V_112 ,
V_58 -> V_75 ) ;
if ( V_75 -> V_125 || V_75 -> V_126 ) {
F_31 ( V_68 , V_59 , V_127 , 1 ) ;
F_31 ( V_68 , V_63 , V_127 , 1 ) ;
F_31 ( V_68 , V_59 , V_128 , V_75 -> V_125 ) ;
F_31 ( V_68 , V_63 , V_128 , V_74 -> V_125 ) ;
F_31 ( V_68 , V_59 , V_129 , V_75 -> V_126 ) ;
F_31 ( V_68 , V_63 , V_129 , V_74 -> V_126 ) ;
}
}
if ( V_91 == V_92 ) {
struct V_93 * V_74 =
F_33 ( V_58 -> V_71 ,
V_92 ,
V_58 -> V_74 ) ;
struct V_93 * V_75 =
F_33 ( V_58 -> V_71 ,
V_92 ,
V_58 -> V_75 ) ;
memcpy ( F_29 ( V_68 , V_59 ,
V_95 . V_96 . V_97 ) ,
& V_75 -> V_90 , sizeof( V_75 -> V_90 ) ) ;
memcpy ( F_29 ( V_68 , V_63 ,
V_95 . V_96 . V_97 ) ,
& V_74 -> V_90 , sizeof( V_74 -> V_90 ) ) ;
memcpy ( F_29 ( V_68 , V_59 ,
V_98 . V_96 . V_97 ) ,
& V_75 -> V_84 , sizeof( V_75 -> V_84 ) ) ;
memcpy ( F_29 ( V_68 , V_63 ,
V_98 . V_96 . V_97 ) ,
& V_74 -> V_84 , sizeof( V_74 -> V_84 ) ) ;
if ( V_75 -> V_90 || V_75 -> V_84 )
* V_105 = V_119 ;
}
if ( V_91 == V_113 ) {
struct V_130 * V_74 =
F_33 ( V_58 -> V_71 ,
V_113 ,
V_58 -> V_74 ) ;
struct V_130 * V_75 =
F_33 ( V_58 -> V_71 ,
V_113 ,
V_58 -> V_75 ) ;
memcpy ( F_29 ( V_68 , V_59 ,
V_95 . V_131 . V_132 ) ,
& V_75 -> V_90 , sizeof( V_75 -> V_90 ) ) ;
memcpy ( F_29 ( V_68 , V_63 ,
V_95 . V_131 . V_132 ) ,
& V_74 -> V_90 , sizeof( V_74 -> V_90 ) ) ;
memcpy ( F_29 ( V_68 , V_59 ,
V_98 . V_131 . V_132 ) ,
& V_75 -> V_84 , sizeof( V_75 -> V_84 ) ) ;
memcpy ( F_29 ( V_68 , V_63 ,
V_98 . V_131 . V_132 ) ,
& V_74 -> V_84 , sizeof( V_74 -> V_84 ) ) ;
if ( F_46 ( & V_75 -> V_90 ) != V_133 ||
F_46 ( & V_75 -> V_84 ) != V_133 )
* V_105 = V_119 ;
}
if ( F_32 ( V_58 -> V_71 , V_114 ) ) {
struct V_83 * V_74 =
F_33 ( V_58 -> V_71 ,
V_114 ,
V_58 -> V_74 ) ;
struct V_83 * V_75 =
F_33 ( V_58 -> V_71 ,
V_114 ,
V_58 -> V_75 ) ;
switch ( V_106 ) {
case V_134 :
F_31 ( V_68 , V_59 ,
V_135 , F_41 ( V_75 -> V_90 ) ) ;
F_31 ( V_68 , V_63 ,
V_135 , F_41 ( V_74 -> V_90 ) ) ;
F_31 ( V_68 , V_59 ,
V_136 , F_41 ( V_75 -> V_84 ) ) ;
F_31 ( V_68 , V_63 ,
V_136 , F_41 ( V_74 -> V_84 ) ) ;
break;
case V_70 :
F_31 ( V_68 , V_59 ,
V_89 , F_41 ( V_75 -> V_90 ) ) ;
F_31 ( V_68 , V_63 ,
V_89 , F_41 ( V_74 -> V_90 ) ) ;
F_31 ( V_68 , V_59 ,
V_88 , F_41 ( V_75 -> V_84 ) ) ;
F_31 ( V_68 , V_63 ,
V_88 , F_41 ( V_74 -> V_84 ) ) ;
break;
default:
F_7 ( V_3 -> V_33 ,
L_6 ) ;
return - V_137 ;
}
if ( V_75 -> V_90 || V_75 -> V_84 )
* V_105 = V_138 ;
}
return 0 ;
}
static int F_47 ( struct V_2 * V_3 ,
struct V_4 * V_5 ,
struct V_57 * V_58 )
{
struct V_8 * V_9 = V_3 -> V_10 ;
struct V_40 * V_41 = V_9 -> V_3 . V_42 ;
struct V_139 * V_140 = V_3 -> V_141 ;
T_2 V_105 ;
int V_43 ;
V_43 = F_44 ( V_3 , V_5 , V_58 , & V_105 ) ;
if ( ! V_43 && V_41 -> V_54 == V_55 &&
V_140 -> V_142 != V_143 ) {
if ( V_105 > V_41 -> V_144 . V_145 ) {
F_40 ( V_3 -> V_33 ,
L_7 ,
V_105 , V_41 -> V_144 . V_145 ) ;
return - V_87 ;
}
}
return V_43 ;
}
static int F_48 ( struct V_2 * V_3 , struct V_146 * V_147 ,
T_1 * V_6 , T_1 * V_7 )
{
const struct V_148 * V_149 ;
F_49 ( V_150 ) ;
if ( F_50 ( V_147 ) )
return - V_137 ;
* V_7 = V_151 ;
* V_6 = 0 ;
F_51 ( V_147 , & V_150 ) ;
F_52 (a, &actions, list) {
if ( * V_6 )
return - V_137 ;
if ( F_53 ( V_149 ) ) {
* V_6 |= V_152 ;
if ( F_54 ( V_3 -> V_10 ,
V_153 . V_154 ) )
* V_6 |= V_26 ;
continue;
}
if ( F_55 ( V_149 ) ) {
T_1 V_155 = F_56 ( V_149 ) ;
if ( V_155 & ~ V_156 ) {
F_40 ( V_3 -> V_33 , L_8 ,
V_155 ) ;
return - V_137 ;
}
* V_7 = V_155 ;
* V_6 |= V_20 ;
continue;
}
return - V_137 ;
}
return 0 ;
}
static inline int F_57 ( struct V_157 * V_149 ,
struct V_157 * V_158 )
{
return memcmp ( V_149 , V_158 , sizeof( * V_149 ) ) ;
}
static inline int F_58 ( struct V_157 * V_159 )
{
return F_59 ( V_159 , sizeof( * V_159 ) , 0 ) ;
}
static int F_60 ( struct V_2 * V_3 ,
struct V_160 * V_161 ,
struct V_160 * * V_162 ,
struct V_163 * V_164 ,
struct V_165 * * V_166 ,
T_4 * V_167 ,
int * V_168 )
{
struct V_40 * V_41 = V_3 -> V_10 -> V_3 . V_42 ;
struct V_169 * V_170 ;
struct V_165 * V_52 = NULL ;
int V_171 ;
#if F_61 ( V_172 )
int V_173 ;
V_170 = F_62 ( F_63 ( V_161 ) , V_164 ) ;
V_173 = F_64 ( V_170 ) ;
if ( V_173 )
return V_173 ;
#else
return - V_87 ;
#endif
if ( ! F_65 ( V_3 -> V_33 , V_170 -> V_84 . V_9 ) )
* V_162 = F_66 ( V_41 ) ;
else
* V_162 = V_170 -> V_84 . V_9 ;
V_171 = F_67 ( & V_170 -> V_84 ) ;
V_52 = F_68 ( & V_170 -> V_84 , & V_164 -> V_174 ) ;
F_69 ( V_170 ) ;
if ( ! V_52 )
return - V_175 ;
* V_166 = V_52 ;
* V_167 = V_164 -> V_167 ;
* V_168 = V_171 ;
return 0 ;
}
static int F_70 ( struct V_160 * V_162 ,
char V_176 [] ,
unsigned char V_177 [ V_178 ] ,
int V_171 ,
T_4 V_174 ,
T_4 V_167 ,
T_5 V_179 ,
T_4 V_180 )
{
int V_181 = V_182 + sizeof( struct V_183 ) + V_184 ;
struct V_185 * V_186 = (struct V_185 * ) V_176 ;
struct V_183 * V_187 = (struct V_183 * ) ( ( char * ) V_186 + sizeof( struct V_185 ) ) ;
struct V_188 * V_189 = (struct V_188 * ) ( ( char * ) V_187 + sizeof( struct V_183 ) ) ;
struct V_190 * V_191 = (struct V_190 * ) ( ( char * ) V_189 + sizeof( struct V_188 ) ) ;
memset ( V_176 , 0 , V_181 ) ;
F_43 ( V_186 -> V_177 , V_177 ) ;
F_43 ( V_186 -> V_192 , V_162 -> V_103 ) ;
V_186 -> V_193 = F_71 ( V_100 ) ;
V_187 -> V_174 = V_174 ;
V_187 -> V_167 = V_167 ;
V_187 -> V_171 = V_171 ;
V_187 -> V_194 = V_70 ;
V_187 -> V_195 = 0x4 ;
V_187 -> V_196 = 0x5 ;
V_189 -> V_12 = V_179 ;
V_191 -> V_197 = V_198 ;
V_191 -> V_180 = F_72 ( V_180 ) ;
return V_181 ;
}
static int F_73 ( struct V_2 * V_3 ,
struct V_160 * V_161 ,
struct V_49 * V_50 ,
struct V_160 * * V_162 )
{
int V_199 = F_39 ( V_3 -> V_10 , V_200 ) ;
struct V_165 * V_52 = NULL ;
struct V_163 V_164 = {} ;
char * V_201 ;
int V_181 ;
T_4 V_167 ;
int V_171 ;
int V_43 ;
V_201 = F_74 ( V_199 , V_202 ) ;
if ( ! V_201 )
return - V_175 ;
switch ( V_50 -> V_203 ) {
case V_204 :
V_164 . V_205 = V_70 ;
V_164 . V_206 = V_50 -> V_207 . V_208 ;
break;
default:
V_43 = - V_87 ;
goto V_209;
}
V_164 . V_174 = V_50 -> V_207 . V_174 ;
V_43 = F_60 ( V_3 , V_161 , V_162 ,
& V_164 , & V_52 , & V_167 , & V_171 ) ;
if ( V_43 )
goto V_209;
V_50 -> V_52 = V_52 ;
V_50 -> V_162 = * V_162 ;
if ( ! ( V_52 -> V_210 & V_211 ) ) {
F_75 ( L_9 , V_212 , & V_164 . V_174 ) ;
V_43 = - V_87 ;
goto V_209;
}
F_76 ( V_50 -> V_177 , V_52 , * V_162 ) ;
switch ( V_50 -> V_203 ) {
case V_204 :
V_181 = F_70 ( * V_162 , V_201 ,
V_50 -> V_177 , V_171 ,
V_50 -> V_207 . V_174 ,
V_167 , V_50 -> V_207 . V_208 ,
V_50 -> V_207 . V_213 ) ;
break;
default:
V_43 = - V_87 ;
goto V_209;
}
V_43 = F_77 ( V_3 -> V_10 , V_50 -> V_203 ,
V_181 , V_201 , & V_50 -> V_15 ) ;
V_209:
if ( V_43 && V_52 )
F_20 ( V_52 ) ;
F_22 ( V_201 ) ;
return V_43 ;
}
static int F_78 ( struct V_2 * V_3 ,
struct V_214 * V_207 ,
struct V_160 * V_161 ,
struct V_38 * V_39 )
{
struct V_40 * V_41 = V_3 -> V_10 -> V_3 . V_42 ;
unsigned short V_215 = F_79 ( V_207 ) ;
struct V_216 * V_74 = & V_207 -> V_74 ;
struct V_157 V_159 ;
struct V_49 * V_50 ;
struct V_160 * V_162 ;
T_6 V_217 ;
bool V_218 = false ;
int V_203 ;
int V_43 ;
if ( ! F_36 ( & V_74 -> V_208 , 0 , sizeof( V_74 -> V_208 ) ) )
goto V_219;
if ( F_36 ( & V_74 -> V_220 , 0 , sizeof( V_74 -> V_220 ) ) ) {
V_219:
F_40 ( V_3 -> V_33 ,
L_10 ) ;
return - V_87 ;
}
if ( F_37 ( V_3 , F_38 ( V_74 -> V_208 ) ) &&
F_39 ( V_3 -> V_10 , V_86 ) ) {
V_159 . V_208 = V_74 -> V_208 ;
V_159 . V_213 = F_80 ( V_74 -> V_213 ) ;
V_203 = V_204 ;
} else {
F_40 ( V_3 -> V_33 ,
L_2 , F_38 ( V_74 -> V_208 ) ) ;
return - V_87 ;
}
switch ( V_215 ) {
case V_221 :
V_159 . V_174 = V_74 -> V_222 . V_97 . V_84 ;
break;
case V_223 :
F_40 ( V_3 -> V_33 ,
L_11 ) ;
default:
return - V_87 ;
}
V_217 = F_58 ( & V_159 ) ;
F_81 (esw->offloads.encap_tbl, e,
encap_hlist, hash_key) {
if ( ! F_57 ( & V_50 -> V_207 , & V_159 ) ) {
V_218 = true ;
break;
}
}
if ( V_218 ) {
V_39 -> V_48 = V_50 ;
return 0 ;
}
V_50 = F_74 ( sizeof( * V_50 ) , V_202 ) ;
if ( ! V_50 )
return - V_175 ;
V_50 -> V_207 = V_159 ;
V_50 -> V_203 = V_203 ;
F_82 ( & V_50 -> V_51 ) ;
V_43 = F_73 ( V_3 , V_161 , V_50 , & V_162 ) ;
if ( V_43 )
goto V_224;
V_39 -> V_48 = V_50 ;
F_83 ( V_41 -> V_144 . V_225 , & V_50 -> V_53 , V_217 ) ;
return V_43 ;
V_224:
F_22 ( V_50 ) ;
return V_43 ;
}
static int F_84 ( struct V_2 * V_3 , struct V_146 * V_147 ,
struct V_44 * V_45 )
{
struct V_38 * V_39 = V_45 -> V_39 ;
struct V_214 * V_159 = NULL ;
const struct V_148 * V_149 ;
F_49 ( V_150 ) ;
bool V_48 = false ;
int V_43 ;
if ( F_50 ( V_147 ) )
return - V_137 ;
memset ( V_39 , 0 , sizeof( * V_39 ) ) ;
V_39 -> V_226 = V_3 -> V_141 ;
F_51 ( V_147 , & V_150 ) ;
F_52 (a, &actions, list) {
if ( F_53 ( V_149 ) ) {
V_39 -> V_6 |= V_152 |
V_26 ;
continue;
}
if ( F_85 ( V_149 ) ) {
int V_227 = F_86 ( V_149 ) ;
struct V_160 * V_162 ;
struct V_2 * V_228 ;
V_162 = F_87 ( F_63 ( V_3 -> V_33 ) , V_227 ) ;
if ( F_65 ( V_3 -> V_33 ,
V_162 ) ) {
V_39 -> V_6 |= V_20 |
V_26 ;
V_228 = F_88 ( V_162 ) ;
V_39 -> V_229 = V_228 -> V_141 ;
} else if ( V_48 ) {
V_43 = F_78 ( V_3 , V_159 ,
V_162 , V_39 ) ;
if ( V_43 )
return V_43 ;
F_89 ( & V_45 -> V_48 , & V_39 -> V_48 -> V_51 ) ;
V_39 -> V_6 |= V_56 |
V_20 |
V_26 ;
V_228 = F_88 ( V_39 -> V_48 -> V_162 ) ;
V_39 -> V_229 = V_228 -> V_141 ;
} else {
F_90 ( L_12 ,
V_3 -> V_33 -> V_230 , V_162 -> V_230 ) ;
return - V_137 ;
}
continue;
}
if ( F_91 ( V_149 ) ) {
V_159 = F_92 ( V_149 ) ;
if ( V_159 )
V_48 = true ;
else
return - V_87 ;
continue;
}
if ( F_93 ( V_149 ) ) {
if ( F_94 ( V_149 ) == V_231 ) {
V_39 -> V_6 |= V_232 ;
} else if ( F_94 ( V_149 ) == V_233 ) {
if ( F_95 ( V_149 ) != F_71 ( V_234 ) )
return - V_87 ;
V_39 -> V_6 |= V_235 ;
V_39 -> V_24 = F_96 ( V_149 ) ;
}
continue;
}
if ( F_97 ( V_149 ) ) {
V_39 -> V_6 |= V_236 ;
continue;
}
return - V_137 ;
}
return 0 ;
}
int F_98 ( struct V_2 * V_3 , T_5 V_194 ,
struct V_57 * V_58 )
{
struct V_237 * V_28 = & V_3 -> V_23 . V_28 ;
int V_43 = 0 ;
bool V_238 = false ;
T_1 V_7 , V_6 ;
struct V_44 * V_45 ;
struct V_4 * V_5 ;
struct V_40 * V_41 = V_3 -> V_10 -> V_3 . V_42 ;
if ( V_41 && V_41 -> V_54 == V_55 )
V_238 = true ;
if ( V_238 )
V_45 = F_74 ( sizeof( * V_45 ) +
sizeof( struct V_38 ) ,
V_202 ) ;
else
V_45 = F_74 ( sizeof( * V_45 ) , V_202 ) ;
V_5 = F_99 ( sizeof( * V_5 ) ) ;
if ( ! V_5 || ! V_45 ) {
V_43 = - V_175 ;
goto V_239;
}
V_45 -> V_240 = V_58 -> V_240 ;
V_43 = F_47 ( V_3 , V_5 , V_58 ) ;
if ( V_43 < 0 )
goto V_239;
if ( V_238 ) {
V_45 -> V_39 = (struct V_38 * ) ( V_45 + 1 ) ;
V_43 = F_84 ( V_3 , V_58 -> V_147 , V_45 ) ;
if ( V_43 < 0 )
goto V_239;
V_45 -> V_18 = F_11 ( V_3 , V_5 , V_45 -> V_39 ) ;
} else {
V_43 = F_48 ( V_3 , V_58 -> V_147 , & V_6 , & V_7 ) ;
if ( V_43 < 0 )
goto V_239;
V_45 -> V_18 = F_1 ( V_3 , V_5 , V_6 , V_7 ) ;
}
if ( F_3 ( V_45 -> V_18 ) ) {
V_43 = F_100 ( V_45 -> V_18 ) ;
goto V_241;
}
V_43 = F_101 ( & V_28 -> V_242 , & V_45 -> V_243 ,
V_28 -> V_244 ) ;
if ( V_43 )
goto V_241;
goto V_209;
V_241:
F_23 ( V_3 , V_45 ) ;
V_239:
F_22 ( V_45 ) ;
V_209:
F_102 ( V_5 ) ;
return V_43 ;
}
int F_103 ( struct V_2 * V_3 ,
struct V_57 * V_58 )
{
struct V_44 * V_45 ;
struct V_237 * V_28 = & V_3 -> V_23 . V_28 ;
V_45 = F_104 ( & V_28 -> V_242 , & V_58 -> V_240 ,
V_28 -> V_244 ) ;
if ( ! V_45 )
return - V_137 ;
F_105 ( & V_28 -> V_242 , & V_45 -> V_243 , V_28 -> V_244 ) ;
F_23 ( V_3 , V_45 ) ;
F_22 ( V_45 ) ;
return 0 ;
}
int F_106 ( struct V_2 * V_3 ,
struct V_57 * V_58 )
{
struct V_237 * V_28 = & V_3 -> V_23 . V_28 ;
struct V_44 * V_45 ;
struct V_148 * V_149 ;
struct V_16 * V_17 ;
F_49 ( V_150 ) ;
T_7 V_245 ;
T_7 V_246 ;
T_7 V_247 ;
V_45 = F_104 ( & V_28 -> V_242 , & V_58 -> V_240 ,
V_28 -> V_244 ) ;
if ( ! V_45 )
return - V_137 ;
V_17 = F_24 ( V_45 -> V_18 ) ;
if ( ! V_17 )
return 0 ;
F_107 ( V_17 , & V_245 , & V_246 , & V_247 ) ;
F_108 () ;
F_51 ( V_58 -> V_147 , & V_150 ) ;
F_52 (a, &actions, list)
F_109 ( V_149 , V_245 , V_246 , V_247 ) ;
F_110 () ;
return 0 ;
}
int F_111 ( struct V_2 * V_3 )
{
struct V_237 * V_28 = & V_3 -> V_23 . V_28 ;
V_28 -> V_244 = V_248 ;
return F_112 ( & V_28 -> V_242 , & V_28 -> V_244 ) ;
}
static void F_113 ( void * V_249 , void * V_250 )
{
struct V_44 * V_45 = V_249 ;
struct V_2 * V_3 = V_250 ;
F_23 ( V_3 , V_45 ) ;
F_22 ( V_45 ) ;
}
void F_114 ( struct V_2 * V_3 )
{
struct V_237 * V_28 = & V_3 -> V_23 . V_28 ;
F_115 ( & V_28 -> V_242 , F_113 , V_3 ) ;
if ( ! F_5 ( V_28 -> V_25 ) ) {
F_9 ( V_28 -> V_25 ) ;
V_28 -> V_25 = NULL ;
}
}
