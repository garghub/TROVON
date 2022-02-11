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
F_21 () ;
F_22 (mrt, next, &net->ipv6.mr6_tables, list) {
F_23 ( & V_4 -> V_49 ) ;
F_24 ( V_4 ) ;
}
F_25 () ;
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
F_21 () ;
F_24 ( V_2 -> V_13 . V_50 ) ;
V_2 -> V_13 . V_50 = NULL ;
F_25 () ;
}
static struct V_1 * F_16 ( struct V_2 * V_2 , T_1 V_3 )
{
struct V_1 * V_4 ;
unsigned int V_51 ;
V_4 = F_1 ( V_2 , V_3 ) ;
if ( V_4 != NULL )
return V_4 ;
V_4 = F_26 ( sizeof( * V_4 ) , V_52 ) ;
if ( V_4 == NULL )
return NULL ;
V_4 -> V_3 = V_3 ;
F_27 ( & V_4 -> V_2 , V_2 ) ;
for ( V_51 = 0 ; V_51 < V_53 ; V_51 ++ )
F_15 ( & V_4 -> V_54 [ V_51 ] ) ;
F_15 ( & V_4 -> V_55 ) ;
F_28 ( & V_4 -> V_56 , V_57 ,
( unsigned long ) V_4 ) ;
#ifdef F_29
V_4 -> V_58 = - 1 ;
#endif
#ifdef F_30
F_31 ( & V_4 -> V_49 , & V_2 -> V_13 . V_43 ) ;
#endif
return V_4 ;
}
static void F_24 ( struct V_1 * V_4 )
{
F_32 ( & V_4 -> V_56 ) ;
F_33 ( V_4 ) ;
F_18 ( V_4 ) ;
}
static struct V_59 * F_34 ( struct V_2 * V_2 ,
struct V_60 * V_61 , T_4 V_62 )
{
struct V_1 * V_4 = V_61 -> V_4 ;
struct V_59 * V_63 ;
F_35 ( & V_64 ) ;
for ( V_61 -> V_65 = 0 ; V_61 -> V_65 < V_53 ; V_61 -> V_65 ++ ) {
V_61 -> V_66 = & V_4 -> V_54 [ V_61 -> V_65 ] ;
F_36 (mfc, it->cache, list)
if ( V_62 -- == 0 )
return V_63 ;
}
F_37 ( & V_64 ) ;
F_38 ( & V_67 ) ;
V_61 -> V_66 = & V_4 -> V_55 ;
F_36 (mfc, it->cache, list)
if ( V_62 -- == 0 )
return V_63 ;
F_39 ( & V_67 ) ;
V_61 -> V_66 = NULL ;
return NULL ;
}
static struct V_68 * F_40 ( struct V_2 * V_2 ,
struct V_69 * V_70 ,
T_4 V_62 )
{
struct V_1 * V_4 = V_70 -> V_4 ;
for ( V_70 -> V_65 = 0 ; V_70 -> V_65 < V_4 -> V_71 ; ++ V_70 -> V_65 ) {
if ( ! F_41 ( V_4 , V_70 -> V_65 ) )
continue;
if ( V_62 -- == 0 )
return & V_4 -> V_72 [ V_70 -> V_65 ] ;
}
return NULL ;
}
static void * F_42 ( struct V_73 * V_74 , T_4 * V_62 )
__acquires( V_64 )
{
struct V_69 * V_70 = V_74 -> V_75 ;
struct V_2 * V_2 = F_43 ( V_74 ) ;
struct V_1 * V_4 ;
V_4 = F_1 ( V_2 , V_44 ) ;
if ( V_4 == NULL )
return F_44 ( - V_76 ) ;
V_70 -> V_4 = V_4 ;
F_35 ( & V_64 ) ;
return * V_62 ? F_40 ( V_2 , V_74 -> V_75 , * V_62 - 1 )
: V_77 ;
}
static void * F_45 ( struct V_73 * V_74 , void * V_78 , T_4 * V_62 )
{
struct V_69 * V_70 = V_74 -> V_75 ;
struct V_2 * V_2 = F_43 ( V_74 ) ;
struct V_1 * V_4 = V_70 -> V_4 ;
++ * V_62 ;
if ( V_78 == V_77 )
return F_40 ( V_2 , V_70 , 0 ) ;
while ( ++ V_70 -> V_65 < V_4 -> V_71 ) {
if ( ! F_41 ( V_4 , V_70 -> V_65 ) )
continue;
return & V_4 -> V_72 [ V_70 -> V_65 ] ;
}
return NULL ;
}
static void F_46 ( struct V_73 * V_74 , void * V_78 )
__releases( V_64 )
{
F_37 ( & V_64 ) ;
}
static int F_47 ( struct V_73 * V_74 , void * V_78 )
{
struct V_69 * V_70 = V_74 -> V_75 ;
struct V_1 * V_4 = V_70 -> V_4 ;
if ( V_78 == V_77 ) {
F_48 ( V_74 ,
L_1 ) ;
} else {
const struct V_68 * V_79 = V_78 ;
const char * V_80 = V_79 -> V_81 ? V_79 -> V_81 -> V_80 : L_2 ;
F_49 ( V_74 ,
L_3 ,
V_79 - V_4 -> V_72 ,
V_80 , V_79 -> V_82 , V_79 -> V_83 ,
V_79 -> V_84 , V_79 -> V_85 ,
V_79 -> V_19 ) ;
}
return 0 ;
}
static int F_50 ( struct V_86 * V_86 , struct V_87 * V_87 )
{
return F_51 ( V_86 , V_87 , & V_88 ,
sizeof( struct V_69 ) ) ;
}
static void * F_52 ( struct V_73 * V_74 , T_4 * V_62 )
{
struct V_60 * V_61 = V_74 -> V_75 ;
struct V_2 * V_2 = F_43 ( V_74 ) ;
struct V_1 * V_4 ;
V_4 = F_1 ( V_2 , V_44 ) ;
if ( V_4 == NULL )
return F_44 ( - V_76 ) ;
V_61 -> V_4 = V_4 ;
return * V_62 ? F_34 ( V_2 , V_74 -> V_75 , * V_62 - 1 )
: V_77 ;
}
static void * F_53 ( struct V_73 * V_74 , void * V_78 , T_4 * V_62 )
{
struct V_59 * V_63 = V_78 ;
struct V_60 * V_61 = V_74 -> V_75 ;
struct V_2 * V_2 = F_43 ( V_74 ) ;
struct V_1 * V_4 = V_61 -> V_4 ;
++ * V_62 ;
if ( V_78 == V_77 )
return F_34 ( V_2 , V_74 -> V_75 , 0 ) ;
if ( V_63 -> V_49 . V_48 != V_61 -> V_66 )
return F_54 ( V_63 -> V_49 . V_48 , struct V_59 , V_49 ) ;
if ( V_61 -> V_66 == & V_4 -> V_55 )
goto V_89;
F_55 ( V_61 -> V_66 != & V_4 -> V_54 [ V_61 -> V_65 ] ) ;
while ( ++ V_61 -> V_65 < V_53 ) {
V_61 -> V_66 = & V_4 -> V_54 [ V_61 -> V_65 ] ;
if ( F_56 ( V_61 -> V_66 ) )
continue;
return F_57 ( V_61 -> V_66 , struct V_59 , V_49 ) ;
}
F_37 ( & V_64 ) ;
V_61 -> V_66 = & V_4 -> V_55 ;
V_61 -> V_65 = 0 ;
F_38 ( & V_67 ) ;
if ( ! F_56 ( V_61 -> V_66 ) )
return F_57 ( V_61 -> V_66 , struct V_59 , V_49 ) ;
V_89:
F_39 ( & V_67 ) ;
V_61 -> V_66 = NULL ;
return NULL ;
}
static void F_58 ( struct V_73 * V_74 , void * V_78 )
{
struct V_60 * V_61 = V_74 -> V_75 ;
struct V_1 * V_4 = V_61 -> V_4 ;
if ( V_61 -> V_66 == & V_4 -> V_55 )
F_39 ( & V_67 ) ;
else if ( V_61 -> V_66 == V_4 -> V_54 )
F_37 ( & V_64 ) ;
}
static int F_59 ( struct V_73 * V_74 , void * V_78 )
{
int V_90 ;
if ( V_78 == V_77 ) {
F_48 ( V_74 ,
L_4
L_5
L_6 ) ;
} else {
const struct V_59 * V_63 = V_78 ;
const struct V_60 * V_61 = V_74 -> V_75 ;
struct V_1 * V_4 = V_61 -> V_4 ;
F_49 ( V_74 , L_7 ,
& V_63 -> V_91 , & V_63 -> V_92 ,
V_63 -> V_93 ) ;
if ( V_61 -> V_66 != & V_4 -> V_55 ) {
F_49 ( V_74 , L_8 ,
V_63 -> V_94 . V_8 . V_95 ,
V_63 -> V_94 . V_8 . V_96 ,
V_63 -> V_94 . V_8 . V_97 ) ;
for ( V_90 = V_63 -> V_94 . V_8 . V_98 ;
V_90 < V_63 -> V_94 . V_8 . V_71 ; V_90 ++ ) {
if ( F_41 ( V_4 , V_90 ) &&
V_63 -> V_94 . V_8 . V_99 [ V_90 ] < 255 )
F_49 ( V_74 ,
L_9 ,
V_90 , V_63 -> V_94 . V_8 . V_99 [ V_90 ] ) ;
}
} else {
F_49 ( V_74 , L_8 , 0ul , 0ul , 0ul ) ;
}
F_60 ( V_74 , '\n' ) ;
}
return 0 ;
}
static int F_61 ( struct V_86 * V_86 , struct V_87 * V_87 )
{
return F_51 ( V_86 , V_87 , & V_100 ,
sizeof( struct V_60 ) ) ;
}
static int F_62 ( struct V_31 * V_32 )
{
struct V_101 * V_102 ;
struct V_103 * V_104 ;
struct V_105 * V_106 = NULL ;
struct V_2 * V_2 = F_63 ( V_32 -> V_81 ) ;
struct V_1 * V_4 ;
struct V_5 V_107 = {
. V_108 = V_32 -> V_81 -> V_109 ,
. V_110 = V_32 -> V_111 ,
} ;
int V_112 ;
if ( ! F_64 ( V_32 , sizeof( * V_102 ) + sizeof( * V_104 ) ) )
goto V_113;
V_102 = (struct V_101 * ) F_65 ( V_32 ) ;
if ( V_102 -> type != ( ( V_114 << 4 ) | V_115 ) ||
( V_102 -> V_19 & V_116 ) ||
( F_66 ( & F_67 ( V_32 ) -> V_117 , & F_67 ( V_32 ) -> V_118 ,
sizeof( * V_102 ) , V_119 ,
F_68 ( ( void * ) V_102 , sizeof( * V_102 ) , 0 ) ) &&
F_69 ( F_70 ( V_32 , 0 , V_32 -> V_120 , 0 ) ) ) )
goto V_113;
V_104 = (struct V_103 * ) ( F_65 ( V_32 ) +
sizeof( * V_102 ) ) ;
if ( ! F_71 ( & V_104 -> V_118 ) ||
V_104 -> V_121 == 0 ||
F_72 ( V_104 -> V_121 ) + sizeof( * V_102 ) > V_32 -> V_120 )
goto V_113;
if ( F_3 ( V_2 , & V_107 , & V_4 ) < 0 )
goto V_113;
V_112 = V_4 -> V_58 ;
F_35 ( & V_64 ) ;
if ( V_112 >= 0 )
V_106 = V_4 -> V_72 [ V_112 ] . V_81 ;
if ( V_106 )
F_73 ( V_106 ) ;
F_37 ( & V_64 ) ;
if ( V_106 == NULL )
goto V_113;
V_32 -> V_122 = V_32 -> V_123 ;
F_74 ( V_32 , ( V_124 * ) V_104 - V_32 -> V_125 ) ;
F_75 ( V_32 ) ;
V_32 -> V_126 = F_76 ( V_127 ) ;
V_32 -> V_128 = V_129 ;
F_77 ( V_32 , V_106 , F_63 ( V_106 ) ) ;
F_78 ( V_32 ) ;
F_79 ( V_106 ) ;
return 0 ;
V_113:
F_80 ( V_32 ) ;
return 0 ;
}
static T_5 F_81 ( struct V_31 * V_32 ,
struct V_105 * V_81 )
{
struct V_2 * V_2 = F_63 ( V_81 ) ;
struct V_1 * V_4 ;
struct V_5 V_107 = {
. V_130 = V_81 -> V_109 ,
. V_108 = V_32 -> V_131 ,
. V_110 = V_32 -> V_111 ,
} ;
int V_12 ;
V_12 = F_3 ( V_2 , & V_107 , & V_4 ) ;
if ( V_12 < 0 ) {
F_80 ( V_32 ) ;
return V_12 ;
}
F_35 ( & V_64 ) ;
V_81 -> V_132 . V_133 += V_32 -> V_120 ;
V_81 -> V_132 . V_134 ++ ;
F_82 ( V_4 , V_32 , V_4 -> V_58 , V_135 ) ;
F_37 ( & V_64 ) ;
F_80 ( V_32 ) ;
return V_136 ;
}
static void F_83 ( struct V_105 * V_81 )
{
V_81 -> type = V_137 ;
V_81 -> V_138 = 1500 - sizeof( struct V_103 ) - 8 ;
V_81 -> V_19 = V_139 ;
V_81 -> V_140 = & V_141 ;
V_81 -> V_142 = V_143 ;
V_81 -> V_144 |= V_145 ;
}
static struct V_105 * F_84 ( struct V_2 * V_2 , struct V_1 * V_4 )
{
struct V_105 * V_81 ;
char V_80 [ V_146 ] ;
if ( V_4 -> V_3 == V_44 )
sprintf ( V_80 , L_10 ) ;
else
sprintf ( V_80 , L_11 , V_4 -> V_3 ) ;
V_81 = F_85 ( 0 , V_80 , F_83 ) ;
if ( V_81 == NULL )
return NULL ;
F_86 ( V_81 , V_2 ) ;
if ( F_87 ( V_81 ) ) {
V_143 ( V_81 ) ;
return NULL ;
}
V_81 -> V_147 = 0 ;
if ( F_88 ( V_81 ) )
goto V_148;
F_73 ( V_81 ) ;
return V_81 ;
V_148:
F_25 () ;
F_21 () ;
F_89 ( V_81 ) ;
return NULL ;
}
static int F_90 ( struct V_1 * V_4 , int V_149 , struct V_150 * V_151 )
{
struct V_68 * V_78 ;
struct V_105 * V_81 ;
struct V_152 * V_153 ;
if ( V_149 < 0 || V_149 >= V_4 -> V_71 )
return - V_154 ;
V_78 = & V_4 -> V_72 [ V_149 ] ;
F_91 ( & V_64 ) ;
V_81 = V_78 -> V_81 ;
V_78 -> V_81 = NULL ;
if ( ! V_81 ) {
F_92 ( & V_64 ) ;
return - V_154 ;
}
#ifdef F_29
if ( V_149 == V_4 -> V_58 )
V_4 -> V_58 = - 1 ;
#endif
if ( V_149 + 1 == V_4 -> V_71 ) {
int V_155 ;
for ( V_155 = V_149 - 1 ; V_155 >= 0 ; V_155 -- ) {
if ( F_41 ( V_4 , V_155 ) )
break;
}
V_4 -> V_71 = V_155 + 1 ;
}
F_92 ( & V_64 ) ;
F_93 ( V_81 , - 1 ) ;
V_153 = F_94 ( V_81 ) ;
if ( V_153 ) {
V_153 -> V_156 . V_157 -- ;
F_95 ( F_63 ( V_81 ) ,
V_158 ,
V_81 -> V_109 , & V_153 -> V_156 ) ;
}
if ( V_78 -> V_19 & V_159 )
F_96 ( V_81 , V_151 ) ;
F_79 ( V_81 ) ;
return 0 ;
}
static inline void F_97 ( struct V_59 * V_160 )
{
F_98 ( V_161 , V_160 ) ;
}
static void F_99 ( struct V_1 * V_4 , struct V_59 * V_160 )
{
struct V_2 * V_2 = F_100 ( & V_4 -> V_2 ) ;
struct V_31 * V_32 ;
F_101 ( & V_4 -> V_162 ) ;
while( ( V_32 = F_102 ( & V_160 -> V_94 . V_163 . V_164 ) ) != NULL ) {
if ( F_67 ( V_32 ) -> V_165 == 0 ) {
struct V_166 * V_167 = (struct V_166 * ) F_74 ( V_32 , sizeof( struct V_103 ) ) ;
V_167 -> V_168 = V_169 ;
V_167 -> V_170 = F_103 ( sizeof( struct V_171 ) ) ;
F_104 ( V_32 , V_167 -> V_170 ) ;
( (struct V_171 * ) F_105 ( V_167 ) ) -> error = - V_172 ;
F_106 ( V_32 , V_2 , F_107 ( V_32 ) . V_173 ) ;
} else
F_80 ( V_32 ) ;
}
F_97 ( V_160 ) ;
}
static void F_108 ( struct V_1 * V_4 )
{
unsigned long V_174 = V_175 ;
unsigned long V_176 = 10 * V_177 ;
struct V_59 * V_160 , * V_48 ;
F_22 (c, next, &mrt->mfc6_unres_queue, list) {
if ( F_109 ( V_160 -> V_94 . V_163 . V_176 , V_174 ) ) {
unsigned long V_178 = V_160 -> V_94 . V_163 . V_176 - V_174 ;
if ( V_178 < V_176 )
V_176 = V_178 ;
continue;
}
F_23 ( & V_160 -> V_49 ) ;
F_110 ( V_4 , V_160 , V_179 ) ;
F_99 ( V_4 , V_160 ) ;
}
if ( ! F_56 ( & V_4 -> V_55 ) )
F_111 ( & V_4 -> V_56 , V_175 + V_176 ) ;
}
static void V_57 ( unsigned long V_10 )
{
struct V_1 * V_4 = (struct V_1 * ) V_10 ;
if ( ! F_112 ( & V_67 ) ) {
F_111 ( & V_4 -> V_56 , V_175 + 1 ) ;
return;
}
if ( ! F_56 ( & V_4 -> V_55 ) )
F_108 ( V_4 ) ;
F_113 ( & V_67 ) ;
}
static void F_114 ( struct V_1 * V_4 , struct V_59 * V_66 ,
unsigned char * V_99 )
{
int V_149 ;
V_66 -> V_94 . V_8 . V_98 = V_180 ;
V_66 -> V_94 . V_8 . V_71 = 0 ;
memset ( V_66 -> V_94 . V_8 . V_99 , 255 , V_180 ) ;
for ( V_149 = 0 ; V_149 < V_4 -> V_71 ; V_149 ++ ) {
if ( F_41 ( V_4 , V_149 ) &&
V_99 [ V_149 ] && V_99 [ V_149 ] < 255 ) {
V_66 -> V_94 . V_8 . V_99 [ V_149 ] = V_99 [ V_149 ] ;
if ( V_66 -> V_94 . V_8 . V_98 > V_149 )
V_66 -> V_94 . V_8 . V_98 = V_149 ;
if ( V_66 -> V_94 . V_8 . V_71 <= V_149 )
V_66 -> V_94 . V_8 . V_71 = V_149 + 1 ;
}
}
}
static int F_115 ( struct V_2 * V_2 , struct V_1 * V_4 ,
struct V_181 * V_182 , int V_183 )
{
int V_149 = V_182 -> V_184 ;
struct V_68 * V_78 = & V_4 -> V_72 [ V_149 ] ;
struct V_105 * V_81 ;
struct V_152 * V_153 ;
int V_12 ;
if ( F_41 ( V_4 , V_149 ) )
return - V_185 ;
switch ( V_182 -> V_186 ) {
#ifdef F_29
case V_159 :
if ( V_4 -> V_58 >= 0 )
return - V_185 ;
V_81 = F_84 ( V_2 , V_4 ) ;
if ( ! V_81 )
return - V_187 ;
V_12 = F_93 ( V_81 , 1 ) ;
if ( V_12 ) {
F_89 ( V_81 ) ;
F_79 ( V_81 ) ;
return V_12 ;
}
break;
#endif
case 0 :
V_81 = F_116 ( V_2 , V_182 -> V_188 ) ;
if ( ! V_81 )
return - V_154 ;
V_12 = F_93 ( V_81 , 1 ) ;
if ( V_12 ) {
F_79 ( V_81 ) ;
return V_12 ;
}
break;
default:
return - V_27 ;
}
V_153 = F_94 ( V_81 ) ;
if ( V_153 ) {
V_153 -> V_156 . V_157 ++ ;
F_95 ( F_63 ( V_81 ) ,
V_158 ,
V_81 -> V_109 , & V_153 -> V_156 ) ;
}
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
if ( V_78 -> V_19 & V_159 )
V_78 -> V_194 = V_81 -> V_147 ;
F_91 ( & V_64 ) ;
V_78 -> V_81 = V_81 ;
#ifdef F_29
if ( V_78 -> V_19 & V_159 )
V_4 -> V_58 = V_149 ;
#endif
if ( V_149 + 1 > V_4 -> V_71 )
V_4 -> V_71 = V_149 + 1 ;
F_92 ( & V_64 ) ;
return 0 ;
}
static struct V_59 * F_117 ( struct V_1 * V_4 ,
const struct V_195 * V_196 ,
const struct V_195 * V_197 )
{
int line = F_118 ( V_197 , V_196 ) ;
struct V_59 * V_160 ;
F_36 (c, &mrt->mfc6_cache_array[line], list) {
if ( F_119 ( & V_160 -> V_92 , V_196 ) &&
F_119 ( & V_160 -> V_91 , V_197 ) )
return V_160 ;
}
return NULL ;
}
static struct V_59 * F_120 ( struct V_1 * V_4 ,
T_6 V_198 )
{
int line = F_118 ( & V_199 , & V_199 ) ;
struct V_59 * V_160 ;
F_36 (c, &mrt->mfc6_cache_array[line], list)
if ( F_121 ( & V_160 -> V_92 ) &&
F_121 ( & V_160 -> V_91 ) &&
( V_160 -> V_94 . V_8 . V_99 [ V_198 ] < 255 ) )
return V_160 ;
return NULL ;
}
static struct V_59 * F_122 ( struct V_1 * V_4 ,
struct V_195 * V_197 ,
T_6 V_198 )
{
int line = F_118 ( V_197 , & V_199 ) ;
struct V_59 * V_160 , * V_200 ;
if ( F_121 ( V_197 ) )
goto V_201;
F_36 (c, &mrt->mfc6_cache_array[line], list)
if ( F_121 ( & V_160 -> V_92 ) &&
F_119 ( & V_160 -> V_91 , V_197 ) ) {
if ( V_160 -> V_94 . V_8 . V_99 [ V_198 ] < 255 )
return V_160 ;
V_200 = F_120 ( V_4 ,
V_160 -> V_93 ) ;
if ( V_200 && V_200 -> V_94 . V_8 . V_99 [ V_198 ] < 255 )
return V_160 ;
}
V_201:
return F_120 ( V_4 , V_198 ) ;
}
static struct V_59 * F_123 ( void )
{
struct V_59 * V_160 = F_124 ( V_161 , V_52 ) ;
if ( V_160 == NULL )
return NULL ;
V_160 -> V_94 . V_8 . V_98 = V_180 ;
return V_160 ;
}
static struct V_59 * F_125 ( void )
{
struct V_59 * V_160 = F_124 ( V_161 , V_202 ) ;
if ( V_160 == NULL )
return NULL ;
F_126 ( & V_160 -> V_94 . V_163 . V_164 ) ;
V_160 -> V_94 . V_163 . V_176 = V_175 + 10 * V_177 ;
return V_160 ;
}
static void F_127 ( struct V_2 * V_2 , struct V_1 * V_4 ,
struct V_59 * V_203 , struct V_59 * V_160 )
{
struct V_31 * V_32 ;
while( ( V_32 = F_128 ( & V_203 -> V_94 . V_163 . V_164 ) ) ) {
if ( F_67 ( V_32 ) -> V_165 == 0 ) {
struct V_166 * V_167 = (struct V_166 * ) F_74 ( V_32 , sizeof( struct V_103 ) ) ;
if ( F_129 ( V_4 , V_32 , V_160 , F_105 ( V_167 ) ) > 0 ) {
V_167 -> V_170 = F_130 ( V_32 ) - ( V_124 * ) V_167 ;
} else {
V_167 -> V_168 = V_169 ;
V_167 -> V_170 = F_103 ( sizeof( struct V_171 ) ) ;
F_104 ( V_32 , V_167 -> V_170 ) ;
( (struct V_171 * ) F_105 ( V_167 ) ) -> error = - V_204 ;
}
F_106 ( V_32 , V_2 , F_107 ( V_32 ) . V_173 ) ;
} else
F_131 ( V_2 , V_4 , V_32 , V_160 ) ;
}
}
static int F_82 ( struct V_1 * V_4 , struct V_31 * V_95 ,
T_6 V_198 , int assert )
{
struct V_31 * V_32 ;
struct V_205 * V_206 ;
int V_207 ;
#ifdef F_29
if ( assert == V_135 )
V_32 = F_132 ( V_95 , - F_133 ( V_95 )
+ sizeof( * V_206 ) ) ;
else
#endif
V_32 = F_134 ( sizeof( struct V_103 ) + sizeof( * V_206 ) , V_202 ) ;
if ( ! V_32 )
return - V_187 ;
V_32 -> V_128 = V_208 ;
#ifdef F_29
if ( assert == V_135 ) {
F_135 ( V_32 , - F_133 ( V_95 ) ) ;
F_135 ( V_32 , sizeof( * V_206 ) ) ;
F_136 ( V_32 ) ;
V_206 = (struct V_205 * ) F_65 ( V_32 ) ;
V_206 -> V_209 = 0 ;
V_206 -> V_210 = V_135 ;
V_206 -> V_211 = V_4 -> V_58 ;
V_206 -> V_212 = 0 ;
V_206 -> V_213 = F_67 ( V_95 ) -> V_117 ;
V_206 -> V_214 = F_67 ( V_95 ) -> V_118 ;
V_32 -> V_128 = V_208 ;
} else
#endif
{
F_137 ( V_32 , sizeof( struct V_103 ) ) ;
F_75 ( V_32 ) ;
F_138 ( V_32 , F_67 ( V_95 ) , sizeof( struct V_103 ) ) ;
F_137 ( V_32 , sizeof( * V_206 ) ) ;
F_136 ( V_32 ) ;
V_206 = (struct V_205 * ) F_65 ( V_32 ) ;
V_206 -> V_209 = 0 ;
V_206 -> V_210 = assert ;
V_206 -> V_211 = V_198 ;
V_206 -> V_212 = 0 ;
V_206 -> V_213 = F_67 ( V_95 ) -> V_117 ;
V_206 -> V_214 = F_67 ( V_95 ) -> V_118 ;
F_139 ( V_32 , F_140 ( F_141 ( V_95 ) ) ) ;
V_32 -> V_128 = V_208 ;
}
if ( V_4 -> V_215 == NULL ) {
F_80 ( V_32 ) ;
return - V_27 ;
}
V_207 = F_142 ( V_4 -> V_215 , V_32 ) ;
if ( V_207 < 0 ) {
F_143 ( L_12 ) ;
F_80 ( V_32 ) ;
}
return V_207 ;
}
static int
F_144 ( struct V_1 * V_4 , T_6 V_198 , struct V_31 * V_32 )
{
bool V_216 = false ;
int V_12 ;
struct V_59 * V_160 ;
F_38 ( & V_67 ) ;
F_36 (c, &mrt->mfc6_unres_queue, list) {
if ( F_119 ( & V_160 -> V_91 , & F_67 ( V_32 ) -> V_118 ) &&
F_119 ( & V_160 -> V_92 , & F_67 ( V_32 ) -> V_117 ) ) {
V_216 = true ;
break;
}
}
if ( ! V_216 ) {
if ( F_145 ( & V_4 -> V_162 ) >= 10 ||
( V_160 = F_125 () ) == NULL ) {
F_39 ( & V_67 ) ;
F_80 ( V_32 ) ;
return - V_187 ;
}
V_160 -> V_93 = - 1 ;
V_160 -> V_92 = F_67 ( V_32 ) -> V_117 ;
V_160 -> V_91 = F_67 ( V_32 ) -> V_118 ;
V_12 = F_82 ( V_4 , V_32 , V_198 , V_217 ) ;
if ( V_12 < 0 ) {
F_39 ( & V_67 ) ;
F_97 ( V_160 ) ;
F_80 ( V_32 ) ;
return V_12 ;
}
F_146 ( & V_4 -> V_162 ) ;
F_147 ( & V_160 -> V_49 , & V_4 -> V_55 ) ;
F_110 ( V_4 , V_160 , V_218 ) ;
F_108 ( V_4 ) ;
}
if ( V_160 -> V_94 . V_163 . V_164 . V_219 > 3 ) {
F_80 ( V_32 ) ;
V_12 = - V_187 ;
} else {
F_148 ( & V_160 -> V_94 . V_163 . V_164 , V_32 ) ;
V_12 = 0 ;
}
F_39 ( & V_67 ) ;
return V_12 ;
}
static int F_149 ( struct V_1 * V_4 , struct V_220 * V_63 ,
int V_221 )
{
int line ;
struct V_59 * V_160 , * V_48 ;
line = F_118 ( & V_63 -> V_222 . V_223 , & V_63 -> V_224 . V_223 ) ;
F_22 (c, next, &mrt->mfc6_cache_array[line], list) {
if ( F_119 ( & V_160 -> V_92 , & V_63 -> V_224 . V_223 ) &&
F_119 ( & V_160 -> V_91 ,
& V_63 -> V_222 . V_223 ) &&
( V_221 == - 1 || V_221 == V_160 -> V_93 ) ) {
F_91 ( & V_64 ) ;
F_23 ( & V_160 -> V_49 ) ;
F_92 ( & V_64 ) ;
F_110 ( V_4 , V_160 , V_179 ) ;
F_97 ( V_160 ) ;
return 0 ;
}
}
return - V_76 ;
}
static int F_150 ( struct V_225 * V_226 ,
unsigned long V_227 , void * V_228 )
{
struct V_105 * V_81 = F_151 ( V_228 ) ;
struct V_2 * V_2 = F_63 ( V_81 ) ;
struct V_1 * V_4 ;
struct V_68 * V_78 ;
int V_65 ;
F_152 ( V_49 ) ;
if ( V_227 != V_229 )
return V_230 ;
F_2 (mrt, net) {
V_78 = & V_4 -> V_72 [ 0 ] ;
for ( V_65 = 0 ; V_65 < V_4 -> V_71 ; V_65 ++ , V_78 ++ ) {
if ( V_78 -> V_81 == V_81 )
F_90 ( V_4 , V_65 , & V_49 ) ;
}
}
F_153 ( & V_49 ) ;
return V_230 ;
}
static int T_2 F_154 ( struct V_2 * V_2 )
{
int V_12 ;
V_12 = F_11 ( V_2 ) ;
if ( V_12 < 0 )
goto V_231;
#ifdef F_155
V_12 = - V_45 ;
if ( ! F_156 ( L_13 , 0 , V_2 -> V_232 , & V_233 ) )
goto V_234;
if ( ! F_156 ( L_14 , 0 , V_2 -> V_232 , & V_235 ) )
goto V_236;
#endif
return 0 ;
#ifdef F_155
V_236:
F_157 ( L_13 , V_2 -> V_232 ) ;
V_234:
F_20 ( V_2 ) ;
#endif
V_231:
return V_12 ;
}
static void T_3 F_158 ( struct V_2 * V_2 )
{
#ifdef F_155
F_157 ( L_14 , V_2 -> V_232 ) ;
F_157 ( L_13 , V_2 -> V_232 ) ;
#endif
F_20 ( V_2 ) ;
}
int T_7 F_159 ( void )
{
int V_12 ;
V_161 = F_160 ( L_15 ,
sizeof( struct V_59 ) ,
0 , V_237 ,
NULL ) ;
if ( ! V_161 )
return - V_45 ;
V_12 = F_161 ( & V_238 ) ;
if ( V_12 )
goto V_239;
V_12 = F_162 ( & V_240 ) ;
if ( V_12 )
goto V_241;
#ifdef F_29
if ( F_163 ( & V_242 , V_119 ) < 0 ) {
F_164 ( L_16 , V_243 ) ;
V_12 = - V_30 ;
goto V_244;
}
#endif
F_165 ( V_245 , V_246 , NULL ,
V_247 , NULL ) ;
return 0 ;
#ifdef F_29
V_244:
F_166 ( & V_240 ) ;
#endif
V_241:
F_167 ( & V_238 ) ;
V_239:
F_168 ( V_161 ) ;
return V_12 ;
}
void F_169 ( void )
{
F_166 ( & V_240 ) ;
F_167 ( & V_238 ) ;
F_168 ( V_161 ) ;
}
static int F_170 ( struct V_2 * V_2 , struct V_1 * V_4 ,
struct V_220 * V_63 , int V_183 , int V_221 )
{
bool V_216 = false ;
int line ;
struct V_59 * V_203 , * V_160 ;
unsigned char V_99 [ V_180 ] ;
int V_51 ;
if ( V_63 -> V_248 >= V_180 )
return - V_249 ;
memset ( V_99 , 255 , V_180 ) ;
for ( V_51 = 0 ; V_51 < V_180 ; V_51 ++ ) {
if ( F_171 ( V_51 , & V_63 -> V_250 ) )
V_99 [ V_51 ] = 1 ;
}
line = F_118 ( & V_63 -> V_222 . V_223 , & V_63 -> V_224 . V_223 ) ;
F_36 (c, &mrt->mfc6_cache_array[line], list) {
if ( F_119 ( & V_160 -> V_92 , & V_63 -> V_224 . V_223 ) &&
F_119 ( & V_160 -> V_91 ,
& V_63 -> V_222 . V_223 ) &&
( V_221 == - 1 || V_221 == V_63 -> V_248 ) ) {
V_216 = true ;
break;
}
}
if ( V_216 ) {
F_91 ( & V_64 ) ;
V_160 -> V_93 = V_63 -> V_248 ;
F_114 ( V_4 , V_160 , V_99 ) ;
if ( ! V_183 )
V_160 -> V_251 |= V_252 ;
F_92 ( & V_64 ) ;
F_110 ( V_4 , V_160 , V_218 ) ;
return 0 ;
}
if ( ! F_121 ( & V_63 -> V_222 . V_223 ) &&
! F_71 ( & V_63 -> V_222 . V_223 ) )
return - V_27 ;
V_160 = F_123 () ;
if ( V_160 == NULL )
return - V_45 ;
V_160 -> V_92 = V_63 -> V_224 . V_223 ;
V_160 -> V_91 = V_63 -> V_222 . V_223 ;
V_160 -> V_93 = V_63 -> V_248 ;
F_114 ( V_4 , V_160 , V_99 ) ;
if ( ! V_183 )
V_160 -> V_251 |= V_252 ;
F_91 ( & V_64 ) ;
F_147 ( & V_160 -> V_49 , & V_4 -> V_54 [ line ] ) ;
F_92 ( & V_64 ) ;
V_216 = false ;
F_38 ( & V_67 ) ;
F_36 (uc, &mrt->mfc6_unres_queue, list) {
if ( F_119 ( & V_203 -> V_92 , & V_160 -> V_92 ) &&
F_119 ( & V_203 -> V_91 , & V_160 -> V_91 ) ) {
F_23 ( & V_203 -> V_49 ) ;
F_101 ( & V_4 -> V_162 ) ;
V_216 = true ;
break;
}
}
if ( F_56 ( & V_4 -> V_55 ) )
F_32 ( & V_4 -> V_56 ) ;
F_39 ( & V_67 ) ;
if ( V_216 ) {
F_127 ( V_2 , V_4 , V_203 , V_160 ) ;
F_97 ( V_203 ) ;
}
F_110 ( V_4 , V_160 , V_218 ) ;
return 0 ;
}
static void F_33 ( struct V_1 * V_4 )
{
int V_51 ;
F_152 ( V_49 ) ;
struct V_59 * V_160 , * V_48 ;
for ( V_51 = 0 ; V_51 < V_4 -> V_71 ; V_51 ++ ) {
if ( ! ( V_4 -> V_72 [ V_51 ] . V_19 & V_191 ) )
F_90 ( V_4 , V_51 , & V_49 ) ;
}
F_153 ( & V_49 ) ;
for ( V_51 = 0 ; V_51 < V_53 ; V_51 ++ ) {
F_22 (c, next, &mrt->mfc6_cache_array[i], list) {
if ( V_160 -> V_251 & V_252 )
continue;
F_91 ( & V_64 ) ;
F_23 ( & V_160 -> V_49 ) ;
F_92 ( & V_64 ) ;
F_110 ( V_4 , V_160 , V_179 ) ;
F_97 ( V_160 ) ;
}
}
if ( F_145 ( & V_4 -> V_162 ) != 0 ) {
F_38 ( & V_67 ) ;
F_22 (c, next, &mrt->mfc6_unres_queue, list) {
F_23 ( & V_160 -> V_49 ) ;
F_110 ( V_4 , V_160 , V_179 ) ;
F_99 ( V_4 , V_160 ) ;
}
F_39 ( & V_67 ) ;
}
}
static int F_172 ( struct V_1 * V_4 , struct V_253 * V_254 )
{
int V_12 = 0 ;
struct V_2 * V_2 = F_173 ( V_254 ) ;
F_21 () ;
F_91 ( & V_64 ) ;
if ( F_174 ( V_4 -> V_215 == NULL ) ) {
V_4 -> V_215 = V_254 ;
V_2 -> V_13 . V_255 -> V_157 ++ ;
F_95 ( V_2 , V_158 ,
V_256 ,
V_2 -> V_13 . V_255 ) ;
}
else
V_12 = - V_185 ;
F_92 ( & V_64 ) ;
F_25 () ;
return V_12 ;
}
int F_175 ( struct V_253 * V_254 )
{
int V_12 = - V_25 ;
struct V_2 * V_2 = F_173 ( V_254 ) ;
struct V_1 * V_4 ;
F_21 () ;
F_2 (mrt, net) {
if ( V_254 == V_4 -> V_215 ) {
F_91 ( & V_64 ) ;
V_4 -> V_215 = NULL ;
V_2 -> V_13 . V_255 -> V_157 -- ;
F_95 ( V_2 ,
V_158 ,
V_256 ,
V_2 -> V_13 . V_255 ) ;
F_92 ( & V_64 ) ;
F_33 ( V_4 ) ;
V_12 = 0 ;
break;
}
}
F_25 () ;
return V_12 ;
}
struct V_253 * F_176 ( struct V_2 * V_2 , struct V_31 * V_32 )
{
struct V_1 * V_4 ;
struct V_5 V_107 = {
. V_108 = V_32 -> V_131 ,
. V_130 = V_32 -> V_81 -> V_109 ,
. V_110 = V_32 -> V_111 ,
} ;
if ( F_3 ( V_2 , & V_107 , & V_4 ) < 0 )
return NULL ;
return V_4 -> V_215 ;
}
int F_177 ( struct V_253 * V_254 , int V_257 , char T_8 * V_258 , unsigned int V_259 )
{
int V_207 , V_221 = 0 ;
struct V_181 V_79 ;
struct V_220 V_63 ;
T_6 V_198 ;
struct V_2 * V_2 = F_173 ( V_254 ) ;
struct V_1 * V_4 ;
V_4 = F_1 ( V_2 , F_178 ( V_254 ) -> V_260 ? : V_44 ) ;
if ( V_4 == NULL )
return - V_76 ;
if ( V_257 != V_261 ) {
if ( V_254 != V_4 -> V_215 && ! F_179 ( V_2 -> V_262 , V_263 ) )
return - V_25 ;
}
switch ( V_257 ) {
case V_261 :
if ( V_254 -> V_264 != V_265 ||
F_180 ( V_254 ) -> V_266 != V_267 )
return - V_268 ;
if ( V_259 < sizeof( int ) )
return - V_27 ;
return F_172 ( V_4 , V_254 ) ;
case V_269 :
return F_175 ( V_254 ) ;
case V_270 :
if ( V_259 < sizeof( V_79 ) )
return - V_27 ;
if ( F_181 ( & V_79 , V_258 , sizeof( V_79 ) ) )
return - V_271 ;
if ( V_79 . V_184 >= V_180 )
return - V_249 ;
F_21 () ;
V_207 = F_115 ( V_2 , V_4 , & V_79 , V_254 == V_4 -> V_215 ) ;
F_25 () ;
return V_207 ;
case V_272 :
if ( V_259 < sizeof( T_6 ) )
return - V_27 ;
if ( F_181 ( & V_198 , V_258 , sizeof( T_6 ) ) )
return - V_271 ;
F_21 () ;
V_207 = F_90 ( V_4 , V_198 , NULL ) ;
F_25 () ;
return V_207 ;
case V_273 :
case V_274 :
V_221 = - 1 ;
case V_275 :
case V_276 :
if ( V_259 < sizeof( V_63 ) )
return - V_27 ;
if ( F_181 ( & V_63 , V_258 , sizeof( V_63 ) ) )
return - V_271 ;
if ( V_221 == 0 )
V_221 = V_63 . V_248 ;
F_21 () ;
if ( V_257 == V_274 || V_257 == V_276 )
V_207 = F_149 ( V_4 , & V_63 , V_221 ) ;
else
V_207 = F_170 ( V_2 , V_4 , & V_63 ,
V_254 == V_4 -> V_215 , V_221 ) ;
F_25 () ;
return V_207 ;
case V_277 :
{
int V_78 ;
if ( V_259 != sizeof( V_78 ) )
return - V_27 ;
if ( F_182 ( V_78 , ( int T_8 * ) V_258 ) )
return - V_271 ;
V_4 -> V_278 = V_78 ;
return 0 ;
}
#ifdef F_29
case V_279 :
{
int V_78 ;
if ( V_259 != sizeof( V_78 ) )
return - V_27 ;
if ( F_182 ( V_78 , ( int T_8 * ) V_258 ) )
return - V_271 ;
V_78 = ! ! V_78 ;
F_21 () ;
V_207 = 0 ;
if ( V_78 != V_4 -> V_280 ) {
V_4 -> V_280 = V_78 ;
V_4 -> V_278 = V_78 ;
}
F_25 () ;
return V_207 ;
}
#endif
#ifdef F_30
case V_281 :
{
T_1 V_78 ;
if ( V_259 != sizeof( T_1 ) )
return - V_27 ;
if ( F_182 ( V_78 , ( T_1 T_8 * ) V_258 ) )
return - V_271 ;
if ( V_78 != V_282 && V_78 >= 100000000 )
return - V_27 ;
if ( V_254 == V_4 -> V_215 )
return - V_283 ;
F_21 () ;
V_207 = 0 ;
if ( ! F_16 ( V_2 , V_78 ) )
V_207 = - V_45 ;
F_178 ( V_254 ) -> V_260 = V_78 ;
F_25 () ;
return V_207 ;
}
#endif
default:
return - V_284 ;
}
}
int F_183 ( struct V_253 * V_254 , int V_257 , char T_8 * V_258 ,
int T_8 * V_259 )
{
int V_285 ;
int V_286 ;
struct V_2 * V_2 = F_173 ( V_254 ) ;
struct V_1 * V_4 ;
V_4 = F_1 ( V_2 , F_178 ( V_254 ) -> V_260 ? : V_44 ) ;
if ( V_4 == NULL )
return - V_76 ;
switch ( V_257 ) {
case V_287 :
V_286 = 0x0305 ;
break;
#ifdef F_29
case V_279 :
V_286 = V_4 -> V_280 ;
break;
#endif
case V_277 :
V_286 = V_4 -> V_278 ;
break;
default:
return - V_284 ;
}
if ( F_182 ( V_285 , V_259 ) )
return - V_271 ;
V_285 = F_184 ( int , V_285 , sizeof( int ) ) ;
if ( V_285 < 0 )
return - V_27 ;
if ( F_185 ( V_285 , V_259 ) )
return - V_271 ;
if ( F_186 ( V_258 , & V_286 , V_285 ) )
return - V_271 ;
return 0 ;
}
int F_187 ( struct V_253 * V_254 , int V_288 , void T_8 * V_10 )
{
struct V_289 V_290 ;
struct V_291 V_292 ;
struct V_68 * V_79 ;
struct V_59 * V_160 ;
struct V_2 * V_2 = F_173 ( V_254 ) ;
struct V_1 * V_4 ;
V_4 = F_1 ( V_2 , F_178 ( V_254 ) -> V_260 ? : V_44 ) ;
if ( V_4 == NULL )
return - V_76 ;
switch ( V_288 ) {
case V_293 :
if ( F_181 ( & V_292 , V_10 , sizeof( V_292 ) ) )
return - V_271 ;
if ( V_292 . V_198 >= V_4 -> V_71 )
return - V_27 ;
F_35 ( & V_64 ) ;
V_79 = & V_4 -> V_72 [ V_292 . V_198 ] ;
if ( F_41 ( V_4 , V_292 . V_198 ) ) {
V_292 . V_294 = V_79 -> V_83 ;
V_292 . V_295 = V_79 -> V_85 ;
V_292 . V_296 = V_79 -> V_82 ;
V_292 . V_297 = V_79 -> V_84 ;
F_37 ( & V_64 ) ;
if ( F_186 ( V_10 , & V_292 , sizeof( V_292 ) ) )
return - V_271 ;
return 0 ;
}
F_37 ( & V_64 ) ;
return - V_154 ;
case V_298 :
if ( F_181 ( & V_290 , V_10 , sizeof( V_290 ) ) )
return - V_271 ;
F_35 ( & V_64 ) ;
V_160 = F_117 ( V_4 , & V_290 . V_299 . V_223 , & V_290 . V_300 . V_223 ) ;
if ( V_160 ) {
V_290 . V_301 = V_160 -> V_94 . V_8 . V_95 ;
V_290 . V_302 = V_160 -> V_94 . V_8 . V_96 ;
V_290 . V_97 = V_160 -> V_94 . V_8 . V_97 ;
F_37 ( & V_64 ) ;
if ( F_186 ( V_10 , & V_290 , sizeof( V_290 ) ) )
return - V_271 ;
return 0 ;
}
F_37 ( & V_64 ) ;
return - V_154 ;
default:
return - V_303 ;
}
}
int F_188 ( struct V_253 * V_254 , unsigned int V_288 , void T_8 * V_10 )
{
struct V_304 V_290 ;
struct V_305 V_292 ;
struct V_68 * V_79 ;
struct V_59 * V_160 ;
struct V_2 * V_2 = F_173 ( V_254 ) ;
struct V_1 * V_4 ;
V_4 = F_1 ( V_2 , F_178 ( V_254 ) -> V_260 ? : V_44 ) ;
if ( V_4 == NULL )
return - V_76 ;
switch ( V_288 ) {
case V_293 :
if ( F_181 ( & V_292 , V_10 , sizeof( V_292 ) ) )
return - V_271 ;
if ( V_292 . V_198 >= V_4 -> V_71 )
return - V_27 ;
F_35 ( & V_64 ) ;
V_79 = & V_4 -> V_72 [ V_292 . V_198 ] ;
if ( F_41 ( V_4 , V_292 . V_198 ) ) {
V_292 . V_294 = V_79 -> V_83 ;
V_292 . V_295 = V_79 -> V_85 ;
V_292 . V_296 = V_79 -> V_82 ;
V_292 . V_297 = V_79 -> V_84 ;
F_37 ( & V_64 ) ;
if ( F_186 ( V_10 , & V_292 , sizeof( V_292 ) ) )
return - V_271 ;
return 0 ;
}
F_37 ( & V_64 ) ;
return - V_154 ;
case V_298 :
if ( F_181 ( & V_290 , V_10 , sizeof( V_290 ) ) )
return - V_271 ;
F_35 ( & V_64 ) ;
V_160 = F_117 ( V_4 , & V_290 . V_299 . V_223 , & V_290 . V_300 . V_223 ) ;
if ( V_160 ) {
V_290 . V_301 = V_160 -> V_94 . V_8 . V_95 ;
V_290 . V_302 = V_160 -> V_94 . V_8 . V_96 ;
V_290 . V_97 = V_160 -> V_94 . V_8 . V_97 ;
F_37 ( & V_64 ) ;
if ( F_186 ( V_10 , & V_290 , sizeof( V_290 ) ) )
return - V_271 ;
return 0 ;
}
F_37 ( & V_64 ) ;
return - V_154 ;
default:
return - V_303 ;
}
}
static inline int F_189 ( struct V_31 * V_32 )
{
F_190 ( F_63 ( F_141 ( V_32 ) -> V_81 ) , F_191 ( F_141 ( V_32 ) ) ,
V_306 ) ;
F_192 ( F_63 ( F_141 ( V_32 ) -> V_81 ) , F_191 ( F_141 ( V_32 ) ) ,
V_307 , V_32 -> V_120 ) ;
return F_193 ( V_32 ) ;
}
static int F_194 ( struct V_2 * V_2 , struct V_1 * V_4 ,
struct V_31 * V_32 , struct V_59 * V_160 , int V_149 )
{
struct V_103 * V_308 ;
struct V_68 * V_79 = & V_4 -> V_72 [ V_149 ] ;
struct V_105 * V_81 ;
struct V_309 * V_310 ;
struct V_5 V_107 ;
if ( V_79 -> V_81 == NULL )
goto V_311;
#ifdef F_29
if ( V_79 -> V_19 & V_159 ) {
V_79 -> V_85 ++ ;
V_79 -> V_84 += V_32 -> V_120 ;
V_79 -> V_81 -> V_132 . V_133 += V_32 -> V_120 ;
V_79 -> V_81 -> V_132 . V_134 ++ ;
F_82 ( V_4 , V_32 , V_149 , V_135 ) ;
goto V_311;
}
#endif
V_308 = F_67 ( V_32 ) ;
V_107 = (struct V_5 ) {
. V_130 = V_79 -> V_194 ,
. V_118 = V_308 -> V_118 ,
} ;
V_310 = F_195 ( V_2 , NULL , & V_107 ) ;
if ( V_310 -> error ) {
F_196 ( V_310 ) ;
goto V_311;
}
F_197 ( V_32 ) ;
F_139 ( V_32 , V_310 ) ;
V_81 = V_79 -> V_81 ;
V_32 -> V_81 = V_81 ;
V_79 -> V_85 ++ ;
V_79 -> V_84 += V_32 -> V_120 ;
if ( F_198 ( V_32 , sizeof( * V_308 ) + F_199 ( V_81 ) ) )
goto V_311;
V_308 = F_67 ( V_32 ) ;
V_308 -> V_312 -- ;
F_200 ( V_32 ) -> V_19 |= V_313 ;
return F_201 ( V_314 , V_315 , V_32 , V_32 -> V_81 , V_81 ,
F_189 ) ;
V_311:
F_80 ( V_32 ) ;
return 0 ;
}
static int F_202 ( struct V_1 * V_4 , struct V_105 * V_81 )
{
int V_65 ;
for ( V_65 = V_4 -> V_71 - 1 ; V_65 >= 0 ; V_65 -- ) {
if ( V_4 -> V_72 [ V_65 ] . V_81 == V_81 )
break;
}
return V_65 ;
}
static void F_131 ( struct V_2 * V_2 , struct V_1 * V_4 ,
struct V_31 * V_32 , struct V_59 * V_66 )
{
int V_316 = - 1 ;
int V_79 , V_65 ;
int V_317 = F_202 ( V_4 , V_32 -> V_81 ) ;
V_79 = V_66 -> V_93 ;
V_66 -> V_94 . V_8 . V_95 ++ ;
V_66 -> V_94 . V_8 . V_96 += V_32 -> V_120 ;
if ( F_121 ( & V_66 -> V_92 ) && V_317 >= 0 ) {
struct V_59 * V_318 ;
V_318 = F_120 ( V_4 , V_79 ) ;
if ( V_318 &&
V_318 -> V_94 . V_8 . V_99 [ V_317 ] < 255 )
goto V_319;
}
if ( V_4 -> V_72 [ V_79 ] . V_81 != V_32 -> V_81 ) {
V_66 -> V_94 . V_8 . V_97 ++ ;
if ( V_317 >= 0 && V_4 -> V_278 &&
( V_4 -> V_280 ||
V_66 -> V_94 . V_8 . V_99 [ V_317 ] < 255 ) &&
F_109 ( V_175 ,
V_66 -> V_94 . V_8 . V_320 + V_321 ) ) {
V_66 -> V_94 . V_8 . V_320 = V_175 ;
F_82 ( V_4 , V_32 , V_317 , V_322 ) ;
}
goto V_323;
}
V_319:
V_4 -> V_72 [ V_79 ] . V_83 ++ ;
V_4 -> V_72 [ V_79 ] . V_82 += V_32 -> V_120 ;
if ( F_121 ( & V_66 -> V_92 ) &&
F_121 ( & V_66 -> V_91 ) ) {
if ( V_317 >= 0 &&
V_317 != V_66 -> V_93 &&
F_67 ( V_32 ) -> V_312 >
V_66 -> V_94 . V_8 . V_99 [ V_66 -> V_93 ] ) {
V_316 = V_66 -> V_93 ;
goto V_324;
}
goto V_323;
}
for ( V_65 = V_66 -> V_94 . V_8 . V_71 - 1 ; V_65 >= V_66 -> V_94 . V_8 . V_98 ; V_65 -- ) {
if ( ( ! F_121 ( & V_66 -> V_92 ) || V_65 != V_317 ) &&
F_67 ( V_32 ) -> V_312 > V_66 -> V_94 . V_8 . V_99 [ V_65 ] ) {
if ( V_316 != - 1 ) {
struct V_31 * V_325 = F_203 ( V_32 , V_202 ) ;
if ( V_325 )
F_194 ( V_2 , V_4 , V_325 , V_66 , V_316 ) ;
}
V_316 = V_65 ;
}
}
V_324:
if ( V_316 != - 1 ) {
F_194 ( V_2 , V_4 , V_32 , V_66 , V_316 ) ;
return;
}
V_323:
F_80 ( V_32 ) ;
}
int F_204 ( struct V_31 * V_32 )
{
struct V_59 * V_66 ;
struct V_2 * V_2 = F_63 ( V_32 -> V_81 ) ;
struct V_1 * V_4 ;
struct V_5 V_107 = {
. V_108 = V_32 -> V_81 -> V_109 ,
. V_110 = V_32 -> V_111 ,
} ;
int V_12 ;
V_12 = F_3 ( V_2 , & V_107 , & V_4 ) ;
if ( V_12 < 0 ) {
F_80 ( V_32 ) ;
return V_12 ;
}
F_35 ( & V_64 ) ;
V_66 = F_117 ( V_4 ,
& F_67 ( V_32 ) -> V_117 , & F_67 ( V_32 ) -> V_118 ) ;
if ( V_66 == NULL ) {
int V_79 = F_202 ( V_4 , V_32 -> V_81 ) ;
if ( V_79 >= 0 )
V_66 = F_122 ( V_4 ,
& F_67 ( V_32 ) -> V_118 ,
V_79 ) ;
}
if ( V_66 == NULL ) {
int V_79 ;
V_79 = F_202 ( V_4 , V_32 -> V_81 ) ;
if ( V_79 >= 0 ) {
int V_12 = F_144 ( V_4 , V_79 , V_32 ) ;
F_37 ( & V_64 ) ;
return V_12 ;
}
F_37 ( & V_64 ) ;
F_80 ( V_32 ) ;
return - V_326 ;
}
F_131 ( V_2 , V_4 , V_32 , V_66 ) ;
F_37 ( & V_64 ) ;
return 0 ;
}
static int F_129 ( struct V_1 * V_4 , struct V_31 * V_32 ,
struct V_59 * V_160 , struct V_327 * V_328 )
{
int V_65 ;
struct V_329 * V_330 ;
struct V_35 * V_331 ;
struct V_332 V_333 ;
if ( V_160 -> V_93 >= V_180 )
return - V_76 ;
if ( F_41 ( V_4 , V_160 -> V_93 ) &&
F_205 ( V_32 , V_334 , V_4 -> V_72 [ V_160 -> V_93 ] . V_81 -> V_109 ) < 0 )
return - V_204 ;
V_331 = F_206 ( V_32 , V_335 ) ;
if ( V_331 == NULL )
return - V_204 ;
for ( V_65 = V_160 -> V_94 . V_8 . V_98 ; V_65 < V_160 -> V_94 . V_8 . V_71 ; V_65 ++ ) {
if ( F_41 ( V_4 , V_65 ) && V_160 -> V_94 . V_8 . V_99 [ V_65 ] < 255 ) {
V_330 = F_207 ( V_32 , sizeof( * V_330 ) ) ;
if ( V_330 == NULL ) {
F_208 ( V_32 , V_331 ) ;
return - V_204 ;
}
V_330 -> V_336 = 0 ;
V_330 -> V_337 = V_160 -> V_94 . V_8 . V_99 [ V_65 ] ;
V_330 -> V_338 = V_4 -> V_72 [ V_65 ] . V_81 -> V_109 ;
V_330 -> V_339 = sizeof( * V_330 ) ;
}
}
F_209 ( V_32 , V_331 ) ;
V_333 . V_340 = V_160 -> V_94 . V_8 . V_95 ;
V_333 . V_341 = V_160 -> V_94 . V_8 . V_96 ;
V_333 . V_342 = V_160 -> V_94 . V_8 . V_97 ;
if ( F_210 ( V_32 , V_343 , sizeof( V_333 ) , & V_333 ) < 0 )
return - V_204 ;
V_328 -> V_344 = V_345 ;
return 1 ;
}
int F_211 ( struct V_2 * V_2 ,
struct V_31 * V_32 , struct V_327 * V_328 , int V_346 )
{
int V_12 ;
struct V_1 * V_4 ;
struct V_59 * V_66 ;
struct V_347 * V_348 = (struct V_347 * ) F_141 ( V_32 ) ;
V_4 = F_1 ( V_2 , V_44 ) ;
if ( V_4 == NULL )
return - V_76 ;
F_35 ( & V_64 ) ;
V_66 = F_117 ( V_4 , & V_348 -> V_349 . V_350 , & V_348 -> V_351 . V_350 ) ;
if ( ! V_66 && V_32 -> V_81 ) {
int V_79 = F_202 ( V_4 , V_32 -> V_81 ) ;
if ( V_79 >= 0 )
V_66 = F_122 ( V_4 , & V_348 -> V_351 . V_350 ,
V_79 ) ;
}
if ( ! V_66 ) {
struct V_31 * V_325 ;
struct V_103 * V_352 ;
struct V_105 * V_81 ;
int V_79 ;
if ( V_346 ) {
F_37 ( & V_64 ) ;
return - V_30 ;
}
V_81 = V_32 -> V_81 ;
if ( V_81 == NULL || ( V_79 = F_202 ( V_4 , V_81 ) ) < 0 ) {
F_37 ( & V_64 ) ;
return - V_326 ;
}
V_325 = F_134 ( sizeof( struct V_103 ) , V_202 ) ;
if ( ! V_325 ) {
F_37 ( & V_64 ) ;
return - V_45 ;
}
F_136 ( V_325 ) ;
F_137 ( V_325 , sizeof( struct V_103 ) ) ;
F_75 ( V_325 ) ;
V_352 = F_67 ( V_325 ) ;
V_352 -> V_165 = 0 ;
V_352 -> V_353 = 0 ;
V_352 -> V_354 [ 0 ] = 0 ;
V_352 -> V_354 [ 1 ] = 0 ;
V_352 -> V_354 [ 2 ] = 0 ;
V_352 -> V_121 = 0 ;
V_352 -> V_355 = V_356 ;
V_352 -> V_312 = 0 ;
V_352 -> V_117 = V_348 -> V_349 . V_350 ;
V_352 -> V_118 = V_348 -> V_351 . V_350 ;
V_12 = F_144 ( V_4 , V_79 , V_325 ) ;
F_37 ( & V_64 ) ;
return V_12 ;
}
if ( ! V_346 && ( V_328 -> V_357 & V_358 ) )
V_66 -> V_251 |= V_359 ;
V_12 = F_129 ( V_4 , V_32 , V_66 , V_328 ) ;
F_37 ( & V_64 ) ;
return V_12 ;
}
static int F_212 ( struct V_1 * V_4 , struct V_31 * V_32 ,
T_1 V_173 , T_1 V_74 , struct V_59 * V_160 , int V_288 )
{
struct V_166 * V_167 ;
struct V_327 * V_328 ;
int V_12 ;
V_167 = F_213 ( V_32 , V_173 , V_74 , V_288 , sizeof( * V_328 ) , V_360 ) ;
if ( V_167 == NULL )
return - V_204 ;
V_328 = F_105 ( V_167 ) ;
V_328 -> V_361 = V_245 ;
V_328 -> V_362 = 128 ;
V_328 -> V_363 = 128 ;
V_328 -> V_364 = 0 ;
V_328 -> V_365 = V_4 -> V_3 ;
if ( F_205 ( V_32 , V_366 , V_4 -> V_3 ) )
goto V_367;
V_328 -> V_344 = V_345 ;
V_328 -> V_368 = V_369 ;
if ( V_160 -> V_251 & V_252 )
V_328 -> V_370 = V_371 ;
else
V_328 -> V_370 = V_372 ;
V_328 -> V_357 = 0 ;
if ( F_210 ( V_32 , V_373 , 16 , & V_160 -> V_92 ) ||
F_210 ( V_32 , V_374 , 16 , & V_160 -> V_91 ) )
goto V_367;
V_12 = F_129 ( V_4 , V_32 , V_160 , V_328 ) ;
if ( V_12 < 0 && V_12 != - V_76 )
goto V_367;
return F_214 ( V_32 , V_167 ) ;
V_367:
F_215 ( V_32 , V_167 ) ;
return - V_204 ;
}
static int F_216 ( bool V_164 , int V_71 )
{
T_9 V_120 =
F_217 ( sizeof( struct V_327 ) )
+ F_218 ( 4 )
+ F_218 ( sizeof( struct V_195 ) )
+ F_218 ( sizeof( struct V_195 ) )
;
if ( ! V_164 )
V_120 = V_120
+ F_218 ( 4 )
+ F_218 ( 0 )
+ V_71 * F_219 ( sizeof( struct V_329 ) )
+ F_218 ( sizeof( struct V_332 ) )
;
return V_120 ;
}
static void F_110 ( struct V_1 * V_4 , struct V_59 * V_63 ,
int V_288 )
{
struct V_2 * V_2 = F_100 ( & V_4 -> V_2 ) ;
struct V_31 * V_32 ;
int V_12 = - V_187 ;
V_32 = F_220 ( F_216 ( V_63 -> V_93 >= V_180 , V_4 -> V_71 ) ,
V_202 ) ;
if ( V_32 == NULL )
goto V_375;
V_12 = F_212 ( V_4 , V_32 , 0 , 0 , V_63 , V_288 ) ;
if ( V_12 < 0 )
goto V_375;
F_221 ( V_32 , V_2 , 0 , V_376 , NULL , V_202 ) ;
return;
V_375:
F_80 ( V_32 ) ;
if ( V_12 < 0 )
F_222 ( V_2 , V_376 , V_12 ) ;
}
static int V_247 ( struct V_31 * V_32 , struct V_377 * V_378 )
{
struct V_2 * V_2 = F_173 ( V_32 -> V_254 ) ;
struct V_1 * V_4 ;
struct V_59 * V_63 ;
unsigned int V_379 = 0 , V_380 ;
unsigned int V_381 = 0 , V_382 ;
unsigned int V_383 = 0 , V_384 ;
V_380 = V_378 -> args [ 0 ] ;
V_382 = V_378 -> args [ 1 ] ;
V_384 = V_378 -> args [ 2 ] ;
F_35 ( & V_64 ) ;
F_2 (mrt, net) {
if ( V_379 < V_380 )
goto V_385;
if ( V_379 > V_380 )
V_382 = 0 ;
for ( V_381 = V_382 ; V_381 < V_53 ; V_381 ++ ) {
F_36 (mfc, &mrt->mfc6_cache_array[h], list) {
if ( V_383 < V_384 )
goto V_386;
if ( F_212 ( V_4 , V_32 ,
F_107 ( V_378 -> V_32 ) . V_173 ,
V_378 -> V_167 -> V_387 ,
V_63 , V_218 ) < 0 )
goto V_388;
V_386:
V_383 ++ ;
}
V_383 = V_384 = 0 ;
}
F_38 ( & V_67 ) ;
F_36 (mfc, &mrt->mfc6_unres_queue, list) {
if ( V_383 < V_384 )
goto V_389;
if ( F_212 ( V_4 , V_32 ,
F_107 ( V_378 -> V_32 ) . V_173 ,
V_378 -> V_167 -> V_387 ,
V_63 , V_218 ) < 0 ) {
F_39 ( & V_67 ) ;
goto V_388;
}
V_389:
V_383 ++ ;
}
F_39 ( & V_67 ) ;
V_383 = V_384 = 0 ;
V_382 = 0 ;
V_385:
V_379 ++ ;
}
V_388:
F_37 ( & V_64 ) ;
V_378 -> args [ 2 ] = V_383 ;
V_378 -> args [ 1 ] = V_381 ;
V_378 -> args [ 0 ] = V_379 ;
return V_32 -> V_120 ;
}
