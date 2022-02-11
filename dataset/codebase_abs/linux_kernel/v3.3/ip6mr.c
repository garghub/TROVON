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
if ( V_155 )
V_155 -> V_158 . V_159 -- ;
if ( V_78 -> V_19 & V_160 )
F_95 ( V_81 , V_153 ) ;
F_77 ( V_81 ) ;
return 0 ;
}
static inline void F_96 ( struct V_59 * V_161 )
{
F_97 ( V_162 , V_161 ) ;
}
static void F_98 ( struct V_1 * V_4 , struct V_59 * V_161 )
{
struct V_2 * V_2 = F_99 ( & V_4 -> V_2 ) ;
struct V_31 * V_32 ;
F_100 ( & V_4 -> V_163 ) ;
while( ( V_32 = F_101 ( & V_161 -> V_94 . V_164 . V_165 ) ) != NULL ) {
if ( F_65 ( V_32 ) -> V_166 == 0 ) {
struct V_167 * V_168 = (struct V_167 * ) F_72 ( V_32 , sizeof( struct V_103 ) ) ;
V_168 -> V_169 = V_170 ;
V_168 -> V_171 = F_102 ( sizeof( struct V_172 ) ) ;
F_103 ( V_32 , V_168 -> V_171 ) ;
( (struct V_172 * ) F_104 ( V_168 ) ) -> error = - V_173 ;
F_105 ( V_32 , V_2 , F_106 ( V_32 ) . V_174 ) ;
} else
F_78 ( V_32 ) ;
}
F_96 ( V_161 ) ;
}
static void F_107 ( struct V_1 * V_4 )
{
unsigned long V_175 = V_176 ;
unsigned long V_177 = 10 * V_178 ;
struct V_59 * V_161 , * V_48 ;
F_21 (c, next, &mrt->mfc6_unres_queue, list) {
if ( F_108 ( V_161 -> V_94 . V_164 . V_177 , V_175 ) ) {
unsigned long V_179 = V_161 -> V_94 . V_164 . V_177 - V_175 ;
if ( V_179 < V_177 )
V_177 = V_179 ;
continue;
}
F_22 ( & V_161 -> V_49 ) ;
F_98 ( V_4 , V_161 ) ;
}
if ( ! F_54 ( & V_4 -> V_55 ) )
F_109 ( & V_4 -> V_56 , V_176 + V_177 ) ;
}
static void V_57 ( unsigned long V_10 )
{
struct V_1 * V_4 = (struct V_1 * ) V_10 ;
if ( ! F_110 ( & V_67 ) ) {
F_109 ( & V_4 -> V_56 , V_176 + 1 ) ;
return;
}
if ( ! F_54 ( & V_4 -> V_55 ) )
F_107 ( V_4 ) ;
F_111 ( & V_67 ) ;
}
static void F_112 ( struct V_1 * V_4 , struct V_59 * V_66 ,
unsigned char * V_99 )
{
int V_151 ;
V_66 -> V_94 . V_8 . V_98 = V_180 ;
V_66 -> V_94 . V_8 . V_71 = 0 ;
memset ( V_66 -> V_94 . V_8 . V_99 , 255 , V_180 ) ;
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
static int F_113 ( struct V_2 * V_2 , struct V_1 * V_4 ,
struct V_181 * V_182 , int V_183 )
{
int V_151 = V_182 -> V_184 ;
struct V_68 * V_78 = & V_4 -> V_72 [ V_151 ] ;
struct V_105 * V_81 ;
struct V_154 * V_155 ;
int V_12 ;
if ( F_39 ( V_4 , V_151 ) )
return - V_185 ;
switch ( V_182 -> V_186 ) {
#ifdef F_27
case V_160 :
if ( V_4 -> V_58 >= 0 )
return - V_185 ;
V_81 = F_82 ( V_2 , V_4 ) ;
if ( ! V_81 )
return - V_187 ;
V_12 = F_93 ( V_81 , 1 ) ;
if ( V_12 ) {
F_89 ( V_81 ) ;
F_77 ( V_81 ) ;
return V_12 ;
}
break;
#endif
case 0 :
V_81 = F_114 ( V_2 , V_182 -> V_188 ) ;
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
if ( V_155 )
V_155 -> V_158 . V_159 ++ ;
V_78 -> V_189 = V_182 -> V_190 ;
V_78 -> V_19 = V_182 -> V_186 ;
if ( ! V_183 )
V_78 -> V_19 |= V_191 ;
V_78 -> V_192 = V_182 -> V_193 ;
V_78 -> V_82 = 0 ;
V_78 -> V_84 = 0 ;
V_78 -> V_83 = 0 ;
V_78 -> V_85 = 0 ;
V_78 -> V_194 = V_81 -> V_109 ;
if ( V_78 -> V_19 & V_160 )
V_78 -> V_194 = V_81 -> V_149 ;
F_91 ( & V_64 ) ;
V_78 -> V_81 = V_81 ;
#ifdef F_27
if ( V_78 -> V_19 & V_160 )
V_4 -> V_58 = V_151 ;
#endif
if ( V_151 + 1 > V_4 -> V_71 )
V_4 -> V_71 = V_151 + 1 ;
F_92 ( & V_64 ) ;
return 0 ;
}
static struct V_59 * F_115 ( struct V_1 * V_4 ,
const struct V_195 * V_196 ,
const struct V_195 * V_197 )
{
int line = F_116 ( V_197 , V_196 ) ;
struct V_59 * V_161 ;
F_34 (c, &mrt->mfc6_cache_array[line], list) {
if ( F_117 ( & V_161 -> V_92 , V_196 ) &&
F_117 ( & V_161 -> V_91 , V_197 ) )
return V_161 ;
}
return NULL ;
}
static struct V_59 * F_118 ( void )
{
struct V_59 * V_161 = F_119 ( V_162 , V_52 ) ;
if ( V_161 == NULL )
return NULL ;
V_161 -> V_94 . V_8 . V_98 = V_180 ;
return V_161 ;
}
static struct V_59 * F_120 ( void )
{
struct V_59 * V_161 = F_119 ( V_162 , V_198 ) ;
if ( V_161 == NULL )
return NULL ;
F_121 ( & V_161 -> V_94 . V_164 . V_165 ) ;
V_161 -> V_94 . V_164 . V_177 = V_176 + 10 * V_178 ;
return V_161 ;
}
static void F_122 ( struct V_2 * V_2 , struct V_1 * V_4 ,
struct V_59 * V_199 , struct V_59 * V_161 )
{
struct V_31 * V_32 ;
while( ( V_32 = F_123 ( & V_199 -> V_94 . V_164 . V_165 ) ) ) {
if ( F_65 ( V_32 ) -> V_166 == 0 ) {
struct V_167 * V_168 = (struct V_167 * ) F_72 ( V_32 , sizeof( struct V_103 ) ) ;
if ( F_124 ( V_4 , V_32 , V_161 , F_104 ( V_168 ) ) > 0 ) {
V_168 -> V_171 = F_125 ( V_32 ) - ( V_124 * ) V_168 ;
} else {
V_168 -> V_169 = V_170 ;
V_168 -> V_171 = F_102 ( sizeof( struct V_172 ) ) ;
F_103 ( V_32 , V_168 -> V_171 ) ;
( (struct V_172 * ) F_104 ( V_168 ) ) -> error = - V_200 ;
}
F_105 ( V_32 , V_2 , F_106 ( V_32 ) . V_174 ) ;
} else
F_126 ( V_2 , V_4 , V_32 , V_161 ) ;
}
}
static int F_80 ( struct V_1 * V_4 , struct V_31 * V_95 ,
T_6 V_201 , int assert )
{
struct V_31 * V_32 ;
struct V_202 * V_203 ;
int V_204 ;
#ifdef F_27
if ( assert == V_137 )
V_32 = F_127 ( V_95 , - F_128 ( V_95 )
+ sizeof( * V_203 ) ) ;
else
#endif
V_32 = F_129 ( sizeof( struct V_103 ) + sizeof( * V_203 ) , V_198 ) ;
if ( ! V_32 )
return - V_187 ;
V_32 -> V_128 = V_205 ;
#ifdef F_27
if ( assert == V_137 ) {
F_130 ( V_32 , - F_128 ( V_95 ) ) ;
F_130 ( V_32 , sizeof( * V_203 ) ) ;
F_131 ( V_32 ) ;
V_203 = (struct V_202 * ) F_63 ( V_32 ) ;
V_203 -> V_206 = 0 ;
V_203 -> V_207 = V_137 ;
V_203 -> V_208 = V_4 -> V_58 ;
V_203 -> V_209 = 0 ;
V_203 -> V_210 = F_65 ( V_95 ) -> V_117 ;
V_203 -> V_211 = F_65 ( V_95 ) -> V_118 ;
V_32 -> V_128 = V_205 ;
} else
#endif
{
F_132 ( V_32 , sizeof( struct V_103 ) ) ;
F_73 ( V_32 ) ;
F_133 ( V_32 , F_65 ( V_95 ) , sizeof( struct V_103 ) ) ;
F_132 ( V_32 , sizeof( * V_203 ) ) ;
F_131 ( V_32 ) ;
V_203 = (struct V_202 * ) F_63 ( V_32 ) ;
V_203 -> V_206 = 0 ;
V_203 -> V_207 = assert ;
V_203 -> V_208 = V_201 ;
V_203 -> V_209 = 0 ;
V_203 -> V_210 = F_65 ( V_95 ) -> V_117 ;
V_203 -> V_211 = F_65 ( V_95 ) -> V_118 ;
F_134 ( V_32 , F_135 ( F_136 ( V_95 ) ) ) ;
V_32 -> V_128 = V_205 ;
}
if ( V_4 -> V_212 == NULL ) {
F_78 ( V_32 ) ;
return - V_27 ;
}
V_204 = F_137 ( V_4 -> V_212 , V_32 ) ;
if ( V_204 < 0 ) {
if ( F_138 () )
F_139 ( V_213 L_12 ) ;
F_78 ( V_32 ) ;
}
return V_204 ;
}
static int
F_140 ( struct V_1 * V_4 , T_6 V_201 , struct V_31 * V_32 )
{
bool V_214 = false ;
int V_12 ;
struct V_59 * V_161 ;
F_36 ( & V_67 ) ;
F_34 (c, &mrt->mfc6_unres_queue, list) {
if ( F_117 ( & V_161 -> V_91 , & F_65 ( V_32 ) -> V_118 ) &&
F_117 ( & V_161 -> V_92 , & F_65 ( V_32 ) -> V_117 ) ) {
V_214 = true ;
break;
}
}
if ( ! V_214 ) {
if ( F_141 ( & V_4 -> V_163 ) >= 10 ||
( V_161 = F_120 () ) == NULL ) {
F_37 ( & V_67 ) ;
F_78 ( V_32 ) ;
return - V_187 ;
}
V_161 -> V_93 = - 1 ;
V_161 -> V_92 = F_65 ( V_32 ) -> V_117 ;
V_161 -> V_91 = F_65 ( V_32 ) -> V_118 ;
V_12 = F_80 ( V_4 , V_32 , V_201 , V_215 ) ;
if ( V_12 < 0 ) {
F_37 ( & V_67 ) ;
F_96 ( V_161 ) ;
F_78 ( V_32 ) ;
return V_12 ;
}
F_142 ( & V_4 -> V_163 ) ;
F_143 ( & V_161 -> V_49 , & V_4 -> V_55 ) ;
F_107 ( V_4 ) ;
}
if ( V_161 -> V_94 . V_164 . V_165 . V_216 > 3 ) {
F_78 ( V_32 ) ;
V_12 = - V_187 ;
} else {
F_144 ( & V_161 -> V_94 . V_164 . V_165 , V_32 ) ;
V_12 = 0 ;
}
F_37 ( & V_67 ) ;
return V_12 ;
}
static int F_145 ( struct V_1 * V_4 , struct V_217 * V_63 )
{
int line ;
struct V_59 * V_161 , * V_48 ;
line = F_116 ( & V_63 -> V_218 . V_219 , & V_63 -> V_220 . V_219 ) ;
F_21 (c, next, &mrt->mfc6_cache_array[line], list) {
if ( F_117 ( & V_161 -> V_92 , & V_63 -> V_220 . V_219 ) &&
F_117 ( & V_161 -> V_91 , & V_63 -> V_218 . V_219 ) ) {
F_91 ( & V_64 ) ;
F_22 ( & V_161 -> V_49 ) ;
F_92 ( & V_64 ) ;
F_96 ( V_161 ) ;
return 0 ;
}
}
return - V_76 ;
}
static int F_146 ( struct V_221 * V_222 ,
unsigned long V_223 , void * V_224 )
{
struct V_105 * V_81 = V_224 ;
struct V_2 * V_2 = F_61 ( V_81 ) ;
struct V_1 * V_4 ;
struct V_68 * V_78 ;
int V_65 ;
F_147 ( V_49 ) ;
if ( V_223 != V_225 )
return V_226 ;
F_2 (mrt, net) {
V_78 = & V_4 -> V_72 [ 0 ] ;
for ( V_65 = 0 ; V_65 < V_4 -> V_71 ; V_65 ++ , V_78 ++ ) {
if ( V_78 -> V_81 == V_81 )
F_90 ( V_4 , V_65 , & V_49 ) ;
}
}
F_148 ( & V_49 ) ;
return V_226 ;
}
static int T_2 F_149 ( struct V_2 * V_2 )
{
int V_12 ;
V_12 = F_11 ( V_2 ) ;
if ( V_12 < 0 )
goto V_227;
#ifdef F_150
V_12 = - V_45 ;
if ( ! F_151 ( V_2 , L_13 , 0 , & V_228 ) )
goto V_229;
if ( ! F_151 ( V_2 , L_14 , 0 , & V_230 ) )
goto V_231;
#endif
return 0 ;
#ifdef F_150
V_231:
F_152 ( V_2 , L_13 ) ;
V_229:
F_20 ( V_2 ) ;
#endif
V_227:
return V_12 ;
}
static void T_3 F_153 ( struct V_2 * V_2 )
{
#ifdef F_150
F_152 ( V_2 , L_14 ) ;
F_152 ( V_2 , L_13 ) ;
#endif
F_20 ( V_2 ) ;
}
int T_7 F_154 ( void )
{
int V_12 ;
V_162 = F_155 ( L_15 ,
sizeof( struct V_59 ) ,
0 , V_232 ,
NULL ) ;
if ( ! V_162 )
return - V_45 ;
V_12 = F_156 ( & V_233 ) ;
if ( V_12 )
goto V_234;
V_12 = F_157 ( & V_235 ) ;
if ( V_12 )
goto V_236;
#ifdef F_27
if ( F_158 ( & V_237 , V_119 ) < 0 ) {
F_139 ( V_238 L_16 ) ;
V_12 = - V_30 ;
goto V_239;
}
#endif
F_159 ( V_240 , V_241 , NULL ,
V_242 , NULL ) ;
return 0 ;
#ifdef F_27
V_239:
F_160 ( & V_235 ) ;
#endif
V_236:
F_161 ( & V_233 ) ;
V_234:
F_162 ( V_162 ) ;
return V_12 ;
}
void F_163 ( void )
{
F_160 ( & V_235 ) ;
F_161 ( & V_233 ) ;
F_162 ( V_162 ) ;
}
static int F_164 ( struct V_2 * V_2 , struct V_1 * V_4 ,
struct V_217 * V_63 , int V_183 )
{
bool V_214 = false ;
int line ;
struct V_59 * V_199 , * V_161 ;
unsigned char V_99 [ V_180 ] ;
int V_51 ;
if ( V_63 -> V_243 >= V_180 )
return - V_244 ;
memset ( V_99 , 255 , V_180 ) ;
for ( V_51 = 0 ; V_51 < V_180 ; V_51 ++ ) {
if ( F_165 ( V_51 , & V_63 -> V_245 ) )
V_99 [ V_51 ] = 1 ;
}
line = F_116 ( & V_63 -> V_218 . V_219 , & V_63 -> V_220 . V_219 ) ;
F_34 (c, &mrt->mfc6_cache_array[line], list) {
if ( F_117 ( & V_161 -> V_92 , & V_63 -> V_220 . V_219 ) &&
F_117 ( & V_161 -> V_91 , & V_63 -> V_218 . V_219 ) ) {
V_214 = true ;
break;
}
}
if ( V_214 ) {
F_91 ( & V_64 ) ;
V_161 -> V_93 = V_63 -> V_243 ;
F_112 ( V_4 , V_161 , V_99 ) ;
if ( ! V_183 )
V_161 -> V_246 |= V_247 ;
F_92 ( & V_64 ) ;
return 0 ;
}
if ( ! F_69 ( & V_63 -> V_218 . V_219 ) )
return - V_27 ;
V_161 = F_118 () ;
if ( V_161 == NULL )
return - V_45 ;
V_161 -> V_92 = V_63 -> V_220 . V_219 ;
V_161 -> V_91 = V_63 -> V_218 . V_219 ;
V_161 -> V_93 = V_63 -> V_243 ;
F_112 ( V_4 , V_161 , V_99 ) ;
if ( ! V_183 )
V_161 -> V_246 |= V_247 ;
F_91 ( & V_64 ) ;
F_143 ( & V_161 -> V_49 , & V_4 -> V_54 [ line ] ) ;
F_92 ( & V_64 ) ;
V_214 = false ;
F_36 ( & V_67 ) ;
F_34 (uc, &mrt->mfc6_unres_queue, list) {
if ( F_117 ( & V_199 -> V_92 , & V_161 -> V_92 ) &&
F_117 ( & V_199 -> V_91 , & V_161 -> V_91 ) ) {
F_22 ( & V_199 -> V_49 ) ;
F_100 ( & V_4 -> V_163 ) ;
V_214 = true ;
break;
}
}
if ( F_54 ( & V_4 -> V_55 ) )
F_30 ( & V_4 -> V_56 ) ;
F_37 ( & V_67 ) ;
if ( V_214 ) {
F_122 ( V_2 , V_4 , V_199 , V_161 ) ;
F_96 ( V_199 ) ;
}
return 0 ;
}
static void F_31 ( struct V_1 * V_4 )
{
int V_51 ;
F_147 ( V_49 ) ;
struct V_59 * V_161 , * V_48 ;
for ( V_51 = 0 ; V_51 < V_4 -> V_71 ; V_51 ++ ) {
if ( ! ( V_4 -> V_72 [ V_51 ] . V_19 & V_191 ) )
F_90 ( V_4 , V_51 , & V_49 ) ;
}
F_148 ( & V_49 ) ;
for ( V_51 = 0 ; V_51 < V_53 ; V_51 ++ ) {
F_21 (c, next, &mrt->mfc6_cache_array[i], list) {
if ( V_161 -> V_246 & V_247 )
continue;
F_91 ( & V_64 ) ;
F_22 ( & V_161 -> V_49 ) ;
F_92 ( & V_64 ) ;
F_96 ( V_161 ) ;
}
}
if ( F_141 ( & V_4 -> V_163 ) != 0 ) {
F_36 ( & V_67 ) ;
F_21 (c, next, &mrt->mfc6_unres_queue, list) {
F_22 ( & V_161 -> V_49 ) ;
F_98 ( V_4 , V_161 ) ;
}
F_37 ( & V_67 ) ;
}
}
static int F_166 ( struct V_1 * V_4 , struct V_248 * V_249 )
{
int V_12 = 0 ;
struct V_2 * V_2 = F_167 ( V_249 ) ;
F_88 () ;
F_91 ( & V_64 ) ;
if ( F_168 ( V_4 -> V_212 == NULL ) ) {
V_4 -> V_212 = V_249 ;
V_2 -> V_13 . V_250 -> V_159 ++ ;
}
else
V_12 = - V_185 ;
F_92 ( & V_64 ) ;
F_87 () ;
return V_12 ;
}
int F_169 ( struct V_248 * V_249 )
{
int V_12 = - V_25 ;
struct V_2 * V_2 = F_167 ( V_249 ) ;
struct V_1 * V_4 ;
F_88 () ;
F_2 (mrt, net) {
if ( V_249 == V_4 -> V_212 ) {
F_91 ( & V_64 ) ;
V_4 -> V_212 = NULL ;
V_2 -> V_13 . V_250 -> V_159 -- ;
F_92 ( & V_64 ) ;
F_31 ( V_4 ) ;
V_12 = 0 ;
break;
}
}
F_87 () ;
return V_12 ;
}
struct V_248 * F_170 ( struct V_2 * V_2 , struct V_31 * V_32 )
{
struct V_1 * V_4 ;
struct V_5 V_107 = {
. V_108 = V_32 -> V_133 ,
. V_132 = V_32 -> V_81 -> V_109 ,
. V_110 = V_32 -> V_111 ,
} ;
if ( F_3 ( V_2 , & V_107 , & V_4 ) < 0 )
return NULL ;
return V_4 -> V_212 ;
}
int F_171 ( struct V_248 * V_249 , int V_251 , char T_8 * V_252 , unsigned int V_253 )
{
int V_204 ;
struct V_181 V_79 ;
struct V_217 V_63 ;
T_6 V_201 ;
struct V_2 * V_2 = F_167 ( V_249 ) ;
struct V_1 * V_4 ;
V_4 = F_1 ( V_2 , F_172 ( V_249 ) -> V_254 ? : V_44 ) ;
if ( V_4 == NULL )
return - V_76 ;
if ( V_251 != V_255 ) {
if ( V_249 != V_4 -> V_212 && ! F_173 ( V_256 ) )
return - V_25 ;
}
switch ( V_251 ) {
case V_255 :
if ( V_249 -> V_257 != V_258 ||
F_174 ( V_249 ) -> V_259 != V_260 )
return - V_261 ;
if ( V_253 < sizeof( int ) )
return - V_27 ;
return F_166 ( V_4 , V_249 ) ;
case V_262 :
return F_169 ( V_249 ) ;
case V_263 :
if ( V_253 < sizeof( V_79 ) )
return - V_27 ;
if ( F_175 ( & V_79 , V_252 , sizeof( V_79 ) ) )
return - V_264 ;
if ( V_79 . V_184 >= V_180 )
return - V_244 ;
F_88 () ;
V_204 = F_113 ( V_2 , V_4 , & V_79 , V_249 == V_4 -> V_212 ) ;
F_87 () ;
return V_204 ;
case V_265 :
if ( V_253 < sizeof( T_6 ) )
return - V_27 ;
if ( F_175 ( & V_201 , V_252 , sizeof( T_6 ) ) )
return - V_264 ;
F_88 () ;
V_204 = F_90 ( V_4 , V_201 , NULL ) ;
F_87 () ;
return V_204 ;
case V_266 :
case V_267 :
if ( V_253 < sizeof( V_63 ) )
return - V_27 ;
if ( F_175 ( & V_63 , V_252 , sizeof( V_63 ) ) )
return - V_264 ;
F_88 () ;
if ( V_251 == V_267 )
V_204 = F_145 ( V_4 , & V_63 ) ;
else
V_204 = F_164 ( V_2 , V_4 , & V_63 , V_249 == V_4 -> V_212 ) ;
F_87 () ;
return V_204 ;
case V_268 :
{
int V_78 ;
if ( F_176 ( V_78 , ( int T_8 * ) V_252 ) )
return - V_264 ;
V_4 -> V_269 = ! ! V_78 ;
return 0 ;
}
#ifdef F_27
case V_270 :
{
int V_78 ;
if ( F_176 ( V_78 , ( int T_8 * ) V_252 ) )
return - V_264 ;
V_78 = ! ! V_78 ;
F_88 () ;
V_204 = 0 ;
if ( V_78 != V_4 -> V_271 ) {
V_4 -> V_271 = V_78 ;
V_4 -> V_269 = V_78 ;
}
F_87 () ;
return V_204 ;
}
#endif
#ifdef F_28
case V_272 :
{
T_1 V_78 ;
if ( V_253 != sizeof( T_1 ) )
return - V_27 ;
if ( F_176 ( V_78 , ( T_1 T_8 * ) V_252 ) )
return - V_264 ;
if ( V_249 == V_4 -> V_212 )
return - V_273 ;
F_88 () ;
V_204 = 0 ;
if ( ! F_16 ( V_2 , V_78 ) )
V_204 = - V_45 ;
F_172 ( V_249 ) -> V_254 = V_78 ;
F_87 () ;
return V_204 ;
}
#endif
default:
return - V_274 ;
}
}
int F_177 ( struct V_248 * V_249 , int V_251 , char T_8 * V_252 ,
int T_8 * V_253 )
{
int V_275 ;
int V_276 ;
struct V_2 * V_2 = F_167 ( V_249 ) ;
struct V_1 * V_4 ;
V_4 = F_1 ( V_2 , F_172 ( V_249 ) -> V_254 ? : V_44 ) ;
if ( V_4 == NULL )
return - V_76 ;
switch ( V_251 ) {
case V_277 :
V_276 = 0x0305 ;
break;
#ifdef F_27
case V_270 :
V_276 = V_4 -> V_271 ;
break;
#endif
case V_268 :
V_276 = V_4 -> V_269 ;
break;
default:
return - V_274 ;
}
if ( F_176 ( V_275 , V_253 ) )
return - V_264 ;
V_275 = F_178 ( int , V_275 , sizeof( int ) ) ;
if ( V_275 < 0 )
return - V_27 ;
if ( F_179 ( V_275 , V_253 ) )
return - V_264 ;
if ( F_180 ( V_252 , & V_276 , V_275 ) )
return - V_264 ;
return 0 ;
}
int F_181 ( struct V_248 * V_249 , int V_278 , void T_8 * V_10 )
{
struct V_279 V_280 ;
struct V_281 V_282 ;
struct V_68 * V_79 ;
struct V_59 * V_161 ;
struct V_2 * V_2 = F_167 ( V_249 ) ;
struct V_1 * V_4 ;
V_4 = F_1 ( V_2 , F_172 ( V_249 ) -> V_254 ? : V_44 ) ;
if ( V_4 == NULL )
return - V_76 ;
switch ( V_278 ) {
case V_283 :
if ( F_175 ( & V_282 , V_10 , sizeof( V_282 ) ) )
return - V_264 ;
if ( V_282 . V_201 >= V_4 -> V_71 )
return - V_27 ;
F_33 ( & V_64 ) ;
V_79 = & V_4 -> V_72 [ V_282 . V_201 ] ;
if ( F_39 ( V_4 , V_282 . V_201 ) ) {
V_282 . V_284 = V_79 -> V_83 ;
V_282 . V_285 = V_79 -> V_85 ;
V_282 . V_286 = V_79 -> V_82 ;
V_282 . V_287 = V_79 -> V_84 ;
F_35 ( & V_64 ) ;
if ( F_180 ( V_10 , & V_282 , sizeof( V_282 ) ) )
return - V_264 ;
return 0 ;
}
F_35 ( & V_64 ) ;
return - V_156 ;
case V_288 :
if ( F_175 ( & V_280 , V_10 , sizeof( V_280 ) ) )
return - V_264 ;
F_33 ( & V_64 ) ;
V_161 = F_115 ( V_4 , & V_280 . V_289 . V_219 , & V_280 . V_290 . V_219 ) ;
if ( V_161 ) {
V_280 . V_291 = V_161 -> V_94 . V_8 . V_95 ;
V_280 . V_292 = V_161 -> V_94 . V_8 . V_96 ;
V_280 . V_97 = V_161 -> V_94 . V_8 . V_97 ;
F_35 ( & V_64 ) ;
if ( F_180 ( V_10 , & V_280 , sizeof( V_280 ) ) )
return - V_264 ;
return 0 ;
}
F_35 ( & V_64 ) ;
return - V_156 ;
default:
return - V_293 ;
}
}
int F_182 ( struct V_248 * V_249 , unsigned int V_278 , void T_8 * V_10 )
{
struct V_294 V_280 ;
struct V_295 V_282 ;
struct V_68 * V_79 ;
struct V_59 * V_161 ;
struct V_2 * V_2 = F_167 ( V_249 ) ;
struct V_1 * V_4 ;
V_4 = F_1 ( V_2 , F_172 ( V_249 ) -> V_254 ? : V_44 ) ;
if ( V_4 == NULL )
return - V_76 ;
switch ( V_278 ) {
case V_283 :
if ( F_175 ( & V_282 , V_10 , sizeof( V_282 ) ) )
return - V_264 ;
if ( V_282 . V_201 >= V_4 -> V_71 )
return - V_27 ;
F_33 ( & V_64 ) ;
V_79 = & V_4 -> V_72 [ V_282 . V_201 ] ;
if ( F_39 ( V_4 , V_282 . V_201 ) ) {
V_282 . V_284 = V_79 -> V_83 ;
V_282 . V_285 = V_79 -> V_85 ;
V_282 . V_286 = V_79 -> V_82 ;
V_282 . V_287 = V_79 -> V_84 ;
F_35 ( & V_64 ) ;
if ( F_180 ( V_10 , & V_282 , sizeof( V_282 ) ) )
return - V_264 ;
return 0 ;
}
F_35 ( & V_64 ) ;
return - V_156 ;
case V_288 :
if ( F_175 ( & V_280 , V_10 , sizeof( V_280 ) ) )
return - V_264 ;
F_33 ( & V_64 ) ;
V_161 = F_115 ( V_4 , & V_280 . V_289 . V_219 , & V_280 . V_290 . V_219 ) ;
if ( V_161 ) {
V_280 . V_291 = V_161 -> V_94 . V_8 . V_95 ;
V_280 . V_292 = V_161 -> V_94 . V_8 . V_96 ;
V_280 . V_97 = V_161 -> V_94 . V_8 . V_97 ;
F_35 ( & V_64 ) ;
if ( F_180 ( V_10 , & V_280 , sizeof( V_280 ) ) )
return - V_264 ;
return 0 ;
}
F_35 ( & V_64 ) ;
return - V_156 ;
default:
return - V_293 ;
}
}
static inline int F_183 ( struct V_31 * V_32 )
{
F_184 ( F_61 ( F_136 ( V_32 ) -> V_81 ) , F_185 ( F_136 ( V_32 ) ) ,
V_296 ) ;
return F_186 ( V_32 ) ;
}
static int F_187 ( struct V_2 * V_2 , struct V_1 * V_4 ,
struct V_31 * V_32 , struct V_59 * V_161 , int V_151 )
{
struct V_103 * V_297 ;
struct V_68 * V_79 = & V_4 -> V_72 [ V_151 ] ;
struct V_105 * V_81 ;
struct V_298 * V_299 ;
struct V_5 V_107 ;
if ( V_79 -> V_81 == NULL )
goto V_300;
#ifdef F_27
if ( V_79 -> V_19 & V_160 ) {
V_79 -> V_85 ++ ;
V_79 -> V_84 += V_32 -> V_120 ;
V_79 -> V_81 -> V_134 . V_135 += V_32 -> V_120 ;
V_79 -> V_81 -> V_134 . V_136 ++ ;
F_80 ( V_4 , V_32 , V_151 , V_137 ) ;
goto V_300;
}
#endif
V_297 = F_65 ( V_32 ) ;
V_107 = (struct V_5 ) {
. V_132 = V_79 -> V_194 ,
. V_118 = V_297 -> V_118 ,
} ;
V_299 = F_188 ( V_2 , NULL , & V_107 ) ;
if ( V_299 -> error ) {
F_189 ( V_299 ) ;
goto V_300;
}
F_190 ( V_32 ) ;
F_134 ( V_32 , V_299 ) ;
V_81 = V_79 -> V_81 ;
V_32 -> V_81 = V_81 ;
V_79 -> V_85 ++ ;
V_79 -> V_84 += V_32 -> V_120 ;
if ( F_191 ( V_32 , sizeof( * V_297 ) + F_192 ( V_81 ) ) )
goto V_300;
V_297 = F_65 ( V_32 ) ;
V_297 -> V_301 -- ;
F_193 ( V_32 ) -> V_19 |= V_302 ;
return F_194 ( V_303 , V_304 , V_32 , V_32 -> V_81 , V_81 ,
F_183 ) ;
V_300:
F_78 ( V_32 ) ;
return 0 ;
}
static int F_195 ( struct V_1 * V_4 , struct V_105 * V_81 )
{
int V_65 ;
for ( V_65 = V_4 -> V_71 - 1 ; V_65 >= 0 ; V_65 -- ) {
if ( V_4 -> V_72 [ V_65 ] . V_81 == V_81 )
break;
}
return V_65 ;
}
static int F_126 ( struct V_2 * V_2 , struct V_1 * V_4 ,
struct V_31 * V_32 , struct V_59 * V_66 )
{
int V_305 = - 1 ;
int V_79 , V_65 ;
V_79 = V_66 -> V_93 ;
V_66 -> V_94 . V_8 . V_95 ++ ;
V_66 -> V_94 . V_8 . V_96 += V_32 -> V_120 ;
if ( V_4 -> V_72 [ V_79 ] . V_81 != V_32 -> V_81 ) {
int V_306 ;
V_66 -> V_94 . V_8 . V_97 ++ ;
V_306 = F_195 ( V_4 , V_32 -> V_81 ) ;
if ( V_306 >= 0 && V_4 -> V_269 &&
( V_4 -> V_271 ||
V_66 -> V_94 . V_8 . V_99 [ V_306 ] < 255 ) &&
F_108 ( V_176 ,
V_66 -> V_94 . V_8 . V_307 + V_308 ) ) {
V_66 -> V_94 . V_8 . V_307 = V_176 ;
F_80 ( V_4 , V_32 , V_306 , V_309 ) ;
}
goto V_310;
}
V_4 -> V_72 [ V_79 ] . V_83 ++ ;
V_4 -> V_72 [ V_79 ] . V_82 += V_32 -> V_120 ;
for ( V_65 = V_66 -> V_94 . V_8 . V_71 - 1 ; V_65 >= V_66 -> V_94 . V_8 . V_98 ; V_65 -- ) {
if ( F_65 ( V_32 ) -> V_301 > V_66 -> V_94 . V_8 . V_99 [ V_65 ] ) {
if ( V_305 != - 1 ) {
struct V_31 * V_311 = F_196 ( V_32 , V_198 ) ;
if ( V_311 )
F_187 ( V_2 , V_4 , V_311 , V_66 , V_305 ) ;
}
V_305 = V_65 ;
}
}
if ( V_305 != - 1 ) {
F_187 ( V_2 , V_4 , V_32 , V_66 , V_305 ) ;
return 0 ;
}
V_310:
F_78 ( V_32 ) ;
return 0 ;
}
int F_197 ( struct V_31 * V_32 )
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
V_66 = F_115 ( V_4 ,
& F_65 ( V_32 ) -> V_117 , & F_65 ( V_32 ) -> V_118 ) ;
if ( V_66 == NULL ) {
int V_79 ;
V_79 = F_195 ( V_4 , V_32 -> V_81 ) ;
if ( V_79 >= 0 ) {
int V_12 = F_140 ( V_4 , V_79 , V_32 ) ;
F_35 ( & V_64 ) ;
return V_12 ;
}
F_35 ( & V_64 ) ;
F_78 ( V_32 ) ;
return - V_312 ;
}
F_126 ( V_2 , V_4 , V_32 , V_66 ) ;
F_35 ( & V_64 ) ;
return 0 ;
}
static int F_124 ( struct V_1 * V_4 , struct V_31 * V_32 ,
struct V_59 * V_161 , struct V_313 * V_314 )
{
int V_65 ;
struct V_315 * V_316 ;
V_124 * V_317 = F_125 ( V_32 ) ;
struct V_318 * V_319 ;
if ( V_161 -> V_93 >= V_180 )
return - V_76 ;
if ( F_39 ( V_4 , V_161 -> V_93 ) )
F_198 ( V_32 , V_320 , 4 , & V_4 -> V_72 [ V_161 -> V_93 ] . V_81 -> V_109 ) ;
V_319 = (struct V_318 * ) F_132 ( V_32 , F_199 ( 0 ) ) ;
for ( V_65 = V_161 -> V_94 . V_8 . V_98 ; V_65 < V_161 -> V_94 . V_8 . V_71 ; V_65 ++ ) {
if ( F_39 ( V_4 , V_65 ) && V_161 -> V_94 . V_8 . V_99 [ V_65 ] < 255 ) {
if ( F_200 ( V_32 ) < F_201 ( F_201 ( sizeof( * V_316 ) ) + 4 ) )
goto V_321;
V_316 = (struct V_315 * ) F_132 ( V_32 , F_201 ( sizeof( * V_316 ) ) ) ;
V_316 -> V_322 = 0 ;
V_316 -> V_323 = V_161 -> V_94 . V_8 . V_99 [ V_65 ] ;
V_316 -> V_324 = V_4 -> V_72 [ V_65 ] . V_81 -> V_109 ;
V_316 -> V_325 = sizeof( * V_316 ) ;
}
}
V_319 -> V_326 = V_327 ;
V_319 -> V_328 = F_125 ( V_32 ) - ( V_124 * ) V_319 ;
V_314 -> V_329 = V_330 ;
return 1 ;
V_321:
F_202 ( V_32 , V_317 ) ;
return - V_200 ;
}
int F_203 ( struct V_2 * V_2 ,
struct V_31 * V_32 , struct V_313 * V_314 , int V_331 )
{
int V_12 ;
struct V_1 * V_4 ;
struct V_59 * V_66 ;
struct V_332 * V_333 = (struct V_332 * ) F_136 ( V_32 ) ;
V_4 = F_1 ( V_2 , V_44 ) ;
if ( V_4 == NULL )
return - V_76 ;
F_33 ( & V_64 ) ;
V_66 = F_115 ( V_4 , & V_333 -> V_334 . V_335 , & V_333 -> V_336 . V_335 ) ;
if ( ! V_66 ) {
struct V_31 * V_311 ;
struct V_103 * V_337 ;
struct V_105 * V_81 ;
int V_79 ;
if ( V_331 ) {
F_35 ( & V_64 ) ;
return - V_30 ;
}
V_81 = V_32 -> V_81 ;
if ( V_81 == NULL || ( V_79 = F_195 ( V_4 , V_81 ) ) < 0 ) {
F_35 ( & V_64 ) ;
return - V_312 ;
}
V_311 = F_129 ( sizeof( struct V_103 ) , V_198 ) ;
if ( ! V_311 ) {
F_35 ( & V_64 ) ;
return - V_45 ;
}
F_131 ( V_311 ) ;
F_132 ( V_311 , sizeof( struct V_103 ) ) ;
F_73 ( V_311 ) ;
V_337 = F_65 ( V_311 ) ;
V_337 -> V_166 = 0 ;
V_337 -> V_338 = 0 ;
V_337 -> V_339 [ 0 ] = 0 ;
V_337 -> V_339 [ 1 ] = 0 ;
V_337 -> V_339 [ 2 ] = 0 ;
V_337 -> V_121 = 0 ;
V_337 -> V_340 = V_341 ;
V_337 -> V_301 = 0 ;
V_337 -> V_117 = V_333 -> V_334 . V_335 ;
V_337 -> V_118 = V_333 -> V_336 . V_335 ;
V_12 = F_140 ( V_4 , V_79 , V_311 ) ;
F_35 ( & V_64 ) ;
return V_12 ;
}
if ( ! V_331 && ( V_314 -> V_342 & V_343 ) )
V_66 -> V_246 |= V_344 ;
V_12 = F_124 ( V_4 , V_32 , V_66 , V_314 ) ;
F_35 ( & V_64 ) ;
return V_12 ;
}
static int F_204 ( struct V_1 * V_4 , struct V_31 * V_32 ,
T_1 V_174 , T_1 V_74 , struct V_59 * V_161 )
{
struct V_167 * V_168 ;
struct V_313 * V_314 ;
V_168 = F_205 ( V_32 , V_174 , V_74 , V_345 , sizeof( * V_314 ) , V_346 ) ;
if ( V_168 == NULL )
return - V_200 ;
V_314 = F_206 ( V_168 ) ;
V_314 -> V_347 = V_348 ;
V_314 -> V_349 = 128 ;
V_314 -> V_350 = 128 ;
V_314 -> V_351 = 0 ;
V_314 -> V_352 = V_4 -> V_3 ;
F_207 ( V_32 , V_353 , V_4 -> V_3 ) ;
V_314 -> V_354 = V_355 ;
V_314 -> V_356 = V_357 ;
V_314 -> V_342 = 0 ;
F_208 ( V_32 , V_358 , 16 , & V_161 -> V_92 ) ;
F_208 ( V_32 , V_359 , 16 , & V_161 -> V_91 ) ;
if ( F_124 ( V_4 , V_32 , V_161 , V_314 ) < 0 )
goto V_360;
return F_209 ( V_32 , V_168 ) ;
V_360:
F_210 ( V_32 , V_168 ) ;
return - V_200 ;
}
static int V_242 ( struct V_31 * V_32 , struct V_361 * V_362 )
{
struct V_2 * V_2 = F_167 ( V_32 -> V_249 ) ;
struct V_1 * V_4 ;
struct V_59 * V_63 ;
unsigned int V_363 = 0 , V_364 ;
unsigned int V_365 = 0 , V_366 ;
unsigned int V_367 = 0 , V_368 ;
V_364 = V_362 -> args [ 0 ] ;
V_366 = V_362 -> args [ 1 ] ;
V_368 = V_362 -> args [ 2 ] ;
F_33 ( & V_64 ) ;
F_2 (mrt, net) {
if ( V_363 < V_364 )
goto V_369;
if ( V_363 > V_364 )
V_366 = 0 ;
for ( V_365 = V_366 ; V_365 < V_53 ; V_365 ++ ) {
F_34 (mfc, &mrt->mfc6_cache_array[h], list) {
if ( V_367 < V_368 )
goto V_370;
if ( F_204 ( V_4 , V_32 ,
F_106 ( V_362 -> V_32 ) . V_174 ,
V_362 -> V_168 -> V_371 ,
V_63 ) < 0 )
goto V_372;
V_370:
V_367 ++ ;
}
V_367 = V_368 = 0 ;
}
V_366 = 0 ;
V_369:
V_363 ++ ;
}
V_372:
F_35 ( & V_64 ) ;
V_362 -> args [ 2 ] = V_367 ;
V_362 -> args [ 1 ] = V_365 ;
V_362 -> args [ 0 ] = V_363 ;
return V_32 -> V_120 ;
}
