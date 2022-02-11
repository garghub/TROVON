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
F_44 ( V_48 , V_84 , F_45 ( V_59 -> V_85 ) ) ;
#else
if ( V_34 -> V_75 == V_86 ) {
F_44 ( V_48 , V_87 ,
F_45 ( V_59 -> V_85 ) ) ;
F_44 ( V_48 , V_84 ,
F_45 ( F_46 ( V_59 ) -> V_88 -> V_89 -> V_85 ) ) ;
} else {
F_44 ( V_48 , V_84 ,
F_45 ( V_59 -> V_85 ) ) ;
if ( V_57 -> V_90 && V_57 -> V_90 -> V_91 )
F_44 ( V_48 , V_87 ,
F_45 ( V_57 -> V_90 -> V_91 -> V_85 ) ) ;
}
#endif
}
if ( V_60 ) {
#ifndef F_35
F_44 ( V_48 , V_92 , F_45 ( V_60 -> V_85 ) ) ;
#else
if ( V_34 -> V_75 == V_86 ) {
F_44 ( V_48 , V_93 ,
F_45 ( V_60 -> V_85 ) ) ;
F_44 ( V_48 , V_92 ,
F_45 ( F_46 ( V_60 ) -> V_88 -> V_89 -> V_85 ) ) ;
} else {
F_44 ( V_48 , V_92 ,
F_45 ( V_60 -> V_85 ) ) ;
if ( V_57 -> V_90 && V_57 -> V_90 -> V_94 )
F_44 ( V_48 , V_93 ,
F_45 ( V_57 -> V_90 -> V_94 -> V_85 ) ) ;
}
#endif
}
if ( V_57 -> V_95 )
F_44 ( V_48 , V_96 , F_45 ( V_57 -> V_95 ) ) ;
if ( V_59 && V_57 -> V_89 &&
V_57 -> V_97 != V_57 -> V_98 ) {
struct V_62 V_99 ;
int V_69 = F_47 ( V_57 , V_99 . V_100 ) ;
if ( V_69 ) {
V_99 . V_101 = F_41 ( V_69 ) ;
F_48 ( V_48 , V_102 , sizeof( V_99 ) , & V_99 ) ;
}
}
if ( V_57 -> V_103 . V_104 ) {
struct V_63 V_105 ;
struct V_106 V_107 = F_49 ( V_57 -> V_103 ) ;
V_105 . V_108 = F_50 ( V_107 . V_109 ) ;
V_105 . V_110 = F_50 ( V_107 . V_111 ) ;
F_48 ( V_48 , V_112 , sizeof( V_105 ) , & V_105 ) ;
}
if ( V_47 ) {
struct V_49 * V_50 ;
int V_113 = F_51 ( V_47 ) ;
if ( F_52 ( V_48 ) < F_34 ( V_47 ) ) {
F_53 ( V_114 L_1 ) ;
goto V_70;
}
V_50 = (struct V_49 * ) F_54 ( V_48 , F_34 ( V_47 ) ) ;
V_50 -> V_115 = V_116 ;
V_50 -> V_117 = V_113 ;
if ( F_55 ( V_57 , 0 , F_43 ( V_50 ) , V_47 ) )
F_56 () ;
}
V_54 -> V_118 = V_48 -> V_71 - V_45 ;
return V_48 ;
V_70:
V_119:
if ( V_48 )
F_57 ( V_48 ) ;
if ( F_58 () )
F_53 ( V_120 L_2 ) ;
return NULL ;
}
static int
F_59 ( struct V_33 * V_34 , unsigned int V_121 )
{
struct V_43 * V_122 ;
struct V_3 * V_32 ;
int V_12 = - V_123 ;
T_4 * V_44 ;
V_32 = F_2 ( V_121 ) ;
if ( ! V_32 ) {
V_12 = - V_124 ;
goto V_125;
}
if ( V_32 -> V_22 == V_23 ) {
V_12 = - V_126 ;
goto V_125;
}
V_122 = F_32 ( V_32 , V_34 , & V_44 ) ;
if ( V_122 == NULL ) {
V_12 = - V_17 ;
goto V_125;
}
F_27 ( & V_32 -> V_24 ) ;
if ( ! V_32 -> V_18 ) {
V_12 = - V_126 ;
goto V_127;
}
if ( V_32 -> V_36 >= V_32 -> V_19 ) {
V_32 -> V_128 ++ ;
if ( F_58 () )
F_53 ( V_114 L_3
L_4 ,
V_32 -> V_36 ) ;
goto V_127;
}
V_34 -> V_37 = ++ V_32 -> V_129 ;
* V_44 = F_45 ( V_34 -> V_37 ) ;
V_12 = F_60 ( V_122 , & V_130 , V_32 -> V_18 , V_131 ) ;
if ( V_12 < 0 ) {
V_32 -> V_132 ++ ;
goto V_133;
}
F_22 ( V_32 , V_34 ) ;
F_29 ( & V_32 -> V_24 ) ;
return 0 ;
V_127:
F_57 ( V_122 ) ;
V_133:
F_29 ( & V_32 -> V_24 ) ;
V_125:
return V_12 ;
}
static int
F_61 ( void * V_40 , int V_47 , struct V_33 * V_134 )
{
struct V_43 * V_122 ;
int V_135 ;
V_135 = V_47 - V_134 -> V_48 -> V_69 ;
if ( V_135 < 0 ) {
if ( F_62 ( V_134 -> V_48 , V_47 ) )
return - V_17 ;
} else if ( V_135 > 0 ) {
if ( V_47 > 0xFFFF )
return - V_126 ;
if ( V_135 > F_52 ( V_134 -> V_48 ) ) {
V_122 = F_63 ( V_134 -> V_48 , F_64 ( V_134 -> V_48 ) ,
V_135 , V_16 ) ;
if ( ! V_122 ) {
F_53 ( V_114 L_5
L_6 ) ;
return - V_17 ;
}
F_57 ( V_134 -> V_48 ) ;
V_134 -> V_48 = V_122 ;
}
F_54 ( V_134 -> V_48 , V_135 ) ;
}
if ( ! F_65 ( V_134 -> V_48 , V_47 ) )
return - V_17 ;
F_66 ( V_134 -> V_48 , V_40 , V_47 ) ;
V_134 -> V_48 -> V_67 = V_136 ;
return 0 ;
}
static int
F_67 ( struct V_3 * V_32 ,
unsigned char V_137 , unsigned int V_138 )
{
int V_139 = 0 ;
F_27 ( & V_32 -> V_24 ) ;
switch ( V_137 ) {
case V_23 :
case V_65 :
V_32 -> V_22 = V_137 ;
V_32 -> V_21 = 0 ;
break;
case V_66 :
V_32 -> V_22 = V_137 ;
if ( V_138 > 0xffff )
V_32 -> V_21 = 0xffff ;
else
V_32 -> V_21 = V_138 ;
break;
default:
V_139 = - V_126 ;
}
F_29 ( & V_32 -> V_24 ) ;
return V_139 ;
}
static int
F_68 ( struct V_33 * V_34 , unsigned long V_85 )
{
if ( V_34 -> V_59 )
if ( V_34 -> V_59 -> V_85 == V_85 )
return 1 ;
if ( V_34 -> V_60 )
if ( V_34 -> V_60 -> V_85 == V_85 )
return 1 ;
#ifdef F_35
if ( V_34 -> V_48 -> V_90 ) {
if ( V_34 -> V_48 -> V_90 -> V_91 &&
V_34 -> V_48 -> V_90 -> V_91 -> V_85 == V_85 )
return 1 ;
if ( V_34 -> V_48 -> V_90 -> V_94 &&
V_34 -> V_48 -> V_90 -> V_94 -> V_85 == V_85 )
return 1 ;
}
#endif
return 0 ;
}
static void
F_69 ( int V_85 )
{
int V_38 ;
F_70 () ;
for ( V_38 = 0 ; V_38 < V_2 ; V_38 ++ ) {
struct V_6 * V_140 ;
struct V_3 * V_8 ;
struct V_4 * V_5 = & V_9 [ V_38 ] ;
F_3 (inst, tmp, head, hlist)
F_16 ( V_8 , F_68 , V_85 ) ;
}
F_71 () ;
}
static int
F_72 ( struct V_141 * V_142 ,
unsigned long V_143 , void * V_144 )
{
struct V_58 * V_89 = V_144 ;
if ( ! F_73 ( F_74 ( V_89 ) , & V_130 ) )
return V_145 ;
if ( V_143 == V_146 )
F_69 ( V_89 -> V_85 ) ;
return V_145 ;
}
static int
F_75 ( struct V_141 * V_142 ,
unsigned long V_143 , void * V_144 )
{
struct V_147 * V_148 = V_144 ;
if ( V_143 == V_149 && V_148 -> V_81 == V_150 ) {
int V_38 ;
F_5 ( & V_13 ) ;
for ( V_38 = 0 ; V_38 < V_2 ; V_38 ++ ) {
struct V_6 * V_140 , * V_151 ;
struct V_3 * V_8 ;
struct V_4 * V_5 = & V_9 [ V_38 ] ;
F_76 (inst, tmp, t2, head, hlist) {
if ( ( V_148 -> V_152 == & V_130 ) &&
( V_148 -> V_10 == V_8 -> V_18 ) )
F_18 ( V_8 ) ;
}
}
F_11 ( & V_13 ) ;
}
return V_145 ;
}
static struct V_3 * F_77 ( T_7 V_1 , int V_153 )
{
struct V_3 * V_32 ;
V_32 = F_2 ( V_1 ) ;
if ( ! V_32 )
return F_13 ( - V_154 ) ;
if ( V_32 -> V_18 != V_153 )
return F_13 ( - V_155 ) ;
return V_32 ;
}
static struct V_156 *
F_78 ( const struct V_49 * const V_157 [] )
{
struct V_156 * V_158 ;
unsigned int V_159 ;
if ( ! V_157 [ V_160 ] )
return NULL ;
V_158 = F_43 ( V_157 [ V_160 ] ) ;
V_159 = F_79 ( V_158 -> V_159 ) & V_161 ;
if ( V_159 > V_162 || V_159 == V_163 )
return NULL ;
return V_158 ;
}
static int F_80 ( unsigned int V_37 , unsigned int V_164 )
{
return ( int ) ( V_37 - V_164 ) > 0 ;
}
static int
F_81 ( struct V_165 * V_166 , struct V_43 * V_48 ,
const struct V_53 * V_54 ,
const struct V_49 * const V_157 [] )
{
struct V_55 * V_56 = F_40 ( V_54 ) ;
struct V_33 * V_34 , * V_140 ;
unsigned int V_159 , V_167 ;
struct V_156 * V_158 ;
struct V_3 * V_32 ;
F_82 ( V_168 ) ;
T_7 V_1 = F_83 ( V_56 -> V_78 ) ;
V_32 = F_77 ( V_1 , F_84 ( V_48 ) . V_10 ) ;
if ( F_85 ( V_32 ) )
return F_86 ( V_32 ) ;
V_158 = F_78 ( V_157 ) ;
if ( ! V_158 )
return - V_126 ;
V_159 = F_79 ( V_158 -> V_159 ) ;
V_167 = F_79 ( V_158 -> V_37 ) ;
F_27 ( & V_32 -> V_24 ) ;
F_30 (entry, tmp, &queue->queue_list, list) {
if ( F_80 ( V_34 -> V_37 , V_167 ) )
break;
F_24 ( V_32 , V_34 ) ;
F_23 ( & V_34 -> V_35 , & V_168 ) ;
}
F_29 ( & V_32 -> V_24 ) ;
if ( F_87 ( & V_168 ) )
return - V_169 ;
F_30 (entry, tmp, &batch_list, list) {
if ( V_157 [ V_96 ] )
V_34 -> V_48 -> V_95 = F_79 ( F_88 ( V_157 [ V_96 ] ) ) ;
F_31 ( V_34 , V_159 ) ;
}
return 0 ;
}
static int
F_89 ( struct V_165 * V_166 , struct V_43 * V_48 ,
const struct V_53 * V_54 ,
const struct V_49 * const V_157 [] )
{
struct V_55 * V_56 = F_40 ( V_54 ) ;
T_2 V_1 = F_83 ( V_56 -> V_78 ) ;
struct V_156 * V_158 ;
struct V_3 * V_32 ;
unsigned int V_159 ;
struct V_33 * V_34 ;
V_32 = F_2 ( V_1 ) ;
if ( ! V_32 )
V_32 = F_77 ( V_1 , F_84 ( V_48 ) . V_10 ) ;
if ( F_85 ( V_32 ) )
return F_86 ( V_32 ) ;
V_158 = F_78 ( V_157 ) ;
if ( ! V_158 )
return - V_126 ;
V_159 = F_79 ( V_158 -> V_159 ) ;
V_34 = F_26 ( V_32 , F_79 ( V_158 -> V_37 ) ) ;
if ( V_34 == NULL )
return - V_169 ;
if ( V_157 [ V_116 ] ) {
if ( F_61 ( F_43 ( V_157 [ V_116 ] ) ,
V_117 ( V_157 [ V_116 ] ) , V_34 ) < 0 )
V_159 = V_42 ;
}
if ( V_157 [ V_96 ] )
V_34 -> V_48 -> V_95 = F_79 ( F_88 ( V_157 [ V_96 ] ) ) ;
F_31 ( V_34 , V_159 ) ;
return 0 ;
}
static int
F_90 ( struct V_165 * V_166 , struct V_43 * V_48 ,
const struct V_53 * V_54 ,
const struct V_49 * const V_157 [] )
{
return - V_170 ;
}
static int
F_91 ( struct V_165 * V_166 , struct V_43 * V_48 ,
const struct V_53 * V_54 ,
const struct V_49 * const V_157 [] )
{
struct V_55 * V_56 = F_40 ( V_54 ) ;
T_2 V_1 = F_83 ( V_56 -> V_78 ) ;
struct V_3 * V_32 ;
struct V_171 * V_172 = NULL ;
int V_173 = 0 ;
if ( V_157 [ V_174 ] ) {
V_172 = F_43 ( V_157 [ V_174 ] ) ;
switch ( V_172 -> V_175 ) {
case V_176 :
return F_92 ( F_83 ( V_172 -> V_75 ) ,
& V_177 ) ;
case V_178 :
return F_93 ( F_83 ( V_172 -> V_75 ) ,
& V_177 ) ;
}
}
F_70 () ;
V_32 = F_2 ( V_1 ) ;
if ( V_32 && V_32 -> V_18 != F_84 ( V_48 ) . V_10 ) {
V_173 = - V_155 ;
goto V_133;
}
if ( V_172 != NULL ) {
switch ( V_172 -> V_175 ) {
case V_179 :
if ( V_32 ) {
V_173 = - V_180 ;
goto V_133;
}
V_32 = F_4 ( V_1 , F_84 ( V_48 ) . V_10 ) ;
if ( F_85 ( V_32 ) ) {
V_173 = F_86 ( V_32 ) ;
goto V_133;
}
break;
case V_181 :
if ( ! V_32 ) {
V_173 = - V_154 ;
goto V_133;
}
F_21 ( V_32 ) ;
break;
case V_176 :
case V_178 :
break;
default:
V_173 = - V_170 ;
break;
}
}
if ( V_157 [ V_182 ] ) {
struct V_183 * V_184 ;
if ( ! V_32 ) {
V_173 = - V_154 ;
goto V_133;
}
V_184 = F_43 ( V_157 [ V_182 ] ) ;
F_67 ( V_32 , V_184 -> V_22 ,
F_79 ( V_184 -> V_21 ) ) ;
}
if ( V_157 [ V_185 ] ) {
T_4 * V_19 ;
if ( ! V_32 ) {
V_173 = - V_154 ;
goto V_133;
}
V_19 = F_43 ( V_157 [ V_185 ] ) ;
F_27 ( & V_32 -> V_24 ) ;
V_32 -> V_19 = F_79 ( * V_19 ) ;
F_29 ( & V_32 -> V_24 ) ;
}
V_133:
F_71 () ;
return V_173 ;
}
static struct V_6 * F_94 ( struct V_186 * V_187 )
{
struct V_188 * V_189 = V_187 -> V_190 ;
if ( ! V_189 )
return NULL ;
for ( V_189 -> V_191 = 0 ; V_189 -> V_191 < V_2 ; V_189 -> V_191 ++ ) {
if ( ! F_95 ( & V_9 [ V_189 -> V_191 ] ) )
return V_9 [ V_189 -> V_191 ] . V_192 ;
}
return NULL ;
}
static struct V_6 * F_96 ( struct V_186 * V_187 , struct V_6 * V_11 )
{
struct V_188 * V_189 = V_187 -> V_190 ;
V_11 = V_11 -> V_41 ;
while ( ! V_11 ) {
if ( ++ V_189 -> V_191 >= V_2 )
return NULL ;
V_11 = V_9 [ V_189 -> V_191 ] . V_192 ;
}
return V_11 ;
}
static struct V_6 * F_97 ( struct V_186 * V_187 , T_8 V_7 )
{
struct V_6 * V_5 ;
V_5 = F_94 ( V_187 ) ;
if ( V_5 )
while ( V_7 && ( V_5 = F_96 ( V_187 , V_5 ) ) )
V_7 -- ;
return V_7 ? NULL : V_5 ;
}
static void * F_98 ( struct V_186 * V_187 , T_8 * V_7 )
__acquires( V_13 )
{
F_5 ( & V_13 ) ;
return F_97 ( V_187 , * V_7 ) ;
}
static void * F_99 ( struct V_186 * V_193 , void * V_194 , T_8 * V_7 )
{
( * V_7 ) ++ ;
return F_96 ( V_193 , V_194 ) ;
}
static void F_100 ( struct V_186 * V_193 , void * V_194 )
__releases( V_13 )
{
F_11 ( & V_13 ) ;
}
static int F_101 ( struct V_186 * V_193 , void * V_194 )
{
const struct V_3 * V_8 = V_194 ;
return F_102 ( V_193 , L_7 ,
V_8 -> V_1 ,
V_8 -> V_18 , V_8 -> V_36 ,
V_8 -> V_22 , V_8 -> V_21 ,
V_8 -> V_128 , V_8 -> V_132 ,
V_8 -> V_129 , 1 ) ;
}
static int F_103 ( struct V_195 * V_195 , struct V_196 * V_196 )
{
return F_104 ( V_196 , & V_197 ,
sizeof( struct V_188 ) ) ;
}
static int T_9 F_105 ( void )
{
int V_38 , V_139 = - V_17 ;
for ( V_38 = 0 ; V_38 < V_2 ; V_38 ++ )
F_106 ( & V_9 [ V_38 ] ) ;
F_107 ( & V_198 ) ;
V_139 = F_108 ( & V_199 ) ;
if ( V_139 < 0 ) {
F_53 ( V_120 L_8 ) ;
goto V_200;
}
#ifdef F_109
if ( ! F_110 ( L_9 , 0440 ,
V_201 , & V_202 ) )
goto V_203;
#endif
F_111 ( & V_204 ) ;
return V_139 ;
#ifdef F_109
V_203:
F_112 ( & V_199 ) ;
#endif
V_200:
F_113 ( & V_198 ) ;
return V_139 ;
}
static void T_10 F_114 ( void )
{
F_115 ( & V_177 ) ;
F_116 ( & V_204 ) ;
#ifdef F_109
F_117 ( L_9 , V_201 ) ;
#endif
F_112 ( & V_199 ) ;
F_113 ( & V_198 ) ;
F_118 () ;
}
