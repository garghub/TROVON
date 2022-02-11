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
void F_43 ( struct V_1 * V_2 , int V_83 , int V_84 )
{
if ( V_2 -> V_85 ) {
F_12 ( & V_2 -> V_81 ) ;
F_44 ( V_2 -> V_85 , V_83 , V_84 ) ;
F_45 ( V_2 -> V_85 ) ;
V_2 -> V_85 = NULL ;
}
}
static struct V_75 * F_46 ( struct V_1 * V_2 , T_1 V_86 )
{
struct V_87 * V_88 = V_2 -> V_89 ;
struct V_75 * V_75 ;
F_2 ( V_2 -> V_85 ) ;
V_75 = F_47 ( V_90 , V_91 ) ;
V_75 -> V_92 . V_93 = V_86 * ( V_88 -> V_94 >> 9 ) ;
V_75 -> V_95 = V_88 -> V_96 ;
V_75 -> V_97 = F_35 ;
V_75 -> V_76 = V_2 ;
V_2 -> V_85 = V_75 ;
return V_75 ;
}
static struct V_75 * F_48 ( struct V_1 * V_2 , T_1 V_86 )
{
struct V_75 * V_75 = V_2 -> V_85 ;
T_1 V_98 ;
if ( V_75 ) {
V_98 = F_49 ( V_75 ) ;
V_98 >>= V_2 -> V_99 ;
if ( V_86 == V_98 )
return V_75 ;
F_43 ( V_2 , V_100 , 0 ) ;
}
return F_46 ( V_2 , V_86 ) ;
}
static void F_50 ( struct V_1 * V_2 , struct V_68 * V_68 ,
unsigned V_70 , unsigned V_101 )
{
T_1 V_86 = F_29 ( V_2 ) ;
struct V_75 * V_75 ;
int V_102 ;
V_75 = F_48 ( V_2 , V_86 ) ;
V_102 = F_51 ( V_75 , V_68 , V_70 , V_101 ) ;
if ( V_102 == 0 ) {
F_43 ( V_2 , V_100 , 0 ) ;
V_75 = F_46 ( V_2 , V_86 ) ;
V_102 = F_51 ( V_75 , V_68 , V_70 , V_101 ) ;
F_52 ( V_102 == 0 ) ;
}
}
static void F_53 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
F_50 ( V_2 , V_4 -> V_103 , V_4 -> V_74 , F_33 ( V_4 ) ) ;
}
void F_54 ( struct V_1 * V_2 , struct V_68 * V_68 )
{
struct V_87 * V_88 = V_2 -> V_89 ;
F_50 ( V_2 , V_68 , V_88 -> V_94 , 0 ) ;
}
static struct V_68 * F_55 ( struct V_1 * V_2 , T_2 V_104 ,
T_2 V_105 , T_2 V_106 )
{
struct V_68 * V_68 = F_56 ( V_80 , V_90 ) ;
struct V_107 * V_108 = F_57 ( V_68 ) ;
F_58 ( V_108 ) ;
V_108 -> V_109 . V_110 = F_59 ( V_111 ) ;
V_108 -> V_109 . V_112 = F_59 ( V_113 ) ;
V_108 -> V_109 . V_114 = F_59 ( V_115 ) ;
V_108 -> V_104 = F_59 ( V_104 ) ;
V_108 -> V_105 = F_59 ( V_105 ) ;
V_108 -> V_106 = F_59 ( V_106 ) ;
V_108 -> V_116 = 0 ;
return V_68 ;
}
static void F_60 ( struct V_3 * V_4 )
{
void * V_117 ;
T_3 * V_118 ;
F_61 ( V_4 ) ;
V_117 = F_62 ( V_4 -> V_103 ) ;
V_118 = V_117 + F_33 ( V_4 ) ;
if ( * V_118 == F_59 ( V_111 ) )
F_63 ( V_4 ) ;
F_64 ( V_117 ) ;
}
static int F_65 ( void * V_119 , struct V_120 * V_121 , struct V_120 * V_122 )
{
struct V_5 * V_123 , * V_124 ;
V_123 = F_66 ( V_121 , struct V_5 , V_125 ) ;
V_124 = F_66 ( V_122 , struct V_5 , V_125 ) ;
if ( V_123 -> V_26 -> V_27 < V_124 -> V_26 -> V_27 )
return - 1 ;
if ( V_123 -> V_26 -> V_27 > V_124 -> V_26 -> V_27 )
return 1 ;
return 0 ;
}
static void F_67 ( struct V_1 * V_2 , unsigned int V_126 ,
unsigned int V_127 , struct V_120 * V_128 ,
bool V_129 )
{
struct V_107 * V_108 ;
struct V_5 * V_130 = NULL , * V_131 ;
struct V_68 * V_68 ;
unsigned int V_132 ;
unsigned V_133 ;
T_4 * V_118 ;
F_68 ( V_2 ) ;
F_69 ( NULL , V_128 , F_65 ) ;
V_130 = V_131 = F_70 ( V_130 , V_128 , V_125 ) ;
while( V_127 ) {
V_132 = V_127 ;
if ( V_127 > V_126 )
V_132 = V_126 ;
F_71 ( V_2 ) ;
V_68 = F_55 ( V_2 ,
V_129 ? V_134 :
V_135 , V_132 + 1 , V_132 ) ;
V_108 = F_57 ( V_68 ) ;
F_68 ( V_2 ) ;
V_118 = ( T_4 * ) ( V_108 + 1 ) ;
V_133 = 0 ;
F_72 (bd1, blist, bd_list) {
* V_118 ++ = F_73 ( V_130 -> V_26 -> V_27 ) ;
if ( V_129 ) {
F_60 ( V_130 -> V_26 ) ;
* V_118 ++ = F_73 ( F_74 ( V_130 -> V_26 ) ? 1 : 0 ) ;
}
if ( ++ V_133 >= V_132 )
break;
}
F_71 ( V_2 ) ;
F_54 ( V_2 , V_68 ) ;
F_68 ( V_2 ) ;
V_133 = 0 ;
F_72 (bd2, blist, bd_list) {
F_11 ( V_131 -> V_26 ) ;
F_71 ( V_2 ) ;
F_20 ( V_131 -> V_26 ) ;
if ( F_74 ( V_131 -> V_26 ) ) {
void * V_117 ;
V_68 = F_56 ( V_80 , V_90 ) ;
V_118 = F_57 ( V_68 ) ;
V_117 = F_62 ( V_131 -> V_26 -> V_103 ) ;
memcpy ( V_118 , V_117 + F_33 ( V_131 -> V_26 ) ,
V_131 -> V_26 -> V_74 ) ;
F_64 ( V_117 ) ;
* ( T_3 * ) V_118 = 0 ;
F_61 ( V_131 -> V_26 ) ;
F_26 ( V_131 -> V_26 ) ;
F_24 ( V_131 -> V_26 ) ;
F_54 ( V_2 , V_68 ) ;
} else {
F_53 ( V_2 , V_131 -> V_26 ) ;
}
F_68 ( V_2 ) ;
if ( ++ V_133 >= V_132 )
break;
}
F_2 ( V_127 < V_132 ) ;
V_127 -= V_132 ;
}
F_71 ( V_2 ) ;
}
static void F_75 ( struct V_1 * V_2 , struct V_44 * V_45 )
{
unsigned int V_126 = F_76 ( V_2 ) ;
unsigned int V_136 ;
if ( V_45 == NULL )
return;
V_136 = V_45 -> V_137 - V_45 -> V_138 ;
F_67 ( V_2 , V_126 , V_136 , & V_45 -> V_139 , 0 ) ;
}
static void F_77 ( struct V_1 * V_2 , struct V_44 * V_45 )
{
struct V_120 * V_140 ;
struct V_5 * V_6 ;
if ( V_45 == NULL )
return;
V_140 = & V_45 -> V_139 ;
while ( ! F_78 ( V_140 ) ) {
V_6 = F_66 ( V_140 -> V_67 , struct V_5 , V_125 ) ;
F_79 ( & V_6 -> V_125 ) ;
F_18 ( V_2 , V_6 -> V_26 , V_45 ) ;
}
}
static void F_80 ( struct V_141 * V_142 ,
struct V_143 * V_140 , int V_144 )
{
if ( V_144 != 0 )
return;
V_142 -> V_145 = 0 ;
V_142 -> V_146 = 0 ;
}
static int F_81 ( struct V_141 * V_142 , unsigned int V_147 ,
struct V_107 * V_108 , T_4 * V_118 ,
int V_144 )
{
struct V_148 * V_149 = F_82 ( V_142 -> V_150 ) ;
struct V_1 * V_2 = F_83 ( V_142 -> V_150 ) ;
struct V_19 * V_20 = V_149 -> V_151 ;
unsigned int V_152 = F_84 ( V_108 -> V_106 ) ;
struct V_3 * V_153 , * V_154 ;
T_1 V_86 ;
int error = 0 ;
if ( V_144 != 1 || F_84 ( V_108 -> V_104 ) != V_135 )
return 0 ;
F_85 ( V_142 , & V_147 ) ;
for (; V_152 ; F_85 ( V_142 , & V_147 ) , V_152 -- ) {
V_86 = F_86 ( * V_118 ++ ) ;
V_142 -> V_145 ++ ;
if ( F_87 ( V_142 , V_86 , V_147 ) )
continue;
error = F_88 ( V_142 , V_147 , & V_153 ) ;
if ( error )
return error ;
V_154 = F_89 ( V_20 , V_86 ) ;
memcpy ( V_154 -> V_37 , V_153 -> V_37 , V_153 -> V_74 ) ;
if ( F_90 ( V_2 , V_154 ) )
error = - V_155 ;
else
F_21 ( V_154 ) ;
F_24 ( V_153 ) ;
F_24 ( V_154 ) ;
if ( error )
break;
V_142 -> V_146 ++ ;
}
return error ;
}
static void F_91 ( struct V_19 * V_20 )
{
struct V_156 * V_157 = F_92 ( V_20 ) ;
struct V_1 * V_2 = V_20 -> V_16 . V_21 ;
int error ;
if ( V_157 == NULL )
V_157 = & V_2 -> V_158 ;
F_93 ( V_157 ) ;
error = F_94 ( V_157 ) ;
if ( error )
F_95 ( V_20 -> V_16 . V_21 ) ;
}
static void F_96 ( struct V_141 * V_142 , int error , int V_144 )
{
struct V_148 * V_149 = F_82 ( V_142 -> V_150 ) ;
struct V_1 * V_2 = F_83 ( V_142 -> V_150 ) ;
if ( error ) {
F_91 ( V_149 -> V_151 ) ;
return;
}
if ( V_144 != 1 )
return;
F_91 ( V_149 -> V_151 ) ;
F_97 ( V_2 , L_2 ,
V_142 -> V_159 , V_142 -> V_146 , V_142 -> V_145 ) ;
}
static void F_98 ( struct V_1 * V_2 , struct V_44 * V_45 )
{
struct V_160 * V_161 ;
unsigned int V_101 ;
struct V_120 * V_140 = & V_2 -> V_162 ;
struct V_5 * V_6 ;
struct V_68 * V_68 ;
unsigned int V_163 ;
F_99 ( V_2 ) ;
if ( ! V_2 -> V_164 )
return;
V_163 = F_100 ( V_2 , V_2 -> V_164 , sizeof( T_1 ) ) ;
V_68 = F_55 ( V_2 , V_165 , V_163 , V_2 -> V_164 ) ;
V_101 = sizeof( struct V_107 ) ;
F_30 (bd, head, bd_list) {
V_2 -> V_164 -- ;
if ( V_101 + sizeof( T_1 ) > V_2 -> V_166 . V_167 ) {
F_54 ( V_2 , V_68 ) ;
V_68 = F_56 ( V_80 , V_90 ) ;
V_161 = F_57 ( V_68 ) ;
F_58 ( V_161 ) ;
V_161 -> V_110 = F_59 ( V_111 ) ;
V_161 -> V_112 = F_59 ( V_168 ) ;
V_161 -> V_114 = F_59 ( V_169 ) ;
V_101 = sizeof( struct V_160 ) ;
}
* ( T_4 * ) ( F_57 ( V_68 ) + V_101 ) = F_73 ( V_6 -> V_170 ) ;
V_101 += sizeof( T_1 ) ;
}
F_5 ( V_2 , ! V_2 -> V_164 ) ;
F_54 ( V_2 , V_68 ) ;
}
static void F_101 ( struct V_1 * V_2 , struct V_44 * V_45 )
{
struct V_120 * V_140 = & V_2 -> V_162 ;
struct V_5 * V_6 ;
struct V_19 * V_20 ;
while ( ! F_78 ( V_140 ) ) {
V_6 = F_66 ( V_140 -> V_67 , struct V_5 , V_125 ) ;
F_79 ( & V_6 -> V_125 ) ;
V_20 = V_6 -> V_15 ;
F_27 ( & V_20 -> V_171 ) ;
F_17 ( V_50 , & V_20 -> V_51 ) ;
F_102 ( V_172 , V_6 ) ;
}
}
static void F_103 ( struct V_141 * V_142 ,
struct V_143 * V_140 , int V_144 )
{
if ( V_144 != 0 )
return;
V_142 -> V_173 = 0 ;
V_142 -> V_174 = V_140 -> V_175 ;
}
static int F_104 ( struct V_141 * V_142 , unsigned int V_147 ,
struct V_107 * V_108 , T_4 * V_118 ,
int V_144 )
{
struct V_1 * V_2 = F_83 ( V_142 -> V_150 ) ;
unsigned int V_152 = F_84 ( V_108 -> V_105 ) ;
unsigned int V_176 = F_84 ( V_108 -> V_106 ) ;
struct V_3 * V_4 ;
unsigned int V_101 ;
T_1 V_86 ;
int V_177 = 1 ;
int error ;
if ( V_144 != 0 || F_84 ( V_108 -> V_104 ) != V_165 )
return 0 ;
V_101 = sizeof( struct V_107 ) ;
for (; V_152 ; F_85 ( V_142 , & V_147 ) , V_152 -- ) {
error = F_88 ( V_142 , V_147 , & V_4 ) ;
if ( error )
return error ;
if ( ! V_177 )
F_105 ( V_2 , V_4 , V_168 ) ;
while ( V_101 + sizeof( T_1 ) <= V_2 -> V_166 . V_167 ) {
V_86 = F_86 ( * ( T_4 * ) ( V_4 -> V_37 + V_101 ) ) ;
error = F_106 ( V_142 , V_86 , V_147 ) ;
if ( error < 0 ) {
F_24 ( V_4 ) ;
return error ;
}
else if ( error )
V_142 -> V_173 ++ ;
if ( ! -- V_176 )
break;
V_101 += sizeof( T_1 ) ;
}
F_24 ( V_4 ) ;
V_101 = sizeof( struct V_160 ) ;
V_177 = 0 ;
}
return 0 ;
}
static void F_107 ( struct V_141 * V_142 , int error , int V_144 )
{
struct V_1 * V_2 = F_83 ( V_142 -> V_150 ) ;
if ( error ) {
F_108 ( V_142 ) ;
return;
}
if ( V_144 != 1 )
return;
F_97 ( V_2 , L_3 ,
V_142 -> V_159 , V_142 -> V_173 ) ;
F_108 ( V_142 ) ;
}
static void F_109 ( struct V_1 * V_2 , struct V_44 * V_45 )
{
unsigned int V_126 = F_110 ( V_2 ) ;
unsigned int V_136 ;
if ( V_45 == NULL )
return;
V_136 = V_45 -> V_178 - V_45 -> V_179 ;
F_67 ( V_2 , V_126 , V_136 , & V_45 -> V_180 , 1 ) ;
}
static int F_111 ( struct V_141 * V_142 , unsigned int V_147 ,
struct V_107 * V_108 ,
T_4 * V_118 , int V_144 )
{
struct V_148 * V_149 = F_82 ( V_142 -> V_150 ) ;
struct V_19 * V_20 = V_149 -> V_151 ;
unsigned int V_152 = F_84 ( V_108 -> V_106 ) ;
struct V_3 * V_153 , * V_154 ;
T_1 V_86 ;
T_1 V_181 ;
int error = 0 ;
if ( V_144 != 1 || F_84 ( V_108 -> V_104 ) != V_134 )
return 0 ;
F_85 ( V_142 , & V_147 ) ;
for (; V_152 ; F_85 ( V_142 , & V_147 ) , V_152 -- ) {
V_86 = F_86 ( * V_118 ++ ) ;
V_181 = F_86 ( * V_118 ++ ) ;
V_142 -> V_145 ++ ;
if ( F_87 ( V_142 , V_86 , V_147 ) )
continue;
error = F_88 ( V_142 , V_147 , & V_153 ) ;
if ( error )
return error ;
V_154 = F_89 ( V_20 , V_86 ) ;
memcpy ( V_154 -> V_37 , V_153 -> V_37 , V_153 -> V_74 ) ;
if ( V_181 ) {
T_3 * V_182 = ( T_3 * ) V_154 -> V_37 ;
* V_182 = F_59 ( V_111 ) ;
}
F_21 ( V_154 ) ;
F_24 ( V_153 ) ;
F_24 ( V_154 ) ;
V_142 -> V_146 ++ ;
}
return error ;
}
static void F_112 ( struct V_141 * V_142 , int error , int V_144 )
{
struct V_148 * V_149 = F_82 ( V_142 -> V_150 ) ;
struct V_1 * V_2 = F_83 ( V_142 -> V_150 ) ;
if ( error ) {
F_91 ( V_149 -> V_151 ) ;
return;
}
if ( V_144 != 1 )
return;
F_91 ( V_149 -> V_151 ) ;
F_97 ( V_2 , L_4 ,
V_142 -> V_159 , V_142 -> V_146 , V_142 -> V_145 ) ;
}
static void F_113 ( struct V_1 * V_2 , struct V_44 * V_45 )
{
struct V_120 * V_140 ;
struct V_5 * V_6 ;
if ( V_45 == NULL )
return;
V_140 = & V_45 -> V_180 ;
while ( ! F_78 ( V_140 ) ) {
V_6 = F_66 ( V_140 -> V_67 , struct V_5 , V_125 ) ;
F_79 ( & V_6 -> V_125 ) ;
F_18 ( V_2 , V_6 -> V_26 , V_45 ) ;
}
}
