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
F_6 ( struct V_1 * V_7 , T_2 V_4 ,
int V_12 )
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
F_18 ( struct V_6 * V_35 , T_3 V_42 , unsigned long V_43 )
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
T_4 V_50 = 0 ;
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
if ( V_59 -> V_61 == V_62 )
return 0 ;
F_39 ( & V_59 -> V_63 ) ;
if ( V_59 -> V_64 && V_59 -> V_64 -> V_65 ) {
V_60 = V_59 -> V_64 -> V_65 -> V_66 ;
if ( F_36 ( V_57 , V_67 ,
F_37 ( F_40 ( & V_68 , V_60 -> V_69 ) ) ) )
goto V_70;
if ( F_36 ( V_57 , V_71 ,
F_37 ( F_41 ( & V_68 , V_60 -> V_72 ) ) ) )
goto V_70;
}
F_42 ( & V_59 -> V_63 ) ;
return 0 ;
V_70:
F_42 ( & V_59 -> V_63 ) ;
return - 1 ;
}
static struct V_46 *
F_43 ( struct V_2 * V_2 , struct V_6 * V_35 ,
struct V_36 * V_37 ,
T_5 * * V_73 )
{
T_6 V_74 ;
T_6 V_75 = 0 , V_76 = 0 ;
unsigned int V_77 = 0 ;
struct V_46 * V_57 ;
struct V_78 * V_79 ;
struct V_80 * V_81 ;
struct V_82 * V_83 ;
struct V_84 * V_85 ;
struct V_46 * V_86 = V_37 -> V_57 ;
struct V_87 * V_88 ;
struct V_87 * V_89 ;
struct V_90 * V_91 = NULL ;
enum V_92 V_93 ( V_94 ) ;
bool V_49 ;
V_74 = F_44 ( sizeof( struct V_84 ) )
+ F_45 ( sizeof( struct V_80 ) )
+ F_45 ( sizeof( V_95 ) )
+ F_45 ( sizeof( V_95 ) )
#if F_46 ( V_96 )
+ F_45 ( sizeof( V_95 ) )
+ F_45 ( sizeof( V_95 ) )
#endif
+ F_45 ( sizeof( V_95 ) )
+ F_45 ( sizeof( struct V_97 ) )
+ F_45 ( sizeof( V_95 ) )
+ F_45 ( sizeof( V_95 ) ) ;
if ( V_86 -> V_98 . V_99 )
V_74 += F_45 ( sizeof( struct V_100 ) ) ;
if ( V_37 -> V_101 <= V_102 ||
( V_37 -> V_101 == V_103 && V_86 -> V_59 == NULL ) )
V_49 = ! F_47 ( V_86 ) ;
else
V_49 = false ;
V_89 = V_37 -> V_89 ;
switch ( (enum V_104 ) F_48 ( V_35 -> V_25 ) ) {
case V_105 :
case V_26 :
break;
case V_106 :
if ( ! ( V_35 -> V_50 & V_107 ) &&
V_86 -> V_51 == V_52 &&
F_49 ( V_86 ) )
return NULL ;
V_75 = F_48 ( V_35 -> V_23 ) ;
if ( V_75 > V_86 -> V_108 )
V_75 = V_86 -> V_108 ;
V_77 = F_50 ( V_86 ) ;
V_77 = F_51 (unsigned int, hlen, data_len) ;
V_74 += sizeof( struct V_78 ) + V_77 ;
V_76 = V_86 -> V_108 ;
break;
}
if ( V_35 -> V_50 & V_109 )
V_91 = F_52 ( V_86 , & V_74 , & V_94 ) ;
if ( V_35 -> V_50 & V_110 ) {
V_74 += ( F_45 ( sizeof( V_95 ) )
+ F_45 ( sizeof( V_95 ) ) ) ;
}
V_57 = F_53 ( V_2 , V_74 , V_35 -> V_20 ,
V_18 ) ;
if ( ! V_57 ) {
F_54 ( V_86 ) ;
return NULL ;
}
V_83 = F_55 ( V_57 , 0 , 0 ,
V_111 << 8 | V_112 ,
sizeof( struct V_84 ) , 0 ) ;
if ( ! V_83 ) {
F_54 ( V_86 ) ;
F_56 ( V_57 ) ;
return NULL ;
}
V_85 = F_57 ( V_83 ) ;
V_85 -> V_113 = V_37 -> V_114 ;
V_85 -> V_115 = V_116 ;
V_85 -> V_117 = F_58 ( V_35 -> V_4 ) ;
V_79 = F_59 ( V_57 , V_118 , sizeof( * V_81 ) ) ;
V_81 = F_60 ( V_79 ) ;
V_81 -> V_119 = V_86 -> V_120 ;
V_81 -> V_101 = V_37 -> V_101 ;
* V_73 = & V_81 -> V_121 ;
V_88 = V_37 -> V_88 ;
if ( V_88 ) {
#if ! F_46 ( V_96 )
if ( F_36 ( V_57 , V_122 , F_37 ( V_88 -> V_123 ) ) )
goto V_70;
#else
if ( V_37 -> V_114 == V_124 ) {
if ( F_36 ( V_57 , V_125 ,
F_37 ( V_88 -> V_123 ) ) ||
F_36 ( V_57 , V_122 ,
F_37 ( F_61 ( V_88 ) -> V_126 -> V_127 -> V_123 ) ) )
goto V_70;
} else {
if ( F_36 ( V_57 , V_122 ,
F_37 ( V_88 -> V_123 ) ) )
goto V_70;
if ( V_86 -> V_128 && V_86 -> V_128 -> V_129 &&
F_36 ( V_57 , V_125 ,
F_37 ( V_86 -> V_128 -> V_129 -> V_123 ) ) )
goto V_70;
}
#endif
}
if ( V_89 ) {
#if ! F_46 ( V_96 )
if ( F_36 ( V_57 , V_130 , F_37 ( V_89 -> V_123 ) ) )
goto V_70;
#else
if ( V_37 -> V_114 == V_124 ) {
if ( F_36 ( V_57 , V_131 ,
F_37 ( V_89 -> V_123 ) ) ||
F_36 ( V_57 , V_130 ,
F_37 ( F_61 ( V_89 ) -> V_126 -> V_127 -> V_123 ) ) )
goto V_70;
} else {
if ( F_36 ( V_57 , V_130 ,
F_37 ( V_89 -> V_123 ) ) )
goto V_70;
if ( V_86 -> V_128 && V_86 -> V_128 -> V_132 &&
F_36 ( V_57 , V_131 ,
F_37 ( V_86 -> V_128 -> V_132 -> V_123 ) ) )
goto V_70;
}
#endif
}
if ( V_86 -> V_133 &&
F_36 ( V_57 , V_134 , F_37 ( V_86 -> V_133 ) ) )
goto V_70;
if ( V_88 && V_86 -> V_127 &&
V_86 -> V_135 != V_86 -> V_136 ) {
struct V_97 V_137 ;
int V_108 ;
memset ( & V_137 , 0 , sizeof( V_137 ) ) ;
V_108 = F_62 ( V_86 , V_137 . V_138 ) ;
if ( V_108 ) {
V_137 . V_139 = F_58 ( V_108 ) ;
if ( F_63 ( V_57 , V_140 , sizeof( V_137 ) , & V_137 ) )
goto V_70;
}
}
if ( V_86 -> V_98 . V_99 ) {
struct V_100 V_141 ;
struct V_142 V_143 = F_64 ( V_86 -> V_98 ) ;
V_141 . V_144 = F_65 ( V_143 . V_145 ) ;
V_141 . V_146 = F_65 ( V_143 . V_147 ) ;
if ( F_63 ( V_57 , V_148 , sizeof( V_141 ) , & V_141 ) )
goto V_70;
}
if ( ( V_35 -> V_50 & V_110 ) && V_86 -> V_59 &&
F_38 ( V_57 , V_86 -> V_59 ) < 0 )
goto V_70;
if ( V_91 && F_66 ( V_57 , V_91 , V_94 ) < 0 )
goto V_70;
if ( V_76 > V_75 &&
F_36 ( V_57 , V_149 , F_37 ( V_76 ) ) )
goto V_70;
if ( F_34 ( V_57 , V_86 , V_49 ) )
goto V_70;
if ( V_75 ) {
struct V_78 * V_79 ;
if ( F_67 ( V_57 ) < sizeof( * V_79 ) + V_77 )
goto V_70;
V_79 = (struct V_78 * ) F_68 ( V_57 , sizeof( * V_79 ) ) ;
V_79 -> V_150 = V_151 ;
V_79 -> V_152 = F_69 ( V_75 ) ;
if ( F_70 ( V_57 , V_86 , V_75 , V_77 ) )
goto V_70;
}
V_83 -> V_153 = V_57 -> V_108 ;
return V_57 ;
V_70:
F_54 ( V_86 ) ;
F_56 ( V_57 ) ;
F_71 ( L_1 ) ;
return NULL ;
}
static int
F_72 ( struct V_2 * V_2 , struct V_6 * V_35 ,
struct V_36 * V_37 )
{
struct V_46 * V_154 ;
int V_14 = - V_155 ;
T_5 * V_73 ;
int V_156 = 0 ;
V_154 = F_43 ( V_2 , V_35 , V_37 , & V_73 ) ;
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
F_73 ( L_2 ,
V_35 -> V_39 ) ;
}
goto V_160;
}
V_37 -> V_40 = ++ V_35 -> V_161 ;
* V_73 = F_37 ( V_37 -> V_40 ) ;
V_14 = F_74 ( V_154 , V_2 , V_35 -> V_20 , V_162 ) ;
if ( V_14 < 0 ) {
V_35 -> V_163 ++ ;
goto V_164;
}
F_24 ( V_35 , V_37 ) ;
F_31 ( & V_35 -> V_27 ) ;
return 0 ;
V_160:
F_56 ( V_154 ) ;
V_164:
F_31 ( & V_35 -> V_27 ) ;
if ( V_156 )
F_33 ( V_37 , V_165 ) ;
V_157:
return V_14 ;
}
static struct V_36 *
F_75 ( struct V_36 * V_166 )
{
struct V_36 * V_37 = F_76 ( V_166 , V_166 -> V_74 , V_18 ) ;
if ( V_37 ) {
if ( F_77 ( V_37 ) )
return V_37 ;
F_14 ( V_37 ) ;
}
return NULL ;
}
static void F_78 ( struct V_46 * V_57 )
{
if ( V_57 -> V_128 )
F_79 ( V_57 , V_57 -> V_136 - V_57 -> V_135 ) ;
}
static void F_80 ( struct V_46 * V_57 )
{
if ( V_57 -> V_128 )
F_81 ( V_57 , V_57 -> V_136 - V_57 -> V_135 ) ;
}
static void F_82 ( struct V_36 * V_37 )
{
F_83 ( V_37 ) ;
F_14 ( V_37 ) ;
}
static int
F_84 ( struct V_2 * V_2 , struct V_6 * V_35 ,
struct V_46 * V_57 , struct V_36 * V_37 )
{
int V_167 = - V_19 ;
struct V_36 * V_168 ;
F_80 ( V_57 ) ;
if ( V_57 -> V_44 == NULL ) {
struct V_46 * V_169 = V_37 -> V_57 ;
V_37 -> V_57 = V_57 ;
V_167 = F_72 ( V_2 , V_35 , V_37 ) ;
if ( V_167 )
V_37 -> V_57 = V_169 ;
return V_167 ;
}
V_57 -> V_44 = NULL ;
V_168 = F_75 ( V_37 ) ;
if ( V_168 ) {
V_168 -> V_57 = V_57 ;
V_167 = F_72 ( V_2 , V_35 , V_168 ) ;
if ( V_167 )
F_82 ( V_168 ) ;
}
return V_167 ;
}
static int
F_85 ( struct V_36 * V_37 , unsigned int V_170 )
{
unsigned int V_171 ;
struct V_6 * V_35 ;
struct V_46 * V_57 , * V_172 ;
int V_14 = - V_155 ;
struct V_2 * V_2 = F_86 ( V_37 -> V_88 ?
V_37 -> V_88 : V_37 -> V_89 ) ;
struct V_1 * V_7 = F_1 ( V_2 ) ;
V_35 = F_4 ( V_7 , V_170 ) ;
if ( ! V_35 )
return - V_173 ;
if ( V_35 -> V_25 == V_26 )
return - V_174 ;
V_57 = V_37 -> V_57 ;
switch ( V_37 -> V_114 ) {
case V_175 :
V_57 -> V_120 = F_58 ( V_176 ) ;
break;
case V_177 :
V_57 -> V_120 = F_58 ( V_178 ) ;
break;
}
if ( ( V_35 -> V_50 & V_107 ) || ! F_35 ( V_57 ) )
return F_72 ( V_2 , V_35 , V_37 ) ;
F_78 ( V_57 ) ;
V_172 = F_87 ( V_57 , 0 ) ;
if ( F_88 ( V_172 ) )
goto V_179;
V_171 = 0 ;
V_14 = 0 ;
do {
struct V_46 * V_154 = V_172 -> V_44 ;
if ( V_14 == 0 )
V_14 = F_84 ( V_2 , V_35 ,
V_172 , V_37 ) ;
if ( V_14 == 0 )
V_171 ++ ;
else
F_56 ( V_172 ) ;
V_172 = V_154 ;
} while ( V_172 );
if ( V_171 ) {
if ( V_14 )
F_82 ( V_37 ) ;
F_56 ( V_57 ) ;
return 0 ;
}
V_179:
F_80 ( V_57 ) ;
return V_14 ;
}
static int
F_89 ( void * V_43 , int V_75 , struct V_36 * V_166 , int V_180 )
{
struct V_46 * V_154 ;
if ( V_180 < 0 ) {
if ( F_90 ( V_166 -> V_57 , V_75 ) )
return - V_19 ;
} else if ( V_180 > 0 ) {
if ( V_75 > 0xFFFF )
return - V_174 ;
if ( V_180 > F_67 ( V_166 -> V_57 ) ) {
V_154 = F_91 ( V_166 -> V_57 , F_92 ( V_166 -> V_57 ) ,
V_180 , V_18 ) ;
if ( ! V_154 ) {
F_93 ( V_181 L_3
L_4 ) ;
return - V_19 ;
}
F_56 ( V_166 -> V_57 ) ;
V_166 -> V_57 = V_154 ;
}
F_68 ( V_166 -> V_57 , V_180 ) ;
}
if ( ! F_94 ( V_166 -> V_57 , V_75 ) )
return - V_19 ;
F_95 ( V_166 -> V_57 , V_43 , V_75 ) ;
V_166 -> V_57 -> V_51 = V_182 ;
return 0 ;
}
static int
F_96 ( struct V_6 * V_35 ,
unsigned char V_183 , unsigned int V_184 )
{
int V_185 = 0 ;
F_29 ( & V_35 -> V_27 ) ;
switch ( V_183 ) {
case V_26 :
case V_105 :
V_35 -> V_25 = V_183 ;
V_35 -> V_23 = 0 ;
break;
case V_106 :
V_35 -> V_25 = V_183 ;
if ( V_184 == 0 || V_184 > V_24 )
V_35 -> V_23 = V_24 ;
else
V_35 -> V_23 = V_184 ;
break;
default:
V_185 = - V_174 ;
}
F_31 ( & V_35 -> V_27 ) ;
return V_185 ;
}
static int
F_97 ( struct V_36 * V_37 , unsigned long V_123 )
{
if ( V_37 -> V_88 )
if ( V_37 -> V_88 -> V_123 == V_123 )
return 1 ;
if ( V_37 -> V_89 )
if ( V_37 -> V_89 -> V_123 == V_123 )
return 1 ;
#if F_46 ( V_96 )
if ( V_37 -> V_57 -> V_128 ) {
if ( V_37 -> V_57 -> V_128 -> V_129 &&
V_37 -> V_57 -> V_128 -> V_129 -> V_123 == V_123 )
return 1 ;
if ( V_37 -> V_57 -> V_128 -> V_132 &&
V_37 -> V_57 -> V_128 -> V_132 -> V_123 == V_123 )
return 1 ;
}
#endif
return 0 ;
}
static void
F_98 ( struct V_2 * V_2 , int V_123 )
{
int V_41 ;
struct V_1 * V_7 = F_1 ( V_2 ) ;
F_99 () ;
for ( V_41 = 0 ; V_41 < V_5 ; V_41 ++ ) {
struct V_6 * V_10 ;
struct V_8 * V_9 = & V_7 -> V_11 [ V_41 ] ;
F_5 (inst, head, hlist)
F_18 ( V_10 , F_97 , V_123 ) ;
}
F_100 () ;
}
static int
F_101 ( struct V_186 * V_187 ,
unsigned long V_188 , void * V_189 )
{
struct V_87 * V_127 = F_102 ( V_189 ) ;
if ( V_188 == V_190 )
F_98 ( F_86 ( V_127 ) , V_127 -> V_123 ) ;
return V_191 ;
}
static int
F_103 ( struct V_186 * V_187 ,
unsigned long V_188 , void * V_189 )
{
struct V_192 * V_193 = V_189 ;
struct V_1 * V_7 = F_1 ( V_193 -> V_2 ) ;
if ( V_188 == V_194 && V_193 -> V_120 == V_195 ) {
int V_41 ;
F_7 ( & V_7 -> V_15 ) ;
for ( V_41 = 0 ; V_41 < V_5 ; V_41 ++ ) {
struct V_196 * V_197 ;
struct V_6 * V_10 ;
struct V_8 * V_9 = & V_7 -> V_11 [ V_41 ] ;
F_104 (inst, t2, head, hlist) {
if ( V_193 -> V_12 == V_10 -> V_20 )
F_20 ( V_10 ) ;
}
}
F_13 ( & V_7 -> V_15 ) ;
}
return V_191 ;
}
static struct V_6 *
F_105 ( struct V_1 * V_7 , T_7 V_4 , int V_198 )
{
struct V_6 * V_35 ;
V_35 = F_4 ( V_7 , V_4 ) ;
if ( ! V_35 )
return F_15 ( - V_199 ) ;
if ( V_35 -> V_20 != V_198 )
return F_15 ( - V_200 ) ;
return V_35 ;
}
static struct V_201 *
F_106 ( const struct V_78 * const V_202 [] )
{
struct V_201 * V_203 ;
unsigned int V_204 ;
if ( ! V_202 [ V_205 ] )
return NULL ;
V_203 = F_60 ( V_202 [ V_205 ] ) ;
V_204 = F_107 ( V_203 -> V_204 ) & V_206 ;
if ( V_204 > V_207 || V_204 == V_208 )
return NULL ;
return V_203 ;
}
static int F_108 ( unsigned int V_40 , unsigned int V_209 )
{
return ( int ) ( V_40 - V_209 ) > 0 ;
}
static int
F_109 ( struct V_58 * V_210 , struct V_46 * V_57 ,
const struct V_82 * V_83 ,
const struct V_78 * const V_202 [] )
{
struct V_84 * V_85 = F_57 ( V_83 ) ;
struct V_36 * V_37 , * V_211 ;
unsigned int V_204 , V_212 ;
struct V_201 * V_203 ;
struct V_6 * V_35 ;
F_110 ( V_213 ) ;
T_7 V_4 = F_111 ( V_85 -> V_117 ) ;
struct V_2 * V_2 = F_112 ( V_210 ) ;
struct V_1 * V_7 = F_1 ( V_2 ) ;
V_35 = F_105 ( V_7 , V_4 ,
F_113 ( V_57 ) . V_12 ) ;
if ( F_114 ( V_35 ) )
return F_115 ( V_35 ) ;
V_203 = F_106 ( V_202 ) ;
if ( ! V_203 )
return - V_174 ;
V_204 = F_107 ( V_203 -> V_204 ) ;
V_212 = F_107 ( V_203 -> V_40 ) ;
F_29 ( & V_35 -> V_27 ) ;
F_32 (entry, tmp, &queue->queue_list, list) {
if ( F_108 ( V_37 -> V_40 , V_212 ) )
break;
F_26 ( V_35 , V_37 ) ;
F_25 ( & V_37 -> V_38 , & V_213 ) ;
}
F_31 ( & V_35 -> V_27 ) ;
if ( F_116 ( & V_213 ) )
return - V_214 ;
F_32 (entry, tmp, &batch_list, list) {
if ( V_202 [ V_134 ] )
V_37 -> V_57 -> V_133 = F_107 ( F_117 ( V_202 [ V_134 ] ) ) ;
F_33 ( V_37 , V_204 ) ;
}
return 0 ;
}
static int
F_118 ( struct V_58 * V_210 , struct V_46 * V_57 ,
const struct V_82 * V_83 ,
const struct V_78 * const V_202 [] )
{
struct V_84 * V_85 = F_57 ( V_83 ) ;
T_2 V_4 = F_111 ( V_85 -> V_117 ) ;
struct V_201 * V_203 ;
struct V_6 * V_35 ;
unsigned int V_204 ;
struct V_36 * V_37 ;
enum V_92 V_93 ( V_94 ) ;
struct V_90 * V_91 = NULL ;
struct V_2 * V_2 = F_112 ( V_210 ) ;
struct V_1 * V_7 = F_1 ( V_2 ) ;
V_35 = F_4 ( V_7 , V_4 ) ;
if ( ! V_35 )
V_35 = F_105 ( V_7 , V_4 ,
F_113 ( V_57 ) . V_12 ) ;
if ( F_114 ( V_35 ) )
return F_115 ( V_35 ) ;
V_203 = F_106 ( V_202 ) ;
if ( ! V_203 )
return - V_174 ;
V_204 = F_107 ( V_203 -> V_204 ) ;
V_37 = F_28 ( V_35 , F_107 ( V_203 -> V_40 ) ) ;
if ( V_37 == NULL )
return - V_214 ;
if ( V_202 [ V_215 ] ) {
V_91 = F_119 ( V_37 -> V_57 , V_202 [ V_215 ] , & V_94 ) ;
if ( V_91 && V_202 [ V_216 ] ) {
F_120 ( V_91 , V_202 [ V_216 ] ,
F_113 ( V_57 ) . V_12 ,
F_121 ( V_83 ) ) ;
}
}
if ( V_202 [ V_151 ] ) {
T_7 V_217 = V_152 ( V_202 [ V_151 ] ) ;
int V_180 = V_217 - V_37 -> V_57 -> V_108 ;
if ( F_89 ( F_60 ( V_202 [ V_151 ] ) ,
V_217 , V_37 , V_180 ) < 0 )
V_204 = V_45 ;
if ( V_91 )
F_122 ( V_37 -> V_57 , V_91 , V_94 , V_180 ) ;
}
if ( V_202 [ V_134 ] )
V_37 -> V_57 -> V_133 = F_107 ( F_117 ( V_202 [ V_134 ] ) ) ;
F_33 ( V_37 , V_204 ) ;
return 0 ;
}
static int
F_123 ( struct V_58 * V_210 , struct V_46 * V_57 ,
const struct V_82 * V_83 ,
const struct V_78 * const V_202 [] )
{
return - V_218 ;
}
static int
F_124 ( struct V_58 * V_210 , struct V_46 * V_57 ,
const struct V_82 * V_83 ,
const struct V_78 * const V_202 [] )
{
struct V_84 * V_85 = F_57 ( V_83 ) ;
T_2 V_4 = F_111 ( V_85 -> V_117 ) ;
struct V_6 * V_35 ;
struct V_219 * V_220 = NULL ;
struct V_2 * V_2 = F_112 ( V_210 ) ;
struct V_1 * V_7 = F_1 ( V_2 ) ;
int V_167 = 0 ;
if ( V_202 [ V_221 ] ) {
V_220 = F_60 ( V_202 [ V_221 ] ) ;
switch ( V_220 -> V_222 ) {
case V_223 : return 0 ;
case V_224 : return 0 ;
}
}
F_99 () ;
V_35 = F_4 ( V_7 , V_4 ) ;
if ( V_35 && V_35 -> V_20 != F_113 ( V_57 ) . V_12 ) {
V_167 = - V_200 ;
goto V_164;
}
if ( V_220 != NULL ) {
switch ( V_220 -> V_222 ) {
case V_225 :
if ( V_35 ) {
V_167 = - V_226 ;
goto V_164;
}
V_35 = F_6 ( V_7 , V_4 ,
F_113 ( V_57 ) . V_12 ) ;
if ( F_114 ( V_35 ) ) {
V_167 = F_115 ( V_35 ) ;
goto V_164;
}
break;
case V_227 :
if ( ! V_35 ) {
V_167 = - V_199 ;
goto V_164;
}
F_23 ( V_7 , V_35 ) ;
break;
case V_223 :
case V_224 :
break;
default:
V_167 = - V_218 ;
break;
}
}
if ( V_202 [ V_228 ] ) {
struct V_229 * V_230 ;
if ( ! V_35 ) {
V_167 = - V_199 ;
goto V_164;
}
V_230 = F_60 ( V_202 [ V_228 ] ) ;
F_96 ( V_35 , V_230 -> V_25 ,
F_107 ( V_230 -> V_23 ) ) ;
}
if ( V_202 [ V_231 ] ) {
T_5 * V_21 ;
if ( ! V_35 ) {
V_167 = - V_199 ;
goto V_164;
}
V_21 = F_60 ( V_202 [ V_231 ] ) ;
F_29 ( & V_35 -> V_27 ) ;
V_35 -> V_21 = F_107 ( * V_21 ) ;
F_31 ( & V_35 -> V_27 ) ;
}
if ( V_202 [ V_232 ] ) {
T_4 V_50 , V_233 ;
if ( ! V_35 ) {
V_167 = - V_199 ;
goto V_164;
}
if ( ! V_202 [ V_234 ] ) {
V_167 = - V_174 ;
goto V_164;
}
V_50 = F_107 ( F_117 ( V_202 [ V_232 ] ) ) ;
V_233 = F_107 ( F_117 ( V_202 [ V_234 ] ) ) ;
if ( V_50 >= V_235 ) {
V_167 = - V_236 ;
goto V_164;
}
F_29 ( & V_35 -> V_27 ) ;
V_35 -> V_50 &= ~ V_233 ;
V_35 -> V_50 |= V_50 & V_233 ;
F_31 ( & V_35 -> V_27 ) ;
}
V_164:
F_100 () ;
return V_167 ;
}
static struct V_196 * F_125 ( struct V_237 * V_238 )
{
struct V_239 * V_240 = V_238 -> V_241 ;
struct V_2 * V_2 ;
struct V_1 * V_7 ;
if ( ! V_240 )
return NULL ;
V_2 = F_126 ( V_238 ) ;
V_7 = F_1 ( V_2 ) ;
for ( V_240 -> V_242 = 0 ; V_240 -> V_242 < V_5 ; V_240 -> V_242 ++ ) {
if ( ! F_127 ( & V_7 -> V_11 [ V_240 -> V_242 ] ) )
return V_7 -> V_11 [ V_240 -> V_242 ] . V_243 ;
}
return NULL ;
}
static struct V_196 * F_128 ( struct V_237 * V_238 , struct V_196 * V_13 )
{
struct V_239 * V_240 = V_238 -> V_241 ;
struct V_2 * V_2 = F_126 ( V_238 ) ;
V_13 = V_13 -> V_44 ;
while ( ! V_13 ) {
struct V_1 * V_7 ;
if ( ++ V_240 -> V_242 >= V_5 )
return NULL ;
V_7 = F_1 ( V_2 ) ;
V_13 = V_7 -> V_11 [ V_240 -> V_242 ] . V_243 ;
}
return V_13 ;
}
static struct V_196 * F_129 ( struct V_237 * V_238 , T_8 V_244 )
{
struct V_196 * V_9 ;
V_9 = F_125 ( V_238 ) ;
if ( V_9 )
while ( V_244 && ( V_9 = F_128 ( V_238 , V_9 ) ) )
V_244 -- ;
return V_244 ? NULL : V_9 ;
}
static void * F_130 ( struct V_237 * V_245 , T_8 * V_244 )
__acquires( nfnl_queue_pernet( seq_file_net( V_245 )
static void * F_131 ( struct V_237 * V_245 , void * V_246 , T_8 * V_244 )
{
( * V_244 ) ++ ;
return F_128 ( V_245 , V_246 ) ;
}
static void F_132 ( struct V_237 * V_245 , void * V_246 )
__releases( nfnl_queue_pernet( seq_file_net( V_245 )
static int F_133 ( struct V_237 * V_245 , void * V_246 )
{
const struct V_6 * V_10 = V_246 ;
return F_134 ( V_245 , L_5 ,
V_10 -> V_4 ,
V_10 -> V_20 , V_10 -> V_39 ,
V_10 -> V_25 , V_10 -> V_23 ,
V_10 -> V_159 , V_10 -> V_163 ,
V_10 -> V_161 , 1 ) ;
}
static int F_135 ( struct V_247 * V_247 , struct V_65 * V_65 )
{
return F_136 ( V_247 , V_65 , & V_248 ,
sizeof( struct V_239 ) ) ;
}
static int T_9 F_137 ( struct V_2 * V_2 )
{
unsigned int V_41 ;
struct V_1 * V_7 = F_1 ( V_2 ) ;
for ( V_41 = 0 ; V_41 < V_5 ; V_41 ++ )
F_138 ( & V_7 -> V_11 [ V_41 ] ) ;
F_9 ( & V_7 -> V_15 ) ;
#ifdef F_139
if ( ! F_140 ( L_6 , 0440 ,
V_2 -> V_249 . V_250 , & V_251 ) )
return - V_19 ;
#endif
return 0 ;
}
static void T_10 F_141 ( struct V_2 * V_2 )
{
#ifdef F_139
F_142 ( L_6 , V_2 -> V_249 . V_250 ) ;
#endif
}
static int T_11 F_143 ( void )
{
int V_185 = - V_19 ;
F_144 ( & V_252 ) ;
V_185 = F_145 ( & V_253 ) ;
if ( V_185 < 0 ) {
F_146 ( L_7 ) ;
goto V_254;
}
V_185 = F_147 ( & V_255 ) ;
if ( V_185 < 0 ) {
F_146 ( L_8 ) ;
goto V_256;
}
F_148 ( & V_257 ) ;
F_149 ( & V_258 ) ;
return V_185 ;
V_256:
F_150 ( & V_253 ) ;
V_254:
F_151 ( & V_252 ) ;
return V_185 ;
}
static void T_12 F_152 ( void )
{
F_153 () ;
F_154 ( & V_257 ) ;
F_155 ( & V_255 ) ;
F_150 ( & V_253 ) ;
F_151 ( & V_252 ) ;
F_156 () ;
}
