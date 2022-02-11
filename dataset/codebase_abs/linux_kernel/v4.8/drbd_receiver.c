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
F_135 ( V_244 , V_259 , V_260 ) ;
V_10 -> V_261 = V_66 ;
F_111 ( V_251 , & V_10 -> V_69 ) ;
F_136 ( & V_249 -> V_252 ) ;
F_137 ( V_244 ) ;
}
static void F_138 ( struct V_26 * V_27 )
{
if ( V_27 -> V_24 -> V_262 >= V_263 ) {
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
F_132 ( V_10 , & V_249 ) ;
F_24 () ;
}
F_28 () ;
if ( ! F_131 ( & V_249 . V_252 ) )
F_141 ( & V_249 . V_253 ) ;
if ( V_249 . error ) {
F_142 ( V_27 -> V_24 , NULL , V_264 ) ;
}
}
}
static enum V_265 F_143 ( struct V_26 * V_27 ,
struct V_266 * V_267 ,
enum V_268 V_269 )
{
int V_270 ;
struct V_266 * V_271 ;
enum V_265 V_95 = V_272 ;
F_11 ( & V_27 -> V_273 ) ;
do {
V_271 = NULL ;
V_270 = F_26 ( & V_267 -> V_270 ) ;
switch ( V_269 & ~ V_274 ) {
case V_275 :
F_144 ( & V_267 -> V_276 ) ;
break;
case V_277 :
F_111 ( V_278 , & V_267 -> V_69 ) ;
break;
case V_279 :
break;
}
if ( V_270 != 0 &&
F_26 ( & V_267 -> V_276 ) == 0 &&
( F_69 ( V_278 , & V_267 -> V_69 ) || V_269 & V_274 ) ) {
if ( ! ( V_269 & V_274 ) ) {
F_12 ( & V_27 -> V_273 ) ;
F_145 ( V_267 -> V_27 , V_267 -> V_280 , V_270 ) ;
F_11 ( & V_27 -> V_273 ) ;
}
#if 0
if (test_bit(DE_HAVE_BARRIER_NUMBER, &epoch->flags))
dec_unacked(epoch->connection);
#endif
if ( V_27 -> V_281 != V_267 ) {
V_271 = F_146 ( V_267 -> V_21 . V_282 , struct V_266 , V_21 ) ;
F_147 ( & V_267 -> V_21 ) ;
V_269 = V_279 | ( V_269 & V_274 ) ;
V_27 -> V_283 -- ;
F_52 ( V_267 ) ;
if ( V_95 == V_272 )
V_95 = V_284 ;
} else {
V_267 -> V_69 = 0 ;
F_101 ( & V_267 -> V_270 , 0 ) ;
if ( V_95 == V_272 )
V_95 = V_285 ;
}
}
if ( ! V_271 )
break;
V_267 = V_271 ;
} while ( 1 );
F_12 ( & V_27 -> V_273 ) ;
return V_95 ;
}
static enum V_286
F_148 ( struct V_287 * V_288 , enum V_286 V_289 )
{
struct V_290 * V_291 ;
V_291 = F_32 ( V_288 -> V_290 ) ;
if ( V_289 == V_263 && ! V_291 -> V_292 )
V_289 = V_264 ;
if ( V_289 == V_264 && ! V_291 -> V_293 )
V_289 = V_294 ;
return V_289 ;
}
void F_142 ( struct V_295 * V_24 , struct V_287 * V_288 ,
enum V_286 V_289 )
{
struct V_9 * V_10 ;
enum V_286 V_296 ;
int V_30 ;
static char * V_297 [] = {
[ V_294 ] = L_29 ,
[ V_264 ] = L_30 ,
[ V_263 ] = L_31 ,
} ;
V_296 = V_24 -> V_262 ;
if ( V_289 != V_263 )
V_289 = F_149 ( V_296 , V_289 ) ;
F_24 () ;
F_25 (&resource->devices, device, vnr) {
if ( F_140 ( V_10 ) ) {
V_289 = F_148 ( V_10 -> V_256 , V_289 ) ;
if ( V_10 -> V_256 == V_288 )
V_288 = NULL ;
F_130 ( V_10 ) ;
}
}
if ( V_288 )
V_289 = F_148 ( V_288 , V_289 ) ;
F_28 () ;
V_24 -> V_262 = V_289 ;
if ( V_296 != V_24 -> V_262 || V_289 == V_263 )
F_68 ( V_24 , L_32 , V_297 [ V_24 -> V_262 ] ) ;
}
int F_150 ( struct V_9 * V_10 , T_3 V_298 , unsigned int V_299 , bool V_300 )
{
struct V_301 * V_288 = V_10 -> V_256 -> V_257 ;
struct V_302 * V_303 = F_151 ( V_288 ) ;
T_3 V_4 , V_304 ;
unsigned int V_305 , V_306 ;
int V_307 ;
int V_77 = 0 ;
if ( ! V_300 )
goto V_308;
V_306 = F_152 ( V_303 -> V_309 . V_310 >> 9 , 1U ) ;
V_307 = ( F_153 ( V_288 ) >> 9 ) % V_306 ;
V_305 = F_149 ( V_303 -> V_309 . V_305 , ( 1U << 22 ) ) ;
V_305 -= V_305 % V_306 ;
if ( F_154 ( ! V_305 ) )
goto V_308;
if ( V_299 < V_306 )
goto V_308;
V_4 = V_298 ;
if ( F_155 ( V_4 , V_306 ) != V_307 ) {
if ( V_299 < 2 * V_306 )
goto V_308;
V_4 = V_298 + V_306 - V_307 ;
V_4 = V_298 + V_306 - F_155 ( V_4 , V_306 ) ;
V_304 = V_4 - V_298 ;
V_77 |= F_156 ( V_288 , V_298 , V_304 , V_213 , 0 ) ;
V_299 -= V_304 ;
V_298 = V_4 ;
}
while ( V_299 >= V_306 ) {
V_304 = F_77 ( T_3 , V_299 , V_305 ) ;
V_77 |= F_157 ( V_288 , V_298 , V_304 , V_213 , 0 ) ;
V_299 -= V_304 ;
V_298 += V_304 ;
}
V_308:
if ( V_299 ) {
V_77 |= F_156 ( V_288 , V_298 , V_299 , V_213 , 0 ) ;
}
return V_77 != 0 ;
}
static bool F_158 ( struct V_9 * V_10 )
{
struct V_302 * V_303 = F_151 ( V_10 -> V_256 -> V_257 ) ;
struct V_290 * V_291 ;
bool V_311 ;
if ( ! F_159 ( V_303 ) )
return false ;
if ( V_303 -> V_309 . V_312 )
return true ;
F_24 () ;
V_291 = F_32 ( V_10 -> V_256 -> V_290 ) ;
V_311 = V_291 -> V_313 ;
F_28 () ;
return V_311 ;
}
static void F_160 ( struct V_9 * V_10 , struct V_18 * V_19 )
{
if ( ! F_158 ( V_10 ) )
V_19 -> V_69 |= V_314 ;
if ( F_150 ( V_10 , V_19 -> V_6 . V_52 ,
V_19 -> V_6 . V_64 >> 9 , ! ( V_19 -> V_69 & V_314 ) ) )
V_19 -> V_69 |= V_315 ;
F_161 ( V_19 ) ;
}
static void F_162 ( struct V_9 * V_10 ,
struct V_18 * V_19 )
{
struct V_301 * V_288 = V_10 -> V_256 -> V_257 ;
T_3 V_203 = V_19 -> V_6 . V_52 ;
T_3 V_304 = V_19 -> V_6 . V_64 >> 9 ;
if ( F_163 ( V_288 , V_203 , V_304 , V_213 , V_19 -> V_67 ) )
V_19 -> V_69 |= V_315 ;
F_161 ( V_19 ) ;
}
int F_164 ( struct V_9 * V_10 ,
struct V_18 * V_19 ,
const unsigned V_316 , const unsigned V_317 ,
const int V_318 )
{
struct V_244 * V_319 = NULL ;
struct V_244 * V_244 ;
struct V_1 * V_1 = V_19 -> V_67 ;
T_3 V_52 = V_19 -> V_6 . V_52 ;
unsigned V_320 = V_19 -> V_6 . V_64 ;
unsigned V_321 = 0 ;
unsigned V_56 = ( V_320 + V_49 - 1 ) >> V_57 ;
int V_77 = - V_254 ;
if ( V_19 -> V_69 & ( V_322 | V_323 ) ) {
F_165 ( V_19 -> V_29 -> V_27 ) ;
V_19 -> V_65 = V_66 ;
V_19 -> V_69 |= V_324 ;
if ( F_62 ( & V_19 -> V_20 . V_21 ) ) {
F_20 ( & V_10 -> V_24 -> V_25 ) ;
F_166 ( & V_19 -> V_20 . V_21 , & V_10 -> V_325 ) ;
F_21 ( & V_10 -> V_24 -> V_25 ) ;
}
if ( V_19 -> V_69 & V_322 )
F_160 ( V_10 , V_19 ) ;
else
F_162 ( V_10 , V_19 ) ;
return 0 ;
}
V_326:
V_244 = F_133 ( V_213 , V_56 ) ;
if ( ! V_244 ) {
F_45 ( V_10 , L_33 , V_56 ) ;
goto V_63;
}
V_244 -> V_327 . V_328 = V_52 ;
V_244 -> V_255 = V_10 -> V_256 -> V_257 ;
F_135 ( V_244 , V_316 , V_317 ) ;
V_244 -> V_247 = V_19 ;
V_244 -> V_258 = V_329 ;
V_244 -> V_330 = V_319 ;
V_319 = V_244 ;
++ V_321 ;
F_167 (page) {
unsigned V_5 = F_77 ( unsigned , V_320 , V_49 ) ;
if ( ! F_168 ( V_244 , V_1 , V_5 , 0 ) ) {
if ( V_244 -> V_331 == 0 ) {
F_45 ( V_10 ,
L_34
L_35 ,
V_5 , ( V_332 ) V_244 -> V_327 . V_328 ) ;
V_77 = - V_333 ;
goto V_63;
}
goto V_326;
}
V_320 -= V_5 ;
V_52 += V_5 >> 9 ;
-- V_56 ;
}
F_53 ( V_10 , V_320 == 0 ) ;
F_53 ( V_10 , V_1 == NULL ) ;
F_101 ( & V_19 -> V_72 , V_321 ) ;
V_19 -> V_65 = V_66 ;
V_19 -> V_69 |= V_324 ;
do {
V_244 = V_319 ;
V_319 = V_319 -> V_330 ;
V_244 -> V_330 = NULL ;
F_169 ( V_10 , V_318 , V_244 ) ;
} while ( V_319 );
return 0 ;
V_63:
while ( V_319 ) {
V_244 = V_319 ;
V_319 = V_319 -> V_330 ;
F_129 ( V_244 ) ;
}
return V_77 ;
}
static void F_170 ( struct V_9 * V_10 ,
struct V_18 * V_19 )
{
struct V_334 * V_6 = & V_19 -> V_6 ;
F_171 ( & V_10 -> V_335 , V_6 ) ;
F_48 ( V_6 ) ;
if ( V_6 -> V_336 )
F_41 ( & V_10 -> V_337 ) ;
}
static void F_165 ( struct V_26 * V_27 )
{
struct V_28 * V_29 ;
int V_30 ;
F_24 () ;
F_25 (&connection->peer_devices, peer_device, vnr) {
struct V_9 * V_10 = V_29 -> V_10 ;
F_27 ( & V_10 -> V_32 ) ;
F_28 () ;
F_64 ( V_10 , & V_10 -> V_325 ) ;
F_29 ( & V_10 -> V_32 , V_33 ) ;
F_24 () ;
}
F_28 () ;
}
static int F_172 ( struct V_26 * V_27 , struct V_171 * V_172 )
{
int V_95 ;
struct V_338 * V_339 = V_172 -> V_96 ;
struct V_266 * V_267 ;
V_27 -> V_281 -> V_280 = V_339 -> V_340 ;
V_27 -> V_281 -> V_27 = V_27 ;
V_95 = F_143 ( V_27 , V_27 -> V_281 , V_277 ) ;
switch ( V_27 -> V_24 -> V_262 ) {
case V_294 :
if ( V_95 == V_285 )
return 0 ;
V_267 = F_134 ( sizeof( struct V_266 ) , V_213 ) ;
if ( V_267 )
break;
else
F_35 ( V_27 , L_36 ) ;
case V_263 :
case V_264 :
F_165 ( V_27 ) ;
F_138 ( V_27 ) ;
if ( F_26 ( & V_27 -> V_281 -> V_270 ) ) {
V_267 = F_134 ( sizeof( struct V_266 ) , V_213 ) ;
if ( V_267 )
break;
}
return 0 ;
default:
F_45 ( V_27 , L_37 ,
V_27 -> V_24 -> V_262 ) ;
return - V_108 ;
}
V_267 -> V_69 = 0 ;
F_101 ( & V_267 -> V_270 , 0 ) ;
F_101 ( & V_267 -> V_276 , 0 ) ;
F_11 ( & V_27 -> V_273 ) ;
if ( F_26 ( & V_27 -> V_281 -> V_270 ) ) {
F_173 ( & V_267 -> V_21 , & V_27 -> V_281 -> V_21 ) ;
V_27 -> V_281 = V_267 ;
V_27 -> V_283 ++ ;
} else {
F_52 ( V_267 ) ;
}
F_12 ( & V_27 -> V_273 ) ;
return 0 ;
}
static void F_174 ( struct V_341 * V_194 ,
struct V_18 * V_342 , void * V_343 ,
unsigned int V_54 )
{
unsigned int V_4 = V_342 -> V_6 . V_64 ;
V_342 -> V_6 . V_64 = V_54 ;
F_175 ( V_194 , V_342 , V_343 ) ;
V_342 -> V_6 . V_64 = V_4 ;
}
static struct V_18 *
F_176 ( struct V_28 * V_29 , T_2 V_51 , T_3 V_52 ,
struct V_171 * V_172 ) __must_hold( T_5 )
{
struct V_9 * V_10 = V_29 -> V_10 ;
const T_3 V_344 = F_177 ( V_10 -> V_345 ) ;
struct V_18 * V_19 ;
struct V_1 * V_1 ;
int V_346 , V_77 ;
unsigned int V_320 = V_172 -> V_64 , V_347 ;
void * V_348 = V_29 -> V_27 -> V_349 ;
void * V_350 = V_29 -> V_27 -> V_351 ;
unsigned long * V_96 ;
struct V_352 * V_353 = ( V_172 -> V_169 == V_354 ) ? V_172 -> V_96 : NULL ;
struct V_352 * V_355 = ( V_172 -> V_169 == V_356 ) ? V_172 -> V_96 : NULL ;
V_346 = 0 ;
if ( ! V_353 && V_29 -> V_27 -> V_357 ) {
V_346 = F_178 ( V_29 -> V_27 -> V_357 ) ;
V_77 = F_74 ( V_29 -> V_27 , V_348 , V_346 ) ;
if ( V_77 )
return NULL ;
V_320 -= V_346 ;
}
V_347 = V_320 ;
if ( V_353 ) {
if ( ! F_55 ( V_320 == 0 ) )
return NULL ;
V_347 = F_125 ( V_353 -> V_64 ) ;
} else if ( V_355 ) {
if ( V_320 != F_179 ( V_10 -> V_358 ) ) {
F_45 ( V_29 , L_38 ,
V_320 , F_179 ( V_10 -> V_358 ) ) ;
return NULL ;
}
if ( V_320 != F_180 ( V_10 -> V_256 -> V_257 ) ) {
F_45 ( V_29 , L_39 ,
V_320 , F_180 ( V_10 -> V_256 -> V_257 ) ) ;
return NULL ;
}
V_347 = F_125 ( V_355 -> V_64 ) ;
}
if ( ! F_55 ( F_181 ( V_347 , 512 ) ) )
return NULL ;
if ( V_353 || V_355 ) {
if ( ! F_55 ( V_347 <= ( V_359 << 9 ) ) )
return NULL ;
} else if ( ! F_55 ( V_347 <= V_48 ) )
return NULL ;
if ( V_52 + ( V_347 >> 9 ) > V_344 ) {
F_45 ( V_10 , L_40
L_41 ,
( unsigned long long ) V_344 ,
( unsigned long long ) V_52 , V_347 ) ;
return NULL ;
}
V_19 = F_42 ( V_29 , V_51 , V_52 , V_347 , V_320 , V_213 ) ;
if ( ! V_19 )
return NULL ;
V_19 -> V_69 |= V_360 ;
if ( V_353 ) {
V_19 -> V_69 |= V_322 ;
return V_19 ;
}
if ( V_355 )
V_19 -> V_69 |= V_323 ;
V_347 = V_320 ;
V_1 = V_19 -> V_67 ;
F_167 (page) {
unsigned V_5 = F_77 ( int , V_347 , V_49 ) ;
V_96 = F_182 ( V_1 ) ;
V_77 = F_74 ( V_29 -> V_27 , V_96 , V_5 ) ;
if ( F_43 ( V_10 , V_361 ) ) {
F_45 ( V_10 , L_42 ) ;
V_96 [ 0 ] = V_96 [ 0 ] ^ ( unsigned long ) - 1 ;
}
F_183 ( V_1 ) ;
if ( V_77 ) {
F_60 ( V_10 , V_19 ) ;
return NULL ;
}
V_347 -= V_5 ;
}
if ( V_346 ) {
F_174 ( V_29 -> V_27 -> V_357 , V_19 , V_350 , V_320 ) ;
if ( memcmp ( V_348 , V_350 , V_346 ) ) {
F_45 ( V_10 , L_43 ,
( unsigned long long ) V_52 , V_320 ) ;
F_60 ( V_10 , V_19 ) ;
return NULL ;
}
}
V_10 -> V_362 += V_320 >> 9 ;
return V_19 ;
}
static int F_184 ( struct V_28 * V_29 , int V_320 )
{
struct V_1 * V_1 ;
int V_77 = 0 ;
void * V_96 ;
if ( ! V_320 )
return 0 ;
V_1 = F_30 ( V_29 , 1 , 1 ) ;
V_96 = F_182 ( V_1 ) ;
while ( V_320 ) {
unsigned int V_5 = F_77 ( int , V_320 , V_49 ) ;
V_77 = F_74 ( V_29 -> V_27 , V_96 , V_5 ) ;
if ( V_77 )
break;
V_320 -= V_5 ;
}
F_183 ( V_1 ) ;
F_39 ( V_29 -> V_10 , V_1 , 0 ) ;
return V_77 ;
}
static int F_185 ( struct V_28 * V_29 , struct V_363 * V_364 ,
T_3 V_52 , int V_320 )
{
struct V_365 V_366 ;
struct V_367 V_368 ;
struct V_244 * V_244 ;
int V_346 , V_77 , F_55 ;
void * V_348 = V_29 -> V_27 -> V_349 ;
void * V_350 = V_29 -> V_27 -> V_351 ;
V_346 = 0 ;
if ( V_29 -> V_27 -> V_357 ) {
V_346 = F_178 ( V_29 -> V_27 -> V_357 ) ;
V_77 = F_74 ( V_29 -> V_27 , V_348 , V_346 ) ;
if ( V_77 )
return V_77 ;
V_320 -= V_346 ;
}
V_29 -> V_10 -> V_362 += V_320 >> 9 ;
V_244 = V_364 -> V_369 ;
F_53 ( V_29 -> V_10 , V_52 == V_244 -> V_327 . V_328 ) ;
F_186 (bvec, bio, iter) {
void * V_370 = F_182 ( V_366 . V_371 ) + V_366 . V_372 ;
F_55 = F_77 ( int , V_320 , V_366 . V_373 ) ;
V_77 = F_74 ( V_29 -> V_27 , V_370 , F_55 ) ;
F_183 ( V_366 . V_371 ) ;
if ( V_77 )
return V_77 ;
V_320 -= F_55 ;
}
if ( V_346 ) {
F_187 ( V_29 -> V_27 -> V_357 , V_244 , V_350 ) ;
if ( memcmp ( V_348 , V_350 , V_346 ) ) {
F_45 ( V_29 , L_44 ) ;
return - V_234 ;
}
}
F_53 ( V_29 -> V_10 , V_320 == 0 ) ;
return 0 ;
}
static int F_188 ( struct V_374 * V_20 , int V_375 )
{
struct V_18 * V_19 =
F_189 ( V_20 , struct V_18 , V_20 ) ;
struct V_28 * V_29 = V_19 -> V_29 ;
struct V_9 * V_10 = V_29 -> V_10 ;
T_3 V_52 = V_19 -> V_6 . V_52 ;
int V_77 ;
F_53 ( V_10 , F_54 ( & V_19 -> V_6 ) ) ;
if ( F_190 ( ( V_19 -> V_69 & V_315 ) == 0 ) ) {
F_191 ( V_10 , V_52 , V_19 -> V_6 . V_64 ) ;
V_77 = F_192 ( V_29 , V_376 , V_19 ) ;
} else {
F_193 ( V_10 , V_52 , V_19 -> V_6 . V_64 ) ;
V_77 = F_192 ( V_29 , V_377 , V_19 ) ;
}
F_194 ( V_10 ) ;
return V_77 ;
}
static int F_195 ( struct V_28 * V_29 , T_3 V_52 ,
struct V_171 * V_172 ) __releases( T_5 )
{
struct V_9 * V_10 = V_29 -> V_10 ;
struct V_18 * V_19 ;
V_19 = F_176 ( V_29 , V_378 , V_52 , V_172 ) ;
if ( ! V_19 )
goto V_63;
F_196 ( V_10 ) ;
F_197 ( V_10 ) ;
V_19 -> V_20 . V_80 = F_188 ;
V_19 -> V_65 = V_66 ;
F_20 ( & V_10 -> V_24 -> V_25 ) ;
F_166 ( & V_19 -> V_20 . V_21 , & V_10 -> V_379 ) ;
F_21 ( & V_10 -> V_24 -> V_25 ) ;
F_38 ( V_172 -> V_64 >> 9 , & V_10 -> V_380 ) ;
if ( F_164 ( V_10 , V_19 , V_381 , 0 ,
V_382 ) == 0 )
return 0 ;
F_45 ( V_10 , L_45 ) ;
F_20 ( & V_10 -> V_24 -> V_25 ) ;
F_147 ( & V_19 -> V_20 . V_21 ) ;
F_21 ( & V_10 -> V_24 -> V_25 ) ;
F_60 ( V_10 , V_19 ) ;
V_63:
F_130 ( V_10 ) ;
return - V_108 ;
}
static struct V_363 *
F_198 ( struct V_9 * V_10 , struct V_383 * V_384 , T_2 V_51 ,
T_3 V_52 , bool V_385 , const char * V_386 )
{
struct V_363 * V_364 ;
V_364 = (struct V_363 * ) ( unsigned long ) V_51 ;
if ( F_199 ( V_384 , V_52 , & V_364 -> V_6 ) && V_364 -> V_6 . T_5 )
return V_364 ;
if ( ! V_385 ) {
F_45 ( V_10 , L_46 , V_386 ,
( unsigned long ) V_51 , ( unsigned long long ) V_52 ) ;
}
return NULL ;
}
static int F_200 ( struct V_26 * V_27 , struct V_171 * V_172 )
{
struct V_28 * V_29 ;
struct V_9 * V_10 ;
struct V_363 * V_364 ;
T_3 V_52 ;
int V_77 ;
struct V_387 * V_339 = V_172 -> V_96 ;
V_29 = F_201 ( V_27 , V_172 -> V_30 ) ;
if ( ! V_29 )
return - V_108 ;
V_10 = V_29 -> V_10 ;
V_52 = F_202 ( V_339 -> V_52 ) ;
F_20 ( & V_10 -> V_24 -> V_25 ) ;
V_364 = F_198 ( V_10 , & V_10 -> V_388 , V_339 -> V_68 , V_52 , false , V_62 ) ;
F_21 ( & V_10 -> V_24 -> V_25 ) ;
if ( F_154 ( ! V_364 ) )
return - V_108 ;
V_77 = F_185 ( V_29 , V_364 , V_52 , V_172 -> V_64 ) ;
if ( ! V_77 )
F_203 ( V_364 , V_389 ) ;
return V_77 ;
}
static int F_204 ( struct V_26 * V_27 , struct V_171 * V_172 )
{
struct V_28 * V_29 ;
struct V_9 * V_10 ;
T_3 V_52 ;
int V_77 ;
struct V_387 * V_339 = V_172 -> V_96 ;
V_29 = F_201 ( V_27 , V_172 -> V_30 ) ;
if ( ! V_29 )
return - V_108 ;
V_10 = V_29 -> V_10 ;
V_52 = F_202 ( V_339 -> V_52 ) ;
F_53 ( V_10 , V_339 -> V_68 == V_378 ) ;
if ( F_140 ( V_10 ) ) {
V_77 = F_195 ( V_29 , V_52 , V_172 ) ;
} else {
if ( F_205 ( & V_390 ) )
F_45 ( V_10 , L_47 ) ;
V_77 = F_184 ( V_29 , V_172 -> V_64 ) ;
F_206 ( V_29 , V_377 , V_339 , V_172 -> V_64 ) ;
}
F_38 ( V_172 -> V_64 >> 9 , & V_10 -> V_391 ) ;
return V_77 ;
}
static void F_207 ( struct V_9 * V_10 ,
T_3 V_52 , int V_64 )
{
struct V_334 * V_6 ;
struct V_363 * V_364 ;
F_208 (i, &device->write_requests, sector, size) {
if ( ! V_6 -> T_5 )
continue;
V_364 = F_189 ( V_6 , struct V_363 , V_6 ) ;
if ( V_364 -> V_392 & V_393 ||
! ( V_364 -> V_392 & V_394 ) )
continue;
F_209 ( V_364 , V_395 , NULL ) ;
}
}
static int F_210 ( struct V_374 * V_20 , int V_396 )
{
struct V_18 * V_19 =
F_189 ( V_20 , struct V_18 , V_20 ) ;
struct V_28 * V_29 = V_19 -> V_29 ;
struct V_9 * V_10 = V_29 -> V_10 ;
T_3 V_52 = V_19 -> V_6 . V_52 ;
int V_77 = 0 , V_397 ;
if ( V_19 -> V_69 & V_398 ) {
if ( F_190 ( ( V_19 -> V_69 & V_315 ) == 0 ) ) {
V_397 = ( V_10 -> V_399 . V_105 >= V_400 &&
V_10 -> V_399 . V_105 <= V_401 &&
V_19 -> V_69 & V_402 ) ?
V_376 : V_403 ;
V_77 = F_192 ( V_29 , V_397 , V_19 ) ;
if ( V_397 == V_376 )
F_191 ( V_10 , V_52 , V_19 -> V_6 . V_64 ) ;
} else {
V_77 = F_192 ( V_29 , V_377 , V_19 ) ;
}
F_194 ( V_10 ) ;
}
if ( V_19 -> V_69 & V_404 ) {
F_20 ( & V_10 -> V_24 -> V_25 ) ;
F_53 ( V_10 , ! F_54 ( & V_19 -> V_6 ) ) ;
F_170 ( V_10 , V_19 ) ;
if ( V_19 -> V_69 & V_405 )
F_207 ( V_10 , V_52 , V_19 -> V_6 . V_64 ) ;
F_21 ( & V_10 -> V_24 -> V_25 ) ;
} else
F_53 ( V_10 , F_54 ( & V_19 -> V_6 ) ) ;
F_143 ( V_29 -> V_27 , V_19 -> V_267 , V_275 + ( V_396 ? V_274 : 0 ) ) ;
return V_77 ;
}
static int F_211 ( struct V_374 * V_20 , enum V_168 V_406 )
{
struct V_18 * V_19 =
F_189 ( V_20 , struct V_18 , V_20 ) ;
struct V_28 * V_29 = V_19 -> V_29 ;
int V_77 ;
V_77 = F_192 ( V_29 , V_406 , V_19 ) ;
F_194 ( V_29 -> V_10 ) ;
return V_77 ;
}
static int F_212 ( struct V_374 * V_20 , int V_375 )
{
return F_211 ( V_20 , V_407 ) ;
}
static int F_213 ( struct V_374 * V_20 , int V_375 )
{
struct V_18 * V_19 =
F_189 ( V_20 , struct V_18 , V_20 ) ;
struct V_26 * V_27 = V_19 -> V_29 -> V_27 ;
return F_211 ( V_20 , V_27 -> V_186 >= 100 ?
V_408 : V_407 ) ;
}
static bool F_214 ( T_7 V_47 , T_7 V_409 )
{
return ( V_410 ) V_47 - ( V_410 ) V_409 > 0 ;
}
static T_7 F_215 ( T_7 V_47 , T_7 V_409 )
{
return F_214 ( V_47 , V_409 ) ? V_47 : V_409 ;
}
static void F_216 ( struct V_28 * V_29 , unsigned int V_184 )
{
struct V_9 * V_10 = V_29 -> V_10 ;
unsigned int V_411 ;
if ( F_69 ( V_205 , & V_29 -> V_27 -> V_69 ) ) {
F_11 ( & V_10 -> V_412 ) ;
V_411 = F_215 ( V_10 -> V_184 , V_184 ) ;
V_10 -> V_184 = V_411 ;
F_12 ( & V_10 -> V_412 ) ;
if ( V_184 == V_411 )
F_41 ( & V_10 -> V_413 ) ;
}
}
static inline int F_217 ( T_3 V_414 , int V_415 , T_3 V_416 , int V_417 )
{
return ! ( ( V_414 + ( V_415 >> 9 ) <= V_416 ) || ( V_414 >= V_416 + ( V_417 >> 9 ) ) ) ;
}
static bool F_218 ( struct V_9 * V_10 , struct V_18 * V_19 )
{
struct V_18 * V_418 ;
bool V_95 = false ;
F_20 ( & V_10 -> V_24 -> V_25 ) ;
F_219 (rs_req, &device->sync_ee, w.list) {
if ( F_217 ( V_19 -> V_6 . V_52 , V_19 -> V_6 . V_64 ,
V_418 -> V_6 . V_52 , V_418 -> V_6 . V_64 ) ) {
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
int V_419 = 0 , V_420 ;
if ( ! F_69 ( V_205 , & V_29 -> V_27 -> V_69 ) )
return 0 ;
F_11 ( & V_10 -> V_412 ) ;
for (; ; ) {
if ( ! F_214 ( V_184 - 1 , V_10 -> V_184 ) ) {
V_10 -> V_184 = F_215 ( V_10 -> V_184 , V_184 ) ;
break;
}
if ( F_34 ( V_43 ) ) {
V_419 = - V_98 ;
break;
}
F_24 () ;
V_420 = F_32 ( V_29 -> V_27 -> V_35 ) -> V_421 ;
F_28 () ;
if ( ! V_420 )
break;
F_33 ( & V_10 -> V_413 , & V_37 , V_42 ) ;
F_12 ( & V_10 -> V_412 ) ;
F_24 () ;
V_180 = F_32 ( V_29 -> V_27 -> V_35 ) -> V_100 * V_44 / 10 ;
F_28 () ;
V_180 = F_36 ( V_180 ) ;
F_11 ( & V_10 -> V_412 ) ;
if ( ! V_180 ) {
V_419 = - V_143 ;
F_45 ( V_10 , L_48 ) ;
break;
}
}
F_12 ( & V_10 -> V_412 ) ;
F_37 ( & V_10 -> V_413 , & V_37 ) ;
return V_419 ;
}
static unsigned long F_221 ( T_7 V_422 )
{
return ( V_422 & V_423 ? V_424 : 0 ) |
( V_422 & V_425 ? V_426 : 0 ) |
( V_422 & V_427 ? V_428 : 0 ) ;
}
static unsigned long F_222 ( T_7 V_422 )
{
if ( V_422 & V_429 )
return V_430 ;
else
return V_381 ;
}
static void F_223 ( struct V_9 * V_10 , T_3 V_52 ,
unsigned int V_64 )
{
struct V_334 * V_6 ;
V_431:
F_208 (i, &device->write_requests, sector, size) {
struct V_363 * V_364 ;
struct V_432 V_433 ;
if ( ! V_6 -> T_5 )
continue;
V_364 = F_189 ( V_6 , struct V_363 , V_6 ) ;
if ( ! ( V_364 -> V_392 & V_394 ) )
continue;
V_364 -> V_392 &= ~ V_394 ;
F_209 ( V_364 , V_434 , & V_433 ) ;
F_21 ( & V_10 -> V_24 -> V_25 ) ;
if ( V_433 . V_244 )
F_224 ( V_10 , & V_433 ) ;
F_20 ( & V_10 -> V_24 -> V_25 ) ;
goto V_431;
}
}
static int F_225 ( struct V_9 * V_10 ,
struct V_18 * V_19 )
{
struct V_26 * V_27 = V_19 -> V_29 -> V_27 ;
bool V_435 = F_69 ( V_205 , & V_27 -> V_69 ) ;
T_3 V_52 = V_19 -> V_6 . V_52 ;
const unsigned int V_64 = V_19 -> V_6 . V_64 ;
struct V_334 * V_6 ;
bool V_436 ;
int V_77 ;
F_226 ( & V_10 -> V_335 , & V_19 -> V_6 ) ;
V_431:
F_208 (i, &device->write_requests, sector, size) {
if ( V_6 == & V_19 -> V_6 )
continue;
if ( V_6 -> V_437 )
continue;
if ( ! V_6 -> T_5 ) {
V_77 = F_227 ( V_10 , V_6 ) ;
if ( V_77 )
goto V_104;
goto V_431;
}
V_436 = V_6 -> V_52 == V_52 && V_6 -> V_64 == V_64 ;
if ( V_435 ) {
bool V_438 = V_6 -> V_52 <= V_52 && V_6 -> V_52 +
( V_6 -> V_64 >> 9 ) >= V_52 + ( V_64 >> 9 ) ;
if ( ! V_436 )
F_228 ( V_10 , L_49
L_50
L_51 ,
( unsigned long long ) V_6 -> V_52 , V_6 -> V_64 ,
( unsigned long long ) V_52 , V_64 ,
V_438 ? L_52 : L_53 ) ;
V_19 -> V_20 . V_80 = V_438 ? F_212 :
F_213 ;
F_166 ( & V_19 -> V_20 . V_21 , & V_10 -> V_78 ) ;
F_229 ( V_27 -> V_225 , & V_19 -> V_29 -> V_439 ) ;
V_77 = - V_440 ;
goto V_104;
} else {
struct V_363 * V_364 =
F_189 ( V_6 , struct V_363 , V_6 ) ;
if ( ! V_436 )
F_228 ( V_10 , L_49
L_54 ,
( unsigned long long ) V_6 -> V_52 , V_6 -> V_64 ,
( unsigned long long ) V_52 , V_64 ) ;
if ( V_364 -> V_392 & V_393 ||
! ( V_364 -> V_392 & V_394 ) ) {
V_77 = F_227 ( V_10 , & V_364 -> V_6 ) ;
if ( V_77 ) {
F_230 ( V_27 , F_72 ( V_105 , V_441 ) , V_107 ) ;
F_223 ( V_10 , V_52 , V_64 ) ;
goto V_104;
}
goto V_431;
}
V_19 -> V_69 |= V_405 ;
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
struct V_387 * V_339 = V_172 -> V_96 ;
T_7 V_184 = F_125 ( V_339 -> V_442 ) ;
int V_316 , V_317 ;
T_7 V_443 ;
int V_77 , V_420 ;
V_29 = F_201 ( V_27 , V_172 -> V_30 ) ;
if ( ! V_29 )
return - V_108 ;
V_10 = V_29 -> V_10 ;
if ( ! F_140 ( V_10 ) ) {
int V_79 ;
V_77 = F_220 ( V_29 , V_184 ) ;
F_206 ( V_29 , V_377 , V_339 , V_172 -> V_64 ) ;
F_136 ( & V_27 -> V_281 -> V_270 ) ;
V_79 = F_184 ( V_29 , V_172 -> V_64 ) ;
if ( ! V_77 )
V_77 = V_79 ;
return V_77 ;
}
V_52 = F_202 ( V_339 -> V_52 ) ;
V_19 = F_176 ( V_29 , V_339 -> V_68 , V_52 , V_172 ) ;
if ( ! V_19 ) {
F_130 ( V_10 ) ;
return - V_108 ;
}
V_19 -> V_20 . V_80 = F_210 ;
V_19 -> V_65 = V_66 ;
V_19 -> V_69 |= V_444 ;
V_443 = F_125 ( V_339 -> V_443 ) ;
V_316 = F_222 ( V_443 ) ;
V_317 = F_221 ( V_443 ) ;
if ( V_172 -> V_169 == V_354 ) {
F_53 ( V_29 , V_19 -> V_6 . V_64 > 0 ) ;
F_53 ( V_29 , V_316 == V_430 ) ;
F_53 ( V_29 , V_19 -> V_67 == NULL ) ;
} else if ( V_19 -> V_67 == NULL ) {
F_53 ( V_10 , V_19 -> V_6 . V_64 == 0 ) ;
F_53 ( V_10 , V_443 & V_427 ) ;
}
if ( V_443 & V_445 )
V_19 -> V_69 |= V_402 ;
F_11 ( & V_27 -> V_273 ) ;
V_19 -> V_267 = V_27 -> V_281 ;
F_136 ( & V_19 -> V_267 -> V_270 ) ;
F_136 ( & V_19 -> V_267 -> V_276 ) ;
F_12 ( & V_27 -> V_273 ) ;
F_24 () ;
V_36 = F_32 ( V_29 -> V_27 -> V_35 ) ;
V_420 = V_36 -> V_421 ;
if ( V_29 -> V_27 -> V_186 < 100 ) {
switch ( V_36 -> V_446 ) {
case V_447 :
V_443 |= V_448 ;
break;
case V_449 :
V_443 |= V_450 ;
break;
}
}
F_28 () ;
if ( V_443 & V_448 ) {
V_19 -> V_69 |= V_398 ;
F_197 ( V_10 ) ;
}
if ( V_443 & V_450 ) {
F_192 ( V_29 , V_451 , V_19 ) ;
}
if ( V_420 ) {
F_53 ( V_10 , V_443 & V_448 ) ;
V_19 -> V_69 |= V_404 ;
V_77 = F_220 ( V_29 , V_184 ) ;
if ( V_77 )
goto V_452;
F_20 ( & V_10 -> V_24 -> V_25 ) ;
V_77 = F_225 ( V_10 , V_19 ) ;
if ( V_77 ) {
F_21 ( & V_10 -> V_24 -> V_25 ) ;
if ( V_77 == - V_440 ) {
F_130 ( V_10 ) ;
return 0 ;
}
goto V_452;
}
} else {
F_216 ( V_29 , V_184 ) ;
F_20 ( & V_10 -> V_24 -> V_25 ) ;
}
if ( ( V_19 -> V_69 & ( V_322 | V_323 ) ) == 0 )
F_166 ( & V_19 -> V_20 . V_21 , & V_10 -> V_325 ) ;
F_21 ( & V_10 -> V_24 -> V_25 ) ;
if ( V_10 -> V_399 . V_105 == V_453 )
F_232 ( V_10 -> V_81 , ! F_218 ( V_10 , V_19 ) ) ;
if ( V_10 -> V_399 . V_454 < V_455 ) {
F_233 ( V_10 , V_19 -> V_6 . V_52 , V_19 -> V_6 . V_64 ) ;
V_19 -> V_69 &= ~ V_402 ;
F_234 ( V_10 , & V_19 -> V_6 ) ;
V_19 -> V_69 |= V_73 ;
}
V_77 = F_164 ( V_10 , V_19 , V_316 , V_317 ,
V_456 ) ;
if ( ! V_77 )
return 0 ;
F_45 ( V_10 , L_45 ) ;
F_20 ( & V_10 -> V_24 -> V_25 ) ;
F_147 ( & V_19 -> V_20 . V_21 ) ;
F_170 ( V_10 , V_19 ) ;
F_21 ( & V_10 -> V_24 -> V_25 ) ;
if ( V_19 -> V_69 & V_73 ) {
V_19 -> V_69 &= ~ V_73 ;
F_56 ( V_10 , & V_19 -> V_6 ) ;
}
V_452:
F_143 ( V_27 , V_19 -> V_267 , V_275 | V_274 ) ;
F_130 ( V_10 ) ;
F_60 ( V_10 , V_19 ) ;
return V_77 ;
}
bool F_235 ( struct V_9 * V_10 , T_3 V_52 ,
bool V_457 )
{
struct V_458 * V_4 ;
bool V_459 = F_236 ( V_10 ) ;
if ( ! V_459 || V_457 )
return V_459 ;
F_20 ( & V_10 -> V_460 ) ;
V_4 = F_237 ( V_10 -> V_461 , F_238 ( V_52 ) ) ;
if ( V_4 ) {
struct V_462 * V_463 = F_239 ( V_4 , struct V_462 , V_464 ) ;
if ( F_69 ( V_465 , & V_463 -> V_69 ) )
V_459 = false ;
}
F_21 ( & V_10 -> V_460 ) ;
return V_459 ;
}
bool F_236 ( struct V_9 * V_10 )
{
struct V_466 * V_467 = V_10 -> V_256 -> V_257 -> V_468 -> V_469 ;
unsigned long V_470 , V_471 , V_472 ;
unsigned int V_473 ;
int V_474 ;
F_24 () ;
V_473 = F_32 ( V_10 -> V_256 -> V_290 ) -> V_473 ;
F_28 () ;
if ( V_473 == 0 )
return false ;
V_474 = ( int ) F_240 ( & V_467 -> V_475 , V_476 [ 0 ] ) +
( int ) F_240 ( & V_467 -> V_475 , V_476 [ 1 ] ) -
F_26 ( & V_10 -> V_380 ) ;
if ( F_26 ( & V_10 -> V_477 )
|| V_474 - V_10 -> V_478 > 64 ) {
unsigned long V_479 ;
int V_6 ;
V_10 -> V_478 = V_474 ;
V_6 = ( V_10 -> V_480 + V_481 - 1 ) % V_481 ;
if ( V_10 -> V_399 . V_105 == V_482 || V_10 -> V_399 . V_105 == V_483 )
V_479 = V_10 -> V_484 ;
else
V_479 = F_241 ( V_10 ) - V_10 -> V_485 ;
V_471 = ( ( long ) V_66 - ( long ) V_10 -> V_486 [ V_6 ] ) / V_44 ;
if ( ! V_471 )
V_471 ++ ;
V_470 = V_10 -> V_487 [ V_6 ] - V_479 ;
V_472 = F_242 ( V_470 / V_471 ) ;
if ( V_472 > V_473 )
return true ;
}
return false ;
}
static int F_243 ( struct V_26 * V_27 , struct V_171 * V_172 )
{
struct V_28 * V_29 ;
struct V_9 * V_10 ;
T_3 V_52 ;
T_3 V_344 ;
struct V_18 * V_19 ;
struct V_488 * V_489 = NULL ;
int V_64 , V_490 ;
unsigned int V_318 ;
struct V_491 * V_339 = V_172 -> V_96 ;
V_29 = F_201 ( V_27 , V_172 -> V_30 ) ;
if ( ! V_29 )
return - V_108 ;
V_10 = V_29 -> V_10 ;
V_344 = F_177 ( V_10 -> V_345 ) ;
V_52 = F_202 ( V_339 -> V_52 ) ;
V_64 = F_125 ( V_339 -> V_492 ) ;
if ( V_64 <= 0 || ! F_181 ( V_64 , 512 ) || V_64 > V_48 ) {
F_45 ( V_10 , L_55 , __FILE__ , __LINE__ ,
( unsigned long long ) V_52 , V_64 ) ;
return - V_234 ;
}
if ( V_52 + ( V_64 >> 9 ) > V_344 ) {
F_45 ( V_10 , L_55 , __FILE__ , __LINE__ ,
( unsigned long long ) V_52 , V_64 ) ;
return - V_234 ;
}
if ( ! F_244 ( V_10 , V_493 ) ) {
V_490 = 1 ;
switch ( V_172 -> V_169 ) {
case V_494 :
F_245 ( V_29 , V_495 , V_339 ) ;
break;
case V_496 :
case V_497 :
case V_498 :
case V_499 :
F_245 ( V_29 , V_500 , V_339 ) ;
break;
case V_501 :
V_490 = 0 ;
F_196 ( V_10 ) ;
F_246 ( V_29 , V_502 , V_52 , V_64 , V_503 ) ;
break;
default:
F_247 () ;
}
if ( V_490 && F_205 ( & V_390 ) )
F_45 ( V_10 , L_56
L_57 ) ;
return F_184 ( V_29 , V_172 -> V_64 ) ;
}
V_19 = F_42 ( V_29 , V_339 -> V_68 , V_52 , V_64 ,
V_64 , V_213 ) ;
if ( ! V_19 ) {
F_130 ( V_10 ) ;
return - V_254 ;
}
switch ( V_172 -> V_169 ) {
case V_494 :
V_19 -> V_20 . V_80 = V_504 ;
V_318 = V_505 ;
V_19 -> V_69 |= V_444 ;
goto V_506;
case V_496 :
V_19 -> V_69 |= V_507 ;
case V_497 :
V_19 -> V_20 . V_80 = V_508 ;
V_318 = V_509 ;
V_10 -> V_510 = F_248 ( V_52 ) ;
break;
case V_501 :
case V_498 :
V_318 = V_509 ;
V_489 = F_134 ( sizeof( * V_489 ) + V_172 -> V_64 , V_213 ) ;
if ( ! V_489 )
goto V_511;
V_489 -> V_346 = V_172 -> V_64 ;
V_489 -> V_71 = ( ( ( char * ) V_489 ) + sizeof( struct V_488 ) ) ;
V_19 -> V_71 = V_489 ;
V_19 -> V_69 |= V_70 ;
if ( F_73 ( V_29 -> V_27 , V_489 -> V_71 , V_172 -> V_64 ) )
goto V_511;
if ( V_172 -> V_169 == V_498 ) {
F_53 ( V_10 , V_29 -> V_27 -> V_186 >= 89 ) ;
V_19 -> V_20 . V_80 = V_512 ;
V_10 -> V_510 = F_248 ( V_52 ) ;
V_10 -> V_513 = true ;
} else if ( V_172 -> V_169 == V_501 ) {
F_38 ( V_64 >> 9 , & V_10 -> V_391 ) ;
V_19 -> V_20 . V_80 = V_514 ;
F_196 ( V_10 ) ;
goto V_515;
}
break;
case V_499 :
if ( V_10 -> V_516 == ~ ( T_3 ) 0 &&
V_29 -> V_27 -> V_186 >= 90 ) {
unsigned long V_517 = V_66 ;
int V_6 ;
V_10 -> V_516 = V_52 ;
V_10 -> V_518 = V_52 ;
V_10 -> V_484 = F_249 ( V_10 ) - F_248 ( V_52 ) ;
V_10 -> V_519 = V_10 -> V_484 ;
for ( V_6 = 0 ; V_6 < V_481 ; V_6 ++ ) {
V_10 -> V_487 [ V_6 ] = V_10 -> V_484 ;
V_10 -> V_486 [ V_6 ] = V_517 ;
}
F_68 ( V_10 , L_58 ,
( unsigned long long ) V_52 ) ;
}
V_19 -> V_20 . V_80 = V_520 ;
V_318 = V_509 ;
break;
default:
F_247 () ;
}
F_20 ( & V_10 -> V_24 -> V_25 ) ;
F_166 ( & V_19 -> V_20 . V_21 , & V_10 -> V_521 ) ;
F_21 ( & V_10 -> V_24 -> V_25 ) ;
F_250 ( V_27 , F_235 ) ;
if ( V_10 -> V_399 . V_522 != V_523
&& F_235 ( V_10 , V_52 , false ) )
F_251 ( V_44 / 10 ) ;
F_250 ( V_27 , V_524 ) ;
if ( V_524 ( V_10 , V_52 ) )
goto V_511;
V_515:
F_38 ( V_64 >> 9 , & V_10 -> V_380 ) ;
V_506:
F_250 ( V_27 , F_164 ) ;
F_197 ( V_10 ) ;
if ( F_164 ( V_10 , V_19 , V_525 , 0 ,
V_318 ) == 0 )
return 0 ;
F_45 ( V_10 , L_45 ) ;
V_511:
F_20 ( & V_10 -> V_24 -> V_25 ) ;
F_147 ( & V_19 -> V_20 . V_21 ) ;
F_21 ( & V_10 -> V_24 -> V_25 ) ;
F_130 ( V_10 ) ;
F_60 ( V_10 , V_19 ) ;
return - V_108 ;
}
static int F_252 ( struct V_28 * V_29 ) __must_hold( T_5 )
{
struct V_9 * V_10 = V_29 -> V_10 ;
int V_526 , V_522 , V_95 = - 100 ;
unsigned long V_527 , V_528 ;
enum V_529 V_530 ;
V_526 = V_10 -> V_256 -> V_531 . V_532 [ V_533 ] & 1 ;
V_522 = V_10 -> V_534 [ V_533 ] & 1 ;
V_528 = V_10 -> V_534 [ V_535 ] ;
V_527 = V_10 -> V_536 ;
F_24 () ;
V_530 = F_32 ( V_29 -> V_27 -> V_35 ) -> V_530 ;
F_28 () ;
switch ( V_530 ) {
case V_537 :
case V_538 :
case V_539 :
case V_540 :
F_45 ( V_10 , L_59 ) ;
break;
case V_541 :
break;
case V_542 :
if ( V_526 == 0 && V_522 == 1 ) {
V_95 = - 1 ;
break;
}
if ( V_526 == 1 && V_522 == 0 ) {
V_95 = 1 ;
break;
}
case V_543 :
if ( V_526 == 0 && V_522 == 1 ) {
V_95 = 1 ;
break;
}
if ( V_526 == 1 && V_522 == 0 ) {
V_95 = - 1 ;
break;
}
F_35 ( V_10 , L_60
L_61 ) ;
case V_544 :
if ( V_528 == 0 && V_527 == 0 ) {
V_95 = F_69 ( V_205 , & V_29 -> V_27 -> V_69 )
? - 1 : 1 ;
break;
} else {
if ( V_528 == 0 ) { V_95 = 1 ; break; }
if ( V_527 == 0 ) { V_95 = - 1 ; break; }
}
if ( V_530 == V_544 )
break;
case V_545 :
if ( V_527 < V_528 )
V_95 = - 1 ;
else if ( V_527 > V_528 )
V_95 = 1 ;
else
V_95 = F_69 ( V_205 , & V_29 -> V_27 -> V_69 )
? - 1 : 1 ;
break;
case V_546 :
V_95 = - 1 ;
break;
case V_547 :
V_95 = 1 ;
}
return V_95 ;
}
static int F_253 ( struct V_28 * V_29 ) __must_hold( T_5 )
{
struct V_9 * V_10 = V_29 -> V_10 ;
int V_548 , V_95 = - 100 ;
enum V_529 V_549 ;
F_24 () ;
V_549 = F_32 ( V_29 -> V_27 -> V_35 ) -> V_549 ;
F_28 () ;
switch ( V_549 ) {
case V_542 :
case V_543 :
case V_545 :
case V_546 :
case V_547 :
case V_544 :
F_45 ( V_10 , L_59 ) ;
break;
case V_541 :
break;
case V_537 :
V_548 = F_252 ( V_29 ) ;
if ( V_548 == - 1 && V_10 -> V_399 . V_550 == V_551 )
V_95 = V_548 ;
if ( V_548 == 1 && V_10 -> V_399 . V_550 == V_523 )
V_95 = V_548 ;
break;
case V_540 :
V_95 = F_252 ( V_29 ) ;
break;
case V_538 :
return V_10 -> V_399 . V_550 == V_523 ? 1 : - 1 ;
case V_539 :
V_548 = F_252 ( V_29 ) ;
if ( V_548 == - 1 && V_10 -> V_399 . V_550 == V_523 ) {
enum V_196 V_552 ;
V_552 = F_254 ( V_10 , V_198 , F_72 ( V_550 , V_551 ) ) ;
if ( V_552 != V_199 ) {
F_255 ( V_10 , L_62 ) ;
} else {
F_35 ( V_10 , L_63 ) ;
V_95 = V_548 ;
}
} else
V_95 = V_548 ;
}
return V_95 ;
}
static int F_256 ( struct V_28 * V_29 ) __must_hold( T_5 )
{
struct V_9 * V_10 = V_29 -> V_10 ;
int V_548 , V_95 = - 100 ;
enum V_529 V_553 ;
F_24 () ;
V_553 = F_32 ( V_29 -> V_27 -> V_35 ) -> V_553 ;
F_28 () ;
switch ( V_553 ) {
case V_542 :
case V_543 :
case V_545 :
case V_546 :
case V_547 :
case V_537 :
case V_538 :
case V_544 :
F_45 ( V_10 , L_59 ) ;
break;
case V_540 :
V_95 = F_252 ( V_29 ) ;
break;
case V_541 :
break;
case V_539 :
V_548 = F_252 ( V_29 ) ;
if ( V_548 == - 1 ) {
enum V_196 V_552 ;
V_552 = F_254 ( V_10 , V_198 , F_72 ( V_550 , V_551 ) ) ;
if ( V_552 != V_199 ) {
F_255 ( V_10 , L_62 ) ;
} else {
F_35 ( V_10 , L_63 ) ;
V_95 = V_548 ;
}
} else
V_95 = V_548 ;
}
return V_95 ;
}
static void F_257 ( struct V_9 * V_10 , char * V_554 , T_2 * V_532 ,
T_2 V_555 , T_2 V_69 )
{
if ( ! V_532 ) {
F_68 ( V_10 , L_64 , V_554 ) ;
return;
}
F_68 ( V_10 , L_65 ,
V_554 ,
( unsigned long long ) V_532 [ V_556 ] ,
( unsigned long long ) V_532 [ V_533 ] ,
( unsigned long long ) V_532 [ V_557 ] ,
( unsigned long long ) V_532 [ V_558 ] ,
( unsigned long long ) V_555 ,
( unsigned long long ) V_69 ) ;
}
static int F_258 ( struct V_9 * const V_10 , enum V_559 const V_560 , int * V_561 ) __must_hold( T_5 )
{
struct V_28 * const V_29 = F_259 ( V_10 ) ;
struct V_26 * const V_27 = V_29 ? V_29 -> V_27 : NULL ;
T_2 V_526 , V_522 ;
int V_6 , V_562 ;
V_526 = V_10 -> V_256 -> V_531 . V_532 [ V_556 ] & ~ ( ( T_2 ) 1 ) ;
V_522 = V_10 -> V_534 [ V_556 ] & ~ ( ( T_2 ) 1 ) ;
* V_561 = 10 ;
if ( V_526 == V_563 && V_522 == V_563 )
return 0 ;
* V_561 = 20 ;
if ( ( V_526 == V_563 || V_526 == ( T_2 ) 0 ) &&
V_522 != V_563 )
return - 2 ;
* V_561 = 30 ;
if ( V_526 != V_563 &&
( V_522 == V_563 || V_522 == ( T_2 ) 0 ) )
return 2 ;
if ( V_526 == V_522 ) {
int V_564 , V_291 ;
if ( V_10 -> V_534 [ V_533 ] == ( T_2 ) 0 && V_10 -> V_256 -> V_531 . V_532 [ V_533 ] != ( T_2 ) 0 ) {
if ( V_27 -> V_186 < 91 )
return - 1091 ;
if ( ( V_10 -> V_256 -> V_531 . V_532 [ V_533 ] & ~ ( ( T_2 ) 1 ) ) == ( V_10 -> V_534 [ V_557 ] & ~ ( ( T_2 ) 1 ) ) &&
( V_10 -> V_256 -> V_531 . V_532 [ V_557 ] & ~ ( ( T_2 ) 1 ) ) == ( V_10 -> V_534 [ V_557 + 1 ] & ~ ( ( T_2 ) 1 ) ) ) {
F_68 ( V_10 , L_66 ) ;
F_260 ( V_10 ) ;
V_10 -> V_256 -> V_531 . V_532 [ V_557 ] = V_10 -> V_256 -> V_531 . V_532 [ V_533 ] ;
V_10 -> V_256 -> V_531 . V_532 [ V_533 ] = 0 ;
F_257 ( V_10 , L_67 , V_10 -> V_256 -> V_531 . V_532 ,
V_10 -> V_399 . V_467 >= V_565 ? F_241 ( V_10 ) : 0 , 0 ) ;
* V_561 = 34 ;
} else {
F_68 ( V_10 , L_68 ) ;
* V_561 = 36 ;
}
return 1 ;
}
if ( V_10 -> V_256 -> V_531 . V_532 [ V_533 ] == ( T_2 ) 0 && V_10 -> V_534 [ V_533 ] != ( T_2 ) 0 ) {
if ( V_27 -> V_186 < 91 )
return - 1091 ;
if ( ( V_10 -> V_256 -> V_531 . V_532 [ V_557 ] & ~ ( ( T_2 ) 1 ) ) == ( V_10 -> V_534 [ V_533 ] & ~ ( ( T_2 ) 1 ) ) &&
( V_10 -> V_256 -> V_531 . V_532 [ V_557 + 1 ] & ~ ( ( T_2 ) 1 ) ) == ( V_10 -> V_534 [ V_557 ] & ~ ( ( T_2 ) 1 ) ) ) {
F_68 ( V_10 , L_69 ) ;
V_10 -> V_534 [ V_557 + 1 ] = V_10 -> V_534 [ V_557 ] ;
V_10 -> V_534 [ V_557 ] = V_10 -> V_534 [ V_533 ] ;
V_10 -> V_534 [ V_533 ] = 0UL ;
F_257 ( V_10 , L_70 , V_10 -> V_534 , V_10 -> V_534 [ V_535 ] , V_10 -> V_534 [ V_566 ] ) ;
* V_561 = 35 ;
} else {
F_68 ( V_10 , L_71 ) ;
* V_561 = 37 ;
}
return - 1 ;
}
V_564 = ( F_69 ( V_567 , & V_10 -> V_69 ) ? 1 : 0 ) +
( V_10 -> V_534 [ V_566 ] & 2 ) ;
* V_561 = 40 ;
if ( V_564 == 0 )
return 0 ;
if ( V_10 -> V_399 . V_550 == V_523 || V_560 == V_523 ) {
* V_561 = 41 ;
if ( ! ( V_27 -> V_568 & V_569 ) ) {
F_35 ( V_29 , L_72 ) ;
return - ( 0x10000 | V_570 | ( V_569 << 8 ) ) ;
}
if ( V_10 -> V_399 . V_550 == V_523 && V_560 == V_523 ) {
F_45 ( V_29 , L_73 ) ;
return - 100 ;
}
if ( V_10 -> V_399 . V_550 == V_523 )
return 1 ;
return - 1 ;
}
switch ( V_564 ) {
case 0 : return 0 ;
case 1 : return 1 ;
case 2 : return - 1 ;
case 3 :
V_291 = F_69 ( V_205 , & V_27 -> V_69 ) ;
return V_291 ? - 1 : 1 ;
}
}
* V_561 = 50 ;
V_522 = V_10 -> V_534 [ V_533 ] & ~ ( ( T_2 ) 1 ) ;
if ( V_526 == V_522 )
return - 1 ;
* V_561 = 51 ;
V_522 = V_10 -> V_534 [ V_557 ] & ~ ( ( T_2 ) 1 ) ;
if ( V_526 == V_522 ) {
if ( V_27 -> V_186 < 96 ?
( V_10 -> V_256 -> V_531 . V_532 [ V_557 ] & ~ ( ( T_2 ) 1 ) ) ==
( V_10 -> V_534 [ V_557 + 1 ] & ~ ( ( T_2 ) 1 ) ) :
V_522 + V_571 == ( V_10 -> V_534 [ V_533 ] & ~ ( ( T_2 ) 1 ) ) ) {
if ( V_27 -> V_186 < 91 )
return - 1091 ;
V_10 -> V_534 [ V_533 ] = V_10 -> V_534 [ V_557 ] ;
V_10 -> V_534 [ V_557 ] = V_10 -> V_534 [ V_557 + 1 ] ;
F_68 ( V_10 , L_74 ) ;
F_257 ( V_10 , L_70 , V_10 -> V_534 , V_10 -> V_534 [ V_535 ] , V_10 -> V_534 [ V_566 ] ) ;
return - 1 ;
}
}
* V_561 = 60 ;
V_526 = V_10 -> V_256 -> V_531 . V_532 [ V_556 ] & ~ ( ( T_2 ) 1 ) ;
for ( V_6 = V_557 ; V_6 <= V_558 ; V_6 ++ ) {
V_522 = V_10 -> V_534 [ V_6 ] & ~ ( ( T_2 ) 1 ) ;
if ( V_526 == V_522 )
return - 2 ;
}
* V_561 = 70 ;
V_526 = V_10 -> V_256 -> V_531 . V_532 [ V_533 ] & ~ ( ( T_2 ) 1 ) ;
V_522 = V_10 -> V_534 [ V_556 ] & ~ ( ( T_2 ) 1 ) ;
if ( V_526 == V_522 )
return 1 ;
* V_561 = 71 ;
V_526 = V_10 -> V_256 -> V_531 . V_532 [ V_557 ] & ~ ( ( T_2 ) 1 ) ;
if ( V_526 == V_522 ) {
if ( V_27 -> V_186 < 96 ?
( V_10 -> V_256 -> V_531 . V_532 [ V_557 + 1 ] & ~ ( ( T_2 ) 1 ) ) ==
( V_10 -> V_534 [ V_557 ] & ~ ( ( T_2 ) 1 ) ) :
V_526 + V_571 == ( V_10 -> V_256 -> V_531 . V_532 [ V_533 ] & ~ ( ( T_2 ) 1 ) ) ) {
if ( V_27 -> V_186 < 91 )
return - 1091 ;
F_261 ( V_10 , V_533 , V_10 -> V_256 -> V_531 . V_532 [ V_557 ] ) ;
F_261 ( V_10 , V_557 , V_10 -> V_256 -> V_531 . V_532 [ V_557 + 1 ] ) ;
F_68 ( V_10 , L_75 ) ;
F_257 ( V_10 , L_67 , V_10 -> V_256 -> V_531 . V_532 ,
V_10 -> V_399 . V_467 >= V_565 ? F_241 ( V_10 ) : 0 , 0 ) ;
return 1 ;
}
}
* V_561 = 80 ;
V_522 = V_10 -> V_534 [ V_556 ] & ~ ( ( T_2 ) 1 ) ;
for ( V_6 = V_557 ; V_6 <= V_558 ; V_6 ++ ) {
V_526 = V_10 -> V_256 -> V_531 . V_532 [ V_6 ] & ~ ( ( T_2 ) 1 ) ;
if ( V_526 == V_522 )
return 2 ;
}
* V_561 = 90 ;
V_526 = V_10 -> V_256 -> V_531 . V_532 [ V_533 ] & ~ ( ( T_2 ) 1 ) ;
V_522 = V_10 -> V_534 [ V_533 ] & ~ ( ( T_2 ) 1 ) ;
if ( V_526 == V_522 && V_526 != ( ( T_2 ) 0 ) )
return 100 ;
* V_561 = 100 ;
for ( V_6 = V_557 ; V_6 <= V_558 ; V_6 ++ ) {
V_526 = V_10 -> V_256 -> V_531 . V_532 [ V_6 ] & ~ ( ( T_2 ) 1 ) ;
for ( V_562 = V_557 ; V_562 <= V_558 ; V_562 ++ ) {
V_522 = V_10 -> V_534 [ V_562 ] & ~ ( ( T_2 ) 1 ) ;
if ( V_526 == V_522 )
return - 100 ;
}
}
return - 1000 ;
}
static enum V_572 F_262 ( struct V_28 * V_29 ,
enum V_559 V_560 ,
enum V_573 V_574 ) __must_hold( T_5 )
{
struct V_9 * V_10 = V_29 -> V_10 ;
enum V_572 V_95 = V_575 ;
enum V_573 V_576 ;
struct V_35 * V_36 ;
int V_548 , V_561 , V_577 , V_578 ;
V_576 = V_10 -> V_399 . V_467 ;
if ( V_576 == V_565 )
V_576 = V_10 -> V_579 . V_467 ;
F_68 ( V_10 , L_76 ) ;
F_20 ( & V_10 -> V_256 -> V_531 . V_580 ) ;
F_257 ( V_10 , L_67 , V_10 -> V_256 -> V_531 . V_532 , V_10 -> V_536 , 0 ) ;
F_257 ( V_10 , L_70 , V_10 -> V_534 ,
V_10 -> V_534 [ V_535 ] , V_10 -> V_534 [ V_566 ] ) ;
V_548 = F_258 ( V_10 , V_560 , & V_561 ) ;
F_21 ( & V_10 -> V_256 -> V_531 . V_580 ) ;
F_68 ( V_10 , L_77 , V_548 , V_561 ) ;
if ( V_548 == - 1000 ) {
F_228 ( V_10 , L_78 ) ;
return V_575 ;
}
if ( V_548 < - 0x10000 ) {
int V_581 , V_582 ;
V_548 = - V_548 ;
V_581 = V_548 & 0xff ;
V_582 = ( V_548 >> 8 ) & 0xff ;
F_228 ( V_10 , L_79 ,
V_581 , V_582 ) ;
return V_575 ;
}
if ( V_548 < - 1000 ) {
F_228 ( V_10 , L_80 , - V_548 - 1000 ) ;
return V_575 ;
}
if ( ( V_576 == V_455 && V_574 > V_455 ) ||
( V_574 == V_455 && V_576 > V_455 ) ) {
int V_583 = ( V_548 == - 100 ) || abs ( V_548 ) == 2 ;
V_548 = V_576 > V_455 ? 1 : - 1 ;
if ( V_583 )
V_548 = V_548 * 2 ;
F_68 ( V_10 , L_81 ,
V_548 > 0 ? L_82 : L_83 ) ;
}
if ( abs ( V_548 ) == 100 )
F_255 ( V_10 , L_84 ) ;
F_24 () ;
V_36 = F_32 ( V_29 -> V_27 -> V_35 ) ;
if ( V_548 == 100 || ( V_548 == - 100 && V_36 -> V_584 ) ) {
int V_585 = ( V_10 -> V_399 . V_550 == V_523 )
+ ( V_560 == V_523 ) ;
int V_586 = ( V_548 == - 100 ) ;
switch ( V_585 ) {
case 0 :
V_548 = F_252 ( V_29 ) ;
break;
case 1 :
V_548 = F_253 ( V_29 ) ;
break;
case 2 :
V_548 = F_256 ( V_29 ) ;
break;
}
if ( abs ( V_548 ) < 100 ) {
F_35 ( V_10 , L_85
L_86 ,
V_585 , ( V_548 < 0 ) ? L_70 : L_87 ) ;
if ( V_586 ) {
F_35 ( V_10 , L_88
L_89 ) ;
V_548 = V_548 * 2 ;
}
}
}
if ( V_548 == - 100 ) {
if ( F_69 ( V_223 , & V_10 -> V_69 ) && ! ( V_10 -> V_534 [ V_566 ] & 1 ) )
V_548 = - 1 ;
if ( ! F_69 ( V_223 , & V_10 -> V_69 ) && ( V_10 -> V_534 [ V_566 ] & 1 ) )
V_548 = 1 ;
if ( abs ( V_548 ) < 100 )
F_35 ( V_10 , L_90
L_91 ,
( V_548 < 0 ) ? L_70 : L_87 ) ;
}
V_577 = V_36 -> V_577 ;
V_578 = V_36 -> V_578 ;
F_28 () ;
if ( V_548 == - 100 ) {
F_228 ( V_10 , L_92 ) ;
F_255 ( V_10 , L_93 ) ;
return V_575 ;
}
if ( V_548 > 0 && V_576 <= V_455 ) {
F_45 ( V_10 , L_94 ) ;
return V_575 ;
}
if ( V_548 < 0 &&
V_10 -> V_399 . V_550 == V_523 && V_10 -> V_399 . V_467 >= V_587 ) {
switch ( V_577 ) {
case V_539 :
F_255 ( V_10 , L_95 ) ;
case V_541 :
F_45 ( V_10 , L_96 ) ;
return V_575 ;
case V_540 :
F_35 ( V_10 , L_97
L_98 ) ;
}
}
if ( V_578 || F_69 ( V_588 , & V_29 -> V_27 -> V_69 ) ) {
if ( V_548 == 0 )
F_68 ( V_10 , L_99 ) ;
else
F_68 ( V_10 , L_100 ,
F_263 ( V_548 > 0 ? V_400 : V_453 ) ,
abs ( V_548 ) >= 2 ? L_101 : L_102 ) ;
return V_575 ;
}
if ( abs ( V_548 ) >= 2 ) {
F_68 ( V_10 , L_103 ) ;
if ( F_264 ( V_10 , & V_589 , L_104 ,
V_590 ) )
return V_575 ;
}
if ( V_548 > 0 ) {
V_95 = V_591 ;
} else if ( V_548 < 0 ) {
V_95 = V_592 ;
} else {
V_95 = V_593 ;
if ( F_241 ( V_10 ) ) {
F_68 ( V_10 , L_105 ,
F_241 ( V_10 ) ) ;
}
}
return V_95 ;
}
static enum V_529 F_265 ( enum V_529 V_522 )
{
if ( V_522 == V_547 )
return V_546 ;
if ( V_522 == V_546 )
return V_547 ;
return V_522 ;
}
static int F_266 ( struct V_26 * V_27 , struct V_171 * V_172 )
{
struct V_594 * V_339 = V_172 -> V_96 ;
enum V_529 V_595 , V_596 , V_597 ;
int V_598 , V_599 , V_600 , V_601 ;
struct V_35 * V_36 , * V_602 , * V_603 = NULL ;
char V_604 [ V_605 ] = L_106 ;
struct V_341 * V_357 = NULL ;
void * V_349 = NULL , * V_351 = NULL ;
V_598 = F_125 ( V_339 -> V_606 ) ;
V_595 = F_125 ( V_339 -> V_530 ) ;
V_596 = F_125 ( V_339 -> V_549 ) ;
V_597 = F_125 ( V_339 -> V_553 ) ;
V_600 = F_125 ( V_339 -> V_421 ) ;
V_601 = F_125 ( V_339 -> V_607 ) ;
V_599 = V_601 & V_608 ;
if ( V_27 -> V_186 >= 87 ) {
int V_77 ;
if ( V_172 -> V_64 > sizeof( V_604 ) )
return - V_108 ;
V_77 = F_73 ( V_27 , V_604 , V_172 -> V_64 ) ;
if ( V_77 )
return V_77 ;
V_604 [ V_605 - 1 ] = 0 ;
}
if ( V_172 -> V_169 != V_609 ) {
F_106 ( V_588 , & V_27 -> V_69 ) ;
if ( V_601 & V_610 )
F_111 ( V_588 , & V_27 -> V_69 ) ;
F_24 () ;
V_36 = F_32 ( V_27 -> V_35 ) ;
if ( V_598 != V_36 -> V_446 ) {
F_45 ( V_27 , L_107 , L_108 ) ;
goto V_611;
}
if ( F_265 ( V_595 ) != V_36 -> V_530 ) {
F_45 ( V_27 , L_107 , L_109 ) ;
goto V_611;
}
if ( F_265 ( V_596 ) != V_36 -> V_549 ) {
F_45 ( V_27 , L_107 , L_110 ) ;
goto V_611;
}
if ( F_265 ( V_597 ) != V_36 -> V_553 ) {
F_45 ( V_27 , L_107 , L_111 ) ;
goto V_611;
}
if ( V_599 && V_36 -> V_195 ) {
F_45 ( V_27 , L_107 , L_112 ) ;
goto V_611;
}
if ( V_600 != V_36 -> V_421 ) {
F_45 ( V_27 , L_107 , L_113 ) ;
goto V_611;
}
if ( strcmp ( V_604 , V_36 -> V_604 ) ) {
F_45 ( V_27 , L_107 , L_114 ) ;
goto V_611;
}
F_28 () ;
}
if ( V_604 [ 0 ] ) {
int V_612 ;
V_357 = F_267 ( V_604 , 0 , V_613 ) ;
if ( F_268 ( V_357 ) ) {
V_357 = NULL ;
F_45 ( V_27 , L_115 ,
V_604 ) ;
goto V_614;
}
V_612 = F_178 ( V_357 ) ;
V_349 = F_134 ( V_612 , V_615 ) ;
V_351 = F_134 ( V_612 , V_615 ) ;
if ( ! ( V_349 && V_351 ) ) {
F_45 ( V_27 , L_116 ) ;
goto V_614;
}
}
V_603 = F_134 ( sizeof( struct V_35 ) , V_615 ) ;
if ( ! V_603 ) {
F_45 ( V_27 , L_117 ) ;
goto V_614;
}
F_119 ( & V_27 -> V_96 . V_200 ) ;
F_119 ( & V_27 -> V_24 -> V_228 ) ;
V_602 = V_27 -> V_35 ;
* V_603 = * V_602 ;
V_603 -> V_446 = V_598 ;
V_603 -> V_530 = F_265 ( V_595 ) ;
V_603 -> V_549 = F_265 ( V_596 ) ;
V_603 -> V_553 = F_265 ( V_597 ) ;
V_603 -> V_421 = V_600 ;
F_269 ( V_27 -> V_35 , V_603 ) ;
F_120 ( & V_27 -> V_24 -> V_228 ) ;
F_120 ( & V_27 -> V_96 . V_200 ) ;
F_270 ( V_27 -> V_357 ) ;
F_52 ( V_27 -> V_349 ) ;
F_52 ( V_27 -> V_351 ) ;
V_27 -> V_357 = V_357 ;
V_27 -> V_349 = V_349 ;
V_27 -> V_351 = V_351 ;
if ( strcmp ( V_602 -> V_604 , V_604 ) )
F_68 ( V_27 , L_118 ,
V_604 [ 0 ] ? V_604 : L_119 ) ;
F_271 () ;
F_52 ( V_602 ) ;
return 0 ;
V_611:
F_28 () ;
V_614:
F_270 ( V_357 ) ;
F_52 ( V_349 ) ;
F_52 ( V_351 ) ;
F_71 ( V_27 , F_72 ( V_105 , V_151 ) , V_107 ) ;
return - V_108 ;
}
static struct V_341 * F_272 ( const struct V_9 * V_10 ,
const char * V_616 , const char * V_227 )
{
struct V_341 * V_617 ;
if ( ! V_616 [ 0 ] )
return NULL ;
V_617 = F_267 ( V_616 , 0 , V_613 ) ;
if ( F_268 ( V_617 ) ) {
F_45 ( V_10 , L_120 ,
V_616 , V_227 , F_273 ( V_617 ) ) ;
return V_617 ;
}
return V_617 ;
}
static int F_274 ( struct V_26 * V_27 , struct V_171 * V_172 )
{
void * V_243 = V_27 -> V_96 . V_173 ;
int V_64 = V_172 -> V_64 ;
while ( V_64 ) {
int V_203 = F_77 ( int , V_64 , V_618 ) ;
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
F_35 ( V_27 , L_121 ,
F_276 ( V_172 -> V_169 ) , V_172 -> V_30 ) ;
return F_274 ( V_27 , V_172 ) ;
}
static int F_277 ( struct V_26 * V_27 , struct V_171 * V_172 )
{
struct V_28 * V_29 ;
struct V_9 * V_10 ;
struct V_619 * V_339 ;
unsigned int V_170 , V_320 , V_620 ;
struct V_341 * V_621 = NULL ;
struct V_341 * V_622 = NULL ;
struct V_35 * V_602 , * V_603 = NULL ;
struct V_290 * V_623 = NULL , * V_624 = NULL ;
const int V_625 = V_27 -> V_186 ;
struct V_626 * V_627 = NULL , * V_628 = NULL ;
int V_629 = 0 ;
int V_77 ;
V_29 = F_201 ( V_27 , V_172 -> V_30 ) ;
if ( ! V_29 )
return F_275 ( V_27 , V_172 ) ;
V_10 = V_29 -> V_10 ;
V_620 = V_625 <= 87 ? sizeof( struct V_630 )
: V_625 == 88 ? sizeof( struct V_630 )
+ V_605
: V_625 <= 94 ? sizeof( struct V_631 )
: sizeof( struct V_619 ) ;
if ( V_172 -> V_64 > V_620 ) {
F_45 ( V_10 , L_122 ,
V_172 -> V_64 , V_620 ) ;
return - V_108 ;
}
if ( V_625 <= 88 ) {
V_170 = sizeof( struct V_630 ) ;
V_320 = V_172 -> V_64 - V_170 ;
} else if ( V_625 <= 94 ) {
V_170 = sizeof( struct V_631 ) ;
V_320 = V_172 -> V_64 - V_170 ;
F_53 ( V_10 , V_320 == 0 ) ;
} else {
V_170 = sizeof( struct V_619 ) ;
V_320 = V_172 -> V_64 - V_170 ;
F_53 ( V_10 , V_320 == 0 ) ;
}
V_339 = V_172 -> V_96 ;
memset ( V_339 -> V_632 , 0 , 2 * V_605 ) ;
V_77 = F_73 ( V_29 -> V_27 , V_339 , V_170 ) ;
if ( V_77 )
return V_77 ;
F_119 ( & V_27 -> V_24 -> V_228 ) ;
V_602 = V_29 -> V_27 -> V_35 ;
if ( F_140 ( V_10 ) ) {
V_624 = F_278 ( sizeof( struct V_290 ) , V_615 ) ;
if ( ! V_624 ) {
F_130 ( V_10 ) ;
F_120 ( & V_27 -> V_24 -> V_228 ) ;
F_45 ( V_10 , L_123 ) ;
return - V_254 ;
}
V_623 = V_10 -> V_256 -> V_290 ;
* V_624 = * V_623 ;
V_624 -> V_633 = F_125 ( V_339 -> V_633 ) ;
}
if ( V_625 >= 88 ) {
if ( V_625 == 88 ) {
if ( V_320 > V_605 || V_320 == 0 ) {
F_45 ( V_10 , L_124
L_125 ,
V_320 , V_605 ) ;
V_77 = - V_108 ;
goto V_634;
}
V_77 = F_73 ( V_29 -> V_27 , V_339 -> V_632 , V_320 ) ;
if ( V_77 )
goto V_634;
F_53 ( V_10 , V_339 -> V_632 [ V_320 - 1 ] == 0 ) ;
V_339 -> V_632 [ V_320 - 1 ] = 0 ;
} else {
F_53 ( V_10 , V_339 -> V_632 [ V_605 - 1 ] == 0 ) ;
F_53 ( V_10 , V_339 -> V_635 [ V_605 - 1 ] == 0 ) ;
V_339 -> V_632 [ V_605 - 1 ] = 0 ;
V_339 -> V_635 [ V_605 - 1 ] = 0 ;
}
if ( strcmp ( V_602 -> V_632 , V_339 -> V_632 ) ) {
if ( V_10 -> V_399 . V_105 == V_103 ) {
F_45 ( V_10 , L_126 ,
V_602 -> V_632 , V_339 -> V_632 ) ;
goto V_614;
}
V_621 = F_272 ( V_10 ,
V_339 -> V_632 , L_127 ) ;
if ( F_268 ( V_621 ) ) {
V_621 = NULL ;
goto V_614;
}
}
if ( V_625 >= 89 && strcmp ( V_602 -> V_635 , V_339 -> V_635 ) ) {
if ( V_10 -> V_399 . V_105 == V_103 ) {
F_45 ( V_10 , L_128 ,
V_602 -> V_635 , V_339 -> V_635 ) ;
goto V_614;
}
V_622 = F_272 ( V_10 ,
V_339 -> V_635 , L_129 ) ;
if ( F_268 ( V_622 ) ) {
V_622 = NULL ;
goto V_614;
}
}
if ( V_625 > 94 && V_624 ) {
V_624 -> V_636 = F_125 ( V_339 -> V_636 ) ;
V_624 -> V_637 = F_125 ( V_339 -> V_637 ) ;
V_624 -> V_638 = F_125 ( V_339 -> V_638 ) ;
V_624 -> V_639 = F_125 ( V_339 -> V_639 ) ;
V_629 = ( V_624 -> V_636 * 10 * V_640 ) / V_44 ;
if ( V_629 != V_10 -> V_641 -> V_64 ) {
V_628 = F_279 ( V_629 ) ;
if ( ! V_628 ) {
F_45 ( V_10 , L_130 ) ;
F_130 ( V_10 ) ;
goto V_614;
}
}
}
if ( V_621 || V_622 ) {
V_603 = F_278 ( sizeof( struct V_35 ) , V_615 ) ;
if ( ! V_603 ) {
F_45 ( V_10 , L_117 ) ;
goto V_614;
}
* V_603 = * V_602 ;
if ( V_621 ) {
strcpy ( V_603 -> V_632 , V_339 -> V_632 ) ;
V_603 -> V_642 = strlen ( V_339 -> V_632 ) + 1 ;
F_270 ( V_29 -> V_27 -> V_621 ) ;
V_29 -> V_27 -> V_621 = V_621 ;
F_68 ( V_10 , L_131 , V_339 -> V_632 ) ;
}
if ( V_622 ) {
strcpy ( V_603 -> V_635 , V_339 -> V_635 ) ;
V_603 -> V_643 = strlen ( V_339 -> V_635 ) + 1 ;
F_270 ( V_29 -> V_27 -> V_622 ) ;
V_29 -> V_27 -> V_622 = V_622 ;
F_68 ( V_10 , L_132 , V_339 -> V_635 ) ;
}
F_269 ( V_27 -> V_35 , V_603 ) ;
}
}
if ( V_624 ) {
F_269 ( V_10 -> V_256 -> V_290 , V_624 ) ;
F_130 ( V_10 ) ;
}
if ( V_628 ) {
V_627 = V_10 -> V_641 ;
F_269 ( V_10 -> V_641 , V_628 ) ;
}
F_120 ( & V_27 -> V_24 -> V_228 ) ;
F_271 () ;
if ( V_603 )
F_52 ( V_602 ) ;
F_52 ( V_623 ) ;
F_52 ( V_627 ) ;
return 0 ;
V_634:
if ( V_624 ) {
F_130 ( V_10 ) ;
F_52 ( V_624 ) ;
}
F_120 ( & V_27 -> V_24 -> V_228 ) ;
return - V_108 ;
V_614:
F_52 ( V_628 ) ;
if ( V_624 ) {
F_130 ( V_10 ) ;
F_52 ( V_624 ) ;
}
F_120 ( & V_27 -> V_24 -> V_228 ) ;
F_270 ( V_622 ) ;
F_270 ( V_621 ) ;
F_71 ( V_29 -> V_27 , F_72 ( V_105 , V_151 ) , V_107 ) ;
return - V_108 ;
}
static void F_280 ( struct V_9 * V_10 ,
const char * V_203 , T_3 V_47 , T_3 V_409 )
{
T_3 V_343 ;
if ( V_47 == 0 || V_409 == 0 )
return;
V_343 = ( V_47 > V_409 ) ? ( V_47 - V_409 ) : ( V_409 - V_47 ) ;
if ( V_343 > ( V_47 >> 3 ) || V_343 > ( V_409 >> 3 ) )
F_35 ( V_10 , L_133 , V_203 ,
( unsigned long long ) V_47 , ( unsigned long long ) V_409 ) ;
}
static int F_281 ( struct V_26 * V_27 , struct V_171 * V_172 )
{
struct V_28 * V_29 ;
struct V_9 * V_10 ;
struct V_644 * V_339 = V_172 -> V_96 ;
struct V_645 * V_646 = ( V_27 -> V_568 & V_569 ) ? V_339 -> V_647 : NULL ;
enum V_648 V_649 = V_650 ;
T_3 V_651 , V_652 , V_653 , V_654 ;
int V_655 = 0 ;
enum V_656 V_657 ;
V_29 = F_201 ( V_27 , V_172 -> V_30 ) ;
if ( ! V_29 )
return F_275 ( V_27 , V_172 ) ;
V_10 = V_29 -> V_10 ;
V_651 = F_202 ( V_339 -> V_658 ) ;
V_652 = F_202 ( V_339 -> V_659 ) ;
V_653 = F_202 ( V_339 -> V_660 ) ;
V_10 -> V_651 = V_651 ;
if ( F_140 ( V_10 ) ) {
T_3 V_661 , V_662 ;
F_24 () ;
V_654 = F_32 ( V_10 -> V_256 -> V_290 ) -> V_663 ;
F_28 () ;
F_280 ( V_10 , L_134 ,
V_651 , F_282 ( V_10 -> V_256 ) ) ;
F_280 ( V_10 , L_135 ,
V_652 , V_654 ) ;
if ( V_10 -> V_399 . V_105 == V_103 )
V_652 = F_283 ( V_654 , V_652 ) ;
V_661 = F_284 ( V_10 , V_10 -> V_256 , V_652 , 0 ) ;
V_662 = F_177 ( V_10 -> V_345 ) ;
if ( V_661 < V_662 &&
V_10 -> V_399 . V_467 >= V_664 &&
V_10 -> V_399 . V_105 < V_593 ) {
F_45 ( V_10 , L_136 ,
( unsigned long long ) V_661 , ( unsigned long long ) V_662 ) ;
F_71 ( V_29 -> V_27 , F_72 ( V_105 , V_151 ) , V_107 ) ;
F_130 ( V_10 ) ;
return - V_108 ;
}
if ( V_654 != V_652 ) {
struct V_290 * V_623 , * V_624 = NULL ;
V_624 = F_278 ( sizeof( struct V_290 ) , V_615 ) ;
if ( ! V_624 ) {
F_45 ( V_10 , L_123 ) ;
F_130 ( V_10 ) ;
return - V_254 ;
}
F_119 ( & V_27 -> V_24 -> V_228 ) ;
V_623 = V_10 -> V_256 -> V_290 ;
* V_624 = * V_623 ;
V_624 -> V_663 = V_652 ;
F_269 ( V_10 -> V_256 -> V_290 , V_624 ) ;
F_120 ( & V_27 -> V_24 -> V_228 ) ;
F_271 () ;
F_52 ( V_623 ) ;
F_68 ( V_10 , L_137 ,
( unsigned long ) V_654 ) ;
}
F_130 ( V_10 ) ;
}
V_10 -> V_665 = F_125 ( V_339 -> V_666 ) ;
V_657 = F_124 ( V_339 -> V_656 ) ;
if ( F_140 ( V_10 ) ) {
F_285 ( V_10 , V_10 -> V_256 , V_646 ) ;
V_649 = F_286 ( V_10 , V_657 , NULL ) ;
F_130 ( V_10 ) ;
if ( V_649 == V_667 )
return - V_108 ;
F_287 ( V_10 ) ;
} else {
F_285 ( V_10 , NULL , V_646 ) ;
F_288 ( V_10 , V_653 ? : V_652 ? : V_651 ) ;
}
if ( F_140 ( V_10 ) ) {
if ( V_10 -> V_256 -> V_668 != F_177 ( V_10 -> V_256 -> V_257 ) ) {
V_10 -> V_256 -> V_668 = F_177 ( V_10 -> V_256 -> V_257 ) ;
V_655 = 1 ;
}
F_130 ( V_10 ) ;
}
if ( V_10 -> V_399 . V_105 > V_103 ) {
if ( F_202 ( V_339 -> V_660 ) !=
F_177 ( V_10 -> V_345 ) || V_655 ) {
F_103 ( V_29 , 0 , V_657 ) ;
}
if ( F_289 ( V_190 , & V_10 -> V_69 ) ||
( V_649 == V_669 && V_10 -> V_399 . V_105 == V_593 ) ) {
if ( V_10 -> V_399 . V_454 >= V_455 &&
V_10 -> V_399 . V_467 >= V_455 ) {
if ( V_657 & V_670 )
F_68 ( V_10 , L_138 ) ;
else
F_290 ( V_10 ) ;
} else
F_111 ( V_671 , & V_10 -> V_69 ) ;
}
}
return 0 ;
}
static int F_291 ( struct V_26 * V_27 , struct V_171 * V_172 )
{
struct V_28 * V_29 ;
struct V_9 * V_10 ;
struct V_672 * V_339 = V_172 -> V_96 ;
T_2 * V_534 ;
int V_6 , V_673 = 0 ;
V_29 = F_201 ( V_27 , V_172 -> V_30 ) ;
if ( ! V_29 )
return F_275 ( V_27 , V_172 ) ;
V_10 = V_29 -> V_10 ;
V_534 = F_134 ( sizeof( T_2 ) * V_674 , V_213 ) ;
if ( ! V_534 ) {
F_45 ( V_10 , L_139 ) ;
return false ;
}
for ( V_6 = V_556 ; V_6 < V_674 ; V_6 ++ )
V_534 [ V_6 ] = F_202 ( V_339 -> V_532 [ V_6 ] ) ;
F_52 ( V_10 -> V_534 ) ;
V_10 -> V_534 = V_534 ;
if ( V_10 -> V_399 . V_105 < V_593 &&
V_10 -> V_399 . V_467 < V_455 &&
V_10 -> V_399 . V_550 == V_523 &&
( V_10 -> V_675 & ~ ( ( T_2 ) 1 ) ) != ( V_534 [ V_556 ] & ~ ( ( T_2 ) 1 ) ) ) {
F_45 ( V_10 , L_140 ,
( unsigned long long ) V_10 -> V_675 ) ;
F_71 ( V_29 -> V_27 , F_72 ( V_105 , V_151 ) , V_107 ) ;
return - V_108 ;
}
if ( F_140 ( V_10 ) ) {
int V_676 =
V_10 -> V_399 . V_105 == V_593 &&
V_29 -> V_27 -> V_186 >= 90 &&
V_10 -> V_256 -> V_531 . V_532 [ V_556 ] == V_563 &&
( V_534 [ V_566 ] & 8 ) ;
if ( V_676 ) {
F_68 ( V_10 , L_141 ) ;
F_264 ( V_10 , & V_677 ,
L_142 ,
V_678 ) ;
F_292 ( V_10 , V_556 , V_534 [ V_556 ] ) ;
F_292 ( V_10 , V_533 , 0 ) ;
F_293 ( F_294 ( V_10 , V_467 , V_493 , V_454 , V_493 ) ,
V_198 , NULL ) ;
F_287 ( V_10 ) ;
V_673 = 1 ;
}
F_130 ( V_10 ) ;
} else if ( V_10 -> V_399 . V_467 < V_455 &&
V_10 -> V_399 . V_550 == V_523 ) {
V_673 = F_295 ( V_10 , V_534 [ V_556 ] ) ;
}
F_119 ( V_10 -> V_185 ) ;
F_120 ( V_10 -> V_185 ) ;
if ( V_10 -> V_399 . V_105 >= V_593 && V_10 -> V_399 . V_467 < V_455 )
V_673 |= F_295 ( V_10 , V_534 [ V_556 ] ) ;
if ( V_673 )
F_296 ( V_10 , L_143 ) ;
return 0 ;
}
static union V_679 F_297 ( union V_679 V_680 )
{
union V_679 V_681 ;
static enum V_572 V_682 [] = {
[ V_103 ] = V_103 ,
[ V_593 ] = V_593 ,
[ V_683 ] = V_684 ,
[ V_684 ] = V_683 ,
[ V_151 ] = V_685 ,
[ V_482 ] = V_483 ,
[ V_575 ] = V_575 ,
} ;
V_681 . V_6 = V_680 . V_6 ;
V_681 . V_105 = V_682 [ V_680 . V_105 ] ;
V_681 . V_522 = V_680 . V_550 ;
V_681 . V_550 = V_680 . V_522 ;
V_681 . V_454 = V_680 . V_467 ;
V_681 . V_467 = V_680 . V_454 ;
V_681 . V_686 = ( V_680 . V_687 | V_680 . V_688 ) ;
return V_681 ;
}
static int F_298 ( struct V_26 * V_27 , struct V_171 * V_172 )
{
struct V_28 * V_29 ;
struct V_9 * V_10 ;
struct V_689 * V_339 = V_172 -> V_96 ;
union V_679 V_690 , V_691 ;
enum V_196 V_95 ;
V_29 = F_201 ( V_27 , V_172 -> V_30 ) ;
if ( ! V_29 )
return - V_108 ;
V_10 = V_29 -> V_10 ;
V_690 . V_6 = F_125 ( V_339 -> V_690 ) ;
V_691 . V_6 = F_125 ( V_339 -> V_691 ) ;
if ( F_69 ( V_205 , & V_29 -> V_27 -> V_69 ) &&
F_299 ( V_10 -> V_185 ) ) {
F_300 ( V_29 , V_692 ) ;
return 0 ;
}
V_690 = F_297 ( V_690 ) ;
V_691 = F_297 ( V_691 ) ;
V_95 = F_254 ( V_10 , V_198 , V_690 , V_691 ) ;
F_300 ( V_29 , V_95 ) ;
F_287 ( V_10 ) ;
return 0 ;
}
static int F_301 ( struct V_26 * V_27 , struct V_171 * V_172 )
{
struct V_689 * V_339 = V_172 -> V_96 ;
union V_679 V_690 , V_691 ;
enum V_196 V_95 ;
V_690 . V_6 = F_125 ( V_339 -> V_690 ) ;
V_691 . V_6 = F_125 ( V_339 -> V_691 ) ;
if ( F_69 ( V_205 , & V_27 -> V_69 ) &&
F_299 ( & V_27 -> V_187 ) ) {
F_302 ( V_27 , V_692 ) ;
return 0 ;
}
V_690 = F_297 ( V_690 ) ;
V_691 = F_297 ( V_691 ) ;
V_95 = F_71 ( V_27 , V_690 , V_691 , V_198 | V_693 | V_694 ) ;
F_302 ( V_27 , V_95 ) ;
return 0 ;
}
static int F_303 ( struct V_26 * V_27 , struct V_171 * V_172 )
{
struct V_28 * V_29 ;
struct V_9 * V_10 ;
struct V_695 * V_339 = V_172 -> V_96 ;
union V_679 V_696 , V_697 , V_698 ;
enum V_573 V_699 ;
enum V_700 V_701 ;
int V_95 ;
V_29 = F_201 ( V_27 , V_172 -> V_30 ) ;
if ( ! V_29 )
return F_275 ( V_27 , V_172 ) ;
V_10 = V_29 -> V_10 ;
V_698 . V_6 = F_125 ( V_339 -> V_399 ) ;
V_699 = V_698 . V_467 ;
if ( V_698 . V_467 == V_565 ) {
V_699 = V_10 -> V_534 [ V_566 ] & 4 ? V_455 : V_587 ;
F_68 ( V_10 , L_144 , F_304 ( V_699 ) ) ;
}
F_20 ( & V_10 -> V_24 -> V_25 ) ;
V_34:
V_696 = V_697 = F_305 ( V_10 ) ;
F_21 ( & V_10 -> V_24 -> V_25 ) ;
if ( V_696 . V_105 <= V_685 )
return - V_97 ;
if ( ( V_696 . V_454 == V_455 || V_696 . V_454 == V_587 ) &&
V_699 == V_493 &&
V_696 . V_105 > V_593 && V_696 . V_467 == V_493 ) {
if ( V_698 . V_105 > V_593 &&
V_698 . V_105 < V_400 )
V_699 = V_455 ;
else if ( V_696 . V_105 >= V_400 &&
V_698 . V_105 == V_593 ) {
if ( F_241 ( V_10 ) <= V_10 -> V_485 )
F_306 ( V_10 ) ;
return 0 ;
}
}
if ( V_696 . V_105 == V_483 && V_696 . V_467 == V_493 &&
V_698 . V_105 == V_593 && V_699 == V_493 ) {
F_307 ( V_10 ) ;
F_306 ( V_10 ) ;
return 0 ;
}
if ( V_696 . V_454 == V_493 && V_699 == V_455 &&
V_696 . V_105 == V_593 && V_698 . V_105 > V_400 )
V_699 = V_493 ;
if ( V_697 . V_105 == V_103 )
V_697 . V_105 = V_593 ;
if ( V_698 . V_105 == V_702 )
V_697 . V_105 = V_703 ;
if ( V_10 -> V_534 && V_698 . V_467 >= V_565 &&
F_244 ( V_10 , V_565 ) ) {
int V_704 ;
V_704 = ( V_696 . V_105 < V_593 ) ;
V_704 |= ( V_696 . V_105 == V_593 &&
( V_698 . V_467 == V_565 ||
V_696 . V_467 == V_565 ) ) ;
V_704 |= F_69 ( V_705 , & V_10 -> V_69 ) ;
V_704 |= ( V_696 . V_105 == V_593 &&
( V_698 . V_105 >= V_683 &&
V_698 . V_105 <= V_592 ) ) ;
if ( V_704 )
V_697 . V_105 = F_262 ( V_29 , V_698 . V_550 , V_699 ) ;
F_130 ( V_10 ) ;
if ( V_697 . V_105 == V_575 ) {
V_697 . V_105 = V_593 ;
if ( V_10 -> V_399 . V_467 == V_565 ) {
F_308 ( V_10 , F_72 ( V_467 , V_706 ) ) ;
} else if ( V_698 . V_467 == V_565 ) {
F_45 ( V_10 , L_145 ) ;
V_698 . V_467 = V_707 ;
V_699 = V_707 ;
} else {
if ( F_289 ( V_588 , & V_29 -> V_27 -> V_69 ) )
return - V_108 ;
F_53 ( V_10 , V_696 . V_105 == V_103 ) ;
F_71 ( V_29 -> V_27 , F_72 ( V_105 , V_151 ) , V_107 ) ;
return - V_108 ;
}
}
}
F_20 ( & V_10 -> V_24 -> V_25 ) ;
if ( V_696 . V_6 != F_305 ( V_10 ) . V_6 )
goto V_34;
F_106 ( V_705 , & V_10 -> V_69 ) ;
V_697 . V_522 = V_698 . V_550 ;
V_697 . V_454 = V_699 ;
V_697 . V_686 = ( V_698 . V_687 | V_698 . V_688 ) ;
if ( ( V_697 . V_105 == V_593 || V_697 . V_105 == V_591 ) && V_697 . V_467 == V_565 )
V_697 . V_467 = V_10 -> V_579 . V_467 ;
V_701 = V_198 + ( V_696 . V_105 < V_593 && V_697 . V_105 >= V_593 ? 0 : V_107 ) ;
if ( V_697 . V_454 == V_587 && F_309 ( V_10 ) && V_697 . V_105 == V_593 && V_696 . V_105 < V_593 &&
F_69 ( V_708 , & V_10 -> V_69 ) ) {
F_21 ( & V_10 -> V_24 -> V_25 ) ;
F_45 ( V_10 , L_146 ) ;
F_310 ( V_29 -> V_27 ) ;
F_311 ( V_10 ) ;
F_106 ( V_708 , & V_10 -> V_69 ) ;
F_71 ( V_29 -> V_27 , F_312 ( V_105 , V_709 , V_710 , 0 ) , V_107 ) ;
return - V_108 ;
}
V_95 = F_293 ( V_10 , V_697 , V_701 , NULL ) ;
V_697 = F_305 ( V_10 ) ;
F_21 ( & V_10 -> V_24 -> V_25 ) ;
if ( V_95 < V_199 ) {
F_71 ( V_29 -> V_27 , F_72 ( V_105 , V_151 ) , V_107 ) ;
return - V_108 ;
}
if ( V_696 . V_105 > V_103 ) {
if ( V_697 . V_105 > V_593 && V_698 . V_105 <= V_593 &&
V_698 . V_467 != V_565 ) {
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
struct V_711 * V_339 = V_172 -> V_96 ;
V_29 = F_201 ( V_27 , V_172 -> V_30 ) ;
if ( ! V_29 )
return - V_108 ;
V_10 = V_29 -> V_10 ;
F_232 ( V_10 -> V_337 ,
V_10 -> V_399 . V_105 == V_712 ||
V_10 -> V_399 . V_105 == V_703 ||
V_10 -> V_399 . V_105 < V_593 ||
V_10 -> V_399 . V_467 < V_565 ) ;
if ( F_244 ( V_10 , V_565 ) ) {
F_292 ( V_10 , V_556 , F_202 ( V_339 -> V_532 ) ) ;
F_292 ( V_10 , V_533 , 0UL ) ;
F_296 ( V_10 , L_147 ) ;
F_314 ( V_10 , V_453 ) ;
F_130 ( V_10 ) ;
} else
F_45 ( V_10 , L_148 ) ;
return 0 ;
}
static int
F_315 ( struct V_28 * V_29 , unsigned int V_64 ,
unsigned long * V_339 , struct V_713 * V_714 )
{
unsigned int V_320 = V_618 -
F_95 ( V_29 -> V_27 ) ;
unsigned int V_715 = F_77 ( T_6 , V_320 / sizeof( * V_339 ) ,
V_714 -> V_716 - V_714 -> V_717 ) ;
unsigned int V_718 = V_715 * sizeof( * V_339 ) ;
int V_77 ;
if ( V_718 != V_64 ) {
F_45 ( V_29 , L_149 , V_62 , V_718 , V_64 ) ;
return - V_108 ;
}
if ( V_718 == 0 )
return 0 ;
V_77 = F_73 ( V_29 -> V_27 , V_339 , V_718 ) ;
if ( V_77 )
return V_77 ;
F_316 ( V_29 -> V_10 , V_714 -> V_717 , V_715 , V_339 ) ;
V_714 -> V_717 += V_715 ;
V_714 -> V_719 = V_714 -> V_717 * V_720 ;
if ( V_714 -> V_719 > V_714 -> V_721 )
V_714 -> V_719 = V_714 -> V_721 ;
return 1 ;
}
static enum V_722 F_317 ( struct V_723 * V_339 )
{
return (enum V_722 ) ( V_339 -> V_724 & 0x0f ) ;
}
static int F_318 ( struct V_723 * V_339 )
{
return ( V_339 -> V_724 & 0x80 ) != 0 ;
}
static int F_319 ( struct V_723 * V_339 )
{
return ( V_339 -> V_724 >> 4 ) & 0x7 ;
}
static int
F_320 ( struct V_28 * V_29 ,
struct V_723 * V_339 ,
struct V_713 * V_714 ,
unsigned int V_5 )
{
struct V_725 V_726 ;
T_2 V_727 ;
T_2 V_728 ;
T_2 V_4 ;
unsigned long V_203 = V_714 -> V_719 ;
unsigned long V_729 ;
int V_730 = F_318 ( V_339 ) ;
int V_731 ;
int V_555 ;
F_321 ( & V_726 , V_339 -> V_732 , V_5 , F_319 ( V_339 ) ) ;
V_555 = F_322 ( & V_726 , & V_727 , 64 ) ;
if ( V_555 < 0 )
return - V_108 ;
for ( V_731 = V_555 ; V_731 > 0 ; V_203 += V_728 , V_730 = ! V_730 ) {
V_555 = F_323 ( & V_728 , V_727 ) ;
if ( V_555 <= 0 )
return - V_108 ;
if ( V_730 ) {
V_729 = V_203 + V_728 - 1 ;
if ( V_729 >= V_714 -> V_721 ) {
F_45 ( V_29 , L_150 , V_729 ) ;
return - V_108 ;
}
F_324 ( V_29 -> V_10 , V_203 , V_729 ) ;
}
if ( V_731 < V_555 ) {
F_45 ( V_29 , L_151 ,
V_731 , V_555 , V_727 ,
( unsigned int ) ( V_726 . V_733 . V_409 - V_339 -> V_732 ) ,
( unsigned int ) V_726 . V_734 ) ;
return - V_108 ;
}
if ( F_190 ( V_555 < 64 ) )
V_727 >>= V_555 ;
else
V_727 = 0 ;
V_731 -= V_555 ;
V_555 = F_322 ( & V_726 , & V_4 , 64 - V_731 ) ;
if ( V_555 < 0 )
return - V_108 ;
V_727 |= V_4 << V_731 ;
V_731 += V_555 ;
}
V_714 -> V_719 = V_203 ;
F_325 ( V_714 ) ;
return ( V_203 != V_714 -> V_721 ) ;
}
static int
F_326 ( struct V_28 * V_29 ,
struct V_723 * V_339 ,
struct V_713 * V_714 ,
unsigned int V_5 )
{
if ( F_317 ( V_339 ) == V_735 )
return F_320 ( V_29 , V_339 , V_714 , V_5 - sizeof( * V_339 ) ) ;
F_45 ( V_29 , L_152 , V_339 -> V_724 ) ;
F_71 ( V_29 -> V_27 , F_72 ( V_105 , V_709 ) , V_107 ) ;
return - V_108 ;
}
void F_327 ( struct V_9 * V_10 ,
const char * V_736 , struct V_713 * V_714 )
{
unsigned int V_170 = F_95 ( F_259 ( V_10 ) -> V_27 ) ;
unsigned int V_320 = V_618 - V_170 ;
unsigned int V_737 =
V_170 * ( F_328 ( V_714 -> V_716 , V_320 ) + 1 ) +
V_714 -> V_716 * sizeof( unsigned long ) ;
unsigned int V_738 = V_714 -> V_739 [ 0 ] + V_714 -> V_739 [ 1 ] ;
unsigned int V_342 ;
if ( V_738 == 0 )
return;
if ( V_738 >= V_737 )
return;
V_342 = ( V_738 > V_45 / 1000 ) ? ( V_738 / ( V_737 / 1000 ) )
: ( 1000 * V_738 / V_737 ) ;
if ( V_342 > 1000 )
V_342 = 1000 ;
V_342 = 1000 - V_342 ;
F_68 ( V_10 , L_153
L_154 ,
V_736 ,
V_714 -> V_739 [ 1 ] , V_714 -> V_740 [ 1 ] ,
V_714 -> V_739 [ 0 ] , V_714 -> V_740 [ 0 ] ,
V_738 , V_342 / 10 , V_342 % 10 ) ;
}
static int F_329 ( struct V_26 * V_27 , struct V_171 * V_172 )
{
struct V_28 * V_29 ;
struct V_9 * V_10 ;
struct V_713 V_714 ;
int V_77 ;
V_29 = F_201 ( V_27 , V_172 -> V_30 ) ;
if ( ! V_29 )
return - V_108 ;
V_10 = V_29 -> V_10 ;
F_330 ( V_10 , L_155 , V_590 ) ;
V_714 = (struct V_713 ) {
. V_721 = F_249 ( V_10 ) ,
. V_716 = F_331 ( V_10 ) ,
} ;
for(; ; ) {
if ( V_172 -> V_169 == V_741 )
V_77 = F_315 ( V_29 , V_172 -> V_64 , V_172 -> V_96 , & V_714 ) ;
else if ( V_172 -> V_169 == V_742 ) {
struct V_723 * V_339 = V_172 -> V_96 ;
if ( V_172 -> V_64 > V_618 - F_95 ( V_27 ) ) {
F_45 ( V_10 , L_156 ) ;
V_77 = - V_108 ;
goto V_104;
}
if ( V_172 -> V_64 <= sizeof( * V_339 ) ) {
F_45 ( V_10 , L_157 , V_172 -> V_64 ) ;
V_77 = - V_108 ;
goto V_104;
}
V_77 = F_73 ( V_29 -> V_27 , V_339 , V_172 -> V_64 ) ;
if ( V_77 )
goto V_104;
V_77 = F_326 ( V_29 , V_339 , & V_714 , V_172 -> V_64 ) ;
} else {
F_35 ( V_10 , L_158 , V_172 -> V_169 ) ;
V_77 = - V_108 ;
goto V_104;
}
V_714 . V_740 [ V_172 -> V_169 == V_741 ] ++ ;
V_714 . V_739 [ V_172 -> V_169 == V_741 ] += F_95 ( V_27 ) + V_172 -> V_64 ;
if ( V_77 <= 0 ) {
if ( V_77 < 0 )
goto V_104;
break;
}
V_77 = F_127 ( V_29 -> V_27 , V_172 ) ;
if ( V_77 )
goto V_104;
}
F_327 ( V_10 , L_159 , & V_714 ) ;
if ( V_10 -> V_399 . V_105 == V_592 ) {
enum V_196 V_95 ;
V_77 = F_332 ( V_10 ) ;
if ( V_77 )
goto V_104;
V_95 = F_333 ( V_10 , F_72 ( V_105 , V_712 ) , V_198 ) ;
F_53 ( V_10 , V_95 == V_199 ) ;
} else if ( V_10 -> V_399 . V_105 != V_591 ) {
F_68 ( V_10 , L_160 ,
F_263 ( V_10 -> V_399 . V_105 ) ) ;
}
V_77 = 0 ;
V_104:
F_334 ( V_10 ) ;
if ( ! V_77 && V_10 -> V_399 . V_105 == V_591 )
F_314 ( V_10 , V_400 ) ;
return V_77 ;
}
static int F_335 ( struct V_26 * V_27 , struct V_171 * V_172 )
{
F_35 ( V_27 , L_161 ,
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
struct V_743 * V_339 = V_172 -> V_96 ;
V_29 = F_201 ( V_27 , V_172 -> V_30 ) ;
if ( ! V_29 )
return - V_108 ;
V_10 = V_29 -> V_10 ;
switch ( V_10 -> V_399 . V_105 ) {
case V_712 :
case V_592 :
case V_703 :
break;
default:
F_45 ( V_10 , L_162 ,
F_263 ( V_10 -> V_399 . V_105 ) ) ;
}
F_233 ( V_10 , F_202 ( V_339 -> V_52 ) , F_125 ( V_339 -> V_492 ) ) ;
return 0 ;
}
static int F_339 ( struct V_26 * V_27 , struct V_171 * V_172 )
{
struct V_28 * V_29 ;
struct V_743 * V_339 = V_172 -> V_96 ;
struct V_9 * V_10 ;
T_3 V_52 ;
int V_64 , V_77 = 0 ;
V_29 = F_201 ( V_27 , V_172 -> V_30 ) ;
if ( ! V_29 )
return - V_108 ;
V_10 = V_29 -> V_10 ;
V_52 = F_202 ( V_339 -> V_52 ) ;
V_64 = F_125 ( V_339 -> V_492 ) ;
F_196 ( V_10 ) ;
if ( F_140 ( V_10 ) ) {
struct V_18 * V_19 ;
const int V_316 = V_430 ;
V_19 = F_42 ( V_29 , V_378 , V_52 ,
V_64 , 0 , V_213 ) ;
if ( ! V_19 ) {
F_130 ( V_10 ) ;
return - V_254 ;
}
V_19 -> V_20 . V_80 = F_188 ;
V_19 -> V_65 = V_66 ;
V_19 -> V_69 |= V_322 ;
F_20 ( & V_10 -> V_24 -> V_25 ) ;
F_166 ( & V_19 -> V_20 . V_21 , & V_10 -> V_379 ) ;
F_21 ( & V_10 -> V_24 -> V_25 ) ;
F_38 ( V_172 -> V_64 >> 9 , & V_10 -> V_380 ) ;
V_77 = F_164 ( V_10 , V_19 , V_316 , 0 , V_382 ) ;
if ( V_77 ) {
F_20 ( & V_10 -> V_24 -> V_25 ) ;
F_147 ( & V_19 -> V_20 . V_21 ) ;
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
F_246 ( V_29 , V_377 , V_52 , V_64 , V_378 ) ;
}
F_38 ( V_64 >> 9 , & V_10 -> V_391 ) ;
return V_77 ;
}
static void F_341 ( struct V_26 * V_27 )
{
struct V_171 V_172 ;
T_6 V_744 ;
int V_77 ;
while ( F_114 ( & V_27 -> V_210 ) == V_745 ) {
struct V_746 const * V_169 ;
F_342 ( & V_27 -> V_210 ) ;
F_250 ( V_27 , F_127 ) ;
if ( F_127 ( V_27 , & V_172 ) )
goto V_747;
V_169 = & V_748 [ V_172 . V_169 ] ;
if ( F_154 ( V_172 . V_169 >= F_343 ( V_748 ) || ! V_169 -> V_749 ) ) {
F_45 ( V_27 , L_163 ,
F_276 ( V_172 . V_169 ) , V_172 . V_169 ) ;
goto V_747;
}
V_744 = V_169 -> V_750 ;
if ( V_172 . V_169 == V_751 && V_27 -> V_568 & V_569 )
V_744 += sizeof( struct V_645 ) ;
if ( V_172 . V_64 > V_744 && ! V_169 -> V_752 ) {
F_45 ( V_27 , L_164 ,
F_276 ( V_172 . V_169 ) , V_172 . V_64 ) ;
goto V_747;
}
if ( V_172 . V_64 < V_744 ) {
F_45 ( V_27 , L_165 ,
F_276 ( V_172 . V_169 ) , ( int ) V_744 , V_172 . V_64 ) ;
goto V_747;
}
if ( V_744 ) {
F_250 ( V_27 , F_74 ) ;
V_77 = F_74 ( V_27 , V_172 . V_96 , V_744 ) ;
if ( V_77 )
goto V_747;
V_172 . V_64 -= V_744 ;
}
F_250 ( V_27 , V_169 -> V_749 ) ;
V_77 = V_169 -> V_749 ( V_27 , & V_172 ) ;
if ( V_77 ) {
F_45 ( V_27 , L_166 ,
F_276 ( V_172 . V_169 ) , V_77 , V_172 . V_64 ) ;
goto V_747;
}
}
return;
V_747:
F_71 ( V_27 , F_72 ( V_105 , V_709 ) , V_107 ) ;
}
static void F_344 ( struct V_26 * V_27 )
{
struct V_28 * V_29 ;
enum V_572 V_753 ;
int V_30 ;
if ( V_27 -> V_102 == V_754 )
return;
F_71 ( V_27 , F_72 ( V_105 , V_755 ) , V_107 ) ;
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
if ( ! F_62 ( & V_27 -> V_281 -> V_21 ) )
F_45 ( V_27 , L_167 ) ;
F_101 ( & V_27 -> V_281 -> V_270 , 0 ) ;
V_27 -> V_756 . V_757 = false ;
F_68 ( V_27 , L_168 ) ;
if ( F_349 ( V_27 ) == V_523 && F_350 ( V_27 ) >= V_758 )
F_351 ( V_27 ) ;
F_20 ( & V_27 -> V_24 -> V_25 ) ;
V_753 = V_27 -> V_102 ;
if ( V_753 >= V_759 )
F_230 ( V_27 , F_72 ( V_105 , V_759 ) , V_198 ) ;
F_21 ( & V_27 -> V_24 -> V_25 ) ;
if ( V_753 == V_151 )
F_71 ( V_27 , F_72 ( V_105 , V_754 ) , V_198 | V_107 ) ;
}
static int F_348 ( struct V_28 * V_29 )
{
struct V_9 * V_10 = V_29 -> V_10 ;
unsigned int V_6 ;
F_20 ( & V_10 -> V_24 -> V_25 ) ;
F_61 ( V_10 , & V_10 -> V_325 ) ;
F_61 ( V_10 , & V_10 -> V_379 ) ;
F_61 ( V_10 , & V_10 -> V_521 ) ;
F_21 ( & V_10 -> V_24 -> V_25 ) ;
F_352 ( V_10 ) ;
V_10 -> V_519 = 0 ;
V_10 -> V_485 = 0 ;
F_101 ( & V_10 -> V_760 , 0 ) ;
F_41 ( & V_10 -> V_337 ) ;
F_353 ( & V_10 -> V_761 ) ;
F_354 ( ( unsigned long ) V_10 ) ;
F_355 ( & V_29 -> V_27 -> V_762 ) ;
F_59 ( V_10 ) ;
F_355 ( & V_29 -> V_27 -> V_762 ) ;
F_352 ( V_10 ) ;
F_52 ( V_10 -> V_534 ) ;
V_10 -> V_534 = NULL ;
if ( ! F_309 ( V_10 ) )
F_310 ( V_29 -> V_27 ) ;
F_287 ( V_10 ) ;
if ( F_140 ( V_10 ) ) {
F_264 ( V_10 , & V_763 ,
L_169 , V_764 ) ;
F_130 ( V_10 ) ;
}
V_6 = F_57 ( V_10 , & V_10 -> V_76 ) ;
if ( V_6 )
F_68 ( V_10 , L_170 , V_6 ) ;
V_6 = F_26 ( & V_10 -> V_31 ) ;
if ( V_6 )
F_68 ( V_10 , L_171 , V_6 ) ;
V_6 = F_26 ( & V_10 -> V_40 ) ;
if ( V_6 )
F_68 ( V_10 , L_172 , V_6 ) ;
F_53 ( V_10 , F_62 ( & V_10 -> V_521 ) ) ;
F_53 ( V_10 , F_62 ( & V_10 -> V_325 ) ) ;
F_53 ( V_10 , F_62 ( & V_10 -> V_379 ) ) ;
F_53 ( V_10 , F_62 ( & V_10 -> V_78 ) ) ;
return 0 ;
}
static int F_356 ( struct V_26 * V_27 )
{
struct V_167 * V_84 ;
struct V_765 * V_339 ;
V_84 = & V_27 -> V_96 ;
V_339 = F_92 ( V_27 , V_84 ) ;
if ( ! V_339 )
return - V_108 ;
memset ( V_339 , 0 , sizeof( * V_339 ) ) ;
V_339 -> V_766 = F_123 ( V_767 ) ;
V_339 -> V_768 = F_123 ( V_570 ) ;
V_339 -> V_769 = F_123 ( V_770 ) ;
return F_93 ( V_27 , V_84 , V_771 , sizeof( * V_339 ) , NULL , 0 ) ;
}
static int F_116 ( struct V_26 * V_27 )
{
struct V_765 * V_339 ;
const int F_55 = sizeof( struct V_765 ) ;
struct V_171 V_172 ;
int V_77 ;
V_77 = F_356 ( V_27 ) ;
if ( V_77 )
return 0 ;
V_77 = F_127 ( V_27 , & V_172 ) ;
if ( V_77 )
return 0 ;
if ( V_172 . V_169 != V_771 ) {
F_45 ( V_27 , L_173 ,
F_276 ( V_172 . V_169 ) , V_172 . V_169 ) ;
return - 1 ;
}
if ( V_172 . V_64 != F_55 ) {
F_45 ( V_27 , L_174 ,
F_55 , V_172 . V_64 ) ;
return - 1 ;
}
V_339 = V_172 . V_96 ;
V_77 = F_74 ( V_27 , V_339 , F_55 ) ;
if ( V_77 )
return 0 ;
V_339 -> V_766 = F_125 ( V_339 -> V_766 ) ;
V_339 -> V_768 = F_125 ( V_339 -> V_768 ) ;
if ( V_339 -> V_768 == 0 )
V_339 -> V_768 = V_339 -> V_766 ;
if ( V_570 < V_339 -> V_766 ||
V_767 > V_339 -> V_768 )
goto V_772;
V_27 -> V_186 = F_77 ( int , V_570 , V_339 -> V_768 ) ;
V_27 -> V_568 = V_770 & F_125 ( V_339 -> V_769 ) ;
F_68 ( V_27 , L_175
L_176 , V_27 -> V_186 ) ;
F_68 ( V_27 , L_177 ,
V_27 -> V_568 ,
V_27 -> V_568 & V_773 ? L_178 : L_106 ,
V_27 -> V_568 & V_774 ? L_179 : L_106 ,
V_27 -> V_568 & V_569 ? L_180 :
V_27 -> V_568 ? L_106 : L_181 ) ;
return 1 ;
V_772:
F_45 ( V_27 , L_182
L_183 ,
V_767 , V_570 ,
V_339 -> V_766 , V_339 -> V_768 ) ;
return - 1 ;
}
static int F_117 ( struct V_26 * V_27 )
{
F_45 ( V_27 , L_184 ) ;
F_45 ( V_27 , L_185 ) ;
return - 1 ;
}
static int F_117 ( struct V_26 * V_27 )
{
struct V_167 * V_84 ;
char V_775 [ V_776 ] ;
char * V_777 = NULL ;
char * V_778 = NULL ;
char * V_779 = NULL ;
unsigned int V_780 ;
char V_781 [ V_605 ] ;
unsigned int V_782 ;
F_357 ( V_783 , V_27 -> V_219 ) ;
struct V_171 V_172 ;
struct V_35 * V_36 ;
int V_77 , V_95 ;
F_24 () ;
V_36 = F_32 ( V_27 -> V_35 ) ;
V_780 = strlen ( V_36 -> V_784 ) ;
memcpy ( V_781 , V_36 -> V_784 , V_780 ) ;
F_28 () ;
V_783 -> V_617 = V_27 -> V_219 ;
V_783 -> V_69 = 0 ;
V_95 = F_358 ( V_27 -> V_219 , ( V_785 * ) V_781 , V_780 ) ;
if ( V_95 ) {
F_45 ( V_27 , L_186 , V_95 ) ;
V_95 = - 1 ;
goto V_63;
}
F_359 ( V_775 , V_776 ) ;
V_84 = & V_27 -> V_96 ;
if ( ! F_92 ( V_27 , V_84 ) ) {
V_95 = 0 ;
goto V_63;
}
V_95 = ! F_93 ( V_27 , V_84 , V_786 , 0 ,
V_775 , V_776 ) ;
if ( ! V_95 )
goto V_63;
V_77 = F_127 ( V_27 , & V_172 ) ;
if ( V_77 ) {
V_95 = 0 ;
goto V_63;
}
if ( V_172 . V_169 != V_786 ) {
F_45 ( V_27 , L_187 ,
F_276 ( V_172 . V_169 ) , V_172 . V_169 ) ;
V_95 = 0 ;
goto V_63;
}
if ( V_172 . V_64 > V_776 * 2 ) {
F_45 ( V_27 , L_188 ) ;
V_95 = - 1 ;
goto V_63;
}
if ( V_172 . V_64 < V_776 ) {
F_45 ( V_27 , L_189 ) ;
V_95 = - 1 ;
goto V_63;
}
V_779 = F_134 ( V_172 . V_64 , V_213 ) ;
if ( V_779 == NULL ) {
F_45 ( V_27 , L_190 ) ;
V_95 = - 1 ;
goto V_63;
}
V_77 = F_74 ( V_27 , V_779 , V_172 . V_64 ) ;
if ( V_77 ) {
V_95 = 0 ;
goto V_63;
}
if ( ! memcmp ( V_775 , V_779 , V_776 ) ) {
F_45 ( V_27 , L_191 ) ;
V_95 = - 1 ;
goto V_63;
}
V_782 = F_360 ( V_27 -> V_219 ) ;
V_777 = F_134 ( V_782 , V_213 ) ;
if ( V_777 == NULL ) {
F_45 ( V_27 , L_192 ) ;
V_95 = - 1 ;
goto V_63;
}
V_95 = F_361 ( V_783 , V_779 , V_172 . V_64 , V_777 ) ;
if ( V_95 ) {
F_45 ( V_27 , L_193 , V_95 ) ;
V_95 = - 1 ;
goto V_63;
}
if ( ! F_92 ( V_27 , V_84 ) ) {
V_95 = 0 ;
goto V_63;
}
V_95 = ! F_93 ( V_27 , V_84 , V_787 , 0 ,
V_777 , V_782 ) ;
if ( ! V_95 )
goto V_63;
V_77 = F_127 ( V_27 , & V_172 ) ;
if ( V_77 ) {
V_95 = 0 ;
goto V_63;
}
if ( V_172 . V_169 != V_787 ) {
F_45 ( V_27 , L_194 ,
F_276 ( V_172 . V_169 ) , V_172 . V_169 ) ;
V_95 = 0 ;
goto V_63;
}
if ( V_172 . V_64 != V_782 ) {
F_45 ( V_27 , L_195 ) ;
V_95 = 0 ;
goto V_63;
}
V_77 = F_74 ( V_27 , V_777 , V_782 ) ;
if ( V_77 ) {
V_95 = 0 ;
goto V_63;
}
V_778 = F_134 ( V_782 , V_213 ) ;
if ( V_778 == NULL ) {
F_45 ( V_27 , L_196 ) ;
V_95 = - 1 ;
goto V_63;
}
V_95 = F_361 ( V_783 , V_775 , V_776 ,
V_778 ) ;
if ( V_95 ) {
F_45 ( V_27 , L_193 , V_95 ) ;
V_95 = - 1 ;
goto V_63;
}
V_95 = ! memcmp ( V_777 , V_778 , V_782 ) ;
if ( V_95 )
F_68 ( V_27 , L_197 ,
V_782 ) ;
else
V_95 = - 1 ;
V_63:
F_52 ( V_779 ) ;
F_52 ( V_777 ) ;
F_52 ( V_778 ) ;
F_362 ( V_783 ) ;
return V_95 ;
}
int F_363 ( struct V_788 * V_789 )
{
struct V_26 * V_27 = V_789 -> V_27 ;
int V_194 ;
F_68 ( V_27 , L_198 ) ;
do {
V_194 = F_108 ( V_27 ) ;
if ( V_194 == 0 ) {
F_344 ( V_27 ) ;
F_99 ( V_44 ) ;
}
if ( V_194 == - 1 ) {
F_35 ( V_27 , L_199 ) ;
F_71 ( V_27 , F_72 ( V_105 , V_151 ) , V_107 ) ;
}
} while ( V_194 == 0 );
if ( V_194 > 0 )
F_341 ( V_27 ) ;
F_344 ( V_27 ) ;
F_68 ( V_27 , L_200 ) ;
return 0 ;
}
static int F_364 ( struct V_26 * V_27 , struct V_171 * V_172 )
{
struct V_790 * V_339 = V_172 -> V_96 ;
int V_791 = F_125 ( V_339 -> V_791 ) ;
if ( V_791 >= V_199 ) {
F_111 ( V_792 , & V_27 -> V_69 ) ;
} else {
F_111 ( V_793 , & V_27 -> V_69 ) ;
F_45 ( V_27 , L_201 ,
F_365 ( V_791 ) , V_791 ) ;
}
F_41 ( & V_27 -> V_101 ) ;
return 0 ;
}
static int F_366 ( struct V_26 * V_27 , struct V_171 * V_172 )
{
struct V_28 * V_29 ;
struct V_9 * V_10 ;
struct V_790 * V_339 = V_172 -> V_96 ;
int V_791 = F_125 ( V_339 -> V_791 ) ;
V_29 = F_201 ( V_27 , V_172 -> V_30 ) ;
if ( ! V_29 )
return - V_108 ;
V_10 = V_29 -> V_10 ;
if ( F_69 ( V_794 , & V_27 -> V_69 ) ) {
F_53 ( V_10 , V_27 -> V_186 < 100 ) ;
return F_364 ( V_27 , V_172 ) ;
}
if ( V_791 >= V_199 ) {
F_111 ( V_795 , & V_10 -> V_69 ) ;
} else {
F_111 ( V_796 , & V_10 -> V_69 ) ;
F_45 ( V_10 , L_201 ,
F_365 ( V_791 ) , V_791 ) ;
}
F_41 ( & V_10 -> V_797 ) ;
return 0 ;
}
static int F_367 ( struct V_26 * V_27 , struct V_171 * V_172 )
{
return F_368 ( V_27 ) ;
}
static int F_369 ( struct V_26 * V_27 , struct V_171 * V_172 )
{
V_27 -> V_202 . V_83 -> V_111 -> V_138 = V_27 -> V_35 -> V_217 * V_44 ;
if ( ! F_370 ( V_798 , & V_27 -> V_69 ) )
F_41 ( & V_27 -> V_101 ) ;
return 0 ;
}
static int F_371 ( struct V_26 * V_27 , struct V_171 * V_172 )
{
struct V_28 * V_29 ;
struct V_9 * V_10 ;
struct V_799 * V_339 = V_172 -> V_96 ;
T_3 V_52 = F_202 ( V_339 -> V_52 ) ;
int V_492 = F_125 ( V_339 -> V_492 ) ;
V_29 = F_201 ( V_27 , V_172 -> V_30 ) ;
if ( ! V_29 )
return - V_108 ;
V_10 = V_29 -> V_10 ;
F_53 ( V_10 , V_29 -> V_27 -> V_186 >= 89 ) ;
F_216 ( V_29 , F_125 ( V_339 -> V_442 ) ) ;
if ( F_140 ( V_10 ) ) {
F_340 ( V_10 , V_52 ) ;
F_191 ( V_10 , V_52 , V_492 ) ;
V_10 -> V_800 += ( V_492 >> V_801 ) ;
F_130 ( V_10 ) ;
}
F_196 ( V_10 ) ;
F_38 ( V_492 >> 9 , & V_10 -> V_391 ) ;
return 0 ;
}
static int
F_372 ( struct V_9 * V_10 , T_2 V_51 , T_3 V_52 ,
struct V_383 * V_384 , const char * V_386 ,
enum V_802 V_117 , bool V_385 )
{
struct V_363 * V_364 ;
struct V_432 V_433 ;
F_20 ( & V_10 -> V_24 -> V_25 ) ;
V_364 = F_198 ( V_10 , V_384 , V_51 , V_52 , V_385 , V_386 ) ;
if ( F_154 ( ! V_364 ) ) {
F_21 ( & V_10 -> V_24 -> V_25 ) ;
return - V_108 ;
}
F_209 ( V_364 , V_117 , & V_433 ) ;
F_21 ( & V_10 -> V_24 -> V_25 ) ;
if ( V_433 . V_244 )
F_224 ( V_10 , & V_433 ) ;
return 0 ;
}
static int F_373 ( struct V_26 * V_27 , struct V_171 * V_172 )
{
struct V_28 * V_29 ;
struct V_9 * V_10 ;
struct V_799 * V_339 = V_172 -> V_96 ;
T_3 V_52 = F_202 ( V_339 -> V_52 ) ;
int V_492 = F_125 ( V_339 -> V_492 ) ;
enum V_802 V_117 ;
V_29 = F_201 ( V_27 , V_172 -> V_30 ) ;
if ( ! V_29 )
return - V_108 ;
V_10 = V_29 -> V_10 ;
F_216 ( V_29 , F_125 ( V_339 -> V_442 ) ) ;
if ( V_339 -> V_68 == V_378 ) {
F_191 ( V_10 , V_52 , V_492 ) ;
F_196 ( V_10 ) ;
return 0 ;
}
switch ( V_172 -> V_169 ) {
case V_376 :
V_117 = V_803 ;
break;
case V_403 :
V_117 = V_804 ;
break;
case V_451 :
V_117 = V_805 ;
break;
case V_407 :
V_117 = V_395 ;
break;
case V_408 :
V_117 = V_806 ;
break;
default:
F_247 () ;
}
return F_372 ( V_10 , V_339 -> V_68 , V_52 ,
& V_10 -> V_335 , V_62 ,
V_117 , false ) ;
}
static int F_374 ( struct V_26 * V_27 , struct V_171 * V_172 )
{
struct V_28 * V_29 ;
struct V_9 * V_10 ;
struct V_799 * V_339 = V_172 -> V_96 ;
T_3 V_52 = F_202 ( V_339 -> V_52 ) ;
int V_64 = F_125 ( V_339 -> V_492 ) ;
int V_77 ;
V_29 = F_201 ( V_27 , V_172 -> V_30 ) ;
if ( ! V_29 )
return - V_108 ;
V_10 = V_29 -> V_10 ;
F_216 ( V_29 , F_125 ( V_339 -> V_442 ) ) ;
if ( V_339 -> V_68 == V_378 ) {
F_196 ( V_10 ) ;
F_193 ( V_10 , V_52 , V_64 ) ;
return 0 ;
}
V_77 = F_372 ( V_10 , V_339 -> V_68 , V_52 ,
& V_10 -> V_335 , V_62 ,
V_434 , true ) ;
if ( V_77 ) {
F_233 ( V_10 , V_52 , V_64 ) ;
}
return 0 ;
}
static int F_375 ( struct V_26 * V_27 , struct V_171 * V_172 )
{
struct V_28 * V_29 ;
struct V_9 * V_10 ;
struct V_799 * V_339 = V_172 -> V_96 ;
T_3 V_52 = F_202 ( V_339 -> V_52 ) ;
V_29 = F_201 ( V_27 , V_172 -> V_30 ) ;
if ( ! V_29 )
return - V_108 ;
V_10 = V_29 -> V_10 ;
F_216 ( V_29 , F_125 ( V_339 -> V_442 ) ) ;
F_45 ( V_10 , L_202 ,
( unsigned long long ) V_52 , F_125 ( V_339 -> V_492 ) ) ;
return F_372 ( V_10 , V_339 -> V_68 , V_52 ,
& V_10 -> V_388 , V_62 ,
V_434 , false ) ;
}
static int F_376 ( struct V_26 * V_27 , struct V_171 * V_172 )
{
struct V_28 * V_29 ;
struct V_9 * V_10 ;
T_3 V_52 ;
int V_64 ;
struct V_799 * V_339 = V_172 -> V_96 ;
V_29 = F_201 ( V_27 , V_172 -> V_30 ) ;
if ( ! V_29 )
return - V_108 ;
V_10 = V_29 -> V_10 ;
V_52 = F_202 ( V_339 -> V_52 ) ;
V_64 = F_125 ( V_339 -> V_492 ) ;
F_216 ( V_29 , F_125 ( V_339 -> V_442 ) ) ;
F_196 ( V_10 ) ;
if ( F_244 ( V_10 , V_706 ) ) {
F_340 ( V_10 , V_52 ) ;
switch ( V_172 -> V_169 ) {
case V_500 :
F_193 ( V_10 , V_52 , V_64 ) ;
case V_807 :
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
struct V_808 * V_339 = V_172 -> V_96 ;
struct V_28 * V_29 ;
int V_30 ;
F_378 ( V_27 , V_339 -> V_340 , F_125 ( V_339 -> V_809 ) ) ;
F_24 () ;
F_25 (&connection->peer_devices, peer_device, vnr) {
struct V_9 * V_10 = V_29 -> V_10 ;
if ( V_10 -> V_399 . V_105 == V_702 &&
F_26 ( & V_10 -> V_191 ) == 0 &&
! F_370 ( V_810 , & V_10 -> V_69 ) ) {
V_10 -> V_811 . V_812 = V_66 + V_44 ;
F_379 ( & V_10 -> V_811 ) ;
}
}
F_28 () ;
return 0 ;
}
static int F_380 ( struct V_26 * V_27 , struct V_171 * V_172 )
{
struct V_28 * V_29 ;
struct V_9 * V_10 ;
struct V_799 * V_339 = V_172 -> V_96 ;
struct V_813 * V_814 ;
T_3 V_52 ;
int V_64 ;
V_29 = F_201 ( V_27 , V_172 -> V_30 ) ;
if ( ! V_29 )
return - V_108 ;
V_10 = V_29 -> V_10 ;
V_52 = F_202 ( V_339 -> V_52 ) ;
V_64 = F_125 ( V_339 -> V_492 ) ;
F_216 ( V_29 , F_125 ( V_339 -> V_442 ) ) ;
if ( F_202 ( V_339 -> V_68 ) == V_815 )
F_381 ( V_10 , V_52 , V_64 ) ;
else
F_307 ( V_10 ) ;
if ( ! F_140 ( V_10 ) )
return 0 ;
F_340 ( V_10 , V_52 ) ;
F_196 ( V_10 ) ;
-- V_10 -> V_484 ;
if ( ( V_10 -> V_484 & 0x200 ) == 0x200 )
F_382 ( V_10 , V_10 -> V_484 ) ;
if ( V_10 -> V_484 == 0 ) {
V_814 = F_134 ( sizeof( * V_814 ) , V_213 ) ;
if ( V_814 ) {
V_814 -> V_20 . V_80 = V_816 ;
V_814 -> V_10 = V_10 ;
F_383 ( & V_29 -> V_27 -> V_762 , & V_814 -> V_20 ) ;
} else {
F_45 ( V_10 , L_203 ) ;
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
static void F_385 ( struct V_26 * V_27 , bool V_817 )
{
long V_23 ;
struct V_35 * V_36 ;
F_24 () ;
V_36 = F_32 ( V_27 -> V_35 ) ;
V_23 = V_817 ? V_36 -> V_100 : V_36 -> V_217 ;
F_28 () ;
V_23 *= V_44 ;
if ( V_817 )
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
int F_388 ( struct V_788 * V_789 )
{
struct V_26 * V_27 = V_789 -> V_27 ;
struct V_818 * V_169 = NULL ;
struct V_171 V_172 ;
unsigned long V_819 ;
int V_95 ;
void * V_85 = V_27 -> V_202 . V_173 ;
int V_820 = 0 ;
unsigned int V_170 = F_95 ( V_27 ) ;
int F_55 = V_170 ;
bool V_821 = false ;
struct V_822 V_823 = { . V_824 = 2 } ;
V_95 = F_389 ( V_43 , V_825 , & V_823 ) ;
if ( V_95 < 0 )
F_45 ( V_27 , L_204 , V_95 ) ;
while ( F_114 ( V_789 ) == V_745 ) {
F_342 ( V_789 ) ;
F_23 ( V_27 ) ;
if ( F_289 ( V_826 , & V_27 -> V_69 ) ) {
if ( F_390 ( V_27 ) ) {
F_45 ( V_27 , L_205 ) ;
goto V_634;
}
F_386 ( V_27 ) ;
V_821 = true ;
}
V_819 = V_66 ;
V_95 = F_65 ( V_27 -> V_202 . V_83 , V_85 , F_55 - V_820 , 0 ) ;
if ( F_190 ( V_95 > 0 ) ) {
V_820 += V_95 ;
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
F_45 ( V_27 , L_206 ) ;
goto V_634;
} else if ( V_95 == - V_144 ) {
if ( F_391 ( V_27 -> V_218 , V_819 ) )
continue;
if ( V_821 ) {
F_45 ( V_27 , L_207 ) ;
goto V_634;
}
F_111 ( V_826 , & V_27 -> V_69 ) ;
continue;
} else if ( V_95 == - V_146 ) {
F_112 ( V_43 ) ;
continue;
} else {
F_45 ( V_27 , L_7 , V_95 ) ;
goto V_634;
}
if ( V_820 == F_55 && V_169 == NULL ) {
if ( F_96 ( V_27 , V_27 -> V_202 . V_173 , & V_172 ) )
goto V_634;
V_169 = & V_827 [ V_172 . V_169 ] ;
if ( V_172 . V_169 >= F_343 ( V_827 ) || ! V_169 -> V_749 ) {
F_45 ( V_27 , L_208 ,
F_276 ( V_172 . V_169 ) , V_172 . V_169 ) ;
goto V_614;
}
F_55 = V_170 + V_169 -> V_750 ;
if ( V_172 . V_64 != F_55 - V_170 ) {
F_45 ( V_27 , L_209 ,
V_172 . V_169 , V_172 . V_64 ) ;
goto V_634;
}
}
if ( V_820 == F_55 ) {
bool V_77 ;
V_77 = V_169 -> V_749 ( V_27 , & V_172 ) ;
if ( V_77 ) {
F_45 ( V_27 , L_210 , V_169 -> V_749 ) ;
goto V_634;
}
V_27 -> V_218 = V_66 ;
if ( V_169 == & V_827 [ V_828 ] ) {
F_387 ( V_27 ) ;
V_821 = false ;
}
V_85 = V_27 -> V_202 . V_173 ;
V_820 = 0 ;
F_55 = V_170 ;
V_169 = NULL ;
}
}
if ( 0 ) {
V_634:
F_71 ( V_27 , F_72 ( V_105 , V_755 ) , V_107 ) ;
F_392 ( V_27 ) ;
}
if ( 0 ) {
V_614:
F_71 ( V_27 , F_72 ( V_105 , V_151 ) , V_107 ) ;
}
F_68 ( V_27 , L_211 ) ;
return 0 ;
}
void F_393 ( struct V_829 * V_830 )
{
struct V_28 * V_29 =
F_189 ( V_830 , struct V_28 , V_439 ) ;
struct V_26 * V_27 = V_29 -> V_27 ;
struct V_9 * V_10 = V_29 -> V_10 ;
struct V_35 * V_36 ;
int V_831 , V_77 ;
F_24 () ;
V_36 = F_32 ( V_27 -> V_35 ) ;
V_831 = V_36 -> V_831 ;
F_28 () ;
if ( V_831 )
F_394 ( V_27 -> V_202 . V_83 ) ;
V_77 = F_59 ( V_10 ) ;
F_29 ( & V_10 -> V_32 , V_33 ) ;
if ( V_77 ) {
F_71 ( V_27 , F_72 ( V_105 , V_755 ) , V_107 ) ;
return;
}
if ( V_831 )
F_395 ( V_27 -> V_202 . V_83 ) ;
return;
}
