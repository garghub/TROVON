static struct V_1 * F_1 ( struct V_2 * V_2 , T_1 V_3 )
{
struct V_1 * V_4 ;
F_2 (mrt, net) {
if ( V_4 -> V_3 == V_3 )
return V_4 ;
}
return NULL ;
}
static int F_3 ( struct V_2 * V_2 , struct V_5 * V_6 ,
struct V_1 * * V_4 )
{
struct V_7 V_8 ;
struct V_9 V_10 = { . V_11 = & V_8 , } ;
int V_12 ;
V_12 = F_4 ( V_2 -> V_13 . V_14 ,
F_5 ( V_6 ) , 0 , & V_10 ) ;
if ( V_12 < 0 )
return V_12 ;
* V_4 = V_8 . V_4 ;
return 0 ;
}
static int F_6 ( struct V_15 * V_16 , struct V_17 * V_18 ,
int V_19 , struct V_9 * V_10 )
{
struct V_7 * V_8 = V_10 -> V_11 ;
struct V_1 * V_4 ;
switch ( V_16 -> V_20 ) {
case V_21 :
break;
case V_22 :
return - V_23 ;
case V_24 :
return - V_25 ;
case V_26 :
default:
return - V_27 ;
}
V_4 = F_1 ( V_16 -> V_28 , V_16 -> V_29 ) ;
if ( V_4 == NULL )
return - V_30 ;
V_8 -> V_4 = V_4 ;
return 0 ;
}
static int F_7 ( struct V_15 * V_16 , struct V_17 * V_31 , int V_19 )
{
return 1 ;
}
static int F_8 ( struct V_15 * V_16 , struct V_32 * V_33 ,
struct V_34 * V_35 , struct V_36 * * V_37 )
{
return 0 ;
}
static int F_9 ( struct V_15 * V_16 , struct V_34 * V_35 ,
struct V_36 * * V_37 )
{
return 1 ;
}
static int F_10 ( struct V_15 * V_16 , struct V_32 * V_33 ,
struct V_34 * V_35 )
{
V_35 -> V_38 = 0 ;
V_35 -> V_39 = 0 ;
V_35 -> V_40 = 0 ;
return 0 ;
}
static int T_2 F_11 ( struct V_2 * V_2 )
{
struct V_41 * V_42 ;
struct V_1 * V_4 ;
int V_12 ;
V_42 = F_12 ( & V_43 , V_2 ) ;
if ( F_13 ( V_42 ) )
return F_14 ( V_42 ) ;
F_15 ( & V_2 -> V_13 . V_44 ) ;
V_4 = F_16 ( V_2 , V_45 ) ;
if ( V_4 == NULL ) {
V_12 = - V_46 ;
goto V_47;
}
V_12 = F_17 ( V_42 , 0x7fff , V_45 , 0 ) ;
if ( V_12 < 0 )
goto V_48;
V_2 -> V_13 . V_14 = V_42 ;
return 0 ;
V_48:
F_18 ( V_4 ) ;
V_47:
F_19 ( V_42 ) ;
return V_12 ;
}
static void T_3 F_20 ( struct V_2 * V_2 )
{
struct V_1 * V_4 , * V_49 ;
F_21 (mrt, next, &net->ipv4.mr_tables, list) {
F_22 ( & V_4 -> V_50 ) ;
F_18 ( V_4 ) ;
}
F_19 ( V_2 -> V_13 . V_14 ) ;
}
static struct V_1 * F_1 ( struct V_2 * V_2 , T_1 V_3 )
{
return V_2 -> V_13 . V_4 ;
}
static int F_3 ( struct V_2 * V_2 , struct V_5 * V_6 ,
struct V_1 * * V_4 )
{
* V_4 = V_2 -> V_13 . V_4 ;
return 0 ;
}
static int T_2 F_11 ( struct V_2 * V_2 )
{
V_2 -> V_13 . V_4 = F_16 ( V_2 , V_45 ) ;
return V_2 -> V_13 . V_4 ? 0 : - V_46 ;
}
static void T_3 F_20 ( struct V_2 * V_2 )
{
F_18 ( V_2 -> V_13 . V_4 ) ;
}
static struct V_1 * F_16 ( struct V_2 * V_2 , T_1 V_3 )
{
struct V_1 * V_4 ;
unsigned int V_51 ;
V_4 = F_1 ( V_2 , V_3 ) ;
if ( V_4 != NULL )
return V_4 ;
V_4 = F_23 ( sizeof( * V_4 ) , V_52 ) ;
if ( V_4 == NULL )
return NULL ;
F_24 ( & V_4 -> V_2 , V_2 ) ;
V_4 -> V_3 = V_3 ;
for ( V_51 = 0 ; V_51 < V_53 ; V_51 ++ )
F_15 ( & V_4 -> V_54 [ V_51 ] ) ;
F_15 ( & V_4 -> V_55 ) ;
F_25 ( & V_4 -> V_56 , V_57 ,
( unsigned long ) V_4 ) ;
#ifdef F_26
V_4 -> V_58 = - 1 ;
#endif
#ifdef F_27
F_28 ( & V_4 -> V_50 , & V_2 -> V_13 . V_44 ) ;
#endif
return V_4 ;
}
static void F_29 ( struct V_59 * V_60 , struct V_61 * V_62 )
{
struct V_2 * V_2 = F_30 ( V_60 ) ;
F_31 ( V_60 ) ;
V_60 = F_32 ( V_2 , L_1 ) ;
if ( V_60 ) {
const struct V_63 * V_42 = V_60 -> V_64 ;
struct V_65 V_66 ;
struct V_67 V_68 ;
memset ( & V_68 , 0 , sizeof( V_68 ) ) ;
V_68 . V_69 . V_70 = V_62 -> V_71 . V_72 ;
V_68 . V_69 . V_73 = V_62 -> V_74 . V_72 ;
V_68 . V_69 . V_75 = 4 ;
V_68 . V_69 . V_76 = 5 ;
V_68 . V_69 . V_77 = V_78 ;
sprintf ( V_68 . V_79 , L_2 , V_62 -> V_80 ) ;
V_66 . V_81 . V_82 = ( V_83 void V_84 * ) & V_68 ;
if ( V_42 -> V_85 ) {
T_4 V_86 = F_33 () ;
F_34 ( V_87 ) ;
V_42 -> V_85 ( V_60 , & V_66 , V_88 ) ;
F_34 ( V_86 ) ;
}
}
}
static
struct V_59 * F_35 ( struct V_2 * V_2 , struct V_61 * V_62 )
{
struct V_59 * V_60 ;
V_60 = F_32 ( V_2 , L_1 ) ;
if ( V_60 ) {
const struct V_63 * V_42 = V_60 -> V_64 ;
int V_12 ;
struct V_65 V_66 ;
struct V_67 V_68 ;
struct V_89 * V_90 ;
memset ( & V_68 , 0 , sizeof( V_68 ) ) ;
V_68 . V_69 . V_70 = V_62 -> V_71 . V_72 ;
V_68 . V_69 . V_73 = V_62 -> V_74 . V_72 ;
V_68 . V_69 . V_75 = 4 ;
V_68 . V_69 . V_76 = 5 ;
V_68 . V_69 . V_77 = V_78 ;
sprintf ( V_68 . V_79 , L_2 , V_62 -> V_80 ) ;
V_66 . V_81 . V_82 = ( V_83 void V_84 * ) & V_68 ;
if ( V_42 -> V_85 ) {
T_4 V_86 = F_33 () ;
F_34 ( V_87 ) ;
V_12 = V_42 -> V_85 ( V_60 , & V_66 , V_91 ) ;
F_34 ( V_86 ) ;
} else {
V_12 = - V_92 ;
}
V_60 = NULL ;
if ( V_12 == 0 &&
( V_60 = F_32 ( V_2 , V_68 . V_79 ) ) != NULL ) {
V_60 -> V_19 |= V_93 ;
V_90 = F_36 ( V_60 ) ;
if ( V_90 == NULL )
goto V_94;
F_37 ( V_90 ) ;
F_38 ( V_90 -> V_95 , V_96 ) = 0 ;
if ( F_39 ( V_60 ) )
goto V_94;
F_40 ( V_60 ) ;
}
}
return V_60 ;
V_94:
F_41 () ;
F_42 () ;
F_43 ( V_60 ) ;
return NULL ;
}
static T_5 F_44 ( struct V_32 * V_33 , struct V_59 * V_60 )
{
struct V_2 * V_2 = F_30 ( V_60 ) ;
struct V_1 * V_4 ;
struct V_5 V_97 = {
. V_98 = V_60 -> V_99 ,
. V_100 = V_33 -> V_101 ,
. V_102 = V_33 -> V_103 ,
} ;
int V_12 ;
V_12 = F_3 ( V_2 , & V_97 , & V_4 ) ;
if ( V_12 < 0 ) {
F_45 ( V_33 ) ;
return V_12 ;
}
F_46 ( & V_104 ) ;
V_60 -> V_105 . V_106 += V_33 -> V_107 ;
V_60 -> V_105 . V_108 ++ ;
F_47 ( V_4 , V_33 , V_4 -> V_58 , V_109 ) ;
F_48 ( & V_104 ) ;
F_45 ( V_33 ) ;
return V_110 ;
}
static void F_49 ( struct V_59 * V_60 )
{
V_60 -> type = V_111 ;
V_60 -> V_112 = V_113 - sizeof( struct V_114 ) - 8 ;
V_60 -> V_19 = V_115 ;
V_60 -> V_64 = & V_116 ,
V_60 -> V_117 = V_118 ;
V_60 -> V_119 |= V_120 ;
}
static struct V_59 * F_50 ( struct V_2 * V_2 , struct V_1 * V_4 )
{
struct V_59 * V_60 ;
struct V_89 * V_90 ;
char V_79 [ V_121 ] ;
if ( V_4 -> V_3 == V_45 )
sprintf ( V_79 , L_3 ) ;
else
sprintf ( V_79 , L_4 , V_4 -> V_3 ) ;
V_60 = F_51 ( 0 , V_79 , F_49 ) ;
if ( V_60 == NULL )
return NULL ;
F_52 ( V_60 , V_2 ) ;
if ( F_53 ( V_60 ) ) {
V_118 ( V_60 ) ;
return NULL ;
}
V_60 -> V_122 = 0 ;
F_54 () ;
V_90 = F_55 ( V_60 ) ;
if ( ! V_90 ) {
F_56 () ;
goto V_94;
}
F_37 ( V_90 ) ;
F_38 ( V_90 -> V_95 , V_96 ) = 0 ;
F_56 () ;
if ( F_39 ( V_60 ) )
goto V_94;
F_40 ( V_60 ) ;
return V_60 ;
V_94:
F_41 () ;
F_42 () ;
F_43 ( V_60 ) ;
return NULL ;
}
static int F_57 ( struct V_1 * V_4 , int V_123 , int V_124 ,
struct V_125 * V_126 )
{
struct V_127 * V_62 ;
struct V_59 * V_60 ;
struct V_89 * V_90 ;
if ( V_123 < 0 || V_123 >= V_4 -> V_128 )
return - V_129 ;
V_62 = & V_4 -> V_130 [ V_123 ] ;
F_58 ( & V_104 ) ;
V_60 = V_62 -> V_60 ;
V_62 -> V_60 = NULL ;
if ( ! V_60 ) {
F_59 ( & V_104 ) ;
return - V_129 ;
}
#ifdef F_26
if ( V_123 == V_4 -> V_58 )
V_4 -> V_58 = - 1 ;
#endif
if ( V_123 + 1 == V_4 -> V_128 ) {
int V_131 ;
for ( V_131 = V_123 - 1 ; V_131 >= 0 ; V_131 -- ) {
if ( F_60 ( V_4 , V_131 ) )
break;
}
V_4 -> V_128 = V_131 + 1 ;
}
F_59 ( & V_104 ) ;
F_61 ( V_60 , - 1 ) ;
V_90 = F_36 ( V_60 ) ;
if ( V_90 ) {
F_38 ( V_90 -> V_95 , V_132 ) -- ;
F_62 ( V_90 ) ;
}
if ( V_62 -> V_19 & ( V_133 | V_134 ) && ! V_124 )
F_63 ( V_60 , V_126 ) ;
F_64 ( V_60 ) ;
return 0 ;
}
static void F_65 ( struct V_135 * V_126 )
{
struct V_136 * V_137 = F_66 ( V_126 , struct V_136 , V_138 ) ;
F_67 ( V_139 , V_137 ) ;
}
static inline void F_68 ( struct V_136 * V_137 )
{
F_69 ( & V_137 -> V_138 , F_65 ) ;
}
static void F_70 ( struct V_1 * V_4 , struct V_136 * V_137 )
{
struct V_2 * V_2 = F_71 ( & V_4 -> V_2 ) ;
struct V_32 * V_33 ;
struct V_140 * V_141 ;
F_72 ( & V_4 -> V_142 ) ;
while ( ( V_33 = F_73 ( & V_137 -> V_143 . V_144 . V_145 ) ) ) {
if ( F_74 ( V_33 ) -> V_75 == 0 ) {
struct V_146 * V_147 = (struct V_146 * ) F_75 ( V_33 , sizeof( struct V_114 ) ) ;
V_147 -> V_148 = V_149 ;
V_147 -> V_150 = F_76 ( sizeof( struct V_140 ) ) ;
F_77 ( V_33 , V_147 -> V_150 ) ;
V_141 = F_78 ( V_147 ) ;
V_141 -> error = - V_151 ;
memset ( & V_141 -> V_152 , 0 , sizeof( V_141 -> V_152 ) ) ;
F_79 ( V_33 , V_2 , F_80 ( V_33 ) . V_153 ) ;
} else {
F_45 ( V_33 ) ;
}
}
F_68 ( V_137 ) ;
}
static void V_57 ( unsigned long V_10 )
{
struct V_1 * V_4 = (struct V_1 * ) V_10 ;
unsigned long V_154 ;
unsigned long V_155 ;
struct V_136 * V_137 , * V_49 ;
if ( ! F_81 ( & V_156 ) ) {
F_82 ( & V_4 -> V_56 , V_157 + V_158 / 10 ) ;
return;
}
if ( F_83 ( & V_4 -> V_55 ) )
goto V_159;
V_154 = V_157 ;
V_155 = 10 * V_158 ;
F_21 (c, next, &mrt->mfc_unres_queue, list) {
if ( F_84 ( V_137 -> V_143 . V_144 . V_155 , V_154 ) ) {
unsigned long V_160 = V_137 -> V_143 . V_144 . V_155 - V_154 ;
if ( V_160 < V_155 )
V_155 = V_160 ;
continue;
}
F_22 ( & V_137 -> V_50 ) ;
F_70 ( V_4 , V_137 ) ;
}
if ( ! F_83 ( & V_4 -> V_55 ) )
F_82 ( & V_4 -> V_56 , V_157 + V_155 ) ;
V_159:
F_85 ( & V_156 ) ;
}
static void F_86 ( struct V_1 * V_4 , struct V_136 * V_161 ,
unsigned char * V_162 )
{
int V_123 ;
V_161 -> V_143 . V_8 . V_163 = V_164 ;
V_161 -> V_143 . V_8 . V_128 = 0 ;
memset ( V_161 -> V_143 . V_8 . V_162 , 255 , V_164 ) ;
for ( V_123 = 0 ; V_123 < V_4 -> V_128 ; V_123 ++ ) {
if ( F_60 ( V_4 , V_123 ) &&
V_162 [ V_123 ] && V_162 [ V_123 ] < 255 ) {
V_161 -> V_143 . V_8 . V_162 [ V_123 ] = V_162 [ V_123 ] ;
if ( V_161 -> V_143 . V_8 . V_163 > V_123 )
V_161 -> V_143 . V_8 . V_163 = V_123 ;
if ( V_161 -> V_143 . V_8 . V_128 <= V_123 )
V_161 -> V_143 . V_8 . V_128 = V_123 + 1 ;
}
}
}
static int F_87 ( struct V_2 * V_2 , struct V_1 * V_4 ,
struct V_61 * V_165 , int V_166 )
{
int V_123 = V_165 -> V_80 ;
struct V_127 * V_62 = & V_4 -> V_130 [ V_123 ] ;
struct V_59 * V_60 ;
struct V_89 * V_90 ;
int V_12 ;
if ( F_60 ( V_4 , V_123 ) )
return - V_167 ;
switch ( V_165 -> V_168 ) {
#ifdef F_26
case V_134 :
if ( V_4 -> V_58 >= 0 )
return - V_167 ;
V_60 = F_50 ( V_2 , V_4 ) ;
if ( ! V_60 )
return - V_169 ;
V_12 = F_61 ( V_60 , 1 ) ;
if ( V_12 ) {
F_43 ( V_60 ) ;
F_64 ( V_60 ) ;
return V_12 ;
}
break;
#endif
case V_133 :
V_60 = F_35 ( V_2 , V_165 ) ;
if ( ! V_60 )
return - V_169 ;
V_12 = F_61 ( V_60 , 1 ) ;
if ( V_12 ) {
F_29 ( V_60 , V_165 ) ;
F_64 ( V_60 ) ;
return V_12 ;
}
break;
case V_170 :
case 0 :
if ( V_165 -> V_168 == V_170 ) {
V_60 = F_88 ( V_2 , V_165 -> V_171 ) ;
if ( V_60 && F_36 ( V_60 ) == NULL ) {
F_64 ( V_60 ) ;
return - V_129 ;
}
} else {
V_60 = F_89 ( V_2 , V_165 -> V_74 . V_72 ) ;
}
if ( ! V_60 )
return - V_129 ;
V_12 = F_61 ( V_60 , 1 ) ;
if ( V_12 ) {
F_64 ( V_60 ) ;
return V_12 ;
}
break;
default:
return - V_27 ;
}
V_90 = F_36 ( V_60 ) ;
if ( ! V_90 ) {
F_64 ( V_60 ) ;
return - V_129 ;
}
F_38 ( V_90 -> V_95 , V_132 ) ++ ;
F_62 ( V_90 ) ;
V_62 -> V_172 = V_165 -> V_173 ;
V_62 -> V_174 = V_165 -> V_74 . V_72 ;
V_62 -> V_175 = V_165 -> V_71 . V_72 ;
V_62 -> V_19 = V_165 -> V_168 ;
if ( ! V_166 )
V_62 -> V_19 |= V_176 ;
V_62 -> V_177 = V_165 -> V_178 ;
V_62 -> V_179 = 0 ;
V_62 -> V_180 = 0 ;
V_62 -> V_181 = 0 ;
V_62 -> V_182 = 0 ;
V_62 -> V_183 = V_60 -> V_99 ;
if ( V_62 -> V_19 & ( V_133 | V_134 ) )
V_62 -> V_183 = V_60 -> V_122 ;
F_58 ( & V_104 ) ;
V_62 -> V_60 = V_60 ;
#ifdef F_26
if ( V_62 -> V_19 & V_134 )
V_4 -> V_58 = V_123 ;
#endif
if ( V_123 + 1 > V_4 -> V_128 )
V_4 -> V_128 = V_123 + 1 ;
F_59 ( & V_104 ) ;
return 0 ;
}
static struct V_136 * F_90 ( struct V_1 * V_4 ,
T_6 V_184 ,
T_6 V_185 )
{
int line = F_91 ( V_185 , V_184 ) ;
struct V_136 * V_137 ;
F_92 (c, &mrt->mfc_cache_array[line], list) {
if ( V_137 -> V_186 == V_184 && V_137 -> V_187 == V_185 )
return V_137 ;
}
return NULL ;
}
static struct V_136 * F_93 ( void )
{
struct V_136 * V_137 = F_94 ( V_139 , V_52 ) ;
if ( V_137 )
V_137 -> V_143 . V_8 . V_163 = V_164 ;
return V_137 ;
}
static struct V_136 * F_95 ( void )
{
struct V_136 * V_137 = F_94 ( V_139 , V_188 ) ;
if ( V_137 ) {
F_96 ( & V_137 -> V_143 . V_144 . V_145 ) ;
V_137 -> V_143 . V_144 . V_155 = V_157 + 10 * V_158 ;
}
return V_137 ;
}
static void F_97 ( struct V_2 * V_2 , struct V_1 * V_4 ,
struct V_136 * V_189 , struct V_136 * V_137 )
{
struct V_32 * V_33 ;
struct V_140 * V_141 ;
while ( ( V_33 = F_98 ( & V_189 -> V_143 . V_144 . V_145 ) ) ) {
if ( F_74 ( V_33 ) -> V_75 == 0 ) {
struct V_146 * V_147 = (struct V_146 * ) F_75 ( V_33 , sizeof( struct V_114 ) ) ;
if ( F_99 ( V_4 , V_33 , V_137 , F_78 ( V_147 ) ) > 0 ) {
V_147 -> V_150 = F_100 ( V_33 ) -
( V_190 * ) V_147 ;
} else {
V_147 -> V_148 = V_149 ;
V_147 -> V_150 = F_76 ( sizeof( struct V_140 ) ) ;
F_77 ( V_33 , V_147 -> V_150 ) ;
V_141 = F_78 ( V_147 ) ;
V_141 -> error = - V_191 ;
memset ( & V_141 -> V_152 , 0 , sizeof( V_141 -> V_152 ) ) ;
}
F_79 ( V_33 , V_2 , F_80 ( V_33 ) . V_153 ) ;
} else {
F_101 ( V_2 , V_4 , V_33 , V_137 , 0 ) ;
}
}
}
static int F_47 ( struct V_1 * V_4 ,
struct V_32 * V_192 , T_7 V_123 , int assert )
{
struct V_32 * V_33 ;
const int V_76 = F_102 ( V_192 ) ;
struct V_193 * V_194 ;
struct V_195 * V_152 ;
struct V_196 * V_197 ;
int V_198 ;
#ifdef F_26
if ( assert == V_109 )
V_33 = F_103 ( V_192 , sizeof( struct V_114 ) ) ;
else
#endif
V_33 = F_104 ( 128 , V_188 ) ;
if ( ! V_33 )
return - V_169 ;
#ifdef F_26
if ( assert == V_109 ) {
F_105 ( V_33 , sizeof( struct V_114 ) ) ;
F_106 ( V_33 ) ;
F_107 ( V_33 ) ;
V_152 = (struct V_195 * ) F_108 ( V_33 ) ;
memcpy ( V_152 , F_108 ( V_192 ) , sizeof( struct V_114 ) ) ;
V_152 -> V_199 = V_109 ;
V_152 -> V_200 = 0 ;
V_152 -> V_201 = V_4 -> V_58 ;
F_74 ( V_33 ) -> V_76 = sizeof( struct V_114 ) >> 2 ;
F_74 ( V_33 ) -> V_202 = F_109 ( F_110 ( F_74 ( V_192 ) -> V_202 ) +
sizeof( struct V_114 ) ) ;
} else
#endif
{
V_33 -> V_203 = V_33 -> V_204 ;
F_111 ( V_33 , V_76 ) ;
F_112 ( V_33 , V_192 -> V_205 , V_76 ) ;
F_74 ( V_33 ) -> V_77 = 0 ;
V_152 = (struct V_195 * ) F_108 ( V_33 ) ;
V_152 -> V_201 = V_123 ;
F_113 ( V_33 , F_114 ( F_115 ( V_192 ) ) ) ;
V_194 = (struct V_193 * ) F_111 ( V_33 , sizeof( struct V_193 ) ) ;
V_194 -> type =
V_152 -> V_199 = assert ;
V_194 -> V_206 = 0 ;
F_74 ( V_33 ) -> V_202 = F_109 ( V_33 -> V_107 ) ;
V_33 -> V_207 = V_33 -> V_203 ;
}
F_54 () ;
V_197 = F_116 ( V_4 -> V_197 ) ;
if ( V_197 == NULL ) {
F_56 () ;
F_45 ( V_33 ) ;
return - V_27 ;
}
V_198 = F_117 ( V_197 , V_33 ) ;
F_56 () ;
if ( V_198 < 0 ) {
F_118 ( L_5 ) ;
F_45 ( V_33 ) ;
}
return V_198 ;
}
static int
F_119 ( struct V_1 * V_4 , T_7 V_123 , struct V_32 * V_33 )
{
bool V_208 = false ;
int V_12 ;
struct V_136 * V_137 ;
const struct V_114 * V_69 = F_74 ( V_33 ) ;
F_120 ( & V_156 ) ;
F_121 (c, &mrt->mfc_unres_queue, list) {
if ( V_137 -> V_187 == V_69 -> V_70 &&
V_137 -> V_186 == V_69 -> V_73 ) {
V_208 = true ;
break;
}
}
if ( ! V_208 ) {
if ( F_122 ( & V_4 -> V_142 ) >= 10 ||
( V_137 = F_95 () ) == NULL ) {
F_123 ( & V_156 ) ;
F_45 ( V_33 ) ;
return - V_169 ;
}
V_137 -> V_209 = - 1 ;
V_137 -> V_186 = V_69 -> V_73 ;
V_137 -> V_187 = V_69 -> V_70 ;
V_12 = F_47 ( V_4 , V_33 , V_123 , V_210 ) ;
if ( V_12 < 0 ) {
F_123 ( & V_156 ) ;
F_68 ( V_137 ) ;
F_45 ( V_33 ) ;
return V_12 ;
}
F_124 ( & V_4 -> V_142 ) ;
F_125 ( & V_137 -> V_50 , & V_4 -> V_55 ) ;
if ( F_122 ( & V_4 -> V_142 ) == 1 )
F_82 ( & V_4 -> V_56 , V_137 -> V_143 . V_144 . V_155 ) ;
}
if ( V_137 -> V_143 . V_144 . V_145 . V_211 > 3 ) {
F_45 ( V_33 ) ;
V_12 = - V_169 ;
} else {
F_126 ( & V_137 -> V_143 . V_144 . V_145 , V_33 ) ;
V_12 = 0 ;
}
F_123 ( & V_156 ) ;
return V_12 ;
}
static int F_127 ( struct V_1 * V_4 , struct V_212 * V_213 )
{
int line ;
struct V_136 * V_137 , * V_49 ;
line = F_91 ( V_213 -> V_214 . V_72 , V_213 -> V_215 . V_72 ) ;
F_21 (c, next, &mrt->mfc_cache_array[line], list) {
if ( V_137 -> V_186 == V_213 -> V_215 . V_72 &&
V_137 -> V_187 == V_213 -> V_214 . V_72 ) {
F_128 ( & V_137 -> V_50 ) ;
F_68 ( V_137 ) ;
return 0 ;
}
}
return - V_216 ;
}
static int F_129 ( struct V_2 * V_2 , struct V_1 * V_4 ,
struct V_212 * V_213 , int V_166 )
{
bool V_208 = false ;
int line ;
struct V_136 * V_189 , * V_137 ;
if ( V_213 -> V_217 >= V_164 )
return - V_218 ;
line = F_91 ( V_213 -> V_214 . V_72 , V_213 -> V_215 . V_72 ) ;
F_121 (c, &mrt->mfc_cache_array[line], list) {
if ( V_137 -> V_186 == V_213 -> V_215 . V_72 &&
V_137 -> V_187 == V_213 -> V_214 . V_72 ) {
V_208 = true ;
break;
}
}
if ( V_208 ) {
F_58 ( & V_104 ) ;
V_137 -> V_209 = V_213 -> V_217 ;
F_86 ( V_4 , V_137 , V_213 -> V_219 ) ;
if ( ! V_166 )
V_137 -> V_220 |= V_221 ;
F_59 ( & V_104 ) ;
return 0 ;
}
if ( ! F_130 ( V_213 -> V_214 . V_72 ) )
return - V_27 ;
V_137 = F_93 () ;
if ( V_137 == NULL )
return - V_46 ;
V_137 -> V_186 = V_213 -> V_215 . V_72 ;
V_137 -> V_187 = V_213 -> V_214 . V_72 ;
V_137 -> V_209 = V_213 -> V_217 ;
F_86 ( V_4 , V_137 , V_213 -> V_219 ) ;
if ( ! V_166 )
V_137 -> V_220 |= V_221 ;
F_131 ( & V_137 -> V_50 , & V_4 -> V_54 [ line ] ) ;
V_208 = false ;
F_120 ( & V_156 ) ;
F_121 (uc, &mrt->mfc_unres_queue, list) {
if ( V_189 -> V_186 == V_137 -> V_186 &&
V_189 -> V_187 == V_137 -> V_187 ) {
F_22 ( & V_189 -> V_50 ) ;
F_72 ( & V_4 -> V_142 ) ;
V_208 = true ;
break;
}
}
if ( F_83 ( & V_4 -> V_55 ) )
F_132 ( & V_4 -> V_56 ) ;
F_123 ( & V_156 ) ;
if ( V_208 ) {
F_97 ( V_2 , V_4 , V_189 , V_137 ) ;
F_68 ( V_189 ) ;
}
return 0 ;
}
static void F_133 ( struct V_1 * V_4 )
{
int V_51 ;
F_134 ( V_50 ) ;
struct V_136 * V_137 , * V_49 ;
for ( V_51 = 0 ; V_51 < V_4 -> V_128 ; V_51 ++ ) {
if ( ! ( V_4 -> V_130 [ V_51 ] . V_19 & V_176 ) )
F_57 ( V_4 , V_51 , 0 , & V_50 ) ;
}
F_135 ( & V_50 ) ;
for ( V_51 = 0 ; V_51 < V_53 ; V_51 ++ ) {
F_21 (c, next, &mrt->mfc_cache_array[i], list) {
if ( V_137 -> V_220 & V_221 )
continue;
F_128 ( & V_137 -> V_50 ) ;
F_68 ( V_137 ) ;
}
}
if ( F_122 ( & V_4 -> V_142 ) != 0 ) {
F_120 ( & V_156 ) ;
F_21 (c, next, &mrt->mfc_unres_queue, list) {
F_22 ( & V_137 -> V_50 ) ;
F_70 ( V_4 , V_137 ) ;
}
F_123 ( & V_156 ) ;
}
}
static void F_136 ( struct V_196 * V_222 )
{
struct V_2 * V_2 = F_137 ( V_222 ) ;
struct V_1 * V_4 ;
F_42 () ;
F_2 (mrt, net) {
if ( V_222 == F_138 ( V_4 -> V_197 ) ) {
F_139 ( V_2 , V_132 ) -- ;
F_140 ( V_4 -> V_197 , NULL ) ;
F_133 ( V_4 ) ;
}
}
F_41 () ;
}
int F_141 ( struct V_196 * V_222 , int V_223 , char V_84 * V_224 , unsigned int V_225 )
{
int V_198 ;
struct V_61 V_226 ;
struct V_212 V_213 ;
struct V_2 * V_2 = F_137 ( V_222 ) ;
struct V_1 * V_4 ;
V_4 = F_1 ( V_2 , F_142 ( V_222 ) -> V_227 ? : V_45 ) ;
if ( V_4 == NULL )
return - V_216 ;
if ( V_223 != V_228 ) {
if ( V_222 != F_143 ( V_4 -> V_197 ) &&
! F_144 ( V_229 ) )
return - V_25 ;
}
switch ( V_223 ) {
case V_228 :
if ( V_222 -> V_230 != V_231 ||
F_145 ( V_222 ) -> V_232 != V_233 )
return - V_92 ;
if ( V_225 != sizeof( int ) )
return - V_234 ;
F_42 () ;
if ( F_138 ( V_4 -> V_197 ) ) {
F_41 () ;
return - V_167 ;
}
V_198 = F_146 ( V_222 , 1 , F_136 ) ;
if ( V_198 == 0 ) {
F_147 ( V_4 -> V_197 , V_222 ) ;
F_139 ( V_2 , V_132 ) ++ ;
}
F_41 () ;
return V_198 ;
case V_235 :
if ( V_222 != F_143 ( V_4 -> V_197 ) )
return - V_25 ;
return F_146 ( V_222 , 0 , NULL ) ;
case V_236 :
case V_237 :
if ( V_225 != sizeof( V_226 ) )
return - V_27 ;
if ( F_148 ( & V_226 , V_224 , sizeof( V_226 ) ) )
return - V_238 ;
if ( V_226 . V_80 >= V_164 )
return - V_218 ;
F_42 () ;
if ( V_223 == V_236 ) {
V_198 = F_87 ( V_2 , V_4 , & V_226 ,
V_222 == F_138 ( V_4 -> V_197 ) ) ;
} else {
V_198 = F_57 ( V_4 , V_226 . V_80 , 0 , NULL ) ;
}
F_41 () ;
return V_198 ;
case V_239 :
case V_240 :
if ( V_225 != sizeof( V_213 ) )
return - V_27 ;
if ( F_148 ( & V_213 , V_224 , sizeof( V_213 ) ) )
return - V_238 ;
F_42 () ;
if ( V_223 == V_240 )
V_198 = F_127 ( V_4 , & V_213 ) ;
else
V_198 = F_129 ( V_2 , V_4 , & V_213 ,
V_222 == F_138 ( V_4 -> V_197 ) ) ;
F_41 () ;
return V_198 ;
case V_241 :
{
int V_62 ;
if ( F_149 ( V_62 , ( int V_84 * ) V_224 ) )
return - V_238 ;
V_4 -> V_242 = ( V_62 ) ? 1 : 0 ;
return 0 ;
}
#ifdef F_26
case V_243 :
{
int V_62 ;
if ( F_149 ( V_62 , ( int V_84 * ) V_224 ) )
return - V_238 ;
V_62 = ( V_62 ) ? 1 : 0 ;
F_42 () ;
V_198 = 0 ;
if ( V_62 != V_4 -> V_244 ) {
V_4 -> V_244 = V_62 ;
V_4 -> V_242 = V_62 ;
}
F_41 () ;
return V_198 ;
}
#endif
#ifdef F_27
case V_245 :
{
T_1 V_62 ;
if ( V_225 != sizeof( T_1 ) )
return - V_27 ;
if ( F_149 ( V_62 , ( T_1 V_84 * ) V_224 ) )
return - V_238 ;
F_42 () ;
V_198 = 0 ;
if ( V_222 == F_138 ( V_4 -> V_197 ) ) {
V_198 = - V_246 ;
} else {
if ( ! F_16 ( V_2 , V_62 ) )
V_198 = - V_46 ;
F_142 ( V_222 ) -> V_227 = V_62 ;
}
F_41 () ;
return V_198 ;
}
#endif
default:
return - V_234 ;
}
}
int F_150 ( struct V_196 * V_222 , int V_223 , char V_84 * V_224 , int V_84 * V_225 )
{
int V_247 ;
int V_248 ;
struct V_2 * V_2 = F_137 ( V_222 ) ;
struct V_1 * V_4 ;
V_4 = F_1 ( V_2 , F_142 ( V_222 ) -> V_227 ? : V_45 ) ;
if ( V_4 == NULL )
return - V_216 ;
if ( V_223 != V_249 &&
#ifdef F_26
V_223 != V_243 &&
#endif
V_223 != V_241 )
return - V_234 ;
if ( F_149 ( V_247 , V_225 ) )
return - V_238 ;
V_247 = F_151 (unsigned int, olr, sizeof(int)) ;
if ( V_247 < 0 )
return - V_27 ;
if ( F_152 ( V_247 , V_225 ) )
return - V_238 ;
if ( V_223 == V_249 )
V_248 = 0x0305 ;
#ifdef F_26
else if ( V_223 == V_243 )
V_248 = V_4 -> V_244 ;
#endif
else
V_248 = V_4 -> V_242 ;
if ( F_153 ( V_224 , & V_248 , V_247 ) )
return - V_238 ;
return 0 ;
}
int F_154 ( struct V_196 * V_222 , int V_250 , void V_84 * V_10 )
{
struct V_251 V_252 ;
struct V_253 V_254 ;
struct V_127 * V_226 ;
struct V_136 * V_137 ;
struct V_2 * V_2 = F_137 ( V_222 ) ;
struct V_1 * V_4 ;
V_4 = F_1 ( V_2 , F_142 ( V_222 ) -> V_227 ? : V_45 ) ;
if ( V_4 == NULL )
return - V_216 ;
switch ( V_250 ) {
case V_255 :
if ( F_148 ( & V_254 , V_10 , sizeof( V_254 ) ) )
return - V_238 ;
if ( V_254 . V_123 >= V_4 -> V_128 )
return - V_27 ;
F_46 ( & V_104 ) ;
V_226 = & V_4 -> V_130 [ V_254 . V_123 ] ;
if ( F_60 ( V_4 , V_254 . V_123 ) ) {
V_254 . V_256 = V_226 -> V_181 ;
V_254 . V_257 = V_226 -> V_182 ;
V_254 . V_258 = V_226 -> V_179 ;
V_254 . V_259 = V_226 -> V_180 ;
F_48 ( & V_104 ) ;
if ( F_153 ( V_10 , & V_254 , sizeof( V_254 ) ) )
return - V_238 ;
return 0 ;
}
F_48 ( & V_104 ) ;
return - V_129 ;
case V_260 :
if ( F_148 ( & V_252 , V_10 , sizeof( V_252 ) ) )
return - V_238 ;
F_54 () ;
V_137 = F_90 ( V_4 , V_252 . V_261 . V_72 , V_252 . V_262 . V_72 ) ;
if ( V_137 ) {
V_252 . V_263 = V_137 -> V_143 . V_8 . V_192 ;
V_252 . V_264 = V_137 -> V_143 . V_8 . V_265 ;
V_252 . V_266 = V_137 -> V_143 . V_8 . V_266 ;
F_56 () ;
if ( F_153 ( V_10 , & V_252 , sizeof( V_252 ) ) )
return - V_238 ;
return 0 ;
}
F_56 () ;
return - V_129 ;
default:
return - V_267 ;
}
}
int F_155 ( struct V_196 * V_222 , unsigned int V_250 , void V_84 * V_10 )
{
struct V_268 V_252 ;
struct V_269 V_254 ;
struct V_127 * V_226 ;
struct V_136 * V_137 ;
struct V_2 * V_2 = F_137 ( V_222 ) ;
struct V_1 * V_4 ;
V_4 = F_1 ( V_2 , F_142 ( V_222 ) -> V_227 ? : V_45 ) ;
if ( V_4 == NULL )
return - V_216 ;
switch ( V_250 ) {
case V_255 :
if ( F_148 ( & V_254 , V_10 , sizeof( V_254 ) ) )
return - V_238 ;
if ( V_254 . V_123 >= V_4 -> V_128 )
return - V_27 ;
F_46 ( & V_104 ) ;
V_226 = & V_4 -> V_130 [ V_254 . V_123 ] ;
if ( F_60 ( V_4 , V_254 . V_123 ) ) {
V_254 . V_256 = V_226 -> V_181 ;
V_254 . V_257 = V_226 -> V_182 ;
V_254 . V_258 = V_226 -> V_179 ;
V_254 . V_259 = V_226 -> V_180 ;
F_48 ( & V_104 ) ;
if ( F_153 ( V_10 , & V_254 , sizeof( V_254 ) ) )
return - V_238 ;
return 0 ;
}
F_48 ( & V_104 ) ;
return - V_129 ;
case V_260 :
if ( F_148 ( & V_252 , V_10 , sizeof( V_252 ) ) )
return - V_238 ;
F_54 () ;
V_137 = F_90 ( V_4 , V_252 . V_261 . V_72 , V_252 . V_262 . V_72 ) ;
if ( V_137 ) {
V_252 . V_263 = V_137 -> V_143 . V_8 . V_192 ;
V_252 . V_264 = V_137 -> V_143 . V_8 . V_265 ;
V_252 . V_266 = V_137 -> V_143 . V_8 . V_266 ;
F_56 () ;
if ( F_153 ( V_10 , & V_252 , sizeof( V_252 ) ) )
return - V_238 ;
return 0 ;
}
F_56 () ;
return - V_129 ;
default:
return - V_267 ;
}
}
static int F_156 ( struct V_270 * V_271 , unsigned long V_272 , void * V_273 )
{
struct V_59 * V_60 = V_273 ;
struct V_2 * V_2 = F_30 ( V_60 ) ;
struct V_1 * V_4 ;
struct V_127 * V_62 ;
int V_274 ;
if ( V_272 != V_275 )
return V_276 ;
F_2 (mrt, net) {
V_62 = & V_4 -> V_130 [ 0 ] ;
for ( V_274 = 0 ; V_274 < V_4 -> V_128 ; V_274 ++ , V_62 ++ ) {
if ( V_62 -> V_60 == V_60 )
F_57 ( V_4 , V_274 , 1 , NULL ) ;
}
}
return V_276 ;
}
static void F_157 ( struct V_32 * V_33 , T_6 V_73 , T_6 V_70 )
{
struct V_114 * V_69 ;
const struct V_114 * V_277 = F_74 ( V_33 ) ;
F_105 ( V_33 , sizeof( struct V_114 ) ) ;
V_33 -> V_207 = V_33 -> V_203 ;
F_106 ( V_33 ) ;
V_69 = F_74 ( V_33 ) ;
V_69 -> V_75 = 4 ;
V_69 -> V_40 = V_277 -> V_40 ;
V_69 -> V_278 = V_277 -> V_278 ;
V_69 -> V_279 = 0 ;
V_69 -> V_70 = V_70 ;
V_69 -> V_73 = V_73 ;
V_69 -> V_77 = V_78 ;
V_69 -> V_76 = 5 ;
V_69 -> V_202 = F_109 ( V_33 -> V_107 ) ;
F_158 ( V_69 , F_115 ( V_33 ) , NULL ) ;
F_159 ( V_69 ) ;
memset ( & ( F_160 ( V_33 ) -> V_280 ) , 0 , sizeof( F_160 ( V_33 ) -> V_280 ) ) ;
F_161 ( V_33 ) ;
}
static inline int F_162 ( struct V_32 * V_33 )
{
struct V_281 * V_280 = & ( F_160 ( V_33 ) -> V_280 ) ;
F_163 ( F_30 ( F_115 ( V_33 ) -> V_60 ) , V_282 ) ;
F_164 ( F_30 ( F_115 ( V_33 ) -> V_60 ) , V_283 , V_33 -> V_107 ) ;
if ( F_165 ( V_280 -> V_225 ) )
F_166 ( V_33 ) ;
return F_167 ( V_33 ) ;
}
static void F_168 ( struct V_2 * V_2 , struct V_1 * V_4 ,
struct V_32 * V_33 , struct V_136 * V_137 , int V_123 )
{
const struct V_114 * V_69 = F_74 ( V_33 ) ;
struct V_127 * V_226 = & V_4 -> V_130 [ V_123 ] ;
struct V_59 * V_60 ;
struct V_284 * V_285 ;
struct V_5 V_97 ;
int V_286 = 0 ;
if ( V_226 -> V_60 == NULL )
goto V_287;
#ifdef F_26
if ( V_226 -> V_19 & V_134 ) {
V_226 -> V_182 ++ ;
V_226 -> V_180 += V_33 -> V_107 ;
V_226 -> V_60 -> V_105 . V_106 += V_33 -> V_107 ;
V_226 -> V_60 -> V_105 . V_108 ++ ;
F_47 ( V_4 , V_33 , V_123 , V_109 ) ;
goto V_287;
}
#endif
if ( V_226 -> V_19 & V_133 ) {
V_285 = F_169 ( V_2 , & V_97 , NULL ,
V_226 -> V_175 , V_226 -> V_174 ,
0 , 0 ,
V_78 ,
F_170 ( V_69 -> V_40 ) , V_226 -> V_183 ) ;
if ( F_13 ( V_285 ) )
goto V_287;
V_286 = sizeof( struct V_114 ) ;
} else {
V_285 = F_169 ( V_2 , & V_97 , NULL , V_69 -> V_70 , 0 ,
0 , 0 ,
V_78 ,
F_170 ( V_69 -> V_40 ) , V_226 -> V_183 ) ;
if ( F_13 ( V_285 ) )
goto V_287;
}
V_60 = V_285 -> V_288 . V_60 ;
if ( V_33 -> V_107 + V_286 > F_171 ( & V_285 -> V_288 ) && ( F_110 ( V_69 -> V_279 ) & V_289 ) ) {
F_163 ( F_30 ( V_60 ) , V_290 ) ;
F_172 ( V_285 ) ;
goto V_287;
}
V_286 += F_173 ( V_60 ) + V_285 -> V_288 . V_291 ;
if ( F_174 ( V_33 , V_286 ) ) {
F_172 ( V_285 ) ;
goto V_287;
}
V_226 -> V_182 ++ ;
V_226 -> V_180 += V_33 -> V_107 ;
F_175 ( V_33 ) ;
F_113 ( V_33 , & V_285 -> V_288 ) ;
F_176 ( F_74 ( V_33 ) ) ;
if ( V_226 -> V_19 & V_133 ) {
F_157 ( V_33 , V_226 -> V_174 , V_226 -> V_175 ) ;
V_226 -> V_60 -> V_105 . V_108 ++ ;
V_226 -> V_60 -> V_105 . V_106 += V_33 -> V_107 ;
}
F_160 ( V_33 ) -> V_19 |= V_292 ;
F_177 ( V_293 , V_294 , V_33 , V_33 -> V_60 , V_60 ,
F_162 ) ;
return;
V_287:
F_45 ( V_33 ) ;
}
static int F_178 ( struct V_1 * V_4 , struct V_59 * V_60 )
{
int V_274 ;
for ( V_274 = V_4 -> V_128 - 1 ; V_274 >= 0 ; V_274 -- ) {
if ( V_4 -> V_130 [ V_274 ] . V_60 == V_60 )
break;
}
return V_274 ;
}
static int F_101 ( struct V_2 * V_2 , struct V_1 * V_4 ,
struct V_32 * V_33 , struct V_136 * V_161 ,
int V_174 )
{
int V_295 = - 1 ;
int V_226 , V_274 ;
V_226 = V_161 -> V_209 ;
V_161 -> V_143 . V_8 . V_192 ++ ;
V_161 -> V_143 . V_8 . V_265 += V_33 -> V_107 ;
if ( V_4 -> V_130 [ V_226 ] . V_60 != V_33 -> V_60 ) {
int V_296 ;
if ( F_179 ( F_180 ( V_33 ) ) ) {
goto V_297;
}
V_161 -> V_143 . V_8 . V_266 ++ ;
V_296 = F_178 ( V_4 , V_33 -> V_60 ) ;
if ( V_296 >= 0 && V_4 -> V_242 &&
( V_4 -> V_244 ||
V_161 -> V_143 . V_8 . V_162 [ V_296 ] < 255 ) &&
F_84 ( V_157 ,
V_161 -> V_143 . V_8 . V_298 + V_299 ) ) {
V_161 -> V_143 . V_8 . V_298 = V_157 ;
F_47 ( V_4 , V_33 , V_296 , V_300 ) ;
}
goto V_297;
}
V_4 -> V_130 [ V_226 ] . V_181 ++ ;
V_4 -> V_130 [ V_226 ] . V_179 += V_33 -> V_107 ;
for ( V_274 = V_161 -> V_143 . V_8 . V_128 - 1 ;
V_274 >= V_161 -> V_143 . V_8 . V_163 ; V_274 -- ) {
if ( F_74 ( V_33 ) -> V_278 > V_161 -> V_143 . V_8 . V_162 [ V_274 ] ) {
if ( V_295 != - 1 ) {
struct V_32 * V_301 = F_181 ( V_33 , V_188 ) ;
if ( V_301 )
F_168 ( V_2 , V_4 , V_301 , V_161 ,
V_295 ) ;
}
V_295 = V_274 ;
}
}
if ( V_295 != - 1 ) {
if ( V_174 ) {
struct V_32 * V_301 = F_181 ( V_33 , V_188 ) ;
if ( V_301 )
F_168 ( V_2 , V_4 , V_301 , V_161 , V_295 ) ;
} else {
F_168 ( V_2 , V_4 , V_33 , V_161 , V_295 ) ;
return 0 ;
}
}
V_297:
if ( ! V_174 )
F_45 ( V_33 ) ;
return 0 ;
}
static struct V_1 * F_182 ( struct V_2 * V_2 , struct V_32 * V_33 )
{
struct V_284 * V_285 = F_180 ( V_33 ) ;
struct V_114 * V_69 = F_74 ( V_33 ) ;
struct V_5 V_97 = {
. V_70 = V_69 -> V_70 ,
. V_73 = V_69 -> V_73 ,
. V_302 = F_170 ( V_69 -> V_40 ) ,
. V_98 = V_285 -> V_303 ,
. V_100 = V_285 -> V_304 ,
. V_102 = V_285 -> V_305 ,
} ;
struct V_1 * V_4 ;
int V_12 ;
V_12 = F_3 ( V_2 , & V_97 , & V_4 ) ;
if ( V_12 )
return F_183 ( V_12 ) ;
return V_4 ;
}
int F_184 ( struct V_32 * V_33 )
{
struct V_136 * V_161 ;
struct V_2 * V_2 = F_30 ( V_33 -> V_60 ) ;
int V_174 = F_180 ( V_33 ) -> V_306 & V_307 ;
struct V_1 * V_4 ;
if ( F_160 ( V_33 ) -> V_19 & V_292 )
goto V_297;
V_4 = F_182 ( V_2 , V_33 ) ;
if ( F_13 ( V_4 ) ) {
F_45 ( V_33 ) ;
return F_14 ( V_4 ) ;
}
if ( ! V_174 ) {
if ( F_160 ( V_33 ) -> V_280 . V_308 ) {
if ( F_185 ( V_33 ) )
return 0 ;
} else if ( F_74 ( V_33 ) -> V_77 == V_233 ) {
struct V_196 * V_197 ;
V_197 = F_116 ( V_4 -> V_197 ) ;
if ( V_197 ) {
F_161 ( V_33 ) ;
F_186 ( V_197 , V_33 ) ;
return 0 ;
}
}
}
V_161 = F_90 ( V_4 , F_74 ( V_33 ) -> V_73 , F_74 ( V_33 ) -> V_70 ) ;
if ( V_161 == NULL ) {
int V_226 ;
if ( V_174 ) {
struct V_32 * V_301 = F_181 ( V_33 , V_188 ) ;
F_187 ( V_33 ) ;
if ( V_301 == NULL )
return - V_169 ;
V_33 = V_301 ;
}
F_46 ( & V_104 ) ;
V_226 = F_178 ( V_4 , V_33 -> V_60 ) ;
if ( V_226 >= 0 ) {
int V_48 = F_119 ( V_4 , V_226 , V_33 ) ;
F_48 ( & V_104 ) ;
return V_48 ;
}
F_48 ( & V_104 ) ;
F_45 ( V_33 ) ;
return - V_309 ;
}
F_46 ( & V_104 ) ;
F_101 ( V_2 , V_4 , V_33 , V_161 , V_174 ) ;
F_48 ( & V_104 ) ;
if ( V_174 )
return F_187 ( V_33 ) ;
return 0 ;
V_297:
if ( V_174 )
return F_187 ( V_33 ) ;
F_45 ( V_33 ) ;
return 0 ;
}
static int F_188 ( struct V_1 * V_4 , struct V_32 * V_33 ,
unsigned int V_310 )
{
struct V_59 * V_311 = NULL ;
struct V_114 * V_286 ;
V_286 = (struct V_114 * ) ( F_189 ( V_33 ) + V_310 ) ;
if ( ! F_130 ( V_286 -> V_70 ) ||
V_286 -> V_202 == 0 ||
F_110 ( V_286 -> V_202 ) + V_310 > V_33 -> V_107 )
return 1 ;
F_46 ( & V_104 ) ;
if ( V_4 -> V_58 >= 0 )
V_311 = V_4 -> V_130 [ V_4 -> V_58 ] . V_60 ;
F_48 ( & V_104 ) ;
if ( V_311 == NULL )
return 1 ;
V_33 -> V_312 = V_33 -> V_203 ;
F_75 ( V_33 , ( V_190 * ) V_286 - V_33 -> V_205 ) ;
F_106 ( V_33 ) ;
V_33 -> V_77 = F_109 ( V_313 ) ;
V_33 -> V_314 = V_315 ;
V_33 -> V_316 = V_317 ;
F_190 ( V_33 , V_311 ) ;
F_191 ( V_33 ) ;
return V_318 ;
}
int F_192 ( struct V_32 * V_33 )
{
struct V_193 * V_319 ;
struct V_2 * V_2 = F_30 ( V_33 -> V_60 ) ;
struct V_1 * V_4 ;
if ( ! F_193 ( V_33 , sizeof( * V_319 ) + sizeof( struct V_114 ) ) )
goto V_320;
V_319 = F_194 ( V_33 ) ;
V_4 = F_182 ( V_2 , V_33 ) ;
if ( F_13 ( V_4 ) )
goto V_320;
if ( ! V_4 -> V_244 ||
V_319 -> V_321 != V_322 || V_319 -> V_206 != V_323 )
goto V_320;
if ( F_188 ( V_4 , V_33 , sizeof( * V_319 ) ) ) {
V_320:
F_45 ( V_33 ) ;
}
return 0 ;
}
static int F_195 ( struct V_32 * V_33 )
{
struct V_324 * V_319 ;
struct V_2 * V_2 = F_30 ( V_33 -> V_60 ) ;
struct V_1 * V_4 ;
if ( ! F_193 ( V_33 , sizeof( * V_319 ) + sizeof( struct V_114 ) ) )
goto V_320;
V_319 = (struct V_324 * ) F_189 ( V_33 ) ;
if ( V_319 -> type != ( ( V_325 << 4 ) | ( V_326 ) ) ||
( V_319 -> V_19 & V_327 ) ||
( F_196 ( ( void * ) V_319 , sizeof( * V_319 ) ) != 0 &&
F_197 ( F_198 ( V_33 , 0 , V_33 -> V_107 , 0 ) ) ) )
goto V_320;
V_4 = F_182 ( V_2 , V_33 ) ;
if ( F_13 ( V_4 ) )
goto V_320;
if ( F_188 ( V_4 , V_33 , sizeof( * V_319 ) ) ) {
V_320:
F_45 ( V_33 ) ;
}
return 0 ;
}
static int F_99 ( struct V_1 * V_4 , struct V_32 * V_33 ,
struct V_136 * V_137 , struct V_328 * V_329 )
{
int V_274 ;
struct V_330 * V_331 ;
V_190 * V_332 = F_100 ( V_33 ) ;
struct V_333 * V_334 ;
if ( V_137 -> V_209 >= V_164 )
return - V_216 ;
if ( F_60 ( V_4 , V_137 -> V_209 ) )
F_199 ( V_33 , V_335 , 4 , & V_4 -> V_130 [ V_137 -> V_209 ] . V_60 -> V_99 ) ;
V_334 = (struct V_333 * ) F_111 ( V_33 , F_200 ( 0 ) ) ;
for ( V_274 = V_137 -> V_143 . V_8 . V_163 ; V_274 < V_137 -> V_143 . V_8 . V_128 ; V_274 ++ ) {
if ( F_60 ( V_4 , V_274 ) && V_137 -> V_143 . V_8 . V_162 [ V_274 ] < 255 ) {
if ( F_201 ( V_33 ) < F_202 ( F_202 ( sizeof( * V_331 ) ) + 4 ) )
goto V_336;
V_331 = (struct V_330 * ) F_111 ( V_33 , F_202 ( sizeof( * V_331 ) ) ) ;
V_331 -> V_337 = 0 ;
V_331 -> V_338 = V_137 -> V_143 . V_8 . V_162 [ V_274 ] ;
V_331 -> V_339 = V_4 -> V_130 [ V_274 ] . V_60 -> V_99 ;
V_331 -> V_340 = sizeof( * V_331 ) ;
}
}
V_334 -> V_341 = V_342 ;
V_334 -> V_343 = F_100 ( V_33 ) - ( V_190 * ) V_334 ;
V_329 -> V_344 = V_345 ;
return 1 ;
V_336:
F_203 ( V_33 , V_332 ) ;
return - V_191 ;
}
int F_204 ( struct V_2 * V_2 , struct V_32 * V_33 ,
T_6 V_73 , T_6 V_70 ,
struct V_328 * V_329 , int V_346 )
{
struct V_136 * V_161 ;
struct V_1 * V_4 ;
int V_12 ;
V_4 = F_1 ( V_2 , V_45 ) ;
if ( V_4 == NULL )
return - V_216 ;
F_54 () ;
V_161 = F_90 ( V_4 , V_73 , V_70 ) ;
if ( V_161 == NULL ) {
struct V_32 * V_301 ;
struct V_114 * V_69 ;
struct V_59 * V_60 ;
int V_226 = - 1 ;
if ( V_346 ) {
F_56 () ;
return - V_30 ;
}
V_60 = V_33 -> V_60 ;
F_46 ( & V_104 ) ;
if ( V_60 )
V_226 = F_178 ( V_4 , V_60 ) ;
if ( V_226 < 0 ) {
F_48 ( & V_104 ) ;
F_56 () ;
return - V_309 ;
}
V_301 = F_181 ( V_33 , V_188 ) ;
if ( ! V_301 ) {
F_48 ( & V_104 ) ;
F_56 () ;
return - V_46 ;
}
F_105 ( V_301 , sizeof( struct V_114 ) ) ;
F_106 ( V_301 ) ;
V_69 = F_74 ( V_301 ) ;
V_69 -> V_76 = sizeof( struct V_114 ) >> 2 ;
V_69 -> V_73 = V_73 ;
V_69 -> V_70 = V_70 ;
V_69 -> V_75 = 0 ;
V_12 = F_119 ( V_4 , V_226 , V_301 ) ;
F_48 ( & V_104 ) ;
F_56 () ;
return V_12 ;
}
F_46 ( & V_104 ) ;
if ( ! V_346 && ( V_329 -> V_347 & V_348 ) )
V_161 -> V_220 |= V_349 ;
V_12 = F_99 ( V_4 , V_33 , V_161 , V_329 ) ;
F_48 ( & V_104 ) ;
F_56 () ;
return V_12 ;
}
static int F_205 ( struct V_1 * V_4 , struct V_32 * V_33 ,
T_1 V_153 , T_1 V_350 , struct V_136 * V_137 )
{
struct V_146 * V_147 ;
struct V_328 * V_329 ;
V_147 = F_206 ( V_33 , V_153 , V_350 , V_351 , sizeof( * V_329 ) , V_352 ) ;
if ( V_147 == NULL )
return - V_191 ;
V_329 = F_207 ( V_147 ) ;
V_329 -> V_353 = V_354 ;
V_329 -> V_355 = 32 ;
V_329 -> V_356 = 32 ;
V_329 -> V_357 = 0 ;
V_329 -> V_358 = V_4 -> V_3 ;
if ( F_208 ( V_33 , V_359 , V_4 -> V_3 ) )
goto V_360;
V_329 -> V_344 = V_345 ;
V_329 -> V_361 = V_362 ;
V_329 -> V_363 = V_364 ;
V_329 -> V_347 = 0 ;
if ( F_209 ( V_33 , V_365 , V_137 -> V_186 ) ||
F_209 ( V_33 , V_366 , V_137 -> V_187 ) )
goto V_360;
if ( F_99 ( V_4 , V_33 , V_137 , V_329 ) < 0 )
goto V_360;
return F_210 ( V_33 , V_147 ) ;
V_360:
F_211 ( V_33 , V_147 ) ;
return - V_191 ;
}
static int F_212 ( struct V_32 * V_33 , struct V_367 * V_368 )
{
struct V_2 * V_2 = F_137 ( V_33 -> V_222 ) ;
struct V_1 * V_4 ;
struct V_136 * V_213 ;
unsigned int V_369 = 0 , V_370 ;
unsigned int V_371 = 0 , V_372 ;
unsigned int V_141 = 0 , V_373 ;
V_370 = V_368 -> args [ 0 ] ;
V_372 = V_368 -> args [ 1 ] ;
V_373 = V_368 -> args [ 2 ] ;
F_54 () ;
F_2 (mrt, net) {
if ( V_369 < V_370 )
goto V_374;
if ( V_369 > V_370 )
V_372 = 0 ;
for ( V_371 = V_372 ; V_371 < V_53 ; V_371 ++ ) {
F_92 (mfc, &mrt->mfc_cache_array[h], list) {
if ( V_141 < V_373 )
goto V_375;
if ( F_205 ( V_4 , V_33 ,
F_80 ( V_368 -> V_33 ) . V_153 ,
V_368 -> V_147 -> V_376 ,
V_213 ) < 0 )
goto V_377;
V_375:
V_141 ++ ;
}
V_141 = V_373 = 0 ;
}
V_372 = 0 ;
V_374:
V_369 ++ ;
}
V_377:
F_56 () ;
V_368 -> args [ 2 ] = V_141 ;
V_368 -> args [ 1 ] = V_371 ;
V_368 -> args [ 0 ] = V_369 ;
return V_33 -> V_107 ;
}
static struct V_127 * F_213 ( struct V_2 * V_2 ,
struct V_378 * V_379 ,
T_8 V_380 )
{
struct V_1 * V_4 = V_379 -> V_4 ;
for ( V_379 -> V_274 = 0 ; V_379 -> V_274 < V_4 -> V_128 ; ++ V_379 -> V_274 ) {
if ( ! F_60 ( V_4 , V_379 -> V_274 ) )
continue;
if ( V_380 -- == 0 )
return & V_4 -> V_130 [ V_379 -> V_274 ] ;
}
return NULL ;
}
static void * F_214 ( struct V_381 * V_350 , T_8 * V_380 )
__acquires( V_104 )
{
struct V_378 * V_379 = V_350 -> V_382 ;
struct V_2 * V_2 = F_215 ( V_350 ) ;
struct V_1 * V_4 ;
V_4 = F_1 ( V_2 , V_45 ) ;
if ( V_4 == NULL )
return F_183 ( - V_216 ) ;
V_379 -> V_4 = V_4 ;
F_46 ( & V_104 ) ;
return * V_380 ? F_213 ( V_2 , V_350 -> V_382 , * V_380 - 1 )
: V_383 ;
}
static void * F_216 ( struct V_381 * V_350 , void * V_62 , T_8 * V_380 )
{
struct V_378 * V_379 = V_350 -> V_382 ;
struct V_2 * V_2 = F_215 ( V_350 ) ;
struct V_1 * V_4 = V_379 -> V_4 ;
++ * V_380 ;
if ( V_62 == V_383 )
return F_213 ( V_2 , V_379 , 0 ) ;
while ( ++ V_379 -> V_274 < V_4 -> V_128 ) {
if ( ! F_60 ( V_4 , V_379 -> V_274 ) )
continue;
return & V_4 -> V_130 [ V_379 -> V_274 ] ;
}
return NULL ;
}
static void F_217 ( struct V_381 * V_350 , void * V_62 )
__releases( V_104 )
{
F_48 ( & V_104 ) ;
}
static int F_218 ( struct V_381 * V_350 , void * V_62 )
{
struct V_378 * V_379 = V_350 -> V_382 ;
struct V_1 * V_4 = V_379 -> V_4 ;
if ( V_62 == V_383 ) {
F_219 ( V_350 ,
L_6 ) ;
} else {
const struct V_127 * V_226 = V_62 ;
const char * V_79 = V_226 -> V_60 ? V_226 -> V_60 -> V_79 : L_7 ;
F_220 ( V_350 ,
L_8 ,
V_226 - V_4 -> V_130 ,
V_79 , V_226 -> V_179 , V_226 -> V_181 ,
V_226 -> V_180 , V_226 -> V_182 ,
V_226 -> V_19 , V_226 -> V_174 , V_226 -> V_175 ) ;
}
return 0 ;
}
static int F_221 ( struct V_384 * V_384 , struct V_385 * V_385 )
{
return F_222 ( V_384 , V_385 , & V_386 ,
sizeof( struct V_378 ) ) ;
}
static struct V_136 * F_223 ( struct V_2 * V_2 ,
struct V_387 * V_388 , T_8 V_380 )
{
struct V_1 * V_4 = V_388 -> V_4 ;
struct V_136 * V_213 ;
F_54 () ;
for ( V_388 -> V_274 = 0 ; V_388 -> V_274 < V_53 ; V_388 -> V_274 ++ ) {
V_388 -> V_161 = & V_4 -> V_54 [ V_388 -> V_274 ] ;
F_92 (mfc, it->cache, list)
if ( V_380 -- == 0 )
return V_213 ;
}
F_56 () ;
F_120 ( & V_156 ) ;
V_388 -> V_161 = & V_4 -> V_55 ;
F_121 (mfc, it->cache, list)
if ( V_380 -- == 0 )
return V_213 ;
F_123 ( & V_156 ) ;
V_388 -> V_161 = NULL ;
return NULL ;
}
static void * F_224 ( struct V_381 * V_350 , T_8 * V_380 )
{
struct V_387 * V_388 = V_350 -> V_382 ;
struct V_2 * V_2 = F_215 ( V_350 ) ;
struct V_1 * V_4 ;
V_4 = F_1 ( V_2 , V_45 ) ;
if ( V_4 == NULL )
return F_183 ( - V_216 ) ;
V_388 -> V_4 = V_4 ;
V_388 -> V_161 = NULL ;
V_388 -> V_274 = 0 ;
return * V_380 ? F_223 ( V_2 , V_350 -> V_382 , * V_380 - 1 )
: V_383 ;
}
static void * F_225 ( struct V_381 * V_350 , void * V_62 , T_8 * V_380 )
{
struct V_136 * V_213 = V_62 ;
struct V_387 * V_388 = V_350 -> V_382 ;
struct V_2 * V_2 = F_215 ( V_350 ) ;
struct V_1 * V_4 = V_388 -> V_4 ;
++ * V_380 ;
if ( V_62 == V_383 )
return F_223 ( V_2 , V_350 -> V_382 , 0 ) ;
if ( V_213 -> V_50 . V_49 != V_388 -> V_161 )
return F_226 ( V_213 -> V_50 . V_49 , struct V_136 , V_50 ) ;
if ( V_388 -> V_161 == & V_4 -> V_55 )
goto V_389;
F_227 ( V_388 -> V_161 != & V_4 -> V_54 [ V_388 -> V_274 ] ) ;
while ( ++ V_388 -> V_274 < V_53 ) {
V_388 -> V_161 = & V_4 -> V_54 [ V_388 -> V_274 ] ;
if ( F_83 ( V_388 -> V_161 ) )
continue;
return F_228 ( V_388 -> V_161 , struct V_136 , V_50 ) ;
}
F_56 () ;
V_388 -> V_161 = & V_4 -> V_55 ;
V_388 -> V_274 = 0 ;
F_120 ( & V_156 ) ;
if ( ! F_83 ( V_388 -> V_161 ) )
return F_228 ( V_388 -> V_161 , struct V_136 , V_50 ) ;
V_389:
F_123 ( & V_156 ) ;
V_388 -> V_161 = NULL ;
return NULL ;
}
static void F_229 ( struct V_381 * V_350 , void * V_62 )
{
struct V_387 * V_388 = V_350 -> V_382 ;
struct V_1 * V_4 = V_388 -> V_4 ;
if ( V_388 -> V_161 == & V_4 -> V_55 )
F_123 ( & V_156 ) ;
else if ( V_388 -> V_161 == & V_4 -> V_54 [ V_388 -> V_274 ] )
F_56 () ;
}
static int F_230 ( struct V_381 * V_350 , void * V_62 )
{
int V_390 ;
if ( V_62 == V_383 ) {
F_219 ( V_350 ,
L_9 ) ;
} else {
const struct V_136 * V_213 = V_62 ;
const struct V_387 * V_388 = V_350 -> V_382 ;
const struct V_1 * V_4 = V_388 -> V_4 ;
F_220 ( V_350 , L_10 ,
( V_83 T_1 ) V_213 -> V_187 ,
( V_83 T_1 ) V_213 -> V_186 ,
V_213 -> V_209 ) ;
if ( V_388 -> V_161 != & V_4 -> V_55 ) {
F_220 ( V_350 , L_11 ,
V_213 -> V_143 . V_8 . V_192 ,
V_213 -> V_143 . V_8 . V_265 ,
V_213 -> V_143 . V_8 . V_266 ) ;
for ( V_390 = V_213 -> V_143 . V_8 . V_163 ;
V_390 < V_213 -> V_143 . V_8 . V_128 ; V_390 ++ ) {
if ( F_60 ( V_4 , V_390 ) &&
V_213 -> V_143 . V_8 . V_162 [ V_390 ] < 255 )
F_220 ( V_350 ,
L_12 ,
V_390 , V_213 -> V_143 . V_8 . V_162 [ V_390 ] ) ;
}
} else {
F_220 ( V_350 , L_11 , 0ul , 0ul , 0ul ) ;
}
F_231 ( V_350 , '\n' ) ;
}
return 0 ;
}
static int F_232 ( struct V_384 * V_384 , struct V_385 * V_385 )
{
return F_222 ( V_384 , V_385 , & V_391 ,
sizeof( struct V_387 ) ) ;
}
static int T_2 F_233 ( struct V_2 * V_2 )
{
int V_12 ;
V_12 = F_11 ( V_2 ) ;
if ( V_12 < 0 )
goto V_392;
#ifdef F_234
V_12 = - V_46 ;
if ( ! F_235 ( V_2 , L_13 , 0 , & V_393 ) )
goto V_394;
if ( ! F_235 ( V_2 , L_14 , 0 , & V_395 ) )
goto V_396;
#endif
return 0 ;
#ifdef F_234
V_396:
F_236 ( V_2 , L_13 ) ;
V_394:
F_20 ( V_2 ) ;
#endif
V_392:
return V_12 ;
}
static void T_3 F_237 ( struct V_2 * V_2 )
{
#ifdef F_234
F_236 ( V_2 , L_14 ) ;
F_236 ( V_2 , L_13 ) ;
#endif
F_20 ( V_2 ) ;
}
int T_9 F_238 ( void )
{
int V_12 ;
V_139 = F_239 ( L_15 ,
sizeof( struct V_136 ) ,
0 , V_397 | V_398 ,
NULL ) ;
if ( ! V_139 )
return - V_46 ;
V_12 = F_240 ( & V_399 ) ;
if ( V_12 )
goto V_400;
V_12 = F_241 ( & V_401 ) ;
if ( V_12 )
goto V_402;
#ifdef F_242
if ( F_243 ( & V_403 , V_404 ) < 0 ) {
F_244 ( L_16 , V_405 ) ;
V_12 = - V_30 ;
goto V_406;
}
#endif
F_245 ( V_354 , V_407 ,
NULL , F_212 , NULL ) ;
return 0 ;
#ifdef F_242
V_406:
F_246 ( & V_401 ) ;
#endif
V_402:
F_247 ( & V_399 ) ;
V_400:
F_248 ( V_139 ) ;
return V_12 ;
}
