static inline T_1 F_1 ( T_2 V_1 )
{
return ( ( V_1 >> 8 ) | V_1 ) % V_2 ;
}
static struct V_3 *
F_2 ( T_2 V_1 )
{
struct V_4 * V_5 ;
struct V_6 * V_7 ;
struct V_3 * V_8 ;
V_5 = & V_9 [ F_1 ( V_1 ) ] ;
F_3 (inst, pos, head, hlist) {
if ( V_8 -> V_1 == V_1 )
return V_8 ;
}
return NULL ;
}
static struct V_3 *
F_4 ( T_2 V_1 , int V_10 )
{
struct V_3 * V_8 ;
unsigned int V_11 ;
int V_12 ;
F_5 ( & V_13 ) ;
if ( F_2 ( V_1 ) ) {
V_12 = - V_14 ;
goto V_15;
}
V_8 = F_6 ( sizeof( * V_8 ) , V_16 ) ;
if ( ! V_8 ) {
V_12 = - V_17 ;
goto V_15;
}
V_8 -> V_1 = V_1 ;
V_8 -> V_18 = V_10 ;
V_8 -> V_19 = V_20 ;
V_8 -> V_21 = 0xfffff ;
V_8 -> V_22 = V_23 ;
F_7 ( & V_8 -> V_24 ) ;
F_8 ( & V_8 -> V_25 ) ;
if ( ! F_9 ( V_26 ) ) {
V_12 = - V_27 ;
goto V_28;
}
V_11 = F_1 ( V_1 ) ;
F_10 ( & V_8 -> V_29 , & V_9 [ V_11 ] ) ;
F_11 ( & V_13 ) ;
return V_8 ;
V_28:
F_12 ( V_8 ) ;
V_15:
F_11 ( & V_13 ) ;
return F_13 ( V_12 ) ;
}
static void
F_14 ( struct V_30 * V_5 )
{
struct V_3 * V_8 = F_15 ( V_5 , struct V_3 ,
V_31 ) ;
F_16 ( V_8 , NULL , 0 ) ;
F_12 ( V_8 ) ;
F_17 ( V_26 ) ;
}
static void
F_18 ( struct V_3 * V_8 )
{
F_19 ( & V_8 -> V_29 ) ;
F_20 ( & V_8 -> V_31 , F_14 ) ;
}
static void
F_21 ( struct V_3 * V_8 )
{
F_5 ( & V_13 ) ;
F_18 ( V_8 ) ;
F_11 ( & V_13 ) ;
}
static inline void
F_22 ( struct V_3 * V_32 , struct V_33 * V_34 )
{
F_23 ( & V_34 -> V_35 , & V_32 -> V_25 ) ;
V_32 -> V_36 ++ ;
}
static void
F_24 ( struct V_3 * V_32 , struct V_33 * V_34 )
{
F_25 ( & V_34 -> V_35 ) ;
V_32 -> V_36 -- ;
}
static struct V_33 *
F_26 ( struct V_3 * V_32 , unsigned int V_37 )
{
struct V_33 * V_34 = NULL , * V_38 ;
F_27 ( & V_32 -> V_24 ) ;
F_28 (i, &queue->queue_list, list) {
if ( V_38 -> V_37 == V_37 ) {
V_34 = V_38 ;
break;
}
}
if ( V_34 )
F_24 ( V_32 , V_34 ) ;
F_29 ( & V_32 -> V_24 ) ;
return V_34 ;
}
static void
F_16 ( struct V_3 * V_32 , T_3 V_39 , unsigned long V_40 )
{
struct V_33 * V_34 , * V_41 ;
F_27 ( & V_32 -> V_24 ) ;
F_30 (entry, next, &queue->queue_list, list) {
if ( ! V_39 || V_39 ( V_34 , V_40 ) ) {
F_25 ( & V_34 -> V_35 ) ;
V_32 -> V_36 -- ;
F_31 ( V_34 , V_42 ) ;
}
}
F_29 ( & V_32 -> V_24 ) ;
}
static struct V_43 *
F_32 ( struct V_3 * V_32 ,
struct V_33 * V_34 ,
T_4 * * V_44 )
{
T_5 V_45 ;
T_6 V_46 ;
T_6 V_47 = 0 , V_48 = 0 ;
struct V_43 * V_49 ;
struct V_50 * V_51 ;
struct V_52 * V_53 ;
struct V_54 * V_55 ;
struct V_56 * V_57 ;
struct V_43 * V_58 = V_34 -> V_49 ;
struct V_59 * V_60 ;
struct V_59 * V_61 ;
struct V_62 * V_63 = NULL ;
enum V_64 V_65 ( V_66 ) ;
V_46 = F_33 ( sizeof( struct V_56 ) )
+ F_34 ( sizeof( struct V_52 ) )
+ F_34 ( sizeof( V_67 ) )
+ F_34 ( sizeof( V_67 ) )
#ifdef F_35
+ F_34 ( sizeof( V_67 ) )
+ F_34 ( sizeof( V_67 ) )
#endif
+ F_34 ( sizeof( V_67 ) )
+ F_34 ( sizeof( struct V_68 ) )
+ F_34 ( sizeof( struct V_69 )
+ F_34 ( sizeof( V_67 ) ) ) ;
V_61 = V_34 -> V_61 ;
switch ( (enum V_70 ) F_36 ( V_32 -> V_22 ) ) {
case V_71 :
case V_23 :
break;
case V_72 :
if ( V_58 -> V_73 == V_74 &&
F_37 ( V_58 ) )
return NULL ;
V_47 = F_36 ( V_32 -> V_21 ) ;
if ( V_47 == 0 || V_47 > V_58 -> V_75 )
V_47 = V_58 -> V_75 ;
V_46 += F_34 ( V_47 ) ;
V_48 = V_58 -> V_75 ;
break;
}
if ( V_32 -> V_76 & V_77 )
V_63 = F_38 ( V_58 , & V_46 , & V_66 ) ;
V_49 = F_39 ( V_46 , V_16 ) ;
if ( ! V_49 )
return NULL ;
V_45 = V_49 -> V_78 ;
V_55 = F_40 ( V_49 , 0 , 0 ,
V_79 << 8 | V_80 ,
sizeof( struct V_56 ) , 0 ) ;
if ( ! V_55 ) {
F_41 ( V_49 ) ;
return NULL ;
}
V_57 = F_42 ( V_55 ) ;
V_57 -> V_81 = V_34 -> V_82 ;
V_57 -> V_83 = V_84 ;
V_57 -> V_85 = F_43 ( V_32 -> V_1 ) ;
V_51 = F_44 ( V_49 , V_86 , sizeof( * V_53 ) ) ;
V_53 = F_45 ( V_51 ) ;
V_53 -> V_87 = V_58 -> V_88 ;
V_53 -> V_89 = V_34 -> V_89 ;
* V_44 = & V_53 -> V_90 ;
V_60 = V_34 -> V_60 ;
if ( V_60 ) {
#ifndef F_35
if ( F_46 ( V_49 , V_91 , F_47 ( V_60 -> V_92 ) ) )
goto V_93;
#else
if ( V_34 -> V_82 == V_94 ) {
if ( F_46 ( V_49 , V_95 ,
F_47 ( V_60 -> V_92 ) ) ||
F_46 ( V_49 , V_91 ,
F_47 ( F_48 ( V_60 ) -> V_96 -> V_97 -> V_92 ) ) )
goto V_93;
} else {
if ( F_46 ( V_49 , V_91 ,
F_47 ( V_60 -> V_92 ) ) )
goto V_93;
if ( V_58 -> V_98 && V_58 -> V_98 -> V_99 &&
F_46 ( V_49 , V_95 ,
F_47 ( V_58 -> V_98 -> V_99 -> V_92 ) ) )
goto V_93;
}
#endif
}
if ( V_61 ) {
#ifndef F_35
if ( F_46 ( V_49 , V_100 , F_47 ( V_61 -> V_92 ) ) )
goto V_93;
#else
if ( V_34 -> V_82 == V_94 ) {
if ( F_46 ( V_49 , V_101 ,
F_47 ( V_61 -> V_92 ) ) ||
F_46 ( V_49 , V_100 ,
F_47 ( F_48 ( V_61 ) -> V_96 -> V_97 -> V_92 ) ) )
goto V_93;
} else {
if ( F_46 ( V_49 , V_100 ,
F_47 ( V_61 -> V_92 ) ) )
goto V_93;
if ( V_58 -> V_98 && V_58 -> V_98 -> V_102 &&
F_46 ( V_49 , V_101 ,
F_47 ( V_58 -> V_98 -> V_102 -> V_92 ) ) )
goto V_93;
}
#endif
}
if ( V_58 -> V_103 &&
F_46 ( V_49 , V_104 , F_47 ( V_58 -> V_103 ) ) )
goto V_93;
if ( V_60 && V_58 -> V_97 &&
V_58 -> V_105 != V_58 -> V_106 ) {
struct V_68 V_107 ;
int V_75 = F_49 ( V_58 , V_107 . V_108 ) ;
if ( V_75 ) {
V_107 . V_109 = F_43 ( V_75 ) ;
if ( F_50 ( V_49 , V_110 , sizeof( V_107 ) , & V_107 ) )
goto V_93;
}
}
if ( V_58 -> V_111 . V_112 ) {
struct V_69 V_113 ;
struct V_114 V_115 = F_51 ( V_58 -> V_111 ) ;
V_113 . V_116 = F_52 ( V_115 . V_117 ) ;
V_113 . V_118 = F_52 ( V_115 . V_119 ) ;
if ( F_50 ( V_49 , V_120 , sizeof( V_113 ) , & V_113 ) )
goto V_93;
}
if ( V_47 ) {
struct V_50 * V_51 ;
int V_121 = F_53 ( V_47 ) ;
if ( F_54 ( V_49 ) < F_34 ( V_47 ) ) {
F_55 ( V_122 L_1 ) ;
F_41 ( V_49 ) ;
return NULL ;
}
V_51 = (struct V_50 * ) F_56 ( V_49 , F_34 ( V_47 ) ) ;
V_51 -> V_123 = V_124 ;
V_51 -> V_125 = V_121 ;
if ( F_57 ( V_58 , 0 , F_45 ( V_51 ) , V_47 ) )
F_58 () ;
}
if ( V_63 && F_59 ( V_49 , V_63 , V_66 ) < 0 )
goto V_93;
if ( V_48 > 0 && F_46 ( V_49 , V_126 , F_47 ( V_48 ) ) )
goto V_93;
V_55 -> V_127 = V_49 -> V_78 - V_45 ;
return V_49 ;
V_93:
F_41 ( V_49 ) ;
F_60 ( L_2 ) ;
return NULL ;
}
static int
F_61 ( struct V_33 * V_34 , unsigned int V_128 )
{
struct V_43 * V_129 ;
struct V_3 * V_32 ;
int V_12 = - V_130 ;
T_4 * V_44 ;
int V_131 = 0 ;
V_32 = F_2 ( V_128 ) ;
if ( ! V_32 ) {
V_12 = - V_132 ;
goto V_133;
}
if ( V_32 -> V_22 == V_23 ) {
V_12 = - V_134 ;
goto V_133;
}
V_129 = F_32 ( V_32 , V_34 , & V_44 ) ;
if ( V_129 == NULL ) {
V_12 = - V_17 ;
goto V_133;
}
F_27 ( & V_32 -> V_24 ) ;
if ( ! V_32 -> V_18 ) {
V_12 = - V_134 ;
goto V_135;
}
if ( V_32 -> V_36 >= V_32 -> V_19 ) {
if ( V_32 -> V_76 & V_136 ) {
V_131 = 1 ;
V_12 = 0 ;
} else {
V_32 -> V_137 ++ ;
F_62 ( L_3 ,
V_32 -> V_36 ) ;
}
goto V_135;
}
V_34 -> V_37 = ++ V_32 -> V_138 ;
* V_44 = F_47 ( V_34 -> V_37 ) ;
V_12 = F_63 ( V_129 , & V_139 , V_32 -> V_18 , V_140 ) ;
if ( V_12 < 0 ) {
V_32 -> V_141 ++ ;
goto V_142;
}
F_22 ( V_32 , V_34 ) ;
F_29 ( & V_32 -> V_24 ) ;
return 0 ;
V_135:
F_41 ( V_129 ) ;
V_142:
F_29 ( & V_32 -> V_24 ) ;
if ( V_131 )
F_31 ( V_34 , V_143 ) ;
V_133:
return V_12 ;
}
static int
F_64 ( void * V_40 , int V_47 , struct V_33 * V_144 , int V_145 )
{
struct V_43 * V_129 ;
if ( V_145 < 0 ) {
if ( F_65 ( V_144 -> V_49 , V_47 ) )
return - V_17 ;
} else if ( V_145 > 0 ) {
if ( V_47 > 0xFFFF )
return - V_134 ;
if ( V_145 > F_54 ( V_144 -> V_49 ) ) {
V_129 = F_66 ( V_144 -> V_49 , F_67 ( V_144 -> V_49 ) ,
V_145 , V_16 ) ;
if ( ! V_129 ) {
F_55 ( V_122 L_4
L_5 ) ;
return - V_17 ;
}
F_41 ( V_144 -> V_49 ) ;
V_144 -> V_49 = V_129 ;
}
F_56 ( V_144 -> V_49 , V_145 ) ;
}
if ( ! F_68 ( V_144 -> V_49 , V_47 ) )
return - V_17 ;
F_69 ( V_144 -> V_49 , V_40 , V_47 ) ;
V_144 -> V_49 -> V_73 = V_146 ;
return 0 ;
}
static int
F_70 ( struct V_3 * V_32 ,
unsigned char V_147 , unsigned int V_148 )
{
int V_149 = 0 ;
F_27 ( & V_32 -> V_24 ) ;
switch ( V_147 ) {
case V_23 :
case V_71 :
V_32 -> V_22 = V_147 ;
V_32 -> V_21 = 0 ;
break;
case V_72 :
V_32 -> V_22 = V_147 ;
if ( V_148 > 0xffff - V_150 )
V_32 -> V_21 = 0xffff - V_150 ;
else
V_32 -> V_21 = V_148 ;
break;
default:
V_149 = - V_134 ;
}
F_29 ( & V_32 -> V_24 ) ;
return V_149 ;
}
static int
F_71 ( struct V_33 * V_34 , unsigned long V_92 )
{
if ( V_34 -> V_60 )
if ( V_34 -> V_60 -> V_92 == V_92 )
return 1 ;
if ( V_34 -> V_61 )
if ( V_34 -> V_61 -> V_92 == V_92 )
return 1 ;
#ifdef F_35
if ( V_34 -> V_49 -> V_98 ) {
if ( V_34 -> V_49 -> V_98 -> V_99 &&
V_34 -> V_49 -> V_98 -> V_99 -> V_92 == V_92 )
return 1 ;
if ( V_34 -> V_49 -> V_98 -> V_102 &&
V_34 -> V_49 -> V_98 -> V_102 -> V_92 == V_92 )
return 1 ;
}
#endif
return 0 ;
}
static void
F_72 ( int V_92 )
{
int V_38 ;
F_73 () ;
for ( V_38 = 0 ; V_38 < V_2 ; V_38 ++ ) {
struct V_6 * V_151 ;
struct V_3 * V_8 ;
struct V_4 * V_5 = & V_9 [ V_38 ] ;
F_3 (inst, tmp, head, hlist)
F_16 ( V_8 , F_71 , V_92 ) ;
}
F_74 () ;
}
static int
F_75 ( struct V_152 * V_153 ,
unsigned long V_154 , void * V_155 )
{
struct V_59 * V_97 = V_155 ;
if ( ! F_76 ( F_77 ( V_97 ) , & V_139 ) )
return V_156 ;
if ( V_154 == V_157 )
F_72 ( V_97 -> V_92 ) ;
return V_156 ;
}
static int
F_78 ( struct V_152 * V_153 ,
unsigned long V_154 , void * V_155 )
{
struct V_158 * V_159 = V_155 ;
if ( V_154 == V_160 && V_159 -> V_88 == V_161 ) {
int V_38 ;
F_5 ( & V_13 ) ;
for ( V_38 = 0 ; V_38 < V_2 ; V_38 ++ ) {
struct V_6 * V_151 , * V_162 ;
struct V_3 * V_8 ;
struct V_4 * V_5 = & V_9 [ V_38 ] ;
F_79 (inst, tmp, t2, head, hlist) {
if ( ( V_159 -> V_163 == & V_139 ) &&
( V_159 -> V_10 == V_8 -> V_18 ) )
F_18 ( V_8 ) ;
}
}
F_11 ( & V_13 ) ;
}
return V_156 ;
}
static struct V_3 * F_80 ( T_7 V_1 , int V_164 )
{
struct V_3 * V_32 ;
V_32 = F_2 ( V_1 ) ;
if ( ! V_32 )
return F_13 ( - V_165 ) ;
if ( V_32 -> V_18 != V_164 )
return F_13 ( - V_166 ) ;
return V_32 ;
}
static struct V_167 *
F_81 ( const struct V_50 * const V_168 [] )
{
struct V_167 * V_169 ;
unsigned int V_170 ;
if ( ! V_168 [ V_171 ] )
return NULL ;
V_169 = F_45 ( V_168 [ V_171 ] ) ;
V_170 = F_82 ( V_169 -> V_170 ) & V_172 ;
if ( V_170 > V_173 || V_170 == V_174 )
return NULL ;
return V_169 ;
}
static int F_83 ( unsigned int V_37 , unsigned int V_175 )
{
return ( int ) ( V_37 - V_175 ) > 0 ;
}
static int
F_84 ( struct V_176 * V_177 , struct V_43 * V_49 ,
const struct V_54 * V_55 ,
const struct V_50 * const V_168 [] )
{
struct V_56 * V_57 = F_42 ( V_55 ) ;
struct V_33 * V_34 , * V_151 ;
unsigned int V_170 , V_178 ;
struct V_167 * V_169 ;
struct V_3 * V_32 ;
F_85 ( V_179 ) ;
T_7 V_1 = F_86 ( V_57 -> V_85 ) ;
V_32 = F_80 ( V_1 , F_87 ( V_49 ) . V_10 ) ;
if ( F_88 ( V_32 ) )
return F_89 ( V_32 ) ;
V_169 = F_81 ( V_168 ) ;
if ( ! V_169 )
return - V_134 ;
V_170 = F_82 ( V_169 -> V_170 ) ;
V_178 = F_82 ( V_169 -> V_37 ) ;
F_27 ( & V_32 -> V_24 ) ;
F_30 (entry, tmp, &queue->queue_list, list) {
if ( F_83 ( V_34 -> V_37 , V_178 ) )
break;
F_24 ( V_32 , V_34 ) ;
F_23 ( & V_34 -> V_35 , & V_179 ) ;
}
F_29 ( & V_32 -> V_24 ) ;
if ( F_90 ( & V_179 ) )
return - V_180 ;
F_30 (entry, tmp, &batch_list, list) {
if ( V_168 [ V_104 ] )
V_34 -> V_49 -> V_103 = F_82 ( F_91 ( V_168 [ V_104 ] ) ) ;
F_31 ( V_34 , V_170 ) ;
}
return 0 ;
}
static int
F_92 ( struct V_176 * V_177 , struct V_43 * V_49 ,
const struct V_54 * V_55 ,
const struct V_50 * const V_168 [] )
{
struct V_56 * V_57 = F_42 ( V_55 ) ;
T_2 V_1 = F_86 ( V_57 -> V_85 ) ;
struct V_167 * V_169 ;
struct V_3 * V_32 ;
unsigned int V_170 ;
struct V_33 * V_34 ;
enum V_64 V_65 ( V_66 ) ;
struct V_62 * V_63 = NULL ;
V_32 = F_2 ( V_1 ) ;
if ( ! V_32 )
V_32 = F_80 ( V_1 , F_87 ( V_49 ) . V_10 ) ;
if ( F_88 ( V_32 ) )
return F_89 ( V_32 ) ;
V_169 = F_81 ( V_168 ) ;
if ( ! V_169 )
return - V_134 ;
V_170 = F_82 ( V_169 -> V_170 ) ;
V_34 = F_26 ( V_32 , F_82 ( V_169 -> V_37 ) ) ;
if ( V_34 == NULL )
return - V_180 ;
F_73 () ;
if ( V_168 [ V_181 ] && ( V_32 -> V_76 & V_77 ) )
V_63 = F_93 ( V_34 -> V_49 , V_168 [ V_181 ] , & V_66 ) ;
if ( V_168 [ V_124 ] ) {
T_7 V_182 = V_125 ( V_168 [ V_124 ] ) ;
int V_145 = V_182 - V_34 -> V_49 -> V_75 ;
if ( F_64 ( F_45 ( V_168 [ V_124 ] ) ,
V_182 , V_34 , V_145 ) < 0 )
V_170 = V_42 ;
if ( V_63 )
F_94 ( V_49 , V_63 , V_66 , V_145 ) ;
}
F_74 () ;
if ( V_168 [ V_104 ] )
V_34 -> V_49 -> V_103 = F_82 ( F_91 ( V_168 [ V_104 ] ) ) ;
F_31 ( V_34 , V_170 ) ;
return 0 ;
}
static int
F_95 ( struct V_176 * V_177 , struct V_43 * V_49 ,
const struct V_54 * V_55 ,
const struct V_50 * const V_168 [] )
{
return - V_183 ;
}
static int
F_96 ( struct V_176 * V_177 , struct V_43 * V_49 ,
const struct V_54 * V_55 ,
const struct V_50 * const V_168 [] )
{
struct V_56 * V_57 = F_42 ( V_55 ) ;
T_2 V_1 = F_86 ( V_57 -> V_85 ) ;
struct V_3 * V_32 ;
struct V_184 * V_185 = NULL ;
int V_186 = 0 ;
if ( V_168 [ V_187 ] ) {
V_185 = F_45 ( V_168 [ V_187 ] ) ;
switch ( V_185 -> V_188 ) {
case V_189 : return 0 ;
case V_190 : return 0 ;
}
}
F_73 () ;
V_32 = F_2 ( V_1 ) ;
if ( V_32 && V_32 -> V_18 != F_87 ( V_49 ) . V_10 ) {
V_186 = - V_166 ;
goto V_142;
}
if ( V_185 != NULL ) {
switch ( V_185 -> V_188 ) {
case V_191 :
if ( V_32 ) {
V_186 = - V_192 ;
goto V_142;
}
V_32 = F_4 ( V_1 , F_87 ( V_49 ) . V_10 ) ;
if ( F_88 ( V_32 ) ) {
V_186 = F_89 ( V_32 ) ;
goto V_142;
}
break;
case V_193 :
if ( ! V_32 ) {
V_186 = - V_165 ;
goto V_142;
}
F_21 ( V_32 ) ;
break;
case V_189 :
case V_190 :
break;
default:
V_186 = - V_183 ;
break;
}
}
if ( V_168 [ V_194 ] ) {
struct V_195 * V_196 ;
if ( ! V_32 ) {
V_186 = - V_165 ;
goto V_142;
}
V_196 = F_45 ( V_168 [ V_194 ] ) ;
F_70 ( V_32 , V_196 -> V_22 ,
F_82 ( V_196 -> V_21 ) ) ;
}
if ( V_168 [ V_197 ] ) {
T_4 * V_19 ;
if ( ! V_32 ) {
V_186 = - V_165 ;
goto V_142;
}
V_19 = F_45 ( V_168 [ V_197 ] ) ;
F_27 ( & V_32 -> V_24 ) ;
V_32 -> V_19 = F_82 ( * V_19 ) ;
F_29 ( & V_32 -> V_24 ) ;
}
if ( V_168 [ V_198 ] ) {
T_8 V_76 , V_199 ;
if ( ! V_32 ) {
V_186 = - V_165 ;
goto V_142;
}
if ( ! V_168 [ V_200 ] ) {
V_186 = - V_134 ;
goto V_142;
}
V_76 = F_82 ( F_91 ( V_168 [ V_198 ] ) ) ;
V_199 = F_82 ( F_91 ( V_168 [ V_200 ] ) ) ;
if ( V_76 >= V_201 ) {
V_186 = - V_202 ;
goto V_142;
}
F_27 ( & V_32 -> V_24 ) ;
V_32 -> V_76 &= ~ V_199 ;
V_32 -> V_76 |= V_76 & V_199 ;
F_29 ( & V_32 -> V_24 ) ;
}
V_142:
F_74 () ;
return V_186 ;
}
static struct V_6 * F_97 ( struct V_203 * V_204 )
{
struct V_205 * V_206 = V_204 -> V_207 ;
if ( ! V_206 )
return NULL ;
for ( V_206 -> V_208 = 0 ; V_206 -> V_208 < V_2 ; V_206 -> V_208 ++ ) {
if ( ! F_98 ( & V_9 [ V_206 -> V_208 ] ) )
return V_9 [ V_206 -> V_208 ] . V_209 ;
}
return NULL ;
}
static struct V_6 * F_99 ( struct V_203 * V_204 , struct V_6 * V_11 )
{
struct V_205 * V_206 = V_204 -> V_207 ;
V_11 = V_11 -> V_41 ;
while ( ! V_11 ) {
if ( ++ V_206 -> V_208 >= V_2 )
return NULL ;
V_11 = V_9 [ V_206 -> V_208 ] . V_209 ;
}
return V_11 ;
}
static struct V_6 * F_100 ( struct V_203 * V_204 , T_9 V_7 )
{
struct V_6 * V_5 ;
V_5 = F_97 ( V_204 ) ;
if ( V_5 )
while ( V_7 && ( V_5 = F_99 ( V_204 , V_5 ) ) )
V_7 -- ;
return V_7 ? NULL : V_5 ;
}
static void * F_101 ( struct V_203 * V_204 , T_9 * V_7 )
__acquires( V_13 )
{
F_5 ( & V_13 ) ;
return F_100 ( V_204 , * V_7 ) ;
}
static void * F_102 ( struct V_203 * V_210 , void * V_211 , T_9 * V_7 )
{
( * V_7 ) ++ ;
return F_99 ( V_210 , V_211 ) ;
}
static void F_103 ( struct V_203 * V_210 , void * V_211 )
__releases( V_13 )
{
F_11 ( & V_13 ) ;
}
static int F_104 ( struct V_203 * V_210 , void * V_211 )
{
const struct V_3 * V_8 = V_211 ;
return F_105 ( V_210 , L_6 ,
V_8 -> V_1 ,
V_8 -> V_18 , V_8 -> V_36 ,
V_8 -> V_22 , V_8 -> V_21 ,
V_8 -> V_137 , V_8 -> V_141 ,
V_8 -> V_138 , 1 ) ;
}
static int F_106 ( struct V_212 * V_212 , struct V_213 * V_213 )
{
return F_107 ( V_213 , & V_214 ,
sizeof( struct V_205 ) ) ;
}
static int T_10 F_108 ( void )
{
int V_38 , V_149 = - V_17 ;
for ( V_38 = 0 ; V_38 < V_2 ; V_38 ++ )
F_109 ( & V_9 [ V_38 ] ) ;
F_110 ( & V_215 ) ;
V_149 = F_111 ( & V_216 ) ;
if ( V_149 < 0 ) {
F_55 ( V_217 L_7 ) ;
goto V_218;
}
#ifdef F_112
if ( ! F_113 ( L_8 , 0440 ,
V_219 , & V_220 ) )
goto V_221;
#endif
F_114 ( & V_222 ) ;
F_115 ( & V_223 ) ;
return V_149 ;
#ifdef F_112
V_221:
F_116 ( & V_216 ) ;
#endif
V_218:
F_117 ( & V_215 ) ;
return V_149 ;
}
static void T_11 F_118 ( void )
{
F_119 () ;
F_120 ( & V_222 ) ;
#ifdef F_112
F_121 ( L_8 , V_219 ) ;
#endif
F_116 ( & V_216 ) ;
F_117 ( & V_215 ) ;
F_122 () ;
}
