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
int V_7 ;
struct V_8 V_9 ;
struct V_10 V_11 = {
. V_12 = & V_9 ,
. V_13 = V_14 ,
} ;
V_7 = F_4 ( V_2 -> V_15 . V_16 ,
F_5 ( V_6 ) , 0 , & V_11 ) ;
if ( V_7 < 0 )
return V_7 ;
* V_4 = V_9 . V_4 ;
return 0 ;
}
static int F_6 ( struct V_17 * V_18 , struct V_19 * V_20 ,
int V_13 , struct V_10 * V_11 )
{
struct V_8 * V_9 = V_11 -> V_12 ;
struct V_1 * V_4 ;
switch ( V_18 -> V_21 ) {
case V_22 :
break;
case V_23 :
return - V_24 ;
case V_25 :
return - V_26 ;
case V_27 :
default:
return - V_28 ;
}
V_4 = F_1 ( V_18 -> V_29 , V_18 -> V_30 ) ;
if ( V_4 == NULL )
return - V_31 ;
V_9 -> V_4 = V_4 ;
return 0 ;
}
static int F_7 ( struct V_17 * V_18 , struct V_19 * V_20 , int V_13 )
{
return 1 ;
}
static int F_8 ( struct V_17 * V_18 , struct V_32 * V_33 ,
struct V_34 * V_35 , struct V_36 * * V_37 )
{
return 0 ;
}
static int F_9 ( struct V_17 * V_18 , struct V_34 * V_35 ,
struct V_36 * * V_37 )
{
return 1 ;
}
static int F_10 ( struct V_17 * V_18 , struct V_32 * V_33 ,
struct V_34 * V_35 )
{
V_35 -> V_38 = 0 ;
V_35 -> V_39 = 0 ;
V_35 -> V_40 = 0 ;
return 0 ;
}
static int T_2 F_11 ( struct V_2 * V_2 )
{
struct V_41 * V_42 ;
struct V_1 * V_4 ;
int V_7 ;
V_42 = F_12 ( & V_43 , V_2 ) ;
if ( F_13 ( V_42 ) )
return F_14 ( V_42 ) ;
F_15 ( & V_2 -> V_15 . V_44 ) ;
V_4 = F_16 ( V_2 , V_45 ) ;
if ( V_4 == NULL ) {
V_7 = - V_46 ;
goto V_47;
}
V_7 = F_17 ( V_42 , 0x7fff , V_45 , 0 ) ;
if ( V_7 < 0 )
goto V_48;
V_2 -> V_15 . V_16 = V_42 ;
return 0 ;
V_48:
F_18 ( V_4 ) ;
V_47:
F_19 ( V_42 ) ;
return V_7 ;
}
static void T_3 F_20 ( struct V_2 * V_2 )
{
struct V_1 * V_4 , * V_49 ;
F_21 () ;
F_22 (mrt, next, &net->ipv6.mr6_tables, list) {
F_23 ( & V_4 -> V_50 ) ;
F_24 ( V_4 ) ;
}
F_25 () ;
F_19 ( V_2 -> V_15 . V_16 ) ;
}
static struct V_1 * F_1 ( struct V_2 * V_2 , T_1 V_3 )
{
return V_2 -> V_15 . V_51 ;
}
static int F_3 ( struct V_2 * V_2 , struct V_5 * V_6 ,
struct V_1 * * V_4 )
{
* V_4 = V_2 -> V_15 . V_51 ;
return 0 ;
}
static int T_2 F_11 ( struct V_2 * V_2 )
{
V_2 -> V_15 . V_51 = F_16 ( V_2 , V_45 ) ;
return V_2 -> V_15 . V_51 ? 0 : - V_46 ;
}
static void T_3 F_20 ( struct V_2 * V_2 )
{
F_21 () ;
F_24 ( V_2 -> V_15 . V_51 ) ;
V_2 -> V_15 . V_51 = NULL ;
F_25 () ;
}
static struct V_1 * F_16 ( struct V_2 * V_2 , T_1 V_3 )
{
struct V_1 * V_4 ;
unsigned int V_52 ;
V_4 = F_1 ( V_2 , V_3 ) ;
if ( V_4 != NULL )
return V_4 ;
V_4 = F_26 ( sizeof( * V_4 ) , V_53 ) ;
if ( V_4 == NULL )
return NULL ;
V_4 -> V_3 = V_3 ;
F_27 ( & V_4 -> V_2 , V_2 ) ;
for ( V_52 = 0 ; V_52 < V_54 ; V_52 ++ )
F_15 ( & V_4 -> V_55 [ V_52 ] ) ;
F_15 ( & V_4 -> V_56 ) ;
F_28 ( & V_4 -> V_57 , V_58 ,
( unsigned long ) V_4 ) ;
#ifdef F_29
V_4 -> V_59 = - 1 ;
#endif
#ifdef F_30
F_31 ( & V_4 -> V_50 , & V_2 -> V_15 . V_44 ) ;
#endif
return V_4 ;
}
static void F_24 ( struct V_1 * V_4 )
{
F_32 ( & V_4 -> V_57 ) ;
F_33 ( V_4 ) ;
F_18 ( V_4 ) ;
}
static struct V_60 * F_34 ( struct V_2 * V_2 ,
struct V_61 * V_62 , T_4 V_63 )
{
struct V_1 * V_4 = V_62 -> V_4 ;
struct V_60 * V_64 ;
F_35 ( & V_65 ) ;
for ( V_62 -> V_66 = 0 ; V_62 -> V_66 < V_54 ; V_62 -> V_66 ++ ) {
V_62 -> V_67 = & V_4 -> V_55 [ V_62 -> V_66 ] ;
F_36 (mfc, it->cache, list)
if ( V_63 -- == 0 )
return V_64 ;
}
F_37 ( & V_65 ) ;
F_38 ( & V_68 ) ;
V_62 -> V_67 = & V_4 -> V_56 ;
F_36 (mfc, it->cache, list)
if ( V_63 -- == 0 )
return V_64 ;
F_39 ( & V_68 ) ;
V_62 -> V_67 = NULL ;
return NULL ;
}
static struct V_69 * F_40 ( struct V_2 * V_2 ,
struct V_70 * V_71 ,
T_4 V_63 )
{
struct V_1 * V_4 = V_71 -> V_4 ;
for ( V_71 -> V_66 = 0 ; V_71 -> V_66 < V_4 -> V_72 ; ++ V_71 -> V_66 ) {
if ( ! F_41 ( V_4 , V_71 -> V_66 ) )
continue;
if ( V_63 -- == 0 )
return & V_4 -> V_73 [ V_71 -> V_66 ] ;
}
return NULL ;
}
static void * F_42 ( struct V_74 * V_75 , T_4 * V_63 )
__acquires( V_65 )
{
struct V_70 * V_71 = V_75 -> V_76 ;
struct V_2 * V_2 = F_43 ( V_75 ) ;
struct V_1 * V_4 ;
V_4 = F_1 ( V_2 , V_45 ) ;
if ( V_4 == NULL )
return F_44 ( - V_77 ) ;
V_71 -> V_4 = V_4 ;
F_35 ( & V_65 ) ;
return * V_63 ? F_40 ( V_2 , V_75 -> V_76 , * V_63 - 1 )
: V_78 ;
}
static void * F_45 ( struct V_74 * V_75 , void * V_79 , T_4 * V_63 )
{
struct V_70 * V_71 = V_75 -> V_76 ;
struct V_2 * V_2 = F_43 ( V_75 ) ;
struct V_1 * V_4 = V_71 -> V_4 ;
++ * V_63 ;
if ( V_79 == V_78 )
return F_40 ( V_2 , V_71 , 0 ) ;
while ( ++ V_71 -> V_66 < V_4 -> V_72 ) {
if ( ! F_41 ( V_4 , V_71 -> V_66 ) )
continue;
return & V_4 -> V_73 [ V_71 -> V_66 ] ;
}
return NULL ;
}
static void F_46 ( struct V_74 * V_75 , void * V_79 )
__releases( V_65 )
{
F_37 ( & V_65 ) ;
}
static int F_47 ( struct V_74 * V_75 , void * V_79 )
{
struct V_70 * V_71 = V_75 -> V_76 ;
struct V_1 * V_4 = V_71 -> V_4 ;
if ( V_79 == V_78 ) {
F_48 ( V_75 ,
L_1 ) ;
} else {
const struct V_69 * V_80 = V_79 ;
const char * V_81 = V_80 -> V_82 ? V_80 -> V_82 -> V_81 : L_2 ;
F_49 ( V_75 ,
L_3 ,
V_80 - V_4 -> V_73 ,
V_81 , V_80 -> V_83 , V_80 -> V_84 ,
V_80 -> V_85 , V_80 -> V_86 ,
V_80 -> V_13 ) ;
}
return 0 ;
}
static int F_50 ( struct V_87 * V_87 , struct V_88 * V_88 )
{
return F_51 ( V_87 , V_88 , & V_89 ,
sizeof( struct V_70 ) ) ;
}
static void * F_52 ( struct V_74 * V_75 , T_4 * V_63 )
{
struct V_61 * V_62 = V_75 -> V_76 ;
struct V_2 * V_2 = F_43 ( V_75 ) ;
struct V_1 * V_4 ;
V_4 = F_1 ( V_2 , V_45 ) ;
if ( V_4 == NULL )
return F_44 ( - V_77 ) ;
V_62 -> V_4 = V_4 ;
return * V_63 ? F_34 ( V_2 , V_75 -> V_76 , * V_63 - 1 )
: V_78 ;
}
static void * F_53 ( struct V_74 * V_75 , void * V_79 , T_4 * V_63 )
{
struct V_60 * V_64 = V_79 ;
struct V_61 * V_62 = V_75 -> V_76 ;
struct V_2 * V_2 = F_43 ( V_75 ) ;
struct V_1 * V_4 = V_62 -> V_4 ;
++ * V_63 ;
if ( V_79 == V_78 )
return F_34 ( V_2 , V_75 -> V_76 , 0 ) ;
if ( V_64 -> V_50 . V_49 != V_62 -> V_67 )
return F_54 ( V_64 -> V_50 . V_49 , struct V_60 , V_50 ) ;
if ( V_62 -> V_67 == & V_4 -> V_56 )
goto V_90;
F_55 ( V_62 -> V_67 != & V_4 -> V_55 [ V_62 -> V_66 ] ) ;
while ( ++ V_62 -> V_66 < V_54 ) {
V_62 -> V_67 = & V_4 -> V_55 [ V_62 -> V_66 ] ;
if ( F_56 ( V_62 -> V_67 ) )
continue;
return F_57 ( V_62 -> V_67 , struct V_60 , V_50 ) ;
}
F_37 ( & V_65 ) ;
V_62 -> V_67 = & V_4 -> V_56 ;
V_62 -> V_66 = 0 ;
F_38 ( & V_68 ) ;
if ( ! F_56 ( V_62 -> V_67 ) )
return F_57 ( V_62 -> V_67 , struct V_60 , V_50 ) ;
V_90:
F_39 ( & V_68 ) ;
V_62 -> V_67 = NULL ;
return NULL ;
}
static void F_58 ( struct V_74 * V_75 , void * V_79 )
{
struct V_61 * V_62 = V_75 -> V_76 ;
struct V_1 * V_4 = V_62 -> V_4 ;
if ( V_62 -> V_67 == & V_4 -> V_56 )
F_39 ( & V_68 ) ;
else if ( V_62 -> V_67 == V_4 -> V_55 )
F_37 ( & V_65 ) ;
}
static int F_59 ( struct V_74 * V_75 , void * V_79 )
{
int V_91 ;
if ( V_79 == V_78 ) {
F_48 ( V_75 ,
L_4
L_5
L_6 ) ;
} else {
const struct V_60 * V_64 = V_79 ;
const struct V_61 * V_62 = V_75 -> V_76 ;
struct V_1 * V_4 = V_62 -> V_4 ;
F_49 ( V_75 , L_7 ,
& V_64 -> V_92 , & V_64 -> V_93 ,
V_64 -> V_94 ) ;
if ( V_62 -> V_67 != & V_4 -> V_56 ) {
F_49 ( V_75 , L_8 ,
V_64 -> V_95 . V_9 . V_96 ,
V_64 -> V_95 . V_9 . V_97 ,
V_64 -> V_95 . V_9 . V_98 ) ;
for ( V_91 = V_64 -> V_95 . V_9 . V_99 ;
V_91 < V_64 -> V_95 . V_9 . V_72 ; V_91 ++ ) {
if ( F_41 ( V_4 , V_91 ) &&
V_64 -> V_95 . V_9 . V_100 [ V_91 ] < 255 )
F_49 ( V_75 ,
L_9 ,
V_91 , V_64 -> V_95 . V_9 . V_100 [ V_91 ] ) ;
}
} else {
F_49 ( V_75 , L_8 , 0ul , 0ul , 0ul ) ;
}
F_60 ( V_75 , '\n' ) ;
}
return 0 ;
}
static int F_61 ( struct V_87 * V_87 , struct V_88 * V_88 )
{
return F_51 ( V_87 , V_88 , & V_101 ,
sizeof( struct V_61 ) ) ;
}
static int F_62 ( struct V_32 * V_33 )
{
struct V_102 * V_103 ;
struct V_104 * V_105 ;
struct V_106 * V_107 = NULL ;
struct V_2 * V_2 = F_63 ( V_33 -> V_82 ) ;
struct V_1 * V_4 ;
struct V_5 V_108 = {
. V_109 = V_33 -> V_82 -> V_110 ,
. V_111 = V_33 -> V_112 ,
} ;
int V_113 ;
if ( ! F_64 ( V_33 , sizeof( * V_103 ) + sizeof( * V_105 ) ) )
goto V_114;
V_103 = (struct V_102 * ) F_65 ( V_33 ) ;
if ( V_103 -> type != ( ( V_115 << 4 ) | V_116 ) ||
( V_103 -> V_13 & V_117 ) ||
( F_66 ( & F_67 ( V_33 ) -> V_118 , & F_67 ( V_33 ) -> V_119 ,
sizeof( * V_103 ) , V_120 ,
F_68 ( ( void * ) V_103 , sizeof( * V_103 ) , 0 ) ) &&
F_69 ( F_70 ( V_33 , 0 , V_33 -> V_121 , 0 ) ) ) )
goto V_114;
V_105 = (struct V_104 * ) ( F_65 ( V_33 ) +
sizeof( * V_103 ) ) ;
if ( ! F_71 ( & V_105 -> V_119 ) ||
V_105 -> V_122 == 0 ||
F_72 ( V_105 -> V_122 ) + sizeof( * V_103 ) > V_33 -> V_121 )
goto V_114;
if ( F_3 ( V_2 , & V_108 , & V_4 ) < 0 )
goto V_114;
V_113 = V_4 -> V_59 ;
F_35 ( & V_65 ) ;
if ( V_113 >= 0 )
V_107 = V_4 -> V_73 [ V_113 ] . V_82 ;
if ( V_107 )
F_73 ( V_107 ) ;
F_37 ( & V_65 ) ;
if ( V_107 == NULL )
goto V_114;
V_33 -> V_123 = V_33 -> V_124 ;
F_74 ( V_33 , ( V_125 * ) V_105 - V_33 -> V_126 ) ;
F_75 ( V_33 ) ;
V_33 -> V_127 = F_76 ( V_128 ) ;
V_33 -> V_129 = V_130 ;
F_77 ( V_33 , V_107 , F_63 ( V_107 ) ) ;
F_78 ( V_33 ) ;
F_79 ( V_107 ) ;
return 0 ;
V_114:
F_80 ( V_33 ) ;
return 0 ;
}
static T_5 F_81 ( struct V_32 * V_33 ,
struct V_106 * V_82 )
{
struct V_2 * V_2 = F_63 ( V_82 ) ;
struct V_1 * V_4 ;
struct V_5 V_108 = {
. V_131 = V_82 -> V_110 ,
. V_109 = V_33 -> V_132 ? : V_133 ,
. V_111 = V_33 -> V_112 ,
} ;
int V_7 ;
V_7 = F_3 ( V_2 , & V_108 , & V_4 ) ;
if ( V_7 < 0 ) {
F_80 ( V_33 ) ;
return V_7 ;
}
F_35 ( & V_65 ) ;
V_82 -> V_134 . V_135 += V_33 -> V_121 ;
V_82 -> V_134 . V_136 ++ ;
F_82 ( V_4 , V_33 , V_4 -> V_59 , V_137 ) ;
F_37 ( & V_65 ) ;
F_80 ( V_33 ) ;
return V_138 ;
}
static void F_83 ( struct V_106 * V_82 )
{
V_82 -> type = V_139 ;
V_82 -> V_140 = 1500 - sizeof( struct V_104 ) - 8 ;
V_82 -> V_13 = V_141 ;
V_82 -> V_142 = & V_143 ;
V_82 -> V_144 = V_145 ;
V_82 -> V_146 |= V_147 ;
}
static struct V_106 * F_84 ( struct V_2 * V_2 , struct V_1 * V_4 )
{
struct V_106 * V_82 ;
char V_81 [ V_148 ] ;
if ( V_4 -> V_3 == V_45 )
sprintf ( V_81 , L_10 ) ;
else
sprintf ( V_81 , L_11 , V_4 -> V_3 ) ;
V_82 = F_85 ( 0 , V_81 , F_83 ) ;
if ( V_82 == NULL )
return NULL ;
F_86 ( V_82 , V_2 ) ;
if ( F_87 ( V_82 ) ) {
V_145 ( V_82 ) ;
return NULL ;
}
V_82 -> V_149 = 0 ;
if ( F_88 ( V_82 ) )
goto V_150;
F_73 ( V_82 ) ;
return V_82 ;
V_150:
F_25 () ;
F_21 () ;
F_89 ( V_82 ) ;
return NULL ;
}
static int F_90 ( struct V_1 * V_4 , int V_151 , struct V_152 * V_153 )
{
struct V_69 * V_79 ;
struct V_106 * V_82 ;
struct V_154 * V_155 ;
if ( V_151 < 0 || V_151 >= V_4 -> V_72 )
return - V_156 ;
V_79 = & V_4 -> V_73 [ V_151 ] ;
F_91 ( & V_65 ) ;
V_82 = V_79 -> V_82 ;
V_79 -> V_82 = NULL ;
if ( ! V_82 ) {
F_92 ( & V_65 ) ;
return - V_156 ;
}
#ifdef F_29
if ( V_151 == V_4 -> V_59 )
V_4 -> V_59 = - 1 ;
#endif
if ( V_151 + 1 == V_4 -> V_72 ) {
int V_157 ;
for ( V_157 = V_151 - 1 ; V_157 >= 0 ; V_157 -- ) {
if ( F_41 ( V_4 , V_157 ) )
break;
}
V_4 -> V_72 = V_157 + 1 ;
}
F_92 ( & V_65 ) ;
F_93 ( V_82 , - 1 ) ;
V_155 = F_94 ( V_82 ) ;
if ( V_155 ) {
V_155 -> V_158 . V_159 -- ;
F_95 ( F_63 ( V_82 ) ,
V_160 ,
V_82 -> V_110 , & V_155 -> V_158 ) ;
}
if ( V_79 -> V_13 & V_161 )
F_96 ( V_82 , V_153 ) ;
F_79 ( V_82 ) ;
return 0 ;
}
static inline void F_97 ( struct V_60 * V_162 )
{
F_98 ( V_163 , V_162 ) ;
}
static void F_99 ( struct V_1 * V_4 , struct V_60 * V_162 )
{
struct V_2 * V_2 = F_100 ( & V_4 -> V_2 ) ;
struct V_32 * V_33 ;
F_101 ( & V_4 -> V_164 ) ;
while( ( V_33 = F_102 ( & V_162 -> V_95 . V_165 . V_166 ) ) != NULL ) {
if ( F_67 ( V_33 ) -> V_167 == 0 ) {
struct V_168 * V_169 = (struct V_168 * ) F_74 ( V_33 , sizeof( struct V_104 ) ) ;
V_169 -> V_170 = V_171 ;
V_169 -> V_172 = F_103 ( sizeof( struct V_173 ) ) ;
F_104 ( V_33 , V_169 -> V_172 ) ;
( (struct V_173 * ) F_105 ( V_169 ) ) -> error = - V_174 ;
F_106 ( V_33 , V_2 , F_107 ( V_33 ) . V_175 ) ;
} else
F_80 ( V_33 ) ;
}
F_97 ( V_162 ) ;
}
static void F_108 ( struct V_1 * V_4 )
{
unsigned long V_176 = V_177 ;
unsigned long V_178 = 10 * V_179 ;
struct V_60 * V_162 , * V_49 ;
F_22 (c, next, &mrt->mfc6_unres_queue, list) {
if ( F_109 ( V_162 -> V_95 . V_165 . V_178 , V_176 ) ) {
unsigned long V_180 = V_162 -> V_95 . V_165 . V_178 - V_176 ;
if ( V_180 < V_178 )
V_178 = V_180 ;
continue;
}
F_23 ( & V_162 -> V_50 ) ;
F_110 ( V_4 , V_162 , V_181 ) ;
F_99 ( V_4 , V_162 ) ;
}
if ( ! F_56 ( & V_4 -> V_56 ) )
F_111 ( & V_4 -> V_57 , V_177 + V_178 ) ;
}
static void V_58 ( unsigned long V_11 )
{
struct V_1 * V_4 = (struct V_1 * ) V_11 ;
if ( ! F_112 ( & V_68 ) ) {
F_111 ( & V_4 -> V_57 , V_177 + 1 ) ;
return;
}
if ( ! F_56 ( & V_4 -> V_56 ) )
F_108 ( V_4 ) ;
F_113 ( & V_68 ) ;
}
static void F_114 ( struct V_1 * V_4 , struct V_60 * V_67 ,
unsigned char * V_100 )
{
int V_151 ;
V_67 -> V_95 . V_9 . V_99 = V_182 ;
V_67 -> V_95 . V_9 . V_72 = 0 ;
memset ( V_67 -> V_95 . V_9 . V_100 , 255 , V_182 ) ;
for ( V_151 = 0 ; V_151 < V_4 -> V_72 ; V_151 ++ ) {
if ( F_41 ( V_4 , V_151 ) &&
V_100 [ V_151 ] && V_100 [ V_151 ] < 255 ) {
V_67 -> V_95 . V_9 . V_100 [ V_151 ] = V_100 [ V_151 ] ;
if ( V_67 -> V_95 . V_9 . V_99 > V_151 )
V_67 -> V_95 . V_9 . V_99 = V_151 ;
if ( V_67 -> V_95 . V_9 . V_72 <= V_151 )
V_67 -> V_95 . V_9 . V_72 = V_151 + 1 ;
}
}
}
static int F_115 ( struct V_2 * V_2 , struct V_1 * V_4 ,
struct V_183 * V_184 , int V_185 )
{
int V_151 = V_184 -> V_186 ;
struct V_69 * V_79 = & V_4 -> V_73 [ V_151 ] ;
struct V_106 * V_82 ;
struct V_154 * V_155 ;
int V_7 ;
if ( F_41 ( V_4 , V_151 ) )
return - V_187 ;
switch ( V_184 -> V_188 ) {
#ifdef F_29
case V_161 :
if ( V_4 -> V_59 >= 0 )
return - V_187 ;
V_82 = F_84 ( V_2 , V_4 ) ;
if ( ! V_82 )
return - V_189 ;
V_7 = F_93 ( V_82 , 1 ) ;
if ( V_7 ) {
F_89 ( V_82 ) ;
F_79 ( V_82 ) ;
return V_7 ;
}
break;
#endif
case 0 :
V_82 = F_116 ( V_2 , V_184 -> V_190 ) ;
if ( ! V_82 )
return - V_156 ;
V_7 = F_93 ( V_82 , 1 ) ;
if ( V_7 ) {
F_79 ( V_82 ) ;
return V_7 ;
}
break;
default:
return - V_28 ;
}
V_155 = F_94 ( V_82 ) ;
if ( V_155 ) {
V_155 -> V_158 . V_159 ++ ;
F_95 ( F_63 ( V_82 ) ,
V_160 ,
V_82 -> V_110 , & V_155 -> V_158 ) ;
}
V_79 -> V_191 = V_184 -> V_192 ;
V_79 -> V_13 = V_184 -> V_188 ;
if ( ! V_185 )
V_79 -> V_13 |= V_193 ;
V_79 -> V_194 = V_184 -> V_195 ;
V_79 -> V_83 = 0 ;
V_79 -> V_85 = 0 ;
V_79 -> V_84 = 0 ;
V_79 -> V_86 = 0 ;
V_79 -> V_196 = V_82 -> V_110 ;
if ( V_79 -> V_13 & V_161 )
V_79 -> V_196 = V_82 -> V_149 ;
F_91 ( & V_65 ) ;
V_79 -> V_82 = V_82 ;
#ifdef F_29
if ( V_79 -> V_13 & V_161 )
V_4 -> V_59 = V_151 ;
#endif
if ( V_151 + 1 > V_4 -> V_72 )
V_4 -> V_72 = V_151 + 1 ;
F_92 ( & V_65 ) ;
return 0 ;
}
static struct V_60 * F_117 ( struct V_1 * V_4 ,
const struct V_197 * V_198 ,
const struct V_197 * V_199 )
{
int line = F_118 ( V_199 , V_198 ) ;
struct V_60 * V_162 ;
F_36 (c, &mrt->mfc6_cache_array[line], list) {
if ( F_119 ( & V_162 -> V_93 , V_198 ) &&
F_119 ( & V_162 -> V_92 , V_199 ) )
return V_162 ;
}
return NULL ;
}
static struct V_60 * F_120 ( struct V_1 * V_4 ,
T_6 V_200 )
{
int line = F_118 ( & V_201 , & V_201 ) ;
struct V_60 * V_162 ;
F_36 (c, &mrt->mfc6_cache_array[line], list)
if ( F_121 ( & V_162 -> V_93 ) &&
F_121 ( & V_162 -> V_92 ) &&
( V_162 -> V_95 . V_9 . V_100 [ V_200 ] < 255 ) )
return V_162 ;
return NULL ;
}
static struct V_60 * F_122 ( struct V_1 * V_4 ,
struct V_197 * V_199 ,
T_6 V_200 )
{
int line = F_118 ( V_199 , & V_201 ) ;
struct V_60 * V_162 , * V_202 ;
if ( F_121 ( V_199 ) )
goto V_203;
F_36 (c, &mrt->mfc6_cache_array[line], list)
if ( F_121 ( & V_162 -> V_93 ) &&
F_119 ( & V_162 -> V_92 , V_199 ) ) {
if ( V_162 -> V_95 . V_9 . V_100 [ V_200 ] < 255 )
return V_162 ;
V_202 = F_120 ( V_4 ,
V_162 -> V_94 ) ;
if ( V_202 && V_202 -> V_95 . V_9 . V_100 [ V_200 ] < 255 )
return V_162 ;
}
V_203:
return F_120 ( V_4 , V_200 ) ;
}
static struct V_60 * F_123 ( void )
{
struct V_60 * V_162 = F_124 ( V_163 , V_53 ) ;
if ( V_162 == NULL )
return NULL ;
V_162 -> V_95 . V_9 . V_99 = V_182 ;
return V_162 ;
}
static struct V_60 * F_125 ( void )
{
struct V_60 * V_162 = F_124 ( V_163 , V_204 ) ;
if ( V_162 == NULL )
return NULL ;
F_126 ( & V_162 -> V_95 . V_165 . V_166 ) ;
V_162 -> V_95 . V_165 . V_178 = V_177 + 10 * V_179 ;
return V_162 ;
}
static void F_127 ( struct V_2 * V_2 , struct V_1 * V_4 ,
struct V_60 * V_205 , struct V_60 * V_162 )
{
struct V_32 * V_33 ;
while( ( V_33 = F_128 ( & V_205 -> V_95 . V_165 . V_166 ) ) ) {
if ( F_67 ( V_33 ) -> V_167 == 0 ) {
struct V_168 * V_169 = (struct V_168 * ) F_74 ( V_33 , sizeof( struct V_104 ) ) ;
if ( F_129 ( V_4 , V_33 , V_162 , F_105 ( V_169 ) ) > 0 ) {
V_169 -> V_172 = F_130 ( V_33 ) - ( V_125 * ) V_169 ;
} else {
V_169 -> V_170 = V_171 ;
V_169 -> V_172 = F_103 ( sizeof( struct V_173 ) ) ;
F_104 ( V_33 , V_169 -> V_172 ) ;
( (struct V_173 * ) F_105 ( V_169 ) ) -> error = - V_206 ;
}
F_106 ( V_33 , V_2 , F_107 ( V_33 ) . V_175 ) ;
} else
F_131 ( V_2 , V_4 , V_33 , V_162 ) ;
}
}
static int F_82 ( struct V_1 * V_4 , struct V_32 * V_96 ,
T_6 V_200 , int assert )
{
struct V_32 * V_33 ;
struct V_207 * V_208 ;
int V_209 ;
#ifdef F_29
if ( assert == V_137 )
V_33 = F_132 ( V_96 , - F_133 ( V_96 )
+ sizeof( * V_208 ) ) ;
else
#endif
V_33 = F_134 ( sizeof( struct V_104 ) + sizeof( * V_208 ) , V_204 ) ;
if ( ! V_33 )
return - V_189 ;
V_33 -> V_129 = V_210 ;
#ifdef F_29
if ( assert == V_137 ) {
F_135 ( V_33 , - F_133 ( V_96 ) ) ;
F_135 ( V_33 , sizeof( * V_208 ) ) ;
F_136 ( V_33 ) ;
V_208 = (struct V_207 * ) F_65 ( V_33 ) ;
V_208 -> V_211 = 0 ;
V_208 -> V_212 = V_137 ;
V_208 -> V_213 = V_4 -> V_59 ;
V_208 -> V_214 = 0 ;
V_208 -> V_215 = F_67 ( V_96 ) -> V_118 ;
V_208 -> V_216 = F_67 ( V_96 ) -> V_119 ;
V_33 -> V_129 = V_210 ;
} else
#endif
{
F_137 ( V_33 , sizeof( struct V_104 ) ) ;
F_75 ( V_33 ) ;
F_138 ( V_33 , F_67 ( V_96 ) , sizeof( struct V_104 ) ) ;
F_137 ( V_33 , sizeof( * V_208 ) ) ;
F_136 ( V_33 ) ;
V_208 = (struct V_207 * ) F_65 ( V_33 ) ;
V_208 -> V_211 = 0 ;
V_208 -> V_212 = assert ;
V_208 -> V_213 = V_200 ;
V_208 -> V_214 = 0 ;
V_208 -> V_215 = F_67 ( V_96 ) -> V_118 ;
V_208 -> V_216 = F_67 ( V_96 ) -> V_119 ;
F_139 ( V_33 , F_140 ( F_141 ( V_96 ) ) ) ;
V_33 -> V_129 = V_210 ;
}
if ( V_4 -> V_217 == NULL ) {
F_80 ( V_33 ) ;
return - V_28 ;
}
V_209 = F_142 ( V_4 -> V_217 , V_33 ) ;
if ( V_209 < 0 ) {
F_143 ( L_12 ) ;
F_80 ( V_33 ) ;
}
return V_209 ;
}
static int
F_144 ( struct V_1 * V_4 , T_6 V_200 , struct V_32 * V_33 )
{
bool V_218 = false ;
int V_7 ;
struct V_60 * V_162 ;
F_38 ( & V_68 ) ;
F_36 (c, &mrt->mfc6_unres_queue, list) {
if ( F_119 ( & V_162 -> V_92 , & F_67 ( V_33 ) -> V_119 ) &&
F_119 ( & V_162 -> V_93 , & F_67 ( V_33 ) -> V_118 ) ) {
V_218 = true ;
break;
}
}
if ( ! V_218 ) {
if ( F_145 ( & V_4 -> V_164 ) >= 10 ||
( V_162 = F_125 () ) == NULL ) {
F_39 ( & V_68 ) ;
F_80 ( V_33 ) ;
return - V_189 ;
}
V_162 -> V_94 = - 1 ;
V_162 -> V_93 = F_67 ( V_33 ) -> V_118 ;
V_162 -> V_92 = F_67 ( V_33 ) -> V_119 ;
V_7 = F_82 ( V_4 , V_33 , V_200 , V_219 ) ;
if ( V_7 < 0 ) {
F_39 ( & V_68 ) ;
F_97 ( V_162 ) ;
F_80 ( V_33 ) ;
return V_7 ;
}
F_146 ( & V_4 -> V_164 ) ;
F_147 ( & V_162 -> V_50 , & V_4 -> V_56 ) ;
F_110 ( V_4 , V_162 , V_220 ) ;
F_108 ( V_4 ) ;
}
if ( V_162 -> V_95 . V_165 . V_166 . V_221 > 3 ) {
F_80 ( V_33 ) ;
V_7 = - V_189 ;
} else {
F_148 ( & V_162 -> V_95 . V_165 . V_166 , V_33 ) ;
V_7 = 0 ;
}
F_39 ( & V_68 ) ;
return V_7 ;
}
static int F_149 ( struct V_1 * V_4 , struct V_222 * V_64 ,
int V_223 )
{
int line ;
struct V_60 * V_162 , * V_49 ;
line = F_118 ( & V_64 -> V_224 . V_225 , & V_64 -> V_226 . V_225 ) ;
F_22 (c, next, &mrt->mfc6_cache_array[line], list) {
if ( F_119 ( & V_162 -> V_93 , & V_64 -> V_226 . V_225 ) &&
F_119 ( & V_162 -> V_92 ,
& V_64 -> V_224 . V_225 ) &&
( V_223 == - 1 || V_223 == V_162 -> V_94 ) ) {
F_91 ( & V_65 ) ;
F_23 ( & V_162 -> V_50 ) ;
F_92 ( & V_65 ) ;
F_110 ( V_4 , V_162 , V_181 ) ;
F_97 ( V_162 ) ;
return 0 ;
}
}
return - V_77 ;
}
static int F_150 ( struct V_227 * V_228 ,
unsigned long V_229 , void * V_230 )
{
struct V_106 * V_82 = F_151 ( V_230 ) ;
struct V_2 * V_2 = F_63 ( V_82 ) ;
struct V_1 * V_4 ;
struct V_69 * V_79 ;
int V_66 ;
F_152 ( V_50 ) ;
if ( V_229 != V_231 )
return V_232 ;
F_2 (mrt, net) {
V_79 = & V_4 -> V_73 [ 0 ] ;
for ( V_66 = 0 ; V_66 < V_4 -> V_72 ; V_66 ++ , V_79 ++ ) {
if ( V_79 -> V_82 == V_82 )
F_90 ( V_4 , V_66 , & V_50 ) ;
}
}
F_153 ( & V_50 ) ;
return V_232 ;
}
static int T_2 F_154 ( struct V_2 * V_2 )
{
int V_7 ;
V_7 = F_11 ( V_2 ) ;
if ( V_7 < 0 )
goto V_233;
#ifdef F_155
V_7 = - V_46 ;
if ( ! F_156 ( L_13 , 0 , V_2 -> V_234 , & V_235 ) )
goto V_236;
if ( ! F_156 ( L_14 , 0 , V_2 -> V_234 , & V_237 ) )
goto V_238;
#endif
return 0 ;
#ifdef F_155
V_238:
F_157 ( L_13 , V_2 -> V_234 ) ;
V_236:
F_20 ( V_2 ) ;
#endif
V_233:
return V_7 ;
}
static void T_3 F_158 ( struct V_2 * V_2 )
{
#ifdef F_155
F_157 ( L_14 , V_2 -> V_234 ) ;
F_157 ( L_13 , V_2 -> V_234 ) ;
#endif
F_20 ( V_2 ) ;
}
int T_7 F_159 ( void )
{
int V_7 ;
V_163 = F_160 ( L_15 ,
sizeof( struct V_60 ) ,
0 , V_239 ,
NULL ) ;
if ( ! V_163 )
return - V_46 ;
V_7 = F_161 ( & V_240 ) ;
if ( V_7 )
goto V_241;
V_7 = F_162 ( & V_242 ) ;
if ( V_7 )
goto V_243;
#ifdef F_29
if ( F_163 ( & V_244 , V_120 ) < 0 ) {
F_164 ( L_16 , V_245 ) ;
V_7 = - V_31 ;
goto V_246;
}
#endif
F_165 ( V_247 , V_248 , NULL ,
V_249 , NULL ) ;
return 0 ;
#ifdef F_29
V_246:
F_166 ( & V_242 ) ;
#endif
V_243:
F_167 ( & V_240 ) ;
V_241:
F_168 ( V_163 ) ;
return V_7 ;
}
void F_169 ( void )
{
F_166 ( & V_242 ) ;
F_167 ( & V_240 ) ;
F_168 ( V_163 ) ;
}
static int F_170 ( struct V_2 * V_2 , struct V_1 * V_4 ,
struct V_222 * V_64 , int V_185 , int V_223 )
{
bool V_218 = false ;
int line ;
struct V_60 * V_205 , * V_162 ;
unsigned char V_100 [ V_182 ] ;
int V_52 ;
if ( V_64 -> V_250 >= V_182 )
return - V_251 ;
memset ( V_100 , 255 , V_182 ) ;
for ( V_52 = 0 ; V_52 < V_182 ; V_52 ++ ) {
if ( F_171 ( V_52 , & V_64 -> V_252 ) )
V_100 [ V_52 ] = 1 ;
}
line = F_118 ( & V_64 -> V_224 . V_225 , & V_64 -> V_226 . V_225 ) ;
F_36 (c, &mrt->mfc6_cache_array[line], list) {
if ( F_119 ( & V_162 -> V_93 , & V_64 -> V_226 . V_225 ) &&
F_119 ( & V_162 -> V_92 ,
& V_64 -> V_224 . V_225 ) &&
( V_223 == - 1 || V_223 == V_64 -> V_250 ) ) {
V_218 = true ;
break;
}
}
if ( V_218 ) {
F_91 ( & V_65 ) ;
V_162 -> V_94 = V_64 -> V_250 ;
F_114 ( V_4 , V_162 , V_100 ) ;
if ( ! V_185 )
V_162 -> V_253 |= V_254 ;
F_92 ( & V_65 ) ;
F_110 ( V_4 , V_162 , V_220 ) ;
return 0 ;
}
if ( ! F_121 ( & V_64 -> V_224 . V_225 ) &&
! F_71 ( & V_64 -> V_224 . V_225 ) )
return - V_28 ;
V_162 = F_123 () ;
if ( V_162 == NULL )
return - V_46 ;
V_162 -> V_93 = V_64 -> V_226 . V_225 ;
V_162 -> V_92 = V_64 -> V_224 . V_225 ;
V_162 -> V_94 = V_64 -> V_250 ;
F_114 ( V_4 , V_162 , V_100 ) ;
if ( ! V_185 )
V_162 -> V_253 |= V_254 ;
F_91 ( & V_65 ) ;
F_147 ( & V_162 -> V_50 , & V_4 -> V_55 [ line ] ) ;
F_92 ( & V_65 ) ;
V_218 = false ;
F_38 ( & V_68 ) ;
F_36 (uc, &mrt->mfc6_unres_queue, list) {
if ( F_119 ( & V_205 -> V_93 , & V_162 -> V_93 ) &&
F_119 ( & V_205 -> V_92 , & V_162 -> V_92 ) ) {
F_23 ( & V_205 -> V_50 ) ;
F_101 ( & V_4 -> V_164 ) ;
V_218 = true ;
break;
}
}
if ( F_56 ( & V_4 -> V_56 ) )
F_32 ( & V_4 -> V_57 ) ;
F_39 ( & V_68 ) ;
if ( V_218 ) {
F_127 ( V_2 , V_4 , V_205 , V_162 ) ;
F_97 ( V_205 ) ;
}
F_110 ( V_4 , V_162 , V_220 ) ;
return 0 ;
}
static void F_33 ( struct V_1 * V_4 )
{
int V_52 ;
F_152 ( V_50 ) ;
struct V_60 * V_162 , * V_49 ;
for ( V_52 = 0 ; V_52 < V_4 -> V_72 ; V_52 ++ ) {
if ( ! ( V_4 -> V_73 [ V_52 ] . V_13 & V_193 ) )
F_90 ( V_4 , V_52 , & V_50 ) ;
}
F_153 ( & V_50 ) ;
for ( V_52 = 0 ; V_52 < V_54 ; V_52 ++ ) {
F_22 (c, next, &mrt->mfc6_cache_array[i], list) {
if ( V_162 -> V_253 & V_254 )
continue;
F_91 ( & V_65 ) ;
F_23 ( & V_162 -> V_50 ) ;
F_92 ( & V_65 ) ;
F_110 ( V_4 , V_162 , V_181 ) ;
F_97 ( V_162 ) ;
}
}
if ( F_145 ( & V_4 -> V_164 ) != 0 ) {
F_38 ( & V_68 ) ;
F_22 (c, next, &mrt->mfc6_unres_queue, list) {
F_23 ( & V_162 -> V_50 ) ;
F_110 ( V_4 , V_162 , V_181 ) ;
F_99 ( V_4 , V_162 ) ;
}
F_39 ( & V_68 ) ;
}
}
static int F_172 ( struct V_1 * V_4 , struct V_255 * V_256 )
{
int V_7 = 0 ;
struct V_2 * V_2 = F_173 ( V_256 ) ;
F_21 () ;
F_91 ( & V_65 ) ;
if ( F_174 ( V_4 -> V_217 == NULL ) ) {
V_4 -> V_217 = V_256 ;
V_2 -> V_15 . V_257 -> V_159 ++ ;
F_95 ( V_2 , V_160 ,
V_258 ,
V_2 -> V_15 . V_257 ) ;
}
else
V_7 = - V_187 ;
F_92 ( & V_65 ) ;
F_25 () ;
return V_7 ;
}
int F_175 ( struct V_255 * V_256 )
{
int V_7 = - V_26 ;
struct V_2 * V_2 = F_173 ( V_256 ) ;
struct V_1 * V_4 ;
F_21 () ;
F_2 (mrt, net) {
if ( V_256 == V_4 -> V_217 ) {
F_91 ( & V_65 ) ;
V_4 -> V_217 = NULL ;
V_2 -> V_15 . V_257 -> V_159 -- ;
F_95 ( V_2 ,
V_160 ,
V_258 ,
V_2 -> V_15 . V_257 ) ;
F_92 ( & V_65 ) ;
F_33 ( V_4 ) ;
V_7 = 0 ;
break;
}
}
F_25 () ;
return V_7 ;
}
struct V_255 * F_176 ( struct V_2 * V_2 , struct V_32 * V_33 )
{
struct V_1 * V_4 ;
struct V_5 V_108 = {
. V_109 = V_33 -> V_132 ? : V_133 ,
. V_131 = V_33 -> V_82 -> V_110 ,
. V_111 = V_33 -> V_112 ,
} ;
if ( F_3 ( V_2 , & V_108 , & V_4 ) < 0 )
return NULL ;
return V_4 -> V_217 ;
}
int F_177 ( struct V_255 * V_256 , int V_259 , char T_8 * V_260 , unsigned int V_261 )
{
int V_209 , V_223 = 0 ;
struct V_183 V_80 ;
struct V_222 V_64 ;
T_6 V_200 ;
struct V_2 * V_2 = F_173 ( V_256 ) ;
struct V_1 * V_4 ;
V_4 = F_1 ( V_2 , F_178 ( V_256 ) -> V_262 ? : V_45 ) ;
if ( V_4 == NULL )
return - V_77 ;
if ( V_259 != V_263 ) {
if ( V_256 != V_4 -> V_217 && ! F_179 ( V_2 -> V_264 , V_265 ) )
return - V_26 ;
}
switch ( V_259 ) {
case V_263 :
if ( V_256 -> V_266 != V_267 ||
F_180 ( V_256 ) -> V_268 != V_269 )
return - V_270 ;
if ( V_261 < sizeof( int ) )
return - V_28 ;
return F_172 ( V_4 , V_256 ) ;
case V_271 :
return F_175 ( V_256 ) ;
case V_272 :
if ( V_261 < sizeof( V_80 ) )
return - V_28 ;
if ( F_181 ( & V_80 , V_260 , sizeof( V_80 ) ) )
return - V_273 ;
if ( V_80 . V_186 >= V_182 )
return - V_251 ;
F_21 () ;
V_209 = F_115 ( V_2 , V_4 , & V_80 , V_256 == V_4 -> V_217 ) ;
F_25 () ;
return V_209 ;
case V_274 :
if ( V_261 < sizeof( T_6 ) )
return - V_28 ;
if ( F_181 ( & V_200 , V_260 , sizeof( T_6 ) ) )
return - V_273 ;
F_21 () ;
V_209 = F_90 ( V_4 , V_200 , NULL ) ;
F_25 () ;
return V_209 ;
case V_275 :
case V_276 :
V_223 = - 1 ;
case V_277 :
case V_278 :
if ( V_261 < sizeof( V_64 ) )
return - V_28 ;
if ( F_181 ( & V_64 , V_260 , sizeof( V_64 ) ) )
return - V_273 ;
if ( V_223 == 0 )
V_223 = V_64 . V_250 ;
F_21 () ;
if ( V_259 == V_276 || V_259 == V_278 )
V_209 = F_149 ( V_4 , & V_64 , V_223 ) ;
else
V_209 = F_170 ( V_2 , V_4 , & V_64 ,
V_256 == V_4 -> V_217 , V_223 ) ;
F_25 () ;
return V_209 ;
case V_279 :
{
int V_79 ;
if ( V_261 != sizeof( V_79 ) )
return - V_28 ;
if ( F_182 ( V_79 , ( int T_8 * ) V_260 ) )
return - V_273 ;
V_4 -> V_280 = V_79 ;
return 0 ;
}
#ifdef F_29
case V_281 :
{
int V_79 ;
if ( V_261 != sizeof( V_79 ) )
return - V_28 ;
if ( F_182 ( V_79 , ( int T_8 * ) V_260 ) )
return - V_273 ;
V_79 = ! ! V_79 ;
F_21 () ;
V_209 = 0 ;
if ( V_79 != V_4 -> V_282 ) {
V_4 -> V_282 = V_79 ;
V_4 -> V_280 = V_79 ;
}
F_25 () ;
return V_209 ;
}
#endif
#ifdef F_30
case V_283 :
{
T_1 V_79 ;
if ( V_261 != sizeof( T_1 ) )
return - V_28 ;
if ( F_182 ( V_79 , ( T_1 T_8 * ) V_260 ) )
return - V_273 ;
if ( V_79 != V_284 && V_79 >= 100000000 )
return - V_28 ;
if ( V_256 == V_4 -> V_217 )
return - V_285 ;
F_21 () ;
V_209 = 0 ;
if ( ! F_16 ( V_2 , V_79 ) )
V_209 = - V_46 ;
F_178 ( V_256 ) -> V_262 = V_79 ;
F_25 () ;
return V_209 ;
}
#endif
default:
return - V_286 ;
}
}
int F_183 ( struct V_255 * V_256 , int V_259 , char T_8 * V_260 ,
int T_8 * V_261 )
{
int V_287 ;
int V_288 ;
struct V_2 * V_2 = F_173 ( V_256 ) ;
struct V_1 * V_4 ;
V_4 = F_1 ( V_2 , F_178 ( V_256 ) -> V_262 ? : V_45 ) ;
if ( V_4 == NULL )
return - V_77 ;
switch ( V_259 ) {
case V_289 :
V_288 = 0x0305 ;
break;
#ifdef F_29
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
if ( F_182 ( V_287 , V_261 ) )
return - V_273 ;
V_287 = F_184 ( int , V_287 , sizeof( int ) ) ;
if ( V_287 < 0 )
return - V_28 ;
if ( F_185 ( V_287 , V_261 ) )
return - V_273 ;
if ( F_186 ( V_260 , & V_288 , V_287 ) )
return - V_273 ;
return 0 ;
}
int F_187 ( struct V_255 * V_256 , int V_290 , void T_8 * V_11 )
{
struct V_291 V_292 ;
struct V_293 V_294 ;
struct V_69 * V_80 ;
struct V_60 * V_162 ;
struct V_2 * V_2 = F_173 ( V_256 ) ;
struct V_1 * V_4 ;
V_4 = F_1 ( V_2 , F_178 ( V_256 ) -> V_262 ? : V_45 ) ;
if ( V_4 == NULL )
return - V_77 ;
switch ( V_290 ) {
case V_295 :
if ( F_181 ( & V_294 , V_11 , sizeof( V_294 ) ) )
return - V_273 ;
if ( V_294 . V_200 >= V_4 -> V_72 )
return - V_28 ;
F_35 ( & V_65 ) ;
V_80 = & V_4 -> V_73 [ V_294 . V_200 ] ;
if ( F_41 ( V_4 , V_294 . V_200 ) ) {
V_294 . V_296 = V_80 -> V_84 ;
V_294 . V_297 = V_80 -> V_86 ;
V_294 . V_298 = V_80 -> V_83 ;
V_294 . V_299 = V_80 -> V_85 ;
F_37 ( & V_65 ) ;
if ( F_186 ( V_11 , & V_294 , sizeof( V_294 ) ) )
return - V_273 ;
return 0 ;
}
F_37 ( & V_65 ) ;
return - V_156 ;
case V_300 :
if ( F_181 ( & V_292 , V_11 , sizeof( V_292 ) ) )
return - V_273 ;
F_35 ( & V_65 ) ;
V_162 = F_117 ( V_4 , & V_292 . V_301 . V_225 , & V_292 . V_302 . V_225 ) ;
if ( V_162 ) {
V_292 . V_303 = V_162 -> V_95 . V_9 . V_96 ;
V_292 . V_304 = V_162 -> V_95 . V_9 . V_97 ;
V_292 . V_98 = V_162 -> V_95 . V_9 . V_98 ;
F_37 ( & V_65 ) ;
if ( F_186 ( V_11 , & V_292 , sizeof( V_292 ) ) )
return - V_273 ;
return 0 ;
}
F_37 ( & V_65 ) ;
return - V_156 ;
default:
return - V_305 ;
}
}
int F_188 ( struct V_255 * V_256 , unsigned int V_290 , void T_8 * V_11 )
{
struct V_306 V_292 ;
struct V_307 V_294 ;
struct V_69 * V_80 ;
struct V_60 * V_162 ;
struct V_2 * V_2 = F_173 ( V_256 ) ;
struct V_1 * V_4 ;
V_4 = F_1 ( V_2 , F_178 ( V_256 ) -> V_262 ? : V_45 ) ;
if ( V_4 == NULL )
return - V_77 ;
switch ( V_290 ) {
case V_295 :
if ( F_181 ( & V_294 , V_11 , sizeof( V_294 ) ) )
return - V_273 ;
if ( V_294 . V_200 >= V_4 -> V_72 )
return - V_28 ;
F_35 ( & V_65 ) ;
V_80 = & V_4 -> V_73 [ V_294 . V_200 ] ;
if ( F_41 ( V_4 , V_294 . V_200 ) ) {
V_294 . V_296 = V_80 -> V_84 ;
V_294 . V_297 = V_80 -> V_86 ;
V_294 . V_298 = V_80 -> V_83 ;
V_294 . V_299 = V_80 -> V_85 ;
F_37 ( & V_65 ) ;
if ( F_186 ( V_11 , & V_294 , sizeof( V_294 ) ) )
return - V_273 ;
return 0 ;
}
F_37 ( & V_65 ) ;
return - V_156 ;
case V_300 :
if ( F_181 ( & V_292 , V_11 , sizeof( V_292 ) ) )
return - V_273 ;
F_35 ( & V_65 ) ;
V_162 = F_117 ( V_4 , & V_292 . V_301 . V_225 , & V_292 . V_302 . V_225 ) ;
if ( V_162 ) {
V_292 . V_303 = V_162 -> V_95 . V_9 . V_96 ;
V_292 . V_304 = V_162 -> V_95 . V_9 . V_97 ;
V_292 . V_98 = V_162 -> V_95 . V_9 . V_98 ;
F_37 ( & V_65 ) ;
if ( F_186 ( V_11 , & V_292 , sizeof( V_292 ) ) )
return - V_273 ;
return 0 ;
}
F_37 ( & V_65 ) ;
return - V_156 ;
default:
return - V_305 ;
}
}
static inline int F_189 ( struct V_32 * V_33 )
{
F_190 ( F_63 ( F_141 ( V_33 ) -> V_82 ) , F_191 ( F_141 ( V_33 ) ) ,
V_308 ) ;
F_192 ( F_63 ( F_141 ( V_33 ) -> V_82 ) , F_191 ( F_141 ( V_33 ) ) ,
V_309 , V_33 -> V_121 ) ;
return F_193 ( V_33 ) ;
}
static int F_194 ( struct V_2 * V_2 , struct V_1 * V_4 ,
struct V_32 * V_33 , struct V_60 * V_162 , int V_151 )
{
struct V_104 * V_310 ;
struct V_69 * V_80 = & V_4 -> V_73 [ V_151 ] ;
struct V_106 * V_82 ;
struct V_311 * V_312 ;
struct V_5 V_108 ;
if ( V_80 -> V_82 == NULL )
goto V_313;
#ifdef F_29
if ( V_80 -> V_13 & V_161 ) {
V_80 -> V_86 ++ ;
V_80 -> V_85 += V_33 -> V_121 ;
V_80 -> V_82 -> V_134 . V_135 += V_33 -> V_121 ;
V_80 -> V_82 -> V_134 . V_136 ++ ;
F_82 ( V_4 , V_33 , V_151 , V_137 ) ;
goto V_313;
}
#endif
V_310 = F_67 ( V_33 ) ;
V_108 = (struct V_5 ) {
. V_131 = V_80 -> V_196 ,
. V_119 = V_310 -> V_119 ,
} ;
V_312 = F_195 ( V_2 , NULL , & V_108 ) ;
if ( V_312 -> error ) {
F_196 ( V_312 ) ;
goto V_313;
}
F_197 ( V_33 ) ;
F_139 ( V_33 , V_312 ) ;
V_82 = V_80 -> V_82 ;
V_33 -> V_82 = V_82 ;
V_80 -> V_86 ++ ;
V_80 -> V_85 += V_33 -> V_121 ;
if ( F_198 ( V_33 , sizeof( * V_310 ) + F_199 ( V_82 ) ) )
goto V_313;
V_310 = F_67 ( V_33 ) ;
V_310 -> V_314 -- ;
F_200 ( V_33 ) -> V_13 |= V_315 ;
return F_201 ( V_316 , V_317 , V_33 , V_33 -> V_82 , V_82 ,
F_189 ) ;
V_313:
F_80 ( V_33 ) ;
return 0 ;
}
static int F_202 ( struct V_1 * V_4 , struct V_106 * V_82 )
{
int V_66 ;
for ( V_66 = V_4 -> V_72 - 1 ; V_66 >= 0 ; V_66 -- ) {
if ( V_4 -> V_73 [ V_66 ] . V_82 == V_82 )
break;
}
return V_66 ;
}
static void F_131 ( struct V_2 * V_2 , struct V_1 * V_4 ,
struct V_32 * V_33 , struct V_60 * V_67 )
{
int V_318 = - 1 ;
int V_80 , V_66 ;
int V_319 = F_202 ( V_4 , V_33 -> V_82 ) ;
V_80 = V_67 -> V_94 ;
V_67 -> V_95 . V_9 . V_96 ++ ;
V_67 -> V_95 . V_9 . V_97 += V_33 -> V_121 ;
if ( F_121 ( & V_67 -> V_93 ) && V_319 >= 0 ) {
struct V_60 * V_320 ;
V_320 = F_120 ( V_4 , V_80 ) ;
if ( V_320 &&
V_320 -> V_95 . V_9 . V_100 [ V_319 ] < 255 )
goto V_321;
}
if ( V_4 -> V_73 [ V_80 ] . V_82 != V_33 -> V_82 ) {
V_67 -> V_95 . V_9 . V_98 ++ ;
if ( V_319 >= 0 && V_4 -> V_280 &&
( V_4 -> V_282 ||
V_67 -> V_95 . V_9 . V_100 [ V_319 ] < 255 ) &&
F_109 ( V_177 ,
V_67 -> V_95 . V_9 . V_322 + V_323 ) ) {
V_67 -> V_95 . V_9 . V_322 = V_177 ;
F_82 ( V_4 , V_33 , V_319 , V_324 ) ;
}
goto V_325;
}
V_321:
V_4 -> V_73 [ V_80 ] . V_84 ++ ;
V_4 -> V_73 [ V_80 ] . V_83 += V_33 -> V_121 ;
if ( F_121 ( & V_67 -> V_93 ) &&
F_121 ( & V_67 -> V_92 ) ) {
if ( V_319 >= 0 &&
V_319 != V_67 -> V_94 &&
F_67 ( V_33 ) -> V_314 >
V_67 -> V_95 . V_9 . V_100 [ V_67 -> V_94 ] ) {
V_318 = V_67 -> V_94 ;
goto V_326;
}
goto V_325;
}
for ( V_66 = V_67 -> V_95 . V_9 . V_72 - 1 ; V_66 >= V_67 -> V_95 . V_9 . V_99 ; V_66 -- ) {
if ( ( ! F_121 ( & V_67 -> V_93 ) || V_66 != V_319 ) &&
F_67 ( V_33 ) -> V_314 > V_67 -> V_95 . V_9 . V_100 [ V_66 ] ) {
if ( V_318 != - 1 ) {
struct V_32 * V_327 = F_203 ( V_33 , V_204 ) ;
if ( V_327 )
F_194 ( V_2 , V_4 , V_327 , V_67 , V_318 ) ;
}
V_318 = V_66 ;
}
}
V_326:
if ( V_318 != - 1 ) {
F_194 ( V_2 , V_4 , V_33 , V_67 , V_318 ) ;
return;
}
V_325:
F_80 ( V_33 ) ;
}
int F_204 ( struct V_32 * V_33 )
{
struct V_60 * V_67 ;
struct V_2 * V_2 = F_63 ( V_33 -> V_82 ) ;
struct V_1 * V_4 ;
struct V_5 V_108 = {
. V_109 = V_33 -> V_82 -> V_110 ,
. V_111 = V_33 -> V_112 ,
} ;
int V_7 ;
V_7 = F_3 ( V_2 , & V_108 , & V_4 ) ;
if ( V_7 < 0 ) {
F_80 ( V_33 ) ;
return V_7 ;
}
F_35 ( & V_65 ) ;
V_67 = F_117 ( V_4 ,
& F_67 ( V_33 ) -> V_118 , & F_67 ( V_33 ) -> V_119 ) ;
if ( V_67 == NULL ) {
int V_80 = F_202 ( V_4 , V_33 -> V_82 ) ;
if ( V_80 >= 0 )
V_67 = F_122 ( V_4 ,
& F_67 ( V_33 ) -> V_119 ,
V_80 ) ;
}
if ( V_67 == NULL ) {
int V_80 ;
V_80 = F_202 ( V_4 , V_33 -> V_82 ) ;
if ( V_80 >= 0 ) {
int V_7 = F_144 ( V_4 , V_80 , V_33 ) ;
F_37 ( & V_65 ) ;
return V_7 ;
}
F_37 ( & V_65 ) ;
F_80 ( V_33 ) ;
return - V_328 ;
}
F_131 ( V_2 , V_4 , V_33 , V_67 ) ;
F_37 ( & V_65 ) ;
return 0 ;
}
static int F_129 ( struct V_1 * V_4 , struct V_32 * V_33 ,
struct V_60 * V_162 , struct V_329 * V_330 )
{
int V_66 ;
struct V_331 * V_332 ;
struct V_36 * V_333 ;
struct V_334 V_335 ;
if ( V_162 -> V_94 >= V_182 )
return - V_77 ;
if ( F_41 ( V_4 , V_162 -> V_94 ) &&
F_205 ( V_33 , V_336 , V_4 -> V_73 [ V_162 -> V_94 ] . V_82 -> V_110 ) < 0 )
return - V_206 ;
V_333 = F_206 ( V_33 , V_337 ) ;
if ( V_333 == NULL )
return - V_206 ;
for ( V_66 = V_162 -> V_95 . V_9 . V_99 ; V_66 < V_162 -> V_95 . V_9 . V_72 ; V_66 ++ ) {
if ( F_41 ( V_4 , V_66 ) && V_162 -> V_95 . V_9 . V_100 [ V_66 ] < 255 ) {
V_332 = F_207 ( V_33 , sizeof( * V_332 ) ) ;
if ( V_332 == NULL ) {
F_208 ( V_33 , V_333 ) ;
return - V_206 ;
}
V_332 -> V_338 = 0 ;
V_332 -> V_339 = V_162 -> V_95 . V_9 . V_100 [ V_66 ] ;
V_332 -> V_340 = V_4 -> V_73 [ V_66 ] . V_82 -> V_110 ;
V_332 -> V_341 = sizeof( * V_332 ) ;
}
}
F_209 ( V_33 , V_333 ) ;
V_335 . V_342 = V_162 -> V_95 . V_9 . V_96 ;
V_335 . V_343 = V_162 -> V_95 . V_9 . V_97 ;
V_335 . V_344 = V_162 -> V_95 . V_9 . V_98 ;
if ( F_210 ( V_33 , V_345 , sizeof( V_335 ) , & V_335 ) < 0 )
return - V_206 ;
V_330 -> V_346 = V_347 ;
return 1 ;
}
int F_211 ( struct V_2 * V_2 ,
struct V_32 * V_33 , struct V_329 * V_330 , int V_348 )
{
int V_7 ;
struct V_1 * V_4 ;
struct V_60 * V_67 ;
struct V_349 * V_350 = (struct V_349 * ) F_141 ( V_33 ) ;
V_4 = F_1 ( V_2 , V_45 ) ;
if ( V_4 == NULL )
return - V_77 ;
F_35 ( & V_65 ) ;
V_67 = F_117 ( V_4 , & V_350 -> V_351 . V_352 , & V_350 -> V_353 . V_352 ) ;
if ( ! V_67 && V_33 -> V_82 ) {
int V_80 = F_202 ( V_4 , V_33 -> V_82 ) ;
if ( V_80 >= 0 )
V_67 = F_122 ( V_4 , & V_350 -> V_353 . V_352 ,
V_80 ) ;
}
if ( ! V_67 ) {
struct V_32 * V_327 ;
struct V_104 * V_354 ;
struct V_106 * V_82 ;
int V_80 ;
if ( V_348 ) {
F_37 ( & V_65 ) ;
return - V_31 ;
}
V_82 = V_33 -> V_82 ;
if ( V_82 == NULL || ( V_80 = F_202 ( V_4 , V_82 ) ) < 0 ) {
F_37 ( & V_65 ) ;
return - V_328 ;
}
V_327 = F_134 ( sizeof( struct V_104 ) , V_204 ) ;
if ( ! V_327 ) {
F_37 ( & V_65 ) ;
return - V_46 ;
}
F_136 ( V_327 ) ;
F_137 ( V_327 , sizeof( struct V_104 ) ) ;
F_75 ( V_327 ) ;
V_354 = F_67 ( V_327 ) ;
V_354 -> V_167 = 0 ;
V_354 -> V_355 = 0 ;
V_354 -> V_356 [ 0 ] = 0 ;
V_354 -> V_356 [ 1 ] = 0 ;
V_354 -> V_356 [ 2 ] = 0 ;
V_354 -> V_122 = 0 ;
V_354 -> V_357 = V_358 ;
V_354 -> V_314 = 0 ;
V_354 -> V_118 = V_350 -> V_351 . V_352 ;
V_354 -> V_119 = V_350 -> V_353 . V_352 ;
V_7 = F_144 ( V_4 , V_80 , V_327 ) ;
F_37 ( & V_65 ) ;
return V_7 ;
}
if ( ! V_348 && ( V_330 -> V_359 & V_360 ) )
V_67 -> V_253 |= V_361 ;
V_7 = F_129 ( V_4 , V_33 , V_67 , V_330 ) ;
F_37 ( & V_65 ) ;
return V_7 ;
}
static int F_212 ( struct V_1 * V_4 , struct V_32 * V_33 ,
T_1 V_175 , T_1 V_75 , struct V_60 * V_162 , int V_290 ,
int V_13 )
{
struct V_168 * V_169 ;
struct V_329 * V_330 ;
int V_7 ;
V_169 = F_213 ( V_33 , V_175 , V_75 , V_290 , sizeof( * V_330 ) , V_13 ) ;
if ( V_169 == NULL )
return - V_206 ;
V_330 = F_105 ( V_169 ) ;
V_330 -> V_362 = V_247 ;
V_330 -> V_363 = 128 ;
V_330 -> V_364 = 128 ;
V_330 -> V_365 = 0 ;
V_330 -> V_366 = V_4 -> V_3 ;
if ( F_205 ( V_33 , V_367 , V_4 -> V_3 ) )
goto V_368;
V_330 -> V_346 = V_347 ;
V_330 -> V_369 = V_370 ;
if ( V_162 -> V_253 & V_254 )
V_330 -> V_371 = V_372 ;
else
V_330 -> V_371 = V_373 ;
V_330 -> V_359 = 0 ;
if ( F_210 ( V_33 , V_374 , 16 , & V_162 -> V_93 ) ||
F_210 ( V_33 , V_375 , 16 , & V_162 -> V_92 ) )
goto V_368;
V_7 = F_129 ( V_4 , V_33 , V_162 , V_330 ) ;
if ( V_7 < 0 && V_7 != - V_77 )
goto V_368;
return F_214 ( V_33 , V_169 ) ;
V_368:
F_215 ( V_33 , V_169 ) ;
return - V_206 ;
}
static int F_216 ( bool V_166 , int V_72 )
{
T_9 V_121 =
F_217 ( sizeof( struct V_329 ) )
+ F_218 ( 4 )
+ F_218 ( sizeof( struct V_197 ) )
+ F_218 ( sizeof( struct V_197 ) )
;
if ( ! V_166 )
V_121 = V_121
+ F_218 ( 4 )
+ F_218 ( 0 )
+ V_72 * F_219 ( sizeof( struct V_331 ) )
+ F_218 ( sizeof( struct V_334 ) )
;
return V_121 ;
}
static void F_110 ( struct V_1 * V_4 , struct V_60 * V_64 ,
int V_290 )
{
struct V_2 * V_2 = F_100 ( & V_4 -> V_2 ) ;
struct V_32 * V_33 ;
int V_7 = - V_189 ;
V_33 = F_220 ( F_216 ( V_64 -> V_94 >= V_182 , V_4 -> V_72 ) ,
V_204 ) ;
if ( V_33 == NULL )
goto V_376;
V_7 = F_212 ( V_4 , V_33 , 0 , 0 , V_64 , V_290 , 0 ) ;
if ( V_7 < 0 )
goto V_376;
F_221 ( V_33 , V_2 , 0 , V_377 , NULL , V_204 ) ;
return;
V_376:
F_80 ( V_33 ) ;
if ( V_7 < 0 )
F_222 ( V_2 , V_377 , V_7 ) ;
}
static int V_249 ( struct V_32 * V_33 , struct V_378 * V_379 )
{
struct V_2 * V_2 = F_173 ( V_33 -> V_256 ) ;
struct V_1 * V_4 ;
struct V_60 * V_64 ;
unsigned int V_380 = 0 , V_381 ;
unsigned int V_382 = 0 , V_383 ;
unsigned int V_384 = 0 , V_385 ;
V_381 = V_379 -> args [ 0 ] ;
V_383 = V_379 -> args [ 1 ] ;
V_385 = V_379 -> args [ 2 ] ;
F_35 ( & V_65 ) ;
F_2 (mrt, net) {
if ( V_380 < V_381 )
goto V_386;
if ( V_380 > V_381 )
V_383 = 0 ;
for ( V_382 = V_383 ; V_382 < V_54 ; V_382 ++ ) {
F_36 (mfc, &mrt->mfc6_cache_array[h], list) {
if ( V_384 < V_385 )
goto V_387;
if ( F_212 ( V_4 , V_33 ,
F_107 ( V_379 -> V_33 ) . V_175 ,
V_379 -> V_169 -> V_388 ,
V_64 , V_220 ,
V_389 ) < 0 )
goto V_390;
V_387:
V_384 ++ ;
}
V_384 = V_385 = 0 ;
}
F_38 ( & V_68 ) ;
F_36 (mfc, &mrt->mfc6_unres_queue, list) {
if ( V_384 < V_385 )
goto V_391;
if ( F_212 ( V_4 , V_33 ,
F_107 ( V_379 -> V_33 ) . V_175 ,
V_379 -> V_169 -> V_388 ,
V_64 , V_220 ,
V_389 ) < 0 ) {
F_39 ( & V_68 ) ;
goto V_390;
}
V_391:
V_384 ++ ;
}
F_39 ( & V_68 ) ;
V_384 = V_385 = 0 ;
V_383 = 0 ;
V_386:
V_380 ++ ;
}
V_390:
F_37 ( & V_65 ) ;
V_379 -> args [ 2 ] = V_384 ;
V_379 -> args [ 1 ] = V_382 ;
V_379 -> args [ 0 ] = V_380 ;
return V_33 -> V_121 ;
}
