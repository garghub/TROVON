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
return 0 ;
}
void F_8 ( struct V_7 * V_8 )
{
struct V_35 * V_28 = V_8 -> V_36 . V_27 -> V_28 ;
F_9 ( V_28 ) ;
}
static int
F_10 ( struct V_20 * V_21 , unsigned V_37 )
{
struct V_7 * V_8 = F_5 ( V_21 ) ;
F_6 ( V_21 -> V_27 -> V_28 , L_2 , V_37 ) ;
if ( V_37 == V_8 -> V_38 )
return 0 ;
else if ( V_37 != V_8 -> V_39 )
return - V_29 ;
else
return V_8 -> V_40 . V_4 -> V_41 ? 1 : 0 ;
}
static int
F_11 ( struct V_20 * V_21 , unsigned V_37 , unsigned V_42 )
{
struct V_7 * V_8 = F_5 ( V_21 ) ;
struct V_35 * V_28 = V_21 -> V_27 -> V_28 ;
struct V_10 V_10 ;
struct V_11 * V_11 = ( void * ) & V_10 . V_12 . V_13 ;
int V_43 ;
F_6 ( V_28 , L_3 , V_37 , V_42 ) ;
if ( V_37 == V_8 -> V_38 ) {
if ( V_42 )
return - V_29 ;
if ( V_8 -> V_44 -> V_41 ) {
F_6 ( V_28 , L_4 ) ;
F_12 ( V_8 -> V_44 ) ;
V_8 -> V_44 -> V_41 = NULL ;
}
if ( ! V_8 -> V_44 -> V_45 )
if ( F_13 ( V_28 -> V_46 , V_21 , V_8 -> V_44 ) )
return - V_29 ;
F_14 ( V_8 -> V_44 ) ;
V_8 -> V_44 -> V_41 = V_8 ;
if ( V_8 -> V_47 == V_48 ) {
memset ( & V_10 , 0 , sizeof( V_10 ) ) ;
V_10 . type = V_49 ;
V_11 -> V_50 = V_28 -> V_46 -> V_50 ;
F_3 ( & V_8 -> V_19 , & V_10 ) ;
V_8 -> V_47 = V_51 ;
}
return 0 ;
}
if ( V_37 != V_8 -> V_39 )
return - V_29 ;
switch ( V_42 ) {
case 0 :
if ( V_8 -> V_47 != V_52 )
return 0 ;
if ( V_8 -> V_40 . V_4 ) {
F_12 ( V_8 -> V_40 . V_4 ) ;
V_8 -> V_40 . V_4 -> V_41 = NULL ;
}
memset ( & V_10 , 0 , sizeof( V_10 ) ) ;
V_10 . type = V_53 ;
F_3 ( & V_8 -> V_19 , & V_10 ) ;
V_8 -> V_47 = V_51 ;
return 0 ;
case 1 :
if ( V_8 -> V_47 != V_51 )
return 0 ;
if ( ! V_8 -> V_40 . V_4 )
return - V_29 ;
if ( V_8 -> V_40 . V_4 -> V_41 ) {
F_6 ( V_28 , L_5 ) ;
F_12 ( V_8 -> V_40 . V_4 ) ;
V_8 -> V_40 . V_4 -> V_41 = NULL ;
}
V_43 = F_13 ( V_21 -> V_27 -> V_28 -> V_46 ,
& ( V_8 -> V_36 ) , V_8 -> V_40 . V_4 ) ;
if ( V_43 )
return V_43 ;
F_14 ( V_8 -> V_40 . V_4 ) ;
V_8 -> V_40 . V_4 -> V_41 = V_8 ;
memset ( & V_10 , 0 , sizeof( V_10 ) ) ;
V_10 . type = V_54 ;
F_3 ( & V_8 -> V_19 , & V_10 ) ;
return V_55 ;
default:
return - V_29 ;
}
}
static void
F_15 ( struct V_20 * V_21 )
{
struct V_7 * V_8 = F_5 ( V_21 ) ;
struct V_10 V_10 ;
F_6 ( V_21 -> V_27 -> V_28 , L_6 ) ;
memset ( & V_10 , 0 , sizeof( V_10 ) ) ;
V_10 . type = V_56 ;
F_3 ( & V_8 -> V_19 , & V_10 ) ;
V_8 -> V_47 = V_48 ;
if ( V_8 -> V_40 . V_4 -> V_41 ) {
F_12 ( V_8 -> V_40 . V_4 ) ;
V_8 -> V_40 . V_4 -> V_41 = NULL ;
}
if ( V_8 -> V_44 -> V_41 ) {
F_12 ( V_8 -> V_44 ) ;
V_8 -> V_44 -> V_41 = NULL ;
}
}
void
F_16 ( struct V_7 * V_8 )
{
struct V_35 * V_28 = V_8 -> V_36 . V_27 -> V_28 ;
int V_43 ;
if ( ( V_43 = F_17 ( & V_8 -> V_36 ) ) < 0 )
F_6 ( V_28 , L_7 , V_43 ) ;
}
void
F_18 ( struct V_7 * V_8 )
{
struct V_35 * V_28 = V_8 -> V_36 . V_27 -> V_28 ;
int V_43 ;
if ( ( V_43 = F_19 ( & V_8 -> V_36 ) ) < 0 )
F_6 ( V_28 , L_8 , V_43 ) ;
}
static int
F_20 ( struct V_7 * V_8 )
{
struct V_35 * V_28 = V_8 -> V_36 . V_27 -> V_28 ;
V_8 -> V_19 . V_57 = & V_8 -> V_57 ;
V_8 -> V_19 . V_58 = & V_59 ;
V_8 -> V_19 . V_60 = & V_61 ;
V_8 -> V_19 . V_62 = V_63 ;
V_8 -> V_19 . V_64 = V_65 ;
V_8 -> V_19 . V_66 = & V_8 -> V_40 . V_67 ;
F_21 ( V_8 -> V_19 . V_68 , V_28 -> V_46 -> V_68 , sizeof( V_8 -> V_19 . V_68 ) ) ;
F_22 ( & V_8 -> V_19 , V_8 ) ;
return F_23 ( & V_8 -> V_19 , V_69 , - 1 ) ;
}
static struct V_70 * *
F_24 ( struct V_7 * V_8 , enum V_71 V_50 )
{
struct V_72 * V_73 ;
struct V_74 * V_75 ;
const struct V_76 * const * V_77 ;
const struct V_76 * const * V_78 ;
const struct V_70 * const * V_79 ;
const struct V_70 * const * V_80 ;
struct V_70 * * V_81 ;
struct V_70 * * V_82 ;
unsigned int V_83 ;
unsigned int V_84 ;
unsigned int V_85 ;
unsigned int V_86 ;
void * V_87 ;
switch ( V_50 ) {
case V_88 :
V_77 = V_8 -> V_45 . V_89 ;
V_78 = V_8 -> V_45 . V_90 ;
V_79 = V_91 ;
break;
case V_92 :
V_77 = V_8 -> V_45 . V_93 ;
V_78 = V_8 -> V_45 . V_94 ;
V_79 = V_95 ;
break;
case V_96 :
default:
V_77 = V_8 -> V_45 . V_93 ;
V_78 = V_8 -> V_45 . V_97 ;
V_79 = V_98 ;
break;
}
if ( ! V_77 || ! V_78 )
return F_25 ( - V_99 ) ;
V_83 = 0 ;
V_84 = 0 ;
V_86 = V_100 . V_101 + V_102 . V_101
+ V_103 . V_101 + V_104 . V_101
+ V_105 . V_101 ;
if ( V_50 == V_88 ) {
V_86 += V_106 . V_101 ;
V_85 = 6 ;
} else {
V_85 = 5 ;
}
for ( V_80 = ( const struct V_70 * * ) V_77 ;
* V_80 ; ++ V_80 ) {
V_83 += ( * V_80 ) -> V_101 ;
V_86 += ( * V_80 ) -> V_101 ;
V_85 ++ ;
}
for ( V_80 = ( const struct V_70 * * ) V_78 ;
* V_80 ; ++ V_80 ) {
V_84 += ( * V_80 ) -> V_101 ;
V_86 += ( * V_80 ) -> V_101 ;
V_85 ++ ;
}
for ( V_80 = V_79 ; * V_80 ; ++ V_80 ) {
V_86 += ( * V_80 ) -> V_101 ;
V_85 ++ ;
}
V_87 = F_26 ( ( V_85 + 1 ) * sizeof( * V_80 ) + V_86 , V_107 ) ;
if ( V_87 == NULL )
return NULL ;
V_82 = V_87 ;
V_81 = V_87 ;
V_87 += ( V_85 + 1 ) * sizeof( * V_80 ) ;
F_27 ( V_87 , V_81 , & V_100 ) ;
F_27 ( V_87 , V_81 , & V_102 ) ;
V_75 = V_87 ;
F_28 ( V_87 , V_81 ,
( const struct V_70 * * ) V_77 ) ;
V_75 -> V_108 = F_29 ( V_83 ) ;
V_75 -> V_109 = 1 ;
V_75 -> V_110 [ 0 ] = V_8 -> V_39 ;
F_27 ( V_87 , V_81 , & V_103 ) ;
if ( V_50 == V_88 )
F_27 ( V_87 , V_81 , & V_106 ) ;
F_27 ( V_87 , V_81 , & V_104 ) ;
F_27 ( V_87 , V_81 , & V_105 ) ;
V_73 = V_87 ;
F_28 ( V_87 , V_81 ,
( const struct V_70 * * ) V_78 ) ;
V_73 -> V_108 = F_29 ( V_84 ) ;
V_73 -> V_111 = V_8 -> V_40 . V_4 -> V_112 ;
F_28 ( V_87 , V_81 , V_79 ) ;
* V_81 = NULL ;
return V_82 ;
}
static int
F_30 ( struct V_113 * V_114 , struct V_20 * V_21 )
{
struct V_35 * V_28 = V_114 -> V_28 ;
struct V_7 * V_8 = F_5 ( V_21 ) ;
struct V_115 * V_116 ;
unsigned int V_117 ;
unsigned int V_118 ;
struct V_3 * V_4 ;
struct V_119 * V_120 ;
int V_43 = - V_29 ;
F_6 ( V_28 , L_9 ) ;
V_120 = F_31 ( V_21 -> V_121 ) ;
V_120 -> V_122 = F_32 ( V_120 -> V_122 , 1U , 16U ) ;
V_120 -> V_123 = F_32 ( V_120 -> V_123 , 1U , 3072U ) ;
V_120 -> V_124 = F_33 ( V_120 -> V_124 , 15U ) ;
if ( V_120 -> V_123 <= 1024 ) {
V_117 = 1 ;
V_118 = V_120 -> V_123 ;
} else if ( V_120 -> V_123 <= 2048 ) {
V_117 = 2 ;
V_118 = V_120 -> V_123 / 2 ;
} else {
V_117 = 3 ;
V_118 = V_120 -> V_123 / 3 ;
}
V_125 . V_126 =
F_29 ( F_33 ( V_120 -> V_123 , 1023U ) ) ;
V_125 . V_127 = V_120 -> V_122 ;
V_128 . V_126 =
F_29 ( V_118 | ( ( V_117 - 1 ) << 11 ) ) ;
V_128 . V_127 = V_120 -> V_122 ;
V_129 . V_126 = F_29 ( V_118 ) ;
V_129 . V_127 = V_120 -> V_122 ;
V_130 . V_131 = V_117 - 1 ;
V_130 . V_132 = V_120 -> V_124 ;
V_130 . V_133 =
F_29 ( V_118 * V_117 *
V_120 -> V_124 ) ;
V_4 = F_34 ( V_28 -> V_46 , & V_103 ) ;
if ( ! V_4 ) {
F_6 ( V_28 , L_10 ) ;
goto error;
}
V_8 -> V_44 = V_4 ;
V_4 -> V_41 = V_8 ;
if ( F_35 ( V_114 -> V_28 -> V_46 ) )
V_4 = F_36 ( V_28 -> V_46 , & V_129 ,
& V_130 ) ;
else if ( F_37 ( V_28 -> V_46 ) )
V_4 = F_34 ( V_28 -> V_46 , & V_128 ) ;
else
V_4 = F_34 ( V_28 -> V_46 , & V_125 ) ;
if ( ! V_4 ) {
F_6 ( V_28 , L_11 ) ;
goto error;
}
V_8 -> V_40 . V_4 = V_4 ;
V_4 -> V_41 = V_8 ;
V_125 . V_111 = V_8 -> V_40 . V_4 -> V_112 ;
V_128 . V_111 = V_8 -> V_40 . V_4 -> V_112 ;
V_129 . V_111 = V_8 -> V_40 . V_4 -> V_112 ;
V_116 = F_38 ( V_28 , V_134 ,
F_39 ( V_135 ) ) ;
if ( F_40 ( V_116 ) ) {
V_43 = F_41 ( V_116 ) ;
goto error;
}
V_100 . V_136 = V_116 [ V_137 ] . V_138 ;
V_102 . V_139 = V_116 [ V_137 ] . V_138 ;
V_43 = V_116 [ V_140 ] . V_138 ;
V_105 . V_139 = V_43 ;
V_141 . V_139 = V_43 ;
if ( ( V_43 = F_42 ( V_114 , V_21 ) ) < 0 )
goto error;
V_100 . V_142 = V_43 ;
V_102 . V_143 = V_43 ;
V_8 -> V_38 = V_43 ;
if ( ( V_43 = F_42 ( V_114 , V_21 ) ) < 0 )
goto error;
V_105 . V_143 = V_43 ;
V_141 . V_143 = V_43 ;
V_8 -> V_39 = V_43 ;
V_21 -> V_144 = F_24 ( V_8 , V_96 ) ;
if ( F_40 ( V_21 -> V_144 ) ) {
V_43 = F_41 ( V_21 -> V_144 ) ;
V_21 -> V_144 = NULL ;
goto error;
}
if ( F_37 ( V_28 -> V_46 ) ) {
V_21 -> V_145 = F_24 ( V_8 , V_92 ) ;
if ( F_40 ( V_21 -> V_145 ) ) {
V_43 = F_41 ( V_21 -> V_145 ) ;
V_21 -> V_145 = NULL ;
goto error;
}
}
if ( F_35 ( V_114 -> V_28 -> V_46 ) ) {
V_21 -> V_146 = F_24 ( V_8 , V_88 ) ;
if ( F_40 ( V_21 -> V_146 ) ) {
V_43 = F_41 ( V_21 -> V_146 ) ;
V_21 -> V_146 = NULL ;
goto error;
}
}
V_8 -> V_147 = F_43 ( V_28 -> V_46 -> V_148 , V_107 ) ;
V_8 -> V_149 = F_26 ( V_31 , V_107 ) ;
if ( V_8 -> V_147 == NULL || V_8 -> V_149 == NULL ) {
V_43 = - V_150 ;
goto error;
}
V_8 -> V_147 -> V_18 = V_8 -> V_149 ;
V_8 -> V_147 -> V_151 = F_2 ;
V_8 -> V_147 -> V_9 = V_8 ;
if ( F_44 ( & V_28 -> V_46 -> V_152 , & V_8 -> V_57 ) ) {
F_45 ( V_153 L_12 ) ;
goto error;
}
V_43 = F_46 ( & V_8 -> V_40 ) ;
if ( V_43 < 0 )
goto error;
V_43 = F_20 ( V_8 ) ;
if ( V_43 < 0 ) {
F_45 ( V_153 L_13 ) ;
goto error;
}
return 0 ;
error:
F_47 ( & V_8 -> V_57 ) ;
if ( V_8 -> V_44 )
V_8 -> V_44 -> V_41 = NULL ;
if ( V_8 -> V_40 . V_4 )
V_8 -> V_40 . V_4 -> V_41 = NULL ;
if ( V_8 -> V_147 )
F_48 ( V_28 -> V_46 -> V_148 , V_8 -> V_147 ) ;
F_49 ( V_8 -> V_149 ) ;
F_50 ( V_21 ) ;
return V_43 ;
}
static void F_51 ( struct V_154 * V_21 )
{
struct V_119 * V_120 = F_31 ( V_21 ) ;
F_52 ( & V_120 -> V_66 ) ;
F_49 ( V_120 ) ;
}
static struct V_154 * F_53 ( void )
{
struct V_119 * V_120 ;
struct V_155 * V_156 ;
struct V_157 * V_158 ;
struct V_159 * V_160 ;
struct V_161 * V_162 ;
struct V_76 * * V_163 ;
V_120 = F_54 ( sizeof( * V_120 ) , V_107 ) ;
if ( ! V_120 )
return F_25 ( - V_150 ) ;
V_120 -> V_164 . V_165 = F_51 ;
F_55 ( & V_120 -> V_66 ) ;
V_156 = & V_120 -> V_166 ;
V_156 -> V_101 = F_56 ( 3 ) ;
V_156 -> V_167 = V_168 ;
V_156 -> V_169 = V_170 ;
V_156 -> V_171 = 1 ;
V_156 -> V_172 = F_29 ( 0x0201 ) ;
V_156 -> V_173 = 0 ;
V_156 -> V_174 = 0 ;
V_156 -> V_175 = F_29 ( 0 ) ;
V_156 -> V_176 = F_29 ( 0 ) ;
V_156 -> V_177 = F_29 ( 0 ) ;
V_156 -> V_178 = 3 ;
V_156 -> V_179 [ 0 ] = 2 ;
V_156 -> V_179 [ 1 ] = 0 ;
V_156 -> V_179 [ 2 ] = 0 ;
V_158 = & V_120 -> V_180 ;
V_158 -> V_101 = F_57 ( 2 ) ;
V_158 -> V_167 = V_168 ;
V_158 -> V_169 = V_181 ;
V_158 -> V_182 = 2 ;
V_158 -> V_183 = 1 ;
V_158 -> V_184 = F_29 ( 16 * 1024 ) ;
V_158 -> V_178 = 2 ;
V_158 -> V_179 [ 0 ] = 1 ;
V_158 -> V_179 [ 1 ] = 0 ;
V_158 -> V_185 = 0 ;
V_160 = & V_120 -> V_186 ;
V_160 -> V_101 = V_187 ;
V_160 -> V_167 = V_168 ;
V_160 -> V_169 = V_188 ;
V_160 -> V_171 = 3 ;
V_160 -> V_172 = F_29 ( 0x0101 ) ;
V_160 -> V_173 = 0 ;
V_160 -> V_183 = 2 ;
V_160 -> V_174 = 0 ;
V_162 = & V_120 -> V_189 ;
V_162 -> V_101 = V_190 ;
V_162 -> V_167 = V_168 ;
V_162 -> V_169 = V_191 ;
V_162 -> V_192 = 1 ;
V_162 -> V_193 = 1 ;
V_162 -> V_194 = 4 ;
V_163 = V_120 -> V_195 ;
V_163 [ 0 ] = NULL ;
V_163 [ 1 ] = (struct V_76 * ) V_156 ;
V_163 [ 2 ] = (struct V_76 * ) V_158 ;
V_163 [ 3 ] = (struct V_76 * ) V_160 ;
V_163 [ 4 ] = NULL ;
V_120 -> V_93 =
( const struct V_76 * const * ) V_163 ;
V_163 = V_120 -> V_196 ;
V_163 [ 0 ] = NULL ;
V_163 [ 1 ] = (struct V_76 * ) V_156 ;
V_163 [ 2 ] = (struct V_76 * ) V_158 ;
V_163 [ 3 ] = (struct V_76 * ) V_160 ;
V_163 [ 4 ] = NULL ;
V_120 -> V_89 =
( const struct V_76 * const * ) V_163 ;
V_120 -> V_122 = 1 ;
V_120 -> V_123 = 1024 ;
F_58 ( V_120 ) ;
return & V_120 -> V_164 ;
}
static void F_59 ( struct V_20 * V_21 )
{
struct V_7 * V_8 = F_5 ( V_21 ) ;
struct V_119 * V_120 = F_60 ( V_21 -> V_121 , struct V_119 ,
V_164 ) ;
-- V_120 -> V_197 ;
F_49 ( V_8 ) ;
}
static void F_61 ( struct V_113 * V_114 , struct V_20 * V_21 )
{
struct V_35 * V_28 = V_114 -> V_28 ;
struct V_7 * V_8 = F_5 ( V_21 ) ;
F_6 ( V_28 , L_14 , V_198 ) ;
F_62 ( & V_8 -> V_19 ) ;
F_47 ( & V_8 -> V_57 ) ;
V_8 -> V_44 -> V_41 = NULL ;
V_8 -> V_40 . V_4 -> V_41 = NULL ;
F_48 ( V_28 -> V_46 -> V_148 , V_8 -> V_147 ) ;
F_49 ( V_8 -> V_149 ) ;
F_50 ( V_21 ) ;
}
static struct V_20 * F_63 ( struct V_154 * V_121 )
{
struct V_7 * V_8 ;
struct V_119 * V_120 ;
struct V_76 * * V_199 ;
V_8 = F_54 ( sizeof( * V_8 ) , V_107 ) ;
if ( V_8 == NULL )
return F_25 ( - V_150 ) ;
F_55 ( & V_8 -> V_40 . V_67 ) ;
V_8 -> V_47 = V_48 ;
V_120 = F_31 ( V_121 ) ;
F_64 ( & V_120 -> V_66 ) ;
if ( V_120 -> V_200 ) {
V_199 = V_120 -> V_200 ;
V_120 -> V_97 =
( const struct V_76 * const * ) V_199 ;
}
if ( V_120 -> V_201 ) {
V_199 = V_120 -> V_201 ;
V_120 -> V_94 =
( const struct V_76 * const * ) V_199 ;
}
if ( V_120 -> V_202 ) {
V_199 = V_120 -> V_202 ;
V_120 -> V_90 =
( const struct V_76 * const * ) V_199 ;
}
V_8 -> V_45 . V_93 = V_120 -> V_93 ;
V_8 -> V_45 . V_89 = V_120 -> V_89 ;
V_8 -> V_45 . V_97 = V_120 -> V_97 ;
V_8 -> V_45 . V_94 = V_120 -> V_94 ;
V_8 -> V_45 . V_90 = V_120 -> V_90 ;
++ V_120 -> V_197 ;
F_65 ( & V_120 -> V_66 ) ;
V_8 -> V_36 . V_68 = L_15 ;
V_8 -> V_36 . V_203 = F_30 ;
V_8 -> V_36 . V_204 = F_61 ;
V_8 -> V_36 . V_205 = F_10 ;
V_8 -> V_36 . V_206 = F_11 ;
V_8 -> V_36 . V_207 = F_15 ;
V_8 -> V_36 . V_208 = F_4 ;
V_8 -> V_36 . V_209 = F_59 ;
V_8 -> V_36 . V_210 = true ;
return & V_8 -> V_36 ;
}
