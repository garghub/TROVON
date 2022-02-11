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
V_1 = F_23 ( V_27 , V_52 ,
F_42 ( V_51 ) ) ;
if ( ! V_1 )
goto V_59;
}
memset ( V_19 , 0 , sizeof( * V_19 ) ) ;
F_43 ( & V_19 -> V_20 . V_21 ) ;
F_44 ( & V_19 -> V_6 ) ;
V_19 -> V_6 . V_60 = V_49 ;
V_19 -> V_6 . V_48 = V_48 ;
V_19 -> V_61 = V_62 ;
V_19 -> V_27 = V_27 ;
V_19 -> V_63 = V_1 ;
V_19 -> V_64 = V_47 ;
return V_19 ;
V_59:
F_45 ( V_19 , V_55 ) ;
return NULL ;
}
void F_46 ( struct V_9 * V_10 , struct V_18 * V_19 ,
int V_41 )
{
F_47 () ;
if ( V_19 -> V_65 & V_66 )
F_48 ( V_19 -> V_67 ) ;
F_35 ( V_10 , V_19 -> V_63 , V_41 ) ;
F_49 ( V_10 , F_28 ( & V_19 -> V_68 ) == 0 ) ;
F_49 ( V_10 , F_50 ( & V_19 -> V_6 ) ) ;
if ( ! F_51 ( ! ( V_19 -> V_65 & V_69 ) ) ) {
V_19 -> V_65 &= ~ V_69 ;
F_52 ( V_10 , & V_19 -> V_6 ) ;
}
F_45 ( V_19 , V_55 ) ;
}
int F_53 ( struct V_9 * V_10 , struct V_16 * V_21 )
{
F_19 ( V_70 ) ;
struct V_18 * V_19 , * V_23 ;
int V_71 = 0 ;
int V_41 = V_21 == & V_10 -> V_72 ;
F_20 ( & V_10 -> V_24 -> V_25 ) ;
F_54 ( V_21 , & V_70 ) ;
F_21 ( & V_10 -> V_24 -> V_25 ) ;
F_15 (peer_req, t, &work_list, w.list) {
F_46 ( V_10 , V_19 , V_41 ) ;
V_71 ++ ;
}
return V_71 ;
}
static int F_55 ( struct V_9 * V_10 )
{
F_19 ( V_70 ) ;
F_19 ( V_22 ) ;
struct V_18 * V_19 , * V_23 ;
int V_73 = 0 ;
F_20 ( & V_10 -> V_24 -> V_25 ) ;
F_14 ( V_10 , & V_22 ) ;
F_54 ( & V_10 -> V_74 , & V_70 ) ;
F_21 ( & V_10 -> V_24 -> V_25 ) ;
F_15 (peer_req, t, &reclaimed, w.list)
F_22 ( V_10 , V_19 ) ;
F_15 (peer_req, t, &work_list, w.list) {
int V_75 ;
V_75 = V_19 -> V_20 . V_76 ( & V_19 -> V_20 , ! ! V_73 ) ;
if ( ! V_73 )
V_73 = V_75 ;
F_56 ( V_10 , V_19 ) ;
}
F_37 ( & V_10 -> V_77 ) ;
return V_73 ;
}
static void F_57 ( struct V_9 * V_10 ,
struct V_16 * V_2 )
{
F_24 ( V_31 ) ;
while ( ! F_58 ( V_2 ) ) {
F_29 ( & V_10 -> V_77 , & V_31 , V_78 ) ;
F_21 ( & V_10 -> V_24 -> V_25 ) ;
F_59 () ;
F_33 ( & V_10 -> V_77 , & V_31 ) ;
F_20 ( & V_10 -> V_24 -> V_25 ) ;
}
}
static void F_60 ( struct V_9 * V_10 ,
struct V_16 * V_2 )
{
F_20 ( & V_10 -> V_24 -> V_25 ) ;
F_57 ( V_10 , V_2 ) ;
F_21 ( & V_10 -> V_24 -> V_25 ) ;
}
static int F_61 ( struct V_79 * V_80 , void * V_81 , T_6 V_60 , int V_65 )
{
struct V_82 V_83 = {
. V_84 = V_81 ,
. V_85 = V_60 ,
} ;
struct V_86 V_87 = {
. V_88 = ( V_65 ? V_65 : V_89 | V_90 )
} ;
return F_62 ( V_80 , & V_87 , & V_83 , 1 , V_60 , V_87 . V_88 ) ;
}
static int F_63 ( struct V_91 * V_33 , void * V_81 , T_6 V_60 )
{
int V_92 ;
V_92 = F_61 ( V_33 -> V_93 . V_79 , V_81 , V_60 , 0 ) ;
if ( V_92 < 0 ) {
if ( V_92 == - V_94 )
F_64 ( V_33 , L_6 ) ;
else if ( V_92 != - V_95 )
F_41 ( V_33 , L_7 , V_92 ) ;
} else if ( V_92 == 0 ) {
if ( F_65 ( V_96 , & V_33 -> V_65 ) ) {
long V_23 ;
F_25 () ;
V_23 = F_26 ( V_33 -> V_29 ) -> V_97 * V_39 / 10 ;
F_27 () ;
V_23 = F_66 ( V_33 -> V_98 , V_33 -> V_99 < V_100 , V_23 ) ;
if ( V_23 )
goto V_101;
}
F_64 ( V_33 , L_8 ) ;
}
if ( V_92 != V_60 )
F_67 ( V_33 , F_68 ( V_102 , V_103 ) , V_104 ) ;
V_101:
return V_92 ;
}
static int F_69 ( struct V_91 * V_33 , void * V_81 , T_6 V_60 )
{
int V_73 ;
V_73 = F_63 ( V_33 , V_81 , V_60 ) ;
if ( V_73 != V_60 ) {
if ( V_73 >= 0 )
V_73 = - V_105 ;
} else
V_73 = 0 ;
return V_73 ;
}
static int F_70 ( struct V_91 * V_33 , void * V_81 , T_6 V_60 )
{
int V_73 ;
V_73 = F_69 ( V_33 , V_81 , V_60 ) ;
if ( V_73 && ! F_30 ( V_38 ) )
F_31 ( V_33 , L_9 , ( int ) V_60 ) ;
return V_73 ;
}
static void F_71 ( struct V_79 * V_80 , unsigned int V_106 ,
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
static struct V_79 * F_72 ( struct V_91 * V_33 )
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
V_119 = F_73 ( int , V_33 -> V_119 , sizeof( V_116 ) ) ;
memcpy ( & V_116 , & V_33 -> V_124 , V_119 ) ;
if ( ( (struct V_125 * ) & V_33 -> V_124 ) -> V_126 == V_127 )
V_116 . V_128 = 0 ;
else
( (struct V_129 * ) & V_116 ) -> V_130 = 0 ;
V_118 = F_73 ( int , V_33 -> V_118 , sizeof( V_116 ) ) ;
memcpy ( & V_117 , & V_33 -> V_131 , V_118 ) ;
V_114 = L_10 ;
V_73 = F_74 ( & V_132 , ( (struct V_125 * ) & V_116 ) -> V_126 ,
V_133 , V_134 , & V_80 ) ;
if ( V_73 < 0 ) {
V_80 = NULL ;
goto V_101;
}
V_80 -> V_108 -> V_135 =
V_80 -> V_108 -> V_136 = V_122 * V_39 ;
F_71 ( V_80 , V_120 , V_121 ) ;
V_114 = L_11 ;
V_73 = V_80 -> V_137 -> V_138 ( V_80 , (struct V_125 * ) & V_116 , V_119 ) ;
if ( V_73 < 0 )
goto V_101;
V_123 = 0 ;
V_114 = L_12 ;
V_73 = V_80 -> V_137 -> V_139 ( V_80 , (struct V_125 * ) & V_117 , V_118 , 0 ) ;
V_101:
if ( V_73 < 0 ) {
if ( V_80 ) {
F_75 ( V_80 ) ;
V_80 = NULL ;
}
switch ( - V_73 ) {
case V_140 : case V_141 : case V_142 :
case V_143 : case V_95 :
case V_144 : case V_145 :
case V_146 : case V_147 :
V_123 = 0 ;
break;
default:
F_41 ( V_33 , L_13 , V_114 , V_73 ) ;
}
if ( V_123 )
F_67 ( V_33 , F_68 ( V_102 , V_148 ) , V_104 ) ;
}
return V_80 ;
}
static void F_76 ( struct V_80 * V_108 )
{
struct V_149 * V_150 = V_108 -> V_151 ;
void (* F_77)( struct V_80 * V_108 );
F_77 = V_150 -> V_152 ;
if ( V_108 -> V_153 == V_154 )
F_78 ( & V_150 -> V_155 ) ;
F_77 ( V_108 ) ;
}
static int F_79 ( struct V_91 * V_33 , struct V_149 * V_150 )
{
int V_73 , V_120 , V_121 , V_119 ;
struct V_115 V_124 ;
struct V_79 * V_156 ;
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
V_119 = F_73 ( int , V_33 -> V_119 , sizeof( struct V_115 ) ) ;
memcpy ( & V_124 , & V_33 -> V_124 , V_119 ) ;
V_114 = L_10 ;
V_73 = F_74 ( & V_132 , ( (struct V_125 * ) & V_124 ) -> V_126 ,
V_133 , V_134 , & V_156 ) ;
if ( V_73 ) {
V_156 = NULL ;
goto V_101;
}
V_156 -> V_108 -> V_157 = V_158 ;
F_71 ( V_156 , V_120 , V_121 ) ;
V_114 = L_14 ;
V_73 = V_156 -> V_137 -> V_138 ( V_156 , (struct V_125 * ) & V_124 , V_119 ) ;
if ( V_73 < 0 )
goto V_101;
V_150 -> V_156 = V_156 ;
F_80 ( & V_156 -> V_108 -> V_159 ) ;
V_150 -> V_152 = V_156 -> V_108 -> V_160 ;
V_156 -> V_108 -> V_160 = F_76 ;
V_156 -> V_108 -> V_151 = V_150 ;
F_81 ( & V_156 -> V_108 -> V_159 ) ;
V_114 = L_15 ;
V_73 = V_156 -> V_137 -> V_161 ( V_156 , 5 ) ;
if ( V_73 < 0 )
goto V_101;
return 0 ;
V_101:
if ( V_156 )
F_75 ( V_156 ) ;
if ( V_73 < 0 ) {
if ( V_73 != - V_141 && V_73 != - V_143 && V_73 != - V_95 ) {
F_41 ( V_33 , L_13 , V_114 , V_73 ) ;
F_67 ( V_33 , F_68 ( V_102 , V_148 ) , V_104 ) ;
}
}
return - V_105 ;
}
static void F_82 ( struct V_80 * V_108 , struct V_149 * V_150 )
{
F_80 ( & V_108 -> V_159 ) ;
V_108 -> V_160 = V_150 -> V_152 ;
V_108 -> V_151 = NULL ;
F_81 ( & V_108 -> V_159 ) ;
}
static struct V_79 * F_83 ( struct V_91 * V_33 , struct V_149 * V_150 )
{
int V_162 , V_122 , V_73 = 0 ;
struct V_79 * V_163 = NULL ;
struct V_29 * V_30 ;
F_25 () ;
V_30 = F_26 ( V_33 -> V_29 ) ;
if ( ! V_30 ) {
F_27 () ;
return NULL ;
}
V_122 = V_30 -> V_122 ;
F_27 () ;
V_162 = V_122 * V_39 ;
V_162 += ( F_84 () & 1 ) ? V_162 / 7 : - V_162 / 7 ;
V_73 = F_85 ( & V_150 -> V_155 , V_162 ) ;
if ( V_73 <= 0 )
return NULL ;
V_73 = F_86 ( V_150 -> V_156 , & V_163 , 0 ) ;
if ( V_73 < 0 ) {
if ( V_73 != - V_141 && V_73 != - V_143 && V_73 != - V_95 ) {
F_41 ( V_33 , L_16 , V_73 ) ;
F_67 ( V_33 , F_68 ( V_102 , V_148 ) , V_104 ) ;
}
}
if ( V_163 )
F_82 ( V_163 -> V_108 , V_150 ) ;
return V_163 ;
}
static int F_87 ( struct V_91 * V_33 , struct V_164 * V_80 ,
enum V_165 V_166 )
{
if ( ! F_88 ( V_33 , V_80 ) )
return - V_105 ;
return F_89 ( V_33 , V_80 , V_166 , 0 , NULL , 0 ) ;
}
static int F_90 ( struct V_91 * V_33 , struct V_79 * V_80 )
{
unsigned int V_167 = F_91 ( V_33 ) ;
struct V_168 V_169 ;
struct V_29 * V_30 ;
int V_73 ;
F_25 () ;
V_30 = F_26 ( V_33 -> V_29 ) ;
if ( ! V_30 ) {
F_27 () ;
return - V_105 ;
}
V_80 -> V_108 -> V_135 = V_30 -> V_97 * 4 * V_39 / 10 ;
F_27 () ;
V_73 = F_61 ( V_80 , V_33 -> V_93 . V_170 , V_167 , 0 ) ;
if ( V_73 != V_167 ) {
if ( V_73 >= 0 )
V_73 = - V_105 ;
return V_73 ;
}
V_73 = F_92 ( V_33 , V_33 -> V_93 . V_170 , & V_169 ) ;
if ( V_73 )
return V_73 ;
return V_169 . V_166 ;
}
static bool F_93 ( struct V_79 * * V_80 )
{
int V_171 ;
char V_172 [ 4 ] ;
if ( ! * V_80 )
return false ;
V_171 = F_61 ( * V_80 , V_172 , 4 , V_173 | V_174 ) ;
if ( V_171 > 0 || V_171 == - V_141 ) {
return true ;
} else {
F_75 ( * V_80 ) ;
* V_80 = NULL ;
return false ;
}
}
static bool F_94 ( struct V_91 * V_33 ,
struct V_79 * * V_175 ,
struct V_79 * * V_176 )
{
struct V_29 * V_30 ;
int V_177 ;
bool V_178 ;
if ( ! * V_175 || ! * V_176 )
return false ;
F_25 () ;
V_30 = F_26 ( V_33 -> V_29 ) ;
V_177 = ( V_30 -> V_179 ? : V_30 -> V_97 ) * V_39 / 10 ;
F_27 () ;
F_95 ( V_177 ) ;
V_178 = F_93 ( V_175 ) ;
V_178 = F_93 ( V_176 ) && V_178 ;
return V_178 ;
}
int F_96 ( struct V_26 * V_27 )
{
struct V_9 * V_10 = V_27 -> V_10 ;
int V_73 ;
F_97 ( & V_10 -> V_180 , 0 ) ;
V_10 -> V_181 = 0 ;
V_10 -> V_182 = V_27 -> V_33 -> V_183 < 100 ?
& V_27 -> V_33 -> V_184 :
& V_10 -> V_185 ;
V_73 = F_98 ( V_27 ) ;
if ( ! V_73 )
V_73 = F_99 ( V_27 , 0 , 0 ) ;
if ( ! V_73 )
V_73 = F_100 ( V_27 ) ;
if ( ! V_73 )
V_73 = F_101 ( V_27 ) ;
F_102 ( V_186 , & V_10 -> V_65 ) ;
F_102 ( V_187 , & V_10 -> V_65 ) ;
F_97 ( & V_10 -> V_188 , 0 ) ;
F_103 ( & V_10 -> V_189 , V_62 + V_39 ) ;
return V_73 ;
}
static int F_104 ( struct V_91 * V_33 )
{
struct V_164 V_80 , V_190 ;
struct V_26 * V_27 ;
struct V_29 * V_30 ;
int V_191 , V_177 , V_192 ;
bool V_193 , V_178 ;
enum V_194 V_92 ;
struct V_149 V_150 = {
. V_33 = V_33 ,
. V_155 = F_105 ( V_150 . V_155 ) ,
} ;
F_102 ( V_96 , & V_33 -> V_65 ) ;
if ( F_67 ( V_33 , F_68 ( V_102 , V_195 ) , V_196 ) < V_197 )
return - 2 ;
F_106 ( & V_80 . V_198 ) ;
V_80 . V_199 = V_33 -> V_93 . V_199 ;
V_80 . V_170 = V_33 -> V_93 . V_170 ;
V_80 . V_79 = NULL ;
F_106 ( & V_190 . V_198 ) ;
V_190 . V_199 = V_33 -> V_200 . V_199 ;
V_190 . V_170 = V_33 -> V_200 . V_170 ;
V_190 . V_79 = NULL ;
V_33 -> V_183 = 80 ;
if ( F_79 ( V_33 , & V_150 ) )
return 0 ;
do {
struct V_79 * V_201 ;
V_201 = F_72 ( V_33 ) ;
if ( V_201 ) {
if ( ! V_80 . V_79 ) {
V_80 . V_79 = V_201 ;
F_87 ( V_33 , & V_80 , V_202 ) ;
} else if ( ! V_190 . V_79 ) {
F_102 ( V_203 , & V_33 -> V_65 ) ;
V_190 . V_79 = V_201 ;
F_87 ( V_33 , & V_190 , V_204 ) ;
} else {
F_41 ( V_33 , L_17 ) ;
goto V_205;
}
}
if ( F_94 ( V_33 , & V_80 . V_79 , & V_190 . V_79 ) )
break;
V_28:
V_201 = F_83 ( V_33 , & V_150 ) ;
if ( V_201 ) {
int V_206 = F_90 ( V_33 , V_201 ) ;
F_93 ( & V_80 . V_79 ) ;
F_93 ( & V_190 . V_79 ) ;
switch ( V_206 ) {
case V_202 :
if ( V_80 . V_79 ) {
F_31 ( V_33 , L_18 ) ;
F_75 ( V_80 . V_79 ) ;
V_80 . V_79 = V_201 ;
goto V_207;
}
V_80 . V_79 = V_201 ;
break;
case V_204 :
F_107 ( V_203 , & V_33 -> V_65 ) ;
if ( V_190 . V_79 ) {
F_31 ( V_33 , L_19 ) ;
F_75 ( V_190 . V_79 ) ;
V_190 . V_79 = V_201 ;
goto V_207;
}
V_190 . V_79 = V_201 ;
break;
default:
F_31 ( V_33 , L_20 ) ;
F_75 ( V_201 ) ;
V_207:
if ( F_84 () & 1 )
goto V_28;
}
}
if ( V_33 -> V_99 <= V_148 )
goto V_205;
if ( F_30 ( V_38 ) ) {
F_108 ( V_38 ) ;
F_109 () ;
if ( F_110 ( & V_33 -> V_208 ) == V_209 )
goto V_205;
}
V_178 = F_94 ( V_33 , & V_80 . V_79 , & V_190 . V_79 ) ;
} while ( ! V_178 );
if ( V_150 . V_156 )
F_75 ( V_150 . V_156 ) ;
V_80 . V_79 -> V_108 -> V_157 = V_158 ;
V_190 . V_79 -> V_108 -> V_157 = V_158 ;
V_80 . V_79 -> V_108 -> V_210 = V_211 ;
V_190 . V_79 -> V_108 -> V_210 = V_211 ;
V_80 . V_79 -> V_108 -> V_212 = V_213 ;
V_190 . V_79 -> V_108 -> V_212 = V_214 ;
F_25 () ;
V_30 = F_26 ( V_33 -> V_29 ) ;
V_80 . V_79 -> V_108 -> V_136 =
V_80 . V_79 -> V_108 -> V_135 = V_30 -> V_97 * 4 * V_39 / 10 ;
V_190 . V_79 -> V_108 -> V_135 = V_30 -> V_215 * V_39 ;
V_177 = V_30 -> V_177 * V_39 / 10 ;
V_193 = V_30 -> V_193 ;
F_27 () ;
V_190 . V_79 -> V_108 -> V_136 = V_177 ;
F_111 ( V_80 . V_79 ) ;
F_111 ( V_190 . V_79 ) ;
V_33 -> V_93 . V_79 = V_80 . V_79 ;
V_33 -> V_200 . V_79 = V_190 . V_79 ;
V_33 -> V_216 = V_62 ;
V_192 = F_112 ( V_33 ) ;
if ( V_192 <= 0 )
return V_192 ;
if ( V_33 -> V_217 ) {
switch ( F_113 ( V_33 ) ) {
case - 1 :
F_41 ( V_33 , L_21 ) ;
return - 1 ;
case 0 :
F_41 ( V_33 , L_22 ) ;
return 0 ;
}
}
V_33 -> V_93 . V_79 -> V_108 -> V_136 = V_177 ;
V_33 -> V_93 . V_79 -> V_108 -> V_135 = V_218 ;
if ( F_114 ( V_33 ) == - V_219 )
return - 1 ;
F_115 (&connection->peer_devices, peer_device, vnr)
F_116 ( V_27 -> V_10 -> V_182 ) ;
F_107 ( V_220 , & V_33 -> V_65 ) ;
F_115 (&connection->peer_devices, peer_device, vnr)
F_117 ( V_27 -> V_10 -> V_182 ) ;
F_25 () ;
F_115 (&connection->peer_devices, peer_device, vnr) {
struct V_9 * V_10 = V_27 -> V_10 ;
F_118 ( & V_10 -> V_221 ) ;
F_27 () ;
if ( V_193 )
F_107 ( V_222 , & V_10 -> V_65 ) ;
else
F_102 ( V_222 , & V_10 -> V_65 ) ;
F_96 ( V_27 ) ;
F_119 ( & V_10 -> V_221 , V_223 ) ;
F_25 () ;
}
F_27 () ;
V_92 = F_67 ( V_33 , F_68 ( V_102 , V_100 ) , V_196 ) ;
if ( V_92 < V_197 || V_33 -> V_99 != V_100 ) {
F_102 ( V_220 , & V_33 -> V_65 ) ;
return 0 ;
}
F_120 ( & V_33 -> V_224 ) ;
F_116 ( & V_33 -> V_24 -> V_225 ) ;
V_33 -> V_29 -> V_193 = 0 ;
F_117 ( & V_33 -> V_24 -> V_225 ) ;
return V_192 ;
V_205:
if ( V_150 . V_156 )
F_75 ( V_150 . V_156 ) ;
if ( V_80 . V_79 )
F_75 ( V_80 . V_79 ) ;
if ( V_190 . V_79 )
F_75 ( V_190 . V_79 ) ;
return - 1 ;
}
static int F_92 ( struct V_91 * V_33 , void * V_226 , struct V_168 * V_169 )
{
unsigned int V_167 = F_91 ( V_33 ) ;
if ( V_167 == sizeof( struct V_227 ) &&
* ( V_228 * ) V_226 == F_121 ( V_229 ) ) {
struct V_227 * V_192 = V_226 ;
if ( V_192 -> V_230 != 0 ) {
F_41 ( V_33 , L_23 ) ;
return - V_231 ;
}
V_169 -> V_191 = F_122 ( V_192 -> V_232 ) ;
V_169 -> V_166 = F_122 ( V_192 -> V_233 ) ;
V_169 -> V_60 = F_123 ( V_192 -> V_234 ) ;
} else if ( V_167 == sizeof( struct V_235 ) &&
* ( V_236 * ) V_226 == F_124 ( V_237 ) ) {
struct V_235 * V_192 = V_226 ;
V_169 -> V_166 = F_122 ( V_192 -> V_233 ) ;
V_169 -> V_60 = F_123 ( V_192 -> V_234 ) ;
V_169 -> V_191 = 0 ;
} else if ( V_167 == sizeof( struct V_238 ) &&
* ( V_228 * ) V_226 == F_121 ( V_239 ) ) {
struct V_238 * V_192 = V_226 ;
V_169 -> V_166 = F_122 ( V_192 -> V_233 ) ;
V_169 -> V_60 = F_122 ( V_192 -> V_234 ) ;
V_169 -> V_191 = 0 ;
} else {
F_41 ( V_33 , L_24 ,
F_123 ( * ( V_228 * ) V_226 ) ,
V_33 -> V_183 ) ;
return - V_231 ;
}
V_169 -> V_93 = V_226 + V_167 ;
return 0 ;
}
static int F_125 ( struct V_91 * V_33 , struct V_168 * V_169 )
{
void * V_240 = V_33 -> V_93 . V_170 ;
int V_73 ;
V_73 = F_70 ( V_33 , V_240 , F_91 ( V_33 ) ) ;
if ( V_73 )
return V_73 ;
V_73 = F_92 ( V_33 , V_240 , V_169 ) ;
V_33 -> V_216 = V_62 ;
return V_73 ;
}
static void F_126 ( struct V_91 * V_33 )
{
int V_92 ;
struct V_26 * V_27 ;
int V_191 ;
if ( V_33 -> V_24 -> V_241 >= V_242 ) {
F_25 () ;
F_115 (&connection->peer_devices, peer_device, vnr) {
struct V_9 * V_10 = V_27 -> V_10 ;
if ( ! F_127 ( V_10 ) )
continue;
F_118 ( & V_10 -> V_221 ) ;
F_27 () ;
V_10 -> V_243 = V_62 ;
F_107 ( V_244 , & V_10 -> V_65 ) ;
V_92 = F_128 ( V_10 -> V_245 -> V_246 ,
V_211 , NULL ) ;
F_102 ( V_244 , & V_10 -> V_65 ) ;
if ( V_92 ) {
F_64 ( V_10 , L_25 , V_92 ) ;
F_129 ( V_33 -> V_24 , NULL , V_247 ) ;
}
F_130 ( V_10 ) ;
F_119 ( & V_10 -> V_221 , V_223 ) ;
F_25 () ;
if ( V_92 )
break;
}
F_27 () ;
}
}
static enum V_248 F_131 ( struct V_91 * V_33 ,
struct V_249 * V_250 ,
enum V_251 V_252 )
{
int V_253 ;
struct V_249 * V_254 ;
enum V_248 V_92 = V_255 ;
F_11 ( & V_33 -> V_256 ) ;
do {
V_254 = NULL ;
V_253 = F_28 ( & V_250 -> V_253 ) ;
switch ( V_252 & ~ V_257 ) {
case V_258 :
F_132 ( & V_250 -> V_259 ) ;
break;
case V_260 :
F_107 ( V_261 , & V_250 -> V_65 ) ;
break;
case V_262 :
break;
}
if ( V_253 != 0 &&
F_28 ( & V_250 -> V_259 ) == 0 &&
( F_65 ( V_261 , & V_250 -> V_65 ) || V_252 & V_257 ) ) {
if ( ! ( V_252 & V_257 ) ) {
F_12 ( & V_33 -> V_256 ) ;
F_133 ( V_250 -> V_33 , V_250 -> V_263 , V_253 ) ;
F_11 ( & V_33 -> V_256 ) ;
}
#if 0
if (test_bit(DE_HAVE_BARRIER_NUMBER, &epoch->flags))
dec_unacked(epoch->connection);
#endif
if ( V_33 -> V_264 != V_250 ) {
V_254 = F_134 ( V_250 -> V_21 . V_265 , struct V_249 , V_21 ) ;
F_135 ( & V_250 -> V_21 ) ;
V_252 = V_262 | ( V_252 & V_257 ) ;
V_33 -> V_266 -- ;
F_48 ( V_250 ) ;
if ( V_92 == V_255 )
V_92 = V_267 ;
} else {
V_250 -> V_65 = 0 ;
F_97 ( & V_250 -> V_253 , 0 ) ;
if ( V_92 == V_255 )
V_92 = V_268 ;
}
}
if ( ! V_254 )
break;
V_250 = V_254 ;
} while ( 1 );
F_12 ( & V_33 -> V_256 ) ;
return V_92 ;
}
static enum V_269
F_136 ( struct V_270 * V_271 , enum V_269 V_272 )
{
struct V_273 * V_274 ;
V_274 = F_26 ( V_271 -> V_273 ) ;
if ( V_272 == V_242 && ! V_274 -> V_275 )
V_272 = V_247 ;
if ( V_272 == V_247 && ! V_274 -> V_276 )
V_272 = V_277 ;
return V_272 ;
}
void F_129 ( struct V_278 * V_24 , struct V_270 * V_271 ,
enum V_269 V_272 )
{
struct V_9 * V_10 ;
enum V_269 V_279 ;
int V_191 ;
static char * V_280 [] = {
[ V_277 ] = L_26 ,
[ V_247 ] = L_27 ,
[ V_242 ] = L_28 ,
} ;
V_279 = V_24 -> V_241 ;
if ( V_272 != V_242 )
V_272 = F_137 ( V_279 , V_272 ) ;
F_25 () ;
F_115 (&resource->devices, device, vnr) {
if ( F_127 ( V_10 ) ) {
V_272 = F_136 ( V_10 -> V_245 , V_272 ) ;
if ( V_10 -> V_245 == V_271 )
V_271 = NULL ;
F_130 ( V_10 ) ;
}
}
if ( V_271 )
V_272 = F_136 ( V_271 , V_272 ) ;
F_27 () ;
V_24 -> V_241 = V_272 ;
if ( V_279 != V_24 -> V_241 || V_272 == V_242 )
F_64 ( V_24 , L_29 , V_280 [ V_24 -> V_241 ] ) ;
}
int F_138 ( struct V_9 * V_10 ,
struct V_18 * V_19 ,
const unsigned V_281 , const int V_282 )
{
struct V_283 * V_284 = NULL ;
struct V_283 * V_283 ;
struct V_1 * V_1 = V_19 -> V_63 ;
T_3 V_48 = V_19 -> V_6 . V_48 ;
unsigned V_49 = V_19 -> V_6 . V_60 ;
unsigned V_285 = 0 ;
unsigned V_52 = ( V_49 + V_45 - 1 ) >> V_53 ;
int V_73 = - V_286 ;
if ( V_19 -> V_65 & V_287 ) {
F_139 ( F_140 ( V_10 ) -> V_33 ) ;
V_19 -> V_61 = V_62 ;
V_19 -> V_65 |= V_288 ;
F_20 ( & V_10 -> V_24 -> V_25 ) ;
F_141 ( & V_19 -> V_20 . V_21 , & V_10 -> V_289 ) ;
F_21 ( & V_10 -> V_24 -> V_25 ) ;
if ( F_142 ( V_10 -> V_245 -> V_246 ,
V_48 , V_49 >> 9 , V_211 , false ) )
V_19 -> V_65 |= V_290 ;
F_143 ( V_19 ) ;
return 0 ;
}
if ( V_19 -> V_65 & V_291 )
V_52 = 1 ;
V_292:
V_283 = F_144 ( V_211 , V_52 ) ;
if ( ! V_283 ) {
F_41 ( V_10 , L_30 , V_52 ) ;
goto V_59;
}
V_283 -> V_293 . V_294 = V_48 ;
V_283 -> V_295 = V_10 -> V_245 -> V_246 ;
V_283 -> V_296 = V_281 ;
V_283 -> V_297 = V_19 ;
V_283 -> V_298 = V_299 ;
V_283 -> V_300 = V_284 ;
V_284 = V_283 ;
++ V_285 ;
if ( V_281 & V_301 ) {
V_283 -> V_293 . V_302 = V_49 ;
goto V_303;
}
F_145 (page) {
unsigned V_5 = F_73 ( unsigned , V_49 , V_45 ) ;
if ( ! F_146 ( V_283 , V_1 , V_5 , 0 ) ) {
if ( V_283 -> V_304 == 0 ) {
F_41 ( V_10 ,
L_31
L_32 ,
V_5 , ( V_305 ) V_283 -> V_293 . V_294 ) ;
V_73 = - V_306 ;
goto V_59;
}
goto V_292;
}
V_49 -= V_5 ;
V_48 += V_5 >> 9 ;
-- V_52 ;
}
F_49 ( V_10 , V_49 == 0 ) ;
V_303:
F_49 ( V_10 , V_1 == NULL ) ;
F_97 ( & V_19 -> V_68 , V_285 ) ;
V_19 -> V_61 = V_62 ;
V_19 -> V_65 |= V_288 ;
do {
V_283 = V_284 ;
V_284 = V_284 -> V_300 ;
V_283 -> V_300 = NULL ;
F_147 ( V_10 , V_282 , V_283 ) ;
} while ( V_284 );
return 0 ;
V_59:
while ( V_284 ) {
V_283 = V_284 ;
V_284 = V_284 -> V_300 ;
F_148 ( V_283 ) ;
}
return V_73 ;
}
static void F_149 ( struct V_9 * V_10 ,
struct V_18 * V_19 )
{
struct V_307 * V_6 = & V_19 -> V_6 ;
F_150 ( & V_10 -> V_308 , V_6 ) ;
F_44 ( V_6 ) ;
if ( V_6 -> V_309 )
F_37 ( & V_10 -> V_310 ) ;
}
static void F_139 ( struct V_91 * V_33 )
{
struct V_26 * V_27 ;
int V_191 ;
F_25 () ;
F_115 (&connection->peer_devices, peer_device, vnr) {
struct V_9 * V_10 = V_27 -> V_10 ;
F_118 ( & V_10 -> V_221 ) ;
F_27 () ;
F_60 ( V_10 , & V_10 -> V_289 ) ;
F_119 ( & V_10 -> V_221 , V_223 ) ;
F_25 () ;
}
F_27 () ;
}
static struct V_26 *
F_151 ( struct V_91 * V_33 , int V_311 )
{
return F_152 ( & V_33 -> V_312 , V_311 ) ;
}
static int F_153 ( struct V_91 * V_33 , struct V_168 * V_169 )
{
int V_92 ;
struct V_313 * V_314 = V_169 -> V_93 ;
struct V_249 * V_250 ;
V_33 -> V_264 -> V_263 = V_314 -> V_315 ;
V_33 -> V_264 -> V_33 = V_33 ;
V_92 = F_131 ( V_33 , V_33 -> V_264 , V_260 ) ;
switch ( V_33 -> V_24 -> V_241 ) {
case V_277 :
if ( V_92 == V_268 )
return 0 ;
V_250 = F_154 ( sizeof( struct V_249 ) , V_211 ) ;
if ( V_250 )
break;
else
F_31 ( V_33 , L_33 ) ;
case V_242 :
case V_247 :
F_139 ( V_33 ) ;
F_126 ( V_33 ) ;
if ( F_28 ( & V_33 -> V_264 -> V_253 ) ) {
V_250 = F_154 ( sizeof( struct V_249 ) , V_211 ) ;
if ( V_250 )
break;
}
return 0 ;
default:
F_41 ( V_33 , L_34 ,
V_33 -> V_24 -> V_241 ) ;
return - V_105 ;
}
V_250 -> V_65 = 0 ;
F_97 ( & V_250 -> V_253 , 0 ) ;
F_97 ( & V_250 -> V_259 , 0 ) ;
F_11 ( & V_33 -> V_256 ) ;
if ( F_28 ( & V_33 -> V_264 -> V_253 ) ) {
F_155 ( & V_250 -> V_21 , & V_33 -> V_264 -> V_21 ) ;
V_33 -> V_264 = V_250 ;
V_33 -> V_266 ++ ;
} else {
F_48 ( V_250 ) ;
}
F_12 ( & V_33 -> V_256 ) ;
return 0 ;
}
static struct V_18 *
F_156 ( struct V_26 * V_27 , T_2 V_47 , T_3 V_48 ,
struct V_168 * V_169 ) __must_hold( T_5 )
{
struct V_9 * V_10 = V_27 -> V_10 ;
const T_3 V_316 = F_157 ( V_10 -> V_317 ) ;
struct V_18 * V_19 ;
struct V_1 * V_1 ;
int V_318 , V_73 ;
unsigned int V_49 = V_169 -> V_60 , V_319 ;
void * V_320 = V_27 -> V_33 -> V_321 ;
void * V_322 = V_27 -> V_33 -> V_323 ;
unsigned long * V_93 ;
struct V_324 * V_325 = ( V_169 -> V_166 == V_326 ) ? V_169 -> V_93 : NULL ;
V_318 = 0 ;
if ( ! V_325 && V_27 -> V_33 -> V_327 ) {
V_318 = F_158 ( V_27 -> V_33 -> V_327 ) ;
V_73 = F_70 ( V_27 -> V_33 , V_320 , V_318 ) ;
if ( V_73 )
return NULL ;
V_49 -= V_318 ;
}
if ( V_325 ) {
F_49 ( V_27 , V_49 == 0 ) ;
V_49 = F_123 ( V_325 -> V_60 ) ;
}
if ( ! F_51 ( F_159 ( V_49 , 512 ) ) )
return NULL ;
if ( ! V_325 && ! F_51 ( V_49 <= V_44 ) )
return NULL ;
if ( V_48 + ( V_49 >> 9 ) > V_316 ) {
F_41 ( V_10 , L_35
L_36 ,
( unsigned long long ) V_316 ,
( unsigned long long ) V_48 , V_49 ) ;
return NULL ;
}
V_19 = F_38 ( V_27 , V_47 , V_48 , V_49 , V_325 == NULL , V_211 ) ;
if ( ! V_19 )
return NULL ;
V_19 -> V_65 |= V_328 ;
if ( V_325 )
return V_19 ;
V_319 = V_49 ;
V_1 = V_19 -> V_63 ;
F_145 (page) {
unsigned V_5 = F_73 ( int , V_319 , V_45 ) ;
V_93 = F_160 ( V_1 ) ;
V_73 = F_70 ( V_27 -> V_33 , V_93 , V_5 ) ;
if ( F_39 ( V_10 , V_329 ) ) {
F_41 ( V_10 , L_37 ) ;
V_93 [ 0 ] = V_93 [ 0 ] ^ ( unsigned long ) - 1 ;
}
F_161 ( V_1 ) ;
if ( V_73 ) {
F_56 ( V_10 , V_19 ) ;
return NULL ;
}
V_319 -= V_5 ;
}
if ( V_318 ) {
F_162 ( V_27 -> V_33 -> V_327 , V_19 , V_322 ) ;
if ( memcmp ( V_320 , V_322 , V_318 ) ) {
F_41 ( V_10 , L_38 ,
( unsigned long long ) V_48 , V_49 ) ;
F_56 ( V_10 , V_19 ) ;
return NULL ;
}
}
V_10 -> V_330 += V_49 >> 9 ;
return V_19 ;
}
static int F_163 ( struct V_26 * V_27 , int V_49 )
{
struct V_1 * V_1 ;
int V_73 = 0 ;
void * V_93 ;
if ( ! V_49 )
return 0 ;
V_1 = F_23 ( V_27 , 1 , 1 ) ;
V_93 = F_160 ( V_1 ) ;
while ( V_49 ) {
unsigned int V_5 = F_73 ( int , V_49 , V_45 ) ;
V_73 = F_70 ( V_27 -> V_33 , V_93 , V_5 ) ;
if ( V_73 )
break;
V_49 -= V_5 ;
}
F_161 ( V_1 ) ;
F_35 ( V_27 -> V_10 , V_1 , 0 ) ;
return V_73 ;
}
static int F_164 ( struct V_26 * V_27 , struct V_331 * V_332 ,
T_3 V_48 , int V_49 )
{
struct V_333 V_334 ;
struct V_335 V_336 ;
struct V_283 * V_283 ;
int V_318 , V_73 , F_51 ;
void * V_320 = V_27 -> V_33 -> V_321 ;
void * V_322 = V_27 -> V_33 -> V_323 ;
V_318 = 0 ;
if ( V_27 -> V_33 -> V_327 ) {
V_318 = F_158 ( V_27 -> V_33 -> V_327 ) ;
V_73 = F_70 ( V_27 -> V_33 , V_320 , V_318 ) ;
if ( V_73 )
return V_73 ;
V_49 -= V_318 ;
}
V_27 -> V_10 -> V_330 += V_49 >> 9 ;
V_283 = V_332 -> V_337 ;
F_49 ( V_27 -> V_10 , V_48 == V_283 -> V_293 . V_294 ) ;
F_165 (bvec, bio, iter) {
void * V_338 = F_160 ( V_334 . V_339 ) + V_334 . V_340 ;
F_51 = F_73 ( int , V_49 , V_334 . V_341 ) ;
V_73 = F_70 ( V_27 -> V_33 , V_338 , F_51 ) ;
F_161 ( V_334 . V_339 ) ;
if ( V_73 )
return V_73 ;
V_49 -= F_51 ;
}
if ( V_318 ) {
F_166 ( V_27 -> V_33 -> V_327 , V_283 , V_322 ) ;
if ( memcmp ( V_320 , V_322 , V_318 ) ) {
F_41 ( V_27 , L_39 ) ;
return - V_231 ;
}
}
F_49 ( V_27 -> V_10 , V_49 == 0 ) ;
return 0 ;
}
static int F_167 ( struct V_342 * V_20 , int V_343 )
{
struct V_18 * V_19 =
F_168 ( V_20 , struct V_18 , V_20 ) ;
struct V_26 * V_27 = V_19 -> V_27 ;
struct V_9 * V_10 = V_27 -> V_10 ;
T_3 V_48 = V_19 -> V_6 . V_48 ;
int V_73 ;
F_49 ( V_10 , F_50 ( & V_19 -> V_6 ) ) ;
if ( F_169 ( ( V_19 -> V_65 & V_290 ) == 0 ) ) {
F_170 ( V_10 , V_48 , V_19 -> V_6 . V_60 ) ;
V_73 = F_171 ( V_27 , V_344 , V_19 ) ;
} else {
F_172 ( V_10 , V_48 , V_19 -> V_6 . V_60 ) ;
V_73 = F_171 ( V_27 , V_345 , V_19 ) ;
}
F_173 ( V_10 ) ;
return V_73 ;
}
static int F_174 ( struct V_26 * V_27 , T_3 V_48 ,
struct V_168 * V_169 ) __releases( T_5 )
{
struct V_9 * V_10 = V_27 -> V_10 ;
struct V_18 * V_19 ;
V_19 = F_156 ( V_27 , V_346 , V_48 , V_169 ) ;
if ( ! V_19 )
goto V_59;
F_175 ( V_10 ) ;
F_176 ( V_10 ) ;
V_19 -> V_20 . V_76 = F_167 ;
V_19 -> V_61 = V_62 ;
F_20 ( & V_10 -> V_24 -> V_25 ) ;
F_141 ( & V_19 -> V_20 . V_21 , & V_10 -> V_347 ) ;
F_21 ( & V_10 -> V_24 -> V_25 ) ;
F_34 ( V_169 -> V_60 >> 9 , & V_10 -> V_348 ) ;
if ( F_138 ( V_10 , V_19 , V_349 , V_350 ) == 0 )
return 0 ;
F_41 ( V_10 , L_40 ) ;
F_20 ( & V_10 -> V_24 -> V_25 ) ;
F_135 ( & V_19 -> V_20 . V_21 ) ;
F_21 ( & V_10 -> V_24 -> V_25 ) ;
F_56 ( V_10 , V_19 ) ;
V_59:
F_130 ( V_10 ) ;
return - V_105 ;
}
static struct V_331 *
F_177 ( struct V_9 * V_10 , struct V_351 * V_352 , T_2 V_47 ,
T_3 V_48 , bool V_353 , const char * V_354 )
{
struct V_331 * V_332 ;
V_332 = (struct V_331 * ) ( unsigned long ) V_47 ;
if ( F_178 ( V_352 , V_48 , & V_332 -> V_6 ) && V_332 -> V_6 . T_5 )
return V_332 ;
if ( ! V_353 ) {
F_41 ( V_10 , L_41 , V_354 ,
( unsigned long ) V_47 , ( unsigned long long ) V_48 ) ;
}
return NULL ;
}
static int F_179 ( struct V_91 * V_33 , struct V_168 * V_169 )
{
struct V_26 * V_27 ;
struct V_9 * V_10 ;
struct V_331 * V_332 ;
T_3 V_48 ;
int V_73 ;
struct V_355 * V_314 = V_169 -> V_93 ;
V_27 = F_151 ( V_33 , V_169 -> V_191 ) ;
if ( ! V_27 )
return - V_105 ;
V_10 = V_27 -> V_10 ;
V_48 = F_180 ( V_314 -> V_48 ) ;
F_20 ( & V_10 -> V_24 -> V_25 ) ;
V_332 = F_177 ( V_10 , & V_10 -> V_356 , V_314 -> V_64 , V_48 , false , V_58 ) ;
F_21 ( & V_10 -> V_24 -> V_25 ) ;
if ( F_181 ( ! V_332 ) )
return - V_105 ;
V_73 = F_164 ( V_27 , V_332 , V_48 , V_169 -> V_60 ) ;
if ( ! V_73 )
F_182 ( V_332 , V_357 ) ;
return V_73 ;
}
static int F_183 ( struct V_91 * V_33 , struct V_168 * V_169 )
{
struct V_26 * V_27 ;
struct V_9 * V_10 ;
T_3 V_48 ;
int V_73 ;
struct V_355 * V_314 = V_169 -> V_93 ;
V_27 = F_151 ( V_33 , V_169 -> V_191 ) ;
if ( ! V_27 )
return - V_105 ;
V_10 = V_27 -> V_10 ;
V_48 = F_180 ( V_314 -> V_48 ) ;
F_49 ( V_10 , V_314 -> V_64 == V_346 ) ;
if ( F_127 ( V_10 ) ) {
V_73 = F_174 ( V_27 , V_48 , V_169 ) ;
} else {
if ( F_184 ( & V_358 ) )
F_41 ( V_10 , L_42 ) ;
V_73 = F_163 ( V_27 , V_169 -> V_60 ) ;
F_185 ( V_27 , V_345 , V_314 , V_169 -> V_60 ) ;
}
F_34 ( V_169 -> V_60 >> 9 , & V_10 -> V_359 ) ;
return V_73 ;
}
static void F_186 ( struct V_9 * V_10 ,
T_3 V_48 , int V_60 )
{
struct V_307 * V_6 ;
struct V_331 * V_332 ;
F_187 (i, &device->write_requests, sector, size) {
if ( ! V_6 -> T_5 )
continue;
V_332 = F_168 ( V_6 , struct V_331 , V_6 ) ;
if ( V_332 -> V_360 & V_361 ||
! ( V_332 -> V_360 & V_362 ) )
continue;
F_188 ( V_332 , V_363 , NULL ) ;
}
}
static int F_189 ( struct V_342 * V_20 , int V_364 )
{
struct V_18 * V_19 =
F_168 ( V_20 , struct V_18 , V_20 ) ;
struct V_26 * V_27 = V_19 -> V_27 ;
struct V_9 * V_10 = V_27 -> V_10 ;
T_3 V_48 = V_19 -> V_6 . V_48 ;
int V_73 = 0 , V_365 ;
if ( V_19 -> V_65 & V_366 ) {
if ( F_169 ( ( V_19 -> V_65 & V_290 ) == 0 ) ) {
V_365 = ( V_10 -> V_367 . V_102 >= V_368 &&
V_10 -> V_367 . V_102 <= V_369 &&
V_19 -> V_65 & V_370 ) ?
V_344 : V_371 ;
V_73 = F_171 ( V_27 , V_365 , V_19 ) ;
if ( V_365 == V_344 )
F_170 ( V_10 , V_48 , V_19 -> V_6 . V_60 ) ;
} else {
V_73 = F_171 ( V_27 , V_345 , V_19 ) ;
}
F_173 ( V_10 ) ;
}
if ( V_19 -> V_65 & V_372 ) {
F_20 ( & V_10 -> V_24 -> V_25 ) ;
F_49 ( V_10 , ! F_50 ( & V_19 -> V_6 ) ) ;
F_149 ( V_10 , V_19 ) ;
if ( V_19 -> V_65 & V_373 )
F_186 ( V_10 , V_48 , V_19 -> V_6 . V_60 ) ;
F_21 ( & V_10 -> V_24 -> V_25 ) ;
} else
F_49 ( V_10 , F_50 ( & V_19 -> V_6 ) ) ;
F_131 ( F_140 ( V_10 ) -> V_33 , V_19 -> V_250 , V_258 + ( V_364 ? V_257 : 0 ) ) ;
return V_73 ;
}
static int F_190 ( struct V_342 * V_20 , enum V_165 V_374 )
{
struct V_18 * V_19 =
F_168 ( V_20 , struct V_18 , V_20 ) ;
struct V_26 * V_27 = V_19 -> V_27 ;
int V_73 ;
V_73 = F_171 ( V_27 , V_374 , V_19 ) ;
F_173 ( V_27 -> V_10 ) ;
return V_73 ;
}
static int F_191 ( struct V_342 * V_20 , int V_343 )
{
return F_190 ( V_20 , V_375 ) ;
}
static int F_192 ( struct V_342 * V_20 , int V_343 )
{
struct V_18 * V_19 =
F_168 ( V_20 , struct V_18 , V_20 ) ;
struct V_91 * V_33 = V_19 -> V_27 -> V_33 ;
return F_190 ( V_20 , V_33 -> V_183 >= 100 ?
V_376 : V_375 ) ;
}
static bool F_193 ( T_7 V_42 , T_7 V_377 )
{
return ( V_378 ) V_42 - ( V_378 ) V_377 > 0 ;
}
static T_7 F_194 ( T_7 V_42 , T_7 V_377 )
{
return F_193 ( V_42 , V_377 ) ? V_42 : V_377 ;
}
static void F_195 ( struct V_26 * V_27 , unsigned int V_181 )
{
struct V_9 * V_10 = V_27 -> V_10 ;
unsigned int V_379 ;
if ( F_65 ( V_203 , & V_27 -> V_33 -> V_65 ) ) {
F_11 ( & V_10 -> V_380 ) ;
V_379 = F_194 ( V_10 -> V_181 , V_181 ) ;
V_10 -> V_181 = V_379 ;
F_12 ( & V_10 -> V_380 ) ;
if ( V_181 == V_379 )
F_37 ( & V_10 -> V_381 ) ;
}
}
static inline int F_196 ( T_3 V_382 , int V_383 , T_3 V_384 , int V_385 )
{
return ! ( ( V_382 + ( V_383 >> 9 ) <= V_384 ) || ( V_382 >= V_384 + ( V_385 >> 9 ) ) ) ;
}
static bool F_197 ( struct V_9 * V_10 , struct V_18 * V_19 )
{
struct V_18 * V_386 ;
bool V_92 = 0 ;
F_20 ( & V_10 -> V_24 -> V_25 ) ;
F_198 (rs_req, &device->sync_ee, w.list) {
if ( F_196 ( V_19 -> V_6 . V_48 , V_19 -> V_6 . V_60 ,
V_386 -> V_6 . V_48 , V_386 -> V_6 . V_60 ) ) {
V_92 = 1 ;
break;
}
}
F_21 ( & V_10 -> V_24 -> V_25 ) ;
return V_92 ;
}
static int F_199 ( struct V_26 * V_27 , const T_7 V_181 )
{
struct V_9 * V_10 = V_27 -> V_10 ;
F_24 ( V_31 ) ;
long V_177 ;
int V_387 = 0 , V_388 ;
if ( ! F_65 ( V_203 , & V_27 -> V_33 -> V_65 ) )
return 0 ;
F_11 ( & V_10 -> V_380 ) ;
for (; ; ) {
if ( ! F_193 ( V_181 - 1 , V_10 -> V_181 ) ) {
V_10 -> V_181 = F_194 ( V_10 -> V_181 , V_181 ) ;
break;
}
if ( F_30 ( V_38 ) ) {
V_387 = - V_95 ;
break;
}
F_25 () ;
V_388 = F_26 ( F_140 ( V_10 ) -> V_33 -> V_29 ) -> V_389 ;
F_27 () ;
if ( ! V_388 )
break;
F_29 ( & V_10 -> V_381 , & V_31 , V_37 ) ;
F_12 ( & V_10 -> V_380 ) ;
F_25 () ;
V_177 = F_26 ( V_27 -> V_33 -> V_29 ) -> V_97 * V_39 / 10 ;
F_27 () ;
V_177 = F_32 ( V_177 ) ;
F_11 ( & V_10 -> V_380 ) ;
if ( ! V_177 ) {
V_387 = - V_140 ;
F_41 ( V_10 , L_43 ) ;
break;
}
}
F_12 ( & V_10 -> V_380 ) ;
F_33 ( & V_10 -> V_381 , & V_31 ) ;
return V_387 ;
}
static unsigned long F_200 ( T_7 V_390 )
{
return ( V_390 & V_391 ? V_392 : 0 ) |
( V_390 & V_393 ? V_394 : 0 ) |
( V_390 & V_395 ? V_396 : 0 ) |
( V_390 & V_397 ? V_301 : 0 ) ;
}
static void F_201 ( struct V_9 * V_10 , T_3 V_48 ,
unsigned int V_60 )
{
struct V_307 * V_6 ;
V_398:
F_187 (i, &device->write_requests, sector, size) {
struct V_331 * V_332 ;
struct V_399 V_400 ;
if ( ! V_6 -> T_5 )
continue;
V_332 = F_168 ( V_6 , struct V_331 , V_6 ) ;
if ( ! ( V_332 -> V_360 & V_362 ) )
continue;
V_332 -> V_360 &= ~ V_362 ;
F_188 ( V_332 , V_401 , & V_400 ) ;
F_21 ( & V_10 -> V_24 -> V_25 ) ;
if ( V_400 . V_283 )
F_202 ( V_10 , & V_400 ) ;
F_20 ( & V_10 -> V_24 -> V_25 ) ;
goto V_398;
}
}
static int F_203 ( struct V_9 * V_10 ,
struct V_18 * V_19 )
{
struct V_91 * V_33 = V_19 -> V_27 -> V_33 ;
bool V_402 = F_65 ( V_203 , & V_33 -> V_65 ) ;
T_3 V_48 = V_19 -> V_6 . V_48 ;
const unsigned int V_60 = V_19 -> V_6 . V_60 ;
struct V_307 * V_6 ;
bool V_403 ;
int V_73 ;
F_204 ( & V_10 -> V_308 , & V_19 -> V_6 ) ;
V_398:
F_187 (i, &device->write_requests, sector, size) {
if ( V_6 == & V_19 -> V_6 )
continue;
if ( V_6 -> V_404 )
continue;
if ( ! V_6 -> T_5 ) {
V_73 = F_205 ( V_10 , V_6 ) ;
if ( V_73 )
goto V_101;
goto V_398;
}
V_403 = V_6 -> V_48 == V_48 && V_6 -> V_60 == V_60 ;
if ( V_402 ) {
bool V_405 = V_6 -> V_48 <= V_48 && V_6 -> V_48 +
( V_6 -> V_60 >> 9 ) >= V_48 + ( V_60 >> 9 ) ;
if ( ! V_403 )
F_206 ( V_10 , L_44
L_45
L_46 ,
( unsigned long long ) V_6 -> V_48 , V_6 -> V_60 ,
( unsigned long long ) V_48 , V_60 ,
V_405 ? L_47 : L_48 ) ;
V_19 -> V_20 . V_76 = V_405 ? F_191 :
F_192 ;
F_141 ( & V_19 -> V_20 . V_21 , & V_10 -> V_74 ) ;
F_207 ( V_33 ) ;
V_73 = - V_406 ;
goto V_101;
} else {
struct V_331 * V_332 =
F_168 ( V_6 , struct V_331 , V_6 ) ;
if ( ! V_403 )
F_206 ( V_10 , L_44
L_49 ,
( unsigned long long ) V_6 -> V_48 , V_6 -> V_60 ,
( unsigned long long ) V_48 , V_60 ) ;
if ( V_332 -> V_360 & V_361 ||
! ( V_332 -> V_360 & V_362 ) ) {
V_73 = F_205 ( V_10 , & V_332 -> V_6 ) ;
if ( V_73 ) {
F_208 ( V_33 , F_68 ( V_102 , V_407 ) , V_104 ) ;
F_201 ( V_10 , V_48 , V_60 ) ;
goto V_101;
}
goto V_398;
}
V_19 -> V_65 |= V_373 ;
}
}
V_73 = 0 ;
V_101:
if ( V_73 )
F_149 ( V_10 , V_19 ) ;
return V_73 ;
}
static int F_209 ( struct V_91 * V_33 , struct V_168 * V_169 )
{
struct V_26 * V_27 ;
struct V_9 * V_10 ;
struct V_29 * V_30 ;
T_3 V_48 ;
struct V_18 * V_19 ;
struct V_355 * V_314 = V_169 -> V_93 ;
T_7 V_181 = F_123 ( V_314 -> V_408 ) ;
int V_281 = V_349 ;
T_7 V_409 ;
int V_73 , V_388 ;
V_27 = F_151 ( V_33 , V_169 -> V_191 ) ;
if ( ! V_27 )
return - V_105 ;
V_10 = V_27 -> V_10 ;
if ( ! F_127 ( V_10 ) ) {
int V_75 ;
V_73 = F_199 ( V_27 , V_181 ) ;
F_185 ( V_27 , V_345 , V_314 , V_169 -> V_60 ) ;
F_210 ( & V_33 -> V_264 -> V_253 ) ;
V_75 = F_163 ( V_27 , V_169 -> V_60 ) ;
if ( ! V_73 )
V_73 = V_75 ;
return V_73 ;
}
V_48 = F_180 ( V_314 -> V_48 ) ;
V_19 = F_156 ( V_27 , V_314 -> V_64 , V_48 , V_169 ) ;
if ( ! V_19 ) {
F_130 ( V_10 ) ;
return - V_105 ;
}
V_19 -> V_20 . V_76 = F_189 ;
V_19 -> V_61 = V_62 ;
V_19 -> V_65 |= V_410 ;
V_409 = F_123 ( V_314 -> V_409 ) ;
V_281 |= F_200 ( V_409 ) ;
if ( V_169 -> V_166 == V_326 ) {
struct V_411 * V_412 = F_211 ( V_10 -> V_245 -> V_246 ) ;
V_19 -> V_65 |= V_291 ;
if ( ! F_212 ( V_412 ) )
V_19 -> V_65 |= V_287 ;
F_49 ( V_27 , V_19 -> V_6 . V_60 > 0 ) ;
F_49 ( V_27 , V_281 & V_301 ) ;
F_49 ( V_27 , V_19 -> V_63 == NULL ) ;
} else if ( V_19 -> V_63 == NULL ) {
F_49 ( V_10 , V_19 -> V_6 . V_60 == 0 ) ;
F_49 ( V_10 , V_409 & V_395 ) ;
}
if ( V_409 & V_413 )
V_19 -> V_65 |= V_370 ;
F_11 ( & V_33 -> V_256 ) ;
V_19 -> V_250 = V_33 -> V_264 ;
F_210 ( & V_19 -> V_250 -> V_253 ) ;
F_210 ( & V_19 -> V_250 -> V_259 ) ;
F_12 ( & V_33 -> V_256 ) ;
F_25 () ;
V_30 = F_26 ( V_27 -> V_33 -> V_29 ) ;
V_388 = V_30 -> V_389 ;
if ( V_27 -> V_33 -> V_183 < 100 ) {
switch ( V_30 -> V_414 ) {
case V_415 :
V_409 |= V_416 ;
break;
case V_417 :
V_409 |= V_418 ;
break;
}
}
F_27 () ;
if ( V_409 & V_416 ) {
V_19 -> V_65 |= V_366 ;
F_176 ( V_10 ) ;
}
if ( V_409 & V_418 ) {
F_171 ( F_140 ( V_10 ) , V_419 , V_19 ) ;
}
if ( V_388 ) {
F_49 ( V_10 , V_409 & V_416 ) ;
V_19 -> V_65 |= V_372 ;
V_73 = F_199 ( V_27 , V_181 ) ;
if ( V_73 )
goto V_420;
F_20 ( & V_10 -> V_24 -> V_25 ) ;
V_73 = F_203 ( V_10 , V_19 ) ;
if ( V_73 ) {
F_21 ( & V_10 -> V_24 -> V_25 ) ;
if ( V_73 == - V_406 ) {
F_130 ( V_10 ) ;
return 0 ;
}
goto V_420;
}
} else {
F_195 ( V_27 , V_181 ) ;
F_20 ( & V_10 -> V_24 -> V_25 ) ;
}
if ( ( V_19 -> V_65 & V_287 ) == 0 )
F_141 ( & V_19 -> V_20 . V_21 , & V_10 -> V_289 ) ;
F_21 ( & V_10 -> V_24 -> V_25 ) ;
if ( V_10 -> V_367 . V_102 == V_421 )
F_213 ( V_10 -> V_77 , ! F_197 ( V_10 , V_19 ) ) ;
if ( V_10 -> V_367 . V_422 < V_423 ) {
F_214 ( V_10 , V_19 -> V_6 . V_48 , V_19 -> V_6 . V_60 ) ;
V_19 -> V_65 &= ~ V_370 ;
F_215 ( V_10 , & V_19 -> V_6 ) ;
V_19 -> V_65 |= V_69 ;
}
V_73 = F_138 ( V_10 , V_19 , V_281 , V_424 ) ;
if ( ! V_73 )
return 0 ;
F_41 ( V_10 , L_40 ) ;
F_20 ( & V_10 -> V_24 -> V_25 ) ;
F_135 ( & V_19 -> V_20 . V_21 ) ;
F_149 ( V_10 , V_19 ) ;
F_21 ( & V_10 -> V_24 -> V_25 ) ;
if ( V_19 -> V_65 & V_69 ) {
V_19 -> V_65 &= ~ V_69 ;
F_52 ( V_10 , & V_19 -> V_6 ) ;
}
V_420:
F_131 ( V_33 , V_19 -> V_250 , V_258 + V_257 ) ;
F_130 ( V_10 ) ;
F_56 ( V_10 , V_19 ) ;
return V_73 ;
}
bool F_216 ( struct V_9 * V_10 , T_3 V_48 ,
bool V_425 )
{
struct V_426 * V_4 ;
bool V_427 = F_217 ( V_10 ) ;
if ( ! V_427 || V_425 )
return V_427 ;
F_20 ( & V_10 -> V_428 ) ;
V_4 = F_218 ( V_10 -> V_429 , F_219 ( V_48 ) ) ;
if ( V_4 ) {
struct V_430 * V_431 = F_220 ( V_4 , struct V_430 , V_432 ) ;
if ( F_65 ( V_433 , & V_431 -> V_65 ) )
V_427 = false ;
}
F_21 ( & V_10 -> V_428 ) ;
return V_427 ;
}
bool F_217 ( struct V_9 * V_10 )
{
struct V_434 * V_435 = V_10 -> V_245 -> V_246 -> V_436 -> V_437 ;
unsigned long V_438 , V_439 , V_440 ;
unsigned int V_441 ;
int V_442 ;
F_25 () ;
V_441 = F_26 ( V_10 -> V_245 -> V_273 ) -> V_441 ;
F_27 () ;
if ( V_441 == 0 )
return false ;
V_442 = ( int ) F_221 ( & V_435 -> V_443 , V_444 [ 0 ] ) +
( int ) F_221 ( & V_435 -> V_443 , V_444 [ 1 ] ) -
F_28 ( & V_10 -> V_348 ) ;
if ( F_28 ( & V_10 -> V_445 )
|| V_442 - V_10 -> V_446 > 64 ) {
unsigned long V_447 ;
int V_6 ;
V_10 -> V_446 = V_442 ;
V_6 = ( V_10 -> V_448 + V_449 - 1 ) % V_449 ;
if ( V_10 -> V_367 . V_102 == V_450 || V_10 -> V_367 . V_102 == V_451 )
V_447 = V_10 -> V_452 ;
else
V_447 = F_222 ( V_10 ) - V_10 -> V_453 ;
V_439 = ( ( long ) V_62 - ( long ) V_10 -> V_454 [ V_6 ] ) / V_39 ;
if ( ! V_439 )
V_439 ++ ;
V_438 = V_10 -> V_455 [ V_6 ] - V_447 ;
V_440 = F_223 ( V_438 / V_439 ) ;
if ( V_440 > V_441 )
return true ;
}
return false ;
}
static int F_224 ( struct V_91 * V_33 , struct V_168 * V_169 )
{
struct V_26 * V_27 ;
struct V_9 * V_10 ;
T_3 V_48 ;
T_3 V_316 ;
struct V_18 * V_19 ;
struct V_456 * V_457 = NULL ;
int V_60 , V_458 ;
unsigned int V_282 ;
struct V_459 * V_314 = V_169 -> V_93 ;
V_27 = F_151 ( V_33 , V_169 -> V_191 ) ;
if ( ! V_27 )
return - V_105 ;
V_10 = V_27 -> V_10 ;
V_316 = F_157 ( V_10 -> V_317 ) ;
V_48 = F_180 ( V_314 -> V_48 ) ;
V_60 = F_123 ( V_314 -> V_460 ) ;
if ( V_60 <= 0 || ! F_159 ( V_60 , 512 ) || V_60 > V_44 ) {
F_41 ( V_10 , L_50 , __FILE__ , __LINE__ ,
( unsigned long long ) V_48 , V_60 ) ;
return - V_231 ;
}
if ( V_48 + ( V_60 >> 9 ) > V_316 ) {
F_41 ( V_10 , L_50 , __FILE__ , __LINE__ ,
( unsigned long long ) V_48 , V_60 ) ;
return - V_231 ;
}
if ( ! F_225 ( V_10 , V_461 ) ) {
V_458 = 1 ;
switch ( V_169 -> V_166 ) {
case V_462 :
F_226 ( V_27 , V_463 , V_314 ) ;
break;
case V_464 :
case V_465 :
case V_466 :
F_226 ( V_27 , V_467 , V_314 ) ;
break;
case V_468 :
V_458 = 0 ;
F_175 ( V_10 ) ;
F_227 ( V_27 , V_469 , V_48 , V_60 , V_470 ) ;
break;
default:
F_228 () ;
}
if ( V_458 && F_184 ( & V_358 ) )
F_41 ( V_10 , L_51
L_52 ) ;
return F_163 ( V_27 , V_169 -> V_60 ) ;
}
V_19 = F_38 ( V_27 , V_314 -> V_64 , V_48 , V_60 ,
true , V_211 ) ;
if ( ! V_19 ) {
F_130 ( V_10 ) ;
return - V_286 ;
}
switch ( V_169 -> V_166 ) {
case V_462 :
V_19 -> V_20 . V_76 = V_471 ;
V_282 = V_472 ;
V_19 -> V_65 |= V_410 ;
goto V_303;
case V_464 :
V_19 -> V_20 . V_76 = V_473 ;
V_282 = V_474 ;
V_10 -> V_475 = F_229 ( V_48 ) ;
break;
case V_468 :
case V_465 :
V_282 = V_474 ;
V_457 = F_154 ( sizeof( * V_457 ) + V_169 -> V_60 , V_211 ) ;
if ( ! V_457 )
goto V_476;
V_457 -> V_318 = V_169 -> V_60 ;
V_457 -> V_67 = ( ( ( char * ) V_457 ) + sizeof( struct V_456 ) ) ;
V_19 -> V_67 = V_457 ;
V_19 -> V_65 |= V_66 ;
if ( F_69 ( V_27 -> V_33 , V_457 -> V_67 , V_169 -> V_60 ) )
goto V_476;
if ( V_169 -> V_166 == V_465 ) {
F_49 ( V_10 , V_27 -> V_33 -> V_183 >= 89 ) ;
V_19 -> V_20 . V_76 = V_477 ;
V_10 -> V_475 = F_229 ( V_48 ) ;
V_10 -> V_478 = true ;
} else if ( V_169 -> V_166 == V_468 ) {
F_34 ( V_60 >> 9 , & V_10 -> V_359 ) ;
V_19 -> V_20 . V_76 = V_479 ;
F_175 ( V_10 ) ;
goto V_480;
}
break;
case V_466 :
if ( V_10 -> V_481 == ~ ( T_3 ) 0 &&
V_27 -> V_33 -> V_183 >= 90 ) {
unsigned long V_482 = V_62 ;
int V_6 ;
V_10 -> V_481 = V_48 ;
V_10 -> V_483 = V_48 ;
V_10 -> V_452 = F_230 ( V_10 ) - F_229 ( V_48 ) ;
V_10 -> V_484 = V_10 -> V_452 ;
for ( V_6 = 0 ; V_6 < V_449 ; V_6 ++ ) {
V_10 -> V_455 [ V_6 ] = V_10 -> V_452 ;
V_10 -> V_454 [ V_6 ] = V_482 ;
}
F_64 ( V_10 , L_53 ,
( unsigned long long ) V_48 ) ;
}
V_19 -> V_20 . V_76 = V_485 ;
V_282 = V_474 ;
break;
default:
F_228 () ;
}
F_20 ( & V_10 -> V_24 -> V_25 ) ;
F_141 ( & V_19 -> V_20 . V_21 , & V_10 -> V_486 ) ;
F_21 ( & V_10 -> V_24 -> V_25 ) ;
F_231 ( V_33 , F_216 ) ;
if ( V_10 -> V_367 . V_487 != V_488
&& F_216 ( V_10 , V_48 , false ) )
F_232 ( V_39 / 10 ) ;
F_231 ( V_33 , V_489 ) ;
if ( V_489 ( V_10 , V_48 ) )
goto V_476;
V_480:
F_34 ( V_60 >> 9 , & V_10 -> V_348 ) ;
V_303:
F_231 ( V_33 , F_138 ) ;
F_176 ( V_10 ) ;
if ( F_138 ( V_10 , V_19 , V_490 , V_282 ) == 0 )
return 0 ;
F_41 ( V_10 , L_40 ) ;
V_476:
F_20 ( & V_10 -> V_24 -> V_25 ) ;
F_135 ( & V_19 -> V_20 . V_21 ) ;
F_21 ( & V_10 -> V_24 -> V_25 ) ;
F_130 ( V_10 ) ;
F_56 ( V_10 , V_19 ) ;
return - V_105 ;
}
static int F_233 ( struct V_26 * V_27 ) __must_hold( T_5 )
{
struct V_9 * V_10 = V_27 -> V_10 ;
int V_491 , V_487 , V_92 = - 100 ;
unsigned long V_492 , V_493 ;
enum V_494 V_495 ;
V_491 = V_10 -> V_245 -> V_496 . V_497 [ V_498 ] & 1 ;
V_487 = V_10 -> V_499 [ V_498 ] & 1 ;
V_493 = V_10 -> V_499 [ V_500 ] ;
V_492 = V_10 -> V_501 ;
F_25 () ;
V_495 = F_26 ( V_27 -> V_33 -> V_29 ) -> V_495 ;
F_27 () ;
switch ( V_495 ) {
case V_502 :
case V_503 :
case V_504 :
case V_505 :
F_41 ( V_10 , L_54 ) ;
break;
case V_506 :
break;
case V_507 :
if ( V_491 == 0 && V_487 == 1 ) {
V_92 = - 1 ;
break;
}
if ( V_491 == 1 && V_487 == 0 ) {
V_92 = 1 ;
break;
}
case V_508 :
if ( V_491 == 0 && V_487 == 1 ) {
V_92 = 1 ;
break;
}
if ( V_491 == 1 && V_487 == 0 ) {
V_92 = - 1 ;
break;
}
F_31 ( V_10 , L_55
L_56 ) ;
case V_509 :
if ( V_493 == 0 && V_492 == 0 ) {
V_92 = F_65 ( V_203 , & V_27 -> V_33 -> V_65 )
? - 1 : 1 ;
break;
} else {
if ( V_493 == 0 ) { V_92 = 1 ; break; }
if ( V_492 == 0 ) { V_92 = - 1 ; break; }
}
if ( V_495 == V_509 )
break;
case V_510 :
if ( V_492 < V_493 )
V_92 = - 1 ;
else if ( V_492 > V_493 )
V_92 = 1 ;
else
V_92 = F_65 ( V_203 , & V_27 -> V_33 -> V_65 )
? - 1 : 1 ;
break;
case V_511 :
V_92 = - 1 ;
break;
case V_512 :
V_92 = 1 ;
}
return V_92 ;
}
static int F_234 ( struct V_26 * V_27 ) __must_hold( T_5 )
{
struct V_9 * V_10 = V_27 -> V_10 ;
int V_513 , V_92 = - 100 ;
enum V_494 V_514 ;
F_25 () ;
V_514 = F_26 ( V_27 -> V_33 -> V_29 ) -> V_514 ;
F_27 () ;
switch ( V_514 ) {
case V_507 :
case V_508 :
case V_510 :
case V_511 :
case V_512 :
case V_509 :
F_41 ( V_10 , L_54 ) ;
break;
case V_506 :
break;
case V_502 :
V_513 = F_233 ( V_27 ) ;
if ( V_513 == - 1 && V_10 -> V_367 . V_515 == V_516 )
V_92 = V_513 ;
if ( V_513 == 1 && V_10 -> V_367 . V_515 == V_488 )
V_92 = V_513 ;
break;
case V_505 :
V_92 = F_233 ( V_27 ) ;
break;
case V_503 :
return V_10 -> V_367 . V_515 == V_488 ? 1 : - 1 ;
case V_504 :
V_513 = F_233 ( V_27 ) ;
if ( V_513 == - 1 && V_10 -> V_367 . V_515 == V_488 ) {
enum V_194 V_517 ;
V_517 = F_235 ( V_10 , V_196 , F_68 ( V_515 , V_516 ) ) ;
if ( V_517 != V_197 ) {
F_236 ( V_10 , L_57 ) ;
} else {
F_31 ( V_10 , L_58 ) ;
V_92 = V_513 ;
}
} else
V_92 = V_513 ;
}
return V_92 ;
}
static int F_237 ( struct V_26 * V_27 ) __must_hold( T_5 )
{
struct V_9 * V_10 = V_27 -> V_10 ;
int V_513 , V_92 = - 100 ;
enum V_494 V_518 ;
F_25 () ;
V_518 = F_26 ( V_27 -> V_33 -> V_29 ) -> V_518 ;
F_27 () ;
switch ( V_518 ) {
case V_507 :
case V_508 :
case V_510 :
case V_511 :
case V_512 :
case V_502 :
case V_503 :
case V_509 :
F_41 ( V_10 , L_54 ) ;
break;
case V_505 :
V_92 = F_233 ( V_27 ) ;
break;
case V_506 :
break;
case V_504 :
V_513 = F_233 ( V_27 ) ;
if ( V_513 == - 1 ) {
enum V_194 V_517 ;
V_517 = F_235 ( V_10 , V_196 , F_68 ( V_515 , V_516 ) ) ;
if ( V_517 != V_197 ) {
F_236 ( V_10 , L_57 ) ;
} else {
F_31 ( V_10 , L_58 ) ;
V_92 = V_513 ;
}
} else
V_92 = V_513 ;
}
return V_92 ;
}
static void F_238 ( struct V_9 * V_10 , char * V_519 , T_2 * V_497 ,
T_2 V_520 , T_2 V_65 )
{
if ( ! V_497 ) {
F_64 ( V_10 , L_59 , V_519 ) ;
return;
}
F_64 ( V_10 , L_60 ,
V_519 ,
( unsigned long long ) V_497 [ V_521 ] ,
( unsigned long long ) V_497 [ V_498 ] ,
( unsigned long long ) V_497 [ V_522 ] ,
( unsigned long long ) V_497 [ V_523 ] ,
( unsigned long long ) V_520 ,
( unsigned long long ) V_65 ) ;
}
static int F_239 ( struct V_9 * const V_10 , int * V_524 ) __must_hold( T_5 )
{
struct V_26 * const V_27 = F_140 ( V_10 ) ;
struct V_91 * const V_33 = V_27 ? V_27 -> V_33 : NULL ;
T_2 V_491 , V_487 ;
int V_6 , V_525 ;
V_491 = V_10 -> V_245 -> V_496 . V_497 [ V_521 ] & ~ ( ( T_2 ) 1 ) ;
V_487 = V_10 -> V_499 [ V_521 ] & ~ ( ( T_2 ) 1 ) ;
* V_524 = 10 ;
if ( V_491 == V_526 && V_487 == V_526 )
return 0 ;
* V_524 = 20 ;
if ( ( V_491 == V_526 || V_491 == ( T_2 ) 0 ) &&
V_487 != V_526 )
return - 2 ;
* V_524 = 30 ;
if ( V_491 != V_526 &&
( V_487 == V_526 || V_487 == ( T_2 ) 0 ) )
return 2 ;
if ( V_491 == V_487 ) {
int V_527 , V_274 ;
if ( V_10 -> V_499 [ V_498 ] == ( T_2 ) 0 && V_10 -> V_245 -> V_496 . V_497 [ V_498 ] != ( T_2 ) 0 ) {
if ( V_33 -> V_183 < 91 )
return - 1091 ;
if ( ( V_10 -> V_245 -> V_496 . V_497 [ V_498 ] & ~ ( ( T_2 ) 1 ) ) == ( V_10 -> V_499 [ V_522 ] & ~ ( ( T_2 ) 1 ) ) &&
( V_10 -> V_245 -> V_496 . V_497 [ V_522 ] & ~ ( ( T_2 ) 1 ) ) == ( V_10 -> V_499 [ V_522 + 1 ] & ~ ( ( T_2 ) 1 ) ) ) {
F_64 ( V_10 , L_61 ) ;
F_240 ( V_10 ) ;
V_10 -> V_245 -> V_496 . V_497 [ V_522 ] = V_10 -> V_245 -> V_496 . V_497 [ V_498 ] ;
V_10 -> V_245 -> V_496 . V_497 [ V_498 ] = 0 ;
F_238 ( V_10 , L_62 , V_10 -> V_245 -> V_496 . V_497 ,
V_10 -> V_367 . V_435 >= V_528 ? F_222 ( V_10 ) : 0 , 0 ) ;
* V_524 = 34 ;
} else {
F_64 ( V_10 , L_63 ) ;
* V_524 = 36 ;
}
return 1 ;
}
if ( V_10 -> V_245 -> V_496 . V_497 [ V_498 ] == ( T_2 ) 0 && V_10 -> V_499 [ V_498 ] != ( T_2 ) 0 ) {
if ( V_33 -> V_183 < 91 )
return - 1091 ;
if ( ( V_10 -> V_245 -> V_496 . V_497 [ V_522 ] & ~ ( ( T_2 ) 1 ) ) == ( V_10 -> V_499 [ V_498 ] & ~ ( ( T_2 ) 1 ) ) &&
( V_10 -> V_245 -> V_496 . V_497 [ V_522 + 1 ] & ~ ( ( T_2 ) 1 ) ) == ( V_10 -> V_499 [ V_522 ] & ~ ( ( T_2 ) 1 ) ) ) {
F_64 ( V_10 , L_64 ) ;
V_10 -> V_499 [ V_522 + 1 ] = V_10 -> V_499 [ V_522 ] ;
V_10 -> V_499 [ V_522 ] = V_10 -> V_499 [ V_498 ] ;
V_10 -> V_499 [ V_498 ] = 0UL ;
F_238 ( V_10 , L_65 , V_10 -> V_499 , V_10 -> V_499 [ V_500 ] , V_10 -> V_499 [ V_529 ] ) ;
* V_524 = 35 ;
} else {
F_64 ( V_10 , L_66 ) ;
* V_524 = 37 ;
}
return - 1 ;
}
V_527 = ( F_65 ( V_530 , & V_10 -> V_65 ) ? 1 : 0 ) +
( V_10 -> V_499 [ V_529 ] & 2 ) ;
* V_524 = 40 ;
switch ( V_527 ) {
case 0 : return 0 ;
case 1 : return 1 ;
case 2 : return - 1 ;
case 3 :
V_274 = F_65 ( V_203 , & V_33 -> V_65 ) ;
return V_274 ? - 1 : 1 ;
}
}
* V_524 = 50 ;
V_487 = V_10 -> V_499 [ V_498 ] & ~ ( ( T_2 ) 1 ) ;
if ( V_491 == V_487 )
return - 1 ;
* V_524 = 51 ;
V_487 = V_10 -> V_499 [ V_522 ] & ~ ( ( T_2 ) 1 ) ;
if ( V_491 == V_487 ) {
if ( V_33 -> V_183 < 96 ?
( V_10 -> V_245 -> V_496 . V_497 [ V_522 ] & ~ ( ( T_2 ) 1 ) ) ==
( V_10 -> V_499 [ V_522 + 1 ] & ~ ( ( T_2 ) 1 ) ) :
V_487 + V_531 == ( V_10 -> V_499 [ V_498 ] & ~ ( ( T_2 ) 1 ) ) ) {
if ( V_33 -> V_183 < 91 )
return - 1091 ;
V_10 -> V_499 [ V_498 ] = V_10 -> V_499 [ V_522 ] ;
V_10 -> V_499 [ V_522 ] = V_10 -> V_499 [ V_522 + 1 ] ;
F_64 ( V_10 , L_67 ) ;
F_238 ( V_10 , L_65 , V_10 -> V_499 , V_10 -> V_499 [ V_500 ] , V_10 -> V_499 [ V_529 ] ) ;
return - 1 ;
}
}
* V_524 = 60 ;
V_491 = V_10 -> V_245 -> V_496 . V_497 [ V_521 ] & ~ ( ( T_2 ) 1 ) ;
for ( V_6 = V_522 ; V_6 <= V_523 ; V_6 ++ ) {
V_487 = V_10 -> V_499 [ V_6 ] & ~ ( ( T_2 ) 1 ) ;
if ( V_491 == V_487 )
return - 2 ;
}
* V_524 = 70 ;
V_491 = V_10 -> V_245 -> V_496 . V_497 [ V_498 ] & ~ ( ( T_2 ) 1 ) ;
V_487 = V_10 -> V_499 [ V_521 ] & ~ ( ( T_2 ) 1 ) ;
if ( V_491 == V_487 )
return 1 ;
* V_524 = 71 ;
V_491 = V_10 -> V_245 -> V_496 . V_497 [ V_522 ] & ~ ( ( T_2 ) 1 ) ;
if ( V_491 == V_487 ) {
if ( V_33 -> V_183 < 96 ?
( V_10 -> V_245 -> V_496 . V_497 [ V_522 + 1 ] & ~ ( ( T_2 ) 1 ) ) ==
( V_10 -> V_499 [ V_522 ] & ~ ( ( T_2 ) 1 ) ) :
V_491 + V_531 == ( V_10 -> V_245 -> V_496 . V_497 [ V_498 ] & ~ ( ( T_2 ) 1 ) ) ) {
if ( V_33 -> V_183 < 91 )
return - 1091 ;
F_241 ( V_10 , V_498 , V_10 -> V_245 -> V_496 . V_497 [ V_522 ] ) ;
F_241 ( V_10 , V_522 , V_10 -> V_245 -> V_496 . V_497 [ V_522 + 1 ] ) ;
F_64 ( V_10 , L_68 ) ;
F_238 ( V_10 , L_62 , V_10 -> V_245 -> V_496 . V_497 ,
V_10 -> V_367 . V_435 >= V_528 ? F_222 ( V_10 ) : 0 , 0 ) ;
return 1 ;
}
}
* V_524 = 80 ;
V_487 = V_10 -> V_499 [ V_521 ] & ~ ( ( T_2 ) 1 ) ;
for ( V_6 = V_522 ; V_6 <= V_523 ; V_6 ++ ) {
V_491 = V_10 -> V_245 -> V_496 . V_497 [ V_6 ] & ~ ( ( T_2 ) 1 ) ;
if ( V_491 == V_487 )
return 2 ;
}
* V_524 = 90 ;
V_491 = V_10 -> V_245 -> V_496 . V_497 [ V_498 ] & ~ ( ( T_2 ) 1 ) ;
V_487 = V_10 -> V_499 [ V_498 ] & ~ ( ( T_2 ) 1 ) ;
if ( V_491 == V_487 && V_491 != ( ( T_2 ) 0 ) )
return 100 ;
* V_524 = 100 ;
for ( V_6 = V_522 ; V_6 <= V_523 ; V_6 ++ ) {
V_491 = V_10 -> V_245 -> V_496 . V_497 [ V_6 ] & ~ ( ( T_2 ) 1 ) ;
for ( V_525 = V_522 ; V_525 <= V_523 ; V_525 ++ ) {
V_487 = V_10 -> V_499 [ V_525 ] & ~ ( ( T_2 ) 1 ) ;
if ( V_491 == V_487 )
return - 100 ;
}
}
return - 1000 ;
}
static enum V_532 F_242 ( struct V_26 * V_27 ,
enum V_533 V_534 ,
enum V_535 V_536 ) __must_hold( T_5 )
{
struct V_9 * V_10 = V_27 -> V_10 ;
enum V_532 V_92 = V_537 ;
enum V_535 V_538 ;
struct V_29 * V_30 ;
int V_513 , V_524 , V_539 , V_540 ;
V_538 = V_10 -> V_367 . V_435 ;
if ( V_538 == V_528 )
V_538 = V_10 -> V_541 . V_435 ;
F_64 ( V_10 , L_69 ) ;
F_20 ( & V_10 -> V_245 -> V_496 . V_542 ) ;
F_238 ( V_10 , L_62 , V_10 -> V_245 -> V_496 . V_497 , V_10 -> V_501 , 0 ) ;
F_238 ( V_10 , L_65 , V_10 -> V_499 ,
V_10 -> V_499 [ V_500 ] , V_10 -> V_499 [ V_529 ] ) ;
V_513 = F_239 ( V_10 , & V_524 ) ;
F_21 ( & V_10 -> V_245 -> V_496 . V_542 ) ;
F_64 ( V_10 , L_70 , V_513 , V_524 ) ;
if ( V_513 == - 1000 ) {
F_206 ( V_10 , L_71 ) ;
return V_537 ;
}
if ( V_513 < - 1000 ) {
F_206 ( V_10 , L_72 , - V_513 - 1000 ) ;
return V_537 ;
}
if ( ( V_538 == V_423 && V_536 > V_423 ) ||
( V_536 == V_423 && V_538 > V_423 ) ) {
int V_543 = ( V_513 == - 100 ) || abs ( V_513 ) == 2 ;
V_513 = V_538 > V_423 ? 1 : - 1 ;
if ( V_543 )
V_513 = V_513 * 2 ;
F_64 ( V_10 , L_73 ,
V_513 > 0 ? L_74 : L_75 ) ;
}
if ( abs ( V_513 ) == 100 )
F_236 ( V_10 , L_76 ) ;
F_25 () ;
V_30 = F_26 ( V_27 -> V_33 -> V_29 ) ;
if ( V_513 == 100 || ( V_513 == - 100 && V_30 -> V_544 ) ) {
int V_545 = ( V_10 -> V_367 . V_515 == V_488 )
+ ( V_534 == V_488 ) ;
int V_546 = ( V_513 == - 100 ) ;
switch ( V_545 ) {
case 0 :
V_513 = F_233 ( V_27 ) ;
break;
case 1 :
V_513 = F_234 ( V_27 ) ;
break;
case 2 :
V_513 = F_237 ( V_27 ) ;
break;
}
if ( abs ( V_513 ) < 100 ) {
F_31 ( V_10 , L_77
L_78 ,
V_545 , ( V_513 < 0 ) ? L_65 : L_79 ) ;
if ( V_546 ) {
F_31 ( V_10 , L_80
L_81 ) ;
V_513 = V_513 * 2 ;
}
}
}
if ( V_513 == - 100 ) {
if ( F_65 ( V_222 , & V_10 -> V_65 ) && ! ( V_10 -> V_499 [ V_529 ] & 1 ) )
V_513 = - 1 ;
if ( ! F_65 ( V_222 , & V_10 -> V_65 ) && ( V_10 -> V_499 [ V_529 ] & 1 ) )
V_513 = 1 ;
if ( abs ( V_513 ) < 100 )
F_31 ( V_10 , L_82
L_83 ,
( V_513 < 0 ) ? L_65 : L_79 ) ;
}
V_539 = V_30 -> V_539 ;
V_540 = V_30 -> V_540 ;
F_27 () ;
if ( V_513 == - 100 ) {
F_206 ( V_10 , L_84 ) ;
F_236 ( V_10 , L_85 ) ;
return V_537 ;
}
if ( V_513 > 0 && V_538 <= V_423 ) {
F_41 ( V_10 , L_86 ) ;
return V_537 ;
}
if ( V_513 < 0 &&
V_10 -> V_367 . V_515 == V_488 && V_10 -> V_367 . V_435 >= V_547 ) {
switch ( V_539 ) {
case V_504 :
F_236 ( V_10 , L_87 ) ;
case V_506 :
F_41 ( V_10 , L_88 ) ;
return V_537 ;
case V_505 :
F_31 ( V_10 , L_89
L_90 ) ;
}
}
if ( V_540 || F_65 ( V_548 , & V_27 -> V_33 -> V_65 ) ) {
if ( V_513 == 0 )
F_64 ( V_10 , L_91 ) ;
else
F_64 ( V_10 , L_92 ,
F_243 ( V_513 > 0 ? V_368 : V_421 ) ,
abs ( V_513 ) >= 2 ? L_93 : L_94 ) ;
return V_537 ;
}
if ( abs ( V_513 ) >= 2 ) {
F_64 ( V_10 , L_95 ) ;
if ( F_244 ( V_10 , & V_549 , L_96 ,
V_550 ) )
return V_537 ;
}
if ( V_513 > 0 ) {
V_92 = V_551 ;
} else if ( V_513 < 0 ) {
V_92 = V_552 ;
} else {
V_92 = V_553 ;
if ( F_222 ( V_10 ) ) {
F_64 ( V_10 , L_97 ,
F_222 ( V_10 ) ) ;
}
}
return V_92 ;
}
static enum V_494 F_245 ( enum V_494 V_487 )
{
if ( V_487 == V_512 )
return V_511 ;
if ( V_487 == V_511 )
return V_512 ;
return V_487 ;
}
static int F_246 ( struct V_91 * V_33 , struct V_168 * V_169 )
{
struct V_554 * V_314 = V_169 -> V_93 ;
enum V_494 V_555 , V_556 , V_557 ;
int V_558 , V_559 , V_560 , V_561 ;
struct V_29 * V_30 , * V_562 , * V_563 = NULL ;
char V_564 [ V_565 ] = L_98 ;
struct V_566 * V_327 = NULL ;
void * V_321 = NULL , * V_323 = NULL ;
V_558 = F_123 ( V_314 -> V_567 ) ;
V_555 = F_123 ( V_314 -> V_495 ) ;
V_556 = F_123 ( V_314 -> V_514 ) ;
V_557 = F_123 ( V_314 -> V_518 ) ;
V_560 = F_123 ( V_314 -> V_389 ) ;
V_561 = F_123 ( V_314 -> V_568 ) ;
V_559 = V_561 & V_569 ;
if ( V_33 -> V_183 >= 87 ) {
int V_73 ;
if ( V_169 -> V_60 > sizeof( V_564 ) )
return - V_105 ;
V_73 = F_69 ( V_33 , V_564 , V_169 -> V_60 ) ;
if ( V_73 )
return V_73 ;
V_564 [ V_565 - 1 ] = 0 ;
}
if ( V_169 -> V_166 != V_570 ) {
F_102 ( V_548 , & V_33 -> V_65 ) ;
if ( V_561 & V_571 )
F_107 ( V_548 , & V_33 -> V_65 ) ;
F_25 () ;
V_30 = F_26 ( V_33 -> V_29 ) ;
if ( V_558 != V_30 -> V_414 ) {
F_41 ( V_33 , L_99 , L_100 ) ;
goto V_572;
}
if ( F_245 ( V_555 ) != V_30 -> V_495 ) {
F_41 ( V_33 , L_99 , L_101 ) ;
goto V_572;
}
if ( F_245 ( V_556 ) != V_30 -> V_514 ) {
F_41 ( V_33 , L_99 , L_102 ) ;
goto V_572;
}
if ( F_245 ( V_557 ) != V_30 -> V_518 ) {
F_41 ( V_33 , L_99 , L_103 ) ;
goto V_572;
}
if ( V_559 && V_30 -> V_193 ) {
F_41 ( V_33 , L_99 , L_104 ) ;
goto V_572;
}
if ( V_560 != V_30 -> V_389 ) {
F_41 ( V_33 , L_99 , L_105 ) ;
goto V_572;
}
if ( strcmp ( V_564 , V_30 -> V_564 ) ) {
F_41 ( V_33 , L_99 , L_106 ) ;
goto V_572;
}
F_27 () ;
}
if ( V_564 [ 0 ] ) {
int V_573 ;
V_327 = F_247 ( V_564 , 0 , V_574 ) ;
if ( ! V_327 ) {
F_41 ( V_33 , L_107 ,
V_564 ) ;
goto V_575;
}
V_573 = F_158 ( V_327 ) ;
V_321 = F_154 ( V_573 , V_576 ) ;
V_323 = F_154 ( V_573 , V_576 ) ;
if ( ! ( V_321 && V_323 ) ) {
F_41 ( V_33 , L_108 ) ;
goto V_575;
}
}
V_563 = F_154 ( sizeof( struct V_29 ) , V_576 ) ;
if ( ! V_563 ) {
F_41 ( V_33 , L_109 ) ;
goto V_575;
}
F_116 ( & V_33 -> V_93 . V_198 ) ;
F_116 ( & V_33 -> V_24 -> V_225 ) ;
V_562 = V_33 -> V_29 ;
* V_563 = * V_562 ;
V_563 -> V_414 = V_558 ;
V_563 -> V_495 = F_245 ( V_555 ) ;
V_563 -> V_514 = F_245 ( V_556 ) ;
V_563 -> V_518 = F_245 ( V_557 ) ;
V_563 -> V_389 = V_560 ;
F_248 ( V_33 -> V_29 , V_563 ) ;
F_117 ( & V_33 -> V_24 -> V_225 ) ;
F_117 ( & V_33 -> V_93 . V_198 ) ;
F_249 ( V_33 -> V_327 ) ;
F_48 ( V_33 -> V_321 ) ;
F_48 ( V_33 -> V_323 ) ;
V_33 -> V_327 = V_327 ;
V_33 -> V_321 = V_321 ;
V_33 -> V_323 = V_323 ;
if ( strcmp ( V_562 -> V_564 , V_564 ) )
F_64 ( V_33 , L_110 ,
V_564 [ 0 ] ? V_564 : L_111 ) ;
F_250 () ;
F_48 ( V_562 ) ;
return 0 ;
V_572:
F_27 () ;
V_575:
F_249 ( V_327 ) ;
F_48 ( V_321 ) ;
F_48 ( V_323 ) ;
F_67 ( V_33 , F_68 ( V_102 , V_148 ) , V_104 ) ;
return - V_105 ;
}
static struct V_566 * F_251 ( const struct V_9 * V_10 ,
const char * V_577 , const char * V_578 )
{
struct V_566 * V_579 ;
if ( ! V_577 [ 0 ] )
return NULL ;
V_579 = F_247 ( V_577 , 0 , V_574 ) ;
if ( F_252 ( V_579 ) ) {
F_41 ( V_10 , L_112 ,
V_577 , V_578 , F_253 ( V_579 ) ) ;
return V_579 ;
}
return V_579 ;
}
static int F_254 ( struct V_91 * V_33 , struct V_168 * V_169 )
{
void * V_240 = V_33 -> V_93 . V_170 ;
int V_60 = V_169 -> V_60 ;
while ( V_60 ) {
int V_201 = F_73 ( int , V_60 , V_580 ) ;
V_201 = F_63 ( V_33 , V_240 , V_201 ) ;
if ( V_201 <= 0 ) {
if ( V_201 < 0 )
return V_201 ;
break;
}
V_60 -= V_201 ;
}
if ( V_60 )
return - V_105 ;
return 0 ;
}
static int F_255 ( struct V_91 * V_33 , struct V_168 * V_169 )
{
F_31 ( V_33 , L_113 ,
F_256 ( V_169 -> V_166 ) , V_169 -> V_191 ) ;
return F_254 ( V_33 , V_169 ) ;
}
static int F_257 ( struct V_91 * V_33 , struct V_168 * V_169 )
{
struct V_26 * V_27 ;
struct V_9 * V_10 ;
struct V_581 * V_314 ;
unsigned int V_167 , V_49 , V_582 ;
struct V_566 * V_583 = NULL ;
struct V_566 * V_584 = NULL ;
struct V_29 * V_562 , * V_563 = NULL ;
struct V_273 * V_585 = NULL , * V_586 = NULL ;
const int V_587 = V_33 -> V_183 ;
struct V_588 * V_589 = NULL , * V_590 = NULL ;
int V_591 = 0 ;
int V_73 ;
V_27 = F_151 ( V_33 , V_169 -> V_191 ) ;
if ( ! V_27 )
return F_255 ( V_33 , V_169 ) ;
V_10 = V_27 -> V_10 ;
V_582 = V_587 <= 87 ? sizeof( struct V_592 )
: V_587 == 88 ? sizeof( struct V_592 )
+ V_565
: V_587 <= 94 ? sizeof( struct V_593 )
: sizeof( struct V_581 ) ;
if ( V_169 -> V_60 > V_582 ) {
F_41 ( V_10 , L_114 ,
V_169 -> V_60 , V_582 ) ;
return - V_105 ;
}
if ( V_587 <= 88 ) {
V_167 = sizeof( struct V_592 ) ;
V_49 = V_169 -> V_60 - V_167 ;
} else if ( V_587 <= 94 ) {
V_167 = sizeof( struct V_593 ) ;
V_49 = V_169 -> V_60 - V_167 ;
F_49 ( V_10 , V_49 == 0 ) ;
} else {
V_167 = sizeof( struct V_581 ) ;
V_49 = V_169 -> V_60 - V_167 ;
F_49 ( V_10 , V_49 == 0 ) ;
}
V_314 = V_169 -> V_93 ;
memset ( V_314 -> V_594 , 0 , 2 * V_565 ) ;
V_73 = F_69 ( V_27 -> V_33 , V_314 , V_167 ) ;
if ( V_73 )
return V_73 ;
F_116 ( & V_33 -> V_24 -> V_225 ) ;
V_562 = V_27 -> V_33 -> V_29 ;
if ( F_127 ( V_10 ) ) {
V_586 = F_258 ( sizeof( struct V_273 ) , V_576 ) ;
if ( ! V_586 ) {
F_130 ( V_10 ) ;
F_117 ( & V_33 -> V_24 -> V_225 ) ;
F_41 ( V_10 , L_115 ) ;
return - V_286 ;
}
V_585 = V_10 -> V_245 -> V_273 ;
* V_586 = * V_585 ;
V_586 -> V_595 = F_123 ( V_314 -> V_595 ) ;
}
if ( V_587 >= 88 ) {
if ( V_587 == 88 ) {
if ( V_49 > V_565 || V_49 == 0 ) {
F_41 ( V_10 , L_116
L_117 ,
V_49 , V_565 ) ;
V_73 = - V_105 ;
goto V_596;
}
V_73 = F_69 ( V_27 -> V_33 , V_314 -> V_594 , V_49 ) ;
if ( V_73 )
goto V_596;
F_49 ( V_10 , V_314 -> V_594 [ V_49 - 1 ] == 0 ) ;
V_314 -> V_594 [ V_49 - 1 ] = 0 ;
} else {
F_49 ( V_10 , V_314 -> V_594 [ V_565 - 1 ] == 0 ) ;
F_49 ( V_10 , V_314 -> V_597 [ V_565 - 1 ] == 0 ) ;
V_314 -> V_594 [ V_565 - 1 ] = 0 ;
V_314 -> V_597 [ V_565 - 1 ] = 0 ;
}
if ( strcmp ( V_562 -> V_594 , V_314 -> V_594 ) ) {
if ( V_10 -> V_367 . V_102 == V_100 ) {
F_41 ( V_10 , L_118 ,
V_562 -> V_594 , V_314 -> V_594 ) ;
goto V_575;
}
V_583 = F_251 ( V_10 ,
V_314 -> V_594 , L_119 ) ;
if ( F_252 ( V_583 ) ) {
V_583 = NULL ;
goto V_575;
}
}
if ( V_587 >= 89 && strcmp ( V_562 -> V_597 , V_314 -> V_597 ) ) {
if ( V_10 -> V_367 . V_102 == V_100 ) {
F_41 ( V_10 , L_120 ,
V_562 -> V_597 , V_314 -> V_597 ) ;
goto V_575;
}
V_584 = F_251 ( V_10 ,
V_314 -> V_597 , L_121 ) ;
if ( F_252 ( V_584 ) ) {
V_584 = NULL ;
goto V_575;
}
}
if ( V_587 > 94 && V_586 ) {
V_586 -> V_598 = F_123 ( V_314 -> V_598 ) ;
V_586 -> V_599 = F_123 ( V_314 -> V_599 ) ;
V_586 -> V_600 = F_123 ( V_314 -> V_600 ) ;
V_586 -> V_601 = F_123 ( V_314 -> V_601 ) ;
V_591 = ( V_586 -> V_598 * 10 * V_602 ) / V_39 ;
if ( V_591 != V_10 -> V_603 -> V_60 ) {
V_590 = F_259 ( V_591 ) ;
if ( ! V_590 ) {
F_41 ( V_10 , L_122 ) ;
F_130 ( V_10 ) ;
goto V_575;
}
}
}
if ( V_583 || V_584 ) {
V_563 = F_258 ( sizeof( struct V_29 ) , V_576 ) ;
if ( ! V_563 ) {
F_41 ( V_10 , L_109 ) ;
goto V_575;
}
* V_563 = * V_562 ;
if ( V_583 ) {
strcpy ( V_563 -> V_594 , V_314 -> V_594 ) ;
V_563 -> V_604 = strlen ( V_314 -> V_594 ) + 1 ;
F_249 ( V_27 -> V_33 -> V_583 ) ;
V_27 -> V_33 -> V_583 = V_583 ;
F_64 ( V_10 , L_123 , V_314 -> V_594 ) ;
}
if ( V_584 ) {
strcpy ( V_563 -> V_597 , V_314 -> V_597 ) ;
V_563 -> V_605 = strlen ( V_314 -> V_597 ) + 1 ;
F_249 ( V_27 -> V_33 -> V_584 ) ;
V_27 -> V_33 -> V_584 = V_584 ;
F_64 ( V_10 , L_124 , V_314 -> V_597 ) ;
}
F_248 ( V_33 -> V_29 , V_563 ) ;
}
}
if ( V_586 ) {
F_248 ( V_10 -> V_245 -> V_273 , V_586 ) ;
F_130 ( V_10 ) ;
}
if ( V_590 ) {
V_589 = V_10 -> V_603 ;
F_248 ( V_10 -> V_603 , V_590 ) ;
}
F_117 ( & V_33 -> V_24 -> V_225 ) ;
F_250 () ;
if ( V_563 )
F_48 ( V_562 ) ;
F_48 ( V_585 ) ;
F_48 ( V_589 ) ;
return 0 ;
V_596:
if ( V_586 ) {
F_130 ( V_10 ) ;
F_48 ( V_586 ) ;
}
F_117 ( & V_33 -> V_24 -> V_225 ) ;
return - V_105 ;
V_575:
F_48 ( V_590 ) ;
if ( V_586 ) {
F_130 ( V_10 ) ;
F_48 ( V_586 ) ;
}
F_117 ( & V_33 -> V_24 -> V_225 ) ;
F_249 ( V_584 ) ;
F_249 ( V_583 ) ;
F_67 ( V_27 -> V_33 , F_68 ( V_102 , V_148 ) , V_104 ) ;
return - V_105 ;
}
static void F_260 ( struct V_9 * V_10 ,
const char * V_201 , T_3 V_42 , T_3 V_377 )
{
T_3 V_606 ;
if ( V_42 == 0 || V_377 == 0 )
return;
V_606 = ( V_42 > V_377 ) ? ( V_42 - V_377 ) : ( V_377 - V_42 ) ;
if ( V_606 > ( V_42 >> 3 ) || V_606 > ( V_377 >> 3 ) )
F_31 ( V_10 , L_125 , V_201 ,
( unsigned long long ) V_42 , ( unsigned long long ) V_377 ) ;
}
static int F_261 ( struct V_91 * V_33 , struct V_168 * V_169 )
{
struct V_26 * V_27 ;
struct V_9 * V_10 ;
struct V_607 * V_314 = V_169 -> V_93 ;
enum V_608 V_609 = V_610 ;
T_3 V_611 , V_612 , V_613 , V_614 ;
int V_615 = 0 ;
enum V_616 V_617 ;
V_27 = F_151 ( V_33 , V_169 -> V_191 ) ;
if ( ! V_27 )
return F_255 ( V_33 , V_169 ) ;
V_10 = V_27 -> V_10 ;
V_611 = F_180 ( V_314 -> V_618 ) ;
V_612 = F_180 ( V_314 -> V_619 ) ;
V_613 = F_180 ( V_314 -> V_620 ) ;
V_10 -> V_611 = V_611 ;
if ( F_127 ( V_10 ) ) {
F_25 () ;
V_614 = F_26 ( V_10 -> V_245 -> V_273 ) -> V_621 ;
F_27 () ;
F_260 ( V_10 , L_126 ,
V_611 , F_262 ( V_10 -> V_245 ) ) ;
F_260 ( V_10 , L_127 ,
V_612 , V_614 ) ;
if ( V_10 -> V_367 . V_102 == V_100 )
V_612 = F_263 ( V_614 , V_612 ) ;
if ( F_264 ( V_10 , V_10 -> V_245 , V_612 , 0 ) <
F_157 ( V_10 -> V_317 ) &&
V_10 -> V_367 . V_435 >= V_622 &&
V_10 -> V_367 . V_102 < V_553 ) {
F_41 ( V_10 , L_128 ) ;
F_67 ( V_27 -> V_33 , F_68 ( V_102 , V_148 ) , V_104 ) ;
F_130 ( V_10 ) ;
return - V_105 ;
}
if ( V_614 != V_612 ) {
struct V_273 * V_585 , * V_586 = NULL ;
V_586 = F_258 ( sizeof( struct V_273 ) , V_576 ) ;
if ( ! V_586 ) {
F_41 ( V_10 , L_115 ) ;
F_130 ( V_10 ) ;
return - V_286 ;
}
F_116 ( & V_33 -> V_24 -> V_225 ) ;
V_585 = V_10 -> V_245 -> V_273 ;
* V_586 = * V_585 ;
V_586 -> V_621 = V_612 ;
F_248 ( V_10 -> V_245 -> V_273 , V_586 ) ;
F_117 ( & V_33 -> V_24 -> V_225 ) ;
F_250 () ;
F_48 ( V_585 ) ;
F_64 ( V_10 , L_129 ,
( unsigned long ) V_614 ) ;
}
F_130 ( V_10 ) ;
}
V_10 -> V_623 = F_123 ( V_314 -> V_624 ) ;
V_617 = F_122 ( V_314 -> V_616 ) ;
if ( F_127 ( V_10 ) ) {
F_265 ( V_10 , V_10 -> V_245 ) ;
V_609 = F_266 ( V_10 , V_617 , NULL ) ;
F_130 ( V_10 ) ;
if ( V_609 == V_625 )
return - V_105 ;
F_267 ( V_10 ) ;
} else {
F_265 ( V_10 , NULL ) ;
F_268 ( V_10 , V_613 ? : V_612 ? : V_611 ) ;
}
if ( F_127 ( V_10 ) ) {
if ( V_10 -> V_245 -> V_626 != F_157 ( V_10 -> V_245 -> V_246 ) ) {
V_10 -> V_245 -> V_626 = F_157 ( V_10 -> V_245 -> V_246 ) ;
V_615 = 1 ;
}
F_130 ( V_10 ) ;
}
if ( V_10 -> V_367 . V_102 > V_100 ) {
if ( F_180 ( V_314 -> V_620 ) !=
F_157 ( V_10 -> V_317 ) || V_615 ) {
F_99 ( V_27 , 0 , V_617 ) ;
}
if ( F_269 ( V_187 , & V_10 -> V_65 ) ||
( V_609 == V_627 && V_10 -> V_367 . V_102 == V_553 ) ) {
if ( V_10 -> V_367 . V_422 >= V_423 &&
V_10 -> V_367 . V_435 >= V_423 ) {
if ( V_617 & V_628 )
F_64 ( V_10 , L_130 ) ;
else
F_270 ( V_10 ) ;
} else
F_107 ( V_629 , & V_10 -> V_65 ) ;
}
}
return 0 ;
}
static int F_271 ( struct V_91 * V_33 , struct V_168 * V_169 )
{
struct V_26 * V_27 ;
struct V_9 * V_10 ;
struct V_630 * V_314 = V_169 -> V_93 ;
T_2 * V_499 ;
int V_6 , V_631 = 0 ;
V_27 = F_151 ( V_33 , V_169 -> V_191 ) ;
if ( ! V_27 )
return F_255 ( V_33 , V_169 ) ;
V_10 = V_27 -> V_10 ;
V_499 = F_154 ( sizeof( T_2 ) * V_632 , V_211 ) ;
if ( ! V_499 ) {
F_41 ( V_10 , L_131 ) ;
return false ;
}
for ( V_6 = V_521 ; V_6 < V_632 ; V_6 ++ )
V_499 [ V_6 ] = F_180 ( V_314 -> V_497 [ V_6 ] ) ;
F_48 ( V_10 -> V_499 ) ;
V_10 -> V_499 = V_499 ;
if ( V_10 -> V_367 . V_102 < V_553 &&
V_10 -> V_367 . V_435 < V_423 &&
V_10 -> V_367 . V_515 == V_488 &&
( V_10 -> V_633 & ~ ( ( T_2 ) 1 ) ) != ( V_499 [ V_521 ] & ~ ( ( T_2 ) 1 ) ) ) {
F_41 ( V_10 , L_132 ,
( unsigned long long ) V_10 -> V_633 ) ;
F_67 ( V_27 -> V_33 , F_68 ( V_102 , V_148 ) , V_104 ) ;
return - V_105 ;
}
if ( F_127 ( V_10 ) ) {
int V_634 =
V_10 -> V_367 . V_102 == V_553 &&
V_27 -> V_33 -> V_183 >= 90 &&
V_10 -> V_245 -> V_496 . V_497 [ V_521 ] == V_526 &&
( V_499 [ V_529 ] & 8 ) ;
if ( V_634 ) {
F_64 ( V_10 , L_133 ) ;
F_244 ( V_10 , & V_635 ,
L_134 ,
V_636 ) ;
F_272 ( V_10 , V_521 , V_499 [ V_521 ] ) ;
F_272 ( V_10 , V_498 , 0 ) ;
F_273 ( F_274 ( V_10 , V_435 , V_461 , V_422 , V_461 ) ,
V_196 , NULL ) ;
F_267 ( V_10 ) ;
V_631 = 1 ;
}
F_130 ( V_10 ) ;
} else if ( V_10 -> V_367 . V_435 < V_423 &&
V_10 -> V_367 . V_515 == V_488 ) {
V_631 = F_275 ( V_10 , V_499 [ V_521 ] ) ;
}
F_116 ( V_10 -> V_182 ) ;
F_117 ( V_10 -> V_182 ) ;
if ( V_10 -> V_367 . V_102 >= V_553 && V_10 -> V_367 . V_435 < V_423 )
V_631 |= F_275 ( V_10 , V_499 [ V_521 ] ) ;
if ( V_631 )
F_276 ( V_10 , L_135 ) ;
return 0 ;
}
static union V_637 F_277 ( union V_637 V_638 )
{
union V_637 V_639 ;
static enum V_532 V_640 [] = {
[ V_100 ] = V_100 ,
[ V_553 ] = V_553 ,
[ V_641 ] = V_642 ,
[ V_642 ] = V_641 ,
[ V_148 ] = V_643 ,
[ V_450 ] = V_451 ,
[ V_537 ] = V_537 ,
} ;
V_639 . V_6 = V_638 . V_6 ;
V_639 . V_102 = V_640 [ V_638 . V_102 ] ;
V_639 . V_487 = V_638 . V_515 ;
V_639 . V_515 = V_638 . V_487 ;
V_639 . V_422 = V_638 . V_435 ;
V_639 . V_435 = V_638 . V_422 ;
V_639 . V_644 = ( V_638 . V_645 | V_638 . V_646 ) ;
return V_639 ;
}
static int F_278 ( struct V_91 * V_33 , struct V_168 * V_169 )
{
struct V_26 * V_27 ;
struct V_9 * V_10 ;
struct V_647 * V_314 = V_169 -> V_93 ;
union V_637 V_648 , V_649 ;
enum V_194 V_92 ;
V_27 = F_151 ( V_33 , V_169 -> V_191 ) ;
if ( ! V_27 )
return - V_105 ;
V_10 = V_27 -> V_10 ;
V_648 . V_6 = F_123 ( V_314 -> V_648 ) ;
V_649 . V_6 = F_123 ( V_314 -> V_649 ) ;
if ( F_65 ( V_203 , & V_27 -> V_33 -> V_65 ) &&
F_279 ( V_10 -> V_182 ) ) {
F_280 ( V_27 , V_650 ) ;
return 0 ;
}
V_648 = F_277 ( V_648 ) ;
V_649 = F_277 ( V_649 ) ;
V_92 = F_235 ( V_10 , V_196 , V_648 , V_649 ) ;
F_280 ( V_27 , V_92 ) ;
F_267 ( V_10 ) ;
return 0 ;
}
static int F_281 ( struct V_91 * V_33 , struct V_168 * V_169 )
{
struct V_647 * V_314 = V_169 -> V_93 ;
union V_637 V_648 , V_649 ;
enum V_194 V_92 ;
V_648 . V_6 = F_123 ( V_314 -> V_648 ) ;
V_649 . V_6 = F_123 ( V_314 -> V_649 ) ;
if ( F_65 ( V_203 , & V_33 -> V_65 ) &&
F_279 ( & V_33 -> V_184 ) ) {
F_282 ( V_33 , V_650 ) ;
return 0 ;
}
V_648 = F_277 ( V_648 ) ;
V_649 = F_277 ( V_649 ) ;
V_92 = F_67 ( V_33 , V_648 , V_649 , V_196 | V_651 | V_652 ) ;
F_282 ( V_33 , V_92 ) ;
return 0 ;
}
static int F_283 ( struct V_91 * V_33 , struct V_168 * V_169 )
{
struct V_26 * V_27 ;
struct V_9 * V_10 ;
struct V_653 * V_314 = V_169 -> V_93 ;
union V_637 V_654 , V_655 , V_656 ;
enum V_535 V_657 ;
enum V_658 V_659 ;
int V_92 ;
V_27 = F_151 ( V_33 , V_169 -> V_191 ) ;
if ( ! V_27 )
return F_255 ( V_33 , V_169 ) ;
V_10 = V_27 -> V_10 ;
V_656 . V_6 = F_123 ( V_314 -> V_367 ) ;
V_657 = V_656 . V_435 ;
if ( V_656 . V_435 == V_528 ) {
V_657 = V_10 -> V_499 [ V_529 ] & 4 ? V_423 : V_547 ;
F_64 ( V_10 , L_136 , F_284 ( V_657 ) ) ;
}
F_20 ( & V_10 -> V_24 -> V_25 ) ;
V_28:
V_654 = V_655 = F_285 ( V_10 ) ;
F_21 ( & V_10 -> V_24 -> V_25 ) ;
if ( V_654 . V_102 <= V_643 )
return - V_94 ;
if ( ( V_654 . V_422 == V_423 || V_654 . V_422 == V_547 ) &&
V_657 == V_461 &&
V_654 . V_102 > V_553 && V_654 . V_435 == V_461 ) {
if ( V_656 . V_102 > V_553 &&
V_656 . V_102 < V_368 )
V_657 = V_423 ;
else if ( V_654 . V_102 >= V_368 &&
V_656 . V_102 == V_553 ) {
if ( F_222 ( V_10 ) <= V_10 -> V_453 )
F_286 ( V_10 ) ;
return 0 ;
}
}
if ( V_654 . V_102 == V_451 && V_654 . V_435 == V_461 &&
V_656 . V_102 == V_553 && V_657 == V_461 ) {
F_287 ( V_10 ) ;
F_286 ( V_10 ) ;
return 0 ;
}
if ( V_654 . V_422 == V_461 && V_657 == V_423 &&
V_654 . V_102 == V_553 && V_656 . V_102 > V_368 )
V_657 = V_461 ;
if ( V_655 . V_102 == V_100 )
V_655 . V_102 = V_553 ;
if ( V_656 . V_102 == V_660 )
V_655 . V_102 = V_661 ;
if ( V_10 -> V_499 && V_656 . V_435 >= V_528 &&
F_225 ( V_10 , V_528 ) ) {
int V_662 ;
V_662 = ( V_654 . V_102 < V_553 ) ;
V_662 |= ( V_654 . V_102 == V_553 &&
( V_656 . V_435 == V_528 ||
V_654 . V_435 == V_528 ) ) ;
V_662 |= F_65 ( V_663 , & V_10 -> V_65 ) ;
V_662 |= ( V_654 . V_102 == V_553 &&
( V_656 . V_102 >= V_641 &&
V_656 . V_102 <= V_552 ) ) ;
if ( V_662 )
V_655 . V_102 = F_242 ( V_27 , V_656 . V_515 , V_657 ) ;
F_130 ( V_10 ) ;
if ( V_655 . V_102 == V_537 ) {
V_655 . V_102 = V_553 ;
if ( V_10 -> V_367 . V_435 == V_528 ) {
F_288 ( V_10 , F_68 ( V_435 , V_664 ) ) ;
} else if ( V_656 . V_435 == V_528 ) {
F_41 ( V_10 , L_137 ) ;
V_656 . V_435 = V_665 ;
V_657 = V_665 ;
} else {
if ( F_269 ( V_548 , & V_27 -> V_33 -> V_65 ) )
return - V_105 ;
F_49 ( V_10 , V_654 . V_102 == V_100 ) ;
F_67 ( V_27 -> V_33 , F_68 ( V_102 , V_148 ) , V_104 ) ;
return - V_105 ;
}
}
}
F_20 ( & V_10 -> V_24 -> V_25 ) ;
if ( V_654 . V_6 != F_285 ( V_10 ) . V_6 )
goto V_28;
F_102 ( V_663 , & V_10 -> V_65 ) ;
V_655 . V_487 = V_656 . V_515 ;
V_655 . V_422 = V_657 ;
V_655 . V_644 = ( V_656 . V_645 | V_656 . V_646 ) ;
if ( ( V_655 . V_102 == V_553 || V_655 . V_102 == V_551 ) && V_655 . V_435 == V_528 )
V_655 . V_435 = V_10 -> V_541 . V_435 ;
V_659 = V_196 + ( V_654 . V_102 < V_553 && V_655 . V_102 >= V_553 ? 0 : V_104 ) ;
if ( V_655 . V_422 == V_547 && F_289 ( V_10 ) && V_655 . V_102 == V_553 && V_654 . V_102 < V_553 &&
F_65 ( V_666 , & V_10 -> V_65 ) ) {
F_21 ( & V_10 -> V_24 -> V_25 ) ;
F_41 ( V_10 , L_138 ) ;
F_290 ( V_27 -> V_33 ) ;
F_291 ( V_10 ) ;
F_102 ( V_666 , & V_10 -> V_65 ) ;
F_67 ( V_27 -> V_33 , F_292 ( V_102 , V_667 , V_668 , 0 ) , V_104 ) ;
return - V_105 ;
}
V_92 = F_273 ( V_10 , V_655 , V_659 , NULL ) ;
V_655 = F_285 ( V_10 ) ;
F_21 ( & V_10 -> V_24 -> V_25 ) ;
if ( V_92 < V_197 ) {
F_67 ( V_27 -> V_33 , F_68 ( V_102 , V_148 ) , V_104 ) ;
return - V_105 ;
}
if ( V_654 . V_102 > V_100 ) {
if ( V_655 . V_102 > V_553 && V_656 . V_102 <= V_553 &&
V_656 . V_435 != V_528 ) {
F_100 ( V_27 ) ;
F_101 ( V_27 ) ;
}
}
F_102 ( V_222 , & V_10 -> V_65 ) ;
F_267 ( V_10 ) ;
return 0 ;
}
static int F_293 ( struct V_91 * V_33 , struct V_168 * V_169 )
{
struct V_26 * V_27 ;
struct V_9 * V_10 ;
struct V_669 * V_314 = V_169 -> V_93 ;
V_27 = F_151 ( V_33 , V_169 -> V_191 ) ;
if ( ! V_27 )
return - V_105 ;
V_10 = V_27 -> V_10 ;
F_213 ( V_10 -> V_310 ,
V_10 -> V_367 . V_102 == V_670 ||
V_10 -> V_367 . V_102 == V_661 ||
V_10 -> V_367 . V_102 < V_553 ||
V_10 -> V_367 . V_435 < V_528 ) ;
if ( F_225 ( V_10 , V_528 ) ) {
F_272 ( V_10 , V_521 , F_180 ( V_314 -> V_497 ) ) ;
F_272 ( V_10 , V_498 , 0UL ) ;
F_276 ( V_10 , L_139 ) ;
F_294 ( V_10 , V_421 ) ;
F_130 ( V_10 ) ;
} else
F_41 ( V_10 , L_140 ) ;
return 0 ;
}
static int
F_295 ( struct V_26 * V_27 , unsigned int V_60 ,
unsigned long * V_314 , struct V_671 * V_672 )
{
unsigned int V_49 = V_580 -
F_91 ( V_27 -> V_33 ) ;
unsigned int V_673 = F_73 ( T_6 , V_49 / sizeof( * V_314 ) ,
V_672 -> V_674 - V_672 -> V_675 ) ;
unsigned int V_676 = V_673 * sizeof( * V_314 ) ;
int V_73 ;
if ( V_676 != V_60 ) {
F_41 ( V_27 , L_141 , V_58 , V_676 , V_60 ) ;
return - V_105 ;
}
if ( V_676 == 0 )
return 0 ;
V_73 = F_69 ( V_27 -> V_33 , V_314 , V_676 ) ;
if ( V_73 )
return V_73 ;
F_296 ( V_27 -> V_10 , V_672 -> V_675 , V_673 , V_314 ) ;
V_672 -> V_675 += V_673 ;
V_672 -> V_677 = V_672 -> V_675 * V_678 ;
if ( V_672 -> V_677 > V_672 -> V_679 )
V_672 -> V_677 = V_672 -> V_679 ;
return 1 ;
}
static enum V_680 F_297 ( struct V_681 * V_314 )
{
return (enum V_680 ) ( V_314 -> V_682 & 0x0f ) ;
}
static int F_298 ( struct V_681 * V_314 )
{
return ( V_314 -> V_682 & 0x80 ) != 0 ;
}
static int F_299 ( struct V_681 * V_314 )
{
return ( V_314 -> V_682 >> 4 ) & 0x7 ;
}
static int
F_300 ( struct V_26 * V_27 ,
struct V_681 * V_314 ,
struct V_671 * V_672 ,
unsigned int V_5 )
{
struct V_683 V_684 ;
T_2 V_685 ;
T_2 V_686 ;
T_2 V_4 ;
unsigned long V_201 = V_672 -> V_677 ;
unsigned long V_687 ;
int V_688 = F_298 ( V_314 ) ;
int V_689 ;
int V_520 ;
F_301 ( & V_684 , V_314 -> V_690 , V_5 , F_299 ( V_314 ) ) ;
V_520 = F_302 ( & V_684 , & V_685 , 64 ) ;
if ( V_520 < 0 )
return - V_105 ;
for ( V_689 = V_520 ; V_689 > 0 ; V_201 += V_686 , V_688 = ! V_688 ) {
V_520 = F_303 ( & V_686 , V_685 ) ;
if ( V_520 <= 0 )
return - V_105 ;
if ( V_688 ) {
V_687 = V_201 + V_686 - 1 ;
if ( V_687 >= V_672 -> V_679 ) {
F_41 ( V_27 , L_142 , V_687 ) ;
return - V_105 ;
}
F_304 ( V_27 -> V_10 , V_201 , V_687 ) ;
}
if ( V_689 < V_520 ) {
F_41 ( V_27 , L_143 ,
V_689 , V_520 , V_685 ,
( unsigned int ) ( V_684 . V_691 . V_377 - V_314 -> V_690 ) ,
( unsigned int ) V_684 . V_692 ) ;
return - V_105 ;
}
if ( F_169 ( V_520 < 64 ) )
V_685 >>= V_520 ;
else
V_685 = 0 ;
V_689 -= V_520 ;
V_520 = F_302 ( & V_684 , & V_4 , 64 - V_689 ) ;
if ( V_520 < 0 )
return - V_105 ;
V_685 |= V_4 << V_689 ;
V_689 += V_520 ;
}
V_672 -> V_677 = V_201 ;
F_305 ( V_672 ) ;
return ( V_201 != V_672 -> V_679 ) ;
}
static int
F_306 ( struct V_26 * V_27 ,
struct V_681 * V_314 ,
struct V_671 * V_672 ,
unsigned int V_5 )
{
if ( F_297 ( V_314 ) == V_693 )
return F_300 ( V_27 , V_314 , V_672 , V_5 - sizeof( * V_314 ) ) ;
F_41 ( V_27 , L_144 , V_314 -> V_682 ) ;
F_67 ( V_27 -> V_33 , F_68 ( V_102 , V_667 ) , V_104 ) ;
return - V_105 ;
}
void F_307 ( struct V_9 * V_10 ,
const char * V_694 , struct V_671 * V_672 )
{
unsigned int V_167 = F_91 ( F_140 ( V_10 ) -> V_33 ) ;
unsigned int V_49 = V_580 - V_167 ;
unsigned int V_695 =
V_167 * ( F_308 ( V_672 -> V_674 , V_49 ) + 1 ) +
V_672 -> V_674 * sizeof( unsigned long ) ;
unsigned int V_696 = V_672 -> V_697 [ 0 ] + V_672 -> V_697 [ 1 ] ;
unsigned int V_698 ;
if ( V_696 == 0 )
return;
if ( V_696 >= V_695 )
return;
V_698 = ( V_696 > V_40 / 1000 ) ? ( V_696 / ( V_695 / 1000 ) )
: ( 1000 * V_696 / V_695 ) ;
if ( V_698 > 1000 )
V_698 = 1000 ;
V_698 = 1000 - V_698 ;
F_64 ( V_10 , L_145
L_146 ,
V_694 ,
V_672 -> V_697 [ 1 ] , V_672 -> V_699 [ 1 ] ,
V_672 -> V_697 [ 0 ] , V_672 -> V_699 [ 0 ] ,
V_696 , V_698 / 10 , V_698 % 10 ) ;
}
static int F_309 ( struct V_91 * V_33 , struct V_168 * V_169 )
{
struct V_26 * V_27 ;
struct V_9 * V_10 ;
struct V_671 V_672 ;
int V_73 ;
V_27 = F_151 ( V_33 , V_169 -> V_191 ) ;
if ( ! V_27 )
return - V_105 ;
V_10 = V_27 -> V_10 ;
F_310 ( V_10 , L_147 , V_550 ) ;
V_672 = (struct V_671 ) {
. V_679 = F_230 ( V_10 ) ,
. V_674 = F_311 ( V_10 ) ,
} ;
for(; ; ) {
if ( V_169 -> V_166 == V_700 )
V_73 = F_295 ( V_27 , V_169 -> V_60 , V_169 -> V_93 , & V_672 ) ;
else if ( V_169 -> V_166 == V_701 ) {
struct V_681 * V_314 = V_169 -> V_93 ;
if ( V_169 -> V_60 > V_580 - F_91 ( V_33 ) ) {
F_41 ( V_10 , L_148 ) ;
V_73 = - V_105 ;
goto V_101;
}
if ( V_169 -> V_60 <= sizeof( * V_314 ) ) {
F_41 ( V_10 , L_149 , V_169 -> V_60 ) ;
V_73 = - V_105 ;
goto V_101;
}
V_73 = F_69 ( V_27 -> V_33 , V_314 , V_169 -> V_60 ) ;
if ( V_73 )
goto V_101;
V_73 = F_306 ( V_27 , V_314 , & V_672 , V_169 -> V_60 ) ;
} else {
F_31 ( V_10 , L_150 , V_169 -> V_166 ) ;
V_73 = - V_105 ;
goto V_101;
}
V_672 . V_699 [ V_169 -> V_166 == V_700 ] ++ ;
V_672 . V_697 [ V_169 -> V_166 == V_700 ] += F_91 ( V_33 ) + V_169 -> V_60 ;
if ( V_73 <= 0 ) {
if ( V_73 < 0 )
goto V_101;
break;
}
V_73 = F_125 ( V_27 -> V_33 , V_169 ) ;
if ( V_73 )
goto V_101;
}
F_307 ( V_10 , L_151 , & V_672 ) ;
if ( V_10 -> V_367 . V_102 == V_552 ) {
enum V_194 V_92 ;
V_73 = F_312 ( V_10 ) ;
if ( V_73 )
goto V_101;
V_92 = F_313 ( V_10 , F_68 ( V_102 , V_670 ) , V_196 ) ;
F_49 ( V_10 , V_92 == V_197 ) ;
} else if ( V_10 -> V_367 . V_102 != V_551 ) {
F_64 ( V_10 , L_152 ,
F_243 ( V_10 -> V_367 . V_102 ) ) ;
}
V_73 = 0 ;
V_101:
F_314 ( V_10 ) ;
if ( ! V_73 && V_10 -> V_367 . V_102 == V_551 )
F_294 ( V_10 , V_368 ) ;
return V_73 ;
}
static int F_315 ( struct V_91 * V_33 , struct V_168 * V_169 )
{
F_31 ( V_33 , L_153 ,
V_169 -> V_166 , V_169 -> V_60 ) ;
return F_254 ( V_33 , V_169 ) ;
}
static int F_316 ( struct V_91 * V_33 , struct V_168 * V_169 )
{
F_317 ( V_33 -> V_93 . V_79 ) ;
return 0 ;
}
static int F_318 ( struct V_91 * V_33 , struct V_168 * V_169 )
{
struct V_26 * V_27 ;
struct V_9 * V_10 ;
struct V_702 * V_314 = V_169 -> V_93 ;
V_27 = F_151 ( V_33 , V_169 -> V_191 ) ;
if ( ! V_27 )
return - V_105 ;
V_10 = V_27 -> V_10 ;
switch ( V_10 -> V_367 . V_102 ) {
case V_670 :
case V_552 :
case V_661 :
break;
default:
F_41 ( V_10 , L_154 ,
F_243 ( V_10 -> V_367 . V_102 ) ) ;
}
F_214 ( V_10 , F_180 ( V_314 -> V_48 ) , F_123 ( V_314 -> V_460 ) ) ;
return 0 ;
}
static void F_319 ( struct V_91 * V_33 )
{
struct V_168 V_169 ;
T_6 V_703 ;
int V_73 ;
while ( F_110 ( & V_33 -> V_208 ) == V_704 ) {
struct V_705 * V_166 ;
F_320 ( & V_33 -> V_208 ) ;
F_231 ( V_33 , F_125 ) ;
if ( F_125 ( V_33 , & V_169 ) )
goto V_706;
V_166 = & V_707 [ V_169 . V_166 ] ;
if ( F_181 ( V_169 . V_166 >= F_321 ( V_707 ) || ! V_166 -> V_708 ) ) {
F_41 ( V_33 , L_155 ,
F_256 ( V_169 . V_166 ) , V_169 . V_166 ) ;
goto V_706;
}
V_703 = V_166 -> V_709 ;
if ( V_169 . V_60 > V_703 && ! V_166 -> V_710 ) {
F_41 ( V_33 , L_156 ,
F_256 ( V_169 . V_166 ) , V_169 . V_60 ) ;
goto V_706;
}
if ( V_703 ) {
F_231 ( V_33 , F_70 ) ;
V_73 = F_70 ( V_33 , V_169 . V_93 , V_703 ) ;
if ( V_73 )
goto V_706;
V_169 . V_60 -= V_703 ;
}
F_231 ( V_33 , V_166 -> V_708 ) ;
V_73 = V_166 -> V_708 ( V_33 , & V_169 ) ;
if ( V_73 ) {
F_41 ( V_33 , L_157 ,
F_256 ( V_169 . V_166 ) , V_73 , V_169 . V_60 ) ;
goto V_706;
}
}
return;
V_706:
F_67 ( V_33 , F_68 ( V_102 , V_667 ) , V_104 ) ;
}
static void F_322 ( struct V_91 * V_33 )
{
struct V_26 * V_27 ;
enum V_532 V_711 ;
int V_191 ;
if ( V_33 -> V_99 == V_712 )
return;
F_67 ( V_33 , F_68 ( V_102 , V_713 ) , V_104 ) ;
F_323 ( & V_33 -> V_224 ) ;
F_324 ( V_33 ) ;
F_25 () ;
F_115 (&connection->peer_devices, peer_device, vnr) {
struct V_9 * V_10 = V_27 -> V_10 ;
F_118 ( & V_10 -> V_221 ) ;
F_27 () ;
F_325 ( V_27 ) ;
F_119 ( & V_10 -> V_221 , V_223 ) ;
F_25 () ;
}
F_27 () ;
if ( ! F_58 ( & V_33 -> V_264 -> V_21 ) )
F_41 ( V_33 , L_158 ) ;
F_97 ( & V_33 -> V_264 -> V_253 , 0 ) ;
V_33 -> V_714 . V_715 = false ;
F_64 ( V_33 , L_159 ) ;
if ( F_326 ( V_33 ) == V_488 && F_327 ( V_33 ) >= V_716 )
F_328 ( V_33 ) ;
F_20 ( & V_33 -> V_24 -> V_25 ) ;
V_711 = V_33 -> V_99 ;
if ( V_711 >= V_717 )
F_208 ( V_33 , F_68 ( V_102 , V_717 ) , V_196 ) ;
F_21 ( & V_33 -> V_24 -> V_25 ) ;
if ( V_711 == V_148 )
F_67 ( V_33 , F_68 ( V_102 , V_712 ) , V_196 | V_104 ) ;
}
static int F_325 ( struct V_26 * V_27 )
{
struct V_9 * V_10 = V_27 -> V_10 ;
unsigned int V_6 ;
F_20 ( & V_10 -> V_24 -> V_25 ) ;
F_57 ( V_10 , & V_10 -> V_289 ) ;
F_57 ( V_10 , & V_10 -> V_347 ) ;
F_57 ( V_10 , & V_10 -> V_486 ) ;
F_21 ( & V_10 -> V_24 -> V_25 ) ;
F_329 ( V_10 ) ;
V_10 -> V_484 = 0 ;
V_10 -> V_453 = 0 ;
F_97 ( & V_10 -> V_718 , 0 ) ;
F_37 ( & V_10 -> V_310 ) ;
F_330 ( & V_10 -> V_719 ) ;
F_331 ( ( unsigned long ) V_10 ) ;
F_332 ( & V_27 -> V_33 -> V_720 ) ;
F_55 ( V_10 ) ;
F_332 ( & V_27 -> V_33 -> V_720 ) ;
F_329 ( V_10 ) ;
F_48 ( V_10 -> V_499 ) ;
V_10 -> V_499 = NULL ;
if ( ! F_289 ( V_10 ) )
F_290 ( V_27 -> V_33 ) ;
F_267 ( V_10 ) ;
F_213 ( V_10 -> V_310 , ! F_65 ( V_721 , & V_10 -> V_65 ) ) ;
V_6 = F_53 ( V_10 , & V_10 -> V_72 ) ;
if ( V_6 )
F_64 ( V_10 , L_160 , V_6 ) ;
V_6 = F_28 ( & V_10 -> V_43 ) ;
if ( V_6 )
F_64 ( V_10 , L_161 , V_6 ) ;
V_6 = F_28 ( & V_10 -> V_35 ) ;
if ( V_6 )
F_64 ( V_10 , L_162 , V_6 ) ;
F_49 ( V_10 , F_58 ( & V_10 -> V_486 ) ) ;
F_49 ( V_10 , F_58 ( & V_10 -> V_289 ) ) ;
F_49 ( V_10 , F_58 ( & V_10 -> V_347 ) ) ;
F_49 ( V_10 , F_58 ( & V_10 -> V_74 ) ) ;
return 0 ;
}
static int F_333 ( struct V_91 * V_33 )
{
struct V_164 * V_80 ;
struct V_722 * V_314 ;
V_80 = & V_33 -> V_93 ;
V_314 = F_88 ( V_33 , V_80 ) ;
if ( ! V_314 )
return - V_105 ;
memset ( V_314 , 0 , sizeof( * V_314 ) ) ;
V_314 -> V_723 = F_121 ( V_724 ) ;
V_314 -> V_725 = F_121 ( V_726 ) ;
V_314 -> V_727 = F_121 ( V_728 ) ;
return F_89 ( V_33 , V_80 , V_729 , sizeof( * V_314 ) , NULL , 0 ) ;
}
static int F_112 ( struct V_91 * V_33 )
{
struct V_722 * V_314 ;
const int F_51 = sizeof( struct V_722 ) ;
struct V_168 V_169 ;
int V_73 ;
V_73 = F_333 ( V_33 ) ;
if ( V_73 )
return 0 ;
V_73 = F_125 ( V_33 , & V_169 ) ;
if ( V_73 )
return 0 ;
if ( V_169 . V_166 != V_729 ) {
F_41 ( V_33 , L_163 ,
F_256 ( V_169 . V_166 ) , V_169 . V_166 ) ;
return - 1 ;
}
if ( V_169 . V_60 != F_51 ) {
F_41 ( V_33 , L_164 ,
F_51 , V_169 . V_60 ) ;
return - 1 ;
}
V_314 = V_169 . V_93 ;
V_73 = F_70 ( V_33 , V_314 , F_51 ) ;
if ( V_73 )
return 0 ;
V_314 -> V_723 = F_123 ( V_314 -> V_723 ) ;
V_314 -> V_725 = F_123 ( V_314 -> V_725 ) ;
if ( V_314 -> V_725 == 0 )
V_314 -> V_725 = V_314 -> V_723 ;
if ( V_726 < V_314 -> V_723 ||
V_724 > V_314 -> V_725 )
goto V_730;
V_33 -> V_183 = F_73 ( int , V_726 , V_314 -> V_725 ) ;
V_33 -> V_731 = V_728 & F_123 ( V_314 -> V_727 ) ;
F_64 ( V_33 , L_165
L_166 , V_33 -> V_183 ) ;
F_64 ( V_33 , L_167 ,
V_33 -> V_731 & V_732 ? L_168 : L_169 ) ;
return 1 ;
V_730:
F_41 ( V_33 , L_170
L_171 ,
V_724 , V_726 ,
V_314 -> V_723 , V_314 -> V_725 ) ;
return - 1 ;
}
static int F_113 ( struct V_91 * V_33 )
{
F_41 ( V_33 , L_172 ) ;
F_41 ( V_33 , L_173 ) ;
return - 1 ;
}
static int F_113 ( struct V_91 * V_33 )
{
struct V_164 * V_80 ;
char V_733 [ V_734 ] ;
struct V_735 V_736 ;
char * V_737 = NULL ;
char * V_738 = NULL ;
char * V_739 = NULL ;
unsigned int V_740 ;
char V_741 [ V_565 ] ;
unsigned int V_742 ;
struct V_743 V_744 ;
struct V_168 V_169 ;
struct V_29 * V_30 ;
int V_73 , V_92 ;
F_25 () ;
V_30 = F_26 ( V_33 -> V_29 ) ;
V_740 = strlen ( V_30 -> V_745 ) ;
memcpy ( V_741 , V_30 -> V_745 , V_740 ) ;
F_27 () ;
V_744 . V_579 = V_33 -> V_217 ;
V_744 . V_65 = 0 ;
V_92 = F_334 ( V_33 -> V_217 , ( V_746 * ) V_741 , V_740 ) ;
if ( V_92 ) {
F_41 ( V_33 , L_174 , V_92 ) ;
V_92 = - 1 ;
goto V_59;
}
F_335 ( V_733 , V_734 ) ;
V_80 = & V_33 -> V_93 ;
if ( ! F_88 ( V_33 , V_80 ) ) {
V_92 = 0 ;
goto V_59;
}
V_92 = ! F_89 ( V_33 , V_80 , V_747 , 0 ,
V_733 , V_734 ) ;
if ( ! V_92 )
goto V_59;
V_73 = F_125 ( V_33 , & V_169 ) ;
if ( V_73 ) {
V_92 = 0 ;
goto V_59;
}
if ( V_169 . V_166 != V_747 ) {
F_41 ( V_33 , L_175 ,
F_256 ( V_169 . V_166 ) , V_169 . V_166 ) ;
V_92 = 0 ;
goto V_59;
}
if ( V_169 . V_60 > V_734 * 2 ) {
F_41 ( V_33 , L_176 ) ;
V_92 = - 1 ;
goto V_59;
}
if ( V_169 . V_60 < V_734 ) {
F_41 ( V_33 , L_177 ) ;
V_92 = - 1 ;
goto V_59;
}
V_739 = F_154 ( V_169 . V_60 , V_211 ) ;
if ( V_739 == NULL ) {
F_41 ( V_33 , L_178 ) ;
V_92 = - 1 ;
goto V_59;
}
V_73 = F_70 ( V_33 , V_739 , V_169 . V_60 ) ;
if ( V_73 ) {
V_92 = 0 ;
goto V_59;
}
if ( ! memcmp ( V_733 , V_739 , V_734 ) ) {
F_41 ( V_33 , L_179 ) ;
V_92 = - 1 ;
goto V_59;
}
V_742 = F_158 ( V_33 -> V_217 ) ;
V_737 = F_154 ( V_742 , V_211 ) ;
if ( V_737 == NULL ) {
F_41 ( V_33 , L_180 ) ;
V_92 = - 1 ;
goto V_59;
}
F_336 ( & V_736 , 1 ) ;
F_337 ( & V_736 , V_739 , V_169 . V_60 ) ;
V_92 = F_338 ( & V_744 , & V_736 , V_736 . V_234 , V_737 ) ;
if ( V_92 ) {
F_41 ( V_33 , L_181 , V_92 ) ;
V_92 = - 1 ;
goto V_59;
}
if ( ! F_88 ( V_33 , V_80 ) ) {
V_92 = 0 ;
goto V_59;
}
V_92 = ! F_89 ( V_33 , V_80 , V_748 , 0 ,
V_737 , V_742 ) ;
if ( ! V_92 )
goto V_59;
V_73 = F_125 ( V_33 , & V_169 ) ;
if ( V_73 ) {
V_92 = 0 ;
goto V_59;
}
if ( V_169 . V_166 != V_748 ) {
F_41 ( V_33 , L_182 ,
F_256 ( V_169 . V_166 ) , V_169 . V_166 ) ;
V_92 = 0 ;
goto V_59;
}
if ( V_169 . V_60 != V_742 ) {
F_41 ( V_33 , L_183 ) ;
V_92 = 0 ;
goto V_59;
}
V_73 = F_70 ( V_33 , V_737 , V_742 ) ;
if ( V_73 ) {
V_92 = 0 ;
goto V_59;
}
V_738 = F_154 ( V_742 , V_211 ) ;
if ( V_738 == NULL ) {
F_41 ( V_33 , L_184 ) ;
V_92 = - 1 ;
goto V_59;
}
F_337 ( & V_736 , V_733 , V_734 ) ;
V_92 = F_338 ( & V_744 , & V_736 , V_736 . V_234 , V_738 ) ;
if ( V_92 ) {
F_41 ( V_33 , L_181 , V_92 ) ;
V_92 = - 1 ;
goto V_59;
}
V_92 = ! memcmp ( V_737 , V_738 , V_742 ) ;
if ( V_92 )
F_64 ( V_33 , L_185 ,
V_742 ) ;
else
V_92 = - 1 ;
V_59:
F_48 ( V_739 ) ;
F_48 ( V_737 ) ;
F_48 ( V_738 ) ;
return V_92 ;
}
int F_339 ( struct V_749 * V_750 )
{
struct V_91 * V_33 = V_750 -> V_33 ;
int V_192 ;
F_64 ( V_33 , L_186 ) ;
do {
V_192 = F_104 ( V_33 ) ;
if ( V_192 == 0 ) {
F_322 ( V_33 ) ;
F_95 ( V_39 ) ;
}
if ( V_192 == - 1 ) {
F_31 ( V_33 , L_187 ) ;
F_67 ( V_33 , F_68 ( V_102 , V_148 ) , V_104 ) ;
}
} while ( V_192 == 0 );
if ( V_192 > 0 )
F_319 ( V_33 ) ;
F_322 ( V_33 ) ;
F_64 ( V_33 , L_188 ) ;
return 0 ;
}
static int F_340 ( struct V_91 * V_33 , struct V_168 * V_169 )
{
struct V_751 * V_314 = V_169 -> V_93 ;
int V_752 = F_123 ( V_314 -> V_752 ) ;
if ( V_752 >= V_197 ) {
F_107 ( V_753 , & V_33 -> V_65 ) ;
} else {
F_107 ( V_754 , & V_33 -> V_65 ) ;
F_41 ( V_33 , L_189 ,
F_341 ( V_752 ) , V_752 ) ;
}
F_37 ( & V_33 -> V_98 ) ;
return 0 ;
}
static int F_342 ( struct V_91 * V_33 , struct V_168 * V_169 )
{
struct V_26 * V_27 ;
struct V_9 * V_10 ;
struct V_751 * V_314 = V_169 -> V_93 ;
int V_752 = F_123 ( V_314 -> V_752 ) ;
V_27 = F_151 ( V_33 , V_169 -> V_191 ) ;
if ( ! V_27 )
return - V_105 ;
V_10 = V_27 -> V_10 ;
if ( F_65 ( V_755 , & V_33 -> V_65 ) ) {
F_49 ( V_10 , V_33 -> V_183 < 100 ) ;
return F_340 ( V_33 , V_169 ) ;
}
if ( V_752 >= V_197 ) {
F_107 ( V_756 , & V_10 -> V_65 ) ;
} else {
F_107 ( V_757 , & V_10 -> V_65 ) ;
F_41 ( V_10 , L_189 ,
F_341 ( V_752 ) , V_752 ) ;
}
F_37 ( & V_10 -> V_758 ) ;
return 0 ;
}
static int F_343 ( struct V_91 * V_33 , struct V_168 * V_169 )
{
return F_344 ( V_33 ) ;
}
static int F_345 ( struct V_91 * V_33 , struct V_168 * V_169 )
{
V_33 -> V_200 . V_79 -> V_108 -> V_135 = V_33 -> V_29 -> V_215 * V_39 ;
if ( ! F_346 ( V_759 , & V_33 -> V_65 ) )
F_37 ( & V_33 -> V_98 ) ;
return 0 ;
}
static int F_347 ( struct V_91 * V_33 , struct V_168 * V_169 )
{
struct V_26 * V_27 ;
struct V_9 * V_10 ;
struct V_760 * V_314 = V_169 -> V_93 ;
T_3 V_48 = F_180 ( V_314 -> V_48 ) ;
int V_460 = F_123 ( V_314 -> V_460 ) ;
V_27 = F_151 ( V_33 , V_169 -> V_191 ) ;
if ( ! V_27 )
return - V_105 ;
V_10 = V_27 -> V_10 ;
F_49 ( V_10 , V_27 -> V_33 -> V_183 >= 89 ) ;
F_195 ( V_27 , F_123 ( V_314 -> V_408 ) ) ;
if ( F_127 ( V_10 ) ) {
F_348 ( V_10 , V_48 ) ;
F_170 ( V_10 , V_48 , V_460 ) ;
V_10 -> V_761 += ( V_460 >> V_762 ) ;
F_130 ( V_10 ) ;
}
F_175 ( V_10 ) ;
F_34 ( V_460 >> 9 , & V_10 -> V_359 ) ;
return 0 ;
}
static int
F_349 ( struct V_9 * V_10 , T_2 V_47 , T_3 V_48 ,
struct V_351 * V_352 , const char * V_354 ,
enum V_763 V_114 , bool V_353 )
{
struct V_331 * V_332 ;
struct V_399 V_400 ;
F_20 ( & V_10 -> V_24 -> V_25 ) ;
V_332 = F_177 ( V_10 , V_352 , V_47 , V_48 , V_353 , V_354 ) ;
if ( F_181 ( ! V_332 ) ) {
F_21 ( & V_10 -> V_24 -> V_25 ) ;
return - V_105 ;
}
F_188 ( V_332 , V_114 , & V_400 ) ;
F_21 ( & V_10 -> V_24 -> V_25 ) ;
if ( V_400 . V_283 )
F_202 ( V_10 , & V_400 ) ;
return 0 ;
}
static int F_350 ( struct V_91 * V_33 , struct V_168 * V_169 )
{
struct V_26 * V_27 ;
struct V_9 * V_10 ;
struct V_760 * V_314 = V_169 -> V_93 ;
T_3 V_48 = F_180 ( V_314 -> V_48 ) ;
int V_460 = F_123 ( V_314 -> V_460 ) ;
enum V_763 V_114 ;
V_27 = F_151 ( V_33 , V_169 -> V_191 ) ;
if ( ! V_27 )
return - V_105 ;
V_10 = V_27 -> V_10 ;
F_195 ( V_27 , F_123 ( V_314 -> V_408 ) ) ;
if ( V_314 -> V_64 == V_346 ) {
F_170 ( V_10 , V_48 , V_460 ) ;
F_175 ( V_10 ) ;
return 0 ;
}
switch ( V_169 -> V_166 ) {
case V_344 :
V_114 = V_764 ;
break;
case V_371 :
V_114 = V_765 ;
break;
case V_419 :
V_114 = V_766 ;
break;
case V_375 :
V_114 = V_363 ;
break;
case V_376 :
V_114 = V_767 ;
break;
default:
F_228 () ;
}
return F_349 ( V_10 , V_314 -> V_64 , V_48 ,
& V_10 -> V_308 , V_58 ,
V_114 , false ) ;
}
static int F_351 ( struct V_91 * V_33 , struct V_168 * V_169 )
{
struct V_26 * V_27 ;
struct V_9 * V_10 ;
struct V_760 * V_314 = V_169 -> V_93 ;
T_3 V_48 = F_180 ( V_314 -> V_48 ) ;
int V_60 = F_123 ( V_314 -> V_460 ) ;
int V_73 ;
V_27 = F_151 ( V_33 , V_169 -> V_191 ) ;
if ( ! V_27 )
return - V_105 ;
V_10 = V_27 -> V_10 ;
F_195 ( V_27 , F_123 ( V_314 -> V_408 ) ) ;
if ( V_314 -> V_64 == V_346 ) {
F_175 ( V_10 ) ;
F_172 ( V_10 , V_48 , V_60 ) ;
return 0 ;
}
V_73 = F_349 ( V_10 , V_314 -> V_64 , V_48 ,
& V_10 -> V_308 , V_58 ,
V_401 , true ) ;
if ( V_73 ) {
F_214 ( V_10 , V_48 , V_60 ) ;
}
return 0 ;
}
static int F_352 ( struct V_91 * V_33 , struct V_168 * V_169 )
{
struct V_26 * V_27 ;
struct V_9 * V_10 ;
struct V_760 * V_314 = V_169 -> V_93 ;
T_3 V_48 = F_180 ( V_314 -> V_48 ) ;
V_27 = F_151 ( V_33 , V_169 -> V_191 ) ;
if ( ! V_27 )
return - V_105 ;
V_10 = V_27 -> V_10 ;
F_195 ( V_27 , F_123 ( V_314 -> V_408 ) ) ;
F_41 ( V_10 , L_190 ,
( unsigned long long ) V_48 , F_123 ( V_314 -> V_460 ) ) ;
return F_349 ( V_10 , V_314 -> V_64 , V_48 ,
& V_10 -> V_356 , V_58 ,
V_401 , false ) ;
}
static int F_353 ( struct V_91 * V_33 , struct V_168 * V_169 )
{
struct V_26 * V_27 ;
struct V_9 * V_10 ;
T_3 V_48 ;
int V_60 ;
struct V_760 * V_314 = V_169 -> V_93 ;
V_27 = F_151 ( V_33 , V_169 -> V_191 ) ;
if ( ! V_27 )
return - V_105 ;
V_10 = V_27 -> V_10 ;
V_48 = F_180 ( V_314 -> V_48 ) ;
V_60 = F_123 ( V_314 -> V_460 ) ;
F_195 ( V_27 , F_123 ( V_314 -> V_408 ) ) ;
F_175 ( V_10 ) ;
if ( F_225 ( V_10 , V_664 ) ) {
F_348 ( V_10 , V_48 ) ;
switch ( V_169 -> V_166 ) {
case V_467 :
F_172 ( V_10 , V_48 , V_60 ) ;
case V_768 :
break;
default:
F_228 () ;
}
F_130 ( V_10 ) ;
}
return 0 ;
}
static int F_354 ( struct V_91 * V_33 , struct V_168 * V_169 )
{
struct V_769 * V_314 = V_169 -> V_93 ;
struct V_26 * V_27 ;
int V_191 ;
F_355 ( V_33 , V_314 -> V_315 , F_123 ( V_314 -> V_770 ) ) ;
F_25 () ;
F_115 (&connection->peer_devices, peer_device, vnr) {
struct V_9 * V_10 = V_27 -> V_10 ;
if ( V_10 -> V_367 . V_102 == V_660 &&
F_28 ( & V_10 -> V_188 ) == 0 &&
! F_346 ( V_771 , & V_10 -> V_65 ) ) {
V_10 -> V_772 . V_773 = V_62 + V_39 ;
F_356 ( & V_10 -> V_772 ) ;
}
}
F_27 () ;
return 0 ;
}
static int F_357 ( struct V_91 * V_33 , struct V_168 * V_169 )
{
struct V_26 * V_27 ;
struct V_9 * V_10 ;
struct V_760 * V_314 = V_169 -> V_93 ;
struct V_774 * V_775 ;
T_3 V_48 ;
int V_60 ;
V_27 = F_151 ( V_33 , V_169 -> V_191 ) ;
if ( ! V_27 )
return - V_105 ;
V_10 = V_27 -> V_10 ;
V_48 = F_180 ( V_314 -> V_48 ) ;
V_60 = F_123 ( V_314 -> V_460 ) ;
F_195 ( V_27 , F_123 ( V_314 -> V_408 ) ) ;
if ( F_180 ( V_314 -> V_64 ) == V_776 )
F_358 ( V_10 , V_48 , V_60 ) ;
else
F_287 ( V_10 ) ;
if ( ! F_127 ( V_10 ) )
return 0 ;
F_348 ( V_10 , V_48 ) ;
F_175 ( V_10 ) ;
-- V_10 -> V_452 ;
if ( ( V_10 -> V_452 & 0x200 ) == 0x200 )
F_359 ( V_10 , V_10 -> V_452 ) ;
if ( V_10 -> V_452 == 0 ) {
V_775 = F_154 ( sizeof( * V_775 ) , V_211 ) ;
if ( V_775 ) {
V_775 -> V_20 . V_76 = V_777 ;
V_775 -> V_10 = V_10 ;
F_360 ( & V_27 -> V_33 -> V_720 , & V_775 -> V_20 ) ;
} else {
F_41 ( V_10 , L_191 ) ;
F_287 ( V_10 ) ;
F_286 ( V_10 ) ;
}
}
F_130 ( V_10 ) ;
return 0 ;
}
static int F_361 ( struct V_91 * V_33 , struct V_168 * V_169 )
{
return 0 ;
}
static int F_362 ( struct V_91 * V_33 )
{
struct V_26 * V_27 ;
int V_191 , V_778 = 0 ;
do {
F_102 ( V_779 , & V_33 -> V_65 ) ;
F_108 ( V_38 ) ;
F_25 () ;
F_115 (&connection->peer_devices, peer_device, vnr) {
struct V_9 * V_10 = V_27 -> V_10 ;
F_118 ( & V_10 -> V_221 ) ;
F_27 () ;
if ( F_55 ( V_10 ) ) {
F_119 ( & V_10 -> V_221 , V_223 ) ;
return 1 ;
}
F_119 ( & V_10 -> V_221 , V_223 ) ;
F_25 () ;
}
F_107 ( V_779 , & V_33 -> V_65 ) ;
F_20 ( & V_33 -> V_24 -> V_25 ) ;
F_115 (&connection->peer_devices, peer_device, vnr) {
struct V_9 * V_10 = V_27 -> V_10 ;
V_778 = ! F_58 ( & V_10 -> V_74 ) ;
if ( V_778 )
break;
}
F_21 ( & V_33 -> V_24 -> V_25 ) ;
F_27 () ;
} while ( V_778 );
return 0 ;
}
int F_363 ( struct V_749 * V_750 )
{
struct V_91 * V_33 = V_750 -> V_33 ;
struct V_780 * V_166 = NULL ;
struct V_168 V_169 ;
int V_92 ;
void * V_81 = V_33 -> V_200 . V_170 ;
int V_781 = 0 ;
unsigned int V_167 = F_91 ( V_33 ) ;
int F_51 = V_167 ;
bool V_782 = false ;
struct V_29 * V_30 ;
int V_97 , V_783 , V_215 ;
struct V_784 V_785 = { . V_786 = 2 } ;
V_92 = F_364 ( V_38 , V_787 , & V_785 ) ;
if ( V_92 < 0 )
F_41 ( V_33 , L_192 , V_92 ) ;
while ( F_110 ( V_750 ) == V_704 ) {
F_320 ( V_750 ) ;
F_25 () ;
V_30 = F_26 ( V_33 -> V_29 ) ;
V_97 = V_30 -> V_97 ;
V_783 = V_30 -> V_783 ;
V_215 = V_30 -> V_215 ;
F_27 () ;
if ( F_269 ( V_788 , & V_33 -> V_65 ) ) {
if ( F_365 ( V_33 ) ) {
F_41 ( V_33 , L_193 ) ;
goto V_596;
}
V_33 -> V_200 . V_79 -> V_108 -> V_135 = V_97 * V_39 / 10 ;
V_782 = true ;
}
if ( V_783 )
F_366 ( V_33 -> V_200 . V_79 ) ;
if ( F_362 ( V_33 ) ) {
F_41 ( V_33 , L_194 ) ;
goto V_596;
}
if ( V_783 )
F_367 ( V_33 -> V_200 . V_79 ) ;
if ( F_30 ( V_38 ) )
continue;
V_92 = F_61 ( V_33 -> V_200 . V_79 , V_81 , F_51 - V_781 , 0 ) ;
F_102 ( V_779 , & V_33 -> V_65 ) ;
F_108 ( V_38 ) ;
V_789:
if ( F_169 ( V_92 > 0 ) ) {
V_781 += V_92 ;
V_81 += V_92 ;
} else if ( V_92 == 0 ) {
if ( F_65 ( V_96 , & V_33 -> V_65 ) ) {
long V_23 ;
F_25 () ;
V_23 = F_26 ( V_33 -> V_29 ) -> V_97 * V_39 / 10 ;
F_27 () ;
V_23 = F_66 ( V_33 -> V_98 ,
V_33 -> V_99 < V_100 ,
V_23 ) ;
if ( V_23 )
break;
}
F_41 ( V_33 , L_195 ) ;
goto V_596;
} else if ( V_92 == - V_141 ) {
if ( F_368 ( V_33 -> V_216 ,
V_62 - V_33 -> V_200 . V_79 -> V_108 -> V_135 ) )
continue;
if ( V_782 ) {
F_41 ( V_33 , L_196 ) ;
goto V_596;
}
F_107 ( V_788 , & V_33 -> V_65 ) ;
continue;
} else if ( V_92 == - V_143 ) {
continue;
} else {
F_41 ( V_33 , L_7 , V_92 ) ;
goto V_596;
}
if ( V_781 == F_51 && V_166 == NULL ) {
if ( F_92 ( V_33 , V_33 -> V_200 . V_170 , & V_169 ) )
goto V_596;
V_166 = & V_790 [ V_169 . V_166 ] ;
if ( V_169 . V_166 >= F_321 ( V_790 ) || ! V_166 -> V_708 ) {
F_41 ( V_33 , L_197 ,
F_256 ( V_169 . V_166 ) , V_169 . V_166 ) ;
goto V_575;
}
F_51 = V_167 + V_166 -> V_709 ;
if ( V_169 . V_60 != F_51 - V_167 ) {
F_41 ( V_33 , L_198 ,
V_169 . V_166 , V_169 . V_60 ) ;
goto V_596;
}
}
if ( V_781 == F_51 ) {
bool V_73 ;
V_73 = V_166 -> V_708 ( V_33 , & V_169 ) ;
if ( V_73 ) {
F_41 ( V_33 , L_199 , V_166 -> V_708 ) ;
goto V_596;
}
V_33 -> V_216 = V_62 ;
if ( V_166 == & V_790 [ V_791 ] ) {
V_33 -> V_200 . V_79 -> V_108 -> V_135 = V_215 * V_39 ;
V_782 = false ;
}
V_81 = V_33 -> V_200 . V_170 ;
V_781 = 0 ;
F_51 = V_167 ;
V_166 = NULL ;
}
if ( F_65 ( V_788 , & V_33 -> V_65 ) )
continue;
V_92 = F_61 ( V_33 -> V_200 . V_79 , V_81 , F_51 - V_781 , V_173 ) ;
if ( V_92 > 0 )
goto V_789;
}
if ( 0 ) {
V_596:
F_67 ( V_33 , F_68 ( V_102 , V_713 ) , V_104 ) ;
F_369 ( V_33 ) ;
}
if ( 0 ) {
V_575:
F_67 ( V_33 , F_68 ( V_102 , V_148 ) , V_104 ) ;
}
F_102 ( V_779 , & V_33 -> V_65 ) ;
F_64 ( V_33 , L_200 ) ;
return 0 ;
}
