int F_1 ( struct V_1 * V_2 , T_1 V_3 , void * V_4 , T_2 V_5 ,
T_2 V_6 )
{
struct V_7 * V_8 ;
unsigned long V_9 ;
T_3 V_10 ;
int V_11 = 0 ;
T_1 V_12 ;
T_1 V_13 = 0 ;
V_8 = V_4 ;
V_8 -> V_3 = F_2 ( V_3 ) ;
V_8 -> V_12 = 0 ;
F_3 ( V_5 % 4 != 0 ) ;
F_3 ( F_4 ( V_14 , & V_2 -> V_15 ) ) ;
F_5 ( V_2 , V_2 -> V_16 , V_4 , V_5 , false ) ;
F_6 ( V_2 , V_17 , V_18 ) ;
V_9 = V_19 + F_7 ( V_20 ) ;
V_10 = F_8 ( V_2 , V_21 ) ;
while ( ! ( V_10 & V_22 ) ) {
if ( F_9 ( V_19 , V_9 ) ) {
F_10 ( L_1 ) ;
V_11 = - V_23 ;
goto V_24;
}
V_13 ++ ;
if ( V_13 < V_25 )
F_11 ( 10 ) ;
else
F_12 ( 1 ) ;
V_10 = F_8 ( V_2 , V_21 ) ;
}
if ( V_6 == 0 )
V_6 = sizeof( struct V_7 ) ;
F_13 ( V_2 , V_2 -> V_16 , V_8 , V_6 , false ) ;
V_12 = F_14 ( V_8 -> V_12 ) ;
if ( V_12 != V_26 ) {
F_10 ( L_2 , V_12 ) ;
V_11 = - V_27 ;
goto V_24;
}
F_6 ( V_2 , V_28 ,
V_22 ) ;
return 0 ;
V_24:
F_3 ( 1 ) ;
F_15 ( V_2 -> V_29 , & V_2 -> V_30 ) ;
return V_11 ;
}
int F_16 ( struct V_1 * V_2 )
{
struct V_31 * V_32 ;
struct V_33 * V_34 =
& ( (struct V_35 * ) V_2 -> V_36 ) -> V_37 ;
bool V_38 = false ;
int V_11 ;
if ( ! V_2 -> V_36 )
return - V_39 ;
V_32 = F_17 ( sizeof( * V_32 ) , V_40 ) ;
if ( ! V_32 )
return - V_41 ;
V_32 -> V_42 . V_3 = V_43 ;
memcpy ( & V_32 -> V_37 , V_34 , sizeof( * V_34 ) ) ;
if ( V_34 -> V_44 )
V_38 = true ;
V_32 -> V_37 . V_45 = V_2 -> V_45 ;
V_11 = F_18 ( V_2 , V_32 , sizeof( * V_32 ) , V_38 ) ;
if ( V_11 < 0 ) {
F_19 ( L_3 ) ;
goto V_46;
}
V_34 -> V_47 =
V_32 -> V_37 . V_47 ;
F_20 ( V_48 , L_4 ,
V_38 ? L_5 : L_6 , V_34 -> V_47 ) ;
V_46:
F_21 ( V_32 ) ;
return V_11 ;
}
int F_22 ( struct V_1 * V_2 )
{
struct V_49 * V_32 ;
struct V_50 * V_34 =
& ( (struct V_51 * ) V_2 -> V_36 ) -> V_37 ;
bool V_38 = false ;
int V_11 ;
if ( ! V_2 -> V_36 )
return - V_39 ;
V_32 = F_17 ( sizeof( * V_32 ) , V_40 ) ;
if ( ! V_32 )
return - V_41 ;
V_32 -> V_42 . V_3 = V_43 ;
memcpy ( & V_32 -> V_37 , V_34 , sizeof( * V_34 ) ) ;
if ( V_34 -> V_44 )
V_38 = true ;
V_32 -> V_37 . V_45 = V_2 -> V_45 ;
V_32 -> V_37 . V_52 = V_2 -> V_53 ;
V_11 = F_18 ( V_2 , V_32 , sizeof( * V_32 ) , V_38 ) ;
if ( V_11 < 0 ) {
F_19 ( L_3 ) ;
goto V_46;
}
V_34 -> V_47 =
V_32 -> V_37 . V_47 ;
F_20 ( V_48 , L_4 ,
V_38 ? L_5 : L_6 , V_34 -> V_47 ) ;
V_46:
F_21 ( V_32 ) ;
return V_11 ;
}
int F_23 ( struct V_1 * V_2 )
{
struct V_35 * V_36 = (struct V_35 * ) V_2 -> V_36 ;
struct V_54 * V_55 ;
struct V_33 * V_34 = & V_36 -> V_37 ;
int V_11 ;
if ( ! V_2 -> V_36 )
return - V_39 ;
V_55 = F_17 ( sizeof( * V_55 ) , V_40 ) ;
if ( ! V_55 )
return - V_41 ;
V_55 -> V_42 . V_3 = V_56 ;
memcpy ( & V_55 -> V_57 , & V_36 -> V_58 ,
sizeof( struct V_59 ) ) ;
memcpy ( & V_55 -> V_60 ,
& V_36 -> V_61 [ V_34 -> V_47 ] . V_62 ,
sizeof( struct V_63 ) ) ;
memcpy ( & V_55 -> V_64 ,
& V_36 -> V_65 ,
sizeof( struct V_66 ) ) ;
memcpy ( & V_55 -> V_67 ,
& V_36 -> V_68 [ V_34 -> V_47 ] . V_62 ,
sizeof( struct V_69 ) ) ;
F_24 ( V_48 , L_7 ,
V_55 , sizeof( * V_55 ) ) ;
V_11 = F_18 ( V_2 , V_55 , sizeof( * V_55 ) , 0 ) ;
if ( V_11 < 0 )
F_19 ( L_8 ) ;
F_21 ( V_55 ) ;
return V_11 ;
}
int F_25 ( struct V_1 * V_2 )
{
struct V_51 * V_36 = (struct V_51 * ) V_2 -> V_36 ;
struct V_70 * V_55 ;
struct V_50 * V_34 = & V_36 -> V_37 ;
int V_11 ;
if ( ! V_2 -> V_36 )
return - V_39 ;
V_55 = F_17 ( sizeof( * V_55 ) , V_40 ) ;
if ( ! V_55 )
return - V_41 ;
V_55 -> V_42 . V_3 = V_56 ;
memcpy ( & V_55 -> V_57 , & V_36 -> V_58 ,
sizeof( struct V_71 ) ) ;
memcpy ( & V_55 -> V_60 ,
& V_36 -> V_61 [ V_34 -> V_47 ] . V_62 ,
sizeof( struct V_72 ) ) ;
memcpy ( & V_55 -> V_64 ,
& V_36 -> V_65 ,
sizeof( struct V_73 ) ) ;
memcpy ( & V_55 -> V_67 ,
& V_36 -> V_68 [ V_34 -> V_47 ] . V_62 ,
sizeof( struct V_74 ) ) ;
V_55 -> V_75 = V_36 -> V_75 ;
F_24 ( V_48 , L_7 ,
V_55 , sizeof( * V_55 ) ) ;
V_11 = F_18 ( V_2 , V_55 , sizeof( * V_55 ) , 0 ) ;
if ( V_11 < 0 )
F_19 ( L_8 ) ;
F_21 ( V_55 ) ;
return V_11 ;
}
int F_26 ( struct V_1 * V_2 )
{
struct V_76 * V_77 ;
struct V_78 * V_79 = & V_2 -> V_80 . V_79 ;
int V_11 ;
if ( ! V_2 -> V_36 )
return - V_39 ;
V_77 = F_17 ( sizeof( * V_77 ) , V_40 ) ;
if ( ! V_77 )
return - V_41 ;
V_77 -> V_42 . V_3 = V_81 ;
memcpy ( V_77 -> V_82 ,
V_79 -> V_82 ,
V_83 ) ;
memcpy ( V_77 -> V_84 ,
V_79 -> V_84 ,
V_85 ) ;
F_24 ( V_48 , L_9 ,
V_77 , sizeof( * V_77 ) ) ;
V_11 = F_18 ( V_2 , V_77 , sizeof( * V_77 ) , 0 ) ;
if ( V_11 < 0 )
F_19 ( L_10 ) ;
F_21 ( V_77 ) ;
return V_11 ;
}
static int F_27 ( struct V_1 * V_2 , T_3 V_86 )
{
T_3 V_87 , V_88 ;
unsigned long V_9 ;
V_9 = V_19 + F_7 ( V_89 ) ;
do {
if ( F_9 ( V_19 , V_9 ) ) {
F_20 ( V_48 , L_11 ,
( int ) V_86 ) ;
return - V_23 ;
}
F_12 ( 1 ) ;
F_13 ( V_2 , V_2 -> V_90 [ 0 ] , & V_87 ,
sizeof( V_87 ) , false ) ;
V_88 = V_87 & V_86 ;
F_13 ( V_2 , V_2 -> V_90 [ 1 ] , & V_87 ,
sizeof( V_87 ) , false ) ;
V_88 |= V_87 & V_86 ;
} while ( ! V_88 );
return 0 ;
}
static int F_28 ( struct V_1 * V_2 , T_3 V_86 )
{
int V_11 ;
V_11 = F_27 ( V_2 , V_86 ) ;
if ( V_11 != 0 ) {
F_15 ( V_2 -> V_29 , & V_2 -> V_30 ) ;
return V_11 ;
}
return 0 ;
}
int F_29 ( struct V_1 * V_2 , T_4 V_91 )
{
struct F_29 * V_92 ;
int V_11 , V_93 ;
T_4 * V_94 ;
V_92 = F_17 ( sizeof( * V_92 ) , V_40 ) ;
if ( ! V_92 ) {
V_11 = - V_41 ;
goto V_46;
}
F_20 ( V_48 , L_12 ) ;
V_94 = ( T_4 * ) & V_92 -> V_95 ;
for ( V_93 = 0 ; V_93 < V_96 ; V_93 ++ )
V_94 [ V_93 ] = V_2 -> V_94 [ V_96 - V_93 - 1 ] ;
V_92 -> V_97 = F_30 ( V_2 -> V_98 ) ;
V_92 -> V_99 = F_30 ( V_2 -> V_100 ) ;
V_92 -> V_91 = V_91 ;
V_92 -> V_101 = F_30 ( V_2 -> V_101 ) ;
V_92 -> V_102 = F_30 ( V_2 -> V_103 ) ;
if ( V_2 -> V_104 == V_105 )
V_92 -> V_91 |= V_106 ;
V_92 -> V_107 = F_2 ( V_2 -> V_108 ) ;
V_92 -> V_109 = V_110 ;
V_92 -> V_111 = V_2 -> V_111 ;
V_92 -> V_112 = V_2 -> V_112 ;
memcpy ( V_92 -> V_113 , V_2 -> V_113 , V_2 -> V_112 ) ;
V_92 -> V_114 |= V_2 -> V_115 << V_116 ;
V_2 -> V_117 = 0 ;
V_2 -> V_118 = 0 ;
F_20 ( V_48 , L_13 ,
V_92 -> V_101 , V_92 -> V_102 ) ;
V_11 = F_1 ( V_2 , V_119 , V_92 , sizeof( * V_92 ) , 0 ) ;
if ( V_11 < 0 ) {
F_10 ( L_14 ) ;
goto V_120;
}
V_11 = F_28 ( V_2 , V_121 ) ;
if ( V_11 < 0 )
F_10 ( L_15 ) ;
V_120:
F_21 ( V_92 ) ;
V_46:
return V_11 ;
}
int F_18 ( struct V_1 * V_2 , void * V_4 , T_2 V_122 , T_4 V_38 )
{
int V_11 ;
T_2 V_6 = 0 ;
F_20 ( V_48 , L_16 ) ;
if ( V_38 )
V_6 = V_122 ;
V_11 = F_1 ( V_2 , V_123 , V_4 , V_122 , V_6 ) ;
if ( V_11 < 0 ) {
F_19 ( L_17 ) ;
return V_11 ;
}
return V_11 ;
}
int F_31 ( struct V_1 * V_2 , T_1 V_3 , void * V_4 , T_2 V_5 )
{
struct V_124 * V_125 = V_4 ;
int V_11 ;
F_20 ( V_48 , L_18 ) ;
V_125 -> V_3 = F_2 ( V_3 ) ;
V_125 -> V_5 = F_2 ( V_5 - sizeof( * V_125 ) ) ;
V_11 = F_1 ( V_2 , V_126 , V_125 , sizeof( * V_125 ) , V_5 ) ;
if ( V_11 < 0 )
F_10 ( L_19 ) ;
return V_11 ;
}
int F_32 ( struct V_1 * V_2 , T_1 V_3 , void * V_4 , T_2 V_5 )
{
struct V_124 * V_125 = V_4 ;
int V_11 ;
F_20 ( V_48 , L_20 ) ;
V_125 -> V_3 = F_2 ( V_3 ) ;
V_125 -> V_5 = F_2 ( V_5 - sizeof( * V_125 ) ) ;
V_11 = F_1 ( V_2 , V_127 , V_125 , V_5 , 0 ) ;
if ( V_11 < 0 ) {
F_19 ( L_21 ) ;
return V_11 ;
}
return 0 ;
}
int F_33 ( struct V_1 * V_2 , bool V_128 )
{
struct V_129 * V_8 ;
int V_11 ;
T_1 V_130 , V_131 ;
F_20 ( V_48 , L_22 ) ;
V_8 = F_17 ( sizeof( * V_8 ) , V_40 ) ;
if ( ! V_8 ) {
V_11 = - V_41 ;
goto V_46;
}
V_8 -> V_111 = 1 ;
if ( V_128 ) {
V_130 = V_132 ;
V_131 = V_133 ;
} else {
V_130 = V_134 ;
V_131 = V_135 ;
}
V_11 = F_1 ( V_2 , V_130 , V_8 , sizeof( * V_8 ) , 0 ) ;
if ( V_11 < 0 ) {
F_10 ( L_23 ,
V_128 ? L_24 : L_25 , V_8 -> V_111 ) ;
goto V_46;
}
F_20 ( V_136 , L_26 ,
V_128 ? L_24 : L_25 , V_8 -> V_111 ) ;
V_11 = F_1 ( V_2 , V_131 , V_8 , sizeof( * V_8 ) , 0 ) ;
if ( V_11 < 0 ) {
F_10 ( L_27 ,
V_128 ? L_24 : L_25 , V_8 -> V_111 ) ;
goto V_46;
}
F_20 ( V_136 , L_28 ,
V_128 ? L_24 : L_25 , V_8 -> V_111 ) ;
V_46:
F_21 ( V_8 ) ;
return V_11 ;
}
int F_34 ( struct V_1 * V_2 , T_4 V_137 )
{
struct V_138 * V_139 = NULL ;
int V_11 = 0 ;
F_20 ( V_48 , L_29 ) ;
V_139 = F_17 ( sizeof( * V_139 ) , V_40 ) ;
if ( ! V_139 ) {
V_11 = - V_41 ;
goto V_46;
}
V_139 -> V_137 = V_137 ;
V_11 = F_1 ( V_2 , V_140 , V_139 ,
sizeof( * V_139 ) , 0 ) ;
if ( V_11 < 0 ) {
F_10 ( L_30 ) ;
goto V_46;
}
V_46:
F_21 ( V_139 ) ;
return V_11 ;
}
int F_35 ( struct V_1 * V_2 , T_1 V_141 ,
void * V_4 , T_2 V_122 , int V_142 , T_3 V_143 )
{
struct F_35 * V_8 ;
int V_11 = 0 ;
F_20 ( V_48 , L_31 , V_141 ) ;
F_3 ( V_122 > V_144 ) ;
V_122 = F_36 ( T_2 , V_122 , V_144 ) ;
V_8 = F_17 ( sizeof( * V_8 ) , V_40 ) ;
if ( ! V_8 ) {
V_11 = - V_41 ;
goto V_46;
}
V_8 -> V_5 = F_2 ( V_122 ) ;
V_8 -> V_145 = V_141 ;
V_8 -> V_146 = F_30 ( V_143 ) ;
V_8 -> V_147 = V_2 -> V_80 . V_148 . V_149 ;
V_8 -> V_150 = V_2 -> V_80 . V_148 . V_151 ;
V_8 -> V_142 = V_142 ;
if ( V_4 )
memcpy ( V_8 -> V_152 , V_4 , V_122 ) ;
V_11 = F_1 ( V_2 , V_153 , V_8 , sizeof( * V_8 ) , 0 ) ;
if ( V_11 < 0 ) {
F_19 ( L_32 , V_11 ) ;
goto V_120;
}
V_120:
F_21 ( V_8 ) ;
V_46:
return V_11 ;
}
int F_37 ( struct V_1 * V_2 )
{
struct V_154 * V_155 = NULL ;
int V_156 ;
void * V_157 ;
int V_11 = - V_41 ;
if ( V_2 -> V_91 == V_158 ) {
V_156 = sizeof( struct V_159 ) ;
V_157 = NULL ;
} else {
V_155 = F_38 ( V_2 -> V_29 , V_2 -> V_160 ) ;
if ( ! V_155 )
goto V_46;
V_156 = V_155 -> V_5 ;
V_157 = V_155 -> V_161 ;
}
V_11 = F_35 ( V_2 , V_162 , V_157 , V_156 , 0 ,
V_2 -> V_163 ) ;
V_46:
F_39 ( V_155 ) ;
if ( V_11 )
F_19 ( L_33 , V_11 ) ;
return V_11 ;
}
int F_40 ( struct V_1 * V_2 )
{
struct V_154 * V_155 = NULL ;
int V_11 = - V_41 ;
V_155 = F_38 ( V_2 -> V_29 , V_2 -> V_160 ) ;
if ( ! V_155 )
goto V_46;
V_11 = F_35 ( V_2 , V_164 ,
V_155 -> V_161 , V_155 -> V_5 ,
V_165 ,
V_2 -> V_163 ) ;
V_46:
F_39 ( V_155 ) ;
if ( V_11 )
F_19 ( L_34 , V_11 ) ;
return V_11 ;
}
int F_41 ( struct V_1 * V_2 , T_1 V_166 )
{
struct V_154 * V_155 ;
int V_11 = 0 ;
V_155 = F_42 ( V_2 -> V_29 , V_2 -> V_160 ) ;
if ( ! V_155 )
goto V_46;
V_11 = F_35 ( V_2 , V_167 , V_155 -> V_161 ,
V_155 -> V_5 , 0 , V_2 -> V_101 ) ;
V_46:
F_39 ( V_155 ) ;
return V_11 ;
}
int F_43 ( struct V_1 * V_2 ,
const T_4 * V_113 , T_2 V_112 ,
const T_4 * V_168 , T_2 V_169 , T_4 V_104 )
{
struct V_154 * V_155 ;
int V_11 ;
V_155 = F_44 ( V_2 -> V_29 , V_2 -> V_160 , V_113 , V_112 ,
V_168 , V_169 ) ;
if ( ! V_155 ) {
V_11 = - V_41 ;
goto V_46;
}
F_24 ( V_170 , L_35 , V_155 -> V_161 , V_155 -> V_5 ) ;
if ( V_104 == V_171 )
V_11 = F_35 ( V_2 , V_172 ,
V_155 -> V_161 , V_155 -> V_5 , 0 ,
V_2 -> V_80 . V_148 . V_163 ) ;
else
V_11 = F_35 ( V_2 , V_173 ,
V_155 -> V_161 , V_155 -> V_5 , 0 ,
V_2 -> V_80 . V_148 . V_174 ) ;
V_46:
F_39 ( V_155 ) ;
return V_11 ;
}
struct V_154 * F_45 ( struct V_1 * V_2 ,
struct V_154 * V_155 )
{
int V_11 ;
if ( ! V_155 )
V_155 = F_46 ( V_2 -> V_29 , V_2 -> V_160 ) ;
if ( ! V_155 )
goto V_46;
F_24 ( V_170 , L_36 , V_155 -> V_161 , V_155 -> V_5 ) ;
if ( V_2 -> V_104 == V_171 )
V_11 = F_35 ( V_2 , V_172 ,
V_155 -> V_161 , V_155 -> V_5 , 0 ,
V_2 -> V_80 . V_148 . V_163 ) ;
else
V_11 = F_35 ( V_2 , V_173 ,
V_155 -> V_161 , V_155 -> V_5 , 0 ,
V_2 -> V_80 . V_148 . V_174 ) ;
if ( V_11 < 0 )
F_10 ( L_37 ) ;
V_46:
return V_155 ;
}
int F_47 ( struct V_1 * V_2 , T_5 V_175 )
{
int V_11 ;
struct V_176 V_177 ;
struct V_178 * V_179 ;
struct V_180 * V_181 ;
memset ( & V_177 , 0 , sizeof( V_177 ) ) ;
V_179 = & V_177 . V_179 ;
V_179 -> V_182 = F_2 ( V_183 |
V_184 |
V_185 ) ;
memcpy ( V_179 -> V_186 , V_2 -> V_160 -> V_187 . V_94 , V_96 ) ;
memcpy ( V_179 -> V_188 , V_2 -> V_160 -> V_189 , V_96 ) ;
memset ( V_179 -> V_190 , 0xff , V_96 ) ;
memcpy ( V_177 . V_191 , V_192 , sizeof( V_192 ) ) ;
V_177 . V_193 = F_48 ( V_194 ) ;
V_181 = & V_177 . V_181 ;
V_181 -> V_195 = F_48 ( V_196 ) ;
V_181 -> V_197 = F_48 ( V_198 ) ;
V_181 -> V_199 = V_96 ;
V_181 -> V_200 = 4 ;
V_181 -> V_201 = F_48 ( V_202 ) ;
memcpy ( V_177 . V_203 , V_2 -> V_160 -> V_189 , V_96 ) ;
V_177 . V_204 = V_175 ;
V_11 = F_35 ( V_2 , V_205 ,
& V_177 , sizeof( V_177 ) , 0 ,
V_2 -> V_163 ) ;
return V_11 ;
}
int F_49 ( struct V_1 * V_2 )
{
struct V_206 V_207 ;
memset ( & V_207 , 0 , sizeof( V_207 ) ) ;
memcpy ( V_207 . V_186 , V_2 -> V_94 , V_96 ) ;
memcpy ( V_207 . V_188 , V_2 -> V_208 , V_96 ) ;
memcpy ( V_207 . V_190 , V_2 -> V_94 , V_96 ) ;
V_207 . V_182 = F_2 ( V_183 |
V_209 |
V_185 ) ;
V_207 . V_210 = F_2 ( 0 ) ;
return F_35 ( V_2 , V_211 , & V_207 ,
sizeof( V_207 ) , 0 ,
V_2 -> V_163 ) ;
}
int F_50 ( struct V_1 * V_2 , T_4 V_3 )
{
struct V_212 * V_8 ;
int V_11 = 0 ;
F_20 ( V_48 , L_38 , V_3 ) ;
V_8 = F_17 ( sizeof( * V_8 ) , V_40 ) ;
if ( ! V_8 ) {
V_11 = - V_41 ;
goto V_46;
}
V_8 -> V_3 = V_3 ;
V_8 -> V_213 = F_2 ( V_214 ) ;
V_8 -> V_215 = V_216 ;
V_11 = F_1 ( V_2 , V_217 , V_8 , sizeof( * V_8 ) , 0 ) ;
if ( V_11 < 0 ) {
F_19 ( L_39 , V_11 ) ;
goto V_46;
}
V_46:
F_21 ( V_8 ) ;
return V_11 ;
}
int F_51 ( struct V_1 * V_2 , T_4 V_3 )
{
struct V_218 * V_8 ;
int V_11 = 0 ;
F_20 ( V_48 , L_40 , V_3 ) ;
V_8 = F_17 ( sizeof( * V_8 ) , V_40 ) ;
if ( ! V_8 ) {
V_11 = - V_41 ;
goto V_46;
}
V_8 -> V_219 = V_220 ;
V_8 -> V_221 = V_3 ;
V_8 -> V_222 = V_223 ;
V_8 -> V_213 = F_2 ( V_214 ) ;
V_8 -> V_215 = V_216 ;
V_11 = F_1 ( V_2 , V_217 , V_8 , sizeof( * V_8 ) , 0 ) ;
if ( V_11 < 0 ) {
F_19 ( L_41 , V_11 ) ;
goto V_46;
}
V_46:
F_21 ( V_8 ) ;
return V_11 ;
}
int F_52 ( struct V_1 * V_2 , T_1 V_224 , T_4 V_3 , T_4 V_215 ,
T_4 V_225 , const T_4 * V_226 , const T_4 * V_189 ,
T_3 V_227 , T_1 V_228 )
{
struct V_212 * V_8 ;
int V_11 = 0 ;
V_8 = F_17 ( sizeof( * V_8 ) , V_40 ) ;
if ( ! V_8 ) {
V_11 = - V_41 ;
goto V_46;
}
if ( V_215 != V_216 )
memcpy ( V_8 -> V_189 , V_189 , V_96 ) ;
V_8 -> V_213 = F_2 ( V_224 ) ;
V_8 -> V_225 = V_225 ;
V_8 -> V_215 = V_215 ;
V_8 -> V_229 [ 0 ] = F_2 ( V_228 ) ;
V_8 -> V_230 [ 0 ] = F_30 ( V_227 ) ;
V_8 -> V_231 = 0 ;
V_8 -> V_3 = V_3 ;
if ( V_215 == V_232 ) {
memcpy ( V_8 -> V_226 , V_226 , 16 ) ;
memcpy ( V_8 -> V_226 + 16 , V_226 + 24 , 8 ) ;
memcpy ( V_8 -> V_226 + 24 , V_226 + 16 , 8 ) ;
} else {
memcpy ( V_8 -> V_226 , V_226 , V_225 ) ;
}
F_24 ( V_233 , L_42 , V_8 , sizeof( * V_8 ) ) ;
V_11 = F_1 ( V_2 , V_217 , V_8 , sizeof( * V_8 ) , 0 ) ;
if ( V_11 < 0 ) {
F_19 ( L_43 ) ;
goto V_46;
}
V_46:
F_21 ( V_8 ) ;
return V_11 ;
}
int F_53 ( struct V_1 * V_2 , T_1 V_224 , T_4 V_3 , T_4 V_215 ,
T_4 V_225 , const T_4 * V_226 , T_4 V_219 , T_3 V_227 ,
T_1 V_228 )
{
struct V_218 * V_8 ;
int V_11 = 0 ;
T_4 V_234 ;
V_8 = F_17 ( sizeof( * V_8 ) , V_40 ) ;
if ( ! V_8 )
return - V_41 ;
if ( V_219 == V_220 ) {
if ( V_215 == V_216 )
V_234 = V_223 ;
else
V_234 = V_235 ;
} else {
V_234 = V_236 ;
}
F_20 ( V_233 , L_44
L_45 , ( int ) V_224 , ( int ) V_3 , ( int ) V_234 ,
( int ) V_215 , ( int ) V_219 ) ;
V_8 -> V_222 = V_234 ;
V_8 -> V_219 = V_219 ;
V_8 -> V_213 = F_2 ( V_224 ) ;
V_8 -> V_225 = V_225 ;
V_8 -> V_215 = V_215 ;
V_8 -> V_221 = V_3 ;
V_8 -> V_229 [ 0 ] = F_2 ( V_228 ) ;
V_8 -> V_230 [ 0 ] = F_30 ( V_227 ) ;
if ( V_215 == V_232 ) {
memcpy ( V_8 -> V_226 , V_226 , 16 ) ;
memcpy ( V_8 -> V_226 + 16 , V_226 + 24 , 8 ) ;
memcpy ( V_8 -> V_226 + 24 , V_226 + 16 , 8 ) ;
} else {
memcpy ( V_8 -> V_226 , V_226 , V_225 ) ;
}
F_24 ( V_233 , L_46 , V_8 , sizeof( * V_8 ) ) ;
V_11 = F_1 ( V_2 , V_217 , V_8 , sizeof( * V_8 ) , 0 ) ;
if ( V_11 < 0 ) {
F_19 ( L_47 ) ;
goto V_46;
}
V_46:
F_21 ( V_8 ) ;
return V_11 ;
}
int F_54 ( struct V_1 * V_2 )
{
struct F_54 * V_8 ;
int V_11 = 0 ;
F_20 ( V_48 , L_48 ) ;
V_8 = F_17 ( sizeof( * V_8 ) , V_40 ) ;
if ( ! V_8 ) {
V_11 = - V_41 ;
goto V_46;
}
V_8 -> V_97 = F_30 ( V_2 -> V_98 ) ;
V_8 -> V_99 = F_30 ( V_2 -> V_100 ) ;
V_8 -> type = V_237 ;
V_11 = F_1 ( V_2 , V_238 , V_8 , sizeof( * V_8 ) , 0 ) ;
if ( V_11 < 0 ) {
F_10 ( L_49 ) ;
goto V_120;
}
V_11 = F_28 ( V_2 , V_239 ) ;
if ( V_11 < 0 )
F_10 ( L_50 ) ;
V_120:
F_21 ( V_8 ) ;
V_46:
return V_11 ;
}
int F_55 ( struct V_1 * V_2 )
{
struct F_55 * V_8 ;
int V_11 = 0 ;
F_20 ( V_48 , L_51 ) ;
V_8 = F_17 ( sizeof( * V_8 ) , V_40 ) ;
if ( ! V_8 ) {
V_11 = - V_41 ;
goto V_46;
}
V_8 -> V_240 = V_241 ;
V_11 = F_1 ( V_2 , V_242 , V_8 , sizeof( * V_8 ) , 0 ) ;
if ( V_11 < 0 ) {
F_10 ( L_52 ) ;
goto V_120;
}
V_120:
F_21 ( V_8 ) ;
V_46:
return V_11 ;
}
int F_56 ( struct V_1 * V_2 )
{
struct V_243 * V_8 ;
struct V_244 * V_187 = & V_2 -> V_160 -> V_187 ;
int V_11 ;
F_20 ( V_48 , L_53 ) ;
if ( V_2 -> V_112 == 0 ) {
F_19 ( L_54 ) ;
V_11 = - V_245 ;
goto V_46;
}
V_8 = F_17 ( sizeof( * V_8 ) , V_40 ) ;
if ( ! V_8 ) {
V_11 = - V_41 ;
goto V_46;
}
memcpy ( V_8 -> V_94 , V_187 -> V_94 , V_96 ) ;
V_8 -> V_246 = F_2 ( V_247 ) ;
V_8 -> V_248 = V_249 ;
V_8 -> V_250 = V_251 ;
V_8 -> V_252 = V_220 ;
V_8 -> V_101 = F_30 ( V_2 -> V_101 ) ;
V_8 -> V_107 = F_2 ( V_2 -> V_108 ) ;
V_8 -> V_109 = V_187 -> V_253 ;
V_8 -> V_254 = V_255 ;
V_8 -> V_111 = V_2 -> V_111 ;
V_8 -> V_112 = V_2 -> V_112 ;
V_8 -> V_256 = V_257 ;
memcpy ( V_8 -> V_113 , V_2 -> V_113 , V_2 -> V_112 ) ;
switch ( V_2 -> V_104 ) {
case V_171 :
V_8 -> V_104 = V_258 ;
break;
case V_105 :
V_8 -> V_104 = V_259 ;
break;
default:
F_19 ( L_55 , ( int ) V_2 -> V_104 ) ;
V_8 -> V_104 = V_258 ;
break;
}
V_11 = F_1 ( V_2 , V_260 , V_8 , sizeof( * V_8 ) , 0 ) ;
if ( V_11 < 0 ) {
F_10 ( L_56 ) ;
goto V_120;
}
V_120:
F_21 ( V_8 ) ;
V_46:
return V_11 ;
}
int F_57 ( struct V_1 * V_2 )
{
struct V_243 * V_8 ;
int V_11 ;
F_20 ( V_48 , L_57 ) ;
V_8 = F_17 ( sizeof( * V_8 ) , V_40 ) ;
if ( ! V_8 ) {
V_11 = - V_41 ;
goto V_46;
}
V_8 -> V_248 = V_249 ;
V_11 = F_1 ( V_2 , V_261 , V_8 , sizeof( * V_8 ) , 0 ) ;
if ( V_11 < 0 ) {
F_10 ( L_58 ) ;
goto V_120;
}
V_120:
F_21 ( V_8 ) ;
V_46:
return V_11 ;
}
int F_58 ( struct V_1 * V_2 , struct V_262 * V_263 , T_4 V_219 )
{
struct F_58 * V_8 ;
int V_11 ;
F_20 ( V_48 , L_59 , ( int ) V_219 ) ;
V_8 = F_17 ( sizeof( * V_8 ) , V_40 ) ;
if ( ! V_8 ) {
V_11 = - V_41 ;
goto V_46;
}
V_8 -> V_264 = 0 ;
memcpy ( V_8 -> V_189 , V_263 -> V_189 , V_96 ) ;
V_8 -> V_248 = V_249 ;
V_8 -> V_166 = V_263 -> V_166 ;
V_8 -> V_219 = V_219 ;
V_8 -> V_265 = 0 ;
V_8 -> V_266 = F_30 ( F_59 ( V_2 ,
V_263 -> V_267 [ V_2 -> V_104 ] ) ) ;
F_20 ( V_48 , L_60 , V_8 -> V_266 ) ;
V_11 = F_1 ( V_2 , V_268 , V_8 , sizeof( * V_8 ) , 0 ) ;
if ( V_11 < 0 ) {
F_10 ( L_61 ) ;
goto V_120;
}
V_120:
F_21 ( V_8 ) ;
V_46:
return V_11 ;
}
int F_60 ( struct V_1 * V_2 , T_4 V_219 )
{
struct F_60 * V_8 ;
int V_11 ;
F_20 ( V_48 , L_62 , ( int ) V_219 ) ;
V_8 = F_17 ( sizeof( * V_8 ) , V_40 ) ;
if ( ! V_8 ) {
V_11 = - V_41 ;
goto V_46;
}
V_8 -> V_219 = V_219 ;
V_8 -> V_269 = 0 ;
V_8 -> V_270 = 0 ;
V_11 = F_1 ( V_2 , V_271 , V_8 , sizeof( * V_8 ) , 0 ) ;
if ( V_11 < 0 ) {
F_10 ( L_63 ) ;
goto V_120;
}
F_27 ( V_2 , V_272 ) ;
V_120:
F_21 ( V_8 ) ;
V_46:
return V_11 ;
}
