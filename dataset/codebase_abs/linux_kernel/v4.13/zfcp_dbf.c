static inline unsigned int F_1 ( unsigned int V_1 )
{
return sizeof( struct V_2 ) + V_1 - V_3 ;
}
static inline
void F_2 ( struct V_4 * V_5 , void * V_6 , T_1 V_7 , char * V_8 ,
T_2 V_9 )
{
struct V_2 * V_10 = & V_5 -> V_11 ;
T_1 V_1 = 0 , V_12 ;
F_3 ( & V_5 -> V_13 ) ;
memset ( V_10 , 0 , sizeof( * V_10 ) ) ;
V_10 -> V_14 = V_9 ;
memcpy ( V_10 -> V_8 , V_8 , V_15 ) ;
while ( V_1 < V_7 ) {
V_12 = F_4 ( ( T_1 ) V_3 ,
( T_1 ) ( V_7 - V_1 ) ) ;
memcpy ( V_10 -> V_6 , V_6 + V_1 , V_12 ) ;
F_5 ( V_5 -> V_16 , 1 , V_10 , F_1 ( V_12 ) ) ;
V_1 += V_12 ;
V_10 -> V_17 ++ ;
}
F_6 ( & V_5 -> V_13 ) ;
}
void F_7 ( char * V_18 , int V_19 , struct V_20 * V_21 )
{
struct V_4 * V_5 = V_21 -> V_22 -> V_5 ;
struct V_23 * V_24 = & V_21 -> V_25 -> V_26 ;
struct V_27 * V_28 = & V_21 -> V_25 -> V_29 ;
struct V_30 * V_31 = & V_5 -> V_32 ;
unsigned long V_33 ;
F_8 ( & V_5 -> V_34 , V_33 ) ;
memset ( V_31 , 0 , sizeof( * V_31 ) ) ;
memcpy ( V_31 -> V_18 , V_18 , V_15 ) ;
V_31 -> V_35 = V_36 ;
V_31 -> V_14 = V_21 -> V_9 ;
V_31 -> V_37 = V_21 -> V_38 ;
V_31 -> V_39 = V_21 -> V_40 ;
V_31 -> V_41 = V_21 -> V_42 ;
V_31 -> V_43 . V_44 . V_45 = V_21 -> V_46 ;
V_31 -> V_43 . V_44 . V_47 = V_24 -> V_47 ;
V_31 -> V_43 . V_44 . V_48 = V_28 -> V_48 ;
V_31 -> V_43 . V_44 . V_49 = V_28 -> V_49 ;
V_31 -> V_43 . V_44 . V_50 = V_28 -> V_50 ;
memcpy ( V_31 -> V_43 . V_44 . V_51 , & V_24 -> V_51 ,
V_52 ) ;
memcpy ( V_31 -> V_43 . V_44 . V_53 , & V_28 -> V_53 ,
V_54 ) ;
if ( V_21 -> V_40 != V_55 ) {
V_31 -> V_56 = V_28 -> V_57 ;
F_2 ( V_5 , ( char * ) V_24 + V_28 -> V_58 ,
V_31 -> V_56 , L_1 , V_21 -> V_9 ) ;
}
F_5 ( V_5 -> V_59 , V_19 , V_31 , sizeof( * V_31 ) ) ;
F_9 ( & V_5 -> V_34 , V_33 ) ;
}
void F_10 ( char * V_18 , struct V_20 * V_21 )
{
struct V_4 * V_5 = V_21 -> V_22 -> V_5 ;
struct V_60 * V_61 = V_21 -> V_6 ;
struct V_30 * V_31 = & V_5 -> V_32 ;
unsigned long V_33 ;
F_8 ( & V_5 -> V_34 , V_33 ) ;
memset ( V_31 , 0 , sizeof( * V_31 ) ) ;
memcpy ( V_31 -> V_18 , V_18 , V_15 ) ;
V_31 -> V_35 = V_62 ;
V_31 -> V_14 = V_21 -> V_9 ;
V_31 -> V_37 = V_21 -> V_38 ;
V_31 -> V_39 = V_21 -> V_40 ;
if ( ! V_61 )
goto log;
V_31 -> V_43 . V_63 . V_64 = V_61 -> V_64 ;
V_31 -> V_43 . V_63 . V_65 = V_61 -> V_65 ;
V_31 -> V_43 . V_63 . V_66 = F_11 ( V_61 -> V_66 ) ;
V_31 -> V_43 . V_63 . V_67 = V_61 -> V_68 ;
memcpy ( & V_31 -> V_43 . V_63 . V_69 , & V_61 -> V_69 ,
sizeof( V_31 -> V_43 . V_63 . V_69 ) ) ;
V_31 -> V_56 = ( ! V_61 -> V_7 ) ? 0 : V_61 -> V_7 -
F_12 ( struct V_60 , V_70 ) ;
if ( V_31 -> V_56 )
F_2 ( V_5 , V_61 -> V_70 . V_6 , V_31 -> V_56 ,
L_2 , V_21 -> V_9 ) ;
log:
F_5 ( V_5 -> V_59 , 2 , V_31 , sizeof( * V_31 ) ) ;
F_9 ( & V_5 -> V_34 , V_33 ) ;
}
void F_13 ( char * V_18 , struct V_20 * V_21 )
{
struct V_4 * V_5 = V_21 -> V_22 -> V_5 ;
struct V_30 * V_31 = & V_5 -> V_32 ;
struct V_60 * V_71 = V_21 -> V_6 ;
unsigned long V_33 ;
F_8 ( & V_5 -> V_34 , V_33 ) ;
memset ( V_31 , 0 , sizeof( * V_31 ) ) ;
memcpy ( V_31 -> V_18 , V_18 , V_15 ) ;
V_31 -> V_35 = V_72 ;
V_31 -> V_14 = V_21 -> V_9 ;
V_31 -> V_37 = V_21 -> V_38 ;
V_31 -> V_39 = V_21 -> V_40 ;
memcpy ( & V_31 -> V_43 . V_73 , & V_71 -> V_70 . V_74 ,
sizeof( struct V_75 ) ) ;
F_5 ( V_5 -> V_59 , 1 , V_31 , sizeof( * V_31 ) ) ;
F_9 ( & V_5 -> V_34 , V_33 ) ;
}
void F_14 ( struct V_76 * V_22 , T_2 V_9 , T_1 V_77 ,
void * * V_10 )
{
struct V_4 * V_5 = V_22 -> V_5 ;
struct V_2 * V_70 = & V_5 -> V_11 ;
unsigned long V_33 ;
T_1 V_7 ;
if ( ! V_10 )
return;
F_8 ( & V_5 -> V_13 , V_33 ) ;
memset ( V_70 , 0 , sizeof( * V_70 ) ) ;
memcpy ( V_70 -> V_8 , L_3 , 7 ) ;
V_70 -> V_14 = V_9 ;
V_70 -> V_17 = 0 ;
V_7 = F_4 ( ( T_1 ) sizeof( struct V_78 ) ,
( T_1 ) V_3 ) ;
while ( V_70 -> V_17 < V_77 && ( char * ) V_10 [ V_70 -> V_17 ] ) {
memcpy ( V_70 -> V_6 , ( char * ) V_10 [ V_70 -> V_17 ] , V_7 ) ;
F_5 ( V_5 -> V_16 , 1 , V_70 , F_1 ( V_7 ) ) ;
V_70 -> V_17 ++ ;
}
F_9 ( & V_5 -> V_13 , V_33 ) ;
}
void F_15 ( char * V_18 , struct V_76 * V_22 )
{
struct V_4 * V_5 = V_22 -> V_5 ;
struct V_30 * V_31 = & V_5 -> V_32 ;
unsigned long V_33 ;
F_8 ( & V_5 -> V_34 , V_33 ) ;
memset ( V_31 , 0 , sizeof( * V_31 ) ) ;
memcpy ( V_31 -> V_18 , V_18 , V_15 ) ;
V_31 -> V_35 = V_79 ;
F_5 ( V_5 -> V_59 , 1 , V_31 , sizeof( * V_31 ) ) ;
F_9 ( & V_5 -> V_34 , V_33 ) ;
}
static void F_16 ( struct V_80 * V_31 ,
struct V_76 * V_22 ,
struct V_81 * V_82 ,
struct V_83 * V_84 )
{
V_31 -> V_85 = F_17 ( & V_22 -> V_38 ) ;
if ( V_82 ) {
V_31 -> V_86 = F_17 ( & V_82 -> V_38 ) ;
V_31 -> V_87 = V_82 -> V_87 ;
V_31 -> V_66 = V_82 -> V_66 ;
}
if ( V_84 ) {
V_31 -> V_88 = F_17 ( & F_18 ( V_84 ) -> V_38 ) ;
V_31 -> V_67 = F_19 ( V_84 ) ;
} else
V_31 -> V_67 = V_89 ;
}
void F_20 ( char * V_18 , struct V_76 * V_22 ,
struct V_81 * V_82 , struct V_83 * V_84 ,
T_3 V_90 , T_3 V_91 )
{
struct V_4 * V_5 = V_22 -> V_5 ;
struct V_80 * V_31 = & V_5 -> V_92 ;
struct V_93 * V_94 ;
unsigned long V_33 ;
F_8 ( & V_5 -> V_95 , V_33 ) ;
memset ( V_31 , 0 , sizeof( * V_31 ) ) ;
V_31 -> V_35 = V_96 ;
memcpy ( V_31 -> V_18 , V_18 , V_15 ) ;
F_16 ( V_31 , V_22 , V_82 , V_84 ) ;
F_21 (entry, &adapter->erp_ready_head)
V_31 -> V_43 . V_97 . V_98 ++ ;
F_21 (entry, &adapter->erp_running_head)
V_31 -> V_43 . V_97 . V_99 ++ ;
V_31 -> V_43 . V_97 . V_90 = V_90 ;
V_31 -> V_43 . V_97 . V_91 = V_91 ;
F_5 ( V_5 -> V_31 , 1 , V_31 , sizeof( * V_31 ) ) ;
F_9 ( & V_5 -> V_95 , V_33 ) ;
}
void F_22 ( int V_19 , char * V_18 , struct V_100 * V_101 )
{
struct V_4 * V_5 = V_101 -> V_22 -> V_5 ;
struct V_80 * V_31 = & V_5 -> V_92 ;
unsigned long V_33 ;
F_8 ( & V_5 -> V_95 , V_33 ) ;
memset ( V_31 , 0 , sizeof( * V_31 ) ) ;
V_31 -> V_35 = V_102 ;
memcpy ( V_31 -> V_18 , V_18 , V_15 ) ;
F_16 ( V_31 , V_101 -> V_22 , V_101 -> V_82 , V_101 -> V_84 ) ;
V_31 -> V_43 . V_103 . V_14 = V_101 -> V_14 ;
V_31 -> V_43 . V_103 . V_104 = V_101 -> V_38 ;
V_31 -> V_43 . V_103 . V_105 = V_101 -> V_106 ;
V_31 -> V_43 . V_103 . V_107 = V_101 -> V_108 ;
if ( V_101 -> V_84 )
V_31 -> V_43 . V_103 . V_109 =
F_17 ( & F_18 ( V_101 -> V_84 ) -> V_110 ) ;
else if ( V_101 -> V_82 )
V_31 -> V_43 . V_103 . V_109 = F_17 ( & V_101 -> V_82 -> V_110 ) ;
else
V_31 -> V_43 . V_103 . V_109 = F_17 ( & V_101 -> V_22 -> V_110 ) ;
F_5 ( V_5 -> V_31 , V_19 , V_31 , sizeof( * V_31 ) ) ;
F_9 ( & V_5 -> V_95 , V_33 ) ;
}
void F_23 ( char * V_18 , struct V_100 * V_101 )
{
F_22 ( 1 , V_18 , V_101 ) ;
}
void F_24 ( char * V_18 , struct V_111 * V_112 ,
T_2 V_9 )
{
struct V_4 * V_5 = V_112 -> V_22 -> V_5 ;
struct V_80 * V_31 = & V_5 -> V_92 ;
unsigned long V_33 ;
F_8 ( & V_5 -> V_95 , V_33 ) ;
memset ( V_31 , 0 , sizeof( * V_31 ) ) ;
V_31 -> V_35 = V_102 ;
memcpy ( V_31 -> V_18 , V_18 , V_15 ) ;
V_31 -> V_86 = V_112 -> V_38 ;
V_31 -> V_66 = V_112 -> V_66 ;
V_31 -> V_67 = V_89 ;
V_31 -> V_43 . V_103 . V_14 = V_9 ;
V_31 -> V_43 . V_103 . V_104 = ~ 0 ;
V_31 -> V_43 . V_103 . V_105 = ~ 0 ;
V_31 -> V_43 . V_103 . V_107 = ~ 0 ;
V_31 -> V_43 . V_103 . V_109 = ~ 0 ;
F_5 ( V_5 -> V_31 , 1 , V_31 , sizeof( * V_31 ) ) ;
F_9 ( & V_5 -> V_95 , V_33 ) ;
}
static inline
void F_25 ( char * V_18 , struct V_4 * V_5 ,
char * V_113 , struct V_114 * V_115 , T_3 V_35 , T_1 V_116 ,
T_2 V_9 , T_4 V_66 , T_1 V_117 )
{
struct F_25 * V_31 = & V_5 -> V_118 ;
T_1 V_119 ;
unsigned long V_33 ;
struct V_2 * V_70 = & V_5 -> V_11 ;
T_1 V_120 = 0 ;
F_8 ( & V_5 -> V_121 , V_33 ) ;
memset ( V_31 , 0 , sizeof( * V_31 ) ) ;
V_31 -> V_35 = V_35 ;
V_31 -> V_14 = V_9 ;
V_31 -> V_66 = V_66 ;
memcpy ( V_31 -> V_18 , V_18 , V_15 ) ;
V_31 -> V_56 = V_116 ;
if ( ! V_115 )
goto V_122;
V_119 = F_26 (unsigned int, sg->length, ZFCP_DBF_SAN_MAX_PAYLOAD) ;
memcpy ( V_31 -> V_70 , F_27 ( V_115 ) , V_119 ) ;
if ( V_116 <= V_119 )
goto V_122;
F_3 ( & V_5 -> V_13 ) ;
memset ( V_70 , 0 , sizeof( * V_70 ) ) ;
memcpy ( V_70 -> V_8 , V_113 , V_15 ) ;
V_70 -> V_14 = V_9 ;
V_70 -> V_17 = 0 ;
for (; V_115 && V_120 < V_117 ; V_115 = F_28 ( V_115 ) ) {
T_1 V_123 , V_1 = 0 ;
while ( V_1 < V_115 -> V_7 && V_120 < V_117 ) {
V_123 = F_4 ( ( T_1 ) V_3 ,
( T_1 ) ( V_115 -> V_7 - V_1 ) ) ;
memcpy ( V_70 -> V_6 , F_27 ( V_115 ) + V_1 , V_123 ) ;
F_5 ( V_5 -> V_16 , 1 , V_70 ,
F_1 ( V_123 ) ) ;
V_70 -> V_17 ++ ;
V_1 += V_123 ;
V_120 += V_123 ;
}
}
F_6 ( & V_5 -> V_13 ) ;
V_122:
F_5 ( V_5 -> V_124 , 1 , V_31 , sizeof( * V_31 ) ) ;
F_9 ( & V_5 -> V_121 , V_33 ) ;
}
void F_29 ( char * V_18 , struct V_20 * V_125 , T_4 V_66 )
{
struct V_4 * V_5 = V_125 -> V_22 -> V_5 ;
struct V_126 * V_127 = V_125 -> V_6 ;
T_1 V_7 ;
V_7 = ( T_1 ) F_30 ( V_127 -> V_21 ) ;
F_25 ( V_18 , V_5 , L_4 , V_127 -> V_21 , V_128 ,
V_7 , V_125 -> V_9 , V_66 , V_7 ) ;
}
static T_1 F_31 ( char * V_18 ,
struct V_20 * V_125 ,
T_1 V_116 )
{
struct V_126 * V_127 = V_125 -> V_6 ;
struct V_129 * V_130 = F_27 ( V_127 -> V_21 ) ;
struct V_131 * V_132 = (struct V_131 * ) ( V_130 + 1 ) ;
struct V_114 * V_133 = V_127 -> V_134 ;
struct V_135 * V_136 ;
int V_137 , V_138 , V_139 = 0 ;
if ( ! ( memcmp ( V_18 , L_5 , 7 ) == 0
&& V_127 -> V_66 == V_140
&& V_130 -> V_141 == V_142
&& V_130 -> V_143 [ 0 ] == 0
&& V_130 -> V_143 [ 1 ] == 0
&& V_130 -> V_143 [ 2 ] == 0
&& V_130 -> V_144 == V_145
&& V_130 -> V_146 == V_147
&& V_130 -> V_148 == 0
&& V_130 -> V_149 == 0
&& V_130 -> V_150 == V_151
&& V_130 -> V_152 == 0
&& V_130 -> V_153 == 0
&& V_130 -> V_154 == 0
&& V_130 -> V_155 == 0
&& V_132 -> V_156 == 0
&& V_132 -> V_157 == 0
&& V_132 -> V_158 == 0
&& V_132 -> V_159 == V_160 ) )
return V_116 ;
V_136 = F_27 ( V_133 ) ;
V_137 = ( V_130 -> V_161 * 4 / sizeof( struct V_135 ) )
+ 1 ;
for ( V_138 = 1 ; V_138 < V_137 && ! V_139 ; V_138 ++ ) {
if ( V_138 % ( V_162 + 1 ) )
V_136 ++ ;
else
V_136 = F_27 ( ++ V_133 ) ;
V_139 = V_136 -> V_163 & V_164 ;
}
V_116 = F_4 ( V_116 , ( T_1 ) ( V_138 * sizeof( struct V_135 ) ) ) ;
return V_116 ;
}
void F_32 ( char * V_18 , struct V_20 * V_125 )
{
struct V_4 * V_5 = V_125 -> V_22 -> V_5 ;
struct V_126 * V_127 = V_125 -> V_6 ;
T_1 V_7 ;
V_7 = ( T_1 ) F_30 ( V_127 -> V_134 ) ;
F_25 ( V_18 , V_5 , L_6 , V_127 -> V_134 , V_165 ,
V_7 , V_125 -> V_9 , V_127 -> V_66 ,
F_31 ( V_18 , V_125 , V_7 ) ) ;
}
void F_33 ( char * V_18 , struct V_20 * V_125 )
{
struct V_4 * V_5 = V_125 -> V_22 -> V_5 ;
struct V_60 * V_61 =
(struct V_60 * ) V_125 -> V_6 ;
T_1 V_7 ;
struct V_114 V_115 ;
V_7 = ( T_1 ) ( V_61 -> V_7 -
F_12 ( struct V_60 , V_70 ) ) ;
F_34 ( & V_115 , V_61 -> V_70 . V_6 , V_7 ) ;
F_25 ( V_18 , V_5 , L_7 , & V_115 , V_166 , V_7 ,
V_125 -> V_9 , F_11 ( V_61 -> V_66 ) , V_7 ) ;
}
void F_35 ( char * V_18 , int V_19 , struct V_167 * V_168 ,
struct V_20 * V_125 )
{
struct V_76 * V_22 =
(struct V_76 * ) V_168 -> V_169 -> V_170 -> V_171 [ 0 ] ;
struct V_4 * V_5 = V_22 -> V_5 ;
struct F_35 * V_31 = & V_5 -> V_172 ;
struct V_173 * V_174 ;
struct V_175 * V_176 ;
unsigned long V_33 ;
F_8 ( & V_5 -> V_177 , V_33 ) ;
memset ( V_31 , 0 , sizeof( * V_31 ) ) ;
memcpy ( V_31 -> V_18 , V_18 , V_15 ) ;
V_31 -> V_35 = V_178 ;
V_31 -> V_179 = V_168 -> V_180 ;
V_31 -> V_181 = V_168 -> V_182 ;
V_31 -> V_183 = V_168 -> V_184 ;
V_31 -> V_185 = V_168 -> V_169 -> V_35 ;
V_31 -> V_186 = ( T_4 ) V_168 -> V_169 -> V_67 ;
V_31 -> V_187 = ( unsigned long ) V_168 -> V_187 ;
memcpy ( V_31 -> V_188 , V_168 -> V_189 ,
F_4 ( ( int ) V_168 -> V_190 , V_191 ) ) ;
if ( V_125 ) {
V_31 -> V_14 = V_125 -> V_9 ;
V_174 = (struct V_173 * )
& ( V_125 -> V_25 -> V_192 . V_193 . V_174 ) ;
memcpy ( & V_31 -> V_174 , V_174 , V_194 ) ;
if ( V_174 -> V_134 . V_195 & V_196 ) {
V_176 = (struct V_175 * ) & V_174 [ 1 ] ;
V_31 -> V_176 = V_176 -> V_197 ;
}
if ( V_174 -> V_134 . V_195 & V_198 ) {
V_31 -> V_56 = F_4 ( ( T_1 ) V_199 ,
( T_1 ) V_3 ) ;
F_2 ( V_5 , V_168 -> V_200 , V_31 -> V_56 ,
L_8 , V_125 -> V_9 ) ;
}
}
F_5 ( V_5 -> V_201 , V_19 , V_31 , sizeof( * V_31 ) ) ;
F_9 ( & V_5 -> V_177 , V_33 ) ;
}
static T_5 * F_36 ( const char * V_202 , int V_203 , int V_204 )
{
struct V_205 * V_206 ;
V_206 = F_37 ( V_202 , V_203 , 1 , V_204 ) ;
if ( ! V_206 )
return NULL ;
F_38 ( V_206 , & V_207 ) ;
F_39 ( V_206 , V_208 ) ;
return V_206 ;
}
static void F_40 ( struct V_4 * V_5 )
{
if ( ! V_5 )
return;
F_41 ( V_5 -> V_201 ) ;
F_41 ( V_5 -> V_124 ) ;
F_41 ( V_5 -> V_59 ) ;
F_41 ( V_5 -> V_16 ) ;
F_41 ( V_5 -> V_31 ) ;
F_42 ( V_5 ) ;
}
int F_43 ( struct V_76 * V_22 )
{
char V_202 [ V_209 ] ;
struct V_4 * V_5 ;
V_5 = F_44 ( sizeof( struct V_4 ) , V_210 ) ;
if ( ! V_5 )
return - V_211 ;
F_45 ( & V_5 -> V_13 ) ;
F_45 ( & V_5 -> V_34 ) ;
F_45 ( & V_5 -> V_121 ) ;
F_45 ( & V_5 -> V_177 ) ;
F_45 ( & V_5 -> V_95 ) ;
sprintf ( V_202 , L_9 , F_46 ( & V_22 -> V_212 -> V_213 ) ) ;
V_5 -> V_31 = F_36 ( V_202 , V_214 , sizeof( struct V_80 ) ) ;
if ( ! V_5 -> V_31 )
goto V_215;
sprintf ( V_202 , L_10 , F_46 ( & V_22 -> V_212 -> V_213 ) ) ;
V_5 -> V_59 = F_36 ( V_202 , V_214 , sizeof( struct V_30 ) ) ;
if ( ! V_5 -> V_59 )
goto V_215;
sprintf ( V_202 , L_11 , F_46 ( & V_22 -> V_212 -> V_213 ) ) ;
V_5 -> V_16 = F_36 ( V_202 , V_214 * 2 , sizeof( struct V_2 ) ) ;
if ( ! V_5 -> V_16 )
goto V_215;
sprintf ( V_202 , L_12 , F_46 ( & V_22 -> V_212 -> V_213 ) ) ;
V_5 -> V_124 = F_36 ( V_202 , V_214 , sizeof( struct F_25 ) ) ;
if ( ! V_5 -> V_124 )
goto V_215;
sprintf ( V_202 , L_13 , F_46 ( & V_22 -> V_212 -> V_213 ) ) ;
V_5 -> V_201 = F_36 ( V_202 , V_214 , sizeof( struct F_35 ) ) ;
if ( ! V_5 -> V_201 )
goto V_215;
V_22 -> V_5 = V_5 ;
return 0 ;
V_215:
F_40 ( V_5 ) ;
return - V_211 ;
}
void F_47 ( struct V_76 * V_22 )
{
struct V_4 * V_5 = V_22 -> V_5 ;
V_22 -> V_5 = NULL ;
F_40 ( V_5 ) ;
}
