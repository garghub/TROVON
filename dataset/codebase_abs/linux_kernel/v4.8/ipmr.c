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
int V_7 ;
struct V_8 V_9 ;
struct V_10 V_11 = {
. V_12 = & V_9 ,
. V_13 = V_14 ,
} ;
V_7 = F_4 ( V_2 -> V_15 . V_16 ,
F_5 ( V_6 ) , 0 , & V_11 ) ;
if ( V_7 < 0 )
return V_7 ;
* V_4 = V_9 . V_4 ;
return 0 ;
}
static int F_6 ( struct V_17 * V_18 , struct V_19 * V_20 ,
int V_13 , struct V_10 * V_11 )
{
struct V_8 * V_9 = V_11 -> V_12 ;
struct V_1 * V_4 ;
switch ( V_18 -> V_21 ) {
case V_22 :
break;
case V_23 :
return - V_24 ;
case V_25 :
return - V_26 ;
case V_27 :
default:
return - V_28 ;
}
V_4 = F_1 ( V_18 -> V_29 , V_18 -> V_30 ) ;
if ( ! V_4 )
return - V_31 ;
V_9 -> V_4 = V_4 ;
return 0 ;
}
static int F_7 ( struct V_17 * V_18 , struct V_19 * V_32 , int V_13 )
{
return 1 ;
}
static int F_8 ( struct V_17 * V_18 , struct V_33 * V_34 ,
struct V_35 * V_36 , struct V_37 * * V_38 )
{
return 0 ;
}
static int F_9 ( struct V_17 * V_18 , struct V_35 * V_36 ,
struct V_37 * * V_38 )
{
return 1 ;
}
static int F_10 ( struct V_17 * V_18 , struct V_33 * V_34 ,
struct V_35 * V_36 )
{
V_36 -> V_39 = 0 ;
V_36 -> V_40 = 0 ;
V_36 -> V_41 = 0 ;
return 0 ;
}
static int T_2 F_11 ( struct V_2 * V_2 )
{
struct V_42 * V_43 ;
struct V_1 * V_4 ;
int V_7 ;
V_43 = F_12 ( & V_44 , V_2 ) ;
if ( F_13 ( V_43 ) )
return F_14 ( V_43 ) ;
F_15 ( & V_2 -> V_15 . V_45 ) ;
V_4 = F_16 ( V_2 , V_46 ) ;
if ( F_13 ( V_4 ) ) {
V_7 = F_14 ( V_4 ) ;
goto V_47;
}
V_7 = F_17 ( V_43 , 0x7fff , V_46 , 0 ) ;
if ( V_7 < 0 )
goto V_48;
V_2 -> V_15 . V_16 = V_43 ;
return 0 ;
V_48:
F_18 ( V_4 ) ;
V_47:
F_19 ( V_43 ) ;
return V_7 ;
}
static void T_3 F_20 ( struct V_2 * V_2 )
{
struct V_1 * V_4 , * V_49 ;
F_21 () ;
F_22 (mrt, next, &net->ipv4.mr_tables, list) {
F_23 ( & V_4 -> V_50 ) ;
F_18 ( V_4 ) ;
}
F_19 ( V_2 -> V_15 . V_16 ) ;
F_24 () ;
}
static struct V_1 * F_1 ( struct V_2 * V_2 , T_1 V_3 )
{
return V_2 -> V_15 . V_4 ;
}
static int F_3 ( struct V_2 * V_2 , struct V_5 * V_6 ,
struct V_1 * * V_4 )
{
* V_4 = V_2 -> V_15 . V_4 ;
return 0 ;
}
static int T_2 F_11 ( struct V_2 * V_2 )
{
struct V_1 * V_4 ;
V_4 = F_16 ( V_2 , V_46 ) ;
if ( F_13 ( V_4 ) )
return F_14 ( V_4 ) ;
V_2 -> V_15 . V_4 = V_4 ;
return 0 ;
}
static void T_3 F_20 ( struct V_2 * V_2 )
{
F_21 () ;
F_18 ( V_2 -> V_15 . V_4 ) ;
V_2 -> V_15 . V_4 = NULL ;
F_24 () ;
}
static struct V_1 * F_16 ( struct V_2 * V_2 , T_1 V_3 )
{
struct V_1 * V_4 ;
unsigned int V_51 ;
if ( V_3 != V_46 && V_3 >= 1000000000 )
return F_25 ( - V_28 ) ;
V_4 = F_1 ( V_2 , V_3 ) ;
if ( V_4 )
return V_4 ;
V_4 = F_26 ( sizeof( * V_4 ) , V_52 ) ;
if ( ! V_4 )
return F_25 ( - V_53 ) ;
F_27 ( & V_4 -> V_2 , V_2 ) ;
V_4 -> V_3 = V_3 ;
for ( V_51 = 0 ; V_51 < V_54 ; V_51 ++ )
F_15 ( & V_4 -> V_55 [ V_51 ] ) ;
F_15 ( & V_4 -> V_56 ) ;
F_28 ( & V_4 -> V_57 , V_58 ,
( unsigned long ) V_4 ) ;
V_4 -> V_59 = - 1 ;
#ifdef F_29
F_30 ( & V_4 -> V_50 , & V_2 -> V_15 . V_45 ) ;
#endif
return V_4 ;
}
static void F_18 ( struct V_1 * V_4 )
{
F_31 ( & V_4 -> V_57 ) ;
F_32 ( V_4 , true ) ;
F_33 ( V_4 ) ;
}
static void F_34 ( struct V_60 * V_61 , struct V_62 * V_63 )
{
struct V_2 * V_2 = F_35 ( V_61 ) ;
F_36 ( V_61 ) ;
V_61 = F_37 ( V_2 , L_1 ) ;
if ( V_61 ) {
const struct V_64 * V_43 = V_61 -> V_65 ;
struct V_66 V_67 ;
struct V_68 V_69 ;
memset ( & V_69 , 0 , sizeof( V_69 ) ) ;
V_69 . V_70 . V_71 = V_63 -> V_72 . V_73 ;
V_69 . V_70 . V_74 = V_63 -> V_75 . V_73 ;
V_69 . V_70 . V_76 = 4 ;
V_69 . V_70 . V_77 = 5 ;
V_69 . V_70 . V_78 = V_79 ;
sprintf ( V_69 . V_80 , L_2 , V_63 -> V_81 ) ;
V_67 . V_82 . V_83 = ( V_84 void V_85 * ) & V_69 ;
if ( V_43 -> V_86 ) {
T_4 V_87 = F_38 () ;
F_39 ( V_88 ) ;
V_43 -> V_86 ( V_61 , & V_67 , V_89 ) ;
F_39 ( V_87 ) ;
}
}
}
static bool F_40 ( const struct V_60 * V_61 )
{
struct V_90 * V_91 ;
F_41 () ;
V_91 = F_42 ( V_61 ) ;
if ( ! V_91 )
return false ;
F_43 ( V_91 ) ;
F_44 ( V_91 -> V_92 ) ;
F_45 ( V_91 -> V_93 , V_94 ) = 0 ;
return true ;
}
static struct V_60 * F_46 ( struct V_2 * V_2 , struct V_62 * V_63 )
{
struct V_60 * V_61 ;
V_61 = F_37 ( V_2 , L_1 ) ;
if ( V_61 ) {
const struct V_64 * V_43 = V_61 -> V_65 ;
int V_7 ;
struct V_66 V_67 ;
struct V_68 V_69 ;
memset ( & V_69 , 0 , sizeof( V_69 ) ) ;
V_69 . V_70 . V_71 = V_63 -> V_72 . V_73 ;
V_69 . V_70 . V_74 = V_63 -> V_75 . V_73 ;
V_69 . V_70 . V_76 = 4 ;
V_69 . V_70 . V_77 = 5 ;
V_69 . V_70 . V_78 = V_79 ;
sprintf ( V_69 . V_80 , L_2 , V_63 -> V_81 ) ;
V_67 . V_82 . V_83 = ( V_84 void V_85 * ) & V_69 ;
if ( V_43 -> V_86 ) {
T_4 V_87 = F_38 () ;
F_39 ( V_88 ) ;
V_7 = V_43 -> V_86 ( V_61 , & V_67 , V_95 ) ;
F_39 ( V_87 ) ;
} else {
V_7 = - V_96 ;
}
V_61 = NULL ;
if ( V_7 == 0 &&
( V_61 = F_37 ( V_2 , V_69 . V_80 ) ) != NULL ) {
V_61 -> V_13 |= V_97 ;
if ( ! F_40 ( V_61 ) )
goto V_98;
if ( F_47 ( V_61 ) )
goto V_98;
F_48 ( V_61 ) ;
}
}
return V_61 ;
V_98:
F_49 ( V_61 ) ;
return NULL ;
}
static T_5 F_50 ( struct V_33 * V_34 , struct V_60 * V_61 )
{
struct V_2 * V_2 = F_35 ( V_61 ) ;
struct V_1 * V_4 ;
struct V_5 V_99 = {
. V_100 = V_61 -> V_101 ,
. V_102 = V_34 -> V_103 ? : V_104 ,
. V_105 = V_34 -> V_106 ,
} ;
int V_7 ;
V_7 = F_3 ( V_2 , & V_99 , & V_4 ) ;
if ( V_7 < 0 ) {
F_51 ( V_34 ) ;
return V_7 ;
}
F_52 ( & V_107 ) ;
V_61 -> V_108 . V_109 += V_34 -> V_110 ;
V_61 -> V_108 . V_111 ++ ;
F_53 ( V_4 , V_34 , V_4 -> V_59 , V_112 ) ;
F_54 ( & V_107 ) ;
F_51 ( V_34 ) ;
return V_113 ;
}
static int F_55 ( const struct V_60 * V_61 )
{
return 0 ;
}
static void F_56 ( struct V_60 * V_61 )
{
V_61 -> type = V_114 ;
V_61 -> V_115 = V_116 - sizeof( struct V_117 ) - 8 ;
V_61 -> V_13 = V_118 ;
V_61 -> V_65 = & V_119 ;
V_61 -> V_120 = V_121 ;
V_61 -> V_122 |= V_123 ;
}
static struct V_60 * F_57 ( struct V_2 * V_2 , struct V_1 * V_4 )
{
struct V_60 * V_61 ;
char V_80 [ V_124 ] ;
if ( V_4 -> V_3 == V_46 )
sprintf ( V_80 , L_3 ) ;
else
sprintf ( V_80 , L_4 , V_4 -> V_3 ) ;
V_61 = F_58 ( 0 , V_80 , V_125 , F_56 ) ;
if ( ! V_61 )
return NULL ;
F_59 ( V_61 , V_2 ) ;
if ( F_60 ( V_61 ) ) {
V_121 ( V_61 ) ;
return NULL ;
}
if ( ! F_40 ( V_61 ) )
goto V_98;
if ( F_47 ( V_61 ) )
goto V_98;
F_48 ( V_61 ) ;
return V_61 ;
V_98:
F_49 ( V_61 ) ;
return NULL ;
}
static int F_61 ( struct V_1 * V_4 , struct V_33 * V_34 ,
unsigned int V_126 )
{
struct V_60 * V_127 = NULL ;
struct V_117 * V_128 ;
V_128 = (struct V_117 * ) ( F_62 ( V_34 ) + V_126 ) ;
if ( ! F_63 ( V_128 -> V_71 ) ||
V_128 -> V_129 == 0 ||
F_64 ( V_128 -> V_129 ) + V_126 > V_34 -> V_110 )
return 1 ;
F_52 ( & V_107 ) ;
if ( V_4 -> V_59 >= 0 )
V_127 = V_4 -> V_130 [ V_4 -> V_59 ] . V_61 ;
F_54 ( & V_107 ) ;
if ( ! V_127 )
return 1 ;
V_34 -> V_131 = V_34 -> V_132 ;
F_65 ( V_34 , ( V_133 * ) V_128 - V_34 -> V_134 ) ;
F_66 ( V_34 ) ;
V_34 -> V_78 = F_67 ( V_135 ) ;
V_34 -> V_136 = V_137 ;
F_68 ( V_34 , V_127 , F_35 ( V_127 ) ) ;
F_69 ( V_34 ) ;
return V_138 ;
}
static struct V_60 * F_57 ( struct V_2 * V_2 , struct V_1 * V_4 )
{
return NULL ;
}
static int F_70 ( struct V_1 * V_4 , int V_139 , int V_140 ,
struct V_141 * V_142 )
{
struct V_143 * V_63 ;
struct V_60 * V_61 ;
struct V_90 * V_91 ;
if ( V_139 < 0 || V_139 >= V_4 -> V_144 )
return - V_145 ;
V_63 = & V_4 -> V_130 [ V_139 ] ;
F_71 ( & V_107 ) ;
V_61 = V_63 -> V_61 ;
V_63 -> V_61 = NULL ;
if ( ! V_61 ) {
F_72 ( & V_107 ) ;
return - V_145 ;
}
if ( V_139 == V_4 -> V_59 )
V_4 -> V_59 = - 1 ;
if ( V_139 + 1 == V_4 -> V_144 ) {
int V_146 ;
for ( V_146 = V_139 - 1 ; V_146 >= 0 ; V_146 -- ) {
if ( F_73 ( V_4 , V_146 ) )
break;
}
V_4 -> V_144 = V_146 + 1 ;
}
F_72 ( & V_107 ) ;
F_74 ( V_61 , - 1 ) ;
V_91 = F_42 ( V_61 ) ;
if ( V_91 ) {
F_45 ( V_91 -> V_93 , V_147 ) -- ;
F_75 ( F_35 ( V_61 ) ,
V_148 ,
V_61 -> V_101 , & V_91 -> V_93 ) ;
F_76 ( V_91 ) ;
}
if ( V_63 -> V_13 & ( V_149 | V_150 ) && ! V_140 )
F_77 ( V_61 , V_142 ) ;
F_78 ( V_61 ) ;
return 0 ;
}
static void F_79 ( struct V_151 * V_142 )
{
struct V_152 * V_153 = F_80 ( V_142 , struct V_152 , V_154 ) ;
F_81 ( V_155 , V_153 ) ;
}
static inline void F_82 ( struct V_152 * V_153 )
{
F_83 ( & V_153 -> V_154 , F_79 ) ;
}
static void F_84 ( struct V_1 * V_4 , struct V_152 * V_153 )
{
struct V_2 * V_2 = F_85 ( & V_4 -> V_2 ) ;
struct V_33 * V_34 ;
struct V_156 * V_157 ;
F_86 ( & V_4 -> V_158 ) ;
while ( ( V_34 = F_87 ( & V_153 -> V_159 . V_160 . V_161 ) ) ) {
if ( F_88 ( V_34 ) -> V_76 == 0 ) {
struct V_162 * V_163 = (struct V_162 * ) F_65 ( V_34 , sizeof( struct V_117 ) ) ;
V_163 -> V_164 = V_165 ;
V_163 -> V_166 = F_89 ( sizeof( struct V_156 ) ) ;
F_90 ( V_34 , V_163 -> V_166 ) ;
V_157 = F_91 ( V_163 ) ;
V_157 -> error = - V_167 ;
memset ( & V_157 -> V_168 , 0 , sizeof( V_157 -> V_168 ) ) ;
F_92 ( V_34 , V_2 , F_93 ( V_34 ) . V_169 ) ;
} else {
F_51 ( V_34 ) ;
}
}
F_82 ( V_153 ) ;
}
static void V_58 ( unsigned long V_11 )
{
struct V_1 * V_4 = (struct V_1 * ) V_11 ;
unsigned long V_170 ;
unsigned long V_171 ;
struct V_152 * V_153 , * V_49 ;
if ( ! F_94 ( & V_172 ) ) {
F_95 ( & V_4 -> V_57 , V_173 + V_174 / 10 ) ;
return;
}
if ( F_96 ( & V_4 -> V_56 ) )
goto V_175;
V_170 = V_173 ;
V_171 = 10 * V_174 ;
F_22 (c, next, &mrt->mfc_unres_queue, list) {
if ( F_97 ( V_153 -> V_159 . V_160 . V_171 , V_170 ) ) {
unsigned long V_176 = V_153 -> V_159 . V_160 . V_171 - V_170 ;
if ( V_176 < V_171 )
V_171 = V_176 ;
continue;
}
F_23 ( & V_153 -> V_50 ) ;
F_98 ( V_4 , V_153 , V_177 ) ;
F_84 ( V_4 , V_153 ) ;
}
if ( ! F_96 ( & V_4 -> V_56 ) )
F_95 ( & V_4 -> V_57 , V_173 + V_171 ) ;
V_175:
F_99 ( & V_172 ) ;
}
static void F_100 ( struct V_1 * V_4 , struct V_152 * V_178 ,
unsigned char * V_179 )
{
int V_139 ;
V_178 -> V_159 . V_9 . V_180 = V_181 ;
V_178 -> V_159 . V_9 . V_144 = 0 ;
memset ( V_178 -> V_159 . V_9 . V_179 , 255 , V_181 ) ;
for ( V_139 = 0 ; V_139 < V_4 -> V_144 ; V_139 ++ ) {
if ( F_73 ( V_4 , V_139 ) &&
V_179 [ V_139 ] && V_179 [ V_139 ] < 255 ) {
V_178 -> V_159 . V_9 . V_179 [ V_139 ] = V_179 [ V_139 ] ;
if ( V_178 -> V_159 . V_9 . V_180 > V_139 )
V_178 -> V_159 . V_9 . V_180 = V_139 ;
if ( V_178 -> V_159 . V_9 . V_144 <= V_139 )
V_178 -> V_159 . V_9 . V_144 = V_139 + 1 ;
}
}
V_178 -> V_159 . V_9 . V_182 = V_173 ;
}
static int F_101 ( struct V_2 * V_2 , struct V_1 * V_4 ,
struct V_62 * V_183 , int V_184 )
{
int V_139 = V_183 -> V_81 ;
struct V_143 * V_63 = & V_4 -> V_130 [ V_139 ] ;
struct V_60 * V_61 ;
struct V_90 * V_91 ;
int V_7 ;
if ( F_73 ( V_4 , V_139 ) )
return - V_185 ;
switch ( V_183 -> V_186 ) {
case V_150 :
if ( ! F_102 () )
return - V_28 ;
if ( V_4 -> V_59 >= 0 )
return - V_185 ;
V_61 = F_57 ( V_2 , V_4 ) ;
if ( ! V_61 )
return - V_187 ;
V_7 = F_74 ( V_61 , 1 ) ;
if ( V_7 ) {
F_49 ( V_61 ) ;
F_78 ( V_61 ) ;
return V_7 ;
}
break;
case V_149 :
V_61 = F_46 ( V_2 , V_183 ) ;
if ( ! V_61 )
return - V_187 ;
V_7 = F_74 ( V_61 , 1 ) ;
if ( V_7 ) {
F_34 ( V_61 , V_183 ) ;
F_78 ( V_61 ) ;
return V_7 ;
}
break;
case V_188 :
case 0 :
if ( V_183 -> V_186 == V_188 ) {
V_61 = F_103 ( V_2 , V_183 -> V_189 ) ;
if ( V_61 && ! F_42 ( V_61 ) ) {
F_78 ( V_61 ) ;
return - V_145 ;
}
} else {
V_61 = F_104 ( V_2 , V_183 -> V_75 . V_73 ) ;
}
if ( ! V_61 )
return - V_145 ;
V_7 = F_74 ( V_61 , 1 ) ;
if ( V_7 ) {
F_78 ( V_61 ) ;
return V_7 ;
}
break;
default:
return - V_28 ;
}
V_91 = F_42 ( V_61 ) ;
if ( ! V_91 ) {
F_78 ( V_61 ) ;
return - V_145 ;
}
F_45 ( V_91 -> V_93 , V_147 ) ++ ;
F_75 ( V_2 , V_148 , V_61 -> V_101 ,
& V_91 -> V_93 ) ;
F_76 ( V_91 ) ;
V_63 -> V_190 = V_183 -> V_191 ;
V_63 -> V_192 = V_183 -> V_75 . V_73 ;
V_63 -> V_193 = V_183 -> V_72 . V_73 ;
V_63 -> V_13 = V_183 -> V_186 ;
if ( ! V_184 )
V_63 -> V_13 |= V_194 ;
V_63 -> V_195 = V_183 -> V_196 ;
V_63 -> V_197 = 0 ;
V_63 -> V_198 = 0 ;
V_63 -> V_199 = 0 ;
V_63 -> V_200 = 0 ;
V_63 -> V_201 = V_61 -> V_101 ;
if ( V_63 -> V_13 & ( V_149 | V_150 ) )
V_63 -> V_201 = F_105 ( V_61 ) ;
F_71 ( & V_107 ) ;
V_63 -> V_61 = V_61 ;
if ( V_63 -> V_13 & V_150 )
V_4 -> V_59 = V_139 ;
if ( V_139 + 1 > V_4 -> V_144 )
V_4 -> V_144 = V_139 + 1 ;
F_72 ( & V_107 ) ;
return 0 ;
}
static struct V_152 * F_106 ( struct V_1 * V_4 ,
T_6 V_202 ,
T_6 V_203 )
{
int line = F_107 ( V_203 , V_202 ) ;
struct V_152 * V_153 ;
F_108 (c, &mrt->mfc_cache_array[line], list) {
if ( V_153 -> V_204 == V_202 && V_153 -> V_205 == V_203 )
return V_153 ;
}
return NULL ;
}
static struct V_152 * F_109 ( struct V_1 * V_4 ,
int V_139 )
{
int line = F_107 ( F_110 ( V_206 ) , F_110 ( V_206 ) ) ;
struct V_152 * V_153 ;
F_108 (c, &mrt->mfc_cache_array[line], list)
if ( V_153 -> V_204 == F_110 ( V_206 ) &&
V_153 -> V_205 == F_110 ( V_206 ) &&
V_153 -> V_159 . V_9 . V_179 [ V_139 ] < 255 )
return V_153 ;
return NULL ;
}
static struct V_152 * F_111 ( struct V_1 * V_4 ,
T_6 V_203 , int V_139 )
{
int line = F_107 ( V_203 , F_110 ( V_206 ) ) ;
struct V_152 * V_153 , * V_207 ;
if ( V_203 == F_110 ( V_206 ) )
goto V_208;
F_108 (c, &mrt->mfc_cache_array[line], list)
if ( V_153 -> V_204 == F_110 ( V_206 ) &&
V_153 -> V_205 == V_203 ) {
if ( V_153 -> V_159 . V_9 . V_179 [ V_139 ] < 255 )
return V_153 ;
V_207 = F_109 ( V_4 ,
V_153 -> V_209 ) ;
if ( V_207 && V_207 -> V_159 . V_9 . V_179 [ V_139 ] < 255 )
return V_153 ;
}
V_208:
return F_109 ( V_4 , V_139 ) ;
}
static struct V_152 * F_112 ( void )
{
struct V_152 * V_153 = F_113 ( V_155 , V_52 ) ;
if ( V_153 ) {
V_153 -> V_159 . V_9 . V_210 = V_173 - V_211 - 1 ;
V_153 -> V_159 . V_9 . V_180 = V_181 ;
}
return V_153 ;
}
static struct V_152 * F_114 ( void )
{
struct V_152 * V_153 = F_113 ( V_155 , V_212 ) ;
if ( V_153 ) {
F_115 ( & V_153 -> V_159 . V_160 . V_161 ) ;
V_153 -> V_159 . V_160 . V_171 = V_173 + 10 * V_174 ;
}
return V_153 ;
}
static void F_116 ( struct V_2 * V_2 , struct V_1 * V_4 ,
struct V_152 * V_213 , struct V_152 * V_153 )
{
struct V_33 * V_34 ;
struct V_156 * V_157 ;
while ( ( V_34 = F_117 ( & V_213 -> V_159 . V_160 . V_161 ) ) ) {
if ( F_88 ( V_34 ) -> V_76 == 0 ) {
struct V_162 * V_163 = (struct V_162 * ) F_65 ( V_34 , sizeof( struct V_117 ) ) ;
if ( F_118 ( V_4 , V_34 , V_153 , F_91 ( V_163 ) ) > 0 ) {
V_163 -> V_166 = F_119 ( V_34 ) -
( V_133 * ) V_163 ;
} else {
V_163 -> V_164 = V_165 ;
V_163 -> V_166 = F_89 ( sizeof( struct V_156 ) ) ;
F_90 ( V_34 , V_163 -> V_166 ) ;
V_157 = F_91 ( V_163 ) ;
V_157 -> error = - V_214 ;
memset ( & V_157 -> V_168 , 0 , sizeof( V_157 -> V_168 ) ) ;
}
F_92 ( V_34 , V_2 , F_93 ( V_34 ) . V_169 ) ;
} else {
F_120 ( V_2 , V_4 , V_34 , V_153 , 0 ) ;
}
}
}
static int F_53 ( struct V_1 * V_4 ,
struct V_33 * V_215 , T_7 V_139 , int assert )
{
const int V_77 = F_121 ( V_215 ) ;
struct V_216 * V_217 ;
struct V_218 * V_219 ;
struct V_220 * V_168 ;
struct V_33 * V_34 ;
int V_221 ;
if ( assert == V_112 )
V_34 = F_122 ( V_215 , sizeof( struct V_117 ) ) ;
else
V_34 = F_123 ( 128 , V_212 ) ;
if ( ! V_34 )
return - V_187 ;
if ( assert == V_112 ) {
F_124 ( V_34 , sizeof( struct V_117 ) ) ;
F_66 ( V_34 ) ;
F_125 ( V_34 ) ;
V_168 = (struct V_220 * ) F_126 ( V_34 ) ;
memcpy ( V_168 , F_126 ( V_215 ) , sizeof( struct V_117 ) ) ;
V_168 -> V_222 = V_112 ;
V_168 -> V_223 = 0 ;
V_168 -> V_224 = V_4 -> V_59 ;
F_88 ( V_34 ) -> V_77 = sizeof( struct V_117 ) >> 2 ;
F_88 ( V_34 ) -> V_129 = F_67 ( F_64 ( F_88 ( V_215 ) -> V_129 ) +
sizeof( struct V_117 ) ) ;
} else {
F_127 ( V_34 , V_34 -> V_110 ) ;
F_128 ( V_34 , V_77 ) ;
F_129 ( V_34 , V_215 -> V_134 , V_77 ) ;
F_88 ( V_34 ) -> V_78 = 0 ;
V_168 = (struct V_220 * ) F_126 ( V_34 ) ;
V_168 -> V_224 = V_139 ;
F_130 ( V_34 , F_131 ( F_132 ( V_215 ) ) ) ;
V_219 = (struct V_218 * ) F_128 ( V_34 , sizeof( struct V_218 ) ) ;
V_219 -> type = assert ;
V_168 -> V_222 = assert ;
V_219 -> V_225 = 0 ;
F_88 ( V_34 ) -> V_129 = F_67 ( V_34 -> V_110 ) ;
V_34 -> V_226 = V_34 -> V_132 ;
}
F_133 () ;
V_217 = F_134 ( V_4 -> V_217 ) ;
if ( ! V_217 ) {
F_135 () ;
F_51 ( V_34 ) ;
return - V_28 ;
}
V_221 = F_136 ( V_217 , V_34 ) ;
F_135 () ;
if ( V_221 < 0 ) {
F_137 ( L_5 ) ;
F_51 ( V_34 ) ;
}
return V_221 ;
}
static int F_138 ( struct V_1 * V_4 , T_7 V_139 ,
struct V_33 * V_34 )
{
bool V_227 = false ;
int V_7 ;
struct V_152 * V_153 ;
const struct V_117 * V_70 = F_88 ( V_34 ) ;
F_139 ( & V_172 ) ;
F_140 (c, &mrt->mfc_unres_queue, list) {
if ( V_153 -> V_205 == V_70 -> V_71 &&
V_153 -> V_204 == V_70 -> V_74 ) {
V_227 = true ;
break;
}
}
if ( ! V_227 ) {
if ( F_141 ( & V_4 -> V_158 ) >= 10 ||
( V_153 = F_114 () ) == NULL ) {
F_142 ( & V_172 ) ;
F_51 ( V_34 ) ;
return - V_187 ;
}
V_153 -> V_209 = - 1 ;
V_153 -> V_204 = V_70 -> V_74 ;
V_153 -> V_205 = V_70 -> V_71 ;
V_7 = F_53 ( V_4 , V_34 , V_139 , V_228 ) ;
if ( V_7 < 0 ) {
F_142 ( & V_172 ) ;
F_82 ( V_153 ) ;
F_51 ( V_34 ) ;
return V_7 ;
}
F_143 ( & V_4 -> V_158 ) ;
F_144 ( & V_153 -> V_50 , & V_4 -> V_56 ) ;
F_98 ( V_4 , V_153 , V_229 ) ;
if ( F_141 ( & V_4 -> V_158 ) == 1 )
F_95 ( & V_4 -> V_57 , V_153 -> V_159 . V_160 . V_171 ) ;
}
if ( V_153 -> V_159 . V_160 . V_161 . V_230 > 3 ) {
F_51 ( V_34 ) ;
V_7 = - V_187 ;
} else {
F_145 ( & V_153 -> V_159 . V_160 . V_161 , V_34 ) ;
V_7 = 0 ;
}
F_142 ( & V_172 ) ;
return V_7 ;
}
static int F_146 ( struct V_1 * V_4 , struct V_231 * V_232 , int V_233 )
{
int line ;
struct V_152 * V_153 , * V_49 ;
line = F_107 ( V_232 -> V_234 . V_73 , V_232 -> V_235 . V_73 ) ;
F_22 (c, next, &mrt->mfc_cache_array[line], list) {
if ( V_153 -> V_204 == V_232 -> V_235 . V_73 &&
V_153 -> V_205 == V_232 -> V_234 . V_73 &&
( V_233 == - 1 || V_233 == V_153 -> V_209 ) ) {
F_147 ( & V_153 -> V_50 ) ;
F_98 ( V_4 , V_153 , V_177 ) ;
F_82 ( V_153 ) ;
return 0 ;
}
}
return - V_236 ;
}
static int F_148 ( struct V_2 * V_2 , struct V_1 * V_4 ,
struct V_231 * V_232 , int V_184 , int V_233 )
{
bool V_227 = false ;
int line ;
struct V_152 * V_213 , * V_153 ;
if ( V_232 -> V_237 >= V_181 )
return - V_238 ;
line = F_107 ( V_232 -> V_234 . V_73 , V_232 -> V_235 . V_73 ) ;
F_140 (c, &mrt->mfc_cache_array[line], list) {
if ( V_153 -> V_204 == V_232 -> V_235 . V_73 &&
V_153 -> V_205 == V_232 -> V_234 . V_73 &&
( V_233 == - 1 || V_233 == V_153 -> V_209 ) ) {
V_227 = true ;
break;
}
}
if ( V_227 ) {
F_71 ( & V_107 ) ;
V_153 -> V_209 = V_232 -> V_237 ;
F_100 ( V_4 , V_153 , V_232 -> V_239 ) ;
if ( ! V_184 )
V_153 -> V_240 |= V_241 ;
F_72 ( & V_107 ) ;
F_98 ( V_4 , V_153 , V_229 ) ;
return 0 ;
}
if ( V_232 -> V_234 . V_73 != F_110 ( V_206 ) &&
! F_63 ( V_232 -> V_234 . V_73 ) )
return - V_28 ;
V_153 = F_112 () ;
if ( ! V_153 )
return - V_53 ;
V_153 -> V_204 = V_232 -> V_235 . V_73 ;
V_153 -> V_205 = V_232 -> V_234 . V_73 ;
V_153 -> V_209 = V_232 -> V_237 ;
F_100 ( V_4 , V_153 , V_232 -> V_239 ) ;
if ( ! V_184 )
V_153 -> V_240 |= V_241 ;
F_149 ( & V_153 -> V_50 , & V_4 -> V_55 [ line ] ) ;
V_227 = false ;
F_139 ( & V_172 ) ;
F_140 (uc, &mrt->mfc_unres_queue, list) {
if ( V_213 -> V_204 == V_153 -> V_204 &&
V_213 -> V_205 == V_153 -> V_205 ) {
F_23 ( & V_213 -> V_50 ) ;
F_86 ( & V_4 -> V_158 ) ;
V_227 = true ;
break;
}
}
if ( F_96 ( & V_4 -> V_56 ) )
F_150 ( & V_4 -> V_57 ) ;
F_142 ( & V_172 ) ;
if ( V_227 ) {
F_116 ( V_2 , V_4 , V_213 , V_153 ) ;
F_82 ( V_213 ) ;
}
F_98 ( V_4 , V_153 , V_229 ) ;
return 0 ;
}
static void F_32 ( struct V_1 * V_4 , bool V_242 )
{
int V_51 ;
F_151 ( V_50 ) ;
struct V_152 * V_153 , * V_49 ;
for ( V_51 = 0 ; V_51 < V_4 -> V_144 ; V_51 ++ ) {
if ( ! V_242 && ( V_4 -> V_130 [ V_51 ] . V_13 & V_194 ) )
continue;
F_70 ( V_4 , V_51 , 0 , & V_50 ) ;
}
F_152 ( & V_50 ) ;
for ( V_51 = 0 ; V_51 < V_54 ; V_51 ++ ) {
F_22 (c, next, &mrt->mfc_cache_array[i], list) {
if ( ! V_242 && ( V_153 -> V_240 & V_241 ) )
continue;
F_147 ( & V_153 -> V_50 ) ;
F_98 ( V_4 , V_153 , V_177 ) ;
F_82 ( V_153 ) ;
}
}
if ( F_141 ( & V_4 -> V_158 ) != 0 ) {
F_139 ( & V_172 ) ;
F_22 (c, next, &mrt->mfc_unres_queue, list) {
F_23 ( & V_153 -> V_50 ) ;
F_98 ( V_4 , V_153 , V_177 ) ;
F_84 ( V_4 , V_153 ) ;
}
F_142 ( & V_172 ) ;
}
}
static void F_153 ( struct V_216 * V_243 )
{
struct V_2 * V_2 = F_154 ( V_243 ) ;
struct V_1 * V_4 ;
F_21 () ;
F_2 (mrt, net) {
if ( V_243 == F_155 ( V_4 -> V_217 ) ) {
F_156 ( V_2 , V_147 ) -- ;
F_75 ( V_2 , V_148 ,
V_244 ,
V_2 -> V_15 . V_245 ) ;
F_157 ( V_4 -> V_217 , NULL ) ;
F_32 ( V_4 , false ) ;
}
}
F_24 () ;
}
int F_158 ( struct V_216 * V_243 , int V_246 , char V_85 * V_247 ,
unsigned int V_248 )
{
struct V_2 * V_2 = F_154 ( V_243 ) ;
int V_249 , V_221 = 0 , V_233 = 0 ;
struct V_1 * V_4 ;
struct V_62 V_250 ;
struct V_231 V_232 ;
T_1 V_251 ;
F_21 () ;
if ( V_243 -> V_252 != V_253 ||
F_159 ( V_243 ) -> V_254 != V_255 ) {
V_221 = - V_96 ;
goto V_256;
}
V_4 = F_1 ( V_2 , F_160 ( V_243 ) -> V_257 ? : V_46 ) ;
if ( ! V_4 ) {
V_221 = - V_236 ;
goto V_256;
}
if ( V_246 != V_258 ) {
if ( V_243 != F_161 ( V_4 -> V_217 ) &&
! F_162 ( V_2 -> V_259 , V_260 ) ) {
V_221 = - V_26 ;
goto V_256;
}
}
switch ( V_246 ) {
case V_258 :
if ( V_248 != sizeof( int ) ) {
V_221 = - V_28 ;
break;
}
if ( F_155 ( V_4 -> V_217 ) ) {
V_221 = - V_185 ;
break;
}
V_221 = F_163 ( V_243 , 1 , F_153 ) ;
if ( V_221 == 0 ) {
F_164 ( V_4 -> V_217 , V_243 ) ;
F_156 ( V_2 , V_147 ) ++ ;
F_75 ( V_2 , V_148 ,
V_244 ,
V_2 -> V_15 . V_245 ) ;
}
break;
case V_261 :
if ( V_243 != F_161 ( V_4 -> V_217 ) ) {
V_221 = - V_26 ;
} else {
F_24 () ;
V_221 = F_163 ( V_243 , 0 , NULL ) ;
goto V_175;
}
break;
case V_262 :
case V_263 :
if ( V_248 != sizeof( V_250 ) ) {
V_221 = - V_28 ;
break;
}
if ( F_165 ( & V_250 , V_247 , sizeof( V_250 ) ) ) {
V_221 = - V_264 ;
break;
}
if ( V_250 . V_81 >= V_181 ) {
V_221 = - V_238 ;
break;
}
if ( V_246 == V_262 ) {
V_221 = F_101 ( V_2 , V_4 , & V_250 ,
V_243 == F_155 ( V_4 -> V_217 ) ) ;
} else {
V_221 = F_70 ( V_4 , V_250 . V_81 , 0 , NULL ) ;
}
break;
case V_265 :
case V_266 :
V_233 = - 1 ;
case V_267 :
case V_268 :
if ( V_248 != sizeof( V_232 ) ) {
V_221 = - V_28 ;
break;
}
if ( F_165 ( & V_232 , V_247 , sizeof( V_232 ) ) ) {
V_221 = - V_264 ;
break;
}
if ( V_233 == 0 )
V_233 = V_232 . V_237 ;
if ( V_246 == V_266 || V_246 == V_268 )
V_221 = F_146 ( V_4 , & V_232 , V_233 ) ;
else
V_221 = F_148 ( V_2 , V_4 , & V_232 ,
V_243 == F_155 ( V_4 -> V_217 ) ,
V_233 ) ;
break;
case V_269 :
if ( V_248 != sizeof( V_249 ) ) {
V_221 = - V_28 ;
break;
}
if ( F_166 ( V_249 , ( int V_85 * ) V_247 ) ) {
V_221 = - V_264 ;
break;
}
V_4 -> V_270 = V_249 ;
break;
case V_271 :
if ( ! F_102 () ) {
V_221 = - V_272 ;
break;
}
if ( V_248 != sizeof( V_249 ) ) {
V_221 = - V_28 ;
break;
}
if ( F_166 ( V_249 , ( int V_85 * ) V_247 ) ) {
V_221 = - V_264 ;
break;
}
V_249 = ! ! V_249 ;
if ( V_249 != V_4 -> V_273 ) {
V_4 -> V_273 = V_249 ;
V_4 -> V_270 = V_249 ;
}
break;
case V_274 :
if ( ! F_167 ( F_29 ) ) {
V_221 = - V_272 ;
break;
}
if ( V_248 != sizeof( V_251 ) ) {
V_221 = - V_28 ;
break;
}
if ( F_166 ( V_251 , ( T_1 V_85 * ) V_247 ) ) {
V_221 = - V_264 ;
break;
}
if ( V_243 == F_155 ( V_4 -> V_217 ) ) {
V_221 = - V_275 ;
} else {
V_4 = F_16 ( V_2 , V_251 ) ;
if ( F_13 ( V_4 ) )
V_221 = F_14 ( V_4 ) ;
else
F_160 ( V_243 ) -> V_257 = V_251 ;
}
break;
default:
V_221 = - V_272 ;
}
V_256:
F_24 () ;
V_175:
return V_221 ;
}
int F_168 ( struct V_216 * V_243 , int V_246 , char V_85 * V_247 , int V_85 * V_248 )
{
int V_276 ;
int V_249 ;
struct V_2 * V_2 = F_154 ( V_243 ) ;
struct V_1 * V_4 ;
if ( V_243 -> V_252 != V_253 ||
F_159 ( V_243 ) -> V_254 != V_255 )
return - V_96 ;
V_4 = F_1 ( V_2 , F_160 ( V_243 ) -> V_257 ? : V_46 ) ;
if ( ! V_4 )
return - V_236 ;
switch ( V_246 ) {
case V_277 :
V_249 = 0x0305 ;
break;
case V_271 :
if ( ! F_102 () )
return - V_272 ;
V_249 = V_4 -> V_273 ;
break;
case V_269 :
V_249 = V_4 -> V_270 ;
break;
default:
return - V_272 ;
}
if ( F_166 ( V_276 , V_248 ) )
return - V_264 ;
V_276 = F_169 (unsigned int, olr, sizeof(int)) ;
if ( V_276 < 0 )
return - V_28 ;
if ( F_170 ( V_276 , V_248 ) )
return - V_264 ;
if ( F_171 ( V_247 , & V_249 , V_276 ) )
return - V_264 ;
return 0 ;
}
int F_172 ( struct V_216 * V_243 , int V_278 , void V_85 * V_11 )
{
struct V_279 V_280 ;
struct V_281 V_282 ;
struct V_143 * V_250 ;
struct V_152 * V_153 ;
struct V_2 * V_2 = F_154 ( V_243 ) ;
struct V_1 * V_4 ;
V_4 = F_1 ( V_2 , F_160 ( V_243 ) -> V_257 ? : V_46 ) ;
if ( ! V_4 )
return - V_236 ;
switch ( V_278 ) {
case V_283 :
if ( F_165 ( & V_282 , V_11 , sizeof( V_282 ) ) )
return - V_264 ;
if ( V_282 . V_139 >= V_4 -> V_144 )
return - V_28 ;
F_52 ( & V_107 ) ;
V_250 = & V_4 -> V_130 [ V_282 . V_139 ] ;
if ( F_73 ( V_4 , V_282 . V_139 ) ) {
V_282 . V_284 = V_250 -> V_199 ;
V_282 . V_285 = V_250 -> V_200 ;
V_282 . V_286 = V_250 -> V_197 ;
V_282 . V_287 = V_250 -> V_198 ;
F_54 ( & V_107 ) ;
if ( F_171 ( V_11 , & V_282 , sizeof( V_282 ) ) )
return - V_264 ;
return 0 ;
}
F_54 ( & V_107 ) ;
return - V_145 ;
case V_288 :
if ( F_165 ( & V_280 , V_11 , sizeof( V_280 ) ) )
return - V_264 ;
F_133 () ;
V_153 = F_106 ( V_4 , V_280 . V_289 . V_73 , V_280 . V_290 . V_73 ) ;
if ( V_153 ) {
V_280 . V_291 = V_153 -> V_159 . V_9 . V_215 ;
V_280 . V_292 = V_153 -> V_159 . V_9 . V_293 ;
V_280 . V_294 = V_153 -> V_159 . V_9 . V_294 ;
F_135 () ;
if ( F_171 ( V_11 , & V_280 , sizeof( V_280 ) ) )
return - V_264 ;
return 0 ;
}
F_135 () ;
return - V_145 ;
default:
return - V_295 ;
}
}
int F_173 ( struct V_216 * V_243 , unsigned int V_278 , void V_85 * V_11 )
{
struct V_296 V_280 ;
struct V_297 V_282 ;
struct V_143 * V_250 ;
struct V_152 * V_153 ;
struct V_2 * V_2 = F_154 ( V_243 ) ;
struct V_1 * V_4 ;
V_4 = F_1 ( V_2 , F_160 ( V_243 ) -> V_257 ? : V_46 ) ;
if ( ! V_4 )
return - V_236 ;
switch ( V_278 ) {
case V_283 :
if ( F_165 ( & V_282 , V_11 , sizeof( V_282 ) ) )
return - V_264 ;
if ( V_282 . V_139 >= V_4 -> V_144 )
return - V_28 ;
F_52 ( & V_107 ) ;
V_250 = & V_4 -> V_130 [ V_282 . V_139 ] ;
if ( F_73 ( V_4 , V_282 . V_139 ) ) {
V_282 . V_284 = V_250 -> V_199 ;
V_282 . V_285 = V_250 -> V_200 ;
V_282 . V_286 = V_250 -> V_197 ;
V_282 . V_287 = V_250 -> V_198 ;
F_54 ( & V_107 ) ;
if ( F_171 ( V_11 , & V_282 , sizeof( V_282 ) ) )
return - V_264 ;
return 0 ;
}
F_54 ( & V_107 ) ;
return - V_145 ;
case V_288 :
if ( F_165 ( & V_280 , V_11 , sizeof( V_280 ) ) )
return - V_264 ;
F_133 () ;
V_153 = F_106 ( V_4 , V_280 . V_289 . V_73 , V_280 . V_290 . V_73 ) ;
if ( V_153 ) {
V_280 . V_291 = V_153 -> V_159 . V_9 . V_215 ;
V_280 . V_292 = V_153 -> V_159 . V_9 . V_293 ;
V_280 . V_294 = V_153 -> V_159 . V_9 . V_294 ;
F_135 () ;
if ( F_171 ( V_11 , & V_280 , sizeof( V_280 ) ) )
return - V_264 ;
return 0 ;
}
F_135 () ;
return - V_145 ;
default:
return - V_295 ;
}
}
static int F_174 ( struct V_298 * V_299 , unsigned long V_300 , void * V_301 )
{
struct V_60 * V_61 = F_175 ( V_301 ) ;
struct V_2 * V_2 = F_35 ( V_61 ) ;
struct V_1 * V_4 ;
struct V_143 * V_63 ;
int V_302 ;
if ( V_300 != V_303 )
return V_304 ;
F_2 (mrt, net) {
V_63 = & V_4 -> V_130 [ 0 ] ;
for ( V_302 = 0 ; V_302 < V_4 -> V_144 ; V_302 ++ , V_63 ++ ) {
if ( V_63 -> V_61 == V_61 )
F_70 ( V_4 , V_302 , 1 , NULL ) ;
}
}
return V_304 ;
}
static void F_176 ( struct V_2 * V_2 , struct V_33 * V_34 ,
T_6 V_74 , T_6 V_71 )
{
struct V_117 * V_70 ;
const struct V_117 * V_305 = F_88 ( V_34 ) ;
F_124 ( V_34 , sizeof( struct V_117 ) ) ;
V_34 -> V_226 = V_34 -> V_132 ;
F_66 ( V_34 ) ;
V_70 = F_88 ( V_34 ) ;
V_70 -> V_76 = 4 ;
V_70 -> V_41 = V_305 -> V_41 ;
V_70 -> V_306 = V_305 -> V_306 ;
V_70 -> V_307 = 0 ;
V_70 -> V_71 = V_71 ;
V_70 -> V_74 = V_74 ;
V_70 -> V_78 = V_79 ;
V_70 -> V_77 = 5 ;
V_70 -> V_129 = F_67 ( V_34 -> V_110 ) ;
F_177 ( V_2 , V_34 , NULL ) ;
F_178 ( V_70 ) ;
memset ( & ( F_179 ( V_34 ) -> V_308 ) , 0 , sizeof( F_179 ( V_34 ) -> V_308 ) ) ;
F_180 ( V_34 ) ;
}
static inline int F_181 ( struct V_2 * V_2 , struct V_216 * V_243 ,
struct V_33 * V_34 )
{
struct V_309 * V_308 = & ( F_179 ( V_34 ) -> V_308 ) ;
F_182 ( V_2 , V_310 ) ;
F_183 ( V_2 , V_311 , V_34 -> V_110 ) ;
if ( F_184 ( V_308 -> V_248 ) )
F_185 ( V_34 ) ;
return F_186 ( V_2 , V_243 , V_34 ) ;
}
static void F_187 ( struct V_2 * V_2 , struct V_1 * V_4 ,
struct V_33 * V_34 , struct V_152 * V_153 , int V_139 )
{
const struct V_117 * V_70 = F_88 ( V_34 ) ;
struct V_143 * V_250 = & V_4 -> V_130 [ V_139 ] ;
struct V_60 * V_61 ;
struct V_312 * V_313 ;
struct V_5 V_99 ;
int V_128 = 0 ;
if ( ! V_250 -> V_61 )
goto V_314;
if ( V_250 -> V_13 & V_150 ) {
V_250 -> V_200 ++ ;
V_250 -> V_198 += V_34 -> V_110 ;
V_250 -> V_61 -> V_108 . V_109 += V_34 -> V_110 ;
V_250 -> V_61 -> V_108 . V_111 ++ ;
F_53 ( V_4 , V_34 , V_139 , V_112 ) ;
goto V_314;
}
if ( V_250 -> V_13 & V_149 ) {
V_313 = F_188 ( V_2 , & V_99 , NULL ,
V_250 -> V_193 , V_250 -> V_192 ,
0 , 0 ,
V_79 ,
F_189 ( V_70 -> V_41 ) , V_250 -> V_201 ) ;
if ( F_13 ( V_313 ) )
goto V_314;
V_128 = sizeof( struct V_117 ) ;
} else {
V_313 = F_188 ( V_2 , & V_99 , NULL , V_70 -> V_71 , 0 ,
0 , 0 ,
V_79 ,
F_189 ( V_70 -> V_41 ) , V_250 -> V_201 ) ;
if ( F_13 ( V_313 ) )
goto V_314;
}
V_61 = V_313 -> V_315 . V_61 ;
if ( V_34 -> V_110 + V_128 > F_190 ( & V_313 -> V_315 ) && ( F_64 ( V_70 -> V_307 ) & V_316 ) ) {
F_182 ( V_2 , V_317 ) ;
F_191 ( V_313 ) ;
goto V_314;
}
V_128 += F_192 ( V_61 ) + V_313 -> V_315 . V_318 ;
if ( F_193 ( V_34 , V_128 ) ) {
F_191 ( V_313 ) ;
goto V_314;
}
V_250 -> V_200 ++ ;
V_250 -> V_198 += V_34 -> V_110 ;
F_194 ( V_34 ) ;
F_130 ( V_34 , & V_313 -> V_315 ) ;
F_195 ( F_88 ( V_34 ) ) ;
if ( V_250 -> V_13 & V_149 ) {
F_176 ( V_2 , V_34 , V_250 -> V_192 , V_250 -> V_193 ) ;
V_250 -> V_61 -> V_108 . V_111 ++ ;
V_250 -> V_61 -> V_108 . V_109 += V_34 -> V_110 ;
}
F_179 ( V_34 ) -> V_13 |= V_319 | V_320 ;
F_196 ( V_321 , V_322 ,
V_2 , NULL , V_34 , V_34 -> V_61 , V_61 ,
F_181 ) ;
return;
V_314:
F_51 ( V_34 ) ;
}
static int F_197 ( struct V_1 * V_4 , struct V_60 * V_61 )
{
int V_302 ;
for ( V_302 = V_4 -> V_144 - 1 ; V_302 >= 0 ; V_302 -- ) {
if ( V_4 -> V_130 [ V_302 ] . V_61 == V_61 )
break;
}
return V_302 ;
}
static void F_120 ( struct V_2 * V_2 , struct V_1 * V_4 ,
struct V_33 * V_34 , struct V_152 * V_178 ,
int V_192 )
{
int V_323 = - 1 ;
int V_250 , V_302 ;
int V_324 = F_197 ( V_4 , V_34 -> V_61 ) ;
V_250 = V_178 -> V_209 ;
V_178 -> V_159 . V_9 . V_215 ++ ;
V_178 -> V_159 . V_9 . V_293 += V_34 -> V_110 ;
V_178 -> V_159 . V_9 . V_182 = V_173 ;
if ( V_178 -> V_204 == F_110 ( V_206 ) && V_324 >= 0 ) {
struct V_152 * V_325 ;
V_325 = F_109 ( V_4 , V_250 ) ;
if ( V_325 &&
V_325 -> V_159 . V_9 . V_179 [ V_324 ] < 255 )
goto V_326;
}
if ( V_4 -> V_130 [ V_250 ] . V_61 != V_34 -> V_61 ) {
if ( F_198 ( F_199 ( V_34 ) ) ) {
goto V_327;
}
V_178 -> V_159 . V_9 . V_294 ++ ;
if ( V_324 >= 0 && V_4 -> V_270 &&
( V_4 -> V_273 ||
V_178 -> V_159 . V_9 . V_179 [ V_324 ] < 255 ) &&
F_97 ( V_173 ,
V_178 -> V_159 . V_9 . V_210 + V_211 ) ) {
V_178 -> V_159 . V_9 . V_210 = V_173 ;
F_53 ( V_4 , V_34 , V_324 , V_328 ) ;
}
goto V_327;
}
V_326:
V_4 -> V_130 [ V_250 ] . V_199 ++ ;
V_4 -> V_130 [ V_250 ] . V_197 += V_34 -> V_110 ;
if ( V_178 -> V_204 == F_110 ( V_206 ) &&
V_178 -> V_205 == F_110 ( V_206 ) ) {
if ( V_324 >= 0 &&
V_324 != V_178 -> V_209 &&
F_88 ( V_34 ) -> V_306 >
V_178 -> V_159 . V_9 . V_179 [ V_178 -> V_209 ] ) {
V_323 = V_178 -> V_209 ;
goto V_329;
}
goto V_327;
}
for ( V_302 = V_178 -> V_159 . V_9 . V_144 - 1 ;
V_302 >= V_178 -> V_159 . V_9 . V_180 ; V_302 -- ) {
if ( ( V_178 -> V_204 != F_110 ( V_206 ) ||
V_302 != V_324 ) &&
F_88 ( V_34 ) -> V_306 > V_178 -> V_159 . V_9 . V_179 [ V_302 ] ) {
if ( V_323 != - 1 ) {
struct V_33 * V_330 = F_200 ( V_34 , V_212 ) ;
if ( V_330 )
F_187 ( V_2 , V_4 , V_330 , V_178 ,
V_323 ) ;
}
V_323 = V_302 ;
}
}
V_329:
if ( V_323 != - 1 ) {
if ( V_192 ) {
struct V_33 * V_330 = F_200 ( V_34 , V_212 ) ;
if ( V_330 )
F_187 ( V_2 , V_4 , V_330 , V_178 , V_323 ) ;
} else {
F_187 ( V_2 , V_4 , V_34 , V_178 , V_323 ) ;
return;
}
}
V_327:
if ( ! V_192 )
F_51 ( V_34 ) ;
}
static struct V_1 * F_201 ( struct V_2 * V_2 , struct V_33 * V_34 )
{
struct V_312 * V_313 = F_199 ( V_34 ) ;
struct V_117 * V_70 = F_88 ( V_34 ) ;
struct V_5 V_99 = {
. V_71 = V_70 -> V_71 ,
. V_74 = V_70 -> V_74 ,
. V_331 = F_189 ( V_70 -> V_41 ) ,
. V_100 = ( F_198 ( V_313 ) ?
V_34 -> V_61 -> V_101 : 0 ) ,
. V_102 = ( F_198 ( V_313 ) ?
V_104 :
V_34 -> V_61 -> V_101 ) ,
. V_105 = V_34 -> V_106 ,
} ;
struct V_1 * V_4 ;
int V_7 ;
V_7 = F_3 ( V_2 , & V_99 , & V_4 ) ;
if ( V_7 )
return F_25 ( V_7 ) ;
return V_4 ;
}
int F_202 ( struct V_33 * V_34 )
{
struct V_152 * V_178 ;
struct V_2 * V_2 = F_35 ( V_34 -> V_61 ) ;
int V_192 = F_199 ( V_34 ) -> V_332 & V_333 ;
struct V_1 * V_4 ;
if ( F_179 ( V_34 ) -> V_13 & V_319 )
goto V_327;
V_4 = F_201 ( V_2 , V_34 ) ;
if ( F_13 ( V_4 ) ) {
F_51 ( V_34 ) ;
return F_14 ( V_4 ) ;
}
if ( ! V_192 ) {
if ( F_179 ( V_34 ) -> V_308 . V_334 ) {
if ( F_203 ( V_34 ) )
return 0 ;
} else if ( F_88 ( V_34 ) -> V_78 == V_255 ) {
struct V_216 * V_217 ;
V_217 = F_134 ( V_4 -> V_217 ) ;
if ( V_217 ) {
F_180 ( V_34 ) ;
F_204 ( V_217 , V_34 ) ;
return 0 ;
}
}
}
V_178 = F_106 ( V_4 , F_88 ( V_34 ) -> V_74 , F_88 ( V_34 ) -> V_71 ) ;
if ( ! V_178 ) {
int V_250 = F_197 ( V_4 , V_34 -> V_61 ) ;
if ( V_250 >= 0 )
V_178 = F_111 ( V_4 , F_88 ( V_34 ) -> V_71 ,
V_250 ) ;
}
if ( ! V_178 ) {
int V_250 ;
if ( V_192 ) {
struct V_33 * V_330 = F_200 ( V_34 , V_212 ) ;
F_205 ( V_34 ) ;
if ( ! V_330 )
return - V_187 ;
V_34 = V_330 ;
}
F_52 ( & V_107 ) ;
V_250 = F_197 ( V_4 , V_34 -> V_61 ) ;
if ( V_250 >= 0 ) {
int V_48 = F_138 ( V_4 , V_250 , V_34 ) ;
F_54 ( & V_107 ) ;
return V_48 ;
}
F_54 ( & V_107 ) ;
F_51 ( V_34 ) ;
return - V_335 ;
}
F_52 ( & V_107 ) ;
F_120 ( V_2 , V_4 , V_34 , V_178 , V_192 ) ;
F_54 ( & V_107 ) ;
if ( V_192 )
return F_205 ( V_34 ) ;
return 0 ;
V_327:
if ( V_192 )
return F_205 ( V_34 ) ;
F_51 ( V_34 ) ;
return 0 ;
}
int F_206 ( struct V_33 * V_34 )
{
struct V_218 * V_336 ;
struct V_2 * V_2 = F_35 ( V_34 -> V_61 ) ;
struct V_1 * V_4 ;
if ( ! F_207 ( V_34 , sizeof( * V_336 ) + sizeof( struct V_117 ) ) )
goto V_337;
V_336 = F_208 ( V_34 ) ;
V_4 = F_201 ( V_2 , V_34 ) ;
if ( F_13 ( V_4 ) )
goto V_337;
if ( ! V_4 -> V_273 ||
V_336 -> V_338 != V_339 || V_336 -> V_225 != V_340 )
goto V_337;
if ( F_61 ( V_4 , V_34 , sizeof( * V_336 ) ) ) {
V_337:
F_51 ( V_34 ) ;
}
return 0 ;
}
static int F_209 ( struct V_33 * V_34 )
{
struct V_341 * V_336 ;
struct V_2 * V_2 = F_35 ( V_34 -> V_61 ) ;
struct V_1 * V_4 ;
if ( ! F_207 ( V_34 , sizeof( * V_336 ) + sizeof( struct V_117 ) ) )
goto V_337;
V_336 = (struct V_341 * ) F_62 ( V_34 ) ;
if ( V_336 -> type != ( ( V_342 << 4 ) | ( V_343 ) ) ||
( V_336 -> V_13 & V_344 ) ||
( F_210 ( ( void * ) V_336 , sizeof( * V_336 ) ) != 0 &&
F_211 ( F_212 ( V_34 , 0 , V_34 -> V_110 , 0 ) ) ) )
goto V_337;
V_4 = F_201 ( V_2 , V_34 ) ;
if ( F_13 ( V_4 ) )
goto V_337;
if ( F_61 ( V_4 , V_34 , sizeof( * V_336 ) ) ) {
V_337:
F_51 ( V_34 ) ;
}
return 0 ;
}
static int F_118 ( struct V_1 * V_4 , struct V_33 * V_34 ,
struct V_152 * V_153 , struct V_345 * V_346 )
{
struct V_347 V_348 ;
struct V_37 * V_349 ;
struct V_350 * V_351 ;
unsigned long V_182 ;
int V_302 ;
if ( V_153 -> V_209 >= V_181 )
return - V_236 ;
if ( F_73 ( V_4 , V_153 -> V_209 ) &&
F_213 ( V_34 , V_352 , V_4 -> V_130 [ V_153 -> V_209 ] . V_61 -> V_101 ) < 0 )
return - V_214 ;
if ( ! ( V_349 = F_214 ( V_34 , V_353 ) ) )
return - V_214 ;
for ( V_302 = V_153 -> V_159 . V_9 . V_180 ; V_302 < V_153 -> V_159 . V_9 . V_144 ; V_302 ++ ) {
if ( F_73 ( V_4 , V_302 ) && V_153 -> V_159 . V_9 . V_179 [ V_302 ] < 255 ) {
if ( ! ( V_351 = F_215 ( V_34 , sizeof( * V_351 ) ) ) ) {
F_216 ( V_34 , V_349 ) ;
return - V_214 ;
}
V_351 -> V_354 = 0 ;
V_351 -> V_355 = V_153 -> V_159 . V_9 . V_179 [ V_302 ] ;
V_351 -> V_356 = V_4 -> V_130 [ V_302 ] . V_61 -> V_101 ;
V_351 -> V_357 = sizeof( * V_351 ) ;
}
}
F_217 ( V_34 , V_349 ) ;
V_182 = F_218 ( V_153 -> V_159 . V_9 . V_182 ) ;
V_182 = F_219 ( V_173 , V_182 ) ? V_173 - V_182 : 0 ;
V_348 . V_358 = V_153 -> V_159 . V_9 . V_215 ;
V_348 . V_359 = V_153 -> V_159 . V_9 . V_293 ;
V_348 . V_360 = V_153 -> V_159 . V_9 . V_294 ;
if ( F_220 ( V_34 , V_361 , sizeof( V_348 ) , & V_348 , V_362 ) ||
F_221 ( V_34 , V_363 , F_222 ( V_182 ) ,
V_362 ) )
return - V_214 ;
V_346 -> V_364 = V_365 ;
return 1 ;
}
int F_223 ( struct V_2 * V_2 , struct V_33 * V_34 ,
T_6 V_74 , T_6 V_71 ,
struct V_345 * V_346 , int V_366 , T_1 V_169 )
{
struct V_152 * V_178 ;
struct V_1 * V_4 ;
int V_7 ;
V_4 = F_1 ( V_2 , V_46 ) ;
if ( ! V_4 )
return - V_236 ;
F_133 () ;
V_178 = F_106 ( V_4 , V_74 , V_71 ) ;
if ( ! V_178 && V_34 -> V_61 ) {
int V_250 = F_197 ( V_4 , V_34 -> V_61 ) ;
if ( V_250 >= 0 )
V_178 = F_111 ( V_4 , V_71 , V_250 ) ;
}
if ( ! V_178 ) {
struct V_33 * V_330 ;
struct V_117 * V_70 ;
struct V_60 * V_61 ;
int V_250 = - 1 ;
if ( V_366 ) {
F_135 () ;
return - V_31 ;
}
V_61 = V_34 -> V_61 ;
F_52 ( & V_107 ) ;
if ( V_61 )
V_250 = F_197 ( V_4 , V_61 ) ;
if ( V_250 < 0 ) {
F_54 ( & V_107 ) ;
F_135 () ;
return - V_335 ;
}
V_330 = F_200 ( V_34 , V_212 ) ;
if ( ! V_330 ) {
F_54 ( & V_107 ) ;
F_135 () ;
return - V_53 ;
}
F_93 ( V_330 ) . V_169 = V_169 ;
F_124 ( V_330 , sizeof( struct V_117 ) ) ;
F_66 ( V_330 ) ;
V_70 = F_88 ( V_330 ) ;
V_70 -> V_77 = sizeof( struct V_117 ) >> 2 ;
V_70 -> V_74 = V_74 ;
V_70 -> V_71 = V_71 ;
V_70 -> V_76 = 0 ;
V_7 = F_138 ( V_4 , V_250 , V_330 ) ;
F_54 ( & V_107 ) ;
F_135 () ;
return V_7 ;
}
F_52 ( & V_107 ) ;
V_7 = F_118 ( V_4 , V_34 , V_178 , V_346 ) ;
F_54 ( & V_107 ) ;
F_135 () ;
return V_7 ;
}
static int F_224 ( struct V_1 * V_4 , struct V_33 * V_34 ,
T_1 V_169 , T_1 V_367 , struct V_152 * V_153 , int V_278 ,
int V_13 )
{
struct V_162 * V_163 ;
struct V_345 * V_346 ;
int V_7 ;
V_163 = F_225 ( V_34 , V_169 , V_367 , V_278 , sizeof( * V_346 ) , V_13 ) ;
if ( ! V_163 )
return - V_214 ;
V_346 = F_91 ( V_163 ) ;
V_346 -> V_368 = V_369 ;
V_346 -> V_370 = 32 ;
V_346 -> V_371 = 32 ;
V_346 -> V_372 = 0 ;
V_346 -> V_373 = V_4 -> V_3 ;
if ( F_213 ( V_34 , V_374 , V_4 -> V_3 ) )
goto V_375;
V_346 -> V_364 = V_365 ;
V_346 -> V_376 = V_377 ;
if ( V_153 -> V_240 & V_241 )
V_346 -> V_378 = V_379 ;
else
V_346 -> V_378 = V_380 ;
V_346 -> V_381 = 0 ;
if ( F_226 ( V_34 , V_382 , V_153 -> V_204 ) ||
F_226 ( V_34 , V_383 , V_153 -> V_205 ) )
goto V_375;
V_7 = F_118 ( V_4 , V_34 , V_153 , V_346 ) ;
if ( V_7 < 0 && V_7 != - V_236 )
goto V_375;
F_227 ( V_34 , V_163 ) ;
return 0 ;
V_375:
F_228 ( V_34 , V_163 ) ;
return - V_214 ;
}
static T_8 F_229 ( bool V_161 , int V_144 )
{
T_8 V_110 =
F_230 ( sizeof( struct V_345 ) )
+ F_231 ( 4 )
+ F_231 ( 4 )
+ F_231 ( 4 )
;
if ( ! V_161 )
V_110 = V_110
+ F_231 ( 4 )
+ F_231 ( 0 )
+ V_144 * F_232 ( sizeof( struct V_350 ) )
+ F_233 ( sizeof( struct V_347 ) )
;
return V_110 ;
}
static void F_98 ( struct V_1 * V_4 , struct V_152 * V_232 ,
int V_278 )
{
struct V_2 * V_2 = F_85 ( & V_4 -> V_2 ) ;
struct V_33 * V_34 ;
int V_7 = - V_187 ;
V_34 = F_234 ( F_229 ( V_232 -> V_209 >= V_181 , V_4 -> V_144 ) ,
V_212 ) ;
if ( ! V_34 )
goto V_384;
V_7 = F_224 ( V_4 , V_34 , 0 , 0 , V_232 , V_278 , 0 ) ;
if ( V_7 < 0 )
goto V_384;
F_235 ( V_34 , V_2 , 0 , V_385 , NULL , V_212 ) ;
return;
V_384:
F_51 ( V_34 ) ;
if ( V_7 < 0 )
F_236 ( V_2 , V_385 , V_7 ) ;
}
static int F_237 ( struct V_33 * V_34 , struct V_386 * V_387 )
{
struct V_2 * V_2 = F_154 ( V_34 -> V_243 ) ;
struct V_1 * V_4 ;
struct V_152 * V_232 ;
unsigned int V_388 = 0 , V_389 ;
unsigned int V_390 = 0 , V_391 ;
unsigned int V_157 = 0 , V_392 ;
V_389 = V_387 -> args [ 0 ] ;
V_391 = V_387 -> args [ 1 ] ;
V_392 = V_387 -> args [ 2 ] ;
F_133 () ;
F_2 (mrt, net) {
if ( V_388 < V_389 )
goto V_393;
if ( V_388 > V_389 )
V_391 = 0 ;
for ( V_390 = V_391 ; V_390 < V_54 ; V_390 ++ ) {
F_108 (mfc, &mrt->mfc_cache_array[h], list) {
if ( V_157 < V_392 )
goto V_394;
if ( F_224 ( V_4 , V_34 ,
F_93 ( V_387 -> V_34 ) . V_169 ,
V_387 -> V_163 -> V_395 ,
V_232 , V_229 ,
V_396 ) < 0 )
goto V_397;
V_394:
V_157 ++ ;
}
V_157 = V_392 = 0 ;
}
F_139 ( & V_172 ) ;
F_140 (mfc, &mrt->mfc_unres_queue, list) {
if ( V_157 < V_392 )
goto V_398;
if ( F_224 ( V_4 , V_34 ,
F_93 ( V_387 -> V_34 ) . V_169 ,
V_387 -> V_163 -> V_395 ,
V_232 , V_229 ,
V_396 ) < 0 ) {
F_142 ( & V_172 ) ;
goto V_397;
}
V_398:
V_157 ++ ;
}
F_142 ( & V_172 ) ;
V_157 = V_392 = 0 ;
V_391 = 0 ;
V_393:
V_388 ++ ;
}
V_397:
F_135 () ;
V_387 -> args [ 2 ] = V_157 ;
V_387 -> args [ 1 ] = V_390 ;
V_387 -> args [ 0 ] = V_388 ;
return V_34 -> V_110 ;
}
static bool F_238 ( unsigned char V_378 )
{
switch ( V_378 ) {
case V_379 :
case V_380 :
return true ;
}
return false ;
}
static int F_239 ( const struct V_37 * V_399 , struct V_231 * V_400 )
{
struct V_350 * V_401 = F_240 ( V_399 ) ;
int V_402 = F_241 ( V_399 ) , V_139 = 0 ;
while ( F_242 ( V_401 , V_402 ) ) {
V_400 -> V_239 [ V_139 ] = V_401 -> V_355 ;
if ( ++ V_139 == V_181 )
break;
V_401 = F_243 ( V_401 , & V_402 ) ;
}
return V_402 > 0 ? - V_28 : V_139 ;
}
static int F_244 ( struct V_2 * V_2 , struct V_162 * V_163 ,
struct V_231 * V_400 , int * V_184 ,
struct V_1 * * V_403 )
{
struct V_60 * V_61 = NULL ;
T_1 V_404 = V_46 ;
struct V_1 * V_4 ;
struct V_37 * V_405 ;
struct V_345 * V_346 ;
int V_221 , V_406 ;
V_221 = F_245 ( V_163 , sizeof( * V_346 ) , V_407 , V_408 ) ;
if ( V_221 < 0 )
goto V_175;
V_346 = F_91 ( V_163 ) ;
V_221 = - V_28 ;
if ( V_346 -> V_368 != V_369 || V_346 -> V_370 != 32 ||
V_346 -> V_364 != V_365 ||
V_346 -> V_376 != V_377 ||
! F_238 ( V_346 -> V_378 ) )
goto V_175;
memset ( V_400 , 0 , sizeof( * V_400 ) ) ;
V_400 -> V_237 = - 1 ;
V_221 = 0 ;
F_246 (attr, nlh, sizeof(struct rtmsg), rem) {
switch ( F_247 ( V_405 ) ) {
case V_382 :
V_400 -> V_235 . V_73 = F_248 ( V_405 ) ;
break;
case V_383 :
V_400 -> V_234 . V_73 = F_248 ( V_405 ) ;
break;
case V_352 :
V_61 = F_249 ( V_2 , F_250 ( V_405 ) ) ;
if ( ! V_61 ) {
V_221 = - V_335 ;
goto V_175;
}
break;
case V_353 :
if ( F_239 ( V_405 , V_400 ) < 0 ) {
V_221 = - V_28 ;
goto V_175;
}
break;
case V_409 :
V_221 = 1 ;
break;
case V_374 :
V_404 = F_250 ( V_405 ) ;
break;
}
}
V_4 = F_1 ( V_2 , V_404 ) ;
if ( ! V_4 ) {
V_221 = - V_236 ;
goto V_175;
}
* V_403 = V_4 ;
* V_184 = V_346 -> V_378 == V_380 ? 1 : 0 ;
if ( V_61 )
V_400 -> V_237 = F_197 ( V_4 , V_61 ) ;
V_175:
return V_221 ;
}
static int F_251 ( struct V_33 * V_34 , struct V_162 * V_163 )
{
struct V_2 * V_2 = F_154 ( V_34 -> V_243 ) ;
int V_221 , V_184 , V_233 ;
struct V_1 * V_410 ;
struct V_231 V_400 ;
V_184 = 0 ;
V_410 = NULL ;
V_221 = F_244 ( V_2 , V_163 , & V_400 , & V_184 , & V_410 ) ;
if ( V_221 < 0 )
return V_221 ;
V_233 = V_221 ? V_400 . V_237 : - 1 ;
if ( V_163 -> V_164 == V_229 )
return F_148 ( V_2 , V_410 , & V_400 , V_184 , V_233 ) ;
else
return F_146 ( V_410 , & V_400 , V_233 ) ;
}
static struct V_143 * F_252 ( struct V_2 * V_2 ,
struct V_411 * V_412 ,
T_9 V_413 )
{
struct V_1 * V_4 = V_412 -> V_4 ;
for ( V_412 -> V_302 = 0 ; V_412 -> V_302 < V_4 -> V_144 ; ++ V_412 -> V_302 ) {
if ( ! F_73 ( V_4 , V_412 -> V_302 ) )
continue;
if ( V_413 -- == 0 )
return & V_4 -> V_130 [ V_412 -> V_302 ] ;
}
return NULL ;
}
static void * F_253 ( struct V_414 * V_367 , T_9 * V_413 )
__acquires( V_107 )
{
struct V_411 * V_412 = V_367 -> V_415 ;
struct V_2 * V_2 = F_254 ( V_367 ) ;
struct V_1 * V_4 ;
V_4 = F_1 ( V_2 , V_46 ) ;
if ( ! V_4 )
return F_25 ( - V_236 ) ;
V_412 -> V_4 = V_4 ;
F_52 ( & V_107 ) ;
return * V_413 ? F_252 ( V_2 , V_367 -> V_415 , * V_413 - 1 )
: V_416 ;
}
static void * F_255 ( struct V_414 * V_367 , void * V_63 , T_9 * V_413 )
{
struct V_411 * V_412 = V_367 -> V_415 ;
struct V_2 * V_2 = F_254 ( V_367 ) ;
struct V_1 * V_4 = V_412 -> V_4 ;
++ * V_413 ;
if ( V_63 == V_416 )
return F_252 ( V_2 , V_412 , 0 ) ;
while ( ++ V_412 -> V_302 < V_4 -> V_144 ) {
if ( ! F_73 ( V_4 , V_412 -> V_302 ) )
continue;
return & V_4 -> V_130 [ V_412 -> V_302 ] ;
}
return NULL ;
}
static void F_256 ( struct V_414 * V_367 , void * V_63 )
__releases( V_107 )
{
F_54 ( & V_107 ) ;
}
static int F_257 ( struct V_414 * V_367 , void * V_63 )
{
struct V_411 * V_412 = V_367 -> V_415 ;
struct V_1 * V_4 = V_412 -> V_4 ;
if ( V_63 == V_416 ) {
F_258 ( V_367 ,
L_6 ) ;
} else {
const struct V_143 * V_250 = V_63 ;
const char * V_80 = V_250 -> V_61 ? V_250 -> V_61 -> V_80 : L_7 ;
F_259 ( V_367 ,
L_8 ,
V_250 - V_4 -> V_130 ,
V_80 , V_250 -> V_197 , V_250 -> V_199 ,
V_250 -> V_198 , V_250 -> V_200 ,
V_250 -> V_13 , V_250 -> V_192 , V_250 -> V_193 ) ;
}
return 0 ;
}
static int F_260 ( struct V_417 * V_417 , struct V_418 * V_418 )
{
return F_261 ( V_417 , V_418 , & V_419 ,
sizeof( struct V_411 ) ) ;
}
static struct V_152 * F_262 ( struct V_2 * V_2 ,
struct V_420 * V_421 , T_9 V_413 )
{
struct V_1 * V_4 = V_421 -> V_4 ;
struct V_152 * V_232 ;
F_133 () ;
for ( V_421 -> V_302 = 0 ; V_421 -> V_302 < V_54 ; V_421 -> V_302 ++ ) {
V_421 -> V_178 = & V_4 -> V_55 [ V_421 -> V_302 ] ;
F_108 (mfc, it->cache, list)
if ( V_413 -- == 0 )
return V_232 ;
}
F_135 () ;
F_139 ( & V_172 ) ;
V_421 -> V_178 = & V_4 -> V_56 ;
F_140 (mfc, it->cache, list)
if ( V_413 -- == 0 )
return V_232 ;
F_142 ( & V_172 ) ;
V_421 -> V_178 = NULL ;
return NULL ;
}
static void * F_263 ( struct V_414 * V_367 , T_9 * V_413 )
{
struct V_420 * V_421 = V_367 -> V_415 ;
struct V_2 * V_2 = F_254 ( V_367 ) ;
struct V_1 * V_4 ;
V_4 = F_1 ( V_2 , V_46 ) ;
if ( ! V_4 )
return F_25 ( - V_236 ) ;
V_421 -> V_4 = V_4 ;
V_421 -> V_178 = NULL ;
V_421 -> V_302 = 0 ;
return * V_413 ? F_262 ( V_2 , V_367 -> V_415 , * V_413 - 1 )
: V_416 ;
}
static void * F_264 ( struct V_414 * V_367 , void * V_63 , T_9 * V_413 )
{
struct V_152 * V_232 = V_63 ;
struct V_420 * V_421 = V_367 -> V_415 ;
struct V_2 * V_2 = F_254 ( V_367 ) ;
struct V_1 * V_4 = V_421 -> V_4 ;
++ * V_413 ;
if ( V_63 == V_416 )
return F_262 ( V_2 , V_367 -> V_415 , 0 ) ;
if ( V_232 -> V_50 . V_49 != V_421 -> V_178 )
return F_265 ( V_232 -> V_50 . V_49 , struct V_152 , V_50 ) ;
if ( V_421 -> V_178 == & V_4 -> V_56 )
goto V_422;
F_266 ( V_421 -> V_178 != & V_4 -> V_55 [ V_421 -> V_302 ] ) ;
while ( ++ V_421 -> V_302 < V_54 ) {
V_421 -> V_178 = & V_4 -> V_55 [ V_421 -> V_302 ] ;
if ( F_96 ( V_421 -> V_178 ) )
continue;
return F_267 ( V_421 -> V_178 , struct V_152 , V_50 ) ;
}
F_135 () ;
V_421 -> V_178 = & V_4 -> V_56 ;
V_421 -> V_302 = 0 ;
F_139 ( & V_172 ) ;
if ( ! F_96 ( V_421 -> V_178 ) )
return F_267 ( V_421 -> V_178 , struct V_152 , V_50 ) ;
V_422:
F_142 ( & V_172 ) ;
V_421 -> V_178 = NULL ;
return NULL ;
}
static void F_268 ( struct V_414 * V_367 , void * V_63 )
{
struct V_420 * V_421 = V_367 -> V_415 ;
struct V_1 * V_4 = V_421 -> V_4 ;
if ( V_421 -> V_178 == & V_4 -> V_56 )
F_142 ( & V_172 ) ;
else if ( V_421 -> V_178 == & V_4 -> V_55 [ V_421 -> V_302 ] )
F_135 () ;
}
static int F_269 ( struct V_414 * V_367 , void * V_63 )
{
int V_423 ;
if ( V_63 == V_416 ) {
F_258 ( V_367 ,
L_9 ) ;
} else {
const struct V_152 * V_232 = V_63 ;
const struct V_420 * V_421 = V_367 -> V_415 ;
const struct V_1 * V_4 = V_421 -> V_4 ;
F_259 ( V_367 , L_10 ,
( V_84 T_1 ) V_232 -> V_205 ,
( V_84 T_1 ) V_232 -> V_204 ,
V_232 -> V_209 ) ;
if ( V_421 -> V_178 != & V_4 -> V_56 ) {
F_259 ( V_367 , L_11 ,
V_232 -> V_159 . V_9 . V_215 ,
V_232 -> V_159 . V_9 . V_293 ,
V_232 -> V_159 . V_9 . V_294 ) ;
for ( V_423 = V_232 -> V_159 . V_9 . V_180 ;
V_423 < V_232 -> V_159 . V_9 . V_144 ; V_423 ++ ) {
if ( F_73 ( V_4 , V_423 ) &&
V_232 -> V_159 . V_9 . V_179 [ V_423 ] < 255 )
F_259 ( V_367 ,
L_12 ,
V_423 , V_232 -> V_159 . V_9 . V_179 [ V_423 ] ) ;
}
} else {
F_259 ( V_367 , L_11 , 0ul , 0ul , 0ul ) ;
}
F_270 ( V_367 , '\n' ) ;
}
return 0 ;
}
static int F_271 ( struct V_417 * V_417 , struct V_418 * V_418 )
{
return F_261 ( V_417 , V_418 , & V_424 ,
sizeof( struct V_420 ) ) ;
}
static int T_2 F_272 ( struct V_2 * V_2 )
{
int V_7 ;
V_7 = F_11 ( V_2 ) ;
if ( V_7 < 0 )
goto V_425;
#ifdef F_273
V_7 = - V_53 ;
if ( ! F_274 ( L_13 , 0 , V_2 -> V_426 , & V_427 ) )
goto V_428;
if ( ! F_274 ( L_14 , 0 , V_2 -> V_426 , & V_429 ) )
goto V_430;
#endif
return 0 ;
#ifdef F_273
V_430:
F_275 ( L_13 , V_2 -> V_426 ) ;
V_428:
F_20 ( V_2 ) ;
#endif
V_425:
return V_7 ;
}
static void T_3 F_276 ( struct V_2 * V_2 )
{
#ifdef F_273
F_275 ( L_14 , V_2 -> V_426 ) ;
F_275 ( L_13 , V_2 -> V_426 ) ;
#endif
F_20 ( V_2 ) ;
}
int T_10 F_277 ( void )
{
int V_7 ;
V_155 = F_278 ( L_15 ,
sizeof( struct V_152 ) ,
0 , V_431 | V_432 ,
NULL ) ;
V_7 = F_279 ( & V_433 ) ;
if ( V_7 )
goto V_434;
V_7 = F_280 ( & V_435 ) ;
if ( V_7 )
goto V_436;
#ifdef F_281
if ( F_282 ( & V_437 , V_438 ) < 0 ) {
F_283 ( L_16 , V_439 ) ;
V_7 = - V_31 ;
goto V_440;
}
#endif
F_284 ( V_369 , V_441 ,
NULL , F_237 , NULL ) ;
F_284 ( V_369 , V_229 ,
F_251 , NULL , NULL ) ;
F_284 ( V_369 , V_177 ,
F_251 , NULL , NULL ) ;
return 0 ;
#ifdef F_281
V_440:
F_285 ( & V_435 ) ;
#endif
V_436:
F_286 ( & V_433 ) ;
V_434:
F_287 ( V_155 ) ;
return V_7 ;
}
