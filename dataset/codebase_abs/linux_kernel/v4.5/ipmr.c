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
}
static int F_101 ( struct V_2 * V_2 , struct V_1 * V_4 ,
struct V_62 * V_182 , int V_183 )
{
int V_139 = V_182 -> V_81 ;
struct V_143 * V_63 = & V_4 -> V_130 [ V_139 ] ;
struct V_60 * V_61 ;
struct V_90 * V_91 ;
int V_7 ;
if ( F_73 ( V_4 , V_139 ) )
return - V_184 ;
switch ( V_182 -> V_185 ) {
case V_150 :
if ( ! F_102 () )
return - V_28 ;
if ( V_4 -> V_59 >= 0 )
return - V_184 ;
V_61 = F_57 ( V_2 , V_4 ) ;
if ( ! V_61 )
return - V_186 ;
V_7 = F_74 ( V_61 , 1 ) ;
if ( V_7 ) {
F_49 ( V_61 ) ;
F_78 ( V_61 ) ;
return V_7 ;
}
break;
case V_149 :
V_61 = F_46 ( V_2 , V_182 ) ;
if ( ! V_61 )
return - V_186 ;
V_7 = F_74 ( V_61 , 1 ) ;
if ( V_7 ) {
F_34 ( V_61 , V_182 ) ;
F_78 ( V_61 ) ;
return V_7 ;
}
break;
case V_187 :
case 0 :
if ( V_182 -> V_185 == V_187 ) {
V_61 = F_103 ( V_2 , V_182 -> V_188 ) ;
if ( V_61 && ! F_42 ( V_61 ) ) {
F_78 ( V_61 ) ;
return - V_145 ;
}
} else {
V_61 = F_104 ( V_2 , V_182 -> V_75 . V_73 ) ;
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
V_63 -> V_189 = V_182 -> V_190 ;
V_63 -> V_191 = V_182 -> V_75 . V_73 ;
V_63 -> V_192 = V_182 -> V_72 . V_73 ;
V_63 -> V_13 = V_182 -> V_185 ;
if ( ! V_183 )
V_63 -> V_13 |= V_193 ;
V_63 -> V_194 = V_182 -> V_195 ;
V_63 -> V_196 = 0 ;
V_63 -> V_197 = 0 ;
V_63 -> V_198 = 0 ;
V_63 -> V_199 = 0 ;
V_63 -> V_200 = V_61 -> V_101 ;
if ( V_63 -> V_13 & ( V_149 | V_150 ) )
V_63 -> V_200 = F_105 ( V_61 ) ;
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
T_6 V_201 ,
T_6 V_202 )
{
int line = F_107 ( V_202 , V_201 ) ;
struct V_152 * V_153 ;
F_108 (c, &mrt->mfc_cache_array[line], list) {
if ( V_153 -> V_203 == V_201 && V_153 -> V_204 == V_202 )
return V_153 ;
}
return NULL ;
}
static struct V_152 * F_109 ( struct V_1 * V_4 ,
int V_139 )
{
int line = F_107 ( F_110 ( V_205 ) , F_110 ( V_205 ) ) ;
struct V_152 * V_153 ;
F_108 (c, &mrt->mfc_cache_array[line], list)
if ( V_153 -> V_203 == F_110 ( V_205 ) &&
V_153 -> V_204 == F_110 ( V_205 ) &&
V_153 -> V_159 . V_9 . V_179 [ V_139 ] < 255 )
return V_153 ;
return NULL ;
}
static struct V_152 * F_111 ( struct V_1 * V_4 ,
T_6 V_202 , int V_139 )
{
int line = F_107 ( V_202 , F_110 ( V_205 ) ) ;
struct V_152 * V_153 , * V_206 ;
if ( V_202 == F_110 ( V_205 ) )
goto V_207;
F_108 (c, &mrt->mfc_cache_array[line], list)
if ( V_153 -> V_203 == F_110 ( V_205 ) &&
V_153 -> V_204 == V_202 ) {
if ( V_153 -> V_159 . V_9 . V_179 [ V_139 ] < 255 )
return V_153 ;
V_206 = F_109 ( V_4 ,
V_153 -> V_208 ) ;
if ( V_206 && V_206 -> V_159 . V_9 . V_179 [ V_139 ] < 255 )
return V_153 ;
}
V_207:
return F_109 ( V_4 , V_139 ) ;
}
static struct V_152 * F_112 ( void )
{
struct V_152 * V_153 = F_113 ( V_155 , V_52 ) ;
if ( V_153 )
V_153 -> V_159 . V_9 . V_180 = V_181 ;
return V_153 ;
}
static struct V_152 * F_114 ( void )
{
struct V_152 * V_153 = F_113 ( V_155 , V_209 ) ;
if ( V_153 ) {
F_115 ( & V_153 -> V_159 . V_160 . V_161 ) ;
V_153 -> V_159 . V_160 . V_171 = V_173 + 10 * V_174 ;
}
return V_153 ;
}
static void F_116 ( struct V_2 * V_2 , struct V_1 * V_4 ,
struct V_152 * V_210 , struct V_152 * V_153 )
{
struct V_33 * V_34 ;
struct V_156 * V_157 ;
while ( ( V_34 = F_117 ( & V_210 -> V_159 . V_160 . V_161 ) ) ) {
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
V_157 -> error = - V_211 ;
memset ( & V_157 -> V_168 , 0 , sizeof( V_157 -> V_168 ) ) ;
}
F_92 ( V_34 , V_2 , F_93 ( V_34 ) . V_169 ) ;
} else {
F_120 ( V_2 , V_4 , V_34 , V_153 , 0 ) ;
}
}
}
static int F_53 ( struct V_1 * V_4 ,
struct V_33 * V_212 , T_7 V_139 , int assert )
{
const int V_77 = F_121 ( V_212 ) ;
struct V_213 * V_214 ;
struct V_215 * V_216 ;
struct V_217 * V_168 ;
struct V_33 * V_34 ;
int V_218 ;
if ( assert == V_112 )
V_34 = F_122 ( V_212 , sizeof( struct V_117 ) ) ;
else
V_34 = F_123 ( 128 , V_209 ) ;
if ( ! V_34 )
return - V_186 ;
if ( assert == V_112 ) {
F_124 ( V_34 , sizeof( struct V_117 ) ) ;
F_66 ( V_34 ) ;
F_125 ( V_34 ) ;
V_168 = (struct V_217 * ) F_126 ( V_34 ) ;
memcpy ( V_168 , F_126 ( V_212 ) , sizeof( struct V_117 ) ) ;
V_168 -> V_219 = V_112 ;
V_168 -> V_220 = 0 ;
V_168 -> V_221 = V_4 -> V_59 ;
F_88 ( V_34 ) -> V_77 = sizeof( struct V_117 ) >> 2 ;
F_88 ( V_34 ) -> V_129 = F_67 ( F_64 ( F_88 ( V_212 ) -> V_129 ) +
sizeof( struct V_117 ) ) ;
} else {
F_127 ( V_34 , V_34 -> V_110 ) ;
F_128 ( V_34 , V_77 ) ;
F_129 ( V_34 , V_212 -> V_134 , V_77 ) ;
F_88 ( V_34 ) -> V_78 = 0 ;
V_168 = (struct V_217 * ) F_126 ( V_34 ) ;
V_168 -> V_221 = V_139 ;
F_130 ( V_34 , F_131 ( F_132 ( V_212 ) ) ) ;
V_216 = (struct V_215 * ) F_128 ( V_34 , sizeof( struct V_215 ) ) ;
V_216 -> type = assert ;
V_168 -> V_219 = assert ;
V_216 -> V_222 = 0 ;
F_88 ( V_34 ) -> V_129 = F_67 ( V_34 -> V_110 ) ;
V_34 -> V_223 = V_34 -> V_132 ;
}
F_133 () ;
V_214 = F_134 ( V_4 -> V_214 ) ;
if ( ! V_214 ) {
F_135 () ;
F_51 ( V_34 ) ;
return - V_28 ;
}
V_218 = F_136 ( V_214 , V_34 ) ;
F_135 () ;
if ( V_218 < 0 ) {
F_137 ( L_5 ) ;
F_51 ( V_34 ) ;
}
return V_218 ;
}
static int F_138 ( struct V_1 * V_4 , T_7 V_139 ,
struct V_33 * V_34 )
{
bool V_224 = false ;
int V_7 ;
struct V_152 * V_153 ;
const struct V_117 * V_70 = F_88 ( V_34 ) ;
F_139 ( & V_172 ) ;
F_140 (c, &mrt->mfc_unres_queue, list) {
if ( V_153 -> V_204 == V_70 -> V_71 &&
V_153 -> V_203 == V_70 -> V_74 ) {
V_224 = true ;
break;
}
}
if ( ! V_224 ) {
if ( F_141 ( & V_4 -> V_158 ) >= 10 ||
( V_153 = F_114 () ) == NULL ) {
F_142 ( & V_172 ) ;
F_51 ( V_34 ) ;
return - V_186 ;
}
V_153 -> V_208 = - 1 ;
V_153 -> V_203 = V_70 -> V_74 ;
V_153 -> V_204 = V_70 -> V_71 ;
V_7 = F_53 ( V_4 , V_34 , V_139 , V_225 ) ;
if ( V_7 < 0 ) {
F_142 ( & V_172 ) ;
F_82 ( V_153 ) ;
F_51 ( V_34 ) ;
return V_7 ;
}
F_143 ( & V_4 -> V_158 ) ;
F_144 ( & V_153 -> V_50 , & V_4 -> V_56 ) ;
F_98 ( V_4 , V_153 , V_226 ) ;
if ( F_141 ( & V_4 -> V_158 ) == 1 )
F_95 ( & V_4 -> V_57 , V_153 -> V_159 . V_160 . V_171 ) ;
}
if ( V_153 -> V_159 . V_160 . V_161 . V_227 > 3 ) {
F_51 ( V_34 ) ;
V_7 = - V_186 ;
} else {
F_145 ( & V_153 -> V_159 . V_160 . V_161 , V_34 ) ;
V_7 = 0 ;
}
F_142 ( & V_172 ) ;
return V_7 ;
}
static int F_146 ( struct V_1 * V_4 , struct V_228 * V_229 , int V_230 )
{
int line ;
struct V_152 * V_153 , * V_49 ;
line = F_107 ( V_229 -> V_231 . V_73 , V_229 -> V_232 . V_73 ) ;
F_22 (c, next, &mrt->mfc_cache_array[line], list) {
if ( V_153 -> V_203 == V_229 -> V_232 . V_73 &&
V_153 -> V_204 == V_229 -> V_231 . V_73 &&
( V_230 == - 1 || V_230 == V_153 -> V_208 ) ) {
F_147 ( & V_153 -> V_50 ) ;
F_98 ( V_4 , V_153 , V_177 ) ;
F_82 ( V_153 ) ;
return 0 ;
}
}
return - V_233 ;
}
static int F_148 ( struct V_2 * V_2 , struct V_1 * V_4 ,
struct V_228 * V_229 , int V_183 , int V_230 )
{
bool V_224 = false ;
int line ;
struct V_152 * V_210 , * V_153 ;
if ( V_229 -> V_234 >= V_181 )
return - V_235 ;
line = F_107 ( V_229 -> V_231 . V_73 , V_229 -> V_232 . V_73 ) ;
F_140 (c, &mrt->mfc_cache_array[line], list) {
if ( V_153 -> V_203 == V_229 -> V_232 . V_73 &&
V_153 -> V_204 == V_229 -> V_231 . V_73 &&
( V_230 == - 1 || V_230 == V_153 -> V_208 ) ) {
V_224 = true ;
break;
}
}
if ( V_224 ) {
F_71 ( & V_107 ) ;
V_153 -> V_208 = V_229 -> V_234 ;
F_100 ( V_4 , V_153 , V_229 -> V_236 ) ;
if ( ! V_183 )
V_153 -> V_237 |= V_238 ;
F_72 ( & V_107 ) ;
F_98 ( V_4 , V_153 , V_226 ) ;
return 0 ;
}
if ( V_229 -> V_231 . V_73 != F_110 ( V_205 ) &&
! F_63 ( V_229 -> V_231 . V_73 ) )
return - V_28 ;
V_153 = F_112 () ;
if ( ! V_153 )
return - V_53 ;
V_153 -> V_203 = V_229 -> V_232 . V_73 ;
V_153 -> V_204 = V_229 -> V_231 . V_73 ;
V_153 -> V_208 = V_229 -> V_234 ;
F_100 ( V_4 , V_153 , V_229 -> V_236 ) ;
if ( ! V_183 )
V_153 -> V_237 |= V_238 ;
F_149 ( & V_153 -> V_50 , & V_4 -> V_55 [ line ] ) ;
V_224 = false ;
F_139 ( & V_172 ) ;
F_140 (uc, &mrt->mfc_unres_queue, list) {
if ( V_210 -> V_203 == V_153 -> V_203 &&
V_210 -> V_204 == V_153 -> V_204 ) {
F_23 ( & V_210 -> V_50 ) ;
F_86 ( & V_4 -> V_158 ) ;
V_224 = true ;
break;
}
}
if ( F_96 ( & V_4 -> V_56 ) )
F_150 ( & V_4 -> V_57 ) ;
F_142 ( & V_172 ) ;
if ( V_224 ) {
F_116 ( V_2 , V_4 , V_210 , V_153 ) ;
F_82 ( V_210 ) ;
}
F_98 ( V_4 , V_153 , V_226 ) ;
return 0 ;
}
static void F_32 ( struct V_1 * V_4 , bool V_239 )
{
int V_51 ;
F_151 ( V_50 ) ;
struct V_152 * V_153 , * V_49 ;
for ( V_51 = 0 ; V_51 < V_4 -> V_144 ; V_51 ++ ) {
if ( ! V_239 && ( V_4 -> V_130 [ V_51 ] . V_13 & V_193 ) )
continue;
F_70 ( V_4 , V_51 , 0 , & V_50 ) ;
}
F_152 ( & V_50 ) ;
for ( V_51 = 0 ; V_51 < V_54 ; V_51 ++ ) {
F_22 (c, next, &mrt->mfc_cache_array[i], list) {
if ( ! V_239 && ( V_153 -> V_237 & V_238 ) )
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
static void F_153 ( struct V_213 * V_240 )
{
struct V_2 * V_2 = F_154 ( V_240 ) ;
struct V_1 * V_4 ;
F_21 () ;
F_2 (mrt, net) {
if ( V_240 == F_155 ( V_4 -> V_214 ) ) {
F_156 ( V_2 , V_147 ) -- ;
F_75 ( V_2 , V_148 ,
V_241 ,
V_2 -> V_15 . V_242 ) ;
F_157 ( V_4 -> V_214 , NULL ) ;
F_32 ( V_4 , false ) ;
}
}
F_24 () ;
}
int F_158 ( struct V_213 * V_240 , int V_243 , char V_85 * V_244 ,
unsigned int V_245 )
{
struct V_2 * V_2 = F_154 ( V_240 ) ;
int V_246 , V_218 = 0 , V_230 = 0 ;
struct V_1 * V_4 ;
struct V_62 V_247 ;
struct V_228 V_229 ;
T_1 V_248 ;
F_21 () ;
if ( V_240 -> V_249 != V_250 ||
F_159 ( V_240 ) -> V_251 != V_252 ) {
V_218 = - V_96 ;
goto V_253;
}
V_4 = F_1 ( V_2 , F_160 ( V_240 ) -> V_254 ? : V_46 ) ;
if ( ! V_4 ) {
V_218 = - V_233 ;
goto V_253;
}
if ( V_243 != V_255 ) {
if ( V_240 != F_161 ( V_4 -> V_214 ) &&
! F_162 ( V_2 -> V_256 , V_257 ) ) {
V_218 = - V_26 ;
goto V_253;
}
}
switch ( V_243 ) {
case V_255 :
if ( V_245 != sizeof( int ) ) {
V_218 = - V_28 ;
break;
}
if ( F_155 ( V_4 -> V_214 ) ) {
V_218 = - V_184 ;
break;
}
V_218 = F_163 ( V_240 , 1 , F_153 ) ;
if ( V_218 == 0 ) {
F_164 ( V_4 -> V_214 , V_240 ) ;
F_156 ( V_2 , V_147 ) ++ ;
F_75 ( V_2 , V_148 ,
V_241 ,
V_2 -> V_15 . V_242 ) ;
}
break;
case V_258 :
if ( V_240 != F_161 ( V_4 -> V_214 ) ) {
V_218 = - V_26 ;
} else {
F_24 () ;
V_218 = F_163 ( V_240 , 0 , NULL ) ;
goto V_175;
}
break;
case V_259 :
case V_260 :
if ( V_245 != sizeof( V_247 ) ) {
V_218 = - V_28 ;
break;
}
if ( F_165 ( & V_247 , V_244 , sizeof( V_247 ) ) ) {
V_218 = - V_261 ;
break;
}
if ( V_247 . V_81 >= V_181 ) {
V_218 = - V_235 ;
break;
}
if ( V_243 == V_259 ) {
V_218 = F_101 ( V_2 , V_4 , & V_247 ,
V_240 == F_155 ( V_4 -> V_214 ) ) ;
} else {
V_218 = F_70 ( V_4 , V_247 . V_81 , 0 , NULL ) ;
}
break;
case V_262 :
case V_263 :
V_230 = - 1 ;
case V_264 :
case V_265 :
if ( V_245 != sizeof( V_229 ) ) {
V_218 = - V_28 ;
break;
}
if ( F_165 ( & V_229 , V_244 , sizeof( V_229 ) ) ) {
V_218 = - V_261 ;
break;
}
if ( V_230 == 0 )
V_230 = V_229 . V_234 ;
if ( V_243 == V_263 || V_243 == V_265 )
V_218 = F_146 ( V_4 , & V_229 , V_230 ) ;
else
V_218 = F_148 ( V_2 , V_4 , & V_229 ,
V_240 == F_155 ( V_4 -> V_214 ) ,
V_230 ) ;
break;
case V_266 :
if ( V_245 != sizeof( V_246 ) ) {
V_218 = - V_28 ;
break;
}
if ( F_166 ( V_246 , ( int V_85 * ) V_244 ) ) {
V_218 = - V_261 ;
break;
}
V_4 -> V_267 = V_246 ;
break;
case V_268 :
if ( ! F_102 () ) {
V_218 = - V_269 ;
break;
}
if ( V_245 != sizeof( V_246 ) ) {
V_218 = - V_28 ;
break;
}
if ( F_166 ( V_246 , ( int V_85 * ) V_244 ) ) {
V_218 = - V_261 ;
break;
}
V_246 = ! ! V_246 ;
if ( V_246 != V_4 -> V_270 ) {
V_4 -> V_270 = V_246 ;
V_4 -> V_267 = V_246 ;
}
break;
case V_271 :
if ( ! F_167 ( F_29 ) ) {
V_218 = - V_269 ;
break;
}
if ( V_245 != sizeof( V_248 ) ) {
V_218 = - V_28 ;
break;
}
if ( F_166 ( V_248 , ( T_1 V_85 * ) V_244 ) ) {
V_218 = - V_261 ;
break;
}
if ( V_240 == F_155 ( V_4 -> V_214 ) ) {
V_218 = - V_272 ;
} else {
V_4 = F_16 ( V_2 , V_248 ) ;
if ( F_13 ( V_4 ) )
V_218 = F_14 ( V_4 ) ;
else
F_160 ( V_240 ) -> V_254 = V_248 ;
}
break;
default:
V_218 = - V_269 ;
}
V_253:
F_24 () ;
V_175:
return V_218 ;
}
int F_168 ( struct V_213 * V_240 , int V_243 , char V_85 * V_244 , int V_85 * V_245 )
{
int V_273 ;
int V_246 ;
struct V_2 * V_2 = F_154 ( V_240 ) ;
struct V_1 * V_4 ;
if ( V_240 -> V_249 != V_250 ||
F_159 ( V_240 ) -> V_251 != V_252 )
return - V_96 ;
V_4 = F_1 ( V_2 , F_160 ( V_240 ) -> V_254 ? : V_46 ) ;
if ( ! V_4 )
return - V_233 ;
switch ( V_243 ) {
case V_274 :
V_246 = 0x0305 ;
break;
case V_268 :
if ( ! F_102 () )
return - V_269 ;
V_246 = V_4 -> V_270 ;
break;
case V_266 :
V_246 = V_4 -> V_267 ;
break;
default:
return - V_269 ;
}
if ( F_166 ( V_273 , V_245 ) )
return - V_261 ;
V_273 = F_169 (unsigned int, olr, sizeof(int)) ;
if ( V_273 < 0 )
return - V_28 ;
if ( F_170 ( V_273 , V_245 ) )
return - V_261 ;
if ( F_171 ( V_244 , & V_246 , V_273 ) )
return - V_261 ;
return 0 ;
}
int F_172 ( struct V_213 * V_240 , int V_275 , void V_85 * V_11 )
{
struct V_276 V_277 ;
struct V_278 V_279 ;
struct V_143 * V_247 ;
struct V_152 * V_153 ;
struct V_2 * V_2 = F_154 ( V_240 ) ;
struct V_1 * V_4 ;
V_4 = F_1 ( V_2 , F_160 ( V_240 ) -> V_254 ? : V_46 ) ;
if ( ! V_4 )
return - V_233 ;
switch ( V_275 ) {
case V_280 :
if ( F_165 ( & V_279 , V_11 , sizeof( V_279 ) ) )
return - V_261 ;
if ( V_279 . V_139 >= V_4 -> V_144 )
return - V_28 ;
F_52 ( & V_107 ) ;
V_247 = & V_4 -> V_130 [ V_279 . V_139 ] ;
if ( F_73 ( V_4 , V_279 . V_139 ) ) {
V_279 . V_281 = V_247 -> V_198 ;
V_279 . V_282 = V_247 -> V_199 ;
V_279 . V_283 = V_247 -> V_196 ;
V_279 . V_284 = V_247 -> V_197 ;
F_54 ( & V_107 ) ;
if ( F_171 ( V_11 , & V_279 , sizeof( V_279 ) ) )
return - V_261 ;
return 0 ;
}
F_54 ( & V_107 ) ;
return - V_145 ;
case V_285 :
if ( F_165 ( & V_277 , V_11 , sizeof( V_277 ) ) )
return - V_261 ;
F_133 () ;
V_153 = F_106 ( V_4 , V_277 . V_286 . V_73 , V_277 . V_287 . V_73 ) ;
if ( V_153 ) {
V_277 . V_288 = V_153 -> V_159 . V_9 . V_212 ;
V_277 . V_289 = V_153 -> V_159 . V_9 . V_290 ;
V_277 . V_291 = V_153 -> V_159 . V_9 . V_291 ;
F_135 () ;
if ( F_171 ( V_11 , & V_277 , sizeof( V_277 ) ) )
return - V_261 ;
return 0 ;
}
F_135 () ;
return - V_145 ;
default:
return - V_292 ;
}
}
int F_173 ( struct V_213 * V_240 , unsigned int V_275 , void V_85 * V_11 )
{
struct V_293 V_277 ;
struct V_294 V_279 ;
struct V_143 * V_247 ;
struct V_152 * V_153 ;
struct V_2 * V_2 = F_154 ( V_240 ) ;
struct V_1 * V_4 ;
V_4 = F_1 ( V_2 , F_160 ( V_240 ) -> V_254 ? : V_46 ) ;
if ( ! V_4 )
return - V_233 ;
switch ( V_275 ) {
case V_280 :
if ( F_165 ( & V_279 , V_11 , sizeof( V_279 ) ) )
return - V_261 ;
if ( V_279 . V_139 >= V_4 -> V_144 )
return - V_28 ;
F_52 ( & V_107 ) ;
V_247 = & V_4 -> V_130 [ V_279 . V_139 ] ;
if ( F_73 ( V_4 , V_279 . V_139 ) ) {
V_279 . V_281 = V_247 -> V_198 ;
V_279 . V_282 = V_247 -> V_199 ;
V_279 . V_283 = V_247 -> V_196 ;
V_279 . V_284 = V_247 -> V_197 ;
F_54 ( & V_107 ) ;
if ( F_171 ( V_11 , & V_279 , sizeof( V_279 ) ) )
return - V_261 ;
return 0 ;
}
F_54 ( & V_107 ) ;
return - V_145 ;
case V_285 :
if ( F_165 ( & V_277 , V_11 , sizeof( V_277 ) ) )
return - V_261 ;
F_133 () ;
V_153 = F_106 ( V_4 , V_277 . V_286 . V_73 , V_277 . V_287 . V_73 ) ;
if ( V_153 ) {
V_277 . V_288 = V_153 -> V_159 . V_9 . V_212 ;
V_277 . V_289 = V_153 -> V_159 . V_9 . V_290 ;
V_277 . V_291 = V_153 -> V_159 . V_9 . V_291 ;
F_135 () ;
if ( F_171 ( V_11 , & V_277 , sizeof( V_277 ) ) )
return - V_261 ;
return 0 ;
}
F_135 () ;
return - V_145 ;
default:
return - V_292 ;
}
}
static int F_174 ( struct V_295 * V_296 , unsigned long V_297 , void * V_298 )
{
struct V_60 * V_61 = F_175 ( V_298 ) ;
struct V_2 * V_2 = F_35 ( V_61 ) ;
struct V_1 * V_4 ;
struct V_143 * V_63 ;
int V_299 ;
if ( V_297 != V_300 )
return V_301 ;
F_2 (mrt, net) {
V_63 = & V_4 -> V_130 [ 0 ] ;
for ( V_299 = 0 ; V_299 < V_4 -> V_144 ; V_299 ++ , V_63 ++ ) {
if ( V_63 -> V_61 == V_61 )
F_70 ( V_4 , V_299 , 1 , NULL ) ;
}
}
return V_301 ;
}
static void F_176 ( struct V_2 * V_2 , struct V_33 * V_34 ,
T_6 V_74 , T_6 V_71 )
{
struct V_117 * V_70 ;
const struct V_117 * V_302 = F_88 ( V_34 ) ;
F_124 ( V_34 , sizeof( struct V_117 ) ) ;
V_34 -> V_223 = V_34 -> V_132 ;
F_66 ( V_34 ) ;
V_70 = F_88 ( V_34 ) ;
V_70 -> V_76 = 4 ;
V_70 -> V_41 = V_302 -> V_41 ;
V_70 -> V_303 = V_302 -> V_303 ;
V_70 -> V_304 = 0 ;
V_70 -> V_71 = V_71 ;
V_70 -> V_74 = V_74 ;
V_70 -> V_78 = V_79 ;
V_70 -> V_77 = 5 ;
V_70 -> V_129 = F_67 ( V_34 -> V_110 ) ;
F_177 ( V_2 , V_34 , NULL ) ;
F_178 ( V_70 ) ;
memset ( & ( F_179 ( V_34 ) -> V_305 ) , 0 , sizeof( F_179 ( V_34 ) -> V_305 ) ) ;
F_180 ( V_34 ) ;
}
static inline int F_181 ( struct V_2 * V_2 , struct V_213 * V_240 ,
struct V_33 * V_34 )
{
struct V_306 * V_305 = & ( F_179 ( V_34 ) -> V_305 ) ;
F_182 ( V_2 , V_307 ) ;
F_183 ( V_2 , V_308 , V_34 -> V_110 ) ;
if ( F_184 ( V_305 -> V_245 ) )
F_185 ( V_34 ) ;
return F_186 ( V_2 , V_240 , V_34 ) ;
}
static void F_187 ( struct V_2 * V_2 , struct V_1 * V_4 ,
struct V_33 * V_34 , struct V_152 * V_153 , int V_139 )
{
const struct V_117 * V_70 = F_88 ( V_34 ) ;
struct V_143 * V_247 = & V_4 -> V_130 [ V_139 ] ;
struct V_60 * V_61 ;
struct V_309 * V_310 ;
struct V_5 V_99 ;
int V_128 = 0 ;
if ( ! V_247 -> V_61 )
goto V_311;
if ( V_247 -> V_13 & V_150 ) {
V_247 -> V_199 ++ ;
V_247 -> V_197 += V_34 -> V_110 ;
V_247 -> V_61 -> V_108 . V_109 += V_34 -> V_110 ;
V_247 -> V_61 -> V_108 . V_111 ++ ;
F_53 ( V_4 , V_34 , V_139 , V_112 ) ;
goto V_311;
}
if ( V_247 -> V_13 & V_149 ) {
V_310 = F_188 ( V_2 , & V_99 , NULL ,
V_247 -> V_192 , V_247 -> V_191 ,
0 , 0 ,
V_79 ,
F_189 ( V_70 -> V_41 ) , V_247 -> V_200 ) ;
if ( F_13 ( V_310 ) )
goto V_311;
V_128 = sizeof( struct V_117 ) ;
} else {
V_310 = F_188 ( V_2 , & V_99 , NULL , V_70 -> V_71 , 0 ,
0 , 0 ,
V_79 ,
F_189 ( V_70 -> V_41 ) , V_247 -> V_200 ) ;
if ( F_13 ( V_310 ) )
goto V_311;
}
V_61 = V_310 -> V_312 . V_61 ;
if ( V_34 -> V_110 + V_128 > F_190 ( & V_310 -> V_312 ) && ( F_64 ( V_70 -> V_304 ) & V_313 ) ) {
F_182 ( V_2 , V_314 ) ;
F_191 ( V_310 ) ;
goto V_311;
}
V_128 += F_192 ( V_61 ) + V_310 -> V_312 . V_315 ;
if ( F_193 ( V_34 , V_128 ) ) {
F_191 ( V_310 ) ;
goto V_311;
}
V_247 -> V_199 ++ ;
V_247 -> V_197 += V_34 -> V_110 ;
F_194 ( V_34 ) ;
F_130 ( V_34 , & V_310 -> V_312 ) ;
F_195 ( F_88 ( V_34 ) ) ;
if ( V_247 -> V_13 & V_149 ) {
F_176 ( V_2 , V_34 , V_247 -> V_191 , V_247 -> V_192 ) ;
V_247 -> V_61 -> V_108 . V_111 ++ ;
V_247 -> V_61 -> V_108 . V_109 += V_34 -> V_110 ;
}
F_179 ( V_34 ) -> V_13 |= V_316 ;
F_196 ( V_317 , V_318 ,
V_2 , NULL , V_34 , V_34 -> V_61 , V_61 ,
F_181 ) ;
return;
V_311:
F_51 ( V_34 ) ;
}
static int F_197 ( struct V_1 * V_4 , struct V_60 * V_61 )
{
int V_299 ;
for ( V_299 = V_4 -> V_144 - 1 ; V_299 >= 0 ; V_299 -- ) {
if ( V_4 -> V_130 [ V_299 ] . V_61 == V_61 )
break;
}
return V_299 ;
}
static void F_120 ( struct V_2 * V_2 , struct V_1 * V_4 ,
struct V_33 * V_34 , struct V_152 * V_178 ,
int V_191 )
{
int V_319 = - 1 ;
int V_247 , V_299 ;
int V_320 = F_197 ( V_4 , V_34 -> V_61 ) ;
V_247 = V_178 -> V_208 ;
V_178 -> V_159 . V_9 . V_212 ++ ;
V_178 -> V_159 . V_9 . V_290 += V_34 -> V_110 ;
if ( V_178 -> V_203 == F_110 ( V_205 ) && V_320 >= 0 ) {
struct V_152 * V_321 ;
V_321 = F_109 ( V_4 , V_247 ) ;
if ( V_321 &&
V_321 -> V_159 . V_9 . V_179 [ V_320 ] < 255 )
goto V_322;
}
if ( V_4 -> V_130 [ V_247 ] . V_61 != V_34 -> V_61 ) {
if ( F_198 ( F_199 ( V_34 ) ) ) {
goto V_323;
}
V_178 -> V_159 . V_9 . V_291 ++ ;
if ( V_320 >= 0 && V_4 -> V_267 &&
( V_4 -> V_270 ||
V_178 -> V_159 . V_9 . V_179 [ V_320 ] < 255 ) &&
F_97 ( V_173 ,
V_178 -> V_159 . V_9 . V_324 + V_325 ) ) {
V_178 -> V_159 . V_9 . V_324 = V_173 ;
F_53 ( V_4 , V_34 , V_320 , V_326 ) ;
}
goto V_323;
}
V_322:
V_4 -> V_130 [ V_247 ] . V_198 ++ ;
V_4 -> V_130 [ V_247 ] . V_196 += V_34 -> V_110 ;
if ( V_178 -> V_203 == F_110 ( V_205 ) &&
V_178 -> V_204 == F_110 ( V_205 ) ) {
if ( V_320 >= 0 &&
V_320 != V_178 -> V_208 &&
F_88 ( V_34 ) -> V_303 >
V_178 -> V_159 . V_9 . V_179 [ V_178 -> V_208 ] ) {
V_319 = V_178 -> V_208 ;
goto V_327;
}
goto V_323;
}
for ( V_299 = V_178 -> V_159 . V_9 . V_144 - 1 ;
V_299 >= V_178 -> V_159 . V_9 . V_180 ; V_299 -- ) {
if ( ( V_178 -> V_203 != F_110 ( V_205 ) ||
V_299 != V_320 ) &&
F_88 ( V_34 ) -> V_303 > V_178 -> V_159 . V_9 . V_179 [ V_299 ] ) {
if ( V_319 != - 1 ) {
struct V_33 * V_328 = F_200 ( V_34 , V_209 ) ;
if ( V_328 )
F_187 ( V_2 , V_4 , V_328 , V_178 ,
V_319 ) ;
}
V_319 = V_299 ;
}
}
V_327:
if ( V_319 != - 1 ) {
if ( V_191 ) {
struct V_33 * V_328 = F_200 ( V_34 , V_209 ) ;
if ( V_328 )
F_187 ( V_2 , V_4 , V_328 , V_178 , V_319 ) ;
} else {
F_187 ( V_2 , V_4 , V_34 , V_178 , V_319 ) ;
return;
}
}
V_323:
if ( ! V_191 )
F_51 ( V_34 ) ;
}
static struct V_1 * F_201 ( struct V_2 * V_2 , struct V_33 * V_34 )
{
struct V_309 * V_310 = F_199 ( V_34 ) ;
struct V_117 * V_70 = F_88 ( V_34 ) ;
struct V_5 V_99 = {
. V_71 = V_70 -> V_71 ,
. V_74 = V_70 -> V_74 ,
. V_329 = F_189 ( V_70 -> V_41 ) ,
. V_100 = ( F_198 ( V_310 ) ?
V_34 -> V_61 -> V_101 : 0 ) ,
. V_102 = ( F_198 ( V_310 ) ?
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
int V_191 = F_199 ( V_34 ) -> V_330 & V_331 ;
struct V_1 * V_4 ;
if ( F_179 ( V_34 ) -> V_13 & V_316 )
goto V_323;
V_4 = F_201 ( V_2 , V_34 ) ;
if ( F_13 ( V_4 ) ) {
F_51 ( V_34 ) ;
return F_14 ( V_4 ) ;
}
if ( ! V_191 ) {
if ( F_179 ( V_34 ) -> V_305 . V_332 ) {
if ( F_203 ( V_34 ) )
return 0 ;
} else if ( F_88 ( V_34 ) -> V_78 == V_252 ) {
struct V_213 * V_214 ;
V_214 = F_134 ( V_4 -> V_214 ) ;
if ( V_214 ) {
F_180 ( V_34 ) ;
F_204 ( V_214 , V_34 ) ;
return 0 ;
}
}
}
V_178 = F_106 ( V_4 , F_88 ( V_34 ) -> V_74 , F_88 ( V_34 ) -> V_71 ) ;
if ( ! V_178 ) {
int V_247 = F_197 ( V_4 , V_34 -> V_61 ) ;
if ( V_247 >= 0 )
V_178 = F_111 ( V_4 , F_88 ( V_34 ) -> V_71 ,
V_247 ) ;
}
if ( ! V_178 ) {
int V_247 ;
if ( V_191 ) {
struct V_33 * V_328 = F_200 ( V_34 , V_209 ) ;
F_205 ( V_34 ) ;
if ( ! V_328 )
return - V_186 ;
V_34 = V_328 ;
}
F_52 ( & V_107 ) ;
V_247 = F_197 ( V_4 , V_34 -> V_61 ) ;
if ( V_247 >= 0 ) {
int V_48 = F_138 ( V_4 , V_247 , V_34 ) ;
F_54 ( & V_107 ) ;
return V_48 ;
}
F_54 ( & V_107 ) ;
F_51 ( V_34 ) ;
return - V_333 ;
}
F_52 ( & V_107 ) ;
F_120 ( V_2 , V_4 , V_34 , V_178 , V_191 ) ;
F_54 ( & V_107 ) ;
if ( V_191 )
return F_205 ( V_34 ) ;
return 0 ;
V_323:
if ( V_191 )
return F_205 ( V_34 ) ;
F_51 ( V_34 ) ;
return 0 ;
}
int F_206 ( struct V_33 * V_34 )
{
struct V_215 * V_334 ;
struct V_2 * V_2 = F_35 ( V_34 -> V_61 ) ;
struct V_1 * V_4 ;
if ( ! F_207 ( V_34 , sizeof( * V_334 ) + sizeof( struct V_117 ) ) )
goto V_335;
V_334 = F_208 ( V_34 ) ;
V_4 = F_201 ( V_2 , V_34 ) ;
if ( F_13 ( V_4 ) )
goto V_335;
if ( ! V_4 -> V_270 ||
V_334 -> V_336 != V_337 || V_334 -> V_222 != V_338 )
goto V_335;
if ( F_61 ( V_4 , V_34 , sizeof( * V_334 ) ) ) {
V_335:
F_51 ( V_34 ) ;
}
return 0 ;
}
static int F_209 ( struct V_33 * V_34 )
{
struct V_339 * V_334 ;
struct V_2 * V_2 = F_35 ( V_34 -> V_61 ) ;
struct V_1 * V_4 ;
if ( ! F_207 ( V_34 , sizeof( * V_334 ) + sizeof( struct V_117 ) ) )
goto V_335;
V_334 = (struct V_339 * ) F_62 ( V_34 ) ;
if ( V_334 -> type != ( ( V_340 << 4 ) | ( V_341 ) ) ||
( V_334 -> V_13 & V_342 ) ||
( F_210 ( ( void * ) V_334 , sizeof( * V_334 ) ) != 0 &&
F_211 ( F_212 ( V_34 , 0 , V_34 -> V_110 , 0 ) ) ) )
goto V_335;
V_4 = F_201 ( V_2 , V_34 ) ;
if ( F_13 ( V_4 ) )
goto V_335;
if ( F_61 ( V_4 , V_34 , sizeof( * V_334 ) ) ) {
V_335:
F_51 ( V_34 ) ;
}
return 0 ;
}
static int F_118 ( struct V_1 * V_4 , struct V_33 * V_34 ,
struct V_152 * V_153 , struct V_343 * V_344 )
{
int V_299 ;
struct V_345 * V_346 ;
struct V_37 * V_347 ;
struct V_348 V_349 ;
if ( V_153 -> V_208 >= V_181 )
return - V_233 ;
if ( F_73 ( V_4 , V_153 -> V_208 ) &&
F_213 ( V_34 , V_350 , V_4 -> V_130 [ V_153 -> V_208 ] . V_61 -> V_101 ) < 0 )
return - V_211 ;
if ( ! ( V_347 = F_214 ( V_34 , V_351 ) ) )
return - V_211 ;
for ( V_299 = V_153 -> V_159 . V_9 . V_180 ; V_299 < V_153 -> V_159 . V_9 . V_144 ; V_299 ++ ) {
if ( F_73 ( V_4 , V_299 ) && V_153 -> V_159 . V_9 . V_179 [ V_299 ] < 255 ) {
if ( ! ( V_346 = F_215 ( V_34 , sizeof( * V_346 ) ) ) ) {
F_216 ( V_34 , V_347 ) ;
return - V_211 ;
}
V_346 -> V_352 = 0 ;
V_346 -> V_353 = V_153 -> V_159 . V_9 . V_179 [ V_299 ] ;
V_346 -> V_354 = V_4 -> V_130 [ V_299 ] . V_61 -> V_101 ;
V_346 -> V_355 = sizeof( * V_346 ) ;
}
}
F_217 ( V_34 , V_347 ) ;
V_349 . V_356 = V_153 -> V_159 . V_9 . V_212 ;
V_349 . V_357 = V_153 -> V_159 . V_9 . V_290 ;
V_349 . V_358 = V_153 -> V_159 . V_9 . V_291 ;
if ( F_218 ( V_34 , V_359 , sizeof( V_349 ) , & V_349 ) < 0 )
return - V_211 ;
V_344 -> V_360 = V_361 ;
return 1 ;
}
int F_219 ( struct V_2 * V_2 , struct V_33 * V_34 ,
T_6 V_74 , T_6 V_71 ,
struct V_343 * V_344 , int V_362 )
{
struct V_152 * V_178 ;
struct V_1 * V_4 ;
int V_7 ;
V_4 = F_1 ( V_2 , V_46 ) ;
if ( ! V_4 )
return - V_233 ;
F_133 () ;
V_178 = F_106 ( V_4 , V_74 , V_71 ) ;
if ( ! V_178 && V_34 -> V_61 ) {
int V_247 = F_197 ( V_4 , V_34 -> V_61 ) ;
if ( V_247 >= 0 )
V_178 = F_111 ( V_4 , V_71 , V_247 ) ;
}
if ( ! V_178 ) {
struct V_33 * V_328 ;
struct V_117 * V_70 ;
struct V_60 * V_61 ;
int V_247 = - 1 ;
if ( V_362 ) {
F_135 () ;
return - V_31 ;
}
V_61 = V_34 -> V_61 ;
F_52 ( & V_107 ) ;
if ( V_61 )
V_247 = F_197 ( V_4 , V_61 ) ;
if ( V_247 < 0 ) {
F_54 ( & V_107 ) ;
F_135 () ;
return - V_333 ;
}
V_328 = F_200 ( V_34 , V_209 ) ;
if ( ! V_328 ) {
F_54 ( & V_107 ) ;
F_135 () ;
return - V_53 ;
}
F_124 ( V_328 , sizeof( struct V_117 ) ) ;
F_66 ( V_328 ) ;
V_70 = F_88 ( V_328 ) ;
V_70 -> V_77 = sizeof( struct V_117 ) >> 2 ;
V_70 -> V_74 = V_74 ;
V_70 -> V_71 = V_71 ;
V_70 -> V_76 = 0 ;
V_7 = F_138 ( V_4 , V_247 , V_328 ) ;
F_54 ( & V_107 ) ;
F_135 () ;
return V_7 ;
}
F_52 ( & V_107 ) ;
V_7 = F_118 ( V_4 , V_34 , V_178 , V_344 ) ;
F_54 ( & V_107 ) ;
F_135 () ;
return V_7 ;
}
static int F_220 ( struct V_1 * V_4 , struct V_33 * V_34 ,
T_1 V_169 , T_1 V_363 , struct V_152 * V_153 , int V_275 ,
int V_13 )
{
struct V_162 * V_163 ;
struct V_343 * V_344 ;
int V_7 ;
V_163 = F_221 ( V_34 , V_169 , V_363 , V_275 , sizeof( * V_344 ) , V_13 ) ;
if ( ! V_163 )
return - V_211 ;
V_344 = F_91 ( V_163 ) ;
V_344 -> V_364 = V_365 ;
V_344 -> V_366 = 32 ;
V_344 -> V_367 = 32 ;
V_344 -> V_368 = 0 ;
V_344 -> V_369 = V_4 -> V_3 ;
if ( F_213 ( V_34 , V_370 , V_4 -> V_3 ) )
goto V_371;
V_344 -> V_360 = V_361 ;
V_344 -> V_372 = V_373 ;
if ( V_153 -> V_237 & V_238 )
V_344 -> V_374 = V_375 ;
else
V_344 -> V_374 = V_376 ;
V_344 -> V_377 = 0 ;
if ( F_222 ( V_34 , V_378 , V_153 -> V_203 ) ||
F_222 ( V_34 , V_379 , V_153 -> V_204 ) )
goto V_371;
V_7 = F_118 ( V_4 , V_34 , V_153 , V_344 ) ;
if ( V_7 < 0 && V_7 != - V_233 )
goto V_371;
F_223 ( V_34 , V_163 ) ;
return 0 ;
V_371:
F_224 ( V_34 , V_163 ) ;
return - V_211 ;
}
static T_8 F_225 ( bool V_161 , int V_144 )
{
T_8 V_110 =
F_226 ( sizeof( struct V_343 ) )
+ F_227 ( 4 )
+ F_227 ( 4 )
+ F_227 ( 4 )
;
if ( ! V_161 )
V_110 = V_110
+ F_227 ( 4 )
+ F_227 ( 0 )
+ V_144 * F_228 ( sizeof( struct V_345 ) )
+ F_227 ( sizeof( struct V_348 ) )
;
return V_110 ;
}
static void F_98 ( struct V_1 * V_4 , struct V_152 * V_229 ,
int V_275 )
{
struct V_2 * V_2 = F_85 ( & V_4 -> V_2 ) ;
struct V_33 * V_34 ;
int V_7 = - V_186 ;
V_34 = F_229 ( F_225 ( V_229 -> V_208 >= V_181 , V_4 -> V_144 ) ,
V_209 ) ;
if ( ! V_34 )
goto V_380;
V_7 = F_220 ( V_4 , V_34 , 0 , 0 , V_229 , V_275 , 0 ) ;
if ( V_7 < 0 )
goto V_380;
F_230 ( V_34 , V_2 , 0 , V_381 , NULL , V_209 ) ;
return;
V_380:
F_51 ( V_34 ) ;
if ( V_7 < 0 )
F_231 ( V_2 , V_381 , V_7 ) ;
}
static int F_232 ( struct V_33 * V_34 , struct V_382 * V_383 )
{
struct V_2 * V_2 = F_154 ( V_34 -> V_240 ) ;
struct V_1 * V_4 ;
struct V_152 * V_229 ;
unsigned int V_384 = 0 , V_385 ;
unsigned int V_386 = 0 , V_387 ;
unsigned int V_157 = 0 , V_388 ;
V_385 = V_383 -> args [ 0 ] ;
V_387 = V_383 -> args [ 1 ] ;
V_388 = V_383 -> args [ 2 ] ;
F_133 () ;
F_2 (mrt, net) {
if ( V_384 < V_385 )
goto V_389;
if ( V_384 > V_385 )
V_387 = 0 ;
for ( V_386 = V_387 ; V_386 < V_54 ; V_386 ++ ) {
F_108 (mfc, &mrt->mfc_cache_array[h], list) {
if ( V_157 < V_388 )
goto V_390;
if ( F_220 ( V_4 , V_34 ,
F_93 ( V_383 -> V_34 ) . V_169 ,
V_383 -> V_163 -> V_391 ,
V_229 , V_226 ,
V_392 ) < 0 )
goto V_393;
V_390:
V_157 ++ ;
}
V_157 = V_388 = 0 ;
}
F_139 ( & V_172 ) ;
F_140 (mfc, &mrt->mfc_unres_queue, list) {
if ( V_157 < V_388 )
goto V_394;
if ( F_220 ( V_4 , V_34 ,
F_93 ( V_383 -> V_34 ) . V_169 ,
V_383 -> V_163 -> V_391 ,
V_229 , V_226 ,
V_392 ) < 0 ) {
F_142 ( & V_172 ) ;
goto V_393;
}
V_394:
V_157 ++ ;
}
F_142 ( & V_172 ) ;
V_157 = V_388 = 0 ;
V_387 = 0 ;
V_389:
V_384 ++ ;
}
V_393:
F_135 () ;
V_383 -> args [ 2 ] = V_157 ;
V_383 -> args [ 1 ] = V_386 ;
V_383 -> args [ 0 ] = V_384 ;
return V_34 -> V_110 ;
}
static bool F_233 ( unsigned char V_374 )
{
switch ( V_374 ) {
case V_375 :
case V_376 :
return true ;
}
return false ;
}
static int F_234 ( const struct V_37 * V_395 , struct V_228 * V_396 )
{
struct V_345 * V_397 = F_235 ( V_395 ) ;
int V_398 = F_236 ( V_395 ) , V_139 = 0 ;
while ( F_237 ( V_397 , V_398 ) ) {
V_396 -> V_236 [ V_139 ] = V_397 -> V_353 ;
if ( ++ V_139 == V_181 )
break;
V_397 = F_238 ( V_397 , & V_398 ) ;
}
return V_398 > 0 ? - V_28 : V_139 ;
}
static int F_239 ( struct V_2 * V_2 , struct V_162 * V_163 ,
struct V_228 * V_396 , int * V_183 ,
struct V_1 * * V_399 )
{
struct V_60 * V_61 = NULL ;
T_1 V_400 = V_46 ;
struct V_1 * V_4 ;
struct V_37 * V_401 ;
struct V_343 * V_344 ;
int V_218 , V_402 ;
V_218 = F_240 ( V_163 , sizeof( * V_344 ) , V_403 , V_404 ) ;
if ( V_218 < 0 )
goto V_175;
V_344 = F_91 ( V_163 ) ;
V_218 = - V_28 ;
if ( V_344 -> V_364 != V_365 || V_344 -> V_366 != 32 ||
V_344 -> V_360 != V_361 ||
V_344 -> V_372 != V_373 ||
! F_233 ( V_344 -> V_374 ) )
goto V_175;
memset ( V_396 , 0 , sizeof( * V_396 ) ) ;
V_396 -> V_234 = - 1 ;
V_218 = 0 ;
F_241 (attr, nlh, sizeof(struct rtmsg), rem) {
switch ( F_242 ( V_401 ) ) {
case V_378 :
V_396 -> V_232 . V_73 = F_243 ( V_401 ) ;
break;
case V_379 :
V_396 -> V_231 . V_73 = F_243 ( V_401 ) ;
break;
case V_350 :
V_61 = F_244 ( V_2 , F_245 ( V_401 ) ) ;
if ( ! V_61 ) {
V_218 = - V_333 ;
goto V_175;
}
break;
case V_351 :
if ( F_234 ( V_401 , V_396 ) < 0 ) {
V_218 = - V_28 ;
goto V_175;
}
break;
case V_405 :
V_218 = 1 ;
break;
case V_370 :
V_400 = F_245 ( V_401 ) ;
break;
}
}
V_4 = F_1 ( V_2 , V_400 ) ;
if ( ! V_4 ) {
V_218 = - V_233 ;
goto V_175;
}
* V_399 = V_4 ;
* V_183 = V_344 -> V_374 == V_376 ? 1 : 0 ;
if ( V_61 )
V_396 -> V_234 = F_197 ( V_4 , V_61 ) ;
V_175:
return V_218 ;
}
static int F_246 ( struct V_33 * V_34 , struct V_162 * V_163 )
{
struct V_2 * V_2 = F_154 ( V_34 -> V_240 ) ;
int V_218 , V_183 , V_230 ;
struct V_1 * V_406 ;
struct V_228 V_396 ;
V_183 = 0 ;
V_406 = NULL ;
V_218 = F_239 ( V_2 , V_163 , & V_396 , & V_183 , & V_406 ) ;
if ( V_218 < 0 )
return V_218 ;
V_230 = V_218 ? V_396 . V_234 : - 1 ;
if ( V_163 -> V_164 == V_226 )
return F_148 ( V_2 , V_406 , & V_396 , V_183 , V_230 ) ;
else
return F_146 ( V_406 , & V_396 , V_230 ) ;
}
static struct V_143 * F_247 ( struct V_2 * V_2 ,
struct V_407 * V_408 ,
T_9 V_409 )
{
struct V_1 * V_4 = V_408 -> V_4 ;
for ( V_408 -> V_299 = 0 ; V_408 -> V_299 < V_4 -> V_144 ; ++ V_408 -> V_299 ) {
if ( ! F_73 ( V_4 , V_408 -> V_299 ) )
continue;
if ( V_409 -- == 0 )
return & V_4 -> V_130 [ V_408 -> V_299 ] ;
}
return NULL ;
}
static void * F_248 ( struct V_410 * V_363 , T_9 * V_409 )
__acquires( V_107 )
{
struct V_407 * V_408 = V_363 -> V_411 ;
struct V_2 * V_2 = F_249 ( V_363 ) ;
struct V_1 * V_4 ;
V_4 = F_1 ( V_2 , V_46 ) ;
if ( ! V_4 )
return F_25 ( - V_233 ) ;
V_408 -> V_4 = V_4 ;
F_52 ( & V_107 ) ;
return * V_409 ? F_247 ( V_2 , V_363 -> V_411 , * V_409 - 1 )
: V_412 ;
}
static void * F_250 ( struct V_410 * V_363 , void * V_63 , T_9 * V_409 )
{
struct V_407 * V_408 = V_363 -> V_411 ;
struct V_2 * V_2 = F_249 ( V_363 ) ;
struct V_1 * V_4 = V_408 -> V_4 ;
++ * V_409 ;
if ( V_63 == V_412 )
return F_247 ( V_2 , V_408 , 0 ) ;
while ( ++ V_408 -> V_299 < V_4 -> V_144 ) {
if ( ! F_73 ( V_4 , V_408 -> V_299 ) )
continue;
return & V_4 -> V_130 [ V_408 -> V_299 ] ;
}
return NULL ;
}
static void F_251 ( struct V_410 * V_363 , void * V_63 )
__releases( V_107 )
{
F_54 ( & V_107 ) ;
}
static int F_252 ( struct V_410 * V_363 , void * V_63 )
{
struct V_407 * V_408 = V_363 -> V_411 ;
struct V_1 * V_4 = V_408 -> V_4 ;
if ( V_63 == V_412 ) {
F_253 ( V_363 ,
L_6 ) ;
} else {
const struct V_143 * V_247 = V_63 ;
const char * V_80 = V_247 -> V_61 ? V_247 -> V_61 -> V_80 : L_7 ;
F_254 ( V_363 ,
L_8 ,
V_247 - V_4 -> V_130 ,
V_80 , V_247 -> V_196 , V_247 -> V_198 ,
V_247 -> V_197 , V_247 -> V_199 ,
V_247 -> V_13 , V_247 -> V_191 , V_247 -> V_192 ) ;
}
return 0 ;
}
static int F_255 ( struct V_413 * V_413 , struct V_414 * V_414 )
{
return F_256 ( V_413 , V_414 , & V_415 ,
sizeof( struct V_407 ) ) ;
}
static struct V_152 * F_257 ( struct V_2 * V_2 ,
struct V_416 * V_417 , T_9 V_409 )
{
struct V_1 * V_4 = V_417 -> V_4 ;
struct V_152 * V_229 ;
F_133 () ;
for ( V_417 -> V_299 = 0 ; V_417 -> V_299 < V_54 ; V_417 -> V_299 ++ ) {
V_417 -> V_178 = & V_4 -> V_55 [ V_417 -> V_299 ] ;
F_108 (mfc, it->cache, list)
if ( V_409 -- == 0 )
return V_229 ;
}
F_135 () ;
F_139 ( & V_172 ) ;
V_417 -> V_178 = & V_4 -> V_56 ;
F_140 (mfc, it->cache, list)
if ( V_409 -- == 0 )
return V_229 ;
F_142 ( & V_172 ) ;
V_417 -> V_178 = NULL ;
return NULL ;
}
static void * F_258 ( struct V_410 * V_363 , T_9 * V_409 )
{
struct V_416 * V_417 = V_363 -> V_411 ;
struct V_2 * V_2 = F_249 ( V_363 ) ;
struct V_1 * V_4 ;
V_4 = F_1 ( V_2 , V_46 ) ;
if ( ! V_4 )
return F_25 ( - V_233 ) ;
V_417 -> V_4 = V_4 ;
V_417 -> V_178 = NULL ;
V_417 -> V_299 = 0 ;
return * V_409 ? F_257 ( V_2 , V_363 -> V_411 , * V_409 - 1 )
: V_412 ;
}
static void * F_259 ( struct V_410 * V_363 , void * V_63 , T_9 * V_409 )
{
struct V_152 * V_229 = V_63 ;
struct V_416 * V_417 = V_363 -> V_411 ;
struct V_2 * V_2 = F_249 ( V_363 ) ;
struct V_1 * V_4 = V_417 -> V_4 ;
++ * V_409 ;
if ( V_63 == V_412 )
return F_257 ( V_2 , V_363 -> V_411 , 0 ) ;
if ( V_229 -> V_50 . V_49 != V_417 -> V_178 )
return F_260 ( V_229 -> V_50 . V_49 , struct V_152 , V_50 ) ;
if ( V_417 -> V_178 == & V_4 -> V_56 )
goto V_418;
F_261 ( V_417 -> V_178 != & V_4 -> V_55 [ V_417 -> V_299 ] ) ;
while ( ++ V_417 -> V_299 < V_54 ) {
V_417 -> V_178 = & V_4 -> V_55 [ V_417 -> V_299 ] ;
if ( F_96 ( V_417 -> V_178 ) )
continue;
return F_262 ( V_417 -> V_178 , struct V_152 , V_50 ) ;
}
F_135 () ;
V_417 -> V_178 = & V_4 -> V_56 ;
V_417 -> V_299 = 0 ;
F_139 ( & V_172 ) ;
if ( ! F_96 ( V_417 -> V_178 ) )
return F_262 ( V_417 -> V_178 , struct V_152 , V_50 ) ;
V_418:
F_142 ( & V_172 ) ;
V_417 -> V_178 = NULL ;
return NULL ;
}
static void F_263 ( struct V_410 * V_363 , void * V_63 )
{
struct V_416 * V_417 = V_363 -> V_411 ;
struct V_1 * V_4 = V_417 -> V_4 ;
if ( V_417 -> V_178 == & V_4 -> V_56 )
F_142 ( & V_172 ) ;
else if ( V_417 -> V_178 == & V_4 -> V_55 [ V_417 -> V_299 ] )
F_135 () ;
}
static int F_264 ( struct V_410 * V_363 , void * V_63 )
{
int V_419 ;
if ( V_63 == V_412 ) {
F_253 ( V_363 ,
L_9 ) ;
} else {
const struct V_152 * V_229 = V_63 ;
const struct V_416 * V_417 = V_363 -> V_411 ;
const struct V_1 * V_4 = V_417 -> V_4 ;
F_254 ( V_363 , L_10 ,
( V_84 T_1 ) V_229 -> V_204 ,
( V_84 T_1 ) V_229 -> V_203 ,
V_229 -> V_208 ) ;
if ( V_417 -> V_178 != & V_4 -> V_56 ) {
F_254 ( V_363 , L_11 ,
V_229 -> V_159 . V_9 . V_212 ,
V_229 -> V_159 . V_9 . V_290 ,
V_229 -> V_159 . V_9 . V_291 ) ;
for ( V_419 = V_229 -> V_159 . V_9 . V_180 ;
V_419 < V_229 -> V_159 . V_9 . V_144 ; V_419 ++ ) {
if ( F_73 ( V_4 , V_419 ) &&
V_229 -> V_159 . V_9 . V_179 [ V_419 ] < 255 )
F_254 ( V_363 ,
L_12 ,
V_419 , V_229 -> V_159 . V_9 . V_179 [ V_419 ] ) ;
}
} else {
F_254 ( V_363 , L_11 , 0ul , 0ul , 0ul ) ;
}
F_265 ( V_363 , '\n' ) ;
}
return 0 ;
}
static int F_266 ( struct V_413 * V_413 , struct V_414 * V_414 )
{
return F_256 ( V_413 , V_414 , & V_420 ,
sizeof( struct V_416 ) ) ;
}
static int T_2 F_267 ( struct V_2 * V_2 )
{
int V_7 ;
V_7 = F_11 ( V_2 ) ;
if ( V_7 < 0 )
goto V_421;
#ifdef F_268
V_7 = - V_53 ;
if ( ! F_269 ( L_13 , 0 , V_2 -> V_422 , & V_423 ) )
goto V_424;
if ( ! F_269 ( L_14 , 0 , V_2 -> V_422 , & V_425 ) )
goto V_426;
#endif
return 0 ;
#ifdef F_268
V_426:
F_270 ( L_13 , V_2 -> V_422 ) ;
V_424:
F_20 ( V_2 ) ;
#endif
V_421:
return V_7 ;
}
static void T_3 F_271 ( struct V_2 * V_2 )
{
#ifdef F_268
F_270 ( L_14 , V_2 -> V_422 ) ;
F_270 ( L_13 , V_2 -> V_422 ) ;
#endif
F_20 ( V_2 ) ;
}
int T_10 F_272 ( void )
{
int V_7 ;
V_155 = F_273 ( L_15 ,
sizeof( struct V_152 ) ,
0 , V_427 | V_428 ,
NULL ) ;
V_7 = F_274 ( & V_429 ) ;
if ( V_7 )
goto V_430;
V_7 = F_275 ( & V_431 ) ;
if ( V_7 )
goto V_432;
#ifdef F_276
if ( F_277 ( & V_433 , V_434 ) < 0 ) {
F_278 ( L_16 , V_435 ) ;
V_7 = - V_31 ;
goto V_436;
}
#endif
F_279 ( V_365 , V_437 ,
NULL , F_232 , NULL ) ;
F_279 ( V_365 , V_226 ,
F_246 , NULL , NULL ) ;
F_279 ( V_365 , V_177 ,
F_246 , NULL , NULL ) ;
return 0 ;
#ifdef F_276
V_436:
F_280 ( & V_431 ) ;
#endif
V_432:
F_281 ( & V_429 ) ;
V_430:
F_282 ( V_155 ) ;
return V_7 ;
}
