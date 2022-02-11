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
T_6 V_47 = 0 ;
struct V_43 * V_48 ;
struct V_49 * V_50 ;
struct V_51 * V_52 ;
struct V_53 * V_54 ;
struct V_55 * V_56 ;
struct V_43 * V_57 = V_34 -> V_48 ;
struct V_58 * V_59 ;
struct V_58 * V_60 ;
struct V_61 * V_62 = NULL ;
enum V_63 V_64 ( V_65 ) ;
V_46 = F_33 ( sizeof( struct V_55 ) )
+ F_34 ( sizeof( struct V_51 ) )
+ F_34 ( sizeof( V_66 ) )
+ F_34 ( sizeof( V_66 ) )
#ifdef F_35
+ F_34 ( sizeof( V_66 ) )
+ F_34 ( sizeof( V_66 ) )
#endif
+ F_34 ( sizeof( V_66 ) )
+ F_34 ( sizeof( struct V_67 ) )
+ F_34 ( sizeof( struct V_68 ) ) ;
V_60 = V_34 -> V_60 ;
switch ( (enum V_69 ) F_36 ( V_32 -> V_22 ) ) {
case V_70 :
case V_23 :
break;
case V_71 :
if ( V_57 -> V_72 == V_73 &&
F_37 ( V_57 ) )
return NULL ;
V_47 = F_36 ( V_32 -> V_21 ) ;
if ( V_47 == 0 || V_47 > V_57 -> V_74 )
V_47 = V_57 -> V_74 ;
V_46 += F_34 ( V_47 ) ;
break;
}
if ( V_32 -> V_75 & V_76 )
V_62 = F_38 ( V_57 , & V_46 , & V_65 ) ;
V_48 = F_39 ( V_46 , V_16 ) ;
if ( ! V_48 )
return NULL ;
V_45 = V_48 -> V_77 ;
V_54 = F_40 ( V_48 , 0 , 0 ,
V_78 << 8 | V_79 ,
sizeof( struct V_55 ) , 0 ) ;
if ( ! V_54 ) {
F_41 ( V_48 ) ;
return NULL ;
}
V_56 = F_42 ( V_54 ) ;
V_56 -> V_80 = V_34 -> V_81 ;
V_56 -> V_82 = V_83 ;
V_56 -> V_84 = F_43 ( V_32 -> V_1 ) ;
V_50 = F_44 ( V_48 , V_85 , sizeof( * V_52 ) ) ;
V_52 = F_45 ( V_50 ) ;
V_52 -> V_86 = V_57 -> V_87 ;
V_52 -> V_88 = V_34 -> V_88 ;
* V_44 = & V_52 -> V_89 ;
V_59 = V_34 -> V_59 ;
if ( V_59 ) {
#ifndef F_35
if ( F_46 ( V_48 , V_90 , F_47 ( V_59 -> V_91 ) ) )
goto V_92;
#else
if ( V_34 -> V_81 == V_93 ) {
if ( F_46 ( V_48 , V_94 ,
F_47 ( V_59 -> V_91 ) ) ||
F_46 ( V_48 , V_90 ,
F_47 ( F_48 ( V_59 ) -> V_95 -> V_96 -> V_91 ) ) )
goto V_92;
} else {
if ( F_46 ( V_48 , V_90 ,
F_47 ( V_59 -> V_91 ) ) )
goto V_92;
if ( V_57 -> V_97 && V_57 -> V_97 -> V_98 &&
F_46 ( V_48 , V_94 ,
F_47 ( V_57 -> V_97 -> V_98 -> V_91 ) ) )
goto V_92;
}
#endif
}
if ( V_60 ) {
#ifndef F_35
if ( F_46 ( V_48 , V_99 , F_47 ( V_60 -> V_91 ) ) )
goto V_92;
#else
if ( V_34 -> V_81 == V_93 ) {
if ( F_46 ( V_48 , V_100 ,
F_47 ( V_60 -> V_91 ) ) ||
F_46 ( V_48 , V_99 ,
F_47 ( F_48 ( V_60 ) -> V_95 -> V_96 -> V_91 ) ) )
goto V_92;
} else {
if ( F_46 ( V_48 , V_99 ,
F_47 ( V_60 -> V_91 ) ) )
goto V_92;
if ( V_57 -> V_97 && V_57 -> V_97 -> V_101 &&
F_46 ( V_48 , V_100 ,
F_47 ( V_57 -> V_97 -> V_101 -> V_91 ) ) )
goto V_92;
}
#endif
}
if ( V_57 -> V_102 &&
F_46 ( V_48 , V_103 , F_47 ( V_57 -> V_102 ) ) )
goto V_92;
if ( V_59 && V_57 -> V_96 &&
V_57 -> V_104 != V_57 -> V_105 ) {
struct V_67 V_106 ;
int V_74 = F_49 ( V_57 , V_106 . V_107 ) ;
if ( V_74 ) {
V_106 . V_108 = F_43 ( V_74 ) ;
if ( F_50 ( V_48 , V_109 , sizeof( V_106 ) , & V_106 ) )
goto V_92;
}
}
if ( V_57 -> V_110 . V_111 ) {
struct V_68 V_112 ;
struct V_113 V_114 = F_51 ( V_57 -> V_110 ) ;
V_112 . V_115 = F_52 ( V_114 . V_116 ) ;
V_112 . V_117 = F_52 ( V_114 . V_118 ) ;
if ( F_50 ( V_48 , V_119 , sizeof( V_112 ) , & V_112 ) )
goto V_92;
}
if ( V_47 ) {
struct V_49 * V_50 ;
int V_120 = F_53 ( V_47 ) ;
if ( F_54 ( V_48 ) < F_34 ( V_47 ) ) {
F_55 ( V_121 L_1 ) ;
F_41 ( V_48 ) ;
return NULL ;
}
V_50 = (struct V_49 * ) F_56 ( V_48 , F_34 ( V_47 ) ) ;
V_50 -> V_122 = V_123 ;
V_50 -> V_124 = V_120 ;
if ( F_57 ( V_57 , 0 , F_45 ( V_50 ) , V_47 ) )
F_58 () ;
}
if ( V_62 && F_59 ( V_48 , V_62 , V_65 ) < 0 )
goto V_92;
V_54 -> V_125 = V_48 -> V_77 - V_45 ;
return V_48 ;
V_92:
if ( V_48 )
F_41 ( V_48 ) ;
F_60 ( L_2 ) ;
return NULL ;
}
static int
F_61 ( struct V_33 * V_34 , unsigned int V_126 )
{
struct V_43 * V_127 ;
struct V_3 * V_32 ;
int V_12 = - V_128 ;
T_4 * V_44 ;
int V_129 = 0 ;
V_32 = F_2 ( V_126 ) ;
if ( ! V_32 ) {
V_12 = - V_130 ;
goto V_131;
}
if ( V_32 -> V_22 == V_23 ) {
V_12 = - V_132 ;
goto V_131;
}
V_127 = F_32 ( V_32 , V_34 , & V_44 ) ;
if ( V_127 == NULL ) {
V_12 = - V_17 ;
goto V_131;
}
F_27 ( & V_32 -> V_24 ) ;
if ( ! V_32 -> V_18 ) {
V_12 = - V_132 ;
goto V_133;
}
if ( V_32 -> V_36 >= V_32 -> V_19 ) {
if ( V_32 -> V_75 & V_134 ) {
V_129 = 1 ;
V_12 = 0 ;
} else {
V_32 -> V_135 ++ ;
F_62 ( L_3 ,
V_32 -> V_36 ) ;
}
goto V_133;
}
V_34 -> V_37 = ++ V_32 -> V_136 ;
* V_44 = F_47 ( V_34 -> V_37 ) ;
V_12 = F_63 ( V_127 , & V_137 , V_32 -> V_18 , V_138 ) ;
if ( V_12 < 0 ) {
V_32 -> V_139 ++ ;
goto V_140;
}
F_22 ( V_32 , V_34 ) ;
F_29 ( & V_32 -> V_24 ) ;
return 0 ;
V_133:
F_41 ( V_127 ) ;
V_140:
F_29 ( & V_32 -> V_24 ) ;
if ( V_129 )
F_31 ( V_34 , V_141 ) ;
V_131:
return V_12 ;
}
static int
F_64 ( void * V_40 , int V_47 , struct V_33 * V_142 , int V_143 )
{
struct V_43 * V_127 ;
if ( V_143 < 0 ) {
if ( F_65 ( V_142 -> V_48 , V_47 ) )
return - V_17 ;
} else if ( V_143 > 0 ) {
if ( V_47 > 0xFFFF )
return - V_132 ;
if ( V_143 > F_54 ( V_142 -> V_48 ) ) {
V_127 = F_66 ( V_142 -> V_48 , F_67 ( V_142 -> V_48 ) ,
V_143 , V_16 ) ;
if ( ! V_127 ) {
F_55 ( V_121 L_4
L_5 ) ;
return - V_17 ;
}
F_41 ( V_142 -> V_48 ) ;
V_142 -> V_48 = V_127 ;
}
F_56 ( V_142 -> V_48 , V_143 ) ;
}
if ( ! F_68 ( V_142 -> V_48 , V_47 ) )
return - V_17 ;
F_69 ( V_142 -> V_48 , V_40 , V_47 ) ;
V_142 -> V_48 -> V_72 = V_144 ;
return 0 ;
}
static int
F_70 ( struct V_3 * V_32 ,
unsigned char V_145 , unsigned int V_146 )
{
int V_147 = 0 ;
F_27 ( & V_32 -> V_24 ) ;
switch ( V_145 ) {
case V_23 :
case V_70 :
V_32 -> V_22 = V_145 ;
V_32 -> V_21 = 0 ;
break;
case V_71 :
V_32 -> V_22 = V_145 ;
if ( V_146 > 0xffff )
V_32 -> V_21 = 0xffff ;
else
V_32 -> V_21 = V_146 ;
break;
default:
V_147 = - V_132 ;
}
F_29 ( & V_32 -> V_24 ) ;
return V_147 ;
}
static int
F_71 ( struct V_33 * V_34 , unsigned long V_91 )
{
if ( V_34 -> V_59 )
if ( V_34 -> V_59 -> V_91 == V_91 )
return 1 ;
if ( V_34 -> V_60 )
if ( V_34 -> V_60 -> V_91 == V_91 )
return 1 ;
#ifdef F_35
if ( V_34 -> V_48 -> V_97 ) {
if ( V_34 -> V_48 -> V_97 -> V_98 &&
V_34 -> V_48 -> V_97 -> V_98 -> V_91 == V_91 )
return 1 ;
if ( V_34 -> V_48 -> V_97 -> V_101 &&
V_34 -> V_48 -> V_97 -> V_101 -> V_91 == V_91 )
return 1 ;
}
#endif
return 0 ;
}
static void
F_72 ( int V_91 )
{
int V_38 ;
F_73 () ;
for ( V_38 = 0 ; V_38 < V_2 ; V_38 ++ ) {
struct V_6 * V_148 ;
struct V_3 * V_8 ;
struct V_4 * V_5 = & V_9 [ V_38 ] ;
F_3 (inst, tmp, head, hlist)
F_16 ( V_8 , F_71 , V_91 ) ;
}
F_74 () ;
}
static int
F_75 ( struct V_149 * V_150 ,
unsigned long V_151 , void * V_152 )
{
struct V_58 * V_96 = V_152 ;
if ( ! F_76 ( F_77 ( V_96 ) , & V_137 ) )
return V_153 ;
if ( V_151 == V_154 )
F_72 ( V_96 -> V_91 ) ;
return V_153 ;
}
static int
F_78 ( struct V_149 * V_150 ,
unsigned long V_151 , void * V_152 )
{
struct V_155 * V_156 = V_152 ;
if ( V_151 == V_157 && V_156 -> V_87 == V_158 ) {
int V_38 ;
F_5 ( & V_13 ) ;
for ( V_38 = 0 ; V_38 < V_2 ; V_38 ++ ) {
struct V_6 * V_148 , * V_159 ;
struct V_3 * V_8 ;
struct V_4 * V_5 = & V_9 [ V_38 ] ;
F_79 (inst, tmp, t2, head, hlist) {
if ( ( V_156 -> V_160 == & V_137 ) &&
( V_156 -> V_10 == V_8 -> V_18 ) )
F_18 ( V_8 ) ;
}
}
F_11 ( & V_13 ) ;
}
return V_153 ;
}
static struct V_3 * F_80 ( T_7 V_1 , int V_161 )
{
struct V_3 * V_32 ;
V_32 = F_2 ( V_1 ) ;
if ( ! V_32 )
return F_13 ( - V_162 ) ;
if ( V_32 -> V_18 != V_161 )
return F_13 ( - V_163 ) ;
return V_32 ;
}
static struct V_164 *
F_81 ( const struct V_49 * const V_165 [] )
{
struct V_164 * V_166 ;
unsigned int V_167 ;
if ( ! V_165 [ V_168 ] )
return NULL ;
V_166 = F_45 ( V_165 [ V_168 ] ) ;
V_167 = F_82 ( V_166 -> V_167 ) & V_169 ;
if ( V_167 > V_170 || V_167 == V_171 )
return NULL ;
return V_166 ;
}
static int F_83 ( unsigned int V_37 , unsigned int V_172 )
{
return ( int ) ( V_37 - V_172 ) > 0 ;
}
static int
F_84 ( struct V_173 * V_174 , struct V_43 * V_48 ,
const struct V_53 * V_54 ,
const struct V_49 * const V_165 [] )
{
struct V_55 * V_56 = F_42 ( V_54 ) ;
struct V_33 * V_34 , * V_148 ;
unsigned int V_167 , V_175 ;
struct V_164 * V_166 ;
struct V_3 * V_32 ;
F_85 ( V_176 ) ;
T_7 V_1 = F_86 ( V_56 -> V_84 ) ;
V_32 = F_80 ( V_1 , F_87 ( V_48 ) . V_10 ) ;
if ( F_88 ( V_32 ) )
return F_89 ( V_32 ) ;
V_166 = F_81 ( V_165 ) ;
if ( ! V_166 )
return - V_132 ;
V_167 = F_82 ( V_166 -> V_167 ) ;
V_175 = F_82 ( V_166 -> V_37 ) ;
F_27 ( & V_32 -> V_24 ) ;
F_30 (entry, tmp, &queue->queue_list, list) {
if ( F_83 ( V_34 -> V_37 , V_175 ) )
break;
F_24 ( V_32 , V_34 ) ;
F_23 ( & V_34 -> V_35 , & V_176 ) ;
}
F_29 ( & V_32 -> V_24 ) ;
if ( F_90 ( & V_176 ) )
return - V_177 ;
F_30 (entry, tmp, &batch_list, list) {
if ( V_165 [ V_103 ] )
V_34 -> V_48 -> V_102 = F_82 ( F_91 ( V_165 [ V_103 ] ) ) ;
F_31 ( V_34 , V_167 ) ;
}
return 0 ;
}
static int
F_92 ( struct V_173 * V_174 , struct V_43 * V_48 ,
const struct V_53 * V_54 ,
const struct V_49 * const V_165 [] )
{
struct V_55 * V_56 = F_42 ( V_54 ) ;
T_2 V_1 = F_86 ( V_56 -> V_84 ) ;
struct V_164 * V_166 ;
struct V_3 * V_32 ;
unsigned int V_167 ;
struct V_33 * V_34 ;
enum V_63 V_64 ( V_65 ) ;
struct V_61 * V_62 = NULL ;
V_32 = F_2 ( V_1 ) ;
if ( ! V_32 )
V_32 = F_80 ( V_1 , F_87 ( V_48 ) . V_10 ) ;
if ( F_88 ( V_32 ) )
return F_89 ( V_32 ) ;
V_166 = F_81 ( V_165 ) ;
if ( ! V_166 )
return - V_132 ;
V_167 = F_82 ( V_166 -> V_167 ) ;
V_34 = F_26 ( V_32 , F_82 ( V_166 -> V_37 ) ) ;
if ( V_34 == NULL )
return - V_177 ;
F_73 () ;
if ( V_165 [ V_178 ] && ( V_32 -> V_75 & V_76 ) )
V_62 = F_93 ( V_34 -> V_48 , V_165 [ V_178 ] , & V_65 ) ;
if ( V_165 [ V_123 ] ) {
T_7 V_179 = V_124 ( V_165 [ V_123 ] ) ;
int V_143 = V_179 - V_34 -> V_48 -> V_74 ;
if ( F_64 ( F_45 ( V_165 [ V_123 ] ) ,
V_179 , V_34 , V_143 ) < 0 )
V_167 = V_42 ;
if ( V_62 )
F_94 ( V_48 , V_62 , V_65 , V_143 ) ;
}
F_74 () ;
if ( V_165 [ V_103 ] )
V_34 -> V_48 -> V_102 = F_82 ( F_91 ( V_165 [ V_103 ] ) ) ;
F_31 ( V_34 , V_167 ) ;
return 0 ;
}
static int
F_95 ( struct V_173 * V_174 , struct V_43 * V_48 ,
const struct V_53 * V_54 ,
const struct V_49 * const V_165 [] )
{
return - V_180 ;
}
static int
F_96 ( struct V_173 * V_174 , struct V_43 * V_48 ,
const struct V_53 * V_54 ,
const struct V_49 * const V_165 [] )
{
struct V_55 * V_56 = F_42 ( V_54 ) ;
T_2 V_1 = F_86 ( V_56 -> V_84 ) ;
struct V_3 * V_32 ;
struct V_181 * V_182 = NULL ;
int V_183 = 0 ;
if ( V_165 [ V_184 ] ) {
V_182 = F_45 ( V_165 [ V_184 ] ) ;
switch ( V_182 -> V_185 ) {
case V_186 :
return F_97 ( F_86 ( V_182 -> V_81 ) ,
& V_187 ) ;
case V_188 :
return F_98 ( F_86 ( V_182 -> V_81 ) ,
& V_187 ) ;
}
}
F_73 () ;
V_32 = F_2 ( V_1 ) ;
if ( V_32 && V_32 -> V_18 != F_87 ( V_48 ) . V_10 ) {
V_183 = - V_163 ;
goto V_140;
}
if ( V_182 != NULL ) {
switch ( V_182 -> V_185 ) {
case V_189 :
if ( V_32 ) {
V_183 = - V_190 ;
goto V_140;
}
V_32 = F_4 ( V_1 , F_87 ( V_48 ) . V_10 ) ;
if ( F_88 ( V_32 ) ) {
V_183 = F_89 ( V_32 ) ;
goto V_140;
}
break;
case V_191 :
if ( ! V_32 ) {
V_183 = - V_162 ;
goto V_140;
}
F_21 ( V_32 ) ;
break;
case V_186 :
case V_188 :
break;
default:
V_183 = - V_180 ;
break;
}
}
if ( V_165 [ V_192 ] ) {
struct V_193 * V_194 ;
if ( ! V_32 ) {
V_183 = - V_162 ;
goto V_140;
}
V_194 = F_45 ( V_165 [ V_192 ] ) ;
F_70 ( V_32 , V_194 -> V_22 ,
F_82 ( V_194 -> V_21 ) ) ;
}
if ( V_165 [ V_195 ] ) {
T_4 * V_19 ;
if ( ! V_32 ) {
V_183 = - V_162 ;
goto V_140;
}
V_19 = F_45 ( V_165 [ V_195 ] ) ;
F_27 ( & V_32 -> V_24 ) ;
V_32 -> V_19 = F_82 ( * V_19 ) ;
F_29 ( & V_32 -> V_24 ) ;
}
if ( V_165 [ V_196 ] ) {
T_8 V_75 , V_197 ;
if ( ! V_32 ) {
V_183 = - V_162 ;
goto V_140;
}
if ( ! V_165 [ V_198 ] ) {
V_183 = - V_132 ;
goto V_140;
}
V_75 = F_82 ( F_91 ( V_165 [ V_196 ] ) ) ;
V_197 = F_82 ( F_91 ( V_165 [ V_198 ] ) ) ;
if ( V_75 >= V_199 ) {
V_183 = - V_200 ;
goto V_140;
}
F_27 ( & V_32 -> V_24 ) ;
V_32 -> V_75 &= ~ V_197 ;
V_32 -> V_75 |= V_75 & V_197 ;
F_29 ( & V_32 -> V_24 ) ;
}
V_140:
F_74 () ;
return V_183 ;
}
static struct V_6 * F_99 ( struct V_201 * V_202 )
{
struct V_203 * V_204 = V_202 -> V_205 ;
if ( ! V_204 )
return NULL ;
for ( V_204 -> V_206 = 0 ; V_204 -> V_206 < V_2 ; V_204 -> V_206 ++ ) {
if ( ! F_100 ( & V_9 [ V_204 -> V_206 ] ) )
return V_9 [ V_204 -> V_206 ] . V_207 ;
}
return NULL ;
}
static struct V_6 * F_101 ( struct V_201 * V_202 , struct V_6 * V_11 )
{
struct V_203 * V_204 = V_202 -> V_205 ;
V_11 = V_11 -> V_41 ;
while ( ! V_11 ) {
if ( ++ V_204 -> V_206 >= V_2 )
return NULL ;
V_11 = V_9 [ V_204 -> V_206 ] . V_207 ;
}
return V_11 ;
}
static struct V_6 * F_102 ( struct V_201 * V_202 , T_9 V_7 )
{
struct V_6 * V_5 ;
V_5 = F_99 ( V_202 ) ;
if ( V_5 )
while ( V_7 && ( V_5 = F_101 ( V_202 , V_5 ) ) )
V_7 -- ;
return V_7 ? NULL : V_5 ;
}
static void * F_103 ( struct V_201 * V_202 , T_9 * V_7 )
__acquires( V_13 )
{
F_5 ( & V_13 ) ;
return F_102 ( V_202 , * V_7 ) ;
}
static void * F_104 ( struct V_201 * V_208 , void * V_209 , T_9 * V_7 )
{
( * V_7 ) ++ ;
return F_101 ( V_208 , V_209 ) ;
}
static void F_105 ( struct V_201 * V_208 , void * V_209 )
__releases( V_13 )
{
F_11 ( & V_13 ) ;
}
static int F_106 ( struct V_201 * V_208 , void * V_209 )
{
const struct V_3 * V_8 = V_209 ;
return F_107 ( V_208 , L_6 ,
V_8 -> V_1 ,
V_8 -> V_18 , V_8 -> V_36 ,
V_8 -> V_22 , V_8 -> V_21 ,
V_8 -> V_135 , V_8 -> V_139 ,
V_8 -> V_136 , 1 ) ;
}
static int F_108 ( struct V_210 * V_210 , struct V_211 * V_211 )
{
return F_109 ( V_211 , & V_212 ,
sizeof( struct V_203 ) ) ;
}
static int T_10 F_110 ( void )
{
int V_38 , V_147 = - V_17 ;
for ( V_38 = 0 ; V_38 < V_2 ; V_38 ++ )
F_111 ( & V_9 [ V_38 ] ) ;
F_112 ( & V_213 ) ;
V_147 = F_113 ( & V_214 ) ;
if ( V_147 < 0 ) {
F_55 ( V_215 L_7 ) ;
goto V_216;
}
#ifdef F_114
if ( ! F_115 ( L_8 , 0440 ,
V_217 , & V_218 ) )
goto V_219;
#endif
F_116 ( & V_220 ) ;
return V_147 ;
#ifdef F_114
V_219:
F_117 ( & V_214 ) ;
#endif
V_216:
F_118 ( & V_213 ) ;
return V_147 ;
}
static void T_11 F_119 ( void )
{
F_120 ( & V_187 ) ;
F_121 ( & V_220 ) ;
#ifdef F_114
F_122 ( L_8 , V_217 ) ;
#endif
F_117 ( & V_214 ) ;
F_118 ( & V_213 ) ;
F_123 () ;
}
