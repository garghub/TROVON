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
static void F_5 ( T_3 V_6 , T_4 * V_1 )
{
#ifdef F_4
V_1 [ 0 ] = ( V_4 T_4 ) ( V_6 >> 16 ) ;
V_1 [ 1 ] = ( V_4 T_4 ) ( V_6 >> 8 ) ;
V_1 [ 2 ] = ( V_4 T_4 ) V_6 ;
#else
V_1 [ 0 ] = ( V_4 T_4 ) ( ( V_4 V_5 ) V_6 >> 40 ) ;
V_1 [ 1 ] = ( V_4 T_4 ) ( ( V_4 V_5 ) V_6 >> 48 ) ;
V_1 [ 2 ] = ( V_4 T_4 ) ( ( V_4 V_5 ) V_6 >> 56 ) ;
#endif
}
static bool F_6 ( T_2 * V_6 , T_2 * V_1 )
{
return ! memcmp ( V_1 , & V_6 [ 5 ] , 3 ) ;
}
static T_5 F_7 ( struct V_7 * V_8 )
{
return V_8 -> V_9 -> V_10 -> V_11 ;
}
static struct V_12 * F_8 ( struct V_7 * V_8 ,
T_6 V_13 , T_2 V_1 [] )
{
struct V_14 * V_15 ;
struct V_16 * V_17 ;
T_1 V_18 ;
V_18 = F_1 ( V_1 ) ;
V_15 = & V_8 -> V_19 [ V_18 ] ;
F_9 (node, vni_list_head, hlist) {
if ( F_6 ( ( T_2 * ) & V_17 -> V_20 -> V_21 . V_22 . V_6 , V_1 ) &&
V_13 == V_17 -> V_20 -> V_21 . V_22 . V_23 . V_24 . V_25 )
return V_17 -> V_20 ;
}
return NULL ;
}
static struct V_12 * F_10 ( struct V_7 * V_8 ,
struct V_26 V_27 , T_2 V_1 [] )
{
struct V_14 * V_15 ;
struct V_16 * V_17 ;
T_1 V_18 ;
V_18 = F_1 ( V_1 ) ;
V_15 = & V_8 -> V_19 [ V_18 ] ;
F_9 (node, vni_list_head, hlist) {
if ( F_6 ( ( T_2 * ) & V_17 -> V_20 -> V_21 . V_22 . V_6 , V_1 ) &&
F_11 ( & V_27 , & V_17 -> V_20 -> V_21 . V_22 . V_23 . V_28 . V_25 ) )
return V_17 -> V_20 ;
}
return NULL ;
}
static inline struct V_29 * F_12 ( const struct V_30 * V_31 )
{
return (struct V_29 * ) ( F_13 ( V_31 ) + 1 ) ;
}
static struct V_12 * F_14 ( struct V_7 * V_8 ,
struct V_30 * V_31 )
{
static T_2 V_32 [ 3 ] ;
T_2 * V_1 ;
if ( F_7 ( V_8 ) == V_33 ) {
struct V_34 * V_35 ;
T_6 V_13 ;
V_35 = F_15 ( V_31 ) ;
if ( V_8 -> V_36 ) {
V_1 = V_32 ;
V_13 = 0 ;
} else {
V_1 = F_12 ( V_31 ) -> V_1 ;
V_13 = V_35 -> V_37 ;
}
return F_8 ( V_8 , V_13 , V_1 ) ;
#if F_16 ( V_38 )
} else if ( F_7 ( V_8 ) == V_39 ) {
static struct V_26 V_40 ;
struct V_41 * V_42 ;
struct V_26 V_27 ;
V_42 = F_17 ( V_31 ) ;
if ( V_8 -> V_36 ) {
V_1 = V_32 ;
V_27 = V_40 ;
} else {
V_1 = F_12 ( V_31 ) -> V_1 ;
V_27 = V_42 -> V_37 ;
}
return F_10 ( V_8 , V_27 , V_1 ) ;
#endif
}
return NULL ;
}
static void F_18 ( struct V_12 * V_20 , struct V_7 * V_8 ,
struct V_30 * V_31 )
{
struct V_29 * V_43 = F_12 ( V_31 ) ;
struct V_44 * V_45 = NULL ;
struct V_46 * V_47 ;
unsigned int V_48 ;
int V_49 = 0 ;
void * V_50 ;
if ( F_19 () || V_8 -> V_36 ) {
T_7 V_51 ;
V_51 = V_52 | V_53 |
( V_43 -> V_54 ? V_55 : 0 ) |
( V_43 -> V_56 ? V_57 : 0 ) ;
V_45 = F_20 ( V_31 , F_7 ( V_8 ) , V_51 ,
F_3 ( V_43 -> V_1 ) ,
V_43 -> V_58 * 4 ) ;
if ( ! V_45 ) {
V_20 -> V_59 -> V_47 . V_60 ++ ;
goto V_61;
}
F_21 ( & V_45 -> V_23 . V_62 ,
V_43 -> V_63 , V_43 -> V_58 * 4 ) ;
} else {
if ( V_43 -> V_56 ) {
V_20 -> V_59 -> V_47 . V_64 ++ ;
V_20 -> V_59 -> V_47 . V_65 ++ ;
goto V_61;
}
}
F_22 ( V_31 ) ;
V_31 -> V_66 = F_23 ( V_31 , V_20 -> V_59 ) ;
F_24 ( V_31 , F_25 ( V_31 ) , V_67 ) ;
if ( V_45 )
F_26 ( V_31 , & V_45 -> V_25 ) ;
if ( F_27 ( F_25 ( V_31 ) -> V_68 , V_20 -> V_59 -> V_69 ) ) {
V_20 -> V_59 -> V_47 . V_65 ++ ;
goto V_61;
}
V_50 = F_28 ( V_31 ) ;
F_29 ( V_31 ) ;
if ( F_7 ( V_8 ) == V_33 )
V_49 = F_30 ( V_50 , V_31 ) ;
#if F_16 ( V_38 )
else
V_49 = F_31 ( V_50 , V_31 ) ;
#endif
if ( F_32 ( V_49 ) ) {
if ( V_70 ) {
if ( F_7 ( V_8 ) == V_33 )
F_33 ( L_1
L_2 ,
& ( (struct V_34 * ) V_50 ) -> V_37 ,
( (struct V_34 * ) V_50 ) -> V_71 ) ;
#if F_16 ( V_38 )
else
F_33 ( L_3 ,
& ( (struct V_41 * ) V_50 ) -> V_37 ) ;
#endif
}
if ( V_49 > 1 ) {
++ V_20 -> V_59 -> V_47 . V_64 ;
++ V_20 -> V_59 -> V_47 . V_65 ;
goto V_61;
}
}
V_48 = V_31 -> V_48 ;
V_49 = F_34 ( & V_20 -> V_72 , V_31 ) ;
if ( F_35 ( V_49 == V_73 ) ) {
V_47 = F_36 ( V_20 -> V_59 -> V_74 ) ;
F_37 ( & V_47 -> V_75 ) ;
V_47 -> V_76 ++ ;
V_47 -> V_77 += V_48 ;
F_38 ( & V_47 -> V_75 ) ;
}
return;
V_61:
F_39 ( V_31 ) ;
}
static int F_40 ( struct V_78 * V_59 )
{
struct V_12 * V_20 = F_41 ( V_59 ) ;
int V_49 ;
V_59 -> V_74 = F_42 ( struct V_46 ) ;
if ( ! V_59 -> V_74 )
return - V_79 ;
V_49 = F_43 ( & V_20 -> V_72 , V_59 ) ;
if ( V_49 ) {
F_44 ( V_59 -> V_74 ) ;
return V_49 ;
}
V_49 = F_45 ( & V_20 -> V_21 . V_80 , V_81 ) ;
if ( V_49 ) {
F_44 ( V_59 -> V_74 ) ;
F_46 ( & V_20 -> V_72 ) ;
return V_49 ;
}
return 0 ;
}
static void F_47 ( struct V_78 * V_59 )
{
struct V_12 * V_20 = F_41 ( V_59 ) ;
F_48 ( & V_20 -> V_21 . V_80 ) ;
F_46 ( & V_20 -> V_72 ) ;
F_44 ( V_59 -> V_74 ) ;
}
static int F_49 ( struct V_9 * V_10 , struct V_30 * V_31 )
{
struct V_29 * V_82 ;
struct V_12 * V_20 ;
struct V_7 * V_8 ;
int V_83 ;
if ( F_32 ( ! F_50 ( V_31 , V_84 ) ) )
goto V_61;
V_82 = F_12 ( V_31 ) ;
if ( F_32 ( V_82 -> V_85 != V_86 ) )
goto V_61;
if ( F_32 ( V_82 -> V_87 != F_51 ( V_88 ) ) )
goto V_61;
V_8 = F_52 ( V_10 ) ;
if ( ! V_8 )
goto V_61;
V_20 = F_14 ( V_8 , V_31 ) ;
if ( ! V_20 )
goto V_61;
V_83 = V_82 -> V_58 * 4 ;
if ( F_53 ( V_31 , V_84 + V_83 ,
F_51 ( V_88 ) ,
! F_54 ( V_20 -> V_89 , F_55 ( V_20 -> V_59 ) ) ) ) {
V_20 -> V_59 -> V_47 . V_60 ++ ;
goto V_61;
}
F_18 ( V_20 , V_8 , V_31 ) ;
return 0 ;
V_61:
F_39 ( V_31 ) ;
return 0 ;
}
static struct V_90 * F_56 ( struct V_89 * V_89 , bool V_28 ,
T_7 V_91 , bool V_92 )
{
struct V_90 * V_9 ;
struct V_93 V_94 ;
int V_49 ;
memset ( & V_94 , 0 , sizeof( V_94 ) ) ;
if ( V_28 ) {
V_94 . V_95 = V_39 ;
V_94 . V_96 = 1 ;
V_94 . V_97 = V_92 ;
} else {
V_94 . V_95 = V_33 ;
V_94 . V_98 . V_99 = F_57 ( V_100 ) ;
}
V_94 . V_101 = V_91 ;
V_49 = F_58 ( V_89 , & V_94 , & V_9 ) ;
if ( V_49 < 0 )
return F_59 ( V_49 ) ;
return V_9 ;
}
static int F_60 ( struct V_29 * V_102 )
{
return sizeof( * V_102 ) + V_102 -> V_58 * 4 ;
}
static struct V_30 * * F_61 ( struct V_9 * V_10 ,
struct V_30 * * V_103 ,
struct V_30 * V_31 )
{
struct V_30 * V_104 , * * V_105 = NULL ;
struct V_29 * V_102 , * V_106 ;
unsigned int V_107 , V_108 , V_109 ;
const struct V_110 * V_111 ;
T_7 type ;
int V_112 = 1 ;
V_109 = F_62 ( V_31 ) ;
V_107 = V_109 + sizeof( * V_102 ) ;
V_102 = F_63 ( V_31 , V_109 ) ;
if ( F_64 ( V_31 , V_107 ) ) {
V_102 = F_65 ( V_31 , V_107 , V_109 ) ;
if ( F_32 ( ! V_102 ) )
goto V_113;
}
if ( V_102 -> V_85 != V_86 || V_102 -> V_54 )
goto V_113;
V_108 = F_60 ( V_102 ) ;
V_107 = V_109 + V_108 ;
if ( F_64 ( V_31 , V_107 ) ) {
V_102 = F_65 ( V_31 , V_107 , V_109 ) ;
if ( F_32 ( ! V_102 ) )
goto V_113;
}
for ( V_104 = * V_103 ; V_104 ; V_104 = V_104 -> V_114 ) {
if ( ! F_66 ( V_104 ) -> V_115 )
continue;
V_106 = (struct V_29 * ) ( V_104 -> V_116 + V_109 ) ;
if ( V_102 -> V_58 != V_106 -> V_58 ||
memcmp ( V_102 , V_106 , V_108 ) ) {
F_66 ( V_104 ) -> V_115 = 0 ;
continue;
}
}
type = V_102 -> V_87 ;
F_67 () ;
V_111 = F_68 ( type ) ;
if ( ! V_111 )
goto V_117;
F_69 ( V_31 , V_108 ) ;
F_70 ( V_31 , V_102 , V_108 ) ;
V_105 = F_71 ( V_111 -> V_118 . V_119 , V_103 , V_31 ) ;
V_112 = 0 ;
V_117:
F_72 () ;
V_113:
F_66 ( V_31 ) -> V_112 |= V_112 ;
return V_105 ;
}
static int F_73 ( struct V_9 * V_10 , struct V_30 * V_31 ,
int V_120 )
{
struct V_29 * V_102 ;
struct V_110 * V_111 ;
T_7 type ;
int V_108 ;
int V_49 = - V_121 ;
V_102 = (struct V_29 * ) ( V_31 -> V_116 + V_120 ) ;
V_108 = F_60 ( V_102 ) ;
type = V_102 -> V_87 ;
F_67 () ;
V_111 = F_74 ( type ) ;
if ( V_111 )
V_49 = V_111 -> V_118 . V_122 ( V_31 , V_120 + V_108 ) ;
F_72 () ;
F_75 ( V_31 , V_120 + V_108 ) ;
return V_49 ;
}
static struct V_7 * F_76 ( struct V_89 * V_89 , T_7 V_91 ,
bool V_28 , bool V_92 )
{
struct V_123 * V_124 = F_77 ( V_89 , V_125 ) ;
struct V_7 * V_8 ;
struct V_90 * V_9 ;
struct V_126 V_127 ;
int V_128 ;
V_8 = F_78 ( sizeof( * V_8 ) , V_81 ) ;
if ( ! V_8 )
return F_59 ( - V_79 ) ;
V_9 = F_56 ( V_89 , V_28 , V_91 , V_92 ) ;
if ( F_79 ( V_9 ) ) {
F_80 ( V_8 ) ;
return F_81 ( V_9 ) ;
}
V_8 -> V_9 = V_9 ;
V_8 -> V_129 = 1 ;
for ( V_128 = 0 ; V_128 < V_130 ; ++ V_128 )
F_82 ( & V_8 -> V_19 [ V_128 ] ) ;
F_83 ( V_8 -> V_9 , V_131 ) ;
memset ( & V_127 , 0 , sizeof( V_127 ) ) ;
V_127 . V_132 = V_8 ;
V_127 . V_133 = 1 ;
V_127 . V_119 = F_61 ;
V_127 . V_122 = F_73 ;
V_127 . V_134 = F_49 ;
V_127 . V_135 = NULL ;
F_84 ( V_89 , V_9 , & V_127 ) ;
F_85 ( & V_8 -> V_136 , & V_124 -> V_137 ) ;
return V_8 ;
}
static void F_86 ( struct V_7 * V_8 )
{
if ( ! V_8 || -- V_8 -> V_129 )
return;
F_87 ( & V_8 -> V_136 ) ;
F_88 ( V_8 -> V_9 , V_131 ) ;
F_89 ( V_8 -> V_9 ) ;
F_90 ( V_8 , V_138 ) ;
}
static void F_91 ( struct V_12 * V_20 )
{
struct V_7 * V_139 = F_92 ( V_20 -> V_140 ) ;
#if F_16 ( V_38 )
struct V_7 * V_141 = F_92 ( V_20 -> V_142 ) ;
F_93 ( V_20 -> V_142 , NULL ) ;
#endif
F_93 ( V_20 -> V_140 , NULL ) ;
F_94 () ;
F_86 ( V_139 ) ;
#if F_16 ( V_38 )
F_86 ( V_141 ) ;
#endif
}
static struct V_7 * F_95 ( struct V_123 * V_124 ,
T_5 V_95 ,
T_7 V_143 )
{
struct V_7 * V_8 ;
F_96 (gs, &gn->sock_list, list) {
if ( F_97 ( V_8 -> V_9 -> V_10 ) -> V_144 == V_143 &&
F_7 ( V_8 ) == V_95 ) {
return V_8 ;
}
}
return NULL ;
}
static int F_98 ( struct V_12 * V_20 , bool V_28 )
{
struct V_89 * V_89 = V_20 -> V_89 ;
struct V_123 * V_124 = F_77 ( V_89 , V_125 ) ;
struct V_16 * V_17 ;
struct V_7 * V_8 ;
T_4 V_1 [ 3 ] ;
T_1 V_18 ;
V_8 = F_95 ( V_124 , V_28 ? V_39 : V_33 , V_20 -> V_21 . V_22 . V_145 ) ;
if ( V_8 ) {
V_8 -> V_129 ++ ;
goto V_113;
}
V_8 = F_76 ( V_89 , V_20 -> V_21 . V_22 . V_145 , V_28 ,
V_20 -> V_97 ) ;
if ( F_79 ( V_8 ) )
return F_99 ( V_8 ) ;
V_113:
V_8 -> V_36 = V_20 -> V_36 ;
#if F_16 ( V_38 )
if ( V_28 ) {
F_93 ( V_20 -> V_142 , V_8 ) ;
V_17 = & V_20 -> V_146 ;
} else
#endif
{
F_93 ( V_20 -> V_140 , V_8 ) ;
V_17 = & V_20 -> V_147 ;
}
V_17 -> V_20 = V_20 ;
F_5 ( V_20 -> V_21 . V_22 . V_6 , V_1 ) ;
V_18 = F_1 ( V_1 ) ;
F_100 ( & V_17 -> V_148 , & V_8 -> V_19 [ V_18 ] ) ;
return 0 ;
}
static int F_101 ( struct V_78 * V_59 )
{
struct V_12 * V_20 = F_41 ( V_59 ) ;
bool V_28 = ! ! ( V_20 -> V_21 . V_149 & V_150 ) ;
bool V_151 = V_20 -> V_36 ;
int V_152 = 0 ;
#if F_16 ( V_38 )
if ( V_28 || V_151 )
V_152 = F_98 ( V_20 , true ) ;
#endif
if ( ! V_152 && ( ! V_28 || V_151 ) )
V_152 = F_98 ( V_20 , false ) ;
if ( V_152 < 0 )
F_91 ( V_20 ) ;
return V_152 ;
}
static int F_102 ( struct V_78 * V_59 )
{
struct V_12 * V_20 = F_41 ( V_59 ) ;
F_103 ( & V_20 -> V_147 . V_148 ) ;
#if F_16 ( V_38 )
F_103 ( & V_20 -> V_146 . V_148 ) ;
#endif
F_91 ( V_20 ) ;
return 0 ;
}
static void F_104 ( struct V_29 * V_82 ,
const struct V_153 * V_21 )
{
V_82 -> V_85 = V_86 ;
V_82 -> V_58 = V_21 -> V_154 / 4 ;
V_82 -> V_54 = ! ! ( V_21 -> V_22 . V_155 & V_55 ) ;
V_82 -> V_56 = ! ! ( V_21 -> V_22 . V_155 & V_57 ) ;
V_82 -> V_156 = 0 ;
F_5 ( V_21 -> V_22 . V_6 , V_82 -> V_1 ) ;
V_82 -> V_87 = F_51 ( V_88 ) ;
V_82 -> V_157 = 0 ;
F_105 ( V_82 -> V_63 , V_21 ) ;
}
static int F_106 ( struct V_158 * V_25 , struct V_30 * V_31 ,
const struct V_153 * V_21 ,
bool V_159 , int V_160 )
{
bool V_161 = ! ! ( V_21 -> V_22 . V_155 & V_162 ) ;
struct V_29 * V_43 ;
int V_163 ;
int V_49 ;
F_22 ( V_31 ) ;
F_107 ( V_31 , V_159 ) ;
V_163 = F_108 ( V_25 -> V_59 ) + V_25 -> V_164 +
V_84 + V_21 -> V_154 + V_160 ;
V_49 = F_109 ( V_31 , V_163 ) ;
if ( F_32 ( V_49 ) )
goto V_165;
V_49 = F_110 ( V_31 , V_161 ) ;
if ( V_49 )
goto V_165;
V_43 = F_111 ( V_31 , sizeof( * V_43 ) + V_21 -> V_154 ) ;
F_104 ( V_43 , V_21 ) ;
F_112 ( V_31 , F_51 ( V_88 ) ) ;
return 0 ;
V_165:
F_113 ( V_25 ) ;
return V_49 ;
}
static struct V_166 * F_114 ( struct V_30 * V_31 ,
struct V_78 * V_59 ,
struct V_7 * V_139 ,
struct V_167 * V_168 ,
const struct V_153 * V_21 )
{
bool V_169 = F_115 ( V_31 , V_21 ) ;
struct V_12 * V_20 = F_41 ( V_59 ) ;
struct V_80 * V_80 ;
struct V_166 * V_170 = NULL ;
T_4 V_71 ;
if ( ! V_139 )
return F_59 ( - V_171 ) ;
memset ( V_168 , 0 , sizeof( * V_168 ) ) ;
V_168 -> V_172 = V_31 -> V_173 ;
V_168 -> V_174 = V_175 ;
V_168 -> V_176 = V_21 -> V_22 . V_23 . V_24 . V_25 ;
V_168 -> V_37 = V_21 -> V_22 . V_23 . V_24 . V_177 ;
V_71 = V_21 -> V_22 . V_71 ;
if ( ( V_71 == 1 ) && ! V_20 -> V_36 ) {
V_71 = F_116 ( F_15 ( V_31 ) , V_31 ) ;
V_169 = false ;
}
V_168 -> V_178 = F_117 ( V_71 ) ;
V_80 = (struct V_80 * ) & V_21 -> V_80 ;
if ( V_169 ) {
V_170 = F_118 ( V_80 , & V_168 -> V_37 ) ;
if ( V_170 )
return V_170 ;
}
V_170 = F_119 ( V_20 -> V_89 , V_168 ) ;
if ( F_79 ( V_170 ) ) {
F_120 ( V_59 , L_4 , & V_168 -> V_176 ) ;
return F_59 ( - V_179 ) ;
}
if ( V_170 -> V_25 . V_59 == V_59 ) {
F_120 ( V_59 , L_5 , & V_168 -> V_176 ) ;
F_121 ( V_170 ) ;
return F_59 ( - V_180 ) ;
}
if ( V_169 )
F_122 ( V_80 , & V_170 -> V_25 , V_168 -> V_37 ) ;
return V_170 ;
}
static struct V_158 * F_123 ( struct V_30 * V_31 ,
struct V_78 * V_59 ,
struct V_7 * V_141 ,
struct V_181 * V_182 ,
const struct V_153 * V_21 )
{
bool V_169 = F_115 ( V_31 , V_21 ) ;
struct V_12 * V_20 = F_41 ( V_59 ) ;
struct V_158 * V_25 = NULL ;
struct V_80 * V_80 ;
T_4 V_183 ;
if ( ! V_141 )
return F_59 ( - V_171 ) ;
memset ( V_182 , 0 , sizeof( * V_182 ) ) ;
V_182 -> V_184 = V_31 -> V_173 ;
V_182 -> V_185 = V_175 ;
V_182 -> V_176 = V_21 -> V_22 . V_23 . V_28 . V_25 ;
V_182 -> V_37 = V_21 -> V_22 . V_23 . V_28 . V_177 ;
V_183 = V_21 -> V_22 . V_71 ;
if ( ( V_183 == 1 ) && ! V_20 -> V_36 ) {
V_183 = F_116 ( F_15 ( V_31 ) , V_31 ) ;
V_169 = false ;
}
V_182 -> V_186 = F_124 ( F_117 ( V_183 ) ,
V_21 -> V_22 . V_187 ) ;
V_80 = (struct V_80 * ) & V_21 -> V_80 ;
if ( V_169 ) {
V_25 = F_125 ( V_80 , & V_182 -> V_37 ) ;
if ( V_25 )
return V_25 ;
}
if ( V_188 -> V_189 ( V_20 -> V_89 , V_141 -> V_9 -> V_10 , & V_25 , V_182 ) ) {
F_120 ( V_59 , L_6 , & V_182 -> V_176 ) ;
return F_59 ( - V_179 ) ;
}
if ( V_25 -> V_59 == V_59 ) {
F_120 ( V_59 , L_7 , & V_182 -> V_176 ) ;
F_113 ( V_25 ) ;
return F_59 ( - V_180 ) ;
}
if ( V_169 )
F_126 ( V_80 , V_25 , & V_182 -> V_37 ) ;
return V_25 ;
}
static int F_127 ( struct V_30 * V_31 , struct V_78 * V_59 ,
struct V_12 * V_20 ,
const struct V_153 * V_21 )
{
bool V_159 = ! F_54 ( V_20 -> V_89 , F_55 ( V_20 -> V_59 ) ) ;
struct V_7 * V_139 = F_128 ( V_20 -> V_140 ) ;
const struct V_190 * V_22 = & V_21 -> V_22 ;
struct V_166 * V_170 ;
struct V_167 V_168 ;
T_4 V_71 , V_191 ;
T_7 V_192 ;
T_7 V_193 ;
int V_49 ;
V_170 = F_114 ( V_31 , V_59 , V_139 , & V_168 , V_21 ) ;
if ( F_79 ( V_170 ) )
return F_99 ( V_170 ) ;
V_192 = F_129 ( V_20 -> V_89 , V_31 , 1 , V_194 , true ) ;
if ( V_20 -> V_36 ) {
V_71 = F_130 ( V_22 -> V_71 , F_15 ( V_31 ) , V_31 ) ;
V_191 = V_22 -> V_191 ;
} else {
V_71 = F_130 ( V_168 . V_178 , F_15 ( V_31 ) , V_31 ) ;
V_191 = V_22 -> V_191 ? : F_131 ( & V_170 -> V_25 ) ;
}
V_193 = V_22 -> V_155 & V_195 ? F_51 ( V_196 ) : 0 ;
V_49 = F_106 ( & V_170 -> V_25 , V_31 , V_21 , V_159 , sizeof( struct V_34 ) ) ;
if ( F_32 ( V_49 ) )
return V_49 ;
F_132 ( V_170 , V_139 -> V_9 -> V_10 , V_31 , V_168 . V_37 , V_168 . V_176 ,
V_71 , V_191 , V_193 , V_192 , V_20 -> V_21 . V_22 . V_145 ,
! F_54 ( V_20 -> V_89 , F_55 ( V_20 -> V_59 ) ) ,
! ( V_21 -> V_22 . V_155 & V_162 ) ) ;
return 0 ;
}
static int F_133 ( struct V_30 * V_31 , struct V_78 * V_59 ,
struct V_12 * V_20 ,
const struct V_153 * V_21 )
{
bool V_159 = ! F_54 ( V_20 -> V_89 , F_55 ( V_20 -> V_59 ) ) ;
struct V_7 * V_141 = F_128 ( V_20 -> V_142 ) ;
const struct V_190 * V_22 = & V_21 -> V_22 ;
struct V_158 * V_25 = NULL ;
struct V_181 V_182 ;
T_4 V_183 , V_191 ;
T_7 V_192 ;
int V_49 ;
V_25 = F_123 ( V_31 , V_59 , V_141 , & V_182 , V_21 ) ;
if ( F_79 ( V_25 ) )
return F_99 ( V_25 ) ;
V_192 = F_129 ( V_20 -> V_89 , V_31 , 1 , V_194 , true ) ;
if ( V_20 -> V_36 ) {
V_183 = F_130 ( V_22 -> V_71 , F_15 ( V_31 ) , V_31 ) ;
V_191 = V_22 -> V_191 ;
} else {
V_183 = F_130 ( F_134 ( V_182 . V_186 ) ,
F_15 ( V_31 ) , V_31 ) ;
V_191 = V_22 -> V_191 ? : F_135 ( V_25 ) ;
}
V_49 = F_106 ( V_25 , V_31 , V_21 , V_159 , sizeof( struct V_41 ) ) ;
if ( F_32 ( V_49 ) )
return V_49 ;
F_136 ( V_25 , V_141 -> V_9 -> V_10 , V_31 , V_59 ,
& V_182 . V_37 , & V_182 . V_176 , V_183 , V_191 ,
V_21 -> V_22 . V_187 , V_192 , V_20 -> V_21 . V_22 . V_145 ,
! ( V_21 -> V_22 . V_155 & V_162 ) ) ;
return 0 ;
}
static T_8 F_137 ( struct V_30 * V_31 , struct V_78 * V_59 )
{
struct V_12 * V_20 = F_41 ( V_59 ) ;
struct V_153 * V_21 = NULL ;
int V_49 ;
if ( V_20 -> V_36 ) {
V_21 = F_138 ( V_31 ) ;
if ( F_32 ( ! V_21 || ! ( V_21 -> V_149 & V_197 ) ) ) {
V_49 = - V_198 ;
F_120 ( V_59 , L_8 ) ;
goto V_199;
}
} else {
V_21 = & V_20 -> V_21 ;
}
F_67 () ;
#if F_16 ( V_38 )
if ( V_21 -> V_149 & V_150 )
V_49 = F_133 ( V_31 , V_59 , V_20 , V_21 ) ;
else
#endif
V_49 = F_127 ( V_31 , V_59 , V_20 , V_21 ) ;
F_72 () ;
if ( F_35 ( ! V_49 ) )
return V_200 ;
V_199:
F_139 ( V_31 ) ;
if ( V_49 == - V_180 )
V_59 -> V_47 . V_201 ++ ;
else if ( V_49 == - V_179 )
V_59 -> V_47 . V_202 ++ ;
V_59 -> V_47 . V_203 ++ ;
return V_200 ;
}
static int F_140 ( struct V_78 * V_59 , int V_204 )
{
if ( V_204 > V_59 -> V_205 )
V_204 = V_59 -> V_205 ;
V_59 -> V_206 = V_204 ;
return 0 ;
}
static int F_141 ( struct V_78 * V_59 , struct V_30 * V_31 )
{
struct V_153 * V_21 = F_138 ( V_31 ) ;
struct V_12 * V_20 = F_41 ( V_59 ) ;
if ( F_142 ( V_21 ) == V_33 ) {
struct V_166 * V_170 ;
struct V_167 V_168 ;
struct V_7 * V_139 = F_128 ( V_20 -> V_140 ) ;
V_170 = F_114 ( V_31 , V_59 , V_139 , & V_168 , V_21 ) ;
if ( F_79 ( V_170 ) )
return F_99 ( V_170 ) ;
F_121 ( V_170 ) ;
V_21 -> V_22 . V_23 . V_24 . V_177 = V_168 . V_37 ;
#if F_16 ( V_38 )
} else if ( F_142 ( V_21 ) == V_39 ) {
struct V_158 * V_25 ;
struct V_181 V_182 ;
struct V_7 * V_141 = F_128 ( V_20 -> V_142 ) ;
V_25 = F_123 ( V_31 , V_59 , V_141 , & V_182 , V_21 ) ;
if ( F_79 ( V_25 ) )
return F_99 ( V_25 ) ;
F_113 ( V_25 ) ;
V_21 -> V_22 . V_23 . V_28 . V_177 = V_182 . V_37 ;
#endif
} else {
return - V_198 ;
}
V_21 -> V_22 . V_207 = F_129 ( V_20 -> V_89 , V_31 ,
1 , V_194 , true ) ;
V_21 -> V_22 . V_145 = V_20 -> V_21 . V_22 . V_145 ;
return 0 ;
}
static void F_143 ( struct V_78 * V_59 ,
struct V_208 * V_209 )
{
F_144 ( V_209 -> V_210 , V_211 , sizeof( V_209 -> V_210 ) ) ;
F_144 ( V_209 -> V_212 , L_9 , sizeof( V_209 -> V_212 ) ) ;
}
static void F_145 ( struct V_78 * V_59 , bool V_213 )
{
struct V_89 * V_89 = F_55 ( V_59 ) ;
struct V_123 * V_124 = F_77 ( V_89 , V_125 ) ;
struct V_7 * V_8 ;
F_67 () ;
F_146 (gs, &gn->sock_list, list) {
if ( V_213 ) {
F_147 ( V_59 , V_8 -> V_9 ,
V_131 ) ;
} else {
F_148 ( V_59 , V_8 -> V_9 ,
V_131 ) ;
}
}
F_72 () ;
}
static void F_149 ( struct V_78 * V_59 )
{
F_150 ( V_59 ) ;
V_59 -> V_214 = & V_215 ;
V_59 -> V_216 = & V_217 ;
V_59 -> V_218 = true ;
F_151 ( V_59 , & V_219 ) ;
V_59 -> V_220 |= V_221 ;
V_59 -> V_220 |= V_222 | V_223 ;
V_59 -> V_220 |= V_224 ;
V_59 -> V_220 |= V_225 ;
V_59 -> V_226 |= V_222 | V_223 | V_224 ;
V_59 -> V_226 |= V_225 ;
V_59 -> V_227 = V_228 ;
V_59 -> V_205 = V_229 - V_84 - V_59 -> V_230 ;
F_152 ( V_59 ) ;
V_59 -> V_231 &= ~ V_232 ;
V_59 -> V_231 |= V_233 | V_234 ;
F_153 ( V_59 ) ;
}
static int F_154 ( struct V_235 * V_236 [] , struct V_235 * V_116 [] ,
struct V_237 * V_238 )
{
if ( V_236 [ V_239 ] ) {
if ( F_155 ( V_236 [ V_239 ] ) != V_240 ) {
F_156 ( V_238 , V_236 [ V_239 ] ,
L_10 ) ;
return - V_198 ;
}
if ( ! F_157 ( F_158 ( V_236 [ V_239 ] ) ) ) {
F_156 ( V_238 , V_236 [ V_239 ] ,
L_11 ) ;
return - V_241 ;
}
}
if ( ! V_116 ) {
F_159 ( V_238 ,
L_12 ) ;
return - V_198 ;
}
if ( V_116 [ V_242 ] ) {
T_1 V_1 = F_160 ( V_116 [ V_242 ] ) ;
if ( V_1 >= V_243 ) {
F_156 ( V_238 , V_116 [ V_242 ] ,
L_13 ) ;
return - V_244 ;
}
}
return 0 ;
}
static struct V_12 * F_161 ( struct V_123 * V_124 ,
const struct V_153 * V_21 ,
bool * V_245 ,
bool * V_246 )
{
struct V_12 * V_20 , * V_247 = NULL ;
* V_245 = false ;
* V_246 = false ;
F_96 (geneve, &gn->geneve_list, next) {
if ( V_21 -> V_22 . V_145 == V_20 -> V_21 . V_22 . V_145 ) {
* V_246 = V_20 -> V_36 ;
* V_245 = true ;
}
if ( V_21 -> V_22 . V_6 == V_20 -> V_21 . V_22 . V_6 &&
V_21 -> V_22 . V_145 == V_20 -> V_21 . V_22 . V_145 &&
! memcmp ( & V_21 -> V_22 . V_23 , & V_20 -> V_21 . V_22 . V_23 , sizeof( V_21 -> V_22 . V_23 ) ) )
V_247 = V_20 ;
}
return V_247 ;
}
static bool F_162 ( const T_2 * V_248 , T_9 V_249 )
{
int V_250 ;
for ( V_250 = 0 ; V_250 < V_249 ; V_250 ++ )
if ( V_248 [ V_250 ] )
return false ;
return true ;
}
static bool F_163 ( const struct V_153 * V_21 )
{
if ( V_21 -> V_22 . V_6 || V_21 -> V_22 . V_155 || V_21 -> V_22 . V_71 ||
V_21 -> V_22 . V_191 || V_21 -> V_22 . V_187 || V_21 -> V_22 . V_207 ||
! F_162 ( ( const T_2 * ) & V_21 -> V_22 . V_23 , sizeof( V_21 -> V_22 . V_23 ) ) )
return false ;
else
return true ;
}
static bool F_164 ( struct V_153 * V_251 ,
struct V_153 * V_252 )
{
if ( F_142 ( V_251 ) == V_33 )
return V_251 -> V_22 . V_23 . V_24 . V_25 == V_252 -> V_22 . V_23 . V_24 . V_25 ;
else
return F_11 ( & V_251 -> V_22 . V_23 . V_28 . V_25 , & V_252 -> V_22 . V_23 . V_28 . V_25 ) ;
}
static int F_165 ( struct V_89 * V_89 , struct V_78 * V_59 ,
struct V_237 * V_238 ,
const struct V_153 * V_21 ,
bool V_151 , bool V_92 )
{
struct V_123 * V_124 = F_77 ( V_89 , V_125 ) ;
struct V_12 * V_247 , * V_20 = F_41 ( V_59 ) ;
bool V_246 , V_245 ;
int V_49 , V_253 ;
if ( V_151 && ! F_163 ( V_21 ) ) {
F_159 ( V_238 ,
L_14 ) ;
return - V_198 ;
}
V_20 -> V_89 = V_89 ;
V_20 -> V_59 = V_59 ;
V_247 = F_161 ( V_124 , V_21 , & V_245 , & V_246 ) ;
if ( V_247 )
return - V_254 ;
V_253 = V_84 + V_67 ;
if ( ! V_151 && F_142 ( V_21 ) == V_33 ) {
V_253 += sizeof( struct V_34 ) ;
V_59 -> V_205 -= sizeof( struct V_34 ) ;
} else {
V_253 += sizeof( struct V_41 ) ;
V_59 -> V_205 -= sizeof( struct V_41 ) ;
}
V_59 -> V_255 = V_253 + V_67 ;
if ( V_151 ) {
if ( V_245 ) {
F_159 ( V_238 ,
L_15 ) ;
return - V_256 ;
}
} else {
if ( V_246 ) {
F_159 ( V_238 ,
L_16 ) ;
return - V_256 ;
}
}
F_166 ( & V_20 -> V_21 . V_80 ) ;
V_20 -> V_21 = * V_21 ;
V_20 -> V_36 = V_151 ;
V_20 -> V_97 = V_92 ;
V_49 = F_167 ( V_59 ) ;
if ( V_49 )
return V_49 ;
F_85 ( & V_20 -> V_114 , & V_124 -> V_257 ) ;
return 0 ;
}
static void F_168 ( struct V_153 * V_21 , T_10 V_143 )
{
memset ( V_21 , 0 , sizeof( * V_21 ) ) ;
V_21 -> V_22 . V_145 = F_51 ( V_143 ) ;
}
static int F_169 ( struct V_235 * V_236 [] , struct V_235 * V_116 [] ,
struct V_237 * V_238 ,
struct V_153 * V_21 , bool * V_151 ,
bool * V_97 , bool V_258 )
{
int V_259 ;
if ( V_116 [ V_260 ] && V_116 [ V_261 ] ) {
F_159 ( V_238 ,
L_17 ) ;
return - V_198 ;
}
if ( V_116 [ V_260 ] ) {
if ( V_258 && ( F_142 ( V_21 ) == V_39 ) ) {
V_259 = V_260 ;
goto V_262;
}
V_21 -> V_22 . V_23 . V_24 . V_25 =
F_170 ( V_116 [ V_260 ] ) ;
if ( F_171 ( F_172 ( V_21 -> V_22 . V_23 . V_24 . V_25 ) ) ) {
F_156 ( V_238 , V_116 [ V_260 ] ,
L_18 ) ;
return - V_198 ;
}
}
if ( V_116 [ V_261 ] ) {
#if F_16 ( V_38 )
if ( V_258 && ( F_142 ( V_21 ) == V_33 ) ) {
V_259 = V_261 ;
goto V_262;
}
V_21 -> V_149 = V_150 ;
V_21 -> V_22 . V_23 . V_28 . V_25 =
F_173 ( V_116 [ V_261 ] ) ;
if ( F_174 ( & V_21 -> V_22 . V_23 . V_28 . V_25 ) &
V_263 ) {
F_156 ( V_238 , V_116 [ V_261 ] ,
L_19 ) ;
return - V_198 ;
}
if ( F_175 ( & V_21 -> V_22 . V_23 . V_28 . V_25 ) ) {
F_156 ( V_238 , V_116 [ V_261 ] ,
L_20 ) ;
return - V_198 ;
}
V_21 -> V_22 . V_155 |= V_162 ;
* V_97 = true ;
#else
F_156 ( V_238 , V_116 [ V_261 ] ,
L_21 ) ;
return - V_264 ;
#endif
}
if ( V_116 [ V_242 ] ) {
T_1 V_1 ;
T_4 V_265 [ 3 ] ;
T_3 V_266 ;
V_1 = F_160 ( V_116 [ V_242 ] ) ;
V_265 [ 0 ] = ( V_1 & 0x00ff0000 ) >> 16 ;
V_265 [ 1 ] = ( V_1 & 0x0000ff00 ) >> 8 ;
V_265 [ 2 ] = V_1 & 0x000000ff ;
V_266 = F_3 ( V_265 ) ;
if ( V_258 && ( V_266 != V_21 -> V_22 . V_6 ) ) {
V_259 = V_242 ;
goto V_262;
}
V_21 -> V_22 . V_6 = V_266 ;
}
if ( V_116 [ V_267 ] )
V_21 -> V_22 . V_191 = F_176 ( V_116 [ V_267 ] ) ;
if ( V_116 [ V_268 ] )
V_21 -> V_22 . V_71 = F_176 ( V_116 [ V_268 ] ) ;
if ( V_116 [ V_269 ] ) {
V_21 -> V_22 . V_187 = F_177 ( V_116 [ V_269 ] ) &
V_270 ;
if ( V_21 -> V_22 . V_187 && ( ! ( V_21 -> V_149 & V_150 ) ) ) {
F_156 ( V_238 , V_116 [ V_269 ] ,
L_22 ) ;
return - V_198 ;
}
}
if ( V_116 [ V_271 ] ) {
if ( V_258 ) {
V_259 = V_271 ;
goto V_262;
}
V_21 -> V_22 . V_145 = F_178 ( V_116 [ V_271 ] ) ;
}
if ( V_116 [ V_272 ] ) {
if ( V_258 ) {
V_259 = V_272 ;
goto V_262;
}
* V_151 = true ;
}
if ( V_116 [ V_273 ] ) {
if ( V_258 ) {
V_259 = V_273 ;
goto V_262;
}
if ( F_176 ( V_116 [ V_273 ] ) )
V_21 -> V_22 . V_155 |= V_162 ;
}
if ( V_116 [ V_274 ] ) {
if ( V_258 ) {
V_259 = V_274 ;
goto V_262;
}
if ( F_176 ( V_116 [ V_274 ] ) )
V_21 -> V_22 . V_155 &= ~ V_162 ;
}
if ( V_116 [ V_275 ] ) {
if ( V_258 ) {
V_259 = V_275 ;
goto V_262;
}
if ( F_176 ( V_116 [ V_275 ] ) )
* V_97 = false ;
}
return 0 ;
V_262:
F_156 ( V_238 , V_116 [ V_259 ] ,
L_23 ) ;
return - V_276 ;
}
static int F_179 ( struct V_89 * V_89 , struct V_78 * V_59 ,
struct V_235 * V_236 [] , struct V_235 * V_116 [] ,
struct V_237 * V_238 )
{
bool V_97 = false ;
struct V_153 V_21 ;
bool V_151 = false ;
int V_49 ;
F_168 ( & V_21 , V_277 ) ;
V_49 = F_169 ( V_236 , V_116 , V_238 , & V_21 , & V_151 ,
& V_97 , false ) ;
if ( V_49 )
return V_49 ;
return F_165 ( V_89 , V_59 , V_238 , & V_21 , V_151 ,
V_97 ) ;
}
static void F_180 ( struct V_12 * V_20 , struct V_7 * * V_139 ,
struct V_7 * * V_141 )
{
* V_139 = F_92 ( V_20 -> V_140 ) ;
F_93 ( V_20 -> V_140 , NULL ) ;
if ( * V_139 )
F_181 ( ( * V_139 ) -> V_9 -> V_10 , NULL ) ;
#if F_16 ( V_38 )
* V_141 = F_92 ( V_20 -> V_142 ) ;
F_93 ( V_20 -> V_142 , NULL ) ;
if ( * V_141 )
F_181 ( ( * V_141 ) -> V_9 -> V_10 , NULL ) ;
#else
* V_141 = NULL ;
#endif
F_94 () ;
}
static void F_182 ( struct V_12 * V_20 , struct V_7 * V_139 ,
struct V_7 T_11 * V_141 )
{
F_93 ( V_20 -> V_140 , V_139 ) ;
if ( V_139 )
F_181 ( V_139 -> V_9 -> V_10 , V_139 ) ;
#if F_16 ( V_38 )
F_93 ( V_20 -> V_142 , V_141 ) ;
if ( V_141 )
F_181 ( V_141 -> V_9 -> V_10 , V_141 ) ;
#endif
F_94 () ;
}
static int F_183 ( struct V_78 * V_59 , struct V_235 * V_236 [] ,
struct V_235 * V_116 [] ,
struct V_237 * V_238 )
{
struct V_12 * V_20 = F_41 ( V_59 ) ;
struct V_7 * V_139 , * V_141 ;
struct V_153 V_21 ;
bool V_151 ;
bool V_97 ;
int V_49 ;
if ( V_20 -> V_36 )
return - V_276 ;
memcpy ( & V_21 , & V_20 -> V_21 , sizeof( V_21 ) ) ;
V_151 = V_20 -> V_36 ;
V_97 = V_20 -> V_97 ;
V_49 = F_169 ( V_236 , V_116 , V_238 , & V_21 , & V_151 ,
& V_97 , true ) ;
if ( V_49 )
return V_49 ;
if ( ! F_164 ( & V_20 -> V_21 , & V_21 ) )
F_166 ( & V_21 . V_80 ) ;
F_180 ( V_20 , & V_139 , & V_141 ) ;
V_20 -> V_21 = V_21 ;
V_20 -> V_36 = V_151 ;
V_20 -> V_97 = V_97 ;
F_182 ( V_20 , V_139 , V_141 ) ;
return 0 ;
}
static void F_184 ( struct V_78 * V_59 , struct V_278 * V_103 )
{
struct V_12 * V_20 = F_41 ( V_59 ) ;
F_87 ( & V_20 -> V_114 ) ;
F_185 ( V_59 , V_103 ) ;
}
static T_9 F_186 ( const struct V_78 * V_59 )
{
return F_187 ( sizeof( T_1 ) ) +
F_187 ( sizeof( struct V_26 ) ) +
F_187 ( sizeof( T_4 ) ) +
F_187 ( sizeof( T_4 ) ) +
F_187 ( sizeof( T_6 ) ) +
F_187 ( sizeof( T_7 ) ) +
F_187 ( 0 ) +
F_187 ( sizeof( T_4 ) ) +
F_187 ( sizeof( T_4 ) ) +
F_187 ( sizeof( T_4 ) ) +
0 ;
}
static int F_188 ( struct V_30 * V_31 , const struct V_78 * V_59 )
{
struct V_12 * V_20 = F_41 ( V_59 ) ;
struct V_153 * V_21 = & V_20 -> V_21 ;
T_4 V_279 [ 3 ] ;
T_1 V_1 ;
F_5 ( V_21 -> V_22 . V_6 , V_279 ) ;
V_1 = ( V_279 [ 0 ] << 16 ) | ( V_279 [ 1 ] << 8 ) | V_279 [ 2 ] ;
if ( F_189 ( V_31 , V_242 , V_1 ) )
goto V_280;
if ( F_92 ( V_20 -> V_140 ) ) {
if ( F_190 ( V_31 , V_260 ,
V_21 -> V_22 . V_23 . V_24 . V_25 ) )
goto V_280;
if ( F_191 ( V_31 , V_273 ,
! ! ( V_21 -> V_22 . V_155 & V_162 ) ) )
goto V_280;
}
#if F_16 ( V_38 )
if ( F_92 ( V_20 -> V_142 ) ) {
if ( F_192 ( V_31 , V_261 ,
& V_21 -> V_22 . V_23 . V_28 . V_25 ) )
goto V_280;
if ( F_191 ( V_31 , V_274 ,
! ( V_21 -> V_22 . V_155 & V_162 ) ) )
goto V_280;
if ( F_191 ( V_31 , V_275 ,
! V_20 -> V_97 ) )
goto V_280;
}
#endif
if ( F_191 ( V_31 , V_267 , V_21 -> V_22 . V_191 ) ||
F_191 ( V_31 , V_268 , V_21 -> V_22 . V_71 ) ||
F_193 ( V_31 , V_269 , V_21 -> V_22 . V_187 ) )
goto V_280;
if ( F_194 ( V_31 , V_271 , V_21 -> V_22 . V_145 ) )
goto V_280;
if ( V_20 -> V_36 ) {
if ( F_195 ( V_31 , V_272 ) )
goto V_280;
}
return 0 ;
V_280:
return - V_281 ;
}
struct V_78 * F_196 ( struct V_89 * V_89 , const char * V_282 ,
T_2 V_283 , T_12 V_143 )
{
struct V_235 * V_236 [ V_284 + 1 ] ;
struct V_153 V_21 ;
struct V_78 * V_59 ;
F_197 ( V_285 ) ;
int V_49 ;
memset ( V_236 , 0 , sizeof( V_236 ) ) ;
V_59 = F_198 ( V_89 , V_282 , V_283 ,
& V_286 , V_236 ) ;
if ( F_79 ( V_59 ) )
return V_59 ;
F_168 ( & V_21 , V_143 ) ;
V_49 = F_165 ( V_89 , V_59 , NULL , & V_21 , true , true ) ;
if ( V_49 ) {
F_199 ( V_59 ) ;
return F_59 ( V_49 ) ;
}
V_49 = F_140 ( V_59 , V_229 ) ;
if ( V_49 )
goto V_49;
V_49 = F_200 ( V_59 , NULL ) ;
if ( V_49 < 0 )
goto V_49;
return V_59 ;
V_49:
F_184 ( V_59 , & V_285 ) ;
F_201 ( & V_285 ) ;
return F_59 ( V_49 ) ;
}
static int F_202 ( struct V_287 * V_288 ,
unsigned long V_289 , void * V_290 )
{
struct V_78 * V_59 = F_203 ( V_290 ) ;
if ( V_289 == V_291 ||
V_289 == V_292 ) {
F_145 ( V_59 , V_289 == V_291 ) ;
} else if ( V_289 == V_293 ) {
F_145 ( V_59 , false ) ;
} else if ( V_289 == V_294 ) {
F_145 ( V_59 , true ) ;
}
return V_295 ;
}
static T_13 int F_204 ( struct V_89 * V_89 )
{
struct V_123 * V_124 = F_77 ( V_89 , V_125 ) ;
F_205 ( & V_124 -> V_257 ) ;
F_205 ( & V_124 -> V_137 ) ;
return 0 ;
}
static void T_14 F_206 ( struct V_89 * V_89 )
{
struct V_123 * V_124 = F_77 ( V_89 , V_125 ) ;
struct V_12 * V_20 , * V_114 ;
struct V_78 * V_59 , * V_296 ;
F_197 ( V_136 ) ;
F_207 () ;
F_208 (net, dev, aux)
if ( V_59 -> V_297 == & V_286 )
F_185 ( V_59 , & V_136 ) ;
F_209 (geneve, next, &gn->geneve_list, next) {
if ( ! F_54 ( F_55 ( V_20 -> V_59 ) , V_89 ) )
F_185 ( V_20 -> V_59 , & V_136 ) ;
}
F_201 ( & V_136 ) ;
F_210 () ;
}
static int T_15 F_211 ( void )
{
int V_298 ;
V_298 = F_212 ( & V_299 ) ;
if ( V_298 )
goto V_300;
V_298 = F_213 ( & V_301 ) ;
if ( V_298 )
goto V_302;
V_298 = F_214 ( & V_286 ) ;
if ( V_298 )
goto V_303;
return 0 ;
V_303:
F_215 ( & V_301 ) ;
V_302:
F_216 ( & V_299 ) ;
V_300:
return V_298 ;
}
static void T_16 F_217 ( void )
{
F_218 ( & V_286 ) ;
F_215 ( & V_301 ) ;
F_216 ( & V_299 ) ;
}
