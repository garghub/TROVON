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
T_7 V_77 = 0 , V_78 = 0 , V_79 = 0 ;
unsigned int V_80 = 0 ;
struct V_46 * V_57 ;
struct V_81 * V_82 ;
struct V_83 * V_84 ;
struct V_85 * V_86 ;
struct V_87 * V_88 ;
struct V_46 * V_89 = V_37 -> V_57 ;
struct V_90 * V_91 ;
struct V_90 * V_92 ;
struct V_93 * V_94 = NULL ;
enum V_95 V_96 ( V_97 ) ;
bool V_49 ;
char * V_71 = NULL ;
T_3 V_72 = 0 ;
V_76 = F_48 ( sizeof( struct V_87 ) )
+ F_49 ( sizeof( struct V_83 ) )
+ F_49 ( sizeof( V_98 ) )
+ F_49 ( sizeof( V_98 ) )
#if F_45 ( V_99 )
+ F_49 ( sizeof( V_98 ) )
+ F_49 ( sizeof( V_98 ) )
#endif
+ F_49 ( sizeof( V_98 ) )
+ F_49 ( sizeof( struct V_100 ) )
+ F_49 ( sizeof( V_98 ) )
+ F_49 ( sizeof( V_98 ) ) ;
if ( V_89 -> V_101 . V_102 )
V_76 += F_49 ( sizeof( struct V_103 ) ) ;
if ( V_37 -> V_104 . V_105 <= V_106 ||
( V_37 -> V_104 . V_105 == V_107 && V_89 -> V_59 == NULL ) )
V_49 = ! F_50 ( V_89 ) ;
else
V_49 = false ;
V_92 = V_37 -> V_104 . V_108 ;
switch ( (enum V_109 ) F_51 ( V_35 -> V_25 ) ) {
case V_110 :
case V_26 :
break;
case V_111 :
if ( ! ( V_35 -> V_50 & V_112 ) &&
V_89 -> V_51 == V_52 &&
F_52 ( V_89 ) )
return NULL ;
V_77 = F_51 ( V_35 -> V_23 ) ;
if ( V_77 > V_89 -> V_113 )
V_77 = V_89 -> V_113 ;
V_80 = F_53 ( V_89 ) ;
V_80 = F_54 (unsigned int, hlen, data_len) ;
V_76 += sizeof( struct V_81 ) + V_80 ;
V_78 = V_89 -> V_113 ;
V_79 = V_77 - V_80 ;
break;
}
if ( V_35 -> V_50 & V_114 )
V_94 = F_55 ( V_89 , & V_76 , & V_97 ) ;
if ( V_35 -> V_50 & V_115 ) {
V_76 += ( F_49 ( sizeof( V_98 ) )
+ F_49 ( sizeof( V_98 ) ) ) ;
}
if ( ( V_35 -> V_50 & V_116 ) && V_89 -> V_59 ) {
V_72 = F_44 ( V_89 , & V_71 ) ;
if ( V_72 )
V_76 += F_49 ( V_72 ) ;
}
V_57 = F_56 ( V_2 -> V_117 , V_76 , V_79 , V_35 -> V_20 ,
V_18 ) ;
if ( ! V_57 ) {
F_57 ( V_89 ) ;
return NULL ;
}
V_86 = F_58 ( V_57 , 0 , 0 ,
V_118 << 8 | V_119 ,
sizeof( struct V_87 ) , 0 ) ;
if ( ! V_86 ) {
F_57 ( V_89 ) ;
F_59 ( V_57 ) ;
return NULL ;
}
V_88 = F_60 ( V_86 ) ;
V_88 -> V_120 = V_37 -> V_104 . V_121 ;
V_88 -> V_122 = V_123 ;
V_88 -> V_124 = F_61 ( V_35 -> V_4 ) ;
V_82 = F_62 ( V_57 , V_125 , sizeof( * V_84 ) ) ;
V_84 = F_63 ( V_82 ) ;
V_84 -> V_126 = V_89 -> V_127 ;
V_84 -> V_105 = V_37 -> V_104 . V_105 ;
* V_75 = & V_84 -> V_128 ;
V_91 = V_37 -> V_104 . V_129 ;
if ( V_91 ) {
#if ! F_45 ( V_99 )
if ( F_36 ( V_57 , V_130 , F_37 ( V_91 -> V_131 ) ) )
goto V_68;
#else
if ( V_37 -> V_104 . V_121 == V_132 ) {
if ( F_36 ( V_57 , V_133 ,
F_37 ( V_91 -> V_131 ) ) ||
F_36 ( V_57 , V_130 ,
F_37 ( F_64 ( V_91 ) -> V_134 -> V_135 -> V_131 ) ) )
goto V_68;
} else {
int V_136 ;
if ( F_36 ( V_57 , V_130 ,
F_37 ( V_91 -> V_131 ) ) )
goto V_68;
V_136 = F_65 ( V_89 ) ;
if ( V_136 &&
F_36 ( V_57 , V_133 ,
F_37 ( V_136 ) ) )
goto V_68;
}
#endif
}
if ( V_92 ) {
#if ! F_45 ( V_99 )
if ( F_36 ( V_57 , V_137 , F_37 ( V_92 -> V_131 ) ) )
goto V_68;
#else
if ( V_37 -> V_104 . V_121 == V_132 ) {
if ( F_36 ( V_57 , V_138 ,
F_37 ( V_92 -> V_131 ) ) ||
F_36 ( V_57 , V_137 ,
F_37 ( F_64 ( V_92 ) -> V_134 -> V_135 -> V_131 ) ) )
goto V_68;
} else {
int V_139 ;
if ( F_36 ( V_57 , V_137 ,
F_37 ( V_92 -> V_131 ) ) )
goto V_68;
V_139 = F_66 ( V_89 ) ;
if ( V_139 &&
F_36 ( V_57 , V_138 ,
F_37 ( V_139 ) ) )
goto V_68;
}
#endif
}
if ( V_89 -> V_140 &&
F_36 ( V_57 , V_141 , F_37 ( V_89 -> V_140 ) ) )
goto V_68;
if ( V_91 && V_89 -> V_135 &&
V_89 -> V_142 != V_89 -> V_143 ) {
struct V_100 V_144 ;
int V_113 ;
memset ( & V_144 , 0 , sizeof( V_144 ) ) ;
V_113 = F_67 ( V_89 , V_144 . V_145 ) ;
if ( V_113 ) {
V_144 . V_146 = F_61 ( V_113 ) ;
if ( F_68 ( V_57 , V_147 , sizeof( V_144 ) , & V_144 ) )
goto V_68;
}
}
if ( V_89 -> V_101 . V_102 ) {
struct V_103 V_148 ;
struct V_149 V_150 = F_69 ( V_89 -> V_101 ) ;
V_148 . V_151 = F_70 ( V_150 . V_152 ) ;
V_148 . V_153 = F_70 ( V_150 . V_154 ) ;
if ( F_68 ( V_57 , V_155 , sizeof( V_148 ) , & V_148 ) )
goto V_68;
}
if ( ( V_35 -> V_50 & V_115 ) && V_89 -> V_59 &&
F_38 ( V_57 , V_89 -> V_59 ) < 0 )
goto V_68;
if ( V_72 && F_68 ( V_57 , V_156 , V_72 , V_71 ) )
goto V_68;
if ( V_94 && F_71 ( V_57 , V_94 , V_97 ) < 0 )
goto V_68;
if ( V_78 > V_77 &&
F_36 ( V_57 , V_157 , F_37 ( V_78 ) ) )
goto V_68;
if ( F_34 ( V_57 , V_89 , V_49 ) )
goto V_68;
if ( V_77 ) {
struct V_81 * V_82 ;
if ( F_72 ( V_57 ) < sizeof( * V_82 ) + V_80 )
goto V_68;
V_82 = (struct V_81 * ) F_73 ( V_57 , sizeof( * V_82 ) ) ;
V_82 -> V_158 = V_159 ;
V_82 -> V_160 = F_74 ( V_77 ) ;
if ( F_75 ( V_57 , V_89 , V_77 , V_80 ) )
goto V_68;
}
V_86 -> V_161 = V_57 -> V_113 ;
return V_57 ;
V_68:
F_57 ( V_89 ) ;
F_59 ( V_57 ) ;
F_76 ( L_1 ) ;
return NULL ;
}
static int
F_77 ( struct V_2 * V_2 , struct V_6 * V_35 ,
struct V_36 * V_37 )
{
struct V_46 * V_162 ;
int V_14 = - V_163 ;
T_6 * V_75 ;
int V_164 = 0 ;
V_162 = F_47 ( V_2 , V_35 , V_37 , & V_75 ) ;
if ( V_162 == NULL ) {
V_14 = - V_19 ;
goto V_165;
}
F_29 ( & V_35 -> V_27 ) ;
if ( V_35 -> V_39 >= V_35 -> V_21 ) {
if ( V_35 -> V_50 & V_166 ) {
V_164 = 1 ;
V_14 = 0 ;
} else {
V_35 -> V_167 ++ ;
F_78 ( L_2 ,
V_35 -> V_39 ) ;
}
goto V_168;
}
V_37 -> V_40 = ++ V_35 -> V_169 ;
* V_75 = F_37 ( V_37 -> V_40 ) ;
V_14 = F_79 ( V_162 , V_2 , V_35 -> V_20 , V_170 ) ;
if ( V_14 < 0 ) {
V_35 -> V_171 ++ ;
goto V_172;
}
F_24 ( V_35 , V_37 ) ;
F_31 ( & V_35 -> V_27 ) ;
return 0 ;
V_168:
F_59 ( V_162 ) ;
V_172:
F_31 ( & V_35 -> V_27 ) ;
if ( V_164 )
F_33 ( V_37 , V_173 ) ;
V_165:
return V_14 ;
}
static struct V_36 *
F_80 ( struct V_36 * V_174 )
{
struct V_36 * V_37 = F_81 ( V_174 , V_174 -> V_76 , V_18 ) ;
if ( V_37 ) {
if ( F_82 ( V_37 ) )
return V_37 ;
F_14 ( V_37 ) ;
}
return NULL ;
}
static void F_83 ( struct V_46 * V_57 )
{
if ( V_57 -> V_175 )
F_84 ( V_57 , V_57 -> V_143 - V_57 -> V_142 ) ;
}
static void F_85 ( struct V_46 * V_57 )
{
if ( V_57 -> V_175 )
F_86 ( V_57 , V_57 -> V_143 - V_57 -> V_142 ) ;
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
int V_176 = - V_19 ;
struct V_36 * V_177 ;
F_85 ( V_57 ) ;
if ( V_57 -> V_44 == NULL ) {
struct V_46 * V_178 = V_37 -> V_57 ;
V_37 -> V_57 = V_57 ;
V_176 = F_77 ( V_2 , V_35 , V_37 ) ;
if ( V_176 )
V_37 -> V_57 = V_178 ;
return V_176 ;
}
V_57 -> V_44 = NULL ;
V_177 = F_80 ( V_37 ) ;
if ( V_177 ) {
V_177 -> V_57 = V_57 ;
V_176 = F_77 ( V_2 , V_35 , V_177 ) ;
if ( V_176 )
F_87 ( V_177 ) ;
}
return V_176 ;
}
static int
F_90 ( struct V_36 * V_37 , unsigned int V_179 )
{
unsigned int V_180 ;
struct V_6 * V_35 ;
struct V_46 * V_57 , * V_181 ;
int V_14 = - V_163 ;
struct V_2 * V_2 = F_91 ( V_37 -> V_104 . V_129 ?
V_37 -> V_104 . V_129 : V_37 -> V_104 . V_108 ) ;
struct V_1 * V_7 = F_1 ( V_2 ) ;
V_35 = F_4 ( V_7 , V_179 ) ;
if ( ! V_35 )
return - V_182 ;
if ( V_35 -> V_25 == V_26 )
return - V_183 ;
V_57 = V_37 -> V_57 ;
switch ( V_37 -> V_104 . V_121 ) {
case V_184 :
V_57 -> V_127 = F_61 ( V_185 ) ;
break;
case V_186 :
V_57 -> V_127 = F_61 ( V_187 ) ;
break;
}
if ( ( V_35 -> V_50 & V_112 ) || ! F_35 ( V_57 ) )
return F_77 ( V_2 , V_35 , V_37 ) ;
F_83 ( V_57 ) ;
V_181 = F_92 ( V_57 , 0 ) ;
if ( F_93 ( V_181 ) )
goto V_188;
V_180 = 0 ;
V_14 = 0 ;
do {
struct V_46 * V_162 = V_181 -> V_44 ;
if ( V_14 == 0 )
V_14 = F_89 ( V_2 , V_35 ,
V_181 , V_37 ) ;
if ( V_14 == 0 )
V_180 ++ ;
else
F_59 ( V_181 ) ;
V_181 = V_162 ;
} while ( V_181 );
if ( V_180 ) {
if ( V_14 )
F_87 ( V_37 ) ;
F_59 ( V_57 ) ;
return 0 ;
}
V_188:
F_85 ( V_57 ) ;
return V_14 ;
}
static int
F_94 ( void * V_43 , int V_77 , struct V_36 * V_174 , int V_189 )
{
struct V_46 * V_162 ;
if ( V_189 < 0 ) {
if ( F_95 ( V_174 -> V_57 , V_77 ) )
return - V_19 ;
} else if ( V_189 > 0 ) {
if ( V_77 > 0xFFFF )
return - V_183 ;
if ( V_189 > F_72 ( V_174 -> V_57 ) ) {
V_162 = F_96 ( V_174 -> V_57 , F_97 ( V_174 -> V_57 ) ,
V_189 , V_18 ) ;
if ( ! V_162 ) {
F_98 ( V_190 L_3
L_4 ) ;
return - V_19 ;
}
F_59 ( V_174 -> V_57 ) ;
V_174 -> V_57 = V_162 ;
}
F_73 ( V_174 -> V_57 , V_189 ) ;
}
if ( ! F_99 ( V_174 -> V_57 , V_77 ) )
return - V_19 ;
F_100 ( V_174 -> V_57 , V_43 , V_77 ) ;
V_174 -> V_57 -> V_51 = V_191 ;
return 0 ;
}
static int
F_101 ( struct V_6 * V_35 ,
unsigned char V_192 , unsigned int V_193 )
{
int V_194 = 0 ;
F_29 ( & V_35 -> V_27 ) ;
switch ( V_192 ) {
case V_26 :
case V_110 :
V_35 -> V_25 = V_192 ;
V_35 -> V_23 = 0 ;
break;
case V_111 :
V_35 -> V_25 = V_192 ;
if ( V_193 == 0 || V_193 > V_24 )
V_35 -> V_23 = V_24 ;
else
V_35 -> V_23 = V_193 ;
break;
default:
V_194 = - V_183 ;
}
F_31 ( & V_35 -> V_27 ) ;
return V_194 ;
}
static int
F_102 ( struct V_36 * V_37 , unsigned long V_131 )
{
if ( V_37 -> V_104 . V_129 )
if ( V_37 -> V_104 . V_129 -> V_131 == V_131 )
return 1 ;
if ( V_37 -> V_104 . V_108 )
if ( V_37 -> V_104 . V_108 -> V_131 == V_131 )
return 1 ;
#if F_45 ( V_99 )
if ( V_37 -> V_57 -> V_175 ) {
int V_136 , V_139 ;
V_136 = F_65 ( V_37 -> V_57 ) ;
V_139 = F_66 ( V_37 -> V_57 ) ;
if ( V_136 == V_131 || V_139 == V_131 )
return 1 ;
}
#endif
return 0 ;
}
static void
F_103 ( struct V_2 * V_2 , int V_131 )
{
int V_41 ;
struct V_1 * V_7 = F_1 ( V_2 ) ;
F_104 () ;
for ( V_41 = 0 ; V_41 < V_5 ; V_41 ++ ) {
struct V_6 * V_10 ;
struct V_8 * V_9 = & V_7 -> V_11 [ V_41 ] ;
F_5 (inst, head, hlist)
F_18 ( V_10 , F_102 , V_131 ) ;
}
F_105 () ;
}
static int
F_106 ( struct V_195 * V_196 ,
unsigned long V_197 , void * V_198 )
{
struct V_90 * V_135 = F_107 ( V_198 ) ;
if ( V_197 == V_199 )
F_103 ( F_91 ( V_135 ) , V_135 -> V_131 ) ;
return V_200 ;
}
static int F_108 ( struct V_36 * V_37 , unsigned long V_201 )
{
return V_37 -> V_202 == (struct V_203 * ) V_201 ;
}
static void F_109 ( struct V_2 * V_2 , struct V_203 * V_105 )
{
struct V_1 * V_7 = F_1 ( V_2 ) ;
int V_41 ;
F_104 () ;
for ( V_41 = 0 ; V_41 < V_5 ; V_41 ++ ) {
struct V_6 * V_10 ;
struct V_8 * V_9 = & V_7 -> V_11 [ V_41 ] ;
F_5 (inst, head, hlist)
F_18 ( V_10 , F_108 , ( unsigned long ) V_105 ) ;
}
F_105 () ;
}
static int
F_110 ( struct V_195 * V_196 ,
unsigned long V_197 , void * V_198 )
{
struct V_204 * V_205 = V_198 ;
struct V_1 * V_7 = F_1 ( V_205 -> V_2 ) ;
if ( V_197 == V_206 && V_205 -> V_127 == V_207 ) {
int V_41 ;
F_7 ( & V_7 -> V_15 ) ;
for ( V_41 = 0 ; V_41 < V_5 ; V_41 ++ ) {
struct V_208 * V_209 ;
struct V_6 * V_10 ;
struct V_8 * V_9 = & V_7 -> V_11 [ V_41 ] ;
F_111 (inst, t2, head, hlist) {
if ( V_205 -> V_12 == V_10 -> V_20 )
F_20 ( V_10 ) ;
}
}
F_13 ( & V_7 -> V_15 ) ;
}
return V_200 ;
}
static struct V_6 *
F_112 ( struct V_1 * V_7 , T_8 V_4 , T_3 V_210 )
{
struct V_6 * V_35 ;
V_35 = F_4 ( V_7 , V_4 ) ;
if ( ! V_35 )
return F_15 ( - V_211 ) ;
if ( V_35 -> V_20 != V_210 )
return F_15 ( - V_212 ) ;
return V_35 ;
}
static struct V_213 *
F_113 ( const struct V_81 * const V_214 [] )
{
struct V_213 * V_215 ;
unsigned int V_216 ;
if ( ! V_214 [ V_217 ] )
return NULL ;
V_215 = F_63 ( V_214 [ V_217 ] ) ;
V_216 = F_114 ( V_215 -> V_216 ) & V_218 ;
if ( V_216 > V_219 || V_216 == V_220 )
return NULL ;
return V_215 ;
}
static int F_115 ( unsigned int V_40 , unsigned int V_221 )
{
return ( int ) ( V_40 - V_221 ) > 0 ;
}
static int
F_116 ( struct V_58 * V_222 , struct V_46 * V_57 ,
const struct V_85 * V_86 ,
const struct V_81 * const V_214 [] )
{
struct V_87 * V_88 = F_60 ( V_86 ) ;
struct V_36 * V_37 , * V_223 ;
unsigned int V_216 , V_224 ;
struct V_213 * V_215 ;
struct V_6 * V_35 ;
F_117 ( V_225 ) ;
T_8 V_4 = F_118 ( V_88 -> V_124 ) ;
struct V_2 * V_2 = F_119 ( V_222 ) ;
struct V_1 * V_7 = F_1 ( V_2 ) ;
V_35 = F_112 ( V_7 , V_4 ,
F_120 ( V_57 ) . V_12 ) ;
if ( F_121 ( V_35 ) )
return F_122 ( V_35 ) ;
V_215 = F_113 ( V_214 ) ;
if ( ! V_215 )
return - V_183 ;
V_216 = F_114 ( V_215 -> V_216 ) ;
V_224 = F_114 ( V_215 -> V_40 ) ;
F_29 ( & V_35 -> V_27 ) ;
F_32 (entry, tmp, &queue->queue_list, list) {
if ( F_115 ( V_37 -> V_40 , V_224 ) )
break;
F_26 ( V_35 , V_37 ) ;
F_25 ( & V_37 -> V_38 , & V_225 ) ;
}
F_31 ( & V_35 -> V_27 ) ;
if ( F_123 ( & V_225 ) )
return - V_226 ;
F_32 (entry, tmp, &batch_list, list) {
if ( V_214 [ V_141 ] )
V_37 -> V_57 -> V_140 = F_114 ( F_124 ( V_214 [ V_141 ] ) ) ;
F_33 ( V_37 , V_216 ) ;
}
return 0 ;
}
static int
F_125 ( struct V_58 * V_222 , struct V_46 * V_57 ,
const struct V_85 * V_86 ,
const struct V_81 * const V_214 [] )
{
struct V_87 * V_88 = F_60 ( V_86 ) ;
T_2 V_4 = F_118 ( V_88 -> V_124 ) ;
struct V_213 * V_215 ;
struct V_6 * V_35 ;
unsigned int V_216 ;
struct V_36 * V_37 ;
enum V_95 V_96 ( V_97 ) ;
struct V_93 * V_94 = NULL ;
struct V_2 * V_2 = F_119 ( V_222 ) ;
struct V_1 * V_7 = F_1 ( V_2 ) ;
V_35 = F_4 ( V_7 , V_4 ) ;
if ( ! V_35 )
V_35 = F_112 ( V_7 , V_4 ,
F_120 ( V_57 ) . V_12 ) ;
if ( F_121 ( V_35 ) )
return F_122 ( V_35 ) ;
V_215 = F_113 ( V_214 ) ;
if ( ! V_215 )
return - V_183 ;
V_216 = F_114 ( V_215 -> V_216 ) ;
V_37 = F_28 ( V_35 , F_114 ( V_215 -> V_40 ) ) ;
if ( V_37 == NULL )
return - V_226 ;
if ( V_214 [ V_227 ] ) {
V_94 = F_126 ( V_37 -> V_57 , V_214 [ V_227 ] , & V_97 ) ;
if ( V_94 && V_214 [ V_228 ] ) {
F_127 ( V_94 , V_214 [ V_228 ] ,
F_120 ( V_57 ) . V_12 ,
F_128 ( V_86 ) ) ;
}
}
if ( V_214 [ V_159 ] ) {
T_8 V_229 = V_160 ( V_214 [ V_159 ] ) ;
int V_189 = V_229 - V_37 -> V_57 -> V_113 ;
if ( F_94 ( F_63 ( V_214 [ V_159 ] ) ,
V_229 , V_37 , V_189 ) < 0 )
V_216 = V_45 ;
if ( V_94 )
F_129 ( V_37 -> V_57 , V_94 , V_97 , V_189 ) ;
}
if ( V_214 [ V_141 ] )
V_37 -> V_57 -> V_140 = F_114 ( F_124 ( V_214 [ V_141 ] ) ) ;
F_33 ( V_37 , V_216 ) ;
return 0 ;
}
static int
F_130 ( struct V_58 * V_222 , struct V_46 * V_57 ,
const struct V_85 * V_86 ,
const struct V_81 * const V_214 [] )
{
return - V_230 ;
}
static int
F_131 ( struct V_58 * V_222 , struct V_46 * V_57 ,
const struct V_85 * V_86 ,
const struct V_81 * const V_214 [] )
{
struct V_87 * V_88 = F_60 ( V_86 ) ;
T_2 V_4 = F_118 ( V_88 -> V_124 ) ;
struct V_6 * V_35 ;
struct V_231 * V_232 = NULL ;
struct V_2 * V_2 = F_119 ( V_222 ) ;
struct V_1 * V_7 = F_1 ( V_2 ) ;
int V_176 = 0 ;
if ( V_214 [ V_233 ] ) {
V_232 = F_63 ( V_214 [ V_233 ] ) ;
switch ( V_232 -> V_234 ) {
case V_235 : return 0 ;
case V_236 : return 0 ;
}
}
F_104 () ;
V_35 = F_4 ( V_7 , V_4 ) ;
if ( V_35 && V_35 -> V_20 != F_120 ( V_57 ) . V_12 ) {
V_176 = - V_212 ;
goto V_172;
}
if ( V_232 != NULL ) {
switch ( V_232 -> V_234 ) {
case V_237 :
if ( V_35 ) {
V_176 = - V_238 ;
goto V_172;
}
V_35 = F_6 ( V_7 , V_4 ,
F_120 ( V_57 ) . V_12 ) ;
if ( F_121 ( V_35 ) ) {
V_176 = F_122 ( V_35 ) ;
goto V_172;
}
break;
case V_239 :
if ( ! V_35 ) {
V_176 = - V_211 ;
goto V_172;
}
F_23 ( V_7 , V_35 ) ;
break;
case V_235 :
case V_236 :
break;
default:
V_176 = - V_230 ;
break;
}
}
if ( V_214 [ V_240 ] ) {
struct V_241 * V_242 ;
if ( ! V_35 ) {
V_176 = - V_211 ;
goto V_172;
}
V_242 = F_63 ( V_214 [ V_240 ] ) ;
F_101 ( V_35 , V_242 -> V_25 ,
F_114 ( V_242 -> V_23 ) ) ;
}
if ( V_214 [ V_243 ] ) {
T_6 * V_21 ;
if ( ! V_35 ) {
V_176 = - V_211 ;
goto V_172;
}
V_21 = F_63 ( V_214 [ V_243 ] ) ;
F_29 ( & V_35 -> V_27 ) ;
V_35 -> V_21 = F_114 ( * V_21 ) ;
F_31 ( & V_35 -> V_27 ) ;
}
if ( V_214 [ V_244 ] ) {
T_5 V_50 , V_245 ;
if ( ! V_35 ) {
V_176 = - V_211 ;
goto V_172;
}
if ( ! V_214 [ V_246 ] ) {
V_176 = - V_183 ;
goto V_172;
}
V_50 = F_114 ( F_124 ( V_214 [ V_244 ] ) ) ;
V_245 = F_114 ( F_124 ( V_214 [ V_246 ] ) ) ;
if ( V_50 >= V_247 ) {
V_176 = - V_248 ;
goto V_172;
}
#if ! F_45 ( V_73 )
if ( V_50 & V_245 & V_116 ) {
V_176 = - V_248 ;
goto V_172;
}
#endif
F_29 ( & V_35 -> V_27 ) ;
V_35 -> V_50 &= ~ V_245 ;
V_35 -> V_50 |= V_50 & V_245 ;
F_31 ( & V_35 -> V_27 ) ;
}
V_172:
F_105 () ;
return V_176 ;
}
static struct V_208 * F_132 ( struct V_249 * V_250 )
{
struct V_251 * V_252 = V_250 -> V_253 ;
struct V_2 * V_2 ;
struct V_1 * V_7 ;
if ( ! V_252 )
return NULL ;
V_2 = F_133 ( V_250 ) ;
V_7 = F_1 ( V_2 ) ;
for ( V_252 -> V_254 = 0 ; V_252 -> V_254 < V_5 ; V_252 -> V_254 ++ ) {
if ( ! F_134 ( & V_7 -> V_11 [ V_252 -> V_254 ] ) )
return V_7 -> V_11 [ V_252 -> V_254 ] . V_255 ;
}
return NULL ;
}
static struct V_208 * F_135 ( struct V_249 * V_250 , struct V_208 * V_13 )
{
struct V_251 * V_252 = V_250 -> V_253 ;
struct V_2 * V_2 = F_133 ( V_250 ) ;
V_13 = V_13 -> V_44 ;
while ( ! V_13 ) {
struct V_1 * V_7 ;
if ( ++ V_252 -> V_254 >= V_5 )
return NULL ;
V_7 = F_1 ( V_2 ) ;
V_13 = V_7 -> V_11 [ V_252 -> V_254 ] . V_255 ;
}
return V_13 ;
}
static struct V_208 * F_136 ( struct V_249 * V_250 , T_9 V_256 )
{
struct V_208 * V_9 ;
V_9 = F_132 ( V_250 ) ;
if ( V_9 )
while ( V_256 && ( V_9 = F_135 ( V_250 , V_9 ) ) )
V_256 -- ;
return V_256 ? NULL : V_9 ;
}
static void * F_137 ( struct V_249 * V_257 , T_9 * V_256 )
__acquires( nfnl_queue_pernet( seq_file_net( V_257 )
static void * F_138 ( struct V_249 * V_257 , void * V_258 , T_9 * V_256 )
{
( * V_256 ) ++ ;
return F_135 ( V_257 , V_258 ) ;
}
static void F_139 ( struct V_249 * V_257 , void * V_258 )
__releases( nfnl_queue_pernet( seq_file_net( V_257 )
static int F_140 ( struct V_249 * V_257 , void * V_258 )
{
const struct V_6 * V_10 = V_258 ;
F_141 ( V_257 , L_5 ,
V_10 -> V_4 ,
V_10 -> V_20 , V_10 -> V_39 ,
V_10 -> V_25 , V_10 -> V_23 ,
V_10 -> V_167 , V_10 -> V_171 ,
V_10 -> V_169 , 1 ) ;
return 0 ;
}
static int F_142 ( struct V_259 * V_259 , struct V_63 * V_63 )
{
return F_143 ( V_259 , V_63 , & V_260 ,
sizeof( struct V_251 ) ) ;
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
V_2 -> V_261 . V_262 , & V_263 ) )
return - V_19 ;
#endif
return 0 ;
}
static void T_11 F_148 ( struct V_2 * V_2 )
{
#ifdef F_146
F_149 ( L_6 , V_2 -> V_261 . V_262 ) ;
#endif
}
static int T_12 F_150 ( void )
{
int V_194 ;
V_194 = F_151 ( & V_264 ) ;
if ( V_194 < 0 ) {
F_152 ( L_7 ) ;
goto V_108;
}
F_153 ( & V_265 ) ;
V_194 = F_154 ( & V_266 ) ;
if ( V_194 < 0 ) {
F_152 ( L_8 ) ;
goto V_267;
}
F_155 ( & V_268 ) ;
F_156 ( & V_269 ) ;
return V_194 ;
V_267:
F_157 ( & V_265 ) ;
V_108:
return V_194 ;
}
static void T_13 F_158 ( void )
{
F_159 () ;
F_160 ( & V_268 ) ;
F_161 ( & V_266 ) ;
F_157 ( & V_265 ) ;
F_162 ( & V_264 ) ;
F_163 () ;
}
