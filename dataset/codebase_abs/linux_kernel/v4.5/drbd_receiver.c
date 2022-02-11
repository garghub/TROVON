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
unsigned int V_53 , bool V_54 , T_4 V_55 ) __must_hold( T_5 )
{
struct V_9 * V_10 = V_29 -> V_10 ;
struct V_18 * V_19 ;
struct V_1 * V_1 = NULL ;
unsigned V_56 = ( V_53 + V_49 - 1 ) >> V_57 ;
if ( F_43 ( V_10 , V_58 ) )
return NULL ;
V_19 = F_44 ( V_59 , V_55 & ~ V_60 ) ;
if ( ! V_19 ) {
if ( ! ( V_55 & V_61 ) )
F_45 ( V_10 , L_5 , V_62 ) ;
return NULL ;
}
if ( V_54 && V_53 ) {
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
static void F_128 ( struct V_26 * V_27 )
{
int V_95 ;
struct V_28 * V_29 ;
int V_30 ;
if ( V_27 -> V_24 -> V_244 >= V_245 ) {
F_24 () ;
F_25 (&connection->peer_devices, peer_device, vnr) {
struct V_9 * V_10 = V_29 -> V_10 ;
if ( ! F_129 ( V_10 ) )
continue;
F_27 ( & V_10 -> V_32 ) ;
F_28 () ;
V_10 -> V_246 = V_66 ;
F_111 ( V_247 , & V_10 -> V_69 ) ;
V_95 = F_130 ( V_10 -> V_248 -> V_249 ,
V_213 , NULL ) ;
F_106 ( V_247 , & V_10 -> V_69 ) ;
if ( V_95 ) {
F_68 ( V_10 , L_27 , V_95 ) ;
F_131 ( V_27 -> V_24 , NULL , V_250 ) ;
}
F_132 ( V_10 ) ;
F_29 ( & V_10 -> V_32 , V_33 ) ;
F_24 () ;
if ( V_95 )
break;
}
F_28 () ;
}
}
static enum V_251 F_133 ( struct V_26 * V_27 ,
struct V_252 * V_253 ,
enum V_254 V_255 )
{
int V_256 ;
struct V_252 * V_257 ;
enum V_251 V_95 = V_258 ;
F_11 ( & V_27 -> V_259 ) ;
do {
V_257 = NULL ;
V_256 = F_26 ( & V_253 -> V_256 ) ;
switch ( V_255 & ~ V_260 ) {
case V_261 :
F_134 ( & V_253 -> V_262 ) ;
break;
case V_263 :
F_111 ( V_264 , & V_253 -> V_69 ) ;
break;
case V_265 :
break;
}
if ( V_256 != 0 &&
F_26 ( & V_253 -> V_262 ) == 0 &&
( F_69 ( V_264 , & V_253 -> V_69 ) || V_255 & V_260 ) ) {
if ( ! ( V_255 & V_260 ) ) {
F_12 ( & V_27 -> V_259 ) ;
F_135 ( V_253 -> V_27 , V_253 -> V_266 , V_256 ) ;
F_11 ( & V_27 -> V_259 ) ;
}
#if 0
if (test_bit(DE_HAVE_BARRIER_NUMBER, &epoch->flags))
dec_unacked(epoch->connection);
#endif
if ( V_27 -> V_267 != V_253 ) {
V_257 = F_136 ( V_253 -> V_21 . V_268 , struct V_252 , V_21 ) ;
F_137 ( & V_253 -> V_21 ) ;
V_255 = V_265 | ( V_255 & V_260 ) ;
V_27 -> V_269 -- ;
F_52 ( V_253 ) ;
if ( V_95 == V_258 )
V_95 = V_270 ;
} else {
V_253 -> V_69 = 0 ;
F_101 ( & V_253 -> V_256 , 0 ) ;
if ( V_95 == V_258 )
V_95 = V_271 ;
}
}
if ( ! V_257 )
break;
V_253 = V_257 ;
} while ( 1 );
F_12 ( & V_27 -> V_259 ) ;
return V_95 ;
}
static enum V_272
F_138 ( struct V_273 * V_274 , enum V_272 V_275 )
{
struct V_276 * V_277 ;
V_277 = F_32 ( V_274 -> V_276 ) ;
if ( V_275 == V_245 && ! V_277 -> V_278 )
V_275 = V_250 ;
if ( V_275 == V_250 && ! V_277 -> V_279 )
V_275 = V_280 ;
return V_275 ;
}
void F_131 ( struct V_281 * V_24 , struct V_273 * V_274 ,
enum V_272 V_275 )
{
struct V_9 * V_10 ;
enum V_272 V_282 ;
int V_30 ;
static char * V_283 [] = {
[ V_280 ] = L_28 ,
[ V_250 ] = L_29 ,
[ V_245 ] = L_30 ,
} ;
V_282 = V_24 -> V_244 ;
if ( V_275 != V_245 )
V_275 = F_139 ( V_282 , V_275 ) ;
F_24 () ;
F_25 (&resource->devices, device, vnr) {
if ( F_129 ( V_10 ) ) {
V_275 = F_138 ( V_10 -> V_248 , V_275 ) ;
if ( V_10 -> V_248 == V_274 )
V_274 = NULL ;
F_132 ( V_10 ) ;
}
}
if ( V_274 )
V_275 = F_138 ( V_274 , V_275 ) ;
F_28 () ;
V_24 -> V_244 = V_275 ;
if ( V_282 != V_24 -> V_244 || V_275 == V_245 )
F_68 ( V_24 , L_31 , V_283 [ V_24 -> V_244 ] ) ;
}
int F_140 ( struct V_9 * V_10 ,
struct V_18 * V_19 ,
const unsigned V_284 , const int V_285 )
{
struct V_286 * V_287 = NULL ;
struct V_286 * V_286 ;
struct V_1 * V_1 = V_19 -> V_67 ;
T_3 V_52 = V_19 -> V_6 . V_52 ;
unsigned V_53 = V_19 -> V_6 . V_64 ;
unsigned V_288 = 0 ;
unsigned V_56 = ( V_53 + V_49 - 1 ) >> V_57 ;
int V_77 = - V_289 ;
if ( V_19 -> V_69 & V_290 ) {
F_141 ( V_19 -> V_29 -> V_27 ) ;
V_19 -> V_65 = V_66 ;
V_19 -> V_69 |= V_291 ;
F_20 ( & V_10 -> V_24 -> V_25 ) ;
F_142 ( & V_19 -> V_20 . V_21 , & V_10 -> V_292 ) ;
F_21 ( & V_10 -> V_24 -> V_25 ) ;
if ( F_143 ( V_10 -> V_248 -> V_249 ,
V_52 , V_53 >> 9 , V_213 , false ) )
V_19 -> V_69 |= V_293 ;
F_144 ( V_19 ) ;
return 0 ;
}
if ( V_19 -> V_69 & V_294 )
V_56 = 1 ;
V_295:
V_286 = F_145 ( V_213 , V_56 ) ;
if ( ! V_286 ) {
F_45 ( V_10 , L_32 , V_56 ) ;
goto V_63;
}
V_286 -> V_296 . V_297 = V_52 ;
V_286 -> V_298 = V_10 -> V_248 -> V_249 ;
V_286 -> V_299 = V_284 ;
V_286 -> V_300 = V_19 ;
V_286 -> V_301 = V_302 ;
V_286 -> V_303 = V_287 ;
V_287 = V_286 ;
++ V_288 ;
if ( V_284 & V_304 ) {
V_286 -> V_296 . V_305 = V_53 ;
goto V_306;
}
F_146 (page) {
unsigned V_5 = F_77 ( unsigned , V_53 , V_49 ) ;
if ( ! F_147 ( V_286 , V_1 , V_5 , 0 ) ) {
if ( V_286 -> V_307 == 0 ) {
F_45 ( V_10 ,
L_33
L_34 ,
V_5 , ( V_308 ) V_286 -> V_296 . V_297 ) ;
V_77 = - V_309 ;
goto V_63;
}
goto V_295;
}
V_53 -= V_5 ;
V_52 += V_5 >> 9 ;
-- V_56 ;
}
F_53 ( V_10 , V_53 == 0 ) ;
V_306:
F_53 ( V_10 , V_1 == NULL ) ;
F_101 ( & V_19 -> V_72 , V_288 ) ;
V_19 -> V_65 = V_66 ;
V_19 -> V_69 |= V_291 ;
do {
V_286 = V_287 ;
V_287 = V_287 -> V_303 ;
V_286 -> V_303 = NULL ;
F_148 ( V_10 , V_285 , V_286 ) ;
} while ( V_287 );
return 0 ;
V_63:
while ( V_287 ) {
V_286 = V_287 ;
V_287 = V_287 -> V_303 ;
F_149 ( V_286 ) ;
}
return V_77 ;
}
static void F_150 ( struct V_9 * V_10 ,
struct V_18 * V_19 )
{
struct V_310 * V_6 = & V_19 -> V_6 ;
F_151 ( & V_10 -> V_311 , V_6 ) ;
F_48 ( V_6 ) ;
if ( V_6 -> V_312 )
F_41 ( & V_10 -> V_313 ) ;
}
static void F_141 ( struct V_26 * V_27 )
{
struct V_28 * V_29 ;
int V_30 ;
F_24 () ;
F_25 (&connection->peer_devices, peer_device, vnr) {
struct V_9 * V_10 = V_29 -> V_10 ;
F_27 ( & V_10 -> V_32 ) ;
F_28 () ;
F_64 ( V_10 , & V_10 -> V_292 ) ;
F_29 ( & V_10 -> V_32 , V_33 ) ;
F_24 () ;
}
F_28 () ;
}
static int F_152 ( struct V_26 * V_27 , struct V_171 * V_172 )
{
int V_95 ;
struct V_314 * V_315 = V_172 -> V_96 ;
struct V_252 * V_253 ;
V_27 -> V_267 -> V_266 = V_315 -> V_316 ;
V_27 -> V_267 -> V_27 = V_27 ;
V_95 = F_133 ( V_27 , V_27 -> V_267 , V_263 ) ;
switch ( V_27 -> V_24 -> V_244 ) {
case V_280 :
if ( V_95 == V_271 )
return 0 ;
V_253 = F_153 ( sizeof( struct V_252 ) , V_213 ) ;
if ( V_253 )
break;
else
F_35 ( V_27 , L_35 ) ;
case V_245 :
case V_250 :
F_141 ( V_27 ) ;
F_128 ( V_27 ) ;
if ( F_26 ( & V_27 -> V_267 -> V_256 ) ) {
V_253 = F_153 ( sizeof( struct V_252 ) , V_213 ) ;
if ( V_253 )
break;
}
return 0 ;
default:
F_45 ( V_27 , L_36 ,
V_27 -> V_24 -> V_244 ) ;
return - V_108 ;
}
V_253 -> V_69 = 0 ;
F_101 ( & V_253 -> V_256 , 0 ) ;
F_101 ( & V_253 -> V_262 , 0 ) ;
F_11 ( & V_27 -> V_259 ) ;
if ( F_26 ( & V_27 -> V_267 -> V_256 ) ) {
F_154 ( & V_253 -> V_21 , & V_27 -> V_267 -> V_21 ) ;
V_27 -> V_267 = V_253 ;
V_27 -> V_269 ++ ;
} else {
F_52 ( V_253 ) ;
}
F_12 ( & V_27 -> V_259 ) ;
return 0 ;
}
static struct V_18 *
F_155 ( struct V_28 * V_29 , T_2 V_51 , T_3 V_52 ,
struct V_171 * V_172 ) __must_hold( T_5 )
{
struct V_9 * V_10 = V_29 -> V_10 ;
const T_3 V_317 = F_156 ( V_10 -> V_318 ) ;
struct V_18 * V_19 ;
struct V_1 * V_1 ;
int V_319 , V_77 ;
unsigned int V_53 = V_172 -> V_64 , V_320 ;
void * V_321 = V_29 -> V_27 -> V_322 ;
void * V_323 = V_29 -> V_27 -> V_324 ;
unsigned long * V_96 ;
struct V_325 * V_326 = ( V_172 -> V_169 == V_327 ) ? V_172 -> V_96 : NULL ;
V_319 = 0 ;
if ( ! V_326 && V_29 -> V_27 -> V_328 ) {
V_319 = F_157 ( V_29 -> V_27 -> V_328 ) ;
V_77 = F_74 ( V_29 -> V_27 , V_321 , V_319 ) ;
if ( V_77 )
return NULL ;
V_53 -= V_319 ;
}
if ( V_326 ) {
F_53 ( V_29 , V_53 == 0 ) ;
V_53 = F_125 ( V_326 -> V_64 ) ;
}
if ( ! F_55 ( F_158 ( V_53 , 512 ) ) )
return NULL ;
if ( ! V_326 && ! F_55 ( V_53 <= V_48 ) )
return NULL ;
if ( V_52 + ( V_53 >> 9 ) > V_317 ) {
F_45 ( V_10 , L_37
L_38 ,
( unsigned long long ) V_317 ,
( unsigned long long ) V_52 , V_53 ) ;
return NULL ;
}
V_19 = F_42 ( V_29 , V_51 , V_52 , V_53 , V_326 == NULL , V_213 ) ;
if ( ! V_19 )
return NULL ;
V_19 -> V_69 |= V_329 ;
if ( V_326 )
return V_19 ;
V_320 = V_53 ;
V_1 = V_19 -> V_67 ;
F_146 (page) {
unsigned V_5 = F_77 ( int , V_320 , V_49 ) ;
V_96 = F_159 ( V_1 ) ;
V_77 = F_74 ( V_29 -> V_27 , V_96 , V_5 ) ;
if ( F_43 ( V_10 , V_330 ) ) {
F_45 ( V_10 , L_39 ) ;
V_96 [ 0 ] = V_96 [ 0 ] ^ ( unsigned long ) - 1 ;
}
F_160 ( V_1 ) ;
if ( V_77 ) {
F_60 ( V_10 , V_19 ) ;
return NULL ;
}
V_320 -= V_5 ;
}
if ( V_319 ) {
F_161 ( V_29 -> V_27 -> V_328 , V_19 , V_323 ) ;
if ( memcmp ( V_321 , V_323 , V_319 ) ) {
F_45 ( V_10 , L_40 ,
( unsigned long long ) V_52 , V_53 ) ;
F_60 ( V_10 , V_19 ) ;
return NULL ;
}
}
V_10 -> V_331 += V_53 >> 9 ;
return V_19 ;
}
static int F_162 ( struct V_28 * V_29 , int V_53 )
{
struct V_1 * V_1 ;
int V_77 = 0 ;
void * V_96 ;
if ( ! V_53 )
return 0 ;
V_1 = F_30 ( V_29 , 1 , 1 ) ;
V_96 = F_159 ( V_1 ) ;
while ( V_53 ) {
unsigned int V_5 = F_77 ( int , V_53 , V_49 ) ;
V_77 = F_74 ( V_29 -> V_27 , V_96 , V_5 ) ;
if ( V_77 )
break;
V_53 -= V_5 ;
}
F_160 ( V_1 ) ;
F_39 ( V_29 -> V_10 , V_1 , 0 ) ;
return V_77 ;
}
static int F_163 ( struct V_28 * V_29 , struct V_332 * V_333 ,
T_3 V_52 , int V_53 )
{
struct V_334 V_335 ;
struct V_336 V_337 ;
struct V_286 * V_286 ;
int V_319 , V_77 , F_55 ;
void * V_321 = V_29 -> V_27 -> V_322 ;
void * V_323 = V_29 -> V_27 -> V_324 ;
V_319 = 0 ;
if ( V_29 -> V_27 -> V_328 ) {
V_319 = F_157 ( V_29 -> V_27 -> V_328 ) ;
V_77 = F_74 ( V_29 -> V_27 , V_321 , V_319 ) ;
if ( V_77 )
return V_77 ;
V_53 -= V_319 ;
}
V_29 -> V_10 -> V_331 += V_53 >> 9 ;
V_286 = V_333 -> V_338 ;
F_53 ( V_29 -> V_10 , V_52 == V_286 -> V_296 . V_297 ) ;
F_164 (bvec, bio, iter) {
void * V_339 = F_159 ( V_335 . V_340 ) + V_335 . V_341 ;
F_55 = F_77 ( int , V_53 , V_335 . V_342 ) ;
V_77 = F_74 ( V_29 -> V_27 , V_339 , F_55 ) ;
F_160 ( V_335 . V_340 ) ;
if ( V_77 )
return V_77 ;
V_53 -= F_55 ;
}
if ( V_319 ) {
F_165 ( V_29 -> V_27 -> V_328 , V_286 , V_323 ) ;
if ( memcmp ( V_321 , V_323 , V_319 ) ) {
F_45 ( V_29 , L_41 ) ;
return - V_234 ;
}
}
F_53 ( V_29 -> V_10 , V_53 == 0 ) ;
return 0 ;
}
static int F_166 ( struct V_343 * V_20 , int V_344 )
{
struct V_18 * V_19 =
F_167 ( V_20 , struct V_18 , V_20 ) ;
struct V_28 * V_29 = V_19 -> V_29 ;
struct V_9 * V_10 = V_29 -> V_10 ;
T_3 V_52 = V_19 -> V_6 . V_52 ;
int V_77 ;
F_53 ( V_10 , F_54 ( & V_19 -> V_6 ) ) ;
if ( F_168 ( ( V_19 -> V_69 & V_293 ) == 0 ) ) {
F_169 ( V_10 , V_52 , V_19 -> V_6 . V_64 ) ;
V_77 = F_170 ( V_29 , V_345 , V_19 ) ;
} else {
F_171 ( V_10 , V_52 , V_19 -> V_6 . V_64 ) ;
V_77 = F_170 ( V_29 , V_346 , V_19 ) ;
}
F_172 ( V_10 ) ;
return V_77 ;
}
static int F_173 ( struct V_28 * V_29 , T_3 V_52 ,
struct V_171 * V_172 ) __releases( T_5 )
{
struct V_9 * V_10 = V_29 -> V_10 ;
struct V_18 * V_19 ;
V_19 = F_155 ( V_29 , V_347 , V_52 , V_172 ) ;
if ( ! V_19 )
goto V_63;
F_174 ( V_10 ) ;
F_175 ( V_10 ) ;
V_19 -> V_20 . V_80 = F_166 ;
V_19 -> V_65 = V_66 ;
F_20 ( & V_10 -> V_24 -> V_25 ) ;
F_142 ( & V_19 -> V_20 . V_21 , & V_10 -> V_348 ) ;
F_21 ( & V_10 -> V_24 -> V_25 ) ;
F_38 ( V_172 -> V_64 >> 9 , & V_10 -> V_349 ) ;
if ( F_140 ( V_10 , V_19 , V_350 , V_351 ) == 0 )
return 0 ;
F_45 ( V_10 , L_42 ) ;
F_20 ( & V_10 -> V_24 -> V_25 ) ;
F_137 ( & V_19 -> V_20 . V_21 ) ;
F_21 ( & V_10 -> V_24 -> V_25 ) ;
F_60 ( V_10 , V_19 ) ;
V_63:
F_132 ( V_10 ) ;
return - V_108 ;
}
static struct V_332 *
F_176 ( struct V_9 * V_10 , struct V_352 * V_353 , T_2 V_51 ,
T_3 V_52 , bool V_354 , const char * V_355 )
{
struct V_332 * V_333 ;
V_333 = (struct V_332 * ) ( unsigned long ) V_51 ;
if ( F_177 ( V_353 , V_52 , & V_333 -> V_6 ) && V_333 -> V_6 . T_5 )
return V_333 ;
if ( ! V_354 ) {
F_45 ( V_10 , L_43 , V_355 ,
( unsigned long ) V_51 , ( unsigned long long ) V_52 ) ;
}
return NULL ;
}
static int F_178 ( struct V_26 * V_27 , struct V_171 * V_172 )
{
struct V_28 * V_29 ;
struct V_9 * V_10 ;
struct V_332 * V_333 ;
T_3 V_52 ;
int V_77 ;
struct V_356 * V_315 = V_172 -> V_96 ;
V_29 = F_179 ( V_27 , V_172 -> V_30 ) ;
if ( ! V_29 )
return - V_108 ;
V_10 = V_29 -> V_10 ;
V_52 = F_180 ( V_315 -> V_52 ) ;
F_20 ( & V_10 -> V_24 -> V_25 ) ;
V_333 = F_176 ( V_10 , & V_10 -> V_357 , V_315 -> V_68 , V_52 , false , V_62 ) ;
F_21 ( & V_10 -> V_24 -> V_25 ) ;
if ( F_181 ( ! V_333 ) )
return - V_108 ;
V_77 = F_163 ( V_29 , V_333 , V_52 , V_172 -> V_64 ) ;
if ( ! V_77 )
F_182 ( V_333 , V_358 ) ;
return V_77 ;
}
static int F_183 ( struct V_26 * V_27 , struct V_171 * V_172 )
{
struct V_28 * V_29 ;
struct V_9 * V_10 ;
T_3 V_52 ;
int V_77 ;
struct V_356 * V_315 = V_172 -> V_96 ;
V_29 = F_179 ( V_27 , V_172 -> V_30 ) ;
if ( ! V_29 )
return - V_108 ;
V_10 = V_29 -> V_10 ;
V_52 = F_180 ( V_315 -> V_52 ) ;
F_53 ( V_10 , V_315 -> V_68 == V_347 ) ;
if ( F_129 ( V_10 ) ) {
V_77 = F_173 ( V_29 , V_52 , V_172 ) ;
} else {
if ( F_184 ( & V_359 ) )
F_45 ( V_10 , L_44 ) ;
V_77 = F_162 ( V_29 , V_172 -> V_64 ) ;
F_185 ( V_29 , V_346 , V_315 , V_172 -> V_64 ) ;
}
F_38 ( V_172 -> V_64 >> 9 , & V_10 -> V_360 ) ;
return V_77 ;
}
static void F_186 ( struct V_9 * V_10 ,
T_3 V_52 , int V_64 )
{
struct V_310 * V_6 ;
struct V_332 * V_333 ;
F_187 (i, &device->write_requests, sector, size) {
if ( ! V_6 -> T_5 )
continue;
V_333 = F_167 ( V_6 , struct V_332 , V_6 ) ;
if ( V_333 -> V_361 & V_362 ||
! ( V_333 -> V_361 & V_363 ) )
continue;
F_188 ( V_333 , V_364 , NULL ) ;
}
}
static int F_189 ( struct V_343 * V_20 , int V_365 )
{
struct V_18 * V_19 =
F_167 ( V_20 , struct V_18 , V_20 ) ;
struct V_28 * V_29 = V_19 -> V_29 ;
struct V_9 * V_10 = V_29 -> V_10 ;
T_3 V_52 = V_19 -> V_6 . V_52 ;
int V_77 = 0 , V_366 ;
if ( V_19 -> V_69 & V_367 ) {
if ( F_168 ( ( V_19 -> V_69 & V_293 ) == 0 ) ) {
V_366 = ( V_10 -> V_368 . V_105 >= V_369 &&
V_10 -> V_368 . V_105 <= V_370 &&
V_19 -> V_69 & V_371 ) ?
V_345 : V_372 ;
V_77 = F_170 ( V_29 , V_366 , V_19 ) ;
if ( V_366 == V_345 )
F_169 ( V_10 , V_52 , V_19 -> V_6 . V_64 ) ;
} else {
V_77 = F_170 ( V_29 , V_346 , V_19 ) ;
}
F_172 ( V_10 ) ;
}
if ( V_19 -> V_69 & V_373 ) {
F_20 ( & V_10 -> V_24 -> V_25 ) ;
F_53 ( V_10 , ! F_54 ( & V_19 -> V_6 ) ) ;
F_150 ( V_10 , V_19 ) ;
if ( V_19 -> V_69 & V_374 )
F_186 ( V_10 , V_52 , V_19 -> V_6 . V_64 ) ;
F_21 ( & V_10 -> V_24 -> V_25 ) ;
} else
F_53 ( V_10 , F_54 ( & V_19 -> V_6 ) ) ;
F_133 ( V_29 -> V_27 , V_19 -> V_253 , V_261 + ( V_365 ? V_260 : 0 ) ) ;
return V_77 ;
}
static int F_190 ( struct V_343 * V_20 , enum V_168 V_375 )
{
struct V_18 * V_19 =
F_167 ( V_20 , struct V_18 , V_20 ) ;
struct V_28 * V_29 = V_19 -> V_29 ;
int V_77 ;
V_77 = F_170 ( V_29 , V_375 , V_19 ) ;
F_172 ( V_29 -> V_10 ) ;
return V_77 ;
}
static int F_191 ( struct V_343 * V_20 , int V_344 )
{
return F_190 ( V_20 , V_376 ) ;
}
static int F_192 ( struct V_343 * V_20 , int V_344 )
{
struct V_18 * V_19 =
F_167 ( V_20 , struct V_18 , V_20 ) ;
struct V_26 * V_27 = V_19 -> V_29 -> V_27 ;
return F_190 ( V_20 , V_27 -> V_186 >= 100 ?
V_377 : V_376 ) ;
}
static bool F_193 ( T_7 V_47 , T_7 V_378 )
{
return ( V_379 ) V_47 - ( V_379 ) V_378 > 0 ;
}
static T_7 F_194 ( T_7 V_47 , T_7 V_378 )
{
return F_193 ( V_47 , V_378 ) ? V_47 : V_378 ;
}
static void F_195 ( struct V_28 * V_29 , unsigned int V_184 )
{
struct V_9 * V_10 = V_29 -> V_10 ;
unsigned int V_380 ;
if ( F_69 ( V_205 , & V_29 -> V_27 -> V_69 ) ) {
F_11 ( & V_10 -> V_381 ) ;
V_380 = F_194 ( V_10 -> V_184 , V_184 ) ;
V_10 -> V_184 = V_380 ;
F_12 ( & V_10 -> V_381 ) ;
if ( V_184 == V_380 )
F_41 ( & V_10 -> V_382 ) ;
}
}
static inline int F_196 ( T_3 V_383 , int V_384 , T_3 V_385 , int V_386 )
{
return ! ( ( V_383 + ( V_384 >> 9 ) <= V_385 ) || ( V_383 >= V_385 + ( V_386 >> 9 ) ) ) ;
}
static bool F_197 ( struct V_9 * V_10 , struct V_18 * V_19 )
{
struct V_18 * V_387 ;
bool V_95 = 0 ;
F_20 ( & V_10 -> V_24 -> V_25 ) ;
F_198 (rs_req, &device->sync_ee, w.list) {
if ( F_196 ( V_19 -> V_6 . V_52 , V_19 -> V_6 . V_64 ,
V_387 -> V_6 . V_52 , V_387 -> V_6 . V_64 ) ) {
V_95 = 1 ;
break;
}
}
F_21 ( & V_10 -> V_24 -> V_25 ) ;
return V_95 ;
}
static int F_199 ( struct V_28 * V_29 , const T_7 V_184 )
{
struct V_9 * V_10 = V_29 -> V_10 ;
F_31 ( V_37 ) ;
long V_180 ;
int V_388 = 0 , V_389 ;
if ( ! F_69 ( V_205 , & V_29 -> V_27 -> V_69 ) )
return 0 ;
F_11 ( & V_10 -> V_381 ) ;
for (; ; ) {
if ( ! F_193 ( V_184 - 1 , V_10 -> V_184 ) ) {
V_10 -> V_184 = F_194 ( V_10 -> V_184 , V_184 ) ;
break;
}
if ( F_34 ( V_43 ) ) {
V_388 = - V_98 ;
break;
}
F_24 () ;
V_389 = F_32 ( V_29 -> V_27 -> V_35 ) -> V_390 ;
F_28 () ;
if ( ! V_389 )
break;
F_33 ( & V_10 -> V_382 , & V_37 , V_42 ) ;
F_12 ( & V_10 -> V_381 ) ;
F_24 () ;
V_180 = F_32 ( V_29 -> V_27 -> V_35 ) -> V_100 * V_44 / 10 ;
F_28 () ;
V_180 = F_36 ( V_180 ) ;
F_11 ( & V_10 -> V_381 ) ;
if ( ! V_180 ) {
V_388 = - V_143 ;
F_45 ( V_10 , L_45 ) ;
break;
}
}
F_12 ( & V_10 -> V_381 ) ;
F_37 ( & V_10 -> V_382 , & V_37 ) ;
return V_388 ;
}
static unsigned long F_200 ( T_7 V_391 )
{
return ( V_391 & V_392 ? V_393 : 0 ) |
( V_391 & V_394 ? V_395 : 0 ) |
( V_391 & V_396 ? V_397 : 0 ) |
( V_391 & V_398 ? V_304 : 0 ) ;
}
static void F_201 ( struct V_9 * V_10 , T_3 V_52 ,
unsigned int V_64 )
{
struct V_310 * V_6 ;
V_399:
F_187 (i, &device->write_requests, sector, size) {
struct V_332 * V_333 ;
struct V_400 V_401 ;
if ( ! V_6 -> T_5 )
continue;
V_333 = F_167 ( V_6 , struct V_332 , V_6 ) ;
if ( ! ( V_333 -> V_361 & V_363 ) )
continue;
V_333 -> V_361 &= ~ V_363 ;
F_188 ( V_333 , V_402 , & V_401 ) ;
F_21 ( & V_10 -> V_24 -> V_25 ) ;
if ( V_401 . V_286 )
F_202 ( V_10 , & V_401 ) ;
F_20 ( & V_10 -> V_24 -> V_25 ) ;
goto V_399;
}
}
static int F_203 ( struct V_9 * V_10 ,
struct V_18 * V_19 )
{
struct V_26 * V_27 = V_19 -> V_29 -> V_27 ;
bool V_403 = F_69 ( V_205 , & V_27 -> V_69 ) ;
T_3 V_52 = V_19 -> V_6 . V_52 ;
const unsigned int V_64 = V_19 -> V_6 . V_64 ;
struct V_310 * V_6 ;
bool V_404 ;
int V_77 ;
F_204 ( & V_10 -> V_311 , & V_19 -> V_6 ) ;
V_399:
F_187 (i, &device->write_requests, sector, size) {
if ( V_6 == & V_19 -> V_6 )
continue;
if ( V_6 -> V_405 )
continue;
if ( ! V_6 -> T_5 ) {
V_77 = F_205 ( V_10 , V_6 ) ;
if ( V_77 )
goto V_104;
goto V_399;
}
V_404 = V_6 -> V_52 == V_52 && V_6 -> V_64 == V_64 ;
if ( V_403 ) {
bool V_406 = V_6 -> V_52 <= V_52 && V_6 -> V_52 +
( V_6 -> V_64 >> 9 ) >= V_52 + ( V_64 >> 9 ) ;
if ( ! V_404 )
F_206 ( V_10 , L_46
L_47
L_48 ,
( unsigned long long ) V_6 -> V_52 , V_6 -> V_64 ,
( unsigned long long ) V_52 , V_64 ,
V_406 ? L_49 : L_50 ) ;
V_19 -> V_20 . V_80 = V_406 ? F_191 :
F_192 ;
F_142 ( & V_19 -> V_20 . V_21 , & V_10 -> V_78 ) ;
F_207 ( V_27 -> V_225 , & V_19 -> V_29 -> V_407 ) ;
V_77 = - V_408 ;
goto V_104;
} else {
struct V_332 * V_333 =
F_167 ( V_6 , struct V_332 , V_6 ) ;
if ( ! V_404 )
F_206 ( V_10 , L_46
L_51 ,
( unsigned long long ) V_6 -> V_52 , V_6 -> V_64 ,
( unsigned long long ) V_52 , V_64 ) ;
if ( V_333 -> V_361 & V_362 ||
! ( V_333 -> V_361 & V_363 ) ) {
V_77 = F_205 ( V_10 , & V_333 -> V_6 ) ;
if ( V_77 ) {
F_208 ( V_27 , F_72 ( V_105 , V_409 ) , V_107 ) ;
F_201 ( V_10 , V_52 , V_64 ) ;
goto V_104;
}
goto V_399;
}
V_19 -> V_69 |= V_374 ;
}
}
V_77 = 0 ;
V_104:
if ( V_77 )
F_150 ( V_10 , V_19 ) ;
return V_77 ;
}
static int F_209 ( struct V_26 * V_27 , struct V_171 * V_172 )
{
struct V_28 * V_29 ;
struct V_9 * V_10 ;
struct V_35 * V_36 ;
T_3 V_52 ;
struct V_18 * V_19 ;
struct V_356 * V_315 = V_172 -> V_96 ;
T_7 V_184 = F_125 ( V_315 -> V_410 ) ;
int V_284 = V_350 ;
T_7 V_411 ;
int V_77 , V_389 ;
V_29 = F_179 ( V_27 , V_172 -> V_30 ) ;
if ( ! V_29 )
return - V_108 ;
V_10 = V_29 -> V_10 ;
if ( ! F_129 ( V_10 ) ) {
int V_79 ;
V_77 = F_199 ( V_29 , V_184 ) ;
F_185 ( V_29 , V_346 , V_315 , V_172 -> V_64 ) ;
F_210 ( & V_27 -> V_267 -> V_256 ) ;
V_79 = F_162 ( V_29 , V_172 -> V_64 ) ;
if ( ! V_77 )
V_77 = V_79 ;
return V_77 ;
}
V_52 = F_180 ( V_315 -> V_52 ) ;
V_19 = F_155 ( V_29 , V_315 -> V_68 , V_52 , V_172 ) ;
if ( ! V_19 ) {
F_132 ( V_10 ) ;
return - V_108 ;
}
V_19 -> V_20 . V_80 = F_189 ;
V_19 -> V_65 = V_66 ;
V_19 -> V_69 |= V_412 ;
V_411 = F_125 ( V_315 -> V_411 ) ;
V_284 |= F_200 ( V_411 ) ;
if ( V_172 -> V_169 == V_327 ) {
struct V_413 * V_414 = F_211 ( V_10 -> V_248 -> V_249 ) ;
V_19 -> V_69 |= V_294 ;
if ( ! F_212 ( V_414 ) )
V_19 -> V_69 |= V_290 ;
F_53 ( V_29 , V_19 -> V_6 . V_64 > 0 ) ;
F_53 ( V_29 , V_284 & V_304 ) ;
F_53 ( V_29 , V_19 -> V_67 == NULL ) ;
} else if ( V_19 -> V_67 == NULL ) {
F_53 ( V_10 , V_19 -> V_6 . V_64 == 0 ) ;
F_53 ( V_10 , V_411 & V_396 ) ;
}
if ( V_411 & V_415 )
V_19 -> V_69 |= V_371 ;
F_11 ( & V_27 -> V_259 ) ;
V_19 -> V_253 = V_27 -> V_267 ;
F_210 ( & V_19 -> V_253 -> V_256 ) ;
F_210 ( & V_19 -> V_253 -> V_262 ) ;
F_12 ( & V_27 -> V_259 ) ;
F_24 () ;
V_36 = F_32 ( V_29 -> V_27 -> V_35 ) ;
V_389 = V_36 -> V_390 ;
if ( V_29 -> V_27 -> V_186 < 100 ) {
switch ( V_36 -> V_416 ) {
case V_417 :
V_411 |= V_418 ;
break;
case V_419 :
V_411 |= V_420 ;
break;
}
}
F_28 () ;
if ( V_411 & V_418 ) {
V_19 -> V_69 |= V_367 ;
F_175 ( V_10 ) ;
}
if ( V_411 & V_420 ) {
F_170 ( V_29 , V_421 , V_19 ) ;
}
if ( V_389 ) {
F_53 ( V_10 , V_411 & V_418 ) ;
V_19 -> V_69 |= V_373 ;
V_77 = F_199 ( V_29 , V_184 ) ;
if ( V_77 )
goto V_422;
F_20 ( & V_10 -> V_24 -> V_25 ) ;
V_77 = F_203 ( V_10 , V_19 ) ;
if ( V_77 ) {
F_21 ( & V_10 -> V_24 -> V_25 ) ;
if ( V_77 == - V_408 ) {
F_132 ( V_10 ) ;
return 0 ;
}
goto V_422;
}
} else {
F_195 ( V_29 , V_184 ) ;
F_20 ( & V_10 -> V_24 -> V_25 ) ;
}
if ( ( V_19 -> V_69 & V_290 ) == 0 )
F_142 ( & V_19 -> V_20 . V_21 , & V_10 -> V_292 ) ;
F_21 ( & V_10 -> V_24 -> V_25 ) ;
if ( V_10 -> V_368 . V_105 == V_423 )
F_213 ( V_10 -> V_81 , ! F_197 ( V_10 , V_19 ) ) ;
if ( V_10 -> V_368 . V_424 < V_425 ) {
F_214 ( V_10 , V_19 -> V_6 . V_52 , V_19 -> V_6 . V_64 ) ;
V_19 -> V_69 &= ~ V_371 ;
F_215 ( V_10 , & V_19 -> V_6 ) ;
V_19 -> V_69 |= V_73 ;
}
V_77 = F_140 ( V_10 , V_19 , V_284 , V_426 ) ;
if ( ! V_77 )
return 0 ;
F_45 ( V_10 , L_42 ) ;
F_20 ( & V_10 -> V_24 -> V_25 ) ;
F_137 ( & V_19 -> V_20 . V_21 ) ;
F_150 ( V_10 , V_19 ) ;
F_21 ( & V_10 -> V_24 -> V_25 ) ;
if ( V_19 -> V_69 & V_73 ) {
V_19 -> V_69 &= ~ V_73 ;
F_56 ( V_10 , & V_19 -> V_6 ) ;
}
V_422:
F_133 ( V_27 , V_19 -> V_253 , V_261 + V_260 ) ;
F_132 ( V_10 ) ;
F_60 ( V_10 , V_19 ) ;
return V_77 ;
}
bool F_216 ( struct V_9 * V_10 , T_3 V_52 ,
bool V_427 )
{
struct V_428 * V_4 ;
bool V_429 = F_217 ( V_10 ) ;
if ( ! V_429 || V_427 )
return V_429 ;
F_20 ( & V_10 -> V_430 ) ;
V_4 = F_218 ( V_10 -> V_431 , F_219 ( V_52 ) ) ;
if ( V_4 ) {
struct V_432 * V_433 = F_220 ( V_4 , struct V_432 , V_434 ) ;
if ( F_69 ( V_435 , & V_433 -> V_69 ) )
V_429 = false ;
}
F_21 ( & V_10 -> V_430 ) ;
return V_429 ;
}
bool F_217 ( struct V_9 * V_10 )
{
struct V_436 * V_437 = V_10 -> V_248 -> V_249 -> V_438 -> V_439 ;
unsigned long V_440 , V_441 , V_442 ;
unsigned int V_443 ;
int V_444 ;
F_24 () ;
V_443 = F_32 ( V_10 -> V_248 -> V_276 ) -> V_443 ;
F_28 () ;
if ( V_443 == 0 )
return false ;
V_444 = ( int ) F_221 ( & V_437 -> V_445 , V_446 [ 0 ] ) +
( int ) F_221 ( & V_437 -> V_445 , V_446 [ 1 ] ) -
F_26 ( & V_10 -> V_349 ) ;
if ( F_26 ( & V_10 -> V_447 )
|| V_444 - V_10 -> V_448 > 64 ) {
unsigned long V_449 ;
int V_6 ;
V_10 -> V_448 = V_444 ;
V_6 = ( V_10 -> V_450 + V_451 - 1 ) % V_451 ;
if ( V_10 -> V_368 . V_105 == V_452 || V_10 -> V_368 . V_105 == V_453 )
V_449 = V_10 -> V_454 ;
else
V_449 = F_222 ( V_10 ) - V_10 -> V_455 ;
V_441 = ( ( long ) V_66 - ( long ) V_10 -> V_456 [ V_6 ] ) / V_44 ;
if ( ! V_441 )
V_441 ++ ;
V_440 = V_10 -> V_457 [ V_6 ] - V_449 ;
V_442 = F_223 ( V_440 / V_441 ) ;
if ( V_442 > V_443 )
return true ;
}
return false ;
}
static int F_224 ( struct V_26 * V_27 , struct V_171 * V_172 )
{
struct V_28 * V_29 ;
struct V_9 * V_10 ;
T_3 V_52 ;
T_3 V_317 ;
struct V_18 * V_19 ;
struct V_458 * V_459 = NULL ;
int V_64 , V_460 ;
unsigned int V_285 ;
struct V_461 * V_315 = V_172 -> V_96 ;
V_29 = F_179 ( V_27 , V_172 -> V_30 ) ;
if ( ! V_29 )
return - V_108 ;
V_10 = V_29 -> V_10 ;
V_317 = F_156 ( V_10 -> V_318 ) ;
V_52 = F_180 ( V_315 -> V_52 ) ;
V_64 = F_125 ( V_315 -> V_462 ) ;
if ( V_64 <= 0 || ! F_158 ( V_64 , 512 ) || V_64 > V_48 ) {
F_45 ( V_10 , L_52 , __FILE__ , __LINE__ ,
( unsigned long long ) V_52 , V_64 ) ;
return - V_234 ;
}
if ( V_52 + ( V_64 >> 9 ) > V_317 ) {
F_45 ( V_10 , L_52 , __FILE__ , __LINE__ ,
( unsigned long long ) V_52 , V_64 ) ;
return - V_234 ;
}
if ( ! F_225 ( V_10 , V_463 ) ) {
V_460 = 1 ;
switch ( V_172 -> V_169 ) {
case V_464 :
F_226 ( V_29 , V_465 , V_315 ) ;
break;
case V_466 :
case V_467 :
case V_468 :
F_226 ( V_29 , V_469 , V_315 ) ;
break;
case V_470 :
V_460 = 0 ;
F_174 ( V_10 ) ;
F_227 ( V_29 , V_471 , V_52 , V_64 , V_472 ) ;
break;
default:
F_228 () ;
}
if ( V_460 && F_184 ( & V_359 ) )
F_45 ( V_10 , L_53
L_54 ) ;
return F_162 ( V_29 , V_172 -> V_64 ) ;
}
V_19 = F_42 ( V_29 , V_315 -> V_68 , V_52 , V_64 ,
true , V_213 ) ;
if ( ! V_19 ) {
F_132 ( V_10 ) ;
return - V_289 ;
}
switch ( V_172 -> V_169 ) {
case V_464 :
V_19 -> V_20 . V_80 = V_473 ;
V_285 = V_474 ;
V_19 -> V_69 |= V_412 ;
goto V_306;
case V_466 :
V_19 -> V_20 . V_80 = V_475 ;
V_285 = V_476 ;
V_10 -> V_477 = F_229 ( V_52 ) ;
break;
case V_470 :
case V_467 :
V_285 = V_476 ;
V_459 = F_153 ( sizeof( * V_459 ) + V_172 -> V_64 , V_213 ) ;
if ( ! V_459 )
goto V_478;
V_459 -> V_319 = V_172 -> V_64 ;
V_459 -> V_71 = ( ( ( char * ) V_459 ) + sizeof( struct V_458 ) ) ;
V_19 -> V_71 = V_459 ;
V_19 -> V_69 |= V_70 ;
if ( F_73 ( V_29 -> V_27 , V_459 -> V_71 , V_172 -> V_64 ) )
goto V_478;
if ( V_172 -> V_169 == V_467 ) {
F_53 ( V_10 , V_29 -> V_27 -> V_186 >= 89 ) ;
V_19 -> V_20 . V_80 = V_479 ;
V_10 -> V_477 = F_229 ( V_52 ) ;
V_10 -> V_480 = true ;
} else if ( V_172 -> V_169 == V_470 ) {
F_38 ( V_64 >> 9 , & V_10 -> V_360 ) ;
V_19 -> V_20 . V_80 = V_481 ;
F_174 ( V_10 ) ;
goto V_482;
}
break;
case V_468 :
if ( V_10 -> V_483 == ~ ( T_3 ) 0 &&
V_29 -> V_27 -> V_186 >= 90 ) {
unsigned long V_484 = V_66 ;
int V_6 ;
V_10 -> V_483 = V_52 ;
V_10 -> V_485 = V_52 ;
V_10 -> V_454 = F_230 ( V_10 ) - F_229 ( V_52 ) ;
V_10 -> V_486 = V_10 -> V_454 ;
for ( V_6 = 0 ; V_6 < V_451 ; V_6 ++ ) {
V_10 -> V_457 [ V_6 ] = V_10 -> V_454 ;
V_10 -> V_456 [ V_6 ] = V_484 ;
}
F_68 ( V_10 , L_55 ,
( unsigned long long ) V_52 ) ;
}
V_19 -> V_20 . V_80 = V_487 ;
V_285 = V_476 ;
break;
default:
F_228 () ;
}
F_20 ( & V_10 -> V_24 -> V_25 ) ;
F_142 ( & V_19 -> V_20 . V_21 , & V_10 -> V_488 ) ;
F_21 ( & V_10 -> V_24 -> V_25 ) ;
F_231 ( V_27 , F_216 ) ;
if ( V_10 -> V_368 . V_489 != V_490
&& F_216 ( V_10 , V_52 , false ) )
F_232 ( V_44 / 10 ) ;
F_231 ( V_27 , V_491 ) ;
if ( V_491 ( V_10 , V_52 ) )
goto V_478;
V_482:
F_38 ( V_64 >> 9 , & V_10 -> V_349 ) ;
V_306:
F_231 ( V_27 , F_140 ) ;
F_175 ( V_10 ) ;
if ( F_140 ( V_10 , V_19 , V_492 , V_285 ) == 0 )
return 0 ;
F_45 ( V_10 , L_42 ) ;
V_478:
F_20 ( & V_10 -> V_24 -> V_25 ) ;
F_137 ( & V_19 -> V_20 . V_21 ) ;
F_21 ( & V_10 -> V_24 -> V_25 ) ;
F_132 ( V_10 ) ;
F_60 ( V_10 , V_19 ) ;
return - V_108 ;
}
static int F_233 ( struct V_28 * V_29 ) __must_hold( T_5 )
{
struct V_9 * V_10 = V_29 -> V_10 ;
int V_493 , V_489 , V_95 = - 100 ;
unsigned long V_494 , V_495 ;
enum V_496 V_497 ;
V_493 = V_10 -> V_248 -> V_498 . V_499 [ V_500 ] & 1 ;
V_489 = V_10 -> V_501 [ V_500 ] & 1 ;
V_495 = V_10 -> V_501 [ V_502 ] ;
V_494 = V_10 -> V_503 ;
F_24 () ;
V_497 = F_32 ( V_29 -> V_27 -> V_35 ) -> V_497 ;
F_28 () ;
switch ( V_497 ) {
case V_504 :
case V_505 :
case V_506 :
case V_507 :
F_45 ( V_10 , L_56 ) ;
break;
case V_508 :
break;
case V_509 :
if ( V_493 == 0 && V_489 == 1 ) {
V_95 = - 1 ;
break;
}
if ( V_493 == 1 && V_489 == 0 ) {
V_95 = 1 ;
break;
}
case V_510 :
if ( V_493 == 0 && V_489 == 1 ) {
V_95 = 1 ;
break;
}
if ( V_493 == 1 && V_489 == 0 ) {
V_95 = - 1 ;
break;
}
F_35 ( V_10 , L_57
L_58 ) ;
case V_511 :
if ( V_495 == 0 && V_494 == 0 ) {
V_95 = F_69 ( V_205 , & V_29 -> V_27 -> V_69 )
? - 1 : 1 ;
break;
} else {
if ( V_495 == 0 ) { V_95 = 1 ; break; }
if ( V_494 == 0 ) { V_95 = - 1 ; break; }
}
if ( V_497 == V_511 )
break;
case V_512 :
if ( V_494 < V_495 )
V_95 = - 1 ;
else if ( V_494 > V_495 )
V_95 = 1 ;
else
V_95 = F_69 ( V_205 , & V_29 -> V_27 -> V_69 )
? - 1 : 1 ;
break;
case V_513 :
V_95 = - 1 ;
break;
case V_514 :
V_95 = 1 ;
}
return V_95 ;
}
static int F_234 ( struct V_28 * V_29 ) __must_hold( T_5 )
{
struct V_9 * V_10 = V_29 -> V_10 ;
int V_515 , V_95 = - 100 ;
enum V_496 V_516 ;
F_24 () ;
V_516 = F_32 ( V_29 -> V_27 -> V_35 ) -> V_516 ;
F_28 () ;
switch ( V_516 ) {
case V_509 :
case V_510 :
case V_512 :
case V_513 :
case V_514 :
case V_511 :
F_45 ( V_10 , L_56 ) ;
break;
case V_508 :
break;
case V_504 :
V_515 = F_233 ( V_29 ) ;
if ( V_515 == - 1 && V_10 -> V_368 . V_517 == V_518 )
V_95 = V_515 ;
if ( V_515 == 1 && V_10 -> V_368 . V_517 == V_490 )
V_95 = V_515 ;
break;
case V_507 :
V_95 = F_233 ( V_29 ) ;
break;
case V_505 :
return V_10 -> V_368 . V_517 == V_490 ? 1 : - 1 ;
case V_506 :
V_515 = F_233 ( V_29 ) ;
if ( V_515 == - 1 && V_10 -> V_368 . V_517 == V_490 ) {
enum V_196 V_519 ;
V_519 = F_235 ( V_10 , V_198 , F_72 ( V_517 , V_518 ) ) ;
if ( V_519 != V_199 ) {
F_236 ( V_10 , L_59 ) ;
} else {
F_35 ( V_10 , L_60 ) ;
V_95 = V_515 ;
}
} else
V_95 = V_515 ;
}
return V_95 ;
}
static int F_237 ( struct V_28 * V_29 ) __must_hold( T_5 )
{
struct V_9 * V_10 = V_29 -> V_10 ;
int V_515 , V_95 = - 100 ;
enum V_496 V_520 ;
F_24 () ;
V_520 = F_32 ( V_29 -> V_27 -> V_35 ) -> V_520 ;
F_28 () ;
switch ( V_520 ) {
case V_509 :
case V_510 :
case V_512 :
case V_513 :
case V_514 :
case V_504 :
case V_505 :
case V_511 :
F_45 ( V_10 , L_56 ) ;
break;
case V_507 :
V_95 = F_233 ( V_29 ) ;
break;
case V_508 :
break;
case V_506 :
V_515 = F_233 ( V_29 ) ;
if ( V_515 == - 1 ) {
enum V_196 V_519 ;
V_519 = F_235 ( V_10 , V_198 , F_72 ( V_517 , V_518 ) ) ;
if ( V_519 != V_199 ) {
F_236 ( V_10 , L_59 ) ;
} else {
F_35 ( V_10 , L_60 ) ;
V_95 = V_515 ;
}
} else
V_95 = V_515 ;
}
return V_95 ;
}
static void F_238 ( struct V_9 * V_10 , char * V_521 , T_2 * V_499 ,
T_2 V_522 , T_2 V_69 )
{
if ( ! V_499 ) {
F_68 ( V_10 , L_61 , V_521 ) ;
return;
}
F_68 ( V_10 , L_62 ,
V_521 ,
( unsigned long long ) V_499 [ V_523 ] ,
( unsigned long long ) V_499 [ V_500 ] ,
( unsigned long long ) V_499 [ V_524 ] ,
( unsigned long long ) V_499 [ V_525 ] ,
( unsigned long long ) V_522 ,
( unsigned long long ) V_69 ) ;
}
static int F_239 ( struct V_9 * const V_10 , int * V_526 ) __must_hold( T_5 )
{
struct V_28 * const V_29 = F_240 ( V_10 ) ;
struct V_26 * const V_27 = V_29 ? V_29 -> V_27 : NULL ;
T_2 V_493 , V_489 ;
int V_6 , V_527 ;
V_493 = V_10 -> V_248 -> V_498 . V_499 [ V_523 ] & ~ ( ( T_2 ) 1 ) ;
V_489 = V_10 -> V_501 [ V_523 ] & ~ ( ( T_2 ) 1 ) ;
* V_526 = 10 ;
if ( V_493 == V_528 && V_489 == V_528 )
return 0 ;
* V_526 = 20 ;
if ( ( V_493 == V_528 || V_493 == ( T_2 ) 0 ) &&
V_489 != V_528 )
return - 2 ;
* V_526 = 30 ;
if ( V_493 != V_528 &&
( V_489 == V_528 || V_489 == ( T_2 ) 0 ) )
return 2 ;
if ( V_493 == V_489 ) {
int V_529 , V_277 ;
if ( V_10 -> V_501 [ V_500 ] == ( T_2 ) 0 && V_10 -> V_248 -> V_498 . V_499 [ V_500 ] != ( T_2 ) 0 ) {
if ( V_27 -> V_186 < 91 )
return - 1091 ;
if ( ( V_10 -> V_248 -> V_498 . V_499 [ V_500 ] & ~ ( ( T_2 ) 1 ) ) == ( V_10 -> V_501 [ V_524 ] & ~ ( ( T_2 ) 1 ) ) &&
( V_10 -> V_248 -> V_498 . V_499 [ V_524 ] & ~ ( ( T_2 ) 1 ) ) == ( V_10 -> V_501 [ V_524 + 1 ] & ~ ( ( T_2 ) 1 ) ) ) {
F_68 ( V_10 , L_63 ) ;
F_241 ( V_10 ) ;
V_10 -> V_248 -> V_498 . V_499 [ V_524 ] = V_10 -> V_248 -> V_498 . V_499 [ V_500 ] ;
V_10 -> V_248 -> V_498 . V_499 [ V_500 ] = 0 ;
F_238 ( V_10 , L_64 , V_10 -> V_248 -> V_498 . V_499 ,
V_10 -> V_368 . V_437 >= V_530 ? F_222 ( V_10 ) : 0 , 0 ) ;
* V_526 = 34 ;
} else {
F_68 ( V_10 , L_65 ) ;
* V_526 = 36 ;
}
return 1 ;
}
if ( V_10 -> V_248 -> V_498 . V_499 [ V_500 ] == ( T_2 ) 0 && V_10 -> V_501 [ V_500 ] != ( T_2 ) 0 ) {
if ( V_27 -> V_186 < 91 )
return - 1091 ;
if ( ( V_10 -> V_248 -> V_498 . V_499 [ V_524 ] & ~ ( ( T_2 ) 1 ) ) == ( V_10 -> V_501 [ V_500 ] & ~ ( ( T_2 ) 1 ) ) &&
( V_10 -> V_248 -> V_498 . V_499 [ V_524 + 1 ] & ~ ( ( T_2 ) 1 ) ) == ( V_10 -> V_501 [ V_524 ] & ~ ( ( T_2 ) 1 ) ) ) {
F_68 ( V_10 , L_66 ) ;
V_10 -> V_501 [ V_524 + 1 ] = V_10 -> V_501 [ V_524 ] ;
V_10 -> V_501 [ V_524 ] = V_10 -> V_501 [ V_500 ] ;
V_10 -> V_501 [ V_500 ] = 0UL ;
F_238 ( V_10 , L_67 , V_10 -> V_501 , V_10 -> V_501 [ V_502 ] , V_10 -> V_501 [ V_531 ] ) ;
* V_526 = 35 ;
} else {
F_68 ( V_10 , L_68 ) ;
* V_526 = 37 ;
}
return - 1 ;
}
V_529 = ( F_69 ( V_532 , & V_10 -> V_69 ) ? 1 : 0 ) +
( V_10 -> V_501 [ V_531 ] & 2 ) ;
* V_526 = 40 ;
switch ( V_529 ) {
case 0 : return 0 ;
case 1 : return 1 ;
case 2 : return - 1 ;
case 3 :
V_277 = F_69 ( V_205 , & V_27 -> V_69 ) ;
return V_277 ? - 1 : 1 ;
}
}
* V_526 = 50 ;
V_489 = V_10 -> V_501 [ V_500 ] & ~ ( ( T_2 ) 1 ) ;
if ( V_493 == V_489 )
return - 1 ;
* V_526 = 51 ;
V_489 = V_10 -> V_501 [ V_524 ] & ~ ( ( T_2 ) 1 ) ;
if ( V_493 == V_489 ) {
if ( V_27 -> V_186 < 96 ?
( V_10 -> V_248 -> V_498 . V_499 [ V_524 ] & ~ ( ( T_2 ) 1 ) ) ==
( V_10 -> V_501 [ V_524 + 1 ] & ~ ( ( T_2 ) 1 ) ) :
V_489 + V_533 == ( V_10 -> V_501 [ V_500 ] & ~ ( ( T_2 ) 1 ) ) ) {
if ( V_27 -> V_186 < 91 )
return - 1091 ;
V_10 -> V_501 [ V_500 ] = V_10 -> V_501 [ V_524 ] ;
V_10 -> V_501 [ V_524 ] = V_10 -> V_501 [ V_524 + 1 ] ;
F_68 ( V_10 , L_69 ) ;
F_238 ( V_10 , L_67 , V_10 -> V_501 , V_10 -> V_501 [ V_502 ] , V_10 -> V_501 [ V_531 ] ) ;
return - 1 ;
}
}
* V_526 = 60 ;
V_493 = V_10 -> V_248 -> V_498 . V_499 [ V_523 ] & ~ ( ( T_2 ) 1 ) ;
for ( V_6 = V_524 ; V_6 <= V_525 ; V_6 ++ ) {
V_489 = V_10 -> V_501 [ V_6 ] & ~ ( ( T_2 ) 1 ) ;
if ( V_493 == V_489 )
return - 2 ;
}
* V_526 = 70 ;
V_493 = V_10 -> V_248 -> V_498 . V_499 [ V_500 ] & ~ ( ( T_2 ) 1 ) ;
V_489 = V_10 -> V_501 [ V_523 ] & ~ ( ( T_2 ) 1 ) ;
if ( V_493 == V_489 )
return 1 ;
* V_526 = 71 ;
V_493 = V_10 -> V_248 -> V_498 . V_499 [ V_524 ] & ~ ( ( T_2 ) 1 ) ;
if ( V_493 == V_489 ) {
if ( V_27 -> V_186 < 96 ?
( V_10 -> V_248 -> V_498 . V_499 [ V_524 + 1 ] & ~ ( ( T_2 ) 1 ) ) ==
( V_10 -> V_501 [ V_524 ] & ~ ( ( T_2 ) 1 ) ) :
V_493 + V_533 == ( V_10 -> V_248 -> V_498 . V_499 [ V_500 ] & ~ ( ( T_2 ) 1 ) ) ) {
if ( V_27 -> V_186 < 91 )
return - 1091 ;
F_242 ( V_10 , V_500 , V_10 -> V_248 -> V_498 . V_499 [ V_524 ] ) ;
F_242 ( V_10 , V_524 , V_10 -> V_248 -> V_498 . V_499 [ V_524 + 1 ] ) ;
F_68 ( V_10 , L_70 ) ;
F_238 ( V_10 , L_64 , V_10 -> V_248 -> V_498 . V_499 ,
V_10 -> V_368 . V_437 >= V_530 ? F_222 ( V_10 ) : 0 , 0 ) ;
return 1 ;
}
}
* V_526 = 80 ;
V_489 = V_10 -> V_501 [ V_523 ] & ~ ( ( T_2 ) 1 ) ;
for ( V_6 = V_524 ; V_6 <= V_525 ; V_6 ++ ) {
V_493 = V_10 -> V_248 -> V_498 . V_499 [ V_6 ] & ~ ( ( T_2 ) 1 ) ;
if ( V_493 == V_489 )
return 2 ;
}
* V_526 = 90 ;
V_493 = V_10 -> V_248 -> V_498 . V_499 [ V_500 ] & ~ ( ( T_2 ) 1 ) ;
V_489 = V_10 -> V_501 [ V_500 ] & ~ ( ( T_2 ) 1 ) ;
if ( V_493 == V_489 && V_493 != ( ( T_2 ) 0 ) )
return 100 ;
* V_526 = 100 ;
for ( V_6 = V_524 ; V_6 <= V_525 ; V_6 ++ ) {
V_493 = V_10 -> V_248 -> V_498 . V_499 [ V_6 ] & ~ ( ( T_2 ) 1 ) ;
for ( V_527 = V_524 ; V_527 <= V_525 ; V_527 ++ ) {
V_489 = V_10 -> V_501 [ V_527 ] & ~ ( ( T_2 ) 1 ) ;
if ( V_493 == V_489 )
return - 100 ;
}
}
return - 1000 ;
}
static enum V_534 F_243 ( struct V_28 * V_29 ,
enum V_535 V_536 ,
enum V_537 V_538 ) __must_hold( T_5 )
{
struct V_9 * V_10 = V_29 -> V_10 ;
enum V_534 V_95 = V_539 ;
enum V_537 V_540 ;
struct V_35 * V_36 ;
int V_515 , V_526 , V_541 , V_542 ;
V_540 = V_10 -> V_368 . V_437 ;
if ( V_540 == V_530 )
V_540 = V_10 -> V_543 . V_437 ;
F_68 ( V_10 , L_71 ) ;
F_20 ( & V_10 -> V_248 -> V_498 . V_544 ) ;
F_238 ( V_10 , L_64 , V_10 -> V_248 -> V_498 . V_499 , V_10 -> V_503 , 0 ) ;
F_238 ( V_10 , L_67 , V_10 -> V_501 ,
V_10 -> V_501 [ V_502 ] , V_10 -> V_501 [ V_531 ] ) ;
V_515 = F_239 ( V_10 , & V_526 ) ;
F_21 ( & V_10 -> V_248 -> V_498 . V_544 ) ;
F_68 ( V_10 , L_72 , V_515 , V_526 ) ;
if ( V_515 == - 1000 ) {
F_206 ( V_10 , L_73 ) ;
return V_539 ;
}
if ( V_515 < - 1000 ) {
F_206 ( V_10 , L_74 , - V_515 - 1000 ) ;
return V_539 ;
}
if ( ( V_540 == V_425 && V_538 > V_425 ) ||
( V_538 == V_425 && V_540 > V_425 ) ) {
int V_545 = ( V_515 == - 100 ) || abs ( V_515 ) == 2 ;
V_515 = V_540 > V_425 ? 1 : - 1 ;
if ( V_545 )
V_515 = V_515 * 2 ;
F_68 ( V_10 , L_75 ,
V_515 > 0 ? L_76 : L_77 ) ;
}
if ( abs ( V_515 ) == 100 )
F_236 ( V_10 , L_78 ) ;
F_24 () ;
V_36 = F_32 ( V_29 -> V_27 -> V_35 ) ;
if ( V_515 == 100 || ( V_515 == - 100 && V_36 -> V_546 ) ) {
int V_547 = ( V_10 -> V_368 . V_517 == V_490 )
+ ( V_536 == V_490 ) ;
int V_548 = ( V_515 == - 100 ) ;
switch ( V_547 ) {
case 0 :
V_515 = F_233 ( V_29 ) ;
break;
case 1 :
V_515 = F_234 ( V_29 ) ;
break;
case 2 :
V_515 = F_237 ( V_29 ) ;
break;
}
if ( abs ( V_515 ) < 100 ) {
F_35 ( V_10 , L_79
L_80 ,
V_547 , ( V_515 < 0 ) ? L_67 : L_81 ) ;
if ( V_548 ) {
F_35 ( V_10 , L_82
L_83 ) ;
V_515 = V_515 * 2 ;
}
}
}
if ( V_515 == - 100 ) {
if ( F_69 ( V_223 , & V_10 -> V_69 ) && ! ( V_10 -> V_501 [ V_531 ] & 1 ) )
V_515 = - 1 ;
if ( ! F_69 ( V_223 , & V_10 -> V_69 ) && ( V_10 -> V_501 [ V_531 ] & 1 ) )
V_515 = 1 ;
if ( abs ( V_515 ) < 100 )
F_35 ( V_10 , L_84
L_85 ,
( V_515 < 0 ) ? L_67 : L_81 ) ;
}
V_541 = V_36 -> V_541 ;
V_542 = V_36 -> V_542 ;
F_28 () ;
if ( V_515 == - 100 ) {
F_206 ( V_10 , L_86 ) ;
F_236 ( V_10 , L_87 ) ;
return V_539 ;
}
if ( V_515 > 0 && V_540 <= V_425 ) {
F_45 ( V_10 , L_88 ) ;
return V_539 ;
}
if ( V_515 < 0 &&
V_10 -> V_368 . V_517 == V_490 && V_10 -> V_368 . V_437 >= V_549 ) {
switch ( V_541 ) {
case V_506 :
F_236 ( V_10 , L_89 ) ;
case V_508 :
F_45 ( V_10 , L_90 ) ;
return V_539 ;
case V_507 :
F_35 ( V_10 , L_91
L_92 ) ;
}
}
if ( V_542 || F_69 ( V_550 , & V_29 -> V_27 -> V_69 ) ) {
if ( V_515 == 0 )
F_68 ( V_10 , L_93 ) ;
else
F_68 ( V_10 , L_94 ,
F_244 ( V_515 > 0 ? V_369 : V_423 ) ,
abs ( V_515 ) >= 2 ? L_95 : L_96 ) ;
return V_539 ;
}
if ( abs ( V_515 ) >= 2 ) {
F_68 ( V_10 , L_97 ) ;
if ( F_245 ( V_10 , & V_551 , L_98 ,
V_552 ) )
return V_539 ;
}
if ( V_515 > 0 ) {
V_95 = V_553 ;
} else if ( V_515 < 0 ) {
V_95 = V_554 ;
} else {
V_95 = V_555 ;
if ( F_222 ( V_10 ) ) {
F_68 ( V_10 , L_99 ,
F_222 ( V_10 ) ) ;
}
}
return V_95 ;
}
static enum V_496 F_246 ( enum V_496 V_489 )
{
if ( V_489 == V_514 )
return V_513 ;
if ( V_489 == V_513 )
return V_514 ;
return V_489 ;
}
static int F_247 ( struct V_26 * V_27 , struct V_171 * V_172 )
{
struct V_556 * V_315 = V_172 -> V_96 ;
enum V_496 V_557 , V_558 , V_559 ;
int V_560 , V_561 , V_562 , V_563 ;
struct V_35 * V_36 , * V_564 , * V_565 = NULL ;
char V_566 [ V_567 ] = L_100 ;
struct V_568 * V_328 = NULL ;
void * V_322 = NULL , * V_324 = NULL ;
V_560 = F_125 ( V_315 -> V_569 ) ;
V_557 = F_125 ( V_315 -> V_497 ) ;
V_558 = F_125 ( V_315 -> V_516 ) ;
V_559 = F_125 ( V_315 -> V_520 ) ;
V_562 = F_125 ( V_315 -> V_390 ) ;
V_563 = F_125 ( V_315 -> V_570 ) ;
V_561 = V_563 & V_571 ;
if ( V_27 -> V_186 >= 87 ) {
int V_77 ;
if ( V_172 -> V_64 > sizeof( V_566 ) )
return - V_108 ;
V_77 = F_73 ( V_27 , V_566 , V_172 -> V_64 ) ;
if ( V_77 )
return V_77 ;
V_566 [ V_567 - 1 ] = 0 ;
}
if ( V_172 -> V_169 != V_572 ) {
F_106 ( V_550 , & V_27 -> V_69 ) ;
if ( V_563 & V_573 )
F_111 ( V_550 , & V_27 -> V_69 ) ;
F_24 () ;
V_36 = F_32 ( V_27 -> V_35 ) ;
if ( V_560 != V_36 -> V_416 ) {
F_45 ( V_27 , L_101 , L_102 ) ;
goto V_574;
}
if ( F_246 ( V_557 ) != V_36 -> V_497 ) {
F_45 ( V_27 , L_101 , L_103 ) ;
goto V_574;
}
if ( F_246 ( V_558 ) != V_36 -> V_516 ) {
F_45 ( V_27 , L_101 , L_104 ) ;
goto V_574;
}
if ( F_246 ( V_559 ) != V_36 -> V_520 ) {
F_45 ( V_27 , L_101 , L_105 ) ;
goto V_574;
}
if ( V_561 && V_36 -> V_195 ) {
F_45 ( V_27 , L_101 , L_106 ) ;
goto V_574;
}
if ( V_562 != V_36 -> V_390 ) {
F_45 ( V_27 , L_101 , L_107 ) ;
goto V_574;
}
if ( strcmp ( V_566 , V_36 -> V_566 ) ) {
F_45 ( V_27 , L_101 , L_108 ) ;
goto V_574;
}
F_28 () ;
}
if ( V_566 [ 0 ] ) {
int V_575 ;
V_328 = F_248 ( V_566 , 0 , V_576 ) ;
if ( ! V_328 ) {
F_45 ( V_27 , L_109 ,
V_566 ) ;
goto V_577;
}
V_575 = F_157 ( V_328 ) ;
V_322 = F_153 ( V_575 , V_578 ) ;
V_324 = F_153 ( V_575 , V_578 ) ;
if ( ! ( V_322 && V_324 ) ) {
F_45 ( V_27 , L_110 ) ;
goto V_577;
}
}
V_565 = F_153 ( sizeof( struct V_35 ) , V_578 ) ;
if ( ! V_565 ) {
F_45 ( V_27 , L_111 ) ;
goto V_577;
}
F_119 ( & V_27 -> V_96 . V_200 ) ;
F_119 ( & V_27 -> V_24 -> V_228 ) ;
V_564 = V_27 -> V_35 ;
* V_565 = * V_564 ;
V_565 -> V_416 = V_560 ;
V_565 -> V_497 = F_246 ( V_557 ) ;
V_565 -> V_516 = F_246 ( V_558 ) ;
V_565 -> V_520 = F_246 ( V_559 ) ;
V_565 -> V_390 = V_562 ;
F_249 ( V_27 -> V_35 , V_565 ) ;
F_120 ( & V_27 -> V_24 -> V_228 ) ;
F_120 ( & V_27 -> V_96 . V_200 ) ;
F_250 ( V_27 -> V_328 ) ;
F_52 ( V_27 -> V_322 ) ;
F_52 ( V_27 -> V_324 ) ;
V_27 -> V_328 = V_328 ;
V_27 -> V_322 = V_322 ;
V_27 -> V_324 = V_324 ;
if ( strcmp ( V_564 -> V_566 , V_566 ) )
F_68 ( V_27 , L_112 ,
V_566 [ 0 ] ? V_566 : L_113 ) ;
F_251 () ;
F_52 ( V_564 ) ;
return 0 ;
V_574:
F_28 () ;
V_577:
F_250 ( V_328 ) ;
F_52 ( V_322 ) ;
F_52 ( V_324 ) ;
F_71 ( V_27 , F_72 ( V_105 , V_151 ) , V_107 ) ;
return - V_108 ;
}
static struct V_568 * F_252 ( const struct V_9 * V_10 ,
const char * V_579 , const char * V_227 )
{
struct V_568 * V_580 ;
if ( ! V_579 [ 0 ] )
return NULL ;
V_580 = F_248 ( V_579 , 0 , V_576 ) ;
if ( F_253 ( V_580 ) ) {
F_45 ( V_10 , L_114 ,
V_579 , V_227 , F_254 ( V_580 ) ) ;
return V_580 ;
}
return V_580 ;
}
static int F_255 ( struct V_26 * V_27 , struct V_171 * V_172 )
{
void * V_243 = V_27 -> V_96 . V_173 ;
int V_64 = V_172 -> V_64 ;
while ( V_64 ) {
int V_203 = F_77 ( int , V_64 , V_581 ) ;
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
static int F_256 ( struct V_26 * V_27 , struct V_171 * V_172 )
{
F_35 ( V_27 , L_115 ,
F_257 ( V_172 -> V_169 ) , V_172 -> V_30 ) ;
return F_255 ( V_27 , V_172 ) ;
}
static int F_258 ( struct V_26 * V_27 , struct V_171 * V_172 )
{
struct V_28 * V_29 ;
struct V_9 * V_10 ;
struct V_582 * V_315 ;
unsigned int V_170 , V_53 , V_583 ;
struct V_568 * V_584 = NULL ;
struct V_568 * V_585 = NULL ;
struct V_35 * V_564 , * V_565 = NULL ;
struct V_276 * V_586 = NULL , * V_587 = NULL ;
const int V_588 = V_27 -> V_186 ;
struct V_589 * V_590 = NULL , * V_591 = NULL ;
int V_592 = 0 ;
int V_77 ;
V_29 = F_179 ( V_27 , V_172 -> V_30 ) ;
if ( ! V_29 )
return F_256 ( V_27 , V_172 ) ;
V_10 = V_29 -> V_10 ;
V_583 = V_588 <= 87 ? sizeof( struct V_593 )
: V_588 == 88 ? sizeof( struct V_593 )
+ V_567
: V_588 <= 94 ? sizeof( struct V_594 )
: sizeof( struct V_582 ) ;
if ( V_172 -> V_64 > V_583 ) {
F_45 ( V_10 , L_116 ,
V_172 -> V_64 , V_583 ) ;
return - V_108 ;
}
if ( V_588 <= 88 ) {
V_170 = sizeof( struct V_593 ) ;
V_53 = V_172 -> V_64 - V_170 ;
} else if ( V_588 <= 94 ) {
V_170 = sizeof( struct V_594 ) ;
V_53 = V_172 -> V_64 - V_170 ;
F_53 ( V_10 , V_53 == 0 ) ;
} else {
V_170 = sizeof( struct V_582 ) ;
V_53 = V_172 -> V_64 - V_170 ;
F_53 ( V_10 , V_53 == 0 ) ;
}
V_315 = V_172 -> V_96 ;
memset ( V_315 -> V_595 , 0 , 2 * V_567 ) ;
V_77 = F_73 ( V_29 -> V_27 , V_315 , V_170 ) ;
if ( V_77 )
return V_77 ;
F_119 ( & V_27 -> V_24 -> V_228 ) ;
V_564 = V_29 -> V_27 -> V_35 ;
if ( F_129 ( V_10 ) ) {
V_587 = F_259 ( sizeof( struct V_276 ) , V_578 ) ;
if ( ! V_587 ) {
F_132 ( V_10 ) ;
F_120 ( & V_27 -> V_24 -> V_228 ) ;
F_45 ( V_10 , L_117 ) ;
return - V_289 ;
}
V_586 = V_10 -> V_248 -> V_276 ;
* V_587 = * V_586 ;
V_587 -> V_596 = F_125 ( V_315 -> V_596 ) ;
}
if ( V_588 >= 88 ) {
if ( V_588 == 88 ) {
if ( V_53 > V_567 || V_53 == 0 ) {
F_45 ( V_10 , L_118
L_119 ,
V_53 , V_567 ) ;
V_77 = - V_108 ;
goto V_597;
}
V_77 = F_73 ( V_29 -> V_27 , V_315 -> V_595 , V_53 ) ;
if ( V_77 )
goto V_597;
F_53 ( V_10 , V_315 -> V_595 [ V_53 - 1 ] == 0 ) ;
V_315 -> V_595 [ V_53 - 1 ] = 0 ;
} else {
F_53 ( V_10 , V_315 -> V_595 [ V_567 - 1 ] == 0 ) ;
F_53 ( V_10 , V_315 -> V_598 [ V_567 - 1 ] == 0 ) ;
V_315 -> V_595 [ V_567 - 1 ] = 0 ;
V_315 -> V_598 [ V_567 - 1 ] = 0 ;
}
if ( strcmp ( V_564 -> V_595 , V_315 -> V_595 ) ) {
if ( V_10 -> V_368 . V_105 == V_103 ) {
F_45 ( V_10 , L_120 ,
V_564 -> V_595 , V_315 -> V_595 ) ;
goto V_577;
}
V_584 = F_252 ( V_10 ,
V_315 -> V_595 , L_121 ) ;
if ( F_253 ( V_584 ) ) {
V_584 = NULL ;
goto V_577;
}
}
if ( V_588 >= 89 && strcmp ( V_564 -> V_598 , V_315 -> V_598 ) ) {
if ( V_10 -> V_368 . V_105 == V_103 ) {
F_45 ( V_10 , L_122 ,
V_564 -> V_598 , V_315 -> V_598 ) ;
goto V_577;
}
V_585 = F_252 ( V_10 ,
V_315 -> V_598 , L_123 ) ;
if ( F_253 ( V_585 ) ) {
V_585 = NULL ;
goto V_577;
}
}
if ( V_588 > 94 && V_587 ) {
V_587 -> V_599 = F_125 ( V_315 -> V_599 ) ;
V_587 -> V_600 = F_125 ( V_315 -> V_600 ) ;
V_587 -> V_601 = F_125 ( V_315 -> V_601 ) ;
V_587 -> V_602 = F_125 ( V_315 -> V_602 ) ;
V_592 = ( V_587 -> V_599 * 10 * V_603 ) / V_44 ;
if ( V_592 != V_10 -> V_604 -> V_64 ) {
V_591 = F_260 ( V_592 ) ;
if ( ! V_591 ) {
F_45 ( V_10 , L_124 ) ;
F_132 ( V_10 ) ;
goto V_577;
}
}
}
if ( V_584 || V_585 ) {
V_565 = F_259 ( sizeof( struct V_35 ) , V_578 ) ;
if ( ! V_565 ) {
F_45 ( V_10 , L_111 ) ;
goto V_577;
}
* V_565 = * V_564 ;
if ( V_584 ) {
strcpy ( V_565 -> V_595 , V_315 -> V_595 ) ;
V_565 -> V_605 = strlen ( V_315 -> V_595 ) + 1 ;
F_250 ( V_29 -> V_27 -> V_584 ) ;
V_29 -> V_27 -> V_584 = V_584 ;
F_68 ( V_10 , L_125 , V_315 -> V_595 ) ;
}
if ( V_585 ) {
strcpy ( V_565 -> V_598 , V_315 -> V_598 ) ;
V_565 -> V_606 = strlen ( V_315 -> V_598 ) + 1 ;
F_250 ( V_29 -> V_27 -> V_585 ) ;
V_29 -> V_27 -> V_585 = V_585 ;
F_68 ( V_10 , L_126 , V_315 -> V_598 ) ;
}
F_249 ( V_27 -> V_35 , V_565 ) ;
}
}
if ( V_587 ) {
F_249 ( V_10 -> V_248 -> V_276 , V_587 ) ;
F_132 ( V_10 ) ;
}
if ( V_591 ) {
V_590 = V_10 -> V_604 ;
F_249 ( V_10 -> V_604 , V_591 ) ;
}
F_120 ( & V_27 -> V_24 -> V_228 ) ;
F_251 () ;
if ( V_565 )
F_52 ( V_564 ) ;
F_52 ( V_586 ) ;
F_52 ( V_590 ) ;
return 0 ;
V_597:
if ( V_587 ) {
F_132 ( V_10 ) ;
F_52 ( V_587 ) ;
}
F_120 ( & V_27 -> V_24 -> V_228 ) ;
return - V_108 ;
V_577:
F_52 ( V_591 ) ;
if ( V_587 ) {
F_132 ( V_10 ) ;
F_52 ( V_587 ) ;
}
F_120 ( & V_27 -> V_24 -> V_228 ) ;
F_250 ( V_585 ) ;
F_250 ( V_584 ) ;
F_71 ( V_29 -> V_27 , F_72 ( V_105 , V_151 ) , V_107 ) ;
return - V_108 ;
}
static void F_261 ( struct V_9 * V_10 ,
const char * V_203 , T_3 V_47 , T_3 V_378 )
{
T_3 V_607 ;
if ( V_47 == 0 || V_378 == 0 )
return;
V_607 = ( V_47 > V_378 ) ? ( V_47 - V_378 ) : ( V_378 - V_47 ) ;
if ( V_607 > ( V_47 >> 3 ) || V_607 > ( V_378 >> 3 ) )
F_35 ( V_10 , L_127 , V_203 ,
( unsigned long long ) V_47 , ( unsigned long long ) V_378 ) ;
}
static int F_262 ( struct V_26 * V_27 , struct V_171 * V_172 )
{
struct V_28 * V_29 ;
struct V_9 * V_10 ;
struct V_608 * V_315 = V_172 -> V_96 ;
enum V_609 V_610 = V_611 ;
T_3 V_612 , V_613 , V_614 , V_615 ;
int V_616 = 0 ;
enum V_617 V_618 ;
V_29 = F_179 ( V_27 , V_172 -> V_30 ) ;
if ( ! V_29 )
return F_256 ( V_27 , V_172 ) ;
V_10 = V_29 -> V_10 ;
V_612 = F_180 ( V_315 -> V_619 ) ;
V_613 = F_180 ( V_315 -> V_620 ) ;
V_614 = F_180 ( V_315 -> V_621 ) ;
V_10 -> V_612 = V_612 ;
if ( F_129 ( V_10 ) ) {
F_24 () ;
V_615 = F_32 ( V_10 -> V_248 -> V_276 ) -> V_622 ;
F_28 () ;
F_261 ( V_10 , L_128 ,
V_612 , F_263 ( V_10 -> V_248 ) ) ;
F_261 ( V_10 , L_129 ,
V_613 , V_615 ) ;
if ( V_10 -> V_368 . V_105 == V_103 )
V_613 = F_264 ( V_615 , V_613 ) ;
if ( F_265 ( V_10 , V_10 -> V_248 , V_613 , 0 ) <
F_156 ( V_10 -> V_318 ) &&
V_10 -> V_368 . V_437 >= V_623 &&
V_10 -> V_368 . V_105 < V_555 ) {
F_45 ( V_10 , L_130 ) ;
F_71 ( V_29 -> V_27 , F_72 ( V_105 , V_151 ) , V_107 ) ;
F_132 ( V_10 ) ;
return - V_108 ;
}
if ( V_615 != V_613 ) {
struct V_276 * V_586 , * V_587 = NULL ;
V_587 = F_259 ( sizeof( struct V_276 ) , V_578 ) ;
if ( ! V_587 ) {
F_45 ( V_10 , L_117 ) ;
F_132 ( V_10 ) ;
return - V_289 ;
}
F_119 ( & V_27 -> V_24 -> V_228 ) ;
V_586 = V_10 -> V_248 -> V_276 ;
* V_587 = * V_586 ;
V_587 -> V_622 = V_613 ;
F_249 ( V_10 -> V_248 -> V_276 , V_587 ) ;
F_120 ( & V_27 -> V_24 -> V_228 ) ;
F_251 () ;
F_52 ( V_586 ) ;
F_68 ( V_10 , L_131 ,
( unsigned long ) V_615 ) ;
}
F_132 ( V_10 ) ;
}
V_10 -> V_624 = F_125 ( V_315 -> V_625 ) ;
V_618 = F_124 ( V_315 -> V_617 ) ;
if ( F_129 ( V_10 ) ) {
F_266 ( V_10 , V_10 -> V_248 ) ;
V_610 = F_267 ( V_10 , V_618 , NULL ) ;
F_132 ( V_10 ) ;
if ( V_610 == V_626 )
return - V_108 ;
F_268 ( V_10 ) ;
} else {
F_266 ( V_10 , NULL ) ;
F_269 ( V_10 , V_614 ? : V_613 ? : V_612 ) ;
}
if ( F_129 ( V_10 ) ) {
if ( V_10 -> V_248 -> V_627 != F_156 ( V_10 -> V_248 -> V_249 ) ) {
V_10 -> V_248 -> V_627 = F_156 ( V_10 -> V_248 -> V_249 ) ;
V_616 = 1 ;
}
F_132 ( V_10 ) ;
}
if ( V_10 -> V_368 . V_105 > V_103 ) {
if ( F_180 ( V_315 -> V_621 ) !=
F_156 ( V_10 -> V_318 ) || V_616 ) {
F_103 ( V_29 , 0 , V_618 ) ;
}
if ( F_270 ( V_190 , & V_10 -> V_69 ) ||
( V_610 == V_628 && V_10 -> V_368 . V_105 == V_555 ) ) {
if ( V_10 -> V_368 . V_424 >= V_425 &&
V_10 -> V_368 . V_437 >= V_425 ) {
if ( V_618 & V_629 )
F_68 ( V_10 , L_132 ) ;
else
F_271 ( V_10 ) ;
} else
F_111 ( V_630 , & V_10 -> V_69 ) ;
}
}
return 0 ;
}
static int F_272 ( struct V_26 * V_27 , struct V_171 * V_172 )
{
struct V_28 * V_29 ;
struct V_9 * V_10 ;
struct V_631 * V_315 = V_172 -> V_96 ;
T_2 * V_501 ;
int V_6 , V_632 = 0 ;
V_29 = F_179 ( V_27 , V_172 -> V_30 ) ;
if ( ! V_29 )
return F_256 ( V_27 , V_172 ) ;
V_10 = V_29 -> V_10 ;
V_501 = F_153 ( sizeof( T_2 ) * V_633 , V_213 ) ;
if ( ! V_501 ) {
F_45 ( V_10 , L_133 ) ;
return false ;
}
for ( V_6 = V_523 ; V_6 < V_633 ; V_6 ++ )
V_501 [ V_6 ] = F_180 ( V_315 -> V_499 [ V_6 ] ) ;
F_52 ( V_10 -> V_501 ) ;
V_10 -> V_501 = V_501 ;
if ( V_10 -> V_368 . V_105 < V_555 &&
V_10 -> V_368 . V_437 < V_425 &&
V_10 -> V_368 . V_517 == V_490 &&
( V_10 -> V_634 & ~ ( ( T_2 ) 1 ) ) != ( V_501 [ V_523 ] & ~ ( ( T_2 ) 1 ) ) ) {
F_45 ( V_10 , L_134 ,
( unsigned long long ) V_10 -> V_634 ) ;
F_71 ( V_29 -> V_27 , F_72 ( V_105 , V_151 ) , V_107 ) ;
return - V_108 ;
}
if ( F_129 ( V_10 ) ) {
int V_635 =
V_10 -> V_368 . V_105 == V_555 &&
V_29 -> V_27 -> V_186 >= 90 &&
V_10 -> V_248 -> V_498 . V_499 [ V_523 ] == V_528 &&
( V_501 [ V_531 ] & 8 ) ;
if ( V_635 ) {
F_68 ( V_10 , L_135 ) ;
F_245 ( V_10 , & V_636 ,
L_136 ,
V_637 ) ;
F_273 ( V_10 , V_523 , V_501 [ V_523 ] ) ;
F_273 ( V_10 , V_500 , 0 ) ;
F_274 ( F_275 ( V_10 , V_437 , V_463 , V_424 , V_463 ) ,
V_198 , NULL ) ;
F_268 ( V_10 ) ;
V_632 = 1 ;
}
F_132 ( V_10 ) ;
} else if ( V_10 -> V_368 . V_437 < V_425 &&
V_10 -> V_368 . V_517 == V_490 ) {
V_632 = F_276 ( V_10 , V_501 [ V_523 ] ) ;
}
F_119 ( V_10 -> V_185 ) ;
F_120 ( V_10 -> V_185 ) ;
if ( V_10 -> V_368 . V_105 >= V_555 && V_10 -> V_368 . V_437 < V_425 )
V_632 |= F_276 ( V_10 , V_501 [ V_523 ] ) ;
if ( V_632 )
F_277 ( V_10 , L_137 ) ;
return 0 ;
}
static union V_638 F_278 ( union V_638 V_639 )
{
union V_638 V_640 ;
static enum V_534 V_641 [] = {
[ V_103 ] = V_103 ,
[ V_555 ] = V_555 ,
[ V_642 ] = V_643 ,
[ V_643 ] = V_642 ,
[ V_151 ] = V_644 ,
[ V_452 ] = V_453 ,
[ V_539 ] = V_539 ,
} ;
V_640 . V_6 = V_639 . V_6 ;
V_640 . V_105 = V_641 [ V_639 . V_105 ] ;
V_640 . V_489 = V_639 . V_517 ;
V_640 . V_517 = V_639 . V_489 ;
V_640 . V_424 = V_639 . V_437 ;
V_640 . V_437 = V_639 . V_424 ;
V_640 . V_645 = ( V_639 . V_646 | V_639 . V_647 ) ;
return V_640 ;
}
static int F_279 ( struct V_26 * V_27 , struct V_171 * V_172 )
{
struct V_28 * V_29 ;
struct V_9 * V_10 ;
struct V_648 * V_315 = V_172 -> V_96 ;
union V_638 V_649 , V_650 ;
enum V_196 V_95 ;
V_29 = F_179 ( V_27 , V_172 -> V_30 ) ;
if ( ! V_29 )
return - V_108 ;
V_10 = V_29 -> V_10 ;
V_649 . V_6 = F_125 ( V_315 -> V_649 ) ;
V_650 . V_6 = F_125 ( V_315 -> V_650 ) ;
if ( F_69 ( V_205 , & V_29 -> V_27 -> V_69 ) &&
F_280 ( V_10 -> V_185 ) ) {
F_281 ( V_29 , V_651 ) ;
return 0 ;
}
V_649 = F_278 ( V_649 ) ;
V_650 = F_278 ( V_650 ) ;
V_95 = F_235 ( V_10 , V_198 , V_649 , V_650 ) ;
F_281 ( V_29 , V_95 ) ;
F_268 ( V_10 ) ;
return 0 ;
}
static int F_282 ( struct V_26 * V_27 , struct V_171 * V_172 )
{
struct V_648 * V_315 = V_172 -> V_96 ;
union V_638 V_649 , V_650 ;
enum V_196 V_95 ;
V_649 . V_6 = F_125 ( V_315 -> V_649 ) ;
V_650 . V_6 = F_125 ( V_315 -> V_650 ) ;
if ( F_69 ( V_205 , & V_27 -> V_69 ) &&
F_280 ( & V_27 -> V_187 ) ) {
F_283 ( V_27 , V_651 ) ;
return 0 ;
}
V_649 = F_278 ( V_649 ) ;
V_650 = F_278 ( V_650 ) ;
V_95 = F_71 ( V_27 , V_649 , V_650 , V_198 | V_652 | V_653 ) ;
F_283 ( V_27 , V_95 ) ;
return 0 ;
}
static int F_284 ( struct V_26 * V_27 , struct V_171 * V_172 )
{
struct V_28 * V_29 ;
struct V_9 * V_10 ;
struct V_654 * V_315 = V_172 -> V_96 ;
union V_638 V_655 , V_656 , V_657 ;
enum V_537 V_658 ;
enum V_659 V_660 ;
int V_95 ;
V_29 = F_179 ( V_27 , V_172 -> V_30 ) ;
if ( ! V_29 )
return F_256 ( V_27 , V_172 ) ;
V_10 = V_29 -> V_10 ;
V_657 . V_6 = F_125 ( V_315 -> V_368 ) ;
V_658 = V_657 . V_437 ;
if ( V_657 . V_437 == V_530 ) {
V_658 = V_10 -> V_501 [ V_531 ] & 4 ? V_425 : V_549 ;
F_68 ( V_10 , L_138 , F_285 ( V_658 ) ) ;
}
F_20 ( & V_10 -> V_24 -> V_25 ) ;
V_34:
V_655 = V_656 = F_286 ( V_10 ) ;
F_21 ( & V_10 -> V_24 -> V_25 ) ;
if ( V_655 . V_105 <= V_644 )
return - V_97 ;
if ( ( V_655 . V_424 == V_425 || V_655 . V_424 == V_549 ) &&
V_658 == V_463 &&
V_655 . V_105 > V_555 && V_655 . V_437 == V_463 ) {
if ( V_657 . V_105 > V_555 &&
V_657 . V_105 < V_369 )
V_658 = V_425 ;
else if ( V_655 . V_105 >= V_369 &&
V_657 . V_105 == V_555 ) {
if ( F_222 ( V_10 ) <= V_10 -> V_455 )
F_287 ( V_10 ) ;
return 0 ;
}
}
if ( V_655 . V_105 == V_453 && V_655 . V_437 == V_463 &&
V_657 . V_105 == V_555 && V_658 == V_463 ) {
F_288 ( V_10 ) ;
F_287 ( V_10 ) ;
return 0 ;
}
if ( V_655 . V_424 == V_463 && V_658 == V_425 &&
V_655 . V_105 == V_555 && V_657 . V_105 > V_369 )
V_658 = V_463 ;
if ( V_656 . V_105 == V_103 )
V_656 . V_105 = V_555 ;
if ( V_657 . V_105 == V_661 )
V_656 . V_105 = V_662 ;
if ( V_10 -> V_501 && V_657 . V_437 >= V_530 &&
F_225 ( V_10 , V_530 ) ) {
int V_663 ;
V_663 = ( V_655 . V_105 < V_555 ) ;
V_663 |= ( V_655 . V_105 == V_555 &&
( V_657 . V_437 == V_530 ||
V_655 . V_437 == V_530 ) ) ;
V_663 |= F_69 ( V_664 , & V_10 -> V_69 ) ;
V_663 |= ( V_655 . V_105 == V_555 &&
( V_657 . V_105 >= V_642 &&
V_657 . V_105 <= V_554 ) ) ;
if ( V_663 )
V_656 . V_105 = F_243 ( V_29 , V_657 . V_517 , V_658 ) ;
F_132 ( V_10 ) ;
if ( V_656 . V_105 == V_539 ) {
V_656 . V_105 = V_555 ;
if ( V_10 -> V_368 . V_437 == V_530 ) {
F_289 ( V_10 , F_72 ( V_437 , V_665 ) ) ;
} else if ( V_657 . V_437 == V_530 ) {
F_45 ( V_10 , L_139 ) ;
V_657 . V_437 = V_666 ;
V_658 = V_666 ;
} else {
if ( F_270 ( V_550 , & V_29 -> V_27 -> V_69 ) )
return - V_108 ;
F_53 ( V_10 , V_655 . V_105 == V_103 ) ;
F_71 ( V_29 -> V_27 , F_72 ( V_105 , V_151 ) , V_107 ) ;
return - V_108 ;
}
}
}
F_20 ( & V_10 -> V_24 -> V_25 ) ;
if ( V_655 . V_6 != F_286 ( V_10 ) . V_6 )
goto V_34;
F_106 ( V_664 , & V_10 -> V_69 ) ;
V_656 . V_489 = V_657 . V_517 ;
V_656 . V_424 = V_658 ;
V_656 . V_645 = ( V_657 . V_646 | V_657 . V_647 ) ;
if ( ( V_656 . V_105 == V_555 || V_656 . V_105 == V_553 ) && V_656 . V_437 == V_530 )
V_656 . V_437 = V_10 -> V_543 . V_437 ;
V_660 = V_198 + ( V_655 . V_105 < V_555 && V_656 . V_105 >= V_555 ? 0 : V_107 ) ;
if ( V_656 . V_424 == V_549 && F_290 ( V_10 ) && V_656 . V_105 == V_555 && V_655 . V_105 < V_555 &&
F_69 ( V_667 , & V_10 -> V_69 ) ) {
F_21 ( & V_10 -> V_24 -> V_25 ) ;
F_45 ( V_10 , L_140 ) ;
F_291 ( V_29 -> V_27 ) ;
F_292 ( V_10 ) ;
F_106 ( V_667 , & V_10 -> V_69 ) ;
F_71 ( V_29 -> V_27 , F_293 ( V_105 , V_668 , V_669 , 0 ) , V_107 ) ;
return - V_108 ;
}
V_95 = F_274 ( V_10 , V_656 , V_660 , NULL ) ;
V_656 = F_286 ( V_10 ) ;
F_21 ( & V_10 -> V_24 -> V_25 ) ;
if ( V_95 < V_199 ) {
F_71 ( V_29 -> V_27 , F_72 ( V_105 , V_151 ) , V_107 ) ;
return - V_108 ;
}
if ( V_655 . V_105 > V_103 ) {
if ( V_656 . V_105 > V_555 && V_657 . V_105 <= V_555 &&
V_657 . V_437 != V_530 ) {
F_104 ( V_29 ) ;
F_105 ( V_29 ) ;
}
}
F_106 ( V_223 , & V_10 -> V_69 ) ;
F_268 ( V_10 ) ;
return 0 ;
}
static int F_294 ( struct V_26 * V_27 , struct V_171 * V_172 )
{
struct V_28 * V_29 ;
struct V_9 * V_10 ;
struct V_670 * V_315 = V_172 -> V_96 ;
V_29 = F_179 ( V_27 , V_172 -> V_30 ) ;
if ( ! V_29 )
return - V_108 ;
V_10 = V_29 -> V_10 ;
F_213 ( V_10 -> V_313 ,
V_10 -> V_368 . V_105 == V_671 ||
V_10 -> V_368 . V_105 == V_662 ||
V_10 -> V_368 . V_105 < V_555 ||
V_10 -> V_368 . V_437 < V_530 ) ;
if ( F_225 ( V_10 , V_530 ) ) {
F_273 ( V_10 , V_523 , F_180 ( V_315 -> V_499 ) ) ;
F_273 ( V_10 , V_500 , 0UL ) ;
F_277 ( V_10 , L_141 ) ;
F_295 ( V_10 , V_423 ) ;
F_132 ( V_10 ) ;
} else
F_45 ( V_10 , L_142 ) ;
return 0 ;
}
static int
F_296 ( struct V_28 * V_29 , unsigned int V_64 ,
unsigned long * V_315 , struct V_672 * V_673 )
{
unsigned int V_53 = V_581 -
F_95 ( V_29 -> V_27 ) ;
unsigned int V_674 = F_77 ( T_6 , V_53 / sizeof( * V_315 ) ,
V_673 -> V_675 - V_673 -> V_676 ) ;
unsigned int V_677 = V_674 * sizeof( * V_315 ) ;
int V_77 ;
if ( V_677 != V_64 ) {
F_45 ( V_29 , L_143 , V_62 , V_677 , V_64 ) ;
return - V_108 ;
}
if ( V_677 == 0 )
return 0 ;
V_77 = F_73 ( V_29 -> V_27 , V_315 , V_677 ) ;
if ( V_77 )
return V_77 ;
F_297 ( V_29 -> V_10 , V_673 -> V_676 , V_674 , V_315 ) ;
V_673 -> V_676 += V_674 ;
V_673 -> V_678 = V_673 -> V_676 * V_679 ;
if ( V_673 -> V_678 > V_673 -> V_680 )
V_673 -> V_678 = V_673 -> V_680 ;
return 1 ;
}
static enum V_681 F_298 ( struct V_682 * V_315 )
{
return (enum V_681 ) ( V_315 -> V_683 & 0x0f ) ;
}
static int F_299 ( struct V_682 * V_315 )
{
return ( V_315 -> V_683 & 0x80 ) != 0 ;
}
static int F_300 ( struct V_682 * V_315 )
{
return ( V_315 -> V_683 >> 4 ) & 0x7 ;
}
static int
F_301 ( struct V_28 * V_29 ,
struct V_682 * V_315 ,
struct V_672 * V_673 ,
unsigned int V_5 )
{
struct V_684 V_685 ;
T_2 V_686 ;
T_2 V_687 ;
T_2 V_4 ;
unsigned long V_203 = V_673 -> V_678 ;
unsigned long V_688 ;
int V_689 = F_299 ( V_315 ) ;
int V_690 ;
int V_522 ;
F_302 ( & V_685 , V_315 -> V_691 , V_5 , F_300 ( V_315 ) ) ;
V_522 = F_303 ( & V_685 , & V_686 , 64 ) ;
if ( V_522 < 0 )
return - V_108 ;
for ( V_690 = V_522 ; V_690 > 0 ; V_203 += V_687 , V_689 = ! V_689 ) {
V_522 = F_304 ( & V_687 , V_686 ) ;
if ( V_522 <= 0 )
return - V_108 ;
if ( V_689 ) {
V_688 = V_203 + V_687 - 1 ;
if ( V_688 >= V_673 -> V_680 ) {
F_45 ( V_29 , L_144 , V_688 ) ;
return - V_108 ;
}
F_305 ( V_29 -> V_10 , V_203 , V_688 ) ;
}
if ( V_690 < V_522 ) {
F_45 ( V_29 , L_145 ,
V_690 , V_522 , V_686 ,
( unsigned int ) ( V_685 . V_692 . V_378 - V_315 -> V_691 ) ,
( unsigned int ) V_685 . V_693 ) ;
return - V_108 ;
}
if ( F_168 ( V_522 < 64 ) )
V_686 >>= V_522 ;
else
V_686 = 0 ;
V_690 -= V_522 ;
V_522 = F_303 ( & V_685 , & V_4 , 64 - V_690 ) ;
if ( V_522 < 0 )
return - V_108 ;
V_686 |= V_4 << V_690 ;
V_690 += V_522 ;
}
V_673 -> V_678 = V_203 ;
F_306 ( V_673 ) ;
return ( V_203 != V_673 -> V_680 ) ;
}
static int
F_307 ( struct V_28 * V_29 ,
struct V_682 * V_315 ,
struct V_672 * V_673 ,
unsigned int V_5 )
{
if ( F_298 ( V_315 ) == V_694 )
return F_301 ( V_29 , V_315 , V_673 , V_5 - sizeof( * V_315 ) ) ;
F_45 ( V_29 , L_146 , V_315 -> V_683 ) ;
F_71 ( V_29 -> V_27 , F_72 ( V_105 , V_668 ) , V_107 ) ;
return - V_108 ;
}
void F_308 ( struct V_9 * V_10 ,
const char * V_695 , struct V_672 * V_673 )
{
unsigned int V_170 = F_95 ( F_240 ( V_10 ) -> V_27 ) ;
unsigned int V_53 = V_581 - V_170 ;
unsigned int V_696 =
V_170 * ( F_309 ( V_673 -> V_675 , V_53 ) + 1 ) +
V_673 -> V_675 * sizeof( unsigned long ) ;
unsigned int V_697 = V_673 -> V_698 [ 0 ] + V_673 -> V_698 [ 1 ] ;
unsigned int V_699 ;
if ( V_697 == 0 )
return;
if ( V_697 >= V_696 )
return;
V_699 = ( V_697 > V_45 / 1000 ) ? ( V_697 / ( V_696 / 1000 ) )
: ( 1000 * V_697 / V_696 ) ;
if ( V_699 > 1000 )
V_699 = 1000 ;
V_699 = 1000 - V_699 ;
F_68 ( V_10 , L_147
L_148 ,
V_695 ,
V_673 -> V_698 [ 1 ] , V_673 -> V_700 [ 1 ] ,
V_673 -> V_698 [ 0 ] , V_673 -> V_700 [ 0 ] ,
V_697 , V_699 / 10 , V_699 % 10 ) ;
}
static int F_310 ( struct V_26 * V_27 , struct V_171 * V_172 )
{
struct V_28 * V_29 ;
struct V_9 * V_10 ;
struct V_672 V_673 ;
int V_77 ;
V_29 = F_179 ( V_27 , V_172 -> V_30 ) ;
if ( ! V_29 )
return - V_108 ;
V_10 = V_29 -> V_10 ;
F_311 ( V_10 , L_149 , V_552 ) ;
V_673 = (struct V_672 ) {
. V_680 = F_230 ( V_10 ) ,
. V_675 = F_312 ( V_10 ) ,
} ;
for(; ; ) {
if ( V_172 -> V_169 == V_701 )
V_77 = F_296 ( V_29 , V_172 -> V_64 , V_172 -> V_96 , & V_673 ) ;
else if ( V_172 -> V_169 == V_702 ) {
struct V_682 * V_315 = V_172 -> V_96 ;
if ( V_172 -> V_64 > V_581 - F_95 ( V_27 ) ) {
F_45 ( V_10 , L_150 ) ;
V_77 = - V_108 ;
goto V_104;
}
if ( V_172 -> V_64 <= sizeof( * V_315 ) ) {
F_45 ( V_10 , L_151 , V_172 -> V_64 ) ;
V_77 = - V_108 ;
goto V_104;
}
V_77 = F_73 ( V_29 -> V_27 , V_315 , V_172 -> V_64 ) ;
if ( V_77 )
goto V_104;
V_77 = F_307 ( V_29 , V_315 , & V_673 , V_172 -> V_64 ) ;
} else {
F_35 ( V_10 , L_152 , V_172 -> V_169 ) ;
V_77 = - V_108 ;
goto V_104;
}
V_673 . V_700 [ V_172 -> V_169 == V_701 ] ++ ;
V_673 . V_698 [ V_172 -> V_169 == V_701 ] += F_95 ( V_27 ) + V_172 -> V_64 ;
if ( V_77 <= 0 ) {
if ( V_77 < 0 )
goto V_104;
break;
}
V_77 = F_127 ( V_29 -> V_27 , V_172 ) ;
if ( V_77 )
goto V_104;
}
F_308 ( V_10 , L_153 , & V_673 ) ;
if ( V_10 -> V_368 . V_105 == V_554 ) {
enum V_196 V_95 ;
V_77 = F_313 ( V_10 ) ;
if ( V_77 )
goto V_104;
V_95 = F_314 ( V_10 , F_72 ( V_105 , V_671 ) , V_198 ) ;
F_53 ( V_10 , V_95 == V_199 ) ;
} else if ( V_10 -> V_368 . V_105 != V_553 ) {
F_68 ( V_10 , L_154 ,
F_244 ( V_10 -> V_368 . V_105 ) ) ;
}
V_77 = 0 ;
V_104:
F_315 ( V_10 ) ;
if ( ! V_77 && V_10 -> V_368 . V_105 == V_553 )
F_295 ( V_10 , V_369 ) ;
return V_77 ;
}
static int F_316 ( struct V_26 * V_27 , struct V_171 * V_172 )
{
F_35 ( V_27 , L_155 ,
V_172 -> V_169 , V_172 -> V_64 ) ;
return F_255 ( V_27 , V_172 ) ;
}
static int F_317 ( struct V_26 * V_27 , struct V_171 * V_172 )
{
F_318 ( V_27 -> V_96 . V_83 ) ;
return 0 ;
}
static int F_319 ( struct V_26 * V_27 , struct V_171 * V_172 )
{
struct V_28 * V_29 ;
struct V_9 * V_10 ;
struct V_703 * V_315 = V_172 -> V_96 ;
V_29 = F_179 ( V_27 , V_172 -> V_30 ) ;
if ( ! V_29 )
return - V_108 ;
V_10 = V_29 -> V_10 ;
switch ( V_10 -> V_368 . V_105 ) {
case V_671 :
case V_554 :
case V_662 :
break;
default:
F_45 ( V_10 , L_156 ,
F_244 ( V_10 -> V_368 . V_105 ) ) ;
}
F_214 ( V_10 , F_180 ( V_315 -> V_52 ) , F_125 ( V_315 -> V_462 ) ) ;
return 0 ;
}
static void F_320 ( struct V_26 * V_27 )
{
struct V_171 V_172 ;
T_6 V_704 ;
int V_77 ;
while ( F_114 ( & V_27 -> V_210 ) == V_705 ) {
struct V_706 * V_169 ;
F_321 ( & V_27 -> V_210 ) ;
F_231 ( V_27 , F_127 ) ;
if ( F_127 ( V_27 , & V_172 ) )
goto V_707;
V_169 = & V_708 [ V_172 . V_169 ] ;
if ( F_181 ( V_172 . V_169 >= F_322 ( V_708 ) || ! V_169 -> V_709 ) ) {
F_45 ( V_27 , L_157 ,
F_257 ( V_172 . V_169 ) , V_172 . V_169 ) ;
goto V_707;
}
V_704 = V_169 -> V_710 ;
if ( V_172 . V_64 > V_704 && ! V_169 -> V_711 ) {
F_45 ( V_27 , L_158 ,
F_257 ( V_172 . V_169 ) , V_172 . V_64 ) ;
goto V_707;
}
if ( V_704 ) {
F_231 ( V_27 , F_74 ) ;
V_77 = F_74 ( V_27 , V_172 . V_96 , V_704 ) ;
if ( V_77 )
goto V_707;
V_172 . V_64 -= V_704 ;
}
F_231 ( V_27 , V_169 -> V_709 ) ;
V_77 = V_169 -> V_709 ( V_27 , & V_172 ) ;
if ( V_77 ) {
F_45 ( V_27 , L_159 ,
F_257 ( V_172 . V_169 ) , V_77 , V_172 . V_64 ) ;
goto V_707;
}
}
return;
V_707:
F_71 ( V_27 , F_72 ( V_105 , V_668 ) , V_107 ) ;
}
static void F_323 ( struct V_26 * V_27 )
{
struct V_28 * V_29 ;
enum V_534 V_712 ;
int V_30 ;
if ( V_27 -> V_102 == V_713 )
return;
F_71 ( V_27 , F_72 ( V_105 , V_714 ) , V_107 ) ;
F_324 ( & V_27 -> V_224 ) ;
if ( V_27 -> V_225 ) {
F_325 ( V_27 -> V_225 ) ;
V_27 -> V_225 = NULL ;
}
F_326 ( V_27 ) ;
F_24 () ;
F_25 (&connection->peer_devices, peer_device, vnr) {
struct V_9 * V_10 = V_29 -> V_10 ;
F_27 ( & V_10 -> V_32 ) ;
F_28 () ;
F_327 ( V_29 ) ;
F_29 ( & V_10 -> V_32 , V_33 ) ;
F_24 () ;
}
F_28 () ;
if ( ! F_62 ( & V_27 -> V_267 -> V_21 ) )
F_45 ( V_27 , L_160 ) ;
F_101 ( & V_27 -> V_267 -> V_256 , 0 ) ;
V_27 -> V_715 . V_716 = false ;
F_68 ( V_27 , L_161 ) ;
if ( F_328 ( V_27 ) == V_490 && F_329 ( V_27 ) >= V_717 )
F_330 ( V_27 ) ;
F_20 ( & V_27 -> V_24 -> V_25 ) ;
V_712 = V_27 -> V_102 ;
if ( V_712 >= V_718 )
F_208 ( V_27 , F_72 ( V_105 , V_718 ) , V_198 ) ;
F_21 ( & V_27 -> V_24 -> V_25 ) ;
if ( V_712 == V_151 )
F_71 ( V_27 , F_72 ( V_105 , V_713 ) , V_198 | V_107 ) ;
}
static int F_327 ( struct V_28 * V_29 )
{
struct V_9 * V_10 = V_29 -> V_10 ;
unsigned int V_6 ;
F_20 ( & V_10 -> V_24 -> V_25 ) ;
F_61 ( V_10 , & V_10 -> V_292 ) ;
F_61 ( V_10 , & V_10 -> V_348 ) ;
F_61 ( V_10 , & V_10 -> V_488 ) ;
F_21 ( & V_10 -> V_24 -> V_25 ) ;
F_331 ( V_10 ) ;
V_10 -> V_486 = 0 ;
V_10 -> V_455 = 0 ;
F_101 ( & V_10 -> V_719 , 0 ) ;
F_41 ( & V_10 -> V_313 ) ;
F_332 ( & V_10 -> V_720 ) ;
F_333 ( ( unsigned long ) V_10 ) ;
F_334 ( & V_29 -> V_27 -> V_721 ) ;
F_59 ( V_10 ) ;
F_334 ( & V_29 -> V_27 -> V_721 ) ;
F_331 ( V_10 ) ;
F_52 ( V_10 -> V_501 ) ;
V_10 -> V_501 = NULL ;
if ( ! F_290 ( V_10 ) )
F_291 ( V_29 -> V_27 ) ;
F_268 ( V_10 ) ;
F_213 ( V_10 -> V_313 , ! F_69 ( V_722 , & V_10 -> V_69 ) ) ;
V_6 = F_57 ( V_10 , & V_10 -> V_76 ) ;
if ( V_6 )
F_68 ( V_10 , L_162 , V_6 ) ;
V_6 = F_26 ( & V_10 -> V_31 ) ;
if ( V_6 )
F_68 ( V_10 , L_163 , V_6 ) ;
V_6 = F_26 ( & V_10 -> V_40 ) ;
if ( V_6 )
F_68 ( V_10 , L_164 , V_6 ) ;
F_53 ( V_10 , F_62 ( & V_10 -> V_488 ) ) ;
F_53 ( V_10 , F_62 ( & V_10 -> V_292 ) ) ;
F_53 ( V_10 , F_62 ( & V_10 -> V_348 ) ) ;
F_53 ( V_10 , F_62 ( & V_10 -> V_78 ) ) ;
return 0 ;
}
static int F_335 ( struct V_26 * V_27 )
{
struct V_167 * V_84 ;
struct V_723 * V_315 ;
V_84 = & V_27 -> V_96 ;
V_315 = F_92 ( V_27 , V_84 ) ;
if ( ! V_315 )
return - V_108 ;
memset ( V_315 , 0 , sizeof( * V_315 ) ) ;
V_315 -> V_724 = F_123 ( V_725 ) ;
V_315 -> V_726 = F_123 ( V_727 ) ;
V_315 -> V_728 = F_123 ( V_729 ) ;
return F_93 ( V_27 , V_84 , V_730 , sizeof( * V_315 ) , NULL , 0 ) ;
}
static int F_116 ( struct V_26 * V_27 )
{
struct V_723 * V_315 ;
const int F_55 = sizeof( struct V_723 ) ;
struct V_171 V_172 ;
int V_77 ;
V_77 = F_335 ( V_27 ) ;
if ( V_77 )
return 0 ;
V_77 = F_127 ( V_27 , & V_172 ) ;
if ( V_77 )
return 0 ;
if ( V_172 . V_169 != V_730 ) {
F_45 ( V_27 , L_165 ,
F_257 ( V_172 . V_169 ) , V_172 . V_169 ) ;
return - 1 ;
}
if ( V_172 . V_64 != F_55 ) {
F_45 ( V_27 , L_166 ,
F_55 , V_172 . V_64 ) ;
return - 1 ;
}
V_315 = V_172 . V_96 ;
V_77 = F_74 ( V_27 , V_315 , F_55 ) ;
if ( V_77 )
return 0 ;
V_315 -> V_724 = F_125 ( V_315 -> V_724 ) ;
V_315 -> V_726 = F_125 ( V_315 -> V_726 ) ;
if ( V_315 -> V_726 == 0 )
V_315 -> V_726 = V_315 -> V_724 ;
if ( V_727 < V_315 -> V_724 ||
V_725 > V_315 -> V_726 )
goto V_731;
V_27 -> V_186 = F_77 ( int , V_727 , V_315 -> V_726 ) ;
V_27 -> V_732 = V_729 & F_125 ( V_315 -> V_728 ) ;
F_68 ( V_27 , L_167
L_168 , V_27 -> V_186 ) ;
F_68 ( V_27 , L_169 ,
V_27 -> V_732 & V_733 ? L_170 : L_171 ) ;
return 1 ;
V_731:
F_45 ( V_27 , L_172
L_173 ,
V_725 , V_727 ,
V_315 -> V_724 , V_315 -> V_726 ) ;
return - 1 ;
}
static int F_117 ( struct V_26 * V_27 )
{
F_45 ( V_27 , L_174 ) ;
F_45 ( V_27 , L_175 ) ;
return - 1 ;
}
static int F_117 ( struct V_26 * V_27 )
{
struct V_167 * V_84 ;
char V_734 [ V_735 ] ;
struct V_736 V_737 ;
char * V_738 = NULL ;
char * V_739 = NULL ;
char * V_740 = NULL ;
unsigned int V_741 ;
char V_742 [ V_567 ] ;
unsigned int V_743 ;
struct V_744 V_745 ;
struct V_171 V_172 ;
struct V_35 * V_36 ;
int V_77 , V_95 ;
F_24 () ;
V_36 = F_32 ( V_27 -> V_35 ) ;
V_741 = strlen ( V_36 -> V_746 ) ;
memcpy ( V_742 , V_36 -> V_746 , V_741 ) ;
F_28 () ;
V_745 . V_580 = V_27 -> V_219 ;
V_745 . V_69 = 0 ;
V_95 = F_336 ( V_27 -> V_219 , ( V_747 * ) V_742 , V_741 ) ;
if ( V_95 ) {
F_45 ( V_27 , L_176 , V_95 ) ;
V_95 = - 1 ;
goto V_63;
}
F_337 ( V_734 , V_735 ) ;
V_84 = & V_27 -> V_96 ;
if ( ! F_92 ( V_27 , V_84 ) ) {
V_95 = 0 ;
goto V_63;
}
V_95 = ! F_93 ( V_27 , V_84 , V_748 , 0 ,
V_734 , V_735 ) ;
if ( ! V_95 )
goto V_63;
V_77 = F_127 ( V_27 , & V_172 ) ;
if ( V_77 ) {
V_95 = 0 ;
goto V_63;
}
if ( V_172 . V_169 != V_748 ) {
F_45 ( V_27 , L_177 ,
F_257 ( V_172 . V_169 ) , V_172 . V_169 ) ;
V_95 = 0 ;
goto V_63;
}
if ( V_172 . V_64 > V_735 * 2 ) {
F_45 ( V_27 , L_178 ) ;
V_95 = - 1 ;
goto V_63;
}
if ( V_172 . V_64 < V_735 ) {
F_45 ( V_27 , L_179 ) ;
V_95 = - 1 ;
goto V_63;
}
V_740 = F_153 ( V_172 . V_64 , V_213 ) ;
if ( V_740 == NULL ) {
F_45 ( V_27 , L_180 ) ;
V_95 = - 1 ;
goto V_63;
}
V_77 = F_74 ( V_27 , V_740 , V_172 . V_64 ) ;
if ( V_77 ) {
V_95 = 0 ;
goto V_63;
}
if ( ! memcmp ( V_734 , V_740 , V_735 ) ) {
F_45 ( V_27 , L_181 ) ;
V_95 = - 1 ;
goto V_63;
}
V_743 = F_157 ( V_27 -> V_219 ) ;
V_738 = F_153 ( V_743 , V_213 ) ;
if ( V_738 == NULL ) {
F_45 ( V_27 , L_182 ) ;
V_95 = - 1 ;
goto V_63;
}
F_338 ( & V_737 , 1 ) ;
F_339 ( & V_737 , V_740 , V_172 . V_64 ) ;
V_95 = F_340 ( & V_745 , & V_737 , V_737 . V_237 , V_738 ) ;
if ( V_95 ) {
F_45 ( V_27 , L_183 , V_95 ) ;
V_95 = - 1 ;
goto V_63;
}
if ( ! F_92 ( V_27 , V_84 ) ) {
V_95 = 0 ;
goto V_63;
}
V_95 = ! F_93 ( V_27 , V_84 , V_749 , 0 ,
V_738 , V_743 ) ;
if ( ! V_95 )
goto V_63;
V_77 = F_127 ( V_27 , & V_172 ) ;
if ( V_77 ) {
V_95 = 0 ;
goto V_63;
}
if ( V_172 . V_169 != V_749 ) {
F_45 ( V_27 , L_184 ,
F_257 ( V_172 . V_169 ) , V_172 . V_169 ) ;
V_95 = 0 ;
goto V_63;
}
if ( V_172 . V_64 != V_743 ) {
F_45 ( V_27 , L_185 ) ;
V_95 = 0 ;
goto V_63;
}
V_77 = F_74 ( V_27 , V_738 , V_743 ) ;
if ( V_77 ) {
V_95 = 0 ;
goto V_63;
}
V_739 = F_153 ( V_743 , V_213 ) ;
if ( V_739 == NULL ) {
F_45 ( V_27 , L_186 ) ;
V_95 = - 1 ;
goto V_63;
}
F_339 ( & V_737 , V_734 , V_735 ) ;
V_95 = F_340 ( & V_745 , & V_737 , V_737 . V_237 , V_739 ) ;
if ( V_95 ) {
F_45 ( V_27 , L_183 , V_95 ) ;
V_95 = - 1 ;
goto V_63;
}
V_95 = ! memcmp ( V_738 , V_739 , V_743 ) ;
if ( V_95 )
F_68 ( V_27 , L_187 ,
V_743 ) ;
else
V_95 = - 1 ;
V_63:
F_52 ( V_740 ) ;
F_52 ( V_738 ) ;
F_52 ( V_739 ) ;
return V_95 ;
}
int F_341 ( struct V_750 * V_751 )
{
struct V_26 * V_27 = V_751 -> V_27 ;
int V_194 ;
F_68 ( V_27 , L_188 ) ;
do {
V_194 = F_108 ( V_27 ) ;
if ( V_194 == 0 ) {
F_323 ( V_27 ) ;
F_99 ( V_44 ) ;
}
if ( V_194 == - 1 ) {
F_35 ( V_27 , L_189 ) ;
F_71 ( V_27 , F_72 ( V_105 , V_151 ) , V_107 ) ;
}
} while ( V_194 == 0 );
if ( V_194 > 0 )
F_320 ( V_27 ) ;
F_323 ( V_27 ) ;
F_68 ( V_27 , L_190 ) ;
return 0 ;
}
static int F_342 ( struct V_26 * V_27 , struct V_171 * V_172 )
{
struct V_752 * V_315 = V_172 -> V_96 ;
int V_753 = F_125 ( V_315 -> V_753 ) ;
if ( V_753 >= V_199 ) {
F_111 ( V_754 , & V_27 -> V_69 ) ;
} else {
F_111 ( V_755 , & V_27 -> V_69 ) ;
F_45 ( V_27 , L_191 ,
F_343 ( V_753 ) , V_753 ) ;
}
F_41 ( & V_27 -> V_101 ) ;
return 0 ;
}
static int F_344 ( struct V_26 * V_27 , struct V_171 * V_172 )
{
struct V_28 * V_29 ;
struct V_9 * V_10 ;
struct V_752 * V_315 = V_172 -> V_96 ;
int V_753 = F_125 ( V_315 -> V_753 ) ;
V_29 = F_179 ( V_27 , V_172 -> V_30 ) ;
if ( ! V_29 )
return - V_108 ;
V_10 = V_29 -> V_10 ;
if ( F_69 ( V_756 , & V_27 -> V_69 ) ) {
F_53 ( V_10 , V_27 -> V_186 < 100 ) ;
return F_342 ( V_27 , V_172 ) ;
}
if ( V_753 >= V_199 ) {
F_111 ( V_757 , & V_10 -> V_69 ) ;
} else {
F_111 ( V_758 , & V_10 -> V_69 ) ;
F_45 ( V_10 , L_191 ,
F_343 ( V_753 ) , V_753 ) ;
}
F_41 ( & V_10 -> V_759 ) ;
return 0 ;
}
static int F_345 ( struct V_26 * V_27 , struct V_171 * V_172 )
{
return F_346 ( V_27 ) ;
}
static int F_347 ( struct V_26 * V_27 , struct V_171 * V_172 )
{
V_27 -> V_202 . V_83 -> V_111 -> V_138 = V_27 -> V_35 -> V_217 * V_44 ;
if ( ! F_348 ( V_760 , & V_27 -> V_69 ) )
F_41 ( & V_27 -> V_101 ) ;
return 0 ;
}
static int F_349 ( struct V_26 * V_27 , struct V_171 * V_172 )
{
struct V_28 * V_29 ;
struct V_9 * V_10 ;
struct V_761 * V_315 = V_172 -> V_96 ;
T_3 V_52 = F_180 ( V_315 -> V_52 ) ;
int V_462 = F_125 ( V_315 -> V_462 ) ;
V_29 = F_179 ( V_27 , V_172 -> V_30 ) ;
if ( ! V_29 )
return - V_108 ;
V_10 = V_29 -> V_10 ;
F_53 ( V_10 , V_29 -> V_27 -> V_186 >= 89 ) ;
F_195 ( V_29 , F_125 ( V_315 -> V_410 ) ) ;
if ( F_129 ( V_10 ) ) {
F_350 ( V_10 , V_52 ) ;
F_169 ( V_10 , V_52 , V_462 ) ;
V_10 -> V_762 += ( V_462 >> V_763 ) ;
F_132 ( V_10 ) ;
}
F_174 ( V_10 ) ;
F_38 ( V_462 >> 9 , & V_10 -> V_360 ) ;
return 0 ;
}
static int
F_351 ( struct V_9 * V_10 , T_2 V_51 , T_3 V_52 ,
struct V_352 * V_353 , const char * V_355 ,
enum V_764 V_117 , bool V_354 )
{
struct V_332 * V_333 ;
struct V_400 V_401 ;
F_20 ( & V_10 -> V_24 -> V_25 ) ;
V_333 = F_176 ( V_10 , V_353 , V_51 , V_52 , V_354 , V_355 ) ;
if ( F_181 ( ! V_333 ) ) {
F_21 ( & V_10 -> V_24 -> V_25 ) ;
return - V_108 ;
}
F_188 ( V_333 , V_117 , & V_401 ) ;
F_21 ( & V_10 -> V_24 -> V_25 ) ;
if ( V_401 . V_286 )
F_202 ( V_10 , & V_401 ) ;
return 0 ;
}
static int F_352 ( struct V_26 * V_27 , struct V_171 * V_172 )
{
struct V_28 * V_29 ;
struct V_9 * V_10 ;
struct V_761 * V_315 = V_172 -> V_96 ;
T_3 V_52 = F_180 ( V_315 -> V_52 ) ;
int V_462 = F_125 ( V_315 -> V_462 ) ;
enum V_764 V_117 ;
V_29 = F_179 ( V_27 , V_172 -> V_30 ) ;
if ( ! V_29 )
return - V_108 ;
V_10 = V_29 -> V_10 ;
F_195 ( V_29 , F_125 ( V_315 -> V_410 ) ) ;
if ( V_315 -> V_68 == V_347 ) {
F_169 ( V_10 , V_52 , V_462 ) ;
F_174 ( V_10 ) ;
return 0 ;
}
switch ( V_172 -> V_169 ) {
case V_345 :
V_117 = V_765 ;
break;
case V_372 :
V_117 = V_766 ;
break;
case V_421 :
V_117 = V_767 ;
break;
case V_376 :
V_117 = V_364 ;
break;
case V_377 :
V_117 = V_768 ;
break;
default:
F_228 () ;
}
return F_351 ( V_10 , V_315 -> V_68 , V_52 ,
& V_10 -> V_311 , V_62 ,
V_117 , false ) ;
}
static int F_353 ( struct V_26 * V_27 , struct V_171 * V_172 )
{
struct V_28 * V_29 ;
struct V_9 * V_10 ;
struct V_761 * V_315 = V_172 -> V_96 ;
T_3 V_52 = F_180 ( V_315 -> V_52 ) ;
int V_64 = F_125 ( V_315 -> V_462 ) ;
int V_77 ;
V_29 = F_179 ( V_27 , V_172 -> V_30 ) ;
if ( ! V_29 )
return - V_108 ;
V_10 = V_29 -> V_10 ;
F_195 ( V_29 , F_125 ( V_315 -> V_410 ) ) ;
if ( V_315 -> V_68 == V_347 ) {
F_174 ( V_10 ) ;
F_171 ( V_10 , V_52 , V_64 ) ;
return 0 ;
}
V_77 = F_351 ( V_10 , V_315 -> V_68 , V_52 ,
& V_10 -> V_311 , V_62 ,
V_402 , true ) ;
if ( V_77 ) {
F_214 ( V_10 , V_52 , V_64 ) ;
}
return 0 ;
}
static int F_354 ( struct V_26 * V_27 , struct V_171 * V_172 )
{
struct V_28 * V_29 ;
struct V_9 * V_10 ;
struct V_761 * V_315 = V_172 -> V_96 ;
T_3 V_52 = F_180 ( V_315 -> V_52 ) ;
V_29 = F_179 ( V_27 , V_172 -> V_30 ) ;
if ( ! V_29 )
return - V_108 ;
V_10 = V_29 -> V_10 ;
F_195 ( V_29 , F_125 ( V_315 -> V_410 ) ) ;
F_45 ( V_10 , L_192 ,
( unsigned long long ) V_52 , F_125 ( V_315 -> V_462 ) ) ;
return F_351 ( V_10 , V_315 -> V_68 , V_52 ,
& V_10 -> V_357 , V_62 ,
V_402 , false ) ;
}
static int F_355 ( struct V_26 * V_27 , struct V_171 * V_172 )
{
struct V_28 * V_29 ;
struct V_9 * V_10 ;
T_3 V_52 ;
int V_64 ;
struct V_761 * V_315 = V_172 -> V_96 ;
V_29 = F_179 ( V_27 , V_172 -> V_30 ) ;
if ( ! V_29 )
return - V_108 ;
V_10 = V_29 -> V_10 ;
V_52 = F_180 ( V_315 -> V_52 ) ;
V_64 = F_125 ( V_315 -> V_462 ) ;
F_195 ( V_29 , F_125 ( V_315 -> V_410 ) ) ;
F_174 ( V_10 ) ;
if ( F_225 ( V_10 , V_665 ) ) {
F_350 ( V_10 , V_52 ) ;
switch ( V_172 -> V_169 ) {
case V_469 :
F_171 ( V_10 , V_52 , V_64 ) ;
case V_769 :
break;
default:
F_228 () ;
}
F_132 ( V_10 ) ;
}
return 0 ;
}
static int F_356 ( struct V_26 * V_27 , struct V_171 * V_172 )
{
struct V_770 * V_315 = V_172 -> V_96 ;
struct V_28 * V_29 ;
int V_30 ;
F_357 ( V_27 , V_315 -> V_316 , F_125 ( V_315 -> V_771 ) ) ;
F_24 () ;
F_25 (&connection->peer_devices, peer_device, vnr) {
struct V_9 * V_10 = V_29 -> V_10 ;
if ( V_10 -> V_368 . V_105 == V_661 &&
F_26 ( & V_10 -> V_191 ) == 0 &&
! F_348 ( V_772 , & V_10 -> V_69 ) ) {
V_10 -> V_773 . V_774 = V_66 + V_44 ;
F_358 ( & V_10 -> V_773 ) ;
}
}
F_28 () ;
return 0 ;
}
static int F_359 ( struct V_26 * V_27 , struct V_171 * V_172 )
{
struct V_28 * V_29 ;
struct V_9 * V_10 ;
struct V_761 * V_315 = V_172 -> V_96 ;
struct V_775 * V_776 ;
T_3 V_52 ;
int V_64 ;
V_29 = F_179 ( V_27 , V_172 -> V_30 ) ;
if ( ! V_29 )
return - V_108 ;
V_10 = V_29 -> V_10 ;
V_52 = F_180 ( V_315 -> V_52 ) ;
V_64 = F_125 ( V_315 -> V_462 ) ;
F_195 ( V_29 , F_125 ( V_315 -> V_410 ) ) ;
if ( F_180 ( V_315 -> V_68 ) == V_777 )
F_360 ( V_10 , V_52 , V_64 ) ;
else
F_288 ( V_10 ) ;
if ( ! F_129 ( V_10 ) )
return 0 ;
F_350 ( V_10 , V_52 ) ;
F_174 ( V_10 ) ;
-- V_10 -> V_454 ;
if ( ( V_10 -> V_454 & 0x200 ) == 0x200 )
F_361 ( V_10 , V_10 -> V_454 ) ;
if ( V_10 -> V_454 == 0 ) {
V_776 = F_153 ( sizeof( * V_776 ) , V_213 ) ;
if ( V_776 ) {
V_776 -> V_20 . V_80 = V_778 ;
V_776 -> V_10 = V_10 ;
F_362 ( & V_29 -> V_27 -> V_721 , & V_776 -> V_20 ) ;
} else {
F_45 ( V_10 , L_193 ) ;
F_288 ( V_10 ) ;
F_287 ( V_10 ) ;
}
}
F_132 ( V_10 ) ;
return 0 ;
}
static int F_363 ( struct V_26 * V_27 , struct V_171 * V_172 )
{
return 0 ;
}
static void F_364 ( struct V_26 * V_27 , bool V_779 )
{
long V_23 ;
struct V_35 * V_36 ;
F_24 () ;
V_36 = F_32 ( V_27 -> V_35 ) ;
V_23 = V_779 ? V_36 -> V_100 : V_36 -> V_217 ;
F_28 () ;
V_23 *= V_44 ;
if ( V_779 )
V_23 /= 10 ;
V_27 -> V_202 . V_83 -> V_111 -> V_138 = V_23 ;
}
static void F_365 ( struct V_26 * V_27 )
{
F_364 ( V_27 , 1 ) ;
}
static void F_366 ( struct V_26 * V_27 )
{
F_364 ( V_27 , 0 ) ;
}
int F_367 ( struct V_750 * V_751 )
{
struct V_26 * V_27 = V_751 -> V_27 ;
struct V_780 * V_169 = NULL ;
struct V_171 V_172 ;
unsigned long V_781 ;
int V_95 ;
void * V_85 = V_27 -> V_202 . V_173 ;
int V_782 = 0 ;
unsigned int V_170 = F_95 ( V_27 ) ;
int F_55 = V_170 ;
bool V_783 = false ;
struct V_784 V_785 = { . V_786 = 2 } ;
V_95 = F_368 ( V_43 , V_787 , & V_785 ) ;
if ( V_95 < 0 )
F_45 ( V_27 , L_194 , V_95 ) ;
while ( F_114 ( V_751 ) == V_705 ) {
F_321 ( V_751 ) ;
F_23 ( V_27 ) ;
if ( F_270 ( V_788 , & V_27 -> V_69 ) ) {
if ( F_369 ( V_27 ) ) {
F_45 ( V_27 , L_195 ) ;
goto V_597;
}
F_365 ( V_27 ) ;
V_783 = true ;
}
V_781 = V_66 ;
V_95 = F_65 ( V_27 -> V_202 . V_83 , V_85 , F_55 - V_782 , 0 ) ;
if ( F_168 ( V_95 > 0 ) ) {
V_782 += V_95 ;
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
F_45 ( V_27 , L_196 ) ;
goto V_597;
} else if ( V_95 == - V_144 ) {
if ( F_370 ( V_27 -> V_218 , V_781 ) )
continue;
if ( V_783 ) {
F_45 ( V_27 , L_197 ) ;
goto V_597;
}
F_111 ( V_788 , & V_27 -> V_69 ) ;
continue;
} else if ( V_95 == - V_146 ) {
F_112 ( V_43 ) ;
continue;
} else {
F_45 ( V_27 , L_7 , V_95 ) ;
goto V_597;
}
if ( V_782 == F_55 && V_169 == NULL ) {
if ( F_96 ( V_27 , V_27 -> V_202 . V_173 , & V_172 ) )
goto V_597;
V_169 = & V_789 [ V_172 . V_169 ] ;
if ( V_172 . V_169 >= F_322 ( V_789 ) || ! V_169 -> V_709 ) {
F_45 ( V_27 , L_198 ,
F_257 ( V_172 . V_169 ) , V_172 . V_169 ) ;
goto V_577;
}
F_55 = V_170 + V_169 -> V_710 ;
if ( V_172 . V_64 != F_55 - V_170 ) {
F_45 ( V_27 , L_199 ,
V_172 . V_169 , V_172 . V_64 ) ;
goto V_597;
}
}
if ( V_782 == F_55 ) {
bool V_77 ;
V_77 = V_169 -> V_709 ( V_27 , & V_172 ) ;
if ( V_77 ) {
F_45 ( V_27 , L_200 , V_169 -> V_709 ) ;
goto V_597;
}
V_27 -> V_218 = V_66 ;
if ( V_169 == & V_789 [ V_790 ] ) {
F_366 ( V_27 ) ;
V_783 = false ;
}
V_85 = V_27 -> V_202 . V_173 ;
V_782 = 0 ;
F_55 = V_170 ;
V_169 = NULL ;
}
}
if ( 0 ) {
V_597:
F_71 ( V_27 , F_72 ( V_105 , V_714 ) , V_107 ) ;
F_371 ( V_27 ) ;
}
if ( 0 ) {
V_577:
F_71 ( V_27 , F_72 ( V_105 , V_151 ) , V_107 ) ;
}
F_68 ( V_27 , L_201 ) ;
return 0 ;
}
void F_372 ( struct V_791 * V_792 )
{
struct V_28 * V_29 =
F_167 ( V_792 , struct V_28 , V_407 ) ;
struct V_26 * V_27 = V_29 -> V_27 ;
struct V_9 * V_10 = V_29 -> V_10 ;
struct V_35 * V_36 ;
int V_793 , V_77 ;
F_24 () ;
V_36 = F_32 ( V_27 -> V_35 ) ;
V_793 = V_36 -> V_793 ;
F_28 () ;
if ( V_793 )
F_373 ( V_27 -> V_202 . V_83 ) ;
V_77 = F_59 ( V_10 ) ;
F_29 ( & V_10 -> V_32 , V_33 ) ;
if ( V_77 ) {
F_71 ( V_27 , F_72 ( V_105 , V_714 ) , V_107 ) ;
return;
}
if ( V_793 )
F_374 ( V_27 -> V_202 . V_83 ) ;
return;
}
