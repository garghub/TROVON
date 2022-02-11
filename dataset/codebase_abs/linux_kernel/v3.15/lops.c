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
struct V_1 * V_2 = V_20 -> V_21 ;
struct V_22 * V_23 = V_20 -> V_24 ;
unsigned int V_25 = V_6 -> V_26 -> V_27 - V_20 -> V_16 . V_28 ;
struct V_29 * V_30 = V_23 -> V_31 + V_25 ;
if ( V_30 -> V_32 == 0 )
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
static void F_35 ( struct V_75 * V_75 , int error )
{
struct V_1 * V_2 = V_75 -> V_76 ;
struct V_65 * V_66 ;
struct V_68 * V_68 ;
int V_77 ;
if ( error ) {
V_2 -> V_78 = error ;
F_36 ( V_2 , L_1 , error ) ;
}
F_37 (bvec, bio, i) {
V_68 = V_66 -> V_69 ;
if ( F_38 ( V_68 ) )
F_31 ( V_2 , V_66 , error ) ;
else
F_39 ( V_68 , V_79 ) ;
}
F_40 ( V_75 ) ;
if ( F_41 ( & V_2 -> V_80 ) )
F_42 ( & V_2 -> V_81 ) ;
}
void F_43 ( struct V_1 * V_2 , int V_82 )
{
if ( V_2 -> V_83 ) {
F_12 ( & V_2 -> V_80 ) ;
F_44 ( V_82 , V_2 -> V_83 ) ;
V_2 -> V_83 = NULL ;
}
}
static struct V_75 * F_45 ( struct V_1 * V_2 , T_1 V_84 )
{
struct V_85 * V_86 = V_2 -> V_87 ;
unsigned V_88 = F_46 ( V_86 -> V_89 ) ;
struct V_75 * V_75 ;
F_2 ( V_2 -> V_83 ) ;
while ( 1 ) {
V_75 = F_47 ( V_90 , V_88 ) ;
if ( F_48 ( V_75 ) )
break;
V_88 = F_49 ( V_88 / 2 , 1U ) ;
}
V_75 -> V_91 . V_92 = V_84 * ( V_86 -> V_93 >> 9 ) ;
V_75 -> V_94 = V_86 -> V_89 ;
V_75 -> V_95 = F_35 ;
V_75 -> V_76 = V_2 ;
V_2 -> V_83 = V_75 ;
return V_75 ;
}
static struct V_75 * F_50 ( struct V_1 * V_2 , T_1 V_84 )
{
struct V_75 * V_75 = V_2 -> V_83 ;
T_1 V_96 ;
if ( V_75 ) {
V_96 = F_51 ( V_75 ) ;
V_96 >>= V_2 -> V_97 ;
if ( V_84 == V_96 )
return V_75 ;
F_43 ( V_2 , V_98 ) ;
}
return F_45 ( V_2 , V_84 ) ;
}
static void F_52 ( struct V_1 * V_2 , struct V_68 * V_68 ,
unsigned V_70 , unsigned V_99 )
{
T_1 V_84 = F_29 ( V_2 ) ;
struct V_75 * V_75 ;
int V_100 ;
V_75 = F_50 ( V_2 , V_84 ) ;
V_100 = F_53 ( V_75 , V_68 , V_70 , V_99 ) ;
if ( V_100 == 0 ) {
F_43 ( V_2 , V_98 ) ;
V_75 = F_45 ( V_2 , V_84 ) ;
V_100 = F_53 ( V_75 , V_68 , V_70 , V_99 ) ;
F_54 ( V_100 == 0 ) ;
}
}
static void F_55 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
F_52 ( V_2 , V_4 -> V_101 , V_4 -> V_74 , F_33 ( V_4 ) ) ;
}
void F_56 ( struct V_1 * V_2 , struct V_68 * V_68 )
{
struct V_85 * V_86 = V_2 -> V_87 ;
F_52 ( V_2 , V_68 , V_86 -> V_93 , 0 ) ;
}
static struct V_68 * F_57 ( struct V_1 * V_2 , T_2 V_102 ,
T_2 V_103 , T_2 V_104 )
{
struct V_68 * V_68 = F_58 ( V_79 , V_90 ) ;
struct V_105 * V_106 = F_59 ( V_68 ) ;
F_60 ( V_106 ) ;
V_106 -> V_107 . V_108 = F_61 ( V_109 ) ;
V_106 -> V_107 . V_110 = F_61 ( V_111 ) ;
V_106 -> V_107 . V_112 = F_61 ( V_113 ) ;
V_106 -> V_102 = F_61 ( V_102 ) ;
V_106 -> V_103 = F_61 ( V_103 ) ;
V_106 -> V_104 = F_61 ( V_104 ) ;
V_106 -> V_114 = 0 ;
return V_68 ;
}
static void F_62 ( struct V_3 * V_4 )
{
void * V_115 ;
T_3 * V_116 ;
F_63 ( V_4 ) ;
V_115 = F_64 ( V_4 -> V_101 ) ;
V_116 = V_115 + F_33 ( V_4 ) ;
if ( * V_116 == F_61 ( V_109 ) )
F_65 ( V_4 ) ;
F_66 ( V_115 ) ;
}
static int F_67 ( void * V_117 , struct V_118 * V_119 , struct V_118 * V_120 )
{
struct V_5 * V_121 , * V_122 ;
V_121 = F_68 ( V_119 , struct V_5 , V_123 ) ;
V_122 = F_68 ( V_120 , struct V_5 , V_123 ) ;
if ( V_121 -> V_26 -> V_27 < V_122 -> V_26 -> V_27 )
return - 1 ;
if ( V_121 -> V_26 -> V_27 > V_122 -> V_26 -> V_27 )
return 1 ;
return 0 ;
}
static void F_69 ( struct V_1 * V_2 , unsigned int V_124 ,
unsigned int V_125 , struct V_118 * V_126 ,
bool V_127 )
{
struct V_105 * V_106 ;
struct V_5 * V_128 = NULL , * V_129 ;
struct V_68 * V_68 ;
unsigned int V_130 ;
unsigned V_131 ;
T_4 * V_116 ;
F_70 ( V_2 ) ;
F_71 ( NULL , V_126 , F_67 ) ;
V_128 = V_129 = F_72 ( V_128 , V_126 , V_123 ) ;
while( V_125 ) {
V_130 = V_125 ;
if ( V_125 > V_124 )
V_130 = V_124 ;
F_73 ( V_2 ) ;
V_68 = F_57 ( V_2 ,
V_127 ? V_132 :
V_133 , V_130 + 1 , V_130 ) ;
V_106 = F_59 ( V_68 ) ;
F_70 ( V_2 ) ;
V_116 = ( T_4 * ) ( V_106 + 1 ) ;
V_131 = 0 ;
F_74 (bd1, blist, bd_list) {
* V_116 ++ = F_75 ( V_128 -> V_26 -> V_27 ) ;
if ( V_127 ) {
F_62 ( V_128 -> V_26 ) ;
* V_116 ++ = F_75 ( F_76 ( V_128 -> V_26 ) ? 1 : 0 ) ;
}
if ( ++ V_131 >= V_130 )
break;
}
F_73 ( V_2 ) ;
F_56 ( V_2 , V_68 ) ;
F_70 ( V_2 ) ;
V_131 = 0 ;
F_74 (bd2, blist, bd_list) {
F_11 ( V_129 -> V_26 ) ;
F_73 ( V_2 ) ;
F_20 ( V_129 -> V_26 ) ;
if ( F_76 ( V_129 -> V_26 ) ) {
void * V_115 ;
V_68 = F_58 ( V_79 , V_90 ) ;
V_116 = F_59 ( V_68 ) ;
V_115 = F_64 ( V_129 -> V_26 -> V_101 ) ;
memcpy ( V_116 , V_115 + F_33 ( V_129 -> V_26 ) ,
V_129 -> V_26 -> V_74 ) ;
F_66 ( V_115 ) ;
* ( T_3 * ) V_116 = 0 ;
F_63 ( V_129 -> V_26 ) ;
F_26 ( V_129 -> V_26 ) ;
F_24 ( V_129 -> V_26 ) ;
F_56 ( V_2 , V_68 ) ;
} else {
F_55 ( V_2 , V_129 -> V_26 ) ;
}
F_70 ( V_2 ) ;
if ( ++ V_131 >= V_130 )
break;
}
F_2 ( V_125 < V_130 ) ;
V_125 -= V_130 ;
}
F_73 ( V_2 ) ;
}
static void F_77 ( struct V_1 * V_2 , struct V_44 * V_45 )
{
unsigned int V_124 = F_78 ( V_2 ) ;
unsigned int V_134 ;
if ( V_45 == NULL )
return;
V_134 = V_45 -> V_135 - V_45 -> V_136 ;
F_69 ( V_2 , V_124 , V_134 , & V_45 -> V_137 , 0 ) ;
}
static void F_79 ( struct V_1 * V_2 , struct V_44 * V_45 )
{
struct V_118 * V_138 ;
struct V_5 * V_6 ;
if ( V_45 == NULL )
return;
V_138 = & V_45 -> V_137 ;
while ( ! F_80 ( V_138 ) ) {
V_6 = F_68 ( V_138 -> V_67 , struct V_5 , V_123 ) ;
F_81 ( & V_6 -> V_123 ) ;
F_18 ( V_2 , V_6 -> V_26 , V_45 ) ;
}
}
static void F_82 ( struct V_139 * V_140 ,
struct V_141 * V_138 , int V_142 )
{
if ( V_142 != 0 )
return;
V_140 -> V_143 = 0 ;
V_140 -> V_144 = 0 ;
}
static int F_83 ( struct V_139 * V_140 , unsigned int V_145 ,
struct V_105 * V_106 , T_4 * V_116 ,
int V_142 )
{
struct V_146 * V_147 = F_84 ( V_140 -> V_148 ) ;
struct V_1 * V_2 = F_85 ( V_140 -> V_148 ) ;
struct V_19 * V_20 = V_147 -> V_149 ;
unsigned int V_150 = F_86 ( V_106 -> V_104 ) ;
struct V_3 * V_151 , * V_152 ;
T_1 V_84 ;
int error = 0 ;
if ( V_142 != 1 || F_86 ( V_106 -> V_102 ) != V_133 )
return 0 ;
F_87 ( V_2 , & V_145 ) ;
for (; V_150 ; F_87 ( V_2 , & V_145 ) , V_150 -- ) {
V_84 = F_88 ( * V_116 ++ ) ;
V_140 -> V_143 ++ ;
if ( F_89 ( V_140 , V_84 , V_145 ) )
continue;
error = F_90 ( V_140 , V_145 , & V_151 ) ;
if ( error )
return error ;
V_152 = F_91 ( V_20 , V_84 ) ;
memcpy ( V_152 -> V_37 , V_151 -> V_37 , V_151 -> V_74 ) ;
if ( F_92 ( V_2 , V_152 ) )
error = - V_153 ;
else
F_21 ( V_152 ) ;
F_24 ( V_151 ) ;
F_24 ( V_152 ) ;
if ( error )
break;
V_140 -> V_144 ++ ;
}
return error ;
}
static void F_93 ( struct V_19 * V_20 )
{
struct V_154 * V_155 = F_94 ( V_20 ) ;
struct V_1 * V_2 = V_20 -> V_21 ;
int error ;
if ( V_155 == NULL )
V_155 = & V_2 -> V_156 ;
F_95 ( V_155 ) ;
error = F_96 ( V_155 ) ;
if ( error )
F_97 ( V_20 -> V_21 ) ;
}
static void F_98 ( struct V_139 * V_140 , int error , int V_142 )
{
struct V_146 * V_147 = F_84 ( V_140 -> V_148 ) ;
struct V_1 * V_2 = F_85 ( V_140 -> V_148 ) ;
if ( error ) {
F_93 ( V_147 -> V_149 ) ;
return;
}
if ( V_142 != 1 )
return;
F_93 ( V_147 -> V_149 ) ;
F_99 ( V_2 , L_2 ,
V_140 -> V_157 , V_140 -> V_144 , V_140 -> V_143 ) ;
}
static void F_100 ( struct V_1 * V_2 , struct V_44 * V_45 )
{
struct V_158 * V_159 ;
unsigned int V_99 ;
struct V_118 * V_138 = & V_2 -> V_160 ;
struct V_5 * V_6 ;
struct V_68 * V_68 ;
unsigned int V_161 ;
F_101 ( V_2 ) ;
if ( ! V_2 -> V_162 )
return;
V_161 = F_102 ( V_2 , V_2 -> V_162 , sizeof( T_1 ) ) ;
V_68 = F_57 ( V_2 , V_163 , V_161 , V_2 -> V_162 ) ;
V_99 = sizeof( struct V_105 ) ;
F_30 (bd, head, bd_list) {
V_2 -> V_162 -- ;
if ( V_99 + sizeof( T_1 ) > V_2 -> V_164 . V_165 ) {
F_56 ( V_2 , V_68 ) ;
V_68 = F_58 ( V_79 , V_90 ) ;
V_159 = F_59 ( V_68 ) ;
F_60 ( V_159 ) ;
V_159 -> V_108 = F_61 ( V_109 ) ;
V_159 -> V_110 = F_61 ( V_166 ) ;
V_159 -> V_112 = F_61 ( V_167 ) ;
V_99 = sizeof( struct V_158 ) ;
}
* ( T_4 * ) ( F_59 ( V_68 ) + V_99 ) = F_75 ( V_6 -> V_168 ) ;
V_99 += sizeof( T_1 ) ;
}
F_5 ( V_2 , ! V_2 -> V_162 ) ;
F_56 ( V_2 , V_68 ) ;
}
static void F_103 ( struct V_1 * V_2 , struct V_44 * V_45 )
{
struct V_118 * V_138 = & V_2 -> V_160 ;
struct V_5 * V_6 ;
struct V_19 * V_20 ;
while ( ! F_80 ( V_138 ) ) {
V_6 = F_68 ( V_138 -> V_67 , struct V_5 , V_123 ) ;
F_81 ( & V_6 -> V_123 ) ;
V_20 = V_6 -> V_15 ;
F_27 ( & V_20 -> V_169 ) ;
F_17 ( V_50 , & V_20 -> V_51 ) ;
F_104 ( V_170 , V_6 ) ;
}
}
static void F_105 ( struct V_139 * V_140 ,
struct V_141 * V_138 , int V_142 )
{
if ( V_142 != 0 )
return;
V_140 -> V_171 = 0 ;
V_140 -> V_172 = V_138 -> V_173 ;
}
static int F_106 ( struct V_139 * V_140 , unsigned int V_145 ,
struct V_105 * V_106 , T_4 * V_116 ,
int V_142 )
{
struct V_1 * V_2 = F_85 ( V_140 -> V_148 ) ;
unsigned int V_150 = F_86 ( V_106 -> V_103 ) ;
unsigned int V_174 = F_86 ( V_106 -> V_104 ) ;
struct V_3 * V_4 ;
unsigned int V_99 ;
T_1 V_84 ;
int V_175 = 1 ;
int error ;
if ( V_142 != 0 || F_86 ( V_106 -> V_102 ) != V_163 )
return 0 ;
V_99 = sizeof( struct V_105 ) ;
for (; V_150 ; F_87 ( V_2 , & V_145 ) , V_150 -- ) {
error = F_90 ( V_140 , V_145 , & V_4 ) ;
if ( error )
return error ;
if ( ! V_175 )
F_107 ( V_2 , V_4 , V_166 ) ;
while ( V_99 + sizeof( T_1 ) <= V_2 -> V_164 . V_165 ) {
V_84 = F_88 ( * ( T_4 * ) ( V_4 -> V_37 + V_99 ) ) ;
error = F_108 ( V_140 , V_84 , V_145 ) ;
if ( error < 0 ) {
F_24 ( V_4 ) ;
return error ;
}
else if ( error )
V_140 -> V_171 ++ ;
if ( ! -- V_174 )
break;
V_99 += sizeof( T_1 ) ;
}
F_24 ( V_4 ) ;
V_99 = sizeof( struct V_158 ) ;
V_175 = 0 ;
}
return 0 ;
}
static void F_109 ( struct V_139 * V_140 , int error , int V_142 )
{
struct V_1 * V_2 = F_85 ( V_140 -> V_148 ) ;
if ( error ) {
F_110 ( V_140 ) ;
return;
}
if ( V_142 != 1 )
return;
F_99 ( V_2 , L_3 ,
V_140 -> V_157 , V_140 -> V_171 ) ;
F_110 ( V_140 ) ;
}
static void F_111 ( struct V_1 * V_2 , struct V_44 * V_45 )
{
unsigned int V_124 = F_112 ( V_2 ) ;
unsigned int V_134 ;
if ( V_45 == NULL )
return;
V_134 = V_45 -> V_176 - V_45 -> V_177 ;
F_69 ( V_2 , V_124 , V_134 , & V_45 -> V_178 , 1 ) ;
}
static int F_113 ( struct V_139 * V_140 , unsigned int V_145 ,
struct V_105 * V_106 ,
T_4 * V_116 , int V_142 )
{
struct V_146 * V_147 = F_84 ( V_140 -> V_148 ) ;
struct V_1 * V_2 = F_85 ( V_140 -> V_148 ) ;
struct V_19 * V_20 = V_147 -> V_149 ;
unsigned int V_150 = F_86 ( V_106 -> V_104 ) ;
struct V_3 * V_151 , * V_152 ;
T_1 V_84 ;
T_1 V_179 ;
int error = 0 ;
if ( V_142 != 1 || F_86 ( V_106 -> V_102 ) != V_132 )
return 0 ;
F_87 ( V_2 , & V_145 ) ;
for (; V_150 ; F_87 ( V_2 , & V_145 ) , V_150 -- ) {
V_84 = F_88 ( * V_116 ++ ) ;
V_179 = F_88 ( * V_116 ++ ) ;
V_140 -> V_143 ++ ;
if ( F_89 ( V_140 , V_84 , V_145 ) )
continue;
error = F_90 ( V_140 , V_145 , & V_151 ) ;
if ( error )
return error ;
V_152 = F_91 ( V_20 , V_84 ) ;
memcpy ( V_152 -> V_37 , V_151 -> V_37 , V_151 -> V_74 ) ;
if ( V_179 ) {
T_3 * V_180 = ( T_3 * ) V_152 -> V_37 ;
* V_180 = F_61 ( V_109 ) ;
}
F_21 ( V_152 ) ;
F_24 ( V_151 ) ;
F_24 ( V_152 ) ;
V_140 -> V_144 ++ ;
}
return error ;
}
static void F_114 ( struct V_139 * V_140 , int error , int V_142 )
{
struct V_146 * V_147 = F_84 ( V_140 -> V_148 ) ;
struct V_1 * V_2 = F_85 ( V_140 -> V_148 ) ;
if ( error ) {
F_93 ( V_147 -> V_149 ) ;
return;
}
if ( V_142 != 1 )
return;
F_93 ( V_147 -> V_149 ) ;
F_99 ( V_2 , L_4 ,
V_140 -> V_157 , V_140 -> V_144 , V_140 -> V_143 ) ;
}
static void F_115 ( struct V_1 * V_2 , struct V_44 * V_45 )
{
struct V_118 * V_138 ;
struct V_5 * V_6 ;
if ( V_45 == NULL )
return;
V_138 = & V_45 -> V_178 ;
while ( ! F_80 ( V_138 ) ) {
V_6 = F_68 ( V_138 -> V_67 , struct V_5 , V_123 ) ;
F_81 ( & V_6 -> V_123 ) ;
F_18 ( V_2 , V_6 -> V_26 , V_45 ) ;
}
}
