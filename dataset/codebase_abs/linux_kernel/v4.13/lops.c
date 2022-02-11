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
struct V_22 * V_23 = F_16 ( V_20 ) ;
unsigned int V_24 = V_6 -> V_25 -> V_26 - V_20 -> V_16 . V_27 ;
struct V_28 * V_29 = V_23 -> V_30 + V_24 ;
if ( V_29 -> V_31 == NULL )
return;
if ( V_2 -> V_32 . V_33 )
F_17 ( V_2 , V_23 -> V_34 , V_6 -> V_25 , V_29 , 1 , NULL ) ;
memcpy ( V_29 -> V_31 + V_29 -> V_35 ,
V_6 -> V_25 -> V_36 + V_29 -> V_35 , V_29 -> V_37 ) ;
F_18 ( V_38 , & V_29 -> V_39 ) ;
V_23 -> V_40 = V_23 -> V_41 ;
V_23 -> V_42 = V_23 -> V_41 ;
}
static void F_19 ( struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_43 * V_44 )
{
struct V_5 * V_6 = V_4 -> V_9 ;
F_2 ( ! F_6 ( V_4 ) ) ;
F_2 ( ! F_20 ( V_4 ) ) ;
F_21 ( V_4 ) ;
F_22 ( V_4 ) ;
F_23 ( V_4 ) ;
if ( F_14 ( V_6 ) )
F_15 ( V_6 ) ;
F_8 ( & V_2 -> V_10 ) ;
if ( V_6 -> V_11 ) {
F_24 ( & V_6 -> V_12 ) ;
F_25 ( V_4 ) ;
} else {
struct V_19 * V_20 = V_6 -> V_15 ;
F_26 ( & V_6 -> V_45 , & V_20 -> V_46 ) ;
F_12 ( & V_20 -> V_47 ) ;
}
V_6 -> V_11 = V_44 ;
F_26 ( & V_6 -> V_12 , & V_44 -> V_48 ) ;
F_10 ( & V_2 -> V_10 ) ;
F_18 ( V_49 , & V_6 -> V_15 -> V_50 ) ;
F_13 ( V_6 , 0 ) ;
F_27 ( V_4 ) ;
F_28 ( & V_2 -> V_14 ) ;
}
static void F_29 ( struct V_1 * V_2 )
{
F_2 ( ( V_2 -> V_51 == V_2 -> V_52 ) &&
( V_2 -> V_51 != V_2 -> V_53 ) ) ;
if ( ++ V_2 -> V_51 == V_2 -> V_54 -> V_55 )
V_2 -> V_51 = 0 ;
}
static T_1 F_30 ( struct V_1 * V_2 )
{
unsigned int V_56 = V_2 -> V_51 ;
struct V_57 * V_58 ;
T_1 V_59 ;
F_31 (je, &sdp->sd_jdesc->extent_list, list) {
if ( ( V_56 >= V_58 -> V_60 ) && ( V_56 < ( V_58 -> V_60 + V_58 -> V_61 ) ) ) {
V_59 = V_58 -> V_62 + V_56 - V_58 -> V_60 ;
F_29 ( V_2 ) ;
return V_59 ;
}
}
return - 1 ;
}
static void F_32 ( struct V_1 * V_2 , struct V_63 * V_64 ,
T_2 error )
{
struct V_3 * V_4 , * V_65 ;
struct V_66 * V_66 = V_64 -> V_67 ;
unsigned V_68 ;
V_4 = F_33 ( V_66 ) ;
V_68 = V_64 -> V_69 ;
while ( F_34 ( V_4 ) < V_64 -> V_70 )
V_4 = V_4 -> V_71 ;
do {
if ( error )
F_35 ( V_4 ) ;
F_27 ( V_4 ) ;
V_65 = V_4 -> V_71 ;
V_68 -= V_4 -> V_72 ;
F_25 ( V_4 ) ;
V_4 = V_65 ;
} while( V_4 && V_68 );
}
static void F_36 ( struct V_73 * V_73 )
{
struct V_1 * V_2 = V_73 -> V_74 ;
struct V_63 * V_64 ;
struct V_66 * V_66 ;
int V_75 ;
if ( V_73 -> V_76 )
F_37 ( V_2 , L_1 , V_73 -> V_76 ) ;
F_38 (bvec, bio, i) {
V_66 = V_64 -> V_67 ;
if ( F_39 ( V_66 ) )
F_32 ( V_2 , V_64 , V_73 -> V_76 ) ;
else
F_40 ( V_66 , V_77 ) ;
}
F_41 ( V_73 ) ;
if ( F_42 ( & V_2 -> V_78 ) )
F_43 ( & V_2 -> V_79 ) ;
}
void F_44 ( struct V_1 * V_2 , int V_80 , int V_81 )
{
if ( V_2 -> V_82 ) {
F_12 ( & V_2 -> V_78 ) ;
F_45 ( V_2 -> V_82 , V_80 , V_81 ) ;
F_46 ( V_2 -> V_82 ) ;
V_2 -> V_82 = NULL ;
}
}
static struct V_73 * F_47 ( struct V_1 * V_2 , T_1 V_83 )
{
struct V_84 * V_85 = V_2 -> V_86 ;
struct V_73 * V_73 ;
F_2 ( V_2 -> V_82 ) ;
V_73 = F_48 ( V_87 , V_88 ) ;
V_73 -> V_89 . V_90 = V_83 * ( V_85 -> V_91 >> 9 ) ;
V_73 -> V_92 = V_85 -> V_93 ;
V_73 -> V_94 = F_36 ;
V_73 -> V_74 = V_2 ;
V_2 -> V_82 = V_73 ;
return V_73 ;
}
static struct V_73 * F_49 ( struct V_1 * V_2 , T_1 V_83 )
{
struct V_73 * V_73 = V_2 -> V_82 ;
T_1 V_95 ;
if ( V_73 ) {
V_95 = F_50 ( V_73 ) ;
V_95 >>= V_2 -> V_96 ;
if ( V_83 == V_95 )
return V_73 ;
F_44 ( V_2 , V_97 , 0 ) ;
}
return F_47 ( V_2 , V_83 ) ;
}
static void F_51 ( struct V_1 * V_2 , struct V_66 * V_66 ,
unsigned V_68 , unsigned V_98 )
{
T_1 V_83 = F_30 ( V_2 ) ;
struct V_73 * V_73 ;
int V_99 ;
V_73 = F_49 ( V_2 , V_83 ) ;
V_99 = F_52 ( V_73 , V_66 , V_68 , V_98 ) ;
if ( V_99 == 0 ) {
F_44 ( V_2 , V_97 , 0 ) ;
V_73 = F_47 ( V_2 , V_83 ) ;
V_99 = F_52 ( V_73 , V_66 , V_68 , V_98 ) ;
F_53 ( V_99 == 0 ) ;
}
}
static void F_54 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
F_51 ( V_2 , V_4 -> V_100 , V_4 -> V_72 , F_34 ( V_4 ) ) ;
}
void F_55 ( struct V_1 * V_2 , struct V_66 * V_66 )
{
struct V_84 * V_85 = V_2 -> V_86 ;
F_51 ( V_2 , V_66 , V_85 -> V_91 , 0 ) ;
}
static struct V_66 * F_56 ( struct V_1 * V_2 , T_3 V_101 ,
T_3 V_102 , T_3 V_103 )
{
struct V_66 * V_66 = F_57 ( V_77 , V_87 ) ;
struct V_104 * V_105 = F_58 ( V_66 ) ;
F_59 ( V_105 ) ;
V_105 -> V_106 . V_107 = F_60 ( V_108 ) ;
V_105 -> V_106 . V_109 = F_60 ( V_110 ) ;
V_105 -> V_106 . V_111 = F_60 ( V_112 ) ;
V_105 -> V_101 = F_60 ( V_101 ) ;
V_105 -> V_102 = F_60 ( V_102 ) ;
V_105 -> V_103 = F_60 ( V_103 ) ;
V_105 -> V_113 = 0 ;
return V_66 ;
}
static void F_61 ( struct V_3 * V_4 )
{
void * V_114 ;
T_4 * V_115 ;
F_62 ( V_4 ) ;
V_114 = F_63 ( V_4 -> V_100 ) ;
V_115 = V_114 + F_34 ( V_4 ) ;
if ( * V_115 == F_60 ( V_108 ) )
F_64 ( V_4 ) ;
F_65 ( V_114 ) ;
}
static int F_66 ( void * V_116 , struct V_117 * V_118 , struct V_117 * V_119 )
{
struct V_5 * V_120 , * V_121 ;
V_120 = F_67 ( V_118 , struct V_5 , V_122 ) ;
V_121 = F_67 ( V_119 , struct V_5 , V_122 ) ;
if ( V_120 -> V_25 -> V_26 < V_121 -> V_25 -> V_26 )
return - 1 ;
if ( V_120 -> V_25 -> V_26 > V_121 -> V_25 -> V_26 )
return 1 ;
return 0 ;
}
static void F_68 ( struct V_1 * V_2 , unsigned int V_123 ,
unsigned int V_124 , struct V_117 * V_125 ,
bool V_126 )
{
struct V_104 * V_105 ;
struct V_5 * V_127 = NULL , * V_128 ;
struct V_66 * V_66 ;
unsigned int V_129 ;
unsigned V_130 ;
T_5 * V_115 ;
F_69 ( V_2 ) ;
F_70 ( NULL , V_125 , F_66 ) ;
V_127 = V_128 = F_71 ( V_127 , V_125 , V_122 ) ;
while( V_124 ) {
V_129 = V_124 ;
if ( V_124 > V_123 )
V_129 = V_123 ;
F_72 ( V_2 ) ;
V_66 = F_56 ( V_2 ,
V_126 ? V_131 :
V_132 , V_129 + 1 , V_129 ) ;
V_105 = F_58 ( V_66 ) ;
F_69 ( V_2 ) ;
V_115 = ( T_5 * ) ( V_105 + 1 ) ;
V_130 = 0 ;
F_73 (bd1, blist, bd_list) {
* V_115 ++ = F_74 ( V_127 -> V_25 -> V_26 ) ;
if ( V_126 ) {
F_61 ( V_127 -> V_25 ) ;
* V_115 ++ = F_74 ( F_75 ( V_127 -> V_25 ) ? 1 : 0 ) ;
}
if ( ++ V_130 >= V_129 )
break;
}
F_72 ( V_2 ) ;
F_55 ( V_2 , V_66 ) ;
F_69 ( V_2 ) ;
V_130 = 0 ;
F_73 (bd2, blist, bd_list) {
F_11 ( V_128 -> V_25 ) ;
F_72 ( V_2 ) ;
F_21 ( V_128 -> V_25 ) ;
if ( F_75 ( V_128 -> V_25 ) ) {
void * V_114 ;
V_66 = F_57 ( V_77 , V_87 ) ;
V_115 = F_58 ( V_66 ) ;
V_114 = F_63 ( V_128 -> V_25 -> V_100 ) ;
memcpy ( V_115 , V_114 + F_34 ( V_128 -> V_25 ) ,
V_128 -> V_25 -> V_72 ) ;
F_65 ( V_114 ) ;
* ( T_4 * ) V_115 = 0 ;
F_62 ( V_128 -> V_25 ) ;
F_27 ( V_128 -> V_25 ) ;
F_25 ( V_128 -> V_25 ) ;
F_55 ( V_2 , V_66 ) ;
} else {
F_54 ( V_2 , V_128 -> V_25 ) ;
}
F_69 ( V_2 ) ;
if ( ++ V_130 >= V_129 )
break;
}
F_2 ( V_124 < V_129 ) ;
V_124 -= V_129 ;
}
F_72 ( V_2 ) ;
}
static void F_76 ( struct V_1 * V_2 , struct V_43 * V_44 )
{
unsigned int V_123 = F_77 ( V_2 ) ;
unsigned int V_133 ;
if ( V_44 == NULL )
return;
V_133 = V_44 -> V_134 - V_44 -> V_135 ;
F_68 ( V_2 , V_123 , V_133 , & V_44 -> V_136 , 0 ) ;
}
static void F_78 ( struct V_1 * V_2 , struct V_43 * V_44 )
{
struct V_117 * V_137 ;
struct V_5 * V_6 ;
if ( V_44 == NULL )
return;
V_137 = & V_44 -> V_136 ;
while ( ! F_79 ( V_137 ) ) {
V_6 = F_67 ( V_137 -> V_65 , struct V_5 , V_122 ) ;
F_80 ( & V_6 -> V_122 ) ;
F_19 ( V_2 , V_6 -> V_25 , V_44 ) ;
}
}
static void F_81 ( struct V_138 * V_139 ,
struct V_140 * V_137 , int V_141 )
{
if ( V_141 != 0 )
return;
V_139 -> V_142 = 0 ;
V_139 -> V_143 = 0 ;
}
static int F_82 ( struct V_138 * V_139 , unsigned int V_144 ,
struct V_104 * V_105 , T_5 * V_115 ,
int V_141 )
{
struct V_145 * V_146 = F_83 ( V_139 -> V_147 ) ;
struct V_1 * V_2 = F_84 ( V_139 -> V_147 ) ;
struct V_19 * V_20 = V_146 -> V_148 ;
unsigned int V_149 = F_85 ( V_105 -> V_103 ) ;
struct V_3 * V_150 , * V_151 ;
T_1 V_83 ;
int error = 0 ;
if ( V_141 != 1 || F_85 ( V_105 -> V_101 ) != V_132 )
return 0 ;
F_86 ( V_139 , & V_144 ) ;
for (; V_149 ; F_86 ( V_139 , & V_144 ) , V_149 -- ) {
V_83 = F_87 ( * V_115 ++ ) ;
V_139 -> V_142 ++ ;
if ( F_88 ( V_139 , V_83 , V_144 ) )
continue;
error = F_89 ( V_139 , V_144 , & V_150 ) ;
if ( error )
return error ;
V_151 = F_90 ( V_20 , V_83 ) ;
memcpy ( V_151 -> V_36 , V_150 -> V_36 , V_150 -> V_72 ) ;
if ( F_91 ( V_2 , V_151 ) )
error = - V_152 ;
else
F_22 ( V_151 ) ;
F_25 ( V_150 ) ;
F_25 ( V_151 ) ;
if ( error )
break;
V_139 -> V_143 ++ ;
}
return error ;
}
static void F_92 ( struct V_19 * V_20 )
{
struct V_153 * V_154 = F_93 ( V_20 ) ;
struct V_1 * V_2 = V_20 -> V_16 . V_21 ;
int error ;
if ( V_154 == NULL )
V_154 = & V_2 -> V_155 ;
F_94 ( V_154 ) ;
error = F_95 ( V_154 ) ;
if ( error )
F_96 ( V_20 -> V_16 . V_21 ) ;
}
static void F_97 ( struct V_138 * V_139 , int error , int V_141 )
{
struct V_145 * V_146 = F_83 ( V_139 -> V_147 ) ;
struct V_1 * V_2 = F_84 ( V_139 -> V_147 ) ;
if ( error ) {
F_92 ( V_146 -> V_148 ) ;
return;
}
if ( V_141 != 1 )
return;
F_92 ( V_146 -> V_148 ) ;
F_98 ( V_2 , L_2 ,
V_139 -> V_156 , V_139 -> V_143 , V_139 -> V_142 ) ;
}
static void F_99 ( struct V_1 * V_2 , struct V_43 * V_44 )
{
struct V_157 * V_158 ;
unsigned int V_98 ;
struct V_117 * V_137 = & V_2 -> V_159 ;
struct V_5 * V_6 ;
struct V_66 * V_66 ;
unsigned int V_160 ;
F_100 ( V_2 ) ;
if ( ! V_2 -> V_161 )
return;
V_160 = F_101 ( V_2 , V_2 -> V_161 , sizeof( T_1 ) ) ;
V_66 = F_56 ( V_2 , V_162 , V_160 , V_2 -> V_161 ) ;
V_98 = sizeof( struct V_104 ) ;
F_31 (bd, head, bd_list) {
V_2 -> V_161 -- ;
if ( V_98 + sizeof( T_1 ) > V_2 -> V_163 . V_164 ) {
F_55 ( V_2 , V_66 ) ;
V_66 = F_57 ( V_77 , V_87 ) ;
V_158 = F_58 ( V_66 ) ;
F_59 ( V_158 ) ;
V_158 -> V_107 = F_60 ( V_108 ) ;
V_158 -> V_109 = F_60 ( V_165 ) ;
V_158 -> V_111 = F_60 ( V_166 ) ;
V_98 = sizeof( struct V_157 ) ;
}
* ( T_5 * ) ( F_58 ( V_66 ) + V_98 ) = F_74 ( V_6 -> V_167 ) ;
V_98 += sizeof( T_1 ) ;
}
F_5 ( V_2 , ! V_2 -> V_161 ) ;
F_55 ( V_2 , V_66 ) ;
}
static void F_102 ( struct V_1 * V_2 , struct V_43 * V_44 )
{
struct V_117 * V_137 = & V_2 -> V_159 ;
struct V_5 * V_6 ;
struct V_19 * V_20 ;
while ( ! F_79 ( V_137 ) ) {
V_6 = F_67 ( V_137 -> V_65 , struct V_5 , V_122 ) ;
F_80 ( & V_6 -> V_122 ) ;
V_20 = V_6 -> V_15 ;
F_28 ( & V_20 -> V_168 ) ;
F_18 ( V_49 , & V_20 -> V_50 ) ;
F_103 ( V_169 , V_6 ) ;
}
}
static void F_104 ( struct V_138 * V_139 ,
struct V_140 * V_137 , int V_141 )
{
if ( V_141 != 0 )
return;
V_139 -> V_170 = 0 ;
V_139 -> V_171 = V_137 -> V_172 ;
}
static int F_105 ( struct V_138 * V_139 , unsigned int V_144 ,
struct V_104 * V_105 , T_5 * V_115 ,
int V_141 )
{
struct V_1 * V_2 = F_84 ( V_139 -> V_147 ) ;
unsigned int V_149 = F_85 ( V_105 -> V_102 ) ;
unsigned int V_173 = F_85 ( V_105 -> V_103 ) ;
struct V_3 * V_4 ;
unsigned int V_98 ;
T_1 V_83 ;
int V_174 = 1 ;
int error ;
if ( V_141 != 0 || F_85 ( V_105 -> V_101 ) != V_162 )
return 0 ;
V_98 = sizeof( struct V_104 ) ;
for (; V_149 ; F_86 ( V_139 , & V_144 ) , V_149 -- ) {
error = F_89 ( V_139 , V_144 , & V_4 ) ;
if ( error )
return error ;
if ( ! V_174 )
F_106 ( V_2 , V_4 , V_165 ) ;
while ( V_98 + sizeof( T_1 ) <= V_2 -> V_163 . V_164 ) {
V_83 = F_87 ( * ( T_5 * ) ( V_4 -> V_36 + V_98 ) ) ;
error = F_107 ( V_139 , V_83 , V_144 ) ;
if ( error < 0 ) {
F_25 ( V_4 ) ;
return error ;
}
else if ( error )
V_139 -> V_170 ++ ;
if ( ! -- V_173 )
break;
V_98 += sizeof( T_1 ) ;
}
F_25 ( V_4 ) ;
V_98 = sizeof( struct V_157 ) ;
V_174 = 0 ;
}
return 0 ;
}
static void F_108 ( struct V_138 * V_139 , int error , int V_141 )
{
struct V_1 * V_2 = F_84 ( V_139 -> V_147 ) ;
if ( error ) {
F_109 ( V_139 ) ;
return;
}
if ( V_141 != 1 )
return;
F_98 ( V_2 , L_3 ,
V_139 -> V_156 , V_139 -> V_170 ) ;
F_109 ( V_139 ) ;
}
static void F_110 ( struct V_1 * V_2 , struct V_43 * V_44 )
{
unsigned int V_123 = F_111 ( V_2 ) ;
unsigned int V_133 ;
if ( V_44 == NULL )
return;
V_133 = V_44 -> V_175 - V_44 -> V_176 ;
F_68 ( V_2 , V_123 , V_133 , & V_44 -> V_177 , 1 ) ;
}
static int F_112 ( struct V_138 * V_139 , unsigned int V_144 ,
struct V_104 * V_105 ,
T_5 * V_115 , int V_141 )
{
struct V_145 * V_146 = F_83 ( V_139 -> V_147 ) ;
struct V_19 * V_20 = V_146 -> V_148 ;
unsigned int V_149 = F_85 ( V_105 -> V_103 ) ;
struct V_3 * V_150 , * V_151 ;
T_1 V_83 ;
T_1 V_178 ;
int error = 0 ;
if ( V_141 != 1 || F_85 ( V_105 -> V_101 ) != V_131 )
return 0 ;
F_86 ( V_139 , & V_144 ) ;
for (; V_149 ; F_86 ( V_139 , & V_144 ) , V_149 -- ) {
V_83 = F_87 ( * V_115 ++ ) ;
V_178 = F_87 ( * V_115 ++ ) ;
V_139 -> V_142 ++ ;
if ( F_88 ( V_139 , V_83 , V_144 ) )
continue;
error = F_89 ( V_139 , V_144 , & V_150 ) ;
if ( error )
return error ;
V_151 = F_90 ( V_20 , V_83 ) ;
memcpy ( V_151 -> V_36 , V_150 -> V_36 , V_150 -> V_72 ) ;
if ( V_178 ) {
T_4 * V_179 = ( T_4 * ) V_151 -> V_36 ;
* V_179 = F_60 ( V_108 ) ;
}
F_22 ( V_151 ) ;
F_25 ( V_150 ) ;
F_25 ( V_151 ) ;
V_139 -> V_143 ++ ;
}
return error ;
}
static void F_113 ( struct V_138 * V_139 , int error , int V_141 )
{
struct V_145 * V_146 = F_83 ( V_139 -> V_147 ) ;
struct V_1 * V_2 = F_84 ( V_139 -> V_147 ) ;
if ( error ) {
F_92 ( V_146 -> V_148 ) ;
return;
}
if ( V_141 != 1 )
return;
F_92 ( V_146 -> V_148 ) ;
F_98 ( V_2 , L_4 ,
V_139 -> V_156 , V_139 -> V_143 , V_139 -> V_142 ) ;
}
static void F_114 ( struct V_1 * V_2 , struct V_43 * V_44 )
{
struct V_117 * V_137 ;
struct V_5 * V_6 ;
if ( V_44 == NULL )
return;
V_137 = & V_44 -> V_177 ;
while ( ! F_79 ( V_137 ) ) {
V_6 = F_67 ( V_137 -> V_65 , struct V_5 , V_122 ) ;
F_80 ( & V_6 -> V_122 ) ;
F_19 ( V_2 , V_6 -> V_25 , V_44 ) ;
}
}
