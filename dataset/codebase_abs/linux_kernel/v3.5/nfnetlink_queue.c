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
V_46 = F_33 ( sizeof( struct V_55 ) )
+ F_34 ( sizeof( struct V_51 ) )
+ F_34 ( sizeof( V_61 ) )
+ F_34 ( sizeof( V_61 ) )
#ifdef F_35
+ F_34 ( sizeof( V_61 ) )
+ F_34 ( sizeof( V_61 ) )
#endif
+ F_34 ( sizeof( V_61 ) )
+ F_34 ( sizeof( struct V_62 ) )
+ F_34 ( sizeof( struct V_63 ) ) ;
V_60 = V_34 -> V_60 ;
switch ( (enum V_64 ) F_36 ( V_32 -> V_22 ) ) {
case V_65 :
case V_23 :
break;
case V_66 :
if ( V_57 -> V_67 == V_68 &&
F_37 ( V_57 ) )
return NULL ;
V_47 = F_36 ( V_32 -> V_21 ) ;
if ( V_47 == 0 || V_47 > V_57 -> V_69 )
V_47 = V_57 -> V_69 ;
V_46 += F_34 ( V_47 ) ;
break;
}
V_48 = F_38 ( V_46 , V_16 ) ;
if ( ! V_48 )
goto V_70;
V_45 = V_48 -> V_71 ;
V_54 = F_39 ( V_48 , 0 , 0 ,
V_72 << 8 | V_73 ,
sizeof( struct V_55 ) ) ;
V_56 = F_40 ( V_54 ) ;
V_56 -> V_74 = V_34 -> V_75 ;
V_56 -> V_76 = V_77 ;
V_56 -> V_78 = F_41 ( V_32 -> V_1 ) ;
V_50 = F_42 ( V_48 , V_79 , sizeof( * V_52 ) ) ;
V_52 = F_43 ( V_50 ) ;
V_52 -> V_80 = V_57 -> V_81 ;
V_52 -> V_82 = V_34 -> V_82 ;
* V_44 = & V_52 -> V_83 ;
V_59 = V_34 -> V_59 ;
if ( V_59 ) {
#ifndef F_35
if ( F_44 ( V_48 , V_84 , F_45 ( V_59 -> V_85 ) ) )
goto V_86;
#else
if ( V_34 -> V_75 == V_87 ) {
if ( F_44 ( V_48 , V_88 ,
F_45 ( V_59 -> V_85 ) ) ||
F_44 ( V_48 , V_84 ,
F_45 ( F_46 ( V_59 ) -> V_89 -> V_90 -> V_85 ) ) )
goto V_86;
} else {
if ( F_44 ( V_48 , V_84 ,
F_45 ( V_59 -> V_85 ) ) )
goto V_86;
if ( V_57 -> V_91 && V_57 -> V_91 -> V_92 &&
F_44 ( V_48 , V_88 ,
F_45 ( V_57 -> V_91 -> V_92 -> V_85 ) ) )
goto V_86;
}
#endif
}
if ( V_60 ) {
#ifndef F_35
if ( F_44 ( V_48 , V_93 , F_45 ( V_60 -> V_85 ) ) )
goto V_86;
#else
if ( V_34 -> V_75 == V_87 ) {
if ( F_44 ( V_48 , V_94 ,
F_45 ( V_60 -> V_85 ) ) ||
F_44 ( V_48 , V_93 ,
F_45 ( F_46 ( V_60 ) -> V_89 -> V_90 -> V_85 ) ) )
goto V_86;
} else {
if ( F_44 ( V_48 , V_93 ,
F_45 ( V_60 -> V_85 ) ) )
goto V_86;
if ( V_57 -> V_91 && V_57 -> V_91 -> V_95 &&
F_44 ( V_48 , V_94 ,
F_45 ( V_57 -> V_91 -> V_95 -> V_85 ) ) )
goto V_86;
}
#endif
}
if ( V_57 -> V_96 &&
F_44 ( V_48 , V_97 , F_45 ( V_57 -> V_96 ) ) )
goto V_86;
if ( V_59 && V_57 -> V_90 &&
V_57 -> V_98 != V_57 -> V_99 ) {
struct V_62 V_100 ;
int V_69 = F_47 ( V_57 , V_100 . V_101 ) ;
if ( V_69 ) {
V_100 . V_102 = F_41 ( V_69 ) ;
if ( F_48 ( V_48 , V_103 , sizeof( V_100 ) , & V_100 ) )
goto V_86;
}
}
if ( V_57 -> V_104 . V_105 ) {
struct V_63 V_106 ;
struct V_107 V_108 = F_49 ( V_57 -> V_104 ) ;
V_106 . V_109 = F_50 ( V_108 . V_110 ) ;
V_106 . V_111 = F_50 ( V_108 . V_112 ) ;
if ( F_48 ( V_48 , V_113 , sizeof( V_106 ) , & V_106 ) )
goto V_86;
}
if ( V_47 ) {
struct V_49 * V_50 ;
int V_114 = F_51 ( V_47 ) ;
if ( F_52 ( V_48 ) < F_34 ( V_47 ) ) {
F_53 ( V_115 L_1 ) ;
goto V_70;
}
V_50 = (struct V_49 * ) F_54 ( V_48 , F_34 ( V_47 ) ) ;
V_50 -> V_116 = V_117 ;
V_50 -> V_118 = V_114 ;
if ( F_55 ( V_57 , 0 , F_43 ( V_50 ) , V_47 ) )
F_56 () ;
}
V_54 -> V_119 = V_48 -> V_71 - V_45 ;
return V_48 ;
V_70:
V_86:
if ( V_48 )
F_57 ( V_48 ) ;
F_58 ( L_2 ) ;
return NULL ;
}
static int
F_59 ( struct V_33 * V_34 , unsigned int V_120 )
{
struct V_43 * V_121 ;
struct V_3 * V_32 ;
int V_12 = - V_122 ;
T_4 * V_44 ;
V_32 = F_2 ( V_120 ) ;
if ( ! V_32 ) {
V_12 = - V_123 ;
goto V_124;
}
if ( V_32 -> V_22 == V_23 ) {
V_12 = - V_125 ;
goto V_124;
}
V_121 = F_32 ( V_32 , V_34 , & V_44 ) ;
if ( V_121 == NULL ) {
V_12 = - V_17 ;
goto V_124;
}
F_27 ( & V_32 -> V_24 ) ;
if ( ! V_32 -> V_18 ) {
V_12 = - V_125 ;
goto V_126;
}
if ( V_32 -> V_36 >= V_32 -> V_19 ) {
V_32 -> V_127 ++ ;
F_60 ( L_3 ,
V_32 -> V_36 ) ;
goto V_126;
}
V_34 -> V_37 = ++ V_32 -> V_128 ;
* V_44 = F_45 ( V_34 -> V_37 ) ;
V_12 = F_61 ( V_121 , & V_129 , V_32 -> V_18 , V_130 ) ;
if ( V_12 < 0 ) {
V_32 -> V_131 ++ ;
goto V_132;
}
F_22 ( V_32 , V_34 ) ;
F_29 ( & V_32 -> V_24 ) ;
return 0 ;
V_126:
F_57 ( V_121 ) ;
V_132:
F_29 ( & V_32 -> V_24 ) ;
V_124:
return V_12 ;
}
static int
F_62 ( void * V_40 , int V_47 , struct V_33 * V_133 )
{
struct V_43 * V_121 ;
int V_134 ;
V_134 = V_47 - V_133 -> V_48 -> V_69 ;
if ( V_134 < 0 ) {
if ( F_63 ( V_133 -> V_48 , V_47 ) )
return - V_17 ;
} else if ( V_134 > 0 ) {
if ( V_47 > 0xFFFF )
return - V_125 ;
if ( V_134 > F_52 ( V_133 -> V_48 ) ) {
V_121 = F_64 ( V_133 -> V_48 , F_65 ( V_133 -> V_48 ) ,
V_134 , V_16 ) ;
if ( ! V_121 ) {
F_53 ( V_115 L_4
L_5 ) ;
return - V_17 ;
}
F_57 ( V_133 -> V_48 ) ;
V_133 -> V_48 = V_121 ;
}
F_54 ( V_133 -> V_48 , V_134 ) ;
}
if ( ! F_66 ( V_133 -> V_48 , V_47 ) )
return - V_17 ;
F_67 ( V_133 -> V_48 , V_40 , V_47 ) ;
V_133 -> V_48 -> V_67 = V_135 ;
return 0 ;
}
static int
F_68 ( struct V_3 * V_32 ,
unsigned char V_136 , unsigned int V_137 )
{
int V_138 = 0 ;
F_27 ( & V_32 -> V_24 ) ;
switch ( V_136 ) {
case V_23 :
case V_65 :
V_32 -> V_22 = V_136 ;
V_32 -> V_21 = 0 ;
break;
case V_66 :
V_32 -> V_22 = V_136 ;
if ( V_137 > 0xffff )
V_32 -> V_21 = 0xffff ;
else
V_32 -> V_21 = V_137 ;
break;
default:
V_138 = - V_125 ;
}
F_29 ( & V_32 -> V_24 ) ;
return V_138 ;
}
static int
F_69 ( struct V_33 * V_34 , unsigned long V_85 )
{
if ( V_34 -> V_59 )
if ( V_34 -> V_59 -> V_85 == V_85 )
return 1 ;
if ( V_34 -> V_60 )
if ( V_34 -> V_60 -> V_85 == V_85 )
return 1 ;
#ifdef F_35
if ( V_34 -> V_48 -> V_91 ) {
if ( V_34 -> V_48 -> V_91 -> V_92 &&
V_34 -> V_48 -> V_91 -> V_92 -> V_85 == V_85 )
return 1 ;
if ( V_34 -> V_48 -> V_91 -> V_95 &&
V_34 -> V_48 -> V_91 -> V_95 -> V_85 == V_85 )
return 1 ;
}
#endif
return 0 ;
}
static void
F_70 ( int V_85 )
{
int V_38 ;
F_71 () ;
for ( V_38 = 0 ; V_38 < V_2 ; V_38 ++ ) {
struct V_6 * V_139 ;
struct V_3 * V_8 ;
struct V_4 * V_5 = & V_9 [ V_38 ] ;
F_3 (inst, tmp, head, hlist)
F_16 ( V_8 , F_69 , V_85 ) ;
}
F_72 () ;
}
static int
F_73 ( struct V_140 * V_141 ,
unsigned long V_142 , void * V_143 )
{
struct V_58 * V_90 = V_143 ;
if ( ! F_74 ( F_75 ( V_90 ) , & V_129 ) )
return V_144 ;
if ( V_142 == V_145 )
F_70 ( V_90 -> V_85 ) ;
return V_144 ;
}
static int
F_76 ( struct V_140 * V_141 ,
unsigned long V_142 , void * V_143 )
{
struct V_146 * V_147 = V_143 ;
if ( V_142 == V_148 && V_147 -> V_81 == V_149 ) {
int V_38 ;
F_5 ( & V_13 ) ;
for ( V_38 = 0 ; V_38 < V_2 ; V_38 ++ ) {
struct V_6 * V_139 , * V_150 ;
struct V_3 * V_8 ;
struct V_4 * V_5 = & V_9 [ V_38 ] ;
F_77 (inst, tmp, t2, head, hlist) {
if ( ( V_147 -> V_151 == & V_129 ) &&
( V_147 -> V_10 == V_8 -> V_18 ) )
F_18 ( V_8 ) ;
}
}
F_11 ( & V_13 ) ;
}
return V_144 ;
}
static struct V_3 * F_78 ( T_7 V_1 , int V_152 )
{
struct V_3 * V_32 ;
V_32 = F_2 ( V_1 ) ;
if ( ! V_32 )
return F_13 ( - V_153 ) ;
if ( V_32 -> V_18 != V_152 )
return F_13 ( - V_154 ) ;
return V_32 ;
}
static struct V_155 *
F_79 ( const struct V_49 * const V_156 [] )
{
struct V_155 * V_157 ;
unsigned int V_158 ;
if ( ! V_156 [ V_159 ] )
return NULL ;
V_157 = F_43 ( V_156 [ V_159 ] ) ;
V_158 = F_80 ( V_157 -> V_158 ) & V_160 ;
if ( V_158 > V_161 || V_158 == V_162 )
return NULL ;
return V_157 ;
}
static int F_81 ( unsigned int V_37 , unsigned int V_163 )
{
return ( int ) ( V_37 - V_163 ) > 0 ;
}
static int
F_82 ( struct V_164 * V_165 , struct V_43 * V_48 ,
const struct V_53 * V_54 ,
const struct V_49 * const V_156 [] )
{
struct V_55 * V_56 = F_40 ( V_54 ) ;
struct V_33 * V_34 , * V_139 ;
unsigned int V_158 , V_166 ;
struct V_155 * V_157 ;
struct V_3 * V_32 ;
F_83 ( V_167 ) ;
T_7 V_1 = F_84 ( V_56 -> V_78 ) ;
V_32 = F_78 ( V_1 , F_85 ( V_48 ) . V_10 ) ;
if ( F_86 ( V_32 ) )
return F_87 ( V_32 ) ;
V_157 = F_79 ( V_156 ) ;
if ( ! V_157 )
return - V_125 ;
V_158 = F_80 ( V_157 -> V_158 ) ;
V_166 = F_80 ( V_157 -> V_37 ) ;
F_27 ( & V_32 -> V_24 ) ;
F_30 (entry, tmp, &queue->queue_list, list) {
if ( F_81 ( V_34 -> V_37 , V_166 ) )
break;
F_24 ( V_32 , V_34 ) ;
F_23 ( & V_34 -> V_35 , & V_167 ) ;
}
F_29 ( & V_32 -> V_24 ) ;
if ( F_88 ( & V_167 ) )
return - V_168 ;
F_30 (entry, tmp, &batch_list, list) {
if ( V_156 [ V_97 ] )
V_34 -> V_48 -> V_96 = F_80 ( F_89 ( V_156 [ V_97 ] ) ) ;
F_31 ( V_34 , V_158 ) ;
}
return 0 ;
}
static int
F_90 ( struct V_164 * V_165 , struct V_43 * V_48 ,
const struct V_53 * V_54 ,
const struct V_49 * const V_156 [] )
{
struct V_55 * V_56 = F_40 ( V_54 ) ;
T_2 V_1 = F_84 ( V_56 -> V_78 ) ;
struct V_155 * V_157 ;
struct V_3 * V_32 ;
unsigned int V_158 ;
struct V_33 * V_34 ;
V_32 = F_2 ( V_1 ) ;
if ( ! V_32 )
V_32 = F_78 ( V_1 , F_85 ( V_48 ) . V_10 ) ;
if ( F_86 ( V_32 ) )
return F_87 ( V_32 ) ;
V_157 = F_79 ( V_156 ) ;
if ( ! V_157 )
return - V_125 ;
V_158 = F_80 ( V_157 -> V_158 ) ;
V_34 = F_26 ( V_32 , F_80 ( V_157 -> V_37 ) ) ;
if ( V_34 == NULL )
return - V_168 ;
if ( V_156 [ V_117 ] ) {
if ( F_62 ( F_43 ( V_156 [ V_117 ] ) ,
V_118 ( V_156 [ V_117 ] ) , V_34 ) < 0 )
V_158 = V_42 ;
}
if ( V_156 [ V_97 ] )
V_34 -> V_48 -> V_96 = F_80 ( F_89 ( V_156 [ V_97 ] ) ) ;
F_31 ( V_34 , V_158 ) ;
return 0 ;
}
static int
F_91 ( struct V_164 * V_165 , struct V_43 * V_48 ,
const struct V_53 * V_54 ,
const struct V_49 * const V_156 [] )
{
return - V_169 ;
}
static int
F_92 ( struct V_164 * V_165 , struct V_43 * V_48 ,
const struct V_53 * V_54 ,
const struct V_49 * const V_156 [] )
{
struct V_55 * V_56 = F_40 ( V_54 ) ;
T_2 V_1 = F_84 ( V_56 -> V_78 ) ;
struct V_3 * V_32 ;
struct V_170 * V_171 = NULL ;
int V_172 = 0 ;
if ( V_156 [ V_173 ] ) {
V_171 = F_43 ( V_156 [ V_173 ] ) ;
switch ( V_171 -> V_174 ) {
case V_175 :
return F_93 ( F_84 ( V_171 -> V_75 ) ,
& V_176 ) ;
case V_177 :
return F_94 ( F_84 ( V_171 -> V_75 ) ,
& V_176 ) ;
}
}
F_71 () ;
V_32 = F_2 ( V_1 ) ;
if ( V_32 && V_32 -> V_18 != F_85 ( V_48 ) . V_10 ) {
V_172 = - V_154 ;
goto V_132;
}
if ( V_171 != NULL ) {
switch ( V_171 -> V_174 ) {
case V_178 :
if ( V_32 ) {
V_172 = - V_179 ;
goto V_132;
}
V_32 = F_4 ( V_1 , F_85 ( V_48 ) . V_10 ) ;
if ( F_86 ( V_32 ) ) {
V_172 = F_87 ( V_32 ) ;
goto V_132;
}
break;
case V_180 :
if ( ! V_32 ) {
V_172 = - V_153 ;
goto V_132;
}
F_21 ( V_32 ) ;
break;
case V_175 :
case V_177 :
break;
default:
V_172 = - V_169 ;
break;
}
}
if ( V_156 [ V_181 ] ) {
struct V_182 * V_183 ;
if ( ! V_32 ) {
V_172 = - V_153 ;
goto V_132;
}
V_183 = F_43 ( V_156 [ V_181 ] ) ;
F_68 ( V_32 , V_183 -> V_22 ,
F_80 ( V_183 -> V_21 ) ) ;
}
if ( V_156 [ V_184 ] ) {
T_4 * V_19 ;
if ( ! V_32 ) {
V_172 = - V_153 ;
goto V_132;
}
V_19 = F_43 ( V_156 [ V_184 ] ) ;
F_27 ( & V_32 -> V_24 ) ;
V_32 -> V_19 = F_80 ( * V_19 ) ;
F_29 ( & V_32 -> V_24 ) ;
}
V_132:
F_72 () ;
return V_172 ;
}
static struct V_6 * F_95 ( struct V_185 * V_186 )
{
struct V_187 * V_188 = V_186 -> V_189 ;
if ( ! V_188 )
return NULL ;
for ( V_188 -> V_190 = 0 ; V_188 -> V_190 < V_2 ; V_188 -> V_190 ++ ) {
if ( ! F_96 ( & V_9 [ V_188 -> V_190 ] ) )
return V_9 [ V_188 -> V_190 ] . V_191 ;
}
return NULL ;
}
static struct V_6 * F_97 ( struct V_185 * V_186 , struct V_6 * V_11 )
{
struct V_187 * V_188 = V_186 -> V_189 ;
V_11 = V_11 -> V_41 ;
while ( ! V_11 ) {
if ( ++ V_188 -> V_190 >= V_2 )
return NULL ;
V_11 = V_9 [ V_188 -> V_190 ] . V_191 ;
}
return V_11 ;
}
static struct V_6 * F_98 ( struct V_185 * V_186 , T_8 V_7 )
{
struct V_6 * V_5 ;
V_5 = F_95 ( V_186 ) ;
if ( V_5 )
while ( V_7 && ( V_5 = F_97 ( V_186 , V_5 ) ) )
V_7 -- ;
return V_7 ? NULL : V_5 ;
}
static void * F_99 ( struct V_185 * V_186 , T_8 * V_7 )
__acquires( V_13 )
{
F_5 ( & V_13 ) ;
return F_98 ( V_186 , * V_7 ) ;
}
static void * F_100 ( struct V_185 * V_192 , void * V_193 , T_8 * V_7 )
{
( * V_7 ) ++ ;
return F_97 ( V_192 , V_193 ) ;
}
static void F_101 ( struct V_185 * V_192 , void * V_193 )
__releases( V_13 )
{
F_11 ( & V_13 ) ;
}
static int F_102 ( struct V_185 * V_192 , void * V_193 )
{
const struct V_3 * V_8 = V_193 ;
return F_103 ( V_192 , L_6 ,
V_8 -> V_1 ,
V_8 -> V_18 , V_8 -> V_36 ,
V_8 -> V_22 , V_8 -> V_21 ,
V_8 -> V_127 , V_8 -> V_131 ,
V_8 -> V_128 , 1 ) ;
}
static int F_104 ( struct V_194 * V_194 , struct V_195 * V_195 )
{
return F_105 ( V_195 , & V_196 ,
sizeof( struct V_187 ) ) ;
}
static int T_9 F_106 ( void )
{
int V_38 , V_138 = - V_17 ;
for ( V_38 = 0 ; V_38 < V_2 ; V_38 ++ )
F_107 ( & V_9 [ V_38 ] ) ;
F_108 ( & V_197 ) ;
V_138 = F_109 ( & V_198 ) ;
if ( V_138 < 0 ) {
F_53 ( V_199 L_7 ) ;
goto V_200;
}
#ifdef F_110
if ( ! F_111 ( L_8 , 0440 ,
V_201 , & V_202 ) )
goto V_203;
#endif
F_112 ( & V_204 ) ;
return V_138 ;
#ifdef F_110
V_203:
F_113 ( & V_198 ) ;
#endif
V_200:
F_114 ( & V_197 ) ;
return V_138 ;
}
static void T_10 F_115 ( void )
{
F_116 ( & V_176 ) ;
F_117 ( & V_204 ) ;
#ifdef F_110
F_118 ( L_8 , V_201 ) ;
#endif
F_113 ( & V_198 ) ;
F_114 ( & V_197 ) ;
F_119 () ;
}
