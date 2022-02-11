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
F_41 ( V_91 -> V_96 ) ;
F_42 ( V_91 -> V_97 , V_98 ) = 0 ;
if ( F_43 ( V_61 ) )
goto V_95;
F_44 ( V_61 ) ;
}
}
return V_61 ;
V_95:
F_45 () ;
F_46 () ;
F_47 ( V_61 ) ;
return NULL ;
}
static T_5 F_48 ( struct V_33 * V_34 , struct V_60 * V_61 )
{
struct V_2 * V_2 = F_33 ( V_61 ) ;
struct V_1 * V_4 ;
struct V_5 V_99 = {
. V_100 = V_61 -> V_101 ,
. V_102 = V_34 -> V_103 ,
. V_104 = V_34 -> V_105 ,
} ;
int V_7 ;
V_7 = F_3 ( V_2 , & V_99 , & V_4 ) ;
if ( V_7 < 0 ) {
F_49 ( V_34 ) ;
return V_7 ;
}
F_50 ( & V_106 ) ;
V_61 -> V_107 . V_108 += V_34 -> V_109 ;
V_61 -> V_107 . V_110 ++ ;
F_51 ( V_4 , V_34 , V_4 -> V_59 , V_111 ) ;
F_52 ( & V_106 ) ;
F_49 ( V_34 ) ;
return V_112 ;
}
static void F_53 ( struct V_60 * V_61 )
{
V_61 -> type = V_113 ;
V_61 -> V_114 = V_115 - sizeof( struct V_116 ) - 8 ;
V_61 -> V_13 = V_117 ;
V_61 -> V_65 = & V_118 ,
V_61 -> V_119 = V_120 ;
V_61 -> V_121 |= V_122 ;
}
static struct V_60 * F_54 ( struct V_2 * V_2 , struct V_1 * V_4 )
{
struct V_60 * V_61 ;
struct V_90 * V_91 ;
char V_80 [ V_123 ] ;
if ( V_4 -> V_3 == V_46 )
sprintf ( V_80 , L_3 ) ;
else
sprintf ( V_80 , L_4 , V_4 -> V_3 ) ;
V_61 = F_55 ( 0 , V_80 , F_53 ) ;
if ( V_61 == NULL )
return NULL ;
F_56 ( V_61 , V_2 ) ;
if ( F_57 ( V_61 ) ) {
V_120 ( V_61 ) ;
return NULL ;
}
V_61 -> V_124 = 0 ;
F_58 () ;
V_91 = F_59 ( V_61 ) ;
if ( ! V_91 ) {
F_60 () ;
goto V_95;
}
F_40 ( V_91 ) ;
F_41 ( V_91 -> V_96 ) ;
F_42 ( V_91 -> V_97 , V_98 ) = 0 ;
F_60 () ;
if ( F_43 ( V_61 ) )
goto V_95;
F_44 ( V_61 ) ;
return V_61 ;
V_95:
F_45 () ;
F_46 () ;
F_47 ( V_61 ) ;
return NULL ;
}
static int F_61 ( struct V_1 * V_4 , int V_125 , int V_126 ,
struct V_127 * V_128 )
{
struct V_129 * V_63 ;
struct V_60 * V_61 ;
struct V_90 * V_91 ;
if ( V_125 < 0 || V_125 >= V_4 -> V_130 )
return - V_131 ;
V_63 = & V_4 -> V_132 [ V_125 ] ;
F_62 ( & V_106 ) ;
V_61 = V_63 -> V_61 ;
V_63 -> V_61 = NULL ;
if ( ! V_61 ) {
F_63 ( & V_106 ) ;
return - V_131 ;
}
#ifdef F_27
if ( V_125 == V_4 -> V_59 )
V_4 -> V_59 = - 1 ;
#endif
if ( V_125 + 1 == V_4 -> V_130 ) {
int V_133 ;
for ( V_133 = V_125 - 1 ; V_133 >= 0 ; V_133 -- ) {
if ( F_64 ( V_4 , V_133 ) )
break;
}
V_4 -> V_130 = V_133 + 1 ;
}
F_63 ( & V_106 ) ;
F_65 ( V_61 , - 1 ) ;
V_91 = F_39 ( V_61 ) ;
if ( V_91 ) {
F_42 ( V_91 -> V_97 , V_134 ) -- ;
F_66 ( F_33 ( V_61 ) ,
V_135 ,
V_61 -> V_101 , & V_91 -> V_97 ) ;
F_67 ( V_91 ) ;
}
if ( V_63 -> V_13 & ( V_136 | V_137 ) && ! V_126 )
F_68 ( V_61 , V_128 ) ;
F_69 ( V_61 ) ;
return 0 ;
}
static void F_70 ( struct V_138 * V_128 )
{
struct V_139 * V_140 = F_71 ( V_128 , struct V_139 , V_141 ) ;
F_72 ( V_142 , V_140 ) ;
}
static inline void F_73 ( struct V_139 * V_140 )
{
F_74 ( & V_140 -> V_141 , F_70 ) ;
}
static void F_75 ( struct V_1 * V_4 , struct V_139 * V_140 )
{
struct V_2 * V_2 = F_76 ( & V_4 -> V_2 ) ;
struct V_33 * V_34 ;
struct V_143 * V_144 ;
F_77 ( & V_4 -> V_145 ) ;
while ( ( V_34 = F_78 ( & V_140 -> V_146 . V_147 . V_148 ) ) ) {
if ( F_79 ( V_34 ) -> V_76 == 0 ) {
struct V_149 * V_150 = (struct V_149 * ) F_80 ( V_34 , sizeof( struct V_116 ) ) ;
V_150 -> V_151 = V_152 ;
V_150 -> V_153 = F_81 ( sizeof( struct V_143 ) ) ;
F_82 ( V_34 , V_150 -> V_153 ) ;
V_144 = F_83 ( V_150 ) ;
V_144 -> error = - V_154 ;
memset ( & V_144 -> V_155 , 0 , sizeof( V_144 -> V_155 ) ) ;
F_84 ( V_34 , V_2 , F_85 ( V_34 ) . V_156 ) ;
} else {
F_49 ( V_34 ) ;
}
}
F_73 ( V_140 ) ;
}
static void V_58 ( unsigned long V_11 )
{
struct V_1 * V_4 = (struct V_1 * ) V_11 ;
unsigned long V_157 ;
unsigned long V_158 ;
struct V_139 * V_140 , * V_50 ;
if ( ! F_86 ( & V_159 ) ) {
F_87 ( & V_4 -> V_57 , V_160 + V_161 / 10 ) ;
return;
}
if ( F_88 ( & V_4 -> V_56 ) )
goto V_162;
V_157 = V_160 ;
V_158 = 10 * V_161 ;
F_21 (c, next, &mrt->mfc_unres_queue, list) {
if ( F_89 ( V_140 -> V_146 . V_147 . V_158 , V_157 ) ) {
unsigned long V_163 = V_140 -> V_146 . V_147 . V_158 - V_157 ;
if ( V_163 < V_158 )
V_158 = V_163 ;
continue;
}
F_22 ( & V_140 -> V_51 ) ;
F_90 ( V_4 , V_140 , V_164 ) ;
F_75 ( V_4 , V_140 ) ;
}
if ( ! F_88 ( & V_4 -> V_56 ) )
F_87 ( & V_4 -> V_57 , V_160 + V_158 ) ;
V_162:
F_91 ( & V_159 ) ;
}
static void F_92 ( struct V_1 * V_4 , struct V_139 * V_165 ,
unsigned char * V_166 )
{
int V_125 ;
V_165 -> V_146 . V_9 . V_167 = V_168 ;
V_165 -> V_146 . V_9 . V_130 = 0 ;
memset ( V_165 -> V_146 . V_9 . V_166 , 255 , V_168 ) ;
for ( V_125 = 0 ; V_125 < V_4 -> V_130 ; V_125 ++ ) {
if ( F_64 ( V_4 , V_125 ) &&
V_166 [ V_125 ] && V_166 [ V_125 ] < 255 ) {
V_165 -> V_146 . V_9 . V_166 [ V_125 ] = V_166 [ V_125 ] ;
if ( V_165 -> V_146 . V_9 . V_167 > V_125 )
V_165 -> V_146 . V_9 . V_167 = V_125 ;
if ( V_165 -> V_146 . V_9 . V_130 <= V_125 )
V_165 -> V_146 . V_9 . V_130 = V_125 + 1 ;
}
}
}
static int F_93 ( struct V_2 * V_2 , struct V_1 * V_4 ,
struct V_62 * V_169 , int V_170 )
{
int V_125 = V_169 -> V_81 ;
struct V_129 * V_63 = & V_4 -> V_132 [ V_125 ] ;
struct V_60 * V_61 ;
struct V_90 * V_91 ;
int V_7 ;
if ( F_64 ( V_4 , V_125 ) )
return - V_171 ;
switch ( V_169 -> V_172 ) {
#ifdef F_27
case V_137 :
if ( V_4 -> V_59 >= 0 )
return - V_171 ;
V_61 = F_54 ( V_2 , V_4 ) ;
if ( ! V_61 )
return - V_173 ;
V_7 = F_65 ( V_61 , 1 ) ;
if ( V_7 ) {
F_47 ( V_61 ) ;
F_69 ( V_61 ) ;
return V_7 ;
}
break;
#endif
case V_136 :
V_61 = F_38 ( V_2 , V_169 ) ;
if ( ! V_61 )
return - V_173 ;
V_7 = F_65 ( V_61 , 1 ) ;
if ( V_7 ) {
F_32 ( V_61 , V_169 ) ;
F_69 ( V_61 ) ;
return V_7 ;
}
break;
case V_174 :
case 0 :
if ( V_169 -> V_172 == V_174 ) {
V_61 = F_94 ( V_2 , V_169 -> V_175 ) ;
if ( V_61 && F_39 ( V_61 ) == NULL ) {
F_69 ( V_61 ) ;
return - V_131 ;
}
} else {
V_61 = F_95 ( V_2 , V_169 -> V_75 . V_73 ) ;
}
if ( ! V_61 )
return - V_131 ;
V_7 = F_65 ( V_61 , 1 ) ;
if ( V_7 ) {
F_69 ( V_61 ) ;
return V_7 ;
}
break;
default:
return - V_28 ;
}
V_91 = F_39 ( V_61 ) ;
if ( ! V_91 ) {
F_69 ( V_61 ) ;
return - V_131 ;
}
F_42 ( V_91 -> V_97 , V_134 ) ++ ;
F_66 ( V_2 , V_135 , V_61 -> V_101 ,
& V_91 -> V_97 ) ;
F_67 ( V_91 ) ;
V_63 -> V_176 = V_169 -> V_177 ;
V_63 -> V_178 = V_169 -> V_75 . V_73 ;
V_63 -> V_179 = V_169 -> V_72 . V_73 ;
V_63 -> V_13 = V_169 -> V_172 ;
if ( ! V_170 )
V_63 -> V_13 |= V_180 ;
V_63 -> V_181 = V_169 -> V_182 ;
V_63 -> V_183 = 0 ;
V_63 -> V_184 = 0 ;
V_63 -> V_185 = 0 ;
V_63 -> V_186 = 0 ;
V_63 -> V_187 = V_61 -> V_101 ;
if ( V_63 -> V_13 & ( V_136 | V_137 ) )
V_63 -> V_187 = V_61 -> V_124 ;
F_62 ( & V_106 ) ;
V_63 -> V_61 = V_61 ;
#ifdef F_27
if ( V_63 -> V_13 & V_137 )
V_4 -> V_59 = V_125 ;
#endif
if ( V_125 + 1 > V_4 -> V_130 )
V_4 -> V_130 = V_125 + 1 ;
F_63 ( & V_106 ) ;
return 0 ;
}
static struct V_139 * F_96 ( struct V_1 * V_4 ,
T_6 V_188 ,
T_6 V_189 )
{
int line = F_97 ( V_189 , V_188 ) ;
struct V_139 * V_140 ;
F_98 (c, &mrt->mfc_cache_array[line], list) {
if ( V_140 -> V_190 == V_188 && V_140 -> V_191 == V_189 )
return V_140 ;
}
return NULL ;
}
static struct V_139 * F_99 ( struct V_1 * V_4 ,
int V_125 )
{
int line = F_97 ( F_100 ( V_192 ) , F_100 ( V_192 ) ) ;
struct V_139 * V_140 ;
F_98 (c, &mrt->mfc_cache_array[line], list)
if ( V_140 -> V_190 == F_100 ( V_192 ) &&
V_140 -> V_191 == F_100 ( V_192 ) &&
V_140 -> V_146 . V_9 . V_166 [ V_125 ] < 255 )
return V_140 ;
return NULL ;
}
static struct V_139 * F_101 ( struct V_1 * V_4 ,
T_6 V_189 , int V_125 )
{
int line = F_97 ( V_189 , F_100 ( V_192 ) ) ;
struct V_139 * V_140 , * V_193 ;
if ( V_189 == F_100 ( V_192 ) )
goto V_194;
F_98 (c, &mrt->mfc_cache_array[line], list)
if ( V_140 -> V_190 == F_100 ( V_192 ) &&
V_140 -> V_191 == V_189 ) {
if ( V_140 -> V_146 . V_9 . V_166 [ V_125 ] < 255 )
return V_140 ;
V_193 = F_99 ( V_4 ,
V_140 -> V_195 ) ;
if ( V_193 && V_193 -> V_146 . V_9 . V_166 [ V_125 ] < 255 )
return V_140 ;
}
V_194:
return F_99 ( V_4 , V_125 ) ;
}
static struct V_139 * F_102 ( void )
{
struct V_139 * V_140 = F_103 ( V_142 , V_53 ) ;
if ( V_140 )
V_140 -> V_146 . V_9 . V_167 = V_168 ;
return V_140 ;
}
static struct V_139 * F_104 ( void )
{
struct V_139 * V_140 = F_103 ( V_142 , V_196 ) ;
if ( V_140 ) {
F_105 ( & V_140 -> V_146 . V_147 . V_148 ) ;
V_140 -> V_146 . V_147 . V_158 = V_160 + 10 * V_161 ;
}
return V_140 ;
}
static void F_106 ( struct V_2 * V_2 , struct V_1 * V_4 ,
struct V_139 * V_197 , struct V_139 * V_140 )
{
struct V_33 * V_34 ;
struct V_143 * V_144 ;
while ( ( V_34 = F_107 ( & V_197 -> V_146 . V_147 . V_148 ) ) ) {
if ( F_79 ( V_34 ) -> V_76 == 0 ) {
struct V_149 * V_150 = (struct V_149 * ) F_80 ( V_34 , sizeof( struct V_116 ) ) ;
if ( F_108 ( V_4 , V_34 , V_140 , F_83 ( V_150 ) ) > 0 ) {
V_150 -> V_153 = F_109 ( V_34 ) -
( V_198 * ) V_150 ;
} else {
V_150 -> V_151 = V_152 ;
V_150 -> V_153 = F_81 ( sizeof( struct V_143 ) ) ;
F_82 ( V_34 , V_150 -> V_153 ) ;
V_144 = F_83 ( V_150 ) ;
V_144 -> error = - V_199 ;
memset ( & V_144 -> V_155 , 0 , sizeof( V_144 -> V_155 ) ) ;
}
F_84 ( V_34 , V_2 , F_85 ( V_34 ) . V_156 ) ;
} else {
F_110 ( V_2 , V_4 , V_34 , V_140 , 0 ) ;
}
}
}
static int F_51 ( struct V_1 * V_4 ,
struct V_33 * V_200 , T_7 V_125 , int assert )
{
struct V_33 * V_34 ;
const int V_77 = F_111 ( V_200 ) ;
struct V_201 * V_202 ;
struct V_203 * V_155 ;
struct V_204 * V_205 ;
int V_206 ;
#ifdef F_27
if ( assert == V_111 )
V_34 = F_112 ( V_200 , sizeof( struct V_116 ) ) ;
else
#endif
V_34 = F_113 ( 128 , V_196 ) ;
if ( ! V_34 )
return - V_173 ;
#ifdef F_27
if ( assert == V_111 ) {
F_114 ( V_34 , sizeof( struct V_116 ) ) ;
F_115 ( V_34 ) ;
F_116 ( V_34 ) ;
V_155 = (struct V_203 * ) F_117 ( V_34 ) ;
memcpy ( V_155 , F_117 ( V_200 ) , sizeof( struct V_116 ) ) ;
V_155 -> V_207 = V_111 ;
V_155 -> V_208 = 0 ;
V_155 -> V_209 = V_4 -> V_59 ;
F_79 ( V_34 ) -> V_77 = sizeof( struct V_116 ) >> 2 ;
F_79 ( V_34 ) -> V_210 = F_118 ( F_119 ( F_79 ( V_200 ) -> V_210 ) +
sizeof( struct V_116 ) ) ;
} else
#endif
{
F_120 ( V_34 , V_34 -> V_109 ) ;
F_121 ( V_34 , V_77 ) ;
F_122 ( V_34 , V_200 -> V_211 , V_77 ) ;
F_79 ( V_34 ) -> V_78 = 0 ;
V_155 = (struct V_203 * ) F_117 ( V_34 ) ;
V_155 -> V_209 = V_125 ;
F_123 ( V_34 , F_124 ( F_125 ( V_200 ) ) ) ;
V_202 = (struct V_201 * ) F_121 ( V_34 , sizeof( struct V_201 ) ) ;
V_202 -> type =
V_155 -> V_207 = assert ;
V_202 -> V_212 = 0 ;
F_79 ( V_34 ) -> V_210 = F_118 ( V_34 -> V_109 ) ;
V_34 -> V_213 = V_34 -> V_214 ;
}
F_58 () ;
V_205 = F_126 ( V_4 -> V_205 ) ;
if ( V_205 == NULL ) {
F_60 () ;
F_49 ( V_34 ) ;
return - V_28 ;
}
V_206 = F_127 ( V_205 , V_34 ) ;
F_60 () ;
if ( V_206 < 0 ) {
F_128 ( L_5 ) ;
F_49 ( V_34 ) ;
}
return V_206 ;
}
static int
F_129 ( struct V_1 * V_4 , T_7 V_125 , struct V_33 * V_34 )
{
bool V_215 = false ;
int V_7 ;
struct V_139 * V_140 ;
const struct V_116 * V_70 = F_79 ( V_34 ) ;
F_130 ( & V_159 ) ;
F_131 (c, &mrt->mfc_unres_queue, list) {
if ( V_140 -> V_191 == V_70 -> V_71 &&
V_140 -> V_190 == V_70 -> V_74 ) {
V_215 = true ;
break;
}
}
if ( ! V_215 ) {
if ( F_132 ( & V_4 -> V_145 ) >= 10 ||
( V_140 = F_104 () ) == NULL ) {
F_133 ( & V_159 ) ;
F_49 ( V_34 ) ;
return - V_173 ;
}
V_140 -> V_195 = - 1 ;
V_140 -> V_190 = V_70 -> V_74 ;
V_140 -> V_191 = V_70 -> V_71 ;
V_7 = F_51 ( V_4 , V_34 , V_125 , V_216 ) ;
if ( V_7 < 0 ) {
F_133 ( & V_159 ) ;
F_73 ( V_140 ) ;
F_49 ( V_34 ) ;
return V_7 ;
}
F_134 ( & V_4 -> V_145 ) ;
F_135 ( & V_140 -> V_51 , & V_4 -> V_56 ) ;
F_90 ( V_4 , V_140 , V_217 ) ;
if ( F_132 ( & V_4 -> V_145 ) == 1 )
F_87 ( & V_4 -> V_57 , V_140 -> V_146 . V_147 . V_158 ) ;
}
if ( V_140 -> V_146 . V_147 . V_148 . V_218 > 3 ) {
F_49 ( V_34 ) ;
V_7 = - V_173 ;
} else {
F_136 ( & V_140 -> V_146 . V_147 . V_148 , V_34 ) ;
V_7 = 0 ;
}
F_133 ( & V_159 ) ;
return V_7 ;
}
static int F_137 ( struct V_1 * V_4 , struct V_219 * V_220 , int V_221 )
{
int line ;
struct V_139 * V_140 , * V_50 ;
line = F_97 ( V_220 -> V_222 . V_73 , V_220 -> V_223 . V_73 ) ;
F_21 (c, next, &mrt->mfc_cache_array[line], list) {
if ( V_140 -> V_190 == V_220 -> V_223 . V_73 &&
V_140 -> V_191 == V_220 -> V_222 . V_73 &&
( V_221 == - 1 || V_221 == V_140 -> V_195 ) ) {
F_138 ( & V_140 -> V_51 ) ;
F_90 ( V_4 , V_140 , V_164 ) ;
F_73 ( V_140 ) ;
return 0 ;
}
}
return - V_224 ;
}
static int F_139 ( struct V_2 * V_2 , struct V_1 * V_4 ,
struct V_219 * V_220 , int V_170 , int V_221 )
{
bool V_215 = false ;
int line ;
struct V_139 * V_197 , * V_140 ;
if ( V_220 -> V_225 >= V_168 )
return - V_226 ;
line = F_97 ( V_220 -> V_222 . V_73 , V_220 -> V_223 . V_73 ) ;
F_131 (c, &mrt->mfc_cache_array[line], list) {
if ( V_140 -> V_190 == V_220 -> V_223 . V_73 &&
V_140 -> V_191 == V_220 -> V_222 . V_73 &&
( V_221 == - 1 || V_221 == V_140 -> V_195 ) ) {
V_215 = true ;
break;
}
}
if ( V_215 ) {
F_62 ( & V_106 ) ;
V_140 -> V_195 = V_220 -> V_225 ;
F_92 ( V_4 , V_140 , V_220 -> V_227 ) ;
if ( ! V_170 )
V_140 -> V_228 |= V_229 ;
F_63 ( & V_106 ) ;
F_90 ( V_4 , V_140 , V_217 ) ;
return 0 ;
}
if ( V_220 -> V_222 . V_73 != F_100 ( V_192 ) &&
! F_140 ( V_220 -> V_222 . V_73 ) )
return - V_28 ;
V_140 = F_102 () ;
if ( V_140 == NULL )
return - V_47 ;
V_140 -> V_190 = V_220 -> V_223 . V_73 ;
V_140 -> V_191 = V_220 -> V_222 . V_73 ;
V_140 -> V_195 = V_220 -> V_225 ;
F_92 ( V_4 , V_140 , V_220 -> V_227 ) ;
if ( ! V_170 )
V_140 -> V_228 |= V_229 ;
F_141 ( & V_140 -> V_51 , & V_4 -> V_55 [ line ] ) ;
V_215 = false ;
F_130 ( & V_159 ) ;
F_131 (uc, &mrt->mfc_unres_queue, list) {
if ( V_197 -> V_190 == V_140 -> V_190 &&
V_197 -> V_191 == V_140 -> V_191 ) {
F_22 ( & V_197 -> V_51 ) ;
F_77 ( & V_4 -> V_145 ) ;
V_215 = true ;
break;
}
}
if ( F_88 ( & V_4 -> V_56 ) )
F_142 ( & V_4 -> V_57 ) ;
F_133 ( & V_159 ) ;
if ( V_215 ) {
F_106 ( V_2 , V_4 , V_197 , V_140 ) ;
F_73 ( V_197 ) ;
}
F_90 ( V_4 , V_140 , V_217 ) ;
return 0 ;
}
static void F_31 ( struct V_1 * V_4 )
{
int V_52 ;
F_143 ( V_51 ) ;
struct V_139 * V_140 , * V_50 ;
for ( V_52 = 0 ; V_52 < V_4 -> V_130 ; V_52 ++ ) {
if ( ! ( V_4 -> V_132 [ V_52 ] . V_13 & V_180 ) )
F_61 ( V_4 , V_52 , 0 , & V_51 ) ;
}
F_144 ( & V_51 ) ;
for ( V_52 = 0 ; V_52 < V_54 ; V_52 ++ ) {
F_21 (c, next, &mrt->mfc_cache_array[i], list) {
if ( V_140 -> V_228 & V_229 )
continue;
F_138 ( & V_140 -> V_51 ) ;
F_90 ( V_4 , V_140 , V_164 ) ;
F_73 ( V_140 ) ;
}
}
if ( F_132 ( & V_4 -> V_145 ) != 0 ) {
F_130 ( & V_159 ) ;
F_21 (c, next, &mrt->mfc_unres_queue, list) {
F_22 ( & V_140 -> V_51 ) ;
F_90 ( V_4 , V_140 , V_164 ) ;
F_75 ( V_4 , V_140 ) ;
}
F_133 ( & V_159 ) ;
}
}
static void F_145 ( struct V_204 * V_230 )
{
struct V_2 * V_2 = F_146 ( V_230 ) ;
struct V_1 * V_4 ;
F_46 () ;
F_2 (mrt, net) {
if ( V_230 == F_147 ( V_4 -> V_205 ) ) {
F_148 ( V_2 , V_134 ) -- ;
F_66 ( V_2 , V_135 ,
V_231 ,
V_2 -> V_15 . V_232 ) ;
F_149 ( V_4 -> V_205 , NULL ) ;
F_31 ( V_4 ) ;
}
}
F_45 () ;
}
int F_150 ( struct V_204 * V_230 , int V_233 , char V_85 * V_234 , unsigned int V_235 )
{
int V_206 , V_221 = 0 ;
struct V_62 V_236 ;
struct V_219 V_220 ;
struct V_2 * V_2 = F_146 ( V_230 ) ;
struct V_1 * V_4 ;
if ( V_230 -> V_237 != V_238 ||
F_151 ( V_230 ) -> V_239 != V_240 )
return - V_93 ;
V_4 = F_1 ( V_2 , F_152 ( V_230 ) -> V_241 ? : V_46 ) ;
if ( V_4 == NULL )
return - V_224 ;
if ( V_233 != V_242 ) {
if ( V_230 != F_153 ( V_4 -> V_205 ) &&
! F_154 ( V_2 -> V_243 , V_244 ) )
return - V_26 ;
}
switch ( V_233 ) {
case V_242 :
if ( V_235 != sizeof( int ) )
return - V_28 ;
F_46 () ;
if ( F_147 ( V_4 -> V_205 ) ) {
F_45 () ;
return - V_171 ;
}
V_206 = F_155 ( V_230 , 1 , F_145 ) ;
if ( V_206 == 0 ) {
F_156 ( V_4 -> V_205 , V_230 ) ;
F_148 ( V_2 , V_134 ) ++ ;
F_66 ( V_2 , V_135 ,
V_231 ,
V_2 -> V_15 . V_232 ) ;
}
F_45 () ;
return V_206 ;
case V_245 :
if ( V_230 != F_153 ( V_4 -> V_205 ) )
return - V_26 ;
return F_155 ( V_230 , 0 , NULL ) ;
case V_246 :
case V_247 :
if ( V_235 != sizeof( V_236 ) )
return - V_28 ;
if ( F_157 ( & V_236 , V_234 , sizeof( V_236 ) ) )
return - V_248 ;
if ( V_236 . V_81 >= V_168 )
return - V_226 ;
F_46 () ;
if ( V_233 == V_246 ) {
V_206 = F_93 ( V_2 , V_4 , & V_236 ,
V_230 == F_147 ( V_4 -> V_205 ) ) ;
} else {
V_206 = F_61 ( V_4 , V_236 . V_81 , 0 , NULL ) ;
}
F_45 () ;
return V_206 ;
case V_249 :
case V_250 :
V_221 = - 1 ;
case V_251 :
case V_252 :
if ( V_235 != sizeof( V_220 ) )
return - V_28 ;
if ( F_157 ( & V_220 , V_234 , sizeof( V_220 ) ) )
return - V_248 ;
if ( V_221 == 0 )
V_221 = V_220 . V_225 ;
F_46 () ;
if ( V_233 == V_250 || V_233 == V_252 )
V_206 = F_137 ( V_4 , & V_220 , V_221 ) ;
else
V_206 = F_139 ( V_2 , V_4 , & V_220 ,
V_230 == F_147 ( V_4 -> V_205 ) ,
V_221 ) ;
F_45 () ;
return V_206 ;
case V_253 :
{
int V_63 ;
if ( V_235 != sizeof( V_63 ) )
return - V_28 ;
if ( F_158 ( V_63 , ( int V_85 * ) V_234 ) )
return - V_248 ;
V_4 -> V_254 = V_63 ;
return 0 ;
}
#ifdef F_27
case V_255 :
{
int V_63 ;
if ( V_235 != sizeof( V_63 ) )
return - V_28 ;
if ( F_158 ( V_63 , ( int V_85 * ) V_234 ) )
return - V_248 ;
V_63 = ! ! V_63 ;
F_46 () ;
V_206 = 0 ;
if ( V_63 != V_4 -> V_256 ) {
V_4 -> V_256 = V_63 ;
V_4 -> V_254 = V_63 ;
}
F_45 () ;
return V_206 ;
}
#endif
#ifdef F_28
case V_257 :
{
T_1 V_63 ;
if ( V_235 != sizeof( T_1 ) )
return - V_28 ;
if ( F_158 ( V_63 , ( T_1 V_85 * ) V_234 ) )
return - V_248 ;
if ( V_63 != V_46 && V_63 >= 1000000000 )
return - V_28 ;
F_46 () ;
V_206 = 0 ;
if ( V_230 == F_147 ( V_4 -> V_205 ) ) {
V_206 = - V_258 ;
} else {
if ( ! F_16 ( V_2 , V_63 ) )
V_206 = - V_47 ;
else
F_152 ( V_230 ) -> V_241 = V_63 ;
}
F_45 () ;
return V_206 ;
}
#endif
default:
return - V_259 ;
}
}
int F_159 ( struct V_204 * V_230 , int V_233 , char V_85 * V_234 , int V_85 * V_235 )
{
int V_260 ;
int V_261 ;
struct V_2 * V_2 = F_146 ( V_230 ) ;
struct V_1 * V_4 ;
if ( V_230 -> V_237 != V_238 ||
F_151 ( V_230 ) -> V_239 != V_240 )
return - V_93 ;
V_4 = F_1 ( V_2 , F_152 ( V_230 ) -> V_241 ? : V_46 ) ;
if ( V_4 == NULL )
return - V_224 ;
if ( V_233 != V_262 &&
#ifdef F_27
V_233 != V_255 &&
#endif
V_233 != V_253 )
return - V_259 ;
if ( F_158 ( V_260 , V_235 ) )
return - V_248 ;
V_260 = F_160 (unsigned int, olr, sizeof(int)) ;
if ( V_260 < 0 )
return - V_28 ;
if ( F_161 ( V_260 , V_235 ) )
return - V_248 ;
if ( V_233 == V_262 )
V_261 = 0x0305 ;
#ifdef F_27
else if ( V_233 == V_255 )
V_261 = V_4 -> V_256 ;
#endif
else
V_261 = V_4 -> V_254 ;
if ( F_162 ( V_234 , & V_261 , V_260 ) )
return - V_248 ;
return 0 ;
}
int F_163 ( struct V_204 * V_230 , int V_263 , void V_85 * V_11 )
{
struct V_264 V_265 ;
struct V_266 V_267 ;
struct V_129 * V_236 ;
struct V_139 * V_140 ;
struct V_2 * V_2 = F_146 ( V_230 ) ;
struct V_1 * V_4 ;
V_4 = F_1 ( V_2 , F_152 ( V_230 ) -> V_241 ? : V_46 ) ;
if ( V_4 == NULL )
return - V_224 ;
switch ( V_263 ) {
case V_268 :
if ( F_157 ( & V_267 , V_11 , sizeof( V_267 ) ) )
return - V_248 ;
if ( V_267 . V_125 >= V_4 -> V_130 )
return - V_28 ;
F_50 ( & V_106 ) ;
V_236 = & V_4 -> V_132 [ V_267 . V_125 ] ;
if ( F_64 ( V_4 , V_267 . V_125 ) ) {
V_267 . V_269 = V_236 -> V_185 ;
V_267 . V_270 = V_236 -> V_186 ;
V_267 . V_271 = V_236 -> V_183 ;
V_267 . V_272 = V_236 -> V_184 ;
F_52 ( & V_106 ) ;
if ( F_162 ( V_11 , & V_267 , sizeof( V_267 ) ) )
return - V_248 ;
return 0 ;
}
F_52 ( & V_106 ) ;
return - V_131 ;
case V_273 :
if ( F_157 ( & V_265 , V_11 , sizeof( V_265 ) ) )
return - V_248 ;
F_58 () ;
V_140 = F_96 ( V_4 , V_265 . V_274 . V_73 , V_265 . V_275 . V_73 ) ;
if ( V_140 ) {
V_265 . V_276 = V_140 -> V_146 . V_9 . V_200 ;
V_265 . V_277 = V_140 -> V_146 . V_9 . V_278 ;
V_265 . V_279 = V_140 -> V_146 . V_9 . V_279 ;
F_60 () ;
if ( F_162 ( V_11 , & V_265 , sizeof( V_265 ) ) )
return - V_248 ;
return 0 ;
}
F_60 () ;
return - V_131 ;
default:
return - V_280 ;
}
}
int F_164 ( struct V_204 * V_230 , unsigned int V_263 , void V_85 * V_11 )
{
struct V_281 V_265 ;
struct V_282 V_267 ;
struct V_129 * V_236 ;
struct V_139 * V_140 ;
struct V_2 * V_2 = F_146 ( V_230 ) ;
struct V_1 * V_4 ;
V_4 = F_1 ( V_2 , F_152 ( V_230 ) -> V_241 ? : V_46 ) ;
if ( V_4 == NULL )
return - V_224 ;
switch ( V_263 ) {
case V_268 :
if ( F_157 ( & V_267 , V_11 , sizeof( V_267 ) ) )
return - V_248 ;
if ( V_267 . V_125 >= V_4 -> V_130 )
return - V_28 ;
F_50 ( & V_106 ) ;
V_236 = & V_4 -> V_132 [ V_267 . V_125 ] ;
if ( F_64 ( V_4 , V_267 . V_125 ) ) {
V_267 . V_269 = V_236 -> V_185 ;
V_267 . V_270 = V_236 -> V_186 ;
V_267 . V_271 = V_236 -> V_183 ;
V_267 . V_272 = V_236 -> V_184 ;
F_52 ( & V_106 ) ;
if ( F_162 ( V_11 , & V_267 , sizeof( V_267 ) ) )
return - V_248 ;
return 0 ;
}
F_52 ( & V_106 ) ;
return - V_131 ;
case V_273 :
if ( F_157 ( & V_265 , V_11 , sizeof( V_265 ) ) )
return - V_248 ;
F_58 () ;
V_140 = F_96 ( V_4 , V_265 . V_274 . V_73 , V_265 . V_275 . V_73 ) ;
if ( V_140 ) {
V_265 . V_276 = V_140 -> V_146 . V_9 . V_200 ;
V_265 . V_277 = V_140 -> V_146 . V_9 . V_278 ;
V_265 . V_279 = V_140 -> V_146 . V_9 . V_279 ;
F_60 () ;
if ( F_162 ( V_11 , & V_265 , sizeof( V_265 ) ) )
return - V_248 ;
return 0 ;
}
F_60 () ;
return - V_131 ;
default:
return - V_280 ;
}
}
static int F_165 ( struct V_283 * V_284 , unsigned long V_285 , void * V_286 )
{
struct V_60 * V_61 = F_166 ( V_286 ) ;
struct V_2 * V_2 = F_33 ( V_61 ) ;
struct V_1 * V_4 ;
struct V_129 * V_63 ;
int V_287 ;
if ( V_285 != V_288 )
return V_289 ;
F_2 (mrt, net) {
V_63 = & V_4 -> V_132 [ 0 ] ;
for ( V_287 = 0 ; V_287 < V_4 -> V_130 ; V_287 ++ , V_63 ++ ) {
if ( V_63 -> V_61 == V_61 )
F_61 ( V_4 , V_287 , 1 , NULL ) ;
}
}
return V_289 ;
}
static void F_167 ( struct V_33 * V_34 , T_6 V_74 , T_6 V_71 )
{
struct V_116 * V_70 ;
const struct V_116 * V_290 = F_79 ( V_34 ) ;
F_114 ( V_34 , sizeof( struct V_116 ) ) ;
V_34 -> V_213 = V_34 -> V_214 ;
F_115 ( V_34 ) ;
V_70 = F_79 ( V_34 ) ;
V_70 -> V_76 = 4 ;
V_70 -> V_41 = V_290 -> V_41 ;
V_70 -> V_291 = V_290 -> V_291 ;
V_70 -> V_292 = 0 ;
V_70 -> V_71 = V_71 ;
V_70 -> V_74 = V_74 ;
V_70 -> V_78 = V_79 ;
V_70 -> V_77 = 5 ;
V_70 -> V_210 = F_118 ( V_34 -> V_109 ) ;
F_168 ( V_34 , F_125 ( V_34 ) , NULL ) ;
F_169 ( V_70 ) ;
memset ( & ( F_170 ( V_34 ) -> V_293 ) , 0 , sizeof( F_170 ( V_34 ) -> V_293 ) ) ;
F_171 ( V_34 ) ;
}
static inline int F_172 ( struct V_33 * V_34 )
{
struct V_294 * V_293 = & ( F_170 ( V_34 ) -> V_293 ) ;
F_173 ( F_33 ( F_125 ( V_34 ) -> V_61 ) , V_295 ) ;
F_174 ( F_33 ( F_125 ( V_34 ) -> V_61 ) , V_296 , V_34 -> V_109 ) ;
if ( F_175 ( V_293 -> V_235 ) )
F_176 ( V_34 ) ;
return F_177 ( V_34 ) ;
}
static void F_178 ( struct V_2 * V_2 , struct V_1 * V_4 ,
struct V_33 * V_34 , struct V_139 * V_140 , int V_125 )
{
const struct V_116 * V_70 = F_79 ( V_34 ) ;
struct V_129 * V_236 = & V_4 -> V_132 [ V_125 ] ;
struct V_60 * V_61 ;
struct V_297 * V_298 ;
struct V_5 V_99 ;
int V_299 = 0 ;
if ( V_236 -> V_61 == NULL )
goto V_300;
#ifdef F_27
if ( V_236 -> V_13 & V_137 ) {
V_236 -> V_186 ++ ;
V_236 -> V_184 += V_34 -> V_109 ;
V_236 -> V_61 -> V_107 . V_108 += V_34 -> V_109 ;
V_236 -> V_61 -> V_107 . V_110 ++ ;
F_51 ( V_4 , V_34 , V_125 , V_111 ) ;
goto V_300;
}
#endif
if ( V_236 -> V_13 & V_136 ) {
V_298 = F_179 ( V_2 , & V_99 , NULL ,
V_236 -> V_179 , V_236 -> V_178 ,
0 , 0 ,
V_79 ,
F_180 ( V_70 -> V_41 ) , V_236 -> V_187 ) ;
if ( F_13 ( V_298 ) )
goto V_300;
V_299 = sizeof( struct V_116 ) ;
} else {
V_298 = F_179 ( V_2 , & V_99 , NULL , V_70 -> V_71 , 0 ,
0 , 0 ,
V_79 ,
F_180 ( V_70 -> V_41 ) , V_236 -> V_187 ) ;
if ( F_13 ( V_298 ) )
goto V_300;
}
V_61 = V_298 -> V_301 . V_61 ;
if ( V_34 -> V_109 + V_299 > F_181 ( & V_298 -> V_301 ) && ( F_119 ( V_70 -> V_292 ) & V_302 ) ) {
F_173 ( F_33 ( V_61 ) , V_303 ) ;
F_182 ( V_298 ) ;
goto V_300;
}
V_299 += F_183 ( V_61 ) + V_298 -> V_301 . V_304 ;
if ( F_184 ( V_34 , V_299 ) ) {
F_182 ( V_298 ) ;
goto V_300;
}
V_236 -> V_186 ++ ;
V_236 -> V_184 += V_34 -> V_109 ;
F_185 ( V_34 ) ;
F_123 ( V_34 , & V_298 -> V_301 ) ;
F_186 ( F_79 ( V_34 ) ) ;
if ( V_236 -> V_13 & V_136 ) {
F_167 ( V_34 , V_236 -> V_178 , V_236 -> V_179 ) ;
V_236 -> V_61 -> V_107 . V_110 ++ ;
V_236 -> V_61 -> V_107 . V_108 += V_34 -> V_109 ;
}
F_170 ( V_34 ) -> V_13 |= V_305 ;
F_187 ( V_306 , V_307 , V_34 , V_34 -> V_61 , V_61 ,
F_172 ) ;
return;
V_300:
F_49 ( V_34 ) ;
}
static int F_188 ( struct V_1 * V_4 , struct V_60 * V_61 )
{
int V_287 ;
for ( V_287 = V_4 -> V_130 - 1 ; V_287 >= 0 ; V_287 -- ) {
if ( V_4 -> V_132 [ V_287 ] . V_61 == V_61 )
break;
}
return V_287 ;
}
static void F_110 ( struct V_2 * V_2 , struct V_1 * V_4 ,
struct V_33 * V_34 , struct V_139 * V_165 ,
int V_178 )
{
int V_308 = - 1 ;
int V_236 , V_287 ;
int V_309 = F_188 ( V_4 , V_34 -> V_61 ) ;
V_236 = V_165 -> V_195 ;
V_165 -> V_146 . V_9 . V_200 ++ ;
V_165 -> V_146 . V_9 . V_278 += V_34 -> V_109 ;
if ( V_165 -> V_190 == F_100 ( V_192 ) && V_309 >= 0 ) {
struct V_139 * V_310 ;
V_310 = F_99 ( V_4 , V_236 ) ;
if ( V_310 &&
V_310 -> V_146 . V_9 . V_166 [ V_309 ] < 255 )
goto V_311;
}
if ( V_4 -> V_132 [ V_236 ] . V_61 != V_34 -> V_61 ) {
if ( F_189 ( F_190 ( V_34 ) ) ) {
goto V_312;
}
V_165 -> V_146 . V_9 . V_279 ++ ;
if ( V_309 >= 0 && V_4 -> V_254 &&
( V_4 -> V_256 ||
V_165 -> V_146 . V_9 . V_166 [ V_309 ] < 255 ) &&
F_89 ( V_160 ,
V_165 -> V_146 . V_9 . V_313 + V_314 ) ) {
V_165 -> V_146 . V_9 . V_313 = V_160 ;
F_51 ( V_4 , V_34 , V_309 , V_315 ) ;
}
goto V_312;
}
V_311:
V_4 -> V_132 [ V_236 ] . V_185 ++ ;
V_4 -> V_132 [ V_236 ] . V_183 += V_34 -> V_109 ;
if ( V_165 -> V_190 == F_100 ( V_192 ) &&
V_165 -> V_191 == F_100 ( V_192 ) ) {
if ( V_309 >= 0 &&
V_309 != V_165 -> V_195 &&
F_79 ( V_34 ) -> V_291 >
V_165 -> V_146 . V_9 . V_166 [ V_165 -> V_195 ] ) {
V_308 = V_165 -> V_195 ;
goto V_316;
}
goto V_312;
}
for ( V_287 = V_165 -> V_146 . V_9 . V_130 - 1 ;
V_287 >= V_165 -> V_146 . V_9 . V_167 ; V_287 -- ) {
if ( ( V_165 -> V_190 != F_100 ( V_192 ) ||
V_287 != V_309 ) &&
F_79 ( V_34 ) -> V_291 > V_165 -> V_146 . V_9 . V_166 [ V_287 ] ) {
if ( V_308 != - 1 ) {
struct V_33 * V_317 = F_191 ( V_34 , V_196 ) ;
if ( V_317 )
F_178 ( V_2 , V_4 , V_317 , V_165 ,
V_308 ) ;
}
V_308 = V_287 ;
}
}
V_316:
if ( V_308 != - 1 ) {
if ( V_178 ) {
struct V_33 * V_317 = F_191 ( V_34 , V_196 ) ;
if ( V_317 )
F_178 ( V_2 , V_4 , V_317 , V_165 , V_308 ) ;
} else {
F_178 ( V_2 , V_4 , V_34 , V_165 , V_308 ) ;
return;
}
}
V_312:
if ( ! V_178 )
F_49 ( V_34 ) ;
}
static struct V_1 * F_192 ( struct V_2 * V_2 , struct V_33 * V_34 )
{
struct V_297 * V_298 = F_190 ( V_34 ) ;
struct V_116 * V_70 = F_79 ( V_34 ) ;
struct V_5 V_99 = {
. V_71 = V_70 -> V_71 ,
. V_74 = V_70 -> V_74 ,
. V_318 = F_180 ( V_70 -> V_41 ) ,
. V_100 = ( F_189 ( V_298 ) ?
V_34 -> V_61 -> V_101 : 0 ) ,
. V_102 = ( F_189 ( V_298 ) ?
V_319 :
V_34 -> V_61 -> V_101 ) ,
. V_104 = V_34 -> V_105 ,
} ;
struct V_1 * V_4 ;
int V_7 ;
V_7 = F_3 ( V_2 , & V_99 , & V_4 ) ;
if ( V_7 )
return F_193 ( V_7 ) ;
return V_4 ;
}
int F_194 ( struct V_33 * V_34 )
{
struct V_139 * V_165 ;
struct V_2 * V_2 = F_33 ( V_34 -> V_61 ) ;
int V_178 = F_190 ( V_34 ) -> V_320 & V_321 ;
struct V_1 * V_4 ;
if ( F_170 ( V_34 ) -> V_13 & V_305 )
goto V_312;
V_4 = F_192 ( V_2 , V_34 ) ;
if ( F_13 ( V_4 ) ) {
F_49 ( V_34 ) ;
return F_14 ( V_4 ) ;
}
if ( ! V_178 ) {
if ( F_170 ( V_34 ) -> V_293 . V_322 ) {
if ( F_195 ( V_34 ) )
return 0 ;
} else if ( F_79 ( V_34 ) -> V_78 == V_240 ) {
struct V_204 * V_205 ;
V_205 = F_126 ( V_4 -> V_205 ) ;
if ( V_205 ) {
F_171 ( V_34 ) ;
F_196 ( V_205 , V_34 ) ;
return 0 ;
}
}
}
V_165 = F_96 ( V_4 , F_79 ( V_34 ) -> V_74 , F_79 ( V_34 ) -> V_71 ) ;
if ( V_165 == NULL ) {
int V_236 = F_188 ( V_4 , V_34 -> V_61 ) ;
if ( V_236 >= 0 )
V_165 = F_101 ( V_4 , F_79 ( V_34 ) -> V_71 ,
V_236 ) ;
}
if ( V_165 == NULL ) {
int V_236 ;
if ( V_178 ) {
struct V_33 * V_317 = F_191 ( V_34 , V_196 ) ;
F_197 ( V_34 ) ;
if ( V_317 == NULL )
return - V_173 ;
V_34 = V_317 ;
}
F_50 ( & V_106 ) ;
V_236 = F_188 ( V_4 , V_34 -> V_61 ) ;
if ( V_236 >= 0 ) {
int V_49 = F_129 ( V_4 , V_236 , V_34 ) ;
F_52 ( & V_106 ) ;
return V_49 ;
}
F_52 ( & V_106 ) ;
F_49 ( V_34 ) ;
return - V_323 ;
}
F_50 ( & V_106 ) ;
F_110 ( V_2 , V_4 , V_34 , V_165 , V_178 ) ;
F_52 ( & V_106 ) ;
if ( V_178 )
return F_197 ( V_34 ) ;
return 0 ;
V_312:
if ( V_178 )
return F_197 ( V_34 ) ;
F_49 ( V_34 ) ;
return 0 ;
}
static int F_198 ( struct V_1 * V_4 , struct V_33 * V_34 ,
unsigned int V_324 )
{
struct V_60 * V_325 = NULL ;
struct V_116 * V_299 ;
V_299 = (struct V_116 * ) ( F_199 ( V_34 ) + V_324 ) ;
if ( ! F_140 ( V_299 -> V_71 ) ||
V_299 -> V_210 == 0 ||
F_119 ( V_299 -> V_210 ) + V_324 > V_34 -> V_109 )
return 1 ;
F_50 ( & V_106 ) ;
if ( V_4 -> V_59 >= 0 )
V_325 = V_4 -> V_132 [ V_4 -> V_59 ] . V_61 ;
F_52 ( & V_106 ) ;
if ( V_325 == NULL )
return 1 ;
V_34 -> V_326 = V_34 -> V_214 ;
F_80 ( V_34 , ( V_198 * ) V_299 - V_34 -> V_211 ) ;
F_115 ( V_34 ) ;
V_34 -> V_78 = F_118 ( V_327 ) ;
V_34 -> V_328 = V_329 ;
F_200 ( V_34 , V_325 , F_33 ( V_325 ) ) ;
F_201 ( V_34 ) ;
return V_330 ;
}
int F_202 ( struct V_33 * V_34 )
{
struct V_201 * V_331 ;
struct V_2 * V_2 = F_33 ( V_34 -> V_61 ) ;
struct V_1 * V_4 ;
if ( ! F_203 ( V_34 , sizeof( * V_331 ) + sizeof( struct V_116 ) ) )
goto V_332;
V_331 = F_204 ( V_34 ) ;
V_4 = F_192 ( V_2 , V_34 ) ;
if ( F_13 ( V_4 ) )
goto V_332;
if ( ! V_4 -> V_256 ||
V_331 -> V_333 != V_334 || V_331 -> V_212 != V_335 )
goto V_332;
if ( F_198 ( V_4 , V_34 , sizeof( * V_331 ) ) ) {
V_332:
F_49 ( V_34 ) ;
}
return 0 ;
}
static int F_205 ( struct V_33 * V_34 )
{
struct V_336 * V_331 ;
struct V_2 * V_2 = F_33 ( V_34 -> V_61 ) ;
struct V_1 * V_4 ;
if ( ! F_203 ( V_34 , sizeof( * V_331 ) + sizeof( struct V_116 ) ) )
goto V_332;
V_331 = (struct V_336 * ) F_199 ( V_34 ) ;
if ( V_331 -> type != ( ( V_337 << 4 ) | ( V_338 ) ) ||
( V_331 -> V_13 & V_339 ) ||
( F_206 ( ( void * ) V_331 , sizeof( * V_331 ) ) != 0 &&
F_207 ( F_208 ( V_34 , 0 , V_34 -> V_109 , 0 ) ) ) )
goto V_332;
V_4 = F_192 ( V_2 , V_34 ) ;
if ( F_13 ( V_4 ) )
goto V_332;
if ( F_198 ( V_4 , V_34 , sizeof( * V_331 ) ) ) {
V_332:
F_49 ( V_34 ) ;
}
return 0 ;
}
static int F_108 ( struct V_1 * V_4 , struct V_33 * V_34 ,
struct V_139 * V_140 , struct V_340 * V_341 )
{
int V_287 ;
struct V_342 * V_343 ;
struct V_37 * V_344 ;
struct V_345 V_346 ;
if ( V_140 -> V_195 >= V_168 )
return - V_224 ;
if ( F_64 ( V_4 , V_140 -> V_195 ) &&
F_209 ( V_34 , V_347 , V_4 -> V_132 [ V_140 -> V_195 ] . V_61 -> V_101 ) < 0 )
return - V_199 ;
if ( ! ( V_344 = F_210 ( V_34 , V_348 ) ) )
return - V_199 ;
for ( V_287 = V_140 -> V_146 . V_9 . V_167 ; V_287 < V_140 -> V_146 . V_9 . V_130 ; V_287 ++ ) {
if ( F_64 ( V_4 , V_287 ) && V_140 -> V_146 . V_9 . V_166 [ V_287 ] < 255 ) {
if ( ! ( V_343 = F_211 ( V_34 , sizeof( * V_343 ) ) ) ) {
F_212 ( V_34 , V_344 ) ;
return - V_199 ;
}
V_343 -> V_349 = 0 ;
V_343 -> V_350 = V_140 -> V_146 . V_9 . V_166 [ V_287 ] ;
V_343 -> V_351 = V_4 -> V_132 [ V_287 ] . V_61 -> V_101 ;
V_343 -> V_352 = sizeof( * V_343 ) ;
}
}
F_213 ( V_34 , V_344 ) ;
V_346 . V_353 = V_140 -> V_146 . V_9 . V_200 ;
V_346 . V_354 = V_140 -> V_146 . V_9 . V_278 ;
V_346 . V_355 = V_140 -> V_146 . V_9 . V_279 ;
if ( F_214 ( V_34 , V_356 , sizeof( V_346 ) , & V_346 ) < 0 )
return - V_199 ;
V_341 -> V_357 = V_358 ;
return 1 ;
}
int F_215 ( struct V_2 * V_2 , struct V_33 * V_34 ,
T_6 V_74 , T_6 V_71 ,
struct V_340 * V_341 , int V_359 )
{
struct V_139 * V_165 ;
struct V_1 * V_4 ;
int V_7 ;
V_4 = F_1 ( V_2 , V_46 ) ;
if ( V_4 == NULL )
return - V_224 ;
F_58 () ;
V_165 = F_96 ( V_4 , V_74 , V_71 ) ;
if ( V_165 == NULL && V_34 -> V_61 ) {
int V_236 = F_188 ( V_4 , V_34 -> V_61 ) ;
if ( V_236 >= 0 )
V_165 = F_101 ( V_4 , V_71 , V_236 ) ;
}
if ( V_165 == NULL ) {
struct V_33 * V_317 ;
struct V_116 * V_70 ;
struct V_60 * V_61 ;
int V_236 = - 1 ;
if ( V_359 ) {
F_60 () ;
return - V_31 ;
}
V_61 = V_34 -> V_61 ;
F_50 ( & V_106 ) ;
if ( V_61 )
V_236 = F_188 ( V_4 , V_61 ) ;
if ( V_236 < 0 ) {
F_52 ( & V_106 ) ;
F_60 () ;
return - V_323 ;
}
V_317 = F_191 ( V_34 , V_196 ) ;
if ( ! V_317 ) {
F_52 ( & V_106 ) ;
F_60 () ;
return - V_47 ;
}
F_114 ( V_317 , sizeof( struct V_116 ) ) ;
F_115 ( V_317 ) ;
V_70 = F_79 ( V_317 ) ;
V_70 -> V_77 = sizeof( struct V_116 ) >> 2 ;
V_70 -> V_74 = V_74 ;
V_70 -> V_71 = V_71 ;
V_70 -> V_76 = 0 ;
V_7 = F_129 ( V_4 , V_236 , V_317 ) ;
F_52 ( & V_106 ) ;
F_60 () ;
return V_7 ;
}
F_50 ( & V_106 ) ;
if ( ! V_359 && ( V_341 -> V_360 & V_361 ) )
V_165 -> V_228 |= V_362 ;
V_7 = F_108 ( V_4 , V_34 , V_165 , V_341 ) ;
F_52 ( & V_106 ) ;
F_60 () ;
return V_7 ;
}
static int F_216 ( struct V_1 * V_4 , struct V_33 * V_34 ,
T_1 V_156 , T_1 V_363 , struct V_139 * V_140 , int V_263 ,
int V_13 )
{
struct V_149 * V_150 ;
struct V_340 * V_341 ;
int V_7 ;
V_150 = F_217 ( V_34 , V_156 , V_363 , V_263 , sizeof( * V_341 ) , V_13 ) ;
if ( V_150 == NULL )
return - V_199 ;
V_341 = F_83 ( V_150 ) ;
V_341 -> V_364 = V_365 ;
V_341 -> V_366 = 32 ;
V_341 -> V_367 = 32 ;
V_341 -> V_368 = 0 ;
V_341 -> V_369 = V_4 -> V_3 ;
if ( F_209 ( V_34 , V_370 , V_4 -> V_3 ) )
goto V_371;
V_341 -> V_357 = V_358 ;
V_341 -> V_372 = V_373 ;
if ( V_140 -> V_228 & V_229 )
V_341 -> V_374 = V_375 ;
else
V_341 -> V_374 = V_376 ;
V_341 -> V_360 = 0 ;
if ( F_218 ( V_34 , V_377 , V_140 -> V_190 ) ||
F_218 ( V_34 , V_378 , V_140 -> V_191 ) )
goto V_371;
V_7 = F_108 ( V_4 , V_34 , V_140 , V_341 ) ;
if ( V_7 < 0 && V_7 != - V_224 )
goto V_371;
return F_219 ( V_34 , V_150 ) ;
V_371:
F_220 ( V_34 , V_150 ) ;
return - V_199 ;
}
static T_8 F_221 ( bool V_148 , int V_130 )
{
T_8 V_109 =
F_222 ( sizeof( struct V_340 ) )
+ F_223 ( 4 )
+ F_223 ( 4 )
+ F_223 ( 4 )
;
if ( ! V_148 )
V_109 = V_109
+ F_223 ( 4 )
+ F_223 ( 0 )
+ V_130 * F_224 ( sizeof( struct V_342 ) )
+ F_223 ( sizeof( struct V_345 ) )
;
return V_109 ;
}
static void F_90 ( struct V_1 * V_4 , struct V_139 * V_220 ,
int V_263 )
{
struct V_2 * V_2 = F_76 ( & V_4 -> V_2 ) ;
struct V_33 * V_34 ;
int V_7 = - V_173 ;
V_34 = F_225 ( F_221 ( V_220 -> V_195 >= V_168 , V_4 -> V_130 ) ,
V_196 ) ;
if ( V_34 == NULL )
goto V_379;
V_7 = F_216 ( V_4 , V_34 , 0 , 0 , V_220 , V_263 , 0 ) ;
if ( V_7 < 0 )
goto V_379;
F_226 ( V_34 , V_2 , 0 , V_380 , NULL , V_196 ) ;
return;
V_379:
F_49 ( V_34 ) ;
if ( V_7 < 0 )
F_227 ( V_2 , V_380 , V_7 ) ;
}
static int F_228 ( struct V_33 * V_34 , struct V_381 * V_382 )
{
struct V_2 * V_2 = F_146 ( V_34 -> V_230 ) ;
struct V_1 * V_4 ;
struct V_139 * V_220 ;
unsigned int V_383 = 0 , V_384 ;
unsigned int V_385 = 0 , V_386 ;
unsigned int V_144 = 0 , V_387 ;
V_384 = V_382 -> args [ 0 ] ;
V_386 = V_382 -> args [ 1 ] ;
V_387 = V_382 -> args [ 2 ] ;
F_58 () ;
F_2 (mrt, net) {
if ( V_383 < V_384 )
goto V_388;
if ( V_383 > V_384 )
V_386 = 0 ;
for ( V_385 = V_386 ; V_385 < V_54 ; V_385 ++ ) {
F_98 (mfc, &mrt->mfc_cache_array[h], list) {
if ( V_144 < V_387 )
goto V_389;
if ( F_216 ( V_4 , V_34 ,
F_85 ( V_382 -> V_34 ) . V_156 ,
V_382 -> V_150 -> V_390 ,
V_220 , V_217 ,
V_391 ) < 0 )
goto V_392;
V_389:
V_144 ++ ;
}
V_144 = V_387 = 0 ;
}
F_130 ( & V_159 ) ;
F_131 (mfc, &mrt->mfc_unres_queue, list) {
if ( V_144 < V_387 )
goto V_393;
if ( F_216 ( V_4 , V_34 ,
F_85 ( V_382 -> V_34 ) . V_156 ,
V_382 -> V_150 -> V_390 ,
V_220 , V_217 ,
V_391 ) < 0 ) {
F_133 ( & V_159 ) ;
goto V_392;
}
V_393:
V_144 ++ ;
}
F_133 ( & V_159 ) ;
V_144 = V_387 = 0 ;
V_386 = 0 ;
V_388:
V_383 ++ ;
}
V_392:
F_60 () ;
V_382 -> args [ 2 ] = V_144 ;
V_382 -> args [ 1 ] = V_385 ;
V_382 -> args [ 0 ] = V_383 ;
return V_34 -> V_109 ;
}
static struct V_129 * F_229 ( struct V_2 * V_2 ,
struct V_394 * V_395 ,
T_9 V_396 )
{
struct V_1 * V_4 = V_395 -> V_4 ;
for ( V_395 -> V_287 = 0 ; V_395 -> V_287 < V_4 -> V_130 ; ++ V_395 -> V_287 ) {
if ( ! F_64 ( V_4 , V_395 -> V_287 ) )
continue;
if ( V_396 -- == 0 )
return & V_4 -> V_132 [ V_395 -> V_287 ] ;
}
return NULL ;
}
static void * F_230 ( struct V_397 * V_363 , T_9 * V_396 )
__acquires( V_106 )
{
struct V_394 * V_395 = V_363 -> V_398 ;
struct V_2 * V_2 = F_231 ( V_363 ) ;
struct V_1 * V_4 ;
V_4 = F_1 ( V_2 , V_46 ) ;
if ( V_4 == NULL )
return F_193 ( - V_224 ) ;
V_395 -> V_4 = V_4 ;
F_50 ( & V_106 ) ;
return * V_396 ? F_229 ( V_2 , V_363 -> V_398 , * V_396 - 1 )
: V_399 ;
}
static void * F_232 ( struct V_397 * V_363 , void * V_63 , T_9 * V_396 )
{
struct V_394 * V_395 = V_363 -> V_398 ;
struct V_2 * V_2 = F_231 ( V_363 ) ;
struct V_1 * V_4 = V_395 -> V_4 ;
++ * V_396 ;
if ( V_63 == V_399 )
return F_229 ( V_2 , V_395 , 0 ) ;
while ( ++ V_395 -> V_287 < V_4 -> V_130 ) {
if ( ! F_64 ( V_4 , V_395 -> V_287 ) )
continue;
return & V_4 -> V_132 [ V_395 -> V_287 ] ;
}
return NULL ;
}
static void F_233 ( struct V_397 * V_363 , void * V_63 )
__releases( V_106 )
{
F_52 ( & V_106 ) ;
}
static int F_234 ( struct V_397 * V_363 , void * V_63 )
{
struct V_394 * V_395 = V_363 -> V_398 ;
struct V_1 * V_4 = V_395 -> V_4 ;
if ( V_63 == V_399 ) {
F_235 ( V_363 ,
L_6 ) ;
} else {
const struct V_129 * V_236 = V_63 ;
const char * V_80 = V_236 -> V_61 ? V_236 -> V_61 -> V_80 : L_7 ;
F_236 ( V_363 ,
L_8 ,
V_236 - V_4 -> V_132 ,
V_80 , V_236 -> V_183 , V_236 -> V_185 ,
V_236 -> V_184 , V_236 -> V_186 ,
V_236 -> V_13 , V_236 -> V_178 , V_236 -> V_179 ) ;
}
return 0 ;
}
static int F_237 ( struct V_400 * V_400 , struct V_401 * V_401 )
{
return F_238 ( V_400 , V_401 , & V_402 ,
sizeof( struct V_394 ) ) ;
}
static struct V_139 * F_239 ( struct V_2 * V_2 ,
struct V_403 * V_404 , T_9 V_396 )
{
struct V_1 * V_4 = V_404 -> V_4 ;
struct V_139 * V_220 ;
F_58 () ;
for ( V_404 -> V_287 = 0 ; V_404 -> V_287 < V_54 ; V_404 -> V_287 ++ ) {
V_404 -> V_165 = & V_4 -> V_55 [ V_404 -> V_287 ] ;
F_98 (mfc, it->cache, list)
if ( V_396 -- == 0 )
return V_220 ;
}
F_60 () ;
F_130 ( & V_159 ) ;
V_404 -> V_165 = & V_4 -> V_56 ;
F_131 (mfc, it->cache, list)
if ( V_396 -- == 0 )
return V_220 ;
F_133 ( & V_159 ) ;
V_404 -> V_165 = NULL ;
return NULL ;
}
static void * F_240 ( struct V_397 * V_363 , T_9 * V_396 )
{
struct V_403 * V_404 = V_363 -> V_398 ;
struct V_2 * V_2 = F_231 ( V_363 ) ;
struct V_1 * V_4 ;
V_4 = F_1 ( V_2 , V_46 ) ;
if ( V_4 == NULL )
return F_193 ( - V_224 ) ;
V_404 -> V_4 = V_4 ;
V_404 -> V_165 = NULL ;
V_404 -> V_287 = 0 ;
return * V_396 ? F_239 ( V_2 , V_363 -> V_398 , * V_396 - 1 )
: V_399 ;
}
static void * F_241 ( struct V_397 * V_363 , void * V_63 , T_9 * V_396 )
{
struct V_139 * V_220 = V_63 ;
struct V_403 * V_404 = V_363 -> V_398 ;
struct V_2 * V_2 = F_231 ( V_363 ) ;
struct V_1 * V_4 = V_404 -> V_4 ;
++ * V_396 ;
if ( V_63 == V_399 )
return F_239 ( V_2 , V_363 -> V_398 , 0 ) ;
if ( V_220 -> V_51 . V_50 != V_404 -> V_165 )
return F_242 ( V_220 -> V_51 . V_50 , struct V_139 , V_51 ) ;
if ( V_404 -> V_165 == & V_4 -> V_56 )
goto V_405;
F_243 ( V_404 -> V_165 != & V_4 -> V_55 [ V_404 -> V_287 ] ) ;
while ( ++ V_404 -> V_287 < V_54 ) {
V_404 -> V_165 = & V_4 -> V_55 [ V_404 -> V_287 ] ;
if ( F_88 ( V_404 -> V_165 ) )
continue;
return F_244 ( V_404 -> V_165 , struct V_139 , V_51 ) ;
}
F_60 () ;
V_404 -> V_165 = & V_4 -> V_56 ;
V_404 -> V_287 = 0 ;
F_130 ( & V_159 ) ;
if ( ! F_88 ( V_404 -> V_165 ) )
return F_244 ( V_404 -> V_165 , struct V_139 , V_51 ) ;
V_405:
F_133 ( & V_159 ) ;
V_404 -> V_165 = NULL ;
return NULL ;
}
static void F_245 ( struct V_397 * V_363 , void * V_63 )
{
struct V_403 * V_404 = V_363 -> V_398 ;
struct V_1 * V_4 = V_404 -> V_4 ;
if ( V_404 -> V_165 == & V_4 -> V_56 )
F_133 ( & V_159 ) ;
else if ( V_404 -> V_165 == & V_4 -> V_55 [ V_404 -> V_287 ] )
F_60 () ;
}
static int F_246 ( struct V_397 * V_363 , void * V_63 )
{
int V_406 ;
if ( V_63 == V_399 ) {
F_235 ( V_363 ,
L_9 ) ;
} else {
const struct V_139 * V_220 = V_63 ;
const struct V_403 * V_404 = V_363 -> V_398 ;
const struct V_1 * V_4 = V_404 -> V_4 ;
F_236 ( V_363 , L_10 ,
( V_84 T_1 ) V_220 -> V_191 ,
( V_84 T_1 ) V_220 -> V_190 ,
V_220 -> V_195 ) ;
if ( V_404 -> V_165 != & V_4 -> V_56 ) {
F_236 ( V_363 , L_11 ,
V_220 -> V_146 . V_9 . V_200 ,
V_220 -> V_146 . V_9 . V_278 ,
V_220 -> V_146 . V_9 . V_279 ) ;
for ( V_406 = V_220 -> V_146 . V_9 . V_167 ;
V_406 < V_220 -> V_146 . V_9 . V_130 ; V_406 ++ ) {
if ( F_64 ( V_4 , V_406 ) &&
V_220 -> V_146 . V_9 . V_166 [ V_406 ] < 255 )
F_236 ( V_363 ,
L_12 ,
V_406 , V_220 -> V_146 . V_9 . V_166 [ V_406 ] ) ;
}
} else {
F_236 ( V_363 , L_11 , 0ul , 0ul , 0ul ) ;
}
F_247 ( V_363 , '\n' ) ;
}
return 0 ;
}
static int F_248 ( struct V_400 * V_400 , struct V_401 * V_401 )
{
return F_238 ( V_400 , V_401 , & V_407 ,
sizeof( struct V_403 ) ) ;
}
static int T_2 F_249 ( struct V_2 * V_2 )
{
int V_7 ;
V_7 = F_11 ( V_2 ) ;
if ( V_7 < 0 )
goto V_408;
#ifdef F_250
V_7 = - V_47 ;
if ( ! F_251 ( L_13 , 0 , V_2 -> V_409 , & V_410 ) )
goto V_411;
if ( ! F_251 ( L_14 , 0 , V_2 -> V_409 , & V_412 ) )
goto V_413;
#endif
return 0 ;
#ifdef F_250
V_413:
F_252 ( L_13 , V_2 -> V_409 ) ;
V_411:
F_20 ( V_2 ) ;
#endif
V_408:
return V_7 ;
}
static void T_3 F_253 ( struct V_2 * V_2 )
{
#ifdef F_250
F_252 ( L_14 , V_2 -> V_409 ) ;
F_252 ( L_13 , V_2 -> V_409 ) ;
#endif
F_20 ( V_2 ) ;
}
int T_10 F_254 ( void )
{
int V_7 ;
V_142 = F_255 ( L_15 ,
sizeof( struct V_139 ) ,
0 , V_414 | V_415 ,
NULL ) ;
if ( ! V_142 )
return - V_47 ;
V_7 = F_256 ( & V_416 ) ;
if ( V_7 )
goto V_417;
V_7 = F_257 ( & V_418 ) ;
if ( V_7 )
goto V_419;
#ifdef F_258
if ( F_259 ( & V_420 , V_421 ) < 0 ) {
F_260 ( L_16 , V_422 ) ;
V_7 = - V_31 ;
goto V_423;
}
#endif
F_261 ( V_365 , V_424 ,
NULL , F_228 , NULL ) ;
return 0 ;
#ifdef F_258
V_423:
F_262 ( & V_418 ) ;
#endif
V_419:
F_263 ( & V_416 ) ;
V_417:
F_264 ( V_142 ) ;
return V_7 ;
}
