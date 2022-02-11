static struct V_1 * F_1 ( struct V_1 * * V_2 , int V_3 )
{
struct V_1 * V_1 ;
struct V_1 * V_4 ;
F_2 ( ! V_3 ) ;
F_2 ( ! V_2 ) ;
V_1 = * V_2 ;
if ( ! V_1 )
return NULL ;
while ( V_1 ) {
V_4 = F_3 ( V_1 ) ;
if ( -- V_3 == 0 )
break;
if ( V_4 == NULL )
return NULL ;
V_1 = V_4 ;
}
F_4 ( V_1 , 0 ) ;
V_1 = * V_2 ;
* V_2 = V_4 ;
return V_1 ;
}
static struct V_1 * F_5 ( struct V_1 * V_1 , int * V_5 )
{
struct V_1 * V_4 ;
int V_6 = 1 ;
while ( ( V_4 = F_3 ( V_1 ) ) )
++ V_6 , V_1 = V_4 ;
if ( V_5 )
* V_5 = V_6 ;
return V_1 ;
}
static int F_6 ( struct V_1 * V_1 )
{
struct V_1 * V_4 ;
int V_6 = 0 ;
F_7 (page, tmp) {
F_8 ( V_1 ) ;
++ V_6 ;
}
return V_6 ;
}
static void F_9 ( struct V_1 * * V_2 ,
struct V_1 * V_7 , struct V_1 * V_8 )
{
#if 1
struct V_1 * V_4 ;
V_4 = F_5 ( V_7 , NULL ) ;
F_2 ( V_4 != V_8 ) ;
#endif
F_4 ( V_8 , ( unsigned long ) * V_2 ) ;
* V_2 = V_7 ;
}
static struct V_1 * F_10 ( struct V_9 * V_10 ,
unsigned int V_11 )
{
struct V_1 * V_1 = NULL ;
struct V_1 * V_4 = NULL ;
unsigned int V_6 = 0 ;
if ( V_12 >= V_11 ) {
F_11 ( & V_13 ) ;
V_1 = F_1 ( & V_14 , V_11 ) ;
if ( V_1 )
V_12 -= V_11 ;
F_12 ( & V_13 ) ;
if ( V_1 )
return V_1 ;
}
for ( V_6 = 0 ; V_6 < V_11 ; V_6 ++ ) {
V_4 = F_13 ( V_15 ) ;
if ( ! V_4 )
break;
F_4 ( V_4 , ( unsigned long ) V_1 ) ;
V_1 = V_4 ;
}
if ( V_6 == V_11 )
return V_1 ;
if ( V_1 ) {
V_4 = F_5 ( V_1 , NULL ) ;
F_11 ( & V_13 ) ;
F_9 ( & V_14 , V_1 , V_4 ) ;
V_12 += V_6 ;
F_12 ( & V_13 ) ;
}
return NULL ;
}
static void F_14 ( struct V_9 * V_10 ,
struct V_16 * V_17 )
{
struct V_18 * V_19 ;
struct V_16 * V_20 , * V_21 ;
F_15 (le, tle, &mdev->net_ee) {
V_19 = F_16 ( V_20 , struct V_18 , V_22 . V_23 ) ;
if ( F_17 ( V_19 ) )
break;
F_18 ( V_20 , V_17 ) ;
}
}
static void F_19 ( struct V_9 * V_10 )
{
F_20 ( V_24 ) ;
struct V_18 * V_19 , * V_25 ;
F_21 ( & V_10 -> V_26 -> V_27 ) ;
F_14 ( V_10 , & V_24 ) ;
F_22 ( & V_10 -> V_26 -> V_27 ) ;
F_23 (peer_req, t, &reclaimed, w.list)
F_24 ( V_10 , V_19 ) ;
}
struct V_1 * F_25 ( struct V_9 * V_10 , unsigned int V_11 ,
bool V_28 )
{
struct V_1 * V_1 = NULL ;
struct V_29 * V_30 ;
F_26 ( V_31 ) ;
int V_32 ;
F_27 () ;
V_30 = F_28 ( V_10 -> V_26 -> V_29 ) ;
V_32 = V_30 ? V_30 -> V_33 : 1000000 ;
F_29 () ;
if ( F_30 ( & V_10 -> V_34 ) < V_32 )
V_1 = F_10 ( V_10 , V_11 ) ;
while ( V_1 == NULL ) {
F_31 ( & V_35 , & V_31 , V_36 ) ;
F_19 ( V_10 ) ;
if ( F_30 ( & V_10 -> V_34 ) < V_32 ) {
V_1 = F_10 ( V_10 , V_11 ) ;
if ( V_1 )
break;
}
if ( ! V_28 )
break;
if ( F_32 ( V_37 ) ) {
F_33 ( V_38 , L_1 ) ;
break;
}
F_34 () ;
}
F_35 ( & V_35 , & V_31 ) ;
if ( V_1 )
F_36 ( V_11 , & V_10 -> V_34 ) ;
return V_1 ;
}
static void F_37 ( struct V_9 * V_10 , struct V_1 * V_1 , int V_39 )
{
T_1 * V_40 = V_39 ? & V_10 -> V_41 : & V_10 -> V_34 ;
int V_6 ;
if ( V_1 == NULL )
return;
if ( V_12 > ( V_42 / V_43 ) * V_44 )
V_6 = F_6 ( V_1 ) ;
else {
struct V_1 * V_4 ;
V_4 = F_5 ( V_1 , & V_6 ) ;
F_11 ( & V_13 ) ;
F_9 ( & V_14 , V_1 , V_4 ) ;
V_12 += V_6 ;
F_12 ( & V_13 ) ;
}
V_6 = F_38 ( V_6 , V_40 ) ;
if ( V_6 < 0 )
F_33 ( V_38 , L_2 ,
V_39 ? L_3 : L_4 , V_6 ) ;
F_39 ( & V_35 ) ;
}
struct V_18 *
F_40 ( struct V_9 * V_10 , T_2 V_45 , T_3 V_46 ,
unsigned int V_47 , T_4 V_48 ) __must_hold( T_5 )
{
struct V_18 * V_19 ;
struct V_1 * V_1 = NULL ;
unsigned V_49 = ( V_47 + V_43 - 1 ) >> V_50 ;
if ( F_41 ( V_10 , V_51 ) )
return NULL ;
V_19 = F_42 ( V_52 , V_48 & ~ V_53 ) ;
if ( ! V_19 ) {
if ( ! ( V_48 & V_54 ) )
F_43 ( V_38 , L_5 , V_55 ) ;
return NULL ;
}
if ( V_47 ) {
V_1 = F_25 ( V_10 , V_49 , ( V_48 & V_56 ) ) ;
if ( ! V_1 )
goto V_57;
}
F_44 ( & V_19 -> V_6 ) ;
V_19 -> V_6 . V_58 = V_47 ;
V_19 -> V_6 . V_46 = V_46 ;
V_19 -> V_6 . T_5 = false ;
V_19 -> V_6 . V_59 = false ;
V_19 -> V_60 = NULL ;
V_19 -> V_22 . V_10 = V_10 ;
V_19 -> V_61 = V_1 ;
F_45 ( & V_19 -> V_62 , 0 ) ;
V_19 -> V_63 = 0 ;
V_19 -> V_64 = V_45 ;
return V_19 ;
V_57:
F_46 ( V_19 , V_52 ) ;
return NULL ;
}
void F_47 ( struct V_9 * V_10 , struct V_18 * V_19 ,
int V_39 )
{
if ( V_19 -> V_63 & V_65 )
F_48 ( V_19 -> V_66 ) ;
F_37 ( V_10 , V_19 -> V_61 , V_39 ) ;
F_49 ( F_30 ( & V_19 -> V_62 ) == 0 ) ;
F_49 ( F_50 ( & V_19 -> V_6 ) ) ;
F_46 ( V_19 , V_52 ) ;
}
int F_51 ( struct V_9 * V_10 , struct V_16 * V_23 )
{
F_20 ( V_67 ) ;
struct V_18 * V_19 , * V_25 ;
int V_68 = 0 ;
int V_39 = V_23 == & V_10 -> V_69 ;
F_21 ( & V_10 -> V_26 -> V_27 ) ;
F_52 ( V_23 , & V_67 ) ;
F_22 ( & V_10 -> V_26 -> V_27 ) ;
F_23 (peer_req, t, &work_list, w.list) {
F_47 ( V_10 , V_19 , V_39 ) ;
V_68 ++ ;
}
return V_68 ;
}
static int F_53 ( struct V_9 * V_10 )
{
F_20 ( V_67 ) ;
F_20 ( V_24 ) ;
struct V_18 * V_19 , * V_25 ;
int V_70 = 0 ;
F_21 ( & V_10 -> V_26 -> V_27 ) ;
F_14 ( V_10 , & V_24 ) ;
F_52 ( & V_10 -> V_71 , & V_67 ) ;
F_22 ( & V_10 -> V_26 -> V_27 ) ;
F_23 (peer_req, t, &reclaimed, w.list)
F_24 ( V_10 , V_19 ) ;
F_23 (peer_req, t, &work_list, w.list) {
int V_72 ;
V_72 = V_19 -> V_22 . V_73 ( & V_19 -> V_22 , ! ! V_70 ) ;
if ( ! V_70 )
V_70 = V_72 ;
F_54 ( V_10 , V_19 ) ;
}
F_39 ( & V_10 -> V_74 ) ;
return V_70 ;
}
static void F_55 ( struct V_9 * V_10 ,
struct V_16 * V_2 )
{
F_26 ( V_31 ) ;
while ( ! F_56 ( V_2 ) ) {
F_31 ( & V_10 -> V_74 , & V_31 , V_75 ) ;
F_22 ( & V_10 -> V_26 -> V_27 ) ;
F_57 () ;
F_35 ( & V_10 -> V_74 , & V_31 ) ;
F_21 ( & V_10 -> V_26 -> V_27 ) ;
}
}
static void F_58 ( struct V_9 * V_10 ,
struct V_16 * V_2 )
{
F_21 ( & V_10 -> V_26 -> V_27 ) ;
F_55 ( V_10 , V_2 ) ;
F_22 ( & V_10 -> V_26 -> V_27 ) ;
}
static int F_59 ( struct V_76 * V_77 , void * V_78 , T_6 V_58 , int V_63 )
{
T_7 V_79 ;
struct V_80 V_81 = {
. V_82 = V_78 ,
. V_83 = V_58 ,
} ;
struct V_84 V_85 = {
. V_86 = 1 ,
. V_87 = (struct V_88 * ) & V_81 ,
. V_89 = ( V_63 ? V_63 : V_90 | V_91 )
} ;
int V_92 ;
V_79 = F_60 () ;
F_61 ( V_93 ) ;
V_92 = F_62 ( V_77 , & V_85 , V_58 , V_85 . V_89 ) ;
F_61 ( V_79 ) ;
return V_92 ;
}
static int F_63 ( struct V_94 * V_26 , void * V_78 , T_6 V_58 )
{
int V_92 ;
V_92 = F_59 ( V_26 -> V_95 . V_76 , V_78 , V_58 , 0 ) ;
if ( V_92 < 0 ) {
if ( V_92 == - V_96 )
F_64 ( V_26 , L_6 ) ;
else if ( V_92 != - V_97 )
F_65 ( V_26 , L_7 , V_92 ) ;
} else if ( V_92 == 0 ) {
if ( F_66 ( V_98 , & V_26 -> V_63 ) ) {
long V_25 ;
F_27 () ;
V_25 = F_28 ( V_26 -> V_29 ) -> V_99 * V_100 / 10 ;
F_29 () ;
V_25 = F_67 ( V_26 -> V_101 , V_26 -> V_102 < V_103 , V_25 ) ;
if ( V_25 )
goto V_104;
}
F_64 ( V_26 , L_8 ) ;
}
if ( V_92 != V_58 )
F_68 ( V_26 , F_69 ( V_105 , V_106 ) , V_107 ) ;
V_104:
return V_92 ;
}
static int F_70 ( struct V_94 * V_26 , void * V_78 , T_6 V_58 )
{
int V_70 ;
V_70 = F_63 ( V_26 , V_78 , V_58 ) ;
if ( V_70 != V_58 ) {
if ( V_70 >= 0 )
V_70 = - V_108 ;
} else
V_70 = 0 ;
return V_70 ;
}
static int F_71 ( struct V_94 * V_26 , void * V_78 , T_6 V_58 )
{
int V_70 ;
V_70 = F_70 ( V_26 , V_78 , V_58 ) ;
if ( V_70 && ! F_32 ( V_37 ) )
F_72 ( V_26 , L_9 , ( int ) V_58 ) ;
return V_70 ;
}
static void F_73 ( struct V_76 * V_77 , unsigned int V_109 ,
unsigned int V_110 )
{
if ( V_109 ) {
V_77 -> V_111 -> V_112 = V_109 ;
V_77 -> V_111 -> V_113 |= V_114 ;
}
if ( V_110 ) {
V_77 -> V_111 -> V_115 = V_110 ;
V_77 -> V_111 -> V_113 |= V_116 ;
}
}
static struct V_76 * F_74 ( struct V_94 * V_26 )
{
const char * V_117 ;
struct V_76 * V_77 ;
struct V_118 V_119 ;
struct V_118 V_120 ;
struct V_29 * V_30 ;
int V_70 , V_121 , V_122 ;
int V_123 , V_124 , V_125 ;
int V_126 = 1 ;
F_27 () ;
V_30 = F_28 ( V_26 -> V_29 ) ;
if ( ! V_30 ) {
F_29 () ;
return NULL ;
}
V_123 = V_30 -> V_123 ;
V_124 = V_30 -> V_124 ;
V_125 = V_30 -> V_125 ;
F_29 () ;
V_122 = F_75 ( int , V_26 -> V_122 , sizeof( V_119 ) ) ;
memcpy ( & V_119 , & V_26 -> V_127 , V_122 ) ;
if ( ( (struct V_128 * ) & V_26 -> V_127 ) -> V_129 == V_130 )
V_119 . V_131 = 0 ;
else
( (struct V_132 * ) & V_119 ) -> V_133 = 0 ;
V_121 = F_75 ( int , V_26 -> V_121 , sizeof( V_119 ) ) ;
memcpy ( & V_120 , & V_26 -> V_134 , V_121 ) ;
V_117 = L_10 ;
V_70 = F_76 ( ( (struct V_128 * ) & V_119 ) -> V_129 ,
V_135 , V_136 , & V_77 ) ;
if ( V_70 < 0 ) {
V_77 = NULL ;
goto V_104;
}
V_77 -> V_111 -> V_137 =
V_77 -> V_111 -> V_138 = V_125 * V_100 ;
F_73 ( V_77 , V_123 , V_124 ) ;
V_117 = L_11 ;
V_70 = V_77 -> V_139 -> V_140 ( V_77 , (struct V_128 * ) & V_119 , V_122 ) ;
if ( V_70 < 0 )
goto V_104;
V_126 = 0 ;
V_117 = L_12 ;
V_70 = V_77 -> V_139 -> V_141 ( V_77 , (struct V_128 * ) & V_120 , V_121 , 0 ) ;
V_104:
if ( V_70 < 0 ) {
if ( V_77 ) {
F_77 ( V_77 ) ;
V_77 = NULL ;
}
switch ( - V_70 ) {
case V_142 : case V_143 : case V_144 :
case V_145 : case V_97 :
case V_146 : case V_147 :
case V_148 : case V_149 :
V_126 = 0 ;
break;
default:
F_65 ( V_26 , L_13 , V_117 , V_70 ) ;
}
if ( V_126 )
F_68 ( V_26 , F_69 ( V_105 , V_150 ) , V_107 ) ;
}
return V_77 ;
}
static void F_78 ( struct V_77 * V_111 )
{
struct V_151 * V_152 = V_111 -> V_153 ;
void (* F_79)( struct V_77 * V_111 );
F_79 = V_152 -> V_154 ;
if ( V_111 -> V_155 == V_156 )
F_80 ( & V_152 -> V_157 ) ;
F_79 ( V_111 ) ;
}
static int F_81 ( struct V_94 * V_26 , struct V_151 * V_152 )
{
int V_70 , V_123 , V_124 , V_122 ;
struct V_118 V_127 ;
struct V_76 * V_158 ;
struct V_29 * V_30 ;
const char * V_117 ;
F_27 () ;
V_30 = F_28 ( V_26 -> V_29 ) ;
if ( ! V_30 ) {
F_29 () ;
return - V_108 ;
}
V_123 = V_30 -> V_123 ;
V_124 = V_30 -> V_124 ;
F_29 () ;
V_122 = F_75 ( int , V_26 -> V_122 , sizeof( struct V_118 ) ) ;
memcpy ( & V_127 , & V_26 -> V_127 , V_122 ) ;
V_117 = L_10 ;
V_70 = F_76 ( ( (struct V_128 * ) & V_127 ) -> V_129 ,
V_135 , V_136 , & V_158 ) ;
if ( V_70 ) {
V_158 = NULL ;
goto V_104;
}
V_158 -> V_111 -> V_159 = V_160 ;
F_73 ( V_158 , V_123 , V_124 ) ;
V_117 = L_14 ;
V_70 = V_158 -> V_139 -> V_140 ( V_158 , (struct V_128 * ) & V_127 , V_122 ) ;
if ( V_70 < 0 )
goto V_104;
V_152 -> V_158 = V_158 ;
F_82 ( & V_158 -> V_111 -> V_161 ) ;
V_152 -> V_154 = V_158 -> V_111 -> V_162 ;
V_158 -> V_111 -> V_162 = F_78 ;
V_158 -> V_111 -> V_153 = V_152 ;
F_83 ( & V_158 -> V_111 -> V_161 ) ;
V_117 = L_15 ;
V_70 = V_158 -> V_139 -> V_163 ( V_158 , 5 ) ;
if ( V_70 < 0 )
goto V_104;
return 0 ;
V_104:
if ( V_158 )
F_77 ( V_158 ) ;
if ( V_70 < 0 ) {
if ( V_70 != - V_143 && V_70 != - V_145 && V_70 != - V_97 ) {
F_65 ( V_26 , L_13 , V_117 , V_70 ) ;
F_68 ( V_26 , F_69 ( V_105 , V_150 ) , V_107 ) ;
}
}
return - V_108 ;
}
static void F_84 ( struct V_77 * V_111 , struct V_151 * V_152 )
{
F_82 ( & V_111 -> V_161 ) ;
V_111 -> V_162 = V_152 -> V_154 ;
V_111 -> V_153 = NULL ;
F_83 ( & V_111 -> V_161 ) ;
}
static struct V_76 * F_85 ( struct V_94 * V_26 , struct V_151 * V_152 )
{
int V_164 , V_125 , V_70 = 0 ;
struct V_76 * V_165 = NULL ;
struct V_29 * V_30 ;
F_27 () ;
V_30 = F_28 ( V_26 -> V_29 ) ;
if ( ! V_30 ) {
F_29 () ;
return NULL ;
}
V_125 = V_30 -> V_125 ;
F_29 () ;
V_164 = V_125 * V_100 ;
V_164 += ( F_86 () & 1 ) ? V_164 / 7 : - V_164 / 7 ;
V_70 = F_87 ( & V_152 -> V_157 , V_164 ) ;
if ( V_70 <= 0 )
return NULL ;
V_70 = F_88 ( V_152 -> V_158 , & V_165 , 0 ) ;
if ( V_70 < 0 ) {
if ( V_70 != - V_143 && V_70 != - V_145 && V_70 != - V_97 ) {
F_65 ( V_26 , L_16 , V_70 ) ;
F_68 ( V_26 , F_69 ( V_105 , V_150 ) , V_107 ) ;
}
}
if ( V_165 )
F_84 ( V_165 -> V_111 , V_152 ) ;
return V_165 ;
}
static int F_89 ( struct V_94 * V_26 , struct V_166 * V_77 ,
enum V_167 V_168 )
{
if ( ! F_90 ( V_26 , V_77 ) )
return - V_108 ;
return F_91 ( V_26 , V_77 , V_168 , 0 , NULL , 0 ) ;
}
static int F_92 ( struct V_94 * V_26 , struct V_76 * V_77 )
{
unsigned int V_169 = F_93 ( V_26 ) ;
struct V_170 V_171 ;
int V_70 ;
V_70 = F_59 ( V_77 , V_26 -> V_95 . V_172 , V_169 , 0 ) ;
if ( V_70 != V_169 ) {
if ( V_70 >= 0 )
V_70 = - V_108 ;
return V_70 ;
}
V_70 = F_94 ( V_26 , V_26 -> V_95 . V_172 , & V_171 ) ;
if ( V_70 )
return V_70 ;
return V_171 . V_168 ;
}
static int F_95 ( struct V_76 * * V_77 )
{
int V_173 ;
char V_174 [ 4 ] ;
if ( ! * V_77 )
return false ;
V_173 = F_59 ( * V_77 , V_174 , 4 , V_175 | V_176 ) ;
if ( V_173 > 0 || V_173 == - V_143 ) {
return true ;
} else {
F_77 ( * V_77 ) ;
* V_77 = NULL ;
return false ;
}
}
int F_96 ( struct V_9 * V_10 )
{
int V_70 ;
F_45 ( & V_10 -> V_177 , 0 ) ;
V_10 -> V_178 = 0 ;
V_10 -> V_179 = V_10 -> V_26 -> V_180 < 100 ?
& V_10 -> V_26 -> V_181 :
& V_10 -> V_182 ;
V_70 = F_97 ( V_10 ) ;
if ( ! V_70 )
V_70 = F_98 ( V_10 , 0 , 0 ) ;
if ( ! V_70 )
V_70 = F_99 ( V_10 ) ;
if ( ! V_70 )
V_70 = F_100 ( V_10 ) ;
F_101 ( V_183 , & V_10 -> V_63 ) ;
F_101 ( V_184 , & V_10 -> V_63 ) ;
F_102 ( & V_10 -> V_185 , V_186 + V_100 ) ;
return V_70 ;
}
static int F_103 ( struct V_94 * V_26 )
{
struct V_166 V_77 , V_187 ;
struct V_9 * V_10 ;
struct V_29 * V_30 ;
int V_188 , V_189 , V_190 , V_191 ;
bool V_192 ;
enum V_193 V_92 ;
struct V_151 V_152 = {
. V_26 = V_26 ,
. V_157 = F_104 ( V_152 . V_157 ) ,
} ;
F_101 ( V_98 , & V_26 -> V_63 ) ;
if ( F_68 ( V_26 , F_69 ( V_105 , V_194 ) , V_195 ) < V_196 )
return - 2 ;
F_105 ( & V_77 . V_197 ) ;
V_77 . V_198 = V_26 -> V_95 . V_198 ;
V_77 . V_172 = V_26 -> V_95 . V_172 ;
V_77 . V_76 = NULL ;
F_105 ( & V_187 . V_197 ) ;
V_187 . V_198 = V_26 -> V_199 . V_198 ;
V_187 . V_172 = V_26 -> V_199 . V_172 ;
V_187 . V_76 = NULL ;
V_26 -> V_180 = 80 ;
if ( F_81 ( V_26 , & V_152 ) )
return 0 ;
do {
struct V_76 * V_200 ;
V_200 = F_74 ( V_26 ) ;
if ( V_200 ) {
if ( ! V_77 . V_76 ) {
V_77 . V_76 = V_200 ;
F_89 ( V_26 , & V_77 , V_201 ) ;
} else if ( ! V_187 . V_76 ) {
F_101 ( V_202 , & V_26 -> V_63 ) ;
V_187 . V_76 = V_200 ;
F_89 ( V_26 , & V_187 , V_203 ) ;
} else {
F_65 ( V_26 , L_17 ) ;
goto V_204;
}
}
if ( V_77 . V_76 && V_187 . V_76 ) {
F_27 () ;
V_30 = F_28 ( V_26 -> V_29 ) ;
V_189 = V_30 -> V_99 * V_100 / 10 ;
F_29 () ;
F_106 ( V_189 ) ;
V_191 = F_95 ( & V_77 . V_76 ) ;
V_191 = F_95 ( & V_187 . V_76 ) && V_191 ;
if ( V_191 )
break;
}
V_28:
V_200 = F_85 ( V_26 , & V_152 ) ;
if ( V_200 ) {
int V_205 = F_92 ( V_26 , V_200 ) ;
F_95 ( & V_77 . V_76 ) ;
F_95 ( & V_187 . V_76 ) ;
switch ( V_205 ) {
case V_201 :
if ( V_77 . V_76 ) {
F_72 ( V_26 , L_18 ) ;
F_77 ( V_77 . V_76 ) ;
V_77 . V_76 = V_200 ;
goto V_206;
}
V_77 . V_76 = V_200 ;
break;
case V_203 :
F_107 ( V_202 , & V_26 -> V_63 ) ;
if ( V_187 . V_76 ) {
F_72 ( V_26 , L_19 ) ;
F_77 ( V_187 . V_76 ) ;
V_187 . V_76 = V_200 ;
goto V_206;
}
V_187 . V_76 = V_200 ;
break;
default:
F_72 ( V_26 , L_20 ) ;
F_77 ( V_200 ) ;
V_206:
if ( F_86 () & 1 )
goto V_28;
}
}
if ( V_26 -> V_102 <= V_150 )
goto V_204;
if ( F_32 ( V_37 ) ) {
F_108 ( V_37 ) ;
F_109 () ;
if ( F_110 ( & V_26 -> V_207 ) == V_208 )
goto V_204;
}
V_191 = F_95 ( & V_77 . V_76 ) ;
V_191 = F_95 ( & V_187 . V_76 ) && V_191 ;
} while ( ! V_191 );
if ( V_152 . V_158 )
F_77 ( V_152 . V_158 ) ;
V_77 . V_76 -> V_111 -> V_159 = V_160 ;
V_187 . V_76 -> V_111 -> V_159 = V_160 ;
V_77 . V_76 -> V_111 -> V_209 = V_210 ;
V_187 . V_76 -> V_111 -> V_209 = V_210 ;
V_77 . V_76 -> V_111 -> V_211 = V_212 ;
V_187 . V_76 -> V_111 -> V_211 = V_213 ;
F_27 () ;
V_30 = F_28 ( V_26 -> V_29 ) ;
V_77 . V_76 -> V_111 -> V_138 =
V_77 . V_76 -> V_111 -> V_137 = V_30 -> V_99 * 4 * V_100 / 10 ;
V_187 . V_76 -> V_111 -> V_137 = V_30 -> V_214 * V_100 ;
V_189 = V_30 -> V_189 * V_100 / 10 ;
V_192 = V_30 -> V_192 ;
F_29 () ;
V_187 . V_76 -> V_111 -> V_138 = V_189 ;
F_111 ( V_77 . V_76 ) ;
F_111 ( V_187 . V_76 ) ;
V_26 -> V_95 . V_76 = V_77 . V_76 ;
V_26 -> V_199 . V_76 = V_187 . V_76 ;
V_26 -> V_215 = V_186 ;
V_190 = F_112 ( V_26 ) ;
if ( V_190 <= 0 )
return V_190 ;
if ( V_26 -> V_216 ) {
switch ( F_113 ( V_26 ) ) {
case - 1 :
F_65 ( V_26 , L_21 ) ;
return - 1 ;
case 0 :
F_65 ( V_26 , L_22 ) ;
return 0 ;
}
}
V_26 -> V_95 . V_76 -> V_111 -> V_138 = V_189 ;
V_26 -> V_95 . V_76 -> V_111 -> V_137 = V_217 ;
if ( F_114 ( V_26 ) == - V_218 )
return - 1 ;
F_107 ( V_219 , & V_26 -> V_63 ) ;
F_27 () ;
F_115 (&tconn->volumes, mdev, vnr) {
F_116 ( & V_10 -> V_220 ) ;
F_117 ( V_10 -> V_179 ) ;
F_118 ( V_10 -> V_179 ) ;
F_29 () ;
if ( V_192 )
F_107 ( V_221 , & V_10 -> V_63 ) ;
else
F_101 ( V_221 , & V_10 -> V_63 ) ;
F_96 ( V_10 ) ;
F_119 ( & V_10 -> V_220 , & V_222 ) ;
F_27 () ;
}
F_29 () ;
V_92 = F_68 ( V_26 , F_69 ( V_105 , V_103 ) , V_195 ) ;
if ( V_92 < V_196 || V_26 -> V_102 != V_103 ) {
F_101 ( V_219 , & V_26 -> V_63 ) ;
return 0 ;
}
F_120 ( & V_26 -> V_223 ) ;
F_117 ( & V_26 -> V_224 ) ;
V_26 -> V_29 -> V_192 = 0 ;
F_118 ( & V_26 -> V_224 ) ;
return V_190 ;
V_204:
if ( V_152 . V_158 )
F_77 ( V_152 . V_158 ) ;
if ( V_77 . V_76 )
F_77 ( V_77 . V_76 ) ;
if ( V_187 . V_76 )
F_77 ( V_187 . V_76 ) ;
return - 1 ;
}
static int F_94 ( struct V_94 * V_26 , void * V_225 , struct V_170 * V_171 )
{
unsigned int V_169 = F_93 ( V_26 ) ;
if ( V_169 == sizeof( struct V_226 ) &&
* ( V_227 * ) V_225 == F_121 ( V_228 ) ) {
struct V_226 * V_190 = V_225 ;
if ( V_190 -> V_229 != 0 ) {
F_65 ( V_26 , L_23 ) ;
return - V_230 ;
}
V_171 -> V_188 = F_122 ( V_190 -> V_231 ) ;
V_171 -> V_168 = F_122 ( V_190 -> V_232 ) ;
V_171 -> V_58 = F_123 ( V_190 -> V_233 ) ;
} else if ( V_169 == sizeof( struct V_234 ) &&
* ( V_235 * ) V_225 == F_124 ( V_236 ) ) {
struct V_234 * V_190 = V_225 ;
V_171 -> V_168 = F_122 ( V_190 -> V_232 ) ;
V_171 -> V_58 = F_123 ( V_190 -> V_233 ) ;
V_171 -> V_188 = 0 ;
} else if ( V_169 == sizeof( struct V_237 ) &&
* ( V_227 * ) V_225 == F_121 ( V_238 ) ) {
struct V_237 * V_190 = V_225 ;
V_171 -> V_168 = F_122 ( V_190 -> V_232 ) ;
V_171 -> V_58 = F_122 ( V_190 -> V_233 ) ;
V_171 -> V_188 = 0 ;
} else {
F_65 ( V_26 , L_24 ,
F_123 ( * ( V_227 * ) V_225 ) ,
V_26 -> V_180 ) ;
return - V_230 ;
}
V_171 -> V_95 = V_225 + V_169 ;
return 0 ;
}
static int F_125 ( struct V_94 * V_26 , struct V_170 * V_171 )
{
void * V_239 = V_26 -> V_95 . V_172 ;
int V_70 ;
V_70 = F_71 ( V_26 , V_239 , F_93 ( V_26 ) ) ;
if ( V_70 )
return V_70 ;
V_70 = F_94 ( V_26 , V_239 , V_171 ) ;
V_26 -> V_215 = V_186 ;
return V_70 ;
}
static void F_126 ( struct V_94 * V_26 )
{
int V_92 ;
struct V_9 * V_10 ;
int V_188 ;
if ( V_26 -> V_240 >= V_241 ) {
F_27 () ;
F_115 (&tconn->volumes, mdev, vnr) {
if ( ! F_127 ( V_10 ) )
continue;
F_116 ( & V_10 -> V_220 ) ;
F_29 () ;
V_92 = F_128 ( V_10 -> V_242 -> V_243 ,
V_210 , NULL ) ;
if ( V_92 ) {
F_129 ( V_38 , L_25 , V_92 ) ;
F_130 ( V_26 , V_244 ) ;
}
F_131 ( V_10 ) ;
F_119 ( & V_10 -> V_220 , & V_222 ) ;
F_27 () ;
if ( V_92 )
break;
}
F_29 () ;
}
}
static enum V_245 F_132 ( struct V_94 * V_26 ,
struct V_246 * V_60 ,
enum V_247 V_248 )
{
int V_249 ;
struct V_246 * V_250 ;
enum V_245 V_92 = V_251 ;
F_11 ( & V_26 -> V_252 ) ;
do {
V_250 = NULL ;
V_249 = F_30 ( & V_60 -> V_249 ) ;
switch ( V_248 & ~ V_253 ) {
case V_254 :
F_133 ( & V_60 -> V_255 ) ;
break;
case V_256 :
F_107 ( V_257 , & V_60 -> V_63 ) ;
break;
case V_258 :
break;
}
if ( V_249 != 0 &&
F_30 ( & V_60 -> V_255 ) == 0 &&
( F_66 ( V_257 , & V_60 -> V_63 ) || V_248 & V_253 ) ) {
if ( ! ( V_248 & V_253 ) ) {
F_12 ( & V_26 -> V_252 ) ;
F_134 ( V_60 -> V_26 , V_60 -> V_259 , V_249 ) ;
F_11 ( & V_26 -> V_252 ) ;
}
#if 0
if (test_bit(DE_HAVE_BARRIER_NUMBER, &epoch->flags))
dec_unacked(epoch->tconn);
#endif
if ( V_26 -> V_260 != V_60 ) {
V_250 = F_16 ( V_60 -> V_23 . V_261 , struct V_246 , V_23 ) ;
F_135 ( & V_60 -> V_23 ) ;
V_248 = V_258 | ( V_248 & V_253 ) ;
V_26 -> V_262 -- ;
F_48 ( V_60 ) ;
if ( V_92 == V_251 )
V_92 = V_263 ;
} else {
V_60 -> V_63 = 0 ;
F_45 ( & V_60 -> V_249 , 0 ) ;
if ( V_92 == V_251 )
V_92 = V_264 ;
}
}
if ( ! V_250 )
break;
V_60 = V_250 ;
} while ( 1 );
F_12 ( & V_26 -> V_252 ) ;
return V_92 ;
}
void F_130 ( struct V_94 * V_26 , enum V_265 V_266 )
{
struct V_267 * V_268 ;
struct V_9 * V_10 ;
enum V_265 V_269 ;
int V_188 ;
static char * V_270 [] = {
[ V_271 ] = L_26 ,
[ V_244 ] = L_27 ,
[ V_241 ] = L_28 ,
} ;
V_269 = V_26 -> V_240 ;
V_266 = F_136 ( V_269 , V_266 ) ;
F_27 () ;
F_115 (&tconn->volumes, mdev, vnr) {
if ( ! F_137 ( V_10 , V_272 ) )
continue;
V_268 = F_28 ( V_10 -> V_242 -> V_267 ) ;
if ( V_266 == V_241 && ! V_268 -> V_273 )
V_266 = V_244 ;
if ( V_266 == V_244 && ! V_268 -> V_274 )
V_266 = V_271 ;
F_131 ( V_10 ) ;
}
F_29 () ;
V_26 -> V_240 = V_266 ;
if ( V_269 != V_26 -> V_240 || V_266 == V_241 )
F_64 ( V_26 , L_29 , V_270 [ V_26 -> V_240 ] ) ;
}
int F_138 ( struct V_9 * V_10 ,
struct V_18 * V_19 ,
const unsigned V_275 , const int V_276 )
{
struct V_277 * V_278 = NULL ;
struct V_277 * V_277 ;
struct V_1 * V_1 = V_19 -> V_61 ;
T_3 V_46 = V_19 -> V_6 . V_46 ;
unsigned V_279 = V_19 -> V_6 . V_58 ;
unsigned V_280 = 0 ;
unsigned V_49 = ( V_279 + V_43 - 1 ) >> V_50 ;
int V_70 = - V_281 ;
V_282:
V_277 = F_139 ( V_210 , V_49 ) ;
if ( ! V_277 ) {
F_43 ( V_38 , L_30 ) ;
goto V_57;
}
V_277 -> V_283 = V_46 ;
V_277 -> V_284 = V_10 -> V_242 -> V_243 ;
V_277 -> V_285 = V_275 ;
V_277 -> V_286 = V_19 ;
V_277 -> V_287 = V_288 ;
V_277 -> V_289 = V_278 ;
V_278 = V_277 ;
++ V_280 ;
F_140 (page) {
unsigned V_5 = F_75 ( unsigned , V_279 , V_43 ) ;
if ( ! F_141 ( V_277 , V_1 , V_5 , 0 ) ) {
if ( V_277 -> V_290 == 0 ) {
F_43 ( V_38 ,
L_31
L_32 ,
V_5 , ( unsigned long long ) V_277 -> V_283 ) ;
V_70 = - V_291 ;
goto V_57;
}
goto V_282;
}
V_279 -= V_5 ;
V_46 += V_5 >> 9 ;
-- V_49 ;
}
F_49 ( V_1 == NULL ) ;
F_49 ( V_279 == 0 ) ;
F_45 ( & V_19 -> V_62 , V_280 ) ;
do {
V_277 = V_278 ;
V_278 = V_278 -> V_289 ;
V_277 -> V_289 = NULL ;
F_142 ( V_10 , V_276 , V_277 ) ;
} while ( V_278 );
return 0 ;
V_57:
while ( V_278 ) {
V_277 = V_278 ;
V_278 = V_278 -> V_289 ;
F_143 ( V_277 ) ;
}
return V_70 ;
}
static void F_144 ( struct V_9 * V_10 ,
struct V_18 * V_19 )
{
struct V_292 * V_6 = & V_19 -> V_6 ;
F_145 ( & V_10 -> V_293 , V_6 ) ;
F_44 ( V_6 ) ;
if ( V_6 -> V_59 )
F_39 ( & V_10 -> V_294 ) ;
}
void F_146 ( struct V_94 * V_26 )
{
struct V_9 * V_10 ;
int V_188 ;
F_27 () ;
F_115 (&tconn->volumes, mdev, vnr) {
F_116 ( & V_10 -> V_220 ) ;
F_29 () ;
F_58 ( V_10 , & V_10 -> V_295 ) ;
F_119 ( & V_10 -> V_220 , & V_222 ) ;
F_27 () ;
}
F_29 () ;
}
static int F_147 ( struct V_94 * V_26 , struct V_170 * V_171 )
{
int V_92 ;
struct V_296 * V_297 = V_171 -> V_95 ;
struct V_246 * V_60 ;
V_26 -> V_260 -> V_259 = V_297 -> V_298 ;
V_26 -> V_260 -> V_26 = V_26 ;
V_92 = F_132 ( V_26 , V_26 -> V_260 , V_256 ) ;
switch ( V_26 -> V_240 ) {
case V_271 :
if ( V_92 == V_264 )
return 0 ;
V_60 = F_148 ( sizeof( struct V_246 ) , V_210 ) ;
if ( V_60 )
break;
else
F_72 ( V_26 , L_33 ) ;
case V_241 :
case V_244 :
F_146 ( V_26 ) ;
F_126 ( V_26 ) ;
if ( F_30 ( & V_26 -> V_260 -> V_249 ) ) {
V_60 = F_148 ( sizeof( struct V_246 ) , V_210 ) ;
if ( V_60 )
break;
}
return 0 ;
default:
F_65 ( V_26 , L_34 , V_26 -> V_240 ) ;
return - V_108 ;
}
V_60 -> V_63 = 0 ;
F_45 ( & V_60 -> V_249 , 0 ) ;
F_45 ( & V_60 -> V_255 , 0 ) ;
F_11 ( & V_26 -> V_252 ) ;
if ( F_30 ( & V_26 -> V_260 -> V_249 ) ) {
F_149 ( & V_60 -> V_23 , & V_26 -> V_260 -> V_23 ) ;
V_26 -> V_260 = V_60 ;
V_26 -> V_262 ++ ;
} else {
F_48 ( V_60 ) ;
}
F_12 ( & V_26 -> V_252 ) ;
return 0 ;
}
static struct V_18 *
F_150 ( struct V_9 * V_10 , T_2 V_45 , T_3 V_46 ,
int V_47 ) __must_hold( T_5 )
{
const T_3 V_299 = F_151 ( V_10 -> V_300 ) ;
struct V_18 * V_19 ;
struct V_1 * V_1 ;
int V_301 , V_279 , V_70 ;
void * V_302 = V_10 -> V_26 -> V_303 ;
void * V_304 = V_10 -> V_26 -> V_305 ;
unsigned long * V_95 ;
V_301 = 0 ;
if ( V_10 -> V_26 -> V_306 ) {
V_301 = F_152 ( V_10 -> V_26 -> V_306 ) ;
V_70 = F_71 ( V_10 -> V_26 , V_302 , V_301 ) ;
if ( V_70 )
return NULL ;
V_47 -= V_301 ;
}
if ( ! F_153 ( F_154 ( V_47 , 512 ) ) )
return NULL ;
if ( ! F_153 ( V_47 <= V_42 ) )
return NULL ;
if ( V_46 + ( V_47 >> 9 ) > V_299 ) {
F_43 ( V_38 , L_35
L_36 ,
( unsigned long long ) V_299 ,
( unsigned long long ) V_46 , V_47 ) ;
return NULL ;
}
V_19 = F_40 ( V_10 , V_45 , V_46 , V_47 , V_210 ) ;
if ( ! V_19 )
return NULL ;
if ( ! V_47 )
return V_19 ;
V_279 = V_47 ;
V_1 = V_19 -> V_61 ;
F_140 (page) {
unsigned V_5 = F_75 ( int , V_279 , V_43 ) ;
V_95 = F_155 ( V_1 ) ;
V_70 = F_71 ( V_10 -> V_26 , V_95 , V_5 ) ;
if ( F_41 ( V_10 , V_307 ) ) {
F_43 ( V_38 , L_37 ) ;
V_95 [ 0 ] = V_95 [ 0 ] ^ ( unsigned long ) - 1 ;
}
F_156 ( V_1 ) ;
if ( V_70 ) {
F_54 ( V_10 , V_19 ) ;
return NULL ;
}
V_279 -= V_5 ;
}
if ( V_301 ) {
F_157 ( V_10 , V_10 -> V_26 -> V_306 , V_19 , V_304 ) ;
if ( memcmp ( V_302 , V_304 , V_301 ) ) {
F_43 ( V_38 , L_38 ,
( unsigned long long ) V_46 , V_47 ) ;
F_54 ( V_10 , V_19 ) ;
return NULL ;
}
}
V_10 -> V_308 += V_47 >> 9 ;
return V_19 ;
}
static int F_158 ( struct V_9 * V_10 , int V_47 )
{
struct V_1 * V_1 ;
int V_70 = 0 ;
void * V_95 ;
if ( ! V_47 )
return 0 ;
V_1 = F_25 ( V_10 , 1 , 1 ) ;
V_95 = F_155 ( V_1 ) ;
while ( V_47 ) {
unsigned int V_5 = F_75 ( int , V_47 , V_43 ) ;
V_70 = F_71 ( V_10 -> V_26 , V_95 , V_5 ) ;
if ( V_70 )
break;
V_47 -= V_5 ;
}
F_156 ( V_1 ) ;
F_37 ( V_10 , V_1 , 0 ) ;
return V_70 ;
}
static int F_159 ( struct V_9 * V_10 , struct V_309 * V_310 ,
T_3 V_46 , int V_47 )
{
struct V_311 * V_312 ;
struct V_277 * V_277 ;
int V_301 , V_70 , V_6 , F_153 ;
void * V_302 = V_10 -> V_26 -> V_303 ;
void * V_304 = V_10 -> V_26 -> V_305 ;
V_301 = 0 ;
if ( V_10 -> V_26 -> V_306 ) {
V_301 = F_152 ( V_10 -> V_26 -> V_306 ) ;
V_70 = F_71 ( V_10 -> V_26 , V_302 , V_301 ) ;
if ( V_70 )
return V_70 ;
V_47 -= V_301 ;
}
V_10 -> V_308 += V_47 >> 9 ;
V_277 = V_310 -> V_313 ;
F_49 ( V_46 == V_277 -> V_283 ) ;
F_160 (bvec, bio, i) {
void * V_314 = F_155 ( V_312 -> V_315 ) + V_312 -> V_316 ;
F_153 = F_75 ( int , V_47 , V_312 -> V_317 ) ;
V_70 = F_71 ( V_10 -> V_26 , V_314 , F_153 ) ;
F_156 ( V_312 -> V_315 ) ;
if ( V_70 )
return V_70 ;
V_47 -= F_153 ;
}
if ( V_301 ) {
F_161 ( V_10 , V_10 -> V_26 -> V_306 , V_277 , V_304 ) ;
if ( memcmp ( V_302 , V_304 , V_301 ) ) {
F_43 ( V_38 , L_39 ) ;
return - V_230 ;
}
}
F_49 ( V_47 == 0 ) ;
return 0 ;
}
static int F_162 ( struct V_318 * V_22 , int V_319 )
{
struct V_18 * V_19 =
F_163 ( V_22 , struct V_18 , V_22 ) ;
struct V_9 * V_10 = V_22 -> V_10 ;
T_3 V_46 = V_19 -> V_6 . V_46 ;
int V_70 ;
F_49 ( F_50 ( & V_19 -> V_6 ) ) ;
if ( F_164 ( ( V_19 -> V_63 & V_320 ) == 0 ) ) {
F_165 ( V_10 , V_46 , V_19 -> V_6 . V_58 ) ;
V_70 = F_166 ( V_10 , V_321 , V_19 ) ;
} else {
F_167 ( V_10 , V_46 , V_19 -> V_6 . V_58 ) ;
V_70 = F_166 ( V_10 , V_322 , V_19 ) ;
}
F_168 ( V_10 ) ;
return V_70 ;
}
static int F_169 ( struct V_9 * V_10 , T_3 V_46 , int V_47 ) __releases( T_5 )
{
struct V_18 * V_19 ;
V_19 = F_150 ( V_10 , V_323 , V_46 , V_47 ) ;
if ( ! V_19 )
goto V_57;
F_170 ( V_10 ) ;
F_171 ( V_10 ) ;
V_19 -> V_22 . V_73 = F_162 ;
F_21 ( & V_10 -> V_26 -> V_27 ) ;
F_149 ( & V_19 -> V_22 . V_23 , & V_10 -> V_324 ) ;
F_22 ( & V_10 -> V_26 -> V_27 ) ;
F_36 ( V_47 >> 9 , & V_10 -> V_325 ) ;
if ( F_138 ( V_10 , V_19 , V_326 , V_327 ) == 0 )
return 0 ;
F_43 ( V_38 , L_40 ) ;
F_21 ( & V_10 -> V_26 -> V_27 ) ;
F_135 ( & V_19 -> V_22 . V_23 ) ;
F_22 ( & V_10 -> V_26 -> V_27 ) ;
F_54 ( V_10 , V_19 ) ;
V_57:
F_131 ( V_10 ) ;
return - V_108 ;
}
static struct V_309 *
F_172 ( struct V_9 * V_10 , struct V_328 * V_329 , T_2 V_45 ,
T_3 V_46 , bool V_330 , const char * V_331 )
{
struct V_309 * V_310 ;
V_310 = (struct V_309 * ) ( unsigned long ) V_45 ;
if ( F_173 ( V_329 , V_46 , & V_310 -> V_6 ) && V_310 -> V_6 . T_5 )
return V_310 ;
if ( ! V_330 ) {
F_43 ( V_38 , L_41 , V_331 ,
( unsigned long ) V_45 , ( unsigned long long ) V_46 ) ;
}
return NULL ;
}
static int F_174 ( struct V_94 * V_26 , struct V_170 * V_171 )
{
struct V_9 * V_10 ;
struct V_309 * V_310 ;
T_3 V_46 ;
int V_70 ;
struct V_332 * V_297 = V_171 -> V_95 ;
V_10 = F_175 ( V_26 , V_171 -> V_188 ) ;
if ( ! V_10 )
return - V_108 ;
V_46 = F_176 ( V_297 -> V_46 ) ;
F_21 ( & V_10 -> V_26 -> V_27 ) ;
V_310 = F_172 ( V_10 , & V_10 -> V_333 , V_297 -> V_64 , V_46 , false , V_55 ) ;
F_22 ( & V_10 -> V_26 -> V_27 ) ;
if ( F_177 ( ! V_310 ) )
return - V_108 ;
V_70 = F_159 ( V_10 , V_310 , V_46 , V_171 -> V_58 ) ;
if ( ! V_70 )
F_178 ( V_310 , V_334 ) ;
return V_70 ;
}
static int F_179 ( struct V_94 * V_26 , struct V_170 * V_171 )
{
struct V_9 * V_10 ;
T_3 V_46 ;
int V_70 ;
struct V_332 * V_297 = V_171 -> V_95 ;
V_10 = F_175 ( V_26 , V_171 -> V_188 ) ;
if ( ! V_10 )
return - V_108 ;
V_46 = F_176 ( V_297 -> V_46 ) ;
F_49 ( V_297 -> V_64 == V_323 ) ;
if ( F_127 ( V_10 ) ) {
V_70 = F_169 ( V_10 , V_46 , V_171 -> V_58 ) ;
} else {
if ( F_180 ( & V_335 ) )
F_43 ( V_38 , L_42 ) ;
V_70 = F_158 ( V_10 , V_171 -> V_58 ) ;
F_181 ( V_10 , V_322 , V_297 , V_171 -> V_58 ) ;
}
F_36 ( V_171 -> V_58 >> 9 , & V_10 -> V_336 ) ;
return V_70 ;
}
static void F_182 ( struct V_9 * V_10 ,
T_3 V_46 , int V_58 )
{
struct V_292 * V_6 ;
struct V_309 * V_310 ;
F_183 (i, &mdev->write_requests, sector, size) {
if ( ! V_6 -> T_5 )
continue;
V_310 = F_163 ( V_6 , struct V_309 , V_6 ) ;
if ( V_310 -> V_337 & V_338 ||
! ( V_310 -> V_337 & V_339 ) )
continue;
F_184 ( V_310 , V_340 , NULL ) ;
}
}
static int F_185 ( struct V_318 * V_22 , int V_341 )
{
struct V_18 * V_19 =
F_163 ( V_22 , struct V_18 , V_22 ) ;
struct V_9 * V_10 = V_22 -> V_10 ;
T_3 V_46 = V_19 -> V_6 . V_46 ;
int V_70 = 0 , V_342 ;
if ( V_19 -> V_63 & V_343 ) {
if ( F_164 ( ( V_19 -> V_63 & V_320 ) == 0 ) ) {
V_342 = ( V_10 -> V_344 . V_105 >= V_345 &&
V_10 -> V_344 . V_105 <= V_346 &&
V_19 -> V_63 & V_347 ) ?
V_321 : V_348 ;
V_70 = F_166 ( V_10 , V_342 , V_19 ) ;
if ( V_342 == V_321 )
F_165 ( V_10 , V_46 , V_19 -> V_6 . V_58 ) ;
} else {
V_70 = F_166 ( V_10 , V_322 , V_19 ) ;
}
F_168 ( V_10 ) ;
}
if ( V_19 -> V_63 & V_349 ) {
F_21 ( & V_10 -> V_26 -> V_27 ) ;
F_49 ( ! F_50 ( & V_19 -> V_6 ) ) ;
F_144 ( V_10 , V_19 ) ;
if ( V_19 -> V_63 & V_350 )
F_182 ( V_10 , V_46 , V_19 -> V_6 . V_58 ) ;
F_22 ( & V_10 -> V_26 -> V_27 ) ;
} else
F_49 ( F_50 ( & V_19 -> V_6 ) ) ;
F_132 ( V_10 -> V_26 , V_19 -> V_60 , V_254 + ( V_341 ? V_253 : 0 ) ) ;
return V_70 ;
}
static int F_186 ( struct V_318 * V_22 , enum V_167 V_351 )
{
struct V_9 * V_10 = V_22 -> V_10 ;
struct V_18 * V_19 =
F_163 ( V_22 , struct V_18 , V_22 ) ;
int V_70 ;
V_70 = F_166 ( V_10 , V_351 , V_19 ) ;
F_168 ( V_10 ) ;
return V_70 ;
}
static int F_187 ( struct V_318 * V_22 , int V_319 )
{
return F_186 ( V_22 , V_352 ) ;
}
static int F_188 ( struct V_318 * V_22 , int V_319 )
{
struct V_94 * V_26 = V_22 -> V_10 -> V_26 ;
return F_186 ( V_22 , V_26 -> V_180 >= 100 ?
V_353 : V_352 ) ;
}
static bool F_189 ( T_8 V_40 , T_8 V_354 )
{
return ( V_355 ) V_40 - ( V_355 ) V_354 > 0 ;
}
static T_8 F_190 ( T_8 V_40 , T_8 V_354 )
{
return F_189 ( V_40 , V_354 ) ? V_40 : V_354 ;
}
static bool F_191 ( struct V_9 * V_10 )
{
struct V_94 * V_26 = V_10 -> V_26 ;
int V_356 ;
F_27 () ;
V_356 = F_28 ( V_10 -> V_26 -> V_29 ) -> V_357 ;
F_29 () ;
return V_356 && F_66 ( V_202 , & V_26 -> V_63 ) ;
}
static void F_192 ( struct V_9 * V_10 , unsigned int V_178 )
{
unsigned int V_358 ;
if ( F_191 ( V_10 ) ) {
F_11 ( & V_10 -> V_359 ) ;
V_358 = F_190 ( V_10 -> V_178 , V_178 ) ;
V_10 -> V_178 = V_358 ;
F_12 ( & V_10 -> V_359 ) ;
if ( V_178 == V_358 )
F_39 ( & V_10 -> V_360 ) ;
}
}
static inline int F_193 ( T_3 V_361 , int V_362 , T_3 V_363 , int V_364 )
{
return ! ( ( V_361 + ( V_362 >> 9 ) <= V_363 ) || ( V_361 >= V_363 + ( V_364 >> 9 ) ) ) ;
}
static bool F_194 ( struct V_9 * V_10 , struct V_18 * V_19 )
{
struct V_18 * V_365 ;
bool V_92 = 0 ;
F_21 ( & V_10 -> V_26 -> V_27 ) ;
F_195 (rs_req, &mdev->sync_ee, w.list) {
if ( F_193 ( V_19 -> V_6 . V_46 , V_19 -> V_6 . V_58 ,
V_365 -> V_6 . V_46 , V_365 -> V_6 . V_58 ) ) {
V_92 = 1 ;
break;
}
}
F_22 ( & V_10 -> V_26 -> V_27 ) ;
return V_92 ;
}
static int F_196 ( struct V_9 * V_10 , const T_8 V_178 )
{
F_26 ( V_31 ) ;
long V_189 ;
int V_366 ;
if ( ! F_191 ( V_10 ) )
return 0 ;
F_11 ( & V_10 -> V_359 ) ;
for (; ; ) {
if ( ! F_189 ( V_178 - 1 , V_10 -> V_178 ) ) {
V_10 -> V_178 = F_190 ( V_10 -> V_178 , V_178 ) ;
V_366 = 0 ;
break;
}
if ( F_32 ( V_37 ) ) {
V_366 = - V_97 ;
break;
}
F_31 ( & V_10 -> V_360 , & V_31 , V_36 ) ;
F_12 ( & V_10 -> V_359 ) ;
F_27 () ;
V_189 = F_28 ( V_10 -> V_26 -> V_29 ) -> V_99 * V_100 / 10 ;
F_29 () ;
V_189 = F_197 ( V_189 ) ;
F_11 ( & V_10 -> V_359 ) ;
if ( ! V_189 ) {
V_366 = - V_142 ;
F_43 ( V_38 , L_43 ) ;
break;
}
}
F_12 ( & V_10 -> V_359 ) ;
F_35 ( & V_10 -> V_360 , & V_31 ) ;
return V_366 ;
}
static unsigned long F_198 ( struct V_9 * V_10 , T_8 V_367 )
{
return ( V_367 & V_368 ? V_369 : 0 ) |
( V_367 & V_370 ? V_371 : 0 ) |
( V_367 & V_372 ? V_373 : 0 ) |
( V_367 & V_374 ? V_375 : 0 ) ;
}
static void F_199 ( struct V_9 * V_10 , T_3 V_46 ,
unsigned int V_58 )
{
struct V_292 * V_6 ;
V_376:
F_183 (i, &mdev->write_requests, sector, size) {
struct V_309 * V_310 ;
struct V_377 V_378 ;
if ( ! V_6 -> T_5 )
continue;
V_310 = F_163 ( V_6 , struct V_309 , V_6 ) ;
if ( ! ( V_310 -> V_337 & V_339 ) )
continue;
V_310 -> V_337 &= ~ V_339 ;
F_184 ( V_310 , V_379 , & V_378 ) ;
F_22 ( & V_10 -> V_26 -> V_27 ) ;
if ( V_378 . V_277 )
F_200 ( V_10 , & V_378 ) ;
F_21 ( & V_10 -> V_26 -> V_27 ) ;
goto V_376;
}
}
static int F_201 ( struct V_9 * V_10 ,
struct V_18 * V_19 )
{
struct V_94 * V_26 = V_10 -> V_26 ;
bool V_380 = F_66 ( V_202 , & V_26 -> V_63 ) ;
T_3 V_46 = V_19 -> V_6 . V_46 ;
const unsigned int V_58 = V_19 -> V_6 . V_58 ;
struct V_292 * V_6 ;
bool V_381 ;
int V_70 ;
F_202 ( & V_10 -> V_293 , & V_19 -> V_6 ) ;
V_376:
F_183 (i, &mdev->write_requests, sector, size) {
if ( V_6 == & V_19 -> V_6 )
continue;
if ( ! V_6 -> T_5 ) {
V_70 = F_203 ( V_10 , V_6 ) ;
if ( V_70 )
goto V_104;
goto V_376;
}
V_381 = V_6 -> V_46 == V_46 && V_6 -> V_58 == V_58 ;
if ( V_380 ) {
bool V_382 = V_6 -> V_46 <= V_46 && V_6 -> V_46 +
( V_6 -> V_58 >> 9 ) >= V_46 + ( V_58 >> 9 ) ;
if ( ! V_381 )
F_204 ( V_38 , L_44
L_45
L_46 ,
( unsigned long long ) V_6 -> V_46 , V_6 -> V_58 ,
( unsigned long long ) V_46 , V_58 ,
V_382 ? L_47 : L_48 ) ;
F_171 ( V_10 ) ;
V_19 -> V_22 . V_73 = V_382 ? F_187 :
F_188 ;
F_205 ( & V_19 -> V_22 . V_23 , & V_10 -> V_71 ) ;
F_206 ( V_10 -> V_26 ) ;
V_70 = - V_383 ;
goto V_104;
} else {
struct V_309 * V_310 =
F_163 ( V_6 , struct V_309 , V_6 ) ;
if ( ! V_381 )
F_204 ( V_38 , L_44
L_49 ,
( unsigned long long ) V_6 -> V_46 , V_6 -> V_58 ,
( unsigned long long ) V_46 , V_58 ) ;
if ( V_310 -> V_337 & V_338 ||
! ( V_310 -> V_337 & V_339 ) ) {
V_70 = F_203 ( V_10 , & V_310 -> V_6 ) ;
if ( V_70 ) {
F_207 ( V_10 -> V_26 ,
F_69 ( V_105 , V_384 ) ,
V_107 ) ;
F_199 ( V_10 , V_46 , V_58 ) ;
goto V_104;
}
goto V_376;
}
V_19 -> V_63 |= V_350 ;
}
}
V_70 = 0 ;
V_104:
if ( V_70 )
F_144 ( V_10 , V_19 ) ;
return V_70 ;
}
static int F_208 ( struct V_94 * V_26 , struct V_170 * V_171 )
{
struct V_9 * V_10 ;
T_3 V_46 ;
struct V_18 * V_19 ;
struct V_332 * V_297 = V_171 -> V_95 ;
T_8 V_178 = F_123 ( V_297 -> V_385 ) ;
int V_275 = V_326 ;
T_8 V_386 ;
int V_70 , V_356 ;
V_10 = F_175 ( V_26 , V_171 -> V_188 ) ;
if ( ! V_10 )
return - V_108 ;
if ( ! F_127 ( V_10 ) ) {
int V_72 ;
V_70 = F_196 ( V_10 , V_178 ) ;
F_181 ( V_10 , V_322 , V_297 , V_171 -> V_58 ) ;
F_209 ( & V_26 -> V_260 -> V_249 ) ;
V_72 = F_158 ( V_10 , V_171 -> V_58 ) ;
if ( ! V_70 )
V_70 = V_72 ;
return V_70 ;
}
V_46 = F_176 ( V_297 -> V_46 ) ;
V_19 = F_150 ( V_10 , V_297 -> V_64 , V_46 , V_171 -> V_58 ) ;
if ( ! V_19 ) {
F_131 ( V_10 ) ;
return - V_108 ;
}
V_19 -> V_22 . V_73 = F_185 ;
V_386 = F_123 ( V_297 -> V_386 ) ;
V_275 |= F_198 ( V_10 , V_386 ) ;
if ( V_19 -> V_61 == NULL ) {
F_49 ( V_19 -> V_6 . V_58 == 0 ) ;
F_49 ( V_386 & V_372 ) ;
}
if ( V_386 & V_387 )
V_19 -> V_63 |= V_347 ;
F_11 ( & V_26 -> V_252 ) ;
V_19 -> V_60 = V_26 -> V_260 ;
F_209 ( & V_19 -> V_60 -> V_249 ) ;
F_209 ( & V_19 -> V_60 -> V_255 ) ;
F_12 ( & V_26 -> V_252 ) ;
F_27 () ;
V_356 = F_28 ( V_10 -> V_26 -> V_29 ) -> V_357 ;
F_29 () ;
if ( V_356 ) {
V_19 -> V_63 |= V_349 ;
V_70 = F_196 ( V_10 , V_178 ) ;
if ( V_70 )
goto V_388;
F_21 ( & V_10 -> V_26 -> V_27 ) ;
V_70 = F_201 ( V_10 , V_19 ) ;
if ( V_70 ) {
F_22 ( & V_10 -> V_26 -> V_27 ) ;
if ( V_70 == - V_383 ) {
F_131 ( V_10 ) ;
return 0 ;
}
goto V_388;
}
} else
F_21 ( & V_10 -> V_26 -> V_27 ) ;
F_149 ( & V_19 -> V_22 . V_23 , & V_10 -> V_295 ) ;
F_22 ( & V_10 -> V_26 -> V_27 ) ;
if ( V_10 -> V_344 . V_105 == V_389 )
F_210 ( V_10 -> V_74 , ! F_194 ( V_10 , V_19 ) ) ;
if ( V_10 -> V_26 -> V_180 < 100 ) {
F_27 () ;
switch ( F_28 ( V_10 -> V_26 -> V_29 ) -> V_390 ) {
case V_391 :
V_386 |= V_392 ;
break;
case V_393 :
V_386 |= V_394 ;
break;
}
F_29 () ;
}
if ( V_386 & V_392 ) {
V_19 -> V_63 |= V_343 ;
F_171 ( V_10 ) ;
}
if ( V_386 & V_394 ) {
F_166 ( V_10 , V_395 , V_19 ) ;
}
if ( V_10 -> V_344 . V_396 < V_397 ) {
F_211 ( V_10 , V_19 -> V_6 . V_46 , V_19 -> V_6 . V_58 ) ;
V_19 -> V_63 |= V_398 ;
V_19 -> V_63 &= ~ V_347 ;
F_212 ( V_10 , & V_19 -> V_6 ) ;
}
V_70 = F_138 ( V_10 , V_19 , V_275 , V_399 ) ;
if ( ! V_70 )
return 0 ;
F_43 ( V_38 , L_40 ) ;
F_21 ( & V_10 -> V_26 -> V_27 ) ;
F_135 ( & V_19 -> V_22 . V_23 ) ;
F_144 ( V_10 , V_19 ) ;
F_22 ( & V_10 -> V_26 -> V_27 ) ;
if ( V_19 -> V_63 & V_398 )
F_213 ( V_10 , & V_19 -> V_6 ) ;
V_388:
F_132 ( V_26 , V_19 -> V_60 , V_254 + V_253 ) ;
F_131 ( V_10 ) ;
F_54 ( V_10 , V_19 ) ;
return V_70 ;
}
int F_214 ( struct V_9 * V_10 , T_3 V_46 )
{
struct V_400 * V_401 = V_10 -> V_242 -> V_243 -> V_402 -> V_403 ;
unsigned long V_404 , V_405 , V_406 ;
struct V_407 * V_4 ;
int V_408 ;
int V_409 = 0 ;
unsigned int V_410 ;
F_27 () ;
V_410 = F_28 ( V_10 -> V_242 -> V_267 ) -> V_410 ;
F_29 () ;
if ( V_410 == 0 )
return 0 ;
F_21 ( & V_10 -> V_411 ) ;
V_4 = F_215 ( V_10 -> V_412 , F_216 ( V_46 ) ) ;
if ( V_4 ) {
struct V_413 * V_414 = F_217 ( V_4 , struct V_413 , V_415 ) ;
if ( F_66 ( V_416 , & V_414 -> V_63 ) ) {
F_22 ( & V_10 -> V_411 ) ;
return 0 ;
}
}
F_22 ( & V_10 -> V_411 ) ;
V_408 = ( int ) F_218 ( & V_401 -> V_417 , V_418 [ 0 ] ) +
( int ) F_218 ( & V_401 -> V_417 , V_418 [ 1 ] ) -
F_30 ( & V_10 -> V_325 ) ;
if ( ! V_10 -> V_419 || V_408 - V_10 -> V_419 > 64 ) {
unsigned long V_420 ;
int V_6 ;
V_10 -> V_419 = V_408 ;
V_6 = ( V_10 -> V_421 + V_422 - 1 ) % V_422 ;
if ( V_10 -> V_344 . V_105 == V_423 || V_10 -> V_344 . V_105 == V_424 )
V_420 = V_10 -> V_425 ;
else
V_420 = F_219 ( V_10 ) - V_10 -> V_426 ;
V_405 = ( ( long ) V_186 - ( long ) V_10 -> V_427 [ V_6 ] ) / V_100 ;
if ( ! V_405 )
V_405 ++ ;
V_404 = V_10 -> V_428 [ V_6 ] - V_420 ;
V_406 = F_220 ( V_404 / V_405 ) ;
if ( V_406 > V_410 )
V_409 = 1 ;
}
return V_409 ;
}
static int F_221 ( struct V_94 * V_26 , struct V_170 * V_171 )
{
struct V_9 * V_10 ;
T_3 V_46 ;
T_3 V_299 ;
struct V_18 * V_19 ;
struct V_429 * V_430 = NULL ;
int V_58 , V_431 ;
unsigned int V_276 ;
struct V_432 * V_297 = V_171 -> V_95 ;
V_10 = F_175 ( V_26 , V_171 -> V_188 ) ;
if ( ! V_10 )
return - V_108 ;
V_299 = F_151 ( V_10 -> V_300 ) ;
V_46 = F_176 ( V_297 -> V_46 ) ;
V_58 = F_123 ( V_297 -> V_433 ) ;
if ( V_58 <= 0 || ! F_154 ( V_58 , 512 ) || V_58 > V_42 ) {
F_43 ( V_38 , L_50 , __FILE__ , __LINE__ ,
( unsigned long long ) V_46 , V_58 ) ;
return - V_230 ;
}
if ( V_46 + ( V_58 >> 9 ) > V_299 ) {
F_43 ( V_38 , L_50 , __FILE__ , __LINE__ ,
( unsigned long long ) V_46 , V_58 ) ;
return - V_230 ;
}
if ( ! F_137 ( V_10 , V_434 ) ) {
V_431 = 1 ;
switch ( V_171 -> V_168 ) {
case V_435 :
F_222 ( V_10 , V_436 , V_297 ) ;
break;
case V_437 :
case V_438 :
case V_439 :
F_222 ( V_10 , V_440 , V_297 ) ;
break;
case V_441 :
V_431 = 0 ;
F_170 ( V_10 ) ;
F_223 ( V_10 , V_442 , V_46 , V_58 , V_443 ) ;
break;
default:
F_224 () ;
}
if ( V_431 && F_180 ( & V_335 ) )
F_43 ( V_38 , L_51
L_52 ) ;
return F_158 ( V_10 , V_171 -> V_58 ) ;
}
V_19 = F_40 ( V_10 , V_297 -> V_64 , V_46 , V_58 , V_210 ) ;
if ( ! V_19 ) {
F_131 ( V_10 ) ;
return - V_281 ;
}
switch ( V_171 -> V_168 ) {
case V_435 :
V_19 -> V_22 . V_73 = V_444 ;
V_276 = V_445 ;
goto V_446;
case V_437 :
V_19 -> V_22 . V_73 = V_447 ;
V_276 = V_448 ;
V_10 -> V_449 = F_225 ( V_46 ) ;
break;
case V_441 :
case V_438 :
V_276 = V_448 ;
V_430 = F_148 ( sizeof( * V_430 ) + V_171 -> V_58 , V_210 ) ;
if ( ! V_430 )
goto V_450;
V_430 -> V_451 = V_171 -> V_58 ;
V_430 -> V_66 = ( ( ( char * ) V_430 ) + sizeof( struct V_429 ) ) ;
V_19 -> V_66 = V_430 ;
V_19 -> V_63 |= V_65 ;
if ( F_70 ( V_10 -> V_26 , V_430 -> V_66 , V_171 -> V_58 ) )
goto V_450;
if ( V_171 -> V_168 == V_438 ) {
F_49 ( V_10 -> V_26 -> V_180 >= 89 ) ;
V_19 -> V_22 . V_73 = V_452 ;
V_10 -> V_449 = F_225 ( V_46 ) ;
} else if ( V_171 -> V_168 == V_441 ) {
F_36 ( V_58 >> 9 , & V_10 -> V_336 ) ;
V_19 -> V_22 . V_73 = V_453 ;
F_170 ( V_10 ) ;
goto V_454;
}
break;
case V_439 :
if ( V_10 -> V_455 == ~ ( T_3 ) 0 &&
V_10 -> V_26 -> V_180 >= 90 ) {
unsigned long V_456 = V_186 ;
int V_6 ;
V_10 -> V_455 = V_46 ;
V_10 -> V_457 = V_46 ;
V_10 -> V_425 = F_226 ( V_10 ) - F_225 ( V_46 ) ;
V_10 -> V_458 = V_10 -> V_425 ;
for ( V_6 = 0 ; V_6 < V_422 ; V_6 ++ ) {
V_10 -> V_428 [ V_6 ] = V_10 -> V_425 ;
V_10 -> V_427 [ V_6 ] = V_456 ;
}
F_129 ( V_38 , L_53 ,
( unsigned long long ) V_46 ) ;
}
V_19 -> V_22 . V_73 = V_459 ;
V_276 = V_448 ;
break;
default:
F_224 () ;
}
if ( V_10 -> V_344 . V_460 != V_461 && F_214 ( V_10 , V_46 ) )
F_227 ( V_100 / 10 ) ;
if ( F_228 ( V_10 , V_46 ) )
goto V_450;
V_454:
F_36 ( V_58 >> 9 , & V_10 -> V_325 ) ;
V_446:
F_171 ( V_10 ) ;
F_21 ( & V_10 -> V_26 -> V_27 ) ;
F_205 ( & V_19 -> V_22 . V_23 , & V_10 -> V_462 ) ;
F_22 ( & V_10 -> V_26 -> V_27 ) ;
if ( F_138 ( V_10 , V_19 , V_463 , V_276 ) == 0 )
return 0 ;
F_43 ( V_38 , L_40 ) ;
F_21 ( & V_10 -> V_26 -> V_27 ) ;
F_135 ( & V_19 -> V_22 . V_23 ) ;
F_22 ( & V_10 -> V_26 -> V_27 ) ;
V_450:
F_131 ( V_10 ) ;
F_54 ( V_10 , V_19 ) ;
return - V_108 ;
}
static int F_229 ( struct V_9 * V_10 ) __must_hold( T_5 )
{
int V_464 , V_460 , V_92 = - 100 ;
unsigned long V_465 , V_466 ;
enum V_467 V_468 ;
V_464 = V_10 -> V_242 -> V_469 . V_470 [ V_471 ] & 1 ;
V_460 = V_10 -> V_472 [ V_471 ] & 1 ;
V_466 = V_10 -> V_472 [ V_473 ] ;
V_465 = V_10 -> V_474 ;
F_27 () ;
V_468 = F_28 ( V_10 -> V_26 -> V_29 ) -> V_468 ;
F_29 () ;
switch ( V_468 ) {
case V_475 :
case V_476 :
case V_477 :
case V_478 :
F_43 ( V_38 , L_54 ) ;
break;
case V_479 :
break;
case V_480 :
if ( V_464 == 0 && V_460 == 1 ) {
V_92 = - 1 ;
break;
}
if ( V_464 == 1 && V_460 == 0 ) {
V_92 = 1 ;
break;
}
case V_481 :
if ( V_464 == 0 && V_460 == 1 ) {
V_92 = 1 ;
break;
}
if ( V_464 == 1 && V_460 == 0 ) {
V_92 = - 1 ;
break;
}
F_33 ( V_38 , L_55
L_56 ) ;
case V_482 :
if ( V_466 == 0 && V_465 == 0 ) {
V_92 = F_66 ( V_202 , & V_10 -> V_26 -> V_63 )
? - 1 : 1 ;
break;
} else {
if ( V_466 == 0 ) { V_92 = 1 ; break; }
if ( V_465 == 0 ) { V_92 = - 1 ; break; }
}
if ( V_468 == V_482 )
break;
case V_483 :
if ( V_465 < V_466 )
V_92 = - 1 ;
else if ( V_465 > V_466 )
V_92 = 1 ;
else
V_92 = F_66 ( V_202 , & V_10 -> V_26 -> V_63 )
? - 1 : 1 ;
break;
case V_484 :
V_92 = - 1 ;
break;
case V_485 :
V_92 = 1 ;
}
return V_92 ;
}
static int F_230 ( struct V_9 * V_10 ) __must_hold( T_5 )
{
int V_486 , V_92 = - 100 ;
enum V_467 V_487 ;
F_27 () ;
V_487 = F_28 ( V_10 -> V_26 -> V_29 ) -> V_487 ;
F_29 () ;
switch ( V_487 ) {
case V_480 :
case V_481 :
case V_483 :
case V_484 :
case V_485 :
case V_482 :
F_43 ( V_38 , L_54 ) ;
break;
case V_479 :
break;
case V_475 :
V_486 = F_229 ( V_10 ) ;
if ( V_486 == - 1 && V_10 -> V_344 . V_488 == V_489 )
V_92 = V_486 ;
if ( V_486 == 1 && V_10 -> V_344 . V_488 == V_461 )
V_92 = V_486 ;
break;
case V_478 :
V_92 = F_229 ( V_10 ) ;
break;
case V_476 :
return V_10 -> V_344 . V_488 == V_461 ? 1 : - 1 ;
case V_477 :
V_486 = F_229 ( V_10 ) ;
if ( V_486 == - 1 && V_10 -> V_344 . V_488 == V_461 ) {
enum V_193 V_490 ;
F_231 ( V_10 , V_489 , 0 ) ;
V_490 = F_232 ( V_10 , V_195 , F_69 ( V_488 , V_489 ) ) ;
if ( V_490 != V_196 ) {
F_233 ( V_10 , L_57 ) ;
} else {
F_33 ( V_38 , L_58 ) ;
V_92 = V_486 ;
}
} else
V_92 = V_486 ;
}
return V_92 ;
}
static int F_234 ( struct V_9 * V_10 ) __must_hold( T_5 )
{
int V_486 , V_92 = - 100 ;
enum V_467 V_491 ;
F_27 () ;
V_491 = F_28 ( V_10 -> V_26 -> V_29 ) -> V_491 ;
F_29 () ;
switch ( V_491 ) {
case V_480 :
case V_481 :
case V_483 :
case V_484 :
case V_485 :
case V_475 :
case V_476 :
case V_482 :
F_43 ( V_38 , L_54 ) ;
break;
case V_478 :
V_92 = F_229 ( V_10 ) ;
break;
case V_479 :
break;
case V_477 :
V_486 = F_229 ( V_10 ) ;
if ( V_486 == - 1 ) {
enum V_193 V_490 ;
V_490 = F_232 ( V_10 , V_195 , F_69 ( V_488 , V_489 ) ) ;
if ( V_490 != V_196 ) {
F_233 ( V_10 , L_57 ) ;
} else {
F_33 ( V_38 , L_58 ) ;
V_92 = V_486 ;
}
} else
V_92 = V_486 ;
}
return V_92 ;
}
static void F_235 ( struct V_9 * V_10 , char * V_492 , T_2 * V_470 ,
T_2 V_493 , T_2 V_63 )
{
if ( ! V_470 ) {
F_129 ( V_38 , L_59 , V_492 ) ;
return;
}
F_129 ( V_38 , L_60 ,
V_492 ,
( unsigned long long ) V_470 [ V_494 ] ,
( unsigned long long ) V_470 [ V_471 ] ,
( unsigned long long ) V_470 [ V_495 ] ,
( unsigned long long ) V_470 [ V_496 ] ,
( unsigned long long ) V_493 ,
( unsigned long long ) V_63 ) ;
}
static int F_236 ( struct V_9 * V_10 , int * V_497 ) __must_hold( T_5 )
{
T_2 V_464 , V_460 ;
int V_6 , V_498 ;
V_464 = V_10 -> V_242 -> V_469 . V_470 [ V_494 ] & ~ ( ( T_2 ) 1 ) ;
V_460 = V_10 -> V_472 [ V_494 ] & ~ ( ( T_2 ) 1 ) ;
* V_497 = 10 ;
if ( V_464 == V_499 && V_460 == V_499 )
return 0 ;
* V_497 = 20 ;
if ( ( V_464 == V_499 || V_464 == ( T_2 ) 0 ) &&
V_460 != V_499 )
return - 2 ;
* V_497 = 30 ;
if ( V_464 != V_499 &&
( V_460 == V_499 || V_460 == ( T_2 ) 0 ) )
return 2 ;
if ( V_464 == V_460 ) {
int V_500 , V_268 ;
if ( V_10 -> V_472 [ V_471 ] == ( T_2 ) 0 && V_10 -> V_242 -> V_469 . V_470 [ V_471 ] != ( T_2 ) 0 ) {
if ( V_10 -> V_26 -> V_180 < 91 )
return - 1091 ;
if ( ( V_10 -> V_242 -> V_469 . V_470 [ V_471 ] & ~ ( ( T_2 ) 1 ) ) == ( V_10 -> V_472 [ V_495 ] & ~ ( ( T_2 ) 1 ) ) &&
( V_10 -> V_242 -> V_469 . V_470 [ V_495 ] & ~ ( ( T_2 ) 1 ) ) == ( V_10 -> V_472 [ V_495 + 1 ] & ~ ( ( T_2 ) 1 ) ) ) {
F_129 ( V_38 , L_61 ) ;
F_237 ( V_10 ) ;
V_10 -> V_242 -> V_469 . V_470 [ V_495 ] = V_10 -> V_242 -> V_469 . V_470 [ V_471 ] ;
V_10 -> V_242 -> V_469 . V_470 [ V_471 ] = 0 ;
F_235 ( V_10 , L_62 , V_10 -> V_242 -> V_469 . V_470 ,
V_10 -> V_344 . V_401 >= V_501 ? F_219 ( V_10 ) : 0 , 0 ) ;
* V_497 = 34 ;
} else {
F_129 ( V_38 , L_63 ) ;
* V_497 = 36 ;
}
return 1 ;
}
if ( V_10 -> V_242 -> V_469 . V_470 [ V_471 ] == ( T_2 ) 0 && V_10 -> V_472 [ V_471 ] != ( T_2 ) 0 ) {
if ( V_10 -> V_26 -> V_180 < 91 )
return - 1091 ;
if ( ( V_10 -> V_242 -> V_469 . V_470 [ V_495 ] & ~ ( ( T_2 ) 1 ) ) == ( V_10 -> V_472 [ V_471 ] & ~ ( ( T_2 ) 1 ) ) &&
( V_10 -> V_242 -> V_469 . V_470 [ V_495 + 1 ] & ~ ( ( T_2 ) 1 ) ) == ( V_10 -> V_472 [ V_495 ] & ~ ( ( T_2 ) 1 ) ) ) {
F_129 ( V_38 , L_64 ) ;
V_10 -> V_472 [ V_495 + 1 ] = V_10 -> V_472 [ V_495 ] ;
V_10 -> V_472 [ V_495 ] = V_10 -> V_472 [ V_471 ] ;
V_10 -> V_472 [ V_471 ] = 0UL ;
F_235 ( V_10 , L_65 , V_10 -> V_472 , V_10 -> V_472 [ V_473 ] , V_10 -> V_472 [ V_502 ] ) ;
* V_497 = 35 ;
} else {
F_129 ( V_38 , L_66 ) ;
* V_497 = 37 ;
}
return - 1 ;
}
V_500 = ( F_66 ( V_503 , & V_10 -> V_63 ) ? 1 : 0 ) +
( V_10 -> V_472 [ V_502 ] & 2 ) ;
* V_497 = 40 ;
switch ( V_500 ) {
case 0 : return 0 ;
case 1 : return 1 ;
case 2 : return - 1 ;
case 3 :
V_268 = F_66 ( V_202 , & V_10 -> V_26 -> V_63 ) ;
return V_268 ? - 1 : 1 ;
}
}
* V_497 = 50 ;
V_460 = V_10 -> V_472 [ V_471 ] & ~ ( ( T_2 ) 1 ) ;
if ( V_464 == V_460 )
return - 1 ;
* V_497 = 51 ;
V_460 = V_10 -> V_472 [ V_495 ] & ~ ( ( T_2 ) 1 ) ;
if ( V_464 == V_460 ) {
if ( V_10 -> V_26 -> V_180 < 96 ?
( V_10 -> V_242 -> V_469 . V_470 [ V_495 ] & ~ ( ( T_2 ) 1 ) ) ==
( V_10 -> V_472 [ V_495 + 1 ] & ~ ( ( T_2 ) 1 ) ) :
V_460 + V_504 == ( V_10 -> V_472 [ V_471 ] & ~ ( ( T_2 ) 1 ) ) ) {
if ( V_10 -> V_26 -> V_180 < 91 )
return - 1091 ;
V_10 -> V_472 [ V_471 ] = V_10 -> V_472 [ V_495 ] ;
V_10 -> V_472 [ V_495 ] = V_10 -> V_472 [ V_495 + 1 ] ;
F_129 ( V_38 , L_67 ) ;
F_235 ( V_10 , L_65 , V_10 -> V_472 , V_10 -> V_472 [ V_473 ] , V_10 -> V_472 [ V_502 ] ) ;
return - 1 ;
}
}
* V_497 = 60 ;
V_464 = V_10 -> V_242 -> V_469 . V_470 [ V_494 ] & ~ ( ( T_2 ) 1 ) ;
for ( V_6 = V_495 ; V_6 <= V_496 ; V_6 ++ ) {
V_460 = V_10 -> V_472 [ V_6 ] & ~ ( ( T_2 ) 1 ) ;
if ( V_464 == V_460 )
return - 2 ;
}
* V_497 = 70 ;
V_464 = V_10 -> V_242 -> V_469 . V_470 [ V_471 ] & ~ ( ( T_2 ) 1 ) ;
V_460 = V_10 -> V_472 [ V_494 ] & ~ ( ( T_2 ) 1 ) ;
if ( V_464 == V_460 )
return 1 ;
* V_497 = 71 ;
V_464 = V_10 -> V_242 -> V_469 . V_470 [ V_495 ] & ~ ( ( T_2 ) 1 ) ;
if ( V_464 == V_460 ) {
if ( V_10 -> V_26 -> V_180 < 96 ?
( V_10 -> V_242 -> V_469 . V_470 [ V_495 + 1 ] & ~ ( ( T_2 ) 1 ) ) ==
( V_10 -> V_472 [ V_495 ] & ~ ( ( T_2 ) 1 ) ) :
V_464 + V_504 == ( V_10 -> V_242 -> V_469 . V_470 [ V_471 ] & ~ ( ( T_2 ) 1 ) ) ) {
if ( V_10 -> V_26 -> V_180 < 91 )
return - 1091 ;
F_238 ( V_10 , V_471 , V_10 -> V_242 -> V_469 . V_470 [ V_495 ] ) ;
F_238 ( V_10 , V_495 , V_10 -> V_242 -> V_469 . V_470 [ V_495 + 1 ] ) ;
F_129 ( V_38 , L_68 ) ;
F_235 ( V_10 , L_62 , V_10 -> V_242 -> V_469 . V_470 ,
V_10 -> V_344 . V_401 >= V_501 ? F_219 ( V_10 ) : 0 , 0 ) ;
return 1 ;
}
}
* V_497 = 80 ;
V_460 = V_10 -> V_472 [ V_494 ] & ~ ( ( T_2 ) 1 ) ;
for ( V_6 = V_495 ; V_6 <= V_496 ; V_6 ++ ) {
V_464 = V_10 -> V_242 -> V_469 . V_470 [ V_6 ] & ~ ( ( T_2 ) 1 ) ;
if ( V_464 == V_460 )
return 2 ;
}
* V_497 = 90 ;
V_464 = V_10 -> V_242 -> V_469 . V_470 [ V_471 ] & ~ ( ( T_2 ) 1 ) ;
V_460 = V_10 -> V_472 [ V_471 ] & ~ ( ( T_2 ) 1 ) ;
if ( V_464 == V_460 && V_464 != ( ( T_2 ) 0 ) )
return 100 ;
* V_497 = 100 ;
for ( V_6 = V_495 ; V_6 <= V_496 ; V_6 ++ ) {
V_464 = V_10 -> V_242 -> V_469 . V_470 [ V_6 ] & ~ ( ( T_2 ) 1 ) ;
for ( V_498 = V_495 ; V_498 <= V_496 ; V_498 ++ ) {
V_460 = V_10 -> V_472 [ V_498 ] & ~ ( ( T_2 ) 1 ) ;
if ( V_464 == V_460 )
return - 100 ;
}
}
return - 1000 ;
}
static enum V_505 F_239 ( struct V_9 * V_10 , enum V_506 V_507 ,
enum V_508 V_509 ) __must_hold( T_5 )
{
enum V_505 V_92 = V_510 ;
enum V_508 V_511 ;
struct V_29 * V_30 ;
int V_486 , V_497 , V_512 , V_513 ;
V_511 = V_10 -> V_344 . V_401 ;
if ( V_511 == V_501 )
V_511 = V_10 -> V_514 . V_401 ;
F_129 ( V_38 , L_69 ) ;
F_21 ( & V_10 -> V_242 -> V_469 . V_515 ) ;
F_235 ( V_10 , L_62 , V_10 -> V_242 -> V_469 . V_470 , V_10 -> V_474 , 0 ) ;
F_235 ( V_10 , L_65 , V_10 -> V_472 ,
V_10 -> V_472 [ V_473 ] , V_10 -> V_472 [ V_502 ] ) ;
V_486 = F_236 ( V_10 , & V_497 ) ;
F_22 ( & V_10 -> V_242 -> V_469 . V_515 ) ;
F_129 ( V_38 , L_70 , V_486 , V_497 ) ;
if ( V_486 == - 1000 ) {
F_204 ( V_38 , L_71 ) ;
return V_510 ;
}
if ( V_486 < - 1000 ) {
F_204 ( V_38 , L_72 , - V_486 - 1000 ) ;
return V_510 ;
}
if ( ( V_511 == V_397 && V_509 > V_397 ) ||
( V_509 == V_397 && V_511 > V_397 ) ) {
int V_516 = ( V_486 == - 100 ) || abs ( V_486 ) == 2 ;
V_486 = V_511 > V_397 ? 1 : - 1 ;
if ( V_516 )
V_486 = V_486 * 2 ;
F_129 ( V_38 , L_73 ,
V_486 > 0 ? L_74 : L_75 ) ;
}
if ( abs ( V_486 ) == 100 )
F_233 ( V_10 , L_76 ) ;
F_27 () ;
V_30 = F_28 ( V_10 -> V_26 -> V_29 ) ;
if ( V_486 == 100 || ( V_486 == - 100 && V_30 -> V_517 ) ) {
int V_518 = ( V_10 -> V_344 . V_488 == V_461 )
+ ( V_507 == V_461 ) ;
int V_519 = ( V_486 == - 100 ) ;
switch ( V_518 ) {
case 0 :
V_486 = F_229 ( V_10 ) ;
break;
case 1 :
V_486 = F_230 ( V_10 ) ;
break;
case 2 :
V_486 = F_234 ( V_10 ) ;
break;
}
if ( abs ( V_486 ) < 100 ) {
F_33 ( V_38 , L_77
L_78 ,
V_518 , ( V_486 < 0 ) ? L_65 : L_79 ) ;
if ( V_519 ) {
F_33 ( V_38 , L_80
L_81 ) ;
V_486 = V_486 * 2 ;
}
}
}
if ( V_486 == - 100 ) {
if ( F_66 ( V_221 , & V_10 -> V_63 ) && ! ( V_10 -> V_472 [ V_502 ] & 1 ) )
V_486 = - 1 ;
if ( ! F_66 ( V_221 , & V_10 -> V_63 ) && ( V_10 -> V_472 [ V_502 ] & 1 ) )
V_486 = 1 ;
if ( abs ( V_486 ) < 100 )
F_33 ( V_38 , L_82
L_83 ,
( V_486 < 0 ) ? L_65 : L_79 ) ;
}
V_512 = V_30 -> V_512 ;
V_513 = V_30 -> V_513 ;
F_29 () ;
if ( V_486 == - 100 ) {
F_204 ( V_38 , L_84 ) ;
F_233 ( V_10 , L_85 ) ;
return V_510 ;
}
if ( V_486 > 0 && V_511 <= V_397 ) {
F_43 ( V_38 , L_86 ) ;
return V_510 ;
}
if ( V_486 < 0 &&
V_10 -> V_344 . V_488 == V_461 && V_10 -> V_344 . V_401 >= V_520 ) {
switch ( V_512 ) {
case V_477 :
F_233 ( V_10 , L_87 ) ;
case V_479 :
F_43 ( V_38 , L_88 ) ;
return V_510 ;
case V_478 :
F_33 ( V_38 , L_89
L_90 ) ;
}
}
if ( V_513 || F_66 ( V_521 , & V_10 -> V_26 -> V_63 ) ) {
if ( V_486 == 0 )
F_129 ( V_38 , L_91 ) ;
else
F_129 ( V_38 , L_92 ,
F_240 ( V_486 > 0 ? V_345 : V_389 ) ,
abs ( V_486 ) >= 2 ? L_93 : L_94 ) ;
return V_510 ;
}
if ( abs ( V_486 ) >= 2 ) {
F_129 ( V_38 , L_95 ) ;
if ( F_241 ( V_10 , & V_522 , L_96 ,
V_523 ) )
return V_510 ;
}
if ( V_486 > 0 ) {
V_92 = V_524 ;
} else if ( V_486 < 0 ) {
V_92 = V_525 ;
} else {
V_92 = V_526 ;
if ( F_219 ( V_10 ) ) {
F_129 ( V_38 , L_97 ,
F_219 ( V_10 ) ) ;
}
}
return V_92 ;
}
static enum V_467 F_242 ( enum V_467 V_460 )
{
if ( V_460 == V_485 )
return V_484 ;
if ( V_460 == V_484 )
return V_485 ;
return V_460 ;
}
static int F_243 ( struct V_94 * V_26 , struct V_170 * V_171 )
{
struct V_527 * V_297 = V_171 -> V_95 ;
enum V_467 V_528 , V_529 , V_530 ;
int V_531 , V_532 , V_533 , V_534 ;
struct V_29 * V_30 , * V_535 , * V_536 = NULL ;
char V_537 [ V_538 ] = L_98 ;
struct V_539 * V_306 = NULL ;
void * V_303 = NULL , * V_305 = NULL ;
V_531 = F_123 ( V_297 -> V_540 ) ;
V_528 = F_123 ( V_297 -> V_468 ) ;
V_529 = F_123 ( V_297 -> V_487 ) ;
V_530 = F_123 ( V_297 -> V_491 ) ;
V_533 = F_123 ( V_297 -> V_357 ) ;
V_534 = F_123 ( V_297 -> V_541 ) ;
V_532 = V_534 & V_542 ;
if ( V_26 -> V_180 >= 87 ) {
int V_70 ;
if ( V_171 -> V_58 > sizeof( V_537 ) )
return - V_108 ;
V_70 = F_70 ( V_26 , V_537 , V_171 -> V_58 ) ;
if ( V_70 )
return V_70 ;
V_537 [ V_538 - 1 ] = 0 ;
}
if ( V_171 -> V_168 != V_543 ) {
F_101 ( V_521 , & V_26 -> V_63 ) ;
if ( V_534 & V_544 )
F_107 ( V_521 , & V_26 -> V_63 ) ;
F_27 () ;
V_30 = F_28 ( V_26 -> V_29 ) ;
if ( V_531 != V_30 -> V_390 ) {
F_65 ( V_26 , L_99 , L_100 ) ;
goto V_545;
}
if ( F_242 ( V_528 ) != V_30 -> V_468 ) {
F_65 ( V_26 , L_99 , L_101 ) ;
goto V_545;
}
if ( F_242 ( V_529 ) != V_30 -> V_487 ) {
F_65 ( V_26 , L_99 , L_102 ) ;
goto V_545;
}
if ( F_242 ( V_530 ) != V_30 -> V_491 ) {
F_65 ( V_26 , L_99 , L_103 ) ;
goto V_545;
}
if ( V_532 && V_30 -> V_192 ) {
F_65 ( V_26 , L_99 , L_104 ) ;
goto V_545;
}
if ( V_533 != V_30 -> V_357 ) {
F_65 ( V_26 , L_99 , L_105 ) ;
goto V_545;
}
if ( strcmp ( V_537 , V_30 -> V_537 ) ) {
F_65 ( V_26 , L_99 , L_106 ) ;
goto V_545;
}
F_29 () ;
}
if ( V_537 [ 0 ] ) {
int V_546 ;
V_306 = F_244 ( V_537 , 0 , V_547 ) ;
if ( ! V_306 ) {
F_65 ( V_26 , L_107 ,
V_537 ) ;
goto V_548;
}
V_546 = F_152 ( V_306 ) ;
V_303 = F_148 ( V_546 , V_549 ) ;
V_305 = F_148 ( V_546 , V_549 ) ;
if ( ! ( V_303 && V_305 ) ) {
F_65 ( V_26 , L_108 ) ;
goto V_548;
}
}
V_536 = F_148 ( sizeof( struct V_29 ) , V_549 ) ;
if ( ! V_536 ) {
F_65 ( V_26 , L_109 ) ;
goto V_548;
}
F_117 ( & V_26 -> V_95 . V_197 ) ;
F_117 ( & V_26 -> V_224 ) ;
V_535 = V_26 -> V_29 ;
* V_536 = * V_535 ;
V_536 -> V_390 = V_531 ;
V_536 -> V_468 = F_242 ( V_528 ) ;
V_536 -> V_487 = F_242 ( V_529 ) ;
V_536 -> V_491 = F_242 ( V_530 ) ;
V_536 -> V_357 = V_533 ;
F_245 ( V_26 -> V_29 , V_536 ) ;
F_118 ( & V_26 -> V_224 ) ;
F_118 ( & V_26 -> V_95 . V_197 ) ;
F_246 ( V_26 -> V_306 ) ;
F_48 ( V_26 -> V_303 ) ;
F_48 ( V_26 -> V_305 ) ;
V_26 -> V_306 = V_306 ;
V_26 -> V_303 = V_303 ;
V_26 -> V_305 = V_305 ;
if ( strcmp ( V_535 -> V_537 , V_537 ) )
F_64 ( V_26 , L_110 ,
V_537 [ 0 ] ? V_537 : L_111 ) ;
F_247 () ;
F_48 ( V_535 ) ;
return 0 ;
V_545:
F_29 () ;
V_548:
F_246 ( V_306 ) ;
F_48 ( V_303 ) ;
F_48 ( V_305 ) ;
F_68 ( V_26 , F_69 ( V_105 , V_150 ) , V_107 ) ;
return - V_108 ;
}
struct V_539 * F_248 ( const struct V_9 * V_10 ,
const char * V_550 , const char * V_551 )
{
struct V_539 * V_552 ;
if ( ! V_550 [ 0 ] )
return NULL ;
V_552 = F_244 ( V_550 , 0 , V_547 ) ;
if ( F_249 ( V_552 ) ) {
F_43 ( V_38 , L_112 ,
V_550 , V_551 , F_250 ( V_552 ) ) ;
return V_552 ;
}
return V_552 ;
}
static int F_251 ( struct V_94 * V_26 , struct V_170 * V_171 )
{
void * V_239 = V_26 -> V_95 . V_172 ;
int V_58 = V_171 -> V_58 ;
while ( V_58 ) {
int V_200 = F_75 ( int , V_58 , V_553 ) ;
V_200 = F_63 ( V_26 , V_239 , V_200 ) ;
if ( V_200 <= 0 ) {
if ( V_200 < 0 )
return V_200 ;
break;
}
V_58 -= V_200 ;
}
if ( V_58 )
return - V_108 ;
return 0 ;
}
static int F_252 ( struct V_94 * V_26 , struct V_170 * V_171 )
{
F_72 ( V_26 , L_113 ,
F_253 ( V_171 -> V_168 ) , V_171 -> V_188 ) ;
return F_251 ( V_26 , V_171 ) ;
}
static int F_254 ( struct V_94 * V_26 , struct V_170 * V_171 )
{
struct V_9 * V_10 ;
struct V_554 * V_297 ;
unsigned int V_169 , V_47 , V_555 ;
struct V_539 * V_556 = NULL ;
struct V_539 * V_557 = NULL ;
struct V_29 * V_535 , * V_536 = NULL ;
struct V_267 * V_558 = NULL , * V_559 = NULL ;
const int V_560 = V_26 -> V_180 ;
struct V_561 * V_562 = NULL , * V_563 = NULL ;
int V_564 = 0 ;
int V_70 ;
V_10 = F_175 ( V_26 , V_171 -> V_188 ) ;
if ( ! V_10 )
return F_252 ( V_26 , V_171 ) ;
V_555 = V_560 <= 87 ? sizeof( struct V_565 )
: V_560 == 88 ? sizeof( struct V_565 )
+ V_538
: V_560 <= 94 ? sizeof( struct V_566 )
: sizeof( struct V_554 ) ;
if ( V_171 -> V_58 > V_555 ) {
F_43 ( V_38 , L_114 ,
V_171 -> V_58 , V_555 ) ;
return - V_108 ;
}
if ( V_560 <= 88 ) {
V_169 = sizeof( struct V_565 ) ;
V_47 = V_171 -> V_58 - V_169 ;
} else if ( V_560 <= 94 ) {
V_169 = sizeof( struct V_566 ) ;
V_47 = V_171 -> V_58 - V_169 ;
F_49 ( V_47 == 0 ) ;
} else {
V_169 = sizeof( struct V_554 ) ;
V_47 = V_171 -> V_58 - V_169 ;
F_49 ( V_47 == 0 ) ;
}
V_297 = V_171 -> V_95 ;
memset ( V_297 -> V_567 , 0 , 2 * V_538 ) ;
V_70 = F_70 ( V_10 -> V_26 , V_297 , V_169 ) ;
if ( V_70 )
return V_70 ;
F_117 ( & V_10 -> V_26 -> V_224 ) ;
V_535 = V_10 -> V_26 -> V_29 ;
if ( F_127 ( V_10 ) ) {
V_559 = F_255 ( sizeof( struct V_267 ) , V_549 ) ;
if ( ! V_559 ) {
F_131 ( V_10 ) ;
F_118 ( & V_10 -> V_26 -> V_224 ) ;
F_43 ( V_38 , L_115 ) ;
return - V_281 ;
}
V_558 = V_10 -> V_242 -> V_267 ;
* V_559 = * V_558 ;
V_559 -> V_568 = F_123 ( V_297 -> V_568 ) ;
}
if ( V_560 >= 88 ) {
if ( V_560 == 88 ) {
if ( V_47 > V_538 || V_47 == 0 ) {
F_43 ( V_38 , L_116
L_117 ,
V_47 , V_538 ) ;
V_70 = - V_108 ;
goto V_569;
}
V_70 = F_70 ( V_10 -> V_26 , V_297 -> V_567 , V_47 ) ;
if ( V_70 )
goto V_569;
F_49 ( V_297 -> V_567 [ V_47 - 1 ] == 0 ) ;
V_297 -> V_567 [ V_47 - 1 ] = 0 ;
} else {
F_49 ( V_297 -> V_567 [ V_538 - 1 ] == 0 ) ;
F_49 ( V_297 -> V_570 [ V_538 - 1 ] == 0 ) ;
V_297 -> V_567 [ V_538 - 1 ] = 0 ;
V_297 -> V_570 [ V_538 - 1 ] = 0 ;
}
if ( strcmp ( V_535 -> V_567 , V_297 -> V_567 ) ) {
if ( V_10 -> V_344 . V_105 == V_103 ) {
F_43 ( V_38 , L_118 ,
V_535 -> V_567 , V_297 -> V_567 ) ;
goto V_548;
}
V_556 = F_248 ( V_10 ,
V_297 -> V_567 , L_119 ) ;
if ( F_249 ( V_556 ) ) {
V_556 = NULL ;
goto V_548;
}
}
if ( V_560 >= 89 && strcmp ( V_535 -> V_570 , V_297 -> V_570 ) ) {
if ( V_10 -> V_344 . V_105 == V_103 ) {
F_43 ( V_38 , L_120 ,
V_535 -> V_570 , V_297 -> V_570 ) ;
goto V_548;
}
V_557 = F_248 ( V_10 ,
V_297 -> V_570 , L_121 ) ;
if ( F_249 ( V_557 ) ) {
V_557 = NULL ;
goto V_548;
}
}
if ( V_560 > 94 && V_559 ) {
V_559 -> V_571 = F_123 ( V_297 -> V_571 ) ;
V_559 -> V_572 = F_123 ( V_297 -> V_572 ) ;
V_559 -> V_573 = F_123 ( V_297 -> V_573 ) ;
V_559 -> V_574 = F_123 ( V_297 -> V_574 ) ;
V_564 = ( V_559 -> V_571 * 10 * V_575 ) / V_100 ;
if ( V_564 != V_10 -> V_576 -> V_58 ) {
V_563 = F_256 ( V_564 ) ;
if ( ! V_563 ) {
F_43 ( V_38 , L_122 ) ;
F_131 ( V_10 ) ;
goto V_548;
}
}
}
if ( V_556 || V_557 ) {
V_536 = F_255 ( sizeof( struct V_29 ) , V_549 ) ;
if ( ! V_536 ) {
F_43 ( V_38 , L_109 ) ;
goto V_548;
}
* V_536 = * V_535 ;
if ( V_556 ) {
strcpy ( V_536 -> V_567 , V_297 -> V_567 ) ;
V_536 -> V_577 = strlen ( V_297 -> V_567 ) + 1 ;
F_246 ( V_10 -> V_26 -> V_556 ) ;
V_10 -> V_26 -> V_556 = V_556 ;
F_129 ( V_38 , L_123 , V_297 -> V_567 ) ;
}
if ( V_557 ) {
strcpy ( V_536 -> V_570 , V_297 -> V_570 ) ;
V_536 -> V_578 = strlen ( V_297 -> V_570 ) + 1 ;
F_246 ( V_10 -> V_26 -> V_557 ) ;
V_10 -> V_26 -> V_557 = V_557 ;
F_129 ( V_38 , L_124 , V_297 -> V_570 ) ;
}
F_245 ( V_26 -> V_29 , V_536 ) ;
}
}
if ( V_559 ) {
F_245 ( V_10 -> V_242 -> V_267 , V_559 ) ;
F_131 ( V_10 ) ;
}
if ( V_563 ) {
V_562 = V_10 -> V_576 ;
F_245 ( V_10 -> V_576 , V_563 ) ;
}
F_118 ( & V_10 -> V_26 -> V_224 ) ;
F_247 () ;
if ( V_536 )
F_48 ( V_535 ) ;
F_48 ( V_558 ) ;
F_48 ( V_562 ) ;
return 0 ;
V_569:
if ( V_559 ) {
F_131 ( V_10 ) ;
F_48 ( V_559 ) ;
}
F_118 ( & V_10 -> V_26 -> V_224 ) ;
return - V_108 ;
V_548:
F_48 ( V_563 ) ;
if ( V_559 ) {
F_131 ( V_10 ) ;
F_48 ( V_559 ) ;
}
F_118 ( & V_10 -> V_26 -> V_224 ) ;
F_246 ( V_557 ) ;
F_246 ( V_556 ) ;
F_68 ( V_10 -> V_26 , F_69 ( V_105 , V_150 ) , V_107 ) ;
return - V_108 ;
}
static void F_257 ( struct V_9 * V_10 ,
const char * V_200 , T_3 V_40 , T_3 V_354 )
{
T_3 V_579 ;
if ( V_40 == 0 || V_354 == 0 )
return;
V_579 = ( V_40 > V_354 ) ? ( V_40 - V_354 ) : ( V_354 - V_40 ) ;
if ( V_579 > ( V_40 >> 3 ) || V_579 > ( V_354 >> 3 ) )
F_33 ( V_38 , L_125 , V_200 ,
( unsigned long long ) V_40 , ( unsigned long long ) V_354 ) ;
}
static int F_258 ( struct V_94 * V_26 , struct V_170 * V_171 )
{
struct V_9 * V_10 ;
struct V_580 * V_297 = V_171 -> V_95 ;
enum V_581 V_582 = V_583 ;
T_3 V_584 , V_585 , V_586 ;
int V_587 = 0 ;
enum V_588 V_589 ;
V_10 = F_175 ( V_26 , V_171 -> V_188 ) ;
if ( ! V_10 )
return F_252 ( V_26 , V_171 ) ;
V_584 = F_176 ( V_297 -> V_590 ) ;
V_585 = F_176 ( V_297 -> V_591 ) ;
V_10 -> V_584 = V_584 ;
if ( F_127 ( V_10 ) ) {
F_27 () ;
V_586 = F_28 ( V_10 -> V_242 -> V_267 ) -> V_592 ;
F_29 () ;
F_257 ( V_10 , L_126 ,
V_584 , F_259 ( V_10 -> V_242 ) ) ;
F_257 ( V_10 , L_127 ,
V_585 , V_586 ) ;
if ( V_10 -> V_344 . V_105 == V_103 )
V_585 = F_260 ( V_586 , V_585 ) ;
if ( F_261 ( V_10 , V_10 -> V_242 , V_585 , 0 ) <
F_151 ( V_10 -> V_300 ) &&
V_10 -> V_344 . V_401 >= V_593 &&
V_10 -> V_344 . V_105 < V_526 ) {
F_43 ( V_38 , L_128 ) ;
F_68 ( V_10 -> V_26 , F_69 ( V_105 , V_150 ) , V_107 ) ;
F_131 ( V_10 ) ;
return - V_108 ;
}
if ( V_586 != V_585 ) {
struct V_267 * V_558 , * V_559 = NULL ;
V_559 = F_255 ( sizeof( struct V_267 ) , V_549 ) ;
if ( ! V_559 ) {
F_43 ( V_38 , L_115 ) ;
F_131 ( V_10 ) ;
return - V_281 ;
}
F_117 ( & V_10 -> V_26 -> V_224 ) ;
V_558 = V_10 -> V_242 -> V_267 ;
* V_559 = * V_558 ;
V_559 -> V_592 = V_585 ;
F_245 ( V_10 -> V_242 -> V_267 , V_559 ) ;
F_118 ( & V_10 -> V_26 -> V_224 ) ;
F_247 () ;
F_48 ( V_558 ) ;
F_129 ( V_38 , L_129 ,
( unsigned long ) V_586 ) ;
}
F_131 ( V_10 ) ;
}
V_589 = F_122 ( V_297 -> V_588 ) ;
if ( F_127 ( V_10 ) ) {
V_582 = F_262 ( V_10 , V_589 ) ;
F_131 ( V_10 ) ;
if ( V_582 == V_594 )
return - V_108 ;
F_263 ( V_10 ) ;
} else {
F_264 ( V_10 , V_584 ) ;
}
V_10 -> V_595 = F_123 ( V_297 -> V_596 ) ;
F_265 ( V_10 ) ;
if ( F_127 ( V_10 ) ) {
if ( V_10 -> V_242 -> V_597 != F_151 ( V_10 -> V_242 -> V_243 ) ) {
V_10 -> V_242 -> V_597 = F_151 ( V_10 -> V_242 -> V_243 ) ;
V_587 = 1 ;
}
F_131 ( V_10 ) ;
}
if ( V_10 -> V_344 . V_105 > V_103 ) {
if ( F_176 ( V_297 -> V_598 ) !=
F_151 ( V_10 -> V_300 ) || V_587 ) {
F_98 ( V_10 , 0 , V_589 ) ;
}
if ( F_266 ( V_184 , & V_10 -> V_63 ) ||
( V_582 == V_599 && V_10 -> V_344 . V_105 == V_526 ) ) {
if ( V_10 -> V_344 . V_396 >= V_397 &&
V_10 -> V_344 . V_401 >= V_397 ) {
if ( V_589 & V_600 )
F_129 ( V_38 , L_130 ) ;
else
F_267 ( V_10 ) ;
} else
F_107 ( V_601 , & V_10 -> V_63 ) ;
}
}
return 0 ;
}
static int F_268 ( struct V_94 * V_26 , struct V_170 * V_171 )
{
struct V_9 * V_10 ;
struct V_602 * V_297 = V_171 -> V_95 ;
T_2 * V_472 ;
int V_6 , V_603 = 0 ;
V_10 = F_175 ( V_26 , V_171 -> V_188 ) ;
if ( ! V_10 )
return F_252 ( V_26 , V_171 ) ;
V_472 = F_148 ( sizeof( T_2 ) * V_604 , V_210 ) ;
if ( ! V_472 ) {
F_43 ( V_38 , L_131 ) ;
return false ;
}
for ( V_6 = V_494 ; V_6 < V_604 ; V_6 ++ )
V_472 [ V_6 ] = F_176 ( V_297 -> V_470 [ V_6 ] ) ;
F_48 ( V_10 -> V_472 ) ;
V_10 -> V_472 = V_472 ;
if ( V_10 -> V_344 . V_105 < V_526 &&
V_10 -> V_344 . V_401 < V_397 &&
V_10 -> V_344 . V_488 == V_461 &&
( V_10 -> V_605 & ~ ( ( T_2 ) 1 ) ) != ( V_472 [ V_494 ] & ~ ( ( T_2 ) 1 ) ) ) {
F_43 ( V_38 , L_132 ,
( unsigned long long ) V_10 -> V_605 ) ;
F_68 ( V_10 -> V_26 , F_69 ( V_105 , V_150 ) , V_107 ) ;
return - V_108 ;
}
if ( F_127 ( V_10 ) ) {
int V_606 =
V_10 -> V_344 . V_105 == V_526 &&
V_10 -> V_26 -> V_180 >= 90 &&
V_10 -> V_242 -> V_469 . V_470 [ V_494 ] == V_499 &&
( V_472 [ V_502 ] & 8 ) ;
if ( V_606 ) {
F_129 ( V_38 , L_133 ) ;
F_241 ( V_10 , & V_607 ,
L_134 ,
V_608 ) ;
F_269 ( V_10 , V_494 , V_472 [ V_494 ] ) ;
F_269 ( V_10 , V_471 , 0 ) ;
F_270 ( F_271 ( V_10 , V_401 , V_434 , V_396 , V_434 ) ,
V_195 , NULL ) ;
F_263 ( V_10 ) ;
V_603 = 1 ;
}
F_131 ( V_10 ) ;
} else if ( V_10 -> V_344 . V_401 < V_397 &&
V_10 -> V_344 . V_488 == V_461 ) {
V_603 = F_272 ( V_10 , V_472 [ V_494 ] ) ;
}
F_117 ( V_10 -> V_179 ) ;
F_118 ( V_10 -> V_179 ) ;
if ( V_10 -> V_344 . V_105 >= V_526 && V_10 -> V_344 . V_401 < V_397 )
V_603 |= F_272 ( V_10 , V_472 [ V_494 ] ) ;
if ( V_603 )
F_273 ( V_10 , L_135 ) ;
return 0 ;
}
static union V_609 F_274 ( union V_609 V_610 )
{
union V_609 V_611 ;
static enum V_505 V_612 [] = {
[ V_103 ] = V_103 ,
[ V_526 ] = V_526 ,
[ V_613 ] = V_614 ,
[ V_614 ] = V_613 ,
[ V_150 ] = V_615 ,
[ V_423 ] = V_424 ,
[ V_510 ] = V_510 ,
} ;
V_611 . V_6 = V_610 . V_6 ;
V_611 . V_105 = V_612 [ V_610 . V_105 ] ;
V_611 . V_460 = V_610 . V_488 ;
V_611 . V_488 = V_610 . V_460 ;
V_611 . V_396 = V_610 . V_401 ;
V_611 . V_401 = V_610 . V_396 ;
V_611 . V_616 = ( V_610 . V_617 | V_610 . V_618 ) ;
return V_611 ;
}
static int F_275 ( struct V_94 * V_26 , struct V_170 * V_171 )
{
struct V_9 * V_10 ;
struct V_619 * V_297 = V_171 -> V_95 ;
union V_609 V_620 , V_621 ;
enum V_193 V_92 ;
V_10 = F_175 ( V_26 , V_171 -> V_188 ) ;
if ( ! V_10 )
return - V_108 ;
V_620 . V_6 = F_123 ( V_297 -> V_620 ) ;
V_621 . V_6 = F_123 ( V_297 -> V_621 ) ;
if ( F_66 ( V_202 , & V_10 -> V_26 -> V_63 ) &&
F_276 ( V_10 -> V_179 ) ) {
F_277 ( V_10 , V_622 ) ;
return 0 ;
}
V_620 = F_274 ( V_620 ) ;
V_621 = F_274 ( V_621 ) ;
V_92 = F_232 ( V_10 , V_195 , V_620 , V_621 ) ;
F_277 ( V_10 , V_92 ) ;
F_263 ( V_10 ) ;
return 0 ;
}
static int F_278 ( struct V_94 * V_26 , struct V_170 * V_171 )
{
struct V_619 * V_297 = V_171 -> V_95 ;
union V_609 V_620 , V_621 ;
enum V_193 V_92 ;
V_620 . V_6 = F_123 ( V_297 -> V_620 ) ;
V_621 . V_6 = F_123 ( V_297 -> V_621 ) ;
if ( F_66 ( V_202 , & V_26 -> V_63 ) &&
F_276 ( & V_26 -> V_181 ) ) {
F_279 ( V_26 , V_622 ) ;
return 0 ;
}
V_620 = F_274 ( V_620 ) ;
V_621 = F_274 ( V_621 ) ;
V_92 = F_68 ( V_26 , V_620 , V_621 , V_195 | V_623 | V_624 ) ;
F_279 ( V_26 , V_92 ) ;
return 0 ;
}
static int F_280 ( struct V_94 * V_26 , struct V_170 * V_171 )
{
struct V_9 * V_10 ;
struct V_625 * V_297 = V_171 -> V_95 ;
union V_609 V_626 , V_627 , V_628 ;
enum V_508 V_629 ;
enum V_630 V_631 ;
int V_92 ;
V_10 = F_175 ( V_26 , V_171 -> V_188 ) ;
if ( ! V_10 )
return F_252 ( V_26 , V_171 ) ;
V_628 . V_6 = F_123 ( V_297 -> V_344 ) ;
V_629 = V_628 . V_401 ;
if ( V_628 . V_401 == V_501 ) {
V_629 = V_10 -> V_472 [ V_502 ] & 4 ? V_397 : V_520 ;
F_129 ( V_38 , L_136 , F_281 ( V_629 ) ) ;
}
F_21 ( & V_10 -> V_26 -> V_27 ) ;
V_28:
V_626 = V_627 = F_282 ( V_10 ) ;
F_22 ( & V_10 -> V_26 -> V_27 ) ;
if ( V_626 . V_105 <= V_615 )
return - V_96 ;
if ( ( V_626 . V_396 == V_397 || V_626 . V_396 == V_520 ) &&
V_629 == V_434 &&
V_626 . V_105 > V_526 && V_626 . V_401 == V_434 ) {
if ( V_628 . V_105 > V_526 &&
V_628 . V_105 < V_345 )
V_629 = V_397 ;
else if ( V_626 . V_105 >= V_345 &&
V_628 . V_105 == V_526 ) {
if ( F_219 ( V_10 ) <= V_10 -> V_426 )
F_283 ( V_10 ) ;
return 0 ;
}
}
if ( V_626 . V_105 == V_424 && V_626 . V_401 == V_434 &&
V_628 . V_105 == V_526 && V_629 == V_434 ) {
F_284 ( V_10 ) ;
F_283 ( V_10 ) ;
return 0 ;
}
if ( V_626 . V_396 == V_434 && V_629 == V_397 &&
V_626 . V_105 == V_526 && V_628 . V_105 > V_345 )
V_629 = V_434 ;
if ( V_627 . V_105 == V_103 )
V_627 . V_105 = V_526 ;
if ( V_628 . V_105 == V_632 )
V_627 . V_105 = V_633 ;
if ( V_10 -> V_472 && V_628 . V_401 >= V_501 &&
F_137 ( V_10 , V_501 ) ) {
int V_634 ;
V_634 = ( V_626 . V_105 < V_526 ) ;
V_634 |= ( V_626 . V_105 == V_526 &&
( V_628 . V_401 == V_501 ||
V_626 . V_401 == V_501 ) ) ;
V_634 |= F_66 ( V_635 , & V_10 -> V_63 ) ;
V_634 |= ( V_626 . V_105 == V_526 &&
( V_628 . V_105 >= V_613 &&
V_628 . V_105 <= V_525 ) ) ;
if ( V_634 )
V_627 . V_105 = F_239 ( V_10 , V_628 . V_488 , V_629 ) ;
F_131 ( V_10 ) ;
if ( V_627 . V_105 == V_510 ) {
V_627 . V_105 = V_526 ;
if ( V_10 -> V_344 . V_401 == V_501 ) {
F_285 ( V_10 , F_69 ( V_401 , V_636 ) ) ;
} else if ( V_628 . V_401 == V_501 ) {
F_43 ( V_38 , L_137 ) ;
V_628 . V_401 = V_637 ;
V_629 = V_637 ;
} else {
if ( F_266 ( V_521 , & V_10 -> V_26 -> V_63 ) )
return - V_108 ;
F_49 ( V_626 . V_105 == V_103 ) ;
F_68 ( V_10 -> V_26 , F_69 ( V_105 , V_150 ) , V_107 ) ;
return - V_108 ;
}
}
}
F_21 ( & V_10 -> V_26 -> V_27 ) ;
if ( V_626 . V_6 != F_282 ( V_10 ) . V_6 )
goto V_28;
F_101 ( V_635 , & V_10 -> V_63 ) ;
V_627 . V_460 = V_628 . V_488 ;
V_627 . V_396 = V_629 ;
V_627 . V_616 = ( V_628 . V_617 | V_628 . V_618 ) ;
if ( ( V_627 . V_105 == V_526 || V_627 . V_105 == V_524 ) && V_627 . V_401 == V_501 )
V_627 . V_401 = V_10 -> V_514 . V_401 ;
V_631 = V_195 + ( V_626 . V_105 < V_526 && V_627 . V_105 >= V_526 ? 0 : V_107 ) ;
if ( V_627 . V_396 == V_520 && F_286 ( V_10 ) && V_627 . V_105 == V_526 && V_626 . V_105 < V_526 &&
F_66 ( V_638 , & V_10 -> V_63 ) ) {
F_22 ( & V_10 -> V_26 -> V_27 ) ;
F_43 ( V_38 , L_138 ) ;
F_287 ( V_10 -> V_26 ) ;
F_288 ( V_10 ) ;
F_101 ( V_638 , & V_10 -> V_63 ) ;
F_68 ( V_10 -> V_26 , F_289 ( V_105 , V_639 , V_640 , 0 ) , V_107 ) ;
return - V_108 ;
}
V_92 = F_270 ( V_10 , V_627 , V_631 , NULL ) ;
V_627 = F_282 ( V_10 ) ;
F_22 ( & V_10 -> V_26 -> V_27 ) ;
if ( V_92 < V_196 ) {
F_68 ( V_10 -> V_26 , F_69 ( V_105 , V_150 ) , V_107 ) ;
return - V_108 ;
}
if ( V_626 . V_105 > V_103 ) {
if ( V_627 . V_105 > V_526 && V_628 . V_105 <= V_526 &&
V_628 . V_401 != V_501 ) {
F_99 ( V_10 ) ;
F_100 ( V_10 ) ;
}
}
F_101 ( V_221 , & V_10 -> V_63 ) ;
F_263 ( V_10 ) ;
return 0 ;
}
static int F_290 ( struct V_94 * V_26 , struct V_170 * V_171 )
{
struct V_9 * V_10 ;
struct V_641 * V_297 = V_171 -> V_95 ;
V_10 = F_175 ( V_26 , V_171 -> V_188 ) ;
if ( ! V_10 )
return - V_108 ;
F_210 ( V_10 -> V_294 ,
V_10 -> V_344 . V_105 == V_642 ||
V_10 -> V_344 . V_105 == V_633 ||
V_10 -> V_344 . V_105 < V_526 ||
V_10 -> V_344 . V_401 < V_501 ) ;
if ( F_137 ( V_10 , V_501 ) ) {
F_269 ( V_10 , V_494 , F_176 ( V_297 -> V_470 ) ) ;
F_269 ( V_10 , V_471 , 0UL ) ;
F_273 ( V_10 , L_139 ) ;
F_291 ( V_10 , V_389 ) ;
F_131 ( V_10 ) ;
} else
F_43 ( V_38 , L_140 ) ;
return 0 ;
}
static int
F_292 ( struct V_9 * V_10 , unsigned int V_58 ,
unsigned long * V_297 , struct V_643 * V_644 )
{
unsigned int V_47 = V_553 -
F_93 ( V_10 -> V_26 ) ;
unsigned int V_645 = F_75 ( T_6 , V_47 / sizeof( * V_297 ) ,
V_644 -> V_646 - V_644 -> V_647 ) ;
unsigned int V_648 = V_645 * sizeof( * V_297 ) ;
int V_70 ;
if ( V_648 != V_58 ) {
F_43 ( V_38 , L_141 , V_55 , V_648 , V_58 ) ;
return - V_108 ;
}
if ( V_648 == 0 )
return 0 ;
V_70 = F_70 ( V_10 -> V_26 , V_297 , V_648 ) ;
if ( V_70 )
return V_70 ;
F_293 ( V_10 , V_644 -> V_647 , V_645 , V_297 ) ;
V_644 -> V_647 += V_645 ;
V_644 -> V_649 = V_644 -> V_647 * V_650 ;
if ( V_644 -> V_649 > V_644 -> V_651 )
V_644 -> V_649 = V_644 -> V_651 ;
return 1 ;
}
static enum V_652 F_294 ( struct V_653 * V_297 )
{
return (enum V_652 ) ( V_297 -> V_654 & 0x0f ) ;
}
static int F_295 ( struct V_653 * V_297 )
{
return ( V_297 -> V_654 & 0x80 ) != 0 ;
}
static int F_296 ( struct V_653 * V_297 )
{
return ( V_297 -> V_654 >> 4 ) & 0x7 ;
}
static int
F_297 ( struct V_9 * V_10 ,
struct V_653 * V_297 ,
struct V_643 * V_644 ,
unsigned int V_5 )
{
struct V_655 V_656 ;
T_2 V_657 ;
T_2 V_658 ;
T_2 V_4 ;
unsigned long V_200 = V_644 -> V_649 ;
unsigned long V_659 ;
int V_660 = F_295 ( V_297 ) ;
int V_661 ;
int V_493 ;
F_298 ( & V_656 , V_297 -> V_662 , V_5 , F_296 ( V_297 ) ) ;
V_493 = F_299 ( & V_656 , & V_657 , 64 ) ;
if ( V_493 < 0 )
return - V_108 ;
for ( V_661 = V_493 ; V_661 > 0 ; V_200 += V_658 , V_660 = ! V_660 ) {
V_493 = F_300 ( & V_658 , V_657 ) ;
if ( V_493 <= 0 )
return - V_108 ;
if ( V_660 ) {
V_659 = V_200 + V_658 - 1 ;
if ( V_659 >= V_644 -> V_651 ) {
F_43 ( V_38 , L_142 , V_659 ) ;
return - V_108 ;
}
F_301 ( V_10 , V_200 , V_659 ) ;
}
if ( V_661 < V_493 ) {
F_43 ( V_38 , L_143 ,
V_661 , V_493 , V_657 ,
( unsigned int ) ( V_656 . V_663 . V_354 - V_297 -> V_662 ) ,
( unsigned int ) V_656 . V_664 ) ;
return - V_108 ;
}
V_657 >>= V_493 ;
V_661 -= V_493 ;
V_493 = F_299 ( & V_656 , & V_4 , 64 - V_661 ) ;
if ( V_493 < 0 )
return - V_108 ;
V_657 |= V_4 << V_661 ;
V_661 += V_493 ;
}
V_644 -> V_649 = V_200 ;
F_302 ( V_644 ) ;
return ( V_200 != V_644 -> V_651 ) ;
}
static int
F_303 ( struct V_9 * V_10 ,
struct V_653 * V_297 ,
struct V_643 * V_644 ,
unsigned int V_5 )
{
if ( F_294 ( V_297 ) == V_665 )
return F_297 ( V_10 , V_297 , V_644 , V_5 - sizeof( * V_297 ) ) ;
F_43 ( V_38 , L_144 , V_297 -> V_654 ) ;
F_68 ( V_10 -> V_26 , F_69 ( V_105 , V_639 ) , V_107 ) ;
return - V_108 ;
}
void F_304 ( struct V_9 * V_10 ,
const char * V_666 , struct V_643 * V_644 )
{
unsigned int V_169 = F_93 ( V_10 -> V_26 ) ;
unsigned int V_47 = V_553 - V_169 ;
unsigned int V_667 =
V_169 * ( F_305 ( V_644 -> V_646 , V_47 ) + 1 ) +
V_644 -> V_646 * sizeof( unsigned long ) ;
unsigned int V_668 = V_644 -> V_669 [ 0 ] + V_644 -> V_669 [ 1 ] ;
unsigned int V_670 ;
if ( V_668 == 0 )
return;
if ( V_668 >= V_667 )
return;
V_670 = ( V_668 > V_671 / 1000 ) ? ( V_668 / ( V_667 / 1000 ) )
: ( 1000 * V_668 / V_667 ) ;
if ( V_670 > 1000 )
V_670 = 1000 ;
V_670 = 1000 - V_670 ;
F_129 ( V_38 , L_145
L_146 ,
V_666 ,
V_644 -> V_669 [ 1 ] , V_644 -> V_672 [ 1 ] ,
V_644 -> V_669 [ 0 ] , V_644 -> V_672 [ 0 ] ,
V_668 , V_670 / 10 , V_670 % 10 ) ;
}
static int F_306 ( struct V_94 * V_26 , struct V_170 * V_171 )
{
struct V_9 * V_10 ;
struct V_643 V_644 ;
int V_70 ;
V_10 = F_175 ( V_26 , V_171 -> V_188 ) ;
if ( ! V_10 )
return - V_108 ;
F_307 ( V_10 , L_147 , V_523 ) ;
V_644 = (struct V_643 ) {
. V_651 = F_226 ( V_10 ) ,
. V_646 = F_308 ( V_10 ) ,
} ;
for(; ; ) {
if ( V_171 -> V_168 == V_673 )
V_70 = F_292 ( V_10 , V_171 -> V_58 , V_171 -> V_95 , & V_644 ) ;
else if ( V_171 -> V_168 == V_674 ) {
struct V_653 * V_297 = V_171 -> V_95 ;
if ( V_171 -> V_58 > V_553 - F_93 ( V_26 ) ) {
F_43 ( V_38 , L_148 ) ;
V_70 = - V_108 ;
goto V_104;
}
if ( V_171 -> V_58 <= sizeof( * V_297 ) ) {
F_43 ( V_38 , L_149 , V_171 -> V_58 ) ;
V_70 = - V_108 ;
goto V_104;
}
V_70 = F_70 ( V_10 -> V_26 , V_297 , V_171 -> V_58 ) ;
if ( V_70 )
goto V_104;
V_70 = F_303 ( V_10 , V_297 , & V_644 , V_171 -> V_58 ) ;
} else {
F_33 ( V_38 , L_150 , V_171 -> V_168 ) ;
V_70 = - V_108 ;
goto V_104;
}
V_644 . V_672 [ V_171 -> V_168 == V_673 ] ++ ;
V_644 . V_669 [ V_171 -> V_168 == V_673 ] += F_93 ( V_26 ) + V_171 -> V_58 ;
if ( V_70 <= 0 ) {
if ( V_70 < 0 )
goto V_104;
break;
}
V_70 = F_125 ( V_10 -> V_26 , V_171 ) ;
if ( V_70 )
goto V_104;
}
F_304 ( V_10 , L_151 , & V_644 ) ;
if ( V_10 -> V_344 . V_105 == V_525 ) {
enum V_193 V_92 ;
V_70 = F_309 ( V_10 ) ;
if ( V_70 )
goto V_104;
V_92 = F_310 ( V_10 , F_69 ( V_105 , V_642 ) , V_195 ) ;
F_49 ( V_92 == V_196 ) ;
} else if ( V_10 -> V_344 . V_105 != V_524 ) {
F_129 ( V_38 , L_152 ,
F_240 ( V_10 -> V_344 . V_105 ) ) ;
}
V_70 = 0 ;
V_104:
F_311 ( V_10 ) ;
if ( ! V_70 && V_10 -> V_344 . V_105 == V_524 )
F_291 ( V_10 , V_345 ) ;
return V_70 ;
}
static int F_312 ( struct V_94 * V_26 , struct V_170 * V_171 )
{
F_72 ( V_26 , L_153 ,
V_171 -> V_168 , V_171 -> V_58 ) ;
return F_251 ( V_26 , V_171 ) ;
}
static int F_313 ( struct V_94 * V_26 , struct V_170 * V_171 )
{
F_314 ( V_26 -> V_95 . V_76 ) ;
return 0 ;
}
static int F_315 ( struct V_94 * V_26 , struct V_170 * V_171 )
{
struct V_9 * V_10 ;
struct V_675 * V_297 = V_171 -> V_95 ;
V_10 = F_175 ( V_26 , V_171 -> V_188 ) ;
if ( ! V_10 )
return - V_108 ;
switch ( V_10 -> V_344 . V_105 ) {
case V_642 :
case V_525 :
case V_633 :
break;
default:
F_43 ( V_38 , L_154 ,
F_240 ( V_10 -> V_344 . V_105 ) ) ;
}
F_211 ( V_10 , F_176 ( V_297 -> V_46 ) , F_123 ( V_297 -> V_433 ) ) ;
return 0 ;
}
static void F_316 ( struct V_94 * V_26 )
{
struct V_170 V_171 ;
T_6 V_676 ;
int V_70 ;
while ( F_110 ( & V_26 -> V_207 ) == V_677 ) {
struct V_678 * V_168 ;
F_317 ( & V_26 -> V_207 ) ;
if ( F_125 ( V_26 , & V_171 ) )
goto V_679;
V_168 = & V_680 [ V_171 . V_168 ] ;
if ( F_177 ( V_171 . V_168 >= F_318 ( V_680 ) || ! V_168 -> V_681 ) ) {
F_65 ( V_26 , L_155 ,
F_253 ( V_171 . V_168 ) , V_171 . V_168 ) ;
goto V_679;
}
V_676 = V_168 -> V_682 ;
if ( V_171 . V_58 > V_676 && ! V_168 -> V_683 ) {
F_65 ( V_26 , L_156 ,
F_253 ( V_171 . V_168 ) , V_171 . V_58 ) ;
goto V_679;
}
if ( V_676 ) {
V_70 = F_71 ( V_26 , V_171 . V_95 , V_676 ) ;
if ( V_70 )
goto V_679;
V_171 . V_58 -= V_676 ;
}
V_70 = V_168 -> V_681 ( V_26 , & V_171 ) ;
if ( V_70 ) {
F_65 ( V_26 , L_157 ,
F_253 ( V_171 . V_168 ) , V_70 , V_171 . V_58 ) ;
goto V_679;
}
}
return;
V_679:
F_68 ( V_26 , F_69 ( V_105 , V_639 ) , V_107 ) ;
}
void F_319 ( struct V_94 * V_26 )
{
struct V_684 V_685 ;
V_685 . V_22 . V_73 = V_686 ;
V_685 . V_22 . V_26 = V_26 ;
F_320 ( & V_685 . V_687 ) ;
F_321 ( & V_26 -> V_688 , & V_685 . V_22 ) ;
F_322 ( & V_685 . V_687 ) ;
}
static void F_323 ( struct V_94 * V_26 )
{
struct V_9 * V_10 ;
enum V_505 V_689 ;
int V_188 ;
if ( V_26 -> V_102 == V_690 )
return;
F_68 ( V_26 , F_69 ( V_105 , V_691 ) , V_107 ) ;
F_324 ( & V_26 -> V_223 ) ;
F_325 ( V_26 ) ;
F_27 () ;
F_115 (&tconn->volumes, mdev, vnr) {
F_116 ( & V_10 -> V_220 ) ;
F_29 () ;
F_326 ( V_10 ) ;
F_119 ( & V_10 -> V_220 , & V_222 ) ;
F_27 () ;
}
F_29 () ;
if ( ! F_56 ( & V_26 -> V_260 -> V_23 ) )
F_65 ( V_26 , L_158 ) ;
F_45 ( & V_26 -> V_260 -> V_249 , 0 ) ;
V_26 -> V_692 . V_693 = false ;
F_64 ( V_26 , L_159 ) ;
if ( F_327 ( V_26 ) == V_461 && F_328 ( V_26 ) >= V_694 )
F_329 ( V_26 ) ;
F_21 ( & V_26 -> V_27 ) ;
V_689 = V_26 -> V_102 ;
if ( V_689 >= V_695 )
F_207 ( V_26 , F_69 ( V_105 , V_695 ) , V_195 ) ;
F_22 ( & V_26 -> V_27 ) ;
if ( V_689 == V_150 )
F_68 ( V_26 , F_69 ( V_105 , V_690 ) , V_195 | V_107 ) ;
}
static int F_326 ( struct V_9 * V_10 )
{
unsigned int V_6 ;
F_21 ( & V_10 -> V_26 -> V_27 ) ;
F_55 ( V_10 , & V_10 -> V_295 ) ;
F_55 ( V_10 , & V_10 -> V_324 ) ;
F_55 ( V_10 , & V_10 -> V_462 ) ;
F_22 ( & V_10 -> V_26 -> V_27 ) ;
F_330 ( V_10 ) ;
V_10 -> V_458 = 0 ;
V_10 -> V_426 = 0 ;
F_45 ( & V_10 -> V_696 , 0 ) ;
F_39 ( & V_10 -> V_294 ) ;
F_331 ( & V_10 -> V_697 ) ;
F_332 ( ( unsigned long ) V_10 ) ;
F_333 ( V_10 ) ;
F_53 ( V_10 ) ;
F_333 ( V_10 ) ;
F_330 ( V_10 ) ;
F_48 ( V_10 -> V_472 ) ;
V_10 -> V_472 = NULL ;
if ( ! F_286 ( V_10 ) )
F_287 ( V_10 -> V_26 ) ;
F_263 ( V_10 ) ;
F_210 ( V_10 -> V_294 , ! F_66 ( V_698 , & V_10 -> V_63 ) ) ;
V_6 = F_51 ( V_10 , & V_10 -> V_69 ) ;
if ( V_6 )
F_129 ( V_38 , L_160 , V_6 ) ;
V_6 = F_30 ( & V_10 -> V_41 ) ;
if ( V_6 )
F_129 ( V_38 , L_161 , V_6 ) ;
V_6 = F_30 ( & V_10 -> V_34 ) ;
if ( V_6 )
F_129 ( V_38 , L_162 , V_6 ) ;
F_49 ( F_56 ( & V_10 -> V_462 ) ) ;
F_49 ( F_56 ( & V_10 -> V_295 ) ) ;
F_49 ( F_56 ( & V_10 -> V_324 ) ) ;
F_49 ( F_56 ( & V_10 -> V_71 ) ) ;
return 0 ;
}
static int F_334 ( struct V_94 * V_26 )
{
struct V_166 * V_77 ;
struct V_699 * V_297 ;
V_77 = & V_26 -> V_95 ;
V_297 = F_90 ( V_26 , V_77 ) ;
if ( ! V_297 )
return - V_108 ;
memset ( V_297 , 0 , sizeof( * V_297 ) ) ;
V_297 -> V_700 = F_121 ( V_701 ) ;
V_297 -> V_702 = F_121 ( V_703 ) ;
return F_91 ( V_26 , V_77 , V_704 , sizeof( * V_297 ) , NULL , 0 ) ;
}
static int F_112 ( struct V_94 * V_26 )
{
struct V_699 * V_297 ;
const int F_153 = sizeof( struct V_699 ) ;
struct V_170 V_171 ;
int V_70 ;
V_70 = F_334 ( V_26 ) ;
if ( V_70 )
return 0 ;
V_70 = F_125 ( V_26 , & V_171 ) ;
if ( V_70 )
return 0 ;
if ( V_171 . V_168 != V_704 ) {
F_65 ( V_26 , L_163 ,
F_253 ( V_171 . V_168 ) , V_171 . V_168 ) ;
return - 1 ;
}
if ( V_171 . V_58 != F_153 ) {
F_65 ( V_26 , L_164 ,
F_153 , V_171 . V_58 ) ;
return - 1 ;
}
V_297 = V_171 . V_95 ;
V_70 = F_71 ( V_26 , V_297 , F_153 ) ;
if ( V_70 )
return 0 ;
V_297 -> V_700 = F_123 ( V_297 -> V_700 ) ;
V_297 -> V_702 = F_123 ( V_297 -> V_702 ) ;
if ( V_297 -> V_702 == 0 )
V_297 -> V_702 = V_297 -> V_700 ;
if ( V_703 < V_297 -> V_700 ||
V_701 > V_297 -> V_702 )
goto V_705;
V_26 -> V_180 = F_75 ( int , V_703 , V_297 -> V_702 ) ;
F_64 ( V_26 , L_165
L_166 , V_26 -> V_180 ) ;
return 1 ;
V_705:
F_65 ( V_26 , L_167
L_168 ,
V_701 , V_703 ,
V_297 -> V_700 , V_297 -> V_702 ) ;
return - 1 ;
}
static int F_113 ( struct V_94 * V_26 )
{
F_43 ( V_38 , L_169 ) ;
F_43 ( V_38 , L_170 ) ;
return - 1 ;
}
static int F_113 ( struct V_94 * V_26 )
{
struct V_166 * V_77 ;
char V_706 [ V_707 ] ;
struct V_708 V_709 ;
char * V_710 = NULL ;
char * V_711 = NULL ;
char * V_712 = NULL ;
unsigned int V_713 ;
char V_714 [ V_538 ] ;
unsigned int V_715 ;
struct V_716 V_717 ;
struct V_170 V_171 ;
struct V_29 * V_30 ;
int V_70 , V_92 ;
F_27 () ;
V_30 = F_28 ( V_26 -> V_29 ) ;
V_713 = strlen ( V_30 -> V_718 ) ;
memcpy ( V_714 , V_30 -> V_718 , V_713 ) ;
F_29 () ;
V_717 . V_552 = V_26 -> V_216 ;
V_717 . V_63 = 0 ;
V_92 = F_335 ( V_26 -> V_216 , ( V_719 * ) V_714 , V_713 ) ;
if ( V_92 ) {
F_65 ( V_26 , L_171 , V_92 ) ;
V_92 = - 1 ;
goto V_57;
}
F_336 ( V_706 , V_707 ) ;
V_77 = & V_26 -> V_95 ;
if ( ! F_90 ( V_26 , V_77 ) ) {
V_92 = 0 ;
goto V_57;
}
V_92 = ! F_91 ( V_26 , V_77 , V_720 , 0 ,
V_706 , V_707 ) ;
if ( ! V_92 )
goto V_57;
V_70 = F_125 ( V_26 , & V_171 ) ;
if ( V_70 ) {
V_92 = 0 ;
goto V_57;
}
if ( V_171 . V_168 != V_720 ) {
F_65 ( V_26 , L_172 ,
F_253 ( V_171 . V_168 ) , V_171 . V_168 ) ;
V_92 = 0 ;
goto V_57;
}
if ( V_171 . V_58 > V_707 * 2 ) {
F_65 ( V_26 , L_173 ) ;
V_92 = - 1 ;
goto V_57;
}
V_712 = F_148 ( V_171 . V_58 , V_210 ) ;
if ( V_712 == NULL ) {
F_65 ( V_26 , L_174 ) ;
V_92 = - 1 ;
goto V_57;
}
V_70 = F_71 ( V_26 , V_712 , V_171 . V_58 ) ;
if ( V_70 ) {
V_92 = 0 ;
goto V_57;
}
V_715 = F_152 ( V_26 -> V_216 ) ;
V_710 = F_148 ( V_715 , V_210 ) ;
if ( V_710 == NULL ) {
F_65 ( V_26 , L_175 ) ;
V_92 = - 1 ;
goto V_57;
}
F_337 ( & V_709 , 1 ) ;
F_338 ( & V_709 , V_712 , V_171 . V_58 ) ;
V_92 = F_339 ( & V_717 , & V_709 , V_709 . V_233 , V_710 ) ;
if ( V_92 ) {
F_65 ( V_26 , L_176 , V_92 ) ;
V_92 = - 1 ;
goto V_57;
}
if ( ! F_90 ( V_26 , V_77 ) ) {
V_92 = 0 ;
goto V_57;
}
V_92 = ! F_91 ( V_26 , V_77 , V_721 , 0 ,
V_710 , V_715 ) ;
if ( ! V_92 )
goto V_57;
V_70 = F_125 ( V_26 , & V_171 ) ;
if ( V_70 ) {
V_92 = 0 ;
goto V_57;
}
if ( V_171 . V_168 != V_721 ) {
F_65 ( V_26 , L_177 ,
F_253 ( V_171 . V_168 ) , V_171 . V_168 ) ;
V_92 = 0 ;
goto V_57;
}
if ( V_171 . V_58 != V_715 ) {
F_65 ( V_26 , L_178 ) ;
V_92 = 0 ;
goto V_57;
}
V_70 = F_71 ( V_26 , V_710 , V_715 ) ;
if ( V_70 ) {
V_92 = 0 ;
goto V_57;
}
V_711 = F_148 ( V_715 , V_210 ) ;
if ( V_711 == NULL ) {
F_65 ( V_26 , L_179 ) ;
V_92 = - 1 ;
goto V_57;
}
F_338 ( & V_709 , V_706 , V_707 ) ;
V_92 = F_339 ( & V_717 , & V_709 , V_709 . V_233 , V_711 ) ;
if ( V_92 ) {
F_65 ( V_26 , L_176 , V_92 ) ;
V_92 = - 1 ;
goto V_57;
}
V_92 = ! memcmp ( V_710 , V_711 , V_715 ) ;
if ( V_92 )
F_64 ( V_26 , L_180 ,
V_715 ) ;
else
V_92 = - 1 ;
V_57:
F_48 ( V_712 ) ;
F_48 ( V_710 ) ;
F_48 ( V_711 ) ;
return V_92 ;
}
int F_340 ( struct V_722 * V_723 )
{
struct V_94 * V_26 = V_723 -> V_26 ;
int V_190 ;
F_64 ( V_26 , L_181 ) ;
do {
V_190 = F_103 ( V_26 ) ;
if ( V_190 == 0 ) {
F_323 ( V_26 ) ;
F_106 ( V_100 ) ;
}
if ( V_190 == - 1 ) {
F_72 ( V_26 , L_182 ) ;
F_68 ( V_26 , F_69 ( V_105 , V_150 ) , V_107 ) ;
}
} while ( V_190 == 0 );
if ( V_190 > 0 )
F_316 ( V_26 ) ;
F_323 ( V_26 ) ;
F_64 ( V_26 , L_183 ) ;
return 0 ;
}
static int F_341 ( struct V_94 * V_26 , struct V_170 * V_171 )
{
struct V_724 * V_297 = V_171 -> V_95 ;
int V_725 = F_123 ( V_297 -> V_725 ) ;
if ( V_725 >= V_196 ) {
F_107 ( V_726 , & V_26 -> V_63 ) ;
} else {
F_107 ( V_727 , & V_26 -> V_63 ) ;
F_65 ( V_26 , L_184 ,
F_342 ( V_725 ) , V_725 ) ;
}
F_39 ( & V_26 -> V_101 ) ;
return 0 ;
}
static int F_343 ( struct V_94 * V_26 , struct V_170 * V_171 )
{
struct V_9 * V_10 ;
struct V_724 * V_297 = V_171 -> V_95 ;
int V_725 = F_123 ( V_297 -> V_725 ) ;
V_10 = F_175 ( V_26 , V_171 -> V_188 ) ;
if ( ! V_10 )
return - V_108 ;
if ( F_66 ( V_728 , & V_26 -> V_63 ) ) {
F_49 ( V_26 -> V_180 < 100 ) ;
return F_341 ( V_26 , V_171 ) ;
}
if ( V_725 >= V_196 ) {
F_107 ( V_729 , & V_10 -> V_63 ) ;
} else {
F_107 ( V_730 , & V_10 -> V_63 ) ;
F_43 ( V_38 , L_184 ,
F_342 ( V_725 ) , V_725 ) ;
}
F_39 ( & V_10 -> V_731 ) ;
return 0 ;
}
static int F_344 ( struct V_94 * V_26 , struct V_170 * V_171 )
{
return F_345 ( V_26 ) ;
}
static int F_346 ( struct V_94 * V_26 , struct V_170 * V_171 )
{
V_26 -> V_199 . V_76 -> V_111 -> V_137 = V_26 -> V_29 -> V_214 * V_100 ;
if ( ! F_347 ( V_732 , & V_26 -> V_63 ) )
F_39 ( & V_26 -> V_101 ) ;
return 0 ;
}
static int F_348 ( struct V_94 * V_26 , struct V_170 * V_171 )
{
struct V_9 * V_10 ;
struct V_733 * V_297 = V_171 -> V_95 ;
T_3 V_46 = F_176 ( V_297 -> V_46 ) ;
int V_433 = F_123 ( V_297 -> V_433 ) ;
V_10 = F_175 ( V_26 , V_171 -> V_188 ) ;
if ( ! V_10 )
return - V_108 ;
F_49 ( V_10 -> V_26 -> V_180 >= 89 ) ;
F_192 ( V_10 , F_123 ( V_297 -> V_385 ) ) ;
if ( F_127 ( V_10 ) ) {
F_349 ( V_10 , V_46 ) ;
F_165 ( V_10 , V_46 , V_433 ) ;
V_10 -> V_734 += ( V_433 >> V_735 ) ;
F_131 ( V_10 ) ;
}
F_170 ( V_10 ) ;
F_36 ( V_433 >> 9 , & V_10 -> V_336 ) ;
return 0 ;
}
static int
F_350 ( struct V_9 * V_10 , T_2 V_45 , T_3 V_46 ,
struct V_328 * V_329 , const char * V_331 ,
enum V_736 V_117 , bool V_330 )
{
struct V_309 * V_310 ;
struct V_377 V_378 ;
F_21 ( & V_10 -> V_26 -> V_27 ) ;
V_310 = F_172 ( V_10 , V_329 , V_45 , V_46 , V_330 , V_331 ) ;
if ( F_177 ( ! V_310 ) ) {
F_22 ( & V_10 -> V_26 -> V_27 ) ;
return - V_108 ;
}
F_184 ( V_310 , V_117 , & V_378 ) ;
F_22 ( & V_10 -> V_26 -> V_27 ) ;
if ( V_378 . V_277 )
F_200 ( V_10 , & V_378 ) ;
return 0 ;
}
static int F_351 ( struct V_94 * V_26 , struct V_170 * V_171 )
{
struct V_9 * V_10 ;
struct V_733 * V_297 = V_171 -> V_95 ;
T_3 V_46 = F_176 ( V_297 -> V_46 ) ;
int V_433 = F_123 ( V_297 -> V_433 ) ;
enum V_736 V_117 ;
V_10 = F_175 ( V_26 , V_171 -> V_188 ) ;
if ( ! V_10 )
return - V_108 ;
F_192 ( V_10 , F_123 ( V_297 -> V_385 ) ) ;
if ( V_297 -> V_64 == V_323 ) {
F_165 ( V_10 , V_46 , V_433 ) ;
F_170 ( V_10 ) ;
return 0 ;
}
switch ( V_171 -> V_168 ) {
case V_321 :
V_117 = V_737 ;
break;
case V_348 :
V_117 = V_738 ;
break;
case V_395 :
V_117 = V_739 ;
break;
case V_352 :
V_117 = V_340 ;
break;
case V_353 :
V_117 = V_740 ;
break;
default:
F_224 () ;
}
return F_350 ( V_10 , V_297 -> V_64 , V_46 ,
& V_10 -> V_293 , V_55 ,
V_117 , false ) ;
}
static int F_352 ( struct V_94 * V_26 , struct V_170 * V_171 )
{
struct V_9 * V_10 ;
struct V_733 * V_297 = V_171 -> V_95 ;
T_3 V_46 = F_176 ( V_297 -> V_46 ) ;
int V_58 = F_123 ( V_297 -> V_433 ) ;
int V_70 ;
V_10 = F_175 ( V_26 , V_171 -> V_188 ) ;
if ( ! V_10 )
return - V_108 ;
F_192 ( V_10 , F_123 ( V_297 -> V_385 ) ) ;
if ( V_297 -> V_64 == V_323 ) {
F_170 ( V_10 ) ;
F_167 ( V_10 , V_46 , V_58 ) ;
return 0 ;
}
V_70 = F_350 ( V_10 , V_297 -> V_64 , V_46 ,
& V_10 -> V_293 , V_55 ,
V_379 , true ) ;
if ( V_70 ) {
F_211 ( V_10 , V_46 , V_58 ) ;
}
return 0 ;
}
static int F_353 ( struct V_94 * V_26 , struct V_170 * V_171 )
{
struct V_9 * V_10 ;
struct V_733 * V_297 = V_171 -> V_95 ;
T_3 V_46 = F_176 ( V_297 -> V_46 ) ;
V_10 = F_175 ( V_26 , V_171 -> V_188 ) ;
if ( ! V_10 )
return - V_108 ;
F_192 ( V_10 , F_123 ( V_297 -> V_385 ) ) ;
F_43 ( V_38 , L_185 ,
( unsigned long long ) V_46 , F_123 ( V_297 -> V_433 ) ) ;
return F_350 ( V_10 , V_297 -> V_64 , V_46 ,
& V_10 -> V_333 , V_55 ,
V_379 , false ) ;
}
static int F_354 ( struct V_94 * V_26 , struct V_170 * V_171 )
{
struct V_9 * V_10 ;
T_3 V_46 ;
int V_58 ;
struct V_733 * V_297 = V_171 -> V_95 ;
V_10 = F_175 ( V_26 , V_171 -> V_188 ) ;
if ( ! V_10 )
return - V_108 ;
V_46 = F_176 ( V_297 -> V_46 ) ;
V_58 = F_123 ( V_297 -> V_433 ) ;
F_192 ( V_10 , F_123 ( V_297 -> V_385 ) ) ;
F_170 ( V_10 ) ;
if ( F_137 ( V_10 , V_636 ) ) {
F_349 ( V_10 , V_46 ) ;
switch ( V_171 -> V_168 ) {
case V_440 :
F_167 ( V_10 , V_46 , V_58 ) ;
case V_741 :
break;
default:
F_224 () ;
}
F_131 ( V_10 ) ;
}
return 0 ;
}
static int F_355 ( struct V_94 * V_26 , struct V_170 * V_171 )
{
struct V_742 * V_297 = V_171 -> V_95 ;
struct V_9 * V_10 ;
int V_188 ;
F_356 ( V_26 , V_297 -> V_298 , F_123 ( V_297 -> V_743 ) ) ;
F_27 () ;
F_115 (&tconn->volumes, mdev, vnr) {
if ( V_10 -> V_344 . V_105 == V_632 &&
F_30 ( & V_10 -> V_744 ) == 0 &&
! F_347 ( V_745 , & V_10 -> V_63 ) ) {
V_10 -> V_746 . V_747 = V_186 + V_100 ;
F_357 ( & V_10 -> V_746 ) ;
}
}
F_29 () ;
return 0 ;
}
static int F_358 ( struct V_94 * V_26 , struct V_170 * V_171 )
{
struct V_9 * V_10 ;
struct V_733 * V_297 = V_171 -> V_95 ;
struct V_318 * V_22 ;
T_3 V_46 ;
int V_58 ;
V_10 = F_175 ( V_26 , V_171 -> V_188 ) ;
if ( ! V_10 )
return - V_108 ;
V_46 = F_176 ( V_297 -> V_46 ) ;
V_58 = F_123 ( V_297 -> V_433 ) ;
F_192 ( V_10 , F_123 ( V_297 -> V_385 ) ) ;
if ( F_176 ( V_297 -> V_64 ) == V_748 )
F_359 ( V_10 , V_46 , V_58 ) ;
else
F_284 ( V_10 ) ;
if ( ! F_127 ( V_10 ) )
return 0 ;
F_349 ( V_10 , V_46 ) ;
F_170 ( V_10 ) ;
-- V_10 -> V_425 ;
if ( ( V_10 -> V_425 & 0x200 ) == 0x200 )
F_360 ( V_10 , V_10 -> V_425 ) ;
if ( V_10 -> V_425 == 0 ) {
V_22 = F_148 ( sizeof( * V_22 ) , V_210 ) ;
if ( V_22 ) {
V_22 -> V_73 = V_749 ;
V_22 -> V_10 = V_10 ;
F_321 ( & V_10 -> V_26 -> V_688 , V_22 ) ;
} else {
F_43 ( V_38 , L_186 ) ;
F_284 ( V_10 ) ;
F_283 ( V_10 ) ;
}
}
F_131 ( V_10 ) ;
return 0 ;
}
static int F_361 ( struct V_94 * V_26 , struct V_170 * V_171 )
{
return 0 ;
}
static int F_362 ( struct V_94 * V_26 )
{
struct V_9 * V_10 ;
int V_188 , V_750 = 0 ;
do {
F_101 ( V_751 , & V_26 -> V_63 ) ;
F_108 ( V_37 ) ;
F_27 () ;
F_115 (&tconn->volumes, mdev, vnr) {
F_116 ( & V_10 -> V_220 ) ;
F_29 () ;
if ( F_53 ( V_10 ) ) {
F_119 ( & V_10 -> V_220 , & V_222 ) ;
return 1 ;
}
F_119 ( & V_10 -> V_220 , & V_222 ) ;
F_27 () ;
}
F_107 ( V_751 , & V_26 -> V_63 ) ;
F_21 ( & V_26 -> V_27 ) ;
F_115 (&tconn->volumes, mdev, vnr) {
V_750 = ! F_56 ( & V_10 -> V_71 ) ;
if ( V_750 )
break;
}
F_22 ( & V_26 -> V_27 ) ;
F_29 () ;
} while ( V_750 );
return 0 ;
}
int F_363 ( struct V_722 * V_723 )
{
struct V_94 * V_26 = V_723 -> V_26 ;
struct V_752 * V_168 = NULL ;
struct V_170 V_171 ;
int V_92 ;
void * V_78 = V_26 -> V_199 . V_172 ;
int V_753 = 0 ;
unsigned int V_169 = F_93 ( V_26 ) ;
int F_153 = V_169 ;
bool V_754 = false ;
struct V_29 * V_30 ;
int V_99 , V_755 , V_214 ;
V_37 -> V_756 = V_757 ;
V_37 -> V_758 = 2 ;
while ( F_110 ( V_723 ) == V_677 ) {
F_317 ( V_723 ) ;
F_27 () ;
V_30 = F_28 ( V_26 -> V_29 ) ;
V_99 = V_30 -> V_99 ;
V_755 = V_30 -> V_755 ;
V_214 = V_30 -> V_214 ;
F_29 () ;
if ( F_266 ( V_759 , & V_26 -> V_63 ) ) {
if ( F_364 ( V_26 ) ) {
F_65 ( V_26 , L_187 ) ;
goto V_569;
}
V_26 -> V_199 . V_76 -> V_111 -> V_137 = V_99 * V_100 / 10 ;
V_754 = true ;
}
if ( V_755 )
F_365 ( V_26 -> V_199 . V_76 ) ;
if ( F_362 ( V_26 ) ) {
F_65 ( V_26 , L_188 ) ;
goto V_569;
}
if ( V_755 )
F_366 ( V_26 -> V_199 . V_76 ) ;
if ( F_32 ( V_37 ) )
continue;
V_92 = F_59 ( V_26 -> V_199 . V_76 , V_78 , F_153 - V_753 , 0 ) ;
F_101 ( V_751 , & V_26 -> V_63 ) ;
F_108 ( V_37 ) ;
if ( F_164 ( V_92 > 0 ) ) {
V_753 += V_92 ;
V_78 += V_92 ;
} else if ( V_92 == 0 ) {
if ( F_66 ( V_98 , & V_26 -> V_63 ) ) {
long V_25 ;
F_27 () ;
V_25 = F_28 ( V_26 -> V_29 ) -> V_99 * V_100 / 10 ;
F_29 () ;
V_25 = F_67 ( V_26 -> V_101 ,
V_26 -> V_102 < V_103 ,
V_25 ) ;
if ( V_25 )
break;
}
F_65 ( V_26 , L_189 ) ;
goto V_569;
} else if ( V_92 == - V_143 ) {
if ( F_367 ( V_26 -> V_215 ,
V_186 - V_26 -> V_199 . V_76 -> V_111 -> V_137 ) )
continue;
if ( V_754 ) {
F_65 ( V_26 , L_190 ) ;
goto V_569;
}
F_107 ( V_759 , & V_26 -> V_63 ) ;
continue;
} else if ( V_92 == - V_145 ) {
continue;
} else {
F_65 ( V_26 , L_7 , V_92 ) ;
goto V_569;
}
if ( V_753 == F_153 && V_168 == NULL ) {
if ( F_94 ( V_26 , V_26 -> V_199 . V_172 , & V_171 ) )
goto V_569;
V_168 = & V_760 [ V_171 . V_168 ] ;
if ( V_171 . V_168 >= F_318 ( V_760 ) || ! V_168 -> V_681 ) {
F_65 ( V_26 , L_191 ,
F_253 ( V_171 . V_168 ) , V_171 . V_168 ) ;
goto V_548;
}
F_153 = V_169 + V_168 -> V_682 ;
if ( V_171 . V_58 != F_153 - V_169 ) {
F_65 ( V_26 , L_192 ,
V_171 . V_168 , V_171 . V_58 ) ;
goto V_569;
}
}
if ( V_753 == F_153 ) {
bool V_70 ;
V_70 = V_168 -> V_681 ( V_26 , & V_171 ) ;
if ( V_70 ) {
F_65 ( V_26 , L_193 , V_168 -> V_681 ) ;
goto V_569;
}
V_26 -> V_215 = V_186 ;
if ( V_168 == & V_760 [ V_761 ] ) {
V_26 -> V_199 . V_76 -> V_111 -> V_137 = V_214 * V_100 ;
V_754 = false ;
}
V_78 = V_26 -> V_199 . V_172 ;
V_753 = 0 ;
F_153 = V_169 ;
V_168 = NULL ;
}
}
if ( 0 ) {
V_569:
F_68 ( V_26 , F_69 ( V_105 , V_691 ) , V_107 ) ;
F_368 ( V_26 ) ;
}
if ( 0 ) {
V_548:
F_68 ( V_26 , F_69 ( V_105 , V_150 ) , V_107 ) ;
}
F_101 ( V_751 , & V_26 -> V_63 ) ;
F_64 ( V_26 , L_194 ) ;
return 0 ;
}
