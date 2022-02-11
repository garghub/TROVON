static inline T_1 F_1 ( T_2 V_1 )
{
return ( ( V_1 >> 8 ) | V_1 ) % V_2 ;
}
static struct V_3 *
F_2 ( T_2 V_1 )
{
struct V_4 * V_5 ;
struct V_3 * V_6 ;
V_5 = & V_7 [ F_1 ( V_1 ) ] ;
F_3 (inst, head, hlist) {
if ( V_6 -> V_1 == V_1 )
return V_6 ;
}
return NULL ;
}
static struct V_3 *
F_4 ( T_2 V_1 , int V_8 )
{
struct V_3 * V_6 ;
unsigned int V_9 ;
int V_10 ;
F_5 ( & V_11 ) ;
if ( F_2 ( V_1 ) ) {
V_10 = - V_12 ;
goto V_13;
}
V_6 = F_6 ( sizeof( * V_6 ) , V_14 ) ;
if ( ! V_6 ) {
V_10 = - V_15 ;
goto V_13;
}
V_6 -> V_1 = V_1 ;
V_6 -> V_16 = V_8 ;
V_6 -> V_17 = V_18 ;
V_6 -> V_19 = 0xffff ;
V_6 -> V_20 = V_21 ;
F_7 ( & V_6 -> V_22 ) ;
F_8 ( & V_6 -> V_23 ) ;
if ( ! F_9 ( V_24 ) ) {
V_10 = - V_25 ;
goto V_26;
}
V_9 = F_1 ( V_1 ) ;
F_10 ( & V_6 -> V_27 , & V_7 [ V_9 ] ) ;
F_11 ( & V_11 ) ;
return V_6 ;
V_26:
F_12 ( V_6 ) ;
V_13:
F_11 ( & V_11 ) ;
return F_13 ( V_10 ) ;
}
static void
F_14 ( struct V_28 * V_5 )
{
struct V_3 * V_6 = F_15 ( V_5 , struct V_3 ,
V_29 ) ;
F_16 ( V_6 , NULL , 0 ) ;
F_12 ( V_6 ) ;
F_17 ( V_24 ) ;
}
static void
F_18 ( struct V_3 * V_6 )
{
F_19 ( & V_6 -> V_27 ) ;
F_20 ( & V_6 -> V_29 , F_14 ) ;
}
static void
F_21 ( struct V_3 * V_6 )
{
F_5 ( & V_11 ) ;
F_18 ( V_6 ) ;
F_11 ( & V_11 ) ;
}
static inline void
F_22 ( struct V_3 * V_30 , struct V_31 * V_32 )
{
F_23 ( & V_32 -> V_33 , & V_30 -> V_23 ) ;
V_30 -> V_34 ++ ;
}
static void
F_24 ( struct V_3 * V_30 , struct V_31 * V_32 )
{
F_25 ( & V_32 -> V_33 ) ;
V_30 -> V_34 -- ;
}
static struct V_31 *
F_26 ( struct V_3 * V_30 , unsigned int V_35 )
{
struct V_31 * V_32 = NULL , * V_36 ;
F_27 ( & V_30 -> V_22 ) ;
F_28 (i, &queue->queue_list, list) {
if ( V_36 -> V_35 == V_35 ) {
V_32 = V_36 ;
break;
}
}
if ( V_32 )
F_24 ( V_30 , V_32 ) ;
F_29 ( & V_30 -> V_22 ) ;
return V_32 ;
}
static void
F_16 ( struct V_3 * V_30 , T_3 V_37 , unsigned long V_38 )
{
struct V_31 * V_32 , * V_39 ;
F_27 ( & V_30 -> V_22 ) ;
F_30 (entry, next, &queue->queue_list, list) {
if ( ! V_37 || V_37 ( V_32 , V_38 ) ) {
F_25 ( & V_32 -> V_33 ) ;
V_30 -> V_34 -- ;
F_31 ( V_32 , V_40 ) ;
}
}
F_29 ( & V_30 -> V_22 ) ;
}
static struct V_41 *
F_32 ( struct V_3 * V_30 ,
struct V_31 * V_32 ,
T_4 * * V_42 )
{
T_5 V_43 ;
T_6 V_44 ;
T_6 V_45 = 0 , V_46 = 0 ;
struct V_41 * V_47 ;
struct V_48 * V_49 ;
struct V_50 * V_51 ;
struct V_52 * V_53 ;
struct V_54 * V_55 ;
struct V_41 * V_56 = V_32 -> V_47 ;
struct V_57 * V_58 ;
struct V_57 * V_59 ;
struct V_60 * V_61 = NULL ;
enum V_62 V_63 ( V_64 ) ;
V_44 = F_33 ( sizeof( struct V_54 ) )
+ F_34 ( sizeof( struct V_50 ) )
+ F_34 ( sizeof( V_65 ) )
+ F_34 ( sizeof( V_65 ) )
#ifdef F_35
+ F_34 ( sizeof( V_65 ) )
+ F_34 ( sizeof( V_65 ) )
#endif
+ F_34 ( sizeof( V_65 ) )
+ F_34 ( sizeof( struct V_66 ) )
+ F_34 ( sizeof( struct V_67 )
+ F_34 ( sizeof( V_65 ) ) ) ;
V_59 = V_32 -> V_59 ;
switch ( (enum V_68 ) F_36 ( V_30 -> V_20 ) ) {
case V_69 :
case V_21 :
break;
case V_70 :
if ( V_56 -> V_71 == V_72 &&
F_37 ( V_56 ) )
return NULL ;
V_45 = F_36 ( V_30 -> V_19 ) ;
if ( V_45 == 0 || V_45 > V_56 -> V_73 )
V_45 = V_56 -> V_73 ;
V_44 += F_34 ( V_45 ) ;
V_46 = V_56 -> V_73 ;
break;
}
if ( V_30 -> V_74 & V_75 )
V_61 = F_38 ( V_56 , & V_44 , & V_64 ) ;
V_47 = F_39 ( V_44 , V_14 ) ;
if ( ! V_47 )
return NULL ;
V_43 = V_47 -> V_76 ;
V_53 = F_40 ( V_47 , 0 , 0 ,
V_77 << 8 | V_78 ,
sizeof( struct V_54 ) , 0 ) ;
if ( ! V_53 ) {
F_41 ( V_47 ) ;
return NULL ;
}
V_55 = F_42 ( V_53 ) ;
V_55 -> V_79 = V_32 -> V_80 ;
V_55 -> V_81 = V_82 ;
V_55 -> V_83 = F_43 ( V_30 -> V_1 ) ;
V_49 = F_44 ( V_47 , V_84 , sizeof( * V_51 ) ) ;
V_51 = F_45 ( V_49 ) ;
V_51 -> V_85 = V_56 -> V_86 ;
V_51 -> V_87 = V_32 -> V_87 ;
* V_42 = & V_51 -> V_88 ;
V_58 = V_32 -> V_58 ;
if ( V_58 ) {
#ifndef F_35
if ( F_46 ( V_47 , V_89 , F_47 ( V_58 -> V_90 ) ) )
goto V_91;
#else
if ( V_32 -> V_80 == V_92 ) {
if ( F_46 ( V_47 , V_93 ,
F_47 ( V_58 -> V_90 ) ) ||
F_46 ( V_47 , V_89 ,
F_47 ( F_48 ( V_58 ) -> V_94 -> V_95 -> V_90 ) ) )
goto V_91;
} else {
if ( F_46 ( V_47 , V_89 ,
F_47 ( V_58 -> V_90 ) ) )
goto V_91;
if ( V_56 -> V_96 && V_56 -> V_96 -> V_97 &&
F_46 ( V_47 , V_93 ,
F_47 ( V_56 -> V_96 -> V_97 -> V_90 ) ) )
goto V_91;
}
#endif
}
if ( V_59 ) {
#ifndef F_35
if ( F_46 ( V_47 , V_98 , F_47 ( V_59 -> V_90 ) ) )
goto V_91;
#else
if ( V_32 -> V_80 == V_92 ) {
if ( F_46 ( V_47 , V_99 ,
F_47 ( V_59 -> V_90 ) ) ||
F_46 ( V_47 , V_98 ,
F_47 ( F_48 ( V_59 ) -> V_94 -> V_95 -> V_90 ) ) )
goto V_91;
} else {
if ( F_46 ( V_47 , V_98 ,
F_47 ( V_59 -> V_90 ) ) )
goto V_91;
if ( V_56 -> V_96 && V_56 -> V_96 -> V_100 &&
F_46 ( V_47 , V_99 ,
F_47 ( V_56 -> V_96 -> V_100 -> V_90 ) ) )
goto V_91;
}
#endif
}
if ( V_56 -> V_101 &&
F_46 ( V_47 , V_102 , F_47 ( V_56 -> V_101 ) ) )
goto V_91;
if ( V_58 && V_56 -> V_95 &&
V_56 -> V_103 != V_56 -> V_104 ) {
struct V_66 V_105 ;
int V_73 = F_49 ( V_56 , V_105 . V_106 ) ;
if ( V_73 ) {
V_105 . V_107 = F_43 ( V_73 ) ;
if ( F_50 ( V_47 , V_108 , sizeof( V_105 ) , & V_105 ) )
goto V_91;
}
}
if ( V_56 -> V_109 . V_110 ) {
struct V_67 V_111 ;
struct V_112 V_113 = F_51 ( V_56 -> V_109 ) ;
V_111 . V_114 = F_52 ( V_113 . V_115 ) ;
V_111 . V_116 = F_52 ( V_113 . V_117 ) ;
if ( F_50 ( V_47 , V_118 , sizeof( V_111 ) , & V_111 ) )
goto V_91;
}
if ( V_45 ) {
struct V_48 * V_49 ;
int V_119 = F_53 ( V_45 ) ;
if ( F_54 ( V_47 ) < F_34 ( V_45 ) ) {
F_55 ( V_120 L_1 ) ;
F_41 ( V_47 ) ;
return NULL ;
}
V_49 = (struct V_48 * ) F_56 ( V_47 , F_34 ( V_45 ) ) ;
V_49 -> V_121 = V_122 ;
V_49 -> V_123 = V_119 ;
if ( F_57 ( V_56 , 0 , F_45 ( V_49 ) , V_45 ) )
F_58 () ;
}
if ( V_61 && F_59 ( V_47 , V_61 , V_64 ) < 0 )
goto V_91;
if ( V_46 > 0 && F_46 ( V_47 , V_124 , F_47 ( V_46 ) ) )
goto V_91;
V_53 -> V_125 = V_47 -> V_76 - V_43 ;
return V_47 ;
V_91:
F_41 ( V_47 ) ;
F_60 ( L_2 ) ;
return NULL ;
}
static int
F_61 ( struct V_31 * V_32 , unsigned int V_126 )
{
struct V_41 * V_127 ;
struct V_3 * V_30 ;
int V_10 = - V_128 ;
T_4 * V_42 ;
int V_129 = 0 ;
V_30 = F_2 ( V_126 ) ;
if ( ! V_30 ) {
V_10 = - V_130 ;
goto V_131;
}
if ( V_30 -> V_20 == V_21 ) {
V_10 = - V_132 ;
goto V_131;
}
V_127 = F_32 ( V_30 , V_32 , & V_42 ) ;
if ( V_127 == NULL ) {
V_10 = - V_15 ;
goto V_131;
}
F_27 ( & V_30 -> V_22 ) ;
if ( ! V_30 -> V_16 ) {
V_10 = - V_132 ;
goto V_133;
}
if ( V_30 -> V_34 >= V_30 -> V_17 ) {
if ( V_30 -> V_74 & V_134 ) {
V_129 = 1 ;
V_10 = 0 ;
} else {
V_30 -> V_135 ++ ;
F_62 ( L_3 ,
V_30 -> V_34 ) ;
}
goto V_133;
}
V_32 -> V_35 = ++ V_30 -> V_136 ;
* V_42 = F_47 ( V_32 -> V_35 ) ;
V_10 = F_63 ( V_127 , & V_137 , V_30 -> V_16 , V_138 ) ;
if ( V_10 < 0 ) {
V_30 -> V_139 ++ ;
goto V_140;
}
F_22 ( V_30 , V_32 ) ;
F_29 ( & V_30 -> V_22 ) ;
return 0 ;
V_133:
F_41 ( V_127 ) ;
V_140:
F_29 ( & V_30 -> V_22 ) ;
if ( V_129 )
F_31 ( V_32 , V_141 ) ;
V_131:
return V_10 ;
}
static int
F_64 ( void * V_38 , int V_45 , struct V_31 * V_142 , int V_143 )
{
struct V_41 * V_127 ;
if ( V_143 < 0 ) {
if ( F_65 ( V_142 -> V_47 , V_45 ) )
return - V_15 ;
} else if ( V_143 > 0 ) {
if ( V_45 > 0xFFFF )
return - V_132 ;
if ( V_143 > F_54 ( V_142 -> V_47 ) ) {
V_127 = F_66 ( V_142 -> V_47 , F_67 ( V_142 -> V_47 ) ,
V_143 , V_14 ) ;
if ( ! V_127 ) {
F_55 ( V_120 L_4
L_5 ) ;
return - V_15 ;
}
F_41 ( V_142 -> V_47 ) ;
V_142 -> V_47 = V_127 ;
}
F_56 ( V_142 -> V_47 , V_143 ) ;
}
if ( ! F_68 ( V_142 -> V_47 , V_45 ) )
return - V_15 ;
F_69 ( V_142 -> V_47 , V_38 , V_45 ) ;
V_142 -> V_47 -> V_71 = V_144 ;
return 0 ;
}
static int
F_70 ( struct V_3 * V_30 ,
unsigned char V_145 , unsigned int V_146 )
{
int V_147 = 0 ;
F_27 ( & V_30 -> V_22 ) ;
switch ( V_145 ) {
case V_21 :
case V_69 :
V_30 -> V_20 = V_145 ;
V_30 -> V_19 = 0 ;
break;
case V_70 :
V_30 -> V_20 = V_145 ;
if ( V_146 > 0xffff - V_148 )
V_30 -> V_19 = 0xffff - V_148 ;
else
V_30 -> V_19 = V_146 ;
break;
default:
V_147 = - V_132 ;
}
F_29 ( & V_30 -> V_22 ) ;
return V_147 ;
}
static int
F_71 ( struct V_31 * V_32 , unsigned long V_90 )
{
if ( V_32 -> V_58 )
if ( V_32 -> V_58 -> V_90 == V_90 )
return 1 ;
if ( V_32 -> V_59 )
if ( V_32 -> V_59 -> V_90 == V_90 )
return 1 ;
#ifdef F_35
if ( V_32 -> V_47 -> V_96 ) {
if ( V_32 -> V_47 -> V_96 -> V_97 &&
V_32 -> V_47 -> V_96 -> V_97 -> V_90 == V_90 )
return 1 ;
if ( V_32 -> V_47 -> V_96 -> V_100 &&
V_32 -> V_47 -> V_96 -> V_100 -> V_90 == V_90 )
return 1 ;
}
#endif
return 0 ;
}
static void
F_72 ( int V_90 )
{
int V_36 ;
F_73 () ;
for ( V_36 = 0 ; V_36 < V_2 ; V_36 ++ ) {
struct V_3 * V_6 ;
struct V_4 * V_5 = & V_7 [ V_36 ] ;
F_3 (inst, head, hlist)
F_16 ( V_6 , F_71 , V_90 ) ;
}
F_74 () ;
}
static int
F_75 ( struct V_149 * V_150 ,
unsigned long V_151 , void * V_152 )
{
struct V_57 * V_95 = V_152 ;
if ( ! F_76 ( F_77 ( V_95 ) , & V_137 ) )
return V_153 ;
if ( V_151 == V_154 )
F_72 ( V_95 -> V_90 ) ;
return V_153 ;
}
static int
F_78 ( struct V_149 * V_150 ,
unsigned long V_151 , void * V_152 )
{
struct V_155 * V_156 = V_152 ;
if ( V_151 == V_157 && V_156 -> V_86 == V_158 ) {
int V_36 ;
F_5 ( & V_11 ) ;
for ( V_36 = 0 ; V_36 < V_2 ; V_36 ++ ) {
struct V_159 * V_160 ;
struct V_3 * V_6 ;
struct V_4 * V_5 = & V_7 [ V_36 ] ;
F_79 (inst, t2, head, hlist) {
if ( ( V_156 -> V_161 == & V_137 ) &&
( V_156 -> V_8 == V_6 -> V_16 ) )
F_18 ( V_6 ) ;
}
}
F_11 ( & V_11 ) ;
}
return V_153 ;
}
static struct V_3 * F_80 ( T_7 V_1 , int V_162 )
{
struct V_3 * V_30 ;
V_30 = F_2 ( V_1 ) ;
if ( ! V_30 )
return F_13 ( - V_163 ) ;
if ( V_30 -> V_16 != V_162 )
return F_13 ( - V_164 ) ;
return V_30 ;
}
static struct V_165 *
F_81 ( const struct V_48 * const V_166 [] )
{
struct V_165 * V_167 ;
unsigned int V_168 ;
if ( ! V_166 [ V_169 ] )
return NULL ;
V_167 = F_45 ( V_166 [ V_169 ] ) ;
V_168 = F_82 ( V_167 -> V_168 ) & V_170 ;
if ( V_168 > V_171 || V_168 == V_172 )
return NULL ;
return V_167 ;
}
static int F_83 ( unsigned int V_35 , unsigned int V_173 )
{
return ( int ) ( V_35 - V_173 ) > 0 ;
}
static int
F_84 ( struct V_174 * V_175 , struct V_41 * V_47 ,
const struct V_52 * V_53 ,
const struct V_48 * const V_166 [] )
{
struct V_54 * V_55 = F_42 ( V_53 ) ;
struct V_31 * V_32 , * V_176 ;
unsigned int V_168 , V_177 ;
struct V_165 * V_167 ;
struct V_3 * V_30 ;
F_85 ( V_178 ) ;
T_7 V_1 = F_86 ( V_55 -> V_83 ) ;
V_30 = F_80 ( V_1 , F_87 ( V_47 ) . V_8 ) ;
if ( F_88 ( V_30 ) )
return F_89 ( V_30 ) ;
V_167 = F_81 ( V_166 ) ;
if ( ! V_167 )
return - V_132 ;
V_168 = F_82 ( V_167 -> V_168 ) ;
V_177 = F_82 ( V_167 -> V_35 ) ;
F_27 ( & V_30 -> V_22 ) ;
F_30 (entry, tmp, &queue->queue_list, list) {
if ( F_83 ( V_32 -> V_35 , V_177 ) )
break;
F_24 ( V_30 , V_32 ) ;
F_23 ( & V_32 -> V_33 , & V_178 ) ;
}
F_29 ( & V_30 -> V_22 ) ;
if ( F_90 ( & V_178 ) )
return - V_179 ;
F_30 (entry, tmp, &batch_list, list) {
if ( V_166 [ V_102 ] )
V_32 -> V_47 -> V_101 = F_82 ( F_91 ( V_166 [ V_102 ] ) ) ;
F_31 ( V_32 , V_168 ) ;
}
return 0 ;
}
static int
F_92 ( struct V_174 * V_175 , struct V_41 * V_47 ,
const struct V_52 * V_53 ,
const struct V_48 * const V_166 [] )
{
struct V_54 * V_55 = F_42 ( V_53 ) ;
T_2 V_1 = F_86 ( V_55 -> V_83 ) ;
struct V_165 * V_167 ;
struct V_3 * V_30 ;
unsigned int V_168 ;
struct V_31 * V_32 ;
enum V_62 V_63 ( V_64 ) ;
struct V_60 * V_61 = NULL ;
V_30 = F_2 ( V_1 ) ;
if ( ! V_30 )
V_30 = F_80 ( V_1 , F_87 ( V_47 ) . V_8 ) ;
if ( F_88 ( V_30 ) )
return F_89 ( V_30 ) ;
V_167 = F_81 ( V_166 ) ;
if ( ! V_167 )
return - V_132 ;
V_168 = F_82 ( V_167 -> V_168 ) ;
V_32 = F_26 ( V_30 , F_82 ( V_167 -> V_35 ) ) ;
if ( V_32 == NULL )
return - V_179 ;
F_73 () ;
if ( V_166 [ V_180 ] && ( V_30 -> V_74 & V_75 ) )
V_61 = F_93 ( V_32 -> V_47 , V_166 [ V_180 ] , & V_64 ) ;
if ( V_166 [ V_122 ] ) {
T_7 V_181 = V_123 ( V_166 [ V_122 ] ) ;
int V_143 = V_181 - V_32 -> V_47 -> V_73 ;
if ( F_64 ( F_45 ( V_166 [ V_122 ] ) ,
V_181 , V_32 , V_143 ) < 0 )
V_168 = V_40 ;
if ( V_61 )
F_94 ( V_47 , V_61 , V_64 , V_143 ) ;
}
F_74 () ;
if ( V_166 [ V_102 ] )
V_32 -> V_47 -> V_101 = F_82 ( F_91 ( V_166 [ V_102 ] ) ) ;
F_31 ( V_32 , V_168 ) ;
return 0 ;
}
static int
F_95 ( struct V_174 * V_175 , struct V_41 * V_47 ,
const struct V_52 * V_53 ,
const struct V_48 * const V_166 [] )
{
return - V_182 ;
}
static int
F_96 ( struct V_174 * V_175 , struct V_41 * V_47 ,
const struct V_52 * V_53 ,
const struct V_48 * const V_166 [] )
{
struct V_54 * V_55 = F_42 ( V_53 ) ;
T_2 V_1 = F_86 ( V_55 -> V_83 ) ;
struct V_3 * V_30 ;
struct V_183 * V_184 = NULL ;
int V_185 = 0 ;
if ( V_166 [ V_186 ] ) {
V_184 = F_45 ( V_166 [ V_186 ] ) ;
switch ( V_184 -> V_187 ) {
case V_188 : return 0 ;
case V_189 : return 0 ;
}
}
F_73 () ;
V_30 = F_2 ( V_1 ) ;
if ( V_30 && V_30 -> V_16 != F_87 ( V_47 ) . V_8 ) {
V_185 = - V_164 ;
goto V_140;
}
if ( V_184 != NULL ) {
switch ( V_184 -> V_187 ) {
case V_190 :
if ( V_30 ) {
V_185 = - V_191 ;
goto V_140;
}
V_30 = F_4 ( V_1 , F_87 ( V_47 ) . V_8 ) ;
if ( F_88 ( V_30 ) ) {
V_185 = F_89 ( V_30 ) ;
goto V_140;
}
break;
case V_192 :
if ( ! V_30 ) {
V_185 = - V_163 ;
goto V_140;
}
F_21 ( V_30 ) ;
break;
case V_188 :
case V_189 :
break;
default:
V_185 = - V_182 ;
break;
}
}
if ( V_166 [ V_193 ] ) {
struct V_194 * V_195 ;
if ( ! V_30 ) {
V_185 = - V_163 ;
goto V_140;
}
V_195 = F_45 ( V_166 [ V_193 ] ) ;
F_70 ( V_30 , V_195 -> V_20 ,
F_82 ( V_195 -> V_19 ) ) ;
}
if ( V_166 [ V_196 ] ) {
T_4 * V_17 ;
if ( ! V_30 ) {
V_185 = - V_163 ;
goto V_140;
}
V_17 = F_45 ( V_166 [ V_196 ] ) ;
F_27 ( & V_30 -> V_22 ) ;
V_30 -> V_17 = F_82 ( * V_17 ) ;
F_29 ( & V_30 -> V_22 ) ;
}
if ( V_166 [ V_197 ] ) {
T_8 V_74 , V_198 ;
if ( ! V_30 ) {
V_185 = - V_163 ;
goto V_140;
}
if ( ! V_166 [ V_199 ] ) {
V_185 = - V_132 ;
goto V_140;
}
V_74 = F_82 ( F_91 ( V_166 [ V_197 ] ) ) ;
V_198 = F_82 ( F_91 ( V_166 [ V_199 ] ) ) ;
if ( V_74 >= V_200 ) {
V_185 = - V_201 ;
goto V_140;
}
F_27 ( & V_30 -> V_22 ) ;
V_30 -> V_74 &= ~ V_198 ;
V_30 -> V_74 |= V_74 & V_198 ;
F_29 ( & V_30 -> V_22 ) ;
}
V_140:
F_74 () ;
return V_185 ;
}
static struct V_159 * F_97 ( struct V_202 * V_203 )
{
struct V_204 * V_205 = V_203 -> V_206 ;
if ( ! V_205 )
return NULL ;
for ( V_205 -> V_207 = 0 ; V_205 -> V_207 < V_2 ; V_205 -> V_207 ++ ) {
if ( ! F_98 ( & V_7 [ V_205 -> V_207 ] ) )
return V_7 [ V_205 -> V_207 ] . V_208 ;
}
return NULL ;
}
static struct V_159 * F_99 ( struct V_202 * V_203 , struct V_159 * V_9 )
{
struct V_204 * V_205 = V_203 -> V_206 ;
V_9 = V_9 -> V_39 ;
while ( ! V_9 ) {
if ( ++ V_205 -> V_207 >= V_2 )
return NULL ;
V_9 = V_7 [ V_205 -> V_207 ] . V_208 ;
}
return V_9 ;
}
static struct V_159 * F_100 ( struct V_202 * V_203 , T_9 V_209 )
{
struct V_159 * V_5 ;
V_5 = F_97 ( V_203 ) ;
if ( V_5 )
while ( V_209 && ( V_5 = F_99 ( V_203 , V_5 ) ) )
V_209 -- ;
return V_209 ? NULL : V_5 ;
}
static void * F_101 ( struct V_202 * V_203 , T_9 * V_209 )
__acquires( V_11 )
{
F_5 ( & V_11 ) ;
return F_100 ( V_203 , * V_209 ) ;
}
static void * F_102 ( struct V_202 * V_210 , void * V_211 , T_9 * V_209 )
{
( * V_209 ) ++ ;
return F_99 ( V_210 , V_211 ) ;
}
static void F_103 ( struct V_202 * V_210 , void * V_211 )
__releases( V_11 )
{
F_11 ( & V_11 ) ;
}
static int F_104 ( struct V_202 * V_210 , void * V_211 )
{
const struct V_3 * V_6 = V_211 ;
return F_105 ( V_210 , L_6 ,
V_6 -> V_1 ,
V_6 -> V_16 , V_6 -> V_34 ,
V_6 -> V_20 , V_6 -> V_19 ,
V_6 -> V_135 , V_6 -> V_139 ,
V_6 -> V_136 , 1 ) ;
}
static int F_106 ( struct V_212 * V_212 , struct V_213 * V_213 )
{
return F_107 ( V_213 , & V_214 ,
sizeof( struct V_204 ) ) ;
}
static int T_10 F_108 ( void )
{
int V_36 , V_147 = - V_15 ;
for ( V_36 = 0 ; V_36 < V_2 ; V_36 ++ )
F_109 ( & V_7 [ V_36 ] ) ;
F_110 ( & V_215 ) ;
V_147 = F_111 ( & V_216 ) ;
if ( V_147 < 0 ) {
F_55 ( V_217 L_7 ) ;
goto V_218;
}
#ifdef F_112
if ( ! F_113 ( L_8 , 0440 ,
V_219 , & V_220 ) ) {
V_147 = - V_15 ;
goto V_221;
}
#endif
F_114 ( & V_222 ) ;
F_115 ( & V_223 ) ;
return V_147 ;
#ifdef F_112
V_221:
F_116 ( & V_216 ) ;
#endif
V_218:
F_117 ( & V_215 ) ;
return V_147 ;
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
