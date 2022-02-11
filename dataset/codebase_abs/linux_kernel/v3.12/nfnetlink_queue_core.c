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
static void
F_34 ( struct V_46 * V_47 , const struct V_46 * V_48 , int V_49 , int V_50 )
{
int V_41 , V_51 = 0 ;
int V_52 = 0 ;
struct V_53 * V_53 ;
unsigned int V_54 ;
if ( V_49 <= F_35 ( V_47 ) ) {
F_36 ( V_48 , 0 , F_37 ( V_47 , V_49 ) , V_49 ) ;
return;
}
if ( V_50 ) {
F_36 ( V_48 , 0 , F_37 ( V_47 , V_50 ) , V_50 ) ;
V_49 -= V_50 ;
} else {
V_52 = F_38 ( int , F_39 ( V_48 ) , V_49 ) ;
if ( V_52 ) {
V_53 = F_40 ( V_48 -> V_9 ) ;
V_54 = V_48 -> V_43 - ( unsigned char * ) F_41 ( V_53 ) ;
F_42 ( V_47 , 0 , V_53 , V_54 , V_52 ) ;
F_43 ( V_53 ) ;
V_51 = 1 ;
V_49 -= V_52 ;
}
}
V_47 -> V_55 += V_49 + V_52 ;
V_47 -> V_49 += V_49 + V_52 ;
V_47 -> V_56 += V_49 + V_52 ;
for ( V_41 = 0 ; V_41 < F_44 ( V_48 ) -> V_57 ; V_41 ++ ) {
if ( ! V_49 )
break;
F_44 ( V_47 ) -> V_58 [ V_51 ] = F_44 ( V_48 ) -> V_58 [ V_41 ] ;
F_44 ( V_47 ) -> V_58 [ V_51 ] . V_59 = F_38 ( int , F_44 ( V_47 ) -> V_58 [ V_51 ] . V_59 , V_49 ) ;
V_49 -= F_44 ( V_47 ) -> V_58 [ V_51 ] . V_59 ;
F_45 ( V_47 , V_51 ) ;
V_51 ++ ;
}
F_44 ( V_47 ) -> V_57 = V_51 ;
}
static int
F_46 ( struct V_46 * V_60 , struct V_46 * V_61 ,
bool V_62 )
{
T_4 V_63 = 0 ;
if ( V_61 -> V_64 == V_65 )
V_63 = V_66 ;
else if ( V_62 )
V_63 = V_67 ;
if ( F_47 ( V_61 ) )
V_63 |= V_68 ;
return V_63 ? F_48 ( V_60 , V_69 , F_49 ( V_63 ) ) : 0 ;
}
static struct V_46 *
F_50 ( struct V_6 * V_35 ,
struct V_36 * V_37 ,
T_5 * * V_70 )
{
T_6 V_59 ;
T_6 V_56 = 0 , V_71 = 0 ;
int V_50 = 0 ;
struct V_46 * V_72 ;
struct V_73 * V_74 ;
struct V_75 * V_76 ;
struct V_77 * V_78 ;
struct V_79 * V_80 ;
struct V_46 * V_81 = V_37 -> V_72 ;
struct V_82 * V_83 ;
struct V_82 * V_84 ;
struct V_85 * V_86 = NULL ;
enum V_87 V_88 ( V_89 ) ;
bool V_62 ;
V_59 = F_51 ( sizeof( struct V_79 ) )
+ F_52 ( sizeof( struct V_75 ) )
+ F_52 ( sizeof( V_90 ) )
+ F_52 ( sizeof( V_90 ) )
#ifdef F_53
+ F_52 ( sizeof( V_90 ) )
+ F_52 ( sizeof( V_90 ) )
#endif
+ F_52 ( sizeof( V_90 ) )
+ F_52 ( sizeof( struct V_91 ) )
+ F_52 ( sizeof( V_90 ) )
+ F_52 ( sizeof( V_90 ) ) ;
if ( V_81 -> V_92 . V_93 )
V_59 += F_52 ( sizeof( struct V_94 ) ) ;
if ( V_37 -> V_95 <= V_96 ||
( V_37 -> V_95 == V_97 && V_81 -> V_98 == NULL ) )
V_62 = ! F_54 ( V_81 ) ;
else
V_62 = false ;
V_84 = V_37 -> V_84 ;
switch ( (enum V_99 ) F_55 ( V_35 -> V_25 ) ) {
case V_100 :
case V_26 :
break;
case V_101 :
if ( ! ( V_35 -> V_63 & V_102 ) &&
V_81 -> V_64 == V_65 &&
F_56 ( V_81 ) )
return NULL ;
V_56 = F_55 ( V_35 -> V_23 ) ;
if ( V_56 > V_81 -> V_49 )
V_56 = V_81 -> V_49 ;
if ( ! V_81 -> V_103 ||
F_39 ( V_81 ) < V_104 ||
F_44 ( V_81 ) -> V_57 >= V_105 )
V_50 = F_39 ( V_81 ) ;
if ( F_57 ( V_81 ) )
V_50 = V_81 -> V_49 ;
V_50 = F_38 ( int , V_56 , V_50 ) ;
V_59 += sizeof( struct V_73 ) + V_50 ;
V_71 = V_81 -> V_49 ;
break;
}
if ( V_35 -> V_63 & V_106 )
V_86 = F_58 ( V_81 , & V_59 , & V_89 ) ;
V_72 = F_59 ( & V_107 , V_59 , V_35 -> V_20 ,
V_18 ) ;
if ( ! V_72 )
return NULL ;
V_78 = F_60 ( V_72 , 0 , 0 ,
V_108 << 8 | V_109 ,
sizeof( struct V_79 ) , 0 ) ;
if ( ! V_78 ) {
F_61 ( V_72 ) ;
return NULL ;
}
V_80 = F_62 ( V_78 ) ;
V_80 -> V_110 = V_37 -> V_111 ;
V_80 -> V_112 = V_113 ;
V_80 -> V_114 = F_63 ( V_35 -> V_4 ) ;
V_74 = F_64 ( V_72 , V_115 , sizeof( * V_76 ) ) ;
V_76 = F_65 ( V_74 ) ;
V_76 -> V_116 = V_81 -> V_117 ;
V_76 -> V_95 = V_37 -> V_95 ;
* V_70 = & V_76 -> V_118 ;
V_83 = V_37 -> V_83 ;
if ( V_83 ) {
#ifndef F_53
if ( F_48 ( V_72 , V_119 , F_49 ( V_83 -> V_120 ) ) )
goto V_121;
#else
if ( V_37 -> V_111 == V_122 ) {
if ( F_48 ( V_72 , V_123 ,
F_49 ( V_83 -> V_120 ) ) ||
F_48 ( V_72 , V_119 ,
F_49 ( F_66 ( V_83 ) -> V_124 -> V_125 -> V_120 ) ) )
goto V_121;
} else {
if ( F_48 ( V_72 , V_119 ,
F_49 ( V_83 -> V_120 ) ) )
goto V_121;
if ( V_81 -> V_126 && V_81 -> V_126 -> V_127 &&
F_48 ( V_72 , V_123 ,
F_49 ( V_81 -> V_126 -> V_127 -> V_120 ) ) )
goto V_121;
}
#endif
}
if ( V_84 ) {
#ifndef F_53
if ( F_48 ( V_72 , V_128 , F_49 ( V_84 -> V_120 ) ) )
goto V_121;
#else
if ( V_37 -> V_111 == V_122 ) {
if ( F_48 ( V_72 , V_129 ,
F_49 ( V_84 -> V_120 ) ) ||
F_48 ( V_72 , V_128 ,
F_49 ( F_66 ( V_84 ) -> V_124 -> V_125 -> V_120 ) ) )
goto V_121;
} else {
if ( F_48 ( V_72 , V_128 ,
F_49 ( V_84 -> V_120 ) ) )
goto V_121;
if ( V_81 -> V_126 && V_81 -> V_126 -> V_130 &&
F_48 ( V_72 , V_129 ,
F_49 ( V_81 -> V_126 -> V_130 -> V_120 ) ) )
goto V_121;
}
#endif
}
if ( V_81 -> V_131 &&
F_48 ( V_72 , V_132 , F_49 ( V_81 -> V_131 ) ) )
goto V_121;
if ( V_83 && V_81 -> V_125 &&
V_81 -> V_133 != V_81 -> V_134 ) {
struct V_91 V_135 ;
int V_49 ;
memset ( & V_135 , 0 , sizeof( V_135 ) ) ;
V_49 = F_67 ( V_81 , V_135 . V_136 ) ;
if ( V_49 ) {
V_135 . V_137 = F_63 ( V_49 ) ;
if ( F_68 ( V_72 , V_138 , sizeof( V_135 ) , & V_135 ) )
goto V_121;
}
}
if ( V_81 -> V_92 . V_93 ) {
struct V_94 V_139 ;
struct V_140 V_141 = F_69 ( V_81 -> V_92 ) ;
V_139 . V_142 = F_70 ( V_141 . V_143 ) ;
V_139 . V_144 = F_70 ( V_141 . V_145 ) ;
if ( F_68 ( V_72 , V_146 , sizeof( V_139 ) , & V_139 ) )
goto V_121;
}
if ( V_86 && F_71 ( V_72 , V_86 , V_89 ) < 0 )
goto V_121;
if ( V_71 > V_56 &&
F_48 ( V_72 , V_147 , F_49 ( V_71 ) ) )
goto V_121;
if ( F_46 ( V_72 , V_81 , V_62 ) )
goto V_121;
if ( V_56 ) {
struct V_73 * V_74 ;
if ( F_35 ( V_72 ) < sizeof( * V_74 ) + V_50 )
goto V_121;
V_74 = (struct V_73 * ) F_37 ( V_72 , sizeof( * V_74 ) ) ;
V_74 -> V_148 = V_149 ;
V_74 -> V_150 = F_72 ( V_56 ) ;
F_34 ( V_72 , V_81 , V_56 , V_50 ) ;
}
V_78 -> V_151 = V_72 -> V_49 ;
return V_72 ;
V_121:
F_61 ( V_72 ) ;
F_73 ( L_1 ) ;
return NULL ;
}
static int
F_74 ( struct V_2 * V_2 , struct V_6 * V_35 ,
struct V_36 * V_37 )
{
struct V_46 * V_152 ;
int V_14 = - V_153 ;
T_5 * V_70 ;
int V_154 = 0 ;
V_152 = F_50 ( V_35 , V_37 , & V_70 ) ;
if ( V_152 == NULL ) {
V_14 = - V_19 ;
goto V_155;
}
F_29 ( & V_35 -> V_27 ) ;
if ( V_35 -> V_39 >= V_35 -> V_21 ) {
if ( V_35 -> V_63 & V_156 ) {
V_154 = 1 ;
V_14 = 0 ;
} else {
V_35 -> V_157 ++ ;
F_75 ( L_2 ,
V_35 -> V_39 ) ;
}
goto V_158;
}
V_37 -> V_40 = ++ V_35 -> V_159 ;
* V_70 = F_49 ( V_37 -> V_40 ) ;
V_14 = F_76 ( V_152 , V_2 , V_35 -> V_20 , V_160 ) ;
if ( V_14 < 0 ) {
V_35 -> V_161 ++ ;
goto V_162;
}
F_24 ( V_35 , V_37 ) ;
F_31 ( & V_35 -> V_27 ) ;
return 0 ;
V_158:
F_61 ( V_152 ) ;
V_162:
F_31 ( & V_35 -> V_27 ) ;
if ( V_154 )
F_33 ( V_37 , V_163 ) ;
V_155:
return V_14 ;
}
static struct V_36 *
F_77 ( struct V_36 * V_164 )
{
struct V_36 * V_37 = F_78 ( V_164 , V_164 -> V_59 , V_18 ) ;
if ( V_37 ) {
if ( F_79 ( V_37 ) )
return V_37 ;
F_14 ( V_37 ) ;
}
return NULL ;
}
static void F_80 ( struct V_46 * V_72 )
{
if ( V_72 -> V_126 )
F_81 ( V_72 , V_72 -> V_134 - V_72 -> V_133 ) ;
}
static void F_82 ( struct V_46 * V_72 )
{
if ( V_72 -> V_126 )
F_83 ( V_72 , V_72 -> V_134 - V_72 -> V_133 ) ;
}
static void F_84 ( struct V_36 * V_37 )
{
F_85 ( V_37 ) ;
F_14 ( V_37 ) ;
}
static int
F_86 ( struct V_2 * V_2 , struct V_6 * V_35 ,
struct V_46 * V_72 , struct V_36 * V_37 )
{
int V_165 = - V_19 ;
struct V_36 * V_166 ;
F_82 ( V_72 ) ;
if ( V_72 -> V_44 == NULL ) {
struct V_46 * V_167 = V_37 -> V_72 ;
V_37 -> V_72 = V_72 ;
V_165 = F_74 ( V_2 , V_35 , V_37 ) ;
if ( V_165 )
V_37 -> V_72 = V_167 ;
return V_165 ;
}
V_72 -> V_44 = NULL ;
V_166 = F_77 ( V_37 ) ;
if ( V_166 ) {
V_166 -> V_72 = V_72 ;
V_165 = F_74 ( V_2 , V_35 , V_166 ) ;
if ( V_165 )
F_84 ( V_166 ) ;
}
return V_165 ;
}
static int
F_87 ( struct V_36 * V_37 , unsigned int V_168 )
{
unsigned int V_169 ;
struct V_6 * V_35 ;
struct V_46 * V_72 , * V_170 ;
int V_14 = - V_153 ;
struct V_2 * V_2 = F_88 ( V_37 -> V_83 ?
V_37 -> V_83 : V_37 -> V_84 ) ;
struct V_1 * V_7 = F_1 ( V_2 ) ;
V_35 = F_4 ( V_7 , V_168 ) ;
if ( ! V_35 )
return - V_171 ;
if ( V_35 -> V_25 == V_26 )
return - V_172 ;
V_72 = V_37 -> V_72 ;
switch ( V_37 -> V_111 ) {
case V_173 :
V_72 -> V_117 = F_63 ( V_174 ) ;
break;
case V_175 :
V_72 -> V_117 = F_63 ( V_176 ) ;
break;
}
if ( ( V_35 -> V_63 & V_102 ) || ! F_47 ( V_72 ) )
return F_74 ( V_2 , V_35 , V_37 ) ;
F_80 ( V_72 ) ;
V_170 = F_89 ( V_72 , 0 ) ;
if ( F_90 ( V_170 ) )
goto V_177;
V_169 = 0 ;
V_14 = 0 ;
do {
struct V_46 * V_152 = V_170 -> V_44 ;
if ( V_14 == 0 )
V_14 = F_86 ( V_2 , V_35 ,
V_170 , V_37 ) ;
if ( V_14 == 0 )
V_169 ++ ;
else
F_61 ( V_170 ) ;
V_170 = V_152 ;
} while ( V_170 );
if ( V_169 ) {
if ( V_14 )
F_84 ( V_37 ) ;
F_61 ( V_72 ) ;
return 0 ;
}
V_177:
F_82 ( V_72 ) ;
return V_14 ;
}
static int
F_91 ( void * V_43 , int V_56 , struct V_36 * V_164 , int V_178 )
{
struct V_46 * V_152 ;
if ( V_178 < 0 ) {
if ( F_92 ( V_164 -> V_72 , V_56 ) )
return - V_19 ;
} else if ( V_178 > 0 ) {
if ( V_56 > 0xFFFF )
return - V_172 ;
if ( V_178 > F_35 ( V_164 -> V_72 ) ) {
V_152 = F_93 ( V_164 -> V_72 , F_94 ( V_164 -> V_72 ) ,
V_178 , V_18 ) ;
if ( ! V_152 ) {
F_95 ( V_179 L_3
L_4 ) ;
return - V_19 ;
}
F_61 ( V_164 -> V_72 ) ;
V_164 -> V_72 = V_152 ;
}
F_37 ( V_164 -> V_72 , V_178 ) ;
}
if ( ! F_96 ( V_164 -> V_72 , V_56 ) )
return - V_19 ;
F_97 ( V_164 -> V_72 , V_43 , V_56 ) ;
V_164 -> V_72 -> V_64 = V_180 ;
return 0 ;
}
static int
F_98 ( struct V_6 * V_35 ,
unsigned char V_181 , unsigned int V_182 )
{
int V_183 = 0 ;
F_29 ( & V_35 -> V_27 ) ;
switch ( V_181 ) {
case V_26 :
case V_100 :
V_35 -> V_25 = V_181 ;
V_35 -> V_23 = 0 ;
break;
case V_101 :
V_35 -> V_25 = V_181 ;
if ( V_182 == 0 || V_182 > V_24 )
V_35 -> V_23 = V_24 ;
else
V_35 -> V_23 = V_182 ;
break;
default:
V_183 = - V_172 ;
}
F_31 ( & V_35 -> V_27 ) ;
return V_183 ;
}
static int
F_99 ( struct V_36 * V_37 , unsigned long V_120 )
{
if ( V_37 -> V_83 )
if ( V_37 -> V_83 -> V_120 == V_120 )
return 1 ;
if ( V_37 -> V_84 )
if ( V_37 -> V_84 -> V_120 == V_120 )
return 1 ;
#ifdef F_53
if ( V_37 -> V_72 -> V_126 ) {
if ( V_37 -> V_72 -> V_126 -> V_127 &&
V_37 -> V_72 -> V_126 -> V_127 -> V_120 == V_120 )
return 1 ;
if ( V_37 -> V_72 -> V_126 -> V_130 &&
V_37 -> V_72 -> V_126 -> V_130 -> V_120 == V_120 )
return 1 ;
}
#endif
return 0 ;
}
static void
F_100 ( struct V_2 * V_2 , int V_120 )
{
int V_41 ;
struct V_1 * V_7 = F_1 ( V_2 ) ;
F_101 () ;
for ( V_41 = 0 ; V_41 < V_5 ; V_41 ++ ) {
struct V_6 * V_10 ;
struct V_8 * V_9 = & V_7 -> V_11 [ V_41 ] ;
F_5 (inst, head, hlist)
F_18 ( V_10 , F_99 , V_120 ) ;
}
F_102 () ;
}
static int
F_103 ( struct V_184 * V_185 ,
unsigned long V_186 , void * V_187 )
{
struct V_82 * V_125 = F_104 ( V_187 ) ;
if ( V_186 == V_188 )
F_100 ( F_88 ( V_125 ) , V_125 -> V_120 ) ;
return V_189 ;
}
static int
F_105 ( struct V_184 * V_185 ,
unsigned long V_186 , void * V_187 )
{
struct V_190 * V_191 = V_187 ;
struct V_1 * V_7 = F_1 ( V_191 -> V_2 ) ;
if ( V_186 == V_192 && V_191 -> V_117 == V_193 ) {
int V_41 ;
F_7 ( & V_7 -> V_15 ) ;
for ( V_41 = 0 ; V_41 < V_5 ; V_41 ++ ) {
struct V_194 * V_195 ;
struct V_6 * V_10 ;
struct V_8 * V_9 = & V_7 -> V_11 [ V_41 ] ;
F_106 (inst, t2, head, hlist) {
if ( V_191 -> V_12 == V_10 -> V_20 )
F_20 ( V_10 ) ;
}
}
F_13 ( & V_7 -> V_15 ) ;
}
return V_189 ;
}
static struct V_6 *
F_107 ( struct V_1 * V_7 , T_7 V_4 , int V_196 )
{
struct V_6 * V_35 ;
V_35 = F_4 ( V_7 , V_4 ) ;
if ( ! V_35 )
return F_15 ( - V_197 ) ;
if ( V_35 -> V_20 != V_196 )
return F_15 ( - V_198 ) ;
return V_35 ;
}
static struct V_199 *
F_108 ( const struct V_73 * const V_200 [] )
{
struct V_199 * V_201 ;
unsigned int V_202 ;
if ( ! V_200 [ V_203 ] )
return NULL ;
V_201 = F_65 ( V_200 [ V_203 ] ) ;
V_202 = F_109 ( V_201 -> V_202 ) & V_204 ;
if ( V_202 > V_205 || V_202 == V_206 )
return NULL ;
return V_201 ;
}
static int F_110 ( unsigned int V_40 , unsigned int V_207 )
{
return ( int ) ( V_40 - V_207 ) > 0 ;
}
static int
F_111 ( struct V_208 * V_209 , struct V_46 * V_72 ,
const struct V_77 * V_78 ,
const struct V_73 * const V_200 [] )
{
struct V_79 * V_80 = F_62 ( V_78 ) ;
struct V_36 * V_37 , * V_210 ;
unsigned int V_202 , V_211 ;
struct V_199 * V_201 ;
struct V_6 * V_35 ;
F_112 ( V_212 ) ;
T_7 V_4 = F_113 ( V_80 -> V_114 ) ;
struct V_2 * V_2 = F_114 ( V_209 ) ;
struct V_1 * V_7 = F_1 ( V_2 ) ;
V_35 = F_107 ( V_7 , V_4 ,
F_115 ( V_72 ) . V_12 ) ;
if ( F_90 ( V_35 ) )
return F_116 ( V_35 ) ;
V_201 = F_108 ( V_200 ) ;
if ( ! V_201 )
return - V_172 ;
V_202 = F_109 ( V_201 -> V_202 ) ;
V_211 = F_109 ( V_201 -> V_40 ) ;
F_29 ( & V_35 -> V_27 ) ;
F_32 (entry, tmp, &queue->queue_list, list) {
if ( F_110 ( V_37 -> V_40 , V_211 ) )
break;
F_26 ( V_35 , V_37 ) ;
F_25 ( & V_37 -> V_38 , & V_212 ) ;
}
F_31 ( & V_35 -> V_27 ) ;
if ( F_117 ( & V_212 ) )
return - V_213 ;
F_32 (entry, tmp, &batch_list, list) {
if ( V_200 [ V_132 ] )
V_37 -> V_72 -> V_131 = F_109 ( F_118 ( V_200 [ V_132 ] ) ) ;
F_33 ( V_37 , V_202 ) ;
}
return 0 ;
}
static int
F_119 ( struct V_208 * V_209 , struct V_46 * V_72 ,
const struct V_77 * V_78 ,
const struct V_73 * const V_200 [] )
{
struct V_79 * V_80 = F_62 ( V_78 ) ;
T_2 V_4 = F_113 ( V_80 -> V_114 ) ;
struct V_199 * V_201 ;
struct V_6 * V_35 ;
unsigned int V_202 ;
struct V_36 * V_37 ;
enum V_87 V_88 ( V_89 ) ;
struct V_85 * V_86 = NULL ;
struct V_2 * V_2 = F_114 ( V_209 ) ;
struct V_1 * V_7 = F_1 ( V_2 ) ;
V_35 = F_4 ( V_7 , V_4 ) ;
if ( ! V_35 )
V_35 = F_107 ( V_7 , V_4 ,
F_115 ( V_72 ) . V_12 ) ;
if ( F_90 ( V_35 ) )
return F_116 ( V_35 ) ;
V_201 = F_108 ( V_200 ) ;
if ( ! V_201 )
return - V_172 ;
V_202 = F_109 ( V_201 -> V_202 ) ;
V_37 = F_28 ( V_35 , F_109 ( V_201 -> V_40 ) ) ;
if ( V_37 == NULL )
return - V_213 ;
if ( V_200 [ V_214 ] ) {
V_86 = F_120 ( V_37 -> V_72 , V_200 [ V_214 ] , & V_89 ) ;
if ( V_86 && V_200 [ V_215 ] ) {
F_121 ( V_86 , V_200 [ V_215 ] ,
F_115 ( V_72 ) . V_12 ,
F_122 ( V_78 ) ) ;
}
}
if ( V_200 [ V_149 ] ) {
T_7 V_216 = V_150 ( V_200 [ V_149 ] ) ;
int V_178 = V_216 - V_37 -> V_72 -> V_49 ;
if ( F_91 ( F_65 ( V_200 [ V_149 ] ) ,
V_216 , V_37 , V_178 ) < 0 )
V_202 = V_45 ;
if ( V_86 )
F_123 ( V_37 -> V_72 , V_86 , V_89 , V_178 ) ;
}
if ( V_200 [ V_132 ] )
V_37 -> V_72 -> V_131 = F_109 ( F_118 ( V_200 [ V_132 ] ) ) ;
F_33 ( V_37 , V_202 ) ;
return 0 ;
}
static int
F_124 ( struct V_208 * V_209 , struct V_46 * V_72 ,
const struct V_77 * V_78 ,
const struct V_73 * const V_200 [] )
{
return - V_217 ;
}
static int
F_125 ( struct V_208 * V_209 , struct V_46 * V_72 ,
const struct V_77 * V_78 ,
const struct V_73 * const V_200 [] )
{
struct V_79 * V_80 = F_62 ( V_78 ) ;
T_2 V_4 = F_113 ( V_80 -> V_114 ) ;
struct V_6 * V_35 ;
struct V_218 * V_219 = NULL ;
struct V_2 * V_2 = F_114 ( V_209 ) ;
struct V_1 * V_7 = F_1 ( V_2 ) ;
int V_165 = 0 ;
if ( V_200 [ V_220 ] ) {
V_219 = F_65 ( V_200 [ V_220 ] ) ;
switch ( V_219 -> V_221 ) {
case V_222 : return 0 ;
case V_223 : return 0 ;
}
}
F_101 () ;
V_35 = F_4 ( V_7 , V_4 ) ;
if ( V_35 && V_35 -> V_20 != F_115 ( V_72 ) . V_12 ) {
V_165 = - V_198 ;
goto V_162;
}
if ( V_219 != NULL ) {
switch ( V_219 -> V_221 ) {
case V_224 :
if ( V_35 ) {
V_165 = - V_225 ;
goto V_162;
}
V_35 = F_6 ( V_7 , V_4 ,
F_115 ( V_72 ) . V_12 ) ;
if ( F_90 ( V_35 ) ) {
V_165 = F_116 ( V_35 ) ;
goto V_162;
}
break;
case V_226 :
if ( ! V_35 ) {
V_165 = - V_197 ;
goto V_162;
}
F_23 ( V_7 , V_35 ) ;
break;
case V_222 :
case V_223 :
break;
default:
V_165 = - V_217 ;
break;
}
}
if ( V_200 [ V_227 ] ) {
struct V_228 * V_229 ;
if ( ! V_35 ) {
V_165 = - V_197 ;
goto V_162;
}
V_229 = F_65 ( V_200 [ V_227 ] ) ;
F_98 ( V_35 , V_229 -> V_25 ,
F_109 ( V_229 -> V_23 ) ) ;
}
if ( V_200 [ V_230 ] ) {
T_5 * V_21 ;
if ( ! V_35 ) {
V_165 = - V_197 ;
goto V_162;
}
V_21 = F_65 ( V_200 [ V_230 ] ) ;
F_29 ( & V_35 -> V_27 ) ;
V_35 -> V_21 = F_109 ( * V_21 ) ;
F_31 ( & V_35 -> V_27 ) ;
}
if ( V_200 [ V_231 ] ) {
T_4 V_63 , V_232 ;
if ( ! V_35 ) {
V_165 = - V_197 ;
goto V_162;
}
if ( ! V_200 [ V_233 ] ) {
V_165 = - V_172 ;
goto V_162;
}
V_63 = F_109 ( F_118 ( V_200 [ V_231 ] ) ) ;
V_232 = F_109 ( F_118 ( V_200 [ V_233 ] ) ) ;
if ( V_63 >= V_234 ) {
V_165 = - V_235 ;
goto V_162;
}
F_29 ( & V_35 -> V_27 ) ;
V_35 -> V_63 &= ~ V_232 ;
V_35 -> V_63 |= V_63 & V_232 ;
F_31 ( & V_35 -> V_27 ) ;
}
V_162:
F_102 () ;
return V_165 ;
}
static struct V_194 * F_126 ( struct V_236 * V_237 )
{
struct V_238 * V_239 = V_237 -> V_240 ;
struct V_2 * V_2 ;
struct V_1 * V_7 ;
if ( ! V_239 )
return NULL ;
V_2 = F_127 ( V_237 ) ;
V_7 = F_1 ( V_2 ) ;
for ( V_239 -> V_241 = 0 ; V_239 -> V_241 < V_5 ; V_239 -> V_241 ++ ) {
if ( ! F_128 ( & V_7 -> V_11 [ V_239 -> V_241 ] ) )
return V_7 -> V_11 [ V_239 -> V_241 ] . V_242 ;
}
return NULL ;
}
static struct V_194 * F_129 ( struct V_236 * V_237 , struct V_194 * V_13 )
{
struct V_238 * V_239 = V_237 -> V_240 ;
struct V_2 * V_2 = F_127 ( V_237 ) ;
V_13 = V_13 -> V_44 ;
while ( ! V_13 ) {
struct V_1 * V_7 ;
if ( ++ V_239 -> V_241 >= V_5 )
return NULL ;
V_7 = F_1 ( V_2 ) ;
V_13 = V_7 -> V_11 [ V_239 -> V_241 ] . V_242 ;
}
return V_13 ;
}
static struct V_194 * F_130 ( struct V_236 * V_237 , T_8 V_243 )
{
struct V_194 * V_9 ;
V_9 = F_126 ( V_237 ) ;
if ( V_9 )
while ( V_243 && ( V_9 = F_129 ( V_237 , V_9 ) ) )
V_243 -- ;
return V_243 ? NULL : V_9 ;
}
static void * F_131 ( struct V_236 * V_244 , T_8 * V_243 )
__acquires( nfnl_queue_pernet( seq_file_net( V_244 )
static void * F_132 ( struct V_236 * V_244 , void * V_245 , T_8 * V_243 )
{
( * V_243 ) ++ ;
return F_129 ( V_244 , V_245 ) ;
}
static void F_133 ( struct V_236 * V_244 , void * V_245 )
__releases( nfnl_queue_pernet( seq_file_net( V_244 )
static int F_134 ( struct V_236 * V_244 , void * V_245 )
{
const struct V_6 * V_10 = V_245 ;
return F_135 ( V_244 , L_5 ,
V_10 -> V_4 ,
V_10 -> V_20 , V_10 -> V_39 ,
V_10 -> V_25 , V_10 -> V_23 ,
V_10 -> V_157 , V_10 -> V_161 ,
V_10 -> V_159 , 1 ) ;
}
static int F_136 ( struct V_246 * V_246 , struct V_247 * V_247 )
{
return F_137 ( V_246 , V_247 , & V_248 ,
sizeof( struct V_238 ) ) ;
}
static int T_9 F_138 ( struct V_2 * V_2 )
{
unsigned int V_41 ;
struct V_1 * V_7 = F_1 ( V_2 ) ;
for ( V_41 = 0 ; V_41 < V_5 ; V_41 ++ )
F_139 ( & V_7 -> V_11 [ V_41 ] ) ;
F_9 ( & V_7 -> V_15 ) ;
#ifdef F_140
if ( ! F_141 ( L_6 , 0440 ,
V_2 -> V_249 . V_250 , & V_251 ) )
return - V_19 ;
#endif
return 0 ;
}
static void T_10 F_142 ( struct V_2 * V_2 )
{
#ifdef F_140
F_143 ( L_6 , V_2 -> V_249 . V_250 ) ;
#endif
}
static int T_11 F_144 ( void )
{
int V_183 = - V_19 ;
F_145 ( & V_252 ) ;
V_183 = F_146 ( & V_253 ) ;
if ( V_183 < 0 ) {
F_147 ( L_7 ) ;
goto V_254;
}
V_183 = F_148 ( & V_255 ) ;
if ( V_183 < 0 ) {
F_147 ( L_8 ) ;
goto V_256;
}
F_149 ( & V_257 ) ;
F_150 ( & V_258 ) ;
return V_183 ;
V_256:
F_151 ( & V_253 ) ;
V_254:
F_152 ( & V_252 ) ;
return V_183 ;
}
static void T_12 F_153 ( void )
{
F_154 () ;
F_155 ( & V_257 ) ;
F_156 ( & V_255 ) ;
F_151 ( & V_253 ) ;
F_152 ( & V_252 ) ;
F_157 () ;
}
