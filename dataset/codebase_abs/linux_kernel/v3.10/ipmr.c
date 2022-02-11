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
static struct V_137 * F_98 ( struct V_1 * V_4 ,
int V_123 )
{
int line = F_96 ( F_99 ( V_190 ) , F_99 ( V_190 ) ) ;
struct V_137 * V_138 ;
F_97 (c, &mrt->mfc_cache_array[line], list)
if ( V_138 -> V_188 == F_99 ( V_190 ) &&
V_138 -> V_189 == F_99 ( V_190 ) &&
V_138 -> V_144 . V_8 . V_164 [ V_123 ] < 255 )
return V_138 ;
return NULL ;
}
static struct V_137 * F_100 ( struct V_1 * V_4 ,
T_6 V_187 , int V_123 )
{
int line = F_96 ( V_187 , F_99 ( V_190 ) ) ;
struct V_137 * V_138 , * V_191 ;
if ( V_187 == F_99 ( V_190 ) )
goto V_192;
F_97 (c, &mrt->mfc_cache_array[line], list)
if ( V_138 -> V_188 == F_99 ( V_190 ) &&
V_138 -> V_189 == V_187 ) {
if ( V_138 -> V_144 . V_8 . V_164 [ V_123 ] < 255 )
return V_138 ;
V_191 = F_98 ( V_4 ,
V_138 -> V_193 ) ;
if ( V_191 && V_191 -> V_144 . V_8 . V_164 [ V_123 ] < 255 )
return V_138 ;
}
V_192:
return F_98 ( V_4 , V_123 ) ;
}
static struct V_137 * F_101 ( void )
{
struct V_137 * V_138 = F_102 ( V_140 , V_52 ) ;
if ( V_138 )
V_138 -> V_144 . V_8 . V_165 = V_166 ;
return V_138 ;
}
static struct V_137 * F_103 ( void )
{
struct V_137 * V_138 = F_102 ( V_140 , V_194 ) ;
if ( V_138 ) {
F_104 ( & V_138 -> V_144 . V_145 . V_146 ) ;
V_138 -> V_144 . V_145 . V_156 = V_158 + 10 * V_159 ;
}
return V_138 ;
}
static void F_105 ( struct V_2 * V_2 , struct V_1 * V_4 ,
struct V_137 * V_195 , struct V_137 * V_138 )
{
struct V_32 * V_33 ;
struct V_141 * V_142 ;
while ( ( V_33 = F_106 ( & V_195 -> V_144 . V_145 . V_146 ) ) ) {
if ( F_78 ( V_33 ) -> V_75 == 0 ) {
struct V_147 * V_148 = (struct V_147 * ) F_79 ( V_33 , sizeof( struct V_114 ) ) ;
if ( F_107 ( V_4 , V_33 , V_138 , F_82 ( V_148 ) ) > 0 ) {
V_148 -> V_151 = F_108 ( V_33 ) -
( V_196 * ) V_148 ;
} else {
V_148 -> V_149 = V_150 ;
V_148 -> V_151 = F_80 ( sizeof( struct V_141 ) ) ;
F_81 ( V_33 , V_148 -> V_151 ) ;
V_142 = F_82 ( V_148 ) ;
V_142 -> error = - V_197 ;
memset ( & V_142 -> V_153 , 0 , sizeof( V_142 -> V_153 ) ) ;
}
F_83 ( V_33 , V_2 , F_84 ( V_33 ) . V_154 ) ;
} else {
F_109 ( V_2 , V_4 , V_33 , V_138 , 0 ) ;
}
}
}
static int F_50 ( struct V_1 * V_4 ,
struct V_32 * V_198 , T_7 V_123 , int assert )
{
struct V_32 * V_33 ;
const int V_76 = F_110 ( V_198 ) ;
struct V_199 * V_200 ;
struct V_201 * V_153 ;
struct V_202 * V_203 ;
int V_204 ;
#ifdef F_27
if ( assert == V_109 )
V_33 = F_111 ( V_198 , sizeof( struct V_114 ) ) ;
else
#endif
V_33 = F_112 ( 128 , V_194 ) ;
if ( ! V_33 )
return - V_171 ;
#ifdef F_27
if ( assert == V_109 ) {
F_113 ( V_33 , sizeof( struct V_114 ) ) ;
F_114 ( V_33 ) ;
F_115 ( V_33 ) ;
V_153 = (struct V_201 * ) F_116 ( V_33 ) ;
memcpy ( V_153 , F_116 ( V_198 ) , sizeof( struct V_114 ) ) ;
V_153 -> V_205 = V_109 ;
V_153 -> V_206 = 0 ;
V_153 -> V_207 = V_4 -> V_58 ;
F_78 ( V_33 ) -> V_76 = sizeof( struct V_114 ) >> 2 ;
F_78 ( V_33 ) -> V_208 = F_117 ( F_118 ( F_78 ( V_198 ) -> V_208 ) +
sizeof( struct V_114 ) ) ;
} else
#endif
{
V_33 -> V_209 = V_33 -> V_210 ;
F_119 ( V_33 , V_76 ) ;
F_120 ( V_33 , V_198 -> V_211 , V_76 ) ;
F_78 ( V_33 ) -> V_77 = 0 ;
V_153 = (struct V_201 * ) F_116 ( V_33 ) ;
V_153 -> V_207 = V_123 ;
F_121 ( V_33 , F_122 ( F_123 ( V_198 ) ) ) ;
V_200 = (struct V_199 * ) F_119 ( V_33 , sizeof( struct V_199 ) ) ;
V_200 -> type =
V_153 -> V_205 = assert ;
V_200 -> V_212 = 0 ;
F_78 ( V_33 ) -> V_208 = F_117 ( V_33 -> V_107 ) ;
V_33 -> V_213 = V_33 -> V_209 ;
}
F_57 () ;
V_203 = F_124 ( V_4 -> V_203 ) ;
if ( V_203 == NULL ) {
F_59 () ;
F_48 ( V_33 ) ;
return - V_27 ;
}
V_204 = F_125 ( V_203 , V_33 ) ;
F_59 () ;
if ( V_204 < 0 ) {
F_126 ( L_5 ) ;
F_48 ( V_33 ) ;
}
return V_204 ;
}
static int
F_127 ( struct V_1 * V_4 , T_7 V_123 , struct V_32 * V_33 )
{
bool V_214 = false ;
int V_12 ;
struct V_137 * V_138 ;
const struct V_114 * V_69 = F_78 ( V_33 ) ;
F_128 ( & V_157 ) ;
F_129 (c, &mrt->mfc_unres_queue, list) {
if ( V_138 -> V_189 == V_69 -> V_70 &&
V_138 -> V_188 == V_69 -> V_73 ) {
V_214 = true ;
break;
}
}
if ( ! V_214 ) {
if ( F_130 ( & V_4 -> V_143 ) >= 10 ||
( V_138 = F_103 () ) == NULL ) {
F_131 ( & V_157 ) ;
F_48 ( V_33 ) ;
return - V_171 ;
}
V_138 -> V_193 = - 1 ;
V_138 -> V_188 = V_69 -> V_73 ;
V_138 -> V_189 = V_69 -> V_70 ;
V_12 = F_50 ( V_4 , V_33 , V_123 , V_215 ) ;
if ( V_12 < 0 ) {
F_131 ( & V_157 ) ;
F_72 ( V_138 ) ;
F_48 ( V_33 ) ;
return V_12 ;
}
F_132 ( & V_4 -> V_143 ) ;
F_133 ( & V_138 -> V_50 , & V_4 -> V_55 ) ;
F_89 ( V_4 , V_138 , V_216 ) ;
if ( F_130 ( & V_4 -> V_143 ) == 1 )
F_86 ( & V_4 -> V_56 , V_138 -> V_144 . V_145 . V_156 ) ;
}
if ( V_138 -> V_144 . V_145 . V_146 . V_217 > 3 ) {
F_48 ( V_33 ) ;
V_12 = - V_171 ;
} else {
F_134 ( & V_138 -> V_144 . V_145 . V_146 , V_33 ) ;
V_12 = 0 ;
}
F_131 ( & V_157 ) ;
return V_12 ;
}
static int F_135 ( struct V_1 * V_4 , struct V_218 * V_219 , int V_220 )
{
int line ;
struct V_137 * V_138 , * V_49 ;
line = F_96 ( V_219 -> V_221 . V_72 , V_219 -> V_222 . V_72 ) ;
F_21 (c, next, &mrt->mfc_cache_array[line], list) {
if ( V_138 -> V_188 == V_219 -> V_222 . V_72 &&
V_138 -> V_189 == V_219 -> V_221 . V_72 &&
( V_220 == - 1 || V_220 == V_138 -> V_193 ) ) {
F_136 ( & V_138 -> V_50 ) ;
F_89 ( V_4 , V_138 , V_162 ) ;
F_72 ( V_138 ) ;
return 0 ;
}
}
return - V_223 ;
}
static int F_137 ( struct V_2 * V_2 , struct V_1 * V_4 ,
struct V_218 * V_219 , int V_168 , int V_220 )
{
bool V_214 = false ;
int line ;
struct V_137 * V_195 , * V_138 ;
if ( V_219 -> V_224 >= V_166 )
return - V_225 ;
line = F_96 ( V_219 -> V_221 . V_72 , V_219 -> V_222 . V_72 ) ;
F_129 (c, &mrt->mfc_cache_array[line], list) {
if ( V_138 -> V_188 == V_219 -> V_222 . V_72 &&
V_138 -> V_189 == V_219 -> V_221 . V_72 &&
( V_220 == - 1 || V_220 == V_138 -> V_193 ) ) {
V_214 = true ;
break;
}
}
if ( V_214 ) {
F_61 ( & V_104 ) ;
V_138 -> V_193 = V_219 -> V_224 ;
F_91 ( V_4 , V_138 , V_219 -> V_226 ) ;
if ( ! V_168 )
V_138 -> V_227 |= V_228 ;
F_62 ( & V_104 ) ;
F_89 ( V_4 , V_138 , V_216 ) ;
return 0 ;
}
if ( V_219 -> V_221 . V_72 != F_99 ( V_190 ) &&
! F_138 ( V_219 -> V_221 . V_72 ) )
return - V_27 ;
V_138 = F_101 () ;
if ( V_138 == NULL )
return - V_46 ;
V_138 -> V_188 = V_219 -> V_222 . V_72 ;
V_138 -> V_189 = V_219 -> V_221 . V_72 ;
V_138 -> V_193 = V_219 -> V_224 ;
F_91 ( V_4 , V_138 , V_219 -> V_226 ) ;
if ( ! V_168 )
V_138 -> V_227 |= V_228 ;
F_139 ( & V_138 -> V_50 , & V_4 -> V_54 [ line ] ) ;
V_214 = false ;
F_128 ( & V_157 ) ;
F_129 (uc, &mrt->mfc_unres_queue, list) {
if ( V_195 -> V_188 == V_138 -> V_188 &&
V_195 -> V_189 == V_138 -> V_189 ) {
F_22 ( & V_195 -> V_50 ) ;
F_76 ( & V_4 -> V_143 ) ;
V_214 = true ;
break;
}
}
if ( F_87 ( & V_4 -> V_55 ) )
F_140 ( & V_4 -> V_56 ) ;
F_131 ( & V_157 ) ;
if ( V_214 ) {
F_105 ( V_2 , V_4 , V_195 , V_138 ) ;
F_72 ( V_195 ) ;
}
F_89 ( V_4 , V_138 , V_216 ) ;
return 0 ;
}
static void F_31 ( struct V_1 * V_4 )
{
int V_51 ;
F_141 ( V_50 ) ;
struct V_137 * V_138 , * V_49 ;
for ( V_51 = 0 ; V_51 < V_4 -> V_128 ; V_51 ++ ) {
if ( ! ( V_4 -> V_130 [ V_51 ] . V_19 & V_178 ) )
F_60 ( V_4 , V_51 , 0 , & V_50 ) ;
}
F_142 ( & V_50 ) ;
for ( V_51 = 0 ; V_51 < V_53 ; V_51 ++ ) {
F_21 (c, next, &mrt->mfc_cache_array[i], list) {
if ( V_138 -> V_227 & V_228 )
continue;
F_136 ( & V_138 -> V_50 ) ;
F_89 ( V_4 , V_138 , V_162 ) ;
F_72 ( V_138 ) ;
}
}
if ( F_130 ( & V_4 -> V_143 ) != 0 ) {
F_128 ( & V_157 ) ;
F_21 (c, next, &mrt->mfc_unres_queue, list) {
F_22 ( & V_138 -> V_50 ) ;
F_89 ( V_4 , V_138 , V_162 ) ;
F_74 ( V_4 , V_138 ) ;
}
F_131 ( & V_157 ) ;
}
}
static void F_143 ( struct V_202 * V_229 )
{
struct V_2 * V_2 = F_144 ( V_229 ) ;
struct V_1 * V_4 ;
F_45 () ;
F_2 (mrt, net) {
if ( V_229 == F_145 ( V_4 -> V_203 ) ) {
F_146 ( V_2 , V_132 ) -- ;
F_65 ( V_2 , V_133 ,
V_230 ,
V_2 -> V_13 . V_231 ) ;
F_147 ( V_4 -> V_203 , NULL ) ;
F_31 ( V_4 ) ;
}
}
F_44 () ;
}
int F_148 ( struct V_202 * V_229 , int V_232 , char V_84 * V_233 , unsigned int V_234 )
{
int V_204 , V_220 = 0 ;
struct V_61 V_235 ;
struct V_218 V_219 ;
struct V_2 * V_2 = F_144 ( V_229 ) ;
struct V_1 * V_4 ;
if ( V_229 -> V_236 != V_237 ||
F_149 ( V_229 ) -> V_238 != V_239 )
return - V_92 ;
V_4 = F_1 ( V_2 , F_150 ( V_229 ) -> V_240 ? : V_45 ) ;
if ( V_4 == NULL )
return - V_223 ;
if ( V_232 != V_241 ) {
if ( V_229 != F_151 ( V_4 -> V_203 ) &&
! F_152 ( V_2 -> V_242 , V_243 ) )
return - V_25 ;
}
switch ( V_232 ) {
case V_241 :
if ( V_234 != sizeof( int ) )
return - V_27 ;
F_45 () ;
if ( F_145 ( V_4 -> V_203 ) ) {
F_44 () ;
return - V_169 ;
}
V_204 = F_153 ( V_229 , 1 , F_143 ) ;
if ( V_204 == 0 ) {
F_154 ( V_4 -> V_203 , V_229 ) ;
F_146 ( V_2 , V_132 ) ++ ;
F_65 ( V_2 , V_133 ,
V_230 ,
V_2 -> V_13 . V_231 ) ;
}
F_44 () ;
return V_204 ;
case V_244 :
if ( V_229 != F_151 ( V_4 -> V_203 ) )
return - V_25 ;
return F_153 ( V_229 , 0 , NULL ) ;
case V_245 :
case V_246 :
if ( V_234 != sizeof( V_235 ) )
return - V_27 ;
if ( F_155 ( & V_235 , V_233 , sizeof( V_235 ) ) )
return - V_247 ;
if ( V_235 . V_80 >= V_166 )
return - V_225 ;
F_45 () ;
if ( V_232 == V_245 ) {
V_204 = F_92 ( V_2 , V_4 , & V_235 ,
V_229 == F_145 ( V_4 -> V_203 ) ) ;
} else {
V_204 = F_60 ( V_4 , V_235 . V_80 , 0 , NULL ) ;
}
F_44 () ;
return V_204 ;
case V_248 :
case V_249 :
V_220 = - 1 ;
case V_250 :
case V_251 :
if ( V_234 != sizeof( V_219 ) )
return - V_27 ;
if ( F_155 ( & V_219 , V_233 , sizeof( V_219 ) ) )
return - V_247 ;
if ( V_220 == 0 )
V_220 = V_219 . V_224 ;
F_45 () ;
if ( V_232 == V_249 || V_232 == V_251 )
V_204 = F_135 ( V_4 , & V_219 , V_220 ) ;
else
V_204 = F_137 ( V_2 , V_4 , & V_219 ,
V_229 == F_145 ( V_4 -> V_203 ) ,
V_220 ) ;
F_44 () ;
return V_204 ;
case V_252 :
{
int V_62 ;
if ( V_234 != sizeof( V_62 ) )
return - V_27 ;
if ( F_156 ( V_62 , ( int V_84 * ) V_233 ) )
return - V_247 ;
V_4 -> V_253 = V_62 ;
return 0 ;
}
#ifdef F_27
case V_254 :
{
int V_62 ;
if ( V_234 != sizeof( V_62 ) )
return - V_27 ;
if ( F_156 ( V_62 , ( int V_84 * ) V_233 ) )
return - V_247 ;
V_62 = ! ! V_62 ;
F_45 () ;
V_204 = 0 ;
if ( V_62 != V_4 -> V_255 ) {
V_4 -> V_255 = V_62 ;
V_4 -> V_253 = V_62 ;
}
F_44 () ;
return V_204 ;
}
#endif
#ifdef F_28
case V_256 :
{
T_1 V_62 ;
if ( V_234 != sizeof( T_1 ) )
return - V_27 ;
if ( F_156 ( V_62 , ( T_1 V_84 * ) V_233 ) )
return - V_247 ;
if ( V_62 != V_45 && V_62 >= 1000000000 )
return - V_27 ;
F_45 () ;
V_204 = 0 ;
if ( V_229 == F_145 ( V_4 -> V_203 ) ) {
V_204 = - V_257 ;
} else {
if ( ! F_16 ( V_2 , V_62 ) )
V_204 = - V_46 ;
else
F_150 ( V_229 ) -> V_240 = V_62 ;
}
F_44 () ;
return V_204 ;
}
#endif
default:
return - V_258 ;
}
}
int F_157 ( struct V_202 * V_229 , int V_232 , char V_84 * V_233 , int V_84 * V_234 )
{
int V_259 ;
int V_260 ;
struct V_2 * V_2 = F_144 ( V_229 ) ;
struct V_1 * V_4 ;
if ( V_229 -> V_236 != V_237 ||
F_149 ( V_229 ) -> V_238 != V_239 )
return - V_92 ;
V_4 = F_1 ( V_2 , F_150 ( V_229 ) -> V_240 ? : V_45 ) ;
if ( V_4 == NULL )
return - V_223 ;
if ( V_232 != V_261 &&
#ifdef F_27
V_232 != V_254 &&
#endif
V_232 != V_252 )
return - V_258 ;
if ( F_156 ( V_259 , V_234 ) )
return - V_247 ;
V_259 = F_158 (unsigned int, olr, sizeof(int)) ;
if ( V_259 < 0 )
return - V_27 ;
if ( F_159 ( V_259 , V_234 ) )
return - V_247 ;
if ( V_232 == V_261 )
V_260 = 0x0305 ;
#ifdef F_27
else if ( V_232 == V_254 )
V_260 = V_4 -> V_255 ;
#endif
else
V_260 = V_4 -> V_253 ;
if ( F_160 ( V_233 , & V_260 , V_259 ) )
return - V_247 ;
return 0 ;
}
int F_161 ( struct V_202 * V_229 , int V_262 , void V_84 * V_10 )
{
struct V_263 V_264 ;
struct V_265 V_266 ;
struct V_127 * V_235 ;
struct V_137 * V_138 ;
struct V_2 * V_2 = F_144 ( V_229 ) ;
struct V_1 * V_4 ;
V_4 = F_1 ( V_2 , F_150 ( V_229 ) -> V_240 ? : V_45 ) ;
if ( V_4 == NULL )
return - V_223 ;
switch ( V_262 ) {
case V_267 :
if ( F_155 ( & V_266 , V_10 , sizeof( V_266 ) ) )
return - V_247 ;
if ( V_266 . V_123 >= V_4 -> V_128 )
return - V_27 ;
F_49 ( & V_104 ) ;
V_235 = & V_4 -> V_130 [ V_266 . V_123 ] ;
if ( F_63 ( V_4 , V_266 . V_123 ) ) {
V_266 . V_268 = V_235 -> V_183 ;
V_266 . V_269 = V_235 -> V_184 ;
V_266 . V_270 = V_235 -> V_181 ;
V_266 . V_271 = V_235 -> V_182 ;
F_51 ( & V_104 ) ;
if ( F_160 ( V_10 , & V_266 , sizeof( V_266 ) ) )
return - V_247 ;
return 0 ;
}
F_51 ( & V_104 ) ;
return - V_129 ;
case V_272 :
if ( F_155 ( & V_264 , V_10 , sizeof( V_264 ) ) )
return - V_247 ;
F_57 () ;
V_138 = F_95 ( V_4 , V_264 . V_273 . V_72 , V_264 . V_274 . V_72 ) ;
if ( V_138 ) {
V_264 . V_275 = V_138 -> V_144 . V_8 . V_198 ;
V_264 . V_276 = V_138 -> V_144 . V_8 . V_277 ;
V_264 . V_278 = V_138 -> V_144 . V_8 . V_278 ;
F_59 () ;
if ( F_160 ( V_10 , & V_264 , sizeof( V_264 ) ) )
return - V_247 ;
return 0 ;
}
F_59 () ;
return - V_129 ;
default:
return - V_279 ;
}
}
int F_162 ( struct V_202 * V_229 , unsigned int V_262 , void V_84 * V_10 )
{
struct V_280 V_264 ;
struct V_281 V_266 ;
struct V_127 * V_235 ;
struct V_137 * V_138 ;
struct V_2 * V_2 = F_144 ( V_229 ) ;
struct V_1 * V_4 ;
V_4 = F_1 ( V_2 , F_150 ( V_229 ) -> V_240 ? : V_45 ) ;
if ( V_4 == NULL )
return - V_223 ;
switch ( V_262 ) {
case V_267 :
if ( F_155 ( & V_266 , V_10 , sizeof( V_266 ) ) )
return - V_247 ;
if ( V_266 . V_123 >= V_4 -> V_128 )
return - V_27 ;
F_49 ( & V_104 ) ;
V_235 = & V_4 -> V_130 [ V_266 . V_123 ] ;
if ( F_63 ( V_4 , V_266 . V_123 ) ) {
V_266 . V_268 = V_235 -> V_183 ;
V_266 . V_269 = V_235 -> V_184 ;
V_266 . V_270 = V_235 -> V_181 ;
V_266 . V_271 = V_235 -> V_182 ;
F_51 ( & V_104 ) ;
if ( F_160 ( V_10 , & V_266 , sizeof( V_266 ) ) )
return - V_247 ;
return 0 ;
}
F_51 ( & V_104 ) ;
return - V_129 ;
case V_272 :
if ( F_155 ( & V_264 , V_10 , sizeof( V_264 ) ) )
return - V_247 ;
F_57 () ;
V_138 = F_95 ( V_4 , V_264 . V_273 . V_72 , V_264 . V_274 . V_72 ) ;
if ( V_138 ) {
V_264 . V_275 = V_138 -> V_144 . V_8 . V_198 ;
V_264 . V_276 = V_138 -> V_144 . V_8 . V_277 ;
V_264 . V_278 = V_138 -> V_144 . V_8 . V_278 ;
F_59 () ;
if ( F_160 ( V_10 , & V_264 , sizeof( V_264 ) ) )
return - V_247 ;
return 0 ;
}
F_59 () ;
return - V_129 ;
default:
return - V_279 ;
}
}
static int F_163 ( struct V_282 * V_283 , unsigned long V_284 , void * V_285 )
{
struct V_59 * V_60 = V_285 ;
struct V_2 * V_2 = F_33 ( V_60 ) ;
struct V_1 * V_4 ;
struct V_127 * V_62 ;
int V_286 ;
if ( V_284 != V_287 )
return V_288 ;
F_2 (mrt, net) {
V_62 = & V_4 -> V_130 [ 0 ] ;
for ( V_286 = 0 ; V_286 < V_4 -> V_128 ; V_286 ++ , V_62 ++ ) {
if ( V_62 -> V_60 == V_60 )
F_60 ( V_4 , V_286 , 1 , NULL ) ;
}
}
return V_288 ;
}
static void F_164 ( struct V_32 * V_33 , T_6 V_73 , T_6 V_70 )
{
struct V_114 * V_69 ;
const struct V_114 * V_289 = F_78 ( V_33 ) ;
F_113 ( V_33 , sizeof( struct V_114 ) ) ;
V_33 -> V_213 = V_33 -> V_209 ;
F_114 ( V_33 ) ;
V_69 = F_78 ( V_33 ) ;
V_69 -> V_75 = 4 ;
V_69 -> V_40 = V_289 -> V_40 ;
V_69 -> V_290 = V_289 -> V_290 ;
V_69 -> V_291 = 0 ;
V_69 -> V_70 = V_70 ;
V_69 -> V_73 = V_73 ;
V_69 -> V_77 = V_78 ;
V_69 -> V_76 = 5 ;
V_69 -> V_208 = F_117 ( V_33 -> V_107 ) ;
F_165 ( V_69 , F_123 ( V_33 ) , NULL ) ;
F_166 ( V_69 ) ;
memset ( & ( F_167 ( V_33 ) -> V_292 ) , 0 , sizeof( F_167 ( V_33 ) -> V_292 ) ) ;
F_168 ( V_33 ) ;
}
static inline int F_169 ( struct V_32 * V_33 )
{
struct V_293 * V_292 = & ( F_167 ( V_33 ) -> V_292 ) ;
F_170 ( F_33 ( F_123 ( V_33 ) -> V_60 ) , V_294 ) ;
F_171 ( F_33 ( F_123 ( V_33 ) -> V_60 ) , V_295 , V_33 -> V_107 ) ;
if ( F_172 ( V_292 -> V_234 ) )
F_173 ( V_33 ) ;
return F_174 ( V_33 ) ;
}
static void F_175 ( struct V_2 * V_2 , struct V_1 * V_4 ,
struct V_32 * V_33 , struct V_137 * V_138 , int V_123 )
{
const struct V_114 * V_69 = F_78 ( V_33 ) ;
struct V_127 * V_235 = & V_4 -> V_130 [ V_123 ] ;
struct V_59 * V_60 ;
struct V_296 * V_297 ;
struct V_5 V_97 ;
int V_298 = 0 ;
if ( V_235 -> V_60 == NULL )
goto V_299;
#ifdef F_27
if ( V_235 -> V_19 & V_135 ) {
V_235 -> V_184 ++ ;
V_235 -> V_182 += V_33 -> V_107 ;
V_235 -> V_60 -> V_105 . V_106 += V_33 -> V_107 ;
V_235 -> V_60 -> V_105 . V_108 ++ ;
F_50 ( V_4 , V_33 , V_123 , V_109 ) ;
goto V_299;
}
#endif
if ( V_235 -> V_19 & V_134 ) {
V_297 = F_176 ( V_2 , & V_97 , NULL ,
V_235 -> V_177 , V_235 -> V_176 ,
0 , 0 ,
V_78 ,
F_177 ( V_69 -> V_40 ) , V_235 -> V_185 ) ;
if ( F_13 ( V_297 ) )
goto V_299;
V_298 = sizeof( struct V_114 ) ;
} else {
V_297 = F_176 ( V_2 , & V_97 , NULL , V_69 -> V_70 , 0 ,
0 , 0 ,
V_78 ,
F_177 ( V_69 -> V_40 ) , V_235 -> V_185 ) ;
if ( F_13 ( V_297 ) )
goto V_299;
}
V_60 = V_297 -> V_300 . V_60 ;
if ( V_33 -> V_107 + V_298 > F_178 ( & V_297 -> V_300 ) && ( F_118 ( V_69 -> V_291 ) & V_301 ) ) {
F_170 ( F_33 ( V_60 ) , V_302 ) ;
F_179 ( V_297 ) ;
goto V_299;
}
V_298 += F_180 ( V_60 ) + V_297 -> V_300 . V_303 ;
if ( F_181 ( V_33 , V_298 ) ) {
F_179 ( V_297 ) ;
goto V_299;
}
V_235 -> V_184 ++ ;
V_235 -> V_182 += V_33 -> V_107 ;
F_182 ( V_33 ) ;
F_121 ( V_33 , & V_297 -> V_300 ) ;
F_183 ( F_78 ( V_33 ) ) ;
if ( V_235 -> V_19 & V_134 ) {
F_164 ( V_33 , V_235 -> V_176 , V_235 -> V_177 ) ;
V_235 -> V_60 -> V_105 . V_108 ++ ;
V_235 -> V_60 -> V_105 . V_106 += V_33 -> V_107 ;
}
F_167 ( V_33 ) -> V_19 |= V_304 ;
F_184 ( V_305 , V_306 , V_33 , V_33 -> V_60 , V_60 ,
F_169 ) ;
return;
V_299:
F_48 ( V_33 ) ;
}
static int F_185 ( struct V_1 * V_4 , struct V_59 * V_60 )
{
int V_286 ;
for ( V_286 = V_4 -> V_128 - 1 ; V_286 >= 0 ; V_286 -- ) {
if ( V_4 -> V_130 [ V_286 ] . V_60 == V_60 )
break;
}
return V_286 ;
}
static int F_109 ( struct V_2 * V_2 , struct V_1 * V_4 ,
struct V_32 * V_33 , struct V_137 * V_163 ,
int V_176 )
{
int V_307 = - 1 ;
int V_235 , V_286 ;
int V_308 = F_185 ( V_4 , V_33 -> V_60 ) ;
V_235 = V_163 -> V_193 ;
V_163 -> V_144 . V_8 . V_198 ++ ;
V_163 -> V_144 . V_8 . V_277 += V_33 -> V_107 ;
if ( V_163 -> V_188 == F_99 ( V_190 ) && V_308 >= 0 ) {
struct V_137 * V_309 ;
V_309 = F_98 ( V_4 , V_235 ) ;
if ( V_309 &&
V_309 -> V_144 . V_8 . V_164 [ V_308 ] < 255 )
goto V_310;
}
if ( V_4 -> V_130 [ V_235 ] . V_60 != V_33 -> V_60 ) {
if ( F_186 ( F_187 ( V_33 ) ) ) {
goto V_311;
}
V_163 -> V_144 . V_8 . V_278 ++ ;
if ( V_308 >= 0 && V_4 -> V_253 &&
( V_4 -> V_255 ||
V_163 -> V_144 . V_8 . V_164 [ V_308 ] < 255 ) &&
F_88 ( V_158 ,
V_163 -> V_144 . V_8 . V_312 + V_313 ) ) {
V_163 -> V_144 . V_8 . V_312 = V_158 ;
F_50 ( V_4 , V_33 , V_308 , V_314 ) ;
}
goto V_311;
}
V_310:
V_4 -> V_130 [ V_235 ] . V_183 ++ ;
V_4 -> V_130 [ V_235 ] . V_181 += V_33 -> V_107 ;
if ( V_163 -> V_188 == F_99 ( V_190 ) &&
V_163 -> V_189 == F_99 ( V_190 ) ) {
if ( V_308 >= 0 &&
V_308 != V_163 -> V_193 &&
F_78 ( V_33 ) -> V_290 >
V_163 -> V_144 . V_8 . V_164 [ V_163 -> V_193 ] ) {
V_307 = V_163 -> V_193 ;
goto V_315;
}
goto V_311;
}
for ( V_286 = V_163 -> V_144 . V_8 . V_128 - 1 ;
V_286 >= V_163 -> V_144 . V_8 . V_165 ; V_286 -- ) {
if ( ( V_163 -> V_188 != F_99 ( V_190 ) ||
V_286 != V_308 ) &&
F_78 ( V_33 ) -> V_290 > V_163 -> V_144 . V_8 . V_164 [ V_286 ] ) {
if ( V_307 != - 1 ) {
struct V_32 * V_316 = F_188 ( V_33 , V_194 ) ;
if ( V_316 )
F_175 ( V_2 , V_4 , V_316 , V_163 ,
V_307 ) ;
}
V_307 = V_286 ;
}
}
V_315:
if ( V_307 != - 1 ) {
if ( V_176 ) {
struct V_32 * V_316 = F_188 ( V_33 , V_194 ) ;
if ( V_316 )
F_175 ( V_2 , V_4 , V_316 , V_163 , V_307 ) ;
} else {
F_175 ( V_2 , V_4 , V_33 , V_163 , V_307 ) ;
return 0 ;
}
}
V_311:
if ( ! V_176 )
F_48 ( V_33 ) ;
return 0 ;
}
static struct V_1 * F_189 ( struct V_2 * V_2 , struct V_32 * V_33 )
{
struct V_296 * V_297 = F_187 ( V_33 ) ;
struct V_114 * V_69 = F_78 ( V_33 ) ;
struct V_5 V_97 = {
. V_70 = V_69 -> V_70 ,
. V_73 = V_69 -> V_73 ,
. V_317 = F_177 ( V_69 -> V_40 ) ,
. V_98 = ( F_186 ( V_297 ) ?
V_33 -> V_60 -> V_99 : 0 ) ,
. V_100 = ( F_186 ( V_297 ) ?
V_318 :
V_33 -> V_60 -> V_99 ) ,
. V_102 = V_33 -> V_103 ,
} ;
struct V_1 * V_4 ;
int V_12 ;
V_12 = F_3 ( V_2 , & V_97 , & V_4 ) ;
if ( V_12 )
return F_190 ( V_12 ) ;
return V_4 ;
}
int F_191 ( struct V_32 * V_33 )
{
struct V_137 * V_163 ;
struct V_2 * V_2 = F_33 ( V_33 -> V_60 ) ;
int V_176 = F_187 ( V_33 ) -> V_319 & V_320 ;
struct V_1 * V_4 ;
if ( F_167 ( V_33 ) -> V_19 & V_304 )
goto V_311;
V_4 = F_189 ( V_2 , V_33 ) ;
if ( F_13 ( V_4 ) ) {
F_48 ( V_33 ) ;
return F_14 ( V_4 ) ;
}
if ( ! V_176 ) {
if ( F_167 ( V_33 ) -> V_292 . V_321 ) {
if ( F_192 ( V_33 ) )
return 0 ;
} else if ( F_78 ( V_33 ) -> V_77 == V_239 ) {
struct V_202 * V_203 ;
V_203 = F_124 ( V_4 -> V_203 ) ;
if ( V_203 ) {
F_168 ( V_33 ) ;
F_193 ( V_203 , V_33 ) ;
return 0 ;
}
}
}
V_163 = F_95 ( V_4 , F_78 ( V_33 ) -> V_73 , F_78 ( V_33 ) -> V_70 ) ;
if ( V_163 == NULL ) {
int V_235 = F_185 ( V_4 , V_33 -> V_60 ) ;
if ( V_235 >= 0 )
V_163 = F_100 ( V_4 , F_78 ( V_33 ) -> V_70 ,
V_235 ) ;
}
if ( V_163 == NULL ) {
int V_235 ;
if ( V_176 ) {
struct V_32 * V_316 = F_188 ( V_33 , V_194 ) ;
F_194 ( V_33 ) ;
if ( V_316 == NULL )
return - V_171 ;
V_33 = V_316 ;
}
F_49 ( & V_104 ) ;
V_235 = F_185 ( V_4 , V_33 -> V_60 ) ;
if ( V_235 >= 0 ) {
int V_48 = F_127 ( V_4 , V_235 , V_33 ) ;
F_51 ( & V_104 ) ;
return V_48 ;
}
F_51 ( & V_104 ) ;
F_48 ( V_33 ) ;
return - V_322 ;
}
F_49 ( & V_104 ) ;
F_109 ( V_2 , V_4 , V_33 , V_163 , V_176 ) ;
F_51 ( & V_104 ) ;
if ( V_176 )
return F_194 ( V_33 ) ;
return 0 ;
V_311:
if ( V_176 )
return F_194 ( V_33 ) ;
F_48 ( V_33 ) ;
return 0 ;
}
static int F_195 ( struct V_1 * V_4 , struct V_32 * V_33 ,
unsigned int V_323 )
{
struct V_59 * V_324 = NULL ;
struct V_114 * V_298 ;
V_298 = (struct V_114 * ) ( F_196 ( V_33 ) + V_323 ) ;
if ( ! F_138 ( V_298 -> V_70 ) ||
V_298 -> V_208 == 0 ||
F_118 ( V_298 -> V_208 ) + V_323 > V_33 -> V_107 )
return 1 ;
F_49 ( & V_104 ) ;
if ( V_4 -> V_58 >= 0 )
V_324 = V_4 -> V_130 [ V_4 -> V_58 ] . V_60 ;
F_51 ( & V_104 ) ;
if ( V_324 == NULL )
return 1 ;
V_33 -> V_325 = V_33 -> V_209 ;
F_79 ( V_33 , ( V_196 * ) V_298 - V_33 -> V_211 ) ;
F_114 ( V_33 ) ;
V_33 -> V_77 = F_117 ( V_326 ) ;
V_33 -> V_327 = V_328 ;
V_33 -> V_329 = V_330 ;
F_197 ( V_33 , V_324 ) ;
F_198 ( V_33 ) ;
return V_331 ;
}
int F_199 ( struct V_32 * V_33 )
{
struct V_199 * V_332 ;
struct V_2 * V_2 = F_33 ( V_33 -> V_60 ) ;
struct V_1 * V_4 ;
if ( ! F_200 ( V_33 , sizeof( * V_332 ) + sizeof( struct V_114 ) ) )
goto V_333;
V_332 = F_201 ( V_33 ) ;
V_4 = F_189 ( V_2 , V_33 ) ;
if ( F_13 ( V_4 ) )
goto V_333;
if ( ! V_4 -> V_255 ||
V_332 -> V_334 != V_335 || V_332 -> V_212 != V_336 )
goto V_333;
if ( F_195 ( V_4 , V_33 , sizeof( * V_332 ) ) ) {
V_333:
F_48 ( V_33 ) ;
}
return 0 ;
}
static int F_202 ( struct V_32 * V_33 )
{
struct V_337 * V_332 ;
struct V_2 * V_2 = F_33 ( V_33 -> V_60 ) ;
struct V_1 * V_4 ;
if ( ! F_200 ( V_33 , sizeof( * V_332 ) + sizeof( struct V_114 ) ) )
goto V_333;
V_332 = (struct V_337 * ) F_196 ( V_33 ) ;
if ( V_332 -> type != ( ( V_338 << 4 ) | ( V_339 ) ) ||
( V_332 -> V_19 & V_340 ) ||
( F_203 ( ( void * ) V_332 , sizeof( * V_332 ) ) != 0 &&
F_204 ( F_205 ( V_33 , 0 , V_33 -> V_107 , 0 ) ) ) )
goto V_333;
V_4 = F_189 ( V_2 , V_33 ) ;
if ( F_13 ( V_4 ) )
goto V_333;
if ( F_195 ( V_4 , V_33 , sizeof( * V_332 ) ) ) {
V_333:
F_48 ( V_33 ) ;
}
return 0 ;
}
static int F_107 ( struct V_1 * V_4 , struct V_32 * V_33 ,
struct V_137 * V_138 , struct V_341 * V_342 )
{
int V_286 ;
struct V_343 * V_344 ;
struct V_36 * V_345 ;
struct V_346 V_347 ;
if ( V_138 -> V_193 >= V_166 )
return - V_223 ;
if ( F_63 ( V_4 , V_138 -> V_193 ) &&
F_206 ( V_33 , V_348 , V_4 -> V_130 [ V_138 -> V_193 ] . V_60 -> V_99 ) < 0 )
return - V_197 ;
if ( ! ( V_345 = F_207 ( V_33 , V_349 ) ) )
return - V_197 ;
for ( V_286 = V_138 -> V_144 . V_8 . V_165 ; V_286 < V_138 -> V_144 . V_8 . V_128 ; V_286 ++ ) {
if ( F_63 ( V_4 , V_286 ) && V_138 -> V_144 . V_8 . V_164 [ V_286 ] < 255 ) {
if ( ! ( V_344 = F_208 ( V_33 , sizeof( * V_344 ) ) ) ) {
F_209 ( V_33 , V_345 ) ;
return - V_197 ;
}
V_344 -> V_350 = 0 ;
V_344 -> V_351 = V_138 -> V_144 . V_8 . V_164 [ V_286 ] ;
V_344 -> V_352 = V_4 -> V_130 [ V_286 ] . V_60 -> V_99 ;
V_344 -> V_353 = sizeof( * V_344 ) ;
}
}
F_210 ( V_33 , V_345 ) ;
V_347 . V_354 = V_138 -> V_144 . V_8 . V_198 ;
V_347 . V_355 = V_138 -> V_144 . V_8 . V_277 ;
V_347 . V_356 = V_138 -> V_144 . V_8 . V_278 ;
if ( F_211 ( V_33 , V_357 , sizeof( V_347 ) , & V_347 ) < 0 )
return - V_197 ;
V_342 -> V_358 = V_359 ;
return 1 ;
}
int F_212 ( struct V_2 * V_2 , struct V_32 * V_33 ,
T_6 V_73 , T_6 V_70 ,
struct V_341 * V_342 , int V_360 )
{
struct V_137 * V_163 ;
struct V_1 * V_4 ;
int V_12 ;
V_4 = F_1 ( V_2 , V_45 ) ;
if ( V_4 == NULL )
return - V_223 ;
F_57 () ;
V_163 = F_95 ( V_4 , V_73 , V_70 ) ;
if ( V_163 == NULL && V_33 -> V_60 ) {
int V_235 = F_185 ( V_4 , V_33 -> V_60 ) ;
if ( V_235 >= 0 )
V_163 = F_100 ( V_4 , V_70 , V_235 ) ;
}
if ( V_163 == NULL ) {
struct V_32 * V_316 ;
struct V_114 * V_69 ;
struct V_59 * V_60 ;
int V_235 = - 1 ;
if ( V_360 ) {
F_59 () ;
return - V_30 ;
}
V_60 = V_33 -> V_60 ;
F_49 ( & V_104 ) ;
if ( V_60 )
V_235 = F_185 ( V_4 , V_60 ) ;
if ( V_235 < 0 ) {
F_51 ( & V_104 ) ;
F_59 () ;
return - V_322 ;
}
V_316 = F_188 ( V_33 , V_194 ) ;
if ( ! V_316 ) {
F_51 ( & V_104 ) ;
F_59 () ;
return - V_46 ;
}
F_113 ( V_316 , sizeof( struct V_114 ) ) ;
F_114 ( V_316 ) ;
V_69 = F_78 ( V_316 ) ;
V_69 -> V_76 = sizeof( struct V_114 ) >> 2 ;
V_69 -> V_73 = V_73 ;
V_69 -> V_70 = V_70 ;
V_69 -> V_75 = 0 ;
V_12 = F_127 ( V_4 , V_235 , V_316 ) ;
F_51 ( & V_104 ) ;
F_59 () ;
return V_12 ;
}
F_49 ( & V_104 ) ;
if ( ! V_360 && ( V_342 -> V_361 & V_362 ) )
V_163 -> V_227 |= V_363 ;
V_12 = F_107 ( V_4 , V_33 , V_163 , V_342 ) ;
F_51 ( & V_104 ) ;
F_59 () ;
return V_12 ;
}
static int F_213 ( struct V_1 * V_4 , struct V_32 * V_33 ,
T_1 V_154 , T_1 V_364 , struct V_137 * V_138 , int V_262 )
{
struct V_147 * V_148 ;
struct V_341 * V_342 ;
int V_12 ;
V_148 = F_214 ( V_33 , V_154 , V_364 , V_262 , sizeof( * V_342 ) , V_365 ) ;
if ( V_148 == NULL )
return - V_197 ;
V_342 = F_82 ( V_148 ) ;
V_342 -> V_366 = V_367 ;
V_342 -> V_368 = 32 ;
V_342 -> V_369 = 32 ;
V_342 -> V_370 = 0 ;
V_342 -> V_371 = V_4 -> V_3 ;
if ( F_206 ( V_33 , V_372 , V_4 -> V_3 ) )
goto V_373;
V_342 -> V_358 = V_359 ;
V_342 -> V_374 = V_375 ;
if ( V_138 -> V_227 & V_228 )
V_342 -> V_376 = V_377 ;
else
V_342 -> V_376 = V_378 ;
V_342 -> V_361 = 0 ;
if ( F_215 ( V_33 , V_379 , V_138 -> V_188 ) ||
F_215 ( V_33 , V_380 , V_138 -> V_189 ) )
goto V_373;
V_12 = F_107 ( V_4 , V_33 , V_138 , V_342 ) ;
if ( V_12 < 0 && V_12 != - V_223 )
goto V_373;
return F_216 ( V_33 , V_148 ) ;
V_373:
F_217 ( V_33 , V_148 ) ;
return - V_197 ;
}
static T_8 F_218 ( bool V_146 , int V_128 )
{
T_8 V_107 =
F_219 ( sizeof( struct V_341 ) )
+ F_220 ( 4 )
+ F_220 ( 4 )
+ F_220 ( 4 )
;
if ( ! V_146 )
V_107 = V_107
+ F_220 ( 4 )
+ F_220 ( 0 )
+ V_128 * F_221 ( sizeof( struct V_343 ) )
+ F_220 ( sizeof( struct V_346 ) )
;
return V_107 ;
}
static void F_89 ( struct V_1 * V_4 , struct V_137 * V_219 ,
int V_262 )
{
struct V_2 * V_2 = F_75 ( & V_4 -> V_2 ) ;
struct V_32 * V_33 ;
int V_12 = - V_171 ;
V_33 = F_222 ( F_218 ( V_219 -> V_193 >= V_166 , V_4 -> V_128 ) ,
V_194 ) ;
if ( V_33 == NULL )
goto V_381;
V_12 = F_213 ( V_4 , V_33 , 0 , 0 , V_219 , V_262 ) ;
if ( V_12 < 0 )
goto V_381;
F_223 ( V_33 , V_2 , 0 , V_382 , NULL , V_194 ) ;
return;
V_381:
F_48 ( V_33 ) ;
if ( V_12 < 0 )
F_224 ( V_2 , V_382 , V_12 ) ;
}
static int F_225 ( struct V_32 * V_33 , struct V_383 * V_384 )
{
struct V_2 * V_2 = F_144 ( V_33 -> V_229 ) ;
struct V_1 * V_4 ;
struct V_137 * V_219 ;
unsigned int V_385 = 0 , V_386 ;
unsigned int V_387 = 0 , V_388 ;
unsigned int V_142 = 0 , V_389 ;
V_386 = V_384 -> args [ 0 ] ;
V_388 = V_384 -> args [ 1 ] ;
V_389 = V_384 -> args [ 2 ] ;
F_57 () ;
F_2 (mrt, net) {
if ( V_385 < V_386 )
goto V_390;
if ( V_385 > V_386 )
V_388 = 0 ;
for ( V_387 = V_388 ; V_387 < V_53 ; V_387 ++ ) {
F_97 (mfc, &mrt->mfc_cache_array[h], list) {
if ( V_142 < V_389 )
goto V_391;
if ( F_213 ( V_4 , V_33 ,
F_84 ( V_384 -> V_33 ) . V_154 ,
V_384 -> V_148 -> V_392 ,
V_219 , V_216 ) < 0 )
goto V_393;
V_391:
V_142 ++ ;
}
V_142 = V_389 = 0 ;
}
F_128 ( & V_157 ) ;
F_129 (mfc, &mrt->mfc_unres_queue, list) {
if ( V_142 < V_389 )
goto V_394;
if ( F_213 ( V_4 , V_33 ,
F_84 ( V_384 -> V_33 ) . V_154 ,
V_384 -> V_148 -> V_392 ,
V_219 , V_216 ) < 0 ) {
F_131 ( & V_157 ) ;
goto V_393;
}
V_394:
V_142 ++ ;
}
F_131 ( & V_157 ) ;
V_142 = V_389 = 0 ;
V_388 = 0 ;
V_390:
V_385 ++ ;
}
V_393:
F_59 () ;
V_384 -> args [ 2 ] = V_142 ;
V_384 -> args [ 1 ] = V_387 ;
V_384 -> args [ 0 ] = V_385 ;
return V_33 -> V_107 ;
}
static struct V_127 * F_226 ( struct V_2 * V_2 ,
struct V_395 * V_396 ,
T_9 V_397 )
{
struct V_1 * V_4 = V_396 -> V_4 ;
for ( V_396 -> V_286 = 0 ; V_396 -> V_286 < V_4 -> V_128 ; ++ V_396 -> V_286 ) {
if ( ! F_63 ( V_4 , V_396 -> V_286 ) )
continue;
if ( V_397 -- == 0 )
return & V_4 -> V_130 [ V_396 -> V_286 ] ;
}
return NULL ;
}
static void * F_227 ( struct V_398 * V_364 , T_9 * V_397 )
__acquires( V_104 )
{
struct V_395 * V_396 = V_364 -> V_399 ;
struct V_2 * V_2 = F_228 ( V_364 ) ;
struct V_1 * V_4 ;
V_4 = F_1 ( V_2 , V_45 ) ;
if ( V_4 == NULL )
return F_190 ( - V_223 ) ;
V_396 -> V_4 = V_4 ;
F_49 ( & V_104 ) ;
return * V_397 ? F_226 ( V_2 , V_364 -> V_399 , * V_397 - 1 )
: V_400 ;
}
static void * F_229 ( struct V_398 * V_364 , void * V_62 , T_9 * V_397 )
{
struct V_395 * V_396 = V_364 -> V_399 ;
struct V_2 * V_2 = F_228 ( V_364 ) ;
struct V_1 * V_4 = V_396 -> V_4 ;
++ * V_397 ;
if ( V_62 == V_400 )
return F_226 ( V_2 , V_396 , 0 ) ;
while ( ++ V_396 -> V_286 < V_4 -> V_128 ) {
if ( ! F_63 ( V_4 , V_396 -> V_286 ) )
continue;
return & V_4 -> V_130 [ V_396 -> V_286 ] ;
}
return NULL ;
}
static void F_230 ( struct V_398 * V_364 , void * V_62 )
__releases( V_104 )
{
F_51 ( & V_104 ) ;
}
static int F_231 ( struct V_398 * V_364 , void * V_62 )
{
struct V_395 * V_396 = V_364 -> V_399 ;
struct V_1 * V_4 = V_396 -> V_4 ;
if ( V_62 == V_400 ) {
F_232 ( V_364 ,
L_6 ) ;
} else {
const struct V_127 * V_235 = V_62 ;
const char * V_79 = V_235 -> V_60 ? V_235 -> V_60 -> V_79 : L_7 ;
F_233 ( V_364 ,
L_8 ,
V_235 - V_4 -> V_130 ,
V_79 , V_235 -> V_181 , V_235 -> V_183 ,
V_235 -> V_182 , V_235 -> V_184 ,
V_235 -> V_19 , V_235 -> V_176 , V_235 -> V_177 ) ;
}
return 0 ;
}
static int F_234 ( struct V_401 * V_401 , struct V_402 * V_402 )
{
return F_235 ( V_401 , V_402 , & V_403 ,
sizeof( struct V_395 ) ) ;
}
static struct V_137 * F_236 ( struct V_2 * V_2 ,
struct V_404 * V_405 , T_9 V_397 )
{
struct V_1 * V_4 = V_405 -> V_4 ;
struct V_137 * V_219 ;
F_57 () ;
for ( V_405 -> V_286 = 0 ; V_405 -> V_286 < V_53 ; V_405 -> V_286 ++ ) {
V_405 -> V_163 = & V_4 -> V_54 [ V_405 -> V_286 ] ;
F_97 (mfc, it->cache, list)
if ( V_397 -- == 0 )
return V_219 ;
}
F_59 () ;
F_128 ( & V_157 ) ;
V_405 -> V_163 = & V_4 -> V_55 ;
F_129 (mfc, it->cache, list)
if ( V_397 -- == 0 )
return V_219 ;
F_131 ( & V_157 ) ;
V_405 -> V_163 = NULL ;
return NULL ;
}
static void * F_237 ( struct V_398 * V_364 , T_9 * V_397 )
{
struct V_404 * V_405 = V_364 -> V_399 ;
struct V_2 * V_2 = F_228 ( V_364 ) ;
struct V_1 * V_4 ;
V_4 = F_1 ( V_2 , V_45 ) ;
if ( V_4 == NULL )
return F_190 ( - V_223 ) ;
V_405 -> V_4 = V_4 ;
V_405 -> V_163 = NULL ;
V_405 -> V_286 = 0 ;
return * V_397 ? F_236 ( V_2 , V_364 -> V_399 , * V_397 - 1 )
: V_400 ;
}
static void * F_238 ( struct V_398 * V_364 , void * V_62 , T_9 * V_397 )
{
struct V_137 * V_219 = V_62 ;
struct V_404 * V_405 = V_364 -> V_399 ;
struct V_2 * V_2 = F_228 ( V_364 ) ;
struct V_1 * V_4 = V_405 -> V_4 ;
++ * V_397 ;
if ( V_62 == V_400 )
return F_236 ( V_2 , V_364 -> V_399 , 0 ) ;
if ( V_219 -> V_50 . V_49 != V_405 -> V_163 )
return F_239 ( V_219 -> V_50 . V_49 , struct V_137 , V_50 ) ;
if ( V_405 -> V_163 == & V_4 -> V_55 )
goto V_406;
F_240 ( V_405 -> V_163 != & V_4 -> V_54 [ V_405 -> V_286 ] ) ;
while ( ++ V_405 -> V_286 < V_53 ) {
V_405 -> V_163 = & V_4 -> V_54 [ V_405 -> V_286 ] ;
if ( F_87 ( V_405 -> V_163 ) )
continue;
return F_241 ( V_405 -> V_163 , struct V_137 , V_50 ) ;
}
F_59 () ;
V_405 -> V_163 = & V_4 -> V_55 ;
V_405 -> V_286 = 0 ;
F_128 ( & V_157 ) ;
if ( ! F_87 ( V_405 -> V_163 ) )
return F_241 ( V_405 -> V_163 , struct V_137 , V_50 ) ;
V_406:
F_131 ( & V_157 ) ;
V_405 -> V_163 = NULL ;
return NULL ;
}
static void F_242 ( struct V_398 * V_364 , void * V_62 )
{
struct V_404 * V_405 = V_364 -> V_399 ;
struct V_1 * V_4 = V_405 -> V_4 ;
if ( V_405 -> V_163 == & V_4 -> V_55 )
F_131 ( & V_157 ) ;
else if ( V_405 -> V_163 == & V_4 -> V_54 [ V_405 -> V_286 ] )
F_59 () ;
}
static int F_243 ( struct V_398 * V_364 , void * V_62 )
{
int V_407 ;
if ( V_62 == V_400 ) {
F_232 ( V_364 ,
L_9 ) ;
} else {
const struct V_137 * V_219 = V_62 ;
const struct V_404 * V_405 = V_364 -> V_399 ;
const struct V_1 * V_4 = V_405 -> V_4 ;
F_233 ( V_364 , L_10 ,
( V_83 T_1 ) V_219 -> V_189 ,
( V_83 T_1 ) V_219 -> V_188 ,
V_219 -> V_193 ) ;
if ( V_405 -> V_163 != & V_4 -> V_55 ) {
F_233 ( V_364 , L_11 ,
V_219 -> V_144 . V_8 . V_198 ,
V_219 -> V_144 . V_8 . V_277 ,
V_219 -> V_144 . V_8 . V_278 ) ;
for ( V_407 = V_219 -> V_144 . V_8 . V_165 ;
V_407 < V_219 -> V_144 . V_8 . V_128 ; V_407 ++ ) {
if ( F_63 ( V_4 , V_407 ) &&
V_219 -> V_144 . V_8 . V_164 [ V_407 ] < 255 )
F_233 ( V_364 ,
L_12 ,
V_407 , V_219 -> V_144 . V_8 . V_164 [ V_407 ] ) ;
}
} else {
F_233 ( V_364 , L_11 , 0ul , 0ul , 0ul ) ;
}
F_244 ( V_364 , '\n' ) ;
}
return 0 ;
}
static int F_245 ( struct V_401 * V_401 , struct V_402 * V_402 )
{
return F_235 ( V_401 , V_402 , & V_408 ,
sizeof( struct V_404 ) ) ;
}
static int T_2 F_246 ( struct V_2 * V_2 )
{
int V_12 ;
V_12 = F_11 ( V_2 ) ;
if ( V_12 < 0 )
goto V_409;
#ifdef F_247
V_12 = - V_46 ;
if ( ! F_248 ( L_13 , 0 , V_2 -> V_410 , & V_411 ) )
goto V_412;
if ( ! F_248 ( L_14 , 0 , V_2 -> V_410 , & V_413 ) )
goto V_414;
#endif
return 0 ;
#ifdef F_247
V_414:
F_249 ( L_13 , V_2 -> V_410 ) ;
V_412:
F_20 ( V_2 ) ;
#endif
V_409:
return V_12 ;
}
static void T_3 F_250 ( struct V_2 * V_2 )
{
#ifdef F_247
F_249 ( L_14 , V_2 -> V_410 ) ;
F_249 ( L_13 , V_2 -> V_410 ) ;
#endif
F_20 ( V_2 ) ;
}
int T_10 F_251 ( void )
{
int V_12 ;
V_140 = F_252 ( L_15 ,
sizeof( struct V_137 ) ,
0 , V_415 | V_416 ,
NULL ) ;
if ( ! V_140 )
return - V_46 ;
V_12 = F_253 ( & V_417 ) ;
if ( V_12 )
goto V_418;
V_12 = F_254 ( & V_419 ) ;
if ( V_12 )
goto V_420;
#ifdef F_255
if ( F_256 ( & V_421 , V_422 ) < 0 ) {
F_257 ( L_16 , V_423 ) ;
V_12 = - V_30 ;
goto V_424;
}
#endif
F_258 ( V_367 , V_425 ,
NULL , F_225 , NULL ) ;
return 0 ;
#ifdef F_255
V_424:
F_259 ( & V_419 ) ;
#endif
V_420:
F_260 ( & V_417 ) ;
V_418:
F_261 ( V_140 ) ;
return V_12 ;
}
