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
}
static void F_18 ( struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_43 * V_44 )
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
F_25 ( & V_6 -> V_45 , & V_20 -> V_46 ) ;
F_12 ( & V_20 -> V_47 ) ;
}
V_6 -> V_11 = V_44 ;
F_25 ( & V_6 -> V_12 , & V_44 -> V_48 ) ;
F_10 ( & V_2 -> V_10 ) ;
F_17 ( V_49 , & V_6 -> V_15 -> V_50 ) ;
F_13 ( V_6 , 0 ) ;
F_26 ( V_4 ) ;
F_27 ( & V_2 -> V_14 ) ;
}
static void F_28 ( struct V_1 * V_2 )
{
F_2 ( ( V_2 -> V_51 == V_2 -> V_52 ) &&
( V_2 -> V_51 != V_2 -> V_53 ) ) ;
if ( ++ V_2 -> V_51 == V_2 -> V_54 -> V_55 ) {
V_2 -> V_51 = 0 ;
V_2 -> V_56 = 1 ;
}
}
static T_1 F_29 ( struct V_1 * V_2 )
{
unsigned int V_57 = V_2 -> V_51 ;
struct V_58 * V_59 ;
T_1 V_60 ;
F_30 (je, &sdp->sd_jdesc->extent_list, extent_list) {
if ( V_57 >= V_59 -> V_61 && V_57 < V_59 -> V_61 + V_59 -> V_62 ) {
V_60 = V_59 -> V_63 + V_57 - V_59 -> V_61 ;
F_28 ( V_2 ) ;
return V_60 ;
}
}
return - 1 ;
}
static void F_31 ( struct V_1 * V_2 , struct V_64 * V_65 ,
int error )
{
struct V_3 * V_4 , * V_66 ;
struct V_67 * V_67 = V_65 -> V_68 ;
unsigned V_69 ;
V_4 = F_32 ( V_67 ) ;
V_69 = V_65 -> V_70 ;
while ( F_33 ( V_4 ) < V_65 -> V_71 )
V_4 = V_4 -> V_72 ;
do {
if ( error )
F_34 ( V_4 ) ;
F_26 ( V_4 ) ;
V_66 = V_4 -> V_72 ;
V_69 -= V_4 -> V_73 ;
F_24 ( V_4 ) ;
V_4 = V_66 ;
} while( V_4 && V_69 );
}
static void F_35 ( struct V_74 * V_74 , int error )
{
struct V_1 * V_2 = V_74 -> V_75 ;
struct V_64 * V_65 ;
struct V_67 * V_67 ;
int V_76 ;
if ( error ) {
V_2 -> V_77 = error ;
F_36 ( V_2 , L_1 , error ) ;
}
F_37 (bvec, bio, i) {
V_67 = V_65 -> V_68 ;
if ( F_38 ( V_67 ) )
F_31 ( V_2 , V_65 , error ) ;
else
F_39 ( V_67 , V_78 ) ;
}
F_40 ( V_74 ) ;
if ( F_41 ( & V_2 -> V_79 ) )
F_42 ( & V_2 -> V_80 ) ;
}
void F_43 ( struct V_1 * V_2 , int V_81 )
{
if ( V_2 -> V_82 ) {
F_12 ( & V_2 -> V_79 ) ;
F_44 ( V_81 , V_2 -> V_82 ) ;
V_2 -> V_82 = NULL ;
}
}
static struct V_74 * F_45 ( struct V_1 * V_2 , T_1 V_83 )
{
struct V_84 * V_85 = V_2 -> V_86 ;
unsigned V_87 = F_46 ( V_85 -> V_88 ) ;
struct V_74 * V_74 ;
F_2 ( V_2 -> V_82 ) ;
while ( 1 ) {
V_74 = F_47 ( V_89 , V_87 ) ;
if ( F_48 ( V_74 ) )
break;
V_87 = F_49 ( V_87 / 2 , 1U ) ;
}
V_74 -> V_90 = V_83 * ( V_85 -> V_91 >> 9 ) ;
V_74 -> V_92 = V_85 -> V_88 ;
V_74 -> V_93 = F_35 ;
V_74 -> V_75 = V_2 ;
V_2 -> V_82 = V_74 ;
return V_74 ;
}
static struct V_74 * F_50 ( struct V_1 * V_2 , T_1 V_83 )
{
struct V_74 * V_74 = V_2 -> V_82 ;
T_1 V_94 ;
if ( V_74 ) {
V_94 = F_51 ( V_74 ) ;
V_94 >>= V_2 -> V_95 ;
if ( V_83 == V_94 )
return V_74 ;
F_43 ( V_2 , V_96 ) ;
}
return F_45 ( V_2 , V_83 ) ;
}
static void F_52 ( struct V_1 * V_2 , struct V_67 * V_67 ,
unsigned V_69 , unsigned V_97 )
{
T_1 V_83 = F_29 ( V_2 ) ;
struct V_74 * V_74 ;
int V_98 ;
V_74 = F_50 ( V_2 , V_83 ) ;
V_98 = F_53 ( V_74 , V_67 , V_69 , V_97 ) ;
if ( V_98 == 0 ) {
F_43 ( V_2 , V_96 ) ;
V_74 = F_45 ( V_2 , V_83 ) ;
V_98 = F_53 ( V_74 , V_67 , V_69 , V_97 ) ;
F_54 ( V_98 == 0 ) ;
}
}
static void F_55 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
F_52 ( V_2 , V_4 -> V_99 , V_4 -> V_73 , F_33 ( V_4 ) ) ;
}
void F_56 ( struct V_1 * V_2 , struct V_67 * V_67 )
{
struct V_84 * V_85 = V_2 -> V_86 ;
F_52 ( V_2 , V_67 , V_85 -> V_91 , 0 ) ;
}
static struct V_67 * F_57 ( struct V_1 * V_2 , T_2 V_100 ,
T_2 V_101 , T_2 V_102 )
{
struct V_67 * V_67 = F_58 ( V_78 , V_89 ) ;
struct V_103 * V_104 = F_59 ( V_67 ) ;
F_60 ( V_104 ) ;
V_104 -> V_105 . V_106 = F_61 ( V_107 ) ;
V_104 -> V_105 . V_108 = F_61 ( V_109 ) ;
V_104 -> V_105 . V_110 = F_61 ( V_111 ) ;
V_104 -> V_100 = F_61 ( V_100 ) ;
V_104 -> V_101 = F_61 ( V_101 ) ;
V_104 -> V_102 = F_61 ( V_102 ) ;
V_104 -> V_112 = 0 ;
return V_67 ;
}
static void F_62 ( struct V_3 * V_4 )
{
void * V_113 ;
T_3 * V_114 ;
F_63 ( V_4 ) ;
V_113 = F_64 ( V_4 -> V_99 ) ;
V_114 = V_113 + F_33 ( V_4 ) ;
if ( * V_114 == F_61 ( V_107 ) )
F_65 ( V_4 ) ;
F_66 ( V_113 ) ;
}
static int F_67 ( void * V_115 , struct V_116 * V_117 , struct V_116 * V_118 )
{
struct V_5 * V_119 , * V_120 ;
V_119 = F_68 ( V_117 , struct V_5 , V_121 ) ;
V_120 = F_68 ( V_118 , struct V_5 , V_121 ) ;
if ( V_119 -> V_26 -> V_27 < V_120 -> V_26 -> V_27 )
return - 1 ;
if ( V_119 -> V_26 -> V_27 > V_120 -> V_26 -> V_27 )
return 1 ;
return 0 ;
}
static void F_69 ( struct V_1 * V_2 , unsigned int V_122 ,
unsigned int V_123 , struct V_116 * V_124 ,
bool V_125 )
{
struct V_103 * V_104 ;
struct V_5 * V_126 = NULL , * V_127 ;
struct V_67 * V_67 ;
unsigned int V_128 ;
unsigned V_129 ;
T_4 * V_114 ;
F_70 ( V_2 ) ;
F_71 ( NULL , V_124 , F_67 ) ;
V_126 = V_127 = F_72 ( V_126 , V_124 , V_121 ) ;
while( V_123 ) {
V_128 = V_123 ;
if ( V_123 > V_122 )
V_128 = V_122 ;
F_73 ( V_2 ) ;
V_67 = F_57 ( V_2 ,
V_125 ? V_130 :
V_131 , V_128 + 1 , V_128 ) ;
V_104 = F_59 ( V_67 ) ;
F_70 ( V_2 ) ;
V_114 = ( T_4 * ) ( V_104 + 1 ) ;
V_129 = 0 ;
F_74 (bd1, blist, bd_list) {
* V_114 ++ = F_75 ( V_126 -> V_26 -> V_27 ) ;
if ( V_125 ) {
F_62 ( V_126 -> V_26 ) ;
* V_114 ++ = F_75 ( F_76 ( V_126 -> V_26 ) ? 1 : 0 ) ;
}
if ( ++ V_129 >= V_128 )
break;
}
F_73 ( V_2 ) ;
F_56 ( V_2 , V_67 ) ;
F_70 ( V_2 ) ;
V_129 = 0 ;
F_74 (bd2, blist, bd_list) {
F_11 ( V_127 -> V_26 ) ;
F_73 ( V_2 ) ;
F_20 ( V_127 -> V_26 ) ;
if ( F_76 ( V_127 -> V_26 ) ) {
void * V_113 ;
V_67 = F_58 ( V_78 , V_89 ) ;
V_114 = F_59 ( V_67 ) ;
V_113 = F_64 ( V_127 -> V_26 -> V_99 ) ;
memcpy ( V_114 , V_113 + F_33 ( V_127 -> V_26 ) ,
V_127 -> V_26 -> V_73 ) ;
F_66 ( V_113 ) ;
* ( T_3 * ) V_114 = 0 ;
F_63 ( V_127 -> V_26 ) ;
F_26 ( V_127 -> V_26 ) ;
F_24 ( V_127 -> V_26 ) ;
F_56 ( V_2 , V_67 ) ;
} else {
F_55 ( V_2 , V_127 -> V_26 ) ;
}
F_70 ( V_2 ) ;
if ( ++ V_129 >= V_128 )
break;
}
F_2 ( V_123 < V_128 ) ;
V_123 -= V_128 ;
}
F_73 ( V_2 ) ;
}
static void F_77 ( struct V_1 * V_2 )
{
unsigned int V_122 = F_78 ( V_2 ) ;
F_69 ( V_2 , V_122 , V_2 -> V_132 ,
& V_2 -> V_133 , 0 ) ;
}
static void F_79 ( struct V_1 * V_2 , struct V_43 * V_44 )
{
struct V_116 * V_134 = & V_2 -> V_133 ;
struct V_5 * V_6 ;
if ( V_44 == NULL ) {
F_80 ( V_2 , F_81 ( V_134 ) ) ;
return;
}
while ( ! F_81 ( V_134 ) ) {
V_6 = F_68 ( V_134 -> V_66 , struct V_5 , V_121 ) ;
F_82 ( & V_6 -> V_121 ) ;
V_2 -> V_132 -- ;
F_18 ( V_2 , V_6 -> V_26 , V_44 ) ;
}
F_83 ( V_2 , ! V_2 -> V_132 ) ;
}
static void F_84 ( struct V_135 * V_136 ,
struct V_137 * V_134 , int V_138 )
{
struct V_1 * V_2 = F_85 ( V_136 -> V_139 ) ;
if ( V_138 != 0 )
return;
V_2 -> V_140 = 0 ;
V_2 -> V_141 = 0 ;
}
static int F_86 ( struct V_135 * V_136 , unsigned int V_142 ,
struct V_103 * V_104 , T_4 * V_114 ,
int V_138 )
{
struct V_143 * V_144 = F_87 ( V_136 -> V_139 ) ;
struct V_1 * V_2 = F_85 ( V_136 -> V_139 ) ;
struct V_19 * V_20 = V_144 -> V_145 ;
unsigned int V_146 = F_88 ( V_104 -> V_102 ) ;
struct V_3 * V_147 , * V_148 ;
T_1 V_83 ;
int error = 0 ;
if ( V_138 != 1 || F_88 ( V_104 -> V_100 ) != V_131 )
return 0 ;
F_89 ( V_2 , & V_142 ) ;
for (; V_146 ; F_89 ( V_2 , & V_142 ) , V_146 -- ) {
V_83 = F_90 ( * V_114 ++ ) ;
V_2 -> V_140 ++ ;
if ( F_91 ( V_2 , V_83 , V_142 ) )
continue;
error = F_92 ( V_136 , V_142 , & V_147 ) ;
if ( error )
return error ;
V_148 = F_93 ( V_20 , V_83 ) ;
memcpy ( V_148 -> V_37 , V_147 -> V_37 , V_147 -> V_73 ) ;
if ( F_94 ( V_2 , V_148 ) )
error = - V_149 ;
else
F_21 ( V_148 ) ;
F_24 ( V_147 ) ;
F_24 ( V_148 ) ;
if ( error )
break;
V_2 -> V_141 ++ ;
}
return error ;
}
static void F_95 ( struct V_19 * V_20 )
{
struct V_150 * V_151 = F_96 ( V_20 ) ;
int error ;
F_97 ( V_151 ) ;
error = F_98 ( V_151 ) ;
if ( error )
F_99 ( V_20 -> V_21 ) ;
}
static void F_100 ( struct V_135 * V_136 , int error , int V_138 )
{
struct V_143 * V_144 = F_87 ( V_136 -> V_139 ) ;
struct V_1 * V_2 = F_85 ( V_136 -> V_139 ) ;
if ( error ) {
F_95 ( V_144 -> V_145 ) ;
return;
}
if ( V_138 != 1 )
return;
F_95 ( V_144 -> V_145 ) ;
F_101 ( V_2 , L_2 ,
V_136 -> V_152 , V_2 -> V_141 , V_2 -> V_140 ) ;
}
static void F_102 ( struct V_1 * V_2 )
{
struct V_153 * V_154 ;
unsigned int V_97 ;
struct V_116 * V_134 = & V_2 -> V_155 ;
struct V_5 * V_6 ;
struct V_67 * V_67 ;
unsigned int V_156 ;
F_103 ( V_2 ) ;
if ( ! V_2 -> V_157 )
return;
V_156 = F_104 ( V_2 , V_2 -> V_157 , sizeof( T_1 ) ) ;
V_67 = F_57 ( V_2 , V_158 , V_156 , V_2 -> V_157 ) ;
V_97 = sizeof( struct V_103 ) ;
F_30 (bd, head, bd_list) {
V_2 -> V_157 -- ;
if ( V_97 + sizeof( T_1 ) > V_2 -> V_159 . V_160 ) {
F_56 ( V_2 , V_67 ) ;
V_67 = F_58 ( V_78 , V_89 ) ;
V_154 = F_59 ( V_67 ) ;
F_60 ( V_154 ) ;
V_154 -> V_106 = F_61 ( V_107 ) ;
V_154 -> V_108 = F_61 ( V_161 ) ;
V_154 -> V_110 = F_61 ( V_162 ) ;
V_97 = sizeof( struct V_153 ) ;
}
* ( T_4 * ) ( F_59 ( V_67 ) + V_97 ) = F_75 ( V_6 -> V_163 ) ;
V_97 += sizeof( T_1 ) ;
}
F_5 ( V_2 , ! V_2 -> V_157 ) ;
F_56 ( V_2 , V_67 ) ;
}
static void F_105 ( struct V_1 * V_2 , struct V_43 * V_44 )
{
struct V_116 * V_134 = & V_2 -> V_155 ;
struct V_5 * V_6 ;
struct V_19 * V_20 ;
while ( ! F_81 ( V_134 ) ) {
V_6 = F_68 ( V_134 -> V_66 , struct V_5 , V_121 ) ;
F_82 ( & V_6 -> V_121 ) ;
V_20 = V_6 -> V_15 ;
F_27 ( & V_20 -> V_164 ) ;
F_17 ( V_49 , & V_20 -> V_50 ) ;
F_106 ( V_165 , V_6 ) ;
}
}
static void F_107 ( struct V_135 * V_136 ,
struct V_137 * V_134 , int V_138 )
{
struct V_1 * V_2 = F_85 ( V_136 -> V_139 ) ;
if ( V_138 != 0 )
return;
V_2 -> V_166 = 0 ;
V_2 -> V_167 = V_134 -> V_168 ;
}
static int F_108 ( struct V_135 * V_136 , unsigned int V_142 ,
struct V_103 * V_104 , T_4 * V_114 ,
int V_138 )
{
struct V_1 * V_2 = F_85 ( V_136 -> V_139 ) ;
unsigned int V_146 = F_88 ( V_104 -> V_101 ) ;
unsigned int V_169 = F_88 ( V_104 -> V_102 ) ;
struct V_3 * V_4 ;
unsigned int V_97 ;
T_1 V_83 ;
int V_170 = 1 ;
int error ;
if ( V_138 != 0 || F_88 ( V_104 -> V_100 ) != V_158 )
return 0 ;
V_97 = sizeof( struct V_103 ) ;
for (; V_146 ; F_89 ( V_2 , & V_142 ) , V_146 -- ) {
error = F_92 ( V_136 , V_142 , & V_4 ) ;
if ( error )
return error ;
if ( ! V_170 )
F_109 ( V_2 , V_4 , V_161 ) ;
while ( V_97 + sizeof( T_1 ) <= V_2 -> V_159 . V_160 ) {
V_83 = F_90 ( * ( T_4 * ) ( V_4 -> V_37 + V_97 ) ) ;
error = F_110 ( V_2 , V_83 , V_142 ) ;
if ( error < 0 ) {
F_24 ( V_4 ) ;
return error ;
}
else if ( error )
V_2 -> V_166 ++ ;
if ( ! -- V_169 )
break;
V_97 += sizeof( T_1 ) ;
}
F_24 ( V_4 ) ;
V_97 = sizeof( struct V_153 ) ;
V_170 = 0 ;
}
return 0 ;
}
static void F_111 ( struct V_135 * V_136 , int error , int V_138 )
{
struct V_1 * V_2 = F_85 ( V_136 -> V_139 ) ;
if ( error ) {
F_112 ( V_2 ) ;
return;
}
if ( V_138 != 1 )
return;
F_101 ( V_2 , L_3 ,
V_136 -> V_152 , V_2 -> V_166 ) ;
F_112 ( V_2 ) ;
}
static void F_113 ( struct V_1 * V_2 )
{
unsigned int V_122 = F_78 ( V_2 ) / 2 ;
F_69 ( V_2 , V_122 , V_2 -> V_171 ,
& V_2 -> V_172 , 1 ) ;
}
static int F_114 ( struct V_135 * V_136 , unsigned int V_142 ,
struct V_103 * V_104 ,
T_4 * V_114 , int V_138 )
{
struct V_143 * V_144 = F_87 ( V_136 -> V_139 ) ;
struct V_1 * V_2 = F_85 ( V_136 -> V_139 ) ;
struct V_19 * V_20 = V_144 -> V_145 ;
unsigned int V_146 = F_88 ( V_104 -> V_102 ) ;
struct V_3 * V_147 , * V_148 ;
T_1 V_83 ;
T_1 V_173 ;
int error = 0 ;
if ( V_138 != 1 || F_88 ( V_104 -> V_100 ) != V_130 )
return 0 ;
F_89 ( V_2 , & V_142 ) ;
for (; V_146 ; F_89 ( V_2 , & V_142 ) , V_146 -- ) {
V_83 = F_90 ( * V_114 ++ ) ;
V_173 = F_90 ( * V_114 ++ ) ;
V_2 -> V_140 ++ ;
if ( F_91 ( V_2 , V_83 , V_142 ) )
continue;
error = F_92 ( V_136 , V_142 , & V_147 ) ;
if ( error )
return error ;
V_148 = F_93 ( V_20 , V_83 ) ;
memcpy ( V_148 -> V_37 , V_147 -> V_37 , V_147 -> V_73 ) ;
if ( V_173 ) {
T_3 * V_174 = ( T_3 * ) V_148 -> V_37 ;
* V_174 = F_61 ( V_107 ) ;
}
F_21 ( V_148 ) ;
F_24 ( V_147 ) ;
F_24 ( V_148 ) ;
V_2 -> V_141 ++ ;
}
return error ;
}
static void F_115 ( struct V_135 * V_136 , int error , int V_138 )
{
struct V_143 * V_144 = F_87 ( V_136 -> V_139 ) ;
struct V_1 * V_2 = F_85 ( V_136 -> V_139 ) ;
if ( error ) {
F_95 ( V_144 -> V_145 ) ;
return;
}
if ( V_138 != 1 )
return;
F_95 ( V_144 -> V_145 ) ;
F_101 ( V_2 , L_4 ,
V_136 -> V_152 , V_2 -> V_141 , V_2 -> V_140 ) ;
}
static void F_116 ( struct V_1 * V_2 , struct V_43 * V_44 )
{
struct V_116 * V_134 = & V_2 -> V_172 ;
struct V_5 * V_6 ;
if ( V_44 == NULL ) {
F_80 ( V_2 , F_81 ( V_134 ) ) ;
return;
}
while ( ! F_81 ( V_134 ) ) {
V_6 = F_68 ( V_134 -> V_66 , struct V_5 , V_121 ) ;
F_82 ( & V_6 -> V_121 ) ;
V_2 -> V_171 -- ;
F_18 ( V_2 , V_6 -> V_26 , V_44 ) ;
}
F_83 ( V_2 , ! V_2 -> V_171 ) ;
}
