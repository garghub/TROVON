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
struct V_18 * V_19 , * V_4 ;
F_15 (peer_req, tmp, &device->net_ee, w.list) {
if ( F_16 ( V_19 ) )
break;
F_17 ( & V_19 -> V_20 . V_21 , V_17 ) ;
}
}
static void F_18 ( struct V_9 * V_10 )
{
F_19 ( V_22 ) ;
struct V_18 * V_19 , * V_23 ;
F_20 ( & V_10 -> V_24 -> V_25 ) ;
F_14 ( V_10 , & V_22 ) ;
F_21 ( & V_10 -> V_24 -> V_25 ) ;
F_15 (peer_req, t, &reclaimed, w.list)
F_22 ( V_10 , V_19 ) ;
}
struct V_1 * F_23 ( struct V_26 * V_27 , unsigned int V_11 ,
bool V_28 )
{
struct V_9 * V_10 = V_27 -> V_10 ;
struct V_1 * V_1 = NULL ;
struct V_29 * V_30 ;
F_24 ( V_31 ) ;
unsigned int V_32 ;
F_25 () ;
V_30 = F_26 ( V_27 -> V_33 -> V_29 ) ;
V_32 = V_30 ? V_30 -> V_34 : 1000000 ;
F_27 () ;
if ( F_28 ( & V_10 -> V_35 ) < V_32 )
V_1 = F_10 ( V_10 , V_11 ) ;
while ( V_1 == NULL ) {
F_29 ( & V_36 , & V_31 , V_37 ) ;
F_18 ( V_10 ) ;
if ( F_28 ( & V_10 -> V_35 ) < V_32 ) {
V_1 = F_10 ( V_10 , V_11 ) ;
if ( V_1 )
break;
}
if ( ! V_28 )
break;
if ( F_30 ( V_38 ) ) {
F_31 ( V_10 , L_1 ) ;
break;
}
if ( F_32 ( V_39 / 10 ) == 0 )
V_32 = V_40 ;
}
F_33 ( & V_36 , & V_31 ) ;
if ( V_1 )
F_34 ( V_11 , & V_10 -> V_35 ) ;
return V_1 ;
}
static void F_35 ( struct V_9 * V_10 , struct V_1 * V_1 , int V_41 )
{
T_1 * V_42 = V_41 ? & V_10 -> V_43 : & V_10 -> V_35 ;
int V_6 ;
if ( V_1 == NULL )
return;
if ( V_12 > ( V_44 / V_45 ) * V_46 )
V_6 = F_6 ( V_1 ) ;
else {
struct V_1 * V_4 ;
V_4 = F_5 ( V_1 , & V_6 ) ;
F_11 ( & V_13 ) ;
F_9 ( & V_14 , V_1 , V_4 ) ;
V_12 += V_6 ;
F_12 ( & V_13 ) ;
}
V_6 = F_36 ( V_6 , V_42 ) ;
if ( V_6 < 0 )
F_31 ( V_10 , L_2 ,
V_41 ? L_3 : L_4 , V_6 ) ;
F_37 ( & V_36 ) ;
}
struct V_18 *
F_38 ( struct V_26 * V_27 , T_2 V_47 , T_3 V_48 ,
unsigned int V_49 , bool V_50 , T_4 V_51 ) __must_hold( T_5 )
{
struct V_9 * V_10 = V_27 -> V_10 ;
struct V_18 * V_19 ;
struct V_1 * V_1 = NULL ;
unsigned V_52 = ( V_49 + V_45 - 1 ) >> V_53 ;
if ( F_39 ( V_10 , V_54 ) )
return NULL ;
V_19 = F_40 ( V_55 , V_51 & ~ V_56 ) ;
if ( ! V_19 ) {
if ( ! ( V_51 & V_57 ) )
F_41 ( V_10 , L_5 , V_58 ) ;
return NULL ;
}
if ( V_50 && V_49 ) {
V_1 = F_23 ( V_27 , V_52 , ( V_51 & V_59 ) ) ;
if ( ! V_1 )
goto V_60;
}
F_42 ( & V_19 -> V_6 ) ;
V_19 -> V_6 . V_61 = V_49 ;
V_19 -> V_6 . V_48 = V_48 ;
V_19 -> V_6 . T_5 = false ;
V_19 -> V_6 . V_62 = false ;
V_19 -> V_63 = NULL ;
V_19 -> V_27 = V_27 ;
V_19 -> V_64 = V_1 ;
F_43 ( & V_19 -> V_65 , 0 ) ;
V_19 -> V_66 = 0 ;
V_19 -> V_67 = V_47 ;
return V_19 ;
V_60:
F_44 ( V_19 , V_55 ) ;
return NULL ;
}
void F_45 ( struct V_9 * V_10 , struct V_18 * V_19 ,
int V_41 )
{
if ( V_19 -> V_66 & V_68 )
F_46 ( V_19 -> V_69 ) ;
F_35 ( V_10 , V_19 -> V_64 , V_41 ) ;
F_47 ( V_10 , F_28 ( & V_19 -> V_65 ) == 0 ) ;
F_47 ( V_10 , F_48 ( & V_19 -> V_6 ) ) ;
F_44 ( V_19 , V_55 ) ;
}
int F_49 ( struct V_9 * V_10 , struct V_16 * V_21 )
{
F_19 ( V_70 ) ;
struct V_18 * V_19 , * V_23 ;
int V_71 = 0 ;
int V_41 = V_21 == & V_10 -> V_72 ;
F_20 ( & V_10 -> V_24 -> V_25 ) ;
F_50 ( V_21 , & V_70 ) ;
F_21 ( & V_10 -> V_24 -> V_25 ) ;
F_15 (peer_req, t, &work_list, w.list) {
F_45 ( V_10 , V_19 , V_41 ) ;
V_71 ++ ;
}
return V_71 ;
}
static int F_51 ( struct V_9 * V_10 )
{
F_19 ( V_70 ) ;
F_19 ( V_22 ) ;
struct V_18 * V_19 , * V_23 ;
int V_73 = 0 ;
F_20 ( & V_10 -> V_24 -> V_25 ) ;
F_14 ( V_10 , & V_22 ) ;
F_50 ( & V_10 -> V_74 , & V_70 ) ;
F_21 ( & V_10 -> V_24 -> V_25 ) ;
F_15 (peer_req, t, &reclaimed, w.list)
F_22 ( V_10 , V_19 ) ;
F_15 (peer_req, t, &work_list, w.list) {
int V_75 ;
V_75 = V_19 -> V_20 . V_76 ( & V_19 -> V_20 , ! ! V_73 ) ;
if ( ! V_73 )
V_73 = V_75 ;
F_52 ( V_10 , V_19 ) ;
}
F_37 ( & V_10 -> V_77 ) ;
return V_73 ;
}
static void F_53 ( struct V_9 * V_10 ,
struct V_16 * V_2 )
{
F_24 ( V_31 ) ;
while ( ! F_54 ( V_2 ) ) {
F_29 ( & V_10 -> V_77 , & V_31 , V_78 ) ;
F_21 ( & V_10 -> V_24 -> V_25 ) ;
F_55 () ;
F_33 ( & V_10 -> V_77 , & V_31 ) ;
F_20 ( & V_10 -> V_24 -> V_25 ) ;
}
}
static void F_56 ( struct V_9 * V_10 ,
struct V_16 * V_2 )
{
F_20 ( & V_10 -> V_24 -> V_25 ) ;
F_53 ( V_10 , V_2 ) ;
F_21 ( & V_10 -> V_24 -> V_25 ) ;
}
static int F_57 ( struct V_79 * V_80 , void * V_81 , T_6 V_61 , int V_66 )
{
struct V_82 V_83 = {
. V_84 = V_81 ,
. V_85 = V_61 ,
} ;
struct V_86 V_87 = {
. V_88 = ( V_66 ? V_66 : V_89 | V_90 )
} ;
return F_58 ( V_80 , & V_87 , & V_83 , 1 , V_61 , V_87 . V_88 ) ;
}
static int F_59 ( struct V_91 * V_33 , void * V_81 , T_6 V_61 )
{
int V_92 ;
V_92 = F_57 ( V_33 -> V_93 . V_79 , V_81 , V_61 , 0 ) ;
if ( V_92 < 0 ) {
if ( V_92 == - V_94 )
F_60 ( V_33 , L_6 ) ;
else if ( V_92 != - V_95 )
F_41 ( V_33 , L_7 , V_92 ) ;
} else if ( V_92 == 0 ) {
if ( F_61 ( V_96 , & V_33 -> V_66 ) ) {
long V_23 ;
F_25 () ;
V_23 = F_26 ( V_33 -> V_29 ) -> V_97 * V_39 / 10 ;
F_27 () ;
V_23 = F_62 ( V_33 -> V_98 , V_33 -> V_99 < V_100 , V_23 ) ;
if ( V_23 )
goto V_101;
}
F_60 ( V_33 , L_8 ) ;
}
if ( V_92 != V_61 )
F_63 ( V_33 , F_64 ( V_102 , V_103 ) , V_104 ) ;
V_101:
return V_92 ;
}
static int F_65 ( struct V_91 * V_33 , void * V_81 , T_6 V_61 )
{
int V_73 ;
V_73 = F_59 ( V_33 , V_81 , V_61 ) ;
if ( V_73 != V_61 ) {
if ( V_73 >= 0 )
V_73 = - V_105 ;
} else
V_73 = 0 ;
return V_73 ;
}
static int F_66 ( struct V_91 * V_33 , void * V_81 , T_6 V_61 )
{
int V_73 ;
V_73 = F_65 ( V_33 , V_81 , V_61 ) ;
if ( V_73 && ! F_30 ( V_38 ) )
F_31 ( V_33 , L_9 , ( int ) V_61 ) ;
return V_73 ;
}
static void F_67 ( struct V_79 * V_80 , unsigned int V_106 ,
unsigned int V_107 )
{
if ( V_106 ) {
V_80 -> V_108 -> V_109 = V_106 ;
V_80 -> V_108 -> V_110 |= V_111 ;
}
if ( V_107 ) {
V_80 -> V_108 -> V_112 = V_107 ;
V_80 -> V_108 -> V_110 |= V_113 ;
}
}
static struct V_79 * F_68 ( struct V_91 * V_33 )
{
const char * V_114 ;
struct V_79 * V_80 ;
struct V_115 V_116 ;
struct V_115 V_117 ;
struct V_29 * V_30 ;
int V_73 , V_118 , V_119 ;
int V_120 , V_121 , V_122 ;
int V_123 = 1 ;
F_25 () ;
V_30 = F_26 ( V_33 -> V_29 ) ;
if ( ! V_30 ) {
F_27 () ;
return NULL ;
}
V_120 = V_30 -> V_120 ;
V_121 = V_30 -> V_121 ;
V_122 = V_30 -> V_122 ;
F_27 () ;
V_119 = F_69 ( int , V_33 -> V_119 , sizeof( V_116 ) ) ;
memcpy ( & V_116 , & V_33 -> V_124 , V_119 ) ;
if ( ( (struct V_125 * ) & V_33 -> V_124 ) -> V_126 == V_127 )
V_116 . V_128 = 0 ;
else
( (struct V_129 * ) & V_116 ) -> V_130 = 0 ;
V_118 = F_69 ( int , V_33 -> V_118 , sizeof( V_116 ) ) ;
memcpy ( & V_117 , & V_33 -> V_131 , V_118 ) ;
V_114 = L_10 ;
V_73 = F_70 ( ( (struct V_125 * ) & V_116 ) -> V_126 ,
V_132 , V_133 , & V_80 ) ;
if ( V_73 < 0 ) {
V_80 = NULL ;
goto V_101;
}
V_80 -> V_108 -> V_134 =
V_80 -> V_108 -> V_135 = V_122 * V_39 ;
F_67 ( V_80 , V_120 , V_121 ) ;
V_114 = L_11 ;
V_73 = V_80 -> V_136 -> V_137 ( V_80 , (struct V_125 * ) & V_116 , V_119 ) ;
if ( V_73 < 0 )
goto V_101;
V_123 = 0 ;
V_114 = L_12 ;
V_73 = V_80 -> V_136 -> V_138 ( V_80 , (struct V_125 * ) & V_117 , V_118 , 0 ) ;
V_101:
if ( V_73 < 0 ) {
if ( V_80 ) {
F_71 ( V_80 ) ;
V_80 = NULL ;
}
switch ( - V_73 ) {
case V_139 : case V_140 : case V_141 :
case V_142 : case V_95 :
case V_143 : case V_144 :
case V_145 : case V_146 :
V_123 = 0 ;
break;
default:
F_41 ( V_33 , L_13 , V_114 , V_73 ) ;
}
if ( V_123 )
F_63 ( V_33 , F_64 ( V_102 , V_147 ) , V_104 ) ;
}
return V_80 ;
}
static void F_72 ( struct V_80 * V_108 )
{
struct V_148 * V_149 = V_108 -> V_150 ;
void (* F_73)( struct V_80 * V_108 );
F_73 = V_149 -> V_151 ;
if ( V_108 -> V_152 == V_153 )
F_74 ( & V_149 -> V_154 ) ;
F_73 ( V_108 ) ;
}
static int F_75 ( struct V_91 * V_33 , struct V_148 * V_149 )
{
int V_73 , V_120 , V_121 , V_119 ;
struct V_115 V_124 ;
struct V_79 * V_155 ;
struct V_29 * V_30 ;
const char * V_114 ;
F_25 () ;
V_30 = F_26 ( V_33 -> V_29 ) ;
if ( ! V_30 ) {
F_27 () ;
return - V_105 ;
}
V_120 = V_30 -> V_120 ;
V_121 = V_30 -> V_121 ;
F_27 () ;
V_119 = F_69 ( int , V_33 -> V_119 , sizeof( struct V_115 ) ) ;
memcpy ( & V_124 , & V_33 -> V_124 , V_119 ) ;
V_114 = L_10 ;
V_73 = F_70 ( ( (struct V_125 * ) & V_124 ) -> V_126 ,
V_132 , V_133 , & V_155 ) ;
if ( V_73 ) {
V_155 = NULL ;
goto V_101;
}
V_155 -> V_108 -> V_156 = V_157 ;
F_67 ( V_155 , V_120 , V_121 ) ;
V_114 = L_14 ;
V_73 = V_155 -> V_136 -> V_137 ( V_155 , (struct V_125 * ) & V_124 , V_119 ) ;
if ( V_73 < 0 )
goto V_101;
V_149 -> V_155 = V_155 ;
F_76 ( & V_155 -> V_108 -> V_158 ) ;
V_149 -> V_151 = V_155 -> V_108 -> V_159 ;
V_155 -> V_108 -> V_159 = F_72 ;
V_155 -> V_108 -> V_150 = V_149 ;
F_77 ( & V_155 -> V_108 -> V_158 ) ;
V_114 = L_15 ;
V_73 = V_155 -> V_136 -> V_160 ( V_155 , 5 ) ;
if ( V_73 < 0 )
goto V_101;
return 0 ;
V_101:
if ( V_155 )
F_71 ( V_155 ) ;
if ( V_73 < 0 ) {
if ( V_73 != - V_140 && V_73 != - V_142 && V_73 != - V_95 ) {
F_41 ( V_33 , L_13 , V_114 , V_73 ) ;
F_63 ( V_33 , F_64 ( V_102 , V_147 ) , V_104 ) ;
}
}
return - V_105 ;
}
static void F_78 ( struct V_80 * V_108 , struct V_148 * V_149 )
{
F_76 ( & V_108 -> V_158 ) ;
V_108 -> V_159 = V_149 -> V_151 ;
V_108 -> V_150 = NULL ;
F_77 ( & V_108 -> V_158 ) ;
}
static struct V_79 * F_79 ( struct V_91 * V_33 , struct V_148 * V_149 )
{
int V_161 , V_122 , V_73 = 0 ;
struct V_79 * V_162 = NULL ;
struct V_29 * V_30 ;
F_25 () ;
V_30 = F_26 ( V_33 -> V_29 ) ;
if ( ! V_30 ) {
F_27 () ;
return NULL ;
}
V_122 = V_30 -> V_122 ;
F_27 () ;
V_161 = V_122 * V_39 ;
V_161 += ( F_80 () & 1 ) ? V_161 / 7 : - V_161 / 7 ;
V_73 = F_81 ( & V_149 -> V_154 , V_161 ) ;
if ( V_73 <= 0 )
return NULL ;
V_73 = F_82 ( V_149 -> V_155 , & V_162 , 0 ) ;
if ( V_73 < 0 ) {
if ( V_73 != - V_140 && V_73 != - V_142 && V_73 != - V_95 ) {
F_41 ( V_33 , L_16 , V_73 ) ;
F_63 ( V_33 , F_64 ( V_102 , V_147 ) , V_104 ) ;
}
}
if ( V_162 )
F_78 ( V_162 -> V_108 , V_149 ) ;
return V_162 ;
}
static int F_83 ( struct V_91 * V_33 , struct V_163 * V_80 ,
enum V_164 V_165 )
{
if ( ! F_84 ( V_33 , V_80 ) )
return - V_105 ;
return F_85 ( V_33 , V_80 , V_165 , 0 , NULL , 0 ) ;
}
static int F_86 ( struct V_91 * V_33 , struct V_79 * V_80 )
{
unsigned int V_166 = F_87 ( V_33 ) ;
struct V_167 V_168 ;
int V_73 ;
V_73 = F_57 ( V_80 , V_33 -> V_93 . V_169 , V_166 , 0 ) ;
if ( V_73 != V_166 ) {
if ( V_73 >= 0 )
V_73 = - V_105 ;
return V_73 ;
}
V_73 = F_88 ( V_33 , V_33 -> V_93 . V_169 , & V_168 ) ;
if ( V_73 )
return V_73 ;
return V_168 . V_165 ;
}
static int F_89 ( struct V_79 * * V_80 )
{
int V_170 ;
char V_171 [ 4 ] ;
if ( ! * V_80 )
return false ;
V_170 = F_57 ( * V_80 , V_171 , 4 , V_172 | V_173 ) ;
if ( V_170 > 0 || V_170 == - V_140 ) {
return true ;
} else {
F_71 ( * V_80 ) ;
* V_80 = NULL ;
return false ;
}
}
int F_90 ( struct V_26 * V_27 )
{
struct V_9 * V_10 = V_27 -> V_10 ;
int V_73 ;
F_43 ( & V_10 -> V_174 , 0 ) ;
V_10 -> V_175 = 0 ;
V_10 -> V_176 = V_27 -> V_33 -> V_177 < 100 ?
& V_27 -> V_33 -> V_178 :
& V_10 -> V_179 ;
V_73 = F_91 ( V_27 ) ;
if ( ! V_73 )
V_73 = F_92 ( V_27 , 0 , 0 ) ;
if ( ! V_73 )
V_73 = F_93 ( V_27 ) ;
if ( ! V_73 )
V_73 = F_94 ( V_27 ) ;
F_95 ( V_180 , & V_10 -> V_66 ) ;
F_95 ( V_181 , & V_10 -> V_66 ) ;
F_43 ( & V_10 -> V_182 , 0 ) ;
F_96 ( & V_10 -> V_183 , V_184 + V_39 ) ;
return V_73 ;
}
static int F_97 ( struct V_91 * V_33 )
{
struct V_163 V_80 , V_185 ;
struct V_26 * V_27 ;
struct V_29 * V_30 ;
int V_186 , V_187 , V_188 , V_189 ;
bool V_190 ;
enum V_191 V_92 ;
struct V_148 V_149 = {
. V_33 = V_33 ,
. V_154 = F_98 ( V_149 . V_154 ) ,
} ;
F_95 ( V_96 , & V_33 -> V_66 ) ;
if ( F_63 ( V_33 , F_64 ( V_102 , V_192 ) , V_193 ) < V_194 )
return - 2 ;
F_99 ( & V_80 . V_195 ) ;
V_80 . V_196 = V_33 -> V_93 . V_196 ;
V_80 . V_169 = V_33 -> V_93 . V_169 ;
V_80 . V_79 = NULL ;
F_99 ( & V_185 . V_195 ) ;
V_185 . V_196 = V_33 -> V_197 . V_196 ;
V_185 . V_169 = V_33 -> V_197 . V_169 ;
V_185 . V_79 = NULL ;
V_33 -> V_177 = 80 ;
if ( F_75 ( V_33 , & V_149 ) )
return 0 ;
do {
struct V_79 * V_198 ;
V_198 = F_68 ( V_33 ) ;
if ( V_198 ) {
if ( ! V_80 . V_79 ) {
V_80 . V_79 = V_198 ;
F_83 ( V_33 , & V_80 , V_199 ) ;
} else if ( ! V_185 . V_79 ) {
F_95 ( V_200 , & V_33 -> V_66 ) ;
V_185 . V_79 = V_198 ;
F_83 ( V_33 , & V_185 , V_201 ) ;
} else {
F_41 ( V_33 , L_17 ) ;
goto V_202;
}
}
if ( V_80 . V_79 && V_185 . V_79 ) {
F_25 () ;
V_30 = F_26 ( V_33 -> V_29 ) ;
V_187 = V_30 -> V_97 * V_39 / 10 ;
F_27 () ;
F_100 ( V_187 ) ;
V_189 = F_89 ( & V_80 . V_79 ) ;
V_189 = F_89 ( & V_185 . V_79 ) && V_189 ;
if ( V_189 )
break;
}
V_28:
V_198 = F_79 ( V_33 , & V_149 ) ;
if ( V_198 ) {
int V_203 = F_86 ( V_33 , V_198 ) ;
F_89 ( & V_80 . V_79 ) ;
F_89 ( & V_185 . V_79 ) ;
switch ( V_203 ) {
case V_199 :
if ( V_80 . V_79 ) {
F_31 ( V_33 , L_18 ) ;
F_71 ( V_80 . V_79 ) ;
V_80 . V_79 = V_198 ;
goto V_204;
}
V_80 . V_79 = V_198 ;
break;
case V_201 :
F_101 ( V_200 , & V_33 -> V_66 ) ;
if ( V_185 . V_79 ) {
F_31 ( V_33 , L_19 ) ;
F_71 ( V_185 . V_79 ) ;
V_185 . V_79 = V_198 ;
goto V_204;
}
V_185 . V_79 = V_198 ;
break;
default:
F_31 ( V_33 , L_20 ) ;
F_71 ( V_198 ) ;
V_204:
if ( F_80 () & 1 )
goto V_28;
}
}
if ( V_33 -> V_99 <= V_147 )
goto V_202;
if ( F_30 ( V_38 ) ) {
F_102 ( V_38 ) ;
F_103 () ;
if ( F_104 ( & V_33 -> V_205 ) == V_206 )
goto V_202;
}
V_189 = F_89 ( & V_80 . V_79 ) ;
V_189 = F_89 ( & V_185 . V_79 ) && V_189 ;
} while ( ! V_189 );
if ( V_149 . V_155 )
F_71 ( V_149 . V_155 ) ;
V_80 . V_79 -> V_108 -> V_156 = V_157 ;
V_185 . V_79 -> V_108 -> V_156 = V_157 ;
V_80 . V_79 -> V_108 -> V_207 = V_208 ;
V_185 . V_79 -> V_108 -> V_207 = V_208 ;
V_80 . V_79 -> V_108 -> V_209 = V_210 ;
V_185 . V_79 -> V_108 -> V_209 = V_211 ;
F_25 () ;
V_30 = F_26 ( V_33 -> V_29 ) ;
V_80 . V_79 -> V_108 -> V_135 =
V_80 . V_79 -> V_108 -> V_134 = V_30 -> V_97 * 4 * V_39 / 10 ;
V_185 . V_79 -> V_108 -> V_134 = V_30 -> V_212 * V_39 ;
V_187 = V_30 -> V_187 * V_39 / 10 ;
V_190 = V_30 -> V_190 ;
F_27 () ;
V_185 . V_79 -> V_108 -> V_135 = V_187 ;
F_105 ( V_80 . V_79 ) ;
F_105 ( V_185 . V_79 ) ;
V_33 -> V_93 . V_79 = V_80 . V_79 ;
V_33 -> V_197 . V_79 = V_185 . V_79 ;
V_33 -> V_213 = V_184 ;
V_188 = F_106 ( V_33 ) ;
if ( V_188 <= 0 )
return V_188 ;
if ( V_33 -> V_214 ) {
switch ( F_107 ( V_33 ) ) {
case - 1 :
F_41 ( V_33 , L_21 ) ;
return - 1 ;
case 0 :
F_41 ( V_33 , L_22 ) ;
return 0 ;
}
}
V_33 -> V_93 . V_79 -> V_108 -> V_135 = V_187 ;
V_33 -> V_93 . V_79 -> V_108 -> V_134 = V_215 ;
if ( F_108 ( V_33 ) == - V_216 )
return - 1 ;
F_109 (&connection->peer_devices, peer_device, vnr)
F_110 ( V_27 -> V_10 -> V_176 ) ;
F_101 ( V_217 , & V_33 -> V_66 ) ;
F_109 (&connection->peer_devices, peer_device, vnr)
F_111 ( V_27 -> V_10 -> V_176 ) ;
F_25 () ;
F_109 (&connection->peer_devices, peer_device, vnr) {
struct V_9 * V_10 = V_27 -> V_10 ;
F_112 ( & V_10 -> V_218 ) ;
F_27 () ;
if ( V_190 )
F_101 ( V_219 , & V_10 -> V_66 ) ;
else
F_95 ( V_219 , & V_10 -> V_66 ) ;
F_90 ( V_27 ) ;
F_113 ( & V_10 -> V_218 , V_220 ) ;
F_25 () ;
}
F_27 () ;
V_92 = F_63 ( V_33 , F_64 ( V_102 , V_100 ) , V_193 ) ;
if ( V_92 < V_194 || V_33 -> V_99 != V_100 ) {
F_95 ( V_217 , & V_33 -> V_66 ) ;
return 0 ;
}
F_114 ( & V_33 -> V_221 ) ;
F_110 ( & V_33 -> V_24 -> V_222 ) ;
V_33 -> V_29 -> V_190 = 0 ;
F_111 ( & V_33 -> V_24 -> V_222 ) ;
return V_188 ;
V_202:
if ( V_149 . V_155 )
F_71 ( V_149 . V_155 ) ;
if ( V_80 . V_79 )
F_71 ( V_80 . V_79 ) ;
if ( V_185 . V_79 )
F_71 ( V_185 . V_79 ) ;
return - 1 ;
}
static int F_88 ( struct V_91 * V_33 , void * V_223 , struct V_167 * V_168 )
{
unsigned int V_166 = F_87 ( V_33 ) ;
if ( V_166 == sizeof( struct V_224 ) &&
* ( V_225 * ) V_223 == F_115 ( V_226 ) ) {
struct V_224 * V_188 = V_223 ;
if ( V_188 -> V_227 != 0 ) {
F_41 ( V_33 , L_23 ) ;
return - V_228 ;
}
V_168 -> V_186 = F_116 ( V_188 -> V_229 ) ;
V_168 -> V_165 = F_116 ( V_188 -> V_230 ) ;
V_168 -> V_61 = F_117 ( V_188 -> V_231 ) ;
} else if ( V_166 == sizeof( struct V_232 ) &&
* ( V_233 * ) V_223 == F_118 ( V_234 ) ) {
struct V_232 * V_188 = V_223 ;
V_168 -> V_165 = F_116 ( V_188 -> V_230 ) ;
V_168 -> V_61 = F_117 ( V_188 -> V_231 ) ;
V_168 -> V_186 = 0 ;
} else if ( V_166 == sizeof( struct V_235 ) &&
* ( V_225 * ) V_223 == F_115 ( V_236 ) ) {
struct V_235 * V_188 = V_223 ;
V_168 -> V_165 = F_116 ( V_188 -> V_230 ) ;
V_168 -> V_61 = F_116 ( V_188 -> V_231 ) ;
V_168 -> V_186 = 0 ;
} else {
F_41 ( V_33 , L_24 ,
F_117 ( * ( V_225 * ) V_223 ) ,
V_33 -> V_177 ) ;
return - V_228 ;
}
V_168 -> V_93 = V_223 + V_166 ;
return 0 ;
}
static int F_119 ( struct V_91 * V_33 , struct V_167 * V_168 )
{
void * V_237 = V_33 -> V_93 . V_169 ;
int V_73 ;
V_73 = F_66 ( V_33 , V_237 , F_87 ( V_33 ) ) ;
if ( V_73 )
return V_73 ;
V_73 = F_88 ( V_33 , V_237 , V_168 ) ;
V_33 -> V_213 = V_184 ;
return V_73 ;
}
static void F_120 ( struct V_91 * V_33 )
{
int V_92 ;
struct V_26 * V_27 ;
int V_186 ;
if ( V_33 -> V_238 >= V_239 ) {
F_25 () ;
F_109 (&connection->peer_devices, peer_device, vnr) {
struct V_9 * V_10 = V_27 -> V_10 ;
if ( ! F_121 ( V_10 ) )
continue;
F_112 ( & V_10 -> V_218 ) ;
F_27 () ;
V_92 = F_122 ( V_10 -> V_240 -> V_241 ,
V_208 , NULL ) ;
if ( V_92 ) {
F_60 ( V_10 , L_25 , V_92 ) ;
F_123 ( V_33 , V_242 ) ;
}
F_124 ( V_10 ) ;
F_113 ( & V_10 -> V_218 , V_220 ) ;
F_25 () ;
if ( V_92 )
break;
}
F_27 () ;
}
}
static enum V_243 F_125 ( struct V_91 * V_33 ,
struct V_244 * V_63 ,
enum V_245 V_246 )
{
int V_247 ;
struct V_244 * V_248 ;
enum V_243 V_92 = V_249 ;
F_11 ( & V_33 -> V_250 ) ;
do {
V_248 = NULL ;
V_247 = F_28 ( & V_63 -> V_247 ) ;
switch ( V_246 & ~ V_251 ) {
case V_252 :
F_126 ( & V_63 -> V_253 ) ;
break;
case V_254 :
F_101 ( V_255 , & V_63 -> V_66 ) ;
break;
case V_256 :
break;
}
if ( V_247 != 0 &&
F_28 ( & V_63 -> V_253 ) == 0 &&
( F_61 ( V_255 , & V_63 -> V_66 ) || V_246 & V_251 ) ) {
if ( ! ( V_246 & V_251 ) ) {
F_12 ( & V_33 -> V_250 ) ;
F_127 ( V_63 -> V_33 , V_63 -> V_257 , V_247 ) ;
F_11 ( & V_33 -> V_250 ) ;
}
#if 0
if (test_bit(DE_HAVE_BARRIER_NUMBER, &epoch->flags))
dec_unacked(epoch->connection);
#endif
if ( V_33 -> V_258 != V_63 ) {
V_248 = F_128 ( V_63 -> V_21 . V_259 , struct V_244 , V_21 ) ;
F_129 ( & V_63 -> V_21 ) ;
V_246 = V_256 | ( V_246 & V_251 ) ;
V_33 -> V_260 -- ;
F_46 ( V_63 ) ;
if ( V_92 == V_249 )
V_92 = V_261 ;
} else {
V_63 -> V_66 = 0 ;
F_43 ( & V_63 -> V_247 , 0 ) ;
if ( V_92 == V_249 )
V_92 = V_262 ;
}
}
if ( ! V_248 )
break;
V_63 = V_248 ;
} while ( 1 );
F_12 ( & V_33 -> V_250 ) ;
return V_92 ;
}
void F_123 ( struct V_91 * V_33 , enum V_263 V_264 )
{
struct V_265 * V_266 ;
struct V_26 * V_27 ;
enum V_263 V_267 ;
int V_186 ;
static char * V_268 [] = {
[ V_269 ] = L_26 ,
[ V_242 ] = L_27 ,
[ V_239 ] = L_28 ,
} ;
V_267 = V_33 -> V_238 ;
V_264 = F_130 ( V_267 , V_264 ) ;
F_25 () ;
F_109 (&connection->peer_devices, peer_device, vnr) {
struct V_9 * V_10 = V_27 -> V_10 ;
if ( ! F_131 ( V_10 , V_270 ) )
continue;
V_266 = F_26 ( V_10 -> V_240 -> V_265 ) ;
if ( V_264 == V_239 && ! V_266 -> V_271 )
V_264 = V_242 ;
if ( V_264 == V_242 && ! V_266 -> V_272 )
V_264 = V_269 ;
F_124 ( V_10 ) ;
}
F_27 () ;
V_33 -> V_238 = V_264 ;
if ( V_267 != V_33 -> V_238 || V_264 == V_239 )
F_60 ( V_33 , L_29 , V_268 [ V_33 -> V_238 ] ) ;
}
int F_132 ( struct V_9 * V_10 ,
struct V_18 * V_19 ,
const unsigned V_273 , const int V_274 )
{
struct V_275 * V_276 = NULL ;
struct V_275 * V_275 ;
struct V_1 * V_1 = V_19 -> V_64 ;
T_3 V_48 = V_19 -> V_6 . V_48 ;
unsigned V_277 = V_19 -> V_6 . V_61 ;
unsigned V_278 = 0 ;
unsigned V_52 = ( V_277 + V_45 - 1 ) >> V_53 ;
int V_73 = - V_279 ;
if ( V_19 -> V_66 & V_280 ) {
F_133 ( F_134 ( V_10 ) -> V_33 ) ;
if ( F_135 ( V_10 -> V_240 -> V_241 ,
V_48 , V_277 >> 9 , V_208 ) )
V_19 -> V_66 |= V_281 ;
F_136 ( V_19 ) ;
return 0 ;
}
if ( V_19 -> V_66 & V_282 )
V_52 = 1 ;
V_283:
V_275 = F_137 ( V_208 , V_52 ) ;
if ( ! V_275 ) {
F_41 ( V_10 , L_30 , V_52 ) ;
goto V_60;
}
V_275 -> V_284 . V_285 = V_48 ;
V_275 -> V_286 = V_10 -> V_240 -> V_241 ;
V_275 -> V_287 = V_273 ;
V_275 -> V_288 = V_19 ;
V_275 -> V_289 = V_290 ;
V_275 -> V_291 = V_276 ;
V_276 = V_275 ;
++ V_278 ;
if ( V_273 & V_292 ) {
V_275 -> V_284 . V_293 = V_277 ;
goto V_294;
}
F_138 (page) {
unsigned V_5 = F_69 ( unsigned , V_277 , V_45 ) ;
if ( ! F_139 ( V_275 , V_1 , V_5 , 0 ) ) {
if ( V_275 -> V_295 == 0 ) {
F_41 ( V_10 ,
L_31
L_32 ,
V_5 , ( V_296 ) V_275 -> V_284 . V_285 ) ;
V_73 = - V_297 ;
goto V_60;
}
goto V_283;
}
V_277 -= V_5 ;
V_48 += V_5 >> 9 ;
-- V_52 ;
}
F_47 ( V_10 , V_277 == 0 ) ;
V_294:
F_47 ( V_10 , V_1 == NULL ) ;
F_43 ( & V_19 -> V_65 , V_278 ) ;
do {
V_275 = V_276 ;
V_276 = V_276 -> V_291 ;
V_275 -> V_291 = NULL ;
F_140 ( V_10 , V_274 , V_275 ) ;
} while ( V_276 );
return 0 ;
V_60:
while ( V_276 ) {
V_275 = V_276 ;
V_276 = V_276 -> V_291 ;
F_141 ( V_275 ) ;
}
return V_73 ;
}
static void F_142 ( struct V_9 * V_10 ,
struct V_18 * V_19 )
{
struct V_298 * V_6 = & V_19 -> V_6 ;
F_143 ( & V_10 -> V_299 , V_6 ) ;
F_42 ( V_6 ) ;
if ( V_6 -> V_62 )
F_37 ( & V_10 -> V_300 ) ;
}
static void F_133 ( struct V_91 * V_33 )
{
struct V_26 * V_27 ;
int V_186 ;
F_25 () ;
F_109 (&connection->peer_devices, peer_device, vnr) {
struct V_9 * V_10 = V_27 -> V_10 ;
F_112 ( & V_10 -> V_218 ) ;
F_27 () ;
F_56 ( V_10 , & V_10 -> V_301 ) ;
F_113 ( & V_10 -> V_218 , V_220 ) ;
F_25 () ;
}
F_27 () ;
}
static struct V_26 *
F_144 ( struct V_91 * V_33 , int V_302 )
{
return F_145 ( & V_33 -> V_303 , V_302 ) ;
}
static int F_146 ( struct V_91 * V_33 , struct V_167 * V_168 )
{
int V_92 ;
struct V_304 * V_305 = V_168 -> V_93 ;
struct V_244 * V_63 ;
V_33 -> V_258 -> V_257 = V_305 -> V_306 ;
V_33 -> V_258 -> V_33 = V_33 ;
V_92 = F_125 ( V_33 , V_33 -> V_258 , V_254 ) ;
switch ( V_33 -> V_238 ) {
case V_269 :
if ( V_92 == V_262 )
return 0 ;
V_63 = F_147 ( sizeof( struct V_244 ) , V_208 ) ;
if ( V_63 )
break;
else
F_31 ( V_33 , L_33 ) ;
case V_239 :
case V_242 :
F_133 ( V_33 ) ;
F_120 ( V_33 ) ;
if ( F_28 ( & V_33 -> V_258 -> V_247 ) ) {
V_63 = F_147 ( sizeof( struct V_244 ) , V_208 ) ;
if ( V_63 )
break;
}
return 0 ;
default:
F_41 ( V_33 , L_34 , V_33 -> V_238 ) ;
return - V_105 ;
}
V_63 -> V_66 = 0 ;
F_43 ( & V_63 -> V_247 , 0 ) ;
F_43 ( & V_63 -> V_253 , 0 ) ;
F_11 ( & V_33 -> V_250 ) ;
if ( F_28 ( & V_33 -> V_258 -> V_247 ) ) {
F_148 ( & V_63 -> V_21 , & V_33 -> V_258 -> V_21 ) ;
V_33 -> V_258 = V_63 ;
V_33 -> V_260 ++ ;
} else {
F_46 ( V_63 ) ;
}
F_12 ( & V_33 -> V_250 ) ;
return 0 ;
}
static struct V_18 *
F_149 ( struct V_26 * V_27 , T_2 V_47 , T_3 V_48 ,
struct V_167 * V_168 ) __must_hold( T_5 )
{
struct V_9 * V_10 = V_27 -> V_10 ;
const T_3 V_307 = F_150 ( V_10 -> V_308 ) ;
struct V_18 * V_19 ;
struct V_1 * V_1 ;
int V_309 , V_277 , V_73 ;
int V_49 = V_168 -> V_61 ;
void * V_310 = V_27 -> V_33 -> V_311 ;
void * V_312 = V_27 -> V_33 -> V_313 ;
unsigned long * V_93 ;
struct V_314 * V_315 = ( V_168 -> V_165 == V_316 ) ? V_168 -> V_93 : NULL ;
V_309 = 0 ;
if ( ! V_315 && V_27 -> V_33 -> V_317 ) {
V_309 = F_151 ( V_27 -> V_33 -> V_317 ) ;
V_73 = F_66 ( V_27 -> V_33 , V_310 , V_309 ) ;
if ( V_73 )
return NULL ;
V_49 -= V_309 ;
}
if ( V_315 ) {
F_47 ( V_27 , V_49 == 0 ) ;
V_49 = F_117 ( V_315 -> V_61 ) ;
}
if ( ! F_152 ( F_153 ( V_49 , 512 ) ) )
return NULL ;
if ( ! V_315 && ! F_152 ( V_49 <= V_44 ) )
return NULL ;
if ( V_48 + ( V_49 >> 9 ) > V_307 ) {
F_41 ( V_10 , L_35
L_36 ,
( unsigned long long ) V_307 ,
( unsigned long long ) V_48 , V_49 ) ;
return NULL ;
}
V_19 = F_38 ( V_27 , V_47 , V_48 , V_49 , V_315 == NULL , V_208 ) ;
if ( ! V_19 )
return NULL ;
if ( V_315 )
return V_19 ;
V_277 = V_49 ;
V_1 = V_19 -> V_64 ;
F_138 (page) {
unsigned V_5 = F_69 ( int , V_277 , V_45 ) ;
V_93 = F_154 ( V_1 ) ;
V_73 = F_66 ( V_27 -> V_33 , V_93 , V_5 ) ;
if ( F_39 ( V_10 , V_318 ) ) {
F_41 ( V_10 , L_37 ) ;
V_93 [ 0 ] = V_93 [ 0 ] ^ ( unsigned long ) - 1 ;
}
F_155 ( V_1 ) ;
if ( V_73 ) {
F_52 ( V_10 , V_19 ) ;
return NULL ;
}
V_277 -= V_5 ;
}
if ( V_309 ) {
F_156 ( V_27 -> V_33 -> V_317 , V_19 , V_312 ) ;
if ( memcmp ( V_310 , V_312 , V_309 ) ) {
F_41 ( V_10 , L_38 ,
( unsigned long long ) V_48 , V_49 ) ;
F_52 ( V_10 , V_19 ) ;
return NULL ;
}
}
V_10 -> V_319 += V_49 >> 9 ;
return V_19 ;
}
static int F_157 ( struct V_26 * V_27 , int V_49 )
{
struct V_1 * V_1 ;
int V_73 = 0 ;
void * V_93 ;
if ( ! V_49 )
return 0 ;
V_1 = F_23 ( V_27 , 1 , 1 ) ;
V_93 = F_154 ( V_1 ) ;
while ( V_49 ) {
unsigned int V_5 = F_69 ( int , V_49 , V_45 ) ;
V_73 = F_66 ( V_27 -> V_33 , V_93 , V_5 ) ;
if ( V_73 )
break;
V_49 -= V_5 ;
}
F_155 ( V_1 ) ;
F_35 ( V_27 -> V_10 , V_1 , 0 ) ;
return V_73 ;
}
static int F_158 ( struct V_26 * V_27 , struct V_320 * V_321 ,
T_3 V_48 , int V_49 )
{
struct V_322 V_323 ;
struct V_324 V_325 ;
struct V_275 * V_275 ;
int V_309 , V_73 , F_152 ;
void * V_310 = V_27 -> V_33 -> V_311 ;
void * V_312 = V_27 -> V_33 -> V_313 ;
V_309 = 0 ;
if ( V_27 -> V_33 -> V_317 ) {
V_309 = F_151 ( V_27 -> V_33 -> V_317 ) ;
V_73 = F_66 ( V_27 -> V_33 , V_310 , V_309 ) ;
if ( V_73 )
return V_73 ;
V_49 -= V_309 ;
}
V_27 -> V_10 -> V_319 += V_49 >> 9 ;
V_275 = V_321 -> V_326 ;
F_47 ( V_27 -> V_10 , V_48 == V_275 -> V_284 . V_285 ) ;
F_159 (bvec, bio, iter) {
void * V_327 = F_154 ( V_323 . V_328 ) + V_323 . V_329 ;
F_152 = F_69 ( int , V_49 , V_323 . V_330 ) ;
V_73 = F_66 ( V_27 -> V_33 , V_327 , F_152 ) ;
F_155 ( V_323 . V_328 ) ;
if ( V_73 )
return V_73 ;
V_49 -= F_152 ;
}
if ( V_309 ) {
F_160 ( V_27 -> V_33 -> V_317 , V_275 , V_312 ) ;
if ( memcmp ( V_310 , V_312 , V_309 ) ) {
F_41 ( V_27 , L_39 ) ;
return - V_228 ;
}
}
F_47 ( V_27 -> V_10 , V_49 == 0 ) ;
return 0 ;
}
static int F_161 ( struct V_331 * V_20 , int V_332 )
{
struct V_18 * V_19 =
F_162 ( V_20 , struct V_18 , V_20 ) ;
struct V_26 * V_27 = V_19 -> V_27 ;
struct V_9 * V_10 = V_27 -> V_10 ;
T_3 V_48 = V_19 -> V_6 . V_48 ;
int V_73 ;
F_47 ( V_10 , F_48 ( & V_19 -> V_6 ) ) ;
if ( F_163 ( ( V_19 -> V_66 & V_281 ) == 0 ) ) {
F_164 ( V_10 , V_48 , V_19 -> V_6 . V_61 ) ;
V_73 = F_165 ( V_27 , V_333 , V_19 ) ;
} else {
F_166 ( V_10 , V_48 , V_19 -> V_6 . V_61 ) ;
V_73 = F_165 ( V_27 , V_334 , V_19 ) ;
}
F_167 ( V_10 ) ;
return V_73 ;
}
static int F_168 ( struct V_26 * V_27 , T_3 V_48 ,
struct V_167 * V_168 ) __releases( T_5 )
{
struct V_9 * V_10 = V_27 -> V_10 ;
struct V_18 * V_19 ;
V_19 = F_149 ( V_27 , V_335 , V_48 , V_168 ) ;
if ( ! V_19 )
goto V_60;
F_169 ( V_10 ) ;
F_170 ( V_10 ) ;
V_19 -> V_20 . V_76 = F_161 ;
F_20 ( & V_10 -> V_24 -> V_25 ) ;
F_148 ( & V_19 -> V_20 . V_21 , & V_10 -> V_336 ) ;
F_21 ( & V_10 -> V_24 -> V_25 ) ;
F_34 ( V_168 -> V_61 >> 9 , & V_10 -> V_337 ) ;
if ( F_132 ( V_10 , V_19 , V_338 , V_339 ) == 0 )
return 0 ;
F_41 ( V_10 , L_40 ) ;
F_20 ( & V_10 -> V_24 -> V_25 ) ;
F_129 ( & V_19 -> V_20 . V_21 ) ;
F_21 ( & V_10 -> V_24 -> V_25 ) ;
F_52 ( V_10 , V_19 ) ;
V_60:
F_124 ( V_10 ) ;
return - V_105 ;
}
static struct V_320 *
F_171 ( struct V_9 * V_10 , struct V_340 * V_341 , T_2 V_47 ,
T_3 V_48 , bool V_342 , const char * V_343 )
{
struct V_320 * V_321 ;
V_321 = (struct V_320 * ) ( unsigned long ) V_47 ;
if ( F_172 ( V_341 , V_48 , & V_321 -> V_6 ) && V_321 -> V_6 . T_5 )
return V_321 ;
if ( ! V_342 ) {
F_41 ( V_10 , L_41 , V_343 ,
( unsigned long ) V_47 , ( unsigned long long ) V_48 ) ;
}
return NULL ;
}
static int F_173 ( struct V_91 * V_33 , struct V_167 * V_168 )
{
struct V_26 * V_27 ;
struct V_9 * V_10 ;
struct V_320 * V_321 ;
T_3 V_48 ;
int V_73 ;
struct V_344 * V_305 = V_168 -> V_93 ;
V_27 = F_144 ( V_33 , V_168 -> V_186 ) ;
if ( ! V_27 )
return - V_105 ;
V_10 = V_27 -> V_10 ;
V_48 = F_174 ( V_305 -> V_48 ) ;
F_20 ( & V_10 -> V_24 -> V_25 ) ;
V_321 = F_171 ( V_10 , & V_10 -> V_345 , V_305 -> V_67 , V_48 , false , V_58 ) ;
F_21 ( & V_10 -> V_24 -> V_25 ) ;
if ( F_175 ( ! V_321 ) )
return - V_105 ;
V_73 = F_158 ( V_27 , V_321 , V_48 , V_168 -> V_61 ) ;
if ( ! V_73 )
F_176 ( V_321 , V_346 ) ;
return V_73 ;
}
static int F_177 ( struct V_91 * V_33 , struct V_167 * V_168 )
{
struct V_26 * V_27 ;
struct V_9 * V_10 ;
T_3 V_48 ;
int V_73 ;
struct V_344 * V_305 = V_168 -> V_93 ;
V_27 = F_144 ( V_33 , V_168 -> V_186 ) ;
if ( ! V_27 )
return - V_105 ;
V_10 = V_27 -> V_10 ;
V_48 = F_174 ( V_305 -> V_48 ) ;
F_47 ( V_10 , V_305 -> V_67 == V_335 ) ;
if ( F_121 ( V_10 ) ) {
V_73 = F_168 ( V_27 , V_48 , V_168 ) ;
} else {
if ( F_178 ( & V_347 ) )
F_41 ( V_10 , L_42 ) ;
V_73 = F_157 ( V_27 , V_168 -> V_61 ) ;
F_179 ( V_27 , V_334 , V_305 , V_168 -> V_61 ) ;
}
F_34 ( V_168 -> V_61 >> 9 , & V_10 -> V_348 ) ;
return V_73 ;
}
static void F_180 ( struct V_9 * V_10 ,
T_3 V_48 , int V_61 )
{
struct V_298 * V_6 ;
struct V_320 * V_321 ;
F_181 (i, &device->write_requests, sector, size) {
if ( ! V_6 -> T_5 )
continue;
V_321 = F_162 ( V_6 , struct V_320 , V_6 ) ;
if ( V_321 -> V_349 & V_350 ||
! ( V_321 -> V_349 & V_351 ) )
continue;
F_182 ( V_321 , V_352 , NULL ) ;
}
}
static int F_183 ( struct V_331 * V_20 , int V_353 )
{
struct V_18 * V_19 =
F_162 ( V_20 , struct V_18 , V_20 ) ;
struct V_26 * V_27 = V_19 -> V_27 ;
struct V_9 * V_10 = V_27 -> V_10 ;
T_3 V_48 = V_19 -> V_6 . V_48 ;
int V_73 = 0 , V_354 ;
if ( V_19 -> V_66 & V_355 ) {
if ( F_163 ( ( V_19 -> V_66 & V_281 ) == 0 ) ) {
V_354 = ( V_10 -> V_356 . V_102 >= V_357 &&
V_10 -> V_356 . V_102 <= V_358 &&
V_19 -> V_66 & V_359 ) ?
V_333 : V_360 ;
V_73 = F_165 ( V_27 , V_354 , V_19 ) ;
if ( V_354 == V_333 )
F_164 ( V_10 , V_48 , V_19 -> V_6 . V_61 ) ;
} else {
V_73 = F_165 ( V_27 , V_334 , V_19 ) ;
}
F_167 ( V_10 ) ;
}
if ( V_19 -> V_66 & V_361 ) {
F_20 ( & V_10 -> V_24 -> V_25 ) ;
F_47 ( V_10 , ! F_48 ( & V_19 -> V_6 ) ) ;
F_142 ( V_10 , V_19 ) ;
if ( V_19 -> V_66 & V_362 )
F_180 ( V_10 , V_48 , V_19 -> V_6 . V_61 ) ;
F_21 ( & V_10 -> V_24 -> V_25 ) ;
} else
F_47 ( V_10 , F_48 ( & V_19 -> V_6 ) ) ;
F_125 ( F_134 ( V_10 ) -> V_33 , V_19 -> V_63 , V_252 + ( V_353 ? V_251 : 0 ) ) ;
return V_73 ;
}
static int F_184 ( struct V_331 * V_20 , enum V_164 V_363 )
{
struct V_18 * V_19 =
F_162 ( V_20 , struct V_18 , V_20 ) ;
struct V_26 * V_27 = V_19 -> V_27 ;
int V_73 ;
V_73 = F_165 ( V_27 , V_363 , V_19 ) ;
F_167 ( V_27 -> V_10 ) ;
return V_73 ;
}
static int F_185 ( struct V_331 * V_20 , int V_332 )
{
return F_184 ( V_20 , V_364 ) ;
}
static int F_186 ( struct V_331 * V_20 , int V_332 )
{
struct V_18 * V_19 =
F_162 ( V_20 , struct V_18 , V_20 ) ;
struct V_91 * V_33 = V_19 -> V_27 -> V_33 ;
return F_184 ( V_20 , V_33 -> V_177 >= 100 ?
V_365 : V_364 ) ;
}
static bool F_187 ( T_7 V_42 , T_7 V_366 )
{
return ( V_367 ) V_42 - ( V_367 ) V_366 > 0 ;
}
static T_7 F_188 ( T_7 V_42 , T_7 V_366 )
{
return F_187 ( V_42 , V_366 ) ? V_42 : V_366 ;
}
static void F_189 ( struct V_26 * V_27 , unsigned int V_175 )
{
struct V_9 * V_10 = V_27 -> V_10 ;
unsigned int V_368 ;
if ( F_61 ( V_200 , & V_27 -> V_33 -> V_66 ) ) {
F_11 ( & V_10 -> V_369 ) ;
V_368 = F_188 ( V_10 -> V_175 , V_175 ) ;
V_10 -> V_175 = V_368 ;
F_12 ( & V_10 -> V_369 ) ;
if ( V_175 == V_368 )
F_37 ( & V_10 -> V_370 ) ;
}
}
static inline int F_190 ( T_3 V_371 , int V_372 , T_3 V_373 , int V_374 )
{
return ! ( ( V_371 + ( V_372 >> 9 ) <= V_373 ) || ( V_371 >= V_373 + ( V_374 >> 9 ) ) ) ;
}
static bool F_191 ( struct V_9 * V_10 , struct V_18 * V_19 )
{
struct V_18 * V_375 ;
bool V_92 = 0 ;
F_20 ( & V_10 -> V_24 -> V_25 ) ;
F_192 (rs_req, &device->sync_ee, w.list) {
if ( F_190 ( V_19 -> V_6 . V_48 , V_19 -> V_6 . V_61 ,
V_375 -> V_6 . V_48 , V_375 -> V_6 . V_61 ) ) {
V_92 = 1 ;
break;
}
}
F_21 ( & V_10 -> V_24 -> V_25 ) ;
return V_92 ;
}
static int F_193 ( struct V_26 * V_27 , const T_7 V_175 )
{
struct V_9 * V_10 = V_27 -> V_10 ;
F_24 ( V_31 ) ;
long V_187 ;
int V_376 = 0 , V_377 ;
if ( ! F_61 ( V_200 , & V_27 -> V_33 -> V_66 ) )
return 0 ;
F_11 ( & V_10 -> V_369 ) ;
for (; ; ) {
if ( ! F_187 ( V_175 - 1 , V_10 -> V_175 ) ) {
V_10 -> V_175 = F_188 ( V_10 -> V_175 , V_175 ) ;
break;
}
if ( F_30 ( V_38 ) ) {
V_376 = - V_95 ;
break;
}
F_25 () ;
V_377 = F_26 ( F_134 ( V_10 ) -> V_33 -> V_29 ) -> V_378 ;
F_27 () ;
if ( ! V_377 )
break;
F_29 ( & V_10 -> V_370 , & V_31 , V_37 ) ;
F_12 ( & V_10 -> V_369 ) ;
F_25 () ;
V_187 = F_26 ( V_27 -> V_33 -> V_29 ) -> V_97 * V_39 / 10 ;
F_27 () ;
V_187 = F_32 ( V_187 ) ;
F_11 ( & V_10 -> V_369 ) ;
if ( ! V_187 ) {
V_376 = - V_139 ;
F_41 ( V_10 , L_43 ) ;
break;
}
}
F_12 ( & V_10 -> V_369 ) ;
F_33 ( & V_10 -> V_370 , & V_31 ) ;
return V_376 ;
}
static unsigned long F_194 ( T_7 V_379 )
{
return ( V_379 & V_380 ? V_381 : 0 ) |
( V_379 & V_382 ? V_383 : 0 ) |
( V_379 & V_384 ? V_385 : 0 ) |
( V_379 & V_386 ? V_292 : 0 ) ;
}
static void F_195 ( struct V_9 * V_10 , T_3 V_48 ,
unsigned int V_61 )
{
struct V_298 * V_6 ;
V_387:
F_181 (i, &device->write_requests, sector, size) {
struct V_320 * V_321 ;
struct V_388 V_389 ;
if ( ! V_6 -> T_5 )
continue;
V_321 = F_162 ( V_6 , struct V_320 , V_6 ) ;
if ( ! ( V_321 -> V_349 & V_351 ) )
continue;
V_321 -> V_349 &= ~ V_351 ;
F_182 ( V_321 , V_390 , & V_389 ) ;
F_21 ( & V_10 -> V_24 -> V_25 ) ;
if ( V_389 . V_275 )
F_196 ( V_10 , & V_389 ) ;
F_20 ( & V_10 -> V_24 -> V_25 ) ;
goto V_387;
}
}
static int F_197 ( struct V_9 * V_10 ,
struct V_18 * V_19 )
{
struct V_91 * V_33 = V_19 -> V_27 -> V_33 ;
bool V_391 = F_61 ( V_200 , & V_33 -> V_66 ) ;
T_3 V_48 = V_19 -> V_6 . V_48 ;
const unsigned int V_61 = V_19 -> V_6 . V_61 ;
struct V_298 * V_6 ;
bool V_392 ;
int V_73 ;
F_198 ( & V_10 -> V_299 , & V_19 -> V_6 ) ;
V_387:
F_181 (i, &device->write_requests, sector, size) {
if ( V_6 == & V_19 -> V_6 )
continue;
if ( ! V_6 -> T_5 ) {
V_73 = F_199 ( V_10 , V_6 ) ;
if ( V_73 )
goto V_101;
goto V_387;
}
V_392 = V_6 -> V_48 == V_48 && V_6 -> V_61 == V_61 ;
if ( V_391 ) {
bool V_393 = V_6 -> V_48 <= V_48 && V_6 -> V_48 +
( V_6 -> V_61 >> 9 ) >= V_48 + ( V_61 >> 9 ) ;
if ( ! V_392 )
F_200 ( V_10 , L_44
L_45
L_46 ,
( unsigned long long ) V_6 -> V_48 , V_6 -> V_61 ,
( unsigned long long ) V_48 , V_61 ,
V_393 ? L_47 : L_48 ) ;
F_170 ( V_10 ) ;
V_19 -> V_20 . V_76 = V_393 ? F_185 :
F_186 ;
F_201 ( & V_19 -> V_20 . V_21 , & V_10 -> V_74 ) ;
F_202 ( V_33 ) ;
V_73 = - V_394 ;
goto V_101;
} else {
struct V_320 * V_321 =
F_162 ( V_6 , struct V_320 , V_6 ) ;
if ( ! V_392 )
F_200 ( V_10 , L_44
L_49 ,
( unsigned long long ) V_6 -> V_48 , V_6 -> V_61 ,
( unsigned long long ) V_48 , V_61 ) ;
if ( V_321 -> V_349 & V_350 ||
! ( V_321 -> V_349 & V_351 ) ) {
V_73 = F_199 ( V_10 , & V_321 -> V_6 ) ;
if ( V_73 ) {
F_203 ( V_33 , F_64 ( V_102 , V_395 ) , V_104 ) ;
F_195 ( V_10 , V_48 , V_61 ) ;
goto V_101;
}
goto V_387;
}
V_19 -> V_66 |= V_362 ;
}
}
V_73 = 0 ;
V_101:
if ( V_73 )
F_142 ( V_10 , V_19 ) ;
return V_73 ;
}
static int F_204 ( struct V_91 * V_33 , struct V_167 * V_168 )
{
struct V_26 * V_27 ;
struct V_9 * V_10 ;
T_3 V_48 ;
struct V_18 * V_19 ;
struct V_344 * V_305 = V_168 -> V_93 ;
T_7 V_175 = F_117 ( V_305 -> V_396 ) ;
int V_273 = V_338 ;
T_7 V_397 ;
int V_73 , V_377 ;
V_27 = F_144 ( V_33 , V_168 -> V_186 ) ;
if ( ! V_27 )
return - V_105 ;
V_10 = V_27 -> V_10 ;
if ( ! F_121 ( V_10 ) ) {
int V_75 ;
V_73 = F_193 ( V_27 , V_175 ) ;
F_179 ( V_27 , V_334 , V_305 , V_168 -> V_61 ) ;
F_205 ( & V_33 -> V_258 -> V_247 ) ;
V_75 = F_157 ( V_27 , V_168 -> V_61 ) ;
if ( ! V_73 )
V_73 = V_75 ;
return V_73 ;
}
V_48 = F_174 ( V_305 -> V_48 ) ;
V_19 = F_149 ( V_27 , V_305 -> V_67 , V_48 , V_168 ) ;
if ( ! V_19 ) {
F_124 ( V_10 ) ;
return - V_105 ;
}
V_19 -> V_20 . V_76 = F_183 ;
V_397 = F_117 ( V_305 -> V_397 ) ;
V_273 |= F_194 ( V_397 ) ;
if ( V_168 -> V_165 == V_316 ) {
struct V_398 * V_399 = F_206 ( V_10 -> V_240 -> V_241 ) ;
V_19 -> V_66 |= V_282 ;
if ( ! F_207 ( V_399 ) )
V_19 -> V_66 |= V_280 ;
F_47 ( V_27 , V_19 -> V_6 . V_61 > 0 ) ;
F_47 ( V_27 , V_273 & V_292 ) ;
F_47 ( V_27 , V_19 -> V_64 == NULL ) ;
} else if ( V_19 -> V_64 == NULL ) {
F_47 ( V_10 , V_19 -> V_6 . V_61 == 0 ) ;
F_47 ( V_10 , V_397 & V_384 ) ;
}
if ( V_397 & V_400 )
V_19 -> V_66 |= V_359 ;
F_11 ( & V_33 -> V_250 ) ;
V_19 -> V_63 = V_33 -> V_258 ;
F_205 ( & V_19 -> V_63 -> V_247 ) ;
F_205 ( & V_19 -> V_63 -> V_253 ) ;
F_12 ( & V_33 -> V_250 ) ;
F_25 () ;
V_377 = F_26 ( V_27 -> V_33 -> V_29 ) -> V_378 ;
F_27 () ;
if ( V_377 ) {
V_19 -> V_66 |= V_361 ;
V_73 = F_193 ( V_27 , V_175 ) ;
if ( V_73 )
goto V_401;
F_20 ( & V_10 -> V_24 -> V_25 ) ;
V_73 = F_197 ( V_10 , V_19 ) ;
if ( V_73 ) {
F_21 ( & V_10 -> V_24 -> V_25 ) ;
if ( V_73 == - V_394 ) {
F_124 ( V_10 ) ;
return 0 ;
}
goto V_401;
}
} else {
F_189 ( V_27 , V_175 ) ;
F_20 ( & V_10 -> V_24 -> V_25 ) ;
}
if ( ( V_19 -> V_66 & V_280 ) == 0 )
F_148 ( & V_19 -> V_20 . V_21 , & V_10 -> V_301 ) ;
F_21 ( & V_10 -> V_24 -> V_25 ) ;
if ( V_10 -> V_356 . V_102 == V_402 )
F_208 ( V_10 -> V_77 , ! F_191 ( V_10 , V_19 ) ) ;
if ( V_27 -> V_33 -> V_177 < 100 ) {
F_25 () ;
switch ( F_26 ( V_27 -> V_33 -> V_29 ) -> V_403 ) {
case V_404 :
V_397 |= V_405 ;
break;
case V_406 :
V_397 |= V_407 ;
break;
}
F_27 () ;
}
if ( V_397 & V_405 ) {
V_19 -> V_66 |= V_355 ;
F_170 ( V_10 ) ;
}
if ( V_397 & V_407 ) {
F_165 ( F_134 ( V_10 ) , V_408 , V_19 ) ;
}
if ( V_10 -> V_356 . V_409 < V_410 ) {
F_209 ( V_10 , V_19 -> V_6 . V_48 , V_19 -> V_6 . V_61 ) ;
V_19 -> V_66 |= V_411 ;
V_19 -> V_66 &= ~ V_359 ;
F_210 ( V_10 , & V_19 -> V_6 , true ) ;
}
V_73 = F_132 ( V_10 , V_19 , V_273 , V_412 ) ;
if ( ! V_73 )
return 0 ;
F_41 ( V_10 , L_40 ) ;
F_20 ( & V_10 -> V_24 -> V_25 ) ;
F_129 ( & V_19 -> V_20 . V_21 ) ;
F_142 ( V_10 , V_19 ) ;
F_21 ( & V_10 -> V_24 -> V_25 ) ;
if ( V_19 -> V_66 & V_411 )
F_211 ( V_10 , & V_19 -> V_6 ) ;
V_401:
F_125 ( V_33 , V_19 -> V_63 , V_252 + V_251 ) ;
F_124 ( V_10 ) ;
F_52 ( V_10 , V_19 ) ;
return V_73 ;
}
bool F_212 ( struct V_9 * V_10 , T_3 V_48 )
{
struct V_413 * V_4 ;
bool V_414 = true ;
if ( ! F_213 ( V_10 ) )
return false ;
F_20 ( & V_10 -> V_415 ) ;
V_4 = F_214 ( V_10 -> V_416 , F_215 ( V_48 ) ) ;
if ( V_4 ) {
struct V_417 * V_418 = F_216 ( V_4 , struct V_417 , V_419 ) ;
if ( F_61 ( V_420 , & V_418 -> V_66 ) )
V_414 = false ;
}
F_21 ( & V_10 -> V_415 ) ;
return V_414 ;
}
bool F_213 ( struct V_9 * V_10 )
{
struct V_421 * V_422 = V_10 -> V_240 -> V_241 -> V_423 -> V_424 ;
unsigned long V_425 , V_426 , V_427 ;
unsigned int V_428 ;
int V_429 ;
F_25 () ;
V_428 = F_26 ( V_10 -> V_240 -> V_265 ) -> V_428 ;
F_27 () ;
if ( V_428 == 0 )
return false ;
V_429 = ( int ) F_217 ( & V_422 -> V_430 , V_431 [ 0 ] ) +
( int ) F_217 ( & V_422 -> V_430 , V_431 [ 1 ] ) -
F_28 ( & V_10 -> V_337 ) ;
if ( ! V_10 -> V_432 || V_429 - V_10 -> V_432 > 64 ) {
unsigned long V_433 ;
int V_6 ;
V_10 -> V_432 = V_429 ;
V_6 = ( V_10 -> V_434 + V_435 - 1 ) % V_435 ;
if ( V_10 -> V_356 . V_102 == V_436 || V_10 -> V_356 . V_102 == V_437 )
V_433 = V_10 -> V_438 ;
else
V_433 = F_218 ( V_10 ) - V_10 -> V_439 ;
V_426 = ( ( long ) V_184 - ( long ) V_10 -> V_440 [ V_6 ] ) / V_39 ;
if ( ! V_426 )
V_426 ++ ;
V_425 = V_10 -> V_441 [ V_6 ] - V_433 ;
V_427 = F_219 ( V_425 / V_426 ) ;
if ( V_427 > V_428 )
return true ;
}
return false ;
}
static int F_220 ( struct V_91 * V_33 , struct V_167 * V_168 )
{
struct V_26 * V_27 ;
struct V_9 * V_10 ;
T_3 V_48 ;
T_3 V_307 ;
struct V_18 * V_19 ;
struct V_442 * V_443 = NULL ;
int V_61 , V_444 ;
unsigned int V_274 ;
struct V_445 * V_305 = V_168 -> V_93 ;
V_27 = F_144 ( V_33 , V_168 -> V_186 ) ;
if ( ! V_27 )
return - V_105 ;
V_10 = V_27 -> V_10 ;
V_307 = F_150 ( V_10 -> V_308 ) ;
V_48 = F_174 ( V_305 -> V_48 ) ;
V_61 = F_117 ( V_305 -> V_446 ) ;
if ( V_61 <= 0 || ! F_153 ( V_61 , 512 ) || V_61 > V_44 ) {
F_41 ( V_10 , L_50 , __FILE__ , __LINE__ ,
( unsigned long long ) V_48 , V_61 ) ;
return - V_228 ;
}
if ( V_48 + ( V_61 >> 9 ) > V_307 ) {
F_41 ( V_10 , L_50 , __FILE__ , __LINE__ ,
( unsigned long long ) V_48 , V_61 ) ;
return - V_228 ;
}
if ( ! F_131 ( V_10 , V_447 ) ) {
V_444 = 1 ;
switch ( V_168 -> V_165 ) {
case V_448 :
F_221 ( V_27 , V_449 , V_305 ) ;
break;
case V_450 :
case V_451 :
case V_452 :
F_221 ( V_27 , V_453 , V_305 ) ;
break;
case V_454 :
V_444 = 0 ;
F_169 ( V_10 ) ;
F_222 ( V_27 , V_455 , V_48 , V_61 , V_456 ) ;
break;
default:
F_223 () ;
}
if ( V_444 && F_178 ( & V_347 ) )
F_41 ( V_10 , L_51
L_52 ) ;
return F_157 ( V_27 , V_168 -> V_61 ) ;
}
V_19 = F_38 ( V_27 , V_305 -> V_67 , V_48 , V_61 ,
true , V_208 ) ;
if ( ! V_19 ) {
F_124 ( V_10 ) ;
return - V_279 ;
}
switch ( V_168 -> V_165 ) {
case V_448 :
V_19 -> V_20 . V_76 = V_457 ;
V_274 = V_458 ;
goto V_294;
case V_450 :
V_19 -> V_20 . V_76 = V_459 ;
V_274 = V_460 ;
V_10 -> V_461 = F_224 ( V_48 ) ;
break;
case V_454 :
case V_451 :
V_274 = V_460 ;
V_443 = F_147 ( sizeof( * V_443 ) + V_168 -> V_61 , V_208 ) ;
if ( ! V_443 )
goto V_462;
V_443 -> V_463 = V_168 -> V_61 ;
V_443 -> V_69 = ( ( ( char * ) V_443 ) + sizeof( struct V_442 ) ) ;
V_19 -> V_69 = V_443 ;
V_19 -> V_66 |= V_68 ;
if ( F_65 ( V_27 -> V_33 , V_443 -> V_69 , V_168 -> V_61 ) )
goto V_462;
if ( V_168 -> V_165 == V_451 ) {
F_47 ( V_10 , V_27 -> V_33 -> V_177 >= 89 ) ;
V_19 -> V_20 . V_76 = V_464 ;
V_10 -> V_461 = F_224 ( V_48 ) ;
} else if ( V_168 -> V_165 == V_454 ) {
F_34 ( V_61 >> 9 , & V_10 -> V_348 ) ;
V_19 -> V_20 . V_76 = V_465 ;
F_169 ( V_10 ) ;
goto V_466;
}
break;
case V_452 :
if ( V_10 -> V_467 == ~ ( T_3 ) 0 &&
V_27 -> V_33 -> V_177 >= 90 ) {
unsigned long V_468 = V_184 ;
int V_6 ;
V_10 -> V_467 = V_48 ;
V_10 -> V_469 = V_48 ;
V_10 -> V_438 = F_225 ( V_10 ) - F_224 ( V_48 ) ;
V_10 -> V_470 = V_10 -> V_438 ;
for ( V_6 = 0 ; V_6 < V_435 ; V_6 ++ ) {
V_10 -> V_441 [ V_6 ] = V_10 -> V_438 ;
V_10 -> V_440 [ V_6 ] = V_468 ;
}
F_60 ( V_10 , L_53 ,
( unsigned long long ) V_48 ) ;
}
V_19 -> V_20 . V_76 = V_471 ;
V_274 = V_460 ;
break;
default:
F_223 () ;
}
if ( V_10 -> V_356 . V_472 != V_473 && F_212 ( V_10 , V_48 ) )
F_226 ( V_39 / 10 ) ;
if ( F_227 ( V_10 , V_48 ) )
goto V_462;
V_466:
F_34 ( V_61 >> 9 , & V_10 -> V_337 ) ;
V_294:
F_170 ( V_10 ) ;
F_20 ( & V_10 -> V_24 -> V_25 ) ;
F_201 ( & V_19 -> V_20 . V_21 , & V_10 -> V_474 ) ;
F_21 ( & V_10 -> V_24 -> V_25 ) ;
if ( F_132 ( V_10 , V_19 , V_475 , V_274 ) == 0 )
return 0 ;
F_41 ( V_10 , L_40 ) ;
F_20 ( & V_10 -> V_24 -> V_25 ) ;
F_129 ( & V_19 -> V_20 . V_21 ) ;
F_21 ( & V_10 -> V_24 -> V_25 ) ;
V_462:
F_124 ( V_10 ) ;
F_52 ( V_10 , V_19 ) ;
return - V_105 ;
}
static int F_228 ( struct V_26 * V_27 ) __must_hold( T_5 )
{
struct V_9 * V_10 = V_27 -> V_10 ;
int V_476 , V_472 , V_92 = - 100 ;
unsigned long V_477 , V_478 ;
enum V_479 V_480 ;
V_476 = V_10 -> V_240 -> V_481 . V_482 [ V_483 ] & 1 ;
V_472 = V_10 -> V_484 [ V_483 ] & 1 ;
V_478 = V_10 -> V_484 [ V_485 ] ;
V_477 = V_10 -> V_486 ;
F_25 () ;
V_480 = F_26 ( V_27 -> V_33 -> V_29 ) -> V_480 ;
F_27 () ;
switch ( V_480 ) {
case V_487 :
case V_488 :
case V_489 :
case V_490 :
F_41 ( V_10 , L_54 ) ;
break;
case V_491 :
break;
case V_492 :
if ( V_476 == 0 && V_472 == 1 ) {
V_92 = - 1 ;
break;
}
if ( V_476 == 1 && V_472 == 0 ) {
V_92 = 1 ;
break;
}
case V_493 :
if ( V_476 == 0 && V_472 == 1 ) {
V_92 = 1 ;
break;
}
if ( V_476 == 1 && V_472 == 0 ) {
V_92 = - 1 ;
break;
}
F_31 ( V_10 , L_55
L_56 ) ;
case V_494 :
if ( V_478 == 0 && V_477 == 0 ) {
V_92 = F_61 ( V_200 , & V_27 -> V_33 -> V_66 )
? - 1 : 1 ;
break;
} else {
if ( V_478 == 0 ) { V_92 = 1 ; break; }
if ( V_477 == 0 ) { V_92 = - 1 ; break; }
}
if ( V_480 == V_494 )
break;
case V_495 :
if ( V_477 < V_478 )
V_92 = - 1 ;
else if ( V_477 > V_478 )
V_92 = 1 ;
else
V_92 = F_61 ( V_200 , & V_27 -> V_33 -> V_66 )
? - 1 : 1 ;
break;
case V_496 :
V_92 = - 1 ;
break;
case V_497 :
V_92 = 1 ;
}
return V_92 ;
}
static int F_229 ( struct V_26 * V_27 ) __must_hold( T_5 )
{
struct V_9 * V_10 = V_27 -> V_10 ;
int V_498 , V_92 = - 100 ;
enum V_479 V_499 ;
F_25 () ;
V_499 = F_26 ( V_27 -> V_33 -> V_29 ) -> V_499 ;
F_27 () ;
switch ( V_499 ) {
case V_492 :
case V_493 :
case V_495 :
case V_496 :
case V_497 :
case V_494 :
F_41 ( V_10 , L_54 ) ;
break;
case V_491 :
break;
case V_487 :
V_498 = F_228 ( V_27 ) ;
if ( V_498 == - 1 && V_10 -> V_356 . V_500 == V_501 )
V_92 = V_498 ;
if ( V_498 == 1 && V_10 -> V_356 . V_500 == V_473 )
V_92 = V_498 ;
break;
case V_490 :
V_92 = F_228 ( V_27 ) ;
break;
case V_488 :
return V_10 -> V_356 . V_500 == V_473 ? 1 : - 1 ;
case V_489 :
V_498 = F_228 ( V_27 ) ;
if ( V_498 == - 1 && V_10 -> V_356 . V_500 == V_473 ) {
enum V_191 V_502 ;
V_502 = F_230 ( V_10 , V_193 , F_64 ( V_500 , V_501 ) ) ;
if ( V_502 != V_194 ) {
F_231 ( V_10 , L_57 ) ;
} else {
F_31 ( V_10 , L_58 ) ;
V_92 = V_498 ;
}
} else
V_92 = V_498 ;
}
return V_92 ;
}
static int F_232 ( struct V_26 * V_27 ) __must_hold( T_5 )
{
struct V_9 * V_10 = V_27 -> V_10 ;
int V_498 , V_92 = - 100 ;
enum V_479 V_503 ;
F_25 () ;
V_503 = F_26 ( V_27 -> V_33 -> V_29 ) -> V_503 ;
F_27 () ;
switch ( V_503 ) {
case V_492 :
case V_493 :
case V_495 :
case V_496 :
case V_497 :
case V_487 :
case V_488 :
case V_494 :
F_41 ( V_10 , L_54 ) ;
break;
case V_490 :
V_92 = F_228 ( V_27 ) ;
break;
case V_491 :
break;
case V_489 :
V_498 = F_228 ( V_27 ) ;
if ( V_498 == - 1 ) {
enum V_191 V_502 ;
V_502 = F_230 ( V_10 , V_193 , F_64 ( V_500 , V_501 ) ) ;
if ( V_502 != V_194 ) {
F_231 ( V_10 , L_57 ) ;
} else {
F_31 ( V_10 , L_58 ) ;
V_92 = V_498 ;
}
} else
V_92 = V_498 ;
}
return V_92 ;
}
static void F_233 ( struct V_9 * V_10 , char * V_504 , T_2 * V_482 ,
T_2 V_505 , T_2 V_66 )
{
if ( ! V_482 ) {
F_60 ( V_10 , L_59 , V_504 ) ;
return;
}
F_60 ( V_10 , L_60 ,
V_504 ,
( unsigned long long ) V_482 [ V_506 ] ,
( unsigned long long ) V_482 [ V_483 ] ,
( unsigned long long ) V_482 [ V_507 ] ,
( unsigned long long ) V_482 [ V_508 ] ,
( unsigned long long ) V_505 ,
( unsigned long long ) V_66 ) ;
}
static int F_234 ( struct V_9 * V_10 , int * V_509 ) __must_hold( T_5 )
{
T_2 V_476 , V_472 ;
int V_6 , V_510 ;
V_476 = V_10 -> V_240 -> V_481 . V_482 [ V_506 ] & ~ ( ( T_2 ) 1 ) ;
V_472 = V_10 -> V_484 [ V_506 ] & ~ ( ( T_2 ) 1 ) ;
* V_509 = 10 ;
if ( V_476 == V_511 && V_472 == V_511 )
return 0 ;
* V_509 = 20 ;
if ( ( V_476 == V_511 || V_476 == ( T_2 ) 0 ) &&
V_472 != V_511 )
return - 2 ;
* V_509 = 30 ;
if ( V_476 != V_511 &&
( V_472 == V_511 || V_472 == ( T_2 ) 0 ) )
return 2 ;
if ( V_476 == V_472 ) {
int V_512 , V_266 ;
if ( V_10 -> V_484 [ V_483 ] == ( T_2 ) 0 && V_10 -> V_240 -> V_481 . V_482 [ V_483 ] != ( T_2 ) 0 ) {
if ( F_134 ( V_10 ) -> V_33 -> V_177 < 91 )
return - 1091 ;
if ( ( V_10 -> V_240 -> V_481 . V_482 [ V_483 ] & ~ ( ( T_2 ) 1 ) ) == ( V_10 -> V_484 [ V_507 ] & ~ ( ( T_2 ) 1 ) ) &&
( V_10 -> V_240 -> V_481 . V_482 [ V_507 ] & ~ ( ( T_2 ) 1 ) ) == ( V_10 -> V_484 [ V_507 + 1 ] & ~ ( ( T_2 ) 1 ) ) ) {
F_60 ( V_10 , L_61 ) ;
F_235 ( V_10 ) ;
V_10 -> V_240 -> V_481 . V_482 [ V_507 ] = V_10 -> V_240 -> V_481 . V_482 [ V_483 ] ;
V_10 -> V_240 -> V_481 . V_482 [ V_483 ] = 0 ;
F_233 ( V_10 , L_62 , V_10 -> V_240 -> V_481 . V_482 ,
V_10 -> V_356 . V_422 >= V_513 ? F_218 ( V_10 ) : 0 , 0 ) ;
* V_509 = 34 ;
} else {
F_60 ( V_10 , L_63 ) ;
* V_509 = 36 ;
}
return 1 ;
}
if ( V_10 -> V_240 -> V_481 . V_482 [ V_483 ] == ( T_2 ) 0 && V_10 -> V_484 [ V_483 ] != ( T_2 ) 0 ) {
if ( F_134 ( V_10 ) -> V_33 -> V_177 < 91 )
return - 1091 ;
if ( ( V_10 -> V_240 -> V_481 . V_482 [ V_507 ] & ~ ( ( T_2 ) 1 ) ) == ( V_10 -> V_484 [ V_483 ] & ~ ( ( T_2 ) 1 ) ) &&
( V_10 -> V_240 -> V_481 . V_482 [ V_507 + 1 ] & ~ ( ( T_2 ) 1 ) ) == ( V_10 -> V_484 [ V_507 ] & ~ ( ( T_2 ) 1 ) ) ) {
F_60 ( V_10 , L_64 ) ;
V_10 -> V_484 [ V_507 + 1 ] = V_10 -> V_484 [ V_507 ] ;
V_10 -> V_484 [ V_507 ] = V_10 -> V_484 [ V_483 ] ;
V_10 -> V_484 [ V_483 ] = 0UL ;
F_233 ( V_10 , L_65 , V_10 -> V_484 , V_10 -> V_484 [ V_485 ] , V_10 -> V_484 [ V_514 ] ) ;
* V_509 = 35 ;
} else {
F_60 ( V_10 , L_66 ) ;
* V_509 = 37 ;
}
return - 1 ;
}
V_512 = ( F_61 ( V_515 , & V_10 -> V_66 ) ? 1 : 0 ) +
( V_10 -> V_484 [ V_514 ] & 2 ) ;
* V_509 = 40 ;
switch ( V_512 ) {
case 0 : return 0 ;
case 1 : return 1 ;
case 2 : return - 1 ;
case 3 :
V_266 = F_61 ( V_200 , & F_134 ( V_10 ) -> V_33 -> V_66 ) ;
return V_266 ? - 1 : 1 ;
}
}
* V_509 = 50 ;
V_472 = V_10 -> V_484 [ V_483 ] & ~ ( ( T_2 ) 1 ) ;
if ( V_476 == V_472 )
return - 1 ;
* V_509 = 51 ;
V_472 = V_10 -> V_484 [ V_507 ] & ~ ( ( T_2 ) 1 ) ;
if ( V_476 == V_472 ) {
if ( F_134 ( V_10 ) -> V_33 -> V_177 < 96 ?
( V_10 -> V_240 -> V_481 . V_482 [ V_507 ] & ~ ( ( T_2 ) 1 ) ) ==
( V_10 -> V_484 [ V_507 + 1 ] & ~ ( ( T_2 ) 1 ) ) :
V_472 + V_516 == ( V_10 -> V_484 [ V_483 ] & ~ ( ( T_2 ) 1 ) ) ) {
if ( F_134 ( V_10 ) -> V_33 -> V_177 < 91 )
return - 1091 ;
V_10 -> V_484 [ V_483 ] = V_10 -> V_484 [ V_507 ] ;
V_10 -> V_484 [ V_507 ] = V_10 -> V_484 [ V_507 + 1 ] ;
F_60 ( V_10 , L_67 ) ;
F_233 ( V_10 , L_65 , V_10 -> V_484 , V_10 -> V_484 [ V_485 ] , V_10 -> V_484 [ V_514 ] ) ;
return - 1 ;
}
}
* V_509 = 60 ;
V_476 = V_10 -> V_240 -> V_481 . V_482 [ V_506 ] & ~ ( ( T_2 ) 1 ) ;
for ( V_6 = V_507 ; V_6 <= V_508 ; V_6 ++ ) {
V_472 = V_10 -> V_484 [ V_6 ] & ~ ( ( T_2 ) 1 ) ;
if ( V_476 == V_472 )
return - 2 ;
}
* V_509 = 70 ;
V_476 = V_10 -> V_240 -> V_481 . V_482 [ V_483 ] & ~ ( ( T_2 ) 1 ) ;
V_472 = V_10 -> V_484 [ V_506 ] & ~ ( ( T_2 ) 1 ) ;
if ( V_476 == V_472 )
return 1 ;
* V_509 = 71 ;
V_476 = V_10 -> V_240 -> V_481 . V_482 [ V_507 ] & ~ ( ( T_2 ) 1 ) ;
if ( V_476 == V_472 ) {
if ( F_134 ( V_10 ) -> V_33 -> V_177 < 96 ?
( V_10 -> V_240 -> V_481 . V_482 [ V_507 + 1 ] & ~ ( ( T_2 ) 1 ) ) ==
( V_10 -> V_484 [ V_507 ] & ~ ( ( T_2 ) 1 ) ) :
V_476 + V_516 == ( V_10 -> V_240 -> V_481 . V_482 [ V_483 ] & ~ ( ( T_2 ) 1 ) ) ) {
if ( F_134 ( V_10 ) -> V_33 -> V_177 < 91 )
return - 1091 ;
F_236 ( V_10 , V_483 , V_10 -> V_240 -> V_481 . V_482 [ V_507 ] ) ;
F_236 ( V_10 , V_507 , V_10 -> V_240 -> V_481 . V_482 [ V_507 + 1 ] ) ;
F_60 ( V_10 , L_68 ) ;
F_233 ( V_10 , L_62 , V_10 -> V_240 -> V_481 . V_482 ,
V_10 -> V_356 . V_422 >= V_513 ? F_218 ( V_10 ) : 0 , 0 ) ;
return 1 ;
}
}
* V_509 = 80 ;
V_472 = V_10 -> V_484 [ V_506 ] & ~ ( ( T_2 ) 1 ) ;
for ( V_6 = V_507 ; V_6 <= V_508 ; V_6 ++ ) {
V_476 = V_10 -> V_240 -> V_481 . V_482 [ V_6 ] & ~ ( ( T_2 ) 1 ) ;
if ( V_476 == V_472 )
return 2 ;
}
* V_509 = 90 ;
V_476 = V_10 -> V_240 -> V_481 . V_482 [ V_483 ] & ~ ( ( T_2 ) 1 ) ;
V_472 = V_10 -> V_484 [ V_483 ] & ~ ( ( T_2 ) 1 ) ;
if ( V_476 == V_472 && V_476 != ( ( T_2 ) 0 ) )
return 100 ;
* V_509 = 100 ;
for ( V_6 = V_507 ; V_6 <= V_508 ; V_6 ++ ) {
V_476 = V_10 -> V_240 -> V_481 . V_482 [ V_6 ] & ~ ( ( T_2 ) 1 ) ;
for ( V_510 = V_507 ; V_510 <= V_508 ; V_510 ++ ) {
V_472 = V_10 -> V_484 [ V_510 ] & ~ ( ( T_2 ) 1 ) ;
if ( V_476 == V_472 )
return - 100 ;
}
}
return - 1000 ;
}
static enum V_517 F_237 ( struct V_26 * V_27 ,
enum V_518 V_519 ,
enum V_520 V_521 ) __must_hold( T_5 )
{
struct V_9 * V_10 = V_27 -> V_10 ;
enum V_517 V_92 = V_522 ;
enum V_520 V_523 ;
struct V_29 * V_30 ;
int V_498 , V_509 , V_524 , V_525 ;
V_523 = V_10 -> V_356 . V_422 ;
if ( V_523 == V_513 )
V_523 = V_10 -> V_526 . V_422 ;
F_60 ( V_10 , L_69 ) ;
F_20 ( & V_10 -> V_240 -> V_481 . V_527 ) ;
F_233 ( V_10 , L_62 , V_10 -> V_240 -> V_481 . V_482 , V_10 -> V_486 , 0 ) ;
F_233 ( V_10 , L_65 , V_10 -> V_484 ,
V_10 -> V_484 [ V_485 ] , V_10 -> V_484 [ V_514 ] ) ;
V_498 = F_234 ( V_10 , & V_509 ) ;
F_21 ( & V_10 -> V_240 -> V_481 . V_527 ) ;
F_60 ( V_10 , L_70 , V_498 , V_509 ) ;
if ( V_498 == - 1000 ) {
F_200 ( V_10 , L_71 ) ;
return V_522 ;
}
if ( V_498 < - 1000 ) {
F_200 ( V_10 , L_72 , - V_498 - 1000 ) ;
return V_522 ;
}
if ( ( V_523 == V_410 && V_521 > V_410 ) ||
( V_521 == V_410 && V_523 > V_410 ) ) {
int V_528 = ( V_498 == - 100 ) || abs ( V_498 ) == 2 ;
V_498 = V_523 > V_410 ? 1 : - 1 ;
if ( V_528 )
V_498 = V_498 * 2 ;
F_60 ( V_10 , L_73 ,
V_498 > 0 ? L_74 : L_75 ) ;
}
if ( abs ( V_498 ) == 100 )
F_231 ( V_10 , L_76 ) ;
F_25 () ;
V_30 = F_26 ( V_27 -> V_33 -> V_29 ) ;
if ( V_498 == 100 || ( V_498 == - 100 && V_30 -> V_529 ) ) {
int V_530 = ( V_10 -> V_356 . V_500 == V_473 )
+ ( V_519 == V_473 ) ;
int V_531 = ( V_498 == - 100 ) ;
switch ( V_530 ) {
case 0 :
V_498 = F_228 ( V_27 ) ;
break;
case 1 :
V_498 = F_229 ( V_27 ) ;
break;
case 2 :
V_498 = F_232 ( V_27 ) ;
break;
}
if ( abs ( V_498 ) < 100 ) {
F_31 ( V_10 , L_77
L_78 ,
V_530 , ( V_498 < 0 ) ? L_65 : L_79 ) ;
if ( V_531 ) {
F_31 ( V_10 , L_80
L_81 ) ;
V_498 = V_498 * 2 ;
}
}
}
if ( V_498 == - 100 ) {
if ( F_61 ( V_219 , & V_10 -> V_66 ) && ! ( V_10 -> V_484 [ V_514 ] & 1 ) )
V_498 = - 1 ;
if ( ! F_61 ( V_219 , & V_10 -> V_66 ) && ( V_10 -> V_484 [ V_514 ] & 1 ) )
V_498 = 1 ;
if ( abs ( V_498 ) < 100 )
F_31 ( V_10 , L_82
L_83 ,
( V_498 < 0 ) ? L_65 : L_79 ) ;
}
V_524 = V_30 -> V_524 ;
V_525 = V_30 -> V_525 ;
F_27 () ;
if ( V_498 == - 100 ) {
F_200 ( V_10 , L_84 ) ;
F_231 ( V_10 , L_85 ) ;
return V_522 ;
}
if ( V_498 > 0 && V_523 <= V_410 ) {
F_41 ( V_10 , L_86 ) ;
return V_522 ;
}
if ( V_498 < 0 &&
V_10 -> V_356 . V_500 == V_473 && V_10 -> V_356 . V_422 >= V_532 ) {
switch ( V_524 ) {
case V_489 :
F_231 ( V_10 , L_87 ) ;
case V_491 :
F_41 ( V_10 , L_88 ) ;
return V_522 ;
case V_490 :
F_31 ( V_10 , L_89
L_90 ) ;
}
}
if ( V_525 || F_61 ( V_533 , & V_27 -> V_33 -> V_66 ) ) {
if ( V_498 == 0 )
F_60 ( V_10 , L_91 ) ;
else
F_60 ( V_10 , L_92 ,
F_238 ( V_498 > 0 ? V_357 : V_402 ) ,
abs ( V_498 ) >= 2 ? L_93 : L_94 ) ;
return V_522 ;
}
if ( abs ( V_498 ) >= 2 ) {
F_60 ( V_10 , L_95 ) ;
if ( F_239 ( V_10 , & V_534 , L_96 ,
V_535 ) )
return V_522 ;
}
if ( V_498 > 0 ) {
V_92 = V_536 ;
} else if ( V_498 < 0 ) {
V_92 = V_537 ;
} else {
V_92 = V_538 ;
if ( F_218 ( V_10 ) ) {
F_60 ( V_10 , L_97 ,
F_218 ( V_10 ) ) ;
}
}
return V_92 ;
}
static enum V_479 F_240 ( enum V_479 V_472 )
{
if ( V_472 == V_497 )
return V_496 ;
if ( V_472 == V_496 )
return V_497 ;
return V_472 ;
}
static int F_241 ( struct V_91 * V_33 , struct V_167 * V_168 )
{
struct V_539 * V_305 = V_168 -> V_93 ;
enum V_479 V_540 , V_541 , V_542 ;
int V_543 , V_544 , V_545 , V_546 ;
struct V_29 * V_30 , * V_547 , * V_548 = NULL ;
char V_549 [ V_550 ] = L_98 ;
struct V_551 * V_317 = NULL ;
void * V_311 = NULL , * V_313 = NULL ;
V_543 = F_117 ( V_305 -> V_552 ) ;
V_540 = F_117 ( V_305 -> V_480 ) ;
V_541 = F_117 ( V_305 -> V_499 ) ;
V_542 = F_117 ( V_305 -> V_503 ) ;
V_545 = F_117 ( V_305 -> V_378 ) ;
V_546 = F_117 ( V_305 -> V_553 ) ;
V_544 = V_546 & V_554 ;
if ( V_33 -> V_177 >= 87 ) {
int V_73 ;
if ( V_168 -> V_61 > sizeof( V_549 ) )
return - V_105 ;
V_73 = F_65 ( V_33 , V_549 , V_168 -> V_61 ) ;
if ( V_73 )
return V_73 ;
V_549 [ V_550 - 1 ] = 0 ;
}
if ( V_168 -> V_165 != V_555 ) {
F_95 ( V_533 , & V_33 -> V_66 ) ;
if ( V_546 & V_556 )
F_101 ( V_533 , & V_33 -> V_66 ) ;
F_25 () ;
V_30 = F_26 ( V_33 -> V_29 ) ;
if ( V_543 != V_30 -> V_403 ) {
F_41 ( V_33 , L_99 , L_100 ) ;
goto V_557;
}
if ( F_240 ( V_540 ) != V_30 -> V_480 ) {
F_41 ( V_33 , L_99 , L_101 ) ;
goto V_557;
}
if ( F_240 ( V_541 ) != V_30 -> V_499 ) {
F_41 ( V_33 , L_99 , L_102 ) ;
goto V_557;
}
if ( F_240 ( V_542 ) != V_30 -> V_503 ) {
F_41 ( V_33 , L_99 , L_103 ) ;
goto V_557;
}
if ( V_544 && V_30 -> V_190 ) {
F_41 ( V_33 , L_99 , L_104 ) ;
goto V_557;
}
if ( V_545 != V_30 -> V_378 ) {
F_41 ( V_33 , L_99 , L_105 ) ;
goto V_557;
}
if ( strcmp ( V_549 , V_30 -> V_549 ) ) {
F_41 ( V_33 , L_99 , L_106 ) ;
goto V_557;
}
F_27 () ;
}
if ( V_549 [ 0 ] ) {
int V_558 ;
V_317 = F_242 ( V_549 , 0 , V_559 ) ;
if ( ! V_317 ) {
F_41 ( V_33 , L_107 ,
V_549 ) ;
goto V_560;
}
V_558 = F_151 ( V_317 ) ;
V_311 = F_147 ( V_558 , V_561 ) ;
V_313 = F_147 ( V_558 , V_561 ) ;
if ( ! ( V_311 && V_313 ) ) {
F_41 ( V_33 , L_108 ) ;
goto V_560;
}
}
V_548 = F_147 ( sizeof( struct V_29 ) , V_561 ) ;
if ( ! V_548 ) {
F_41 ( V_33 , L_109 ) ;
goto V_560;
}
F_110 ( & V_33 -> V_93 . V_195 ) ;
F_110 ( & V_33 -> V_24 -> V_222 ) ;
V_547 = V_33 -> V_29 ;
* V_548 = * V_547 ;
V_548 -> V_403 = V_543 ;
V_548 -> V_480 = F_240 ( V_540 ) ;
V_548 -> V_499 = F_240 ( V_541 ) ;
V_548 -> V_503 = F_240 ( V_542 ) ;
V_548 -> V_378 = V_545 ;
F_243 ( V_33 -> V_29 , V_548 ) ;
F_111 ( & V_33 -> V_24 -> V_222 ) ;
F_111 ( & V_33 -> V_93 . V_195 ) ;
F_244 ( V_33 -> V_317 ) ;
F_46 ( V_33 -> V_311 ) ;
F_46 ( V_33 -> V_313 ) ;
V_33 -> V_317 = V_317 ;
V_33 -> V_311 = V_311 ;
V_33 -> V_313 = V_313 ;
if ( strcmp ( V_547 -> V_549 , V_549 ) )
F_60 ( V_33 , L_110 ,
V_549 [ 0 ] ? V_549 : L_111 ) ;
F_245 () ;
F_46 ( V_547 ) ;
return 0 ;
V_557:
F_27 () ;
V_560:
F_244 ( V_317 ) ;
F_46 ( V_311 ) ;
F_46 ( V_313 ) ;
F_63 ( V_33 , F_64 ( V_102 , V_147 ) , V_104 ) ;
return - V_105 ;
}
static
struct V_551 * F_246 ( const struct V_9 * V_10 ,
const char * V_562 , const char * V_563 )
{
struct V_551 * V_564 ;
if ( ! V_562 [ 0 ] )
return NULL ;
V_564 = F_242 ( V_562 , 0 , V_559 ) ;
if ( F_247 ( V_564 ) ) {
F_41 ( V_10 , L_112 ,
V_562 , V_563 , F_248 ( V_564 ) ) ;
return V_564 ;
}
return V_564 ;
}
static int F_249 ( struct V_91 * V_33 , struct V_167 * V_168 )
{
void * V_237 = V_33 -> V_93 . V_169 ;
int V_61 = V_168 -> V_61 ;
while ( V_61 ) {
int V_198 = F_69 ( int , V_61 , V_565 ) ;
V_198 = F_59 ( V_33 , V_237 , V_198 ) ;
if ( V_198 <= 0 ) {
if ( V_198 < 0 )
return V_198 ;
break;
}
V_61 -= V_198 ;
}
if ( V_61 )
return - V_105 ;
return 0 ;
}
static int F_250 ( struct V_91 * V_33 , struct V_167 * V_168 )
{
F_31 ( V_33 , L_113 ,
F_251 ( V_168 -> V_165 ) , V_168 -> V_186 ) ;
return F_249 ( V_33 , V_168 ) ;
}
static int F_252 ( struct V_91 * V_33 , struct V_167 * V_168 )
{
struct V_26 * V_27 ;
struct V_9 * V_10 ;
struct V_566 * V_305 ;
unsigned int V_166 , V_49 , V_567 ;
struct V_551 * V_568 = NULL ;
struct V_551 * V_569 = NULL ;
struct V_29 * V_547 , * V_548 = NULL ;
struct V_265 * V_570 = NULL , * V_571 = NULL ;
const int V_572 = V_33 -> V_177 ;
struct V_573 * V_574 = NULL , * V_575 = NULL ;
int V_576 = 0 ;
int V_73 ;
V_27 = F_144 ( V_33 , V_168 -> V_186 ) ;
if ( ! V_27 )
return F_250 ( V_33 , V_168 ) ;
V_10 = V_27 -> V_10 ;
V_567 = V_572 <= 87 ? sizeof( struct V_577 )
: V_572 == 88 ? sizeof( struct V_577 )
+ V_550
: V_572 <= 94 ? sizeof( struct V_578 )
: sizeof( struct V_566 ) ;
if ( V_168 -> V_61 > V_567 ) {
F_41 ( V_10 , L_114 ,
V_168 -> V_61 , V_567 ) ;
return - V_105 ;
}
if ( V_572 <= 88 ) {
V_166 = sizeof( struct V_577 ) ;
V_49 = V_168 -> V_61 - V_166 ;
} else if ( V_572 <= 94 ) {
V_166 = sizeof( struct V_578 ) ;
V_49 = V_168 -> V_61 - V_166 ;
F_47 ( V_10 , V_49 == 0 ) ;
} else {
V_166 = sizeof( struct V_566 ) ;
V_49 = V_168 -> V_61 - V_166 ;
F_47 ( V_10 , V_49 == 0 ) ;
}
V_305 = V_168 -> V_93 ;
memset ( V_305 -> V_579 , 0 , 2 * V_550 ) ;
V_73 = F_65 ( V_27 -> V_33 , V_305 , V_166 ) ;
if ( V_73 )
return V_73 ;
F_110 ( & V_33 -> V_24 -> V_222 ) ;
V_547 = V_27 -> V_33 -> V_29 ;
if ( F_121 ( V_10 ) ) {
V_571 = F_253 ( sizeof( struct V_265 ) , V_561 ) ;
if ( ! V_571 ) {
F_124 ( V_10 ) ;
F_111 ( & V_33 -> V_24 -> V_222 ) ;
F_41 ( V_10 , L_115 ) ;
return - V_279 ;
}
V_570 = V_10 -> V_240 -> V_265 ;
* V_571 = * V_570 ;
V_571 -> V_580 = F_117 ( V_305 -> V_580 ) ;
}
if ( V_572 >= 88 ) {
if ( V_572 == 88 ) {
if ( V_49 > V_550 || V_49 == 0 ) {
F_41 ( V_10 , L_116
L_117 ,
V_49 , V_550 ) ;
V_73 = - V_105 ;
goto V_581;
}
V_73 = F_65 ( V_27 -> V_33 , V_305 -> V_579 , V_49 ) ;
if ( V_73 )
goto V_581;
F_47 ( V_10 , V_305 -> V_579 [ V_49 - 1 ] == 0 ) ;
V_305 -> V_579 [ V_49 - 1 ] = 0 ;
} else {
F_47 ( V_10 , V_305 -> V_579 [ V_550 - 1 ] == 0 ) ;
F_47 ( V_10 , V_305 -> V_582 [ V_550 - 1 ] == 0 ) ;
V_305 -> V_579 [ V_550 - 1 ] = 0 ;
V_305 -> V_582 [ V_550 - 1 ] = 0 ;
}
if ( strcmp ( V_547 -> V_579 , V_305 -> V_579 ) ) {
if ( V_10 -> V_356 . V_102 == V_100 ) {
F_41 ( V_10 , L_118 ,
V_547 -> V_579 , V_305 -> V_579 ) ;
goto V_560;
}
V_568 = F_246 ( V_10 ,
V_305 -> V_579 , L_119 ) ;
if ( F_247 ( V_568 ) ) {
V_568 = NULL ;
goto V_560;
}
}
if ( V_572 >= 89 && strcmp ( V_547 -> V_582 , V_305 -> V_582 ) ) {
if ( V_10 -> V_356 . V_102 == V_100 ) {
F_41 ( V_10 , L_120 ,
V_547 -> V_582 , V_305 -> V_582 ) ;
goto V_560;
}
V_569 = F_246 ( V_10 ,
V_305 -> V_582 , L_121 ) ;
if ( F_247 ( V_569 ) ) {
V_569 = NULL ;
goto V_560;
}
}
if ( V_572 > 94 && V_571 ) {
V_571 -> V_583 = F_117 ( V_305 -> V_583 ) ;
V_571 -> V_584 = F_117 ( V_305 -> V_584 ) ;
V_571 -> V_585 = F_117 ( V_305 -> V_585 ) ;
V_571 -> V_586 = F_117 ( V_305 -> V_586 ) ;
V_576 = ( V_571 -> V_583 * 10 * V_587 ) / V_39 ;
if ( V_576 != V_10 -> V_588 -> V_61 ) {
V_575 = F_254 ( V_576 ) ;
if ( ! V_575 ) {
F_41 ( V_10 , L_122 ) ;
F_124 ( V_10 ) ;
goto V_560;
}
}
}
if ( V_568 || V_569 ) {
V_548 = F_253 ( sizeof( struct V_29 ) , V_561 ) ;
if ( ! V_548 ) {
F_41 ( V_10 , L_109 ) ;
goto V_560;
}
* V_548 = * V_547 ;
if ( V_568 ) {
strcpy ( V_548 -> V_579 , V_305 -> V_579 ) ;
V_548 -> V_589 = strlen ( V_305 -> V_579 ) + 1 ;
F_244 ( V_27 -> V_33 -> V_568 ) ;
V_27 -> V_33 -> V_568 = V_568 ;
F_60 ( V_10 , L_123 , V_305 -> V_579 ) ;
}
if ( V_569 ) {
strcpy ( V_548 -> V_582 , V_305 -> V_582 ) ;
V_548 -> V_590 = strlen ( V_305 -> V_582 ) + 1 ;
F_244 ( V_27 -> V_33 -> V_569 ) ;
V_27 -> V_33 -> V_569 = V_569 ;
F_60 ( V_10 , L_124 , V_305 -> V_582 ) ;
}
F_243 ( V_33 -> V_29 , V_548 ) ;
}
}
if ( V_571 ) {
F_243 ( V_10 -> V_240 -> V_265 , V_571 ) ;
F_124 ( V_10 ) ;
}
if ( V_575 ) {
V_574 = V_10 -> V_588 ;
F_243 ( V_10 -> V_588 , V_575 ) ;
}
F_111 ( & V_33 -> V_24 -> V_222 ) ;
F_245 () ;
if ( V_548 )
F_46 ( V_547 ) ;
F_46 ( V_570 ) ;
F_46 ( V_574 ) ;
return 0 ;
V_581:
if ( V_571 ) {
F_124 ( V_10 ) ;
F_46 ( V_571 ) ;
}
F_111 ( & V_33 -> V_24 -> V_222 ) ;
return - V_105 ;
V_560:
F_46 ( V_575 ) ;
if ( V_571 ) {
F_124 ( V_10 ) ;
F_46 ( V_571 ) ;
}
F_111 ( & V_33 -> V_24 -> V_222 ) ;
F_244 ( V_569 ) ;
F_244 ( V_568 ) ;
F_63 ( V_27 -> V_33 , F_64 ( V_102 , V_147 ) , V_104 ) ;
return - V_105 ;
}
static void F_255 ( struct V_9 * V_10 ,
const char * V_198 , T_3 V_42 , T_3 V_366 )
{
T_3 V_591 ;
if ( V_42 == 0 || V_366 == 0 )
return;
V_591 = ( V_42 > V_366 ) ? ( V_42 - V_366 ) : ( V_366 - V_42 ) ;
if ( V_591 > ( V_42 >> 3 ) || V_591 > ( V_366 >> 3 ) )
F_31 ( V_10 , L_125 , V_198 ,
( unsigned long long ) V_42 , ( unsigned long long ) V_366 ) ;
}
static int F_256 ( struct V_91 * V_33 , struct V_167 * V_168 )
{
struct V_26 * V_27 ;
struct V_9 * V_10 ;
struct V_592 * V_305 = V_168 -> V_93 ;
enum V_593 V_594 = V_595 ;
T_3 V_596 , V_597 , V_598 ;
int V_599 = 0 ;
enum V_600 V_601 ;
V_27 = F_144 ( V_33 , V_168 -> V_186 ) ;
if ( ! V_27 )
return F_250 ( V_33 , V_168 ) ;
V_10 = V_27 -> V_10 ;
V_596 = F_174 ( V_305 -> V_602 ) ;
V_597 = F_174 ( V_305 -> V_603 ) ;
V_10 -> V_596 = V_596 ;
if ( F_121 ( V_10 ) ) {
F_25 () ;
V_598 = F_26 ( V_10 -> V_240 -> V_265 ) -> V_604 ;
F_27 () ;
F_255 ( V_10 , L_126 ,
V_596 , F_257 ( V_10 -> V_240 ) ) ;
F_255 ( V_10 , L_127 ,
V_597 , V_598 ) ;
if ( V_10 -> V_356 . V_102 == V_100 )
V_597 = F_258 ( V_598 , V_597 ) ;
if ( F_259 ( V_10 , V_10 -> V_240 , V_597 , 0 ) <
F_150 ( V_10 -> V_308 ) &&
V_10 -> V_356 . V_422 >= V_605 &&
V_10 -> V_356 . V_102 < V_538 ) {
F_41 ( V_10 , L_128 ) ;
F_63 ( V_27 -> V_33 , F_64 ( V_102 , V_147 ) , V_104 ) ;
F_124 ( V_10 ) ;
return - V_105 ;
}
if ( V_598 != V_597 ) {
struct V_265 * V_570 , * V_571 = NULL ;
V_571 = F_253 ( sizeof( struct V_265 ) , V_561 ) ;
if ( ! V_571 ) {
F_41 ( V_10 , L_115 ) ;
F_124 ( V_10 ) ;
return - V_279 ;
}
F_110 ( & V_33 -> V_24 -> V_222 ) ;
V_570 = V_10 -> V_240 -> V_265 ;
* V_571 = * V_570 ;
V_571 -> V_604 = V_597 ;
F_243 ( V_10 -> V_240 -> V_265 , V_571 ) ;
F_111 ( & V_33 -> V_24 -> V_222 ) ;
F_245 () ;
F_46 ( V_570 ) ;
F_60 ( V_10 , L_129 ,
( unsigned long ) V_598 ) ;
}
F_124 ( V_10 ) ;
}
V_10 -> V_606 = F_117 ( V_305 -> V_607 ) ;
F_260 ( V_10 ) ;
V_601 = F_116 ( V_305 -> V_600 ) ;
if ( F_121 ( V_10 ) ) {
V_594 = F_261 ( V_10 , V_601 , NULL ) ;
F_124 ( V_10 ) ;
if ( V_594 == V_608 )
return - V_105 ;
F_262 ( V_10 ) ;
} else {
F_263 ( V_10 , V_596 ) ;
}
if ( F_121 ( V_10 ) ) {
if ( V_10 -> V_240 -> V_609 != F_150 ( V_10 -> V_240 -> V_241 ) ) {
V_10 -> V_240 -> V_609 = F_150 ( V_10 -> V_240 -> V_241 ) ;
V_599 = 1 ;
}
F_124 ( V_10 ) ;
}
if ( V_10 -> V_356 . V_102 > V_100 ) {
if ( F_174 ( V_305 -> V_610 ) !=
F_150 ( V_10 -> V_308 ) || V_599 ) {
F_92 ( V_27 , 0 , V_601 ) ;
}
if ( F_264 ( V_181 , & V_10 -> V_66 ) ||
( V_594 == V_611 && V_10 -> V_356 . V_102 == V_538 ) ) {
if ( V_10 -> V_356 . V_409 >= V_410 &&
V_10 -> V_356 . V_422 >= V_410 ) {
if ( V_601 & V_612 )
F_60 ( V_10 , L_130 ) ;
else
F_265 ( V_10 ) ;
} else
F_101 ( V_613 , & V_10 -> V_66 ) ;
}
}
return 0 ;
}
static int F_266 ( struct V_91 * V_33 , struct V_167 * V_168 )
{
struct V_26 * V_27 ;
struct V_9 * V_10 ;
struct V_614 * V_305 = V_168 -> V_93 ;
T_2 * V_484 ;
int V_6 , V_615 = 0 ;
V_27 = F_144 ( V_33 , V_168 -> V_186 ) ;
if ( ! V_27 )
return F_250 ( V_33 , V_168 ) ;
V_10 = V_27 -> V_10 ;
V_484 = F_147 ( sizeof( T_2 ) * V_616 , V_208 ) ;
if ( ! V_484 ) {
F_41 ( V_10 , L_131 ) ;
return false ;
}
for ( V_6 = V_506 ; V_6 < V_616 ; V_6 ++ )
V_484 [ V_6 ] = F_174 ( V_305 -> V_482 [ V_6 ] ) ;
F_46 ( V_10 -> V_484 ) ;
V_10 -> V_484 = V_484 ;
if ( V_10 -> V_356 . V_102 < V_538 &&
V_10 -> V_356 . V_422 < V_410 &&
V_10 -> V_356 . V_500 == V_473 &&
( V_10 -> V_617 & ~ ( ( T_2 ) 1 ) ) != ( V_484 [ V_506 ] & ~ ( ( T_2 ) 1 ) ) ) {
F_41 ( V_10 , L_132 ,
( unsigned long long ) V_10 -> V_617 ) ;
F_63 ( V_27 -> V_33 , F_64 ( V_102 , V_147 ) , V_104 ) ;
return - V_105 ;
}
if ( F_121 ( V_10 ) ) {
int V_618 =
V_10 -> V_356 . V_102 == V_538 &&
V_27 -> V_33 -> V_177 >= 90 &&
V_10 -> V_240 -> V_481 . V_482 [ V_506 ] == V_511 &&
( V_484 [ V_514 ] & 8 ) ;
if ( V_618 ) {
F_60 ( V_10 , L_133 ) ;
F_239 ( V_10 , & V_619 ,
L_134 ,
V_620 ) ;
F_267 ( V_10 , V_506 , V_484 [ V_506 ] ) ;
F_267 ( V_10 , V_483 , 0 ) ;
F_268 ( F_269 ( V_10 , V_422 , V_447 , V_409 , V_447 ) ,
V_193 , NULL ) ;
F_262 ( V_10 ) ;
V_615 = 1 ;
}
F_124 ( V_10 ) ;
} else if ( V_10 -> V_356 . V_422 < V_410 &&
V_10 -> V_356 . V_500 == V_473 ) {
V_615 = F_270 ( V_10 , V_484 [ V_506 ] ) ;
}
F_110 ( V_10 -> V_176 ) ;
F_111 ( V_10 -> V_176 ) ;
if ( V_10 -> V_356 . V_102 >= V_538 && V_10 -> V_356 . V_422 < V_410 )
V_615 |= F_270 ( V_10 , V_484 [ V_506 ] ) ;
if ( V_615 )
F_271 ( V_10 , L_135 ) ;
return 0 ;
}
static union V_621 F_272 ( union V_621 V_622 )
{
union V_621 V_623 ;
static enum V_517 V_624 [] = {
[ V_100 ] = V_100 ,
[ V_538 ] = V_538 ,
[ V_625 ] = V_626 ,
[ V_626 ] = V_625 ,
[ V_147 ] = V_627 ,
[ V_436 ] = V_437 ,
[ V_522 ] = V_522 ,
} ;
V_623 . V_6 = V_622 . V_6 ;
V_623 . V_102 = V_624 [ V_622 . V_102 ] ;
V_623 . V_472 = V_622 . V_500 ;
V_623 . V_500 = V_622 . V_472 ;
V_623 . V_409 = V_622 . V_422 ;
V_623 . V_422 = V_622 . V_409 ;
V_623 . V_628 = ( V_622 . V_629 | V_622 . V_630 ) ;
return V_623 ;
}
static int F_273 ( struct V_91 * V_33 , struct V_167 * V_168 )
{
struct V_26 * V_27 ;
struct V_9 * V_10 ;
struct V_631 * V_305 = V_168 -> V_93 ;
union V_621 V_632 , V_633 ;
enum V_191 V_92 ;
V_27 = F_144 ( V_33 , V_168 -> V_186 ) ;
if ( ! V_27 )
return - V_105 ;
V_10 = V_27 -> V_10 ;
V_632 . V_6 = F_117 ( V_305 -> V_632 ) ;
V_633 . V_6 = F_117 ( V_305 -> V_633 ) ;
if ( F_61 ( V_200 , & V_27 -> V_33 -> V_66 ) &&
F_274 ( V_10 -> V_176 ) ) {
F_275 ( V_27 , V_634 ) ;
return 0 ;
}
V_632 = F_272 ( V_632 ) ;
V_633 = F_272 ( V_633 ) ;
V_92 = F_230 ( V_10 , V_193 , V_632 , V_633 ) ;
F_275 ( V_27 , V_92 ) ;
F_262 ( V_10 ) ;
return 0 ;
}
static int F_276 ( struct V_91 * V_33 , struct V_167 * V_168 )
{
struct V_631 * V_305 = V_168 -> V_93 ;
union V_621 V_632 , V_633 ;
enum V_191 V_92 ;
V_632 . V_6 = F_117 ( V_305 -> V_632 ) ;
V_633 . V_6 = F_117 ( V_305 -> V_633 ) ;
if ( F_61 ( V_200 , & V_33 -> V_66 ) &&
F_274 ( & V_33 -> V_178 ) ) {
F_277 ( V_33 , V_634 ) ;
return 0 ;
}
V_632 = F_272 ( V_632 ) ;
V_633 = F_272 ( V_633 ) ;
V_92 = F_63 ( V_33 , V_632 , V_633 , V_193 | V_635 | V_636 ) ;
F_277 ( V_33 , V_92 ) ;
return 0 ;
}
static int F_278 ( struct V_91 * V_33 , struct V_167 * V_168 )
{
struct V_26 * V_27 ;
struct V_9 * V_10 ;
struct V_637 * V_305 = V_168 -> V_93 ;
union V_621 V_638 , V_639 , V_640 ;
enum V_520 V_641 ;
enum V_642 V_643 ;
int V_92 ;
V_27 = F_144 ( V_33 , V_168 -> V_186 ) ;
if ( ! V_27 )
return F_250 ( V_33 , V_168 ) ;
V_10 = V_27 -> V_10 ;
V_640 . V_6 = F_117 ( V_305 -> V_356 ) ;
V_641 = V_640 . V_422 ;
if ( V_640 . V_422 == V_513 ) {
V_641 = V_10 -> V_484 [ V_514 ] & 4 ? V_410 : V_532 ;
F_60 ( V_10 , L_136 , F_279 ( V_641 ) ) ;
}
F_20 ( & V_10 -> V_24 -> V_25 ) ;
V_28:
V_638 = V_639 = F_280 ( V_10 ) ;
F_21 ( & V_10 -> V_24 -> V_25 ) ;
if ( V_638 . V_102 <= V_627 )
return - V_94 ;
if ( ( V_638 . V_409 == V_410 || V_638 . V_409 == V_532 ) &&
V_641 == V_447 &&
V_638 . V_102 > V_538 && V_638 . V_422 == V_447 ) {
if ( V_640 . V_102 > V_538 &&
V_640 . V_102 < V_357 )
V_641 = V_410 ;
else if ( V_638 . V_102 >= V_357 &&
V_640 . V_102 == V_538 ) {
if ( F_218 ( V_10 ) <= V_10 -> V_439 )
F_281 ( V_10 ) ;
return 0 ;
}
}
if ( V_638 . V_102 == V_437 && V_638 . V_422 == V_447 &&
V_640 . V_102 == V_538 && V_641 == V_447 ) {
F_282 ( V_10 ) ;
F_281 ( V_10 ) ;
return 0 ;
}
if ( V_638 . V_409 == V_447 && V_641 == V_410 &&
V_638 . V_102 == V_538 && V_640 . V_102 > V_357 )
V_641 = V_447 ;
if ( V_639 . V_102 == V_100 )
V_639 . V_102 = V_538 ;
if ( V_640 . V_102 == V_644 )
V_639 . V_102 = V_645 ;
if ( V_10 -> V_484 && V_640 . V_422 >= V_513 &&
F_131 ( V_10 , V_513 ) ) {
int V_646 ;
V_646 = ( V_638 . V_102 < V_538 ) ;
V_646 |= ( V_638 . V_102 == V_538 &&
( V_640 . V_422 == V_513 ||
V_638 . V_422 == V_513 ) ) ;
V_646 |= F_61 ( V_647 , & V_10 -> V_66 ) ;
V_646 |= ( V_638 . V_102 == V_538 &&
( V_640 . V_102 >= V_625 &&
V_640 . V_102 <= V_537 ) ) ;
if ( V_646 )
V_639 . V_102 = F_237 ( V_27 , V_640 . V_500 , V_641 ) ;
F_124 ( V_10 ) ;
if ( V_639 . V_102 == V_522 ) {
V_639 . V_102 = V_538 ;
if ( V_10 -> V_356 . V_422 == V_513 ) {
F_283 ( V_10 , F_64 ( V_422 , V_648 ) ) ;
} else if ( V_640 . V_422 == V_513 ) {
F_41 ( V_10 , L_137 ) ;
V_640 . V_422 = V_649 ;
V_641 = V_649 ;
} else {
if ( F_264 ( V_533 , & V_27 -> V_33 -> V_66 ) )
return - V_105 ;
F_47 ( V_10 , V_638 . V_102 == V_100 ) ;
F_63 ( V_27 -> V_33 , F_64 ( V_102 , V_147 ) , V_104 ) ;
return - V_105 ;
}
}
}
F_20 ( & V_10 -> V_24 -> V_25 ) ;
if ( V_638 . V_6 != F_280 ( V_10 ) . V_6 )
goto V_28;
F_95 ( V_647 , & V_10 -> V_66 ) ;
V_639 . V_472 = V_640 . V_500 ;
V_639 . V_409 = V_641 ;
V_639 . V_628 = ( V_640 . V_629 | V_640 . V_630 ) ;
if ( ( V_639 . V_102 == V_538 || V_639 . V_102 == V_536 ) && V_639 . V_422 == V_513 )
V_639 . V_422 = V_10 -> V_526 . V_422 ;
V_643 = V_193 + ( V_638 . V_102 < V_538 && V_639 . V_102 >= V_538 ? 0 : V_104 ) ;
if ( V_639 . V_409 == V_532 && F_284 ( V_10 ) && V_639 . V_102 == V_538 && V_638 . V_102 < V_538 &&
F_61 ( V_650 , & V_10 -> V_66 ) ) {
F_21 ( & V_10 -> V_24 -> V_25 ) ;
F_41 ( V_10 , L_138 ) ;
F_285 ( V_27 -> V_33 ) ;
F_286 ( V_10 ) ;
F_95 ( V_650 , & V_10 -> V_66 ) ;
F_63 ( V_27 -> V_33 , F_287 ( V_102 , V_651 , V_652 , 0 ) , V_104 ) ;
return - V_105 ;
}
V_92 = F_268 ( V_10 , V_639 , V_643 , NULL ) ;
V_639 = F_280 ( V_10 ) ;
F_21 ( & V_10 -> V_24 -> V_25 ) ;
if ( V_92 < V_194 ) {
F_63 ( V_27 -> V_33 , F_64 ( V_102 , V_147 ) , V_104 ) ;
return - V_105 ;
}
if ( V_638 . V_102 > V_100 ) {
if ( V_639 . V_102 > V_538 && V_640 . V_102 <= V_538 &&
V_640 . V_422 != V_513 ) {
F_93 ( V_27 ) ;
F_94 ( V_27 ) ;
}
}
F_95 ( V_219 , & V_10 -> V_66 ) ;
F_262 ( V_10 ) ;
return 0 ;
}
static int F_288 ( struct V_91 * V_33 , struct V_167 * V_168 )
{
struct V_26 * V_27 ;
struct V_9 * V_10 ;
struct V_653 * V_305 = V_168 -> V_93 ;
V_27 = F_144 ( V_33 , V_168 -> V_186 ) ;
if ( ! V_27 )
return - V_105 ;
V_10 = V_27 -> V_10 ;
F_208 ( V_10 -> V_300 ,
V_10 -> V_356 . V_102 == V_654 ||
V_10 -> V_356 . V_102 == V_645 ||
V_10 -> V_356 . V_102 < V_538 ||
V_10 -> V_356 . V_422 < V_513 ) ;
if ( F_131 ( V_10 , V_513 ) ) {
F_267 ( V_10 , V_506 , F_174 ( V_305 -> V_482 ) ) ;
F_267 ( V_10 , V_483 , 0UL ) ;
F_271 ( V_10 , L_139 ) ;
F_289 ( V_10 , V_402 ) ;
F_124 ( V_10 ) ;
} else
F_41 ( V_10 , L_140 ) ;
return 0 ;
}
static int
F_290 ( struct V_26 * V_27 , unsigned int V_61 ,
unsigned long * V_305 , struct V_655 * V_656 )
{
unsigned int V_49 = V_565 -
F_87 ( V_27 -> V_33 ) ;
unsigned int V_657 = F_69 ( T_6 , V_49 / sizeof( * V_305 ) ,
V_656 -> V_658 - V_656 -> V_659 ) ;
unsigned int V_660 = V_657 * sizeof( * V_305 ) ;
int V_73 ;
if ( V_660 != V_61 ) {
F_41 ( V_27 , L_141 , V_58 , V_660 , V_61 ) ;
return - V_105 ;
}
if ( V_660 == 0 )
return 0 ;
V_73 = F_65 ( V_27 -> V_33 , V_305 , V_660 ) ;
if ( V_73 )
return V_73 ;
F_291 ( V_27 -> V_10 , V_656 -> V_659 , V_657 , V_305 ) ;
V_656 -> V_659 += V_657 ;
V_656 -> V_661 = V_656 -> V_659 * V_662 ;
if ( V_656 -> V_661 > V_656 -> V_663 )
V_656 -> V_661 = V_656 -> V_663 ;
return 1 ;
}
static enum V_664 F_292 ( struct V_665 * V_305 )
{
return (enum V_664 ) ( V_305 -> V_666 & 0x0f ) ;
}
static int F_293 ( struct V_665 * V_305 )
{
return ( V_305 -> V_666 & 0x80 ) != 0 ;
}
static int F_294 ( struct V_665 * V_305 )
{
return ( V_305 -> V_666 >> 4 ) & 0x7 ;
}
static int
F_295 ( struct V_26 * V_27 ,
struct V_665 * V_305 ,
struct V_655 * V_656 ,
unsigned int V_5 )
{
struct V_667 V_668 ;
T_2 V_669 ;
T_2 V_670 ;
T_2 V_4 ;
unsigned long V_198 = V_656 -> V_661 ;
unsigned long V_671 ;
int V_672 = F_293 ( V_305 ) ;
int V_673 ;
int V_505 ;
F_296 ( & V_668 , V_305 -> V_674 , V_5 , F_294 ( V_305 ) ) ;
V_505 = F_297 ( & V_668 , & V_669 , 64 ) ;
if ( V_505 < 0 )
return - V_105 ;
for ( V_673 = V_505 ; V_673 > 0 ; V_198 += V_670 , V_672 = ! V_672 ) {
V_505 = F_298 ( & V_670 , V_669 ) ;
if ( V_505 <= 0 )
return - V_105 ;
if ( V_672 ) {
V_671 = V_198 + V_670 - 1 ;
if ( V_671 >= V_656 -> V_663 ) {
F_41 ( V_27 , L_142 , V_671 ) ;
return - V_105 ;
}
F_299 ( V_27 -> V_10 , V_198 , V_671 ) ;
}
if ( V_673 < V_505 ) {
F_41 ( V_27 , L_143 ,
V_673 , V_505 , V_669 ,
( unsigned int ) ( V_668 . V_675 . V_366 - V_305 -> V_674 ) ,
( unsigned int ) V_668 . V_676 ) ;
return - V_105 ;
}
if ( F_163 ( V_505 < 64 ) )
V_669 >>= V_505 ;
else
V_669 = 0 ;
V_673 -= V_505 ;
V_505 = F_297 ( & V_668 , & V_4 , 64 - V_673 ) ;
if ( V_505 < 0 )
return - V_105 ;
V_669 |= V_4 << V_673 ;
V_673 += V_505 ;
}
V_656 -> V_661 = V_198 ;
F_300 ( V_656 ) ;
return ( V_198 != V_656 -> V_663 ) ;
}
static int
F_301 ( struct V_26 * V_27 ,
struct V_665 * V_305 ,
struct V_655 * V_656 ,
unsigned int V_5 )
{
if ( F_292 ( V_305 ) == V_677 )
return F_295 ( V_27 , V_305 , V_656 , V_5 - sizeof( * V_305 ) ) ;
F_41 ( V_27 , L_144 , V_305 -> V_666 ) ;
F_63 ( V_27 -> V_33 , F_64 ( V_102 , V_651 ) , V_104 ) ;
return - V_105 ;
}
void F_302 ( struct V_9 * V_10 ,
const char * V_678 , struct V_655 * V_656 )
{
unsigned int V_166 = F_87 ( F_134 ( V_10 ) -> V_33 ) ;
unsigned int V_49 = V_565 - V_166 ;
unsigned int V_679 =
V_166 * ( F_303 ( V_656 -> V_658 , V_49 ) + 1 ) +
V_656 -> V_658 * sizeof( unsigned long ) ;
unsigned int V_680 = V_656 -> V_681 [ 0 ] + V_656 -> V_681 [ 1 ] ;
unsigned int V_682 ;
if ( V_680 == 0 )
return;
if ( V_680 >= V_679 )
return;
V_682 = ( V_680 > V_40 / 1000 ) ? ( V_680 / ( V_679 / 1000 ) )
: ( 1000 * V_680 / V_679 ) ;
if ( V_682 > 1000 )
V_682 = 1000 ;
V_682 = 1000 - V_682 ;
F_60 ( V_10 , L_145
L_146 ,
V_678 ,
V_656 -> V_681 [ 1 ] , V_656 -> V_683 [ 1 ] ,
V_656 -> V_681 [ 0 ] , V_656 -> V_683 [ 0 ] ,
V_680 , V_682 / 10 , V_682 % 10 ) ;
}
static int F_304 ( struct V_91 * V_33 , struct V_167 * V_168 )
{
struct V_26 * V_27 ;
struct V_9 * V_10 ;
struct V_655 V_656 ;
int V_73 ;
V_27 = F_144 ( V_33 , V_168 -> V_186 ) ;
if ( ! V_27 )
return - V_105 ;
V_10 = V_27 -> V_10 ;
F_305 ( V_10 , L_147 , V_535 ) ;
V_656 = (struct V_655 ) {
. V_663 = F_225 ( V_10 ) ,
. V_658 = F_306 ( V_10 ) ,
} ;
for(; ; ) {
if ( V_168 -> V_165 == V_684 )
V_73 = F_290 ( V_27 , V_168 -> V_61 , V_168 -> V_93 , & V_656 ) ;
else if ( V_168 -> V_165 == V_685 ) {
struct V_665 * V_305 = V_168 -> V_93 ;
if ( V_168 -> V_61 > V_565 - F_87 ( V_33 ) ) {
F_41 ( V_10 , L_148 ) ;
V_73 = - V_105 ;
goto V_101;
}
if ( V_168 -> V_61 <= sizeof( * V_305 ) ) {
F_41 ( V_10 , L_149 , V_168 -> V_61 ) ;
V_73 = - V_105 ;
goto V_101;
}
V_73 = F_65 ( V_27 -> V_33 , V_305 , V_168 -> V_61 ) ;
if ( V_73 )
goto V_101;
V_73 = F_301 ( V_27 , V_305 , & V_656 , V_168 -> V_61 ) ;
} else {
F_31 ( V_10 , L_150 , V_168 -> V_165 ) ;
V_73 = - V_105 ;
goto V_101;
}
V_656 . V_683 [ V_168 -> V_165 == V_684 ] ++ ;
V_656 . V_681 [ V_168 -> V_165 == V_684 ] += F_87 ( V_33 ) + V_168 -> V_61 ;
if ( V_73 <= 0 ) {
if ( V_73 < 0 )
goto V_101;
break;
}
V_73 = F_119 ( V_27 -> V_33 , V_168 ) ;
if ( V_73 )
goto V_101;
}
F_302 ( V_10 , L_151 , & V_656 ) ;
if ( V_10 -> V_356 . V_102 == V_537 ) {
enum V_191 V_92 ;
V_73 = F_307 ( V_10 ) ;
if ( V_73 )
goto V_101;
V_92 = F_308 ( V_10 , F_64 ( V_102 , V_654 ) , V_193 ) ;
F_47 ( V_10 , V_92 == V_194 ) ;
} else if ( V_10 -> V_356 . V_102 != V_536 ) {
F_60 ( V_10 , L_152 ,
F_238 ( V_10 -> V_356 . V_102 ) ) ;
}
V_73 = 0 ;
V_101:
F_309 ( V_10 ) ;
if ( ! V_73 && V_10 -> V_356 . V_102 == V_536 )
F_289 ( V_10 , V_357 ) ;
return V_73 ;
}
static int F_310 ( struct V_91 * V_33 , struct V_167 * V_168 )
{
F_31 ( V_33 , L_153 ,
V_168 -> V_165 , V_168 -> V_61 ) ;
return F_249 ( V_33 , V_168 ) ;
}
static int F_311 ( struct V_91 * V_33 , struct V_167 * V_168 )
{
F_312 ( V_33 -> V_93 . V_79 ) ;
return 0 ;
}
static int F_313 ( struct V_91 * V_33 , struct V_167 * V_168 )
{
struct V_26 * V_27 ;
struct V_9 * V_10 ;
struct V_686 * V_305 = V_168 -> V_93 ;
V_27 = F_144 ( V_33 , V_168 -> V_186 ) ;
if ( ! V_27 )
return - V_105 ;
V_10 = V_27 -> V_10 ;
switch ( V_10 -> V_356 . V_102 ) {
case V_654 :
case V_537 :
case V_645 :
break;
default:
F_41 ( V_10 , L_154 ,
F_238 ( V_10 -> V_356 . V_102 ) ) ;
}
F_209 ( V_10 , F_174 ( V_305 -> V_48 ) , F_117 ( V_305 -> V_446 ) ) ;
return 0 ;
}
static void F_314 ( struct V_91 * V_33 )
{
struct V_167 V_168 ;
T_6 V_687 ;
int V_73 ;
while ( F_104 ( & V_33 -> V_205 ) == V_688 ) {
struct V_689 * V_165 ;
F_315 ( & V_33 -> V_205 ) ;
if ( F_119 ( V_33 , & V_168 ) )
goto V_690;
V_165 = & V_691 [ V_168 . V_165 ] ;
if ( F_175 ( V_168 . V_165 >= F_316 ( V_691 ) || ! V_165 -> V_692 ) ) {
F_41 ( V_33 , L_155 ,
F_251 ( V_168 . V_165 ) , V_168 . V_165 ) ;
goto V_690;
}
V_687 = V_165 -> V_693 ;
if ( V_168 . V_61 > V_687 && ! V_165 -> V_694 ) {
F_41 ( V_33 , L_156 ,
F_251 ( V_168 . V_165 ) , V_168 . V_61 ) ;
goto V_690;
}
if ( V_687 ) {
V_73 = F_66 ( V_33 , V_168 . V_93 , V_687 ) ;
if ( V_73 )
goto V_690;
V_168 . V_61 -= V_687 ;
}
V_73 = V_165 -> V_692 ( V_33 , & V_168 ) ;
if ( V_73 ) {
F_41 ( V_33 , L_157 ,
F_251 ( V_168 . V_165 ) , V_73 , V_168 . V_61 ) ;
goto V_690;
}
}
return;
V_690:
F_63 ( V_33 , F_64 ( V_102 , V_651 ) , V_104 ) ;
}
static void F_317 ( struct V_91 * V_33 )
{
struct V_26 * V_27 ;
enum V_517 V_695 ;
int V_186 ;
if ( V_33 -> V_99 == V_696 )
return;
F_63 ( V_33 , F_64 ( V_102 , V_697 ) , V_104 ) ;
F_318 ( & V_33 -> V_221 ) ;
F_319 ( V_33 ) ;
F_25 () ;
F_109 (&connection->peer_devices, peer_device, vnr) {
struct V_9 * V_10 = V_27 -> V_10 ;
F_112 ( & V_10 -> V_218 ) ;
F_27 () ;
F_320 ( V_27 ) ;
F_113 ( & V_10 -> V_218 , V_220 ) ;
F_25 () ;
}
F_27 () ;
if ( ! F_54 ( & V_33 -> V_258 -> V_21 ) )
F_41 ( V_33 , L_158 ) ;
F_43 ( & V_33 -> V_258 -> V_247 , 0 ) ;
V_33 -> V_698 . V_699 = false ;
F_60 ( V_33 , L_159 ) ;
if ( F_321 ( V_33 ) == V_473 && F_322 ( V_33 ) >= V_700 )
F_323 ( V_33 ) ;
F_20 ( & V_33 -> V_24 -> V_25 ) ;
V_695 = V_33 -> V_99 ;
if ( V_695 >= V_701 )
F_203 ( V_33 , F_64 ( V_102 , V_701 ) , V_193 ) ;
F_21 ( & V_33 -> V_24 -> V_25 ) ;
if ( V_695 == V_147 )
F_63 ( V_33 , F_64 ( V_102 , V_696 ) , V_193 | V_104 ) ;
}
static int F_320 ( struct V_26 * V_27 )
{
struct V_9 * V_10 = V_27 -> V_10 ;
unsigned int V_6 ;
F_20 ( & V_10 -> V_24 -> V_25 ) ;
F_53 ( V_10 , & V_10 -> V_301 ) ;
F_53 ( V_10 , & V_10 -> V_336 ) ;
F_53 ( V_10 , & V_10 -> V_474 ) ;
F_21 ( & V_10 -> V_24 -> V_25 ) ;
F_324 ( V_10 ) ;
V_10 -> V_470 = 0 ;
V_10 -> V_439 = 0 ;
F_43 ( & V_10 -> V_702 , 0 ) ;
F_37 ( & V_10 -> V_300 ) ;
F_325 ( & V_10 -> V_703 ) ;
F_326 ( ( unsigned long ) V_10 ) ;
F_327 ( & V_27 -> V_33 -> V_704 ) ;
F_51 ( V_10 ) ;
F_327 ( & V_27 -> V_33 -> V_704 ) ;
F_324 ( V_10 ) ;
F_46 ( V_10 -> V_484 ) ;
V_10 -> V_484 = NULL ;
if ( ! F_284 ( V_10 ) )
F_285 ( V_27 -> V_33 ) ;
F_262 ( V_10 ) ;
F_208 ( V_10 -> V_300 , ! F_61 ( V_705 , & V_10 -> V_66 ) ) ;
V_6 = F_49 ( V_10 , & V_10 -> V_72 ) ;
if ( V_6 )
F_60 ( V_10 , L_160 , V_6 ) ;
V_6 = F_28 ( & V_10 -> V_43 ) ;
if ( V_6 )
F_60 ( V_10 , L_161 , V_6 ) ;
V_6 = F_28 ( & V_10 -> V_35 ) ;
if ( V_6 )
F_60 ( V_10 , L_162 , V_6 ) ;
F_47 ( V_10 , F_54 ( & V_10 -> V_474 ) ) ;
F_47 ( V_10 , F_54 ( & V_10 -> V_301 ) ) ;
F_47 ( V_10 , F_54 ( & V_10 -> V_336 ) ) ;
F_47 ( V_10 , F_54 ( & V_10 -> V_74 ) ) ;
return 0 ;
}
static int F_328 ( struct V_91 * V_33 )
{
struct V_163 * V_80 ;
struct V_706 * V_305 ;
V_80 = & V_33 -> V_93 ;
V_305 = F_84 ( V_33 , V_80 ) ;
if ( ! V_305 )
return - V_105 ;
memset ( V_305 , 0 , sizeof( * V_305 ) ) ;
V_305 -> V_707 = F_115 ( V_708 ) ;
V_305 -> V_709 = F_115 ( V_710 ) ;
V_305 -> V_711 = F_115 ( V_712 ) ;
return F_85 ( V_33 , V_80 , V_713 , sizeof( * V_305 ) , NULL , 0 ) ;
}
static int F_106 ( struct V_91 * V_33 )
{
struct V_706 * V_305 ;
const int F_152 = sizeof( struct V_706 ) ;
struct V_167 V_168 ;
int V_73 ;
V_73 = F_328 ( V_33 ) ;
if ( V_73 )
return 0 ;
V_73 = F_119 ( V_33 , & V_168 ) ;
if ( V_73 )
return 0 ;
if ( V_168 . V_165 != V_713 ) {
F_41 ( V_33 , L_163 ,
F_251 ( V_168 . V_165 ) , V_168 . V_165 ) ;
return - 1 ;
}
if ( V_168 . V_61 != F_152 ) {
F_41 ( V_33 , L_164 ,
F_152 , V_168 . V_61 ) ;
return - 1 ;
}
V_305 = V_168 . V_93 ;
V_73 = F_66 ( V_33 , V_305 , F_152 ) ;
if ( V_73 )
return 0 ;
V_305 -> V_707 = F_117 ( V_305 -> V_707 ) ;
V_305 -> V_709 = F_117 ( V_305 -> V_709 ) ;
if ( V_305 -> V_709 == 0 )
V_305 -> V_709 = V_305 -> V_707 ;
if ( V_710 < V_305 -> V_707 ||
V_708 > V_305 -> V_709 )
goto V_714;
V_33 -> V_177 = F_69 ( int , V_710 , V_305 -> V_709 ) ;
V_33 -> V_715 = V_712 & F_117 ( V_305 -> V_711 ) ;
F_60 ( V_33 , L_165
L_166 , V_33 -> V_177 ) ;
F_60 ( V_33 , L_167 ,
V_33 -> V_715 & V_716 ? L_168 : L_169 ) ;
return 1 ;
V_714:
F_41 ( V_33 , L_170
L_171 ,
V_708 , V_710 ,
V_305 -> V_707 , V_305 -> V_709 ) ;
return - 1 ;
}
static int F_107 ( struct V_91 * V_33 )
{
F_41 ( V_33 , L_172 ) ;
F_41 ( V_33 , L_173 ) ;
return - 1 ;
}
static int F_107 ( struct V_91 * V_33 )
{
struct V_163 * V_80 ;
char V_717 [ V_718 ] ;
struct V_719 V_720 ;
char * V_721 = NULL ;
char * V_722 = NULL ;
char * V_723 = NULL ;
unsigned int V_724 ;
char V_725 [ V_550 ] ;
unsigned int V_726 ;
struct V_727 V_728 ;
struct V_167 V_168 ;
struct V_29 * V_30 ;
int V_73 , V_92 ;
F_25 () ;
V_30 = F_26 ( V_33 -> V_29 ) ;
V_724 = strlen ( V_30 -> V_729 ) ;
memcpy ( V_725 , V_30 -> V_729 , V_724 ) ;
F_27 () ;
V_728 . V_564 = V_33 -> V_214 ;
V_728 . V_66 = 0 ;
V_92 = F_329 ( V_33 -> V_214 , ( V_730 * ) V_725 , V_724 ) ;
if ( V_92 ) {
F_41 ( V_33 , L_174 , V_92 ) ;
V_92 = - 1 ;
goto V_60;
}
F_330 ( V_717 , V_718 ) ;
V_80 = & V_33 -> V_93 ;
if ( ! F_84 ( V_33 , V_80 ) ) {
V_92 = 0 ;
goto V_60;
}
V_92 = ! F_85 ( V_33 , V_80 , V_731 , 0 ,
V_717 , V_718 ) ;
if ( ! V_92 )
goto V_60;
V_73 = F_119 ( V_33 , & V_168 ) ;
if ( V_73 ) {
V_92 = 0 ;
goto V_60;
}
if ( V_168 . V_165 != V_731 ) {
F_41 ( V_33 , L_175 ,
F_251 ( V_168 . V_165 ) , V_168 . V_165 ) ;
V_92 = 0 ;
goto V_60;
}
if ( V_168 . V_61 > V_718 * 2 ) {
F_41 ( V_33 , L_176 ) ;
V_92 = - 1 ;
goto V_60;
}
if ( V_168 . V_61 < V_718 ) {
F_41 ( V_33 , L_177 ) ;
V_92 = - 1 ;
goto V_60;
}
V_723 = F_147 ( V_168 . V_61 , V_208 ) ;
if ( V_723 == NULL ) {
F_41 ( V_33 , L_178 ) ;
V_92 = - 1 ;
goto V_60;
}
V_73 = F_66 ( V_33 , V_723 , V_168 . V_61 ) ;
if ( V_73 ) {
V_92 = 0 ;
goto V_60;
}
if ( ! memcmp ( V_717 , V_723 , V_718 ) ) {
F_41 ( V_33 , L_179 ) ;
V_92 = - 1 ;
goto V_60;
}
V_726 = F_151 ( V_33 -> V_214 ) ;
V_721 = F_147 ( V_726 , V_208 ) ;
if ( V_721 == NULL ) {
F_41 ( V_33 , L_180 ) ;
V_92 = - 1 ;
goto V_60;
}
F_331 ( & V_720 , 1 ) ;
F_332 ( & V_720 , V_723 , V_168 . V_61 ) ;
V_92 = F_333 ( & V_728 , & V_720 , V_720 . V_231 , V_721 ) ;
if ( V_92 ) {
F_41 ( V_33 , L_181 , V_92 ) ;
V_92 = - 1 ;
goto V_60;
}
if ( ! F_84 ( V_33 , V_80 ) ) {
V_92 = 0 ;
goto V_60;
}
V_92 = ! F_85 ( V_33 , V_80 , V_732 , 0 ,
V_721 , V_726 ) ;
if ( ! V_92 )
goto V_60;
V_73 = F_119 ( V_33 , & V_168 ) ;
if ( V_73 ) {
V_92 = 0 ;
goto V_60;
}
if ( V_168 . V_165 != V_732 ) {
F_41 ( V_33 , L_182 ,
F_251 ( V_168 . V_165 ) , V_168 . V_165 ) ;
V_92 = 0 ;
goto V_60;
}
if ( V_168 . V_61 != V_726 ) {
F_41 ( V_33 , L_183 ) ;
V_92 = 0 ;
goto V_60;
}
V_73 = F_66 ( V_33 , V_721 , V_726 ) ;
if ( V_73 ) {
V_92 = 0 ;
goto V_60;
}
V_722 = F_147 ( V_726 , V_208 ) ;
if ( V_722 == NULL ) {
F_41 ( V_33 , L_184 ) ;
V_92 = - 1 ;
goto V_60;
}
F_332 ( & V_720 , V_717 , V_718 ) ;
V_92 = F_333 ( & V_728 , & V_720 , V_720 . V_231 , V_722 ) ;
if ( V_92 ) {
F_41 ( V_33 , L_181 , V_92 ) ;
V_92 = - 1 ;
goto V_60;
}
V_92 = ! memcmp ( V_721 , V_722 , V_726 ) ;
if ( V_92 )
F_60 ( V_33 , L_185 ,
V_726 ) ;
else
V_92 = - 1 ;
V_60:
F_46 ( V_723 ) ;
F_46 ( V_721 ) ;
F_46 ( V_722 ) ;
return V_92 ;
}
int F_334 ( struct V_733 * V_734 )
{
struct V_91 * V_33 = V_734 -> V_33 ;
int V_188 ;
F_60 ( V_33 , L_186 ) ;
do {
V_188 = F_97 ( V_33 ) ;
if ( V_188 == 0 ) {
F_317 ( V_33 ) ;
F_100 ( V_39 ) ;
}
if ( V_188 == - 1 ) {
F_31 ( V_33 , L_187 ) ;
F_63 ( V_33 , F_64 ( V_102 , V_147 ) , V_104 ) ;
}
} while ( V_188 == 0 );
if ( V_188 > 0 )
F_314 ( V_33 ) ;
F_317 ( V_33 ) ;
F_60 ( V_33 , L_188 ) ;
return 0 ;
}
static int F_335 ( struct V_91 * V_33 , struct V_167 * V_168 )
{
struct V_735 * V_305 = V_168 -> V_93 ;
int V_736 = F_117 ( V_305 -> V_736 ) ;
if ( V_736 >= V_194 ) {
F_101 ( V_737 , & V_33 -> V_66 ) ;
} else {
F_101 ( V_738 , & V_33 -> V_66 ) ;
F_41 ( V_33 , L_189 ,
F_336 ( V_736 ) , V_736 ) ;
}
F_37 ( & V_33 -> V_98 ) ;
return 0 ;
}
static int F_337 ( struct V_91 * V_33 , struct V_167 * V_168 )
{
struct V_26 * V_27 ;
struct V_9 * V_10 ;
struct V_735 * V_305 = V_168 -> V_93 ;
int V_736 = F_117 ( V_305 -> V_736 ) ;
V_27 = F_144 ( V_33 , V_168 -> V_186 ) ;
if ( ! V_27 )
return - V_105 ;
V_10 = V_27 -> V_10 ;
if ( F_61 ( V_739 , & V_33 -> V_66 ) ) {
F_47 ( V_10 , V_33 -> V_177 < 100 ) ;
return F_335 ( V_33 , V_168 ) ;
}
if ( V_736 >= V_194 ) {
F_101 ( V_740 , & V_10 -> V_66 ) ;
} else {
F_101 ( V_741 , & V_10 -> V_66 ) ;
F_41 ( V_10 , L_189 ,
F_336 ( V_736 ) , V_736 ) ;
}
F_37 ( & V_10 -> V_742 ) ;
return 0 ;
}
static int F_338 ( struct V_91 * V_33 , struct V_167 * V_168 )
{
return F_339 ( V_33 ) ;
}
static int F_340 ( struct V_91 * V_33 , struct V_167 * V_168 )
{
V_33 -> V_197 . V_79 -> V_108 -> V_134 = V_33 -> V_29 -> V_212 * V_39 ;
if ( ! F_341 ( V_743 , & V_33 -> V_66 ) )
F_37 ( & V_33 -> V_98 ) ;
return 0 ;
}
static int F_342 ( struct V_91 * V_33 , struct V_167 * V_168 )
{
struct V_26 * V_27 ;
struct V_9 * V_10 ;
struct V_744 * V_305 = V_168 -> V_93 ;
T_3 V_48 = F_174 ( V_305 -> V_48 ) ;
int V_446 = F_117 ( V_305 -> V_446 ) ;
V_27 = F_144 ( V_33 , V_168 -> V_186 ) ;
if ( ! V_27 )
return - V_105 ;
V_10 = V_27 -> V_10 ;
F_47 ( V_10 , V_27 -> V_33 -> V_177 >= 89 ) ;
F_189 ( V_27 , F_117 ( V_305 -> V_396 ) ) ;
if ( F_121 ( V_10 ) ) {
F_343 ( V_10 , V_48 ) ;
F_164 ( V_10 , V_48 , V_446 ) ;
V_10 -> V_745 += ( V_446 >> V_746 ) ;
F_124 ( V_10 ) ;
}
F_169 ( V_10 ) ;
F_34 ( V_446 >> 9 , & V_10 -> V_348 ) ;
return 0 ;
}
static int
F_344 ( struct V_9 * V_10 , T_2 V_47 , T_3 V_48 ,
struct V_340 * V_341 , const char * V_343 ,
enum V_747 V_114 , bool V_342 )
{
struct V_320 * V_321 ;
struct V_388 V_389 ;
F_20 ( & V_10 -> V_24 -> V_25 ) ;
V_321 = F_171 ( V_10 , V_341 , V_47 , V_48 , V_342 , V_343 ) ;
if ( F_175 ( ! V_321 ) ) {
F_21 ( & V_10 -> V_24 -> V_25 ) ;
return - V_105 ;
}
F_182 ( V_321 , V_114 , & V_389 ) ;
F_21 ( & V_10 -> V_24 -> V_25 ) ;
if ( V_389 . V_275 )
F_196 ( V_10 , & V_389 ) ;
return 0 ;
}
static int F_345 ( struct V_91 * V_33 , struct V_167 * V_168 )
{
struct V_26 * V_27 ;
struct V_9 * V_10 ;
struct V_744 * V_305 = V_168 -> V_93 ;
T_3 V_48 = F_174 ( V_305 -> V_48 ) ;
int V_446 = F_117 ( V_305 -> V_446 ) ;
enum V_747 V_114 ;
V_27 = F_144 ( V_33 , V_168 -> V_186 ) ;
if ( ! V_27 )
return - V_105 ;
V_10 = V_27 -> V_10 ;
F_189 ( V_27 , F_117 ( V_305 -> V_396 ) ) ;
if ( V_305 -> V_67 == V_335 ) {
F_164 ( V_10 , V_48 , V_446 ) ;
F_169 ( V_10 ) ;
return 0 ;
}
switch ( V_168 -> V_165 ) {
case V_333 :
V_114 = V_748 ;
break;
case V_360 :
V_114 = V_749 ;
break;
case V_408 :
V_114 = V_750 ;
break;
case V_364 :
V_114 = V_352 ;
break;
case V_365 :
V_114 = V_751 ;
break;
default:
F_223 () ;
}
return F_344 ( V_10 , V_305 -> V_67 , V_48 ,
& V_10 -> V_299 , V_58 ,
V_114 , false ) ;
}
static int F_346 ( struct V_91 * V_33 , struct V_167 * V_168 )
{
struct V_26 * V_27 ;
struct V_9 * V_10 ;
struct V_744 * V_305 = V_168 -> V_93 ;
T_3 V_48 = F_174 ( V_305 -> V_48 ) ;
int V_61 = F_117 ( V_305 -> V_446 ) ;
int V_73 ;
V_27 = F_144 ( V_33 , V_168 -> V_186 ) ;
if ( ! V_27 )
return - V_105 ;
V_10 = V_27 -> V_10 ;
F_189 ( V_27 , F_117 ( V_305 -> V_396 ) ) ;
if ( V_305 -> V_67 == V_335 ) {
F_169 ( V_10 ) ;
F_166 ( V_10 , V_48 , V_61 ) ;
return 0 ;
}
V_73 = F_344 ( V_10 , V_305 -> V_67 , V_48 ,
& V_10 -> V_299 , V_58 ,
V_390 , true ) ;
if ( V_73 ) {
F_209 ( V_10 , V_48 , V_61 ) ;
}
return 0 ;
}
static int F_347 ( struct V_91 * V_33 , struct V_167 * V_168 )
{
struct V_26 * V_27 ;
struct V_9 * V_10 ;
struct V_744 * V_305 = V_168 -> V_93 ;
T_3 V_48 = F_174 ( V_305 -> V_48 ) ;
V_27 = F_144 ( V_33 , V_168 -> V_186 ) ;
if ( ! V_27 )
return - V_105 ;
V_10 = V_27 -> V_10 ;
F_189 ( V_27 , F_117 ( V_305 -> V_396 ) ) ;
F_41 ( V_10 , L_190 ,
( unsigned long long ) V_48 , F_117 ( V_305 -> V_446 ) ) ;
return F_344 ( V_10 , V_305 -> V_67 , V_48 ,
& V_10 -> V_345 , V_58 ,
V_390 , false ) ;
}
static int F_348 ( struct V_91 * V_33 , struct V_167 * V_168 )
{
struct V_26 * V_27 ;
struct V_9 * V_10 ;
T_3 V_48 ;
int V_61 ;
struct V_744 * V_305 = V_168 -> V_93 ;
V_27 = F_144 ( V_33 , V_168 -> V_186 ) ;
if ( ! V_27 )
return - V_105 ;
V_10 = V_27 -> V_10 ;
V_48 = F_174 ( V_305 -> V_48 ) ;
V_61 = F_117 ( V_305 -> V_446 ) ;
F_189 ( V_27 , F_117 ( V_305 -> V_396 ) ) ;
F_169 ( V_10 ) ;
if ( F_131 ( V_10 , V_648 ) ) {
F_343 ( V_10 , V_48 ) ;
switch ( V_168 -> V_165 ) {
case V_453 :
F_166 ( V_10 , V_48 , V_61 ) ;
case V_752 :
break;
default:
F_223 () ;
}
F_124 ( V_10 ) ;
}
return 0 ;
}
static int F_349 ( struct V_91 * V_33 , struct V_167 * V_168 )
{
struct V_753 * V_305 = V_168 -> V_93 ;
struct V_26 * V_27 ;
int V_186 ;
F_350 ( V_33 , V_305 -> V_306 , F_117 ( V_305 -> V_754 ) ) ;
F_25 () ;
F_109 (&connection->peer_devices, peer_device, vnr) {
struct V_9 * V_10 = V_27 -> V_10 ;
if ( V_10 -> V_356 . V_102 == V_644 &&
F_28 ( & V_10 -> V_182 ) == 0 &&
! F_341 ( V_755 , & V_10 -> V_66 ) ) {
V_10 -> V_756 . V_757 = V_184 + V_39 ;
F_351 ( & V_10 -> V_756 ) ;
}
}
F_27 () ;
return 0 ;
}
static int F_352 ( struct V_91 * V_33 , struct V_167 * V_168 )
{
struct V_26 * V_27 ;
struct V_9 * V_10 ;
struct V_744 * V_305 = V_168 -> V_93 ;
struct V_758 * V_759 ;
T_3 V_48 ;
int V_61 ;
V_27 = F_144 ( V_33 , V_168 -> V_186 ) ;
if ( ! V_27 )
return - V_105 ;
V_10 = V_27 -> V_10 ;
V_48 = F_174 ( V_305 -> V_48 ) ;
V_61 = F_117 ( V_305 -> V_446 ) ;
F_189 ( V_27 , F_117 ( V_305 -> V_396 ) ) ;
if ( F_174 ( V_305 -> V_67 ) == V_760 )
F_353 ( V_10 , V_48 , V_61 ) ;
else
F_282 ( V_10 ) ;
if ( ! F_121 ( V_10 ) )
return 0 ;
F_343 ( V_10 , V_48 ) ;
F_169 ( V_10 ) ;
-- V_10 -> V_438 ;
if ( ( V_10 -> V_438 & 0x200 ) == 0x200 )
F_354 ( V_10 , V_10 -> V_438 ) ;
if ( V_10 -> V_438 == 0 ) {
V_759 = F_147 ( sizeof( * V_759 ) , V_208 ) ;
if ( V_759 ) {
V_759 -> V_20 . V_76 = V_761 ;
V_759 -> V_10 = V_10 ;
F_355 ( & V_27 -> V_33 -> V_704 , & V_759 -> V_20 ) ;
} else {
F_41 ( V_10 , L_191 ) ;
F_282 ( V_10 ) ;
F_281 ( V_10 ) ;
}
}
F_124 ( V_10 ) ;
return 0 ;
}
static int F_356 ( struct V_91 * V_33 , struct V_167 * V_168 )
{
return 0 ;
}
static int F_357 ( struct V_91 * V_33 )
{
struct V_26 * V_27 ;
int V_186 , V_762 = 0 ;
do {
F_95 ( V_763 , & V_33 -> V_66 ) ;
F_102 ( V_38 ) ;
F_25 () ;
F_109 (&connection->peer_devices, peer_device, vnr) {
struct V_9 * V_10 = V_27 -> V_10 ;
F_112 ( & V_10 -> V_218 ) ;
F_27 () ;
if ( F_51 ( V_10 ) ) {
F_113 ( & V_10 -> V_218 , V_220 ) ;
return 1 ;
}
F_113 ( & V_10 -> V_218 , V_220 ) ;
F_25 () ;
}
F_101 ( V_763 , & V_33 -> V_66 ) ;
F_20 ( & V_33 -> V_24 -> V_25 ) ;
F_109 (&connection->peer_devices, peer_device, vnr) {
struct V_9 * V_10 = V_27 -> V_10 ;
V_762 = ! F_54 ( & V_10 -> V_74 ) ;
if ( V_762 )
break;
}
F_21 ( & V_33 -> V_24 -> V_25 ) ;
F_27 () ;
} while ( V_762 );
return 0 ;
}
int F_358 ( struct V_733 * V_734 )
{
struct V_91 * V_33 = V_734 -> V_33 ;
struct V_764 * V_165 = NULL ;
struct V_167 V_168 ;
int V_92 ;
void * V_81 = V_33 -> V_197 . V_169 ;
int V_765 = 0 ;
unsigned int V_166 = F_87 ( V_33 ) ;
int F_152 = V_166 ;
bool V_766 = false ;
struct V_29 * V_30 ;
int V_97 , V_767 , V_212 ;
struct V_768 V_769 = { . V_770 = 2 } ;
V_92 = F_359 ( V_38 , V_771 , & V_769 ) ;
if ( V_92 < 0 )
F_41 ( V_33 , L_192 , V_92 ) ;
while ( F_104 ( V_734 ) == V_688 ) {
F_315 ( V_734 ) ;
F_25 () ;
V_30 = F_26 ( V_33 -> V_29 ) ;
V_97 = V_30 -> V_97 ;
V_767 = V_30 -> V_767 ;
V_212 = V_30 -> V_212 ;
F_27 () ;
if ( F_264 ( V_772 , & V_33 -> V_66 ) ) {
if ( F_360 ( V_33 ) ) {
F_41 ( V_33 , L_193 ) ;
goto V_581;
}
V_33 -> V_197 . V_79 -> V_108 -> V_134 = V_97 * V_39 / 10 ;
V_766 = true ;
}
if ( V_767 )
F_361 ( V_33 -> V_197 . V_79 ) ;
if ( F_357 ( V_33 ) ) {
F_41 ( V_33 , L_194 ) ;
goto V_581;
}
if ( V_767 )
F_362 ( V_33 -> V_197 . V_79 ) ;
if ( F_30 ( V_38 ) )
continue;
V_92 = F_57 ( V_33 -> V_197 . V_79 , V_81 , F_152 - V_765 , 0 ) ;
F_95 ( V_763 , & V_33 -> V_66 ) ;
F_102 ( V_38 ) ;
if ( F_163 ( V_92 > 0 ) ) {
V_765 += V_92 ;
V_81 += V_92 ;
} else if ( V_92 == 0 ) {
if ( F_61 ( V_96 , & V_33 -> V_66 ) ) {
long V_23 ;
F_25 () ;
V_23 = F_26 ( V_33 -> V_29 ) -> V_97 * V_39 / 10 ;
F_27 () ;
V_23 = F_62 ( V_33 -> V_98 ,
V_33 -> V_99 < V_100 ,
V_23 ) ;
if ( V_23 )
break;
}
F_41 ( V_33 , L_195 ) ;
goto V_581;
} else if ( V_92 == - V_140 ) {
if ( F_363 ( V_33 -> V_213 ,
V_184 - V_33 -> V_197 . V_79 -> V_108 -> V_134 ) )
continue;
if ( V_766 ) {
F_41 ( V_33 , L_196 ) ;
goto V_581;
}
F_101 ( V_772 , & V_33 -> V_66 ) ;
continue;
} else if ( V_92 == - V_142 ) {
continue;
} else {
F_41 ( V_33 , L_7 , V_92 ) ;
goto V_581;
}
if ( V_765 == F_152 && V_165 == NULL ) {
if ( F_88 ( V_33 , V_33 -> V_197 . V_169 , & V_168 ) )
goto V_581;
V_165 = & V_773 [ V_168 . V_165 ] ;
if ( V_168 . V_165 >= F_316 ( V_773 ) || ! V_165 -> V_692 ) {
F_41 ( V_33 , L_197 ,
F_251 ( V_168 . V_165 ) , V_168 . V_165 ) ;
goto V_560;
}
F_152 = V_166 + V_165 -> V_693 ;
if ( V_168 . V_61 != F_152 - V_166 ) {
F_41 ( V_33 , L_198 ,
V_168 . V_165 , V_168 . V_61 ) ;
goto V_581;
}
}
if ( V_765 == F_152 ) {
bool V_73 ;
V_73 = V_165 -> V_692 ( V_33 , & V_168 ) ;
if ( V_73 ) {
F_41 ( V_33 , L_199 , V_165 -> V_692 ) ;
goto V_581;
}
V_33 -> V_213 = V_184 ;
if ( V_165 == & V_773 [ V_774 ] ) {
V_33 -> V_197 . V_79 -> V_108 -> V_134 = V_212 * V_39 ;
V_766 = false ;
}
V_81 = V_33 -> V_197 . V_169 ;
V_765 = 0 ;
F_152 = V_166 ;
V_165 = NULL ;
}
}
if ( 0 ) {
V_581:
F_63 ( V_33 , F_64 ( V_102 , V_697 ) , V_104 ) ;
F_364 ( V_33 ) ;
}
if ( 0 ) {
V_560:
F_63 ( V_33 , F_64 ( V_102 , V_147 ) , V_104 ) ;
}
F_95 ( V_763 , & V_33 -> V_66 ) ;
F_60 ( V_33 , L_200 ) ;
return 0 ;
}
