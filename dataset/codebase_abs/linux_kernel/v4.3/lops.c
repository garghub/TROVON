void F_1 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_5 * V_6 ;
F_2 ( ! V_7 -> V_8 ) ;
F_3 ( V_4 ) ;
if ( F_4 ( V_4 ) )
F_5 ( V_2 , 0 ) ;
if ( ! F_6 ( V_4 ) )
F_7 ( V_2 , V_4 ) ;
V_6 = V_4 -> V_9 ;
F_8 ( & V_2 -> V_10 ) ;
if ( V_6 -> V_11 )
F_9 ( & V_6 -> V_12 , & V_6 -> V_11 -> V_13 ) ;
F_10 ( & V_2 -> V_10 ) ;
F_11 ( V_4 ) ;
F_12 ( & V_2 -> V_14 ) ;
F_13 ( V_6 , 1 ) ;
}
static bool F_14 ( const struct V_5 * V_6 )
{
return V_6 -> V_15 -> V_16 . V_17 == V_18 ;
}
static void F_15 ( struct V_5 * V_6 )
{
struct V_19 * V_20 = V_6 -> V_15 ;
struct V_1 * V_2 = V_20 -> V_16 . V_21 ;
struct V_22 * V_23 = V_20 -> V_24 ;
unsigned int V_25 = V_6 -> V_26 -> V_27 - V_20 -> V_16 . V_28 ;
struct V_29 * V_30 = V_23 -> V_31 + V_25 ;
if ( V_30 -> V_32 == NULL )
return;
if ( V_2 -> V_33 . V_34 )
F_16 ( V_2 , V_23 -> V_35 , V_6 -> V_26 , V_30 , 1 , NULL ) ;
memcpy ( V_30 -> V_32 + V_30 -> V_36 ,
V_6 -> V_26 -> V_37 + V_30 -> V_36 , V_30 -> V_38 ) ;
F_17 ( V_39 , & V_30 -> V_40 ) ;
V_23 -> V_41 = V_23 -> V_42 ;
V_23 -> V_43 = V_23 -> V_42 ;
}
static void F_18 ( struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_44 * V_45 )
{
struct V_5 * V_6 = V_4 -> V_9 ;
F_2 ( ! F_6 ( V_4 ) ) ;
F_2 ( ! F_19 ( V_4 ) ) ;
F_20 ( V_4 ) ;
F_21 ( V_4 ) ;
F_22 ( V_4 ) ;
if ( F_14 ( V_6 ) )
F_15 ( V_6 ) ;
F_8 ( & V_2 -> V_10 ) ;
if ( V_6 -> V_11 ) {
F_23 ( & V_6 -> V_12 ) ;
F_24 ( V_4 ) ;
} else {
struct V_19 * V_20 = V_6 -> V_15 ;
F_25 ( & V_6 -> V_46 , & V_20 -> V_47 ) ;
F_12 ( & V_20 -> V_48 ) ;
}
V_6 -> V_11 = V_45 ;
F_25 ( & V_6 -> V_12 , & V_45 -> V_49 ) ;
F_10 ( & V_2 -> V_10 ) ;
F_17 ( V_50 , & V_6 -> V_15 -> V_51 ) ;
F_13 ( V_6 , 0 ) ;
F_26 ( V_4 ) ;
F_27 ( & V_2 -> V_14 ) ;
}
static void F_28 ( struct V_1 * V_2 )
{
F_2 ( ( V_2 -> V_52 == V_2 -> V_53 ) &&
( V_2 -> V_52 != V_2 -> V_54 ) ) ;
if ( ++ V_2 -> V_52 == V_2 -> V_55 -> V_56 ) {
V_2 -> V_52 = 0 ;
V_2 -> V_57 = 1 ;
}
}
static T_1 F_29 ( struct V_1 * V_2 )
{
unsigned int V_58 = V_2 -> V_52 ;
struct V_59 * V_60 ;
T_1 V_61 ;
F_30 (je, &sdp->sd_jdesc->extent_list, list) {
if ( ( V_58 >= V_60 -> V_62 ) && ( V_58 < ( V_60 -> V_62 + V_60 -> V_63 ) ) ) {
V_61 = V_60 -> V_64 + V_58 - V_60 -> V_62 ;
F_28 ( V_2 ) ;
return V_61 ;
}
}
return - 1 ;
}
static void F_31 ( struct V_1 * V_2 , struct V_65 * V_66 ,
int error )
{
struct V_3 * V_4 , * V_67 ;
struct V_68 * V_68 = V_66 -> V_69 ;
unsigned V_70 ;
V_4 = F_32 ( V_68 ) ;
V_70 = V_66 -> V_71 ;
while ( F_33 ( V_4 ) < V_66 -> V_72 )
V_4 = V_4 -> V_73 ;
do {
if ( error )
F_34 ( V_4 ) ;
F_26 ( V_4 ) ;
V_67 = V_4 -> V_73 ;
V_70 -= V_4 -> V_74 ;
F_24 ( V_4 ) ;
V_4 = V_67 ;
} while( V_4 && V_70 );
}
static void F_35 ( struct V_75 * V_75 )
{
struct V_1 * V_2 = V_75 -> V_76 ;
struct V_65 * V_66 ;
struct V_68 * V_68 ;
int V_77 ;
if ( V_75 -> V_78 ) {
V_2 -> V_79 = V_75 -> V_78 ;
F_36 ( V_2 , L_1 , V_75 -> V_78 ) ;
}
F_37 (bvec, bio, i) {
V_68 = V_66 -> V_69 ;
if ( F_38 ( V_68 ) )
F_31 ( V_2 , V_66 , V_75 -> V_78 ) ;
else
F_39 ( V_68 , V_80 ) ;
}
F_40 ( V_75 ) ;
if ( F_41 ( & V_2 -> V_81 ) )
F_42 ( & V_2 -> V_82 ) ;
}
void F_43 ( struct V_1 * V_2 , int V_83 )
{
if ( V_2 -> V_84 ) {
F_12 ( & V_2 -> V_81 ) ;
F_44 ( V_83 , V_2 -> V_84 ) ;
V_2 -> V_84 = NULL ;
}
}
static struct V_75 * F_45 ( struct V_1 * V_2 , T_1 V_85 )
{
struct V_86 * V_87 = V_2 -> V_88 ;
struct V_75 * V_75 ;
F_2 ( V_2 -> V_84 ) ;
V_75 = F_46 ( V_89 , V_90 ) ;
V_75 -> V_91 . V_92 = V_85 * ( V_87 -> V_93 >> 9 ) ;
V_75 -> V_94 = V_87 -> V_95 ;
V_75 -> V_96 = F_35 ;
V_75 -> V_76 = V_2 ;
V_2 -> V_84 = V_75 ;
return V_75 ;
}
static struct V_75 * F_47 ( struct V_1 * V_2 , T_1 V_85 )
{
struct V_75 * V_75 = V_2 -> V_84 ;
T_1 V_97 ;
if ( V_75 ) {
V_97 = F_48 ( V_75 ) ;
V_97 >>= V_2 -> V_98 ;
if ( V_85 == V_97 )
return V_75 ;
F_43 ( V_2 , V_99 ) ;
}
return F_45 ( V_2 , V_85 ) ;
}
static void F_49 ( struct V_1 * V_2 , struct V_68 * V_68 ,
unsigned V_70 , unsigned V_100 )
{
T_1 V_85 = F_29 ( V_2 ) ;
struct V_75 * V_75 ;
int V_101 ;
V_75 = F_47 ( V_2 , V_85 ) ;
V_101 = F_50 ( V_75 , V_68 , V_70 , V_100 ) ;
if ( V_101 == 0 ) {
F_43 ( V_2 , V_99 ) ;
V_75 = F_45 ( V_2 , V_85 ) ;
V_101 = F_50 ( V_75 , V_68 , V_70 , V_100 ) ;
F_51 ( V_101 == 0 ) ;
}
}
static void F_52 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
F_49 ( V_2 , V_4 -> V_102 , V_4 -> V_74 , F_33 ( V_4 ) ) ;
}
void F_53 ( struct V_1 * V_2 , struct V_68 * V_68 )
{
struct V_86 * V_87 = V_2 -> V_88 ;
F_49 ( V_2 , V_68 , V_87 -> V_93 , 0 ) ;
}
static struct V_68 * F_54 ( struct V_1 * V_2 , T_2 V_103 ,
T_2 V_104 , T_2 V_105 )
{
struct V_68 * V_68 = F_55 ( V_80 , V_89 ) ;
struct V_106 * V_107 = F_56 ( V_68 ) ;
F_57 ( V_107 ) ;
V_107 -> V_108 . V_109 = F_58 ( V_110 ) ;
V_107 -> V_108 . V_111 = F_58 ( V_112 ) ;
V_107 -> V_108 . V_113 = F_58 ( V_114 ) ;
V_107 -> V_103 = F_58 ( V_103 ) ;
V_107 -> V_104 = F_58 ( V_104 ) ;
V_107 -> V_105 = F_58 ( V_105 ) ;
V_107 -> V_115 = 0 ;
return V_68 ;
}
static void F_59 ( struct V_3 * V_4 )
{
void * V_116 ;
T_3 * V_117 ;
F_60 ( V_4 ) ;
V_116 = F_61 ( V_4 -> V_102 ) ;
V_117 = V_116 + F_33 ( V_4 ) ;
if ( * V_117 == F_58 ( V_110 ) )
F_62 ( V_4 ) ;
F_63 ( V_116 ) ;
}
static int F_64 ( void * V_118 , struct V_119 * V_120 , struct V_119 * V_121 )
{
struct V_5 * V_122 , * V_123 ;
V_122 = F_65 ( V_120 , struct V_5 , V_124 ) ;
V_123 = F_65 ( V_121 , struct V_5 , V_124 ) ;
if ( V_122 -> V_26 -> V_27 < V_123 -> V_26 -> V_27 )
return - 1 ;
if ( V_122 -> V_26 -> V_27 > V_123 -> V_26 -> V_27 )
return 1 ;
return 0 ;
}
static void F_66 ( struct V_1 * V_2 , unsigned int V_125 ,
unsigned int V_126 , struct V_119 * V_127 ,
bool V_128 )
{
struct V_106 * V_107 ;
struct V_5 * V_129 = NULL , * V_130 ;
struct V_68 * V_68 ;
unsigned int V_131 ;
unsigned V_132 ;
T_4 * V_117 ;
F_67 ( V_2 ) ;
F_68 ( NULL , V_127 , F_64 ) ;
V_129 = V_130 = F_69 ( V_129 , V_127 , V_124 ) ;
while( V_126 ) {
V_131 = V_126 ;
if ( V_126 > V_125 )
V_131 = V_125 ;
F_70 ( V_2 ) ;
V_68 = F_54 ( V_2 ,
V_128 ? V_133 :
V_134 , V_131 + 1 , V_131 ) ;
V_107 = F_56 ( V_68 ) ;
F_67 ( V_2 ) ;
V_117 = ( T_4 * ) ( V_107 + 1 ) ;
V_132 = 0 ;
F_71 (bd1, blist, bd_list) {
* V_117 ++ = F_72 ( V_129 -> V_26 -> V_27 ) ;
if ( V_128 ) {
F_59 ( V_129 -> V_26 ) ;
* V_117 ++ = F_72 ( F_73 ( V_129 -> V_26 ) ? 1 : 0 ) ;
}
if ( ++ V_132 >= V_131 )
break;
}
F_70 ( V_2 ) ;
F_53 ( V_2 , V_68 ) ;
F_67 ( V_2 ) ;
V_132 = 0 ;
F_71 (bd2, blist, bd_list) {
F_11 ( V_130 -> V_26 ) ;
F_70 ( V_2 ) ;
F_20 ( V_130 -> V_26 ) ;
if ( F_73 ( V_130 -> V_26 ) ) {
void * V_116 ;
V_68 = F_55 ( V_80 , V_89 ) ;
V_117 = F_56 ( V_68 ) ;
V_116 = F_61 ( V_130 -> V_26 -> V_102 ) ;
memcpy ( V_117 , V_116 + F_33 ( V_130 -> V_26 ) ,
V_130 -> V_26 -> V_74 ) ;
F_63 ( V_116 ) ;
* ( T_3 * ) V_117 = 0 ;
F_60 ( V_130 -> V_26 ) ;
F_26 ( V_130 -> V_26 ) ;
F_24 ( V_130 -> V_26 ) ;
F_53 ( V_2 , V_68 ) ;
} else {
F_52 ( V_2 , V_130 -> V_26 ) ;
}
F_67 ( V_2 ) ;
if ( ++ V_132 >= V_131 )
break;
}
F_2 ( V_126 < V_131 ) ;
V_126 -= V_131 ;
}
F_70 ( V_2 ) ;
}
static void F_74 ( struct V_1 * V_2 , struct V_44 * V_45 )
{
unsigned int V_125 = F_75 ( V_2 ) ;
unsigned int V_135 ;
if ( V_45 == NULL )
return;
V_135 = V_45 -> V_136 - V_45 -> V_137 ;
F_66 ( V_2 , V_125 , V_135 , & V_45 -> V_138 , 0 ) ;
}
static void F_76 ( struct V_1 * V_2 , struct V_44 * V_45 )
{
struct V_119 * V_139 ;
struct V_5 * V_6 ;
if ( V_45 == NULL )
return;
V_139 = & V_45 -> V_138 ;
while ( ! F_77 ( V_139 ) ) {
V_6 = F_65 ( V_139 -> V_67 , struct V_5 , V_124 ) ;
F_78 ( & V_6 -> V_124 ) ;
F_18 ( V_2 , V_6 -> V_26 , V_45 ) ;
}
}
static void F_79 ( struct V_140 * V_141 ,
struct V_142 * V_139 , int V_143 )
{
if ( V_143 != 0 )
return;
V_141 -> V_144 = 0 ;
V_141 -> V_145 = 0 ;
}
static int F_80 ( struct V_140 * V_141 , unsigned int V_146 ,
struct V_106 * V_107 , T_4 * V_117 ,
int V_143 )
{
struct V_147 * V_148 = F_81 ( V_141 -> V_149 ) ;
struct V_1 * V_2 = F_82 ( V_141 -> V_149 ) ;
struct V_19 * V_20 = V_148 -> V_150 ;
unsigned int V_151 = F_83 ( V_107 -> V_105 ) ;
struct V_3 * V_152 , * V_153 ;
T_1 V_85 ;
int error = 0 ;
if ( V_143 != 1 || F_83 ( V_107 -> V_103 ) != V_134 )
return 0 ;
F_84 ( V_2 , & V_146 ) ;
for (; V_151 ; F_84 ( V_2 , & V_146 ) , V_151 -- ) {
V_85 = F_85 ( * V_117 ++ ) ;
V_141 -> V_144 ++ ;
if ( F_86 ( V_141 , V_85 , V_146 ) )
continue;
error = F_87 ( V_141 , V_146 , & V_152 ) ;
if ( error )
return error ;
V_153 = F_88 ( V_20 , V_85 ) ;
memcpy ( V_153 -> V_37 , V_152 -> V_37 , V_152 -> V_74 ) ;
if ( F_89 ( V_2 , V_153 ) )
error = - V_154 ;
else
F_21 ( V_153 ) ;
F_24 ( V_152 ) ;
F_24 ( V_153 ) ;
if ( error )
break;
V_141 -> V_145 ++ ;
}
return error ;
}
static void F_90 ( struct V_19 * V_20 )
{
struct V_155 * V_156 = F_91 ( V_20 ) ;
struct V_1 * V_2 = V_20 -> V_16 . V_21 ;
int error ;
if ( V_156 == NULL )
V_156 = & V_2 -> V_157 ;
F_92 ( V_156 ) ;
error = F_93 ( V_156 ) ;
if ( error )
F_94 ( V_20 -> V_16 . V_21 ) ;
}
static void F_95 ( struct V_140 * V_141 , int error , int V_143 )
{
struct V_147 * V_148 = F_81 ( V_141 -> V_149 ) ;
struct V_1 * V_2 = F_82 ( V_141 -> V_149 ) ;
if ( error ) {
F_90 ( V_148 -> V_150 ) ;
return;
}
if ( V_143 != 1 )
return;
F_90 ( V_148 -> V_150 ) ;
F_96 ( V_2 , L_2 ,
V_141 -> V_158 , V_141 -> V_145 , V_141 -> V_144 ) ;
}
static void F_97 ( struct V_1 * V_2 , struct V_44 * V_45 )
{
struct V_159 * V_160 ;
unsigned int V_100 ;
struct V_119 * V_139 = & V_2 -> V_161 ;
struct V_5 * V_6 ;
struct V_68 * V_68 ;
unsigned int V_162 ;
F_98 ( V_2 ) ;
if ( ! V_2 -> V_163 )
return;
V_162 = F_99 ( V_2 , V_2 -> V_163 , sizeof( T_1 ) ) ;
V_68 = F_54 ( V_2 , V_164 , V_162 , V_2 -> V_163 ) ;
V_100 = sizeof( struct V_106 ) ;
F_30 (bd, head, bd_list) {
V_2 -> V_163 -- ;
if ( V_100 + sizeof( T_1 ) > V_2 -> V_165 . V_166 ) {
F_53 ( V_2 , V_68 ) ;
V_68 = F_55 ( V_80 , V_89 ) ;
V_160 = F_56 ( V_68 ) ;
F_57 ( V_160 ) ;
V_160 -> V_109 = F_58 ( V_110 ) ;
V_160 -> V_111 = F_58 ( V_167 ) ;
V_160 -> V_113 = F_58 ( V_168 ) ;
V_100 = sizeof( struct V_159 ) ;
}
* ( T_4 * ) ( F_56 ( V_68 ) + V_100 ) = F_72 ( V_6 -> V_169 ) ;
V_100 += sizeof( T_1 ) ;
}
F_5 ( V_2 , ! V_2 -> V_163 ) ;
F_53 ( V_2 , V_68 ) ;
}
static void F_100 ( struct V_1 * V_2 , struct V_44 * V_45 )
{
struct V_119 * V_139 = & V_2 -> V_161 ;
struct V_5 * V_6 ;
struct V_19 * V_20 ;
while ( ! F_77 ( V_139 ) ) {
V_6 = F_65 ( V_139 -> V_67 , struct V_5 , V_124 ) ;
F_78 ( & V_6 -> V_124 ) ;
V_20 = V_6 -> V_15 ;
F_27 ( & V_20 -> V_170 ) ;
F_17 ( V_50 , & V_20 -> V_51 ) ;
F_101 ( V_171 , V_6 ) ;
}
}
static void F_102 ( struct V_140 * V_141 ,
struct V_142 * V_139 , int V_143 )
{
if ( V_143 != 0 )
return;
V_141 -> V_172 = 0 ;
V_141 -> V_173 = V_139 -> V_174 ;
}
static int F_103 ( struct V_140 * V_141 , unsigned int V_146 ,
struct V_106 * V_107 , T_4 * V_117 ,
int V_143 )
{
struct V_1 * V_2 = F_82 ( V_141 -> V_149 ) ;
unsigned int V_151 = F_83 ( V_107 -> V_104 ) ;
unsigned int V_175 = F_83 ( V_107 -> V_105 ) ;
struct V_3 * V_4 ;
unsigned int V_100 ;
T_1 V_85 ;
int V_176 = 1 ;
int error ;
if ( V_143 != 0 || F_83 ( V_107 -> V_103 ) != V_164 )
return 0 ;
V_100 = sizeof( struct V_106 ) ;
for (; V_151 ; F_84 ( V_2 , & V_146 ) , V_151 -- ) {
error = F_87 ( V_141 , V_146 , & V_4 ) ;
if ( error )
return error ;
if ( ! V_176 )
F_104 ( V_2 , V_4 , V_167 ) ;
while ( V_100 + sizeof( T_1 ) <= V_2 -> V_165 . V_166 ) {
V_85 = F_85 ( * ( T_4 * ) ( V_4 -> V_37 + V_100 ) ) ;
error = F_105 ( V_141 , V_85 , V_146 ) ;
if ( error < 0 ) {
F_24 ( V_4 ) ;
return error ;
}
else if ( error )
V_141 -> V_172 ++ ;
if ( ! -- V_175 )
break;
V_100 += sizeof( T_1 ) ;
}
F_24 ( V_4 ) ;
V_100 = sizeof( struct V_159 ) ;
V_176 = 0 ;
}
return 0 ;
}
static void F_106 ( struct V_140 * V_141 , int error , int V_143 )
{
struct V_1 * V_2 = F_82 ( V_141 -> V_149 ) ;
if ( error ) {
F_107 ( V_141 ) ;
return;
}
if ( V_143 != 1 )
return;
F_96 ( V_2 , L_3 ,
V_141 -> V_158 , V_141 -> V_172 ) ;
F_107 ( V_141 ) ;
}
static void F_108 ( struct V_1 * V_2 , struct V_44 * V_45 )
{
unsigned int V_125 = F_109 ( V_2 ) ;
unsigned int V_135 ;
if ( V_45 == NULL )
return;
V_135 = V_45 -> V_177 - V_45 -> V_178 ;
F_66 ( V_2 , V_125 , V_135 , & V_45 -> V_179 , 1 ) ;
}
static int F_110 ( struct V_140 * V_141 , unsigned int V_146 ,
struct V_106 * V_107 ,
T_4 * V_117 , int V_143 )
{
struct V_147 * V_148 = F_81 ( V_141 -> V_149 ) ;
struct V_1 * V_2 = F_82 ( V_141 -> V_149 ) ;
struct V_19 * V_20 = V_148 -> V_150 ;
unsigned int V_151 = F_83 ( V_107 -> V_105 ) ;
struct V_3 * V_152 , * V_153 ;
T_1 V_85 ;
T_1 V_180 ;
int error = 0 ;
if ( V_143 != 1 || F_83 ( V_107 -> V_103 ) != V_133 )
return 0 ;
F_84 ( V_2 , & V_146 ) ;
for (; V_151 ; F_84 ( V_2 , & V_146 ) , V_151 -- ) {
V_85 = F_85 ( * V_117 ++ ) ;
V_180 = F_85 ( * V_117 ++ ) ;
V_141 -> V_144 ++ ;
if ( F_86 ( V_141 , V_85 , V_146 ) )
continue;
error = F_87 ( V_141 , V_146 , & V_152 ) ;
if ( error )
return error ;
V_153 = F_88 ( V_20 , V_85 ) ;
memcpy ( V_153 -> V_37 , V_152 -> V_37 , V_152 -> V_74 ) ;
if ( V_180 ) {
T_3 * V_181 = ( T_3 * ) V_153 -> V_37 ;
* V_181 = F_58 ( V_110 ) ;
}
F_21 ( V_153 ) ;
F_24 ( V_152 ) ;
F_24 ( V_153 ) ;
V_141 -> V_145 ++ ;
}
return error ;
}
static void F_111 ( struct V_140 * V_141 , int error , int V_143 )
{
struct V_147 * V_148 = F_81 ( V_141 -> V_149 ) ;
struct V_1 * V_2 = F_82 ( V_141 -> V_149 ) ;
if ( error ) {
F_90 ( V_148 -> V_150 ) ;
return;
}
if ( V_143 != 1 )
return;
F_90 ( V_148 -> V_150 ) ;
F_96 ( V_2 , L_4 ,
V_141 -> V_158 , V_141 -> V_145 , V_141 -> V_144 ) ;
}
static void F_112 ( struct V_1 * V_2 , struct V_44 * V_45 )
{
struct V_119 * V_139 ;
struct V_5 * V_6 ;
if ( V_45 == NULL )
return;
V_139 = & V_45 -> V_179 ;
while ( ! F_77 ( V_139 ) ) {
V_6 = F_65 ( V_139 -> V_67 , struct V_5 , V_124 ) ;
F_78 ( & V_6 -> V_124 ) ;
F_18 ( V_2 , V_6 -> V_26 , V_45 ) ;
}
}
