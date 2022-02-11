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
F_23 ( V_4 ) ;
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
F_23 ( V_2 -> V_13 . V_4 ) ;
}
static struct V_1 * F_16 ( struct V_2 * V_2 , T_1 V_3 )
{
struct V_1 * V_4 ;
unsigned int V_51 ;
V_4 = F_1 ( V_2 , V_3 ) ;
if ( V_4 != NULL )
return V_4 ;
V_4 = F_24 ( sizeof( * V_4 ) , V_52 ) ;
if ( V_4 == NULL )
return NULL ;
F_25 ( & V_4 -> V_2 , V_2 ) ;
V_4 -> V_3 = V_3 ;
for ( V_51 = 0 ; V_51 < V_53 ; V_51 ++ )
F_15 ( & V_4 -> V_54 [ V_51 ] ) ;
F_15 ( & V_4 -> V_55 ) ;
F_26 ( & V_4 -> V_56 , V_57 ,
( unsigned long ) V_4 ) ;
#ifdef F_27
V_4 -> V_58 = - 1 ;
#endif
#ifdef F_28
F_29 ( & V_4 -> V_50 , & V_2 -> V_13 . V_44 ) ;
#endif
return V_4 ;
}
static void F_23 ( struct V_1 * V_4 )
{
F_30 ( & V_4 -> V_56 ) ;
F_31 ( V_4 ) ;
F_18 ( V_4 ) ;
}
static void F_32 ( struct V_59 * V_60 , struct V_61 * V_62 )
{
struct V_2 * V_2 = F_33 ( V_60 ) ;
F_34 ( V_60 ) ;
V_60 = F_35 ( V_2 , L_1 ) ;
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
T_4 V_86 = F_36 () ;
F_37 ( V_87 ) ;
V_42 -> V_85 ( V_60 , & V_66 , V_88 ) ;
F_37 ( V_86 ) ;
}
}
}
static
struct V_59 * F_38 ( struct V_2 * V_2 , struct V_61 * V_62 )
{
struct V_59 * V_60 ;
V_60 = F_35 ( V_2 , L_1 ) ;
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
T_4 V_86 = F_36 () ;
F_37 ( V_87 ) ;
V_12 = V_42 -> V_85 ( V_60 , & V_66 , V_91 ) ;
F_37 ( V_86 ) ;
} else {
V_12 = - V_92 ;
}
V_60 = NULL ;
if ( V_12 == 0 &&
( V_60 = F_35 ( V_2 , V_68 . V_79 ) ) != NULL ) {
V_60 -> V_19 |= V_93 ;
V_90 = F_39 ( V_60 ) ;
if ( V_90 == NULL )
goto V_94;
F_40 ( V_90 ) ;
F_41 ( V_90 -> V_95 , V_96 ) = 0 ;
if ( F_42 ( V_60 ) )
goto V_94;
F_43 ( V_60 ) ;
}
}
return V_60 ;
V_94:
F_44 () ;
F_45 () ;
F_46 ( V_60 ) ;
return NULL ;
}
static T_5 F_47 ( struct V_32 * V_33 , struct V_59 * V_60 )
{
struct V_2 * V_2 = F_33 ( V_60 ) ;
struct V_1 * V_4 ;
struct V_5 V_97 = {
. V_98 = V_60 -> V_99 ,
. V_100 = V_33 -> V_101 ,
. V_102 = V_33 -> V_103 ,
} ;
int V_12 ;
V_12 = F_3 ( V_2 , & V_97 , & V_4 ) ;
if ( V_12 < 0 ) {
F_48 ( V_33 ) ;
return V_12 ;
}
F_49 ( & V_104 ) ;
V_60 -> V_105 . V_106 += V_33 -> V_107 ;
V_60 -> V_105 . V_108 ++ ;
F_50 ( V_4 , V_33 , V_4 -> V_58 , V_109 ) ;
F_51 ( & V_104 ) ;
F_48 ( V_33 ) ;
return V_110 ;
}
static void F_52 ( struct V_59 * V_60 )
{
V_60 -> type = V_111 ;
V_60 -> V_112 = V_113 - sizeof( struct V_114 ) - 8 ;
V_60 -> V_19 = V_115 ;
V_60 -> V_64 = & V_116 ,
V_60 -> V_117 = V_118 ;
V_60 -> V_119 |= V_120 ;
}
static struct V_59 * F_53 ( struct V_2 * V_2 , struct V_1 * V_4 )
{
struct V_59 * V_60 ;
struct V_89 * V_90 ;
char V_79 [ V_121 ] ;
if ( V_4 -> V_3 == V_45 )
sprintf ( V_79 , L_3 ) ;
else
sprintf ( V_79 , L_4 , V_4 -> V_3 ) ;
V_60 = F_54 ( 0 , V_79 , F_52 ) ;
if ( V_60 == NULL )
return NULL ;
F_55 ( V_60 , V_2 ) ;
if ( F_56 ( V_60 ) ) {
V_118 ( V_60 ) ;
return NULL ;
}
V_60 -> V_122 = 0 ;
F_57 () ;
V_90 = F_58 ( V_60 ) ;
if ( ! V_90 ) {
F_59 () ;
goto V_94;
}
F_40 ( V_90 ) ;
F_41 ( V_90 -> V_95 , V_96 ) = 0 ;
F_59 () ;
if ( F_42 ( V_60 ) )
goto V_94;
F_43 ( V_60 ) ;
return V_60 ;
V_94:
F_44 () ;
F_45 () ;
F_46 ( V_60 ) ;
return NULL ;
}
static int F_60 ( struct V_1 * V_4 , int V_123 , int V_124 ,
struct V_125 * V_126 )
{
struct V_127 * V_62 ;
struct V_59 * V_60 ;
struct V_89 * V_90 ;
if ( V_123 < 0 || V_123 >= V_4 -> V_128 )
return - V_129 ;
V_62 = & V_4 -> V_130 [ V_123 ] ;
F_61 ( & V_104 ) ;
V_60 = V_62 -> V_60 ;
V_62 -> V_60 = NULL ;
if ( ! V_60 ) {
F_62 ( & V_104 ) ;
return - V_129 ;
}
#ifdef F_27
if ( V_123 == V_4 -> V_58 )
V_4 -> V_58 = - 1 ;
#endif
if ( V_123 + 1 == V_4 -> V_128 ) {
int V_131 ;
for ( V_131 = V_123 - 1 ; V_131 >= 0 ; V_131 -- ) {
if ( F_63 ( V_4 , V_131 ) )
break;
}
V_4 -> V_128 = V_131 + 1 ;
}
F_62 ( & V_104 ) ;
F_64 ( V_60 , - 1 ) ;
V_90 = F_39 ( V_60 ) ;
if ( V_90 ) {
F_41 ( V_90 -> V_95 , V_132 ) -- ;
F_65 ( F_33 ( V_60 ) ,
V_133 ,
V_60 -> V_99 , & V_90 -> V_95 ) ;
F_66 ( V_90 ) ;
}
if ( V_62 -> V_19 & ( V_134 | V_135 ) && ! V_124 )
F_67 ( V_60 , V_126 ) ;
F_68 ( V_60 ) ;
return 0 ;
}
static void F_69 ( struct V_136 * V_126 )
{
struct V_137 * V_138 = F_70 ( V_126 , struct V_137 , V_139 ) ;
F_71 ( V_140 , V_138 ) ;
}
static inline void F_72 ( struct V_137 * V_138 )
{
F_73 ( & V_138 -> V_139 , F_69 ) ;
}
static void F_74 ( struct V_1 * V_4 , struct V_137 * V_138 )
{
struct V_2 * V_2 = F_75 ( & V_4 -> V_2 ) ;
struct V_32 * V_33 ;
struct V_141 * V_142 ;
F_76 ( & V_4 -> V_143 ) ;
while ( ( V_33 = F_77 ( & V_138 -> V_144 . V_145 . V_146 ) ) ) {
if ( F_78 ( V_33 ) -> V_75 == 0 ) {
struct V_147 * V_148 = (struct V_147 * ) F_79 ( V_33 , sizeof( struct V_114 ) ) ;
V_148 -> V_149 = V_150 ;
V_148 -> V_151 = F_80 ( sizeof( struct V_141 ) ) ;
F_81 ( V_33 , V_148 -> V_151 ) ;
V_142 = F_82 ( V_148 ) ;
V_142 -> error = - V_152 ;
memset ( & V_142 -> V_153 , 0 , sizeof( V_142 -> V_153 ) ) ;
F_83 ( V_33 , V_2 , F_84 ( V_33 ) . V_154 ) ;
} else {
F_48 ( V_33 ) ;
}
}
F_72 ( V_138 ) ;
}
static void V_57 ( unsigned long V_10 )
{
struct V_1 * V_4 = (struct V_1 * ) V_10 ;
unsigned long V_155 ;
unsigned long V_156 ;
struct V_137 * V_138 , * V_49 ;
if ( ! F_85 ( & V_157 ) ) {
F_86 ( & V_4 -> V_56 , V_158 + V_159 / 10 ) ;
return;
}
if ( F_87 ( & V_4 -> V_55 ) )
goto V_160;
V_155 = V_158 ;
V_156 = 10 * V_159 ;
F_21 (c, next, &mrt->mfc_unres_queue, list) {
if ( F_88 ( V_138 -> V_144 . V_145 . V_156 , V_155 ) ) {
unsigned long V_161 = V_138 -> V_144 . V_145 . V_156 - V_155 ;
if ( V_161 < V_156 )
V_156 = V_161 ;
continue;
}
F_22 ( & V_138 -> V_50 ) ;
F_89 ( V_4 , V_138 , V_162 ) ;
F_74 ( V_4 , V_138 ) ;
}
if ( ! F_87 ( & V_4 -> V_55 ) )
F_86 ( & V_4 -> V_56 , V_158 + V_156 ) ;
V_160:
F_90 ( & V_157 ) ;
}
static void F_91 ( struct V_1 * V_4 , struct V_137 * V_163 ,
unsigned char * V_164 )
{
int V_123 ;
V_163 -> V_144 . V_8 . V_165 = V_166 ;
V_163 -> V_144 . V_8 . V_128 = 0 ;
memset ( V_163 -> V_144 . V_8 . V_164 , 255 , V_166 ) ;
for ( V_123 = 0 ; V_123 < V_4 -> V_128 ; V_123 ++ ) {
if ( F_63 ( V_4 , V_123 ) &&
V_164 [ V_123 ] && V_164 [ V_123 ] < 255 ) {
V_163 -> V_144 . V_8 . V_164 [ V_123 ] = V_164 [ V_123 ] ;
if ( V_163 -> V_144 . V_8 . V_165 > V_123 )
V_163 -> V_144 . V_8 . V_165 = V_123 ;
if ( V_163 -> V_144 . V_8 . V_128 <= V_123 )
V_163 -> V_144 . V_8 . V_128 = V_123 + 1 ;
}
}
}
static int F_92 ( struct V_2 * V_2 , struct V_1 * V_4 ,
struct V_61 * V_167 , int V_168 )
{
int V_123 = V_167 -> V_80 ;
struct V_127 * V_62 = & V_4 -> V_130 [ V_123 ] ;
struct V_59 * V_60 ;
struct V_89 * V_90 ;
int V_12 ;
if ( F_63 ( V_4 , V_123 ) )
return - V_169 ;
switch ( V_167 -> V_170 ) {
#ifdef F_27
case V_135 :
if ( V_4 -> V_58 >= 0 )
return - V_169 ;
V_60 = F_53 ( V_2 , V_4 ) ;
if ( ! V_60 )
return - V_171 ;
V_12 = F_64 ( V_60 , 1 ) ;
if ( V_12 ) {
F_46 ( V_60 ) ;
F_68 ( V_60 ) ;
return V_12 ;
}
break;
#endif
case V_134 :
V_60 = F_38 ( V_2 , V_167 ) ;
if ( ! V_60 )
return - V_171 ;
V_12 = F_64 ( V_60 , 1 ) ;
if ( V_12 ) {
F_32 ( V_60 , V_167 ) ;
F_68 ( V_60 ) ;
return V_12 ;
}
break;
case V_172 :
case 0 :
if ( V_167 -> V_170 == V_172 ) {
V_60 = F_93 ( V_2 , V_167 -> V_173 ) ;
if ( V_60 && F_39 ( V_60 ) == NULL ) {
F_68 ( V_60 ) ;
return - V_129 ;
}
} else {
V_60 = F_94 ( V_2 , V_167 -> V_74 . V_72 ) ;
}
if ( ! V_60 )
return - V_129 ;
V_12 = F_64 ( V_60 , 1 ) ;
if ( V_12 ) {
F_68 ( V_60 ) ;
return V_12 ;
}
break;
default:
return - V_27 ;
}
V_90 = F_39 ( V_60 ) ;
if ( ! V_90 ) {
F_68 ( V_60 ) ;
return - V_129 ;
}
F_41 ( V_90 -> V_95 , V_132 ) ++ ;
F_65 ( V_2 , V_133 , V_60 -> V_99 ,
& V_90 -> V_95 ) ;
F_66 ( V_90 ) ;
V_62 -> V_174 = V_167 -> V_175 ;
V_62 -> V_176 = V_167 -> V_74 . V_72 ;
V_62 -> V_177 = V_167 -> V_71 . V_72 ;
V_62 -> V_19 = V_167 -> V_170 ;
if ( ! V_168 )
V_62 -> V_19 |= V_178 ;
V_62 -> V_179 = V_167 -> V_180 ;
V_62 -> V_181 = 0 ;
V_62 -> V_182 = 0 ;
V_62 -> V_183 = 0 ;
V_62 -> V_184 = 0 ;
V_62 -> V_185 = V_60 -> V_99 ;
if ( V_62 -> V_19 & ( V_134 | V_135 ) )
V_62 -> V_185 = V_60 -> V_122 ;
F_61 ( & V_104 ) ;
V_62 -> V_60 = V_60 ;
#ifdef F_27
if ( V_62 -> V_19 & V_135 )
V_4 -> V_58 = V_123 ;
#endif
if ( V_123 + 1 > V_4 -> V_128 )
V_4 -> V_128 = V_123 + 1 ;
F_62 ( & V_104 ) ;
return 0 ;
}
static struct V_137 * F_95 ( struct V_1 * V_4 ,
T_6 V_186 ,
T_6 V_187 )
{
int line = F_96 ( V_187 , V_186 ) ;
struct V_137 * V_138 ;
F_97 (c, &mrt->mfc_cache_array[line], list) {
if ( V_138 -> V_188 == V_186 && V_138 -> V_189 == V_187 )
return V_138 ;
}
return NULL ;
}
static struct V_137 * F_98 ( void )
{
struct V_137 * V_138 = F_99 ( V_140 , V_52 ) ;
if ( V_138 )
V_138 -> V_144 . V_8 . V_165 = V_166 ;
return V_138 ;
}
static struct V_137 * F_100 ( void )
{
struct V_137 * V_138 = F_99 ( V_140 , V_190 ) ;
if ( V_138 ) {
F_101 ( & V_138 -> V_144 . V_145 . V_146 ) ;
V_138 -> V_144 . V_145 . V_156 = V_158 + 10 * V_159 ;
}
return V_138 ;
}
static void F_102 ( struct V_2 * V_2 , struct V_1 * V_4 ,
struct V_137 * V_191 , struct V_137 * V_138 )
{
struct V_32 * V_33 ;
struct V_141 * V_142 ;
while ( ( V_33 = F_103 ( & V_191 -> V_144 . V_145 . V_146 ) ) ) {
if ( F_78 ( V_33 ) -> V_75 == 0 ) {
struct V_147 * V_148 = (struct V_147 * ) F_79 ( V_33 , sizeof( struct V_114 ) ) ;
if ( F_104 ( V_4 , V_33 , V_138 , F_82 ( V_148 ) ) > 0 ) {
V_148 -> V_151 = F_105 ( V_33 ) -
( V_192 * ) V_148 ;
} else {
V_148 -> V_149 = V_150 ;
V_148 -> V_151 = F_80 ( sizeof( struct V_141 ) ) ;
F_81 ( V_33 , V_148 -> V_151 ) ;
V_142 = F_82 ( V_148 ) ;
V_142 -> error = - V_193 ;
memset ( & V_142 -> V_153 , 0 , sizeof( V_142 -> V_153 ) ) ;
}
F_83 ( V_33 , V_2 , F_84 ( V_33 ) . V_154 ) ;
} else {
F_106 ( V_2 , V_4 , V_33 , V_138 , 0 ) ;
}
}
}
static int F_50 ( struct V_1 * V_4 ,
struct V_32 * V_194 , T_7 V_123 , int assert )
{
struct V_32 * V_33 ;
const int V_76 = F_107 ( V_194 ) ;
struct V_195 * V_196 ;
struct V_197 * V_153 ;
struct V_198 * V_199 ;
int V_200 ;
#ifdef F_27
if ( assert == V_109 )
V_33 = F_108 ( V_194 , sizeof( struct V_114 ) ) ;
else
#endif
V_33 = F_109 ( 128 , V_190 ) ;
if ( ! V_33 )
return - V_171 ;
#ifdef F_27
if ( assert == V_109 ) {
F_110 ( V_33 , sizeof( struct V_114 ) ) ;
F_111 ( V_33 ) ;
F_112 ( V_33 ) ;
V_153 = (struct V_197 * ) F_113 ( V_33 ) ;
memcpy ( V_153 , F_113 ( V_194 ) , sizeof( struct V_114 ) ) ;
V_153 -> V_201 = V_109 ;
V_153 -> V_202 = 0 ;
V_153 -> V_203 = V_4 -> V_58 ;
F_78 ( V_33 ) -> V_76 = sizeof( struct V_114 ) >> 2 ;
F_78 ( V_33 ) -> V_204 = F_114 ( F_115 ( F_78 ( V_194 ) -> V_204 ) +
sizeof( struct V_114 ) ) ;
} else
#endif
{
V_33 -> V_205 = V_33 -> V_206 ;
F_116 ( V_33 , V_76 ) ;
F_117 ( V_33 , V_194 -> V_207 , V_76 ) ;
F_78 ( V_33 ) -> V_77 = 0 ;
V_153 = (struct V_197 * ) F_113 ( V_33 ) ;
V_153 -> V_203 = V_123 ;
F_118 ( V_33 , F_119 ( F_120 ( V_194 ) ) ) ;
V_196 = (struct V_195 * ) F_116 ( V_33 , sizeof( struct V_195 ) ) ;
V_196 -> type =
V_153 -> V_201 = assert ;
V_196 -> V_208 = 0 ;
F_78 ( V_33 ) -> V_204 = F_114 ( V_33 -> V_107 ) ;
V_33 -> V_209 = V_33 -> V_205 ;
}
F_57 () ;
V_199 = F_121 ( V_4 -> V_199 ) ;
if ( V_199 == NULL ) {
F_59 () ;
F_48 ( V_33 ) ;
return - V_27 ;
}
V_200 = F_122 ( V_199 , V_33 ) ;
F_59 () ;
if ( V_200 < 0 ) {
F_123 ( L_5 ) ;
F_48 ( V_33 ) ;
}
return V_200 ;
}
static int
F_124 ( struct V_1 * V_4 , T_7 V_123 , struct V_32 * V_33 )
{
bool V_210 = false ;
int V_12 ;
struct V_137 * V_138 ;
const struct V_114 * V_69 = F_78 ( V_33 ) ;
F_125 ( & V_157 ) ;
F_126 (c, &mrt->mfc_unres_queue, list) {
if ( V_138 -> V_189 == V_69 -> V_70 &&
V_138 -> V_188 == V_69 -> V_73 ) {
V_210 = true ;
break;
}
}
if ( ! V_210 ) {
if ( F_127 ( & V_4 -> V_143 ) >= 10 ||
( V_138 = F_100 () ) == NULL ) {
F_128 ( & V_157 ) ;
F_48 ( V_33 ) ;
return - V_171 ;
}
V_138 -> V_211 = - 1 ;
V_138 -> V_188 = V_69 -> V_73 ;
V_138 -> V_189 = V_69 -> V_70 ;
V_12 = F_50 ( V_4 , V_33 , V_123 , V_212 ) ;
if ( V_12 < 0 ) {
F_128 ( & V_157 ) ;
F_72 ( V_138 ) ;
F_48 ( V_33 ) ;
return V_12 ;
}
F_129 ( & V_4 -> V_143 ) ;
F_130 ( & V_138 -> V_50 , & V_4 -> V_55 ) ;
F_89 ( V_4 , V_138 , V_213 ) ;
if ( F_127 ( & V_4 -> V_143 ) == 1 )
F_86 ( & V_4 -> V_56 , V_138 -> V_144 . V_145 . V_156 ) ;
}
if ( V_138 -> V_144 . V_145 . V_146 . V_214 > 3 ) {
F_48 ( V_33 ) ;
V_12 = - V_171 ;
} else {
F_131 ( & V_138 -> V_144 . V_145 . V_146 , V_33 ) ;
V_12 = 0 ;
}
F_128 ( & V_157 ) ;
return V_12 ;
}
static int F_132 ( struct V_1 * V_4 , struct V_215 * V_216 )
{
int line ;
struct V_137 * V_138 , * V_49 ;
line = F_96 ( V_216 -> V_217 . V_72 , V_216 -> V_218 . V_72 ) ;
F_21 (c, next, &mrt->mfc_cache_array[line], list) {
if ( V_138 -> V_188 == V_216 -> V_218 . V_72 &&
V_138 -> V_189 == V_216 -> V_217 . V_72 ) {
F_133 ( & V_138 -> V_50 ) ;
F_89 ( V_4 , V_138 , V_162 ) ;
F_72 ( V_138 ) ;
return 0 ;
}
}
return - V_219 ;
}
static int F_134 ( struct V_2 * V_2 , struct V_1 * V_4 ,
struct V_215 * V_216 , int V_168 )
{
bool V_210 = false ;
int line ;
struct V_137 * V_191 , * V_138 ;
if ( V_216 -> V_220 >= V_166 )
return - V_221 ;
line = F_96 ( V_216 -> V_217 . V_72 , V_216 -> V_218 . V_72 ) ;
F_126 (c, &mrt->mfc_cache_array[line], list) {
if ( V_138 -> V_188 == V_216 -> V_218 . V_72 &&
V_138 -> V_189 == V_216 -> V_217 . V_72 ) {
V_210 = true ;
break;
}
}
if ( V_210 ) {
F_61 ( & V_104 ) ;
V_138 -> V_211 = V_216 -> V_220 ;
F_91 ( V_4 , V_138 , V_216 -> V_222 ) ;
if ( ! V_168 )
V_138 -> V_223 |= V_224 ;
F_62 ( & V_104 ) ;
F_89 ( V_4 , V_138 , V_213 ) ;
return 0 ;
}
if ( ! F_135 ( V_216 -> V_217 . V_72 ) )
return - V_27 ;
V_138 = F_98 () ;
if ( V_138 == NULL )
return - V_46 ;
V_138 -> V_188 = V_216 -> V_218 . V_72 ;
V_138 -> V_189 = V_216 -> V_217 . V_72 ;
V_138 -> V_211 = V_216 -> V_220 ;
F_91 ( V_4 , V_138 , V_216 -> V_222 ) ;
if ( ! V_168 )
V_138 -> V_223 |= V_224 ;
F_136 ( & V_138 -> V_50 , & V_4 -> V_54 [ line ] ) ;
V_210 = false ;
F_125 ( & V_157 ) ;
F_126 (uc, &mrt->mfc_unres_queue, list) {
if ( V_191 -> V_188 == V_138 -> V_188 &&
V_191 -> V_189 == V_138 -> V_189 ) {
F_22 ( & V_191 -> V_50 ) ;
F_76 ( & V_4 -> V_143 ) ;
V_210 = true ;
break;
}
}
if ( F_87 ( & V_4 -> V_55 ) )
F_137 ( & V_4 -> V_56 ) ;
F_128 ( & V_157 ) ;
if ( V_210 ) {
F_102 ( V_2 , V_4 , V_191 , V_138 ) ;
F_72 ( V_191 ) ;
}
F_89 ( V_4 , V_138 , V_213 ) ;
return 0 ;
}
static void F_31 ( struct V_1 * V_4 )
{
int V_51 ;
F_138 ( V_50 ) ;
struct V_137 * V_138 , * V_49 ;
for ( V_51 = 0 ; V_51 < V_4 -> V_128 ; V_51 ++ ) {
if ( ! ( V_4 -> V_130 [ V_51 ] . V_19 & V_178 ) )
F_60 ( V_4 , V_51 , 0 , & V_50 ) ;
}
F_139 ( & V_50 ) ;
for ( V_51 = 0 ; V_51 < V_53 ; V_51 ++ ) {
F_21 (c, next, &mrt->mfc_cache_array[i], list) {
if ( V_138 -> V_223 & V_224 )
continue;
F_133 ( & V_138 -> V_50 ) ;
F_89 ( V_4 , V_138 , V_162 ) ;
F_72 ( V_138 ) ;
}
}
if ( F_127 ( & V_4 -> V_143 ) != 0 ) {
F_125 ( & V_157 ) ;
F_21 (c, next, &mrt->mfc_unres_queue, list) {
F_22 ( & V_138 -> V_50 ) ;
F_89 ( V_4 , V_138 , V_162 ) ;
F_74 ( V_4 , V_138 ) ;
}
F_128 ( & V_157 ) ;
}
}
static void F_140 ( struct V_198 * V_225 )
{
struct V_2 * V_2 = F_141 ( V_225 ) ;
struct V_1 * V_4 ;
F_45 () ;
F_2 (mrt, net) {
if ( V_225 == F_142 ( V_4 -> V_199 ) ) {
F_143 ( V_2 , V_132 ) -- ;
F_65 ( V_2 , V_133 ,
V_226 ,
V_2 -> V_13 . V_227 ) ;
F_144 ( V_4 -> V_199 , NULL ) ;
F_31 ( V_4 ) ;
}
}
F_44 () ;
}
int F_145 ( struct V_198 * V_225 , int V_228 , char V_84 * V_229 , unsigned int V_230 )
{
int V_200 ;
struct V_61 V_231 ;
struct V_215 V_216 ;
struct V_2 * V_2 = F_141 ( V_225 ) ;
struct V_1 * V_4 ;
if ( V_225 -> V_232 != V_233 ||
F_146 ( V_225 ) -> V_234 != V_235 )
return - V_92 ;
V_4 = F_1 ( V_2 , F_147 ( V_225 ) -> V_236 ? : V_45 ) ;
if ( V_4 == NULL )
return - V_219 ;
if ( V_228 != V_237 ) {
if ( V_225 != F_148 ( V_4 -> V_199 ) &&
! F_149 ( V_2 -> V_238 , V_239 ) )
return - V_25 ;
}
switch ( V_228 ) {
case V_237 :
if ( V_230 != sizeof( int ) )
return - V_27 ;
F_45 () ;
if ( F_142 ( V_4 -> V_199 ) ) {
F_44 () ;
return - V_169 ;
}
V_200 = F_150 ( V_225 , 1 , F_140 ) ;
if ( V_200 == 0 ) {
F_151 ( V_4 -> V_199 , V_225 ) ;
F_143 ( V_2 , V_132 ) ++ ;
F_65 ( V_2 , V_133 ,
V_226 ,
V_2 -> V_13 . V_227 ) ;
}
F_44 () ;
return V_200 ;
case V_240 :
if ( V_225 != F_148 ( V_4 -> V_199 ) )
return - V_25 ;
return F_150 ( V_225 , 0 , NULL ) ;
case V_241 :
case V_242 :
if ( V_230 != sizeof( V_231 ) )
return - V_27 ;
if ( F_152 ( & V_231 , V_229 , sizeof( V_231 ) ) )
return - V_243 ;
if ( V_231 . V_80 >= V_166 )
return - V_221 ;
F_45 () ;
if ( V_228 == V_241 ) {
V_200 = F_92 ( V_2 , V_4 , & V_231 ,
V_225 == F_142 ( V_4 -> V_199 ) ) ;
} else {
V_200 = F_60 ( V_4 , V_231 . V_80 , 0 , NULL ) ;
}
F_44 () ;
return V_200 ;
case V_244 :
case V_245 :
if ( V_230 != sizeof( V_216 ) )
return - V_27 ;
if ( F_152 ( & V_216 , V_229 , sizeof( V_216 ) ) )
return - V_243 ;
F_45 () ;
if ( V_228 == V_245 )
V_200 = F_132 ( V_4 , & V_216 ) ;
else
V_200 = F_134 ( V_2 , V_4 , & V_216 ,
V_225 == F_142 ( V_4 -> V_199 ) ) ;
F_44 () ;
return V_200 ;
case V_246 :
{
int V_62 ;
if ( V_230 != sizeof( V_62 ) )
return - V_27 ;
if ( F_153 ( V_62 , ( int V_84 * ) V_229 ) )
return - V_243 ;
V_4 -> V_247 = V_62 ;
return 0 ;
}
#ifdef F_27
case V_248 :
{
int V_62 ;
if ( V_230 != sizeof( V_62 ) )
return - V_27 ;
if ( F_153 ( V_62 , ( int V_84 * ) V_229 ) )
return - V_243 ;
V_62 = ! ! V_62 ;
F_45 () ;
V_200 = 0 ;
if ( V_62 != V_4 -> V_249 ) {
V_4 -> V_249 = V_62 ;
V_4 -> V_247 = V_62 ;
}
F_44 () ;
return V_200 ;
}
#endif
#ifdef F_28
case V_250 :
{
T_1 V_62 ;
if ( V_230 != sizeof( T_1 ) )
return - V_27 ;
if ( F_153 ( V_62 , ( T_1 V_84 * ) V_229 ) )
return - V_243 ;
if ( V_62 != V_45 && V_62 >= 1000000000 )
return - V_27 ;
F_45 () ;
V_200 = 0 ;
if ( V_225 == F_142 ( V_4 -> V_199 ) ) {
V_200 = - V_251 ;
} else {
if ( ! F_16 ( V_2 , V_62 ) )
V_200 = - V_46 ;
else
F_147 ( V_225 ) -> V_236 = V_62 ;
}
F_44 () ;
return V_200 ;
}
#endif
default:
return - V_252 ;
}
}
int F_154 ( struct V_198 * V_225 , int V_228 , char V_84 * V_229 , int V_84 * V_230 )
{
int V_253 ;
int V_254 ;
struct V_2 * V_2 = F_141 ( V_225 ) ;
struct V_1 * V_4 ;
if ( V_225 -> V_232 != V_233 ||
F_146 ( V_225 ) -> V_234 != V_235 )
return - V_92 ;
V_4 = F_1 ( V_2 , F_147 ( V_225 ) -> V_236 ? : V_45 ) ;
if ( V_4 == NULL )
return - V_219 ;
if ( V_228 != V_255 &&
#ifdef F_27
V_228 != V_248 &&
#endif
V_228 != V_246 )
return - V_252 ;
if ( F_153 ( V_253 , V_230 ) )
return - V_243 ;
V_253 = F_155 (unsigned int, olr, sizeof(int)) ;
if ( V_253 < 0 )
return - V_27 ;
if ( F_156 ( V_253 , V_230 ) )
return - V_243 ;
if ( V_228 == V_255 )
V_254 = 0x0305 ;
#ifdef F_27
else if ( V_228 == V_248 )
V_254 = V_4 -> V_249 ;
#endif
else
V_254 = V_4 -> V_247 ;
if ( F_157 ( V_229 , & V_254 , V_253 ) )
return - V_243 ;
return 0 ;
}
int F_158 ( struct V_198 * V_225 , int V_256 , void V_84 * V_10 )
{
struct V_257 V_258 ;
struct V_259 V_260 ;
struct V_127 * V_231 ;
struct V_137 * V_138 ;
struct V_2 * V_2 = F_141 ( V_225 ) ;
struct V_1 * V_4 ;
V_4 = F_1 ( V_2 , F_147 ( V_225 ) -> V_236 ? : V_45 ) ;
if ( V_4 == NULL )
return - V_219 ;
switch ( V_256 ) {
case V_261 :
if ( F_152 ( & V_260 , V_10 , sizeof( V_260 ) ) )
return - V_243 ;
if ( V_260 . V_123 >= V_4 -> V_128 )
return - V_27 ;
F_49 ( & V_104 ) ;
V_231 = & V_4 -> V_130 [ V_260 . V_123 ] ;
if ( F_63 ( V_4 , V_260 . V_123 ) ) {
V_260 . V_262 = V_231 -> V_183 ;
V_260 . V_263 = V_231 -> V_184 ;
V_260 . V_264 = V_231 -> V_181 ;
V_260 . V_265 = V_231 -> V_182 ;
F_51 ( & V_104 ) ;
if ( F_157 ( V_10 , & V_260 , sizeof( V_260 ) ) )
return - V_243 ;
return 0 ;
}
F_51 ( & V_104 ) ;
return - V_129 ;
case V_266 :
if ( F_152 ( & V_258 , V_10 , sizeof( V_258 ) ) )
return - V_243 ;
F_57 () ;
V_138 = F_95 ( V_4 , V_258 . V_267 . V_72 , V_258 . V_268 . V_72 ) ;
if ( V_138 ) {
V_258 . V_269 = V_138 -> V_144 . V_8 . V_194 ;
V_258 . V_270 = V_138 -> V_144 . V_8 . V_271 ;
V_258 . V_272 = V_138 -> V_144 . V_8 . V_272 ;
F_59 () ;
if ( F_157 ( V_10 , & V_258 , sizeof( V_258 ) ) )
return - V_243 ;
return 0 ;
}
F_59 () ;
return - V_129 ;
default:
return - V_273 ;
}
}
int F_159 ( struct V_198 * V_225 , unsigned int V_256 , void V_84 * V_10 )
{
struct V_274 V_258 ;
struct V_275 V_260 ;
struct V_127 * V_231 ;
struct V_137 * V_138 ;
struct V_2 * V_2 = F_141 ( V_225 ) ;
struct V_1 * V_4 ;
V_4 = F_1 ( V_2 , F_147 ( V_225 ) -> V_236 ? : V_45 ) ;
if ( V_4 == NULL )
return - V_219 ;
switch ( V_256 ) {
case V_261 :
if ( F_152 ( & V_260 , V_10 , sizeof( V_260 ) ) )
return - V_243 ;
if ( V_260 . V_123 >= V_4 -> V_128 )
return - V_27 ;
F_49 ( & V_104 ) ;
V_231 = & V_4 -> V_130 [ V_260 . V_123 ] ;
if ( F_63 ( V_4 , V_260 . V_123 ) ) {
V_260 . V_262 = V_231 -> V_183 ;
V_260 . V_263 = V_231 -> V_184 ;
V_260 . V_264 = V_231 -> V_181 ;
V_260 . V_265 = V_231 -> V_182 ;
F_51 ( & V_104 ) ;
if ( F_157 ( V_10 , & V_260 , sizeof( V_260 ) ) )
return - V_243 ;
return 0 ;
}
F_51 ( & V_104 ) ;
return - V_129 ;
case V_266 :
if ( F_152 ( & V_258 , V_10 , sizeof( V_258 ) ) )
return - V_243 ;
F_57 () ;
V_138 = F_95 ( V_4 , V_258 . V_267 . V_72 , V_258 . V_268 . V_72 ) ;
if ( V_138 ) {
V_258 . V_269 = V_138 -> V_144 . V_8 . V_194 ;
V_258 . V_270 = V_138 -> V_144 . V_8 . V_271 ;
V_258 . V_272 = V_138 -> V_144 . V_8 . V_272 ;
F_59 () ;
if ( F_157 ( V_10 , & V_258 , sizeof( V_258 ) ) )
return - V_243 ;
return 0 ;
}
F_59 () ;
return - V_129 ;
default:
return - V_273 ;
}
}
static int F_160 ( struct V_276 * V_277 , unsigned long V_278 , void * V_279 )
{
struct V_59 * V_60 = V_279 ;
struct V_2 * V_2 = F_33 ( V_60 ) ;
struct V_1 * V_4 ;
struct V_127 * V_62 ;
int V_280 ;
if ( V_278 != V_281 )
return V_282 ;
F_2 (mrt, net) {
V_62 = & V_4 -> V_130 [ 0 ] ;
for ( V_280 = 0 ; V_280 < V_4 -> V_128 ; V_280 ++ , V_62 ++ ) {
if ( V_62 -> V_60 == V_60 )
F_60 ( V_4 , V_280 , 1 , NULL ) ;
}
}
return V_282 ;
}
static void F_161 ( struct V_32 * V_33 , T_6 V_73 , T_6 V_70 )
{
struct V_114 * V_69 ;
const struct V_114 * V_283 = F_78 ( V_33 ) ;
F_110 ( V_33 , sizeof( struct V_114 ) ) ;
V_33 -> V_209 = V_33 -> V_205 ;
F_111 ( V_33 ) ;
V_69 = F_78 ( V_33 ) ;
V_69 -> V_75 = 4 ;
V_69 -> V_40 = V_283 -> V_40 ;
V_69 -> V_284 = V_283 -> V_284 ;
V_69 -> V_285 = 0 ;
V_69 -> V_70 = V_70 ;
V_69 -> V_73 = V_73 ;
V_69 -> V_77 = V_78 ;
V_69 -> V_76 = 5 ;
V_69 -> V_204 = F_114 ( V_33 -> V_107 ) ;
F_162 ( V_69 , F_120 ( V_33 ) , NULL ) ;
F_163 ( V_69 ) ;
memset ( & ( F_164 ( V_33 ) -> V_286 ) , 0 , sizeof( F_164 ( V_33 ) -> V_286 ) ) ;
F_165 ( V_33 ) ;
}
static inline int F_166 ( struct V_32 * V_33 )
{
struct V_287 * V_286 = & ( F_164 ( V_33 ) -> V_286 ) ;
F_167 ( F_33 ( F_120 ( V_33 ) -> V_60 ) , V_288 ) ;
F_168 ( F_33 ( F_120 ( V_33 ) -> V_60 ) , V_289 , V_33 -> V_107 ) ;
if ( F_169 ( V_286 -> V_230 ) )
F_170 ( V_33 ) ;
return F_171 ( V_33 ) ;
}
static void F_172 ( struct V_2 * V_2 , struct V_1 * V_4 ,
struct V_32 * V_33 , struct V_137 * V_138 , int V_123 )
{
const struct V_114 * V_69 = F_78 ( V_33 ) ;
struct V_127 * V_231 = & V_4 -> V_130 [ V_123 ] ;
struct V_59 * V_60 ;
struct V_290 * V_291 ;
struct V_5 V_97 ;
int V_292 = 0 ;
if ( V_231 -> V_60 == NULL )
goto V_293;
#ifdef F_27
if ( V_231 -> V_19 & V_135 ) {
V_231 -> V_184 ++ ;
V_231 -> V_182 += V_33 -> V_107 ;
V_231 -> V_60 -> V_105 . V_106 += V_33 -> V_107 ;
V_231 -> V_60 -> V_105 . V_108 ++ ;
F_50 ( V_4 , V_33 , V_123 , V_109 ) ;
goto V_293;
}
#endif
if ( V_231 -> V_19 & V_134 ) {
V_291 = F_173 ( V_2 , & V_97 , NULL ,
V_231 -> V_177 , V_231 -> V_176 ,
0 , 0 ,
V_78 ,
F_174 ( V_69 -> V_40 ) , V_231 -> V_185 ) ;
if ( F_13 ( V_291 ) )
goto V_293;
V_292 = sizeof( struct V_114 ) ;
} else {
V_291 = F_173 ( V_2 , & V_97 , NULL , V_69 -> V_70 , 0 ,
0 , 0 ,
V_78 ,
F_174 ( V_69 -> V_40 ) , V_231 -> V_185 ) ;
if ( F_13 ( V_291 ) )
goto V_293;
}
V_60 = V_291 -> V_294 . V_60 ;
if ( V_33 -> V_107 + V_292 > F_175 ( & V_291 -> V_294 ) && ( F_115 ( V_69 -> V_285 ) & V_295 ) ) {
F_167 ( F_33 ( V_60 ) , V_296 ) ;
F_176 ( V_291 ) ;
goto V_293;
}
V_292 += F_177 ( V_60 ) + V_291 -> V_294 . V_297 ;
if ( F_178 ( V_33 , V_292 ) ) {
F_176 ( V_291 ) ;
goto V_293;
}
V_231 -> V_184 ++ ;
V_231 -> V_182 += V_33 -> V_107 ;
F_179 ( V_33 ) ;
F_118 ( V_33 , & V_291 -> V_294 ) ;
F_180 ( F_78 ( V_33 ) ) ;
if ( V_231 -> V_19 & V_134 ) {
F_161 ( V_33 , V_231 -> V_176 , V_231 -> V_177 ) ;
V_231 -> V_60 -> V_105 . V_108 ++ ;
V_231 -> V_60 -> V_105 . V_106 += V_33 -> V_107 ;
}
F_164 ( V_33 ) -> V_19 |= V_298 ;
F_181 ( V_299 , V_300 , V_33 , V_33 -> V_60 , V_60 ,
F_166 ) ;
return;
V_293:
F_48 ( V_33 ) ;
}
static int F_182 ( struct V_1 * V_4 , struct V_59 * V_60 )
{
int V_280 ;
for ( V_280 = V_4 -> V_128 - 1 ; V_280 >= 0 ; V_280 -- ) {
if ( V_4 -> V_130 [ V_280 ] . V_60 == V_60 )
break;
}
return V_280 ;
}
static int F_106 ( struct V_2 * V_2 , struct V_1 * V_4 ,
struct V_32 * V_33 , struct V_137 * V_163 ,
int V_176 )
{
int V_301 = - 1 ;
int V_231 , V_280 ;
V_231 = V_163 -> V_211 ;
V_163 -> V_144 . V_8 . V_194 ++ ;
V_163 -> V_144 . V_8 . V_271 += V_33 -> V_107 ;
if ( V_4 -> V_130 [ V_231 ] . V_60 != V_33 -> V_60 ) {
int V_302 ;
if ( F_183 ( F_184 ( V_33 ) ) ) {
goto V_303;
}
V_163 -> V_144 . V_8 . V_272 ++ ;
V_302 = F_182 ( V_4 , V_33 -> V_60 ) ;
if ( V_302 >= 0 && V_4 -> V_247 &&
( V_4 -> V_249 ||
V_163 -> V_144 . V_8 . V_164 [ V_302 ] < 255 ) &&
F_88 ( V_158 ,
V_163 -> V_144 . V_8 . V_304 + V_305 ) ) {
V_163 -> V_144 . V_8 . V_304 = V_158 ;
F_50 ( V_4 , V_33 , V_302 , V_306 ) ;
}
goto V_303;
}
V_4 -> V_130 [ V_231 ] . V_183 ++ ;
V_4 -> V_130 [ V_231 ] . V_181 += V_33 -> V_107 ;
for ( V_280 = V_163 -> V_144 . V_8 . V_128 - 1 ;
V_280 >= V_163 -> V_144 . V_8 . V_165 ; V_280 -- ) {
if ( F_78 ( V_33 ) -> V_284 > V_163 -> V_144 . V_8 . V_164 [ V_280 ] ) {
if ( V_301 != - 1 ) {
struct V_32 * V_307 = F_185 ( V_33 , V_190 ) ;
if ( V_307 )
F_172 ( V_2 , V_4 , V_307 , V_163 ,
V_301 ) ;
}
V_301 = V_280 ;
}
}
if ( V_301 != - 1 ) {
if ( V_176 ) {
struct V_32 * V_307 = F_185 ( V_33 , V_190 ) ;
if ( V_307 )
F_172 ( V_2 , V_4 , V_307 , V_163 , V_301 ) ;
} else {
F_172 ( V_2 , V_4 , V_33 , V_163 , V_301 ) ;
return 0 ;
}
}
V_303:
if ( ! V_176 )
F_48 ( V_33 ) ;
return 0 ;
}
static struct V_1 * F_186 ( struct V_2 * V_2 , struct V_32 * V_33 )
{
struct V_290 * V_291 = F_184 ( V_33 ) ;
struct V_114 * V_69 = F_78 ( V_33 ) ;
struct V_5 V_97 = {
. V_70 = V_69 -> V_70 ,
. V_73 = V_69 -> V_73 ,
. V_308 = F_174 ( V_69 -> V_40 ) ,
. V_98 = ( F_183 ( V_291 ) ?
V_33 -> V_60 -> V_99 : 0 ) ,
. V_100 = ( F_183 ( V_291 ) ?
V_309 :
V_33 -> V_60 -> V_99 ) ,
. V_102 = V_33 -> V_103 ,
} ;
struct V_1 * V_4 ;
int V_12 ;
V_12 = F_3 ( V_2 , & V_97 , & V_4 ) ;
if ( V_12 )
return F_187 ( V_12 ) ;
return V_4 ;
}
int F_188 ( struct V_32 * V_33 )
{
struct V_137 * V_163 ;
struct V_2 * V_2 = F_33 ( V_33 -> V_60 ) ;
int V_176 = F_184 ( V_33 ) -> V_310 & V_311 ;
struct V_1 * V_4 ;
if ( F_164 ( V_33 ) -> V_19 & V_298 )
goto V_303;
V_4 = F_186 ( V_2 , V_33 ) ;
if ( F_13 ( V_4 ) ) {
F_48 ( V_33 ) ;
return F_14 ( V_4 ) ;
}
if ( ! V_176 ) {
if ( F_164 ( V_33 ) -> V_286 . V_312 ) {
if ( F_189 ( V_33 ) )
return 0 ;
} else if ( F_78 ( V_33 ) -> V_77 == V_235 ) {
struct V_198 * V_199 ;
V_199 = F_121 ( V_4 -> V_199 ) ;
if ( V_199 ) {
F_165 ( V_33 ) ;
F_190 ( V_199 , V_33 ) ;
return 0 ;
}
}
}
V_163 = F_95 ( V_4 , F_78 ( V_33 ) -> V_73 , F_78 ( V_33 ) -> V_70 ) ;
if ( V_163 == NULL ) {
int V_231 ;
if ( V_176 ) {
struct V_32 * V_307 = F_185 ( V_33 , V_190 ) ;
F_191 ( V_33 ) ;
if ( V_307 == NULL )
return - V_171 ;
V_33 = V_307 ;
}
F_49 ( & V_104 ) ;
V_231 = F_182 ( V_4 , V_33 -> V_60 ) ;
if ( V_231 >= 0 ) {
int V_48 = F_124 ( V_4 , V_231 , V_33 ) ;
F_51 ( & V_104 ) ;
return V_48 ;
}
F_51 ( & V_104 ) ;
F_48 ( V_33 ) ;
return - V_313 ;
}
F_49 ( & V_104 ) ;
F_106 ( V_2 , V_4 , V_33 , V_163 , V_176 ) ;
F_51 ( & V_104 ) ;
if ( V_176 )
return F_191 ( V_33 ) ;
return 0 ;
V_303:
if ( V_176 )
return F_191 ( V_33 ) ;
F_48 ( V_33 ) ;
return 0 ;
}
static int F_192 ( struct V_1 * V_4 , struct V_32 * V_33 ,
unsigned int V_314 )
{
struct V_59 * V_315 = NULL ;
struct V_114 * V_292 ;
V_292 = (struct V_114 * ) ( F_193 ( V_33 ) + V_314 ) ;
if ( ! F_135 ( V_292 -> V_70 ) ||
V_292 -> V_204 == 0 ||
F_115 ( V_292 -> V_204 ) + V_314 > V_33 -> V_107 )
return 1 ;
F_49 ( & V_104 ) ;
if ( V_4 -> V_58 >= 0 )
V_315 = V_4 -> V_130 [ V_4 -> V_58 ] . V_60 ;
F_51 ( & V_104 ) ;
if ( V_315 == NULL )
return 1 ;
V_33 -> V_316 = V_33 -> V_205 ;
F_79 ( V_33 , ( V_192 * ) V_292 - V_33 -> V_207 ) ;
F_111 ( V_33 ) ;
V_33 -> V_77 = F_114 ( V_317 ) ;
V_33 -> V_318 = V_319 ;
V_33 -> V_320 = V_321 ;
F_194 ( V_33 , V_315 ) ;
F_195 ( V_33 ) ;
return V_322 ;
}
int F_196 ( struct V_32 * V_33 )
{
struct V_195 * V_323 ;
struct V_2 * V_2 = F_33 ( V_33 -> V_60 ) ;
struct V_1 * V_4 ;
if ( ! F_197 ( V_33 , sizeof( * V_323 ) + sizeof( struct V_114 ) ) )
goto V_324;
V_323 = F_198 ( V_33 ) ;
V_4 = F_186 ( V_2 , V_33 ) ;
if ( F_13 ( V_4 ) )
goto V_324;
if ( ! V_4 -> V_249 ||
V_323 -> V_325 != V_326 || V_323 -> V_208 != V_327 )
goto V_324;
if ( F_192 ( V_4 , V_33 , sizeof( * V_323 ) ) ) {
V_324:
F_48 ( V_33 ) ;
}
return 0 ;
}
static int F_199 ( struct V_32 * V_33 )
{
struct V_328 * V_323 ;
struct V_2 * V_2 = F_33 ( V_33 -> V_60 ) ;
struct V_1 * V_4 ;
if ( ! F_197 ( V_33 , sizeof( * V_323 ) + sizeof( struct V_114 ) ) )
goto V_324;
V_323 = (struct V_328 * ) F_193 ( V_33 ) ;
if ( V_323 -> type != ( ( V_329 << 4 ) | ( V_330 ) ) ||
( V_323 -> V_19 & V_331 ) ||
( F_200 ( ( void * ) V_323 , sizeof( * V_323 ) ) != 0 &&
F_201 ( F_202 ( V_33 , 0 , V_33 -> V_107 , 0 ) ) ) )
goto V_324;
V_4 = F_186 ( V_2 , V_33 ) ;
if ( F_13 ( V_4 ) )
goto V_324;
if ( F_192 ( V_4 , V_33 , sizeof( * V_323 ) ) ) {
V_324:
F_48 ( V_33 ) ;
}
return 0 ;
}
static int F_104 ( struct V_1 * V_4 , struct V_32 * V_33 ,
struct V_137 * V_138 , struct V_332 * V_333 )
{
int V_280 ;
struct V_334 * V_335 ;
struct V_36 * V_336 ;
struct V_337 V_338 ;
if ( V_138 -> V_211 >= V_166 )
return - V_219 ;
if ( F_63 ( V_4 , V_138 -> V_211 ) &&
F_203 ( V_33 , V_339 , V_4 -> V_130 [ V_138 -> V_211 ] . V_60 -> V_99 ) < 0 )
return - V_193 ;
if ( ! ( V_336 = F_204 ( V_33 , V_340 ) ) )
return - V_193 ;
for ( V_280 = V_138 -> V_144 . V_8 . V_165 ; V_280 < V_138 -> V_144 . V_8 . V_128 ; V_280 ++ ) {
if ( F_63 ( V_4 , V_280 ) && V_138 -> V_144 . V_8 . V_164 [ V_280 ] < 255 ) {
if ( ! ( V_335 = F_205 ( V_33 , sizeof( * V_335 ) ) ) ) {
F_206 ( V_33 , V_336 ) ;
return - V_193 ;
}
V_335 -> V_341 = 0 ;
V_335 -> V_342 = V_138 -> V_144 . V_8 . V_164 [ V_280 ] ;
V_335 -> V_343 = V_4 -> V_130 [ V_280 ] . V_60 -> V_99 ;
V_335 -> V_344 = sizeof( * V_335 ) ;
}
}
F_207 ( V_33 , V_336 ) ;
V_338 . V_345 = V_138 -> V_144 . V_8 . V_194 ;
V_338 . V_346 = V_138 -> V_144 . V_8 . V_271 ;
V_338 . V_347 = V_138 -> V_144 . V_8 . V_272 ;
if ( F_208 ( V_33 , V_348 , sizeof( V_338 ) , & V_338 ) < 0 )
return - V_193 ;
V_333 -> V_349 = V_350 ;
return 1 ;
}
int F_209 ( struct V_2 * V_2 , struct V_32 * V_33 ,
T_6 V_73 , T_6 V_70 ,
struct V_332 * V_333 , int V_351 )
{
struct V_137 * V_163 ;
struct V_1 * V_4 ;
int V_12 ;
V_4 = F_1 ( V_2 , V_45 ) ;
if ( V_4 == NULL )
return - V_219 ;
F_57 () ;
V_163 = F_95 ( V_4 , V_73 , V_70 ) ;
if ( V_163 == NULL ) {
struct V_32 * V_307 ;
struct V_114 * V_69 ;
struct V_59 * V_60 ;
int V_231 = - 1 ;
if ( V_351 ) {
F_59 () ;
return - V_30 ;
}
V_60 = V_33 -> V_60 ;
F_49 ( & V_104 ) ;
if ( V_60 )
V_231 = F_182 ( V_4 , V_60 ) ;
if ( V_231 < 0 ) {
F_51 ( & V_104 ) ;
F_59 () ;
return - V_313 ;
}
V_307 = F_185 ( V_33 , V_190 ) ;
if ( ! V_307 ) {
F_51 ( & V_104 ) ;
F_59 () ;
return - V_46 ;
}
F_110 ( V_307 , sizeof( struct V_114 ) ) ;
F_111 ( V_307 ) ;
V_69 = F_78 ( V_307 ) ;
V_69 -> V_76 = sizeof( struct V_114 ) >> 2 ;
V_69 -> V_73 = V_73 ;
V_69 -> V_70 = V_70 ;
V_69 -> V_75 = 0 ;
V_12 = F_124 ( V_4 , V_231 , V_307 ) ;
F_51 ( & V_104 ) ;
F_59 () ;
return V_12 ;
}
F_49 ( & V_104 ) ;
if ( ! V_351 && ( V_333 -> V_352 & V_353 ) )
V_163 -> V_223 |= V_354 ;
V_12 = F_104 ( V_4 , V_33 , V_163 , V_333 ) ;
F_51 ( & V_104 ) ;
F_59 () ;
return V_12 ;
}
static int F_210 ( struct V_1 * V_4 , struct V_32 * V_33 ,
T_1 V_154 , T_1 V_355 , struct V_137 * V_138 , int V_256 )
{
struct V_147 * V_148 ;
struct V_332 * V_333 ;
int V_12 ;
V_148 = F_211 ( V_33 , V_154 , V_355 , V_256 , sizeof( * V_333 ) , V_356 ) ;
if ( V_148 == NULL )
return - V_193 ;
V_333 = F_212 ( V_148 ) ;
V_333 -> V_357 = V_358 ;
V_333 -> V_359 = 32 ;
V_333 -> V_360 = 32 ;
V_333 -> V_361 = 0 ;
V_333 -> V_362 = V_4 -> V_3 ;
if ( F_203 ( V_33 , V_363 , V_4 -> V_3 ) )
goto V_364;
V_333 -> V_349 = V_350 ;
V_333 -> V_365 = V_366 ;
if ( V_138 -> V_223 & V_224 )
V_333 -> V_367 = V_368 ;
else
V_333 -> V_367 = V_369 ;
V_333 -> V_352 = 0 ;
if ( F_213 ( V_33 , V_370 , V_138 -> V_188 ) ||
F_213 ( V_33 , V_371 , V_138 -> V_189 ) )
goto V_364;
V_12 = F_104 ( V_4 , V_33 , V_138 , V_333 ) ;
if ( V_12 < 0 && V_12 != - V_219 )
goto V_364;
return F_214 ( V_33 , V_148 ) ;
V_364:
F_215 ( V_33 , V_148 ) ;
return - V_193 ;
}
static T_8 F_216 ( bool V_146 , int V_128 )
{
T_8 V_107 =
F_217 ( sizeof( struct V_332 ) )
+ F_218 ( 4 )
+ F_218 ( 4 )
+ F_218 ( 4 )
;
if ( ! V_146 )
V_107 = V_107
+ F_218 ( 4 )
+ F_218 ( 0 )
+ V_128 * F_219 ( sizeof( struct V_334 ) )
+ F_218 ( sizeof( struct V_337 ) )
;
return V_107 ;
}
static void F_89 ( struct V_1 * V_4 , struct V_137 * V_216 ,
int V_256 )
{
struct V_2 * V_2 = F_75 ( & V_4 -> V_2 ) ;
struct V_32 * V_33 ;
int V_12 = - V_171 ;
V_33 = F_220 ( F_216 ( V_216 -> V_211 >= V_166 , V_4 -> V_128 ) ,
V_190 ) ;
if ( V_33 == NULL )
goto V_372;
V_12 = F_210 ( V_4 , V_33 , 0 , 0 , V_216 , V_256 ) ;
if ( V_12 < 0 )
goto V_372;
F_221 ( V_33 , V_2 , 0 , V_373 , NULL , V_190 ) ;
return;
V_372:
F_48 ( V_33 ) ;
if ( V_12 < 0 )
F_222 ( V_2 , V_373 , V_12 ) ;
}
static int F_223 ( struct V_32 * V_33 , struct V_374 * V_375 )
{
struct V_2 * V_2 = F_141 ( V_33 -> V_225 ) ;
struct V_1 * V_4 ;
struct V_137 * V_216 ;
unsigned int V_376 = 0 , V_377 ;
unsigned int V_378 = 0 , V_379 ;
unsigned int V_142 = 0 , V_380 ;
V_377 = V_375 -> args [ 0 ] ;
V_379 = V_375 -> args [ 1 ] ;
V_380 = V_375 -> args [ 2 ] ;
F_57 () ;
F_2 (mrt, net) {
if ( V_376 < V_377 )
goto V_381;
if ( V_376 > V_377 )
V_379 = 0 ;
for ( V_378 = V_379 ; V_378 < V_53 ; V_378 ++ ) {
F_97 (mfc, &mrt->mfc_cache_array[h], list) {
if ( V_142 < V_380 )
goto V_382;
if ( F_210 ( V_4 , V_33 ,
F_84 ( V_375 -> V_33 ) . V_154 ,
V_375 -> V_148 -> V_383 ,
V_216 , V_213 ) < 0 )
goto V_384;
V_382:
V_142 ++ ;
}
V_142 = V_380 = 0 ;
}
F_125 ( & V_157 ) ;
F_126 (mfc, &mrt->mfc_unres_queue, list) {
if ( V_142 < V_380 )
goto V_385;
if ( F_210 ( V_4 , V_33 ,
F_84 ( V_375 -> V_33 ) . V_154 ,
V_375 -> V_148 -> V_383 ,
V_216 , V_213 ) < 0 ) {
F_128 ( & V_157 ) ;
goto V_384;
}
V_385:
V_142 ++ ;
}
F_128 ( & V_157 ) ;
V_142 = V_380 = 0 ;
V_379 = 0 ;
V_381:
V_376 ++ ;
}
V_384:
F_59 () ;
V_375 -> args [ 2 ] = V_142 ;
V_375 -> args [ 1 ] = V_378 ;
V_375 -> args [ 0 ] = V_376 ;
return V_33 -> V_107 ;
}
static struct V_127 * F_224 ( struct V_2 * V_2 ,
struct V_386 * V_387 ,
T_9 V_388 )
{
struct V_1 * V_4 = V_387 -> V_4 ;
for ( V_387 -> V_280 = 0 ; V_387 -> V_280 < V_4 -> V_128 ; ++ V_387 -> V_280 ) {
if ( ! F_63 ( V_4 , V_387 -> V_280 ) )
continue;
if ( V_388 -- == 0 )
return & V_4 -> V_130 [ V_387 -> V_280 ] ;
}
return NULL ;
}
static void * F_225 ( struct V_389 * V_355 , T_9 * V_388 )
__acquires( V_104 )
{
struct V_386 * V_387 = V_355 -> V_390 ;
struct V_2 * V_2 = F_226 ( V_355 ) ;
struct V_1 * V_4 ;
V_4 = F_1 ( V_2 , V_45 ) ;
if ( V_4 == NULL )
return F_187 ( - V_219 ) ;
V_387 -> V_4 = V_4 ;
F_49 ( & V_104 ) ;
return * V_388 ? F_224 ( V_2 , V_355 -> V_390 , * V_388 - 1 )
: V_391 ;
}
static void * F_227 ( struct V_389 * V_355 , void * V_62 , T_9 * V_388 )
{
struct V_386 * V_387 = V_355 -> V_390 ;
struct V_2 * V_2 = F_226 ( V_355 ) ;
struct V_1 * V_4 = V_387 -> V_4 ;
++ * V_388 ;
if ( V_62 == V_391 )
return F_224 ( V_2 , V_387 , 0 ) ;
while ( ++ V_387 -> V_280 < V_4 -> V_128 ) {
if ( ! F_63 ( V_4 , V_387 -> V_280 ) )
continue;
return & V_4 -> V_130 [ V_387 -> V_280 ] ;
}
return NULL ;
}
static void F_228 ( struct V_389 * V_355 , void * V_62 )
__releases( V_104 )
{
F_51 ( & V_104 ) ;
}
static int F_229 ( struct V_389 * V_355 , void * V_62 )
{
struct V_386 * V_387 = V_355 -> V_390 ;
struct V_1 * V_4 = V_387 -> V_4 ;
if ( V_62 == V_391 ) {
F_230 ( V_355 ,
L_6 ) ;
} else {
const struct V_127 * V_231 = V_62 ;
const char * V_79 = V_231 -> V_60 ? V_231 -> V_60 -> V_79 : L_7 ;
F_231 ( V_355 ,
L_8 ,
V_231 - V_4 -> V_130 ,
V_79 , V_231 -> V_181 , V_231 -> V_183 ,
V_231 -> V_182 , V_231 -> V_184 ,
V_231 -> V_19 , V_231 -> V_176 , V_231 -> V_177 ) ;
}
return 0 ;
}
static int F_232 ( struct V_392 * V_392 , struct V_393 * V_393 )
{
return F_233 ( V_392 , V_393 , & V_394 ,
sizeof( struct V_386 ) ) ;
}
static struct V_137 * F_234 ( struct V_2 * V_2 ,
struct V_395 * V_396 , T_9 V_388 )
{
struct V_1 * V_4 = V_396 -> V_4 ;
struct V_137 * V_216 ;
F_57 () ;
for ( V_396 -> V_280 = 0 ; V_396 -> V_280 < V_53 ; V_396 -> V_280 ++ ) {
V_396 -> V_163 = & V_4 -> V_54 [ V_396 -> V_280 ] ;
F_97 (mfc, it->cache, list)
if ( V_388 -- == 0 )
return V_216 ;
}
F_59 () ;
F_125 ( & V_157 ) ;
V_396 -> V_163 = & V_4 -> V_55 ;
F_126 (mfc, it->cache, list)
if ( V_388 -- == 0 )
return V_216 ;
F_128 ( & V_157 ) ;
V_396 -> V_163 = NULL ;
return NULL ;
}
static void * F_235 ( struct V_389 * V_355 , T_9 * V_388 )
{
struct V_395 * V_396 = V_355 -> V_390 ;
struct V_2 * V_2 = F_226 ( V_355 ) ;
struct V_1 * V_4 ;
V_4 = F_1 ( V_2 , V_45 ) ;
if ( V_4 == NULL )
return F_187 ( - V_219 ) ;
V_396 -> V_4 = V_4 ;
V_396 -> V_163 = NULL ;
V_396 -> V_280 = 0 ;
return * V_388 ? F_234 ( V_2 , V_355 -> V_390 , * V_388 - 1 )
: V_391 ;
}
static void * F_236 ( struct V_389 * V_355 , void * V_62 , T_9 * V_388 )
{
struct V_137 * V_216 = V_62 ;
struct V_395 * V_396 = V_355 -> V_390 ;
struct V_2 * V_2 = F_226 ( V_355 ) ;
struct V_1 * V_4 = V_396 -> V_4 ;
++ * V_388 ;
if ( V_62 == V_391 )
return F_234 ( V_2 , V_355 -> V_390 , 0 ) ;
if ( V_216 -> V_50 . V_49 != V_396 -> V_163 )
return F_237 ( V_216 -> V_50 . V_49 , struct V_137 , V_50 ) ;
if ( V_396 -> V_163 == & V_4 -> V_55 )
goto V_397;
F_238 ( V_396 -> V_163 != & V_4 -> V_54 [ V_396 -> V_280 ] ) ;
while ( ++ V_396 -> V_280 < V_53 ) {
V_396 -> V_163 = & V_4 -> V_54 [ V_396 -> V_280 ] ;
if ( F_87 ( V_396 -> V_163 ) )
continue;
return F_239 ( V_396 -> V_163 , struct V_137 , V_50 ) ;
}
F_59 () ;
V_396 -> V_163 = & V_4 -> V_55 ;
V_396 -> V_280 = 0 ;
F_125 ( & V_157 ) ;
if ( ! F_87 ( V_396 -> V_163 ) )
return F_239 ( V_396 -> V_163 , struct V_137 , V_50 ) ;
V_397:
F_128 ( & V_157 ) ;
V_396 -> V_163 = NULL ;
return NULL ;
}
static void F_240 ( struct V_389 * V_355 , void * V_62 )
{
struct V_395 * V_396 = V_355 -> V_390 ;
struct V_1 * V_4 = V_396 -> V_4 ;
if ( V_396 -> V_163 == & V_4 -> V_55 )
F_128 ( & V_157 ) ;
else if ( V_396 -> V_163 == & V_4 -> V_54 [ V_396 -> V_280 ] )
F_59 () ;
}
static int F_241 ( struct V_389 * V_355 , void * V_62 )
{
int V_398 ;
if ( V_62 == V_391 ) {
F_230 ( V_355 ,
L_9 ) ;
} else {
const struct V_137 * V_216 = V_62 ;
const struct V_395 * V_396 = V_355 -> V_390 ;
const struct V_1 * V_4 = V_396 -> V_4 ;
F_231 ( V_355 , L_10 ,
( V_83 T_1 ) V_216 -> V_189 ,
( V_83 T_1 ) V_216 -> V_188 ,
V_216 -> V_211 ) ;
if ( V_396 -> V_163 != & V_4 -> V_55 ) {
F_231 ( V_355 , L_11 ,
V_216 -> V_144 . V_8 . V_194 ,
V_216 -> V_144 . V_8 . V_271 ,
V_216 -> V_144 . V_8 . V_272 ) ;
for ( V_398 = V_216 -> V_144 . V_8 . V_165 ;
V_398 < V_216 -> V_144 . V_8 . V_128 ; V_398 ++ ) {
if ( F_63 ( V_4 , V_398 ) &&
V_216 -> V_144 . V_8 . V_164 [ V_398 ] < 255 )
F_231 ( V_355 ,
L_12 ,
V_398 , V_216 -> V_144 . V_8 . V_164 [ V_398 ] ) ;
}
} else {
F_231 ( V_355 , L_11 , 0ul , 0ul , 0ul ) ;
}
F_242 ( V_355 , '\n' ) ;
}
return 0 ;
}
static int F_243 ( struct V_392 * V_392 , struct V_393 * V_393 )
{
return F_233 ( V_392 , V_393 , & V_399 ,
sizeof( struct V_395 ) ) ;
}
static int T_2 F_244 ( struct V_2 * V_2 )
{
int V_12 ;
V_12 = F_11 ( V_2 ) ;
if ( V_12 < 0 )
goto V_400;
#ifdef F_245
V_12 = - V_46 ;
if ( ! F_246 ( V_2 , L_13 , 0 , & V_401 ) )
goto V_402;
if ( ! F_246 ( V_2 , L_14 , 0 , & V_403 ) )
goto V_404;
#endif
return 0 ;
#ifdef F_245
V_404:
F_247 ( V_2 , L_13 ) ;
V_402:
F_20 ( V_2 ) ;
#endif
V_400:
return V_12 ;
}
static void T_3 F_248 ( struct V_2 * V_2 )
{
#ifdef F_245
F_247 ( V_2 , L_14 ) ;
F_247 ( V_2 , L_13 ) ;
#endif
F_20 ( V_2 ) ;
}
int T_10 F_249 ( void )
{
int V_12 ;
V_140 = F_250 ( L_15 ,
sizeof( struct V_137 ) ,
0 , V_405 | V_406 ,
NULL ) ;
if ( ! V_140 )
return - V_46 ;
V_12 = F_251 ( & V_407 ) ;
if ( V_12 )
goto V_408;
V_12 = F_252 ( & V_409 ) ;
if ( V_12 )
goto V_410;
#ifdef F_253
if ( F_254 ( & V_411 , V_412 ) < 0 ) {
F_255 ( L_16 , V_413 ) ;
V_12 = - V_30 ;
goto V_414;
}
#endif
F_256 ( V_358 , V_415 ,
NULL , F_223 , NULL ) ;
return 0 ;
#ifdef F_253
V_414:
F_257 ( & V_409 ) ;
#endif
V_410:
F_258 ( & V_407 ) ;
V_408:
F_259 ( V_140 ) ;
return V_12 ;
}
