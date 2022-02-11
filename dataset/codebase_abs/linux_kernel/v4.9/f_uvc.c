void F_1 ( unsigned int V_1 )
{
V_2 = V_1 ;
}
static void
F_2 ( struct V_3 * V_4 , struct V_5 * V_6 )
{
struct V_7 * V_8 = V_6 -> V_9 ;
struct V_10 V_10 ;
struct V_11 * V_11 = ( void * ) & V_10 . V_12 . V_13 ;
if ( V_8 -> V_14 ) {
V_8 -> V_14 = 0 ;
memset ( & V_10 , 0 , sizeof( V_10 ) ) ;
V_10 . type = V_15 ;
V_11 -> V_13 . V_16 = V_6 -> V_17 ;
memcpy ( & V_11 -> V_13 . V_13 , V_6 -> V_18 , V_6 -> V_17 ) ;
F_3 ( & V_8 -> V_19 , & V_10 ) ;
}
}
static int
F_4 ( struct V_20 * V_21 , const struct V_22 * V_23 )
{
struct V_7 * V_8 = F_5 ( V_21 ) ;
struct V_10 V_10 ;
struct V_11 * V_11 = ( void * ) & V_10 . V_12 . V_13 ;
if ( ( V_23 -> V_24 & V_25 ) != V_26 ) {
F_6 ( V_21 -> V_27 -> V_28 , L_1 ) ;
return - V_29 ;
}
if ( F_7 ( V_23 -> V_30 ) > V_31 )
return - V_29 ;
V_8 -> V_14 = ! ( V_23 -> V_24 & V_32 ) ;
V_8 -> V_33 = F_7 ( V_23 -> V_30 ) ;
memset ( & V_10 , 0 , sizeof( V_10 ) ) ;
V_10 . type = V_34 ;
memcpy ( & V_11 -> V_6 , V_23 , sizeof( V_11 -> V_6 ) ) ;
F_3 ( & V_8 -> V_19 , & V_10 ) ;
if ( V_8 -> V_14 && V_8 -> V_33 ) {
V_8 -> V_35 -> V_16 = V_8 -> V_33 ;
return F_8 ( V_8 -> V_36 . V_27 -> V_28 -> V_37 -> V_38 ,
V_8 -> V_35 , V_39 ) ;
}
return 0 ;
}
void F_9 ( struct V_7 * V_8 )
{
struct V_40 * V_28 = V_8 -> V_36 . V_27 -> V_28 ;
F_10 ( V_28 ) ;
}
static int
F_11 ( struct V_20 * V_21 , unsigned V_41 )
{
struct V_7 * V_8 = F_5 ( V_21 ) ;
F_6 ( V_21 -> V_27 -> V_28 , L_2 , V_41 ) ;
if ( V_41 == V_8 -> V_42 )
return 0 ;
else if ( V_41 != V_8 -> V_43 )
return - V_29 ;
else
return V_8 -> V_44 . V_4 -> V_45 ? 1 : 0 ;
}
static int
F_12 ( struct V_20 * V_21 , unsigned V_41 , unsigned V_46 )
{
struct V_7 * V_8 = F_5 ( V_21 ) ;
struct V_40 * V_28 = V_21 -> V_27 -> V_28 ;
struct V_10 V_10 ;
struct V_11 * V_11 = ( void * ) & V_10 . V_12 . V_13 ;
int V_47 ;
F_6 ( V_28 , L_3 , V_41 , V_46 ) ;
if ( V_41 == V_8 -> V_42 ) {
if ( V_46 )
return - V_29 ;
F_6 ( V_28 , L_4 ) ;
F_13 ( V_8 -> V_48 ) ;
if ( ! V_8 -> V_48 -> V_49 )
if ( F_14 ( V_28 -> V_37 , V_21 , V_8 -> V_48 ) )
return - V_29 ;
F_15 ( V_8 -> V_48 ) ;
if ( V_8 -> V_50 == V_51 ) {
memset ( & V_10 , 0 , sizeof( V_10 ) ) ;
V_10 . type = V_52 ;
V_11 -> V_53 = V_28 -> V_37 -> V_53 ;
F_3 ( & V_8 -> V_19 , & V_10 ) ;
V_8 -> V_50 = V_54 ;
}
return 0 ;
}
if ( V_41 != V_8 -> V_43 )
return - V_29 ;
switch ( V_46 ) {
case 0 :
if ( V_8 -> V_50 != V_55 )
return 0 ;
if ( V_8 -> V_44 . V_4 )
F_13 ( V_8 -> V_44 . V_4 ) ;
memset ( & V_10 , 0 , sizeof( V_10 ) ) ;
V_10 . type = V_56 ;
F_3 ( & V_8 -> V_19 , & V_10 ) ;
V_8 -> V_50 = V_54 ;
return 0 ;
case 1 :
if ( V_8 -> V_50 != V_54 )
return 0 ;
if ( ! V_8 -> V_44 . V_4 )
return - V_29 ;
F_6 ( V_28 , L_5 ) ;
F_13 ( V_8 -> V_44 . V_4 ) ;
V_47 = F_14 ( V_21 -> V_27 -> V_28 -> V_37 ,
& ( V_8 -> V_36 ) , V_8 -> V_44 . V_4 ) ;
if ( V_47 )
return V_47 ;
F_15 ( V_8 -> V_44 . V_4 ) ;
memset ( & V_10 , 0 , sizeof( V_10 ) ) ;
V_10 . type = V_57 ;
F_3 ( & V_8 -> V_19 , & V_10 ) ;
return V_58 ;
default:
return - V_29 ;
}
}
static void
F_16 ( struct V_20 * V_21 )
{
struct V_7 * V_8 = F_5 ( V_21 ) ;
struct V_10 V_10 ;
F_6 ( V_21 -> V_27 -> V_28 , L_6 ) ;
memset ( & V_10 , 0 , sizeof( V_10 ) ) ;
V_10 . type = V_59 ;
F_3 ( & V_8 -> V_19 , & V_10 ) ;
V_8 -> V_50 = V_51 ;
F_13 ( V_8 -> V_44 . V_4 ) ;
F_13 ( V_8 -> V_48 ) ;
}
void
F_17 ( struct V_7 * V_8 )
{
struct V_40 * V_28 = V_8 -> V_36 . V_27 -> V_28 ;
int V_47 ;
if ( ( V_47 = F_18 ( & V_8 -> V_36 ) ) < 0 )
F_6 ( V_28 , L_7 , V_47 ) ;
}
void
F_19 ( struct V_7 * V_8 )
{
struct V_40 * V_28 = V_8 -> V_36 . V_27 -> V_28 ;
int V_47 ;
if ( ( V_47 = F_20 ( & V_8 -> V_36 ) ) < 0 )
F_6 ( V_28 , L_8 , V_47 ) ;
}
static int
F_21 ( struct V_7 * V_8 )
{
struct V_40 * V_28 = V_8 -> V_36 . V_27 -> V_28 ;
V_8 -> V_19 . V_60 = & V_8 -> V_60 ;
V_8 -> V_19 . V_61 = & V_62 ;
V_8 -> V_19 . V_63 = & V_64 ;
V_8 -> V_19 . V_65 = V_66 ;
V_8 -> V_19 . V_67 = V_68 ;
V_8 -> V_19 . V_69 = & V_8 -> V_44 . V_70 ;
F_22 ( V_8 -> V_19 . V_71 , V_28 -> V_37 -> V_71 , sizeof( V_8 -> V_19 . V_71 ) ) ;
F_23 ( & V_8 -> V_19 , V_8 ) ;
return F_24 ( & V_8 -> V_19 , V_72 , - 1 ) ;
}
static struct V_73 * *
F_25 ( struct V_7 * V_8 , enum V_74 V_53 )
{
struct V_75 * V_76 ;
struct V_77 * V_78 ;
const struct V_79 * const * V_80 ;
const struct V_79 * const * V_81 ;
const struct V_73 * const * V_82 ;
const struct V_73 * const * V_83 ;
struct V_73 * * V_84 ;
struct V_73 * * V_85 ;
unsigned int V_86 ;
unsigned int V_87 ;
unsigned int V_88 ;
unsigned int V_89 ;
void * V_90 ;
switch ( V_53 ) {
case V_91 :
V_80 = V_8 -> V_49 . V_92 ;
V_81 = V_8 -> V_49 . V_93 ;
V_82 = V_94 ;
break;
case V_95 :
V_80 = V_8 -> V_49 . V_96 ;
V_81 = V_8 -> V_49 . V_97 ;
V_82 = V_98 ;
break;
case V_99 :
default:
V_80 = V_8 -> V_49 . V_96 ;
V_81 = V_8 -> V_49 . V_100 ;
V_82 = V_101 ;
break;
}
if ( ! V_80 || ! V_81 )
return F_26 ( - V_102 ) ;
V_86 = 0 ;
V_87 = 0 ;
V_89 = V_103 . V_104 + V_105 . V_104
+ V_106 . V_104 + V_107 . V_104
+ V_108 . V_104 ;
if ( V_53 == V_91 ) {
V_89 += V_109 . V_104 ;
V_88 = 6 ;
} else {
V_88 = 5 ;
}
for ( V_83 = ( const struct V_73 * * ) V_80 ;
* V_83 ; ++ V_83 ) {
V_86 += ( * V_83 ) -> V_104 ;
V_89 += ( * V_83 ) -> V_104 ;
V_88 ++ ;
}
for ( V_83 = ( const struct V_73 * * ) V_81 ;
* V_83 ; ++ V_83 ) {
V_87 += ( * V_83 ) -> V_104 ;
V_89 += ( * V_83 ) -> V_104 ;
V_88 ++ ;
}
for ( V_83 = V_82 ; * V_83 ; ++ V_83 ) {
V_89 += ( * V_83 ) -> V_104 ;
V_88 ++ ;
}
V_90 = F_27 ( ( V_88 + 1 ) * sizeof( * V_83 ) + V_89 , V_110 ) ;
if ( V_90 == NULL )
return NULL ;
V_85 = V_90 ;
V_84 = V_90 ;
V_90 += ( V_88 + 1 ) * sizeof( * V_83 ) ;
F_28 ( V_90 , V_84 , & V_103 ) ;
F_28 ( V_90 , V_84 , & V_105 ) ;
V_78 = V_90 ;
F_29 ( V_90 , V_84 ,
( const struct V_73 * * ) V_80 ) ;
V_78 -> V_111 = F_30 ( V_86 ) ;
V_78 -> V_112 = 1 ;
V_78 -> V_113 [ 0 ] = V_8 -> V_43 ;
F_28 ( V_90 , V_84 , & V_106 ) ;
if ( V_53 == V_91 )
F_28 ( V_90 , V_84 , & V_109 ) ;
F_28 ( V_90 , V_84 , & V_107 ) ;
F_28 ( V_90 , V_84 , & V_108 ) ;
V_76 = V_90 ;
F_29 ( V_90 , V_84 ,
( const struct V_73 * * ) V_81 ) ;
V_76 -> V_111 = F_30 ( V_87 ) ;
V_76 -> V_114 = V_8 -> V_44 . V_4 -> V_115 ;
F_29 ( V_90 , V_84 , V_82 ) ;
* V_84 = NULL ;
return V_85 ;
}
static int
F_31 ( struct V_116 * V_117 , struct V_20 * V_21 )
{
struct V_40 * V_28 = V_117 -> V_28 ;
struct V_7 * V_8 = F_5 ( V_21 ) ;
struct V_118 * V_119 ;
unsigned int V_120 ;
unsigned int V_121 ;
struct V_3 * V_4 ;
struct V_122 * V_123 ;
int V_47 = - V_29 ;
F_6 ( V_28 , L_9 ) ;
V_123 = F_32 ( V_21 -> V_124 ) ;
V_123 -> V_125 = F_33 ( V_123 -> V_125 , 1U , 16U ) ;
V_123 -> V_126 = F_33 ( V_123 -> V_126 , 1U , 3072U ) ;
V_123 -> V_127 = F_34 ( V_123 -> V_127 , 15U ) ;
if ( V_123 -> V_126 <= 1024 ) {
V_120 = 1 ;
V_121 = V_123 -> V_126 ;
} else if ( V_123 -> V_126 <= 2048 ) {
V_120 = 2 ;
V_121 = V_123 -> V_126 / 2 ;
} else {
V_120 = 3 ;
V_121 = V_123 -> V_126 / 3 ;
}
V_128 . V_129 =
F_30 ( F_34 ( V_123 -> V_126 , 1023U ) ) ;
V_128 . V_130 = V_123 -> V_125 ;
V_131 . V_129 =
F_30 ( V_121 | ( ( V_120 - 1 ) << 11 ) ) ;
V_131 . V_130 = V_123 -> V_125 ;
V_132 . V_129 = F_30 ( V_121 ) ;
V_132 . V_130 = V_123 -> V_125 ;
V_133 . V_134 = V_120 - 1 ;
V_133 . V_135 = V_123 -> V_127 ;
V_133 . V_136 =
F_30 ( V_121 * V_120 *
V_123 -> V_127 ) ;
V_4 = F_35 ( V_28 -> V_37 , & V_106 ) ;
if ( ! V_4 ) {
F_6 ( V_28 , L_10 ) ;
goto error;
}
V_8 -> V_48 = V_4 ;
if ( F_36 ( V_117 -> V_28 -> V_37 ) )
V_4 = F_37 ( V_28 -> V_37 , & V_132 ,
& V_133 ) ;
else if ( F_38 ( V_28 -> V_37 ) )
V_4 = F_35 ( V_28 -> V_37 , & V_131 ) ;
else
V_4 = F_35 ( V_28 -> V_37 , & V_128 ) ;
if ( ! V_4 ) {
F_6 ( V_28 , L_11 ) ;
goto error;
}
V_8 -> V_44 . V_4 = V_4 ;
V_128 . V_114 = V_8 -> V_44 . V_4 -> V_115 ;
V_131 . V_114 = V_8 -> V_44 . V_4 -> V_115 ;
V_132 . V_114 = V_8 -> V_44 . V_4 -> V_115 ;
V_119 = F_39 ( V_28 , V_137 ,
F_40 ( V_138 ) ) ;
if ( F_41 ( V_119 ) ) {
V_47 = F_42 ( V_119 ) ;
goto error;
}
V_103 . V_139 = V_119 [ V_140 ] . V_141 ;
V_105 . V_142 = V_119 [ V_140 ] . V_141 ;
V_47 = V_119 [ V_143 ] . V_141 ;
V_108 . V_142 = V_47 ;
V_144 . V_142 = V_47 ;
if ( ( V_47 = F_43 ( V_117 , V_21 ) ) < 0 )
goto error;
V_103 . V_145 = V_47 ;
V_105 . V_146 = V_47 ;
V_8 -> V_42 = V_47 ;
if ( ( V_47 = F_43 ( V_117 , V_21 ) ) < 0 )
goto error;
V_108 . V_146 = V_47 ;
V_144 . V_146 = V_47 ;
V_8 -> V_43 = V_47 ;
V_21 -> V_147 = F_25 ( V_8 , V_99 ) ;
if ( F_41 ( V_21 -> V_147 ) ) {
V_47 = F_42 ( V_21 -> V_147 ) ;
V_21 -> V_147 = NULL ;
goto error;
}
if ( F_38 ( V_28 -> V_37 ) ) {
V_21 -> V_148 = F_25 ( V_8 , V_95 ) ;
if ( F_41 ( V_21 -> V_148 ) ) {
V_47 = F_42 ( V_21 -> V_148 ) ;
V_21 -> V_148 = NULL ;
goto error;
}
}
if ( F_36 ( V_117 -> V_28 -> V_37 ) ) {
V_21 -> V_149 = F_25 ( V_8 , V_91 ) ;
if ( F_41 ( V_21 -> V_149 ) ) {
V_47 = F_42 ( V_21 -> V_149 ) ;
V_21 -> V_149 = NULL ;
goto error;
}
}
V_8 -> V_35 = F_44 ( V_28 -> V_37 -> V_38 , V_110 ) ;
V_8 -> V_150 = F_27 ( V_31 , V_110 ) ;
if ( V_8 -> V_35 == NULL || V_8 -> V_150 == NULL ) {
V_47 = - V_151 ;
goto error;
}
V_8 -> V_35 -> V_18 = V_8 -> V_150 ;
V_8 -> V_35 -> V_152 = F_2 ;
V_8 -> V_35 -> V_9 = V_8 ;
if ( F_45 ( & V_28 -> V_37 -> V_153 , & V_8 -> V_60 ) ) {
F_46 ( V_154 L_12 ) ;
goto error;
}
V_47 = F_47 ( & V_8 -> V_44 ) ;
if ( V_47 < 0 )
goto error;
V_47 = F_21 ( V_8 ) ;
if ( V_47 < 0 ) {
F_46 ( V_154 L_13 ) ;
goto error;
}
return 0 ;
error:
F_48 ( & V_8 -> V_60 ) ;
if ( V_8 -> V_35 )
F_49 ( V_28 -> V_37 -> V_38 , V_8 -> V_35 ) ;
F_50 ( V_8 -> V_150 ) ;
F_51 ( V_21 ) ;
return V_47 ;
}
static void F_52 ( struct V_155 * V_21 )
{
struct V_122 * V_123 = F_32 ( V_21 ) ;
F_53 ( & V_123 -> V_69 ) ;
F_50 ( V_123 ) ;
}
static struct V_155 * F_54 ( void )
{
struct V_122 * V_123 ;
struct V_156 * V_157 ;
struct V_158 * V_159 ;
struct V_160 * V_161 ;
struct V_162 * V_163 ;
struct V_79 * * V_164 ;
V_123 = F_55 ( sizeof( * V_123 ) , V_110 ) ;
if ( ! V_123 )
return F_26 ( - V_151 ) ;
V_123 -> V_165 . V_166 = F_52 ;
F_56 ( & V_123 -> V_69 ) ;
V_157 = & V_123 -> V_167 ;
V_157 -> V_104 = F_57 ( 3 ) ;
V_157 -> V_168 = V_169 ;
V_157 -> V_170 = V_171 ;
V_157 -> V_172 = 1 ;
V_157 -> V_173 = F_30 ( 0x0201 ) ;
V_157 -> V_174 = 0 ;
V_157 -> V_175 = 0 ;
V_157 -> V_176 = F_30 ( 0 ) ;
V_157 -> V_177 = F_30 ( 0 ) ;
V_157 -> V_178 = F_30 ( 0 ) ;
V_157 -> V_179 = 3 ;
V_157 -> V_180 [ 0 ] = 2 ;
V_157 -> V_180 [ 1 ] = 0 ;
V_157 -> V_180 [ 2 ] = 0 ;
V_159 = & V_123 -> V_181 ;
V_159 -> V_104 = F_58 ( 2 ) ;
V_159 -> V_168 = V_169 ;
V_159 -> V_170 = V_182 ;
V_159 -> V_183 = 2 ;
V_159 -> V_184 = 1 ;
V_159 -> V_185 = F_30 ( 16 * 1024 ) ;
V_159 -> V_179 = 2 ;
V_159 -> V_180 [ 0 ] = 1 ;
V_159 -> V_180 [ 1 ] = 0 ;
V_159 -> V_186 = 0 ;
V_161 = & V_123 -> V_187 ;
V_161 -> V_104 = V_188 ;
V_161 -> V_168 = V_169 ;
V_161 -> V_170 = V_189 ;
V_161 -> V_172 = 3 ;
V_161 -> V_173 = F_30 ( 0x0101 ) ;
V_161 -> V_174 = 0 ;
V_161 -> V_184 = 2 ;
V_161 -> V_175 = 0 ;
V_163 = & V_123 -> V_190 ;
V_163 -> V_104 = V_191 ;
V_163 -> V_168 = V_169 ;
V_163 -> V_170 = V_192 ;
V_163 -> V_193 = 1 ;
V_163 -> V_194 = 1 ;
V_163 -> V_195 = 4 ;
V_164 = V_123 -> V_196 ;
V_164 [ 0 ] = NULL ;
V_164 [ 1 ] = (struct V_79 * ) V_157 ;
V_164 [ 2 ] = (struct V_79 * ) V_159 ;
V_164 [ 3 ] = (struct V_79 * ) V_161 ;
V_164 [ 4 ] = NULL ;
V_123 -> V_96 =
( const struct V_79 * const * ) V_164 ;
V_164 = V_123 -> V_197 ;
V_164 [ 0 ] = NULL ;
V_164 [ 1 ] = (struct V_79 * ) V_157 ;
V_164 [ 2 ] = (struct V_79 * ) V_159 ;
V_164 [ 3 ] = (struct V_79 * ) V_161 ;
V_164 [ 4 ] = NULL ;
V_123 -> V_92 =
( const struct V_79 * const * ) V_164 ;
V_123 -> V_125 = 1 ;
V_123 -> V_126 = 1024 ;
F_59 ( V_123 ) ;
return & V_123 -> V_165 ;
}
static void F_60 ( struct V_20 * V_21 )
{
struct V_7 * V_8 = F_5 ( V_21 ) ;
struct V_122 * V_123 = F_61 ( V_21 -> V_124 , struct V_122 ,
V_165 ) ;
-- V_123 -> V_198 ;
F_50 ( V_8 ) ;
}
static void F_62 ( struct V_116 * V_117 , struct V_20 * V_21 )
{
struct V_40 * V_28 = V_117 -> V_28 ;
struct V_7 * V_8 = F_5 ( V_21 ) ;
F_6 ( V_28 , L_14 , V_199 ) ;
F_63 ( & V_8 -> V_19 ) ;
F_48 ( & V_8 -> V_60 ) ;
F_49 ( V_28 -> V_37 -> V_38 , V_8 -> V_35 ) ;
F_50 ( V_8 -> V_150 ) ;
F_51 ( V_21 ) ;
}
static struct V_20 * F_64 ( struct V_155 * V_124 )
{
struct V_7 * V_8 ;
struct V_122 * V_123 ;
struct V_79 * * V_200 ;
V_8 = F_55 ( sizeof( * V_8 ) , V_110 ) ;
if ( V_8 == NULL )
return F_26 ( - V_151 ) ;
F_56 ( & V_8 -> V_44 . V_70 ) ;
V_8 -> V_50 = V_51 ;
V_123 = F_32 ( V_124 ) ;
F_65 ( & V_123 -> V_69 ) ;
if ( V_123 -> V_201 ) {
V_200 = V_123 -> V_201 ;
V_123 -> V_100 =
( const struct V_79 * const * ) V_200 ;
}
if ( V_123 -> V_202 ) {
V_200 = V_123 -> V_202 ;
V_123 -> V_97 =
( const struct V_79 * const * ) V_200 ;
}
if ( V_123 -> V_203 ) {
V_200 = V_123 -> V_203 ;
V_123 -> V_93 =
( const struct V_79 * const * ) V_200 ;
}
V_8 -> V_49 . V_96 = V_123 -> V_96 ;
V_8 -> V_49 . V_92 = V_123 -> V_92 ;
V_8 -> V_49 . V_100 = V_123 -> V_100 ;
V_8 -> V_49 . V_97 = V_123 -> V_97 ;
V_8 -> V_49 . V_93 = V_123 -> V_93 ;
++ V_123 -> V_198 ;
F_66 ( & V_123 -> V_69 ) ;
V_8 -> V_36 . V_71 = L_15 ;
V_8 -> V_36 . V_204 = F_31 ;
V_8 -> V_36 . V_205 = F_62 ;
V_8 -> V_36 . V_206 = F_11 ;
V_8 -> V_36 . V_207 = F_12 ;
V_8 -> V_36 . V_208 = F_16 ;
V_8 -> V_36 . V_209 = F_4 ;
V_8 -> V_36 . V_210 = F_60 ;
V_8 -> V_36 . V_211 = true ;
return & V_8 -> V_36 ;
}
