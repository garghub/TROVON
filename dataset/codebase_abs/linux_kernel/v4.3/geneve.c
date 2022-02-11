static inline T_1 F_1 ( T_2 V_1 [ 3 ] )
{
T_1 V_2 ;
V_2 = ( V_1 [ 0 ] << 16 ) | ( V_1 [ 1 ] << 8 ) | V_1 [ 2 ] ;
return F_2 ( V_2 , V_3 ) ;
}
static T_3 F_3 ( const T_4 * V_1 )
{
#ifdef F_4
return ( V_1 [ 0 ] << 16 ) | ( V_1 [ 1 ] << 8 ) | V_1 [ 2 ] ;
#else
return ( V_4 T_3 ) ( ( ( V_4 V_5 ) V_1 [ 0 ] << 40 ) |
( ( V_4 V_5 ) V_1 [ 1 ] << 48 ) |
( ( V_4 V_5 ) V_1 [ 2 ] << 56 ) ) ;
#endif
}
static struct V_6 * F_5 ( struct V_7 * V_8 ,
T_5 V_9 , T_2 V_1 [] )
{
struct V_10 * V_11 ;
struct V_6 * V_12 ;
T_1 V_13 ;
V_13 = F_1 ( V_1 ) ;
V_11 = & V_8 -> V_14 [ V_13 ] ;
F_6 (geneve, vni_list_head, hlist) {
if ( ! memcmp ( V_1 , V_12 -> V_1 , sizeof( V_12 -> V_1 ) ) &&
V_9 == V_12 -> V_15 . V_16 . V_17 )
return V_12 ;
}
return NULL ;
}
static inline struct V_18 * F_7 ( const struct V_19 * V_20 )
{
return (struct V_18 * ) ( F_8 ( V_20 ) + 1 ) ;
}
static void F_9 ( struct V_7 * V_8 , struct V_19 * V_20 )
{
struct V_18 * V_21 = F_7 ( V_20 ) ;
struct V_22 * V_23 = NULL ;
struct V_6 * V_12 = NULL ;
struct V_24 * V_25 ;
struct V_26 * V_27 ;
T_2 * V_1 ;
T_5 V_9 ;
int V_28 ;
V_27 = F_10 ( V_20 ) ;
if ( V_8 -> V_29 ) {
static T_2 V_30 [ 3 ] ;
V_1 = V_30 ;
V_9 = 0 ;
} else {
V_1 = V_21 -> V_1 ;
V_9 = V_27 -> V_31 ;
}
V_12 = F_5 ( V_8 , V_9 , V_1 ) ;
if ( ! V_12 )
goto V_32;
if ( F_11 () || V_8 -> V_29 ) {
T_6 V_33 ;
V_33 = V_34 | V_35 |
( V_21 -> V_36 ? V_37 : 0 ) |
( V_21 -> V_38 ? V_39 : 0 ) ;
V_23 = F_12 ( V_20 , V_40 , V_33 ,
F_3 ( V_21 -> V_1 ) ,
V_21 -> V_41 * 4 ) ;
if ( ! V_23 )
goto V_32;
F_13 ( & V_23 -> V_42 . V_43 ,
V_21 -> V_44 , V_21 -> V_41 * 4 ) ;
} else {
if ( V_21 -> V_38 )
goto V_32;
}
F_14 ( V_20 ) ;
F_15 ( V_20 , ! F_16 ( V_12 -> V_45 , F_17 ( V_12 -> V_46 ) ) ) ;
V_20 -> V_47 = F_18 ( V_20 , V_12 -> V_46 ) ;
F_19 ( V_20 , F_20 ( V_20 ) , V_48 ) ;
if ( V_23 )
F_21 ( V_20 , & V_23 -> V_49 ) ;
if ( F_22 ( F_20 ( V_20 ) -> V_50 , V_12 -> V_46 -> V_51 ) )
goto V_32;
F_23 ( V_20 ) ;
V_28 = F_24 ( V_27 , V_20 ) ;
if ( F_25 ( V_28 ) ) {
if ( V_52 )
F_26 ( L_1 ,
& V_27 -> V_31 , V_27 -> V_53 ) ;
if ( V_28 > 1 ) {
++ V_12 -> V_46 -> V_25 . V_54 ;
++ V_12 -> V_46 -> V_25 . V_55 ;
goto V_32;
}
}
V_25 = F_27 ( V_12 -> V_46 -> V_56 ) ;
F_28 ( & V_25 -> V_57 ) ;
V_25 -> V_58 ++ ;
V_25 -> V_59 += V_20 -> V_60 ;
F_29 ( & V_25 -> V_57 ) ;
F_30 ( & V_12 -> V_61 , V_20 ) ;
return;
V_32:
F_31 ( V_20 ) ;
}
static int F_32 ( struct V_62 * V_46 )
{
struct V_6 * V_12 = F_33 ( V_46 ) ;
int V_28 ;
V_46 -> V_56 = F_34 ( struct V_24 ) ;
if ( ! V_46 -> V_56 )
return - V_63 ;
V_28 = F_35 ( & V_12 -> V_61 , V_46 ) ;
if ( V_28 ) {
F_36 ( V_46 -> V_56 ) ;
return V_28 ;
}
return 0 ;
}
static void F_37 ( struct V_62 * V_46 )
{
struct V_6 * V_12 = F_33 ( V_46 ) ;
F_38 ( & V_12 -> V_61 ) ;
F_36 ( V_46 -> V_56 ) ;
}
static int F_39 ( struct V_64 * V_65 , struct V_19 * V_20 )
{
struct V_18 * V_66 ;
struct V_7 * V_8 ;
int V_67 ;
if ( F_25 ( ! F_40 ( V_20 , V_68 ) ) )
goto error;
V_66 = F_7 ( V_20 ) ;
if ( F_25 ( V_66 -> V_69 != V_70 ) )
goto error;
if ( F_25 ( V_66 -> V_71 != F_41 ( V_72 ) ) )
goto error;
V_67 = V_66 -> V_41 * 4 ;
if ( F_42 ( V_20 , V_68 + V_67 ,
F_41 ( V_72 ) ) )
goto V_32;
V_8 = F_43 ( V_65 ) ;
if ( ! V_8 )
goto V_32;
F_9 ( V_8 , V_20 ) ;
return 0 ;
V_32:
F_31 ( V_20 ) ;
return 0 ;
error:
return 1 ;
}
static struct V_73 * F_44 ( struct V_45 * V_45 , bool V_74 ,
T_6 V_75 )
{
struct V_73 * V_64 ;
struct V_76 V_77 ;
int V_28 ;
memset ( & V_77 , 0 , sizeof( V_77 ) ) ;
if ( V_74 ) {
V_77 . V_78 = V_79 ;
} else {
V_77 . V_78 = V_40 ;
V_77 . V_80 . V_17 = F_45 ( V_81 ) ;
}
V_77 . V_82 = V_75 ;
V_28 = F_46 ( V_45 , & V_77 , & V_64 ) ;
if ( V_28 < 0 )
return F_47 ( V_28 ) ;
return V_64 ;
}
static void F_48 ( struct V_7 * V_8 )
{
struct V_64 * V_65 = V_8 -> V_64 -> V_65 ;
T_7 V_83 = V_65 -> V_84 ;
int V_28 ;
if ( V_83 == V_40 ) {
V_28 = F_49 ( & V_8 -> V_85 ) ;
if ( V_28 )
F_50 ( L_2 ,
V_28 ) ;
}
}
static int F_51 ( struct V_18 * V_86 )
{
return sizeof( * V_86 ) + V_86 -> V_41 * 4 ;
}
static struct V_19 * * F_52 ( struct V_19 * * V_87 ,
struct V_19 * V_20 ,
struct V_88 * V_89 )
{
struct V_19 * V_90 , * * V_91 = NULL ;
struct V_18 * V_86 , * V_92 ;
unsigned int V_93 , V_94 , V_95 ;
const struct V_96 * V_97 ;
T_6 type ;
int V_98 = 1 ;
V_95 = F_53 ( V_20 ) ;
V_93 = V_95 + sizeof( * V_86 ) ;
V_86 = F_54 ( V_20 , V_95 ) ;
if ( F_55 ( V_20 , V_93 ) ) {
V_86 = F_56 ( V_20 , V_93 , V_95 ) ;
if ( F_25 ( ! V_86 ) )
goto V_99;
}
if ( V_86 -> V_69 != V_70 || V_86 -> V_36 )
goto V_99;
V_94 = F_51 ( V_86 ) ;
V_93 = V_95 + V_94 ;
if ( F_55 ( V_20 , V_93 ) ) {
V_86 = F_56 ( V_20 , V_93 , V_95 ) ;
if ( F_25 ( ! V_86 ) )
goto V_99;
}
V_98 = 0 ;
for ( V_90 = * V_87 ; V_90 ; V_90 = V_90 -> V_100 ) {
if ( ! F_57 ( V_90 ) -> V_101 )
continue;
V_92 = (struct V_18 * ) ( V_90 -> V_102 + V_95 ) ;
if ( V_86 -> V_41 != V_92 -> V_41 ||
memcmp ( V_86 , V_92 , V_94 ) ) {
F_57 ( V_90 ) -> V_101 = 0 ;
continue;
}
}
type = V_86 -> V_71 ;
F_58 () ;
V_97 = F_59 ( type ) ;
if ( ! V_97 ) {
V_98 = 1 ;
goto V_103;
}
F_60 ( V_20 , V_94 ) ;
F_61 ( V_20 , V_86 , V_94 ) ;
V_91 = V_97 -> V_104 . V_105 ( V_87 , V_20 ) ;
V_103:
F_62 () ;
V_99:
F_57 ( V_20 ) -> V_98 |= V_98 ;
return V_91 ;
}
static int F_63 ( struct V_19 * V_20 , int V_106 ,
struct V_88 * V_89 )
{
struct V_18 * V_86 ;
struct V_96 * V_97 ;
T_6 type ;
int V_94 ;
int V_28 = - V_107 ;
F_64 ( V_20 , V_106 ) ;
V_86 = (struct V_18 * ) ( V_20 -> V_102 + V_106 ) ;
V_94 = F_51 ( V_86 ) ;
type = V_86 -> V_71 ;
F_58 () ;
V_97 = F_65 ( type ) ;
if ( V_97 )
V_28 = V_97 -> V_104 . V_108 ( V_20 , V_106 + V_94 ) ;
F_62 () ;
return V_28 ;
}
static struct V_7 * F_66 ( struct V_45 * V_45 , T_6 V_75 ,
bool V_74 )
{
struct V_109 * V_110 = F_67 ( V_45 , V_111 ) ;
struct V_7 * V_8 ;
struct V_73 * V_64 ;
struct V_112 V_113 ;
int V_114 ;
V_8 = F_68 ( sizeof( * V_8 ) , V_115 ) ;
if ( ! V_8 )
return F_47 ( - V_63 ) ;
V_64 = F_44 ( V_45 , V_74 , V_75 ) ;
if ( F_69 ( V_64 ) ) {
F_70 ( V_8 ) ;
return F_71 ( V_64 ) ;
}
V_8 -> V_64 = V_64 ;
V_8 -> V_116 = 1 ;
for ( V_114 = 0 ; V_114 < V_117 ; ++ V_114 )
F_72 ( & V_8 -> V_14 [ V_114 ] ) ;
V_8 -> V_85 . V_75 = V_75 ;
V_8 -> V_85 . V_104 . V_105 = F_52 ;
V_8 -> V_85 . V_104 . V_108 = F_63 ;
F_48 ( V_8 ) ;
V_113 . V_118 = V_8 ;
V_113 . V_119 = 1 ;
V_113 . V_120 = F_39 ;
V_113 . V_121 = NULL ;
F_73 ( V_45 , V_64 , & V_113 ) ;
F_74 ( & V_8 -> V_122 , & V_110 -> V_123 ) ;
return V_8 ;
}
static void F_75 ( struct V_7 * V_8 )
{
struct V_64 * V_65 = V_8 -> V_64 -> V_65 ;
T_7 V_83 = V_65 -> V_84 ;
if ( V_83 == V_40 )
F_76 ( & V_8 -> V_85 ) ;
}
static void F_77 ( struct V_7 * V_8 )
{
if ( -- V_8 -> V_116 )
return;
F_78 ( & V_8 -> V_122 ) ;
F_75 ( V_8 ) ;
F_79 ( V_8 -> V_64 ) ;
F_80 ( V_8 , V_124 ) ;
}
static struct V_7 * F_81 ( struct V_109 * V_110 ,
T_6 V_125 )
{
struct V_7 * V_8 ;
F_82 (gs, &gn->sock_list, list) {
if ( F_83 ( V_8 -> V_64 -> V_65 ) -> V_126 == V_125 &&
F_83 ( V_8 -> V_64 -> V_65 ) -> V_65 . V_84 == V_40 ) {
return V_8 ;
}
}
return NULL ;
}
static int F_84 ( struct V_62 * V_46 )
{
struct V_6 * V_12 = F_33 ( V_46 ) ;
struct V_45 * V_45 = V_12 -> V_45 ;
struct V_109 * V_110 = F_67 ( V_45 , V_111 ) ;
struct V_7 * V_8 ;
T_1 V_13 ;
V_8 = F_81 ( V_110 , V_12 -> V_125 ) ;
if ( V_8 ) {
V_8 -> V_116 ++ ;
goto V_99;
}
V_8 = F_66 ( V_45 , V_12 -> V_125 , false ) ;
if ( F_69 ( V_8 ) )
return F_85 ( V_8 ) ;
V_99:
V_8 -> V_29 = V_12 -> V_29 ;
V_12 -> V_64 = V_8 ;
V_13 = F_1 ( V_12 -> V_1 ) ;
F_86 ( & V_12 -> V_127 , & V_8 -> V_14 [ V_13 ] ) ;
return 0 ;
}
static int F_87 ( struct V_62 * V_46 )
{
struct V_6 * V_12 = F_33 ( V_46 ) ;
struct V_7 * V_8 = V_12 -> V_64 ;
if ( ! F_88 ( & V_12 -> V_127 ) )
F_89 ( & V_12 -> V_127 ) ;
F_77 ( V_8 ) ;
return 0 ;
}
static int F_90 ( struct V_128 * V_129 , struct V_19 * V_20 ,
T_6 V_130 , T_2 V_1 [ 3 ] , T_2 V_41 , T_2 * V_131 ,
bool V_132 )
{
struct V_18 * V_21 ;
int V_133 ;
int V_28 ;
V_133 = F_91 ( V_129 -> V_49 . V_46 ) + V_129 -> V_49 . V_134
+ V_68 + V_41 + sizeof( struct V_26 ) ;
V_28 = F_92 ( V_20 , V_133 ) ;
if ( F_25 ( V_28 ) ) {
F_31 ( V_20 ) ;
goto V_135;
}
V_20 = F_93 ( V_20 , V_132 ) ;
if ( F_69 ( V_20 ) ) {
V_28 = F_85 ( V_20 ) ;
goto V_135;
}
V_21 = (struct V_18 * ) F_94 ( V_20 , sizeof( * V_21 ) + V_41 ) ;
V_21 -> V_69 = V_70 ;
V_21 -> V_41 = V_41 / 4 ;
V_21 -> V_36 = ! ! ( V_130 & V_37 ) ;
V_21 -> V_38 = ! ! ( V_130 & V_39 ) ;
V_21 -> V_136 = 0 ;
memcpy ( V_21 -> V_1 , V_1 , 3 ) ;
V_21 -> V_71 = F_41 ( V_72 ) ;
V_21 -> V_137 = 0 ;
memcpy ( V_21 -> V_44 , V_131 , V_41 ) ;
F_95 ( V_20 , F_41 ( V_72 ) ) ;
return 0 ;
V_135:
F_96 ( V_129 ) ;
return V_28 ;
}
static struct V_128 * F_97 ( struct V_19 * V_20 ,
struct V_62 * V_46 ,
struct V_138 * V_139 ,
struct V_140 * V_141 )
{
struct V_6 * V_12 = F_33 ( V_46 ) ;
struct V_128 * V_129 = NULL ;
T_4 V_53 ;
memset ( V_139 , 0 , sizeof( * V_139 ) ) ;
V_139 -> V_142 = V_20 -> V_143 ;
V_139 -> V_144 = V_145 ;
if ( V_141 ) {
V_139 -> V_146 = V_141 -> V_147 . V_42 . V_148 . V_49 ;
V_139 -> V_31 = V_141 -> V_147 . V_42 . V_148 . V_149 ;
V_139 -> V_150 = F_98 ( V_141 -> V_147 . V_53 ) ;
} else {
V_53 = V_12 -> V_53 ;
if ( V_53 == 1 ) {
const struct V_26 * V_151 = F_10 ( V_20 ) ;
V_53 = F_99 ( V_151 , V_20 ) ;
}
V_139 -> V_150 = F_98 ( V_53 ) ;
V_139 -> V_146 = V_12 -> V_15 . V_16 . V_17 ;
}
V_129 = F_100 ( V_12 -> V_45 , V_139 ) ;
if ( F_69 ( V_129 ) ) {
F_101 ( V_46 , L_3 , & V_139 -> V_146 ) ;
return F_47 ( - V_152 ) ;
}
if ( V_129 -> V_49 . V_46 == V_46 ) {
F_101 ( V_46 , L_4 , & V_139 -> V_146 ) ;
F_96 ( V_129 ) ;
return F_47 ( - V_153 ) ;
}
return V_129 ;
}
static void F_102 ( T_3 V_154 , T_4 * V_1 )
{
#ifdef F_4
V_1 [ 0 ] = ( V_4 T_4 ) ( V_154 >> 16 ) ;
V_1 [ 1 ] = ( V_4 T_4 ) ( V_154 >> 8 ) ;
V_1 [ 2 ] = ( V_4 T_4 ) V_154 ;
#else
V_1 [ 0 ] = ( V_4 T_4 ) ( ( V_4 V_5 ) V_154 >> 40 ) ;
V_1 [ 1 ] = ( V_4 T_4 ) ( ( V_4 V_5 ) V_154 >> 48 ) ;
V_1 [ 2 ] = ( V_4 T_4 ) ( ( V_4 V_5 ) V_154 >> 56 ) ;
#endif
}
static T_8 F_103 ( struct V_19 * V_20 , struct V_62 * V_46 )
{
struct V_6 * V_12 = F_33 ( V_46 ) ;
struct V_7 * V_8 = V_12 -> V_64 ;
struct V_140 * V_141 = NULL ;
struct V_128 * V_129 = NULL ;
const struct V_26 * V_151 ;
int V_28 = - V_155 ;
struct V_138 V_139 ;
T_4 V_53 , V_156 ;
T_6 V_157 ;
bool V_158 ;
T_6 V_159 ;
if ( V_12 -> V_29 ) {
V_141 = F_104 ( V_20 ) ;
if ( F_25 ( V_141 && ! ( V_141 -> V_160 & V_161 ) ) ) {
F_101 ( V_46 , L_5 ) ;
goto V_162;
}
if ( V_141 && F_105 ( V_141 ) != V_40 )
goto V_162;
}
V_129 = F_97 ( V_20 , V_46 , & V_139 , V_141 ) ;
if ( F_69 ( V_129 ) ) {
F_101 ( V_46 , L_3 , & V_139 . V_146 ) ;
V_28 = F_85 ( V_129 ) ;
goto V_162;
}
V_157 = F_106 ( V_12 -> V_45 , V_20 , 1 , V_163 , true ) ;
F_14 ( V_20 ) ;
V_151 = F_10 ( V_20 ) ;
if ( V_141 ) {
const struct V_164 * V_147 = & V_141 -> V_147 ;
T_2 * V_165 = NULL ;
T_2 V_1 [ 3 ] ;
F_102 ( V_147 -> V_154 , V_1 ) ;
if ( V_147 -> V_130 & V_35 )
V_165 = F_107 ( V_141 ) ;
V_158 = ! ! ( V_147 -> V_130 & V_166 ) ;
V_28 = F_90 ( V_129 , V_20 , V_147 -> V_130 , V_1 ,
V_141 -> V_167 , V_165 , V_158 ) ;
if ( F_25 ( V_28 ) )
goto V_28;
V_53 = F_108 ( V_147 -> V_53 , V_151 , V_20 ) ;
V_156 = V_147 -> V_156 ;
V_159 = V_147 -> V_130 & V_168 ? F_41 ( V_169 ) : 0 ;
} else {
V_158 = false ;
V_28 = F_90 ( V_129 , V_20 , 0 , V_12 -> V_1 ,
0 , NULL , V_158 ) ;
if ( F_25 ( V_28 ) )
goto V_28;
V_53 = F_108 ( V_139 . V_150 , V_151 , V_20 ) ;
V_156 = V_12 -> V_156 ;
if ( ! V_156 && F_109 ( F_110 ( V_139 . V_146 ) ) )
V_156 = 1 ;
V_156 = V_156 ? : F_111 ( & V_129 -> V_49 ) ;
V_159 = 0 ;
}
V_28 = F_112 ( V_129 , V_8 -> V_64 -> V_65 , V_20 , V_139 . V_31 , V_139 . V_146 ,
V_53 , V_156 , V_159 , V_157 , V_12 -> V_125 ,
! F_16 ( V_12 -> V_45 , F_17 ( V_12 -> V_46 ) ) ,
! V_158 ) ;
F_113 ( V_28 , & V_46 -> V_25 , V_46 -> V_56 ) ;
return V_170 ;
V_162:
F_114 ( V_20 ) ;
V_28:
if ( V_28 == - V_153 )
V_46 -> V_25 . V_171 ++ ;
else if ( V_28 == - V_152 )
V_46 -> V_25 . V_172 ++ ;
else
V_46 -> V_25 . V_173 ++ ;
return V_170 ;
}
static int F_115 ( struct V_62 * V_46 , struct V_19 * V_20 )
{
struct V_140 * V_141 = F_104 ( V_20 ) ;
struct V_6 * V_12 = F_33 ( V_46 ) ;
struct V_128 * V_129 ;
struct V_138 V_139 ;
if ( F_105 ( V_141 ) != V_40 )
return - V_155 ;
V_129 = F_97 ( V_20 , V_46 , & V_139 , V_141 ) ;
if ( F_69 ( V_129 ) )
return F_85 ( V_129 ) ;
F_96 ( V_129 ) ;
V_141 -> V_147 . V_42 . V_148 . V_149 = V_139 . V_31 ;
V_141 -> V_147 . V_174 = F_106 ( V_12 -> V_45 , V_20 ,
1 , V_163 , true ) ;
V_141 -> V_147 . V_175 = V_12 -> V_125 ;
return 0 ;
}
static void F_116 ( struct V_62 * V_46 ,
struct V_176 * V_177 )
{
F_117 ( V_177 -> V_178 , V_179 , sizeof( V_177 -> V_178 ) ) ;
F_117 ( V_177 -> V_180 , L_6 , sizeof( V_177 -> V_180 ) ) ;
}
static void F_118 ( struct V_62 * V_46 )
{
F_119 ( V_46 ) ;
V_46 -> V_181 = & V_182 ;
V_46 -> V_183 = & V_184 ;
V_46 -> V_185 = V_186 ;
F_120 ( V_46 , & V_187 ) ;
V_46 -> V_188 |= V_189 ;
V_46 -> V_188 |= V_190 | V_191 ;
V_46 -> V_188 |= V_192 ;
V_46 -> V_188 |= V_193 ;
V_46 -> V_194 |= V_190 | V_191 | V_192 ;
V_46 -> V_194 |= V_193 ;
F_121 ( V_46 ) ;
V_46 -> V_195 |= V_196 | V_197 ;
F_122 ( V_46 ) ;
}
static int F_123 ( struct V_198 * V_199 [] , struct V_198 * V_102 [] )
{
if ( V_199 [ V_200 ] ) {
if ( F_124 ( V_199 [ V_200 ] ) != V_201 )
return - V_155 ;
if ( ! F_125 ( F_126 ( V_199 [ V_200 ] ) ) )
return - V_202 ;
}
if ( ! V_102 )
return - V_155 ;
if ( V_102 [ V_203 ] ) {
T_1 V_1 = F_127 ( V_102 [ V_203 ] ) ;
if ( V_1 >= V_204 )
return - V_205 ;
}
return 0 ;
}
static struct V_6 * F_128 ( struct V_109 * V_110 ,
T_6 V_125 ,
T_5 V_206 ,
T_2 V_1 [] ,
bool * V_207 ,
bool * V_208 )
{
struct V_6 * V_12 , * V_209 ;
* V_207 = false ;
* V_208 = false ;
V_209 = NULL ;
F_82 (geneve, &gn->geneve_list, next) {
if ( V_12 -> V_125 == V_125 ) {
* V_208 = V_12 -> V_29 ;
* V_207 = true ;
}
if ( ! memcmp ( V_1 , V_12 -> V_1 , sizeof( V_12 -> V_1 ) ) &&
V_206 == V_12 -> V_15 . V_16 . V_17 &&
V_125 == V_12 -> V_125 )
V_209 = V_12 ;
}
return V_209 ;
}
static int F_129 ( struct V_45 * V_45 , struct V_62 * V_46 ,
T_5 V_206 , T_1 V_1 , T_4 V_156 , T_4 V_53 ,
T_6 V_125 , bool V_210 )
{
struct V_109 * V_110 = F_67 ( V_45 , V_111 ) ;
struct V_6 * V_209 , * V_12 = F_33 ( V_46 ) ;
bool V_208 , V_207 ;
int V_28 ;
if ( V_210 ) {
if ( V_206 || V_1 || V_53 || V_156 )
return - V_155 ;
}
V_12 -> V_45 = V_45 ;
V_12 -> V_46 = V_46 ;
V_12 -> V_1 [ 0 ] = ( V_1 & 0x00ff0000 ) >> 16 ;
V_12 -> V_1 [ 1 ] = ( V_1 & 0x0000ff00 ) >> 8 ;
V_12 -> V_1 [ 2 ] = V_1 & 0x000000ff ;
V_12 -> V_15 . V_16 . V_17 = V_206 ;
if ( F_109 ( F_110 ( V_12 -> V_15 . V_16 . V_17 ) ) )
return - V_155 ;
V_12 -> V_156 = V_156 ;
V_12 -> V_53 = V_53 ;
V_12 -> V_125 = V_125 ;
V_12 -> V_29 = V_210 ;
V_209 = F_128 ( V_110 , V_125 , V_206 , V_12 -> V_1 ,
& V_207 , & V_208 ) ;
if ( V_209 )
return - V_211 ;
if ( V_210 ) {
if ( V_207 )
return - V_212 ;
} else {
if ( V_208 )
return - V_212 ;
}
V_28 = F_130 ( V_46 ) ;
if ( V_28 )
return V_28 ;
F_74 ( & V_12 -> V_100 , & V_110 -> V_213 ) ;
return 0 ;
}
static int F_131 ( struct V_45 * V_45 , struct V_62 * V_46 ,
struct V_198 * V_199 [] , struct V_198 * V_102 [] )
{
T_6 V_125 = F_41 ( V_214 ) ;
T_4 V_156 = 0 , V_53 = 0 ;
bool V_210 = false ;
T_5 V_206 = 0 ;
T_1 V_1 = 0 ;
if ( V_102 [ V_203 ] )
V_1 = F_127 ( V_102 [ V_203 ] ) ;
if ( V_102 [ V_215 ] )
V_206 = F_132 ( V_102 [ V_215 ] ) ;
if ( V_102 [ V_216 ] )
V_156 = F_133 ( V_102 [ V_216 ] ) ;
if ( V_102 [ V_217 ] )
V_53 = F_133 ( V_102 [ V_217 ] ) ;
if ( V_102 [ V_218 ] )
V_125 = F_134 ( V_102 [ V_218 ] ) ;
if ( V_102 [ V_219 ] )
V_210 = true ;
return F_129 ( V_45 , V_46 , V_206 , V_1 ,
V_156 , V_53 , V_125 , V_210 ) ;
}
static void F_135 ( struct V_62 * V_46 , struct V_220 * V_87 )
{
struct V_6 * V_12 = F_33 ( V_46 ) ;
F_78 ( & V_12 -> V_100 ) ;
F_136 ( V_46 , V_87 ) ;
}
static T_9 F_137 ( const struct V_62 * V_46 )
{
return F_138 ( sizeof( T_1 ) ) +
F_138 ( sizeof( struct V_221 ) ) +
F_138 ( sizeof( T_4 ) ) +
F_138 ( sizeof( T_4 ) ) +
F_138 ( sizeof( T_6 ) ) +
F_138 ( 0 ) +
0 ;
}
static int F_139 ( struct V_19 * V_20 , const struct V_62 * V_46 )
{
struct V_6 * V_12 = F_33 ( V_46 ) ;
T_1 V_1 ;
V_1 = ( V_12 -> V_1 [ 0 ] << 16 ) | ( V_12 -> V_1 [ 1 ] << 8 ) | V_12 -> V_1 [ 2 ] ;
if ( F_140 ( V_20 , V_203 , V_1 ) )
goto V_222;
if ( F_141 ( V_20 , V_215 ,
V_12 -> V_15 . V_16 . V_17 ) )
goto V_222;
if ( F_142 ( V_20 , V_216 , V_12 -> V_156 ) ||
F_142 ( V_20 , V_217 , V_12 -> V_53 ) )
goto V_222;
if ( F_143 ( V_20 , V_218 , V_12 -> V_125 ) )
goto V_222;
if ( V_12 -> V_29 ) {
if ( F_144 ( V_20 , V_219 ) )
goto V_222;
}
return 0 ;
V_222:
return - V_223 ;
}
struct V_62 * F_145 ( struct V_45 * V_45 , const char * V_224 ,
T_2 V_225 , T_10 V_125 )
{
struct V_198 * V_199 [ V_226 + 1 ] ;
struct V_62 * V_46 ;
int V_28 ;
memset ( V_199 , 0 , sizeof( V_199 ) ) ;
V_46 = F_146 ( V_45 , V_224 , V_225 ,
& V_227 , V_199 ) ;
if ( F_69 ( V_46 ) )
return V_46 ;
V_28 = F_129 ( V_45 , V_46 , 0 , 0 , 0 , 0 , F_41 ( V_125 ) , true ) ;
if ( V_28 ) {
V_186 ( V_46 ) ;
return F_47 ( V_28 ) ;
}
return V_46 ;
}
static T_11 int F_147 ( struct V_45 * V_45 )
{
struct V_109 * V_110 = F_67 ( V_45 , V_111 ) ;
F_148 ( & V_110 -> V_213 ) ;
F_148 ( & V_110 -> V_123 ) ;
return 0 ;
}
static void T_12 F_149 ( struct V_45 * V_45 )
{
struct V_109 * V_110 = F_67 ( V_45 , V_111 ) ;
struct V_6 * V_12 , * V_100 ;
struct V_62 * V_46 , * V_228 ;
F_150 ( V_122 ) ;
F_151 () ;
F_152 (net, dev, aux)
if ( V_46 -> V_229 == & V_227 )
F_136 ( V_46 , & V_122 ) ;
F_153 (geneve, next, &gn->geneve_list, next) {
if ( ! F_16 ( F_17 ( V_12 -> V_46 ) , V_45 ) )
F_136 ( V_12 -> V_46 , & V_122 ) ;
}
F_154 ( & V_122 ) ;
F_155 () ;
}
static int T_13 F_156 ( void )
{
int V_230 ;
V_230 = F_157 ( & V_231 ) ;
if ( V_230 )
goto V_232;
V_230 = F_158 ( & V_227 ) ;
if ( V_230 )
goto V_233;
return 0 ;
V_233:
F_159 ( & V_231 ) ;
V_232:
return V_230 ;
}
static void T_14 F_160 ( void )
{
F_161 ( & V_227 ) ;
F_159 ( & V_231 ) ;
}
