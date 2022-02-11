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
static void F_23 ( struct V_26 * V_27 )
{
struct V_28 * V_29 ;
int V_30 ;
F_24 () ;
F_25 (&connection->peer_devices, peer_device, vnr) {
struct V_9 * V_10 = V_29 -> V_10 ;
if ( ! F_26 ( & V_10 -> V_31 ) )
continue;
F_27 ( & V_10 -> V_32 ) ;
F_28 () ;
F_18 ( V_10 ) ;
F_29 ( & V_10 -> V_32 , V_33 ) ;
F_24 () ;
}
F_28 () ;
}
struct V_1 * F_30 ( struct V_28 * V_29 , unsigned int V_11 ,
bool V_34 )
{
struct V_9 * V_10 = V_29 -> V_10 ;
struct V_1 * V_1 = NULL ;
struct V_35 * V_36 ;
F_31 ( V_37 ) ;
unsigned int V_38 ;
F_24 () ;
V_36 = F_32 ( V_29 -> V_27 -> V_35 ) ;
V_38 = V_36 ? V_36 -> V_39 : 1000000 ;
F_28 () ;
if ( F_26 ( & V_10 -> V_40 ) < V_38 )
V_1 = F_10 ( V_10 , V_11 ) ;
if ( V_1 && F_26 ( & V_10 -> V_31 ) > 512 )
F_18 ( V_10 ) ;
while ( V_1 == NULL ) {
F_33 ( & V_41 , & V_37 , V_42 ) ;
F_18 ( V_10 ) ;
if ( F_26 ( & V_10 -> V_40 ) < V_38 ) {
V_1 = F_10 ( V_10 , V_11 ) ;
if ( V_1 )
break;
}
if ( ! V_34 )
break;
if ( F_34 ( V_43 ) ) {
F_35 ( V_10 , L_1 ) ;
break;
}
if ( F_36 ( V_44 / 10 ) == 0 )
V_38 = V_45 ;
}
F_37 ( & V_41 , & V_37 ) ;
if ( V_1 )
F_38 ( V_11 , & V_10 -> V_40 ) ;
return V_1 ;
}
static void F_39 ( struct V_9 * V_10 , struct V_1 * V_1 , int V_46 )
{
T_1 * V_47 = V_46 ? & V_10 -> V_31 : & V_10 -> V_40 ;
int V_6 ;
if ( V_1 == NULL )
return;
if ( V_12 > ( V_48 / V_49 ) * V_50 )
V_6 = F_6 ( V_1 ) ;
else {
struct V_1 * V_4 ;
V_4 = F_5 ( V_1 , & V_6 ) ;
F_11 ( & V_13 ) ;
F_9 ( & V_14 , V_1 , V_4 ) ;
V_12 += V_6 ;
F_12 ( & V_13 ) ;
}
V_6 = F_40 ( V_6 , V_47 ) ;
if ( V_6 < 0 )
F_35 ( V_10 , L_2 ,
V_46 ? L_3 : L_4 , V_6 ) ;
F_41 ( & V_41 ) ;
}
struct V_18 *
F_42 ( struct V_28 * V_29 , T_2 V_51 , T_3 V_52 ,
unsigned int V_53 , unsigned int V_54 , T_4 V_55 ) __must_hold( T_5 )
{
struct V_9 * V_10 = V_29 -> V_10 ;
struct V_18 * V_19 ;
struct V_1 * V_1 = NULL ;
unsigned V_56 = ( V_54 + V_49 - 1 ) >> V_57 ;
if ( F_43 ( V_10 , V_58 ) )
return NULL ;
V_19 = F_44 ( V_59 , V_55 & ~ V_60 ) ;
if ( ! V_19 ) {
if ( ! ( V_55 & V_61 ) )
F_45 ( V_10 , L_5 , V_62 ) ;
return NULL ;
}
if ( V_56 ) {
V_1 = F_30 ( V_29 , V_56 ,
F_46 ( V_55 ) ) ;
if ( ! V_1 )
goto V_63;
}
memset ( V_19 , 0 , sizeof( * V_19 ) ) ;
F_47 ( & V_19 -> V_20 . V_21 ) ;
F_48 ( & V_19 -> V_6 ) ;
V_19 -> V_6 . V_64 = V_53 ;
V_19 -> V_6 . V_52 = V_52 ;
V_19 -> V_65 = V_66 ;
V_19 -> V_29 = V_29 ;
V_19 -> V_67 = V_1 ;
V_19 -> V_68 = V_51 ;
return V_19 ;
V_63:
F_49 ( V_19 , V_59 ) ;
return NULL ;
}
void F_50 ( struct V_9 * V_10 , struct V_18 * V_19 ,
int V_46 )
{
F_51 () ;
if ( V_19 -> V_69 & V_70 )
F_52 ( V_19 -> V_71 ) ;
F_39 ( V_10 , V_19 -> V_67 , V_46 ) ;
F_53 ( V_10 , F_26 ( & V_19 -> V_72 ) == 0 ) ;
F_53 ( V_10 , F_54 ( & V_19 -> V_6 ) ) ;
if ( ! F_55 ( ! ( V_19 -> V_69 & V_73 ) ) ) {
V_19 -> V_69 &= ~ V_73 ;
F_56 ( V_10 , & V_19 -> V_6 ) ;
}
F_49 ( V_19 , V_59 ) ;
}
int F_57 ( struct V_9 * V_10 , struct V_16 * V_21 )
{
F_19 ( V_74 ) ;
struct V_18 * V_19 , * V_23 ;
int V_75 = 0 ;
int V_46 = V_21 == & V_10 -> V_76 ;
F_20 ( & V_10 -> V_24 -> V_25 ) ;
F_58 ( V_21 , & V_74 ) ;
F_21 ( & V_10 -> V_24 -> V_25 ) ;
F_15 (peer_req, t, &work_list, w.list) {
F_50 ( V_10 , V_19 , V_46 ) ;
V_75 ++ ;
}
return V_75 ;
}
static int F_59 ( struct V_9 * V_10 )
{
F_19 ( V_74 ) ;
F_19 ( V_22 ) ;
struct V_18 * V_19 , * V_23 ;
int V_77 = 0 ;
F_20 ( & V_10 -> V_24 -> V_25 ) ;
F_14 ( V_10 , & V_22 ) ;
F_58 ( & V_10 -> V_78 , & V_74 ) ;
F_21 ( & V_10 -> V_24 -> V_25 ) ;
F_15 (peer_req, t, &reclaimed, w.list)
F_22 ( V_10 , V_19 ) ;
F_15 (peer_req, t, &work_list, w.list) {
int V_79 ;
V_79 = V_19 -> V_20 . V_80 ( & V_19 -> V_20 , ! ! V_77 ) ;
if ( ! V_77 )
V_77 = V_79 ;
F_60 ( V_10 , V_19 ) ;
}
F_41 ( & V_10 -> V_81 ) ;
return V_77 ;
}
static void F_61 ( struct V_9 * V_10 ,
struct V_16 * V_2 )
{
F_31 ( V_37 ) ;
while ( ! F_62 ( V_2 ) ) {
F_33 ( & V_10 -> V_81 , & V_37 , V_82 ) ;
F_21 ( & V_10 -> V_24 -> V_25 ) ;
F_63 () ;
F_37 ( & V_10 -> V_81 , & V_37 ) ;
F_20 ( & V_10 -> V_24 -> V_25 ) ;
}
}
static void F_64 ( struct V_9 * V_10 ,
struct V_16 * V_2 )
{
F_20 ( & V_10 -> V_24 -> V_25 ) ;
F_61 ( V_10 , V_2 ) ;
F_21 ( & V_10 -> V_24 -> V_25 ) ;
}
static int F_65 ( struct V_83 * V_84 , void * V_85 , T_6 V_64 , int V_69 )
{
struct V_86 V_87 = {
. V_88 = V_85 ,
. V_89 = V_64 ,
} ;
struct V_90 V_91 = {
. V_92 = ( V_69 ? V_69 : V_93 | V_94 )
} ;
return F_66 ( V_84 , & V_91 , & V_87 , 1 , V_64 , V_91 . V_92 ) ;
}
static int F_67 ( struct V_26 * V_27 , void * V_85 , T_6 V_64 )
{
int V_95 ;
V_95 = F_65 ( V_27 -> V_96 . V_83 , V_85 , V_64 , 0 ) ;
if ( V_95 < 0 ) {
if ( V_95 == - V_97 )
F_68 ( V_27 , L_6 ) ;
else if ( V_95 != - V_98 )
F_45 ( V_27 , L_7 , V_95 ) ;
} else if ( V_95 == 0 ) {
if ( F_69 ( V_99 , & V_27 -> V_69 ) ) {
long V_23 ;
F_24 () ;
V_23 = F_32 ( V_27 -> V_35 ) -> V_100 * V_44 / 10 ;
F_28 () ;
V_23 = F_70 ( V_27 -> V_101 , V_27 -> V_102 < V_103 , V_23 ) ;
if ( V_23 )
goto V_104;
}
F_68 ( V_27 , L_8 ) ;
}
if ( V_95 != V_64 )
F_71 ( V_27 , F_72 ( V_105 , V_106 ) , V_107 ) ;
V_104:
return V_95 ;
}
static int F_73 ( struct V_26 * V_27 , void * V_85 , T_6 V_64 )
{
int V_77 ;
V_77 = F_67 ( V_27 , V_85 , V_64 ) ;
if ( V_77 != V_64 ) {
if ( V_77 >= 0 )
V_77 = - V_108 ;
} else
V_77 = 0 ;
return V_77 ;
}
static int F_74 ( struct V_26 * V_27 , void * V_85 , T_6 V_64 )
{
int V_77 ;
V_77 = F_73 ( V_27 , V_85 , V_64 ) ;
if ( V_77 && ! F_34 ( V_43 ) )
F_35 ( V_27 , L_9 , ( int ) V_64 ) ;
return V_77 ;
}
static void F_75 ( struct V_83 * V_84 , unsigned int V_109 ,
unsigned int V_110 )
{
if ( V_109 ) {
V_84 -> V_111 -> V_112 = V_109 ;
V_84 -> V_111 -> V_113 |= V_114 ;
}
if ( V_110 ) {
V_84 -> V_111 -> V_115 = V_110 ;
V_84 -> V_111 -> V_113 |= V_116 ;
}
}
static struct V_83 * F_76 ( struct V_26 * V_27 )
{
const char * V_117 ;
struct V_83 * V_84 ;
struct V_118 V_119 ;
struct V_118 V_120 ;
struct V_35 * V_36 ;
int V_77 , V_121 , V_122 ;
int V_123 , V_124 , V_125 ;
int V_126 = 1 ;
F_24 () ;
V_36 = F_32 ( V_27 -> V_35 ) ;
if ( ! V_36 ) {
F_28 () ;
return NULL ;
}
V_123 = V_36 -> V_123 ;
V_124 = V_36 -> V_124 ;
V_125 = V_36 -> V_125 ;
F_28 () ;
V_122 = F_77 ( int , V_27 -> V_122 , sizeof( V_119 ) ) ;
memcpy ( & V_119 , & V_27 -> V_127 , V_122 ) ;
if ( ( (struct V_128 * ) & V_27 -> V_127 ) -> V_129 == V_130 )
V_119 . V_131 = 0 ;
else
( (struct V_132 * ) & V_119 ) -> V_133 = 0 ;
V_121 = F_77 ( int , V_27 -> V_121 , sizeof( V_119 ) ) ;
memcpy ( & V_120 , & V_27 -> V_134 , V_121 ) ;
V_117 = L_10 ;
V_77 = F_78 ( & V_135 , ( (struct V_128 * ) & V_119 ) -> V_129 ,
V_136 , V_137 , & V_84 ) ;
if ( V_77 < 0 ) {
V_84 = NULL ;
goto V_104;
}
V_84 -> V_111 -> V_138 =
V_84 -> V_111 -> V_139 = V_125 * V_44 ;
F_75 ( V_84 , V_123 , V_124 ) ;
V_117 = L_11 ;
V_77 = V_84 -> V_140 -> V_141 ( V_84 , (struct V_128 * ) & V_119 , V_122 ) ;
if ( V_77 < 0 )
goto V_104;
V_126 = 0 ;
V_117 = L_12 ;
V_77 = V_84 -> V_140 -> V_142 ( V_84 , (struct V_128 * ) & V_120 , V_121 , 0 ) ;
V_104:
if ( V_77 < 0 ) {
if ( V_84 ) {
F_79 ( V_84 ) ;
V_84 = NULL ;
}
switch ( - V_77 ) {
case V_143 : case V_144 : case V_145 :
case V_146 : case V_98 :
case V_147 : case V_148 :
case V_149 : case V_150 :
V_126 = 0 ;
break;
default:
F_45 ( V_27 , L_13 , V_117 , V_77 ) ;
}
if ( V_126 )
F_71 ( V_27 , F_72 ( V_105 , V_151 ) , V_107 ) ;
}
return V_84 ;
}
static void F_80 ( struct V_84 * V_111 )
{
struct V_152 * V_153 = V_111 -> V_154 ;
void (* F_81)( struct V_84 * V_111 );
F_81 = V_153 -> V_155 ;
if ( V_111 -> V_156 == V_157 )
F_82 ( & V_153 -> V_158 ) ;
F_81 ( V_111 ) ;
}
static int F_83 ( struct V_26 * V_27 , struct V_152 * V_153 )
{
int V_77 , V_123 , V_124 , V_122 ;
struct V_118 V_127 ;
struct V_83 * V_159 ;
struct V_35 * V_36 ;
const char * V_117 ;
F_24 () ;
V_36 = F_32 ( V_27 -> V_35 ) ;
if ( ! V_36 ) {
F_28 () ;
return - V_108 ;
}
V_123 = V_36 -> V_123 ;
V_124 = V_36 -> V_124 ;
F_28 () ;
V_122 = F_77 ( int , V_27 -> V_122 , sizeof( struct V_118 ) ) ;
memcpy ( & V_127 , & V_27 -> V_127 , V_122 ) ;
V_117 = L_10 ;
V_77 = F_78 ( & V_135 , ( (struct V_128 * ) & V_127 ) -> V_129 ,
V_136 , V_137 , & V_159 ) ;
if ( V_77 ) {
V_159 = NULL ;
goto V_104;
}
V_159 -> V_111 -> V_160 = V_161 ;
F_75 ( V_159 , V_123 , V_124 ) ;
V_117 = L_14 ;
V_77 = V_159 -> V_140 -> V_141 ( V_159 , (struct V_128 * ) & V_127 , V_122 ) ;
if ( V_77 < 0 )
goto V_104;
V_153 -> V_159 = V_159 ;
F_84 ( & V_159 -> V_111 -> V_162 ) ;
V_153 -> V_155 = V_159 -> V_111 -> V_163 ;
V_159 -> V_111 -> V_163 = F_80 ;
V_159 -> V_111 -> V_154 = V_153 ;
F_85 ( & V_159 -> V_111 -> V_162 ) ;
V_117 = L_15 ;
V_77 = V_159 -> V_140 -> V_164 ( V_159 , 5 ) ;
if ( V_77 < 0 )
goto V_104;
return 0 ;
V_104:
if ( V_159 )
F_79 ( V_159 ) ;
if ( V_77 < 0 ) {
if ( V_77 != - V_144 && V_77 != - V_146 && V_77 != - V_98 ) {
F_45 ( V_27 , L_13 , V_117 , V_77 ) ;
F_71 ( V_27 , F_72 ( V_105 , V_151 ) , V_107 ) ;
}
}
return - V_108 ;
}
static void F_86 ( struct V_84 * V_111 , struct V_152 * V_153 )
{
F_84 ( & V_111 -> V_162 ) ;
V_111 -> V_163 = V_153 -> V_155 ;
V_111 -> V_154 = NULL ;
F_85 ( & V_111 -> V_162 ) ;
}
static struct V_83 * F_87 ( struct V_26 * V_27 , struct V_152 * V_153 )
{
int V_165 , V_125 , V_77 = 0 ;
struct V_83 * V_166 = NULL ;
struct V_35 * V_36 ;
F_24 () ;
V_36 = F_32 ( V_27 -> V_35 ) ;
if ( ! V_36 ) {
F_28 () ;
return NULL ;
}
V_125 = V_36 -> V_125 ;
F_28 () ;
V_165 = V_125 * V_44 ;
V_165 += ( F_88 () & 1 ) ? V_165 / 7 : - V_165 / 7 ;
V_77 = F_89 ( & V_153 -> V_158 , V_165 ) ;
if ( V_77 <= 0 )
return NULL ;
V_77 = F_90 ( V_153 -> V_159 , & V_166 , 0 ) ;
if ( V_77 < 0 ) {
if ( V_77 != - V_144 && V_77 != - V_146 && V_77 != - V_98 ) {
F_45 ( V_27 , L_16 , V_77 ) ;
F_71 ( V_27 , F_72 ( V_105 , V_151 ) , V_107 ) ;
}
}
if ( V_166 )
F_86 ( V_166 -> V_111 , V_153 ) ;
return V_166 ;
}
static int F_91 ( struct V_26 * V_27 , struct V_167 * V_84 ,
enum V_168 V_169 )
{
if ( ! F_92 ( V_27 , V_84 ) )
return - V_108 ;
return F_93 ( V_27 , V_84 , V_169 , 0 , NULL , 0 ) ;
}
static int F_94 ( struct V_26 * V_27 , struct V_83 * V_84 )
{
unsigned int V_170 = F_95 ( V_27 ) ;
struct V_171 V_172 ;
struct V_35 * V_36 ;
int V_77 ;
F_24 () ;
V_36 = F_32 ( V_27 -> V_35 ) ;
if ( ! V_36 ) {
F_28 () ;
return - V_108 ;
}
V_84 -> V_111 -> V_138 = V_36 -> V_100 * 4 * V_44 / 10 ;
F_28 () ;
V_77 = F_65 ( V_84 , V_27 -> V_96 . V_173 , V_170 , 0 ) ;
if ( V_77 != V_170 ) {
if ( V_77 >= 0 )
V_77 = - V_108 ;
return V_77 ;
}
V_77 = F_96 ( V_27 , V_27 -> V_96 . V_173 , & V_172 ) ;
if ( V_77 )
return V_77 ;
return V_172 . V_169 ;
}
static bool F_97 ( struct V_83 * * V_84 )
{
int V_174 ;
char V_175 [ 4 ] ;
if ( ! * V_84 )
return false ;
V_174 = F_65 ( * V_84 , V_175 , 4 , V_176 | V_177 ) ;
if ( V_174 > 0 || V_174 == - V_144 ) {
return true ;
} else {
F_79 ( * V_84 ) ;
* V_84 = NULL ;
return false ;
}
}
static bool F_98 ( struct V_26 * V_27 ,
struct V_83 * * V_178 ,
struct V_83 * * V_179 )
{
struct V_35 * V_36 ;
int V_180 ;
bool V_181 ;
if ( ! * V_178 || ! * V_179 )
return false ;
F_24 () ;
V_36 = F_32 ( V_27 -> V_35 ) ;
V_180 = ( V_36 -> V_182 ? : V_36 -> V_100 ) * V_44 / 10 ;
F_28 () ;
F_99 ( V_180 ) ;
V_181 = F_97 ( V_178 ) ;
V_181 = F_97 ( V_179 ) && V_181 ;
return V_181 ;
}
int F_100 ( struct V_28 * V_29 )
{
struct V_9 * V_10 = V_29 -> V_10 ;
int V_77 ;
F_101 ( & V_10 -> V_183 , 0 ) ;
V_10 -> V_184 = 0 ;
V_10 -> V_185 = V_29 -> V_27 -> V_186 < 100 ?
& V_29 -> V_27 -> V_187 :
& V_10 -> V_188 ;
V_77 = F_102 ( V_29 ) ;
if ( ! V_77 )
V_77 = F_103 ( V_29 , 0 , 0 ) ;
if ( ! V_77 )
V_77 = F_104 ( V_29 ) ;
if ( ! V_77 )
V_77 = F_105 ( V_29 ) ;
F_106 ( V_189 , & V_10 -> V_69 ) ;
F_106 ( V_190 , & V_10 -> V_69 ) ;
F_101 ( & V_10 -> V_191 , 0 ) ;
F_107 ( & V_10 -> V_192 , V_66 + V_44 ) ;
return V_77 ;
}
static int F_108 ( struct V_26 * V_27 )
{
struct V_167 V_84 , V_193 ;
struct V_28 * V_29 ;
struct V_35 * V_36 ;
int V_30 , V_180 , V_194 ;
bool V_195 , V_181 ;
enum V_196 V_95 ;
struct V_152 V_153 = {
. V_27 = V_27 ,
. V_158 = F_109 ( V_153 . V_158 ) ,
} ;
F_106 ( V_99 , & V_27 -> V_69 ) ;
if ( F_71 ( V_27 , F_72 ( V_105 , V_197 ) , V_198 ) < V_199 )
return - 2 ;
F_110 ( & V_84 . V_200 ) ;
V_84 . V_201 = V_27 -> V_96 . V_201 ;
V_84 . V_173 = V_27 -> V_96 . V_173 ;
V_84 . V_83 = NULL ;
F_110 ( & V_193 . V_200 ) ;
V_193 . V_201 = V_27 -> V_202 . V_201 ;
V_193 . V_173 = V_27 -> V_202 . V_173 ;
V_193 . V_83 = NULL ;
V_27 -> V_186 = 80 ;
if ( F_83 ( V_27 , & V_153 ) )
return 0 ;
do {
struct V_83 * V_203 ;
V_203 = F_76 ( V_27 ) ;
if ( V_203 ) {
if ( ! V_84 . V_83 ) {
V_84 . V_83 = V_203 ;
F_91 ( V_27 , & V_84 , V_204 ) ;
} else if ( ! V_193 . V_83 ) {
F_106 ( V_205 , & V_27 -> V_69 ) ;
V_193 . V_83 = V_203 ;
F_91 ( V_27 , & V_193 , V_206 ) ;
} else {
F_45 ( V_27 , L_17 ) ;
goto V_207;
}
}
if ( F_98 ( V_27 , & V_84 . V_83 , & V_193 . V_83 ) )
break;
V_34:
V_203 = F_87 ( V_27 , & V_153 ) ;
if ( V_203 ) {
int V_208 = F_94 ( V_27 , V_203 ) ;
F_97 ( & V_84 . V_83 ) ;
F_97 ( & V_193 . V_83 ) ;
switch ( V_208 ) {
case V_204 :
if ( V_84 . V_83 ) {
F_35 ( V_27 , L_18 ) ;
F_79 ( V_84 . V_83 ) ;
V_84 . V_83 = V_203 ;
goto V_209;
}
V_84 . V_83 = V_203 ;
break;
case V_206 :
F_111 ( V_205 , & V_27 -> V_69 ) ;
if ( V_193 . V_83 ) {
F_35 ( V_27 , L_19 ) ;
F_79 ( V_193 . V_83 ) ;
V_193 . V_83 = V_203 ;
goto V_209;
}
V_193 . V_83 = V_203 ;
break;
default:
F_35 ( V_27 , L_20 ) ;
F_79 ( V_203 ) ;
V_209:
if ( F_88 () & 1 )
goto V_34;
}
}
if ( V_27 -> V_102 <= V_151 )
goto V_207;
if ( F_34 ( V_43 ) ) {
F_112 ( V_43 ) ;
F_113 () ;
if ( F_114 ( & V_27 -> V_210 ) == V_211 )
goto V_207;
}
V_181 = F_98 ( V_27 , & V_84 . V_83 , & V_193 . V_83 ) ;
} while ( ! V_181 );
if ( V_153 . V_159 )
F_79 ( V_153 . V_159 ) ;
V_84 . V_83 -> V_111 -> V_160 = V_161 ;
V_193 . V_83 -> V_111 -> V_160 = V_161 ;
V_84 . V_83 -> V_111 -> V_212 = V_213 ;
V_193 . V_83 -> V_111 -> V_212 = V_213 ;
V_84 . V_83 -> V_111 -> V_214 = V_215 ;
V_193 . V_83 -> V_111 -> V_214 = V_216 ;
F_24 () ;
V_36 = F_32 ( V_27 -> V_35 ) ;
V_84 . V_83 -> V_111 -> V_139 =
V_84 . V_83 -> V_111 -> V_138 = V_36 -> V_100 * 4 * V_44 / 10 ;
V_193 . V_83 -> V_111 -> V_138 = V_36 -> V_217 * V_44 ;
V_180 = V_36 -> V_180 * V_44 / 10 ;
V_195 = V_36 -> V_195 ;
F_28 () ;
V_193 . V_83 -> V_111 -> V_139 = V_180 ;
F_115 ( V_84 . V_83 ) ;
F_115 ( V_193 . V_83 ) ;
V_27 -> V_96 . V_83 = V_84 . V_83 ;
V_27 -> V_202 . V_83 = V_193 . V_83 ;
V_27 -> V_218 = V_66 ;
V_194 = F_116 ( V_27 ) ;
if ( V_194 <= 0 )
return V_194 ;
if ( V_27 -> V_219 ) {
switch ( F_117 ( V_27 ) ) {
case - 1 :
F_45 ( V_27 , L_21 ) ;
return - 1 ;
case 0 :
F_45 ( V_27 , L_22 ) ;
return 0 ;
}
}
V_27 -> V_96 . V_83 -> V_111 -> V_139 = V_180 ;
V_27 -> V_96 . V_83 -> V_111 -> V_138 = V_220 ;
if ( F_118 ( V_27 ) == - V_221 )
return - 1 ;
F_25 (&connection->peer_devices, peer_device, vnr)
F_119 ( V_29 -> V_10 -> V_185 ) ;
F_111 ( V_222 , & V_27 -> V_69 ) ;
F_25 (&connection->peer_devices, peer_device, vnr)
F_120 ( V_29 -> V_10 -> V_185 ) ;
F_24 () ;
F_25 (&connection->peer_devices, peer_device, vnr) {
struct V_9 * V_10 = V_29 -> V_10 ;
F_27 ( & V_10 -> V_32 ) ;
F_28 () ;
if ( V_195 )
F_111 ( V_223 , & V_10 -> V_69 ) ;
else
F_106 ( V_223 , & V_10 -> V_69 ) ;
F_100 ( V_29 ) ;
F_29 ( & V_10 -> V_32 , V_33 ) ;
F_24 () ;
}
F_28 () ;
V_95 = F_71 ( V_27 , F_72 ( V_105 , V_103 ) , V_198 ) ;
if ( V_95 < V_199 || V_27 -> V_102 != V_103 ) {
F_106 ( V_222 , & V_27 -> V_69 ) ;
return 0 ;
}
F_121 ( & V_27 -> V_224 ) ;
V_27 -> V_225 =
F_122 ( L_23 , V_226 , V_27 -> V_24 -> V_227 ) ;
if ( ! V_27 -> V_225 ) {
F_45 ( V_27 , L_24 ) ;
return 0 ;
}
F_119 ( & V_27 -> V_24 -> V_228 ) ;
V_27 -> V_35 -> V_195 = 0 ;
F_120 ( & V_27 -> V_24 -> V_228 ) ;
return V_194 ;
V_207:
if ( V_153 . V_159 )
F_79 ( V_153 . V_159 ) ;
if ( V_84 . V_83 )
F_79 ( V_84 . V_83 ) ;
if ( V_193 . V_83 )
F_79 ( V_193 . V_83 ) ;
return - 1 ;
}
static int F_96 ( struct V_26 * V_27 , void * V_229 , struct V_171 * V_172 )
{
unsigned int V_170 = F_95 ( V_27 ) ;
if ( V_170 == sizeof( struct V_230 ) &&
* ( V_231 * ) V_229 == F_123 ( V_232 ) ) {
struct V_230 * V_194 = V_229 ;
if ( V_194 -> V_233 != 0 ) {
F_45 ( V_27 , L_25 ) ;
return - V_234 ;
}
V_172 -> V_30 = F_124 ( V_194 -> V_235 ) ;
V_172 -> V_169 = F_124 ( V_194 -> V_236 ) ;
V_172 -> V_64 = F_125 ( V_194 -> V_237 ) ;
} else if ( V_170 == sizeof( struct V_238 ) &&
* ( V_239 * ) V_229 == F_126 ( V_240 ) ) {
struct V_238 * V_194 = V_229 ;
V_172 -> V_169 = F_124 ( V_194 -> V_236 ) ;
V_172 -> V_64 = F_125 ( V_194 -> V_237 ) ;
V_172 -> V_30 = 0 ;
} else if ( V_170 == sizeof( struct V_241 ) &&
* ( V_231 * ) V_229 == F_123 ( V_242 ) ) {
struct V_241 * V_194 = V_229 ;
V_172 -> V_169 = F_124 ( V_194 -> V_236 ) ;
V_172 -> V_64 = F_124 ( V_194 -> V_237 ) ;
V_172 -> V_30 = 0 ;
} else {
F_45 ( V_27 , L_26 ,
F_125 ( * ( V_231 * ) V_229 ) ,
V_27 -> V_186 ) ;
return - V_234 ;
}
V_172 -> V_96 = V_229 + V_170 ;
return 0 ;
}
static int F_127 ( struct V_26 * V_27 , struct V_171 * V_172 )
{
void * V_243 = V_27 -> V_96 . V_173 ;
int V_77 ;
V_77 = F_74 ( V_27 , V_243 , F_95 ( V_27 ) ) ;
if ( V_77 )
return V_77 ;
V_77 = F_96 ( V_27 , V_243 , V_172 ) ;
V_27 -> V_218 = V_66 ;
return V_77 ;
}
void F_128 ( struct V_244 * V_244 )
{
struct V_245 * V_246 = V_244 -> V_247 ;
struct V_9 * V_10 = V_246 -> V_10 ;
struct V_248 * V_249 = V_246 -> V_249 ;
if ( V_244 -> V_250 ) {
V_249 -> error = V_244 -> V_250 ;
F_68 ( V_10 , L_27 , V_244 -> V_250 ) ;
}
F_52 ( V_246 ) ;
F_129 ( V_244 ) ;
F_106 ( V_251 , & V_10 -> V_69 ) ;
F_130 ( V_10 ) ;
F_29 ( & V_10 -> V_32 , V_33 ) ;
if ( F_131 ( & V_249 -> V_252 ) )
F_82 ( & V_249 -> V_253 ) ;
}
static void F_132 ( struct V_9 * V_10 , struct V_248 * V_249 )
{
struct V_244 * V_244 = F_133 ( V_213 , 0 ) ;
struct V_245 * V_246 = F_134 ( sizeof( * V_246 ) , V_213 ) ;
if ( ! V_244 || ! V_246 ) {
F_35 ( V_10 , L_28 ) ;
F_52 ( V_246 ) ;
if ( V_244 )
F_129 ( V_244 ) ;
V_249 -> error = - V_254 ;
F_130 ( V_10 ) ;
F_29 ( & V_10 -> V_32 , V_33 ) ;
return;
}
V_246 -> V_10 = V_10 ;
V_246 -> V_249 = V_249 ;
V_244 -> V_255 = V_10 -> V_256 -> V_257 ;
V_244 -> V_247 = V_246 ;
V_244 -> V_258 = F_128 ;
V_244 -> V_259 = V_260 | V_261 ;
V_10 -> V_262 = V_66 ;
F_111 ( V_251 , & V_10 -> V_69 ) ;
F_135 ( & V_249 -> V_252 ) ;
F_136 ( V_244 ) ;
}
static void F_137 ( struct V_26 * V_27 )
{
if ( V_27 -> V_24 -> V_263 >= V_264 ) {
struct V_28 * V_29 ;
struct V_248 V_249 ;
int V_30 ;
F_101 ( & V_249 . V_252 , 1 ) ;
V_249 . error = 0 ;
F_138 ( & V_249 . V_253 ) ;
F_24 () ;
F_25 (&connection->peer_devices, peer_device, vnr) {
struct V_9 * V_10 = V_29 -> V_10 ;
if ( ! F_139 ( V_10 ) )
continue;
F_27 ( & V_10 -> V_32 ) ;
F_28 () ;
F_132 ( V_10 , & V_249 ) ;
F_24 () ;
}
F_28 () ;
if ( ! F_131 ( & V_249 . V_252 ) )
F_140 ( & V_249 . V_253 ) ;
if ( V_249 . error ) {
F_141 ( V_27 -> V_24 , NULL , V_265 ) ;
}
}
}
static enum V_266 F_142 ( struct V_26 * V_27 ,
struct V_267 * V_268 ,
enum V_269 V_270 )
{
int V_271 ;
struct V_267 * V_272 ;
enum V_266 V_95 = V_273 ;
F_11 ( & V_27 -> V_274 ) ;
do {
V_272 = NULL ;
V_271 = F_26 ( & V_268 -> V_271 ) ;
switch ( V_270 & ~ V_275 ) {
case V_276 :
F_143 ( & V_268 -> V_277 ) ;
break;
case V_278 :
F_111 ( V_279 , & V_268 -> V_69 ) ;
break;
case V_280 :
break;
}
if ( V_271 != 0 &&
F_26 ( & V_268 -> V_277 ) == 0 &&
( F_69 ( V_279 , & V_268 -> V_69 ) || V_270 & V_275 ) ) {
if ( ! ( V_270 & V_275 ) ) {
F_12 ( & V_27 -> V_274 ) ;
F_144 ( V_268 -> V_27 , V_268 -> V_281 , V_271 ) ;
F_11 ( & V_27 -> V_274 ) ;
}
#if 0
if (test_bit(DE_HAVE_BARRIER_NUMBER, &epoch->flags))
dec_unacked(epoch->connection);
#endif
if ( V_27 -> V_282 != V_268 ) {
V_272 = F_145 ( V_268 -> V_21 . V_283 , struct V_267 , V_21 ) ;
F_146 ( & V_268 -> V_21 ) ;
V_270 = V_280 | ( V_270 & V_275 ) ;
V_27 -> V_284 -- ;
F_52 ( V_268 ) ;
if ( V_95 == V_273 )
V_95 = V_285 ;
} else {
V_268 -> V_69 = 0 ;
F_101 ( & V_268 -> V_271 , 0 ) ;
if ( V_95 == V_273 )
V_95 = V_286 ;
}
}
if ( ! V_272 )
break;
V_268 = V_272 ;
} while ( 1 );
F_12 ( & V_27 -> V_274 ) ;
return V_95 ;
}
static enum V_287
F_147 ( struct V_288 * V_289 , enum V_287 V_290 )
{
struct V_291 * V_292 ;
V_292 = F_32 ( V_289 -> V_291 ) ;
if ( V_290 == V_264 && ! V_292 -> V_293 )
V_290 = V_265 ;
if ( V_290 == V_265 && ! V_292 -> V_294 )
V_290 = V_295 ;
return V_290 ;
}
void F_141 ( struct V_296 * V_24 , struct V_288 * V_289 ,
enum V_287 V_290 )
{
struct V_9 * V_10 ;
enum V_287 V_297 ;
int V_30 ;
static char * V_298 [] = {
[ V_295 ] = L_29 ,
[ V_265 ] = L_30 ,
[ V_264 ] = L_31 ,
} ;
V_297 = V_24 -> V_263 ;
if ( V_290 != V_264 )
V_290 = F_148 ( V_297 , V_290 ) ;
F_24 () ;
F_25 (&resource->devices, device, vnr) {
if ( F_139 ( V_10 ) ) {
V_290 = F_147 ( V_10 -> V_256 , V_290 ) ;
if ( V_10 -> V_256 == V_289 )
V_289 = NULL ;
F_130 ( V_10 ) ;
}
}
if ( V_289 )
V_290 = F_147 ( V_289 , V_290 ) ;
F_28 () ;
V_24 -> V_263 = V_290 ;
if ( V_297 != V_24 -> V_263 || V_290 == V_264 )
F_68 ( V_24 , L_32 , V_298 [ V_24 -> V_263 ] ) ;
}
int F_149 ( struct V_9 * V_10 , T_3 V_299 , unsigned int V_300 , bool V_301 )
{
struct V_302 * V_289 = V_10 -> V_256 -> V_257 ;
struct V_303 * V_304 = F_150 ( V_289 ) ;
T_3 V_4 , V_305 ;
unsigned int V_306 , V_307 ;
int V_308 ;
int V_77 = 0 ;
if ( ! V_301 )
goto V_309;
V_307 = F_151 ( V_304 -> V_310 . V_311 >> 9 , 1U ) ;
V_308 = ( F_152 ( V_289 ) >> 9 ) % V_307 ;
V_306 = F_148 ( V_304 -> V_310 . V_306 , ( 1U << 22 ) ) ;
V_306 -= V_306 % V_307 ;
if ( F_153 ( ! V_306 ) )
goto V_309;
if ( V_300 < V_307 )
goto V_309;
V_4 = V_299 ;
if ( F_154 ( V_4 , V_307 ) != V_308 ) {
if ( V_300 < 2 * V_307 )
goto V_309;
V_4 = V_299 + V_307 - V_308 ;
V_4 = V_299 + V_307 - F_154 ( V_4 , V_307 ) ;
V_305 = V_4 - V_299 ;
V_77 |= F_155 ( V_289 , V_299 , V_305 , V_213 , 0 ) ;
V_300 -= V_305 ;
V_299 = V_4 ;
}
while ( V_300 >= V_307 ) {
V_305 = F_77 ( T_3 , V_300 , V_306 ) ;
V_77 |= F_156 ( V_289 , V_299 , V_305 , V_213 , 0 ) ;
V_300 -= V_305 ;
V_299 += V_305 ;
}
V_309:
if ( V_300 ) {
V_77 |= F_155 ( V_289 , V_299 , V_300 , V_213 , 0 ) ;
}
return V_77 != 0 ;
}
static bool F_157 ( struct V_9 * V_10 )
{
struct V_303 * V_304 = F_150 ( V_10 -> V_256 -> V_257 ) ;
struct V_291 * V_292 ;
bool V_312 ;
if ( ! F_158 ( V_304 ) )
return false ;
if ( V_304 -> V_310 . V_313 )
return true ;
F_24 () ;
V_292 = F_32 ( V_10 -> V_256 -> V_291 ) ;
V_312 = V_292 -> V_314 ;
F_28 () ;
return V_312 ;
}
static void F_159 ( struct V_9 * V_10 , struct V_18 * V_19 )
{
if ( ! F_157 ( V_10 ) )
V_19 -> V_69 |= V_315 ;
if ( F_149 ( V_10 , V_19 -> V_6 . V_52 ,
V_19 -> V_6 . V_64 >> 9 , ! ( V_19 -> V_69 & V_315 ) ) )
V_19 -> V_69 |= V_316 ;
F_160 ( V_19 ) ;
}
static void F_161 ( struct V_9 * V_10 ,
struct V_18 * V_19 )
{
struct V_302 * V_289 = V_10 -> V_256 -> V_257 ;
T_3 V_203 = V_19 -> V_6 . V_52 ;
T_3 V_305 = V_19 -> V_6 . V_64 >> 9 ;
if ( F_162 ( V_289 , V_203 , V_305 , V_213 , V_19 -> V_67 ) )
V_19 -> V_69 |= V_316 ;
F_160 ( V_19 ) ;
}
int F_163 ( struct V_9 * V_10 ,
struct V_18 * V_19 ,
const unsigned V_317 , const unsigned V_318 ,
const int V_319 )
{
struct V_244 * V_320 = NULL ;
struct V_244 * V_244 ;
struct V_1 * V_1 = V_19 -> V_67 ;
T_3 V_52 = V_19 -> V_6 . V_52 ;
unsigned V_321 = V_19 -> V_6 . V_64 ;
unsigned V_322 = 0 ;
unsigned V_56 = ( V_321 + V_49 - 1 ) >> V_57 ;
int V_77 = - V_254 ;
if ( V_19 -> V_69 & ( V_323 | V_324 ) ) {
F_164 ( V_19 -> V_29 -> V_27 ) ;
V_19 -> V_65 = V_66 ;
V_19 -> V_69 |= V_325 ;
if ( F_62 ( & V_19 -> V_20 . V_21 ) ) {
F_20 ( & V_10 -> V_24 -> V_25 ) ;
F_165 ( & V_19 -> V_20 . V_21 , & V_10 -> V_326 ) ;
F_21 ( & V_10 -> V_24 -> V_25 ) ;
}
if ( V_19 -> V_69 & V_323 )
F_159 ( V_10 , V_19 ) ;
else
F_161 ( V_10 , V_19 ) ;
return 0 ;
}
V_327:
V_244 = F_133 ( V_213 , V_56 ) ;
if ( ! V_244 ) {
F_45 ( V_10 , L_33 , V_56 ) ;
goto V_63;
}
V_244 -> V_328 . V_329 = V_52 ;
V_244 -> V_255 = V_10 -> V_256 -> V_257 ;
F_166 ( V_244 , V_317 , V_318 ) ;
V_244 -> V_247 = V_19 ;
V_244 -> V_258 = V_330 ;
V_244 -> V_331 = V_320 ;
V_320 = V_244 ;
++ V_322 ;
F_167 (page) {
unsigned V_5 = F_77 ( unsigned , V_321 , V_49 ) ;
if ( ! F_168 ( V_244 , V_1 , V_5 , 0 ) )
goto V_327;
V_321 -= V_5 ;
V_52 += V_5 >> 9 ;
-- V_56 ;
}
F_53 ( V_10 , V_321 == 0 ) ;
F_53 ( V_10 , V_1 == NULL ) ;
F_101 ( & V_19 -> V_72 , V_322 ) ;
V_19 -> V_65 = V_66 ;
V_19 -> V_69 |= V_325 ;
do {
V_244 = V_320 ;
V_320 = V_320 -> V_331 ;
V_244 -> V_331 = NULL ;
F_169 ( V_10 , V_319 , V_244 ) ;
} while ( V_320 );
return 0 ;
V_63:
while ( V_320 ) {
V_244 = V_320 ;
V_320 = V_320 -> V_331 ;
F_129 ( V_244 ) ;
}
return V_77 ;
}
static void F_170 ( struct V_9 * V_10 ,
struct V_18 * V_19 )
{
struct V_332 * V_6 = & V_19 -> V_6 ;
F_171 ( & V_10 -> V_333 , V_6 ) ;
F_48 ( V_6 ) ;
if ( V_6 -> V_334 )
F_41 ( & V_10 -> V_335 ) ;
}
static void F_164 ( struct V_26 * V_27 )
{
struct V_28 * V_29 ;
int V_30 ;
F_24 () ;
F_25 (&connection->peer_devices, peer_device, vnr) {
struct V_9 * V_10 = V_29 -> V_10 ;
F_27 ( & V_10 -> V_32 ) ;
F_28 () ;
F_64 ( V_10 , & V_10 -> V_326 ) ;
F_29 ( & V_10 -> V_32 , V_33 ) ;
F_24 () ;
}
F_28 () ;
}
static int F_172 ( struct V_26 * V_27 , struct V_171 * V_172 )
{
int V_95 ;
struct V_336 * V_337 = V_172 -> V_96 ;
struct V_267 * V_268 ;
V_27 -> V_282 -> V_281 = V_337 -> V_338 ;
V_27 -> V_282 -> V_27 = V_27 ;
V_95 = F_142 ( V_27 , V_27 -> V_282 , V_278 ) ;
switch ( V_27 -> V_24 -> V_263 ) {
case V_295 :
if ( V_95 == V_286 )
return 0 ;
V_268 = F_134 ( sizeof( struct V_267 ) , V_213 ) ;
if ( V_268 )
break;
else
F_35 ( V_27 , L_34 ) ;
case V_264 :
case V_265 :
F_164 ( V_27 ) ;
F_137 ( V_27 ) ;
if ( F_26 ( & V_27 -> V_282 -> V_271 ) ) {
V_268 = F_134 ( sizeof( struct V_267 ) , V_213 ) ;
if ( V_268 )
break;
}
return 0 ;
default:
F_45 ( V_27 , L_35 ,
V_27 -> V_24 -> V_263 ) ;
return - V_108 ;
}
V_268 -> V_69 = 0 ;
F_101 ( & V_268 -> V_271 , 0 ) ;
F_101 ( & V_268 -> V_277 , 0 ) ;
F_11 ( & V_27 -> V_274 ) ;
if ( F_26 ( & V_27 -> V_282 -> V_271 ) ) {
F_173 ( & V_268 -> V_21 , & V_27 -> V_282 -> V_21 ) ;
V_27 -> V_282 = V_268 ;
V_27 -> V_284 ++ ;
} else {
F_52 ( V_268 ) ;
}
F_12 ( & V_27 -> V_274 ) ;
return 0 ;
}
static void F_174 ( struct V_339 * V_194 ,
struct V_18 * V_340 , void * V_341 ,
unsigned int V_54 )
{
unsigned int V_4 = V_340 -> V_6 . V_64 ;
V_340 -> V_6 . V_64 = V_54 ;
F_175 ( V_194 , V_340 , V_341 ) ;
V_340 -> V_6 . V_64 = V_4 ;
}
static struct V_18 *
F_176 ( struct V_28 * V_29 , T_2 V_51 , T_3 V_52 ,
struct V_171 * V_172 ) __must_hold( T_5 )
{
struct V_9 * V_10 = V_29 -> V_10 ;
const T_3 V_342 = F_177 ( V_10 -> V_343 ) ;
struct V_18 * V_19 ;
struct V_1 * V_1 ;
int V_344 , V_77 ;
unsigned int V_321 = V_172 -> V_64 , V_345 ;
void * V_346 = V_29 -> V_27 -> V_347 ;
void * V_348 = V_29 -> V_27 -> V_349 ;
unsigned long * V_96 ;
struct V_350 * V_351 = ( V_172 -> V_169 == V_352 ) ? V_172 -> V_96 : NULL ;
struct V_350 * V_353 = ( V_172 -> V_169 == V_354 ) ? V_172 -> V_96 : NULL ;
V_344 = 0 ;
if ( ! V_351 && V_29 -> V_27 -> V_355 ) {
V_344 = F_178 ( V_29 -> V_27 -> V_355 ) ;
V_77 = F_74 ( V_29 -> V_27 , V_346 , V_344 ) ;
if ( V_77 )
return NULL ;
V_321 -= V_344 ;
}
V_345 = V_321 ;
if ( V_351 ) {
if ( ! F_55 ( V_321 == 0 ) )
return NULL ;
V_345 = F_125 ( V_351 -> V_64 ) ;
} else if ( V_353 ) {
if ( V_321 != F_179 ( V_10 -> V_356 ) ) {
F_45 ( V_29 , L_36 ,
V_321 , F_179 ( V_10 -> V_356 ) ) ;
return NULL ;
}
if ( V_321 != F_180 ( V_10 -> V_256 -> V_257 ) ) {
F_45 ( V_29 , L_37 ,
V_321 , F_180 ( V_10 -> V_256 -> V_257 ) ) ;
return NULL ;
}
V_345 = F_125 ( V_353 -> V_64 ) ;
}
if ( ! F_55 ( F_181 ( V_345 , 512 ) ) )
return NULL ;
if ( V_351 || V_353 ) {
if ( ! F_55 ( V_345 <= ( V_357 << 9 ) ) )
return NULL ;
} else if ( ! F_55 ( V_345 <= V_48 ) )
return NULL ;
if ( V_52 + ( V_345 >> 9 ) > V_342 ) {
F_45 ( V_10 , L_38
L_39 ,
( unsigned long long ) V_342 ,
( unsigned long long ) V_52 , V_345 ) ;
return NULL ;
}
V_19 = F_42 ( V_29 , V_51 , V_52 , V_345 , V_321 , V_213 ) ;
if ( ! V_19 )
return NULL ;
V_19 -> V_69 |= V_358 ;
if ( V_351 ) {
V_19 -> V_69 |= V_323 ;
return V_19 ;
}
if ( V_353 )
V_19 -> V_69 |= V_324 ;
V_345 = V_321 ;
V_1 = V_19 -> V_67 ;
F_167 (page) {
unsigned V_5 = F_77 ( int , V_345 , V_49 ) ;
V_96 = F_182 ( V_1 ) ;
V_77 = F_74 ( V_29 -> V_27 , V_96 , V_5 ) ;
if ( F_43 ( V_10 , V_359 ) ) {
F_45 ( V_10 , L_40 ) ;
V_96 [ 0 ] = V_96 [ 0 ] ^ ( unsigned long ) - 1 ;
}
F_183 ( V_1 ) ;
if ( V_77 ) {
F_60 ( V_10 , V_19 ) ;
return NULL ;
}
V_345 -= V_5 ;
}
if ( V_344 ) {
F_174 ( V_29 -> V_27 -> V_355 , V_19 , V_348 , V_321 ) ;
if ( memcmp ( V_346 , V_348 , V_344 ) ) {
F_45 ( V_10 , L_41 ,
( unsigned long long ) V_52 , V_321 ) ;
F_60 ( V_10 , V_19 ) ;
return NULL ;
}
}
V_10 -> V_360 += V_321 >> 9 ;
return V_19 ;
}
static int F_184 ( struct V_28 * V_29 , int V_321 )
{
struct V_1 * V_1 ;
int V_77 = 0 ;
void * V_96 ;
if ( ! V_321 )
return 0 ;
V_1 = F_30 ( V_29 , 1 , 1 ) ;
V_96 = F_182 ( V_1 ) ;
while ( V_321 ) {
unsigned int V_5 = F_77 ( int , V_321 , V_49 ) ;
V_77 = F_74 ( V_29 -> V_27 , V_96 , V_5 ) ;
if ( V_77 )
break;
V_321 -= V_5 ;
}
F_183 ( V_1 ) ;
F_39 ( V_29 -> V_10 , V_1 , 0 ) ;
return V_77 ;
}
static int F_185 ( struct V_28 * V_29 , struct V_361 * V_362 ,
T_3 V_52 , int V_321 )
{
struct V_363 V_364 ;
struct V_365 V_366 ;
struct V_244 * V_244 ;
int V_344 , V_77 , F_55 ;
void * V_346 = V_29 -> V_27 -> V_347 ;
void * V_348 = V_29 -> V_27 -> V_349 ;
V_344 = 0 ;
if ( V_29 -> V_27 -> V_355 ) {
V_344 = F_178 ( V_29 -> V_27 -> V_355 ) ;
V_77 = F_74 ( V_29 -> V_27 , V_346 , V_344 ) ;
if ( V_77 )
return V_77 ;
V_321 -= V_344 ;
}
V_29 -> V_10 -> V_360 += V_321 >> 9 ;
V_244 = V_362 -> V_367 ;
F_53 ( V_29 -> V_10 , V_52 == V_244 -> V_328 . V_329 ) ;
F_186 (bvec, bio, iter) {
void * V_368 = F_182 ( V_364 . V_369 ) + V_364 . V_370 ;
F_55 = F_77 ( int , V_321 , V_364 . V_371 ) ;
V_77 = F_74 ( V_29 -> V_27 , V_368 , F_55 ) ;
F_183 ( V_364 . V_369 ) ;
if ( V_77 )
return V_77 ;
V_321 -= F_55 ;
}
if ( V_344 ) {
F_187 ( V_29 -> V_27 -> V_355 , V_244 , V_348 ) ;
if ( memcmp ( V_346 , V_348 , V_344 ) ) {
F_45 ( V_29 , L_42 ) ;
return - V_234 ;
}
}
F_53 ( V_29 -> V_10 , V_321 == 0 ) ;
return 0 ;
}
static int F_188 ( struct V_372 * V_20 , int V_373 )
{
struct V_18 * V_19 =
F_189 ( V_20 , struct V_18 , V_20 ) ;
struct V_28 * V_29 = V_19 -> V_29 ;
struct V_9 * V_10 = V_29 -> V_10 ;
T_3 V_52 = V_19 -> V_6 . V_52 ;
int V_77 ;
F_53 ( V_10 , F_54 ( & V_19 -> V_6 ) ) ;
if ( F_190 ( ( V_19 -> V_69 & V_316 ) == 0 ) ) {
F_191 ( V_10 , V_52 , V_19 -> V_6 . V_64 ) ;
V_77 = F_192 ( V_29 , V_374 , V_19 ) ;
} else {
F_193 ( V_10 , V_52 , V_19 -> V_6 . V_64 ) ;
V_77 = F_192 ( V_29 , V_375 , V_19 ) ;
}
F_194 ( V_10 ) ;
return V_77 ;
}
static int F_195 ( struct V_28 * V_29 , T_3 V_52 ,
struct V_171 * V_172 ) __releases( T_5 )
{
struct V_9 * V_10 = V_29 -> V_10 ;
struct V_18 * V_19 ;
V_19 = F_176 ( V_29 , V_376 , V_52 , V_172 ) ;
if ( ! V_19 )
goto V_63;
F_196 ( V_10 ) ;
F_197 ( V_10 ) ;
V_19 -> V_20 . V_80 = F_188 ;
V_19 -> V_65 = V_66 ;
F_20 ( & V_10 -> V_24 -> V_25 ) ;
F_165 ( & V_19 -> V_20 . V_21 , & V_10 -> V_377 ) ;
F_21 ( & V_10 -> V_24 -> V_25 ) ;
F_38 ( V_172 -> V_64 >> 9 , & V_10 -> V_378 ) ;
if ( F_163 ( V_10 , V_19 , V_379 , 0 ,
V_380 ) == 0 )
return 0 ;
F_45 ( V_10 , L_43 ) ;
F_20 ( & V_10 -> V_24 -> V_25 ) ;
F_146 ( & V_19 -> V_20 . V_21 ) ;
F_21 ( & V_10 -> V_24 -> V_25 ) ;
F_60 ( V_10 , V_19 ) ;
V_63:
F_130 ( V_10 ) ;
return - V_108 ;
}
static struct V_361 *
F_198 ( struct V_9 * V_10 , struct V_381 * V_382 , T_2 V_51 ,
T_3 V_52 , bool V_383 , const char * V_384 )
{
struct V_361 * V_362 ;
V_362 = (struct V_361 * ) ( unsigned long ) V_51 ;
if ( F_199 ( V_382 , V_52 , & V_362 -> V_6 ) && V_362 -> V_6 . T_5 )
return V_362 ;
if ( ! V_383 ) {
F_45 ( V_10 , L_44 , V_384 ,
( unsigned long ) V_51 , ( unsigned long long ) V_52 ) ;
}
return NULL ;
}
static int F_200 ( struct V_26 * V_27 , struct V_171 * V_172 )
{
struct V_28 * V_29 ;
struct V_9 * V_10 ;
struct V_361 * V_362 ;
T_3 V_52 ;
int V_77 ;
struct V_385 * V_337 = V_172 -> V_96 ;
V_29 = F_201 ( V_27 , V_172 -> V_30 ) ;
if ( ! V_29 )
return - V_108 ;
V_10 = V_29 -> V_10 ;
V_52 = F_202 ( V_337 -> V_52 ) ;
F_20 ( & V_10 -> V_24 -> V_25 ) ;
V_362 = F_198 ( V_10 , & V_10 -> V_386 , V_337 -> V_68 , V_52 , false , V_62 ) ;
F_21 ( & V_10 -> V_24 -> V_25 ) ;
if ( F_153 ( ! V_362 ) )
return - V_108 ;
V_77 = F_185 ( V_29 , V_362 , V_52 , V_172 -> V_64 ) ;
if ( ! V_77 )
F_203 ( V_362 , V_387 ) ;
return V_77 ;
}
static int F_204 ( struct V_26 * V_27 , struct V_171 * V_172 )
{
struct V_28 * V_29 ;
struct V_9 * V_10 ;
T_3 V_52 ;
int V_77 ;
struct V_385 * V_337 = V_172 -> V_96 ;
V_29 = F_201 ( V_27 , V_172 -> V_30 ) ;
if ( ! V_29 )
return - V_108 ;
V_10 = V_29 -> V_10 ;
V_52 = F_202 ( V_337 -> V_52 ) ;
F_53 ( V_10 , V_337 -> V_68 == V_376 ) ;
if ( F_139 ( V_10 ) ) {
V_77 = F_195 ( V_29 , V_52 , V_172 ) ;
} else {
if ( F_205 ( & V_388 ) )
F_45 ( V_10 , L_45 ) ;
V_77 = F_184 ( V_29 , V_172 -> V_64 ) ;
F_206 ( V_29 , V_375 , V_337 , V_172 -> V_64 ) ;
}
F_38 ( V_172 -> V_64 >> 9 , & V_10 -> V_389 ) ;
return V_77 ;
}
static void F_207 ( struct V_9 * V_10 ,
T_3 V_52 , int V_64 )
{
struct V_332 * V_6 ;
struct V_361 * V_362 ;
F_208 (i, &device->write_requests, sector, size) {
if ( ! V_6 -> T_5 )
continue;
V_362 = F_189 ( V_6 , struct V_361 , V_6 ) ;
if ( V_362 -> V_390 & V_391 ||
! ( V_362 -> V_390 & V_392 ) )
continue;
F_209 ( V_362 , V_393 , NULL ) ;
}
}
static int F_210 ( struct V_372 * V_20 , int V_394 )
{
struct V_18 * V_19 =
F_189 ( V_20 , struct V_18 , V_20 ) ;
struct V_28 * V_29 = V_19 -> V_29 ;
struct V_9 * V_10 = V_29 -> V_10 ;
T_3 V_52 = V_19 -> V_6 . V_52 ;
int V_77 = 0 , V_395 ;
if ( V_19 -> V_69 & V_396 ) {
if ( F_190 ( ( V_19 -> V_69 & V_316 ) == 0 ) ) {
V_395 = ( V_10 -> V_397 . V_105 >= V_398 &&
V_10 -> V_397 . V_105 <= V_399 &&
V_19 -> V_69 & V_400 ) ?
V_374 : V_401 ;
V_77 = F_192 ( V_29 , V_395 , V_19 ) ;
if ( V_395 == V_374 )
F_191 ( V_10 , V_52 , V_19 -> V_6 . V_64 ) ;
} else {
V_77 = F_192 ( V_29 , V_375 , V_19 ) ;
}
F_194 ( V_10 ) ;
}
if ( V_19 -> V_69 & V_402 ) {
F_20 ( & V_10 -> V_24 -> V_25 ) ;
F_53 ( V_10 , ! F_54 ( & V_19 -> V_6 ) ) ;
F_170 ( V_10 , V_19 ) ;
if ( V_19 -> V_69 & V_403 )
F_207 ( V_10 , V_52 , V_19 -> V_6 . V_64 ) ;
F_21 ( & V_10 -> V_24 -> V_25 ) ;
} else
F_53 ( V_10 , F_54 ( & V_19 -> V_6 ) ) ;
F_142 ( V_29 -> V_27 , V_19 -> V_268 , V_276 + ( V_394 ? V_275 : 0 ) ) ;
return V_77 ;
}
static int F_211 ( struct V_372 * V_20 , enum V_168 V_404 )
{
struct V_18 * V_19 =
F_189 ( V_20 , struct V_18 , V_20 ) ;
struct V_28 * V_29 = V_19 -> V_29 ;
int V_77 ;
V_77 = F_192 ( V_29 , V_404 , V_19 ) ;
F_194 ( V_29 -> V_10 ) ;
return V_77 ;
}
static int F_212 ( struct V_372 * V_20 , int V_373 )
{
return F_211 ( V_20 , V_405 ) ;
}
static int F_213 ( struct V_372 * V_20 , int V_373 )
{
struct V_18 * V_19 =
F_189 ( V_20 , struct V_18 , V_20 ) ;
struct V_26 * V_27 = V_19 -> V_29 -> V_27 ;
return F_211 ( V_20 , V_27 -> V_186 >= 100 ?
V_406 : V_405 ) ;
}
static bool F_214 ( T_7 V_47 , T_7 V_407 )
{
return ( V_408 ) V_47 - ( V_408 ) V_407 > 0 ;
}
static T_7 F_215 ( T_7 V_47 , T_7 V_407 )
{
return F_214 ( V_47 , V_407 ) ? V_47 : V_407 ;
}
static void F_216 ( struct V_28 * V_29 , unsigned int V_184 )
{
struct V_9 * V_10 = V_29 -> V_10 ;
unsigned int V_409 ;
if ( F_69 ( V_205 , & V_29 -> V_27 -> V_69 ) ) {
F_11 ( & V_10 -> V_410 ) ;
V_409 = F_215 ( V_10 -> V_184 , V_184 ) ;
V_10 -> V_184 = V_409 ;
F_12 ( & V_10 -> V_410 ) ;
if ( V_184 == V_409 )
F_41 ( & V_10 -> V_411 ) ;
}
}
static inline int F_217 ( T_3 V_412 , int V_413 , T_3 V_414 , int V_415 )
{
return ! ( ( V_412 + ( V_413 >> 9 ) <= V_414 ) || ( V_412 >= V_414 + ( V_415 >> 9 ) ) ) ;
}
static bool F_218 ( struct V_9 * V_10 , struct V_18 * V_19 )
{
struct V_18 * V_416 ;
bool V_95 = false ;
F_20 ( & V_10 -> V_24 -> V_25 ) ;
F_219 (rs_req, &device->sync_ee, w.list) {
if ( F_217 ( V_19 -> V_6 . V_52 , V_19 -> V_6 . V_64 ,
V_416 -> V_6 . V_52 , V_416 -> V_6 . V_64 ) ) {
V_95 = true ;
break;
}
}
F_21 ( & V_10 -> V_24 -> V_25 ) ;
return V_95 ;
}
static int F_220 ( struct V_28 * V_29 , const T_7 V_184 )
{
struct V_9 * V_10 = V_29 -> V_10 ;
F_31 ( V_37 ) ;
long V_180 ;
int V_417 = 0 , V_418 ;
if ( ! F_69 ( V_205 , & V_29 -> V_27 -> V_69 ) )
return 0 ;
F_11 ( & V_10 -> V_410 ) ;
for (; ; ) {
if ( ! F_214 ( V_184 - 1 , V_10 -> V_184 ) ) {
V_10 -> V_184 = F_215 ( V_10 -> V_184 , V_184 ) ;
break;
}
if ( F_34 ( V_43 ) ) {
V_417 = - V_98 ;
break;
}
F_24 () ;
V_418 = F_32 ( V_29 -> V_27 -> V_35 ) -> V_419 ;
F_28 () ;
if ( ! V_418 )
break;
F_33 ( & V_10 -> V_411 , & V_37 , V_42 ) ;
F_12 ( & V_10 -> V_410 ) ;
F_24 () ;
V_180 = F_32 ( V_29 -> V_27 -> V_35 ) -> V_100 * V_44 / 10 ;
F_28 () ;
V_180 = F_36 ( V_180 ) ;
F_11 ( & V_10 -> V_410 ) ;
if ( ! V_180 ) {
V_417 = - V_143 ;
F_45 ( V_10 , L_46 ) ;
break;
}
}
F_12 ( & V_10 -> V_410 ) ;
F_37 ( & V_10 -> V_411 , & V_37 ) ;
return V_417 ;
}
static unsigned long F_221 ( T_7 V_420 )
{
return ( V_420 & V_421 ? V_422 : 0 ) |
( V_420 & V_423 ? V_424 : 0 ) |
( V_420 & V_425 ? V_261 : 0 ) ;
}
static unsigned long F_222 ( T_7 V_420 )
{
if ( V_420 & V_426 )
return V_427 ;
else
return V_379 ;
}
static void F_223 ( struct V_9 * V_10 , T_3 V_52 ,
unsigned int V_64 )
{
struct V_332 * V_6 ;
V_428:
F_208 (i, &device->write_requests, sector, size) {
struct V_361 * V_362 ;
struct V_429 V_430 ;
if ( ! V_6 -> T_5 )
continue;
V_362 = F_189 ( V_6 , struct V_361 , V_6 ) ;
if ( ! ( V_362 -> V_390 & V_392 ) )
continue;
V_362 -> V_390 &= ~ V_392 ;
F_209 ( V_362 , V_431 , & V_430 ) ;
F_21 ( & V_10 -> V_24 -> V_25 ) ;
if ( V_430 . V_244 )
F_224 ( V_10 , & V_430 ) ;
F_20 ( & V_10 -> V_24 -> V_25 ) ;
goto V_428;
}
}
static int F_225 ( struct V_9 * V_10 ,
struct V_18 * V_19 )
{
struct V_26 * V_27 = V_19 -> V_29 -> V_27 ;
bool V_432 = F_69 ( V_205 , & V_27 -> V_69 ) ;
T_3 V_52 = V_19 -> V_6 . V_52 ;
const unsigned int V_64 = V_19 -> V_6 . V_64 ;
struct V_332 * V_6 ;
bool V_433 ;
int V_77 ;
F_226 ( & V_10 -> V_333 , & V_19 -> V_6 ) ;
V_428:
F_208 (i, &device->write_requests, sector, size) {
if ( V_6 == & V_19 -> V_6 )
continue;
if ( V_6 -> V_434 )
continue;
if ( ! V_6 -> T_5 ) {
V_77 = F_227 ( V_10 , V_6 ) ;
if ( V_77 )
goto V_104;
goto V_428;
}
V_433 = V_6 -> V_52 == V_52 && V_6 -> V_64 == V_64 ;
if ( V_432 ) {
bool V_435 = V_6 -> V_52 <= V_52 && V_6 -> V_52 +
( V_6 -> V_64 >> 9 ) >= V_52 + ( V_64 >> 9 ) ;
if ( ! V_433 )
F_228 ( V_10 , L_47
L_48
L_49 ,
( unsigned long long ) V_6 -> V_52 , V_6 -> V_64 ,
( unsigned long long ) V_52 , V_64 ,
V_435 ? L_50 : L_51 ) ;
V_19 -> V_20 . V_80 = V_435 ? F_212 :
F_213 ;
F_165 ( & V_19 -> V_20 . V_21 , & V_10 -> V_78 ) ;
F_229 ( V_27 -> V_225 , & V_19 -> V_29 -> V_436 ) ;
V_77 = - V_437 ;
goto V_104;
} else {
struct V_361 * V_362 =
F_189 ( V_6 , struct V_361 , V_6 ) ;
if ( ! V_433 )
F_228 ( V_10 , L_47
L_52 ,
( unsigned long long ) V_6 -> V_52 , V_6 -> V_64 ,
( unsigned long long ) V_52 , V_64 ) ;
if ( V_362 -> V_390 & V_391 ||
! ( V_362 -> V_390 & V_392 ) ) {
V_77 = F_227 ( V_10 , & V_362 -> V_6 ) ;
if ( V_77 ) {
F_230 ( V_27 , F_72 ( V_105 , V_438 ) , V_107 ) ;
F_223 ( V_10 , V_52 , V_64 ) ;
goto V_104;
}
goto V_428;
}
V_19 -> V_69 |= V_403 ;
}
}
V_77 = 0 ;
V_104:
if ( V_77 )
F_170 ( V_10 , V_19 ) ;
return V_77 ;
}
static int F_231 ( struct V_26 * V_27 , struct V_171 * V_172 )
{
struct V_28 * V_29 ;
struct V_9 * V_10 ;
struct V_35 * V_36 ;
T_3 V_52 ;
struct V_18 * V_19 ;
struct V_385 * V_337 = V_172 -> V_96 ;
T_7 V_184 = F_125 ( V_337 -> V_439 ) ;
int V_317 , V_318 ;
T_7 V_440 ;
int V_77 , V_418 ;
V_29 = F_201 ( V_27 , V_172 -> V_30 ) ;
if ( ! V_29 )
return - V_108 ;
V_10 = V_29 -> V_10 ;
if ( ! F_139 ( V_10 ) ) {
int V_79 ;
V_77 = F_220 ( V_29 , V_184 ) ;
F_206 ( V_29 , V_375 , V_337 , V_172 -> V_64 ) ;
F_135 ( & V_27 -> V_282 -> V_271 ) ;
V_79 = F_184 ( V_29 , V_172 -> V_64 ) ;
if ( ! V_77 )
V_77 = V_79 ;
return V_77 ;
}
V_52 = F_202 ( V_337 -> V_52 ) ;
V_19 = F_176 ( V_29 , V_337 -> V_68 , V_52 , V_172 ) ;
if ( ! V_19 ) {
F_130 ( V_10 ) ;
return - V_108 ;
}
V_19 -> V_20 . V_80 = F_210 ;
V_19 -> V_65 = V_66 ;
V_19 -> V_69 |= V_441 ;
V_440 = F_125 ( V_337 -> V_440 ) ;
V_317 = F_222 ( V_440 ) ;
V_318 = F_221 ( V_440 ) ;
if ( V_172 -> V_169 == V_352 ) {
F_53 ( V_29 , V_19 -> V_6 . V_64 > 0 ) ;
F_53 ( V_29 , V_317 == V_427 ) ;
F_53 ( V_29 , V_19 -> V_67 == NULL ) ;
} else if ( V_19 -> V_67 == NULL ) {
F_53 ( V_10 , V_19 -> V_6 . V_64 == 0 ) ;
F_53 ( V_10 , V_440 & V_425 ) ;
}
if ( V_440 & V_442 )
V_19 -> V_69 |= V_400 ;
F_11 ( & V_27 -> V_274 ) ;
V_19 -> V_268 = V_27 -> V_282 ;
F_135 ( & V_19 -> V_268 -> V_271 ) ;
F_135 ( & V_19 -> V_268 -> V_277 ) ;
F_12 ( & V_27 -> V_274 ) ;
F_24 () ;
V_36 = F_32 ( V_29 -> V_27 -> V_35 ) ;
V_418 = V_36 -> V_419 ;
if ( V_29 -> V_27 -> V_186 < 100 ) {
switch ( V_36 -> V_443 ) {
case V_444 :
V_440 |= V_445 ;
break;
case V_446 :
V_440 |= V_447 ;
break;
}
}
F_28 () ;
if ( V_440 & V_445 ) {
V_19 -> V_69 |= V_396 ;
F_197 ( V_10 ) ;
}
if ( V_440 & V_447 ) {
F_192 ( V_29 , V_448 , V_19 ) ;
}
if ( V_418 ) {
F_53 ( V_10 , V_440 & V_445 ) ;
V_19 -> V_69 |= V_402 ;
V_77 = F_220 ( V_29 , V_184 ) ;
if ( V_77 )
goto V_449;
F_20 ( & V_10 -> V_24 -> V_25 ) ;
V_77 = F_225 ( V_10 , V_19 ) ;
if ( V_77 ) {
F_21 ( & V_10 -> V_24 -> V_25 ) ;
if ( V_77 == - V_437 ) {
F_130 ( V_10 ) ;
return 0 ;
}
goto V_449;
}
} else {
F_216 ( V_29 , V_184 ) ;
F_20 ( & V_10 -> V_24 -> V_25 ) ;
}
if ( ( V_19 -> V_69 & ( V_323 | V_324 ) ) == 0 )
F_165 ( & V_19 -> V_20 . V_21 , & V_10 -> V_326 ) ;
F_21 ( & V_10 -> V_24 -> V_25 ) ;
if ( V_10 -> V_397 . V_105 == V_450 )
F_232 ( V_10 -> V_81 , ! F_218 ( V_10 , V_19 ) ) ;
if ( V_10 -> V_397 . V_451 < V_452 ) {
F_233 ( V_10 , V_19 -> V_6 . V_52 , V_19 -> V_6 . V_64 ) ;
V_19 -> V_69 &= ~ V_400 ;
F_234 ( V_10 , & V_19 -> V_6 ) ;
V_19 -> V_69 |= V_73 ;
}
V_77 = F_163 ( V_10 , V_19 , V_317 , V_318 ,
V_453 ) ;
if ( ! V_77 )
return 0 ;
F_45 ( V_10 , L_43 ) ;
F_20 ( & V_10 -> V_24 -> V_25 ) ;
F_146 ( & V_19 -> V_20 . V_21 ) ;
F_170 ( V_10 , V_19 ) ;
F_21 ( & V_10 -> V_24 -> V_25 ) ;
if ( V_19 -> V_69 & V_73 ) {
V_19 -> V_69 &= ~ V_73 ;
F_56 ( V_10 , & V_19 -> V_6 ) ;
}
V_449:
F_142 ( V_27 , V_19 -> V_268 , V_276 | V_275 ) ;
F_130 ( V_10 ) ;
F_60 ( V_10 , V_19 ) ;
return V_77 ;
}
bool F_235 ( struct V_9 * V_10 , T_3 V_52 ,
bool V_454 )
{
struct V_455 * V_4 ;
bool V_456 = F_236 ( V_10 ) ;
if ( ! V_456 || V_454 )
return V_456 ;
F_20 ( & V_10 -> V_457 ) ;
V_4 = F_237 ( V_10 -> V_458 , F_238 ( V_52 ) ) ;
if ( V_4 ) {
struct V_459 * V_460 = F_239 ( V_4 , struct V_459 , V_461 ) ;
if ( F_69 ( V_462 , & V_460 -> V_69 ) )
V_456 = false ;
}
F_21 ( & V_10 -> V_457 ) ;
return V_456 ;
}
bool F_236 ( struct V_9 * V_10 )
{
struct V_463 * V_464 = V_10 -> V_256 -> V_257 -> V_465 -> V_466 ;
unsigned long V_467 , V_468 , V_469 ;
unsigned int V_470 ;
int V_471 ;
F_24 () ;
V_470 = F_32 ( V_10 -> V_256 -> V_291 ) -> V_470 ;
F_28 () ;
if ( V_470 == 0 )
return false ;
V_471 = ( int ) F_240 ( & V_464 -> V_472 , V_473 [ 0 ] ) +
( int ) F_240 ( & V_464 -> V_472 , V_473 [ 1 ] ) -
F_26 ( & V_10 -> V_378 ) ;
if ( F_26 ( & V_10 -> V_474 )
|| V_471 - V_10 -> V_475 > 64 ) {
unsigned long V_476 ;
int V_6 ;
V_10 -> V_475 = V_471 ;
V_6 = ( V_10 -> V_477 + V_478 - 1 ) % V_478 ;
if ( V_10 -> V_397 . V_105 == V_479 || V_10 -> V_397 . V_105 == V_480 )
V_476 = V_10 -> V_481 ;
else
V_476 = F_241 ( V_10 ) - V_10 -> V_482 ;
V_468 = ( ( long ) V_66 - ( long ) V_10 -> V_483 [ V_6 ] ) / V_44 ;
if ( ! V_468 )
V_468 ++ ;
V_467 = V_10 -> V_484 [ V_6 ] - V_476 ;
V_469 = F_242 ( V_467 / V_468 ) ;
if ( V_469 > V_470 )
return true ;
}
return false ;
}
static int F_243 ( struct V_26 * V_27 , struct V_171 * V_172 )
{
struct V_28 * V_29 ;
struct V_9 * V_10 ;
T_3 V_52 ;
T_3 V_342 ;
struct V_18 * V_19 ;
struct V_485 * V_486 = NULL ;
int V_64 , V_487 ;
unsigned int V_319 ;
struct V_488 * V_337 = V_172 -> V_96 ;
V_29 = F_201 ( V_27 , V_172 -> V_30 ) ;
if ( ! V_29 )
return - V_108 ;
V_10 = V_29 -> V_10 ;
V_342 = F_177 ( V_10 -> V_343 ) ;
V_52 = F_202 ( V_337 -> V_52 ) ;
V_64 = F_125 ( V_337 -> V_489 ) ;
if ( V_64 <= 0 || ! F_181 ( V_64 , 512 ) || V_64 > V_48 ) {
F_45 ( V_10 , L_53 , __FILE__ , __LINE__ ,
( unsigned long long ) V_52 , V_64 ) ;
return - V_234 ;
}
if ( V_52 + ( V_64 >> 9 ) > V_342 ) {
F_45 ( V_10 , L_53 , __FILE__ , __LINE__ ,
( unsigned long long ) V_52 , V_64 ) ;
return - V_234 ;
}
if ( ! F_244 ( V_10 , V_490 ) ) {
V_487 = 1 ;
switch ( V_172 -> V_169 ) {
case V_491 :
F_245 ( V_29 , V_492 , V_337 ) ;
break;
case V_493 :
case V_494 :
case V_495 :
case V_496 :
F_245 ( V_29 , V_497 , V_337 ) ;
break;
case V_498 :
V_487 = 0 ;
F_196 ( V_10 ) ;
F_246 ( V_29 , V_499 , V_52 , V_64 , V_500 ) ;
break;
default:
F_247 () ;
}
if ( V_487 && F_205 ( & V_388 ) )
F_45 ( V_10 , L_54
L_55 ) ;
return F_184 ( V_29 , V_172 -> V_64 ) ;
}
V_19 = F_42 ( V_29 , V_337 -> V_68 , V_52 , V_64 ,
V_64 , V_213 ) ;
if ( ! V_19 ) {
F_130 ( V_10 ) ;
return - V_254 ;
}
switch ( V_172 -> V_169 ) {
case V_491 :
V_19 -> V_20 . V_80 = V_501 ;
V_319 = V_502 ;
V_19 -> V_69 |= V_441 ;
goto V_503;
case V_493 :
V_19 -> V_69 |= V_504 ;
case V_494 :
V_19 -> V_20 . V_80 = V_505 ;
V_319 = V_506 ;
V_10 -> V_507 = F_248 ( V_52 ) ;
break;
case V_498 :
case V_495 :
V_319 = V_506 ;
V_486 = F_134 ( sizeof( * V_486 ) + V_172 -> V_64 , V_213 ) ;
if ( ! V_486 )
goto V_508;
V_486 -> V_344 = V_172 -> V_64 ;
V_486 -> V_71 = ( ( ( char * ) V_486 ) + sizeof( struct V_485 ) ) ;
V_19 -> V_71 = V_486 ;
V_19 -> V_69 |= V_70 ;
if ( F_73 ( V_29 -> V_27 , V_486 -> V_71 , V_172 -> V_64 ) )
goto V_508;
if ( V_172 -> V_169 == V_495 ) {
F_53 ( V_10 , V_29 -> V_27 -> V_186 >= 89 ) ;
V_19 -> V_20 . V_80 = V_509 ;
V_10 -> V_507 = F_248 ( V_52 ) ;
V_10 -> V_510 = true ;
} else if ( V_172 -> V_169 == V_498 ) {
F_38 ( V_64 >> 9 , & V_10 -> V_389 ) ;
V_19 -> V_20 . V_80 = V_511 ;
F_196 ( V_10 ) ;
goto V_512;
}
break;
case V_496 :
if ( V_10 -> V_513 == ~ ( T_3 ) 0 &&
V_29 -> V_27 -> V_186 >= 90 ) {
unsigned long V_514 = V_66 ;
int V_6 ;
V_10 -> V_513 = V_52 ;
V_10 -> V_515 = V_52 ;
V_10 -> V_481 = F_249 ( V_10 ) - F_248 ( V_52 ) ;
V_10 -> V_516 = V_10 -> V_481 ;
for ( V_6 = 0 ; V_6 < V_478 ; V_6 ++ ) {
V_10 -> V_484 [ V_6 ] = V_10 -> V_481 ;
V_10 -> V_483 [ V_6 ] = V_514 ;
}
F_68 ( V_10 , L_56 ,
( unsigned long long ) V_52 ) ;
}
V_19 -> V_20 . V_80 = V_517 ;
V_319 = V_506 ;
break;
default:
F_247 () ;
}
F_20 ( & V_10 -> V_24 -> V_25 ) ;
F_165 ( & V_19 -> V_20 . V_21 , & V_10 -> V_518 ) ;
F_21 ( & V_10 -> V_24 -> V_25 ) ;
F_250 ( V_27 , F_235 ) ;
if ( V_10 -> V_397 . V_519 != V_520
&& F_235 ( V_10 , V_52 , false ) )
F_251 ( V_44 / 10 ) ;
F_250 ( V_27 , V_521 ) ;
if ( V_521 ( V_10 , V_52 ) )
goto V_508;
V_512:
F_38 ( V_64 >> 9 , & V_10 -> V_378 ) ;
V_503:
F_250 ( V_27 , F_163 ) ;
F_197 ( V_10 ) ;
if ( F_163 ( V_10 , V_19 , V_522 , 0 ,
V_319 ) == 0 )
return 0 ;
F_45 ( V_10 , L_43 ) ;
V_508:
F_20 ( & V_10 -> V_24 -> V_25 ) ;
F_146 ( & V_19 -> V_20 . V_21 ) ;
F_21 ( & V_10 -> V_24 -> V_25 ) ;
F_130 ( V_10 ) ;
F_60 ( V_10 , V_19 ) ;
return - V_108 ;
}
static int F_252 ( struct V_28 * V_29 ) __must_hold( T_5 )
{
struct V_9 * V_10 = V_29 -> V_10 ;
int V_523 , V_519 , V_95 = - 100 ;
unsigned long V_524 , V_525 ;
enum V_526 V_527 ;
V_523 = V_10 -> V_256 -> V_528 . V_529 [ V_530 ] & 1 ;
V_519 = V_10 -> V_531 [ V_530 ] & 1 ;
V_525 = V_10 -> V_531 [ V_532 ] ;
V_524 = V_10 -> V_533 ;
F_24 () ;
V_527 = F_32 ( V_29 -> V_27 -> V_35 ) -> V_527 ;
F_28 () ;
switch ( V_527 ) {
case V_534 :
case V_535 :
case V_536 :
case V_537 :
F_45 ( V_10 , L_57 ) ;
break;
case V_538 :
break;
case V_539 :
if ( V_523 == 0 && V_519 == 1 ) {
V_95 = - 1 ;
break;
}
if ( V_523 == 1 && V_519 == 0 ) {
V_95 = 1 ;
break;
}
case V_540 :
if ( V_523 == 0 && V_519 == 1 ) {
V_95 = 1 ;
break;
}
if ( V_523 == 1 && V_519 == 0 ) {
V_95 = - 1 ;
break;
}
F_35 ( V_10 , L_58
L_59 ) ;
case V_541 :
if ( V_525 == 0 && V_524 == 0 ) {
V_95 = F_69 ( V_205 , & V_29 -> V_27 -> V_69 )
? - 1 : 1 ;
break;
} else {
if ( V_525 == 0 ) { V_95 = 1 ; break; }
if ( V_524 == 0 ) { V_95 = - 1 ; break; }
}
if ( V_527 == V_541 )
break;
case V_542 :
if ( V_524 < V_525 )
V_95 = - 1 ;
else if ( V_524 > V_525 )
V_95 = 1 ;
else
V_95 = F_69 ( V_205 , & V_29 -> V_27 -> V_69 )
? - 1 : 1 ;
break;
case V_543 :
V_95 = - 1 ;
break;
case V_544 :
V_95 = 1 ;
}
return V_95 ;
}
static int F_253 ( struct V_28 * V_29 ) __must_hold( T_5 )
{
struct V_9 * V_10 = V_29 -> V_10 ;
int V_545 , V_95 = - 100 ;
enum V_526 V_546 ;
F_24 () ;
V_546 = F_32 ( V_29 -> V_27 -> V_35 ) -> V_546 ;
F_28 () ;
switch ( V_546 ) {
case V_539 :
case V_540 :
case V_542 :
case V_543 :
case V_544 :
case V_541 :
F_45 ( V_10 , L_57 ) ;
break;
case V_538 :
break;
case V_534 :
V_545 = F_252 ( V_29 ) ;
if ( V_545 == - 1 && V_10 -> V_397 . V_547 == V_548 )
V_95 = V_545 ;
if ( V_545 == 1 && V_10 -> V_397 . V_547 == V_520 )
V_95 = V_545 ;
break;
case V_537 :
V_95 = F_252 ( V_29 ) ;
break;
case V_535 :
return V_10 -> V_397 . V_547 == V_520 ? 1 : - 1 ;
case V_536 :
V_545 = F_252 ( V_29 ) ;
if ( V_545 == - 1 && V_10 -> V_397 . V_547 == V_520 ) {
enum V_196 V_549 ;
V_549 = F_254 ( V_10 , V_198 , F_72 ( V_547 , V_548 ) ) ;
if ( V_549 != V_199 ) {
F_255 ( V_10 , L_60 ) ;
} else {
F_35 ( V_10 , L_61 ) ;
V_95 = V_545 ;
}
} else
V_95 = V_545 ;
}
return V_95 ;
}
static int F_256 ( struct V_28 * V_29 ) __must_hold( T_5 )
{
struct V_9 * V_10 = V_29 -> V_10 ;
int V_545 , V_95 = - 100 ;
enum V_526 V_550 ;
F_24 () ;
V_550 = F_32 ( V_29 -> V_27 -> V_35 ) -> V_550 ;
F_28 () ;
switch ( V_550 ) {
case V_539 :
case V_540 :
case V_542 :
case V_543 :
case V_544 :
case V_534 :
case V_535 :
case V_541 :
F_45 ( V_10 , L_57 ) ;
break;
case V_537 :
V_95 = F_252 ( V_29 ) ;
break;
case V_538 :
break;
case V_536 :
V_545 = F_252 ( V_29 ) ;
if ( V_545 == - 1 ) {
enum V_196 V_549 ;
V_549 = F_254 ( V_10 , V_198 , F_72 ( V_547 , V_548 ) ) ;
if ( V_549 != V_199 ) {
F_255 ( V_10 , L_60 ) ;
} else {
F_35 ( V_10 , L_61 ) ;
V_95 = V_545 ;
}
} else
V_95 = V_545 ;
}
return V_95 ;
}
static void F_257 ( struct V_9 * V_10 , char * V_551 , T_2 * V_529 ,
T_2 V_552 , T_2 V_69 )
{
if ( ! V_529 ) {
F_68 ( V_10 , L_62 , V_551 ) ;
return;
}
F_68 ( V_10 , L_63 ,
V_551 ,
( unsigned long long ) V_529 [ V_553 ] ,
( unsigned long long ) V_529 [ V_530 ] ,
( unsigned long long ) V_529 [ V_554 ] ,
( unsigned long long ) V_529 [ V_555 ] ,
( unsigned long long ) V_552 ,
( unsigned long long ) V_69 ) ;
}
static int F_258 ( struct V_9 * const V_10 , enum V_556 const V_557 , int * V_558 ) __must_hold( T_5 )
{
struct V_28 * const V_29 = F_259 ( V_10 ) ;
struct V_26 * const V_27 = V_29 ? V_29 -> V_27 : NULL ;
T_2 V_523 , V_519 ;
int V_6 , V_559 ;
V_523 = V_10 -> V_256 -> V_528 . V_529 [ V_553 ] & ~ ( ( T_2 ) 1 ) ;
V_519 = V_10 -> V_531 [ V_553 ] & ~ ( ( T_2 ) 1 ) ;
* V_558 = 10 ;
if ( V_523 == V_560 && V_519 == V_560 )
return 0 ;
* V_558 = 20 ;
if ( ( V_523 == V_560 || V_523 == ( T_2 ) 0 ) &&
V_519 != V_560 )
return - 2 ;
* V_558 = 30 ;
if ( V_523 != V_560 &&
( V_519 == V_560 || V_519 == ( T_2 ) 0 ) )
return 2 ;
if ( V_523 == V_519 ) {
int V_561 , V_292 ;
if ( V_10 -> V_531 [ V_530 ] == ( T_2 ) 0 && V_10 -> V_256 -> V_528 . V_529 [ V_530 ] != ( T_2 ) 0 ) {
if ( V_27 -> V_186 < 91 )
return - 1091 ;
if ( ( V_10 -> V_256 -> V_528 . V_529 [ V_530 ] & ~ ( ( T_2 ) 1 ) ) == ( V_10 -> V_531 [ V_554 ] & ~ ( ( T_2 ) 1 ) ) &&
( V_10 -> V_256 -> V_528 . V_529 [ V_554 ] & ~ ( ( T_2 ) 1 ) ) == ( V_10 -> V_531 [ V_554 + 1 ] & ~ ( ( T_2 ) 1 ) ) ) {
F_68 ( V_10 , L_64 ) ;
F_260 ( V_10 ) ;
V_10 -> V_256 -> V_528 . V_529 [ V_554 ] = V_10 -> V_256 -> V_528 . V_529 [ V_530 ] ;
V_10 -> V_256 -> V_528 . V_529 [ V_530 ] = 0 ;
F_257 ( V_10 , L_65 , V_10 -> V_256 -> V_528 . V_529 ,
V_10 -> V_397 . V_464 >= V_562 ? F_241 ( V_10 ) : 0 , 0 ) ;
* V_558 = 34 ;
} else {
F_68 ( V_10 , L_66 ) ;
* V_558 = 36 ;
}
return 1 ;
}
if ( V_10 -> V_256 -> V_528 . V_529 [ V_530 ] == ( T_2 ) 0 && V_10 -> V_531 [ V_530 ] != ( T_2 ) 0 ) {
if ( V_27 -> V_186 < 91 )
return - 1091 ;
if ( ( V_10 -> V_256 -> V_528 . V_529 [ V_554 ] & ~ ( ( T_2 ) 1 ) ) == ( V_10 -> V_531 [ V_530 ] & ~ ( ( T_2 ) 1 ) ) &&
( V_10 -> V_256 -> V_528 . V_529 [ V_554 + 1 ] & ~ ( ( T_2 ) 1 ) ) == ( V_10 -> V_531 [ V_554 ] & ~ ( ( T_2 ) 1 ) ) ) {
F_68 ( V_10 , L_67 ) ;
V_10 -> V_531 [ V_554 + 1 ] = V_10 -> V_531 [ V_554 ] ;
V_10 -> V_531 [ V_554 ] = V_10 -> V_531 [ V_530 ] ;
V_10 -> V_531 [ V_530 ] = 0UL ;
F_257 ( V_10 , L_68 , V_10 -> V_531 , V_10 -> V_531 [ V_532 ] , V_10 -> V_531 [ V_563 ] ) ;
* V_558 = 35 ;
} else {
F_68 ( V_10 , L_69 ) ;
* V_558 = 37 ;
}
return - 1 ;
}
V_561 = ( F_69 ( V_564 , & V_10 -> V_69 ) ? 1 : 0 ) +
( V_10 -> V_531 [ V_563 ] & 2 ) ;
* V_558 = 40 ;
if ( V_561 == 0 )
return 0 ;
if ( V_10 -> V_397 . V_547 == V_520 || V_557 == V_520 ) {
* V_558 = 41 ;
if ( ! ( V_27 -> V_565 & V_566 ) ) {
F_35 ( V_29 , L_70 ) ;
return - ( 0x10000 | V_567 | ( V_566 << 8 ) ) ;
}
if ( V_10 -> V_397 . V_547 == V_520 && V_557 == V_520 ) {
F_45 ( V_29 , L_71 ) ;
return - 100 ;
}
if ( V_10 -> V_397 . V_547 == V_520 )
return 1 ;
return - 1 ;
}
switch ( V_561 ) {
case 0 : return 0 ;
case 1 : return 1 ;
case 2 : return - 1 ;
case 3 :
V_292 = F_69 ( V_205 , & V_27 -> V_69 ) ;
return V_292 ? - 1 : 1 ;
}
}
* V_558 = 50 ;
V_519 = V_10 -> V_531 [ V_530 ] & ~ ( ( T_2 ) 1 ) ;
if ( V_523 == V_519 )
return - 1 ;
* V_558 = 51 ;
V_519 = V_10 -> V_531 [ V_554 ] & ~ ( ( T_2 ) 1 ) ;
if ( V_523 == V_519 ) {
if ( V_27 -> V_186 < 96 ?
( V_10 -> V_256 -> V_528 . V_529 [ V_554 ] & ~ ( ( T_2 ) 1 ) ) ==
( V_10 -> V_531 [ V_554 + 1 ] & ~ ( ( T_2 ) 1 ) ) :
V_519 + V_568 == ( V_10 -> V_531 [ V_530 ] & ~ ( ( T_2 ) 1 ) ) ) {
if ( V_27 -> V_186 < 91 )
return - 1091 ;
V_10 -> V_531 [ V_530 ] = V_10 -> V_531 [ V_554 ] ;
V_10 -> V_531 [ V_554 ] = V_10 -> V_531 [ V_554 + 1 ] ;
F_68 ( V_10 , L_72 ) ;
F_257 ( V_10 , L_68 , V_10 -> V_531 , V_10 -> V_531 [ V_532 ] , V_10 -> V_531 [ V_563 ] ) ;
return - 1 ;
}
}
* V_558 = 60 ;
V_523 = V_10 -> V_256 -> V_528 . V_529 [ V_553 ] & ~ ( ( T_2 ) 1 ) ;
for ( V_6 = V_554 ; V_6 <= V_555 ; V_6 ++ ) {
V_519 = V_10 -> V_531 [ V_6 ] & ~ ( ( T_2 ) 1 ) ;
if ( V_523 == V_519 )
return - 2 ;
}
* V_558 = 70 ;
V_523 = V_10 -> V_256 -> V_528 . V_529 [ V_530 ] & ~ ( ( T_2 ) 1 ) ;
V_519 = V_10 -> V_531 [ V_553 ] & ~ ( ( T_2 ) 1 ) ;
if ( V_523 == V_519 )
return 1 ;
* V_558 = 71 ;
V_523 = V_10 -> V_256 -> V_528 . V_529 [ V_554 ] & ~ ( ( T_2 ) 1 ) ;
if ( V_523 == V_519 ) {
if ( V_27 -> V_186 < 96 ?
( V_10 -> V_256 -> V_528 . V_529 [ V_554 + 1 ] & ~ ( ( T_2 ) 1 ) ) ==
( V_10 -> V_531 [ V_554 ] & ~ ( ( T_2 ) 1 ) ) :
V_523 + V_568 == ( V_10 -> V_256 -> V_528 . V_529 [ V_530 ] & ~ ( ( T_2 ) 1 ) ) ) {
if ( V_27 -> V_186 < 91 )
return - 1091 ;
F_261 ( V_10 , V_530 , V_10 -> V_256 -> V_528 . V_529 [ V_554 ] ) ;
F_261 ( V_10 , V_554 , V_10 -> V_256 -> V_528 . V_529 [ V_554 + 1 ] ) ;
F_68 ( V_10 , L_73 ) ;
F_257 ( V_10 , L_65 , V_10 -> V_256 -> V_528 . V_529 ,
V_10 -> V_397 . V_464 >= V_562 ? F_241 ( V_10 ) : 0 , 0 ) ;
return 1 ;
}
}
* V_558 = 80 ;
V_519 = V_10 -> V_531 [ V_553 ] & ~ ( ( T_2 ) 1 ) ;
for ( V_6 = V_554 ; V_6 <= V_555 ; V_6 ++ ) {
V_523 = V_10 -> V_256 -> V_528 . V_529 [ V_6 ] & ~ ( ( T_2 ) 1 ) ;
if ( V_523 == V_519 )
return 2 ;
}
* V_558 = 90 ;
V_523 = V_10 -> V_256 -> V_528 . V_529 [ V_530 ] & ~ ( ( T_2 ) 1 ) ;
V_519 = V_10 -> V_531 [ V_530 ] & ~ ( ( T_2 ) 1 ) ;
if ( V_523 == V_519 && V_523 != ( ( T_2 ) 0 ) )
return 100 ;
* V_558 = 100 ;
for ( V_6 = V_554 ; V_6 <= V_555 ; V_6 ++ ) {
V_523 = V_10 -> V_256 -> V_528 . V_529 [ V_6 ] & ~ ( ( T_2 ) 1 ) ;
for ( V_559 = V_554 ; V_559 <= V_555 ; V_559 ++ ) {
V_519 = V_10 -> V_531 [ V_559 ] & ~ ( ( T_2 ) 1 ) ;
if ( V_523 == V_519 )
return - 100 ;
}
}
return - 1000 ;
}
static enum V_569 F_262 ( struct V_28 * V_29 ,
enum V_556 V_557 ,
enum V_570 V_571 ) __must_hold( T_5 )
{
struct V_9 * V_10 = V_29 -> V_10 ;
enum V_569 V_95 = V_572 ;
enum V_570 V_573 ;
struct V_35 * V_36 ;
int V_545 , V_558 , V_574 , V_575 ;
V_573 = V_10 -> V_397 . V_464 ;
if ( V_573 == V_562 )
V_573 = V_10 -> V_576 . V_464 ;
F_68 ( V_10 , L_74 ) ;
F_20 ( & V_10 -> V_256 -> V_528 . V_577 ) ;
F_257 ( V_10 , L_65 , V_10 -> V_256 -> V_528 . V_529 , V_10 -> V_533 , 0 ) ;
F_257 ( V_10 , L_68 , V_10 -> V_531 ,
V_10 -> V_531 [ V_532 ] , V_10 -> V_531 [ V_563 ] ) ;
V_545 = F_258 ( V_10 , V_557 , & V_558 ) ;
F_21 ( & V_10 -> V_256 -> V_528 . V_577 ) ;
F_68 ( V_10 , L_75 , V_545 , V_558 ) ;
if ( V_545 == - 1000 ) {
F_228 ( V_10 , L_76 ) ;
return V_572 ;
}
if ( V_545 < - 0x10000 ) {
int V_578 , V_579 ;
V_545 = - V_545 ;
V_578 = V_545 & 0xff ;
V_579 = ( V_545 >> 8 ) & 0xff ;
F_228 ( V_10 , L_77 ,
V_578 , V_579 ) ;
return V_572 ;
}
if ( V_545 < - 1000 ) {
F_228 ( V_10 , L_78 , - V_545 - 1000 ) ;
return V_572 ;
}
if ( ( V_573 == V_452 && V_571 > V_452 ) ||
( V_571 == V_452 && V_573 > V_452 ) ) {
int V_580 = ( V_545 == - 100 ) || abs ( V_545 ) == 2 ;
V_545 = V_573 > V_452 ? 1 : - 1 ;
if ( V_580 )
V_545 = V_545 * 2 ;
F_68 ( V_10 , L_79 ,
V_545 > 0 ? L_80 : L_81 ) ;
}
if ( abs ( V_545 ) == 100 )
F_255 ( V_10 , L_82 ) ;
F_24 () ;
V_36 = F_32 ( V_29 -> V_27 -> V_35 ) ;
if ( V_545 == 100 || ( V_545 == - 100 && V_36 -> V_581 ) ) {
int V_582 = ( V_10 -> V_397 . V_547 == V_520 )
+ ( V_557 == V_520 ) ;
int V_583 = ( V_545 == - 100 ) ;
switch ( V_582 ) {
case 0 :
V_545 = F_252 ( V_29 ) ;
break;
case 1 :
V_545 = F_253 ( V_29 ) ;
break;
case 2 :
V_545 = F_256 ( V_29 ) ;
break;
}
if ( abs ( V_545 ) < 100 ) {
F_35 ( V_10 , L_83
L_84 ,
V_582 , ( V_545 < 0 ) ? L_68 : L_85 ) ;
if ( V_583 ) {
F_35 ( V_10 , L_86
L_87 ) ;
V_545 = V_545 * 2 ;
}
}
}
if ( V_545 == - 100 ) {
if ( F_69 ( V_223 , & V_10 -> V_69 ) && ! ( V_10 -> V_531 [ V_563 ] & 1 ) )
V_545 = - 1 ;
if ( ! F_69 ( V_223 , & V_10 -> V_69 ) && ( V_10 -> V_531 [ V_563 ] & 1 ) )
V_545 = 1 ;
if ( abs ( V_545 ) < 100 )
F_35 ( V_10 , L_88
L_89 ,
( V_545 < 0 ) ? L_68 : L_85 ) ;
}
V_574 = V_36 -> V_574 ;
V_575 = V_36 -> V_575 ;
F_28 () ;
if ( V_545 == - 100 ) {
F_228 ( V_10 , L_90 ) ;
F_255 ( V_10 , L_91 ) ;
return V_572 ;
}
if ( V_545 > 0 && V_573 <= V_452 ) {
F_45 ( V_10 , L_92 ) ;
return V_572 ;
}
if ( V_545 < 0 &&
V_10 -> V_397 . V_547 == V_520 && V_10 -> V_397 . V_464 >= V_584 ) {
switch ( V_574 ) {
case V_536 :
F_255 ( V_10 , L_93 ) ;
case V_538 :
F_45 ( V_10 , L_94 ) ;
return V_572 ;
case V_537 :
F_35 ( V_10 , L_95
L_96 ) ;
}
}
if ( V_575 || F_69 ( V_585 , & V_29 -> V_27 -> V_69 ) ) {
if ( V_545 == 0 )
F_68 ( V_10 , L_97 ) ;
else
F_68 ( V_10 , L_98 ,
F_263 ( V_545 > 0 ? V_398 : V_450 ) ,
abs ( V_545 ) >= 2 ? L_99 : L_100 ) ;
return V_572 ;
}
if ( abs ( V_545 ) >= 2 ) {
F_68 ( V_10 , L_101 ) ;
if ( F_264 ( V_10 , & V_586 , L_102 ,
V_587 ) )
return V_572 ;
}
if ( V_545 > 0 ) {
V_95 = V_588 ;
} else if ( V_545 < 0 ) {
V_95 = V_589 ;
} else {
V_95 = V_590 ;
if ( F_241 ( V_10 ) ) {
F_68 ( V_10 , L_103 ,
F_241 ( V_10 ) ) ;
}
}
return V_95 ;
}
static enum V_526 F_265 ( enum V_526 V_519 )
{
if ( V_519 == V_544 )
return V_543 ;
if ( V_519 == V_543 )
return V_544 ;
return V_519 ;
}
static int F_266 ( struct V_26 * V_27 , struct V_171 * V_172 )
{
struct V_591 * V_337 = V_172 -> V_96 ;
enum V_526 V_592 , V_593 , V_594 ;
int V_595 , V_596 , V_597 , V_598 ;
struct V_35 * V_36 , * V_599 , * V_600 = NULL ;
char V_601 [ V_602 ] = L_104 ;
struct V_339 * V_355 = NULL ;
void * V_347 = NULL , * V_349 = NULL ;
V_595 = F_125 ( V_337 -> V_603 ) ;
V_592 = F_125 ( V_337 -> V_527 ) ;
V_593 = F_125 ( V_337 -> V_546 ) ;
V_594 = F_125 ( V_337 -> V_550 ) ;
V_597 = F_125 ( V_337 -> V_419 ) ;
V_598 = F_125 ( V_337 -> V_604 ) ;
V_596 = V_598 & V_605 ;
if ( V_27 -> V_186 >= 87 ) {
int V_77 ;
if ( V_172 -> V_64 > sizeof( V_601 ) )
return - V_108 ;
V_77 = F_73 ( V_27 , V_601 , V_172 -> V_64 ) ;
if ( V_77 )
return V_77 ;
V_601 [ V_602 - 1 ] = 0 ;
}
if ( V_172 -> V_169 != V_606 ) {
F_106 ( V_585 , & V_27 -> V_69 ) ;
if ( V_598 & V_607 )
F_111 ( V_585 , & V_27 -> V_69 ) ;
F_24 () ;
V_36 = F_32 ( V_27 -> V_35 ) ;
if ( V_595 != V_36 -> V_443 ) {
F_45 ( V_27 , L_105 , L_106 ) ;
goto V_608;
}
if ( F_265 ( V_592 ) != V_36 -> V_527 ) {
F_45 ( V_27 , L_105 , L_107 ) ;
goto V_608;
}
if ( F_265 ( V_593 ) != V_36 -> V_546 ) {
F_45 ( V_27 , L_105 , L_108 ) ;
goto V_608;
}
if ( F_265 ( V_594 ) != V_36 -> V_550 ) {
F_45 ( V_27 , L_105 , L_109 ) ;
goto V_608;
}
if ( V_596 && V_36 -> V_195 ) {
F_45 ( V_27 , L_105 , L_110 ) ;
goto V_608;
}
if ( V_597 != V_36 -> V_419 ) {
F_45 ( V_27 , L_105 , L_111 ) ;
goto V_608;
}
if ( strcmp ( V_601 , V_36 -> V_601 ) ) {
F_45 ( V_27 , L_105 , L_112 ) ;
goto V_608;
}
F_28 () ;
}
if ( V_601 [ 0 ] ) {
int V_609 ;
V_355 = F_267 ( V_601 , 0 , V_610 ) ;
if ( F_268 ( V_355 ) ) {
V_355 = NULL ;
F_45 ( V_27 , L_113 ,
V_601 ) ;
goto V_611;
}
V_609 = F_178 ( V_355 ) ;
V_347 = F_134 ( V_609 , V_612 ) ;
V_349 = F_134 ( V_609 , V_612 ) ;
if ( ! ( V_347 && V_349 ) ) {
F_45 ( V_27 , L_114 ) ;
goto V_611;
}
}
V_600 = F_134 ( sizeof( struct V_35 ) , V_612 ) ;
if ( ! V_600 ) {
F_45 ( V_27 , L_115 ) ;
goto V_611;
}
F_119 ( & V_27 -> V_96 . V_200 ) ;
F_119 ( & V_27 -> V_24 -> V_228 ) ;
V_599 = V_27 -> V_35 ;
* V_600 = * V_599 ;
V_600 -> V_443 = V_595 ;
V_600 -> V_527 = F_265 ( V_592 ) ;
V_600 -> V_546 = F_265 ( V_593 ) ;
V_600 -> V_550 = F_265 ( V_594 ) ;
V_600 -> V_419 = V_597 ;
F_269 ( V_27 -> V_35 , V_600 ) ;
F_120 ( & V_27 -> V_24 -> V_228 ) ;
F_120 ( & V_27 -> V_96 . V_200 ) ;
F_270 ( V_27 -> V_355 ) ;
F_52 ( V_27 -> V_347 ) ;
F_52 ( V_27 -> V_349 ) ;
V_27 -> V_355 = V_355 ;
V_27 -> V_347 = V_347 ;
V_27 -> V_349 = V_349 ;
if ( strcmp ( V_599 -> V_601 , V_601 ) )
F_68 ( V_27 , L_116 ,
V_601 [ 0 ] ? V_601 : L_117 ) ;
F_271 () ;
F_52 ( V_599 ) ;
return 0 ;
V_608:
F_28 () ;
V_611:
F_270 ( V_355 ) ;
F_52 ( V_347 ) ;
F_52 ( V_349 ) ;
F_71 ( V_27 , F_72 ( V_105 , V_151 ) , V_107 ) ;
return - V_108 ;
}
static struct V_339 * F_272 ( const struct V_9 * V_10 ,
const char * V_613 , const char * V_227 )
{
struct V_339 * V_614 ;
if ( ! V_613 [ 0 ] )
return NULL ;
V_614 = F_267 ( V_613 , 0 , V_610 ) ;
if ( F_268 ( V_614 ) ) {
F_45 ( V_10 , L_118 ,
V_613 , V_227 , F_273 ( V_614 ) ) ;
return V_614 ;
}
return V_614 ;
}
static int F_274 ( struct V_26 * V_27 , struct V_171 * V_172 )
{
void * V_243 = V_27 -> V_96 . V_173 ;
int V_64 = V_172 -> V_64 ;
while ( V_64 ) {
int V_203 = F_77 ( int , V_64 , V_615 ) ;
V_203 = F_67 ( V_27 , V_243 , V_203 ) ;
if ( V_203 <= 0 ) {
if ( V_203 < 0 )
return V_203 ;
break;
}
V_64 -= V_203 ;
}
if ( V_64 )
return - V_108 ;
return 0 ;
}
static int F_275 ( struct V_26 * V_27 , struct V_171 * V_172 )
{
F_35 ( V_27 , L_119 ,
F_276 ( V_172 -> V_169 ) , V_172 -> V_30 ) ;
return F_274 ( V_27 , V_172 ) ;
}
static int F_277 ( struct V_26 * V_27 , struct V_171 * V_172 )
{
struct V_28 * V_29 ;
struct V_9 * V_10 ;
struct V_616 * V_337 ;
unsigned int V_170 , V_321 , V_617 ;
struct V_339 * V_618 = NULL ;
struct V_339 * V_619 = NULL ;
struct V_35 * V_599 , * V_600 = NULL ;
struct V_291 * V_620 = NULL , * V_621 = NULL ;
const int V_622 = V_27 -> V_186 ;
struct V_623 * V_624 = NULL , * V_625 = NULL ;
int V_626 = 0 ;
int V_77 ;
V_29 = F_201 ( V_27 , V_172 -> V_30 ) ;
if ( ! V_29 )
return F_275 ( V_27 , V_172 ) ;
V_10 = V_29 -> V_10 ;
V_617 = V_622 <= 87 ? sizeof( struct V_627 )
: V_622 == 88 ? sizeof( struct V_627 )
+ V_602
: V_622 <= 94 ? sizeof( struct V_628 )
: sizeof( struct V_616 ) ;
if ( V_172 -> V_64 > V_617 ) {
F_45 ( V_10 , L_120 ,
V_172 -> V_64 , V_617 ) ;
return - V_108 ;
}
if ( V_622 <= 88 ) {
V_170 = sizeof( struct V_627 ) ;
V_321 = V_172 -> V_64 - V_170 ;
} else if ( V_622 <= 94 ) {
V_170 = sizeof( struct V_628 ) ;
V_321 = V_172 -> V_64 - V_170 ;
F_53 ( V_10 , V_321 == 0 ) ;
} else {
V_170 = sizeof( struct V_616 ) ;
V_321 = V_172 -> V_64 - V_170 ;
F_53 ( V_10 , V_321 == 0 ) ;
}
V_337 = V_172 -> V_96 ;
memset ( V_337 -> V_629 , 0 , 2 * V_602 ) ;
V_77 = F_73 ( V_29 -> V_27 , V_337 , V_170 ) ;
if ( V_77 )
return V_77 ;
F_119 ( & V_27 -> V_24 -> V_228 ) ;
V_599 = V_29 -> V_27 -> V_35 ;
if ( F_139 ( V_10 ) ) {
V_621 = F_278 ( sizeof( struct V_291 ) , V_612 ) ;
if ( ! V_621 ) {
F_130 ( V_10 ) ;
F_120 ( & V_27 -> V_24 -> V_228 ) ;
F_45 ( V_10 , L_121 ) ;
return - V_254 ;
}
V_620 = V_10 -> V_256 -> V_291 ;
* V_621 = * V_620 ;
V_621 -> V_630 = F_125 ( V_337 -> V_630 ) ;
}
if ( V_622 >= 88 ) {
if ( V_622 == 88 ) {
if ( V_321 > V_602 || V_321 == 0 ) {
F_45 ( V_10 , L_122
L_123 ,
V_321 , V_602 ) ;
V_77 = - V_108 ;
goto V_631;
}
V_77 = F_73 ( V_29 -> V_27 , V_337 -> V_629 , V_321 ) ;
if ( V_77 )
goto V_631;
F_53 ( V_10 , V_337 -> V_629 [ V_321 - 1 ] == 0 ) ;
V_337 -> V_629 [ V_321 - 1 ] = 0 ;
} else {
F_53 ( V_10 , V_337 -> V_629 [ V_602 - 1 ] == 0 ) ;
F_53 ( V_10 , V_337 -> V_632 [ V_602 - 1 ] == 0 ) ;
V_337 -> V_629 [ V_602 - 1 ] = 0 ;
V_337 -> V_632 [ V_602 - 1 ] = 0 ;
}
if ( strcmp ( V_599 -> V_629 , V_337 -> V_629 ) ) {
if ( V_10 -> V_397 . V_105 == V_103 ) {
F_45 ( V_10 , L_124 ,
V_599 -> V_629 , V_337 -> V_629 ) ;
goto V_611;
}
V_618 = F_272 ( V_10 ,
V_337 -> V_629 , L_125 ) ;
if ( F_268 ( V_618 ) ) {
V_618 = NULL ;
goto V_611;
}
}
if ( V_622 >= 89 && strcmp ( V_599 -> V_632 , V_337 -> V_632 ) ) {
if ( V_10 -> V_397 . V_105 == V_103 ) {
F_45 ( V_10 , L_126 ,
V_599 -> V_632 , V_337 -> V_632 ) ;
goto V_611;
}
V_619 = F_272 ( V_10 ,
V_337 -> V_632 , L_127 ) ;
if ( F_268 ( V_619 ) ) {
V_619 = NULL ;
goto V_611;
}
}
if ( V_622 > 94 && V_621 ) {
V_621 -> V_633 = F_125 ( V_337 -> V_633 ) ;
V_621 -> V_634 = F_125 ( V_337 -> V_634 ) ;
V_621 -> V_635 = F_125 ( V_337 -> V_635 ) ;
V_621 -> V_636 = F_125 ( V_337 -> V_636 ) ;
V_626 = ( V_621 -> V_633 * 10 * V_637 ) / V_44 ;
if ( V_626 != V_10 -> V_638 -> V_64 ) {
V_625 = F_279 ( V_626 ) ;
if ( ! V_625 ) {
F_45 ( V_10 , L_128 ) ;
F_130 ( V_10 ) ;
goto V_611;
}
}
}
if ( V_618 || V_619 ) {
V_600 = F_278 ( sizeof( struct V_35 ) , V_612 ) ;
if ( ! V_600 ) {
F_45 ( V_10 , L_115 ) ;
goto V_611;
}
* V_600 = * V_599 ;
if ( V_618 ) {
strcpy ( V_600 -> V_629 , V_337 -> V_629 ) ;
V_600 -> V_639 = strlen ( V_337 -> V_629 ) + 1 ;
F_270 ( V_29 -> V_27 -> V_618 ) ;
V_29 -> V_27 -> V_618 = V_618 ;
F_68 ( V_10 , L_129 , V_337 -> V_629 ) ;
}
if ( V_619 ) {
strcpy ( V_600 -> V_632 , V_337 -> V_632 ) ;
V_600 -> V_640 = strlen ( V_337 -> V_632 ) + 1 ;
F_270 ( V_29 -> V_27 -> V_619 ) ;
V_29 -> V_27 -> V_619 = V_619 ;
F_68 ( V_10 , L_130 , V_337 -> V_632 ) ;
}
F_269 ( V_27 -> V_35 , V_600 ) ;
}
}
if ( V_621 ) {
F_269 ( V_10 -> V_256 -> V_291 , V_621 ) ;
F_130 ( V_10 ) ;
}
if ( V_625 ) {
V_624 = V_10 -> V_638 ;
F_269 ( V_10 -> V_638 , V_625 ) ;
}
F_120 ( & V_27 -> V_24 -> V_228 ) ;
F_271 () ;
if ( V_600 )
F_52 ( V_599 ) ;
F_52 ( V_620 ) ;
F_52 ( V_624 ) ;
return 0 ;
V_631:
if ( V_621 ) {
F_130 ( V_10 ) ;
F_52 ( V_621 ) ;
}
F_120 ( & V_27 -> V_24 -> V_228 ) ;
return - V_108 ;
V_611:
F_52 ( V_625 ) ;
if ( V_621 ) {
F_130 ( V_10 ) ;
F_52 ( V_621 ) ;
}
F_120 ( & V_27 -> V_24 -> V_228 ) ;
F_270 ( V_619 ) ;
F_270 ( V_618 ) ;
F_71 ( V_29 -> V_27 , F_72 ( V_105 , V_151 ) , V_107 ) ;
return - V_108 ;
}
static void F_280 ( struct V_9 * V_10 ,
const char * V_203 , T_3 V_47 , T_3 V_407 )
{
T_3 V_341 ;
if ( V_47 == 0 || V_407 == 0 )
return;
V_341 = ( V_47 > V_407 ) ? ( V_47 - V_407 ) : ( V_407 - V_47 ) ;
if ( V_341 > ( V_47 >> 3 ) || V_341 > ( V_407 >> 3 ) )
F_35 ( V_10 , L_131 , V_203 ,
( unsigned long long ) V_47 , ( unsigned long long ) V_407 ) ;
}
static int F_281 ( struct V_26 * V_27 , struct V_171 * V_172 )
{
struct V_28 * V_29 ;
struct V_9 * V_10 ;
struct V_641 * V_337 = V_172 -> V_96 ;
struct V_642 * V_643 = ( V_27 -> V_565 & V_566 ) ? V_337 -> V_644 : NULL ;
enum V_645 V_646 = V_647 ;
T_3 V_648 , V_649 , V_650 , V_651 ;
int V_652 = 0 ;
enum V_653 V_654 ;
V_29 = F_201 ( V_27 , V_172 -> V_30 ) ;
if ( ! V_29 )
return F_275 ( V_27 , V_172 ) ;
V_10 = V_29 -> V_10 ;
V_648 = F_202 ( V_337 -> V_655 ) ;
V_649 = F_202 ( V_337 -> V_656 ) ;
V_650 = F_202 ( V_337 -> V_657 ) ;
V_10 -> V_648 = V_648 ;
if ( F_139 ( V_10 ) ) {
T_3 V_658 , V_659 ;
F_24 () ;
V_651 = F_32 ( V_10 -> V_256 -> V_291 ) -> V_660 ;
F_28 () ;
F_280 ( V_10 , L_132 ,
V_648 , F_282 ( V_10 -> V_256 ) ) ;
F_280 ( V_10 , L_133 ,
V_649 , V_651 ) ;
if ( V_10 -> V_397 . V_105 == V_103 )
V_649 = F_283 ( V_651 , V_649 ) ;
V_658 = F_284 ( V_10 , V_10 -> V_256 , V_649 , 0 ) ;
V_659 = F_177 ( V_10 -> V_343 ) ;
if ( V_658 < V_659 &&
V_10 -> V_397 . V_464 >= V_661 &&
V_10 -> V_397 . V_105 < V_590 ) {
F_45 ( V_10 , L_134 ,
( unsigned long long ) V_658 , ( unsigned long long ) V_659 ) ;
F_71 ( V_29 -> V_27 , F_72 ( V_105 , V_151 ) , V_107 ) ;
F_130 ( V_10 ) ;
return - V_108 ;
}
if ( V_651 != V_649 ) {
struct V_291 * V_620 , * V_621 = NULL ;
V_621 = F_278 ( sizeof( struct V_291 ) , V_612 ) ;
if ( ! V_621 ) {
F_45 ( V_10 , L_121 ) ;
F_130 ( V_10 ) ;
return - V_254 ;
}
F_119 ( & V_27 -> V_24 -> V_228 ) ;
V_620 = V_10 -> V_256 -> V_291 ;
* V_621 = * V_620 ;
V_621 -> V_660 = V_649 ;
F_269 ( V_10 -> V_256 -> V_291 , V_621 ) ;
F_120 ( & V_27 -> V_24 -> V_228 ) ;
F_271 () ;
F_52 ( V_620 ) ;
F_68 ( V_10 , L_135 ,
( unsigned long ) V_651 ) ;
}
F_130 ( V_10 ) ;
}
V_10 -> V_662 = F_125 ( V_337 -> V_663 ) ;
V_654 = F_124 ( V_337 -> V_653 ) ;
if ( F_139 ( V_10 ) ) {
F_285 ( V_10 , V_10 -> V_256 , V_643 ) ;
V_646 = F_286 ( V_10 , V_654 , NULL ) ;
F_130 ( V_10 ) ;
if ( V_646 == V_664 )
return - V_108 ;
F_287 ( V_10 ) ;
} else {
F_285 ( V_10 , NULL , V_643 ) ;
F_288 ( V_10 , V_650 ? : V_649 ? : V_648 ) ;
}
if ( F_139 ( V_10 ) ) {
if ( V_10 -> V_256 -> V_665 != F_177 ( V_10 -> V_256 -> V_257 ) ) {
V_10 -> V_256 -> V_665 = F_177 ( V_10 -> V_256 -> V_257 ) ;
V_652 = 1 ;
}
F_130 ( V_10 ) ;
}
if ( V_10 -> V_397 . V_105 > V_103 ) {
if ( F_202 ( V_337 -> V_657 ) !=
F_177 ( V_10 -> V_343 ) || V_652 ) {
F_103 ( V_29 , 0 , V_654 ) ;
}
if ( F_289 ( V_190 , & V_10 -> V_69 ) ||
( V_646 == V_666 && V_10 -> V_397 . V_105 == V_590 ) ) {
if ( V_10 -> V_397 . V_451 >= V_452 &&
V_10 -> V_397 . V_464 >= V_452 ) {
if ( V_654 & V_667 )
F_68 ( V_10 , L_136 ) ;
else
F_290 ( V_10 ) ;
} else
F_111 ( V_668 , & V_10 -> V_69 ) ;
}
}
return 0 ;
}
static int F_291 ( struct V_26 * V_27 , struct V_171 * V_172 )
{
struct V_28 * V_29 ;
struct V_9 * V_10 ;
struct V_669 * V_337 = V_172 -> V_96 ;
T_2 * V_531 ;
int V_6 , V_670 = 0 ;
V_29 = F_201 ( V_27 , V_172 -> V_30 ) ;
if ( ! V_29 )
return F_275 ( V_27 , V_172 ) ;
V_10 = V_29 -> V_10 ;
V_531 = F_134 ( sizeof( T_2 ) * V_671 , V_213 ) ;
if ( ! V_531 ) {
F_45 ( V_10 , L_137 ) ;
return false ;
}
for ( V_6 = V_553 ; V_6 < V_671 ; V_6 ++ )
V_531 [ V_6 ] = F_202 ( V_337 -> V_529 [ V_6 ] ) ;
F_52 ( V_10 -> V_531 ) ;
V_10 -> V_531 = V_531 ;
if ( V_10 -> V_397 . V_105 < V_590 &&
V_10 -> V_397 . V_464 < V_452 &&
V_10 -> V_397 . V_547 == V_520 &&
( V_10 -> V_672 & ~ ( ( T_2 ) 1 ) ) != ( V_531 [ V_553 ] & ~ ( ( T_2 ) 1 ) ) ) {
F_45 ( V_10 , L_138 ,
( unsigned long long ) V_10 -> V_672 ) ;
F_71 ( V_29 -> V_27 , F_72 ( V_105 , V_151 ) , V_107 ) ;
return - V_108 ;
}
if ( F_139 ( V_10 ) ) {
int V_673 =
V_10 -> V_397 . V_105 == V_590 &&
V_29 -> V_27 -> V_186 >= 90 &&
V_10 -> V_256 -> V_528 . V_529 [ V_553 ] == V_560 &&
( V_531 [ V_563 ] & 8 ) ;
if ( V_673 ) {
F_68 ( V_10 , L_139 ) ;
F_264 ( V_10 , & V_674 ,
L_140 ,
V_675 ) ;
F_292 ( V_10 , V_553 , V_531 [ V_553 ] ) ;
F_292 ( V_10 , V_530 , 0 ) ;
F_293 ( F_294 ( V_10 , V_464 , V_490 , V_451 , V_490 ) ,
V_198 , NULL ) ;
F_287 ( V_10 ) ;
V_670 = 1 ;
}
F_130 ( V_10 ) ;
} else if ( V_10 -> V_397 . V_464 < V_452 &&
V_10 -> V_397 . V_547 == V_520 ) {
V_670 = F_295 ( V_10 , V_531 [ V_553 ] ) ;
}
F_119 ( V_10 -> V_185 ) ;
F_120 ( V_10 -> V_185 ) ;
if ( V_10 -> V_397 . V_105 >= V_590 && V_10 -> V_397 . V_464 < V_452 )
V_670 |= F_295 ( V_10 , V_531 [ V_553 ] ) ;
if ( V_670 )
F_296 ( V_10 , L_141 ) ;
return 0 ;
}
static union V_676 F_297 ( union V_676 V_677 )
{
union V_676 V_678 ;
static enum V_569 V_679 [] = {
[ V_103 ] = V_103 ,
[ V_590 ] = V_590 ,
[ V_680 ] = V_681 ,
[ V_681 ] = V_680 ,
[ V_151 ] = V_682 ,
[ V_479 ] = V_480 ,
[ V_572 ] = V_572 ,
} ;
V_678 . V_6 = V_677 . V_6 ;
V_678 . V_105 = V_679 [ V_677 . V_105 ] ;
V_678 . V_519 = V_677 . V_547 ;
V_678 . V_547 = V_677 . V_519 ;
V_678 . V_451 = V_677 . V_464 ;
V_678 . V_464 = V_677 . V_451 ;
V_678 . V_683 = ( V_677 . V_684 | V_677 . V_685 ) ;
return V_678 ;
}
static int F_298 ( struct V_26 * V_27 , struct V_171 * V_172 )
{
struct V_28 * V_29 ;
struct V_9 * V_10 ;
struct V_686 * V_337 = V_172 -> V_96 ;
union V_676 V_687 , V_688 ;
enum V_196 V_95 ;
V_29 = F_201 ( V_27 , V_172 -> V_30 ) ;
if ( ! V_29 )
return - V_108 ;
V_10 = V_29 -> V_10 ;
V_687 . V_6 = F_125 ( V_337 -> V_687 ) ;
V_688 . V_6 = F_125 ( V_337 -> V_688 ) ;
if ( F_69 ( V_205 , & V_29 -> V_27 -> V_69 ) &&
F_299 ( V_10 -> V_185 ) ) {
F_300 ( V_29 , V_689 ) ;
return 0 ;
}
V_687 = F_297 ( V_687 ) ;
V_688 = F_297 ( V_688 ) ;
V_95 = F_254 ( V_10 , V_198 , V_687 , V_688 ) ;
F_300 ( V_29 , V_95 ) ;
F_287 ( V_10 ) ;
return 0 ;
}
static int F_301 ( struct V_26 * V_27 , struct V_171 * V_172 )
{
struct V_686 * V_337 = V_172 -> V_96 ;
union V_676 V_687 , V_688 ;
enum V_196 V_95 ;
V_687 . V_6 = F_125 ( V_337 -> V_687 ) ;
V_688 . V_6 = F_125 ( V_337 -> V_688 ) ;
if ( F_69 ( V_205 , & V_27 -> V_69 ) &&
F_299 ( & V_27 -> V_187 ) ) {
F_302 ( V_27 , V_689 ) ;
return 0 ;
}
V_687 = F_297 ( V_687 ) ;
V_688 = F_297 ( V_688 ) ;
V_95 = F_71 ( V_27 , V_687 , V_688 , V_198 | V_690 | V_691 ) ;
F_302 ( V_27 , V_95 ) ;
return 0 ;
}
static int F_303 ( struct V_26 * V_27 , struct V_171 * V_172 )
{
struct V_28 * V_29 ;
struct V_9 * V_10 ;
struct V_692 * V_337 = V_172 -> V_96 ;
union V_676 V_693 , V_694 , V_695 ;
enum V_570 V_696 ;
enum V_697 V_698 ;
int V_95 ;
V_29 = F_201 ( V_27 , V_172 -> V_30 ) ;
if ( ! V_29 )
return F_275 ( V_27 , V_172 ) ;
V_10 = V_29 -> V_10 ;
V_695 . V_6 = F_125 ( V_337 -> V_397 ) ;
V_696 = V_695 . V_464 ;
if ( V_695 . V_464 == V_562 ) {
V_696 = V_10 -> V_531 [ V_563 ] & 4 ? V_452 : V_584 ;
F_68 ( V_10 , L_142 , F_304 ( V_696 ) ) ;
}
F_20 ( & V_10 -> V_24 -> V_25 ) ;
V_34:
V_693 = V_694 = F_305 ( V_10 ) ;
F_21 ( & V_10 -> V_24 -> V_25 ) ;
if ( V_693 . V_105 <= V_682 )
return - V_97 ;
if ( ( V_693 . V_451 == V_452 || V_693 . V_451 == V_584 ) &&
V_696 == V_490 &&
V_693 . V_105 > V_590 && V_693 . V_464 == V_490 ) {
if ( V_695 . V_105 > V_590 &&
V_695 . V_105 < V_398 )
V_696 = V_452 ;
else if ( V_693 . V_105 >= V_398 &&
V_695 . V_105 == V_590 ) {
if ( F_241 ( V_10 ) <= V_10 -> V_482 )
F_306 ( V_10 ) ;
return 0 ;
}
}
if ( V_693 . V_105 == V_480 && V_693 . V_464 == V_490 &&
V_695 . V_105 == V_590 && V_696 == V_490 ) {
F_307 ( V_10 ) ;
F_306 ( V_10 ) ;
return 0 ;
}
if ( V_693 . V_451 == V_490 && V_696 == V_452 &&
V_693 . V_105 == V_590 && V_695 . V_105 > V_398 )
V_696 = V_490 ;
if ( V_694 . V_105 == V_103 )
V_694 . V_105 = V_590 ;
if ( V_695 . V_105 == V_699 )
V_694 . V_105 = V_700 ;
if ( V_10 -> V_531 && V_695 . V_464 >= V_562 &&
F_244 ( V_10 , V_562 ) ) {
int V_701 ;
V_701 = ( V_693 . V_105 < V_590 ) ;
V_701 |= ( V_693 . V_105 == V_590 &&
( V_695 . V_464 == V_562 ||
V_693 . V_464 == V_562 ) ) ;
V_701 |= F_69 ( V_702 , & V_10 -> V_69 ) ;
V_701 |= ( V_693 . V_105 == V_590 &&
( V_695 . V_105 >= V_680 &&
V_695 . V_105 <= V_589 ) ) ;
if ( V_701 )
V_694 . V_105 = F_262 ( V_29 , V_695 . V_547 , V_696 ) ;
F_130 ( V_10 ) ;
if ( V_694 . V_105 == V_572 ) {
V_694 . V_105 = V_590 ;
if ( V_10 -> V_397 . V_464 == V_562 ) {
F_308 ( V_10 , F_72 ( V_464 , V_703 ) ) ;
} else if ( V_695 . V_464 == V_562 ) {
F_45 ( V_10 , L_143 ) ;
V_695 . V_464 = V_704 ;
V_696 = V_704 ;
} else {
if ( F_289 ( V_585 , & V_29 -> V_27 -> V_69 ) )
return - V_108 ;
F_53 ( V_10 , V_693 . V_105 == V_103 ) ;
F_71 ( V_29 -> V_27 , F_72 ( V_105 , V_151 ) , V_107 ) ;
return - V_108 ;
}
}
}
F_20 ( & V_10 -> V_24 -> V_25 ) ;
if ( V_693 . V_6 != F_305 ( V_10 ) . V_6 )
goto V_34;
F_106 ( V_702 , & V_10 -> V_69 ) ;
V_694 . V_519 = V_695 . V_547 ;
V_694 . V_451 = V_696 ;
V_694 . V_683 = ( V_695 . V_684 | V_695 . V_685 ) ;
if ( ( V_694 . V_105 == V_590 || V_694 . V_105 == V_588 ) && V_694 . V_464 == V_562 )
V_694 . V_464 = V_10 -> V_576 . V_464 ;
V_698 = V_198 + ( V_693 . V_105 < V_590 && V_694 . V_105 >= V_590 ? 0 : V_107 ) ;
if ( V_694 . V_451 == V_584 && F_309 ( V_10 ) && V_694 . V_105 == V_590 && V_693 . V_105 < V_590 &&
F_69 ( V_705 , & V_10 -> V_69 ) ) {
F_21 ( & V_10 -> V_24 -> V_25 ) ;
F_45 ( V_10 , L_144 ) ;
F_310 ( V_29 -> V_27 ) ;
F_311 ( V_10 ) ;
F_106 ( V_705 , & V_10 -> V_69 ) ;
F_71 ( V_29 -> V_27 , F_312 ( V_105 , V_706 , V_707 , 0 ) , V_107 ) ;
return - V_108 ;
}
V_95 = F_293 ( V_10 , V_694 , V_698 , NULL ) ;
V_694 = F_305 ( V_10 ) ;
F_21 ( & V_10 -> V_24 -> V_25 ) ;
if ( V_95 < V_199 ) {
F_71 ( V_29 -> V_27 , F_72 ( V_105 , V_151 ) , V_107 ) ;
return - V_108 ;
}
if ( V_693 . V_105 > V_103 ) {
if ( V_694 . V_105 > V_590 && V_695 . V_105 <= V_590 &&
V_695 . V_464 != V_562 ) {
F_104 ( V_29 ) ;
F_105 ( V_29 ) ;
}
}
F_106 ( V_223 , & V_10 -> V_69 ) ;
F_287 ( V_10 ) ;
return 0 ;
}
static int F_313 ( struct V_26 * V_27 , struct V_171 * V_172 )
{
struct V_28 * V_29 ;
struct V_9 * V_10 ;
struct V_708 * V_337 = V_172 -> V_96 ;
V_29 = F_201 ( V_27 , V_172 -> V_30 ) ;
if ( ! V_29 )
return - V_108 ;
V_10 = V_29 -> V_10 ;
F_232 ( V_10 -> V_335 ,
V_10 -> V_397 . V_105 == V_709 ||
V_10 -> V_397 . V_105 == V_700 ||
V_10 -> V_397 . V_105 < V_590 ||
V_10 -> V_397 . V_464 < V_562 ) ;
if ( F_244 ( V_10 , V_562 ) ) {
F_292 ( V_10 , V_553 , F_202 ( V_337 -> V_529 ) ) ;
F_292 ( V_10 , V_530 , 0UL ) ;
F_296 ( V_10 , L_145 ) ;
F_314 ( V_10 , V_450 ) ;
F_130 ( V_10 ) ;
} else
F_45 ( V_10 , L_146 ) ;
return 0 ;
}
static int
F_315 ( struct V_28 * V_29 , unsigned int V_64 ,
unsigned long * V_337 , struct V_710 * V_711 )
{
unsigned int V_321 = V_615 -
F_95 ( V_29 -> V_27 ) ;
unsigned int V_712 = F_77 ( T_6 , V_321 / sizeof( * V_337 ) ,
V_711 -> V_713 - V_711 -> V_714 ) ;
unsigned int V_715 = V_712 * sizeof( * V_337 ) ;
int V_77 ;
if ( V_715 != V_64 ) {
F_45 ( V_29 , L_147 , V_62 , V_715 , V_64 ) ;
return - V_108 ;
}
if ( V_715 == 0 )
return 0 ;
V_77 = F_73 ( V_29 -> V_27 , V_337 , V_715 ) ;
if ( V_77 )
return V_77 ;
F_316 ( V_29 -> V_10 , V_711 -> V_714 , V_712 , V_337 ) ;
V_711 -> V_714 += V_712 ;
V_711 -> V_716 = V_711 -> V_714 * V_717 ;
if ( V_711 -> V_716 > V_711 -> V_718 )
V_711 -> V_716 = V_711 -> V_718 ;
return 1 ;
}
static enum V_719 F_317 ( struct V_720 * V_337 )
{
return (enum V_719 ) ( V_337 -> V_721 & 0x0f ) ;
}
static int F_318 ( struct V_720 * V_337 )
{
return ( V_337 -> V_721 & 0x80 ) != 0 ;
}
static int F_319 ( struct V_720 * V_337 )
{
return ( V_337 -> V_721 >> 4 ) & 0x7 ;
}
static int
F_320 ( struct V_28 * V_29 ,
struct V_720 * V_337 ,
struct V_710 * V_711 ,
unsigned int V_5 )
{
struct V_722 V_723 ;
T_2 V_724 ;
T_2 V_725 ;
T_2 V_4 ;
unsigned long V_203 = V_711 -> V_716 ;
unsigned long V_726 ;
int V_727 = F_318 ( V_337 ) ;
int V_728 ;
int V_552 ;
F_321 ( & V_723 , V_337 -> V_729 , V_5 , F_319 ( V_337 ) ) ;
V_552 = F_322 ( & V_723 , & V_724 , 64 ) ;
if ( V_552 < 0 )
return - V_108 ;
for ( V_728 = V_552 ; V_728 > 0 ; V_203 += V_725 , V_727 = ! V_727 ) {
V_552 = F_323 ( & V_725 , V_724 ) ;
if ( V_552 <= 0 )
return - V_108 ;
if ( V_727 ) {
V_726 = V_203 + V_725 - 1 ;
if ( V_726 >= V_711 -> V_718 ) {
F_45 ( V_29 , L_148 , V_726 ) ;
return - V_108 ;
}
F_324 ( V_29 -> V_10 , V_203 , V_726 ) ;
}
if ( V_728 < V_552 ) {
F_45 ( V_29 , L_149 ,
V_728 , V_552 , V_724 ,
( unsigned int ) ( V_723 . V_730 . V_407 - V_337 -> V_729 ) ,
( unsigned int ) V_723 . V_731 ) ;
return - V_108 ;
}
if ( F_190 ( V_552 < 64 ) )
V_724 >>= V_552 ;
else
V_724 = 0 ;
V_728 -= V_552 ;
V_552 = F_322 ( & V_723 , & V_4 , 64 - V_728 ) ;
if ( V_552 < 0 )
return - V_108 ;
V_724 |= V_4 << V_728 ;
V_728 += V_552 ;
}
V_711 -> V_716 = V_203 ;
F_325 ( V_711 ) ;
return ( V_203 != V_711 -> V_718 ) ;
}
static int
F_326 ( struct V_28 * V_29 ,
struct V_720 * V_337 ,
struct V_710 * V_711 ,
unsigned int V_5 )
{
if ( F_317 ( V_337 ) == V_732 )
return F_320 ( V_29 , V_337 , V_711 , V_5 - sizeof( * V_337 ) ) ;
F_45 ( V_29 , L_150 , V_337 -> V_721 ) ;
F_71 ( V_29 -> V_27 , F_72 ( V_105 , V_706 ) , V_107 ) ;
return - V_108 ;
}
void F_327 ( struct V_9 * V_10 ,
const char * V_733 , struct V_710 * V_711 )
{
unsigned int V_170 = F_95 ( F_259 ( V_10 ) -> V_27 ) ;
unsigned int V_321 = V_615 - V_170 ;
unsigned int V_734 =
V_170 * ( F_328 ( V_711 -> V_713 , V_321 ) + 1 ) +
V_711 -> V_713 * sizeof( unsigned long ) ;
unsigned int V_735 = V_711 -> V_736 [ 0 ] + V_711 -> V_736 [ 1 ] ;
unsigned int V_340 ;
if ( V_735 == 0 )
return;
if ( V_735 >= V_734 )
return;
V_340 = ( V_735 > V_45 / 1000 ) ? ( V_735 / ( V_734 / 1000 ) )
: ( 1000 * V_735 / V_734 ) ;
if ( V_340 > 1000 )
V_340 = 1000 ;
V_340 = 1000 - V_340 ;
F_68 ( V_10 , L_151
L_152 ,
V_733 ,
V_711 -> V_736 [ 1 ] , V_711 -> V_737 [ 1 ] ,
V_711 -> V_736 [ 0 ] , V_711 -> V_737 [ 0 ] ,
V_735 , V_340 / 10 , V_340 % 10 ) ;
}
static int F_329 ( struct V_26 * V_27 , struct V_171 * V_172 )
{
struct V_28 * V_29 ;
struct V_9 * V_10 ;
struct V_710 V_711 ;
int V_77 ;
V_29 = F_201 ( V_27 , V_172 -> V_30 ) ;
if ( ! V_29 )
return - V_108 ;
V_10 = V_29 -> V_10 ;
F_330 ( V_10 , L_153 , V_587 ) ;
V_711 = (struct V_710 ) {
. V_718 = F_249 ( V_10 ) ,
. V_713 = F_331 ( V_10 ) ,
} ;
for(; ; ) {
if ( V_172 -> V_169 == V_738 )
V_77 = F_315 ( V_29 , V_172 -> V_64 , V_172 -> V_96 , & V_711 ) ;
else if ( V_172 -> V_169 == V_739 ) {
struct V_720 * V_337 = V_172 -> V_96 ;
if ( V_172 -> V_64 > V_615 - F_95 ( V_27 ) ) {
F_45 ( V_10 , L_154 ) ;
V_77 = - V_108 ;
goto V_104;
}
if ( V_172 -> V_64 <= sizeof( * V_337 ) ) {
F_45 ( V_10 , L_155 , V_172 -> V_64 ) ;
V_77 = - V_108 ;
goto V_104;
}
V_77 = F_73 ( V_29 -> V_27 , V_337 , V_172 -> V_64 ) ;
if ( V_77 )
goto V_104;
V_77 = F_326 ( V_29 , V_337 , & V_711 , V_172 -> V_64 ) ;
} else {
F_35 ( V_10 , L_156 , V_172 -> V_169 ) ;
V_77 = - V_108 ;
goto V_104;
}
V_711 . V_737 [ V_172 -> V_169 == V_738 ] ++ ;
V_711 . V_736 [ V_172 -> V_169 == V_738 ] += F_95 ( V_27 ) + V_172 -> V_64 ;
if ( V_77 <= 0 ) {
if ( V_77 < 0 )
goto V_104;
break;
}
V_77 = F_127 ( V_29 -> V_27 , V_172 ) ;
if ( V_77 )
goto V_104;
}
F_327 ( V_10 , L_157 , & V_711 ) ;
if ( V_10 -> V_397 . V_105 == V_589 ) {
enum V_196 V_95 ;
V_77 = F_332 ( V_10 ) ;
if ( V_77 )
goto V_104;
V_95 = F_333 ( V_10 , F_72 ( V_105 , V_709 ) , V_198 ) ;
F_53 ( V_10 , V_95 == V_199 ) ;
} else if ( V_10 -> V_397 . V_105 != V_588 ) {
F_68 ( V_10 , L_158 ,
F_263 ( V_10 -> V_397 . V_105 ) ) ;
}
V_77 = 0 ;
V_104:
F_334 ( V_10 ) ;
if ( ! V_77 && V_10 -> V_397 . V_105 == V_588 )
F_314 ( V_10 , V_398 ) ;
return V_77 ;
}
static int F_335 ( struct V_26 * V_27 , struct V_171 * V_172 )
{
F_35 ( V_27 , L_159 ,
V_172 -> V_169 , V_172 -> V_64 ) ;
return F_274 ( V_27 , V_172 ) ;
}
static int F_336 ( struct V_26 * V_27 , struct V_171 * V_172 )
{
F_337 ( V_27 -> V_96 . V_83 ) ;
return 0 ;
}
static int F_338 ( struct V_26 * V_27 , struct V_171 * V_172 )
{
struct V_28 * V_29 ;
struct V_9 * V_10 ;
struct V_740 * V_337 = V_172 -> V_96 ;
V_29 = F_201 ( V_27 , V_172 -> V_30 ) ;
if ( ! V_29 )
return - V_108 ;
V_10 = V_29 -> V_10 ;
switch ( V_10 -> V_397 . V_105 ) {
case V_709 :
case V_589 :
case V_700 :
break;
default:
F_45 ( V_10 , L_160 ,
F_263 ( V_10 -> V_397 . V_105 ) ) ;
}
F_233 ( V_10 , F_202 ( V_337 -> V_52 ) , F_125 ( V_337 -> V_489 ) ) ;
return 0 ;
}
static int F_339 ( struct V_26 * V_27 , struct V_171 * V_172 )
{
struct V_28 * V_29 ;
struct V_740 * V_337 = V_172 -> V_96 ;
struct V_9 * V_10 ;
T_3 V_52 ;
int V_64 , V_77 = 0 ;
V_29 = F_201 ( V_27 , V_172 -> V_30 ) ;
if ( ! V_29 )
return - V_108 ;
V_10 = V_29 -> V_10 ;
V_52 = F_202 ( V_337 -> V_52 ) ;
V_64 = F_125 ( V_337 -> V_489 ) ;
F_196 ( V_10 ) ;
if ( F_139 ( V_10 ) ) {
struct V_18 * V_19 ;
const int V_317 = V_427 ;
V_19 = F_42 ( V_29 , V_376 , V_52 ,
V_64 , 0 , V_213 ) ;
if ( ! V_19 ) {
F_130 ( V_10 ) ;
return - V_254 ;
}
V_19 -> V_20 . V_80 = F_188 ;
V_19 -> V_65 = V_66 ;
V_19 -> V_69 |= V_323 ;
F_20 ( & V_10 -> V_24 -> V_25 ) ;
F_165 ( & V_19 -> V_20 . V_21 , & V_10 -> V_377 ) ;
F_21 ( & V_10 -> V_24 -> V_25 ) ;
F_38 ( V_172 -> V_64 >> 9 , & V_10 -> V_378 ) ;
V_77 = F_163 ( V_10 , V_19 , V_317 , 0 , V_380 ) ;
if ( V_77 ) {
F_20 ( & V_10 -> V_24 -> V_25 ) ;
F_146 ( & V_19 -> V_20 . V_21 ) ;
F_21 ( & V_10 -> V_24 -> V_25 ) ;
F_60 ( V_10 , V_19 ) ;
F_130 ( V_10 ) ;
V_77 = 0 ;
goto V_63;
}
F_197 ( V_10 ) ;
} else {
V_63:
F_340 ( V_10 , V_52 ) ;
F_246 ( V_29 , V_375 , V_52 , V_64 , V_376 ) ;
}
F_38 ( V_64 >> 9 , & V_10 -> V_389 ) ;
return V_77 ;
}
static void F_341 ( struct V_26 * V_27 )
{
struct V_171 V_172 ;
T_6 V_741 ;
int V_77 ;
while ( F_114 ( & V_27 -> V_210 ) == V_742 ) {
struct V_743 const * V_169 ;
F_342 ( & V_27 -> V_210 ) ;
F_250 ( V_27 , F_127 ) ;
if ( F_127 ( V_27 , & V_172 ) )
goto V_744;
V_169 = & V_745 [ V_172 . V_169 ] ;
if ( F_153 ( V_172 . V_169 >= F_343 ( V_745 ) || ! V_169 -> V_746 ) ) {
F_45 ( V_27 , L_161 ,
F_276 ( V_172 . V_169 ) , V_172 . V_169 ) ;
goto V_744;
}
V_741 = V_169 -> V_747 ;
if ( V_172 . V_169 == V_748 && V_27 -> V_565 & V_566 )
V_741 += sizeof( struct V_642 ) ;
if ( V_172 . V_64 > V_741 && ! V_169 -> V_749 ) {
F_45 ( V_27 , L_162 ,
F_276 ( V_172 . V_169 ) , V_172 . V_64 ) ;
goto V_744;
}
if ( V_172 . V_64 < V_741 ) {
F_45 ( V_27 , L_163 ,
F_276 ( V_172 . V_169 ) , ( int ) V_741 , V_172 . V_64 ) ;
goto V_744;
}
if ( V_741 ) {
F_250 ( V_27 , F_74 ) ;
V_77 = F_74 ( V_27 , V_172 . V_96 , V_741 ) ;
if ( V_77 )
goto V_744;
V_172 . V_64 -= V_741 ;
}
F_250 ( V_27 , V_169 -> V_746 ) ;
V_77 = V_169 -> V_746 ( V_27 , & V_172 ) ;
if ( V_77 ) {
F_45 ( V_27 , L_164 ,
F_276 ( V_172 . V_169 ) , V_77 , V_172 . V_64 ) ;
goto V_744;
}
}
return;
V_744:
F_71 ( V_27 , F_72 ( V_105 , V_706 ) , V_107 ) ;
}
static void F_344 ( struct V_26 * V_27 )
{
struct V_28 * V_29 ;
enum V_569 V_750 ;
int V_30 ;
if ( V_27 -> V_102 == V_751 )
return;
F_71 ( V_27 , F_72 ( V_105 , V_752 ) , V_107 ) ;
F_345 ( & V_27 -> V_224 ) ;
if ( V_27 -> V_225 ) {
F_346 ( V_27 -> V_225 ) ;
V_27 -> V_225 = NULL ;
}
F_347 ( V_27 ) ;
F_24 () ;
F_25 (&connection->peer_devices, peer_device, vnr) {
struct V_9 * V_10 = V_29 -> V_10 ;
F_27 ( & V_10 -> V_32 ) ;
F_28 () ;
F_348 ( V_29 ) ;
F_29 ( & V_10 -> V_32 , V_33 ) ;
F_24 () ;
}
F_28 () ;
if ( ! F_62 ( & V_27 -> V_282 -> V_21 ) )
F_45 ( V_27 , L_165 ) ;
F_101 ( & V_27 -> V_282 -> V_271 , 0 ) ;
V_27 -> V_753 . V_754 = false ;
F_68 ( V_27 , L_166 ) ;
if ( F_349 ( V_27 ) == V_520 && F_350 ( V_27 ) >= V_755 )
F_351 ( V_27 ) ;
F_20 ( & V_27 -> V_24 -> V_25 ) ;
V_750 = V_27 -> V_102 ;
if ( V_750 >= V_756 )
F_230 ( V_27 , F_72 ( V_105 , V_756 ) , V_198 ) ;
F_21 ( & V_27 -> V_24 -> V_25 ) ;
if ( V_750 == V_151 )
F_71 ( V_27 , F_72 ( V_105 , V_751 ) , V_198 | V_107 ) ;
}
static int F_348 ( struct V_28 * V_29 )
{
struct V_9 * V_10 = V_29 -> V_10 ;
unsigned int V_6 ;
F_20 ( & V_10 -> V_24 -> V_25 ) ;
F_61 ( V_10 , & V_10 -> V_326 ) ;
F_61 ( V_10 , & V_10 -> V_377 ) ;
F_61 ( V_10 , & V_10 -> V_518 ) ;
F_21 ( & V_10 -> V_24 -> V_25 ) ;
F_352 ( V_10 ) ;
V_10 -> V_516 = 0 ;
V_10 -> V_482 = 0 ;
F_101 ( & V_10 -> V_757 , 0 ) ;
F_41 ( & V_10 -> V_335 ) ;
F_353 ( & V_10 -> V_758 ) ;
F_354 ( ( unsigned long ) V_10 ) ;
F_355 ( & V_29 -> V_27 -> V_759 ) ;
F_59 ( V_10 ) ;
F_355 ( & V_29 -> V_27 -> V_759 ) ;
F_352 ( V_10 ) ;
F_52 ( V_10 -> V_531 ) ;
V_10 -> V_531 = NULL ;
if ( ! F_309 ( V_10 ) )
F_310 ( V_29 -> V_27 ) ;
F_287 ( V_10 ) ;
if ( F_139 ( V_10 ) ) {
F_264 ( V_10 , & V_760 ,
L_167 , V_761 ) ;
F_130 ( V_10 ) ;
}
V_6 = F_57 ( V_10 , & V_10 -> V_76 ) ;
if ( V_6 )
F_68 ( V_10 , L_168 , V_6 ) ;
V_6 = F_26 ( & V_10 -> V_31 ) ;
if ( V_6 )
F_68 ( V_10 , L_169 , V_6 ) ;
V_6 = F_26 ( & V_10 -> V_40 ) ;
if ( V_6 )
F_68 ( V_10 , L_170 , V_6 ) ;
F_53 ( V_10 , F_62 ( & V_10 -> V_518 ) ) ;
F_53 ( V_10 , F_62 ( & V_10 -> V_326 ) ) ;
F_53 ( V_10 , F_62 ( & V_10 -> V_377 ) ) ;
F_53 ( V_10 , F_62 ( & V_10 -> V_78 ) ) ;
return 0 ;
}
static int F_356 ( struct V_26 * V_27 )
{
struct V_167 * V_84 ;
struct V_762 * V_337 ;
V_84 = & V_27 -> V_96 ;
V_337 = F_92 ( V_27 , V_84 ) ;
if ( ! V_337 )
return - V_108 ;
memset ( V_337 , 0 , sizeof( * V_337 ) ) ;
V_337 -> V_763 = F_123 ( V_764 ) ;
V_337 -> V_765 = F_123 ( V_567 ) ;
V_337 -> V_766 = F_123 ( V_767 ) ;
return F_93 ( V_27 , V_84 , V_768 , sizeof( * V_337 ) , NULL , 0 ) ;
}
static int F_116 ( struct V_26 * V_27 )
{
struct V_762 * V_337 ;
const int F_55 = sizeof( struct V_762 ) ;
struct V_171 V_172 ;
int V_77 ;
V_77 = F_356 ( V_27 ) ;
if ( V_77 )
return 0 ;
V_77 = F_127 ( V_27 , & V_172 ) ;
if ( V_77 )
return 0 ;
if ( V_172 . V_169 != V_768 ) {
F_45 ( V_27 , L_171 ,
F_276 ( V_172 . V_169 ) , V_172 . V_169 ) ;
return - 1 ;
}
if ( V_172 . V_64 != F_55 ) {
F_45 ( V_27 , L_172 ,
F_55 , V_172 . V_64 ) ;
return - 1 ;
}
V_337 = V_172 . V_96 ;
V_77 = F_74 ( V_27 , V_337 , F_55 ) ;
if ( V_77 )
return 0 ;
V_337 -> V_763 = F_125 ( V_337 -> V_763 ) ;
V_337 -> V_765 = F_125 ( V_337 -> V_765 ) ;
if ( V_337 -> V_765 == 0 )
V_337 -> V_765 = V_337 -> V_763 ;
if ( V_567 < V_337 -> V_763 ||
V_764 > V_337 -> V_765 )
goto V_769;
V_27 -> V_186 = F_77 ( int , V_567 , V_337 -> V_765 ) ;
V_27 -> V_565 = V_767 & F_125 ( V_337 -> V_766 ) ;
F_68 ( V_27 , L_173
L_174 , V_27 -> V_186 ) ;
F_68 ( V_27 , L_175 ,
V_27 -> V_565 ,
V_27 -> V_565 & V_770 ? L_176 : L_104 ,
V_27 -> V_565 & V_771 ? L_177 : L_104 ,
V_27 -> V_565 & V_566 ? L_178 :
V_27 -> V_565 ? L_104 : L_179 ) ;
return 1 ;
V_769:
F_45 ( V_27 , L_180
L_181 ,
V_764 , V_567 ,
V_337 -> V_763 , V_337 -> V_765 ) ;
return - 1 ;
}
static int F_117 ( struct V_26 * V_27 )
{
F_45 ( V_27 , L_182 ) ;
F_45 ( V_27 , L_183 ) ;
return - 1 ;
}
static int F_117 ( struct V_26 * V_27 )
{
struct V_167 * V_84 ;
char V_772 [ V_773 ] ;
char * V_774 = NULL ;
char * V_775 = NULL ;
char * V_776 = NULL ;
unsigned int V_777 ;
char V_778 [ V_602 ] ;
unsigned int V_779 ;
F_357 ( V_780 , V_27 -> V_219 ) ;
struct V_171 V_172 ;
struct V_35 * V_36 ;
int V_77 , V_95 ;
F_24 () ;
V_36 = F_32 ( V_27 -> V_35 ) ;
V_777 = strlen ( V_36 -> V_781 ) ;
memcpy ( V_778 , V_36 -> V_781 , V_777 ) ;
F_28 () ;
V_780 -> V_614 = V_27 -> V_219 ;
V_780 -> V_69 = 0 ;
V_95 = F_358 ( V_27 -> V_219 , ( V_782 * ) V_778 , V_777 ) ;
if ( V_95 ) {
F_45 ( V_27 , L_184 , V_95 ) ;
V_95 = - 1 ;
goto V_63;
}
F_359 ( V_772 , V_773 ) ;
V_84 = & V_27 -> V_96 ;
if ( ! F_92 ( V_27 , V_84 ) ) {
V_95 = 0 ;
goto V_63;
}
V_95 = ! F_93 ( V_27 , V_84 , V_783 , 0 ,
V_772 , V_773 ) ;
if ( ! V_95 )
goto V_63;
V_77 = F_127 ( V_27 , & V_172 ) ;
if ( V_77 ) {
V_95 = 0 ;
goto V_63;
}
if ( V_172 . V_169 != V_783 ) {
F_45 ( V_27 , L_185 ,
F_276 ( V_172 . V_169 ) , V_172 . V_169 ) ;
V_95 = 0 ;
goto V_63;
}
if ( V_172 . V_64 > V_773 * 2 ) {
F_45 ( V_27 , L_186 ) ;
V_95 = - 1 ;
goto V_63;
}
if ( V_172 . V_64 < V_773 ) {
F_45 ( V_27 , L_187 ) ;
V_95 = - 1 ;
goto V_63;
}
V_776 = F_134 ( V_172 . V_64 , V_213 ) ;
if ( V_776 == NULL ) {
F_45 ( V_27 , L_188 ) ;
V_95 = - 1 ;
goto V_63;
}
V_77 = F_74 ( V_27 , V_776 , V_172 . V_64 ) ;
if ( V_77 ) {
V_95 = 0 ;
goto V_63;
}
if ( ! memcmp ( V_772 , V_776 , V_773 ) ) {
F_45 ( V_27 , L_189 ) ;
V_95 = - 1 ;
goto V_63;
}
V_779 = F_360 ( V_27 -> V_219 ) ;
V_774 = F_134 ( V_779 , V_213 ) ;
if ( V_774 == NULL ) {
F_45 ( V_27 , L_190 ) ;
V_95 = - 1 ;
goto V_63;
}
V_95 = F_361 ( V_780 , V_776 , V_172 . V_64 , V_774 ) ;
if ( V_95 ) {
F_45 ( V_27 , L_191 , V_95 ) ;
V_95 = - 1 ;
goto V_63;
}
if ( ! F_92 ( V_27 , V_84 ) ) {
V_95 = 0 ;
goto V_63;
}
V_95 = ! F_93 ( V_27 , V_84 , V_784 , 0 ,
V_774 , V_779 ) ;
if ( ! V_95 )
goto V_63;
V_77 = F_127 ( V_27 , & V_172 ) ;
if ( V_77 ) {
V_95 = 0 ;
goto V_63;
}
if ( V_172 . V_169 != V_784 ) {
F_45 ( V_27 , L_192 ,
F_276 ( V_172 . V_169 ) , V_172 . V_169 ) ;
V_95 = 0 ;
goto V_63;
}
if ( V_172 . V_64 != V_779 ) {
F_45 ( V_27 , L_193 ) ;
V_95 = 0 ;
goto V_63;
}
V_77 = F_74 ( V_27 , V_774 , V_779 ) ;
if ( V_77 ) {
V_95 = 0 ;
goto V_63;
}
V_775 = F_134 ( V_779 , V_213 ) ;
if ( V_775 == NULL ) {
F_45 ( V_27 , L_194 ) ;
V_95 = - 1 ;
goto V_63;
}
V_95 = F_361 ( V_780 , V_772 , V_773 ,
V_775 ) ;
if ( V_95 ) {
F_45 ( V_27 , L_191 , V_95 ) ;
V_95 = - 1 ;
goto V_63;
}
V_95 = ! memcmp ( V_774 , V_775 , V_779 ) ;
if ( V_95 )
F_68 ( V_27 , L_195 ,
V_779 ) ;
else
V_95 = - 1 ;
V_63:
F_52 ( V_776 ) ;
F_52 ( V_774 ) ;
F_52 ( V_775 ) ;
F_362 ( V_780 ) ;
return V_95 ;
}
int F_363 ( struct V_785 * V_786 )
{
struct V_26 * V_27 = V_786 -> V_27 ;
int V_194 ;
F_68 ( V_27 , L_196 ) ;
do {
V_194 = F_108 ( V_27 ) ;
if ( V_194 == 0 ) {
F_344 ( V_27 ) ;
F_99 ( V_44 ) ;
}
if ( V_194 == - 1 ) {
F_35 ( V_27 , L_197 ) ;
F_71 ( V_27 , F_72 ( V_105 , V_151 ) , V_107 ) ;
}
} while ( V_194 == 0 );
if ( V_194 > 0 )
F_341 ( V_27 ) ;
F_344 ( V_27 ) ;
F_68 ( V_27 , L_198 ) ;
return 0 ;
}
static int F_364 ( struct V_26 * V_27 , struct V_171 * V_172 )
{
struct V_787 * V_337 = V_172 -> V_96 ;
int V_788 = F_125 ( V_337 -> V_788 ) ;
if ( V_788 >= V_199 ) {
F_111 ( V_789 , & V_27 -> V_69 ) ;
} else {
F_111 ( V_790 , & V_27 -> V_69 ) ;
F_45 ( V_27 , L_199 ,
F_365 ( V_788 ) , V_788 ) ;
}
F_41 ( & V_27 -> V_101 ) ;
return 0 ;
}
static int F_366 ( struct V_26 * V_27 , struct V_171 * V_172 )
{
struct V_28 * V_29 ;
struct V_9 * V_10 ;
struct V_787 * V_337 = V_172 -> V_96 ;
int V_788 = F_125 ( V_337 -> V_788 ) ;
V_29 = F_201 ( V_27 , V_172 -> V_30 ) ;
if ( ! V_29 )
return - V_108 ;
V_10 = V_29 -> V_10 ;
if ( F_69 ( V_791 , & V_27 -> V_69 ) ) {
F_53 ( V_10 , V_27 -> V_186 < 100 ) ;
return F_364 ( V_27 , V_172 ) ;
}
if ( V_788 >= V_199 ) {
F_111 ( V_792 , & V_10 -> V_69 ) ;
} else {
F_111 ( V_793 , & V_10 -> V_69 ) ;
F_45 ( V_10 , L_199 ,
F_365 ( V_788 ) , V_788 ) ;
}
F_41 ( & V_10 -> V_794 ) ;
return 0 ;
}
static int F_367 ( struct V_26 * V_27 , struct V_171 * V_172 )
{
return F_368 ( V_27 ) ;
}
static int F_369 ( struct V_26 * V_27 , struct V_171 * V_172 )
{
V_27 -> V_202 . V_83 -> V_111 -> V_138 = V_27 -> V_35 -> V_217 * V_44 ;
if ( ! F_370 ( V_795 , & V_27 -> V_69 ) )
F_41 ( & V_27 -> V_101 ) ;
return 0 ;
}
static int F_371 ( struct V_26 * V_27 , struct V_171 * V_172 )
{
struct V_28 * V_29 ;
struct V_9 * V_10 ;
struct V_796 * V_337 = V_172 -> V_96 ;
T_3 V_52 = F_202 ( V_337 -> V_52 ) ;
int V_489 = F_125 ( V_337 -> V_489 ) ;
V_29 = F_201 ( V_27 , V_172 -> V_30 ) ;
if ( ! V_29 )
return - V_108 ;
V_10 = V_29 -> V_10 ;
F_53 ( V_10 , V_29 -> V_27 -> V_186 >= 89 ) ;
F_216 ( V_29 , F_125 ( V_337 -> V_439 ) ) ;
if ( F_139 ( V_10 ) ) {
F_340 ( V_10 , V_52 ) ;
F_191 ( V_10 , V_52 , V_489 ) ;
V_10 -> V_797 += ( V_489 >> V_798 ) ;
F_130 ( V_10 ) ;
}
F_196 ( V_10 ) ;
F_38 ( V_489 >> 9 , & V_10 -> V_389 ) ;
return 0 ;
}
static int
F_372 ( struct V_9 * V_10 , T_2 V_51 , T_3 V_52 ,
struct V_381 * V_382 , const char * V_384 ,
enum V_799 V_117 , bool V_383 )
{
struct V_361 * V_362 ;
struct V_429 V_430 ;
F_20 ( & V_10 -> V_24 -> V_25 ) ;
V_362 = F_198 ( V_10 , V_382 , V_51 , V_52 , V_383 , V_384 ) ;
if ( F_153 ( ! V_362 ) ) {
F_21 ( & V_10 -> V_24 -> V_25 ) ;
return - V_108 ;
}
F_209 ( V_362 , V_117 , & V_430 ) ;
F_21 ( & V_10 -> V_24 -> V_25 ) ;
if ( V_430 . V_244 )
F_224 ( V_10 , & V_430 ) ;
return 0 ;
}
static int F_373 ( struct V_26 * V_27 , struct V_171 * V_172 )
{
struct V_28 * V_29 ;
struct V_9 * V_10 ;
struct V_796 * V_337 = V_172 -> V_96 ;
T_3 V_52 = F_202 ( V_337 -> V_52 ) ;
int V_489 = F_125 ( V_337 -> V_489 ) ;
enum V_799 V_117 ;
V_29 = F_201 ( V_27 , V_172 -> V_30 ) ;
if ( ! V_29 )
return - V_108 ;
V_10 = V_29 -> V_10 ;
F_216 ( V_29 , F_125 ( V_337 -> V_439 ) ) ;
if ( V_337 -> V_68 == V_376 ) {
F_191 ( V_10 , V_52 , V_489 ) ;
F_196 ( V_10 ) ;
return 0 ;
}
switch ( V_172 -> V_169 ) {
case V_374 :
V_117 = V_800 ;
break;
case V_401 :
V_117 = V_801 ;
break;
case V_448 :
V_117 = V_802 ;
break;
case V_405 :
V_117 = V_393 ;
break;
case V_406 :
V_117 = V_803 ;
break;
default:
F_247 () ;
}
return F_372 ( V_10 , V_337 -> V_68 , V_52 ,
& V_10 -> V_333 , V_62 ,
V_117 , false ) ;
}
static int F_374 ( struct V_26 * V_27 , struct V_171 * V_172 )
{
struct V_28 * V_29 ;
struct V_9 * V_10 ;
struct V_796 * V_337 = V_172 -> V_96 ;
T_3 V_52 = F_202 ( V_337 -> V_52 ) ;
int V_64 = F_125 ( V_337 -> V_489 ) ;
int V_77 ;
V_29 = F_201 ( V_27 , V_172 -> V_30 ) ;
if ( ! V_29 )
return - V_108 ;
V_10 = V_29 -> V_10 ;
F_216 ( V_29 , F_125 ( V_337 -> V_439 ) ) ;
if ( V_337 -> V_68 == V_376 ) {
F_196 ( V_10 ) ;
F_193 ( V_10 , V_52 , V_64 ) ;
return 0 ;
}
V_77 = F_372 ( V_10 , V_337 -> V_68 , V_52 ,
& V_10 -> V_333 , V_62 ,
V_431 , true ) ;
if ( V_77 ) {
F_233 ( V_10 , V_52 , V_64 ) ;
}
return 0 ;
}
static int F_375 ( struct V_26 * V_27 , struct V_171 * V_172 )
{
struct V_28 * V_29 ;
struct V_9 * V_10 ;
struct V_796 * V_337 = V_172 -> V_96 ;
T_3 V_52 = F_202 ( V_337 -> V_52 ) ;
V_29 = F_201 ( V_27 , V_172 -> V_30 ) ;
if ( ! V_29 )
return - V_108 ;
V_10 = V_29 -> V_10 ;
F_216 ( V_29 , F_125 ( V_337 -> V_439 ) ) ;
F_45 ( V_10 , L_200 ,
( unsigned long long ) V_52 , F_125 ( V_337 -> V_489 ) ) ;
return F_372 ( V_10 , V_337 -> V_68 , V_52 ,
& V_10 -> V_386 , V_62 ,
V_431 , false ) ;
}
static int F_376 ( struct V_26 * V_27 , struct V_171 * V_172 )
{
struct V_28 * V_29 ;
struct V_9 * V_10 ;
T_3 V_52 ;
int V_64 ;
struct V_796 * V_337 = V_172 -> V_96 ;
V_29 = F_201 ( V_27 , V_172 -> V_30 ) ;
if ( ! V_29 )
return - V_108 ;
V_10 = V_29 -> V_10 ;
V_52 = F_202 ( V_337 -> V_52 ) ;
V_64 = F_125 ( V_337 -> V_489 ) ;
F_216 ( V_29 , F_125 ( V_337 -> V_439 ) ) ;
F_196 ( V_10 ) ;
if ( F_244 ( V_10 , V_703 ) ) {
F_340 ( V_10 , V_52 ) ;
switch ( V_172 -> V_169 ) {
case V_497 :
F_193 ( V_10 , V_52 , V_64 ) ;
case V_804 :
break;
default:
F_247 () ;
}
F_130 ( V_10 ) ;
}
return 0 ;
}
static int F_377 ( struct V_26 * V_27 , struct V_171 * V_172 )
{
struct V_805 * V_337 = V_172 -> V_96 ;
struct V_28 * V_29 ;
int V_30 ;
F_378 ( V_27 , V_337 -> V_338 , F_125 ( V_337 -> V_806 ) ) ;
F_24 () ;
F_25 (&connection->peer_devices, peer_device, vnr) {
struct V_9 * V_10 = V_29 -> V_10 ;
if ( V_10 -> V_397 . V_105 == V_699 &&
F_26 ( & V_10 -> V_191 ) == 0 &&
! F_370 ( V_807 , & V_10 -> V_69 ) ) {
V_10 -> V_808 . V_809 = V_66 + V_44 ;
F_379 ( & V_10 -> V_808 ) ;
}
}
F_28 () ;
return 0 ;
}
static int F_380 ( struct V_26 * V_27 , struct V_171 * V_172 )
{
struct V_28 * V_29 ;
struct V_9 * V_10 ;
struct V_796 * V_337 = V_172 -> V_96 ;
struct V_810 * V_811 ;
T_3 V_52 ;
int V_64 ;
V_29 = F_201 ( V_27 , V_172 -> V_30 ) ;
if ( ! V_29 )
return - V_108 ;
V_10 = V_29 -> V_10 ;
V_52 = F_202 ( V_337 -> V_52 ) ;
V_64 = F_125 ( V_337 -> V_489 ) ;
F_216 ( V_29 , F_125 ( V_337 -> V_439 ) ) ;
if ( F_202 ( V_337 -> V_68 ) == V_812 )
F_381 ( V_10 , V_52 , V_64 ) ;
else
F_307 ( V_10 ) ;
if ( ! F_139 ( V_10 ) )
return 0 ;
F_340 ( V_10 , V_52 ) ;
F_196 ( V_10 ) ;
-- V_10 -> V_481 ;
if ( ( V_10 -> V_481 & 0x200 ) == 0x200 )
F_382 ( V_10 , V_10 -> V_481 ) ;
if ( V_10 -> V_481 == 0 ) {
V_811 = F_134 ( sizeof( * V_811 ) , V_213 ) ;
if ( V_811 ) {
V_811 -> V_20 . V_80 = V_813 ;
V_811 -> V_10 = V_10 ;
F_383 ( & V_29 -> V_27 -> V_759 , & V_811 -> V_20 ) ;
} else {
F_45 ( V_10 , L_201 ) ;
F_307 ( V_10 ) ;
F_306 ( V_10 ) ;
}
}
F_130 ( V_10 ) ;
return 0 ;
}
static int F_384 ( struct V_26 * V_27 , struct V_171 * V_172 )
{
return 0 ;
}
static void F_385 ( struct V_26 * V_27 , bool V_814 )
{
long V_23 ;
struct V_35 * V_36 ;
F_24 () ;
V_36 = F_32 ( V_27 -> V_35 ) ;
V_23 = V_814 ? V_36 -> V_100 : V_36 -> V_217 ;
F_28 () ;
V_23 *= V_44 ;
if ( V_814 )
V_23 /= 10 ;
V_27 -> V_202 . V_83 -> V_111 -> V_138 = V_23 ;
}
static void F_386 ( struct V_26 * V_27 )
{
F_385 ( V_27 , 1 ) ;
}
static void F_387 ( struct V_26 * V_27 )
{
F_385 ( V_27 , 0 ) ;
}
int F_388 ( struct V_785 * V_786 )
{
struct V_26 * V_27 = V_786 -> V_27 ;
struct V_815 * V_169 = NULL ;
struct V_171 V_172 ;
unsigned long V_816 ;
int V_95 ;
void * V_85 = V_27 -> V_202 . V_173 ;
int V_817 = 0 ;
unsigned int V_170 = F_95 ( V_27 ) ;
int F_55 = V_170 ;
bool V_818 = false ;
struct V_819 V_820 = { . V_821 = 2 } ;
V_95 = F_389 ( V_43 , V_822 , & V_820 ) ;
if ( V_95 < 0 )
F_45 ( V_27 , L_202 , V_95 ) ;
while ( F_114 ( V_786 ) == V_742 ) {
F_342 ( V_786 ) ;
F_23 ( V_27 ) ;
if ( F_289 ( V_823 , & V_27 -> V_69 ) ) {
if ( F_390 ( V_27 ) ) {
F_45 ( V_27 , L_203 ) ;
goto V_631;
}
F_386 ( V_27 ) ;
V_818 = true ;
}
V_816 = V_66 ;
V_95 = F_65 ( V_27 -> V_202 . V_83 , V_85 , F_55 - V_817 , 0 ) ;
if ( F_190 ( V_95 > 0 ) ) {
V_817 += V_95 ;
V_85 += V_95 ;
} else if ( V_95 == 0 ) {
if ( F_69 ( V_99 , & V_27 -> V_69 ) ) {
long V_23 ;
F_24 () ;
V_23 = F_32 ( V_27 -> V_35 ) -> V_100 * V_44 / 10 ;
F_28 () ;
V_23 = F_70 ( V_27 -> V_101 ,
V_27 -> V_102 < V_103 ,
V_23 ) ;
if ( V_23 )
break;
}
F_45 ( V_27 , L_204 ) ;
goto V_631;
} else if ( V_95 == - V_144 ) {
if ( F_391 ( V_27 -> V_218 , V_816 ) )
continue;
if ( V_818 ) {
F_45 ( V_27 , L_205 ) ;
goto V_631;
}
F_111 ( V_823 , & V_27 -> V_69 ) ;
continue;
} else if ( V_95 == - V_146 ) {
F_112 ( V_43 ) ;
continue;
} else {
F_45 ( V_27 , L_7 , V_95 ) ;
goto V_631;
}
if ( V_817 == F_55 && V_169 == NULL ) {
if ( F_96 ( V_27 , V_27 -> V_202 . V_173 , & V_172 ) )
goto V_631;
V_169 = & V_824 [ V_172 . V_169 ] ;
if ( V_172 . V_169 >= F_343 ( V_824 ) || ! V_169 -> V_746 ) {
F_45 ( V_27 , L_206 ,
F_276 ( V_172 . V_169 ) , V_172 . V_169 ) ;
goto V_611;
}
F_55 = V_170 + V_169 -> V_747 ;
if ( V_172 . V_64 != F_55 - V_170 ) {
F_45 ( V_27 , L_207 ,
V_172 . V_169 , V_172 . V_64 ) ;
goto V_631;
}
}
if ( V_817 == F_55 ) {
bool V_77 ;
V_77 = V_169 -> V_746 ( V_27 , & V_172 ) ;
if ( V_77 ) {
F_45 ( V_27 , L_208 , V_169 -> V_746 ) ;
goto V_631;
}
V_27 -> V_218 = V_66 ;
if ( V_169 == & V_824 [ V_825 ] ) {
F_387 ( V_27 ) ;
V_818 = false ;
}
V_85 = V_27 -> V_202 . V_173 ;
V_817 = 0 ;
F_55 = V_170 ;
V_169 = NULL ;
}
}
if ( 0 ) {
V_631:
F_71 ( V_27 , F_72 ( V_105 , V_752 ) , V_107 ) ;
F_392 ( V_27 ) ;
}
if ( 0 ) {
V_611:
F_71 ( V_27 , F_72 ( V_105 , V_151 ) , V_107 ) ;
}
F_68 ( V_27 , L_209 ) ;
return 0 ;
}
void F_393 ( struct V_826 * V_827 )
{
struct V_28 * V_29 =
F_189 ( V_827 , struct V_28 , V_436 ) ;
struct V_26 * V_27 = V_29 -> V_27 ;
struct V_9 * V_10 = V_29 -> V_10 ;
struct V_35 * V_36 ;
int V_828 , V_77 ;
F_24 () ;
V_36 = F_32 ( V_27 -> V_35 ) ;
V_828 = V_36 -> V_828 ;
F_28 () ;
if ( V_828 )
F_394 ( V_27 -> V_202 . V_83 ) ;
V_77 = F_59 ( V_10 ) ;
F_29 ( & V_10 -> V_32 , V_33 ) ;
if ( V_77 ) {
F_71 ( V_27 , F_72 ( V_105 , V_752 ) , V_107 ) ;
return;
}
if ( V_828 )
F_395 ( V_27 -> V_202 . V_83 ) ;
return;
}
