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
V_249 -> error = F_129 ( V_244 -> V_250 ) ;
F_68 ( V_10 , L_27 , V_244 -> V_250 ) ;
}
F_52 ( V_246 ) ;
F_130 ( V_244 ) ;
F_106 ( V_251 , & V_10 -> V_69 ) ;
F_131 ( V_10 ) ;
F_29 ( & V_10 -> V_32 , V_33 ) ;
if ( F_132 ( & V_249 -> V_252 ) )
F_82 ( & V_249 -> V_253 ) ;
}
static void F_133 ( struct V_9 * V_10 , struct V_248 * V_249 )
{
struct V_244 * V_244 = F_134 ( V_213 , 0 ) ;
struct V_245 * V_246 = F_135 ( sizeof( * V_246 ) , V_213 ) ;
if ( ! V_244 || ! V_246 ) {
F_35 ( V_10 , L_28 ) ;
F_52 ( V_246 ) ;
if ( V_244 )
F_130 ( V_244 ) ;
V_249 -> error = - V_254 ;
F_131 ( V_10 ) ;
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
F_136 ( & V_249 -> V_252 ) ;
F_137 ( V_244 ) ;
}
static void F_138 ( struct V_26 * V_27 )
{
if ( V_27 -> V_24 -> V_263 >= V_264 ) {
struct V_28 * V_29 ;
struct V_248 V_249 ;
int V_30 ;
F_101 ( & V_249 . V_252 , 1 ) ;
V_249 . error = 0 ;
F_139 ( & V_249 . V_253 ) ;
F_24 () ;
F_25 (&connection->peer_devices, peer_device, vnr) {
struct V_9 * V_10 = V_29 -> V_10 ;
if ( ! F_140 ( V_10 ) )
continue;
F_27 ( & V_10 -> V_32 ) ;
F_28 () ;
F_133 ( V_10 , & V_249 ) ;
F_24 () ;
}
F_28 () ;
if ( ! F_132 ( & V_249 . V_252 ) )
F_141 ( & V_249 . V_253 ) ;
if ( V_249 . error ) {
F_142 ( V_27 -> V_24 , NULL , V_265 ) ;
}
}
}
static enum V_266 F_143 ( struct V_26 * V_27 ,
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
F_144 ( & V_268 -> V_277 ) ;
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
F_145 ( V_268 -> V_27 , V_268 -> V_281 , V_271 ) ;
F_11 ( & V_27 -> V_274 ) ;
}
#if 0
if (test_bit(DE_HAVE_BARRIER_NUMBER, &epoch->flags))
dec_unacked(epoch->connection);
#endif
if ( V_27 -> V_282 != V_268 ) {
V_272 = F_146 ( V_268 -> V_21 . V_283 , struct V_267 , V_21 ) ;
F_147 ( & V_268 -> V_21 ) ;
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
F_148 ( struct V_288 * V_289 , enum V_287 V_290 )
{
struct V_291 * V_292 ;
V_292 = F_32 ( V_289 -> V_291 ) ;
if ( V_290 == V_264 && ! V_292 -> V_293 )
V_290 = V_265 ;
if ( V_290 == V_265 && ! V_292 -> V_294 )
V_290 = V_295 ;
return V_290 ;
}
void F_142 ( struct V_296 * V_24 , struct V_288 * V_289 ,
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
V_290 = F_149 ( V_297 , V_290 ) ;
F_24 () ;
F_25 (&resource->devices, device, vnr) {
if ( F_140 ( V_10 ) ) {
V_290 = F_148 ( V_10 -> V_256 , V_290 ) ;
if ( V_10 -> V_256 == V_289 )
V_289 = NULL ;
F_131 ( V_10 ) ;
}
}
if ( V_289 )
V_290 = F_148 ( V_289 , V_290 ) ;
F_28 () ;
V_24 -> V_263 = V_290 ;
if ( V_297 != V_24 -> V_263 || V_290 == V_264 )
F_68 ( V_24 , L_32 , V_298 [ V_24 -> V_263 ] ) ;
}
static void F_150 ( struct V_9 * V_10 , struct V_18 * V_19 )
{
struct V_299 * V_289 = V_10 -> V_256 -> V_257 ;
if ( F_151 ( V_289 , V_19 -> V_6 . V_52 , V_19 -> V_6 . V_64 >> 9 ,
V_213 , 0 ) )
V_19 -> V_69 |= V_300 ;
F_152 ( V_19 ) ;
}
static void F_153 ( struct V_9 * V_10 ,
struct V_18 * V_19 )
{
struct V_299 * V_289 = V_10 -> V_256 -> V_257 ;
T_3 V_203 = V_19 -> V_6 . V_52 ;
T_3 V_301 = V_19 -> V_6 . V_64 >> 9 ;
if ( F_154 ( V_289 , V_203 , V_301 , V_213 , V_19 -> V_67 ) )
V_19 -> V_69 |= V_300 ;
F_152 ( V_19 ) ;
}
int F_155 ( struct V_9 * V_10 ,
struct V_18 * V_19 ,
const unsigned V_302 , const unsigned V_303 ,
const int V_304 )
{
struct V_244 * V_305 = NULL ;
struct V_244 * V_244 ;
struct V_1 * V_1 = V_19 -> V_67 ;
T_3 V_52 = V_19 -> V_6 . V_52 ;
unsigned V_306 = V_19 -> V_6 . V_64 ;
unsigned V_307 = 0 ;
unsigned V_56 = ( V_306 + V_49 - 1 ) >> V_57 ;
int V_77 = - V_254 ;
if ( V_19 -> V_69 & ( V_308 | V_309 ) ) {
F_156 ( V_19 -> V_29 -> V_27 ) ;
V_19 -> V_65 = V_66 ;
V_19 -> V_69 |= V_310 ;
if ( F_62 ( & V_19 -> V_20 . V_21 ) ) {
F_20 ( & V_10 -> V_24 -> V_25 ) ;
F_157 ( & V_19 -> V_20 . V_21 , & V_10 -> V_311 ) ;
F_21 ( & V_10 -> V_24 -> V_25 ) ;
}
if ( V_19 -> V_69 & V_308 )
F_150 ( V_10 , V_19 ) ;
else
F_153 ( V_10 , V_19 ) ;
return 0 ;
}
V_312:
V_244 = F_134 ( V_213 , V_56 ) ;
if ( ! V_244 ) {
F_45 ( V_10 , L_33 , V_56 ) ;
goto V_63;
}
V_244 -> V_313 . V_314 = V_52 ;
V_244 -> V_255 = V_10 -> V_256 -> V_257 ;
F_158 ( V_244 , V_302 , V_303 ) ;
V_244 -> V_247 = V_19 ;
V_244 -> V_258 = V_315 ;
V_244 -> V_316 = V_305 ;
V_305 = V_244 ;
++ V_307 ;
F_159 (page) {
unsigned V_5 = F_77 ( unsigned , V_306 , V_49 ) ;
if ( ! F_160 ( V_244 , V_1 , V_5 , 0 ) )
goto V_312;
V_306 -= V_5 ;
V_52 += V_5 >> 9 ;
-- V_56 ;
}
F_53 ( V_10 , V_306 == 0 ) ;
F_53 ( V_10 , V_1 == NULL ) ;
F_101 ( & V_19 -> V_72 , V_307 ) ;
V_19 -> V_65 = V_66 ;
V_19 -> V_69 |= V_310 ;
do {
V_244 = V_305 ;
V_305 = V_305 -> V_316 ;
V_244 -> V_316 = NULL ;
F_161 ( V_10 , V_304 , V_244 ) ;
} while ( V_305 );
return 0 ;
V_63:
while ( V_305 ) {
V_244 = V_305 ;
V_305 = V_305 -> V_316 ;
F_130 ( V_244 ) ;
}
return V_77 ;
}
static void F_162 ( struct V_9 * V_10 ,
struct V_18 * V_19 )
{
struct V_317 * V_6 = & V_19 -> V_6 ;
F_163 ( & V_10 -> V_318 , V_6 ) ;
F_48 ( V_6 ) ;
if ( V_6 -> V_319 )
F_41 ( & V_10 -> V_320 ) ;
}
static void F_156 ( struct V_26 * V_27 )
{
struct V_28 * V_29 ;
int V_30 ;
F_24 () ;
F_25 (&connection->peer_devices, peer_device, vnr) {
struct V_9 * V_10 = V_29 -> V_10 ;
F_27 ( & V_10 -> V_32 ) ;
F_28 () ;
F_64 ( V_10 , & V_10 -> V_311 ) ;
F_29 ( & V_10 -> V_32 , V_33 ) ;
F_24 () ;
}
F_28 () ;
}
static int F_164 ( struct V_26 * V_27 , struct V_171 * V_172 )
{
int V_95 ;
struct V_321 * V_322 = V_172 -> V_96 ;
struct V_267 * V_268 ;
V_27 -> V_282 -> V_281 = V_322 -> V_323 ;
V_27 -> V_282 -> V_27 = V_27 ;
V_95 = F_143 ( V_27 , V_27 -> V_282 , V_278 ) ;
switch ( V_27 -> V_24 -> V_263 ) {
case V_295 :
if ( V_95 == V_286 )
return 0 ;
V_268 = F_135 ( sizeof( struct V_267 ) , V_213 ) ;
if ( V_268 )
break;
else
F_35 ( V_27 , L_34 ) ;
case V_264 :
case V_265 :
F_156 ( V_27 ) ;
F_138 ( V_27 ) ;
if ( F_26 ( & V_27 -> V_282 -> V_271 ) ) {
V_268 = F_135 ( sizeof( struct V_267 ) , V_213 ) ;
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
F_165 ( & V_268 -> V_21 , & V_27 -> V_282 -> V_21 ) ;
V_27 -> V_282 = V_268 ;
V_27 -> V_284 ++ ;
} else {
F_52 ( V_268 ) ;
}
F_12 ( & V_27 -> V_274 ) ;
return 0 ;
}
static void F_166 ( struct V_324 * V_194 ,
struct V_18 * V_325 , void * V_326 ,
unsigned int V_54 )
{
unsigned int V_4 = V_325 -> V_6 . V_64 ;
V_325 -> V_6 . V_64 = V_54 ;
F_167 ( V_194 , V_325 , V_326 ) ;
V_325 -> V_6 . V_64 = V_4 ;
}
static struct V_18 *
F_168 ( struct V_28 * V_29 , T_2 V_51 , T_3 V_52 ,
struct V_171 * V_172 ) __must_hold( T_5 )
{
struct V_9 * V_10 = V_29 -> V_10 ;
const T_3 V_327 = F_169 ( V_10 -> V_328 ) ;
struct V_18 * V_19 ;
struct V_1 * V_1 ;
int V_329 , V_77 ;
unsigned int V_306 = V_172 -> V_64 , V_330 ;
void * V_331 = V_29 -> V_27 -> V_332 ;
void * V_333 = V_29 -> V_27 -> V_334 ;
unsigned long * V_96 ;
struct V_335 * V_336 = ( V_172 -> V_169 == V_337 ) ? V_172 -> V_96 : NULL ;
struct V_335 * V_338 = ( V_172 -> V_169 == V_339 ) ? V_172 -> V_96 : NULL ;
V_329 = 0 ;
if ( ! V_336 && V_29 -> V_27 -> V_340 ) {
V_329 = F_170 ( V_29 -> V_27 -> V_340 ) ;
V_77 = F_74 ( V_29 -> V_27 , V_331 , V_329 ) ;
if ( V_77 )
return NULL ;
V_306 -= V_329 ;
}
V_330 = V_306 ;
if ( V_336 ) {
if ( ! F_55 ( V_306 == 0 ) )
return NULL ;
V_330 = F_125 ( V_336 -> V_64 ) ;
} else if ( V_338 ) {
if ( V_306 != F_171 ( V_10 -> V_341 ) ) {
F_45 ( V_29 , L_36 ,
V_306 , F_171 ( V_10 -> V_341 ) ) ;
return NULL ;
}
if ( V_306 != F_172 ( V_10 -> V_256 -> V_257 ) ) {
F_45 ( V_29 , L_37 ,
V_306 , F_172 ( V_10 -> V_256 -> V_257 ) ) ;
return NULL ;
}
V_330 = F_125 ( V_338 -> V_64 ) ;
}
if ( ! F_55 ( F_173 ( V_330 , 512 ) ) )
return NULL ;
if ( V_336 || V_338 ) {
if ( ! F_55 ( V_330 <= ( V_342 << 9 ) ) )
return NULL ;
} else if ( ! F_55 ( V_330 <= V_48 ) )
return NULL ;
if ( V_52 + ( V_330 >> 9 ) > V_327 ) {
F_45 ( V_10 , L_38
L_39 ,
( unsigned long long ) V_327 ,
( unsigned long long ) V_52 , V_330 ) ;
return NULL ;
}
V_19 = F_42 ( V_29 , V_51 , V_52 , V_330 , V_306 , V_213 ) ;
if ( ! V_19 )
return NULL ;
V_19 -> V_69 |= V_343 ;
if ( V_336 ) {
V_19 -> V_69 |= V_308 ;
return V_19 ;
}
if ( V_338 )
V_19 -> V_69 |= V_309 ;
V_330 = V_306 ;
V_1 = V_19 -> V_67 ;
F_159 (page) {
unsigned V_5 = F_77 ( int , V_330 , V_49 ) ;
V_96 = F_174 ( V_1 ) ;
V_77 = F_74 ( V_29 -> V_27 , V_96 , V_5 ) ;
if ( F_43 ( V_10 , V_344 ) ) {
F_45 ( V_10 , L_40 ) ;
V_96 [ 0 ] = V_96 [ 0 ] ^ ( unsigned long ) - 1 ;
}
F_175 ( V_1 ) ;
if ( V_77 ) {
F_60 ( V_10 , V_19 ) ;
return NULL ;
}
V_330 -= V_5 ;
}
if ( V_329 ) {
F_166 ( V_29 -> V_27 -> V_340 , V_19 , V_333 , V_306 ) ;
if ( memcmp ( V_331 , V_333 , V_329 ) ) {
F_45 ( V_10 , L_41 ,
( unsigned long long ) V_52 , V_306 ) ;
F_60 ( V_10 , V_19 ) ;
return NULL ;
}
}
V_10 -> V_345 += V_306 >> 9 ;
return V_19 ;
}
static int F_176 ( struct V_28 * V_29 , int V_306 )
{
struct V_1 * V_1 ;
int V_77 = 0 ;
void * V_96 ;
if ( ! V_306 )
return 0 ;
V_1 = F_30 ( V_29 , 1 , 1 ) ;
V_96 = F_174 ( V_1 ) ;
while ( V_306 ) {
unsigned int V_5 = F_77 ( int , V_306 , V_49 ) ;
V_77 = F_74 ( V_29 -> V_27 , V_96 , V_5 ) ;
if ( V_77 )
break;
V_306 -= V_5 ;
}
F_175 ( V_1 ) ;
F_39 ( V_29 -> V_10 , V_1 , 0 ) ;
return V_77 ;
}
static int F_177 ( struct V_28 * V_29 , struct V_346 * V_347 ,
T_3 V_52 , int V_306 )
{
struct V_348 V_349 ;
struct V_350 V_351 ;
struct V_244 * V_244 ;
int V_329 , V_77 , F_55 ;
void * V_331 = V_29 -> V_27 -> V_332 ;
void * V_333 = V_29 -> V_27 -> V_334 ;
V_329 = 0 ;
if ( V_29 -> V_27 -> V_340 ) {
V_329 = F_170 ( V_29 -> V_27 -> V_340 ) ;
V_77 = F_74 ( V_29 -> V_27 , V_331 , V_329 ) ;
if ( V_77 )
return V_77 ;
V_306 -= V_329 ;
}
V_29 -> V_10 -> V_345 += V_306 >> 9 ;
V_244 = V_347 -> V_352 ;
F_53 ( V_29 -> V_10 , V_52 == V_244 -> V_313 . V_314 ) ;
F_178 (bvec, bio, iter) {
void * V_353 = F_174 ( V_349 . V_354 ) + V_349 . V_355 ;
F_55 = F_77 ( int , V_306 , V_349 . V_356 ) ;
V_77 = F_74 ( V_29 -> V_27 , V_353 , F_55 ) ;
F_175 ( V_349 . V_354 ) ;
if ( V_77 )
return V_77 ;
V_306 -= F_55 ;
}
if ( V_329 ) {
F_179 ( V_29 -> V_27 -> V_340 , V_244 , V_333 ) ;
if ( memcmp ( V_331 , V_333 , V_329 ) ) {
F_45 ( V_29 , L_42 ) ;
return - V_234 ;
}
}
F_53 ( V_29 -> V_10 , V_306 == 0 ) ;
return 0 ;
}
static int F_180 ( struct V_357 * V_20 , int V_358 )
{
struct V_18 * V_19 =
F_181 ( V_20 , struct V_18 , V_20 ) ;
struct V_28 * V_29 = V_19 -> V_29 ;
struct V_9 * V_10 = V_29 -> V_10 ;
T_3 V_52 = V_19 -> V_6 . V_52 ;
int V_77 ;
F_53 ( V_10 , F_54 ( & V_19 -> V_6 ) ) ;
if ( F_182 ( ( V_19 -> V_69 & V_300 ) == 0 ) ) {
F_183 ( V_10 , V_52 , V_19 -> V_6 . V_64 ) ;
V_77 = F_184 ( V_29 , V_359 , V_19 ) ;
} else {
F_185 ( V_10 , V_52 , V_19 -> V_6 . V_64 ) ;
V_77 = F_184 ( V_29 , V_360 , V_19 ) ;
}
F_186 ( V_10 ) ;
return V_77 ;
}
static int F_187 ( struct V_28 * V_29 , T_3 V_52 ,
struct V_171 * V_172 ) __releases( T_5 )
{
struct V_9 * V_10 = V_29 -> V_10 ;
struct V_18 * V_19 ;
V_19 = F_168 ( V_29 , V_361 , V_52 , V_172 ) ;
if ( ! V_19 )
goto V_63;
F_188 ( V_10 ) ;
F_189 ( V_10 ) ;
V_19 -> V_20 . V_80 = F_180 ;
V_19 -> V_65 = V_66 ;
F_20 ( & V_10 -> V_24 -> V_25 ) ;
F_157 ( & V_19 -> V_20 . V_21 , & V_10 -> V_362 ) ;
F_21 ( & V_10 -> V_24 -> V_25 ) ;
F_38 ( V_172 -> V_64 >> 9 , & V_10 -> V_363 ) ;
if ( F_155 ( V_10 , V_19 , V_364 , 0 ,
V_365 ) == 0 )
return 0 ;
F_45 ( V_10 , L_43 ) ;
F_20 ( & V_10 -> V_24 -> V_25 ) ;
F_147 ( & V_19 -> V_20 . V_21 ) ;
F_21 ( & V_10 -> V_24 -> V_25 ) ;
F_60 ( V_10 , V_19 ) ;
V_63:
F_131 ( V_10 ) ;
return - V_108 ;
}
static struct V_346 *
F_190 ( struct V_9 * V_10 , struct V_366 * V_367 , T_2 V_51 ,
T_3 V_52 , bool V_368 , const char * V_369 )
{
struct V_346 * V_347 ;
V_347 = (struct V_346 * ) ( unsigned long ) V_51 ;
if ( F_191 ( V_367 , V_52 , & V_347 -> V_6 ) && V_347 -> V_6 . T_5 )
return V_347 ;
if ( ! V_368 ) {
F_45 ( V_10 , L_44 , V_369 ,
( unsigned long ) V_51 , ( unsigned long long ) V_52 ) ;
}
return NULL ;
}
static int F_192 ( struct V_26 * V_27 , struct V_171 * V_172 )
{
struct V_28 * V_29 ;
struct V_9 * V_10 ;
struct V_346 * V_347 ;
T_3 V_52 ;
int V_77 ;
struct V_370 * V_322 = V_172 -> V_96 ;
V_29 = F_193 ( V_27 , V_172 -> V_30 ) ;
if ( ! V_29 )
return - V_108 ;
V_10 = V_29 -> V_10 ;
V_52 = F_194 ( V_322 -> V_52 ) ;
F_20 ( & V_10 -> V_24 -> V_25 ) ;
V_347 = F_190 ( V_10 , & V_10 -> V_371 , V_322 -> V_68 , V_52 , false , V_62 ) ;
F_21 ( & V_10 -> V_24 -> V_25 ) ;
if ( F_195 ( ! V_347 ) )
return - V_108 ;
V_77 = F_177 ( V_29 , V_347 , V_52 , V_172 -> V_64 ) ;
if ( ! V_77 )
F_196 ( V_347 , V_372 ) ;
return V_77 ;
}
static int F_197 ( struct V_26 * V_27 , struct V_171 * V_172 )
{
struct V_28 * V_29 ;
struct V_9 * V_10 ;
T_3 V_52 ;
int V_77 ;
struct V_370 * V_322 = V_172 -> V_96 ;
V_29 = F_193 ( V_27 , V_172 -> V_30 ) ;
if ( ! V_29 )
return - V_108 ;
V_10 = V_29 -> V_10 ;
V_52 = F_194 ( V_322 -> V_52 ) ;
F_53 ( V_10 , V_322 -> V_68 == V_361 ) ;
if ( F_140 ( V_10 ) ) {
V_77 = F_187 ( V_29 , V_52 , V_172 ) ;
} else {
if ( F_198 ( & V_373 ) )
F_45 ( V_10 , L_45 ) ;
V_77 = F_176 ( V_29 , V_172 -> V_64 ) ;
F_199 ( V_29 , V_360 , V_322 , V_172 -> V_64 ) ;
}
F_38 ( V_172 -> V_64 >> 9 , & V_10 -> V_374 ) ;
return V_77 ;
}
static void F_200 ( struct V_9 * V_10 ,
T_3 V_52 , int V_64 )
{
struct V_317 * V_6 ;
struct V_346 * V_347 ;
F_201 (i, &device->write_requests, sector, size) {
if ( ! V_6 -> T_5 )
continue;
V_347 = F_181 ( V_6 , struct V_346 , V_6 ) ;
if ( V_347 -> V_375 & V_376 ||
! ( V_347 -> V_375 & V_377 ) )
continue;
F_202 ( V_347 , V_378 , NULL ) ;
}
}
static int F_203 ( struct V_357 * V_20 , int V_379 )
{
struct V_18 * V_19 =
F_181 ( V_20 , struct V_18 , V_20 ) ;
struct V_28 * V_29 = V_19 -> V_29 ;
struct V_9 * V_10 = V_29 -> V_10 ;
T_3 V_52 = V_19 -> V_6 . V_52 ;
int V_77 = 0 , V_380 ;
if ( V_19 -> V_69 & V_381 ) {
if ( F_182 ( ( V_19 -> V_69 & V_300 ) == 0 ) ) {
V_380 = ( V_10 -> V_382 . V_105 >= V_383 &&
V_10 -> V_382 . V_105 <= V_384 &&
V_19 -> V_69 & V_385 ) ?
V_359 : V_386 ;
V_77 = F_184 ( V_29 , V_380 , V_19 ) ;
if ( V_380 == V_359 )
F_183 ( V_10 , V_52 , V_19 -> V_6 . V_64 ) ;
} else {
V_77 = F_184 ( V_29 , V_360 , V_19 ) ;
}
F_186 ( V_10 ) ;
}
if ( V_19 -> V_69 & V_387 ) {
F_20 ( & V_10 -> V_24 -> V_25 ) ;
F_53 ( V_10 , ! F_54 ( & V_19 -> V_6 ) ) ;
F_162 ( V_10 , V_19 ) ;
if ( V_19 -> V_69 & V_388 )
F_200 ( V_10 , V_52 , V_19 -> V_6 . V_64 ) ;
F_21 ( & V_10 -> V_24 -> V_25 ) ;
} else
F_53 ( V_10 , F_54 ( & V_19 -> V_6 ) ) ;
F_143 ( V_29 -> V_27 , V_19 -> V_268 , V_276 + ( V_379 ? V_275 : 0 ) ) ;
return V_77 ;
}
static int F_204 ( struct V_357 * V_20 , enum V_168 V_389 )
{
struct V_18 * V_19 =
F_181 ( V_20 , struct V_18 , V_20 ) ;
struct V_28 * V_29 = V_19 -> V_29 ;
int V_77 ;
V_77 = F_184 ( V_29 , V_389 , V_19 ) ;
F_186 ( V_29 -> V_10 ) ;
return V_77 ;
}
static int F_205 ( struct V_357 * V_20 , int V_358 )
{
return F_204 ( V_20 , V_390 ) ;
}
static int F_206 ( struct V_357 * V_20 , int V_358 )
{
struct V_18 * V_19 =
F_181 ( V_20 , struct V_18 , V_20 ) ;
struct V_26 * V_27 = V_19 -> V_29 -> V_27 ;
return F_204 ( V_20 , V_27 -> V_186 >= 100 ?
V_391 : V_390 ) ;
}
static bool F_207 ( T_7 V_47 , T_7 V_392 )
{
return ( V_393 ) V_47 - ( V_393 ) V_392 > 0 ;
}
static T_7 F_208 ( T_7 V_47 , T_7 V_392 )
{
return F_207 ( V_47 , V_392 ) ? V_47 : V_392 ;
}
static void F_209 ( struct V_28 * V_29 , unsigned int V_184 )
{
struct V_9 * V_10 = V_29 -> V_10 ;
unsigned int V_394 ;
if ( F_69 ( V_205 , & V_29 -> V_27 -> V_69 ) ) {
F_11 ( & V_10 -> V_395 ) ;
V_394 = F_208 ( V_10 -> V_184 , V_184 ) ;
V_10 -> V_184 = V_394 ;
F_12 ( & V_10 -> V_395 ) ;
if ( V_184 == V_394 )
F_41 ( & V_10 -> V_396 ) ;
}
}
static inline int F_210 ( T_3 V_397 , int V_398 , T_3 V_399 , int V_400 )
{
return ! ( ( V_397 + ( V_398 >> 9 ) <= V_399 ) || ( V_397 >= V_399 + ( V_400 >> 9 ) ) ) ;
}
static bool F_211 ( struct V_9 * V_10 , struct V_18 * V_19 )
{
struct V_18 * V_401 ;
bool V_95 = false ;
F_20 ( & V_10 -> V_24 -> V_25 ) ;
F_212 (rs_req, &device->sync_ee, w.list) {
if ( F_210 ( V_19 -> V_6 . V_52 , V_19 -> V_6 . V_64 ,
V_401 -> V_6 . V_52 , V_401 -> V_6 . V_64 ) ) {
V_95 = true ;
break;
}
}
F_21 ( & V_10 -> V_24 -> V_25 ) ;
return V_95 ;
}
static int F_213 ( struct V_28 * V_29 , const T_7 V_184 )
{
struct V_9 * V_10 = V_29 -> V_10 ;
F_31 ( V_37 ) ;
long V_180 ;
int V_402 = 0 , V_403 ;
if ( ! F_69 ( V_205 , & V_29 -> V_27 -> V_69 ) )
return 0 ;
F_11 ( & V_10 -> V_395 ) ;
for (; ; ) {
if ( ! F_207 ( V_184 - 1 , V_10 -> V_184 ) ) {
V_10 -> V_184 = F_208 ( V_10 -> V_184 , V_184 ) ;
break;
}
if ( F_34 ( V_43 ) ) {
V_402 = - V_98 ;
break;
}
F_24 () ;
V_403 = F_32 ( V_29 -> V_27 -> V_35 ) -> V_404 ;
F_28 () ;
if ( ! V_403 )
break;
F_33 ( & V_10 -> V_396 , & V_37 , V_42 ) ;
F_12 ( & V_10 -> V_395 ) ;
F_24 () ;
V_180 = F_32 ( V_29 -> V_27 -> V_35 ) -> V_100 * V_44 / 10 ;
F_28 () ;
V_180 = F_36 ( V_180 ) ;
F_11 ( & V_10 -> V_395 ) ;
if ( ! V_180 ) {
V_402 = - V_143 ;
F_45 ( V_10 , L_46 ) ;
break;
}
}
F_12 ( & V_10 -> V_395 ) ;
F_37 ( & V_10 -> V_396 , & V_37 ) ;
return V_402 ;
}
static unsigned long F_214 ( T_7 V_405 )
{
return ( V_405 & V_406 ? V_407 : 0 ) |
( V_405 & V_408 ? V_409 : 0 ) |
( V_405 & V_410 ? V_261 : 0 ) ;
}
static unsigned long F_215 ( T_7 V_405 )
{
if ( V_405 & V_411 )
return V_412 ;
else
return V_364 ;
}
static void F_216 ( struct V_9 * V_10 , T_3 V_52 ,
unsigned int V_64 )
{
struct V_317 * V_6 ;
V_413:
F_201 (i, &device->write_requests, sector, size) {
struct V_346 * V_347 ;
struct V_414 V_415 ;
if ( ! V_6 -> T_5 )
continue;
V_347 = F_181 ( V_6 , struct V_346 , V_6 ) ;
if ( ! ( V_347 -> V_375 & V_377 ) )
continue;
V_347 -> V_375 &= ~ V_377 ;
F_202 ( V_347 , V_416 , & V_415 ) ;
F_21 ( & V_10 -> V_24 -> V_25 ) ;
if ( V_415 . V_244 )
F_217 ( V_10 , & V_415 ) ;
F_20 ( & V_10 -> V_24 -> V_25 ) ;
goto V_413;
}
}
static int F_218 ( struct V_9 * V_10 ,
struct V_18 * V_19 )
{
struct V_26 * V_27 = V_19 -> V_29 -> V_27 ;
bool V_417 = F_69 ( V_205 , & V_27 -> V_69 ) ;
T_3 V_52 = V_19 -> V_6 . V_52 ;
const unsigned int V_64 = V_19 -> V_6 . V_64 ;
struct V_317 * V_6 ;
bool V_418 ;
int V_77 ;
F_219 ( & V_10 -> V_318 , & V_19 -> V_6 ) ;
V_413:
F_201 (i, &device->write_requests, sector, size) {
if ( V_6 == & V_19 -> V_6 )
continue;
if ( V_6 -> V_419 )
continue;
if ( ! V_6 -> T_5 ) {
V_77 = F_220 ( V_10 , V_6 ) ;
if ( V_77 )
goto V_104;
goto V_413;
}
V_418 = V_6 -> V_52 == V_52 && V_6 -> V_64 == V_64 ;
if ( V_417 ) {
bool V_420 = V_6 -> V_52 <= V_52 && V_6 -> V_52 +
( V_6 -> V_64 >> 9 ) >= V_52 + ( V_64 >> 9 ) ;
if ( ! V_418 )
F_221 ( V_10 , L_47
L_48
L_49 ,
( unsigned long long ) V_6 -> V_52 , V_6 -> V_64 ,
( unsigned long long ) V_52 , V_64 ,
V_420 ? L_50 : L_51 ) ;
V_19 -> V_20 . V_80 = V_420 ? F_205 :
F_206 ;
F_157 ( & V_19 -> V_20 . V_21 , & V_10 -> V_78 ) ;
F_222 ( V_27 -> V_225 , & V_19 -> V_29 -> V_421 ) ;
V_77 = - V_422 ;
goto V_104;
} else {
struct V_346 * V_347 =
F_181 ( V_6 , struct V_346 , V_6 ) ;
if ( ! V_418 )
F_221 ( V_10 , L_47
L_52 ,
( unsigned long long ) V_6 -> V_52 , V_6 -> V_64 ,
( unsigned long long ) V_52 , V_64 ) ;
if ( V_347 -> V_375 & V_376 ||
! ( V_347 -> V_375 & V_377 ) ) {
V_77 = F_220 ( V_10 , & V_347 -> V_6 ) ;
if ( V_77 ) {
F_223 ( V_27 , F_72 ( V_105 , V_423 ) , V_107 ) ;
F_216 ( V_10 , V_52 , V_64 ) ;
goto V_104;
}
goto V_413;
}
V_19 -> V_69 |= V_388 ;
}
}
V_77 = 0 ;
V_104:
if ( V_77 )
F_162 ( V_10 , V_19 ) ;
return V_77 ;
}
static int F_224 ( struct V_26 * V_27 , struct V_171 * V_172 )
{
struct V_28 * V_29 ;
struct V_9 * V_10 ;
struct V_35 * V_36 ;
T_3 V_52 ;
struct V_18 * V_19 ;
struct V_370 * V_322 = V_172 -> V_96 ;
T_7 V_184 = F_125 ( V_322 -> V_424 ) ;
int V_302 , V_303 ;
T_7 V_425 ;
int V_77 , V_403 ;
V_29 = F_193 ( V_27 , V_172 -> V_30 ) ;
if ( ! V_29 )
return - V_108 ;
V_10 = V_29 -> V_10 ;
if ( ! F_140 ( V_10 ) ) {
int V_79 ;
V_77 = F_213 ( V_29 , V_184 ) ;
F_199 ( V_29 , V_360 , V_322 , V_172 -> V_64 ) ;
F_136 ( & V_27 -> V_282 -> V_271 ) ;
V_79 = F_176 ( V_29 , V_172 -> V_64 ) ;
if ( ! V_77 )
V_77 = V_79 ;
return V_77 ;
}
V_52 = F_194 ( V_322 -> V_52 ) ;
V_19 = F_168 ( V_29 , V_322 -> V_68 , V_52 , V_172 ) ;
if ( ! V_19 ) {
F_131 ( V_10 ) ;
return - V_108 ;
}
V_19 -> V_20 . V_80 = F_203 ;
V_19 -> V_65 = V_66 ;
V_19 -> V_69 |= V_426 ;
V_425 = F_125 ( V_322 -> V_425 ) ;
V_302 = F_215 ( V_425 ) ;
V_303 = F_214 ( V_425 ) ;
if ( V_172 -> V_169 == V_337 ) {
F_53 ( V_29 , V_19 -> V_6 . V_64 > 0 ) ;
F_53 ( V_29 , V_302 == V_412 ) ;
F_53 ( V_29 , V_19 -> V_67 == NULL ) ;
} else if ( V_19 -> V_67 == NULL ) {
F_53 ( V_10 , V_19 -> V_6 . V_64 == 0 ) ;
F_53 ( V_10 , V_425 & V_410 ) ;
}
if ( V_425 & V_427 )
V_19 -> V_69 |= V_385 ;
F_11 ( & V_27 -> V_274 ) ;
V_19 -> V_268 = V_27 -> V_282 ;
F_136 ( & V_19 -> V_268 -> V_271 ) ;
F_136 ( & V_19 -> V_268 -> V_277 ) ;
F_12 ( & V_27 -> V_274 ) ;
F_24 () ;
V_36 = F_32 ( V_29 -> V_27 -> V_35 ) ;
V_403 = V_36 -> V_404 ;
if ( V_29 -> V_27 -> V_186 < 100 ) {
switch ( V_36 -> V_428 ) {
case V_429 :
V_425 |= V_430 ;
break;
case V_431 :
V_425 |= V_432 ;
break;
}
}
F_28 () ;
if ( V_425 & V_430 ) {
V_19 -> V_69 |= V_381 ;
F_189 ( V_10 ) ;
}
if ( V_425 & V_432 ) {
F_184 ( V_29 , V_433 , V_19 ) ;
}
if ( V_403 ) {
F_53 ( V_10 , V_425 & V_430 ) ;
V_19 -> V_69 |= V_387 ;
V_77 = F_213 ( V_29 , V_184 ) ;
if ( V_77 )
goto V_434;
F_20 ( & V_10 -> V_24 -> V_25 ) ;
V_77 = F_218 ( V_10 , V_19 ) ;
if ( V_77 ) {
F_21 ( & V_10 -> V_24 -> V_25 ) ;
if ( V_77 == - V_422 ) {
F_131 ( V_10 ) ;
return 0 ;
}
goto V_434;
}
} else {
F_209 ( V_29 , V_184 ) ;
F_20 ( & V_10 -> V_24 -> V_25 ) ;
}
if ( ( V_19 -> V_69 & ( V_308 | V_309 ) ) == 0 )
F_157 ( & V_19 -> V_20 . V_21 , & V_10 -> V_311 ) ;
F_21 ( & V_10 -> V_24 -> V_25 ) ;
if ( V_10 -> V_382 . V_105 == V_435 )
F_225 ( V_10 -> V_81 , ! F_211 ( V_10 , V_19 ) ) ;
if ( V_10 -> V_382 . V_436 < V_437 ) {
F_226 ( V_10 , V_19 -> V_6 . V_52 , V_19 -> V_6 . V_64 ) ;
V_19 -> V_69 &= ~ V_385 ;
F_227 ( V_10 , & V_19 -> V_6 ) ;
V_19 -> V_69 |= V_73 ;
}
V_77 = F_155 ( V_10 , V_19 , V_302 , V_303 ,
V_438 ) ;
if ( ! V_77 )
return 0 ;
F_45 ( V_10 , L_43 ) ;
F_20 ( & V_10 -> V_24 -> V_25 ) ;
F_147 ( & V_19 -> V_20 . V_21 ) ;
F_162 ( V_10 , V_19 ) ;
F_21 ( & V_10 -> V_24 -> V_25 ) ;
if ( V_19 -> V_69 & V_73 ) {
V_19 -> V_69 &= ~ V_73 ;
F_56 ( V_10 , & V_19 -> V_6 ) ;
}
V_434:
F_143 ( V_27 , V_19 -> V_268 , V_276 | V_275 ) ;
F_131 ( V_10 ) ;
F_60 ( V_10 , V_19 ) ;
return V_77 ;
}
bool F_228 ( struct V_9 * V_10 , T_3 V_52 ,
bool V_439 )
{
struct V_440 * V_4 ;
bool V_441 = F_229 ( V_10 ) ;
if ( ! V_441 || V_439 )
return V_441 ;
F_20 ( & V_10 -> V_442 ) ;
V_4 = F_230 ( V_10 -> V_443 , F_231 ( V_52 ) ) ;
if ( V_4 ) {
struct V_444 * V_445 = F_232 ( V_4 , struct V_444 , V_446 ) ;
if ( F_69 ( V_447 , & V_445 -> V_69 ) )
V_441 = false ;
}
F_21 ( & V_10 -> V_442 ) ;
return V_441 ;
}
bool F_229 ( struct V_9 * V_10 )
{
struct V_448 * V_449 = V_10 -> V_256 -> V_257 -> V_450 -> V_451 ;
unsigned long V_452 , V_453 , V_454 ;
unsigned int V_455 ;
int V_456 ;
F_24 () ;
V_455 = F_32 ( V_10 -> V_256 -> V_291 ) -> V_455 ;
F_28 () ;
if ( V_455 == 0 )
return false ;
V_456 = ( int ) F_233 ( & V_449 -> V_457 , V_458 [ 0 ] ) +
( int ) F_233 ( & V_449 -> V_457 , V_458 [ 1 ] ) -
F_26 ( & V_10 -> V_363 ) ;
if ( F_26 ( & V_10 -> V_459 )
|| V_456 - V_10 -> V_460 > 64 ) {
unsigned long V_461 ;
int V_6 ;
V_10 -> V_460 = V_456 ;
V_6 = ( V_10 -> V_462 + V_463 - 1 ) % V_463 ;
if ( V_10 -> V_382 . V_105 == V_464 || V_10 -> V_382 . V_105 == V_465 )
V_461 = V_10 -> V_466 ;
else
V_461 = F_234 ( V_10 ) - V_10 -> V_467 ;
V_453 = ( ( long ) V_66 - ( long ) V_10 -> V_468 [ V_6 ] ) / V_44 ;
if ( ! V_453 )
V_453 ++ ;
V_452 = V_10 -> V_469 [ V_6 ] - V_461 ;
V_454 = F_235 ( V_452 / V_453 ) ;
if ( V_454 > V_455 )
return true ;
}
return false ;
}
static int F_236 ( struct V_26 * V_27 , struct V_171 * V_172 )
{
struct V_28 * V_29 ;
struct V_9 * V_10 ;
T_3 V_52 ;
T_3 V_327 ;
struct V_18 * V_19 ;
struct V_470 * V_471 = NULL ;
int V_64 , V_472 ;
unsigned int V_304 ;
struct V_473 * V_322 = V_172 -> V_96 ;
V_29 = F_193 ( V_27 , V_172 -> V_30 ) ;
if ( ! V_29 )
return - V_108 ;
V_10 = V_29 -> V_10 ;
V_327 = F_169 ( V_10 -> V_328 ) ;
V_52 = F_194 ( V_322 -> V_52 ) ;
V_64 = F_125 ( V_322 -> V_474 ) ;
if ( V_64 <= 0 || ! F_173 ( V_64 , 512 ) || V_64 > V_48 ) {
F_45 ( V_10 , L_53 , __FILE__ , __LINE__ ,
( unsigned long long ) V_52 , V_64 ) ;
return - V_234 ;
}
if ( V_52 + ( V_64 >> 9 ) > V_327 ) {
F_45 ( V_10 , L_53 , __FILE__ , __LINE__ ,
( unsigned long long ) V_52 , V_64 ) ;
return - V_234 ;
}
if ( ! F_237 ( V_10 , V_475 ) ) {
V_472 = 1 ;
switch ( V_172 -> V_169 ) {
case V_476 :
F_238 ( V_29 , V_477 , V_322 ) ;
break;
case V_478 :
case V_479 :
case V_480 :
case V_481 :
F_238 ( V_29 , V_482 , V_322 ) ;
break;
case V_483 :
V_472 = 0 ;
F_188 ( V_10 ) ;
F_239 ( V_29 , V_484 , V_52 , V_64 , V_485 ) ;
break;
default:
F_240 () ;
}
if ( V_472 && F_198 ( & V_373 ) )
F_45 ( V_10 , L_54
L_55 ) ;
return F_176 ( V_29 , V_172 -> V_64 ) ;
}
V_19 = F_42 ( V_29 , V_322 -> V_68 , V_52 , V_64 ,
V_64 , V_213 ) ;
if ( ! V_19 ) {
F_131 ( V_10 ) ;
return - V_254 ;
}
switch ( V_172 -> V_169 ) {
case V_476 :
V_19 -> V_20 . V_80 = V_486 ;
V_304 = V_487 ;
V_19 -> V_69 |= V_426 ;
goto V_488;
case V_478 :
V_19 -> V_69 |= V_489 ;
case V_479 :
V_19 -> V_20 . V_80 = V_490 ;
V_304 = V_491 ;
V_10 -> V_492 = F_241 ( V_52 ) ;
break;
case V_483 :
case V_480 :
V_304 = V_491 ;
V_471 = F_135 ( sizeof( * V_471 ) + V_172 -> V_64 , V_213 ) ;
if ( ! V_471 )
goto V_493;
V_471 -> V_329 = V_172 -> V_64 ;
V_471 -> V_71 = ( ( ( char * ) V_471 ) + sizeof( struct V_470 ) ) ;
V_19 -> V_71 = V_471 ;
V_19 -> V_69 |= V_70 ;
if ( F_73 ( V_29 -> V_27 , V_471 -> V_71 , V_172 -> V_64 ) )
goto V_493;
if ( V_172 -> V_169 == V_480 ) {
F_53 ( V_10 , V_29 -> V_27 -> V_186 >= 89 ) ;
V_19 -> V_20 . V_80 = V_494 ;
V_10 -> V_492 = F_241 ( V_52 ) ;
V_10 -> V_495 = true ;
} else if ( V_172 -> V_169 == V_483 ) {
F_38 ( V_64 >> 9 , & V_10 -> V_374 ) ;
V_19 -> V_20 . V_80 = V_496 ;
F_188 ( V_10 ) ;
goto V_497;
}
break;
case V_481 :
if ( V_10 -> V_498 == ~ ( T_3 ) 0 &&
V_29 -> V_27 -> V_186 >= 90 ) {
unsigned long V_499 = V_66 ;
int V_6 ;
V_10 -> V_498 = V_52 ;
V_10 -> V_500 = V_52 ;
V_10 -> V_466 = F_242 ( V_10 ) - F_241 ( V_52 ) ;
V_10 -> V_501 = V_10 -> V_466 ;
for ( V_6 = 0 ; V_6 < V_463 ; V_6 ++ ) {
V_10 -> V_469 [ V_6 ] = V_10 -> V_466 ;
V_10 -> V_468 [ V_6 ] = V_499 ;
}
F_68 ( V_10 , L_56 ,
( unsigned long long ) V_52 ) ;
}
V_19 -> V_20 . V_80 = V_502 ;
V_304 = V_491 ;
break;
default:
F_240 () ;
}
F_20 ( & V_10 -> V_24 -> V_25 ) ;
F_157 ( & V_19 -> V_20 . V_21 , & V_10 -> V_503 ) ;
F_21 ( & V_10 -> V_24 -> V_25 ) ;
F_243 ( V_27 , F_228 ) ;
if ( V_10 -> V_382 . V_504 != V_505
&& F_228 ( V_10 , V_52 , false ) )
F_244 ( V_44 / 10 ) ;
F_243 ( V_27 , V_506 ) ;
if ( V_506 ( V_10 , V_52 ) )
goto V_493;
V_497:
F_38 ( V_64 >> 9 , & V_10 -> V_363 ) ;
V_488:
F_243 ( V_27 , F_155 ) ;
F_189 ( V_10 ) ;
if ( F_155 ( V_10 , V_19 , V_507 , 0 ,
V_304 ) == 0 )
return 0 ;
F_45 ( V_10 , L_43 ) ;
V_493:
F_20 ( & V_10 -> V_24 -> V_25 ) ;
F_147 ( & V_19 -> V_20 . V_21 ) ;
F_21 ( & V_10 -> V_24 -> V_25 ) ;
F_131 ( V_10 ) ;
F_60 ( V_10 , V_19 ) ;
return - V_108 ;
}
static int F_245 ( struct V_28 * V_29 ) __must_hold( T_5 )
{
struct V_9 * V_10 = V_29 -> V_10 ;
int V_508 , V_504 , V_95 = - 100 ;
unsigned long V_509 , V_510 ;
enum V_511 V_512 ;
V_508 = V_10 -> V_256 -> V_513 . V_514 [ V_515 ] & 1 ;
V_504 = V_10 -> V_516 [ V_515 ] & 1 ;
V_510 = V_10 -> V_516 [ V_517 ] ;
V_509 = V_10 -> V_518 ;
F_24 () ;
V_512 = F_32 ( V_29 -> V_27 -> V_35 ) -> V_512 ;
F_28 () ;
switch ( V_512 ) {
case V_519 :
case V_520 :
case V_521 :
case V_522 :
F_45 ( V_10 , L_57 ) ;
break;
case V_523 :
break;
case V_524 :
if ( V_508 == 0 && V_504 == 1 ) {
V_95 = - 1 ;
break;
}
if ( V_508 == 1 && V_504 == 0 ) {
V_95 = 1 ;
break;
}
case V_525 :
if ( V_508 == 0 && V_504 == 1 ) {
V_95 = 1 ;
break;
}
if ( V_508 == 1 && V_504 == 0 ) {
V_95 = - 1 ;
break;
}
F_35 ( V_10 , L_58
L_59 ) ;
case V_526 :
if ( V_510 == 0 && V_509 == 0 ) {
V_95 = F_69 ( V_205 , & V_29 -> V_27 -> V_69 )
? - 1 : 1 ;
break;
} else {
if ( V_510 == 0 ) { V_95 = 1 ; break; }
if ( V_509 == 0 ) { V_95 = - 1 ; break; }
}
if ( V_512 == V_526 )
break;
case V_527 :
if ( V_509 < V_510 )
V_95 = - 1 ;
else if ( V_509 > V_510 )
V_95 = 1 ;
else
V_95 = F_69 ( V_205 , & V_29 -> V_27 -> V_69 )
? - 1 : 1 ;
break;
case V_528 :
V_95 = - 1 ;
break;
case V_529 :
V_95 = 1 ;
}
return V_95 ;
}
static int F_246 ( struct V_28 * V_29 ) __must_hold( T_5 )
{
struct V_9 * V_10 = V_29 -> V_10 ;
int V_530 , V_95 = - 100 ;
enum V_511 V_531 ;
F_24 () ;
V_531 = F_32 ( V_29 -> V_27 -> V_35 ) -> V_531 ;
F_28 () ;
switch ( V_531 ) {
case V_524 :
case V_525 :
case V_527 :
case V_528 :
case V_529 :
case V_526 :
F_45 ( V_10 , L_57 ) ;
break;
case V_523 :
break;
case V_519 :
V_530 = F_245 ( V_29 ) ;
if ( V_530 == - 1 && V_10 -> V_382 . V_532 == V_533 )
V_95 = V_530 ;
if ( V_530 == 1 && V_10 -> V_382 . V_532 == V_505 )
V_95 = V_530 ;
break;
case V_522 :
V_95 = F_245 ( V_29 ) ;
break;
case V_520 :
return V_10 -> V_382 . V_532 == V_505 ? 1 : - 1 ;
case V_521 :
V_530 = F_245 ( V_29 ) ;
if ( V_530 == - 1 && V_10 -> V_382 . V_532 == V_505 ) {
enum V_196 V_534 ;
V_534 = F_247 ( V_10 , V_198 , F_72 ( V_532 , V_533 ) ) ;
if ( V_534 != V_199 ) {
F_248 ( V_10 , L_60 ) ;
} else {
F_35 ( V_10 , L_61 ) ;
V_95 = V_530 ;
}
} else
V_95 = V_530 ;
}
return V_95 ;
}
static int F_249 ( struct V_28 * V_29 ) __must_hold( T_5 )
{
struct V_9 * V_10 = V_29 -> V_10 ;
int V_530 , V_95 = - 100 ;
enum V_511 V_535 ;
F_24 () ;
V_535 = F_32 ( V_29 -> V_27 -> V_35 ) -> V_535 ;
F_28 () ;
switch ( V_535 ) {
case V_524 :
case V_525 :
case V_527 :
case V_528 :
case V_529 :
case V_519 :
case V_520 :
case V_526 :
F_45 ( V_10 , L_57 ) ;
break;
case V_522 :
V_95 = F_245 ( V_29 ) ;
break;
case V_523 :
break;
case V_521 :
V_530 = F_245 ( V_29 ) ;
if ( V_530 == - 1 ) {
enum V_196 V_534 ;
V_534 = F_247 ( V_10 , V_198 , F_72 ( V_532 , V_533 ) ) ;
if ( V_534 != V_199 ) {
F_248 ( V_10 , L_60 ) ;
} else {
F_35 ( V_10 , L_61 ) ;
V_95 = V_530 ;
}
} else
V_95 = V_530 ;
}
return V_95 ;
}
static void F_250 ( struct V_9 * V_10 , char * V_536 , T_2 * V_514 ,
T_2 V_537 , T_2 V_69 )
{
if ( ! V_514 ) {
F_68 ( V_10 , L_62 , V_536 ) ;
return;
}
F_68 ( V_10 , L_63 ,
V_536 ,
( unsigned long long ) V_514 [ V_538 ] ,
( unsigned long long ) V_514 [ V_515 ] ,
( unsigned long long ) V_514 [ V_539 ] ,
( unsigned long long ) V_514 [ V_540 ] ,
( unsigned long long ) V_537 ,
( unsigned long long ) V_69 ) ;
}
static int F_251 ( struct V_9 * const V_10 , enum V_541 const V_542 , int * V_543 ) __must_hold( T_5 )
{
struct V_28 * const V_29 = F_252 ( V_10 ) ;
struct V_26 * const V_27 = V_29 ? V_29 -> V_27 : NULL ;
T_2 V_508 , V_504 ;
int V_6 , V_544 ;
V_508 = V_10 -> V_256 -> V_513 . V_514 [ V_538 ] & ~ ( ( T_2 ) 1 ) ;
V_504 = V_10 -> V_516 [ V_538 ] & ~ ( ( T_2 ) 1 ) ;
* V_543 = 10 ;
if ( V_508 == V_545 && V_504 == V_545 )
return 0 ;
* V_543 = 20 ;
if ( ( V_508 == V_545 || V_508 == ( T_2 ) 0 ) &&
V_504 != V_545 )
return - 2 ;
* V_543 = 30 ;
if ( V_508 != V_545 &&
( V_504 == V_545 || V_504 == ( T_2 ) 0 ) )
return 2 ;
if ( V_508 == V_504 ) {
int V_546 , V_292 ;
if ( V_10 -> V_516 [ V_515 ] == ( T_2 ) 0 && V_10 -> V_256 -> V_513 . V_514 [ V_515 ] != ( T_2 ) 0 ) {
if ( V_27 -> V_186 < 91 )
return - 1091 ;
if ( ( V_10 -> V_256 -> V_513 . V_514 [ V_515 ] & ~ ( ( T_2 ) 1 ) ) == ( V_10 -> V_516 [ V_539 ] & ~ ( ( T_2 ) 1 ) ) &&
( V_10 -> V_256 -> V_513 . V_514 [ V_539 ] & ~ ( ( T_2 ) 1 ) ) == ( V_10 -> V_516 [ V_539 + 1 ] & ~ ( ( T_2 ) 1 ) ) ) {
F_68 ( V_10 , L_64 ) ;
F_253 ( V_10 ) ;
V_10 -> V_256 -> V_513 . V_514 [ V_539 ] = V_10 -> V_256 -> V_513 . V_514 [ V_515 ] ;
V_10 -> V_256 -> V_513 . V_514 [ V_515 ] = 0 ;
F_250 ( V_10 , L_65 , V_10 -> V_256 -> V_513 . V_514 ,
V_10 -> V_382 . V_449 >= V_547 ? F_234 ( V_10 ) : 0 , 0 ) ;
* V_543 = 34 ;
} else {
F_68 ( V_10 , L_66 ) ;
* V_543 = 36 ;
}
return 1 ;
}
if ( V_10 -> V_256 -> V_513 . V_514 [ V_515 ] == ( T_2 ) 0 && V_10 -> V_516 [ V_515 ] != ( T_2 ) 0 ) {
if ( V_27 -> V_186 < 91 )
return - 1091 ;
if ( ( V_10 -> V_256 -> V_513 . V_514 [ V_539 ] & ~ ( ( T_2 ) 1 ) ) == ( V_10 -> V_516 [ V_515 ] & ~ ( ( T_2 ) 1 ) ) &&
( V_10 -> V_256 -> V_513 . V_514 [ V_539 + 1 ] & ~ ( ( T_2 ) 1 ) ) == ( V_10 -> V_516 [ V_539 ] & ~ ( ( T_2 ) 1 ) ) ) {
F_68 ( V_10 , L_67 ) ;
V_10 -> V_516 [ V_539 + 1 ] = V_10 -> V_516 [ V_539 ] ;
V_10 -> V_516 [ V_539 ] = V_10 -> V_516 [ V_515 ] ;
V_10 -> V_516 [ V_515 ] = 0UL ;
F_250 ( V_10 , L_68 , V_10 -> V_516 , V_10 -> V_516 [ V_517 ] , V_10 -> V_516 [ V_548 ] ) ;
* V_543 = 35 ;
} else {
F_68 ( V_10 , L_69 ) ;
* V_543 = 37 ;
}
return - 1 ;
}
V_546 = ( F_69 ( V_549 , & V_10 -> V_69 ) ? 1 : 0 ) +
( V_10 -> V_516 [ V_548 ] & 2 ) ;
* V_543 = 40 ;
if ( V_546 == 0 )
return 0 ;
if ( V_10 -> V_382 . V_532 == V_505 || V_542 == V_505 ) {
* V_543 = 41 ;
if ( ! ( V_27 -> V_550 & V_551 ) ) {
F_35 ( V_29 , L_70 ) ;
return - ( 0x10000 | V_552 | ( V_551 << 8 ) ) ;
}
if ( V_10 -> V_382 . V_532 == V_505 && V_542 == V_505 ) {
F_45 ( V_29 , L_71 ) ;
return - 100 ;
}
if ( V_10 -> V_382 . V_532 == V_505 )
return 1 ;
return - 1 ;
}
switch ( V_546 ) {
case 0 : return 0 ;
case 1 : return 1 ;
case 2 : return - 1 ;
case 3 :
V_292 = F_69 ( V_205 , & V_27 -> V_69 ) ;
return V_292 ? - 1 : 1 ;
}
}
* V_543 = 50 ;
V_504 = V_10 -> V_516 [ V_515 ] & ~ ( ( T_2 ) 1 ) ;
if ( V_508 == V_504 )
return - 1 ;
* V_543 = 51 ;
V_504 = V_10 -> V_516 [ V_539 ] & ~ ( ( T_2 ) 1 ) ;
if ( V_508 == V_504 ) {
if ( V_27 -> V_186 < 96 ?
( V_10 -> V_256 -> V_513 . V_514 [ V_539 ] & ~ ( ( T_2 ) 1 ) ) ==
( V_10 -> V_516 [ V_539 + 1 ] & ~ ( ( T_2 ) 1 ) ) :
V_504 + V_553 == ( V_10 -> V_516 [ V_515 ] & ~ ( ( T_2 ) 1 ) ) ) {
if ( V_27 -> V_186 < 91 )
return - 1091 ;
V_10 -> V_516 [ V_515 ] = V_10 -> V_516 [ V_539 ] ;
V_10 -> V_516 [ V_539 ] = V_10 -> V_516 [ V_539 + 1 ] ;
F_68 ( V_10 , L_72 ) ;
F_250 ( V_10 , L_68 , V_10 -> V_516 , V_10 -> V_516 [ V_517 ] , V_10 -> V_516 [ V_548 ] ) ;
return - 1 ;
}
}
* V_543 = 60 ;
V_508 = V_10 -> V_256 -> V_513 . V_514 [ V_538 ] & ~ ( ( T_2 ) 1 ) ;
for ( V_6 = V_539 ; V_6 <= V_540 ; V_6 ++ ) {
V_504 = V_10 -> V_516 [ V_6 ] & ~ ( ( T_2 ) 1 ) ;
if ( V_508 == V_504 )
return - 2 ;
}
* V_543 = 70 ;
V_508 = V_10 -> V_256 -> V_513 . V_514 [ V_515 ] & ~ ( ( T_2 ) 1 ) ;
V_504 = V_10 -> V_516 [ V_538 ] & ~ ( ( T_2 ) 1 ) ;
if ( V_508 == V_504 )
return 1 ;
* V_543 = 71 ;
V_508 = V_10 -> V_256 -> V_513 . V_514 [ V_539 ] & ~ ( ( T_2 ) 1 ) ;
if ( V_508 == V_504 ) {
if ( V_27 -> V_186 < 96 ?
( V_10 -> V_256 -> V_513 . V_514 [ V_539 + 1 ] & ~ ( ( T_2 ) 1 ) ) ==
( V_10 -> V_516 [ V_539 ] & ~ ( ( T_2 ) 1 ) ) :
V_508 + V_553 == ( V_10 -> V_256 -> V_513 . V_514 [ V_515 ] & ~ ( ( T_2 ) 1 ) ) ) {
if ( V_27 -> V_186 < 91 )
return - 1091 ;
F_254 ( V_10 , V_515 , V_10 -> V_256 -> V_513 . V_514 [ V_539 ] ) ;
F_254 ( V_10 , V_539 , V_10 -> V_256 -> V_513 . V_514 [ V_539 + 1 ] ) ;
F_68 ( V_10 , L_73 ) ;
F_250 ( V_10 , L_65 , V_10 -> V_256 -> V_513 . V_514 ,
V_10 -> V_382 . V_449 >= V_547 ? F_234 ( V_10 ) : 0 , 0 ) ;
return 1 ;
}
}
* V_543 = 80 ;
V_504 = V_10 -> V_516 [ V_538 ] & ~ ( ( T_2 ) 1 ) ;
for ( V_6 = V_539 ; V_6 <= V_540 ; V_6 ++ ) {
V_508 = V_10 -> V_256 -> V_513 . V_514 [ V_6 ] & ~ ( ( T_2 ) 1 ) ;
if ( V_508 == V_504 )
return 2 ;
}
* V_543 = 90 ;
V_508 = V_10 -> V_256 -> V_513 . V_514 [ V_515 ] & ~ ( ( T_2 ) 1 ) ;
V_504 = V_10 -> V_516 [ V_515 ] & ~ ( ( T_2 ) 1 ) ;
if ( V_508 == V_504 && V_508 != ( ( T_2 ) 0 ) )
return 100 ;
* V_543 = 100 ;
for ( V_6 = V_539 ; V_6 <= V_540 ; V_6 ++ ) {
V_508 = V_10 -> V_256 -> V_513 . V_514 [ V_6 ] & ~ ( ( T_2 ) 1 ) ;
for ( V_544 = V_539 ; V_544 <= V_540 ; V_544 ++ ) {
V_504 = V_10 -> V_516 [ V_544 ] & ~ ( ( T_2 ) 1 ) ;
if ( V_508 == V_504 )
return - 100 ;
}
}
return - 1000 ;
}
static enum V_554 F_255 ( struct V_28 * V_29 ,
enum V_541 V_542 ,
enum V_555 V_556 ) __must_hold( T_5 )
{
struct V_9 * V_10 = V_29 -> V_10 ;
enum V_554 V_95 = V_557 ;
enum V_555 V_558 ;
struct V_35 * V_36 ;
int V_530 , V_543 , V_559 , V_560 ;
V_558 = V_10 -> V_382 . V_449 ;
if ( V_558 == V_547 )
V_558 = V_10 -> V_561 . V_449 ;
F_68 ( V_10 , L_74 ) ;
F_20 ( & V_10 -> V_256 -> V_513 . V_562 ) ;
F_250 ( V_10 , L_65 , V_10 -> V_256 -> V_513 . V_514 , V_10 -> V_518 , 0 ) ;
F_250 ( V_10 , L_68 , V_10 -> V_516 ,
V_10 -> V_516 [ V_517 ] , V_10 -> V_516 [ V_548 ] ) ;
V_530 = F_251 ( V_10 , V_542 , & V_543 ) ;
F_21 ( & V_10 -> V_256 -> V_513 . V_562 ) ;
F_68 ( V_10 , L_75 , V_530 , V_543 ) ;
if ( V_530 == - 1000 ) {
F_221 ( V_10 , L_76 ) ;
return V_557 ;
}
if ( V_530 < - 0x10000 ) {
int V_563 , V_564 ;
V_530 = - V_530 ;
V_563 = V_530 & 0xff ;
V_564 = ( V_530 >> 8 ) & 0xff ;
F_221 ( V_10 , L_77 ,
V_563 , V_564 ) ;
return V_557 ;
}
if ( V_530 < - 1000 ) {
F_221 ( V_10 , L_78 , - V_530 - 1000 ) ;
return V_557 ;
}
if ( ( V_558 == V_437 && V_556 > V_437 ) ||
( V_556 == V_437 && V_558 > V_437 ) ) {
int V_565 = ( V_530 == - 100 ) || abs ( V_530 ) == 2 ;
V_530 = V_558 > V_437 ? 1 : - 1 ;
if ( V_565 )
V_530 = V_530 * 2 ;
F_68 ( V_10 , L_79 ,
V_530 > 0 ? L_80 : L_81 ) ;
}
if ( abs ( V_530 ) == 100 )
F_248 ( V_10 , L_82 ) ;
F_24 () ;
V_36 = F_32 ( V_29 -> V_27 -> V_35 ) ;
if ( V_530 == 100 || ( V_530 == - 100 && V_36 -> V_566 ) ) {
int V_567 = ( V_10 -> V_382 . V_532 == V_505 )
+ ( V_542 == V_505 ) ;
int V_568 = ( V_530 == - 100 ) ;
switch ( V_567 ) {
case 0 :
V_530 = F_245 ( V_29 ) ;
break;
case 1 :
V_530 = F_246 ( V_29 ) ;
break;
case 2 :
V_530 = F_249 ( V_29 ) ;
break;
}
if ( abs ( V_530 ) < 100 ) {
F_35 ( V_10 , L_83
L_84 ,
V_567 , ( V_530 < 0 ) ? L_68 : L_85 ) ;
if ( V_568 ) {
F_35 ( V_10 , L_86
L_87 ) ;
V_530 = V_530 * 2 ;
}
}
}
if ( V_530 == - 100 ) {
if ( F_69 ( V_223 , & V_10 -> V_69 ) && ! ( V_10 -> V_516 [ V_548 ] & 1 ) )
V_530 = - 1 ;
if ( ! F_69 ( V_223 , & V_10 -> V_69 ) && ( V_10 -> V_516 [ V_548 ] & 1 ) )
V_530 = 1 ;
if ( abs ( V_530 ) < 100 )
F_35 ( V_10 , L_88
L_89 ,
( V_530 < 0 ) ? L_68 : L_85 ) ;
}
V_559 = V_36 -> V_559 ;
V_560 = V_36 -> V_560 ;
F_28 () ;
if ( V_530 == - 100 ) {
F_221 ( V_10 , L_90 ) ;
F_248 ( V_10 , L_91 ) ;
return V_557 ;
}
if ( V_530 > 0 && V_558 <= V_437 ) {
F_45 ( V_10 , L_92 ) ;
return V_557 ;
}
if ( V_530 < 0 &&
V_10 -> V_382 . V_532 == V_505 && V_10 -> V_382 . V_449 >= V_569 ) {
switch ( V_559 ) {
case V_521 :
F_248 ( V_10 , L_93 ) ;
case V_523 :
F_45 ( V_10 , L_94 ) ;
return V_557 ;
case V_522 :
F_35 ( V_10 , L_95
L_96 ) ;
}
}
if ( V_560 || F_69 ( V_570 , & V_29 -> V_27 -> V_69 ) ) {
if ( V_530 == 0 )
F_68 ( V_10 , L_97 ) ;
else
F_68 ( V_10 , L_98 ,
F_256 ( V_530 > 0 ? V_383 : V_435 ) ,
abs ( V_530 ) >= 2 ? L_99 : L_100 ) ;
return V_557 ;
}
if ( abs ( V_530 ) >= 2 ) {
F_68 ( V_10 , L_101 ) ;
if ( F_257 ( V_10 , & V_571 , L_102 ,
V_572 ) )
return V_557 ;
}
if ( V_530 > 0 ) {
V_95 = V_573 ;
} else if ( V_530 < 0 ) {
V_95 = V_574 ;
} else {
V_95 = V_575 ;
if ( F_234 ( V_10 ) ) {
F_68 ( V_10 , L_103 ,
F_234 ( V_10 ) ) ;
}
}
return V_95 ;
}
static enum V_511 F_258 ( enum V_511 V_504 )
{
if ( V_504 == V_529 )
return V_528 ;
if ( V_504 == V_528 )
return V_529 ;
return V_504 ;
}
static int F_259 ( struct V_26 * V_27 , struct V_171 * V_172 )
{
struct V_576 * V_322 = V_172 -> V_96 ;
enum V_511 V_577 , V_578 , V_579 ;
int V_580 , V_581 , V_582 , V_583 ;
struct V_35 * V_36 , * V_584 , * V_585 = NULL ;
char V_586 [ V_587 ] = L_104 ;
struct V_324 * V_340 = NULL ;
void * V_332 = NULL , * V_334 = NULL ;
V_580 = F_125 ( V_322 -> V_588 ) ;
V_577 = F_125 ( V_322 -> V_512 ) ;
V_578 = F_125 ( V_322 -> V_531 ) ;
V_579 = F_125 ( V_322 -> V_535 ) ;
V_582 = F_125 ( V_322 -> V_404 ) ;
V_583 = F_125 ( V_322 -> V_589 ) ;
V_581 = V_583 & V_590 ;
if ( V_27 -> V_186 >= 87 ) {
int V_77 ;
if ( V_172 -> V_64 > sizeof( V_586 ) )
return - V_108 ;
V_77 = F_73 ( V_27 , V_586 , V_172 -> V_64 ) ;
if ( V_77 )
return V_77 ;
V_586 [ V_587 - 1 ] = 0 ;
}
if ( V_172 -> V_169 != V_591 ) {
F_106 ( V_570 , & V_27 -> V_69 ) ;
if ( V_583 & V_592 )
F_111 ( V_570 , & V_27 -> V_69 ) ;
F_24 () ;
V_36 = F_32 ( V_27 -> V_35 ) ;
if ( V_580 != V_36 -> V_428 ) {
F_45 ( V_27 , L_105 , L_106 ) ;
goto V_593;
}
if ( F_258 ( V_577 ) != V_36 -> V_512 ) {
F_45 ( V_27 , L_105 , L_107 ) ;
goto V_593;
}
if ( F_258 ( V_578 ) != V_36 -> V_531 ) {
F_45 ( V_27 , L_105 , L_108 ) ;
goto V_593;
}
if ( F_258 ( V_579 ) != V_36 -> V_535 ) {
F_45 ( V_27 , L_105 , L_109 ) ;
goto V_593;
}
if ( V_581 && V_36 -> V_195 ) {
F_45 ( V_27 , L_105 , L_110 ) ;
goto V_593;
}
if ( V_582 != V_36 -> V_404 ) {
F_45 ( V_27 , L_105 , L_111 ) ;
goto V_593;
}
if ( strcmp ( V_586 , V_36 -> V_586 ) ) {
F_45 ( V_27 , L_105 , L_112 ) ;
goto V_593;
}
F_28 () ;
}
if ( V_586 [ 0 ] ) {
int V_594 ;
V_340 = F_260 ( V_586 , 0 , V_595 ) ;
if ( F_261 ( V_340 ) ) {
V_340 = NULL ;
F_45 ( V_27 , L_113 ,
V_586 ) ;
goto V_596;
}
V_594 = F_170 ( V_340 ) ;
V_332 = F_135 ( V_594 , V_597 ) ;
V_334 = F_135 ( V_594 , V_597 ) ;
if ( ! ( V_332 && V_334 ) ) {
F_45 ( V_27 , L_114 ) ;
goto V_596;
}
}
V_585 = F_135 ( sizeof( struct V_35 ) , V_597 ) ;
if ( ! V_585 ) {
F_45 ( V_27 , L_115 ) ;
goto V_596;
}
F_119 ( & V_27 -> V_96 . V_200 ) ;
F_119 ( & V_27 -> V_24 -> V_228 ) ;
V_584 = V_27 -> V_35 ;
* V_585 = * V_584 ;
V_585 -> V_428 = V_580 ;
V_585 -> V_512 = F_258 ( V_577 ) ;
V_585 -> V_531 = F_258 ( V_578 ) ;
V_585 -> V_535 = F_258 ( V_579 ) ;
V_585 -> V_404 = V_582 ;
F_262 ( V_27 -> V_35 , V_585 ) ;
F_120 ( & V_27 -> V_24 -> V_228 ) ;
F_120 ( & V_27 -> V_96 . V_200 ) ;
F_263 ( V_27 -> V_340 ) ;
F_52 ( V_27 -> V_332 ) ;
F_52 ( V_27 -> V_334 ) ;
V_27 -> V_340 = V_340 ;
V_27 -> V_332 = V_332 ;
V_27 -> V_334 = V_334 ;
if ( strcmp ( V_584 -> V_586 , V_586 ) )
F_68 ( V_27 , L_116 ,
V_586 [ 0 ] ? V_586 : L_117 ) ;
F_264 () ;
F_52 ( V_584 ) ;
return 0 ;
V_593:
F_28 () ;
V_596:
F_263 ( V_340 ) ;
F_52 ( V_332 ) ;
F_52 ( V_334 ) ;
F_71 ( V_27 , F_72 ( V_105 , V_151 ) , V_107 ) ;
return - V_108 ;
}
static struct V_324 * F_265 ( const struct V_9 * V_10 ,
const char * V_598 , const char * V_227 )
{
struct V_324 * V_599 ;
if ( ! V_598 [ 0 ] )
return NULL ;
V_599 = F_260 ( V_598 , 0 , V_595 ) ;
if ( F_261 ( V_599 ) ) {
F_45 ( V_10 , L_118 ,
V_598 , V_227 , F_266 ( V_599 ) ) ;
return V_599 ;
}
return V_599 ;
}
static int F_267 ( struct V_26 * V_27 , struct V_171 * V_172 )
{
void * V_243 = V_27 -> V_96 . V_173 ;
int V_64 = V_172 -> V_64 ;
while ( V_64 ) {
int V_203 = F_77 ( int , V_64 , V_600 ) ;
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
static int F_268 ( struct V_26 * V_27 , struct V_171 * V_172 )
{
F_35 ( V_27 , L_119 ,
F_269 ( V_172 -> V_169 ) , V_172 -> V_30 ) ;
return F_267 ( V_27 , V_172 ) ;
}
static int F_270 ( struct V_26 * V_27 , struct V_171 * V_172 )
{
struct V_28 * V_29 ;
struct V_9 * V_10 ;
struct V_601 * V_322 ;
unsigned int V_170 , V_306 , V_602 ;
struct V_324 * V_603 = NULL ;
struct V_324 * V_604 = NULL ;
struct V_35 * V_584 , * V_585 = NULL ;
struct V_291 * V_605 = NULL , * V_606 = NULL ;
const int V_607 = V_27 -> V_186 ;
struct V_608 * V_609 = NULL , * V_610 = NULL ;
int V_611 = 0 ;
int V_77 ;
V_29 = F_193 ( V_27 , V_172 -> V_30 ) ;
if ( ! V_29 )
return F_268 ( V_27 , V_172 ) ;
V_10 = V_29 -> V_10 ;
V_602 = V_607 <= 87 ? sizeof( struct V_612 )
: V_607 == 88 ? sizeof( struct V_612 )
+ V_587
: V_607 <= 94 ? sizeof( struct V_613 )
: sizeof( struct V_601 ) ;
if ( V_172 -> V_64 > V_602 ) {
F_45 ( V_10 , L_120 ,
V_172 -> V_64 , V_602 ) ;
return - V_108 ;
}
if ( V_607 <= 88 ) {
V_170 = sizeof( struct V_612 ) ;
V_306 = V_172 -> V_64 - V_170 ;
} else if ( V_607 <= 94 ) {
V_170 = sizeof( struct V_613 ) ;
V_306 = V_172 -> V_64 - V_170 ;
F_53 ( V_10 , V_306 == 0 ) ;
} else {
V_170 = sizeof( struct V_601 ) ;
V_306 = V_172 -> V_64 - V_170 ;
F_53 ( V_10 , V_306 == 0 ) ;
}
V_322 = V_172 -> V_96 ;
memset ( V_322 -> V_614 , 0 , 2 * V_587 ) ;
V_77 = F_73 ( V_29 -> V_27 , V_322 , V_170 ) ;
if ( V_77 )
return V_77 ;
F_119 ( & V_27 -> V_24 -> V_228 ) ;
V_584 = V_29 -> V_27 -> V_35 ;
if ( F_140 ( V_10 ) ) {
V_606 = F_271 ( sizeof( struct V_291 ) , V_597 ) ;
if ( ! V_606 ) {
F_131 ( V_10 ) ;
F_120 ( & V_27 -> V_24 -> V_228 ) ;
F_45 ( V_10 , L_121 ) ;
return - V_254 ;
}
V_605 = V_10 -> V_256 -> V_291 ;
* V_606 = * V_605 ;
V_606 -> V_615 = F_125 ( V_322 -> V_615 ) ;
}
if ( V_607 >= 88 ) {
if ( V_607 == 88 ) {
if ( V_306 > V_587 || V_306 == 0 ) {
F_45 ( V_10 , L_122
L_123 ,
V_306 , V_587 ) ;
V_77 = - V_108 ;
goto V_616;
}
V_77 = F_73 ( V_29 -> V_27 , V_322 -> V_614 , V_306 ) ;
if ( V_77 )
goto V_616;
F_53 ( V_10 , V_322 -> V_614 [ V_306 - 1 ] == 0 ) ;
V_322 -> V_614 [ V_306 - 1 ] = 0 ;
} else {
F_53 ( V_10 , V_322 -> V_614 [ V_587 - 1 ] == 0 ) ;
F_53 ( V_10 , V_322 -> V_617 [ V_587 - 1 ] == 0 ) ;
V_322 -> V_614 [ V_587 - 1 ] = 0 ;
V_322 -> V_617 [ V_587 - 1 ] = 0 ;
}
if ( strcmp ( V_584 -> V_614 , V_322 -> V_614 ) ) {
if ( V_10 -> V_382 . V_105 == V_103 ) {
F_45 ( V_10 , L_124 ,
V_584 -> V_614 , V_322 -> V_614 ) ;
goto V_596;
}
V_603 = F_265 ( V_10 ,
V_322 -> V_614 , L_125 ) ;
if ( F_261 ( V_603 ) ) {
V_603 = NULL ;
goto V_596;
}
}
if ( V_607 >= 89 && strcmp ( V_584 -> V_617 , V_322 -> V_617 ) ) {
if ( V_10 -> V_382 . V_105 == V_103 ) {
F_45 ( V_10 , L_126 ,
V_584 -> V_617 , V_322 -> V_617 ) ;
goto V_596;
}
V_604 = F_265 ( V_10 ,
V_322 -> V_617 , L_127 ) ;
if ( F_261 ( V_604 ) ) {
V_604 = NULL ;
goto V_596;
}
}
if ( V_607 > 94 && V_606 ) {
V_606 -> V_618 = F_125 ( V_322 -> V_618 ) ;
V_606 -> V_619 = F_125 ( V_322 -> V_619 ) ;
V_606 -> V_620 = F_125 ( V_322 -> V_620 ) ;
V_606 -> V_621 = F_125 ( V_322 -> V_621 ) ;
V_611 = ( V_606 -> V_618 * 10 * V_622 ) / V_44 ;
if ( V_611 != V_10 -> V_623 -> V_64 ) {
V_610 = F_272 ( V_611 ) ;
if ( ! V_610 ) {
F_45 ( V_10 , L_128 ) ;
F_131 ( V_10 ) ;
goto V_596;
}
}
}
if ( V_603 || V_604 ) {
V_585 = F_271 ( sizeof( struct V_35 ) , V_597 ) ;
if ( ! V_585 ) {
F_45 ( V_10 , L_115 ) ;
goto V_596;
}
* V_585 = * V_584 ;
if ( V_603 ) {
strcpy ( V_585 -> V_614 , V_322 -> V_614 ) ;
V_585 -> V_624 = strlen ( V_322 -> V_614 ) + 1 ;
F_263 ( V_29 -> V_27 -> V_603 ) ;
V_29 -> V_27 -> V_603 = V_603 ;
F_68 ( V_10 , L_129 , V_322 -> V_614 ) ;
}
if ( V_604 ) {
strcpy ( V_585 -> V_617 , V_322 -> V_617 ) ;
V_585 -> V_625 = strlen ( V_322 -> V_617 ) + 1 ;
F_263 ( V_29 -> V_27 -> V_604 ) ;
V_29 -> V_27 -> V_604 = V_604 ;
F_68 ( V_10 , L_130 , V_322 -> V_617 ) ;
}
F_262 ( V_27 -> V_35 , V_585 ) ;
}
}
if ( V_606 ) {
F_262 ( V_10 -> V_256 -> V_291 , V_606 ) ;
F_131 ( V_10 ) ;
}
if ( V_610 ) {
V_609 = V_10 -> V_623 ;
F_262 ( V_10 -> V_623 , V_610 ) ;
}
F_120 ( & V_27 -> V_24 -> V_228 ) ;
F_264 () ;
if ( V_585 )
F_52 ( V_584 ) ;
F_52 ( V_605 ) ;
F_52 ( V_609 ) ;
return 0 ;
V_616:
if ( V_606 ) {
F_131 ( V_10 ) ;
F_52 ( V_606 ) ;
}
F_120 ( & V_27 -> V_24 -> V_228 ) ;
return - V_108 ;
V_596:
F_52 ( V_610 ) ;
if ( V_606 ) {
F_131 ( V_10 ) ;
F_52 ( V_606 ) ;
}
F_120 ( & V_27 -> V_24 -> V_228 ) ;
F_263 ( V_604 ) ;
F_263 ( V_603 ) ;
F_71 ( V_29 -> V_27 , F_72 ( V_105 , V_151 ) , V_107 ) ;
return - V_108 ;
}
static void F_273 ( struct V_9 * V_10 ,
const char * V_203 , T_3 V_47 , T_3 V_392 )
{
T_3 V_326 ;
if ( V_47 == 0 || V_392 == 0 )
return;
V_326 = ( V_47 > V_392 ) ? ( V_47 - V_392 ) : ( V_392 - V_47 ) ;
if ( V_326 > ( V_47 >> 3 ) || V_326 > ( V_392 >> 3 ) )
F_35 ( V_10 , L_131 , V_203 ,
( unsigned long long ) V_47 , ( unsigned long long ) V_392 ) ;
}
static int F_274 ( struct V_26 * V_27 , struct V_171 * V_172 )
{
struct V_28 * V_29 ;
struct V_9 * V_10 ;
struct V_626 * V_322 = V_172 -> V_96 ;
struct V_627 * V_628 = ( V_27 -> V_550 & V_551 ) ? V_322 -> V_629 : NULL ;
enum V_630 V_631 = V_632 ;
T_3 V_633 , V_634 , V_635 , V_636 ;
int V_637 = 0 ;
enum V_638 V_639 ;
V_29 = F_193 ( V_27 , V_172 -> V_30 ) ;
if ( ! V_29 )
return F_268 ( V_27 , V_172 ) ;
V_10 = V_29 -> V_10 ;
V_633 = F_194 ( V_322 -> V_640 ) ;
V_634 = F_194 ( V_322 -> V_641 ) ;
V_635 = F_194 ( V_322 -> V_642 ) ;
V_10 -> V_633 = V_633 ;
if ( F_140 ( V_10 ) ) {
T_3 V_643 , V_644 ;
F_24 () ;
V_636 = F_32 ( V_10 -> V_256 -> V_291 ) -> V_645 ;
F_28 () ;
F_273 ( V_10 , L_132 ,
V_633 , F_275 ( V_10 -> V_256 ) ) ;
F_273 ( V_10 , L_133 ,
V_634 , V_636 ) ;
if ( V_10 -> V_382 . V_105 == V_103 )
V_634 = F_276 ( V_636 , V_634 ) ;
V_643 = F_277 ( V_10 , V_10 -> V_256 , V_634 , 0 ) ;
V_644 = F_169 ( V_10 -> V_328 ) ;
if ( V_643 < V_644 &&
V_10 -> V_382 . V_449 >= V_646 &&
V_10 -> V_382 . V_105 < V_575 ) {
F_45 ( V_10 , L_134 ,
( unsigned long long ) V_643 , ( unsigned long long ) V_644 ) ;
F_71 ( V_29 -> V_27 , F_72 ( V_105 , V_151 ) , V_107 ) ;
F_131 ( V_10 ) ;
return - V_108 ;
}
if ( V_636 != V_634 ) {
struct V_291 * V_605 , * V_606 = NULL ;
V_606 = F_271 ( sizeof( struct V_291 ) , V_597 ) ;
if ( ! V_606 ) {
F_45 ( V_10 , L_121 ) ;
F_131 ( V_10 ) ;
return - V_254 ;
}
F_119 ( & V_27 -> V_24 -> V_228 ) ;
V_605 = V_10 -> V_256 -> V_291 ;
* V_606 = * V_605 ;
V_606 -> V_645 = V_634 ;
F_262 ( V_10 -> V_256 -> V_291 , V_606 ) ;
F_120 ( & V_27 -> V_24 -> V_228 ) ;
F_264 () ;
F_52 ( V_605 ) ;
F_68 ( V_10 , L_135 ,
( unsigned long ) V_636 ) ;
}
F_131 ( V_10 ) ;
}
V_10 -> V_647 = F_125 ( V_322 -> V_648 ) ;
V_639 = F_124 ( V_322 -> V_638 ) ;
if ( F_140 ( V_10 ) ) {
F_278 ( V_10 , V_10 -> V_256 , V_628 ) ;
V_631 = F_279 ( V_10 , V_639 , NULL ) ;
F_131 ( V_10 ) ;
if ( V_631 == V_649 )
return - V_108 ;
F_280 ( V_10 ) ;
} else {
F_278 ( V_10 , NULL , V_628 ) ;
F_281 ( V_10 , V_635 ? : V_634 ? : V_633 ) ;
}
if ( F_140 ( V_10 ) ) {
if ( V_10 -> V_256 -> V_650 != F_169 ( V_10 -> V_256 -> V_257 ) ) {
V_10 -> V_256 -> V_650 = F_169 ( V_10 -> V_256 -> V_257 ) ;
V_637 = 1 ;
}
F_131 ( V_10 ) ;
}
if ( V_10 -> V_382 . V_105 > V_103 ) {
if ( F_194 ( V_322 -> V_642 ) !=
F_169 ( V_10 -> V_328 ) || V_637 ) {
F_103 ( V_29 , 0 , V_639 ) ;
}
if ( F_282 ( V_190 , & V_10 -> V_69 ) ||
( V_631 == V_651 && V_10 -> V_382 . V_105 == V_575 ) ) {
if ( V_10 -> V_382 . V_436 >= V_437 &&
V_10 -> V_382 . V_449 >= V_437 ) {
if ( V_639 & V_652 )
F_68 ( V_10 , L_136 ) ;
else
F_283 ( V_10 ) ;
} else
F_111 ( V_653 , & V_10 -> V_69 ) ;
}
}
return 0 ;
}
static int F_284 ( struct V_26 * V_27 , struct V_171 * V_172 )
{
struct V_28 * V_29 ;
struct V_9 * V_10 ;
struct V_654 * V_322 = V_172 -> V_96 ;
T_2 * V_516 ;
int V_6 , V_655 = 0 ;
V_29 = F_193 ( V_27 , V_172 -> V_30 ) ;
if ( ! V_29 )
return F_268 ( V_27 , V_172 ) ;
V_10 = V_29 -> V_10 ;
V_516 = F_135 ( sizeof( T_2 ) * V_656 , V_213 ) ;
if ( ! V_516 ) {
F_45 ( V_10 , L_137 ) ;
return false ;
}
for ( V_6 = V_538 ; V_6 < V_656 ; V_6 ++ )
V_516 [ V_6 ] = F_194 ( V_322 -> V_514 [ V_6 ] ) ;
F_52 ( V_10 -> V_516 ) ;
V_10 -> V_516 = V_516 ;
if ( V_10 -> V_382 . V_105 < V_575 &&
V_10 -> V_382 . V_449 < V_437 &&
V_10 -> V_382 . V_532 == V_505 &&
( V_10 -> V_657 & ~ ( ( T_2 ) 1 ) ) != ( V_516 [ V_538 ] & ~ ( ( T_2 ) 1 ) ) ) {
F_45 ( V_10 , L_138 ,
( unsigned long long ) V_10 -> V_657 ) ;
F_71 ( V_29 -> V_27 , F_72 ( V_105 , V_151 ) , V_107 ) ;
return - V_108 ;
}
if ( F_140 ( V_10 ) ) {
int V_658 =
V_10 -> V_382 . V_105 == V_575 &&
V_29 -> V_27 -> V_186 >= 90 &&
V_10 -> V_256 -> V_513 . V_514 [ V_538 ] == V_545 &&
( V_516 [ V_548 ] & 8 ) ;
if ( V_658 ) {
F_68 ( V_10 , L_139 ) ;
F_257 ( V_10 , & V_659 ,
L_140 ,
V_660 ) ;
F_285 ( V_10 , V_538 , V_516 [ V_538 ] ) ;
F_285 ( V_10 , V_515 , 0 ) ;
F_286 ( F_287 ( V_10 , V_449 , V_475 , V_436 , V_475 ) ,
V_198 , NULL ) ;
F_280 ( V_10 ) ;
V_655 = 1 ;
}
F_131 ( V_10 ) ;
} else if ( V_10 -> V_382 . V_449 < V_437 &&
V_10 -> V_382 . V_532 == V_505 ) {
V_655 = F_288 ( V_10 , V_516 [ V_538 ] ) ;
}
F_119 ( V_10 -> V_185 ) ;
F_120 ( V_10 -> V_185 ) ;
if ( V_10 -> V_382 . V_105 >= V_575 && V_10 -> V_382 . V_449 < V_437 )
V_655 |= F_288 ( V_10 , V_516 [ V_538 ] ) ;
if ( V_655 )
F_289 ( V_10 , L_141 ) ;
return 0 ;
}
static union V_661 F_290 ( union V_661 V_662 )
{
union V_661 V_663 ;
static enum V_554 V_664 [] = {
[ V_103 ] = V_103 ,
[ V_575 ] = V_575 ,
[ V_665 ] = V_666 ,
[ V_666 ] = V_665 ,
[ V_151 ] = V_667 ,
[ V_464 ] = V_465 ,
[ V_557 ] = V_557 ,
} ;
V_663 . V_6 = V_662 . V_6 ;
V_663 . V_105 = V_664 [ V_662 . V_105 ] ;
V_663 . V_504 = V_662 . V_532 ;
V_663 . V_532 = V_662 . V_504 ;
V_663 . V_436 = V_662 . V_449 ;
V_663 . V_449 = V_662 . V_436 ;
V_663 . V_668 = ( V_662 . V_669 | V_662 . V_670 ) ;
return V_663 ;
}
static int F_291 ( struct V_26 * V_27 , struct V_171 * V_172 )
{
struct V_28 * V_29 ;
struct V_9 * V_10 ;
struct V_671 * V_322 = V_172 -> V_96 ;
union V_661 V_672 , V_673 ;
enum V_196 V_95 ;
V_29 = F_193 ( V_27 , V_172 -> V_30 ) ;
if ( ! V_29 )
return - V_108 ;
V_10 = V_29 -> V_10 ;
V_672 . V_6 = F_125 ( V_322 -> V_672 ) ;
V_673 . V_6 = F_125 ( V_322 -> V_673 ) ;
if ( F_69 ( V_205 , & V_29 -> V_27 -> V_69 ) &&
F_292 ( V_10 -> V_185 ) ) {
F_293 ( V_29 , V_674 ) ;
return 0 ;
}
V_672 = F_290 ( V_672 ) ;
V_673 = F_290 ( V_673 ) ;
V_95 = F_247 ( V_10 , V_198 , V_672 , V_673 ) ;
F_293 ( V_29 , V_95 ) ;
F_280 ( V_10 ) ;
return 0 ;
}
static int F_294 ( struct V_26 * V_27 , struct V_171 * V_172 )
{
struct V_671 * V_322 = V_172 -> V_96 ;
union V_661 V_672 , V_673 ;
enum V_196 V_95 ;
V_672 . V_6 = F_125 ( V_322 -> V_672 ) ;
V_673 . V_6 = F_125 ( V_322 -> V_673 ) ;
if ( F_69 ( V_205 , & V_27 -> V_69 ) &&
F_292 ( & V_27 -> V_187 ) ) {
F_295 ( V_27 , V_674 ) ;
return 0 ;
}
V_672 = F_290 ( V_672 ) ;
V_673 = F_290 ( V_673 ) ;
V_95 = F_71 ( V_27 , V_672 , V_673 , V_198 | V_675 | V_676 ) ;
F_295 ( V_27 , V_95 ) ;
return 0 ;
}
static int F_296 ( struct V_26 * V_27 , struct V_171 * V_172 )
{
struct V_28 * V_29 ;
struct V_9 * V_10 ;
struct V_677 * V_322 = V_172 -> V_96 ;
union V_661 V_678 , V_679 , V_680 ;
enum V_555 V_681 ;
enum V_682 V_683 ;
int V_95 ;
V_29 = F_193 ( V_27 , V_172 -> V_30 ) ;
if ( ! V_29 )
return F_268 ( V_27 , V_172 ) ;
V_10 = V_29 -> V_10 ;
V_680 . V_6 = F_125 ( V_322 -> V_382 ) ;
V_681 = V_680 . V_449 ;
if ( V_680 . V_449 == V_547 ) {
V_681 = V_10 -> V_516 [ V_548 ] & 4 ? V_437 : V_569 ;
F_68 ( V_10 , L_142 , F_297 ( V_681 ) ) ;
}
F_20 ( & V_10 -> V_24 -> V_25 ) ;
V_34:
V_678 = V_679 = F_298 ( V_10 ) ;
F_21 ( & V_10 -> V_24 -> V_25 ) ;
if ( V_678 . V_105 <= V_667 )
return - V_97 ;
if ( ( V_678 . V_436 == V_437 || V_678 . V_436 == V_569 ) &&
V_681 == V_475 &&
V_678 . V_105 > V_575 && V_678 . V_449 == V_475 ) {
if ( V_680 . V_105 > V_575 &&
V_680 . V_105 < V_383 )
V_681 = V_437 ;
else if ( V_678 . V_105 >= V_383 &&
V_680 . V_105 == V_575 ) {
if ( F_234 ( V_10 ) <= V_10 -> V_467 )
F_299 ( V_10 ) ;
return 0 ;
}
}
if ( V_678 . V_105 == V_465 && V_678 . V_449 == V_475 &&
V_680 . V_105 == V_575 && V_681 == V_475 ) {
F_300 ( V_10 ) ;
F_299 ( V_10 ) ;
return 0 ;
}
if ( V_678 . V_436 == V_475 && V_681 == V_437 &&
V_678 . V_105 == V_575 && V_680 . V_105 > V_383 )
V_681 = V_475 ;
if ( V_679 . V_105 == V_103 )
V_679 . V_105 = V_575 ;
if ( V_680 . V_105 == V_684 )
V_679 . V_105 = V_685 ;
if ( V_10 -> V_516 && V_680 . V_449 >= V_547 &&
F_237 ( V_10 , V_547 ) ) {
int V_686 ;
V_686 = ( V_678 . V_105 < V_575 ) ;
V_686 |= ( V_678 . V_105 == V_575 &&
( V_680 . V_449 == V_547 ||
V_678 . V_449 == V_547 ) ) ;
V_686 |= F_69 ( V_687 , & V_10 -> V_69 ) ;
V_686 |= ( V_678 . V_105 == V_575 &&
( V_680 . V_105 >= V_665 &&
V_680 . V_105 <= V_574 ) ) ;
if ( V_686 )
V_679 . V_105 = F_255 ( V_29 , V_680 . V_532 , V_681 ) ;
F_131 ( V_10 ) ;
if ( V_679 . V_105 == V_557 ) {
V_679 . V_105 = V_575 ;
if ( V_10 -> V_382 . V_449 == V_547 ) {
F_301 ( V_10 , F_72 ( V_449 , V_688 ) ) ;
} else if ( V_680 . V_449 == V_547 ) {
F_45 ( V_10 , L_143 ) ;
V_680 . V_449 = V_689 ;
V_681 = V_689 ;
} else {
if ( F_282 ( V_570 , & V_29 -> V_27 -> V_69 ) )
return - V_108 ;
F_53 ( V_10 , V_678 . V_105 == V_103 ) ;
F_71 ( V_29 -> V_27 , F_72 ( V_105 , V_151 ) , V_107 ) ;
return - V_108 ;
}
}
}
F_20 ( & V_10 -> V_24 -> V_25 ) ;
if ( V_678 . V_6 != F_298 ( V_10 ) . V_6 )
goto V_34;
F_106 ( V_687 , & V_10 -> V_69 ) ;
V_679 . V_504 = V_680 . V_532 ;
V_679 . V_436 = V_681 ;
V_679 . V_668 = ( V_680 . V_669 | V_680 . V_670 ) ;
if ( ( V_679 . V_105 == V_575 || V_679 . V_105 == V_573 ) && V_679 . V_449 == V_547 )
V_679 . V_449 = V_10 -> V_561 . V_449 ;
V_683 = V_198 + ( V_678 . V_105 < V_575 && V_679 . V_105 >= V_575 ? 0 : V_107 ) ;
if ( V_679 . V_436 == V_569 && F_302 ( V_10 ) && V_679 . V_105 == V_575 && V_678 . V_105 < V_575 &&
F_69 ( V_690 , & V_10 -> V_69 ) ) {
F_21 ( & V_10 -> V_24 -> V_25 ) ;
F_45 ( V_10 , L_144 ) ;
F_303 ( V_29 -> V_27 ) ;
F_304 ( V_10 ) ;
F_106 ( V_690 , & V_10 -> V_69 ) ;
F_71 ( V_29 -> V_27 , F_305 ( V_105 , V_691 , V_692 , 0 ) , V_107 ) ;
return - V_108 ;
}
V_95 = F_286 ( V_10 , V_679 , V_683 , NULL ) ;
V_679 = F_298 ( V_10 ) ;
F_21 ( & V_10 -> V_24 -> V_25 ) ;
if ( V_95 < V_199 ) {
F_71 ( V_29 -> V_27 , F_72 ( V_105 , V_151 ) , V_107 ) ;
return - V_108 ;
}
if ( V_678 . V_105 > V_103 ) {
if ( V_679 . V_105 > V_575 && V_680 . V_105 <= V_575 &&
V_680 . V_449 != V_547 ) {
F_104 ( V_29 ) ;
F_105 ( V_29 ) ;
}
}
F_106 ( V_223 , & V_10 -> V_69 ) ;
F_280 ( V_10 ) ;
return 0 ;
}
static int F_306 ( struct V_26 * V_27 , struct V_171 * V_172 )
{
struct V_28 * V_29 ;
struct V_9 * V_10 ;
struct V_693 * V_322 = V_172 -> V_96 ;
V_29 = F_193 ( V_27 , V_172 -> V_30 ) ;
if ( ! V_29 )
return - V_108 ;
V_10 = V_29 -> V_10 ;
F_225 ( V_10 -> V_320 ,
V_10 -> V_382 . V_105 == V_694 ||
V_10 -> V_382 . V_105 == V_685 ||
V_10 -> V_382 . V_105 < V_575 ||
V_10 -> V_382 . V_449 < V_547 ) ;
if ( F_237 ( V_10 , V_547 ) ) {
F_285 ( V_10 , V_538 , F_194 ( V_322 -> V_514 ) ) ;
F_285 ( V_10 , V_515 , 0UL ) ;
F_289 ( V_10 , L_145 ) ;
F_307 ( V_10 , V_435 ) ;
F_131 ( V_10 ) ;
} else
F_45 ( V_10 , L_146 ) ;
return 0 ;
}
static int
F_308 ( struct V_28 * V_29 , unsigned int V_64 ,
unsigned long * V_322 , struct V_695 * V_696 )
{
unsigned int V_306 = V_600 -
F_95 ( V_29 -> V_27 ) ;
unsigned int V_697 = F_77 ( T_6 , V_306 / sizeof( * V_322 ) ,
V_696 -> V_698 - V_696 -> V_699 ) ;
unsigned int V_700 = V_697 * sizeof( * V_322 ) ;
int V_77 ;
if ( V_700 != V_64 ) {
F_45 ( V_29 , L_147 , V_62 , V_700 , V_64 ) ;
return - V_108 ;
}
if ( V_700 == 0 )
return 0 ;
V_77 = F_73 ( V_29 -> V_27 , V_322 , V_700 ) ;
if ( V_77 )
return V_77 ;
F_309 ( V_29 -> V_10 , V_696 -> V_699 , V_697 , V_322 ) ;
V_696 -> V_699 += V_697 ;
V_696 -> V_701 = V_696 -> V_699 * V_702 ;
if ( V_696 -> V_701 > V_696 -> V_703 )
V_696 -> V_701 = V_696 -> V_703 ;
return 1 ;
}
static enum V_704 F_310 ( struct V_705 * V_322 )
{
return (enum V_704 ) ( V_322 -> V_706 & 0x0f ) ;
}
static int F_311 ( struct V_705 * V_322 )
{
return ( V_322 -> V_706 & 0x80 ) != 0 ;
}
static int F_312 ( struct V_705 * V_322 )
{
return ( V_322 -> V_706 >> 4 ) & 0x7 ;
}
static int
F_313 ( struct V_28 * V_29 ,
struct V_705 * V_322 ,
struct V_695 * V_696 ,
unsigned int V_5 )
{
struct V_707 V_708 ;
T_2 V_709 ;
T_2 V_710 ;
T_2 V_4 ;
unsigned long V_203 = V_696 -> V_701 ;
unsigned long V_711 ;
int V_712 = F_311 ( V_322 ) ;
int V_713 ;
int V_537 ;
F_314 ( & V_708 , V_322 -> V_714 , V_5 , F_312 ( V_322 ) ) ;
V_537 = F_315 ( & V_708 , & V_709 , 64 ) ;
if ( V_537 < 0 )
return - V_108 ;
for ( V_713 = V_537 ; V_713 > 0 ; V_203 += V_710 , V_712 = ! V_712 ) {
V_537 = F_316 ( & V_710 , V_709 ) ;
if ( V_537 <= 0 )
return - V_108 ;
if ( V_712 ) {
V_711 = V_203 + V_710 - 1 ;
if ( V_711 >= V_696 -> V_703 ) {
F_45 ( V_29 , L_148 , V_711 ) ;
return - V_108 ;
}
F_317 ( V_29 -> V_10 , V_203 , V_711 ) ;
}
if ( V_713 < V_537 ) {
F_45 ( V_29 , L_149 ,
V_713 , V_537 , V_709 ,
( unsigned int ) ( V_708 . V_715 . V_392 - V_322 -> V_714 ) ,
( unsigned int ) V_708 . V_716 ) ;
return - V_108 ;
}
if ( F_182 ( V_537 < 64 ) )
V_709 >>= V_537 ;
else
V_709 = 0 ;
V_713 -= V_537 ;
V_537 = F_315 ( & V_708 , & V_4 , 64 - V_713 ) ;
if ( V_537 < 0 )
return - V_108 ;
V_709 |= V_4 << V_713 ;
V_713 += V_537 ;
}
V_696 -> V_701 = V_203 ;
F_318 ( V_696 ) ;
return ( V_203 != V_696 -> V_703 ) ;
}
static int
F_319 ( struct V_28 * V_29 ,
struct V_705 * V_322 ,
struct V_695 * V_696 ,
unsigned int V_5 )
{
if ( F_310 ( V_322 ) == V_717 )
return F_313 ( V_29 , V_322 , V_696 , V_5 - sizeof( * V_322 ) ) ;
F_45 ( V_29 , L_150 , V_322 -> V_706 ) ;
F_71 ( V_29 -> V_27 , F_72 ( V_105 , V_691 ) , V_107 ) ;
return - V_108 ;
}
void F_320 ( struct V_9 * V_10 ,
const char * V_718 , struct V_695 * V_696 )
{
unsigned int V_170 = F_95 ( F_252 ( V_10 ) -> V_27 ) ;
unsigned int V_306 = V_600 - V_170 ;
unsigned int V_719 =
V_170 * ( F_321 ( V_696 -> V_698 , V_306 ) + 1 ) +
V_696 -> V_698 * sizeof( unsigned long ) ;
unsigned int V_720 = V_696 -> V_721 [ 0 ] + V_696 -> V_721 [ 1 ] ;
unsigned int V_325 ;
if ( V_720 == 0 )
return;
if ( V_720 >= V_719 )
return;
V_325 = ( V_720 > V_45 / 1000 ) ? ( V_720 / ( V_719 / 1000 ) )
: ( 1000 * V_720 / V_719 ) ;
if ( V_325 > 1000 )
V_325 = 1000 ;
V_325 = 1000 - V_325 ;
F_68 ( V_10 , L_151
L_152 ,
V_718 ,
V_696 -> V_721 [ 1 ] , V_696 -> V_722 [ 1 ] ,
V_696 -> V_721 [ 0 ] , V_696 -> V_722 [ 0 ] ,
V_720 , V_325 / 10 , V_325 % 10 ) ;
}
static int F_322 ( struct V_26 * V_27 , struct V_171 * V_172 )
{
struct V_28 * V_29 ;
struct V_9 * V_10 ;
struct V_695 V_696 ;
int V_77 ;
V_29 = F_193 ( V_27 , V_172 -> V_30 ) ;
if ( ! V_29 )
return - V_108 ;
V_10 = V_29 -> V_10 ;
F_323 ( V_10 , L_153 , V_572 ) ;
V_696 = (struct V_695 ) {
. V_703 = F_242 ( V_10 ) ,
. V_698 = F_324 ( V_10 ) ,
} ;
for(; ; ) {
if ( V_172 -> V_169 == V_723 )
V_77 = F_308 ( V_29 , V_172 -> V_64 , V_172 -> V_96 , & V_696 ) ;
else if ( V_172 -> V_169 == V_724 ) {
struct V_705 * V_322 = V_172 -> V_96 ;
if ( V_172 -> V_64 > V_600 - F_95 ( V_27 ) ) {
F_45 ( V_10 , L_154 ) ;
V_77 = - V_108 ;
goto V_104;
}
if ( V_172 -> V_64 <= sizeof( * V_322 ) ) {
F_45 ( V_10 , L_155 , V_172 -> V_64 ) ;
V_77 = - V_108 ;
goto V_104;
}
V_77 = F_73 ( V_29 -> V_27 , V_322 , V_172 -> V_64 ) ;
if ( V_77 )
goto V_104;
V_77 = F_319 ( V_29 , V_322 , & V_696 , V_172 -> V_64 ) ;
} else {
F_35 ( V_10 , L_156 , V_172 -> V_169 ) ;
V_77 = - V_108 ;
goto V_104;
}
V_696 . V_722 [ V_172 -> V_169 == V_723 ] ++ ;
V_696 . V_721 [ V_172 -> V_169 == V_723 ] += F_95 ( V_27 ) + V_172 -> V_64 ;
if ( V_77 <= 0 ) {
if ( V_77 < 0 )
goto V_104;
break;
}
V_77 = F_127 ( V_29 -> V_27 , V_172 ) ;
if ( V_77 )
goto V_104;
}
F_320 ( V_10 , L_157 , & V_696 ) ;
if ( V_10 -> V_382 . V_105 == V_574 ) {
enum V_196 V_95 ;
V_77 = F_325 ( V_10 ) ;
if ( V_77 )
goto V_104;
V_95 = F_326 ( V_10 , F_72 ( V_105 , V_694 ) , V_198 ) ;
F_53 ( V_10 , V_95 == V_199 ) ;
} else if ( V_10 -> V_382 . V_105 != V_573 ) {
F_68 ( V_10 , L_158 ,
F_256 ( V_10 -> V_382 . V_105 ) ) ;
}
V_77 = 0 ;
V_104:
F_327 ( V_10 ) ;
if ( ! V_77 && V_10 -> V_382 . V_105 == V_573 )
F_307 ( V_10 , V_383 ) ;
return V_77 ;
}
static int F_328 ( struct V_26 * V_27 , struct V_171 * V_172 )
{
F_35 ( V_27 , L_159 ,
V_172 -> V_169 , V_172 -> V_64 ) ;
return F_267 ( V_27 , V_172 ) ;
}
static int F_329 ( struct V_26 * V_27 , struct V_171 * V_172 )
{
F_330 ( V_27 -> V_96 . V_83 ) ;
return 0 ;
}
static int F_331 ( struct V_26 * V_27 , struct V_171 * V_172 )
{
struct V_28 * V_29 ;
struct V_9 * V_10 ;
struct V_725 * V_322 = V_172 -> V_96 ;
V_29 = F_193 ( V_27 , V_172 -> V_30 ) ;
if ( ! V_29 )
return - V_108 ;
V_10 = V_29 -> V_10 ;
switch ( V_10 -> V_382 . V_105 ) {
case V_694 :
case V_574 :
case V_685 :
break;
default:
F_45 ( V_10 , L_160 ,
F_256 ( V_10 -> V_382 . V_105 ) ) ;
}
F_226 ( V_10 , F_194 ( V_322 -> V_52 ) , F_125 ( V_322 -> V_474 ) ) ;
return 0 ;
}
static int F_332 ( struct V_26 * V_27 , struct V_171 * V_172 )
{
struct V_28 * V_29 ;
struct V_725 * V_322 = V_172 -> V_96 ;
struct V_9 * V_10 ;
T_3 V_52 ;
int V_64 , V_77 = 0 ;
V_29 = F_193 ( V_27 , V_172 -> V_30 ) ;
if ( ! V_29 )
return - V_108 ;
V_10 = V_29 -> V_10 ;
V_52 = F_194 ( V_322 -> V_52 ) ;
V_64 = F_125 ( V_322 -> V_474 ) ;
F_188 ( V_10 ) ;
if ( F_140 ( V_10 ) ) {
struct V_18 * V_19 ;
const int V_302 = V_412 ;
V_19 = F_42 ( V_29 , V_361 , V_52 ,
V_64 , 0 , V_213 ) ;
if ( ! V_19 ) {
F_131 ( V_10 ) ;
return - V_254 ;
}
V_19 -> V_20 . V_80 = F_180 ;
V_19 -> V_65 = V_66 ;
V_19 -> V_69 |= V_308 ;
F_20 ( & V_10 -> V_24 -> V_25 ) ;
F_157 ( & V_19 -> V_20 . V_21 , & V_10 -> V_362 ) ;
F_21 ( & V_10 -> V_24 -> V_25 ) ;
F_38 ( V_172 -> V_64 >> 9 , & V_10 -> V_363 ) ;
V_77 = F_155 ( V_10 , V_19 , V_302 , 0 , V_365 ) ;
if ( V_77 ) {
F_20 ( & V_10 -> V_24 -> V_25 ) ;
F_147 ( & V_19 -> V_20 . V_21 ) ;
F_21 ( & V_10 -> V_24 -> V_25 ) ;
F_60 ( V_10 , V_19 ) ;
F_131 ( V_10 ) ;
V_77 = 0 ;
goto V_63;
}
F_189 ( V_10 ) ;
} else {
V_63:
F_333 ( V_10 , V_52 ) ;
F_239 ( V_29 , V_360 , V_52 , V_64 , V_361 ) ;
}
F_38 ( V_64 >> 9 , & V_10 -> V_374 ) ;
return V_77 ;
}
static void F_334 ( struct V_26 * V_27 )
{
struct V_171 V_172 ;
T_6 V_726 ;
int V_77 ;
while ( F_114 ( & V_27 -> V_210 ) == V_727 ) {
struct V_728 const * V_169 ;
F_335 ( & V_27 -> V_210 ) ;
F_243 ( V_27 , F_127 ) ;
if ( F_127 ( V_27 , & V_172 ) )
goto V_729;
V_169 = & V_730 [ V_172 . V_169 ] ;
if ( F_195 ( V_172 . V_169 >= F_336 ( V_730 ) || ! V_169 -> V_731 ) ) {
F_45 ( V_27 , L_161 ,
F_269 ( V_172 . V_169 ) , V_172 . V_169 ) ;
goto V_729;
}
V_726 = V_169 -> V_732 ;
if ( V_172 . V_169 == V_733 && V_27 -> V_550 & V_551 )
V_726 += sizeof( struct V_627 ) ;
if ( V_172 . V_64 > V_726 && ! V_169 -> V_734 ) {
F_45 ( V_27 , L_162 ,
F_269 ( V_172 . V_169 ) , V_172 . V_64 ) ;
goto V_729;
}
if ( V_172 . V_64 < V_726 ) {
F_45 ( V_27 , L_163 ,
F_269 ( V_172 . V_169 ) , ( int ) V_726 , V_172 . V_64 ) ;
goto V_729;
}
if ( V_726 ) {
F_243 ( V_27 , F_74 ) ;
V_77 = F_74 ( V_27 , V_172 . V_96 , V_726 ) ;
if ( V_77 )
goto V_729;
V_172 . V_64 -= V_726 ;
}
F_243 ( V_27 , V_169 -> V_731 ) ;
V_77 = V_169 -> V_731 ( V_27 , & V_172 ) ;
if ( V_77 ) {
F_45 ( V_27 , L_164 ,
F_269 ( V_172 . V_169 ) , V_77 , V_172 . V_64 ) ;
goto V_729;
}
}
return;
V_729:
F_71 ( V_27 , F_72 ( V_105 , V_691 ) , V_107 ) ;
}
static void F_337 ( struct V_26 * V_27 )
{
struct V_28 * V_29 ;
enum V_554 V_735 ;
int V_30 ;
if ( V_27 -> V_102 == V_736 )
return;
F_71 ( V_27 , F_72 ( V_105 , V_737 ) , V_107 ) ;
F_338 ( & V_27 -> V_224 ) ;
if ( V_27 -> V_225 ) {
F_339 ( V_27 -> V_225 ) ;
V_27 -> V_225 = NULL ;
}
F_340 ( V_27 ) ;
F_24 () ;
F_25 (&connection->peer_devices, peer_device, vnr) {
struct V_9 * V_10 = V_29 -> V_10 ;
F_27 ( & V_10 -> V_32 ) ;
F_28 () ;
F_341 ( V_29 ) ;
F_29 ( & V_10 -> V_32 , V_33 ) ;
F_24 () ;
}
F_28 () ;
if ( ! F_62 ( & V_27 -> V_282 -> V_21 ) )
F_45 ( V_27 , L_165 ) ;
F_101 ( & V_27 -> V_282 -> V_271 , 0 ) ;
V_27 -> V_738 . V_739 = false ;
F_68 ( V_27 , L_166 ) ;
if ( F_342 ( V_27 ) == V_505 && F_343 ( V_27 ) >= V_740 )
F_344 ( V_27 ) ;
F_20 ( & V_27 -> V_24 -> V_25 ) ;
V_735 = V_27 -> V_102 ;
if ( V_735 >= V_741 )
F_223 ( V_27 , F_72 ( V_105 , V_741 ) , V_198 ) ;
F_21 ( & V_27 -> V_24 -> V_25 ) ;
if ( V_735 == V_151 )
F_71 ( V_27 , F_72 ( V_105 , V_736 ) , V_198 | V_107 ) ;
}
static int F_341 ( struct V_28 * V_29 )
{
struct V_9 * V_10 = V_29 -> V_10 ;
unsigned int V_6 ;
F_20 ( & V_10 -> V_24 -> V_25 ) ;
F_61 ( V_10 , & V_10 -> V_311 ) ;
F_61 ( V_10 , & V_10 -> V_362 ) ;
F_61 ( V_10 , & V_10 -> V_503 ) ;
F_21 ( & V_10 -> V_24 -> V_25 ) ;
F_345 ( V_10 ) ;
V_10 -> V_501 = 0 ;
V_10 -> V_467 = 0 ;
F_101 ( & V_10 -> V_742 , 0 ) ;
F_41 ( & V_10 -> V_320 ) ;
F_346 ( & V_10 -> V_743 ) ;
F_347 ( ( unsigned long ) V_10 ) ;
F_348 ( & V_29 -> V_27 -> V_744 ) ;
F_59 ( V_10 ) ;
F_348 ( & V_29 -> V_27 -> V_744 ) ;
F_345 ( V_10 ) ;
F_52 ( V_10 -> V_516 ) ;
V_10 -> V_516 = NULL ;
if ( ! F_302 ( V_10 ) )
F_303 ( V_29 -> V_27 ) ;
F_280 ( V_10 ) ;
if ( F_140 ( V_10 ) ) {
F_257 ( V_10 , & V_745 ,
L_167 , V_746 ) ;
F_131 ( V_10 ) ;
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
F_53 ( V_10 , F_62 ( & V_10 -> V_503 ) ) ;
F_53 ( V_10 , F_62 ( & V_10 -> V_311 ) ) ;
F_53 ( V_10 , F_62 ( & V_10 -> V_362 ) ) ;
F_53 ( V_10 , F_62 ( & V_10 -> V_78 ) ) ;
return 0 ;
}
static int F_349 ( struct V_26 * V_27 )
{
struct V_167 * V_84 ;
struct V_747 * V_322 ;
V_84 = & V_27 -> V_96 ;
V_322 = F_92 ( V_27 , V_84 ) ;
if ( ! V_322 )
return - V_108 ;
memset ( V_322 , 0 , sizeof( * V_322 ) ) ;
V_322 -> V_748 = F_123 ( V_749 ) ;
V_322 -> V_750 = F_123 ( V_552 ) ;
V_322 -> V_751 = F_123 ( V_752 ) ;
return F_93 ( V_27 , V_84 , V_753 , sizeof( * V_322 ) , NULL , 0 ) ;
}
static int F_116 ( struct V_26 * V_27 )
{
struct V_747 * V_322 ;
const int F_55 = sizeof( struct V_747 ) ;
struct V_171 V_172 ;
int V_77 ;
V_77 = F_349 ( V_27 ) ;
if ( V_77 )
return 0 ;
V_77 = F_127 ( V_27 , & V_172 ) ;
if ( V_77 )
return 0 ;
if ( V_172 . V_169 != V_753 ) {
F_45 ( V_27 , L_171 ,
F_269 ( V_172 . V_169 ) , V_172 . V_169 ) ;
return - 1 ;
}
if ( V_172 . V_64 != F_55 ) {
F_45 ( V_27 , L_172 ,
F_55 , V_172 . V_64 ) ;
return - 1 ;
}
V_322 = V_172 . V_96 ;
V_77 = F_74 ( V_27 , V_322 , F_55 ) ;
if ( V_77 )
return 0 ;
V_322 -> V_748 = F_125 ( V_322 -> V_748 ) ;
V_322 -> V_750 = F_125 ( V_322 -> V_750 ) ;
if ( V_322 -> V_750 == 0 )
V_322 -> V_750 = V_322 -> V_748 ;
if ( V_552 < V_322 -> V_748 ||
V_749 > V_322 -> V_750 )
goto V_754;
V_27 -> V_186 = F_77 ( int , V_552 , V_322 -> V_750 ) ;
V_27 -> V_550 = V_752 & F_125 ( V_322 -> V_751 ) ;
F_68 ( V_27 , L_173
L_174 , V_27 -> V_186 ) ;
F_68 ( V_27 , L_175 ,
V_27 -> V_550 ,
V_27 -> V_550 & V_755 ? L_176 : L_104 ,
V_27 -> V_550 & V_756 ? L_177 : L_104 ,
V_27 -> V_550 & V_551 ? L_178 :
V_27 -> V_550 ? L_104 : L_179 ) ;
return 1 ;
V_754:
F_45 ( V_27 , L_180
L_181 ,
V_749 , V_552 ,
V_322 -> V_748 , V_322 -> V_750 ) ;
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
char V_757 [ V_758 ] ;
char * V_759 = NULL ;
char * V_760 = NULL ;
char * V_761 = NULL ;
unsigned int V_762 ;
char V_763 [ V_587 ] ;
unsigned int V_764 ;
F_350 ( V_765 , V_27 -> V_219 ) ;
struct V_171 V_172 ;
struct V_35 * V_36 ;
int V_77 , V_95 ;
F_24 () ;
V_36 = F_32 ( V_27 -> V_35 ) ;
V_762 = strlen ( V_36 -> V_766 ) ;
memcpy ( V_763 , V_36 -> V_766 , V_762 ) ;
F_28 () ;
V_765 -> V_599 = V_27 -> V_219 ;
V_765 -> V_69 = 0 ;
V_95 = F_351 ( V_27 -> V_219 , ( V_767 * ) V_763 , V_762 ) ;
if ( V_95 ) {
F_45 ( V_27 , L_184 , V_95 ) ;
V_95 = - 1 ;
goto V_63;
}
F_352 ( V_757 , V_758 ) ;
V_84 = & V_27 -> V_96 ;
if ( ! F_92 ( V_27 , V_84 ) ) {
V_95 = 0 ;
goto V_63;
}
V_95 = ! F_93 ( V_27 , V_84 , V_768 , 0 ,
V_757 , V_758 ) ;
if ( ! V_95 )
goto V_63;
V_77 = F_127 ( V_27 , & V_172 ) ;
if ( V_77 ) {
V_95 = 0 ;
goto V_63;
}
if ( V_172 . V_169 != V_768 ) {
F_45 ( V_27 , L_185 ,
F_269 ( V_172 . V_169 ) , V_172 . V_169 ) ;
V_95 = 0 ;
goto V_63;
}
if ( V_172 . V_64 > V_758 * 2 ) {
F_45 ( V_27 , L_186 ) ;
V_95 = - 1 ;
goto V_63;
}
if ( V_172 . V_64 < V_758 ) {
F_45 ( V_27 , L_187 ) ;
V_95 = - 1 ;
goto V_63;
}
V_761 = F_135 ( V_172 . V_64 , V_213 ) ;
if ( V_761 == NULL ) {
F_45 ( V_27 , L_188 ) ;
V_95 = - 1 ;
goto V_63;
}
V_77 = F_74 ( V_27 , V_761 , V_172 . V_64 ) ;
if ( V_77 ) {
V_95 = 0 ;
goto V_63;
}
if ( ! memcmp ( V_757 , V_761 , V_758 ) ) {
F_45 ( V_27 , L_189 ) ;
V_95 = - 1 ;
goto V_63;
}
V_764 = F_353 ( V_27 -> V_219 ) ;
V_759 = F_135 ( V_764 , V_213 ) ;
if ( V_759 == NULL ) {
F_45 ( V_27 , L_190 ) ;
V_95 = - 1 ;
goto V_63;
}
V_95 = F_354 ( V_765 , V_761 , V_172 . V_64 , V_759 ) ;
if ( V_95 ) {
F_45 ( V_27 , L_191 , V_95 ) ;
V_95 = - 1 ;
goto V_63;
}
if ( ! F_92 ( V_27 , V_84 ) ) {
V_95 = 0 ;
goto V_63;
}
V_95 = ! F_93 ( V_27 , V_84 , V_769 , 0 ,
V_759 , V_764 ) ;
if ( ! V_95 )
goto V_63;
V_77 = F_127 ( V_27 , & V_172 ) ;
if ( V_77 ) {
V_95 = 0 ;
goto V_63;
}
if ( V_172 . V_169 != V_769 ) {
F_45 ( V_27 , L_192 ,
F_269 ( V_172 . V_169 ) , V_172 . V_169 ) ;
V_95 = 0 ;
goto V_63;
}
if ( V_172 . V_64 != V_764 ) {
F_45 ( V_27 , L_193 ) ;
V_95 = 0 ;
goto V_63;
}
V_77 = F_74 ( V_27 , V_759 , V_764 ) ;
if ( V_77 ) {
V_95 = 0 ;
goto V_63;
}
V_760 = F_135 ( V_764 , V_213 ) ;
if ( V_760 == NULL ) {
F_45 ( V_27 , L_194 ) ;
V_95 = - 1 ;
goto V_63;
}
V_95 = F_354 ( V_765 , V_757 , V_758 ,
V_760 ) ;
if ( V_95 ) {
F_45 ( V_27 , L_191 , V_95 ) ;
V_95 = - 1 ;
goto V_63;
}
V_95 = ! memcmp ( V_759 , V_760 , V_764 ) ;
if ( V_95 )
F_68 ( V_27 , L_195 ,
V_764 ) ;
else
V_95 = - 1 ;
V_63:
F_52 ( V_761 ) ;
F_52 ( V_759 ) ;
F_52 ( V_760 ) ;
F_355 ( V_765 ) ;
return V_95 ;
}
int F_356 ( struct V_770 * V_771 )
{
struct V_26 * V_27 = V_771 -> V_27 ;
int V_194 ;
F_68 ( V_27 , L_196 ) ;
do {
V_194 = F_108 ( V_27 ) ;
if ( V_194 == 0 ) {
F_337 ( V_27 ) ;
F_99 ( V_44 ) ;
}
if ( V_194 == - 1 ) {
F_35 ( V_27 , L_197 ) ;
F_71 ( V_27 , F_72 ( V_105 , V_151 ) , V_107 ) ;
}
} while ( V_194 == 0 );
if ( V_194 > 0 )
F_334 ( V_27 ) ;
F_337 ( V_27 ) ;
F_68 ( V_27 , L_198 ) ;
return 0 ;
}
static int F_357 ( struct V_26 * V_27 , struct V_171 * V_172 )
{
struct V_772 * V_322 = V_172 -> V_96 ;
int V_773 = F_125 ( V_322 -> V_773 ) ;
if ( V_773 >= V_199 ) {
F_111 ( V_774 , & V_27 -> V_69 ) ;
} else {
F_111 ( V_775 , & V_27 -> V_69 ) ;
F_45 ( V_27 , L_199 ,
F_358 ( V_773 ) , V_773 ) ;
}
F_41 ( & V_27 -> V_101 ) ;
return 0 ;
}
static int F_359 ( struct V_26 * V_27 , struct V_171 * V_172 )
{
struct V_28 * V_29 ;
struct V_9 * V_10 ;
struct V_772 * V_322 = V_172 -> V_96 ;
int V_773 = F_125 ( V_322 -> V_773 ) ;
V_29 = F_193 ( V_27 , V_172 -> V_30 ) ;
if ( ! V_29 )
return - V_108 ;
V_10 = V_29 -> V_10 ;
if ( F_69 ( V_776 , & V_27 -> V_69 ) ) {
F_53 ( V_10 , V_27 -> V_186 < 100 ) ;
return F_357 ( V_27 , V_172 ) ;
}
if ( V_773 >= V_199 ) {
F_111 ( V_777 , & V_10 -> V_69 ) ;
} else {
F_111 ( V_778 , & V_10 -> V_69 ) ;
F_45 ( V_10 , L_199 ,
F_358 ( V_773 ) , V_773 ) ;
}
F_41 ( & V_10 -> V_779 ) ;
return 0 ;
}
static int F_360 ( struct V_26 * V_27 , struct V_171 * V_172 )
{
return F_361 ( V_27 ) ;
}
static int F_362 ( struct V_26 * V_27 , struct V_171 * V_172 )
{
V_27 -> V_202 . V_83 -> V_111 -> V_138 = V_27 -> V_35 -> V_217 * V_44 ;
if ( ! F_363 ( V_780 , & V_27 -> V_69 ) )
F_41 ( & V_27 -> V_101 ) ;
return 0 ;
}
static int F_364 ( struct V_26 * V_27 , struct V_171 * V_172 )
{
struct V_28 * V_29 ;
struct V_9 * V_10 ;
struct V_781 * V_322 = V_172 -> V_96 ;
T_3 V_52 = F_194 ( V_322 -> V_52 ) ;
int V_474 = F_125 ( V_322 -> V_474 ) ;
V_29 = F_193 ( V_27 , V_172 -> V_30 ) ;
if ( ! V_29 )
return - V_108 ;
V_10 = V_29 -> V_10 ;
F_53 ( V_10 , V_29 -> V_27 -> V_186 >= 89 ) ;
F_209 ( V_29 , F_125 ( V_322 -> V_424 ) ) ;
if ( F_140 ( V_10 ) ) {
F_333 ( V_10 , V_52 ) ;
F_183 ( V_10 , V_52 , V_474 ) ;
V_10 -> V_782 += ( V_474 >> V_783 ) ;
F_131 ( V_10 ) ;
}
F_188 ( V_10 ) ;
F_38 ( V_474 >> 9 , & V_10 -> V_374 ) ;
return 0 ;
}
static int
F_365 ( struct V_9 * V_10 , T_2 V_51 , T_3 V_52 ,
struct V_366 * V_367 , const char * V_369 ,
enum V_784 V_117 , bool V_368 )
{
struct V_346 * V_347 ;
struct V_414 V_415 ;
F_20 ( & V_10 -> V_24 -> V_25 ) ;
V_347 = F_190 ( V_10 , V_367 , V_51 , V_52 , V_368 , V_369 ) ;
if ( F_195 ( ! V_347 ) ) {
F_21 ( & V_10 -> V_24 -> V_25 ) ;
return - V_108 ;
}
F_202 ( V_347 , V_117 , & V_415 ) ;
F_21 ( & V_10 -> V_24 -> V_25 ) ;
if ( V_415 . V_244 )
F_217 ( V_10 , & V_415 ) ;
return 0 ;
}
static int F_366 ( struct V_26 * V_27 , struct V_171 * V_172 )
{
struct V_28 * V_29 ;
struct V_9 * V_10 ;
struct V_781 * V_322 = V_172 -> V_96 ;
T_3 V_52 = F_194 ( V_322 -> V_52 ) ;
int V_474 = F_125 ( V_322 -> V_474 ) ;
enum V_784 V_117 ;
V_29 = F_193 ( V_27 , V_172 -> V_30 ) ;
if ( ! V_29 )
return - V_108 ;
V_10 = V_29 -> V_10 ;
F_209 ( V_29 , F_125 ( V_322 -> V_424 ) ) ;
if ( V_322 -> V_68 == V_361 ) {
F_183 ( V_10 , V_52 , V_474 ) ;
F_188 ( V_10 ) ;
return 0 ;
}
switch ( V_172 -> V_169 ) {
case V_359 :
V_117 = V_785 ;
break;
case V_386 :
V_117 = V_786 ;
break;
case V_433 :
V_117 = V_787 ;
break;
case V_390 :
V_117 = V_378 ;
break;
case V_391 :
V_117 = V_788 ;
break;
default:
F_240 () ;
}
return F_365 ( V_10 , V_322 -> V_68 , V_52 ,
& V_10 -> V_318 , V_62 ,
V_117 , false ) ;
}
static int F_367 ( struct V_26 * V_27 , struct V_171 * V_172 )
{
struct V_28 * V_29 ;
struct V_9 * V_10 ;
struct V_781 * V_322 = V_172 -> V_96 ;
T_3 V_52 = F_194 ( V_322 -> V_52 ) ;
int V_64 = F_125 ( V_322 -> V_474 ) ;
int V_77 ;
V_29 = F_193 ( V_27 , V_172 -> V_30 ) ;
if ( ! V_29 )
return - V_108 ;
V_10 = V_29 -> V_10 ;
F_209 ( V_29 , F_125 ( V_322 -> V_424 ) ) ;
if ( V_322 -> V_68 == V_361 ) {
F_188 ( V_10 ) ;
F_185 ( V_10 , V_52 , V_64 ) ;
return 0 ;
}
V_77 = F_365 ( V_10 , V_322 -> V_68 , V_52 ,
& V_10 -> V_318 , V_62 ,
V_416 , true ) ;
if ( V_77 ) {
F_226 ( V_10 , V_52 , V_64 ) ;
}
return 0 ;
}
static int F_368 ( struct V_26 * V_27 , struct V_171 * V_172 )
{
struct V_28 * V_29 ;
struct V_9 * V_10 ;
struct V_781 * V_322 = V_172 -> V_96 ;
T_3 V_52 = F_194 ( V_322 -> V_52 ) ;
V_29 = F_193 ( V_27 , V_172 -> V_30 ) ;
if ( ! V_29 )
return - V_108 ;
V_10 = V_29 -> V_10 ;
F_209 ( V_29 , F_125 ( V_322 -> V_424 ) ) ;
F_45 ( V_10 , L_200 ,
( unsigned long long ) V_52 , F_125 ( V_322 -> V_474 ) ) ;
return F_365 ( V_10 , V_322 -> V_68 , V_52 ,
& V_10 -> V_371 , V_62 ,
V_416 , false ) ;
}
static int F_369 ( struct V_26 * V_27 , struct V_171 * V_172 )
{
struct V_28 * V_29 ;
struct V_9 * V_10 ;
T_3 V_52 ;
int V_64 ;
struct V_781 * V_322 = V_172 -> V_96 ;
V_29 = F_193 ( V_27 , V_172 -> V_30 ) ;
if ( ! V_29 )
return - V_108 ;
V_10 = V_29 -> V_10 ;
V_52 = F_194 ( V_322 -> V_52 ) ;
V_64 = F_125 ( V_322 -> V_474 ) ;
F_209 ( V_29 , F_125 ( V_322 -> V_424 ) ) ;
F_188 ( V_10 ) ;
if ( F_237 ( V_10 , V_688 ) ) {
F_333 ( V_10 , V_52 ) ;
switch ( V_172 -> V_169 ) {
case V_482 :
F_185 ( V_10 , V_52 , V_64 ) ;
case V_789 :
break;
default:
F_240 () ;
}
F_131 ( V_10 ) ;
}
return 0 ;
}
static int F_370 ( struct V_26 * V_27 , struct V_171 * V_172 )
{
struct V_790 * V_322 = V_172 -> V_96 ;
struct V_28 * V_29 ;
int V_30 ;
F_371 ( V_27 , V_322 -> V_323 , F_125 ( V_322 -> V_791 ) ) ;
F_24 () ;
F_25 (&connection->peer_devices, peer_device, vnr) {
struct V_9 * V_10 = V_29 -> V_10 ;
if ( V_10 -> V_382 . V_105 == V_684 &&
F_26 ( & V_10 -> V_191 ) == 0 &&
! F_363 ( V_792 , & V_10 -> V_69 ) ) {
V_10 -> V_793 . V_794 = V_66 + V_44 ;
F_372 ( & V_10 -> V_793 ) ;
}
}
F_28 () ;
return 0 ;
}
static int F_373 ( struct V_26 * V_27 , struct V_171 * V_172 )
{
struct V_28 * V_29 ;
struct V_9 * V_10 ;
struct V_781 * V_322 = V_172 -> V_96 ;
struct V_795 * V_796 ;
T_3 V_52 ;
int V_64 ;
V_29 = F_193 ( V_27 , V_172 -> V_30 ) ;
if ( ! V_29 )
return - V_108 ;
V_10 = V_29 -> V_10 ;
V_52 = F_194 ( V_322 -> V_52 ) ;
V_64 = F_125 ( V_322 -> V_474 ) ;
F_209 ( V_29 , F_125 ( V_322 -> V_424 ) ) ;
if ( F_194 ( V_322 -> V_68 ) == V_797 )
F_374 ( V_10 , V_52 , V_64 ) ;
else
F_300 ( V_10 ) ;
if ( ! F_140 ( V_10 ) )
return 0 ;
F_333 ( V_10 , V_52 ) ;
F_188 ( V_10 ) ;
-- V_10 -> V_466 ;
if ( ( V_10 -> V_466 & 0x200 ) == 0x200 )
F_375 ( V_10 , V_10 -> V_466 ) ;
if ( V_10 -> V_466 == 0 ) {
V_796 = F_135 ( sizeof( * V_796 ) , V_213 ) ;
if ( V_796 ) {
V_796 -> V_20 . V_80 = V_798 ;
V_796 -> V_10 = V_10 ;
F_376 ( & V_29 -> V_27 -> V_744 , & V_796 -> V_20 ) ;
} else {
F_45 ( V_10 , L_201 ) ;
F_300 ( V_10 ) ;
F_299 ( V_10 ) ;
}
}
F_131 ( V_10 ) ;
return 0 ;
}
static int F_377 ( struct V_26 * V_27 , struct V_171 * V_172 )
{
return 0 ;
}
static void F_378 ( struct V_26 * V_27 , bool V_799 )
{
long V_23 ;
struct V_35 * V_36 ;
F_24 () ;
V_36 = F_32 ( V_27 -> V_35 ) ;
V_23 = V_799 ? V_36 -> V_100 : V_36 -> V_217 ;
F_28 () ;
V_23 *= V_44 ;
if ( V_799 )
V_23 /= 10 ;
V_27 -> V_202 . V_83 -> V_111 -> V_138 = V_23 ;
}
static void F_379 ( struct V_26 * V_27 )
{
F_378 ( V_27 , 1 ) ;
}
static void F_380 ( struct V_26 * V_27 )
{
F_378 ( V_27 , 0 ) ;
}
int F_381 ( struct V_770 * V_771 )
{
struct V_26 * V_27 = V_771 -> V_27 ;
struct V_800 * V_169 = NULL ;
struct V_171 V_172 ;
unsigned long V_801 ;
int V_95 ;
void * V_85 = V_27 -> V_202 . V_173 ;
int V_802 = 0 ;
unsigned int V_170 = F_95 ( V_27 ) ;
int F_55 = V_170 ;
bool V_803 = false ;
struct V_804 V_805 = { . V_806 = 2 } ;
V_95 = F_382 ( V_43 , V_807 , & V_805 ) ;
if ( V_95 < 0 )
F_45 ( V_27 , L_202 , V_95 ) ;
while ( F_114 ( V_771 ) == V_727 ) {
F_335 ( V_771 ) ;
F_23 ( V_27 ) ;
if ( F_282 ( V_808 , & V_27 -> V_69 ) ) {
if ( F_383 ( V_27 ) ) {
F_45 ( V_27 , L_203 ) ;
goto V_616;
}
F_379 ( V_27 ) ;
V_803 = true ;
}
V_801 = V_66 ;
V_95 = F_65 ( V_27 -> V_202 . V_83 , V_85 , F_55 - V_802 , 0 ) ;
if ( F_182 ( V_95 > 0 ) ) {
V_802 += V_95 ;
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
goto V_616;
} else if ( V_95 == - V_144 ) {
if ( F_384 ( V_27 -> V_218 , V_801 ) )
continue;
if ( V_803 ) {
F_45 ( V_27 , L_205 ) ;
goto V_616;
}
F_111 ( V_808 , & V_27 -> V_69 ) ;
continue;
} else if ( V_95 == - V_146 ) {
F_112 ( V_43 ) ;
continue;
} else {
F_45 ( V_27 , L_7 , V_95 ) ;
goto V_616;
}
if ( V_802 == F_55 && V_169 == NULL ) {
if ( F_96 ( V_27 , V_27 -> V_202 . V_173 , & V_172 ) )
goto V_616;
V_169 = & V_809 [ V_172 . V_169 ] ;
if ( V_172 . V_169 >= F_336 ( V_809 ) || ! V_169 -> V_731 ) {
F_45 ( V_27 , L_206 ,
F_269 ( V_172 . V_169 ) , V_172 . V_169 ) ;
goto V_596;
}
F_55 = V_170 + V_169 -> V_732 ;
if ( V_172 . V_64 != F_55 - V_170 ) {
F_45 ( V_27 , L_207 ,
V_172 . V_169 , V_172 . V_64 ) ;
goto V_616;
}
}
if ( V_802 == F_55 ) {
bool V_77 ;
V_77 = V_169 -> V_731 ( V_27 , & V_172 ) ;
if ( V_77 ) {
F_45 ( V_27 , L_208 , V_169 -> V_731 ) ;
goto V_616;
}
V_27 -> V_218 = V_66 ;
if ( V_169 == & V_809 [ V_810 ] ) {
F_380 ( V_27 ) ;
V_803 = false ;
}
V_85 = V_27 -> V_202 . V_173 ;
V_802 = 0 ;
F_55 = V_170 ;
V_169 = NULL ;
}
}
if ( 0 ) {
V_616:
F_71 ( V_27 , F_72 ( V_105 , V_737 ) , V_107 ) ;
F_385 ( V_27 ) ;
}
if ( 0 ) {
V_596:
F_71 ( V_27 , F_72 ( V_105 , V_151 ) , V_107 ) ;
}
F_68 ( V_27 , L_209 ) ;
return 0 ;
}
void F_386 ( struct V_811 * V_812 )
{
struct V_28 * V_29 =
F_181 ( V_812 , struct V_28 , V_421 ) ;
struct V_26 * V_27 = V_29 -> V_27 ;
struct V_9 * V_10 = V_29 -> V_10 ;
struct V_35 * V_36 ;
int V_813 , V_77 ;
F_24 () ;
V_36 = F_32 ( V_27 -> V_35 ) ;
V_813 = V_36 -> V_813 ;
F_28 () ;
if ( V_813 )
F_387 ( V_27 -> V_202 . V_83 ) ;
V_77 = F_59 ( V_10 ) ;
F_29 ( & V_10 -> V_32 , V_33 ) ;
if ( V_77 ) {
F_71 ( V_27 , F_72 ( V_105 , V_737 ) , V_107 ) ;
return;
}
if ( V_813 )
F_388 ( V_27 -> V_202 . V_83 ) ;
return;
}
