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
V_9 == V_12 -> V_15 . sin . V_16 . V_17 )
return V_12 ;
}
return NULL ;
}
static struct V_6 * F_7 ( struct V_7 * V_8 ,
struct V_18 V_19 , T_2 V_1 [] )
{
struct V_10 * V_11 ;
struct V_6 * V_12 ;
T_1 V_13 ;
V_13 = F_1 ( V_1 ) ;
V_11 = & V_8 -> V_14 [ V_13 ] ;
F_6 (geneve, vni_list_head, hlist) {
if ( ! memcmp ( V_1 , V_12 -> V_1 , sizeof( V_12 -> V_1 ) ) &&
F_8 ( & V_19 , & V_12 -> V_15 . V_20 . V_21 ) )
return V_12 ;
}
return NULL ;
}
static inline struct V_22 * F_9 ( const struct V_23 * V_24 )
{
return (struct V_22 * ) ( F_10 ( V_24 ) + 1 ) ;
}
static void F_11 ( struct V_7 * V_8 , struct V_23 * V_24 )
{
struct V_22 * V_25 = F_9 ( V_24 ) ;
struct V_26 * V_27 = NULL ;
struct V_6 * V_12 = NULL ;
struct V_28 * V_29 ;
struct V_30 * V_31 = NULL ;
T_5 V_9 ;
static T_2 V_32 [ 3 ] ;
T_2 * V_1 ;
int V_33 = 0 ;
T_6 V_34 ;
#if F_12 ( V_35 )
struct V_36 * V_37 = NULL ;
struct V_18 V_19 ;
static struct V_18 V_38 ;
#endif
V_34 = V_8 -> V_39 -> V_40 -> V_41 ;
if ( V_34 == V_42 ) {
V_31 = F_13 ( V_24 ) ;
if ( V_8 -> V_43 ) {
V_1 = V_32 ;
V_9 = 0 ;
} else {
V_1 = V_25 -> V_1 ;
V_9 = V_31 -> V_44 ;
}
V_12 = F_5 ( V_8 , V_9 , V_1 ) ;
#if F_12 ( V_35 )
} else if ( V_34 == V_45 ) {
V_37 = F_14 ( V_24 ) ;
if ( V_8 -> V_43 ) {
V_1 = V_32 ;
V_19 = V_38 ;
} else {
V_1 = V_25 -> V_1 ;
V_19 = V_37 -> V_44 ;
}
V_12 = F_7 ( V_8 , V_19 , V_1 ) ;
#endif
}
if ( ! V_12 )
goto V_46;
if ( F_15 () || V_8 -> V_43 ) {
T_7 V_47 ;
V_47 = V_48 | V_49 |
( V_25 -> V_50 ? V_51 : 0 ) |
( V_25 -> V_52 ? V_53 : 0 ) ;
V_27 = F_16 ( V_24 , V_34 , V_47 ,
F_3 ( V_25 -> V_1 ) ,
V_25 -> V_54 * 4 ) ;
if ( ! V_27 )
goto V_46;
F_17 ( & V_27 -> V_55 . V_56 ,
V_25 -> V_57 , V_25 -> V_54 * 4 ) ;
} else {
if ( V_25 -> V_52 )
goto V_46;
}
F_18 ( V_24 ) ;
F_19 ( V_24 , ! F_20 ( V_12 -> V_58 , F_21 ( V_12 -> V_59 ) ) ) ;
V_24 -> V_60 = F_22 ( V_24 , V_12 -> V_59 ) ;
F_23 ( V_24 , F_24 ( V_24 ) , V_61 ) ;
if ( V_27 )
F_25 ( V_24 , & V_27 -> V_62 ) ;
if ( F_26 ( F_24 ( V_24 ) -> V_63 , V_12 -> V_59 -> V_64 ) )
goto V_46;
F_27 ( V_24 ) ;
if ( V_31 )
V_33 = F_28 ( V_31 , V_24 ) ;
#if F_12 ( V_35 )
if ( V_37 )
V_33 = F_29 ( V_37 , V_24 ) ;
#endif
if ( F_30 ( V_33 ) ) {
if ( V_65 ) {
if ( V_31 )
F_31 ( L_1
L_2 ,
& V_31 -> V_44 , V_31 -> V_66 ) ;
#if F_12 ( V_35 )
if ( V_37 )
F_31 ( L_3 ,
& V_37 -> V_44 ) ;
#endif
}
if ( V_33 > 1 ) {
++ V_12 -> V_59 -> V_29 . V_67 ;
++ V_12 -> V_59 -> V_29 . V_68 ;
goto V_46;
}
}
V_29 = F_32 ( V_12 -> V_59 -> V_69 ) ;
F_33 ( & V_29 -> V_70 ) ;
V_29 -> V_71 ++ ;
V_29 -> V_72 += V_24 -> V_73 ;
F_34 ( & V_29 -> V_70 ) ;
F_35 ( & V_12 -> V_74 , V_24 ) ;
return;
V_46:
F_36 ( V_24 ) ;
}
static int F_37 ( struct V_75 * V_59 )
{
struct V_6 * V_12 = F_38 ( V_59 ) ;
int V_33 ;
V_59 -> V_69 = F_39 ( struct V_28 ) ;
if ( ! V_59 -> V_69 )
return - V_76 ;
V_33 = F_40 ( & V_12 -> V_74 , V_59 ) ;
if ( V_33 ) {
F_41 ( V_59 -> V_69 ) ;
return V_33 ;
}
return 0 ;
}
static void F_42 ( struct V_75 * V_59 )
{
struct V_6 * V_12 = F_38 ( V_59 ) ;
F_43 ( & V_12 -> V_74 ) ;
F_41 ( V_59 -> V_69 ) ;
}
static int F_44 ( struct V_39 * V_40 , struct V_23 * V_24 )
{
struct V_22 * V_77 ;
struct V_7 * V_8 ;
int V_78 ;
if ( F_30 ( ! F_45 ( V_24 , V_79 ) ) )
goto error;
V_77 = F_9 ( V_24 ) ;
if ( F_30 ( V_77 -> V_80 != V_81 ) )
goto error;
if ( F_30 ( V_77 -> V_82 != F_46 ( V_83 ) ) )
goto error;
V_78 = V_77 -> V_54 * 4 ;
if ( F_47 ( V_24 , V_79 + V_78 ,
F_46 ( V_83 ) ) )
goto V_46;
V_8 = F_48 ( V_40 ) ;
if ( ! V_8 )
goto V_46;
F_11 ( V_8 , V_24 ) ;
return 0 ;
V_46:
F_36 ( V_24 ) ;
return 0 ;
error:
return 1 ;
}
static struct V_84 * F_49 ( struct V_58 * V_58 , bool V_85 ,
T_7 V_86 , T_8 V_47 )
{
struct V_84 * V_39 ;
struct V_87 V_88 ;
int V_33 ;
memset ( & V_88 , 0 , sizeof( V_88 ) ) ;
if ( V_85 ) {
V_88 . V_89 = V_45 ;
V_88 . V_90 = 1 ;
V_88 . V_91 =
! ( V_47 & V_92 ) ;
} else {
V_88 . V_89 = V_42 ;
V_88 . V_93 . V_17 = F_50 ( V_94 ) ;
}
V_88 . V_95 = V_86 ;
V_33 = F_51 ( V_58 , & V_88 , & V_39 ) ;
if ( V_33 < 0 )
return F_52 ( V_33 ) ;
return V_39 ;
}
static void F_53 ( struct V_7 * V_8 )
{
struct V_75 * V_59 ;
struct V_39 * V_40 = V_8 -> V_39 -> V_40 ;
struct V_58 * V_58 = F_54 ( V_40 ) ;
T_6 V_34 = V_40 -> V_41 ;
T_7 V_86 = F_55 ( V_40 ) -> V_96 ;
int V_33 ;
if ( V_34 == V_42 ) {
V_33 = F_56 ( F_54 ( V_40 ) , & V_8 -> V_97 ) ;
if ( V_33 )
F_57 ( L_4 ,
V_33 ) ;
}
F_58 () ;
F_59 (net, dev) {
if ( V_59 -> V_98 -> V_99 )
V_59 -> V_98 -> V_99 ( V_59 , V_34 ,
V_86 ) ;
}
F_60 () ;
}
static int F_61 ( struct V_22 * V_100 )
{
return sizeof( * V_100 ) + V_100 -> V_54 * 4 ;
}
static struct V_23 * * F_62 ( struct V_23 * * V_101 ,
struct V_23 * V_24 ,
struct V_102 * V_103 )
{
struct V_23 * V_104 , * * V_105 = NULL ;
struct V_22 * V_100 , * V_106 ;
unsigned int V_107 , V_108 , V_109 ;
const struct V_110 * V_111 ;
T_7 type ;
int V_112 = 1 ;
V_109 = F_63 ( V_24 ) ;
V_107 = V_109 + sizeof( * V_100 ) ;
V_100 = F_64 ( V_24 , V_109 ) ;
if ( F_65 ( V_24 , V_107 ) ) {
V_100 = F_66 ( V_24 , V_107 , V_109 ) ;
if ( F_30 ( ! V_100 ) )
goto V_113;
}
if ( V_100 -> V_80 != V_81 || V_100 -> V_50 )
goto V_113;
V_108 = F_61 ( V_100 ) ;
V_107 = V_109 + V_108 ;
if ( F_65 ( V_24 , V_107 ) ) {
V_100 = F_66 ( V_24 , V_107 , V_109 ) ;
if ( F_30 ( ! V_100 ) )
goto V_113;
}
V_112 = 0 ;
for ( V_104 = * V_101 ; V_104 ; V_104 = V_104 -> V_114 ) {
if ( ! F_67 ( V_104 ) -> V_115 )
continue;
V_106 = (struct V_22 * ) ( V_104 -> V_116 + V_109 ) ;
if ( V_100 -> V_54 != V_106 -> V_54 ||
memcmp ( V_100 , V_106 , V_108 ) ) {
F_67 ( V_104 ) -> V_115 = 0 ;
continue;
}
}
type = V_100 -> V_82 ;
F_58 () ;
V_111 = F_68 ( type ) ;
if ( ! V_111 ) {
V_112 = 1 ;
goto V_117;
}
F_69 ( V_24 , V_108 ) ;
F_70 ( V_24 , V_100 , V_108 ) ;
V_105 = V_111 -> V_118 . V_119 ( V_101 , V_24 ) ;
V_117:
F_60 () ;
V_113:
F_67 ( V_24 ) -> V_112 |= V_112 ;
return V_105 ;
}
static int F_71 ( struct V_23 * V_24 , int V_120 ,
struct V_102 * V_103 )
{
struct V_22 * V_100 ;
struct V_110 * V_111 ;
T_7 type ;
int V_108 ;
int V_33 = - V_121 ;
F_72 ( V_24 , V_120 ) ;
V_100 = (struct V_22 * ) ( V_24 -> V_116 + V_120 ) ;
V_108 = F_61 ( V_100 ) ;
type = V_100 -> V_82 ;
F_58 () ;
V_111 = F_73 ( type ) ;
if ( V_111 )
V_33 = V_111 -> V_118 . V_122 ( V_24 , V_120 + V_108 ) ;
F_60 () ;
return V_33 ;
}
static struct V_7 * F_74 ( struct V_58 * V_58 , T_7 V_86 ,
bool V_85 , T_8 V_47 )
{
struct V_123 * V_124 = F_75 ( V_58 , V_125 ) ;
struct V_7 * V_8 ;
struct V_84 * V_39 ;
struct V_126 V_127 ;
int V_128 ;
V_8 = F_76 ( sizeof( * V_8 ) , V_129 ) ;
if ( ! V_8 )
return F_52 ( - V_76 ) ;
V_39 = F_49 ( V_58 , V_85 , V_86 , V_47 ) ;
if ( F_77 ( V_39 ) ) {
F_78 ( V_8 ) ;
return F_79 ( V_39 ) ;
}
V_8 -> V_39 = V_39 ;
V_8 -> V_130 = 1 ;
for ( V_128 = 0 ; V_128 < V_131 ; ++ V_128 )
F_80 ( & V_8 -> V_14 [ V_128 ] ) ;
V_8 -> V_97 . V_86 = V_86 ;
V_8 -> V_97 . V_118 . V_119 = F_62 ;
V_8 -> V_97 . V_118 . V_122 = F_71 ;
F_53 ( V_8 ) ;
V_127 . V_132 = V_8 ;
V_127 . V_133 = 1 ;
V_127 . V_134 = F_44 ;
V_127 . V_135 = NULL ;
F_81 ( V_58 , V_39 , & V_127 ) ;
F_82 ( & V_8 -> V_136 , & V_124 -> V_137 ) ;
return V_8 ;
}
static void F_83 ( struct V_7 * V_8 )
{
struct V_75 * V_59 ;
struct V_39 * V_40 = V_8 -> V_39 -> V_40 ;
struct V_58 * V_58 = F_54 ( V_40 ) ;
T_6 V_34 = V_40 -> V_41 ;
T_7 V_86 = F_55 ( V_40 ) -> V_96 ;
F_58 () ;
F_59 (net, dev) {
if ( V_59 -> V_98 -> V_138 )
V_59 -> V_98 -> V_138 ( V_59 , V_34 ,
V_86 ) ;
}
F_60 () ;
if ( V_34 == V_42 )
F_84 ( & V_8 -> V_97 ) ;
}
static void F_85 ( struct V_7 * V_8 )
{
if ( ! V_8 || -- V_8 -> V_130 )
return;
F_86 ( & V_8 -> V_136 ) ;
F_83 ( V_8 ) ;
F_87 ( V_8 -> V_39 ) ;
F_88 ( V_8 , V_139 ) ;
}
static void F_89 ( struct V_6 * V_12 )
{
F_85 ( V_12 -> V_140 ) ;
#if F_12 ( V_35 )
F_85 ( V_12 -> V_141 ) ;
#endif
}
static struct V_7 * F_90 ( struct V_123 * V_124 ,
T_6 V_89 ,
T_7 V_142 )
{
struct V_7 * V_8 ;
F_91 (gs, &gn->sock_list, list) {
if ( F_55 ( V_8 -> V_39 -> V_40 ) -> V_96 == V_142 &&
F_55 ( V_8 -> V_39 -> V_40 ) -> V_40 . V_41 == V_89 ) {
return V_8 ;
}
}
return NULL ;
}
static int F_92 ( struct V_6 * V_12 , bool V_85 )
{
struct V_58 * V_58 = V_12 -> V_58 ;
struct V_123 * V_124 = F_75 ( V_58 , V_125 ) ;
struct V_7 * V_8 ;
T_1 V_13 ;
V_8 = F_90 ( V_124 , V_85 ? V_45 : V_42 , V_12 -> V_142 ) ;
if ( V_8 ) {
V_8 -> V_130 ++ ;
goto V_113;
}
V_8 = F_74 ( V_58 , V_12 -> V_142 , V_85 , V_12 -> V_47 ) ;
if ( F_77 ( V_8 ) )
return F_93 ( V_8 ) ;
V_113:
V_8 -> V_43 = V_12 -> V_43 ;
V_8 -> V_47 = V_12 -> V_47 ;
#if F_12 ( V_35 )
if ( V_85 )
V_12 -> V_141 = V_8 ;
else
#endif
V_12 -> V_140 = V_8 ;
V_13 = F_1 ( V_12 -> V_1 ) ;
F_94 ( & V_12 -> V_143 , & V_8 -> V_14 [ V_13 ] ) ;
return 0 ;
}
static int F_95 ( struct V_75 * V_59 )
{
struct V_6 * V_12 = F_38 ( V_59 ) ;
bool V_85 = V_12 -> V_15 . V_144 . V_34 == V_45 ;
bool V_145 = V_12 -> V_43 ;
int V_146 = 0 ;
V_12 -> V_140 = NULL ;
#if F_12 ( V_35 )
V_12 -> V_141 = NULL ;
if ( V_85 || V_145 )
V_146 = F_92 ( V_12 , true ) ;
#endif
if ( ! V_146 && ( ! V_85 || V_145 ) )
V_146 = F_92 ( V_12 , false ) ;
if ( V_146 < 0 )
F_89 ( V_12 ) ;
return V_146 ;
}
static int F_96 ( struct V_75 * V_59 )
{
struct V_6 * V_12 = F_38 ( V_59 ) ;
if ( ! F_97 ( & V_12 -> V_143 ) )
F_98 ( & V_12 -> V_143 ) ;
F_89 ( V_12 ) ;
return 0 ;
}
static void F_99 ( struct V_22 * V_77 ,
T_7 V_147 , T_2 V_1 [ 3 ] ,
T_2 V_148 , T_2 * V_57 )
{
V_77 -> V_80 = V_81 ;
V_77 -> V_54 = V_148 / 4 ;
V_77 -> V_50 = ! ! ( V_147 & V_51 ) ;
V_77 -> V_52 = ! ! ( V_147 & V_53 ) ;
V_77 -> V_149 = 0 ;
memcpy ( V_77 -> V_1 , V_1 , 3 ) ;
V_77 -> V_82 = F_46 ( V_83 ) ;
V_77 -> V_150 = 0 ;
memcpy ( V_77 -> V_57 , V_57 , V_148 ) ;
}
static int F_100 ( struct V_151 * V_152 , struct V_23 * V_24 ,
T_7 V_147 , T_2 V_1 [ 3 ] , T_2 V_54 , T_2 * V_153 ,
T_8 V_47 , bool V_154 )
{
struct V_22 * V_25 ;
int V_155 ;
int V_33 ;
bool V_156 = ! ! ( V_47 & V_157 ) ;
F_19 ( V_24 , V_154 ) ;
V_155 = F_101 ( V_152 -> V_62 . V_59 ) + V_152 -> V_62 . V_158
+ V_79 + V_54 + sizeof( struct V_30 ) ;
V_33 = F_102 ( V_24 , V_155 ) ;
if ( F_30 ( V_33 ) ) {
F_36 ( V_24 ) ;
goto V_159;
}
V_24 = F_103 ( V_24 , V_156 ) ;
if ( F_77 ( V_24 ) ) {
V_33 = F_93 ( V_24 ) ;
goto V_159;
}
V_25 = (struct V_22 * ) F_104 ( V_24 , sizeof( * V_25 ) + V_54 ) ;
F_99 ( V_25 , V_147 , V_1 , V_54 , V_153 ) ;
F_105 ( V_24 , F_46 ( V_83 ) ) ;
return 0 ;
V_159:
F_106 ( V_152 ) ;
return V_33 ;
}
static int F_107 ( struct V_160 * V_62 , struct V_23 * V_24 ,
T_7 V_147 , T_2 V_1 [ 3 ] , T_2 V_54 , T_2 * V_153 ,
T_8 V_47 , bool V_154 )
{
struct V_22 * V_25 ;
int V_155 ;
int V_33 ;
bool V_156 = ! ( V_47 & V_161 ) ;
F_19 ( V_24 , V_154 ) ;
V_155 = F_101 ( V_62 -> V_59 ) + V_62 -> V_158
+ V_79 + V_54 + sizeof( struct V_36 ) ;
V_33 = F_102 ( V_24 , V_155 ) ;
if ( F_30 ( V_33 ) ) {
F_36 ( V_24 ) ;
goto V_162;
}
V_24 = F_103 ( V_24 , V_156 ) ;
if ( F_77 ( V_24 ) ) {
V_33 = F_93 ( V_24 ) ;
goto V_162;
}
V_25 = (struct V_22 * ) F_104 ( V_24 , sizeof( * V_25 ) + V_54 ) ;
F_99 ( V_25 , V_147 , V_1 , V_54 , V_153 ) ;
F_105 ( V_24 , F_46 ( V_83 ) ) ;
return 0 ;
V_162:
F_108 ( V_62 ) ;
return V_33 ;
}
static struct V_151 * F_109 ( struct V_23 * V_24 ,
struct V_75 * V_59 ,
struct V_163 * V_164 ,
struct V_165 * V_166 )
{
struct V_6 * V_12 = F_38 ( V_59 ) ;
struct V_151 * V_152 = NULL ;
T_4 V_66 ;
memset ( V_164 , 0 , sizeof( * V_164 ) ) ;
V_164 -> V_167 = V_24 -> V_168 ;
V_164 -> V_169 = V_170 ;
if ( V_166 ) {
V_164 -> V_171 = V_166 -> V_172 . V_55 . V_173 . V_62 ;
V_164 -> V_44 = V_166 -> V_172 . V_55 . V_173 . V_174 ;
V_164 -> V_175 = F_110 ( V_166 -> V_172 . V_66 ) ;
} else {
V_66 = V_12 -> V_66 ;
if ( V_66 == 1 ) {
const struct V_30 * V_176 = F_13 ( V_24 ) ;
V_66 = F_111 ( V_176 , V_24 ) ;
}
V_164 -> V_175 = F_110 ( V_66 ) ;
V_164 -> V_171 = V_12 -> V_15 . sin . V_16 . V_17 ;
}
V_152 = F_112 ( V_12 -> V_58 , V_164 ) ;
if ( F_77 ( V_152 ) ) {
F_113 ( V_59 , L_5 , & V_164 -> V_171 ) ;
return F_52 ( - V_177 ) ;
}
if ( V_152 -> V_62 . V_59 == V_59 ) {
F_113 ( V_59 , L_6 , & V_164 -> V_171 ) ;
F_106 ( V_152 ) ;
return F_52 ( - V_178 ) ;
}
return V_152 ;
}
static struct V_160 * F_114 ( struct V_23 * V_24 ,
struct V_75 * V_59 ,
struct V_179 * V_180 ,
struct V_165 * V_166 )
{
struct V_6 * V_12 = F_38 ( V_59 ) ;
struct V_7 * V_181 = V_12 -> V_141 ;
struct V_160 * V_62 = NULL ;
T_4 V_182 ;
memset ( V_180 , 0 , sizeof( * V_180 ) ) ;
V_180 -> V_183 = V_24 -> V_168 ;
V_180 -> V_184 = V_170 ;
if ( V_166 ) {
V_180 -> V_171 = V_166 -> V_172 . V_55 . V_85 . V_62 ;
V_180 -> V_44 = V_166 -> V_172 . V_55 . V_85 . V_174 ;
V_180 -> V_185 = F_110 ( V_166 -> V_172 . V_66 ) ;
} else {
V_182 = V_12 -> V_66 ;
if ( V_182 == 1 ) {
const struct V_30 * V_176 = F_13 ( V_24 ) ;
V_182 = F_111 ( V_176 , V_24 ) ;
}
V_180 -> V_185 = F_110 ( V_182 ) ;
V_180 -> V_171 = V_12 -> V_15 . V_20 . V_21 ;
}
if ( V_186 -> V_187 ( V_12 -> V_58 , V_181 -> V_39 -> V_40 , & V_62 , V_180 ) ) {
F_113 ( V_59 , L_7 , & V_180 -> V_171 ) ;
return F_52 ( - V_177 ) ;
}
if ( V_62 -> V_59 == V_59 ) {
F_113 ( V_59 , L_8 , & V_180 -> V_171 ) ;
F_108 ( V_62 ) ;
return F_52 ( - V_178 ) ;
}
return V_62 ;
}
static void F_115 ( T_3 V_188 , T_4 * V_1 )
{
#ifdef F_4
V_1 [ 0 ] = ( V_4 T_4 ) ( V_188 >> 16 ) ;
V_1 [ 1 ] = ( V_4 T_4 ) ( V_188 >> 8 ) ;
V_1 [ 2 ] = ( V_4 T_4 ) V_188 ;
#else
V_1 [ 0 ] = ( V_4 T_4 ) ( ( V_4 V_5 ) V_188 >> 40 ) ;
V_1 [ 1 ] = ( V_4 T_4 ) ( ( V_4 V_5 ) V_188 >> 48 ) ;
V_1 [ 2 ] = ( V_4 T_4 ) ( ( V_4 V_5 ) V_188 >> 56 ) ;
#endif
}
static T_9 F_116 ( struct V_23 * V_24 , struct V_75 * V_59 ,
struct V_165 * V_166 )
{
struct V_6 * V_12 = F_38 ( V_59 ) ;
struct V_7 * V_189 = V_12 -> V_140 ;
struct V_151 * V_152 = NULL ;
const struct V_30 * V_176 ;
int V_33 = - V_190 ;
struct V_163 V_164 ;
T_4 V_66 , V_191 ;
T_7 V_192 ;
T_7 V_193 ;
bool V_154 = ! F_20 ( V_12 -> V_58 , F_21 ( V_12 -> V_59 ) ) ;
T_8 V_47 = V_12 -> V_47 ;
if ( V_12 -> V_43 ) {
if ( F_30 ( ! V_166 || ! ( V_166 -> V_194 & V_195 ) ) ) {
F_113 ( V_59 , L_9 ) ;
goto V_196;
}
if ( V_166 && F_117 ( V_166 ) != V_42 )
goto V_196;
}
V_152 = F_109 ( V_24 , V_59 , & V_164 , V_166 ) ;
if ( F_77 ( V_152 ) ) {
V_33 = F_93 ( V_152 ) ;
goto V_196;
}
V_192 = F_118 ( V_12 -> V_58 , V_24 , 1 , V_197 , true ) ;
F_18 ( V_24 ) ;
V_176 = F_13 ( V_24 ) ;
if ( V_166 ) {
const struct V_198 * V_172 = & V_166 -> V_172 ;
T_2 * V_199 = NULL ;
T_2 V_1 [ 3 ] ;
F_115 ( V_172 -> V_188 , V_1 ) ;
if ( V_172 -> V_147 & V_49 )
V_199 = F_119 ( V_166 ) ;
if ( V_172 -> V_147 & V_200 )
V_47 |= V_157 ;
else
V_47 &= ~ V_157 ;
V_33 = F_100 ( V_152 , V_24 , V_172 -> V_147 , V_1 ,
V_166 -> V_148 , V_199 , V_47 , V_154 ) ;
if ( F_30 ( V_33 ) )
goto V_33;
V_66 = F_120 ( V_172 -> V_66 , V_176 , V_24 ) ;
V_191 = V_172 -> V_191 ;
V_193 = V_172 -> V_147 & V_201 ? F_46 ( V_202 ) : 0 ;
} else {
V_33 = F_100 ( V_152 , V_24 , 0 , V_12 -> V_1 ,
0 , NULL , V_47 , V_154 ) ;
if ( F_30 ( V_33 ) )
goto V_33;
V_66 = F_120 ( V_164 . V_175 , V_176 , V_24 ) ;
V_191 = V_12 -> V_191 ;
if ( ! V_191 && F_121 ( F_122 ( V_164 . V_171 ) ) )
V_191 = 1 ;
V_191 = V_191 ? : F_123 ( & V_152 -> V_62 ) ;
V_193 = 0 ;
}
F_124 ( V_152 , V_189 -> V_39 -> V_40 , V_24 , V_164 . V_44 , V_164 . V_171 ,
V_66 , V_191 , V_193 , V_192 , V_12 -> V_142 ,
! F_20 ( V_12 -> V_58 , F_21 ( V_12 -> V_59 ) ) ,
! ( V_47 & V_157 ) ) ;
return V_203 ;
V_196:
F_125 ( V_24 ) ;
V_33:
if ( V_33 == - V_178 )
V_59 -> V_29 . V_204 ++ ;
else if ( V_33 == - V_177 )
V_59 -> V_29 . V_205 ++ ;
else
V_59 -> V_29 . V_206 ++ ;
return V_203 ;
}
static T_9 F_126 ( struct V_23 * V_24 , struct V_75 * V_59 ,
struct V_165 * V_166 )
{
struct V_6 * V_12 = F_38 ( V_59 ) ;
struct V_7 * V_181 = V_12 -> V_141 ;
struct V_160 * V_62 = NULL ;
const struct V_30 * V_176 ;
int V_33 = - V_190 ;
struct V_179 V_180 ;
T_4 V_182 , V_191 ;
T_7 V_192 ;
bool V_154 = ! F_20 ( V_12 -> V_58 , F_21 ( V_12 -> V_59 ) ) ;
T_8 V_47 = V_12 -> V_47 ;
if ( V_12 -> V_43 ) {
if ( F_30 ( ! V_166 || ! ( V_166 -> V_194 & V_195 ) ) ) {
F_113 ( V_59 , L_9 ) ;
goto V_196;
}
}
V_62 = F_114 ( V_24 , V_59 , & V_180 , V_166 ) ;
if ( F_77 ( V_62 ) ) {
V_33 = F_93 ( V_62 ) ;
goto V_196;
}
V_192 = F_118 ( V_12 -> V_58 , V_24 , 1 , V_197 , true ) ;
F_18 ( V_24 ) ;
V_176 = F_13 ( V_24 ) ;
if ( V_166 ) {
const struct V_198 * V_172 = & V_166 -> V_172 ;
T_2 * V_199 = NULL ;
T_2 V_1 [ 3 ] ;
F_115 ( V_172 -> V_188 , V_1 ) ;
if ( V_172 -> V_147 & V_49 )
V_199 = F_119 ( V_166 ) ;
if ( V_172 -> V_147 & V_200 )
V_47 &= ~ V_161 ;
else
V_47 |= V_161 ;
V_33 = F_107 ( V_62 , V_24 , V_172 -> V_147 , V_1 ,
V_166 -> V_148 , V_199 ,
V_47 , V_154 ) ;
if ( F_30 ( V_33 ) )
goto V_33;
V_182 = F_120 ( V_172 -> V_66 , V_176 , V_24 ) ;
V_191 = V_172 -> V_191 ;
} else {
V_33 = F_107 ( V_62 , V_24 , 0 , V_12 -> V_1 ,
0 , NULL , V_47 , V_154 ) ;
if ( F_30 ( V_33 ) )
goto V_33;
V_182 = F_120 ( V_180 . V_185 , V_176 , V_24 ) ;
V_191 = V_12 -> V_191 ;
if ( ! V_191 && F_127 ( & V_180 . V_171 ) )
V_191 = 1 ;
V_191 = V_191 ? : F_128 ( V_62 ) ;
}
F_129 ( V_62 , V_181 -> V_39 -> V_40 , V_24 , V_59 ,
& V_180 . V_44 , & V_180 . V_171 , V_182 , V_191 ,
V_192 , V_12 -> V_142 ,
! ! ( V_47 & V_161 ) ) ;
return V_203 ;
V_196:
F_125 ( V_24 ) ;
V_33:
if ( V_33 == - V_178 )
V_59 -> V_29 . V_204 ++ ;
else if ( V_33 == - V_177 )
V_59 -> V_29 . V_205 ++ ;
else
V_59 -> V_29 . V_206 ++ ;
return V_203 ;
}
static T_9 F_130 ( struct V_23 * V_24 , struct V_75 * V_59 )
{
struct V_6 * V_12 = F_38 ( V_59 ) ;
struct V_165 * V_166 = NULL ;
if ( V_12 -> V_43 )
V_166 = F_131 ( V_24 ) ;
#if F_12 ( V_35 )
if ( ( V_166 && F_117 ( V_166 ) == V_45 ) ||
( ! V_166 && V_12 -> V_15 . V_144 . V_34 == V_45 ) )
return F_126 ( V_24 , V_59 , V_166 ) ;
#endif
return F_116 ( V_24 , V_59 , V_166 ) ;
}
static int F_132 ( struct V_75 * V_59 , int V_207 , bool V_208 )
{
int V_209 = V_210 - V_79 - sizeof( struct V_30 )
- V_59 -> V_211 ;
if ( V_207 < 68 )
return - V_190 ;
if ( V_207 > V_209 ) {
if ( V_208 )
return - V_190 ;
V_207 = V_209 ;
}
V_59 -> V_212 = V_207 ;
return 0 ;
}
static int F_133 ( struct V_75 * V_59 , int V_207 )
{
return F_132 ( V_59 , V_207 , true ) ;
}
static int F_134 ( struct V_75 * V_59 , struct V_23 * V_24 )
{
struct V_165 * V_166 = F_131 ( V_24 ) ;
struct V_6 * V_12 = F_38 ( V_59 ) ;
struct V_151 * V_152 ;
struct V_163 V_164 ;
#if F_12 ( V_35 )
struct V_160 * V_62 ;
struct V_179 V_180 ;
#endif
if ( F_117 ( V_166 ) == V_42 ) {
V_152 = F_109 ( V_24 , V_59 , & V_164 , V_166 ) ;
if ( F_77 ( V_152 ) )
return F_93 ( V_152 ) ;
F_106 ( V_152 ) ;
V_166 -> V_172 . V_55 . V_173 . V_174 = V_164 . V_44 ;
#if F_12 ( V_35 )
} else if ( F_117 ( V_166 ) == V_45 ) {
V_62 = F_114 ( V_24 , V_59 , & V_180 , V_166 ) ;
if ( F_77 ( V_62 ) )
return F_93 ( V_62 ) ;
F_108 ( V_62 ) ;
V_166 -> V_172 . V_55 . V_85 . V_174 = V_180 . V_44 ;
#endif
} else {
return - V_190 ;
}
V_166 -> V_172 . V_213 = F_118 ( V_12 -> V_58 , V_24 ,
1 , V_197 , true ) ;
V_166 -> V_172 . V_214 = V_12 -> V_142 ;
return 0 ;
}
static void F_135 ( struct V_75 * V_59 ,
struct V_215 * V_216 )
{
F_136 ( V_216 -> V_217 , V_218 , sizeof( V_216 -> V_217 ) ) ;
F_136 ( V_216 -> V_219 , L_10 , sizeof( V_216 -> V_219 ) ) ;
}
void F_137 ( struct V_75 * V_59 )
{
struct V_58 * V_58 = F_21 ( V_59 ) ;
struct V_123 * V_124 = F_75 ( V_58 , V_125 ) ;
struct V_7 * V_8 ;
T_6 V_34 ;
struct V_39 * V_40 ;
T_7 V_86 ;
F_58 () ;
F_138 (gs, &gn->sock_list, list) {
V_40 = V_8 -> V_39 -> V_40 ;
V_34 = V_40 -> V_41 ;
V_86 = F_55 ( V_40 ) -> V_96 ;
V_59 -> V_98 -> V_99 ( V_59 , V_34 , V_86 ) ;
}
F_60 () ;
}
static void F_139 ( struct V_75 * V_59 )
{
F_140 ( V_59 ) ;
V_59 -> V_98 = & V_220 ;
V_59 -> V_221 = & V_222 ;
V_59 -> V_223 = V_224 ;
F_141 ( V_59 , & V_225 ) ;
V_59 -> V_226 |= V_227 ;
V_59 -> V_226 |= V_228 | V_229 ;
V_59 -> V_226 |= V_230 ;
V_59 -> V_226 |= V_231 ;
V_59 -> V_232 |= V_228 | V_229 | V_230 ;
V_59 -> V_232 |= V_231 ;
F_142 ( V_59 ) ;
V_59 -> V_233 &= ~ V_234 ;
V_59 -> V_233 |= V_235 | V_236 ;
F_143 ( V_59 ) ;
}
static int F_144 ( struct V_237 * V_238 [] , struct V_237 * V_116 [] )
{
if ( V_238 [ V_239 ] ) {
if ( F_145 ( V_238 [ V_239 ] ) != V_240 )
return - V_190 ;
if ( ! F_146 ( F_147 ( V_238 [ V_239 ] ) ) )
return - V_241 ;
}
if ( ! V_116 )
return - V_190 ;
if ( V_116 [ V_242 ] ) {
T_1 V_1 = F_148 ( V_116 [ V_242 ] ) ;
if ( V_1 >= V_243 )
return - V_244 ;
}
return 0 ;
}
static struct V_6 * F_149 ( struct V_123 * V_124 ,
T_7 V_142 ,
union V_245 * V_15 ,
T_2 V_1 [] ,
bool * V_246 ,
bool * V_247 )
{
struct V_6 * V_12 , * V_248 ;
* V_246 = false ;
* V_247 = false ;
V_248 = NULL ;
F_91 (geneve, &gn->geneve_list, next) {
if ( V_12 -> V_142 == V_142 ) {
* V_247 = V_12 -> V_43 ;
* V_246 = true ;
}
if ( ! memcmp ( V_1 , V_12 -> V_1 , sizeof( V_12 -> V_1 ) ) &&
! memcmp ( V_15 , & V_12 -> V_15 , sizeof( V_12 -> V_15 ) ) &&
V_142 == V_12 -> V_142 )
V_248 = V_12 ;
}
return V_248 ;
}
static int F_150 ( struct V_58 * V_58 , struct V_75 * V_59 ,
union V_245 * V_15 ,
T_1 V_1 , T_4 V_191 , T_4 V_66 , T_7 V_142 ,
bool V_145 , T_8 V_47 )
{
struct V_123 * V_124 = F_75 ( V_58 , V_125 ) ;
struct V_6 * V_248 , * V_12 = F_38 ( V_59 ) ;
bool V_247 , V_246 ;
int V_33 , V_249 ;
if ( ! V_15 )
return - V_190 ;
if ( V_145 &&
( V_15 -> V_144 . V_34 != V_250 || V_1 || V_66 || V_191 ) )
return - V_190 ;
V_12 -> V_58 = V_58 ;
V_12 -> V_59 = V_59 ;
V_12 -> V_1 [ 0 ] = ( V_1 & 0x00ff0000 ) >> 16 ;
V_12 -> V_1 [ 1 ] = ( V_1 & 0x0000ff00 ) >> 8 ;
V_12 -> V_1 [ 2 ] = V_1 & 0x000000ff ;
if ( ( V_15 -> V_144 . V_34 == V_42 &&
F_121 ( F_122 ( V_15 -> sin . V_16 . V_17 ) ) ) ||
( V_15 -> V_144 . V_34 == V_45 &&
F_127 ( & V_15 -> V_20 . V_21 ) ) )
return - V_190 ;
V_12 -> V_15 = * V_15 ;
V_12 -> V_191 = V_191 ;
V_12 -> V_66 = V_66 ;
V_12 -> V_142 = V_142 ;
V_12 -> V_43 = V_145 ;
V_12 -> V_47 = V_47 ;
V_248 = F_149 ( V_124 , V_142 , V_15 , V_12 -> V_1 ,
& V_246 , & V_247 ) ;
if ( V_248 )
return - V_251 ;
V_249 = V_79 + V_61 ;
if ( V_15 -> V_144 . V_34 == V_42 )
V_249 += sizeof( struct V_30 ) ;
else
V_249 += sizeof( struct V_36 ) ;
V_59 -> V_252 = V_249 + V_61 ;
if ( V_145 ) {
if ( V_246 )
return - V_253 ;
} else {
if ( V_247 )
return - V_253 ;
}
V_33 = F_151 ( V_59 ) ;
if ( V_33 )
return V_33 ;
F_82 ( & V_12 -> V_114 , & V_124 -> V_254 ) ;
return 0 ;
}
static int F_152 ( struct V_58 * V_58 , struct V_75 * V_59 ,
struct V_237 * V_238 [] , struct V_237 * V_116 [] )
{
T_7 V_142 = F_46 ( V_255 ) ;
T_4 V_191 = 0 , V_66 = 0 ;
bool V_145 = false ;
union V_245 V_15 = V_256 ;
T_1 V_1 = 0 ;
T_8 V_47 = 0 ;
if ( V_116 [ V_257 ] && V_116 [ V_258 ] )
return - V_190 ;
if ( V_116 [ V_257 ] ) {
V_15 . V_144 . V_34 = V_42 ;
V_15 . sin . V_16 . V_17 =
F_153 ( V_116 [ V_257 ] ) ;
}
if ( V_116 [ V_258 ] ) {
if ( ! F_12 ( V_35 ) )
return - V_259 ;
V_15 . V_144 . V_34 = V_45 ;
V_15 . V_20 . V_21 =
F_154 ( V_116 [ V_258 ] ) ;
if ( F_155 ( & V_15 . V_20 . V_21 ) &
V_260 ) {
F_113 ( V_59 , L_11 ) ;
return - V_190 ;
}
}
if ( V_116 [ V_242 ] )
V_1 = F_148 ( V_116 [ V_242 ] ) ;
if ( V_116 [ V_261 ] )
V_191 = F_156 ( V_116 [ V_261 ] ) ;
if ( V_116 [ V_262 ] )
V_66 = F_156 ( V_116 [ V_262 ] ) ;
if ( V_116 [ V_263 ] )
V_142 = F_157 ( V_116 [ V_263 ] ) ;
if ( V_116 [ V_264 ] )
V_145 = true ;
if ( V_116 [ V_265 ] &&
F_156 ( V_116 [ V_265 ] ) )
V_47 |= V_157 ;
if ( V_116 [ V_266 ] &&
F_156 ( V_116 [ V_266 ] ) )
V_47 |= V_161 ;
if ( V_116 [ V_267 ] &&
F_156 ( V_116 [ V_267 ] ) )
V_47 |= V_92 ;
return F_150 ( V_58 , V_59 , & V_15 , V_1 , V_191 , V_66 , V_142 ,
V_145 , V_47 ) ;
}
static void F_158 ( struct V_75 * V_59 , struct V_268 * V_101 )
{
struct V_6 * V_12 = F_38 ( V_59 ) ;
F_86 ( & V_12 -> V_114 ) ;
F_159 ( V_59 , V_101 ) ;
}
static T_10 F_160 ( const struct V_75 * V_59 )
{
return F_161 ( sizeof( T_1 ) ) +
F_161 ( sizeof( struct V_18 ) ) +
F_161 ( sizeof( T_4 ) ) +
F_161 ( sizeof( T_4 ) ) +
F_161 ( sizeof( T_7 ) ) +
F_161 ( 0 ) +
F_161 ( sizeof( T_4 ) ) +
F_161 ( sizeof( T_4 ) ) +
F_161 ( sizeof( T_4 ) ) +
0 ;
}
static int F_162 ( struct V_23 * V_24 , const struct V_75 * V_59 )
{
struct V_6 * V_12 = F_38 ( V_59 ) ;
T_1 V_1 ;
V_1 = ( V_12 -> V_1 [ 0 ] << 16 ) | ( V_12 -> V_1 [ 1 ] << 8 ) | V_12 -> V_1 [ 2 ] ;
if ( F_163 ( V_24 , V_242 , V_1 ) )
goto V_269;
if ( V_12 -> V_15 . V_144 . V_34 == V_42 ) {
if ( F_164 ( V_24 , V_257 ,
V_12 -> V_15 . sin . V_16 . V_17 ) )
goto V_269;
#if F_12 ( V_35 )
} else {
if ( F_165 ( V_24 , V_258 ,
& V_12 -> V_15 . V_20 . V_21 ) )
goto V_269;
#endif
}
if ( F_166 ( V_24 , V_261 , V_12 -> V_191 ) ||
F_166 ( V_24 , V_262 , V_12 -> V_66 ) )
goto V_269;
if ( F_167 ( V_24 , V_263 , V_12 -> V_142 ) )
goto V_269;
if ( V_12 -> V_43 ) {
if ( F_168 ( V_24 , V_264 ) )
goto V_269;
}
if ( F_166 ( V_24 , V_265 ,
! ! ( V_12 -> V_47 & V_157 ) ) ||
F_166 ( V_24 , V_266 ,
! ! ( V_12 -> V_47 & V_161 ) ) ||
F_166 ( V_24 , V_267 ,
! ! ( V_12 -> V_47 & V_92 ) ) )
goto V_269;
return 0 ;
V_269:
return - V_270 ;
}
struct V_75 * F_169 ( struct V_58 * V_58 , const char * V_271 ,
T_2 V_272 , T_11 V_142 )
{
struct V_237 * V_238 [ V_273 + 1 ] ;
struct V_75 * V_59 ;
int V_33 ;
memset ( V_238 , 0 , sizeof( V_238 ) ) ;
V_59 = F_170 ( V_58 , V_271 , V_272 ,
& V_274 , V_238 ) ;
if ( F_77 ( V_59 ) )
return V_59 ;
V_33 = F_150 ( V_58 , V_59 , & V_256 ,
0 , 0 , 0 , F_46 ( V_142 ) , true ,
V_92 ) ;
if ( V_33 )
goto V_33;
V_33 = F_132 ( V_59 , V_210 , false ) ;
if ( V_33 )
goto V_33;
return V_59 ;
V_33:
V_224 ( V_59 ) ;
return F_52 ( V_33 ) ;
}
static T_12 int F_171 ( struct V_58 * V_58 )
{
struct V_123 * V_124 = F_75 ( V_58 , V_125 ) ;
F_172 ( & V_124 -> V_254 ) ;
F_172 ( & V_124 -> V_137 ) ;
return 0 ;
}
static void T_13 F_173 ( struct V_58 * V_58 )
{
struct V_123 * V_124 = F_75 ( V_58 , V_125 ) ;
struct V_6 * V_12 , * V_114 ;
struct V_75 * V_59 , * V_275 ;
F_174 ( V_136 ) ;
F_175 () ;
F_176 (net, dev, aux)
if ( V_59 -> V_276 == & V_274 )
F_159 ( V_59 , & V_136 ) ;
F_177 (geneve, next, &gn->geneve_list, next) {
if ( ! F_20 ( F_21 ( V_12 -> V_59 ) , V_58 ) )
F_159 ( V_12 -> V_59 , & V_136 ) ;
}
F_178 ( & V_136 ) ;
F_179 () ;
}
static int T_14 F_180 ( void )
{
int V_277 ;
V_277 = F_181 ( & V_278 ) ;
if ( V_277 )
goto V_279;
V_277 = F_182 ( & V_274 ) ;
if ( V_277 )
goto V_280;
return 0 ;
V_280:
F_183 ( & V_278 ) ;
V_279:
return V_277 ;
}
static void T_15 F_184 ( void )
{
F_185 ( & V_274 ) ;
F_183 ( & V_278 ) ;
}
