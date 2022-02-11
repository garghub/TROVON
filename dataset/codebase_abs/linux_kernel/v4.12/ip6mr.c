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
if ( ! V_4 )
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
if ( ! V_4 ) {
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
F_18 ( V_4 ) ;
}
F_19 ( V_2 -> V_15 . V_16 ) ;
F_24 () ;
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
F_18 ( V_2 -> V_15 . V_51 ) ;
V_2 -> V_15 . V_51 = NULL ;
F_24 () ;
}
static struct V_1 * F_16 ( struct V_2 * V_2 , T_1 V_3 )
{
struct V_1 * V_4 ;
unsigned int V_52 ;
V_4 = F_1 ( V_2 , V_3 ) ;
if ( V_4 )
return V_4 ;
V_4 = F_25 ( sizeof( * V_4 ) , V_53 ) ;
if ( ! V_4 )
return NULL ;
V_4 -> V_3 = V_3 ;
F_26 ( & V_4 -> V_2 , V_2 ) ;
for ( V_52 = 0 ; V_52 < V_54 ; V_52 ++ )
F_15 ( & V_4 -> V_55 [ V_52 ] ) ;
F_15 ( & V_4 -> V_56 ) ;
F_27 ( & V_4 -> V_57 , V_58 ,
( unsigned long ) V_4 ) ;
#ifdef F_28
V_4 -> V_59 = - 1 ;
#endif
#ifdef F_29
F_30 ( & V_4 -> V_50 , & V_2 -> V_15 . V_44 ) ;
#endif
return V_4 ;
}
static void F_18 ( struct V_1 * V_4 )
{
F_31 ( & V_4 -> V_57 ) ;
F_32 ( V_4 , true ) ;
F_33 ( V_4 ) ;
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
if ( ! V_4 )
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
if ( ! V_4 )
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
else if ( V_62 -> V_67 == & V_4 -> V_55 [ V_62 -> V_66 ] )
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
if ( ! V_107 )
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
static int F_83 ( const struct V_106 * V_82 )
{
return 0 ;
}
static void F_84 ( struct V_106 * V_82 )
{
V_82 -> type = V_139 ;
V_82 -> V_140 = 1500 - sizeof( struct V_104 ) - 8 ;
V_82 -> V_13 = V_141 ;
V_82 -> V_142 = & V_143 ;
V_82 -> V_144 = true ;
V_82 -> V_145 |= V_146 ;
}
static struct V_106 * F_85 ( struct V_2 * V_2 , struct V_1 * V_4 )
{
struct V_106 * V_82 ;
char V_81 [ V_147 ] ;
if ( V_4 -> V_3 == V_45 )
sprintf ( V_81 , L_10 ) ;
else
sprintf ( V_81 , L_11 , V_4 -> V_3 ) ;
V_82 = F_86 ( 0 , V_81 , V_148 , F_84 ) ;
if ( ! V_82 )
return NULL ;
F_87 ( V_82 , V_2 ) ;
if ( F_88 ( V_82 ) ) {
F_89 ( V_82 ) ;
return NULL ;
}
if ( F_90 ( V_82 ) )
goto V_149;
F_73 ( V_82 ) ;
return V_82 ;
V_149:
F_91 ( V_82 ) ;
return NULL ;
}
static int F_92 ( struct V_1 * V_4 , int V_150 , int V_151 ,
struct V_152 * V_153 )
{
struct V_69 * V_79 ;
struct V_106 * V_82 ;
struct V_154 * V_155 ;
if ( V_150 < 0 || V_150 >= V_4 -> V_72 )
return - V_156 ;
V_79 = & V_4 -> V_73 [ V_150 ] ;
F_93 ( & V_65 ) ;
V_82 = V_79 -> V_82 ;
V_79 -> V_82 = NULL ;
if ( ! V_82 ) {
F_94 ( & V_65 ) ;
return - V_156 ;
}
#ifdef F_28
if ( V_150 == V_4 -> V_59 )
V_4 -> V_59 = - 1 ;
#endif
if ( V_150 + 1 == V_4 -> V_72 ) {
int V_157 ;
for ( V_157 = V_150 - 1 ; V_157 >= 0 ; V_157 -- ) {
if ( F_41 ( V_4 , V_157 ) )
break;
}
V_4 -> V_72 = V_157 + 1 ;
}
F_94 ( & V_65 ) ;
F_95 ( V_82 , - 1 ) ;
V_155 = F_96 ( V_82 ) ;
if ( V_155 ) {
V_155 -> V_158 . V_159 -- ;
F_97 ( F_63 ( V_82 ) , V_160 ,
V_161 ,
V_82 -> V_110 , & V_155 -> V_158 ) ;
}
if ( ( V_79 -> V_13 & V_162 ) && ! V_151 )
F_98 ( V_82 , V_153 ) ;
F_79 ( V_82 ) ;
return 0 ;
}
static inline void F_99 ( struct V_60 * V_163 )
{
F_100 ( V_164 , V_163 ) ;
}
static void F_101 ( struct V_1 * V_4 , struct V_60 * V_163 )
{
struct V_2 * V_2 = F_102 ( & V_4 -> V_2 ) ;
struct V_32 * V_33 ;
F_103 ( & V_4 -> V_165 ) ;
while ( ( V_33 = F_104 ( & V_163 -> V_95 . V_166 . V_167 ) ) != NULL ) {
if ( F_67 ( V_33 ) -> V_168 == 0 ) {
struct V_169 * V_170 = (struct V_169 * ) F_74 ( V_33 , sizeof( struct V_104 ) ) ;
V_170 -> V_171 = V_172 ;
V_170 -> V_173 = F_105 ( sizeof( struct V_174 ) ) ;
F_106 ( V_33 , V_170 -> V_173 ) ;
( (struct V_174 * ) F_107 ( V_170 ) ) -> error = - V_175 ;
F_108 ( V_33 , V_2 , F_109 ( V_33 ) . V_176 ) ;
} else
F_80 ( V_33 ) ;
}
F_99 ( V_163 ) ;
}
static void F_110 ( struct V_1 * V_4 )
{
unsigned long V_177 = V_178 ;
unsigned long V_179 = 10 * V_180 ;
struct V_60 * V_163 , * V_49 ;
F_22 (c, next, &mrt->mfc6_unres_queue, list) {
if ( F_111 ( V_163 -> V_95 . V_166 . V_179 , V_177 ) ) {
unsigned long V_181 = V_163 -> V_95 . V_166 . V_179 - V_177 ;
if ( V_181 < V_179 )
V_179 = V_181 ;
continue;
}
F_23 ( & V_163 -> V_50 ) ;
F_112 ( V_4 , V_163 , V_182 ) ;
F_101 ( V_4 , V_163 ) ;
}
if ( ! F_56 ( & V_4 -> V_56 ) )
F_113 ( & V_4 -> V_57 , V_178 + V_179 ) ;
}
static void V_58 ( unsigned long V_11 )
{
struct V_1 * V_4 = (struct V_1 * ) V_11 ;
if ( ! F_114 ( & V_68 ) ) {
F_113 ( & V_4 -> V_57 , V_178 + 1 ) ;
return;
}
if ( ! F_56 ( & V_4 -> V_56 ) )
F_110 ( V_4 ) ;
F_115 ( & V_68 ) ;
}
static void F_116 ( struct V_1 * V_4 , struct V_60 * V_67 ,
unsigned char * V_100 )
{
int V_150 ;
V_67 -> V_95 . V_9 . V_99 = V_183 ;
V_67 -> V_95 . V_9 . V_72 = 0 ;
memset ( V_67 -> V_95 . V_9 . V_100 , 255 , V_183 ) ;
for ( V_150 = 0 ; V_150 < V_4 -> V_72 ; V_150 ++ ) {
if ( F_41 ( V_4 , V_150 ) &&
V_100 [ V_150 ] && V_100 [ V_150 ] < 255 ) {
V_67 -> V_95 . V_9 . V_100 [ V_150 ] = V_100 [ V_150 ] ;
if ( V_67 -> V_95 . V_9 . V_99 > V_150 )
V_67 -> V_95 . V_9 . V_99 = V_150 ;
if ( V_67 -> V_95 . V_9 . V_72 <= V_150 )
V_67 -> V_95 . V_9 . V_72 = V_150 + 1 ;
}
}
V_67 -> V_95 . V_9 . V_184 = V_178 ;
}
static int F_117 ( struct V_2 * V_2 , struct V_1 * V_4 ,
struct V_185 * V_186 , int V_187 )
{
int V_150 = V_186 -> V_188 ;
struct V_69 * V_79 = & V_4 -> V_73 [ V_150 ] ;
struct V_106 * V_82 ;
struct V_154 * V_155 ;
int V_7 ;
if ( F_41 ( V_4 , V_150 ) )
return - V_189 ;
switch ( V_186 -> V_190 ) {
#ifdef F_28
case V_162 :
if ( V_4 -> V_59 >= 0 )
return - V_189 ;
V_82 = F_85 ( V_2 , V_4 ) ;
if ( ! V_82 )
return - V_191 ;
V_7 = F_95 ( V_82 , 1 ) ;
if ( V_7 ) {
F_91 ( V_82 ) ;
F_79 ( V_82 ) ;
return V_7 ;
}
break;
#endif
case 0 :
V_82 = F_118 ( V_2 , V_186 -> V_192 ) ;
if ( ! V_82 )
return - V_156 ;
V_7 = F_95 ( V_82 , 1 ) ;
if ( V_7 ) {
F_79 ( V_82 ) ;
return V_7 ;
}
break;
default:
return - V_28 ;
}
V_155 = F_96 ( V_82 ) ;
if ( V_155 ) {
V_155 -> V_158 . V_159 ++ ;
F_97 ( F_63 ( V_82 ) , V_160 ,
V_161 ,
V_82 -> V_110 , & V_155 -> V_158 ) ;
}
V_79 -> V_193 = V_186 -> V_194 ;
V_79 -> V_13 = V_186 -> V_190 ;
if ( ! V_187 )
V_79 -> V_13 |= V_195 ;
V_79 -> V_196 = V_186 -> V_197 ;
V_79 -> V_83 = 0 ;
V_79 -> V_85 = 0 ;
V_79 -> V_84 = 0 ;
V_79 -> V_86 = 0 ;
V_79 -> V_198 = V_82 -> V_110 ;
if ( V_79 -> V_13 & V_162 )
V_79 -> V_198 = F_119 ( V_82 ) ;
F_93 ( & V_65 ) ;
V_79 -> V_82 = V_82 ;
#ifdef F_28
if ( V_79 -> V_13 & V_162 )
V_4 -> V_59 = V_150 ;
#endif
if ( V_150 + 1 > V_4 -> V_72 )
V_4 -> V_72 = V_150 + 1 ;
F_94 ( & V_65 ) ;
return 0 ;
}
static struct V_60 * F_120 ( struct V_1 * V_4 ,
const struct V_199 * V_200 ,
const struct V_199 * V_201 )
{
int line = F_121 ( V_201 , V_200 ) ;
struct V_60 * V_163 ;
F_36 (c, &mrt->mfc6_cache_array[line], list) {
if ( F_122 ( & V_163 -> V_93 , V_200 ) &&
F_122 ( & V_163 -> V_92 , V_201 ) )
return V_163 ;
}
return NULL ;
}
static struct V_60 * F_123 ( struct V_1 * V_4 ,
T_6 V_202 )
{
int line = F_121 ( & V_203 , & V_203 ) ;
struct V_60 * V_163 ;
F_36 (c, &mrt->mfc6_cache_array[line], list)
if ( F_124 ( & V_163 -> V_93 ) &&
F_124 ( & V_163 -> V_92 ) &&
( V_163 -> V_95 . V_9 . V_100 [ V_202 ] < 255 ) )
return V_163 ;
return NULL ;
}
static struct V_60 * F_125 ( struct V_1 * V_4 ,
struct V_199 * V_201 ,
T_6 V_202 )
{
int line = F_121 ( V_201 , & V_203 ) ;
struct V_60 * V_163 , * V_204 ;
if ( F_124 ( V_201 ) )
goto V_205;
F_36 (c, &mrt->mfc6_cache_array[line], list)
if ( F_124 ( & V_163 -> V_93 ) &&
F_122 ( & V_163 -> V_92 , V_201 ) ) {
if ( V_163 -> V_95 . V_9 . V_100 [ V_202 ] < 255 )
return V_163 ;
V_204 = F_123 ( V_4 ,
V_163 -> V_94 ) ;
if ( V_204 && V_204 -> V_95 . V_9 . V_100 [ V_202 ] < 255 )
return V_163 ;
}
V_205:
return F_123 ( V_4 , V_202 ) ;
}
static struct V_60 * F_126 ( void )
{
struct V_60 * V_163 = F_127 ( V_164 , V_53 ) ;
if ( ! V_163 )
return NULL ;
V_163 -> V_95 . V_9 . V_206 = V_178 - V_207 - 1 ;
V_163 -> V_95 . V_9 . V_99 = V_183 ;
return V_163 ;
}
static struct V_60 * F_128 ( void )
{
struct V_60 * V_163 = F_127 ( V_164 , V_208 ) ;
if ( ! V_163 )
return NULL ;
F_129 ( & V_163 -> V_95 . V_166 . V_167 ) ;
V_163 -> V_95 . V_166 . V_179 = V_178 + 10 * V_180 ;
return V_163 ;
}
static void F_130 ( struct V_2 * V_2 , struct V_1 * V_4 ,
struct V_60 * V_209 , struct V_60 * V_163 )
{
struct V_32 * V_33 ;
while ( ( V_33 = F_131 ( & V_209 -> V_95 . V_166 . V_167 ) ) ) {
if ( F_67 ( V_33 ) -> V_168 == 0 ) {
struct V_169 * V_170 = (struct V_169 * ) F_74 ( V_33 , sizeof( struct V_104 ) ) ;
if ( F_132 ( V_4 , V_33 , V_163 , F_107 ( V_170 ) ) > 0 ) {
V_170 -> V_173 = F_133 ( V_33 ) - ( V_125 * ) V_170 ;
} else {
V_170 -> V_171 = V_172 ;
V_170 -> V_173 = F_105 ( sizeof( struct V_174 ) ) ;
F_106 ( V_33 , V_170 -> V_173 ) ;
( (struct V_174 * ) F_107 ( V_170 ) ) -> error = - V_210 ;
}
F_108 ( V_33 , V_2 , F_109 ( V_33 ) . V_176 ) ;
} else
F_134 ( V_2 , V_4 , V_33 , V_163 ) ;
}
}
static int F_82 ( struct V_1 * V_4 , struct V_32 * V_96 ,
T_6 V_202 , int assert )
{
struct V_32 * V_33 ;
struct V_211 * V_212 ;
int V_213 ;
#ifdef F_28
if ( assert == V_137 )
V_33 = F_135 ( V_96 , - F_136 ( V_96 )
+ sizeof( * V_212 ) ) ;
else
#endif
V_33 = F_137 ( sizeof( struct V_104 ) + sizeof( * V_212 ) , V_208 ) ;
if ( ! V_33 )
return - V_191 ;
V_33 -> V_129 = V_214 ;
#ifdef F_28
if ( assert == V_137 ) {
F_138 ( V_33 , - F_136 ( V_96 ) ) ;
F_138 ( V_33 , sizeof( * V_212 ) ) ;
F_139 ( V_33 ) ;
V_212 = (struct V_211 * ) F_65 ( V_33 ) ;
V_212 -> V_215 = 0 ;
V_212 -> V_216 = V_137 ;
V_212 -> V_217 = V_4 -> V_59 ;
V_212 -> V_218 = 0 ;
V_212 -> V_219 = F_67 ( V_96 ) -> V_118 ;
V_212 -> V_220 = F_67 ( V_96 ) -> V_119 ;
V_33 -> V_129 = V_214 ;
} else
#endif
{
F_140 ( V_33 , sizeof( struct V_104 ) ) ;
F_75 ( V_33 ) ;
F_141 ( V_33 , F_67 ( V_96 ) , sizeof( struct V_104 ) ) ;
F_140 ( V_33 , sizeof( * V_212 ) ) ;
F_139 ( V_33 ) ;
V_212 = (struct V_211 * ) F_65 ( V_33 ) ;
V_212 -> V_215 = 0 ;
V_212 -> V_216 = assert ;
V_212 -> V_217 = V_202 ;
V_212 -> V_218 = 0 ;
V_212 -> V_219 = F_67 ( V_96 ) -> V_118 ;
V_212 -> V_220 = F_67 ( V_96 ) -> V_119 ;
F_142 ( V_33 , F_143 ( F_144 ( V_96 ) ) ) ;
V_33 -> V_129 = V_214 ;
}
if ( ! V_4 -> V_221 ) {
F_80 ( V_33 ) ;
return - V_28 ;
}
V_213 = F_145 ( V_4 -> V_221 , V_33 ) ;
if ( V_213 < 0 ) {
F_146 ( L_12 ) ;
F_80 ( V_33 ) ;
}
return V_213 ;
}
static int
F_147 ( struct V_1 * V_4 , T_6 V_202 , struct V_32 * V_33 )
{
bool V_222 = false ;
int V_7 ;
struct V_60 * V_163 ;
F_38 ( & V_68 ) ;
F_36 (c, &mrt->mfc6_unres_queue, list) {
if ( F_122 ( & V_163 -> V_92 , & F_67 ( V_33 ) -> V_119 ) &&
F_122 ( & V_163 -> V_93 , & F_67 ( V_33 ) -> V_118 ) ) {
V_222 = true ;
break;
}
}
if ( ! V_222 ) {
if ( F_148 ( & V_4 -> V_165 ) >= 10 ||
( V_163 = F_128 () ) == NULL ) {
F_39 ( & V_68 ) ;
F_80 ( V_33 ) ;
return - V_191 ;
}
V_163 -> V_94 = - 1 ;
V_163 -> V_93 = F_67 ( V_33 ) -> V_118 ;
V_163 -> V_92 = F_67 ( V_33 ) -> V_119 ;
V_7 = F_82 ( V_4 , V_33 , V_202 , V_223 ) ;
if ( V_7 < 0 ) {
F_39 ( & V_68 ) ;
F_99 ( V_163 ) ;
F_80 ( V_33 ) ;
return V_7 ;
}
F_149 ( & V_4 -> V_165 ) ;
F_150 ( & V_163 -> V_50 , & V_4 -> V_56 ) ;
F_112 ( V_4 , V_163 , V_224 ) ;
F_110 ( V_4 ) ;
}
if ( V_163 -> V_95 . V_166 . V_167 . V_225 > 3 ) {
F_80 ( V_33 ) ;
V_7 = - V_191 ;
} else {
F_151 ( & V_163 -> V_95 . V_166 . V_167 , V_33 ) ;
V_7 = 0 ;
}
F_39 ( & V_68 ) ;
return V_7 ;
}
static int F_152 ( struct V_1 * V_4 , struct V_226 * V_64 ,
int V_227 )
{
int line ;
struct V_60 * V_163 , * V_49 ;
line = F_121 ( & V_64 -> V_228 . V_229 , & V_64 -> V_230 . V_229 ) ;
F_22 (c, next, &mrt->mfc6_cache_array[line], list) {
if ( F_122 ( & V_163 -> V_93 , & V_64 -> V_230 . V_229 ) &&
F_122 ( & V_163 -> V_92 ,
& V_64 -> V_228 . V_229 ) &&
( V_227 == - 1 || V_227 == V_163 -> V_94 ) ) {
F_93 ( & V_65 ) ;
F_23 ( & V_163 -> V_50 ) ;
F_94 ( & V_65 ) ;
F_112 ( V_4 , V_163 , V_182 ) ;
F_99 ( V_163 ) ;
return 0 ;
}
}
return - V_77 ;
}
static int F_153 ( struct V_231 * V_232 ,
unsigned long V_233 , void * V_234 )
{
struct V_106 * V_82 = F_154 ( V_234 ) ;
struct V_2 * V_2 = F_63 ( V_82 ) ;
struct V_1 * V_4 ;
struct V_69 * V_79 ;
int V_66 ;
if ( V_233 != V_235 )
return V_236 ;
F_2 (mrt, net) {
V_79 = & V_4 -> V_73 [ 0 ] ;
for ( V_66 = 0 ; V_66 < V_4 -> V_72 ; V_66 ++ , V_79 ++ ) {
if ( V_79 -> V_82 == V_82 )
F_92 ( V_4 , V_66 , 1 , NULL ) ;
}
}
return V_236 ;
}
static int T_2 F_155 ( struct V_2 * V_2 )
{
int V_7 ;
V_7 = F_11 ( V_2 ) ;
if ( V_7 < 0 )
goto V_237;
#ifdef F_156
V_7 = - V_46 ;
if ( ! F_157 ( L_13 , 0 , V_2 -> V_238 , & V_239 ) )
goto V_240;
if ( ! F_157 ( L_14 , 0 , V_2 -> V_238 , & V_241 ) )
goto V_242;
#endif
return 0 ;
#ifdef F_156
V_242:
F_158 ( L_13 , V_2 -> V_238 ) ;
V_240:
F_20 ( V_2 ) ;
#endif
V_237:
return V_7 ;
}
static void T_3 F_159 ( struct V_2 * V_2 )
{
#ifdef F_156
F_158 ( L_14 , V_2 -> V_238 ) ;
F_158 ( L_13 , V_2 -> V_238 ) ;
#endif
F_20 ( V_2 ) ;
}
int T_7 F_160 ( void )
{
int V_7 ;
V_164 = F_161 ( L_15 ,
sizeof( struct V_60 ) ,
0 , V_243 ,
NULL ) ;
if ( ! V_164 )
return - V_46 ;
V_7 = F_162 ( & V_244 ) ;
if ( V_7 )
goto V_245;
V_7 = F_163 ( & V_246 ) ;
if ( V_7 )
goto V_247;
#ifdef F_28
if ( F_164 ( & V_248 , V_120 ) < 0 ) {
F_165 ( L_16 , V_249 ) ;
V_7 = - V_31 ;
goto V_250;
}
#endif
F_166 ( V_251 , V_252 , NULL ,
V_253 , NULL ) ;
return 0 ;
#ifdef F_28
V_250:
F_167 ( & V_246 ) ;
#endif
V_247:
F_168 ( & V_244 ) ;
V_245:
F_169 ( V_164 ) ;
return V_7 ;
}
void F_170 ( void )
{
F_171 ( V_251 , V_252 ) ;
#ifdef F_28
F_172 ( & V_248 , V_120 ) ;
#endif
F_167 ( & V_246 ) ;
F_168 ( & V_244 ) ;
F_169 ( V_164 ) ;
}
static int F_173 ( struct V_2 * V_2 , struct V_1 * V_4 ,
struct V_226 * V_64 , int V_187 , int V_227 )
{
bool V_222 = false ;
int line ;
struct V_60 * V_209 , * V_163 ;
unsigned char V_100 [ V_183 ] ;
int V_52 ;
if ( V_64 -> V_254 >= V_183 )
return - V_255 ;
memset ( V_100 , 255 , V_183 ) ;
for ( V_52 = 0 ; V_52 < V_183 ; V_52 ++ ) {
if ( F_174 ( V_52 , & V_64 -> V_256 ) )
V_100 [ V_52 ] = 1 ;
}
line = F_121 ( & V_64 -> V_228 . V_229 , & V_64 -> V_230 . V_229 ) ;
F_36 (c, &mrt->mfc6_cache_array[line], list) {
if ( F_122 ( & V_163 -> V_93 , & V_64 -> V_230 . V_229 ) &&
F_122 ( & V_163 -> V_92 ,
& V_64 -> V_228 . V_229 ) &&
( V_227 == - 1 || V_227 == V_64 -> V_254 ) ) {
V_222 = true ;
break;
}
}
if ( V_222 ) {
F_93 ( & V_65 ) ;
V_163 -> V_94 = V_64 -> V_254 ;
F_116 ( V_4 , V_163 , V_100 ) ;
if ( ! V_187 )
V_163 -> V_257 |= V_258 ;
F_94 ( & V_65 ) ;
F_112 ( V_4 , V_163 , V_224 ) ;
return 0 ;
}
if ( ! F_124 ( & V_64 -> V_228 . V_229 ) &&
! F_71 ( & V_64 -> V_228 . V_229 ) )
return - V_28 ;
V_163 = F_126 () ;
if ( ! V_163 )
return - V_46 ;
V_163 -> V_93 = V_64 -> V_230 . V_229 ;
V_163 -> V_92 = V_64 -> V_228 . V_229 ;
V_163 -> V_94 = V_64 -> V_254 ;
F_116 ( V_4 , V_163 , V_100 ) ;
if ( ! V_187 )
V_163 -> V_257 |= V_258 ;
F_93 ( & V_65 ) ;
F_150 ( & V_163 -> V_50 , & V_4 -> V_55 [ line ] ) ;
F_94 ( & V_65 ) ;
V_222 = false ;
F_38 ( & V_68 ) ;
F_36 (uc, &mrt->mfc6_unres_queue, list) {
if ( F_122 ( & V_209 -> V_93 , & V_163 -> V_93 ) &&
F_122 ( & V_209 -> V_92 , & V_163 -> V_92 ) ) {
F_23 ( & V_209 -> V_50 ) ;
F_103 ( & V_4 -> V_165 ) ;
V_222 = true ;
break;
}
}
if ( F_56 ( & V_4 -> V_56 ) )
F_175 ( & V_4 -> V_57 ) ;
F_39 ( & V_68 ) ;
if ( V_222 ) {
F_130 ( V_2 , V_4 , V_209 , V_163 ) ;
F_99 ( V_209 ) ;
}
F_112 ( V_4 , V_163 , V_224 ) ;
return 0 ;
}
static void F_32 ( struct V_1 * V_4 , bool V_259 )
{
int V_52 ;
F_176 ( V_50 ) ;
struct V_60 * V_163 , * V_49 ;
for ( V_52 = 0 ; V_52 < V_4 -> V_72 ; V_52 ++ ) {
if ( ! V_259 && ( V_4 -> V_73 [ V_52 ] . V_13 & V_195 ) )
continue;
F_92 ( V_4 , V_52 , 0 , & V_50 ) ;
}
F_177 ( & V_50 ) ;
for ( V_52 = 0 ; V_52 < V_54 ; V_52 ++ ) {
F_22 (c, next, &mrt->mfc6_cache_array[i], list) {
if ( ! V_259 && ( V_163 -> V_257 & V_258 ) )
continue;
F_93 ( & V_65 ) ;
F_23 ( & V_163 -> V_50 ) ;
F_94 ( & V_65 ) ;
F_112 ( V_4 , V_163 , V_182 ) ;
F_99 ( V_163 ) ;
}
}
if ( F_148 ( & V_4 -> V_165 ) != 0 ) {
F_38 ( & V_68 ) ;
F_22 (c, next, &mrt->mfc6_unres_queue, list) {
F_23 ( & V_163 -> V_50 ) ;
F_112 ( V_4 , V_163 , V_182 ) ;
F_101 ( V_4 , V_163 ) ;
}
F_39 ( & V_68 ) ;
}
}
static int F_178 ( struct V_1 * V_4 , struct V_260 * V_261 )
{
int V_7 = 0 ;
struct V_2 * V_2 = F_179 ( V_261 ) ;
F_21 () ;
F_93 ( & V_65 ) ;
if ( F_180 ( V_4 -> V_221 == NULL ) ) {
V_4 -> V_221 = V_261 ;
V_2 -> V_15 . V_262 -> V_159 ++ ;
} else {
V_7 = - V_189 ;
}
F_94 ( & V_65 ) ;
if ( ! V_7 )
F_97 ( V_2 , V_160 ,
V_161 ,
V_263 ,
V_2 -> V_15 . V_262 ) ;
F_24 () ;
return V_7 ;
}
int F_181 ( struct V_260 * V_261 )
{
int V_7 = - V_26 ;
struct V_2 * V_2 = F_179 ( V_261 ) ;
struct V_1 * V_4 ;
F_21 () ;
F_2 (mrt, net) {
if ( V_261 == V_4 -> V_221 ) {
F_93 ( & V_65 ) ;
V_4 -> V_221 = NULL ;
V_2 -> V_15 . V_262 -> V_159 -- ;
F_94 ( & V_65 ) ;
F_97 ( V_2 , V_160 ,
V_161 ,
V_263 ,
V_2 -> V_15 . V_262 ) ;
F_32 ( V_4 , false ) ;
V_7 = 0 ;
break;
}
}
F_24 () ;
return V_7 ;
}
struct V_260 * F_182 ( struct V_2 * V_2 , struct V_32 * V_33 )
{
struct V_1 * V_4 ;
struct V_5 V_108 = {
. V_109 = V_33 -> V_132 ? : V_133 ,
. V_131 = V_33 -> V_82 -> V_110 ,
. V_111 = V_33 -> V_112 ,
} ;
if ( F_3 ( V_2 , & V_108 , & V_4 ) < 0 )
return NULL ;
return V_4 -> V_221 ;
}
int F_183 ( struct V_260 * V_261 , int V_264 , char T_8 * V_265 , unsigned int V_266 )
{
int V_213 , V_227 = 0 ;
struct V_185 V_80 ;
struct V_226 V_64 ;
T_6 V_202 ;
struct V_2 * V_2 = F_179 ( V_261 ) ;
struct V_1 * V_4 ;
if ( V_261 -> V_267 != V_268 ||
F_184 ( V_261 ) -> V_269 != V_270 )
return - V_271 ;
V_4 = F_1 ( V_2 , F_185 ( V_261 ) -> V_272 ? : V_45 ) ;
if ( ! V_4 )
return - V_77 ;
if ( V_264 != V_273 ) {
if ( V_261 != V_4 -> V_221 && ! F_186 ( V_2 -> V_274 , V_275 ) )
return - V_26 ;
}
switch ( V_264 ) {
case V_273 :
if ( V_266 < sizeof( int ) )
return - V_28 ;
return F_178 ( V_4 , V_261 ) ;
case V_276 :
return F_181 ( V_261 ) ;
case V_277 :
if ( V_266 < sizeof( V_80 ) )
return - V_28 ;
if ( F_187 ( & V_80 , V_265 , sizeof( V_80 ) ) )
return - V_278 ;
if ( V_80 . V_188 >= V_183 )
return - V_255 ;
F_21 () ;
V_213 = F_117 ( V_2 , V_4 , & V_80 , V_261 == V_4 -> V_221 ) ;
F_24 () ;
return V_213 ;
case V_279 :
if ( V_266 < sizeof( T_6 ) )
return - V_28 ;
if ( F_187 ( & V_202 , V_265 , sizeof( T_6 ) ) )
return - V_278 ;
F_21 () ;
V_213 = F_92 ( V_4 , V_202 , 0 , NULL ) ;
F_24 () ;
return V_213 ;
case V_280 :
case V_281 :
V_227 = - 1 ;
case V_282 :
case V_283 :
if ( V_266 < sizeof( V_64 ) )
return - V_28 ;
if ( F_187 ( & V_64 , V_265 , sizeof( V_64 ) ) )
return - V_278 ;
if ( V_227 == 0 )
V_227 = V_64 . V_254 ;
F_21 () ;
if ( V_264 == V_281 || V_264 == V_283 )
V_213 = F_152 ( V_4 , & V_64 , V_227 ) ;
else
V_213 = F_173 ( V_2 , V_4 , & V_64 ,
V_261 == V_4 -> V_221 , V_227 ) ;
F_24 () ;
return V_213 ;
case V_284 :
{
int V_79 ;
if ( V_266 != sizeof( V_79 ) )
return - V_28 ;
if ( F_188 ( V_79 , ( int T_8 * ) V_265 ) )
return - V_278 ;
V_4 -> V_285 = V_79 ;
return 0 ;
}
#ifdef F_28
case V_286 :
{
int V_79 ;
if ( V_266 != sizeof( V_79 ) )
return - V_28 ;
if ( F_188 ( V_79 , ( int T_8 * ) V_265 ) )
return - V_278 ;
V_79 = ! ! V_79 ;
F_21 () ;
V_213 = 0 ;
if ( V_79 != V_4 -> V_287 ) {
V_4 -> V_287 = V_79 ;
V_4 -> V_285 = V_79 ;
}
F_24 () ;
return V_213 ;
}
#endif
#ifdef F_29
case V_288 :
{
T_1 V_79 ;
if ( V_266 != sizeof( T_1 ) )
return - V_28 ;
if ( F_188 ( V_79 , ( T_1 T_8 * ) V_265 ) )
return - V_278 ;
if ( V_79 != V_289 && V_79 >= 100000000 )
return - V_28 ;
if ( V_261 == V_4 -> V_221 )
return - V_290 ;
F_21 () ;
V_213 = 0 ;
if ( ! F_16 ( V_2 , V_79 ) )
V_213 = - V_46 ;
F_185 ( V_261 ) -> V_272 = V_79 ;
F_24 () ;
return V_213 ;
}
#endif
default:
return - V_291 ;
}
}
int F_189 ( struct V_260 * V_261 , int V_264 , char T_8 * V_265 ,
int T_8 * V_266 )
{
int V_292 ;
int V_293 ;
struct V_2 * V_2 = F_179 ( V_261 ) ;
struct V_1 * V_4 ;
if ( V_261 -> V_267 != V_268 ||
F_184 ( V_261 ) -> V_269 != V_270 )
return - V_271 ;
V_4 = F_1 ( V_2 , F_185 ( V_261 ) -> V_272 ? : V_45 ) ;
if ( ! V_4 )
return - V_77 ;
switch ( V_264 ) {
case V_294 :
V_293 = 0x0305 ;
break;
#ifdef F_28
case V_286 :
V_293 = V_4 -> V_287 ;
break;
#endif
case V_284 :
V_293 = V_4 -> V_285 ;
break;
default:
return - V_291 ;
}
if ( F_188 ( V_292 , V_266 ) )
return - V_278 ;
V_292 = F_190 ( int , V_292 , sizeof( int ) ) ;
if ( V_292 < 0 )
return - V_28 ;
if ( F_191 ( V_292 , V_266 ) )
return - V_278 ;
if ( F_192 ( V_265 , & V_293 , V_292 ) )
return - V_278 ;
return 0 ;
}
int F_193 ( struct V_260 * V_261 , int V_295 , void T_8 * V_11 )
{
struct V_296 V_297 ;
struct V_298 V_299 ;
struct V_69 * V_80 ;
struct V_60 * V_163 ;
struct V_2 * V_2 = F_179 ( V_261 ) ;
struct V_1 * V_4 ;
V_4 = F_1 ( V_2 , F_185 ( V_261 ) -> V_272 ? : V_45 ) ;
if ( ! V_4 )
return - V_77 ;
switch ( V_295 ) {
case V_300 :
if ( F_187 ( & V_299 , V_11 , sizeof( V_299 ) ) )
return - V_278 ;
if ( V_299 . V_202 >= V_4 -> V_72 )
return - V_28 ;
F_35 ( & V_65 ) ;
V_80 = & V_4 -> V_73 [ V_299 . V_202 ] ;
if ( F_41 ( V_4 , V_299 . V_202 ) ) {
V_299 . V_301 = V_80 -> V_84 ;
V_299 . V_302 = V_80 -> V_86 ;
V_299 . V_303 = V_80 -> V_83 ;
V_299 . V_304 = V_80 -> V_85 ;
F_37 ( & V_65 ) ;
if ( F_192 ( V_11 , & V_299 , sizeof( V_299 ) ) )
return - V_278 ;
return 0 ;
}
F_37 ( & V_65 ) ;
return - V_156 ;
case V_305 :
if ( F_187 ( & V_297 , V_11 , sizeof( V_297 ) ) )
return - V_278 ;
F_35 ( & V_65 ) ;
V_163 = F_120 ( V_4 , & V_297 . V_306 . V_229 , & V_297 . V_307 . V_229 ) ;
if ( V_163 ) {
V_297 . V_308 = V_163 -> V_95 . V_9 . V_96 ;
V_297 . V_309 = V_163 -> V_95 . V_9 . V_97 ;
V_297 . V_98 = V_163 -> V_95 . V_9 . V_98 ;
F_37 ( & V_65 ) ;
if ( F_192 ( V_11 , & V_297 , sizeof( V_297 ) ) )
return - V_278 ;
return 0 ;
}
F_37 ( & V_65 ) ;
return - V_156 ;
default:
return - V_310 ;
}
}
int F_194 ( struct V_260 * V_261 , unsigned int V_295 , void T_8 * V_11 )
{
struct V_311 V_297 ;
struct V_312 V_299 ;
struct V_69 * V_80 ;
struct V_60 * V_163 ;
struct V_2 * V_2 = F_179 ( V_261 ) ;
struct V_1 * V_4 ;
V_4 = F_1 ( V_2 , F_185 ( V_261 ) -> V_272 ? : V_45 ) ;
if ( ! V_4 )
return - V_77 ;
switch ( V_295 ) {
case V_300 :
if ( F_187 ( & V_299 , V_11 , sizeof( V_299 ) ) )
return - V_278 ;
if ( V_299 . V_202 >= V_4 -> V_72 )
return - V_28 ;
F_35 ( & V_65 ) ;
V_80 = & V_4 -> V_73 [ V_299 . V_202 ] ;
if ( F_41 ( V_4 , V_299 . V_202 ) ) {
V_299 . V_301 = V_80 -> V_84 ;
V_299 . V_302 = V_80 -> V_86 ;
V_299 . V_303 = V_80 -> V_83 ;
V_299 . V_304 = V_80 -> V_85 ;
F_37 ( & V_65 ) ;
if ( F_192 ( V_11 , & V_299 , sizeof( V_299 ) ) )
return - V_278 ;
return 0 ;
}
F_37 ( & V_65 ) ;
return - V_156 ;
case V_305 :
if ( F_187 ( & V_297 , V_11 , sizeof( V_297 ) ) )
return - V_278 ;
F_35 ( & V_65 ) ;
V_163 = F_120 ( V_4 , & V_297 . V_306 . V_229 , & V_297 . V_307 . V_229 ) ;
if ( V_163 ) {
V_297 . V_308 = V_163 -> V_95 . V_9 . V_96 ;
V_297 . V_309 = V_163 -> V_95 . V_9 . V_97 ;
V_297 . V_98 = V_163 -> V_95 . V_9 . V_98 ;
F_37 ( & V_65 ) ;
if ( F_192 ( V_11 , & V_297 , sizeof( V_297 ) ) )
return - V_278 ;
return 0 ;
}
F_37 ( & V_65 ) ;
return - V_156 ;
default:
return - V_310 ;
}
}
static inline int F_195 ( struct V_2 * V_2 , struct V_260 * V_261 , struct V_32 * V_33 )
{
F_196 ( V_2 , F_197 ( F_144 ( V_33 ) ) ,
V_313 ) ;
F_198 ( V_2 , F_197 ( F_144 ( V_33 ) ) ,
V_314 , V_33 -> V_121 ) ;
return F_199 ( V_2 , V_261 , V_33 ) ;
}
static int F_200 ( struct V_2 * V_2 , struct V_1 * V_4 ,
struct V_32 * V_33 , struct V_60 * V_163 , int V_150 )
{
struct V_104 * V_315 ;
struct V_69 * V_80 = & V_4 -> V_73 [ V_150 ] ;
struct V_106 * V_82 ;
struct V_316 * V_317 ;
struct V_5 V_108 ;
if ( ! V_80 -> V_82 )
goto V_318;
#ifdef F_28
if ( V_80 -> V_13 & V_162 ) {
V_80 -> V_86 ++ ;
V_80 -> V_85 += V_33 -> V_121 ;
V_80 -> V_82 -> V_134 . V_135 += V_33 -> V_121 ;
V_80 -> V_82 -> V_134 . V_136 ++ ;
F_82 ( V_4 , V_33 , V_150 , V_137 ) ;
goto V_318;
}
#endif
V_315 = F_67 ( V_33 ) ;
V_108 = (struct V_5 ) {
. V_131 = V_80 -> V_198 ,
. V_119 = V_315 -> V_119 ,
} ;
V_317 = F_201 ( V_2 , NULL , & V_108 ) ;
if ( V_317 -> error ) {
F_202 ( V_317 ) ;
goto V_318;
}
F_203 ( V_33 ) ;
F_142 ( V_33 , V_317 ) ;
V_82 = V_80 -> V_82 ;
V_33 -> V_82 = V_82 ;
V_80 -> V_86 ++ ;
V_80 -> V_85 += V_33 -> V_121 ;
if ( F_204 ( V_33 , sizeof( * V_315 ) + F_205 ( V_82 ) ) )
goto V_318;
V_315 = F_67 ( V_33 ) ;
V_315 -> V_319 -- ;
F_206 ( V_33 ) -> V_13 |= V_320 ;
return F_207 ( V_321 , V_322 ,
V_2 , NULL , V_33 , V_33 -> V_82 , V_82 ,
F_195 ) ;
V_318:
F_80 ( V_33 ) ;
return 0 ;
}
static int F_208 ( struct V_1 * V_4 , struct V_106 * V_82 )
{
int V_66 ;
for ( V_66 = V_4 -> V_72 - 1 ; V_66 >= 0 ; V_66 -- ) {
if ( V_4 -> V_73 [ V_66 ] . V_82 == V_82 )
break;
}
return V_66 ;
}
static void F_134 ( struct V_2 * V_2 , struct V_1 * V_4 ,
struct V_32 * V_33 , struct V_60 * V_67 )
{
int V_323 = - 1 ;
int V_80 , V_66 ;
int V_324 = F_208 ( V_4 , V_33 -> V_82 ) ;
V_80 = V_67 -> V_94 ;
V_67 -> V_95 . V_9 . V_96 ++ ;
V_67 -> V_95 . V_9 . V_97 += V_33 -> V_121 ;
V_67 -> V_95 . V_9 . V_184 = V_178 ;
if ( F_124 ( & V_67 -> V_93 ) && V_324 >= 0 ) {
struct V_60 * V_325 ;
V_325 = F_123 ( V_4 , V_80 ) ;
if ( V_325 &&
V_325 -> V_95 . V_9 . V_100 [ V_324 ] < 255 )
goto V_326;
}
if ( V_4 -> V_73 [ V_80 ] . V_82 != V_33 -> V_82 ) {
V_67 -> V_95 . V_9 . V_98 ++ ;
if ( V_324 >= 0 && V_4 -> V_285 &&
( V_4 -> V_287 ||
V_67 -> V_95 . V_9 . V_100 [ V_324 ] < 255 ) &&
F_111 ( V_178 ,
V_67 -> V_95 . V_9 . V_206 + V_207 ) ) {
V_67 -> V_95 . V_9 . V_206 = V_178 ;
F_82 ( V_4 , V_33 , V_324 , V_327 ) ;
}
goto V_328;
}
V_326:
V_4 -> V_73 [ V_80 ] . V_84 ++ ;
V_4 -> V_73 [ V_80 ] . V_83 += V_33 -> V_121 ;
if ( F_124 ( & V_67 -> V_93 ) &&
F_124 ( & V_67 -> V_92 ) ) {
if ( V_324 >= 0 &&
V_324 != V_67 -> V_94 &&
F_67 ( V_33 ) -> V_319 >
V_67 -> V_95 . V_9 . V_100 [ V_67 -> V_94 ] ) {
V_323 = V_67 -> V_94 ;
goto V_329;
}
goto V_328;
}
for ( V_66 = V_67 -> V_95 . V_9 . V_72 - 1 ; V_66 >= V_67 -> V_95 . V_9 . V_99 ; V_66 -- ) {
if ( ( ! F_124 ( & V_67 -> V_93 ) || V_66 != V_324 ) &&
F_67 ( V_33 ) -> V_319 > V_67 -> V_95 . V_9 . V_100 [ V_66 ] ) {
if ( V_323 != - 1 ) {
struct V_32 * V_330 = F_209 ( V_33 , V_208 ) ;
if ( V_330 )
F_200 ( V_2 , V_4 , V_330 , V_67 , V_323 ) ;
}
V_323 = V_66 ;
}
}
V_329:
if ( V_323 != - 1 ) {
F_200 ( V_2 , V_4 , V_33 , V_67 , V_323 ) ;
return;
}
V_328:
F_80 ( V_33 ) ;
}
int F_210 ( struct V_32 * V_33 )
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
V_67 = F_120 ( V_4 ,
& F_67 ( V_33 ) -> V_118 , & F_67 ( V_33 ) -> V_119 ) ;
if ( ! V_67 ) {
int V_80 = F_208 ( V_4 , V_33 -> V_82 ) ;
if ( V_80 >= 0 )
V_67 = F_125 ( V_4 ,
& F_67 ( V_33 ) -> V_119 ,
V_80 ) ;
}
if ( ! V_67 ) {
int V_80 ;
V_80 = F_208 ( V_4 , V_33 -> V_82 ) ;
if ( V_80 >= 0 ) {
int V_7 = F_147 ( V_4 , V_80 , V_33 ) ;
F_37 ( & V_65 ) ;
return V_7 ;
}
F_37 ( & V_65 ) ;
F_80 ( V_33 ) ;
return - V_331 ;
}
F_134 ( V_2 , V_4 , V_33 , V_67 ) ;
F_37 ( & V_65 ) ;
return 0 ;
}
static int F_132 ( struct V_1 * V_4 , struct V_32 * V_33 ,
struct V_60 * V_163 , struct V_332 * V_333 )
{
struct V_334 V_335 ;
struct V_36 * V_336 ;
struct V_337 * V_338 ;
unsigned long V_184 ;
int V_66 ;
if ( V_163 -> V_94 >= V_183 ) {
V_333 -> V_339 |= V_340 ;
return - V_77 ;
}
if ( F_41 ( V_4 , V_163 -> V_94 ) &&
F_211 ( V_33 , V_341 , V_4 -> V_73 [ V_163 -> V_94 ] . V_82 -> V_110 ) < 0 )
return - V_210 ;
V_336 = F_212 ( V_33 , V_342 ) ;
if ( ! V_336 )
return - V_210 ;
for ( V_66 = V_163 -> V_95 . V_9 . V_99 ; V_66 < V_163 -> V_95 . V_9 . V_72 ; V_66 ++ ) {
if ( F_41 ( V_4 , V_66 ) && V_163 -> V_95 . V_9 . V_100 [ V_66 ] < 255 ) {
V_338 = F_213 ( V_33 , sizeof( * V_338 ) ) ;
if ( ! V_338 ) {
F_214 ( V_33 , V_336 ) ;
return - V_210 ;
}
V_338 -> V_343 = 0 ;
V_338 -> V_344 = V_163 -> V_95 . V_9 . V_100 [ V_66 ] ;
V_338 -> V_345 = V_4 -> V_73 [ V_66 ] . V_82 -> V_110 ;
V_338 -> V_346 = sizeof( * V_338 ) ;
}
}
F_215 ( V_33 , V_336 ) ;
V_184 = F_216 ( V_163 -> V_95 . V_9 . V_184 ) ;
V_184 = F_217 ( V_178 , V_184 ) ? V_178 - V_184 : 0 ;
V_335 . V_347 = V_163 -> V_95 . V_9 . V_96 ;
V_335 . V_348 = V_163 -> V_95 . V_9 . V_97 ;
V_335 . V_349 = V_163 -> V_95 . V_9 . V_98 ;
if ( F_218 ( V_33 , V_350 , sizeof( V_335 ) , & V_335 , V_351 ) ||
F_219 ( V_33 , V_352 , F_220 ( V_184 ) ,
V_351 ) )
return - V_210 ;
V_333 -> V_353 = V_354 ;
return 1 ;
}
int F_221 ( struct V_2 * V_2 , struct V_32 * V_33 , struct V_332 * V_333 ,
T_1 V_176 )
{
int V_7 ;
struct V_1 * V_4 ;
struct V_60 * V_67 ;
struct V_355 * V_356 = (struct V_355 * ) F_144 ( V_33 ) ;
V_4 = F_1 ( V_2 , V_45 ) ;
if ( ! V_4 )
return - V_77 ;
F_35 ( & V_65 ) ;
V_67 = F_120 ( V_4 , & V_356 -> V_357 . V_358 , & V_356 -> V_359 . V_358 ) ;
if ( ! V_67 && V_33 -> V_82 ) {
int V_80 = F_208 ( V_4 , V_33 -> V_82 ) ;
if ( V_80 >= 0 )
V_67 = F_125 ( V_4 , & V_356 -> V_359 . V_358 ,
V_80 ) ;
}
if ( ! V_67 ) {
struct V_32 * V_330 ;
struct V_104 * V_360 ;
struct V_106 * V_82 ;
int V_80 ;
V_82 = V_33 -> V_82 ;
if ( ! V_82 || ( V_80 = F_208 ( V_4 , V_82 ) ) < 0 ) {
F_37 ( & V_65 ) ;
return - V_331 ;
}
V_330 = F_137 ( sizeof( struct V_104 ) , V_208 ) ;
if ( ! V_330 ) {
F_37 ( & V_65 ) ;
return - V_46 ;
}
F_109 ( V_330 ) . V_176 = V_176 ;
F_139 ( V_330 ) ;
F_140 ( V_330 , sizeof( struct V_104 ) ) ;
F_75 ( V_330 ) ;
V_360 = F_67 ( V_330 ) ;
V_360 -> V_168 = 0 ;
V_360 -> V_361 = 0 ;
V_360 -> V_362 [ 0 ] = 0 ;
V_360 -> V_362 [ 1 ] = 0 ;
V_360 -> V_362 [ 2 ] = 0 ;
V_360 -> V_122 = 0 ;
V_360 -> V_363 = V_364 ;
V_360 -> V_319 = 0 ;
V_360 -> V_118 = V_356 -> V_357 . V_358 ;
V_360 -> V_119 = V_356 -> V_359 . V_358 ;
V_7 = F_147 ( V_4 , V_80 , V_330 ) ;
F_37 ( & V_65 ) ;
return V_7 ;
}
if ( V_333 -> V_339 & V_365 )
V_67 -> V_257 |= V_366 ;
V_7 = F_132 ( V_4 , V_33 , V_67 , V_333 ) ;
F_37 ( & V_65 ) ;
return V_7 ;
}
static int F_222 ( struct V_1 * V_4 , struct V_32 * V_33 ,
T_1 V_176 , T_1 V_75 , struct V_60 * V_163 , int V_295 ,
int V_13 )
{
struct V_169 * V_170 ;
struct V_332 * V_333 ;
int V_7 ;
V_170 = F_223 ( V_33 , V_176 , V_75 , V_295 , sizeof( * V_333 ) , V_13 ) ;
if ( ! V_170 )
return - V_210 ;
V_333 = F_107 ( V_170 ) ;
V_333 -> V_367 = V_251 ;
V_333 -> V_368 = 128 ;
V_333 -> V_369 = 128 ;
V_333 -> V_370 = 0 ;
V_333 -> V_371 = V_4 -> V_3 ;
if ( F_211 ( V_33 , V_372 , V_4 -> V_3 ) )
goto V_373;
V_333 -> V_353 = V_354 ;
V_333 -> V_374 = V_375 ;
if ( V_163 -> V_257 & V_258 )
V_333 -> V_376 = V_377 ;
else
V_333 -> V_376 = V_378 ;
V_333 -> V_339 = 0 ;
if ( F_224 ( V_33 , V_379 , & V_163 -> V_93 ) ||
F_224 ( V_33 , V_380 , & V_163 -> V_92 ) )
goto V_373;
V_7 = F_132 ( V_4 , V_33 , V_163 , V_333 ) ;
if ( V_7 < 0 && V_7 != - V_77 )
goto V_373;
F_225 ( V_33 , V_170 ) ;
return 0 ;
V_373:
F_226 ( V_33 , V_170 ) ;
return - V_210 ;
}
static int F_227 ( bool V_167 , int V_72 )
{
T_9 V_121 =
F_228 ( sizeof( struct V_332 ) )
+ F_229 ( 4 )
+ F_229 ( sizeof( struct V_199 ) )
+ F_229 ( sizeof( struct V_199 ) )
;
if ( ! V_167 )
V_121 = V_121
+ F_229 ( 4 )
+ F_229 ( 0 )
+ V_72 * F_230 ( sizeof( struct V_337 ) )
+ F_231 ( sizeof( struct V_334 ) )
;
return V_121 ;
}
static void F_112 ( struct V_1 * V_4 , struct V_60 * V_64 ,
int V_295 )
{
struct V_2 * V_2 = F_102 ( & V_4 -> V_2 ) ;
struct V_32 * V_33 ;
int V_7 = - V_191 ;
V_33 = F_232 ( F_227 ( V_64 -> V_94 >= V_183 , V_4 -> V_72 ) ,
V_208 ) ;
if ( ! V_33 )
goto V_381;
V_7 = F_222 ( V_4 , V_33 , 0 , 0 , V_64 , V_295 , 0 ) ;
if ( V_7 < 0 )
goto V_381;
F_233 ( V_33 , V_2 , 0 , V_382 , NULL , V_208 ) ;
return;
V_381:
F_80 ( V_33 ) ;
if ( V_7 < 0 )
F_234 ( V_2 , V_382 , V_7 ) ;
}
static int V_253 ( struct V_32 * V_33 , struct V_383 * V_384 )
{
struct V_2 * V_2 = F_179 ( V_33 -> V_261 ) ;
struct V_1 * V_4 ;
struct V_60 * V_64 ;
unsigned int V_385 = 0 , V_386 ;
unsigned int V_387 = 0 , V_388 ;
unsigned int V_389 = 0 , V_390 ;
V_386 = V_384 -> args [ 0 ] ;
V_388 = V_384 -> args [ 1 ] ;
V_390 = V_384 -> args [ 2 ] ;
F_35 ( & V_65 ) ;
F_2 (mrt, net) {
if ( V_385 < V_386 )
goto V_391;
if ( V_385 > V_386 )
V_388 = 0 ;
for ( V_387 = V_388 ; V_387 < V_54 ; V_387 ++ ) {
F_36 (mfc, &mrt->mfc6_cache_array[h], list) {
if ( V_389 < V_390 )
goto V_392;
if ( F_222 ( V_4 , V_33 ,
F_109 ( V_384 -> V_33 ) . V_176 ,
V_384 -> V_170 -> V_393 ,
V_64 , V_224 ,
V_394 ) < 0 )
goto V_395;
V_392:
V_389 ++ ;
}
V_389 = V_390 = 0 ;
}
F_38 ( & V_68 ) ;
F_36 (mfc, &mrt->mfc6_unres_queue, list) {
if ( V_389 < V_390 )
goto V_396;
if ( F_222 ( V_4 , V_33 ,
F_109 ( V_384 -> V_33 ) . V_176 ,
V_384 -> V_170 -> V_393 ,
V_64 , V_224 ,
V_394 ) < 0 ) {
F_39 ( & V_68 ) ;
goto V_395;
}
V_396:
V_389 ++ ;
}
F_39 ( & V_68 ) ;
V_389 = V_390 = 0 ;
V_388 = 0 ;
V_391:
V_385 ++ ;
}
V_395:
F_37 ( & V_65 ) ;
V_384 -> args [ 2 ] = V_389 ;
V_384 -> args [ 1 ] = V_387 ;
V_384 -> args [ 0 ] = V_385 ;
return V_33 -> V_121 ;
}
