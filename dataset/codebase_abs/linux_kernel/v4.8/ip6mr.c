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
V_82 -> V_144 = V_145 ;
V_82 -> V_146 |= V_147 ;
}
static struct V_106 * F_85 ( struct V_2 * V_2 , struct V_1 * V_4 )
{
struct V_106 * V_82 ;
char V_81 [ V_148 ] ;
if ( V_4 -> V_3 == V_45 )
sprintf ( V_81 , L_10 ) ;
else
sprintf ( V_81 , L_11 , V_4 -> V_3 ) ;
V_82 = F_86 ( 0 , V_81 , V_149 , F_84 ) ;
if ( ! V_82 )
return NULL ;
F_87 ( V_82 , V_2 ) ;
if ( F_88 ( V_82 ) ) {
V_145 ( V_82 ) ;
return NULL ;
}
if ( F_89 ( V_82 ) )
goto V_150;
F_73 ( V_82 ) ;
return V_82 ;
V_150:
F_90 ( V_82 ) ;
return NULL ;
}
static int F_91 ( struct V_1 * V_4 , int V_151 , struct V_152 * V_153 )
{
struct V_69 * V_79 ;
struct V_106 * V_82 ;
struct V_154 * V_155 ;
if ( V_151 < 0 || V_151 >= V_4 -> V_72 )
return - V_156 ;
V_79 = & V_4 -> V_73 [ V_151 ] ;
F_92 ( & V_65 ) ;
V_82 = V_79 -> V_82 ;
V_79 -> V_82 = NULL ;
if ( ! V_82 ) {
F_93 ( & V_65 ) ;
return - V_156 ;
}
#ifdef F_28
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
F_93 ( & V_65 ) ;
F_94 ( V_82 , - 1 ) ;
V_155 = F_95 ( V_82 ) ;
if ( V_155 ) {
V_155 -> V_158 . V_159 -- ;
F_96 ( F_63 ( V_82 ) ,
V_160 ,
V_82 -> V_110 , & V_155 -> V_158 ) ;
}
if ( V_79 -> V_13 & V_161 )
F_97 ( V_82 , V_153 ) ;
F_79 ( V_82 ) ;
return 0 ;
}
static inline void F_98 ( struct V_60 * V_162 )
{
F_99 ( V_163 , V_162 ) ;
}
static void F_100 ( struct V_1 * V_4 , struct V_60 * V_162 )
{
struct V_2 * V_2 = F_101 ( & V_4 -> V_2 ) ;
struct V_32 * V_33 ;
F_102 ( & V_4 -> V_164 ) ;
while ( ( V_33 = F_103 ( & V_162 -> V_95 . V_165 . V_166 ) ) != NULL ) {
if ( F_67 ( V_33 ) -> V_167 == 0 ) {
struct V_168 * V_169 = (struct V_168 * ) F_74 ( V_33 , sizeof( struct V_104 ) ) ;
V_169 -> V_170 = V_171 ;
V_169 -> V_172 = F_104 ( sizeof( struct V_173 ) ) ;
F_105 ( V_33 , V_169 -> V_172 ) ;
( (struct V_173 * ) F_106 ( V_169 ) ) -> error = - V_174 ;
F_107 ( V_33 , V_2 , F_108 ( V_33 ) . V_175 ) ;
} else
F_80 ( V_33 ) ;
}
F_98 ( V_162 ) ;
}
static void F_109 ( struct V_1 * V_4 )
{
unsigned long V_176 = V_177 ;
unsigned long V_178 = 10 * V_179 ;
struct V_60 * V_162 , * V_49 ;
F_22 (c, next, &mrt->mfc6_unres_queue, list) {
if ( F_110 ( V_162 -> V_95 . V_165 . V_178 , V_176 ) ) {
unsigned long V_180 = V_162 -> V_95 . V_165 . V_178 - V_176 ;
if ( V_180 < V_178 )
V_178 = V_180 ;
continue;
}
F_23 ( & V_162 -> V_50 ) ;
F_111 ( V_4 , V_162 , V_181 ) ;
F_100 ( V_4 , V_162 ) ;
}
if ( ! F_56 ( & V_4 -> V_56 ) )
F_112 ( & V_4 -> V_57 , V_177 + V_178 ) ;
}
static void V_58 ( unsigned long V_11 )
{
struct V_1 * V_4 = (struct V_1 * ) V_11 ;
if ( ! F_113 ( & V_68 ) ) {
F_112 ( & V_4 -> V_57 , V_177 + 1 ) ;
return;
}
if ( ! F_56 ( & V_4 -> V_56 ) )
F_109 ( V_4 ) ;
F_114 ( & V_68 ) ;
}
static void F_115 ( struct V_1 * V_4 , struct V_60 * V_67 ,
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
V_67 -> V_95 . V_9 . V_183 = V_177 ;
}
static int F_116 ( struct V_2 * V_2 , struct V_1 * V_4 ,
struct V_184 * V_185 , int V_186 )
{
int V_151 = V_185 -> V_187 ;
struct V_69 * V_79 = & V_4 -> V_73 [ V_151 ] ;
struct V_106 * V_82 ;
struct V_154 * V_155 ;
int V_7 ;
if ( F_41 ( V_4 , V_151 ) )
return - V_188 ;
switch ( V_185 -> V_189 ) {
#ifdef F_28
case V_161 :
if ( V_4 -> V_59 >= 0 )
return - V_188 ;
V_82 = F_85 ( V_2 , V_4 ) ;
if ( ! V_82 )
return - V_190 ;
V_7 = F_94 ( V_82 , 1 ) ;
if ( V_7 ) {
F_90 ( V_82 ) ;
F_79 ( V_82 ) ;
return V_7 ;
}
break;
#endif
case 0 :
V_82 = F_117 ( V_2 , V_185 -> V_191 ) ;
if ( ! V_82 )
return - V_156 ;
V_7 = F_94 ( V_82 , 1 ) ;
if ( V_7 ) {
F_79 ( V_82 ) ;
return V_7 ;
}
break;
default:
return - V_28 ;
}
V_155 = F_95 ( V_82 ) ;
if ( V_155 ) {
V_155 -> V_158 . V_159 ++ ;
F_96 ( F_63 ( V_82 ) ,
V_160 ,
V_82 -> V_110 , & V_155 -> V_158 ) ;
}
V_79 -> V_192 = V_185 -> V_193 ;
V_79 -> V_13 = V_185 -> V_189 ;
if ( ! V_186 )
V_79 -> V_13 |= V_194 ;
V_79 -> V_195 = V_185 -> V_196 ;
V_79 -> V_83 = 0 ;
V_79 -> V_85 = 0 ;
V_79 -> V_84 = 0 ;
V_79 -> V_86 = 0 ;
V_79 -> V_197 = V_82 -> V_110 ;
if ( V_79 -> V_13 & V_161 )
V_79 -> V_197 = F_118 ( V_82 ) ;
F_92 ( & V_65 ) ;
V_79 -> V_82 = V_82 ;
#ifdef F_28
if ( V_79 -> V_13 & V_161 )
V_4 -> V_59 = V_151 ;
#endif
if ( V_151 + 1 > V_4 -> V_72 )
V_4 -> V_72 = V_151 + 1 ;
F_93 ( & V_65 ) ;
return 0 ;
}
static struct V_60 * F_119 ( struct V_1 * V_4 ,
const struct V_198 * V_199 ,
const struct V_198 * V_200 )
{
int line = F_120 ( V_200 , V_199 ) ;
struct V_60 * V_162 ;
F_36 (c, &mrt->mfc6_cache_array[line], list) {
if ( F_121 ( & V_162 -> V_93 , V_199 ) &&
F_121 ( & V_162 -> V_92 , V_200 ) )
return V_162 ;
}
return NULL ;
}
static struct V_60 * F_122 ( struct V_1 * V_4 ,
T_6 V_201 )
{
int line = F_120 ( & V_202 , & V_202 ) ;
struct V_60 * V_162 ;
F_36 (c, &mrt->mfc6_cache_array[line], list)
if ( F_123 ( & V_162 -> V_93 ) &&
F_123 ( & V_162 -> V_92 ) &&
( V_162 -> V_95 . V_9 . V_100 [ V_201 ] < 255 ) )
return V_162 ;
return NULL ;
}
static struct V_60 * F_124 ( struct V_1 * V_4 ,
struct V_198 * V_200 ,
T_6 V_201 )
{
int line = F_120 ( V_200 , & V_202 ) ;
struct V_60 * V_162 , * V_203 ;
if ( F_123 ( V_200 ) )
goto V_204;
F_36 (c, &mrt->mfc6_cache_array[line], list)
if ( F_123 ( & V_162 -> V_93 ) &&
F_121 ( & V_162 -> V_92 , V_200 ) ) {
if ( V_162 -> V_95 . V_9 . V_100 [ V_201 ] < 255 )
return V_162 ;
V_203 = F_122 ( V_4 ,
V_162 -> V_94 ) ;
if ( V_203 && V_203 -> V_95 . V_9 . V_100 [ V_201 ] < 255 )
return V_162 ;
}
V_204:
return F_122 ( V_4 , V_201 ) ;
}
static struct V_60 * F_125 ( void )
{
struct V_60 * V_162 = F_126 ( V_163 , V_53 ) ;
if ( ! V_162 )
return NULL ;
V_162 -> V_95 . V_9 . V_205 = V_177 - V_206 - 1 ;
V_162 -> V_95 . V_9 . V_99 = V_182 ;
return V_162 ;
}
static struct V_60 * F_127 ( void )
{
struct V_60 * V_162 = F_126 ( V_163 , V_207 ) ;
if ( ! V_162 )
return NULL ;
F_128 ( & V_162 -> V_95 . V_165 . V_166 ) ;
V_162 -> V_95 . V_165 . V_178 = V_177 + 10 * V_179 ;
return V_162 ;
}
static void F_129 ( struct V_2 * V_2 , struct V_1 * V_4 ,
struct V_60 * V_208 , struct V_60 * V_162 )
{
struct V_32 * V_33 ;
while ( ( V_33 = F_130 ( & V_208 -> V_95 . V_165 . V_166 ) ) ) {
if ( F_67 ( V_33 ) -> V_167 == 0 ) {
struct V_168 * V_169 = (struct V_168 * ) F_74 ( V_33 , sizeof( struct V_104 ) ) ;
if ( F_131 ( V_4 , V_33 , V_162 , F_106 ( V_169 ) ) > 0 ) {
V_169 -> V_172 = F_132 ( V_33 ) - ( V_125 * ) V_169 ;
} else {
V_169 -> V_170 = V_171 ;
V_169 -> V_172 = F_104 ( sizeof( struct V_173 ) ) ;
F_105 ( V_33 , V_169 -> V_172 ) ;
( (struct V_173 * ) F_106 ( V_169 ) ) -> error = - V_209 ;
}
F_107 ( V_33 , V_2 , F_108 ( V_33 ) . V_175 ) ;
} else
F_133 ( V_2 , V_4 , V_33 , V_162 ) ;
}
}
static int F_82 ( struct V_1 * V_4 , struct V_32 * V_96 ,
T_6 V_201 , int assert )
{
struct V_32 * V_33 ;
struct V_210 * V_211 ;
int V_212 ;
#ifdef F_28
if ( assert == V_137 )
V_33 = F_134 ( V_96 , - F_135 ( V_96 )
+ sizeof( * V_211 ) ) ;
else
#endif
V_33 = F_136 ( sizeof( struct V_104 ) + sizeof( * V_211 ) , V_207 ) ;
if ( ! V_33 )
return - V_190 ;
V_33 -> V_129 = V_213 ;
#ifdef F_28
if ( assert == V_137 ) {
F_137 ( V_33 , - F_135 ( V_96 ) ) ;
F_137 ( V_33 , sizeof( * V_211 ) ) ;
F_138 ( V_33 ) ;
V_211 = (struct V_210 * ) F_65 ( V_33 ) ;
V_211 -> V_214 = 0 ;
V_211 -> V_215 = V_137 ;
V_211 -> V_216 = V_4 -> V_59 ;
V_211 -> V_217 = 0 ;
V_211 -> V_218 = F_67 ( V_96 ) -> V_118 ;
V_211 -> V_219 = F_67 ( V_96 ) -> V_119 ;
V_33 -> V_129 = V_213 ;
} else
#endif
{
F_139 ( V_33 , sizeof( struct V_104 ) ) ;
F_75 ( V_33 ) ;
F_140 ( V_33 , F_67 ( V_96 ) , sizeof( struct V_104 ) ) ;
F_139 ( V_33 , sizeof( * V_211 ) ) ;
F_138 ( V_33 ) ;
V_211 = (struct V_210 * ) F_65 ( V_33 ) ;
V_211 -> V_214 = 0 ;
V_211 -> V_215 = assert ;
V_211 -> V_216 = V_201 ;
V_211 -> V_217 = 0 ;
V_211 -> V_218 = F_67 ( V_96 ) -> V_118 ;
V_211 -> V_219 = F_67 ( V_96 ) -> V_119 ;
F_141 ( V_33 , F_142 ( F_143 ( V_96 ) ) ) ;
V_33 -> V_129 = V_213 ;
}
if ( ! V_4 -> V_220 ) {
F_80 ( V_33 ) ;
return - V_28 ;
}
V_212 = F_144 ( V_4 -> V_220 , V_33 ) ;
if ( V_212 < 0 ) {
F_145 ( L_12 ) ;
F_80 ( V_33 ) ;
}
return V_212 ;
}
static int
F_146 ( struct V_1 * V_4 , T_6 V_201 , struct V_32 * V_33 )
{
bool V_221 = false ;
int V_7 ;
struct V_60 * V_162 ;
F_38 ( & V_68 ) ;
F_36 (c, &mrt->mfc6_unres_queue, list) {
if ( F_121 ( & V_162 -> V_92 , & F_67 ( V_33 ) -> V_119 ) &&
F_121 ( & V_162 -> V_93 , & F_67 ( V_33 ) -> V_118 ) ) {
V_221 = true ;
break;
}
}
if ( ! V_221 ) {
if ( F_147 ( & V_4 -> V_164 ) >= 10 ||
( V_162 = F_127 () ) == NULL ) {
F_39 ( & V_68 ) ;
F_80 ( V_33 ) ;
return - V_190 ;
}
V_162 -> V_94 = - 1 ;
V_162 -> V_93 = F_67 ( V_33 ) -> V_118 ;
V_162 -> V_92 = F_67 ( V_33 ) -> V_119 ;
V_7 = F_82 ( V_4 , V_33 , V_201 , V_222 ) ;
if ( V_7 < 0 ) {
F_39 ( & V_68 ) ;
F_98 ( V_162 ) ;
F_80 ( V_33 ) ;
return V_7 ;
}
F_148 ( & V_4 -> V_164 ) ;
F_149 ( & V_162 -> V_50 , & V_4 -> V_56 ) ;
F_111 ( V_4 , V_162 , V_223 ) ;
F_109 ( V_4 ) ;
}
if ( V_162 -> V_95 . V_165 . V_166 . V_224 > 3 ) {
F_80 ( V_33 ) ;
V_7 = - V_190 ;
} else {
F_150 ( & V_162 -> V_95 . V_165 . V_166 , V_33 ) ;
V_7 = 0 ;
}
F_39 ( & V_68 ) ;
return V_7 ;
}
static int F_151 ( struct V_1 * V_4 , struct V_225 * V_64 ,
int V_226 )
{
int line ;
struct V_60 * V_162 , * V_49 ;
line = F_120 ( & V_64 -> V_227 . V_228 , & V_64 -> V_229 . V_228 ) ;
F_22 (c, next, &mrt->mfc6_cache_array[line], list) {
if ( F_121 ( & V_162 -> V_93 , & V_64 -> V_229 . V_228 ) &&
F_121 ( & V_162 -> V_92 ,
& V_64 -> V_227 . V_228 ) &&
( V_226 == - 1 || V_226 == V_162 -> V_94 ) ) {
F_92 ( & V_65 ) ;
F_23 ( & V_162 -> V_50 ) ;
F_93 ( & V_65 ) ;
F_111 ( V_4 , V_162 , V_181 ) ;
F_98 ( V_162 ) ;
return 0 ;
}
}
return - V_77 ;
}
static int F_152 ( struct V_230 * V_231 ,
unsigned long V_232 , void * V_233 )
{
struct V_106 * V_82 = F_153 ( V_233 ) ;
struct V_2 * V_2 = F_63 ( V_82 ) ;
struct V_1 * V_4 ;
struct V_69 * V_79 ;
int V_66 ;
F_154 ( V_50 ) ;
if ( V_232 != V_234 )
return V_235 ;
F_2 (mrt, net) {
V_79 = & V_4 -> V_73 [ 0 ] ;
for ( V_66 = 0 ; V_66 < V_4 -> V_72 ; V_66 ++ , V_79 ++ ) {
if ( V_79 -> V_82 == V_82 )
F_91 ( V_4 , V_66 , & V_50 ) ;
}
}
F_155 ( & V_50 ) ;
return V_235 ;
}
static int T_2 F_156 ( struct V_2 * V_2 )
{
int V_7 ;
V_7 = F_11 ( V_2 ) ;
if ( V_7 < 0 )
goto V_236;
#ifdef F_157
V_7 = - V_46 ;
if ( ! F_158 ( L_13 , 0 , V_2 -> V_237 , & V_238 ) )
goto V_239;
if ( ! F_158 ( L_14 , 0 , V_2 -> V_237 , & V_240 ) )
goto V_241;
#endif
return 0 ;
#ifdef F_157
V_241:
F_159 ( L_13 , V_2 -> V_237 ) ;
V_239:
F_20 ( V_2 ) ;
#endif
V_236:
return V_7 ;
}
static void T_3 F_160 ( struct V_2 * V_2 )
{
#ifdef F_157
F_159 ( L_14 , V_2 -> V_237 ) ;
F_159 ( L_13 , V_2 -> V_237 ) ;
#endif
F_20 ( V_2 ) ;
}
int T_7 F_161 ( void )
{
int V_7 ;
V_163 = F_162 ( L_15 ,
sizeof( struct V_60 ) ,
0 , V_242 ,
NULL ) ;
if ( ! V_163 )
return - V_46 ;
V_7 = F_163 ( & V_243 ) ;
if ( V_7 )
goto V_244;
V_7 = F_164 ( & V_245 ) ;
if ( V_7 )
goto V_246;
#ifdef F_28
if ( F_165 ( & V_247 , V_120 ) < 0 ) {
F_166 ( L_16 , V_248 ) ;
V_7 = - V_31 ;
goto V_249;
}
#endif
F_167 ( V_250 , V_251 , NULL ,
V_252 , NULL ) ;
return 0 ;
#ifdef F_28
V_249:
F_168 ( & V_245 ) ;
#endif
V_246:
F_169 ( & V_243 ) ;
V_244:
F_170 ( V_163 ) ;
return V_7 ;
}
void F_171 ( void )
{
F_172 ( V_250 , V_251 ) ;
#ifdef F_28
F_173 ( & V_247 , V_120 ) ;
#endif
F_168 ( & V_245 ) ;
F_169 ( & V_243 ) ;
F_170 ( V_163 ) ;
}
static int F_174 ( struct V_2 * V_2 , struct V_1 * V_4 ,
struct V_225 * V_64 , int V_186 , int V_226 )
{
bool V_221 = false ;
int line ;
struct V_60 * V_208 , * V_162 ;
unsigned char V_100 [ V_182 ] ;
int V_52 ;
if ( V_64 -> V_253 >= V_182 )
return - V_254 ;
memset ( V_100 , 255 , V_182 ) ;
for ( V_52 = 0 ; V_52 < V_182 ; V_52 ++ ) {
if ( F_175 ( V_52 , & V_64 -> V_255 ) )
V_100 [ V_52 ] = 1 ;
}
line = F_120 ( & V_64 -> V_227 . V_228 , & V_64 -> V_229 . V_228 ) ;
F_36 (c, &mrt->mfc6_cache_array[line], list) {
if ( F_121 ( & V_162 -> V_93 , & V_64 -> V_229 . V_228 ) &&
F_121 ( & V_162 -> V_92 ,
& V_64 -> V_227 . V_228 ) &&
( V_226 == - 1 || V_226 == V_64 -> V_253 ) ) {
V_221 = true ;
break;
}
}
if ( V_221 ) {
F_92 ( & V_65 ) ;
V_162 -> V_94 = V_64 -> V_253 ;
F_115 ( V_4 , V_162 , V_100 ) ;
if ( ! V_186 )
V_162 -> V_256 |= V_257 ;
F_93 ( & V_65 ) ;
F_111 ( V_4 , V_162 , V_223 ) ;
return 0 ;
}
if ( ! F_123 ( & V_64 -> V_227 . V_228 ) &&
! F_71 ( & V_64 -> V_227 . V_228 ) )
return - V_28 ;
V_162 = F_125 () ;
if ( ! V_162 )
return - V_46 ;
V_162 -> V_93 = V_64 -> V_229 . V_228 ;
V_162 -> V_92 = V_64 -> V_227 . V_228 ;
V_162 -> V_94 = V_64 -> V_253 ;
F_115 ( V_4 , V_162 , V_100 ) ;
if ( ! V_186 )
V_162 -> V_256 |= V_257 ;
F_92 ( & V_65 ) ;
F_149 ( & V_162 -> V_50 , & V_4 -> V_55 [ line ] ) ;
F_93 ( & V_65 ) ;
V_221 = false ;
F_38 ( & V_68 ) ;
F_36 (uc, &mrt->mfc6_unres_queue, list) {
if ( F_121 ( & V_208 -> V_93 , & V_162 -> V_93 ) &&
F_121 ( & V_208 -> V_92 , & V_162 -> V_92 ) ) {
F_23 ( & V_208 -> V_50 ) ;
F_102 ( & V_4 -> V_164 ) ;
V_221 = true ;
break;
}
}
if ( F_56 ( & V_4 -> V_56 ) )
F_176 ( & V_4 -> V_57 ) ;
F_39 ( & V_68 ) ;
if ( V_221 ) {
F_129 ( V_2 , V_4 , V_208 , V_162 ) ;
F_98 ( V_208 ) ;
}
F_111 ( V_4 , V_162 , V_223 ) ;
return 0 ;
}
static void F_32 ( struct V_1 * V_4 , bool V_258 )
{
int V_52 ;
F_154 ( V_50 ) ;
struct V_60 * V_162 , * V_49 ;
for ( V_52 = 0 ; V_52 < V_4 -> V_72 ; V_52 ++ ) {
if ( ! V_258 && ( V_4 -> V_73 [ V_52 ] . V_13 & V_194 ) )
continue;
F_91 ( V_4 , V_52 , & V_50 ) ;
}
F_155 ( & V_50 ) ;
for ( V_52 = 0 ; V_52 < V_54 ; V_52 ++ ) {
F_22 (c, next, &mrt->mfc6_cache_array[i], list) {
if ( ! V_258 && ( V_162 -> V_256 & V_257 ) )
continue;
F_92 ( & V_65 ) ;
F_23 ( & V_162 -> V_50 ) ;
F_93 ( & V_65 ) ;
F_111 ( V_4 , V_162 , V_181 ) ;
F_98 ( V_162 ) ;
}
}
if ( F_147 ( & V_4 -> V_164 ) != 0 ) {
F_38 ( & V_68 ) ;
F_22 (c, next, &mrt->mfc6_unres_queue, list) {
F_23 ( & V_162 -> V_50 ) ;
F_111 ( V_4 , V_162 , V_181 ) ;
F_100 ( V_4 , V_162 ) ;
}
F_39 ( & V_68 ) ;
}
}
static int F_177 ( struct V_1 * V_4 , struct V_259 * V_260 )
{
int V_7 = 0 ;
struct V_2 * V_2 = F_178 ( V_260 ) ;
F_21 () ;
F_92 ( & V_65 ) ;
if ( F_179 ( V_4 -> V_220 == NULL ) ) {
V_4 -> V_220 = V_260 ;
V_2 -> V_15 . V_261 -> V_159 ++ ;
} else {
V_7 = - V_188 ;
}
F_93 ( & V_65 ) ;
if ( ! V_7 )
F_96 ( V_2 , V_160 ,
V_262 ,
V_2 -> V_15 . V_261 ) ;
F_24 () ;
return V_7 ;
}
int F_180 ( struct V_259 * V_260 )
{
int V_7 = - V_26 ;
struct V_2 * V_2 = F_178 ( V_260 ) ;
struct V_1 * V_4 ;
F_21 () ;
F_2 (mrt, net) {
if ( V_260 == V_4 -> V_220 ) {
F_92 ( & V_65 ) ;
V_4 -> V_220 = NULL ;
V_2 -> V_15 . V_261 -> V_159 -- ;
F_93 ( & V_65 ) ;
F_96 ( V_2 ,
V_160 ,
V_262 ,
V_2 -> V_15 . V_261 ) ;
F_32 ( V_4 , false ) ;
V_7 = 0 ;
break;
}
}
F_24 () ;
return V_7 ;
}
struct V_259 * F_181 ( struct V_2 * V_2 , struct V_32 * V_33 )
{
struct V_1 * V_4 ;
struct V_5 V_108 = {
. V_109 = V_33 -> V_132 ? : V_133 ,
. V_131 = V_33 -> V_82 -> V_110 ,
. V_111 = V_33 -> V_112 ,
} ;
if ( F_3 ( V_2 , & V_108 , & V_4 ) < 0 )
return NULL ;
return V_4 -> V_220 ;
}
int F_182 ( struct V_259 * V_260 , int V_263 , char T_8 * V_264 , unsigned int V_265 )
{
int V_212 , V_226 = 0 ;
struct V_184 V_80 ;
struct V_225 V_64 ;
T_6 V_201 ;
struct V_2 * V_2 = F_178 ( V_260 ) ;
struct V_1 * V_4 ;
V_4 = F_1 ( V_2 , F_183 ( V_260 ) -> V_266 ? : V_45 ) ;
if ( ! V_4 )
return - V_77 ;
if ( V_263 != V_267 ) {
if ( V_260 != V_4 -> V_220 && ! F_184 ( V_2 -> V_268 , V_269 ) )
return - V_26 ;
}
switch ( V_263 ) {
case V_267 :
if ( V_260 -> V_270 != V_271 ||
F_185 ( V_260 ) -> V_272 != V_273 )
return - V_274 ;
if ( V_265 < sizeof( int ) )
return - V_28 ;
return F_177 ( V_4 , V_260 ) ;
case V_275 :
return F_180 ( V_260 ) ;
case V_276 :
if ( V_265 < sizeof( V_80 ) )
return - V_28 ;
if ( F_186 ( & V_80 , V_264 , sizeof( V_80 ) ) )
return - V_277 ;
if ( V_80 . V_187 >= V_182 )
return - V_254 ;
F_21 () ;
V_212 = F_116 ( V_2 , V_4 , & V_80 , V_260 == V_4 -> V_220 ) ;
F_24 () ;
return V_212 ;
case V_278 :
if ( V_265 < sizeof( T_6 ) )
return - V_28 ;
if ( F_186 ( & V_201 , V_264 , sizeof( T_6 ) ) )
return - V_277 ;
F_21 () ;
V_212 = F_91 ( V_4 , V_201 , NULL ) ;
F_24 () ;
return V_212 ;
case V_279 :
case V_280 :
V_226 = - 1 ;
case V_281 :
case V_282 :
if ( V_265 < sizeof( V_64 ) )
return - V_28 ;
if ( F_186 ( & V_64 , V_264 , sizeof( V_64 ) ) )
return - V_277 ;
if ( V_226 == 0 )
V_226 = V_64 . V_253 ;
F_21 () ;
if ( V_263 == V_280 || V_263 == V_282 )
V_212 = F_151 ( V_4 , & V_64 , V_226 ) ;
else
V_212 = F_174 ( V_2 , V_4 , & V_64 ,
V_260 == V_4 -> V_220 , V_226 ) ;
F_24 () ;
return V_212 ;
case V_283 :
{
int V_79 ;
if ( V_265 != sizeof( V_79 ) )
return - V_28 ;
if ( F_187 ( V_79 , ( int T_8 * ) V_264 ) )
return - V_277 ;
V_4 -> V_284 = V_79 ;
return 0 ;
}
#ifdef F_28
case V_285 :
{
int V_79 ;
if ( V_265 != sizeof( V_79 ) )
return - V_28 ;
if ( F_187 ( V_79 , ( int T_8 * ) V_264 ) )
return - V_277 ;
V_79 = ! ! V_79 ;
F_21 () ;
V_212 = 0 ;
if ( V_79 != V_4 -> V_286 ) {
V_4 -> V_286 = V_79 ;
V_4 -> V_284 = V_79 ;
}
F_24 () ;
return V_212 ;
}
#endif
#ifdef F_29
case V_287 :
{
T_1 V_79 ;
if ( V_265 != sizeof( T_1 ) )
return - V_28 ;
if ( F_187 ( V_79 , ( T_1 T_8 * ) V_264 ) )
return - V_277 ;
if ( V_79 != V_288 && V_79 >= 100000000 )
return - V_28 ;
if ( V_260 == V_4 -> V_220 )
return - V_289 ;
F_21 () ;
V_212 = 0 ;
if ( ! F_16 ( V_2 , V_79 ) )
V_212 = - V_46 ;
F_183 ( V_260 ) -> V_266 = V_79 ;
F_24 () ;
return V_212 ;
}
#endif
default:
return - V_290 ;
}
}
int F_188 ( struct V_259 * V_260 , int V_263 , char T_8 * V_264 ,
int T_8 * V_265 )
{
int V_291 ;
int V_292 ;
struct V_2 * V_2 = F_178 ( V_260 ) ;
struct V_1 * V_4 ;
V_4 = F_1 ( V_2 , F_183 ( V_260 ) -> V_266 ? : V_45 ) ;
if ( ! V_4 )
return - V_77 ;
switch ( V_263 ) {
case V_293 :
V_292 = 0x0305 ;
break;
#ifdef F_28
case V_285 :
V_292 = V_4 -> V_286 ;
break;
#endif
case V_283 :
V_292 = V_4 -> V_284 ;
break;
default:
return - V_290 ;
}
if ( F_187 ( V_291 , V_265 ) )
return - V_277 ;
V_291 = F_189 ( int , V_291 , sizeof( int ) ) ;
if ( V_291 < 0 )
return - V_28 ;
if ( F_190 ( V_291 , V_265 ) )
return - V_277 ;
if ( F_191 ( V_264 , & V_292 , V_291 ) )
return - V_277 ;
return 0 ;
}
int F_192 ( struct V_259 * V_260 , int V_294 , void T_8 * V_11 )
{
struct V_295 V_296 ;
struct V_297 V_298 ;
struct V_69 * V_80 ;
struct V_60 * V_162 ;
struct V_2 * V_2 = F_178 ( V_260 ) ;
struct V_1 * V_4 ;
V_4 = F_1 ( V_2 , F_183 ( V_260 ) -> V_266 ? : V_45 ) ;
if ( ! V_4 )
return - V_77 ;
switch ( V_294 ) {
case V_299 :
if ( F_186 ( & V_298 , V_11 , sizeof( V_298 ) ) )
return - V_277 ;
if ( V_298 . V_201 >= V_4 -> V_72 )
return - V_28 ;
F_35 ( & V_65 ) ;
V_80 = & V_4 -> V_73 [ V_298 . V_201 ] ;
if ( F_41 ( V_4 , V_298 . V_201 ) ) {
V_298 . V_300 = V_80 -> V_84 ;
V_298 . V_301 = V_80 -> V_86 ;
V_298 . V_302 = V_80 -> V_83 ;
V_298 . V_303 = V_80 -> V_85 ;
F_37 ( & V_65 ) ;
if ( F_191 ( V_11 , & V_298 , sizeof( V_298 ) ) )
return - V_277 ;
return 0 ;
}
F_37 ( & V_65 ) ;
return - V_156 ;
case V_304 :
if ( F_186 ( & V_296 , V_11 , sizeof( V_296 ) ) )
return - V_277 ;
F_35 ( & V_65 ) ;
V_162 = F_119 ( V_4 , & V_296 . V_305 . V_228 , & V_296 . V_306 . V_228 ) ;
if ( V_162 ) {
V_296 . V_307 = V_162 -> V_95 . V_9 . V_96 ;
V_296 . V_308 = V_162 -> V_95 . V_9 . V_97 ;
V_296 . V_98 = V_162 -> V_95 . V_9 . V_98 ;
F_37 ( & V_65 ) ;
if ( F_191 ( V_11 , & V_296 , sizeof( V_296 ) ) )
return - V_277 ;
return 0 ;
}
F_37 ( & V_65 ) ;
return - V_156 ;
default:
return - V_309 ;
}
}
int F_193 ( struct V_259 * V_260 , unsigned int V_294 , void T_8 * V_11 )
{
struct V_310 V_296 ;
struct V_311 V_298 ;
struct V_69 * V_80 ;
struct V_60 * V_162 ;
struct V_2 * V_2 = F_178 ( V_260 ) ;
struct V_1 * V_4 ;
V_4 = F_1 ( V_2 , F_183 ( V_260 ) -> V_266 ? : V_45 ) ;
if ( ! V_4 )
return - V_77 ;
switch ( V_294 ) {
case V_299 :
if ( F_186 ( & V_298 , V_11 , sizeof( V_298 ) ) )
return - V_277 ;
if ( V_298 . V_201 >= V_4 -> V_72 )
return - V_28 ;
F_35 ( & V_65 ) ;
V_80 = & V_4 -> V_73 [ V_298 . V_201 ] ;
if ( F_41 ( V_4 , V_298 . V_201 ) ) {
V_298 . V_300 = V_80 -> V_84 ;
V_298 . V_301 = V_80 -> V_86 ;
V_298 . V_302 = V_80 -> V_83 ;
V_298 . V_303 = V_80 -> V_85 ;
F_37 ( & V_65 ) ;
if ( F_191 ( V_11 , & V_298 , sizeof( V_298 ) ) )
return - V_277 ;
return 0 ;
}
F_37 ( & V_65 ) ;
return - V_156 ;
case V_304 :
if ( F_186 ( & V_296 , V_11 , sizeof( V_296 ) ) )
return - V_277 ;
F_35 ( & V_65 ) ;
V_162 = F_119 ( V_4 , & V_296 . V_305 . V_228 , & V_296 . V_306 . V_228 ) ;
if ( V_162 ) {
V_296 . V_307 = V_162 -> V_95 . V_9 . V_96 ;
V_296 . V_308 = V_162 -> V_95 . V_9 . V_97 ;
V_296 . V_98 = V_162 -> V_95 . V_9 . V_98 ;
F_37 ( & V_65 ) ;
if ( F_191 ( V_11 , & V_296 , sizeof( V_296 ) ) )
return - V_277 ;
return 0 ;
}
F_37 ( & V_65 ) ;
return - V_156 ;
default:
return - V_309 ;
}
}
static inline int F_194 ( struct V_2 * V_2 , struct V_259 * V_260 , struct V_32 * V_33 )
{
F_195 ( V_2 , F_196 ( F_143 ( V_33 ) ) ,
V_312 ) ;
F_197 ( V_2 , F_196 ( F_143 ( V_33 ) ) ,
V_313 , V_33 -> V_121 ) ;
return F_198 ( V_2 , V_260 , V_33 ) ;
}
static int F_199 ( struct V_2 * V_2 , struct V_1 * V_4 ,
struct V_32 * V_33 , struct V_60 * V_162 , int V_151 )
{
struct V_104 * V_314 ;
struct V_69 * V_80 = & V_4 -> V_73 [ V_151 ] ;
struct V_106 * V_82 ;
struct V_315 * V_316 ;
struct V_5 V_108 ;
if ( ! V_80 -> V_82 )
goto V_317;
#ifdef F_28
if ( V_80 -> V_13 & V_161 ) {
V_80 -> V_86 ++ ;
V_80 -> V_85 += V_33 -> V_121 ;
V_80 -> V_82 -> V_134 . V_135 += V_33 -> V_121 ;
V_80 -> V_82 -> V_134 . V_136 ++ ;
F_82 ( V_4 , V_33 , V_151 , V_137 ) ;
goto V_317;
}
#endif
V_314 = F_67 ( V_33 ) ;
V_108 = (struct V_5 ) {
. V_131 = V_80 -> V_197 ,
. V_119 = V_314 -> V_119 ,
} ;
V_316 = F_200 ( V_2 , NULL , & V_108 ) ;
if ( V_316 -> error ) {
F_201 ( V_316 ) ;
goto V_317;
}
F_202 ( V_33 ) ;
F_141 ( V_33 , V_316 ) ;
V_82 = V_80 -> V_82 ;
V_33 -> V_82 = V_82 ;
V_80 -> V_86 ++ ;
V_80 -> V_85 += V_33 -> V_121 ;
if ( F_203 ( V_33 , sizeof( * V_314 ) + F_204 ( V_82 ) ) )
goto V_317;
V_314 = F_67 ( V_33 ) ;
V_314 -> V_318 -- ;
F_205 ( V_33 ) -> V_13 |= V_319 ;
return F_206 ( V_320 , V_321 ,
V_2 , NULL , V_33 , V_33 -> V_82 , V_82 ,
F_194 ) ;
V_317:
F_80 ( V_33 ) ;
return 0 ;
}
static int F_207 ( struct V_1 * V_4 , struct V_106 * V_82 )
{
int V_66 ;
for ( V_66 = V_4 -> V_72 - 1 ; V_66 >= 0 ; V_66 -- ) {
if ( V_4 -> V_73 [ V_66 ] . V_82 == V_82 )
break;
}
return V_66 ;
}
static void F_133 ( struct V_2 * V_2 , struct V_1 * V_4 ,
struct V_32 * V_33 , struct V_60 * V_67 )
{
int V_322 = - 1 ;
int V_80 , V_66 ;
int V_323 = F_207 ( V_4 , V_33 -> V_82 ) ;
V_80 = V_67 -> V_94 ;
V_67 -> V_95 . V_9 . V_96 ++ ;
V_67 -> V_95 . V_9 . V_97 += V_33 -> V_121 ;
V_67 -> V_95 . V_9 . V_183 = V_177 ;
if ( F_123 ( & V_67 -> V_93 ) && V_323 >= 0 ) {
struct V_60 * V_324 ;
V_324 = F_122 ( V_4 , V_80 ) ;
if ( V_324 &&
V_324 -> V_95 . V_9 . V_100 [ V_323 ] < 255 )
goto V_325;
}
if ( V_4 -> V_73 [ V_80 ] . V_82 != V_33 -> V_82 ) {
V_67 -> V_95 . V_9 . V_98 ++ ;
if ( V_323 >= 0 && V_4 -> V_284 &&
( V_4 -> V_286 ||
V_67 -> V_95 . V_9 . V_100 [ V_323 ] < 255 ) &&
F_110 ( V_177 ,
V_67 -> V_95 . V_9 . V_205 + V_206 ) ) {
V_67 -> V_95 . V_9 . V_205 = V_177 ;
F_82 ( V_4 , V_33 , V_323 , V_326 ) ;
}
goto V_327;
}
V_325:
V_4 -> V_73 [ V_80 ] . V_84 ++ ;
V_4 -> V_73 [ V_80 ] . V_83 += V_33 -> V_121 ;
if ( F_123 ( & V_67 -> V_93 ) &&
F_123 ( & V_67 -> V_92 ) ) {
if ( V_323 >= 0 &&
V_323 != V_67 -> V_94 &&
F_67 ( V_33 ) -> V_318 >
V_67 -> V_95 . V_9 . V_100 [ V_67 -> V_94 ] ) {
V_322 = V_67 -> V_94 ;
goto V_328;
}
goto V_327;
}
for ( V_66 = V_67 -> V_95 . V_9 . V_72 - 1 ; V_66 >= V_67 -> V_95 . V_9 . V_99 ; V_66 -- ) {
if ( ( ! F_123 ( & V_67 -> V_93 ) || V_66 != V_323 ) &&
F_67 ( V_33 ) -> V_318 > V_67 -> V_95 . V_9 . V_100 [ V_66 ] ) {
if ( V_322 != - 1 ) {
struct V_32 * V_329 = F_208 ( V_33 , V_207 ) ;
if ( V_329 )
F_199 ( V_2 , V_4 , V_329 , V_67 , V_322 ) ;
}
V_322 = V_66 ;
}
}
V_328:
if ( V_322 != - 1 ) {
F_199 ( V_2 , V_4 , V_33 , V_67 , V_322 ) ;
return;
}
V_327:
F_80 ( V_33 ) ;
}
int F_209 ( struct V_32 * V_33 )
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
V_67 = F_119 ( V_4 ,
& F_67 ( V_33 ) -> V_118 , & F_67 ( V_33 ) -> V_119 ) ;
if ( ! V_67 ) {
int V_80 = F_207 ( V_4 , V_33 -> V_82 ) ;
if ( V_80 >= 0 )
V_67 = F_124 ( V_4 ,
& F_67 ( V_33 ) -> V_119 ,
V_80 ) ;
}
if ( ! V_67 ) {
int V_80 ;
V_80 = F_207 ( V_4 , V_33 -> V_82 ) ;
if ( V_80 >= 0 ) {
int V_7 = F_146 ( V_4 , V_80 , V_33 ) ;
F_37 ( & V_65 ) ;
return V_7 ;
}
F_37 ( & V_65 ) ;
F_80 ( V_33 ) ;
return - V_330 ;
}
F_133 ( V_2 , V_4 , V_33 , V_67 ) ;
F_37 ( & V_65 ) ;
return 0 ;
}
static int F_131 ( struct V_1 * V_4 , struct V_32 * V_33 ,
struct V_60 * V_162 , struct V_331 * V_332 )
{
struct V_333 V_334 ;
struct V_36 * V_335 ;
struct V_336 * V_337 ;
unsigned long V_183 ;
int V_66 ;
if ( V_162 -> V_94 >= V_182 )
return - V_77 ;
if ( F_41 ( V_4 , V_162 -> V_94 ) &&
F_210 ( V_33 , V_338 , V_4 -> V_73 [ V_162 -> V_94 ] . V_82 -> V_110 ) < 0 )
return - V_209 ;
V_335 = F_211 ( V_33 , V_339 ) ;
if ( ! V_335 )
return - V_209 ;
for ( V_66 = V_162 -> V_95 . V_9 . V_99 ; V_66 < V_162 -> V_95 . V_9 . V_72 ; V_66 ++ ) {
if ( F_41 ( V_4 , V_66 ) && V_162 -> V_95 . V_9 . V_100 [ V_66 ] < 255 ) {
V_337 = F_212 ( V_33 , sizeof( * V_337 ) ) ;
if ( ! V_337 ) {
F_213 ( V_33 , V_335 ) ;
return - V_209 ;
}
V_337 -> V_340 = 0 ;
V_337 -> V_341 = V_162 -> V_95 . V_9 . V_100 [ V_66 ] ;
V_337 -> V_342 = V_4 -> V_73 [ V_66 ] . V_82 -> V_110 ;
V_337 -> V_343 = sizeof( * V_337 ) ;
}
}
F_214 ( V_33 , V_335 ) ;
V_183 = F_215 ( V_162 -> V_95 . V_9 . V_183 ) ;
V_183 = F_216 ( V_177 , V_183 ) ? V_177 - V_183 : 0 ;
V_334 . V_344 = V_162 -> V_95 . V_9 . V_96 ;
V_334 . V_345 = V_162 -> V_95 . V_9 . V_97 ;
V_334 . V_346 = V_162 -> V_95 . V_9 . V_98 ;
if ( F_217 ( V_33 , V_347 , sizeof( V_334 ) , & V_334 , V_348 ) ||
F_218 ( V_33 , V_349 , F_219 ( V_183 ) ,
V_348 ) )
return - V_209 ;
V_332 -> V_350 = V_351 ;
return 1 ;
}
int F_220 ( struct V_2 * V_2 , struct V_32 * V_33 , struct V_331 * V_332 ,
int V_352 , T_1 V_175 )
{
int V_7 ;
struct V_1 * V_4 ;
struct V_60 * V_67 ;
struct V_353 * V_354 = (struct V_353 * ) F_143 ( V_33 ) ;
V_4 = F_1 ( V_2 , V_45 ) ;
if ( ! V_4 )
return - V_77 ;
F_35 ( & V_65 ) ;
V_67 = F_119 ( V_4 , & V_354 -> V_355 . V_356 , & V_354 -> V_357 . V_356 ) ;
if ( ! V_67 && V_33 -> V_82 ) {
int V_80 = F_207 ( V_4 , V_33 -> V_82 ) ;
if ( V_80 >= 0 )
V_67 = F_124 ( V_4 , & V_354 -> V_357 . V_356 ,
V_80 ) ;
}
if ( ! V_67 ) {
struct V_32 * V_329 ;
struct V_104 * V_358 ;
struct V_106 * V_82 ;
int V_80 ;
if ( V_352 ) {
F_37 ( & V_65 ) ;
return - V_31 ;
}
V_82 = V_33 -> V_82 ;
if ( ! V_82 || ( V_80 = F_207 ( V_4 , V_82 ) ) < 0 ) {
F_37 ( & V_65 ) ;
return - V_330 ;
}
V_329 = F_136 ( sizeof( struct V_104 ) , V_207 ) ;
if ( ! V_329 ) {
F_37 ( & V_65 ) ;
return - V_46 ;
}
F_108 ( V_329 ) . V_175 = V_175 ;
F_138 ( V_329 ) ;
F_139 ( V_329 , sizeof( struct V_104 ) ) ;
F_75 ( V_329 ) ;
V_358 = F_67 ( V_329 ) ;
V_358 -> V_167 = 0 ;
V_358 -> V_359 = 0 ;
V_358 -> V_360 [ 0 ] = 0 ;
V_358 -> V_360 [ 1 ] = 0 ;
V_358 -> V_360 [ 2 ] = 0 ;
V_358 -> V_122 = 0 ;
V_358 -> V_361 = V_362 ;
V_358 -> V_318 = 0 ;
V_358 -> V_118 = V_354 -> V_355 . V_356 ;
V_358 -> V_119 = V_354 -> V_357 . V_356 ;
V_7 = F_146 ( V_4 , V_80 , V_329 ) ;
F_37 ( & V_65 ) ;
return V_7 ;
}
if ( ! V_352 && ( V_332 -> V_363 & V_364 ) )
V_67 -> V_256 |= V_365 ;
V_7 = F_131 ( V_4 , V_33 , V_67 , V_332 ) ;
F_37 ( & V_65 ) ;
return V_7 ;
}
static int F_221 ( struct V_1 * V_4 , struct V_32 * V_33 ,
T_1 V_175 , T_1 V_75 , struct V_60 * V_162 , int V_294 ,
int V_13 )
{
struct V_168 * V_169 ;
struct V_331 * V_332 ;
int V_7 ;
V_169 = F_222 ( V_33 , V_175 , V_75 , V_294 , sizeof( * V_332 ) , V_13 ) ;
if ( ! V_169 )
return - V_209 ;
V_332 = F_106 ( V_169 ) ;
V_332 -> V_366 = V_250 ;
V_332 -> V_367 = 128 ;
V_332 -> V_368 = 128 ;
V_332 -> V_369 = 0 ;
V_332 -> V_370 = V_4 -> V_3 ;
if ( F_210 ( V_33 , V_371 , V_4 -> V_3 ) )
goto V_372;
V_332 -> V_350 = V_351 ;
V_332 -> V_373 = V_374 ;
if ( V_162 -> V_256 & V_257 )
V_332 -> V_375 = V_376 ;
else
V_332 -> V_375 = V_377 ;
V_332 -> V_363 = 0 ;
if ( F_223 ( V_33 , V_378 , & V_162 -> V_93 ) ||
F_223 ( V_33 , V_379 , & V_162 -> V_92 ) )
goto V_372;
V_7 = F_131 ( V_4 , V_33 , V_162 , V_332 ) ;
if ( V_7 < 0 && V_7 != - V_77 )
goto V_372;
F_224 ( V_33 , V_169 ) ;
return 0 ;
V_372:
F_225 ( V_33 , V_169 ) ;
return - V_209 ;
}
static int F_226 ( bool V_166 , int V_72 )
{
T_9 V_121 =
F_227 ( sizeof( struct V_331 ) )
+ F_228 ( 4 )
+ F_228 ( sizeof( struct V_198 ) )
+ F_228 ( sizeof( struct V_198 ) )
;
if ( ! V_166 )
V_121 = V_121
+ F_228 ( 4 )
+ F_228 ( 0 )
+ V_72 * F_229 ( sizeof( struct V_336 ) )
+ F_230 ( sizeof( struct V_333 ) )
;
return V_121 ;
}
static void F_111 ( struct V_1 * V_4 , struct V_60 * V_64 ,
int V_294 )
{
struct V_2 * V_2 = F_101 ( & V_4 -> V_2 ) ;
struct V_32 * V_33 ;
int V_7 = - V_190 ;
V_33 = F_231 ( F_226 ( V_64 -> V_94 >= V_182 , V_4 -> V_72 ) ,
V_207 ) ;
if ( ! V_33 )
goto V_380;
V_7 = F_221 ( V_4 , V_33 , 0 , 0 , V_64 , V_294 , 0 ) ;
if ( V_7 < 0 )
goto V_380;
F_232 ( V_33 , V_2 , 0 , V_381 , NULL , V_207 ) ;
return;
V_380:
F_80 ( V_33 ) ;
if ( V_7 < 0 )
F_233 ( V_2 , V_381 , V_7 ) ;
}
static int V_252 ( struct V_32 * V_33 , struct V_382 * V_383 )
{
struct V_2 * V_2 = F_178 ( V_33 -> V_260 ) ;
struct V_1 * V_4 ;
struct V_60 * V_64 ;
unsigned int V_384 = 0 , V_385 ;
unsigned int V_386 = 0 , V_387 ;
unsigned int V_388 = 0 , V_389 ;
V_385 = V_383 -> args [ 0 ] ;
V_387 = V_383 -> args [ 1 ] ;
V_389 = V_383 -> args [ 2 ] ;
F_35 ( & V_65 ) ;
F_2 (mrt, net) {
if ( V_384 < V_385 )
goto V_390;
if ( V_384 > V_385 )
V_387 = 0 ;
for ( V_386 = V_387 ; V_386 < V_54 ; V_386 ++ ) {
F_36 (mfc, &mrt->mfc6_cache_array[h], list) {
if ( V_388 < V_389 )
goto V_391;
if ( F_221 ( V_4 , V_33 ,
F_108 ( V_383 -> V_33 ) . V_175 ,
V_383 -> V_169 -> V_392 ,
V_64 , V_223 ,
V_393 ) < 0 )
goto V_394;
V_391:
V_388 ++ ;
}
V_388 = V_389 = 0 ;
}
F_38 ( & V_68 ) ;
F_36 (mfc, &mrt->mfc6_unres_queue, list) {
if ( V_388 < V_389 )
goto V_395;
if ( F_221 ( V_4 , V_33 ,
F_108 ( V_383 -> V_33 ) . V_175 ,
V_383 -> V_169 -> V_392 ,
V_64 , V_223 ,
V_393 ) < 0 ) {
F_39 ( & V_68 ) ;
goto V_394;
}
V_395:
V_388 ++ ;
}
F_39 ( & V_68 ) ;
V_388 = V_389 = 0 ;
V_387 = 0 ;
V_390:
V_384 ++ ;
}
V_394:
F_37 ( & V_65 ) ;
V_383 -> args [ 2 ] = V_388 ;
V_383 -> args [ 1 ] = V_386 ;
V_383 -> args [ 0 ] = V_384 ;
return V_33 -> V_121 ;
}
