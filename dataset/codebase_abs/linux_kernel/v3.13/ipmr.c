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
if ( V_4 == NULL )
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
if ( V_4 == NULL ) {
V_7 = - V_47 ;
goto V_48;
}
V_7 = F_17 ( V_43 , 0x7fff , V_46 , 0 ) ;
if ( V_7 < 0 )
goto V_49;
V_2 -> V_15 . V_16 = V_43 ;
return 0 ;
V_49:
F_18 ( V_4 ) ;
V_48:
F_19 ( V_43 ) ;
return V_7 ;
}
static void T_3 F_20 ( struct V_2 * V_2 )
{
struct V_1 * V_4 , * V_50 ;
F_21 (mrt, next, &net->ipv4.mr_tables, list) {
F_22 ( & V_4 -> V_51 ) ;
F_23 ( V_4 ) ;
}
F_19 ( V_2 -> V_15 . V_16 ) ;
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
V_2 -> V_15 . V_4 = F_16 ( V_2 , V_46 ) ;
return V_2 -> V_15 . V_4 ? 0 : - V_47 ;
}
static void T_3 F_20 ( struct V_2 * V_2 )
{
F_23 ( V_2 -> V_15 . V_4 ) ;
}
static struct V_1 * F_16 ( struct V_2 * V_2 , T_1 V_3 )
{
struct V_1 * V_4 ;
unsigned int V_52 ;
V_4 = F_1 ( V_2 , V_3 ) ;
if ( V_4 != NULL )
return V_4 ;
V_4 = F_24 ( sizeof( * V_4 ) , V_53 ) ;
if ( V_4 == NULL )
return NULL ;
F_25 ( & V_4 -> V_2 , V_2 ) ;
V_4 -> V_3 = V_3 ;
for ( V_52 = 0 ; V_52 < V_54 ; V_52 ++ )
F_15 ( & V_4 -> V_55 [ V_52 ] ) ;
F_15 ( & V_4 -> V_56 ) ;
F_26 ( & V_4 -> V_57 , V_58 ,
( unsigned long ) V_4 ) ;
#ifdef F_27
V_4 -> V_59 = - 1 ;
#endif
#ifdef F_28
F_29 ( & V_4 -> V_51 , & V_2 -> V_15 . V_45 ) ;
#endif
return V_4 ;
}
static void F_23 ( struct V_1 * V_4 )
{
F_30 ( & V_4 -> V_57 ) ;
F_31 ( V_4 ) ;
F_18 ( V_4 ) ;
}
static void F_32 ( struct V_60 * V_61 , struct V_62 * V_63 )
{
struct V_2 * V_2 = F_33 ( V_61 ) ;
F_34 ( V_61 ) ;
V_61 = F_35 ( V_2 , L_1 ) ;
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
T_4 V_87 = F_36 () ;
F_37 ( V_88 ) ;
V_43 -> V_86 ( V_61 , & V_67 , V_89 ) ;
F_37 ( V_87 ) ;
}
}
}
static
struct V_60 * F_38 ( struct V_2 * V_2 , struct V_62 * V_63 )
{
struct V_60 * V_61 ;
V_61 = F_35 ( V_2 , L_1 ) ;
if ( V_61 ) {
const struct V_64 * V_43 = V_61 -> V_65 ;
int V_7 ;
struct V_66 V_67 ;
struct V_68 V_69 ;
struct V_90 * V_91 ;
memset ( & V_69 , 0 , sizeof( V_69 ) ) ;
V_69 . V_70 . V_71 = V_63 -> V_72 . V_73 ;
V_69 . V_70 . V_74 = V_63 -> V_75 . V_73 ;
V_69 . V_70 . V_76 = 4 ;
V_69 . V_70 . V_77 = 5 ;
V_69 . V_70 . V_78 = V_79 ;
sprintf ( V_69 . V_80 , L_2 , V_63 -> V_81 ) ;
V_67 . V_82 . V_83 = ( V_84 void V_85 * ) & V_69 ;
if ( V_43 -> V_86 ) {
T_4 V_87 = F_36 () ;
F_37 ( V_88 ) ;
V_7 = V_43 -> V_86 ( V_61 , & V_67 , V_92 ) ;
F_37 ( V_87 ) ;
} else {
V_7 = - V_93 ;
}
V_61 = NULL ;
if ( V_7 == 0 &&
( V_61 = F_35 ( V_2 , V_69 . V_80 ) ) != NULL ) {
V_61 -> V_13 |= V_94 ;
V_91 = F_39 ( V_61 ) ;
if ( V_91 == NULL )
goto V_95;
F_40 ( V_91 ) ;
F_41 ( V_91 -> V_96 , V_97 ) = 0 ;
if ( F_42 ( V_61 ) )
goto V_95;
F_43 ( V_61 ) ;
}
}
return V_61 ;
V_95:
F_44 () ;
F_45 () ;
F_46 ( V_61 ) ;
return NULL ;
}
static T_5 F_47 ( struct V_33 * V_34 , struct V_60 * V_61 )
{
struct V_2 * V_2 = F_33 ( V_61 ) ;
struct V_1 * V_4 ;
struct V_5 V_98 = {
. V_99 = V_61 -> V_100 ,
. V_101 = V_34 -> V_102 ,
. V_103 = V_34 -> V_104 ,
} ;
int V_7 ;
V_7 = F_3 ( V_2 , & V_98 , & V_4 ) ;
if ( V_7 < 0 ) {
F_48 ( V_34 ) ;
return V_7 ;
}
F_49 ( & V_105 ) ;
V_61 -> V_106 . V_107 += V_34 -> V_108 ;
V_61 -> V_106 . V_109 ++ ;
F_50 ( V_4 , V_34 , V_4 -> V_59 , V_110 ) ;
F_51 ( & V_105 ) ;
F_48 ( V_34 ) ;
return V_111 ;
}
static void F_52 ( struct V_60 * V_61 )
{
V_61 -> type = V_112 ;
V_61 -> V_113 = V_114 - sizeof( struct V_115 ) - 8 ;
V_61 -> V_13 = V_116 ;
V_61 -> V_65 = & V_117 ,
V_61 -> V_118 = V_119 ;
V_61 -> V_120 |= V_121 ;
}
static struct V_60 * F_53 ( struct V_2 * V_2 , struct V_1 * V_4 )
{
struct V_60 * V_61 ;
struct V_90 * V_91 ;
char V_80 [ V_122 ] ;
if ( V_4 -> V_3 == V_46 )
sprintf ( V_80 , L_3 ) ;
else
sprintf ( V_80 , L_4 , V_4 -> V_3 ) ;
V_61 = F_54 ( 0 , V_80 , F_52 ) ;
if ( V_61 == NULL )
return NULL ;
F_55 ( V_61 , V_2 ) ;
if ( F_56 ( V_61 ) ) {
V_119 ( V_61 ) ;
return NULL ;
}
V_61 -> V_123 = 0 ;
F_57 () ;
V_91 = F_58 ( V_61 ) ;
if ( ! V_91 ) {
F_59 () ;
goto V_95;
}
F_40 ( V_91 ) ;
F_41 ( V_91 -> V_96 , V_97 ) = 0 ;
F_59 () ;
if ( F_42 ( V_61 ) )
goto V_95;
F_43 ( V_61 ) ;
return V_61 ;
V_95:
F_44 () ;
F_45 () ;
F_46 ( V_61 ) ;
return NULL ;
}
static int F_60 ( struct V_1 * V_4 , int V_124 , int V_125 ,
struct V_126 * V_127 )
{
struct V_128 * V_63 ;
struct V_60 * V_61 ;
struct V_90 * V_91 ;
if ( V_124 < 0 || V_124 >= V_4 -> V_129 )
return - V_130 ;
V_63 = & V_4 -> V_131 [ V_124 ] ;
F_61 ( & V_105 ) ;
V_61 = V_63 -> V_61 ;
V_63 -> V_61 = NULL ;
if ( ! V_61 ) {
F_62 ( & V_105 ) ;
return - V_130 ;
}
#ifdef F_27
if ( V_124 == V_4 -> V_59 )
V_4 -> V_59 = - 1 ;
#endif
if ( V_124 + 1 == V_4 -> V_129 ) {
int V_132 ;
for ( V_132 = V_124 - 1 ; V_132 >= 0 ; V_132 -- ) {
if ( F_63 ( V_4 , V_132 ) )
break;
}
V_4 -> V_129 = V_132 + 1 ;
}
F_62 ( & V_105 ) ;
F_64 ( V_61 , - 1 ) ;
V_91 = F_39 ( V_61 ) ;
if ( V_91 ) {
F_41 ( V_91 -> V_96 , V_133 ) -- ;
F_65 ( F_33 ( V_61 ) ,
V_134 ,
V_61 -> V_100 , & V_91 -> V_96 ) ;
F_66 ( V_91 ) ;
}
if ( V_63 -> V_13 & ( V_135 | V_136 ) && ! V_125 )
F_67 ( V_61 , V_127 ) ;
F_68 ( V_61 ) ;
return 0 ;
}
static void F_69 ( struct V_137 * V_127 )
{
struct V_138 * V_139 = F_70 ( V_127 , struct V_138 , V_140 ) ;
F_71 ( V_141 , V_139 ) ;
}
static inline void F_72 ( struct V_138 * V_139 )
{
F_73 ( & V_139 -> V_140 , F_69 ) ;
}
static void F_74 ( struct V_1 * V_4 , struct V_138 * V_139 )
{
struct V_2 * V_2 = F_75 ( & V_4 -> V_2 ) ;
struct V_33 * V_34 ;
struct V_142 * V_143 ;
F_76 ( & V_4 -> V_144 ) ;
while ( ( V_34 = F_77 ( & V_139 -> V_145 . V_146 . V_147 ) ) ) {
if ( F_78 ( V_34 ) -> V_76 == 0 ) {
struct V_148 * V_149 = (struct V_148 * ) F_79 ( V_34 , sizeof( struct V_115 ) ) ;
V_149 -> V_150 = V_151 ;
V_149 -> V_152 = F_80 ( sizeof( struct V_142 ) ) ;
F_81 ( V_34 , V_149 -> V_152 ) ;
V_143 = F_82 ( V_149 ) ;
V_143 -> error = - V_153 ;
memset ( & V_143 -> V_154 , 0 , sizeof( V_143 -> V_154 ) ) ;
F_83 ( V_34 , V_2 , F_84 ( V_34 ) . V_155 ) ;
} else {
F_48 ( V_34 ) ;
}
}
F_72 ( V_139 ) ;
}
static void V_58 ( unsigned long V_11 )
{
struct V_1 * V_4 = (struct V_1 * ) V_11 ;
unsigned long V_156 ;
unsigned long V_157 ;
struct V_138 * V_139 , * V_50 ;
if ( ! F_85 ( & V_158 ) ) {
F_86 ( & V_4 -> V_57 , V_159 + V_160 / 10 ) ;
return;
}
if ( F_87 ( & V_4 -> V_56 ) )
goto V_161;
V_156 = V_159 ;
V_157 = 10 * V_160 ;
F_21 (c, next, &mrt->mfc_unres_queue, list) {
if ( F_88 ( V_139 -> V_145 . V_146 . V_157 , V_156 ) ) {
unsigned long V_162 = V_139 -> V_145 . V_146 . V_157 - V_156 ;
if ( V_162 < V_157 )
V_157 = V_162 ;
continue;
}
F_22 ( & V_139 -> V_51 ) ;
F_89 ( V_4 , V_139 , V_163 ) ;
F_74 ( V_4 , V_139 ) ;
}
if ( ! F_87 ( & V_4 -> V_56 ) )
F_86 ( & V_4 -> V_57 , V_159 + V_157 ) ;
V_161:
F_90 ( & V_158 ) ;
}
static void F_91 ( struct V_1 * V_4 , struct V_138 * V_164 ,
unsigned char * V_165 )
{
int V_124 ;
V_164 -> V_145 . V_9 . V_166 = V_167 ;
V_164 -> V_145 . V_9 . V_129 = 0 ;
memset ( V_164 -> V_145 . V_9 . V_165 , 255 , V_167 ) ;
for ( V_124 = 0 ; V_124 < V_4 -> V_129 ; V_124 ++ ) {
if ( F_63 ( V_4 , V_124 ) &&
V_165 [ V_124 ] && V_165 [ V_124 ] < 255 ) {
V_164 -> V_145 . V_9 . V_165 [ V_124 ] = V_165 [ V_124 ] ;
if ( V_164 -> V_145 . V_9 . V_166 > V_124 )
V_164 -> V_145 . V_9 . V_166 = V_124 ;
if ( V_164 -> V_145 . V_9 . V_129 <= V_124 )
V_164 -> V_145 . V_9 . V_129 = V_124 + 1 ;
}
}
}
static int F_92 ( struct V_2 * V_2 , struct V_1 * V_4 ,
struct V_62 * V_168 , int V_169 )
{
int V_124 = V_168 -> V_81 ;
struct V_128 * V_63 = & V_4 -> V_131 [ V_124 ] ;
struct V_60 * V_61 ;
struct V_90 * V_91 ;
int V_7 ;
if ( F_63 ( V_4 , V_124 ) )
return - V_170 ;
switch ( V_168 -> V_171 ) {
#ifdef F_27
case V_136 :
if ( V_4 -> V_59 >= 0 )
return - V_170 ;
V_61 = F_53 ( V_2 , V_4 ) ;
if ( ! V_61 )
return - V_172 ;
V_7 = F_64 ( V_61 , 1 ) ;
if ( V_7 ) {
F_46 ( V_61 ) ;
F_68 ( V_61 ) ;
return V_7 ;
}
break;
#endif
case V_135 :
V_61 = F_38 ( V_2 , V_168 ) ;
if ( ! V_61 )
return - V_172 ;
V_7 = F_64 ( V_61 , 1 ) ;
if ( V_7 ) {
F_32 ( V_61 , V_168 ) ;
F_68 ( V_61 ) ;
return V_7 ;
}
break;
case V_173 :
case 0 :
if ( V_168 -> V_171 == V_173 ) {
V_61 = F_93 ( V_2 , V_168 -> V_174 ) ;
if ( V_61 && F_39 ( V_61 ) == NULL ) {
F_68 ( V_61 ) ;
return - V_130 ;
}
} else {
V_61 = F_94 ( V_2 , V_168 -> V_75 . V_73 ) ;
}
if ( ! V_61 )
return - V_130 ;
V_7 = F_64 ( V_61 , 1 ) ;
if ( V_7 ) {
F_68 ( V_61 ) ;
return V_7 ;
}
break;
default:
return - V_28 ;
}
V_91 = F_39 ( V_61 ) ;
if ( ! V_91 ) {
F_68 ( V_61 ) ;
return - V_130 ;
}
F_41 ( V_91 -> V_96 , V_133 ) ++ ;
F_65 ( V_2 , V_134 , V_61 -> V_100 ,
& V_91 -> V_96 ) ;
F_66 ( V_91 ) ;
V_63 -> V_175 = V_168 -> V_176 ;
V_63 -> V_177 = V_168 -> V_75 . V_73 ;
V_63 -> V_178 = V_168 -> V_72 . V_73 ;
V_63 -> V_13 = V_168 -> V_171 ;
if ( ! V_169 )
V_63 -> V_13 |= V_179 ;
V_63 -> V_180 = V_168 -> V_181 ;
V_63 -> V_182 = 0 ;
V_63 -> V_183 = 0 ;
V_63 -> V_184 = 0 ;
V_63 -> V_185 = 0 ;
V_63 -> V_186 = V_61 -> V_100 ;
if ( V_63 -> V_13 & ( V_135 | V_136 ) )
V_63 -> V_186 = V_61 -> V_123 ;
F_61 ( & V_105 ) ;
V_63 -> V_61 = V_61 ;
#ifdef F_27
if ( V_63 -> V_13 & V_136 )
V_4 -> V_59 = V_124 ;
#endif
if ( V_124 + 1 > V_4 -> V_129 )
V_4 -> V_129 = V_124 + 1 ;
F_62 ( & V_105 ) ;
return 0 ;
}
static struct V_138 * F_95 ( struct V_1 * V_4 ,
T_6 V_187 ,
T_6 V_188 )
{
int line = F_96 ( V_188 , V_187 ) ;
struct V_138 * V_139 ;
F_97 (c, &mrt->mfc_cache_array[line], list) {
if ( V_139 -> V_189 == V_187 && V_139 -> V_190 == V_188 )
return V_139 ;
}
return NULL ;
}
static struct V_138 * F_98 ( struct V_1 * V_4 ,
int V_124 )
{
int line = F_96 ( F_99 ( V_191 ) , F_99 ( V_191 ) ) ;
struct V_138 * V_139 ;
F_97 (c, &mrt->mfc_cache_array[line], list)
if ( V_139 -> V_189 == F_99 ( V_191 ) &&
V_139 -> V_190 == F_99 ( V_191 ) &&
V_139 -> V_145 . V_9 . V_165 [ V_124 ] < 255 )
return V_139 ;
return NULL ;
}
static struct V_138 * F_100 ( struct V_1 * V_4 ,
T_6 V_188 , int V_124 )
{
int line = F_96 ( V_188 , F_99 ( V_191 ) ) ;
struct V_138 * V_139 , * V_192 ;
if ( V_188 == F_99 ( V_191 ) )
goto V_193;
F_97 (c, &mrt->mfc_cache_array[line], list)
if ( V_139 -> V_189 == F_99 ( V_191 ) &&
V_139 -> V_190 == V_188 ) {
if ( V_139 -> V_145 . V_9 . V_165 [ V_124 ] < 255 )
return V_139 ;
V_192 = F_98 ( V_4 ,
V_139 -> V_194 ) ;
if ( V_192 && V_192 -> V_145 . V_9 . V_165 [ V_124 ] < 255 )
return V_139 ;
}
V_193:
return F_98 ( V_4 , V_124 ) ;
}
static struct V_138 * F_101 ( void )
{
struct V_138 * V_139 = F_102 ( V_141 , V_53 ) ;
if ( V_139 )
V_139 -> V_145 . V_9 . V_166 = V_167 ;
return V_139 ;
}
static struct V_138 * F_103 ( void )
{
struct V_138 * V_139 = F_102 ( V_141 , V_195 ) ;
if ( V_139 ) {
F_104 ( & V_139 -> V_145 . V_146 . V_147 ) ;
V_139 -> V_145 . V_146 . V_157 = V_159 + 10 * V_160 ;
}
return V_139 ;
}
static void F_105 ( struct V_2 * V_2 , struct V_1 * V_4 ,
struct V_138 * V_196 , struct V_138 * V_139 )
{
struct V_33 * V_34 ;
struct V_142 * V_143 ;
while ( ( V_34 = F_106 ( & V_196 -> V_145 . V_146 . V_147 ) ) ) {
if ( F_78 ( V_34 ) -> V_76 == 0 ) {
struct V_148 * V_149 = (struct V_148 * ) F_79 ( V_34 , sizeof( struct V_115 ) ) ;
if ( F_107 ( V_4 , V_34 , V_139 , F_82 ( V_149 ) ) > 0 ) {
V_149 -> V_152 = F_108 ( V_34 ) -
( V_197 * ) V_149 ;
} else {
V_149 -> V_150 = V_151 ;
V_149 -> V_152 = F_80 ( sizeof( struct V_142 ) ) ;
F_81 ( V_34 , V_149 -> V_152 ) ;
V_143 = F_82 ( V_149 ) ;
V_143 -> error = - V_198 ;
memset ( & V_143 -> V_154 , 0 , sizeof( V_143 -> V_154 ) ) ;
}
F_83 ( V_34 , V_2 , F_84 ( V_34 ) . V_155 ) ;
} else {
F_109 ( V_2 , V_4 , V_34 , V_139 , 0 ) ;
}
}
}
static int F_50 ( struct V_1 * V_4 ,
struct V_33 * V_199 , T_7 V_124 , int assert )
{
struct V_33 * V_34 ;
const int V_77 = F_110 ( V_199 ) ;
struct V_200 * V_201 ;
struct V_202 * V_154 ;
struct V_203 * V_204 ;
int V_205 ;
#ifdef F_27
if ( assert == V_110 )
V_34 = F_111 ( V_199 , sizeof( struct V_115 ) ) ;
else
#endif
V_34 = F_112 ( 128 , V_195 ) ;
if ( ! V_34 )
return - V_172 ;
#ifdef F_27
if ( assert == V_110 ) {
F_113 ( V_34 , sizeof( struct V_115 ) ) ;
F_114 ( V_34 ) ;
F_115 ( V_34 ) ;
V_154 = (struct V_202 * ) F_116 ( V_34 ) ;
memcpy ( V_154 , F_116 ( V_199 ) , sizeof( struct V_115 ) ) ;
V_154 -> V_206 = V_110 ;
V_154 -> V_207 = 0 ;
V_154 -> V_208 = V_4 -> V_59 ;
F_78 ( V_34 ) -> V_77 = sizeof( struct V_115 ) >> 2 ;
F_78 ( V_34 ) -> V_209 = F_117 ( F_118 ( F_78 ( V_199 ) -> V_209 ) +
sizeof( struct V_115 ) ) ;
} else
#endif
{
F_119 ( V_34 , V_34 -> V_108 ) ;
F_120 ( V_34 , V_77 ) ;
F_121 ( V_34 , V_199 -> V_210 , V_77 ) ;
F_78 ( V_34 ) -> V_78 = 0 ;
V_154 = (struct V_202 * ) F_116 ( V_34 ) ;
V_154 -> V_208 = V_124 ;
F_122 ( V_34 , F_123 ( F_124 ( V_199 ) ) ) ;
V_201 = (struct V_200 * ) F_120 ( V_34 , sizeof( struct V_200 ) ) ;
V_201 -> type =
V_154 -> V_206 = assert ;
V_201 -> V_211 = 0 ;
F_78 ( V_34 ) -> V_209 = F_117 ( V_34 -> V_108 ) ;
V_34 -> V_212 = V_34 -> V_213 ;
}
F_57 () ;
V_204 = F_125 ( V_4 -> V_204 ) ;
if ( V_204 == NULL ) {
F_59 () ;
F_48 ( V_34 ) ;
return - V_28 ;
}
V_205 = F_126 ( V_204 , V_34 ) ;
F_59 () ;
if ( V_205 < 0 ) {
F_127 ( L_5 ) ;
F_48 ( V_34 ) ;
}
return V_205 ;
}
static int
F_128 ( struct V_1 * V_4 , T_7 V_124 , struct V_33 * V_34 )
{
bool V_214 = false ;
int V_7 ;
struct V_138 * V_139 ;
const struct V_115 * V_70 = F_78 ( V_34 ) ;
F_129 ( & V_158 ) ;
F_130 (c, &mrt->mfc_unres_queue, list) {
if ( V_139 -> V_190 == V_70 -> V_71 &&
V_139 -> V_189 == V_70 -> V_74 ) {
V_214 = true ;
break;
}
}
if ( ! V_214 ) {
if ( F_131 ( & V_4 -> V_144 ) >= 10 ||
( V_139 = F_103 () ) == NULL ) {
F_132 ( & V_158 ) ;
F_48 ( V_34 ) ;
return - V_172 ;
}
V_139 -> V_194 = - 1 ;
V_139 -> V_189 = V_70 -> V_74 ;
V_139 -> V_190 = V_70 -> V_71 ;
V_7 = F_50 ( V_4 , V_34 , V_124 , V_215 ) ;
if ( V_7 < 0 ) {
F_132 ( & V_158 ) ;
F_72 ( V_139 ) ;
F_48 ( V_34 ) ;
return V_7 ;
}
F_133 ( & V_4 -> V_144 ) ;
F_134 ( & V_139 -> V_51 , & V_4 -> V_56 ) ;
F_89 ( V_4 , V_139 , V_216 ) ;
if ( F_131 ( & V_4 -> V_144 ) == 1 )
F_86 ( & V_4 -> V_57 , V_139 -> V_145 . V_146 . V_157 ) ;
}
if ( V_139 -> V_145 . V_146 . V_147 . V_217 > 3 ) {
F_48 ( V_34 ) ;
V_7 = - V_172 ;
} else {
F_135 ( & V_139 -> V_145 . V_146 . V_147 , V_34 ) ;
V_7 = 0 ;
}
F_132 ( & V_158 ) ;
return V_7 ;
}
static int F_136 ( struct V_1 * V_4 , struct V_218 * V_219 , int V_220 )
{
int line ;
struct V_138 * V_139 , * V_50 ;
line = F_96 ( V_219 -> V_221 . V_73 , V_219 -> V_222 . V_73 ) ;
F_21 (c, next, &mrt->mfc_cache_array[line], list) {
if ( V_139 -> V_189 == V_219 -> V_222 . V_73 &&
V_139 -> V_190 == V_219 -> V_221 . V_73 &&
( V_220 == - 1 || V_220 == V_139 -> V_194 ) ) {
F_137 ( & V_139 -> V_51 ) ;
F_89 ( V_4 , V_139 , V_163 ) ;
F_72 ( V_139 ) ;
return 0 ;
}
}
return - V_223 ;
}
static int F_138 ( struct V_2 * V_2 , struct V_1 * V_4 ,
struct V_218 * V_219 , int V_169 , int V_220 )
{
bool V_214 = false ;
int line ;
struct V_138 * V_196 , * V_139 ;
if ( V_219 -> V_224 >= V_167 )
return - V_225 ;
line = F_96 ( V_219 -> V_221 . V_73 , V_219 -> V_222 . V_73 ) ;
F_130 (c, &mrt->mfc_cache_array[line], list) {
if ( V_139 -> V_189 == V_219 -> V_222 . V_73 &&
V_139 -> V_190 == V_219 -> V_221 . V_73 &&
( V_220 == - 1 || V_220 == V_139 -> V_194 ) ) {
V_214 = true ;
break;
}
}
if ( V_214 ) {
F_61 ( & V_105 ) ;
V_139 -> V_194 = V_219 -> V_224 ;
F_91 ( V_4 , V_139 , V_219 -> V_226 ) ;
if ( ! V_169 )
V_139 -> V_227 |= V_228 ;
F_62 ( & V_105 ) ;
F_89 ( V_4 , V_139 , V_216 ) ;
return 0 ;
}
if ( V_219 -> V_221 . V_73 != F_99 ( V_191 ) &&
! F_139 ( V_219 -> V_221 . V_73 ) )
return - V_28 ;
V_139 = F_101 () ;
if ( V_139 == NULL )
return - V_47 ;
V_139 -> V_189 = V_219 -> V_222 . V_73 ;
V_139 -> V_190 = V_219 -> V_221 . V_73 ;
V_139 -> V_194 = V_219 -> V_224 ;
F_91 ( V_4 , V_139 , V_219 -> V_226 ) ;
if ( ! V_169 )
V_139 -> V_227 |= V_228 ;
F_140 ( & V_139 -> V_51 , & V_4 -> V_55 [ line ] ) ;
V_214 = false ;
F_129 ( & V_158 ) ;
F_130 (uc, &mrt->mfc_unres_queue, list) {
if ( V_196 -> V_189 == V_139 -> V_189 &&
V_196 -> V_190 == V_139 -> V_190 ) {
F_22 ( & V_196 -> V_51 ) ;
F_76 ( & V_4 -> V_144 ) ;
V_214 = true ;
break;
}
}
if ( F_87 ( & V_4 -> V_56 ) )
F_141 ( & V_4 -> V_57 ) ;
F_132 ( & V_158 ) ;
if ( V_214 ) {
F_105 ( V_2 , V_4 , V_196 , V_139 ) ;
F_72 ( V_196 ) ;
}
F_89 ( V_4 , V_139 , V_216 ) ;
return 0 ;
}
static void F_31 ( struct V_1 * V_4 )
{
int V_52 ;
F_142 ( V_51 ) ;
struct V_138 * V_139 , * V_50 ;
for ( V_52 = 0 ; V_52 < V_4 -> V_129 ; V_52 ++ ) {
if ( ! ( V_4 -> V_131 [ V_52 ] . V_13 & V_179 ) )
F_60 ( V_4 , V_52 , 0 , & V_51 ) ;
}
F_143 ( & V_51 ) ;
for ( V_52 = 0 ; V_52 < V_54 ; V_52 ++ ) {
F_21 (c, next, &mrt->mfc_cache_array[i], list) {
if ( V_139 -> V_227 & V_228 )
continue;
F_137 ( & V_139 -> V_51 ) ;
F_89 ( V_4 , V_139 , V_163 ) ;
F_72 ( V_139 ) ;
}
}
if ( F_131 ( & V_4 -> V_144 ) != 0 ) {
F_129 ( & V_158 ) ;
F_21 (c, next, &mrt->mfc_unres_queue, list) {
F_22 ( & V_139 -> V_51 ) ;
F_89 ( V_4 , V_139 , V_163 ) ;
F_74 ( V_4 , V_139 ) ;
}
F_132 ( & V_158 ) ;
}
}
static void F_144 ( struct V_203 * V_229 )
{
struct V_2 * V_2 = F_145 ( V_229 ) ;
struct V_1 * V_4 ;
F_45 () ;
F_2 (mrt, net) {
if ( V_229 == F_146 ( V_4 -> V_204 ) ) {
F_147 ( V_2 , V_133 ) -- ;
F_65 ( V_2 , V_134 ,
V_230 ,
V_2 -> V_15 . V_231 ) ;
F_148 ( V_4 -> V_204 , NULL ) ;
F_31 ( V_4 ) ;
}
}
F_44 () ;
}
int F_149 ( struct V_203 * V_229 , int V_232 , char V_85 * V_233 , unsigned int V_234 )
{
int V_205 , V_220 = 0 ;
struct V_62 V_235 ;
struct V_218 V_219 ;
struct V_2 * V_2 = F_145 ( V_229 ) ;
struct V_1 * V_4 ;
if ( V_229 -> V_236 != V_237 ||
F_150 ( V_229 ) -> V_238 != V_239 )
return - V_93 ;
V_4 = F_1 ( V_2 , F_151 ( V_229 ) -> V_240 ? : V_46 ) ;
if ( V_4 == NULL )
return - V_223 ;
if ( V_232 != V_241 ) {
if ( V_229 != F_152 ( V_4 -> V_204 ) &&
! F_153 ( V_2 -> V_242 , V_243 ) )
return - V_26 ;
}
switch ( V_232 ) {
case V_241 :
if ( V_234 != sizeof( int ) )
return - V_28 ;
F_45 () ;
if ( F_146 ( V_4 -> V_204 ) ) {
F_44 () ;
return - V_170 ;
}
V_205 = F_154 ( V_229 , 1 , F_144 ) ;
if ( V_205 == 0 ) {
F_155 ( V_4 -> V_204 , V_229 ) ;
F_147 ( V_2 , V_133 ) ++ ;
F_65 ( V_2 , V_134 ,
V_230 ,
V_2 -> V_15 . V_231 ) ;
}
F_44 () ;
return V_205 ;
case V_244 :
if ( V_229 != F_152 ( V_4 -> V_204 ) )
return - V_26 ;
return F_154 ( V_229 , 0 , NULL ) ;
case V_245 :
case V_246 :
if ( V_234 != sizeof( V_235 ) )
return - V_28 ;
if ( F_156 ( & V_235 , V_233 , sizeof( V_235 ) ) )
return - V_247 ;
if ( V_235 . V_81 >= V_167 )
return - V_225 ;
F_45 () ;
if ( V_232 == V_245 ) {
V_205 = F_92 ( V_2 , V_4 , & V_235 ,
V_229 == F_146 ( V_4 -> V_204 ) ) ;
} else {
V_205 = F_60 ( V_4 , V_235 . V_81 , 0 , NULL ) ;
}
F_44 () ;
return V_205 ;
case V_248 :
case V_249 :
V_220 = - 1 ;
case V_250 :
case V_251 :
if ( V_234 != sizeof( V_219 ) )
return - V_28 ;
if ( F_156 ( & V_219 , V_233 , sizeof( V_219 ) ) )
return - V_247 ;
if ( V_220 == 0 )
V_220 = V_219 . V_224 ;
F_45 () ;
if ( V_232 == V_249 || V_232 == V_251 )
V_205 = F_136 ( V_4 , & V_219 , V_220 ) ;
else
V_205 = F_138 ( V_2 , V_4 , & V_219 ,
V_229 == F_146 ( V_4 -> V_204 ) ,
V_220 ) ;
F_44 () ;
return V_205 ;
case V_252 :
{
int V_63 ;
if ( V_234 != sizeof( V_63 ) )
return - V_28 ;
if ( F_157 ( V_63 , ( int V_85 * ) V_233 ) )
return - V_247 ;
V_4 -> V_253 = V_63 ;
return 0 ;
}
#ifdef F_27
case V_254 :
{
int V_63 ;
if ( V_234 != sizeof( V_63 ) )
return - V_28 ;
if ( F_157 ( V_63 , ( int V_85 * ) V_233 ) )
return - V_247 ;
V_63 = ! ! V_63 ;
F_45 () ;
V_205 = 0 ;
if ( V_63 != V_4 -> V_255 ) {
V_4 -> V_255 = V_63 ;
V_4 -> V_253 = V_63 ;
}
F_44 () ;
return V_205 ;
}
#endif
#ifdef F_28
case V_256 :
{
T_1 V_63 ;
if ( V_234 != sizeof( T_1 ) )
return - V_28 ;
if ( F_157 ( V_63 , ( T_1 V_85 * ) V_233 ) )
return - V_247 ;
if ( V_63 != V_46 && V_63 >= 1000000000 )
return - V_28 ;
F_45 () ;
V_205 = 0 ;
if ( V_229 == F_146 ( V_4 -> V_204 ) ) {
V_205 = - V_257 ;
} else {
if ( ! F_16 ( V_2 , V_63 ) )
V_205 = - V_47 ;
else
F_151 ( V_229 ) -> V_240 = V_63 ;
}
F_44 () ;
return V_205 ;
}
#endif
default:
return - V_258 ;
}
}
int F_158 ( struct V_203 * V_229 , int V_232 , char V_85 * V_233 , int V_85 * V_234 )
{
int V_259 ;
int V_260 ;
struct V_2 * V_2 = F_145 ( V_229 ) ;
struct V_1 * V_4 ;
if ( V_229 -> V_236 != V_237 ||
F_150 ( V_229 ) -> V_238 != V_239 )
return - V_93 ;
V_4 = F_1 ( V_2 , F_151 ( V_229 ) -> V_240 ? : V_46 ) ;
if ( V_4 == NULL )
return - V_223 ;
if ( V_232 != V_261 &&
#ifdef F_27
V_232 != V_254 &&
#endif
V_232 != V_252 )
return - V_258 ;
if ( F_157 ( V_259 , V_234 ) )
return - V_247 ;
V_259 = F_159 (unsigned int, olr, sizeof(int)) ;
if ( V_259 < 0 )
return - V_28 ;
if ( F_160 ( V_259 , V_234 ) )
return - V_247 ;
if ( V_232 == V_261 )
V_260 = 0x0305 ;
#ifdef F_27
else if ( V_232 == V_254 )
V_260 = V_4 -> V_255 ;
#endif
else
V_260 = V_4 -> V_253 ;
if ( F_161 ( V_233 , & V_260 , V_259 ) )
return - V_247 ;
return 0 ;
}
int F_162 ( struct V_203 * V_229 , int V_262 , void V_85 * V_11 )
{
struct V_263 V_264 ;
struct V_265 V_266 ;
struct V_128 * V_235 ;
struct V_138 * V_139 ;
struct V_2 * V_2 = F_145 ( V_229 ) ;
struct V_1 * V_4 ;
V_4 = F_1 ( V_2 , F_151 ( V_229 ) -> V_240 ? : V_46 ) ;
if ( V_4 == NULL )
return - V_223 ;
switch ( V_262 ) {
case V_267 :
if ( F_156 ( & V_266 , V_11 , sizeof( V_266 ) ) )
return - V_247 ;
if ( V_266 . V_124 >= V_4 -> V_129 )
return - V_28 ;
F_49 ( & V_105 ) ;
V_235 = & V_4 -> V_131 [ V_266 . V_124 ] ;
if ( F_63 ( V_4 , V_266 . V_124 ) ) {
V_266 . V_268 = V_235 -> V_184 ;
V_266 . V_269 = V_235 -> V_185 ;
V_266 . V_270 = V_235 -> V_182 ;
V_266 . V_271 = V_235 -> V_183 ;
F_51 ( & V_105 ) ;
if ( F_161 ( V_11 , & V_266 , sizeof( V_266 ) ) )
return - V_247 ;
return 0 ;
}
F_51 ( & V_105 ) ;
return - V_130 ;
case V_272 :
if ( F_156 ( & V_264 , V_11 , sizeof( V_264 ) ) )
return - V_247 ;
F_57 () ;
V_139 = F_95 ( V_4 , V_264 . V_273 . V_73 , V_264 . V_274 . V_73 ) ;
if ( V_139 ) {
V_264 . V_275 = V_139 -> V_145 . V_9 . V_199 ;
V_264 . V_276 = V_139 -> V_145 . V_9 . V_277 ;
V_264 . V_278 = V_139 -> V_145 . V_9 . V_278 ;
F_59 () ;
if ( F_161 ( V_11 , & V_264 , sizeof( V_264 ) ) )
return - V_247 ;
return 0 ;
}
F_59 () ;
return - V_130 ;
default:
return - V_279 ;
}
}
int F_163 ( struct V_203 * V_229 , unsigned int V_262 , void V_85 * V_11 )
{
struct V_280 V_264 ;
struct V_281 V_266 ;
struct V_128 * V_235 ;
struct V_138 * V_139 ;
struct V_2 * V_2 = F_145 ( V_229 ) ;
struct V_1 * V_4 ;
V_4 = F_1 ( V_2 , F_151 ( V_229 ) -> V_240 ? : V_46 ) ;
if ( V_4 == NULL )
return - V_223 ;
switch ( V_262 ) {
case V_267 :
if ( F_156 ( & V_266 , V_11 , sizeof( V_266 ) ) )
return - V_247 ;
if ( V_266 . V_124 >= V_4 -> V_129 )
return - V_28 ;
F_49 ( & V_105 ) ;
V_235 = & V_4 -> V_131 [ V_266 . V_124 ] ;
if ( F_63 ( V_4 , V_266 . V_124 ) ) {
V_266 . V_268 = V_235 -> V_184 ;
V_266 . V_269 = V_235 -> V_185 ;
V_266 . V_270 = V_235 -> V_182 ;
V_266 . V_271 = V_235 -> V_183 ;
F_51 ( & V_105 ) ;
if ( F_161 ( V_11 , & V_266 , sizeof( V_266 ) ) )
return - V_247 ;
return 0 ;
}
F_51 ( & V_105 ) ;
return - V_130 ;
case V_272 :
if ( F_156 ( & V_264 , V_11 , sizeof( V_264 ) ) )
return - V_247 ;
F_57 () ;
V_139 = F_95 ( V_4 , V_264 . V_273 . V_73 , V_264 . V_274 . V_73 ) ;
if ( V_139 ) {
V_264 . V_275 = V_139 -> V_145 . V_9 . V_199 ;
V_264 . V_276 = V_139 -> V_145 . V_9 . V_277 ;
V_264 . V_278 = V_139 -> V_145 . V_9 . V_278 ;
F_59 () ;
if ( F_161 ( V_11 , & V_264 , sizeof( V_264 ) ) )
return - V_247 ;
return 0 ;
}
F_59 () ;
return - V_130 ;
default:
return - V_279 ;
}
}
static int F_164 ( struct V_282 * V_283 , unsigned long V_284 , void * V_285 )
{
struct V_60 * V_61 = F_165 ( V_285 ) ;
struct V_2 * V_2 = F_33 ( V_61 ) ;
struct V_1 * V_4 ;
struct V_128 * V_63 ;
int V_286 ;
if ( V_284 != V_287 )
return V_288 ;
F_2 (mrt, net) {
V_63 = & V_4 -> V_131 [ 0 ] ;
for ( V_286 = 0 ; V_286 < V_4 -> V_129 ; V_286 ++ , V_63 ++ ) {
if ( V_63 -> V_61 == V_61 )
F_60 ( V_4 , V_286 , 1 , NULL ) ;
}
}
return V_288 ;
}
static void F_166 ( struct V_33 * V_34 , T_6 V_74 , T_6 V_71 )
{
struct V_115 * V_70 ;
const struct V_115 * V_289 = F_78 ( V_34 ) ;
F_113 ( V_34 , sizeof( struct V_115 ) ) ;
V_34 -> V_212 = V_34 -> V_213 ;
F_114 ( V_34 ) ;
V_70 = F_78 ( V_34 ) ;
V_70 -> V_76 = 4 ;
V_70 -> V_41 = V_289 -> V_41 ;
V_70 -> V_290 = V_289 -> V_290 ;
V_70 -> V_291 = 0 ;
V_70 -> V_71 = V_71 ;
V_70 -> V_74 = V_74 ;
V_70 -> V_78 = V_79 ;
V_70 -> V_77 = 5 ;
V_70 -> V_209 = F_117 ( V_34 -> V_108 ) ;
F_167 ( V_34 , F_124 ( V_34 ) , NULL ) ;
F_168 ( V_70 ) ;
memset ( & ( F_169 ( V_34 ) -> V_292 ) , 0 , sizeof( F_169 ( V_34 ) -> V_292 ) ) ;
F_170 ( V_34 ) ;
}
static inline int F_171 ( struct V_33 * V_34 )
{
struct V_293 * V_292 = & ( F_169 ( V_34 ) -> V_292 ) ;
F_172 ( F_33 ( F_124 ( V_34 ) -> V_61 ) , V_294 ) ;
F_173 ( F_33 ( F_124 ( V_34 ) -> V_61 ) , V_295 , V_34 -> V_108 ) ;
if ( F_174 ( V_292 -> V_234 ) )
F_175 ( V_34 ) ;
return F_176 ( V_34 ) ;
}
static void F_177 ( struct V_2 * V_2 , struct V_1 * V_4 ,
struct V_33 * V_34 , struct V_138 * V_139 , int V_124 )
{
const struct V_115 * V_70 = F_78 ( V_34 ) ;
struct V_128 * V_235 = & V_4 -> V_131 [ V_124 ] ;
struct V_60 * V_61 ;
struct V_296 * V_297 ;
struct V_5 V_98 ;
int V_298 = 0 ;
if ( V_235 -> V_61 == NULL )
goto V_299;
#ifdef F_27
if ( V_235 -> V_13 & V_136 ) {
V_235 -> V_185 ++ ;
V_235 -> V_183 += V_34 -> V_108 ;
V_235 -> V_61 -> V_106 . V_107 += V_34 -> V_108 ;
V_235 -> V_61 -> V_106 . V_109 ++ ;
F_50 ( V_4 , V_34 , V_124 , V_110 ) ;
goto V_299;
}
#endif
if ( V_235 -> V_13 & V_135 ) {
V_297 = F_178 ( V_2 , & V_98 , NULL ,
V_235 -> V_178 , V_235 -> V_177 ,
0 , 0 ,
V_79 ,
F_179 ( V_70 -> V_41 ) , V_235 -> V_186 ) ;
if ( F_13 ( V_297 ) )
goto V_299;
V_298 = sizeof( struct V_115 ) ;
} else {
V_297 = F_178 ( V_2 , & V_98 , NULL , V_70 -> V_71 , 0 ,
0 , 0 ,
V_79 ,
F_179 ( V_70 -> V_41 ) , V_235 -> V_186 ) ;
if ( F_13 ( V_297 ) )
goto V_299;
}
V_61 = V_297 -> V_300 . V_61 ;
if ( V_34 -> V_108 + V_298 > F_180 ( & V_297 -> V_300 ) && ( F_118 ( V_70 -> V_291 ) & V_301 ) ) {
F_172 ( F_33 ( V_61 ) , V_302 ) ;
F_181 ( V_297 ) ;
goto V_299;
}
V_298 += F_182 ( V_61 ) + V_297 -> V_300 . V_303 ;
if ( F_183 ( V_34 , V_298 ) ) {
F_181 ( V_297 ) ;
goto V_299;
}
V_235 -> V_185 ++ ;
V_235 -> V_183 += V_34 -> V_108 ;
F_184 ( V_34 ) ;
F_122 ( V_34 , & V_297 -> V_300 ) ;
F_185 ( F_78 ( V_34 ) ) ;
if ( V_235 -> V_13 & V_135 ) {
F_166 ( V_34 , V_235 -> V_177 , V_235 -> V_178 ) ;
V_235 -> V_61 -> V_106 . V_109 ++ ;
V_235 -> V_61 -> V_106 . V_107 += V_34 -> V_108 ;
}
F_169 ( V_34 ) -> V_13 |= V_304 ;
F_186 ( V_305 , V_306 , V_34 , V_34 -> V_61 , V_61 ,
F_171 ) ;
return;
V_299:
F_48 ( V_34 ) ;
}
static int F_187 ( struct V_1 * V_4 , struct V_60 * V_61 )
{
int V_286 ;
for ( V_286 = V_4 -> V_129 - 1 ; V_286 >= 0 ; V_286 -- ) {
if ( V_4 -> V_131 [ V_286 ] . V_61 == V_61 )
break;
}
return V_286 ;
}
static void F_109 ( struct V_2 * V_2 , struct V_1 * V_4 ,
struct V_33 * V_34 , struct V_138 * V_164 ,
int V_177 )
{
int V_307 = - 1 ;
int V_235 , V_286 ;
int V_308 = F_187 ( V_4 , V_34 -> V_61 ) ;
V_235 = V_164 -> V_194 ;
V_164 -> V_145 . V_9 . V_199 ++ ;
V_164 -> V_145 . V_9 . V_277 += V_34 -> V_108 ;
if ( V_164 -> V_189 == F_99 ( V_191 ) && V_308 >= 0 ) {
struct V_138 * V_309 ;
V_309 = F_98 ( V_4 , V_235 ) ;
if ( V_309 &&
V_309 -> V_145 . V_9 . V_165 [ V_308 ] < 255 )
goto V_310;
}
if ( V_4 -> V_131 [ V_235 ] . V_61 != V_34 -> V_61 ) {
if ( F_188 ( F_189 ( V_34 ) ) ) {
goto V_311;
}
V_164 -> V_145 . V_9 . V_278 ++ ;
if ( V_308 >= 0 && V_4 -> V_253 &&
( V_4 -> V_255 ||
V_164 -> V_145 . V_9 . V_165 [ V_308 ] < 255 ) &&
F_88 ( V_159 ,
V_164 -> V_145 . V_9 . V_312 + V_313 ) ) {
V_164 -> V_145 . V_9 . V_312 = V_159 ;
F_50 ( V_4 , V_34 , V_308 , V_314 ) ;
}
goto V_311;
}
V_310:
V_4 -> V_131 [ V_235 ] . V_184 ++ ;
V_4 -> V_131 [ V_235 ] . V_182 += V_34 -> V_108 ;
if ( V_164 -> V_189 == F_99 ( V_191 ) &&
V_164 -> V_190 == F_99 ( V_191 ) ) {
if ( V_308 >= 0 &&
V_308 != V_164 -> V_194 &&
F_78 ( V_34 ) -> V_290 >
V_164 -> V_145 . V_9 . V_165 [ V_164 -> V_194 ] ) {
V_307 = V_164 -> V_194 ;
goto V_315;
}
goto V_311;
}
for ( V_286 = V_164 -> V_145 . V_9 . V_129 - 1 ;
V_286 >= V_164 -> V_145 . V_9 . V_166 ; V_286 -- ) {
if ( ( V_164 -> V_189 != F_99 ( V_191 ) ||
V_286 != V_308 ) &&
F_78 ( V_34 ) -> V_290 > V_164 -> V_145 . V_9 . V_165 [ V_286 ] ) {
if ( V_307 != - 1 ) {
struct V_33 * V_316 = F_190 ( V_34 , V_195 ) ;
if ( V_316 )
F_177 ( V_2 , V_4 , V_316 , V_164 ,
V_307 ) ;
}
V_307 = V_286 ;
}
}
V_315:
if ( V_307 != - 1 ) {
if ( V_177 ) {
struct V_33 * V_316 = F_190 ( V_34 , V_195 ) ;
if ( V_316 )
F_177 ( V_2 , V_4 , V_316 , V_164 , V_307 ) ;
} else {
F_177 ( V_2 , V_4 , V_34 , V_164 , V_307 ) ;
return;
}
}
V_311:
if ( ! V_177 )
F_48 ( V_34 ) ;
}
static struct V_1 * F_191 ( struct V_2 * V_2 , struct V_33 * V_34 )
{
struct V_296 * V_297 = F_189 ( V_34 ) ;
struct V_115 * V_70 = F_78 ( V_34 ) ;
struct V_5 V_98 = {
. V_71 = V_70 -> V_71 ,
. V_74 = V_70 -> V_74 ,
. V_317 = F_179 ( V_70 -> V_41 ) ,
. V_99 = ( F_188 ( V_297 ) ?
V_34 -> V_61 -> V_100 : 0 ) ,
. V_101 = ( F_188 ( V_297 ) ?
V_318 :
V_34 -> V_61 -> V_100 ) ,
. V_103 = V_34 -> V_104 ,
} ;
struct V_1 * V_4 ;
int V_7 ;
V_7 = F_3 ( V_2 , & V_98 , & V_4 ) ;
if ( V_7 )
return F_192 ( V_7 ) ;
return V_4 ;
}
int F_193 ( struct V_33 * V_34 )
{
struct V_138 * V_164 ;
struct V_2 * V_2 = F_33 ( V_34 -> V_61 ) ;
int V_177 = F_189 ( V_34 ) -> V_319 & V_320 ;
struct V_1 * V_4 ;
if ( F_169 ( V_34 ) -> V_13 & V_304 )
goto V_311;
V_4 = F_191 ( V_2 , V_34 ) ;
if ( F_13 ( V_4 ) ) {
F_48 ( V_34 ) ;
return F_14 ( V_4 ) ;
}
if ( ! V_177 ) {
if ( F_169 ( V_34 ) -> V_292 . V_321 ) {
if ( F_194 ( V_34 ) )
return 0 ;
} else if ( F_78 ( V_34 ) -> V_78 == V_239 ) {
struct V_203 * V_204 ;
V_204 = F_125 ( V_4 -> V_204 ) ;
if ( V_204 ) {
F_170 ( V_34 ) ;
F_195 ( V_204 , V_34 ) ;
return 0 ;
}
}
}
V_164 = F_95 ( V_4 , F_78 ( V_34 ) -> V_74 , F_78 ( V_34 ) -> V_71 ) ;
if ( V_164 == NULL ) {
int V_235 = F_187 ( V_4 , V_34 -> V_61 ) ;
if ( V_235 >= 0 )
V_164 = F_100 ( V_4 , F_78 ( V_34 ) -> V_71 ,
V_235 ) ;
}
if ( V_164 == NULL ) {
int V_235 ;
if ( V_177 ) {
struct V_33 * V_316 = F_190 ( V_34 , V_195 ) ;
F_196 ( V_34 ) ;
if ( V_316 == NULL )
return - V_172 ;
V_34 = V_316 ;
}
F_49 ( & V_105 ) ;
V_235 = F_187 ( V_4 , V_34 -> V_61 ) ;
if ( V_235 >= 0 ) {
int V_49 = F_128 ( V_4 , V_235 , V_34 ) ;
F_51 ( & V_105 ) ;
return V_49 ;
}
F_51 ( & V_105 ) ;
F_48 ( V_34 ) ;
return - V_322 ;
}
F_49 ( & V_105 ) ;
F_109 ( V_2 , V_4 , V_34 , V_164 , V_177 ) ;
F_51 ( & V_105 ) ;
if ( V_177 )
return F_196 ( V_34 ) ;
return 0 ;
V_311:
if ( V_177 )
return F_196 ( V_34 ) ;
F_48 ( V_34 ) ;
return 0 ;
}
static int F_197 ( struct V_1 * V_4 , struct V_33 * V_34 ,
unsigned int V_323 )
{
struct V_60 * V_324 = NULL ;
struct V_115 * V_298 ;
V_298 = (struct V_115 * ) ( F_198 ( V_34 ) + V_323 ) ;
if ( ! F_139 ( V_298 -> V_71 ) ||
V_298 -> V_209 == 0 ||
F_118 ( V_298 -> V_209 ) + V_323 > V_34 -> V_108 )
return 1 ;
F_49 ( & V_105 ) ;
if ( V_4 -> V_59 >= 0 )
V_324 = V_4 -> V_131 [ V_4 -> V_59 ] . V_61 ;
F_51 ( & V_105 ) ;
if ( V_324 == NULL )
return 1 ;
V_34 -> V_325 = V_34 -> V_213 ;
F_79 ( V_34 , ( V_197 * ) V_298 - V_34 -> V_210 ) ;
F_114 ( V_34 ) ;
V_34 -> V_78 = F_117 ( V_326 ) ;
V_34 -> V_327 = V_328 ;
F_199 ( V_34 , V_324 , F_33 ( V_324 ) ) ;
F_200 ( V_34 ) ;
return V_329 ;
}
int F_201 ( struct V_33 * V_34 )
{
struct V_200 * V_330 ;
struct V_2 * V_2 = F_33 ( V_34 -> V_61 ) ;
struct V_1 * V_4 ;
if ( ! F_202 ( V_34 , sizeof( * V_330 ) + sizeof( struct V_115 ) ) )
goto V_331;
V_330 = F_203 ( V_34 ) ;
V_4 = F_191 ( V_2 , V_34 ) ;
if ( F_13 ( V_4 ) )
goto V_331;
if ( ! V_4 -> V_255 ||
V_330 -> V_332 != V_333 || V_330 -> V_211 != V_334 )
goto V_331;
if ( F_197 ( V_4 , V_34 , sizeof( * V_330 ) ) ) {
V_331:
F_48 ( V_34 ) ;
}
return 0 ;
}
static int F_204 ( struct V_33 * V_34 )
{
struct V_335 * V_330 ;
struct V_2 * V_2 = F_33 ( V_34 -> V_61 ) ;
struct V_1 * V_4 ;
if ( ! F_202 ( V_34 , sizeof( * V_330 ) + sizeof( struct V_115 ) ) )
goto V_331;
V_330 = (struct V_335 * ) F_198 ( V_34 ) ;
if ( V_330 -> type != ( ( V_336 << 4 ) | ( V_337 ) ) ||
( V_330 -> V_13 & V_338 ) ||
( F_205 ( ( void * ) V_330 , sizeof( * V_330 ) ) != 0 &&
F_206 ( F_207 ( V_34 , 0 , V_34 -> V_108 , 0 ) ) ) )
goto V_331;
V_4 = F_191 ( V_2 , V_34 ) ;
if ( F_13 ( V_4 ) )
goto V_331;
if ( F_197 ( V_4 , V_34 , sizeof( * V_330 ) ) ) {
V_331:
F_48 ( V_34 ) ;
}
return 0 ;
}
static int F_107 ( struct V_1 * V_4 , struct V_33 * V_34 ,
struct V_138 * V_139 , struct V_339 * V_340 )
{
int V_286 ;
struct V_341 * V_342 ;
struct V_37 * V_343 ;
struct V_344 V_345 ;
if ( V_139 -> V_194 >= V_167 )
return - V_223 ;
if ( F_63 ( V_4 , V_139 -> V_194 ) &&
F_208 ( V_34 , V_346 , V_4 -> V_131 [ V_139 -> V_194 ] . V_61 -> V_100 ) < 0 )
return - V_198 ;
if ( ! ( V_343 = F_209 ( V_34 , V_347 ) ) )
return - V_198 ;
for ( V_286 = V_139 -> V_145 . V_9 . V_166 ; V_286 < V_139 -> V_145 . V_9 . V_129 ; V_286 ++ ) {
if ( F_63 ( V_4 , V_286 ) && V_139 -> V_145 . V_9 . V_165 [ V_286 ] < 255 ) {
if ( ! ( V_342 = F_210 ( V_34 , sizeof( * V_342 ) ) ) ) {
F_211 ( V_34 , V_343 ) ;
return - V_198 ;
}
V_342 -> V_348 = 0 ;
V_342 -> V_349 = V_139 -> V_145 . V_9 . V_165 [ V_286 ] ;
V_342 -> V_350 = V_4 -> V_131 [ V_286 ] . V_61 -> V_100 ;
V_342 -> V_351 = sizeof( * V_342 ) ;
}
}
F_212 ( V_34 , V_343 ) ;
V_345 . V_352 = V_139 -> V_145 . V_9 . V_199 ;
V_345 . V_353 = V_139 -> V_145 . V_9 . V_277 ;
V_345 . V_354 = V_139 -> V_145 . V_9 . V_278 ;
if ( F_213 ( V_34 , V_355 , sizeof( V_345 ) , & V_345 ) < 0 )
return - V_198 ;
V_340 -> V_356 = V_357 ;
return 1 ;
}
int F_214 ( struct V_2 * V_2 , struct V_33 * V_34 ,
T_6 V_74 , T_6 V_71 ,
struct V_339 * V_340 , int V_358 )
{
struct V_138 * V_164 ;
struct V_1 * V_4 ;
int V_7 ;
V_4 = F_1 ( V_2 , V_46 ) ;
if ( V_4 == NULL )
return - V_223 ;
F_57 () ;
V_164 = F_95 ( V_4 , V_74 , V_71 ) ;
if ( V_164 == NULL && V_34 -> V_61 ) {
int V_235 = F_187 ( V_4 , V_34 -> V_61 ) ;
if ( V_235 >= 0 )
V_164 = F_100 ( V_4 , V_71 , V_235 ) ;
}
if ( V_164 == NULL ) {
struct V_33 * V_316 ;
struct V_115 * V_70 ;
struct V_60 * V_61 ;
int V_235 = - 1 ;
if ( V_358 ) {
F_59 () ;
return - V_31 ;
}
V_61 = V_34 -> V_61 ;
F_49 ( & V_105 ) ;
if ( V_61 )
V_235 = F_187 ( V_4 , V_61 ) ;
if ( V_235 < 0 ) {
F_51 ( & V_105 ) ;
F_59 () ;
return - V_322 ;
}
V_316 = F_190 ( V_34 , V_195 ) ;
if ( ! V_316 ) {
F_51 ( & V_105 ) ;
F_59 () ;
return - V_47 ;
}
F_113 ( V_316 , sizeof( struct V_115 ) ) ;
F_114 ( V_316 ) ;
V_70 = F_78 ( V_316 ) ;
V_70 -> V_77 = sizeof( struct V_115 ) >> 2 ;
V_70 -> V_74 = V_74 ;
V_70 -> V_71 = V_71 ;
V_70 -> V_76 = 0 ;
V_7 = F_128 ( V_4 , V_235 , V_316 ) ;
F_51 ( & V_105 ) ;
F_59 () ;
return V_7 ;
}
F_49 ( & V_105 ) ;
if ( ! V_358 && ( V_340 -> V_359 & V_360 ) )
V_164 -> V_227 |= V_361 ;
V_7 = F_107 ( V_4 , V_34 , V_164 , V_340 ) ;
F_51 ( & V_105 ) ;
F_59 () ;
return V_7 ;
}
static int F_215 ( struct V_1 * V_4 , struct V_33 * V_34 ,
T_1 V_155 , T_1 V_362 , struct V_138 * V_139 , int V_262 )
{
struct V_148 * V_149 ;
struct V_339 * V_340 ;
int V_7 ;
V_149 = F_216 ( V_34 , V_155 , V_362 , V_262 , sizeof( * V_340 ) , V_363 ) ;
if ( V_149 == NULL )
return - V_198 ;
V_340 = F_82 ( V_149 ) ;
V_340 -> V_364 = V_365 ;
V_340 -> V_366 = 32 ;
V_340 -> V_367 = 32 ;
V_340 -> V_368 = 0 ;
V_340 -> V_369 = V_4 -> V_3 ;
if ( F_208 ( V_34 , V_370 , V_4 -> V_3 ) )
goto V_371;
V_340 -> V_356 = V_357 ;
V_340 -> V_372 = V_373 ;
if ( V_139 -> V_227 & V_228 )
V_340 -> V_374 = V_375 ;
else
V_340 -> V_374 = V_376 ;
V_340 -> V_359 = 0 ;
if ( F_217 ( V_34 , V_377 , V_139 -> V_189 ) ||
F_217 ( V_34 , V_378 , V_139 -> V_190 ) )
goto V_371;
V_7 = F_107 ( V_4 , V_34 , V_139 , V_340 ) ;
if ( V_7 < 0 && V_7 != - V_223 )
goto V_371;
return F_218 ( V_34 , V_149 ) ;
V_371:
F_219 ( V_34 , V_149 ) ;
return - V_198 ;
}
static T_8 F_220 ( bool V_147 , int V_129 )
{
T_8 V_108 =
F_221 ( sizeof( struct V_339 ) )
+ F_222 ( 4 )
+ F_222 ( 4 )
+ F_222 ( 4 )
;
if ( ! V_147 )
V_108 = V_108
+ F_222 ( 4 )
+ F_222 ( 0 )
+ V_129 * F_223 ( sizeof( struct V_341 ) )
+ F_222 ( sizeof( struct V_344 ) )
;
return V_108 ;
}
static void F_89 ( struct V_1 * V_4 , struct V_138 * V_219 ,
int V_262 )
{
struct V_2 * V_2 = F_75 ( & V_4 -> V_2 ) ;
struct V_33 * V_34 ;
int V_7 = - V_172 ;
V_34 = F_224 ( F_220 ( V_219 -> V_194 >= V_167 , V_4 -> V_129 ) ,
V_195 ) ;
if ( V_34 == NULL )
goto V_379;
V_7 = F_215 ( V_4 , V_34 , 0 , 0 , V_219 , V_262 ) ;
if ( V_7 < 0 )
goto V_379;
F_225 ( V_34 , V_2 , 0 , V_380 , NULL , V_195 ) ;
return;
V_379:
F_48 ( V_34 ) ;
if ( V_7 < 0 )
F_226 ( V_2 , V_380 , V_7 ) ;
}
static int F_227 ( struct V_33 * V_34 , struct V_381 * V_382 )
{
struct V_2 * V_2 = F_145 ( V_34 -> V_229 ) ;
struct V_1 * V_4 ;
struct V_138 * V_219 ;
unsigned int V_383 = 0 , V_384 ;
unsigned int V_385 = 0 , V_386 ;
unsigned int V_143 = 0 , V_387 ;
V_384 = V_382 -> args [ 0 ] ;
V_386 = V_382 -> args [ 1 ] ;
V_387 = V_382 -> args [ 2 ] ;
F_57 () ;
F_2 (mrt, net) {
if ( V_383 < V_384 )
goto V_388;
if ( V_383 > V_384 )
V_386 = 0 ;
for ( V_385 = V_386 ; V_385 < V_54 ; V_385 ++ ) {
F_97 (mfc, &mrt->mfc_cache_array[h], list) {
if ( V_143 < V_387 )
goto V_389;
if ( F_215 ( V_4 , V_34 ,
F_84 ( V_382 -> V_34 ) . V_155 ,
V_382 -> V_149 -> V_390 ,
V_219 , V_216 ) < 0 )
goto V_391;
V_389:
V_143 ++ ;
}
V_143 = V_387 = 0 ;
}
F_129 ( & V_158 ) ;
F_130 (mfc, &mrt->mfc_unres_queue, list) {
if ( V_143 < V_387 )
goto V_392;
if ( F_215 ( V_4 , V_34 ,
F_84 ( V_382 -> V_34 ) . V_155 ,
V_382 -> V_149 -> V_390 ,
V_219 , V_216 ) < 0 ) {
F_132 ( & V_158 ) ;
goto V_391;
}
V_392:
V_143 ++ ;
}
F_132 ( & V_158 ) ;
V_143 = V_387 = 0 ;
V_386 = 0 ;
V_388:
V_383 ++ ;
}
V_391:
F_59 () ;
V_382 -> args [ 2 ] = V_143 ;
V_382 -> args [ 1 ] = V_385 ;
V_382 -> args [ 0 ] = V_383 ;
return V_34 -> V_108 ;
}
static struct V_128 * F_228 ( struct V_2 * V_2 ,
struct V_393 * V_394 ,
T_9 V_395 )
{
struct V_1 * V_4 = V_394 -> V_4 ;
for ( V_394 -> V_286 = 0 ; V_394 -> V_286 < V_4 -> V_129 ; ++ V_394 -> V_286 ) {
if ( ! F_63 ( V_4 , V_394 -> V_286 ) )
continue;
if ( V_395 -- == 0 )
return & V_4 -> V_131 [ V_394 -> V_286 ] ;
}
return NULL ;
}
static void * F_229 ( struct V_396 * V_362 , T_9 * V_395 )
__acquires( V_105 )
{
struct V_393 * V_394 = V_362 -> V_397 ;
struct V_2 * V_2 = F_230 ( V_362 ) ;
struct V_1 * V_4 ;
V_4 = F_1 ( V_2 , V_46 ) ;
if ( V_4 == NULL )
return F_192 ( - V_223 ) ;
V_394 -> V_4 = V_4 ;
F_49 ( & V_105 ) ;
return * V_395 ? F_228 ( V_2 , V_362 -> V_397 , * V_395 - 1 )
: V_398 ;
}
static void * F_231 ( struct V_396 * V_362 , void * V_63 , T_9 * V_395 )
{
struct V_393 * V_394 = V_362 -> V_397 ;
struct V_2 * V_2 = F_230 ( V_362 ) ;
struct V_1 * V_4 = V_394 -> V_4 ;
++ * V_395 ;
if ( V_63 == V_398 )
return F_228 ( V_2 , V_394 , 0 ) ;
while ( ++ V_394 -> V_286 < V_4 -> V_129 ) {
if ( ! F_63 ( V_4 , V_394 -> V_286 ) )
continue;
return & V_4 -> V_131 [ V_394 -> V_286 ] ;
}
return NULL ;
}
static void F_232 ( struct V_396 * V_362 , void * V_63 )
__releases( V_105 )
{
F_51 ( & V_105 ) ;
}
static int F_233 ( struct V_396 * V_362 , void * V_63 )
{
struct V_393 * V_394 = V_362 -> V_397 ;
struct V_1 * V_4 = V_394 -> V_4 ;
if ( V_63 == V_398 ) {
F_234 ( V_362 ,
L_6 ) ;
} else {
const struct V_128 * V_235 = V_63 ;
const char * V_80 = V_235 -> V_61 ? V_235 -> V_61 -> V_80 : L_7 ;
F_235 ( V_362 ,
L_8 ,
V_235 - V_4 -> V_131 ,
V_80 , V_235 -> V_182 , V_235 -> V_184 ,
V_235 -> V_183 , V_235 -> V_185 ,
V_235 -> V_13 , V_235 -> V_177 , V_235 -> V_178 ) ;
}
return 0 ;
}
static int F_236 ( struct V_399 * V_399 , struct V_400 * V_400 )
{
return F_237 ( V_399 , V_400 , & V_401 ,
sizeof( struct V_393 ) ) ;
}
static struct V_138 * F_238 ( struct V_2 * V_2 ,
struct V_402 * V_403 , T_9 V_395 )
{
struct V_1 * V_4 = V_403 -> V_4 ;
struct V_138 * V_219 ;
F_57 () ;
for ( V_403 -> V_286 = 0 ; V_403 -> V_286 < V_54 ; V_403 -> V_286 ++ ) {
V_403 -> V_164 = & V_4 -> V_55 [ V_403 -> V_286 ] ;
F_97 (mfc, it->cache, list)
if ( V_395 -- == 0 )
return V_219 ;
}
F_59 () ;
F_129 ( & V_158 ) ;
V_403 -> V_164 = & V_4 -> V_56 ;
F_130 (mfc, it->cache, list)
if ( V_395 -- == 0 )
return V_219 ;
F_132 ( & V_158 ) ;
V_403 -> V_164 = NULL ;
return NULL ;
}
static void * F_239 ( struct V_396 * V_362 , T_9 * V_395 )
{
struct V_402 * V_403 = V_362 -> V_397 ;
struct V_2 * V_2 = F_230 ( V_362 ) ;
struct V_1 * V_4 ;
V_4 = F_1 ( V_2 , V_46 ) ;
if ( V_4 == NULL )
return F_192 ( - V_223 ) ;
V_403 -> V_4 = V_4 ;
V_403 -> V_164 = NULL ;
V_403 -> V_286 = 0 ;
return * V_395 ? F_238 ( V_2 , V_362 -> V_397 , * V_395 - 1 )
: V_398 ;
}
static void * F_240 ( struct V_396 * V_362 , void * V_63 , T_9 * V_395 )
{
struct V_138 * V_219 = V_63 ;
struct V_402 * V_403 = V_362 -> V_397 ;
struct V_2 * V_2 = F_230 ( V_362 ) ;
struct V_1 * V_4 = V_403 -> V_4 ;
++ * V_395 ;
if ( V_63 == V_398 )
return F_238 ( V_2 , V_362 -> V_397 , 0 ) ;
if ( V_219 -> V_51 . V_50 != V_403 -> V_164 )
return F_241 ( V_219 -> V_51 . V_50 , struct V_138 , V_51 ) ;
if ( V_403 -> V_164 == & V_4 -> V_56 )
goto V_404;
F_242 ( V_403 -> V_164 != & V_4 -> V_55 [ V_403 -> V_286 ] ) ;
while ( ++ V_403 -> V_286 < V_54 ) {
V_403 -> V_164 = & V_4 -> V_55 [ V_403 -> V_286 ] ;
if ( F_87 ( V_403 -> V_164 ) )
continue;
return F_243 ( V_403 -> V_164 , struct V_138 , V_51 ) ;
}
F_59 () ;
V_403 -> V_164 = & V_4 -> V_56 ;
V_403 -> V_286 = 0 ;
F_129 ( & V_158 ) ;
if ( ! F_87 ( V_403 -> V_164 ) )
return F_243 ( V_403 -> V_164 , struct V_138 , V_51 ) ;
V_404:
F_132 ( & V_158 ) ;
V_403 -> V_164 = NULL ;
return NULL ;
}
static void F_244 ( struct V_396 * V_362 , void * V_63 )
{
struct V_402 * V_403 = V_362 -> V_397 ;
struct V_1 * V_4 = V_403 -> V_4 ;
if ( V_403 -> V_164 == & V_4 -> V_56 )
F_132 ( & V_158 ) ;
else if ( V_403 -> V_164 == & V_4 -> V_55 [ V_403 -> V_286 ] )
F_59 () ;
}
static int F_245 ( struct V_396 * V_362 , void * V_63 )
{
int V_405 ;
if ( V_63 == V_398 ) {
F_234 ( V_362 ,
L_9 ) ;
} else {
const struct V_138 * V_219 = V_63 ;
const struct V_402 * V_403 = V_362 -> V_397 ;
const struct V_1 * V_4 = V_403 -> V_4 ;
F_235 ( V_362 , L_10 ,
( V_84 T_1 ) V_219 -> V_190 ,
( V_84 T_1 ) V_219 -> V_189 ,
V_219 -> V_194 ) ;
if ( V_403 -> V_164 != & V_4 -> V_56 ) {
F_235 ( V_362 , L_11 ,
V_219 -> V_145 . V_9 . V_199 ,
V_219 -> V_145 . V_9 . V_277 ,
V_219 -> V_145 . V_9 . V_278 ) ;
for ( V_405 = V_219 -> V_145 . V_9 . V_166 ;
V_405 < V_219 -> V_145 . V_9 . V_129 ; V_405 ++ ) {
if ( F_63 ( V_4 , V_405 ) &&
V_219 -> V_145 . V_9 . V_165 [ V_405 ] < 255 )
F_235 ( V_362 ,
L_12 ,
V_405 , V_219 -> V_145 . V_9 . V_165 [ V_405 ] ) ;
}
} else {
F_235 ( V_362 , L_11 , 0ul , 0ul , 0ul ) ;
}
F_246 ( V_362 , '\n' ) ;
}
return 0 ;
}
static int F_247 ( struct V_399 * V_399 , struct V_400 * V_400 )
{
return F_237 ( V_399 , V_400 , & V_406 ,
sizeof( struct V_402 ) ) ;
}
static int T_2 F_248 ( struct V_2 * V_2 )
{
int V_7 ;
V_7 = F_11 ( V_2 ) ;
if ( V_7 < 0 )
goto V_407;
#ifdef F_249
V_7 = - V_47 ;
if ( ! F_250 ( L_13 , 0 , V_2 -> V_408 , & V_409 ) )
goto V_410;
if ( ! F_250 ( L_14 , 0 , V_2 -> V_408 , & V_411 ) )
goto V_412;
#endif
return 0 ;
#ifdef F_249
V_412:
F_251 ( L_13 , V_2 -> V_408 ) ;
V_410:
F_20 ( V_2 ) ;
#endif
V_407:
return V_7 ;
}
static void T_3 F_252 ( struct V_2 * V_2 )
{
#ifdef F_249
F_251 ( L_14 , V_2 -> V_408 ) ;
F_251 ( L_13 , V_2 -> V_408 ) ;
#endif
F_20 ( V_2 ) ;
}
int T_10 F_253 ( void )
{
int V_7 ;
V_141 = F_254 ( L_15 ,
sizeof( struct V_138 ) ,
0 , V_413 | V_414 ,
NULL ) ;
if ( ! V_141 )
return - V_47 ;
V_7 = F_255 ( & V_415 ) ;
if ( V_7 )
goto V_416;
V_7 = F_256 ( & V_417 ) ;
if ( V_7 )
goto V_418;
#ifdef F_257
if ( F_258 ( & V_419 , V_420 ) < 0 ) {
F_259 ( L_16 , V_421 ) ;
V_7 = - V_31 ;
goto V_422;
}
#endif
F_260 ( V_365 , V_423 ,
NULL , F_227 , NULL ) ;
return 0 ;
#ifdef F_257
V_422:
F_261 ( & V_417 ) ;
#endif
V_418:
F_262 ( & V_415 ) ;
V_416:
F_263 ( V_141 ) ;
return V_7 ;
}
