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
static struct V_59 * F_120 ( struct V_1 * V_4 ,
T_6 V_200 )
{
int line = F_118 ( & V_201 , & V_201 ) ;
struct V_59 * V_162 ;
F_34 (c, &mrt->mfc6_cache_array[line], list)
if ( F_121 ( & V_162 -> V_92 ) &&
F_121 ( & V_162 -> V_91 ) &&
( V_162 -> V_94 . V_8 . V_99 [ V_200 ] < 255 ) )
return V_162 ;
return NULL ;
}
static struct V_59 * F_122 ( struct V_1 * V_4 ,
struct V_197 * V_199 ,
T_6 V_200 )
{
int line = F_118 ( V_199 , & V_201 ) ;
struct V_59 * V_162 , * V_202 ;
if ( F_121 ( V_199 ) )
goto V_203;
F_34 (c, &mrt->mfc6_cache_array[line], list)
if ( F_121 ( & V_162 -> V_92 ) &&
F_119 ( & V_162 -> V_91 , V_199 ) ) {
if ( V_162 -> V_94 . V_8 . V_99 [ V_200 ] < 255 )
return V_162 ;
V_202 = F_120 ( V_4 ,
V_162 -> V_93 ) ;
if ( V_202 && V_202 -> V_94 . V_8 . V_99 [ V_200 ] < 255 )
return V_162 ;
}
V_203:
return F_120 ( V_4 , V_200 ) ;
}
static struct V_59 * F_123 ( void )
{
struct V_59 * V_162 = F_124 ( V_163 , V_52 ) ;
if ( V_162 == NULL )
return NULL ;
V_162 -> V_94 . V_8 . V_98 = V_182 ;
return V_162 ;
}
static struct V_59 * F_125 ( void )
{
struct V_59 * V_162 = F_124 ( V_163 , V_204 ) ;
if ( V_162 == NULL )
return NULL ;
F_126 ( & V_162 -> V_94 . V_165 . V_166 ) ;
V_162 -> V_94 . V_165 . V_178 = V_177 + 10 * V_179 ;
return V_162 ;
}
static void F_127 ( struct V_2 * V_2 , struct V_1 * V_4 ,
struct V_59 * V_205 , struct V_59 * V_162 )
{
struct V_31 * V_32 ;
while( ( V_32 = F_128 ( & V_205 -> V_94 . V_165 . V_166 ) ) ) {
if ( F_65 ( V_32 ) -> V_167 == 0 ) {
struct V_168 * V_169 = (struct V_168 * ) F_72 ( V_32 , sizeof( struct V_103 ) ) ;
if ( F_129 ( V_4 , V_32 , V_162 , F_105 ( V_169 ) ) > 0 ) {
V_169 -> V_172 = F_130 ( V_32 ) - ( V_124 * ) V_169 ;
} else {
V_169 -> V_170 = V_171 ;
V_169 -> V_172 = F_103 ( sizeof( struct V_173 ) ) ;
F_104 ( V_32 , V_169 -> V_172 ) ;
( (struct V_173 * ) F_105 ( V_169 ) ) -> error = - V_206 ;
}
F_106 ( V_32 , V_2 , F_107 ( V_32 ) . V_175 ) ;
} else
F_131 ( V_2 , V_4 , V_32 , V_162 ) ;
}
}
static int F_80 ( struct V_1 * V_4 , struct V_31 * V_95 ,
T_6 V_200 , int assert )
{
struct V_31 * V_32 ;
struct V_207 * V_208 ;
int V_209 ;
#ifdef F_27
if ( assert == V_137 )
V_32 = F_132 ( V_95 , - F_133 ( V_95 )
+ sizeof( * V_208 ) ) ;
else
#endif
V_32 = F_134 ( sizeof( struct V_103 ) + sizeof( * V_208 ) , V_204 ) ;
if ( ! V_32 )
return - V_189 ;
V_32 -> V_128 = V_210 ;
#ifdef F_27
if ( assert == V_137 ) {
F_135 ( V_32 , - F_133 ( V_95 ) ) ;
F_135 ( V_32 , sizeof( * V_208 ) ) ;
F_136 ( V_32 ) ;
V_208 = (struct V_207 * ) F_63 ( V_32 ) ;
V_208 -> V_211 = 0 ;
V_208 -> V_212 = V_137 ;
V_208 -> V_213 = V_4 -> V_58 ;
V_208 -> V_214 = 0 ;
V_208 -> V_215 = F_65 ( V_95 ) -> V_117 ;
V_208 -> V_216 = F_65 ( V_95 ) -> V_118 ;
V_32 -> V_128 = V_210 ;
} else
#endif
{
F_137 ( V_32 , sizeof( struct V_103 ) ) ;
F_73 ( V_32 ) ;
F_138 ( V_32 , F_65 ( V_95 ) , sizeof( struct V_103 ) ) ;
F_137 ( V_32 , sizeof( * V_208 ) ) ;
F_136 ( V_32 ) ;
V_208 = (struct V_207 * ) F_63 ( V_32 ) ;
V_208 -> V_211 = 0 ;
V_208 -> V_212 = assert ;
V_208 -> V_213 = V_200 ;
V_208 -> V_214 = 0 ;
V_208 -> V_215 = F_65 ( V_95 ) -> V_117 ;
V_208 -> V_216 = F_65 ( V_95 ) -> V_118 ;
F_139 ( V_32 , F_140 ( F_141 ( V_95 ) ) ) ;
V_32 -> V_128 = V_210 ;
}
if ( V_4 -> V_217 == NULL ) {
F_78 ( V_32 ) ;
return - V_27 ;
}
V_209 = F_142 ( V_4 -> V_217 , V_32 ) ;
if ( V_209 < 0 ) {
F_143 ( L_12 ) ;
F_78 ( V_32 ) ;
}
return V_209 ;
}
static int
F_144 ( struct V_1 * V_4 , T_6 V_200 , struct V_31 * V_32 )
{
bool V_218 = false ;
int V_12 ;
struct V_59 * V_162 ;
F_36 ( & V_67 ) ;
F_34 (c, &mrt->mfc6_unres_queue, list) {
if ( F_119 ( & V_162 -> V_91 , & F_65 ( V_32 ) -> V_118 ) &&
F_119 ( & V_162 -> V_92 , & F_65 ( V_32 ) -> V_117 ) ) {
V_218 = true ;
break;
}
}
if ( ! V_218 ) {
if ( F_145 ( & V_4 -> V_164 ) >= 10 ||
( V_162 = F_125 () ) == NULL ) {
F_37 ( & V_67 ) ;
F_78 ( V_32 ) ;
return - V_189 ;
}
V_162 -> V_93 = - 1 ;
V_162 -> V_92 = F_65 ( V_32 ) -> V_117 ;
V_162 -> V_91 = F_65 ( V_32 ) -> V_118 ;
V_12 = F_80 ( V_4 , V_32 , V_200 , V_219 ) ;
if ( V_12 < 0 ) {
F_37 ( & V_67 ) ;
F_97 ( V_162 ) ;
F_78 ( V_32 ) ;
return V_12 ;
}
F_146 ( & V_4 -> V_164 ) ;
F_147 ( & V_162 -> V_49 , & V_4 -> V_55 ) ;
F_110 ( V_4 , V_162 , V_220 ) ;
F_108 ( V_4 ) ;
}
if ( V_162 -> V_94 . V_165 . V_166 . V_221 > 3 ) {
F_78 ( V_32 ) ;
V_12 = - V_189 ;
} else {
F_148 ( & V_162 -> V_94 . V_165 . V_166 , V_32 ) ;
V_12 = 0 ;
}
F_37 ( & V_67 ) ;
return V_12 ;
}
static int F_149 ( struct V_1 * V_4 , struct V_222 * V_63 ,
int V_223 )
{
int line ;
struct V_59 * V_162 , * V_48 ;
line = F_118 ( & V_63 -> V_224 . V_225 , & V_63 -> V_226 . V_225 ) ;
F_21 (c, next, &mrt->mfc6_cache_array[line], list) {
if ( F_119 ( & V_162 -> V_92 , & V_63 -> V_226 . V_225 ) &&
F_119 ( & V_162 -> V_91 ,
& V_63 -> V_224 . V_225 ) &&
( V_223 == - 1 || V_223 == V_162 -> V_93 ) ) {
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
static int F_150 ( struct V_227 * V_228 ,
unsigned long V_229 , void * V_230 )
{
struct V_105 * V_81 = V_230 ;
struct V_2 * V_2 = F_61 ( V_81 ) ;
struct V_1 * V_4 ;
struct V_68 * V_78 ;
int V_65 ;
F_151 ( V_49 ) ;
if ( V_229 != V_231 )
return V_232 ;
F_2 (mrt, net) {
V_78 = & V_4 -> V_72 [ 0 ] ;
for ( V_65 = 0 ; V_65 < V_4 -> V_71 ; V_65 ++ , V_78 ++ ) {
if ( V_78 -> V_81 == V_81 )
F_90 ( V_4 , V_65 , & V_49 ) ;
}
}
F_152 ( & V_49 ) ;
return V_232 ;
}
static int T_2 F_153 ( struct V_2 * V_2 )
{
int V_12 ;
V_12 = F_11 ( V_2 ) ;
if ( V_12 < 0 )
goto V_233;
#ifdef F_154
V_12 = - V_45 ;
if ( ! F_155 ( L_13 , 0 , V_2 -> V_234 , & V_235 ) )
goto V_236;
if ( ! F_155 ( L_14 , 0 , V_2 -> V_234 , & V_237 ) )
goto V_238;
#endif
return 0 ;
#ifdef F_154
V_238:
F_156 ( L_13 , V_2 -> V_234 ) ;
V_236:
F_20 ( V_2 ) ;
#endif
V_233:
return V_12 ;
}
static void T_3 F_157 ( struct V_2 * V_2 )
{
#ifdef F_154
F_156 ( L_14 , V_2 -> V_234 ) ;
F_156 ( L_13 , V_2 -> V_234 ) ;
#endif
F_20 ( V_2 ) ;
}
int T_7 F_158 ( void )
{
int V_12 ;
V_163 = F_159 ( L_15 ,
sizeof( struct V_59 ) ,
0 , V_239 ,
NULL ) ;
if ( ! V_163 )
return - V_45 ;
V_12 = F_160 ( & V_240 ) ;
if ( V_12 )
goto V_241;
V_12 = F_161 ( & V_242 ) ;
if ( V_12 )
goto V_243;
#ifdef F_27
if ( F_162 ( & V_244 , V_119 ) < 0 ) {
F_163 ( L_16 , V_245 ) ;
V_12 = - V_30 ;
goto V_246;
}
#endif
F_164 ( V_247 , V_248 , NULL ,
V_249 , NULL ) ;
return 0 ;
#ifdef F_27
V_246:
F_165 ( & V_242 ) ;
#endif
V_243:
F_166 ( & V_240 ) ;
V_241:
F_167 ( V_163 ) ;
return V_12 ;
}
void F_168 ( void )
{
F_165 ( & V_242 ) ;
F_166 ( & V_240 ) ;
F_167 ( V_163 ) ;
}
static int F_169 ( struct V_2 * V_2 , struct V_1 * V_4 ,
struct V_222 * V_63 , int V_185 , int V_223 )
{
bool V_218 = false ;
int line ;
struct V_59 * V_205 , * V_162 ;
unsigned char V_99 [ V_182 ] ;
int V_51 ;
if ( V_63 -> V_250 >= V_182 )
return - V_251 ;
memset ( V_99 , 255 , V_182 ) ;
for ( V_51 = 0 ; V_51 < V_182 ; V_51 ++ ) {
if ( F_170 ( V_51 , & V_63 -> V_252 ) )
V_99 [ V_51 ] = 1 ;
}
line = F_118 ( & V_63 -> V_224 . V_225 , & V_63 -> V_226 . V_225 ) ;
F_34 (c, &mrt->mfc6_cache_array[line], list) {
if ( F_119 ( & V_162 -> V_92 , & V_63 -> V_226 . V_225 ) &&
F_119 ( & V_162 -> V_91 ,
& V_63 -> V_224 . V_225 ) &&
( V_223 == - 1 || V_223 == V_63 -> V_250 ) ) {
V_218 = true ;
break;
}
}
if ( V_218 ) {
F_91 ( & V_64 ) ;
V_162 -> V_93 = V_63 -> V_250 ;
F_114 ( V_4 , V_162 , V_99 ) ;
if ( ! V_185 )
V_162 -> V_253 |= V_254 ;
F_92 ( & V_64 ) ;
F_110 ( V_4 , V_162 , V_220 ) ;
return 0 ;
}
if ( ! F_121 ( & V_63 -> V_224 . V_225 ) &&
! F_69 ( & V_63 -> V_224 . V_225 ) )
return - V_27 ;
V_162 = F_123 () ;
if ( V_162 == NULL )
return - V_45 ;
V_162 -> V_92 = V_63 -> V_226 . V_225 ;
V_162 -> V_91 = V_63 -> V_224 . V_225 ;
V_162 -> V_93 = V_63 -> V_250 ;
F_114 ( V_4 , V_162 , V_99 ) ;
if ( ! V_185 )
V_162 -> V_253 |= V_254 ;
F_91 ( & V_64 ) ;
F_147 ( & V_162 -> V_49 , & V_4 -> V_54 [ line ] ) ;
F_92 ( & V_64 ) ;
V_218 = false ;
F_36 ( & V_67 ) ;
F_34 (uc, &mrt->mfc6_unres_queue, list) {
if ( F_119 ( & V_205 -> V_92 , & V_162 -> V_92 ) &&
F_119 ( & V_205 -> V_91 , & V_162 -> V_91 ) ) {
F_22 ( & V_205 -> V_49 ) ;
F_101 ( & V_4 -> V_164 ) ;
V_218 = true ;
break;
}
}
if ( F_54 ( & V_4 -> V_55 ) )
F_30 ( & V_4 -> V_56 ) ;
F_37 ( & V_67 ) ;
if ( V_218 ) {
F_127 ( V_2 , V_4 , V_205 , V_162 ) ;
F_97 ( V_205 ) ;
}
F_110 ( V_4 , V_162 , V_220 ) ;
return 0 ;
}
static void F_31 ( struct V_1 * V_4 )
{
int V_51 ;
F_151 ( V_49 ) ;
struct V_59 * V_162 , * V_48 ;
for ( V_51 = 0 ; V_51 < V_4 -> V_71 ; V_51 ++ ) {
if ( ! ( V_4 -> V_72 [ V_51 ] . V_19 & V_193 ) )
F_90 ( V_4 , V_51 , & V_49 ) ;
}
F_152 ( & V_49 ) ;
for ( V_51 = 0 ; V_51 < V_53 ; V_51 ++ ) {
F_21 (c, next, &mrt->mfc6_cache_array[i], list) {
if ( V_162 -> V_253 & V_254 )
continue;
F_91 ( & V_64 ) ;
F_22 ( & V_162 -> V_49 ) ;
F_92 ( & V_64 ) ;
F_110 ( V_4 , V_162 , V_181 ) ;
F_97 ( V_162 ) ;
}
}
if ( F_145 ( & V_4 -> V_164 ) != 0 ) {
F_36 ( & V_67 ) ;
F_21 (c, next, &mrt->mfc6_unres_queue, list) {
F_22 ( & V_162 -> V_49 ) ;
F_110 ( V_4 , V_162 , V_181 ) ;
F_99 ( V_4 , V_162 ) ;
}
F_37 ( & V_67 ) ;
}
}
static int F_171 ( struct V_1 * V_4 , struct V_255 * V_256 )
{
int V_12 = 0 ;
struct V_2 * V_2 = F_172 ( V_256 ) ;
F_88 () ;
F_91 ( & V_64 ) ;
if ( F_173 ( V_4 -> V_217 == NULL ) ) {
V_4 -> V_217 = V_256 ;
V_2 -> V_13 . V_257 -> V_159 ++ ;
F_95 ( V_2 , V_160 ,
V_258 ,
V_2 -> V_13 . V_257 ) ;
}
else
V_12 = - V_187 ;
F_92 ( & V_64 ) ;
F_87 () ;
return V_12 ;
}
int F_174 ( struct V_255 * V_256 )
{
int V_12 = - V_25 ;
struct V_2 * V_2 = F_172 ( V_256 ) ;
struct V_1 * V_4 ;
F_88 () ;
F_2 (mrt, net) {
if ( V_256 == V_4 -> V_217 ) {
F_91 ( & V_64 ) ;
V_4 -> V_217 = NULL ;
V_2 -> V_13 . V_257 -> V_159 -- ;
F_95 ( V_2 ,
V_160 ,
V_258 ,
V_2 -> V_13 . V_257 ) ;
F_92 ( & V_64 ) ;
F_31 ( V_4 ) ;
V_12 = 0 ;
break;
}
}
F_87 () ;
return V_12 ;
}
struct V_255 * F_175 ( struct V_2 * V_2 , struct V_31 * V_32 )
{
struct V_1 * V_4 ;
struct V_5 V_107 = {
. V_108 = V_32 -> V_133 ,
. V_132 = V_32 -> V_81 -> V_109 ,
. V_110 = V_32 -> V_111 ,
} ;
if ( F_3 ( V_2 , & V_107 , & V_4 ) < 0 )
return NULL ;
return V_4 -> V_217 ;
}
int F_176 ( struct V_255 * V_256 , int V_259 , char T_8 * V_260 , unsigned int V_261 )
{
int V_209 , V_223 = 0 ;
struct V_183 V_79 ;
struct V_222 V_63 ;
T_6 V_200 ;
struct V_2 * V_2 = F_172 ( V_256 ) ;
struct V_1 * V_4 ;
V_4 = F_1 ( V_2 , F_177 ( V_256 ) -> V_262 ? : V_44 ) ;
if ( V_4 == NULL )
return - V_76 ;
if ( V_259 != V_263 ) {
if ( V_256 != V_4 -> V_217 && ! F_178 ( V_2 -> V_264 , V_265 ) )
return - V_25 ;
}
switch ( V_259 ) {
case V_263 :
if ( V_256 -> V_266 != V_267 ||
F_179 ( V_256 ) -> V_268 != V_269 )
return - V_270 ;
if ( V_261 < sizeof( int ) )
return - V_27 ;
return F_171 ( V_4 , V_256 ) ;
case V_271 :
return F_174 ( V_256 ) ;
case V_272 :
if ( V_261 < sizeof( V_79 ) )
return - V_27 ;
if ( F_180 ( & V_79 , V_260 , sizeof( V_79 ) ) )
return - V_273 ;
if ( V_79 . V_186 >= V_182 )
return - V_251 ;
F_88 () ;
V_209 = F_115 ( V_2 , V_4 , & V_79 , V_256 == V_4 -> V_217 ) ;
F_87 () ;
return V_209 ;
case V_274 :
if ( V_261 < sizeof( T_6 ) )
return - V_27 ;
if ( F_180 ( & V_200 , V_260 , sizeof( T_6 ) ) )
return - V_273 ;
F_88 () ;
V_209 = F_90 ( V_4 , V_200 , NULL ) ;
F_87 () ;
return V_209 ;
case V_275 :
case V_276 :
V_223 = - 1 ;
case V_277 :
case V_278 :
if ( V_261 < sizeof( V_63 ) )
return - V_27 ;
if ( F_180 ( & V_63 , V_260 , sizeof( V_63 ) ) )
return - V_273 ;
if ( V_223 == 0 )
V_223 = V_63 . V_250 ;
F_88 () ;
if ( V_259 == V_276 || V_259 == V_278 )
V_209 = F_149 ( V_4 , & V_63 , V_223 ) ;
else
V_209 = F_169 ( V_2 , V_4 , & V_63 ,
V_256 == V_4 -> V_217 , V_223 ) ;
F_87 () ;
return V_209 ;
case V_279 :
{
int V_78 ;
if ( V_261 != sizeof( V_78 ) )
return - V_27 ;
if ( F_181 ( V_78 , ( int T_8 * ) V_260 ) )
return - V_273 ;
V_4 -> V_280 = V_78 ;
return 0 ;
}
#ifdef F_27
case V_281 :
{
int V_78 ;
if ( V_261 != sizeof( V_78 ) )
return - V_27 ;
if ( F_181 ( V_78 , ( int T_8 * ) V_260 ) )
return - V_273 ;
V_78 = ! ! V_78 ;
F_88 () ;
V_209 = 0 ;
if ( V_78 != V_4 -> V_282 ) {
V_4 -> V_282 = V_78 ;
V_4 -> V_280 = V_78 ;
}
F_87 () ;
return V_209 ;
}
#endif
#ifdef F_28
case V_283 :
{
T_1 V_78 ;
if ( V_261 != sizeof( T_1 ) )
return - V_27 ;
if ( F_181 ( V_78 , ( T_1 T_8 * ) V_260 ) )
return - V_273 ;
if ( V_78 != V_284 && V_78 >= 100000000 )
return - V_27 ;
if ( V_256 == V_4 -> V_217 )
return - V_285 ;
F_88 () ;
V_209 = 0 ;
if ( ! F_16 ( V_2 , V_78 ) )
V_209 = - V_45 ;
F_177 ( V_256 ) -> V_262 = V_78 ;
F_87 () ;
return V_209 ;
}
#endif
default:
return - V_286 ;
}
}
int F_182 ( struct V_255 * V_256 , int V_259 , char T_8 * V_260 ,
int T_8 * V_261 )
{
int V_287 ;
int V_288 ;
struct V_2 * V_2 = F_172 ( V_256 ) ;
struct V_1 * V_4 ;
V_4 = F_1 ( V_2 , F_177 ( V_256 ) -> V_262 ? : V_44 ) ;
if ( V_4 == NULL )
return - V_76 ;
switch ( V_259 ) {
case V_289 :
V_288 = 0x0305 ;
break;
#ifdef F_27
case V_281 :
V_288 = V_4 -> V_282 ;
break;
#endif
case V_279 :
V_288 = V_4 -> V_280 ;
break;
default:
return - V_286 ;
}
if ( F_181 ( V_287 , V_261 ) )
return - V_273 ;
V_287 = F_183 ( int , V_287 , sizeof( int ) ) ;
if ( V_287 < 0 )
return - V_27 ;
if ( F_184 ( V_287 , V_261 ) )
return - V_273 ;
if ( F_185 ( V_260 , & V_288 , V_287 ) )
return - V_273 ;
return 0 ;
}
int F_186 ( struct V_255 * V_256 , int V_290 , void T_8 * V_10 )
{
struct V_291 V_292 ;
struct V_293 V_294 ;
struct V_68 * V_79 ;
struct V_59 * V_162 ;
struct V_2 * V_2 = F_172 ( V_256 ) ;
struct V_1 * V_4 ;
V_4 = F_1 ( V_2 , F_177 ( V_256 ) -> V_262 ? : V_44 ) ;
if ( V_4 == NULL )
return - V_76 ;
switch ( V_290 ) {
case V_295 :
if ( F_180 ( & V_294 , V_10 , sizeof( V_294 ) ) )
return - V_273 ;
if ( V_294 . V_200 >= V_4 -> V_71 )
return - V_27 ;
F_33 ( & V_64 ) ;
V_79 = & V_4 -> V_72 [ V_294 . V_200 ] ;
if ( F_39 ( V_4 , V_294 . V_200 ) ) {
V_294 . V_296 = V_79 -> V_83 ;
V_294 . V_297 = V_79 -> V_85 ;
V_294 . V_298 = V_79 -> V_82 ;
V_294 . V_299 = V_79 -> V_84 ;
F_35 ( & V_64 ) ;
if ( F_185 ( V_10 , & V_294 , sizeof( V_294 ) ) )
return - V_273 ;
return 0 ;
}
F_35 ( & V_64 ) ;
return - V_156 ;
case V_300 :
if ( F_180 ( & V_292 , V_10 , sizeof( V_292 ) ) )
return - V_273 ;
F_33 ( & V_64 ) ;
V_162 = F_117 ( V_4 , & V_292 . V_301 . V_225 , & V_292 . V_302 . V_225 ) ;
if ( V_162 ) {
V_292 . V_303 = V_162 -> V_94 . V_8 . V_95 ;
V_292 . V_304 = V_162 -> V_94 . V_8 . V_96 ;
V_292 . V_97 = V_162 -> V_94 . V_8 . V_97 ;
F_35 ( & V_64 ) ;
if ( F_185 ( V_10 , & V_292 , sizeof( V_292 ) ) )
return - V_273 ;
return 0 ;
}
F_35 ( & V_64 ) ;
return - V_156 ;
default:
return - V_305 ;
}
}
int F_187 ( struct V_255 * V_256 , unsigned int V_290 , void T_8 * V_10 )
{
struct V_306 V_292 ;
struct V_307 V_294 ;
struct V_68 * V_79 ;
struct V_59 * V_162 ;
struct V_2 * V_2 = F_172 ( V_256 ) ;
struct V_1 * V_4 ;
V_4 = F_1 ( V_2 , F_177 ( V_256 ) -> V_262 ? : V_44 ) ;
if ( V_4 == NULL )
return - V_76 ;
switch ( V_290 ) {
case V_295 :
if ( F_180 ( & V_294 , V_10 , sizeof( V_294 ) ) )
return - V_273 ;
if ( V_294 . V_200 >= V_4 -> V_71 )
return - V_27 ;
F_33 ( & V_64 ) ;
V_79 = & V_4 -> V_72 [ V_294 . V_200 ] ;
if ( F_39 ( V_4 , V_294 . V_200 ) ) {
V_294 . V_296 = V_79 -> V_83 ;
V_294 . V_297 = V_79 -> V_85 ;
V_294 . V_298 = V_79 -> V_82 ;
V_294 . V_299 = V_79 -> V_84 ;
F_35 ( & V_64 ) ;
if ( F_185 ( V_10 , & V_294 , sizeof( V_294 ) ) )
return - V_273 ;
return 0 ;
}
F_35 ( & V_64 ) ;
return - V_156 ;
case V_300 :
if ( F_180 ( & V_292 , V_10 , sizeof( V_292 ) ) )
return - V_273 ;
F_33 ( & V_64 ) ;
V_162 = F_117 ( V_4 , & V_292 . V_301 . V_225 , & V_292 . V_302 . V_225 ) ;
if ( V_162 ) {
V_292 . V_303 = V_162 -> V_94 . V_8 . V_95 ;
V_292 . V_304 = V_162 -> V_94 . V_8 . V_96 ;
V_292 . V_97 = V_162 -> V_94 . V_8 . V_97 ;
F_35 ( & V_64 ) ;
if ( F_185 ( V_10 , & V_292 , sizeof( V_292 ) ) )
return - V_273 ;
return 0 ;
}
F_35 ( & V_64 ) ;
return - V_156 ;
default:
return - V_305 ;
}
}
static inline int F_188 ( struct V_31 * V_32 )
{
F_189 ( F_61 ( F_141 ( V_32 ) -> V_81 ) , F_190 ( F_141 ( V_32 ) ) ,
V_308 ) ;
F_191 ( F_61 ( F_141 ( V_32 ) -> V_81 ) , F_190 ( F_141 ( V_32 ) ) ,
V_309 , V_32 -> V_120 ) ;
return F_192 ( V_32 ) ;
}
static int F_193 ( struct V_2 * V_2 , struct V_1 * V_4 ,
struct V_31 * V_32 , struct V_59 * V_162 , int V_151 )
{
struct V_103 * V_310 ;
struct V_68 * V_79 = & V_4 -> V_72 [ V_151 ] ;
struct V_105 * V_81 ;
struct V_311 * V_312 ;
struct V_5 V_107 ;
if ( V_79 -> V_81 == NULL )
goto V_313;
#ifdef F_27
if ( V_79 -> V_19 & V_161 ) {
V_79 -> V_85 ++ ;
V_79 -> V_84 += V_32 -> V_120 ;
V_79 -> V_81 -> V_134 . V_135 += V_32 -> V_120 ;
V_79 -> V_81 -> V_134 . V_136 ++ ;
F_80 ( V_4 , V_32 , V_151 , V_137 ) ;
goto V_313;
}
#endif
V_310 = F_65 ( V_32 ) ;
V_107 = (struct V_5 ) {
. V_132 = V_79 -> V_196 ,
. V_118 = V_310 -> V_118 ,
} ;
V_312 = F_194 ( V_2 , NULL , & V_107 ) ;
if ( V_312 -> error ) {
F_195 ( V_312 ) ;
goto V_313;
}
F_196 ( V_32 ) ;
F_139 ( V_32 , V_312 ) ;
V_81 = V_79 -> V_81 ;
V_32 -> V_81 = V_81 ;
V_79 -> V_85 ++ ;
V_79 -> V_84 += V_32 -> V_120 ;
if ( F_197 ( V_32 , sizeof( * V_310 ) + F_198 ( V_81 ) ) )
goto V_313;
V_310 = F_65 ( V_32 ) ;
V_310 -> V_314 -- ;
F_199 ( V_32 ) -> V_19 |= V_315 ;
return F_200 ( V_316 , V_317 , V_32 , V_32 -> V_81 , V_81 ,
F_188 ) ;
V_313:
F_78 ( V_32 ) ;
return 0 ;
}
static int F_201 ( struct V_1 * V_4 , struct V_105 * V_81 )
{
int V_65 ;
for ( V_65 = V_4 -> V_71 - 1 ; V_65 >= 0 ; V_65 -- ) {
if ( V_4 -> V_72 [ V_65 ] . V_81 == V_81 )
break;
}
return V_65 ;
}
static int F_131 ( struct V_2 * V_2 , struct V_1 * V_4 ,
struct V_31 * V_32 , struct V_59 * V_66 )
{
int V_318 = - 1 ;
int V_79 , V_65 ;
int V_319 = F_201 ( V_4 , V_32 -> V_81 ) ;
V_79 = V_66 -> V_93 ;
V_66 -> V_94 . V_8 . V_95 ++ ;
V_66 -> V_94 . V_8 . V_96 += V_32 -> V_120 ;
if ( F_121 ( & V_66 -> V_92 ) && V_319 >= 0 ) {
struct V_59 * V_320 ;
V_320 = F_120 ( V_4 , V_79 ) ;
if ( V_320 &&
V_320 -> V_94 . V_8 . V_99 [ V_319 ] < 255 )
goto V_321;
}
if ( V_4 -> V_72 [ V_79 ] . V_81 != V_32 -> V_81 ) {
V_66 -> V_94 . V_8 . V_97 ++ ;
if ( V_319 >= 0 && V_4 -> V_280 &&
( V_4 -> V_282 ||
V_66 -> V_94 . V_8 . V_99 [ V_319 ] < 255 ) &&
F_109 ( V_177 ,
V_66 -> V_94 . V_8 . V_322 + V_323 ) ) {
V_66 -> V_94 . V_8 . V_322 = V_177 ;
F_80 ( V_4 , V_32 , V_319 , V_324 ) ;
}
goto V_325;
}
V_321:
V_4 -> V_72 [ V_79 ] . V_83 ++ ;
V_4 -> V_72 [ V_79 ] . V_82 += V_32 -> V_120 ;
if ( F_121 ( & V_66 -> V_92 ) &&
F_121 ( & V_66 -> V_91 ) ) {
if ( V_319 >= 0 &&
V_319 != V_66 -> V_93 &&
F_65 ( V_32 ) -> V_314 >
V_66 -> V_94 . V_8 . V_99 [ V_66 -> V_93 ] ) {
V_318 = V_66 -> V_93 ;
goto V_326;
}
goto V_325;
}
for ( V_65 = V_66 -> V_94 . V_8 . V_71 - 1 ; V_65 >= V_66 -> V_94 . V_8 . V_98 ; V_65 -- ) {
if ( ( ! F_121 ( & V_66 -> V_92 ) || V_65 != V_319 ) &&
F_65 ( V_32 ) -> V_314 > V_66 -> V_94 . V_8 . V_99 [ V_65 ] ) {
if ( V_318 != - 1 ) {
struct V_31 * V_327 = F_202 ( V_32 , V_204 ) ;
if ( V_327 )
F_193 ( V_2 , V_4 , V_327 , V_66 , V_318 ) ;
}
V_318 = V_65 ;
}
}
V_326:
if ( V_318 != - 1 ) {
F_193 ( V_2 , V_4 , V_32 , V_66 , V_318 ) ;
return 0 ;
}
V_325:
F_78 ( V_32 ) ;
return 0 ;
}
int F_203 ( struct V_31 * V_32 )
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
int V_79 = F_201 ( V_4 , V_32 -> V_81 ) ;
if ( V_79 >= 0 )
V_66 = F_122 ( V_4 ,
& F_65 ( V_32 ) -> V_118 ,
V_79 ) ;
}
if ( V_66 == NULL ) {
int V_79 ;
V_79 = F_201 ( V_4 , V_32 -> V_81 ) ;
if ( V_79 >= 0 ) {
int V_12 = F_144 ( V_4 , V_79 , V_32 ) ;
F_35 ( & V_64 ) ;
return V_12 ;
}
F_35 ( & V_64 ) ;
F_78 ( V_32 ) ;
return - V_328 ;
}
F_131 ( V_2 , V_4 , V_32 , V_66 ) ;
F_35 ( & V_64 ) ;
return 0 ;
}
static int F_129 ( struct V_1 * V_4 , struct V_31 * V_32 ,
struct V_59 * V_162 , struct V_329 * V_330 )
{
int V_65 ;
struct V_331 * V_332 ;
struct V_35 * V_333 ;
struct V_334 V_335 ;
if ( V_162 -> V_93 >= V_182 )
return - V_76 ;
if ( F_39 ( V_4 , V_162 -> V_93 ) &&
F_204 ( V_32 , V_336 , V_4 -> V_72 [ V_162 -> V_93 ] . V_81 -> V_109 ) < 0 )
return - V_206 ;
V_333 = F_205 ( V_32 , V_337 ) ;
if ( V_333 == NULL )
return - V_206 ;
for ( V_65 = V_162 -> V_94 . V_8 . V_98 ; V_65 < V_162 -> V_94 . V_8 . V_71 ; V_65 ++ ) {
if ( F_39 ( V_4 , V_65 ) && V_162 -> V_94 . V_8 . V_99 [ V_65 ] < 255 ) {
V_332 = F_206 ( V_32 , sizeof( * V_332 ) ) ;
if ( V_332 == NULL ) {
F_207 ( V_32 , V_333 ) ;
return - V_206 ;
}
V_332 -> V_338 = 0 ;
V_332 -> V_339 = V_162 -> V_94 . V_8 . V_99 [ V_65 ] ;
V_332 -> V_340 = V_4 -> V_72 [ V_65 ] . V_81 -> V_109 ;
V_332 -> V_341 = sizeof( * V_332 ) ;
}
}
F_208 ( V_32 , V_333 ) ;
V_335 . V_342 = V_162 -> V_94 . V_8 . V_95 ;
V_335 . V_343 = V_162 -> V_94 . V_8 . V_96 ;
V_335 . V_344 = V_162 -> V_94 . V_8 . V_97 ;
if ( F_209 ( V_32 , V_345 , sizeof( V_335 ) , & V_335 ) < 0 )
return - V_206 ;
V_330 -> V_346 = V_347 ;
return 1 ;
}
int F_210 ( struct V_2 * V_2 ,
struct V_31 * V_32 , struct V_329 * V_330 , int V_348 )
{
int V_12 ;
struct V_1 * V_4 ;
struct V_59 * V_66 ;
struct V_349 * V_350 = (struct V_349 * ) F_141 ( V_32 ) ;
V_4 = F_1 ( V_2 , V_44 ) ;
if ( V_4 == NULL )
return - V_76 ;
F_33 ( & V_64 ) ;
V_66 = F_117 ( V_4 , & V_350 -> V_351 . V_352 , & V_350 -> V_353 . V_352 ) ;
if ( ! V_66 && V_32 -> V_81 ) {
int V_79 = F_201 ( V_4 , V_32 -> V_81 ) ;
if ( V_79 >= 0 )
V_66 = F_122 ( V_4 , & V_350 -> V_353 . V_352 ,
V_79 ) ;
}
if ( ! V_66 ) {
struct V_31 * V_327 ;
struct V_103 * V_354 ;
struct V_105 * V_81 ;
int V_79 ;
if ( V_348 ) {
F_35 ( & V_64 ) ;
return - V_30 ;
}
V_81 = V_32 -> V_81 ;
if ( V_81 == NULL || ( V_79 = F_201 ( V_4 , V_81 ) ) < 0 ) {
F_35 ( & V_64 ) ;
return - V_328 ;
}
V_327 = F_134 ( sizeof( struct V_103 ) , V_204 ) ;
if ( ! V_327 ) {
F_35 ( & V_64 ) ;
return - V_45 ;
}
F_136 ( V_327 ) ;
F_137 ( V_327 , sizeof( struct V_103 ) ) ;
F_73 ( V_327 ) ;
V_354 = F_65 ( V_327 ) ;
V_354 -> V_167 = 0 ;
V_354 -> V_355 = 0 ;
V_354 -> V_356 [ 0 ] = 0 ;
V_354 -> V_356 [ 1 ] = 0 ;
V_354 -> V_356 [ 2 ] = 0 ;
V_354 -> V_121 = 0 ;
V_354 -> V_357 = V_358 ;
V_354 -> V_314 = 0 ;
V_354 -> V_117 = V_350 -> V_351 . V_352 ;
V_354 -> V_118 = V_350 -> V_353 . V_352 ;
V_12 = F_144 ( V_4 , V_79 , V_327 ) ;
F_35 ( & V_64 ) ;
return V_12 ;
}
if ( ! V_348 && ( V_330 -> V_359 & V_360 ) )
V_66 -> V_253 |= V_361 ;
V_12 = F_129 ( V_4 , V_32 , V_66 , V_330 ) ;
F_35 ( & V_64 ) ;
return V_12 ;
}
static int F_211 ( struct V_1 * V_4 , struct V_31 * V_32 ,
T_1 V_175 , T_1 V_74 , struct V_59 * V_162 , int V_290 )
{
struct V_168 * V_169 ;
struct V_329 * V_330 ;
int V_12 ;
V_169 = F_212 ( V_32 , V_175 , V_74 , V_290 , sizeof( * V_330 ) , V_362 ) ;
if ( V_169 == NULL )
return - V_206 ;
V_330 = F_213 ( V_169 ) ;
V_330 -> V_363 = V_247 ;
V_330 -> V_364 = 128 ;
V_330 -> V_365 = 128 ;
V_330 -> V_366 = 0 ;
V_330 -> V_367 = V_4 -> V_3 ;
if ( F_204 ( V_32 , V_368 , V_4 -> V_3 ) )
goto V_369;
V_330 -> V_346 = V_347 ;
V_330 -> V_370 = V_371 ;
if ( V_162 -> V_253 & V_254 )
V_330 -> V_372 = V_373 ;
else
V_330 -> V_372 = V_374 ;
V_330 -> V_359 = 0 ;
if ( F_209 ( V_32 , V_375 , 16 , & V_162 -> V_92 ) ||
F_209 ( V_32 , V_376 , 16 , & V_162 -> V_91 ) )
goto V_369;
V_12 = F_129 ( V_4 , V_32 , V_162 , V_330 ) ;
if ( V_12 < 0 && V_12 != - V_76 )
goto V_369;
return F_214 ( V_32 , V_169 ) ;
V_369:
F_215 ( V_32 , V_169 ) ;
return - V_206 ;
}
static int F_216 ( bool V_166 , int V_71 )
{
T_9 V_120 =
F_217 ( sizeof( struct V_329 ) )
+ F_218 ( 4 )
+ F_218 ( sizeof( struct V_197 ) )
+ F_218 ( sizeof( struct V_197 ) )
;
if ( ! V_166 )
V_120 = V_120
+ F_218 ( 4 )
+ F_218 ( 0 )
+ V_71 * F_219 ( sizeof( struct V_331 ) )
+ F_218 ( sizeof( struct V_334 ) )
;
return V_120 ;
}
static void F_110 ( struct V_1 * V_4 , struct V_59 * V_63 ,
int V_290 )
{
struct V_2 * V_2 = F_100 ( & V_4 -> V_2 ) ;
struct V_31 * V_32 ;
int V_12 = - V_189 ;
V_32 = F_220 ( F_216 ( V_63 -> V_93 >= V_182 , V_4 -> V_71 ) ,
V_204 ) ;
if ( V_32 == NULL )
goto V_377;
V_12 = F_211 ( V_4 , V_32 , 0 , 0 , V_63 , V_290 ) ;
if ( V_12 < 0 )
goto V_377;
F_221 ( V_32 , V_2 , 0 , V_378 , NULL , V_204 ) ;
return;
V_377:
F_78 ( V_32 ) ;
if ( V_12 < 0 )
F_222 ( V_2 , V_378 , V_12 ) ;
}
static int V_249 ( struct V_31 * V_32 , struct V_379 * V_380 )
{
struct V_2 * V_2 = F_172 ( V_32 -> V_256 ) ;
struct V_1 * V_4 ;
struct V_59 * V_63 ;
unsigned int V_381 = 0 , V_382 ;
unsigned int V_383 = 0 , V_384 ;
unsigned int V_385 = 0 , V_386 ;
V_382 = V_380 -> args [ 0 ] ;
V_384 = V_380 -> args [ 1 ] ;
V_386 = V_380 -> args [ 2 ] ;
F_33 ( & V_64 ) ;
F_2 (mrt, net) {
if ( V_381 < V_382 )
goto V_387;
if ( V_381 > V_382 )
V_384 = 0 ;
for ( V_383 = V_384 ; V_383 < V_53 ; V_383 ++ ) {
F_34 (mfc, &mrt->mfc6_cache_array[h], list) {
if ( V_385 < V_386 )
goto V_388;
if ( F_211 ( V_4 , V_32 ,
F_107 ( V_380 -> V_32 ) . V_175 ,
V_380 -> V_169 -> V_389 ,
V_63 , V_220 ) < 0 )
goto V_390;
V_388:
V_385 ++ ;
}
V_385 = V_386 = 0 ;
}
F_36 ( & V_67 ) ;
F_34 (mfc, &mrt->mfc6_unres_queue, list) {
if ( V_385 < V_386 )
goto V_391;
if ( F_211 ( V_4 , V_32 ,
F_107 ( V_380 -> V_32 ) . V_175 ,
V_380 -> V_169 -> V_389 ,
V_63 , V_220 ) < 0 ) {
F_37 ( & V_67 ) ;
goto V_390;
}
V_391:
V_385 ++ ;
}
F_37 ( & V_67 ) ;
V_385 = V_386 = 0 ;
V_384 = 0 ;
V_387:
V_381 ++ ;
}
V_390:
F_35 ( & V_64 ) ;
V_380 -> args [ 2 ] = V_385 ;
V_380 -> args [ 1 ] = V_383 ;
V_380 -> args [ 0 ] = V_381 ;
return V_32 -> V_120 ;
}
