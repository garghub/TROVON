static struct V_1 * F_1 ( struct V_2 * V_2 )
{
return F_2 ( V_2 , V_3 ) ;
}
static inline T_1 F_3 ( T_2 V_4 )
{
return ( ( V_4 >> 8 ) ^ V_4 ) % V_5 ;
}
static struct V_6 *
F_4 ( struct V_1 * V_7 , T_2 V_4 )
{
struct V_8 * V_9 ;
struct V_6 * V_10 ;
V_9 = & V_7 -> V_11 [ F_3 ( V_4 ) ] ;
F_5 (inst, head, hlist) {
if ( V_10 -> V_4 == V_4 )
return V_10 ;
}
return NULL ;
}
static struct V_6 *
F_6 ( struct V_1 * V_7 , T_2 V_4 , T_3 V_12 )
{
struct V_6 * V_10 ;
unsigned int V_13 ;
int V_14 ;
F_7 ( & V_7 -> V_15 ) ;
if ( F_4 ( V_7 , V_4 ) ) {
V_14 = - V_16 ;
goto V_17;
}
V_10 = F_8 ( sizeof( * V_10 ) , V_18 ) ;
if ( ! V_10 ) {
V_14 = - V_19 ;
goto V_17;
}
V_10 -> V_4 = V_4 ;
V_10 -> V_20 = V_12 ;
V_10 -> V_21 = V_22 ;
V_10 -> V_23 = V_24 ;
V_10 -> V_25 = V_26 ;
F_9 ( & V_10 -> V_27 ) ;
F_10 ( & V_10 -> V_28 ) ;
if ( ! F_11 ( V_29 ) ) {
V_14 = - V_30 ;
goto V_31;
}
V_13 = F_3 ( V_4 ) ;
F_12 ( & V_10 -> V_32 , & V_7 -> V_11 [ V_13 ] ) ;
F_13 ( & V_7 -> V_15 ) ;
return V_10 ;
V_31:
F_14 ( V_10 ) ;
V_17:
F_13 ( & V_7 -> V_15 ) ;
return F_15 ( V_14 ) ;
}
static void
F_16 ( struct V_33 * V_9 )
{
struct V_6 * V_10 = F_17 ( V_9 , struct V_6 ,
V_34 ) ;
F_18 ( V_10 , NULL , 0 ) ;
F_14 ( V_10 ) ;
F_19 ( V_29 ) ;
}
static void
F_20 ( struct V_6 * V_10 )
{
F_21 ( & V_10 -> V_32 ) ;
F_22 ( & V_10 -> V_34 , F_16 ) ;
}
static void
F_23 ( struct V_1 * V_7 , struct V_6 * V_10 )
{
F_7 ( & V_7 -> V_15 ) ;
F_20 ( V_10 ) ;
F_13 ( & V_7 -> V_15 ) ;
}
static inline void
F_24 ( struct V_6 * V_35 , struct V_36 * V_37 )
{
F_25 ( & V_37 -> V_38 , & V_35 -> V_28 ) ;
V_35 -> V_39 ++ ;
}
static void
F_26 ( struct V_6 * V_35 , struct V_36 * V_37 )
{
F_27 ( & V_37 -> V_38 ) ;
V_35 -> V_39 -- ;
}
static struct V_36 *
F_28 ( struct V_6 * V_35 , unsigned int V_40 )
{
struct V_36 * V_37 = NULL , * V_41 ;
F_29 ( & V_35 -> V_27 ) ;
F_30 (i, &queue->queue_list, list) {
if ( V_41 -> V_40 == V_40 ) {
V_37 = V_41 ;
break;
}
}
if ( V_37 )
F_26 ( V_35 , V_37 ) ;
F_31 ( & V_35 -> V_27 ) ;
return V_37 ;
}
static void
F_18 ( struct V_6 * V_35 , T_4 V_42 , unsigned long V_43 )
{
struct V_36 * V_37 , * V_44 ;
F_29 ( & V_35 -> V_27 ) ;
F_32 (entry, next, &queue->queue_list, list) {
if ( ! V_42 || V_42 ( V_37 , V_43 ) ) {
F_27 ( & V_37 -> V_38 ) ;
V_35 -> V_39 -- ;
F_33 ( V_37 , V_45 ) ;
}
}
F_31 ( & V_35 -> V_27 ) ;
}
static int
F_34 ( struct V_46 * V_47 , struct V_46 * V_48 ,
bool V_49 )
{
T_5 V_50 = 0 ;
if ( V_48 -> V_51 == V_52 )
V_50 = V_53 ;
else if ( V_49 )
V_50 = V_54 ;
if ( F_35 ( V_48 ) )
V_50 |= V_55 ;
return V_50 ? F_36 ( V_47 , V_56 , F_37 ( V_50 ) ) : 0 ;
}
static int F_38 ( struct V_46 * V_57 , struct V_58 * V_59 )
{
const struct V_60 * V_60 ;
if ( ! F_39 ( V_59 ) )
return 0 ;
F_40 ( & V_59 -> V_61 ) ;
if ( V_59 -> V_62 && V_59 -> V_62 -> V_63 ) {
V_60 = V_59 -> V_62 -> V_63 -> V_64 ;
if ( F_36 ( V_57 , V_65 ,
F_37 ( F_41 ( & V_66 , V_60 -> V_67 ) ) ) )
goto V_68;
if ( F_36 ( V_57 , V_69 ,
F_37 ( F_42 ( & V_66 , V_60 -> V_70 ) ) ) )
goto V_68;
}
F_43 ( & V_59 -> V_61 ) ;
return 0 ;
V_68:
F_43 ( & V_59 -> V_61 ) ;
return - 1 ;
}
static struct V_46 *
F_44 ( struct V_2 * V_2 , struct V_6 * V_35 ,
struct V_36 * V_37 ,
T_6 * * V_71 )
{
T_7 V_72 ;
T_7 V_73 = 0 , V_74 = 0 ;
unsigned int V_75 = 0 ;
struct V_46 * V_57 ;
struct V_76 * V_77 ;
struct V_78 * V_79 ;
struct V_80 * V_81 ;
struct V_82 * V_83 ;
struct V_46 * V_84 = V_37 -> V_57 ;
struct V_85 * V_86 ;
struct V_85 * V_87 ;
struct V_88 * V_89 = NULL ;
enum V_90 V_91 ( V_92 ) ;
bool V_49 ;
V_72 = F_45 ( sizeof( struct V_82 ) )
+ F_46 ( sizeof( struct V_78 ) )
+ F_46 ( sizeof( V_93 ) )
+ F_46 ( sizeof( V_93 ) )
#if F_47 ( V_94 )
+ F_46 ( sizeof( V_93 ) )
+ F_46 ( sizeof( V_93 ) )
#endif
+ F_46 ( sizeof( V_93 ) )
+ F_46 ( sizeof( struct V_95 ) )
+ F_46 ( sizeof( V_93 ) )
+ F_46 ( sizeof( V_93 ) ) ;
if ( V_84 -> V_96 . V_97 )
V_72 += F_46 ( sizeof( struct V_98 ) ) ;
if ( V_37 -> V_99 . V_100 <= V_101 ||
( V_37 -> V_99 . V_100 == V_102 && V_84 -> V_59 == NULL ) )
V_49 = ! F_48 ( V_84 ) ;
else
V_49 = false ;
V_87 = V_37 -> V_99 . V_103 ;
switch ( (enum V_104 ) F_49 ( V_35 -> V_25 ) ) {
case V_105 :
case V_26 :
break;
case V_106 :
if ( ! ( V_35 -> V_50 & V_107 ) &&
V_84 -> V_51 == V_52 &&
F_50 ( V_84 ) )
return NULL ;
V_73 = F_49 ( V_35 -> V_23 ) ;
if ( V_73 > V_84 -> V_108 )
V_73 = V_84 -> V_108 ;
V_75 = F_51 ( V_84 ) ;
V_75 = F_52 (unsigned int, hlen, data_len) ;
V_72 += sizeof( struct V_76 ) + V_75 ;
V_74 = V_84 -> V_108 ;
break;
}
if ( V_35 -> V_50 & V_109 )
V_89 = F_53 ( V_84 , & V_72 , & V_92 ) ;
if ( V_35 -> V_50 & V_110 ) {
V_72 += ( F_46 ( sizeof( V_93 ) )
+ F_46 ( sizeof( V_93 ) ) ) ;
}
V_57 = F_54 ( V_2 , V_72 , V_35 -> V_20 ,
V_18 ) ;
if ( ! V_57 ) {
F_55 ( V_84 ) ;
return NULL ;
}
V_81 = F_56 ( V_57 , 0 , 0 ,
V_111 << 8 | V_112 ,
sizeof( struct V_82 ) , 0 ) ;
if ( ! V_81 ) {
F_55 ( V_84 ) ;
F_57 ( V_57 ) ;
return NULL ;
}
V_83 = F_58 ( V_81 ) ;
V_83 -> V_113 = V_37 -> V_99 . V_114 ;
V_83 -> V_115 = V_116 ;
V_83 -> V_117 = F_59 ( V_35 -> V_4 ) ;
V_77 = F_60 ( V_57 , V_118 , sizeof( * V_79 ) ) ;
V_79 = F_61 ( V_77 ) ;
V_79 -> V_119 = V_84 -> V_120 ;
V_79 -> V_100 = V_37 -> V_99 . V_100 ;
* V_71 = & V_79 -> V_121 ;
V_86 = V_37 -> V_99 . V_122 ;
if ( V_86 ) {
#if ! F_47 ( V_94 )
if ( F_36 ( V_57 , V_123 , F_37 ( V_86 -> V_124 ) ) )
goto V_68;
#else
if ( V_37 -> V_99 . V_114 == V_125 ) {
if ( F_36 ( V_57 , V_126 ,
F_37 ( V_86 -> V_124 ) ) ||
F_36 ( V_57 , V_123 ,
F_37 ( F_62 ( V_86 ) -> V_127 -> V_128 -> V_124 ) ) )
goto V_68;
} else {
int V_129 ;
if ( F_36 ( V_57 , V_123 ,
F_37 ( V_86 -> V_124 ) ) )
goto V_68;
V_129 = F_63 ( V_84 ) ;
if ( V_129 &&
F_36 ( V_57 , V_126 ,
F_37 ( V_129 ) ) )
goto V_68;
}
#endif
}
if ( V_87 ) {
#if ! F_47 ( V_94 )
if ( F_36 ( V_57 , V_130 , F_37 ( V_87 -> V_124 ) ) )
goto V_68;
#else
if ( V_37 -> V_99 . V_114 == V_125 ) {
if ( F_36 ( V_57 , V_131 ,
F_37 ( V_87 -> V_124 ) ) ||
F_36 ( V_57 , V_130 ,
F_37 ( F_62 ( V_87 ) -> V_127 -> V_128 -> V_124 ) ) )
goto V_68;
} else {
int V_132 ;
if ( F_36 ( V_57 , V_130 ,
F_37 ( V_87 -> V_124 ) ) )
goto V_68;
V_132 = F_64 ( V_84 ) ;
if ( V_132 &&
F_36 ( V_57 , V_131 ,
F_37 ( V_132 ) ) )
goto V_68;
}
#endif
}
if ( V_84 -> V_133 &&
F_36 ( V_57 , V_134 , F_37 ( V_84 -> V_133 ) ) )
goto V_68;
if ( V_86 && V_84 -> V_128 &&
V_84 -> V_135 != V_84 -> V_136 ) {
struct V_95 V_137 ;
int V_108 ;
memset ( & V_137 , 0 , sizeof( V_137 ) ) ;
V_108 = F_65 ( V_84 , V_137 . V_138 ) ;
if ( V_108 ) {
V_137 . V_139 = F_59 ( V_108 ) ;
if ( F_66 ( V_57 , V_140 , sizeof( V_137 ) , & V_137 ) )
goto V_68;
}
}
if ( V_84 -> V_96 . V_97 ) {
struct V_98 V_141 ;
struct V_142 V_143 = F_67 ( V_84 -> V_96 ) ;
V_141 . V_144 = F_68 ( V_143 . V_145 ) ;
V_141 . V_146 = F_68 ( V_143 . V_147 ) ;
if ( F_66 ( V_57 , V_148 , sizeof( V_141 ) , & V_141 ) )
goto V_68;
}
if ( ( V_35 -> V_50 & V_110 ) && V_84 -> V_59 &&
F_38 ( V_57 , V_84 -> V_59 ) < 0 )
goto V_68;
if ( V_89 && F_69 ( V_57 , V_89 , V_92 ) < 0 )
goto V_68;
if ( V_74 > V_73 &&
F_36 ( V_57 , V_149 , F_37 ( V_74 ) ) )
goto V_68;
if ( F_34 ( V_57 , V_84 , V_49 ) )
goto V_68;
if ( V_73 ) {
struct V_76 * V_77 ;
if ( F_70 ( V_57 ) < sizeof( * V_77 ) + V_75 )
goto V_68;
V_77 = (struct V_76 * ) F_71 ( V_57 , sizeof( * V_77 ) ) ;
V_77 -> V_150 = V_151 ;
V_77 -> V_152 = F_72 ( V_73 ) ;
if ( F_73 ( V_57 , V_84 , V_73 , V_75 ) )
goto V_68;
}
V_81 -> V_153 = V_57 -> V_108 ;
return V_57 ;
V_68:
F_55 ( V_84 ) ;
F_57 ( V_57 ) ;
F_74 ( L_1 ) ;
return NULL ;
}
static int
F_75 ( struct V_2 * V_2 , struct V_6 * V_35 ,
struct V_36 * V_37 )
{
struct V_46 * V_154 ;
int V_14 = - V_155 ;
T_6 * V_71 ;
int V_156 = 0 ;
V_154 = F_44 ( V_2 , V_35 , V_37 , & V_71 ) ;
if ( V_154 == NULL ) {
V_14 = - V_19 ;
goto V_157;
}
F_29 ( & V_35 -> V_27 ) ;
if ( V_35 -> V_39 >= V_35 -> V_21 ) {
if ( V_35 -> V_50 & V_158 ) {
V_156 = 1 ;
V_14 = 0 ;
} else {
V_35 -> V_159 ++ ;
F_76 ( L_2 ,
V_35 -> V_39 ) ;
}
goto V_160;
}
V_37 -> V_40 = ++ V_35 -> V_161 ;
* V_71 = F_37 ( V_37 -> V_40 ) ;
V_14 = F_77 ( V_154 , V_2 , V_35 -> V_20 , V_162 ) ;
if ( V_14 < 0 ) {
V_35 -> V_163 ++ ;
goto V_164;
}
F_24 ( V_35 , V_37 ) ;
F_31 ( & V_35 -> V_27 ) ;
return 0 ;
V_160:
F_57 ( V_154 ) ;
V_164:
F_31 ( & V_35 -> V_27 ) ;
if ( V_156 )
F_33 ( V_37 , V_165 ) ;
V_157:
return V_14 ;
}
static struct V_36 *
F_78 ( struct V_36 * V_166 )
{
struct V_36 * V_37 = F_79 ( V_166 , V_166 -> V_72 , V_18 ) ;
if ( V_37 ) {
if ( F_80 ( V_37 ) )
return V_37 ;
F_14 ( V_37 ) ;
}
return NULL ;
}
static void F_81 ( struct V_46 * V_57 )
{
if ( V_57 -> V_167 )
F_82 ( V_57 , V_57 -> V_136 - V_57 -> V_135 ) ;
}
static void F_83 ( struct V_46 * V_57 )
{
if ( V_57 -> V_167 )
F_84 ( V_57 , V_57 -> V_136 - V_57 -> V_135 ) ;
}
static void F_85 ( struct V_36 * V_37 )
{
F_86 ( V_37 ) ;
F_14 ( V_37 ) ;
}
static int
F_87 ( struct V_2 * V_2 , struct V_6 * V_35 ,
struct V_46 * V_57 , struct V_36 * V_37 )
{
int V_168 = - V_19 ;
struct V_36 * V_169 ;
F_83 ( V_57 ) ;
if ( V_57 -> V_44 == NULL ) {
struct V_46 * V_170 = V_37 -> V_57 ;
V_37 -> V_57 = V_57 ;
V_168 = F_75 ( V_2 , V_35 , V_37 ) ;
if ( V_168 )
V_37 -> V_57 = V_170 ;
return V_168 ;
}
V_57 -> V_44 = NULL ;
V_169 = F_78 ( V_37 ) ;
if ( V_169 ) {
V_169 -> V_57 = V_57 ;
V_168 = F_75 ( V_2 , V_35 , V_169 ) ;
if ( V_168 )
F_85 ( V_169 ) ;
}
return V_168 ;
}
static int
F_88 ( struct V_36 * V_37 , unsigned int V_171 )
{
unsigned int V_172 ;
struct V_6 * V_35 ;
struct V_46 * V_57 , * V_173 ;
int V_14 = - V_155 ;
struct V_2 * V_2 = F_89 ( V_37 -> V_99 . V_122 ?
V_37 -> V_99 . V_122 : V_37 -> V_99 . V_103 ) ;
struct V_1 * V_7 = F_1 ( V_2 ) ;
V_35 = F_4 ( V_7 , V_171 ) ;
if ( ! V_35 )
return - V_174 ;
if ( V_35 -> V_25 == V_26 )
return - V_175 ;
V_57 = V_37 -> V_57 ;
switch ( V_37 -> V_99 . V_114 ) {
case V_176 :
V_57 -> V_120 = F_59 ( V_177 ) ;
break;
case V_178 :
V_57 -> V_120 = F_59 ( V_179 ) ;
break;
}
if ( ( V_35 -> V_50 & V_107 ) || ! F_35 ( V_57 ) )
return F_75 ( V_2 , V_35 , V_37 ) ;
F_81 ( V_57 ) ;
V_173 = F_90 ( V_57 , 0 ) ;
if ( F_91 ( V_173 ) )
goto V_180;
V_172 = 0 ;
V_14 = 0 ;
do {
struct V_46 * V_154 = V_173 -> V_44 ;
if ( V_14 == 0 )
V_14 = F_87 ( V_2 , V_35 ,
V_173 , V_37 ) ;
if ( V_14 == 0 )
V_172 ++ ;
else
F_57 ( V_173 ) ;
V_173 = V_154 ;
} while ( V_173 );
if ( V_172 ) {
if ( V_14 )
F_85 ( V_37 ) ;
F_57 ( V_57 ) ;
return 0 ;
}
V_180:
F_83 ( V_57 ) ;
return V_14 ;
}
static int
F_92 ( void * V_43 , int V_73 , struct V_36 * V_166 , int V_181 )
{
struct V_46 * V_154 ;
if ( V_181 < 0 ) {
if ( F_93 ( V_166 -> V_57 , V_73 ) )
return - V_19 ;
} else if ( V_181 > 0 ) {
if ( V_73 > 0xFFFF )
return - V_175 ;
if ( V_181 > F_70 ( V_166 -> V_57 ) ) {
V_154 = F_94 ( V_166 -> V_57 , F_95 ( V_166 -> V_57 ) ,
V_181 , V_18 ) ;
if ( ! V_154 ) {
F_96 ( V_182 L_3
L_4 ) ;
return - V_19 ;
}
F_57 ( V_166 -> V_57 ) ;
V_166 -> V_57 = V_154 ;
}
F_71 ( V_166 -> V_57 , V_181 ) ;
}
if ( ! F_97 ( V_166 -> V_57 , V_73 ) )
return - V_19 ;
F_98 ( V_166 -> V_57 , V_43 , V_73 ) ;
V_166 -> V_57 -> V_51 = V_183 ;
return 0 ;
}
static int
F_99 ( struct V_6 * V_35 ,
unsigned char V_184 , unsigned int V_185 )
{
int V_186 = 0 ;
F_29 ( & V_35 -> V_27 ) ;
switch ( V_184 ) {
case V_26 :
case V_105 :
V_35 -> V_25 = V_184 ;
V_35 -> V_23 = 0 ;
break;
case V_106 :
V_35 -> V_25 = V_184 ;
if ( V_185 == 0 || V_185 > V_24 )
V_35 -> V_23 = V_24 ;
else
V_35 -> V_23 = V_185 ;
break;
default:
V_186 = - V_175 ;
}
F_31 ( & V_35 -> V_27 ) ;
return V_186 ;
}
static int
F_100 ( struct V_36 * V_37 , unsigned long V_124 )
{
if ( V_37 -> V_99 . V_122 )
if ( V_37 -> V_99 . V_122 -> V_124 == V_124 )
return 1 ;
if ( V_37 -> V_99 . V_103 )
if ( V_37 -> V_99 . V_103 -> V_124 == V_124 )
return 1 ;
#if F_47 ( V_94 )
if ( V_37 -> V_57 -> V_167 ) {
int V_129 , V_132 ;
V_129 = F_63 ( V_37 -> V_57 ) ;
V_132 = F_64 ( V_37 -> V_57 ) ;
if ( V_129 == V_124 || V_132 == V_124 )
return 1 ;
}
#endif
return 0 ;
}
static void
F_101 ( struct V_2 * V_2 , int V_124 )
{
int V_41 ;
struct V_1 * V_7 = F_1 ( V_2 ) ;
F_102 () ;
for ( V_41 = 0 ; V_41 < V_5 ; V_41 ++ ) {
struct V_6 * V_10 ;
struct V_8 * V_9 = & V_7 -> V_11 [ V_41 ] ;
F_5 (inst, head, hlist)
F_18 ( V_10 , F_100 , V_124 ) ;
}
F_103 () ;
}
static int
F_104 ( struct V_187 * V_188 ,
unsigned long V_189 , void * V_190 )
{
struct V_85 * V_128 = F_105 ( V_190 ) ;
if ( V_189 == V_191 )
F_101 ( F_89 ( V_128 ) , V_128 -> V_124 ) ;
return V_192 ;
}
static int
F_106 ( struct V_187 * V_188 ,
unsigned long V_189 , void * V_190 )
{
struct V_193 * V_194 = V_190 ;
struct V_1 * V_7 = F_1 ( V_194 -> V_2 ) ;
if ( V_189 == V_195 && V_194 -> V_120 == V_196 ) {
int V_41 ;
F_7 ( & V_7 -> V_15 ) ;
for ( V_41 = 0 ; V_41 < V_5 ; V_41 ++ ) {
struct V_197 * V_198 ;
struct V_6 * V_10 ;
struct V_8 * V_9 = & V_7 -> V_11 [ V_41 ] ;
F_107 (inst, t2, head, hlist) {
if ( V_194 -> V_12 == V_10 -> V_20 )
F_20 ( V_10 ) ;
}
}
F_13 ( & V_7 -> V_15 ) ;
}
return V_192 ;
}
static struct V_6 *
F_108 ( struct V_1 * V_7 , T_8 V_4 , T_3 V_199 )
{
struct V_6 * V_35 ;
V_35 = F_4 ( V_7 , V_4 ) ;
if ( ! V_35 )
return F_15 ( - V_200 ) ;
if ( V_35 -> V_20 != V_199 )
return F_15 ( - V_201 ) ;
return V_35 ;
}
static struct V_202 *
F_109 ( const struct V_76 * const V_203 [] )
{
struct V_202 * V_204 ;
unsigned int V_205 ;
if ( ! V_203 [ V_206 ] )
return NULL ;
V_204 = F_61 ( V_203 [ V_206 ] ) ;
V_205 = F_110 ( V_204 -> V_205 ) & V_207 ;
if ( V_205 > V_208 || V_205 == V_209 )
return NULL ;
return V_204 ;
}
static int F_111 ( unsigned int V_40 , unsigned int V_210 )
{
return ( int ) ( V_40 - V_210 ) > 0 ;
}
static int
F_112 ( struct V_58 * V_211 , struct V_46 * V_57 ,
const struct V_80 * V_81 ,
const struct V_76 * const V_203 [] )
{
struct V_82 * V_83 = F_58 ( V_81 ) ;
struct V_36 * V_37 , * V_212 ;
unsigned int V_205 , V_213 ;
struct V_202 * V_204 ;
struct V_6 * V_35 ;
F_113 ( V_214 ) ;
T_8 V_4 = F_114 ( V_83 -> V_117 ) ;
struct V_2 * V_2 = F_115 ( V_211 ) ;
struct V_1 * V_7 = F_1 ( V_2 ) ;
V_35 = F_108 ( V_7 , V_4 ,
F_116 ( V_57 ) . V_12 ) ;
if ( F_117 ( V_35 ) )
return F_118 ( V_35 ) ;
V_204 = F_109 ( V_203 ) ;
if ( ! V_204 )
return - V_175 ;
V_205 = F_110 ( V_204 -> V_205 ) ;
V_213 = F_110 ( V_204 -> V_40 ) ;
F_29 ( & V_35 -> V_27 ) ;
F_32 (entry, tmp, &queue->queue_list, list) {
if ( F_111 ( V_37 -> V_40 , V_213 ) )
break;
F_26 ( V_35 , V_37 ) ;
F_25 ( & V_37 -> V_38 , & V_214 ) ;
}
F_31 ( & V_35 -> V_27 ) ;
if ( F_119 ( & V_214 ) )
return - V_215 ;
F_32 (entry, tmp, &batch_list, list) {
if ( V_203 [ V_134 ] )
V_37 -> V_57 -> V_133 = F_110 ( F_120 ( V_203 [ V_134 ] ) ) ;
F_33 ( V_37 , V_205 ) ;
}
return 0 ;
}
static int
F_121 ( struct V_58 * V_211 , struct V_46 * V_57 ,
const struct V_80 * V_81 ,
const struct V_76 * const V_203 [] )
{
struct V_82 * V_83 = F_58 ( V_81 ) ;
T_2 V_4 = F_114 ( V_83 -> V_117 ) ;
struct V_202 * V_204 ;
struct V_6 * V_35 ;
unsigned int V_205 ;
struct V_36 * V_37 ;
enum V_90 V_91 ( V_92 ) ;
struct V_88 * V_89 = NULL ;
struct V_2 * V_2 = F_115 ( V_211 ) ;
struct V_1 * V_7 = F_1 ( V_2 ) ;
V_35 = F_4 ( V_7 , V_4 ) ;
if ( ! V_35 )
V_35 = F_108 ( V_7 , V_4 ,
F_116 ( V_57 ) . V_12 ) ;
if ( F_117 ( V_35 ) )
return F_118 ( V_35 ) ;
V_204 = F_109 ( V_203 ) ;
if ( ! V_204 )
return - V_175 ;
V_205 = F_110 ( V_204 -> V_205 ) ;
V_37 = F_28 ( V_35 , F_110 ( V_204 -> V_40 ) ) ;
if ( V_37 == NULL )
return - V_215 ;
if ( V_203 [ V_216 ] ) {
V_89 = F_122 ( V_37 -> V_57 , V_203 [ V_216 ] , & V_92 ) ;
if ( V_89 && V_203 [ V_217 ] ) {
F_123 ( V_89 , V_203 [ V_217 ] ,
F_116 ( V_57 ) . V_12 ,
F_124 ( V_81 ) ) ;
}
}
if ( V_203 [ V_151 ] ) {
T_8 V_218 = V_152 ( V_203 [ V_151 ] ) ;
int V_181 = V_218 - V_37 -> V_57 -> V_108 ;
if ( F_92 ( F_61 ( V_203 [ V_151 ] ) ,
V_218 , V_37 , V_181 ) < 0 )
V_205 = V_45 ;
if ( V_89 )
F_125 ( V_37 -> V_57 , V_89 , V_92 , V_181 ) ;
}
if ( V_203 [ V_134 ] )
V_37 -> V_57 -> V_133 = F_110 ( F_120 ( V_203 [ V_134 ] ) ) ;
F_33 ( V_37 , V_205 ) ;
return 0 ;
}
static int
F_126 ( struct V_58 * V_211 , struct V_46 * V_57 ,
const struct V_80 * V_81 ,
const struct V_76 * const V_203 [] )
{
return - V_219 ;
}
static int
F_127 ( struct V_58 * V_211 , struct V_46 * V_57 ,
const struct V_80 * V_81 ,
const struct V_76 * const V_203 [] )
{
struct V_82 * V_83 = F_58 ( V_81 ) ;
T_2 V_4 = F_114 ( V_83 -> V_117 ) ;
struct V_6 * V_35 ;
struct V_220 * V_221 = NULL ;
struct V_2 * V_2 = F_115 ( V_211 ) ;
struct V_1 * V_7 = F_1 ( V_2 ) ;
int V_168 = 0 ;
if ( V_203 [ V_222 ] ) {
V_221 = F_61 ( V_203 [ V_222 ] ) ;
switch ( V_221 -> V_223 ) {
case V_224 : return 0 ;
case V_225 : return 0 ;
}
}
F_102 () ;
V_35 = F_4 ( V_7 , V_4 ) ;
if ( V_35 && V_35 -> V_20 != F_116 ( V_57 ) . V_12 ) {
V_168 = - V_201 ;
goto V_164;
}
if ( V_221 != NULL ) {
switch ( V_221 -> V_223 ) {
case V_226 :
if ( V_35 ) {
V_168 = - V_227 ;
goto V_164;
}
V_35 = F_6 ( V_7 , V_4 ,
F_116 ( V_57 ) . V_12 ) ;
if ( F_117 ( V_35 ) ) {
V_168 = F_118 ( V_35 ) ;
goto V_164;
}
break;
case V_228 :
if ( ! V_35 ) {
V_168 = - V_200 ;
goto V_164;
}
F_23 ( V_7 , V_35 ) ;
break;
case V_224 :
case V_225 :
break;
default:
V_168 = - V_219 ;
break;
}
}
if ( V_203 [ V_229 ] ) {
struct V_230 * V_231 ;
if ( ! V_35 ) {
V_168 = - V_200 ;
goto V_164;
}
V_231 = F_61 ( V_203 [ V_229 ] ) ;
F_99 ( V_35 , V_231 -> V_25 ,
F_110 ( V_231 -> V_23 ) ) ;
}
if ( V_203 [ V_232 ] ) {
T_6 * V_21 ;
if ( ! V_35 ) {
V_168 = - V_200 ;
goto V_164;
}
V_21 = F_61 ( V_203 [ V_232 ] ) ;
F_29 ( & V_35 -> V_27 ) ;
V_35 -> V_21 = F_110 ( * V_21 ) ;
F_31 ( & V_35 -> V_27 ) ;
}
if ( V_203 [ V_233 ] ) {
T_5 V_50 , V_234 ;
if ( ! V_35 ) {
V_168 = - V_200 ;
goto V_164;
}
if ( ! V_203 [ V_235 ] ) {
V_168 = - V_175 ;
goto V_164;
}
V_50 = F_110 ( F_120 ( V_203 [ V_233 ] ) ) ;
V_234 = F_110 ( F_120 ( V_203 [ V_235 ] ) ) ;
if ( V_50 >= V_236 ) {
V_168 = - V_237 ;
goto V_164;
}
F_29 ( & V_35 -> V_27 ) ;
V_35 -> V_50 &= ~ V_234 ;
V_35 -> V_50 |= V_50 & V_234 ;
F_31 ( & V_35 -> V_27 ) ;
}
V_164:
F_103 () ;
return V_168 ;
}
static struct V_197 * F_128 ( struct V_238 * V_239 )
{
struct V_240 * V_241 = V_239 -> V_242 ;
struct V_2 * V_2 ;
struct V_1 * V_7 ;
if ( ! V_241 )
return NULL ;
V_2 = F_129 ( V_239 ) ;
V_7 = F_1 ( V_2 ) ;
for ( V_241 -> V_243 = 0 ; V_241 -> V_243 < V_5 ; V_241 -> V_243 ++ ) {
if ( ! F_130 ( & V_7 -> V_11 [ V_241 -> V_243 ] ) )
return V_7 -> V_11 [ V_241 -> V_243 ] . V_244 ;
}
return NULL ;
}
static struct V_197 * F_131 ( struct V_238 * V_239 , struct V_197 * V_13 )
{
struct V_240 * V_241 = V_239 -> V_242 ;
struct V_2 * V_2 = F_129 ( V_239 ) ;
V_13 = V_13 -> V_44 ;
while ( ! V_13 ) {
struct V_1 * V_7 ;
if ( ++ V_241 -> V_243 >= V_5 )
return NULL ;
V_7 = F_1 ( V_2 ) ;
V_13 = V_7 -> V_11 [ V_241 -> V_243 ] . V_244 ;
}
return V_13 ;
}
static struct V_197 * F_132 ( struct V_238 * V_239 , T_9 V_245 )
{
struct V_197 * V_9 ;
V_9 = F_128 ( V_239 ) ;
if ( V_9 )
while ( V_245 && ( V_9 = F_131 ( V_239 , V_9 ) ) )
V_245 -- ;
return V_245 ? NULL : V_9 ;
}
static void * F_133 ( struct V_238 * V_246 , T_9 * V_245 )
__acquires( nfnl_queue_pernet( seq_file_net( V_246 )
static void * F_134 ( struct V_238 * V_246 , void * V_247 , T_9 * V_245 )
{
( * V_245 ) ++ ;
return F_131 ( V_246 , V_247 ) ;
}
static void F_135 ( struct V_238 * V_246 , void * V_247 )
__releases( nfnl_queue_pernet( seq_file_net( V_246 )
static int F_136 ( struct V_238 * V_246 , void * V_247 )
{
const struct V_6 * V_10 = V_247 ;
F_137 ( V_246 , L_5 ,
V_10 -> V_4 ,
V_10 -> V_20 , V_10 -> V_39 ,
V_10 -> V_25 , V_10 -> V_23 ,
V_10 -> V_159 , V_10 -> V_163 ,
V_10 -> V_161 , 1 ) ;
return F_138 ( V_246 ) ;
}
static int F_139 ( struct V_248 * V_248 , struct V_63 * V_63 )
{
return F_140 ( V_248 , V_63 , & V_249 ,
sizeof( struct V_240 ) ) ;
}
static int T_10 F_141 ( struct V_2 * V_2 )
{
unsigned int V_41 ;
struct V_1 * V_7 = F_1 ( V_2 ) ;
for ( V_41 = 0 ; V_41 < V_5 ; V_41 ++ )
F_142 ( & V_7 -> V_11 [ V_41 ] ) ;
F_9 ( & V_7 -> V_15 ) ;
#ifdef F_143
if ( ! F_144 ( L_6 , 0440 ,
V_2 -> V_250 . V_251 , & V_252 ) )
return - V_19 ;
#endif
return 0 ;
}
static void T_11 F_145 ( struct V_2 * V_2 )
{
#ifdef F_143
F_146 ( L_6 , V_2 -> V_250 . V_251 ) ;
#endif
}
static int T_12 F_147 ( void )
{
int V_186 ;
V_186 = F_148 ( & V_253 ) ;
if ( V_186 < 0 ) {
F_149 ( L_7 ) ;
goto V_103;
}
F_150 ( & V_254 ) ;
V_186 = F_151 ( & V_255 ) ;
if ( V_186 < 0 ) {
F_149 ( L_8 ) ;
goto V_256;
}
F_152 ( & V_257 ) ;
F_153 ( & V_258 ) ;
return V_186 ;
V_256:
F_154 ( & V_254 ) ;
V_103:
return V_186 ;
}
static void T_13 F_155 ( void )
{
F_156 () ;
F_157 ( & V_257 ) ;
F_158 ( & V_255 ) ;
F_154 ( & V_254 ) ;
F_159 ( & V_253 ) ;
F_160 () ;
}
