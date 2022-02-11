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
memset ( V_19 , 0 , sizeof( * V_19 ) ) ;
F_42 ( & V_19 -> V_20 . V_21 ) ;
F_43 ( & V_19 -> V_6 ) ;
V_19 -> V_6 . V_61 = V_49 ;
V_19 -> V_6 . V_48 = V_48 ;
V_19 -> V_62 = V_63 ;
V_19 -> V_27 = V_27 ;
V_19 -> V_64 = V_1 ;
V_19 -> V_65 = V_47 ;
return V_19 ;
V_60:
F_44 ( V_19 , V_55 ) ;
return NULL ;
}
void F_45 ( struct V_9 * V_10 , struct V_18 * V_19 ,
int V_41 )
{
F_46 () ;
if ( V_19 -> V_66 & V_67 )
F_47 ( V_19 -> V_68 ) ;
F_35 ( V_10 , V_19 -> V_64 , V_41 ) ;
F_48 ( V_10 , F_28 ( & V_19 -> V_69 ) == 0 ) ;
F_48 ( V_10 , F_49 ( & V_19 -> V_6 ) ) ;
if ( ! F_50 ( ! ( V_19 -> V_66 & V_70 ) ) ) {
V_19 -> V_66 &= ~ V_70 ;
F_51 ( V_10 , & V_19 -> V_6 ) ;
}
F_44 ( V_19 , V_55 ) ;
}
int F_52 ( struct V_9 * V_10 , struct V_16 * V_21 )
{
F_19 ( V_71 ) ;
struct V_18 * V_19 , * V_23 ;
int V_72 = 0 ;
int V_41 = V_21 == & V_10 -> V_73 ;
F_20 ( & V_10 -> V_24 -> V_25 ) ;
F_53 ( V_21 , & V_71 ) ;
F_21 ( & V_10 -> V_24 -> V_25 ) ;
F_15 (peer_req, t, &work_list, w.list) {
F_45 ( V_10 , V_19 , V_41 ) ;
V_72 ++ ;
}
return V_72 ;
}
static int F_54 ( struct V_9 * V_10 )
{
F_19 ( V_71 ) ;
F_19 ( V_22 ) ;
struct V_18 * V_19 , * V_23 ;
int V_74 = 0 ;
F_20 ( & V_10 -> V_24 -> V_25 ) ;
F_14 ( V_10 , & V_22 ) ;
F_53 ( & V_10 -> V_75 , & V_71 ) ;
F_21 ( & V_10 -> V_24 -> V_25 ) ;
F_15 (peer_req, t, &reclaimed, w.list)
F_22 ( V_10 , V_19 ) ;
F_15 (peer_req, t, &work_list, w.list) {
int V_76 ;
V_76 = V_19 -> V_20 . V_77 ( & V_19 -> V_20 , ! ! V_74 ) ;
if ( ! V_74 )
V_74 = V_76 ;
F_55 ( V_10 , V_19 ) ;
}
F_37 ( & V_10 -> V_78 ) ;
return V_74 ;
}
static void F_56 ( struct V_9 * V_10 ,
struct V_16 * V_2 )
{
F_24 ( V_31 ) ;
while ( ! F_57 ( V_2 ) ) {
F_29 ( & V_10 -> V_78 , & V_31 , V_79 ) ;
F_21 ( & V_10 -> V_24 -> V_25 ) ;
F_58 () ;
F_33 ( & V_10 -> V_78 , & V_31 ) ;
F_20 ( & V_10 -> V_24 -> V_25 ) ;
}
}
static void F_59 ( struct V_9 * V_10 ,
struct V_16 * V_2 )
{
F_20 ( & V_10 -> V_24 -> V_25 ) ;
F_56 ( V_10 , V_2 ) ;
F_21 ( & V_10 -> V_24 -> V_25 ) ;
}
static int F_60 ( struct V_80 * V_81 , void * V_82 , T_6 V_61 , int V_66 )
{
struct V_83 V_84 = {
. V_85 = V_82 ,
. V_86 = V_61 ,
} ;
struct V_87 V_88 = {
. V_89 = ( V_66 ? V_66 : V_90 | V_91 )
} ;
return F_61 ( V_81 , & V_88 , & V_84 , 1 , V_61 , V_88 . V_89 ) ;
}
static int F_62 ( struct V_92 * V_33 , void * V_82 , T_6 V_61 )
{
int V_93 ;
V_93 = F_60 ( V_33 -> V_94 . V_80 , V_82 , V_61 , 0 ) ;
if ( V_93 < 0 ) {
if ( V_93 == - V_95 )
F_63 ( V_33 , L_6 ) ;
else if ( V_93 != - V_96 )
F_41 ( V_33 , L_7 , V_93 ) ;
} else if ( V_93 == 0 ) {
if ( F_64 ( V_97 , & V_33 -> V_66 ) ) {
long V_23 ;
F_25 () ;
V_23 = F_26 ( V_33 -> V_29 ) -> V_98 * V_39 / 10 ;
F_27 () ;
V_23 = F_65 ( V_33 -> V_99 , V_33 -> V_100 < V_101 , V_23 ) ;
if ( V_23 )
goto V_102;
}
F_63 ( V_33 , L_8 ) ;
}
if ( V_93 != V_61 )
F_66 ( V_33 , F_67 ( V_103 , V_104 ) , V_105 ) ;
V_102:
return V_93 ;
}
static int F_68 ( struct V_92 * V_33 , void * V_82 , T_6 V_61 )
{
int V_74 ;
V_74 = F_62 ( V_33 , V_82 , V_61 ) ;
if ( V_74 != V_61 ) {
if ( V_74 >= 0 )
V_74 = - V_106 ;
} else
V_74 = 0 ;
return V_74 ;
}
static int F_69 ( struct V_92 * V_33 , void * V_82 , T_6 V_61 )
{
int V_74 ;
V_74 = F_68 ( V_33 , V_82 , V_61 ) ;
if ( V_74 && ! F_30 ( V_38 ) )
F_31 ( V_33 , L_9 , ( int ) V_61 ) ;
return V_74 ;
}
static void F_70 ( struct V_80 * V_81 , unsigned int V_107 ,
unsigned int V_108 )
{
if ( V_107 ) {
V_81 -> V_109 -> V_110 = V_107 ;
V_81 -> V_109 -> V_111 |= V_112 ;
}
if ( V_108 ) {
V_81 -> V_109 -> V_113 = V_108 ;
V_81 -> V_109 -> V_111 |= V_114 ;
}
}
static struct V_80 * F_71 ( struct V_92 * V_33 )
{
const char * V_115 ;
struct V_80 * V_81 ;
struct V_116 V_117 ;
struct V_116 V_118 ;
struct V_29 * V_30 ;
int V_74 , V_119 , V_120 ;
int V_121 , V_122 , V_123 ;
int V_124 = 1 ;
F_25 () ;
V_30 = F_26 ( V_33 -> V_29 ) ;
if ( ! V_30 ) {
F_27 () ;
return NULL ;
}
V_121 = V_30 -> V_121 ;
V_122 = V_30 -> V_122 ;
V_123 = V_30 -> V_123 ;
F_27 () ;
V_120 = F_72 ( int , V_33 -> V_120 , sizeof( V_117 ) ) ;
memcpy ( & V_117 , & V_33 -> V_125 , V_120 ) ;
if ( ( (struct V_126 * ) & V_33 -> V_125 ) -> V_127 == V_128 )
V_117 . V_129 = 0 ;
else
( (struct V_130 * ) & V_117 ) -> V_131 = 0 ;
V_119 = F_72 ( int , V_33 -> V_119 , sizeof( V_117 ) ) ;
memcpy ( & V_118 , & V_33 -> V_132 , V_119 ) ;
V_115 = L_10 ;
V_74 = F_73 ( & V_133 , ( (struct V_126 * ) & V_117 ) -> V_127 ,
V_134 , V_135 , & V_81 ) ;
if ( V_74 < 0 ) {
V_81 = NULL ;
goto V_102;
}
V_81 -> V_109 -> V_136 =
V_81 -> V_109 -> V_137 = V_123 * V_39 ;
F_70 ( V_81 , V_121 , V_122 ) ;
V_115 = L_11 ;
V_74 = V_81 -> V_138 -> V_139 ( V_81 , (struct V_126 * ) & V_117 , V_120 ) ;
if ( V_74 < 0 )
goto V_102;
V_124 = 0 ;
V_115 = L_12 ;
V_74 = V_81 -> V_138 -> V_140 ( V_81 , (struct V_126 * ) & V_118 , V_119 , 0 ) ;
V_102:
if ( V_74 < 0 ) {
if ( V_81 ) {
F_74 ( V_81 ) ;
V_81 = NULL ;
}
switch ( - V_74 ) {
case V_141 : case V_142 : case V_143 :
case V_144 : case V_96 :
case V_145 : case V_146 :
case V_147 : case V_148 :
V_124 = 0 ;
break;
default:
F_41 ( V_33 , L_13 , V_115 , V_74 ) ;
}
if ( V_124 )
F_66 ( V_33 , F_67 ( V_103 , V_149 ) , V_105 ) ;
}
return V_81 ;
}
static void F_75 ( struct V_81 * V_109 )
{
struct V_150 * V_151 = V_109 -> V_152 ;
void (* F_76)( struct V_81 * V_109 );
F_76 = V_151 -> V_153 ;
if ( V_109 -> V_154 == V_155 )
F_77 ( & V_151 -> V_156 ) ;
F_76 ( V_109 ) ;
}
static int F_78 ( struct V_92 * V_33 , struct V_150 * V_151 )
{
int V_74 , V_121 , V_122 , V_120 ;
struct V_116 V_125 ;
struct V_80 * V_157 ;
struct V_29 * V_30 ;
const char * V_115 ;
F_25 () ;
V_30 = F_26 ( V_33 -> V_29 ) ;
if ( ! V_30 ) {
F_27 () ;
return - V_106 ;
}
V_121 = V_30 -> V_121 ;
V_122 = V_30 -> V_122 ;
F_27 () ;
V_120 = F_72 ( int , V_33 -> V_120 , sizeof( struct V_116 ) ) ;
memcpy ( & V_125 , & V_33 -> V_125 , V_120 ) ;
V_115 = L_10 ;
V_74 = F_73 ( & V_133 , ( (struct V_126 * ) & V_125 ) -> V_127 ,
V_134 , V_135 , & V_157 ) ;
if ( V_74 ) {
V_157 = NULL ;
goto V_102;
}
V_157 -> V_109 -> V_158 = V_159 ;
F_70 ( V_157 , V_121 , V_122 ) ;
V_115 = L_14 ;
V_74 = V_157 -> V_138 -> V_139 ( V_157 , (struct V_126 * ) & V_125 , V_120 ) ;
if ( V_74 < 0 )
goto V_102;
V_151 -> V_157 = V_157 ;
F_79 ( & V_157 -> V_109 -> V_160 ) ;
V_151 -> V_153 = V_157 -> V_109 -> V_161 ;
V_157 -> V_109 -> V_161 = F_75 ;
V_157 -> V_109 -> V_152 = V_151 ;
F_80 ( & V_157 -> V_109 -> V_160 ) ;
V_115 = L_15 ;
V_74 = V_157 -> V_138 -> V_162 ( V_157 , 5 ) ;
if ( V_74 < 0 )
goto V_102;
return 0 ;
V_102:
if ( V_157 )
F_74 ( V_157 ) ;
if ( V_74 < 0 ) {
if ( V_74 != - V_142 && V_74 != - V_144 && V_74 != - V_96 ) {
F_41 ( V_33 , L_13 , V_115 , V_74 ) ;
F_66 ( V_33 , F_67 ( V_103 , V_149 ) , V_105 ) ;
}
}
return - V_106 ;
}
static void F_81 ( struct V_81 * V_109 , struct V_150 * V_151 )
{
F_79 ( & V_109 -> V_160 ) ;
V_109 -> V_161 = V_151 -> V_153 ;
V_109 -> V_152 = NULL ;
F_80 ( & V_109 -> V_160 ) ;
}
static struct V_80 * F_82 ( struct V_92 * V_33 , struct V_150 * V_151 )
{
int V_163 , V_123 , V_74 = 0 ;
struct V_80 * V_164 = NULL ;
struct V_29 * V_30 ;
F_25 () ;
V_30 = F_26 ( V_33 -> V_29 ) ;
if ( ! V_30 ) {
F_27 () ;
return NULL ;
}
V_123 = V_30 -> V_123 ;
F_27 () ;
V_163 = V_123 * V_39 ;
V_163 += ( F_83 () & 1 ) ? V_163 / 7 : - V_163 / 7 ;
V_74 = F_84 ( & V_151 -> V_156 , V_163 ) ;
if ( V_74 <= 0 )
return NULL ;
V_74 = F_85 ( V_151 -> V_157 , & V_164 , 0 ) ;
if ( V_74 < 0 ) {
if ( V_74 != - V_142 && V_74 != - V_144 && V_74 != - V_96 ) {
F_41 ( V_33 , L_16 , V_74 ) ;
F_66 ( V_33 , F_67 ( V_103 , V_149 ) , V_105 ) ;
}
}
if ( V_164 )
F_81 ( V_164 -> V_109 , V_151 ) ;
return V_164 ;
}
static int F_86 ( struct V_92 * V_33 , struct V_165 * V_81 ,
enum V_166 V_167 )
{
if ( ! F_87 ( V_33 , V_81 ) )
return - V_106 ;
return F_88 ( V_33 , V_81 , V_167 , 0 , NULL , 0 ) ;
}
static int F_89 ( struct V_92 * V_33 , struct V_80 * V_81 )
{
unsigned int V_168 = F_90 ( V_33 ) ;
struct V_169 V_170 ;
struct V_29 * V_30 ;
int V_74 ;
F_25 () ;
V_30 = F_26 ( V_33 -> V_29 ) ;
if ( ! V_30 ) {
F_27 () ;
return - V_106 ;
}
V_81 -> V_109 -> V_136 = V_30 -> V_98 * 4 * V_39 / 10 ;
F_27 () ;
V_74 = F_60 ( V_81 , V_33 -> V_94 . V_171 , V_168 , 0 ) ;
if ( V_74 != V_168 ) {
if ( V_74 >= 0 )
V_74 = - V_106 ;
return V_74 ;
}
V_74 = F_91 ( V_33 , V_33 -> V_94 . V_171 , & V_170 ) ;
if ( V_74 )
return V_74 ;
return V_170 . V_167 ;
}
static bool F_92 ( struct V_80 * * V_81 )
{
int V_172 ;
char V_173 [ 4 ] ;
if ( ! * V_81 )
return false ;
V_172 = F_60 ( * V_81 , V_173 , 4 , V_174 | V_175 ) ;
if ( V_172 > 0 || V_172 == - V_142 ) {
return true ;
} else {
F_74 ( * V_81 ) ;
* V_81 = NULL ;
return false ;
}
}
static bool F_93 ( struct V_92 * V_33 ,
struct V_80 * * V_176 ,
struct V_80 * * V_177 )
{
struct V_29 * V_30 ;
int V_178 ;
bool V_179 ;
if ( ! * V_176 || ! * V_177 )
return false ;
F_25 () ;
V_30 = F_26 ( V_33 -> V_29 ) ;
V_178 = ( V_30 -> V_180 ? : V_30 -> V_98 ) * V_39 / 10 ;
F_27 () ;
F_94 ( V_178 ) ;
V_179 = F_92 ( V_176 ) ;
V_179 = F_92 ( V_177 ) && V_179 ;
return V_179 ;
}
int F_95 ( struct V_26 * V_27 )
{
struct V_9 * V_10 = V_27 -> V_10 ;
int V_74 ;
F_96 ( & V_10 -> V_181 , 0 ) ;
V_10 -> V_182 = 0 ;
V_10 -> V_183 = V_27 -> V_33 -> V_184 < 100 ?
& V_27 -> V_33 -> V_185 :
& V_10 -> V_186 ;
V_74 = F_97 ( V_27 ) ;
if ( ! V_74 )
V_74 = F_98 ( V_27 , 0 , 0 ) ;
if ( ! V_74 )
V_74 = F_99 ( V_27 ) ;
if ( ! V_74 )
V_74 = F_100 ( V_27 ) ;
F_101 ( V_187 , & V_10 -> V_66 ) ;
F_101 ( V_188 , & V_10 -> V_66 ) ;
F_96 ( & V_10 -> V_189 , 0 ) ;
F_102 ( & V_10 -> V_190 , V_63 + V_39 ) ;
return V_74 ;
}
static int F_103 ( struct V_92 * V_33 )
{
struct V_165 V_81 , V_191 ;
struct V_26 * V_27 ;
struct V_29 * V_30 ;
int V_192 , V_178 , V_193 ;
bool V_194 , V_179 ;
enum V_195 V_93 ;
struct V_150 V_151 = {
. V_33 = V_33 ,
. V_156 = F_104 ( V_151 . V_156 ) ,
} ;
F_101 ( V_97 , & V_33 -> V_66 ) ;
if ( F_66 ( V_33 , F_67 ( V_103 , V_196 ) , V_197 ) < V_198 )
return - 2 ;
F_105 ( & V_81 . V_199 ) ;
V_81 . V_200 = V_33 -> V_94 . V_200 ;
V_81 . V_171 = V_33 -> V_94 . V_171 ;
V_81 . V_80 = NULL ;
F_105 ( & V_191 . V_199 ) ;
V_191 . V_200 = V_33 -> V_201 . V_200 ;
V_191 . V_171 = V_33 -> V_201 . V_171 ;
V_191 . V_80 = NULL ;
V_33 -> V_184 = 80 ;
if ( F_78 ( V_33 , & V_151 ) )
return 0 ;
do {
struct V_80 * V_202 ;
V_202 = F_71 ( V_33 ) ;
if ( V_202 ) {
if ( ! V_81 . V_80 ) {
V_81 . V_80 = V_202 ;
F_86 ( V_33 , & V_81 , V_203 ) ;
} else if ( ! V_191 . V_80 ) {
F_101 ( V_204 , & V_33 -> V_66 ) ;
V_191 . V_80 = V_202 ;
F_86 ( V_33 , & V_191 , V_205 ) ;
} else {
F_41 ( V_33 , L_17 ) ;
goto V_206;
}
}
if ( F_93 ( V_33 , & V_81 . V_80 , & V_191 . V_80 ) )
break;
V_28:
V_202 = F_82 ( V_33 , & V_151 ) ;
if ( V_202 ) {
int V_207 = F_89 ( V_33 , V_202 ) ;
F_92 ( & V_81 . V_80 ) ;
F_92 ( & V_191 . V_80 ) ;
switch ( V_207 ) {
case V_203 :
if ( V_81 . V_80 ) {
F_31 ( V_33 , L_18 ) ;
F_74 ( V_81 . V_80 ) ;
V_81 . V_80 = V_202 ;
goto V_208;
}
V_81 . V_80 = V_202 ;
break;
case V_205 :
F_106 ( V_204 , & V_33 -> V_66 ) ;
if ( V_191 . V_80 ) {
F_31 ( V_33 , L_19 ) ;
F_74 ( V_191 . V_80 ) ;
V_191 . V_80 = V_202 ;
goto V_208;
}
V_191 . V_80 = V_202 ;
break;
default:
F_31 ( V_33 , L_20 ) ;
F_74 ( V_202 ) ;
V_208:
if ( F_83 () & 1 )
goto V_28;
}
}
if ( V_33 -> V_100 <= V_149 )
goto V_206;
if ( F_30 ( V_38 ) ) {
F_107 ( V_38 ) ;
F_108 () ;
if ( F_109 ( & V_33 -> V_209 ) == V_210 )
goto V_206;
}
V_179 = F_93 ( V_33 , & V_81 . V_80 , & V_191 . V_80 ) ;
} while ( ! V_179 );
if ( V_151 . V_157 )
F_74 ( V_151 . V_157 ) ;
V_81 . V_80 -> V_109 -> V_158 = V_159 ;
V_191 . V_80 -> V_109 -> V_158 = V_159 ;
V_81 . V_80 -> V_109 -> V_211 = V_212 ;
V_191 . V_80 -> V_109 -> V_211 = V_212 ;
V_81 . V_80 -> V_109 -> V_213 = V_214 ;
V_191 . V_80 -> V_109 -> V_213 = V_215 ;
F_25 () ;
V_30 = F_26 ( V_33 -> V_29 ) ;
V_81 . V_80 -> V_109 -> V_137 =
V_81 . V_80 -> V_109 -> V_136 = V_30 -> V_98 * 4 * V_39 / 10 ;
V_191 . V_80 -> V_109 -> V_136 = V_30 -> V_216 * V_39 ;
V_178 = V_30 -> V_178 * V_39 / 10 ;
V_194 = V_30 -> V_194 ;
F_27 () ;
V_191 . V_80 -> V_109 -> V_137 = V_178 ;
F_110 ( V_81 . V_80 ) ;
F_110 ( V_191 . V_80 ) ;
V_33 -> V_94 . V_80 = V_81 . V_80 ;
V_33 -> V_201 . V_80 = V_191 . V_80 ;
V_33 -> V_217 = V_63 ;
V_193 = F_111 ( V_33 ) ;
if ( V_193 <= 0 )
return V_193 ;
if ( V_33 -> V_218 ) {
switch ( F_112 ( V_33 ) ) {
case - 1 :
F_41 ( V_33 , L_21 ) ;
return - 1 ;
case 0 :
F_41 ( V_33 , L_22 ) ;
return 0 ;
}
}
V_33 -> V_94 . V_80 -> V_109 -> V_137 = V_178 ;
V_33 -> V_94 . V_80 -> V_109 -> V_136 = V_219 ;
if ( F_113 ( V_33 ) == - V_220 )
return - 1 ;
F_114 (&connection->peer_devices, peer_device, vnr)
F_115 ( V_27 -> V_10 -> V_183 ) ;
F_106 ( V_221 , & V_33 -> V_66 ) ;
F_114 (&connection->peer_devices, peer_device, vnr)
F_116 ( V_27 -> V_10 -> V_183 ) ;
F_25 () ;
F_114 (&connection->peer_devices, peer_device, vnr) {
struct V_9 * V_10 = V_27 -> V_10 ;
F_117 ( & V_10 -> V_222 ) ;
F_27 () ;
if ( V_194 )
F_106 ( V_223 , & V_10 -> V_66 ) ;
else
F_101 ( V_223 , & V_10 -> V_66 ) ;
F_95 ( V_27 ) ;
F_118 ( & V_10 -> V_222 , V_224 ) ;
F_25 () ;
}
F_27 () ;
V_93 = F_66 ( V_33 , F_67 ( V_103 , V_101 ) , V_197 ) ;
if ( V_93 < V_198 || V_33 -> V_100 != V_101 ) {
F_101 ( V_221 , & V_33 -> V_66 ) ;
return 0 ;
}
F_119 ( & V_33 -> V_225 ) ;
F_115 ( & V_33 -> V_24 -> V_226 ) ;
V_33 -> V_29 -> V_194 = 0 ;
F_116 ( & V_33 -> V_24 -> V_226 ) ;
return V_193 ;
V_206:
if ( V_151 . V_157 )
F_74 ( V_151 . V_157 ) ;
if ( V_81 . V_80 )
F_74 ( V_81 . V_80 ) ;
if ( V_191 . V_80 )
F_74 ( V_191 . V_80 ) ;
return - 1 ;
}
static int F_91 ( struct V_92 * V_33 , void * V_227 , struct V_169 * V_170 )
{
unsigned int V_168 = F_90 ( V_33 ) ;
if ( V_168 == sizeof( struct V_228 ) &&
* ( V_229 * ) V_227 == F_120 ( V_230 ) ) {
struct V_228 * V_193 = V_227 ;
if ( V_193 -> V_231 != 0 ) {
F_41 ( V_33 , L_23 ) ;
return - V_232 ;
}
V_170 -> V_192 = F_121 ( V_193 -> V_233 ) ;
V_170 -> V_167 = F_121 ( V_193 -> V_234 ) ;
V_170 -> V_61 = F_122 ( V_193 -> V_235 ) ;
} else if ( V_168 == sizeof( struct V_236 ) &&
* ( V_237 * ) V_227 == F_123 ( V_238 ) ) {
struct V_236 * V_193 = V_227 ;
V_170 -> V_167 = F_121 ( V_193 -> V_234 ) ;
V_170 -> V_61 = F_122 ( V_193 -> V_235 ) ;
V_170 -> V_192 = 0 ;
} else if ( V_168 == sizeof( struct V_239 ) &&
* ( V_229 * ) V_227 == F_120 ( V_240 ) ) {
struct V_239 * V_193 = V_227 ;
V_170 -> V_167 = F_121 ( V_193 -> V_234 ) ;
V_170 -> V_61 = F_121 ( V_193 -> V_235 ) ;
V_170 -> V_192 = 0 ;
} else {
F_41 ( V_33 , L_24 ,
F_122 ( * ( V_229 * ) V_227 ) ,
V_33 -> V_184 ) ;
return - V_232 ;
}
V_170 -> V_94 = V_227 + V_168 ;
return 0 ;
}
static int F_124 ( struct V_92 * V_33 , struct V_169 * V_170 )
{
void * V_241 = V_33 -> V_94 . V_171 ;
int V_74 ;
V_74 = F_69 ( V_33 , V_241 , F_90 ( V_33 ) ) ;
if ( V_74 )
return V_74 ;
V_74 = F_91 ( V_33 , V_241 , V_170 ) ;
V_33 -> V_217 = V_63 ;
return V_74 ;
}
static void F_125 ( struct V_92 * V_33 )
{
int V_93 ;
struct V_26 * V_27 ;
int V_192 ;
if ( V_33 -> V_24 -> V_242 >= V_243 ) {
F_25 () ;
F_114 (&connection->peer_devices, peer_device, vnr) {
struct V_9 * V_10 = V_27 -> V_10 ;
if ( ! F_126 ( V_10 ) )
continue;
F_117 ( & V_10 -> V_222 ) ;
F_27 () ;
V_10 -> V_244 = V_63 ;
F_106 ( V_245 , & V_10 -> V_66 ) ;
V_93 = F_127 ( V_10 -> V_246 -> V_247 ,
V_212 , NULL ) ;
F_101 ( V_245 , & V_10 -> V_66 ) ;
if ( V_93 ) {
F_63 ( V_10 , L_25 , V_93 ) ;
F_128 ( V_33 -> V_24 , NULL , V_248 ) ;
}
F_129 ( V_10 ) ;
F_118 ( & V_10 -> V_222 , V_224 ) ;
F_25 () ;
if ( V_93 )
break;
}
F_27 () ;
}
}
static enum V_249 F_130 ( struct V_92 * V_33 ,
struct V_250 * V_251 ,
enum V_252 V_253 )
{
int V_254 ;
struct V_250 * V_255 ;
enum V_249 V_93 = V_256 ;
F_11 ( & V_33 -> V_257 ) ;
do {
V_255 = NULL ;
V_254 = F_28 ( & V_251 -> V_254 ) ;
switch ( V_253 & ~ V_258 ) {
case V_259 :
F_131 ( & V_251 -> V_260 ) ;
break;
case V_261 :
F_106 ( V_262 , & V_251 -> V_66 ) ;
break;
case V_263 :
break;
}
if ( V_254 != 0 &&
F_28 ( & V_251 -> V_260 ) == 0 &&
( F_64 ( V_262 , & V_251 -> V_66 ) || V_253 & V_258 ) ) {
if ( ! ( V_253 & V_258 ) ) {
F_12 ( & V_33 -> V_257 ) ;
F_132 ( V_251 -> V_33 , V_251 -> V_264 , V_254 ) ;
F_11 ( & V_33 -> V_257 ) ;
}
#if 0
if (test_bit(DE_HAVE_BARRIER_NUMBER, &epoch->flags))
dec_unacked(epoch->connection);
#endif
if ( V_33 -> V_265 != V_251 ) {
V_255 = F_133 ( V_251 -> V_21 . V_266 , struct V_250 , V_21 ) ;
F_134 ( & V_251 -> V_21 ) ;
V_253 = V_263 | ( V_253 & V_258 ) ;
V_33 -> V_267 -- ;
F_47 ( V_251 ) ;
if ( V_93 == V_256 )
V_93 = V_268 ;
} else {
V_251 -> V_66 = 0 ;
F_96 ( & V_251 -> V_254 , 0 ) ;
if ( V_93 == V_256 )
V_93 = V_269 ;
}
}
if ( ! V_255 )
break;
V_251 = V_255 ;
} while ( 1 );
F_12 ( & V_33 -> V_257 ) ;
return V_93 ;
}
static enum V_270
F_135 ( struct V_271 * V_272 , enum V_270 V_273 )
{
struct V_274 * V_275 ;
V_275 = F_26 ( V_272 -> V_274 ) ;
if ( V_273 == V_243 && ! V_275 -> V_276 )
V_273 = V_248 ;
if ( V_273 == V_248 && ! V_275 -> V_277 )
V_273 = V_278 ;
return V_273 ;
}
void F_128 ( struct V_279 * V_24 , struct V_271 * V_272 ,
enum V_270 V_273 )
{
struct V_9 * V_10 ;
enum V_270 V_280 ;
int V_192 ;
static char * V_281 [] = {
[ V_278 ] = L_26 ,
[ V_248 ] = L_27 ,
[ V_243 ] = L_28 ,
} ;
V_280 = V_24 -> V_242 ;
if ( V_273 != V_243 )
V_273 = F_136 ( V_280 , V_273 ) ;
F_25 () ;
F_114 (&resource->devices, device, vnr) {
if ( F_126 ( V_10 ) ) {
V_273 = F_135 ( V_10 -> V_246 , V_273 ) ;
if ( V_10 -> V_246 == V_272 )
V_272 = NULL ;
F_129 ( V_10 ) ;
}
}
if ( V_272 )
V_273 = F_135 ( V_272 , V_273 ) ;
F_27 () ;
V_24 -> V_242 = V_273 ;
if ( V_280 != V_24 -> V_242 || V_273 == V_243 )
F_63 ( V_24 , L_29 , V_281 [ V_24 -> V_242 ] ) ;
}
int F_137 ( struct V_9 * V_10 ,
struct V_18 * V_19 ,
const unsigned V_282 , const int V_283 )
{
struct V_284 * V_285 = NULL ;
struct V_284 * V_284 ;
struct V_1 * V_1 = V_19 -> V_64 ;
T_3 V_48 = V_19 -> V_6 . V_48 ;
unsigned V_49 = V_19 -> V_6 . V_61 ;
unsigned V_286 = 0 ;
unsigned V_52 = ( V_49 + V_45 - 1 ) >> V_53 ;
int V_74 = - V_287 ;
if ( V_19 -> V_66 & V_288 ) {
F_138 ( F_139 ( V_10 ) -> V_33 ) ;
V_19 -> V_62 = V_63 ;
V_19 -> V_66 |= V_289 ;
F_20 ( & V_10 -> V_24 -> V_25 ) ;
F_140 ( & V_19 -> V_20 . V_21 , & V_10 -> V_290 ) ;
F_21 ( & V_10 -> V_24 -> V_25 ) ;
if ( F_141 ( V_10 -> V_246 -> V_247 ,
V_48 , V_49 >> 9 , V_212 , false ) )
V_19 -> V_66 |= V_291 ;
F_142 ( V_19 ) ;
return 0 ;
}
if ( V_19 -> V_66 & V_292 )
V_52 = 1 ;
V_293:
V_284 = F_143 ( V_212 , V_52 ) ;
if ( ! V_284 ) {
F_41 ( V_10 , L_30 , V_52 ) ;
goto V_60;
}
V_284 -> V_294 . V_295 = V_48 ;
V_284 -> V_296 = V_10 -> V_246 -> V_247 ;
V_284 -> V_297 = V_282 ;
V_284 -> V_298 = V_19 ;
V_284 -> V_299 = V_300 ;
V_284 -> V_301 = V_285 ;
V_285 = V_284 ;
++ V_286 ;
if ( V_282 & V_302 ) {
V_284 -> V_294 . V_303 = V_49 ;
goto V_304;
}
F_144 (page) {
unsigned V_5 = F_72 ( unsigned , V_49 , V_45 ) ;
if ( ! F_145 ( V_284 , V_1 , V_5 , 0 ) ) {
if ( V_284 -> V_305 == 0 ) {
F_41 ( V_10 ,
L_31
L_32 ,
V_5 , ( V_306 ) V_284 -> V_294 . V_295 ) ;
V_74 = - V_307 ;
goto V_60;
}
goto V_293;
}
V_49 -= V_5 ;
V_48 += V_5 >> 9 ;
-- V_52 ;
}
F_48 ( V_10 , V_49 == 0 ) ;
V_304:
F_48 ( V_10 , V_1 == NULL ) ;
F_96 ( & V_19 -> V_69 , V_286 ) ;
V_19 -> V_62 = V_63 ;
V_19 -> V_66 |= V_289 ;
do {
V_284 = V_285 ;
V_285 = V_285 -> V_301 ;
V_284 -> V_301 = NULL ;
F_146 ( V_10 , V_283 , V_284 ) ;
} while ( V_285 );
return 0 ;
V_60:
while ( V_285 ) {
V_284 = V_285 ;
V_285 = V_285 -> V_301 ;
F_147 ( V_284 ) ;
}
return V_74 ;
}
static void F_148 ( struct V_9 * V_10 ,
struct V_18 * V_19 )
{
struct V_308 * V_6 = & V_19 -> V_6 ;
F_149 ( & V_10 -> V_309 , V_6 ) ;
F_43 ( V_6 ) ;
if ( V_6 -> V_310 )
F_37 ( & V_10 -> V_311 ) ;
}
static void F_138 ( struct V_92 * V_33 )
{
struct V_26 * V_27 ;
int V_192 ;
F_25 () ;
F_114 (&connection->peer_devices, peer_device, vnr) {
struct V_9 * V_10 = V_27 -> V_10 ;
F_117 ( & V_10 -> V_222 ) ;
F_27 () ;
F_59 ( V_10 , & V_10 -> V_290 ) ;
F_118 ( & V_10 -> V_222 , V_224 ) ;
F_25 () ;
}
F_27 () ;
}
static struct V_26 *
F_150 ( struct V_92 * V_33 , int V_312 )
{
return F_151 ( & V_33 -> V_313 , V_312 ) ;
}
static int F_152 ( struct V_92 * V_33 , struct V_169 * V_170 )
{
int V_93 ;
struct V_314 * V_315 = V_170 -> V_94 ;
struct V_250 * V_251 ;
V_33 -> V_265 -> V_264 = V_315 -> V_316 ;
V_33 -> V_265 -> V_33 = V_33 ;
V_93 = F_130 ( V_33 , V_33 -> V_265 , V_261 ) ;
switch ( V_33 -> V_24 -> V_242 ) {
case V_278 :
if ( V_93 == V_269 )
return 0 ;
V_251 = F_153 ( sizeof( struct V_250 ) , V_212 ) ;
if ( V_251 )
break;
else
F_31 ( V_33 , L_33 ) ;
case V_243 :
case V_248 :
F_138 ( V_33 ) ;
F_125 ( V_33 ) ;
if ( F_28 ( & V_33 -> V_265 -> V_254 ) ) {
V_251 = F_153 ( sizeof( struct V_250 ) , V_212 ) ;
if ( V_251 )
break;
}
return 0 ;
default:
F_41 ( V_33 , L_34 ,
V_33 -> V_24 -> V_242 ) ;
return - V_106 ;
}
V_251 -> V_66 = 0 ;
F_96 ( & V_251 -> V_254 , 0 ) ;
F_96 ( & V_251 -> V_260 , 0 ) ;
F_11 ( & V_33 -> V_257 ) ;
if ( F_28 ( & V_33 -> V_265 -> V_254 ) ) {
F_154 ( & V_251 -> V_21 , & V_33 -> V_265 -> V_21 ) ;
V_33 -> V_265 = V_251 ;
V_33 -> V_267 ++ ;
} else {
F_47 ( V_251 ) ;
}
F_12 ( & V_33 -> V_257 ) ;
return 0 ;
}
static struct V_18 *
F_155 ( struct V_26 * V_27 , T_2 V_47 , T_3 V_48 ,
struct V_169 * V_170 ) __must_hold( T_5 )
{
struct V_9 * V_10 = V_27 -> V_10 ;
const T_3 V_317 = F_156 ( V_10 -> V_318 ) ;
struct V_18 * V_19 ;
struct V_1 * V_1 ;
int V_319 , V_74 ;
unsigned int V_49 = V_170 -> V_61 , V_320 ;
void * V_321 = V_27 -> V_33 -> V_322 ;
void * V_323 = V_27 -> V_33 -> V_324 ;
unsigned long * V_94 ;
struct V_325 * V_326 = ( V_170 -> V_167 == V_327 ) ? V_170 -> V_94 : NULL ;
V_319 = 0 ;
if ( ! V_326 && V_27 -> V_33 -> V_328 ) {
V_319 = F_157 ( V_27 -> V_33 -> V_328 ) ;
V_74 = F_69 ( V_27 -> V_33 , V_321 , V_319 ) ;
if ( V_74 )
return NULL ;
V_49 -= V_319 ;
}
if ( V_326 ) {
F_48 ( V_27 , V_49 == 0 ) ;
V_49 = F_122 ( V_326 -> V_61 ) ;
}
if ( ! F_50 ( F_158 ( V_49 , 512 ) ) )
return NULL ;
if ( ! V_326 && ! F_50 ( V_49 <= V_44 ) )
return NULL ;
if ( V_48 + ( V_49 >> 9 ) > V_317 ) {
F_41 ( V_10 , L_35
L_36 ,
( unsigned long long ) V_317 ,
( unsigned long long ) V_48 , V_49 ) ;
return NULL ;
}
V_19 = F_38 ( V_27 , V_47 , V_48 , V_49 , V_326 == NULL , V_212 ) ;
if ( ! V_19 )
return NULL ;
V_19 -> V_66 |= V_329 ;
if ( V_326 )
return V_19 ;
V_320 = V_49 ;
V_1 = V_19 -> V_64 ;
F_144 (page) {
unsigned V_5 = F_72 ( int , V_320 , V_45 ) ;
V_94 = F_159 ( V_1 ) ;
V_74 = F_69 ( V_27 -> V_33 , V_94 , V_5 ) ;
if ( F_39 ( V_10 , V_330 ) ) {
F_41 ( V_10 , L_37 ) ;
V_94 [ 0 ] = V_94 [ 0 ] ^ ( unsigned long ) - 1 ;
}
F_160 ( V_1 ) ;
if ( V_74 ) {
F_55 ( V_10 , V_19 ) ;
return NULL ;
}
V_320 -= V_5 ;
}
if ( V_319 ) {
F_161 ( V_27 -> V_33 -> V_328 , V_19 , V_323 ) ;
if ( memcmp ( V_321 , V_323 , V_319 ) ) {
F_41 ( V_10 , L_38 ,
( unsigned long long ) V_48 , V_49 ) ;
F_55 ( V_10 , V_19 ) ;
return NULL ;
}
}
V_10 -> V_331 += V_49 >> 9 ;
return V_19 ;
}
static int F_162 ( struct V_26 * V_27 , int V_49 )
{
struct V_1 * V_1 ;
int V_74 = 0 ;
void * V_94 ;
if ( ! V_49 )
return 0 ;
V_1 = F_23 ( V_27 , 1 , 1 ) ;
V_94 = F_159 ( V_1 ) ;
while ( V_49 ) {
unsigned int V_5 = F_72 ( int , V_49 , V_45 ) ;
V_74 = F_69 ( V_27 -> V_33 , V_94 , V_5 ) ;
if ( V_74 )
break;
V_49 -= V_5 ;
}
F_160 ( V_1 ) ;
F_35 ( V_27 -> V_10 , V_1 , 0 ) ;
return V_74 ;
}
static int F_163 ( struct V_26 * V_27 , struct V_332 * V_333 ,
T_3 V_48 , int V_49 )
{
struct V_334 V_335 ;
struct V_336 V_337 ;
struct V_284 * V_284 ;
int V_319 , V_74 , F_50 ;
void * V_321 = V_27 -> V_33 -> V_322 ;
void * V_323 = V_27 -> V_33 -> V_324 ;
V_319 = 0 ;
if ( V_27 -> V_33 -> V_328 ) {
V_319 = F_157 ( V_27 -> V_33 -> V_328 ) ;
V_74 = F_69 ( V_27 -> V_33 , V_321 , V_319 ) ;
if ( V_74 )
return V_74 ;
V_49 -= V_319 ;
}
V_27 -> V_10 -> V_331 += V_49 >> 9 ;
V_284 = V_333 -> V_338 ;
F_48 ( V_27 -> V_10 , V_48 == V_284 -> V_294 . V_295 ) ;
F_164 (bvec, bio, iter) {
void * V_339 = F_159 ( V_335 . V_340 ) + V_335 . V_341 ;
F_50 = F_72 ( int , V_49 , V_335 . V_342 ) ;
V_74 = F_69 ( V_27 -> V_33 , V_339 , F_50 ) ;
F_160 ( V_335 . V_340 ) ;
if ( V_74 )
return V_74 ;
V_49 -= F_50 ;
}
if ( V_319 ) {
F_165 ( V_27 -> V_33 -> V_328 , V_284 , V_323 ) ;
if ( memcmp ( V_321 , V_323 , V_319 ) ) {
F_41 ( V_27 , L_39 ) ;
return - V_232 ;
}
}
F_48 ( V_27 -> V_10 , V_49 == 0 ) ;
return 0 ;
}
static int F_166 ( struct V_343 * V_20 , int V_344 )
{
struct V_18 * V_19 =
F_167 ( V_20 , struct V_18 , V_20 ) ;
struct V_26 * V_27 = V_19 -> V_27 ;
struct V_9 * V_10 = V_27 -> V_10 ;
T_3 V_48 = V_19 -> V_6 . V_48 ;
int V_74 ;
F_48 ( V_10 , F_49 ( & V_19 -> V_6 ) ) ;
if ( F_168 ( ( V_19 -> V_66 & V_291 ) == 0 ) ) {
F_169 ( V_10 , V_48 , V_19 -> V_6 . V_61 ) ;
V_74 = F_170 ( V_27 , V_345 , V_19 ) ;
} else {
F_171 ( V_10 , V_48 , V_19 -> V_6 . V_61 ) ;
V_74 = F_170 ( V_27 , V_346 , V_19 ) ;
}
F_172 ( V_10 ) ;
return V_74 ;
}
static int F_173 ( struct V_26 * V_27 , T_3 V_48 ,
struct V_169 * V_170 ) __releases( T_5 )
{
struct V_9 * V_10 = V_27 -> V_10 ;
struct V_18 * V_19 ;
V_19 = F_155 ( V_27 , V_347 , V_48 , V_170 ) ;
if ( ! V_19 )
goto V_60;
F_174 ( V_10 ) ;
F_175 ( V_10 ) ;
V_19 -> V_20 . V_77 = F_166 ;
V_19 -> V_62 = V_63 ;
F_20 ( & V_10 -> V_24 -> V_25 ) ;
F_140 ( & V_19 -> V_20 . V_21 , & V_10 -> V_348 ) ;
F_21 ( & V_10 -> V_24 -> V_25 ) ;
F_34 ( V_170 -> V_61 >> 9 , & V_10 -> V_349 ) ;
if ( F_137 ( V_10 , V_19 , V_350 , V_351 ) == 0 )
return 0 ;
F_41 ( V_10 , L_40 ) ;
F_20 ( & V_10 -> V_24 -> V_25 ) ;
F_134 ( & V_19 -> V_20 . V_21 ) ;
F_21 ( & V_10 -> V_24 -> V_25 ) ;
F_55 ( V_10 , V_19 ) ;
V_60:
F_129 ( V_10 ) ;
return - V_106 ;
}
static struct V_332 *
F_176 ( struct V_9 * V_10 , struct V_352 * V_353 , T_2 V_47 ,
T_3 V_48 , bool V_354 , const char * V_355 )
{
struct V_332 * V_333 ;
V_333 = (struct V_332 * ) ( unsigned long ) V_47 ;
if ( F_177 ( V_353 , V_48 , & V_333 -> V_6 ) && V_333 -> V_6 . T_5 )
return V_333 ;
if ( ! V_354 ) {
F_41 ( V_10 , L_41 , V_355 ,
( unsigned long ) V_47 , ( unsigned long long ) V_48 ) ;
}
return NULL ;
}
static int F_178 ( struct V_92 * V_33 , struct V_169 * V_170 )
{
struct V_26 * V_27 ;
struct V_9 * V_10 ;
struct V_332 * V_333 ;
T_3 V_48 ;
int V_74 ;
struct V_356 * V_315 = V_170 -> V_94 ;
V_27 = F_150 ( V_33 , V_170 -> V_192 ) ;
if ( ! V_27 )
return - V_106 ;
V_10 = V_27 -> V_10 ;
V_48 = F_179 ( V_315 -> V_48 ) ;
F_20 ( & V_10 -> V_24 -> V_25 ) ;
V_333 = F_176 ( V_10 , & V_10 -> V_357 , V_315 -> V_65 , V_48 , false , V_58 ) ;
F_21 ( & V_10 -> V_24 -> V_25 ) ;
if ( F_180 ( ! V_333 ) )
return - V_106 ;
V_74 = F_163 ( V_27 , V_333 , V_48 , V_170 -> V_61 ) ;
if ( ! V_74 )
F_181 ( V_333 , V_358 ) ;
return V_74 ;
}
static int F_182 ( struct V_92 * V_33 , struct V_169 * V_170 )
{
struct V_26 * V_27 ;
struct V_9 * V_10 ;
T_3 V_48 ;
int V_74 ;
struct V_356 * V_315 = V_170 -> V_94 ;
V_27 = F_150 ( V_33 , V_170 -> V_192 ) ;
if ( ! V_27 )
return - V_106 ;
V_10 = V_27 -> V_10 ;
V_48 = F_179 ( V_315 -> V_48 ) ;
F_48 ( V_10 , V_315 -> V_65 == V_347 ) ;
if ( F_126 ( V_10 ) ) {
V_74 = F_173 ( V_27 , V_48 , V_170 ) ;
} else {
if ( F_183 ( & V_359 ) )
F_41 ( V_10 , L_42 ) ;
V_74 = F_162 ( V_27 , V_170 -> V_61 ) ;
F_184 ( V_27 , V_346 , V_315 , V_170 -> V_61 ) ;
}
F_34 ( V_170 -> V_61 >> 9 , & V_10 -> V_360 ) ;
return V_74 ;
}
static void F_185 ( struct V_9 * V_10 ,
T_3 V_48 , int V_61 )
{
struct V_308 * V_6 ;
struct V_332 * V_333 ;
F_186 (i, &device->write_requests, sector, size) {
if ( ! V_6 -> T_5 )
continue;
V_333 = F_167 ( V_6 , struct V_332 , V_6 ) ;
if ( V_333 -> V_361 & V_362 ||
! ( V_333 -> V_361 & V_363 ) )
continue;
F_187 ( V_333 , V_364 , NULL ) ;
}
}
static int F_188 ( struct V_343 * V_20 , int V_365 )
{
struct V_18 * V_19 =
F_167 ( V_20 , struct V_18 , V_20 ) ;
struct V_26 * V_27 = V_19 -> V_27 ;
struct V_9 * V_10 = V_27 -> V_10 ;
T_3 V_48 = V_19 -> V_6 . V_48 ;
int V_74 = 0 , V_366 ;
if ( V_19 -> V_66 & V_367 ) {
if ( F_168 ( ( V_19 -> V_66 & V_291 ) == 0 ) ) {
V_366 = ( V_10 -> V_368 . V_103 >= V_369 &&
V_10 -> V_368 . V_103 <= V_370 &&
V_19 -> V_66 & V_371 ) ?
V_345 : V_372 ;
V_74 = F_170 ( V_27 , V_366 , V_19 ) ;
if ( V_366 == V_345 )
F_169 ( V_10 , V_48 , V_19 -> V_6 . V_61 ) ;
} else {
V_74 = F_170 ( V_27 , V_346 , V_19 ) ;
}
F_172 ( V_10 ) ;
}
if ( V_19 -> V_66 & V_373 ) {
F_20 ( & V_10 -> V_24 -> V_25 ) ;
F_48 ( V_10 , ! F_49 ( & V_19 -> V_6 ) ) ;
F_148 ( V_10 , V_19 ) ;
if ( V_19 -> V_66 & V_374 )
F_185 ( V_10 , V_48 , V_19 -> V_6 . V_61 ) ;
F_21 ( & V_10 -> V_24 -> V_25 ) ;
} else
F_48 ( V_10 , F_49 ( & V_19 -> V_6 ) ) ;
F_130 ( F_139 ( V_10 ) -> V_33 , V_19 -> V_251 , V_259 + ( V_365 ? V_258 : 0 ) ) ;
return V_74 ;
}
static int F_189 ( struct V_343 * V_20 , enum V_166 V_375 )
{
struct V_18 * V_19 =
F_167 ( V_20 , struct V_18 , V_20 ) ;
struct V_26 * V_27 = V_19 -> V_27 ;
int V_74 ;
V_74 = F_170 ( V_27 , V_375 , V_19 ) ;
F_172 ( V_27 -> V_10 ) ;
return V_74 ;
}
static int F_190 ( struct V_343 * V_20 , int V_344 )
{
return F_189 ( V_20 , V_376 ) ;
}
static int F_191 ( struct V_343 * V_20 , int V_344 )
{
struct V_18 * V_19 =
F_167 ( V_20 , struct V_18 , V_20 ) ;
struct V_92 * V_33 = V_19 -> V_27 -> V_33 ;
return F_189 ( V_20 , V_33 -> V_184 >= 100 ?
V_377 : V_376 ) ;
}
static bool F_192 ( T_7 V_42 , T_7 V_378 )
{
return ( V_379 ) V_42 - ( V_379 ) V_378 > 0 ;
}
static T_7 F_193 ( T_7 V_42 , T_7 V_378 )
{
return F_192 ( V_42 , V_378 ) ? V_42 : V_378 ;
}
static void F_194 ( struct V_26 * V_27 , unsigned int V_182 )
{
struct V_9 * V_10 = V_27 -> V_10 ;
unsigned int V_380 ;
if ( F_64 ( V_204 , & V_27 -> V_33 -> V_66 ) ) {
F_11 ( & V_10 -> V_381 ) ;
V_380 = F_193 ( V_10 -> V_182 , V_182 ) ;
V_10 -> V_182 = V_380 ;
F_12 ( & V_10 -> V_381 ) ;
if ( V_182 == V_380 )
F_37 ( & V_10 -> V_382 ) ;
}
}
static inline int F_195 ( T_3 V_383 , int V_384 , T_3 V_385 , int V_386 )
{
return ! ( ( V_383 + ( V_384 >> 9 ) <= V_385 ) || ( V_383 >= V_385 + ( V_386 >> 9 ) ) ) ;
}
static bool F_196 ( struct V_9 * V_10 , struct V_18 * V_19 )
{
struct V_18 * V_387 ;
bool V_93 = 0 ;
F_20 ( & V_10 -> V_24 -> V_25 ) ;
F_197 (rs_req, &device->sync_ee, w.list) {
if ( F_195 ( V_19 -> V_6 . V_48 , V_19 -> V_6 . V_61 ,
V_387 -> V_6 . V_48 , V_387 -> V_6 . V_61 ) ) {
V_93 = 1 ;
break;
}
}
F_21 ( & V_10 -> V_24 -> V_25 ) ;
return V_93 ;
}
static int F_198 ( struct V_26 * V_27 , const T_7 V_182 )
{
struct V_9 * V_10 = V_27 -> V_10 ;
F_24 ( V_31 ) ;
long V_178 ;
int V_388 = 0 , V_389 ;
if ( ! F_64 ( V_204 , & V_27 -> V_33 -> V_66 ) )
return 0 ;
F_11 ( & V_10 -> V_381 ) ;
for (; ; ) {
if ( ! F_192 ( V_182 - 1 , V_10 -> V_182 ) ) {
V_10 -> V_182 = F_193 ( V_10 -> V_182 , V_182 ) ;
break;
}
if ( F_30 ( V_38 ) ) {
V_388 = - V_96 ;
break;
}
F_25 () ;
V_389 = F_26 ( F_139 ( V_10 ) -> V_33 -> V_29 ) -> V_390 ;
F_27 () ;
if ( ! V_389 )
break;
F_29 ( & V_10 -> V_382 , & V_31 , V_37 ) ;
F_12 ( & V_10 -> V_381 ) ;
F_25 () ;
V_178 = F_26 ( V_27 -> V_33 -> V_29 ) -> V_98 * V_39 / 10 ;
F_27 () ;
V_178 = F_32 ( V_178 ) ;
F_11 ( & V_10 -> V_381 ) ;
if ( ! V_178 ) {
V_388 = - V_141 ;
F_41 ( V_10 , L_43 ) ;
break;
}
}
F_12 ( & V_10 -> V_381 ) ;
F_33 ( & V_10 -> V_382 , & V_31 ) ;
return V_388 ;
}
static unsigned long F_199 ( T_7 V_391 )
{
return ( V_391 & V_392 ? V_393 : 0 ) |
( V_391 & V_394 ? V_395 : 0 ) |
( V_391 & V_396 ? V_397 : 0 ) |
( V_391 & V_398 ? V_302 : 0 ) ;
}
static void F_200 ( struct V_9 * V_10 , T_3 V_48 ,
unsigned int V_61 )
{
struct V_308 * V_6 ;
V_399:
F_186 (i, &device->write_requests, sector, size) {
struct V_332 * V_333 ;
struct V_400 V_401 ;
if ( ! V_6 -> T_5 )
continue;
V_333 = F_167 ( V_6 , struct V_332 , V_6 ) ;
if ( ! ( V_333 -> V_361 & V_363 ) )
continue;
V_333 -> V_361 &= ~ V_363 ;
F_187 ( V_333 , V_402 , & V_401 ) ;
F_21 ( & V_10 -> V_24 -> V_25 ) ;
if ( V_401 . V_284 )
F_201 ( V_10 , & V_401 ) ;
F_20 ( & V_10 -> V_24 -> V_25 ) ;
goto V_399;
}
}
static int F_202 ( struct V_9 * V_10 ,
struct V_18 * V_19 )
{
struct V_92 * V_33 = V_19 -> V_27 -> V_33 ;
bool V_403 = F_64 ( V_204 , & V_33 -> V_66 ) ;
T_3 V_48 = V_19 -> V_6 . V_48 ;
const unsigned int V_61 = V_19 -> V_6 . V_61 ;
struct V_308 * V_6 ;
bool V_404 ;
int V_74 ;
F_203 ( & V_10 -> V_309 , & V_19 -> V_6 ) ;
V_399:
F_186 (i, &device->write_requests, sector, size) {
if ( V_6 == & V_19 -> V_6 )
continue;
if ( V_6 -> V_405 )
continue;
if ( ! V_6 -> T_5 ) {
V_74 = F_204 ( V_10 , V_6 ) ;
if ( V_74 )
goto V_102;
goto V_399;
}
V_404 = V_6 -> V_48 == V_48 && V_6 -> V_61 == V_61 ;
if ( V_403 ) {
bool V_406 = V_6 -> V_48 <= V_48 && V_6 -> V_48 +
( V_6 -> V_61 >> 9 ) >= V_48 + ( V_61 >> 9 ) ;
if ( ! V_404 )
F_205 ( V_10 , L_44
L_45
L_46 ,
( unsigned long long ) V_6 -> V_48 , V_6 -> V_61 ,
( unsigned long long ) V_48 , V_61 ,
V_406 ? L_47 : L_48 ) ;
V_19 -> V_20 . V_77 = V_406 ? F_190 :
F_191 ;
F_140 ( & V_19 -> V_20 . V_21 , & V_10 -> V_75 ) ;
F_206 ( V_33 ) ;
V_74 = - V_407 ;
goto V_102;
} else {
struct V_332 * V_333 =
F_167 ( V_6 , struct V_332 , V_6 ) ;
if ( ! V_404 )
F_205 ( V_10 , L_44
L_49 ,
( unsigned long long ) V_6 -> V_48 , V_6 -> V_61 ,
( unsigned long long ) V_48 , V_61 ) ;
if ( V_333 -> V_361 & V_362 ||
! ( V_333 -> V_361 & V_363 ) ) {
V_74 = F_204 ( V_10 , & V_333 -> V_6 ) ;
if ( V_74 ) {
F_207 ( V_33 , F_67 ( V_103 , V_408 ) , V_105 ) ;
F_200 ( V_10 , V_48 , V_61 ) ;
goto V_102;
}
goto V_399;
}
V_19 -> V_66 |= V_374 ;
}
}
V_74 = 0 ;
V_102:
if ( V_74 )
F_148 ( V_10 , V_19 ) ;
return V_74 ;
}
static int F_208 ( struct V_92 * V_33 , struct V_169 * V_170 )
{
struct V_26 * V_27 ;
struct V_9 * V_10 ;
struct V_29 * V_30 ;
T_3 V_48 ;
struct V_18 * V_19 ;
struct V_356 * V_315 = V_170 -> V_94 ;
T_7 V_182 = F_122 ( V_315 -> V_409 ) ;
int V_282 = V_350 ;
T_7 V_410 ;
int V_74 , V_389 ;
V_27 = F_150 ( V_33 , V_170 -> V_192 ) ;
if ( ! V_27 )
return - V_106 ;
V_10 = V_27 -> V_10 ;
if ( ! F_126 ( V_10 ) ) {
int V_76 ;
V_74 = F_198 ( V_27 , V_182 ) ;
F_184 ( V_27 , V_346 , V_315 , V_170 -> V_61 ) ;
F_209 ( & V_33 -> V_265 -> V_254 ) ;
V_76 = F_162 ( V_27 , V_170 -> V_61 ) ;
if ( ! V_74 )
V_74 = V_76 ;
return V_74 ;
}
V_48 = F_179 ( V_315 -> V_48 ) ;
V_19 = F_155 ( V_27 , V_315 -> V_65 , V_48 , V_170 ) ;
if ( ! V_19 ) {
F_129 ( V_10 ) ;
return - V_106 ;
}
V_19 -> V_20 . V_77 = F_188 ;
V_19 -> V_62 = V_63 ;
V_19 -> V_66 |= V_411 ;
V_410 = F_122 ( V_315 -> V_410 ) ;
V_282 |= F_199 ( V_410 ) ;
if ( V_170 -> V_167 == V_327 ) {
struct V_412 * V_413 = F_210 ( V_10 -> V_246 -> V_247 ) ;
V_19 -> V_66 |= V_292 ;
if ( ! F_211 ( V_413 ) )
V_19 -> V_66 |= V_288 ;
F_48 ( V_27 , V_19 -> V_6 . V_61 > 0 ) ;
F_48 ( V_27 , V_282 & V_302 ) ;
F_48 ( V_27 , V_19 -> V_64 == NULL ) ;
} else if ( V_19 -> V_64 == NULL ) {
F_48 ( V_10 , V_19 -> V_6 . V_61 == 0 ) ;
F_48 ( V_10 , V_410 & V_396 ) ;
}
if ( V_410 & V_414 )
V_19 -> V_66 |= V_371 ;
F_11 ( & V_33 -> V_257 ) ;
V_19 -> V_251 = V_33 -> V_265 ;
F_209 ( & V_19 -> V_251 -> V_254 ) ;
F_209 ( & V_19 -> V_251 -> V_260 ) ;
F_12 ( & V_33 -> V_257 ) ;
F_25 () ;
V_30 = F_26 ( V_27 -> V_33 -> V_29 ) ;
V_389 = V_30 -> V_390 ;
if ( V_27 -> V_33 -> V_184 < 100 ) {
switch ( V_30 -> V_415 ) {
case V_416 :
V_410 |= V_417 ;
break;
case V_418 :
V_410 |= V_419 ;
break;
}
}
F_27 () ;
if ( V_410 & V_417 ) {
V_19 -> V_66 |= V_367 ;
F_175 ( V_10 ) ;
}
if ( V_410 & V_419 ) {
F_170 ( F_139 ( V_10 ) , V_420 , V_19 ) ;
}
if ( V_389 ) {
F_48 ( V_10 , V_410 & V_417 ) ;
V_19 -> V_66 |= V_373 ;
V_74 = F_198 ( V_27 , V_182 ) ;
if ( V_74 )
goto V_421;
F_20 ( & V_10 -> V_24 -> V_25 ) ;
V_74 = F_202 ( V_10 , V_19 ) ;
if ( V_74 ) {
F_21 ( & V_10 -> V_24 -> V_25 ) ;
if ( V_74 == - V_407 ) {
F_129 ( V_10 ) ;
return 0 ;
}
goto V_421;
}
} else {
F_194 ( V_27 , V_182 ) ;
F_20 ( & V_10 -> V_24 -> V_25 ) ;
}
if ( ( V_19 -> V_66 & V_288 ) == 0 )
F_140 ( & V_19 -> V_20 . V_21 , & V_10 -> V_290 ) ;
F_21 ( & V_10 -> V_24 -> V_25 ) ;
if ( V_10 -> V_368 . V_103 == V_422 )
F_212 ( V_10 -> V_78 , ! F_196 ( V_10 , V_19 ) ) ;
if ( V_10 -> V_368 . V_423 < V_424 ) {
F_213 ( V_10 , V_19 -> V_6 . V_48 , V_19 -> V_6 . V_61 ) ;
V_19 -> V_66 &= ~ V_371 ;
F_214 ( V_10 , & V_19 -> V_6 ) ;
V_19 -> V_66 |= V_70 ;
}
V_74 = F_137 ( V_10 , V_19 , V_282 , V_425 ) ;
if ( ! V_74 )
return 0 ;
F_41 ( V_10 , L_40 ) ;
F_20 ( & V_10 -> V_24 -> V_25 ) ;
F_134 ( & V_19 -> V_20 . V_21 ) ;
F_148 ( V_10 , V_19 ) ;
F_21 ( & V_10 -> V_24 -> V_25 ) ;
if ( V_19 -> V_66 & V_70 ) {
V_19 -> V_66 &= ~ V_70 ;
F_51 ( V_10 , & V_19 -> V_6 ) ;
}
V_421:
F_130 ( V_33 , V_19 -> V_251 , V_259 + V_258 ) ;
F_129 ( V_10 ) ;
F_55 ( V_10 , V_19 ) ;
return V_74 ;
}
bool F_215 ( struct V_9 * V_10 , T_3 V_48 ,
bool V_426 )
{
struct V_427 * V_4 ;
bool V_428 = F_216 ( V_10 ) ;
if ( ! V_428 || V_426 )
return V_428 ;
F_20 ( & V_10 -> V_429 ) ;
V_4 = F_217 ( V_10 -> V_430 , F_218 ( V_48 ) ) ;
if ( V_4 ) {
struct V_431 * V_432 = F_219 ( V_4 , struct V_431 , V_433 ) ;
if ( F_64 ( V_434 , & V_432 -> V_66 ) )
V_428 = false ;
}
F_21 ( & V_10 -> V_429 ) ;
return V_428 ;
}
bool F_216 ( struct V_9 * V_10 )
{
struct V_435 * V_436 = V_10 -> V_246 -> V_247 -> V_437 -> V_438 ;
unsigned long V_439 , V_440 , V_441 ;
unsigned int V_442 ;
int V_443 ;
F_25 () ;
V_442 = F_26 ( V_10 -> V_246 -> V_274 ) -> V_442 ;
F_27 () ;
if ( V_442 == 0 )
return false ;
V_443 = ( int ) F_220 ( & V_436 -> V_444 , V_445 [ 0 ] ) +
( int ) F_220 ( & V_436 -> V_444 , V_445 [ 1 ] ) -
F_28 ( & V_10 -> V_349 ) ;
if ( F_28 ( & V_10 -> V_446 )
|| V_443 - V_10 -> V_447 > 64 ) {
unsigned long V_448 ;
int V_6 ;
V_10 -> V_447 = V_443 ;
V_6 = ( V_10 -> V_449 + V_450 - 1 ) % V_450 ;
if ( V_10 -> V_368 . V_103 == V_451 || V_10 -> V_368 . V_103 == V_452 )
V_448 = V_10 -> V_453 ;
else
V_448 = F_221 ( V_10 ) - V_10 -> V_454 ;
V_440 = ( ( long ) V_63 - ( long ) V_10 -> V_455 [ V_6 ] ) / V_39 ;
if ( ! V_440 )
V_440 ++ ;
V_439 = V_10 -> V_456 [ V_6 ] - V_448 ;
V_441 = F_222 ( V_439 / V_440 ) ;
if ( V_441 > V_442 )
return true ;
}
return false ;
}
static int F_223 ( struct V_92 * V_33 , struct V_169 * V_170 )
{
struct V_26 * V_27 ;
struct V_9 * V_10 ;
T_3 V_48 ;
T_3 V_317 ;
struct V_18 * V_19 ;
struct V_457 * V_458 = NULL ;
int V_61 , V_459 ;
unsigned int V_283 ;
struct V_460 * V_315 = V_170 -> V_94 ;
V_27 = F_150 ( V_33 , V_170 -> V_192 ) ;
if ( ! V_27 )
return - V_106 ;
V_10 = V_27 -> V_10 ;
V_317 = F_156 ( V_10 -> V_318 ) ;
V_48 = F_179 ( V_315 -> V_48 ) ;
V_61 = F_122 ( V_315 -> V_461 ) ;
if ( V_61 <= 0 || ! F_158 ( V_61 , 512 ) || V_61 > V_44 ) {
F_41 ( V_10 , L_50 , __FILE__ , __LINE__ ,
( unsigned long long ) V_48 , V_61 ) ;
return - V_232 ;
}
if ( V_48 + ( V_61 >> 9 ) > V_317 ) {
F_41 ( V_10 , L_50 , __FILE__ , __LINE__ ,
( unsigned long long ) V_48 , V_61 ) ;
return - V_232 ;
}
if ( ! F_224 ( V_10 , V_462 ) ) {
V_459 = 1 ;
switch ( V_170 -> V_167 ) {
case V_463 :
F_225 ( V_27 , V_464 , V_315 ) ;
break;
case V_465 :
case V_466 :
case V_467 :
F_225 ( V_27 , V_468 , V_315 ) ;
break;
case V_469 :
V_459 = 0 ;
F_174 ( V_10 ) ;
F_226 ( V_27 , V_470 , V_48 , V_61 , V_471 ) ;
break;
default:
F_227 () ;
}
if ( V_459 && F_183 ( & V_359 ) )
F_41 ( V_10 , L_51
L_52 ) ;
return F_162 ( V_27 , V_170 -> V_61 ) ;
}
V_19 = F_38 ( V_27 , V_315 -> V_65 , V_48 , V_61 ,
true , V_212 ) ;
if ( ! V_19 ) {
F_129 ( V_10 ) ;
return - V_287 ;
}
switch ( V_170 -> V_167 ) {
case V_463 :
V_19 -> V_20 . V_77 = V_472 ;
V_283 = V_473 ;
V_19 -> V_66 |= V_411 ;
goto V_304;
case V_465 :
V_19 -> V_20 . V_77 = V_474 ;
V_283 = V_475 ;
V_10 -> V_476 = F_228 ( V_48 ) ;
break;
case V_469 :
case V_466 :
V_283 = V_475 ;
V_458 = F_153 ( sizeof( * V_458 ) + V_170 -> V_61 , V_212 ) ;
if ( ! V_458 )
goto V_477;
V_458 -> V_319 = V_170 -> V_61 ;
V_458 -> V_68 = ( ( ( char * ) V_458 ) + sizeof( struct V_457 ) ) ;
V_19 -> V_68 = V_458 ;
V_19 -> V_66 |= V_67 ;
if ( F_68 ( V_27 -> V_33 , V_458 -> V_68 , V_170 -> V_61 ) )
goto V_477;
if ( V_170 -> V_167 == V_466 ) {
F_48 ( V_10 , V_27 -> V_33 -> V_184 >= 89 ) ;
V_19 -> V_20 . V_77 = V_478 ;
V_10 -> V_476 = F_228 ( V_48 ) ;
V_10 -> V_479 = true ;
} else if ( V_170 -> V_167 == V_469 ) {
F_34 ( V_61 >> 9 , & V_10 -> V_360 ) ;
V_19 -> V_20 . V_77 = V_480 ;
F_174 ( V_10 ) ;
goto V_481;
}
break;
case V_467 :
if ( V_10 -> V_482 == ~ ( T_3 ) 0 &&
V_27 -> V_33 -> V_184 >= 90 ) {
unsigned long V_483 = V_63 ;
int V_6 ;
V_10 -> V_482 = V_48 ;
V_10 -> V_484 = V_48 ;
V_10 -> V_453 = F_229 ( V_10 ) - F_228 ( V_48 ) ;
V_10 -> V_485 = V_10 -> V_453 ;
for ( V_6 = 0 ; V_6 < V_450 ; V_6 ++ ) {
V_10 -> V_456 [ V_6 ] = V_10 -> V_453 ;
V_10 -> V_455 [ V_6 ] = V_483 ;
}
F_63 ( V_10 , L_53 ,
( unsigned long long ) V_48 ) ;
}
V_19 -> V_20 . V_77 = V_486 ;
V_283 = V_475 ;
break;
default:
F_227 () ;
}
F_20 ( & V_10 -> V_24 -> V_25 ) ;
F_140 ( & V_19 -> V_20 . V_21 , & V_10 -> V_487 ) ;
F_21 ( & V_10 -> V_24 -> V_25 ) ;
F_230 ( V_33 , F_215 ) ;
if ( V_10 -> V_368 . V_488 != V_489
&& F_215 ( V_10 , V_48 , false ) )
F_231 ( V_39 / 10 ) ;
F_230 ( V_33 , V_490 ) ;
if ( V_490 ( V_10 , V_48 ) )
goto V_477;
V_481:
F_34 ( V_61 >> 9 , & V_10 -> V_349 ) ;
V_304:
F_230 ( V_33 , F_137 ) ;
F_175 ( V_10 ) ;
if ( F_137 ( V_10 , V_19 , V_491 , V_283 ) == 0 )
return 0 ;
F_41 ( V_10 , L_40 ) ;
V_477:
F_20 ( & V_10 -> V_24 -> V_25 ) ;
F_134 ( & V_19 -> V_20 . V_21 ) ;
F_21 ( & V_10 -> V_24 -> V_25 ) ;
F_129 ( V_10 ) ;
F_55 ( V_10 , V_19 ) ;
return - V_106 ;
}
static int F_232 ( struct V_26 * V_27 ) __must_hold( T_5 )
{
struct V_9 * V_10 = V_27 -> V_10 ;
int V_492 , V_488 , V_93 = - 100 ;
unsigned long V_493 , V_494 ;
enum V_495 V_496 ;
V_492 = V_10 -> V_246 -> V_497 . V_498 [ V_499 ] & 1 ;
V_488 = V_10 -> V_500 [ V_499 ] & 1 ;
V_494 = V_10 -> V_500 [ V_501 ] ;
V_493 = V_10 -> V_502 ;
F_25 () ;
V_496 = F_26 ( V_27 -> V_33 -> V_29 ) -> V_496 ;
F_27 () ;
switch ( V_496 ) {
case V_503 :
case V_504 :
case V_505 :
case V_506 :
F_41 ( V_10 , L_54 ) ;
break;
case V_507 :
break;
case V_508 :
if ( V_492 == 0 && V_488 == 1 ) {
V_93 = - 1 ;
break;
}
if ( V_492 == 1 && V_488 == 0 ) {
V_93 = 1 ;
break;
}
case V_509 :
if ( V_492 == 0 && V_488 == 1 ) {
V_93 = 1 ;
break;
}
if ( V_492 == 1 && V_488 == 0 ) {
V_93 = - 1 ;
break;
}
F_31 ( V_10 , L_55
L_56 ) ;
case V_510 :
if ( V_494 == 0 && V_493 == 0 ) {
V_93 = F_64 ( V_204 , & V_27 -> V_33 -> V_66 )
? - 1 : 1 ;
break;
} else {
if ( V_494 == 0 ) { V_93 = 1 ; break; }
if ( V_493 == 0 ) { V_93 = - 1 ; break; }
}
if ( V_496 == V_510 )
break;
case V_511 :
if ( V_493 < V_494 )
V_93 = - 1 ;
else if ( V_493 > V_494 )
V_93 = 1 ;
else
V_93 = F_64 ( V_204 , & V_27 -> V_33 -> V_66 )
? - 1 : 1 ;
break;
case V_512 :
V_93 = - 1 ;
break;
case V_513 :
V_93 = 1 ;
}
return V_93 ;
}
static int F_233 ( struct V_26 * V_27 ) __must_hold( T_5 )
{
struct V_9 * V_10 = V_27 -> V_10 ;
int V_514 , V_93 = - 100 ;
enum V_495 V_515 ;
F_25 () ;
V_515 = F_26 ( V_27 -> V_33 -> V_29 ) -> V_515 ;
F_27 () ;
switch ( V_515 ) {
case V_508 :
case V_509 :
case V_511 :
case V_512 :
case V_513 :
case V_510 :
F_41 ( V_10 , L_54 ) ;
break;
case V_507 :
break;
case V_503 :
V_514 = F_232 ( V_27 ) ;
if ( V_514 == - 1 && V_10 -> V_368 . V_516 == V_517 )
V_93 = V_514 ;
if ( V_514 == 1 && V_10 -> V_368 . V_516 == V_489 )
V_93 = V_514 ;
break;
case V_506 :
V_93 = F_232 ( V_27 ) ;
break;
case V_504 :
return V_10 -> V_368 . V_516 == V_489 ? 1 : - 1 ;
case V_505 :
V_514 = F_232 ( V_27 ) ;
if ( V_514 == - 1 && V_10 -> V_368 . V_516 == V_489 ) {
enum V_195 V_518 ;
V_518 = F_234 ( V_10 , V_197 , F_67 ( V_516 , V_517 ) ) ;
if ( V_518 != V_198 ) {
F_235 ( V_10 , L_57 ) ;
} else {
F_31 ( V_10 , L_58 ) ;
V_93 = V_514 ;
}
} else
V_93 = V_514 ;
}
return V_93 ;
}
static int F_236 ( struct V_26 * V_27 ) __must_hold( T_5 )
{
struct V_9 * V_10 = V_27 -> V_10 ;
int V_514 , V_93 = - 100 ;
enum V_495 V_519 ;
F_25 () ;
V_519 = F_26 ( V_27 -> V_33 -> V_29 ) -> V_519 ;
F_27 () ;
switch ( V_519 ) {
case V_508 :
case V_509 :
case V_511 :
case V_512 :
case V_513 :
case V_503 :
case V_504 :
case V_510 :
F_41 ( V_10 , L_54 ) ;
break;
case V_506 :
V_93 = F_232 ( V_27 ) ;
break;
case V_507 :
break;
case V_505 :
V_514 = F_232 ( V_27 ) ;
if ( V_514 == - 1 ) {
enum V_195 V_518 ;
V_518 = F_234 ( V_10 , V_197 , F_67 ( V_516 , V_517 ) ) ;
if ( V_518 != V_198 ) {
F_235 ( V_10 , L_57 ) ;
} else {
F_31 ( V_10 , L_58 ) ;
V_93 = V_514 ;
}
} else
V_93 = V_514 ;
}
return V_93 ;
}
static void F_237 ( struct V_9 * V_10 , char * V_520 , T_2 * V_498 ,
T_2 V_521 , T_2 V_66 )
{
if ( ! V_498 ) {
F_63 ( V_10 , L_59 , V_520 ) ;
return;
}
F_63 ( V_10 , L_60 ,
V_520 ,
( unsigned long long ) V_498 [ V_522 ] ,
( unsigned long long ) V_498 [ V_499 ] ,
( unsigned long long ) V_498 [ V_523 ] ,
( unsigned long long ) V_498 [ V_524 ] ,
( unsigned long long ) V_521 ,
( unsigned long long ) V_66 ) ;
}
static int F_238 ( struct V_9 * const V_10 , int * V_525 ) __must_hold( T_5 )
{
struct V_26 * const V_27 = F_139 ( V_10 ) ;
struct V_92 * const V_33 = V_27 ? V_27 -> V_33 : NULL ;
T_2 V_492 , V_488 ;
int V_6 , V_526 ;
V_492 = V_10 -> V_246 -> V_497 . V_498 [ V_522 ] & ~ ( ( T_2 ) 1 ) ;
V_488 = V_10 -> V_500 [ V_522 ] & ~ ( ( T_2 ) 1 ) ;
* V_525 = 10 ;
if ( V_492 == V_527 && V_488 == V_527 )
return 0 ;
* V_525 = 20 ;
if ( ( V_492 == V_527 || V_492 == ( T_2 ) 0 ) &&
V_488 != V_527 )
return - 2 ;
* V_525 = 30 ;
if ( V_492 != V_527 &&
( V_488 == V_527 || V_488 == ( T_2 ) 0 ) )
return 2 ;
if ( V_492 == V_488 ) {
int V_528 , V_275 ;
if ( V_10 -> V_500 [ V_499 ] == ( T_2 ) 0 && V_10 -> V_246 -> V_497 . V_498 [ V_499 ] != ( T_2 ) 0 ) {
if ( V_33 -> V_184 < 91 )
return - 1091 ;
if ( ( V_10 -> V_246 -> V_497 . V_498 [ V_499 ] & ~ ( ( T_2 ) 1 ) ) == ( V_10 -> V_500 [ V_523 ] & ~ ( ( T_2 ) 1 ) ) &&
( V_10 -> V_246 -> V_497 . V_498 [ V_523 ] & ~ ( ( T_2 ) 1 ) ) == ( V_10 -> V_500 [ V_523 + 1 ] & ~ ( ( T_2 ) 1 ) ) ) {
F_63 ( V_10 , L_61 ) ;
F_239 ( V_10 ) ;
V_10 -> V_246 -> V_497 . V_498 [ V_523 ] = V_10 -> V_246 -> V_497 . V_498 [ V_499 ] ;
V_10 -> V_246 -> V_497 . V_498 [ V_499 ] = 0 ;
F_237 ( V_10 , L_62 , V_10 -> V_246 -> V_497 . V_498 ,
V_10 -> V_368 . V_436 >= V_529 ? F_221 ( V_10 ) : 0 , 0 ) ;
* V_525 = 34 ;
} else {
F_63 ( V_10 , L_63 ) ;
* V_525 = 36 ;
}
return 1 ;
}
if ( V_10 -> V_246 -> V_497 . V_498 [ V_499 ] == ( T_2 ) 0 && V_10 -> V_500 [ V_499 ] != ( T_2 ) 0 ) {
if ( V_33 -> V_184 < 91 )
return - 1091 ;
if ( ( V_10 -> V_246 -> V_497 . V_498 [ V_523 ] & ~ ( ( T_2 ) 1 ) ) == ( V_10 -> V_500 [ V_499 ] & ~ ( ( T_2 ) 1 ) ) &&
( V_10 -> V_246 -> V_497 . V_498 [ V_523 + 1 ] & ~ ( ( T_2 ) 1 ) ) == ( V_10 -> V_500 [ V_523 ] & ~ ( ( T_2 ) 1 ) ) ) {
F_63 ( V_10 , L_64 ) ;
V_10 -> V_500 [ V_523 + 1 ] = V_10 -> V_500 [ V_523 ] ;
V_10 -> V_500 [ V_523 ] = V_10 -> V_500 [ V_499 ] ;
V_10 -> V_500 [ V_499 ] = 0UL ;
F_237 ( V_10 , L_65 , V_10 -> V_500 , V_10 -> V_500 [ V_501 ] , V_10 -> V_500 [ V_530 ] ) ;
* V_525 = 35 ;
} else {
F_63 ( V_10 , L_66 ) ;
* V_525 = 37 ;
}
return - 1 ;
}
V_528 = ( F_64 ( V_531 , & V_10 -> V_66 ) ? 1 : 0 ) +
( V_10 -> V_500 [ V_530 ] & 2 ) ;
* V_525 = 40 ;
switch ( V_528 ) {
case 0 : return 0 ;
case 1 : return 1 ;
case 2 : return - 1 ;
case 3 :
V_275 = F_64 ( V_204 , & V_33 -> V_66 ) ;
return V_275 ? - 1 : 1 ;
}
}
* V_525 = 50 ;
V_488 = V_10 -> V_500 [ V_499 ] & ~ ( ( T_2 ) 1 ) ;
if ( V_492 == V_488 )
return - 1 ;
* V_525 = 51 ;
V_488 = V_10 -> V_500 [ V_523 ] & ~ ( ( T_2 ) 1 ) ;
if ( V_492 == V_488 ) {
if ( V_33 -> V_184 < 96 ?
( V_10 -> V_246 -> V_497 . V_498 [ V_523 ] & ~ ( ( T_2 ) 1 ) ) ==
( V_10 -> V_500 [ V_523 + 1 ] & ~ ( ( T_2 ) 1 ) ) :
V_488 + V_532 == ( V_10 -> V_500 [ V_499 ] & ~ ( ( T_2 ) 1 ) ) ) {
if ( V_33 -> V_184 < 91 )
return - 1091 ;
V_10 -> V_500 [ V_499 ] = V_10 -> V_500 [ V_523 ] ;
V_10 -> V_500 [ V_523 ] = V_10 -> V_500 [ V_523 + 1 ] ;
F_63 ( V_10 , L_67 ) ;
F_237 ( V_10 , L_65 , V_10 -> V_500 , V_10 -> V_500 [ V_501 ] , V_10 -> V_500 [ V_530 ] ) ;
return - 1 ;
}
}
* V_525 = 60 ;
V_492 = V_10 -> V_246 -> V_497 . V_498 [ V_522 ] & ~ ( ( T_2 ) 1 ) ;
for ( V_6 = V_523 ; V_6 <= V_524 ; V_6 ++ ) {
V_488 = V_10 -> V_500 [ V_6 ] & ~ ( ( T_2 ) 1 ) ;
if ( V_492 == V_488 )
return - 2 ;
}
* V_525 = 70 ;
V_492 = V_10 -> V_246 -> V_497 . V_498 [ V_499 ] & ~ ( ( T_2 ) 1 ) ;
V_488 = V_10 -> V_500 [ V_522 ] & ~ ( ( T_2 ) 1 ) ;
if ( V_492 == V_488 )
return 1 ;
* V_525 = 71 ;
V_492 = V_10 -> V_246 -> V_497 . V_498 [ V_523 ] & ~ ( ( T_2 ) 1 ) ;
if ( V_492 == V_488 ) {
if ( V_33 -> V_184 < 96 ?
( V_10 -> V_246 -> V_497 . V_498 [ V_523 + 1 ] & ~ ( ( T_2 ) 1 ) ) ==
( V_10 -> V_500 [ V_523 ] & ~ ( ( T_2 ) 1 ) ) :
V_492 + V_532 == ( V_10 -> V_246 -> V_497 . V_498 [ V_499 ] & ~ ( ( T_2 ) 1 ) ) ) {
if ( V_33 -> V_184 < 91 )
return - 1091 ;
F_240 ( V_10 , V_499 , V_10 -> V_246 -> V_497 . V_498 [ V_523 ] ) ;
F_240 ( V_10 , V_523 , V_10 -> V_246 -> V_497 . V_498 [ V_523 + 1 ] ) ;
F_63 ( V_10 , L_68 ) ;
F_237 ( V_10 , L_62 , V_10 -> V_246 -> V_497 . V_498 ,
V_10 -> V_368 . V_436 >= V_529 ? F_221 ( V_10 ) : 0 , 0 ) ;
return 1 ;
}
}
* V_525 = 80 ;
V_488 = V_10 -> V_500 [ V_522 ] & ~ ( ( T_2 ) 1 ) ;
for ( V_6 = V_523 ; V_6 <= V_524 ; V_6 ++ ) {
V_492 = V_10 -> V_246 -> V_497 . V_498 [ V_6 ] & ~ ( ( T_2 ) 1 ) ;
if ( V_492 == V_488 )
return 2 ;
}
* V_525 = 90 ;
V_492 = V_10 -> V_246 -> V_497 . V_498 [ V_499 ] & ~ ( ( T_2 ) 1 ) ;
V_488 = V_10 -> V_500 [ V_499 ] & ~ ( ( T_2 ) 1 ) ;
if ( V_492 == V_488 && V_492 != ( ( T_2 ) 0 ) )
return 100 ;
* V_525 = 100 ;
for ( V_6 = V_523 ; V_6 <= V_524 ; V_6 ++ ) {
V_492 = V_10 -> V_246 -> V_497 . V_498 [ V_6 ] & ~ ( ( T_2 ) 1 ) ;
for ( V_526 = V_523 ; V_526 <= V_524 ; V_526 ++ ) {
V_488 = V_10 -> V_500 [ V_526 ] & ~ ( ( T_2 ) 1 ) ;
if ( V_492 == V_488 )
return - 100 ;
}
}
return - 1000 ;
}
static enum V_533 F_241 ( struct V_26 * V_27 ,
enum V_534 V_535 ,
enum V_536 V_537 ) __must_hold( T_5 )
{
struct V_9 * V_10 = V_27 -> V_10 ;
enum V_533 V_93 = V_538 ;
enum V_536 V_539 ;
struct V_29 * V_30 ;
int V_514 , V_525 , V_540 , V_541 ;
V_539 = V_10 -> V_368 . V_436 ;
if ( V_539 == V_529 )
V_539 = V_10 -> V_542 . V_436 ;
F_63 ( V_10 , L_69 ) ;
F_20 ( & V_10 -> V_246 -> V_497 . V_543 ) ;
F_237 ( V_10 , L_62 , V_10 -> V_246 -> V_497 . V_498 , V_10 -> V_502 , 0 ) ;
F_237 ( V_10 , L_65 , V_10 -> V_500 ,
V_10 -> V_500 [ V_501 ] , V_10 -> V_500 [ V_530 ] ) ;
V_514 = F_238 ( V_10 , & V_525 ) ;
F_21 ( & V_10 -> V_246 -> V_497 . V_543 ) ;
F_63 ( V_10 , L_70 , V_514 , V_525 ) ;
if ( V_514 == - 1000 ) {
F_205 ( V_10 , L_71 ) ;
return V_538 ;
}
if ( V_514 < - 1000 ) {
F_205 ( V_10 , L_72 , - V_514 - 1000 ) ;
return V_538 ;
}
if ( ( V_539 == V_424 && V_537 > V_424 ) ||
( V_537 == V_424 && V_539 > V_424 ) ) {
int V_544 = ( V_514 == - 100 ) || abs ( V_514 ) == 2 ;
V_514 = V_539 > V_424 ? 1 : - 1 ;
if ( V_544 )
V_514 = V_514 * 2 ;
F_63 ( V_10 , L_73 ,
V_514 > 0 ? L_74 : L_75 ) ;
}
if ( abs ( V_514 ) == 100 )
F_235 ( V_10 , L_76 ) ;
F_25 () ;
V_30 = F_26 ( V_27 -> V_33 -> V_29 ) ;
if ( V_514 == 100 || ( V_514 == - 100 && V_30 -> V_545 ) ) {
int V_546 = ( V_10 -> V_368 . V_516 == V_489 )
+ ( V_535 == V_489 ) ;
int V_547 = ( V_514 == - 100 ) ;
switch ( V_546 ) {
case 0 :
V_514 = F_232 ( V_27 ) ;
break;
case 1 :
V_514 = F_233 ( V_27 ) ;
break;
case 2 :
V_514 = F_236 ( V_27 ) ;
break;
}
if ( abs ( V_514 ) < 100 ) {
F_31 ( V_10 , L_77
L_78 ,
V_546 , ( V_514 < 0 ) ? L_65 : L_79 ) ;
if ( V_547 ) {
F_31 ( V_10 , L_80
L_81 ) ;
V_514 = V_514 * 2 ;
}
}
}
if ( V_514 == - 100 ) {
if ( F_64 ( V_223 , & V_10 -> V_66 ) && ! ( V_10 -> V_500 [ V_530 ] & 1 ) )
V_514 = - 1 ;
if ( ! F_64 ( V_223 , & V_10 -> V_66 ) && ( V_10 -> V_500 [ V_530 ] & 1 ) )
V_514 = 1 ;
if ( abs ( V_514 ) < 100 )
F_31 ( V_10 , L_82
L_83 ,
( V_514 < 0 ) ? L_65 : L_79 ) ;
}
V_540 = V_30 -> V_540 ;
V_541 = V_30 -> V_541 ;
F_27 () ;
if ( V_514 == - 100 ) {
F_205 ( V_10 , L_84 ) ;
F_235 ( V_10 , L_85 ) ;
return V_538 ;
}
if ( V_514 > 0 && V_539 <= V_424 ) {
F_41 ( V_10 , L_86 ) ;
return V_538 ;
}
if ( V_514 < 0 &&
V_10 -> V_368 . V_516 == V_489 && V_10 -> V_368 . V_436 >= V_548 ) {
switch ( V_540 ) {
case V_505 :
F_235 ( V_10 , L_87 ) ;
case V_507 :
F_41 ( V_10 , L_88 ) ;
return V_538 ;
case V_506 :
F_31 ( V_10 , L_89
L_90 ) ;
}
}
if ( V_541 || F_64 ( V_549 , & V_27 -> V_33 -> V_66 ) ) {
if ( V_514 == 0 )
F_63 ( V_10 , L_91 ) ;
else
F_63 ( V_10 , L_92 ,
F_242 ( V_514 > 0 ? V_369 : V_422 ) ,
abs ( V_514 ) >= 2 ? L_93 : L_94 ) ;
return V_538 ;
}
if ( abs ( V_514 ) >= 2 ) {
F_63 ( V_10 , L_95 ) ;
if ( F_243 ( V_10 , & V_550 , L_96 ,
V_551 ) )
return V_538 ;
}
if ( V_514 > 0 ) {
V_93 = V_552 ;
} else if ( V_514 < 0 ) {
V_93 = V_553 ;
} else {
V_93 = V_554 ;
if ( F_221 ( V_10 ) ) {
F_63 ( V_10 , L_97 ,
F_221 ( V_10 ) ) ;
}
}
return V_93 ;
}
static enum V_495 F_244 ( enum V_495 V_488 )
{
if ( V_488 == V_513 )
return V_512 ;
if ( V_488 == V_512 )
return V_513 ;
return V_488 ;
}
static int F_245 ( struct V_92 * V_33 , struct V_169 * V_170 )
{
struct V_555 * V_315 = V_170 -> V_94 ;
enum V_495 V_556 , V_557 , V_558 ;
int V_559 , V_560 , V_561 , V_562 ;
struct V_29 * V_30 , * V_563 , * V_564 = NULL ;
char V_565 [ V_566 ] = L_98 ;
struct V_567 * V_328 = NULL ;
void * V_322 = NULL , * V_324 = NULL ;
V_559 = F_122 ( V_315 -> V_568 ) ;
V_556 = F_122 ( V_315 -> V_496 ) ;
V_557 = F_122 ( V_315 -> V_515 ) ;
V_558 = F_122 ( V_315 -> V_519 ) ;
V_561 = F_122 ( V_315 -> V_390 ) ;
V_562 = F_122 ( V_315 -> V_569 ) ;
V_560 = V_562 & V_570 ;
if ( V_33 -> V_184 >= 87 ) {
int V_74 ;
if ( V_170 -> V_61 > sizeof( V_565 ) )
return - V_106 ;
V_74 = F_68 ( V_33 , V_565 , V_170 -> V_61 ) ;
if ( V_74 )
return V_74 ;
V_565 [ V_566 - 1 ] = 0 ;
}
if ( V_170 -> V_167 != V_571 ) {
F_101 ( V_549 , & V_33 -> V_66 ) ;
if ( V_562 & V_572 )
F_106 ( V_549 , & V_33 -> V_66 ) ;
F_25 () ;
V_30 = F_26 ( V_33 -> V_29 ) ;
if ( V_559 != V_30 -> V_415 ) {
F_41 ( V_33 , L_99 , L_100 ) ;
goto V_573;
}
if ( F_244 ( V_556 ) != V_30 -> V_496 ) {
F_41 ( V_33 , L_99 , L_101 ) ;
goto V_573;
}
if ( F_244 ( V_557 ) != V_30 -> V_515 ) {
F_41 ( V_33 , L_99 , L_102 ) ;
goto V_573;
}
if ( F_244 ( V_558 ) != V_30 -> V_519 ) {
F_41 ( V_33 , L_99 , L_103 ) ;
goto V_573;
}
if ( V_560 && V_30 -> V_194 ) {
F_41 ( V_33 , L_99 , L_104 ) ;
goto V_573;
}
if ( V_561 != V_30 -> V_390 ) {
F_41 ( V_33 , L_99 , L_105 ) ;
goto V_573;
}
if ( strcmp ( V_565 , V_30 -> V_565 ) ) {
F_41 ( V_33 , L_99 , L_106 ) ;
goto V_573;
}
F_27 () ;
}
if ( V_565 [ 0 ] ) {
int V_574 ;
V_328 = F_246 ( V_565 , 0 , V_575 ) ;
if ( ! V_328 ) {
F_41 ( V_33 , L_107 ,
V_565 ) ;
goto V_576;
}
V_574 = F_157 ( V_328 ) ;
V_322 = F_153 ( V_574 , V_577 ) ;
V_324 = F_153 ( V_574 , V_577 ) ;
if ( ! ( V_322 && V_324 ) ) {
F_41 ( V_33 , L_108 ) ;
goto V_576;
}
}
V_564 = F_153 ( sizeof( struct V_29 ) , V_577 ) ;
if ( ! V_564 ) {
F_41 ( V_33 , L_109 ) ;
goto V_576;
}
F_115 ( & V_33 -> V_94 . V_199 ) ;
F_115 ( & V_33 -> V_24 -> V_226 ) ;
V_563 = V_33 -> V_29 ;
* V_564 = * V_563 ;
V_564 -> V_415 = V_559 ;
V_564 -> V_496 = F_244 ( V_556 ) ;
V_564 -> V_515 = F_244 ( V_557 ) ;
V_564 -> V_519 = F_244 ( V_558 ) ;
V_564 -> V_390 = V_561 ;
F_247 ( V_33 -> V_29 , V_564 ) ;
F_116 ( & V_33 -> V_24 -> V_226 ) ;
F_116 ( & V_33 -> V_94 . V_199 ) ;
F_248 ( V_33 -> V_328 ) ;
F_47 ( V_33 -> V_322 ) ;
F_47 ( V_33 -> V_324 ) ;
V_33 -> V_328 = V_328 ;
V_33 -> V_322 = V_322 ;
V_33 -> V_324 = V_324 ;
if ( strcmp ( V_563 -> V_565 , V_565 ) )
F_63 ( V_33 , L_110 ,
V_565 [ 0 ] ? V_565 : L_111 ) ;
F_249 () ;
F_47 ( V_563 ) ;
return 0 ;
V_573:
F_27 () ;
V_576:
F_248 ( V_328 ) ;
F_47 ( V_322 ) ;
F_47 ( V_324 ) ;
F_66 ( V_33 , F_67 ( V_103 , V_149 ) , V_105 ) ;
return - V_106 ;
}
static struct V_567 * F_250 ( const struct V_9 * V_10 ,
const char * V_578 , const char * V_579 )
{
struct V_567 * V_580 ;
if ( ! V_578 [ 0 ] )
return NULL ;
V_580 = F_246 ( V_578 , 0 , V_575 ) ;
if ( F_251 ( V_580 ) ) {
F_41 ( V_10 , L_112 ,
V_578 , V_579 , F_252 ( V_580 ) ) ;
return V_580 ;
}
return V_580 ;
}
static int F_253 ( struct V_92 * V_33 , struct V_169 * V_170 )
{
void * V_241 = V_33 -> V_94 . V_171 ;
int V_61 = V_170 -> V_61 ;
while ( V_61 ) {
int V_202 = F_72 ( int , V_61 , V_581 ) ;
V_202 = F_62 ( V_33 , V_241 , V_202 ) ;
if ( V_202 <= 0 ) {
if ( V_202 < 0 )
return V_202 ;
break;
}
V_61 -= V_202 ;
}
if ( V_61 )
return - V_106 ;
return 0 ;
}
static int F_254 ( struct V_92 * V_33 , struct V_169 * V_170 )
{
F_31 ( V_33 , L_113 ,
F_255 ( V_170 -> V_167 ) , V_170 -> V_192 ) ;
return F_253 ( V_33 , V_170 ) ;
}
static int F_256 ( struct V_92 * V_33 , struct V_169 * V_170 )
{
struct V_26 * V_27 ;
struct V_9 * V_10 ;
struct V_582 * V_315 ;
unsigned int V_168 , V_49 , V_583 ;
struct V_567 * V_584 = NULL ;
struct V_567 * V_585 = NULL ;
struct V_29 * V_563 , * V_564 = NULL ;
struct V_274 * V_586 = NULL , * V_587 = NULL ;
const int V_588 = V_33 -> V_184 ;
struct V_589 * V_590 = NULL , * V_591 = NULL ;
int V_592 = 0 ;
int V_74 ;
V_27 = F_150 ( V_33 , V_170 -> V_192 ) ;
if ( ! V_27 )
return F_254 ( V_33 , V_170 ) ;
V_10 = V_27 -> V_10 ;
V_583 = V_588 <= 87 ? sizeof( struct V_593 )
: V_588 == 88 ? sizeof( struct V_593 )
+ V_566
: V_588 <= 94 ? sizeof( struct V_594 )
: sizeof( struct V_582 ) ;
if ( V_170 -> V_61 > V_583 ) {
F_41 ( V_10 , L_114 ,
V_170 -> V_61 , V_583 ) ;
return - V_106 ;
}
if ( V_588 <= 88 ) {
V_168 = sizeof( struct V_593 ) ;
V_49 = V_170 -> V_61 - V_168 ;
} else if ( V_588 <= 94 ) {
V_168 = sizeof( struct V_594 ) ;
V_49 = V_170 -> V_61 - V_168 ;
F_48 ( V_10 , V_49 == 0 ) ;
} else {
V_168 = sizeof( struct V_582 ) ;
V_49 = V_170 -> V_61 - V_168 ;
F_48 ( V_10 , V_49 == 0 ) ;
}
V_315 = V_170 -> V_94 ;
memset ( V_315 -> V_595 , 0 , 2 * V_566 ) ;
V_74 = F_68 ( V_27 -> V_33 , V_315 , V_168 ) ;
if ( V_74 )
return V_74 ;
F_115 ( & V_33 -> V_24 -> V_226 ) ;
V_563 = V_27 -> V_33 -> V_29 ;
if ( F_126 ( V_10 ) ) {
V_587 = F_257 ( sizeof( struct V_274 ) , V_577 ) ;
if ( ! V_587 ) {
F_129 ( V_10 ) ;
F_116 ( & V_33 -> V_24 -> V_226 ) ;
F_41 ( V_10 , L_115 ) ;
return - V_287 ;
}
V_586 = V_10 -> V_246 -> V_274 ;
* V_587 = * V_586 ;
V_587 -> V_596 = F_122 ( V_315 -> V_596 ) ;
}
if ( V_588 >= 88 ) {
if ( V_588 == 88 ) {
if ( V_49 > V_566 || V_49 == 0 ) {
F_41 ( V_10 , L_116
L_117 ,
V_49 , V_566 ) ;
V_74 = - V_106 ;
goto V_597;
}
V_74 = F_68 ( V_27 -> V_33 , V_315 -> V_595 , V_49 ) ;
if ( V_74 )
goto V_597;
F_48 ( V_10 , V_315 -> V_595 [ V_49 - 1 ] == 0 ) ;
V_315 -> V_595 [ V_49 - 1 ] = 0 ;
} else {
F_48 ( V_10 , V_315 -> V_595 [ V_566 - 1 ] == 0 ) ;
F_48 ( V_10 , V_315 -> V_598 [ V_566 - 1 ] == 0 ) ;
V_315 -> V_595 [ V_566 - 1 ] = 0 ;
V_315 -> V_598 [ V_566 - 1 ] = 0 ;
}
if ( strcmp ( V_563 -> V_595 , V_315 -> V_595 ) ) {
if ( V_10 -> V_368 . V_103 == V_101 ) {
F_41 ( V_10 , L_118 ,
V_563 -> V_595 , V_315 -> V_595 ) ;
goto V_576;
}
V_584 = F_250 ( V_10 ,
V_315 -> V_595 , L_119 ) ;
if ( F_251 ( V_584 ) ) {
V_584 = NULL ;
goto V_576;
}
}
if ( V_588 >= 89 && strcmp ( V_563 -> V_598 , V_315 -> V_598 ) ) {
if ( V_10 -> V_368 . V_103 == V_101 ) {
F_41 ( V_10 , L_120 ,
V_563 -> V_598 , V_315 -> V_598 ) ;
goto V_576;
}
V_585 = F_250 ( V_10 ,
V_315 -> V_598 , L_121 ) ;
if ( F_251 ( V_585 ) ) {
V_585 = NULL ;
goto V_576;
}
}
if ( V_588 > 94 && V_587 ) {
V_587 -> V_599 = F_122 ( V_315 -> V_599 ) ;
V_587 -> V_600 = F_122 ( V_315 -> V_600 ) ;
V_587 -> V_601 = F_122 ( V_315 -> V_601 ) ;
V_587 -> V_602 = F_122 ( V_315 -> V_602 ) ;
V_592 = ( V_587 -> V_599 * 10 * V_603 ) / V_39 ;
if ( V_592 != V_10 -> V_604 -> V_61 ) {
V_591 = F_258 ( V_592 ) ;
if ( ! V_591 ) {
F_41 ( V_10 , L_122 ) ;
F_129 ( V_10 ) ;
goto V_576;
}
}
}
if ( V_584 || V_585 ) {
V_564 = F_257 ( sizeof( struct V_29 ) , V_577 ) ;
if ( ! V_564 ) {
F_41 ( V_10 , L_109 ) ;
goto V_576;
}
* V_564 = * V_563 ;
if ( V_584 ) {
strcpy ( V_564 -> V_595 , V_315 -> V_595 ) ;
V_564 -> V_605 = strlen ( V_315 -> V_595 ) + 1 ;
F_248 ( V_27 -> V_33 -> V_584 ) ;
V_27 -> V_33 -> V_584 = V_584 ;
F_63 ( V_10 , L_123 , V_315 -> V_595 ) ;
}
if ( V_585 ) {
strcpy ( V_564 -> V_598 , V_315 -> V_598 ) ;
V_564 -> V_606 = strlen ( V_315 -> V_598 ) + 1 ;
F_248 ( V_27 -> V_33 -> V_585 ) ;
V_27 -> V_33 -> V_585 = V_585 ;
F_63 ( V_10 , L_124 , V_315 -> V_598 ) ;
}
F_247 ( V_33 -> V_29 , V_564 ) ;
}
}
if ( V_587 ) {
F_247 ( V_10 -> V_246 -> V_274 , V_587 ) ;
F_129 ( V_10 ) ;
}
if ( V_591 ) {
V_590 = V_10 -> V_604 ;
F_247 ( V_10 -> V_604 , V_591 ) ;
}
F_116 ( & V_33 -> V_24 -> V_226 ) ;
F_249 () ;
if ( V_564 )
F_47 ( V_563 ) ;
F_47 ( V_586 ) ;
F_47 ( V_590 ) ;
return 0 ;
V_597:
if ( V_587 ) {
F_129 ( V_10 ) ;
F_47 ( V_587 ) ;
}
F_116 ( & V_33 -> V_24 -> V_226 ) ;
return - V_106 ;
V_576:
F_47 ( V_591 ) ;
if ( V_587 ) {
F_129 ( V_10 ) ;
F_47 ( V_587 ) ;
}
F_116 ( & V_33 -> V_24 -> V_226 ) ;
F_248 ( V_585 ) ;
F_248 ( V_584 ) ;
F_66 ( V_27 -> V_33 , F_67 ( V_103 , V_149 ) , V_105 ) ;
return - V_106 ;
}
static void F_259 ( struct V_9 * V_10 ,
const char * V_202 , T_3 V_42 , T_3 V_378 )
{
T_3 V_607 ;
if ( V_42 == 0 || V_378 == 0 )
return;
V_607 = ( V_42 > V_378 ) ? ( V_42 - V_378 ) : ( V_378 - V_42 ) ;
if ( V_607 > ( V_42 >> 3 ) || V_607 > ( V_378 >> 3 ) )
F_31 ( V_10 , L_125 , V_202 ,
( unsigned long long ) V_42 , ( unsigned long long ) V_378 ) ;
}
static int F_260 ( struct V_92 * V_33 , struct V_169 * V_170 )
{
struct V_26 * V_27 ;
struct V_9 * V_10 ;
struct V_608 * V_315 = V_170 -> V_94 ;
enum V_609 V_610 = V_611 ;
T_3 V_612 , V_613 , V_614 , V_615 ;
int V_616 = 0 ;
enum V_617 V_618 ;
V_27 = F_150 ( V_33 , V_170 -> V_192 ) ;
if ( ! V_27 )
return F_254 ( V_33 , V_170 ) ;
V_10 = V_27 -> V_10 ;
V_612 = F_179 ( V_315 -> V_619 ) ;
V_613 = F_179 ( V_315 -> V_620 ) ;
V_614 = F_179 ( V_315 -> V_621 ) ;
V_10 -> V_612 = V_612 ;
if ( F_126 ( V_10 ) ) {
F_25 () ;
V_615 = F_26 ( V_10 -> V_246 -> V_274 ) -> V_622 ;
F_27 () ;
F_259 ( V_10 , L_126 ,
V_612 , F_261 ( V_10 -> V_246 ) ) ;
F_259 ( V_10 , L_127 ,
V_613 , V_615 ) ;
if ( V_10 -> V_368 . V_103 == V_101 )
V_613 = F_262 ( V_615 , V_613 ) ;
if ( F_263 ( V_10 , V_10 -> V_246 , V_613 , 0 ) <
F_156 ( V_10 -> V_318 ) &&
V_10 -> V_368 . V_436 >= V_623 &&
V_10 -> V_368 . V_103 < V_554 ) {
F_41 ( V_10 , L_128 ) ;
F_66 ( V_27 -> V_33 , F_67 ( V_103 , V_149 ) , V_105 ) ;
F_129 ( V_10 ) ;
return - V_106 ;
}
if ( V_615 != V_613 ) {
struct V_274 * V_586 , * V_587 = NULL ;
V_587 = F_257 ( sizeof( struct V_274 ) , V_577 ) ;
if ( ! V_587 ) {
F_41 ( V_10 , L_115 ) ;
F_129 ( V_10 ) ;
return - V_287 ;
}
F_115 ( & V_33 -> V_24 -> V_226 ) ;
V_586 = V_10 -> V_246 -> V_274 ;
* V_587 = * V_586 ;
V_587 -> V_622 = V_613 ;
F_247 ( V_10 -> V_246 -> V_274 , V_587 ) ;
F_116 ( & V_33 -> V_24 -> V_226 ) ;
F_249 () ;
F_47 ( V_586 ) ;
F_63 ( V_10 , L_129 ,
( unsigned long ) V_615 ) ;
}
F_129 ( V_10 ) ;
}
V_10 -> V_624 = F_122 ( V_315 -> V_625 ) ;
V_618 = F_121 ( V_315 -> V_617 ) ;
if ( F_126 ( V_10 ) ) {
F_264 ( V_10 , V_10 -> V_246 ) ;
V_610 = F_265 ( V_10 , V_618 , NULL ) ;
F_129 ( V_10 ) ;
if ( V_610 == V_626 )
return - V_106 ;
F_266 ( V_10 ) ;
} else {
F_264 ( V_10 , NULL ) ;
F_267 ( V_10 , V_614 ? : V_613 ? : V_612 ) ;
}
if ( F_126 ( V_10 ) ) {
if ( V_10 -> V_246 -> V_627 != F_156 ( V_10 -> V_246 -> V_247 ) ) {
V_10 -> V_246 -> V_627 = F_156 ( V_10 -> V_246 -> V_247 ) ;
V_616 = 1 ;
}
F_129 ( V_10 ) ;
}
if ( V_10 -> V_368 . V_103 > V_101 ) {
if ( F_179 ( V_315 -> V_621 ) !=
F_156 ( V_10 -> V_318 ) || V_616 ) {
F_98 ( V_27 , 0 , V_618 ) ;
}
if ( F_268 ( V_188 , & V_10 -> V_66 ) ||
( V_610 == V_628 && V_10 -> V_368 . V_103 == V_554 ) ) {
if ( V_10 -> V_368 . V_423 >= V_424 &&
V_10 -> V_368 . V_436 >= V_424 ) {
if ( V_618 & V_629 )
F_63 ( V_10 , L_130 ) ;
else
F_269 ( V_10 ) ;
} else
F_106 ( V_630 , & V_10 -> V_66 ) ;
}
}
return 0 ;
}
static int F_270 ( struct V_92 * V_33 , struct V_169 * V_170 )
{
struct V_26 * V_27 ;
struct V_9 * V_10 ;
struct V_631 * V_315 = V_170 -> V_94 ;
T_2 * V_500 ;
int V_6 , V_632 = 0 ;
V_27 = F_150 ( V_33 , V_170 -> V_192 ) ;
if ( ! V_27 )
return F_254 ( V_33 , V_170 ) ;
V_10 = V_27 -> V_10 ;
V_500 = F_153 ( sizeof( T_2 ) * V_633 , V_212 ) ;
if ( ! V_500 ) {
F_41 ( V_10 , L_131 ) ;
return false ;
}
for ( V_6 = V_522 ; V_6 < V_633 ; V_6 ++ )
V_500 [ V_6 ] = F_179 ( V_315 -> V_498 [ V_6 ] ) ;
F_47 ( V_10 -> V_500 ) ;
V_10 -> V_500 = V_500 ;
if ( V_10 -> V_368 . V_103 < V_554 &&
V_10 -> V_368 . V_436 < V_424 &&
V_10 -> V_368 . V_516 == V_489 &&
( V_10 -> V_634 & ~ ( ( T_2 ) 1 ) ) != ( V_500 [ V_522 ] & ~ ( ( T_2 ) 1 ) ) ) {
F_41 ( V_10 , L_132 ,
( unsigned long long ) V_10 -> V_634 ) ;
F_66 ( V_27 -> V_33 , F_67 ( V_103 , V_149 ) , V_105 ) ;
return - V_106 ;
}
if ( F_126 ( V_10 ) ) {
int V_635 =
V_10 -> V_368 . V_103 == V_554 &&
V_27 -> V_33 -> V_184 >= 90 &&
V_10 -> V_246 -> V_497 . V_498 [ V_522 ] == V_527 &&
( V_500 [ V_530 ] & 8 ) ;
if ( V_635 ) {
F_63 ( V_10 , L_133 ) ;
F_243 ( V_10 , & V_636 ,
L_134 ,
V_637 ) ;
F_271 ( V_10 , V_522 , V_500 [ V_522 ] ) ;
F_271 ( V_10 , V_499 , 0 ) ;
F_272 ( F_273 ( V_10 , V_436 , V_462 , V_423 , V_462 ) ,
V_197 , NULL ) ;
F_266 ( V_10 ) ;
V_632 = 1 ;
}
F_129 ( V_10 ) ;
} else if ( V_10 -> V_368 . V_436 < V_424 &&
V_10 -> V_368 . V_516 == V_489 ) {
V_632 = F_274 ( V_10 , V_500 [ V_522 ] ) ;
}
F_115 ( V_10 -> V_183 ) ;
F_116 ( V_10 -> V_183 ) ;
if ( V_10 -> V_368 . V_103 >= V_554 && V_10 -> V_368 . V_436 < V_424 )
V_632 |= F_274 ( V_10 , V_500 [ V_522 ] ) ;
if ( V_632 )
F_275 ( V_10 , L_135 ) ;
return 0 ;
}
static union V_638 F_276 ( union V_638 V_639 )
{
union V_638 V_640 ;
static enum V_533 V_641 [] = {
[ V_101 ] = V_101 ,
[ V_554 ] = V_554 ,
[ V_642 ] = V_643 ,
[ V_643 ] = V_642 ,
[ V_149 ] = V_644 ,
[ V_451 ] = V_452 ,
[ V_538 ] = V_538 ,
} ;
V_640 . V_6 = V_639 . V_6 ;
V_640 . V_103 = V_641 [ V_639 . V_103 ] ;
V_640 . V_488 = V_639 . V_516 ;
V_640 . V_516 = V_639 . V_488 ;
V_640 . V_423 = V_639 . V_436 ;
V_640 . V_436 = V_639 . V_423 ;
V_640 . V_645 = ( V_639 . V_646 | V_639 . V_647 ) ;
return V_640 ;
}
static int F_277 ( struct V_92 * V_33 , struct V_169 * V_170 )
{
struct V_26 * V_27 ;
struct V_9 * V_10 ;
struct V_648 * V_315 = V_170 -> V_94 ;
union V_638 V_649 , V_650 ;
enum V_195 V_93 ;
V_27 = F_150 ( V_33 , V_170 -> V_192 ) ;
if ( ! V_27 )
return - V_106 ;
V_10 = V_27 -> V_10 ;
V_649 . V_6 = F_122 ( V_315 -> V_649 ) ;
V_650 . V_6 = F_122 ( V_315 -> V_650 ) ;
if ( F_64 ( V_204 , & V_27 -> V_33 -> V_66 ) &&
F_278 ( V_10 -> V_183 ) ) {
F_279 ( V_27 , V_651 ) ;
return 0 ;
}
V_649 = F_276 ( V_649 ) ;
V_650 = F_276 ( V_650 ) ;
V_93 = F_234 ( V_10 , V_197 , V_649 , V_650 ) ;
F_279 ( V_27 , V_93 ) ;
F_266 ( V_10 ) ;
return 0 ;
}
static int F_280 ( struct V_92 * V_33 , struct V_169 * V_170 )
{
struct V_648 * V_315 = V_170 -> V_94 ;
union V_638 V_649 , V_650 ;
enum V_195 V_93 ;
V_649 . V_6 = F_122 ( V_315 -> V_649 ) ;
V_650 . V_6 = F_122 ( V_315 -> V_650 ) ;
if ( F_64 ( V_204 , & V_33 -> V_66 ) &&
F_278 ( & V_33 -> V_185 ) ) {
F_281 ( V_33 , V_651 ) ;
return 0 ;
}
V_649 = F_276 ( V_649 ) ;
V_650 = F_276 ( V_650 ) ;
V_93 = F_66 ( V_33 , V_649 , V_650 , V_197 | V_652 | V_653 ) ;
F_281 ( V_33 , V_93 ) ;
return 0 ;
}
static int F_282 ( struct V_92 * V_33 , struct V_169 * V_170 )
{
struct V_26 * V_27 ;
struct V_9 * V_10 ;
struct V_654 * V_315 = V_170 -> V_94 ;
union V_638 V_655 , V_656 , V_657 ;
enum V_536 V_658 ;
enum V_659 V_660 ;
int V_93 ;
V_27 = F_150 ( V_33 , V_170 -> V_192 ) ;
if ( ! V_27 )
return F_254 ( V_33 , V_170 ) ;
V_10 = V_27 -> V_10 ;
V_657 . V_6 = F_122 ( V_315 -> V_368 ) ;
V_658 = V_657 . V_436 ;
if ( V_657 . V_436 == V_529 ) {
V_658 = V_10 -> V_500 [ V_530 ] & 4 ? V_424 : V_548 ;
F_63 ( V_10 , L_136 , F_283 ( V_658 ) ) ;
}
F_20 ( & V_10 -> V_24 -> V_25 ) ;
V_28:
V_655 = V_656 = F_284 ( V_10 ) ;
F_21 ( & V_10 -> V_24 -> V_25 ) ;
if ( V_655 . V_103 <= V_644 )
return - V_95 ;
if ( ( V_655 . V_423 == V_424 || V_655 . V_423 == V_548 ) &&
V_658 == V_462 &&
V_655 . V_103 > V_554 && V_655 . V_436 == V_462 ) {
if ( V_657 . V_103 > V_554 &&
V_657 . V_103 < V_369 )
V_658 = V_424 ;
else if ( V_655 . V_103 >= V_369 &&
V_657 . V_103 == V_554 ) {
if ( F_221 ( V_10 ) <= V_10 -> V_454 )
F_285 ( V_10 ) ;
return 0 ;
}
}
if ( V_655 . V_103 == V_452 && V_655 . V_436 == V_462 &&
V_657 . V_103 == V_554 && V_658 == V_462 ) {
F_286 ( V_10 ) ;
F_285 ( V_10 ) ;
return 0 ;
}
if ( V_655 . V_423 == V_462 && V_658 == V_424 &&
V_655 . V_103 == V_554 && V_657 . V_103 > V_369 )
V_658 = V_462 ;
if ( V_656 . V_103 == V_101 )
V_656 . V_103 = V_554 ;
if ( V_657 . V_103 == V_661 )
V_656 . V_103 = V_662 ;
if ( V_10 -> V_500 && V_657 . V_436 >= V_529 &&
F_224 ( V_10 , V_529 ) ) {
int V_663 ;
V_663 = ( V_655 . V_103 < V_554 ) ;
V_663 |= ( V_655 . V_103 == V_554 &&
( V_657 . V_436 == V_529 ||
V_655 . V_436 == V_529 ) ) ;
V_663 |= F_64 ( V_664 , & V_10 -> V_66 ) ;
V_663 |= ( V_655 . V_103 == V_554 &&
( V_657 . V_103 >= V_642 &&
V_657 . V_103 <= V_553 ) ) ;
if ( V_663 )
V_656 . V_103 = F_241 ( V_27 , V_657 . V_516 , V_658 ) ;
F_129 ( V_10 ) ;
if ( V_656 . V_103 == V_538 ) {
V_656 . V_103 = V_554 ;
if ( V_10 -> V_368 . V_436 == V_529 ) {
F_287 ( V_10 , F_67 ( V_436 , V_665 ) ) ;
} else if ( V_657 . V_436 == V_529 ) {
F_41 ( V_10 , L_137 ) ;
V_657 . V_436 = V_666 ;
V_658 = V_666 ;
} else {
if ( F_268 ( V_549 , & V_27 -> V_33 -> V_66 ) )
return - V_106 ;
F_48 ( V_10 , V_655 . V_103 == V_101 ) ;
F_66 ( V_27 -> V_33 , F_67 ( V_103 , V_149 ) , V_105 ) ;
return - V_106 ;
}
}
}
F_20 ( & V_10 -> V_24 -> V_25 ) ;
if ( V_655 . V_6 != F_284 ( V_10 ) . V_6 )
goto V_28;
F_101 ( V_664 , & V_10 -> V_66 ) ;
V_656 . V_488 = V_657 . V_516 ;
V_656 . V_423 = V_658 ;
V_656 . V_645 = ( V_657 . V_646 | V_657 . V_647 ) ;
if ( ( V_656 . V_103 == V_554 || V_656 . V_103 == V_552 ) && V_656 . V_436 == V_529 )
V_656 . V_436 = V_10 -> V_542 . V_436 ;
V_660 = V_197 + ( V_655 . V_103 < V_554 && V_656 . V_103 >= V_554 ? 0 : V_105 ) ;
if ( V_656 . V_423 == V_548 && F_288 ( V_10 ) && V_656 . V_103 == V_554 && V_655 . V_103 < V_554 &&
F_64 ( V_667 , & V_10 -> V_66 ) ) {
F_21 ( & V_10 -> V_24 -> V_25 ) ;
F_41 ( V_10 , L_138 ) ;
F_289 ( V_27 -> V_33 ) ;
F_290 ( V_10 ) ;
F_101 ( V_667 , & V_10 -> V_66 ) ;
F_66 ( V_27 -> V_33 , F_291 ( V_103 , V_668 , V_669 , 0 ) , V_105 ) ;
return - V_106 ;
}
V_93 = F_272 ( V_10 , V_656 , V_660 , NULL ) ;
V_656 = F_284 ( V_10 ) ;
F_21 ( & V_10 -> V_24 -> V_25 ) ;
if ( V_93 < V_198 ) {
F_66 ( V_27 -> V_33 , F_67 ( V_103 , V_149 ) , V_105 ) ;
return - V_106 ;
}
if ( V_655 . V_103 > V_101 ) {
if ( V_656 . V_103 > V_554 && V_657 . V_103 <= V_554 &&
V_657 . V_436 != V_529 ) {
F_99 ( V_27 ) ;
F_100 ( V_27 ) ;
}
}
F_101 ( V_223 , & V_10 -> V_66 ) ;
F_266 ( V_10 ) ;
return 0 ;
}
static int F_292 ( struct V_92 * V_33 , struct V_169 * V_170 )
{
struct V_26 * V_27 ;
struct V_9 * V_10 ;
struct V_670 * V_315 = V_170 -> V_94 ;
V_27 = F_150 ( V_33 , V_170 -> V_192 ) ;
if ( ! V_27 )
return - V_106 ;
V_10 = V_27 -> V_10 ;
F_212 ( V_10 -> V_311 ,
V_10 -> V_368 . V_103 == V_671 ||
V_10 -> V_368 . V_103 == V_662 ||
V_10 -> V_368 . V_103 < V_554 ||
V_10 -> V_368 . V_436 < V_529 ) ;
if ( F_224 ( V_10 , V_529 ) ) {
F_271 ( V_10 , V_522 , F_179 ( V_315 -> V_498 ) ) ;
F_271 ( V_10 , V_499 , 0UL ) ;
F_275 ( V_10 , L_139 ) ;
F_293 ( V_10 , V_422 ) ;
F_129 ( V_10 ) ;
} else
F_41 ( V_10 , L_140 ) ;
return 0 ;
}
static int
F_294 ( struct V_26 * V_27 , unsigned int V_61 ,
unsigned long * V_315 , struct V_672 * V_673 )
{
unsigned int V_49 = V_581 -
F_90 ( V_27 -> V_33 ) ;
unsigned int V_674 = F_72 ( T_6 , V_49 / sizeof( * V_315 ) ,
V_673 -> V_675 - V_673 -> V_676 ) ;
unsigned int V_677 = V_674 * sizeof( * V_315 ) ;
int V_74 ;
if ( V_677 != V_61 ) {
F_41 ( V_27 , L_141 , V_58 , V_677 , V_61 ) ;
return - V_106 ;
}
if ( V_677 == 0 )
return 0 ;
V_74 = F_68 ( V_27 -> V_33 , V_315 , V_677 ) ;
if ( V_74 )
return V_74 ;
F_295 ( V_27 -> V_10 , V_673 -> V_676 , V_674 , V_315 ) ;
V_673 -> V_676 += V_674 ;
V_673 -> V_678 = V_673 -> V_676 * V_679 ;
if ( V_673 -> V_678 > V_673 -> V_680 )
V_673 -> V_678 = V_673 -> V_680 ;
return 1 ;
}
static enum V_681 F_296 ( struct V_682 * V_315 )
{
return (enum V_681 ) ( V_315 -> V_683 & 0x0f ) ;
}
static int F_297 ( struct V_682 * V_315 )
{
return ( V_315 -> V_683 & 0x80 ) != 0 ;
}
static int F_298 ( struct V_682 * V_315 )
{
return ( V_315 -> V_683 >> 4 ) & 0x7 ;
}
static int
F_299 ( struct V_26 * V_27 ,
struct V_682 * V_315 ,
struct V_672 * V_673 ,
unsigned int V_5 )
{
struct V_684 V_685 ;
T_2 V_686 ;
T_2 V_687 ;
T_2 V_4 ;
unsigned long V_202 = V_673 -> V_678 ;
unsigned long V_688 ;
int V_689 = F_297 ( V_315 ) ;
int V_690 ;
int V_521 ;
F_300 ( & V_685 , V_315 -> V_691 , V_5 , F_298 ( V_315 ) ) ;
V_521 = F_301 ( & V_685 , & V_686 , 64 ) ;
if ( V_521 < 0 )
return - V_106 ;
for ( V_690 = V_521 ; V_690 > 0 ; V_202 += V_687 , V_689 = ! V_689 ) {
V_521 = F_302 ( & V_687 , V_686 ) ;
if ( V_521 <= 0 )
return - V_106 ;
if ( V_689 ) {
V_688 = V_202 + V_687 - 1 ;
if ( V_688 >= V_673 -> V_680 ) {
F_41 ( V_27 , L_142 , V_688 ) ;
return - V_106 ;
}
F_303 ( V_27 -> V_10 , V_202 , V_688 ) ;
}
if ( V_690 < V_521 ) {
F_41 ( V_27 , L_143 ,
V_690 , V_521 , V_686 ,
( unsigned int ) ( V_685 . V_692 . V_378 - V_315 -> V_691 ) ,
( unsigned int ) V_685 . V_693 ) ;
return - V_106 ;
}
if ( F_168 ( V_521 < 64 ) )
V_686 >>= V_521 ;
else
V_686 = 0 ;
V_690 -= V_521 ;
V_521 = F_301 ( & V_685 , & V_4 , 64 - V_690 ) ;
if ( V_521 < 0 )
return - V_106 ;
V_686 |= V_4 << V_690 ;
V_690 += V_521 ;
}
V_673 -> V_678 = V_202 ;
F_304 ( V_673 ) ;
return ( V_202 != V_673 -> V_680 ) ;
}
static int
F_305 ( struct V_26 * V_27 ,
struct V_682 * V_315 ,
struct V_672 * V_673 ,
unsigned int V_5 )
{
if ( F_296 ( V_315 ) == V_694 )
return F_299 ( V_27 , V_315 , V_673 , V_5 - sizeof( * V_315 ) ) ;
F_41 ( V_27 , L_144 , V_315 -> V_683 ) ;
F_66 ( V_27 -> V_33 , F_67 ( V_103 , V_668 ) , V_105 ) ;
return - V_106 ;
}
void F_306 ( struct V_9 * V_10 ,
const char * V_695 , struct V_672 * V_673 )
{
unsigned int V_168 = F_90 ( F_139 ( V_10 ) -> V_33 ) ;
unsigned int V_49 = V_581 - V_168 ;
unsigned int V_696 =
V_168 * ( F_307 ( V_673 -> V_675 , V_49 ) + 1 ) +
V_673 -> V_675 * sizeof( unsigned long ) ;
unsigned int V_697 = V_673 -> V_698 [ 0 ] + V_673 -> V_698 [ 1 ] ;
unsigned int V_699 ;
if ( V_697 == 0 )
return;
if ( V_697 >= V_696 )
return;
V_699 = ( V_697 > V_40 / 1000 ) ? ( V_697 / ( V_696 / 1000 ) )
: ( 1000 * V_697 / V_696 ) ;
if ( V_699 > 1000 )
V_699 = 1000 ;
V_699 = 1000 - V_699 ;
F_63 ( V_10 , L_145
L_146 ,
V_695 ,
V_673 -> V_698 [ 1 ] , V_673 -> V_700 [ 1 ] ,
V_673 -> V_698 [ 0 ] , V_673 -> V_700 [ 0 ] ,
V_697 , V_699 / 10 , V_699 % 10 ) ;
}
static int F_308 ( struct V_92 * V_33 , struct V_169 * V_170 )
{
struct V_26 * V_27 ;
struct V_9 * V_10 ;
struct V_672 V_673 ;
int V_74 ;
V_27 = F_150 ( V_33 , V_170 -> V_192 ) ;
if ( ! V_27 )
return - V_106 ;
V_10 = V_27 -> V_10 ;
F_309 ( V_10 , L_147 , V_551 ) ;
V_673 = (struct V_672 ) {
. V_680 = F_229 ( V_10 ) ,
. V_675 = F_310 ( V_10 ) ,
} ;
for(; ; ) {
if ( V_170 -> V_167 == V_701 )
V_74 = F_294 ( V_27 , V_170 -> V_61 , V_170 -> V_94 , & V_673 ) ;
else if ( V_170 -> V_167 == V_702 ) {
struct V_682 * V_315 = V_170 -> V_94 ;
if ( V_170 -> V_61 > V_581 - F_90 ( V_33 ) ) {
F_41 ( V_10 , L_148 ) ;
V_74 = - V_106 ;
goto V_102;
}
if ( V_170 -> V_61 <= sizeof( * V_315 ) ) {
F_41 ( V_10 , L_149 , V_170 -> V_61 ) ;
V_74 = - V_106 ;
goto V_102;
}
V_74 = F_68 ( V_27 -> V_33 , V_315 , V_170 -> V_61 ) ;
if ( V_74 )
goto V_102;
V_74 = F_305 ( V_27 , V_315 , & V_673 , V_170 -> V_61 ) ;
} else {
F_31 ( V_10 , L_150 , V_170 -> V_167 ) ;
V_74 = - V_106 ;
goto V_102;
}
V_673 . V_700 [ V_170 -> V_167 == V_701 ] ++ ;
V_673 . V_698 [ V_170 -> V_167 == V_701 ] += F_90 ( V_33 ) + V_170 -> V_61 ;
if ( V_74 <= 0 ) {
if ( V_74 < 0 )
goto V_102;
break;
}
V_74 = F_124 ( V_27 -> V_33 , V_170 ) ;
if ( V_74 )
goto V_102;
}
F_306 ( V_10 , L_151 , & V_673 ) ;
if ( V_10 -> V_368 . V_103 == V_553 ) {
enum V_195 V_93 ;
V_74 = F_311 ( V_10 ) ;
if ( V_74 )
goto V_102;
V_93 = F_312 ( V_10 , F_67 ( V_103 , V_671 ) , V_197 ) ;
F_48 ( V_10 , V_93 == V_198 ) ;
} else if ( V_10 -> V_368 . V_103 != V_552 ) {
F_63 ( V_10 , L_152 ,
F_242 ( V_10 -> V_368 . V_103 ) ) ;
}
V_74 = 0 ;
V_102:
F_313 ( V_10 ) ;
if ( ! V_74 && V_10 -> V_368 . V_103 == V_552 )
F_293 ( V_10 , V_369 ) ;
return V_74 ;
}
static int F_314 ( struct V_92 * V_33 , struct V_169 * V_170 )
{
F_31 ( V_33 , L_153 ,
V_170 -> V_167 , V_170 -> V_61 ) ;
return F_253 ( V_33 , V_170 ) ;
}
static int F_315 ( struct V_92 * V_33 , struct V_169 * V_170 )
{
F_316 ( V_33 -> V_94 . V_80 ) ;
return 0 ;
}
static int F_317 ( struct V_92 * V_33 , struct V_169 * V_170 )
{
struct V_26 * V_27 ;
struct V_9 * V_10 ;
struct V_703 * V_315 = V_170 -> V_94 ;
V_27 = F_150 ( V_33 , V_170 -> V_192 ) ;
if ( ! V_27 )
return - V_106 ;
V_10 = V_27 -> V_10 ;
switch ( V_10 -> V_368 . V_103 ) {
case V_671 :
case V_553 :
case V_662 :
break;
default:
F_41 ( V_10 , L_154 ,
F_242 ( V_10 -> V_368 . V_103 ) ) ;
}
F_213 ( V_10 , F_179 ( V_315 -> V_48 ) , F_122 ( V_315 -> V_461 ) ) ;
return 0 ;
}
static void F_318 ( struct V_92 * V_33 )
{
struct V_169 V_170 ;
T_6 V_704 ;
int V_74 ;
while ( F_109 ( & V_33 -> V_209 ) == V_705 ) {
struct V_706 * V_167 ;
F_319 ( & V_33 -> V_209 ) ;
F_230 ( V_33 , F_124 ) ;
if ( F_124 ( V_33 , & V_170 ) )
goto V_707;
V_167 = & V_708 [ V_170 . V_167 ] ;
if ( F_180 ( V_170 . V_167 >= F_320 ( V_708 ) || ! V_167 -> V_709 ) ) {
F_41 ( V_33 , L_155 ,
F_255 ( V_170 . V_167 ) , V_170 . V_167 ) ;
goto V_707;
}
V_704 = V_167 -> V_710 ;
if ( V_170 . V_61 > V_704 && ! V_167 -> V_711 ) {
F_41 ( V_33 , L_156 ,
F_255 ( V_170 . V_167 ) , V_170 . V_61 ) ;
goto V_707;
}
if ( V_704 ) {
F_230 ( V_33 , F_69 ) ;
V_74 = F_69 ( V_33 , V_170 . V_94 , V_704 ) ;
if ( V_74 )
goto V_707;
V_170 . V_61 -= V_704 ;
}
F_230 ( V_33 , V_167 -> V_709 ) ;
V_74 = V_167 -> V_709 ( V_33 , & V_170 ) ;
if ( V_74 ) {
F_41 ( V_33 , L_157 ,
F_255 ( V_170 . V_167 ) , V_74 , V_170 . V_61 ) ;
goto V_707;
}
}
return;
V_707:
F_66 ( V_33 , F_67 ( V_103 , V_668 ) , V_105 ) ;
}
static void F_321 ( struct V_92 * V_33 )
{
struct V_26 * V_27 ;
enum V_533 V_712 ;
int V_192 ;
if ( V_33 -> V_100 == V_713 )
return;
F_66 ( V_33 , F_67 ( V_103 , V_714 ) , V_105 ) ;
F_322 ( & V_33 -> V_225 ) ;
F_323 ( V_33 ) ;
F_25 () ;
F_114 (&connection->peer_devices, peer_device, vnr) {
struct V_9 * V_10 = V_27 -> V_10 ;
F_117 ( & V_10 -> V_222 ) ;
F_27 () ;
F_324 ( V_27 ) ;
F_118 ( & V_10 -> V_222 , V_224 ) ;
F_25 () ;
}
F_27 () ;
if ( ! F_57 ( & V_33 -> V_265 -> V_21 ) )
F_41 ( V_33 , L_158 ) ;
F_96 ( & V_33 -> V_265 -> V_254 , 0 ) ;
V_33 -> V_715 . V_716 = false ;
F_63 ( V_33 , L_159 ) ;
if ( F_325 ( V_33 ) == V_489 && F_326 ( V_33 ) >= V_717 )
F_327 ( V_33 ) ;
F_20 ( & V_33 -> V_24 -> V_25 ) ;
V_712 = V_33 -> V_100 ;
if ( V_712 >= V_718 )
F_207 ( V_33 , F_67 ( V_103 , V_718 ) , V_197 ) ;
F_21 ( & V_33 -> V_24 -> V_25 ) ;
if ( V_712 == V_149 )
F_66 ( V_33 , F_67 ( V_103 , V_713 ) , V_197 | V_105 ) ;
}
static int F_324 ( struct V_26 * V_27 )
{
struct V_9 * V_10 = V_27 -> V_10 ;
unsigned int V_6 ;
F_20 ( & V_10 -> V_24 -> V_25 ) ;
F_56 ( V_10 , & V_10 -> V_290 ) ;
F_56 ( V_10 , & V_10 -> V_348 ) ;
F_56 ( V_10 , & V_10 -> V_487 ) ;
F_21 ( & V_10 -> V_24 -> V_25 ) ;
F_328 ( V_10 ) ;
V_10 -> V_485 = 0 ;
V_10 -> V_454 = 0 ;
F_96 ( & V_10 -> V_719 , 0 ) ;
F_37 ( & V_10 -> V_311 ) ;
F_329 ( & V_10 -> V_720 ) ;
F_330 ( ( unsigned long ) V_10 ) ;
F_331 ( & V_27 -> V_33 -> V_721 ) ;
F_54 ( V_10 ) ;
F_331 ( & V_27 -> V_33 -> V_721 ) ;
F_328 ( V_10 ) ;
F_47 ( V_10 -> V_500 ) ;
V_10 -> V_500 = NULL ;
if ( ! F_288 ( V_10 ) )
F_289 ( V_27 -> V_33 ) ;
F_266 ( V_10 ) ;
F_212 ( V_10 -> V_311 , ! F_64 ( V_722 , & V_10 -> V_66 ) ) ;
V_6 = F_52 ( V_10 , & V_10 -> V_73 ) ;
if ( V_6 )
F_63 ( V_10 , L_160 , V_6 ) ;
V_6 = F_28 ( & V_10 -> V_43 ) ;
if ( V_6 )
F_63 ( V_10 , L_161 , V_6 ) ;
V_6 = F_28 ( & V_10 -> V_35 ) ;
if ( V_6 )
F_63 ( V_10 , L_162 , V_6 ) ;
F_48 ( V_10 , F_57 ( & V_10 -> V_487 ) ) ;
F_48 ( V_10 , F_57 ( & V_10 -> V_290 ) ) ;
F_48 ( V_10 , F_57 ( & V_10 -> V_348 ) ) ;
F_48 ( V_10 , F_57 ( & V_10 -> V_75 ) ) ;
return 0 ;
}
static int F_332 ( struct V_92 * V_33 )
{
struct V_165 * V_81 ;
struct V_723 * V_315 ;
V_81 = & V_33 -> V_94 ;
V_315 = F_87 ( V_33 , V_81 ) ;
if ( ! V_315 )
return - V_106 ;
memset ( V_315 , 0 , sizeof( * V_315 ) ) ;
V_315 -> V_724 = F_120 ( V_725 ) ;
V_315 -> V_726 = F_120 ( V_727 ) ;
V_315 -> V_728 = F_120 ( V_729 ) ;
return F_88 ( V_33 , V_81 , V_730 , sizeof( * V_315 ) , NULL , 0 ) ;
}
static int F_111 ( struct V_92 * V_33 )
{
struct V_723 * V_315 ;
const int F_50 = sizeof( struct V_723 ) ;
struct V_169 V_170 ;
int V_74 ;
V_74 = F_332 ( V_33 ) ;
if ( V_74 )
return 0 ;
V_74 = F_124 ( V_33 , & V_170 ) ;
if ( V_74 )
return 0 ;
if ( V_170 . V_167 != V_730 ) {
F_41 ( V_33 , L_163 ,
F_255 ( V_170 . V_167 ) , V_170 . V_167 ) ;
return - 1 ;
}
if ( V_170 . V_61 != F_50 ) {
F_41 ( V_33 , L_164 ,
F_50 , V_170 . V_61 ) ;
return - 1 ;
}
V_315 = V_170 . V_94 ;
V_74 = F_69 ( V_33 , V_315 , F_50 ) ;
if ( V_74 )
return 0 ;
V_315 -> V_724 = F_122 ( V_315 -> V_724 ) ;
V_315 -> V_726 = F_122 ( V_315 -> V_726 ) ;
if ( V_315 -> V_726 == 0 )
V_315 -> V_726 = V_315 -> V_724 ;
if ( V_727 < V_315 -> V_724 ||
V_725 > V_315 -> V_726 )
goto V_731;
V_33 -> V_184 = F_72 ( int , V_727 , V_315 -> V_726 ) ;
V_33 -> V_732 = V_729 & F_122 ( V_315 -> V_728 ) ;
F_63 ( V_33 , L_165
L_166 , V_33 -> V_184 ) ;
F_63 ( V_33 , L_167 ,
V_33 -> V_732 & V_733 ? L_168 : L_169 ) ;
return 1 ;
V_731:
F_41 ( V_33 , L_170
L_171 ,
V_725 , V_727 ,
V_315 -> V_724 , V_315 -> V_726 ) ;
return - 1 ;
}
static int F_112 ( struct V_92 * V_33 )
{
F_41 ( V_33 , L_172 ) ;
F_41 ( V_33 , L_173 ) ;
return - 1 ;
}
static int F_112 ( struct V_92 * V_33 )
{
struct V_165 * V_81 ;
char V_734 [ V_735 ] ;
struct V_736 V_737 ;
char * V_738 = NULL ;
char * V_739 = NULL ;
char * V_740 = NULL ;
unsigned int V_741 ;
char V_742 [ V_566 ] ;
unsigned int V_743 ;
struct V_744 V_745 ;
struct V_169 V_170 ;
struct V_29 * V_30 ;
int V_74 , V_93 ;
F_25 () ;
V_30 = F_26 ( V_33 -> V_29 ) ;
V_741 = strlen ( V_30 -> V_746 ) ;
memcpy ( V_742 , V_30 -> V_746 , V_741 ) ;
F_27 () ;
V_745 . V_580 = V_33 -> V_218 ;
V_745 . V_66 = 0 ;
V_93 = F_333 ( V_33 -> V_218 , ( V_747 * ) V_742 , V_741 ) ;
if ( V_93 ) {
F_41 ( V_33 , L_174 , V_93 ) ;
V_93 = - 1 ;
goto V_60;
}
F_334 ( V_734 , V_735 ) ;
V_81 = & V_33 -> V_94 ;
if ( ! F_87 ( V_33 , V_81 ) ) {
V_93 = 0 ;
goto V_60;
}
V_93 = ! F_88 ( V_33 , V_81 , V_748 , 0 ,
V_734 , V_735 ) ;
if ( ! V_93 )
goto V_60;
V_74 = F_124 ( V_33 , & V_170 ) ;
if ( V_74 ) {
V_93 = 0 ;
goto V_60;
}
if ( V_170 . V_167 != V_748 ) {
F_41 ( V_33 , L_175 ,
F_255 ( V_170 . V_167 ) , V_170 . V_167 ) ;
V_93 = 0 ;
goto V_60;
}
if ( V_170 . V_61 > V_735 * 2 ) {
F_41 ( V_33 , L_176 ) ;
V_93 = - 1 ;
goto V_60;
}
if ( V_170 . V_61 < V_735 ) {
F_41 ( V_33 , L_177 ) ;
V_93 = - 1 ;
goto V_60;
}
V_740 = F_153 ( V_170 . V_61 , V_212 ) ;
if ( V_740 == NULL ) {
F_41 ( V_33 , L_178 ) ;
V_93 = - 1 ;
goto V_60;
}
V_74 = F_69 ( V_33 , V_740 , V_170 . V_61 ) ;
if ( V_74 ) {
V_93 = 0 ;
goto V_60;
}
if ( ! memcmp ( V_734 , V_740 , V_735 ) ) {
F_41 ( V_33 , L_179 ) ;
V_93 = - 1 ;
goto V_60;
}
V_743 = F_157 ( V_33 -> V_218 ) ;
V_738 = F_153 ( V_743 , V_212 ) ;
if ( V_738 == NULL ) {
F_41 ( V_33 , L_180 ) ;
V_93 = - 1 ;
goto V_60;
}
F_335 ( & V_737 , 1 ) ;
F_336 ( & V_737 , V_740 , V_170 . V_61 ) ;
V_93 = F_337 ( & V_745 , & V_737 , V_737 . V_235 , V_738 ) ;
if ( V_93 ) {
F_41 ( V_33 , L_181 , V_93 ) ;
V_93 = - 1 ;
goto V_60;
}
if ( ! F_87 ( V_33 , V_81 ) ) {
V_93 = 0 ;
goto V_60;
}
V_93 = ! F_88 ( V_33 , V_81 , V_749 , 0 ,
V_738 , V_743 ) ;
if ( ! V_93 )
goto V_60;
V_74 = F_124 ( V_33 , & V_170 ) ;
if ( V_74 ) {
V_93 = 0 ;
goto V_60;
}
if ( V_170 . V_167 != V_749 ) {
F_41 ( V_33 , L_182 ,
F_255 ( V_170 . V_167 ) , V_170 . V_167 ) ;
V_93 = 0 ;
goto V_60;
}
if ( V_170 . V_61 != V_743 ) {
F_41 ( V_33 , L_183 ) ;
V_93 = 0 ;
goto V_60;
}
V_74 = F_69 ( V_33 , V_738 , V_743 ) ;
if ( V_74 ) {
V_93 = 0 ;
goto V_60;
}
V_739 = F_153 ( V_743 , V_212 ) ;
if ( V_739 == NULL ) {
F_41 ( V_33 , L_184 ) ;
V_93 = - 1 ;
goto V_60;
}
F_336 ( & V_737 , V_734 , V_735 ) ;
V_93 = F_337 ( & V_745 , & V_737 , V_737 . V_235 , V_739 ) ;
if ( V_93 ) {
F_41 ( V_33 , L_181 , V_93 ) ;
V_93 = - 1 ;
goto V_60;
}
V_93 = ! memcmp ( V_738 , V_739 , V_743 ) ;
if ( V_93 )
F_63 ( V_33 , L_185 ,
V_743 ) ;
else
V_93 = - 1 ;
V_60:
F_47 ( V_740 ) ;
F_47 ( V_738 ) ;
F_47 ( V_739 ) ;
return V_93 ;
}
int F_338 ( struct V_750 * V_751 )
{
struct V_92 * V_33 = V_751 -> V_33 ;
int V_193 ;
F_63 ( V_33 , L_186 ) ;
do {
V_193 = F_103 ( V_33 ) ;
if ( V_193 == 0 ) {
F_321 ( V_33 ) ;
F_94 ( V_39 ) ;
}
if ( V_193 == - 1 ) {
F_31 ( V_33 , L_187 ) ;
F_66 ( V_33 , F_67 ( V_103 , V_149 ) , V_105 ) ;
}
} while ( V_193 == 0 );
if ( V_193 > 0 )
F_318 ( V_33 ) ;
F_321 ( V_33 ) ;
F_63 ( V_33 , L_188 ) ;
return 0 ;
}
static int F_339 ( struct V_92 * V_33 , struct V_169 * V_170 )
{
struct V_752 * V_315 = V_170 -> V_94 ;
int V_753 = F_122 ( V_315 -> V_753 ) ;
if ( V_753 >= V_198 ) {
F_106 ( V_754 , & V_33 -> V_66 ) ;
} else {
F_106 ( V_755 , & V_33 -> V_66 ) ;
F_41 ( V_33 , L_189 ,
F_340 ( V_753 ) , V_753 ) ;
}
F_37 ( & V_33 -> V_99 ) ;
return 0 ;
}
static int F_341 ( struct V_92 * V_33 , struct V_169 * V_170 )
{
struct V_26 * V_27 ;
struct V_9 * V_10 ;
struct V_752 * V_315 = V_170 -> V_94 ;
int V_753 = F_122 ( V_315 -> V_753 ) ;
V_27 = F_150 ( V_33 , V_170 -> V_192 ) ;
if ( ! V_27 )
return - V_106 ;
V_10 = V_27 -> V_10 ;
if ( F_64 ( V_756 , & V_33 -> V_66 ) ) {
F_48 ( V_10 , V_33 -> V_184 < 100 ) ;
return F_339 ( V_33 , V_170 ) ;
}
if ( V_753 >= V_198 ) {
F_106 ( V_757 , & V_10 -> V_66 ) ;
} else {
F_106 ( V_758 , & V_10 -> V_66 ) ;
F_41 ( V_10 , L_189 ,
F_340 ( V_753 ) , V_753 ) ;
}
F_37 ( & V_10 -> V_759 ) ;
return 0 ;
}
static int F_342 ( struct V_92 * V_33 , struct V_169 * V_170 )
{
return F_343 ( V_33 ) ;
}
static int F_344 ( struct V_92 * V_33 , struct V_169 * V_170 )
{
V_33 -> V_201 . V_80 -> V_109 -> V_136 = V_33 -> V_29 -> V_216 * V_39 ;
if ( ! F_345 ( V_760 , & V_33 -> V_66 ) )
F_37 ( & V_33 -> V_99 ) ;
return 0 ;
}
static int F_346 ( struct V_92 * V_33 , struct V_169 * V_170 )
{
struct V_26 * V_27 ;
struct V_9 * V_10 ;
struct V_761 * V_315 = V_170 -> V_94 ;
T_3 V_48 = F_179 ( V_315 -> V_48 ) ;
int V_461 = F_122 ( V_315 -> V_461 ) ;
V_27 = F_150 ( V_33 , V_170 -> V_192 ) ;
if ( ! V_27 )
return - V_106 ;
V_10 = V_27 -> V_10 ;
F_48 ( V_10 , V_27 -> V_33 -> V_184 >= 89 ) ;
F_194 ( V_27 , F_122 ( V_315 -> V_409 ) ) ;
if ( F_126 ( V_10 ) ) {
F_347 ( V_10 , V_48 ) ;
F_169 ( V_10 , V_48 , V_461 ) ;
V_10 -> V_762 += ( V_461 >> V_763 ) ;
F_129 ( V_10 ) ;
}
F_174 ( V_10 ) ;
F_34 ( V_461 >> 9 , & V_10 -> V_360 ) ;
return 0 ;
}
static int
F_348 ( struct V_9 * V_10 , T_2 V_47 , T_3 V_48 ,
struct V_352 * V_353 , const char * V_355 ,
enum V_764 V_115 , bool V_354 )
{
struct V_332 * V_333 ;
struct V_400 V_401 ;
F_20 ( & V_10 -> V_24 -> V_25 ) ;
V_333 = F_176 ( V_10 , V_353 , V_47 , V_48 , V_354 , V_355 ) ;
if ( F_180 ( ! V_333 ) ) {
F_21 ( & V_10 -> V_24 -> V_25 ) ;
return - V_106 ;
}
F_187 ( V_333 , V_115 , & V_401 ) ;
F_21 ( & V_10 -> V_24 -> V_25 ) ;
if ( V_401 . V_284 )
F_201 ( V_10 , & V_401 ) ;
return 0 ;
}
static int F_349 ( struct V_92 * V_33 , struct V_169 * V_170 )
{
struct V_26 * V_27 ;
struct V_9 * V_10 ;
struct V_761 * V_315 = V_170 -> V_94 ;
T_3 V_48 = F_179 ( V_315 -> V_48 ) ;
int V_461 = F_122 ( V_315 -> V_461 ) ;
enum V_764 V_115 ;
V_27 = F_150 ( V_33 , V_170 -> V_192 ) ;
if ( ! V_27 )
return - V_106 ;
V_10 = V_27 -> V_10 ;
F_194 ( V_27 , F_122 ( V_315 -> V_409 ) ) ;
if ( V_315 -> V_65 == V_347 ) {
F_169 ( V_10 , V_48 , V_461 ) ;
F_174 ( V_10 ) ;
return 0 ;
}
switch ( V_170 -> V_167 ) {
case V_345 :
V_115 = V_765 ;
break;
case V_372 :
V_115 = V_766 ;
break;
case V_420 :
V_115 = V_767 ;
break;
case V_376 :
V_115 = V_364 ;
break;
case V_377 :
V_115 = V_768 ;
break;
default:
F_227 () ;
}
return F_348 ( V_10 , V_315 -> V_65 , V_48 ,
& V_10 -> V_309 , V_58 ,
V_115 , false ) ;
}
static int F_350 ( struct V_92 * V_33 , struct V_169 * V_170 )
{
struct V_26 * V_27 ;
struct V_9 * V_10 ;
struct V_761 * V_315 = V_170 -> V_94 ;
T_3 V_48 = F_179 ( V_315 -> V_48 ) ;
int V_61 = F_122 ( V_315 -> V_461 ) ;
int V_74 ;
V_27 = F_150 ( V_33 , V_170 -> V_192 ) ;
if ( ! V_27 )
return - V_106 ;
V_10 = V_27 -> V_10 ;
F_194 ( V_27 , F_122 ( V_315 -> V_409 ) ) ;
if ( V_315 -> V_65 == V_347 ) {
F_174 ( V_10 ) ;
F_171 ( V_10 , V_48 , V_61 ) ;
return 0 ;
}
V_74 = F_348 ( V_10 , V_315 -> V_65 , V_48 ,
& V_10 -> V_309 , V_58 ,
V_402 , true ) ;
if ( V_74 ) {
F_213 ( V_10 , V_48 , V_61 ) ;
}
return 0 ;
}
static int F_351 ( struct V_92 * V_33 , struct V_169 * V_170 )
{
struct V_26 * V_27 ;
struct V_9 * V_10 ;
struct V_761 * V_315 = V_170 -> V_94 ;
T_3 V_48 = F_179 ( V_315 -> V_48 ) ;
V_27 = F_150 ( V_33 , V_170 -> V_192 ) ;
if ( ! V_27 )
return - V_106 ;
V_10 = V_27 -> V_10 ;
F_194 ( V_27 , F_122 ( V_315 -> V_409 ) ) ;
F_41 ( V_10 , L_190 ,
( unsigned long long ) V_48 , F_122 ( V_315 -> V_461 ) ) ;
return F_348 ( V_10 , V_315 -> V_65 , V_48 ,
& V_10 -> V_357 , V_58 ,
V_402 , false ) ;
}
static int F_352 ( struct V_92 * V_33 , struct V_169 * V_170 )
{
struct V_26 * V_27 ;
struct V_9 * V_10 ;
T_3 V_48 ;
int V_61 ;
struct V_761 * V_315 = V_170 -> V_94 ;
V_27 = F_150 ( V_33 , V_170 -> V_192 ) ;
if ( ! V_27 )
return - V_106 ;
V_10 = V_27 -> V_10 ;
V_48 = F_179 ( V_315 -> V_48 ) ;
V_61 = F_122 ( V_315 -> V_461 ) ;
F_194 ( V_27 , F_122 ( V_315 -> V_409 ) ) ;
F_174 ( V_10 ) ;
if ( F_224 ( V_10 , V_665 ) ) {
F_347 ( V_10 , V_48 ) ;
switch ( V_170 -> V_167 ) {
case V_468 :
F_171 ( V_10 , V_48 , V_61 ) ;
case V_769 :
break;
default:
F_227 () ;
}
F_129 ( V_10 ) ;
}
return 0 ;
}
static int F_353 ( struct V_92 * V_33 , struct V_169 * V_170 )
{
struct V_770 * V_315 = V_170 -> V_94 ;
struct V_26 * V_27 ;
int V_192 ;
F_354 ( V_33 , V_315 -> V_316 , F_122 ( V_315 -> V_771 ) ) ;
F_25 () ;
F_114 (&connection->peer_devices, peer_device, vnr) {
struct V_9 * V_10 = V_27 -> V_10 ;
if ( V_10 -> V_368 . V_103 == V_661 &&
F_28 ( & V_10 -> V_189 ) == 0 &&
! F_345 ( V_772 , & V_10 -> V_66 ) ) {
V_10 -> V_773 . V_774 = V_63 + V_39 ;
F_355 ( & V_10 -> V_773 ) ;
}
}
F_27 () ;
return 0 ;
}
static int F_356 ( struct V_92 * V_33 , struct V_169 * V_170 )
{
struct V_26 * V_27 ;
struct V_9 * V_10 ;
struct V_761 * V_315 = V_170 -> V_94 ;
struct V_775 * V_776 ;
T_3 V_48 ;
int V_61 ;
V_27 = F_150 ( V_33 , V_170 -> V_192 ) ;
if ( ! V_27 )
return - V_106 ;
V_10 = V_27 -> V_10 ;
V_48 = F_179 ( V_315 -> V_48 ) ;
V_61 = F_122 ( V_315 -> V_461 ) ;
F_194 ( V_27 , F_122 ( V_315 -> V_409 ) ) ;
if ( F_179 ( V_315 -> V_65 ) == V_777 )
F_357 ( V_10 , V_48 , V_61 ) ;
else
F_286 ( V_10 ) ;
if ( ! F_126 ( V_10 ) )
return 0 ;
F_347 ( V_10 , V_48 ) ;
F_174 ( V_10 ) ;
-- V_10 -> V_453 ;
if ( ( V_10 -> V_453 & 0x200 ) == 0x200 )
F_358 ( V_10 , V_10 -> V_453 ) ;
if ( V_10 -> V_453 == 0 ) {
V_776 = F_153 ( sizeof( * V_776 ) , V_212 ) ;
if ( V_776 ) {
V_776 -> V_20 . V_77 = V_778 ;
V_776 -> V_10 = V_10 ;
F_359 ( & V_27 -> V_33 -> V_721 , & V_776 -> V_20 ) ;
} else {
F_41 ( V_10 , L_191 ) ;
F_286 ( V_10 ) ;
F_285 ( V_10 ) ;
}
}
F_129 ( V_10 ) ;
return 0 ;
}
static int F_360 ( struct V_92 * V_33 , struct V_169 * V_170 )
{
return 0 ;
}
static int F_361 ( struct V_92 * V_33 )
{
struct V_26 * V_27 ;
int V_192 , V_779 = 0 ;
do {
F_101 ( V_780 , & V_33 -> V_66 ) ;
F_107 ( V_38 ) ;
F_25 () ;
F_114 (&connection->peer_devices, peer_device, vnr) {
struct V_9 * V_10 = V_27 -> V_10 ;
F_117 ( & V_10 -> V_222 ) ;
F_27 () ;
if ( F_54 ( V_10 ) ) {
F_118 ( & V_10 -> V_222 , V_224 ) ;
return 1 ;
}
F_118 ( & V_10 -> V_222 , V_224 ) ;
F_25 () ;
}
F_106 ( V_780 , & V_33 -> V_66 ) ;
F_20 ( & V_33 -> V_24 -> V_25 ) ;
F_114 (&connection->peer_devices, peer_device, vnr) {
struct V_9 * V_10 = V_27 -> V_10 ;
V_779 = ! F_57 ( & V_10 -> V_75 ) ;
if ( V_779 )
break;
}
F_21 ( & V_33 -> V_24 -> V_25 ) ;
F_27 () ;
} while ( V_779 );
return 0 ;
}
int F_362 ( struct V_750 * V_751 )
{
struct V_92 * V_33 = V_751 -> V_33 ;
struct V_781 * V_167 = NULL ;
struct V_169 V_170 ;
int V_93 ;
void * V_82 = V_33 -> V_201 . V_171 ;
int V_782 = 0 ;
unsigned int V_168 = F_90 ( V_33 ) ;
int F_50 = V_168 ;
bool V_783 = false ;
struct V_29 * V_30 ;
int V_98 , V_784 , V_216 ;
struct V_785 V_786 = { . V_787 = 2 } ;
V_93 = F_363 ( V_38 , V_788 , & V_786 ) ;
if ( V_93 < 0 )
F_41 ( V_33 , L_192 , V_93 ) ;
while ( F_109 ( V_751 ) == V_705 ) {
F_319 ( V_751 ) ;
F_25 () ;
V_30 = F_26 ( V_33 -> V_29 ) ;
V_98 = V_30 -> V_98 ;
V_784 = V_30 -> V_784 ;
V_216 = V_30 -> V_216 ;
F_27 () ;
if ( F_268 ( V_789 , & V_33 -> V_66 ) ) {
if ( F_364 ( V_33 ) ) {
F_41 ( V_33 , L_193 ) ;
goto V_597;
}
V_33 -> V_201 . V_80 -> V_109 -> V_136 = V_98 * V_39 / 10 ;
V_783 = true ;
}
if ( V_784 )
F_365 ( V_33 -> V_201 . V_80 ) ;
if ( F_361 ( V_33 ) ) {
F_41 ( V_33 , L_194 ) ;
goto V_597;
}
if ( V_784 )
F_366 ( V_33 -> V_201 . V_80 ) ;
if ( F_30 ( V_38 ) )
continue;
V_93 = F_60 ( V_33 -> V_201 . V_80 , V_82 , F_50 - V_782 , 0 ) ;
F_101 ( V_780 , & V_33 -> V_66 ) ;
F_107 ( V_38 ) ;
V_790:
if ( F_168 ( V_93 > 0 ) ) {
V_782 += V_93 ;
V_82 += V_93 ;
} else if ( V_93 == 0 ) {
if ( F_64 ( V_97 , & V_33 -> V_66 ) ) {
long V_23 ;
F_25 () ;
V_23 = F_26 ( V_33 -> V_29 ) -> V_98 * V_39 / 10 ;
F_27 () ;
V_23 = F_65 ( V_33 -> V_99 ,
V_33 -> V_100 < V_101 ,
V_23 ) ;
if ( V_23 )
break;
}
F_41 ( V_33 , L_195 ) ;
goto V_597;
} else if ( V_93 == - V_142 ) {
if ( F_367 ( V_33 -> V_217 ,
V_63 - V_33 -> V_201 . V_80 -> V_109 -> V_136 ) )
continue;
if ( V_783 ) {
F_41 ( V_33 , L_196 ) ;
goto V_597;
}
F_106 ( V_789 , & V_33 -> V_66 ) ;
continue;
} else if ( V_93 == - V_144 ) {
continue;
} else {
F_41 ( V_33 , L_7 , V_93 ) ;
goto V_597;
}
if ( V_782 == F_50 && V_167 == NULL ) {
if ( F_91 ( V_33 , V_33 -> V_201 . V_171 , & V_170 ) )
goto V_597;
V_167 = & V_791 [ V_170 . V_167 ] ;
if ( V_170 . V_167 >= F_320 ( V_791 ) || ! V_167 -> V_709 ) {
F_41 ( V_33 , L_197 ,
F_255 ( V_170 . V_167 ) , V_170 . V_167 ) ;
goto V_576;
}
F_50 = V_168 + V_167 -> V_710 ;
if ( V_170 . V_61 != F_50 - V_168 ) {
F_41 ( V_33 , L_198 ,
V_170 . V_167 , V_170 . V_61 ) ;
goto V_597;
}
}
if ( V_782 == F_50 ) {
bool V_74 ;
V_74 = V_167 -> V_709 ( V_33 , & V_170 ) ;
if ( V_74 ) {
F_41 ( V_33 , L_199 , V_167 -> V_709 ) ;
goto V_597;
}
V_33 -> V_217 = V_63 ;
if ( V_167 == & V_791 [ V_792 ] ) {
V_33 -> V_201 . V_80 -> V_109 -> V_136 = V_216 * V_39 ;
V_783 = false ;
}
V_82 = V_33 -> V_201 . V_171 ;
V_782 = 0 ;
F_50 = V_168 ;
V_167 = NULL ;
}
if ( F_64 ( V_789 , & V_33 -> V_66 ) )
continue;
V_93 = F_60 ( V_33 -> V_201 . V_80 , V_82 , F_50 - V_782 , V_174 ) ;
if ( V_93 > 0 )
goto V_790;
}
if ( 0 ) {
V_597:
F_66 ( V_33 , F_67 ( V_103 , V_714 ) , V_105 ) ;
F_368 ( V_33 ) ;
}
if ( 0 ) {
V_576:
F_66 ( V_33 , F_67 ( V_103 , V_149 ) , V_105 ) ;
}
F_101 ( V_780 , & V_33 -> V_66 ) ;
F_63 ( V_33 , L_200 ) ;
return 0 ;
}
