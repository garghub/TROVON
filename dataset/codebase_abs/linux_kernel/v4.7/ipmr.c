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
if ( V_153 ) {
V_153 -> V_159 . V_9 . V_209 = V_173 - V_210 - 1 ;
V_153 -> V_159 . V_9 . V_180 = V_181 ;
}
return V_153 ;
}
static struct V_152 * F_114 ( void )
{
struct V_152 * V_153 = F_113 ( V_155 , V_211 ) ;
if ( V_153 ) {
F_115 ( & V_153 -> V_159 . V_160 . V_161 ) ;
V_153 -> V_159 . V_160 . V_171 = V_173 + 10 * V_174 ;
}
return V_153 ;
}
static void F_116 ( struct V_2 * V_2 , struct V_1 * V_4 ,
struct V_152 * V_212 , struct V_152 * V_153 )
{
struct V_33 * V_34 ;
struct V_156 * V_157 ;
while ( ( V_34 = F_117 ( & V_212 -> V_159 . V_160 . V_161 ) ) ) {
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
V_157 -> error = - V_213 ;
memset ( & V_157 -> V_168 , 0 , sizeof( V_157 -> V_168 ) ) ;
}
F_92 ( V_34 , V_2 , F_93 ( V_34 ) . V_169 ) ;
} else {
F_120 ( V_2 , V_4 , V_34 , V_153 , 0 ) ;
}
}
}
static int F_53 ( struct V_1 * V_4 ,
struct V_33 * V_214 , T_7 V_139 , int assert )
{
const int V_77 = F_121 ( V_214 ) ;
struct V_215 * V_216 ;
struct V_217 * V_218 ;
struct V_219 * V_168 ;
struct V_33 * V_34 ;
int V_220 ;
if ( assert == V_112 )
V_34 = F_122 ( V_214 , sizeof( struct V_117 ) ) ;
else
V_34 = F_123 ( 128 , V_211 ) ;
if ( ! V_34 )
return - V_186 ;
if ( assert == V_112 ) {
F_124 ( V_34 , sizeof( struct V_117 ) ) ;
F_66 ( V_34 ) ;
F_125 ( V_34 ) ;
V_168 = (struct V_219 * ) F_126 ( V_34 ) ;
memcpy ( V_168 , F_126 ( V_214 ) , sizeof( struct V_117 ) ) ;
V_168 -> V_221 = V_112 ;
V_168 -> V_222 = 0 ;
V_168 -> V_223 = V_4 -> V_59 ;
F_88 ( V_34 ) -> V_77 = sizeof( struct V_117 ) >> 2 ;
F_88 ( V_34 ) -> V_129 = F_67 ( F_64 ( F_88 ( V_214 ) -> V_129 ) +
sizeof( struct V_117 ) ) ;
} else {
F_127 ( V_34 , V_34 -> V_110 ) ;
F_128 ( V_34 , V_77 ) ;
F_129 ( V_34 , V_214 -> V_134 , V_77 ) ;
F_88 ( V_34 ) -> V_78 = 0 ;
V_168 = (struct V_219 * ) F_126 ( V_34 ) ;
V_168 -> V_223 = V_139 ;
F_130 ( V_34 , F_131 ( F_132 ( V_214 ) ) ) ;
V_218 = (struct V_217 * ) F_128 ( V_34 , sizeof( struct V_217 ) ) ;
V_218 -> type = assert ;
V_168 -> V_221 = assert ;
V_218 -> V_224 = 0 ;
F_88 ( V_34 ) -> V_129 = F_67 ( V_34 -> V_110 ) ;
V_34 -> V_225 = V_34 -> V_132 ;
}
F_133 () ;
V_216 = F_134 ( V_4 -> V_216 ) ;
if ( ! V_216 ) {
F_135 () ;
F_51 ( V_34 ) ;
return - V_28 ;
}
V_220 = F_136 ( V_216 , V_34 ) ;
F_135 () ;
if ( V_220 < 0 ) {
F_137 ( L_5 ) ;
F_51 ( V_34 ) ;
}
return V_220 ;
}
static int F_138 ( struct V_1 * V_4 , T_7 V_139 ,
struct V_33 * V_34 )
{
bool V_226 = false ;
int V_7 ;
struct V_152 * V_153 ;
const struct V_117 * V_70 = F_88 ( V_34 ) ;
F_139 ( & V_172 ) ;
F_140 (c, &mrt->mfc_unres_queue, list) {
if ( V_153 -> V_204 == V_70 -> V_71 &&
V_153 -> V_203 == V_70 -> V_74 ) {
V_226 = true ;
break;
}
}
if ( ! V_226 ) {
if ( F_141 ( & V_4 -> V_158 ) >= 10 ||
( V_153 = F_114 () ) == NULL ) {
F_142 ( & V_172 ) ;
F_51 ( V_34 ) ;
return - V_186 ;
}
V_153 -> V_208 = - 1 ;
V_153 -> V_203 = V_70 -> V_74 ;
V_153 -> V_204 = V_70 -> V_71 ;
V_7 = F_53 ( V_4 , V_34 , V_139 , V_227 ) ;
if ( V_7 < 0 ) {
F_142 ( & V_172 ) ;
F_82 ( V_153 ) ;
F_51 ( V_34 ) ;
return V_7 ;
}
F_143 ( & V_4 -> V_158 ) ;
F_144 ( & V_153 -> V_50 , & V_4 -> V_56 ) ;
F_98 ( V_4 , V_153 , V_228 ) ;
if ( F_141 ( & V_4 -> V_158 ) == 1 )
F_95 ( & V_4 -> V_57 , V_153 -> V_159 . V_160 . V_171 ) ;
}
if ( V_153 -> V_159 . V_160 . V_161 . V_229 > 3 ) {
F_51 ( V_34 ) ;
V_7 = - V_186 ;
} else {
F_145 ( & V_153 -> V_159 . V_160 . V_161 , V_34 ) ;
V_7 = 0 ;
}
F_142 ( & V_172 ) ;
return V_7 ;
}
static int F_146 ( struct V_1 * V_4 , struct V_230 * V_231 , int V_232 )
{
int line ;
struct V_152 * V_153 , * V_49 ;
line = F_107 ( V_231 -> V_233 . V_73 , V_231 -> V_234 . V_73 ) ;
F_22 (c, next, &mrt->mfc_cache_array[line], list) {
if ( V_153 -> V_203 == V_231 -> V_234 . V_73 &&
V_153 -> V_204 == V_231 -> V_233 . V_73 &&
( V_232 == - 1 || V_232 == V_153 -> V_208 ) ) {
F_147 ( & V_153 -> V_50 ) ;
F_98 ( V_4 , V_153 , V_177 ) ;
F_82 ( V_153 ) ;
return 0 ;
}
}
return - V_235 ;
}
static int F_148 ( struct V_2 * V_2 , struct V_1 * V_4 ,
struct V_230 * V_231 , int V_183 , int V_232 )
{
bool V_226 = false ;
int line ;
struct V_152 * V_212 , * V_153 ;
if ( V_231 -> V_236 >= V_181 )
return - V_237 ;
line = F_107 ( V_231 -> V_233 . V_73 , V_231 -> V_234 . V_73 ) ;
F_140 (c, &mrt->mfc_cache_array[line], list) {
if ( V_153 -> V_203 == V_231 -> V_234 . V_73 &&
V_153 -> V_204 == V_231 -> V_233 . V_73 &&
( V_232 == - 1 || V_232 == V_153 -> V_208 ) ) {
V_226 = true ;
break;
}
}
if ( V_226 ) {
F_71 ( & V_107 ) ;
V_153 -> V_208 = V_231 -> V_236 ;
F_100 ( V_4 , V_153 , V_231 -> V_238 ) ;
if ( ! V_183 )
V_153 -> V_239 |= V_240 ;
F_72 ( & V_107 ) ;
F_98 ( V_4 , V_153 , V_228 ) ;
return 0 ;
}
if ( V_231 -> V_233 . V_73 != F_110 ( V_205 ) &&
! F_63 ( V_231 -> V_233 . V_73 ) )
return - V_28 ;
V_153 = F_112 () ;
if ( ! V_153 )
return - V_53 ;
V_153 -> V_203 = V_231 -> V_234 . V_73 ;
V_153 -> V_204 = V_231 -> V_233 . V_73 ;
V_153 -> V_208 = V_231 -> V_236 ;
F_100 ( V_4 , V_153 , V_231 -> V_238 ) ;
if ( ! V_183 )
V_153 -> V_239 |= V_240 ;
F_149 ( & V_153 -> V_50 , & V_4 -> V_55 [ line ] ) ;
V_226 = false ;
F_139 ( & V_172 ) ;
F_140 (uc, &mrt->mfc_unres_queue, list) {
if ( V_212 -> V_203 == V_153 -> V_203 &&
V_212 -> V_204 == V_153 -> V_204 ) {
F_23 ( & V_212 -> V_50 ) ;
F_86 ( & V_4 -> V_158 ) ;
V_226 = true ;
break;
}
}
if ( F_96 ( & V_4 -> V_56 ) )
F_150 ( & V_4 -> V_57 ) ;
F_142 ( & V_172 ) ;
if ( V_226 ) {
F_116 ( V_2 , V_4 , V_212 , V_153 ) ;
F_82 ( V_212 ) ;
}
F_98 ( V_4 , V_153 , V_228 ) ;
return 0 ;
}
static void F_32 ( struct V_1 * V_4 , bool V_241 )
{
int V_51 ;
F_151 ( V_50 ) ;
struct V_152 * V_153 , * V_49 ;
for ( V_51 = 0 ; V_51 < V_4 -> V_144 ; V_51 ++ ) {
if ( ! V_241 && ( V_4 -> V_130 [ V_51 ] . V_13 & V_193 ) )
continue;
F_70 ( V_4 , V_51 , 0 , & V_50 ) ;
}
F_152 ( & V_50 ) ;
for ( V_51 = 0 ; V_51 < V_54 ; V_51 ++ ) {
F_22 (c, next, &mrt->mfc_cache_array[i], list) {
if ( ! V_241 && ( V_153 -> V_239 & V_240 ) )
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
static void F_153 ( struct V_215 * V_242 )
{
struct V_2 * V_2 = F_154 ( V_242 ) ;
struct V_1 * V_4 ;
F_21 () ;
F_2 (mrt, net) {
if ( V_242 == F_155 ( V_4 -> V_216 ) ) {
F_156 ( V_2 , V_147 ) -- ;
F_75 ( V_2 , V_148 ,
V_243 ,
V_2 -> V_15 . V_244 ) ;
F_157 ( V_4 -> V_216 , NULL ) ;
F_32 ( V_4 , false ) ;
}
}
F_24 () ;
}
int F_158 ( struct V_215 * V_242 , int V_245 , char V_85 * V_246 ,
unsigned int V_247 )
{
struct V_2 * V_2 = F_154 ( V_242 ) ;
int V_248 , V_220 = 0 , V_232 = 0 ;
struct V_1 * V_4 ;
struct V_62 V_249 ;
struct V_230 V_231 ;
T_1 V_250 ;
F_21 () ;
if ( V_242 -> V_251 != V_252 ||
F_159 ( V_242 ) -> V_253 != V_254 ) {
V_220 = - V_96 ;
goto V_255;
}
V_4 = F_1 ( V_2 , F_160 ( V_242 ) -> V_256 ? : V_46 ) ;
if ( ! V_4 ) {
V_220 = - V_235 ;
goto V_255;
}
if ( V_245 != V_257 ) {
if ( V_242 != F_161 ( V_4 -> V_216 ) &&
! F_162 ( V_2 -> V_258 , V_259 ) ) {
V_220 = - V_26 ;
goto V_255;
}
}
switch ( V_245 ) {
case V_257 :
if ( V_247 != sizeof( int ) ) {
V_220 = - V_28 ;
break;
}
if ( F_155 ( V_4 -> V_216 ) ) {
V_220 = - V_184 ;
break;
}
V_220 = F_163 ( V_242 , 1 , F_153 ) ;
if ( V_220 == 0 ) {
F_164 ( V_4 -> V_216 , V_242 ) ;
F_156 ( V_2 , V_147 ) ++ ;
F_75 ( V_2 , V_148 ,
V_243 ,
V_2 -> V_15 . V_244 ) ;
}
break;
case V_260 :
if ( V_242 != F_161 ( V_4 -> V_216 ) ) {
V_220 = - V_26 ;
} else {
F_24 () ;
V_220 = F_163 ( V_242 , 0 , NULL ) ;
goto V_175;
}
break;
case V_261 :
case V_262 :
if ( V_247 != sizeof( V_249 ) ) {
V_220 = - V_28 ;
break;
}
if ( F_165 ( & V_249 , V_246 , sizeof( V_249 ) ) ) {
V_220 = - V_263 ;
break;
}
if ( V_249 . V_81 >= V_181 ) {
V_220 = - V_237 ;
break;
}
if ( V_245 == V_261 ) {
V_220 = F_101 ( V_2 , V_4 , & V_249 ,
V_242 == F_155 ( V_4 -> V_216 ) ) ;
} else {
V_220 = F_70 ( V_4 , V_249 . V_81 , 0 , NULL ) ;
}
break;
case V_264 :
case V_265 :
V_232 = - 1 ;
case V_266 :
case V_267 :
if ( V_247 != sizeof( V_231 ) ) {
V_220 = - V_28 ;
break;
}
if ( F_165 ( & V_231 , V_246 , sizeof( V_231 ) ) ) {
V_220 = - V_263 ;
break;
}
if ( V_232 == 0 )
V_232 = V_231 . V_236 ;
if ( V_245 == V_265 || V_245 == V_267 )
V_220 = F_146 ( V_4 , & V_231 , V_232 ) ;
else
V_220 = F_148 ( V_2 , V_4 , & V_231 ,
V_242 == F_155 ( V_4 -> V_216 ) ,
V_232 ) ;
break;
case V_268 :
if ( V_247 != sizeof( V_248 ) ) {
V_220 = - V_28 ;
break;
}
if ( F_166 ( V_248 , ( int V_85 * ) V_246 ) ) {
V_220 = - V_263 ;
break;
}
V_4 -> V_269 = V_248 ;
break;
case V_270 :
if ( ! F_102 () ) {
V_220 = - V_271 ;
break;
}
if ( V_247 != sizeof( V_248 ) ) {
V_220 = - V_28 ;
break;
}
if ( F_166 ( V_248 , ( int V_85 * ) V_246 ) ) {
V_220 = - V_263 ;
break;
}
V_248 = ! ! V_248 ;
if ( V_248 != V_4 -> V_272 ) {
V_4 -> V_272 = V_248 ;
V_4 -> V_269 = V_248 ;
}
break;
case V_273 :
if ( ! F_167 ( F_29 ) ) {
V_220 = - V_271 ;
break;
}
if ( V_247 != sizeof( V_250 ) ) {
V_220 = - V_28 ;
break;
}
if ( F_166 ( V_250 , ( T_1 V_85 * ) V_246 ) ) {
V_220 = - V_263 ;
break;
}
if ( V_242 == F_155 ( V_4 -> V_216 ) ) {
V_220 = - V_274 ;
} else {
V_4 = F_16 ( V_2 , V_250 ) ;
if ( F_13 ( V_4 ) )
V_220 = F_14 ( V_4 ) ;
else
F_160 ( V_242 ) -> V_256 = V_250 ;
}
break;
default:
V_220 = - V_271 ;
}
V_255:
F_24 () ;
V_175:
return V_220 ;
}
int F_168 ( struct V_215 * V_242 , int V_245 , char V_85 * V_246 , int V_85 * V_247 )
{
int V_275 ;
int V_248 ;
struct V_2 * V_2 = F_154 ( V_242 ) ;
struct V_1 * V_4 ;
if ( V_242 -> V_251 != V_252 ||
F_159 ( V_242 ) -> V_253 != V_254 )
return - V_96 ;
V_4 = F_1 ( V_2 , F_160 ( V_242 ) -> V_256 ? : V_46 ) ;
if ( ! V_4 )
return - V_235 ;
switch ( V_245 ) {
case V_276 :
V_248 = 0x0305 ;
break;
case V_270 :
if ( ! F_102 () )
return - V_271 ;
V_248 = V_4 -> V_272 ;
break;
case V_268 :
V_248 = V_4 -> V_269 ;
break;
default:
return - V_271 ;
}
if ( F_166 ( V_275 , V_247 ) )
return - V_263 ;
V_275 = F_169 (unsigned int, olr, sizeof(int)) ;
if ( V_275 < 0 )
return - V_28 ;
if ( F_170 ( V_275 , V_247 ) )
return - V_263 ;
if ( F_171 ( V_246 , & V_248 , V_275 ) )
return - V_263 ;
return 0 ;
}
int F_172 ( struct V_215 * V_242 , int V_277 , void V_85 * V_11 )
{
struct V_278 V_279 ;
struct V_280 V_281 ;
struct V_143 * V_249 ;
struct V_152 * V_153 ;
struct V_2 * V_2 = F_154 ( V_242 ) ;
struct V_1 * V_4 ;
V_4 = F_1 ( V_2 , F_160 ( V_242 ) -> V_256 ? : V_46 ) ;
if ( ! V_4 )
return - V_235 ;
switch ( V_277 ) {
case V_282 :
if ( F_165 ( & V_281 , V_11 , sizeof( V_281 ) ) )
return - V_263 ;
if ( V_281 . V_139 >= V_4 -> V_144 )
return - V_28 ;
F_52 ( & V_107 ) ;
V_249 = & V_4 -> V_130 [ V_281 . V_139 ] ;
if ( F_73 ( V_4 , V_281 . V_139 ) ) {
V_281 . V_283 = V_249 -> V_198 ;
V_281 . V_284 = V_249 -> V_199 ;
V_281 . V_285 = V_249 -> V_196 ;
V_281 . V_286 = V_249 -> V_197 ;
F_54 ( & V_107 ) ;
if ( F_171 ( V_11 , & V_281 , sizeof( V_281 ) ) )
return - V_263 ;
return 0 ;
}
F_54 ( & V_107 ) ;
return - V_145 ;
case V_287 :
if ( F_165 ( & V_279 , V_11 , sizeof( V_279 ) ) )
return - V_263 ;
F_133 () ;
V_153 = F_106 ( V_4 , V_279 . V_288 . V_73 , V_279 . V_289 . V_73 ) ;
if ( V_153 ) {
V_279 . V_290 = V_153 -> V_159 . V_9 . V_214 ;
V_279 . V_291 = V_153 -> V_159 . V_9 . V_292 ;
V_279 . V_293 = V_153 -> V_159 . V_9 . V_293 ;
F_135 () ;
if ( F_171 ( V_11 , & V_279 , sizeof( V_279 ) ) )
return - V_263 ;
return 0 ;
}
F_135 () ;
return - V_145 ;
default:
return - V_294 ;
}
}
int F_173 ( struct V_215 * V_242 , unsigned int V_277 , void V_85 * V_11 )
{
struct V_295 V_279 ;
struct V_296 V_281 ;
struct V_143 * V_249 ;
struct V_152 * V_153 ;
struct V_2 * V_2 = F_154 ( V_242 ) ;
struct V_1 * V_4 ;
V_4 = F_1 ( V_2 , F_160 ( V_242 ) -> V_256 ? : V_46 ) ;
if ( ! V_4 )
return - V_235 ;
switch ( V_277 ) {
case V_282 :
if ( F_165 ( & V_281 , V_11 , sizeof( V_281 ) ) )
return - V_263 ;
if ( V_281 . V_139 >= V_4 -> V_144 )
return - V_28 ;
F_52 ( & V_107 ) ;
V_249 = & V_4 -> V_130 [ V_281 . V_139 ] ;
if ( F_73 ( V_4 , V_281 . V_139 ) ) {
V_281 . V_283 = V_249 -> V_198 ;
V_281 . V_284 = V_249 -> V_199 ;
V_281 . V_285 = V_249 -> V_196 ;
V_281 . V_286 = V_249 -> V_197 ;
F_54 ( & V_107 ) ;
if ( F_171 ( V_11 , & V_281 , sizeof( V_281 ) ) )
return - V_263 ;
return 0 ;
}
F_54 ( & V_107 ) ;
return - V_145 ;
case V_287 :
if ( F_165 ( & V_279 , V_11 , sizeof( V_279 ) ) )
return - V_263 ;
F_133 () ;
V_153 = F_106 ( V_4 , V_279 . V_288 . V_73 , V_279 . V_289 . V_73 ) ;
if ( V_153 ) {
V_279 . V_290 = V_153 -> V_159 . V_9 . V_214 ;
V_279 . V_291 = V_153 -> V_159 . V_9 . V_292 ;
V_279 . V_293 = V_153 -> V_159 . V_9 . V_293 ;
F_135 () ;
if ( F_171 ( V_11 , & V_279 , sizeof( V_279 ) ) )
return - V_263 ;
return 0 ;
}
F_135 () ;
return - V_145 ;
default:
return - V_294 ;
}
}
static int F_174 ( struct V_297 * V_298 , unsigned long V_299 , void * V_300 )
{
struct V_60 * V_61 = F_175 ( V_300 ) ;
struct V_2 * V_2 = F_35 ( V_61 ) ;
struct V_1 * V_4 ;
struct V_143 * V_63 ;
int V_301 ;
if ( V_299 != V_302 )
return V_303 ;
F_2 (mrt, net) {
V_63 = & V_4 -> V_130 [ 0 ] ;
for ( V_301 = 0 ; V_301 < V_4 -> V_144 ; V_301 ++ , V_63 ++ ) {
if ( V_63 -> V_61 == V_61 )
F_70 ( V_4 , V_301 , 1 , NULL ) ;
}
}
return V_303 ;
}
static void F_176 ( struct V_2 * V_2 , struct V_33 * V_34 ,
T_6 V_74 , T_6 V_71 )
{
struct V_117 * V_70 ;
const struct V_117 * V_304 = F_88 ( V_34 ) ;
F_124 ( V_34 , sizeof( struct V_117 ) ) ;
V_34 -> V_225 = V_34 -> V_132 ;
F_66 ( V_34 ) ;
V_70 = F_88 ( V_34 ) ;
V_70 -> V_76 = 4 ;
V_70 -> V_41 = V_304 -> V_41 ;
V_70 -> V_305 = V_304 -> V_305 ;
V_70 -> V_306 = 0 ;
V_70 -> V_71 = V_71 ;
V_70 -> V_74 = V_74 ;
V_70 -> V_78 = V_79 ;
V_70 -> V_77 = 5 ;
V_70 -> V_129 = F_67 ( V_34 -> V_110 ) ;
F_177 ( V_2 , V_34 , NULL ) ;
F_178 ( V_70 ) ;
memset ( & ( F_179 ( V_34 ) -> V_307 ) , 0 , sizeof( F_179 ( V_34 ) -> V_307 ) ) ;
F_180 ( V_34 ) ;
}
static inline int F_181 ( struct V_2 * V_2 , struct V_215 * V_242 ,
struct V_33 * V_34 )
{
struct V_308 * V_307 = & ( F_179 ( V_34 ) -> V_307 ) ;
F_182 ( V_2 , V_309 ) ;
F_183 ( V_2 , V_310 , V_34 -> V_110 ) ;
if ( F_184 ( V_307 -> V_247 ) )
F_185 ( V_34 ) ;
return F_186 ( V_2 , V_242 , V_34 ) ;
}
static void F_187 ( struct V_2 * V_2 , struct V_1 * V_4 ,
struct V_33 * V_34 , struct V_152 * V_153 , int V_139 )
{
const struct V_117 * V_70 = F_88 ( V_34 ) ;
struct V_143 * V_249 = & V_4 -> V_130 [ V_139 ] ;
struct V_60 * V_61 ;
struct V_311 * V_312 ;
struct V_5 V_99 ;
int V_128 = 0 ;
if ( ! V_249 -> V_61 )
goto V_313;
if ( V_249 -> V_13 & V_150 ) {
V_249 -> V_199 ++ ;
V_249 -> V_197 += V_34 -> V_110 ;
V_249 -> V_61 -> V_108 . V_109 += V_34 -> V_110 ;
V_249 -> V_61 -> V_108 . V_111 ++ ;
F_53 ( V_4 , V_34 , V_139 , V_112 ) ;
goto V_313;
}
if ( V_249 -> V_13 & V_149 ) {
V_312 = F_188 ( V_2 , & V_99 , NULL ,
V_249 -> V_192 , V_249 -> V_191 ,
0 , 0 ,
V_79 ,
F_189 ( V_70 -> V_41 ) , V_249 -> V_200 ) ;
if ( F_13 ( V_312 ) )
goto V_313;
V_128 = sizeof( struct V_117 ) ;
} else {
V_312 = F_188 ( V_2 , & V_99 , NULL , V_70 -> V_71 , 0 ,
0 , 0 ,
V_79 ,
F_189 ( V_70 -> V_41 ) , V_249 -> V_200 ) ;
if ( F_13 ( V_312 ) )
goto V_313;
}
V_61 = V_312 -> V_314 . V_61 ;
if ( V_34 -> V_110 + V_128 > F_190 ( & V_312 -> V_314 ) && ( F_64 ( V_70 -> V_306 ) & V_315 ) ) {
F_182 ( V_2 , V_316 ) ;
F_191 ( V_312 ) ;
goto V_313;
}
V_128 += F_192 ( V_61 ) + V_312 -> V_314 . V_317 ;
if ( F_193 ( V_34 , V_128 ) ) {
F_191 ( V_312 ) ;
goto V_313;
}
V_249 -> V_199 ++ ;
V_249 -> V_197 += V_34 -> V_110 ;
F_194 ( V_34 ) ;
F_130 ( V_34 , & V_312 -> V_314 ) ;
F_195 ( F_88 ( V_34 ) ) ;
if ( V_249 -> V_13 & V_149 ) {
F_176 ( V_2 , V_34 , V_249 -> V_191 , V_249 -> V_192 ) ;
V_249 -> V_61 -> V_108 . V_111 ++ ;
V_249 -> V_61 -> V_108 . V_109 += V_34 -> V_110 ;
}
F_179 ( V_34 ) -> V_13 |= V_318 ;
F_196 ( V_319 , V_320 ,
V_2 , NULL , V_34 , V_34 -> V_61 , V_61 ,
F_181 ) ;
return;
V_313:
F_51 ( V_34 ) ;
}
static int F_197 ( struct V_1 * V_4 , struct V_60 * V_61 )
{
int V_301 ;
for ( V_301 = V_4 -> V_144 - 1 ; V_301 >= 0 ; V_301 -- ) {
if ( V_4 -> V_130 [ V_301 ] . V_61 == V_61 )
break;
}
return V_301 ;
}
static void F_120 ( struct V_2 * V_2 , struct V_1 * V_4 ,
struct V_33 * V_34 , struct V_152 * V_178 ,
int V_191 )
{
int V_321 = - 1 ;
int V_249 , V_301 ;
int V_322 = F_197 ( V_4 , V_34 -> V_61 ) ;
V_249 = V_178 -> V_208 ;
V_178 -> V_159 . V_9 . V_214 ++ ;
V_178 -> V_159 . V_9 . V_292 += V_34 -> V_110 ;
if ( V_178 -> V_203 == F_110 ( V_205 ) && V_322 >= 0 ) {
struct V_152 * V_323 ;
V_323 = F_109 ( V_4 , V_249 ) ;
if ( V_323 &&
V_323 -> V_159 . V_9 . V_179 [ V_322 ] < 255 )
goto V_324;
}
if ( V_4 -> V_130 [ V_249 ] . V_61 != V_34 -> V_61 ) {
if ( F_198 ( F_199 ( V_34 ) ) ) {
goto V_325;
}
V_178 -> V_159 . V_9 . V_293 ++ ;
if ( V_322 >= 0 && V_4 -> V_269 &&
( V_4 -> V_272 ||
V_178 -> V_159 . V_9 . V_179 [ V_322 ] < 255 ) &&
F_97 ( V_173 ,
V_178 -> V_159 . V_9 . V_209 + V_210 ) ) {
V_178 -> V_159 . V_9 . V_209 = V_173 ;
F_53 ( V_4 , V_34 , V_322 , V_326 ) ;
}
goto V_325;
}
V_324:
V_4 -> V_130 [ V_249 ] . V_198 ++ ;
V_4 -> V_130 [ V_249 ] . V_196 += V_34 -> V_110 ;
if ( V_178 -> V_203 == F_110 ( V_205 ) &&
V_178 -> V_204 == F_110 ( V_205 ) ) {
if ( V_322 >= 0 &&
V_322 != V_178 -> V_208 &&
F_88 ( V_34 ) -> V_305 >
V_178 -> V_159 . V_9 . V_179 [ V_178 -> V_208 ] ) {
V_321 = V_178 -> V_208 ;
goto V_327;
}
goto V_325;
}
for ( V_301 = V_178 -> V_159 . V_9 . V_144 - 1 ;
V_301 >= V_178 -> V_159 . V_9 . V_180 ; V_301 -- ) {
if ( ( V_178 -> V_203 != F_110 ( V_205 ) ||
V_301 != V_322 ) &&
F_88 ( V_34 ) -> V_305 > V_178 -> V_159 . V_9 . V_179 [ V_301 ] ) {
if ( V_321 != - 1 ) {
struct V_33 * V_328 = F_200 ( V_34 , V_211 ) ;
if ( V_328 )
F_187 ( V_2 , V_4 , V_328 , V_178 ,
V_321 ) ;
}
V_321 = V_301 ;
}
}
V_327:
if ( V_321 != - 1 ) {
if ( V_191 ) {
struct V_33 * V_328 = F_200 ( V_34 , V_211 ) ;
if ( V_328 )
F_187 ( V_2 , V_4 , V_328 , V_178 , V_321 ) ;
} else {
F_187 ( V_2 , V_4 , V_34 , V_178 , V_321 ) ;
return;
}
}
V_325:
if ( ! V_191 )
F_51 ( V_34 ) ;
}
static struct V_1 * F_201 ( struct V_2 * V_2 , struct V_33 * V_34 )
{
struct V_311 * V_312 = F_199 ( V_34 ) ;
struct V_117 * V_70 = F_88 ( V_34 ) ;
struct V_5 V_99 = {
. V_71 = V_70 -> V_71 ,
. V_74 = V_70 -> V_74 ,
. V_329 = F_189 ( V_70 -> V_41 ) ,
. V_100 = ( F_198 ( V_312 ) ?
V_34 -> V_61 -> V_101 : 0 ) ,
. V_102 = ( F_198 ( V_312 ) ?
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
if ( F_179 ( V_34 ) -> V_13 & V_318 )
goto V_325;
V_4 = F_201 ( V_2 , V_34 ) ;
if ( F_13 ( V_4 ) ) {
F_51 ( V_34 ) ;
return F_14 ( V_4 ) ;
}
if ( ! V_191 ) {
if ( F_179 ( V_34 ) -> V_307 . V_332 ) {
if ( F_203 ( V_34 ) )
return 0 ;
} else if ( F_88 ( V_34 ) -> V_78 == V_254 ) {
struct V_215 * V_216 ;
V_216 = F_134 ( V_4 -> V_216 ) ;
if ( V_216 ) {
F_180 ( V_34 ) ;
F_204 ( V_216 , V_34 ) ;
return 0 ;
}
}
}
V_178 = F_106 ( V_4 , F_88 ( V_34 ) -> V_74 , F_88 ( V_34 ) -> V_71 ) ;
if ( ! V_178 ) {
int V_249 = F_197 ( V_4 , V_34 -> V_61 ) ;
if ( V_249 >= 0 )
V_178 = F_111 ( V_4 , F_88 ( V_34 ) -> V_71 ,
V_249 ) ;
}
if ( ! V_178 ) {
int V_249 ;
if ( V_191 ) {
struct V_33 * V_328 = F_200 ( V_34 , V_211 ) ;
F_205 ( V_34 ) ;
if ( ! V_328 )
return - V_186 ;
V_34 = V_328 ;
}
F_52 ( & V_107 ) ;
V_249 = F_197 ( V_4 , V_34 -> V_61 ) ;
if ( V_249 >= 0 ) {
int V_48 = F_138 ( V_4 , V_249 , V_34 ) ;
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
V_325:
if ( V_191 )
return F_205 ( V_34 ) ;
F_51 ( V_34 ) ;
return 0 ;
}
int F_206 ( struct V_33 * V_34 )
{
struct V_217 * V_334 ;
struct V_2 * V_2 = F_35 ( V_34 -> V_61 ) ;
struct V_1 * V_4 ;
if ( ! F_207 ( V_34 , sizeof( * V_334 ) + sizeof( struct V_117 ) ) )
goto V_335;
V_334 = F_208 ( V_34 ) ;
V_4 = F_201 ( V_2 , V_34 ) ;
if ( F_13 ( V_4 ) )
goto V_335;
if ( ! V_4 -> V_272 ||
V_334 -> V_336 != V_337 || V_334 -> V_224 != V_338 )
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
int V_301 ;
struct V_345 * V_346 ;
struct V_37 * V_347 ;
struct V_348 V_349 ;
if ( V_153 -> V_208 >= V_181 )
return - V_235 ;
if ( F_73 ( V_4 , V_153 -> V_208 ) &&
F_213 ( V_34 , V_350 , V_4 -> V_130 [ V_153 -> V_208 ] . V_61 -> V_101 ) < 0 )
return - V_213 ;
if ( ! ( V_347 = F_214 ( V_34 , V_351 ) ) )
return - V_213 ;
for ( V_301 = V_153 -> V_159 . V_9 . V_180 ; V_301 < V_153 -> V_159 . V_9 . V_144 ; V_301 ++ ) {
if ( F_73 ( V_4 , V_301 ) && V_153 -> V_159 . V_9 . V_179 [ V_301 ] < 255 ) {
if ( ! ( V_346 = F_215 ( V_34 , sizeof( * V_346 ) ) ) ) {
F_216 ( V_34 , V_347 ) ;
return - V_213 ;
}
V_346 -> V_352 = 0 ;
V_346 -> V_353 = V_153 -> V_159 . V_9 . V_179 [ V_301 ] ;
V_346 -> V_354 = V_4 -> V_130 [ V_301 ] . V_61 -> V_101 ;
V_346 -> V_355 = sizeof( * V_346 ) ;
}
}
F_217 ( V_34 , V_347 ) ;
V_349 . V_356 = V_153 -> V_159 . V_9 . V_214 ;
V_349 . V_357 = V_153 -> V_159 . V_9 . V_292 ;
V_349 . V_358 = V_153 -> V_159 . V_9 . V_293 ;
if ( F_218 ( V_34 , V_359 , sizeof( V_349 ) , & V_349 , V_360 ) < 0 )
return - V_213 ;
V_344 -> V_361 = V_362 ;
return 1 ;
}
int F_219 ( struct V_2 * V_2 , struct V_33 * V_34 ,
T_6 V_74 , T_6 V_71 ,
struct V_343 * V_344 , int V_363 )
{
struct V_152 * V_178 ;
struct V_1 * V_4 ;
int V_7 ;
V_4 = F_1 ( V_2 , V_46 ) ;
if ( ! V_4 )
return - V_235 ;
F_133 () ;
V_178 = F_106 ( V_4 , V_74 , V_71 ) ;
if ( ! V_178 && V_34 -> V_61 ) {
int V_249 = F_197 ( V_4 , V_34 -> V_61 ) ;
if ( V_249 >= 0 )
V_178 = F_111 ( V_4 , V_71 , V_249 ) ;
}
if ( ! V_178 ) {
struct V_33 * V_328 ;
struct V_117 * V_70 ;
struct V_60 * V_61 ;
int V_249 = - 1 ;
if ( V_363 ) {
F_135 () ;
return - V_31 ;
}
V_61 = V_34 -> V_61 ;
F_52 ( & V_107 ) ;
if ( V_61 )
V_249 = F_197 ( V_4 , V_61 ) ;
if ( V_249 < 0 ) {
F_54 ( & V_107 ) ;
F_135 () ;
return - V_333 ;
}
V_328 = F_200 ( V_34 , V_211 ) ;
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
V_7 = F_138 ( V_4 , V_249 , V_328 ) ;
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
T_1 V_169 , T_1 V_364 , struct V_152 * V_153 , int V_277 ,
int V_13 )
{
struct V_162 * V_163 ;
struct V_343 * V_344 ;
int V_7 ;
V_163 = F_221 ( V_34 , V_169 , V_364 , V_277 , sizeof( * V_344 ) , V_13 ) ;
if ( ! V_163 )
return - V_213 ;
V_344 = F_91 ( V_163 ) ;
V_344 -> V_365 = V_366 ;
V_344 -> V_367 = 32 ;
V_344 -> V_368 = 32 ;
V_344 -> V_369 = 0 ;
V_344 -> V_370 = V_4 -> V_3 ;
if ( F_213 ( V_34 , V_371 , V_4 -> V_3 ) )
goto V_372;
V_344 -> V_361 = V_362 ;
V_344 -> V_373 = V_374 ;
if ( V_153 -> V_239 & V_240 )
V_344 -> V_375 = V_376 ;
else
V_344 -> V_375 = V_377 ;
V_344 -> V_378 = 0 ;
if ( F_222 ( V_34 , V_379 , V_153 -> V_203 ) ||
F_222 ( V_34 , V_380 , V_153 -> V_204 ) )
goto V_372;
V_7 = F_118 ( V_4 , V_34 , V_153 , V_344 ) ;
if ( V_7 < 0 && V_7 != - V_235 )
goto V_372;
F_223 ( V_34 , V_163 ) ;
return 0 ;
V_372:
F_224 ( V_34 , V_163 ) ;
return - V_213 ;
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
+ F_229 ( sizeof( struct V_348 ) )
;
return V_110 ;
}
static void F_98 ( struct V_1 * V_4 , struct V_152 * V_231 ,
int V_277 )
{
struct V_2 * V_2 = F_85 ( & V_4 -> V_2 ) ;
struct V_33 * V_34 ;
int V_7 = - V_186 ;
V_34 = F_230 ( F_225 ( V_231 -> V_208 >= V_181 , V_4 -> V_144 ) ,
V_211 ) ;
if ( ! V_34 )
goto V_381;
V_7 = F_220 ( V_4 , V_34 , 0 , 0 , V_231 , V_277 , 0 ) ;
if ( V_7 < 0 )
goto V_381;
F_231 ( V_34 , V_2 , 0 , V_382 , NULL , V_211 ) ;
return;
V_381:
F_51 ( V_34 ) ;
if ( V_7 < 0 )
F_232 ( V_2 , V_382 , V_7 ) ;
}
static int F_233 ( struct V_33 * V_34 , struct V_383 * V_384 )
{
struct V_2 * V_2 = F_154 ( V_34 -> V_242 ) ;
struct V_1 * V_4 ;
struct V_152 * V_231 ;
unsigned int V_385 = 0 , V_386 ;
unsigned int V_387 = 0 , V_388 ;
unsigned int V_157 = 0 , V_389 ;
V_386 = V_384 -> args [ 0 ] ;
V_388 = V_384 -> args [ 1 ] ;
V_389 = V_384 -> args [ 2 ] ;
F_133 () ;
F_2 (mrt, net) {
if ( V_385 < V_386 )
goto V_390;
if ( V_385 > V_386 )
V_388 = 0 ;
for ( V_387 = V_388 ; V_387 < V_54 ; V_387 ++ ) {
F_108 (mfc, &mrt->mfc_cache_array[h], list) {
if ( V_157 < V_389 )
goto V_391;
if ( F_220 ( V_4 , V_34 ,
F_93 ( V_384 -> V_34 ) . V_169 ,
V_384 -> V_163 -> V_392 ,
V_231 , V_228 ,
V_393 ) < 0 )
goto V_394;
V_391:
V_157 ++ ;
}
V_157 = V_389 = 0 ;
}
F_139 ( & V_172 ) ;
F_140 (mfc, &mrt->mfc_unres_queue, list) {
if ( V_157 < V_389 )
goto V_395;
if ( F_220 ( V_4 , V_34 ,
F_93 ( V_384 -> V_34 ) . V_169 ,
V_384 -> V_163 -> V_392 ,
V_231 , V_228 ,
V_393 ) < 0 ) {
F_142 ( & V_172 ) ;
goto V_394;
}
V_395:
V_157 ++ ;
}
F_142 ( & V_172 ) ;
V_157 = V_389 = 0 ;
V_388 = 0 ;
V_390:
V_385 ++ ;
}
V_394:
F_135 () ;
V_384 -> args [ 2 ] = V_157 ;
V_384 -> args [ 1 ] = V_387 ;
V_384 -> args [ 0 ] = V_385 ;
return V_34 -> V_110 ;
}
static bool F_234 ( unsigned char V_375 )
{
switch ( V_375 ) {
case V_376 :
case V_377 :
return true ;
}
return false ;
}
static int F_235 ( const struct V_37 * V_396 , struct V_230 * V_397 )
{
struct V_345 * V_398 = F_236 ( V_396 ) ;
int V_399 = F_237 ( V_396 ) , V_139 = 0 ;
while ( F_238 ( V_398 , V_399 ) ) {
V_397 -> V_238 [ V_139 ] = V_398 -> V_353 ;
if ( ++ V_139 == V_181 )
break;
V_398 = F_239 ( V_398 , & V_399 ) ;
}
return V_399 > 0 ? - V_28 : V_139 ;
}
static int F_240 ( struct V_2 * V_2 , struct V_162 * V_163 ,
struct V_230 * V_397 , int * V_183 ,
struct V_1 * * V_400 )
{
struct V_60 * V_61 = NULL ;
T_1 V_401 = V_46 ;
struct V_1 * V_4 ;
struct V_37 * V_402 ;
struct V_343 * V_344 ;
int V_220 , V_403 ;
V_220 = F_241 ( V_163 , sizeof( * V_344 ) , V_404 , V_405 ) ;
if ( V_220 < 0 )
goto V_175;
V_344 = F_91 ( V_163 ) ;
V_220 = - V_28 ;
if ( V_344 -> V_365 != V_366 || V_344 -> V_367 != 32 ||
V_344 -> V_361 != V_362 ||
V_344 -> V_373 != V_374 ||
! F_234 ( V_344 -> V_375 ) )
goto V_175;
memset ( V_397 , 0 , sizeof( * V_397 ) ) ;
V_397 -> V_236 = - 1 ;
V_220 = 0 ;
F_242 (attr, nlh, sizeof(struct rtmsg), rem) {
switch ( F_243 ( V_402 ) ) {
case V_379 :
V_397 -> V_234 . V_73 = F_244 ( V_402 ) ;
break;
case V_380 :
V_397 -> V_233 . V_73 = F_244 ( V_402 ) ;
break;
case V_350 :
V_61 = F_245 ( V_2 , F_246 ( V_402 ) ) ;
if ( ! V_61 ) {
V_220 = - V_333 ;
goto V_175;
}
break;
case V_351 :
if ( F_235 ( V_402 , V_397 ) < 0 ) {
V_220 = - V_28 ;
goto V_175;
}
break;
case V_406 :
V_220 = 1 ;
break;
case V_371 :
V_401 = F_246 ( V_402 ) ;
break;
}
}
V_4 = F_1 ( V_2 , V_401 ) ;
if ( ! V_4 ) {
V_220 = - V_235 ;
goto V_175;
}
* V_400 = V_4 ;
* V_183 = V_344 -> V_375 == V_377 ? 1 : 0 ;
if ( V_61 )
V_397 -> V_236 = F_197 ( V_4 , V_61 ) ;
V_175:
return V_220 ;
}
static int F_247 ( struct V_33 * V_34 , struct V_162 * V_163 )
{
struct V_2 * V_2 = F_154 ( V_34 -> V_242 ) ;
int V_220 , V_183 , V_232 ;
struct V_1 * V_407 ;
struct V_230 V_397 ;
V_183 = 0 ;
V_407 = NULL ;
V_220 = F_240 ( V_2 , V_163 , & V_397 , & V_183 , & V_407 ) ;
if ( V_220 < 0 )
return V_220 ;
V_232 = V_220 ? V_397 . V_236 : - 1 ;
if ( V_163 -> V_164 == V_228 )
return F_148 ( V_2 , V_407 , & V_397 , V_183 , V_232 ) ;
else
return F_146 ( V_407 , & V_397 , V_232 ) ;
}
static struct V_143 * F_248 ( struct V_2 * V_2 ,
struct V_408 * V_409 ,
T_9 V_410 )
{
struct V_1 * V_4 = V_409 -> V_4 ;
for ( V_409 -> V_301 = 0 ; V_409 -> V_301 < V_4 -> V_144 ; ++ V_409 -> V_301 ) {
if ( ! F_73 ( V_4 , V_409 -> V_301 ) )
continue;
if ( V_410 -- == 0 )
return & V_4 -> V_130 [ V_409 -> V_301 ] ;
}
return NULL ;
}
static void * F_249 ( struct V_411 * V_364 , T_9 * V_410 )
__acquires( V_107 )
{
struct V_408 * V_409 = V_364 -> V_412 ;
struct V_2 * V_2 = F_250 ( V_364 ) ;
struct V_1 * V_4 ;
V_4 = F_1 ( V_2 , V_46 ) ;
if ( ! V_4 )
return F_25 ( - V_235 ) ;
V_409 -> V_4 = V_4 ;
F_52 ( & V_107 ) ;
return * V_410 ? F_248 ( V_2 , V_364 -> V_412 , * V_410 - 1 )
: V_413 ;
}
static void * F_251 ( struct V_411 * V_364 , void * V_63 , T_9 * V_410 )
{
struct V_408 * V_409 = V_364 -> V_412 ;
struct V_2 * V_2 = F_250 ( V_364 ) ;
struct V_1 * V_4 = V_409 -> V_4 ;
++ * V_410 ;
if ( V_63 == V_413 )
return F_248 ( V_2 , V_409 , 0 ) ;
while ( ++ V_409 -> V_301 < V_4 -> V_144 ) {
if ( ! F_73 ( V_4 , V_409 -> V_301 ) )
continue;
return & V_4 -> V_130 [ V_409 -> V_301 ] ;
}
return NULL ;
}
static void F_252 ( struct V_411 * V_364 , void * V_63 )
__releases( V_107 )
{
F_54 ( & V_107 ) ;
}
static int F_253 ( struct V_411 * V_364 , void * V_63 )
{
struct V_408 * V_409 = V_364 -> V_412 ;
struct V_1 * V_4 = V_409 -> V_4 ;
if ( V_63 == V_413 ) {
F_254 ( V_364 ,
L_6 ) ;
} else {
const struct V_143 * V_249 = V_63 ;
const char * V_80 = V_249 -> V_61 ? V_249 -> V_61 -> V_80 : L_7 ;
F_255 ( V_364 ,
L_8 ,
V_249 - V_4 -> V_130 ,
V_80 , V_249 -> V_196 , V_249 -> V_198 ,
V_249 -> V_197 , V_249 -> V_199 ,
V_249 -> V_13 , V_249 -> V_191 , V_249 -> V_192 ) ;
}
return 0 ;
}
static int F_256 ( struct V_414 * V_414 , struct V_415 * V_415 )
{
return F_257 ( V_414 , V_415 , & V_416 ,
sizeof( struct V_408 ) ) ;
}
static struct V_152 * F_258 ( struct V_2 * V_2 ,
struct V_417 * V_418 , T_9 V_410 )
{
struct V_1 * V_4 = V_418 -> V_4 ;
struct V_152 * V_231 ;
F_133 () ;
for ( V_418 -> V_301 = 0 ; V_418 -> V_301 < V_54 ; V_418 -> V_301 ++ ) {
V_418 -> V_178 = & V_4 -> V_55 [ V_418 -> V_301 ] ;
F_108 (mfc, it->cache, list)
if ( V_410 -- == 0 )
return V_231 ;
}
F_135 () ;
F_139 ( & V_172 ) ;
V_418 -> V_178 = & V_4 -> V_56 ;
F_140 (mfc, it->cache, list)
if ( V_410 -- == 0 )
return V_231 ;
F_142 ( & V_172 ) ;
V_418 -> V_178 = NULL ;
return NULL ;
}
static void * F_259 ( struct V_411 * V_364 , T_9 * V_410 )
{
struct V_417 * V_418 = V_364 -> V_412 ;
struct V_2 * V_2 = F_250 ( V_364 ) ;
struct V_1 * V_4 ;
V_4 = F_1 ( V_2 , V_46 ) ;
if ( ! V_4 )
return F_25 ( - V_235 ) ;
V_418 -> V_4 = V_4 ;
V_418 -> V_178 = NULL ;
V_418 -> V_301 = 0 ;
return * V_410 ? F_258 ( V_2 , V_364 -> V_412 , * V_410 - 1 )
: V_413 ;
}
static void * F_260 ( struct V_411 * V_364 , void * V_63 , T_9 * V_410 )
{
struct V_152 * V_231 = V_63 ;
struct V_417 * V_418 = V_364 -> V_412 ;
struct V_2 * V_2 = F_250 ( V_364 ) ;
struct V_1 * V_4 = V_418 -> V_4 ;
++ * V_410 ;
if ( V_63 == V_413 )
return F_258 ( V_2 , V_364 -> V_412 , 0 ) ;
if ( V_231 -> V_50 . V_49 != V_418 -> V_178 )
return F_261 ( V_231 -> V_50 . V_49 , struct V_152 , V_50 ) ;
if ( V_418 -> V_178 == & V_4 -> V_56 )
goto V_419;
F_262 ( V_418 -> V_178 != & V_4 -> V_55 [ V_418 -> V_301 ] ) ;
while ( ++ V_418 -> V_301 < V_54 ) {
V_418 -> V_178 = & V_4 -> V_55 [ V_418 -> V_301 ] ;
if ( F_96 ( V_418 -> V_178 ) )
continue;
return F_263 ( V_418 -> V_178 , struct V_152 , V_50 ) ;
}
F_135 () ;
V_418 -> V_178 = & V_4 -> V_56 ;
V_418 -> V_301 = 0 ;
F_139 ( & V_172 ) ;
if ( ! F_96 ( V_418 -> V_178 ) )
return F_263 ( V_418 -> V_178 , struct V_152 , V_50 ) ;
V_419:
F_142 ( & V_172 ) ;
V_418 -> V_178 = NULL ;
return NULL ;
}
static void F_264 ( struct V_411 * V_364 , void * V_63 )
{
struct V_417 * V_418 = V_364 -> V_412 ;
struct V_1 * V_4 = V_418 -> V_4 ;
if ( V_418 -> V_178 == & V_4 -> V_56 )
F_142 ( & V_172 ) ;
else if ( V_418 -> V_178 == & V_4 -> V_55 [ V_418 -> V_301 ] )
F_135 () ;
}
static int F_265 ( struct V_411 * V_364 , void * V_63 )
{
int V_420 ;
if ( V_63 == V_413 ) {
F_254 ( V_364 ,
L_9 ) ;
} else {
const struct V_152 * V_231 = V_63 ;
const struct V_417 * V_418 = V_364 -> V_412 ;
const struct V_1 * V_4 = V_418 -> V_4 ;
F_255 ( V_364 , L_10 ,
( V_84 T_1 ) V_231 -> V_204 ,
( V_84 T_1 ) V_231 -> V_203 ,
V_231 -> V_208 ) ;
if ( V_418 -> V_178 != & V_4 -> V_56 ) {
F_255 ( V_364 , L_11 ,
V_231 -> V_159 . V_9 . V_214 ,
V_231 -> V_159 . V_9 . V_292 ,
V_231 -> V_159 . V_9 . V_293 ) ;
for ( V_420 = V_231 -> V_159 . V_9 . V_180 ;
V_420 < V_231 -> V_159 . V_9 . V_144 ; V_420 ++ ) {
if ( F_73 ( V_4 , V_420 ) &&
V_231 -> V_159 . V_9 . V_179 [ V_420 ] < 255 )
F_255 ( V_364 ,
L_12 ,
V_420 , V_231 -> V_159 . V_9 . V_179 [ V_420 ] ) ;
}
} else {
F_255 ( V_364 , L_11 , 0ul , 0ul , 0ul ) ;
}
F_266 ( V_364 , '\n' ) ;
}
return 0 ;
}
static int F_267 ( struct V_414 * V_414 , struct V_415 * V_415 )
{
return F_257 ( V_414 , V_415 , & V_421 ,
sizeof( struct V_417 ) ) ;
}
static int T_2 F_268 ( struct V_2 * V_2 )
{
int V_7 ;
V_7 = F_11 ( V_2 ) ;
if ( V_7 < 0 )
goto V_422;
#ifdef F_269
V_7 = - V_53 ;
if ( ! F_270 ( L_13 , 0 , V_2 -> V_423 , & V_424 ) )
goto V_425;
if ( ! F_270 ( L_14 , 0 , V_2 -> V_423 , & V_426 ) )
goto V_427;
#endif
return 0 ;
#ifdef F_269
V_427:
F_271 ( L_13 , V_2 -> V_423 ) ;
V_425:
F_20 ( V_2 ) ;
#endif
V_422:
return V_7 ;
}
static void T_3 F_272 ( struct V_2 * V_2 )
{
#ifdef F_269
F_271 ( L_14 , V_2 -> V_423 ) ;
F_271 ( L_13 , V_2 -> V_423 ) ;
#endif
F_20 ( V_2 ) ;
}
int T_10 F_273 ( void )
{
int V_7 ;
V_155 = F_274 ( L_15 ,
sizeof( struct V_152 ) ,
0 , V_428 | V_429 ,
NULL ) ;
V_7 = F_275 ( & V_430 ) ;
if ( V_7 )
goto V_431;
V_7 = F_276 ( & V_432 ) ;
if ( V_7 )
goto V_433;
#ifdef F_277
if ( F_278 ( & V_434 , V_435 ) < 0 ) {
F_279 ( L_16 , V_436 ) ;
V_7 = - V_31 ;
goto V_437;
}
#endif
F_280 ( V_366 , V_438 ,
NULL , F_233 , NULL ) ;
F_280 ( V_366 , V_228 ,
F_247 , NULL , NULL ) ;
F_280 ( V_366 , V_177 ,
F_247 , NULL , NULL ) ;
return 0 ;
#ifdef F_277
V_437:
F_281 ( & V_432 ) ;
#endif
V_433:
F_282 ( & V_430 ) ;
V_431:
F_283 ( V_155 ) ;
return V_7 ;
}
