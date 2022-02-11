static struct V_1 * F_1 ( struct V_2 * V_2 , T_1 V_3 )
{
struct V_1 * V_4 ;
F_2 (mrt, net) {
if ( V_4 -> V_3 == V_3 )
return V_4 ;
}
return NULL ;
}
static int F_3 ( struct V_2 * V_2 , struct V_5 * V_6 ,
struct V_1 * * V_4 )
{
struct V_7 V_8 ;
struct V_9 V_10 = { . V_11 = & V_8 , } ;
int V_12 ;
V_12 = F_4 ( V_2 -> V_13 . V_14 ,
F_5 ( V_6 ) , 0 , & V_10 ) ;
if ( V_12 < 0 )
return V_12 ;
* V_4 = V_8 . V_4 ;
return 0 ;
}
static int F_6 ( struct V_15 * V_16 , struct V_17 * V_18 ,
int V_19 , struct V_9 * V_10 )
{
struct V_7 * V_8 = V_10 -> V_11 ;
struct V_1 * V_4 ;
switch ( V_16 -> V_20 ) {
case V_21 :
break;
case V_22 :
return - V_23 ;
case V_24 :
return - V_25 ;
case V_26 :
default:
return - V_27 ;
}
V_4 = F_1 ( V_16 -> V_28 , V_16 -> V_29 ) ;
if ( V_4 == NULL )
return - V_30 ;
V_8 -> V_4 = V_4 ;
return 0 ;
}
static int F_7 ( struct V_15 * V_16 , struct V_17 * V_18 , int V_19 )
{
return 1 ;
}
static int F_8 ( struct V_15 * V_16 , struct V_31 * V_32 ,
struct V_33 * V_34 , struct V_35 * * V_36 )
{
return 0 ;
}
static int F_9 ( struct V_15 * V_16 , struct V_33 * V_34 ,
struct V_35 * * V_36 )
{
return 1 ;
}
static int F_10 ( struct V_15 * V_16 , struct V_31 * V_32 ,
struct V_33 * V_34 )
{
V_34 -> V_37 = 0 ;
V_34 -> V_38 = 0 ;
V_34 -> V_39 = 0 ;
return 0 ;
}
static int T_2 F_11 ( struct V_2 * V_2 )
{
struct V_40 * V_41 ;
struct V_1 * V_4 ;
int V_12 ;
V_41 = F_12 ( & V_42 , V_2 ) ;
if ( F_13 ( V_41 ) )
return F_14 ( V_41 ) ;
F_15 ( & V_2 -> V_13 . V_43 ) ;
V_4 = F_16 ( V_2 , V_44 ) ;
if ( V_4 == NULL ) {
V_12 = - V_45 ;
goto V_46;
}
V_12 = F_17 ( V_41 , 0x7fff , V_44 , 0 ) ;
if ( V_12 < 0 )
goto V_47;
V_2 -> V_13 . V_14 = V_41 ;
return 0 ;
V_47:
F_18 ( V_4 ) ;
V_46:
F_19 ( V_41 ) ;
return V_12 ;
}
static void T_3 F_20 ( struct V_2 * V_2 )
{
struct V_1 * V_4 , * V_48 ;
F_21 (mrt, next, &net->ipv6.mr6_tables, list) {
F_22 ( & V_4 -> V_49 ) ;
F_23 ( V_4 ) ;
}
F_19 ( V_2 -> V_13 . V_14 ) ;
}
static struct V_1 * F_1 ( struct V_2 * V_2 , T_1 V_3 )
{
return V_2 -> V_13 . V_50 ;
}
static int F_3 ( struct V_2 * V_2 , struct V_5 * V_6 ,
struct V_1 * * V_4 )
{
* V_4 = V_2 -> V_13 . V_50 ;
return 0 ;
}
static int T_2 F_11 ( struct V_2 * V_2 )
{
V_2 -> V_13 . V_50 = F_16 ( V_2 , V_44 ) ;
return V_2 -> V_13 . V_50 ? 0 : - V_45 ;
}
static void T_3 F_20 ( struct V_2 * V_2 )
{
F_23 ( V_2 -> V_13 . V_50 ) ;
}
static struct V_1 * F_16 ( struct V_2 * V_2 , T_1 V_3 )
{
struct V_1 * V_4 ;
unsigned int V_51 ;
V_4 = F_1 ( V_2 , V_3 ) ;
if ( V_4 != NULL )
return V_4 ;
V_4 = F_24 ( sizeof( * V_4 ) , V_52 ) ;
if ( V_4 == NULL )
return NULL ;
V_4 -> V_3 = V_3 ;
F_25 ( & V_4 -> V_2 , V_2 ) ;
for ( V_51 = 0 ; V_51 < V_53 ; V_51 ++ )
F_15 ( & V_4 -> V_54 [ V_51 ] ) ;
F_15 ( & V_4 -> V_55 ) ;
F_26 ( & V_4 -> V_56 , V_57 ,
( unsigned long ) V_4 ) ;
#ifdef F_27
V_4 -> V_58 = - 1 ;
#endif
#ifdef F_28
F_29 ( & V_4 -> V_49 , & V_2 -> V_13 . V_43 ) ;
#endif
return V_4 ;
}
static void F_23 ( struct V_1 * V_4 )
{
F_30 ( & V_4 -> V_56 ) ;
F_31 ( V_4 ) ;
F_18 ( V_4 ) ;
}
static struct V_59 * F_32 ( struct V_2 * V_2 ,
struct V_60 * V_61 , T_4 V_62 )
{
struct V_1 * V_4 = V_61 -> V_4 ;
struct V_59 * V_63 ;
F_33 ( & V_64 ) ;
for ( V_61 -> V_65 = 0 ; V_61 -> V_65 < V_53 ; V_61 -> V_65 ++ ) {
V_61 -> V_66 = & V_4 -> V_54 [ V_61 -> V_65 ] ;
F_34 (mfc, it->cache, list)
if ( V_62 -- == 0 )
return V_63 ;
}
F_35 ( & V_64 ) ;
F_36 ( & V_67 ) ;
V_61 -> V_66 = & V_4 -> V_55 ;
F_34 (mfc, it->cache, list)
if ( V_62 -- == 0 )
return V_63 ;
F_37 ( & V_67 ) ;
V_61 -> V_66 = NULL ;
return NULL ;
}
static struct V_68 * F_38 ( struct V_2 * V_2 ,
struct V_69 * V_70 ,
T_4 V_62 )
{
struct V_1 * V_4 = V_70 -> V_4 ;
for ( V_70 -> V_65 = 0 ; V_70 -> V_65 < V_4 -> V_71 ; ++ V_70 -> V_65 ) {
if ( ! F_39 ( V_4 , V_70 -> V_65 ) )
continue;
if ( V_62 -- == 0 )
return & V_4 -> V_72 [ V_70 -> V_65 ] ;
}
return NULL ;
}
static void * F_40 ( struct V_73 * V_74 , T_4 * V_62 )
__acquires( V_64 )
{
struct V_69 * V_70 = V_74 -> V_75 ;
struct V_2 * V_2 = F_41 ( V_74 ) ;
struct V_1 * V_4 ;
V_4 = F_1 ( V_2 , V_44 ) ;
if ( V_4 == NULL )
return F_42 ( - V_76 ) ;
V_70 -> V_4 = V_4 ;
F_33 ( & V_64 ) ;
return * V_62 ? F_38 ( V_2 , V_74 -> V_75 , * V_62 - 1 )
: V_77 ;
}
static void * F_43 ( struct V_73 * V_74 , void * V_78 , T_4 * V_62 )
{
struct V_69 * V_70 = V_74 -> V_75 ;
struct V_2 * V_2 = F_41 ( V_74 ) ;
struct V_1 * V_4 = V_70 -> V_4 ;
++ * V_62 ;
if ( V_78 == V_77 )
return F_38 ( V_2 , V_70 , 0 ) ;
while ( ++ V_70 -> V_65 < V_4 -> V_71 ) {
if ( ! F_39 ( V_4 , V_70 -> V_65 ) )
continue;
return & V_4 -> V_72 [ V_70 -> V_65 ] ;
}
return NULL ;
}
static void F_44 ( struct V_73 * V_74 , void * V_78 )
__releases( V_64 )
{
F_35 ( & V_64 ) ;
}
static int F_45 ( struct V_73 * V_74 , void * V_78 )
{
struct V_69 * V_70 = V_74 -> V_75 ;
struct V_1 * V_4 = V_70 -> V_4 ;
if ( V_78 == V_77 ) {
F_46 ( V_74 ,
L_1 ) ;
} else {
const struct V_68 * V_79 = V_78 ;
const char * V_80 = V_79 -> V_81 ? V_79 -> V_81 -> V_80 : L_2 ;
F_47 ( V_74 ,
L_3 ,
V_79 - V_4 -> V_72 ,
V_80 , V_79 -> V_82 , V_79 -> V_83 ,
V_79 -> V_84 , V_79 -> V_85 ,
V_79 -> V_19 ) ;
}
return 0 ;
}
static int F_48 ( struct V_86 * V_86 , struct V_87 * V_87 )
{
return F_49 ( V_86 , V_87 , & V_88 ,
sizeof( struct V_69 ) ) ;
}
static void * F_50 ( struct V_73 * V_74 , T_4 * V_62 )
{
struct V_60 * V_61 = V_74 -> V_75 ;
struct V_2 * V_2 = F_41 ( V_74 ) ;
struct V_1 * V_4 ;
V_4 = F_1 ( V_2 , V_44 ) ;
if ( V_4 == NULL )
return F_42 ( - V_76 ) ;
V_61 -> V_4 = V_4 ;
return * V_62 ? F_32 ( V_2 , V_74 -> V_75 , * V_62 - 1 )
: V_77 ;
}
static void * F_51 ( struct V_73 * V_74 , void * V_78 , T_4 * V_62 )
{
struct V_59 * V_63 = V_78 ;
struct V_60 * V_61 = V_74 -> V_75 ;
struct V_2 * V_2 = F_41 ( V_74 ) ;
struct V_1 * V_4 = V_61 -> V_4 ;
++ * V_62 ;
if ( V_78 == V_77 )
return F_32 ( V_2 , V_74 -> V_75 , 0 ) ;
if ( V_63 -> V_49 . V_48 != V_61 -> V_66 )
return F_52 ( V_63 -> V_49 . V_48 , struct V_59 , V_49 ) ;
if ( V_61 -> V_66 == & V_4 -> V_55 )
goto V_89;
F_53 ( V_61 -> V_66 != & V_4 -> V_54 [ V_61 -> V_65 ] ) ;
while ( ++ V_61 -> V_65 < V_53 ) {
V_61 -> V_66 = & V_4 -> V_54 [ V_61 -> V_65 ] ;
if ( F_54 ( V_61 -> V_66 ) )
continue;
return F_55 ( V_61 -> V_66 , struct V_59 , V_49 ) ;
}
F_35 ( & V_64 ) ;
V_61 -> V_66 = & V_4 -> V_55 ;
V_61 -> V_65 = 0 ;
F_36 ( & V_67 ) ;
if ( ! F_54 ( V_61 -> V_66 ) )
return F_55 ( V_61 -> V_66 , struct V_59 , V_49 ) ;
V_89:
F_37 ( & V_67 ) ;
V_61 -> V_66 = NULL ;
return NULL ;
}
static void F_56 ( struct V_73 * V_74 , void * V_78 )
{
struct V_60 * V_61 = V_74 -> V_75 ;
struct V_1 * V_4 = V_61 -> V_4 ;
if ( V_61 -> V_66 == & V_4 -> V_55 )
F_37 ( & V_67 ) ;
else if ( V_61 -> V_66 == V_4 -> V_54 )
F_35 ( & V_64 ) ;
}
static int F_57 ( struct V_73 * V_74 , void * V_78 )
{
int V_90 ;
if ( V_78 == V_77 ) {
F_46 ( V_74 ,
L_4
L_5
L_6 ) ;
} else {
const struct V_59 * V_63 = V_78 ;
const struct V_60 * V_61 = V_74 -> V_75 ;
struct V_1 * V_4 = V_61 -> V_4 ;
F_47 ( V_74 , L_7 ,
& V_63 -> V_91 , & V_63 -> V_92 ,
V_63 -> V_93 ) ;
if ( V_61 -> V_66 != & V_4 -> V_55 ) {
F_47 ( V_74 , L_8 ,
V_63 -> V_94 . V_8 . V_95 ,
V_63 -> V_94 . V_8 . V_96 ,
V_63 -> V_94 . V_8 . V_97 ) ;
for ( V_90 = V_63 -> V_94 . V_8 . V_98 ;
V_90 < V_63 -> V_94 . V_8 . V_71 ; V_90 ++ ) {
if ( F_39 ( V_4 , V_90 ) &&
V_63 -> V_94 . V_8 . V_99 [ V_90 ] < 255 )
F_47 ( V_74 ,
L_9 ,
V_90 , V_63 -> V_94 . V_8 . V_99 [ V_90 ] ) ;
}
} else {
F_47 ( V_74 , L_8 , 0ul , 0ul , 0ul ) ;
}
F_58 ( V_74 , '\n' ) ;
}
return 0 ;
}
static int F_59 ( struct V_86 * V_86 , struct V_87 * V_87 )
{
return F_49 ( V_86 , V_87 , & V_100 ,
sizeof( struct V_60 ) ) ;
}
static int F_60 ( struct V_31 * V_32 )
{
struct V_101 * V_102 ;
struct V_103 * V_104 ;
struct V_105 * V_106 = NULL ;
struct V_2 * V_2 = F_61 ( V_32 -> V_81 ) ;
struct V_1 * V_4 ;
struct V_5 V_107 = {
. V_108 = V_32 -> V_81 -> V_109 ,
. V_110 = V_32 -> V_111 ,
} ;
int V_112 ;
if ( ! F_62 ( V_32 , sizeof( * V_102 ) + sizeof( * V_104 ) ) )
goto V_113;
V_102 = (struct V_101 * ) F_63 ( V_32 ) ;
if ( V_102 -> type != ( ( V_114 << 4 ) | V_115 ) ||
( V_102 -> V_19 & V_116 ) ||
( F_64 ( & F_65 ( V_32 ) -> V_117 , & F_65 ( V_32 ) -> V_118 ,
sizeof( * V_102 ) , V_119 ,
F_66 ( ( void * ) V_102 , sizeof( * V_102 ) , 0 ) ) &&
F_67 ( F_68 ( V_32 , 0 , V_32 -> V_120 , 0 ) ) ) )
goto V_113;
V_104 = (struct V_103 * ) ( F_63 ( V_32 ) +
sizeof( * V_102 ) ) ;
if ( ! F_69 ( & V_104 -> V_118 ) ||
V_104 -> V_121 == 0 ||
F_70 ( V_104 -> V_121 ) + sizeof( * V_102 ) > V_32 -> V_120 )
goto V_113;
if ( F_3 ( V_2 , & V_107 , & V_4 ) < 0 )
goto V_113;
V_112 = V_4 -> V_58 ;
F_33 ( & V_64 ) ;
if ( V_112 >= 0 )
V_106 = V_4 -> V_72 [ V_112 ] . V_81 ;
if ( V_106 )
F_71 ( V_106 ) ;
F_35 ( & V_64 ) ;
if ( V_106 == NULL )
goto V_113;
V_32 -> V_122 = V_32 -> V_123 ;
F_72 ( V_32 , ( V_124 * ) V_104 - V_32 -> V_125 ) ;
F_73 ( V_32 ) ;
V_32 -> V_126 = F_74 ( V_127 ) ;
V_32 -> V_128 = V_129 ;
V_32 -> V_130 = V_131 ;
F_75 ( V_32 , V_106 ) ;
F_76 ( V_32 ) ;
F_77 ( V_106 ) ;
return 0 ;
V_113:
F_78 ( V_32 ) ;
return 0 ;
}
static T_5 F_79 ( struct V_31 * V_32 ,
struct V_105 * V_81 )
{
struct V_2 * V_2 = F_61 ( V_81 ) ;
struct V_1 * V_4 ;
struct V_5 V_107 = {
. V_132 = V_81 -> V_109 ,
. V_108 = V_32 -> V_133 ,
. V_110 = V_32 -> V_111 ,
} ;
int V_12 ;
V_12 = F_3 ( V_2 , & V_107 , & V_4 ) ;
if ( V_12 < 0 ) {
F_78 ( V_32 ) ;
return V_12 ;
}
F_33 ( & V_64 ) ;
V_81 -> V_134 . V_135 += V_32 -> V_120 ;
V_81 -> V_134 . V_136 ++ ;
F_80 ( V_4 , V_32 , V_4 -> V_58 , V_137 ) ;
F_35 ( & V_64 ) ;
F_78 ( V_32 ) ;
return V_138 ;
}
static void F_81 ( struct V_105 * V_81 )
{
V_81 -> type = V_139 ;
V_81 -> V_140 = 1500 - sizeof( struct V_103 ) - 8 ;
V_81 -> V_19 = V_141 ;
V_81 -> V_142 = & V_143 ;
V_81 -> V_144 = V_145 ;
V_81 -> V_146 |= V_147 ;
}
static struct V_105 * F_82 ( struct V_2 * V_2 , struct V_1 * V_4 )
{
struct V_105 * V_81 ;
char V_80 [ V_148 ] ;
if ( V_4 -> V_3 == V_44 )
sprintf ( V_80 , L_10 ) ;
else
sprintf ( V_80 , L_11 , V_4 -> V_3 ) ;
V_81 = F_83 ( 0 , V_80 , F_81 ) ;
if ( V_81 == NULL )
return NULL ;
F_84 ( V_81 , V_2 ) ;
if ( F_85 ( V_81 ) ) {
V_145 ( V_81 ) ;
return NULL ;
}
V_81 -> V_149 = 0 ;
if ( F_86 ( V_81 ) )
goto V_150;
F_71 ( V_81 ) ;
return V_81 ;
V_150:
F_87 () ;
F_88 () ;
F_89 ( V_81 ) ;
return NULL ;
}
static int F_90 ( struct V_1 * V_4 , int V_151 , struct V_152 * V_153 )
{
struct V_68 * V_78 ;
struct V_105 * V_81 ;
struct V_154 * V_155 ;
if ( V_151 < 0 || V_151 >= V_4 -> V_71 )
return - V_156 ;
V_78 = & V_4 -> V_72 [ V_151 ] ;
F_91 ( & V_64 ) ;
V_81 = V_78 -> V_81 ;
V_78 -> V_81 = NULL ;
if ( ! V_81 ) {
F_92 ( & V_64 ) ;
return - V_156 ;
}
#ifdef F_27
if ( V_151 == V_4 -> V_58 )
V_4 -> V_58 = - 1 ;
#endif
if ( V_151 + 1 == V_4 -> V_71 ) {
int V_157 ;
for ( V_157 = V_151 - 1 ; V_157 >= 0 ; V_157 -- ) {
if ( F_39 ( V_4 , V_157 ) )
break;
}
V_4 -> V_71 = V_157 + 1 ;
}
F_92 ( & V_64 ) ;
F_93 ( V_81 , - 1 ) ;
V_155 = F_94 ( V_81 ) ;
if ( V_155 ) {
V_155 -> V_158 . V_159 -- ;
F_95 ( F_61 ( V_81 ) ,
V_160 ,
V_81 -> V_109 , & V_155 -> V_158 ) ;
}
if ( V_78 -> V_19 & V_161 )
F_96 ( V_81 , V_153 ) ;
F_77 ( V_81 ) ;
return 0 ;
}
static inline void F_97 ( struct V_59 * V_162 )
{
F_98 ( V_163 , V_162 ) ;
}
static void F_99 ( struct V_1 * V_4 , struct V_59 * V_162 )
{
struct V_2 * V_2 = F_100 ( & V_4 -> V_2 ) ;
struct V_31 * V_32 ;
F_101 ( & V_4 -> V_164 ) ;
while( ( V_32 = F_102 ( & V_162 -> V_94 . V_165 . V_166 ) ) != NULL ) {
if ( F_65 ( V_32 ) -> V_167 == 0 ) {
struct V_168 * V_169 = (struct V_168 * ) F_72 ( V_32 , sizeof( struct V_103 ) ) ;
V_169 -> V_170 = V_171 ;
V_169 -> V_172 = F_103 ( sizeof( struct V_173 ) ) ;
F_104 ( V_32 , V_169 -> V_172 ) ;
( (struct V_173 * ) F_105 ( V_169 ) ) -> error = - V_174 ;
F_106 ( V_32 , V_2 , F_107 ( V_32 ) . V_175 ) ;
} else
F_78 ( V_32 ) ;
}
F_97 ( V_162 ) ;
}
static void F_108 ( struct V_1 * V_4 )
{
unsigned long V_176 = V_177 ;
unsigned long V_178 = 10 * V_179 ;
struct V_59 * V_162 , * V_48 ;
F_21 (c, next, &mrt->mfc6_unres_queue, list) {
if ( F_109 ( V_162 -> V_94 . V_165 . V_178 , V_176 ) ) {
unsigned long V_180 = V_162 -> V_94 . V_165 . V_178 - V_176 ;
if ( V_180 < V_178 )
V_178 = V_180 ;
continue;
}
F_22 ( & V_162 -> V_49 ) ;
F_110 ( V_4 , V_162 , V_181 ) ;
F_99 ( V_4 , V_162 ) ;
}
if ( ! F_54 ( & V_4 -> V_55 ) )
F_111 ( & V_4 -> V_56 , V_177 + V_178 ) ;
}
static void V_57 ( unsigned long V_10 )
{
struct V_1 * V_4 = (struct V_1 * ) V_10 ;
if ( ! F_112 ( & V_67 ) ) {
F_111 ( & V_4 -> V_56 , V_177 + 1 ) ;
return;
}
if ( ! F_54 ( & V_4 -> V_55 ) )
F_108 ( V_4 ) ;
F_113 ( & V_67 ) ;
}
static void F_114 ( struct V_1 * V_4 , struct V_59 * V_66 ,
unsigned char * V_99 )
{
int V_151 ;
V_66 -> V_94 . V_8 . V_98 = V_182 ;
V_66 -> V_94 . V_8 . V_71 = 0 ;
memset ( V_66 -> V_94 . V_8 . V_99 , 255 , V_182 ) ;
for ( V_151 = 0 ; V_151 < V_4 -> V_71 ; V_151 ++ ) {
if ( F_39 ( V_4 , V_151 ) &&
V_99 [ V_151 ] && V_99 [ V_151 ] < 255 ) {
V_66 -> V_94 . V_8 . V_99 [ V_151 ] = V_99 [ V_151 ] ;
if ( V_66 -> V_94 . V_8 . V_98 > V_151 )
V_66 -> V_94 . V_8 . V_98 = V_151 ;
if ( V_66 -> V_94 . V_8 . V_71 <= V_151 )
V_66 -> V_94 . V_8 . V_71 = V_151 + 1 ;
}
}
}
static int F_115 ( struct V_2 * V_2 , struct V_1 * V_4 ,
struct V_183 * V_184 , int V_185 )
{
int V_151 = V_184 -> V_186 ;
struct V_68 * V_78 = & V_4 -> V_72 [ V_151 ] ;
struct V_105 * V_81 ;
struct V_154 * V_155 ;
int V_12 ;
if ( F_39 ( V_4 , V_151 ) )
return - V_187 ;
switch ( V_184 -> V_188 ) {
#ifdef F_27
case V_161 :
if ( V_4 -> V_58 >= 0 )
return - V_187 ;
V_81 = F_82 ( V_2 , V_4 ) ;
if ( ! V_81 )
return - V_189 ;
V_12 = F_93 ( V_81 , 1 ) ;
if ( V_12 ) {
F_89 ( V_81 ) ;
F_77 ( V_81 ) ;
return V_12 ;
}
break;
#endif
case 0 :
V_81 = F_116 ( V_2 , V_184 -> V_190 ) ;
if ( ! V_81 )
return - V_156 ;
V_12 = F_93 ( V_81 , 1 ) ;
if ( V_12 ) {
F_77 ( V_81 ) ;
return V_12 ;
}
break;
default:
return - V_27 ;
}
V_155 = F_94 ( V_81 ) ;
if ( V_155 ) {
V_155 -> V_158 . V_159 ++ ;
F_95 ( F_61 ( V_81 ) ,
V_160 ,
V_81 -> V_109 , & V_155 -> V_158 ) ;
}
V_78 -> V_191 = V_184 -> V_192 ;
V_78 -> V_19 = V_184 -> V_188 ;
if ( ! V_185 )
V_78 -> V_19 |= V_193 ;
V_78 -> V_194 = V_184 -> V_195 ;
V_78 -> V_82 = 0 ;
V_78 -> V_84 = 0 ;
V_78 -> V_83 = 0 ;
V_78 -> V_85 = 0 ;
V_78 -> V_196 = V_81 -> V_109 ;
if ( V_78 -> V_19 & V_161 )
V_78 -> V_196 = V_81 -> V_149 ;
F_91 ( & V_64 ) ;
V_78 -> V_81 = V_81 ;
#ifdef F_27
if ( V_78 -> V_19 & V_161 )
V_4 -> V_58 = V_151 ;
#endif
if ( V_151 + 1 > V_4 -> V_71 )
V_4 -> V_71 = V_151 + 1 ;
F_92 ( & V_64 ) ;
return 0 ;
}
static struct V_59 * F_117 ( struct V_1 * V_4 ,
const struct V_197 * V_198 ,
const struct V_197 * V_199 )
{
int line = F_118 ( V_199 , V_198 ) ;
struct V_59 * V_162 ;
F_34 (c, &mrt->mfc6_cache_array[line], list) {
if ( F_119 ( & V_162 -> V_92 , V_198 ) &&
F_119 ( & V_162 -> V_91 , V_199 ) )
return V_162 ;
}
return NULL ;
}
static struct V_59 * F_120 ( void )
{
struct V_59 * V_162 = F_121 ( V_163 , V_52 ) ;
if ( V_162 == NULL )
return NULL ;
V_162 -> V_94 . V_8 . V_98 = V_182 ;
return V_162 ;
}
static struct V_59 * F_122 ( void )
{
struct V_59 * V_162 = F_121 ( V_163 , V_200 ) ;
if ( V_162 == NULL )
return NULL ;
F_123 ( & V_162 -> V_94 . V_165 . V_166 ) ;
V_162 -> V_94 . V_165 . V_178 = V_177 + 10 * V_179 ;
return V_162 ;
}
static void F_124 ( struct V_2 * V_2 , struct V_1 * V_4 ,
struct V_59 * V_201 , struct V_59 * V_162 )
{
struct V_31 * V_32 ;
while( ( V_32 = F_125 ( & V_201 -> V_94 . V_165 . V_166 ) ) ) {
if ( F_65 ( V_32 ) -> V_167 == 0 ) {
struct V_168 * V_169 = (struct V_168 * ) F_72 ( V_32 , sizeof( struct V_103 ) ) ;
if ( F_126 ( V_4 , V_32 , V_162 , F_105 ( V_169 ) ) > 0 ) {
V_169 -> V_172 = F_127 ( V_32 ) - ( V_124 * ) V_169 ;
} else {
V_169 -> V_170 = V_171 ;
V_169 -> V_172 = F_103 ( sizeof( struct V_173 ) ) ;
F_104 ( V_32 , V_169 -> V_172 ) ;
( (struct V_173 * ) F_105 ( V_169 ) ) -> error = - V_202 ;
}
F_106 ( V_32 , V_2 , F_107 ( V_32 ) . V_175 ) ;
} else
F_128 ( V_2 , V_4 , V_32 , V_162 ) ;
}
}
static int F_80 ( struct V_1 * V_4 , struct V_31 * V_95 ,
T_6 V_203 , int assert )
{
struct V_31 * V_32 ;
struct V_204 * V_205 ;
int V_206 ;
#ifdef F_27
if ( assert == V_137 )
V_32 = F_129 ( V_95 , - F_130 ( V_95 )
+ sizeof( * V_205 ) ) ;
else
#endif
V_32 = F_131 ( sizeof( struct V_103 ) + sizeof( * V_205 ) , V_200 ) ;
if ( ! V_32 )
return - V_189 ;
V_32 -> V_128 = V_207 ;
#ifdef F_27
if ( assert == V_137 ) {
F_132 ( V_32 , - F_130 ( V_95 ) ) ;
F_132 ( V_32 , sizeof( * V_205 ) ) ;
F_133 ( V_32 ) ;
V_205 = (struct V_204 * ) F_63 ( V_32 ) ;
V_205 -> V_208 = 0 ;
V_205 -> V_209 = V_137 ;
V_205 -> V_210 = V_4 -> V_58 ;
V_205 -> V_211 = 0 ;
V_205 -> V_212 = F_65 ( V_95 ) -> V_117 ;
V_205 -> V_213 = F_65 ( V_95 ) -> V_118 ;
V_32 -> V_128 = V_207 ;
} else
#endif
{
F_134 ( V_32 , sizeof( struct V_103 ) ) ;
F_73 ( V_32 ) ;
F_135 ( V_32 , F_65 ( V_95 ) , sizeof( struct V_103 ) ) ;
F_134 ( V_32 , sizeof( * V_205 ) ) ;
F_133 ( V_32 ) ;
V_205 = (struct V_204 * ) F_63 ( V_32 ) ;
V_205 -> V_208 = 0 ;
V_205 -> V_209 = assert ;
V_205 -> V_210 = V_203 ;
V_205 -> V_211 = 0 ;
V_205 -> V_212 = F_65 ( V_95 ) -> V_117 ;
V_205 -> V_213 = F_65 ( V_95 ) -> V_118 ;
F_136 ( V_32 , F_137 ( F_138 ( V_95 ) ) ) ;
V_32 -> V_128 = V_207 ;
}
if ( V_4 -> V_214 == NULL ) {
F_78 ( V_32 ) ;
return - V_27 ;
}
V_206 = F_139 ( V_4 -> V_214 , V_32 ) ;
if ( V_206 < 0 ) {
F_140 ( L_12 ) ;
F_78 ( V_32 ) ;
}
return V_206 ;
}
static int
F_141 ( struct V_1 * V_4 , T_6 V_203 , struct V_31 * V_32 )
{
bool V_215 = false ;
int V_12 ;
struct V_59 * V_162 ;
F_36 ( & V_67 ) ;
F_34 (c, &mrt->mfc6_unres_queue, list) {
if ( F_119 ( & V_162 -> V_91 , & F_65 ( V_32 ) -> V_118 ) &&
F_119 ( & V_162 -> V_92 , & F_65 ( V_32 ) -> V_117 ) ) {
V_215 = true ;
break;
}
}
if ( ! V_215 ) {
if ( F_142 ( & V_4 -> V_164 ) >= 10 ||
( V_162 = F_122 () ) == NULL ) {
F_37 ( & V_67 ) ;
F_78 ( V_32 ) ;
return - V_189 ;
}
V_162 -> V_93 = - 1 ;
V_162 -> V_92 = F_65 ( V_32 ) -> V_117 ;
V_162 -> V_91 = F_65 ( V_32 ) -> V_118 ;
V_12 = F_80 ( V_4 , V_32 , V_203 , V_216 ) ;
if ( V_12 < 0 ) {
F_37 ( & V_67 ) ;
F_97 ( V_162 ) ;
F_78 ( V_32 ) ;
return V_12 ;
}
F_143 ( & V_4 -> V_164 ) ;
F_144 ( & V_162 -> V_49 , & V_4 -> V_55 ) ;
F_110 ( V_4 , V_162 , V_217 ) ;
F_108 ( V_4 ) ;
}
if ( V_162 -> V_94 . V_165 . V_166 . V_218 > 3 ) {
F_78 ( V_32 ) ;
V_12 = - V_189 ;
} else {
F_145 ( & V_162 -> V_94 . V_165 . V_166 , V_32 ) ;
V_12 = 0 ;
}
F_37 ( & V_67 ) ;
return V_12 ;
}
static int F_146 ( struct V_1 * V_4 , struct V_219 * V_63 )
{
int line ;
struct V_59 * V_162 , * V_48 ;
line = F_118 ( & V_63 -> V_220 . V_221 , & V_63 -> V_222 . V_221 ) ;
F_21 (c, next, &mrt->mfc6_cache_array[line], list) {
if ( F_119 ( & V_162 -> V_92 , & V_63 -> V_222 . V_221 ) &&
F_119 ( & V_162 -> V_91 , & V_63 -> V_220 . V_221 ) ) {
F_91 ( & V_64 ) ;
F_22 ( & V_162 -> V_49 ) ;
F_92 ( & V_64 ) ;
F_110 ( V_4 , V_162 , V_181 ) ;
F_97 ( V_162 ) ;
return 0 ;
}
}
return - V_76 ;
}
static int F_147 ( struct V_223 * V_224 ,
unsigned long V_225 , void * V_226 )
{
struct V_105 * V_81 = V_226 ;
struct V_2 * V_2 = F_61 ( V_81 ) ;
struct V_1 * V_4 ;
struct V_68 * V_78 ;
int V_65 ;
F_148 ( V_49 ) ;
if ( V_225 != V_227 )
return V_228 ;
F_2 (mrt, net) {
V_78 = & V_4 -> V_72 [ 0 ] ;
for ( V_65 = 0 ; V_65 < V_4 -> V_71 ; V_65 ++ , V_78 ++ ) {
if ( V_78 -> V_81 == V_81 )
F_90 ( V_4 , V_65 , & V_49 ) ;
}
}
F_149 ( & V_49 ) ;
return V_228 ;
}
static int T_2 F_150 ( struct V_2 * V_2 )
{
int V_12 ;
V_12 = F_11 ( V_2 ) ;
if ( V_12 < 0 )
goto V_229;
#ifdef F_151
V_12 = - V_45 ;
if ( ! F_152 ( V_2 , L_13 , 0 , & V_230 ) )
goto V_231;
if ( ! F_152 ( V_2 , L_14 , 0 , & V_232 ) )
goto V_233;
#endif
return 0 ;
#ifdef F_151
V_233:
F_153 ( V_2 , L_13 ) ;
V_231:
F_20 ( V_2 ) ;
#endif
V_229:
return V_12 ;
}
static void T_3 F_154 ( struct V_2 * V_2 )
{
#ifdef F_151
F_153 ( V_2 , L_14 ) ;
F_153 ( V_2 , L_13 ) ;
#endif
F_20 ( V_2 ) ;
}
int T_7 F_155 ( void )
{
int V_12 ;
V_163 = F_156 ( L_15 ,
sizeof( struct V_59 ) ,
0 , V_234 ,
NULL ) ;
if ( ! V_163 )
return - V_45 ;
V_12 = F_157 ( & V_235 ) ;
if ( V_12 )
goto V_236;
V_12 = F_158 ( & V_237 ) ;
if ( V_12 )
goto V_238;
#ifdef F_27
if ( F_159 ( & V_239 , V_119 ) < 0 ) {
F_160 ( L_16 , V_240 ) ;
V_12 = - V_30 ;
goto V_241;
}
#endif
F_161 ( V_242 , V_243 , NULL ,
V_244 , NULL ) ;
return 0 ;
#ifdef F_27
V_241:
F_162 ( & V_237 ) ;
#endif
V_238:
F_163 ( & V_235 ) ;
V_236:
F_164 ( V_163 ) ;
return V_12 ;
}
void F_165 ( void )
{
F_162 ( & V_237 ) ;
F_163 ( & V_235 ) ;
F_164 ( V_163 ) ;
}
static int F_166 ( struct V_2 * V_2 , struct V_1 * V_4 ,
struct V_219 * V_63 , int V_185 )
{
bool V_215 = false ;
int line ;
struct V_59 * V_201 , * V_162 ;
unsigned char V_99 [ V_182 ] ;
int V_51 ;
if ( V_63 -> V_245 >= V_182 )
return - V_246 ;
memset ( V_99 , 255 , V_182 ) ;
for ( V_51 = 0 ; V_51 < V_182 ; V_51 ++ ) {
if ( F_167 ( V_51 , & V_63 -> V_247 ) )
V_99 [ V_51 ] = 1 ;
}
line = F_118 ( & V_63 -> V_220 . V_221 , & V_63 -> V_222 . V_221 ) ;
F_34 (c, &mrt->mfc6_cache_array[line], list) {
if ( F_119 ( & V_162 -> V_92 , & V_63 -> V_222 . V_221 ) &&
F_119 ( & V_162 -> V_91 , & V_63 -> V_220 . V_221 ) ) {
V_215 = true ;
break;
}
}
if ( V_215 ) {
F_91 ( & V_64 ) ;
V_162 -> V_93 = V_63 -> V_245 ;
F_114 ( V_4 , V_162 , V_99 ) ;
if ( ! V_185 )
V_162 -> V_248 |= V_249 ;
F_92 ( & V_64 ) ;
F_110 ( V_4 , V_162 , V_217 ) ;
return 0 ;
}
if ( ! F_69 ( & V_63 -> V_220 . V_221 ) )
return - V_27 ;
V_162 = F_120 () ;
if ( V_162 == NULL )
return - V_45 ;
V_162 -> V_92 = V_63 -> V_222 . V_221 ;
V_162 -> V_91 = V_63 -> V_220 . V_221 ;
V_162 -> V_93 = V_63 -> V_245 ;
F_114 ( V_4 , V_162 , V_99 ) ;
if ( ! V_185 )
V_162 -> V_248 |= V_249 ;
F_91 ( & V_64 ) ;
F_144 ( & V_162 -> V_49 , & V_4 -> V_54 [ line ] ) ;
F_92 ( & V_64 ) ;
V_215 = false ;
F_36 ( & V_67 ) ;
F_34 (uc, &mrt->mfc6_unres_queue, list) {
if ( F_119 ( & V_201 -> V_92 , & V_162 -> V_92 ) &&
F_119 ( & V_201 -> V_91 , & V_162 -> V_91 ) ) {
F_22 ( & V_201 -> V_49 ) ;
F_101 ( & V_4 -> V_164 ) ;
V_215 = true ;
break;
}
}
if ( F_54 ( & V_4 -> V_55 ) )
F_30 ( & V_4 -> V_56 ) ;
F_37 ( & V_67 ) ;
if ( V_215 ) {
F_124 ( V_2 , V_4 , V_201 , V_162 ) ;
F_97 ( V_201 ) ;
}
F_110 ( V_4 , V_162 , V_217 ) ;
return 0 ;
}
static void F_31 ( struct V_1 * V_4 )
{
int V_51 ;
F_148 ( V_49 ) ;
struct V_59 * V_162 , * V_48 ;
for ( V_51 = 0 ; V_51 < V_4 -> V_71 ; V_51 ++ ) {
if ( ! ( V_4 -> V_72 [ V_51 ] . V_19 & V_193 ) )
F_90 ( V_4 , V_51 , & V_49 ) ;
}
F_149 ( & V_49 ) ;
for ( V_51 = 0 ; V_51 < V_53 ; V_51 ++ ) {
F_21 (c, next, &mrt->mfc6_cache_array[i], list) {
if ( V_162 -> V_248 & V_249 )
continue;
F_91 ( & V_64 ) ;
F_22 ( & V_162 -> V_49 ) ;
F_92 ( & V_64 ) ;
F_110 ( V_4 , V_162 , V_181 ) ;
F_97 ( V_162 ) ;
}
}
if ( F_142 ( & V_4 -> V_164 ) != 0 ) {
F_36 ( & V_67 ) ;
F_21 (c, next, &mrt->mfc6_unres_queue, list) {
F_22 ( & V_162 -> V_49 ) ;
F_110 ( V_4 , V_162 , V_181 ) ;
F_99 ( V_4 , V_162 ) ;
}
F_37 ( & V_67 ) ;
}
}
static int F_168 ( struct V_1 * V_4 , struct V_250 * V_251 )
{
int V_12 = 0 ;
struct V_2 * V_2 = F_169 ( V_251 ) ;
F_88 () ;
F_91 ( & V_64 ) ;
if ( F_170 ( V_4 -> V_214 == NULL ) ) {
V_4 -> V_214 = V_251 ;
V_2 -> V_13 . V_252 -> V_159 ++ ;
F_95 ( V_2 , V_160 ,
V_253 ,
V_2 -> V_13 . V_252 ) ;
}
else
V_12 = - V_187 ;
F_92 ( & V_64 ) ;
F_87 () ;
return V_12 ;
}
int F_171 ( struct V_250 * V_251 )
{
int V_12 = - V_25 ;
struct V_2 * V_2 = F_169 ( V_251 ) ;
struct V_1 * V_4 ;
F_88 () ;
F_2 (mrt, net) {
if ( V_251 == V_4 -> V_214 ) {
F_91 ( & V_64 ) ;
V_4 -> V_214 = NULL ;
V_2 -> V_13 . V_252 -> V_159 -- ;
F_95 ( V_2 ,
V_160 ,
V_253 ,
V_2 -> V_13 . V_252 ) ;
F_92 ( & V_64 ) ;
F_31 ( V_4 ) ;
V_12 = 0 ;
break;
}
}
F_87 () ;
return V_12 ;
}
struct V_250 * F_172 ( struct V_2 * V_2 , struct V_31 * V_32 )
{
struct V_1 * V_4 ;
struct V_5 V_107 = {
. V_108 = V_32 -> V_133 ,
. V_132 = V_32 -> V_81 -> V_109 ,
. V_110 = V_32 -> V_111 ,
} ;
if ( F_3 ( V_2 , & V_107 , & V_4 ) < 0 )
return NULL ;
return V_4 -> V_214 ;
}
int F_173 ( struct V_250 * V_251 , int V_254 , char T_8 * V_255 , unsigned int V_256 )
{
int V_206 ;
struct V_183 V_79 ;
struct V_219 V_63 ;
T_6 V_203 ;
struct V_2 * V_2 = F_169 ( V_251 ) ;
struct V_1 * V_4 ;
V_4 = F_1 ( V_2 , F_174 ( V_251 ) -> V_257 ? : V_44 ) ;
if ( V_4 == NULL )
return - V_76 ;
if ( V_254 != V_258 ) {
if ( V_251 != V_4 -> V_214 && ! F_175 ( V_2 -> V_259 , V_260 ) )
return - V_25 ;
}
switch ( V_254 ) {
case V_258 :
if ( V_251 -> V_261 != V_262 ||
F_176 ( V_251 ) -> V_263 != V_264 )
return - V_265 ;
if ( V_256 < sizeof( int ) )
return - V_27 ;
return F_168 ( V_4 , V_251 ) ;
case V_266 :
return F_171 ( V_251 ) ;
case V_267 :
if ( V_256 < sizeof( V_79 ) )
return - V_27 ;
if ( F_177 ( & V_79 , V_255 , sizeof( V_79 ) ) )
return - V_268 ;
if ( V_79 . V_186 >= V_182 )
return - V_246 ;
F_88 () ;
V_206 = F_115 ( V_2 , V_4 , & V_79 , V_251 == V_4 -> V_214 ) ;
F_87 () ;
return V_206 ;
case V_269 :
if ( V_256 < sizeof( T_6 ) )
return - V_27 ;
if ( F_177 ( & V_203 , V_255 , sizeof( T_6 ) ) )
return - V_268 ;
F_88 () ;
V_206 = F_90 ( V_4 , V_203 , NULL ) ;
F_87 () ;
return V_206 ;
case V_270 :
case V_271 :
if ( V_256 < sizeof( V_63 ) )
return - V_27 ;
if ( F_177 ( & V_63 , V_255 , sizeof( V_63 ) ) )
return - V_268 ;
F_88 () ;
if ( V_254 == V_271 )
V_206 = F_146 ( V_4 , & V_63 ) ;
else
V_206 = F_166 ( V_2 , V_4 , & V_63 , V_251 == V_4 -> V_214 ) ;
F_87 () ;
return V_206 ;
case V_272 :
{
int V_78 ;
if ( V_256 != sizeof( V_78 ) )
return - V_27 ;
if ( F_178 ( V_78 , ( int T_8 * ) V_255 ) )
return - V_268 ;
V_4 -> V_273 = V_78 ;
return 0 ;
}
#ifdef F_27
case V_274 :
{
int V_78 ;
if ( V_256 != sizeof( V_78 ) )
return - V_27 ;
if ( F_178 ( V_78 , ( int T_8 * ) V_255 ) )
return - V_268 ;
V_78 = ! ! V_78 ;
F_88 () ;
V_206 = 0 ;
if ( V_78 != V_4 -> V_275 ) {
V_4 -> V_275 = V_78 ;
V_4 -> V_273 = V_78 ;
}
F_87 () ;
return V_206 ;
}
#endif
#ifdef F_28
case V_276 :
{
T_1 V_78 ;
if ( V_256 != sizeof( T_1 ) )
return - V_27 ;
if ( F_178 ( V_78 , ( T_1 T_8 * ) V_255 ) )
return - V_268 ;
if ( V_78 != V_277 && V_78 >= 100000000 )
return - V_27 ;
if ( V_251 == V_4 -> V_214 )
return - V_278 ;
F_88 () ;
V_206 = 0 ;
if ( ! F_16 ( V_2 , V_78 ) )
V_206 = - V_45 ;
F_174 ( V_251 ) -> V_257 = V_78 ;
F_87 () ;
return V_206 ;
}
#endif
default:
return - V_279 ;
}
}
int F_179 ( struct V_250 * V_251 , int V_254 , char T_8 * V_255 ,
int T_8 * V_256 )
{
int V_280 ;
int V_281 ;
struct V_2 * V_2 = F_169 ( V_251 ) ;
struct V_1 * V_4 ;
V_4 = F_1 ( V_2 , F_174 ( V_251 ) -> V_257 ? : V_44 ) ;
if ( V_4 == NULL )
return - V_76 ;
switch ( V_254 ) {
case V_282 :
V_281 = 0x0305 ;
break;
#ifdef F_27
case V_274 :
V_281 = V_4 -> V_275 ;
break;
#endif
case V_272 :
V_281 = V_4 -> V_273 ;
break;
default:
return - V_279 ;
}
if ( F_178 ( V_280 , V_256 ) )
return - V_268 ;
V_280 = F_180 ( int , V_280 , sizeof( int ) ) ;
if ( V_280 < 0 )
return - V_27 ;
if ( F_181 ( V_280 , V_256 ) )
return - V_268 ;
if ( F_182 ( V_255 , & V_281 , V_280 ) )
return - V_268 ;
return 0 ;
}
int F_183 ( struct V_250 * V_251 , int V_283 , void T_8 * V_10 )
{
struct V_284 V_285 ;
struct V_286 V_287 ;
struct V_68 * V_79 ;
struct V_59 * V_162 ;
struct V_2 * V_2 = F_169 ( V_251 ) ;
struct V_1 * V_4 ;
V_4 = F_1 ( V_2 , F_174 ( V_251 ) -> V_257 ? : V_44 ) ;
if ( V_4 == NULL )
return - V_76 ;
switch ( V_283 ) {
case V_288 :
if ( F_177 ( & V_287 , V_10 , sizeof( V_287 ) ) )
return - V_268 ;
if ( V_287 . V_203 >= V_4 -> V_71 )
return - V_27 ;
F_33 ( & V_64 ) ;
V_79 = & V_4 -> V_72 [ V_287 . V_203 ] ;
if ( F_39 ( V_4 , V_287 . V_203 ) ) {
V_287 . V_289 = V_79 -> V_83 ;
V_287 . V_290 = V_79 -> V_85 ;
V_287 . V_291 = V_79 -> V_82 ;
V_287 . V_292 = V_79 -> V_84 ;
F_35 ( & V_64 ) ;
if ( F_182 ( V_10 , & V_287 , sizeof( V_287 ) ) )
return - V_268 ;
return 0 ;
}
F_35 ( & V_64 ) ;
return - V_156 ;
case V_293 :
if ( F_177 ( & V_285 , V_10 , sizeof( V_285 ) ) )
return - V_268 ;
F_33 ( & V_64 ) ;
V_162 = F_117 ( V_4 , & V_285 . V_294 . V_221 , & V_285 . V_295 . V_221 ) ;
if ( V_162 ) {
V_285 . V_296 = V_162 -> V_94 . V_8 . V_95 ;
V_285 . V_297 = V_162 -> V_94 . V_8 . V_96 ;
V_285 . V_97 = V_162 -> V_94 . V_8 . V_97 ;
F_35 ( & V_64 ) ;
if ( F_182 ( V_10 , & V_285 , sizeof( V_285 ) ) )
return - V_268 ;
return 0 ;
}
F_35 ( & V_64 ) ;
return - V_156 ;
default:
return - V_298 ;
}
}
int F_184 ( struct V_250 * V_251 , unsigned int V_283 , void T_8 * V_10 )
{
struct V_299 V_285 ;
struct V_300 V_287 ;
struct V_68 * V_79 ;
struct V_59 * V_162 ;
struct V_2 * V_2 = F_169 ( V_251 ) ;
struct V_1 * V_4 ;
V_4 = F_1 ( V_2 , F_174 ( V_251 ) -> V_257 ? : V_44 ) ;
if ( V_4 == NULL )
return - V_76 ;
switch ( V_283 ) {
case V_288 :
if ( F_177 ( & V_287 , V_10 , sizeof( V_287 ) ) )
return - V_268 ;
if ( V_287 . V_203 >= V_4 -> V_71 )
return - V_27 ;
F_33 ( & V_64 ) ;
V_79 = & V_4 -> V_72 [ V_287 . V_203 ] ;
if ( F_39 ( V_4 , V_287 . V_203 ) ) {
V_287 . V_289 = V_79 -> V_83 ;
V_287 . V_290 = V_79 -> V_85 ;
V_287 . V_291 = V_79 -> V_82 ;
V_287 . V_292 = V_79 -> V_84 ;
F_35 ( & V_64 ) ;
if ( F_182 ( V_10 , & V_287 , sizeof( V_287 ) ) )
return - V_268 ;
return 0 ;
}
F_35 ( & V_64 ) ;
return - V_156 ;
case V_293 :
if ( F_177 ( & V_285 , V_10 , sizeof( V_285 ) ) )
return - V_268 ;
F_33 ( & V_64 ) ;
V_162 = F_117 ( V_4 , & V_285 . V_294 . V_221 , & V_285 . V_295 . V_221 ) ;
if ( V_162 ) {
V_285 . V_296 = V_162 -> V_94 . V_8 . V_95 ;
V_285 . V_297 = V_162 -> V_94 . V_8 . V_96 ;
V_285 . V_97 = V_162 -> V_94 . V_8 . V_97 ;
F_35 ( & V_64 ) ;
if ( F_182 ( V_10 , & V_285 , sizeof( V_285 ) ) )
return - V_268 ;
return 0 ;
}
F_35 ( & V_64 ) ;
return - V_156 ;
default:
return - V_298 ;
}
}
static inline int F_185 ( struct V_31 * V_32 )
{
F_186 ( F_61 ( F_138 ( V_32 ) -> V_81 ) , F_187 ( F_138 ( V_32 ) ) ,
V_301 ) ;
F_188 ( F_61 ( F_138 ( V_32 ) -> V_81 ) , F_187 ( F_138 ( V_32 ) ) ,
V_302 , V_32 -> V_120 ) ;
return F_189 ( V_32 ) ;
}
static int F_190 ( struct V_2 * V_2 , struct V_1 * V_4 ,
struct V_31 * V_32 , struct V_59 * V_162 , int V_151 )
{
struct V_103 * V_303 ;
struct V_68 * V_79 = & V_4 -> V_72 [ V_151 ] ;
struct V_105 * V_81 ;
struct V_304 * V_305 ;
struct V_5 V_107 ;
if ( V_79 -> V_81 == NULL )
goto V_306;
#ifdef F_27
if ( V_79 -> V_19 & V_161 ) {
V_79 -> V_85 ++ ;
V_79 -> V_84 += V_32 -> V_120 ;
V_79 -> V_81 -> V_134 . V_135 += V_32 -> V_120 ;
V_79 -> V_81 -> V_134 . V_136 ++ ;
F_80 ( V_4 , V_32 , V_151 , V_137 ) ;
goto V_306;
}
#endif
V_303 = F_65 ( V_32 ) ;
V_107 = (struct V_5 ) {
. V_132 = V_79 -> V_196 ,
. V_118 = V_303 -> V_118 ,
} ;
V_305 = F_191 ( V_2 , NULL , & V_107 ) ;
if ( V_305 -> error ) {
F_192 ( V_305 ) ;
goto V_306;
}
F_193 ( V_32 ) ;
F_136 ( V_32 , V_305 ) ;
V_81 = V_79 -> V_81 ;
V_32 -> V_81 = V_81 ;
V_79 -> V_85 ++ ;
V_79 -> V_84 += V_32 -> V_120 ;
if ( F_194 ( V_32 , sizeof( * V_303 ) + F_195 ( V_81 ) ) )
goto V_306;
V_303 = F_65 ( V_32 ) ;
V_303 -> V_307 -- ;
F_196 ( V_32 ) -> V_19 |= V_308 ;
return F_197 ( V_309 , V_310 , V_32 , V_32 -> V_81 , V_81 ,
F_185 ) ;
V_306:
F_78 ( V_32 ) ;
return 0 ;
}
static int F_198 ( struct V_1 * V_4 , struct V_105 * V_81 )
{
int V_65 ;
for ( V_65 = V_4 -> V_71 - 1 ; V_65 >= 0 ; V_65 -- ) {
if ( V_4 -> V_72 [ V_65 ] . V_81 == V_81 )
break;
}
return V_65 ;
}
static int F_128 ( struct V_2 * V_2 , struct V_1 * V_4 ,
struct V_31 * V_32 , struct V_59 * V_66 )
{
int V_311 = - 1 ;
int V_79 , V_65 ;
V_79 = V_66 -> V_93 ;
V_66 -> V_94 . V_8 . V_95 ++ ;
V_66 -> V_94 . V_8 . V_96 += V_32 -> V_120 ;
if ( V_4 -> V_72 [ V_79 ] . V_81 != V_32 -> V_81 ) {
int V_312 ;
V_66 -> V_94 . V_8 . V_97 ++ ;
V_312 = F_198 ( V_4 , V_32 -> V_81 ) ;
if ( V_312 >= 0 && V_4 -> V_273 &&
( V_4 -> V_275 ||
V_66 -> V_94 . V_8 . V_99 [ V_312 ] < 255 ) &&
F_109 ( V_177 ,
V_66 -> V_94 . V_8 . V_313 + V_314 ) ) {
V_66 -> V_94 . V_8 . V_313 = V_177 ;
F_80 ( V_4 , V_32 , V_312 , V_315 ) ;
}
goto V_316;
}
V_4 -> V_72 [ V_79 ] . V_83 ++ ;
V_4 -> V_72 [ V_79 ] . V_82 += V_32 -> V_120 ;
for ( V_65 = V_66 -> V_94 . V_8 . V_71 - 1 ; V_65 >= V_66 -> V_94 . V_8 . V_98 ; V_65 -- ) {
if ( F_65 ( V_32 ) -> V_307 > V_66 -> V_94 . V_8 . V_99 [ V_65 ] ) {
if ( V_311 != - 1 ) {
struct V_31 * V_317 = F_199 ( V_32 , V_200 ) ;
if ( V_317 )
F_190 ( V_2 , V_4 , V_317 , V_66 , V_311 ) ;
}
V_311 = V_65 ;
}
}
if ( V_311 != - 1 ) {
F_190 ( V_2 , V_4 , V_32 , V_66 , V_311 ) ;
return 0 ;
}
V_316:
F_78 ( V_32 ) ;
return 0 ;
}
int F_200 ( struct V_31 * V_32 )
{
struct V_59 * V_66 ;
struct V_2 * V_2 = F_61 ( V_32 -> V_81 ) ;
struct V_1 * V_4 ;
struct V_5 V_107 = {
. V_108 = V_32 -> V_81 -> V_109 ,
. V_110 = V_32 -> V_111 ,
} ;
int V_12 ;
V_12 = F_3 ( V_2 , & V_107 , & V_4 ) ;
if ( V_12 < 0 ) {
F_78 ( V_32 ) ;
return V_12 ;
}
F_33 ( & V_64 ) ;
V_66 = F_117 ( V_4 ,
& F_65 ( V_32 ) -> V_117 , & F_65 ( V_32 ) -> V_118 ) ;
if ( V_66 == NULL ) {
int V_79 ;
V_79 = F_198 ( V_4 , V_32 -> V_81 ) ;
if ( V_79 >= 0 ) {
int V_12 = F_141 ( V_4 , V_79 , V_32 ) ;
F_35 ( & V_64 ) ;
return V_12 ;
}
F_35 ( & V_64 ) ;
F_78 ( V_32 ) ;
return - V_318 ;
}
F_128 ( V_2 , V_4 , V_32 , V_66 ) ;
F_35 ( & V_64 ) ;
return 0 ;
}
static int F_126 ( struct V_1 * V_4 , struct V_31 * V_32 ,
struct V_59 * V_162 , struct V_319 * V_320 )
{
int V_65 ;
struct V_321 * V_322 ;
struct V_35 * V_323 ;
struct V_324 V_325 ;
if ( V_162 -> V_93 >= V_182 )
return - V_76 ;
if ( F_39 ( V_4 , V_162 -> V_93 ) &&
F_201 ( V_32 , V_326 , V_4 -> V_72 [ V_162 -> V_93 ] . V_81 -> V_109 ) < 0 )
return - V_202 ;
V_323 = F_202 ( V_32 , V_327 ) ;
if ( V_323 == NULL )
return - V_202 ;
for ( V_65 = V_162 -> V_94 . V_8 . V_98 ; V_65 < V_162 -> V_94 . V_8 . V_71 ; V_65 ++ ) {
if ( F_39 ( V_4 , V_65 ) && V_162 -> V_94 . V_8 . V_99 [ V_65 ] < 255 ) {
V_322 = F_203 ( V_32 , sizeof( * V_322 ) ) ;
if ( V_322 == NULL ) {
F_204 ( V_32 , V_323 ) ;
return - V_202 ;
}
V_322 -> V_328 = 0 ;
V_322 -> V_329 = V_162 -> V_94 . V_8 . V_99 [ V_65 ] ;
V_322 -> V_330 = V_4 -> V_72 [ V_65 ] . V_81 -> V_109 ;
V_322 -> V_331 = sizeof( * V_322 ) ;
}
}
F_205 ( V_32 , V_323 ) ;
V_325 . V_332 = V_162 -> V_94 . V_8 . V_95 ;
V_325 . V_333 = V_162 -> V_94 . V_8 . V_96 ;
V_325 . V_334 = V_162 -> V_94 . V_8 . V_97 ;
if ( F_206 ( V_32 , V_335 , sizeof( V_325 ) , & V_325 ) < 0 )
return - V_202 ;
V_320 -> V_336 = V_337 ;
return 1 ;
}
int F_207 ( struct V_2 * V_2 ,
struct V_31 * V_32 , struct V_319 * V_320 , int V_338 )
{
int V_12 ;
struct V_1 * V_4 ;
struct V_59 * V_66 ;
struct V_339 * V_340 = (struct V_339 * ) F_138 ( V_32 ) ;
V_4 = F_1 ( V_2 , V_44 ) ;
if ( V_4 == NULL )
return - V_76 ;
F_33 ( & V_64 ) ;
V_66 = F_117 ( V_4 , & V_340 -> V_341 . V_342 , & V_340 -> V_343 . V_342 ) ;
if ( ! V_66 ) {
struct V_31 * V_317 ;
struct V_103 * V_344 ;
struct V_105 * V_81 ;
int V_79 ;
if ( V_338 ) {
F_35 ( & V_64 ) ;
return - V_30 ;
}
V_81 = V_32 -> V_81 ;
if ( V_81 == NULL || ( V_79 = F_198 ( V_4 , V_81 ) ) < 0 ) {
F_35 ( & V_64 ) ;
return - V_318 ;
}
V_317 = F_131 ( sizeof( struct V_103 ) , V_200 ) ;
if ( ! V_317 ) {
F_35 ( & V_64 ) ;
return - V_45 ;
}
F_133 ( V_317 ) ;
F_134 ( V_317 , sizeof( struct V_103 ) ) ;
F_73 ( V_317 ) ;
V_344 = F_65 ( V_317 ) ;
V_344 -> V_167 = 0 ;
V_344 -> V_345 = 0 ;
V_344 -> V_346 [ 0 ] = 0 ;
V_344 -> V_346 [ 1 ] = 0 ;
V_344 -> V_346 [ 2 ] = 0 ;
V_344 -> V_121 = 0 ;
V_344 -> V_347 = V_348 ;
V_344 -> V_307 = 0 ;
V_344 -> V_117 = V_340 -> V_341 . V_342 ;
V_344 -> V_118 = V_340 -> V_343 . V_342 ;
V_12 = F_141 ( V_4 , V_79 , V_317 ) ;
F_35 ( & V_64 ) ;
return V_12 ;
}
if ( ! V_338 && ( V_320 -> V_349 & V_350 ) )
V_66 -> V_248 |= V_351 ;
V_12 = F_126 ( V_4 , V_32 , V_66 , V_320 ) ;
F_35 ( & V_64 ) ;
return V_12 ;
}
static int F_208 ( struct V_1 * V_4 , struct V_31 * V_32 ,
T_1 V_175 , T_1 V_74 , struct V_59 * V_162 , int V_283 )
{
struct V_168 * V_169 ;
struct V_319 * V_320 ;
int V_12 ;
V_169 = F_209 ( V_32 , V_175 , V_74 , V_283 , sizeof( * V_320 ) , V_352 ) ;
if ( V_169 == NULL )
return - V_202 ;
V_320 = F_210 ( V_169 ) ;
V_320 -> V_353 = V_242 ;
V_320 -> V_354 = 128 ;
V_320 -> V_355 = 128 ;
V_320 -> V_356 = 0 ;
V_320 -> V_357 = V_4 -> V_3 ;
if ( F_201 ( V_32 , V_358 , V_4 -> V_3 ) )
goto V_359;
V_320 -> V_336 = V_337 ;
V_320 -> V_360 = V_361 ;
if ( V_162 -> V_248 & V_249 )
V_320 -> V_362 = V_363 ;
else
V_320 -> V_362 = V_364 ;
V_320 -> V_349 = 0 ;
if ( F_206 ( V_32 , V_365 , 16 , & V_162 -> V_92 ) ||
F_206 ( V_32 , V_366 , 16 , & V_162 -> V_91 ) )
goto V_359;
V_12 = F_126 ( V_4 , V_32 , V_162 , V_320 ) ;
if ( V_12 < 0 && V_12 != - V_76 )
goto V_359;
return F_211 ( V_32 , V_169 ) ;
V_359:
F_212 ( V_32 , V_169 ) ;
return - V_202 ;
}
static int F_213 ( bool V_166 , int V_71 )
{
T_9 V_120 =
F_214 ( sizeof( struct V_319 ) )
+ F_215 ( 4 )
+ F_215 ( sizeof( struct V_197 ) )
+ F_215 ( sizeof( struct V_197 ) )
;
if ( ! V_166 )
V_120 = V_120
+ F_215 ( 4 )
+ F_215 ( 0 )
+ V_71 * F_216 ( sizeof( struct V_321 ) )
+ F_215 ( sizeof( struct V_324 ) )
;
return V_120 ;
}
static void F_110 ( struct V_1 * V_4 , struct V_59 * V_63 ,
int V_283 )
{
struct V_2 * V_2 = F_100 ( & V_4 -> V_2 ) ;
struct V_31 * V_32 ;
int V_12 = - V_189 ;
V_32 = F_217 ( F_213 ( V_63 -> V_93 >= V_182 , V_4 -> V_71 ) ,
V_200 ) ;
if ( V_32 == NULL )
goto V_367;
V_12 = F_208 ( V_4 , V_32 , 0 , 0 , V_63 , V_283 ) ;
if ( V_12 < 0 )
goto V_367;
F_218 ( V_32 , V_2 , 0 , V_368 , NULL , V_200 ) ;
return;
V_367:
F_78 ( V_32 ) ;
if ( V_12 < 0 )
F_219 ( V_2 , V_368 , V_12 ) ;
}
static int V_244 ( struct V_31 * V_32 , struct V_369 * V_370 )
{
struct V_2 * V_2 = F_169 ( V_32 -> V_251 ) ;
struct V_1 * V_4 ;
struct V_59 * V_63 ;
unsigned int V_371 = 0 , V_372 ;
unsigned int V_373 = 0 , V_374 ;
unsigned int V_375 = 0 , V_376 ;
V_372 = V_370 -> args [ 0 ] ;
V_374 = V_370 -> args [ 1 ] ;
V_376 = V_370 -> args [ 2 ] ;
F_33 ( & V_64 ) ;
F_2 (mrt, net) {
if ( V_371 < V_372 )
goto V_377;
if ( V_371 > V_372 )
V_374 = 0 ;
for ( V_373 = V_374 ; V_373 < V_53 ; V_373 ++ ) {
F_34 (mfc, &mrt->mfc6_cache_array[h], list) {
if ( V_375 < V_376 )
goto V_378;
if ( F_208 ( V_4 , V_32 ,
F_107 ( V_370 -> V_32 ) . V_175 ,
V_370 -> V_169 -> V_379 ,
V_63 , V_217 ) < 0 )
goto V_380;
V_378:
V_375 ++ ;
}
V_375 = V_376 = 0 ;
}
F_36 ( & V_67 ) ;
F_34 (mfc, &mrt->mfc6_unres_queue, list) {
if ( V_375 < V_376 )
goto V_381;
if ( F_208 ( V_4 , V_32 ,
F_107 ( V_370 -> V_32 ) . V_175 ,
V_370 -> V_169 -> V_379 ,
V_63 , V_217 ) < 0 ) {
F_37 ( & V_67 ) ;
goto V_380;
}
V_381:
V_375 ++ ;
}
F_37 ( & V_67 ) ;
V_375 = V_376 = 0 ;
V_374 = 0 ;
V_377:
V_371 ++ ;
}
V_380:
F_35 ( & V_64 ) ;
V_370 -> args [ 2 ] = V_375 ;
V_370 -> args [ 1 ] = V_373 ;
V_370 -> args [ 0 ] = V_371 ;
return V_32 -> V_120 ;
}
