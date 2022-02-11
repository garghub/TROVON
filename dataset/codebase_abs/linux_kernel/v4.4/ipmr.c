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
if ( ! V_4 ) {
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
F_21 () ;
F_22 (mrt, next, &net->ipv4.mr_tables, list) {
F_23 ( & V_4 -> V_51 ) ;
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
V_2 -> V_15 . V_4 = F_16 ( V_2 , V_46 ) ;
return V_2 -> V_15 . V_4 ? 0 : - V_47 ;
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
unsigned int V_52 ;
V_4 = F_1 ( V_2 , V_3 ) ;
if ( V_4 )
return V_4 ;
V_4 = F_25 ( sizeof( * V_4 ) , V_53 ) ;
if ( ! V_4 )
return NULL ;
F_26 ( & V_4 -> V_2 , V_2 ) ;
V_4 -> V_3 = V_3 ;
for ( V_52 = 0 ; V_52 < V_54 ; V_52 ++ )
F_15 ( & V_4 -> V_55 [ V_52 ] ) ;
F_15 ( & V_4 -> V_56 ) ;
F_27 ( & V_4 -> V_57 , V_58 ,
( unsigned long ) V_4 ) ;
#ifdef F_28
V_4 -> V_59 = - 1 ;
#endif
#ifdef F_29
F_30 ( & V_4 -> V_51 , & V_2 -> V_15 . V_45 ) ;
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
static
struct V_60 * F_40 ( struct V_2 * V_2 , struct V_62 * V_63 )
{
struct V_60 * V_61 ;
V_61 = F_37 ( V_2 , L_1 ) ;
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
T_4 V_87 = F_38 () ;
F_39 ( V_88 ) ;
V_7 = V_43 -> V_86 ( V_61 , & V_67 , V_92 ) ;
F_39 ( V_87 ) ;
} else {
V_7 = - V_93 ;
}
V_61 = NULL ;
if ( V_7 == 0 &&
( V_61 = F_37 ( V_2 , V_69 . V_80 ) ) != NULL ) {
V_61 -> V_13 |= V_94 ;
V_91 = F_41 ( V_61 ) ;
if ( ! V_91 )
goto V_95;
F_42 ( V_91 ) ;
F_43 ( V_91 -> V_96 ) ;
F_44 ( V_91 -> V_97 , V_98 ) = 0 ;
if ( F_45 ( V_61 ) )
goto V_95;
F_46 ( V_61 ) ;
}
}
return V_61 ;
V_95:
F_47 ( V_61 ) ;
return NULL ;
}
static T_5 F_48 ( struct V_33 * V_34 , struct V_60 * V_61 )
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
F_49 ( V_34 ) ;
return V_7 ;
}
F_50 ( & V_107 ) ;
V_61 -> V_108 . V_109 += V_34 -> V_110 ;
V_61 -> V_108 . V_111 ++ ;
F_51 ( V_4 , V_34 , V_4 -> V_59 , V_112 ) ;
F_52 ( & V_107 ) ;
F_49 ( V_34 ) ;
return V_113 ;
}
static int F_53 ( const struct V_60 * V_61 )
{
return 0 ;
}
static void F_54 ( struct V_60 * V_61 )
{
V_61 -> type = V_114 ;
V_61 -> V_115 = V_116 - sizeof( struct V_117 ) - 8 ;
V_61 -> V_13 = V_118 ;
V_61 -> V_65 = & V_119 ;
V_61 -> V_120 = V_121 ;
V_61 -> V_122 |= V_123 ;
}
static struct V_60 * F_55 ( struct V_2 * V_2 , struct V_1 * V_4 )
{
struct V_60 * V_61 ;
struct V_90 * V_91 ;
char V_80 [ V_124 ] ;
if ( V_4 -> V_3 == V_46 )
sprintf ( V_80 , L_3 ) ;
else
sprintf ( V_80 , L_4 , V_4 -> V_3 ) ;
V_61 = F_56 ( 0 , V_80 , V_125 , F_54 ) ;
if ( ! V_61 )
return NULL ;
F_57 ( V_61 , V_2 ) ;
if ( F_58 ( V_61 ) ) {
V_121 ( V_61 ) ;
return NULL ;
}
F_59 () ;
V_91 = F_60 ( V_61 ) ;
if ( ! V_91 ) {
F_61 () ;
goto V_95;
}
F_42 ( V_91 ) ;
F_43 ( V_91 -> V_96 ) ;
F_44 ( V_91 -> V_97 , V_98 ) = 0 ;
F_61 () ;
if ( F_45 ( V_61 ) )
goto V_95;
F_46 ( V_61 ) ;
return V_61 ;
V_95:
F_47 ( V_61 ) ;
return NULL ;
}
static int F_62 ( struct V_1 * V_4 , int V_126 , int V_127 ,
struct V_128 * V_129 )
{
struct V_130 * V_63 ;
struct V_60 * V_61 ;
struct V_90 * V_91 ;
if ( V_126 < 0 || V_126 >= V_4 -> V_131 )
return - V_132 ;
V_63 = & V_4 -> V_133 [ V_126 ] ;
F_63 ( & V_107 ) ;
V_61 = V_63 -> V_61 ;
V_63 -> V_61 = NULL ;
if ( ! V_61 ) {
F_64 ( & V_107 ) ;
return - V_132 ;
}
#ifdef F_28
if ( V_126 == V_4 -> V_59 )
V_4 -> V_59 = - 1 ;
#endif
if ( V_126 + 1 == V_4 -> V_131 ) {
int V_134 ;
for ( V_134 = V_126 - 1 ; V_134 >= 0 ; V_134 -- ) {
if ( F_65 ( V_4 , V_134 ) )
break;
}
V_4 -> V_131 = V_134 + 1 ;
}
F_64 ( & V_107 ) ;
F_66 ( V_61 , - 1 ) ;
V_91 = F_41 ( V_61 ) ;
if ( V_91 ) {
F_44 ( V_91 -> V_97 , V_135 ) -- ;
F_67 ( F_35 ( V_61 ) ,
V_136 ,
V_61 -> V_101 , & V_91 -> V_97 ) ;
F_68 ( V_91 ) ;
}
if ( V_63 -> V_13 & ( V_137 | V_138 ) && ! V_127 )
F_69 ( V_61 , V_129 ) ;
F_70 ( V_61 ) ;
return 0 ;
}
static void F_71 ( struct V_139 * V_129 )
{
struct V_140 * V_141 = F_72 ( V_129 , struct V_140 , V_142 ) ;
F_73 ( V_143 , V_141 ) ;
}
static inline void F_74 ( struct V_140 * V_141 )
{
F_75 ( & V_141 -> V_142 , F_71 ) ;
}
static void F_76 ( struct V_1 * V_4 , struct V_140 * V_141 )
{
struct V_2 * V_2 = F_77 ( & V_4 -> V_2 ) ;
struct V_33 * V_34 ;
struct V_144 * V_145 ;
F_78 ( & V_4 -> V_146 ) ;
while ( ( V_34 = F_79 ( & V_141 -> V_147 . V_148 . V_149 ) ) ) {
if ( F_80 ( V_34 ) -> V_76 == 0 ) {
struct V_150 * V_151 = (struct V_150 * ) F_81 ( V_34 , sizeof( struct V_117 ) ) ;
V_151 -> V_152 = V_153 ;
V_151 -> V_154 = F_82 ( sizeof( struct V_144 ) ) ;
F_83 ( V_34 , V_151 -> V_154 ) ;
V_145 = F_84 ( V_151 ) ;
V_145 -> error = - V_155 ;
memset ( & V_145 -> V_156 , 0 , sizeof( V_145 -> V_156 ) ) ;
F_85 ( V_34 , V_2 , F_86 ( V_34 ) . V_157 ) ;
} else {
F_49 ( V_34 ) ;
}
}
F_74 ( V_141 ) ;
}
static void V_58 ( unsigned long V_11 )
{
struct V_1 * V_4 = (struct V_1 * ) V_11 ;
unsigned long V_158 ;
unsigned long V_159 ;
struct V_140 * V_141 , * V_50 ;
if ( ! F_87 ( & V_160 ) ) {
F_88 ( & V_4 -> V_57 , V_161 + V_162 / 10 ) ;
return;
}
if ( F_89 ( & V_4 -> V_56 ) )
goto V_163;
V_158 = V_161 ;
V_159 = 10 * V_162 ;
F_22 (c, next, &mrt->mfc_unres_queue, list) {
if ( F_90 ( V_141 -> V_147 . V_148 . V_159 , V_158 ) ) {
unsigned long V_164 = V_141 -> V_147 . V_148 . V_159 - V_158 ;
if ( V_164 < V_159 )
V_159 = V_164 ;
continue;
}
F_23 ( & V_141 -> V_51 ) ;
F_91 ( V_4 , V_141 , V_165 ) ;
F_76 ( V_4 , V_141 ) ;
}
if ( ! F_89 ( & V_4 -> V_56 ) )
F_88 ( & V_4 -> V_57 , V_161 + V_159 ) ;
V_163:
F_92 ( & V_160 ) ;
}
static void F_93 ( struct V_1 * V_4 , struct V_140 * V_166 ,
unsigned char * V_167 )
{
int V_126 ;
V_166 -> V_147 . V_9 . V_168 = V_169 ;
V_166 -> V_147 . V_9 . V_131 = 0 ;
memset ( V_166 -> V_147 . V_9 . V_167 , 255 , V_169 ) ;
for ( V_126 = 0 ; V_126 < V_4 -> V_131 ; V_126 ++ ) {
if ( F_65 ( V_4 , V_126 ) &&
V_167 [ V_126 ] && V_167 [ V_126 ] < 255 ) {
V_166 -> V_147 . V_9 . V_167 [ V_126 ] = V_167 [ V_126 ] ;
if ( V_166 -> V_147 . V_9 . V_168 > V_126 )
V_166 -> V_147 . V_9 . V_168 = V_126 ;
if ( V_166 -> V_147 . V_9 . V_131 <= V_126 )
V_166 -> V_147 . V_9 . V_131 = V_126 + 1 ;
}
}
}
static int F_94 ( struct V_2 * V_2 , struct V_1 * V_4 ,
struct V_62 * V_170 , int V_171 )
{
int V_126 = V_170 -> V_81 ;
struct V_130 * V_63 = & V_4 -> V_133 [ V_126 ] ;
struct V_60 * V_61 ;
struct V_90 * V_91 ;
int V_7 ;
if ( F_65 ( V_4 , V_126 ) )
return - V_172 ;
switch ( V_170 -> V_173 ) {
#ifdef F_28
case V_138 :
if ( V_4 -> V_59 >= 0 )
return - V_172 ;
V_61 = F_55 ( V_2 , V_4 ) ;
if ( ! V_61 )
return - V_174 ;
V_7 = F_66 ( V_61 , 1 ) ;
if ( V_7 ) {
F_47 ( V_61 ) ;
F_70 ( V_61 ) ;
return V_7 ;
}
break;
#endif
case V_137 :
V_61 = F_40 ( V_2 , V_170 ) ;
if ( ! V_61 )
return - V_174 ;
V_7 = F_66 ( V_61 , 1 ) ;
if ( V_7 ) {
F_34 ( V_61 , V_170 ) ;
F_70 ( V_61 ) ;
return V_7 ;
}
break;
case V_175 :
case 0 :
if ( V_170 -> V_173 == V_175 ) {
V_61 = F_95 ( V_2 , V_170 -> V_176 ) ;
if ( V_61 && ! F_41 ( V_61 ) ) {
F_70 ( V_61 ) ;
return - V_132 ;
}
} else {
V_61 = F_96 ( V_2 , V_170 -> V_75 . V_73 ) ;
}
if ( ! V_61 )
return - V_132 ;
V_7 = F_66 ( V_61 , 1 ) ;
if ( V_7 ) {
F_70 ( V_61 ) ;
return V_7 ;
}
break;
default:
return - V_28 ;
}
V_91 = F_41 ( V_61 ) ;
if ( ! V_91 ) {
F_70 ( V_61 ) ;
return - V_132 ;
}
F_44 ( V_91 -> V_97 , V_135 ) ++ ;
F_67 ( V_2 , V_136 , V_61 -> V_101 ,
& V_91 -> V_97 ) ;
F_68 ( V_91 ) ;
V_63 -> V_177 = V_170 -> V_178 ;
V_63 -> V_179 = V_170 -> V_75 . V_73 ;
V_63 -> V_180 = V_170 -> V_72 . V_73 ;
V_63 -> V_13 = V_170 -> V_173 ;
if ( ! V_171 )
V_63 -> V_13 |= V_181 ;
V_63 -> V_182 = V_170 -> V_183 ;
V_63 -> V_184 = 0 ;
V_63 -> V_185 = 0 ;
V_63 -> V_186 = 0 ;
V_63 -> V_187 = 0 ;
V_63 -> V_188 = V_61 -> V_101 ;
if ( V_63 -> V_13 & ( V_137 | V_138 ) )
V_63 -> V_188 = F_97 ( V_61 ) ;
F_63 ( & V_107 ) ;
V_63 -> V_61 = V_61 ;
#ifdef F_28
if ( V_63 -> V_13 & V_138 )
V_4 -> V_59 = V_126 ;
#endif
if ( V_126 + 1 > V_4 -> V_131 )
V_4 -> V_131 = V_126 + 1 ;
F_64 ( & V_107 ) ;
return 0 ;
}
static struct V_140 * F_98 ( struct V_1 * V_4 ,
T_6 V_189 ,
T_6 V_190 )
{
int line = F_99 ( V_190 , V_189 ) ;
struct V_140 * V_141 ;
F_100 (c, &mrt->mfc_cache_array[line], list) {
if ( V_141 -> V_191 == V_189 && V_141 -> V_192 == V_190 )
return V_141 ;
}
return NULL ;
}
static struct V_140 * F_101 ( struct V_1 * V_4 ,
int V_126 )
{
int line = F_99 ( F_102 ( V_193 ) , F_102 ( V_193 ) ) ;
struct V_140 * V_141 ;
F_100 (c, &mrt->mfc_cache_array[line], list)
if ( V_141 -> V_191 == F_102 ( V_193 ) &&
V_141 -> V_192 == F_102 ( V_193 ) &&
V_141 -> V_147 . V_9 . V_167 [ V_126 ] < 255 )
return V_141 ;
return NULL ;
}
static struct V_140 * F_103 ( struct V_1 * V_4 ,
T_6 V_190 , int V_126 )
{
int line = F_99 ( V_190 , F_102 ( V_193 ) ) ;
struct V_140 * V_141 , * V_194 ;
if ( V_190 == F_102 ( V_193 ) )
goto V_195;
F_100 (c, &mrt->mfc_cache_array[line], list)
if ( V_141 -> V_191 == F_102 ( V_193 ) &&
V_141 -> V_192 == V_190 ) {
if ( V_141 -> V_147 . V_9 . V_167 [ V_126 ] < 255 )
return V_141 ;
V_194 = F_101 ( V_4 ,
V_141 -> V_196 ) ;
if ( V_194 && V_194 -> V_147 . V_9 . V_167 [ V_126 ] < 255 )
return V_141 ;
}
V_195:
return F_101 ( V_4 , V_126 ) ;
}
static struct V_140 * F_104 ( void )
{
struct V_140 * V_141 = F_105 ( V_143 , V_53 ) ;
if ( V_141 )
V_141 -> V_147 . V_9 . V_168 = V_169 ;
return V_141 ;
}
static struct V_140 * F_106 ( void )
{
struct V_140 * V_141 = F_105 ( V_143 , V_197 ) ;
if ( V_141 ) {
F_107 ( & V_141 -> V_147 . V_148 . V_149 ) ;
V_141 -> V_147 . V_148 . V_159 = V_161 + 10 * V_162 ;
}
return V_141 ;
}
static void F_108 ( struct V_2 * V_2 , struct V_1 * V_4 ,
struct V_140 * V_198 , struct V_140 * V_141 )
{
struct V_33 * V_34 ;
struct V_144 * V_145 ;
while ( ( V_34 = F_109 ( & V_198 -> V_147 . V_148 . V_149 ) ) ) {
if ( F_80 ( V_34 ) -> V_76 == 0 ) {
struct V_150 * V_151 = (struct V_150 * ) F_81 ( V_34 , sizeof( struct V_117 ) ) ;
if ( F_110 ( V_4 , V_34 , V_141 , F_84 ( V_151 ) ) > 0 ) {
V_151 -> V_154 = F_111 ( V_34 ) -
( V_199 * ) V_151 ;
} else {
V_151 -> V_152 = V_153 ;
V_151 -> V_154 = F_82 ( sizeof( struct V_144 ) ) ;
F_83 ( V_34 , V_151 -> V_154 ) ;
V_145 = F_84 ( V_151 ) ;
V_145 -> error = - V_200 ;
memset ( & V_145 -> V_156 , 0 , sizeof( V_145 -> V_156 ) ) ;
}
F_85 ( V_34 , V_2 , F_86 ( V_34 ) . V_157 ) ;
} else {
F_112 ( V_2 , V_4 , V_34 , V_141 , 0 ) ;
}
}
}
static int F_51 ( struct V_1 * V_4 ,
struct V_33 * V_201 , T_7 V_126 , int assert )
{
struct V_33 * V_34 ;
const int V_77 = F_113 ( V_201 ) ;
struct V_202 * V_203 ;
struct V_204 * V_156 ;
struct V_205 * V_206 ;
int V_207 ;
#ifdef F_28
if ( assert == V_112 )
V_34 = F_114 ( V_201 , sizeof( struct V_117 ) ) ;
else
#endif
V_34 = F_115 ( 128 , V_197 ) ;
if ( ! V_34 )
return - V_174 ;
#ifdef F_28
if ( assert == V_112 ) {
F_116 ( V_34 , sizeof( struct V_117 ) ) ;
F_117 ( V_34 ) ;
F_118 ( V_34 ) ;
V_156 = (struct V_204 * ) F_119 ( V_34 ) ;
memcpy ( V_156 , F_119 ( V_201 ) , sizeof( struct V_117 ) ) ;
V_156 -> V_208 = V_112 ;
V_156 -> V_209 = 0 ;
V_156 -> V_210 = V_4 -> V_59 ;
F_80 ( V_34 ) -> V_77 = sizeof( struct V_117 ) >> 2 ;
F_80 ( V_34 ) -> V_211 = F_120 ( F_121 ( F_80 ( V_201 ) -> V_211 ) +
sizeof( struct V_117 ) ) ;
} else
#endif
{
F_122 ( V_34 , V_34 -> V_110 ) ;
F_123 ( V_34 , V_77 ) ;
F_124 ( V_34 , V_201 -> V_212 , V_77 ) ;
F_80 ( V_34 ) -> V_78 = 0 ;
V_156 = (struct V_204 * ) F_119 ( V_34 ) ;
V_156 -> V_210 = V_126 ;
F_125 ( V_34 , F_126 ( F_127 ( V_201 ) ) ) ;
V_203 = (struct V_202 * ) F_123 ( V_34 , sizeof( struct V_202 ) ) ;
V_203 -> type =
V_156 -> V_208 = assert ;
V_203 -> V_213 = 0 ;
F_80 ( V_34 ) -> V_211 = F_120 ( V_34 -> V_110 ) ;
V_34 -> V_214 = V_34 -> V_215 ;
}
F_59 () ;
V_206 = F_128 ( V_4 -> V_206 ) ;
if ( ! V_206 ) {
F_61 () ;
F_49 ( V_34 ) ;
return - V_28 ;
}
V_207 = F_129 ( V_206 , V_34 ) ;
F_61 () ;
if ( V_207 < 0 ) {
F_130 ( L_5 ) ;
F_49 ( V_34 ) ;
}
return V_207 ;
}
static int
F_131 ( struct V_1 * V_4 , T_7 V_126 , struct V_33 * V_34 )
{
bool V_216 = false ;
int V_7 ;
struct V_140 * V_141 ;
const struct V_117 * V_70 = F_80 ( V_34 ) ;
F_132 ( & V_160 ) ;
F_133 (c, &mrt->mfc_unres_queue, list) {
if ( V_141 -> V_192 == V_70 -> V_71 &&
V_141 -> V_191 == V_70 -> V_74 ) {
V_216 = true ;
break;
}
}
if ( ! V_216 ) {
if ( F_134 ( & V_4 -> V_146 ) >= 10 ||
( V_141 = F_106 () ) == NULL ) {
F_135 ( & V_160 ) ;
F_49 ( V_34 ) ;
return - V_174 ;
}
V_141 -> V_196 = - 1 ;
V_141 -> V_191 = V_70 -> V_74 ;
V_141 -> V_192 = V_70 -> V_71 ;
V_7 = F_51 ( V_4 , V_34 , V_126 , V_217 ) ;
if ( V_7 < 0 ) {
F_135 ( & V_160 ) ;
F_74 ( V_141 ) ;
F_49 ( V_34 ) ;
return V_7 ;
}
F_136 ( & V_4 -> V_146 ) ;
F_137 ( & V_141 -> V_51 , & V_4 -> V_56 ) ;
F_91 ( V_4 , V_141 , V_218 ) ;
if ( F_134 ( & V_4 -> V_146 ) == 1 )
F_88 ( & V_4 -> V_57 , V_141 -> V_147 . V_148 . V_159 ) ;
}
if ( V_141 -> V_147 . V_148 . V_149 . V_219 > 3 ) {
F_49 ( V_34 ) ;
V_7 = - V_174 ;
} else {
F_138 ( & V_141 -> V_147 . V_148 . V_149 , V_34 ) ;
V_7 = 0 ;
}
F_135 ( & V_160 ) ;
return V_7 ;
}
static int F_139 ( struct V_1 * V_4 , struct V_220 * V_221 , int V_222 )
{
int line ;
struct V_140 * V_141 , * V_50 ;
line = F_99 ( V_221 -> V_223 . V_73 , V_221 -> V_224 . V_73 ) ;
F_22 (c, next, &mrt->mfc_cache_array[line], list) {
if ( V_141 -> V_191 == V_221 -> V_224 . V_73 &&
V_141 -> V_192 == V_221 -> V_223 . V_73 &&
( V_222 == - 1 || V_222 == V_141 -> V_196 ) ) {
F_140 ( & V_141 -> V_51 ) ;
F_91 ( V_4 , V_141 , V_165 ) ;
F_74 ( V_141 ) ;
return 0 ;
}
}
return - V_225 ;
}
static int F_141 ( struct V_2 * V_2 , struct V_1 * V_4 ,
struct V_220 * V_221 , int V_171 , int V_222 )
{
bool V_216 = false ;
int line ;
struct V_140 * V_198 , * V_141 ;
if ( V_221 -> V_226 >= V_169 )
return - V_227 ;
line = F_99 ( V_221 -> V_223 . V_73 , V_221 -> V_224 . V_73 ) ;
F_133 (c, &mrt->mfc_cache_array[line], list) {
if ( V_141 -> V_191 == V_221 -> V_224 . V_73 &&
V_141 -> V_192 == V_221 -> V_223 . V_73 &&
( V_222 == - 1 || V_222 == V_141 -> V_196 ) ) {
V_216 = true ;
break;
}
}
if ( V_216 ) {
F_63 ( & V_107 ) ;
V_141 -> V_196 = V_221 -> V_226 ;
F_93 ( V_4 , V_141 , V_221 -> V_228 ) ;
if ( ! V_171 )
V_141 -> V_229 |= V_230 ;
F_64 ( & V_107 ) ;
F_91 ( V_4 , V_141 , V_218 ) ;
return 0 ;
}
if ( V_221 -> V_223 . V_73 != F_102 ( V_193 ) &&
! F_142 ( V_221 -> V_223 . V_73 ) )
return - V_28 ;
V_141 = F_104 () ;
if ( ! V_141 )
return - V_47 ;
V_141 -> V_191 = V_221 -> V_224 . V_73 ;
V_141 -> V_192 = V_221 -> V_223 . V_73 ;
V_141 -> V_196 = V_221 -> V_226 ;
F_93 ( V_4 , V_141 , V_221 -> V_228 ) ;
if ( ! V_171 )
V_141 -> V_229 |= V_230 ;
F_143 ( & V_141 -> V_51 , & V_4 -> V_55 [ line ] ) ;
V_216 = false ;
F_132 ( & V_160 ) ;
F_133 (uc, &mrt->mfc_unres_queue, list) {
if ( V_198 -> V_191 == V_141 -> V_191 &&
V_198 -> V_192 == V_141 -> V_192 ) {
F_23 ( & V_198 -> V_51 ) ;
F_78 ( & V_4 -> V_146 ) ;
V_216 = true ;
break;
}
}
if ( F_89 ( & V_4 -> V_56 ) )
F_144 ( & V_4 -> V_57 ) ;
F_135 ( & V_160 ) ;
if ( V_216 ) {
F_108 ( V_2 , V_4 , V_198 , V_141 ) ;
F_74 ( V_198 ) ;
}
F_91 ( V_4 , V_141 , V_218 ) ;
return 0 ;
}
static void F_32 ( struct V_1 * V_4 , bool V_231 )
{
int V_52 ;
F_145 ( V_51 ) ;
struct V_140 * V_141 , * V_50 ;
for ( V_52 = 0 ; V_52 < V_4 -> V_131 ; V_52 ++ ) {
if ( ! V_231 && ( V_4 -> V_133 [ V_52 ] . V_13 & V_181 ) )
continue;
F_62 ( V_4 , V_52 , 0 , & V_51 ) ;
}
F_146 ( & V_51 ) ;
for ( V_52 = 0 ; V_52 < V_54 ; V_52 ++ ) {
F_22 (c, next, &mrt->mfc_cache_array[i], list) {
if ( ! V_231 && ( V_141 -> V_229 & V_230 ) )
continue;
F_140 ( & V_141 -> V_51 ) ;
F_91 ( V_4 , V_141 , V_165 ) ;
F_74 ( V_141 ) ;
}
}
if ( F_134 ( & V_4 -> V_146 ) != 0 ) {
F_132 ( & V_160 ) ;
F_22 (c, next, &mrt->mfc_unres_queue, list) {
F_23 ( & V_141 -> V_51 ) ;
F_91 ( V_4 , V_141 , V_165 ) ;
F_76 ( V_4 , V_141 ) ;
}
F_135 ( & V_160 ) ;
}
}
static void F_147 ( struct V_205 * V_232 )
{
struct V_2 * V_2 = F_148 ( V_232 ) ;
struct V_1 * V_4 ;
F_21 () ;
F_2 (mrt, net) {
if ( V_232 == F_149 ( V_4 -> V_206 ) ) {
F_150 ( V_2 , V_135 ) -- ;
F_67 ( V_2 , V_136 ,
V_233 ,
V_2 -> V_15 . V_234 ) ;
F_151 ( V_4 -> V_206 , NULL ) ;
F_32 ( V_4 , false ) ;
}
}
F_24 () ;
}
int F_152 ( struct V_205 * V_232 , int V_235 , char V_85 * V_236 , unsigned int V_237 )
{
int V_207 , V_222 = 0 ;
struct V_62 V_238 ;
struct V_220 V_221 ;
struct V_2 * V_2 = F_148 ( V_232 ) ;
struct V_1 * V_4 ;
if ( V_232 -> V_239 != V_240 ||
F_153 ( V_232 ) -> V_241 != V_242 )
return - V_93 ;
V_4 = F_1 ( V_2 , F_154 ( V_232 ) -> V_243 ? : V_46 ) ;
if ( ! V_4 )
return - V_225 ;
if ( V_235 != V_244 ) {
if ( V_232 != F_155 ( V_4 -> V_206 ) &&
! F_156 ( V_2 -> V_245 , V_246 ) )
return - V_26 ;
}
switch ( V_235 ) {
case V_244 :
if ( V_237 != sizeof( int ) )
return - V_28 ;
F_21 () ;
if ( F_149 ( V_4 -> V_206 ) ) {
F_24 () ;
return - V_172 ;
}
V_207 = F_157 ( V_232 , 1 , F_147 ) ;
if ( V_207 == 0 ) {
F_158 ( V_4 -> V_206 , V_232 ) ;
F_150 ( V_2 , V_135 ) ++ ;
F_67 ( V_2 , V_136 ,
V_233 ,
V_2 -> V_15 . V_234 ) ;
}
F_24 () ;
return V_207 ;
case V_247 :
if ( V_232 != F_155 ( V_4 -> V_206 ) )
return - V_26 ;
return F_157 ( V_232 , 0 , NULL ) ;
case V_248 :
case V_249 :
if ( V_237 != sizeof( V_238 ) )
return - V_28 ;
if ( F_159 ( & V_238 , V_236 , sizeof( V_238 ) ) )
return - V_250 ;
if ( V_238 . V_81 >= V_169 )
return - V_227 ;
F_21 () ;
if ( V_235 == V_248 ) {
V_207 = F_94 ( V_2 , V_4 , & V_238 ,
V_232 == F_149 ( V_4 -> V_206 ) ) ;
} else {
V_207 = F_62 ( V_4 , V_238 . V_81 , 0 , NULL ) ;
}
F_24 () ;
return V_207 ;
case V_251 :
case V_252 :
V_222 = - 1 ;
case V_253 :
case V_254 :
if ( V_237 != sizeof( V_221 ) )
return - V_28 ;
if ( F_159 ( & V_221 , V_236 , sizeof( V_221 ) ) )
return - V_250 ;
if ( V_222 == 0 )
V_222 = V_221 . V_226 ;
F_21 () ;
if ( V_235 == V_252 || V_235 == V_254 )
V_207 = F_139 ( V_4 , & V_221 , V_222 ) ;
else
V_207 = F_141 ( V_2 , V_4 , & V_221 ,
V_232 == F_149 ( V_4 -> V_206 ) ,
V_222 ) ;
F_24 () ;
return V_207 ;
case V_255 :
{
int V_63 ;
if ( V_237 != sizeof( V_63 ) )
return - V_28 ;
if ( F_160 ( V_63 , ( int V_85 * ) V_236 ) )
return - V_250 ;
V_4 -> V_256 = V_63 ;
return 0 ;
}
#ifdef F_28
case V_257 :
{
int V_63 ;
if ( V_237 != sizeof( V_63 ) )
return - V_28 ;
if ( F_160 ( V_63 , ( int V_85 * ) V_236 ) )
return - V_250 ;
V_63 = ! ! V_63 ;
F_21 () ;
V_207 = 0 ;
if ( V_63 != V_4 -> V_258 ) {
V_4 -> V_258 = V_63 ;
V_4 -> V_256 = V_63 ;
}
F_24 () ;
return V_207 ;
}
#endif
#ifdef F_29
case V_259 :
{
T_1 V_63 ;
if ( V_237 != sizeof( T_1 ) )
return - V_28 ;
if ( F_160 ( V_63 , ( T_1 V_85 * ) V_236 ) )
return - V_250 ;
if ( V_63 != V_46 && V_63 >= 1000000000 )
return - V_28 ;
F_21 () ;
V_207 = 0 ;
if ( V_232 == F_149 ( V_4 -> V_206 ) ) {
V_207 = - V_260 ;
} else {
if ( ! F_16 ( V_2 , V_63 ) )
V_207 = - V_47 ;
else
F_154 ( V_232 ) -> V_243 = V_63 ;
}
F_24 () ;
return V_207 ;
}
#endif
default:
return - V_261 ;
}
}
int F_161 ( struct V_205 * V_232 , int V_235 , char V_85 * V_236 , int V_85 * V_237 )
{
int V_262 ;
int V_263 ;
struct V_2 * V_2 = F_148 ( V_232 ) ;
struct V_1 * V_4 ;
if ( V_232 -> V_239 != V_240 ||
F_153 ( V_232 ) -> V_241 != V_242 )
return - V_93 ;
V_4 = F_1 ( V_2 , F_154 ( V_232 ) -> V_243 ? : V_46 ) ;
if ( ! V_4 )
return - V_225 ;
if ( V_235 != V_264 &&
#ifdef F_28
V_235 != V_257 &&
#endif
V_235 != V_255 )
return - V_261 ;
if ( F_160 ( V_262 , V_237 ) )
return - V_250 ;
V_262 = F_162 (unsigned int, olr, sizeof(int)) ;
if ( V_262 < 0 )
return - V_28 ;
if ( F_163 ( V_262 , V_237 ) )
return - V_250 ;
if ( V_235 == V_264 )
V_263 = 0x0305 ;
#ifdef F_28
else if ( V_235 == V_257 )
V_263 = V_4 -> V_258 ;
#endif
else
V_263 = V_4 -> V_256 ;
if ( F_164 ( V_236 , & V_263 , V_262 ) )
return - V_250 ;
return 0 ;
}
int F_165 ( struct V_205 * V_232 , int V_265 , void V_85 * V_11 )
{
struct V_266 V_267 ;
struct V_268 V_269 ;
struct V_130 * V_238 ;
struct V_140 * V_141 ;
struct V_2 * V_2 = F_148 ( V_232 ) ;
struct V_1 * V_4 ;
V_4 = F_1 ( V_2 , F_154 ( V_232 ) -> V_243 ? : V_46 ) ;
if ( ! V_4 )
return - V_225 ;
switch ( V_265 ) {
case V_270 :
if ( F_159 ( & V_269 , V_11 , sizeof( V_269 ) ) )
return - V_250 ;
if ( V_269 . V_126 >= V_4 -> V_131 )
return - V_28 ;
F_50 ( & V_107 ) ;
V_238 = & V_4 -> V_133 [ V_269 . V_126 ] ;
if ( F_65 ( V_4 , V_269 . V_126 ) ) {
V_269 . V_271 = V_238 -> V_186 ;
V_269 . V_272 = V_238 -> V_187 ;
V_269 . V_273 = V_238 -> V_184 ;
V_269 . V_274 = V_238 -> V_185 ;
F_52 ( & V_107 ) ;
if ( F_164 ( V_11 , & V_269 , sizeof( V_269 ) ) )
return - V_250 ;
return 0 ;
}
F_52 ( & V_107 ) ;
return - V_132 ;
case V_275 :
if ( F_159 ( & V_267 , V_11 , sizeof( V_267 ) ) )
return - V_250 ;
F_59 () ;
V_141 = F_98 ( V_4 , V_267 . V_276 . V_73 , V_267 . V_277 . V_73 ) ;
if ( V_141 ) {
V_267 . V_278 = V_141 -> V_147 . V_9 . V_201 ;
V_267 . V_279 = V_141 -> V_147 . V_9 . V_280 ;
V_267 . V_281 = V_141 -> V_147 . V_9 . V_281 ;
F_61 () ;
if ( F_164 ( V_11 , & V_267 , sizeof( V_267 ) ) )
return - V_250 ;
return 0 ;
}
F_61 () ;
return - V_132 ;
default:
return - V_282 ;
}
}
int F_166 ( struct V_205 * V_232 , unsigned int V_265 , void V_85 * V_11 )
{
struct V_283 V_267 ;
struct V_284 V_269 ;
struct V_130 * V_238 ;
struct V_140 * V_141 ;
struct V_2 * V_2 = F_148 ( V_232 ) ;
struct V_1 * V_4 ;
V_4 = F_1 ( V_2 , F_154 ( V_232 ) -> V_243 ? : V_46 ) ;
if ( ! V_4 )
return - V_225 ;
switch ( V_265 ) {
case V_270 :
if ( F_159 ( & V_269 , V_11 , sizeof( V_269 ) ) )
return - V_250 ;
if ( V_269 . V_126 >= V_4 -> V_131 )
return - V_28 ;
F_50 ( & V_107 ) ;
V_238 = & V_4 -> V_133 [ V_269 . V_126 ] ;
if ( F_65 ( V_4 , V_269 . V_126 ) ) {
V_269 . V_271 = V_238 -> V_186 ;
V_269 . V_272 = V_238 -> V_187 ;
V_269 . V_273 = V_238 -> V_184 ;
V_269 . V_274 = V_238 -> V_185 ;
F_52 ( & V_107 ) ;
if ( F_164 ( V_11 , & V_269 , sizeof( V_269 ) ) )
return - V_250 ;
return 0 ;
}
F_52 ( & V_107 ) ;
return - V_132 ;
case V_275 :
if ( F_159 ( & V_267 , V_11 , sizeof( V_267 ) ) )
return - V_250 ;
F_59 () ;
V_141 = F_98 ( V_4 , V_267 . V_276 . V_73 , V_267 . V_277 . V_73 ) ;
if ( V_141 ) {
V_267 . V_278 = V_141 -> V_147 . V_9 . V_201 ;
V_267 . V_279 = V_141 -> V_147 . V_9 . V_280 ;
V_267 . V_281 = V_141 -> V_147 . V_9 . V_281 ;
F_61 () ;
if ( F_164 ( V_11 , & V_267 , sizeof( V_267 ) ) )
return - V_250 ;
return 0 ;
}
F_61 () ;
return - V_132 ;
default:
return - V_282 ;
}
}
static int F_167 ( struct V_285 * V_286 , unsigned long V_287 , void * V_288 )
{
struct V_60 * V_61 = F_168 ( V_288 ) ;
struct V_2 * V_2 = F_35 ( V_61 ) ;
struct V_1 * V_4 ;
struct V_130 * V_63 ;
int V_289 ;
if ( V_287 != V_290 )
return V_291 ;
F_2 (mrt, net) {
V_63 = & V_4 -> V_133 [ 0 ] ;
for ( V_289 = 0 ; V_289 < V_4 -> V_131 ; V_289 ++ , V_63 ++ ) {
if ( V_63 -> V_61 == V_61 )
F_62 ( V_4 , V_289 , 1 , NULL ) ;
}
}
return V_291 ;
}
static void F_169 ( struct V_2 * V_2 , struct V_33 * V_34 ,
T_6 V_74 , T_6 V_71 )
{
struct V_117 * V_70 ;
const struct V_117 * V_292 = F_80 ( V_34 ) ;
F_116 ( V_34 , sizeof( struct V_117 ) ) ;
V_34 -> V_214 = V_34 -> V_215 ;
F_117 ( V_34 ) ;
V_70 = F_80 ( V_34 ) ;
V_70 -> V_76 = 4 ;
V_70 -> V_41 = V_292 -> V_41 ;
V_70 -> V_293 = V_292 -> V_293 ;
V_70 -> V_294 = 0 ;
V_70 -> V_71 = V_71 ;
V_70 -> V_74 = V_74 ;
V_70 -> V_78 = V_79 ;
V_70 -> V_77 = 5 ;
V_70 -> V_211 = F_120 ( V_34 -> V_110 ) ;
F_170 ( V_2 , V_34 , NULL ) ;
F_171 ( V_70 ) ;
memset ( & ( F_172 ( V_34 ) -> V_295 ) , 0 , sizeof( F_172 ( V_34 ) -> V_295 ) ) ;
F_173 ( V_34 ) ;
}
static inline int F_174 ( struct V_2 * V_2 , struct V_205 * V_232 ,
struct V_33 * V_34 )
{
struct V_296 * V_295 = & ( F_172 ( V_34 ) -> V_295 ) ;
F_175 ( V_2 , V_297 ) ;
F_176 ( V_2 , V_298 , V_34 -> V_110 ) ;
if ( F_177 ( V_295 -> V_237 ) )
F_178 ( V_34 ) ;
return F_179 ( V_2 , V_232 , V_34 ) ;
}
static void F_180 ( struct V_2 * V_2 , struct V_1 * V_4 ,
struct V_33 * V_34 , struct V_140 * V_141 , int V_126 )
{
const struct V_117 * V_70 = F_80 ( V_34 ) ;
struct V_130 * V_238 = & V_4 -> V_133 [ V_126 ] ;
struct V_60 * V_61 ;
struct V_299 * V_300 ;
struct V_5 V_99 ;
int V_301 = 0 ;
if ( ! V_238 -> V_61 )
goto V_302;
#ifdef F_28
if ( V_238 -> V_13 & V_138 ) {
V_238 -> V_187 ++ ;
V_238 -> V_185 += V_34 -> V_110 ;
V_238 -> V_61 -> V_108 . V_109 += V_34 -> V_110 ;
V_238 -> V_61 -> V_108 . V_111 ++ ;
F_51 ( V_4 , V_34 , V_126 , V_112 ) ;
goto V_302;
}
#endif
if ( V_238 -> V_13 & V_137 ) {
V_300 = F_181 ( V_2 , & V_99 , NULL ,
V_238 -> V_180 , V_238 -> V_179 ,
0 , 0 ,
V_79 ,
F_182 ( V_70 -> V_41 ) , V_238 -> V_188 ) ;
if ( F_13 ( V_300 ) )
goto V_302;
V_301 = sizeof( struct V_117 ) ;
} else {
V_300 = F_181 ( V_2 , & V_99 , NULL , V_70 -> V_71 , 0 ,
0 , 0 ,
V_79 ,
F_182 ( V_70 -> V_41 ) , V_238 -> V_188 ) ;
if ( F_13 ( V_300 ) )
goto V_302;
}
V_61 = V_300 -> V_303 . V_61 ;
if ( V_34 -> V_110 + V_301 > F_183 ( & V_300 -> V_303 ) && ( F_121 ( V_70 -> V_294 ) & V_304 ) ) {
F_175 ( V_2 , V_305 ) ;
F_184 ( V_300 ) ;
goto V_302;
}
V_301 += F_185 ( V_61 ) + V_300 -> V_303 . V_306 ;
if ( F_186 ( V_34 , V_301 ) ) {
F_184 ( V_300 ) ;
goto V_302;
}
V_238 -> V_187 ++ ;
V_238 -> V_185 += V_34 -> V_110 ;
F_187 ( V_34 ) ;
F_125 ( V_34 , & V_300 -> V_303 ) ;
F_188 ( F_80 ( V_34 ) ) ;
if ( V_238 -> V_13 & V_137 ) {
F_169 ( V_2 , V_34 , V_238 -> V_179 , V_238 -> V_180 ) ;
V_238 -> V_61 -> V_108 . V_111 ++ ;
V_238 -> V_61 -> V_108 . V_109 += V_34 -> V_110 ;
}
F_172 ( V_34 ) -> V_13 |= V_307 ;
F_189 ( V_308 , V_309 ,
V_2 , NULL , V_34 , V_34 -> V_61 , V_61 ,
F_174 ) ;
return;
V_302:
F_49 ( V_34 ) ;
}
static int F_190 ( struct V_1 * V_4 , struct V_60 * V_61 )
{
int V_289 ;
for ( V_289 = V_4 -> V_131 - 1 ; V_289 >= 0 ; V_289 -- ) {
if ( V_4 -> V_133 [ V_289 ] . V_61 == V_61 )
break;
}
return V_289 ;
}
static void F_112 ( struct V_2 * V_2 , struct V_1 * V_4 ,
struct V_33 * V_34 , struct V_140 * V_166 ,
int V_179 )
{
int V_310 = - 1 ;
int V_238 , V_289 ;
int V_311 = F_190 ( V_4 , V_34 -> V_61 ) ;
V_238 = V_166 -> V_196 ;
V_166 -> V_147 . V_9 . V_201 ++ ;
V_166 -> V_147 . V_9 . V_280 += V_34 -> V_110 ;
if ( V_166 -> V_191 == F_102 ( V_193 ) && V_311 >= 0 ) {
struct V_140 * V_312 ;
V_312 = F_101 ( V_4 , V_238 ) ;
if ( V_312 &&
V_312 -> V_147 . V_9 . V_167 [ V_311 ] < 255 )
goto V_313;
}
if ( V_4 -> V_133 [ V_238 ] . V_61 != V_34 -> V_61 ) {
if ( F_191 ( F_192 ( V_34 ) ) ) {
goto V_314;
}
V_166 -> V_147 . V_9 . V_281 ++ ;
if ( V_311 >= 0 && V_4 -> V_256 &&
( V_4 -> V_258 ||
V_166 -> V_147 . V_9 . V_167 [ V_311 ] < 255 ) &&
F_90 ( V_161 ,
V_166 -> V_147 . V_9 . V_315 + V_316 ) ) {
V_166 -> V_147 . V_9 . V_315 = V_161 ;
F_51 ( V_4 , V_34 , V_311 , V_317 ) ;
}
goto V_314;
}
V_313:
V_4 -> V_133 [ V_238 ] . V_186 ++ ;
V_4 -> V_133 [ V_238 ] . V_184 += V_34 -> V_110 ;
if ( V_166 -> V_191 == F_102 ( V_193 ) &&
V_166 -> V_192 == F_102 ( V_193 ) ) {
if ( V_311 >= 0 &&
V_311 != V_166 -> V_196 &&
F_80 ( V_34 ) -> V_293 >
V_166 -> V_147 . V_9 . V_167 [ V_166 -> V_196 ] ) {
V_310 = V_166 -> V_196 ;
goto V_318;
}
goto V_314;
}
for ( V_289 = V_166 -> V_147 . V_9 . V_131 - 1 ;
V_289 >= V_166 -> V_147 . V_9 . V_168 ; V_289 -- ) {
if ( ( V_166 -> V_191 != F_102 ( V_193 ) ||
V_289 != V_311 ) &&
F_80 ( V_34 ) -> V_293 > V_166 -> V_147 . V_9 . V_167 [ V_289 ] ) {
if ( V_310 != - 1 ) {
struct V_33 * V_319 = F_193 ( V_34 , V_197 ) ;
if ( V_319 )
F_180 ( V_2 , V_4 , V_319 , V_166 ,
V_310 ) ;
}
V_310 = V_289 ;
}
}
V_318:
if ( V_310 != - 1 ) {
if ( V_179 ) {
struct V_33 * V_319 = F_193 ( V_34 , V_197 ) ;
if ( V_319 )
F_180 ( V_2 , V_4 , V_319 , V_166 , V_310 ) ;
} else {
F_180 ( V_2 , V_4 , V_34 , V_166 , V_310 ) ;
return;
}
}
V_314:
if ( ! V_179 )
F_49 ( V_34 ) ;
}
static struct V_1 * F_194 ( struct V_2 * V_2 , struct V_33 * V_34 )
{
struct V_299 * V_300 = F_192 ( V_34 ) ;
struct V_117 * V_70 = F_80 ( V_34 ) ;
struct V_5 V_99 = {
. V_71 = V_70 -> V_71 ,
. V_74 = V_70 -> V_74 ,
. V_320 = F_182 ( V_70 -> V_41 ) ,
. V_100 = ( F_191 ( V_300 ) ?
V_34 -> V_61 -> V_101 : 0 ) ,
. V_102 = ( F_191 ( V_300 ) ?
V_104 :
V_34 -> V_61 -> V_101 ) ,
. V_105 = V_34 -> V_106 ,
} ;
struct V_1 * V_4 ;
int V_7 ;
V_7 = F_3 ( V_2 , & V_99 , & V_4 ) ;
if ( V_7 )
return F_195 ( V_7 ) ;
return V_4 ;
}
int F_196 ( struct V_33 * V_34 )
{
struct V_140 * V_166 ;
struct V_2 * V_2 = F_35 ( V_34 -> V_61 ) ;
int V_179 = F_192 ( V_34 ) -> V_321 & V_322 ;
struct V_1 * V_4 ;
if ( F_172 ( V_34 ) -> V_13 & V_307 )
goto V_314;
V_4 = F_194 ( V_2 , V_34 ) ;
if ( F_13 ( V_4 ) ) {
F_49 ( V_34 ) ;
return F_14 ( V_4 ) ;
}
if ( ! V_179 ) {
if ( F_172 ( V_34 ) -> V_295 . V_323 ) {
if ( F_197 ( V_34 ) )
return 0 ;
} else if ( F_80 ( V_34 ) -> V_78 == V_242 ) {
struct V_205 * V_206 ;
V_206 = F_128 ( V_4 -> V_206 ) ;
if ( V_206 ) {
F_173 ( V_34 ) ;
F_198 ( V_206 , V_34 ) ;
return 0 ;
}
}
}
V_166 = F_98 ( V_4 , F_80 ( V_34 ) -> V_74 , F_80 ( V_34 ) -> V_71 ) ;
if ( ! V_166 ) {
int V_238 = F_190 ( V_4 , V_34 -> V_61 ) ;
if ( V_238 >= 0 )
V_166 = F_103 ( V_4 , F_80 ( V_34 ) -> V_71 ,
V_238 ) ;
}
if ( ! V_166 ) {
int V_238 ;
if ( V_179 ) {
struct V_33 * V_319 = F_193 ( V_34 , V_197 ) ;
F_199 ( V_34 ) ;
if ( ! V_319 )
return - V_174 ;
V_34 = V_319 ;
}
F_50 ( & V_107 ) ;
V_238 = F_190 ( V_4 , V_34 -> V_61 ) ;
if ( V_238 >= 0 ) {
int V_49 = F_131 ( V_4 , V_238 , V_34 ) ;
F_52 ( & V_107 ) ;
return V_49 ;
}
F_52 ( & V_107 ) ;
F_49 ( V_34 ) ;
return - V_324 ;
}
F_50 ( & V_107 ) ;
F_112 ( V_2 , V_4 , V_34 , V_166 , V_179 ) ;
F_52 ( & V_107 ) ;
if ( V_179 )
return F_199 ( V_34 ) ;
return 0 ;
V_314:
if ( V_179 )
return F_199 ( V_34 ) ;
F_49 ( V_34 ) ;
return 0 ;
}
static int F_200 ( struct V_1 * V_4 , struct V_33 * V_34 ,
unsigned int V_325 )
{
struct V_60 * V_326 = NULL ;
struct V_117 * V_301 ;
V_301 = (struct V_117 * ) ( F_201 ( V_34 ) + V_325 ) ;
if ( ! F_142 ( V_301 -> V_71 ) ||
V_301 -> V_211 == 0 ||
F_121 ( V_301 -> V_211 ) + V_325 > V_34 -> V_110 )
return 1 ;
F_50 ( & V_107 ) ;
if ( V_4 -> V_59 >= 0 )
V_326 = V_4 -> V_133 [ V_4 -> V_59 ] . V_61 ;
F_52 ( & V_107 ) ;
if ( ! V_326 )
return 1 ;
V_34 -> V_327 = V_34 -> V_215 ;
F_81 ( V_34 , ( V_199 * ) V_301 - V_34 -> V_212 ) ;
F_117 ( V_34 ) ;
V_34 -> V_78 = F_120 ( V_328 ) ;
V_34 -> V_329 = V_330 ;
F_202 ( V_34 , V_326 , F_35 ( V_326 ) ) ;
F_203 ( V_34 ) ;
return V_331 ;
}
int F_204 ( struct V_33 * V_34 )
{
struct V_202 * V_332 ;
struct V_2 * V_2 = F_35 ( V_34 -> V_61 ) ;
struct V_1 * V_4 ;
if ( ! F_205 ( V_34 , sizeof( * V_332 ) + sizeof( struct V_117 ) ) )
goto V_333;
V_332 = F_206 ( V_34 ) ;
V_4 = F_194 ( V_2 , V_34 ) ;
if ( F_13 ( V_4 ) )
goto V_333;
if ( ! V_4 -> V_258 ||
V_332 -> V_334 != V_335 || V_332 -> V_213 != V_336 )
goto V_333;
if ( F_200 ( V_4 , V_34 , sizeof( * V_332 ) ) ) {
V_333:
F_49 ( V_34 ) ;
}
return 0 ;
}
static int F_207 ( struct V_33 * V_34 )
{
struct V_337 * V_332 ;
struct V_2 * V_2 = F_35 ( V_34 -> V_61 ) ;
struct V_1 * V_4 ;
if ( ! F_205 ( V_34 , sizeof( * V_332 ) + sizeof( struct V_117 ) ) )
goto V_333;
V_332 = (struct V_337 * ) F_201 ( V_34 ) ;
if ( V_332 -> type != ( ( V_338 << 4 ) | ( V_339 ) ) ||
( V_332 -> V_13 & V_340 ) ||
( F_208 ( ( void * ) V_332 , sizeof( * V_332 ) ) != 0 &&
F_209 ( F_210 ( V_34 , 0 , V_34 -> V_110 , 0 ) ) ) )
goto V_333;
V_4 = F_194 ( V_2 , V_34 ) ;
if ( F_13 ( V_4 ) )
goto V_333;
if ( F_200 ( V_4 , V_34 , sizeof( * V_332 ) ) ) {
V_333:
F_49 ( V_34 ) ;
}
return 0 ;
}
static int F_110 ( struct V_1 * V_4 , struct V_33 * V_34 ,
struct V_140 * V_141 , struct V_341 * V_342 )
{
int V_289 ;
struct V_343 * V_344 ;
struct V_37 * V_345 ;
struct V_346 V_347 ;
if ( V_141 -> V_196 >= V_169 )
return - V_225 ;
if ( F_65 ( V_4 , V_141 -> V_196 ) &&
F_211 ( V_34 , V_348 , V_4 -> V_133 [ V_141 -> V_196 ] . V_61 -> V_101 ) < 0 )
return - V_200 ;
if ( ! ( V_345 = F_212 ( V_34 , V_349 ) ) )
return - V_200 ;
for ( V_289 = V_141 -> V_147 . V_9 . V_168 ; V_289 < V_141 -> V_147 . V_9 . V_131 ; V_289 ++ ) {
if ( F_65 ( V_4 , V_289 ) && V_141 -> V_147 . V_9 . V_167 [ V_289 ] < 255 ) {
if ( ! ( V_344 = F_213 ( V_34 , sizeof( * V_344 ) ) ) ) {
F_214 ( V_34 , V_345 ) ;
return - V_200 ;
}
V_344 -> V_350 = 0 ;
V_344 -> V_351 = V_141 -> V_147 . V_9 . V_167 [ V_289 ] ;
V_344 -> V_352 = V_4 -> V_133 [ V_289 ] . V_61 -> V_101 ;
V_344 -> V_353 = sizeof( * V_344 ) ;
}
}
F_215 ( V_34 , V_345 ) ;
V_347 . V_354 = V_141 -> V_147 . V_9 . V_201 ;
V_347 . V_355 = V_141 -> V_147 . V_9 . V_280 ;
V_347 . V_356 = V_141 -> V_147 . V_9 . V_281 ;
if ( F_216 ( V_34 , V_357 , sizeof( V_347 ) , & V_347 ) < 0 )
return - V_200 ;
V_342 -> V_358 = V_359 ;
return 1 ;
}
int F_217 ( struct V_2 * V_2 , struct V_33 * V_34 ,
T_6 V_74 , T_6 V_71 ,
struct V_341 * V_342 , int V_360 )
{
struct V_140 * V_166 ;
struct V_1 * V_4 ;
int V_7 ;
V_4 = F_1 ( V_2 , V_46 ) ;
if ( ! V_4 )
return - V_225 ;
F_59 () ;
V_166 = F_98 ( V_4 , V_74 , V_71 ) ;
if ( ! V_166 && V_34 -> V_61 ) {
int V_238 = F_190 ( V_4 , V_34 -> V_61 ) ;
if ( V_238 >= 0 )
V_166 = F_103 ( V_4 , V_71 , V_238 ) ;
}
if ( ! V_166 ) {
struct V_33 * V_319 ;
struct V_117 * V_70 ;
struct V_60 * V_61 ;
int V_238 = - 1 ;
if ( V_360 ) {
F_61 () ;
return - V_31 ;
}
V_61 = V_34 -> V_61 ;
F_50 ( & V_107 ) ;
if ( V_61 )
V_238 = F_190 ( V_4 , V_61 ) ;
if ( V_238 < 0 ) {
F_52 ( & V_107 ) ;
F_61 () ;
return - V_324 ;
}
V_319 = F_193 ( V_34 , V_197 ) ;
if ( ! V_319 ) {
F_52 ( & V_107 ) ;
F_61 () ;
return - V_47 ;
}
F_116 ( V_319 , sizeof( struct V_117 ) ) ;
F_117 ( V_319 ) ;
V_70 = F_80 ( V_319 ) ;
V_70 -> V_77 = sizeof( struct V_117 ) >> 2 ;
V_70 -> V_74 = V_74 ;
V_70 -> V_71 = V_71 ;
V_70 -> V_76 = 0 ;
V_7 = F_131 ( V_4 , V_238 , V_319 ) ;
F_52 ( & V_107 ) ;
F_61 () ;
return V_7 ;
}
F_50 ( & V_107 ) ;
if ( ! V_360 && ( V_342 -> V_361 & V_362 ) )
V_166 -> V_229 |= V_363 ;
V_7 = F_110 ( V_4 , V_34 , V_166 , V_342 ) ;
F_52 ( & V_107 ) ;
F_61 () ;
return V_7 ;
}
static int F_218 ( struct V_1 * V_4 , struct V_33 * V_34 ,
T_1 V_157 , T_1 V_364 , struct V_140 * V_141 , int V_265 ,
int V_13 )
{
struct V_150 * V_151 ;
struct V_341 * V_342 ;
int V_7 ;
V_151 = F_219 ( V_34 , V_157 , V_364 , V_265 , sizeof( * V_342 ) , V_13 ) ;
if ( ! V_151 )
return - V_200 ;
V_342 = F_84 ( V_151 ) ;
V_342 -> V_365 = V_366 ;
V_342 -> V_367 = 32 ;
V_342 -> V_368 = 32 ;
V_342 -> V_369 = 0 ;
V_342 -> V_370 = V_4 -> V_3 ;
if ( F_211 ( V_34 , V_371 , V_4 -> V_3 ) )
goto V_372;
V_342 -> V_358 = V_359 ;
V_342 -> V_373 = V_374 ;
if ( V_141 -> V_229 & V_230 )
V_342 -> V_375 = V_376 ;
else
V_342 -> V_375 = V_377 ;
V_342 -> V_361 = 0 ;
if ( F_220 ( V_34 , V_378 , V_141 -> V_191 ) ||
F_220 ( V_34 , V_379 , V_141 -> V_192 ) )
goto V_372;
V_7 = F_110 ( V_4 , V_34 , V_141 , V_342 ) ;
if ( V_7 < 0 && V_7 != - V_225 )
goto V_372;
F_221 ( V_34 , V_151 ) ;
return 0 ;
V_372:
F_222 ( V_34 , V_151 ) ;
return - V_200 ;
}
static T_8 F_223 ( bool V_149 , int V_131 )
{
T_8 V_110 =
F_224 ( sizeof( struct V_341 ) )
+ F_225 ( 4 )
+ F_225 ( 4 )
+ F_225 ( 4 )
;
if ( ! V_149 )
V_110 = V_110
+ F_225 ( 4 )
+ F_225 ( 0 )
+ V_131 * F_226 ( sizeof( struct V_343 ) )
+ F_225 ( sizeof( struct V_346 ) )
;
return V_110 ;
}
static void F_91 ( struct V_1 * V_4 , struct V_140 * V_221 ,
int V_265 )
{
struct V_2 * V_2 = F_77 ( & V_4 -> V_2 ) ;
struct V_33 * V_34 ;
int V_7 = - V_174 ;
V_34 = F_227 ( F_223 ( V_221 -> V_196 >= V_169 , V_4 -> V_131 ) ,
V_197 ) ;
if ( ! V_34 )
goto V_380;
V_7 = F_218 ( V_4 , V_34 , 0 , 0 , V_221 , V_265 , 0 ) ;
if ( V_7 < 0 )
goto V_380;
F_228 ( V_34 , V_2 , 0 , V_381 , NULL , V_197 ) ;
return;
V_380:
F_49 ( V_34 ) ;
if ( V_7 < 0 )
F_229 ( V_2 , V_381 , V_7 ) ;
}
static int F_230 ( struct V_33 * V_34 , struct V_382 * V_383 )
{
struct V_2 * V_2 = F_148 ( V_34 -> V_232 ) ;
struct V_1 * V_4 ;
struct V_140 * V_221 ;
unsigned int V_384 = 0 , V_385 ;
unsigned int V_386 = 0 , V_387 ;
unsigned int V_145 = 0 , V_388 ;
V_385 = V_383 -> args [ 0 ] ;
V_387 = V_383 -> args [ 1 ] ;
V_388 = V_383 -> args [ 2 ] ;
F_59 () ;
F_2 (mrt, net) {
if ( V_384 < V_385 )
goto V_389;
if ( V_384 > V_385 )
V_387 = 0 ;
for ( V_386 = V_387 ; V_386 < V_54 ; V_386 ++ ) {
F_100 (mfc, &mrt->mfc_cache_array[h], list) {
if ( V_145 < V_388 )
goto V_390;
if ( F_218 ( V_4 , V_34 ,
F_86 ( V_383 -> V_34 ) . V_157 ,
V_383 -> V_151 -> V_391 ,
V_221 , V_218 ,
V_392 ) < 0 )
goto V_393;
V_390:
V_145 ++ ;
}
V_145 = V_388 = 0 ;
}
F_132 ( & V_160 ) ;
F_133 (mfc, &mrt->mfc_unres_queue, list) {
if ( V_145 < V_388 )
goto V_394;
if ( F_218 ( V_4 , V_34 ,
F_86 ( V_383 -> V_34 ) . V_157 ,
V_383 -> V_151 -> V_391 ,
V_221 , V_218 ,
V_392 ) < 0 ) {
F_135 ( & V_160 ) ;
goto V_393;
}
V_394:
V_145 ++ ;
}
F_135 ( & V_160 ) ;
V_145 = V_388 = 0 ;
V_387 = 0 ;
V_389:
V_384 ++ ;
}
V_393:
F_61 () ;
V_383 -> args [ 2 ] = V_145 ;
V_383 -> args [ 1 ] = V_386 ;
V_383 -> args [ 0 ] = V_384 ;
return V_34 -> V_110 ;
}
static struct V_130 * F_231 ( struct V_2 * V_2 ,
struct V_395 * V_396 ,
T_9 V_397 )
{
struct V_1 * V_4 = V_396 -> V_4 ;
for ( V_396 -> V_289 = 0 ; V_396 -> V_289 < V_4 -> V_131 ; ++ V_396 -> V_289 ) {
if ( ! F_65 ( V_4 , V_396 -> V_289 ) )
continue;
if ( V_397 -- == 0 )
return & V_4 -> V_133 [ V_396 -> V_289 ] ;
}
return NULL ;
}
static void * F_232 ( struct V_398 * V_364 , T_9 * V_397 )
__acquires( V_107 )
{
struct V_395 * V_396 = V_364 -> V_399 ;
struct V_2 * V_2 = F_233 ( V_364 ) ;
struct V_1 * V_4 ;
V_4 = F_1 ( V_2 , V_46 ) ;
if ( ! V_4 )
return F_195 ( - V_225 ) ;
V_396 -> V_4 = V_4 ;
F_50 ( & V_107 ) ;
return * V_397 ? F_231 ( V_2 , V_364 -> V_399 , * V_397 - 1 )
: V_400 ;
}
static void * F_234 ( struct V_398 * V_364 , void * V_63 , T_9 * V_397 )
{
struct V_395 * V_396 = V_364 -> V_399 ;
struct V_2 * V_2 = F_233 ( V_364 ) ;
struct V_1 * V_4 = V_396 -> V_4 ;
++ * V_397 ;
if ( V_63 == V_400 )
return F_231 ( V_2 , V_396 , 0 ) ;
while ( ++ V_396 -> V_289 < V_4 -> V_131 ) {
if ( ! F_65 ( V_4 , V_396 -> V_289 ) )
continue;
return & V_4 -> V_133 [ V_396 -> V_289 ] ;
}
return NULL ;
}
static void F_235 ( struct V_398 * V_364 , void * V_63 )
__releases( V_107 )
{
F_52 ( & V_107 ) ;
}
static int F_236 ( struct V_398 * V_364 , void * V_63 )
{
struct V_395 * V_396 = V_364 -> V_399 ;
struct V_1 * V_4 = V_396 -> V_4 ;
if ( V_63 == V_400 ) {
F_237 ( V_364 ,
L_6 ) ;
} else {
const struct V_130 * V_238 = V_63 ;
const char * V_80 = V_238 -> V_61 ? V_238 -> V_61 -> V_80 : L_7 ;
F_238 ( V_364 ,
L_8 ,
V_238 - V_4 -> V_133 ,
V_80 , V_238 -> V_184 , V_238 -> V_186 ,
V_238 -> V_185 , V_238 -> V_187 ,
V_238 -> V_13 , V_238 -> V_179 , V_238 -> V_180 ) ;
}
return 0 ;
}
static int F_239 ( struct V_401 * V_401 , struct V_402 * V_402 )
{
return F_240 ( V_401 , V_402 , & V_403 ,
sizeof( struct V_395 ) ) ;
}
static struct V_140 * F_241 ( struct V_2 * V_2 ,
struct V_404 * V_405 , T_9 V_397 )
{
struct V_1 * V_4 = V_405 -> V_4 ;
struct V_140 * V_221 ;
F_59 () ;
for ( V_405 -> V_289 = 0 ; V_405 -> V_289 < V_54 ; V_405 -> V_289 ++ ) {
V_405 -> V_166 = & V_4 -> V_55 [ V_405 -> V_289 ] ;
F_100 (mfc, it->cache, list)
if ( V_397 -- == 0 )
return V_221 ;
}
F_61 () ;
F_132 ( & V_160 ) ;
V_405 -> V_166 = & V_4 -> V_56 ;
F_133 (mfc, it->cache, list)
if ( V_397 -- == 0 )
return V_221 ;
F_135 ( & V_160 ) ;
V_405 -> V_166 = NULL ;
return NULL ;
}
static void * F_242 ( struct V_398 * V_364 , T_9 * V_397 )
{
struct V_404 * V_405 = V_364 -> V_399 ;
struct V_2 * V_2 = F_233 ( V_364 ) ;
struct V_1 * V_4 ;
V_4 = F_1 ( V_2 , V_46 ) ;
if ( ! V_4 )
return F_195 ( - V_225 ) ;
V_405 -> V_4 = V_4 ;
V_405 -> V_166 = NULL ;
V_405 -> V_289 = 0 ;
return * V_397 ? F_241 ( V_2 , V_364 -> V_399 , * V_397 - 1 )
: V_400 ;
}
static void * F_243 ( struct V_398 * V_364 , void * V_63 , T_9 * V_397 )
{
struct V_140 * V_221 = V_63 ;
struct V_404 * V_405 = V_364 -> V_399 ;
struct V_2 * V_2 = F_233 ( V_364 ) ;
struct V_1 * V_4 = V_405 -> V_4 ;
++ * V_397 ;
if ( V_63 == V_400 )
return F_241 ( V_2 , V_364 -> V_399 , 0 ) ;
if ( V_221 -> V_51 . V_50 != V_405 -> V_166 )
return F_244 ( V_221 -> V_51 . V_50 , struct V_140 , V_51 ) ;
if ( V_405 -> V_166 == & V_4 -> V_56 )
goto V_406;
F_245 ( V_405 -> V_166 != & V_4 -> V_55 [ V_405 -> V_289 ] ) ;
while ( ++ V_405 -> V_289 < V_54 ) {
V_405 -> V_166 = & V_4 -> V_55 [ V_405 -> V_289 ] ;
if ( F_89 ( V_405 -> V_166 ) )
continue;
return F_246 ( V_405 -> V_166 , struct V_140 , V_51 ) ;
}
F_61 () ;
V_405 -> V_166 = & V_4 -> V_56 ;
V_405 -> V_289 = 0 ;
F_132 ( & V_160 ) ;
if ( ! F_89 ( V_405 -> V_166 ) )
return F_246 ( V_405 -> V_166 , struct V_140 , V_51 ) ;
V_406:
F_135 ( & V_160 ) ;
V_405 -> V_166 = NULL ;
return NULL ;
}
static void F_247 ( struct V_398 * V_364 , void * V_63 )
{
struct V_404 * V_405 = V_364 -> V_399 ;
struct V_1 * V_4 = V_405 -> V_4 ;
if ( V_405 -> V_166 == & V_4 -> V_56 )
F_135 ( & V_160 ) ;
else if ( V_405 -> V_166 == & V_4 -> V_55 [ V_405 -> V_289 ] )
F_61 () ;
}
static int F_248 ( struct V_398 * V_364 , void * V_63 )
{
int V_407 ;
if ( V_63 == V_400 ) {
F_237 ( V_364 ,
L_9 ) ;
} else {
const struct V_140 * V_221 = V_63 ;
const struct V_404 * V_405 = V_364 -> V_399 ;
const struct V_1 * V_4 = V_405 -> V_4 ;
F_238 ( V_364 , L_10 ,
( V_84 T_1 ) V_221 -> V_192 ,
( V_84 T_1 ) V_221 -> V_191 ,
V_221 -> V_196 ) ;
if ( V_405 -> V_166 != & V_4 -> V_56 ) {
F_238 ( V_364 , L_11 ,
V_221 -> V_147 . V_9 . V_201 ,
V_221 -> V_147 . V_9 . V_280 ,
V_221 -> V_147 . V_9 . V_281 ) ;
for ( V_407 = V_221 -> V_147 . V_9 . V_168 ;
V_407 < V_221 -> V_147 . V_9 . V_131 ; V_407 ++ ) {
if ( F_65 ( V_4 , V_407 ) &&
V_221 -> V_147 . V_9 . V_167 [ V_407 ] < 255 )
F_238 ( V_364 ,
L_12 ,
V_407 , V_221 -> V_147 . V_9 . V_167 [ V_407 ] ) ;
}
} else {
F_238 ( V_364 , L_11 , 0ul , 0ul , 0ul ) ;
}
F_249 ( V_364 , '\n' ) ;
}
return 0 ;
}
static int F_250 ( struct V_401 * V_401 , struct V_402 * V_402 )
{
return F_240 ( V_401 , V_402 , & V_408 ,
sizeof( struct V_404 ) ) ;
}
static int T_2 F_251 ( struct V_2 * V_2 )
{
int V_7 ;
V_7 = F_11 ( V_2 ) ;
if ( V_7 < 0 )
goto V_409;
#ifdef F_252
V_7 = - V_47 ;
if ( ! F_253 ( L_13 , 0 , V_2 -> V_410 , & V_411 ) )
goto V_412;
if ( ! F_253 ( L_14 , 0 , V_2 -> V_410 , & V_413 ) )
goto V_414;
#endif
return 0 ;
#ifdef F_252
V_414:
F_254 ( L_13 , V_2 -> V_410 ) ;
V_412:
F_20 ( V_2 ) ;
#endif
V_409:
return V_7 ;
}
static void T_3 F_255 ( struct V_2 * V_2 )
{
#ifdef F_252
F_254 ( L_14 , V_2 -> V_410 ) ;
F_254 ( L_13 , V_2 -> V_410 ) ;
#endif
F_20 ( V_2 ) ;
}
int T_10 F_256 ( void )
{
int V_7 ;
V_143 = F_257 ( L_15 ,
sizeof( struct V_140 ) ,
0 , V_415 | V_416 ,
NULL ) ;
if ( ! V_143 )
return - V_47 ;
V_7 = F_258 ( & V_417 ) ;
if ( V_7 )
goto V_418;
V_7 = F_259 ( & V_419 ) ;
if ( V_7 )
goto V_420;
#ifdef F_260
if ( F_261 ( & V_421 , V_422 ) < 0 ) {
F_262 ( L_16 , V_423 ) ;
V_7 = - V_31 ;
goto V_424;
}
#endif
F_263 ( V_366 , V_425 ,
NULL , F_230 , NULL ) ;
return 0 ;
#ifdef F_260
V_424:
F_264 ( & V_419 ) ;
#endif
V_420:
F_265 ( & V_417 ) ;
V_418:
F_266 ( V_143 ) ;
return V_7 ;
}
