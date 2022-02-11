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
F_45 ( & V_10 -> V_185 , 0 ) ;
F_102 ( & V_10 -> V_186 , V_187 + V_100 ) ;
return V_70 ;
}
static int F_103 ( struct V_94 * V_26 )
{
struct V_166 V_77 , V_188 ;
struct V_9 * V_10 ;
struct V_29 * V_30 ;
int V_189 , V_190 , V_191 , V_192 ;
bool V_193 ;
enum V_194 V_92 ;
struct V_151 V_152 = {
. V_26 = V_26 ,
. V_157 = F_104 ( V_152 . V_157 ) ,
} ;
F_101 ( V_98 , & V_26 -> V_63 ) ;
if ( F_68 ( V_26 , F_69 ( V_105 , V_195 ) , V_196 ) < V_197 )
return - 2 ;
F_105 ( & V_77 . V_198 ) ;
V_77 . V_199 = V_26 -> V_95 . V_199 ;
V_77 . V_172 = V_26 -> V_95 . V_172 ;
V_77 . V_76 = NULL ;
F_105 ( & V_188 . V_198 ) ;
V_188 . V_199 = V_26 -> V_200 . V_199 ;
V_188 . V_172 = V_26 -> V_200 . V_172 ;
V_188 . V_76 = NULL ;
V_26 -> V_180 = 80 ;
if ( F_81 ( V_26 , & V_152 ) )
return 0 ;
do {
struct V_76 * V_201 ;
V_201 = F_74 ( V_26 ) ;
if ( V_201 ) {
if ( ! V_77 . V_76 ) {
V_77 . V_76 = V_201 ;
F_89 ( V_26 , & V_77 , V_202 ) ;
} else if ( ! V_188 . V_76 ) {
F_101 ( V_203 , & V_26 -> V_63 ) ;
V_188 . V_76 = V_201 ;
F_89 ( V_26 , & V_188 , V_204 ) ;
} else {
F_65 ( V_26 , L_17 ) ;
goto V_205;
}
}
if ( V_77 . V_76 && V_188 . V_76 ) {
F_27 () ;
V_30 = F_28 ( V_26 -> V_29 ) ;
V_190 = V_30 -> V_99 * V_100 / 10 ;
F_29 () ;
F_106 ( V_190 ) ;
V_192 = F_95 ( & V_77 . V_76 ) ;
V_192 = F_95 ( & V_188 . V_76 ) && V_192 ;
if ( V_192 )
break;
}
V_28:
V_201 = F_85 ( V_26 , & V_152 ) ;
if ( V_201 ) {
int V_206 = F_92 ( V_26 , V_201 ) ;
F_95 ( & V_77 . V_76 ) ;
F_95 ( & V_188 . V_76 ) ;
switch ( V_206 ) {
case V_202 :
if ( V_77 . V_76 ) {
F_72 ( V_26 , L_18 ) ;
F_77 ( V_77 . V_76 ) ;
V_77 . V_76 = V_201 ;
goto V_207;
}
V_77 . V_76 = V_201 ;
break;
case V_204 :
F_107 ( V_203 , & V_26 -> V_63 ) ;
if ( V_188 . V_76 ) {
F_72 ( V_26 , L_19 ) ;
F_77 ( V_188 . V_76 ) ;
V_188 . V_76 = V_201 ;
goto V_207;
}
V_188 . V_76 = V_201 ;
break;
default:
F_72 ( V_26 , L_20 ) ;
F_77 ( V_201 ) ;
V_207:
if ( F_86 () & 1 )
goto V_28;
}
}
if ( V_26 -> V_102 <= V_150 )
goto V_205;
if ( F_32 ( V_37 ) ) {
F_108 ( V_37 ) ;
F_109 () ;
if ( F_110 ( & V_26 -> V_208 ) == V_209 )
goto V_205;
}
V_192 = F_95 ( & V_77 . V_76 ) ;
V_192 = F_95 ( & V_188 . V_76 ) && V_192 ;
} while ( ! V_192 );
if ( V_152 . V_158 )
F_77 ( V_152 . V_158 ) ;
V_77 . V_76 -> V_111 -> V_159 = V_160 ;
V_188 . V_76 -> V_111 -> V_159 = V_160 ;
V_77 . V_76 -> V_111 -> V_210 = V_211 ;
V_188 . V_76 -> V_111 -> V_210 = V_211 ;
V_77 . V_76 -> V_111 -> V_212 = V_213 ;
V_188 . V_76 -> V_111 -> V_212 = V_214 ;
F_27 () ;
V_30 = F_28 ( V_26 -> V_29 ) ;
V_77 . V_76 -> V_111 -> V_138 =
V_77 . V_76 -> V_111 -> V_137 = V_30 -> V_99 * 4 * V_100 / 10 ;
V_188 . V_76 -> V_111 -> V_137 = V_30 -> V_215 * V_100 ;
V_190 = V_30 -> V_190 * V_100 / 10 ;
V_193 = V_30 -> V_193 ;
F_29 () ;
V_188 . V_76 -> V_111 -> V_138 = V_190 ;
F_111 ( V_77 . V_76 ) ;
F_111 ( V_188 . V_76 ) ;
V_26 -> V_95 . V_76 = V_77 . V_76 ;
V_26 -> V_200 . V_76 = V_188 . V_76 ;
V_26 -> V_216 = V_187 ;
V_191 = F_112 ( V_26 ) ;
if ( V_191 <= 0 )
return V_191 ;
if ( V_26 -> V_217 ) {
switch ( F_113 ( V_26 ) ) {
case - 1 :
F_65 ( V_26 , L_21 ) ;
return - 1 ;
case 0 :
F_65 ( V_26 , L_22 ) ;
return 0 ;
}
}
V_26 -> V_95 . V_76 -> V_111 -> V_138 = V_190 ;
V_26 -> V_95 . V_76 -> V_111 -> V_137 = V_218 ;
if ( F_114 ( V_26 ) == - V_219 )
return - 1 ;
F_107 ( V_220 , & V_26 -> V_63 ) ;
F_27 () ;
F_115 (&tconn->volumes, mdev, vnr) {
F_116 ( & V_10 -> V_221 ) ;
F_117 ( V_10 -> V_179 ) ;
F_118 ( V_10 -> V_179 ) ;
F_29 () ;
if ( V_193 )
F_107 ( V_222 , & V_10 -> V_63 ) ;
else
F_101 ( V_222 , & V_10 -> V_63 ) ;
F_96 ( V_10 ) ;
F_119 ( & V_10 -> V_221 , & V_223 ) ;
F_27 () ;
}
F_29 () ;
V_92 = F_68 ( V_26 , F_69 ( V_105 , V_103 ) , V_196 ) ;
if ( V_92 < V_197 || V_26 -> V_102 != V_103 ) {
F_101 ( V_220 , & V_26 -> V_63 ) ;
return 0 ;
}
F_120 ( & V_26 -> V_224 ) ;
F_117 ( & V_26 -> V_225 ) ;
V_26 -> V_29 -> V_193 = 0 ;
F_118 ( & V_26 -> V_225 ) ;
return V_191 ;
V_205:
if ( V_152 . V_158 )
F_77 ( V_152 . V_158 ) ;
if ( V_77 . V_76 )
F_77 ( V_77 . V_76 ) ;
if ( V_188 . V_76 )
F_77 ( V_188 . V_76 ) ;
return - 1 ;
}
static int F_94 ( struct V_94 * V_26 , void * V_226 , struct V_170 * V_171 )
{
unsigned int V_169 = F_93 ( V_26 ) ;
if ( V_169 == sizeof( struct V_227 ) &&
* ( V_228 * ) V_226 == F_121 ( V_229 ) ) {
struct V_227 * V_191 = V_226 ;
if ( V_191 -> V_230 != 0 ) {
F_65 ( V_26 , L_23 ) ;
return - V_231 ;
}
V_171 -> V_189 = F_122 ( V_191 -> V_232 ) ;
V_171 -> V_168 = F_122 ( V_191 -> V_233 ) ;
V_171 -> V_58 = F_123 ( V_191 -> V_234 ) ;
} else if ( V_169 == sizeof( struct V_235 ) &&
* ( V_236 * ) V_226 == F_124 ( V_237 ) ) {
struct V_235 * V_191 = V_226 ;
V_171 -> V_168 = F_122 ( V_191 -> V_233 ) ;
V_171 -> V_58 = F_123 ( V_191 -> V_234 ) ;
V_171 -> V_189 = 0 ;
} else if ( V_169 == sizeof( struct V_238 ) &&
* ( V_228 * ) V_226 == F_121 ( V_239 ) ) {
struct V_238 * V_191 = V_226 ;
V_171 -> V_168 = F_122 ( V_191 -> V_233 ) ;
V_171 -> V_58 = F_122 ( V_191 -> V_234 ) ;
V_171 -> V_189 = 0 ;
} else {
F_65 ( V_26 , L_24 ,
F_123 ( * ( V_228 * ) V_226 ) ,
V_26 -> V_180 ) ;
return - V_231 ;
}
V_171 -> V_95 = V_226 + V_169 ;
return 0 ;
}
static int F_125 ( struct V_94 * V_26 , struct V_170 * V_171 )
{
void * V_240 = V_26 -> V_95 . V_172 ;
int V_70 ;
V_70 = F_71 ( V_26 , V_240 , F_93 ( V_26 ) ) ;
if ( V_70 )
return V_70 ;
V_70 = F_94 ( V_26 , V_240 , V_171 ) ;
V_26 -> V_216 = V_187 ;
return V_70 ;
}
static void F_126 ( struct V_94 * V_26 )
{
int V_92 ;
struct V_9 * V_10 ;
int V_189 ;
if ( V_26 -> V_241 >= V_242 ) {
F_27 () ;
F_115 (&tconn->volumes, mdev, vnr) {
if ( ! F_127 ( V_10 ) )
continue;
F_116 ( & V_10 -> V_221 ) ;
F_29 () ;
V_92 = F_128 ( V_10 -> V_243 -> V_244 ,
V_211 , NULL ) ;
if ( V_92 ) {
F_129 ( V_38 , L_25 , V_92 ) ;
F_130 ( V_26 , V_245 ) ;
}
F_131 ( V_10 ) ;
F_119 ( & V_10 -> V_221 , & V_223 ) ;
F_27 () ;
if ( V_92 )
break;
}
F_29 () ;
}
}
static enum V_246 F_132 ( struct V_94 * V_26 ,
struct V_247 * V_60 ,
enum V_248 V_249 )
{
int V_250 ;
struct V_247 * V_251 ;
enum V_246 V_92 = V_252 ;
F_11 ( & V_26 -> V_253 ) ;
do {
V_251 = NULL ;
V_250 = F_30 ( & V_60 -> V_250 ) ;
switch ( V_249 & ~ V_254 ) {
case V_255 :
F_133 ( & V_60 -> V_256 ) ;
break;
case V_257 :
F_107 ( V_258 , & V_60 -> V_63 ) ;
break;
case V_259 :
break;
}
if ( V_250 != 0 &&
F_30 ( & V_60 -> V_256 ) == 0 &&
( F_66 ( V_258 , & V_60 -> V_63 ) || V_249 & V_254 ) ) {
if ( ! ( V_249 & V_254 ) ) {
F_12 ( & V_26 -> V_253 ) ;
F_134 ( V_60 -> V_26 , V_60 -> V_260 , V_250 ) ;
F_11 ( & V_26 -> V_253 ) ;
}
#if 0
if (test_bit(DE_HAVE_BARRIER_NUMBER, &epoch->flags))
dec_unacked(epoch->tconn);
#endif
if ( V_26 -> V_261 != V_60 ) {
V_251 = F_16 ( V_60 -> V_23 . V_262 , struct V_247 , V_23 ) ;
F_135 ( & V_60 -> V_23 ) ;
V_249 = V_259 | ( V_249 & V_254 ) ;
V_26 -> V_263 -- ;
F_48 ( V_60 ) ;
if ( V_92 == V_252 )
V_92 = V_264 ;
} else {
V_60 -> V_63 = 0 ;
F_45 ( & V_60 -> V_250 , 0 ) ;
if ( V_92 == V_252 )
V_92 = V_265 ;
}
}
if ( ! V_251 )
break;
V_60 = V_251 ;
} while ( 1 );
F_12 ( & V_26 -> V_253 ) ;
return V_92 ;
}
void F_130 ( struct V_94 * V_26 , enum V_266 V_267 )
{
struct V_268 * V_269 ;
struct V_9 * V_10 ;
enum V_266 V_270 ;
int V_189 ;
static char * V_271 [] = {
[ V_272 ] = L_26 ,
[ V_245 ] = L_27 ,
[ V_242 ] = L_28 ,
} ;
V_270 = V_26 -> V_241 ;
V_267 = F_136 ( V_270 , V_267 ) ;
F_27 () ;
F_115 (&tconn->volumes, mdev, vnr) {
if ( ! F_137 ( V_10 , V_273 ) )
continue;
V_269 = F_28 ( V_10 -> V_243 -> V_268 ) ;
if ( V_267 == V_242 && ! V_269 -> V_274 )
V_267 = V_245 ;
if ( V_267 == V_245 && ! V_269 -> V_275 )
V_267 = V_272 ;
F_131 ( V_10 ) ;
}
F_29 () ;
V_26 -> V_241 = V_267 ;
if ( V_270 != V_26 -> V_241 || V_267 == V_242 )
F_64 ( V_26 , L_29 , V_271 [ V_26 -> V_241 ] ) ;
}
int F_138 ( struct V_9 * V_10 ,
struct V_18 * V_19 ,
const unsigned V_276 , const int V_277 )
{
struct V_278 * V_279 = NULL ;
struct V_278 * V_278 ;
struct V_1 * V_1 = V_19 -> V_61 ;
T_3 V_46 = V_19 -> V_6 . V_46 ;
unsigned V_280 = V_19 -> V_6 . V_58 ;
unsigned V_281 = 0 ;
unsigned V_49 = ( V_280 + V_43 - 1 ) >> V_50 ;
int V_70 = - V_282 ;
V_283:
V_278 = F_139 ( V_211 , V_49 ) ;
if ( ! V_278 ) {
F_43 ( V_38 , L_30 ) ;
goto V_57;
}
V_278 -> V_284 = V_46 ;
V_278 -> V_285 = V_10 -> V_243 -> V_244 ;
V_278 -> V_286 = V_276 ;
V_278 -> V_287 = V_19 ;
V_278 -> V_288 = V_289 ;
V_278 -> V_290 = V_279 ;
V_279 = V_278 ;
++ V_281 ;
F_140 (page) {
unsigned V_5 = F_75 ( unsigned , V_280 , V_43 ) ;
if ( ! F_141 ( V_278 , V_1 , V_5 , 0 ) ) {
if ( V_278 -> V_291 == 0 ) {
F_43 ( V_38 ,
L_31
L_32 ,
V_5 , ( unsigned long long ) V_278 -> V_284 ) ;
V_70 = - V_292 ;
goto V_57;
}
goto V_283;
}
V_280 -= V_5 ;
V_46 += V_5 >> 9 ;
-- V_49 ;
}
F_49 ( V_1 == NULL ) ;
F_49 ( V_280 == 0 ) ;
F_45 ( & V_19 -> V_62 , V_281 ) ;
do {
V_278 = V_279 ;
V_279 = V_279 -> V_290 ;
V_278 -> V_290 = NULL ;
F_142 ( V_10 , V_277 , V_278 ) ;
} while ( V_279 );
return 0 ;
V_57:
while ( V_279 ) {
V_278 = V_279 ;
V_279 = V_279 -> V_290 ;
F_143 ( V_278 ) ;
}
return V_70 ;
}
static void F_144 ( struct V_9 * V_10 ,
struct V_18 * V_19 )
{
struct V_293 * V_6 = & V_19 -> V_6 ;
F_145 ( & V_10 -> V_294 , V_6 ) ;
F_44 ( V_6 ) ;
if ( V_6 -> V_59 )
F_39 ( & V_10 -> V_295 ) ;
}
void F_146 ( struct V_94 * V_26 )
{
struct V_9 * V_10 ;
int V_189 ;
F_27 () ;
F_115 (&tconn->volumes, mdev, vnr) {
F_116 ( & V_10 -> V_221 ) ;
F_29 () ;
F_58 ( V_10 , & V_10 -> V_296 ) ;
F_119 ( & V_10 -> V_221 , & V_223 ) ;
F_27 () ;
}
F_29 () ;
}
static int F_147 ( struct V_94 * V_26 , struct V_170 * V_171 )
{
int V_92 ;
struct V_297 * V_298 = V_171 -> V_95 ;
struct V_247 * V_60 ;
V_26 -> V_261 -> V_260 = V_298 -> V_299 ;
V_26 -> V_261 -> V_26 = V_26 ;
V_92 = F_132 ( V_26 , V_26 -> V_261 , V_257 ) ;
switch ( V_26 -> V_241 ) {
case V_272 :
if ( V_92 == V_265 )
return 0 ;
V_60 = F_148 ( sizeof( struct V_247 ) , V_211 ) ;
if ( V_60 )
break;
else
F_72 ( V_26 , L_33 ) ;
case V_242 :
case V_245 :
F_146 ( V_26 ) ;
F_126 ( V_26 ) ;
if ( F_30 ( & V_26 -> V_261 -> V_250 ) ) {
V_60 = F_148 ( sizeof( struct V_247 ) , V_211 ) ;
if ( V_60 )
break;
}
return 0 ;
default:
F_65 ( V_26 , L_34 , V_26 -> V_241 ) ;
return - V_108 ;
}
V_60 -> V_63 = 0 ;
F_45 ( & V_60 -> V_250 , 0 ) ;
F_45 ( & V_60 -> V_256 , 0 ) ;
F_11 ( & V_26 -> V_253 ) ;
if ( F_30 ( & V_26 -> V_261 -> V_250 ) ) {
F_149 ( & V_60 -> V_23 , & V_26 -> V_261 -> V_23 ) ;
V_26 -> V_261 = V_60 ;
V_26 -> V_263 ++ ;
} else {
F_48 ( V_60 ) ;
}
F_12 ( & V_26 -> V_253 ) ;
return 0 ;
}
static struct V_18 *
F_150 ( struct V_9 * V_10 , T_2 V_45 , T_3 V_46 ,
int V_47 ) __must_hold( T_5 )
{
const T_3 V_300 = F_151 ( V_10 -> V_301 ) ;
struct V_18 * V_19 ;
struct V_1 * V_1 ;
int V_302 , V_280 , V_70 ;
void * V_303 = V_10 -> V_26 -> V_304 ;
void * V_305 = V_10 -> V_26 -> V_306 ;
unsigned long * V_95 ;
V_302 = 0 ;
if ( V_10 -> V_26 -> V_307 ) {
V_302 = F_152 ( V_10 -> V_26 -> V_307 ) ;
V_70 = F_71 ( V_10 -> V_26 , V_303 , V_302 ) ;
if ( V_70 )
return NULL ;
V_47 -= V_302 ;
}
if ( ! F_153 ( F_154 ( V_47 , 512 ) ) )
return NULL ;
if ( ! F_153 ( V_47 <= V_42 ) )
return NULL ;
if ( V_46 + ( V_47 >> 9 ) > V_300 ) {
F_43 ( V_38 , L_35
L_36 ,
( unsigned long long ) V_300 ,
( unsigned long long ) V_46 , V_47 ) ;
return NULL ;
}
V_19 = F_40 ( V_10 , V_45 , V_46 , V_47 , V_211 ) ;
if ( ! V_19 )
return NULL ;
if ( ! V_47 )
return V_19 ;
V_280 = V_47 ;
V_1 = V_19 -> V_61 ;
F_140 (page) {
unsigned V_5 = F_75 ( int , V_280 , V_43 ) ;
V_95 = F_155 ( V_1 ) ;
V_70 = F_71 ( V_10 -> V_26 , V_95 , V_5 ) ;
if ( F_41 ( V_10 , V_308 ) ) {
F_43 ( V_38 , L_37 ) ;
V_95 [ 0 ] = V_95 [ 0 ] ^ ( unsigned long ) - 1 ;
}
F_156 ( V_1 ) ;
if ( V_70 ) {
F_54 ( V_10 , V_19 ) ;
return NULL ;
}
V_280 -= V_5 ;
}
if ( V_302 ) {
F_157 ( V_10 , V_10 -> V_26 -> V_307 , V_19 , V_305 ) ;
if ( memcmp ( V_303 , V_305 , V_302 ) ) {
F_43 ( V_38 , L_38 ,
( unsigned long long ) V_46 , V_47 ) ;
F_54 ( V_10 , V_19 ) ;
return NULL ;
}
}
V_10 -> V_309 += V_47 >> 9 ;
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
static int F_159 ( struct V_9 * V_10 , struct V_310 * V_311 ,
T_3 V_46 , int V_47 )
{
struct V_312 * V_313 ;
struct V_278 * V_278 ;
int V_302 , V_70 , V_6 , F_153 ;
void * V_303 = V_10 -> V_26 -> V_304 ;
void * V_305 = V_10 -> V_26 -> V_306 ;
V_302 = 0 ;
if ( V_10 -> V_26 -> V_307 ) {
V_302 = F_152 ( V_10 -> V_26 -> V_307 ) ;
V_70 = F_71 ( V_10 -> V_26 , V_303 , V_302 ) ;
if ( V_70 )
return V_70 ;
V_47 -= V_302 ;
}
V_10 -> V_309 += V_47 >> 9 ;
V_278 = V_311 -> V_314 ;
F_49 ( V_46 == V_278 -> V_284 ) ;
F_160 (bvec, bio, i) {
void * V_315 = F_155 ( V_313 -> V_316 ) + V_313 -> V_317 ;
F_153 = F_75 ( int , V_47 , V_313 -> V_318 ) ;
V_70 = F_71 ( V_10 -> V_26 , V_315 , F_153 ) ;
F_156 ( V_313 -> V_316 ) ;
if ( V_70 )
return V_70 ;
V_47 -= F_153 ;
}
if ( V_302 ) {
F_161 ( V_10 , V_10 -> V_26 -> V_307 , V_278 , V_305 ) ;
if ( memcmp ( V_303 , V_305 , V_302 ) ) {
F_43 ( V_38 , L_39 ) ;
return - V_231 ;
}
}
F_49 ( V_47 == 0 ) ;
return 0 ;
}
static int F_162 ( struct V_319 * V_22 , int V_320 )
{
struct V_18 * V_19 =
F_163 ( V_22 , struct V_18 , V_22 ) ;
struct V_9 * V_10 = V_22 -> V_10 ;
T_3 V_46 = V_19 -> V_6 . V_46 ;
int V_70 ;
F_49 ( F_50 ( & V_19 -> V_6 ) ) ;
if ( F_164 ( ( V_19 -> V_63 & V_321 ) == 0 ) ) {
F_165 ( V_10 , V_46 , V_19 -> V_6 . V_58 ) ;
V_70 = F_166 ( V_10 , V_322 , V_19 ) ;
} else {
F_167 ( V_10 , V_46 , V_19 -> V_6 . V_58 ) ;
V_70 = F_166 ( V_10 , V_323 , V_19 ) ;
}
F_168 ( V_10 ) ;
return V_70 ;
}
static int F_169 ( struct V_9 * V_10 , T_3 V_46 , int V_47 ) __releases( T_5 )
{
struct V_18 * V_19 ;
V_19 = F_150 ( V_10 , V_324 , V_46 , V_47 ) ;
if ( ! V_19 )
goto V_57;
F_170 ( V_10 ) ;
F_171 ( V_10 ) ;
V_19 -> V_22 . V_73 = F_162 ;
F_21 ( & V_10 -> V_26 -> V_27 ) ;
F_149 ( & V_19 -> V_22 . V_23 , & V_10 -> V_325 ) ;
F_22 ( & V_10 -> V_26 -> V_27 ) ;
F_36 ( V_47 >> 9 , & V_10 -> V_326 ) ;
if ( F_138 ( V_10 , V_19 , V_327 , V_328 ) == 0 )
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
static struct V_310 *
F_172 ( struct V_9 * V_10 , struct V_329 * V_330 , T_2 V_45 ,
T_3 V_46 , bool V_331 , const char * V_332 )
{
struct V_310 * V_311 ;
V_311 = (struct V_310 * ) ( unsigned long ) V_45 ;
if ( F_173 ( V_330 , V_46 , & V_311 -> V_6 ) && V_311 -> V_6 . T_5 )
return V_311 ;
if ( ! V_331 ) {
F_43 ( V_38 , L_41 , V_332 ,
( unsigned long ) V_45 , ( unsigned long long ) V_46 ) ;
}
return NULL ;
}
static int F_174 ( struct V_94 * V_26 , struct V_170 * V_171 )
{
struct V_9 * V_10 ;
struct V_310 * V_311 ;
T_3 V_46 ;
int V_70 ;
struct V_333 * V_298 = V_171 -> V_95 ;
V_10 = F_175 ( V_26 , V_171 -> V_189 ) ;
if ( ! V_10 )
return - V_108 ;
V_46 = F_176 ( V_298 -> V_46 ) ;
F_21 ( & V_10 -> V_26 -> V_27 ) ;
V_311 = F_172 ( V_10 , & V_10 -> V_334 , V_298 -> V_64 , V_46 , false , V_55 ) ;
F_22 ( & V_10 -> V_26 -> V_27 ) ;
if ( F_177 ( ! V_311 ) )
return - V_108 ;
V_70 = F_159 ( V_10 , V_311 , V_46 , V_171 -> V_58 ) ;
if ( ! V_70 )
F_178 ( V_311 , V_335 ) ;
return V_70 ;
}
static int F_179 ( struct V_94 * V_26 , struct V_170 * V_171 )
{
struct V_9 * V_10 ;
T_3 V_46 ;
int V_70 ;
struct V_333 * V_298 = V_171 -> V_95 ;
V_10 = F_175 ( V_26 , V_171 -> V_189 ) ;
if ( ! V_10 )
return - V_108 ;
V_46 = F_176 ( V_298 -> V_46 ) ;
F_49 ( V_298 -> V_64 == V_324 ) ;
if ( F_127 ( V_10 ) ) {
V_70 = F_169 ( V_10 , V_46 , V_171 -> V_58 ) ;
} else {
if ( F_180 ( & V_336 ) )
F_43 ( V_38 , L_42 ) ;
V_70 = F_158 ( V_10 , V_171 -> V_58 ) ;
F_181 ( V_10 , V_323 , V_298 , V_171 -> V_58 ) ;
}
F_36 ( V_171 -> V_58 >> 9 , & V_10 -> V_337 ) ;
return V_70 ;
}
static void F_182 ( struct V_9 * V_10 ,
T_3 V_46 , int V_58 )
{
struct V_293 * V_6 ;
struct V_310 * V_311 ;
F_183 (i, &mdev->write_requests, sector, size) {
if ( ! V_6 -> T_5 )
continue;
V_311 = F_163 ( V_6 , struct V_310 , V_6 ) ;
if ( V_311 -> V_338 & V_339 ||
! ( V_311 -> V_338 & V_340 ) )
continue;
F_184 ( V_311 , V_341 , NULL ) ;
}
}
static int F_185 ( struct V_319 * V_22 , int V_342 )
{
struct V_18 * V_19 =
F_163 ( V_22 , struct V_18 , V_22 ) ;
struct V_9 * V_10 = V_22 -> V_10 ;
T_3 V_46 = V_19 -> V_6 . V_46 ;
int V_70 = 0 , V_343 ;
if ( V_19 -> V_63 & V_344 ) {
if ( F_164 ( ( V_19 -> V_63 & V_321 ) == 0 ) ) {
V_343 = ( V_10 -> V_345 . V_105 >= V_346 &&
V_10 -> V_345 . V_105 <= V_347 &&
V_19 -> V_63 & V_348 ) ?
V_322 : V_349 ;
V_70 = F_166 ( V_10 , V_343 , V_19 ) ;
if ( V_343 == V_322 )
F_165 ( V_10 , V_46 , V_19 -> V_6 . V_58 ) ;
} else {
V_70 = F_166 ( V_10 , V_323 , V_19 ) ;
}
F_168 ( V_10 ) ;
}
if ( V_19 -> V_63 & V_350 ) {
F_21 ( & V_10 -> V_26 -> V_27 ) ;
F_49 ( ! F_50 ( & V_19 -> V_6 ) ) ;
F_144 ( V_10 , V_19 ) ;
if ( V_19 -> V_63 & V_351 )
F_182 ( V_10 , V_46 , V_19 -> V_6 . V_58 ) ;
F_22 ( & V_10 -> V_26 -> V_27 ) ;
} else
F_49 ( F_50 ( & V_19 -> V_6 ) ) ;
F_132 ( V_10 -> V_26 , V_19 -> V_60 , V_255 + ( V_342 ? V_254 : 0 ) ) ;
return V_70 ;
}
static int F_186 ( struct V_319 * V_22 , enum V_167 V_352 )
{
struct V_9 * V_10 = V_22 -> V_10 ;
struct V_18 * V_19 =
F_163 ( V_22 , struct V_18 , V_22 ) ;
int V_70 ;
V_70 = F_166 ( V_10 , V_352 , V_19 ) ;
F_168 ( V_10 ) ;
return V_70 ;
}
static int F_187 ( struct V_319 * V_22 , int V_320 )
{
return F_186 ( V_22 , V_353 ) ;
}
static int F_188 ( struct V_319 * V_22 , int V_320 )
{
struct V_94 * V_26 = V_22 -> V_10 -> V_26 ;
return F_186 ( V_22 , V_26 -> V_180 >= 100 ?
V_354 : V_353 ) ;
}
static bool F_189 ( T_8 V_40 , T_8 V_355 )
{
return ( V_356 ) V_40 - ( V_356 ) V_355 > 0 ;
}
static T_8 F_190 ( T_8 V_40 , T_8 V_355 )
{
return F_189 ( V_40 , V_355 ) ? V_40 : V_355 ;
}
static bool F_191 ( struct V_9 * V_10 )
{
struct V_94 * V_26 = V_10 -> V_26 ;
int V_357 ;
F_27 () ;
V_357 = F_28 ( V_10 -> V_26 -> V_29 ) -> V_358 ;
F_29 () ;
return V_357 && F_66 ( V_203 , & V_26 -> V_63 ) ;
}
static void F_192 ( struct V_9 * V_10 , unsigned int V_178 )
{
unsigned int V_359 ;
if ( F_191 ( V_10 ) ) {
F_11 ( & V_10 -> V_360 ) ;
V_359 = F_190 ( V_10 -> V_178 , V_178 ) ;
V_10 -> V_178 = V_359 ;
F_12 ( & V_10 -> V_360 ) ;
if ( V_178 == V_359 )
F_39 ( & V_10 -> V_361 ) ;
}
}
static inline int F_193 ( T_3 V_362 , int V_363 , T_3 V_364 , int V_365 )
{
return ! ( ( V_362 + ( V_363 >> 9 ) <= V_364 ) || ( V_362 >= V_364 + ( V_365 >> 9 ) ) ) ;
}
static bool F_194 ( struct V_9 * V_10 , struct V_18 * V_19 )
{
struct V_18 * V_366 ;
bool V_92 = 0 ;
F_21 ( & V_10 -> V_26 -> V_27 ) ;
F_195 (rs_req, &mdev->sync_ee, w.list) {
if ( F_193 ( V_19 -> V_6 . V_46 , V_19 -> V_6 . V_58 ,
V_366 -> V_6 . V_46 , V_366 -> V_6 . V_58 ) ) {
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
long V_190 ;
int V_367 ;
if ( ! F_191 ( V_10 ) )
return 0 ;
F_11 ( & V_10 -> V_360 ) ;
for (; ; ) {
if ( ! F_189 ( V_178 - 1 , V_10 -> V_178 ) ) {
V_10 -> V_178 = F_190 ( V_10 -> V_178 , V_178 ) ;
V_367 = 0 ;
break;
}
if ( F_32 ( V_37 ) ) {
V_367 = - V_97 ;
break;
}
F_31 ( & V_10 -> V_361 , & V_31 , V_36 ) ;
F_12 ( & V_10 -> V_360 ) ;
F_27 () ;
V_190 = F_28 ( V_10 -> V_26 -> V_29 ) -> V_99 * V_100 / 10 ;
F_29 () ;
V_190 = F_197 ( V_190 ) ;
F_11 ( & V_10 -> V_360 ) ;
if ( ! V_190 ) {
V_367 = - V_142 ;
F_43 ( V_38 , L_43 ) ;
break;
}
}
F_12 ( & V_10 -> V_360 ) ;
F_35 ( & V_10 -> V_361 , & V_31 ) ;
return V_367 ;
}
static unsigned long F_198 ( struct V_9 * V_10 , T_8 V_368 )
{
return ( V_368 & V_369 ? V_370 : 0 ) |
( V_368 & V_371 ? V_372 : 0 ) |
( V_368 & V_373 ? V_374 : 0 ) |
( V_368 & V_375 ? V_376 : 0 ) ;
}
static void F_199 ( struct V_9 * V_10 , T_3 V_46 ,
unsigned int V_58 )
{
struct V_293 * V_6 ;
V_377:
F_183 (i, &mdev->write_requests, sector, size) {
struct V_310 * V_311 ;
struct V_378 V_379 ;
if ( ! V_6 -> T_5 )
continue;
V_311 = F_163 ( V_6 , struct V_310 , V_6 ) ;
if ( ! ( V_311 -> V_338 & V_340 ) )
continue;
V_311 -> V_338 &= ~ V_340 ;
F_184 ( V_311 , V_380 , & V_379 ) ;
F_22 ( & V_10 -> V_26 -> V_27 ) ;
if ( V_379 . V_278 )
F_200 ( V_10 , & V_379 ) ;
F_21 ( & V_10 -> V_26 -> V_27 ) ;
goto V_377;
}
}
static int F_201 ( struct V_9 * V_10 ,
struct V_18 * V_19 )
{
struct V_94 * V_26 = V_10 -> V_26 ;
bool V_381 = F_66 ( V_203 , & V_26 -> V_63 ) ;
T_3 V_46 = V_19 -> V_6 . V_46 ;
const unsigned int V_58 = V_19 -> V_6 . V_58 ;
struct V_293 * V_6 ;
bool V_382 ;
int V_70 ;
F_202 ( & V_10 -> V_294 , & V_19 -> V_6 ) ;
V_377:
F_183 (i, &mdev->write_requests, sector, size) {
if ( V_6 == & V_19 -> V_6 )
continue;
if ( ! V_6 -> T_5 ) {
V_70 = F_203 ( V_10 , V_6 ) ;
if ( V_70 )
goto V_104;
goto V_377;
}
V_382 = V_6 -> V_46 == V_46 && V_6 -> V_58 == V_58 ;
if ( V_381 ) {
bool V_383 = V_6 -> V_46 <= V_46 && V_6 -> V_46 +
( V_6 -> V_58 >> 9 ) >= V_46 + ( V_58 >> 9 ) ;
if ( ! V_382 )
F_204 ( V_38 , L_44
L_45
L_46 ,
( unsigned long long ) V_6 -> V_46 , V_6 -> V_58 ,
( unsigned long long ) V_46 , V_58 ,
V_383 ? L_47 : L_48 ) ;
F_171 ( V_10 ) ;
V_19 -> V_22 . V_73 = V_383 ? F_187 :
F_188 ;
F_205 ( & V_19 -> V_22 . V_23 , & V_10 -> V_71 ) ;
F_206 ( V_10 -> V_26 ) ;
V_70 = - V_384 ;
goto V_104;
} else {
struct V_310 * V_311 =
F_163 ( V_6 , struct V_310 , V_6 ) ;
if ( ! V_382 )
F_204 ( V_38 , L_44
L_49 ,
( unsigned long long ) V_6 -> V_46 , V_6 -> V_58 ,
( unsigned long long ) V_46 , V_58 ) ;
if ( V_311 -> V_338 & V_339 ||
! ( V_311 -> V_338 & V_340 ) ) {
V_70 = F_203 ( V_10 , & V_311 -> V_6 ) ;
if ( V_70 ) {
F_207 ( V_10 -> V_26 ,
F_69 ( V_105 , V_385 ) ,
V_107 ) ;
F_199 ( V_10 , V_46 , V_58 ) ;
goto V_104;
}
goto V_377;
}
V_19 -> V_63 |= V_351 ;
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
struct V_333 * V_298 = V_171 -> V_95 ;
T_8 V_178 = F_123 ( V_298 -> V_386 ) ;
int V_276 = V_327 ;
T_8 V_387 ;
int V_70 , V_357 ;
V_10 = F_175 ( V_26 , V_171 -> V_189 ) ;
if ( ! V_10 )
return - V_108 ;
if ( ! F_127 ( V_10 ) ) {
int V_72 ;
V_70 = F_196 ( V_10 , V_178 ) ;
F_181 ( V_10 , V_323 , V_298 , V_171 -> V_58 ) ;
F_209 ( & V_26 -> V_261 -> V_250 ) ;
V_72 = F_158 ( V_10 , V_171 -> V_58 ) ;
if ( ! V_70 )
V_70 = V_72 ;
return V_70 ;
}
V_46 = F_176 ( V_298 -> V_46 ) ;
V_19 = F_150 ( V_10 , V_298 -> V_64 , V_46 , V_171 -> V_58 ) ;
if ( ! V_19 ) {
F_131 ( V_10 ) ;
return - V_108 ;
}
V_19 -> V_22 . V_73 = F_185 ;
V_387 = F_123 ( V_298 -> V_387 ) ;
V_276 |= F_198 ( V_10 , V_387 ) ;
if ( V_19 -> V_61 == NULL ) {
F_49 ( V_19 -> V_6 . V_58 == 0 ) ;
F_49 ( V_387 & V_373 ) ;
}
if ( V_387 & V_388 )
V_19 -> V_63 |= V_348 ;
F_11 ( & V_26 -> V_253 ) ;
V_19 -> V_60 = V_26 -> V_261 ;
F_209 ( & V_19 -> V_60 -> V_250 ) ;
F_209 ( & V_19 -> V_60 -> V_256 ) ;
F_12 ( & V_26 -> V_253 ) ;
F_27 () ;
V_357 = F_28 ( V_10 -> V_26 -> V_29 ) -> V_358 ;
F_29 () ;
if ( V_357 ) {
V_19 -> V_63 |= V_350 ;
V_70 = F_196 ( V_10 , V_178 ) ;
if ( V_70 )
goto V_389;
F_21 ( & V_10 -> V_26 -> V_27 ) ;
V_70 = F_201 ( V_10 , V_19 ) ;
if ( V_70 ) {
F_22 ( & V_10 -> V_26 -> V_27 ) ;
if ( V_70 == - V_384 ) {
F_131 ( V_10 ) ;
return 0 ;
}
goto V_389;
}
} else
F_21 ( & V_10 -> V_26 -> V_27 ) ;
F_149 ( & V_19 -> V_22 . V_23 , & V_10 -> V_296 ) ;
F_22 ( & V_10 -> V_26 -> V_27 ) ;
if ( V_10 -> V_345 . V_105 == V_390 )
F_210 ( V_10 -> V_74 , ! F_194 ( V_10 , V_19 ) ) ;
if ( V_10 -> V_26 -> V_180 < 100 ) {
F_27 () ;
switch ( F_28 ( V_10 -> V_26 -> V_29 ) -> V_391 ) {
case V_392 :
V_387 |= V_393 ;
break;
case V_394 :
V_387 |= V_395 ;
break;
}
F_29 () ;
}
if ( V_387 & V_393 ) {
V_19 -> V_63 |= V_344 ;
F_171 ( V_10 ) ;
}
if ( V_387 & V_395 ) {
F_166 ( V_10 , V_396 , V_19 ) ;
}
if ( V_10 -> V_345 . V_397 < V_398 ) {
F_211 ( V_10 , V_19 -> V_6 . V_46 , V_19 -> V_6 . V_58 ) ;
V_19 -> V_63 |= V_399 ;
V_19 -> V_63 &= ~ V_348 ;
F_212 ( V_10 , & V_19 -> V_6 , true ) ;
}
V_70 = F_138 ( V_10 , V_19 , V_276 , V_400 ) ;
if ( ! V_70 )
return 0 ;
F_43 ( V_38 , L_40 ) ;
F_21 ( & V_10 -> V_26 -> V_27 ) ;
F_135 ( & V_19 -> V_22 . V_23 ) ;
F_144 ( V_10 , V_19 ) ;
F_22 ( & V_10 -> V_26 -> V_27 ) ;
if ( V_19 -> V_63 & V_399 )
F_213 ( V_10 , & V_19 -> V_6 ) ;
V_389:
F_132 ( V_26 , V_19 -> V_60 , V_255 + V_254 ) ;
F_131 ( V_10 ) ;
F_54 ( V_10 , V_19 ) ;
return V_70 ;
}
int F_214 ( struct V_9 * V_10 , T_3 V_46 )
{
struct V_401 * V_402 = V_10 -> V_243 -> V_244 -> V_403 -> V_404 ;
unsigned long V_405 , V_406 , V_407 ;
struct V_408 * V_4 ;
int V_409 ;
int V_410 = 0 ;
unsigned int V_411 ;
F_27 () ;
V_411 = F_28 ( V_10 -> V_243 -> V_268 ) -> V_411 ;
F_29 () ;
if ( V_411 == 0 )
return 0 ;
F_21 ( & V_10 -> V_412 ) ;
V_4 = F_215 ( V_10 -> V_413 , F_216 ( V_46 ) ) ;
if ( V_4 ) {
struct V_414 * V_415 = F_217 ( V_4 , struct V_414 , V_416 ) ;
if ( F_66 ( V_417 , & V_415 -> V_63 ) ) {
F_22 ( & V_10 -> V_412 ) ;
return 0 ;
}
}
F_22 ( & V_10 -> V_412 ) ;
V_409 = ( int ) F_218 ( & V_402 -> V_418 , V_419 [ 0 ] ) +
( int ) F_218 ( & V_402 -> V_418 , V_419 [ 1 ] ) -
F_30 ( & V_10 -> V_326 ) ;
if ( ! V_10 -> V_420 || V_409 - V_10 -> V_420 > 64 ) {
unsigned long V_421 ;
int V_6 ;
V_10 -> V_420 = V_409 ;
V_6 = ( V_10 -> V_422 + V_423 - 1 ) % V_423 ;
if ( V_10 -> V_345 . V_105 == V_424 || V_10 -> V_345 . V_105 == V_425 )
V_421 = V_10 -> V_426 ;
else
V_421 = F_219 ( V_10 ) - V_10 -> V_427 ;
V_406 = ( ( long ) V_187 - ( long ) V_10 -> V_428 [ V_6 ] ) / V_100 ;
if ( ! V_406 )
V_406 ++ ;
V_405 = V_10 -> V_429 [ V_6 ] - V_421 ;
V_407 = F_220 ( V_405 / V_406 ) ;
if ( V_407 > V_411 )
V_410 = 1 ;
}
return V_410 ;
}
static int F_221 ( struct V_94 * V_26 , struct V_170 * V_171 )
{
struct V_9 * V_10 ;
T_3 V_46 ;
T_3 V_300 ;
struct V_18 * V_19 ;
struct V_430 * V_431 = NULL ;
int V_58 , V_432 ;
unsigned int V_277 ;
struct V_433 * V_298 = V_171 -> V_95 ;
V_10 = F_175 ( V_26 , V_171 -> V_189 ) ;
if ( ! V_10 )
return - V_108 ;
V_300 = F_151 ( V_10 -> V_301 ) ;
V_46 = F_176 ( V_298 -> V_46 ) ;
V_58 = F_123 ( V_298 -> V_434 ) ;
if ( V_58 <= 0 || ! F_154 ( V_58 , 512 ) || V_58 > V_42 ) {
F_43 ( V_38 , L_50 , __FILE__ , __LINE__ ,
( unsigned long long ) V_46 , V_58 ) ;
return - V_231 ;
}
if ( V_46 + ( V_58 >> 9 ) > V_300 ) {
F_43 ( V_38 , L_50 , __FILE__ , __LINE__ ,
( unsigned long long ) V_46 , V_58 ) ;
return - V_231 ;
}
if ( ! F_137 ( V_10 , V_435 ) ) {
V_432 = 1 ;
switch ( V_171 -> V_168 ) {
case V_436 :
F_222 ( V_10 , V_437 , V_298 ) ;
break;
case V_438 :
case V_439 :
case V_440 :
F_222 ( V_10 , V_441 , V_298 ) ;
break;
case V_442 :
V_432 = 0 ;
F_170 ( V_10 ) ;
F_223 ( V_10 , V_443 , V_46 , V_58 , V_444 ) ;
break;
default:
F_224 () ;
}
if ( V_432 && F_180 ( & V_336 ) )
F_43 ( V_38 , L_51
L_52 ) ;
return F_158 ( V_10 , V_171 -> V_58 ) ;
}
V_19 = F_40 ( V_10 , V_298 -> V_64 , V_46 , V_58 , V_211 ) ;
if ( ! V_19 ) {
F_131 ( V_10 ) ;
return - V_282 ;
}
switch ( V_171 -> V_168 ) {
case V_436 :
V_19 -> V_22 . V_73 = V_445 ;
V_277 = V_446 ;
goto V_447;
case V_438 :
V_19 -> V_22 . V_73 = V_448 ;
V_277 = V_449 ;
V_10 -> V_450 = F_225 ( V_46 ) ;
break;
case V_442 :
case V_439 :
V_277 = V_449 ;
V_431 = F_148 ( sizeof( * V_431 ) + V_171 -> V_58 , V_211 ) ;
if ( ! V_431 )
goto V_451;
V_431 -> V_452 = V_171 -> V_58 ;
V_431 -> V_66 = ( ( ( char * ) V_431 ) + sizeof( struct V_430 ) ) ;
V_19 -> V_66 = V_431 ;
V_19 -> V_63 |= V_65 ;
if ( F_70 ( V_10 -> V_26 , V_431 -> V_66 , V_171 -> V_58 ) )
goto V_451;
if ( V_171 -> V_168 == V_439 ) {
F_49 ( V_10 -> V_26 -> V_180 >= 89 ) ;
V_19 -> V_22 . V_73 = V_453 ;
V_10 -> V_450 = F_225 ( V_46 ) ;
} else if ( V_171 -> V_168 == V_442 ) {
F_36 ( V_58 >> 9 , & V_10 -> V_337 ) ;
V_19 -> V_22 . V_73 = V_454 ;
F_170 ( V_10 ) ;
goto V_455;
}
break;
case V_440 :
if ( V_10 -> V_456 == ~ ( T_3 ) 0 &&
V_10 -> V_26 -> V_180 >= 90 ) {
unsigned long V_457 = V_187 ;
int V_6 ;
V_10 -> V_456 = V_46 ;
V_10 -> V_458 = V_46 ;
V_10 -> V_426 = F_226 ( V_10 ) - F_225 ( V_46 ) ;
V_10 -> V_459 = V_10 -> V_426 ;
for ( V_6 = 0 ; V_6 < V_423 ; V_6 ++ ) {
V_10 -> V_429 [ V_6 ] = V_10 -> V_426 ;
V_10 -> V_428 [ V_6 ] = V_457 ;
}
F_129 ( V_38 , L_53 ,
( unsigned long long ) V_46 ) ;
}
V_19 -> V_22 . V_73 = V_460 ;
V_277 = V_449 ;
break;
default:
F_224 () ;
}
if ( V_10 -> V_345 . V_461 != V_462 && F_214 ( V_10 , V_46 ) )
F_227 ( V_100 / 10 ) ;
if ( F_228 ( V_10 , V_46 ) )
goto V_451;
V_455:
F_36 ( V_58 >> 9 , & V_10 -> V_326 ) ;
V_447:
F_171 ( V_10 ) ;
F_21 ( & V_10 -> V_26 -> V_27 ) ;
F_205 ( & V_19 -> V_22 . V_23 , & V_10 -> V_463 ) ;
F_22 ( & V_10 -> V_26 -> V_27 ) ;
if ( F_138 ( V_10 , V_19 , V_464 , V_277 ) == 0 )
return 0 ;
F_43 ( V_38 , L_40 ) ;
F_21 ( & V_10 -> V_26 -> V_27 ) ;
F_135 ( & V_19 -> V_22 . V_23 ) ;
F_22 ( & V_10 -> V_26 -> V_27 ) ;
V_451:
F_131 ( V_10 ) ;
F_54 ( V_10 , V_19 ) ;
return - V_108 ;
}
static int F_229 ( struct V_9 * V_10 ) __must_hold( T_5 )
{
int V_465 , V_461 , V_92 = - 100 ;
unsigned long V_466 , V_467 ;
enum V_468 V_469 ;
V_465 = V_10 -> V_243 -> V_470 . V_471 [ V_472 ] & 1 ;
V_461 = V_10 -> V_473 [ V_472 ] & 1 ;
V_467 = V_10 -> V_473 [ V_474 ] ;
V_466 = V_10 -> V_475 ;
F_27 () ;
V_469 = F_28 ( V_10 -> V_26 -> V_29 ) -> V_469 ;
F_29 () ;
switch ( V_469 ) {
case V_476 :
case V_477 :
case V_478 :
case V_479 :
F_43 ( V_38 , L_54 ) ;
break;
case V_480 :
break;
case V_481 :
if ( V_465 == 0 && V_461 == 1 ) {
V_92 = - 1 ;
break;
}
if ( V_465 == 1 && V_461 == 0 ) {
V_92 = 1 ;
break;
}
case V_482 :
if ( V_465 == 0 && V_461 == 1 ) {
V_92 = 1 ;
break;
}
if ( V_465 == 1 && V_461 == 0 ) {
V_92 = - 1 ;
break;
}
F_33 ( V_38 , L_55
L_56 ) ;
case V_483 :
if ( V_467 == 0 && V_466 == 0 ) {
V_92 = F_66 ( V_203 , & V_10 -> V_26 -> V_63 )
? - 1 : 1 ;
break;
} else {
if ( V_467 == 0 ) { V_92 = 1 ; break; }
if ( V_466 == 0 ) { V_92 = - 1 ; break; }
}
if ( V_469 == V_483 )
break;
case V_484 :
if ( V_466 < V_467 )
V_92 = - 1 ;
else if ( V_466 > V_467 )
V_92 = 1 ;
else
V_92 = F_66 ( V_203 , & V_10 -> V_26 -> V_63 )
? - 1 : 1 ;
break;
case V_485 :
V_92 = - 1 ;
break;
case V_486 :
V_92 = 1 ;
}
return V_92 ;
}
static int F_230 ( struct V_9 * V_10 ) __must_hold( T_5 )
{
int V_487 , V_92 = - 100 ;
enum V_468 V_488 ;
F_27 () ;
V_488 = F_28 ( V_10 -> V_26 -> V_29 ) -> V_488 ;
F_29 () ;
switch ( V_488 ) {
case V_481 :
case V_482 :
case V_484 :
case V_485 :
case V_486 :
case V_483 :
F_43 ( V_38 , L_54 ) ;
break;
case V_480 :
break;
case V_476 :
V_487 = F_229 ( V_10 ) ;
if ( V_487 == - 1 && V_10 -> V_345 . V_489 == V_490 )
V_92 = V_487 ;
if ( V_487 == 1 && V_10 -> V_345 . V_489 == V_462 )
V_92 = V_487 ;
break;
case V_479 :
V_92 = F_229 ( V_10 ) ;
break;
case V_477 :
return V_10 -> V_345 . V_489 == V_462 ? 1 : - 1 ;
case V_478 :
V_487 = F_229 ( V_10 ) ;
if ( V_487 == - 1 && V_10 -> V_345 . V_489 == V_462 ) {
enum V_194 V_491 ;
V_491 = F_231 ( V_10 , V_196 , F_69 ( V_489 , V_490 ) ) ;
if ( V_491 != V_197 ) {
F_232 ( V_10 , L_57 ) ;
} else {
F_33 ( V_38 , L_58 ) ;
V_92 = V_487 ;
}
} else
V_92 = V_487 ;
}
return V_92 ;
}
static int F_233 ( struct V_9 * V_10 ) __must_hold( T_5 )
{
int V_487 , V_92 = - 100 ;
enum V_468 V_492 ;
F_27 () ;
V_492 = F_28 ( V_10 -> V_26 -> V_29 ) -> V_492 ;
F_29 () ;
switch ( V_492 ) {
case V_481 :
case V_482 :
case V_484 :
case V_485 :
case V_486 :
case V_476 :
case V_477 :
case V_483 :
F_43 ( V_38 , L_54 ) ;
break;
case V_479 :
V_92 = F_229 ( V_10 ) ;
break;
case V_480 :
break;
case V_478 :
V_487 = F_229 ( V_10 ) ;
if ( V_487 == - 1 ) {
enum V_194 V_491 ;
V_491 = F_231 ( V_10 , V_196 , F_69 ( V_489 , V_490 ) ) ;
if ( V_491 != V_197 ) {
F_232 ( V_10 , L_57 ) ;
} else {
F_33 ( V_38 , L_58 ) ;
V_92 = V_487 ;
}
} else
V_92 = V_487 ;
}
return V_92 ;
}
static void F_234 ( struct V_9 * V_10 , char * V_493 , T_2 * V_471 ,
T_2 V_494 , T_2 V_63 )
{
if ( ! V_471 ) {
F_129 ( V_38 , L_59 , V_493 ) ;
return;
}
F_129 ( V_38 , L_60 ,
V_493 ,
( unsigned long long ) V_471 [ V_495 ] ,
( unsigned long long ) V_471 [ V_472 ] ,
( unsigned long long ) V_471 [ V_496 ] ,
( unsigned long long ) V_471 [ V_497 ] ,
( unsigned long long ) V_494 ,
( unsigned long long ) V_63 ) ;
}
static int F_235 ( struct V_9 * V_10 , int * V_498 ) __must_hold( T_5 )
{
T_2 V_465 , V_461 ;
int V_6 , V_499 ;
V_465 = V_10 -> V_243 -> V_470 . V_471 [ V_495 ] & ~ ( ( T_2 ) 1 ) ;
V_461 = V_10 -> V_473 [ V_495 ] & ~ ( ( T_2 ) 1 ) ;
* V_498 = 10 ;
if ( V_465 == V_500 && V_461 == V_500 )
return 0 ;
* V_498 = 20 ;
if ( ( V_465 == V_500 || V_465 == ( T_2 ) 0 ) &&
V_461 != V_500 )
return - 2 ;
* V_498 = 30 ;
if ( V_465 != V_500 &&
( V_461 == V_500 || V_461 == ( T_2 ) 0 ) )
return 2 ;
if ( V_465 == V_461 ) {
int V_501 , V_269 ;
if ( V_10 -> V_473 [ V_472 ] == ( T_2 ) 0 && V_10 -> V_243 -> V_470 . V_471 [ V_472 ] != ( T_2 ) 0 ) {
if ( V_10 -> V_26 -> V_180 < 91 )
return - 1091 ;
if ( ( V_10 -> V_243 -> V_470 . V_471 [ V_472 ] & ~ ( ( T_2 ) 1 ) ) == ( V_10 -> V_473 [ V_496 ] & ~ ( ( T_2 ) 1 ) ) &&
( V_10 -> V_243 -> V_470 . V_471 [ V_496 ] & ~ ( ( T_2 ) 1 ) ) == ( V_10 -> V_473 [ V_496 + 1 ] & ~ ( ( T_2 ) 1 ) ) ) {
F_129 ( V_38 , L_61 ) ;
F_236 ( V_10 ) ;
V_10 -> V_243 -> V_470 . V_471 [ V_496 ] = V_10 -> V_243 -> V_470 . V_471 [ V_472 ] ;
V_10 -> V_243 -> V_470 . V_471 [ V_472 ] = 0 ;
F_234 ( V_10 , L_62 , V_10 -> V_243 -> V_470 . V_471 ,
V_10 -> V_345 . V_402 >= V_502 ? F_219 ( V_10 ) : 0 , 0 ) ;
* V_498 = 34 ;
} else {
F_129 ( V_38 , L_63 ) ;
* V_498 = 36 ;
}
return 1 ;
}
if ( V_10 -> V_243 -> V_470 . V_471 [ V_472 ] == ( T_2 ) 0 && V_10 -> V_473 [ V_472 ] != ( T_2 ) 0 ) {
if ( V_10 -> V_26 -> V_180 < 91 )
return - 1091 ;
if ( ( V_10 -> V_243 -> V_470 . V_471 [ V_496 ] & ~ ( ( T_2 ) 1 ) ) == ( V_10 -> V_473 [ V_472 ] & ~ ( ( T_2 ) 1 ) ) &&
( V_10 -> V_243 -> V_470 . V_471 [ V_496 + 1 ] & ~ ( ( T_2 ) 1 ) ) == ( V_10 -> V_473 [ V_496 ] & ~ ( ( T_2 ) 1 ) ) ) {
F_129 ( V_38 , L_64 ) ;
V_10 -> V_473 [ V_496 + 1 ] = V_10 -> V_473 [ V_496 ] ;
V_10 -> V_473 [ V_496 ] = V_10 -> V_473 [ V_472 ] ;
V_10 -> V_473 [ V_472 ] = 0UL ;
F_234 ( V_10 , L_65 , V_10 -> V_473 , V_10 -> V_473 [ V_474 ] , V_10 -> V_473 [ V_503 ] ) ;
* V_498 = 35 ;
} else {
F_129 ( V_38 , L_66 ) ;
* V_498 = 37 ;
}
return - 1 ;
}
V_501 = ( F_66 ( V_504 , & V_10 -> V_63 ) ? 1 : 0 ) +
( V_10 -> V_473 [ V_503 ] & 2 ) ;
* V_498 = 40 ;
switch ( V_501 ) {
case 0 : return 0 ;
case 1 : return 1 ;
case 2 : return - 1 ;
case 3 :
V_269 = F_66 ( V_203 , & V_10 -> V_26 -> V_63 ) ;
return V_269 ? - 1 : 1 ;
}
}
* V_498 = 50 ;
V_461 = V_10 -> V_473 [ V_472 ] & ~ ( ( T_2 ) 1 ) ;
if ( V_465 == V_461 )
return - 1 ;
* V_498 = 51 ;
V_461 = V_10 -> V_473 [ V_496 ] & ~ ( ( T_2 ) 1 ) ;
if ( V_465 == V_461 ) {
if ( V_10 -> V_26 -> V_180 < 96 ?
( V_10 -> V_243 -> V_470 . V_471 [ V_496 ] & ~ ( ( T_2 ) 1 ) ) ==
( V_10 -> V_473 [ V_496 + 1 ] & ~ ( ( T_2 ) 1 ) ) :
V_461 + V_505 == ( V_10 -> V_473 [ V_472 ] & ~ ( ( T_2 ) 1 ) ) ) {
if ( V_10 -> V_26 -> V_180 < 91 )
return - 1091 ;
V_10 -> V_473 [ V_472 ] = V_10 -> V_473 [ V_496 ] ;
V_10 -> V_473 [ V_496 ] = V_10 -> V_473 [ V_496 + 1 ] ;
F_129 ( V_38 , L_67 ) ;
F_234 ( V_10 , L_65 , V_10 -> V_473 , V_10 -> V_473 [ V_474 ] , V_10 -> V_473 [ V_503 ] ) ;
return - 1 ;
}
}
* V_498 = 60 ;
V_465 = V_10 -> V_243 -> V_470 . V_471 [ V_495 ] & ~ ( ( T_2 ) 1 ) ;
for ( V_6 = V_496 ; V_6 <= V_497 ; V_6 ++ ) {
V_461 = V_10 -> V_473 [ V_6 ] & ~ ( ( T_2 ) 1 ) ;
if ( V_465 == V_461 )
return - 2 ;
}
* V_498 = 70 ;
V_465 = V_10 -> V_243 -> V_470 . V_471 [ V_472 ] & ~ ( ( T_2 ) 1 ) ;
V_461 = V_10 -> V_473 [ V_495 ] & ~ ( ( T_2 ) 1 ) ;
if ( V_465 == V_461 )
return 1 ;
* V_498 = 71 ;
V_465 = V_10 -> V_243 -> V_470 . V_471 [ V_496 ] & ~ ( ( T_2 ) 1 ) ;
if ( V_465 == V_461 ) {
if ( V_10 -> V_26 -> V_180 < 96 ?
( V_10 -> V_243 -> V_470 . V_471 [ V_496 + 1 ] & ~ ( ( T_2 ) 1 ) ) ==
( V_10 -> V_473 [ V_496 ] & ~ ( ( T_2 ) 1 ) ) :
V_465 + V_505 == ( V_10 -> V_243 -> V_470 . V_471 [ V_472 ] & ~ ( ( T_2 ) 1 ) ) ) {
if ( V_10 -> V_26 -> V_180 < 91 )
return - 1091 ;
F_237 ( V_10 , V_472 , V_10 -> V_243 -> V_470 . V_471 [ V_496 ] ) ;
F_237 ( V_10 , V_496 , V_10 -> V_243 -> V_470 . V_471 [ V_496 + 1 ] ) ;
F_129 ( V_38 , L_68 ) ;
F_234 ( V_10 , L_62 , V_10 -> V_243 -> V_470 . V_471 ,
V_10 -> V_345 . V_402 >= V_502 ? F_219 ( V_10 ) : 0 , 0 ) ;
return 1 ;
}
}
* V_498 = 80 ;
V_461 = V_10 -> V_473 [ V_495 ] & ~ ( ( T_2 ) 1 ) ;
for ( V_6 = V_496 ; V_6 <= V_497 ; V_6 ++ ) {
V_465 = V_10 -> V_243 -> V_470 . V_471 [ V_6 ] & ~ ( ( T_2 ) 1 ) ;
if ( V_465 == V_461 )
return 2 ;
}
* V_498 = 90 ;
V_465 = V_10 -> V_243 -> V_470 . V_471 [ V_472 ] & ~ ( ( T_2 ) 1 ) ;
V_461 = V_10 -> V_473 [ V_472 ] & ~ ( ( T_2 ) 1 ) ;
if ( V_465 == V_461 && V_465 != ( ( T_2 ) 0 ) )
return 100 ;
* V_498 = 100 ;
for ( V_6 = V_496 ; V_6 <= V_497 ; V_6 ++ ) {
V_465 = V_10 -> V_243 -> V_470 . V_471 [ V_6 ] & ~ ( ( T_2 ) 1 ) ;
for ( V_499 = V_496 ; V_499 <= V_497 ; V_499 ++ ) {
V_461 = V_10 -> V_473 [ V_499 ] & ~ ( ( T_2 ) 1 ) ;
if ( V_465 == V_461 )
return - 100 ;
}
}
return - 1000 ;
}
static enum V_506 F_238 ( struct V_9 * V_10 , enum V_507 V_508 ,
enum V_509 V_510 ) __must_hold( T_5 )
{
enum V_506 V_92 = V_511 ;
enum V_509 V_512 ;
struct V_29 * V_30 ;
int V_487 , V_498 , V_513 , V_514 ;
V_512 = V_10 -> V_345 . V_402 ;
if ( V_512 == V_502 )
V_512 = V_10 -> V_515 . V_402 ;
F_129 ( V_38 , L_69 ) ;
F_21 ( & V_10 -> V_243 -> V_470 . V_516 ) ;
F_234 ( V_10 , L_62 , V_10 -> V_243 -> V_470 . V_471 , V_10 -> V_475 , 0 ) ;
F_234 ( V_10 , L_65 , V_10 -> V_473 ,
V_10 -> V_473 [ V_474 ] , V_10 -> V_473 [ V_503 ] ) ;
V_487 = F_235 ( V_10 , & V_498 ) ;
F_22 ( & V_10 -> V_243 -> V_470 . V_516 ) ;
F_129 ( V_38 , L_70 , V_487 , V_498 ) ;
if ( V_487 == - 1000 ) {
F_204 ( V_38 , L_71 ) ;
return V_511 ;
}
if ( V_487 < - 1000 ) {
F_204 ( V_38 , L_72 , - V_487 - 1000 ) ;
return V_511 ;
}
if ( ( V_512 == V_398 && V_510 > V_398 ) ||
( V_510 == V_398 && V_512 > V_398 ) ) {
int V_517 = ( V_487 == - 100 ) || abs ( V_487 ) == 2 ;
V_487 = V_512 > V_398 ? 1 : - 1 ;
if ( V_517 )
V_487 = V_487 * 2 ;
F_129 ( V_38 , L_73 ,
V_487 > 0 ? L_74 : L_75 ) ;
}
if ( abs ( V_487 ) == 100 )
F_232 ( V_10 , L_76 ) ;
F_27 () ;
V_30 = F_28 ( V_10 -> V_26 -> V_29 ) ;
if ( V_487 == 100 || ( V_487 == - 100 && V_30 -> V_518 ) ) {
int V_519 = ( V_10 -> V_345 . V_489 == V_462 )
+ ( V_508 == V_462 ) ;
int V_520 = ( V_487 == - 100 ) ;
switch ( V_519 ) {
case 0 :
V_487 = F_229 ( V_10 ) ;
break;
case 1 :
V_487 = F_230 ( V_10 ) ;
break;
case 2 :
V_487 = F_233 ( V_10 ) ;
break;
}
if ( abs ( V_487 ) < 100 ) {
F_33 ( V_38 , L_77
L_78 ,
V_519 , ( V_487 < 0 ) ? L_65 : L_79 ) ;
if ( V_520 ) {
F_33 ( V_38 , L_80
L_81 ) ;
V_487 = V_487 * 2 ;
}
}
}
if ( V_487 == - 100 ) {
if ( F_66 ( V_222 , & V_10 -> V_63 ) && ! ( V_10 -> V_473 [ V_503 ] & 1 ) )
V_487 = - 1 ;
if ( ! F_66 ( V_222 , & V_10 -> V_63 ) && ( V_10 -> V_473 [ V_503 ] & 1 ) )
V_487 = 1 ;
if ( abs ( V_487 ) < 100 )
F_33 ( V_38 , L_82
L_83 ,
( V_487 < 0 ) ? L_65 : L_79 ) ;
}
V_513 = V_30 -> V_513 ;
V_514 = V_30 -> V_514 ;
F_29 () ;
if ( V_487 == - 100 ) {
F_204 ( V_38 , L_84 ) ;
F_232 ( V_10 , L_85 ) ;
return V_511 ;
}
if ( V_487 > 0 && V_512 <= V_398 ) {
F_43 ( V_38 , L_86 ) ;
return V_511 ;
}
if ( V_487 < 0 &&
V_10 -> V_345 . V_489 == V_462 && V_10 -> V_345 . V_402 >= V_521 ) {
switch ( V_513 ) {
case V_478 :
F_232 ( V_10 , L_87 ) ;
case V_480 :
F_43 ( V_38 , L_88 ) ;
return V_511 ;
case V_479 :
F_33 ( V_38 , L_89
L_90 ) ;
}
}
if ( V_514 || F_66 ( V_522 , & V_10 -> V_26 -> V_63 ) ) {
if ( V_487 == 0 )
F_129 ( V_38 , L_91 ) ;
else
F_129 ( V_38 , L_92 ,
F_239 ( V_487 > 0 ? V_346 : V_390 ) ,
abs ( V_487 ) >= 2 ? L_93 : L_94 ) ;
return V_511 ;
}
if ( abs ( V_487 ) >= 2 ) {
F_129 ( V_38 , L_95 ) ;
if ( F_240 ( V_10 , & V_523 , L_96 ,
V_524 ) )
return V_511 ;
}
if ( V_487 > 0 ) {
V_92 = V_525 ;
} else if ( V_487 < 0 ) {
V_92 = V_526 ;
} else {
V_92 = V_527 ;
if ( F_219 ( V_10 ) ) {
F_129 ( V_38 , L_97 ,
F_219 ( V_10 ) ) ;
}
}
return V_92 ;
}
static enum V_468 F_241 ( enum V_468 V_461 )
{
if ( V_461 == V_486 )
return V_485 ;
if ( V_461 == V_485 )
return V_486 ;
return V_461 ;
}
static int F_242 ( struct V_94 * V_26 , struct V_170 * V_171 )
{
struct V_528 * V_298 = V_171 -> V_95 ;
enum V_468 V_529 , V_530 , V_531 ;
int V_532 , V_533 , V_534 , V_535 ;
struct V_29 * V_30 , * V_536 , * V_537 = NULL ;
char V_538 [ V_539 ] = L_98 ;
struct V_540 * V_307 = NULL ;
void * V_304 = NULL , * V_306 = NULL ;
V_532 = F_123 ( V_298 -> V_541 ) ;
V_529 = F_123 ( V_298 -> V_469 ) ;
V_530 = F_123 ( V_298 -> V_488 ) ;
V_531 = F_123 ( V_298 -> V_492 ) ;
V_534 = F_123 ( V_298 -> V_358 ) ;
V_535 = F_123 ( V_298 -> V_542 ) ;
V_533 = V_535 & V_543 ;
if ( V_26 -> V_180 >= 87 ) {
int V_70 ;
if ( V_171 -> V_58 > sizeof( V_538 ) )
return - V_108 ;
V_70 = F_70 ( V_26 , V_538 , V_171 -> V_58 ) ;
if ( V_70 )
return V_70 ;
V_538 [ V_539 - 1 ] = 0 ;
}
if ( V_171 -> V_168 != V_544 ) {
F_101 ( V_522 , & V_26 -> V_63 ) ;
if ( V_535 & V_545 )
F_107 ( V_522 , & V_26 -> V_63 ) ;
F_27 () ;
V_30 = F_28 ( V_26 -> V_29 ) ;
if ( V_532 != V_30 -> V_391 ) {
F_65 ( V_26 , L_99 , L_100 ) ;
goto V_546;
}
if ( F_241 ( V_529 ) != V_30 -> V_469 ) {
F_65 ( V_26 , L_99 , L_101 ) ;
goto V_546;
}
if ( F_241 ( V_530 ) != V_30 -> V_488 ) {
F_65 ( V_26 , L_99 , L_102 ) ;
goto V_546;
}
if ( F_241 ( V_531 ) != V_30 -> V_492 ) {
F_65 ( V_26 , L_99 , L_103 ) ;
goto V_546;
}
if ( V_533 && V_30 -> V_193 ) {
F_65 ( V_26 , L_99 , L_104 ) ;
goto V_546;
}
if ( V_534 != V_30 -> V_358 ) {
F_65 ( V_26 , L_99 , L_105 ) ;
goto V_546;
}
if ( strcmp ( V_538 , V_30 -> V_538 ) ) {
F_65 ( V_26 , L_99 , L_106 ) ;
goto V_546;
}
F_29 () ;
}
if ( V_538 [ 0 ] ) {
int V_547 ;
V_307 = F_243 ( V_538 , 0 , V_548 ) ;
if ( ! V_307 ) {
F_65 ( V_26 , L_107 ,
V_538 ) ;
goto V_549;
}
V_547 = F_152 ( V_307 ) ;
V_304 = F_148 ( V_547 , V_550 ) ;
V_306 = F_148 ( V_547 , V_550 ) ;
if ( ! ( V_304 && V_306 ) ) {
F_65 ( V_26 , L_108 ) ;
goto V_549;
}
}
V_537 = F_148 ( sizeof( struct V_29 ) , V_550 ) ;
if ( ! V_537 ) {
F_65 ( V_26 , L_109 ) ;
goto V_549;
}
F_117 ( & V_26 -> V_95 . V_198 ) ;
F_117 ( & V_26 -> V_225 ) ;
V_536 = V_26 -> V_29 ;
* V_537 = * V_536 ;
V_537 -> V_391 = V_532 ;
V_537 -> V_469 = F_241 ( V_529 ) ;
V_537 -> V_488 = F_241 ( V_530 ) ;
V_537 -> V_492 = F_241 ( V_531 ) ;
V_537 -> V_358 = V_534 ;
F_244 ( V_26 -> V_29 , V_537 ) ;
F_118 ( & V_26 -> V_225 ) ;
F_118 ( & V_26 -> V_95 . V_198 ) ;
F_245 ( V_26 -> V_307 ) ;
F_48 ( V_26 -> V_304 ) ;
F_48 ( V_26 -> V_306 ) ;
V_26 -> V_307 = V_307 ;
V_26 -> V_304 = V_304 ;
V_26 -> V_306 = V_306 ;
if ( strcmp ( V_536 -> V_538 , V_538 ) )
F_64 ( V_26 , L_110 ,
V_538 [ 0 ] ? V_538 : L_111 ) ;
F_246 () ;
F_48 ( V_536 ) ;
return 0 ;
V_546:
F_29 () ;
V_549:
F_245 ( V_307 ) ;
F_48 ( V_304 ) ;
F_48 ( V_306 ) ;
F_68 ( V_26 , F_69 ( V_105 , V_150 ) , V_107 ) ;
return - V_108 ;
}
struct V_540 * F_247 ( const struct V_9 * V_10 ,
const char * V_551 , const char * V_552 )
{
struct V_540 * V_553 ;
if ( ! V_551 [ 0 ] )
return NULL ;
V_553 = F_243 ( V_551 , 0 , V_548 ) ;
if ( F_248 ( V_553 ) ) {
F_43 ( V_38 , L_112 ,
V_551 , V_552 , F_249 ( V_553 ) ) ;
return V_553 ;
}
return V_553 ;
}
static int F_250 ( struct V_94 * V_26 , struct V_170 * V_171 )
{
void * V_240 = V_26 -> V_95 . V_172 ;
int V_58 = V_171 -> V_58 ;
while ( V_58 ) {
int V_201 = F_75 ( int , V_58 , V_554 ) ;
V_201 = F_63 ( V_26 , V_240 , V_201 ) ;
if ( V_201 <= 0 ) {
if ( V_201 < 0 )
return V_201 ;
break;
}
V_58 -= V_201 ;
}
if ( V_58 )
return - V_108 ;
return 0 ;
}
static int F_251 ( struct V_94 * V_26 , struct V_170 * V_171 )
{
F_72 ( V_26 , L_113 ,
F_252 ( V_171 -> V_168 ) , V_171 -> V_189 ) ;
return F_250 ( V_26 , V_171 ) ;
}
static int F_253 ( struct V_94 * V_26 , struct V_170 * V_171 )
{
struct V_9 * V_10 ;
struct V_555 * V_298 ;
unsigned int V_169 , V_47 , V_556 ;
struct V_540 * V_557 = NULL ;
struct V_540 * V_558 = NULL ;
struct V_29 * V_536 , * V_537 = NULL ;
struct V_268 * V_559 = NULL , * V_560 = NULL ;
const int V_561 = V_26 -> V_180 ;
struct V_562 * V_563 = NULL , * V_564 = NULL ;
int V_565 = 0 ;
int V_70 ;
V_10 = F_175 ( V_26 , V_171 -> V_189 ) ;
if ( ! V_10 )
return F_251 ( V_26 , V_171 ) ;
V_556 = V_561 <= 87 ? sizeof( struct V_566 )
: V_561 == 88 ? sizeof( struct V_566 )
+ V_539
: V_561 <= 94 ? sizeof( struct V_567 )
: sizeof( struct V_555 ) ;
if ( V_171 -> V_58 > V_556 ) {
F_43 ( V_38 , L_114 ,
V_171 -> V_58 , V_556 ) ;
return - V_108 ;
}
if ( V_561 <= 88 ) {
V_169 = sizeof( struct V_566 ) ;
V_47 = V_171 -> V_58 - V_169 ;
} else if ( V_561 <= 94 ) {
V_169 = sizeof( struct V_567 ) ;
V_47 = V_171 -> V_58 - V_169 ;
F_49 ( V_47 == 0 ) ;
} else {
V_169 = sizeof( struct V_555 ) ;
V_47 = V_171 -> V_58 - V_169 ;
F_49 ( V_47 == 0 ) ;
}
V_298 = V_171 -> V_95 ;
memset ( V_298 -> V_568 , 0 , 2 * V_539 ) ;
V_70 = F_70 ( V_10 -> V_26 , V_298 , V_169 ) ;
if ( V_70 )
return V_70 ;
F_117 ( & V_10 -> V_26 -> V_225 ) ;
V_536 = V_10 -> V_26 -> V_29 ;
if ( F_127 ( V_10 ) ) {
V_560 = F_254 ( sizeof( struct V_268 ) , V_550 ) ;
if ( ! V_560 ) {
F_131 ( V_10 ) ;
F_118 ( & V_10 -> V_26 -> V_225 ) ;
F_43 ( V_38 , L_115 ) ;
return - V_282 ;
}
V_559 = V_10 -> V_243 -> V_268 ;
* V_560 = * V_559 ;
V_560 -> V_569 = F_123 ( V_298 -> V_569 ) ;
}
if ( V_561 >= 88 ) {
if ( V_561 == 88 ) {
if ( V_47 > V_539 || V_47 == 0 ) {
F_43 ( V_38 , L_116
L_117 ,
V_47 , V_539 ) ;
V_70 = - V_108 ;
goto V_570;
}
V_70 = F_70 ( V_10 -> V_26 , V_298 -> V_568 , V_47 ) ;
if ( V_70 )
goto V_570;
F_49 ( V_298 -> V_568 [ V_47 - 1 ] == 0 ) ;
V_298 -> V_568 [ V_47 - 1 ] = 0 ;
} else {
F_49 ( V_298 -> V_568 [ V_539 - 1 ] == 0 ) ;
F_49 ( V_298 -> V_571 [ V_539 - 1 ] == 0 ) ;
V_298 -> V_568 [ V_539 - 1 ] = 0 ;
V_298 -> V_571 [ V_539 - 1 ] = 0 ;
}
if ( strcmp ( V_536 -> V_568 , V_298 -> V_568 ) ) {
if ( V_10 -> V_345 . V_105 == V_103 ) {
F_43 ( V_38 , L_118 ,
V_536 -> V_568 , V_298 -> V_568 ) ;
goto V_549;
}
V_557 = F_247 ( V_10 ,
V_298 -> V_568 , L_119 ) ;
if ( F_248 ( V_557 ) ) {
V_557 = NULL ;
goto V_549;
}
}
if ( V_561 >= 89 && strcmp ( V_536 -> V_571 , V_298 -> V_571 ) ) {
if ( V_10 -> V_345 . V_105 == V_103 ) {
F_43 ( V_38 , L_120 ,
V_536 -> V_571 , V_298 -> V_571 ) ;
goto V_549;
}
V_558 = F_247 ( V_10 ,
V_298 -> V_571 , L_121 ) ;
if ( F_248 ( V_558 ) ) {
V_558 = NULL ;
goto V_549;
}
}
if ( V_561 > 94 && V_560 ) {
V_560 -> V_572 = F_123 ( V_298 -> V_572 ) ;
V_560 -> V_573 = F_123 ( V_298 -> V_573 ) ;
V_560 -> V_574 = F_123 ( V_298 -> V_574 ) ;
V_560 -> V_575 = F_123 ( V_298 -> V_575 ) ;
V_565 = ( V_560 -> V_572 * 10 * V_576 ) / V_100 ;
if ( V_565 != V_10 -> V_577 -> V_58 ) {
V_564 = F_255 ( V_565 ) ;
if ( ! V_564 ) {
F_43 ( V_38 , L_122 ) ;
F_131 ( V_10 ) ;
goto V_549;
}
}
}
if ( V_557 || V_558 ) {
V_537 = F_254 ( sizeof( struct V_29 ) , V_550 ) ;
if ( ! V_537 ) {
F_43 ( V_38 , L_109 ) ;
goto V_549;
}
* V_537 = * V_536 ;
if ( V_557 ) {
strcpy ( V_537 -> V_568 , V_298 -> V_568 ) ;
V_537 -> V_578 = strlen ( V_298 -> V_568 ) + 1 ;
F_245 ( V_10 -> V_26 -> V_557 ) ;
V_10 -> V_26 -> V_557 = V_557 ;
F_129 ( V_38 , L_123 , V_298 -> V_568 ) ;
}
if ( V_558 ) {
strcpy ( V_537 -> V_571 , V_298 -> V_571 ) ;
V_537 -> V_579 = strlen ( V_298 -> V_571 ) + 1 ;
F_245 ( V_10 -> V_26 -> V_558 ) ;
V_10 -> V_26 -> V_558 = V_558 ;
F_129 ( V_38 , L_124 , V_298 -> V_571 ) ;
}
F_244 ( V_26 -> V_29 , V_537 ) ;
}
}
if ( V_560 ) {
F_244 ( V_10 -> V_243 -> V_268 , V_560 ) ;
F_131 ( V_10 ) ;
}
if ( V_564 ) {
V_563 = V_10 -> V_577 ;
F_244 ( V_10 -> V_577 , V_564 ) ;
}
F_118 ( & V_10 -> V_26 -> V_225 ) ;
F_246 () ;
if ( V_537 )
F_48 ( V_536 ) ;
F_48 ( V_559 ) ;
F_48 ( V_563 ) ;
return 0 ;
V_570:
if ( V_560 ) {
F_131 ( V_10 ) ;
F_48 ( V_560 ) ;
}
F_118 ( & V_10 -> V_26 -> V_225 ) ;
return - V_108 ;
V_549:
F_48 ( V_564 ) ;
if ( V_560 ) {
F_131 ( V_10 ) ;
F_48 ( V_560 ) ;
}
F_118 ( & V_10 -> V_26 -> V_225 ) ;
F_245 ( V_558 ) ;
F_245 ( V_557 ) ;
F_68 ( V_10 -> V_26 , F_69 ( V_105 , V_150 ) , V_107 ) ;
return - V_108 ;
}
static void F_256 ( struct V_9 * V_10 ,
const char * V_201 , T_3 V_40 , T_3 V_355 )
{
T_3 V_580 ;
if ( V_40 == 0 || V_355 == 0 )
return;
V_580 = ( V_40 > V_355 ) ? ( V_40 - V_355 ) : ( V_355 - V_40 ) ;
if ( V_580 > ( V_40 >> 3 ) || V_580 > ( V_355 >> 3 ) )
F_33 ( V_38 , L_125 , V_201 ,
( unsigned long long ) V_40 , ( unsigned long long ) V_355 ) ;
}
static int F_257 ( struct V_94 * V_26 , struct V_170 * V_171 )
{
struct V_9 * V_10 ;
struct V_581 * V_298 = V_171 -> V_95 ;
enum V_582 V_583 = V_584 ;
T_3 V_585 , V_586 , V_587 ;
int V_588 = 0 ;
enum V_589 V_590 ;
V_10 = F_175 ( V_26 , V_171 -> V_189 ) ;
if ( ! V_10 )
return F_251 ( V_26 , V_171 ) ;
V_585 = F_176 ( V_298 -> V_591 ) ;
V_586 = F_176 ( V_298 -> V_592 ) ;
V_10 -> V_585 = V_585 ;
if ( F_127 ( V_10 ) ) {
F_27 () ;
V_587 = F_28 ( V_10 -> V_243 -> V_268 ) -> V_593 ;
F_29 () ;
F_256 ( V_10 , L_126 ,
V_585 , F_258 ( V_10 -> V_243 ) ) ;
F_256 ( V_10 , L_127 ,
V_586 , V_587 ) ;
if ( V_10 -> V_345 . V_105 == V_103 )
V_586 = F_259 ( V_587 , V_586 ) ;
if ( F_260 ( V_10 , V_10 -> V_243 , V_586 , 0 ) <
F_151 ( V_10 -> V_301 ) &&
V_10 -> V_345 . V_402 >= V_594 &&
V_10 -> V_345 . V_105 < V_527 ) {
F_43 ( V_38 , L_128 ) ;
F_68 ( V_10 -> V_26 , F_69 ( V_105 , V_150 ) , V_107 ) ;
F_131 ( V_10 ) ;
return - V_108 ;
}
if ( V_587 != V_586 ) {
struct V_268 * V_559 , * V_560 = NULL ;
V_560 = F_254 ( sizeof( struct V_268 ) , V_550 ) ;
if ( ! V_560 ) {
F_43 ( V_38 , L_115 ) ;
F_131 ( V_10 ) ;
return - V_282 ;
}
F_117 ( & V_10 -> V_26 -> V_225 ) ;
V_559 = V_10 -> V_243 -> V_268 ;
* V_560 = * V_559 ;
V_560 -> V_593 = V_586 ;
F_244 ( V_10 -> V_243 -> V_268 , V_560 ) ;
F_118 ( & V_10 -> V_26 -> V_225 ) ;
F_246 () ;
F_48 ( V_559 ) ;
F_129 ( V_38 , L_129 ,
( unsigned long ) V_587 ) ;
}
F_131 ( V_10 ) ;
}
V_590 = F_122 ( V_298 -> V_589 ) ;
if ( F_127 ( V_10 ) ) {
V_583 = F_261 ( V_10 , V_590 ) ;
F_131 ( V_10 ) ;
if ( V_583 == V_595 )
return - V_108 ;
F_262 ( V_10 ) ;
} else {
F_263 ( V_10 , V_585 ) ;
}
V_10 -> V_596 = F_123 ( V_298 -> V_597 ) ;
F_264 ( V_10 ) ;
if ( F_127 ( V_10 ) ) {
if ( V_10 -> V_243 -> V_598 != F_151 ( V_10 -> V_243 -> V_244 ) ) {
V_10 -> V_243 -> V_598 = F_151 ( V_10 -> V_243 -> V_244 ) ;
V_588 = 1 ;
}
F_131 ( V_10 ) ;
}
if ( V_10 -> V_345 . V_105 > V_103 ) {
if ( F_176 ( V_298 -> V_599 ) !=
F_151 ( V_10 -> V_301 ) || V_588 ) {
F_98 ( V_10 , 0 , V_590 ) ;
}
if ( F_265 ( V_184 , & V_10 -> V_63 ) ||
( V_583 == V_600 && V_10 -> V_345 . V_105 == V_527 ) ) {
if ( V_10 -> V_345 . V_397 >= V_398 &&
V_10 -> V_345 . V_402 >= V_398 ) {
if ( V_590 & V_601 )
F_129 ( V_38 , L_130 ) ;
else
F_266 ( V_10 ) ;
} else
F_107 ( V_602 , & V_10 -> V_63 ) ;
}
}
return 0 ;
}
static int F_267 ( struct V_94 * V_26 , struct V_170 * V_171 )
{
struct V_9 * V_10 ;
struct V_603 * V_298 = V_171 -> V_95 ;
T_2 * V_473 ;
int V_6 , V_604 = 0 ;
V_10 = F_175 ( V_26 , V_171 -> V_189 ) ;
if ( ! V_10 )
return F_251 ( V_26 , V_171 ) ;
V_473 = F_148 ( sizeof( T_2 ) * V_605 , V_211 ) ;
if ( ! V_473 ) {
F_43 ( V_38 , L_131 ) ;
return false ;
}
for ( V_6 = V_495 ; V_6 < V_605 ; V_6 ++ )
V_473 [ V_6 ] = F_176 ( V_298 -> V_471 [ V_6 ] ) ;
F_48 ( V_10 -> V_473 ) ;
V_10 -> V_473 = V_473 ;
if ( V_10 -> V_345 . V_105 < V_527 &&
V_10 -> V_345 . V_402 < V_398 &&
V_10 -> V_345 . V_489 == V_462 &&
( V_10 -> V_606 & ~ ( ( T_2 ) 1 ) ) != ( V_473 [ V_495 ] & ~ ( ( T_2 ) 1 ) ) ) {
F_43 ( V_38 , L_132 ,
( unsigned long long ) V_10 -> V_606 ) ;
F_68 ( V_10 -> V_26 , F_69 ( V_105 , V_150 ) , V_107 ) ;
return - V_108 ;
}
if ( F_127 ( V_10 ) ) {
int V_607 =
V_10 -> V_345 . V_105 == V_527 &&
V_10 -> V_26 -> V_180 >= 90 &&
V_10 -> V_243 -> V_470 . V_471 [ V_495 ] == V_500 &&
( V_473 [ V_503 ] & 8 ) ;
if ( V_607 ) {
F_129 ( V_38 , L_133 ) ;
F_240 ( V_10 , & V_608 ,
L_134 ,
V_609 ) ;
F_268 ( V_10 , V_495 , V_473 [ V_495 ] ) ;
F_268 ( V_10 , V_472 , 0 ) ;
F_269 ( F_270 ( V_10 , V_402 , V_435 , V_397 , V_435 ) ,
V_196 , NULL ) ;
F_262 ( V_10 ) ;
V_604 = 1 ;
}
F_131 ( V_10 ) ;
} else if ( V_10 -> V_345 . V_402 < V_398 &&
V_10 -> V_345 . V_489 == V_462 ) {
V_604 = F_271 ( V_10 , V_473 [ V_495 ] ) ;
}
F_117 ( V_10 -> V_179 ) ;
F_118 ( V_10 -> V_179 ) ;
if ( V_10 -> V_345 . V_105 >= V_527 && V_10 -> V_345 . V_402 < V_398 )
V_604 |= F_271 ( V_10 , V_473 [ V_495 ] ) ;
if ( V_604 )
F_272 ( V_10 , L_135 ) ;
return 0 ;
}
static union V_610 F_273 ( union V_610 V_611 )
{
union V_610 V_612 ;
static enum V_506 V_613 [] = {
[ V_103 ] = V_103 ,
[ V_527 ] = V_527 ,
[ V_614 ] = V_615 ,
[ V_615 ] = V_614 ,
[ V_150 ] = V_616 ,
[ V_424 ] = V_425 ,
[ V_511 ] = V_511 ,
} ;
V_612 . V_6 = V_611 . V_6 ;
V_612 . V_105 = V_613 [ V_611 . V_105 ] ;
V_612 . V_461 = V_611 . V_489 ;
V_612 . V_489 = V_611 . V_461 ;
V_612 . V_397 = V_611 . V_402 ;
V_612 . V_402 = V_611 . V_397 ;
V_612 . V_617 = ( V_611 . V_618 | V_611 . V_619 ) ;
return V_612 ;
}
static int F_274 ( struct V_94 * V_26 , struct V_170 * V_171 )
{
struct V_9 * V_10 ;
struct V_620 * V_298 = V_171 -> V_95 ;
union V_610 V_621 , V_622 ;
enum V_194 V_92 ;
V_10 = F_175 ( V_26 , V_171 -> V_189 ) ;
if ( ! V_10 )
return - V_108 ;
V_621 . V_6 = F_123 ( V_298 -> V_621 ) ;
V_622 . V_6 = F_123 ( V_298 -> V_622 ) ;
if ( F_66 ( V_203 , & V_10 -> V_26 -> V_63 ) &&
F_275 ( V_10 -> V_179 ) ) {
F_276 ( V_10 , V_623 ) ;
return 0 ;
}
V_621 = F_273 ( V_621 ) ;
V_622 = F_273 ( V_622 ) ;
V_92 = F_231 ( V_10 , V_196 , V_621 , V_622 ) ;
F_276 ( V_10 , V_92 ) ;
F_262 ( V_10 ) ;
return 0 ;
}
static int F_277 ( struct V_94 * V_26 , struct V_170 * V_171 )
{
struct V_620 * V_298 = V_171 -> V_95 ;
union V_610 V_621 , V_622 ;
enum V_194 V_92 ;
V_621 . V_6 = F_123 ( V_298 -> V_621 ) ;
V_622 . V_6 = F_123 ( V_298 -> V_622 ) ;
if ( F_66 ( V_203 , & V_26 -> V_63 ) &&
F_275 ( & V_26 -> V_181 ) ) {
F_278 ( V_26 , V_623 ) ;
return 0 ;
}
V_621 = F_273 ( V_621 ) ;
V_622 = F_273 ( V_622 ) ;
V_92 = F_68 ( V_26 , V_621 , V_622 , V_196 | V_624 | V_625 ) ;
F_278 ( V_26 , V_92 ) ;
return 0 ;
}
static int F_279 ( struct V_94 * V_26 , struct V_170 * V_171 )
{
struct V_9 * V_10 ;
struct V_626 * V_298 = V_171 -> V_95 ;
union V_610 V_627 , V_628 , V_629 ;
enum V_509 V_630 ;
enum V_631 V_632 ;
int V_92 ;
V_10 = F_175 ( V_26 , V_171 -> V_189 ) ;
if ( ! V_10 )
return F_251 ( V_26 , V_171 ) ;
V_629 . V_6 = F_123 ( V_298 -> V_345 ) ;
V_630 = V_629 . V_402 ;
if ( V_629 . V_402 == V_502 ) {
V_630 = V_10 -> V_473 [ V_503 ] & 4 ? V_398 : V_521 ;
F_129 ( V_38 , L_136 , F_280 ( V_630 ) ) ;
}
F_21 ( & V_10 -> V_26 -> V_27 ) ;
V_28:
V_627 = V_628 = F_281 ( V_10 ) ;
F_22 ( & V_10 -> V_26 -> V_27 ) ;
if ( V_627 . V_105 <= V_616 )
return - V_96 ;
if ( ( V_627 . V_397 == V_398 || V_627 . V_397 == V_521 ) &&
V_630 == V_435 &&
V_627 . V_105 > V_527 && V_627 . V_402 == V_435 ) {
if ( V_629 . V_105 > V_527 &&
V_629 . V_105 < V_346 )
V_630 = V_398 ;
else if ( V_627 . V_105 >= V_346 &&
V_629 . V_105 == V_527 ) {
if ( F_219 ( V_10 ) <= V_10 -> V_427 )
F_282 ( V_10 ) ;
return 0 ;
}
}
if ( V_627 . V_105 == V_425 && V_627 . V_402 == V_435 &&
V_629 . V_105 == V_527 && V_630 == V_435 ) {
F_283 ( V_10 ) ;
F_282 ( V_10 ) ;
return 0 ;
}
if ( V_627 . V_397 == V_435 && V_630 == V_398 &&
V_627 . V_105 == V_527 && V_629 . V_105 > V_346 )
V_630 = V_435 ;
if ( V_628 . V_105 == V_103 )
V_628 . V_105 = V_527 ;
if ( V_629 . V_105 == V_633 )
V_628 . V_105 = V_634 ;
if ( V_10 -> V_473 && V_629 . V_402 >= V_502 &&
F_137 ( V_10 , V_502 ) ) {
int V_635 ;
V_635 = ( V_627 . V_105 < V_527 ) ;
V_635 |= ( V_627 . V_105 == V_527 &&
( V_629 . V_402 == V_502 ||
V_627 . V_402 == V_502 ) ) ;
V_635 |= F_66 ( V_636 , & V_10 -> V_63 ) ;
V_635 |= ( V_627 . V_105 == V_527 &&
( V_629 . V_105 >= V_614 &&
V_629 . V_105 <= V_526 ) ) ;
if ( V_635 )
V_628 . V_105 = F_238 ( V_10 , V_629 . V_489 , V_630 ) ;
F_131 ( V_10 ) ;
if ( V_628 . V_105 == V_511 ) {
V_628 . V_105 = V_527 ;
if ( V_10 -> V_345 . V_402 == V_502 ) {
F_284 ( V_10 , F_69 ( V_402 , V_637 ) ) ;
} else if ( V_629 . V_402 == V_502 ) {
F_43 ( V_38 , L_137 ) ;
V_629 . V_402 = V_638 ;
V_630 = V_638 ;
} else {
if ( F_265 ( V_522 , & V_10 -> V_26 -> V_63 ) )
return - V_108 ;
F_49 ( V_627 . V_105 == V_103 ) ;
F_68 ( V_10 -> V_26 , F_69 ( V_105 , V_150 ) , V_107 ) ;
return - V_108 ;
}
}
}
F_21 ( & V_10 -> V_26 -> V_27 ) ;
if ( V_627 . V_6 != F_281 ( V_10 ) . V_6 )
goto V_28;
F_101 ( V_636 , & V_10 -> V_63 ) ;
V_628 . V_461 = V_629 . V_489 ;
V_628 . V_397 = V_630 ;
V_628 . V_617 = ( V_629 . V_618 | V_629 . V_619 ) ;
if ( ( V_628 . V_105 == V_527 || V_628 . V_105 == V_525 ) && V_628 . V_402 == V_502 )
V_628 . V_402 = V_10 -> V_515 . V_402 ;
V_632 = V_196 + ( V_627 . V_105 < V_527 && V_628 . V_105 >= V_527 ? 0 : V_107 ) ;
if ( V_628 . V_397 == V_521 && F_285 ( V_10 ) && V_628 . V_105 == V_527 && V_627 . V_105 < V_527 &&
F_66 ( V_639 , & V_10 -> V_63 ) ) {
F_22 ( & V_10 -> V_26 -> V_27 ) ;
F_43 ( V_38 , L_138 ) ;
F_286 ( V_10 -> V_26 ) ;
F_287 ( V_10 ) ;
F_101 ( V_639 , & V_10 -> V_63 ) ;
F_68 ( V_10 -> V_26 , F_288 ( V_105 , V_640 , V_641 , 0 ) , V_107 ) ;
return - V_108 ;
}
V_92 = F_269 ( V_10 , V_628 , V_632 , NULL ) ;
V_628 = F_281 ( V_10 ) ;
F_22 ( & V_10 -> V_26 -> V_27 ) ;
if ( V_92 < V_197 ) {
F_68 ( V_10 -> V_26 , F_69 ( V_105 , V_150 ) , V_107 ) ;
return - V_108 ;
}
if ( V_627 . V_105 > V_103 ) {
if ( V_628 . V_105 > V_527 && V_629 . V_105 <= V_527 &&
V_629 . V_402 != V_502 ) {
F_99 ( V_10 ) ;
F_100 ( V_10 ) ;
}
}
F_101 ( V_222 , & V_10 -> V_63 ) ;
F_262 ( V_10 ) ;
return 0 ;
}
static int F_289 ( struct V_94 * V_26 , struct V_170 * V_171 )
{
struct V_9 * V_10 ;
struct V_642 * V_298 = V_171 -> V_95 ;
V_10 = F_175 ( V_26 , V_171 -> V_189 ) ;
if ( ! V_10 )
return - V_108 ;
F_210 ( V_10 -> V_295 ,
V_10 -> V_345 . V_105 == V_643 ||
V_10 -> V_345 . V_105 == V_634 ||
V_10 -> V_345 . V_105 < V_527 ||
V_10 -> V_345 . V_402 < V_502 ) ;
if ( F_137 ( V_10 , V_502 ) ) {
F_268 ( V_10 , V_495 , F_176 ( V_298 -> V_471 ) ) ;
F_268 ( V_10 , V_472 , 0UL ) ;
F_272 ( V_10 , L_139 ) ;
F_290 ( V_10 , V_390 ) ;
F_131 ( V_10 ) ;
} else
F_43 ( V_38 , L_140 ) ;
return 0 ;
}
static int
F_291 ( struct V_9 * V_10 , unsigned int V_58 ,
unsigned long * V_298 , struct V_644 * V_645 )
{
unsigned int V_47 = V_554 -
F_93 ( V_10 -> V_26 ) ;
unsigned int V_646 = F_75 ( T_6 , V_47 / sizeof( * V_298 ) ,
V_645 -> V_647 - V_645 -> V_648 ) ;
unsigned int V_649 = V_646 * sizeof( * V_298 ) ;
int V_70 ;
if ( V_649 != V_58 ) {
F_43 ( V_38 , L_141 , V_55 , V_649 , V_58 ) ;
return - V_108 ;
}
if ( V_649 == 0 )
return 0 ;
V_70 = F_70 ( V_10 -> V_26 , V_298 , V_649 ) ;
if ( V_70 )
return V_70 ;
F_292 ( V_10 , V_645 -> V_648 , V_646 , V_298 ) ;
V_645 -> V_648 += V_646 ;
V_645 -> V_650 = V_645 -> V_648 * V_651 ;
if ( V_645 -> V_650 > V_645 -> V_652 )
V_645 -> V_650 = V_645 -> V_652 ;
return 1 ;
}
static enum V_653 F_293 ( struct V_654 * V_298 )
{
return (enum V_653 ) ( V_298 -> V_655 & 0x0f ) ;
}
static int F_294 ( struct V_654 * V_298 )
{
return ( V_298 -> V_655 & 0x80 ) != 0 ;
}
static int F_295 ( struct V_654 * V_298 )
{
return ( V_298 -> V_655 >> 4 ) & 0x7 ;
}
static int
F_296 ( struct V_9 * V_10 ,
struct V_654 * V_298 ,
struct V_644 * V_645 ,
unsigned int V_5 )
{
struct V_656 V_657 ;
T_2 V_658 ;
T_2 V_659 ;
T_2 V_4 ;
unsigned long V_201 = V_645 -> V_650 ;
unsigned long V_660 ;
int V_661 = F_294 ( V_298 ) ;
int V_662 ;
int V_494 ;
F_297 ( & V_657 , V_298 -> V_663 , V_5 , F_295 ( V_298 ) ) ;
V_494 = F_298 ( & V_657 , & V_658 , 64 ) ;
if ( V_494 < 0 )
return - V_108 ;
for ( V_662 = V_494 ; V_662 > 0 ; V_201 += V_659 , V_661 = ! V_661 ) {
V_494 = F_299 ( & V_659 , V_658 ) ;
if ( V_494 <= 0 )
return - V_108 ;
if ( V_661 ) {
V_660 = V_201 + V_659 - 1 ;
if ( V_660 >= V_645 -> V_652 ) {
F_43 ( V_38 , L_142 , V_660 ) ;
return - V_108 ;
}
F_300 ( V_10 , V_201 , V_660 ) ;
}
if ( V_662 < V_494 ) {
F_43 ( V_38 , L_143 ,
V_662 , V_494 , V_658 ,
( unsigned int ) ( V_657 . V_664 . V_355 - V_298 -> V_663 ) ,
( unsigned int ) V_657 . V_665 ) ;
return - V_108 ;
}
V_658 >>= V_494 ;
V_662 -= V_494 ;
V_494 = F_298 ( & V_657 , & V_4 , 64 - V_662 ) ;
if ( V_494 < 0 )
return - V_108 ;
V_658 |= V_4 << V_662 ;
V_662 += V_494 ;
}
V_645 -> V_650 = V_201 ;
F_301 ( V_645 ) ;
return ( V_201 != V_645 -> V_652 ) ;
}
static int
F_302 ( struct V_9 * V_10 ,
struct V_654 * V_298 ,
struct V_644 * V_645 ,
unsigned int V_5 )
{
if ( F_293 ( V_298 ) == V_666 )
return F_296 ( V_10 , V_298 , V_645 , V_5 - sizeof( * V_298 ) ) ;
F_43 ( V_38 , L_144 , V_298 -> V_655 ) ;
F_68 ( V_10 -> V_26 , F_69 ( V_105 , V_640 ) , V_107 ) ;
return - V_108 ;
}
void F_303 ( struct V_9 * V_10 ,
const char * V_667 , struct V_644 * V_645 )
{
unsigned int V_169 = F_93 ( V_10 -> V_26 ) ;
unsigned int V_47 = V_554 - V_169 ;
unsigned int V_668 =
V_169 * ( F_304 ( V_645 -> V_647 , V_47 ) + 1 ) +
V_645 -> V_647 * sizeof( unsigned long ) ;
unsigned int V_669 = V_645 -> V_670 [ 0 ] + V_645 -> V_670 [ 1 ] ;
unsigned int V_671 ;
if ( V_669 == 0 )
return;
if ( V_669 >= V_668 )
return;
V_671 = ( V_669 > V_672 / 1000 ) ? ( V_669 / ( V_668 / 1000 ) )
: ( 1000 * V_669 / V_668 ) ;
if ( V_671 > 1000 )
V_671 = 1000 ;
V_671 = 1000 - V_671 ;
F_129 ( V_38 , L_145
L_146 ,
V_667 ,
V_645 -> V_670 [ 1 ] , V_645 -> V_673 [ 1 ] ,
V_645 -> V_670 [ 0 ] , V_645 -> V_673 [ 0 ] ,
V_669 , V_671 / 10 , V_671 % 10 ) ;
}
static int F_305 ( struct V_94 * V_26 , struct V_170 * V_171 )
{
struct V_9 * V_10 ;
struct V_644 V_645 ;
int V_70 ;
V_10 = F_175 ( V_26 , V_171 -> V_189 ) ;
if ( ! V_10 )
return - V_108 ;
F_306 ( V_10 , L_147 , V_524 ) ;
V_645 = (struct V_644 ) {
. V_652 = F_226 ( V_10 ) ,
. V_647 = F_307 ( V_10 ) ,
} ;
for(; ; ) {
if ( V_171 -> V_168 == V_674 )
V_70 = F_291 ( V_10 , V_171 -> V_58 , V_171 -> V_95 , & V_645 ) ;
else if ( V_171 -> V_168 == V_675 ) {
struct V_654 * V_298 = V_171 -> V_95 ;
if ( V_171 -> V_58 > V_554 - F_93 ( V_26 ) ) {
F_43 ( V_38 , L_148 ) ;
V_70 = - V_108 ;
goto V_104;
}
if ( V_171 -> V_58 <= sizeof( * V_298 ) ) {
F_43 ( V_38 , L_149 , V_171 -> V_58 ) ;
V_70 = - V_108 ;
goto V_104;
}
V_70 = F_70 ( V_10 -> V_26 , V_298 , V_171 -> V_58 ) ;
if ( V_70 )
goto V_104;
V_70 = F_302 ( V_10 , V_298 , & V_645 , V_171 -> V_58 ) ;
} else {
F_33 ( V_38 , L_150 , V_171 -> V_168 ) ;
V_70 = - V_108 ;
goto V_104;
}
V_645 . V_673 [ V_171 -> V_168 == V_674 ] ++ ;
V_645 . V_670 [ V_171 -> V_168 == V_674 ] += F_93 ( V_26 ) + V_171 -> V_58 ;
if ( V_70 <= 0 ) {
if ( V_70 < 0 )
goto V_104;
break;
}
V_70 = F_125 ( V_10 -> V_26 , V_171 ) ;
if ( V_70 )
goto V_104;
}
F_303 ( V_10 , L_151 , & V_645 ) ;
if ( V_10 -> V_345 . V_105 == V_526 ) {
enum V_194 V_92 ;
V_70 = F_308 ( V_10 ) ;
if ( V_70 )
goto V_104;
V_92 = F_309 ( V_10 , F_69 ( V_105 , V_643 ) , V_196 ) ;
F_49 ( V_92 == V_197 ) ;
} else if ( V_10 -> V_345 . V_105 != V_525 ) {
F_129 ( V_38 , L_152 ,
F_239 ( V_10 -> V_345 . V_105 ) ) ;
}
V_70 = 0 ;
V_104:
F_310 ( V_10 ) ;
if ( ! V_70 && V_10 -> V_345 . V_105 == V_525 )
F_290 ( V_10 , V_346 ) ;
return V_70 ;
}
static int F_311 ( struct V_94 * V_26 , struct V_170 * V_171 )
{
F_72 ( V_26 , L_153 ,
V_171 -> V_168 , V_171 -> V_58 ) ;
return F_250 ( V_26 , V_171 ) ;
}
static int F_312 ( struct V_94 * V_26 , struct V_170 * V_171 )
{
F_313 ( V_26 -> V_95 . V_76 ) ;
return 0 ;
}
static int F_314 ( struct V_94 * V_26 , struct V_170 * V_171 )
{
struct V_9 * V_10 ;
struct V_676 * V_298 = V_171 -> V_95 ;
V_10 = F_175 ( V_26 , V_171 -> V_189 ) ;
if ( ! V_10 )
return - V_108 ;
switch ( V_10 -> V_345 . V_105 ) {
case V_643 :
case V_526 :
case V_634 :
break;
default:
F_43 ( V_38 , L_154 ,
F_239 ( V_10 -> V_345 . V_105 ) ) ;
}
F_211 ( V_10 , F_176 ( V_298 -> V_46 ) , F_123 ( V_298 -> V_434 ) ) ;
return 0 ;
}
static void F_315 ( struct V_94 * V_26 )
{
struct V_170 V_171 ;
T_6 V_677 ;
int V_70 ;
while ( F_110 ( & V_26 -> V_208 ) == V_678 ) {
struct V_679 * V_168 ;
F_316 ( & V_26 -> V_208 ) ;
if ( F_125 ( V_26 , & V_171 ) )
goto V_680;
V_168 = & V_681 [ V_171 . V_168 ] ;
if ( F_177 ( V_171 . V_168 >= F_317 ( V_681 ) || ! V_168 -> V_682 ) ) {
F_65 ( V_26 , L_155 ,
F_252 ( V_171 . V_168 ) , V_171 . V_168 ) ;
goto V_680;
}
V_677 = V_168 -> V_683 ;
if ( V_171 . V_58 > V_677 && ! V_168 -> V_684 ) {
F_65 ( V_26 , L_156 ,
F_252 ( V_171 . V_168 ) , V_171 . V_58 ) ;
goto V_680;
}
if ( V_677 ) {
V_70 = F_71 ( V_26 , V_171 . V_95 , V_677 ) ;
if ( V_70 )
goto V_680;
V_171 . V_58 -= V_677 ;
}
V_70 = V_168 -> V_682 ( V_26 , & V_171 ) ;
if ( V_70 ) {
F_65 ( V_26 , L_157 ,
F_252 ( V_171 . V_168 ) , V_70 , V_171 . V_58 ) ;
goto V_680;
}
}
return;
V_680:
F_68 ( V_26 , F_69 ( V_105 , V_640 ) , V_107 ) ;
}
void F_318 ( struct V_94 * V_26 )
{
struct V_685 V_686 ;
V_686 . V_22 . V_73 = V_687 ;
V_686 . V_22 . V_26 = V_26 ;
F_319 ( & V_686 . V_688 ) ;
F_320 ( & V_26 -> V_689 , & V_686 . V_22 ) ;
F_321 ( & V_686 . V_688 ) ;
}
static void F_322 ( struct V_94 * V_26 )
{
struct V_9 * V_10 ;
enum V_506 V_690 ;
int V_189 ;
if ( V_26 -> V_102 == V_691 )
return;
F_68 ( V_26 , F_69 ( V_105 , V_692 ) , V_107 ) ;
F_323 ( & V_26 -> V_224 ) ;
F_324 ( V_26 ) ;
F_27 () ;
F_115 (&tconn->volumes, mdev, vnr) {
F_116 ( & V_10 -> V_221 ) ;
F_29 () ;
F_325 ( V_10 ) ;
F_119 ( & V_10 -> V_221 , & V_223 ) ;
F_27 () ;
}
F_29 () ;
if ( ! F_56 ( & V_26 -> V_261 -> V_23 ) )
F_65 ( V_26 , L_158 ) ;
F_45 ( & V_26 -> V_261 -> V_250 , 0 ) ;
V_26 -> V_693 . V_694 = false ;
F_64 ( V_26 , L_159 ) ;
if ( F_326 ( V_26 ) == V_462 && F_327 ( V_26 ) >= V_695 )
F_328 ( V_26 ) ;
F_21 ( & V_26 -> V_27 ) ;
V_690 = V_26 -> V_102 ;
if ( V_690 >= V_696 )
F_207 ( V_26 , F_69 ( V_105 , V_696 ) , V_196 ) ;
F_22 ( & V_26 -> V_27 ) ;
if ( V_690 == V_150 )
F_68 ( V_26 , F_69 ( V_105 , V_691 ) , V_196 | V_107 ) ;
}
static int F_325 ( struct V_9 * V_10 )
{
unsigned int V_6 ;
F_21 ( & V_10 -> V_26 -> V_27 ) ;
F_55 ( V_10 , & V_10 -> V_296 ) ;
F_55 ( V_10 , & V_10 -> V_325 ) ;
F_55 ( V_10 , & V_10 -> V_463 ) ;
F_22 ( & V_10 -> V_26 -> V_27 ) ;
F_329 ( V_10 ) ;
V_10 -> V_459 = 0 ;
V_10 -> V_427 = 0 ;
F_45 ( & V_10 -> V_697 , 0 ) ;
F_39 ( & V_10 -> V_295 ) ;
F_330 ( & V_10 -> V_698 ) ;
F_331 ( ( unsigned long ) V_10 ) ;
F_332 ( V_10 ) ;
F_53 ( V_10 ) ;
F_332 ( V_10 ) ;
F_329 ( V_10 ) ;
F_48 ( V_10 -> V_473 ) ;
V_10 -> V_473 = NULL ;
if ( ! F_285 ( V_10 ) )
F_286 ( V_10 -> V_26 ) ;
F_262 ( V_10 ) ;
F_210 ( V_10 -> V_295 , ! F_66 ( V_699 , & V_10 -> V_63 ) ) ;
V_6 = F_51 ( V_10 , & V_10 -> V_69 ) ;
if ( V_6 )
F_129 ( V_38 , L_160 , V_6 ) ;
V_6 = F_30 ( & V_10 -> V_41 ) ;
if ( V_6 )
F_129 ( V_38 , L_161 , V_6 ) ;
V_6 = F_30 ( & V_10 -> V_34 ) ;
if ( V_6 )
F_129 ( V_38 , L_162 , V_6 ) ;
F_49 ( F_56 ( & V_10 -> V_463 ) ) ;
F_49 ( F_56 ( & V_10 -> V_296 ) ) ;
F_49 ( F_56 ( & V_10 -> V_325 ) ) ;
F_49 ( F_56 ( & V_10 -> V_71 ) ) ;
return 0 ;
}
static int F_333 ( struct V_94 * V_26 )
{
struct V_166 * V_77 ;
struct V_700 * V_298 ;
V_77 = & V_26 -> V_95 ;
V_298 = F_90 ( V_26 , V_77 ) ;
if ( ! V_298 )
return - V_108 ;
memset ( V_298 , 0 , sizeof( * V_298 ) ) ;
V_298 -> V_701 = F_121 ( V_702 ) ;
V_298 -> V_703 = F_121 ( V_704 ) ;
return F_91 ( V_26 , V_77 , V_705 , sizeof( * V_298 ) , NULL , 0 ) ;
}
static int F_112 ( struct V_94 * V_26 )
{
struct V_700 * V_298 ;
const int F_153 = sizeof( struct V_700 ) ;
struct V_170 V_171 ;
int V_70 ;
V_70 = F_333 ( V_26 ) ;
if ( V_70 )
return 0 ;
V_70 = F_125 ( V_26 , & V_171 ) ;
if ( V_70 )
return 0 ;
if ( V_171 . V_168 != V_705 ) {
F_65 ( V_26 , L_163 ,
F_252 ( V_171 . V_168 ) , V_171 . V_168 ) ;
return - 1 ;
}
if ( V_171 . V_58 != F_153 ) {
F_65 ( V_26 , L_164 ,
F_153 , V_171 . V_58 ) ;
return - 1 ;
}
V_298 = V_171 . V_95 ;
V_70 = F_71 ( V_26 , V_298 , F_153 ) ;
if ( V_70 )
return 0 ;
V_298 -> V_701 = F_123 ( V_298 -> V_701 ) ;
V_298 -> V_703 = F_123 ( V_298 -> V_703 ) ;
if ( V_298 -> V_703 == 0 )
V_298 -> V_703 = V_298 -> V_701 ;
if ( V_704 < V_298 -> V_701 ||
V_702 > V_298 -> V_703 )
goto V_706;
V_26 -> V_180 = F_75 ( int , V_704 , V_298 -> V_703 ) ;
F_64 ( V_26 , L_165
L_166 , V_26 -> V_180 ) ;
return 1 ;
V_706:
F_65 ( V_26 , L_167
L_168 ,
V_702 , V_704 ,
V_298 -> V_701 , V_298 -> V_703 ) ;
return - 1 ;
}
static int F_113 ( struct V_94 * V_26 )
{
F_65 ( V_26 , L_169 ) ;
F_65 ( V_26 , L_170 ) ;
return - 1 ;
}
static int F_113 ( struct V_94 * V_26 )
{
struct V_166 * V_77 ;
char V_707 [ V_708 ] ;
struct V_709 V_710 ;
char * V_711 = NULL ;
char * V_712 = NULL ;
char * V_713 = NULL ;
unsigned int V_714 ;
char V_715 [ V_539 ] ;
unsigned int V_716 ;
struct V_717 V_718 ;
struct V_170 V_171 ;
struct V_29 * V_30 ;
int V_70 , V_92 ;
F_27 () ;
V_30 = F_28 ( V_26 -> V_29 ) ;
V_714 = strlen ( V_30 -> V_719 ) ;
memcpy ( V_715 , V_30 -> V_719 , V_714 ) ;
F_29 () ;
V_718 . V_553 = V_26 -> V_217 ;
V_718 . V_63 = 0 ;
V_92 = F_334 ( V_26 -> V_217 , ( V_720 * ) V_715 , V_714 ) ;
if ( V_92 ) {
F_65 ( V_26 , L_171 , V_92 ) ;
V_92 = - 1 ;
goto V_57;
}
F_335 ( V_707 , V_708 ) ;
V_77 = & V_26 -> V_95 ;
if ( ! F_90 ( V_26 , V_77 ) ) {
V_92 = 0 ;
goto V_57;
}
V_92 = ! F_91 ( V_26 , V_77 , V_721 , 0 ,
V_707 , V_708 ) ;
if ( ! V_92 )
goto V_57;
V_70 = F_125 ( V_26 , & V_171 ) ;
if ( V_70 ) {
V_92 = 0 ;
goto V_57;
}
if ( V_171 . V_168 != V_721 ) {
F_65 ( V_26 , L_172 ,
F_252 ( V_171 . V_168 ) , V_171 . V_168 ) ;
V_92 = 0 ;
goto V_57;
}
if ( V_171 . V_58 > V_708 * 2 ) {
F_65 ( V_26 , L_173 ) ;
V_92 = - 1 ;
goto V_57;
}
V_713 = F_148 ( V_171 . V_58 , V_211 ) ;
if ( V_713 == NULL ) {
F_65 ( V_26 , L_174 ) ;
V_92 = - 1 ;
goto V_57;
}
V_70 = F_71 ( V_26 , V_713 , V_171 . V_58 ) ;
if ( V_70 ) {
V_92 = 0 ;
goto V_57;
}
V_716 = F_152 ( V_26 -> V_217 ) ;
V_711 = F_148 ( V_716 , V_211 ) ;
if ( V_711 == NULL ) {
F_65 ( V_26 , L_175 ) ;
V_92 = - 1 ;
goto V_57;
}
F_336 ( & V_710 , 1 ) ;
F_337 ( & V_710 , V_713 , V_171 . V_58 ) ;
V_92 = F_338 ( & V_718 , & V_710 , V_710 . V_234 , V_711 ) ;
if ( V_92 ) {
F_65 ( V_26 , L_176 , V_92 ) ;
V_92 = - 1 ;
goto V_57;
}
if ( ! F_90 ( V_26 , V_77 ) ) {
V_92 = 0 ;
goto V_57;
}
V_92 = ! F_91 ( V_26 , V_77 , V_722 , 0 ,
V_711 , V_716 ) ;
if ( ! V_92 )
goto V_57;
V_70 = F_125 ( V_26 , & V_171 ) ;
if ( V_70 ) {
V_92 = 0 ;
goto V_57;
}
if ( V_171 . V_168 != V_722 ) {
F_65 ( V_26 , L_177 ,
F_252 ( V_171 . V_168 ) , V_171 . V_168 ) ;
V_92 = 0 ;
goto V_57;
}
if ( V_171 . V_58 != V_716 ) {
F_65 ( V_26 , L_178 ) ;
V_92 = 0 ;
goto V_57;
}
V_70 = F_71 ( V_26 , V_711 , V_716 ) ;
if ( V_70 ) {
V_92 = 0 ;
goto V_57;
}
V_712 = F_148 ( V_716 , V_211 ) ;
if ( V_712 == NULL ) {
F_65 ( V_26 , L_179 ) ;
V_92 = - 1 ;
goto V_57;
}
F_337 ( & V_710 , V_707 , V_708 ) ;
V_92 = F_338 ( & V_718 , & V_710 , V_710 . V_234 , V_712 ) ;
if ( V_92 ) {
F_65 ( V_26 , L_176 , V_92 ) ;
V_92 = - 1 ;
goto V_57;
}
V_92 = ! memcmp ( V_711 , V_712 , V_716 ) ;
if ( V_92 )
F_64 ( V_26 , L_180 ,
V_716 ) ;
else
V_92 = - 1 ;
V_57:
F_48 ( V_713 ) ;
F_48 ( V_711 ) ;
F_48 ( V_712 ) ;
return V_92 ;
}
int F_339 ( struct V_723 * V_724 )
{
struct V_94 * V_26 = V_724 -> V_26 ;
int V_191 ;
F_64 ( V_26 , L_181 ) ;
do {
V_191 = F_103 ( V_26 ) ;
if ( V_191 == 0 ) {
F_322 ( V_26 ) ;
F_106 ( V_100 ) ;
}
if ( V_191 == - 1 ) {
F_72 ( V_26 , L_182 ) ;
F_68 ( V_26 , F_69 ( V_105 , V_150 ) , V_107 ) ;
}
} while ( V_191 == 0 );
if ( V_191 > 0 )
F_315 ( V_26 ) ;
F_322 ( V_26 ) ;
F_64 ( V_26 , L_183 ) ;
return 0 ;
}
static int F_340 ( struct V_94 * V_26 , struct V_170 * V_171 )
{
struct V_725 * V_298 = V_171 -> V_95 ;
int V_726 = F_123 ( V_298 -> V_726 ) ;
if ( V_726 >= V_197 ) {
F_107 ( V_727 , & V_26 -> V_63 ) ;
} else {
F_107 ( V_728 , & V_26 -> V_63 ) ;
F_65 ( V_26 , L_184 ,
F_341 ( V_726 ) , V_726 ) ;
}
F_39 ( & V_26 -> V_101 ) ;
return 0 ;
}
static int F_342 ( struct V_94 * V_26 , struct V_170 * V_171 )
{
struct V_9 * V_10 ;
struct V_725 * V_298 = V_171 -> V_95 ;
int V_726 = F_123 ( V_298 -> V_726 ) ;
V_10 = F_175 ( V_26 , V_171 -> V_189 ) ;
if ( ! V_10 )
return - V_108 ;
if ( F_66 ( V_729 , & V_26 -> V_63 ) ) {
F_49 ( V_26 -> V_180 < 100 ) ;
return F_340 ( V_26 , V_171 ) ;
}
if ( V_726 >= V_197 ) {
F_107 ( V_730 , & V_10 -> V_63 ) ;
} else {
F_107 ( V_731 , & V_10 -> V_63 ) ;
F_43 ( V_38 , L_184 ,
F_341 ( V_726 ) , V_726 ) ;
}
F_39 ( & V_10 -> V_732 ) ;
return 0 ;
}
static int F_343 ( struct V_94 * V_26 , struct V_170 * V_171 )
{
return F_344 ( V_26 ) ;
}
static int F_345 ( struct V_94 * V_26 , struct V_170 * V_171 )
{
V_26 -> V_200 . V_76 -> V_111 -> V_137 = V_26 -> V_29 -> V_215 * V_100 ;
if ( ! F_346 ( V_733 , & V_26 -> V_63 ) )
F_39 ( & V_26 -> V_101 ) ;
return 0 ;
}
static int F_347 ( struct V_94 * V_26 , struct V_170 * V_171 )
{
struct V_9 * V_10 ;
struct V_734 * V_298 = V_171 -> V_95 ;
T_3 V_46 = F_176 ( V_298 -> V_46 ) ;
int V_434 = F_123 ( V_298 -> V_434 ) ;
V_10 = F_175 ( V_26 , V_171 -> V_189 ) ;
if ( ! V_10 )
return - V_108 ;
F_49 ( V_10 -> V_26 -> V_180 >= 89 ) ;
F_192 ( V_10 , F_123 ( V_298 -> V_386 ) ) ;
if ( F_127 ( V_10 ) ) {
F_348 ( V_10 , V_46 ) ;
F_165 ( V_10 , V_46 , V_434 ) ;
V_10 -> V_735 += ( V_434 >> V_736 ) ;
F_131 ( V_10 ) ;
}
F_170 ( V_10 ) ;
F_36 ( V_434 >> 9 , & V_10 -> V_337 ) ;
return 0 ;
}
static int
F_349 ( struct V_9 * V_10 , T_2 V_45 , T_3 V_46 ,
struct V_329 * V_330 , const char * V_332 ,
enum V_737 V_117 , bool V_331 )
{
struct V_310 * V_311 ;
struct V_378 V_379 ;
F_21 ( & V_10 -> V_26 -> V_27 ) ;
V_311 = F_172 ( V_10 , V_330 , V_45 , V_46 , V_331 , V_332 ) ;
if ( F_177 ( ! V_311 ) ) {
F_22 ( & V_10 -> V_26 -> V_27 ) ;
return - V_108 ;
}
F_184 ( V_311 , V_117 , & V_379 ) ;
F_22 ( & V_10 -> V_26 -> V_27 ) ;
if ( V_379 . V_278 )
F_200 ( V_10 , & V_379 ) ;
return 0 ;
}
static int F_350 ( struct V_94 * V_26 , struct V_170 * V_171 )
{
struct V_9 * V_10 ;
struct V_734 * V_298 = V_171 -> V_95 ;
T_3 V_46 = F_176 ( V_298 -> V_46 ) ;
int V_434 = F_123 ( V_298 -> V_434 ) ;
enum V_737 V_117 ;
V_10 = F_175 ( V_26 , V_171 -> V_189 ) ;
if ( ! V_10 )
return - V_108 ;
F_192 ( V_10 , F_123 ( V_298 -> V_386 ) ) ;
if ( V_298 -> V_64 == V_324 ) {
F_165 ( V_10 , V_46 , V_434 ) ;
F_170 ( V_10 ) ;
return 0 ;
}
switch ( V_171 -> V_168 ) {
case V_322 :
V_117 = V_738 ;
break;
case V_349 :
V_117 = V_739 ;
break;
case V_396 :
V_117 = V_740 ;
break;
case V_353 :
V_117 = V_341 ;
break;
case V_354 :
V_117 = V_741 ;
break;
default:
F_224 () ;
}
return F_349 ( V_10 , V_298 -> V_64 , V_46 ,
& V_10 -> V_294 , V_55 ,
V_117 , false ) ;
}
static int F_351 ( struct V_94 * V_26 , struct V_170 * V_171 )
{
struct V_9 * V_10 ;
struct V_734 * V_298 = V_171 -> V_95 ;
T_3 V_46 = F_176 ( V_298 -> V_46 ) ;
int V_58 = F_123 ( V_298 -> V_434 ) ;
int V_70 ;
V_10 = F_175 ( V_26 , V_171 -> V_189 ) ;
if ( ! V_10 )
return - V_108 ;
F_192 ( V_10 , F_123 ( V_298 -> V_386 ) ) ;
if ( V_298 -> V_64 == V_324 ) {
F_170 ( V_10 ) ;
F_167 ( V_10 , V_46 , V_58 ) ;
return 0 ;
}
V_70 = F_349 ( V_10 , V_298 -> V_64 , V_46 ,
& V_10 -> V_294 , V_55 ,
V_380 , true ) ;
if ( V_70 ) {
F_211 ( V_10 , V_46 , V_58 ) ;
}
return 0 ;
}
static int F_352 ( struct V_94 * V_26 , struct V_170 * V_171 )
{
struct V_9 * V_10 ;
struct V_734 * V_298 = V_171 -> V_95 ;
T_3 V_46 = F_176 ( V_298 -> V_46 ) ;
V_10 = F_175 ( V_26 , V_171 -> V_189 ) ;
if ( ! V_10 )
return - V_108 ;
F_192 ( V_10 , F_123 ( V_298 -> V_386 ) ) ;
F_43 ( V_38 , L_185 ,
( unsigned long long ) V_46 , F_123 ( V_298 -> V_434 ) ) ;
return F_349 ( V_10 , V_298 -> V_64 , V_46 ,
& V_10 -> V_334 , V_55 ,
V_380 , false ) ;
}
static int F_353 ( struct V_94 * V_26 , struct V_170 * V_171 )
{
struct V_9 * V_10 ;
T_3 V_46 ;
int V_58 ;
struct V_734 * V_298 = V_171 -> V_95 ;
V_10 = F_175 ( V_26 , V_171 -> V_189 ) ;
if ( ! V_10 )
return - V_108 ;
V_46 = F_176 ( V_298 -> V_46 ) ;
V_58 = F_123 ( V_298 -> V_434 ) ;
F_192 ( V_10 , F_123 ( V_298 -> V_386 ) ) ;
F_170 ( V_10 ) ;
if ( F_137 ( V_10 , V_637 ) ) {
F_348 ( V_10 , V_46 ) ;
switch ( V_171 -> V_168 ) {
case V_441 :
F_167 ( V_10 , V_46 , V_58 ) ;
case V_742 :
break;
default:
F_224 () ;
}
F_131 ( V_10 ) ;
}
return 0 ;
}
static int F_354 ( struct V_94 * V_26 , struct V_170 * V_171 )
{
struct V_743 * V_298 = V_171 -> V_95 ;
struct V_9 * V_10 ;
int V_189 ;
F_355 ( V_26 , V_298 -> V_299 , F_123 ( V_298 -> V_744 ) ) ;
F_27 () ;
F_115 (&tconn->volumes, mdev, vnr) {
if ( V_10 -> V_345 . V_105 == V_633 &&
F_30 ( & V_10 -> V_185 ) == 0 &&
! F_346 ( V_745 , & V_10 -> V_63 ) ) {
V_10 -> V_746 . V_747 = V_187 + V_100 ;
F_356 ( & V_10 -> V_746 ) ;
}
}
F_29 () ;
return 0 ;
}
static int F_357 ( struct V_94 * V_26 , struct V_170 * V_171 )
{
struct V_9 * V_10 ;
struct V_734 * V_298 = V_171 -> V_95 ;
struct V_319 * V_22 ;
T_3 V_46 ;
int V_58 ;
V_10 = F_175 ( V_26 , V_171 -> V_189 ) ;
if ( ! V_10 )
return - V_108 ;
V_46 = F_176 ( V_298 -> V_46 ) ;
V_58 = F_123 ( V_298 -> V_434 ) ;
F_192 ( V_10 , F_123 ( V_298 -> V_386 ) ) ;
if ( F_176 ( V_298 -> V_64 ) == V_748 )
F_358 ( V_10 , V_46 , V_58 ) ;
else
F_283 ( V_10 ) ;
if ( ! F_127 ( V_10 ) )
return 0 ;
F_348 ( V_10 , V_46 ) ;
F_170 ( V_10 ) ;
-- V_10 -> V_426 ;
if ( ( V_10 -> V_426 & 0x200 ) == 0x200 )
F_359 ( V_10 , V_10 -> V_426 ) ;
if ( V_10 -> V_426 == 0 ) {
V_22 = F_148 ( sizeof( * V_22 ) , V_211 ) ;
if ( V_22 ) {
V_22 -> V_73 = V_749 ;
V_22 -> V_10 = V_10 ;
F_320 ( & V_10 -> V_26 -> V_689 , V_22 ) ;
} else {
F_43 ( V_38 , L_186 ) ;
F_283 ( V_10 ) ;
F_282 ( V_10 ) ;
}
}
F_131 ( V_10 ) ;
return 0 ;
}
static int F_360 ( struct V_94 * V_26 , struct V_170 * V_171 )
{
return 0 ;
}
static int F_361 ( struct V_94 * V_26 )
{
struct V_9 * V_10 ;
int V_189 , V_750 = 0 ;
do {
F_101 ( V_751 , & V_26 -> V_63 ) ;
F_108 ( V_37 ) ;
F_27 () ;
F_115 (&tconn->volumes, mdev, vnr) {
F_116 ( & V_10 -> V_221 ) ;
F_29 () ;
if ( F_53 ( V_10 ) ) {
F_119 ( & V_10 -> V_221 , & V_223 ) ;
return 1 ;
}
F_119 ( & V_10 -> V_221 , & V_223 ) ;
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
int F_362 ( struct V_723 * V_724 )
{
struct V_94 * V_26 = V_724 -> V_26 ;
struct V_752 * V_168 = NULL ;
struct V_170 V_171 ;
int V_92 ;
void * V_78 = V_26 -> V_200 . V_172 ;
int V_753 = 0 ;
unsigned int V_169 = F_93 ( V_26 ) ;
int F_153 = V_169 ;
bool V_754 = false ;
struct V_29 * V_30 ;
int V_99 , V_755 , V_215 ;
struct V_756 V_757 = { . V_758 = 2 } ;
V_92 = F_363 ( V_37 , V_759 , & V_757 ) ;
if ( V_92 < 0 )
F_65 ( V_26 , L_187 , V_92 ) ;
while ( F_110 ( V_724 ) == V_678 ) {
F_316 ( V_724 ) ;
F_27 () ;
V_30 = F_28 ( V_26 -> V_29 ) ;
V_99 = V_30 -> V_99 ;
V_755 = V_30 -> V_755 ;
V_215 = V_30 -> V_215 ;
F_29 () ;
if ( F_265 ( V_760 , & V_26 -> V_63 ) ) {
if ( F_364 ( V_26 ) ) {
F_65 ( V_26 , L_188 ) ;
goto V_570;
}
V_26 -> V_200 . V_76 -> V_111 -> V_137 = V_99 * V_100 / 10 ;
V_754 = true ;
}
if ( V_755 )
F_365 ( V_26 -> V_200 . V_76 ) ;
if ( F_361 ( V_26 ) ) {
F_65 ( V_26 , L_189 ) ;
goto V_570;
}
if ( V_755 )
F_366 ( V_26 -> V_200 . V_76 ) ;
if ( F_32 ( V_37 ) )
continue;
V_92 = F_59 ( V_26 -> V_200 . V_76 , V_78 , F_153 - V_753 , 0 ) ;
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
F_65 ( V_26 , L_190 ) ;
goto V_570;
} else if ( V_92 == - V_143 ) {
if ( F_367 ( V_26 -> V_216 ,
V_187 - V_26 -> V_200 . V_76 -> V_111 -> V_137 ) )
continue;
if ( V_754 ) {
F_65 ( V_26 , L_191 ) ;
goto V_570;
}
F_107 ( V_760 , & V_26 -> V_63 ) ;
continue;
} else if ( V_92 == - V_145 ) {
continue;
} else {
F_65 ( V_26 , L_7 , V_92 ) ;
goto V_570;
}
if ( V_753 == F_153 && V_168 == NULL ) {
if ( F_94 ( V_26 , V_26 -> V_200 . V_172 , & V_171 ) )
goto V_570;
V_168 = & V_761 [ V_171 . V_168 ] ;
if ( V_171 . V_168 >= F_317 ( V_761 ) || ! V_168 -> V_682 ) {
F_65 ( V_26 , L_192 ,
F_252 ( V_171 . V_168 ) , V_171 . V_168 ) ;
goto V_549;
}
F_153 = V_169 + V_168 -> V_683 ;
if ( V_171 . V_58 != F_153 - V_169 ) {
F_65 ( V_26 , L_193 ,
V_171 . V_168 , V_171 . V_58 ) ;
goto V_570;
}
}
if ( V_753 == F_153 ) {
bool V_70 ;
V_70 = V_168 -> V_682 ( V_26 , & V_171 ) ;
if ( V_70 ) {
F_65 ( V_26 , L_194 , V_168 -> V_682 ) ;
goto V_570;
}
V_26 -> V_216 = V_187 ;
if ( V_168 == & V_761 [ V_762 ] ) {
V_26 -> V_200 . V_76 -> V_111 -> V_137 = V_215 * V_100 ;
V_754 = false ;
}
V_78 = V_26 -> V_200 . V_172 ;
V_753 = 0 ;
F_153 = V_169 ;
V_168 = NULL ;
}
}
if ( 0 ) {
V_570:
F_68 ( V_26 , F_69 ( V_105 , V_692 ) , V_107 ) ;
F_368 ( V_26 ) ;
}
if ( 0 ) {
V_549:
F_68 ( V_26 , F_69 ( V_105 , V_150 ) , V_107 ) ;
}
F_101 ( V_751 , & V_26 -> V_63 ) ;
F_64 ( V_26 , L_195 ) ;
return 0 ;
}
