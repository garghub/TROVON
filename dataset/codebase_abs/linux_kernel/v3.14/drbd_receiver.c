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
F_29 () ;
F_117 ( V_10 -> V_179 ) ;
F_118 ( V_10 -> V_179 ) ;
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
V_278 -> V_284 . V_285 = V_46 ;
V_278 -> V_286 = V_10 -> V_243 -> V_244 ;
V_278 -> V_287 = V_276 ;
V_278 -> V_288 = V_19 ;
V_278 -> V_289 = V_290 ;
V_278 -> V_291 = V_279 ;
V_279 = V_278 ;
++ V_281 ;
F_140 (page) {
unsigned V_5 = F_75 ( unsigned , V_280 , V_43 ) ;
if ( ! F_141 ( V_278 , V_1 , V_5 , 0 ) ) {
if ( V_278 -> V_292 == 0 ) {
F_43 ( V_38 ,
L_31
L_32 ,
V_5 , ( V_293 ) V_278 -> V_284 . V_285 ) ;
V_70 = - V_294 ;
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
V_279 = V_279 -> V_291 ;
V_278 -> V_291 = NULL ;
F_142 ( V_10 , V_277 , V_278 ) ;
} while ( V_279 );
return 0 ;
V_57:
while ( V_279 ) {
V_278 = V_279 ;
V_279 = V_279 -> V_291 ;
F_143 ( V_278 ) ;
}
return V_70 ;
}
static void F_144 ( struct V_9 * V_10 ,
struct V_18 * V_19 )
{
struct V_295 * V_6 = & V_19 -> V_6 ;
F_145 ( & V_10 -> V_296 , V_6 ) ;
F_44 ( V_6 ) ;
if ( V_6 -> V_59 )
F_39 ( & V_10 -> V_297 ) ;
}
void F_146 ( struct V_94 * V_26 )
{
struct V_9 * V_10 ;
int V_189 ;
F_27 () ;
F_115 (&tconn->volumes, mdev, vnr) {
F_116 ( & V_10 -> V_221 ) ;
F_29 () ;
F_58 ( V_10 , & V_10 -> V_298 ) ;
F_119 ( & V_10 -> V_221 , & V_223 ) ;
F_27 () ;
}
F_29 () ;
}
static int F_147 ( struct V_94 * V_26 , struct V_170 * V_171 )
{
int V_92 ;
struct V_299 * V_300 = V_171 -> V_95 ;
struct V_247 * V_60 ;
V_26 -> V_261 -> V_260 = V_300 -> V_301 ;
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
const T_3 V_302 = F_151 ( V_10 -> V_303 ) ;
struct V_18 * V_19 ;
struct V_1 * V_1 ;
int V_304 , V_280 , V_70 ;
void * V_305 = V_10 -> V_26 -> V_306 ;
void * V_307 = V_10 -> V_26 -> V_308 ;
unsigned long * V_95 ;
V_304 = 0 ;
if ( V_10 -> V_26 -> V_309 ) {
V_304 = F_152 ( V_10 -> V_26 -> V_309 ) ;
V_70 = F_71 ( V_10 -> V_26 , V_305 , V_304 ) ;
if ( V_70 )
return NULL ;
V_47 -= V_304 ;
}
if ( ! F_153 ( F_154 ( V_47 , 512 ) ) )
return NULL ;
if ( ! F_153 ( V_47 <= V_42 ) )
return NULL ;
if ( V_46 + ( V_47 >> 9 ) > V_302 ) {
F_43 ( V_38 , L_35
L_36 ,
( unsigned long long ) V_302 ,
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
if ( F_41 ( V_10 , V_310 ) ) {
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
if ( V_304 ) {
F_157 ( V_10 , V_10 -> V_26 -> V_309 , V_19 , V_307 ) ;
if ( memcmp ( V_305 , V_307 , V_304 ) ) {
F_43 ( V_38 , L_38 ,
( unsigned long long ) V_46 , V_47 ) ;
F_54 ( V_10 , V_19 ) ;
return NULL ;
}
}
V_10 -> V_311 += V_47 >> 9 ;
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
static int F_159 ( struct V_9 * V_10 , struct V_312 * V_313 ,
T_3 V_46 , int V_47 )
{
struct V_314 V_315 ;
struct V_316 V_317 ;
struct V_278 * V_278 ;
int V_304 , V_70 , F_153 ;
void * V_305 = V_10 -> V_26 -> V_306 ;
void * V_307 = V_10 -> V_26 -> V_308 ;
V_304 = 0 ;
if ( V_10 -> V_26 -> V_309 ) {
V_304 = F_152 ( V_10 -> V_26 -> V_309 ) ;
V_70 = F_71 ( V_10 -> V_26 , V_305 , V_304 ) ;
if ( V_70 )
return V_70 ;
V_47 -= V_304 ;
}
V_10 -> V_311 += V_47 >> 9 ;
V_278 = V_313 -> V_318 ;
F_49 ( V_46 == V_278 -> V_284 . V_285 ) ;
F_160 (bvec, bio, iter) {
void * V_319 = F_155 ( V_315 . V_320 ) + V_315 . V_321 ;
F_153 = F_75 ( int , V_47 , V_315 . V_322 ) ;
V_70 = F_71 ( V_10 -> V_26 , V_319 , F_153 ) ;
F_156 ( V_315 . V_320 ) ;
if ( V_70 )
return V_70 ;
V_47 -= F_153 ;
}
if ( V_304 ) {
F_161 ( V_10 , V_10 -> V_26 -> V_309 , V_278 , V_307 ) ;
if ( memcmp ( V_305 , V_307 , V_304 ) ) {
F_43 ( V_38 , L_39 ) ;
return - V_231 ;
}
}
F_49 ( V_47 == 0 ) ;
return 0 ;
}
static int F_162 ( struct V_323 * V_22 , int V_324 )
{
struct V_18 * V_19 =
F_163 ( V_22 , struct V_18 , V_22 ) ;
struct V_9 * V_10 = V_22 -> V_10 ;
T_3 V_46 = V_19 -> V_6 . V_46 ;
int V_70 ;
F_49 ( F_50 ( & V_19 -> V_6 ) ) ;
if ( F_164 ( ( V_19 -> V_63 & V_325 ) == 0 ) ) {
F_165 ( V_10 , V_46 , V_19 -> V_6 . V_58 ) ;
V_70 = F_166 ( V_10 , V_326 , V_19 ) ;
} else {
F_167 ( V_10 , V_46 , V_19 -> V_6 . V_58 ) ;
V_70 = F_166 ( V_10 , V_327 , V_19 ) ;
}
F_168 ( V_10 ) ;
return V_70 ;
}
static int F_169 ( struct V_9 * V_10 , T_3 V_46 , int V_47 ) __releases( T_5 )
{
struct V_18 * V_19 ;
V_19 = F_150 ( V_10 , V_328 , V_46 , V_47 ) ;
if ( ! V_19 )
goto V_57;
F_170 ( V_10 ) ;
F_171 ( V_10 ) ;
V_19 -> V_22 . V_73 = F_162 ;
F_21 ( & V_10 -> V_26 -> V_27 ) ;
F_149 ( & V_19 -> V_22 . V_23 , & V_10 -> V_329 ) ;
F_22 ( & V_10 -> V_26 -> V_27 ) ;
F_36 ( V_47 >> 9 , & V_10 -> V_330 ) ;
if ( F_138 ( V_10 , V_19 , V_331 , V_332 ) == 0 )
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
static struct V_312 *
F_172 ( struct V_9 * V_10 , struct V_333 * V_334 , T_2 V_45 ,
T_3 V_46 , bool V_335 , const char * V_336 )
{
struct V_312 * V_313 ;
V_313 = (struct V_312 * ) ( unsigned long ) V_45 ;
if ( F_173 ( V_334 , V_46 , & V_313 -> V_6 ) && V_313 -> V_6 . T_5 )
return V_313 ;
if ( ! V_335 ) {
F_43 ( V_38 , L_41 , V_336 ,
( unsigned long ) V_45 , ( unsigned long long ) V_46 ) ;
}
return NULL ;
}
static int F_174 ( struct V_94 * V_26 , struct V_170 * V_171 )
{
struct V_9 * V_10 ;
struct V_312 * V_313 ;
T_3 V_46 ;
int V_70 ;
struct V_337 * V_300 = V_171 -> V_95 ;
V_10 = F_175 ( V_26 , V_171 -> V_189 ) ;
if ( ! V_10 )
return - V_108 ;
V_46 = F_176 ( V_300 -> V_46 ) ;
F_21 ( & V_10 -> V_26 -> V_27 ) ;
V_313 = F_172 ( V_10 , & V_10 -> V_338 , V_300 -> V_64 , V_46 , false , V_55 ) ;
F_22 ( & V_10 -> V_26 -> V_27 ) ;
if ( F_177 ( ! V_313 ) )
return - V_108 ;
V_70 = F_159 ( V_10 , V_313 , V_46 , V_171 -> V_58 ) ;
if ( ! V_70 )
F_178 ( V_313 , V_339 ) ;
return V_70 ;
}
static int F_179 ( struct V_94 * V_26 , struct V_170 * V_171 )
{
struct V_9 * V_10 ;
T_3 V_46 ;
int V_70 ;
struct V_337 * V_300 = V_171 -> V_95 ;
V_10 = F_175 ( V_26 , V_171 -> V_189 ) ;
if ( ! V_10 )
return - V_108 ;
V_46 = F_176 ( V_300 -> V_46 ) ;
F_49 ( V_300 -> V_64 == V_328 ) ;
if ( F_127 ( V_10 ) ) {
V_70 = F_169 ( V_10 , V_46 , V_171 -> V_58 ) ;
} else {
if ( F_180 ( & V_340 ) )
F_43 ( V_38 , L_42 ) ;
V_70 = F_158 ( V_10 , V_171 -> V_58 ) ;
F_181 ( V_10 , V_327 , V_300 , V_171 -> V_58 ) ;
}
F_36 ( V_171 -> V_58 >> 9 , & V_10 -> V_341 ) ;
return V_70 ;
}
static void F_182 ( struct V_9 * V_10 ,
T_3 V_46 , int V_58 )
{
struct V_295 * V_6 ;
struct V_312 * V_313 ;
F_183 (i, &mdev->write_requests, sector, size) {
if ( ! V_6 -> T_5 )
continue;
V_313 = F_163 ( V_6 , struct V_312 , V_6 ) ;
if ( V_313 -> V_342 & V_343 ||
! ( V_313 -> V_342 & V_344 ) )
continue;
F_184 ( V_313 , V_345 , NULL ) ;
}
}
static int F_185 ( struct V_323 * V_22 , int V_346 )
{
struct V_18 * V_19 =
F_163 ( V_22 , struct V_18 , V_22 ) ;
struct V_9 * V_10 = V_22 -> V_10 ;
T_3 V_46 = V_19 -> V_6 . V_46 ;
int V_70 = 0 , V_347 ;
if ( V_19 -> V_63 & V_348 ) {
if ( F_164 ( ( V_19 -> V_63 & V_325 ) == 0 ) ) {
V_347 = ( V_10 -> V_349 . V_105 >= V_350 &&
V_10 -> V_349 . V_105 <= V_351 &&
V_19 -> V_63 & V_352 ) ?
V_326 : V_353 ;
V_70 = F_166 ( V_10 , V_347 , V_19 ) ;
if ( V_347 == V_326 )
F_165 ( V_10 , V_46 , V_19 -> V_6 . V_58 ) ;
} else {
V_70 = F_166 ( V_10 , V_327 , V_19 ) ;
}
F_168 ( V_10 ) ;
}
if ( V_19 -> V_63 & V_354 ) {
F_21 ( & V_10 -> V_26 -> V_27 ) ;
F_49 ( ! F_50 ( & V_19 -> V_6 ) ) ;
F_144 ( V_10 , V_19 ) ;
if ( V_19 -> V_63 & V_355 )
F_182 ( V_10 , V_46 , V_19 -> V_6 . V_58 ) ;
F_22 ( & V_10 -> V_26 -> V_27 ) ;
} else
F_49 ( F_50 ( & V_19 -> V_6 ) ) ;
F_132 ( V_10 -> V_26 , V_19 -> V_60 , V_255 + ( V_346 ? V_254 : 0 ) ) ;
return V_70 ;
}
static int F_186 ( struct V_323 * V_22 , enum V_167 V_356 )
{
struct V_9 * V_10 = V_22 -> V_10 ;
struct V_18 * V_19 =
F_163 ( V_22 , struct V_18 , V_22 ) ;
int V_70 ;
V_70 = F_166 ( V_10 , V_356 , V_19 ) ;
F_168 ( V_10 ) ;
return V_70 ;
}
static int F_187 ( struct V_323 * V_22 , int V_324 )
{
return F_186 ( V_22 , V_357 ) ;
}
static int F_188 ( struct V_323 * V_22 , int V_324 )
{
struct V_94 * V_26 = V_22 -> V_10 -> V_26 ;
return F_186 ( V_22 , V_26 -> V_180 >= 100 ?
V_358 : V_357 ) ;
}
static bool F_189 ( T_8 V_40 , T_8 V_359 )
{
return ( V_360 ) V_40 - ( V_360 ) V_359 > 0 ;
}
static T_8 F_190 ( T_8 V_40 , T_8 V_359 )
{
return F_189 ( V_40 , V_359 ) ? V_40 : V_359 ;
}
static void F_191 ( struct V_9 * V_10 , unsigned int V_178 )
{
unsigned int V_361 ;
if ( F_66 ( V_203 , & V_10 -> V_26 -> V_63 ) ) {
F_11 ( & V_10 -> V_362 ) ;
V_361 = F_190 ( V_10 -> V_178 , V_178 ) ;
V_10 -> V_178 = V_361 ;
F_12 ( & V_10 -> V_362 ) ;
if ( V_178 == V_361 )
F_39 ( & V_10 -> V_363 ) ;
}
}
static inline int F_192 ( T_3 V_364 , int V_365 , T_3 V_366 , int V_367 )
{
return ! ( ( V_364 + ( V_365 >> 9 ) <= V_366 ) || ( V_364 >= V_366 + ( V_367 >> 9 ) ) ) ;
}
static bool F_193 ( struct V_9 * V_10 , struct V_18 * V_19 )
{
struct V_18 * V_368 ;
bool V_92 = 0 ;
F_21 ( & V_10 -> V_26 -> V_27 ) ;
F_194 (rs_req, &mdev->sync_ee, w.list) {
if ( F_192 ( V_19 -> V_6 . V_46 , V_19 -> V_6 . V_58 ,
V_368 -> V_6 . V_46 , V_368 -> V_6 . V_58 ) ) {
V_92 = 1 ;
break;
}
}
F_22 ( & V_10 -> V_26 -> V_27 ) ;
return V_92 ;
}
static int F_195 ( struct V_9 * V_10 , const T_8 V_178 )
{
F_26 ( V_31 ) ;
long V_190 ;
int V_369 = 0 , V_370 ;
if ( ! F_66 ( V_203 , & V_10 -> V_26 -> V_63 ) )
return 0 ;
F_11 ( & V_10 -> V_362 ) ;
for (; ; ) {
if ( ! F_189 ( V_178 - 1 , V_10 -> V_178 ) ) {
V_10 -> V_178 = F_190 ( V_10 -> V_178 , V_178 ) ;
break;
}
if ( F_32 ( V_37 ) ) {
V_369 = - V_97 ;
break;
}
F_27 () ;
V_370 = F_28 ( V_10 -> V_26 -> V_29 ) -> V_371 ;
F_29 () ;
if ( ! V_370 )
break;
F_31 ( & V_10 -> V_363 , & V_31 , V_36 ) ;
F_12 ( & V_10 -> V_362 ) ;
F_27 () ;
V_190 = F_28 ( V_10 -> V_26 -> V_29 ) -> V_99 * V_100 / 10 ;
F_29 () ;
V_190 = F_196 ( V_190 ) ;
F_11 ( & V_10 -> V_362 ) ;
if ( ! V_190 ) {
V_369 = - V_142 ;
F_43 ( V_38 , L_43 ) ;
break;
}
}
F_12 ( & V_10 -> V_362 ) ;
F_35 ( & V_10 -> V_363 , & V_31 ) ;
return V_369 ;
}
static unsigned long F_197 ( struct V_9 * V_10 , T_8 V_372 )
{
return ( V_372 & V_373 ? V_374 : 0 ) |
( V_372 & V_375 ? V_376 : 0 ) |
( V_372 & V_377 ? V_378 : 0 ) |
( V_372 & V_379 ? V_380 : 0 ) ;
}
static void F_198 ( struct V_9 * V_10 , T_3 V_46 ,
unsigned int V_58 )
{
struct V_295 * V_6 ;
V_381:
F_183 (i, &mdev->write_requests, sector, size) {
struct V_312 * V_313 ;
struct V_382 V_383 ;
if ( ! V_6 -> T_5 )
continue;
V_313 = F_163 ( V_6 , struct V_312 , V_6 ) ;
if ( ! ( V_313 -> V_342 & V_344 ) )
continue;
V_313 -> V_342 &= ~ V_344 ;
F_184 ( V_313 , V_384 , & V_383 ) ;
F_22 ( & V_10 -> V_26 -> V_27 ) ;
if ( V_383 . V_278 )
F_199 ( V_10 , & V_383 ) ;
F_21 ( & V_10 -> V_26 -> V_27 ) ;
goto V_381;
}
}
static int F_200 ( struct V_9 * V_10 ,
struct V_18 * V_19 )
{
struct V_94 * V_26 = V_10 -> V_26 ;
bool V_385 = F_66 ( V_203 , & V_26 -> V_63 ) ;
T_3 V_46 = V_19 -> V_6 . V_46 ;
const unsigned int V_58 = V_19 -> V_6 . V_58 ;
struct V_295 * V_6 ;
bool V_386 ;
int V_70 ;
F_201 ( & V_10 -> V_296 , & V_19 -> V_6 ) ;
V_381:
F_183 (i, &mdev->write_requests, sector, size) {
if ( V_6 == & V_19 -> V_6 )
continue;
if ( ! V_6 -> T_5 ) {
V_70 = F_202 ( V_10 , V_6 ) ;
if ( V_70 )
goto V_104;
goto V_381;
}
V_386 = V_6 -> V_46 == V_46 && V_6 -> V_58 == V_58 ;
if ( V_385 ) {
bool V_387 = V_6 -> V_46 <= V_46 && V_6 -> V_46 +
( V_6 -> V_58 >> 9 ) >= V_46 + ( V_58 >> 9 ) ;
if ( ! V_386 )
F_203 ( V_38 , L_44
L_45
L_46 ,
( unsigned long long ) V_6 -> V_46 , V_6 -> V_58 ,
( unsigned long long ) V_46 , V_58 ,
V_387 ? L_47 : L_48 ) ;
F_171 ( V_10 ) ;
V_19 -> V_22 . V_73 = V_387 ? F_187 :
F_188 ;
F_204 ( & V_19 -> V_22 . V_23 , & V_10 -> V_71 ) ;
F_205 ( V_10 -> V_26 ) ;
V_70 = - V_388 ;
goto V_104;
} else {
struct V_312 * V_313 =
F_163 ( V_6 , struct V_312 , V_6 ) ;
if ( ! V_386 )
F_203 ( V_38 , L_44
L_49 ,
( unsigned long long ) V_6 -> V_46 , V_6 -> V_58 ,
( unsigned long long ) V_46 , V_58 ) ;
if ( V_313 -> V_342 & V_343 ||
! ( V_313 -> V_342 & V_344 ) ) {
V_70 = F_202 ( V_10 , & V_313 -> V_6 ) ;
if ( V_70 ) {
F_206 ( V_10 -> V_26 ,
F_69 ( V_105 , V_389 ) ,
V_107 ) ;
F_198 ( V_10 , V_46 , V_58 ) ;
goto V_104;
}
goto V_381;
}
V_19 -> V_63 |= V_355 ;
}
}
V_70 = 0 ;
V_104:
if ( V_70 )
F_144 ( V_10 , V_19 ) ;
return V_70 ;
}
static int F_207 ( struct V_94 * V_26 , struct V_170 * V_171 )
{
struct V_9 * V_10 ;
T_3 V_46 ;
struct V_18 * V_19 ;
struct V_337 * V_300 = V_171 -> V_95 ;
T_8 V_178 = F_123 ( V_300 -> V_390 ) ;
int V_276 = V_331 ;
T_8 V_391 ;
int V_70 , V_370 ;
V_10 = F_175 ( V_26 , V_171 -> V_189 ) ;
if ( ! V_10 )
return - V_108 ;
if ( ! F_127 ( V_10 ) ) {
int V_72 ;
V_70 = F_195 ( V_10 , V_178 ) ;
F_181 ( V_10 , V_327 , V_300 , V_171 -> V_58 ) ;
F_208 ( & V_26 -> V_261 -> V_250 ) ;
V_72 = F_158 ( V_10 , V_171 -> V_58 ) ;
if ( ! V_70 )
V_70 = V_72 ;
return V_70 ;
}
V_46 = F_176 ( V_300 -> V_46 ) ;
V_19 = F_150 ( V_10 , V_300 -> V_64 , V_46 , V_171 -> V_58 ) ;
if ( ! V_19 ) {
F_131 ( V_10 ) ;
return - V_108 ;
}
V_19 -> V_22 . V_73 = F_185 ;
V_391 = F_123 ( V_300 -> V_391 ) ;
V_276 |= F_197 ( V_10 , V_391 ) ;
if ( V_19 -> V_61 == NULL ) {
F_49 ( V_19 -> V_6 . V_58 == 0 ) ;
F_49 ( V_391 & V_377 ) ;
}
if ( V_391 & V_392 )
V_19 -> V_63 |= V_352 ;
F_11 ( & V_26 -> V_253 ) ;
V_19 -> V_60 = V_26 -> V_261 ;
F_208 ( & V_19 -> V_60 -> V_250 ) ;
F_208 ( & V_19 -> V_60 -> V_256 ) ;
F_12 ( & V_26 -> V_253 ) ;
F_27 () ;
V_370 = F_28 ( V_10 -> V_26 -> V_29 ) -> V_371 ;
F_29 () ;
if ( V_370 ) {
V_19 -> V_63 |= V_354 ;
V_70 = F_195 ( V_10 , V_178 ) ;
if ( V_70 )
goto V_393;
F_21 ( & V_10 -> V_26 -> V_27 ) ;
V_70 = F_200 ( V_10 , V_19 ) ;
if ( V_70 ) {
F_22 ( & V_10 -> V_26 -> V_27 ) ;
if ( V_70 == - V_388 ) {
F_131 ( V_10 ) ;
return 0 ;
}
goto V_393;
}
} else {
F_191 ( V_10 , V_178 ) ;
F_21 ( & V_10 -> V_26 -> V_27 ) ;
}
F_149 ( & V_19 -> V_22 . V_23 , & V_10 -> V_298 ) ;
F_22 ( & V_10 -> V_26 -> V_27 ) ;
if ( V_10 -> V_349 . V_105 == V_394 )
F_209 ( V_10 -> V_74 , ! F_193 ( V_10 , V_19 ) ) ;
if ( V_10 -> V_26 -> V_180 < 100 ) {
F_27 () ;
switch ( F_28 ( V_10 -> V_26 -> V_29 ) -> V_395 ) {
case V_396 :
V_391 |= V_397 ;
break;
case V_398 :
V_391 |= V_399 ;
break;
}
F_29 () ;
}
if ( V_391 & V_397 ) {
V_19 -> V_63 |= V_348 ;
F_171 ( V_10 ) ;
}
if ( V_391 & V_399 ) {
F_166 ( V_10 , V_400 , V_19 ) ;
}
if ( V_10 -> V_349 . V_401 < V_402 ) {
F_210 ( V_10 , V_19 -> V_6 . V_46 , V_19 -> V_6 . V_58 ) ;
V_19 -> V_63 |= V_403 ;
V_19 -> V_63 &= ~ V_352 ;
F_211 ( V_10 , & V_19 -> V_6 , true ) ;
}
V_70 = F_138 ( V_10 , V_19 , V_276 , V_404 ) ;
if ( ! V_70 )
return 0 ;
F_43 ( V_38 , L_40 ) ;
F_21 ( & V_10 -> V_26 -> V_27 ) ;
F_135 ( & V_19 -> V_22 . V_23 ) ;
F_144 ( V_10 , V_19 ) ;
F_22 ( & V_10 -> V_26 -> V_27 ) ;
if ( V_19 -> V_63 & V_403 )
F_212 ( V_10 , & V_19 -> V_6 ) ;
V_393:
F_132 ( V_26 , V_19 -> V_60 , V_255 + V_254 ) ;
F_131 ( V_10 ) ;
F_54 ( V_10 , V_19 ) ;
return V_70 ;
}
int F_213 ( struct V_9 * V_10 , T_3 V_46 )
{
struct V_405 * V_406 = V_10 -> V_243 -> V_244 -> V_407 -> V_408 ;
unsigned long V_409 , V_410 , V_411 ;
struct V_412 * V_4 ;
int V_413 ;
int V_414 = 0 ;
unsigned int V_415 ;
F_27 () ;
V_415 = F_28 ( V_10 -> V_243 -> V_268 ) -> V_415 ;
F_29 () ;
if ( V_415 == 0 )
return 0 ;
F_21 ( & V_10 -> V_416 ) ;
V_4 = F_214 ( V_10 -> V_417 , F_215 ( V_46 ) ) ;
if ( V_4 ) {
struct V_418 * V_419 = F_216 ( V_4 , struct V_418 , V_420 ) ;
if ( F_66 ( V_421 , & V_419 -> V_63 ) ) {
F_22 ( & V_10 -> V_416 ) ;
return 0 ;
}
}
F_22 ( & V_10 -> V_416 ) ;
V_413 = ( int ) F_217 ( & V_406 -> V_422 , V_423 [ 0 ] ) +
( int ) F_217 ( & V_406 -> V_422 , V_423 [ 1 ] ) -
F_30 ( & V_10 -> V_330 ) ;
if ( ! V_10 -> V_424 || V_413 - V_10 -> V_424 > 64 ) {
unsigned long V_425 ;
int V_6 ;
V_10 -> V_424 = V_413 ;
V_6 = ( V_10 -> V_426 + V_427 - 1 ) % V_427 ;
if ( V_10 -> V_349 . V_105 == V_428 || V_10 -> V_349 . V_105 == V_429 )
V_425 = V_10 -> V_430 ;
else
V_425 = F_218 ( V_10 ) - V_10 -> V_431 ;
V_410 = ( ( long ) V_187 - ( long ) V_10 -> V_432 [ V_6 ] ) / V_100 ;
if ( ! V_410 )
V_410 ++ ;
V_409 = V_10 -> V_433 [ V_6 ] - V_425 ;
V_411 = F_219 ( V_409 / V_410 ) ;
if ( V_411 > V_415 )
V_414 = 1 ;
}
return V_414 ;
}
static int F_220 ( struct V_94 * V_26 , struct V_170 * V_171 )
{
struct V_9 * V_10 ;
T_3 V_46 ;
T_3 V_302 ;
struct V_18 * V_19 ;
struct V_434 * V_435 = NULL ;
int V_58 , V_436 ;
unsigned int V_277 ;
struct V_437 * V_300 = V_171 -> V_95 ;
V_10 = F_175 ( V_26 , V_171 -> V_189 ) ;
if ( ! V_10 )
return - V_108 ;
V_302 = F_151 ( V_10 -> V_303 ) ;
V_46 = F_176 ( V_300 -> V_46 ) ;
V_58 = F_123 ( V_300 -> V_438 ) ;
if ( V_58 <= 0 || ! F_154 ( V_58 , 512 ) || V_58 > V_42 ) {
F_43 ( V_38 , L_50 , __FILE__ , __LINE__ ,
( unsigned long long ) V_46 , V_58 ) ;
return - V_231 ;
}
if ( V_46 + ( V_58 >> 9 ) > V_302 ) {
F_43 ( V_38 , L_50 , __FILE__ , __LINE__ ,
( unsigned long long ) V_46 , V_58 ) ;
return - V_231 ;
}
if ( ! F_137 ( V_10 , V_439 ) ) {
V_436 = 1 ;
switch ( V_171 -> V_168 ) {
case V_440 :
F_221 ( V_10 , V_441 , V_300 ) ;
break;
case V_442 :
case V_443 :
case V_444 :
F_221 ( V_10 , V_445 , V_300 ) ;
break;
case V_446 :
V_436 = 0 ;
F_170 ( V_10 ) ;
F_222 ( V_10 , V_447 , V_46 , V_58 , V_448 ) ;
break;
default:
F_223 () ;
}
if ( V_436 && F_180 ( & V_340 ) )
F_43 ( V_38 , L_51
L_52 ) ;
return F_158 ( V_10 , V_171 -> V_58 ) ;
}
V_19 = F_40 ( V_10 , V_300 -> V_64 , V_46 , V_58 , V_211 ) ;
if ( ! V_19 ) {
F_131 ( V_10 ) ;
return - V_282 ;
}
switch ( V_171 -> V_168 ) {
case V_440 :
V_19 -> V_22 . V_73 = V_449 ;
V_277 = V_450 ;
goto V_451;
case V_442 :
V_19 -> V_22 . V_73 = V_452 ;
V_277 = V_453 ;
V_10 -> V_454 = F_224 ( V_46 ) ;
break;
case V_446 :
case V_443 :
V_277 = V_453 ;
V_435 = F_148 ( sizeof( * V_435 ) + V_171 -> V_58 , V_211 ) ;
if ( ! V_435 )
goto V_455;
V_435 -> V_456 = V_171 -> V_58 ;
V_435 -> V_66 = ( ( ( char * ) V_435 ) + sizeof( struct V_434 ) ) ;
V_19 -> V_66 = V_435 ;
V_19 -> V_63 |= V_65 ;
if ( F_70 ( V_10 -> V_26 , V_435 -> V_66 , V_171 -> V_58 ) )
goto V_455;
if ( V_171 -> V_168 == V_443 ) {
F_49 ( V_10 -> V_26 -> V_180 >= 89 ) ;
V_19 -> V_22 . V_73 = V_457 ;
V_10 -> V_454 = F_224 ( V_46 ) ;
} else if ( V_171 -> V_168 == V_446 ) {
F_36 ( V_58 >> 9 , & V_10 -> V_341 ) ;
V_19 -> V_22 . V_73 = V_458 ;
F_170 ( V_10 ) ;
goto V_459;
}
break;
case V_444 :
if ( V_10 -> V_460 == ~ ( T_3 ) 0 &&
V_10 -> V_26 -> V_180 >= 90 ) {
unsigned long V_461 = V_187 ;
int V_6 ;
V_10 -> V_460 = V_46 ;
V_10 -> V_462 = V_46 ;
V_10 -> V_430 = F_225 ( V_10 ) - F_224 ( V_46 ) ;
V_10 -> V_463 = V_10 -> V_430 ;
for ( V_6 = 0 ; V_6 < V_427 ; V_6 ++ ) {
V_10 -> V_433 [ V_6 ] = V_10 -> V_430 ;
V_10 -> V_432 [ V_6 ] = V_461 ;
}
F_129 ( V_38 , L_53 ,
( unsigned long long ) V_46 ) ;
}
V_19 -> V_22 . V_73 = V_464 ;
V_277 = V_453 ;
break;
default:
F_223 () ;
}
if ( V_10 -> V_349 . V_465 != V_466 && F_213 ( V_10 , V_46 ) )
F_226 ( V_100 / 10 ) ;
if ( F_227 ( V_10 , V_46 ) )
goto V_455;
V_459:
F_36 ( V_58 >> 9 , & V_10 -> V_330 ) ;
V_451:
F_171 ( V_10 ) ;
F_21 ( & V_10 -> V_26 -> V_27 ) ;
F_204 ( & V_19 -> V_22 . V_23 , & V_10 -> V_467 ) ;
F_22 ( & V_10 -> V_26 -> V_27 ) ;
if ( F_138 ( V_10 , V_19 , V_468 , V_277 ) == 0 )
return 0 ;
F_43 ( V_38 , L_40 ) ;
F_21 ( & V_10 -> V_26 -> V_27 ) ;
F_135 ( & V_19 -> V_22 . V_23 ) ;
F_22 ( & V_10 -> V_26 -> V_27 ) ;
V_455:
F_131 ( V_10 ) ;
F_54 ( V_10 , V_19 ) ;
return - V_108 ;
}
static int F_228 ( struct V_9 * V_10 ) __must_hold( T_5 )
{
int V_469 , V_465 , V_92 = - 100 ;
unsigned long V_470 , V_471 ;
enum V_472 V_473 ;
V_469 = V_10 -> V_243 -> V_474 . V_475 [ V_476 ] & 1 ;
V_465 = V_10 -> V_477 [ V_476 ] & 1 ;
V_471 = V_10 -> V_477 [ V_478 ] ;
V_470 = V_10 -> V_479 ;
F_27 () ;
V_473 = F_28 ( V_10 -> V_26 -> V_29 ) -> V_473 ;
F_29 () ;
switch ( V_473 ) {
case V_480 :
case V_481 :
case V_482 :
case V_483 :
F_43 ( V_38 , L_54 ) ;
break;
case V_484 :
break;
case V_485 :
if ( V_469 == 0 && V_465 == 1 ) {
V_92 = - 1 ;
break;
}
if ( V_469 == 1 && V_465 == 0 ) {
V_92 = 1 ;
break;
}
case V_486 :
if ( V_469 == 0 && V_465 == 1 ) {
V_92 = 1 ;
break;
}
if ( V_469 == 1 && V_465 == 0 ) {
V_92 = - 1 ;
break;
}
F_33 ( V_38 , L_55
L_56 ) ;
case V_487 :
if ( V_471 == 0 && V_470 == 0 ) {
V_92 = F_66 ( V_203 , & V_10 -> V_26 -> V_63 )
? - 1 : 1 ;
break;
} else {
if ( V_471 == 0 ) { V_92 = 1 ; break; }
if ( V_470 == 0 ) { V_92 = - 1 ; break; }
}
if ( V_473 == V_487 )
break;
case V_488 :
if ( V_470 < V_471 )
V_92 = - 1 ;
else if ( V_470 > V_471 )
V_92 = 1 ;
else
V_92 = F_66 ( V_203 , & V_10 -> V_26 -> V_63 )
? - 1 : 1 ;
break;
case V_489 :
V_92 = - 1 ;
break;
case V_490 :
V_92 = 1 ;
}
return V_92 ;
}
static int F_229 ( struct V_9 * V_10 ) __must_hold( T_5 )
{
int V_491 , V_92 = - 100 ;
enum V_472 V_492 ;
F_27 () ;
V_492 = F_28 ( V_10 -> V_26 -> V_29 ) -> V_492 ;
F_29 () ;
switch ( V_492 ) {
case V_485 :
case V_486 :
case V_488 :
case V_489 :
case V_490 :
case V_487 :
F_43 ( V_38 , L_54 ) ;
break;
case V_484 :
break;
case V_480 :
V_491 = F_228 ( V_10 ) ;
if ( V_491 == - 1 && V_10 -> V_349 . V_493 == V_494 )
V_92 = V_491 ;
if ( V_491 == 1 && V_10 -> V_349 . V_493 == V_466 )
V_92 = V_491 ;
break;
case V_483 :
V_92 = F_228 ( V_10 ) ;
break;
case V_481 :
return V_10 -> V_349 . V_493 == V_466 ? 1 : - 1 ;
case V_482 :
V_491 = F_228 ( V_10 ) ;
if ( V_491 == - 1 && V_10 -> V_349 . V_493 == V_466 ) {
enum V_194 V_495 ;
V_495 = F_230 ( V_10 , V_196 , F_69 ( V_493 , V_494 ) ) ;
if ( V_495 != V_197 ) {
F_231 ( V_10 , L_57 ) ;
} else {
F_33 ( V_38 , L_58 ) ;
V_92 = V_491 ;
}
} else
V_92 = V_491 ;
}
return V_92 ;
}
static int F_232 ( struct V_9 * V_10 ) __must_hold( T_5 )
{
int V_491 , V_92 = - 100 ;
enum V_472 V_496 ;
F_27 () ;
V_496 = F_28 ( V_10 -> V_26 -> V_29 ) -> V_496 ;
F_29 () ;
switch ( V_496 ) {
case V_485 :
case V_486 :
case V_488 :
case V_489 :
case V_490 :
case V_480 :
case V_481 :
case V_487 :
F_43 ( V_38 , L_54 ) ;
break;
case V_483 :
V_92 = F_228 ( V_10 ) ;
break;
case V_484 :
break;
case V_482 :
V_491 = F_228 ( V_10 ) ;
if ( V_491 == - 1 ) {
enum V_194 V_495 ;
V_495 = F_230 ( V_10 , V_196 , F_69 ( V_493 , V_494 ) ) ;
if ( V_495 != V_197 ) {
F_231 ( V_10 , L_57 ) ;
} else {
F_33 ( V_38 , L_58 ) ;
V_92 = V_491 ;
}
} else
V_92 = V_491 ;
}
return V_92 ;
}
static void F_233 ( struct V_9 * V_10 , char * V_497 , T_2 * V_475 ,
T_2 V_498 , T_2 V_63 )
{
if ( ! V_475 ) {
F_129 ( V_38 , L_59 , V_497 ) ;
return;
}
F_129 ( V_38 , L_60 ,
V_497 ,
( unsigned long long ) V_475 [ V_499 ] ,
( unsigned long long ) V_475 [ V_476 ] ,
( unsigned long long ) V_475 [ V_500 ] ,
( unsigned long long ) V_475 [ V_501 ] ,
( unsigned long long ) V_498 ,
( unsigned long long ) V_63 ) ;
}
static int F_234 ( struct V_9 * V_10 , int * V_502 ) __must_hold( T_5 )
{
T_2 V_469 , V_465 ;
int V_6 , V_503 ;
V_469 = V_10 -> V_243 -> V_474 . V_475 [ V_499 ] & ~ ( ( T_2 ) 1 ) ;
V_465 = V_10 -> V_477 [ V_499 ] & ~ ( ( T_2 ) 1 ) ;
* V_502 = 10 ;
if ( V_469 == V_504 && V_465 == V_504 )
return 0 ;
* V_502 = 20 ;
if ( ( V_469 == V_504 || V_469 == ( T_2 ) 0 ) &&
V_465 != V_504 )
return - 2 ;
* V_502 = 30 ;
if ( V_469 != V_504 &&
( V_465 == V_504 || V_465 == ( T_2 ) 0 ) )
return 2 ;
if ( V_469 == V_465 ) {
int V_505 , V_269 ;
if ( V_10 -> V_477 [ V_476 ] == ( T_2 ) 0 && V_10 -> V_243 -> V_474 . V_475 [ V_476 ] != ( T_2 ) 0 ) {
if ( V_10 -> V_26 -> V_180 < 91 )
return - 1091 ;
if ( ( V_10 -> V_243 -> V_474 . V_475 [ V_476 ] & ~ ( ( T_2 ) 1 ) ) == ( V_10 -> V_477 [ V_500 ] & ~ ( ( T_2 ) 1 ) ) &&
( V_10 -> V_243 -> V_474 . V_475 [ V_500 ] & ~ ( ( T_2 ) 1 ) ) == ( V_10 -> V_477 [ V_500 + 1 ] & ~ ( ( T_2 ) 1 ) ) ) {
F_129 ( V_38 , L_61 ) ;
F_235 ( V_10 ) ;
V_10 -> V_243 -> V_474 . V_475 [ V_500 ] = V_10 -> V_243 -> V_474 . V_475 [ V_476 ] ;
V_10 -> V_243 -> V_474 . V_475 [ V_476 ] = 0 ;
F_233 ( V_10 , L_62 , V_10 -> V_243 -> V_474 . V_475 ,
V_10 -> V_349 . V_406 >= V_506 ? F_218 ( V_10 ) : 0 , 0 ) ;
* V_502 = 34 ;
} else {
F_129 ( V_38 , L_63 ) ;
* V_502 = 36 ;
}
return 1 ;
}
if ( V_10 -> V_243 -> V_474 . V_475 [ V_476 ] == ( T_2 ) 0 && V_10 -> V_477 [ V_476 ] != ( T_2 ) 0 ) {
if ( V_10 -> V_26 -> V_180 < 91 )
return - 1091 ;
if ( ( V_10 -> V_243 -> V_474 . V_475 [ V_500 ] & ~ ( ( T_2 ) 1 ) ) == ( V_10 -> V_477 [ V_476 ] & ~ ( ( T_2 ) 1 ) ) &&
( V_10 -> V_243 -> V_474 . V_475 [ V_500 + 1 ] & ~ ( ( T_2 ) 1 ) ) == ( V_10 -> V_477 [ V_500 ] & ~ ( ( T_2 ) 1 ) ) ) {
F_129 ( V_38 , L_64 ) ;
V_10 -> V_477 [ V_500 + 1 ] = V_10 -> V_477 [ V_500 ] ;
V_10 -> V_477 [ V_500 ] = V_10 -> V_477 [ V_476 ] ;
V_10 -> V_477 [ V_476 ] = 0UL ;
F_233 ( V_10 , L_65 , V_10 -> V_477 , V_10 -> V_477 [ V_478 ] , V_10 -> V_477 [ V_507 ] ) ;
* V_502 = 35 ;
} else {
F_129 ( V_38 , L_66 ) ;
* V_502 = 37 ;
}
return - 1 ;
}
V_505 = ( F_66 ( V_508 , & V_10 -> V_63 ) ? 1 : 0 ) +
( V_10 -> V_477 [ V_507 ] & 2 ) ;
* V_502 = 40 ;
switch ( V_505 ) {
case 0 : return 0 ;
case 1 : return 1 ;
case 2 : return - 1 ;
case 3 :
V_269 = F_66 ( V_203 , & V_10 -> V_26 -> V_63 ) ;
return V_269 ? - 1 : 1 ;
}
}
* V_502 = 50 ;
V_465 = V_10 -> V_477 [ V_476 ] & ~ ( ( T_2 ) 1 ) ;
if ( V_469 == V_465 )
return - 1 ;
* V_502 = 51 ;
V_465 = V_10 -> V_477 [ V_500 ] & ~ ( ( T_2 ) 1 ) ;
if ( V_469 == V_465 ) {
if ( V_10 -> V_26 -> V_180 < 96 ?
( V_10 -> V_243 -> V_474 . V_475 [ V_500 ] & ~ ( ( T_2 ) 1 ) ) ==
( V_10 -> V_477 [ V_500 + 1 ] & ~ ( ( T_2 ) 1 ) ) :
V_465 + V_509 == ( V_10 -> V_477 [ V_476 ] & ~ ( ( T_2 ) 1 ) ) ) {
if ( V_10 -> V_26 -> V_180 < 91 )
return - 1091 ;
V_10 -> V_477 [ V_476 ] = V_10 -> V_477 [ V_500 ] ;
V_10 -> V_477 [ V_500 ] = V_10 -> V_477 [ V_500 + 1 ] ;
F_129 ( V_38 , L_67 ) ;
F_233 ( V_10 , L_65 , V_10 -> V_477 , V_10 -> V_477 [ V_478 ] , V_10 -> V_477 [ V_507 ] ) ;
return - 1 ;
}
}
* V_502 = 60 ;
V_469 = V_10 -> V_243 -> V_474 . V_475 [ V_499 ] & ~ ( ( T_2 ) 1 ) ;
for ( V_6 = V_500 ; V_6 <= V_501 ; V_6 ++ ) {
V_465 = V_10 -> V_477 [ V_6 ] & ~ ( ( T_2 ) 1 ) ;
if ( V_469 == V_465 )
return - 2 ;
}
* V_502 = 70 ;
V_469 = V_10 -> V_243 -> V_474 . V_475 [ V_476 ] & ~ ( ( T_2 ) 1 ) ;
V_465 = V_10 -> V_477 [ V_499 ] & ~ ( ( T_2 ) 1 ) ;
if ( V_469 == V_465 )
return 1 ;
* V_502 = 71 ;
V_469 = V_10 -> V_243 -> V_474 . V_475 [ V_500 ] & ~ ( ( T_2 ) 1 ) ;
if ( V_469 == V_465 ) {
if ( V_10 -> V_26 -> V_180 < 96 ?
( V_10 -> V_243 -> V_474 . V_475 [ V_500 + 1 ] & ~ ( ( T_2 ) 1 ) ) ==
( V_10 -> V_477 [ V_500 ] & ~ ( ( T_2 ) 1 ) ) :
V_469 + V_509 == ( V_10 -> V_243 -> V_474 . V_475 [ V_476 ] & ~ ( ( T_2 ) 1 ) ) ) {
if ( V_10 -> V_26 -> V_180 < 91 )
return - 1091 ;
F_236 ( V_10 , V_476 , V_10 -> V_243 -> V_474 . V_475 [ V_500 ] ) ;
F_236 ( V_10 , V_500 , V_10 -> V_243 -> V_474 . V_475 [ V_500 + 1 ] ) ;
F_129 ( V_38 , L_68 ) ;
F_233 ( V_10 , L_62 , V_10 -> V_243 -> V_474 . V_475 ,
V_10 -> V_349 . V_406 >= V_506 ? F_218 ( V_10 ) : 0 , 0 ) ;
return 1 ;
}
}
* V_502 = 80 ;
V_465 = V_10 -> V_477 [ V_499 ] & ~ ( ( T_2 ) 1 ) ;
for ( V_6 = V_500 ; V_6 <= V_501 ; V_6 ++ ) {
V_469 = V_10 -> V_243 -> V_474 . V_475 [ V_6 ] & ~ ( ( T_2 ) 1 ) ;
if ( V_469 == V_465 )
return 2 ;
}
* V_502 = 90 ;
V_469 = V_10 -> V_243 -> V_474 . V_475 [ V_476 ] & ~ ( ( T_2 ) 1 ) ;
V_465 = V_10 -> V_477 [ V_476 ] & ~ ( ( T_2 ) 1 ) ;
if ( V_469 == V_465 && V_469 != ( ( T_2 ) 0 ) )
return 100 ;
* V_502 = 100 ;
for ( V_6 = V_500 ; V_6 <= V_501 ; V_6 ++ ) {
V_469 = V_10 -> V_243 -> V_474 . V_475 [ V_6 ] & ~ ( ( T_2 ) 1 ) ;
for ( V_503 = V_500 ; V_503 <= V_501 ; V_503 ++ ) {
V_465 = V_10 -> V_477 [ V_503 ] & ~ ( ( T_2 ) 1 ) ;
if ( V_469 == V_465 )
return - 100 ;
}
}
return - 1000 ;
}
static enum V_510 F_237 ( struct V_9 * V_10 , enum V_511 V_512 ,
enum V_513 V_514 ) __must_hold( T_5 )
{
enum V_510 V_92 = V_515 ;
enum V_513 V_516 ;
struct V_29 * V_30 ;
int V_491 , V_502 , V_517 , V_518 ;
V_516 = V_10 -> V_349 . V_406 ;
if ( V_516 == V_506 )
V_516 = V_10 -> V_519 . V_406 ;
F_129 ( V_38 , L_69 ) ;
F_21 ( & V_10 -> V_243 -> V_474 . V_520 ) ;
F_233 ( V_10 , L_62 , V_10 -> V_243 -> V_474 . V_475 , V_10 -> V_479 , 0 ) ;
F_233 ( V_10 , L_65 , V_10 -> V_477 ,
V_10 -> V_477 [ V_478 ] , V_10 -> V_477 [ V_507 ] ) ;
V_491 = F_234 ( V_10 , & V_502 ) ;
F_22 ( & V_10 -> V_243 -> V_474 . V_520 ) ;
F_129 ( V_38 , L_70 , V_491 , V_502 ) ;
if ( V_491 == - 1000 ) {
F_203 ( V_38 , L_71 ) ;
return V_515 ;
}
if ( V_491 < - 1000 ) {
F_203 ( V_38 , L_72 , - V_491 - 1000 ) ;
return V_515 ;
}
if ( ( V_516 == V_402 && V_514 > V_402 ) ||
( V_514 == V_402 && V_516 > V_402 ) ) {
int V_521 = ( V_491 == - 100 ) || abs ( V_491 ) == 2 ;
V_491 = V_516 > V_402 ? 1 : - 1 ;
if ( V_521 )
V_491 = V_491 * 2 ;
F_129 ( V_38 , L_73 ,
V_491 > 0 ? L_74 : L_75 ) ;
}
if ( abs ( V_491 ) == 100 )
F_231 ( V_10 , L_76 ) ;
F_27 () ;
V_30 = F_28 ( V_10 -> V_26 -> V_29 ) ;
if ( V_491 == 100 || ( V_491 == - 100 && V_30 -> V_522 ) ) {
int V_523 = ( V_10 -> V_349 . V_493 == V_466 )
+ ( V_512 == V_466 ) ;
int V_524 = ( V_491 == - 100 ) ;
switch ( V_523 ) {
case 0 :
V_491 = F_228 ( V_10 ) ;
break;
case 1 :
V_491 = F_229 ( V_10 ) ;
break;
case 2 :
V_491 = F_232 ( V_10 ) ;
break;
}
if ( abs ( V_491 ) < 100 ) {
F_33 ( V_38 , L_77
L_78 ,
V_523 , ( V_491 < 0 ) ? L_65 : L_79 ) ;
if ( V_524 ) {
F_33 ( V_38 , L_80
L_81 ) ;
V_491 = V_491 * 2 ;
}
}
}
if ( V_491 == - 100 ) {
if ( F_66 ( V_222 , & V_10 -> V_63 ) && ! ( V_10 -> V_477 [ V_507 ] & 1 ) )
V_491 = - 1 ;
if ( ! F_66 ( V_222 , & V_10 -> V_63 ) && ( V_10 -> V_477 [ V_507 ] & 1 ) )
V_491 = 1 ;
if ( abs ( V_491 ) < 100 )
F_33 ( V_38 , L_82
L_83 ,
( V_491 < 0 ) ? L_65 : L_79 ) ;
}
V_517 = V_30 -> V_517 ;
V_518 = V_30 -> V_518 ;
F_29 () ;
if ( V_491 == - 100 ) {
F_203 ( V_38 , L_84 ) ;
F_231 ( V_10 , L_85 ) ;
return V_515 ;
}
if ( V_491 > 0 && V_516 <= V_402 ) {
F_43 ( V_38 , L_86 ) ;
return V_515 ;
}
if ( V_491 < 0 &&
V_10 -> V_349 . V_493 == V_466 && V_10 -> V_349 . V_406 >= V_525 ) {
switch ( V_517 ) {
case V_482 :
F_231 ( V_10 , L_87 ) ;
case V_484 :
F_43 ( V_38 , L_88 ) ;
return V_515 ;
case V_483 :
F_33 ( V_38 , L_89
L_90 ) ;
}
}
if ( V_518 || F_66 ( V_526 , & V_10 -> V_26 -> V_63 ) ) {
if ( V_491 == 0 )
F_129 ( V_38 , L_91 ) ;
else
F_129 ( V_38 , L_92 ,
F_238 ( V_491 > 0 ? V_350 : V_394 ) ,
abs ( V_491 ) >= 2 ? L_93 : L_94 ) ;
return V_515 ;
}
if ( abs ( V_491 ) >= 2 ) {
F_129 ( V_38 , L_95 ) ;
if ( F_239 ( V_10 , & V_527 , L_96 ,
V_528 ) )
return V_515 ;
}
if ( V_491 > 0 ) {
V_92 = V_529 ;
} else if ( V_491 < 0 ) {
V_92 = V_530 ;
} else {
V_92 = V_531 ;
if ( F_218 ( V_10 ) ) {
F_129 ( V_38 , L_97 ,
F_218 ( V_10 ) ) ;
}
}
return V_92 ;
}
static enum V_472 F_240 ( enum V_472 V_465 )
{
if ( V_465 == V_490 )
return V_489 ;
if ( V_465 == V_489 )
return V_490 ;
return V_465 ;
}
static int F_241 ( struct V_94 * V_26 , struct V_170 * V_171 )
{
struct V_532 * V_300 = V_171 -> V_95 ;
enum V_472 V_533 , V_534 , V_535 ;
int V_536 , V_537 , V_538 , V_539 ;
struct V_29 * V_30 , * V_540 , * V_541 = NULL ;
char V_542 [ V_543 ] = L_98 ;
struct V_544 * V_309 = NULL ;
void * V_306 = NULL , * V_308 = NULL ;
V_536 = F_123 ( V_300 -> V_545 ) ;
V_533 = F_123 ( V_300 -> V_473 ) ;
V_534 = F_123 ( V_300 -> V_492 ) ;
V_535 = F_123 ( V_300 -> V_496 ) ;
V_538 = F_123 ( V_300 -> V_371 ) ;
V_539 = F_123 ( V_300 -> V_546 ) ;
V_537 = V_539 & V_547 ;
if ( V_26 -> V_180 >= 87 ) {
int V_70 ;
if ( V_171 -> V_58 > sizeof( V_542 ) )
return - V_108 ;
V_70 = F_70 ( V_26 , V_542 , V_171 -> V_58 ) ;
if ( V_70 )
return V_70 ;
V_542 [ V_543 - 1 ] = 0 ;
}
if ( V_171 -> V_168 != V_548 ) {
F_101 ( V_526 , & V_26 -> V_63 ) ;
if ( V_539 & V_549 )
F_107 ( V_526 , & V_26 -> V_63 ) ;
F_27 () ;
V_30 = F_28 ( V_26 -> V_29 ) ;
if ( V_536 != V_30 -> V_395 ) {
F_65 ( V_26 , L_99 , L_100 ) ;
goto V_550;
}
if ( F_240 ( V_533 ) != V_30 -> V_473 ) {
F_65 ( V_26 , L_99 , L_101 ) ;
goto V_550;
}
if ( F_240 ( V_534 ) != V_30 -> V_492 ) {
F_65 ( V_26 , L_99 , L_102 ) ;
goto V_550;
}
if ( F_240 ( V_535 ) != V_30 -> V_496 ) {
F_65 ( V_26 , L_99 , L_103 ) ;
goto V_550;
}
if ( V_537 && V_30 -> V_193 ) {
F_65 ( V_26 , L_99 , L_104 ) ;
goto V_550;
}
if ( V_538 != V_30 -> V_371 ) {
F_65 ( V_26 , L_99 , L_105 ) ;
goto V_550;
}
if ( strcmp ( V_542 , V_30 -> V_542 ) ) {
F_65 ( V_26 , L_99 , L_106 ) ;
goto V_550;
}
F_29 () ;
}
if ( V_542 [ 0 ] ) {
int V_551 ;
V_309 = F_242 ( V_542 , 0 , V_552 ) ;
if ( ! V_309 ) {
F_65 ( V_26 , L_107 ,
V_542 ) ;
goto V_553;
}
V_551 = F_152 ( V_309 ) ;
V_306 = F_148 ( V_551 , V_554 ) ;
V_308 = F_148 ( V_551 , V_554 ) ;
if ( ! ( V_306 && V_308 ) ) {
F_65 ( V_26 , L_108 ) ;
goto V_553;
}
}
V_541 = F_148 ( sizeof( struct V_29 ) , V_554 ) ;
if ( ! V_541 ) {
F_65 ( V_26 , L_109 ) ;
goto V_553;
}
F_117 ( & V_26 -> V_95 . V_198 ) ;
F_117 ( & V_26 -> V_225 ) ;
V_540 = V_26 -> V_29 ;
* V_541 = * V_540 ;
V_541 -> V_395 = V_536 ;
V_541 -> V_473 = F_240 ( V_533 ) ;
V_541 -> V_492 = F_240 ( V_534 ) ;
V_541 -> V_496 = F_240 ( V_535 ) ;
V_541 -> V_371 = V_538 ;
F_243 ( V_26 -> V_29 , V_541 ) ;
F_118 ( & V_26 -> V_225 ) ;
F_118 ( & V_26 -> V_95 . V_198 ) ;
F_244 ( V_26 -> V_309 ) ;
F_48 ( V_26 -> V_306 ) ;
F_48 ( V_26 -> V_308 ) ;
V_26 -> V_309 = V_309 ;
V_26 -> V_306 = V_306 ;
V_26 -> V_308 = V_308 ;
if ( strcmp ( V_540 -> V_542 , V_542 ) )
F_64 ( V_26 , L_110 ,
V_542 [ 0 ] ? V_542 : L_111 ) ;
F_245 () ;
F_48 ( V_540 ) ;
return 0 ;
V_550:
F_29 () ;
V_553:
F_244 ( V_309 ) ;
F_48 ( V_306 ) ;
F_48 ( V_308 ) ;
F_68 ( V_26 , F_69 ( V_105 , V_150 ) , V_107 ) ;
return - V_108 ;
}
struct V_544 * F_246 ( const struct V_9 * V_10 ,
const char * V_555 , const char * V_556 )
{
struct V_544 * V_557 ;
if ( ! V_555 [ 0 ] )
return NULL ;
V_557 = F_242 ( V_555 , 0 , V_552 ) ;
if ( F_247 ( V_557 ) ) {
F_43 ( V_38 , L_112 ,
V_555 , V_556 , F_248 ( V_557 ) ) ;
return V_557 ;
}
return V_557 ;
}
static int F_249 ( struct V_94 * V_26 , struct V_170 * V_171 )
{
void * V_240 = V_26 -> V_95 . V_172 ;
int V_58 = V_171 -> V_58 ;
while ( V_58 ) {
int V_201 = F_75 ( int , V_58 , V_558 ) ;
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
static int F_250 ( struct V_94 * V_26 , struct V_170 * V_171 )
{
F_72 ( V_26 , L_113 ,
F_251 ( V_171 -> V_168 ) , V_171 -> V_189 ) ;
return F_249 ( V_26 , V_171 ) ;
}
static int F_252 ( struct V_94 * V_26 , struct V_170 * V_171 )
{
struct V_9 * V_10 ;
struct V_559 * V_300 ;
unsigned int V_169 , V_47 , V_560 ;
struct V_544 * V_561 = NULL ;
struct V_544 * V_562 = NULL ;
struct V_29 * V_540 , * V_541 = NULL ;
struct V_268 * V_563 = NULL , * V_564 = NULL ;
const int V_565 = V_26 -> V_180 ;
struct V_566 * V_567 = NULL , * V_568 = NULL ;
int V_569 = 0 ;
int V_70 ;
V_10 = F_175 ( V_26 , V_171 -> V_189 ) ;
if ( ! V_10 )
return F_250 ( V_26 , V_171 ) ;
V_560 = V_565 <= 87 ? sizeof( struct V_570 )
: V_565 == 88 ? sizeof( struct V_570 )
+ V_543
: V_565 <= 94 ? sizeof( struct V_571 )
: sizeof( struct V_559 ) ;
if ( V_171 -> V_58 > V_560 ) {
F_43 ( V_38 , L_114 ,
V_171 -> V_58 , V_560 ) ;
return - V_108 ;
}
if ( V_565 <= 88 ) {
V_169 = sizeof( struct V_570 ) ;
V_47 = V_171 -> V_58 - V_169 ;
} else if ( V_565 <= 94 ) {
V_169 = sizeof( struct V_571 ) ;
V_47 = V_171 -> V_58 - V_169 ;
F_49 ( V_47 == 0 ) ;
} else {
V_169 = sizeof( struct V_559 ) ;
V_47 = V_171 -> V_58 - V_169 ;
F_49 ( V_47 == 0 ) ;
}
V_300 = V_171 -> V_95 ;
memset ( V_300 -> V_572 , 0 , 2 * V_543 ) ;
V_70 = F_70 ( V_10 -> V_26 , V_300 , V_169 ) ;
if ( V_70 )
return V_70 ;
F_117 ( & V_10 -> V_26 -> V_225 ) ;
V_540 = V_10 -> V_26 -> V_29 ;
if ( F_127 ( V_10 ) ) {
V_564 = F_253 ( sizeof( struct V_268 ) , V_554 ) ;
if ( ! V_564 ) {
F_131 ( V_10 ) ;
F_118 ( & V_10 -> V_26 -> V_225 ) ;
F_43 ( V_38 , L_115 ) ;
return - V_282 ;
}
V_563 = V_10 -> V_243 -> V_268 ;
* V_564 = * V_563 ;
V_564 -> V_573 = F_123 ( V_300 -> V_573 ) ;
}
if ( V_565 >= 88 ) {
if ( V_565 == 88 ) {
if ( V_47 > V_543 || V_47 == 0 ) {
F_43 ( V_38 , L_116
L_117 ,
V_47 , V_543 ) ;
V_70 = - V_108 ;
goto V_574;
}
V_70 = F_70 ( V_10 -> V_26 , V_300 -> V_572 , V_47 ) ;
if ( V_70 )
goto V_574;
F_49 ( V_300 -> V_572 [ V_47 - 1 ] == 0 ) ;
V_300 -> V_572 [ V_47 - 1 ] = 0 ;
} else {
F_49 ( V_300 -> V_572 [ V_543 - 1 ] == 0 ) ;
F_49 ( V_300 -> V_575 [ V_543 - 1 ] == 0 ) ;
V_300 -> V_572 [ V_543 - 1 ] = 0 ;
V_300 -> V_575 [ V_543 - 1 ] = 0 ;
}
if ( strcmp ( V_540 -> V_572 , V_300 -> V_572 ) ) {
if ( V_10 -> V_349 . V_105 == V_103 ) {
F_43 ( V_38 , L_118 ,
V_540 -> V_572 , V_300 -> V_572 ) ;
goto V_553;
}
V_561 = F_246 ( V_10 ,
V_300 -> V_572 , L_119 ) ;
if ( F_247 ( V_561 ) ) {
V_561 = NULL ;
goto V_553;
}
}
if ( V_565 >= 89 && strcmp ( V_540 -> V_575 , V_300 -> V_575 ) ) {
if ( V_10 -> V_349 . V_105 == V_103 ) {
F_43 ( V_38 , L_120 ,
V_540 -> V_575 , V_300 -> V_575 ) ;
goto V_553;
}
V_562 = F_246 ( V_10 ,
V_300 -> V_575 , L_121 ) ;
if ( F_247 ( V_562 ) ) {
V_562 = NULL ;
goto V_553;
}
}
if ( V_565 > 94 && V_564 ) {
V_564 -> V_576 = F_123 ( V_300 -> V_576 ) ;
V_564 -> V_577 = F_123 ( V_300 -> V_577 ) ;
V_564 -> V_578 = F_123 ( V_300 -> V_578 ) ;
V_564 -> V_579 = F_123 ( V_300 -> V_579 ) ;
V_569 = ( V_564 -> V_576 * 10 * V_580 ) / V_100 ;
if ( V_569 != V_10 -> V_581 -> V_58 ) {
V_568 = F_254 ( V_569 ) ;
if ( ! V_568 ) {
F_43 ( V_38 , L_122 ) ;
F_131 ( V_10 ) ;
goto V_553;
}
}
}
if ( V_561 || V_562 ) {
V_541 = F_253 ( sizeof( struct V_29 ) , V_554 ) ;
if ( ! V_541 ) {
F_43 ( V_38 , L_109 ) ;
goto V_553;
}
* V_541 = * V_540 ;
if ( V_561 ) {
strcpy ( V_541 -> V_572 , V_300 -> V_572 ) ;
V_541 -> V_582 = strlen ( V_300 -> V_572 ) + 1 ;
F_244 ( V_10 -> V_26 -> V_561 ) ;
V_10 -> V_26 -> V_561 = V_561 ;
F_129 ( V_38 , L_123 , V_300 -> V_572 ) ;
}
if ( V_562 ) {
strcpy ( V_541 -> V_575 , V_300 -> V_575 ) ;
V_541 -> V_583 = strlen ( V_300 -> V_575 ) + 1 ;
F_244 ( V_10 -> V_26 -> V_562 ) ;
V_10 -> V_26 -> V_562 = V_562 ;
F_129 ( V_38 , L_124 , V_300 -> V_575 ) ;
}
F_243 ( V_26 -> V_29 , V_541 ) ;
}
}
if ( V_564 ) {
F_243 ( V_10 -> V_243 -> V_268 , V_564 ) ;
F_131 ( V_10 ) ;
}
if ( V_568 ) {
V_567 = V_10 -> V_581 ;
F_243 ( V_10 -> V_581 , V_568 ) ;
}
F_118 ( & V_10 -> V_26 -> V_225 ) ;
F_245 () ;
if ( V_541 )
F_48 ( V_540 ) ;
F_48 ( V_563 ) ;
F_48 ( V_567 ) ;
return 0 ;
V_574:
if ( V_564 ) {
F_131 ( V_10 ) ;
F_48 ( V_564 ) ;
}
F_118 ( & V_10 -> V_26 -> V_225 ) ;
return - V_108 ;
V_553:
F_48 ( V_568 ) ;
if ( V_564 ) {
F_131 ( V_10 ) ;
F_48 ( V_564 ) ;
}
F_118 ( & V_10 -> V_26 -> V_225 ) ;
F_244 ( V_562 ) ;
F_244 ( V_561 ) ;
F_68 ( V_10 -> V_26 , F_69 ( V_105 , V_150 ) , V_107 ) ;
return - V_108 ;
}
static void F_255 ( struct V_9 * V_10 ,
const char * V_201 , T_3 V_40 , T_3 V_359 )
{
T_3 V_584 ;
if ( V_40 == 0 || V_359 == 0 )
return;
V_584 = ( V_40 > V_359 ) ? ( V_40 - V_359 ) : ( V_359 - V_40 ) ;
if ( V_584 > ( V_40 >> 3 ) || V_584 > ( V_359 >> 3 ) )
F_33 ( V_38 , L_125 , V_201 ,
( unsigned long long ) V_40 , ( unsigned long long ) V_359 ) ;
}
static int F_256 ( struct V_94 * V_26 , struct V_170 * V_171 )
{
struct V_9 * V_10 ;
struct V_585 * V_300 = V_171 -> V_95 ;
enum V_586 V_587 = V_588 ;
T_3 V_589 , V_590 , V_591 ;
int V_592 = 0 ;
enum V_593 V_594 ;
V_10 = F_175 ( V_26 , V_171 -> V_189 ) ;
if ( ! V_10 )
return F_250 ( V_26 , V_171 ) ;
V_589 = F_176 ( V_300 -> V_595 ) ;
V_590 = F_176 ( V_300 -> V_596 ) ;
V_10 -> V_589 = V_589 ;
if ( F_127 ( V_10 ) ) {
F_27 () ;
V_591 = F_28 ( V_10 -> V_243 -> V_268 ) -> V_597 ;
F_29 () ;
F_255 ( V_10 , L_126 ,
V_589 , F_257 ( V_10 -> V_243 ) ) ;
F_255 ( V_10 , L_127 ,
V_590 , V_591 ) ;
if ( V_10 -> V_349 . V_105 == V_103 )
V_590 = F_258 ( V_591 , V_590 ) ;
if ( F_259 ( V_10 , V_10 -> V_243 , V_590 , 0 ) <
F_151 ( V_10 -> V_303 ) &&
V_10 -> V_349 . V_406 >= V_598 &&
V_10 -> V_349 . V_105 < V_531 ) {
F_43 ( V_38 , L_128 ) ;
F_68 ( V_10 -> V_26 , F_69 ( V_105 , V_150 ) , V_107 ) ;
F_131 ( V_10 ) ;
return - V_108 ;
}
if ( V_591 != V_590 ) {
struct V_268 * V_563 , * V_564 = NULL ;
V_564 = F_253 ( sizeof( struct V_268 ) , V_554 ) ;
if ( ! V_564 ) {
F_43 ( V_38 , L_115 ) ;
F_131 ( V_10 ) ;
return - V_282 ;
}
F_117 ( & V_10 -> V_26 -> V_225 ) ;
V_563 = V_10 -> V_243 -> V_268 ;
* V_564 = * V_563 ;
V_564 -> V_597 = V_590 ;
F_243 ( V_10 -> V_243 -> V_268 , V_564 ) ;
F_118 ( & V_10 -> V_26 -> V_225 ) ;
F_245 () ;
F_48 ( V_563 ) ;
F_129 ( V_38 , L_129 ,
( unsigned long ) V_591 ) ;
}
F_131 ( V_10 ) ;
}
V_594 = F_122 ( V_300 -> V_593 ) ;
if ( F_127 ( V_10 ) ) {
V_587 = F_260 ( V_10 , V_594 , NULL ) ;
F_131 ( V_10 ) ;
if ( V_587 == V_599 )
return - V_108 ;
F_261 ( V_10 ) ;
} else {
F_262 ( V_10 , V_589 ) ;
}
V_10 -> V_600 = F_123 ( V_300 -> V_601 ) ;
F_263 ( V_10 ) ;
if ( F_127 ( V_10 ) ) {
if ( V_10 -> V_243 -> V_602 != F_151 ( V_10 -> V_243 -> V_244 ) ) {
V_10 -> V_243 -> V_602 = F_151 ( V_10 -> V_243 -> V_244 ) ;
V_592 = 1 ;
}
F_131 ( V_10 ) ;
}
if ( V_10 -> V_349 . V_105 > V_103 ) {
if ( F_176 ( V_300 -> V_603 ) !=
F_151 ( V_10 -> V_303 ) || V_592 ) {
F_98 ( V_10 , 0 , V_594 ) ;
}
if ( F_264 ( V_184 , & V_10 -> V_63 ) ||
( V_587 == V_604 && V_10 -> V_349 . V_105 == V_531 ) ) {
if ( V_10 -> V_349 . V_401 >= V_402 &&
V_10 -> V_349 . V_406 >= V_402 ) {
if ( V_594 & V_605 )
F_129 ( V_38 , L_130 ) ;
else
F_265 ( V_10 ) ;
} else
F_107 ( V_606 , & V_10 -> V_63 ) ;
}
}
return 0 ;
}
static int F_266 ( struct V_94 * V_26 , struct V_170 * V_171 )
{
struct V_9 * V_10 ;
struct V_607 * V_300 = V_171 -> V_95 ;
T_2 * V_477 ;
int V_6 , V_608 = 0 ;
V_10 = F_175 ( V_26 , V_171 -> V_189 ) ;
if ( ! V_10 )
return F_250 ( V_26 , V_171 ) ;
V_477 = F_148 ( sizeof( T_2 ) * V_609 , V_211 ) ;
if ( ! V_477 ) {
F_43 ( V_38 , L_131 ) ;
return false ;
}
for ( V_6 = V_499 ; V_6 < V_609 ; V_6 ++ )
V_477 [ V_6 ] = F_176 ( V_300 -> V_475 [ V_6 ] ) ;
F_48 ( V_10 -> V_477 ) ;
V_10 -> V_477 = V_477 ;
if ( V_10 -> V_349 . V_105 < V_531 &&
V_10 -> V_349 . V_406 < V_402 &&
V_10 -> V_349 . V_493 == V_466 &&
( V_10 -> V_610 & ~ ( ( T_2 ) 1 ) ) != ( V_477 [ V_499 ] & ~ ( ( T_2 ) 1 ) ) ) {
F_43 ( V_38 , L_132 ,
( unsigned long long ) V_10 -> V_610 ) ;
F_68 ( V_10 -> V_26 , F_69 ( V_105 , V_150 ) , V_107 ) ;
return - V_108 ;
}
if ( F_127 ( V_10 ) ) {
int V_611 =
V_10 -> V_349 . V_105 == V_531 &&
V_10 -> V_26 -> V_180 >= 90 &&
V_10 -> V_243 -> V_474 . V_475 [ V_499 ] == V_504 &&
( V_477 [ V_507 ] & 8 ) ;
if ( V_611 ) {
F_129 ( V_38 , L_133 ) ;
F_239 ( V_10 , & V_612 ,
L_134 ,
V_613 ) ;
F_267 ( V_10 , V_499 , V_477 [ V_499 ] ) ;
F_267 ( V_10 , V_476 , 0 ) ;
F_268 ( F_269 ( V_10 , V_406 , V_439 , V_401 , V_439 ) ,
V_196 , NULL ) ;
F_261 ( V_10 ) ;
V_608 = 1 ;
}
F_131 ( V_10 ) ;
} else if ( V_10 -> V_349 . V_406 < V_402 &&
V_10 -> V_349 . V_493 == V_466 ) {
V_608 = F_270 ( V_10 , V_477 [ V_499 ] ) ;
}
F_117 ( V_10 -> V_179 ) ;
F_118 ( V_10 -> V_179 ) ;
if ( V_10 -> V_349 . V_105 >= V_531 && V_10 -> V_349 . V_406 < V_402 )
V_608 |= F_270 ( V_10 , V_477 [ V_499 ] ) ;
if ( V_608 )
F_271 ( V_10 , L_135 ) ;
return 0 ;
}
static union V_614 F_272 ( union V_614 V_615 )
{
union V_614 V_616 ;
static enum V_510 V_617 [] = {
[ V_103 ] = V_103 ,
[ V_531 ] = V_531 ,
[ V_618 ] = V_619 ,
[ V_619 ] = V_618 ,
[ V_150 ] = V_620 ,
[ V_428 ] = V_429 ,
[ V_515 ] = V_515 ,
} ;
V_616 . V_6 = V_615 . V_6 ;
V_616 . V_105 = V_617 [ V_615 . V_105 ] ;
V_616 . V_465 = V_615 . V_493 ;
V_616 . V_493 = V_615 . V_465 ;
V_616 . V_401 = V_615 . V_406 ;
V_616 . V_406 = V_615 . V_401 ;
V_616 . V_621 = ( V_615 . V_622 | V_615 . V_623 ) ;
return V_616 ;
}
static int F_273 ( struct V_94 * V_26 , struct V_170 * V_171 )
{
struct V_9 * V_10 ;
struct V_624 * V_300 = V_171 -> V_95 ;
union V_614 V_625 , V_626 ;
enum V_194 V_92 ;
V_10 = F_175 ( V_26 , V_171 -> V_189 ) ;
if ( ! V_10 )
return - V_108 ;
V_625 . V_6 = F_123 ( V_300 -> V_625 ) ;
V_626 . V_6 = F_123 ( V_300 -> V_626 ) ;
if ( F_66 ( V_203 , & V_10 -> V_26 -> V_63 ) &&
F_274 ( V_10 -> V_179 ) ) {
F_275 ( V_10 , V_627 ) ;
return 0 ;
}
V_625 = F_272 ( V_625 ) ;
V_626 = F_272 ( V_626 ) ;
V_92 = F_230 ( V_10 , V_196 , V_625 , V_626 ) ;
F_275 ( V_10 , V_92 ) ;
F_261 ( V_10 ) ;
return 0 ;
}
static int F_276 ( struct V_94 * V_26 , struct V_170 * V_171 )
{
struct V_624 * V_300 = V_171 -> V_95 ;
union V_614 V_625 , V_626 ;
enum V_194 V_92 ;
V_625 . V_6 = F_123 ( V_300 -> V_625 ) ;
V_626 . V_6 = F_123 ( V_300 -> V_626 ) ;
if ( F_66 ( V_203 , & V_26 -> V_63 ) &&
F_274 ( & V_26 -> V_181 ) ) {
F_277 ( V_26 , V_627 ) ;
return 0 ;
}
V_625 = F_272 ( V_625 ) ;
V_626 = F_272 ( V_626 ) ;
V_92 = F_68 ( V_26 , V_625 , V_626 , V_196 | V_628 | V_629 ) ;
F_277 ( V_26 , V_92 ) ;
return 0 ;
}
static int F_278 ( struct V_94 * V_26 , struct V_170 * V_171 )
{
struct V_9 * V_10 ;
struct V_630 * V_300 = V_171 -> V_95 ;
union V_614 V_631 , V_632 , V_633 ;
enum V_513 V_634 ;
enum V_635 V_636 ;
int V_92 ;
V_10 = F_175 ( V_26 , V_171 -> V_189 ) ;
if ( ! V_10 )
return F_250 ( V_26 , V_171 ) ;
V_633 . V_6 = F_123 ( V_300 -> V_349 ) ;
V_634 = V_633 . V_406 ;
if ( V_633 . V_406 == V_506 ) {
V_634 = V_10 -> V_477 [ V_507 ] & 4 ? V_402 : V_525 ;
F_129 ( V_38 , L_136 , F_279 ( V_634 ) ) ;
}
F_21 ( & V_10 -> V_26 -> V_27 ) ;
V_28:
V_631 = V_632 = F_280 ( V_10 ) ;
F_22 ( & V_10 -> V_26 -> V_27 ) ;
if ( V_631 . V_105 <= V_620 )
return - V_96 ;
if ( ( V_631 . V_401 == V_402 || V_631 . V_401 == V_525 ) &&
V_634 == V_439 &&
V_631 . V_105 > V_531 && V_631 . V_406 == V_439 ) {
if ( V_633 . V_105 > V_531 &&
V_633 . V_105 < V_350 )
V_634 = V_402 ;
else if ( V_631 . V_105 >= V_350 &&
V_633 . V_105 == V_531 ) {
if ( F_218 ( V_10 ) <= V_10 -> V_431 )
F_281 ( V_10 ) ;
return 0 ;
}
}
if ( V_631 . V_105 == V_429 && V_631 . V_406 == V_439 &&
V_633 . V_105 == V_531 && V_634 == V_439 ) {
F_282 ( V_10 ) ;
F_281 ( V_10 ) ;
return 0 ;
}
if ( V_631 . V_401 == V_439 && V_634 == V_402 &&
V_631 . V_105 == V_531 && V_633 . V_105 > V_350 )
V_634 = V_439 ;
if ( V_632 . V_105 == V_103 )
V_632 . V_105 = V_531 ;
if ( V_633 . V_105 == V_637 )
V_632 . V_105 = V_638 ;
if ( V_10 -> V_477 && V_633 . V_406 >= V_506 &&
F_137 ( V_10 , V_506 ) ) {
int V_639 ;
V_639 = ( V_631 . V_105 < V_531 ) ;
V_639 |= ( V_631 . V_105 == V_531 &&
( V_633 . V_406 == V_506 ||
V_631 . V_406 == V_506 ) ) ;
V_639 |= F_66 ( V_640 , & V_10 -> V_63 ) ;
V_639 |= ( V_631 . V_105 == V_531 &&
( V_633 . V_105 >= V_618 &&
V_633 . V_105 <= V_530 ) ) ;
if ( V_639 )
V_632 . V_105 = F_237 ( V_10 , V_633 . V_493 , V_634 ) ;
F_131 ( V_10 ) ;
if ( V_632 . V_105 == V_515 ) {
V_632 . V_105 = V_531 ;
if ( V_10 -> V_349 . V_406 == V_506 ) {
F_283 ( V_10 , F_69 ( V_406 , V_641 ) ) ;
} else if ( V_633 . V_406 == V_506 ) {
F_43 ( V_38 , L_137 ) ;
V_633 . V_406 = V_642 ;
V_634 = V_642 ;
} else {
if ( F_264 ( V_526 , & V_10 -> V_26 -> V_63 ) )
return - V_108 ;
F_49 ( V_631 . V_105 == V_103 ) ;
F_68 ( V_10 -> V_26 , F_69 ( V_105 , V_150 ) , V_107 ) ;
return - V_108 ;
}
}
}
F_21 ( & V_10 -> V_26 -> V_27 ) ;
if ( V_631 . V_6 != F_280 ( V_10 ) . V_6 )
goto V_28;
F_101 ( V_640 , & V_10 -> V_63 ) ;
V_632 . V_465 = V_633 . V_493 ;
V_632 . V_401 = V_634 ;
V_632 . V_621 = ( V_633 . V_622 | V_633 . V_623 ) ;
if ( ( V_632 . V_105 == V_531 || V_632 . V_105 == V_529 ) && V_632 . V_406 == V_506 )
V_632 . V_406 = V_10 -> V_519 . V_406 ;
V_636 = V_196 + ( V_631 . V_105 < V_531 && V_632 . V_105 >= V_531 ? 0 : V_107 ) ;
if ( V_632 . V_401 == V_525 && F_284 ( V_10 ) && V_632 . V_105 == V_531 && V_631 . V_105 < V_531 &&
F_66 ( V_643 , & V_10 -> V_63 ) ) {
F_22 ( & V_10 -> V_26 -> V_27 ) ;
F_43 ( V_38 , L_138 ) ;
F_285 ( V_10 -> V_26 ) ;
F_286 ( V_10 ) ;
F_101 ( V_643 , & V_10 -> V_63 ) ;
F_68 ( V_10 -> V_26 , F_287 ( V_105 , V_644 , V_645 , 0 ) , V_107 ) ;
return - V_108 ;
}
V_92 = F_268 ( V_10 , V_632 , V_636 , NULL ) ;
V_632 = F_280 ( V_10 ) ;
F_22 ( & V_10 -> V_26 -> V_27 ) ;
if ( V_92 < V_197 ) {
F_68 ( V_10 -> V_26 , F_69 ( V_105 , V_150 ) , V_107 ) ;
return - V_108 ;
}
if ( V_631 . V_105 > V_103 ) {
if ( V_632 . V_105 > V_531 && V_633 . V_105 <= V_531 &&
V_633 . V_406 != V_506 ) {
F_99 ( V_10 ) ;
F_100 ( V_10 ) ;
}
}
F_101 ( V_222 , & V_10 -> V_63 ) ;
F_261 ( V_10 ) ;
return 0 ;
}
static int F_288 ( struct V_94 * V_26 , struct V_170 * V_171 )
{
struct V_9 * V_10 ;
struct V_646 * V_300 = V_171 -> V_95 ;
V_10 = F_175 ( V_26 , V_171 -> V_189 ) ;
if ( ! V_10 )
return - V_108 ;
F_209 ( V_10 -> V_297 ,
V_10 -> V_349 . V_105 == V_647 ||
V_10 -> V_349 . V_105 == V_638 ||
V_10 -> V_349 . V_105 < V_531 ||
V_10 -> V_349 . V_406 < V_506 ) ;
if ( F_137 ( V_10 , V_506 ) ) {
F_267 ( V_10 , V_499 , F_176 ( V_300 -> V_475 ) ) ;
F_267 ( V_10 , V_476 , 0UL ) ;
F_271 ( V_10 , L_139 ) ;
F_289 ( V_10 , V_394 ) ;
F_131 ( V_10 ) ;
} else
F_43 ( V_38 , L_140 ) ;
return 0 ;
}
static int
F_290 ( struct V_9 * V_10 , unsigned int V_58 ,
unsigned long * V_300 , struct V_648 * V_649 )
{
unsigned int V_47 = V_558 -
F_93 ( V_10 -> V_26 ) ;
unsigned int V_650 = F_75 ( T_6 , V_47 / sizeof( * V_300 ) ,
V_649 -> V_651 - V_649 -> V_652 ) ;
unsigned int V_653 = V_650 * sizeof( * V_300 ) ;
int V_70 ;
if ( V_653 != V_58 ) {
F_43 ( V_38 , L_141 , V_55 , V_653 , V_58 ) ;
return - V_108 ;
}
if ( V_653 == 0 )
return 0 ;
V_70 = F_70 ( V_10 -> V_26 , V_300 , V_653 ) ;
if ( V_70 )
return V_70 ;
F_291 ( V_10 , V_649 -> V_652 , V_650 , V_300 ) ;
V_649 -> V_652 += V_650 ;
V_649 -> V_654 = V_649 -> V_652 * V_655 ;
if ( V_649 -> V_654 > V_649 -> V_656 )
V_649 -> V_654 = V_649 -> V_656 ;
return 1 ;
}
static enum V_657 F_292 ( struct V_658 * V_300 )
{
return (enum V_657 ) ( V_300 -> V_659 & 0x0f ) ;
}
static int F_293 ( struct V_658 * V_300 )
{
return ( V_300 -> V_659 & 0x80 ) != 0 ;
}
static int F_294 ( struct V_658 * V_300 )
{
return ( V_300 -> V_659 >> 4 ) & 0x7 ;
}
static int
F_295 ( struct V_9 * V_10 ,
struct V_658 * V_300 ,
struct V_648 * V_649 ,
unsigned int V_5 )
{
struct V_660 V_661 ;
T_2 V_662 ;
T_2 V_663 ;
T_2 V_4 ;
unsigned long V_201 = V_649 -> V_654 ;
unsigned long V_664 ;
int V_665 = F_293 ( V_300 ) ;
int V_666 ;
int V_498 ;
F_296 ( & V_661 , V_300 -> V_667 , V_5 , F_294 ( V_300 ) ) ;
V_498 = F_297 ( & V_661 , & V_662 , 64 ) ;
if ( V_498 < 0 )
return - V_108 ;
for ( V_666 = V_498 ; V_666 > 0 ; V_201 += V_663 , V_665 = ! V_665 ) {
V_498 = F_298 ( & V_663 , V_662 ) ;
if ( V_498 <= 0 )
return - V_108 ;
if ( V_665 ) {
V_664 = V_201 + V_663 - 1 ;
if ( V_664 >= V_649 -> V_656 ) {
F_43 ( V_38 , L_142 , V_664 ) ;
return - V_108 ;
}
F_299 ( V_10 , V_201 , V_664 ) ;
}
if ( V_666 < V_498 ) {
F_43 ( V_38 , L_143 ,
V_666 , V_498 , V_662 ,
( unsigned int ) ( V_661 . V_668 . V_359 - V_300 -> V_667 ) ,
( unsigned int ) V_661 . V_669 ) ;
return - V_108 ;
}
if ( F_164 ( V_498 < 64 ) )
V_662 >>= V_498 ;
else
V_662 = 0 ;
V_666 -= V_498 ;
V_498 = F_297 ( & V_661 , & V_4 , 64 - V_666 ) ;
if ( V_498 < 0 )
return - V_108 ;
V_662 |= V_4 << V_666 ;
V_666 += V_498 ;
}
V_649 -> V_654 = V_201 ;
F_300 ( V_649 ) ;
return ( V_201 != V_649 -> V_656 ) ;
}
static int
F_301 ( struct V_9 * V_10 ,
struct V_658 * V_300 ,
struct V_648 * V_649 ,
unsigned int V_5 )
{
if ( F_292 ( V_300 ) == V_670 )
return F_295 ( V_10 , V_300 , V_649 , V_5 - sizeof( * V_300 ) ) ;
F_43 ( V_38 , L_144 , V_300 -> V_659 ) ;
F_68 ( V_10 -> V_26 , F_69 ( V_105 , V_644 ) , V_107 ) ;
return - V_108 ;
}
void F_302 ( struct V_9 * V_10 ,
const char * V_671 , struct V_648 * V_649 )
{
unsigned int V_169 = F_93 ( V_10 -> V_26 ) ;
unsigned int V_47 = V_558 - V_169 ;
unsigned int V_672 =
V_169 * ( F_303 ( V_649 -> V_651 , V_47 ) + 1 ) +
V_649 -> V_651 * sizeof( unsigned long ) ;
unsigned int V_673 = V_649 -> V_674 [ 0 ] + V_649 -> V_674 [ 1 ] ;
unsigned int V_675 ;
if ( V_673 == 0 )
return;
if ( V_673 >= V_672 )
return;
V_675 = ( V_673 > V_676 / 1000 ) ? ( V_673 / ( V_672 / 1000 ) )
: ( 1000 * V_673 / V_672 ) ;
if ( V_675 > 1000 )
V_675 = 1000 ;
V_675 = 1000 - V_675 ;
F_129 ( V_38 , L_145
L_146 ,
V_671 ,
V_649 -> V_674 [ 1 ] , V_649 -> V_677 [ 1 ] ,
V_649 -> V_674 [ 0 ] , V_649 -> V_677 [ 0 ] ,
V_673 , V_675 / 10 , V_675 % 10 ) ;
}
static int F_304 ( struct V_94 * V_26 , struct V_170 * V_171 )
{
struct V_9 * V_10 ;
struct V_648 V_649 ;
int V_70 ;
V_10 = F_175 ( V_26 , V_171 -> V_189 ) ;
if ( ! V_10 )
return - V_108 ;
F_305 ( V_10 , L_147 , V_528 ) ;
V_649 = (struct V_648 ) {
. V_656 = F_225 ( V_10 ) ,
. V_651 = F_306 ( V_10 ) ,
} ;
for(; ; ) {
if ( V_171 -> V_168 == V_678 )
V_70 = F_290 ( V_10 , V_171 -> V_58 , V_171 -> V_95 , & V_649 ) ;
else if ( V_171 -> V_168 == V_679 ) {
struct V_658 * V_300 = V_171 -> V_95 ;
if ( V_171 -> V_58 > V_558 - F_93 ( V_26 ) ) {
F_43 ( V_38 , L_148 ) ;
V_70 = - V_108 ;
goto V_104;
}
if ( V_171 -> V_58 <= sizeof( * V_300 ) ) {
F_43 ( V_38 , L_149 , V_171 -> V_58 ) ;
V_70 = - V_108 ;
goto V_104;
}
V_70 = F_70 ( V_10 -> V_26 , V_300 , V_171 -> V_58 ) ;
if ( V_70 )
goto V_104;
V_70 = F_301 ( V_10 , V_300 , & V_649 , V_171 -> V_58 ) ;
} else {
F_33 ( V_38 , L_150 , V_171 -> V_168 ) ;
V_70 = - V_108 ;
goto V_104;
}
V_649 . V_677 [ V_171 -> V_168 == V_678 ] ++ ;
V_649 . V_674 [ V_171 -> V_168 == V_678 ] += F_93 ( V_26 ) + V_171 -> V_58 ;
if ( V_70 <= 0 ) {
if ( V_70 < 0 )
goto V_104;
break;
}
V_70 = F_125 ( V_10 -> V_26 , V_171 ) ;
if ( V_70 )
goto V_104;
}
F_302 ( V_10 , L_151 , & V_649 ) ;
if ( V_10 -> V_349 . V_105 == V_530 ) {
enum V_194 V_92 ;
V_70 = F_307 ( V_10 ) ;
if ( V_70 )
goto V_104;
V_92 = F_308 ( V_10 , F_69 ( V_105 , V_647 ) , V_196 ) ;
F_49 ( V_92 == V_197 ) ;
} else if ( V_10 -> V_349 . V_105 != V_529 ) {
F_129 ( V_38 , L_152 ,
F_238 ( V_10 -> V_349 . V_105 ) ) ;
}
V_70 = 0 ;
V_104:
F_309 ( V_10 ) ;
if ( ! V_70 && V_10 -> V_349 . V_105 == V_529 )
F_289 ( V_10 , V_350 ) ;
return V_70 ;
}
static int F_310 ( struct V_94 * V_26 , struct V_170 * V_171 )
{
F_72 ( V_26 , L_153 ,
V_171 -> V_168 , V_171 -> V_58 ) ;
return F_249 ( V_26 , V_171 ) ;
}
static int F_311 ( struct V_94 * V_26 , struct V_170 * V_171 )
{
F_312 ( V_26 -> V_95 . V_76 ) ;
return 0 ;
}
static int F_313 ( struct V_94 * V_26 , struct V_170 * V_171 )
{
struct V_9 * V_10 ;
struct V_680 * V_300 = V_171 -> V_95 ;
V_10 = F_175 ( V_26 , V_171 -> V_189 ) ;
if ( ! V_10 )
return - V_108 ;
switch ( V_10 -> V_349 . V_105 ) {
case V_647 :
case V_530 :
case V_638 :
break;
default:
F_43 ( V_38 , L_154 ,
F_238 ( V_10 -> V_349 . V_105 ) ) ;
}
F_210 ( V_10 , F_176 ( V_300 -> V_46 ) , F_123 ( V_300 -> V_438 ) ) ;
return 0 ;
}
static void F_314 ( struct V_94 * V_26 )
{
struct V_170 V_171 ;
T_6 V_681 ;
int V_70 ;
while ( F_110 ( & V_26 -> V_208 ) == V_682 ) {
struct V_683 * V_168 ;
F_315 ( & V_26 -> V_208 ) ;
if ( F_125 ( V_26 , & V_171 ) )
goto V_684;
V_168 = & V_685 [ V_171 . V_168 ] ;
if ( F_177 ( V_171 . V_168 >= F_316 ( V_685 ) || ! V_168 -> V_686 ) ) {
F_65 ( V_26 , L_155 ,
F_251 ( V_171 . V_168 ) , V_171 . V_168 ) ;
goto V_684;
}
V_681 = V_168 -> V_687 ;
if ( V_171 . V_58 > V_681 && ! V_168 -> V_688 ) {
F_65 ( V_26 , L_156 ,
F_251 ( V_171 . V_168 ) , V_171 . V_58 ) ;
goto V_684;
}
if ( V_681 ) {
V_70 = F_71 ( V_26 , V_171 . V_95 , V_681 ) ;
if ( V_70 )
goto V_684;
V_171 . V_58 -= V_681 ;
}
V_70 = V_168 -> V_686 ( V_26 , & V_171 ) ;
if ( V_70 ) {
F_65 ( V_26 , L_157 ,
F_251 ( V_171 . V_168 ) , V_70 , V_171 . V_58 ) ;
goto V_684;
}
}
return;
V_684:
F_68 ( V_26 , F_69 ( V_105 , V_644 ) , V_107 ) ;
}
void F_317 ( struct V_94 * V_26 )
{
struct V_689 V_690 ;
V_690 . V_22 . V_73 = V_691 ;
V_690 . V_22 . V_26 = V_26 ;
F_318 ( & V_690 . V_692 ) ;
F_319 ( & V_26 -> V_693 , & V_690 . V_22 ) ;
F_320 ( & V_690 . V_692 ) ;
}
static void F_321 ( struct V_94 * V_26 )
{
struct V_9 * V_10 ;
enum V_510 V_694 ;
int V_189 ;
if ( V_26 -> V_102 == V_695 )
return;
F_68 ( V_26 , F_69 ( V_105 , V_696 ) , V_107 ) ;
F_322 ( & V_26 -> V_224 ) ;
F_323 ( V_26 ) ;
F_27 () ;
F_115 (&tconn->volumes, mdev, vnr) {
F_116 ( & V_10 -> V_221 ) ;
F_29 () ;
F_324 ( V_10 ) ;
F_119 ( & V_10 -> V_221 , & V_223 ) ;
F_27 () ;
}
F_29 () ;
if ( ! F_56 ( & V_26 -> V_261 -> V_23 ) )
F_65 ( V_26 , L_158 ) ;
F_45 ( & V_26 -> V_261 -> V_250 , 0 ) ;
V_26 -> V_697 . V_698 = false ;
F_64 ( V_26 , L_159 ) ;
if ( F_325 ( V_26 ) == V_466 && F_326 ( V_26 ) >= V_699 )
F_327 ( V_26 ) ;
F_21 ( & V_26 -> V_27 ) ;
V_694 = V_26 -> V_102 ;
if ( V_694 >= V_700 )
F_206 ( V_26 , F_69 ( V_105 , V_700 ) , V_196 ) ;
F_22 ( & V_26 -> V_27 ) ;
if ( V_694 == V_150 )
F_68 ( V_26 , F_69 ( V_105 , V_695 ) , V_196 | V_107 ) ;
}
static int F_324 ( struct V_9 * V_10 )
{
unsigned int V_6 ;
F_21 ( & V_10 -> V_26 -> V_27 ) ;
F_55 ( V_10 , & V_10 -> V_298 ) ;
F_55 ( V_10 , & V_10 -> V_329 ) ;
F_55 ( V_10 , & V_10 -> V_467 ) ;
F_22 ( & V_10 -> V_26 -> V_27 ) ;
F_328 ( V_10 ) ;
V_10 -> V_463 = 0 ;
V_10 -> V_431 = 0 ;
F_45 ( & V_10 -> V_701 , 0 ) ;
F_39 ( & V_10 -> V_297 ) ;
F_329 ( & V_10 -> V_702 ) ;
F_330 ( ( unsigned long ) V_10 ) ;
F_331 ( V_10 ) ;
F_53 ( V_10 ) ;
F_331 ( V_10 ) ;
F_328 ( V_10 ) ;
F_48 ( V_10 -> V_477 ) ;
V_10 -> V_477 = NULL ;
if ( ! F_284 ( V_10 ) )
F_285 ( V_10 -> V_26 ) ;
F_261 ( V_10 ) ;
F_209 ( V_10 -> V_297 , ! F_66 ( V_703 , & V_10 -> V_63 ) ) ;
V_6 = F_51 ( V_10 , & V_10 -> V_69 ) ;
if ( V_6 )
F_129 ( V_38 , L_160 , V_6 ) ;
V_6 = F_30 ( & V_10 -> V_41 ) ;
if ( V_6 )
F_129 ( V_38 , L_161 , V_6 ) ;
V_6 = F_30 ( & V_10 -> V_34 ) ;
if ( V_6 )
F_129 ( V_38 , L_162 , V_6 ) ;
F_49 ( F_56 ( & V_10 -> V_467 ) ) ;
F_49 ( F_56 ( & V_10 -> V_298 ) ) ;
F_49 ( F_56 ( & V_10 -> V_329 ) ) ;
F_49 ( F_56 ( & V_10 -> V_71 ) ) ;
return 0 ;
}
static int F_332 ( struct V_94 * V_26 )
{
struct V_166 * V_77 ;
struct V_704 * V_300 ;
V_77 = & V_26 -> V_95 ;
V_300 = F_90 ( V_26 , V_77 ) ;
if ( ! V_300 )
return - V_108 ;
memset ( V_300 , 0 , sizeof( * V_300 ) ) ;
V_300 -> V_705 = F_121 ( V_706 ) ;
V_300 -> V_707 = F_121 ( V_708 ) ;
return F_91 ( V_26 , V_77 , V_709 , sizeof( * V_300 ) , NULL , 0 ) ;
}
static int F_112 ( struct V_94 * V_26 )
{
struct V_704 * V_300 ;
const int F_153 = sizeof( struct V_704 ) ;
struct V_170 V_171 ;
int V_70 ;
V_70 = F_332 ( V_26 ) ;
if ( V_70 )
return 0 ;
V_70 = F_125 ( V_26 , & V_171 ) ;
if ( V_70 )
return 0 ;
if ( V_171 . V_168 != V_709 ) {
F_65 ( V_26 , L_163 ,
F_251 ( V_171 . V_168 ) , V_171 . V_168 ) ;
return - 1 ;
}
if ( V_171 . V_58 != F_153 ) {
F_65 ( V_26 , L_164 ,
F_153 , V_171 . V_58 ) ;
return - 1 ;
}
V_300 = V_171 . V_95 ;
V_70 = F_71 ( V_26 , V_300 , F_153 ) ;
if ( V_70 )
return 0 ;
V_300 -> V_705 = F_123 ( V_300 -> V_705 ) ;
V_300 -> V_707 = F_123 ( V_300 -> V_707 ) ;
if ( V_300 -> V_707 == 0 )
V_300 -> V_707 = V_300 -> V_705 ;
if ( V_708 < V_300 -> V_705 ||
V_706 > V_300 -> V_707 )
goto V_710;
V_26 -> V_180 = F_75 ( int , V_708 , V_300 -> V_707 ) ;
F_64 ( V_26 , L_165
L_166 , V_26 -> V_180 ) ;
return 1 ;
V_710:
F_65 ( V_26 , L_167
L_168 ,
V_706 , V_708 ,
V_300 -> V_705 , V_300 -> V_707 ) ;
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
char V_711 [ V_712 ] ;
struct V_713 V_714 ;
char * V_715 = NULL ;
char * V_716 = NULL ;
char * V_717 = NULL ;
unsigned int V_718 ;
char V_719 [ V_543 ] ;
unsigned int V_720 ;
struct V_721 V_722 ;
struct V_170 V_171 ;
struct V_29 * V_30 ;
int V_70 , V_92 ;
F_27 () ;
V_30 = F_28 ( V_26 -> V_29 ) ;
V_718 = strlen ( V_30 -> V_723 ) ;
memcpy ( V_719 , V_30 -> V_723 , V_718 ) ;
F_29 () ;
V_722 . V_557 = V_26 -> V_217 ;
V_722 . V_63 = 0 ;
V_92 = F_333 ( V_26 -> V_217 , ( V_724 * ) V_719 , V_718 ) ;
if ( V_92 ) {
F_65 ( V_26 , L_171 , V_92 ) ;
V_92 = - 1 ;
goto V_57;
}
F_334 ( V_711 , V_712 ) ;
V_77 = & V_26 -> V_95 ;
if ( ! F_90 ( V_26 , V_77 ) ) {
V_92 = 0 ;
goto V_57;
}
V_92 = ! F_91 ( V_26 , V_77 , V_725 , 0 ,
V_711 , V_712 ) ;
if ( ! V_92 )
goto V_57;
V_70 = F_125 ( V_26 , & V_171 ) ;
if ( V_70 ) {
V_92 = 0 ;
goto V_57;
}
if ( V_171 . V_168 != V_725 ) {
F_65 ( V_26 , L_172 ,
F_251 ( V_171 . V_168 ) , V_171 . V_168 ) ;
V_92 = 0 ;
goto V_57;
}
if ( V_171 . V_58 > V_712 * 2 ) {
F_65 ( V_26 , L_173 ) ;
V_92 = - 1 ;
goto V_57;
}
V_717 = F_148 ( V_171 . V_58 , V_211 ) ;
if ( V_717 == NULL ) {
F_65 ( V_26 , L_174 ) ;
V_92 = - 1 ;
goto V_57;
}
V_70 = F_71 ( V_26 , V_717 , V_171 . V_58 ) ;
if ( V_70 ) {
V_92 = 0 ;
goto V_57;
}
V_720 = F_152 ( V_26 -> V_217 ) ;
V_715 = F_148 ( V_720 , V_211 ) ;
if ( V_715 == NULL ) {
F_65 ( V_26 , L_175 ) ;
V_92 = - 1 ;
goto V_57;
}
F_335 ( & V_714 , 1 ) ;
F_336 ( & V_714 , V_717 , V_171 . V_58 ) ;
V_92 = F_337 ( & V_722 , & V_714 , V_714 . V_234 , V_715 ) ;
if ( V_92 ) {
F_65 ( V_26 , L_176 , V_92 ) ;
V_92 = - 1 ;
goto V_57;
}
if ( ! F_90 ( V_26 , V_77 ) ) {
V_92 = 0 ;
goto V_57;
}
V_92 = ! F_91 ( V_26 , V_77 , V_726 , 0 ,
V_715 , V_720 ) ;
if ( ! V_92 )
goto V_57;
V_70 = F_125 ( V_26 , & V_171 ) ;
if ( V_70 ) {
V_92 = 0 ;
goto V_57;
}
if ( V_171 . V_168 != V_726 ) {
F_65 ( V_26 , L_177 ,
F_251 ( V_171 . V_168 ) , V_171 . V_168 ) ;
V_92 = 0 ;
goto V_57;
}
if ( V_171 . V_58 != V_720 ) {
F_65 ( V_26 , L_178 ) ;
V_92 = 0 ;
goto V_57;
}
V_70 = F_71 ( V_26 , V_715 , V_720 ) ;
if ( V_70 ) {
V_92 = 0 ;
goto V_57;
}
V_716 = F_148 ( V_720 , V_211 ) ;
if ( V_716 == NULL ) {
F_65 ( V_26 , L_179 ) ;
V_92 = - 1 ;
goto V_57;
}
F_336 ( & V_714 , V_711 , V_712 ) ;
V_92 = F_337 ( & V_722 , & V_714 , V_714 . V_234 , V_716 ) ;
if ( V_92 ) {
F_65 ( V_26 , L_176 , V_92 ) ;
V_92 = - 1 ;
goto V_57;
}
V_92 = ! memcmp ( V_715 , V_716 , V_720 ) ;
if ( V_92 )
F_64 ( V_26 , L_180 ,
V_720 ) ;
else
V_92 = - 1 ;
V_57:
F_48 ( V_717 ) ;
F_48 ( V_715 ) ;
F_48 ( V_716 ) ;
return V_92 ;
}
int F_338 ( struct V_727 * V_728 )
{
struct V_94 * V_26 = V_728 -> V_26 ;
int V_191 ;
F_64 ( V_26 , L_181 ) ;
do {
V_191 = F_103 ( V_26 ) ;
if ( V_191 == 0 ) {
F_321 ( V_26 ) ;
F_106 ( V_100 ) ;
}
if ( V_191 == - 1 ) {
F_72 ( V_26 , L_182 ) ;
F_68 ( V_26 , F_69 ( V_105 , V_150 ) , V_107 ) ;
}
} while ( V_191 == 0 );
if ( V_191 > 0 )
F_314 ( V_26 ) ;
F_321 ( V_26 ) ;
F_64 ( V_26 , L_183 ) ;
return 0 ;
}
static int F_339 ( struct V_94 * V_26 , struct V_170 * V_171 )
{
struct V_729 * V_300 = V_171 -> V_95 ;
int V_730 = F_123 ( V_300 -> V_730 ) ;
if ( V_730 >= V_197 ) {
F_107 ( V_731 , & V_26 -> V_63 ) ;
} else {
F_107 ( V_732 , & V_26 -> V_63 ) ;
F_65 ( V_26 , L_184 ,
F_340 ( V_730 ) , V_730 ) ;
}
F_39 ( & V_26 -> V_101 ) ;
return 0 ;
}
static int F_341 ( struct V_94 * V_26 , struct V_170 * V_171 )
{
struct V_9 * V_10 ;
struct V_729 * V_300 = V_171 -> V_95 ;
int V_730 = F_123 ( V_300 -> V_730 ) ;
V_10 = F_175 ( V_26 , V_171 -> V_189 ) ;
if ( ! V_10 )
return - V_108 ;
if ( F_66 ( V_733 , & V_26 -> V_63 ) ) {
F_49 ( V_26 -> V_180 < 100 ) ;
return F_339 ( V_26 , V_171 ) ;
}
if ( V_730 >= V_197 ) {
F_107 ( V_734 , & V_10 -> V_63 ) ;
} else {
F_107 ( V_735 , & V_10 -> V_63 ) ;
F_43 ( V_38 , L_184 ,
F_340 ( V_730 ) , V_730 ) ;
}
F_39 ( & V_10 -> V_736 ) ;
return 0 ;
}
static int F_342 ( struct V_94 * V_26 , struct V_170 * V_171 )
{
return F_343 ( V_26 ) ;
}
static int F_344 ( struct V_94 * V_26 , struct V_170 * V_171 )
{
V_26 -> V_200 . V_76 -> V_111 -> V_137 = V_26 -> V_29 -> V_215 * V_100 ;
if ( ! F_345 ( V_737 , & V_26 -> V_63 ) )
F_39 ( & V_26 -> V_101 ) ;
return 0 ;
}
static int F_346 ( struct V_94 * V_26 , struct V_170 * V_171 )
{
struct V_9 * V_10 ;
struct V_738 * V_300 = V_171 -> V_95 ;
T_3 V_46 = F_176 ( V_300 -> V_46 ) ;
int V_438 = F_123 ( V_300 -> V_438 ) ;
V_10 = F_175 ( V_26 , V_171 -> V_189 ) ;
if ( ! V_10 )
return - V_108 ;
F_49 ( V_10 -> V_26 -> V_180 >= 89 ) ;
F_191 ( V_10 , F_123 ( V_300 -> V_390 ) ) ;
if ( F_127 ( V_10 ) ) {
F_347 ( V_10 , V_46 ) ;
F_165 ( V_10 , V_46 , V_438 ) ;
V_10 -> V_739 += ( V_438 >> V_740 ) ;
F_131 ( V_10 ) ;
}
F_170 ( V_10 ) ;
F_36 ( V_438 >> 9 , & V_10 -> V_341 ) ;
return 0 ;
}
static int
F_348 ( struct V_9 * V_10 , T_2 V_45 , T_3 V_46 ,
struct V_333 * V_334 , const char * V_336 ,
enum V_741 V_117 , bool V_335 )
{
struct V_312 * V_313 ;
struct V_382 V_383 ;
F_21 ( & V_10 -> V_26 -> V_27 ) ;
V_313 = F_172 ( V_10 , V_334 , V_45 , V_46 , V_335 , V_336 ) ;
if ( F_177 ( ! V_313 ) ) {
F_22 ( & V_10 -> V_26 -> V_27 ) ;
return - V_108 ;
}
F_184 ( V_313 , V_117 , & V_383 ) ;
F_22 ( & V_10 -> V_26 -> V_27 ) ;
if ( V_383 . V_278 )
F_199 ( V_10 , & V_383 ) ;
return 0 ;
}
static int F_349 ( struct V_94 * V_26 , struct V_170 * V_171 )
{
struct V_9 * V_10 ;
struct V_738 * V_300 = V_171 -> V_95 ;
T_3 V_46 = F_176 ( V_300 -> V_46 ) ;
int V_438 = F_123 ( V_300 -> V_438 ) ;
enum V_741 V_117 ;
V_10 = F_175 ( V_26 , V_171 -> V_189 ) ;
if ( ! V_10 )
return - V_108 ;
F_191 ( V_10 , F_123 ( V_300 -> V_390 ) ) ;
if ( V_300 -> V_64 == V_328 ) {
F_165 ( V_10 , V_46 , V_438 ) ;
F_170 ( V_10 ) ;
return 0 ;
}
switch ( V_171 -> V_168 ) {
case V_326 :
V_117 = V_742 ;
break;
case V_353 :
V_117 = V_743 ;
break;
case V_400 :
V_117 = V_744 ;
break;
case V_357 :
V_117 = V_345 ;
break;
case V_358 :
V_117 = V_745 ;
break;
default:
F_223 () ;
}
return F_348 ( V_10 , V_300 -> V_64 , V_46 ,
& V_10 -> V_296 , V_55 ,
V_117 , false ) ;
}
static int F_350 ( struct V_94 * V_26 , struct V_170 * V_171 )
{
struct V_9 * V_10 ;
struct V_738 * V_300 = V_171 -> V_95 ;
T_3 V_46 = F_176 ( V_300 -> V_46 ) ;
int V_58 = F_123 ( V_300 -> V_438 ) ;
int V_70 ;
V_10 = F_175 ( V_26 , V_171 -> V_189 ) ;
if ( ! V_10 )
return - V_108 ;
F_191 ( V_10 , F_123 ( V_300 -> V_390 ) ) ;
if ( V_300 -> V_64 == V_328 ) {
F_170 ( V_10 ) ;
F_167 ( V_10 , V_46 , V_58 ) ;
return 0 ;
}
V_70 = F_348 ( V_10 , V_300 -> V_64 , V_46 ,
& V_10 -> V_296 , V_55 ,
V_384 , true ) ;
if ( V_70 ) {
F_210 ( V_10 , V_46 , V_58 ) ;
}
return 0 ;
}
static int F_351 ( struct V_94 * V_26 , struct V_170 * V_171 )
{
struct V_9 * V_10 ;
struct V_738 * V_300 = V_171 -> V_95 ;
T_3 V_46 = F_176 ( V_300 -> V_46 ) ;
V_10 = F_175 ( V_26 , V_171 -> V_189 ) ;
if ( ! V_10 )
return - V_108 ;
F_191 ( V_10 , F_123 ( V_300 -> V_390 ) ) ;
F_43 ( V_38 , L_185 ,
( unsigned long long ) V_46 , F_123 ( V_300 -> V_438 ) ) ;
return F_348 ( V_10 , V_300 -> V_64 , V_46 ,
& V_10 -> V_338 , V_55 ,
V_384 , false ) ;
}
static int F_352 ( struct V_94 * V_26 , struct V_170 * V_171 )
{
struct V_9 * V_10 ;
T_3 V_46 ;
int V_58 ;
struct V_738 * V_300 = V_171 -> V_95 ;
V_10 = F_175 ( V_26 , V_171 -> V_189 ) ;
if ( ! V_10 )
return - V_108 ;
V_46 = F_176 ( V_300 -> V_46 ) ;
V_58 = F_123 ( V_300 -> V_438 ) ;
F_191 ( V_10 , F_123 ( V_300 -> V_390 ) ) ;
F_170 ( V_10 ) ;
if ( F_137 ( V_10 , V_641 ) ) {
F_347 ( V_10 , V_46 ) ;
switch ( V_171 -> V_168 ) {
case V_445 :
F_167 ( V_10 , V_46 , V_58 ) ;
case V_746 :
break;
default:
F_223 () ;
}
F_131 ( V_10 ) ;
}
return 0 ;
}
static int F_353 ( struct V_94 * V_26 , struct V_170 * V_171 )
{
struct V_747 * V_300 = V_171 -> V_95 ;
struct V_9 * V_10 ;
int V_189 ;
F_354 ( V_26 , V_300 -> V_301 , F_123 ( V_300 -> V_748 ) ) ;
F_27 () ;
F_115 (&tconn->volumes, mdev, vnr) {
if ( V_10 -> V_349 . V_105 == V_637 &&
F_30 ( & V_10 -> V_185 ) == 0 &&
! F_345 ( V_749 , & V_10 -> V_63 ) ) {
V_10 -> V_750 . V_751 = V_187 + V_100 ;
F_355 ( & V_10 -> V_750 ) ;
}
}
F_29 () ;
return 0 ;
}
static int F_356 ( struct V_94 * V_26 , struct V_170 * V_171 )
{
struct V_9 * V_10 ;
struct V_738 * V_300 = V_171 -> V_95 ;
struct V_323 * V_22 ;
T_3 V_46 ;
int V_58 ;
V_10 = F_175 ( V_26 , V_171 -> V_189 ) ;
if ( ! V_10 )
return - V_108 ;
V_46 = F_176 ( V_300 -> V_46 ) ;
V_58 = F_123 ( V_300 -> V_438 ) ;
F_191 ( V_10 , F_123 ( V_300 -> V_390 ) ) ;
if ( F_176 ( V_300 -> V_64 ) == V_752 )
F_357 ( V_10 , V_46 , V_58 ) ;
else
F_282 ( V_10 ) ;
if ( ! F_127 ( V_10 ) )
return 0 ;
F_347 ( V_10 , V_46 ) ;
F_170 ( V_10 ) ;
-- V_10 -> V_430 ;
if ( ( V_10 -> V_430 & 0x200 ) == 0x200 )
F_358 ( V_10 , V_10 -> V_430 ) ;
if ( V_10 -> V_430 == 0 ) {
V_22 = F_148 ( sizeof( * V_22 ) , V_211 ) ;
if ( V_22 ) {
V_22 -> V_73 = V_753 ;
V_22 -> V_10 = V_10 ;
F_319 ( & V_10 -> V_26 -> V_693 , V_22 ) ;
} else {
F_43 ( V_38 , L_186 ) ;
F_282 ( V_10 ) ;
F_281 ( V_10 ) ;
}
}
F_131 ( V_10 ) ;
return 0 ;
}
static int F_359 ( struct V_94 * V_26 , struct V_170 * V_171 )
{
return 0 ;
}
static int F_360 ( struct V_94 * V_26 )
{
struct V_9 * V_10 ;
int V_189 , V_754 = 0 ;
do {
F_101 ( V_755 , & V_26 -> V_63 ) ;
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
F_107 ( V_755 , & V_26 -> V_63 ) ;
F_21 ( & V_26 -> V_27 ) ;
F_115 (&tconn->volumes, mdev, vnr) {
V_754 = ! F_56 ( & V_10 -> V_71 ) ;
if ( V_754 )
break;
}
F_22 ( & V_26 -> V_27 ) ;
F_29 () ;
} while ( V_754 );
return 0 ;
}
int F_361 ( struct V_727 * V_728 )
{
struct V_94 * V_26 = V_728 -> V_26 ;
struct V_756 * V_168 = NULL ;
struct V_170 V_171 ;
int V_92 ;
void * V_78 = V_26 -> V_200 . V_172 ;
int V_757 = 0 ;
unsigned int V_169 = F_93 ( V_26 ) ;
int F_153 = V_169 ;
bool V_758 = false ;
struct V_29 * V_30 ;
int V_99 , V_759 , V_215 ;
struct V_760 V_761 = { . V_762 = 2 } ;
V_92 = F_362 ( V_37 , V_763 , & V_761 ) ;
if ( V_92 < 0 )
F_65 ( V_26 , L_187 , V_92 ) ;
while ( F_110 ( V_728 ) == V_682 ) {
F_315 ( V_728 ) ;
F_27 () ;
V_30 = F_28 ( V_26 -> V_29 ) ;
V_99 = V_30 -> V_99 ;
V_759 = V_30 -> V_759 ;
V_215 = V_30 -> V_215 ;
F_29 () ;
if ( F_264 ( V_764 , & V_26 -> V_63 ) ) {
if ( F_363 ( V_26 ) ) {
F_65 ( V_26 , L_188 ) ;
goto V_574;
}
V_26 -> V_200 . V_76 -> V_111 -> V_137 = V_99 * V_100 / 10 ;
V_758 = true ;
}
if ( V_759 )
F_364 ( V_26 -> V_200 . V_76 ) ;
if ( F_360 ( V_26 ) ) {
F_65 ( V_26 , L_189 ) ;
goto V_574;
}
if ( V_759 )
F_365 ( V_26 -> V_200 . V_76 ) ;
if ( F_32 ( V_37 ) )
continue;
V_92 = F_59 ( V_26 -> V_200 . V_76 , V_78 , F_153 - V_757 , 0 ) ;
F_101 ( V_755 , & V_26 -> V_63 ) ;
F_108 ( V_37 ) ;
if ( F_164 ( V_92 > 0 ) ) {
V_757 += V_92 ;
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
goto V_574;
} else if ( V_92 == - V_143 ) {
if ( F_366 ( V_26 -> V_216 ,
V_187 - V_26 -> V_200 . V_76 -> V_111 -> V_137 ) )
continue;
if ( V_758 ) {
F_65 ( V_26 , L_191 ) ;
goto V_574;
}
F_107 ( V_764 , & V_26 -> V_63 ) ;
continue;
} else if ( V_92 == - V_145 ) {
continue;
} else {
F_65 ( V_26 , L_7 , V_92 ) ;
goto V_574;
}
if ( V_757 == F_153 && V_168 == NULL ) {
if ( F_94 ( V_26 , V_26 -> V_200 . V_172 , & V_171 ) )
goto V_574;
V_168 = & V_765 [ V_171 . V_168 ] ;
if ( V_171 . V_168 >= F_316 ( V_765 ) || ! V_168 -> V_686 ) {
F_65 ( V_26 , L_192 ,
F_251 ( V_171 . V_168 ) , V_171 . V_168 ) ;
goto V_553;
}
F_153 = V_169 + V_168 -> V_687 ;
if ( V_171 . V_58 != F_153 - V_169 ) {
F_65 ( V_26 , L_193 ,
V_171 . V_168 , V_171 . V_58 ) ;
goto V_574;
}
}
if ( V_757 == F_153 ) {
bool V_70 ;
V_70 = V_168 -> V_686 ( V_26 , & V_171 ) ;
if ( V_70 ) {
F_65 ( V_26 , L_194 , V_168 -> V_686 ) ;
goto V_574;
}
V_26 -> V_216 = V_187 ;
if ( V_168 == & V_765 [ V_766 ] ) {
V_26 -> V_200 . V_76 -> V_111 -> V_137 = V_215 * V_100 ;
V_758 = false ;
}
V_78 = V_26 -> V_200 . V_172 ;
V_757 = 0 ;
F_153 = V_169 ;
V_168 = NULL ;
}
}
if ( 0 ) {
V_574:
F_68 ( V_26 , F_69 ( V_105 , V_696 ) , V_107 ) ;
F_367 ( V_26 ) ;
}
if ( 0 ) {
V_553:
F_68 ( V_26 , F_69 ( V_105 , V_150 ) , V_107 ) ;
}
F_101 ( V_755 , & V_26 -> V_63 ) ;
F_64 ( V_26 , L_195 ) ;
return 0 ;
}
