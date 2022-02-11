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
int V_32 ;
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
F_32 () ;
}
F_33 ( & V_36 , & V_31 ) ;
if ( V_1 )
F_34 ( V_11 , & V_10 -> V_35 ) ;
return V_1 ;
}
static void F_35 ( struct V_9 * V_10 , struct V_1 * V_1 , int V_39 )
{
T_1 * V_40 = V_39 ? & V_10 -> V_41 : & V_10 -> V_35 ;
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
V_6 = F_36 ( V_6 , V_40 ) ;
if ( V_6 < 0 )
F_31 ( V_10 , L_2 ,
V_39 ? L_3 : L_4 , V_6 ) ;
F_37 ( & V_36 ) ;
}
struct V_18 *
F_38 ( struct V_26 * V_27 , T_2 V_45 , T_3 V_46 ,
unsigned int V_47 , T_4 V_48 ) __must_hold( T_5 )
{
struct V_9 * V_10 = V_27 -> V_10 ;
struct V_18 * V_19 ;
struct V_1 * V_1 = NULL ;
unsigned V_49 = ( V_47 + V_43 - 1 ) >> V_50 ;
if ( F_39 ( V_10 , V_51 ) )
return NULL ;
V_19 = F_40 ( V_52 , V_48 & ~ V_53 ) ;
if ( ! V_19 ) {
if ( ! ( V_48 & V_54 ) )
F_41 ( V_10 , L_5 , V_55 ) ;
return NULL ;
}
if ( V_47 ) {
V_1 = F_23 ( V_27 , V_49 , ( V_48 & V_56 ) ) ;
if ( ! V_1 )
goto V_57;
}
F_42 ( & V_19 -> V_6 ) ;
V_19 -> V_6 . V_58 = V_47 ;
V_19 -> V_6 . V_46 = V_46 ;
V_19 -> V_6 . T_5 = false ;
V_19 -> V_6 . V_59 = false ;
V_19 -> V_60 = NULL ;
V_19 -> V_27 = V_27 ;
V_19 -> V_61 = V_1 ;
F_43 ( & V_19 -> V_62 , 0 ) ;
V_19 -> V_63 = 0 ;
V_19 -> V_64 = V_45 ;
return V_19 ;
V_57:
F_44 ( V_19 , V_52 ) ;
return NULL ;
}
void F_45 ( struct V_9 * V_10 , struct V_18 * V_19 ,
int V_39 )
{
if ( V_19 -> V_63 & V_65 )
F_46 ( V_19 -> V_66 ) ;
F_35 ( V_10 , V_19 -> V_61 , V_39 ) ;
F_47 ( V_10 , F_28 ( & V_19 -> V_62 ) == 0 ) ;
F_47 ( V_10 , F_48 ( & V_19 -> V_6 ) ) ;
F_44 ( V_19 , V_52 ) ;
}
int F_49 ( struct V_9 * V_10 , struct V_16 * V_21 )
{
F_19 ( V_67 ) ;
struct V_18 * V_19 , * V_23 ;
int V_68 = 0 ;
int V_39 = V_21 == & V_10 -> V_69 ;
F_20 ( & V_10 -> V_24 -> V_25 ) ;
F_50 ( V_21 , & V_67 ) ;
F_21 ( & V_10 -> V_24 -> V_25 ) ;
F_15 (peer_req, t, &work_list, w.list) {
F_45 ( V_10 , V_19 , V_39 ) ;
V_68 ++ ;
}
return V_68 ;
}
static int F_51 ( struct V_9 * V_10 )
{
F_19 ( V_67 ) ;
F_19 ( V_22 ) ;
struct V_18 * V_19 , * V_23 ;
int V_70 = 0 ;
F_20 ( & V_10 -> V_24 -> V_25 ) ;
F_14 ( V_10 , & V_22 ) ;
F_50 ( & V_10 -> V_71 , & V_67 ) ;
F_21 ( & V_10 -> V_24 -> V_25 ) ;
F_15 (peer_req, t, &reclaimed, w.list)
F_22 ( V_10 , V_19 ) ;
F_15 (peer_req, t, &work_list, w.list) {
int V_72 ;
V_72 = V_19 -> V_20 . V_73 ( & V_19 -> V_20 , ! ! V_70 ) ;
if ( ! V_70 )
V_70 = V_72 ;
F_52 ( V_10 , V_19 ) ;
}
F_37 ( & V_10 -> V_74 ) ;
return V_70 ;
}
static void F_53 ( struct V_9 * V_10 ,
struct V_16 * V_2 )
{
F_24 ( V_31 ) ;
while ( ! F_54 ( V_2 ) ) {
F_29 ( & V_10 -> V_74 , & V_31 , V_75 ) ;
F_21 ( & V_10 -> V_24 -> V_25 ) ;
F_55 () ;
F_33 ( & V_10 -> V_74 , & V_31 ) ;
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
static int F_57 ( struct V_76 * V_77 , void * V_78 , T_6 V_58 , int V_63 )
{
struct V_79 V_80 = {
. V_81 = V_78 ,
. V_82 = V_58 ,
} ;
struct V_83 V_84 = {
. V_85 = ( V_63 ? V_63 : V_86 | V_87 )
} ;
return F_58 ( V_77 , & V_84 , & V_80 , 1 , V_58 , V_84 . V_85 ) ;
}
static int F_59 ( struct V_88 * V_33 , void * V_78 , T_6 V_58 )
{
int V_89 ;
V_89 = F_57 ( V_33 -> V_90 . V_76 , V_78 , V_58 , 0 ) ;
if ( V_89 < 0 ) {
if ( V_89 == - V_91 )
F_60 ( V_33 , L_6 ) ;
else if ( V_89 != - V_92 )
F_41 ( V_33 , L_7 , V_89 ) ;
} else if ( V_89 == 0 ) {
if ( F_61 ( V_93 , & V_33 -> V_63 ) ) {
long V_23 ;
F_25 () ;
V_23 = F_26 ( V_33 -> V_29 ) -> V_94 * V_95 / 10 ;
F_27 () ;
V_23 = F_62 ( V_33 -> V_96 , V_33 -> V_97 < V_98 , V_23 ) ;
if ( V_23 )
goto V_99;
}
F_60 ( V_33 , L_8 ) ;
}
if ( V_89 != V_58 )
F_63 ( V_33 , F_64 ( V_100 , V_101 ) , V_102 ) ;
V_99:
return V_89 ;
}
static int F_65 ( struct V_88 * V_33 , void * V_78 , T_6 V_58 )
{
int V_70 ;
V_70 = F_59 ( V_33 , V_78 , V_58 ) ;
if ( V_70 != V_58 ) {
if ( V_70 >= 0 )
V_70 = - V_103 ;
} else
V_70 = 0 ;
return V_70 ;
}
static int F_66 ( struct V_88 * V_33 , void * V_78 , T_6 V_58 )
{
int V_70 ;
V_70 = F_65 ( V_33 , V_78 , V_58 ) ;
if ( V_70 && ! F_30 ( V_38 ) )
F_31 ( V_33 , L_9 , ( int ) V_58 ) ;
return V_70 ;
}
static void F_67 ( struct V_76 * V_77 , unsigned int V_104 ,
unsigned int V_105 )
{
if ( V_104 ) {
V_77 -> V_106 -> V_107 = V_104 ;
V_77 -> V_106 -> V_108 |= V_109 ;
}
if ( V_105 ) {
V_77 -> V_106 -> V_110 = V_105 ;
V_77 -> V_106 -> V_108 |= V_111 ;
}
}
static struct V_76 * F_68 ( struct V_88 * V_33 )
{
const char * V_112 ;
struct V_76 * V_77 ;
struct V_113 V_114 ;
struct V_113 V_115 ;
struct V_29 * V_30 ;
int V_70 , V_116 , V_117 ;
int V_118 , V_119 , V_120 ;
int V_121 = 1 ;
F_25 () ;
V_30 = F_26 ( V_33 -> V_29 ) ;
if ( ! V_30 ) {
F_27 () ;
return NULL ;
}
V_118 = V_30 -> V_118 ;
V_119 = V_30 -> V_119 ;
V_120 = V_30 -> V_120 ;
F_27 () ;
V_117 = F_69 ( int , V_33 -> V_117 , sizeof( V_114 ) ) ;
memcpy ( & V_114 , & V_33 -> V_122 , V_117 ) ;
if ( ( (struct V_123 * ) & V_33 -> V_122 ) -> V_124 == V_125 )
V_114 . V_126 = 0 ;
else
( (struct V_127 * ) & V_114 ) -> V_128 = 0 ;
V_116 = F_69 ( int , V_33 -> V_116 , sizeof( V_114 ) ) ;
memcpy ( & V_115 , & V_33 -> V_129 , V_116 ) ;
V_112 = L_10 ;
V_70 = F_70 ( ( (struct V_123 * ) & V_114 ) -> V_124 ,
V_130 , V_131 , & V_77 ) ;
if ( V_70 < 0 ) {
V_77 = NULL ;
goto V_99;
}
V_77 -> V_106 -> V_132 =
V_77 -> V_106 -> V_133 = V_120 * V_95 ;
F_67 ( V_77 , V_118 , V_119 ) ;
V_112 = L_11 ;
V_70 = V_77 -> V_134 -> V_135 ( V_77 , (struct V_123 * ) & V_114 , V_117 ) ;
if ( V_70 < 0 )
goto V_99;
V_121 = 0 ;
V_112 = L_12 ;
V_70 = V_77 -> V_134 -> V_136 ( V_77 , (struct V_123 * ) & V_115 , V_116 , 0 ) ;
V_99:
if ( V_70 < 0 ) {
if ( V_77 ) {
F_71 ( V_77 ) ;
V_77 = NULL ;
}
switch ( - V_70 ) {
case V_137 : case V_138 : case V_139 :
case V_140 : case V_92 :
case V_141 : case V_142 :
case V_143 : case V_144 :
V_121 = 0 ;
break;
default:
F_41 ( V_33 , L_13 , V_112 , V_70 ) ;
}
if ( V_121 )
F_63 ( V_33 , F_64 ( V_100 , V_145 ) , V_102 ) ;
}
return V_77 ;
}
static void F_72 ( struct V_77 * V_106 )
{
struct V_146 * V_147 = V_106 -> V_148 ;
void (* F_73)( struct V_77 * V_106 );
F_73 = V_147 -> V_149 ;
if ( V_106 -> V_150 == V_151 )
F_74 ( & V_147 -> V_152 ) ;
F_73 ( V_106 ) ;
}
static int F_75 ( struct V_88 * V_33 , struct V_146 * V_147 )
{
int V_70 , V_118 , V_119 , V_117 ;
struct V_113 V_122 ;
struct V_76 * V_153 ;
struct V_29 * V_30 ;
const char * V_112 ;
F_25 () ;
V_30 = F_26 ( V_33 -> V_29 ) ;
if ( ! V_30 ) {
F_27 () ;
return - V_103 ;
}
V_118 = V_30 -> V_118 ;
V_119 = V_30 -> V_119 ;
F_27 () ;
V_117 = F_69 ( int , V_33 -> V_117 , sizeof( struct V_113 ) ) ;
memcpy ( & V_122 , & V_33 -> V_122 , V_117 ) ;
V_112 = L_10 ;
V_70 = F_70 ( ( (struct V_123 * ) & V_122 ) -> V_124 ,
V_130 , V_131 , & V_153 ) ;
if ( V_70 ) {
V_153 = NULL ;
goto V_99;
}
V_153 -> V_106 -> V_154 = V_155 ;
F_67 ( V_153 , V_118 , V_119 ) ;
V_112 = L_14 ;
V_70 = V_153 -> V_134 -> V_135 ( V_153 , (struct V_123 * ) & V_122 , V_117 ) ;
if ( V_70 < 0 )
goto V_99;
V_147 -> V_153 = V_153 ;
F_76 ( & V_153 -> V_106 -> V_156 ) ;
V_147 -> V_149 = V_153 -> V_106 -> V_157 ;
V_153 -> V_106 -> V_157 = F_72 ;
V_153 -> V_106 -> V_148 = V_147 ;
F_77 ( & V_153 -> V_106 -> V_156 ) ;
V_112 = L_15 ;
V_70 = V_153 -> V_134 -> V_158 ( V_153 , 5 ) ;
if ( V_70 < 0 )
goto V_99;
return 0 ;
V_99:
if ( V_153 )
F_71 ( V_153 ) ;
if ( V_70 < 0 ) {
if ( V_70 != - V_138 && V_70 != - V_140 && V_70 != - V_92 ) {
F_41 ( V_33 , L_13 , V_112 , V_70 ) ;
F_63 ( V_33 , F_64 ( V_100 , V_145 ) , V_102 ) ;
}
}
return - V_103 ;
}
static void F_78 ( struct V_77 * V_106 , struct V_146 * V_147 )
{
F_76 ( & V_106 -> V_156 ) ;
V_106 -> V_157 = V_147 -> V_149 ;
V_106 -> V_148 = NULL ;
F_77 ( & V_106 -> V_156 ) ;
}
static struct V_76 * F_79 ( struct V_88 * V_33 , struct V_146 * V_147 )
{
int V_159 , V_120 , V_70 = 0 ;
struct V_76 * V_160 = NULL ;
struct V_29 * V_30 ;
F_25 () ;
V_30 = F_26 ( V_33 -> V_29 ) ;
if ( ! V_30 ) {
F_27 () ;
return NULL ;
}
V_120 = V_30 -> V_120 ;
F_27 () ;
V_159 = V_120 * V_95 ;
V_159 += ( F_80 () & 1 ) ? V_159 / 7 : - V_159 / 7 ;
V_70 = F_81 ( & V_147 -> V_152 , V_159 ) ;
if ( V_70 <= 0 )
return NULL ;
V_70 = F_82 ( V_147 -> V_153 , & V_160 , 0 ) ;
if ( V_70 < 0 ) {
if ( V_70 != - V_138 && V_70 != - V_140 && V_70 != - V_92 ) {
F_41 ( V_33 , L_16 , V_70 ) ;
F_63 ( V_33 , F_64 ( V_100 , V_145 ) , V_102 ) ;
}
}
if ( V_160 )
F_78 ( V_160 -> V_106 , V_147 ) ;
return V_160 ;
}
static int F_83 ( struct V_88 * V_33 , struct V_161 * V_77 ,
enum V_162 V_163 )
{
if ( ! F_84 ( V_33 , V_77 ) )
return - V_103 ;
return F_85 ( V_33 , V_77 , V_163 , 0 , NULL , 0 ) ;
}
static int F_86 ( struct V_88 * V_33 , struct V_76 * V_77 )
{
unsigned int V_164 = F_87 ( V_33 ) ;
struct V_165 V_166 ;
int V_70 ;
V_70 = F_57 ( V_77 , V_33 -> V_90 . V_167 , V_164 , 0 ) ;
if ( V_70 != V_164 ) {
if ( V_70 >= 0 )
V_70 = - V_103 ;
return V_70 ;
}
V_70 = F_88 ( V_33 , V_33 -> V_90 . V_167 , & V_166 ) ;
if ( V_70 )
return V_70 ;
return V_166 . V_163 ;
}
static int F_89 ( struct V_76 * * V_77 )
{
int V_168 ;
char V_169 [ 4 ] ;
if ( ! * V_77 )
return false ;
V_168 = F_57 ( * V_77 , V_169 , 4 , V_170 | V_171 ) ;
if ( V_168 > 0 || V_168 == - V_138 ) {
return true ;
} else {
F_71 ( * V_77 ) ;
* V_77 = NULL ;
return false ;
}
}
int F_90 ( struct V_26 * V_27 )
{
struct V_9 * V_10 = V_27 -> V_10 ;
int V_70 ;
F_43 ( & V_10 -> V_172 , 0 ) ;
V_10 -> V_173 = 0 ;
V_10 -> V_174 = V_27 -> V_33 -> V_175 < 100 ?
& V_27 -> V_33 -> V_176 :
& V_10 -> V_177 ;
V_70 = F_91 ( V_27 ) ;
if ( ! V_70 )
V_70 = F_92 ( V_27 , 0 , 0 ) ;
if ( ! V_70 )
V_70 = F_93 ( V_27 ) ;
if ( ! V_70 )
V_70 = F_94 ( V_27 ) ;
F_95 ( V_178 , & V_10 -> V_63 ) ;
F_95 ( V_179 , & V_10 -> V_63 ) ;
F_43 ( & V_10 -> V_180 , 0 ) ;
F_96 ( & V_10 -> V_181 , V_182 + V_95 ) ;
return V_70 ;
}
static int F_97 ( struct V_88 * V_33 )
{
struct V_161 V_77 , V_183 ;
struct V_26 * V_27 ;
struct V_29 * V_30 ;
int V_184 , V_185 , V_186 , V_187 ;
bool V_188 ;
enum V_189 V_89 ;
struct V_146 V_147 = {
. V_33 = V_33 ,
. V_152 = F_98 ( V_147 . V_152 ) ,
} ;
F_95 ( V_93 , & V_33 -> V_63 ) ;
if ( F_63 ( V_33 , F_64 ( V_100 , V_190 ) , V_191 ) < V_192 )
return - 2 ;
F_99 ( & V_77 . V_193 ) ;
V_77 . V_194 = V_33 -> V_90 . V_194 ;
V_77 . V_167 = V_33 -> V_90 . V_167 ;
V_77 . V_76 = NULL ;
F_99 ( & V_183 . V_193 ) ;
V_183 . V_194 = V_33 -> V_195 . V_194 ;
V_183 . V_167 = V_33 -> V_195 . V_167 ;
V_183 . V_76 = NULL ;
V_33 -> V_175 = 80 ;
if ( F_75 ( V_33 , & V_147 ) )
return 0 ;
do {
struct V_76 * V_196 ;
V_196 = F_68 ( V_33 ) ;
if ( V_196 ) {
if ( ! V_77 . V_76 ) {
V_77 . V_76 = V_196 ;
F_83 ( V_33 , & V_77 , V_197 ) ;
} else if ( ! V_183 . V_76 ) {
F_95 ( V_198 , & V_33 -> V_63 ) ;
V_183 . V_76 = V_196 ;
F_83 ( V_33 , & V_183 , V_199 ) ;
} else {
F_41 ( V_33 , L_17 ) ;
goto V_200;
}
}
if ( V_77 . V_76 && V_183 . V_76 ) {
F_25 () ;
V_30 = F_26 ( V_33 -> V_29 ) ;
V_185 = V_30 -> V_94 * V_95 / 10 ;
F_27 () ;
F_100 ( V_185 ) ;
V_187 = F_89 ( & V_77 . V_76 ) ;
V_187 = F_89 ( & V_183 . V_76 ) && V_187 ;
if ( V_187 )
break;
}
V_28:
V_196 = F_79 ( V_33 , & V_147 ) ;
if ( V_196 ) {
int V_201 = F_86 ( V_33 , V_196 ) ;
F_89 ( & V_77 . V_76 ) ;
F_89 ( & V_183 . V_76 ) ;
switch ( V_201 ) {
case V_197 :
if ( V_77 . V_76 ) {
F_31 ( V_33 , L_18 ) ;
F_71 ( V_77 . V_76 ) ;
V_77 . V_76 = V_196 ;
goto V_202;
}
V_77 . V_76 = V_196 ;
break;
case V_199 :
F_101 ( V_198 , & V_33 -> V_63 ) ;
if ( V_183 . V_76 ) {
F_31 ( V_33 , L_19 ) ;
F_71 ( V_183 . V_76 ) ;
V_183 . V_76 = V_196 ;
goto V_202;
}
V_183 . V_76 = V_196 ;
break;
default:
F_31 ( V_33 , L_20 ) ;
F_71 ( V_196 ) ;
V_202:
if ( F_80 () & 1 )
goto V_28;
}
}
if ( V_33 -> V_97 <= V_145 )
goto V_200;
if ( F_30 ( V_38 ) ) {
F_102 ( V_38 ) ;
F_103 () ;
if ( F_104 ( & V_33 -> V_203 ) == V_204 )
goto V_200;
}
V_187 = F_89 ( & V_77 . V_76 ) ;
V_187 = F_89 ( & V_183 . V_76 ) && V_187 ;
} while ( ! V_187 );
if ( V_147 . V_153 )
F_71 ( V_147 . V_153 ) ;
V_77 . V_76 -> V_106 -> V_154 = V_155 ;
V_183 . V_76 -> V_106 -> V_154 = V_155 ;
V_77 . V_76 -> V_106 -> V_205 = V_206 ;
V_183 . V_76 -> V_106 -> V_205 = V_206 ;
V_77 . V_76 -> V_106 -> V_207 = V_208 ;
V_183 . V_76 -> V_106 -> V_207 = V_209 ;
F_25 () ;
V_30 = F_26 ( V_33 -> V_29 ) ;
V_77 . V_76 -> V_106 -> V_133 =
V_77 . V_76 -> V_106 -> V_132 = V_30 -> V_94 * 4 * V_95 / 10 ;
V_183 . V_76 -> V_106 -> V_132 = V_30 -> V_210 * V_95 ;
V_185 = V_30 -> V_185 * V_95 / 10 ;
V_188 = V_30 -> V_188 ;
F_27 () ;
V_183 . V_76 -> V_106 -> V_133 = V_185 ;
F_105 ( V_77 . V_76 ) ;
F_105 ( V_183 . V_76 ) ;
V_33 -> V_90 . V_76 = V_77 . V_76 ;
V_33 -> V_195 . V_76 = V_183 . V_76 ;
V_33 -> V_211 = V_182 ;
V_186 = F_106 ( V_33 ) ;
if ( V_186 <= 0 )
return V_186 ;
if ( V_33 -> V_212 ) {
switch ( F_107 ( V_33 ) ) {
case - 1 :
F_41 ( V_33 , L_21 ) ;
return - 1 ;
case 0 :
F_41 ( V_33 , L_22 ) ;
return 0 ;
}
}
V_33 -> V_90 . V_76 -> V_106 -> V_133 = V_185 ;
V_33 -> V_90 . V_76 -> V_106 -> V_132 = V_213 ;
if ( F_108 ( V_33 ) == - V_214 )
return - 1 ;
F_101 ( V_215 , & V_33 -> V_63 ) ;
F_25 () ;
F_109 (&connection->peer_devices, peer_device, vnr) {
struct V_9 * V_10 = V_27 -> V_10 ;
F_110 ( & V_10 -> V_216 ) ;
F_27 () ;
F_111 ( V_10 -> V_174 ) ;
F_112 ( V_10 -> V_174 ) ;
if ( V_188 )
F_101 ( V_217 , & V_10 -> V_63 ) ;
else
F_95 ( V_217 , & V_10 -> V_63 ) ;
F_90 ( V_27 ) ;
F_113 ( & V_10 -> V_216 , V_218 ) ;
F_25 () ;
}
F_27 () ;
V_89 = F_63 ( V_33 , F_64 ( V_100 , V_98 ) , V_191 ) ;
if ( V_89 < V_192 || V_33 -> V_97 != V_98 ) {
F_95 ( V_215 , & V_33 -> V_63 ) ;
return 0 ;
}
F_114 ( & V_33 -> V_219 ) ;
F_111 ( & V_33 -> V_24 -> V_220 ) ;
V_33 -> V_29 -> V_188 = 0 ;
F_112 ( & V_33 -> V_24 -> V_220 ) ;
return V_186 ;
V_200:
if ( V_147 . V_153 )
F_71 ( V_147 . V_153 ) ;
if ( V_77 . V_76 )
F_71 ( V_77 . V_76 ) ;
if ( V_183 . V_76 )
F_71 ( V_183 . V_76 ) ;
return - 1 ;
}
static int F_88 ( struct V_88 * V_33 , void * V_221 , struct V_165 * V_166 )
{
unsigned int V_164 = F_87 ( V_33 ) ;
if ( V_164 == sizeof( struct V_222 ) &&
* ( V_223 * ) V_221 == F_115 ( V_224 ) ) {
struct V_222 * V_186 = V_221 ;
if ( V_186 -> V_225 != 0 ) {
F_41 ( V_33 , L_23 ) ;
return - V_226 ;
}
V_166 -> V_184 = F_116 ( V_186 -> V_227 ) ;
V_166 -> V_163 = F_116 ( V_186 -> V_228 ) ;
V_166 -> V_58 = F_117 ( V_186 -> V_229 ) ;
} else if ( V_164 == sizeof( struct V_230 ) &&
* ( V_231 * ) V_221 == F_118 ( V_232 ) ) {
struct V_230 * V_186 = V_221 ;
V_166 -> V_163 = F_116 ( V_186 -> V_228 ) ;
V_166 -> V_58 = F_117 ( V_186 -> V_229 ) ;
V_166 -> V_184 = 0 ;
} else if ( V_164 == sizeof( struct V_233 ) &&
* ( V_223 * ) V_221 == F_115 ( V_234 ) ) {
struct V_233 * V_186 = V_221 ;
V_166 -> V_163 = F_116 ( V_186 -> V_228 ) ;
V_166 -> V_58 = F_116 ( V_186 -> V_229 ) ;
V_166 -> V_184 = 0 ;
} else {
F_41 ( V_33 , L_24 ,
F_117 ( * ( V_223 * ) V_221 ) ,
V_33 -> V_175 ) ;
return - V_226 ;
}
V_166 -> V_90 = V_221 + V_164 ;
return 0 ;
}
static int F_119 ( struct V_88 * V_33 , struct V_165 * V_166 )
{
void * V_235 = V_33 -> V_90 . V_167 ;
int V_70 ;
V_70 = F_66 ( V_33 , V_235 , F_87 ( V_33 ) ) ;
if ( V_70 )
return V_70 ;
V_70 = F_88 ( V_33 , V_235 , V_166 ) ;
V_33 -> V_211 = V_182 ;
return V_70 ;
}
static void F_120 ( struct V_88 * V_33 )
{
int V_89 ;
struct V_26 * V_27 ;
int V_184 ;
if ( V_33 -> V_236 >= V_237 ) {
F_25 () ;
F_109 (&connection->peer_devices, peer_device, vnr) {
struct V_9 * V_10 = V_27 -> V_10 ;
if ( ! F_121 ( V_10 ) )
continue;
F_110 ( & V_10 -> V_216 ) ;
F_27 () ;
V_89 = F_122 ( V_10 -> V_238 -> V_239 ,
V_206 , NULL ) ;
if ( V_89 ) {
F_60 ( V_10 , L_25 , V_89 ) ;
F_123 ( V_33 , V_240 ) ;
}
F_124 ( V_10 ) ;
F_113 ( & V_10 -> V_216 , V_218 ) ;
F_25 () ;
if ( V_89 )
break;
}
F_27 () ;
}
}
static enum V_241 F_125 ( struct V_88 * V_33 ,
struct V_242 * V_60 ,
enum V_243 V_244 )
{
int V_245 ;
struct V_242 * V_246 ;
enum V_241 V_89 = V_247 ;
F_11 ( & V_33 -> V_248 ) ;
do {
V_246 = NULL ;
V_245 = F_28 ( & V_60 -> V_245 ) ;
switch ( V_244 & ~ V_249 ) {
case V_250 :
F_126 ( & V_60 -> V_251 ) ;
break;
case V_252 :
F_101 ( V_253 , & V_60 -> V_63 ) ;
break;
case V_254 :
break;
}
if ( V_245 != 0 &&
F_28 ( & V_60 -> V_251 ) == 0 &&
( F_61 ( V_253 , & V_60 -> V_63 ) || V_244 & V_249 ) ) {
if ( ! ( V_244 & V_249 ) ) {
F_12 ( & V_33 -> V_248 ) ;
F_127 ( V_60 -> V_33 , V_60 -> V_255 , V_245 ) ;
F_11 ( & V_33 -> V_248 ) ;
}
#if 0
if (test_bit(DE_HAVE_BARRIER_NUMBER, &epoch->flags))
dec_unacked(epoch->connection);
#endif
if ( V_33 -> V_256 != V_60 ) {
V_246 = F_128 ( V_60 -> V_21 . V_257 , struct V_242 , V_21 ) ;
F_129 ( & V_60 -> V_21 ) ;
V_244 = V_254 | ( V_244 & V_249 ) ;
V_33 -> V_258 -- ;
F_46 ( V_60 ) ;
if ( V_89 == V_247 )
V_89 = V_259 ;
} else {
V_60 -> V_63 = 0 ;
F_43 ( & V_60 -> V_245 , 0 ) ;
if ( V_89 == V_247 )
V_89 = V_260 ;
}
}
if ( ! V_246 )
break;
V_60 = V_246 ;
} while ( 1 );
F_12 ( & V_33 -> V_248 ) ;
return V_89 ;
}
void F_123 ( struct V_88 * V_33 , enum V_261 V_262 )
{
struct V_263 * V_264 ;
struct V_26 * V_27 ;
enum V_261 V_265 ;
int V_184 ;
static char * V_266 [] = {
[ V_267 ] = L_26 ,
[ V_240 ] = L_27 ,
[ V_237 ] = L_28 ,
} ;
V_265 = V_33 -> V_236 ;
V_262 = F_130 ( V_265 , V_262 ) ;
F_25 () ;
F_109 (&connection->peer_devices, peer_device, vnr) {
struct V_9 * V_10 = V_27 -> V_10 ;
if ( ! F_131 ( V_10 , V_268 ) )
continue;
V_264 = F_26 ( V_10 -> V_238 -> V_263 ) ;
if ( V_262 == V_237 && ! V_264 -> V_269 )
V_262 = V_240 ;
if ( V_262 == V_240 && ! V_264 -> V_270 )
V_262 = V_267 ;
F_124 ( V_10 ) ;
}
F_27 () ;
V_33 -> V_236 = V_262 ;
if ( V_265 != V_33 -> V_236 || V_262 == V_237 )
F_60 ( V_33 , L_29 , V_266 [ V_33 -> V_236 ] ) ;
}
int F_132 ( struct V_9 * V_10 ,
struct V_18 * V_19 ,
const unsigned V_271 , const int V_272 )
{
struct V_273 * V_274 = NULL ;
struct V_273 * V_273 ;
struct V_1 * V_1 = V_19 -> V_61 ;
T_3 V_46 = V_19 -> V_6 . V_46 ;
unsigned V_275 = V_19 -> V_6 . V_58 ;
unsigned V_276 = 0 ;
unsigned V_49 = ( V_275 + V_43 - 1 ) >> V_50 ;
int V_70 = - V_277 ;
V_278:
V_273 = F_133 ( V_206 , V_49 ) ;
if ( ! V_273 ) {
F_41 ( V_10 , L_30 ) ;
goto V_57;
}
V_273 -> V_279 . V_280 = V_46 ;
V_273 -> V_281 = V_10 -> V_238 -> V_239 ;
V_273 -> V_282 = V_271 ;
V_273 -> V_283 = V_19 ;
V_273 -> V_284 = V_285 ;
V_273 -> V_286 = V_274 ;
V_274 = V_273 ;
++ V_276 ;
F_134 (page) {
unsigned V_5 = F_69 ( unsigned , V_275 , V_43 ) ;
if ( ! F_135 ( V_273 , V_1 , V_5 , 0 ) ) {
if ( V_273 -> V_287 == 0 ) {
F_41 ( V_10 ,
L_31
L_32 ,
V_5 , ( V_288 ) V_273 -> V_279 . V_280 ) ;
V_70 = - V_289 ;
goto V_57;
}
goto V_278;
}
V_275 -= V_5 ;
V_46 += V_5 >> 9 ;
-- V_49 ;
}
F_47 ( V_10 , V_1 == NULL ) ;
F_47 ( V_10 , V_275 == 0 ) ;
F_43 ( & V_19 -> V_62 , V_276 ) ;
do {
V_273 = V_274 ;
V_274 = V_274 -> V_286 ;
V_273 -> V_286 = NULL ;
F_136 ( V_10 , V_272 , V_273 ) ;
} while ( V_274 );
return 0 ;
V_57:
while ( V_274 ) {
V_273 = V_274 ;
V_274 = V_274 -> V_286 ;
F_137 ( V_273 ) ;
}
return V_70 ;
}
static void F_138 ( struct V_9 * V_10 ,
struct V_18 * V_19 )
{
struct V_290 * V_6 = & V_19 -> V_6 ;
F_139 ( & V_10 -> V_291 , V_6 ) ;
F_42 ( V_6 ) ;
if ( V_6 -> V_59 )
F_37 ( & V_10 -> V_292 ) ;
}
static void F_140 ( struct V_88 * V_33 )
{
struct V_26 * V_27 ;
int V_184 ;
F_25 () ;
F_109 (&connection->peer_devices, peer_device, vnr) {
struct V_9 * V_10 = V_27 -> V_10 ;
F_110 ( & V_10 -> V_216 ) ;
F_27 () ;
F_56 ( V_10 , & V_10 -> V_293 ) ;
F_113 ( & V_10 -> V_216 , V_218 ) ;
F_25 () ;
}
F_27 () ;
}
static struct V_26 *
F_141 ( struct V_88 * V_33 , int V_294 )
{
return F_142 ( & V_33 -> V_295 , V_294 ) ;
}
static int F_143 ( struct V_88 * V_33 , struct V_165 * V_166 )
{
int V_89 ;
struct V_296 * V_297 = V_166 -> V_90 ;
struct V_242 * V_60 ;
V_33 -> V_256 -> V_255 = V_297 -> V_298 ;
V_33 -> V_256 -> V_33 = V_33 ;
V_89 = F_125 ( V_33 , V_33 -> V_256 , V_252 ) ;
switch ( V_33 -> V_236 ) {
case V_267 :
if ( V_89 == V_260 )
return 0 ;
V_60 = F_144 ( sizeof( struct V_242 ) , V_206 ) ;
if ( V_60 )
break;
else
F_31 ( V_33 , L_33 ) ;
case V_237 :
case V_240 :
F_140 ( V_33 ) ;
F_120 ( V_33 ) ;
if ( F_28 ( & V_33 -> V_256 -> V_245 ) ) {
V_60 = F_144 ( sizeof( struct V_242 ) , V_206 ) ;
if ( V_60 )
break;
}
return 0 ;
default:
F_41 ( V_33 , L_34 , V_33 -> V_236 ) ;
return - V_103 ;
}
V_60 -> V_63 = 0 ;
F_43 ( & V_60 -> V_245 , 0 ) ;
F_43 ( & V_60 -> V_251 , 0 ) ;
F_11 ( & V_33 -> V_248 ) ;
if ( F_28 ( & V_33 -> V_256 -> V_245 ) ) {
F_145 ( & V_60 -> V_21 , & V_33 -> V_256 -> V_21 ) ;
V_33 -> V_256 = V_60 ;
V_33 -> V_258 ++ ;
} else {
F_46 ( V_60 ) ;
}
F_12 ( & V_33 -> V_248 ) ;
return 0 ;
}
static struct V_18 *
F_146 ( struct V_26 * V_27 , T_2 V_45 , T_3 V_46 ,
int V_47 ) __must_hold( T_5 )
{
struct V_9 * V_10 = V_27 -> V_10 ;
const T_3 V_299 = F_147 ( V_10 -> V_300 ) ;
struct V_18 * V_19 ;
struct V_1 * V_1 ;
int V_301 , V_275 , V_70 ;
void * V_302 = V_27 -> V_33 -> V_303 ;
void * V_304 = V_27 -> V_33 -> V_305 ;
unsigned long * V_90 ;
V_301 = 0 ;
if ( V_27 -> V_33 -> V_306 ) {
V_301 = F_148 ( V_27 -> V_33 -> V_306 ) ;
V_70 = F_66 ( V_27 -> V_33 , V_302 , V_301 ) ;
if ( V_70 )
return NULL ;
V_47 -= V_301 ;
}
if ( ! F_149 ( F_150 ( V_47 , 512 ) ) )
return NULL ;
if ( ! F_149 ( V_47 <= V_42 ) )
return NULL ;
if ( V_46 + ( V_47 >> 9 ) > V_299 ) {
F_41 ( V_10 , L_35
L_36 ,
( unsigned long long ) V_299 ,
( unsigned long long ) V_46 , V_47 ) ;
return NULL ;
}
V_19 = F_38 ( V_27 , V_45 , V_46 , V_47 , V_206 ) ;
if ( ! V_19 )
return NULL ;
if ( ! V_47 )
return V_19 ;
V_275 = V_47 ;
V_1 = V_19 -> V_61 ;
F_134 (page) {
unsigned V_5 = F_69 ( int , V_275 , V_43 ) ;
V_90 = F_151 ( V_1 ) ;
V_70 = F_66 ( V_27 -> V_33 , V_90 , V_5 ) ;
if ( F_39 ( V_10 , V_307 ) ) {
F_41 ( V_10 , L_37 ) ;
V_90 [ 0 ] = V_90 [ 0 ] ^ ( unsigned long ) - 1 ;
}
F_152 ( V_1 ) ;
if ( V_70 ) {
F_52 ( V_10 , V_19 ) ;
return NULL ;
}
V_275 -= V_5 ;
}
if ( V_301 ) {
F_153 ( V_27 -> V_33 -> V_306 , V_19 , V_304 ) ;
if ( memcmp ( V_302 , V_304 , V_301 ) ) {
F_41 ( V_10 , L_38 ,
( unsigned long long ) V_46 , V_47 ) ;
F_52 ( V_10 , V_19 ) ;
return NULL ;
}
}
V_10 -> V_308 += V_47 >> 9 ;
return V_19 ;
}
static int F_154 ( struct V_26 * V_27 , int V_47 )
{
struct V_1 * V_1 ;
int V_70 = 0 ;
void * V_90 ;
if ( ! V_47 )
return 0 ;
V_1 = F_23 ( V_27 , 1 , 1 ) ;
V_90 = F_151 ( V_1 ) ;
while ( V_47 ) {
unsigned int V_5 = F_69 ( int , V_47 , V_43 ) ;
V_70 = F_66 ( V_27 -> V_33 , V_90 , V_5 ) ;
if ( V_70 )
break;
V_47 -= V_5 ;
}
F_152 ( V_1 ) ;
F_35 ( V_27 -> V_10 , V_1 , 0 ) ;
return V_70 ;
}
static int F_155 ( struct V_26 * V_27 , struct V_309 * V_310 ,
T_3 V_46 , int V_47 )
{
struct V_311 V_312 ;
struct V_313 V_314 ;
struct V_273 * V_273 ;
int V_301 , V_70 , F_149 ;
void * V_302 = V_27 -> V_33 -> V_303 ;
void * V_304 = V_27 -> V_33 -> V_305 ;
V_301 = 0 ;
if ( V_27 -> V_33 -> V_306 ) {
V_301 = F_148 ( V_27 -> V_33 -> V_306 ) ;
V_70 = F_66 ( V_27 -> V_33 , V_302 , V_301 ) ;
if ( V_70 )
return V_70 ;
V_47 -= V_301 ;
}
V_27 -> V_10 -> V_308 += V_47 >> 9 ;
V_273 = V_310 -> V_315 ;
F_47 ( V_27 -> V_10 , V_46 == V_273 -> V_279 . V_280 ) ;
F_156 (bvec, bio, iter) {
void * V_316 = F_151 ( V_312 . V_317 ) + V_312 . V_318 ;
F_149 = F_69 ( int , V_47 , V_312 . V_319 ) ;
V_70 = F_66 ( V_27 -> V_33 , V_316 , F_149 ) ;
F_152 ( V_312 . V_317 ) ;
if ( V_70 )
return V_70 ;
V_47 -= F_149 ;
}
if ( V_301 ) {
F_157 ( V_27 -> V_33 -> V_306 , V_273 , V_304 ) ;
if ( memcmp ( V_302 , V_304 , V_301 ) ) {
F_41 ( V_27 , L_39 ) ;
return - V_226 ;
}
}
F_47 ( V_27 -> V_10 , V_47 == 0 ) ;
return 0 ;
}
static int F_158 ( struct V_320 * V_20 , int V_321 )
{
struct V_18 * V_19 =
F_159 ( V_20 , struct V_18 , V_20 ) ;
struct V_26 * V_27 = V_19 -> V_27 ;
struct V_9 * V_10 = V_27 -> V_10 ;
T_3 V_46 = V_19 -> V_6 . V_46 ;
int V_70 ;
F_47 ( V_10 , F_48 ( & V_19 -> V_6 ) ) ;
if ( F_160 ( ( V_19 -> V_63 & V_322 ) == 0 ) ) {
F_161 ( V_10 , V_46 , V_19 -> V_6 . V_58 ) ;
V_70 = F_162 ( V_27 , V_323 , V_19 ) ;
} else {
F_163 ( V_10 , V_46 , V_19 -> V_6 . V_58 ) ;
V_70 = F_162 ( V_27 , V_324 , V_19 ) ;
}
F_164 ( V_10 ) ;
return V_70 ;
}
static int F_165 ( struct V_26 * V_27 , T_3 V_46 ,
int V_47 ) __releases( T_5 )
{
struct V_9 * V_10 = V_27 -> V_10 ;
struct V_18 * V_19 ;
V_19 = F_146 ( V_27 , V_325 , V_46 , V_47 ) ;
if ( ! V_19 )
goto V_57;
F_166 ( V_10 ) ;
F_167 ( V_10 ) ;
V_19 -> V_20 . V_73 = F_158 ;
F_20 ( & V_10 -> V_24 -> V_25 ) ;
F_145 ( & V_19 -> V_20 . V_21 , & V_10 -> V_326 ) ;
F_21 ( & V_10 -> V_24 -> V_25 ) ;
F_34 ( V_47 >> 9 , & V_10 -> V_327 ) ;
if ( F_132 ( V_10 , V_19 , V_328 , V_329 ) == 0 )
return 0 ;
F_41 ( V_10 , L_40 ) ;
F_20 ( & V_10 -> V_24 -> V_25 ) ;
F_129 ( & V_19 -> V_20 . V_21 ) ;
F_21 ( & V_10 -> V_24 -> V_25 ) ;
F_52 ( V_10 , V_19 ) ;
V_57:
F_124 ( V_10 ) ;
return - V_103 ;
}
static struct V_309 *
F_168 ( struct V_9 * V_10 , struct V_330 * V_331 , T_2 V_45 ,
T_3 V_46 , bool V_332 , const char * V_333 )
{
struct V_309 * V_310 ;
V_310 = (struct V_309 * ) ( unsigned long ) V_45 ;
if ( F_169 ( V_331 , V_46 , & V_310 -> V_6 ) && V_310 -> V_6 . T_5 )
return V_310 ;
if ( ! V_332 ) {
F_41 ( V_10 , L_41 , V_333 ,
( unsigned long ) V_45 , ( unsigned long long ) V_46 ) ;
}
return NULL ;
}
static int F_170 ( struct V_88 * V_33 , struct V_165 * V_166 )
{
struct V_26 * V_27 ;
struct V_9 * V_10 ;
struct V_309 * V_310 ;
T_3 V_46 ;
int V_70 ;
struct V_334 * V_297 = V_166 -> V_90 ;
V_27 = F_141 ( V_33 , V_166 -> V_184 ) ;
if ( ! V_27 )
return - V_103 ;
V_10 = V_27 -> V_10 ;
V_46 = F_171 ( V_297 -> V_46 ) ;
F_20 ( & V_10 -> V_24 -> V_25 ) ;
V_310 = F_168 ( V_10 , & V_10 -> V_335 , V_297 -> V_64 , V_46 , false , V_55 ) ;
F_21 ( & V_10 -> V_24 -> V_25 ) ;
if ( F_172 ( ! V_310 ) )
return - V_103 ;
V_70 = F_155 ( V_27 , V_310 , V_46 , V_166 -> V_58 ) ;
if ( ! V_70 )
F_173 ( V_310 , V_336 ) ;
return V_70 ;
}
static int F_174 ( struct V_88 * V_33 , struct V_165 * V_166 )
{
struct V_26 * V_27 ;
struct V_9 * V_10 ;
T_3 V_46 ;
int V_70 ;
struct V_334 * V_297 = V_166 -> V_90 ;
V_27 = F_141 ( V_33 , V_166 -> V_184 ) ;
if ( ! V_27 )
return - V_103 ;
V_10 = V_27 -> V_10 ;
V_46 = F_171 ( V_297 -> V_46 ) ;
F_47 ( V_10 , V_297 -> V_64 == V_325 ) ;
if ( F_121 ( V_10 ) ) {
V_70 = F_165 ( V_27 , V_46 , V_166 -> V_58 ) ;
} else {
if ( F_175 ( & V_337 ) )
F_41 ( V_10 , L_42 ) ;
V_70 = F_154 ( V_27 , V_166 -> V_58 ) ;
F_176 ( V_27 , V_324 , V_297 , V_166 -> V_58 ) ;
}
F_34 ( V_166 -> V_58 >> 9 , & V_10 -> V_338 ) ;
return V_70 ;
}
static void F_177 ( struct V_9 * V_10 ,
T_3 V_46 , int V_58 )
{
struct V_290 * V_6 ;
struct V_309 * V_310 ;
F_178 (i, &device->write_requests, sector, size) {
if ( ! V_6 -> T_5 )
continue;
V_310 = F_159 ( V_6 , struct V_309 , V_6 ) ;
if ( V_310 -> V_339 & V_340 ||
! ( V_310 -> V_339 & V_341 ) )
continue;
F_179 ( V_310 , V_342 , NULL ) ;
}
}
static int F_180 ( struct V_320 * V_20 , int V_343 )
{
struct V_18 * V_19 =
F_159 ( V_20 , struct V_18 , V_20 ) ;
struct V_26 * V_27 = V_19 -> V_27 ;
struct V_9 * V_10 = V_27 -> V_10 ;
T_3 V_46 = V_19 -> V_6 . V_46 ;
int V_70 = 0 , V_344 ;
if ( V_19 -> V_63 & V_345 ) {
if ( F_160 ( ( V_19 -> V_63 & V_322 ) == 0 ) ) {
V_344 = ( V_10 -> V_346 . V_100 >= V_347 &&
V_10 -> V_346 . V_100 <= V_348 &&
V_19 -> V_63 & V_349 ) ?
V_323 : V_350 ;
V_70 = F_162 ( V_27 , V_344 , V_19 ) ;
if ( V_344 == V_323 )
F_161 ( V_10 , V_46 , V_19 -> V_6 . V_58 ) ;
} else {
V_70 = F_162 ( V_27 , V_324 , V_19 ) ;
}
F_164 ( V_10 ) ;
}
if ( V_19 -> V_63 & V_351 ) {
F_20 ( & V_10 -> V_24 -> V_25 ) ;
F_47 ( V_10 , ! F_48 ( & V_19 -> V_6 ) ) ;
F_138 ( V_10 , V_19 ) ;
if ( V_19 -> V_63 & V_352 )
F_177 ( V_10 , V_46 , V_19 -> V_6 . V_58 ) ;
F_21 ( & V_10 -> V_24 -> V_25 ) ;
} else
F_47 ( V_10 , F_48 ( & V_19 -> V_6 ) ) ;
F_125 ( F_181 ( V_10 ) -> V_33 , V_19 -> V_60 , V_250 + ( V_343 ? V_249 : 0 ) ) ;
return V_70 ;
}
static int F_182 ( struct V_320 * V_20 , enum V_162 V_353 )
{
struct V_18 * V_19 =
F_159 ( V_20 , struct V_18 , V_20 ) ;
struct V_26 * V_27 = V_19 -> V_27 ;
int V_70 ;
V_70 = F_162 ( V_27 , V_353 , V_19 ) ;
F_164 ( V_27 -> V_10 ) ;
return V_70 ;
}
static int F_183 ( struct V_320 * V_20 , int V_321 )
{
return F_182 ( V_20 , V_354 ) ;
}
static int F_184 ( struct V_320 * V_20 , int V_321 )
{
struct V_18 * V_19 =
F_159 ( V_20 , struct V_18 , V_20 ) ;
struct V_88 * V_33 = V_19 -> V_27 -> V_33 ;
return F_182 ( V_20 , V_33 -> V_175 >= 100 ?
V_355 : V_354 ) ;
}
static bool F_185 ( T_7 V_40 , T_7 V_356 )
{
return ( V_357 ) V_40 - ( V_357 ) V_356 > 0 ;
}
static T_7 F_186 ( T_7 V_40 , T_7 V_356 )
{
return F_185 ( V_40 , V_356 ) ? V_40 : V_356 ;
}
static void F_187 ( struct V_26 * V_27 , unsigned int V_173 )
{
struct V_9 * V_10 = V_27 -> V_10 ;
unsigned int V_358 ;
if ( F_61 ( V_198 , & V_27 -> V_33 -> V_63 ) ) {
F_11 ( & V_10 -> V_359 ) ;
V_358 = F_186 ( V_10 -> V_173 , V_173 ) ;
V_10 -> V_173 = V_358 ;
F_12 ( & V_10 -> V_359 ) ;
if ( V_173 == V_358 )
F_37 ( & V_10 -> V_360 ) ;
}
}
static inline int F_188 ( T_3 V_361 , int V_362 , T_3 V_363 , int V_364 )
{
return ! ( ( V_361 + ( V_362 >> 9 ) <= V_363 ) || ( V_361 >= V_363 + ( V_364 >> 9 ) ) ) ;
}
static bool F_189 ( struct V_9 * V_10 , struct V_18 * V_19 )
{
struct V_18 * V_365 ;
bool V_89 = 0 ;
F_20 ( & V_10 -> V_24 -> V_25 ) ;
F_190 (rs_req, &device->sync_ee, w.list) {
if ( F_188 ( V_19 -> V_6 . V_46 , V_19 -> V_6 . V_58 ,
V_365 -> V_6 . V_46 , V_365 -> V_6 . V_58 ) ) {
V_89 = 1 ;
break;
}
}
F_21 ( & V_10 -> V_24 -> V_25 ) ;
return V_89 ;
}
static int F_191 ( struct V_26 * V_27 , const T_7 V_173 )
{
struct V_9 * V_10 = V_27 -> V_10 ;
F_24 ( V_31 ) ;
long V_185 ;
int V_366 = 0 , V_367 ;
if ( ! F_61 ( V_198 , & V_27 -> V_33 -> V_63 ) )
return 0 ;
F_11 ( & V_10 -> V_359 ) ;
for (; ; ) {
if ( ! F_185 ( V_173 - 1 , V_10 -> V_173 ) ) {
V_10 -> V_173 = F_186 ( V_10 -> V_173 , V_173 ) ;
break;
}
if ( F_30 ( V_38 ) ) {
V_366 = - V_92 ;
break;
}
F_25 () ;
V_367 = F_26 ( F_181 ( V_10 ) -> V_33 -> V_29 ) -> V_368 ;
F_27 () ;
if ( ! V_367 )
break;
F_29 ( & V_10 -> V_360 , & V_31 , V_37 ) ;
F_12 ( & V_10 -> V_359 ) ;
F_25 () ;
V_185 = F_26 ( V_27 -> V_33 -> V_29 ) -> V_94 * V_95 / 10 ;
F_27 () ;
V_185 = F_192 ( V_185 ) ;
F_11 ( & V_10 -> V_359 ) ;
if ( ! V_185 ) {
V_366 = - V_137 ;
F_41 ( V_10 , L_43 ) ;
break;
}
}
F_12 ( & V_10 -> V_359 ) ;
F_33 ( & V_10 -> V_360 , & V_31 ) ;
return V_366 ;
}
static unsigned long F_193 ( T_7 V_369 )
{
return ( V_369 & V_370 ? V_371 : 0 ) |
( V_369 & V_372 ? V_373 : 0 ) |
( V_369 & V_374 ? V_375 : 0 ) |
( V_369 & V_376 ? V_377 : 0 ) ;
}
static void F_194 ( struct V_9 * V_10 , T_3 V_46 ,
unsigned int V_58 )
{
struct V_290 * V_6 ;
V_378:
F_178 (i, &device->write_requests, sector, size) {
struct V_309 * V_310 ;
struct V_379 V_380 ;
if ( ! V_6 -> T_5 )
continue;
V_310 = F_159 ( V_6 , struct V_309 , V_6 ) ;
if ( ! ( V_310 -> V_339 & V_341 ) )
continue;
V_310 -> V_339 &= ~ V_341 ;
F_179 ( V_310 , V_381 , & V_380 ) ;
F_21 ( & V_10 -> V_24 -> V_25 ) ;
if ( V_380 . V_273 )
F_195 ( V_10 , & V_380 ) ;
F_20 ( & V_10 -> V_24 -> V_25 ) ;
goto V_378;
}
}
static int F_196 ( struct V_9 * V_10 ,
struct V_18 * V_19 )
{
struct V_88 * V_33 = V_19 -> V_27 -> V_33 ;
bool V_382 = F_61 ( V_198 , & V_33 -> V_63 ) ;
T_3 V_46 = V_19 -> V_6 . V_46 ;
const unsigned int V_58 = V_19 -> V_6 . V_58 ;
struct V_290 * V_6 ;
bool V_383 ;
int V_70 ;
F_197 ( & V_10 -> V_291 , & V_19 -> V_6 ) ;
V_378:
F_178 (i, &device->write_requests, sector, size) {
if ( V_6 == & V_19 -> V_6 )
continue;
if ( ! V_6 -> T_5 ) {
V_70 = F_198 ( V_10 , V_6 ) ;
if ( V_70 )
goto V_99;
goto V_378;
}
V_383 = V_6 -> V_46 == V_46 && V_6 -> V_58 == V_58 ;
if ( V_382 ) {
bool V_384 = V_6 -> V_46 <= V_46 && V_6 -> V_46 +
( V_6 -> V_58 >> 9 ) >= V_46 + ( V_58 >> 9 ) ;
if ( ! V_383 )
F_199 ( V_10 , L_44
L_45
L_46 ,
( unsigned long long ) V_6 -> V_46 , V_6 -> V_58 ,
( unsigned long long ) V_46 , V_58 ,
V_384 ? L_47 : L_48 ) ;
F_167 ( V_10 ) ;
V_19 -> V_20 . V_73 = V_384 ? F_183 :
F_184 ;
F_200 ( & V_19 -> V_20 . V_21 , & V_10 -> V_71 ) ;
F_201 ( V_33 ) ;
V_70 = - V_385 ;
goto V_99;
} else {
struct V_309 * V_310 =
F_159 ( V_6 , struct V_309 , V_6 ) ;
if ( ! V_383 )
F_199 ( V_10 , L_44
L_49 ,
( unsigned long long ) V_6 -> V_46 , V_6 -> V_58 ,
( unsigned long long ) V_46 , V_58 ) ;
if ( V_310 -> V_339 & V_340 ||
! ( V_310 -> V_339 & V_341 ) ) {
V_70 = F_198 ( V_10 , & V_310 -> V_6 ) ;
if ( V_70 ) {
F_202 ( V_33 , F_64 ( V_100 , V_386 ) , V_102 ) ;
F_194 ( V_10 , V_46 , V_58 ) ;
goto V_99;
}
goto V_378;
}
V_19 -> V_63 |= V_352 ;
}
}
V_70 = 0 ;
V_99:
if ( V_70 )
F_138 ( V_10 , V_19 ) ;
return V_70 ;
}
static int F_203 ( struct V_88 * V_33 , struct V_165 * V_166 )
{
struct V_26 * V_27 ;
struct V_9 * V_10 ;
T_3 V_46 ;
struct V_18 * V_19 ;
struct V_334 * V_297 = V_166 -> V_90 ;
T_7 V_173 = F_117 ( V_297 -> V_387 ) ;
int V_271 = V_328 ;
T_7 V_388 ;
int V_70 , V_367 ;
V_27 = F_141 ( V_33 , V_166 -> V_184 ) ;
if ( ! V_27 )
return - V_103 ;
V_10 = V_27 -> V_10 ;
if ( ! F_121 ( V_10 ) ) {
int V_72 ;
V_70 = F_191 ( V_27 , V_173 ) ;
F_176 ( V_27 , V_324 , V_297 , V_166 -> V_58 ) ;
F_204 ( & V_33 -> V_256 -> V_245 ) ;
V_72 = F_154 ( V_27 , V_166 -> V_58 ) ;
if ( ! V_70 )
V_70 = V_72 ;
return V_70 ;
}
V_46 = F_171 ( V_297 -> V_46 ) ;
V_19 = F_146 ( V_27 , V_297 -> V_64 , V_46 , V_166 -> V_58 ) ;
if ( ! V_19 ) {
F_124 ( V_10 ) ;
return - V_103 ;
}
V_19 -> V_20 . V_73 = F_180 ;
V_388 = F_117 ( V_297 -> V_388 ) ;
V_271 |= F_193 ( V_388 ) ;
if ( V_19 -> V_61 == NULL ) {
F_47 ( V_10 , V_19 -> V_6 . V_58 == 0 ) ;
F_47 ( V_10 , V_388 & V_374 ) ;
}
if ( V_388 & V_389 )
V_19 -> V_63 |= V_349 ;
F_11 ( & V_33 -> V_248 ) ;
V_19 -> V_60 = V_33 -> V_256 ;
F_204 ( & V_19 -> V_60 -> V_245 ) ;
F_204 ( & V_19 -> V_60 -> V_251 ) ;
F_12 ( & V_33 -> V_248 ) ;
F_25 () ;
V_367 = F_26 ( V_27 -> V_33 -> V_29 ) -> V_368 ;
F_27 () ;
if ( V_367 ) {
V_19 -> V_63 |= V_351 ;
V_70 = F_191 ( V_27 , V_173 ) ;
if ( V_70 )
goto V_390;
F_20 ( & V_10 -> V_24 -> V_25 ) ;
V_70 = F_196 ( V_10 , V_19 ) ;
if ( V_70 ) {
F_21 ( & V_10 -> V_24 -> V_25 ) ;
if ( V_70 == - V_385 ) {
F_124 ( V_10 ) ;
return 0 ;
}
goto V_390;
}
} else {
F_187 ( V_27 , V_173 ) ;
F_20 ( & V_10 -> V_24 -> V_25 ) ;
}
F_145 ( & V_19 -> V_20 . V_21 , & V_10 -> V_293 ) ;
F_21 ( & V_10 -> V_24 -> V_25 ) ;
if ( V_10 -> V_346 . V_100 == V_391 )
F_205 ( V_10 -> V_74 , ! F_189 ( V_10 , V_19 ) ) ;
if ( V_27 -> V_33 -> V_175 < 100 ) {
F_25 () ;
switch ( F_26 ( V_27 -> V_33 -> V_29 ) -> V_392 ) {
case V_393 :
V_388 |= V_394 ;
break;
case V_395 :
V_388 |= V_396 ;
break;
}
F_27 () ;
}
if ( V_388 & V_394 ) {
V_19 -> V_63 |= V_345 ;
F_167 ( V_10 ) ;
}
if ( V_388 & V_396 ) {
F_162 ( F_181 ( V_10 ) , V_397 , V_19 ) ;
}
if ( V_10 -> V_346 . V_398 < V_399 ) {
F_206 ( V_10 , V_19 -> V_6 . V_46 , V_19 -> V_6 . V_58 ) ;
V_19 -> V_63 |= V_400 ;
V_19 -> V_63 &= ~ V_349 ;
F_207 ( V_10 , & V_19 -> V_6 , true ) ;
}
V_70 = F_132 ( V_10 , V_19 , V_271 , V_401 ) ;
if ( ! V_70 )
return 0 ;
F_41 ( V_10 , L_40 ) ;
F_20 ( & V_10 -> V_24 -> V_25 ) ;
F_129 ( & V_19 -> V_20 . V_21 ) ;
F_138 ( V_10 , V_19 ) ;
F_21 ( & V_10 -> V_24 -> V_25 ) ;
if ( V_19 -> V_63 & V_400 )
F_208 ( V_10 , & V_19 -> V_6 ) ;
V_390:
F_125 ( V_33 , V_19 -> V_60 , V_250 + V_249 ) ;
F_124 ( V_10 ) ;
F_52 ( V_10 , V_19 ) ;
return V_70 ;
}
int F_209 ( struct V_9 * V_10 , T_3 V_46 )
{
struct V_402 * V_403 = V_10 -> V_238 -> V_239 -> V_404 -> V_405 ;
unsigned long V_406 , V_407 , V_408 ;
struct V_409 * V_4 ;
int V_410 ;
int V_411 = 0 ;
unsigned int V_412 ;
F_25 () ;
V_412 = F_26 ( V_10 -> V_238 -> V_263 ) -> V_412 ;
F_27 () ;
if ( V_412 == 0 )
return 0 ;
F_20 ( & V_10 -> V_413 ) ;
V_4 = F_210 ( V_10 -> V_414 , F_211 ( V_46 ) ) ;
if ( V_4 ) {
struct V_415 * V_416 = F_212 ( V_4 , struct V_415 , V_417 ) ;
if ( F_61 ( V_418 , & V_416 -> V_63 ) ) {
F_21 ( & V_10 -> V_413 ) ;
return 0 ;
}
}
F_21 ( & V_10 -> V_413 ) ;
V_410 = ( int ) F_213 ( & V_403 -> V_419 , V_420 [ 0 ] ) +
( int ) F_213 ( & V_403 -> V_419 , V_420 [ 1 ] ) -
F_28 ( & V_10 -> V_327 ) ;
if ( ! V_10 -> V_421 || V_410 - V_10 -> V_421 > 64 ) {
unsigned long V_422 ;
int V_6 ;
V_10 -> V_421 = V_410 ;
V_6 = ( V_10 -> V_423 + V_424 - 1 ) % V_424 ;
if ( V_10 -> V_346 . V_100 == V_425 || V_10 -> V_346 . V_100 == V_426 )
V_422 = V_10 -> V_427 ;
else
V_422 = F_214 ( V_10 ) - V_10 -> V_428 ;
V_407 = ( ( long ) V_182 - ( long ) V_10 -> V_429 [ V_6 ] ) / V_95 ;
if ( ! V_407 )
V_407 ++ ;
V_406 = V_10 -> V_430 [ V_6 ] - V_422 ;
V_408 = F_215 ( V_406 / V_407 ) ;
if ( V_408 > V_412 )
V_411 = 1 ;
}
return V_411 ;
}
static int F_216 ( struct V_88 * V_33 , struct V_165 * V_166 )
{
struct V_26 * V_27 ;
struct V_9 * V_10 ;
T_3 V_46 ;
T_3 V_299 ;
struct V_18 * V_19 ;
struct V_431 * V_432 = NULL ;
int V_58 , V_433 ;
unsigned int V_272 ;
struct V_434 * V_297 = V_166 -> V_90 ;
V_27 = F_141 ( V_33 , V_166 -> V_184 ) ;
if ( ! V_27 )
return - V_103 ;
V_10 = V_27 -> V_10 ;
V_299 = F_147 ( V_10 -> V_300 ) ;
V_46 = F_171 ( V_297 -> V_46 ) ;
V_58 = F_117 ( V_297 -> V_435 ) ;
if ( V_58 <= 0 || ! F_150 ( V_58 , 512 ) || V_58 > V_42 ) {
F_41 ( V_10 , L_50 , __FILE__ , __LINE__ ,
( unsigned long long ) V_46 , V_58 ) ;
return - V_226 ;
}
if ( V_46 + ( V_58 >> 9 ) > V_299 ) {
F_41 ( V_10 , L_50 , __FILE__ , __LINE__ ,
( unsigned long long ) V_46 , V_58 ) ;
return - V_226 ;
}
if ( ! F_131 ( V_10 , V_436 ) ) {
V_433 = 1 ;
switch ( V_166 -> V_163 ) {
case V_437 :
F_217 ( V_27 , V_438 , V_297 ) ;
break;
case V_439 :
case V_440 :
case V_441 :
F_217 ( V_27 , V_442 , V_297 ) ;
break;
case V_443 :
V_433 = 0 ;
F_166 ( V_10 ) ;
F_218 ( V_27 , V_444 , V_46 , V_58 , V_445 ) ;
break;
default:
F_219 () ;
}
if ( V_433 && F_175 ( & V_337 ) )
F_41 ( V_10 , L_51
L_52 ) ;
return F_154 ( V_27 , V_166 -> V_58 ) ;
}
V_19 = F_38 ( V_27 , V_297 -> V_64 , V_46 , V_58 , V_206 ) ;
if ( ! V_19 ) {
F_124 ( V_10 ) ;
return - V_277 ;
}
switch ( V_166 -> V_163 ) {
case V_437 :
V_19 -> V_20 . V_73 = V_446 ;
V_272 = V_447 ;
goto V_448;
case V_439 :
V_19 -> V_20 . V_73 = V_449 ;
V_272 = V_450 ;
V_10 -> V_451 = F_220 ( V_46 ) ;
break;
case V_443 :
case V_440 :
V_272 = V_450 ;
V_432 = F_144 ( sizeof( * V_432 ) + V_166 -> V_58 , V_206 ) ;
if ( ! V_432 )
goto V_452;
V_432 -> V_453 = V_166 -> V_58 ;
V_432 -> V_66 = ( ( ( char * ) V_432 ) + sizeof( struct V_431 ) ) ;
V_19 -> V_66 = V_432 ;
V_19 -> V_63 |= V_65 ;
if ( F_65 ( V_27 -> V_33 , V_432 -> V_66 , V_166 -> V_58 ) )
goto V_452;
if ( V_166 -> V_163 == V_440 ) {
F_47 ( V_10 , V_27 -> V_33 -> V_175 >= 89 ) ;
V_19 -> V_20 . V_73 = V_454 ;
V_10 -> V_451 = F_220 ( V_46 ) ;
} else if ( V_166 -> V_163 == V_443 ) {
F_34 ( V_58 >> 9 , & V_10 -> V_338 ) ;
V_19 -> V_20 . V_73 = V_455 ;
F_166 ( V_10 ) ;
goto V_456;
}
break;
case V_441 :
if ( V_10 -> V_457 == ~ ( T_3 ) 0 &&
V_27 -> V_33 -> V_175 >= 90 ) {
unsigned long V_458 = V_182 ;
int V_6 ;
V_10 -> V_457 = V_46 ;
V_10 -> V_459 = V_46 ;
V_10 -> V_427 = F_221 ( V_10 ) - F_220 ( V_46 ) ;
V_10 -> V_460 = V_10 -> V_427 ;
for ( V_6 = 0 ; V_6 < V_424 ; V_6 ++ ) {
V_10 -> V_430 [ V_6 ] = V_10 -> V_427 ;
V_10 -> V_429 [ V_6 ] = V_458 ;
}
F_60 ( V_10 , L_53 ,
( unsigned long long ) V_46 ) ;
}
V_19 -> V_20 . V_73 = V_461 ;
V_272 = V_450 ;
break;
default:
F_219 () ;
}
if ( V_10 -> V_346 . V_462 != V_463 && F_209 ( V_10 , V_46 ) )
F_222 ( V_95 / 10 ) ;
if ( F_223 ( V_10 , V_46 ) )
goto V_452;
V_456:
F_34 ( V_58 >> 9 , & V_10 -> V_327 ) ;
V_448:
F_167 ( V_10 ) ;
F_20 ( & V_10 -> V_24 -> V_25 ) ;
F_200 ( & V_19 -> V_20 . V_21 , & V_10 -> V_464 ) ;
F_21 ( & V_10 -> V_24 -> V_25 ) ;
if ( F_132 ( V_10 , V_19 , V_465 , V_272 ) == 0 )
return 0 ;
F_41 ( V_10 , L_40 ) ;
F_20 ( & V_10 -> V_24 -> V_25 ) ;
F_129 ( & V_19 -> V_20 . V_21 ) ;
F_21 ( & V_10 -> V_24 -> V_25 ) ;
V_452:
F_124 ( V_10 ) ;
F_52 ( V_10 , V_19 ) ;
return - V_103 ;
}
static int F_224 ( struct V_26 * V_27 ) __must_hold( T_5 )
{
struct V_9 * V_10 = V_27 -> V_10 ;
int V_466 , V_462 , V_89 = - 100 ;
unsigned long V_467 , V_468 ;
enum V_469 V_470 ;
V_466 = V_10 -> V_238 -> V_471 . V_472 [ V_473 ] & 1 ;
V_462 = V_10 -> V_474 [ V_473 ] & 1 ;
V_468 = V_10 -> V_474 [ V_475 ] ;
V_467 = V_10 -> V_476 ;
F_25 () ;
V_470 = F_26 ( V_27 -> V_33 -> V_29 ) -> V_470 ;
F_27 () ;
switch ( V_470 ) {
case V_477 :
case V_478 :
case V_479 :
case V_480 :
F_41 ( V_10 , L_54 ) ;
break;
case V_481 :
break;
case V_482 :
if ( V_466 == 0 && V_462 == 1 ) {
V_89 = - 1 ;
break;
}
if ( V_466 == 1 && V_462 == 0 ) {
V_89 = 1 ;
break;
}
case V_483 :
if ( V_466 == 0 && V_462 == 1 ) {
V_89 = 1 ;
break;
}
if ( V_466 == 1 && V_462 == 0 ) {
V_89 = - 1 ;
break;
}
F_31 ( V_10 , L_55
L_56 ) ;
case V_484 :
if ( V_468 == 0 && V_467 == 0 ) {
V_89 = F_61 ( V_198 , & V_27 -> V_33 -> V_63 )
? - 1 : 1 ;
break;
} else {
if ( V_468 == 0 ) { V_89 = 1 ; break; }
if ( V_467 == 0 ) { V_89 = - 1 ; break; }
}
if ( V_470 == V_484 )
break;
case V_485 :
if ( V_467 < V_468 )
V_89 = - 1 ;
else if ( V_467 > V_468 )
V_89 = 1 ;
else
V_89 = F_61 ( V_198 , & V_27 -> V_33 -> V_63 )
? - 1 : 1 ;
break;
case V_486 :
V_89 = - 1 ;
break;
case V_487 :
V_89 = 1 ;
}
return V_89 ;
}
static int F_225 ( struct V_26 * V_27 ) __must_hold( T_5 )
{
struct V_9 * V_10 = V_27 -> V_10 ;
int V_488 , V_89 = - 100 ;
enum V_469 V_489 ;
F_25 () ;
V_489 = F_26 ( V_27 -> V_33 -> V_29 ) -> V_489 ;
F_27 () ;
switch ( V_489 ) {
case V_482 :
case V_483 :
case V_485 :
case V_486 :
case V_487 :
case V_484 :
F_41 ( V_10 , L_54 ) ;
break;
case V_481 :
break;
case V_477 :
V_488 = F_224 ( V_27 ) ;
if ( V_488 == - 1 && V_10 -> V_346 . V_490 == V_491 )
V_89 = V_488 ;
if ( V_488 == 1 && V_10 -> V_346 . V_490 == V_463 )
V_89 = V_488 ;
break;
case V_480 :
V_89 = F_224 ( V_27 ) ;
break;
case V_478 :
return V_10 -> V_346 . V_490 == V_463 ? 1 : - 1 ;
case V_479 :
V_488 = F_224 ( V_27 ) ;
if ( V_488 == - 1 && V_10 -> V_346 . V_490 == V_463 ) {
enum V_189 V_492 ;
V_492 = F_226 ( V_10 , V_191 , F_64 ( V_490 , V_491 ) ) ;
if ( V_492 != V_192 ) {
F_227 ( V_10 , L_57 ) ;
} else {
F_31 ( V_10 , L_58 ) ;
V_89 = V_488 ;
}
} else
V_89 = V_488 ;
}
return V_89 ;
}
static int F_228 ( struct V_26 * V_27 ) __must_hold( T_5 )
{
struct V_9 * V_10 = V_27 -> V_10 ;
int V_488 , V_89 = - 100 ;
enum V_469 V_493 ;
F_25 () ;
V_493 = F_26 ( V_27 -> V_33 -> V_29 ) -> V_493 ;
F_27 () ;
switch ( V_493 ) {
case V_482 :
case V_483 :
case V_485 :
case V_486 :
case V_487 :
case V_477 :
case V_478 :
case V_484 :
F_41 ( V_10 , L_54 ) ;
break;
case V_480 :
V_89 = F_224 ( V_27 ) ;
break;
case V_481 :
break;
case V_479 :
V_488 = F_224 ( V_27 ) ;
if ( V_488 == - 1 ) {
enum V_189 V_492 ;
V_492 = F_226 ( V_10 , V_191 , F_64 ( V_490 , V_491 ) ) ;
if ( V_492 != V_192 ) {
F_227 ( V_10 , L_57 ) ;
} else {
F_31 ( V_10 , L_58 ) ;
V_89 = V_488 ;
}
} else
V_89 = V_488 ;
}
return V_89 ;
}
static void F_229 ( struct V_9 * V_10 , char * V_494 , T_2 * V_472 ,
T_2 V_495 , T_2 V_63 )
{
if ( ! V_472 ) {
F_60 ( V_10 , L_59 , V_494 ) ;
return;
}
F_60 ( V_10 , L_60 ,
V_494 ,
( unsigned long long ) V_472 [ V_496 ] ,
( unsigned long long ) V_472 [ V_473 ] ,
( unsigned long long ) V_472 [ V_497 ] ,
( unsigned long long ) V_472 [ V_498 ] ,
( unsigned long long ) V_495 ,
( unsigned long long ) V_63 ) ;
}
static int F_230 ( struct V_9 * V_10 , int * V_499 ) __must_hold( T_5 )
{
T_2 V_466 , V_462 ;
int V_6 , V_500 ;
V_466 = V_10 -> V_238 -> V_471 . V_472 [ V_496 ] & ~ ( ( T_2 ) 1 ) ;
V_462 = V_10 -> V_474 [ V_496 ] & ~ ( ( T_2 ) 1 ) ;
* V_499 = 10 ;
if ( V_466 == V_501 && V_462 == V_501 )
return 0 ;
* V_499 = 20 ;
if ( ( V_466 == V_501 || V_466 == ( T_2 ) 0 ) &&
V_462 != V_501 )
return - 2 ;
* V_499 = 30 ;
if ( V_466 != V_501 &&
( V_462 == V_501 || V_462 == ( T_2 ) 0 ) )
return 2 ;
if ( V_466 == V_462 ) {
int V_502 , V_264 ;
if ( V_10 -> V_474 [ V_473 ] == ( T_2 ) 0 && V_10 -> V_238 -> V_471 . V_472 [ V_473 ] != ( T_2 ) 0 ) {
if ( F_181 ( V_10 ) -> V_33 -> V_175 < 91 )
return - 1091 ;
if ( ( V_10 -> V_238 -> V_471 . V_472 [ V_473 ] & ~ ( ( T_2 ) 1 ) ) == ( V_10 -> V_474 [ V_497 ] & ~ ( ( T_2 ) 1 ) ) &&
( V_10 -> V_238 -> V_471 . V_472 [ V_497 ] & ~ ( ( T_2 ) 1 ) ) == ( V_10 -> V_474 [ V_497 + 1 ] & ~ ( ( T_2 ) 1 ) ) ) {
F_60 ( V_10 , L_61 ) ;
F_231 ( V_10 ) ;
V_10 -> V_238 -> V_471 . V_472 [ V_497 ] = V_10 -> V_238 -> V_471 . V_472 [ V_473 ] ;
V_10 -> V_238 -> V_471 . V_472 [ V_473 ] = 0 ;
F_229 ( V_10 , L_62 , V_10 -> V_238 -> V_471 . V_472 ,
V_10 -> V_346 . V_403 >= V_503 ? F_214 ( V_10 ) : 0 , 0 ) ;
* V_499 = 34 ;
} else {
F_60 ( V_10 , L_63 ) ;
* V_499 = 36 ;
}
return 1 ;
}
if ( V_10 -> V_238 -> V_471 . V_472 [ V_473 ] == ( T_2 ) 0 && V_10 -> V_474 [ V_473 ] != ( T_2 ) 0 ) {
if ( F_181 ( V_10 ) -> V_33 -> V_175 < 91 )
return - 1091 ;
if ( ( V_10 -> V_238 -> V_471 . V_472 [ V_497 ] & ~ ( ( T_2 ) 1 ) ) == ( V_10 -> V_474 [ V_473 ] & ~ ( ( T_2 ) 1 ) ) &&
( V_10 -> V_238 -> V_471 . V_472 [ V_497 + 1 ] & ~ ( ( T_2 ) 1 ) ) == ( V_10 -> V_474 [ V_497 ] & ~ ( ( T_2 ) 1 ) ) ) {
F_60 ( V_10 , L_64 ) ;
V_10 -> V_474 [ V_497 + 1 ] = V_10 -> V_474 [ V_497 ] ;
V_10 -> V_474 [ V_497 ] = V_10 -> V_474 [ V_473 ] ;
V_10 -> V_474 [ V_473 ] = 0UL ;
F_229 ( V_10 , L_65 , V_10 -> V_474 , V_10 -> V_474 [ V_475 ] , V_10 -> V_474 [ V_504 ] ) ;
* V_499 = 35 ;
} else {
F_60 ( V_10 , L_66 ) ;
* V_499 = 37 ;
}
return - 1 ;
}
V_502 = ( F_61 ( V_505 , & V_10 -> V_63 ) ? 1 : 0 ) +
( V_10 -> V_474 [ V_504 ] & 2 ) ;
* V_499 = 40 ;
switch ( V_502 ) {
case 0 : return 0 ;
case 1 : return 1 ;
case 2 : return - 1 ;
case 3 :
V_264 = F_61 ( V_198 , & F_181 ( V_10 ) -> V_33 -> V_63 ) ;
return V_264 ? - 1 : 1 ;
}
}
* V_499 = 50 ;
V_462 = V_10 -> V_474 [ V_473 ] & ~ ( ( T_2 ) 1 ) ;
if ( V_466 == V_462 )
return - 1 ;
* V_499 = 51 ;
V_462 = V_10 -> V_474 [ V_497 ] & ~ ( ( T_2 ) 1 ) ;
if ( V_466 == V_462 ) {
if ( F_181 ( V_10 ) -> V_33 -> V_175 < 96 ?
( V_10 -> V_238 -> V_471 . V_472 [ V_497 ] & ~ ( ( T_2 ) 1 ) ) ==
( V_10 -> V_474 [ V_497 + 1 ] & ~ ( ( T_2 ) 1 ) ) :
V_462 + V_506 == ( V_10 -> V_474 [ V_473 ] & ~ ( ( T_2 ) 1 ) ) ) {
if ( F_181 ( V_10 ) -> V_33 -> V_175 < 91 )
return - 1091 ;
V_10 -> V_474 [ V_473 ] = V_10 -> V_474 [ V_497 ] ;
V_10 -> V_474 [ V_497 ] = V_10 -> V_474 [ V_497 + 1 ] ;
F_60 ( V_10 , L_67 ) ;
F_229 ( V_10 , L_65 , V_10 -> V_474 , V_10 -> V_474 [ V_475 ] , V_10 -> V_474 [ V_504 ] ) ;
return - 1 ;
}
}
* V_499 = 60 ;
V_466 = V_10 -> V_238 -> V_471 . V_472 [ V_496 ] & ~ ( ( T_2 ) 1 ) ;
for ( V_6 = V_497 ; V_6 <= V_498 ; V_6 ++ ) {
V_462 = V_10 -> V_474 [ V_6 ] & ~ ( ( T_2 ) 1 ) ;
if ( V_466 == V_462 )
return - 2 ;
}
* V_499 = 70 ;
V_466 = V_10 -> V_238 -> V_471 . V_472 [ V_473 ] & ~ ( ( T_2 ) 1 ) ;
V_462 = V_10 -> V_474 [ V_496 ] & ~ ( ( T_2 ) 1 ) ;
if ( V_466 == V_462 )
return 1 ;
* V_499 = 71 ;
V_466 = V_10 -> V_238 -> V_471 . V_472 [ V_497 ] & ~ ( ( T_2 ) 1 ) ;
if ( V_466 == V_462 ) {
if ( F_181 ( V_10 ) -> V_33 -> V_175 < 96 ?
( V_10 -> V_238 -> V_471 . V_472 [ V_497 + 1 ] & ~ ( ( T_2 ) 1 ) ) ==
( V_10 -> V_474 [ V_497 ] & ~ ( ( T_2 ) 1 ) ) :
V_466 + V_506 == ( V_10 -> V_238 -> V_471 . V_472 [ V_473 ] & ~ ( ( T_2 ) 1 ) ) ) {
if ( F_181 ( V_10 ) -> V_33 -> V_175 < 91 )
return - 1091 ;
F_232 ( V_10 , V_473 , V_10 -> V_238 -> V_471 . V_472 [ V_497 ] ) ;
F_232 ( V_10 , V_497 , V_10 -> V_238 -> V_471 . V_472 [ V_497 + 1 ] ) ;
F_60 ( V_10 , L_68 ) ;
F_229 ( V_10 , L_62 , V_10 -> V_238 -> V_471 . V_472 ,
V_10 -> V_346 . V_403 >= V_503 ? F_214 ( V_10 ) : 0 , 0 ) ;
return 1 ;
}
}
* V_499 = 80 ;
V_462 = V_10 -> V_474 [ V_496 ] & ~ ( ( T_2 ) 1 ) ;
for ( V_6 = V_497 ; V_6 <= V_498 ; V_6 ++ ) {
V_466 = V_10 -> V_238 -> V_471 . V_472 [ V_6 ] & ~ ( ( T_2 ) 1 ) ;
if ( V_466 == V_462 )
return 2 ;
}
* V_499 = 90 ;
V_466 = V_10 -> V_238 -> V_471 . V_472 [ V_473 ] & ~ ( ( T_2 ) 1 ) ;
V_462 = V_10 -> V_474 [ V_473 ] & ~ ( ( T_2 ) 1 ) ;
if ( V_466 == V_462 && V_466 != ( ( T_2 ) 0 ) )
return 100 ;
* V_499 = 100 ;
for ( V_6 = V_497 ; V_6 <= V_498 ; V_6 ++ ) {
V_466 = V_10 -> V_238 -> V_471 . V_472 [ V_6 ] & ~ ( ( T_2 ) 1 ) ;
for ( V_500 = V_497 ; V_500 <= V_498 ; V_500 ++ ) {
V_462 = V_10 -> V_474 [ V_500 ] & ~ ( ( T_2 ) 1 ) ;
if ( V_466 == V_462 )
return - 100 ;
}
}
return - 1000 ;
}
static enum V_507 F_233 ( struct V_26 * V_27 ,
enum V_508 V_509 ,
enum V_510 V_511 ) __must_hold( T_5 )
{
struct V_9 * V_10 = V_27 -> V_10 ;
enum V_507 V_89 = V_512 ;
enum V_510 V_513 ;
struct V_29 * V_30 ;
int V_488 , V_499 , V_514 , V_515 ;
V_513 = V_10 -> V_346 . V_403 ;
if ( V_513 == V_503 )
V_513 = V_10 -> V_516 . V_403 ;
F_60 ( V_10 , L_69 ) ;
F_20 ( & V_10 -> V_238 -> V_471 . V_517 ) ;
F_229 ( V_10 , L_62 , V_10 -> V_238 -> V_471 . V_472 , V_10 -> V_476 , 0 ) ;
F_229 ( V_10 , L_65 , V_10 -> V_474 ,
V_10 -> V_474 [ V_475 ] , V_10 -> V_474 [ V_504 ] ) ;
V_488 = F_230 ( V_10 , & V_499 ) ;
F_21 ( & V_10 -> V_238 -> V_471 . V_517 ) ;
F_60 ( V_10 , L_70 , V_488 , V_499 ) ;
if ( V_488 == - 1000 ) {
F_199 ( V_10 , L_71 ) ;
return V_512 ;
}
if ( V_488 < - 1000 ) {
F_199 ( V_10 , L_72 , - V_488 - 1000 ) ;
return V_512 ;
}
if ( ( V_513 == V_399 && V_511 > V_399 ) ||
( V_511 == V_399 && V_513 > V_399 ) ) {
int V_518 = ( V_488 == - 100 ) || abs ( V_488 ) == 2 ;
V_488 = V_513 > V_399 ? 1 : - 1 ;
if ( V_518 )
V_488 = V_488 * 2 ;
F_60 ( V_10 , L_73 ,
V_488 > 0 ? L_74 : L_75 ) ;
}
if ( abs ( V_488 ) == 100 )
F_227 ( V_10 , L_76 ) ;
F_25 () ;
V_30 = F_26 ( V_27 -> V_33 -> V_29 ) ;
if ( V_488 == 100 || ( V_488 == - 100 && V_30 -> V_519 ) ) {
int V_520 = ( V_10 -> V_346 . V_490 == V_463 )
+ ( V_509 == V_463 ) ;
int V_521 = ( V_488 == - 100 ) ;
switch ( V_520 ) {
case 0 :
V_488 = F_224 ( V_27 ) ;
break;
case 1 :
V_488 = F_225 ( V_27 ) ;
break;
case 2 :
V_488 = F_228 ( V_27 ) ;
break;
}
if ( abs ( V_488 ) < 100 ) {
F_31 ( V_10 , L_77
L_78 ,
V_520 , ( V_488 < 0 ) ? L_65 : L_79 ) ;
if ( V_521 ) {
F_31 ( V_10 , L_80
L_81 ) ;
V_488 = V_488 * 2 ;
}
}
}
if ( V_488 == - 100 ) {
if ( F_61 ( V_217 , & V_10 -> V_63 ) && ! ( V_10 -> V_474 [ V_504 ] & 1 ) )
V_488 = - 1 ;
if ( ! F_61 ( V_217 , & V_10 -> V_63 ) && ( V_10 -> V_474 [ V_504 ] & 1 ) )
V_488 = 1 ;
if ( abs ( V_488 ) < 100 )
F_31 ( V_10 , L_82
L_83 ,
( V_488 < 0 ) ? L_65 : L_79 ) ;
}
V_514 = V_30 -> V_514 ;
V_515 = V_30 -> V_515 ;
F_27 () ;
if ( V_488 == - 100 ) {
F_199 ( V_10 , L_84 ) ;
F_227 ( V_10 , L_85 ) ;
return V_512 ;
}
if ( V_488 > 0 && V_513 <= V_399 ) {
F_41 ( V_10 , L_86 ) ;
return V_512 ;
}
if ( V_488 < 0 &&
V_10 -> V_346 . V_490 == V_463 && V_10 -> V_346 . V_403 >= V_522 ) {
switch ( V_514 ) {
case V_479 :
F_227 ( V_10 , L_87 ) ;
case V_481 :
F_41 ( V_10 , L_88 ) ;
return V_512 ;
case V_480 :
F_31 ( V_10 , L_89
L_90 ) ;
}
}
if ( V_515 || F_61 ( V_523 , & V_27 -> V_33 -> V_63 ) ) {
if ( V_488 == 0 )
F_60 ( V_10 , L_91 ) ;
else
F_60 ( V_10 , L_92 ,
F_234 ( V_488 > 0 ? V_347 : V_391 ) ,
abs ( V_488 ) >= 2 ? L_93 : L_94 ) ;
return V_512 ;
}
if ( abs ( V_488 ) >= 2 ) {
F_60 ( V_10 , L_95 ) ;
if ( F_235 ( V_10 , & V_524 , L_96 ,
V_525 ) )
return V_512 ;
}
if ( V_488 > 0 ) {
V_89 = V_526 ;
} else if ( V_488 < 0 ) {
V_89 = V_527 ;
} else {
V_89 = V_528 ;
if ( F_214 ( V_10 ) ) {
F_60 ( V_10 , L_97 ,
F_214 ( V_10 ) ) ;
}
}
return V_89 ;
}
static enum V_469 F_236 ( enum V_469 V_462 )
{
if ( V_462 == V_487 )
return V_486 ;
if ( V_462 == V_486 )
return V_487 ;
return V_462 ;
}
static int F_237 ( struct V_88 * V_33 , struct V_165 * V_166 )
{
struct V_529 * V_297 = V_166 -> V_90 ;
enum V_469 V_530 , V_531 , V_532 ;
int V_533 , V_534 , V_535 , V_536 ;
struct V_29 * V_30 , * V_537 , * V_538 = NULL ;
char V_539 [ V_540 ] = L_98 ;
struct V_541 * V_306 = NULL ;
void * V_303 = NULL , * V_305 = NULL ;
V_533 = F_117 ( V_297 -> V_542 ) ;
V_530 = F_117 ( V_297 -> V_470 ) ;
V_531 = F_117 ( V_297 -> V_489 ) ;
V_532 = F_117 ( V_297 -> V_493 ) ;
V_535 = F_117 ( V_297 -> V_368 ) ;
V_536 = F_117 ( V_297 -> V_543 ) ;
V_534 = V_536 & V_544 ;
if ( V_33 -> V_175 >= 87 ) {
int V_70 ;
if ( V_166 -> V_58 > sizeof( V_539 ) )
return - V_103 ;
V_70 = F_65 ( V_33 , V_539 , V_166 -> V_58 ) ;
if ( V_70 )
return V_70 ;
V_539 [ V_540 - 1 ] = 0 ;
}
if ( V_166 -> V_163 != V_545 ) {
F_95 ( V_523 , & V_33 -> V_63 ) ;
if ( V_536 & V_546 )
F_101 ( V_523 , & V_33 -> V_63 ) ;
F_25 () ;
V_30 = F_26 ( V_33 -> V_29 ) ;
if ( V_533 != V_30 -> V_392 ) {
F_41 ( V_33 , L_99 , L_100 ) ;
goto V_547;
}
if ( F_236 ( V_530 ) != V_30 -> V_470 ) {
F_41 ( V_33 , L_99 , L_101 ) ;
goto V_547;
}
if ( F_236 ( V_531 ) != V_30 -> V_489 ) {
F_41 ( V_33 , L_99 , L_102 ) ;
goto V_547;
}
if ( F_236 ( V_532 ) != V_30 -> V_493 ) {
F_41 ( V_33 , L_99 , L_103 ) ;
goto V_547;
}
if ( V_534 && V_30 -> V_188 ) {
F_41 ( V_33 , L_99 , L_104 ) ;
goto V_547;
}
if ( V_535 != V_30 -> V_368 ) {
F_41 ( V_33 , L_99 , L_105 ) ;
goto V_547;
}
if ( strcmp ( V_539 , V_30 -> V_539 ) ) {
F_41 ( V_33 , L_99 , L_106 ) ;
goto V_547;
}
F_27 () ;
}
if ( V_539 [ 0 ] ) {
int V_548 ;
V_306 = F_238 ( V_539 , 0 , V_549 ) ;
if ( ! V_306 ) {
F_41 ( V_33 , L_107 ,
V_539 ) ;
goto V_550;
}
V_548 = F_148 ( V_306 ) ;
V_303 = F_144 ( V_548 , V_551 ) ;
V_305 = F_144 ( V_548 , V_551 ) ;
if ( ! ( V_303 && V_305 ) ) {
F_41 ( V_33 , L_108 ) ;
goto V_550;
}
}
V_538 = F_144 ( sizeof( struct V_29 ) , V_551 ) ;
if ( ! V_538 ) {
F_41 ( V_33 , L_109 ) ;
goto V_550;
}
F_111 ( & V_33 -> V_90 . V_193 ) ;
F_111 ( & V_33 -> V_24 -> V_220 ) ;
V_537 = V_33 -> V_29 ;
* V_538 = * V_537 ;
V_538 -> V_392 = V_533 ;
V_538 -> V_470 = F_236 ( V_530 ) ;
V_538 -> V_489 = F_236 ( V_531 ) ;
V_538 -> V_493 = F_236 ( V_532 ) ;
V_538 -> V_368 = V_535 ;
F_239 ( V_33 -> V_29 , V_538 ) ;
F_112 ( & V_33 -> V_24 -> V_220 ) ;
F_112 ( & V_33 -> V_90 . V_193 ) ;
F_240 ( V_33 -> V_306 ) ;
F_46 ( V_33 -> V_303 ) ;
F_46 ( V_33 -> V_305 ) ;
V_33 -> V_306 = V_306 ;
V_33 -> V_303 = V_303 ;
V_33 -> V_305 = V_305 ;
if ( strcmp ( V_537 -> V_539 , V_539 ) )
F_60 ( V_33 , L_110 ,
V_539 [ 0 ] ? V_539 : L_111 ) ;
F_241 () ;
F_46 ( V_537 ) ;
return 0 ;
V_547:
F_27 () ;
V_550:
F_240 ( V_306 ) ;
F_46 ( V_303 ) ;
F_46 ( V_305 ) ;
F_63 ( V_33 , F_64 ( V_100 , V_145 ) , V_102 ) ;
return - V_103 ;
}
static
struct V_541 * F_242 ( const struct V_9 * V_10 ,
const char * V_552 , const char * V_553 )
{
struct V_541 * V_554 ;
if ( ! V_552 [ 0 ] )
return NULL ;
V_554 = F_238 ( V_552 , 0 , V_549 ) ;
if ( F_243 ( V_554 ) ) {
F_41 ( V_10 , L_112 ,
V_552 , V_553 , F_244 ( V_554 ) ) ;
return V_554 ;
}
return V_554 ;
}
static int F_245 ( struct V_88 * V_33 , struct V_165 * V_166 )
{
void * V_235 = V_33 -> V_90 . V_167 ;
int V_58 = V_166 -> V_58 ;
while ( V_58 ) {
int V_196 = F_69 ( int , V_58 , V_555 ) ;
V_196 = F_59 ( V_33 , V_235 , V_196 ) ;
if ( V_196 <= 0 ) {
if ( V_196 < 0 )
return V_196 ;
break;
}
V_58 -= V_196 ;
}
if ( V_58 )
return - V_103 ;
return 0 ;
}
static int F_246 ( struct V_88 * V_33 , struct V_165 * V_166 )
{
F_31 ( V_33 , L_113 ,
F_247 ( V_166 -> V_163 ) , V_166 -> V_184 ) ;
return F_245 ( V_33 , V_166 ) ;
}
static int F_248 ( struct V_88 * V_33 , struct V_165 * V_166 )
{
struct V_26 * V_27 ;
struct V_9 * V_10 ;
struct V_556 * V_297 ;
unsigned int V_164 , V_47 , V_557 ;
struct V_541 * V_558 = NULL ;
struct V_541 * V_559 = NULL ;
struct V_29 * V_537 , * V_538 = NULL ;
struct V_263 * V_560 = NULL , * V_561 = NULL ;
const int V_562 = V_33 -> V_175 ;
struct V_563 * V_564 = NULL , * V_565 = NULL ;
int V_566 = 0 ;
int V_70 ;
V_27 = F_141 ( V_33 , V_166 -> V_184 ) ;
if ( ! V_27 )
return F_246 ( V_33 , V_166 ) ;
V_10 = V_27 -> V_10 ;
V_557 = V_562 <= 87 ? sizeof( struct V_567 )
: V_562 == 88 ? sizeof( struct V_567 )
+ V_540
: V_562 <= 94 ? sizeof( struct V_568 )
: sizeof( struct V_556 ) ;
if ( V_166 -> V_58 > V_557 ) {
F_41 ( V_10 , L_114 ,
V_166 -> V_58 , V_557 ) ;
return - V_103 ;
}
if ( V_562 <= 88 ) {
V_164 = sizeof( struct V_567 ) ;
V_47 = V_166 -> V_58 - V_164 ;
} else if ( V_562 <= 94 ) {
V_164 = sizeof( struct V_568 ) ;
V_47 = V_166 -> V_58 - V_164 ;
F_47 ( V_10 , V_47 == 0 ) ;
} else {
V_164 = sizeof( struct V_556 ) ;
V_47 = V_166 -> V_58 - V_164 ;
F_47 ( V_10 , V_47 == 0 ) ;
}
V_297 = V_166 -> V_90 ;
memset ( V_297 -> V_569 , 0 , 2 * V_540 ) ;
V_70 = F_65 ( V_27 -> V_33 , V_297 , V_164 ) ;
if ( V_70 )
return V_70 ;
F_111 ( & V_33 -> V_24 -> V_220 ) ;
V_537 = V_27 -> V_33 -> V_29 ;
if ( F_121 ( V_10 ) ) {
V_561 = F_249 ( sizeof( struct V_263 ) , V_551 ) ;
if ( ! V_561 ) {
F_124 ( V_10 ) ;
F_112 ( & V_33 -> V_24 -> V_220 ) ;
F_41 ( V_10 , L_115 ) ;
return - V_277 ;
}
V_560 = V_10 -> V_238 -> V_263 ;
* V_561 = * V_560 ;
V_561 -> V_570 = F_117 ( V_297 -> V_570 ) ;
}
if ( V_562 >= 88 ) {
if ( V_562 == 88 ) {
if ( V_47 > V_540 || V_47 == 0 ) {
F_41 ( V_10 , L_116
L_117 ,
V_47 , V_540 ) ;
V_70 = - V_103 ;
goto V_571;
}
V_70 = F_65 ( V_27 -> V_33 , V_297 -> V_569 , V_47 ) ;
if ( V_70 )
goto V_571;
F_47 ( V_10 , V_297 -> V_569 [ V_47 - 1 ] == 0 ) ;
V_297 -> V_569 [ V_47 - 1 ] = 0 ;
} else {
F_47 ( V_10 , V_297 -> V_569 [ V_540 - 1 ] == 0 ) ;
F_47 ( V_10 , V_297 -> V_572 [ V_540 - 1 ] == 0 ) ;
V_297 -> V_569 [ V_540 - 1 ] = 0 ;
V_297 -> V_572 [ V_540 - 1 ] = 0 ;
}
if ( strcmp ( V_537 -> V_569 , V_297 -> V_569 ) ) {
if ( V_10 -> V_346 . V_100 == V_98 ) {
F_41 ( V_10 , L_118 ,
V_537 -> V_569 , V_297 -> V_569 ) ;
goto V_550;
}
V_558 = F_242 ( V_10 ,
V_297 -> V_569 , L_119 ) ;
if ( F_243 ( V_558 ) ) {
V_558 = NULL ;
goto V_550;
}
}
if ( V_562 >= 89 && strcmp ( V_537 -> V_572 , V_297 -> V_572 ) ) {
if ( V_10 -> V_346 . V_100 == V_98 ) {
F_41 ( V_10 , L_120 ,
V_537 -> V_572 , V_297 -> V_572 ) ;
goto V_550;
}
V_559 = F_242 ( V_10 ,
V_297 -> V_572 , L_121 ) ;
if ( F_243 ( V_559 ) ) {
V_559 = NULL ;
goto V_550;
}
}
if ( V_562 > 94 && V_561 ) {
V_561 -> V_573 = F_117 ( V_297 -> V_573 ) ;
V_561 -> V_574 = F_117 ( V_297 -> V_574 ) ;
V_561 -> V_575 = F_117 ( V_297 -> V_575 ) ;
V_561 -> V_576 = F_117 ( V_297 -> V_576 ) ;
V_566 = ( V_561 -> V_573 * 10 * V_577 ) / V_95 ;
if ( V_566 != V_10 -> V_578 -> V_58 ) {
V_565 = F_250 ( V_566 ) ;
if ( ! V_565 ) {
F_41 ( V_10 , L_122 ) ;
F_124 ( V_10 ) ;
goto V_550;
}
}
}
if ( V_558 || V_559 ) {
V_538 = F_249 ( sizeof( struct V_29 ) , V_551 ) ;
if ( ! V_538 ) {
F_41 ( V_10 , L_109 ) ;
goto V_550;
}
* V_538 = * V_537 ;
if ( V_558 ) {
strcpy ( V_538 -> V_569 , V_297 -> V_569 ) ;
V_538 -> V_579 = strlen ( V_297 -> V_569 ) + 1 ;
F_240 ( V_27 -> V_33 -> V_558 ) ;
V_27 -> V_33 -> V_558 = V_558 ;
F_60 ( V_10 , L_123 , V_297 -> V_569 ) ;
}
if ( V_559 ) {
strcpy ( V_538 -> V_572 , V_297 -> V_572 ) ;
V_538 -> V_580 = strlen ( V_297 -> V_572 ) + 1 ;
F_240 ( V_27 -> V_33 -> V_559 ) ;
V_27 -> V_33 -> V_559 = V_559 ;
F_60 ( V_10 , L_124 , V_297 -> V_572 ) ;
}
F_239 ( V_33 -> V_29 , V_538 ) ;
}
}
if ( V_561 ) {
F_239 ( V_10 -> V_238 -> V_263 , V_561 ) ;
F_124 ( V_10 ) ;
}
if ( V_565 ) {
V_564 = V_10 -> V_578 ;
F_239 ( V_10 -> V_578 , V_565 ) ;
}
F_112 ( & V_33 -> V_24 -> V_220 ) ;
F_241 () ;
if ( V_538 )
F_46 ( V_537 ) ;
F_46 ( V_560 ) ;
F_46 ( V_564 ) ;
return 0 ;
V_571:
if ( V_561 ) {
F_124 ( V_10 ) ;
F_46 ( V_561 ) ;
}
F_112 ( & V_33 -> V_24 -> V_220 ) ;
return - V_103 ;
V_550:
F_46 ( V_565 ) ;
if ( V_561 ) {
F_124 ( V_10 ) ;
F_46 ( V_561 ) ;
}
F_112 ( & V_33 -> V_24 -> V_220 ) ;
F_240 ( V_559 ) ;
F_240 ( V_558 ) ;
F_63 ( V_27 -> V_33 , F_64 ( V_100 , V_145 ) , V_102 ) ;
return - V_103 ;
}
static void F_251 ( struct V_9 * V_10 ,
const char * V_196 , T_3 V_40 , T_3 V_356 )
{
T_3 V_581 ;
if ( V_40 == 0 || V_356 == 0 )
return;
V_581 = ( V_40 > V_356 ) ? ( V_40 - V_356 ) : ( V_356 - V_40 ) ;
if ( V_581 > ( V_40 >> 3 ) || V_581 > ( V_356 >> 3 ) )
F_31 ( V_10 , L_125 , V_196 ,
( unsigned long long ) V_40 , ( unsigned long long ) V_356 ) ;
}
static int F_252 ( struct V_88 * V_33 , struct V_165 * V_166 )
{
struct V_26 * V_27 ;
struct V_9 * V_10 ;
struct V_582 * V_297 = V_166 -> V_90 ;
enum V_583 V_584 = V_585 ;
T_3 V_586 , V_587 , V_588 ;
int V_589 = 0 ;
enum V_590 V_591 ;
V_27 = F_141 ( V_33 , V_166 -> V_184 ) ;
if ( ! V_27 )
return F_246 ( V_33 , V_166 ) ;
V_10 = V_27 -> V_10 ;
V_586 = F_171 ( V_297 -> V_592 ) ;
V_587 = F_171 ( V_297 -> V_593 ) ;
V_10 -> V_586 = V_586 ;
if ( F_121 ( V_10 ) ) {
F_25 () ;
V_588 = F_26 ( V_10 -> V_238 -> V_263 ) -> V_594 ;
F_27 () ;
F_251 ( V_10 , L_126 ,
V_586 , F_253 ( V_10 -> V_238 ) ) ;
F_251 ( V_10 , L_127 ,
V_587 , V_588 ) ;
if ( V_10 -> V_346 . V_100 == V_98 )
V_587 = F_254 ( V_588 , V_587 ) ;
if ( F_255 ( V_10 , V_10 -> V_238 , V_587 , 0 ) <
F_147 ( V_10 -> V_300 ) &&
V_10 -> V_346 . V_403 >= V_595 &&
V_10 -> V_346 . V_100 < V_528 ) {
F_41 ( V_10 , L_128 ) ;
F_63 ( V_27 -> V_33 , F_64 ( V_100 , V_145 ) , V_102 ) ;
F_124 ( V_10 ) ;
return - V_103 ;
}
if ( V_588 != V_587 ) {
struct V_263 * V_560 , * V_561 = NULL ;
V_561 = F_249 ( sizeof( struct V_263 ) , V_551 ) ;
if ( ! V_561 ) {
F_41 ( V_10 , L_115 ) ;
F_124 ( V_10 ) ;
return - V_277 ;
}
F_111 ( & V_33 -> V_24 -> V_220 ) ;
V_560 = V_10 -> V_238 -> V_263 ;
* V_561 = * V_560 ;
V_561 -> V_594 = V_587 ;
F_239 ( V_10 -> V_238 -> V_263 , V_561 ) ;
F_112 ( & V_33 -> V_24 -> V_220 ) ;
F_241 () ;
F_46 ( V_560 ) ;
F_60 ( V_10 , L_129 ,
( unsigned long ) V_588 ) ;
}
F_124 ( V_10 ) ;
}
V_591 = F_116 ( V_297 -> V_590 ) ;
if ( F_121 ( V_10 ) ) {
V_584 = F_256 ( V_10 , V_591 , NULL ) ;
F_124 ( V_10 ) ;
if ( V_584 == V_596 )
return - V_103 ;
F_257 ( V_10 ) ;
} else {
F_258 ( V_10 , V_586 ) ;
}
V_10 -> V_597 = F_117 ( V_297 -> V_598 ) ;
F_259 ( V_10 ) ;
if ( F_121 ( V_10 ) ) {
if ( V_10 -> V_238 -> V_599 != F_147 ( V_10 -> V_238 -> V_239 ) ) {
V_10 -> V_238 -> V_599 = F_147 ( V_10 -> V_238 -> V_239 ) ;
V_589 = 1 ;
}
F_124 ( V_10 ) ;
}
if ( V_10 -> V_346 . V_100 > V_98 ) {
if ( F_171 ( V_297 -> V_600 ) !=
F_147 ( V_10 -> V_300 ) || V_589 ) {
F_92 ( V_27 , 0 , V_591 ) ;
}
if ( F_260 ( V_179 , & V_10 -> V_63 ) ||
( V_584 == V_601 && V_10 -> V_346 . V_100 == V_528 ) ) {
if ( V_10 -> V_346 . V_398 >= V_399 &&
V_10 -> V_346 . V_403 >= V_399 ) {
if ( V_591 & V_602 )
F_60 ( V_10 , L_130 ) ;
else
F_261 ( V_10 ) ;
} else
F_101 ( V_603 , & V_10 -> V_63 ) ;
}
}
return 0 ;
}
static int F_262 ( struct V_88 * V_33 , struct V_165 * V_166 )
{
struct V_26 * V_27 ;
struct V_9 * V_10 ;
struct V_604 * V_297 = V_166 -> V_90 ;
T_2 * V_474 ;
int V_6 , V_605 = 0 ;
V_27 = F_141 ( V_33 , V_166 -> V_184 ) ;
if ( ! V_27 )
return F_246 ( V_33 , V_166 ) ;
V_10 = V_27 -> V_10 ;
V_474 = F_144 ( sizeof( T_2 ) * V_606 , V_206 ) ;
if ( ! V_474 ) {
F_41 ( V_10 , L_131 ) ;
return false ;
}
for ( V_6 = V_496 ; V_6 < V_606 ; V_6 ++ )
V_474 [ V_6 ] = F_171 ( V_297 -> V_472 [ V_6 ] ) ;
F_46 ( V_10 -> V_474 ) ;
V_10 -> V_474 = V_474 ;
if ( V_10 -> V_346 . V_100 < V_528 &&
V_10 -> V_346 . V_403 < V_399 &&
V_10 -> V_346 . V_490 == V_463 &&
( V_10 -> V_607 & ~ ( ( T_2 ) 1 ) ) != ( V_474 [ V_496 ] & ~ ( ( T_2 ) 1 ) ) ) {
F_41 ( V_10 , L_132 ,
( unsigned long long ) V_10 -> V_607 ) ;
F_63 ( V_27 -> V_33 , F_64 ( V_100 , V_145 ) , V_102 ) ;
return - V_103 ;
}
if ( F_121 ( V_10 ) ) {
int V_608 =
V_10 -> V_346 . V_100 == V_528 &&
V_27 -> V_33 -> V_175 >= 90 &&
V_10 -> V_238 -> V_471 . V_472 [ V_496 ] == V_501 &&
( V_474 [ V_504 ] & 8 ) ;
if ( V_608 ) {
F_60 ( V_10 , L_133 ) ;
F_235 ( V_10 , & V_609 ,
L_134 ,
V_610 ) ;
F_263 ( V_10 , V_496 , V_474 [ V_496 ] ) ;
F_263 ( V_10 , V_473 , 0 ) ;
F_264 ( F_265 ( V_10 , V_403 , V_436 , V_398 , V_436 ) ,
V_191 , NULL ) ;
F_257 ( V_10 ) ;
V_605 = 1 ;
}
F_124 ( V_10 ) ;
} else if ( V_10 -> V_346 . V_403 < V_399 &&
V_10 -> V_346 . V_490 == V_463 ) {
V_605 = F_266 ( V_10 , V_474 [ V_496 ] ) ;
}
F_111 ( V_10 -> V_174 ) ;
F_112 ( V_10 -> V_174 ) ;
if ( V_10 -> V_346 . V_100 >= V_528 && V_10 -> V_346 . V_403 < V_399 )
V_605 |= F_266 ( V_10 , V_474 [ V_496 ] ) ;
if ( V_605 )
F_267 ( V_10 , L_135 ) ;
return 0 ;
}
static union V_611 F_268 ( union V_611 V_612 )
{
union V_611 V_613 ;
static enum V_507 V_614 [] = {
[ V_98 ] = V_98 ,
[ V_528 ] = V_528 ,
[ V_615 ] = V_616 ,
[ V_616 ] = V_615 ,
[ V_145 ] = V_617 ,
[ V_425 ] = V_426 ,
[ V_512 ] = V_512 ,
} ;
V_613 . V_6 = V_612 . V_6 ;
V_613 . V_100 = V_614 [ V_612 . V_100 ] ;
V_613 . V_462 = V_612 . V_490 ;
V_613 . V_490 = V_612 . V_462 ;
V_613 . V_398 = V_612 . V_403 ;
V_613 . V_403 = V_612 . V_398 ;
V_613 . V_618 = ( V_612 . V_619 | V_612 . V_620 ) ;
return V_613 ;
}
static int F_269 ( struct V_88 * V_33 , struct V_165 * V_166 )
{
struct V_26 * V_27 ;
struct V_9 * V_10 ;
struct V_621 * V_297 = V_166 -> V_90 ;
union V_611 V_622 , V_623 ;
enum V_189 V_89 ;
V_27 = F_141 ( V_33 , V_166 -> V_184 ) ;
if ( ! V_27 )
return - V_103 ;
V_10 = V_27 -> V_10 ;
V_622 . V_6 = F_117 ( V_297 -> V_622 ) ;
V_623 . V_6 = F_117 ( V_297 -> V_623 ) ;
if ( F_61 ( V_198 , & V_27 -> V_33 -> V_63 ) &&
F_270 ( V_10 -> V_174 ) ) {
F_271 ( V_27 , V_624 ) ;
return 0 ;
}
V_622 = F_268 ( V_622 ) ;
V_623 = F_268 ( V_623 ) ;
V_89 = F_226 ( V_10 , V_191 , V_622 , V_623 ) ;
F_271 ( V_27 , V_89 ) ;
F_257 ( V_10 ) ;
return 0 ;
}
static int F_272 ( struct V_88 * V_33 , struct V_165 * V_166 )
{
struct V_621 * V_297 = V_166 -> V_90 ;
union V_611 V_622 , V_623 ;
enum V_189 V_89 ;
V_622 . V_6 = F_117 ( V_297 -> V_622 ) ;
V_623 . V_6 = F_117 ( V_297 -> V_623 ) ;
if ( F_61 ( V_198 , & V_33 -> V_63 ) &&
F_270 ( & V_33 -> V_176 ) ) {
F_273 ( V_33 , V_624 ) ;
return 0 ;
}
V_622 = F_268 ( V_622 ) ;
V_623 = F_268 ( V_623 ) ;
V_89 = F_63 ( V_33 , V_622 , V_623 , V_191 | V_625 | V_626 ) ;
F_273 ( V_33 , V_89 ) ;
return 0 ;
}
static int F_274 ( struct V_88 * V_33 , struct V_165 * V_166 )
{
struct V_26 * V_27 ;
struct V_9 * V_10 ;
struct V_627 * V_297 = V_166 -> V_90 ;
union V_611 V_628 , V_629 , V_630 ;
enum V_510 V_631 ;
enum V_632 V_633 ;
int V_89 ;
V_27 = F_141 ( V_33 , V_166 -> V_184 ) ;
if ( ! V_27 )
return F_246 ( V_33 , V_166 ) ;
V_10 = V_27 -> V_10 ;
V_630 . V_6 = F_117 ( V_297 -> V_346 ) ;
V_631 = V_630 . V_403 ;
if ( V_630 . V_403 == V_503 ) {
V_631 = V_10 -> V_474 [ V_504 ] & 4 ? V_399 : V_522 ;
F_60 ( V_10 , L_136 , F_275 ( V_631 ) ) ;
}
F_20 ( & V_10 -> V_24 -> V_25 ) ;
V_28:
V_628 = V_629 = F_276 ( V_10 ) ;
F_21 ( & V_10 -> V_24 -> V_25 ) ;
if ( V_628 . V_100 <= V_617 )
return - V_91 ;
if ( ( V_628 . V_398 == V_399 || V_628 . V_398 == V_522 ) &&
V_631 == V_436 &&
V_628 . V_100 > V_528 && V_628 . V_403 == V_436 ) {
if ( V_630 . V_100 > V_528 &&
V_630 . V_100 < V_347 )
V_631 = V_399 ;
else if ( V_628 . V_100 >= V_347 &&
V_630 . V_100 == V_528 ) {
if ( F_214 ( V_10 ) <= V_10 -> V_428 )
F_277 ( V_10 ) ;
return 0 ;
}
}
if ( V_628 . V_100 == V_426 && V_628 . V_403 == V_436 &&
V_630 . V_100 == V_528 && V_631 == V_436 ) {
F_278 ( V_10 ) ;
F_277 ( V_10 ) ;
return 0 ;
}
if ( V_628 . V_398 == V_436 && V_631 == V_399 &&
V_628 . V_100 == V_528 && V_630 . V_100 > V_347 )
V_631 = V_436 ;
if ( V_629 . V_100 == V_98 )
V_629 . V_100 = V_528 ;
if ( V_630 . V_100 == V_634 )
V_629 . V_100 = V_635 ;
if ( V_10 -> V_474 && V_630 . V_403 >= V_503 &&
F_131 ( V_10 , V_503 ) ) {
int V_636 ;
V_636 = ( V_628 . V_100 < V_528 ) ;
V_636 |= ( V_628 . V_100 == V_528 &&
( V_630 . V_403 == V_503 ||
V_628 . V_403 == V_503 ) ) ;
V_636 |= F_61 ( V_637 , & V_10 -> V_63 ) ;
V_636 |= ( V_628 . V_100 == V_528 &&
( V_630 . V_100 >= V_615 &&
V_630 . V_100 <= V_527 ) ) ;
if ( V_636 )
V_629 . V_100 = F_233 ( V_27 , V_630 . V_490 , V_631 ) ;
F_124 ( V_10 ) ;
if ( V_629 . V_100 == V_512 ) {
V_629 . V_100 = V_528 ;
if ( V_10 -> V_346 . V_403 == V_503 ) {
F_279 ( V_10 , F_64 ( V_403 , V_638 ) ) ;
} else if ( V_630 . V_403 == V_503 ) {
F_41 ( V_10 , L_137 ) ;
V_630 . V_403 = V_639 ;
V_631 = V_639 ;
} else {
if ( F_260 ( V_523 , & V_27 -> V_33 -> V_63 ) )
return - V_103 ;
F_47 ( V_10 , V_628 . V_100 == V_98 ) ;
F_63 ( V_27 -> V_33 , F_64 ( V_100 , V_145 ) , V_102 ) ;
return - V_103 ;
}
}
}
F_20 ( & V_10 -> V_24 -> V_25 ) ;
if ( V_628 . V_6 != F_276 ( V_10 ) . V_6 )
goto V_28;
F_95 ( V_637 , & V_10 -> V_63 ) ;
V_629 . V_462 = V_630 . V_490 ;
V_629 . V_398 = V_631 ;
V_629 . V_618 = ( V_630 . V_619 | V_630 . V_620 ) ;
if ( ( V_629 . V_100 == V_528 || V_629 . V_100 == V_526 ) && V_629 . V_403 == V_503 )
V_629 . V_403 = V_10 -> V_516 . V_403 ;
V_633 = V_191 + ( V_628 . V_100 < V_528 && V_629 . V_100 >= V_528 ? 0 : V_102 ) ;
if ( V_629 . V_398 == V_522 && F_280 ( V_10 ) && V_629 . V_100 == V_528 && V_628 . V_100 < V_528 &&
F_61 ( V_640 , & V_10 -> V_63 ) ) {
F_21 ( & V_10 -> V_24 -> V_25 ) ;
F_41 ( V_10 , L_138 ) ;
F_281 ( V_27 -> V_33 ) ;
F_282 ( V_10 ) ;
F_95 ( V_640 , & V_10 -> V_63 ) ;
F_63 ( V_27 -> V_33 , F_283 ( V_100 , V_641 , V_642 , 0 ) , V_102 ) ;
return - V_103 ;
}
V_89 = F_264 ( V_10 , V_629 , V_633 , NULL ) ;
V_629 = F_276 ( V_10 ) ;
F_21 ( & V_10 -> V_24 -> V_25 ) ;
if ( V_89 < V_192 ) {
F_63 ( V_27 -> V_33 , F_64 ( V_100 , V_145 ) , V_102 ) ;
return - V_103 ;
}
if ( V_628 . V_100 > V_98 ) {
if ( V_629 . V_100 > V_528 && V_630 . V_100 <= V_528 &&
V_630 . V_403 != V_503 ) {
F_93 ( V_27 ) ;
F_94 ( V_27 ) ;
}
}
F_95 ( V_217 , & V_10 -> V_63 ) ;
F_257 ( V_10 ) ;
return 0 ;
}
static int F_284 ( struct V_88 * V_33 , struct V_165 * V_166 )
{
struct V_26 * V_27 ;
struct V_9 * V_10 ;
struct V_643 * V_297 = V_166 -> V_90 ;
V_27 = F_141 ( V_33 , V_166 -> V_184 ) ;
if ( ! V_27 )
return - V_103 ;
V_10 = V_27 -> V_10 ;
F_205 ( V_10 -> V_292 ,
V_10 -> V_346 . V_100 == V_644 ||
V_10 -> V_346 . V_100 == V_635 ||
V_10 -> V_346 . V_100 < V_528 ||
V_10 -> V_346 . V_403 < V_503 ) ;
if ( F_131 ( V_10 , V_503 ) ) {
F_263 ( V_10 , V_496 , F_171 ( V_297 -> V_472 ) ) ;
F_263 ( V_10 , V_473 , 0UL ) ;
F_267 ( V_10 , L_139 ) ;
F_285 ( V_10 , V_391 ) ;
F_124 ( V_10 ) ;
} else
F_41 ( V_10 , L_140 ) ;
return 0 ;
}
static int
F_286 ( struct V_26 * V_27 , unsigned int V_58 ,
unsigned long * V_297 , struct V_645 * V_646 )
{
unsigned int V_47 = V_555 -
F_87 ( V_27 -> V_33 ) ;
unsigned int V_647 = F_69 ( T_6 , V_47 / sizeof( * V_297 ) ,
V_646 -> V_648 - V_646 -> V_649 ) ;
unsigned int V_650 = V_647 * sizeof( * V_297 ) ;
int V_70 ;
if ( V_650 != V_58 ) {
F_41 ( V_27 , L_141 , V_55 , V_650 , V_58 ) ;
return - V_103 ;
}
if ( V_650 == 0 )
return 0 ;
V_70 = F_65 ( V_27 -> V_33 , V_297 , V_650 ) ;
if ( V_70 )
return V_70 ;
F_287 ( V_27 -> V_10 , V_646 -> V_649 , V_647 , V_297 ) ;
V_646 -> V_649 += V_647 ;
V_646 -> V_651 = V_646 -> V_649 * V_652 ;
if ( V_646 -> V_651 > V_646 -> V_653 )
V_646 -> V_651 = V_646 -> V_653 ;
return 1 ;
}
static enum V_654 F_288 ( struct V_655 * V_297 )
{
return (enum V_654 ) ( V_297 -> V_656 & 0x0f ) ;
}
static int F_289 ( struct V_655 * V_297 )
{
return ( V_297 -> V_656 & 0x80 ) != 0 ;
}
static int F_290 ( struct V_655 * V_297 )
{
return ( V_297 -> V_656 >> 4 ) & 0x7 ;
}
static int
F_291 ( struct V_26 * V_27 ,
struct V_655 * V_297 ,
struct V_645 * V_646 ,
unsigned int V_5 )
{
struct V_657 V_658 ;
T_2 V_659 ;
T_2 V_660 ;
T_2 V_4 ;
unsigned long V_196 = V_646 -> V_651 ;
unsigned long V_661 ;
int V_662 = F_289 ( V_297 ) ;
int V_663 ;
int V_495 ;
F_292 ( & V_658 , V_297 -> V_664 , V_5 , F_290 ( V_297 ) ) ;
V_495 = F_293 ( & V_658 , & V_659 , 64 ) ;
if ( V_495 < 0 )
return - V_103 ;
for ( V_663 = V_495 ; V_663 > 0 ; V_196 += V_660 , V_662 = ! V_662 ) {
V_495 = F_294 ( & V_660 , V_659 ) ;
if ( V_495 <= 0 )
return - V_103 ;
if ( V_662 ) {
V_661 = V_196 + V_660 - 1 ;
if ( V_661 >= V_646 -> V_653 ) {
F_41 ( V_27 , L_142 , V_661 ) ;
return - V_103 ;
}
F_295 ( V_27 -> V_10 , V_196 , V_661 ) ;
}
if ( V_663 < V_495 ) {
F_41 ( V_27 , L_143 ,
V_663 , V_495 , V_659 ,
( unsigned int ) ( V_658 . V_665 . V_356 - V_297 -> V_664 ) ,
( unsigned int ) V_658 . V_666 ) ;
return - V_103 ;
}
if ( F_160 ( V_495 < 64 ) )
V_659 >>= V_495 ;
else
V_659 = 0 ;
V_663 -= V_495 ;
V_495 = F_293 ( & V_658 , & V_4 , 64 - V_663 ) ;
if ( V_495 < 0 )
return - V_103 ;
V_659 |= V_4 << V_663 ;
V_663 += V_495 ;
}
V_646 -> V_651 = V_196 ;
F_296 ( V_646 ) ;
return ( V_196 != V_646 -> V_653 ) ;
}
static int
F_297 ( struct V_26 * V_27 ,
struct V_655 * V_297 ,
struct V_645 * V_646 ,
unsigned int V_5 )
{
if ( F_288 ( V_297 ) == V_667 )
return F_291 ( V_27 , V_297 , V_646 , V_5 - sizeof( * V_297 ) ) ;
F_41 ( V_27 , L_144 , V_297 -> V_656 ) ;
F_63 ( V_27 -> V_33 , F_64 ( V_100 , V_641 ) , V_102 ) ;
return - V_103 ;
}
void F_298 ( struct V_9 * V_10 ,
const char * V_668 , struct V_645 * V_646 )
{
unsigned int V_164 = F_87 ( F_181 ( V_10 ) -> V_33 ) ;
unsigned int V_47 = V_555 - V_164 ;
unsigned int V_669 =
V_164 * ( F_299 ( V_646 -> V_648 , V_47 ) + 1 ) +
V_646 -> V_648 * sizeof( unsigned long ) ;
unsigned int V_670 = V_646 -> V_671 [ 0 ] + V_646 -> V_671 [ 1 ] ;
unsigned int V_672 ;
if ( V_670 == 0 )
return;
if ( V_670 >= V_669 )
return;
V_672 = ( V_670 > V_673 / 1000 ) ? ( V_670 / ( V_669 / 1000 ) )
: ( 1000 * V_670 / V_669 ) ;
if ( V_672 > 1000 )
V_672 = 1000 ;
V_672 = 1000 - V_672 ;
F_60 ( V_10 , L_145
L_146 ,
V_668 ,
V_646 -> V_671 [ 1 ] , V_646 -> V_674 [ 1 ] ,
V_646 -> V_671 [ 0 ] , V_646 -> V_674 [ 0 ] ,
V_670 , V_672 / 10 , V_672 % 10 ) ;
}
static int F_300 ( struct V_88 * V_33 , struct V_165 * V_166 )
{
struct V_26 * V_27 ;
struct V_9 * V_10 ;
struct V_645 V_646 ;
int V_70 ;
V_27 = F_141 ( V_33 , V_166 -> V_184 ) ;
if ( ! V_27 )
return - V_103 ;
V_10 = V_27 -> V_10 ;
F_301 ( V_10 , L_147 , V_525 ) ;
V_646 = (struct V_645 ) {
. V_653 = F_221 ( V_10 ) ,
. V_648 = F_302 ( V_10 ) ,
} ;
for(; ; ) {
if ( V_166 -> V_163 == V_675 )
V_70 = F_286 ( V_27 , V_166 -> V_58 , V_166 -> V_90 , & V_646 ) ;
else if ( V_166 -> V_163 == V_676 ) {
struct V_655 * V_297 = V_166 -> V_90 ;
if ( V_166 -> V_58 > V_555 - F_87 ( V_33 ) ) {
F_41 ( V_10 , L_148 ) ;
V_70 = - V_103 ;
goto V_99;
}
if ( V_166 -> V_58 <= sizeof( * V_297 ) ) {
F_41 ( V_10 , L_149 , V_166 -> V_58 ) ;
V_70 = - V_103 ;
goto V_99;
}
V_70 = F_65 ( V_27 -> V_33 , V_297 , V_166 -> V_58 ) ;
if ( V_70 )
goto V_99;
V_70 = F_297 ( V_27 , V_297 , & V_646 , V_166 -> V_58 ) ;
} else {
F_31 ( V_10 , L_150 , V_166 -> V_163 ) ;
V_70 = - V_103 ;
goto V_99;
}
V_646 . V_674 [ V_166 -> V_163 == V_675 ] ++ ;
V_646 . V_671 [ V_166 -> V_163 == V_675 ] += F_87 ( V_33 ) + V_166 -> V_58 ;
if ( V_70 <= 0 ) {
if ( V_70 < 0 )
goto V_99;
break;
}
V_70 = F_119 ( V_27 -> V_33 , V_166 ) ;
if ( V_70 )
goto V_99;
}
F_298 ( V_10 , L_151 , & V_646 ) ;
if ( V_10 -> V_346 . V_100 == V_527 ) {
enum V_189 V_89 ;
V_70 = F_303 ( V_10 ) ;
if ( V_70 )
goto V_99;
V_89 = F_304 ( V_10 , F_64 ( V_100 , V_644 ) , V_191 ) ;
F_47 ( V_10 , V_89 == V_192 ) ;
} else if ( V_10 -> V_346 . V_100 != V_526 ) {
F_60 ( V_10 , L_152 ,
F_234 ( V_10 -> V_346 . V_100 ) ) ;
}
V_70 = 0 ;
V_99:
F_305 ( V_10 ) ;
if ( ! V_70 && V_10 -> V_346 . V_100 == V_526 )
F_285 ( V_10 , V_347 ) ;
return V_70 ;
}
static int F_306 ( struct V_88 * V_33 , struct V_165 * V_166 )
{
F_31 ( V_33 , L_153 ,
V_166 -> V_163 , V_166 -> V_58 ) ;
return F_245 ( V_33 , V_166 ) ;
}
static int F_307 ( struct V_88 * V_33 , struct V_165 * V_166 )
{
F_308 ( V_33 -> V_90 . V_76 ) ;
return 0 ;
}
static int F_309 ( struct V_88 * V_33 , struct V_165 * V_166 )
{
struct V_26 * V_27 ;
struct V_9 * V_10 ;
struct V_677 * V_297 = V_166 -> V_90 ;
V_27 = F_141 ( V_33 , V_166 -> V_184 ) ;
if ( ! V_27 )
return - V_103 ;
V_10 = V_27 -> V_10 ;
switch ( V_10 -> V_346 . V_100 ) {
case V_644 :
case V_527 :
case V_635 :
break;
default:
F_41 ( V_10 , L_154 ,
F_234 ( V_10 -> V_346 . V_100 ) ) ;
}
F_206 ( V_10 , F_171 ( V_297 -> V_46 ) , F_117 ( V_297 -> V_435 ) ) ;
return 0 ;
}
static void F_310 ( struct V_88 * V_33 )
{
struct V_165 V_166 ;
T_6 V_678 ;
int V_70 ;
while ( F_104 ( & V_33 -> V_203 ) == V_679 ) {
struct V_680 * V_163 ;
F_311 ( & V_33 -> V_203 ) ;
if ( F_119 ( V_33 , & V_166 ) )
goto V_681;
V_163 = & V_682 [ V_166 . V_163 ] ;
if ( F_172 ( V_166 . V_163 >= F_312 ( V_682 ) || ! V_163 -> V_683 ) ) {
F_41 ( V_33 , L_155 ,
F_247 ( V_166 . V_163 ) , V_166 . V_163 ) ;
goto V_681;
}
V_678 = V_163 -> V_684 ;
if ( V_166 . V_58 > V_678 && ! V_163 -> V_685 ) {
F_41 ( V_33 , L_156 ,
F_247 ( V_166 . V_163 ) , V_166 . V_58 ) ;
goto V_681;
}
if ( V_678 ) {
V_70 = F_66 ( V_33 , V_166 . V_90 , V_678 ) ;
if ( V_70 )
goto V_681;
V_166 . V_58 -= V_678 ;
}
V_70 = V_163 -> V_683 ( V_33 , & V_166 ) ;
if ( V_70 ) {
F_41 ( V_33 , L_157 ,
F_247 ( V_166 . V_163 ) , V_70 , V_166 . V_58 ) ;
goto V_681;
}
}
return;
V_681:
F_63 ( V_33 , F_64 ( V_100 , V_641 ) , V_102 ) ;
}
static void F_313 ( struct V_88 * V_33 )
{
struct V_26 * V_27 ;
enum V_507 V_686 ;
int V_184 ;
if ( V_33 -> V_97 == V_687 )
return;
F_63 ( V_33 , F_64 ( V_100 , V_688 ) , V_102 ) ;
F_314 ( & V_33 -> V_219 ) ;
F_315 ( V_33 ) ;
F_25 () ;
F_109 (&connection->peer_devices, peer_device, vnr) {
struct V_9 * V_10 = V_27 -> V_10 ;
F_110 ( & V_10 -> V_216 ) ;
F_27 () ;
F_316 ( V_27 ) ;
F_113 ( & V_10 -> V_216 , V_218 ) ;
F_25 () ;
}
F_27 () ;
if ( ! F_54 ( & V_33 -> V_256 -> V_21 ) )
F_41 ( V_33 , L_158 ) ;
F_43 ( & V_33 -> V_256 -> V_245 , 0 ) ;
V_33 -> V_689 . V_690 = false ;
F_60 ( V_33 , L_159 ) ;
if ( F_317 ( V_33 ) == V_463 && F_318 ( V_33 ) >= V_691 )
F_319 ( V_33 ) ;
F_20 ( & V_33 -> V_24 -> V_25 ) ;
V_686 = V_33 -> V_97 ;
if ( V_686 >= V_692 )
F_202 ( V_33 , F_64 ( V_100 , V_692 ) , V_191 ) ;
F_21 ( & V_33 -> V_24 -> V_25 ) ;
if ( V_686 == V_145 )
F_63 ( V_33 , F_64 ( V_100 , V_687 ) , V_191 | V_102 ) ;
}
static int F_316 ( struct V_26 * V_27 )
{
struct V_9 * V_10 = V_27 -> V_10 ;
unsigned int V_6 ;
F_20 ( & V_10 -> V_24 -> V_25 ) ;
F_53 ( V_10 , & V_10 -> V_293 ) ;
F_53 ( V_10 , & V_10 -> V_326 ) ;
F_53 ( V_10 , & V_10 -> V_464 ) ;
F_21 ( & V_10 -> V_24 -> V_25 ) ;
F_320 ( V_10 ) ;
V_10 -> V_460 = 0 ;
V_10 -> V_428 = 0 ;
F_43 ( & V_10 -> V_693 , 0 ) ;
F_37 ( & V_10 -> V_292 ) ;
F_321 ( & V_10 -> V_694 ) ;
F_322 ( ( unsigned long ) V_10 ) ;
F_323 ( & V_27 -> V_33 -> V_695 ) ;
F_51 ( V_10 ) ;
F_323 ( & V_27 -> V_33 -> V_695 ) ;
F_320 ( V_10 ) ;
F_46 ( V_10 -> V_474 ) ;
V_10 -> V_474 = NULL ;
if ( ! F_280 ( V_10 ) )
F_281 ( V_27 -> V_33 ) ;
F_257 ( V_10 ) ;
F_205 ( V_10 -> V_292 , ! F_61 ( V_696 , & V_10 -> V_63 ) ) ;
V_6 = F_49 ( V_10 , & V_10 -> V_69 ) ;
if ( V_6 )
F_60 ( V_10 , L_160 , V_6 ) ;
V_6 = F_28 ( & V_10 -> V_41 ) ;
if ( V_6 )
F_60 ( V_10 , L_161 , V_6 ) ;
V_6 = F_28 ( & V_10 -> V_35 ) ;
if ( V_6 )
F_60 ( V_10 , L_162 , V_6 ) ;
F_47 ( V_10 , F_54 ( & V_10 -> V_464 ) ) ;
F_47 ( V_10 , F_54 ( & V_10 -> V_293 ) ) ;
F_47 ( V_10 , F_54 ( & V_10 -> V_326 ) ) ;
F_47 ( V_10 , F_54 ( & V_10 -> V_71 ) ) ;
return 0 ;
}
static int F_324 ( struct V_88 * V_33 )
{
struct V_161 * V_77 ;
struct V_697 * V_297 ;
V_77 = & V_33 -> V_90 ;
V_297 = F_84 ( V_33 , V_77 ) ;
if ( ! V_297 )
return - V_103 ;
memset ( V_297 , 0 , sizeof( * V_297 ) ) ;
V_297 -> V_698 = F_115 ( V_699 ) ;
V_297 -> V_700 = F_115 ( V_701 ) ;
return F_85 ( V_33 , V_77 , V_702 , sizeof( * V_297 ) , NULL , 0 ) ;
}
static int F_106 ( struct V_88 * V_33 )
{
struct V_697 * V_297 ;
const int F_149 = sizeof( struct V_697 ) ;
struct V_165 V_166 ;
int V_70 ;
V_70 = F_324 ( V_33 ) ;
if ( V_70 )
return 0 ;
V_70 = F_119 ( V_33 , & V_166 ) ;
if ( V_70 )
return 0 ;
if ( V_166 . V_163 != V_702 ) {
F_41 ( V_33 , L_163 ,
F_247 ( V_166 . V_163 ) , V_166 . V_163 ) ;
return - 1 ;
}
if ( V_166 . V_58 != F_149 ) {
F_41 ( V_33 , L_164 ,
F_149 , V_166 . V_58 ) ;
return - 1 ;
}
V_297 = V_166 . V_90 ;
V_70 = F_66 ( V_33 , V_297 , F_149 ) ;
if ( V_70 )
return 0 ;
V_297 -> V_698 = F_117 ( V_297 -> V_698 ) ;
V_297 -> V_700 = F_117 ( V_297 -> V_700 ) ;
if ( V_297 -> V_700 == 0 )
V_297 -> V_700 = V_297 -> V_698 ;
if ( V_701 < V_297 -> V_698 ||
V_699 > V_297 -> V_700 )
goto V_703;
V_33 -> V_175 = F_69 ( int , V_701 , V_297 -> V_700 ) ;
F_60 ( V_33 , L_165
L_166 , V_33 -> V_175 ) ;
return 1 ;
V_703:
F_41 ( V_33 , L_167
L_168 ,
V_699 , V_701 ,
V_297 -> V_698 , V_297 -> V_700 ) ;
return - 1 ;
}
static int F_107 ( struct V_88 * V_33 )
{
F_41 ( V_33 , L_169 ) ;
F_41 ( V_33 , L_170 ) ;
return - 1 ;
}
static int F_107 ( struct V_88 * V_33 )
{
struct V_161 * V_77 ;
char V_704 [ V_705 ] ;
struct V_706 V_707 ;
char * V_708 = NULL ;
char * V_709 = NULL ;
char * V_710 = NULL ;
unsigned int V_711 ;
char V_712 [ V_540 ] ;
unsigned int V_713 ;
struct V_714 V_715 ;
struct V_165 V_166 ;
struct V_29 * V_30 ;
int V_70 , V_89 ;
F_25 () ;
V_30 = F_26 ( V_33 -> V_29 ) ;
V_711 = strlen ( V_30 -> V_716 ) ;
memcpy ( V_712 , V_30 -> V_716 , V_711 ) ;
F_27 () ;
V_715 . V_554 = V_33 -> V_212 ;
V_715 . V_63 = 0 ;
V_89 = F_325 ( V_33 -> V_212 , ( V_717 * ) V_712 , V_711 ) ;
if ( V_89 ) {
F_41 ( V_33 , L_171 , V_89 ) ;
V_89 = - 1 ;
goto V_57;
}
F_326 ( V_704 , V_705 ) ;
V_77 = & V_33 -> V_90 ;
if ( ! F_84 ( V_33 , V_77 ) ) {
V_89 = 0 ;
goto V_57;
}
V_89 = ! F_85 ( V_33 , V_77 , V_718 , 0 ,
V_704 , V_705 ) ;
if ( ! V_89 )
goto V_57;
V_70 = F_119 ( V_33 , & V_166 ) ;
if ( V_70 ) {
V_89 = 0 ;
goto V_57;
}
if ( V_166 . V_163 != V_718 ) {
F_41 ( V_33 , L_172 ,
F_247 ( V_166 . V_163 ) , V_166 . V_163 ) ;
V_89 = 0 ;
goto V_57;
}
if ( V_166 . V_58 > V_705 * 2 ) {
F_41 ( V_33 , L_173 ) ;
V_89 = - 1 ;
goto V_57;
}
V_710 = F_144 ( V_166 . V_58 , V_206 ) ;
if ( V_710 == NULL ) {
F_41 ( V_33 , L_174 ) ;
V_89 = - 1 ;
goto V_57;
}
V_70 = F_66 ( V_33 , V_710 , V_166 . V_58 ) ;
if ( V_70 ) {
V_89 = 0 ;
goto V_57;
}
V_713 = F_148 ( V_33 -> V_212 ) ;
V_708 = F_144 ( V_713 , V_206 ) ;
if ( V_708 == NULL ) {
F_41 ( V_33 , L_175 ) ;
V_89 = - 1 ;
goto V_57;
}
F_327 ( & V_707 , 1 ) ;
F_328 ( & V_707 , V_710 , V_166 . V_58 ) ;
V_89 = F_329 ( & V_715 , & V_707 , V_707 . V_229 , V_708 ) ;
if ( V_89 ) {
F_41 ( V_33 , L_176 , V_89 ) ;
V_89 = - 1 ;
goto V_57;
}
if ( ! F_84 ( V_33 , V_77 ) ) {
V_89 = 0 ;
goto V_57;
}
V_89 = ! F_85 ( V_33 , V_77 , V_719 , 0 ,
V_708 , V_713 ) ;
if ( ! V_89 )
goto V_57;
V_70 = F_119 ( V_33 , & V_166 ) ;
if ( V_70 ) {
V_89 = 0 ;
goto V_57;
}
if ( V_166 . V_163 != V_719 ) {
F_41 ( V_33 , L_177 ,
F_247 ( V_166 . V_163 ) , V_166 . V_163 ) ;
V_89 = 0 ;
goto V_57;
}
if ( V_166 . V_58 != V_713 ) {
F_41 ( V_33 , L_178 ) ;
V_89 = 0 ;
goto V_57;
}
V_70 = F_66 ( V_33 , V_708 , V_713 ) ;
if ( V_70 ) {
V_89 = 0 ;
goto V_57;
}
V_709 = F_144 ( V_713 , V_206 ) ;
if ( V_709 == NULL ) {
F_41 ( V_33 , L_179 ) ;
V_89 = - 1 ;
goto V_57;
}
F_328 ( & V_707 , V_704 , V_705 ) ;
V_89 = F_329 ( & V_715 , & V_707 , V_707 . V_229 , V_709 ) ;
if ( V_89 ) {
F_41 ( V_33 , L_176 , V_89 ) ;
V_89 = - 1 ;
goto V_57;
}
V_89 = ! memcmp ( V_708 , V_709 , V_713 ) ;
if ( V_89 )
F_60 ( V_33 , L_180 ,
V_713 ) ;
else
V_89 = - 1 ;
V_57:
F_46 ( V_710 ) ;
F_46 ( V_708 ) ;
F_46 ( V_709 ) ;
return V_89 ;
}
int F_330 ( struct V_720 * V_721 )
{
struct V_88 * V_33 = V_721 -> V_33 ;
int V_186 ;
F_60 ( V_33 , L_181 ) ;
do {
V_186 = F_97 ( V_33 ) ;
if ( V_186 == 0 ) {
F_313 ( V_33 ) ;
F_100 ( V_95 ) ;
}
if ( V_186 == - 1 ) {
F_31 ( V_33 , L_182 ) ;
F_63 ( V_33 , F_64 ( V_100 , V_145 ) , V_102 ) ;
}
} while ( V_186 == 0 );
if ( V_186 > 0 )
F_310 ( V_33 ) ;
F_313 ( V_33 ) ;
F_60 ( V_33 , L_183 ) ;
return 0 ;
}
static int F_331 ( struct V_88 * V_33 , struct V_165 * V_166 )
{
struct V_722 * V_297 = V_166 -> V_90 ;
int V_723 = F_117 ( V_297 -> V_723 ) ;
if ( V_723 >= V_192 ) {
F_101 ( V_724 , & V_33 -> V_63 ) ;
} else {
F_101 ( V_725 , & V_33 -> V_63 ) ;
F_41 ( V_33 , L_184 ,
F_332 ( V_723 ) , V_723 ) ;
}
F_37 ( & V_33 -> V_96 ) ;
return 0 ;
}
static int F_333 ( struct V_88 * V_33 , struct V_165 * V_166 )
{
struct V_26 * V_27 ;
struct V_9 * V_10 ;
struct V_722 * V_297 = V_166 -> V_90 ;
int V_723 = F_117 ( V_297 -> V_723 ) ;
V_27 = F_141 ( V_33 , V_166 -> V_184 ) ;
if ( ! V_27 )
return - V_103 ;
V_10 = V_27 -> V_10 ;
if ( F_61 ( V_726 , & V_33 -> V_63 ) ) {
F_47 ( V_10 , V_33 -> V_175 < 100 ) ;
return F_331 ( V_33 , V_166 ) ;
}
if ( V_723 >= V_192 ) {
F_101 ( V_727 , & V_10 -> V_63 ) ;
} else {
F_101 ( V_728 , & V_10 -> V_63 ) ;
F_41 ( V_10 , L_184 ,
F_332 ( V_723 ) , V_723 ) ;
}
F_37 ( & V_10 -> V_729 ) ;
return 0 ;
}
static int F_334 ( struct V_88 * V_33 , struct V_165 * V_166 )
{
return F_335 ( V_33 ) ;
}
static int F_336 ( struct V_88 * V_33 , struct V_165 * V_166 )
{
V_33 -> V_195 . V_76 -> V_106 -> V_132 = V_33 -> V_29 -> V_210 * V_95 ;
if ( ! F_337 ( V_730 , & V_33 -> V_63 ) )
F_37 ( & V_33 -> V_96 ) ;
return 0 ;
}
static int F_338 ( struct V_88 * V_33 , struct V_165 * V_166 )
{
struct V_26 * V_27 ;
struct V_9 * V_10 ;
struct V_731 * V_297 = V_166 -> V_90 ;
T_3 V_46 = F_171 ( V_297 -> V_46 ) ;
int V_435 = F_117 ( V_297 -> V_435 ) ;
V_27 = F_141 ( V_33 , V_166 -> V_184 ) ;
if ( ! V_27 )
return - V_103 ;
V_10 = V_27 -> V_10 ;
F_47 ( V_10 , V_27 -> V_33 -> V_175 >= 89 ) ;
F_187 ( V_27 , F_117 ( V_297 -> V_387 ) ) ;
if ( F_121 ( V_10 ) ) {
F_339 ( V_10 , V_46 ) ;
F_161 ( V_10 , V_46 , V_435 ) ;
V_10 -> V_732 += ( V_435 >> V_733 ) ;
F_124 ( V_10 ) ;
}
F_166 ( V_10 ) ;
F_34 ( V_435 >> 9 , & V_10 -> V_338 ) ;
return 0 ;
}
static int
F_340 ( struct V_9 * V_10 , T_2 V_45 , T_3 V_46 ,
struct V_330 * V_331 , const char * V_333 ,
enum V_734 V_112 , bool V_332 )
{
struct V_309 * V_310 ;
struct V_379 V_380 ;
F_20 ( & V_10 -> V_24 -> V_25 ) ;
V_310 = F_168 ( V_10 , V_331 , V_45 , V_46 , V_332 , V_333 ) ;
if ( F_172 ( ! V_310 ) ) {
F_21 ( & V_10 -> V_24 -> V_25 ) ;
return - V_103 ;
}
F_179 ( V_310 , V_112 , & V_380 ) ;
F_21 ( & V_10 -> V_24 -> V_25 ) ;
if ( V_380 . V_273 )
F_195 ( V_10 , & V_380 ) ;
return 0 ;
}
static int F_341 ( struct V_88 * V_33 , struct V_165 * V_166 )
{
struct V_26 * V_27 ;
struct V_9 * V_10 ;
struct V_731 * V_297 = V_166 -> V_90 ;
T_3 V_46 = F_171 ( V_297 -> V_46 ) ;
int V_435 = F_117 ( V_297 -> V_435 ) ;
enum V_734 V_112 ;
V_27 = F_141 ( V_33 , V_166 -> V_184 ) ;
if ( ! V_27 )
return - V_103 ;
V_10 = V_27 -> V_10 ;
F_187 ( V_27 , F_117 ( V_297 -> V_387 ) ) ;
if ( V_297 -> V_64 == V_325 ) {
F_161 ( V_10 , V_46 , V_435 ) ;
F_166 ( V_10 ) ;
return 0 ;
}
switch ( V_166 -> V_163 ) {
case V_323 :
V_112 = V_735 ;
break;
case V_350 :
V_112 = V_736 ;
break;
case V_397 :
V_112 = V_737 ;
break;
case V_354 :
V_112 = V_342 ;
break;
case V_355 :
V_112 = V_738 ;
break;
default:
F_219 () ;
}
return F_340 ( V_10 , V_297 -> V_64 , V_46 ,
& V_10 -> V_291 , V_55 ,
V_112 , false ) ;
}
static int F_342 ( struct V_88 * V_33 , struct V_165 * V_166 )
{
struct V_26 * V_27 ;
struct V_9 * V_10 ;
struct V_731 * V_297 = V_166 -> V_90 ;
T_3 V_46 = F_171 ( V_297 -> V_46 ) ;
int V_58 = F_117 ( V_297 -> V_435 ) ;
int V_70 ;
V_27 = F_141 ( V_33 , V_166 -> V_184 ) ;
if ( ! V_27 )
return - V_103 ;
V_10 = V_27 -> V_10 ;
F_187 ( V_27 , F_117 ( V_297 -> V_387 ) ) ;
if ( V_297 -> V_64 == V_325 ) {
F_166 ( V_10 ) ;
F_163 ( V_10 , V_46 , V_58 ) ;
return 0 ;
}
V_70 = F_340 ( V_10 , V_297 -> V_64 , V_46 ,
& V_10 -> V_291 , V_55 ,
V_381 , true ) ;
if ( V_70 ) {
F_206 ( V_10 , V_46 , V_58 ) ;
}
return 0 ;
}
static int F_343 ( struct V_88 * V_33 , struct V_165 * V_166 )
{
struct V_26 * V_27 ;
struct V_9 * V_10 ;
struct V_731 * V_297 = V_166 -> V_90 ;
T_3 V_46 = F_171 ( V_297 -> V_46 ) ;
V_27 = F_141 ( V_33 , V_166 -> V_184 ) ;
if ( ! V_27 )
return - V_103 ;
V_10 = V_27 -> V_10 ;
F_187 ( V_27 , F_117 ( V_297 -> V_387 ) ) ;
F_41 ( V_10 , L_185 ,
( unsigned long long ) V_46 , F_117 ( V_297 -> V_435 ) ) ;
return F_340 ( V_10 , V_297 -> V_64 , V_46 ,
& V_10 -> V_335 , V_55 ,
V_381 , false ) ;
}
static int F_344 ( struct V_88 * V_33 , struct V_165 * V_166 )
{
struct V_26 * V_27 ;
struct V_9 * V_10 ;
T_3 V_46 ;
int V_58 ;
struct V_731 * V_297 = V_166 -> V_90 ;
V_27 = F_141 ( V_33 , V_166 -> V_184 ) ;
if ( ! V_27 )
return - V_103 ;
V_10 = V_27 -> V_10 ;
V_46 = F_171 ( V_297 -> V_46 ) ;
V_58 = F_117 ( V_297 -> V_435 ) ;
F_187 ( V_27 , F_117 ( V_297 -> V_387 ) ) ;
F_166 ( V_10 ) ;
if ( F_131 ( V_10 , V_638 ) ) {
F_339 ( V_10 , V_46 ) ;
switch ( V_166 -> V_163 ) {
case V_442 :
F_163 ( V_10 , V_46 , V_58 ) ;
case V_739 :
break;
default:
F_219 () ;
}
F_124 ( V_10 ) ;
}
return 0 ;
}
static int F_345 ( struct V_88 * V_33 , struct V_165 * V_166 )
{
struct V_740 * V_297 = V_166 -> V_90 ;
struct V_26 * V_27 ;
int V_184 ;
F_346 ( V_33 , V_297 -> V_298 , F_117 ( V_297 -> V_741 ) ) ;
F_25 () ;
F_109 (&connection->peer_devices, peer_device, vnr) {
struct V_9 * V_10 = V_27 -> V_10 ;
if ( V_10 -> V_346 . V_100 == V_634 &&
F_28 ( & V_10 -> V_180 ) == 0 &&
! F_337 ( V_742 , & V_10 -> V_63 ) ) {
V_10 -> V_743 . V_744 = V_182 + V_95 ;
F_347 ( & V_10 -> V_743 ) ;
}
}
F_27 () ;
return 0 ;
}
static int F_348 ( struct V_88 * V_33 , struct V_165 * V_166 )
{
struct V_26 * V_27 ;
struct V_9 * V_10 ;
struct V_731 * V_297 = V_166 -> V_90 ;
struct V_745 * V_746 ;
T_3 V_46 ;
int V_58 ;
V_27 = F_141 ( V_33 , V_166 -> V_184 ) ;
if ( ! V_27 )
return - V_103 ;
V_10 = V_27 -> V_10 ;
V_46 = F_171 ( V_297 -> V_46 ) ;
V_58 = F_117 ( V_297 -> V_435 ) ;
F_187 ( V_27 , F_117 ( V_297 -> V_387 ) ) ;
if ( F_171 ( V_297 -> V_64 ) == V_747 )
F_349 ( V_10 , V_46 , V_58 ) ;
else
F_278 ( V_10 ) ;
if ( ! F_121 ( V_10 ) )
return 0 ;
F_339 ( V_10 , V_46 ) ;
F_166 ( V_10 ) ;
-- V_10 -> V_427 ;
if ( ( V_10 -> V_427 & 0x200 ) == 0x200 )
F_350 ( V_10 , V_10 -> V_427 ) ;
if ( V_10 -> V_427 == 0 ) {
V_746 = F_144 ( sizeof( * V_746 ) , V_206 ) ;
if ( V_746 ) {
V_746 -> V_20 . V_73 = V_748 ;
V_746 -> V_10 = V_10 ;
F_351 ( & V_27 -> V_33 -> V_695 , & V_746 -> V_20 ) ;
} else {
F_41 ( V_10 , L_186 ) ;
F_278 ( V_10 ) ;
F_277 ( V_10 ) ;
}
}
F_124 ( V_10 ) ;
return 0 ;
}
static int F_352 ( struct V_88 * V_33 , struct V_165 * V_166 )
{
return 0 ;
}
static int F_353 ( struct V_88 * V_33 )
{
struct V_26 * V_27 ;
int V_184 , V_749 = 0 ;
do {
F_95 ( V_750 , & V_33 -> V_63 ) ;
F_102 ( V_38 ) ;
F_25 () ;
F_109 (&connection->peer_devices, peer_device, vnr) {
struct V_9 * V_10 = V_27 -> V_10 ;
F_110 ( & V_10 -> V_216 ) ;
F_27 () ;
if ( F_51 ( V_10 ) ) {
F_113 ( & V_10 -> V_216 , V_218 ) ;
return 1 ;
}
F_113 ( & V_10 -> V_216 , V_218 ) ;
F_25 () ;
}
F_101 ( V_750 , & V_33 -> V_63 ) ;
F_20 ( & V_33 -> V_24 -> V_25 ) ;
F_109 (&connection->peer_devices, peer_device, vnr) {
struct V_9 * V_10 = V_27 -> V_10 ;
V_749 = ! F_54 ( & V_10 -> V_71 ) ;
if ( V_749 )
break;
}
F_21 ( & V_33 -> V_24 -> V_25 ) ;
F_27 () ;
} while ( V_749 );
return 0 ;
}
int F_354 ( struct V_720 * V_721 )
{
struct V_88 * V_33 = V_721 -> V_33 ;
struct V_751 * V_163 = NULL ;
struct V_165 V_166 ;
int V_89 ;
void * V_78 = V_33 -> V_195 . V_167 ;
int V_752 = 0 ;
unsigned int V_164 = F_87 ( V_33 ) ;
int F_149 = V_164 ;
bool V_753 = false ;
struct V_29 * V_30 ;
int V_94 , V_754 , V_210 ;
struct V_755 V_756 = { . V_757 = 2 } ;
V_89 = F_355 ( V_38 , V_758 , & V_756 ) ;
if ( V_89 < 0 )
F_41 ( V_33 , L_187 , V_89 ) ;
while ( F_104 ( V_721 ) == V_679 ) {
F_311 ( V_721 ) ;
F_25 () ;
V_30 = F_26 ( V_33 -> V_29 ) ;
V_94 = V_30 -> V_94 ;
V_754 = V_30 -> V_754 ;
V_210 = V_30 -> V_210 ;
F_27 () ;
if ( F_260 ( V_759 , & V_33 -> V_63 ) ) {
if ( F_356 ( V_33 ) ) {
F_41 ( V_33 , L_188 ) ;
goto V_571;
}
V_33 -> V_195 . V_76 -> V_106 -> V_132 = V_94 * V_95 / 10 ;
V_753 = true ;
}
if ( V_754 )
F_357 ( V_33 -> V_195 . V_76 ) ;
if ( F_353 ( V_33 ) ) {
F_41 ( V_33 , L_189 ) ;
goto V_571;
}
if ( V_754 )
F_358 ( V_33 -> V_195 . V_76 ) ;
if ( F_30 ( V_38 ) )
continue;
V_89 = F_57 ( V_33 -> V_195 . V_76 , V_78 , F_149 - V_752 , 0 ) ;
F_95 ( V_750 , & V_33 -> V_63 ) ;
F_102 ( V_38 ) ;
if ( F_160 ( V_89 > 0 ) ) {
V_752 += V_89 ;
V_78 += V_89 ;
} else if ( V_89 == 0 ) {
if ( F_61 ( V_93 , & V_33 -> V_63 ) ) {
long V_23 ;
F_25 () ;
V_23 = F_26 ( V_33 -> V_29 ) -> V_94 * V_95 / 10 ;
F_27 () ;
V_23 = F_62 ( V_33 -> V_96 ,
V_33 -> V_97 < V_98 ,
V_23 ) ;
if ( V_23 )
break;
}
F_41 ( V_33 , L_190 ) ;
goto V_571;
} else if ( V_89 == - V_138 ) {
if ( F_359 ( V_33 -> V_211 ,
V_182 - V_33 -> V_195 . V_76 -> V_106 -> V_132 ) )
continue;
if ( V_753 ) {
F_41 ( V_33 , L_191 ) ;
goto V_571;
}
F_101 ( V_759 , & V_33 -> V_63 ) ;
continue;
} else if ( V_89 == - V_140 ) {
continue;
} else {
F_41 ( V_33 , L_7 , V_89 ) ;
goto V_571;
}
if ( V_752 == F_149 && V_163 == NULL ) {
if ( F_88 ( V_33 , V_33 -> V_195 . V_167 , & V_166 ) )
goto V_571;
V_163 = & V_760 [ V_166 . V_163 ] ;
if ( V_166 . V_163 >= F_312 ( V_760 ) || ! V_163 -> V_683 ) {
F_41 ( V_33 , L_192 ,
F_247 ( V_166 . V_163 ) , V_166 . V_163 ) ;
goto V_550;
}
F_149 = V_164 + V_163 -> V_684 ;
if ( V_166 . V_58 != F_149 - V_164 ) {
F_41 ( V_33 , L_193 ,
V_166 . V_163 , V_166 . V_58 ) ;
goto V_571;
}
}
if ( V_752 == F_149 ) {
bool V_70 ;
V_70 = V_163 -> V_683 ( V_33 , & V_166 ) ;
if ( V_70 ) {
F_41 ( V_33 , L_194 , V_163 -> V_683 ) ;
goto V_571;
}
V_33 -> V_211 = V_182 ;
if ( V_163 == & V_760 [ V_761 ] ) {
V_33 -> V_195 . V_76 -> V_106 -> V_132 = V_210 * V_95 ;
V_753 = false ;
}
V_78 = V_33 -> V_195 . V_167 ;
V_752 = 0 ;
F_149 = V_164 ;
V_163 = NULL ;
}
}
if ( 0 ) {
V_571:
F_63 ( V_33 , F_64 ( V_100 , V_688 ) , V_102 ) ;
F_360 ( V_33 ) ;
}
if ( 0 ) {
V_550:
F_63 ( V_33 , F_64 ( V_100 , V_145 ) , V_102 ) ;
}
F_95 ( V_750 , & V_33 -> V_63 ) ;
F_60 ( V_33 , L_195 ) ;
return 0 ;
}
