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
static T_5 F_5 ( struct V_6 * V_7 )
{
return V_7 -> V_8 -> V_9 -> V_10 ;
}
static struct V_11 * F_6 ( struct V_6 * V_7 ,
T_6 V_12 , T_2 V_1 [] )
{
struct V_13 * V_14 ;
struct V_11 * V_15 ;
T_1 V_16 ;
V_16 = F_1 ( V_1 ) ;
V_14 = & V_7 -> V_17 [ V_16 ] ;
F_7 (geneve, vni_list_head, hlist) {
if ( ! memcmp ( V_1 , V_15 -> V_1 , sizeof( V_15 -> V_1 ) ) &&
V_12 == V_15 -> V_18 . sin . V_19 . V_20 )
return V_15 ;
}
return NULL ;
}
static struct V_11 * F_8 ( struct V_6 * V_7 ,
struct V_21 V_22 , T_2 V_1 [] )
{
struct V_13 * V_14 ;
struct V_11 * V_15 ;
T_1 V_16 ;
V_16 = F_1 ( V_1 ) ;
V_14 = & V_7 -> V_17 [ V_16 ] ;
F_7 (geneve, vni_list_head, hlist) {
if ( ! memcmp ( V_1 , V_15 -> V_1 , sizeof( V_15 -> V_1 ) ) &&
F_9 ( & V_22 , & V_15 -> V_18 . V_23 . V_24 ) )
return V_15 ;
}
return NULL ;
}
static inline struct V_25 * F_10 ( const struct V_26 * V_27 )
{
return (struct V_25 * ) ( F_11 ( V_27 ) + 1 ) ;
}
static struct V_11 * F_12 ( struct V_6 * V_7 ,
struct V_26 * V_27 )
{
T_2 * V_1 ;
T_6 V_12 ;
static T_2 V_28 [ 3 ] ;
#if F_13 ( V_29 )
static struct V_21 V_30 ;
#endif
if ( F_5 ( V_7 ) == V_31 ) {
struct V_32 * V_33 ;
V_33 = F_14 ( V_27 ) ;
if ( V_7 -> V_34 ) {
V_1 = V_28 ;
V_12 = 0 ;
} else {
V_1 = F_10 ( V_27 ) -> V_1 ;
V_12 = V_33 -> V_35 ;
}
return F_6 ( V_7 , V_12 , V_1 ) ;
#if F_13 ( V_29 )
} else if ( F_5 ( V_7 ) == V_36 ) {
struct V_37 * V_38 ;
struct V_21 V_22 ;
V_38 = F_15 ( V_27 ) ;
if ( V_7 -> V_34 ) {
V_1 = V_28 ;
V_22 = V_30 ;
} else {
V_1 = F_10 ( V_27 ) -> V_1 ;
V_22 = V_38 -> V_35 ;
}
return F_8 ( V_7 , V_22 , V_1 ) ;
#endif
}
return NULL ;
}
static void F_16 ( struct V_11 * V_15 , struct V_6 * V_7 ,
struct V_26 * V_27 )
{
struct V_25 * V_39 = F_10 ( V_27 ) ;
struct V_40 * V_41 = NULL ;
struct V_42 * V_43 ;
int V_44 = 0 ;
void * V_45 ;
if ( F_17 () || V_7 -> V_34 ) {
T_7 V_46 ;
V_46 = V_47 | V_48 |
( V_39 -> V_49 ? V_50 : 0 ) |
( V_39 -> V_51 ? V_52 : 0 ) ;
V_41 = F_18 ( V_27 , F_5 ( V_7 ) , V_46 ,
F_3 ( V_39 -> V_1 ) ,
V_39 -> V_53 * 4 ) ;
if ( ! V_41 )
goto V_54;
F_19 ( & V_41 -> V_55 . V_56 ,
V_39 -> V_57 , V_39 -> V_53 * 4 ) ;
} else {
if ( V_39 -> V_51 )
goto V_54;
}
F_20 ( V_27 ) ;
V_27 -> V_58 = F_21 ( V_27 , V_15 -> V_59 ) ;
F_22 ( V_27 , F_23 ( V_27 ) , V_60 ) ;
if ( V_41 )
F_24 ( V_27 , & V_41 -> V_61 ) ;
if ( F_25 ( F_23 ( V_27 ) -> V_62 , V_15 -> V_59 -> V_63 ) )
goto V_54;
V_45 = F_26 ( V_27 ) ;
F_27 ( V_27 ) ;
if ( F_5 ( V_7 ) == V_31 )
V_44 = F_28 ( V_45 , V_27 ) ;
#if F_13 ( V_29 )
else
V_44 = F_29 ( V_45 , V_27 ) ;
#endif
if ( F_30 ( V_44 ) ) {
if ( V_64 ) {
if ( F_5 ( V_7 ) == V_31 )
F_31 ( L_1
L_2 ,
& ( (struct V_32 * ) V_45 ) -> V_35 ,
( (struct V_32 * ) V_45 ) -> V_65 ) ;
#if F_13 ( V_29 )
else
F_31 ( L_3 ,
& ( (struct V_37 * ) V_45 ) -> V_35 ) ;
#endif
}
if ( V_44 > 1 ) {
++ V_15 -> V_59 -> V_43 . V_66 ;
++ V_15 -> V_59 -> V_43 . V_67 ;
goto V_54;
}
}
V_43 = F_32 ( V_15 -> V_59 -> V_68 ) ;
F_33 ( & V_43 -> V_69 ) ;
V_43 -> V_70 ++ ;
V_43 -> V_71 += V_27 -> V_72 ;
F_34 ( & V_43 -> V_69 ) ;
F_35 ( & V_15 -> V_73 , V_27 ) ;
return;
V_54:
F_36 ( V_27 ) ;
}
static int F_37 ( struct V_74 * V_59 )
{
struct V_11 * V_15 = F_38 ( V_59 ) ;
int V_44 ;
V_59 -> V_68 = F_39 ( struct V_42 ) ;
if ( ! V_59 -> V_68 )
return - V_75 ;
V_44 = F_40 ( & V_15 -> V_73 , V_59 ) ;
if ( V_44 ) {
F_41 ( V_59 -> V_68 ) ;
return V_44 ;
}
V_44 = F_42 ( & V_15 -> V_76 , V_77 ) ;
if ( V_44 ) {
F_41 ( V_59 -> V_68 ) ;
F_43 ( & V_15 -> V_73 ) ;
return V_44 ;
}
return 0 ;
}
static void F_44 ( struct V_74 * V_59 )
{
struct V_11 * V_15 = F_38 ( V_59 ) ;
F_45 ( & V_15 -> V_76 ) ;
F_43 ( & V_15 -> V_73 ) ;
F_41 ( V_59 -> V_68 ) ;
}
static int F_46 ( struct V_8 * V_9 , struct V_26 * V_27 )
{
struct V_25 * V_78 ;
struct V_11 * V_15 ;
struct V_6 * V_7 ;
int V_79 ;
if ( F_30 ( ! F_47 ( V_27 , V_80 ) ) )
goto error;
V_78 = F_10 ( V_27 ) ;
if ( F_30 ( V_78 -> V_81 != V_82 ) )
goto error;
if ( F_30 ( V_78 -> V_83 != F_48 ( V_84 ) ) )
goto error;
V_7 = F_49 ( V_9 ) ;
if ( ! V_7 )
goto V_54;
V_15 = F_12 ( V_7 , V_27 ) ;
if ( ! V_15 )
goto V_54;
V_79 = V_78 -> V_53 * 4 ;
if ( F_50 ( V_27 , V_80 + V_79 ,
F_48 ( V_84 ) ,
! F_51 ( V_15 -> V_85 , F_52 ( V_15 -> V_59 ) ) ) )
goto V_54;
F_16 ( V_15 , V_7 , V_27 ) ;
return 0 ;
V_54:
F_36 ( V_27 ) ;
return 0 ;
error:
return 1 ;
}
static struct V_86 * F_53 ( struct V_85 * V_85 , bool V_87 ,
T_7 V_88 , T_8 V_46 )
{
struct V_86 * V_8 ;
struct V_89 V_90 ;
int V_44 ;
memset ( & V_90 , 0 , sizeof( V_90 ) ) ;
if ( V_87 ) {
V_90 . V_91 = V_36 ;
V_90 . V_92 = 1 ;
V_90 . V_93 =
! ( V_46 & V_94 ) ;
} else {
V_90 . V_91 = V_31 ;
V_90 . V_95 . V_20 = F_54 ( V_96 ) ;
}
V_90 . V_97 = V_88 ;
V_44 = F_55 ( V_85 , & V_90 , & V_8 ) ;
if ( V_44 < 0 )
return F_56 ( V_44 ) ;
return V_8 ;
}
static void F_57 ( struct V_6 * V_7 )
{
struct V_74 * V_59 ;
struct V_8 * V_9 = V_7 -> V_8 -> V_9 ;
struct V_85 * V_85 = F_58 ( V_9 ) ;
T_5 V_98 = F_5 ( V_7 ) ;
T_7 V_88 = F_59 ( V_9 ) -> V_99 ;
int V_44 ;
if ( V_98 == V_31 ) {
V_44 = F_60 ( F_58 ( V_9 ) , & V_7 -> V_100 ) ;
if ( V_44 )
F_61 ( L_4 ,
V_44 ) ;
}
F_62 () ;
F_63 (net, dev) {
if ( V_59 -> V_101 -> V_102 )
V_59 -> V_101 -> V_102 ( V_59 , V_98 ,
V_88 ) ;
}
F_64 () ;
}
static int F_65 ( struct V_25 * V_103 )
{
return sizeof( * V_103 ) + V_103 -> V_53 * 4 ;
}
static struct V_26 * * F_66 ( struct V_26 * * V_104 ,
struct V_26 * V_27 ,
struct V_105 * V_106 )
{
struct V_26 * V_107 , * * V_108 = NULL ;
struct V_25 * V_103 , * V_109 ;
unsigned int V_110 , V_111 , V_112 ;
const struct V_113 * V_114 ;
T_7 type ;
int V_115 = 1 ;
V_112 = F_67 ( V_27 ) ;
V_110 = V_112 + sizeof( * V_103 ) ;
V_103 = F_68 ( V_27 , V_112 ) ;
if ( F_69 ( V_27 , V_110 ) ) {
V_103 = F_70 ( V_27 , V_110 , V_112 ) ;
if ( F_30 ( ! V_103 ) )
goto V_116;
}
if ( V_103 -> V_81 != V_82 || V_103 -> V_49 )
goto V_116;
V_111 = F_65 ( V_103 ) ;
V_110 = V_112 + V_111 ;
if ( F_69 ( V_27 , V_110 ) ) {
V_103 = F_70 ( V_27 , V_110 , V_112 ) ;
if ( F_30 ( ! V_103 ) )
goto V_116;
}
for ( V_107 = * V_104 ; V_107 ; V_107 = V_107 -> V_117 ) {
if ( ! F_71 ( V_107 ) -> V_118 )
continue;
V_109 = (struct V_25 * ) ( V_107 -> V_119 + V_112 ) ;
if ( V_103 -> V_53 != V_109 -> V_53 ||
memcmp ( V_103 , V_109 , V_111 ) ) {
F_71 ( V_107 ) -> V_118 = 0 ;
continue;
}
}
type = V_103 -> V_83 ;
F_62 () ;
V_114 = F_72 ( type ) ;
if ( ! V_114 )
goto V_120;
F_73 ( V_27 , V_111 ) ;
F_74 ( V_27 , V_103 , V_111 ) ;
V_108 = V_114 -> V_121 . V_122 ( V_104 , V_27 ) ;
V_115 = 0 ;
V_120:
F_64 () ;
V_116:
F_71 ( V_27 ) -> V_115 |= V_115 ;
return V_108 ;
}
static int F_75 ( struct V_26 * V_27 , int V_123 ,
struct V_105 * V_106 )
{
struct V_25 * V_103 ;
struct V_113 * V_114 ;
T_7 type ;
int V_111 ;
int V_44 = - V_124 ;
V_103 = (struct V_25 * ) ( V_27 -> V_119 + V_123 ) ;
V_111 = F_65 ( V_103 ) ;
type = V_103 -> V_83 ;
F_62 () ;
V_114 = F_76 ( type ) ;
if ( V_114 )
V_44 = V_114 -> V_121 . V_125 ( V_27 , V_123 + V_111 ) ;
F_64 () ;
F_77 ( V_27 , V_123 + V_111 ) ;
return V_44 ;
}
static struct V_6 * F_78 ( struct V_85 * V_85 , T_7 V_88 ,
bool V_87 , T_8 V_46 )
{
struct V_126 * V_127 = F_79 ( V_85 , V_128 ) ;
struct V_6 * V_7 ;
struct V_86 * V_8 ;
struct V_129 V_130 ;
int V_131 ;
V_7 = F_80 ( sizeof( * V_7 ) , V_77 ) ;
if ( ! V_7 )
return F_56 ( - V_75 ) ;
V_8 = F_53 ( V_85 , V_87 , V_88 , V_46 ) ;
if ( F_81 ( V_8 ) ) {
F_82 ( V_7 ) ;
return F_83 ( V_8 ) ;
}
V_7 -> V_8 = V_8 ;
V_7 -> V_132 = 1 ;
for ( V_131 = 0 ; V_131 < V_133 ; ++ V_131 )
F_84 ( & V_7 -> V_17 [ V_131 ] ) ;
V_7 -> V_100 . V_88 = V_88 ;
V_7 -> V_100 . V_121 . V_122 = F_66 ;
V_7 -> V_100 . V_121 . V_125 = F_75 ;
F_57 ( V_7 ) ;
V_130 . V_134 = V_7 ;
V_130 . V_135 = 1 ;
V_130 . V_136 = F_46 ;
V_130 . V_137 = NULL ;
F_85 ( V_85 , V_8 , & V_130 ) ;
F_86 ( & V_7 -> V_138 , & V_127 -> V_139 ) ;
return V_7 ;
}
static void F_87 ( struct V_6 * V_7 )
{
struct V_74 * V_59 ;
struct V_8 * V_9 = V_7 -> V_8 -> V_9 ;
struct V_85 * V_85 = F_58 ( V_9 ) ;
T_5 V_98 = F_5 ( V_7 ) ;
T_7 V_88 = F_59 ( V_9 ) -> V_99 ;
F_62 () ;
F_63 (net, dev) {
if ( V_59 -> V_101 -> V_140 )
V_59 -> V_101 -> V_140 ( V_59 , V_98 ,
V_88 ) ;
}
F_64 () ;
if ( V_98 == V_31 )
F_88 ( & V_7 -> V_100 ) ;
}
static void F_89 ( struct V_6 * V_7 )
{
if ( ! V_7 || -- V_7 -> V_132 )
return;
F_90 ( & V_7 -> V_138 ) ;
F_87 ( V_7 ) ;
F_91 ( V_7 -> V_8 ) ;
F_92 ( V_7 , V_141 ) ;
}
static void F_93 ( struct V_11 * V_15 )
{
F_89 ( V_15 -> V_142 ) ;
#if F_13 ( V_29 )
F_89 ( V_15 -> V_143 ) ;
#endif
}
static struct V_6 * F_94 ( struct V_126 * V_127 ,
T_5 V_91 ,
T_7 V_144 )
{
struct V_6 * V_7 ;
F_95 (gs, &gn->sock_list, list) {
if ( F_59 ( V_7 -> V_8 -> V_9 ) -> V_99 == V_144 &&
F_5 ( V_7 ) == V_91 ) {
return V_7 ;
}
}
return NULL ;
}
static int F_96 ( struct V_11 * V_15 , bool V_87 )
{
struct V_85 * V_85 = V_15 -> V_85 ;
struct V_126 * V_127 = F_79 ( V_85 , V_128 ) ;
struct V_6 * V_7 ;
T_1 V_16 ;
V_7 = F_94 ( V_127 , V_87 ? V_36 : V_31 , V_15 -> V_144 ) ;
if ( V_7 ) {
V_7 -> V_132 ++ ;
goto V_116;
}
V_7 = F_78 ( V_85 , V_15 -> V_144 , V_87 , V_15 -> V_46 ) ;
if ( F_81 ( V_7 ) )
return F_97 ( V_7 ) ;
V_116:
V_7 -> V_34 = V_15 -> V_34 ;
V_7 -> V_46 = V_15 -> V_46 ;
#if F_13 ( V_29 )
if ( V_87 )
V_15 -> V_143 = V_7 ;
else
#endif
V_15 -> V_142 = V_7 ;
V_16 = F_1 ( V_15 -> V_1 ) ;
F_98 ( & V_15 -> V_145 , & V_7 -> V_17 [ V_16 ] ) ;
return 0 ;
}
static int F_99 ( struct V_74 * V_59 )
{
struct V_11 * V_15 = F_38 ( V_59 ) ;
bool V_87 = V_15 -> V_18 . V_146 . V_98 == V_36 ;
bool V_147 = V_15 -> V_34 ;
int V_148 = 0 ;
V_15 -> V_142 = NULL ;
#if F_13 ( V_29 )
V_15 -> V_143 = NULL ;
if ( V_87 || V_147 )
V_148 = F_96 ( V_15 , true ) ;
#endif
if ( ! V_148 && ( ! V_87 || V_147 ) )
V_148 = F_96 ( V_15 , false ) ;
if ( V_148 < 0 )
F_93 ( V_15 ) ;
return V_148 ;
}
static int F_100 ( struct V_74 * V_59 )
{
struct V_11 * V_15 = F_38 ( V_59 ) ;
if ( ! F_101 ( & V_15 -> V_145 ) )
F_102 ( & V_15 -> V_145 ) ;
F_93 ( V_15 ) ;
return 0 ;
}
static void F_103 ( struct V_25 * V_78 ,
T_7 V_149 , T_2 V_1 [ 3 ] ,
T_2 V_150 , T_2 * V_57 )
{
V_78 -> V_81 = V_82 ;
V_78 -> V_53 = V_150 / 4 ;
V_78 -> V_49 = ! ! ( V_149 & V_50 ) ;
V_78 -> V_51 = ! ! ( V_149 & V_52 ) ;
V_78 -> V_151 = 0 ;
memcpy ( V_78 -> V_1 , V_1 , 3 ) ;
V_78 -> V_83 = F_48 ( V_84 ) ;
V_78 -> V_152 = 0 ;
memcpy ( V_78 -> V_57 , V_57 , V_150 ) ;
}
static int F_104 ( struct V_153 * V_154 , struct V_26 * V_27 ,
T_7 V_149 , T_2 V_1 [ 3 ] , T_2 V_53 , T_2 * V_155 ,
T_8 V_46 , bool V_156 )
{
struct V_25 * V_39 ;
int V_157 ;
int V_44 ;
bool V_158 = ! ( V_46 & V_159 ) ;
F_105 ( V_27 , V_156 ) ;
V_157 = F_106 ( V_154 -> V_61 . V_59 ) + V_154 -> V_61 . V_160
+ V_80 + V_53 + sizeof( struct V_32 ) ;
V_44 = F_107 ( V_27 , V_157 ) ;
if ( F_30 ( V_44 ) ) {
F_36 ( V_27 ) ;
goto V_161;
}
V_27 = F_108 ( V_27 , V_158 ) ;
if ( F_81 ( V_27 ) ) {
V_44 = F_97 ( V_27 ) ;
goto V_161;
}
V_39 = (struct V_25 * ) F_109 ( V_27 , sizeof( * V_39 ) + V_53 ) ;
F_103 ( V_39 , V_149 , V_1 , V_53 , V_155 ) ;
F_110 ( V_27 , F_48 ( V_84 ) ) ;
return 0 ;
V_161:
F_111 ( V_154 ) ;
return V_44 ;
}
static int F_112 ( struct V_162 * V_61 , struct V_26 * V_27 ,
T_7 V_149 , T_2 V_1 [ 3 ] , T_2 V_53 , T_2 * V_155 ,
T_8 V_46 , bool V_156 )
{
struct V_25 * V_39 ;
int V_157 ;
int V_44 ;
bool V_158 = ! ( V_46 & V_163 ) ;
F_105 ( V_27 , V_156 ) ;
V_157 = F_106 ( V_61 -> V_59 ) + V_61 -> V_160
+ V_80 + V_53 + sizeof( struct V_37 ) ;
V_44 = F_107 ( V_27 , V_157 ) ;
if ( F_30 ( V_44 ) ) {
F_36 ( V_27 ) ;
goto V_164;
}
V_27 = F_108 ( V_27 , V_158 ) ;
if ( F_81 ( V_27 ) ) {
V_44 = F_97 ( V_27 ) ;
goto V_164;
}
V_39 = (struct V_25 * ) F_109 ( V_27 , sizeof( * V_39 ) + V_53 ) ;
F_103 ( V_39 , V_149 , V_1 , V_53 , V_155 ) ;
F_110 ( V_27 , F_48 ( V_84 ) ) ;
return 0 ;
V_164:
F_113 ( V_61 ) ;
return V_44 ;
}
static struct V_153 * F_114 ( struct V_26 * V_27 ,
struct V_74 * V_59 ,
struct V_165 * V_166 ,
struct V_167 * V_168 )
{
bool V_169 = F_115 ( V_27 , V_168 ) ;
struct V_11 * V_15 = F_38 ( V_59 ) ;
struct V_76 * V_76 ;
struct V_153 * V_154 = NULL ;
T_4 V_65 ;
memset ( V_166 , 0 , sizeof( * V_166 ) ) ;
V_166 -> V_170 = V_27 -> V_171 ;
V_166 -> V_172 = V_173 ;
if ( V_168 ) {
V_166 -> V_174 = V_168 -> V_175 . V_55 . V_176 . V_61 ;
V_166 -> V_35 = V_168 -> V_175 . V_55 . V_176 . V_177 ;
V_166 -> V_178 = F_116 ( V_168 -> V_175 . V_65 ) ;
V_76 = & V_168 -> V_76 ;
} else {
V_65 = V_15 -> V_65 ;
if ( V_65 == 1 ) {
const struct V_32 * V_179 = F_14 ( V_27 ) ;
V_65 = F_117 ( V_179 , V_27 ) ;
V_169 = false ;
}
V_166 -> V_178 = F_116 ( V_65 ) ;
V_166 -> V_174 = V_15 -> V_18 . sin . V_19 . V_20 ;
V_76 = & V_15 -> V_76 ;
}
if ( V_169 ) {
V_154 = F_118 ( V_76 , & V_166 -> V_35 ) ;
if ( V_154 )
return V_154 ;
}
V_154 = F_119 ( V_15 -> V_85 , V_166 ) ;
if ( F_81 ( V_154 ) ) {
F_120 ( V_59 , L_5 , & V_166 -> V_174 ) ;
return F_56 ( - V_180 ) ;
}
if ( V_154 -> V_61 . V_59 == V_59 ) {
F_120 ( V_59 , L_6 , & V_166 -> V_174 ) ;
F_111 ( V_154 ) ;
return F_56 ( - V_181 ) ;
}
if ( V_169 )
F_121 ( V_76 , & V_154 -> V_61 , V_166 -> V_35 ) ;
return V_154 ;
}
static struct V_162 * F_122 ( struct V_26 * V_27 ,
struct V_74 * V_59 ,
struct V_182 * V_183 ,
struct V_167 * V_168 )
{
bool V_169 = F_115 ( V_27 , V_168 ) ;
struct V_11 * V_15 = F_38 ( V_59 ) ;
struct V_6 * V_184 = V_15 -> V_143 ;
struct V_162 * V_61 = NULL ;
struct V_76 * V_76 ;
T_4 V_185 ;
memset ( V_183 , 0 , sizeof( * V_183 ) ) ;
V_183 -> V_186 = V_27 -> V_171 ;
V_183 -> V_187 = V_173 ;
if ( V_168 ) {
V_183 -> V_174 = V_168 -> V_175 . V_55 . V_87 . V_61 ;
V_183 -> V_35 = V_168 -> V_175 . V_55 . V_87 . V_177 ;
V_183 -> V_188 = F_123 ( F_116 ( V_168 -> V_175 . V_65 ) ,
V_168 -> V_175 . V_189 ) ;
V_76 = & V_168 -> V_76 ;
} else {
V_185 = V_15 -> V_65 ;
if ( V_185 == 1 ) {
const struct V_32 * V_179 = F_14 ( V_27 ) ;
V_185 = F_117 ( V_179 , V_27 ) ;
V_169 = false ;
}
V_183 -> V_188 = F_123 ( F_116 ( V_185 ) ,
V_15 -> V_189 ) ;
V_183 -> V_174 = V_15 -> V_18 . V_23 . V_24 ;
V_76 = & V_15 -> V_76 ;
}
if ( V_169 ) {
V_61 = F_124 ( V_76 , & V_183 -> V_35 ) ;
if ( V_61 )
return V_61 ;
}
if ( V_190 -> V_191 ( V_15 -> V_85 , V_184 -> V_8 -> V_9 , & V_61 , V_183 ) ) {
F_120 ( V_59 , L_7 , & V_183 -> V_174 ) ;
return F_56 ( - V_180 ) ;
}
if ( V_61 -> V_59 == V_59 ) {
F_120 ( V_59 , L_8 , & V_183 -> V_174 ) ;
F_113 ( V_61 ) ;
return F_56 ( - V_181 ) ;
}
if ( V_169 )
F_125 ( V_76 , V_61 , & V_183 -> V_35 ) ;
return V_61 ;
}
static void F_126 ( T_3 V_192 , T_4 * V_1 )
{
#ifdef F_4
V_1 [ 0 ] = ( V_4 T_4 ) ( V_192 >> 16 ) ;
V_1 [ 1 ] = ( V_4 T_4 ) ( V_192 >> 8 ) ;
V_1 [ 2 ] = ( V_4 T_4 ) V_192 ;
#else
V_1 [ 0 ] = ( V_4 T_4 ) ( ( V_4 V_5 ) V_192 >> 40 ) ;
V_1 [ 1 ] = ( V_4 T_4 ) ( ( V_4 V_5 ) V_192 >> 48 ) ;
V_1 [ 2 ] = ( V_4 T_4 ) ( ( V_4 V_5 ) V_192 >> 56 ) ;
#endif
}
static T_9 F_127 ( struct V_26 * V_27 , struct V_74 * V_59 ,
struct V_167 * V_168 )
{
struct V_11 * V_15 = F_38 ( V_59 ) ;
struct V_6 * V_193 = V_15 -> V_142 ;
struct V_153 * V_154 = NULL ;
const struct V_32 * V_179 ;
int V_44 = - V_194 ;
struct V_165 V_166 ;
T_4 V_65 , V_195 ;
T_7 V_196 ;
T_7 V_197 ;
bool V_156 = ! F_51 ( V_15 -> V_85 , F_52 ( V_15 -> V_59 ) ) ;
T_8 V_46 = V_15 -> V_46 ;
if ( V_15 -> V_34 ) {
if ( F_30 ( ! V_168 || ! ( V_168 -> V_198 & V_199 ) ) ) {
F_120 ( V_59 , L_9 ) ;
goto V_200;
}
if ( V_168 && F_128 ( V_168 ) != V_31 )
goto V_200;
}
V_154 = F_114 ( V_27 , V_59 , & V_166 , V_168 ) ;
if ( F_81 ( V_154 ) ) {
V_44 = F_97 ( V_154 ) ;
goto V_200;
}
V_196 = F_129 ( V_15 -> V_85 , V_27 , 1 , V_201 , true ) ;
F_20 ( V_27 ) ;
V_179 = F_14 ( V_27 ) ;
if ( V_168 ) {
const struct V_202 * V_175 = & V_168 -> V_175 ;
T_2 * V_203 = NULL ;
T_2 V_1 [ 3 ] ;
F_126 ( V_175 -> V_192 , V_1 ) ;
if ( V_168 -> V_150 )
V_203 = F_130 ( V_168 ) ;
if ( V_175 -> V_149 & V_204 )
V_46 &= ~ V_159 ;
else
V_46 |= V_159 ;
V_44 = F_104 ( V_154 , V_27 , V_175 -> V_149 , V_1 ,
V_168 -> V_150 , V_203 , V_46 , V_156 ) ;
if ( F_30 ( V_44 ) )
goto V_44;
V_65 = F_131 ( V_175 -> V_65 , V_179 , V_27 ) ;
V_195 = V_175 -> V_195 ;
V_197 = V_175 -> V_149 & V_205 ? F_48 ( V_206 ) : 0 ;
} else {
V_44 = F_104 ( V_154 , V_27 , 0 , V_15 -> V_1 ,
0 , NULL , V_46 , V_156 ) ;
if ( F_30 ( V_44 ) )
goto V_44;
V_65 = F_131 ( V_166 . V_178 , V_179 , V_27 ) ;
V_195 = V_15 -> V_195 ;
if ( ! V_195 && F_132 ( F_133 ( V_166 . V_174 ) ) )
V_195 = 1 ;
V_195 = V_195 ? : F_134 ( & V_154 -> V_61 ) ;
V_197 = 0 ;
}
F_135 ( V_154 , V_193 -> V_8 -> V_9 , V_27 , V_166 . V_35 , V_166 . V_174 ,
V_65 , V_195 , V_197 , V_196 , V_15 -> V_144 ,
! F_51 ( V_15 -> V_85 , F_52 ( V_15 -> V_59 ) ) ,
! ! ( V_46 & V_159 ) ) ;
return V_207 ;
V_200:
F_136 ( V_27 ) ;
V_44:
if ( V_44 == - V_181 )
V_59 -> V_43 . V_208 ++ ;
else if ( V_44 == - V_180 )
V_59 -> V_43 . V_209 ++ ;
else
V_59 -> V_43 . V_210 ++ ;
return V_207 ;
}
static T_9 F_137 ( struct V_26 * V_27 , struct V_74 * V_59 ,
struct V_167 * V_168 )
{
struct V_11 * V_15 = F_38 ( V_59 ) ;
struct V_6 * V_184 = V_15 -> V_143 ;
struct V_162 * V_61 = NULL ;
const struct V_32 * V_179 ;
int V_44 = - V_194 ;
struct V_182 V_183 ;
T_4 V_185 , V_195 ;
T_7 V_196 ;
T_6 V_189 ;
bool V_156 = ! F_51 ( V_15 -> V_85 , F_52 ( V_15 -> V_59 ) ) ;
T_8 V_46 = V_15 -> V_46 ;
if ( V_15 -> V_34 ) {
if ( F_30 ( ! V_168 || ! ( V_168 -> V_198 & V_199 ) ) ) {
F_120 ( V_59 , L_9 ) ;
goto V_200;
}
}
V_61 = F_122 ( V_27 , V_59 , & V_183 , V_168 ) ;
if ( F_81 ( V_61 ) ) {
V_44 = F_97 ( V_61 ) ;
goto V_200;
}
V_196 = F_129 ( V_15 -> V_85 , V_27 , 1 , V_201 , true ) ;
F_20 ( V_27 ) ;
V_179 = F_14 ( V_27 ) ;
if ( V_168 ) {
const struct V_202 * V_175 = & V_168 -> V_175 ;
T_2 * V_203 = NULL ;
T_2 V_1 [ 3 ] ;
F_126 ( V_175 -> V_192 , V_1 ) ;
if ( V_168 -> V_150 )
V_203 = F_130 ( V_168 ) ;
if ( V_175 -> V_149 & V_204 )
V_46 &= ~ V_163 ;
else
V_46 |= V_163 ;
V_44 = F_112 ( V_61 , V_27 , V_175 -> V_149 , V_1 ,
V_168 -> V_150 , V_203 ,
V_46 , V_156 ) ;
if ( F_30 ( V_44 ) )
goto V_44;
V_185 = F_131 ( V_175 -> V_65 , V_179 , V_27 ) ;
V_195 = V_175 -> V_195 ;
V_189 = V_168 -> V_175 . V_189 ;
} else {
V_44 = F_112 ( V_61 , V_27 , 0 , V_15 -> V_1 ,
0 , NULL , V_46 , V_156 ) ;
if ( F_30 ( V_44 ) )
goto V_44;
V_185 = F_131 ( F_138 ( V_183 . V_188 ) ,
V_179 , V_27 ) ;
V_195 = V_15 -> V_195 ;
if ( ! V_195 && F_139 ( & V_183 . V_174 ) )
V_195 = 1 ;
V_195 = V_195 ? : F_140 ( V_61 ) ;
V_189 = V_15 -> V_189 ;
}
F_141 ( V_61 , V_184 -> V_8 -> V_9 , V_27 , V_59 ,
& V_183 . V_35 , & V_183 . V_174 , V_185 , V_195 , V_189 ,
V_196 , V_15 -> V_144 ,
! ! ( V_46 & V_163 ) ) ;
return V_207 ;
V_200:
F_136 ( V_27 ) ;
V_44:
if ( V_44 == - V_181 )
V_59 -> V_43 . V_208 ++ ;
else if ( V_44 == - V_180 )
V_59 -> V_43 . V_209 ++ ;
else
V_59 -> V_43 . V_210 ++ ;
return V_207 ;
}
static T_9 F_142 ( struct V_26 * V_27 , struct V_74 * V_59 )
{
struct V_11 * V_15 = F_38 ( V_59 ) ;
struct V_167 * V_168 = NULL ;
if ( V_15 -> V_34 )
V_168 = F_143 ( V_27 ) ;
#if F_13 ( V_29 )
if ( ( V_168 && F_128 ( V_168 ) == V_36 ) ||
( ! V_168 && V_15 -> V_18 . V_146 . V_98 == V_36 ) )
return F_137 ( V_27 , V_59 , V_168 ) ;
#endif
return F_127 ( V_27 , V_59 , V_168 ) ;
}
static int F_144 ( struct V_74 * V_59 , int V_211 , bool V_212 )
{
int V_213 = V_214 - V_80 - sizeof( struct V_32 )
- V_59 -> V_215 ;
if ( V_211 < 68 )
return - V_194 ;
if ( V_211 > V_213 ) {
if ( V_212 )
return - V_194 ;
V_211 = V_213 ;
}
V_59 -> V_216 = V_211 ;
return 0 ;
}
static int F_145 ( struct V_74 * V_59 , int V_211 )
{
return F_144 ( V_59 , V_211 , true ) ;
}
static int F_146 ( struct V_74 * V_59 , struct V_26 * V_27 )
{
struct V_167 * V_168 = F_143 ( V_27 ) ;
struct V_11 * V_15 = F_38 ( V_59 ) ;
struct V_153 * V_154 ;
struct V_165 V_166 ;
#if F_13 ( V_29 )
struct V_162 * V_61 ;
struct V_182 V_183 ;
#endif
if ( F_128 ( V_168 ) == V_31 ) {
V_154 = F_114 ( V_27 , V_59 , & V_166 , V_168 ) ;
if ( F_81 ( V_154 ) )
return F_97 ( V_154 ) ;
F_111 ( V_154 ) ;
V_168 -> V_175 . V_55 . V_176 . V_177 = V_166 . V_35 ;
#if F_13 ( V_29 )
} else if ( F_128 ( V_168 ) == V_36 ) {
V_61 = F_122 ( V_27 , V_59 , & V_183 , V_168 ) ;
if ( F_81 ( V_61 ) )
return F_97 ( V_61 ) ;
F_113 ( V_61 ) ;
V_168 -> V_175 . V_55 . V_87 . V_177 = V_183 . V_35 ;
#endif
} else {
return - V_194 ;
}
V_168 -> V_175 . V_217 = F_129 ( V_15 -> V_85 , V_27 ,
1 , V_201 , true ) ;
V_168 -> V_175 . V_218 = V_15 -> V_144 ;
return 0 ;
}
static void F_147 ( struct V_74 * V_59 ,
struct V_219 * V_220 )
{
F_148 ( V_220 -> V_221 , V_222 , sizeof( V_220 -> V_221 ) ) ;
F_148 ( V_220 -> V_223 , L_10 , sizeof( V_220 -> V_223 ) ) ;
}
void F_149 ( struct V_74 * V_59 )
{
struct V_85 * V_85 = F_52 ( V_59 ) ;
struct V_126 * V_127 = F_79 ( V_85 , V_128 ) ;
struct V_6 * V_7 ;
T_5 V_98 ;
struct V_8 * V_9 ;
T_7 V_88 ;
F_62 () ;
F_150 (gs, &gn->sock_list, list) {
V_9 = V_7 -> V_8 -> V_9 ;
V_98 = V_9 -> V_10 ;
V_88 = F_59 ( V_9 ) -> V_99 ;
V_59 -> V_101 -> V_102 ( V_59 , V_98 , V_88 ) ;
}
F_64 () ;
}
static void F_151 ( struct V_74 * V_59 )
{
F_152 ( V_59 ) ;
V_59 -> V_101 = & V_224 ;
V_59 -> V_225 = & V_226 ;
V_59 -> V_227 = V_228 ;
F_153 ( V_59 , & V_229 ) ;
V_59 -> V_230 |= V_231 ;
V_59 -> V_230 |= V_232 | V_233 ;
V_59 -> V_230 |= V_234 ;
V_59 -> V_230 |= V_235 ;
V_59 -> V_236 |= V_232 | V_233 | V_234 ;
V_59 -> V_236 |= V_235 ;
F_154 ( V_59 ) ;
V_59 -> V_237 &= ~ V_238 ;
V_59 -> V_237 |= V_239 | V_240 ;
F_155 ( V_59 ) ;
}
static int F_156 ( struct V_241 * V_242 [] , struct V_241 * V_119 [] )
{
if ( V_242 [ V_243 ] ) {
if ( F_157 ( V_242 [ V_243 ] ) != V_244 )
return - V_194 ;
if ( ! F_158 ( F_159 ( V_242 [ V_243 ] ) ) )
return - V_245 ;
}
if ( ! V_119 )
return - V_194 ;
if ( V_119 [ V_246 ] ) {
T_1 V_1 = F_160 ( V_119 [ V_246 ] ) ;
if ( V_1 >= V_247 )
return - V_248 ;
}
return 0 ;
}
static struct V_11 * F_161 ( struct V_126 * V_127 ,
T_7 V_144 ,
union V_249 * V_18 ,
T_2 V_1 [] ,
bool * V_250 ,
bool * V_251 )
{
struct V_11 * V_15 , * V_252 ;
* V_250 = false ;
* V_251 = false ;
V_252 = NULL ;
F_95 (geneve, &gn->geneve_list, next) {
if ( V_15 -> V_144 == V_144 ) {
* V_251 = V_15 -> V_34 ;
* V_250 = true ;
}
if ( ! memcmp ( V_1 , V_15 -> V_1 , sizeof( V_15 -> V_1 ) ) &&
! memcmp ( V_18 , & V_15 -> V_18 , sizeof( V_15 -> V_18 ) ) &&
V_144 == V_15 -> V_144 )
V_252 = V_15 ;
}
return V_252 ;
}
static int F_162 ( struct V_85 * V_85 , struct V_74 * V_59 ,
union V_249 * V_18 ,
T_1 V_1 , T_4 V_195 , T_4 V_65 , T_6 V_189 ,
T_7 V_144 , bool V_147 , T_8 V_46 )
{
struct V_126 * V_127 = F_79 ( V_85 , V_128 ) ;
struct V_11 * V_252 , * V_15 = F_38 ( V_59 ) ;
bool V_251 , V_250 ;
int V_44 , V_253 ;
if ( ! V_18 )
return - V_194 ;
if ( V_147 &&
( V_18 -> V_146 . V_98 != V_254 || V_1 || V_65 || V_195 || V_189 ) )
return - V_194 ;
V_15 -> V_85 = V_85 ;
V_15 -> V_59 = V_59 ;
V_15 -> V_1 [ 0 ] = ( V_1 & 0x00ff0000 ) >> 16 ;
V_15 -> V_1 [ 1 ] = ( V_1 & 0x0000ff00 ) >> 8 ;
V_15 -> V_1 [ 2 ] = V_1 & 0x000000ff ;
if ( ( V_18 -> V_146 . V_98 == V_31 &&
F_132 ( F_133 ( V_18 -> sin . V_19 . V_20 ) ) ) ||
( V_18 -> V_146 . V_98 == V_36 &&
F_139 ( & V_18 -> V_23 . V_24 ) ) )
return - V_194 ;
if ( V_189 && V_18 -> V_146 . V_98 != V_36 )
return - V_194 ;
V_15 -> V_18 = * V_18 ;
V_15 -> V_195 = V_195 ;
V_15 -> V_65 = V_65 ;
V_15 -> V_189 = V_189 ;
V_15 -> V_144 = V_144 ;
V_15 -> V_34 = V_147 ;
V_15 -> V_46 = V_46 ;
V_252 = F_161 ( V_127 , V_144 , V_18 , V_15 -> V_1 ,
& V_250 , & V_251 ) ;
if ( V_252 )
return - V_255 ;
V_253 = V_80 + V_60 ;
if ( V_18 -> V_146 . V_98 == V_31 )
V_253 += sizeof( struct V_32 ) ;
else
V_253 += sizeof( struct V_37 ) ;
V_59 -> V_256 = V_253 + V_60 ;
if ( V_147 ) {
if ( V_250 )
return - V_257 ;
} else {
if ( V_251 )
return - V_257 ;
}
F_163 ( & V_15 -> V_76 ) ;
V_44 = F_164 ( V_59 ) ;
if ( V_44 )
return V_44 ;
F_86 ( & V_15 -> V_117 , & V_127 -> V_258 ) ;
return 0 ;
}
static int F_165 ( struct V_85 * V_85 , struct V_74 * V_59 ,
struct V_241 * V_242 [] , struct V_241 * V_119 [] )
{
T_7 V_144 = F_48 ( V_259 ) ;
T_4 V_195 = 0 , V_65 = 0 ;
bool V_147 = false ;
union V_249 V_18 = V_260 ;
T_6 V_189 = 0 ;
T_1 V_1 = 0 ;
T_8 V_46 = 0 ;
if ( V_119 [ V_261 ] && V_119 [ V_262 ] )
return - V_194 ;
if ( V_119 [ V_261 ] ) {
V_18 . V_146 . V_98 = V_31 ;
V_18 . sin . V_19 . V_20 =
F_166 ( V_119 [ V_261 ] ) ;
}
if ( V_119 [ V_262 ] ) {
if ( ! F_13 ( V_29 ) )
return - V_263 ;
V_18 . V_146 . V_98 = V_36 ;
V_18 . V_23 . V_24 =
F_167 ( V_119 [ V_262 ] ) ;
if ( F_168 ( & V_18 . V_23 . V_24 ) &
V_264 ) {
F_120 ( V_59 , L_11 ) ;
return - V_194 ;
}
}
if ( V_119 [ V_246 ] )
V_1 = F_160 ( V_119 [ V_246 ] ) ;
if ( V_119 [ V_265 ] )
V_195 = F_169 ( V_119 [ V_265 ] ) ;
if ( V_119 [ V_266 ] )
V_65 = F_169 ( V_119 [ V_266 ] ) ;
if ( V_119 [ V_267 ] )
V_189 = F_170 ( V_119 [ V_267 ] ) &
V_268 ;
if ( V_119 [ V_269 ] )
V_144 = F_171 ( V_119 [ V_269 ] ) ;
if ( V_119 [ V_270 ] )
V_147 = true ;
if ( V_119 [ V_271 ] &&
! F_169 ( V_119 [ V_271 ] ) )
V_46 |= V_159 ;
if ( V_119 [ V_272 ] &&
F_169 ( V_119 [ V_272 ] ) )
V_46 |= V_163 ;
if ( V_119 [ V_273 ] &&
F_169 ( V_119 [ V_273 ] ) )
V_46 |= V_94 ;
return F_162 ( V_85 , V_59 , & V_18 , V_1 , V_195 , V_65 , V_189 ,
V_144 , V_147 , V_46 ) ;
}
static void F_172 ( struct V_74 * V_59 , struct V_274 * V_104 )
{
struct V_11 * V_15 = F_38 ( V_59 ) ;
F_90 ( & V_15 -> V_117 ) ;
F_173 ( V_59 , V_104 ) ;
}
static T_10 F_174 ( const struct V_74 * V_59 )
{
return F_175 ( sizeof( T_1 ) ) +
F_175 ( sizeof( struct V_21 ) ) +
F_175 ( sizeof( T_4 ) ) +
F_175 ( sizeof( T_4 ) ) +
F_175 ( sizeof( T_6 ) ) +
F_175 ( sizeof( T_7 ) ) +
F_175 ( 0 ) +
F_175 ( sizeof( T_4 ) ) +
F_175 ( sizeof( T_4 ) ) +
F_175 ( sizeof( T_4 ) ) +
0 ;
}
static int F_176 ( struct V_26 * V_27 , const struct V_74 * V_59 )
{
struct V_11 * V_15 = F_38 ( V_59 ) ;
T_1 V_1 ;
V_1 = ( V_15 -> V_1 [ 0 ] << 16 ) | ( V_15 -> V_1 [ 1 ] << 8 ) | V_15 -> V_1 [ 2 ] ;
if ( F_177 ( V_27 , V_246 , V_1 ) )
goto V_275;
if ( V_15 -> V_18 . V_146 . V_98 == V_31 ) {
if ( F_178 ( V_27 , V_261 ,
V_15 -> V_18 . sin . V_19 . V_20 ) )
goto V_275;
#if F_13 ( V_29 )
} else {
if ( F_179 ( V_27 , V_262 ,
& V_15 -> V_18 . V_23 . V_24 ) )
goto V_275;
#endif
}
if ( F_180 ( V_27 , V_265 , V_15 -> V_195 ) ||
F_180 ( V_27 , V_266 , V_15 -> V_65 ) ||
F_181 ( V_27 , V_267 , V_15 -> V_189 ) )
goto V_275;
if ( F_182 ( V_27 , V_269 , V_15 -> V_144 ) )
goto V_275;
if ( V_15 -> V_34 ) {
if ( F_183 ( V_27 , V_270 ) )
goto V_275;
}
if ( F_180 ( V_27 , V_271 ,
! ( V_15 -> V_46 & V_159 ) ) ||
F_180 ( V_27 , V_272 ,
! ! ( V_15 -> V_46 & V_163 ) ) ||
F_180 ( V_27 , V_273 ,
! ! ( V_15 -> V_46 & V_94 ) ) )
goto V_275;
return 0 ;
V_275:
return - V_276 ;
}
struct V_74 * F_184 ( struct V_85 * V_85 , const char * V_277 ,
T_2 V_278 , T_11 V_144 )
{
struct V_241 * V_242 [ V_279 + 1 ] ;
struct V_74 * V_59 ;
int V_44 ;
memset ( V_242 , 0 , sizeof( V_242 ) ) ;
V_59 = F_185 ( V_85 , V_277 , V_278 ,
& V_280 , V_242 ) ;
if ( F_81 ( V_59 ) )
return V_59 ;
V_44 = F_162 ( V_85 , V_59 , & V_260 ,
0 , 0 , 0 , 0 , F_48 ( V_144 ) , true ,
V_94 ) ;
if ( V_44 )
goto V_44;
V_44 = F_144 ( V_59 , V_214 , false ) ;
if ( V_44 )
goto V_44;
return V_59 ;
V_44:
V_228 ( V_59 ) ;
return F_56 ( V_44 ) ;
}
static T_12 int F_186 ( struct V_85 * V_85 )
{
struct V_126 * V_127 = F_79 ( V_85 , V_128 ) ;
F_187 ( & V_127 -> V_258 ) ;
F_187 ( & V_127 -> V_139 ) ;
return 0 ;
}
static void T_13 F_188 ( struct V_85 * V_85 )
{
struct V_126 * V_127 = F_79 ( V_85 , V_128 ) ;
struct V_11 * V_15 , * V_117 ;
struct V_74 * V_59 , * V_281 ;
F_189 ( V_138 ) ;
F_190 () ;
F_191 (net, dev, aux)
if ( V_59 -> V_282 == & V_280 )
F_173 ( V_59 , & V_138 ) ;
F_192 (geneve, next, &gn->geneve_list, next) {
if ( ! F_51 ( F_52 ( V_15 -> V_59 ) , V_85 ) )
F_173 ( V_15 -> V_59 , & V_138 ) ;
}
F_193 ( & V_138 ) ;
F_194 () ;
}
static int T_14 F_195 ( void )
{
int V_283 ;
V_283 = F_196 ( & V_284 ) ;
if ( V_283 )
goto V_285;
V_283 = F_197 ( & V_280 ) ;
if ( V_283 )
goto V_286;
return 0 ;
V_286:
F_198 ( & V_284 ) ;
V_285:
return V_283 ;
}
static void T_15 F_199 ( void )
{
F_200 ( & V_280 ) ;
F_198 ( & V_284 ) ;
}
