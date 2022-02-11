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
static T_3 F_44 ( struct V_46 * V_57 , char * * V_71 )
{
T_3 V_72 = 0 ;
#if F_45 ( V_73 )
if ( ! V_57 || ! F_39 ( V_57 -> V_59 ) )
return 0 ;
F_40 ( & V_57 -> V_59 -> V_61 ) ;
if ( V_57 -> V_74 )
F_46 ( V_57 -> V_74 , V_71 , & V_72 ) ;
F_43 ( & V_57 -> V_59 -> V_61 ) ;
#endif
return V_72 ;
}
static struct V_46 *
F_47 ( struct V_2 * V_2 , struct V_6 * V_35 ,
struct V_36 * V_37 ,
T_6 * * V_75 )
{
T_7 V_76 ;
T_7 V_77 = 0 , V_78 = 0 ;
unsigned int V_79 = 0 ;
struct V_46 * V_57 ;
struct V_80 * V_81 ;
struct V_82 * V_83 ;
struct V_84 * V_85 ;
struct V_86 * V_87 ;
struct V_46 * V_88 = V_37 -> V_57 ;
struct V_89 * V_90 ;
struct V_89 * V_91 ;
struct V_92 * V_93 = NULL ;
enum V_94 V_95 ( V_96 ) ;
bool V_49 ;
char * V_71 = NULL ;
T_3 V_72 = 0 ;
V_76 = F_48 ( sizeof( struct V_86 ) )
+ F_49 ( sizeof( struct V_82 ) )
+ F_49 ( sizeof( V_97 ) )
+ F_49 ( sizeof( V_97 ) )
#if F_45 ( V_98 )
+ F_49 ( sizeof( V_97 ) )
+ F_49 ( sizeof( V_97 ) )
#endif
+ F_49 ( sizeof( V_97 ) )
+ F_49 ( sizeof( struct V_99 ) )
+ F_49 ( sizeof( V_97 ) )
+ F_49 ( sizeof( V_97 ) ) ;
if ( V_88 -> V_100 . V_101 )
V_76 += F_49 ( sizeof( struct V_102 ) ) ;
if ( V_37 -> V_103 . V_104 <= V_105 ||
( V_37 -> V_103 . V_104 == V_106 && V_88 -> V_59 == NULL ) )
V_49 = ! F_50 ( V_88 ) ;
else
V_49 = false ;
V_91 = V_37 -> V_103 . V_107 ;
switch ( (enum V_108 ) F_51 ( V_35 -> V_25 ) ) {
case V_109 :
case V_26 :
break;
case V_110 :
if ( ! ( V_35 -> V_50 & V_111 ) &&
V_88 -> V_51 == V_52 &&
F_52 ( V_88 ) )
return NULL ;
V_77 = F_51 ( V_35 -> V_23 ) ;
if ( V_77 > V_88 -> V_112 )
V_77 = V_88 -> V_112 ;
V_79 = F_53 ( V_88 ) ;
V_79 = F_54 (unsigned int, hlen, data_len) ;
V_76 += sizeof( struct V_80 ) + V_79 ;
V_78 = V_88 -> V_112 ;
break;
}
if ( V_35 -> V_50 & V_113 )
V_93 = F_55 ( V_88 , & V_76 , & V_96 ) ;
if ( V_35 -> V_50 & V_114 ) {
V_76 += ( F_49 ( sizeof( V_97 ) )
+ F_49 ( sizeof( V_97 ) ) ) ;
}
if ( ( V_35 -> V_50 & V_115 ) && V_88 -> V_59 ) {
V_72 = F_44 ( V_88 , & V_71 ) ;
if ( V_72 )
V_76 += F_49 ( V_72 ) ;
}
V_57 = F_56 ( V_2 , V_76 , V_35 -> V_20 ,
V_18 ) ;
if ( ! V_57 ) {
F_57 ( V_88 ) ;
return NULL ;
}
V_85 = F_58 ( V_57 , 0 , 0 ,
V_116 << 8 | V_117 ,
sizeof( struct V_86 ) , 0 ) ;
if ( ! V_85 ) {
F_57 ( V_88 ) ;
F_59 ( V_57 ) ;
return NULL ;
}
V_87 = F_60 ( V_85 ) ;
V_87 -> V_118 = V_37 -> V_103 . V_119 ;
V_87 -> V_120 = V_121 ;
V_87 -> V_122 = F_61 ( V_35 -> V_4 ) ;
V_81 = F_62 ( V_57 , V_123 , sizeof( * V_83 ) ) ;
V_83 = F_63 ( V_81 ) ;
V_83 -> V_124 = V_88 -> V_125 ;
V_83 -> V_104 = V_37 -> V_103 . V_104 ;
* V_75 = & V_83 -> V_126 ;
V_90 = V_37 -> V_103 . V_127 ;
if ( V_90 ) {
#if ! F_45 ( V_98 )
if ( F_36 ( V_57 , V_128 , F_37 ( V_90 -> V_129 ) ) )
goto V_68;
#else
if ( V_37 -> V_103 . V_119 == V_130 ) {
if ( F_36 ( V_57 , V_131 ,
F_37 ( V_90 -> V_129 ) ) ||
F_36 ( V_57 , V_128 ,
F_37 ( F_64 ( V_90 ) -> V_132 -> V_133 -> V_129 ) ) )
goto V_68;
} else {
int V_134 ;
if ( F_36 ( V_57 , V_128 ,
F_37 ( V_90 -> V_129 ) ) )
goto V_68;
V_134 = F_65 ( V_88 ) ;
if ( V_134 &&
F_36 ( V_57 , V_131 ,
F_37 ( V_134 ) ) )
goto V_68;
}
#endif
}
if ( V_91 ) {
#if ! F_45 ( V_98 )
if ( F_36 ( V_57 , V_135 , F_37 ( V_91 -> V_129 ) ) )
goto V_68;
#else
if ( V_37 -> V_103 . V_119 == V_130 ) {
if ( F_36 ( V_57 , V_136 ,
F_37 ( V_91 -> V_129 ) ) ||
F_36 ( V_57 , V_135 ,
F_37 ( F_64 ( V_91 ) -> V_132 -> V_133 -> V_129 ) ) )
goto V_68;
} else {
int V_137 ;
if ( F_36 ( V_57 , V_135 ,
F_37 ( V_91 -> V_129 ) ) )
goto V_68;
V_137 = F_66 ( V_88 ) ;
if ( V_137 &&
F_36 ( V_57 , V_136 ,
F_37 ( V_137 ) ) )
goto V_68;
}
#endif
}
if ( V_88 -> V_138 &&
F_36 ( V_57 , V_139 , F_37 ( V_88 -> V_138 ) ) )
goto V_68;
if ( V_90 && V_88 -> V_133 &&
V_88 -> V_140 != V_88 -> V_141 ) {
struct V_99 V_142 ;
int V_112 ;
memset ( & V_142 , 0 , sizeof( V_142 ) ) ;
V_112 = F_67 ( V_88 , V_142 . V_143 ) ;
if ( V_112 ) {
V_142 . V_144 = F_61 ( V_112 ) ;
if ( F_68 ( V_57 , V_145 , sizeof( V_142 ) , & V_142 ) )
goto V_68;
}
}
if ( V_88 -> V_100 . V_101 ) {
struct V_102 V_146 ;
struct V_147 V_148 = F_69 ( V_88 -> V_100 ) ;
V_146 . V_149 = F_70 ( V_148 . V_150 ) ;
V_146 . V_151 = F_70 ( V_148 . V_152 ) ;
if ( F_68 ( V_57 , V_153 , sizeof( V_146 ) , & V_146 ) )
goto V_68;
}
if ( ( V_35 -> V_50 & V_114 ) && V_88 -> V_59 &&
F_38 ( V_57 , V_88 -> V_59 ) < 0 )
goto V_68;
if ( V_72 && F_68 ( V_57 , V_154 , V_72 , V_71 ) )
goto V_68;
if ( V_93 && F_71 ( V_57 , V_93 , V_96 ) < 0 )
goto V_68;
if ( V_78 > V_77 &&
F_36 ( V_57 , V_155 , F_37 ( V_78 ) ) )
goto V_68;
if ( F_34 ( V_57 , V_88 , V_49 ) )
goto V_68;
if ( V_77 ) {
struct V_80 * V_81 ;
if ( F_72 ( V_57 ) < sizeof( * V_81 ) + V_79 )
goto V_68;
V_81 = (struct V_80 * ) F_73 ( V_57 , sizeof( * V_81 ) ) ;
V_81 -> V_156 = V_157 ;
V_81 -> V_158 = F_74 ( V_77 ) ;
if ( F_75 ( V_57 , V_88 , V_77 , V_79 ) )
goto V_68;
}
V_85 -> V_159 = V_57 -> V_112 ;
return V_57 ;
V_68:
F_57 ( V_88 ) ;
F_59 ( V_57 ) ;
F_76 ( L_1 ) ;
return NULL ;
}
static int
F_77 ( struct V_2 * V_2 , struct V_6 * V_35 ,
struct V_36 * V_37 )
{
struct V_46 * V_160 ;
int V_14 = - V_161 ;
T_6 * V_75 ;
int V_162 = 0 ;
V_160 = F_47 ( V_2 , V_35 , V_37 , & V_75 ) ;
if ( V_160 == NULL ) {
V_14 = - V_19 ;
goto V_163;
}
F_29 ( & V_35 -> V_27 ) ;
if ( V_35 -> V_39 >= V_35 -> V_21 ) {
if ( V_35 -> V_50 & V_164 ) {
V_162 = 1 ;
V_14 = 0 ;
} else {
V_35 -> V_165 ++ ;
F_78 ( L_2 ,
V_35 -> V_39 ) ;
}
goto V_166;
}
V_37 -> V_40 = ++ V_35 -> V_167 ;
* V_75 = F_37 ( V_37 -> V_40 ) ;
V_14 = F_79 ( V_160 , V_2 , V_35 -> V_20 , V_168 ) ;
if ( V_14 < 0 ) {
V_35 -> V_169 ++ ;
goto V_170;
}
F_24 ( V_35 , V_37 ) ;
F_31 ( & V_35 -> V_27 ) ;
return 0 ;
V_166:
F_59 ( V_160 ) ;
V_170:
F_31 ( & V_35 -> V_27 ) ;
if ( V_162 )
F_33 ( V_37 , V_171 ) ;
V_163:
return V_14 ;
}
static struct V_36 *
F_80 ( struct V_36 * V_172 )
{
struct V_36 * V_37 = F_81 ( V_172 , V_172 -> V_76 , V_18 ) ;
if ( V_37 ) {
if ( F_82 ( V_37 ) )
return V_37 ;
F_14 ( V_37 ) ;
}
return NULL ;
}
static void F_83 ( struct V_46 * V_57 )
{
if ( V_57 -> V_173 )
F_84 ( V_57 , V_57 -> V_141 - V_57 -> V_140 ) ;
}
static void F_85 ( struct V_46 * V_57 )
{
if ( V_57 -> V_173 )
F_86 ( V_57 , V_57 -> V_141 - V_57 -> V_140 ) ;
}
static void F_87 ( struct V_36 * V_37 )
{
F_88 ( V_37 ) ;
F_14 ( V_37 ) ;
}
static int
F_89 ( struct V_2 * V_2 , struct V_6 * V_35 ,
struct V_46 * V_57 , struct V_36 * V_37 )
{
int V_174 = - V_19 ;
struct V_36 * V_175 ;
F_85 ( V_57 ) ;
if ( V_57 -> V_44 == NULL ) {
struct V_46 * V_176 = V_37 -> V_57 ;
V_37 -> V_57 = V_57 ;
V_174 = F_77 ( V_2 , V_35 , V_37 ) ;
if ( V_174 )
V_37 -> V_57 = V_176 ;
return V_174 ;
}
V_57 -> V_44 = NULL ;
V_175 = F_80 ( V_37 ) ;
if ( V_175 ) {
V_175 -> V_57 = V_57 ;
V_174 = F_77 ( V_2 , V_35 , V_175 ) ;
if ( V_174 )
F_87 ( V_175 ) ;
}
return V_174 ;
}
static int
F_90 ( struct V_36 * V_37 , unsigned int V_177 )
{
unsigned int V_178 ;
struct V_6 * V_35 ;
struct V_46 * V_57 , * V_179 ;
int V_14 = - V_161 ;
struct V_2 * V_2 = F_91 ( V_37 -> V_103 . V_127 ?
V_37 -> V_103 . V_127 : V_37 -> V_103 . V_107 ) ;
struct V_1 * V_7 = F_1 ( V_2 ) ;
V_35 = F_4 ( V_7 , V_177 ) ;
if ( ! V_35 )
return - V_180 ;
if ( V_35 -> V_25 == V_26 )
return - V_181 ;
V_57 = V_37 -> V_57 ;
switch ( V_37 -> V_103 . V_119 ) {
case V_182 :
V_57 -> V_125 = F_61 ( V_183 ) ;
break;
case V_184 :
V_57 -> V_125 = F_61 ( V_185 ) ;
break;
}
if ( ( V_35 -> V_50 & V_111 ) || ! F_35 ( V_57 ) )
return F_77 ( V_2 , V_35 , V_37 ) ;
F_83 ( V_57 ) ;
V_179 = F_92 ( V_57 , 0 ) ;
if ( F_93 ( V_179 ) )
goto V_186;
V_178 = 0 ;
V_14 = 0 ;
do {
struct V_46 * V_160 = V_179 -> V_44 ;
if ( V_14 == 0 )
V_14 = F_89 ( V_2 , V_35 ,
V_179 , V_37 ) ;
if ( V_14 == 0 )
V_178 ++ ;
else
F_59 ( V_179 ) ;
V_179 = V_160 ;
} while ( V_179 );
if ( V_178 ) {
if ( V_14 )
F_87 ( V_37 ) ;
F_59 ( V_57 ) ;
return 0 ;
}
V_186:
F_85 ( V_57 ) ;
return V_14 ;
}
static int
F_94 ( void * V_43 , int V_77 , struct V_36 * V_172 , int V_187 )
{
struct V_46 * V_160 ;
if ( V_187 < 0 ) {
if ( F_95 ( V_172 -> V_57 , V_77 ) )
return - V_19 ;
} else if ( V_187 > 0 ) {
if ( V_77 > 0xFFFF )
return - V_181 ;
if ( V_187 > F_72 ( V_172 -> V_57 ) ) {
V_160 = F_96 ( V_172 -> V_57 , F_97 ( V_172 -> V_57 ) ,
V_187 , V_18 ) ;
if ( ! V_160 ) {
F_98 ( V_188 L_3
L_4 ) ;
return - V_19 ;
}
F_59 ( V_172 -> V_57 ) ;
V_172 -> V_57 = V_160 ;
}
F_73 ( V_172 -> V_57 , V_187 ) ;
}
if ( ! F_99 ( V_172 -> V_57 , V_77 ) )
return - V_19 ;
F_100 ( V_172 -> V_57 , V_43 , V_77 ) ;
V_172 -> V_57 -> V_51 = V_189 ;
return 0 ;
}
static int
F_101 ( struct V_6 * V_35 ,
unsigned char V_190 , unsigned int V_191 )
{
int V_192 = 0 ;
F_29 ( & V_35 -> V_27 ) ;
switch ( V_190 ) {
case V_26 :
case V_109 :
V_35 -> V_25 = V_190 ;
V_35 -> V_23 = 0 ;
break;
case V_110 :
V_35 -> V_25 = V_190 ;
if ( V_191 == 0 || V_191 > V_24 )
V_35 -> V_23 = V_24 ;
else
V_35 -> V_23 = V_191 ;
break;
default:
V_192 = - V_181 ;
}
F_31 ( & V_35 -> V_27 ) ;
return V_192 ;
}
static int
F_102 ( struct V_36 * V_37 , unsigned long V_129 )
{
if ( V_37 -> V_103 . V_127 )
if ( V_37 -> V_103 . V_127 -> V_129 == V_129 )
return 1 ;
if ( V_37 -> V_103 . V_107 )
if ( V_37 -> V_103 . V_107 -> V_129 == V_129 )
return 1 ;
#if F_45 ( V_98 )
if ( V_37 -> V_57 -> V_173 ) {
int V_134 , V_137 ;
V_134 = F_65 ( V_37 -> V_57 ) ;
V_137 = F_66 ( V_37 -> V_57 ) ;
if ( V_134 == V_129 || V_137 == V_129 )
return 1 ;
}
#endif
return 0 ;
}
static void
F_103 ( struct V_2 * V_2 , int V_129 )
{
int V_41 ;
struct V_1 * V_7 = F_1 ( V_2 ) ;
F_104 () ;
for ( V_41 = 0 ; V_41 < V_5 ; V_41 ++ ) {
struct V_6 * V_10 ;
struct V_8 * V_9 = & V_7 -> V_11 [ V_41 ] ;
F_5 (inst, head, hlist)
F_18 ( V_10 , F_102 , V_129 ) ;
}
F_105 () ;
}
static int
F_106 ( struct V_193 * V_194 ,
unsigned long V_195 , void * V_196 )
{
struct V_89 * V_133 = F_107 ( V_196 ) ;
if ( V_195 == V_197 )
F_103 ( F_91 ( V_133 ) , V_133 -> V_129 ) ;
return V_198 ;
}
static int F_108 ( struct V_36 * V_37 , unsigned long V_199 )
{
return V_37 -> V_200 == (struct V_201 * ) V_199 ;
}
static void F_109 ( struct V_2 * V_2 , struct V_201 * V_104 )
{
struct V_1 * V_7 = F_1 ( V_2 ) ;
int V_41 ;
F_104 () ;
for ( V_41 = 0 ; V_41 < V_5 ; V_41 ++ ) {
struct V_6 * V_10 ;
struct V_8 * V_9 = & V_7 -> V_11 [ V_41 ] ;
F_5 (inst, head, hlist)
F_18 ( V_10 , F_108 , ( unsigned long ) V_104 ) ;
}
F_105 () ;
}
static int
F_110 ( struct V_193 * V_194 ,
unsigned long V_195 , void * V_196 )
{
struct V_202 * V_203 = V_196 ;
struct V_1 * V_7 = F_1 ( V_203 -> V_2 ) ;
if ( V_195 == V_204 && V_203 -> V_125 == V_205 ) {
int V_41 ;
F_7 ( & V_7 -> V_15 ) ;
for ( V_41 = 0 ; V_41 < V_5 ; V_41 ++ ) {
struct V_206 * V_207 ;
struct V_6 * V_10 ;
struct V_8 * V_9 = & V_7 -> V_11 [ V_41 ] ;
F_111 (inst, t2, head, hlist) {
if ( V_203 -> V_12 == V_10 -> V_20 )
F_20 ( V_10 ) ;
}
}
F_13 ( & V_7 -> V_15 ) ;
}
return V_198 ;
}
static struct V_6 *
F_112 ( struct V_1 * V_7 , T_8 V_4 , T_3 V_208 )
{
struct V_6 * V_35 ;
V_35 = F_4 ( V_7 , V_4 ) ;
if ( ! V_35 )
return F_15 ( - V_209 ) ;
if ( V_35 -> V_20 != V_208 )
return F_15 ( - V_210 ) ;
return V_35 ;
}
static struct V_211 *
F_113 ( const struct V_80 * const V_212 [] )
{
struct V_211 * V_213 ;
unsigned int V_214 ;
if ( ! V_212 [ V_215 ] )
return NULL ;
V_213 = F_63 ( V_212 [ V_215 ] ) ;
V_214 = F_114 ( V_213 -> V_214 ) & V_216 ;
if ( V_214 > V_217 || V_214 == V_218 )
return NULL ;
return V_213 ;
}
static int F_115 ( unsigned int V_40 , unsigned int V_219 )
{
return ( int ) ( V_40 - V_219 ) > 0 ;
}
static int
F_116 ( struct V_58 * V_220 , struct V_46 * V_57 ,
const struct V_84 * V_85 ,
const struct V_80 * const V_212 [] )
{
struct V_86 * V_87 = F_60 ( V_85 ) ;
struct V_36 * V_37 , * V_221 ;
unsigned int V_214 , V_222 ;
struct V_211 * V_213 ;
struct V_6 * V_35 ;
F_117 ( V_223 ) ;
T_8 V_4 = F_118 ( V_87 -> V_122 ) ;
struct V_2 * V_2 = F_119 ( V_220 ) ;
struct V_1 * V_7 = F_1 ( V_2 ) ;
V_35 = F_112 ( V_7 , V_4 ,
F_120 ( V_57 ) . V_12 ) ;
if ( F_121 ( V_35 ) )
return F_122 ( V_35 ) ;
V_213 = F_113 ( V_212 ) ;
if ( ! V_213 )
return - V_181 ;
V_214 = F_114 ( V_213 -> V_214 ) ;
V_222 = F_114 ( V_213 -> V_40 ) ;
F_29 ( & V_35 -> V_27 ) ;
F_32 (entry, tmp, &queue->queue_list, list) {
if ( F_115 ( V_37 -> V_40 , V_222 ) )
break;
F_26 ( V_35 , V_37 ) ;
F_25 ( & V_37 -> V_38 , & V_223 ) ;
}
F_31 ( & V_35 -> V_27 ) ;
if ( F_123 ( & V_223 ) )
return - V_224 ;
F_32 (entry, tmp, &batch_list, list) {
if ( V_212 [ V_139 ] )
V_37 -> V_57 -> V_138 = F_114 ( F_124 ( V_212 [ V_139 ] ) ) ;
F_33 ( V_37 , V_214 ) ;
}
return 0 ;
}
static int
F_125 ( struct V_58 * V_220 , struct V_46 * V_57 ,
const struct V_84 * V_85 ,
const struct V_80 * const V_212 [] )
{
struct V_86 * V_87 = F_60 ( V_85 ) ;
T_2 V_4 = F_118 ( V_87 -> V_122 ) ;
struct V_211 * V_213 ;
struct V_6 * V_35 ;
unsigned int V_214 ;
struct V_36 * V_37 ;
enum V_94 V_95 ( V_96 ) ;
struct V_92 * V_93 = NULL ;
struct V_2 * V_2 = F_119 ( V_220 ) ;
struct V_1 * V_7 = F_1 ( V_2 ) ;
V_35 = F_4 ( V_7 , V_4 ) ;
if ( ! V_35 )
V_35 = F_112 ( V_7 , V_4 ,
F_120 ( V_57 ) . V_12 ) ;
if ( F_121 ( V_35 ) )
return F_122 ( V_35 ) ;
V_213 = F_113 ( V_212 ) ;
if ( ! V_213 )
return - V_181 ;
V_214 = F_114 ( V_213 -> V_214 ) ;
V_37 = F_28 ( V_35 , F_114 ( V_213 -> V_40 ) ) ;
if ( V_37 == NULL )
return - V_224 ;
if ( V_212 [ V_225 ] ) {
V_93 = F_126 ( V_37 -> V_57 , V_212 [ V_225 ] , & V_96 ) ;
if ( V_93 && V_212 [ V_226 ] ) {
F_127 ( V_93 , V_212 [ V_226 ] ,
F_120 ( V_57 ) . V_12 ,
F_128 ( V_85 ) ) ;
}
}
if ( V_212 [ V_157 ] ) {
T_8 V_227 = V_158 ( V_212 [ V_157 ] ) ;
int V_187 = V_227 - V_37 -> V_57 -> V_112 ;
if ( F_94 ( F_63 ( V_212 [ V_157 ] ) ,
V_227 , V_37 , V_187 ) < 0 )
V_214 = V_45 ;
if ( V_93 )
F_129 ( V_37 -> V_57 , V_93 , V_96 , V_187 ) ;
}
if ( V_212 [ V_139 ] )
V_37 -> V_57 -> V_138 = F_114 ( F_124 ( V_212 [ V_139 ] ) ) ;
F_33 ( V_37 , V_214 ) ;
return 0 ;
}
static int
F_130 ( struct V_58 * V_220 , struct V_46 * V_57 ,
const struct V_84 * V_85 ,
const struct V_80 * const V_212 [] )
{
return - V_228 ;
}
static int
F_131 ( struct V_58 * V_220 , struct V_46 * V_57 ,
const struct V_84 * V_85 ,
const struct V_80 * const V_212 [] )
{
struct V_86 * V_87 = F_60 ( V_85 ) ;
T_2 V_4 = F_118 ( V_87 -> V_122 ) ;
struct V_6 * V_35 ;
struct V_229 * V_230 = NULL ;
struct V_2 * V_2 = F_119 ( V_220 ) ;
struct V_1 * V_7 = F_1 ( V_2 ) ;
int V_174 = 0 ;
if ( V_212 [ V_231 ] ) {
V_230 = F_63 ( V_212 [ V_231 ] ) ;
switch ( V_230 -> V_232 ) {
case V_233 : return 0 ;
case V_234 : return 0 ;
}
}
F_104 () ;
V_35 = F_4 ( V_7 , V_4 ) ;
if ( V_35 && V_35 -> V_20 != F_120 ( V_57 ) . V_12 ) {
V_174 = - V_210 ;
goto V_170;
}
if ( V_230 != NULL ) {
switch ( V_230 -> V_232 ) {
case V_235 :
if ( V_35 ) {
V_174 = - V_236 ;
goto V_170;
}
V_35 = F_6 ( V_7 , V_4 ,
F_120 ( V_57 ) . V_12 ) ;
if ( F_121 ( V_35 ) ) {
V_174 = F_122 ( V_35 ) ;
goto V_170;
}
break;
case V_237 :
if ( ! V_35 ) {
V_174 = - V_209 ;
goto V_170;
}
F_23 ( V_7 , V_35 ) ;
break;
case V_233 :
case V_234 :
break;
default:
V_174 = - V_228 ;
break;
}
}
if ( V_212 [ V_238 ] ) {
struct V_239 * V_240 ;
if ( ! V_35 ) {
V_174 = - V_209 ;
goto V_170;
}
V_240 = F_63 ( V_212 [ V_238 ] ) ;
F_101 ( V_35 , V_240 -> V_25 ,
F_114 ( V_240 -> V_23 ) ) ;
}
if ( V_212 [ V_241 ] ) {
T_6 * V_21 ;
if ( ! V_35 ) {
V_174 = - V_209 ;
goto V_170;
}
V_21 = F_63 ( V_212 [ V_241 ] ) ;
F_29 ( & V_35 -> V_27 ) ;
V_35 -> V_21 = F_114 ( * V_21 ) ;
F_31 ( & V_35 -> V_27 ) ;
}
if ( V_212 [ V_242 ] ) {
T_5 V_50 , V_243 ;
if ( ! V_35 ) {
V_174 = - V_209 ;
goto V_170;
}
if ( ! V_212 [ V_244 ] ) {
V_174 = - V_181 ;
goto V_170;
}
V_50 = F_114 ( F_124 ( V_212 [ V_242 ] ) ) ;
V_243 = F_114 ( F_124 ( V_212 [ V_244 ] ) ) ;
if ( V_50 >= V_245 ) {
V_174 = - V_246 ;
goto V_170;
}
#if ! F_45 ( V_73 )
if ( V_50 & V_243 & V_115 ) {
V_174 = - V_246 ;
goto V_170;
}
#endif
F_29 ( & V_35 -> V_27 ) ;
V_35 -> V_50 &= ~ V_243 ;
V_35 -> V_50 |= V_50 & V_243 ;
F_31 ( & V_35 -> V_27 ) ;
}
V_170:
F_105 () ;
return V_174 ;
}
static struct V_206 * F_132 ( struct V_247 * V_248 )
{
struct V_249 * V_250 = V_248 -> V_251 ;
struct V_2 * V_2 ;
struct V_1 * V_7 ;
if ( ! V_250 )
return NULL ;
V_2 = F_133 ( V_248 ) ;
V_7 = F_1 ( V_2 ) ;
for ( V_250 -> V_252 = 0 ; V_250 -> V_252 < V_5 ; V_250 -> V_252 ++ ) {
if ( ! F_134 ( & V_7 -> V_11 [ V_250 -> V_252 ] ) )
return V_7 -> V_11 [ V_250 -> V_252 ] . V_253 ;
}
return NULL ;
}
static struct V_206 * F_135 ( struct V_247 * V_248 , struct V_206 * V_13 )
{
struct V_249 * V_250 = V_248 -> V_251 ;
struct V_2 * V_2 = F_133 ( V_248 ) ;
V_13 = V_13 -> V_44 ;
while ( ! V_13 ) {
struct V_1 * V_7 ;
if ( ++ V_250 -> V_252 >= V_5 )
return NULL ;
V_7 = F_1 ( V_2 ) ;
V_13 = V_7 -> V_11 [ V_250 -> V_252 ] . V_253 ;
}
return V_13 ;
}
static struct V_206 * F_136 ( struct V_247 * V_248 , T_9 V_254 )
{
struct V_206 * V_9 ;
V_9 = F_132 ( V_248 ) ;
if ( V_9 )
while ( V_254 && ( V_9 = F_135 ( V_248 , V_9 ) ) )
V_254 -- ;
return V_254 ? NULL : V_9 ;
}
static void * F_137 ( struct V_247 * V_255 , T_9 * V_254 )
__acquires( nfnl_queue_pernet( seq_file_net( V_255 )
static void * F_138 ( struct V_247 * V_255 , void * V_256 , T_9 * V_254 )
{
( * V_254 ) ++ ;
return F_135 ( V_255 , V_256 ) ;
}
static void F_139 ( struct V_247 * V_255 , void * V_256 )
__releases( nfnl_queue_pernet( seq_file_net( V_255 )
static int F_140 ( struct V_247 * V_255 , void * V_256 )
{
const struct V_6 * V_10 = V_256 ;
F_141 ( V_255 , L_5 ,
V_10 -> V_4 ,
V_10 -> V_20 , V_10 -> V_39 ,
V_10 -> V_25 , V_10 -> V_23 ,
V_10 -> V_165 , V_10 -> V_169 ,
V_10 -> V_167 , 1 ) ;
return 0 ;
}
static int F_142 ( struct V_257 * V_257 , struct V_63 * V_63 )
{
return F_143 ( V_257 , V_63 , & V_258 ,
sizeof( struct V_249 ) ) ;
}
static int T_10 F_144 ( struct V_2 * V_2 )
{
unsigned int V_41 ;
struct V_1 * V_7 = F_1 ( V_2 ) ;
for ( V_41 = 0 ; V_41 < V_5 ; V_41 ++ )
F_145 ( & V_7 -> V_11 [ V_41 ] ) ;
F_9 ( & V_7 -> V_15 ) ;
#ifdef F_146
if ( ! F_147 ( L_6 , 0440 ,
V_2 -> V_259 . V_260 , & V_261 ) )
return - V_19 ;
#endif
return 0 ;
}
static void T_11 F_148 ( struct V_2 * V_2 )
{
#ifdef F_146
F_149 ( L_6 , V_2 -> V_259 . V_260 ) ;
#endif
}
static int T_12 F_150 ( void )
{
int V_192 ;
V_192 = F_151 ( & V_262 ) ;
if ( V_192 < 0 ) {
F_152 ( L_7 ) ;
goto V_107;
}
F_153 ( & V_263 ) ;
V_192 = F_154 ( & V_264 ) ;
if ( V_192 < 0 ) {
F_152 ( L_8 ) ;
goto V_265;
}
F_155 ( & V_266 ) ;
F_156 ( & V_267 ) ;
return V_192 ;
V_265:
F_157 ( & V_263 ) ;
V_107:
return V_192 ;
}
static void T_13 F_158 ( void )
{
F_159 () ;
F_160 ( & V_266 ) ;
F_161 ( & V_264 ) ;
F_157 ( & V_263 ) ;
F_162 ( & V_262 ) ;
F_163 () ;
}
