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
F_20 ( & V_27 -> V_24 -> V_25 ) ;
F_111 ( V_222 , & V_27 -> V_69 ) ;
F_21 ( & V_27 -> V_24 -> V_25 ) ;
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
static void F_127 ( struct V_26 * V_27 )
{
if ( V_43 -> V_243 == & V_27 -> V_244 ) {
F_128 ( & V_27 -> V_244 ) ;
F_129 ( & V_27 -> V_244 ) ;
}
}
static int F_130 ( struct V_26 * V_27 , struct V_171 * V_172 )
{
void * V_245 = V_27 -> V_96 . V_173 ;
int V_77 ;
V_77 = F_74 ( V_27 , V_245 , F_95 ( V_27 ) ) ;
if ( V_77 )
return V_77 ;
V_77 = F_96 ( V_27 , V_245 , V_172 ) ;
V_27 -> V_218 = V_66 ;
return V_77 ;
}
static int F_131 ( struct V_26 * V_27 , struct V_171 * V_172 )
{
void * V_245 = V_27 -> V_96 . V_173 ;
unsigned int V_64 = F_95 ( V_27 ) ;
int V_77 ;
V_77 = F_65 ( V_27 -> V_96 . V_83 , V_245 , V_64 , V_94 | V_176 ) ;
if ( V_77 != V_64 ) {
if ( V_77 == - V_144 ) {
F_132 ( V_27 -> V_96 . V_83 ) ;
F_127 ( V_27 ) ;
}
if ( V_77 > 0 ) {
V_245 += V_77 ;
V_64 -= V_77 ;
}
V_77 = F_74 ( V_27 , V_245 , V_64 ) ;
if ( V_77 )
return V_77 ;
}
V_77 = F_96 ( V_27 , V_27 -> V_96 . V_173 , V_172 ) ;
V_27 -> V_218 = V_66 ;
return V_77 ;
}
static void F_133 ( struct V_246 * V_246 )
{
struct V_247 * V_248 = V_246 -> V_249 ;
struct V_9 * V_10 = V_248 -> V_10 ;
struct V_250 * V_251 = V_248 -> V_251 ;
if ( V_246 -> V_252 ) {
V_251 -> error = F_134 ( V_246 -> V_252 ) ;
F_68 ( V_10 , L_27 , V_246 -> V_252 ) ;
}
F_52 ( V_248 ) ;
F_135 ( V_246 ) ;
F_106 ( V_253 , & V_10 -> V_69 ) ;
F_136 ( V_10 ) ;
F_29 ( & V_10 -> V_32 , V_33 ) ;
if ( F_137 ( & V_251 -> V_254 ) )
F_82 ( & V_251 -> V_255 ) ;
}
static void F_138 ( struct V_9 * V_10 , struct V_250 * V_251 )
{
struct V_246 * V_246 = F_139 ( V_213 , 0 ) ;
struct V_247 * V_248 = F_140 ( sizeof( * V_248 ) , V_213 ) ;
if ( ! V_246 || ! V_248 ) {
F_35 ( V_10 , L_28 ) ;
F_52 ( V_248 ) ;
if ( V_246 )
F_135 ( V_246 ) ;
V_251 -> error = - V_256 ;
F_136 ( V_10 ) ;
F_29 ( & V_10 -> V_32 , V_33 ) ;
return;
}
V_248 -> V_10 = V_10 ;
V_248 -> V_251 = V_251 ;
F_141 ( V_246 , V_10 -> V_257 -> V_258 ) ;
V_246 -> V_249 = V_248 ;
V_246 -> V_259 = F_133 ;
V_246 -> V_260 = V_261 | V_262 ;
V_10 -> V_263 = V_66 ;
F_111 ( V_253 , & V_10 -> V_69 ) ;
F_142 ( & V_251 -> V_254 ) ;
F_143 ( V_246 ) ;
}
static void F_144 ( struct V_26 * V_27 )
{
if ( V_27 -> V_24 -> V_264 >= V_265 ) {
struct V_28 * V_29 ;
struct V_250 V_251 ;
int V_30 ;
F_101 ( & V_251 . V_254 , 1 ) ;
V_251 . error = 0 ;
F_145 ( & V_251 . V_255 ) ;
F_24 () ;
F_25 (&connection->peer_devices, peer_device, vnr) {
struct V_9 * V_10 = V_29 -> V_10 ;
if ( ! F_146 ( V_10 ) )
continue;
F_27 ( & V_10 -> V_32 ) ;
F_28 () ;
F_138 ( V_10 , & V_251 ) ;
F_24 () ;
}
F_28 () ;
if ( ! F_137 ( & V_251 . V_254 ) )
F_147 ( & V_251 . V_255 ) ;
if ( V_251 . error ) {
F_148 ( V_27 -> V_24 , NULL , V_266 ) ;
}
}
}
static enum V_267 F_149 ( struct V_26 * V_27 ,
struct V_268 * V_269 ,
enum V_270 V_271 )
{
int V_272 ;
struct V_268 * V_273 ;
enum V_267 V_95 = V_274 ;
F_11 ( & V_27 -> V_275 ) ;
do {
V_273 = NULL ;
V_272 = F_26 ( & V_269 -> V_272 ) ;
switch ( V_271 & ~ V_276 ) {
case V_277 :
F_150 ( & V_269 -> V_278 ) ;
break;
case V_279 :
F_111 ( V_280 , & V_269 -> V_69 ) ;
break;
case V_281 :
break;
}
if ( V_272 != 0 &&
F_26 ( & V_269 -> V_278 ) == 0 &&
( F_69 ( V_280 , & V_269 -> V_69 ) || V_271 & V_276 ) ) {
if ( ! ( V_271 & V_276 ) ) {
F_12 ( & V_27 -> V_275 ) ;
F_151 ( V_269 -> V_27 , V_269 -> V_282 , V_272 ) ;
F_11 ( & V_27 -> V_275 ) ;
}
#if 0
if (test_bit(DE_HAVE_BARRIER_NUMBER, &epoch->flags))
dec_unacked(epoch->connection);
#endif
if ( V_27 -> V_283 != V_269 ) {
V_273 = F_152 ( V_269 -> V_21 . V_284 , struct V_268 , V_21 ) ;
F_153 ( & V_269 -> V_21 ) ;
V_271 = V_281 | ( V_271 & V_276 ) ;
V_27 -> V_285 -- ;
F_52 ( V_269 ) ;
if ( V_95 == V_274 )
V_95 = V_286 ;
} else {
V_269 -> V_69 = 0 ;
F_101 ( & V_269 -> V_272 , 0 ) ;
if ( V_95 == V_274 )
V_95 = V_287 ;
}
}
if ( ! V_273 )
break;
V_269 = V_273 ;
} while ( 1 );
F_12 ( & V_27 -> V_275 ) ;
return V_95 ;
}
static enum V_288
F_154 ( struct V_289 * V_290 , enum V_288 V_291 )
{
struct V_292 * V_293 ;
V_293 = F_32 ( V_290 -> V_292 ) ;
if ( V_291 == V_265 && ! V_293 -> V_294 )
V_291 = V_266 ;
if ( V_291 == V_266 && ! V_293 -> V_295 )
V_291 = V_296 ;
return V_291 ;
}
void F_148 ( struct V_297 * V_24 , struct V_289 * V_290 ,
enum V_288 V_291 )
{
struct V_9 * V_10 ;
enum V_288 V_298 ;
int V_30 ;
static char * V_299 [] = {
[ V_296 ] = L_29 ,
[ V_266 ] = L_30 ,
[ V_265 ] = L_31 ,
} ;
V_298 = V_24 -> V_264 ;
if ( V_291 != V_265 )
V_291 = F_155 ( V_298 , V_291 ) ;
F_24 () ;
F_25 (&resource->devices, device, vnr) {
if ( F_146 ( V_10 ) ) {
V_291 = F_154 ( V_10 -> V_257 , V_291 ) ;
if ( V_10 -> V_257 == V_290 )
V_290 = NULL ;
F_136 ( V_10 ) ;
}
}
if ( V_290 )
V_291 = F_154 ( V_290 , V_291 ) ;
F_28 () ;
V_24 -> V_264 = V_291 ;
if ( V_298 != V_24 -> V_264 || V_291 == V_265 )
F_68 ( V_24 , L_32 , V_299 [ V_24 -> V_264 ] ) ;
}
static void F_156 ( struct V_9 * V_10 , struct V_18 * V_19 )
{
struct V_300 * V_290 = V_10 -> V_257 -> V_258 ;
if ( F_157 ( V_290 , V_19 -> V_6 . V_52 , V_19 -> V_6 . V_64 >> 9 ,
V_213 , 0 ) )
V_19 -> V_69 |= V_301 ;
F_158 ( V_19 ) ;
}
static void F_159 ( struct V_9 * V_10 ,
struct V_18 * V_19 )
{
struct V_300 * V_290 = V_10 -> V_257 -> V_258 ;
T_3 V_203 = V_19 -> V_6 . V_52 ;
T_3 V_302 = V_19 -> V_6 . V_64 >> 9 ;
if ( F_160 ( V_290 , V_203 , V_302 , V_213 , V_19 -> V_67 ) )
V_19 -> V_69 |= V_301 ;
F_158 ( V_19 ) ;
}
int F_161 ( struct V_9 * V_10 ,
struct V_18 * V_19 ,
const unsigned V_303 , const unsigned V_304 ,
const int V_305 )
{
struct V_246 * V_306 = NULL ;
struct V_246 * V_246 ;
struct V_1 * V_1 = V_19 -> V_67 ;
T_3 V_52 = V_19 -> V_6 . V_52 ;
unsigned V_307 = V_19 -> V_6 . V_64 ;
unsigned V_308 = 0 ;
unsigned V_56 = ( V_307 + V_49 - 1 ) >> V_57 ;
int V_77 = - V_256 ;
if ( V_19 -> V_69 & ( V_309 | V_310 ) ) {
F_162 ( V_19 -> V_29 -> V_27 ) ;
V_19 -> V_65 = V_66 ;
V_19 -> V_69 |= V_311 ;
if ( F_62 ( & V_19 -> V_20 . V_21 ) ) {
F_20 ( & V_10 -> V_24 -> V_25 ) ;
F_163 ( & V_19 -> V_20 . V_21 , & V_10 -> V_312 ) ;
F_21 ( & V_10 -> V_24 -> V_25 ) ;
}
if ( V_19 -> V_69 & V_309 )
F_156 ( V_10 , V_19 ) ;
else
F_159 ( V_10 , V_19 ) ;
return 0 ;
}
V_313:
V_246 = F_139 ( V_213 , V_56 ) ;
if ( ! V_246 ) {
F_45 ( V_10 , L_33 , V_56 ) ;
goto V_63;
}
V_246 -> V_314 . V_315 = V_52 ;
F_141 ( V_246 , V_10 -> V_257 -> V_258 ) ;
F_164 ( V_246 , V_303 , V_304 ) ;
V_246 -> V_249 = V_19 ;
V_246 -> V_259 = V_316 ;
V_246 -> V_317 = V_306 ;
V_306 = V_246 ;
++ V_308 ;
F_165 (page) {
unsigned V_5 = F_77 ( unsigned , V_307 , V_49 ) ;
if ( ! F_166 ( V_246 , V_1 , V_5 , 0 ) )
goto V_313;
V_307 -= V_5 ;
V_52 += V_5 >> 9 ;
-- V_56 ;
}
F_53 ( V_10 , V_307 == 0 ) ;
F_53 ( V_10 , V_1 == NULL ) ;
F_101 ( & V_19 -> V_72 , V_308 ) ;
V_19 -> V_65 = V_66 ;
V_19 -> V_69 |= V_311 ;
do {
V_246 = V_306 ;
V_306 = V_306 -> V_317 ;
V_246 -> V_317 = NULL ;
F_167 ( V_10 , V_305 , V_246 ) ;
} while ( V_306 );
return 0 ;
V_63:
while ( V_306 ) {
V_246 = V_306 ;
V_306 = V_306 -> V_317 ;
F_135 ( V_246 ) ;
}
return V_77 ;
}
static void F_168 ( struct V_9 * V_10 ,
struct V_18 * V_19 )
{
struct V_318 * V_6 = & V_19 -> V_6 ;
F_169 ( & V_10 -> V_319 , V_6 ) ;
F_48 ( V_6 ) ;
if ( V_6 -> V_320 )
F_41 ( & V_10 -> V_321 ) ;
}
static void F_162 ( struct V_26 * V_27 )
{
struct V_28 * V_29 ;
int V_30 ;
F_24 () ;
F_25 (&connection->peer_devices, peer_device, vnr) {
struct V_9 * V_10 = V_29 -> V_10 ;
F_27 ( & V_10 -> V_32 ) ;
F_28 () ;
F_64 ( V_10 , & V_10 -> V_312 ) ;
F_29 ( & V_10 -> V_32 , V_33 ) ;
F_24 () ;
}
F_28 () ;
}
static int F_170 ( struct V_26 * V_27 , struct V_171 * V_172 )
{
int V_95 ;
struct V_322 * V_323 = V_172 -> V_96 ;
struct V_268 * V_269 ;
V_27 -> V_283 -> V_282 = V_323 -> V_324 ;
V_27 -> V_283 -> V_27 = V_27 ;
V_95 = F_149 ( V_27 , V_27 -> V_283 , V_279 ) ;
switch ( V_27 -> V_24 -> V_264 ) {
case V_296 :
if ( V_95 == V_287 )
return 0 ;
V_269 = F_140 ( sizeof( struct V_268 ) , V_213 ) ;
if ( V_269 )
break;
else
F_35 ( V_27 , L_34 ) ;
case V_265 :
case V_266 :
F_162 ( V_27 ) ;
F_144 ( V_27 ) ;
if ( F_26 ( & V_27 -> V_283 -> V_272 ) ) {
V_269 = F_140 ( sizeof( struct V_268 ) , V_213 ) ;
if ( V_269 )
break;
}
return 0 ;
default:
F_45 ( V_27 , L_35 ,
V_27 -> V_24 -> V_264 ) ;
return - V_108 ;
}
V_269 -> V_69 = 0 ;
F_101 ( & V_269 -> V_272 , 0 ) ;
F_101 ( & V_269 -> V_278 , 0 ) ;
F_11 ( & V_27 -> V_275 ) ;
if ( F_26 ( & V_27 -> V_283 -> V_272 ) ) {
F_171 ( & V_269 -> V_21 , & V_27 -> V_283 -> V_21 ) ;
V_27 -> V_283 = V_269 ;
V_27 -> V_285 ++ ;
} else {
F_52 ( V_269 ) ;
}
F_12 ( & V_27 -> V_275 ) ;
return 0 ;
}
static void F_172 ( struct V_325 * V_194 ,
struct V_18 * V_326 , void * V_327 ,
unsigned int V_54 )
{
unsigned int V_4 = V_326 -> V_6 . V_64 ;
V_326 -> V_6 . V_64 = V_54 ;
F_173 ( V_194 , V_326 , V_327 ) ;
V_326 -> V_6 . V_64 = V_4 ;
}
static struct V_18 *
F_174 ( struct V_28 * V_29 , T_2 V_51 , T_3 V_52 ,
struct V_171 * V_172 ) __must_hold( T_5 )
{
struct V_9 * V_10 = V_29 -> V_10 ;
const T_3 V_328 = F_175 ( V_10 -> V_329 ) ;
struct V_18 * V_19 ;
struct V_1 * V_1 ;
int V_330 , V_77 ;
unsigned int V_307 = V_172 -> V_64 , V_331 ;
void * V_332 = V_29 -> V_27 -> V_333 ;
void * V_334 = V_29 -> V_27 -> V_335 ;
unsigned long * V_96 ;
struct V_336 * V_337 = ( V_172 -> V_169 == V_338 ) ? V_172 -> V_96 : NULL ;
struct V_336 * V_339 = ( V_172 -> V_169 == V_340 ) ? V_172 -> V_96 : NULL ;
V_330 = 0 ;
if ( ! V_337 && V_29 -> V_27 -> V_341 ) {
V_330 = F_176 ( V_29 -> V_27 -> V_341 ) ;
V_77 = F_74 ( V_29 -> V_27 , V_332 , V_330 ) ;
if ( V_77 )
return NULL ;
V_307 -= V_330 ;
}
V_331 = V_307 ;
if ( V_337 ) {
if ( ! F_55 ( V_307 == 0 ) )
return NULL ;
V_331 = F_125 ( V_337 -> V_64 ) ;
} else if ( V_339 ) {
if ( V_307 != F_177 ( V_10 -> V_342 ) ) {
F_45 ( V_29 , L_36 ,
V_307 , F_177 ( V_10 -> V_342 ) ) ;
return NULL ;
}
if ( V_307 != F_178 ( V_10 -> V_257 -> V_258 ) ) {
F_45 ( V_29 , L_37 ,
V_307 , F_178 ( V_10 -> V_257 -> V_258 ) ) ;
return NULL ;
}
V_331 = F_125 ( V_339 -> V_64 ) ;
}
if ( ! F_55 ( F_179 ( V_331 , 512 ) ) )
return NULL ;
if ( V_337 || V_339 ) {
if ( ! F_55 ( V_331 <= ( V_343 << 9 ) ) )
return NULL ;
} else if ( ! F_55 ( V_331 <= V_48 ) )
return NULL ;
if ( V_52 + ( V_331 >> 9 ) > V_328 ) {
F_45 ( V_10 , L_38
L_39 ,
( unsigned long long ) V_328 ,
( unsigned long long ) V_52 , V_331 ) ;
return NULL ;
}
V_19 = F_42 ( V_29 , V_51 , V_52 , V_331 , V_307 , V_213 ) ;
if ( ! V_19 )
return NULL ;
V_19 -> V_69 |= V_344 ;
if ( V_337 ) {
V_19 -> V_69 |= V_309 ;
return V_19 ;
}
if ( V_339 )
V_19 -> V_69 |= V_310 ;
V_331 = V_307 ;
V_1 = V_19 -> V_67 ;
F_165 (page) {
unsigned V_5 = F_77 ( int , V_331 , V_49 ) ;
V_96 = F_180 ( V_1 ) ;
V_77 = F_74 ( V_29 -> V_27 , V_96 , V_5 ) ;
if ( F_43 ( V_10 , V_345 ) ) {
F_45 ( V_10 , L_40 ) ;
V_96 [ 0 ] = V_96 [ 0 ] ^ ( unsigned long ) - 1 ;
}
F_181 ( V_1 ) ;
if ( V_77 ) {
F_60 ( V_10 , V_19 ) ;
return NULL ;
}
V_331 -= V_5 ;
}
if ( V_330 ) {
F_172 ( V_29 -> V_27 -> V_341 , V_19 , V_334 , V_307 ) ;
if ( memcmp ( V_332 , V_334 , V_330 ) ) {
F_45 ( V_10 , L_41 ,
( unsigned long long ) V_52 , V_307 ) ;
F_60 ( V_10 , V_19 ) ;
return NULL ;
}
}
V_10 -> V_346 += V_307 >> 9 ;
return V_19 ;
}
static int F_182 ( struct V_28 * V_29 , int V_307 )
{
struct V_1 * V_1 ;
int V_77 = 0 ;
void * V_96 ;
if ( ! V_307 )
return 0 ;
V_1 = F_30 ( V_29 , 1 , 1 ) ;
V_96 = F_180 ( V_1 ) ;
while ( V_307 ) {
unsigned int V_5 = F_77 ( int , V_307 , V_49 ) ;
V_77 = F_74 ( V_29 -> V_27 , V_96 , V_5 ) ;
if ( V_77 )
break;
V_307 -= V_5 ;
}
F_181 ( V_1 ) ;
F_39 ( V_29 -> V_10 , V_1 , 0 ) ;
return V_77 ;
}
static int F_183 ( struct V_28 * V_29 , struct V_347 * V_348 ,
T_3 V_52 , int V_307 )
{
struct V_349 V_350 ;
struct V_351 V_352 ;
struct V_246 * V_246 ;
int V_330 , V_77 , F_55 ;
void * V_332 = V_29 -> V_27 -> V_333 ;
void * V_334 = V_29 -> V_27 -> V_335 ;
V_330 = 0 ;
if ( V_29 -> V_27 -> V_341 ) {
V_330 = F_176 ( V_29 -> V_27 -> V_341 ) ;
V_77 = F_74 ( V_29 -> V_27 , V_332 , V_330 ) ;
if ( V_77 )
return V_77 ;
V_307 -= V_330 ;
}
V_29 -> V_10 -> V_346 += V_307 >> 9 ;
V_246 = V_348 -> V_353 ;
F_53 ( V_29 -> V_10 , V_52 == V_246 -> V_314 . V_315 ) ;
F_184 (bvec, bio, iter) {
void * V_354 = F_180 ( V_350 . V_355 ) + V_350 . V_356 ;
F_55 = F_77 ( int , V_307 , V_350 . V_357 ) ;
V_77 = F_74 ( V_29 -> V_27 , V_354 , F_55 ) ;
F_181 ( V_350 . V_355 ) ;
if ( V_77 )
return V_77 ;
V_307 -= F_55 ;
}
if ( V_330 ) {
F_185 ( V_29 -> V_27 -> V_341 , V_246 , V_334 ) ;
if ( memcmp ( V_332 , V_334 , V_330 ) ) {
F_45 ( V_29 , L_42 ) ;
return - V_234 ;
}
}
F_53 ( V_29 -> V_10 , V_307 == 0 ) ;
return 0 ;
}
static int F_186 ( struct V_358 * V_20 , int V_359 )
{
struct V_18 * V_19 =
F_187 ( V_20 , struct V_18 , V_20 ) ;
struct V_28 * V_29 = V_19 -> V_29 ;
struct V_9 * V_10 = V_29 -> V_10 ;
T_3 V_52 = V_19 -> V_6 . V_52 ;
int V_77 ;
F_53 ( V_10 , F_54 ( & V_19 -> V_6 ) ) ;
if ( F_188 ( ( V_19 -> V_69 & V_301 ) == 0 ) ) {
F_189 ( V_10 , V_52 , V_19 -> V_6 . V_64 ) ;
V_77 = F_190 ( V_29 , V_360 , V_19 ) ;
} else {
F_191 ( V_10 , V_52 , V_19 -> V_6 . V_64 ) ;
V_77 = F_190 ( V_29 , V_361 , V_19 ) ;
}
F_192 ( V_10 ) ;
return V_77 ;
}
static int F_193 ( struct V_28 * V_29 , T_3 V_52 ,
struct V_171 * V_172 ) __releases( T_5 )
{
struct V_9 * V_10 = V_29 -> V_10 ;
struct V_18 * V_19 ;
V_19 = F_174 ( V_29 , V_362 , V_52 , V_172 ) ;
if ( ! V_19 )
goto V_63;
F_194 ( V_10 ) ;
F_195 ( V_10 ) ;
V_19 -> V_20 . V_80 = F_186 ;
V_19 -> V_65 = V_66 ;
F_20 ( & V_10 -> V_24 -> V_25 ) ;
F_163 ( & V_19 -> V_20 . V_21 , & V_10 -> V_363 ) ;
F_21 ( & V_10 -> V_24 -> V_25 ) ;
F_38 ( V_172 -> V_64 >> 9 , & V_10 -> V_364 ) ;
if ( F_161 ( V_10 , V_19 , V_365 , 0 ,
V_366 ) == 0 )
return 0 ;
F_45 ( V_10 , L_43 ) ;
F_20 ( & V_10 -> V_24 -> V_25 ) ;
F_153 ( & V_19 -> V_20 . V_21 ) ;
F_21 ( & V_10 -> V_24 -> V_25 ) ;
F_60 ( V_10 , V_19 ) ;
V_63:
F_136 ( V_10 ) ;
return - V_108 ;
}
static struct V_347 *
F_196 ( struct V_9 * V_10 , struct V_367 * V_368 , T_2 V_51 ,
T_3 V_52 , bool V_369 , const char * V_370 )
{
struct V_347 * V_348 ;
V_348 = (struct V_347 * ) ( unsigned long ) V_51 ;
if ( F_197 ( V_368 , V_52 , & V_348 -> V_6 ) && V_348 -> V_6 . T_5 )
return V_348 ;
if ( ! V_369 ) {
F_45 ( V_10 , L_44 , V_370 ,
( unsigned long ) V_51 , ( unsigned long long ) V_52 ) ;
}
return NULL ;
}
static int F_198 ( struct V_26 * V_27 , struct V_171 * V_172 )
{
struct V_28 * V_29 ;
struct V_9 * V_10 ;
struct V_347 * V_348 ;
T_3 V_52 ;
int V_77 ;
struct V_371 * V_323 = V_172 -> V_96 ;
V_29 = F_199 ( V_27 , V_172 -> V_30 ) ;
if ( ! V_29 )
return - V_108 ;
V_10 = V_29 -> V_10 ;
V_52 = F_200 ( V_323 -> V_52 ) ;
F_20 ( & V_10 -> V_24 -> V_25 ) ;
V_348 = F_196 ( V_10 , & V_10 -> V_372 , V_323 -> V_68 , V_52 , false , V_62 ) ;
F_21 ( & V_10 -> V_24 -> V_25 ) ;
if ( F_201 ( ! V_348 ) )
return - V_108 ;
V_77 = F_183 ( V_29 , V_348 , V_52 , V_172 -> V_64 ) ;
if ( ! V_77 )
F_202 ( V_348 , V_373 ) ;
return V_77 ;
}
static int F_203 ( struct V_26 * V_27 , struct V_171 * V_172 )
{
struct V_28 * V_29 ;
struct V_9 * V_10 ;
T_3 V_52 ;
int V_77 ;
struct V_371 * V_323 = V_172 -> V_96 ;
V_29 = F_199 ( V_27 , V_172 -> V_30 ) ;
if ( ! V_29 )
return - V_108 ;
V_10 = V_29 -> V_10 ;
V_52 = F_200 ( V_323 -> V_52 ) ;
F_53 ( V_10 , V_323 -> V_68 == V_362 ) ;
if ( F_146 ( V_10 ) ) {
V_77 = F_193 ( V_29 , V_52 , V_172 ) ;
} else {
if ( F_204 ( & V_374 ) )
F_45 ( V_10 , L_45 ) ;
V_77 = F_182 ( V_29 , V_172 -> V_64 ) ;
F_205 ( V_29 , V_361 , V_323 , V_172 -> V_64 ) ;
}
F_38 ( V_172 -> V_64 >> 9 , & V_10 -> V_375 ) ;
return V_77 ;
}
static void F_206 ( struct V_9 * V_10 ,
T_3 V_52 , int V_64 )
{
struct V_318 * V_6 ;
struct V_347 * V_348 ;
F_207 (i, &device->write_requests, sector, size) {
if ( ! V_6 -> T_5 )
continue;
V_348 = F_187 ( V_6 , struct V_347 , V_6 ) ;
if ( V_348 -> V_376 & V_377 ||
! ( V_348 -> V_376 & V_378 ) )
continue;
F_208 ( V_348 , V_379 , NULL ) ;
}
}
static int F_209 ( struct V_358 * V_20 , int V_380 )
{
struct V_18 * V_19 =
F_187 ( V_20 , struct V_18 , V_20 ) ;
struct V_28 * V_29 = V_19 -> V_29 ;
struct V_9 * V_10 = V_29 -> V_10 ;
T_3 V_52 = V_19 -> V_6 . V_52 ;
int V_77 = 0 , V_381 ;
if ( V_19 -> V_69 & V_382 ) {
if ( F_188 ( ( V_19 -> V_69 & V_301 ) == 0 ) ) {
V_381 = ( V_10 -> V_383 . V_105 >= V_384 &&
V_10 -> V_383 . V_105 <= V_385 &&
V_19 -> V_69 & V_386 ) ?
V_360 : V_387 ;
V_77 = F_190 ( V_29 , V_381 , V_19 ) ;
if ( V_381 == V_360 )
F_189 ( V_10 , V_52 , V_19 -> V_6 . V_64 ) ;
} else {
V_77 = F_190 ( V_29 , V_361 , V_19 ) ;
}
F_192 ( V_10 ) ;
}
if ( V_19 -> V_69 & V_388 ) {
F_20 ( & V_10 -> V_24 -> V_25 ) ;
F_53 ( V_10 , ! F_54 ( & V_19 -> V_6 ) ) ;
F_168 ( V_10 , V_19 ) ;
if ( V_19 -> V_69 & V_389 )
F_206 ( V_10 , V_52 , V_19 -> V_6 . V_64 ) ;
F_21 ( & V_10 -> V_24 -> V_25 ) ;
} else
F_53 ( V_10 , F_54 ( & V_19 -> V_6 ) ) ;
F_149 ( V_29 -> V_27 , V_19 -> V_269 , V_277 + ( V_380 ? V_276 : 0 ) ) ;
return V_77 ;
}
static int F_210 ( struct V_358 * V_20 , enum V_168 V_390 )
{
struct V_18 * V_19 =
F_187 ( V_20 , struct V_18 , V_20 ) ;
struct V_28 * V_29 = V_19 -> V_29 ;
int V_77 ;
V_77 = F_190 ( V_29 , V_390 , V_19 ) ;
F_192 ( V_29 -> V_10 ) ;
return V_77 ;
}
static int F_211 ( struct V_358 * V_20 , int V_359 )
{
return F_210 ( V_20 , V_391 ) ;
}
static int F_212 ( struct V_358 * V_20 , int V_359 )
{
struct V_18 * V_19 =
F_187 ( V_20 , struct V_18 , V_20 ) ;
struct V_26 * V_27 = V_19 -> V_29 -> V_27 ;
return F_210 ( V_20 , V_27 -> V_186 >= 100 ?
V_392 : V_391 ) ;
}
static bool F_213 ( T_7 V_47 , T_7 V_393 )
{
return ( V_394 ) V_47 - ( V_394 ) V_393 > 0 ;
}
static T_7 F_214 ( T_7 V_47 , T_7 V_393 )
{
return F_213 ( V_47 , V_393 ) ? V_47 : V_393 ;
}
static void F_215 ( struct V_28 * V_29 , unsigned int V_184 )
{
struct V_9 * V_10 = V_29 -> V_10 ;
unsigned int V_395 ;
if ( F_69 ( V_205 , & V_29 -> V_27 -> V_69 ) ) {
F_11 ( & V_10 -> V_396 ) ;
V_395 = F_214 ( V_10 -> V_184 , V_184 ) ;
V_10 -> V_184 = V_395 ;
F_12 ( & V_10 -> V_396 ) ;
if ( V_184 == V_395 )
F_41 ( & V_10 -> V_397 ) ;
}
}
static inline int F_216 ( T_3 V_398 , int V_399 , T_3 V_400 , int V_401 )
{
return ! ( ( V_398 + ( V_399 >> 9 ) <= V_400 ) || ( V_398 >= V_400 + ( V_401 >> 9 ) ) ) ;
}
static bool F_217 ( struct V_9 * V_10 , struct V_18 * V_19 )
{
struct V_18 * V_402 ;
bool V_95 = false ;
F_20 ( & V_10 -> V_24 -> V_25 ) ;
F_218 (rs_req, &device->sync_ee, w.list) {
if ( F_216 ( V_19 -> V_6 . V_52 , V_19 -> V_6 . V_64 ,
V_402 -> V_6 . V_52 , V_402 -> V_6 . V_64 ) ) {
V_95 = true ;
break;
}
}
F_21 ( & V_10 -> V_24 -> V_25 ) ;
return V_95 ;
}
static int F_219 ( struct V_28 * V_29 , const T_7 V_184 )
{
struct V_9 * V_10 = V_29 -> V_10 ;
F_31 ( V_37 ) ;
long V_180 ;
int V_403 = 0 , V_404 ;
if ( ! F_69 ( V_205 , & V_29 -> V_27 -> V_69 ) )
return 0 ;
F_11 ( & V_10 -> V_396 ) ;
for (; ; ) {
if ( ! F_213 ( V_184 - 1 , V_10 -> V_184 ) ) {
V_10 -> V_184 = F_214 ( V_10 -> V_184 , V_184 ) ;
break;
}
if ( F_34 ( V_43 ) ) {
V_403 = - V_98 ;
break;
}
F_24 () ;
V_404 = F_32 ( V_29 -> V_27 -> V_35 ) -> V_405 ;
F_28 () ;
if ( ! V_404 )
break;
F_33 ( & V_10 -> V_397 , & V_37 , V_42 ) ;
F_12 ( & V_10 -> V_396 ) ;
F_24 () ;
V_180 = F_32 ( V_29 -> V_27 -> V_35 ) -> V_100 * V_44 / 10 ;
F_28 () ;
V_180 = F_36 ( V_180 ) ;
F_11 ( & V_10 -> V_396 ) ;
if ( ! V_180 ) {
V_403 = - V_143 ;
F_45 ( V_10 , L_46 ) ;
break;
}
}
F_12 ( & V_10 -> V_396 ) ;
F_37 ( & V_10 -> V_397 , & V_37 ) ;
return V_403 ;
}
static unsigned long F_220 ( T_7 V_406 )
{
return ( V_406 & V_407 ? V_408 : 0 ) |
( V_406 & V_409 ? V_410 : 0 ) |
( V_406 & V_411 ? V_262 : 0 ) ;
}
static unsigned long F_221 ( T_7 V_406 )
{
if ( V_406 & V_412 )
return V_413 ;
else
return V_365 ;
}
static void F_222 ( struct V_9 * V_10 , T_3 V_52 ,
unsigned int V_64 )
{
struct V_318 * V_6 ;
V_414:
F_207 (i, &device->write_requests, sector, size) {
struct V_347 * V_348 ;
struct V_415 V_416 ;
if ( ! V_6 -> T_5 )
continue;
V_348 = F_187 ( V_6 , struct V_347 , V_6 ) ;
if ( ! ( V_348 -> V_376 & V_378 ) )
continue;
V_348 -> V_376 &= ~ V_378 ;
F_208 ( V_348 , V_417 , & V_416 ) ;
F_21 ( & V_10 -> V_24 -> V_25 ) ;
if ( V_416 . V_246 )
F_223 ( V_10 , & V_416 ) ;
F_20 ( & V_10 -> V_24 -> V_25 ) ;
goto V_414;
}
}
static int F_224 ( struct V_9 * V_10 ,
struct V_18 * V_19 )
{
struct V_26 * V_27 = V_19 -> V_29 -> V_27 ;
bool V_418 = F_69 ( V_205 , & V_27 -> V_69 ) ;
T_3 V_52 = V_19 -> V_6 . V_52 ;
const unsigned int V_64 = V_19 -> V_6 . V_64 ;
struct V_318 * V_6 ;
bool V_419 ;
int V_77 ;
F_225 ( & V_10 -> V_319 , & V_19 -> V_6 ) ;
V_414:
F_207 (i, &device->write_requests, sector, size) {
if ( V_6 == & V_19 -> V_6 )
continue;
if ( V_6 -> V_420 )
continue;
if ( ! V_6 -> T_5 ) {
V_77 = F_226 ( V_10 , V_6 ) ;
if ( V_77 )
goto V_104;
goto V_414;
}
V_419 = V_6 -> V_52 == V_52 && V_6 -> V_64 == V_64 ;
if ( V_418 ) {
bool V_421 = V_6 -> V_52 <= V_52 && V_6 -> V_52 +
( V_6 -> V_64 >> 9 ) >= V_52 + ( V_64 >> 9 ) ;
if ( ! V_419 )
F_227 ( V_10 , L_47
L_48
L_49 ,
( unsigned long long ) V_6 -> V_52 , V_6 -> V_64 ,
( unsigned long long ) V_52 , V_64 ,
V_421 ? L_50 : L_51 ) ;
V_19 -> V_20 . V_80 = V_421 ? F_211 :
F_212 ;
F_163 ( & V_19 -> V_20 . V_21 , & V_10 -> V_78 ) ;
F_228 ( V_27 -> V_225 , & V_19 -> V_29 -> V_422 ) ;
V_77 = - V_423 ;
goto V_104;
} else {
struct V_347 * V_348 =
F_187 ( V_6 , struct V_347 , V_6 ) ;
if ( ! V_419 )
F_227 ( V_10 , L_47
L_52 ,
( unsigned long long ) V_6 -> V_52 , V_6 -> V_64 ,
( unsigned long long ) V_52 , V_64 ) ;
if ( V_348 -> V_376 & V_377 ||
! ( V_348 -> V_376 & V_378 ) ) {
V_77 = F_226 ( V_10 , & V_348 -> V_6 ) ;
if ( V_77 ) {
F_229 ( V_27 , F_72 ( V_105 , V_424 ) , V_107 ) ;
F_222 ( V_10 , V_52 , V_64 ) ;
goto V_104;
}
goto V_414;
}
V_19 -> V_69 |= V_389 ;
}
}
V_77 = 0 ;
V_104:
if ( V_77 )
F_168 ( V_10 , V_19 ) ;
return V_77 ;
}
static int F_230 ( struct V_26 * V_27 , struct V_171 * V_172 )
{
struct V_28 * V_29 ;
struct V_9 * V_10 ;
struct V_35 * V_36 ;
T_3 V_52 ;
struct V_18 * V_19 ;
struct V_371 * V_323 = V_172 -> V_96 ;
T_7 V_184 = F_125 ( V_323 -> V_425 ) ;
int V_303 , V_304 ;
T_7 V_426 ;
int V_77 , V_404 ;
V_29 = F_199 ( V_27 , V_172 -> V_30 ) ;
if ( ! V_29 )
return - V_108 ;
V_10 = V_29 -> V_10 ;
if ( ! F_146 ( V_10 ) ) {
int V_79 ;
V_77 = F_219 ( V_29 , V_184 ) ;
F_205 ( V_29 , V_361 , V_323 , V_172 -> V_64 ) ;
F_142 ( & V_27 -> V_283 -> V_272 ) ;
V_79 = F_182 ( V_29 , V_172 -> V_64 ) ;
if ( ! V_77 )
V_77 = V_79 ;
return V_77 ;
}
V_52 = F_200 ( V_323 -> V_52 ) ;
V_19 = F_174 ( V_29 , V_323 -> V_68 , V_52 , V_172 ) ;
if ( ! V_19 ) {
F_136 ( V_10 ) ;
return - V_108 ;
}
V_19 -> V_20 . V_80 = F_209 ;
V_19 -> V_65 = V_66 ;
V_19 -> V_69 |= V_427 ;
V_426 = F_125 ( V_323 -> V_426 ) ;
V_303 = F_221 ( V_426 ) ;
V_304 = F_220 ( V_426 ) ;
if ( V_172 -> V_169 == V_338 ) {
F_53 ( V_29 , V_19 -> V_6 . V_64 > 0 ) ;
F_53 ( V_29 , V_303 == V_413 ) ;
F_53 ( V_29 , V_19 -> V_67 == NULL ) ;
} else if ( V_19 -> V_67 == NULL ) {
F_53 ( V_10 , V_19 -> V_6 . V_64 == 0 ) ;
F_53 ( V_10 , V_426 & V_411 ) ;
}
if ( V_426 & V_428 )
V_19 -> V_69 |= V_386 ;
F_11 ( & V_27 -> V_275 ) ;
V_19 -> V_269 = V_27 -> V_283 ;
F_142 ( & V_19 -> V_269 -> V_272 ) ;
F_142 ( & V_19 -> V_269 -> V_278 ) ;
F_12 ( & V_27 -> V_275 ) ;
F_24 () ;
V_36 = F_32 ( V_29 -> V_27 -> V_35 ) ;
V_404 = V_36 -> V_405 ;
if ( V_29 -> V_27 -> V_186 < 100 ) {
switch ( V_36 -> V_429 ) {
case V_430 :
V_426 |= V_431 ;
break;
case V_432 :
V_426 |= V_433 ;
break;
}
}
F_28 () ;
if ( V_426 & V_431 ) {
V_19 -> V_69 |= V_382 ;
F_195 ( V_10 ) ;
}
if ( V_426 & V_433 ) {
F_190 ( V_29 , V_434 , V_19 ) ;
}
if ( V_404 ) {
F_53 ( V_10 , V_426 & V_431 ) ;
V_19 -> V_69 |= V_388 ;
V_77 = F_219 ( V_29 , V_184 ) ;
if ( V_77 )
goto V_435;
F_20 ( & V_10 -> V_24 -> V_25 ) ;
V_77 = F_224 ( V_10 , V_19 ) ;
if ( V_77 ) {
F_21 ( & V_10 -> V_24 -> V_25 ) ;
if ( V_77 == - V_423 ) {
F_136 ( V_10 ) ;
return 0 ;
}
goto V_435;
}
} else {
F_215 ( V_29 , V_184 ) ;
F_20 ( & V_10 -> V_24 -> V_25 ) ;
}
if ( ( V_19 -> V_69 & ( V_309 | V_310 ) ) == 0 )
F_163 ( & V_19 -> V_20 . V_21 , & V_10 -> V_312 ) ;
F_21 ( & V_10 -> V_24 -> V_25 ) ;
if ( V_10 -> V_383 . V_105 == V_436 )
F_231 ( V_10 -> V_81 , ! F_217 ( V_10 , V_19 ) ) ;
if ( V_10 -> V_383 . V_437 < V_438 ) {
F_232 ( V_10 , V_19 -> V_6 . V_52 , V_19 -> V_6 . V_64 ) ;
V_19 -> V_69 &= ~ V_386 ;
F_233 ( V_10 , & V_19 -> V_6 ) ;
V_19 -> V_69 |= V_73 ;
}
V_77 = F_161 ( V_10 , V_19 , V_303 , V_304 ,
V_439 ) ;
if ( ! V_77 )
return 0 ;
F_45 ( V_10 , L_43 ) ;
F_20 ( & V_10 -> V_24 -> V_25 ) ;
F_153 ( & V_19 -> V_20 . V_21 ) ;
F_168 ( V_10 , V_19 ) ;
F_21 ( & V_10 -> V_24 -> V_25 ) ;
if ( V_19 -> V_69 & V_73 ) {
V_19 -> V_69 &= ~ V_73 ;
F_56 ( V_10 , & V_19 -> V_6 ) ;
}
V_435:
F_149 ( V_27 , V_19 -> V_269 , V_277 | V_276 ) ;
F_136 ( V_10 ) ;
F_60 ( V_10 , V_19 ) ;
return V_77 ;
}
bool F_234 ( struct V_9 * V_10 , T_3 V_52 ,
bool V_440 )
{
struct V_441 * V_4 ;
bool V_442 = F_235 ( V_10 ) ;
if ( ! V_442 || V_440 )
return V_442 ;
F_20 ( & V_10 -> V_443 ) ;
V_4 = F_236 ( V_10 -> V_444 , F_237 ( V_52 ) ) ;
if ( V_4 ) {
struct V_445 * V_446 = F_238 ( V_4 , struct V_445 , V_447 ) ;
if ( F_69 ( V_448 , & V_446 -> V_69 ) )
V_442 = false ;
}
F_21 ( & V_10 -> V_443 ) ;
return V_442 ;
}
bool F_235 ( struct V_9 * V_10 )
{
struct V_449 * V_450 = V_10 -> V_257 -> V_258 -> V_451 -> V_452 ;
unsigned long V_453 , V_454 , V_455 ;
unsigned int V_456 ;
int V_457 ;
F_24 () ;
V_456 = F_32 ( V_10 -> V_257 -> V_292 ) -> V_456 ;
F_28 () ;
if ( V_456 == 0 )
return false ;
V_457 = ( int ) F_239 ( & V_450 -> V_458 , V_459 [ 0 ] ) +
( int ) F_239 ( & V_450 -> V_458 , V_459 [ 1 ] ) -
F_26 ( & V_10 -> V_364 ) ;
if ( F_26 ( & V_10 -> V_460 )
|| V_457 - V_10 -> V_461 > 64 ) {
unsigned long V_462 ;
int V_6 ;
V_10 -> V_461 = V_457 ;
V_6 = ( V_10 -> V_463 + V_464 - 1 ) % V_464 ;
if ( V_10 -> V_383 . V_105 == V_465 || V_10 -> V_383 . V_105 == V_466 )
V_462 = V_10 -> V_467 ;
else
V_462 = F_240 ( V_10 ) - V_10 -> V_468 ;
V_454 = ( ( long ) V_66 - ( long ) V_10 -> V_469 [ V_6 ] ) / V_44 ;
if ( ! V_454 )
V_454 ++ ;
V_453 = V_10 -> V_470 [ V_6 ] - V_462 ;
V_455 = F_241 ( V_453 / V_454 ) ;
if ( V_455 > V_456 )
return true ;
}
return false ;
}
static int F_242 ( struct V_26 * V_27 , struct V_171 * V_172 )
{
struct V_28 * V_29 ;
struct V_9 * V_10 ;
T_3 V_52 ;
T_3 V_328 ;
struct V_18 * V_19 ;
struct V_471 * V_472 = NULL ;
int V_64 , V_473 ;
unsigned int V_305 ;
struct V_474 * V_323 = V_172 -> V_96 ;
V_29 = F_199 ( V_27 , V_172 -> V_30 ) ;
if ( ! V_29 )
return - V_108 ;
V_10 = V_29 -> V_10 ;
V_328 = F_175 ( V_10 -> V_329 ) ;
V_52 = F_200 ( V_323 -> V_52 ) ;
V_64 = F_125 ( V_323 -> V_475 ) ;
if ( V_64 <= 0 || ! F_179 ( V_64 , 512 ) || V_64 > V_48 ) {
F_45 ( V_10 , L_53 , __FILE__ , __LINE__ ,
( unsigned long long ) V_52 , V_64 ) ;
return - V_234 ;
}
if ( V_52 + ( V_64 >> 9 ) > V_328 ) {
F_45 ( V_10 , L_53 , __FILE__ , __LINE__ ,
( unsigned long long ) V_52 , V_64 ) ;
return - V_234 ;
}
if ( ! F_243 ( V_10 , V_476 ) ) {
V_473 = 1 ;
switch ( V_172 -> V_169 ) {
case V_477 :
F_244 ( V_29 , V_478 , V_323 ) ;
break;
case V_479 :
case V_480 :
case V_481 :
case V_482 :
F_244 ( V_29 , V_483 , V_323 ) ;
break;
case V_484 :
V_473 = 0 ;
F_194 ( V_10 ) ;
F_245 ( V_29 , V_485 , V_52 , V_64 , V_486 ) ;
break;
default:
F_246 () ;
}
if ( V_473 && F_204 ( & V_374 ) )
F_45 ( V_10 , L_54
L_55 ) ;
return F_182 ( V_29 , V_172 -> V_64 ) ;
}
V_19 = F_42 ( V_29 , V_323 -> V_68 , V_52 , V_64 ,
V_64 , V_213 ) ;
if ( ! V_19 ) {
F_136 ( V_10 ) ;
return - V_256 ;
}
switch ( V_172 -> V_169 ) {
case V_477 :
V_19 -> V_20 . V_80 = V_487 ;
V_305 = V_488 ;
V_19 -> V_69 |= V_427 ;
goto V_489;
case V_479 :
V_19 -> V_69 |= V_490 ;
case V_480 :
V_19 -> V_20 . V_80 = V_491 ;
V_305 = V_492 ;
V_10 -> V_493 = F_247 ( V_52 ) ;
break;
case V_484 :
case V_481 :
V_305 = V_492 ;
V_472 = F_140 ( sizeof( * V_472 ) + V_172 -> V_64 , V_213 ) ;
if ( ! V_472 )
goto V_494;
V_472 -> V_330 = V_172 -> V_64 ;
V_472 -> V_71 = ( ( ( char * ) V_472 ) + sizeof( struct V_471 ) ) ;
V_19 -> V_71 = V_472 ;
V_19 -> V_69 |= V_70 ;
if ( F_73 ( V_29 -> V_27 , V_472 -> V_71 , V_172 -> V_64 ) )
goto V_494;
if ( V_172 -> V_169 == V_481 ) {
F_53 ( V_10 , V_29 -> V_27 -> V_186 >= 89 ) ;
V_19 -> V_20 . V_80 = V_495 ;
V_10 -> V_493 = F_247 ( V_52 ) ;
V_10 -> V_496 = true ;
} else if ( V_172 -> V_169 == V_484 ) {
F_38 ( V_64 >> 9 , & V_10 -> V_375 ) ;
V_19 -> V_20 . V_80 = V_497 ;
F_194 ( V_10 ) ;
goto V_498;
}
break;
case V_482 :
if ( V_10 -> V_499 == ~ ( T_3 ) 0 &&
V_29 -> V_27 -> V_186 >= 90 ) {
unsigned long V_500 = V_66 ;
int V_6 ;
V_10 -> V_499 = V_52 ;
V_10 -> V_501 = V_52 ;
V_10 -> V_467 = F_248 ( V_10 ) - F_247 ( V_52 ) ;
V_10 -> V_502 = V_10 -> V_467 ;
for ( V_6 = 0 ; V_6 < V_464 ; V_6 ++ ) {
V_10 -> V_470 [ V_6 ] = V_10 -> V_467 ;
V_10 -> V_469 [ V_6 ] = V_500 ;
}
F_68 ( V_10 , L_56 ,
( unsigned long long ) V_52 ) ;
}
V_19 -> V_20 . V_80 = V_503 ;
V_305 = V_492 ;
break;
default:
F_246 () ;
}
F_20 ( & V_10 -> V_24 -> V_25 ) ;
F_163 ( & V_19 -> V_20 . V_21 , & V_10 -> V_504 ) ;
F_21 ( & V_10 -> V_24 -> V_25 ) ;
F_249 ( V_27 , F_234 ) ;
if ( V_10 -> V_383 . V_505 != V_506
&& F_234 ( V_10 , V_52 , false ) )
F_250 ( V_44 / 10 ) ;
F_249 ( V_27 , V_507 ) ;
if ( V_507 ( V_10 , V_52 ) )
goto V_494;
V_498:
F_38 ( V_64 >> 9 , & V_10 -> V_364 ) ;
V_489:
F_249 ( V_27 , F_161 ) ;
F_195 ( V_10 ) ;
if ( F_161 ( V_10 , V_19 , V_508 , 0 ,
V_305 ) == 0 )
return 0 ;
F_45 ( V_10 , L_43 ) ;
V_494:
F_20 ( & V_10 -> V_24 -> V_25 ) ;
F_153 ( & V_19 -> V_20 . V_21 ) ;
F_21 ( & V_10 -> V_24 -> V_25 ) ;
F_136 ( V_10 ) ;
F_60 ( V_10 , V_19 ) ;
return - V_108 ;
}
static int F_251 ( struct V_28 * V_29 ) __must_hold( T_5 )
{
struct V_9 * V_10 = V_29 -> V_10 ;
int V_509 , V_505 , V_95 = - 100 ;
unsigned long V_510 , V_511 ;
enum V_512 V_513 ;
V_509 = V_10 -> V_257 -> V_514 . V_515 [ V_516 ] & 1 ;
V_505 = V_10 -> V_517 [ V_516 ] & 1 ;
V_511 = V_10 -> V_517 [ V_518 ] ;
V_510 = V_10 -> V_519 ;
F_24 () ;
V_513 = F_32 ( V_29 -> V_27 -> V_35 ) -> V_513 ;
F_28 () ;
switch ( V_513 ) {
case V_520 :
case V_521 :
case V_522 :
case V_523 :
F_45 ( V_10 , L_57 ) ;
break;
case V_524 :
break;
case V_525 :
if ( V_509 == 0 && V_505 == 1 ) {
V_95 = - 1 ;
break;
}
if ( V_509 == 1 && V_505 == 0 ) {
V_95 = 1 ;
break;
}
case V_526 :
if ( V_509 == 0 && V_505 == 1 ) {
V_95 = 1 ;
break;
}
if ( V_509 == 1 && V_505 == 0 ) {
V_95 = - 1 ;
break;
}
F_35 ( V_10 , L_58
L_59 ) ;
case V_527 :
if ( V_511 == 0 && V_510 == 0 ) {
V_95 = F_69 ( V_205 , & V_29 -> V_27 -> V_69 )
? - 1 : 1 ;
break;
} else {
if ( V_511 == 0 ) { V_95 = 1 ; break; }
if ( V_510 == 0 ) { V_95 = - 1 ; break; }
}
if ( V_513 == V_527 )
break;
case V_528 :
if ( V_510 < V_511 )
V_95 = - 1 ;
else if ( V_510 > V_511 )
V_95 = 1 ;
else
V_95 = F_69 ( V_205 , & V_29 -> V_27 -> V_69 )
? - 1 : 1 ;
break;
case V_529 :
V_95 = - 1 ;
break;
case V_530 :
V_95 = 1 ;
}
return V_95 ;
}
static int F_252 ( struct V_28 * V_29 ) __must_hold( T_5 )
{
struct V_9 * V_10 = V_29 -> V_10 ;
int V_531 , V_95 = - 100 ;
enum V_512 V_532 ;
F_24 () ;
V_532 = F_32 ( V_29 -> V_27 -> V_35 ) -> V_532 ;
F_28 () ;
switch ( V_532 ) {
case V_525 :
case V_526 :
case V_528 :
case V_529 :
case V_530 :
case V_527 :
F_45 ( V_10 , L_57 ) ;
break;
case V_524 :
break;
case V_520 :
V_531 = F_251 ( V_29 ) ;
if ( V_531 == - 1 && V_10 -> V_383 . V_533 == V_534 )
V_95 = V_531 ;
if ( V_531 == 1 && V_10 -> V_383 . V_533 == V_506 )
V_95 = V_531 ;
break;
case V_523 :
V_95 = F_251 ( V_29 ) ;
break;
case V_521 :
return V_10 -> V_383 . V_533 == V_506 ? 1 : - 1 ;
case V_522 :
V_531 = F_251 ( V_29 ) ;
if ( V_531 == - 1 && V_10 -> V_383 . V_533 == V_506 ) {
enum V_196 V_535 ;
V_535 = F_253 ( V_10 , V_198 , F_72 ( V_533 , V_534 ) ) ;
if ( V_535 != V_199 ) {
F_254 ( V_10 , L_60 ) ;
} else {
F_35 ( V_10 , L_61 ) ;
V_95 = V_531 ;
}
} else
V_95 = V_531 ;
}
return V_95 ;
}
static int F_255 ( struct V_28 * V_29 ) __must_hold( T_5 )
{
struct V_9 * V_10 = V_29 -> V_10 ;
int V_531 , V_95 = - 100 ;
enum V_512 V_536 ;
F_24 () ;
V_536 = F_32 ( V_29 -> V_27 -> V_35 ) -> V_536 ;
F_28 () ;
switch ( V_536 ) {
case V_525 :
case V_526 :
case V_528 :
case V_529 :
case V_530 :
case V_520 :
case V_521 :
case V_527 :
F_45 ( V_10 , L_57 ) ;
break;
case V_523 :
V_95 = F_251 ( V_29 ) ;
break;
case V_524 :
break;
case V_522 :
V_531 = F_251 ( V_29 ) ;
if ( V_531 == - 1 ) {
enum V_196 V_535 ;
V_535 = F_253 ( V_10 , V_198 , F_72 ( V_533 , V_534 ) ) ;
if ( V_535 != V_199 ) {
F_254 ( V_10 , L_60 ) ;
} else {
F_35 ( V_10 , L_61 ) ;
V_95 = V_531 ;
}
} else
V_95 = V_531 ;
}
return V_95 ;
}
static void F_256 ( struct V_9 * V_10 , char * V_537 , T_2 * V_515 ,
T_2 V_538 , T_2 V_69 )
{
if ( ! V_515 ) {
F_68 ( V_10 , L_62 , V_537 ) ;
return;
}
F_68 ( V_10 , L_63 ,
V_537 ,
( unsigned long long ) V_515 [ V_539 ] ,
( unsigned long long ) V_515 [ V_516 ] ,
( unsigned long long ) V_515 [ V_540 ] ,
( unsigned long long ) V_515 [ V_541 ] ,
( unsigned long long ) V_538 ,
( unsigned long long ) V_69 ) ;
}
static int F_257 ( struct V_9 * const V_10 , enum V_542 const V_543 , int * V_544 ) __must_hold( T_5 )
{
struct V_28 * const V_29 = F_258 ( V_10 ) ;
struct V_26 * const V_27 = V_29 ? V_29 -> V_27 : NULL ;
T_2 V_509 , V_505 ;
int V_6 , V_545 ;
V_509 = V_10 -> V_257 -> V_514 . V_515 [ V_539 ] & ~ ( ( T_2 ) 1 ) ;
V_505 = V_10 -> V_517 [ V_539 ] & ~ ( ( T_2 ) 1 ) ;
* V_544 = 10 ;
if ( V_509 == V_546 && V_505 == V_546 )
return 0 ;
* V_544 = 20 ;
if ( ( V_509 == V_546 || V_509 == ( T_2 ) 0 ) &&
V_505 != V_546 )
return - 2 ;
* V_544 = 30 ;
if ( V_509 != V_546 &&
( V_505 == V_546 || V_505 == ( T_2 ) 0 ) )
return 2 ;
if ( V_509 == V_505 ) {
int V_547 , V_293 ;
if ( V_10 -> V_517 [ V_516 ] == ( T_2 ) 0 && V_10 -> V_257 -> V_514 . V_515 [ V_516 ] != ( T_2 ) 0 ) {
if ( V_27 -> V_186 < 91 )
return - 1091 ;
if ( ( V_10 -> V_257 -> V_514 . V_515 [ V_516 ] & ~ ( ( T_2 ) 1 ) ) == ( V_10 -> V_517 [ V_540 ] & ~ ( ( T_2 ) 1 ) ) &&
( V_10 -> V_257 -> V_514 . V_515 [ V_540 ] & ~ ( ( T_2 ) 1 ) ) == ( V_10 -> V_517 [ V_540 + 1 ] & ~ ( ( T_2 ) 1 ) ) ) {
F_68 ( V_10 , L_64 ) ;
F_259 ( V_10 ) ;
V_10 -> V_257 -> V_514 . V_515 [ V_540 ] = V_10 -> V_257 -> V_514 . V_515 [ V_516 ] ;
V_10 -> V_257 -> V_514 . V_515 [ V_516 ] = 0 ;
F_256 ( V_10 , L_65 , V_10 -> V_257 -> V_514 . V_515 ,
V_10 -> V_383 . V_450 >= V_548 ? F_240 ( V_10 ) : 0 , 0 ) ;
* V_544 = 34 ;
} else {
F_68 ( V_10 , L_66 ) ;
* V_544 = 36 ;
}
return 1 ;
}
if ( V_10 -> V_257 -> V_514 . V_515 [ V_516 ] == ( T_2 ) 0 && V_10 -> V_517 [ V_516 ] != ( T_2 ) 0 ) {
if ( V_27 -> V_186 < 91 )
return - 1091 ;
if ( ( V_10 -> V_257 -> V_514 . V_515 [ V_540 ] & ~ ( ( T_2 ) 1 ) ) == ( V_10 -> V_517 [ V_516 ] & ~ ( ( T_2 ) 1 ) ) &&
( V_10 -> V_257 -> V_514 . V_515 [ V_540 + 1 ] & ~ ( ( T_2 ) 1 ) ) == ( V_10 -> V_517 [ V_540 ] & ~ ( ( T_2 ) 1 ) ) ) {
F_68 ( V_10 , L_67 ) ;
V_10 -> V_517 [ V_540 + 1 ] = V_10 -> V_517 [ V_540 ] ;
V_10 -> V_517 [ V_540 ] = V_10 -> V_517 [ V_516 ] ;
V_10 -> V_517 [ V_516 ] = 0UL ;
F_256 ( V_10 , L_68 , V_10 -> V_517 , V_10 -> V_517 [ V_518 ] , V_10 -> V_517 [ V_549 ] ) ;
* V_544 = 35 ;
} else {
F_68 ( V_10 , L_69 ) ;
* V_544 = 37 ;
}
return - 1 ;
}
V_547 = ( F_69 ( V_550 , & V_10 -> V_69 ) ? 1 : 0 ) +
( V_10 -> V_517 [ V_549 ] & 2 ) ;
* V_544 = 40 ;
if ( V_547 == 0 )
return 0 ;
if ( V_10 -> V_383 . V_533 == V_506 || V_543 == V_506 ) {
* V_544 = 41 ;
if ( ! ( V_27 -> V_551 & V_552 ) ) {
F_35 ( V_29 , L_70 ) ;
return - ( 0x10000 | V_553 | ( V_552 << 8 ) ) ;
}
if ( V_10 -> V_383 . V_533 == V_506 && V_543 == V_506 ) {
F_45 ( V_29 , L_71 ) ;
return - 100 ;
}
if ( V_10 -> V_383 . V_533 == V_506 )
return 1 ;
return - 1 ;
}
switch ( V_547 ) {
case 0 : return 0 ;
case 1 : return 1 ;
case 2 : return - 1 ;
case 3 :
V_293 = F_69 ( V_205 , & V_27 -> V_69 ) ;
return V_293 ? - 1 : 1 ;
}
}
* V_544 = 50 ;
V_505 = V_10 -> V_517 [ V_516 ] & ~ ( ( T_2 ) 1 ) ;
if ( V_509 == V_505 )
return - 1 ;
* V_544 = 51 ;
V_505 = V_10 -> V_517 [ V_540 ] & ~ ( ( T_2 ) 1 ) ;
if ( V_509 == V_505 ) {
if ( V_27 -> V_186 < 96 ?
( V_10 -> V_257 -> V_514 . V_515 [ V_540 ] & ~ ( ( T_2 ) 1 ) ) ==
( V_10 -> V_517 [ V_540 + 1 ] & ~ ( ( T_2 ) 1 ) ) :
V_505 + V_554 == ( V_10 -> V_517 [ V_516 ] & ~ ( ( T_2 ) 1 ) ) ) {
if ( V_27 -> V_186 < 91 )
return - 1091 ;
V_10 -> V_517 [ V_516 ] = V_10 -> V_517 [ V_540 ] ;
V_10 -> V_517 [ V_540 ] = V_10 -> V_517 [ V_540 + 1 ] ;
F_68 ( V_10 , L_72 ) ;
F_256 ( V_10 , L_68 , V_10 -> V_517 , V_10 -> V_517 [ V_518 ] , V_10 -> V_517 [ V_549 ] ) ;
return - 1 ;
}
}
* V_544 = 60 ;
V_509 = V_10 -> V_257 -> V_514 . V_515 [ V_539 ] & ~ ( ( T_2 ) 1 ) ;
for ( V_6 = V_540 ; V_6 <= V_541 ; V_6 ++ ) {
V_505 = V_10 -> V_517 [ V_6 ] & ~ ( ( T_2 ) 1 ) ;
if ( V_509 == V_505 )
return - 2 ;
}
* V_544 = 70 ;
V_509 = V_10 -> V_257 -> V_514 . V_515 [ V_516 ] & ~ ( ( T_2 ) 1 ) ;
V_505 = V_10 -> V_517 [ V_539 ] & ~ ( ( T_2 ) 1 ) ;
if ( V_509 == V_505 )
return 1 ;
* V_544 = 71 ;
V_509 = V_10 -> V_257 -> V_514 . V_515 [ V_540 ] & ~ ( ( T_2 ) 1 ) ;
if ( V_509 == V_505 ) {
if ( V_27 -> V_186 < 96 ?
( V_10 -> V_257 -> V_514 . V_515 [ V_540 + 1 ] & ~ ( ( T_2 ) 1 ) ) ==
( V_10 -> V_517 [ V_540 ] & ~ ( ( T_2 ) 1 ) ) :
V_509 + V_554 == ( V_10 -> V_257 -> V_514 . V_515 [ V_516 ] & ~ ( ( T_2 ) 1 ) ) ) {
if ( V_27 -> V_186 < 91 )
return - 1091 ;
F_260 ( V_10 , V_516 , V_10 -> V_257 -> V_514 . V_515 [ V_540 ] ) ;
F_260 ( V_10 , V_540 , V_10 -> V_257 -> V_514 . V_515 [ V_540 + 1 ] ) ;
F_68 ( V_10 , L_73 ) ;
F_256 ( V_10 , L_65 , V_10 -> V_257 -> V_514 . V_515 ,
V_10 -> V_383 . V_450 >= V_548 ? F_240 ( V_10 ) : 0 , 0 ) ;
return 1 ;
}
}
* V_544 = 80 ;
V_505 = V_10 -> V_517 [ V_539 ] & ~ ( ( T_2 ) 1 ) ;
for ( V_6 = V_540 ; V_6 <= V_541 ; V_6 ++ ) {
V_509 = V_10 -> V_257 -> V_514 . V_515 [ V_6 ] & ~ ( ( T_2 ) 1 ) ;
if ( V_509 == V_505 )
return 2 ;
}
* V_544 = 90 ;
V_509 = V_10 -> V_257 -> V_514 . V_515 [ V_516 ] & ~ ( ( T_2 ) 1 ) ;
V_505 = V_10 -> V_517 [ V_516 ] & ~ ( ( T_2 ) 1 ) ;
if ( V_509 == V_505 && V_509 != ( ( T_2 ) 0 ) )
return 100 ;
* V_544 = 100 ;
for ( V_6 = V_540 ; V_6 <= V_541 ; V_6 ++ ) {
V_509 = V_10 -> V_257 -> V_514 . V_515 [ V_6 ] & ~ ( ( T_2 ) 1 ) ;
for ( V_545 = V_540 ; V_545 <= V_541 ; V_545 ++ ) {
V_505 = V_10 -> V_517 [ V_545 ] & ~ ( ( T_2 ) 1 ) ;
if ( V_509 == V_505 )
return - 100 ;
}
}
return - 1000 ;
}
static enum V_555 F_261 ( struct V_28 * V_29 ,
enum V_542 V_543 ,
enum V_556 V_557 ) __must_hold( T_5 )
{
struct V_9 * V_10 = V_29 -> V_10 ;
enum V_555 V_95 = V_558 ;
enum V_556 V_559 ;
struct V_35 * V_36 ;
int V_531 , V_544 , V_560 , V_561 ;
V_559 = V_10 -> V_383 . V_450 ;
if ( V_559 == V_548 )
V_559 = V_10 -> V_562 . V_450 ;
F_68 ( V_10 , L_74 ) ;
F_20 ( & V_10 -> V_257 -> V_514 . V_563 ) ;
F_256 ( V_10 , L_65 , V_10 -> V_257 -> V_514 . V_515 , V_10 -> V_519 , 0 ) ;
F_256 ( V_10 , L_68 , V_10 -> V_517 ,
V_10 -> V_517 [ V_518 ] , V_10 -> V_517 [ V_549 ] ) ;
V_531 = F_257 ( V_10 , V_543 , & V_544 ) ;
F_21 ( & V_10 -> V_257 -> V_514 . V_563 ) ;
F_68 ( V_10 , L_75 , V_531 , V_544 ) ;
if ( V_531 == - 1000 ) {
F_227 ( V_10 , L_76 ) ;
return V_558 ;
}
if ( V_531 < - 0x10000 ) {
int V_564 , V_565 ;
V_531 = - V_531 ;
V_564 = V_531 & 0xff ;
V_565 = ( V_531 >> 8 ) & 0xff ;
F_227 ( V_10 , L_77 ,
V_564 , V_565 ) ;
return V_558 ;
}
if ( V_531 < - 1000 ) {
F_227 ( V_10 , L_78 , - V_531 - 1000 ) ;
return V_558 ;
}
if ( ( V_559 == V_438 && V_557 > V_438 ) ||
( V_557 == V_438 && V_559 > V_438 ) ) {
int V_566 = ( V_531 == - 100 ) || abs ( V_531 ) == 2 ;
V_531 = V_559 > V_438 ? 1 : - 1 ;
if ( V_566 )
V_531 = V_531 * 2 ;
F_68 ( V_10 , L_79 ,
V_531 > 0 ? L_80 : L_81 ) ;
}
if ( abs ( V_531 ) == 100 )
F_254 ( V_10 , L_82 ) ;
F_24 () ;
V_36 = F_32 ( V_29 -> V_27 -> V_35 ) ;
if ( V_531 == 100 || ( V_531 == - 100 && V_36 -> V_567 ) ) {
int V_568 = ( V_10 -> V_383 . V_533 == V_506 )
+ ( V_543 == V_506 ) ;
int V_569 = ( V_531 == - 100 ) ;
switch ( V_568 ) {
case 0 :
V_531 = F_251 ( V_29 ) ;
break;
case 1 :
V_531 = F_252 ( V_29 ) ;
break;
case 2 :
V_531 = F_255 ( V_29 ) ;
break;
}
if ( abs ( V_531 ) < 100 ) {
F_35 ( V_10 , L_83
L_84 ,
V_568 , ( V_531 < 0 ) ? L_68 : L_85 ) ;
if ( V_569 ) {
F_35 ( V_10 , L_86
L_87 ) ;
V_531 = V_531 * 2 ;
}
}
}
if ( V_531 == - 100 ) {
if ( F_69 ( V_223 , & V_10 -> V_69 ) && ! ( V_10 -> V_517 [ V_549 ] & 1 ) )
V_531 = - 1 ;
if ( ! F_69 ( V_223 , & V_10 -> V_69 ) && ( V_10 -> V_517 [ V_549 ] & 1 ) )
V_531 = 1 ;
if ( abs ( V_531 ) < 100 )
F_35 ( V_10 , L_88
L_89 ,
( V_531 < 0 ) ? L_68 : L_85 ) ;
}
V_560 = V_36 -> V_560 ;
V_561 = V_36 -> V_561 ;
F_28 () ;
if ( V_531 == - 100 ) {
F_227 ( V_10 , L_90 ) ;
F_254 ( V_10 , L_91 ) ;
return V_558 ;
}
if ( V_531 > 0 && V_559 <= V_438 ) {
F_45 ( V_10 , L_92 ) ;
return V_558 ;
}
if ( V_531 < 0 &&
V_10 -> V_383 . V_533 == V_506 && V_10 -> V_383 . V_450 >= V_570 ) {
switch ( V_560 ) {
case V_522 :
F_254 ( V_10 , L_93 ) ;
case V_524 :
F_45 ( V_10 , L_94 ) ;
return V_558 ;
case V_523 :
F_35 ( V_10 , L_95
L_96 ) ;
}
}
if ( V_561 || F_69 ( V_571 , & V_29 -> V_27 -> V_69 ) ) {
if ( V_531 == 0 )
F_68 ( V_10 , L_97 ) ;
else
F_68 ( V_10 , L_98 ,
F_262 ( V_531 > 0 ? V_384 : V_436 ) ,
abs ( V_531 ) >= 2 ? L_99 : L_100 ) ;
return V_558 ;
}
if ( abs ( V_531 ) >= 2 ) {
F_68 ( V_10 , L_101 ) ;
if ( F_263 ( V_10 , & V_572 , L_102 ,
V_573 ) )
return V_558 ;
}
if ( V_531 > 0 ) {
V_95 = V_574 ;
} else if ( V_531 < 0 ) {
V_95 = V_575 ;
} else {
V_95 = V_576 ;
if ( F_240 ( V_10 ) ) {
F_68 ( V_10 , L_103 ,
F_240 ( V_10 ) ) ;
}
}
return V_95 ;
}
static enum V_512 F_264 ( enum V_512 V_505 )
{
if ( V_505 == V_530 )
return V_529 ;
if ( V_505 == V_529 )
return V_530 ;
return V_505 ;
}
static int F_265 ( struct V_26 * V_27 , struct V_171 * V_172 )
{
struct V_577 * V_323 = V_172 -> V_96 ;
enum V_512 V_578 , V_579 , V_580 ;
int V_581 , V_582 , V_583 , V_584 ;
struct V_35 * V_36 , * V_585 , * V_586 = NULL ;
char V_587 [ V_588 ] = L_104 ;
struct V_325 * V_341 = NULL ;
void * V_333 = NULL , * V_335 = NULL ;
V_581 = F_125 ( V_323 -> V_589 ) ;
V_578 = F_125 ( V_323 -> V_513 ) ;
V_579 = F_125 ( V_323 -> V_532 ) ;
V_580 = F_125 ( V_323 -> V_536 ) ;
V_583 = F_125 ( V_323 -> V_405 ) ;
V_584 = F_125 ( V_323 -> V_590 ) ;
V_582 = V_584 & V_591 ;
if ( V_27 -> V_186 >= 87 ) {
int V_77 ;
if ( V_172 -> V_64 > sizeof( V_587 ) )
return - V_108 ;
V_77 = F_73 ( V_27 , V_587 , V_172 -> V_64 ) ;
if ( V_77 )
return V_77 ;
V_587 [ V_588 - 1 ] = 0 ;
}
if ( V_172 -> V_169 != V_592 ) {
F_106 ( V_571 , & V_27 -> V_69 ) ;
if ( V_584 & V_593 )
F_111 ( V_571 , & V_27 -> V_69 ) ;
F_24 () ;
V_36 = F_32 ( V_27 -> V_35 ) ;
if ( V_581 != V_36 -> V_429 ) {
F_45 ( V_27 , L_105 , L_106 ) ;
goto V_594;
}
if ( F_264 ( V_578 ) != V_36 -> V_513 ) {
F_45 ( V_27 , L_105 , L_107 ) ;
goto V_594;
}
if ( F_264 ( V_579 ) != V_36 -> V_532 ) {
F_45 ( V_27 , L_105 , L_108 ) ;
goto V_594;
}
if ( F_264 ( V_580 ) != V_36 -> V_536 ) {
F_45 ( V_27 , L_105 , L_109 ) ;
goto V_594;
}
if ( V_582 && V_36 -> V_195 ) {
F_45 ( V_27 , L_105 , L_110 ) ;
goto V_594;
}
if ( V_583 != V_36 -> V_405 ) {
F_45 ( V_27 , L_105 , L_111 ) ;
goto V_594;
}
if ( strcmp ( V_587 , V_36 -> V_587 ) ) {
F_45 ( V_27 , L_105 , L_112 ) ;
goto V_594;
}
F_28 () ;
}
if ( V_587 [ 0 ] ) {
int V_595 ;
V_341 = F_266 ( V_587 , 0 , V_596 ) ;
if ( F_267 ( V_341 ) ) {
V_341 = NULL ;
F_45 ( V_27 , L_113 ,
V_587 ) ;
goto V_597;
}
V_595 = F_176 ( V_341 ) ;
V_333 = F_140 ( V_595 , V_598 ) ;
V_335 = F_140 ( V_595 , V_598 ) ;
if ( ! ( V_333 && V_335 ) ) {
F_45 ( V_27 , L_114 ) ;
goto V_597;
}
}
V_586 = F_140 ( sizeof( struct V_35 ) , V_598 ) ;
if ( ! V_586 ) {
F_45 ( V_27 , L_115 ) ;
goto V_597;
}
F_119 ( & V_27 -> V_96 . V_200 ) ;
F_119 ( & V_27 -> V_24 -> V_228 ) ;
V_585 = V_27 -> V_35 ;
* V_586 = * V_585 ;
V_586 -> V_429 = V_581 ;
V_586 -> V_513 = F_264 ( V_578 ) ;
V_586 -> V_532 = F_264 ( V_579 ) ;
V_586 -> V_536 = F_264 ( V_580 ) ;
V_586 -> V_405 = V_583 ;
F_268 ( V_27 -> V_35 , V_586 ) ;
F_120 ( & V_27 -> V_24 -> V_228 ) ;
F_120 ( & V_27 -> V_96 . V_200 ) ;
F_269 ( V_27 -> V_341 ) ;
F_52 ( V_27 -> V_333 ) ;
F_52 ( V_27 -> V_335 ) ;
V_27 -> V_341 = V_341 ;
V_27 -> V_333 = V_333 ;
V_27 -> V_335 = V_335 ;
if ( strcmp ( V_585 -> V_587 , V_587 ) )
F_68 ( V_27 , L_116 ,
V_587 [ 0 ] ? V_587 : L_117 ) ;
F_270 () ;
F_52 ( V_585 ) ;
return 0 ;
V_594:
F_28 () ;
V_597:
F_269 ( V_341 ) ;
F_52 ( V_333 ) ;
F_52 ( V_335 ) ;
F_71 ( V_27 , F_72 ( V_105 , V_151 ) , V_107 ) ;
return - V_108 ;
}
static struct V_325 * F_271 ( const struct V_9 * V_10 ,
const char * V_599 , const char * V_227 )
{
struct V_325 * V_600 ;
if ( ! V_599 [ 0 ] )
return NULL ;
V_600 = F_266 ( V_599 , 0 , V_596 ) ;
if ( F_267 ( V_600 ) ) {
F_45 ( V_10 , L_118 ,
V_599 , V_227 , F_272 ( V_600 ) ) ;
return V_600 ;
}
return V_600 ;
}
static int F_273 ( struct V_26 * V_27 , struct V_171 * V_172 )
{
void * V_245 = V_27 -> V_96 . V_173 ;
int V_64 = V_172 -> V_64 ;
while ( V_64 ) {
int V_203 = F_77 ( int , V_64 , V_601 ) ;
V_203 = F_67 ( V_27 , V_245 , V_203 ) ;
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
static int F_274 ( struct V_26 * V_27 , struct V_171 * V_172 )
{
F_35 ( V_27 , L_119 ,
F_275 ( V_172 -> V_169 ) , V_172 -> V_30 ) ;
return F_273 ( V_27 , V_172 ) ;
}
static int F_276 ( struct V_26 * V_27 , struct V_171 * V_172 )
{
struct V_28 * V_29 ;
struct V_9 * V_10 ;
struct V_602 * V_323 ;
unsigned int V_170 , V_307 , V_603 ;
struct V_325 * V_604 = NULL ;
struct V_325 * V_605 = NULL ;
struct V_35 * V_585 , * V_586 = NULL ;
struct V_292 * V_606 = NULL , * V_607 = NULL ;
const int V_608 = V_27 -> V_186 ;
struct V_609 * V_610 = NULL , * V_611 = NULL ;
int V_612 = 0 ;
int V_77 ;
V_29 = F_199 ( V_27 , V_172 -> V_30 ) ;
if ( ! V_29 )
return F_274 ( V_27 , V_172 ) ;
V_10 = V_29 -> V_10 ;
V_603 = V_608 <= 87 ? sizeof( struct V_613 )
: V_608 == 88 ? sizeof( struct V_613 )
+ V_588
: V_608 <= 94 ? sizeof( struct V_614 )
: sizeof( struct V_602 ) ;
if ( V_172 -> V_64 > V_603 ) {
F_45 ( V_10 , L_120 ,
V_172 -> V_64 , V_603 ) ;
return - V_108 ;
}
if ( V_608 <= 88 ) {
V_170 = sizeof( struct V_613 ) ;
V_307 = V_172 -> V_64 - V_170 ;
} else if ( V_608 <= 94 ) {
V_170 = sizeof( struct V_614 ) ;
V_307 = V_172 -> V_64 - V_170 ;
F_53 ( V_10 , V_307 == 0 ) ;
} else {
V_170 = sizeof( struct V_602 ) ;
V_307 = V_172 -> V_64 - V_170 ;
F_53 ( V_10 , V_307 == 0 ) ;
}
V_323 = V_172 -> V_96 ;
memset ( V_323 -> V_615 , 0 , 2 * V_588 ) ;
V_77 = F_73 ( V_29 -> V_27 , V_323 , V_170 ) ;
if ( V_77 )
return V_77 ;
F_119 ( & V_27 -> V_24 -> V_228 ) ;
V_585 = V_29 -> V_27 -> V_35 ;
if ( F_146 ( V_10 ) ) {
V_607 = F_277 ( sizeof( struct V_292 ) , V_598 ) ;
if ( ! V_607 ) {
F_136 ( V_10 ) ;
F_120 ( & V_27 -> V_24 -> V_228 ) ;
F_45 ( V_10 , L_121 ) ;
return - V_256 ;
}
V_606 = V_10 -> V_257 -> V_292 ;
* V_607 = * V_606 ;
V_607 -> V_616 = F_125 ( V_323 -> V_616 ) ;
}
if ( V_608 >= 88 ) {
if ( V_608 == 88 ) {
if ( V_307 > V_588 || V_307 == 0 ) {
F_45 ( V_10 , L_122
L_123 ,
V_307 , V_588 ) ;
V_77 = - V_108 ;
goto V_617;
}
V_77 = F_73 ( V_29 -> V_27 , V_323 -> V_615 , V_307 ) ;
if ( V_77 )
goto V_617;
F_53 ( V_10 , V_323 -> V_615 [ V_307 - 1 ] == 0 ) ;
V_323 -> V_615 [ V_307 - 1 ] = 0 ;
} else {
F_53 ( V_10 , V_323 -> V_615 [ V_588 - 1 ] == 0 ) ;
F_53 ( V_10 , V_323 -> V_618 [ V_588 - 1 ] == 0 ) ;
V_323 -> V_615 [ V_588 - 1 ] = 0 ;
V_323 -> V_618 [ V_588 - 1 ] = 0 ;
}
if ( strcmp ( V_585 -> V_615 , V_323 -> V_615 ) ) {
if ( V_10 -> V_383 . V_105 == V_103 ) {
F_45 ( V_10 , L_124 ,
V_585 -> V_615 , V_323 -> V_615 ) ;
goto V_597;
}
V_604 = F_271 ( V_10 ,
V_323 -> V_615 , L_125 ) ;
if ( F_267 ( V_604 ) ) {
V_604 = NULL ;
goto V_597;
}
}
if ( V_608 >= 89 && strcmp ( V_585 -> V_618 , V_323 -> V_618 ) ) {
if ( V_10 -> V_383 . V_105 == V_103 ) {
F_45 ( V_10 , L_126 ,
V_585 -> V_618 , V_323 -> V_618 ) ;
goto V_597;
}
V_605 = F_271 ( V_10 ,
V_323 -> V_618 , L_127 ) ;
if ( F_267 ( V_605 ) ) {
V_605 = NULL ;
goto V_597;
}
}
if ( V_608 > 94 && V_607 ) {
V_607 -> V_619 = F_125 ( V_323 -> V_619 ) ;
V_607 -> V_620 = F_125 ( V_323 -> V_620 ) ;
V_607 -> V_621 = F_125 ( V_323 -> V_621 ) ;
V_607 -> V_622 = F_125 ( V_323 -> V_622 ) ;
V_612 = ( V_607 -> V_619 * 10 * V_623 ) / V_44 ;
if ( V_612 != V_10 -> V_624 -> V_64 ) {
V_611 = F_278 ( V_612 ) ;
if ( ! V_611 ) {
F_45 ( V_10 , L_128 ) ;
F_136 ( V_10 ) ;
goto V_597;
}
}
}
if ( V_604 || V_605 ) {
V_586 = F_277 ( sizeof( struct V_35 ) , V_598 ) ;
if ( ! V_586 ) {
F_45 ( V_10 , L_115 ) ;
goto V_597;
}
* V_586 = * V_585 ;
if ( V_604 ) {
strcpy ( V_586 -> V_615 , V_323 -> V_615 ) ;
V_586 -> V_625 = strlen ( V_323 -> V_615 ) + 1 ;
F_269 ( V_29 -> V_27 -> V_604 ) ;
V_29 -> V_27 -> V_604 = V_604 ;
F_68 ( V_10 , L_129 , V_323 -> V_615 ) ;
}
if ( V_605 ) {
strcpy ( V_586 -> V_618 , V_323 -> V_618 ) ;
V_586 -> V_626 = strlen ( V_323 -> V_618 ) + 1 ;
F_269 ( V_29 -> V_27 -> V_605 ) ;
V_29 -> V_27 -> V_605 = V_605 ;
F_68 ( V_10 , L_130 , V_323 -> V_618 ) ;
}
F_268 ( V_27 -> V_35 , V_586 ) ;
}
}
if ( V_607 ) {
F_268 ( V_10 -> V_257 -> V_292 , V_607 ) ;
F_136 ( V_10 ) ;
}
if ( V_611 ) {
V_610 = V_10 -> V_624 ;
F_268 ( V_10 -> V_624 , V_611 ) ;
}
F_120 ( & V_27 -> V_24 -> V_228 ) ;
F_270 () ;
if ( V_586 )
F_52 ( V_585 ) ;
F_52 ( V_606 ) ;
F_52 ( V_610 ) ;
return 0 ;
V_617:
if ( V_607 ) {
F_136 ( V_10 ) ;
F_52 ( V_607 ) ;
}
F_120 ( & V_27 -> V_24 -> V_228 ) ;
return - V_108 ;
V_597:
F_52 ( V_611 ) ;
if ( V_607 ) {
F_136 ( V_10 ) ;
F_52 ( V_607 ) ;
}
F_120 ( & V_27 -> V_24 -> V_228 ) ;
F_269 ( V_605 ) ;
F_269 ( V_604 ) ;
F_71 ( V_29 -> V_27 , F_72 ( V_105 , V_151 ) , V_107 ) ;
return - V_108 ;
}
static void F_279 ( struct V_9 * V_10 ,
const char * V_203 , T_3 V_47 , T_3 V_393 )
{
T_3 V_327 ;
if ( V_47 == 0 || V_393 == 0 )
return;
V_327 = ( V_47 > V_393 ) ? ( V_47 - V_393 ) : ( V_393 - V_47 ) ;
if ( V_327 > ( V_47 >> 3 ) || V_327 > ( V_393 >> 3 ) )
F_35 ( V_10 , L_131 , V_203 ,
( unsigned long long ) V_47 , ( unsigned long long ) V_393 ) ;
}
static int F_280 ( struct V_26 * V_27 , struct V_171 * V_172 )
{
struct V_28 * V_29 ;
struct V_9 * V_10 ;
struct V_627 * V_323 = V_172 -> V_96 ;
struct V_628 * V_629 = ( V_27 -> V_551 & V_552 ) ? V_323 -> V_630 : NULL ;
enum V_631 V_632 = V_633 ;
T_3 V_634 , V_635 , V_636 , V_637 ;
int V_638 = 0 ;
enum V_639 V_640 ;
V_29 = F_199 ( V_27 , V_172 -> V_30 ) ;
if ( ! V_29 )
return F_274 ( V_27 , V_172 ) ;
V_10 = V_29 -> V_10 ;
V_634 = F_200 ( V_323 -> V_641 ) ;
V_635 = F_200 ( V_323 -> V_642 ) ;
V_636 = F_200 ( V_323 -> V_643 ) ;
V_10 -> V_634 = V_634 ;
if ( F_146 ( V_10 ) ) {
T_3 V_644 , V_645 ;
F_24 () ;
V_637 = F_32 ( V_10 -> V_257 -> V_292 ) -> V_646 ;
F_28 () ;
F_279 ( V_10 , L_132 ,
V_634 , F_281 ( V_10 -> V_257 ) ) ;
F_279 ( V_10 , L_133 ,
V_635 , V_637 ) ;
if ( V_10 -> V_383 . V_105 == V_103 )
V_635 = F_282 ( V_637 , V_635 ) ;
V_644 = F_283 ( V_10 , V_10 -> V_257 , V_635 , 0 ) ;
V_645 = F_175 ( V_10 -> V_329 ) ;
if ( V_644 < V_645 &&
V_10 -> V_383 . V_450 >= V_647 &&
V_10 -> V_383 . V_105 < V_576 ) {
F_45 ( V_10 , L_134 ,
( unsigned long long ) V_644 , ( unsigned long long ) V_645 ) ;
F_71 ( V_29 -> V_27 , F_72 ( V_105 , V_151 ) , V_107 ) ;
F_136 ( V_10 ) ;
return - V_108 ;
}
if ( V_637 != V_635 ) {
struct V_292 * V_606 , * V_607 = NULL ;
V_607 = F_277 ( sizeof( struct V_292 ) , V_598 ) ;
if ( ! V_607 ) {
F_45 ( V_10 , L_121 ) ;
F_136 ( V_10 ) ;
return - V_256 ;
}
F_119 ( & V_27 -> V_24 -> V_228 ) ;
V_606 = V_10 -> V_257 -> V_292 ;
* V_607 = * V_606 ;
V_607 -> V_646 = V_635 ;
F_268 ( V_10 -> V_257 -> V_292 , V_607 ) ;
F_120 ( & V_27 -> V_24 -> V_228 ) ;
F_270 () ;
F_52 ( V_606 ) ;
F_68 ( V_10 , L_135 ,
( unsigned long ) V_637 ) ;
}
F_136 ( V_10 ) ;
}
V_10 -> V_648 = F_125 ( V_323 -> V_649 ) ;
V_640 = F_124 ( V_323 -> V_639 ) ;
if ( F_146 ( V_10 ) ) {
F_284 ( V_10 , V_10 -> V_257 , V_629 ) ;
V_632 = F_285 ( V_10 , V_640 , NULL ) ;
F_136 ( V_10 ) ;
if ( V_632 == V_650 )
return - V_108 ;
F_286 ( V_10 ) ;
} else {
F_284 ( V_10 , NULL , V_629 ) ;
F_287 ( V_10 , V_636 ? : V_635 ? : V_634 ) ;
}
if ( F_146 ( V_10 ) ) {
if ( V_10 -> V_257 -> V_651 != F_175 ( V_10 -> V_257 -> V_258 ) ) {
V_10 -> V_257 -> V_651 = F_175 ( V_10 -> V_257 -> V_258 ) ;
V_638 = 1 ;
}
F_136 ( V_10 ) ;
}
if ( V_10 -> V_383 . V_105 > V_103 ) {
if ( F_200 ( V_323 -> V_643 ) !=
F_175 ( V_10 -> V_329 ) || V_638 ) {
F_103 ( V_29 , 0 , V_640 ) ;
}
if ( F_288 ( V_190 , & V_10 -> V_69 ) ||
( V_632 == V_652 && V_10 -> V_383 . V_105 == V_576 ) ) {
if ( V_10 -> V_383 . V_437 >= V_438 &&
V_10 -> V_383 . V_450 >= V_438 ) {
if ( V_640 & V_653 )
F_68 ( V_10 , L_136 ) ;
else
F_289 ( V_10 ) ;
} else
F_111 ( V_654 , & V_10 -> V_69 ) ;
}
}
return 0 ;
}
static int F_290 ( struct V_26 * V_27 , struct V_171 * V_172 )
{
struct V_28 * V_29 ;
struct V_9 * V_10 ;
struct V_655 * V_323 = V_172 -> V_96 ;
T_2 * V_517 ;
int V_6 , V_656 = 0 ;
V_29 = F_199 ( V_27 , V_172 -> V_30 ) ;
if ( ! V_29 )
return F_274 ( V_27 , V_172 ) ;
V_10 = V_29 -> V_10 ;
V_517 = F_291 ( V_657 , sizeof( * V_517 ) , V_213 ) ;
if ( ! V_517 ) {
F_45 ( V_10 , L_137 ) ;
return false ;
}
for ( V_6 = V_539 ; V_6 < V_657 ; V_6 ++ )
V_517 [ V_6 ] = F_200 ( V_323 -> V_515 [ V_6 ] ) ;
F_52 ( V_10 -> V_517 ) ;
V_10 -> V_517 = V_517 ;
if ( V_10 -> V_383 . V_105 < V_576 &&
V_10 -> V_383 . V_450 < V_438 &&
V_10 -> V_383 . V_533 == V_506 &&
( V_10 -> V_658 & ~ ( ( T_2 ) 1 ) ) != ( V_517 [ V_539 ] & ~ ( ( T_2 ) 1 ) ) ) {
F_45 ( V_10 , L_138 ,
( unsigned long long ) V_10 -> V_658 ) ;
F_71 ( V_29 -> V_27 , F_72 ( V_105 , V_151 ) , V_107 ) ;
return - V_108 ;
}
if ( F_146 ( V_10 ) ) {
int V_659 =
V_10 -> V_383 . V_105 == V_576 &&
V_29 -> V_27 -> V_186 >= 90 &&
V_10 -> V_257 -> V_514 . V_515 [ V_539 ] == V_546 &&
( V_517 [ V_549 ] & 8 ) ;
if ( V_659 ) {
F_68 ( V_10 , L_139 ) ;
F_263 ( V_10 , & V_660 ,
L_140 ,
V_661 ) ;
F_292 ( V_10 , V_539 , V_517 [ V_539 ] ) ;
F_292 ( V_10 , V_516 , 0 ) ;
F_293 ( F_294 ( V_10 , V_450 , V_476 , V_437 , V_476 ) ,
V_198 , NULL ) ;
F_286 ( V_10 ) ;
V_656 = 1 ;
}
F_136 ( V_10 ) ;
} else if ( V_10 -> V_383 . V_450 < V_438 &&
V_10 -> V_383 . V_533 == V_506 ) {
V_656 = F_295 ( V_10 , V_517 [ V_539 ] ) ;
}
F_119 ( V_10 -> V_185 ) ;
F_120 ( V_10 -> V_185 ) ;
if ( V_10 -> V_383 . V_105 >= V_576 && V_10 -> V_383 . V_450 < V_438 )
V_656 |= F_295 ( V_10 , V_517 [ V_539 ] ) ;
if ( V_656 )
F_296 ( V_10 , L_141 ) ;
return 0 ;
}
static union V_662 F_297 ( union V_662 V_663 )
{
union V_662 V_664 ;
static enum V_555 V_665 [] = {
[ V_103 ] = V_103 ,
[ V_576 ] = V_576 ,
[ V_666 ] = V_667 ,
[ V_667 ] = V_666 ,
[ V_151 ] = V_668 ,
[ V_465 ] = V_466 ,
[ V_558 ] = V_558 ,
} ;
V_664 . V_6 = V_663 . V_6 ;
V_664 . V_105 = V_665 [ V_663 . V_105 ] ;
V_664 . V_505 = V_663 . V_533 ;
V_664 . V_533 = V_663 . V_505 ;
V_664 . V_437 = V_663 . V_450 ;
V_664 . V_450 = V_663 . V_437 ;
V_664 . V_669 = ( V_663 . V_670 | V_663 . V_671 ) ;
return V_664 ;
}
static int F_298 ( struct V_26 * V_27 , struct V_171 * V_172 )
{
struct V_28 * V_29 ;
struct V_9 * V_10 ;
struct V_672 * V_323 = V_172 -> V_96 ;
union V_662 V_673 , V_674 ;
enum V_196 V_95 ;
V_29 = F_199 ( V_27 , V_172 -> V_30 ) ;
if ( ! V_29 )
return - V_108 ;
V_10 = V_29 -> V_10 ;
V_673 . V_6 = F_125 ( V_323 -> V_673 ) ;
V_674 . V_6 = F_125 ( V_323 -> V_674 ) ;
if ( F_69 ( V_205 , & V_29 -> V_27 -> V_69 ) &&
F_299 ( V_10 -> V_185 ) ) {
F_300 ( V_29 , V_675 ) ;
return 0 ;
}
V_673 = F_297 ( V_673 ) ;
V_674 = F_297 ( V_674 ) ;
V_95 = F_253 ( V_10 , V_198 , V_673 , V_674 ) ;
F_300 ( V_29 , V_95 ) ;
F_286 ( V_10 ) ;
return 0 ;
}
static int F_301 ( struct V_26 * V_27 , struct V_171 * V_172 )
{
struct V_672 * V_323 = V_172 -> V_96 ;
union V_662 V_673 , V_674 ;
enum V_196 V_95 ;
V_673 . V_6 = F_125 ( V_323 -> V_673 ) ;
V_674 . V_6 = F_125 ( V_323 -> V_674 ) ;
if ( F_69 ( V_205 , & V_27 -> V_69 ) &&
F_299 ( & V_27 -> V_187 ) ) {
F_302 ( V_27 , V_675 ) ;
return 0 ;
}
V_673 = F_297 ( V_673 ) ;
V_674 = F_297 ( V_674 ) ;
V_95 = F_71 ( V_27 , V_673 , V_674 , V_198 | V_676 | V_677 ) ;
F_302 ( V_27 , V_95 ) ;
return 0 ;
}
static int F_303 ( struct V_26 * V_27 , struct V_171 * V_172 )
{
struct V_28 * V_29 ;
struct V_9 * V_10 ;
struct V_678 * V_323 = V_172 -> V_96 ;
union V_662 V_679 , V_680 , V_681 ;
enum V_556 V_682 ;
enum V_683 V_684 ;
int V_95 ;
V_29 = F_199 ( V_27 , V_172 -> V_30 ) ;
if ( ! V_29 )
return F_274 ( V_27 , V_172 ) ;
V_10 = V_29 -> V_10 ;
V_681 . V_6 = F_125 ( V_323 -> V_383 ) ;
V_682 = V_681 . V_450 ;
if ( V_681 . V_450 == V_548 ) {
V_682 = V_10 -> V_517 [ V_549 ] & 4 ? V_438 : V_570 ;
F_68 ( V_10 , L_142 , F_304 ( V_682 ) ) ;
}
F_20 ( & V_10 -> V_24 -> V_25 ) ;
V_34:
V_679 = V_680 = F_305 ( V_10 ) ;
F_21 ( & V_10 -> V_24 -> V_25 ) ;
if ( V_679 . V_105 <= V_668 )
return - V_97 ;
if ( ( V_679 . V_437 == V_438 || V_679 . V_437 == V_570 ) &&
V_682 == V_476 &&
V_679 . V_105 > V_576 && V_679 . V_450 == V_476 ) {
if ( V_681 . V_105 > V_576 &&
V_681 . V_105 < V_384 )
V_682 = V_438 ;
else if ( V_679 . V_105 >= V_384 &&
V_681 . V_105 == V_576 ) {
if ( F_240 ( V_10 ) <= V_10 -> V_468 )
F_306 ( V_10 ) ;
return 0 ;
}
}
if ( V_679 . V_105 == V_466 && V_679 . V_450 == V_476 &&
V_681 . V_105 == V_576 && V_682 == V_476 ) {
F_307 ( V_10 ) ;
F_306 ( V_10 ) ;
return 0 ;
}
if ( V_679 . V_437 == V_476 && V_682 == V_438 &&
V_679 . V_105 == V_576 && V_681 . V_105 > V_384 )
V_682 = V_476 ;
if ( V_680 . V_105 == V_103 )
V_680 . V_105 = V_576 ;
if ( V_681 . V_105 == V_685 )
V_680 . V_105 = V_686 ;
if ( V_10 -> V_517 && V_681 . V_450 >= V_548 &&
F_243 ( V_10 , V_548 ) ) {
int V_687 ;
V_687 = ( V_679 . V_105 < V_576 ) ;
V_687 |= ( V_679 . V_105 == V_576 &&
( V_681 . V_450 == V_548 ||
V_679 . V_450 == V_548 ) ) ;
V_687 |= F_69 ( V_688 , & V_10 -> V_69 ) ;
V_687 |= ( V_679 . V_105 == V_576 &&
( V_681 . V_105 >= V_666 &&
V_681 . V_105 <= V_575 ) ) ;
if ( V_687 )
V_680 . V_105 = F_261 ( V_29 , V_681 . V_533 , V_682 ) ;
F_136 ( V_10 ) ;
if ( V_680 . V_105 == V_558 ) {
V_680 . V_105 = V_576 ;
if ( V_10 -> V_383 . V_450 == V_548 ) {
F_308 ( V_10 , F_72 ( V_450 , V_689 ) ) ;
} else if ( V_681 . V_450 == V_548 ) {
F_45 ( V_10 , L_143 ) ;
V_681 . V_450 = V_690 ;
V_682 = V_690 ;
} else {
if ( F_288 ( V_571 , & V_29 -> V_27 -> V_69 ) )
return - V_108 ;
F_53 ( V_10 , V_679 . V_105 == V_103 ) ;
F_71 ( V_29 -> V_27 , F_72 ( V_105 , V_151 ) , V_107 ) ;
return - V_108 ;
}
}
}
F_20 ( & V_10 -> V_24 -> V_25 ) ;
if ( V_679 . V_6 != F_305 ( V_10 ) . V_6 )
goto V_34;
F_106 ( V_688 , & V_10 -> V_69 ) ;
V_680 . V_505 = V_681 . V_533 ;
V_680 . V_437 = V_682 ;
V_680 . V_669 = ( V_681 . V_670 | V_681 . V_671 ) ;
if ( ( V_680 . V_105 == V_576 || V_680 . V_105 == V_574 ) && V_680 . V_450 == V_548 )
V_680 . V_450 = V_10 -> V_562 . V_450 ;
V_684 = V_198 + ( V_679 . V_105 < V_576 && V_680 . V_105 >= V_576 ? 0 : V_107 ) ;
if ( V_680 . V_437 == V_570 && F_309 ( V_10 ) && V_680 . V_105 == V_576 && V_679 . V_105 < V_576 &&
F_69 ( V_691 , & V_10 -> V_69 ) ) {
F_21 ( & V_10 -> V_24 -> V_25 ) ;
F_45 ( V_10 , L_144 ) ;
F_310 ( V_29 -> V_27 ) ;
F_311 ( V_10 ) ;
F_106 ( V_691 , & V_10 -> V_69 ) ;
F_71 ( V_29 -> V_27 , F_312 ( V_105 , V_692 , V_693 , 0 ) , V_107 ) ;
return - V_108 ;
}
V_95 = F_293 ( V_10 , V_680 , V_684 , NULL ) ;
V_680 = F_305 ( V_10 ) ;
F_21 ( & V_10 -> V_24 -> V_25 ) ;
if ( V_95 < V_199 ) {
F_71 ( V_29 -> V_27 , F_72 ( V_105 , V_151 ) , V_107 ) ;
return - V_108 ;
}
if ( V_679 . V_105 > V_103 ) {
if ( V_680 . V_105 > V_576 && V_681 . V_105 <= V_576 &&
V_681 . V_450 != V_548 ) {
F_104 ( V_29 ) ;
F_105 ( V_29 ) ;
}
}
F_106 ( V_223 , & V_10 -> V_69 ) ;
F_286 ( V_10 ) ;
return 0 ;
}
static int F_313 ( struct V_26 * V_27 , struct V_171 * V_172 )
{
struct V_28 * V_29 ;
struct V_9 * V_10 ;
struct V_694 * V_323 = V_172 -> V_96 ;
V_29 = F_199 ( V_27 , V_172 -> V_30 ) ;
if ( ! V_29 )
return - V_108 ;
V_10 = V_29 -> V_10 ;
F_231 ( V_10 -> V_321 ,
V_10 -> V_383 . V_105 == V_695 ||
V_10 -> V_383 . V_105 == V_686 ||
V_10 -> V_383 . V_105 < V_576 ||
V_10 -> V_383 . V_450 < V_548 ) ;
if ( F_243 ( V_10 , V_548 ) ) {
F_292 ( V_10 , V_539 , F_200 ( V_323 -> V_515 ) ) ;
F_292 ( V_10 , V_516 , 0UL ) ;
F_296 ( V_10 , L_145 ) ;
F_314 ( V_10 , V_436 ) ;
F_136 ( V_10 ) ;
} else
F_45 ( V_10 , L_146 ) ;
return 0 ;
}
static int
F_315 ( struct V_28 * V_29 , unsigned int V_64 ,
unsigned long * V_323 , struct V_696 * V_697 )
{
unsigned int V_307 = V_601 -
F_95 ( V_29 -> V_27 ) ;
unsigned int V_698 = F_77 ( T_6 , V_307 / sizeof( * V_323 ) ,
V_697 -> V_699 - V_697 -> V_700 ) ;
unsigned int V_701 = V_698 * sizeof( * V_323 ) ;
int V_77 ;
if ( V_701 != V_64 ) {
F_45 ( V_29 , L_147 , V_62 , V_701 , V_64 ) ;
return - V_108 ;
}
if ( V_701 == 0 )
return 0 ;
V_77 = F_73 ( V_29 -> V_27 , V_323 , V_701 ) ;
if ( V_77 )
return V_77 ;
F_316 ( V_29 -> V_10 , V_697 -> V_700 , V_698 , V_323 ) ;
V_697 -> V_700 += V_698 ;
V_697 -> V_702 = V_697 -> V_700 * V_703 ;
if ( V_697 -> V_702 > V_697 -> V_704 )
V_697 -> V_702 = V_697 -> V_704 ;
return 1 ;
}
static enum V_705 F_317 ( struct V_706 * V_323 )
{
return (enum V_705 ) ( V_323 -> V_707 & 0x0f ) ;
}
static int F_318 ( struct V_706 * V_323 )
{
return ( V_323 -> V_707 & 0x80 ) != 0 ;
}
static int F_319 ( struct V_706 * V_323 )
{
return ( V_323 -> V_707 >> 4 ) & 0x7 ;
}
static int
F_320 ( struct V_28 * V_29 ,
struct V_706 * V_323 ,
struct V_696 * V_697 ,
unsigned int V_5 )
{
struct V_708 V_709 ;
T_2 V_710 ;
T_2 V_711 ;
T_2 V_4 ;
unsigned long V_203 = V_697 -> V_702 ;
unsigned long V_712 ;
int V_713 = F_318 ( V_323 ) ;
int V_714 ;
int V_538 ;
F_321 ( & V_709 , V_323 -> V_715 , V_5 , F_319 ( V_323 ) ) ;
V_538 = F_322 ( & V_709 , & V_710 , 64 ) ;
if ( V_538 < 0 )
return - V_108 ;
for ( V_714 = V_538 ; V_714 > 0 ; V_203 += V_711 , V_713 = ! V_713 ) {
V_538 = F_323 ( & V_711 , V_710 ) ;
if ( V_538 <= 0 )
return - V_108 ;
if ( V_713 ) {
V_712 = V_203 + V_711 - 1 ;
if ( V_712 >= V_697 -> V_704 ) {
F_45 ( V_29 , L_148 , V_712 ) ;
return - V_108 ;
}
F_324 ( V_29 -> V_10 , V_203 , V_712 ) ;
}
if ( V_714 < V_538 ) {
F_45 ( V_29 , L_149 ,
V_714 , V_538 , V_710 ,
( unsigned int ) ( V_709 . V_716 . V_393 - V_323 -> V_715 ) ,
( unsigned int ) V_709 . V_717 ) ;
return - V_108 ;
}
if ( F_188 ( V_538 < 64 ) )
V_710 >>= V_538 ;
else
V_710 = 0 ;
V_714 -= V_538 ;
V_538 = F_322 ( & V_709 , & V_4 , 64 - V_714 ) ;
if ( V_538 < 0 )
return - V_108 ;
V_710 |= V_4 << V_714 ;
V_714 += V_538 ;
}
V_697 -> V_702 = V_203 ;
F_325 ( V_697 ) ;
return ( V_203 != V_697 -> V_704 ) ;
}
static int
F_326 ( struct V_28 * V_29 ,
struct V_706 * V_323 ,
struct V_696 * V_697 ,
unsigned int V_5 )
{
if ( F_317 ( V_323 ) == V_718 )
return F_320 ( V_29 , V_323 , V_697 , V_5 - sizeof( * V_323 ) ) ;
F_45 ( V_29 , L_150 , V_323 -> V_707 ) ;
F_71 ( V_29 -> V_27 , F_72 ( V_105 , V_692 ) , V_107 ) ;
return - V_108 ;
}
void F_327 ( struct V_9 * V_10 ,
const char * V_719 , struct V_696 * V_697 )
{
unsigned int V_170 = F_95 ( F_258 ( V_10 ) -> V_27 ) ;
unsigned int V_307 = V_601 - V_170 ;
unsigned int V_720 =
V_170 * ( F_328 ( V_697 -> V_699 , V_307 ) + 1 ) +
V_697 -> V_699 * sizeof( unsigned long ) ;
unsigned int V_721 = V_697 -> V_722 [ 0 ] + V_697 -> V_722 [ 1 ] ;
unsigned int V_326 ;
if ( V_721 == 0 )
return;
if ( V_721 >= V_720 )
return;
V_326 = ( V_721 > V_45 / 1000 ) ? ( V_721 / ( V_720 / 1000 ) )
: ( 1000 * V_721 / V_720 ) ;
if ( V_326 > 1000 )
V_326 = 1000 ;
V_326 = 1000 - V_326 ;
F_68 ( V_10 , L_151
L_152 ,
V_719 ,
V_697 -> V_722 [ 1 ] , V_697 -> V_723 [ 1 ] ,
V_697 -> V_722 [ 0 ] , V_697 -> V_723 [ 0 ] ,
V_721 , V_326 / 10 , V_326 % 10 ) ;
}
static int F_329 ( struct V_26 * V_27 , struct V_171 * V_172 )
{
struct V_28 * V_29 ;
struct V_9 * V_10 ;
struct V_696 V_697 ;
int V_77 ;
V_29 = F_199 ( V_27 , V_172 -> V_30 ) ;
if ( ! V_29 )
return - V_108 ;
V_10 = V_29 -> V_10 ;
F_330 ( V_10 , L_153 , V_573 ) ;
V_697 = (struct V_696 ) {
. V_704 = F_248 ( V_10 ) ,
. V_699 = F_331 ( V_10 ) ,
} ;
for(; ; ) {
if ( V_172 -> V_169 == V_724 )
V_77 = F_315 ( V_29 , V_172 -> V_64 , V_172 -> V_96 , & V_697 ) ;
else if ( V_172 -> V_169 == V_725 ) {
struct V_706 * V_323 = V_172 -> V_96 ;
if ( V_172 -> V_64 > V_601 - F_95 ( V_27 ) ) {
F_45 ( V_10 , L_154 ) ;
V_77 = - V_108 ;
goto V_104;
}
if ( V_172 -> V_64 <= sizeof( * V_323 ) ) {
F_45 ( V_10 , L_155 , V_172 -> V_64 ) ;
V_77 = - V_108 ;
goto V_104;
}
V_77 = F_73 ( V_29 -> V_27 , V_323 , V_172 -> V_64 ) ;
if ( V_77 )
goto V_104;
V_77 = F_326 ( V_29 , V_323 , & V_697 , V_172 -> V_64 ) ;
} else {
F_35 ( V_10 , L_156 , V_172 -> V_169 ) ;
V_77 = - V_108 ;
goto V_104;
}
V_697 . V_723 [ V_172 -> V_169 == V_724 ] ++ ;
V_697 . V_722 [ V_172 -> V_169 == V_724 ] += F_95 ( V_27 ) + V_172 -> V_64 ;
if ( V_77 <= 0 ) {
if ( V_77 < 0 )
goto V_104;
break;
}
V_77 = F_130 ( V_29 -> V_27 , V_172 ) ;
if ( V_77 )
goto V_104;
}
F_327 ( V_10 , L_157 , & V_697 ) ;
if ( V_10 -> V_383 . V_105 == V_575 ) {
enum V_196 V_95 ;
V_77 = F_332 ( V_10 ) ;
if ( V_77 )
goto V_104;
V_95 = F_333 ( V_10 , F_72 ( V_105 , V_695 ) , V_198 ) ;
F_53 ( V_10 , V_95 == V_199 ) ;
} else if ( V_10 -> V_383 . V_105 != V_574 ) {
F_68 ( V_10 , L_158 ,
F_262 ( V_10 -> V_383 . V_105 ) ) ;
}
V_77 = 0 ;
V_104:
F_334 ( V_10 ) ;
if ( ! V_77 && V_10 -> V_383 . V_105 == V_574 )
F_314 ( V_10 , V_384 ) ;
return V_77 ;
}
static int F_335 ( struct V_26 * V_27 , struct V_171 * V_172 )
{
F_35 ( V_27 , L_159 ,
V_172 -> V_169 , V_172 -> V_64 ) ;
return F_273 ( V_27 , V_172 ) ;
}
static int F_336 ( struct V_26 * V_27 , struct V_171 * V_172 )
{
F_132 ( V_27 -> V_96 . V_83 ) ;
return 0 ;
}
static int F_337 ( struct V_26 * V_27 , struct V_171 * V_172 )
{
struct V_28 * V_29 ;
struct V_9 * V_10 ;
struct V_726 * V_323 = V_172 -> V_96 ;
V_29 = F_199 ( V_27 , V_172 -> V_30 ) ;
if ( ! V_29 )
return - V_108 ;
V_10 = V_29 -> V_10 ;
switch ( V_10 -> V_383 . V_105 ) {
case V_695 :
case V_575 :
case V_686 :
break;
default:
F_45 ( V_10 , L_160 ,
F_262 ( V_10 -> V_383 . V_105 ) ) ;
}
F_232 ( V_10 , F_200 ( V_323 -> V_52 ) , F_125 ( V_323 -> V_475 ) ) ;
return 0 ;
}
static int F_338 ( struct V_26 * V_27 , struct V_171 * V_172 )
{
struct V_28 * V_29 ;
struct V_726 * V_323 = V_172 -> V_96 ;
struct V_9 * V_10 ;
T_3 V_52 ;
int V_64 , V_77 = 0 ;
V_29 = F_199 ( V_27 , V_172 -> V_30 ) ;
if ( ! V_29 )
return - V_108 ;
V_10 = V_29 -> V_10 ;
V_52 = F_200 ( V_323 -> V_52 ) ;
V_64 = F_125 ( V_323 -> V_475 ) ;
F_194 ( V_10 ) ;
if ( F_146 ( V_10 ) ) {
struct V_18 * V_19 ;
const int V_303 = V_413 ;
V_19 = F_42 ( V_29 , V_362 , V_52 ,
V_64 , 0 , V_213 ) ;
if ( ! V_19 ) {
F_136 ( V_10 ) ;
return - V_256 ;
}
V_19 -> V_20 . V_80 = F_186 ;
V_19 -> V_65 = V_66 ;
V_19 -> V_69 |= V_309 ;
F_20 ( & V_10 -> V_24 -> V_25 ) ;
F_163 ( & V_19 -> V_20 . V_21 , & V_10 -> V_363 ) ;
F_21 ( & V_10 -> V_24 -> V_25 ) ;
F_38 ( V_172 -> V_64 >> 9 , & V_10 -> V_364 ) ;
V_77 = F_161 ( V_10 , V_19 , V_303 , 0 , V_366 ) ;
if ( V_77 ) {
F_20 ( & V_10 -> V_24 -> V_25 ) ;
F_153 ( & V_19 -> V_20 . V_21 ) ;
F_21 ( & V_10 -> V_24 -> V_25 ) ;
F_60 ( V_10 , V_19 ) ;
F_136 ( V_10 ) ;
V_77 = 0 ;
goto V_63;
}
F_195 ( V_10 ) ;
} else {
V_63:
F_339 ( V_10 , V_52 ) ;
F_245 ( V_29 , V_361 , V_52 , V_64 , V_362 ) ;
}
F_38 ( V_64 >> 9 , & V_10 -> V_375 ) ;
return V_77 ;
}
static void F_340 ( struct V_26 * V_27 )
{
struct V_171 V_172 ;
T_6 V_727 ;
int V_77 ;
while ( F_114 ( & V_27 -> V_210 ) == V_728 ) {
struct V_729 const * V_169 ;
F_341 ( & V_27 -> V_210 ) ;
F_249 ( V_27 , F_131 ) ;
if ( F_131 ( V_27 , & V_172 ) )
goto V_730;
V_169 = & V_731 [ V_172 . V_169 ] ;
if ( F_201 ( V_172 . V_169 >= F_342 ( V_731 ) || ! V_169 -> V_732 ) ) {
F_45 ( V_27 , L_161 ,
F_275 ( V_172 . V_169 ) , V_172 . V_169 ) ;
goto V_730;
}
V_727 = V_169 -> V_733 ;
if ( V_172 . V_169 == V_734 && V_27 -> V_551 & V_552 )
V_727 += sizeof( struct V_628 ) ;
if ( V_172 . V_64 > V_727 && ! V_169 -> V_735 ) {
F_45 ( V_27 , L_162 ,
F_275 ( V_172 . V_169 ) , V_172 . V_64 ) ;
goto V_730;
}
if ( V_172 . V_64 < V_727 ) {
F_45 ( V_27 , L_163 ,
F_275 ( V_172 . V_169 ) , ( int ) V_727 , V_172 . V_64 ) ;
goto V_730;
}
if ( V_727 ) {
F_249 ( V_27 , F_74 ) ;
V_77 = F_74 ( V_27 , V_172 . V_96 , V_727 ) ;
if ( V_77 )
goto V_730;
V_172 . V_64 -= V_727 ;
}
F_249 ( V_27 , V_169 -> V_732 ) ;
V_77 = V_169 -> V_732 ( V_27 , & V_172 ) ;
if ( V_77 ) {
F_45 ( V_27 , L_164 ,
F_275 ( V_172 . V_169 ) , V_77 , V_172 . V_64 ) ;
goto V_730;
}
}
return;
V_730:
F_71 ( V_27 , F_72 ( V_105 , V_692 ) , V_107 ) ;
}
static void F_343 ( struct V_26 * V_27 )
{
struct V_28 * V_29 ;
enum V_555 V_736 ;
int V_30 ;
if ( V_27 -> V_102 == V_737 )
return;
F_71 ( V_27 , F_72 ( V_105 , V_738 ) , V_107 ) ;
F_344 ( & V_27 -> V_224 ) ;
if ( V_27 -> V_225 ) {
F_345 ( V_27 -> V_225 ) ;
V_27 -> V_225 = NULL ;
}
F_346 ( V_27 ) ;
F_24 () ;
F_25 (&connection->peer_devices, peer_device, vnr) {
struct V_9 * V_10 = V_29 -> V_10 ;
F_27 ( & V_10 -> V_32 ) ;
F_28 () ;
F_347 ( V_29 ) ;
F_29 ( & V_10 -> V_32 , V_33 ) ;
F_24 () ;
}
F_28 () ;
if ( ! F_62 ( & V_27 -> V_283 -> V_21 ) )
F_45 ( V_27 , L_165 ) ;
F_101 ( & V_27 -> V_283 -> V_272 , 0 ) ;
V_27 -> V_739 . V_740 = false ;
F_68 ( V_27 , L_166 ) ;
if ( F_348 ( V_27 ) == V_506 && F_349 ( V_27 ) >= V_741 )
F_350 ( V_27 ) ;
F_20 ( & V_27 -> V_24 -> V_25 ) ;
V_736 = V_27 -> V_102 ;
if ( V_736 >= V_742 )
F_229 ( V_27 , F_72 ( V_105 , V_742 ) , V_198 ) ;
F_21 ( & V_27 -> V_24 -> V_25 ) ;
if ( V_736 == V_151 )
F_71 ( V_27 , F_72 ( V_105 , V_737 ) , V_198 | V_107 ) ;
}
static int F_347 ( struct V_28 * V_29 )
{
struct V_9 * V_10 = V_29 -> V_10 ;
unsigned int V_6 ;
F_20 ( & V_10 -> V_24 -> V_25 ) ;
F_61 ( V_10 , & V_10 -> V_312 ) ;
F_61 ( V_10 , & V_10 -> V_363 ) ;
F_61 ( V_10 , & V_10 -> V_504 ) ;
F_21 ( & V_10 -> V_24 -> V_25 ) ;
F_351 ( V_10 ) ;
V_10 -> V_502 = 0 ;
V_10 -> V_468 = 0 ;
F_101 ( & V_10 -> V_743 , 0 ) ;
F_41 ( & V_10 -> V_321 ) ;
F_352 ( & V_10 -> V_744 ) ;
F_353 ( ( unsigned long ) V_10 ) ;
F_354 ( & V_29 -> V_27 -> V_745 ) ;
F_59 ( V_10 ) ;
F_354 ( & V_29 -> V_27 -> V_745 ) ;
F_351 ( V_10 ) ;
F_52 ( V_10 -> V_517 ) ;
V_10 -> V_517 = NULL ;
if ( ! F_309 ( V_10 ) )
F_310 ( V_29 -> V_27 ) ;
F_286 ( V_10 ) ;
if ( F_146 ( V_10 ) ) {
F_263 ( V_10 , & V_746 ,
L_167 , V_747 ) ;
F_136 ( V_10 ) ;
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
F_53 ( V_10 , F_62 ( & V_10 -> V_504 ) ) ;
F_53 ( V_10 , F_62 ( & V_10 -> V_312 ) ) ;
F_53 ( V_10 , F_62 ( & V_10 -> V_363 ) ) ;
F_53 ( V_10 , F_62 ( & V_10 -> V_78 ) ) ;
return 0 ;
}
static int F_355 ( struct V_26 * V_27 )
{
struct V_167 * V_84 ;
struct V_748 * V_323 ;
V_84 = & V_27 -> V_96 ;
V_323 = F_92 ( V_27 , V_84 ) ;
if ( ! V_323 )
return - V_108 ;
memset ( V_323 , 0 , sizeof( * V_323 ) ) ;
V_323 -> V_749 = F_123 ( V_750 ) ;
V_323 -> V_751 = F_123 ( V_553 ) ;
V_323 -> V_752 = F_123 ( V_753 ) ;
return F_93 ( V_27 , V_84 , V_754 , sizeof( * V_323 ) , NULL , 0 ) ;
}
static int F_116 ( struct V_26 * V_27 )
{
struct V_748 * V_323 ;
const int F_55 = sizeof( struct V_748 ) ;
struct V_171 V_172 ;
int V_77 ;
V_77 = F_355 ( V_27 ) ;
if ( V_77 )
return 0 ;
V_77 = F_130 ( V_27 , & V_172 ) ;
if ( V_77 )
return 0 ;
if ( V_172 . V_169 != V_754 ) {
F_45 ( V_27 , L_171 ,
F_275 ( V_172 . V_169 ) , V_172 . V_169 ) ;
return - 1 ;
}
if ( V_172 . V_64 != F_55 ) {
F_45 ( V_27 , L_172 ,
F_55 , V_172 . V_64 ) ;
return - 1 ;
}
V_323 = V_172 . V_96 ;
V_77 = F_74 ( V_27 , V_323 , F_55 ) ;
if ( V_77 )
return 0 ;
V_323 -> V_749 = F_125 ( V_323 -> V_749 ) ;
V_323 -> V_751 = F_125 ( V_323 -> V_751 ) ;
if ( V_323 -> V_751 == 0 )
V_323 -> V_751 = V_323 -> V_749 ;
if ( V_553 < V_323 -> V_749 ||
V_750 > V_323 -> V_751 )
goto V_755;
V_27 -> V_186 = F_77 ( int , V_553 , V_323 -> V_751 ) ;
V_27 -> V_551 = V_753 & F_125 ( V_323 -> V_752 ) ;
F_68 ( V_27 , L_173
L_174 , V_27 -> V_186 ) ;
F_68 ( V_27 , L_175 ,
V_27 -> V_551 ,
V_27 -> V_551 & V_756 ? L_176 : L_104 ,
V_27 -> V_551 & V_757 ? L_177 : L_104 ,
V_27 -> V_551 & V_552 ? L_178 :
V_27 -> V_551 ? L_104 : L_179 ) ;
return 1 ;
V_755:
F_45 ( V_27 , L_180
L_181 ,
V_750 , V_553 ,
V_323 -> V_749 , V_323 -> V_751 ) ;
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
char V_758 [ V_759 ] ;
char * V_760 = NULL ;
char * V_761 = NULL ;
char * V_762 = NULL ;
unsigned int V_763 ;
char V_764 [ V_588 ] ;
unsigned int V_765 ;
F_356 ( V_766 , V_27 -> V_219 ) ;
struct V_171 V_172 ;
struct V_35 * V_36 ;
int V_77 , V_95 ;
F_24 () ;
V_36 = F_32 ( V_27 -> V_35 ) ;
V_763 = strlen ( V_36 -> V_767 ) ;
memcpy ( V_764 , V_36 -> V_767 , V_763 ) ;
F_28 () ;
V_766 -> V_600 = V_27 -> V_219 ;
V_766 -> V_69 = 0 ;
V_95 = F_357 ( V_27 -> V_219 , ( V_768 * ) V_764 , V_763 ) ;
if ( V_95 ) {
F_45 ( V_27 , L_184 , V_95 ) ;
V_95 = - 1 ;
goto V_63;
}
F_358 ( V_758 , V_759 ) ;
V_84 = & V_27 -> V_96 ;
if ( ! F_92 ( V_27 , V_84 ) ) {
V_95 = 0 ;
goto V_63;
}
V_95 = ! F_93 ( V_27 , V_84 , V_769 , 0 ,
V_758 , V_759 ) ;
if ( ! V_95 )
goto V_63;
V_77 = F_130 ( V_27 , & V_172 ) ;
if ( V_77 ) {
V_95 = 0 ;
goto V_63;
}
if ( V_172 . V_169 != V_769 ) {
F_45 ( V_27 , L_185 ,
F_275 ( V_172 . V_169 ) , V_172 . V_169 ) ;
V_95 = 0 ;
goto V_63;
}
if ( V_172 . V_64 > V_759 * 2 ) {
F_45 ( V_27 , L_186 ) ;
V_95 = - 1 ;
goto V_63;
}
if ( V_172 . V_64 < V_759 ) {
F_45 ( V_27 , L_187 ) ;
V_95 = - 1 ;
goto V_63;
}
V_762 = F_140 ( V_172 . V_64 , V_213 ) ;
if ( V_762 == NULL ) {
F_45 ( V_27 , L_188 ) ;
V_95 = - 1 ;
goto V_63;
}
V_77 = F_74 ( V_27 , V_762 , V_172 . V_64 ) ;
if ( V_77 ) {
V_95 = 0 ;
goto V_63;
}
if ( ! memcmp ( V_758 , V_762 , V_759 ) ) {
F_45 ( V_27 , L_189 ) ;
V_95 = - 1 ;
goto V_63;
}
V_765 = F_359 ( V_27 -> V_219 ) ;
V_760 = F_140 ( V_765 , V_213 ) ;
if ( V_760 == NULL ) {
F_45 ( V_27 , L_190 ) ;
V_95 = - 1 ;
goto V_63;
}
V_95 = F_360 ( V_766 , V_762 , V_172 . V_64 , V_760 ) ;
if ( V_95 ) {
F_45 ( V_27 , L_191 , V_95 ) ;
V_95 = - 1 ;
goto V_63;
}
if ( ! F_92 ( V_27 , V_84 ) ) {
V_95 = 0 ;
goto V_63;
}
V_95 = ! F_93 ( V_27 , V_84 , V_770 , 0 ,
V_760 , V_765 ) ;
if ( ! V_95 )
goto V_63;
V_77 = F_130 ( V_27 , & V_172 ) ;
if ( V_77 ) {
V_95 = 0 ;
goto V_63;
}
if ( V_172 . V_169 != V_770 ) {
F_45 ( V_27 , L_192 ,
F_275 ( V_172 . V_169 ) , V_172 . V_169 ) ;
V_95 = 0 ;
goto V_63;
}
if ( V_172 . V_64 != V_765 ) {
F_45 ( V_27 , L_193 ) ;
V_95 = 0 ;
goto V_63;
}
V_77 = F_74 ( V_27 , V_760 , V_765 ) ;
if ( V_77 ) {
V_95 = 0 ;
goto V_63;
}
V_761 = F_140 ( V_765 , V_213 ) ;
if ( V_761 == NULL ) {
F_45 ( V_27 , L_194 ) ;
V_95 = - 1 ;
goto V_63;
}
V_95 = F_360 ( V_766 , V_758 , V_759 ,
V_761 ) ;
if ( V_95 ) {
F_45 ( V_27 , L_191 , V_95 ) ;
V_95 = - 1 ;
goto V_63;
}
V_95 = ! memcmp ( V_760 , V_761 , V_765 ) ;
if ( V_95 )
F_68 ( V_27 , L_195 ,
V_765 ) ;
else
V_95 = - 1 ;
V_63:
F_52 ( V_762 ) ;
F_52 ( V_760 ) ;
F_52 ( V_761 ) ;
F_361 ( V_766 ) ;
return V_95 ;
}
int F_362 ( struct V_771 * V_772 )
{
struct V_26 * V_27 = V_772 -> V_27 ;
int V_194 ;
F_68 ( V_27 , L_196 ) ;
do {
V_194 = F_108 ( V_27 ) ;
if ( V_194 == 0 ) {
F_343 ( V_27 ) ;
F_99 ( V_44 ) ;
}
if ( V_194 == - 1 ) {
F_35 ( V_27 , L_197 ) ;
F_71 ( V_27 , F_72 ( V_105 , V_151 ) , V_107 ) ;
}
} while ( V_194 == 0 );
if ( V_194 > 0 ) {
F_129 ( & V_27 -> V_244 ) ;
F_340 ( V_27 ) ;
F_128 ( & V_27 -> V_244 ) ;
}
F_343 ( V_27 ) ;
F_68 ( V_27 , L_198 ) ;
return 0 ;
}
static int F_363 ( struct V_26 * V_27 , struct V_171 * V_172 )
{
struct V_773 * V_323 = V_172 -> V_96 ;
int V_774 = F_125 ( V_323 -> V_774 ) ;
if ( V_774 >= V_199 ) {
F_111 ( V_775 , & V_27 -> V_69 ) ;
} else {
F_111 ( V_776 , & V_27 -> V_69 ) ;
F_45 ( V_27 , L_199 ,
F_364 ( V_774 ) , V_774 ) ;
}
F_41 ( & V_27 -> V_101 ) ;
return 0 ;
}
static int F_365 ( struct V_26 * V_27 , struct V_171 * V_172 )
{
struct V_28 * V_29 ;
struct V_9 * V_10 ;
struct V_773 * V_323 = V_172 -> V_96 ;
int V_774 = F_125 ( V_323 -> V_774 ) ;
V_29 = F_199 ( V_27 , V_172 -> V_30 ) ;
if ( ! V_29 )
return - V_108 ;
V_10 = V_29 -> V_10 ;
if ( F_69 ( V_777 , & V_27 -> V_69 ) ) {
F_53 ( V_10 , V_27 -> V_186 < 100 ) ;
return F_363 ( V_27 , V_172 ) ;
}
if ( V_774 >= V_199 ) {
F_111 ( V_778 , & V_10 -> V_69 ) ;
} else {
F_111 ( V_779 , & V_10 -> V_69 ) ;
F_45 ( V_10 , L_199 ,
F_364 ( V_774 ) , V_774 ) ;
}
F_41 ( & V_10 -> V_780 ) ;
return 0 ;
}
static int F_366 ( struct V_26 * V_27 , struct V_171 * V_172 )
{
return F_367 ( V_27 ) ;
}
static int F_368 ( struct V_26 * V_27 , struct V_171 * V_172 )
{
V_27 -> V_202 . V_83 -> V_111 -> V_138 = V_27 -> V_35 -> V_217 * V_44 ;
if ( ! F_369 ( V_781 , & V_27 -> V_69 ) )
F_41 ( & V_27 -> V_101 ) ;
return 0 ;
}
static int F_370 ( struct V_26 * V_27 , struct V_171 * V_172 )
{
struct V_28 * V_29 ;
struct V_9 * V_10 ;
struct V_782 * V_323 = V_172 -> V_96 ;
T_3 V_52 = F_200 ( V_323 -> V_52 ) ;
int V_475 = F_125 ( V_323 -> V_475 ) ;
V_29 = F_199 ( V_27 , V_172 -> V_30 ) ;
if ( ! V_29 )
return - V_108 ;
V_10 = V_29 -> V_10 ;
F_53 ( V_10 , V_29 -> V_27 -> V_186 >= 89 ) ;
F_215 ( V_29 , F_125 ( V_323 -> V_425 ) ) ;
if ( F_146 ( V_10 ) ) {
F_339 ( V_10 , V_52 ) ;
F_189 ( V_10 , V_52 , V_475 ) ;
V_10 -> V_783 += ( V_475 >> V_784 ) ;
F_136 ( V_10 ) ;
}
F_194 ( V_10 ) ;
F_38 ( V_475 >> 9 , & V_10 -> V_375 ) ;
return 0 ;
}
static int
F_371 ( struct V_9 * V_10 , T_2 V_51 , T_3 V_52 ,
struct V_367 * V_368 , const char * V_370 ,
enum V_785 V_117 , bool V_369 )
{
struct V_347 * V_348 ;
struct V_415 V_416 ;
F_20 ( & V_10 -> V_24 -> V_25 ) ;
V_348 = F_196 ( V_10 , V_368 , V_51 , V_52 , V_369 , V_370 ) ;
if ( F_201 ( ! V_348 ) ) {
F_21 ( & V_10 -> V_24 -> V_25 ) ;
return - V_108 ;
}
F_208 ( V_348 , V_117 , & V_416 ) ;
F_21 ( & V_10 -> V_24 -> V_25 ) ;
if ( V_416 . V_246 )
F_223 ( V_10 , & V_416 ) ;
return 0 ;
}
static int F_372 ( struct V_26 * V_27 , struct V_171 * V_172 )
{
struct V_28 * V_29 ;
struct V_9 * V_10 ;
struct V_782 * V_323 = V_172 -> V_96 ;
T_3 V_52 = F_200 ( V_323 -> V_52 ) ;
int V_475 = F_125 ( V_323 -> V_475 ) ;
enum V_785 V_117 ;
V_29 = F_199 ( V_27 , V_172 -> V_30 ) ;
if ( ! V_29 )
return - V_108 ;
V_10 = V_29 -> V_10 ;
F_215 ( V_29 , F_125 ( V_323 -> V_425 ) ) ;
if ( V_323 -> V_68 == V_362 ) {
F_189 ( V_10 , V_52 , V_475 ) ;
F_194 ( V_10 ) ;
return 0 ;
}
switch ( V_172 -> V_169 ) {
case V_360 :
V_117 = V_786 ;
break;
case V_387 :
V_117 = V_787 ;
break;
case V_434 :
V_117 = V_788 ;
break;
case V_391 :
V_117 = V_379 ;
break;
case V_392 :
V_117 = V_789 ;
break;
default:
F_246 () ;
}
return F_371 ( V_10 , V_323 -> V_68 , V_52 ,
& V_10 -> V_319 , V_62 ,
V_117 , false ) ;
}
static int F_373 ( struct V_26 * V_27 , struct V_171 * V_172 )
{
struct V_28 * V_29 ;
struct V_9 * V_10 ;
struct V_782 * V_323 = V_172 -> V_96 ;
T_3 V_52 = F_200 ( V_323 -> V_52 ) ;
int V_64 = F_125 ( V_323 -> V_475 ) ;
int V_77 ;
V_29 = F_199 ( V_27 , V_172 -> V_30 ) ;
if ( ! V_29 )
return - V_108 ;
V_10 = V_29 -> V_10 ;
F_215 ( V_29 , F_125 ( V_323 -> V_425 ) ) ;
if ( V_323 -> V_68 == V_362 ) {
F_194 ( V_10 ) ;
F_191 ( V_10 , V_52 , V_64 ) ;
return 0 ;
}
V_77 = F_371 ( V_10 , V_323 -> V_68 , V_52 ,
& V_10 -> V_319 , V_62 ,
V_417 , true ) ;
if ( V_77 ) {
F_232 ( V_10 , V_52 , V_64 ) ;
}
return 0 ;
}
static int F_374 ( struct V_26 * V_27 , struct V_171 * V_172 )
{
struct V_28 * V_29 ;
struct V_9 * V_10 ;
struct V_782 * V_323 = V_172 -> V_96 ;
T_3 V_52 = F_200 ( V_323 -> V_52 ) ;
V_29 = F_199 ( V_27 , V_172 -> V_30 ) ;
if ( ! V_29 )
return - V_108 ;
V_10 = V_29 -> V_10 ;
F_215 ( V_29 , F_125 ( V_323 -> V_425 ) ) ;
F_45 ( V_10 , L_200 ,
( unsigned long long ) V_52 , F_125 ( V_323 -> V_475 ) ) ;
return F_371 ( V_10 , V_323 -> V_68 , V_52 ,
& V_10 -> V_372 , V_62 ,
V_417 , false ) ;
}
static int F_375 ( struct V_26 * V_27 , struct V_171 * V_172 )
{
struct V_28 * V_29 ;
struct V_9 * V_10 ;
T_3 V_52 ;
int V_64 ;
struct V_782 * V_323 = V_172 -> V_96 ;
V_29 = F_199 ( V_27 , V_172 -> V_30 ) ;
if ( ! V_29 )
return - V_108 ;
V_10 = V_29 -> V_10 ;
V_52 = F_200 ( V_323 -> V_52 ) ;
V_64 = F_125 ( V_323 -> V_475 ) ;
F_215 ( V_29 , F_125 ( V_323 -> V_425 ) ) ;
F_194 ( V_10 ) ;
if ( F_243 ( V_10 , V_689 ) ) {
F_339 ( V_10 , V_52 ) ;
switch ( V_172 -> V_169 ) {
case V_483 :
F_191 ( V_10 , V_52 , V_64 ) ;
case V_790 :
break;
default:
F_246 () ;
}
F_136 ( V_10 ) ;
}
return 0 ;
}
static int F_376 ( struct V_26 * V_27 , struct V_171 * V_172 )
{
struct V_791 * V_323 = V_172 -> V_96 ;
struct V_28 * V_29 ;
int V_30 ;
F_377 ( V_27 , V_323 -> V_324 , F_125 ( V_323 -> V_792 ) ) ;
F_24 () ;
F_25 (&connection->peer_devices, peer_device, vnr) {
struct V_9 * V_10 = V_29 -> V_10 ;
if ( V_10 -> V_383 . V_105 == V_685 &&
F_26 ( & V_10 -> V_191 ) == 0 &&
! F_369 ( V_793 , & V_10 -> V_69 ) ) {
V_10 -> V_794 . V_795 = V_66 + V_44 ;
F_378 ( & V_10 -> V_794 ) ;
}
}
F_28 () ;
return 0 ;
}
static int F_379 ( struct V_26 * V_27 , struct V_171 * V_172 )
{
struct V_28 * V_29 ;
struct V_9 * V_10 ;
struct V_782 * V_323 = V_172 -> V_96 ;
struct V_796 * V_797 ;
T_3 V_52 ;
int V_64 ;
V_29 = F_199 ( V_27 , V_172 -> V_30 ) ;
if ( ! V_29 )
return - V_108 ;
V_10 = V_29 -> V_10 ;
V_52 = F_200 ( V_323 -> V_52 ) ;
V_64 = F_125 ( V_323 -> V_475 ) ;
F_215 ( V_29 , F_125 ( V_323 -> V_425 ) ) ;
if ( F_200 ( V_323 -> V_68 ) == V_798 )
F_380 ( V_10 , V_52 , V_64 ) ;
else
F_307 ( V_10 ) ;
if ( ! F_146 ( V_10 ) )
return 0 ;
F_339 ( V_10 , V_52 ) ;
F_194 ( V_10 ) ;
-- V_10 -> V_467 ;
if ( ( V_10 -> V_467 & 0x200 ) == 0x200 )
F_381 ( V_10 , V_10 -> V_467 ) ;
if ( V_10 -> V_467 == 0 ) {
V_797 = F_140 ( sizeof( * V_797 ) , V_213 ) ;
if ( V_797 ) {
V_797 -> V_20 . V_80 = V_799 ;
V_797 -> V_10 = V_10 ;
F_382 ( & V_29 -> V_27 -> V_745 , & V_797 -> V_20 ) ;
} else {
F_45 ( V_10 , L_201 ) ;
F_307 ( V_10 ) ;
F_306 ( V_10 ) ;
}
}
F_136 ( V_10 ) ;
return 0 ;
}
static int F_383 ( struct V_26 * V_27 , struct V_171 * V_172 )
{
return 0 ;
}
static void F_384 ( struct V_26 * V_27 , bool V_800 )
{
long V_23 ;
struct V_35 * V_36 ;
F_24 () ;
V_36 = F_32 ( V_27 -> V_35 ) ;
V_23 = V_800 ? V_36 -> V_100 : V_36 -> V_217 ;
F_28 () ;
V_23 *= V_44 ;
if ( V_800 )
V_23 /= 10 ;
V_27 -> V_202 . V_83 -> V_111 -> V_138 = V_23 ;
}
static void F_385 ( struct V_26 * V_27 )
{
F_384 ( V_27 , 1 ) ;
}
static void F_386 ( struct V_26 * V_27 )
{
F_384 ( V_27 , 0 ) ;
}
int F_387 ( struct V_771 * V_772 )
{
struct V_26 * V_27 = V_772 -> V_27 ;
struct V_801 * V_169 = NULL ;
struct V_171 V_172 ;
unsigned long V_802 ;
int V_95 ;
void * V_85 = V_27 -> V_202 . V_173 ;
int V_803 = 0 ;
unsigned int V_170 = F_95 ( V_27 ) ;
int F_55 = V_170 ;
bool V_804 = false ;
struct V_805 V_806 = { . V_807 = 2 } ;
V_95 = F_388 ( V_43 , V_808 , & V_806 ) ;
if ( V_95 < 0 )
F_45 ( V_27 , L_202 , V_95 ) ;
while ( F_114 ( V_772 ) == V_728 ) {
F_341 ( V_772 ) ;
F_23 ( V_27 ) ;
if ( F_288 ( V_809 , & V_27 -> V_69 ) ) {
if ( F_389 ( V_27 ) ) {
F_45 ( V_27 , L_203 ) ;
goto V_617;
}
F_385 ( V_27 ) ;
V_804 = true ;
}
V_802 = V_66 ;
V_95 = F_65 ( V_27 -> V_202 . V_83 , V_85 , F_55 - V_803 , 0 ) ;
if ( F_188 ( V_95 > 0 ) ) {
V_803 += V_95 ;
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
goto V_617;
} else if ( V_95 == - V_144 ) {
if ( F_390 ( V_27 -> V_218 , V_802 ) )
continue;
if ( V_804 ) {
F_45 ( V_27 , L_205 ) ;
goto V_617;
}
F_111 ( V_809 , & V_27 -> V_69 ) ;
continue;
} else if ( V_95 == - V_146 ) {
F_112 ( V_43 ) ;
continue;
} else {
F_45 ( V_27 , L_7 , V_95 ) ;
goto V_617;
}
if ( V_803 == F_55 && V_169 == NULL ) {
if ( F_96 ( V_27 , V_27 -> V_202 . V_173 , & V_172 ) )
goto V_617;
V_169 = & V_810 [ V_172 . V_169 ] ;
if ( V_172 . V_169 >= F_342 ( V_810 ) || ! V_169 -> V_732 ) {
F_45 ( V_27 , L_206 ,
F_275 ( V_172 . V_169 ) , V_172 . V_169 ) ;
goto V_597;
}
F_55 = V_170 + V_169 -> V_733 ;
if ( V_172 . V_64 != F_55 - V_170 ) {
F_45 ( V_27 , L_207 ,
V_172 . V_169 , V_172 . V_64 ) ;
goto V_617;
}
}
if ( V_803 == F_55 ) {
bool V_77 ;
V_77 = V_169 -> V_732 ( V_27 , & V_172 ) ;
if ( V_77 ) {
F_45 ( V_27 , L_208 , V_169 -> V_732 ) ;
goto V_617;
}
V_27 -> V_218 = V_66 ;
if ( V_169 == & V_810 [ V_811 ] ) {
F_386 ( V_27 ) ;
V_804 = false ;
}
V_85 = V_27 -> V_202 . V_173 ;
V_803 = 0 ;
F_55 = V_170 ;
V_169 = NULL ;
}
}
if ( 0 ) {
V_617:
F_71 ( V_27 , F_72 ( V_105 , V_738 ) , V_107 ) ;
F_391 ( V_27 ) ;
}
if ( 0 ) {
V_597:
F_71 ( V_27 , F_72 ( V_105 , V_151 ) , V_107 ) ;
}
F_68 ( V_27 , L_209 ) ;
return 0 ;
}
void F_392 ( struct V_812 * V_813 )
{
struct V_28 * V_29 =
F_187 ( V_813 , struct V_28 , V_422 ) ;
struct V_26 * V_27 = V_29 -> V_27 ;
struct V_9 * V_10 = V_29 -> V_10 ;
struct V_35 * V_36 ;
int V_814 , V_77 ;
F_24 () ;
V_36 = F_32 ( V_27 -> V_35 ) ;
V_814 = V_36 -> V_814 ;
F_28 () ;
if ( V_814 )
F_393 ( V_27 -> V_202 . V_83 ) ;
V_77 = F_59 ( V_10 ) ;
F_29 ( & V_10 -> V_32 , V_33 ) ;
if ( V_77 ) {
F_71 ( V_27 , F_72 ( V_105 , V_738 ) , V_107 ) ;
return;
}
if ( V_814 )
F_394 ( V_27 -> V_202 . V_83 ) ;
return;
}
