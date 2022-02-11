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
T_7 V_86 )
{
struct V_84 * V_39 ;
struct V_87 V_88 ;
int V_33 ;
memset ( & V_88 , 0 , sizeof( V_88 ) ) ;
if ( V_85 ) {
V_88 . V_89 = V_45 ;
V_88 . V_90 = 1 ;
} else {
V_88 . V_89 = V_42 ;
V_88 . V_91 . V_17 = F_50 ( V_92 ) ;
}
V_88 . V_93 = V_86 ;
V_33 = F_51 ( V_58 , & V_88 , & V_39 ) ;
if ( V_33 < 0 )
return F_52 ( V_33 ) ;
return V_39 ;
}
static void F_53 ( struct V_7 * V_8 )
{
struct V_39 * V_40 = V_8 -> V_39 -> V_40 ;
T_6 V_34 = V_40 -> V_41 ;
int V_33 ;
if ( V_34 == V_42 ) {
V_33 = F_54 ( & V_8 -> V_94 ) ;
if ( V_33 )
F_55 ( L_4 ,
V_33 ) ;
}
}
static int F_56 ( struct V_22 * V_95 )
{
return sizeof( * V_95 ) + V_95 -> V_54 * 4 ;
}
static struct V_23 * * F_57 ( struct V_23 * * V_96 ,
struct V_23 * V_24 ,
struct V_97 * V_98 )
{
struct V_23 * V_99 , * * V_100 = NULL ;
struct V_22 * V_95 , * V_101 ;
unsigned int V_102 , V_103 , V_104 ;
const struct V_105 * V_106 ;
T_7 type ;
int V_107 = 1 ;
V_104 = F_58 ( V_24 ) ;
V_102 = V_104 + sizeof( * V_95 ) ;
V_95 = F_59 ( V_24 , V_104 ) ;
if ( F_60 ( V_24 , V_102 ) ) {
V_95 = F_61 ( V_24 , V_102 , V_104 ) ;
if ( F_30 ( ! V_95 ) )
goto V_108;
}
if ( V_95 -> V_80 != V_81 || V_95 -> V_50 )
goto V_108;
V_103 = F_56 ( V_95 ) ;
V_102 = V_104 + V_103 ;
if ( F_60 ( V_24 , V_102 ) ) {
V_95 = F_61 ( V_24 , V_102 , V_104 ) ;
if ( F_30 ( ! V_95 ) )
goto V_108;
}
V_107 = 0 ;
for ( V_99 = * V_96 ; V_99 ; V_99 = V_99 -> V_109 ) {
if ( ! F_62 ( V_99 ) -> V_110 )
continue;
V_101 = (struct V_22 * ) ( V_99 -> V_111 + V_104 ) ;
if ( V_95 -> V_54 != V_101 -> V_54 ||
memcmp ( V_95 , V_101 , V_103 ) ) {
F_62 ( V_99 ) -> V_110 = 0 ;
continue;
}
}
type = V_95 -> V_82 ;
F_63 () ;
V_106 = F_64 ( type ) ;
if ( ! V_106 ) {
V_107 = 1 ;
goto V_112;
}
F_65 ( V_24 , V_103 ) ;
F_66 ( V_24 , V_95 , V_103 ) ;
V_100 = V_106 -> V_113 . V_114 ( V_96 , V_24 ) ;
V_112:
F_67 () ;
V_108:
F_62 ( V_24 ) -> V_107 |= V_107 ;
return V_100 ;
}
static int F_68 ( struct V_23 * V_24 , int V_115 ,
struct V_97 * V_98 )
{
struct V_22 * V_95 ;
struct V_105 * V_106 ;
T_7 type ;
int V_103 ;
int V_33 = - V_116 ;
F_69 ( V_24 , V_115 ) ;
V_95 = (struct V_22 * ) ( V_24 -> V_111 + V_115 ) ;
V_103 = F_56 ( V_95 ) ;
type = V_95 -> V_82 ;
F_63 () ;
V_106 = F_70 ( type ) ;
if ( V_106 )
V_33 = V_106 -> V_113 . V_117 ( V_24 , V_115 + V_103 ) ;
F_67 () ;
return V_33 ;
}
static struct V_7 * F_71 ( struct V_58 * V_58 , T_7 V_86 ,
bool V_85 )
{
struct V_118 * V_119 = F_72 ( V_58 , V_120 ) ;
struct V_7 * V_8 ;
struct V_84 * V_39 ;
struct V_121 V_122 ;
int V_123 ;
V_8 = F_73 ( sizeof( * V_8 ) , V_124 ) ;
if ( ! V_8 )
return F_52 ( - V_76 ) ;
V_39 = F_49 ( V_58 , V_85 , V_86 ) ;
if ( F_74 ( V_39 ) ) {
F_75 ( V_8 ) ;
return F_76 ( V_39 ) ;
}
V_8 -> V_39 = V_39 ;
V_8 -> V_125 = 1 ;
for ( V_123 = 0 ; V_123 < V_126 ; ++ V_123 )
F_77 ( & V_8 -> V_14 [ V_123 ] ) ;
V_8 -> V_94 . V_86 = V_86 ;
V_8 -> V_94 . V_113 . V_114 = F_57 ;
V_8 -> V_94 . V_113 . V_117 = F_68 ;
F_53 ( V_8 ) ;
V_122 . V_127 = V_8 ;
V_122 . V_128 = 1 ;
V_122 . V_129 = F_44 ;
V_122 . V_130 = NULL ;
F_78 ( V_58 , V_39 , & V_122 ) ;
F_79 ( & V_8 -> V_131 , & V_119 -> V_132 ) ;
return V_8 ;
}
static void F_80 ( struct V_7 * V_8 )
{
struct V_39 * V_40 = V_8 -> V_39 -> V_40 ;
T_6 V_34 = V_40 -> V_41 ;
if ( V_34 == V_42 )
F_81 ( & V_8 -> V_94 ) ;
}
static void F_82 ( struct V_7 * V_8 )
{
if ( ! V_8 || -- V_8 -> V_125 )
return;
F_83 ( & V_8 -> V_131 ) ;
F_80 ( V_8 ) ;
F_84 ( V_8 -> V_39 ) ;
F_85 ( V_8 , V_133 ) ;
}
static void F_86 ( struct V_6 * V_12 )
{
F_82 ( V_12 -> V_134 ) ;
#if F_12 ( V_35 )
F_82 ( V_12 -> V_135 ) ;
#endif
}
static struct V_7 * F_87 ( struct V_118 * V_119 ,
T_6 V_89 ,
T_7 V_136 )
{
struct V_7 * V_8 ;
F_88 (gs, &gn->sock_list, list) {
if ( F_89 ( V_8 -> V_39 -> V_40 ) -> V_137 == V_136 &&
F_89 ( V_8 -> V_39 -> V_40 ) -> V_40 . V_41 == V_89 ) {
return V_8 ;
}
}
return NULL ;
}
static int F_90 ( struct V_6 * V_12 , bool V_85 )
{
struct V_58 * V_58 = V_12 -> V_58 ;
struct V_118 * V_119 = F_72 ( V_58 , V_120 ) ;
struct V_7 * V_8 ;
T_1 V_13 ;
V_8 = F_87 ( V_119 , V_85 ? V_45 : V_42 , V_12 -> V_136 ) ;
if ( V_8 ) {
V_8 -> V_125 ++ ;
goto V_108;
}
V_8 = F_71 ( V_58 , V_12 -> V_136 , V_85 ) ;
if ( F_74 ( V_8 ) )
return F_91 ( V_8 ) ;
V_108:
V_8 -> V_43 = V_12 -> V_43 ;
#if F_12 ( V_35 )
if ( V_85 )
V_12 -> V_135 = V_8 ;
else
#endif
V_12 -> V_134 = V_8 ;
V_13 = F_1 ( V_12 -> V_1 ) ;
F_92 ( & V_12 -> V_138 , & V_8 -> V_14 [ V_13 ] ) ;
return 0 ;
}
static int F_93 ( struct V_75 * V_59 )
{
struct V_6 * V_12 = F_38 ( V_59 ) ;
bool V_85 = V_12 -> V_15 . V_139 . V_34 == V_45 ;
bool V_140 = V_12 -> V_43 ;
int V_141 = 0 ;
V_12 -> V_134 = NULL ;
#if F_12 ( V_35 )
V_12 -> V_135 = NULL ;
if ( V_85 || V_140 )
V_141 = F_90 ( V_12 , true ) ;
#endif
if ( ! V_141 && ( ! V_85 || V_140 ) )
V_141 = F_90 ( V_12 , false ) ;
if ( V_141 < 0 )
F_86 ( V_12 ) ;
return V_141 ;
}
static int F_94 ( struct V_75 * V_59 )
{
struct V_6 * V_12 = F_38 ( V_59 ) ;
if ( ! F_95 ( & V_12 -> V_138 ) )
F_96 ( & V_12 -> V_138 ) ;
F_86 ( V_12 ) ;
return 0 ;
}
static void F_97 ( struct V_22 * V_77 ,
T_7 V_142 , T_2 V_1 [ 3 ] ,
T_2 V_143 , T_2 * V_57 )
{
V_77 -> V_80 = V_81 ;
V_77 -> V_54 = V_143 / 4 ;
V_77 -> V_50 = ! ! ( V_142 & V_51 ) ;
V_77 -> V_52 = ! ! ( V_142 & V_53 ) ;
V_77 -> V_144 = 0 ;
memcpy ( V_77 -> V_1 , V_1 , 3 ) ;
V_77 -> V_82 = F_46 ( V_83 ) ;
V_77 -> V_145 = 0 ;
memcpy ( V_77 -> V_57 , V_57 , V_143 ) ;
}
static int F_98 ( struct V_146 * V_147 , struct V_23 * V_24 ,
T_7 V_142 , T_2 V_1 [ 3 ] , T_2 V_54 , T_2 * V_148 ,
bool V_149 , bool V_150 )
{
struct V_22 * V_25 ;
int V_151 ;
int V_33 ;
F_19 ( V_24 , V_150 ) ;
V_151 = F_99 ( V_147 -> V_62 . V_59 ) + V_147 -> V_62 . V_152
+ V_79 + V_54 + sizeof( struct V_30 ) ;
V_33 = F_100 ( V_24 , V_151 ) ;
if ( F_30 ( V_33 ) ) {
F_36 ( V_24 ) ;
goto V_153;
}
V_24 = F_101 ( V_24 , V_149 ) ;
if ( F_74 ( V_24 ) ) {
V_33 = F_91 ( V_24 ) ;
goto V_153;
}
V_25 = (struct V_22 * ) F_102 ( V_24 , sizeof( * V_25 ) + V_54 ) ;
F_97 ( V_25 , V_142 , V_1 , V_54 , V_148 ) ;
F_103 ( V_24 , F_46 ( V_83 ) ) ;
return 0 ;
V_153:
F_104 ( V_147 ) ;
return V_33 ;
}
static int F_105 ( struct V_154 * V_62 , struct V_23 * V_24 ,
T_7 V_142 , T_2 V_1 [ 3 ] , T_2 V_54 , T_2 * V_148 ,
bool V_149 , bool V_150 )
{
struct V_22 * V_25 ;
int V_151 ;
int V_33 ;
F_19 ( V_24 , V_150 ) ;
V_151 = F_99 ( V_62 -> V_59 ) + V_62 -> V_152
+ V_79 + V_54 + sizeof( struct V_36 ) ;
V_33 = F_100 ( V_24 , V_151 ) ;
if ( F_30 ( V_33 ) ) {
F_36 ( V_24 ) ;
goto V_155;
}
V_24 = F_101 ( V_24 , V_149 ) ;
if ( F_74 ( V_24 ) ) {
V_33 = F_91 ( V_24 ) ;
goto V_155;
}
V_25 = (struct V_22 * ) F_102 ( V_24 , sizeof( * V_25 ) + V_54 ) ;
F_97 ( V_25 , V_142 , V_1 , V_54 , V_148 ) ;
F_103 ( V_24 , F_46 ( V_83 ) ) ;
return 0 ;
V_155:
F_106 ( V_62 ) ;
return V_33 ;
}
static struct V_146 * F_107 ( struct V_23 * V_24 ,
struct V_75 * V_59 ,
struct V_156 * V_157 ,
struct V_158 * V_159 )
{
struct V_6 * V_12 = F_38 ( V_59 ) ;
struct V_146 * V_147 = NULL ;
T_4 V_66 ;
memset ( V_157 , 0 , sizeof( * V_157 ) ) ;
V_157 -> V_160 = V_24 -> V_161 ;
V_157 -> V_162 = V_163 ;
if ( V_159 ) {
V_157 -> V_164 = V_159 -> V_165 . V_55 . V_166 . V_62 ;
V_157 -> V_44 = V_159 -> V_165 . V_55 . V_166 . V_167 ;
V_157 -> V_168 = F_108 ( V_159 -> V_165 . V_66 ) ;
} else {
V_66 = V_12 -> V_66 ;
if ( V_66 == 1 ) {
const struct V_30 * V_169 = F_13 ( V_24 ) ;
V_66 = F_109 ( V_169 , V_24 ) ;
}
V_157 -> V_168 = F_108 ( V_66 ) ;
V_157 -> V_164 = V_12 -> V_15 . sin . V_16 . V_17 ;
}
V_147 = F_110 ( V_12 -> V_58 , V_157 ) ;
if ( F_74 ( V_147 ) ) {
F_111 ( V_59 , L_5 , & V_157 -> V_164 ) ;
return F_52 ( - V_170 ) ;
}
if ( V_147 -> V_62 . V_59 == V_59 ) {
F_111 ( V_59 , L_6 , & V_157 -> V_164 ) ;
F_104 ( V_147 ) ;
return F_52 ( - V_171 ) ;
}
return V_147 ;
}
static struct V_154 * F_112 ( struct V_23 * V_24 ,
struct V_75 * V_59 ,
struct V_172 * V_173 ,
struct V_158 * V_159 )
{
struct V_6 * V_12 = F_38 ( V_59 ) ;
struct V_7 * V_174 = V_12 -> V_135 ;
struct V_154 * V_62 = NULL ;
T_4 V_175 ;
memset ( V_173 , 0 , sizeof( * V_173 ) ) ;
V_173 -> V_176 = V_24 -> V_161 ;
V_173 -> V_177 = V_163 ;
if ( V_159 ) {
V_173 -> V_164 = V_159 -> V_165 . V_55 . V_85 . V_62 ;
V_173 -> V_44 = V_159 -> V_165 . V_55 . V_85 . V_167 ;
V_173 -> V_178 = F_108 ( V_159 -> V_165 . V_66 ) ;
} else {
V_175 = V_12 -> V_66 ;
if ( V_175 == 1 ) {
const struct V_30 * V_169 = F_13 ( V_24 ) ;
V_175 = F_109 ( V_169 , V_24 ) ;
}
V_173 -> V_178 = F_108 ( V_175 ) ;
V_173 -> V_164 = V_12 -> V_15 . V_20 . V_21 ;
}
if ( V_179 -> V_180 ( V_12 -> V_58 , V_174 -> V_39 -> V_40 , & V_62 , V_173 ) ) {
F_111 ( V_59 , L_7 , & V_173 -> V_164 ) ;
return F_52 ( - V_170 ) ;
}
if ( V_62 -> V_59 == V_59 ) {
F_111 ( V_59 , L_8 , & V_173 -> V_164 ) ;
F_106 ( V_62 ) ;
return F_52 ( - V_171 ) ;
}
return V_62 ;
}
static void F_113 ( T_3 V_181 , T_4 * V_1 )
{
#ifdef F_4
V_1 [ 0 ] = ( V_4 T_4 ) ( V_181 >> 16 ) ;
V_1 [ 1 ] = ( V_4 T_4 ) ( V_181 >> 8 ) ;
V_1 [ 2 ] = ( V_4 T_4 ) V_181 ;
#else
V_1 [ 0 ] = ( V_4 T_4 ) ( ( V_4 V_5 ) V_181 >> 40 ) ;
V_1 [ 1 ] = ( V_4 T_4 ) ( ( V_4 V_5 ) V_181 >> 48 ) ;
V_1 [ 2 ] = ( V_4 T_4 ) ( ( V_4 V_5 ) V_181 >> 56 ) ;
#endif
}
static T_8 F_114 ( struct V_23 * V_24 , struct V_75 * V_59 ,
struct V_158 * V_159 )
{
struct V_6 * V_12 = F_38 ( V_59 ) ;
struct V_7 * V_182 = V_12 -> V_134 ;
struct V_146 * V_147 = NULL ;
const struct V_30 * V_169 ;
int V_33 = - V_183 ;
struct V_156 V_157 ;
T_4 V_66 , V_184 ;
T_7 V_185 ;
bool V_186 ;
T_7 V_187 ;
bool V_150 = ! F_20 ( V_12 -> V_58 , F_21 ( V_12 -> V_59 ) ) ;
if ( V_12 -> V_43 ) {
if ( F_30 ( ! V_159 || ! ( V_159 -> V_188 & V_189 ) ) ) {
F_111 ( V_59 , L_9 ) ;
goto V_190;
}
if ( V_159 && F_115 ( V_159 ) != V_42 )
goto V_190;
}
V_147 = F_107 ( V_24 , V_59 , & V_157 , V_159 ) ;
if ( F_74 ( V_147 ) ) {
V_33 = F_91 ( V_147 ) ;
goto V_190;
}
V_185 = F_116 ( V_12 -> V_58 , V_24 , 1 , V_191 , true ) ;
F_18 ( V_24 ) ;
V_169 = F_13 ( V_24 ) ;
if ( V_159 ) {
const struct V_192 * V_165 = & V_159 -> V_165 ;
T_2 * V_193 = NULL ;
T_2 V_1 [ 3 ] ;
F_113 ( V_165 -> V_181 , V_1 ) ;
if ( V_165 -> V_142 & V_49 )
V_193 = F_117 ( V_159 ) ;
V_186 = ! ! ( V_165 -> V_142 & V_194 ) ;
V_33 = F_98 ( V_147 , V_24 , V_165 -> V_142 , V_1 ,
V_159 -> V_143 , V_193 , V_186 , V_150 ) ;
if ( F_30 ( V_33 ) )
goto V_33;
V_66 = F_118 ( V_165 -> V_66 , V_169 , V_24 ) ;
V_184 = V_165 -> V_184 ;
V_187 = V_165 -> V_142 & V_195 ? F_46 ( V_196 ) : 0 ;
} else {
V_186 = false ;
V_33 = F_98 ( V_147 , V_24 , 0 , V_12 -> V_1 ,
0 , NULL , V_186 , V_150 ) ;
if ( F_30 ( V_33 ) )
goto V_33;
V_66 = F_118 ( V_157 . V_168 , V_169 , V_24 ) ;
V_184 = V_12 -> V_184 ;
if ( ! V_184 && F_119 ( F_120 ( V_157 . V_164 ) ) )
V_184 = 1 ;
V_184 = V_184 ? : F_121 ( & V_147 -> V_62 ) ;
V_187 = 0 ;
}
V_33 = F_122 ( V_147 , V_182 -> V_39 -> V_40 , V_24 , V_157 . V_44 , V_157 . V_164 ,
V_66 , V_184 , V_187 , V_185 , V_12 -> V_136 ,
! F_20 ( V_12 -> V_58 , F_21 ( V_12 -> V_59 ) ) ,
! V_186 ) ;
F_123 ( V_33 , & V_59 -> V_29 , V_59 -> V_69 ) ;
return V_197 ;
V_190:
F_124 ( V_24 ) ;
V_33:
if ( V_33 == - V_171 )
V_59 -> V_29 . V_198 ++ ;
else if ( V_33 == - V_170 )
V_59 -> V_29 . V_199 ++ ;
else
V_59 -> V_29 . V_200 ++ ;
return V_197 ;
}
static T_8 F_125 ( struct V_23 * V_24 , struct V_75 * V_59 ,
struct V_158 * V_159 )
{
struct V_6 * V_12 = F_38 ( V_59 ) ;
struct V_7 * V_174 = V_12 -> V_135 ;
struct V_154 * V_62 = NULL ;
const struct V_30 * V_169 ;
int V_33 = - V_183 ;
struct V_172 V_173 ;
T_4 V_175 , V_184 ;
T_7 V_185 ;
bool V_186 ;
bool V_150 = ! F_20 ( V_12 -> V_58 , F_21 ( V_12 -> V_59 ) ) ;
if ( V_12 -> V_43 ) {
if ( F_30 ( ! V_159 || ! ( V_159 -> V_188 & V_189 ) ) ) {
F_111 ( V_59 , L_9 ) ;
goto V_190;
}
}
V_62 = F_112 ( V_24 , V_59 , & V_173 , V_159 ) ;
if ( F_74 ( V_62 ) ) {
V_33 = F_91 ( V_62 ) ;
goto V_190;
}
V_185 = F_116 ( V_12 -> V_58 , V_24 , 1 , V_191 , true ) ;
F_18 ( V_24 ) ;
V_169 = F_13 ( V_24 ) ;
if ( V_159 ) {
const struct V_192 * V_165 = & V_159 -> V_165 ;
T_2 * V_193 = NULL ;
T_2 V_1 [ 3 ] ;
F_113 ( V_165 -> V_181 , V_1 ) ;
if ( V_165 -> V_142 & V_49 )
V_193 = F_117 ( V_159 ) ;
V_186 = ! ! ( V_165 -> V_142 & V_194 ) ;
V_33 = F_105 ( V_62 , V_24 , V_165 -> V_142 , V_1 ,
V_159 -> V_143 , V_193 ,
V_186 , V_150 ) ;
if ( F_30 ( V_33 ) )
goto V_33;
V_175 = F_118 ( V_165 -> V_66 , V_169 , V_24 ) ;
V_184 = V_165 -> V_184 ;
} else {
V_186 = false ;
V_33 = F_105 ( V_62 , V_24 , 0 , V_12 -> V_1 ,
0 , NULL , V_186 , V_150 ) ;
if ( F_30 ( V_33 ) )
goto V_33;
V_175 = F_118 ( V_173 . V_178 , V_169 , V_24 ) ;
V_184 = V_12 -> V_184 ;
if ( ! V_184 && F_126 ( & V_173 . V_164 ) )
V_184 = 1 ;
V_184 = V_184 ? : F_127 ( V_62 ) ;
}
V_33 = F_128 ( V_62 , V_174 -> V_39 -> V_40 , V_24 , V_59 ,
& V_173 . V_44 , & V_173 . V_164 , V_175 , V_184 ,
V_185 , V_12 -> V_136 , ! V_186 ) ;
return V_197 ;
V_190:
F_124 ( V_24 ) ;
V_33:
if ( V_33 == - V_171 )
V_59 -> V_29 . V_198 ++ ;
else if ( V_33 == - V_170 )
V_59 -> V_29 . V_199 ++ ;
else
V_59 -> V_29 . V_200 ++ ;
return V_197 ;
}
static T_8 F_129 ( struct V_23 * V_24 , struct V_75 * V_59 )
{
struct V_6 * V_12 = F_38 ( V_59 ) ;
struct V_158 * V_159 = NULL ;
if ( V_12 -> V_43 )
V_159 = F_130 ( V_24 ) ;
#if F_12 ( V_35 )
if ( ( V_159 && F_115 ( V_159 ) == V_45 ) ||
( ! V_159 && V_12 -> V_15 . V_139 . V_34 == V_45 ) )
return F_125 ( V_24 , V_59 , V_159 ) ;
#endif
return F_114 ( V_24 , V_59 , V_159 ) ;
}
static int F_131 ( struct V_75 * V_59 , struct V_23 * V_24 )
{
struct V_158 * V_159 = F_130 ( V_24 ) ;
struct V_6 * V_12 = F_38 ( V_59 ) ;
struct V_146 * V_147 ;
struct V_156 V_157 ;
#if F_12 ( V_35 )
struct V_154 * V_62 ;
struct V_172 V_173 ;
#endif
if ( F_115 ( V_159 ) == V_42 ) {
V_147 = F_107 ( V_24 , V_59 , & V_157 , V_159 ) ;
if ( F_74 ( V_147 ) )
return F_91 ( V_147 ) ;
F_104 ( V_147 ) ;
V_159 -> V_165 . V_55 . V_166 . V_167 = V_157 . V_44 ;
#if F_12 ( V_35 )
} else if ( F_115 ( V_159 ) == V_45 ) {
V_62 = F_112 ( V_24 , V_59 , & V_173 , V_159 ) ;
if ( F_74 ( V_62 ) )
return F_91 ( V_62 ) ;
F_106 ( V_62 ) ;
V_159 -> V_165 . V_55 . V_85 . V_167 = V_173 . V_44 ;
#endif
} else {
return - V_183 ;
}
V_159 -> V_165 . V_201 = F_116 ( V_12 -> V_58 , V_24 ,
1 , V_191 , true ) ;
V_159 -> V_165 . V_202 = V_12 -> V_136 ;
return 0 ;
}
static void F_132 ( struct V_75 * V_59 ,
struct V_203 * V_204 )
{
F_133 ( V_204 -> V_205 , V_206 , sizeof( V_204 -> V_205 ) ) ;
F_133 ( V_204 -> V_207 , L_10 , sizeof( V_204 -> V_207 ) ) ;
}
static void F_134 ( struct V_75 * V_59 )
{
F_135 ( V_59 ) ;
V_59 -> V_208 = & V_209 ;
V_59 -> V_210 = & V_211 ;
V_59 -> V_212 = V_213 ;
F_136 ( V_59 , & V_214 ) ;
V_59 -> V_215 |= V_216 ;
V_59 -> V_215 |= V_217 | V_218 ;
V_59 -> V_215 |= V_219 ;
V_59 -> V_215 |= V_220 ;
V_59 -> V_221 |= V_217 | V_218 | V_219 ;
V_59 -> V_221 |= V_220 ;
F_137 ( V_59 ) ;
V_59 -> V_222 |= V_223 | V_224 ;
F_138 ( V_59 ) ;
}
static int F_139 ( struct V_225 * V_226 [] , struct V_225 * V_111 [] )
{
if ( V_226 [ V_227 ] ) {
if ( F_140 ( V_226 [ V_227 ] ) != V_228 )
return - V_183 ;
if ( ! F_141 ( F_142 ( V_226 [ V_227 ] ) ) )
return - V_229 ;
}
if ( ! V_111 )
return - V_183 ;
if ( V_111 [ V_230 ] ) {
T_1 V_1 = F_143 ( V_111 [ V_230 ] ) ;
if ( V_1 >= V_231 )
return - V_232 ;
}
return 0 ;
}
static struct V_6 * F_144 ( struct V_118 * V_119 ,
T_7 V_136 ,
union V_233 * V_15 ,
T_2 V_1 [] ,
bool * V_234 ,
bool * V_235 )
{
struct V_6 * V_12 , * V_236 ;
* V_234 = false ;
* V_235 = false ;
V_236 = NULL ;
F_88 (geneve, &gn->geneve_list, next) {
if ( V_12 -> V_136 == V_136 ) {
* V_235 = V_12 -> V_43 ;
* V_234 = true ;
}
if ( ! memcmp ( V_1 , V_12 -> V_1 , sizeof( V_12 -> V_1 ) ) &&
! memcmp ( V_15 , & V_12 -> V_15 , sizeof( V_12 -> V_15 ) ) &&
V_136 == V_12 -> V_136 )
V_236 = V_12 ;
}
return V_236 ;
}
static int F_145 ( struct V_58 * V_58 , struct V_75 * V_59 ,
union V_233 * V_15 ,
T_1 V_1 , T_4 V_184 , T_4 V_66 , T_7 V_136 ,
bool V_140 )
{
struct V_118 * V_119 = F_72 ( V_58 , V_120 ) ;
struct V_6 * V_236 , * V_12 = F_38 ( V_59 ) ;
bool V_235 , V_234 ;
int V_33 , V_237 ;
if ( ! V_15 )
return - V_183 ;
if ( V_140 &&
( V_15 -> V_139 . V_34 != V_238 || V_1 || V_66 || V_184 ) )
return - V_183 ;
V_12 -> V_58 = V_58 ;
V_12 -> V_59 = V_59 ;
V_12 -> V_1 [ 0 ] = ( V_1 & 0x00ff0000 ) >> 16 ;
V_12 -> V_1 [ 1 ] = ( V_1 & 0x0000ff00 ) >> 8 ;
V_12 -> V_1 [ 2 ] = V_1 & 0x000000ff ;
if ( ( V_15 -> V_139 . V_34 == V_42 &&
F_119 ( F_120 ( V_15 -> sin . V_16 . V_17 ) ) ) ||
( V_15 -> V_139 . V_34 == V_45 &&
F_126 ( & V_15 -> V_20 . V_21 ) ) )
return - V_183 ;
V_12 -> V_15 = * V_15 ;
V_12 -> V_184 = V_184 ;
V_12 -> V_66 = V_66 ;
V_12 -> V_136 = V_136 ;
V_12 -> V_43 = V_140 ;
V_236 = F_144 ( V_119 , V_136 , V_15 , V_12 -> V_1 ,
& V_234 , & V_235 ) ;
if ( V_236 )
return - V_239 ;
V_237 = V_79 + V_61 ;
if ( V_15 -> V_139 . V_34 == V_42 )
V_237 += sizeof( struct V_30 ) ;
else
V_237 += sizeof( struct V_36 ) ;
V_59 -> V_240 = V_237 + V_61 ;
if ( V_140 ) {
if ( V_234 )
return - V_241 ;
} else {
if ( V_235 )
return - V_241 ;
}
V_33 = F_146 ( V_59 ) ;
if ( V_33 )
return V_33 ;
F_79 ( & V_12 -> V_109 , & V_119 -> V_242 ) ;
return 0 ;
}
static int F_147 ( struct V_58 * V_58 , struct V_75 * V_59 ,
struct V_225 * V_226 [] , struct V_225 * V_111 [] )
{
T_7 V_136 = F_46 ( V_243 ) ;
T_4 V_184 = 0 , V_66 = 0 ;
bool V_140 = false ;
union V_233 V_15 = V_244 ;
T_1 V_1 = 0 ;
if ( V_111 [ V_245 ] && V_111 [ V_246 ] )
return - V_183 ;
if ( V_111 [ V_245 ] ) {
V_15 . V_139 . V_34 = V_42 ;
V_15 . sin . V_16 . V_17 =
F_148 ( V_111 [ V_245 ] ) ;
}
if ( V_111 [ V_246 ] ) {
if ( ! F_12 ( V_35 ) )
return - V_247 ;
V_15 . V_139 . V_34 = V_45 ;
V_15 . V_20 . V_21 =
F_149 ( V_111 [ V_246 ] ) ;
if ( F_150 ( & V_15 . V_20 . V_21 ) &
V_248 ) {
F_111 ( V_59 , L_11 ) ;
return - V_183 ;
}
}
if ( V_111 [ V_230 ] )
V_1 = F_143 ( V_111 [ V_230 ] ) ;
if ( V_111 [ V_249 ] )
V_184 = F_151 ( V_111 [ V_249 ] ) ;
if ( V_111 [ V_250 ] )
V_66 = F_151 ( V_111 [ V_250 ] ) ;
if ( V_111 [ V_251 ] )
V_136 = F_152 ( V_111 [ V_251 ] ) ;
if ( V_111 [ V_252 ] )
V_140 = true ;
return F_145 ( V_58 , V_59 , & V_15 , V_1 , V_184 , V_66 , V_136 ,
V_140 ) ;
}
static void F_153 ( struct V_75 * V_59 , struct V_253 * V_96 )
{
struct V_6 * V_12 = F_38 ( V_59 ) ;
F_83 ( & V_12 -> V_109 ) ;
F_154 ( V_59 , V_96 ) ;
}
static T_9 F_155 ( const struct V_75 * V_59 )
{
return F_156 ( sizeof( T_1 ) ) +
F_156 ( sizeof( struct V_18 ) ) +
F_156 ( sizeof( T_4 ) ) +
F_156 ( sizeof( T_4 ) ) +
F_156 ( sizeof( T_7 ) ) +
F_156 ( 0 ) +
0 ;
}
static int F_157 ( struct V_23 * V_24 , const struct V_75 * V_59 )
{
struct V_6 * V_12 = F_38 ( V_59 ) ;
T_1 V_1 ;
V_1 = ( V_12 -> V_1 [ 0 ] << 16 ) | ( V_12 -> V_1 [ 1 ] << 8 ) | V_12 -> V_1 [ 2 ] ;
if ( F_158 ( V_24 , V_230 , V_1 ) )
goto V_254;
if ( V_12 -> V_15 . V_139 . V_34 == V_42 ) {
if ( F_159 ( V_24 , V_245 ,
V_12 -> V_15 . sin . V_16 . V_17 ) )
goto V_254;
#if F_12 ( V_35 )
} else {
if ( F_160 ( V_24 , V_246 ,
& V_12 -> V_15 . V_20 . V_21 ) )
goto V_254;
#endif
}
if ( F_161 ( V_24 , V_249 , V_12 -> V_184 ) ||
F_161 ( V_24 , V_250 , V_12 -> V_66 ) )
goto V_254;
if ( F_162 ( V_24 , V_251 , V_12 -> V_136 ) )
goto V_254;
if ( V_12 -> V_43 ) {
if ( F_163 ( V_24 , V_252 ) )
goto V_254;
}
return 0 ;
V_254:
return - V_255 ;
}
struct V_75 * F_164 ( struct V_58 * V_58 , const char * V_256 ,
T_2 V_257 , T_10 V_136 )
{
struct V_225 * V_226 [ V_258 + 1 ] ;
struct V_75 * V_59 ;
int V_33 ;
memset ( V_226 , 0 , sizeof( V_226 ) ) ;
V_59 = F_165 ( V_58 , V_256 , V_257 ,
& V_259 , V_226 ) ;
if ( F_74 ( V_59 ) )
return V_59 ;
V_33 = F_145 ( V_58 , V_59 , & V_244 ,
0 , 0 , 0 , F_46 ( V_136 ) , true ) ;
if ( V_33 ) {
V_213 ( V_59 ) ;
return F_52 ( V_33 ) ;
}
return V_59 ;
}
static T_11 int F_166 ( struct V_58 * V_58 )
{
struct V_118 * V_119 = F_72 ( V_58 , V_120 ) ;
F_167 ( & V_119 -> V_242 ) ;
F_167 ( & V_119 -> V_132 ) ;
return 0 ;
}
static void T_12 F_168 ( struct V_58 * V_58 )
{
struct V_118 * V_119 = F_72 ( V_58 , V_120 ) ;
struct V_6 * V_12 , * V_109 ;
struct V_75 * V_59 , * V_260 ;
F_169 ( V_131 ) ;
F_170 () ;
F_171 (net, dev, aux)
if ( V_59 -> V_261 == & V_259 )
F_154 ( V_59 , & V_131 ) ;
F_172 (geneve, next, &gn->geneve_list, next) {
if ( ! F_20 ( F_21 ( V_12 -> V_59 ) , V_58 ) )
F_154 ( V_12 -> V_59 , & V_131 ) ;
}
F_173 ( & V_131 ) ;
F_174 () ;
}
static int T_13 F_175 ( void )
{
int V_262 ;
V_262 = F_176 ( & V_263 ) ;
if ( V_262 )
goto V_264;
V_262 = F_177 ( & V_259 ) ;
if ( V_262 )
goto V_265;
return 0 ;
V_265:
F_178 ( & V_263 ) ;
V_264:
return V_262 ;
}
static void T_14 F_179 ( void )
{
F_180 ( & V_259 ) ;
F_178 ( & V_263 ) ;
}
