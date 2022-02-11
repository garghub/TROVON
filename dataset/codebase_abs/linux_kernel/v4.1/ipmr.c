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
F_32 ( V_4 ) ;
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
F_24 () ;
F_21 () ;
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
F_24 () ;
F_21 () ;
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
static void F_32 ( struct V_1 * V_4 )
{
int V_52 ;
F_145 ( V_51 ) ;
struct V_140 * V_141 , * V_50 ;
for ( V_52 = 0 ; V_52 < V_4 -> V_131 ; V_52 ++ ) {
if ( ! ( V_4 -> V_133 [ V_52 ] . V_13 & V_181 ) )
F_62 ( V_4 , V_52 , 0 , & V_51 ) ;
}
F_146 ( & V_51 ) ;
for ( V_52 = 0 ; V_52 < V_54 ; V_52 ++ ) {
F_22 (c, next, &mrt->mfc_cache_array[i], list) {
if ( V_141 -> V_229 & V_230 )
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
static void F_147 ( struct V_205 * V_231 )
{
struct V_2 * V_2 = F_148 ( V_231 ) ;
struct V_1 * V_4 ;
F_21 () ;
F_2 (mrt, net) {
if ( V_231 == F_149 ( V_4 -> V_206 ) ) {
F_150 ( V_2 , V_135 ) -- ;
F_67 ( V_2 , V_136 ,
V_232 ,
V_2 -> V_15 . V_233 ) ;
F_151 ( V_4 -> V_206 , NULL ) ;
F_32 ( V_4 ) ;
}
}
F_24 () ;
}
int F_152 ( struct V_205 * V_231 , int V_234 , char V_85 * V_235 , unsigned int V_236 )
{
int V_207 , V_222 = 0 ;
struct V_62 V_237 ;
struct V_220 V_221 ;
struct V_2 * V_2 = F_148 ( V_231 ) ;
struct V_1 * V_4 ;
if ( V_231 -> V_238 != V_239 ||
F_153 ( V_231 ) -> V_240 != V_241 )
return - V_93 ;
V_4 = F_1 ( V_2 , F_154 ( V_231 ) -> V_242 ? : V_46 ) ;
if ( ! V_4 )
return - V_225 ;
if ( V_234 != V_243 ) {
if ( V_231 != F_155 ( V_4 -> V_206 ) &&
! F_156 ( V_2 -> V_244 , V_245 ) )
return - V_26 ;
}
switch ( V_234 ) {
case V_243 :
if ( V_236 != sizeof( int ) )
return - V_28 ;
F_21 () ;
if ( F_149 ( V_4 -> V_206 ) ) {
F_24 () ;
return - V_172 ;
}
V_207 = F_157 ( V_231 , 1 , F_147 ) ;
if ( V_207 == 0 ) {
F_158 ( V_4 -> V_206 , V_231 ) ;
F_150 ( V_2 , V_135 ) ++ ;
F_67 ( V_2 , V_136 ,
V_232 ,
V_2 -> V_15 . V_233 ) ;
}
F_24 () ;
return V_207 ;
case V_246 :
if ( V_231 != F_155 ( V_4 -> V_206 ) )
return - V_26 ;
return F_157 ( V_231 , 0 , NULL ) ;
case V_247 :
case V_248 :
if ( V_236 != sizeof( V_237 ) )
return - V_28 ;
if ( F_159 ( & V_237 , V_235 , sizeof( V_237 ) ) )
return - V_249 ;
if ( V_237 . V_81 >= V_169 )
return - V_227 ;
F_21 () ;
if ( V_234 == V_247 ) {
V_207 = F_94 ( V_2 , V_4 , & V_237 ,
V_231 == F_149 ( V_4 -> V_206 ) ) ;
} else {
V_207 = F_62 ( V_4 , V_237 . V_81 , 0 , NULL ) ;
}
F_24 () ;
return V_207 ;
case V_250 :
case V_251 :
V_222 = - 1 ;
case V_252 :
case V_253 :
if ( V_236 != sizeof( V_221 ) )
return - V_28 ;
if ( F_159 ( & V_221 , V_235 , sizeof( V_221 ) ) )
return - V_249 ;
if ( V_222 == 0 )
V_222 = V_221 . V_226 ;
F_21 () ;
if ( V_234 == V_251 || V_234 == V_253 )
V_207 = F_139 ( V_4 , & V_221 , V_222 ) ;
else
V_207 = F_141 ( V_2 , V_4 , & V_221 ,
V_231 == F_149 ( V_4 -> V_206 ) ,
V_222 ) ;
F_24 () ;
return V_207 ;
case V_254 :
{
int V_63 ;
if ( V_236 != sizeof( V_63 ) )
return - V_28 ;
if ( F_160 ( V_63 , ( int V_85 * ) V_235 ) )
return - V_249 ;
V_4 -> V_255 = V_63 ;
return 0 ;
}
#ifdef F_28
case V_256 :
{
int V_63 ;
if ( V_236 != sizeof( V_63 ) )
return - V_28 ;
if ( F_160 ( V_63 , ( int V_85 * ) V_235 ) )
return - V_249 ;
V_63 = ! ! V_63 ;
F_21 () ;
V_207 = 0 ;
if ( V_63 != V_4 -> V_257 ) {
V_4 -> V_257 = V_63 ;
V_4 -> V_255 = V_63 ;
}
F_24 () ;
return V_207 ;
}
#endif
#ifdef F_29
case V_258 :
{
T_1 V_63 ;
if ( V_236 != sizeof( T_1 ) )
return - V_28 ;
if ( F_160 ( V_63 , ( T_1 V_85 * ) V_235 ) )
return - V_249 ;
if ( V_63 != V_46 && V_63 >= 1000000000 )
return - V_28 ;
F_21 () ;
V_207 = 0 ;
if ( V_231 == F_149 ( V_4 -> V_206 ) ) {
V_207 = - V_259 ;
} else {
if ( ! F_16 ( V_2 , V_63 ) )
V_207 = - V_47 ;
else
F_154 ( V_231 ) -> V_242 = V_63 ;
}
F_24 () ;
return V_207 ;
}
#endif
default:
return - V_260 ;
}
}
int F_161 ( struct V_205 * V_231 , int V_234 , char V_85 * V_235 , int V_85 * V_236 )
{
int V_261 ;
int V_262 ;
struct V_2 * V_2 = F_148 ( V_231 ) ;
struct V_1 * V_4 ;
if ( V_231 -> V_238 != V_239 ||
F_153 ( V_231 ) -> V_240 != V_241 )
return - V_93 ;
V_4 = F_1 ( V_2 , F_154 ( V_231 ) -> V_242 ? : V_46 ) ;
if ( ! V_4 )
return - V_225 ;
if ( V_234 != V_263 &&
#ifdef F_28
V_234 != V_256 &&
#endif
V_234 != V_254 )
return - V_260 ;
if ( F_160 ( V_261 , V_236 ) )
return - V_249 ;
V_261 = F_162 (unsigned int, olr, sizeof(int)) ;
if ( V_261 < 0 )
return - V_28 ;
if ( F_163 ( V_261 , V_236 ) )
return - V_249 ;
if ( V_234 == V_263 )
V_262 = 0x0305 ;
#ifdef F_28
else if ( V_234 == V_256 )
V_262 = V_4 -> V_257 ;
#endif
else
V_262 = V_4 -> V_255 ;
if ( F_164 ( V_235 , & V_262 , V_261 ) )
return - V_249 ;
return 0 ;
}
int F_165 ( struct V_205 * V_231 , int V_264 , void V_85 * V_11 )
{
struct V_265 V_266 ;
struct V_267 V_268 ;
struct V_130 * V_237 ;
struct V_140 * V_141 ;
struct V_2 * V_2 = F_148 ( V_231 ) ;
struct V_1 * V_4 ;
V_4 = F_1 ( V_2 , F_154 ( V_231 ) -> V_242 ? : V_46 ) ;
if ( ! V_4 )
return - V_225 ;
switch ( V_264 ) {
case V_269 :
if ( F_159 ( & V_268 , V_11 , sizeof( V_268 ) ) )
return - V_249 ;
if ( V_268 . V_126 >= V_4 -> V_131 )
return - V_28 ;
F_50 ( & V_107 ) ;
V_237 = & V_4 -> V_133 [ V_268 . V_126 ] ;
if ( F_65 ( V_4 , V_268 . V_126 ) ) {
V_268 . V_270 = V_237 -> V_186 ;
V_268 . V_271 = V_237 -> V_187 ;
V_268 . V_272 = V_237 -> V_184 ;
V_268 . V_273 = V_237 -> V_185 ;
F_52 ( & V_107 ) ;
if ( F_164 ( V_11 , & V_268 , sizeof( V_268 ) ) )
return - V_249 ;
return 0 ;
}
F_52 ( & V_107 ) ;
return - V_132 ;
case V_274 :
if ( F_159 ( & V_266 , V_11 , sizeof( V_266 ) ) )
return - V_249 ;
F_59 () ;
V_141 = F_98 ( V_4 , V_266 . V_275 . V_73 , V_266 . V_276 . V_73 ) ;
if ( V_141 ) {
V_266 . V_277 = V_141 -> V_147 . V_9 . V_201 ;
V_266 . V_278 = V_141 -> V_147 . V_9 . V_279 ;
V_266 . V_280 = V_141 -> V_147 . V_9 . V_280 ;
F_61 () ;
if ( F_164 ( V_11 , & V_266 , sizeof( V_266 ) ) )
return - V_249 ;
return 0 ;
}
F_61 () ;
return - V_132 ;
default:
return - V_281 ;
}
}
int F_166 ( struct V_205 * V_231 , unsigned int V_264 , void V_85 * V_11 )
{
struct V_282 V_266 ;
struct V_283 V_268 ;
struct V_130 * V_237 ;
struct V_140 * V_141 ;
struct V_2 * V_2 = F_148 ( V_231 ) ;
struct V_1 * V_4 ;
V_4 = F_1 ( V_2 , F_154 ( V_231 ) -> V_242 ? : V_46 ) ;
if ( ! V_4 )
return - V_225 ;
switch ( V_264 ) {
case V_269 :
if ( F_159 ( & V_268 , V_11 , sizeof( V_268 ) ) )
return - V_249 ;
if ( V_268 . V_126 >= V_4 -> V_131 )
return - V_28 ;
F_50 ( & V_107 ) ;
V_237 = & V_4 -> V_133 [ V_268 . V_126 ] ;
if ( F_65 ( V_4 , V_268 . V_126 ) ) {
V_268 . V_270 = V_237 -> V_186 ;
V_268 . V_271 = V_237 -> V_187 ;
V_268 . V_272 = V_237 -> V_184 ;
V_268 . V_273 = V_237 -> V_185 ;
F_52 ( & V_107 ) ;
if ( F_164 ( V_11 , & V_268 , sizeof( V_268 ) ) )
return - V_249 ;
return 0 ;
}
F_52 ( & V_107 ) ;
return - V_132 ;
case V_274 :
if ( F_159 ( & V_266 , V_11 , sizeof( V_266 ) ) )
return - V_249 ;
F_59 () ;
V_141 = F_98 ( V_4 , V_266 . V_275 . V_73 , V_266 . V_276 . V_73 ) ;
if ( V_141 ) {
V_266 . V_277 = V_141 -> V_147 . V_9 . V_201 ;
V_266 . V_278 = V_141 -> V_147 . V_9 . V_279 ;
V_266 . V_280 = V_141 -> V_147 . V_9 . V_280 ;
F_61 () ;
if ( F_164 ( V_11 , & V_266 , sizeof( V_266 ) ) )
return - V_249 ;
return 0 ;
}
F_61 () ;
return - V_132 ;
default:
return - V_281 ;
}
}
static int F_167 ( struct V_284 * V_285 , unsigned long V_286 , void * V_287 )
{
struct V_60 * V_61 = F_168 ( V_287 ) ;
struct V_2 * V_2 = F_35 ( V_61 ) ;
struct V_1 * V_4 ;
struct V_130 * V_63 ;
int V_288 ;
if ( V_286 != V_289 )
return V_290 ;
F_2 (mrt, net) {
V_63 = & V_4 -> V_133 [ 0 ] ;
for ( V_288 = 0 ; V_288 < V_4 -> V_131 ; V_288 ++ , V_63 ++ ) {
if ( V_63 -> V_61 == V_61 )
F_62 ( V_4 , V_288 , 1 , NULL ) ;
}
}
return V_290 ;
}
static void F_169 ( struct V_2 * V_2 , struct V_33 * V_34 ,
T_6 V_74 , T_6 V_71 )
{
struct V_117 * V_70 ;
const struct V_117 * V_291 = F_80 ( V_34 ) ;
F_116 ( V_34 , sizeof( struct V_117 ) ) ;
V_34 -> V_214 = V_34 -> V_215 ;
F_117 ( V_34 ) ;
V_70 = F_80 ( V_34 ) ;
V_70 -> V_76 = 4 ;
V_70 -> V_41 = V_291 -> V_41 ;
V_70 -> V_292 = V_291 -> V_292 ;
V_70 -> V_293 = 0 ;
V_70 -> V_71 = V_71 ;
V_70 -> V_74 = V_74 ;
V_70 -> V_78 = V_79 ;
V_70 -> V_77 = 5 ;
V_70 -> V_211 = F_120 ( V_34 -> V_110 ) ;
F_170 ( V_2 , V_34 , NULL ) ;
F_171 ( V_70 ) ;
memset ( & ( F_172 ( V_34 ) -> V_294 ) , 0 , sizeof( F_172 ( V_34 ) -> V_294 ) ) ;
F_173 ( V_34 ) ;
}
static inline int F_174 ( struct V_205 * V_231 , struct V_33 * V_34 )
{
struct V_295 * V_294 = & ( F_172 ( V_34 ) -> V_294 ) ;
F_175 ( F_35 ( F_127 ( V_34 ) -> V_61 ) , V_296 ) ;
F_176 ( F_35 ( F_127 ( V_34 ) -> V_61 ) , V_297 , V_34 -> V_110 ) ;
if ( F_177 ( V_294 -> V_236 ) )
F_178 ( V_34 ) ;
return F_179 ( V_231 , V_34 ) ;
}
static void F_180 ( struct V_2 * V_2 , struct V_1 * V_4 ,
struct V_33 * V_34 , struct V_140 * V_141 , int V_126 )
{
const struct V_117 * V_70 = F_80 ( V_34 ) ;
struct V_130 * V_237 = & V_4 -> V_133 [ V_126 ] ;
struct V_60 * V_61 ;
struct V_298 * V_299 ;
struct V_5 V_99 ;
int V_300 = 0 ;
if ( ! V_237 -> V_61 )
goto V_301;
#ifdef F_28
if ( V_237 -> V_13 & V_138 ) {
V_237 -> V_187 ++ ;
V_237 -> V_185 += V_34 -> V_110 ;
V_237 -> V_61 -> V_108 . V_109 += V_34 -> V_110 ;
V_237 -> V_61 -> V_108 . V_111 ++ ;
F_51 ( V_4 , V_34 , V_126 , V_112 ) ;
goto V_301;
}
#endif
if ( V_237 -> V_13 & V_137 ) {
V_299 = F_181 ( V_2 , & V_99 , NULL ,
V_237 -> V_180 , V_237 -> V_179 ,
0 , 0 ,
V_79 ,
F_182 ( V_70 -> V_41 ) , V_237 -> V_188 ) ;
if ( F_13 ( V_299 ) )
goto V_301;
V_300 = sizeof( struct V_117 ) ;
} else {
V_299 = F_181 ( V_2 , & V_99 , NULL , V_70 -> V_71 , 0 ,
0 , 0 ,
V_79 ,
F_182 ( V_70 -> V_41 ) , V_237 -> V_188 ) ;
if ( F_13 ( V_299 ) )
goto V_301;
}
V_61 = V_299 -> V_302 . V_61 ;
if ( V_34 -> V_110 + V_300 > F_183 ( & V_299 -> V_302 ) && ( F_121 ( V_70 -> V_293 ) & V_303 ) ) {
F_175 ( F_35 ( V_61 ) , V_304 ) ;
F_184 ( V_299 ) ;
goto V_301;
}
V_300 += F_185 ( V_61 ) + V_299 -> V_302 . V_305 ;
if ( F_186 ( V_34 , V_300 ) ) {
F_184 ( V_299 ) ;
goto V_301;
}
V_237 -> V_187 ++ ;
V_237 -> V_185 += V_34 -> V_110 ;
F_187 ( V_34 ) ;
F_125 ( V_34 , & V_299 -> V_302 ) ;
F_188 ( F_80 ( V_34 ) ) ;
if ( V_237 -> V_13 & V_137 ) {
F_169 ( V_2 , V_34 , V_237 -> V_179 , V_237 -> V_180 ) ;
V_237 -> V_61 -> V_108 . V_111 ++ ;
V_237 -> V_61 -> V_108 . V_109 += V_34 -> V_110 ;
}
F_172 ( V_34 ) -> V_13 |= V_306 ;
F_189 ( V_307 , V_308 , NULL , V_34 ,
V_34 -> V_61 , V_61 ,
F_174 ) ;
return;
V_301:
F_49 ( V_34 ) ;
}
static int F_190 ( struct V_1 * V_4 , struct V_60 * V_61 )
{
int V_288 ;
for ( V_288 = V_4 -> V_131 - 1 ; V_288 >= 0 ; V_288 -- ) {
if ( V_4 -> V_133 [ V_288 ] . V_61 == V_61 )
break;
}
return V_288 ;
}
static void F_112 ( struct V_2 * V_2 , struct V_1 * V_4 ,
struct V_33 * V_34 , struct V_140 * V_166 ,
int V_179 )
{
int V_309 = - 1 ;
int V_237 , V_288 ;
int V_310 = F_190 ( V_4 , V_34 -> V_61 ) ;
V_237 = V_166 -> V_196 ;
V_166 -> V_147 . V_9 . V_201 ++ ;
V_166 -> V_147 . V_9 . V_279 += V_34 -> V_110 ;
if ( V_166 -> V_191 == F_102 ( V_193 ) && V_310 >= 0 ) {
struct V_140 * V_311 ;
V_311 = F_101 ( V_4 , V_237 ) ;
if ( V_311 &&
V_311 -> V_147 . V_9 . V_167 [ V_310 ] < 255 )
goto V_312;
}
if ( V_4 -> V_133 [ V_237 ] . V_61 != V_34 -> V_61 ) {
if ( F_191 ( F_192 ( V_34 ) ) ) {
goto V_313;
}
V_166 -> V_147 . V_9 . V_280 ++ ;
if ( V_310 >= 0 && V_4 -> V_255 &&
( V_4 -> V_257 ||
V_166 -> V_147 . V_9 . V_167 [ V_310 ] < 255 ) &&
F_90 ( V_161 ,
V_166 -> V_147 . V_9 . V_314 + V_315 ) ) {
V_166 -> V_147 . V_9 . V_314 = V_161 ;
F_51 ( V_4 , V_34 , V_310 , V_316 ) ;
}
goto V_313;
}
V_312:
V_4 -> V_133 [ V_237 ] . V_186 ++ ;
V_4 -> V_133 [ V_237 ] . V_184 += V_34 -> V_110 ;
if ( V_166 -> V_191 == F_102 ( V_193 ) &&
V_166 -> V_192 == F_102 ( V_193 ) ) {
if ( V_310 >= 0 &&
V_310 != V_166 -> V_196 &&
F_80 ( V_34 ) -> V_292 >
V_166 -> V_147 . V_9 . V_167 [ V_166 -> V_196 ] ) {
V_309 = V_166 -> V_196 ;
goto V_317;
}
goto V_313;
}
for ( V_288 = V_166 -> V_147 . V_9 . V_131 - 1 ;
V_288 >= V_166 -> V_147 . V_9 . V_168 ; V_288 -- ) {
if ( ( V_166 -> V_191 != F_102 ( V_193 ) ||
V_288 != V_310 ) &&
F_80 ( V_34 ) -> V_292 > V_166 -> V_147 . V_9 . V_167 [ V_288 ] ) {
if ( V_309 != - 1 ) {
struct V_33 * V_318 = F_193 ( V_34 , V_197 ) ;
if ( V_318 )
F_180 ( V_2 , V_4 , V_318 , V_166 ,
V_309 ) ;
}
V_309 = V_288 ;
}
}
V_317:
if ( V_309 != - 1 ) {
if ( V_179 ) {
struct V_33 * V_318 = F_193 ( V_34 , V_197 ) ;
if ( V_318 )
F_180 ( V_2 , V_4 , V_318 , V_166 , V_309 ) ;
} else {
F_180 ( V_2 , V_4 , V_34 , V_166 , V_309 ) ;
return;
}
}
V_313:
if ( ! V_179 )
F_49 ( V_34 ) ;
}
static struct V_1 * F_194 ( struct V_2 * V_2 , struct V_33 * V_34 )
{
struct V_298 * V_299 = F_192 ( V_34 ) ;
struct V_117 * V_70 = F_80 ( V_34 ) ;
struct V_5 V_99 = {
. V_71 = V_70 -> V_71 ,
. V_74 = V_70 -> V_74 ,
. V_319 = F_182 ( V_70 -> V_41 ) ,
. V_100 = ( F_191 ( V_299 ) ?
V_34 -> V_61 -> V_101 : 0 ) ,
. V_102 = ( F_191 ( V_299 ) ?
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
int V_179 = F_192 ( V_34 ) -> V_320 & V_321 ;
struct V_1 * V_4 ;
if ( F_172 ( V_34 ) -> V_13 & V_306 )
goto V_313;
V_4 = F_194 ( V_2 , V_34 ) ;
if ( F_13 ( V_4 ) ) {
F_49 ( V_34 ) ;
return F_14 ( V_4 ) ;
}
if ( ! V_179 ) {
if ( F_172 ( V_34 ) -> V_294 . V_322 ) {
if ( F_197 ( V_34 ) )
return 0 ;
} else if ( F_80 ( V_34 ) -> V_78 == V_241 ) {
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
int V_237 = F_190 ( V_4 , V_34 -> V_61 ) ;
if ( V_237 >= 0 )
V_166 = F_103 ( V_4 , F_80 ( V_34 ) -> V_71 ,
V_237 ) ;
}
if ( ! V_166 ) {
int V_237 ;
if ( V_179 ) {
struct V_33 * V_318 = F_193 ( V_34 , V_197 ) ;
F_199 ( V_34 ) ;
if ( ! V_318 )
return - V_174 ;
V_34 = V_318 ;
}
F_50 ( & V_107 ) ;
V_237 = F_190 ( V_4 , V_34 -> V_61 ) ;
if ( V_237 >= 0 ) {
int V_49 = F_131 ( V_4 , V_237 , V_34 ) ;
F_52 ( & V_107 ) ;
return V_49 ;
}
F_52 ( & V_107 ) ;
F_49 ( V_34 ) ;
return - V_323 ;
}
F_50 ( & V_107 ) ;
F_112 ( V_2 , V_4 , V_34 , V_166 , V_179 ) ;
F_52 ( & V_107 ) ;
if ( V_179 )
return F_199 ( V_34 ) ;
return 0 ;
V_313:
if ( V_179 )
return F_199 ( V_34 ) ;
F_49 ( V_34 ) ;
return 0 ;
}
static int F_200 ( struct V_1 * V_4 , struct V_33 * V_34 ,
unsigned int V_324 )
{
struct V_60 * V_325 = NULL ;
struct V_117 * V_300 ;
V_300 = (struct V_117 * ) ( F_201 ( V_34 ) + V_324 ) ;
if ( ! F_142 ( V_300 -> V_71 ) ||
V_300 -> V_211 == 0 ||
F_121 ( V_300 -> V_211 ) + V_324 > V_34 -> V_110 )
return 1 ;
F_50 ( & V_107 ) ;
if ( V_4 -> V_59 >= 0 )
V_325 = V_4 -> V_133 [ V_4 -> V_59 ] . V_61 ;
F_52 ( & V_107 ) ;
if ( ! V_325 )
return 1 ;
V_34 -> V_326 = V_34 -> V_215 ;
F_81 ( V_34 , ( V_199 * ) V_300 - V_34 -> V_212 ) ;
F_117 ( V_34 ) ;
V_34 -> V_78 = F_120 ( V_327 ) ;
V_34 -> V_328 = V_329 ;
F_202 ( V_34 , V_325 , F_35 ( V_325 ) ) ;
F_203 ( V_34 ) ;
return V_330 ;
}
int F_204 ( struct V_33 * V_34 )
{
struct V_202 * V_331 ;
struct V_2 * V_2 = F_35 ( V_34 -> V_61 ) ;
struct V_1 * V_4 ;
if ( ! F_205 ( V_34 , sizeof( * V_331 ) + sizeof( struct V_117 ) ) )
goto V_332;
V_331 = F_206 ( V_34 ) ;
V_4 = F_194 ( V_2 , V_34 ) ;
if ( F_13 ( V_4 ) )
goto V_332;
if ( ! V_4 -> V_257 ||
V_331 -> V_333 != V_334 || V_331 -> V_213 != V_335 )
goto V_332;
if ( F_200 ( V_4 , V_34 , sizeof( * V_331 ) ) ) {
V_332:
F_49 ( V_34 ) ;
}
return 0 ;
}
static int F_207 ( struct V_33 * V_34 )
{
struct V_336 * V_331 ;
struct V_2 * V_2 = F_35 ( V_34 -> V_61 ) ;
struct V_1 * V_4 ;
if ( ! F_205 ( V_34 , sizeof( * V_331 ) + sizeof( struct V_117 ) ) )
goto V_332;
V_331 = (struct V_336 * ) F_201 ( V_34 ) ;
if ( V_331 -> type != ( ( V_337 << 4 ) | ( V_338 ) ) ||
( V_331 -> V_13 & V_339 ) ||
( F_208 ( ( void * ) V_331 , sizeof( * V_331 ) ) != 0 &&
F_209 ( F_210 ( V_34 , 0 , V_34 -> V_110 , 0 ) ) ) )
goto V_332;
V_4 = F_194 ( V_2 , V_34 ) ;
if ( F_13 ( V_4 ) )
goto V_332;
if ( F_200 ( V_4 , V_34 , sizeof( * V_331 ) ) ) {
V_332:
F_49 ( V_34 ) ;
}
return 0 ;
}
static int F_110 ( struct V_1 * V_4 , struct V_33 * V_34 ,
struct V_140 * V_141 , struct V_340 * V_341 )
{
int V_288 ;
struct V_342 * V_343 ;
struct V_37 * V_344 ;
struct V_345 V_346 ;
if ( V_141 -> V_196 >= V_169 )
return - V_225 ;
if ( F_65 ( V_4 , V_141 -> V_196 ) &&
F_211 ( V_34 , V_347 , V_4 -> V_133 [ V_141 -> V_196 ] . V_61 -> V_101 ) < 0 )
return - V_200 ;
if ( ! ( V_344 = F_212 ( V_34 , V_348 ) ) )
return - V_200 ;
for ( V_288 = V_141 -> V_147 . V_9 . V_168 ; V_288 < V_141 -> V_147 . V_9 . V_131 ; V_288 ++ ) {
if ( F_65 ( V_4 , V_288 ) && V_141 -> V_147 . V_9 . V_167 [ V_288 ] < 255 ) {
if ( ! ( V_343 = F_213 ( V_34 , sizeof( * V_343 ) ) ) ) {
F_214 ( V_34 , V_344 ) ;
return - V_200 ;
}
V_343 -> V_349 = 0 ;
V_343 -> V_350 = V_141 -> V_147 . V_9 . V_167 [ V_288 ] ;
V_343 -> V_351 = V_4 -> V_133 [ V_288 ] . V_61 -> V_101 ;
V_343 -> V_352 = sizeof( * V_343 ) ;
}
}
F_215 ( V_34 , V_344 ) ;
V_346 . V_353 = V_141 -> V_147 . V_9 . V_201 ;
V_346 . V_354 = V_141 -> V_147 . V_9 . V_279 ;
V_346 . V_355 = V_141 -> V_147 . V_9 . V_280 ;
if ( F_216 ( V_34 , V_356 , sizeof( V_346 ) , & V_346 ) < 0 )
return - V_200 ;
V_341 -> V_357 = V_358 ;
return 1 ;
}
int F_217 ( struct V_2 * V_2 , struct V_33 * V_34 ,
T_6 V_74 , T_6 V_71 ,
struct V_340 * V_341 , int V_359 )
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
int V_237 = F_190 ( V_4 , V_34 -> V_61 ) ;
if ( V_237 >= 0 )
V_166 = F_103 ( V_4 , V_71 , V_237 ) ;
}
if ( ! V_166 ) {
struct V_33 * V_318 ;
struct V_117 * V_70 ;
struct V_60 * V_61 ;
int V_237 = - 1 ;
if ( V_359 ) {
F_61 () ;
return - V_31 ;
}
V_61 = V_34 -> V_61 ;
F_50 ( & V_107 ) ;
if ( V_61 )
V_237 = F_190 ( V_4 , V_61 ) ;
if ( V_237 < 0 ) {
F_52 ( & V_107 ) ;
F_61 () ;
return - V_323 ;
}
V_318 = F_193 ( V_34 , V_197 ) ;
if ( ! V_318 ) {
F_52 ( & V_107 ) ;
F_61 () ;
return - V_47 ;
}
F_116 ( V_318 , sizeof( struct V_117 ) ) ;
F_117 ( V_318 ) ;
V_70 = F_80 ( V_318 ) ;
V_70 -> V_77 = sizeof( struct V_117 ) >> 2 ;
V_70 -> V_74 = V_74 ;
V_70 -> V_71 = V_71 ;
V_70 -> V_76 = 0 ;
V_7 = F_131 ( V_4 , V_237 , V_318 ) ;
F_52 ( & V_107 ) ;
F_61 () ;
return V_7 ;
}
F_50 ( & V_107 ) ;
if ( ! V_359 && ( V_341 -> V_360 & V_361 ) )
V_166 -> V_229 |= V_362 ;
V_7 = F_110 ( V_4 , V_34 , V_166 , V_341 ) ;
F_52 ( & V_107 ) ;
F_61 () ;
return V_7 ;
}
static int F_218 ( struct V_1 * V_4 , struct V_33 * V_34 ,
T_1 V_157 , T_1 V_363 , struct V_140 * V_141 , int V_264 ,
int V_13 )
{
struct V_150 * V_151 ;
struct V_340 * V_341 ;
int V_7 ;
V_151 = F_219 ( V_34 , V_157 , V_363 , V_264 , sizeof( * V_341 ) , V_13 ) ;
if ( ! V_151 )
return - V_200 ;
V_341 = F_84 ( V_151 ) ;
V_341 -> V_364 = V_365 ;
V_341 -> V_366 = 32 ;
V_341 -> V_367 = 32 ;
V_341 -> V_368 = 0 ;
V_341 -> V_369 = V_4 -> V_3 ;
if ( F_211 ( V_34 , V_370 , V_4 -> V_3 ) )
goto V_371;
V_341 -> V_357 = V_358 ;
V_341 -> V_372 = V_373 ;
if ( V_141 -> V_229 & V_230 )
V_341 -> V_374 = V_375 ;
else
V_341 -> V_374 = V_376 ;
V_341 -> V_360 = 0 ;
if ( F_220 ( V_34 , V_377 , V_141 -> V_191 ) ||
F_220 ( V_34 , V_378 , V_141 -> V_192 ) )
goto V_371;
V_7 = F_110 ( V_4 , V_34 , V_141 , V_341 ) ;
if ( V_7 < 0 && V_7 != - V_225 )
goto V_371;
F_221 ( V_34 , V_151 ) ;
return 0 ;
V_371:
F_222 ( V_34 , V_151 ) ;
return - V_200 ;
}
static T_8 F_223 ( bool V_149 , int V_131 )
{
T_8 V_110 =
F_224 ( sizeof( struct V_340 ) )
+ F_225 ( 4 )
+ F_225 ( 4 )
+ F_225 ( 4 )
;
if ( ! V_149 )
V_110 = V_110
+ F_225 ( 4 )
+ F_225 ( 0 )
+ V_131 * F_226 ( sizeof( struct V_342 ) )
+ F_225 ( sizeof( struct V_345 ) )
;
return V_110 ;
}
static void F_91 ( struct V_1 * V_4 , struct V_140 * V_221 ,
int V_264 )
{
struct V_2 * V_2 = F_77 ( & V_4 -> V_2 ) ;
struct V_33 * V_34 ;
int V_7 = - V_174 ;
V_34 = F_227 ( F_223 ( V_221 -> V_196 >= V_169 , V_4 -> V_131 ) ,
V_197 ) ;
if ( ! V_34 )
goto V_379;
V_7 = F_218 ( V_4 , V_34 , 0 , 0 , V_221 , V_264 , 0 ) ;
if ( V_7 < 0 )
goto V_379;
F_228 ( V_34 , V_2 , 0 , V_380 , NULL , V_197 ) ;
return;
V_379:
F_49 ( V_34 ) ;
if ( V_7 < 0 )
F_229 ( V_2 , V_380 , V_7 ) ;
}
static int F_230 ( struct V_33 * V_34 , struct V_381 * V_382 )
{
struct V_2 * V_2 = F_148 ( V_34 -> V_231 ) ;
struct V_1 * V_4 ;
struct V_140 * V_221 ;
unsigned int V_383 = 0 , V_384 ;
unsigned int V_385 = 0 , V_386 ;
unsigned int V_145 = 0 , V_387 ;
V_384 = V_382 -> args [ 0 ] ;
V_386 = V_382 -> args [ 1 ] ;
V_387 = V_382 -> args [ 2 ] ;
F_59 () ;
F_2 (mrt, net) {
if ( V_383 < V_384 )
goto V_388;
if ( V_383 > V_384 )
V_386 = 0 ;
for ( V_385 = V_386 ; V_385 < V_54 ; V_385 ++ ) {
F_100 (mfc, &mrt->mfc_cache_array[h], list) {
if ( V_145 < V_387 )
goto V_389;
if ( F_218 ( V_4 , V_34 ,
F_86 ( V_382 -> V_34 ) . V_157 ,
V_382 -> V_151 -> V_390 ,
V_221 , V_218 ,
V_391 ) < 0 )
goto V_392;
V_389:
V_145 ++ ;
}
V_145 = V_387 = 0 ;
}
F_132 ( & V_160 ) ;
F_133 (mfc, &mrt->mfc_unres_queue, list) {
if ( V_145 < V_387 )
goto V_393;
if ( F_218 ( V_4 , V_34 ,
F_86 ( V_382 -> V_34 ) . V_157 ,
V_382 -> V_151 -> V_390 ,
V_221 , V_218 ,
V_391 ) < 0 ) {
F_135 ( & V_160 ) ;
goto V_392;
}
V_393:
V_145 ++ ;
}
F_135 ( & V_160 ) ;
V_145 = V_387 = 0 ;
V_386 = 0 ;
V_388:
V_383 ++ ;
}
V_392:
F_61 () ;
V_382 -> args [ 2 ] = V_145 ;
V_382 -> args [ 1 ] = V_385 ;
V_382 -> args [ 0 ] = V_383 ;
return V_34 -> V_110 ;
}
static struct V_130 * F_231 ( struct V_2 * V_2 ,
struct V_394 * V_395 ,
T_9 V_396 )
{
struct V_1 * V_4 = V_395 -> V_4 ;
for ( V_395 -> V_288 = 0 ; V_395 -> V_288 < V_4 -> V_131 ; ++ V_395 -> V_288 ) {
if ( ! F_65 ( V_4 , V_395 -> V_288 ) )
continue;
if ( V_396 -- == 0 )
return & V_4 -> V_133 [ V_395 -> V_288 ] ;
}
return NULL ;
}
static void * F_232 ( struct V_397 * V_363 , T_9 * V_396 )
__acquires( V_107 )
{
struct V_394 * V_395 = V_363 -> V_398 ;
struct V_2 * V_2 = F_233 ( V_363 ) ;
struct V_1 * V_4 ;
V_4 = F_1 ( V_2 , V_46 ) ;
if ( ! V_4 )
return F_195 ( - V_225 ) ;
V_395 -> V_4 = V_4 ;
F_50 ( & V_107 ) ;
return * V_396 ? F_231 ( V_2 , V_363 -> V_398 , * V_396 - 1 )
: V_399 ;
}
static void * F_234 ( struct V_397 * V_363 , void * V_63 , T_9 * V_396 )
{
struct V_394 * V_395 = V_363 -> V_398 ;
struct V_2 * V_2 = F_233 ( V_363 ) ;
struct V_1 * V_4 = V_395 -> V_4 ;
++ * V_396 ;
if ( V_63 == V_399 )
return F_231 ( V_2 , V_395 , 0 ) ;
while ( ++ V_395 -> V_288 < V_4 -> V_131 ) {
if ( ! F_65 ( V_4 , V_395 -> V_288 ) )
continue;
return & V_4 -> V_133 [ V_395 -> V_288 ] ;
}
return NULL ;
}
static void F_235 ( struct V_397 * V_363 , void * V_63 )
__releases( V_107 )
{
F_52 ( & V_107 ) ;
}
static int F_236 ( struct V_397 * V_363 , void * V_63 )
{
struct V_394 * V_395 = V_363 -> V_398 ;
struct V_1 * V_4 = V_395 -> V_4 ;
if ( V_63 == V_399 ) {
F_237 ( V_363 ,
L_6 ) ;
} else {
const struct V_130 * V_237 = V_63 ;
const char * V_80 = V_237 -> V_61 ? V_237 -> V_61 -> V_80 : L_7 ;
F_238 ( V_363 ,
L_8 ,
V_237 - V_4 -> V_133 ,
V_80 , V_237 -> V_184 , V_237 -> V_186 ,
V_237 -> V_185 , V_237 -> V_187 ,
V_237 -> V_13 , V_237 -> V_179 , V_237 -> V_180 ) ;
}
return 0 ;
}
static int F_239 ( struct V_400 * V_400 , struct V_401 * V_401 )
{
return F_240 ( V_400 , V_401 , & V_402 ,
sizeof( struct V_394 ) ) ;
}
static struct V_140 * F_241 ( struct V_2 * V_2 ,
struct V_403 * V_404 , T_9 V_396 )
{
struct V_1 * V_4 = V_404 -> V_4 ;
struct V_140 * V_221 ;
F_59 () ;
for ( V_404 -> V_288 = 0 ; V_404 -> V_288 < V_54 ; V_404 -> V_288 ++ ) {
V_404 -> V_166 = & V_4 -> V_55 [ V_404 -> V_288 ] ;
F_100 (mfc, it->cache, list)
if ( V_396 -- == 0 )
return V_221 ;
}
F_61 () ;
F_132 ( & V_160 ) ;
V_404 -> V_166 = & V_4 -> V_56 ;
F_133 (mfc, it->cache, list)
if ( V_396 -- == 0 )
return V_221 ;
F_135 ( & V_160 ) ;
V_404 -> V_166 = NULL ;
return NULL ;
}
static void * F_242 ( struct V_397 * V_363 , T_9 * V_396 )
{
struct V_403 * V_404 = V_363 -> V_398 ;
struct V_2 * V_2 = F_233 ( V_363 ) ;
struct V_1 * V_4 ;
V_4 = F_1 ( V_2 , V_46 ) ;
if ( ! V_4 )
return F_195 ( - V_225 ) ;
V_404 -> V_4 = V_4 ;
V_404 -> V_166 = NULL ;
V_404 -> V_288 = 0 ;
return * V_396 ? F_241 ( V_2 , V_363 -> V_398 , * V_396 - 1 )
: V_399 ;
}
static void * F_243 ( struct V_397 * V_363 , void * V_63 , T_9 * V_396 )
{
struct V_140 * V_221 = V_63 ;
struct V_403 * V_404 = V_363 -> V_398 ;
struct V_2 * V_2 = F_233 ( V_363 ) ;
struct V_1 * V_4 = V_404 -> V_4 ;
++ * V_396 ;
if ( V_63 == V_399 )
return F_241 ( V_2 , V_363 -> V_398 , 0 ) ;
if ( V_221 -> V_51 . V_50 != V_404 -> V_166 )
return F_244 ( V_221 -> V_51 . V_50 , struct V_140 , V_51 ) ;
if ( V_404 -> V_166 == & V_4 -> V_56 )
goto V_405;
F_245 ( V_404 -> V_166 != & V_4 -> V_55 [ V_404 -> V_288 ] ) ;
while ( ++ V_404 -> V_288 < V_54 ) {
V_404 -> V_166 = & V_4 -> V_55 [ V_404 -> V_288 ] ;
if ( F_89 ( V_404 -> V_166 ) )
continue;
return F_246 ( V_404 -> V_166 , struct V_140 , V_51 ) ;
}
F_61 () ;
V_404 -> V_166 = & V_4 -> V_56 ;
V_404 -> V_288 = 0 ;
F_132 ( & V_160 ) ;
if ( ! F_89 ( V_404 -> V_166 ) )
return F_246 ( V_404 -> V_166 , struct V_140 , V_51 ) ;
V_405:
F_135 ( & V_160 ) ;
V_404 -> V_166 = NULL ;
return NULL ;
}
static void F_247 ( struct V_397 * V_363 , void * V_63 )
{
struct V_403 * V_404 = V_363 -> V_398 ;
struct V_1 * V_4 = V_404 -> V_4 ;
if ( V_404 -> V_166 == & V_4 -> V_56 )
F_135 ( & V_160 ) ;
else if ( V_404 -> V_166 == & V_4 -> V_55 [ V_404 -> V_288 ] )
F_61 () ;
}
static int F_248 ( struct V_397 * V_363 , void * V_63 )
{
int V_406 ;
if ( V_63 == V_399 ) {
F_237 ( V_363 ,
L_9 ) ;
} else {
const struct V_140 * V_221 = V_63 ;
const struct V_403 * V_404 = V_363 -> V_398 ;
const struct V_1 * V_4 = V_404 -> V_4 ;
F_238 ( V_363 , L_10 ,
( V_84 T_1 ) V_221 -> V_192 ,
( V_84 T_1 ) V_221 -> V_191 ,
V_221 -> V_196 ) ;
if ( V_404 -> V_166 != & V_4 -> V_56 ) {
F_238 ( V_363 , L_11 ,
V_221 -> V_147 . V_9 . V_201 ,
V_221 -> V_147 . V_9 . V_279 ,
V_221 -> V_147 . V_9 . V_280 ) ;
for ( V_406 = V_221 -> V_147 . V_9 . V_168 ;
V_406 < V_221 -> V_147 . V_9 . V_131 ; V_406 ++ ) {
if ( F_65 ( V_4 , V_406 ) &&
V_221 -> V_147 . V_9 . V_167 [ V_406 ] < 255 )
F_238 ( V_363 ,
L_12 ,
V_406 , V_221 -> V_147 . V_9 . V_167 [ V_406 ] ) ;
}
} else {
F_238 ( V_363 , L_11 , 0ul , 0ul , 0ul ) ;
}
F_249 ( V_363 , '\n' ) ;
}
return 0 ;
}
static int F_250 ( struct V_400 * V_400 , struct V_401 * V_401 )
{
return F_240 ( V_400 , V_401 , & V_407 ,
sizeof( struct V_403 ) ) ;
}
static int T_2 F_251 ( struct V_2 * V_2 )
{
int V_7 ;
V_7 = F_11 ( V_2 ) ;
if ( V_7 < 0 )
goto V_408;
#ifdef F_252
V_7 = - V_47 ;
if ( ! F_253 ( L_13 , 0 , V_2 -> V_409 , & V_410 ) )
goto V_411;
if ( ! F_253 ( L_14 , 0 , V_2 -> V_409 , & V_412 ) )
goto V_413;
#endif
return 0 ;
#ifdef F_252
V_413:
F_254 ( L_13 , V_2 -> V_409 ) ;
V_411:
F_20 ( V_2 ) ;
#endif
V_408:
return V_7 ;
}
static void T_3 F_255 ( struct V_2 * V_2 )
{
#ifdef F_252
F_254 ( L_14 , V_2 -> V_409 ) ;
F_254 ( L_13 , V_2 -> V_409 ) ;
#endif
F_20 ( V_2 ) ;
}
int T_10 F_256 ( void )
{
int V_7 ;
V_143 = F_257 ( L_15 ,
sizeof( struct V_140 ) ,
0 , V_414 | V_415 ,
NULL ) ;
if ( ! V_143 )
return - V_47 ;
V_7 = F_258 ( & V_416 ) ;
if ( V_7 )
goto V_417;
V_7 = F_259 ( & V_418 ) ;
if ( V_7 )
goto V_419;
#ifdef F_260
if ( F_261 ( & V_420 , V_421 ) < 0 ) {
F_262 ( L_16 , V_422 ) ;
V_7 = - V_31 ;
goto V_423;
}
#endif
F_263 ( V_365 , V_424 ,
NULL , F_230 , NULL ) ;
return 0 ;
#ifdef F_260
V_423:
F_264 ( & V_418 ) ;
#endif
V_419:
F_265 ( & V_416 ) ;
V_417:
F_266 ( V_143 ) ;
return V_7 ;
}
