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
}
static int F_116 ( struct V_2 * V_2 , struct V_1 * V_4 ,
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
#ifdef F_28
case V_161 :
if ( V_4 -> V_59 >= 0 )
return - V_187 ;
V_82 = F_85 ( V_2 , V_4 ) ;
if ( ! V_82 )
return - V_189 ;
V_7 = F_94 ( V_82 , 1 ) ;
if ( V_7 ) {
F_90 ( V_82 ) ;
F_79 ( V_82 ) ;
return V_7 ;
}
break;
#endif
case 0 :
V_82 = F_117 ( V_2 , V_184 -> V_190 ) ;
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
V_79 -> V_196 = F_118 ( V_82 ) ;
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
const struct V_197 * V_198 ,
const struct V_197 * V_199 )
{
int line = F_120 ( V_199 , V_198 ) ;
struct V_60 * V_162 ;
F_36 (c, &mrt->mfc6_cache_array[line], list) {
if ( F_121 ( & V_162 -> V_93 , V_198 ) &&
F_121 ( & V_162 -> V_92 , V_199 ) )
return V_162 ;
}
return NULL ;
}
static struct V_60 * F_122 ( struct V_1 * V_4 ,
T_6 V_200 )
{
int line = F_120 ( & V_201 , & V_201 ) ;
struct V_60 * V_162 ;
F_36 (c, &mrt->mfc6_cache_array[line], list)
if ( F_123 ( & V_162 -> V_93 ) &&
F_123 ( & V_162 -> V_92 ) &&
( V_162 -> V_95 . V_9 . V_100 [ V_200 ] < 255 ) )
return V_162 ;
return NULL ;
}
static struct V_60 * F_124 ( struct V_1 * V_4 ,
struct V_197 * V_199 ,
T_6 V_200 )
{
int line = F_120 ( V_199 , & V_201 ) ;
struct V_60 * V_162 , * V_202 ;
if ( F_123 ( V_199 ) )
goto V_203;
F_36 (c, &mrt->mfc6_cache_array[line], list)
if ( F_123 ( & V_162 -> V_93 ) &&
F_121 ( & V_162 -> V_92 , V_199 ) ) {
if ( V_162 -> V_95 . V_9 . V_100 [ V_200 ] < 255 )
return V_162 ;
V_202 = F_122 ( V_4 ,
V_162 -> V_94 ) ;
if ( V_202 && V_202 -> V_95 . V_9 . V_100 [ V_200 ] < 255 )
return V_162 ;
}
V_203:
return F_122 ( V_4 , V_200 ) ;
}
static struct V_60 * F_125 ( void )
{
struct V_60 * V_162 = F_126 ( V_163 , V_53 ) ;
if ( ! V_162 )
return NULL ;
V_162 -> V_95 . V_9 . V_204 = V_177 - V_205 - 1 ;
V_162 -> V_95 . V_9 . V_99 = V_182 ;
return V_162 ;
}
static struct V_60 * F_127 ( void )
{
struct V_60 * V_162 = F_126 ( V_163 , V_206 ) ;
if ( ! V_162 )
return NULL ;
F_128 ( & V_162 -> V_95 . V_165 . V_166 ) ;
V_162 -> V_95 . V_165 . V_178 = V_177 + 10 * V_179 ;
return V_162 ;
}
static void F_129 ( struct V_2 * V_2 , struct V_1 * V_4 ,
struct V_60 * V_207 , struct V_60 * V_162 )
{
struct V_32 * V_33 ;
while ( ( V_33 = F_130 ( & V_207 -> V_95 . V_165 . V_166 ) ) ) {
if ( F_67 ( V_33 ) -> V_167 == 0 ) {
struct V_168 * V_169 = (struct V_168 * ) F_74 ( V_33 , sizeof( struct V_104 ) ) ;
if ( F_131 ( V_4 , V_33 , V_162 , F_106 ( V_169 ) ) > 0 ) {
V_169 -> V_172 = F_132 ( V_33 ) - ( V_125 * ) V_169 ;
} else {
V_169 -> V_170 = V_171 ;
V_169 -> V_172 = F_104 ( sizeof( struct V_173 ) ) ;
F_105 ( V_33 , V_169 -> V_172 ) ;
( (struct V_173 * ) F_106 ( V_169 ) ) -> error = - V_208 ;
}
F_107 ( V_33 , V_2 , F_108 ( V_33 ) . V_175 ) ;
} else
F_133 ( V_2 , V_4 , V_33 , V_162 ) ;
}
}
static int F_82 ( struct V_1 * V_4 , struct V_32 * V_96 ,
T_6 V_200 , int assert )
{
struct V_32 * V_33 ;
struct V_209 * V_210 ;
int V_211 ;
#ifdef F_28
if ( assert == V_137 )
V_33 = F_134 ( V_96 , - F_135 ( V_96 )
+ sizeof( * V_210 ) ) ;
else
#endif
V_33 = F_136 ( sizeof( struct V_104 ) + sizeof( * V_210 ) , V_206 ) ;
if ( ! V_33 )
return - V_189 ;
V_33 -> V_129 = V_212 ;
#ifdef F_28
if ( assert == V_137 ) {
F_137 ( V_33 , - F_135 ( V_96 ) ) ;
F_137 ( V_33 , sizeof( * V_210 ) ) ;
F_138 ( V_33 ) ;
V_210 = (struct V_209 * ) F_65 ( V_33 ) ;
V_210 -> V_213 = 0 ;
V_210 -> V_214 = V_137 ;
V_210 -> V_215 = V_4 -> V_59 ;
V_210 -> V_216 = 0 ;
V_210 -> V_217 = F_67 ( V_96 ) -> V_118 ;
V_210 -> V_218 = F_67 ( V_96 ) -> V_119 ;
V_33 -> V_129 = V_212 ;
} else
#endif
{
F_139 ( V_33 , sizeof( struct V_104 ) ) ;
F_75 ( V_33 ) ;
F_140 ( V_33 , F_67 ( V_96 ) , sizeof( struct V_104 ) ) ;
F_139 ( V_33 , sizeof( * V_210 ) ) ;
F_138 ( V_33 ) ;
V_210 = (struct V_209 * ) F_65 ( V_33 ) ;
V_210 -> V_213 = 0 ;
V_210 -> V_214 = assert ;
V_210 -> V_215 = V_200 ;
V_210 -> V_216 = 0 ;
V_210 -> V_217 = F_67 ( V_96 ) -> V_118 ;
V_210 -> V_218 = F_67 ( V_96 ) -> V_119 ;
F_141 ( V_33 , F_142 ( F_143 ( V_96 ) ) ) ;
V_33 -> V_129 = V_212 ;
}
if ( ! V_4 -> V_219 ) {
F_80 ( V_33 ) ;
return - V_28 ;
}
V_211 = F_144 ( V_4 -> V_219 , V_33 ) ;
if ( V_211 < 0 ) {
F_145 ( L_12 ) ;
F_80 ( V_33 ) ;
}
return V_211 ;
}
static int
F_146 ( struct V_1 * V_4 , T_6 V_200 , struct V_32 * V_33 )
{
bool V_220 = false ;
int V_7 ;
struct V_60 * V_162 ;
F_38 ( & V_68 ) ;
F_36 (c, &mrt->mfc6_unres_queue, list) {
if ( F_121 ( & V_162 -> V_92 , & F_67 ( V_33 ) -> V_119 ) &&
F_121 ( & V_162 -> V_93 , & F_67 ( V_33 ) -> V_118 ) ) {
V_220 = true ;
break;
}
}
if ( ! V_220 ) {
if ( F_147 ( & V_4 -> V_164 ) >= 10 ||
( V_162 = F_127 () ) == NULL ) {
F_39 ( & V_68 ) ;
F_80 ( V_33 ) ;
return - V_189 ;
}
V_162 -> V_94 = - 1 ;
V_162 -> V_93 = F_67 ( V_33 ) -> V_118 ;
V_162 -> V_92 = F_67 ( V_33 ) -> V_119 ;
V_7 = F_82 ( V_4 , V_33 , V_200 , V_221 ) ;
if ( V_7 < 0 ) {
F_39 ( & V_68 ) ;
F_98 ( V_162 ) ;
F_80 ( V_33 ) ;
return V_7 ;
}
F_148 ( & V_4 -> V_164 ) ;
F_149 ( & V_162 -> V_50 , & V_4 -> V_56 ) ;
F_111 ( V_4 , V_162 , V_222 ) ;
F_109 ( V_4 ) ;
}
if ( V_162 -> V_95 . V_165 . V_166 . V_223 > 3 ) {
F_80 ( V_33 ) ;
V_7 = - V_189 ;
} else {
F_150 ( & V_162 -> V_95 . V_165 . V_166 , V_33 ) ;
V_7 = 0 ;
}
F_39 ( & V_68 ) ;
return V_7 ;
}
static int F_151 ( struct V_1 * V_4 , struct V_224 * V_64 ,
int V_225 )
{
int line ;
struct V_60 * V_162 , * V_49 ;
line = F_120 ( & V_64 -> V_226 . V_227 , & V_64 -> V_228 . V_227 ) ;
F_22 (c, next, &mrt->mfc6_cache_array[line], list) {
if ( F_121 ( & V_162 -> V_93 , & V_64 -> V_228 . V_227 ) &&
F_121 ( & V_162 -> V_92 ,
& V_64 -> V_226 . V_227 ) &&
( V_225 == - 1 || V_225 == V_162 -> V_94 ) ) {
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
static int F_152 ( struct V_229 * V_230 ,
unsigned long V_231 , void * V_232 )
{
struct V_106 * V_82 = F_153 ( V_232 ) ;
struct V_2 * V_2 = F_63 ( V_82 ) ;
struct V_1 * V_4 ;
struct V_69 * V_79 ;
int V_66 ;
F_154 ( V_50 ) ;
if ( V_231 != V_233 )
return V_234 ;
F_2 (mrt, net) {
V_79 = & V_4 -> V_73 [ 0 ] ;
for ( V_66 = 0 ; V_66 < V_4 -> V_72 ; V_66 ++ , V_79 ++ ) {
if ( V_79 -> V_82 == V_82 )
F_91 ( V_4 , V_66 , & V_50 ) ;
}
}
F_155 ( & V_50 ) ;
return V_234 ;
}
static int T_2 F_156 ( struct V_2 * V_2 )
{
int V_7 ;
V_7 = F_11 ( V_2 ) ;
if ( V_7 < 0 )
goto V_235;
#ifdef F_157
V_7 = - V_46 ;
if ( ! F_158 ( L_13 , 0 , V_2 -> V_236 , & V_237 ) )
goto V_238;
if ( ! F_158 ( L_14 , 0 , V_2 -> V_236 , & V_239 ) )
goto V_240;
#endif
return 0 ;
#ifdef F_157
V_240:
F_159 ( L_13 , V_2 -> V_236 ) ;
V_238:
F_20 ( V_2 ) ;
#endif
V_235:
return V_7 ;
}
static void T_3 F_160 ( struct V_2 * V_2 )
{
#ifdef F_157
F_159 ( L_14 , V_2 -> V_236 ) ;
F_159 ( L_13 , V_2 -> V_236 ) ;
#endif
F_20 ( V_2 ) ;
}
int T_7 F_161 ( void )
{
int V_7 ;
V_163 = F_162 ( L_15 ,
sizeof( struct V_60 ) ,
0 , V_241 ,
NULL ) ;
if ( ! V_163 )
return - V_46 ;
V_7 = F_163 ( & V_242 ) ;
if ( V_7 )
goto V_243;
V_7 = F_164 ( & V_244 ) ;
if ( V_7 )
goto V_245;
#ifdef F_28
if ( F_165 ( & V_246 , V_120 ) < 0 ) {
F_166 ( L_16 , V_247 ) ;
V_7 = - V_31 ;
goto V_248;
}
#endif
F_167 ( V_249 , V_250 , NULL ,
V_251 , NULL ) ;
return 0 ;
#ifdef F_28
V_248:
F_168 ( & V_244 ) ;
#endif
V_245:
F_169 ( & V_242 ) ;
V_243:
F_170 ( V_163 ) ;
return V_7 ;
}
void F_171 ( void )
{
F_172 ( V_249 , V_250 ) ;
#ifdef F_28
F_173 ( & V_246 , V_120 ) ;
#endif
F_168 ( & V_244 ) ;
F_169 ( & V_242 ) ;
F_170 ( V_163 ) ;
}
static int F_174 ( struct V_2 * V_2 , struct V_1 * V_4 ,
struct V_224 * V_64 , int V_185 , int V_225 )
{
bool V_220 = false ;
int line ;
struct V_60 * V_207 , * V_162 ;
unsigned char V_100 [ V_182 ] ;
int V_52 ;
if ( V_64 -> V_252 >= V_182 )
return - V_253 ;
memset ( V_100 , 255 , V_182 ) ;
for ( V_52 = 0 ; V_52 < V_182 ; V_52 ++ ) {
if ( F_175 ( V_52 , & V_64 -> V_254 ) )
V_100 [ V_52 ] = 1 ;
}
line = F_120 ( & V_64 -> V_226 . V_227 , & V_64 -> V_228 . V_227 ) ;
F_36 (c, &mrt->mfc6_cache_array[line], list) {
if ( F_121 ( & V_162 -> V_93 , & V_64 -> V_228 . V_227 ) &&
F_121 ( & V_162 -> V_92 ,
& V_64 -> V_226 . V_227 ) &&
( V_225 == - 1 || V_225 == V_64 -> V_252 ) ) {
V_220 = true ;
break;
}
}
if ( V_220 ) {
F_92 ( & V_65 ) ;
V_162 -> V_94 = V_64 -> V_252 ;
F_115 ( V_4 , V_162 , V_100 ) ;
if ( ! V_185 )
V_162 -> V_255 |= V_256 ;
F_93 ( & V_65 ) ;
F_111 ( V_4 , V_162 , V_222 ) ;
return 0 ;
}
if ( ! F_123 ( & V_64 -> V_226 . V_227 ) &&
! F_71 ( & V_64 -> V_226 . V_227 ) )
return - V_28 ;
V_162 = F_125 () ;
if ( ! V_162 )
return - V_46 ;
V_162 -> V_93 = V_64 -> V_228 . V_227 ;
V_162 -> V_92 = V_64 -> V_226 . V_227 ;
V_162 -> V_94 = V_64 -> V_252 ;
F_115 ( V_4 , V_162 , V_100 ) ;
if ( ! V_185 )
V_162 -> V_255 |= V_256 ;
F_92 ( & V_65 ) ;
F_149 ( & V_162 -> V_50 , & V_4 -> V_55 [ line ] ) ;
F_93 ( & V_65 ) ;
V_220 = false ;
F_38 ( & V_68 ) ;
F_36 (uc, &mrt->mfc6_unres_queue, list) {
if ( F_121 ( & V_207 -> V_93 , & V_162 -> V_93 ) &&
F_121 ( & V_207 -> V_92 , & V_162 -> V_92 ) ) {
F_23 ( & V_207 -> V_50 ) ;
F_102 ( & V_4 -> V_164 ) ;
V_220 = true ;
break;
}
}
if ( F_56 ( & V_4 -> V_56 ) )
F_176 ( & V_4 -> V_57 ) ;
F_39 ( & V_68 ) ;
if ( V_220 ) {
F_129 ( V_2 , V_4 , V_207 , V_162 ) ;
F_98 ( V_207 ) ;
}
F_111 ( V_4 , V_162 , V_222 ) ;
return 0 ;
}
static void F_32 ( struct V_1 * V_4 , bool V_257 )
{
int V_52 ;
F_154 ( V_50 ) ;
struct V_60 * V_162 , * V_49 ;
for ( V_52 = 0 ; V_52 < V_4 -> V_72 ; V_52 ++ ) {
if ( ! V_257 && ( V_4 -> V_73 [ V_52 ] . V_13 & V_193 ) )
continue;
F_91 ( V_4 , V_52 , & V_50 ) ;
}
F_155 ( & V_50 ) ;
for ( V_52 = 0 ; V_52 < V_54 ; V_52 ++ ) {
F_22 (c, next, &mrt->mfc6_cache_array[i], list) {
if ( ! V_257 && ( V_162 -> V_255 & V_256 ) )
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
static int F_177 ( struct V_1 * V_4 , struct V_258 * V_259 )
{
int V_7 = 0 ;
struct V_2 * V_2 = F_178 ( V_259 ) ;
F_21 () ;
F_92 ( & V_65 ) ;
if ( F_179 ( V_4 -> V_219 == NULL ) ) {
V_4 -> V_219 = V_259 ;
V_2 -> V_15 . V_260 -> V_159 ++ ;
F_96 ( V_2 , V_160 ,
V_261 ,
V_2 -> V_15 . V_260 ) ;
}
else
V_7 = - V_187 ;
F_93 ( & V_65 ) ;
F_24 () ;
return V_7 ;
}
int F_180 ( struct V_258 * V_259 )
{
int V_7 = - V_26 ;
struct V_2 * V_2 = F_178 ( V_259 ) ;
struct V_1 * V_4 ;
F_21 () ;
F_2 (mrt, net) {
if ( V_259 == V_4 -> V_219 ) {
F_92 ( & V_65 ) ;
V_4 -> V_219 = NULL ;
V_2 -> V_15 . V_260 -> V_159 -- ;
F_96 ( V_2 ,
V_160 ,
V_261 ,
V_2 -> V_15 . V_260 ) ;
F_93 ( & V_65 ) ;
F_32 ( V_4 , false ) ;
V_7 = 0 ;
break;
}
}
F_24 () ;
return V_7 ;
}
struct V_258 * F_181 ( struct V_2 * V_2 , struct V_32 * V_33 )
{
struct V_1 * V_4 ;
struct V_5 V_108 = {
. V_109 = V_33 -> V_132 ? : V_133 ,
. V_131 = V_33 -> V_82 -> V_110 ,
. V_111 = V_33 -> V_112 ,
} ;
if ( F_3 ( V_2 , & V_108 , & V_4 ) < 0 )
return NULL ;
return V_4 -> V_219 ;
}
int F_182 ( struct V_258 * V_259 , int V_262 , char T_8 * V_263 , unsigned int V_264 )
{
int V_211 , V_225 = 0 ;
struct V_183 V_80 ;
struct V_224 V_64 ;
T_6 V_200 ;
struct V_2 * V_2 = F_178 ( V_259 ) ;
struct V_1 * V_4 ;
V_4 = F_1 ( V_2 , F_183 ( V_259 ) -> V_265 ? : V_45 ) ;
if ( ! V_4 )
return - V_77 ;
if ( V_262 != V_266 ) {
if ( V_259 != V_4 -> V_219 && ! F_184 ( V_2 -> V_267 , V_268 ) )
return - V_26 ;
}
switch ( V_262 ) {
case V_266 :
if ( V_259 -> V_269 != V_270 ||
F_185 ( V_259 ) -> V_271 != V_272 )
return - V_273 ;
if ( V_264 < sizeof( int ) )
return - V_28 ;
return F_177 ( V_4 , V_259 ) ;
case V_274 :
return F_180 ( V_259 ) ;
case V_275 :
if ( V_264 < sizeof( V_80 ) )
return - V_28 ;
if ( F_186 ( & V_80 , V_263 , sizeof( V_80 ) ) )
return - V_276 ;
if ( V_80 . V_186 >= V_182 )
return - V_253 ;
F_21 () ;
V_211 = F_116 ( V_2 , V_4 , & V_80 , V_259 == V_4 -> V_219 ) ;
F_24 () ;
return V_211 ;
case V_277 :
if ( V_264 < sizeof( T_6 ) )
return - V_28 ;
if ( F_186 ( & V_200 , V_263 , sizeof( T_6 ) ) )
return - V_276 ;
F_21 () ;
V_211 = F_91 ( V_4 , V_200 , NULL ) ;
F_24 () ;
return V_211 ;
case V_278 :
case V_279 :
V_225 = - 1 ;
case V_280 :
case V_281 :
if ( V_264 < sizeof( V_64 ) )
return - V_28 ;
if ( F_186 ( & V_64 , V_263 , sizeof( V_64 ) ) )
return - V_276 ;
if ( V_225 == 0 )
V_225 = V_64 . V_252 ;
F_21 () ;
if ( V_262 == V_279 || V_262 == V_281 )
V_211 = F_151 ( V_4 , & V_64 , V_225 ) ;
else
V_211 = F_174 ( V_2 , V_4 , & V_64 ,
V_259 == V_4 -> V_219 , V_225 ) ;
F_24 () ;
return V_211 ;
case V_282 :
{
int V_79 ;
if ( V_264 != sizeof( V_79 ) )
return - V_28 ;
if ( F_187 ( V_79 , ( int T_8 * ) V_263 ) )
return - V_276 ;
V_4 -> V_283 = V_79 ;
return 0 ;
}
#ifdef F_28
case V_284 :
{
int V_79 ;
if ( V_264 != sizeof( V_79 ) )
return - V_28 ;
if ( F_187 ( V_79 , ( int T_8 * ) V_263 ) )
return - V_276 ;
V_79 = ! ! V_79 ;
F_21 () ;
V_211 = 0 ;
if ( V_79 != V_4 -> V_285 ) {
V_4 -> V_285 = V_79 ;
V_4 -> V_283 = V_79 ;
}
F_24 () ;
return V_211 ;
}
#endif
#ifdef F_29
case V_286 :
{
T_1 V_79 ;
if ( V_264 != sizeof( T_1 ) )
return - V_28 ;
if ( F_187 ( V_79 , ( T_1 T_8 * ) V_263 ) )
return - V_276 ;
if ( V_79 != V_287 && V_79 >= 100000000 )
return - V_28 ;
if ( V_259 == V_4 -> V_219 )
return - V_288 ;
F_21 () ;
V_211 = 0 ;
if ( ! F_16 ( V_2 , V_79 ) )
V_211 = - V_46 ;
F_183 ( V_259 ) -> V_265 = V_79 ;
F_24 () ;
return V_211 ;
}
#endif
default:
return - V_289 ;
}
}
int F_188 ( struct V_258 * V_259 , int V_262 , char T_8 * V_263 ,
int T_8 * V_264 )
{
int V_290 ;
int V_291 ;
struct V_2 * V_2 = F_178 ( V_259 ) ;
struct V_1 * V_4 ;
V_4 = F_1 ( V_2 , F_183 ( V_259 ) -> V_265 ? : V_45 ) ;
if ( ! V_4 )
return - V_77 ;
switch ( V_262 ) {
case V_292 :
V_291 = 0x0305 ;
break;
#ifdef F_28
case V_284 :
V_291 = V_4 -> V_285 ;
break;
#endif
case V_282 :
V_291 = V_4 -> V_283 ;
break;
default:
return - V_289 ;
}
if ( F_187 ( V_290 , V_264 ) )
return - V_276 ;
V_290 = F_189 ( int , V_290 , sizeof( int ) ) ;
if ( V_290 < 0 )
return - V_28 ;
if ( F_190 ( V_290 , V_264 ) )
return - V_276 ;
if ( F_191 ( V_263 , & V_291 , V_290 ) )
return - V_276 ;
return 0 ;
}
int F_192 ( struct V_258 * V_259 , int V_293 , void T_8 * V_11 )
{
struct V_294 V_295 ;
struct V_296 V_297 ;
struct V_69 * V_80 ;
struct V_60 * V_162 ;
struct V_2 * V_2 = F_178 ( V_259 ) ;
struct V_1 * V_4 ;
V_4 = F_1 ( V_2 , F_183 ( V_259 ) -> V_265 ? : V_45 ) ;
if ( ! V_4 )
return - V_77 ;
switch ( V_293 ) {
case V_298 :
if ( F_186 ( & V_297 , V_11 , sizeof( V_297 ) ) )
return - V_276 ;
if ( V_297 . V_200 >= V_4 -> V_72 )
return - V_28 ;
F_35 ( & V_65 ) ;
V_80 = & V_4 -> V_73 [ V_297 . V_200 ] ;
if ( F_41 ( V_4 , V_297 . V_200 ) ) {
V_297 . V_299 = V_80 -> V_84 ;
V_297 . V_300 = V_80 -> V_86 ;
V_297 . V_301 = V_80 -> V_83 ;
V_297 . V_302 = V_80 -> V_85 ;
F_37 ( & V_65 ) ;
if ( F_191 ( V_11 , & V_297 , sizeof( V_297 ) ) )
return - V_276 ;
return 0 ;
}
F_37 ( & V_65 ) ;
return - V_156 ;
case V_303 :
if ( F_186 ( & V_295 , V_11 , sizeof( V_295 ) ) )
return - V_276 ;
F_35 ( & V_65 ) ;
V_162 = F_119 ( V_4 , & V_295 . V_304 . V_227 , & V_295 . V_305 . V_227 ) ;
if ( V_162 ) {
V_295 . V_306 = V_162 -> V_95 . V_9 . V_96 ;
V_295 . V_307 = V_162 -> V_95 . V_9 . V_97 ;
V_295 . V_98 = V_162 -> V_95 . V_9 . V_98 ;
F_37 ( & V_65 ) ;
if ( F_191 ( V_11 , & V_295 , sizeof( V_295 ) ) )
return - V_276 ;
return 0 ;
}
F_37 ( & V_65 ) ;
return - V_156 ;
default:
return - V_308 ;
}
}
int F_193 ( struct V_258 * V_259 , unsigned int V_293 , void T_8 * V_11 )
{
struct V_309 V_295 ;
struct V_310 V_297 ;
struct V_69 * V_80 ;
struct V_60 * V_162 ;
struct V_2 * V_2 = F_178 ( V_259 ) ;
struct V_1 * V_4 ;
V_4 = F_1 ( V_2 , F_183 ( V_259 ) -> V_265 ? : V_45 ) ;
if ( ! V_4 )
return - V_77 ;
switch ( V_293 ) {
case V_298 :
if ( F_186 ( & V_297 , V_11 , sizeof( V_297 ) ) )
return - V_276 ;
if ( V_297 . V_200 >= V_4 -> V_72 )
return - V_28 ;
F_35 ( & V_65 ) ;
V_80 = & V_4 -> V_73 [ V_297 . V_200 ] ;
if ( F_41 ( V_4 , V_297 . V_200 ) ) {
V_297 . V_299 = V_80 -> V_84 ;
V_297 . V_300 = V_80 -> V_86 ;
V_297 . V_301 = V_80 -> V_83 ;
V_297 . V_302 = V_80 -> V_85 ;
F_37 ( & V_65 ) ;
if ( F_191 ( V_11 , & V_297 , sizeof( V_297 ) ) )
return - V_276 ;
return 0 ;
}
F_37 ( & V_65 ) ;
return - V_156 ;
case V_303 :
if ( F_186 ( & V_295 , V_11 , sizeof( V_295 ) ) )
return - V_276 ;
F_35 ( & V_65 ) ;
V_162 = F_119 ( V_4 , & V_295 . V_304 . V_227 , & V_295 . V_305 . V_227 ) ;
if ( V_162 ) {
V_295 . V_306 = V_162 -> V_95 . V_9 . V_96 ;
V_295 . V_307 = V_162 -> V_95 . V_9 . V_97 ;
V_295 . V_98 = V_162 -> V_95 . V_9 . V_98 ;
F_37 ( & V_65 ) ;
if ( F_191 ( V_11 , & V_295 , sizeof( V_295 ) ) )
return - V_276 ;
return 0 ;
}
F_37 ( & V_65 ) ;
return - V_156 ;
default:
return - V_308 ;
}
}
static inline int F_194 ( struct V_2 * V_2 , struct V_258 * V_259 , struct V_32 * V_33 )
{
F_195 ( V_2 , F_196 ( F_143 ( V_33 ) ) ,
V_311 ) ;
F_197 ( V_2 , F_196 ( F_143 ( V_33 ) ) ,
V_312 , V_33 -> V_121 ) ;
return F_198 ( V_2 , V_259 , V_33 ) ;
}
static int F_199 ( struct V_2 * V_2 , struct V_1 * V_4 ,
struct V_32 * V_33 , struct V_60 * V_162 , int V_151 )
{
struct V_104 * V_313 ;
struct V_69 * V_80 = & V_4 -> V_73 [ V_151 ] ;
struct V_106 * V_82 ;
struct V_314 * V_315 ;
struct V_5 V_108 ;
if ( ! V_80 -> V_82 )
goto V_316;
#ifdef F_28
if ( V_80 -> V_13 & V_161 ) {
V_80 -> V_86 ++ ;
V_80 -> V_85 += V_33 -> V_121 ;
V_80 -> V_82 -> V_134 . V_135 += V_33 -> V_121 ;
V_80 -> V_82 -> V_134 . V_136 ++ ;
F_82 ( V_4 , V_33 , V_151 , V_137 ) ;
goto V_316;
}
#endif
V_313 = F_67 ( V_33 ) ;
V_108 = (struct V_5 ) {
. V_131 = V_80 -> V_196 ,
. V_119 = V_313 -> V_119 ,
} ;
V_315 = F_200 ( V_2 , NULL , & V_108 ) ;
if ( V_315 -> error ) {
F_201 ( V_315 ) ;
goto V_316;
}
F_202 ( V_33 ) ;
F_141 ( V_33 , V_315 ) ;
V_82 = V_80 -> V_82 ;
V_33 -> V_82 = V_82 ;
V_80 -> V_86 ++ ;
V_80 -> V_85 += V_33 -> V_121 ;
if ( F_203 ( V_33 , sizeof( * V_313 ) + F_204 ( V_82 ) ) )
goto V_316;
V_313 = F_67 ( V_33 ) ;
V_313 -> V_317 -- ;
F_205 ( V_33 ) -> V_13 |= V_318 ;
return F_206 ( V_319 , V_320 ,
V_2 , NULL , V_33 , V_33 -> V_82 , V_82 ,
F_194 ) ;
V_316:
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
int V_321 = - 1 ;
int V_80 , V_66 ;
int V_322 = F_207 ( V_4 , V_33 -> V_82 ) ;
V_80 = V_67 -> V_94 ;
V_67 -> V_95 . V_9 . V_96 ++ ;
V_67 -> V_95 . V_9 . V_97 += V_33 -> V_121 ;
if ( F_123 ( & V_67 -> V_93 ) && V_322 >= 0 ) {
struct V_60 * V_323 ;
V_323 = F_122 ( V_4 , V_80 ) ;
if ( V_323 &&
V_323 -> V_95 . V_9 . V_100 [ V_322 ] < 255 )
goto V_324;
}
if ( V_4 -> V_73 [ V_80 ] . V_82 != V_33 -> V_82 ) {
V_67 -> V_95 . V_9 . V_98 ++ ;
if ( V_322 >= 0 && V_4 -> V_283 &&
( V_4 -> V_285 ||
V_67 -> V_95 . V_9 . V_100 [ V_322 ] < 255 ) &&
F_110 ( V_177 ,
V_67 -> V_95 . V_9 . V_204 + V_205 ) ) {
V_67 -> V_95 . V_9 . V_204 = V_177 ;
F_82 ( V_4 , V_33 , V_322 , V_325 ) ;
}
goto V_326;
}
V_324:
V_4 -> V_73 [ V_80 ] . V_84 ++ ;
V_4 -> V_73 [ V_80 ] . V_83 += V_33 -> V_121 ;
if ( F_123 ( & V_67 -> V_93 ) &&
F_123 ( & V_67 -> V_92 ) ) {
if ( V_322 >= 0 &&
V_322 != V_67 -> V_94 &&
F_67 ( V_33 ) -> V_317 >
V_67 -> V_95 . V_9 . V_100 [ V_67 -> V_94 ] ) {
V_321 = V_67 -> V_94 ;
goto V_327;
}
goto V_326;
}
for ( V_66 = V_67 -> V_95 . V_9 . V_72 - 1 ; V_66 >= V_67 -> V_95 . V_9 . V_99 ; V_66 -- ) {
if ( ( ! F_123 ( & V_67 -> V_93 ) || V_66 != V_322 ) &&
F_67 ( V_33 ) -> V_317 > V_67 -> V_95 . V_9 . V_100 [ V_66 ] ) {
if ( V_321 != - 1 ) {
struct V_32 * V_328 = F_208 ( V_33 , V_206 ) ;
if ( V_328 )
F_199 ( V_2 , V_4 , V_328 , V_67 , V_321 ) ;
}
V_321 = V_66 ;
}
}
V_327:
if ( V_321 != - 1 ) {
F_199 ( V_2 , V_4 , V_33 , V_67 , V_321 ) ;
return;
}
V_326:
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
return - V_329 ;
}
F_133 ( V_2 , V_4 , V_33 , V_67 ) ;
F_37 ( & V_65 ) ;
return 0 ;
}
static int F_131 ( struct V_1 * V_4 , struct V_32 * V_33 ,
struct V_60 * V_162 , struct V_330 * V_331 )
{
int V_66 ;
struct V_332 * V_333 ;
struct V_36 * V_334 ;
struct V_335 V_336 ;
if ( V_162 -> V_94 >= V_182 )
return - V_77 ;
if ( F_41 ( V_4 , V_162 -> V_94 ) &&
F_210 ( V_33 , V_337 , V_4 -> V_73 [ V_162 -> V_94 ] . V_82 -> V_110 ) < 0 )
return - V_208 ;
V_334 = F_211 ( V_33 , V_338 ) ;
if ( ! V_334 )
return - V_208 ;
for ( V_66 = V_162 -> V_95 . V_9 . V_99 ; V_66 < V_162 -> V_95 . V_9 . V_72 ; V_66 ++ ) {
if ( F_41 ( V_4 , V_66 ) && V_162 -> V_95 . V_9 . V_100 [ V_66 ] < 255 ) {
V_333 = F_212 ( V_33 , sizeof( * V_333 ) ) ;
if ( ! V_333 ) {
F_213 ( V_33 , V_334 ) ;
return - V_208 ;
}
V_333 -> V_339 = 0 ;
V_333 -> V_340 = V_162 -> V_95 . V_9 . V_100 [ V_66 ] ;
V_333 -> V_341 = V_4 -> V_73 [ V_66 ] . V_82 -> V_110 ;
V_333 -> V_342 = sizeof( * V_333 ) ;
}
}
F_214 ( V_33 , V_334 ) ;
V_336 . V_343 = V_162 -> V_95 . V_9 . V_96 ;
V_336 . V_344 = V_162 -> V_95 . V_9 . V_97 ;
V_336 . V_345 = V_162 -> V_95 . V_9 . V_98 ;
if ( F_215 ( V_33 , V_346 , sizeof( V_336 ) , & V_336 , V_347 ) < 0 )
return - V_208 ;
V_331 -> V_348 = V_349 ;
return 1 ;
}
int F_216 ( struct V_2 * V_2 ,
struct V_32 * V_33 , struct V_330 * V_331 , int V_350 )
{
int V_7 ;
struct V_1 * V_4 ;
struct V_60 * V_67 ;
struct V_351 * V_352 = (struct V_351 * ) F_143 ( V_33 ) ;
V_4 = F_1 ( V_2 , V_45 ) ;
if ( ! V_4 )
return - V_77 ;
F_35 ( & V_65 ) ;
V_67 = F_119 ( V_4 , & V_352 -> V_353 . V_354 , & V_352 -> V_355 . V_354 ) ;
if ( ! V_67 && V_33 -> V_82 ) {
int V_80 = F_207 ( V_4 , V_33 -> V_82 ) ;
if ( V_80 >= 0 )
V_67 = F_124 ( V_4 , & V_352 -> V_355 . V_354 ,
V_80 ) ;
}
if ( ! V_67 ) {
struct V_32 * V_328 ;
struct V_104 * V_356 ;
struct V_106 * V_82 ;
int V_80 ;
if ( V_350 ) {
F_37 ( & V_65 ) ;
return - V_31 ;
}
V_82 = V_33 -> V_82 ;
if ( ! V_82 || ( V_80 = F_207 ( V_4 , V_82 ) ) < 0 ) {
F_37 ( & V_65 ) ;
return - V_329 ;
}
V_328 = F_136 ( sizeof( struct V_104 ) , V_206 ) ;
if ( ! V_328 ) {
F_37 ( & V_65 ) ;
return - V_46 ;
}
F_138 ( V_328 ) ;
F_139 ( V_328 , sizeof( struct V_104 ) ) ;
F_75 ( V_328 ) ;
V_356 = F_67 ( V_328 ) ;
V_356 -> V_167 = 0 ;
V_356 -> V_357 = 0 ;
V_356 -> V_358 [ 0 ] = 0 ;
V_356 -> V_358 [ 1 ] = 0 ;
V_356 -> V_358 [ 2 ] = 0 ;
V_356 -> V_122 = 0 ;
V_356 -> V_359 = V_360 ;
V_356 -> V_317 = 0 ;
V_356 -> V_118 = V_352 -> V_353 . V_354 ;
V_356 -> V_119 = V_352 -> V_355 . V_354 ;
V_7 = F_146 ( V_4 , V_80 , V_328 ) ;
F_37 ( & V_65 ) ;
return V_7 ;
}
if ( ! V_350 && ( V_331 -> V_361 & V_362 ) )
V_67 -> V_255 |= V_363 ;
V_7 = F_131 ( V_4 , V_33 , V_67 , V_331 ) ;
F_37 ( & V_65 ) ;
return V_7 ;
}
static int F_217 ( struct V_1 * V_4 , struct V_32 * V_33 ,
T_1 V_175 , T_1 V_75 , struct V_60 * V_162 , int V_293 ,
int V_13 )
{
struct V_168 * V_169 ;
struct V_330 * V_331 ;
int V_7 ;
V_169 = F_218 ( V_33 , V_175 , V_75 , V_293 , sizeof( * V_331 ) , V_13 ) ;
if ( ! V_169 )
return - V_208 ;
V_331 = F_106 ( V_169 ) ;
V_331 -> V_364 = V_249 ;
V_331 -> V_365 = 128 ;
V_331 -> V_366 = 128 ;
V_331 -> V_367 = 0 ;
V_331 -> V_368 = V_4 -> V_3 ;
if ( F_210 ( V_33 , V_369 , V_4 -> V_3 ) )
goto V_370;
V_331 -> V_348 = V_349 ;
V_331 -> V_371 = V_372 ;
if ( V_162 -> V_255 & V_256 )
V_331 -> V_373 = V_374 ;
else
V_331 -> V_373 = V_375 ;
V_331 -> V_361 = 0 ;
if ( F_219 ( V_33 , V_376 , & V_162 -> V_93 ) ||
F_219 ( V_33 , V_377 , & V_162 -> V_92 ) )
goto V_370;
V_7 = F_131 ( V_4 , V_33 , V_162 , V_331 ) ;
if ( V_7 < 0 && V_7 != - V_77 )
goto V_370;
F_220 ( V_33 , V_169 ) ;
return 0 ;
V_370:
F_221 ( V_33 , V_169 ) ;
return - V_208 ;
}
static int F_222 ( bool V_166 , int V_72 )
{
T_9 V_121 =
F_223 ( sizeof( struct V_330 ) )
+ F_224 ( 4 )
+ F_224 ( sizeof( struct V_197 ) )
+ F_224 ( sizeof( struct V_197 ) )
;
if ( ! V_166 )
V_121 = V_121
+ F_224 ( 4 )
+ F_224 ( 0 )
+ V_72 * F_225 ( sizeof( struct V_332 ) )
+ F_226 ( sizeof( struct V_335 ) )
;
return V_121 ;
}
static void F_111 ( struct V_1 * V_4 , struct V_60 * V_64 ,
int V_293 )
{
struct V_2 * V_2 = F_101 ( & V_4 -> V_2 ) ;
struct V_32 * V_33 ;
int V_7 = - V_189 ;
V_33 = F_227 ( F_222 ( V_64 -> V_94 >= V_182 , V_4 -> V_72 ) ,
V_206 ) ;
if ( ! V_33 )
goto V_378;
V_7 = F_217 ( V_4 , V_33 , 0 , 0 , V_64 , V_293 , 0 ) ;
if ( V_7 < 0 )
goto V_378;
F_228 ( V_33 , V_2 , 0 , V_379 , NULL , V_206 ) ;
return;
V_378:
F_80 ( V_33 ) ;
if ( V_7 < 0 )
F_229 ( V_2 , V_379 , V_7 ) ;
}
static int V_251 ( struct V_32 * V_33 , struct V_380 * V_381 )
{
struct V_2 * V_2 = F_178 ( V_33 -> V_259 ) ;
struct V_1 * V_4 ;
struct V_60 * V_64 ;
unsigned int V_382 = 0 , V_383 ;
unsigned int V_384 = 0 , V_385 ;
unsigned int V_386 = 0 , V_387 ;
V_383 = V_381 -> args [ 0 ] ;
V_385 = V_381 -> args [ 1 ] ;
V_387 = V_381 -> args [ 2 ] ;
F_35 ( & V_65 ) ;
F_2 (mrt, net) {
if ( V_382 < V_383 )
goto V_388;
if ( V_382 > V_383 )
V_385 = 0 ;
for ( V_384 = V_385 ; V_384 < V_54 ; V_384 ++ ) {
F_36 (mfc, &mrt->mfc6_cache_array[h], list) {
if ( V_386 < V_387 )
goto V_389;
if ( F_217 ( V_4 , V_33 ,
F_108 ( V_381 -> V_33 ) . V_175 ,
V_381 -> V_169 -> V_390 ,
V_64 , V_222 ,
V_391 ) < 0 )
goto V_392;
V_389:
V_386 ++ ;
}
V_386 = V_387 = 0 ;
}
F_38 ( & V_68 ) ;
F_36 (mfc, &mrt->mfc6_unres_queue, list) {
if ( V_386 < V_387 )
goto V_393;
if ( F_217 ( V_4 , V_33 ,
F_108 ( V_381 -> V_33 ) . V_175 ,
V_381 -> V_169 -> V_390 ,
V_64 , V_222 ,
V_391 ) < 0 ) {
F_39 ( & V_68 ) ;
goto V_392;
}
V_393:
V_386 ++ ;
}
F_39 ( & V_68 ) ;
V_386 = V_387 = 0 ;
V_385 = 0 ;
V_388:
V_382 ++ ;
}
V_392:
F_37 ( & V_65 ) ;
V_381 -> args [ 2 ] = V_386 ;
V_381 -> args [ 1 ] = V_384 ;
V_381 -> args [ 0 ] = V_382 ;
return V_33 -> V_121 ;
}
