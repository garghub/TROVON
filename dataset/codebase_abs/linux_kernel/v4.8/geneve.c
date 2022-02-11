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
goto V_54;
V_78 = F_10 ( V_27 ) ;
if ( F_30 ( V_78 -> V_81 != V_82 ) )
goto V_54;
if ( F_30 ( V_78 -> V_83 != F_48 ( V_84 ) ) )
goto V_54;
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
static int F_57 ( struct V_25 * V_98 )
{
return sizeof( * V_98 ) + V_98 -> V_53 * 4 ;
}
static struct V_26 * * F_58 ( struct V_8 * V_9 ,
struct V_26 * * V_99 ,
struct V_26 * V_27 )
{
struct V_26 * V_100 , * * V_101 = NULL ;
struct V_25 * V_98 , * V_102 ;
unsigned int V_103 , V_104 , V_105 ;
const struct V_106 * V_107 ;
T_7 type ;
int V_108 = 1 ;
V_105 = F_59 ( V_27 ) ;
V_103 = V_105 + sizeof( * V_98 ) ;
V_98 = F_60 ( V_27 , V_105 ) ;
if ( F_61 ( V_27 , V_103 ) ) {
V_98 = F_62 ( V_27 , V_103 , V_105 ) ;
if ( F_30 ( ! V_98 ) )
goto V_109;
}
if ( V_98 -> V_81 != V_82 || V_98 -> V_49 )
goto V_109;
V_104 = F_57 ( V_98 ) ;
V_103 = V_105 + V_104 ;
if ( F_61 ( V_27 , V_103 ) ) {
V_98 = F_62 ( V_27 , V_103 , V_105 ) ;
if ( F_30 ( ! V_98 ) )
goto V_109;
}
for ( V_100 = * V_99 ; V_100 ; V_100 = V_100 -> V_110 ) {
if ( ! F_63 ( V_100 ) -> V_111 )
continue;
V_102 = (struct V_25 * ) ( V_100 -> V_112 + V_105 ) ;
if ( V_98 -> V_53 != V_102 -> V_53 ||
memcmp ( V_98 , V_102 , V_104 ) ) {
F_63 ( V_100 ) -> V_111 = 0 ;
continue;
}
}
type = V_98 -> V_83 ;
F_64 () ;
V_107 = F_65 ( type ) ;
if ( ! V_107 )
goto V_113;
F_66 ( V_27 , V_104 ) ;
F_67 ( V_27 , V_98 , V_104 ) ;
V_101 = V_107 -> V_114 . V_115 ( V_99 , V_27 ) ;
V_108 = 0 ;
V_113:
F_68 () ;
V_109:
F_63 ( V_27 ) -> V_108 |= V_108 ;
return V_101 ;
}
static int F_69 ( struct V_8 * V_9 , struct V_26 * V_27 ,
int V_116 )
{
struct V_25 * V_98 ;
struct V_106 * V_107 ;
T_7 type ;
int V_104 ;
int V_44 = - V_117 ;
V_98 = (struct V_25 * ) ( V_27 -> V_112 + V_116 ) ;
V_104 = F_57 ( V_98 ) ;
type = V_98 -> V_83 ;
F_64 () ;
V_107 = F_70 ( type ) ;
if ( V_107 )
V_44 = V_107 -> V_114 . V_118 ( V_27 , V_116 + V_104 ) ;
F_68 () ;
F_71 ( V_27 , V_116 + V_104 ) ;
return V_44 ;
}
static struct V_6 * F_72 ( struct V_85 * V_85 , T_7 V_88 ,
bool V_87 , T_8 V_46 )
{
struct V_119 * V_120 = F_73 ( V_85 , V_121 ) ;
struct V_6 * V_7 ;
struct V_86 * V_8 ;
struct V_122 V_123 ;
int V_124 ;
V_7 = F_74 ( sizeof( * V_7 ) , V_77 ) ;
if ( ! V_7 )
return F_56 ( - V_75 ) ;
V_8 = F_53 ( V_85 , V_87 , V_88 , V_46 ) ;
if ( F_75 ( V_8 ) ) {
F_76 ( V_7 ) ;
return F_77 ( V_8 ) ;
}
V_7 -> V_8 = V_8 ;
V_7 -> V_125 = 1 ;
for ( V_124 = 0 ; V_124 < V_126 ; ++ V_124 )
F_78 ( & V_7 -> V_17 [ V_124 ] ) ;
F_79 ( V_7 -> V_8 , V_127 ) ;
memset ( & V_123 , 0 , sizeof( V_123 ) ) ;
V_123 . V_128 = V_7 ;
V_123 . V_129 = 1 ;
V_123 . V_115 = F_58 ;
V_123 . V_118 = F_69 ;
V_123 . V_130 = F_46 ;
V_123 . V_131 = NULL ;
F_80 ( V_85 , V_8 , & V_123 ) ;
F_81 ( & V_7 -> V_132 , & V_120 -> V_133 ) ;
return V_7 ;
}
static void F_82 ( struct V_6 * V_7 )
{
if ( ! V_7 || -- V_7 -> V_125 )
return;
F_83 ( & V_7 -> V_132 ) ;
F_84 ( V_7 -> V_8 , V_127 ) ;
F_85 ( V_7 -> V_8 ) ;
F_86 ( V_7 , V_134 ) ;
}
static void F_87 ( struct V_11 * V_15 )
{
F_82 ( V_15 -> V_135 ) ;
#if F_13 ( V_29 )
F_82 ( V_15 -> V_136 ) ;
#endif
}
static struct V_6 * F_88 ( struct V_119 * V_120 ,
T_5 V_91 ,
T_7 V_137 )
{
struct V_6 * V_7 ;
F_89 (gs, &gn->sock_list, list) {
if ( F_90 ( V_7 -> V_8 -> V_9 ) -> V_138 == V_137 &&
F_5 ( V_7 ) == V_91 ) {
return V_7 ;
}
}
return NULL ;
}
static int F_91 ( struct V_11 * V_15 , bool V_87 )
{
struct V_85 * V_85 = V_15 -> V_85 ;
struct V_119 * V_120 = F_73 ( V_85 , V_121 ) ;
struct V_6 * V_7 ;
T_1 V_16 ;
V_7 = F_88 ( V_120 , V_87 ? V_36 : V_31 , V_15 -> V_137 ) ;
if ( V_7 ) {
V_7 -> V_125 ++ ;
goto V_109;
}
V_7 = F_72 ( V_85 , V_15 -> V_137 , V_87 , V_15 -> V_46 ) ;
if ( F_75 ( V_7 ) )
return F_92 ( V_7 ) ;
V_109:
V_7 -> V_34 = V_15 -> V_34 ;
V_7 -> V_46 = V_15 -> V_46 ;
#if F_13 ( V_29 )
if ( V_87 )
V_15 -> V_136 = V_7 ;
else
#endif
V_15 -> V_135 = V_7 ;
V_16 = F_1 ( V_15 -> V_1 ) ;
F_93 ( & V_15 -> V_139 , & V_7 -> V_17 [ V_16 ] ) ;
return 0 ;
}
static int F_94 ( struct V_74 * V_59 )
{
struct V_11 * V_15 = F_38 ( V_59 ) ;
bool V_87 = V_15 -> V_18 . V_140 . V_141 == V_36 ;
bool V_142 = V_15 -> V_34 ;
int V_143 = 0 ;
V_15 -> V_135 = NULL ;
#if F_13 ( V_29 )
V_15 -> V_136 = NULL ;
if ( V_87 || V_142 )
V_143 = F_91 ( V_15 , true ) ;
#endif
if ( ! V_143 && ( ! V_87 || V_142 ) )
V_143 = F_91 ( V_15 , false ) ;
if ( V_143 < 0 )
F_87 ( V_15 ) ;
return V_143 ;
}
static int F_95 ( struct V_74 * V_59 )
{
struct V_11 * V_15 = F_38 ( V_59 ) ;
if ( ! F_96 ( & V_15 -> V_139 ) )
F_97 ( & V_15 -> V_139 ) ;
F_87 ( V_15 ) ;
return 0 ;
}
static void F_98 ( struct V_25 * V_78 ,
T_7 V_144 , T_2 V_1 [ 3 ] ,
T_2 V_145 , T_2 * V_57 )
{
V_78 -> V_81 = V_82 ;
V_78 -> V_53 = V_145 / 4 ;
V_78 -> V_49 = ! ! ( V_144 & V_50 ) ;
V_78 -> V_51 = ! ! ( V_144 & V_52 ) ;
V_78 -> V_146 = 0 ;
memcpy ( V_78 -> V_1 , V_1 , 3 ) ;
V_78 -> V_83 = F_48 ( V_84 ) ;
V_78 -> V_147 = 0 ;
memcpy ( V_78 -> V_57 , V_57 , V_145 ) ;
}
static int F_99 ( struct V_148 * V_149 , struct V_26 * V_27 ,
T_7 V_144 , T_2 V_1 [ 3 ] , T_2 V_53 , T_2 * V_150 ,
T_8 V_46 , bool V_151 )
{
struct V_25 * V_39 ;
int V_152 ;
int V_44 ;
bool V_153 = ! ( V_46 & V_154 ) ;
F_100 ( V_27 , V_151 ) ;
V_152 = F_101 ( V_149 -> V_61 . V_59 ) + V_149 -> V_61 . V_155
+ V_80 + V_53 + sizeof( struct V_32 ) ;
V_44 = F_102 ( V_27 , V_152 ) ;
if ( F_30 ( V_44 ) )
goto V_156;
V_44 = F_103 ( V_27 , V_153 ) ;
if ( V_44 )
goto V_156;
V_39 = (struct V_25 * ) F_104 ( V_27 , sizeof( * V_39 ) + V_53 ) ;
F_98 ( V_39 , V_144 , V_1 , V_53 , V_150 ) ;
F_105 ( V_27 , F_48 ( V_84 ) ) ;
return 0 ;
V_156:
F_106 ( V_149 ) ;
return V_44 ;
}
static int F_107 ( struct V_157 * V_61 , struct V_26 * V_27 ,
T_7 V_144 , T_2 V_1 [ 3 ] , T_2 V_53 , T_2 * V_150 ,
T_8 V_46 , bool V_151 )
{
struct V_25 * V_39 ;
int V_152 ;
int V_44 ;
bool V_153 = ! ( V_46 & V_158 ) ;
F_100 ( V_27 , V_151 ) ;
V_152 = F_101 ( V_61 -> V_59 ) + V_61 -> V_155
+ V_80 + V_53 + sizeof( struct V_37 ) ;
V_44 = F_102 ( V_27 , V_152 ) ;
if ( F_30 ( V_44 ) )
goto V_159;
V_44 = F_103 ( V_27 , V_153 ) ;
if ( V_44 )
goto V_159;
V_39 = (struct V_25 * ) F_104 ( V_27 , sizeof( * V_39 ) + V_53 ) ;
F_98 ( V_39 , V_144 , V_1 , V_53 , V_150 ) ;
F_105 ( V_27 , F_48 ( V_84 ) ) ;
return 0 ;
V_159:
F_108 ( V_61 ) ;
return V_44 ;
}
static struct V_148 * F_109 ( struct V_26 * V_27 ,
struct V_74 * V_59 ,
struct V_160 * V_161 ,
struct V_162 * V_163 )
{
bool V_164 = F_110 ( V_27 , V_163 ) ;
struct V_11 * V_15 = F_38 ( V_59 ) ;
struct V_76 * V_76 ;
struct V_148 * V_149 = NULL ;
T_4 V_65 ;
memset ( V_161 , 0 , sizeof( * V_161 ) ) ;
V_161 -> V_165 = V_27 -> V_166 ;
V_161 -> V_167 = V_168 ;
if ( V_163 ) {
V_161 -> V_169 = V_163 -> V_170 . V_55 . V_171 . V_61 ;
V_161 -> V_35 = V_163 -> V_170 . V_55 . V_171 . V_172 ;
V_161 -> V_173 = F_111 ( V_163 -> V_170 . V_65 ) ;
V_76 = & V_163 -> V_76 ;
} else {
V_65 = V_15 -> V_65 ;
if ( V_65 == 1 ) {
const struct V_32 * V_174 = F_14 ( V_27 ) ;
V_65 = F_112 ( V_174 , V_27 ) ;
V_164 = false ;
}
V_161 -> V_173 = F_111 ( V_65 ) ;
V_161 -> V_169 = V_15 -> V_18 . sin . V_19 . V_20 ;
V_76 = & V_15 -> V_76 ;
}
if ( V_164 ) {
V_149 = F_113 ( V_76 , & V_161 -> V_35 ) ;
if ( V_149 )
return V_149 ;
}
V_149 = F_114 ( V_15 -> V_85 , V_161 ) ;
if ( F_75 ( V_149 ) ) {
F_115 ( V_59 , L_4 , & V_161 -> V_169 ) ;
return F_56 ( - V_175 ) ;
}
if ( V_149 -> V_61 . V_59 == V_59 ) {
F_115 ( V_59 , L_5 , & V_161 -> V_169 ) ;
F_106 ( V_149 ) ;
return F_56 ( - V_176 ) ;
}
if ( V_164 )
F_116 ( V_76 , & V_149 -> V_61 , V_161 -> V_35 ) ;
return V_149 ;
}
static struct V_157 * F_117 ( struct V_26 * V_27 ,
struct V_74 * V_59 ,
struct V_177 * V_178 ,
struct V_162 * V_163 )
{
bool V_164 = F_110 ( V_27 , V_163 ) ;
struct V_11 * V_15 = F_38 ( V_59 ) ;
struct V_6 * V_179 = V_15 -> V_136 ;
struct V_157 * V_61 = NULL ;
struct V_76 * V_76 ;
T_4 V_180 ;
memset ( V_178 , 0 , sizeof( * V_178 ) ) ;
V_178 -> V_181 = V_27 -> V_166 ;
V_178 -> V_182 = V_168 ;
if ( V_163 ) {
V_178 -> V_169 = V_163 -> V_170 . V_55 . V_87 . V_61 ;
V_178 -> V_35 = V_163 -> V_170 . V_55 . V_87 . V_172 ;
V_178 -> V_183 = F_118 ( F_111 ( V_163 -> V_170 . V_65 ) ,
V_163 -> V_170 . V_184 ) ;
V_76 = & V_163 -> V_76 ;
} else {
V_180 = V_15 -> V_65 ;
if ( V_180 == 1 ) {
const struct V_32 * V_174 = F_14 ( V_27 ) ;
V_180 = F_112 ( V_174 , V_27 ) ;
V_164 = false ;
}
V_178 -> V_183 = F_118 ( F_111 ( V_180 ) ,
V_15 -> V_184 ) ;
V_178 -> V_169 = V_15 -> V_18 . V_23 . V_24 ;
V_76 = & V_15 -> V_76 ;
}
if ( V_164 ) {
V_61 = F_119 ( V_76 , & V_178 -> V_35 ) ;
if ( V_61 )
return V_61 ;
}
if ( V_185 -> V_186 ( V_15 -> V_85 , V_179 -> V_8 -> V_9 , & V_61 , V_178 ) ) {
F_115 ( V_59 , L_6 , & V_178 -> V_169 ) ;
return F_56 ( - V_175 ) ;
}
if ( V_61 -> V_59 == V_59 ) {
F_115 ( V_59 , L_7 , & V_178 -> V_169 ) ;
F_108 ( V_61 ) ;
return F_56 ( - V_176 ) ;
}
if ( V_164 )
F_120 ( V_76 , V_61 , & V_178 -> V_35 ) ;
return V_61 ;
}
static void F_121 ( T_3 V_187 , T_4 * V_1 )
{
#ifdef F_4
V_1 [ 0 ] = ( V_4 T_4 ) ( V_187 >> 16 ) ;
V_1 [ 1 ] = ( V_4 T_4 ) ( V_187 >> 8 ) ;
V_1 [ 2 ] = ( V_4 T_4 ) V_187 ;
#else
V_1 [ 0 ] = ( V_4 T_4 ) ( ( V_4 V_5 ) V_187 >> 40 ) ;
V_1 [ 1 ] = ( V_4 T_4 ) ( ( V_4 V_5 ) V_187 >> 48 ) ;
V_1 [ 2 ] = ( V_4 T_4 ) ( ( V_4 V_5 ) V_187 >> 56 ) ;
#endif
}
static T_9 F_122 ( struct V_26 * V_27 , struct V_74 * V_59 ,
struct V_162 * V_163 )
{
struct V_11 * V_15 = F_38 ( V_59 ) ;
struct V_6 * V_188 = V_15 -> V_135 ;
struct V_148 * V_149 = NULL ;
const struct V_32 * V_174 ;
int V_44 = - V_189 ;
struct V_160 V_161 ;
T_4 V_65 , V_190 ;
T_7 V_191 ;
T_7 V_192 ;
bool V_151 = ! F_51 ( V_15 -> V_85 , F_52 ( V_15 -> V_59 ) ) ;
T_8 V_46 = V_15 -> V_46 ;
if ( V_15 -> V_34 ) {
if ( F_30 ( ! V_163 || ! ( V_163 -> V_193 & V_194 ) ) ) {
F_115 ( V_59 , L_8 ) ;
goto V_195;
}
if ( V_163 && F_123 ( V_163 ) != V_31 )
goto V_195;
}
V_149 = F_109 ( V_27 , V_59 , & V_161 , V_163 ) ;
if ( F_75 ( V_149 ) ) {
V_44 = F_92 ( V_149 ) ;
goto V_195;
}
V_191 = F_124 ( V_15 -> V_85 , V_27 , 1 , V_196 , true ) ;
F_20 ( V_27 ) ;
V_174 = F_14 ( V_27 ) ;
if ( V_163 ) {
const struct V_197 * V_170 = & V_163 -> V_170 ;
T_2 * V_198 = NULL ;
T_2 V_1 [ 3 ] ;
F_121 ( V_170 -> V_187 , V_1 ) ;
if ( V_163 -> V_145 )
V_198 = F_125 ( V_163 ) ;
if ( V_170 -> V_144 & V_199 )
V_46 &= ~ V_154 ;
else
V_46 |= V_154 ;
V_44 = F_99 ( V_149 , V_27 , V_170 -> V_144 , V_1 ,
V_163 -> V_145 , V_198 , V_46 , V_151 ) ;
if ( F_30 ( V_44 ) )
goto V_195;
V_65 = F_126 ( V_170 -> V_65 , V_174 , V_27 ) ;
V_190 = V_170 -> V_190 ;
V_192 = V_170 -> V_144 & V_200 ? F_48 ( V_201 ) : 0 ;
} else {
V_44 = F_99 ( V_149 , V_27 , 0 , V_15 -> V_1 ,
0 , NULL , V_46 , V_151 ) ;
if ( F_30 ( V_44 ) )
goto V_195;
V_65 = F_126 ( V_161 . V_173 , V_174 , V_27 ) ;
V_190 = V_15 -> V_190 ;
if ( ! V_190 && F_127 ( F_128 ( V_161 . V_169 ) ) )
V_190 = 1 ;
V_190 = V_190 ? : F_129 ( & V_149 -> V_61 ) ;
V_192 = 0 ;
}
F_130 ( V_149 , V_188 -> V_8 -> V_9 , V_27 , V_161 . V_35 , V_161 . V_169 ,
V_65 , V_190 , V_192 , V_191 , V_15 -> V_137 ,
! F_51 ( V_15 -> V_85 , F_52 ( V_15 -> V_59 ) ) ,
! ! ( V_46 & V_154 ) ) ;
return V_202 ;
V_195:
F_131 ( V_27 ) ;
if ( V_44 == - V_176 )
V_59 -> V_43 . V_203 ++ ;
else if ( V_44 == - V_175 )
V_59 -> V_43 . V_204 ++ ;
V_59 -> V_43 . V_205 ++ ;
return V_202 ;
}
static T_9 F_132 ( struct V_26 * V_27 , struct V_74 * V_59 ,
struct V_162 * V_163 )
{
struct V_11 * V_15 = F_38 ( V_59 ) ;
struct V_6 * V_179 = V_15 -> V_136 ;
struct V_157 * V_61 = NULL ;
const struct V_32 * V_174 ;
int V_44 = - V_189 ;
struct V_177 V_178 ;
T_4 V_180 , V_190 ;
T_7 V_191 ;
T_6 V_184 ;
bool V_151 = ! F_51 ( V_15 -> V_85 , F_52 ( V_15 -> V_59 ) ) ;
T_8 V_46 = V_15 -> V_46 ;
if ( V_15 -> V_34 ) {
if ( F_30 ( ! V_163 || ! ( V_163 -> V_193 & V_194 ) ) ) {
F_115 ( V_59 , L_8 ) ;
goto V_195;
}
}
V_61 = F_117 ( V_27 , V_59 , & V_178 , V_163 ) ;
if ( F_75 ( V_61 ) ) {
V_44 = F_92 ( V_61 ) ;
goto V_195;
}
V_191 = F_124 ( V_15 -> V_85 , V_27 , 1 , V_196 , true ) ;
F_20 ( V_27 ) ;
V_174 = F_14 ( V_27 ) ;
if ( V_163 ) {
const struct V_197 * V_170 = & V_163 -> V_170 ;
T_2 * V_198 = NULL ;
T_2 V_1 [ 3 ] ;
F_121 ( V_170 -> V_187 , V_1 ) ;
if ( V_163 -> V_145 )
V_198 = F_125 ( V_163 ) ;
if ( V_170 -> V_144 & V_199 )
V_46 &= ~ V_158 ;
else
V_46 |= V_158 ;
V_44 = F_107 ( V_61 , V_27 , V_170 -> V_144 , V_1 ,
V_163 -> V_145 , V_198 ,
V_46 , V_151 ) ;
if ( F_30 ( V_44 ) )
goto V_195;
V_180 = F_126 ( V_170 -> V_65 , V_174 , V_27 ) ;
V_190 = V_170 -> V_190 ;
V_184 = V_163 -> V_170 . V_184 ;
} else {
V_44 = F_107 ( V_61 , V_27 , 0 , V_15 -> V_1 ,
0 , NULL , V_46 , V_151 ) ;
if ( F_30 ( V_44 ) )
goto V_195;
V_180 = F_126 ( F_133 ( V_178 . V_183 ) ,
V_174 , V_27 ) ;
V_190 = V_15 -> V_190 ;
if ( ! V_190 && F_134 ( & V_178 . V_169 ) )
V_190 = 1 ;
V_190 = V_190 ? : F_135 ( V_61 ) ;
V_184 = V_15 -> V_184 ;
}
F_136 ( V_61 , V_179 -> V_8 -> V_9 , V_27 , V_59 ,
& V_178 . V_35 , & V_178 . V_169 , V_180 , V_190 , V_184 ,
V_191 , V_15 -> V_137 ,
! ! ( V_46 & V_158 ) ) ;
return V_202 ;
V_195:
F_131 ( V_27 ) ;
if ( V_44 == - V_176 )
V_59 -> V_43 . V_203 ++ ;
else if ( V_44 == - V_175 )
V_59 -> V_43 . V_204 ++ ;
V_59 -> V_43 . V_205 ++ ;
return V_202 ;
}
static T_9 F_137 ( struct V_26 * V_27 , struct V_74 * V_59 )
{
struct V_11 * V_15 = F_38 ( V_59 ) ;
struct V_162 * V_163 = NULL ;
if ( V_15 -> V_34 )
V_163 = F_138 ( V_27 ) ;
#if F_13 ( V_29 )
if ( ( V_163 && F_123 ( V_163 ) == V_36 ) ||
( ! V_163 && V_15 -> V_18 . V_140 . V_141 == V_36 ) )
return F_132 ( V_27 , V_59 , V_163 ) ;
#endif
return F_122 ( V_27 , V_59 , V_163 ) ;
}
static int F_139 ( struct V_74 * V_59 , int V_206 , bool V_207 )
{
struct V_11 * V_15 = F_38 ( V_59 ) ;
int V_208 = V_209 - V_80 - V_59 -> V_210 ;
if ( V_15 -> V_18 . V_140 . V_141 == V_36 )
V_208 -= sizeof( struct V_37 ) ;
else
V_208 -= sizeof( struct V_32 ) ;
if ( V_206 < 68 )
return - V_189 ;
if ( V_206 > V_208 ) {
if ( V_207 )
return - V_189 ;
V_206 = V_208 ;
}
V_59 -> V_211 = V_206 ;
return 0 ;
}
static int F_140 ( struct V_74 * V_59 , int V_206 )
{
return F_139 ( V_59 , V_206 , true ) ;
}
static int F_141 ( struct V_74 * V_59 , struct V_26 * V_27 )
{
struct V_162 * V_163 = F_138 ( V_27 ) ;
struct V_11 * V_15 = F_38 ( V_59 ) ;
struct V_148 * V_149 ;
struct V_160 V_161 ;
#if F_13 ( V_29 )
struct V_157 * V_61 ;
struct V_177 V_178 ;
#endif
if ( F_123 ( V_163 ) == V_31 ) {
V_149 = F_109 ( V_27 , V_59 , & V_161 , V_163 ) ;
if ( F_75 ( V_149 ) )
return F_92 ( V_149 ) ;
F_106 ( V_149 ) ;
V_163 -> V_170 . V_55 . V_171 . V_172 = V_161 . V_35 ;
#if F_13 ( V_29 )
} else if ( F_123 ( V_163 ) == V_36 ) {
V_61 = F_117 ( V_27 , V_59 , & V_178 , V_163 ) ;
if ( F_75 ( V_61 ) )
return F_92 ( V_61 ) ;
F_108 ( V_61 ) ;
V_163 -> V_170 . V_55 . V_87 . V_172 = V_178 . V_35 ;
#endif
} else {
return - V_189 ;
}
V_163 -> V_170 . V_212 = F_124 ( V_15 -> V_85 , V_27 ,
1 , V_196 , true ) ;
V_163 -> V_170 . V_213 = V_15 -> V_137 ;
return 0 ;
}
static void F_142 ( struct V_74 * V_59 ,
struct V_214 * V_215 )
{
F_143 ( V_215 -> V_216 , V_217 , sizeof( V_215 -> V_216 ) ) ;
F_143 ( V_215 -> V_218 , L_9 , sizeof( V_215 -> V_218 ) ) ;
}
static void F_144 ( struct V_74 * V_59 )
{
struct V_85 * V_85 = F_52 ( V_59 ) ;
struct V_119 * V_120 = F_73 ( V_85 , V_121 ) ;
struct V_6 * V_7 ;
F_64 () ;
F_145 (gs, &gn->sock_list, list)
F_146 ( V_59 , V_7 -> V_8 ,
V_127 ) ;
F_68 () ;
}
static void F_147 ( struct V_74 * V_59 )
{
F_148 ( V_59 ) ;
V_59 -> V_219 = & V_220 ;
V_59 -> V_221 = & V_222 ;
V_59 -> V_223 = V_224 ;
F_149 ( V_59 , & V_225 ) ;
V_59 -> V_226 |= V_227 ;
V_59 -> V_226 |= V_228 | V_229 ;
V_59 -> V_226 |= V_230 ;
V_59 -> V_226 |= V_231 ;
V_59 -> V_232 |= V_228 | V_229 | V_230 ;
V_59 -> V_232 |= V_231 ;
F_150 ( V_59 ) ;
V_59 -> V_233 &= ~ V_234 ;
V_59 -> V_233 |= V_235 | V_236 ;
F_151 ( V_59 ) ;
}
static int F_152 ( struct V_237 * V_238 [] , struct V_237 * V_112 [] )
{
if ( V_238 [ V_239 ] ) {
if ( F_153 ( V_238 [ V_239 ] ) != V_240 )
return - V_189 ;
if ( ! F_154 ( F_155 ( V_238 [ V_239 ] ) ) )
return - V_241 ;
}
if ( ! V_112 )
return - V_189 ;
if ( V_112 [ V_242 ] ) {
T_1 V_1 = F_156 ( V_112 [ V_242 ] ) ;
if ( V_1 >= V_243 )
return - V_244 ;
}
return 0 ;
}
static struct V_11 * F_157 ( struct V_119 * V_120 ,
T_7 V_137 ,
union V_245 * V_18 ,
T_2 V_1 [] ,
bool * V_246 ,
bool * V_247 )
{
struct V_11 * V_15 , * V_248 ;
* V_246 = false ;
* V_247 = false ;
V_248 = NULL ;
F_89 (geneve, &gn->geneve_list, next) {
if ( V_15 -> V_137 == V_137 ) {
* V_247 = V_15 -> V_34 ;
* V_246 = true ;
}
if ( ! memcmp ( V_1 , V_15 -> V_1 , sizeof( V_15 -> V_1 ) ) &&
! memcmp ( V_18 , & V_15 -> V_18 , sizeof( V_15 -> V_18 ) ) &&
V_137 == V_15 -> V_137 )
V_248 = V_15 ;
}
return V_248 ;
}
static int F_158 ( struct V_85 * V_85 , struct V_74 * V_59 ,
union V_245 * V_18 ,
T_1 V_1 , T_4 V_190 , T_4 V_65 , T_6 V_184 ,
T_7 V_137 , bool V_142 , T_8 V_46 )
{
struct V_119 * V_120 = F_73 ( V_85 , V_121 ) ;
struct V_11 * V_248 , * V_15 = F_38 ( V_59 ) ;
bool V_247 , V_246 ;
int V_44 , V_249 ;
if ( ! V_18 )
return - V_189 ;
if ( V_142 &&
( V_18 -> V_140 . V_141 != V_250 || V_1 || V_65 || V_190 || V_184 ) )
return - V_189 ;
V_15 -> V_85 = V_85 ;
V_15 -> V_59 = V_59 ;
V_15 -> V_1 [ 0 ] = ( V_1 & 0x00ff0000 ) >> 16 ;
V_15 -> V_1 [ 1 ] = ( V_1 & 0x0000ff00 ) >> 8 ;
V_15 -> V_1 [ 2 ] = V_1 & 0x000000ff ;
if ( ( V_18 -> V_140 . V_141 == V_31 &&
F_127 ( F_128 ( V_18 -> sin . V_19 . V_20 ) ) ) ||
( V_18 -> V_140 . V_141 == V_36 &&
F_134 ( & V_18 -> V_23 . V_24 ) ) )
return - V_189 ;
if ( V_184 && V_18 -> V_140 . V_141 != V_36 )
return - V_189 ;
V_15 -> V_18 = * V_18 ;
V_15 -> V_190 = V_190 ;
V_15 -> V_65 = V_65 ;
V_15 -> V_184 = V_184 ;
V_15 -> V_137 = V_137 ;
V_15 -> V_34 = V_142 ;
V_15 -> V_46 = V_46 ;
V_248 = F_157 ( V_120 , V_137 , V_18 , V_15 -> V_1 ,
& V_246 , & V_247 ) ;
if ( V_248 )
return - V_251 ;
V_249 = V_80 + V_60 ;
if ( V_18 -> V_140 . V_141 == V_31 )
V_249 += sizeof( struct V_32 ) ;
else
V_249 += sizeof( struct V_37 ) ;
V_59 -> V_252 = V_249 + V_60 ;
if ( V_142 ) {
if ( V_246 )
return - V_253 ;
} else {
if ( V_247 )
return - V_253 ;
}
F_159 ( & V_15 -> V_76 ) ;
V_44 = F_160 ( V_59 ) ;
if ( V_44 )
return V_44 ;
F_81 ( & V_15 -> V_110 , & V_120 -> V_254 ) ;
return 0 ;
}
static int F_161 ( struct V_85 * V_85 , struct V_74 * V_59 ,
struct V_237 * V_238 [] , struct V_237 * V_112 [] )
{
T_7 V_137 = F_48 ( V_255 ) ;
T_4 V_190 = 0 , V_65 = 0 ;
bool V_142 = false ;
union V_245 V_18 = V_256 ;
T_6 V_184 = 0 ;
T_1 V_1 = 0 ;
T_8 V_46 = 0 ;
if ( V_112 [ V_257 ] && V_112 [ V_258 ] )
return - V_189 ;
if ( V_112 [ V_257 ] ) {
V_18 . V_140 . V_141 = V_31 ;
V_18 . sin . V_19 . V_20 =
F_162 ( V_112 [ V_257 ] ) ;
}
if ( V_112 [ V_258 ] ) {
if ( ! F_13 ( V_29 ) )
return - V_259 ;
V_18 . V_140 . V_141 = V_36 ;
V_18 . V_23 . V_24 =
F_163 ( V_112 [ V_258 ] ) ;
if ( F_164 ( & V_18 . V_23 . V_24 ) &
V_260 ) {
F_115 ( V_59 , L_10 ) ;
return - V_189 ;
}
}
if ( V_112 [ V_242 ] )
V_1 = F_156 ( V_112 [ V_242 ] ) ;
if ( V_112 [ V_261 ] )
V_190 = F_165 ( V_112 [ V_261 ] ) ;
if ( V_112 [ V_262 ] )
V_65 = F_165 ( V_112 [ V_262 ] ) ;
if ( V_112 [ V_263 ] )
V_184 = F_166 ( V_112 [ V_263 ] ) &
V_264 ;
if ( V_112 [ V_265 ] )
V_137 = F_167 ( V_112 [ V_265 ] ) ;
if ( V_112 [ V_266 ] )
V_142 = true ;
if ( V_112 [ V_267 ] &&
! F_165 ( V_112 [ V_267 ] ) )
V_46 |= V_154 ;
if ( V_112 [ V_268 ] &&
F_165 ( V_112 [ V_268 ] ) )
V_46 |= V_158 ;
if ( V_112 [ V_269 ] &&
F_165 ( V_112 [ V_269 ] ) )
V_46 |= V_94 ;
return F_158 ( V_85 , V_59 , & V_18 , V_1 , V_190 , V_65 , V_184 ,
V_137 , V_142 , V_46 ) ;
}
static void F_168 ( struct V_74 * V_59 , struct V_270 * V_99 )
{
struct V_11 * V_15 = F_38 ( V_59 ) ;
F_83 ( & V_15 -> V_110 ) ;
F_169 ( V_59 , V_99 ) ;
}
static T_10 F_170 ( const struct V_74 * V_59 )
{
return F_171 ( sizeof( T_1 ) ) +
F_171 ( sizeof( struct V_21 ) ) +
F_171 ( sizeof( T_4 ) ) +
F_171 ( sizeof( T_4 ) ) +
F_171 ( sizeof( T_6 ) ) +
F_171 ( sizeof( T_7 ) ) +
F_171 ( 0 ) +
F_171 ( sizeof( T_4 ) ) +
F_171 ( sizeof( T_4 ) ) +
F_171 ( sizeof( T_4 ) ) +
0 ;
}
static int F_172 ( struct V_26 * V_27 , const struct V_74 * V_59 )
{
struct V_11 * V_15 = F_38 ( V_59 ) ;
T_1 V_1 ;
V_1 = ( V_15 -> V_1 [ 0 ] << 16 ) | ( V_15 -> V_1 [ 1 ] << 8 ) | V_15 -> V_1 [ 2 ] ;
if ( F_173 ( V_27 , V_242 , V_1 ) )
goto V_271;
if ( V_15 -> V_18 . V_140 . V_141 == V_31 ) {
if ( F_174 ( V_27 , V_257 ,
V_15 -> V_18 . sin . V_19 . V_20 ) )
goto V_271;
#if F_13 ( V_29 )
} else {
if ( F_175 ( V_27 , V_258 ,
& V_15 -> V_18 . V_23 . V_24 ) )
goto V_271;
#endif
}
if ( F_176 ( V_27 , V_261 , V_15 -> V_190 ) ||
F_176 ( V_27 , V_262 , V_15 -> V_65 ) ||
F_177 ( V_27 , V_263 , V_15 -> V_184 ) )
goto V_271;
if ( F_178 ( V_27 , V_265 , V_15 -> V_137 ) )
goto V_271;
if ( V_15 -> V_34 ) {
if ( F_179 ( V_27 , V_266 ) )
goto V_271;
}
if ( F_176 ( V_27 , V_267 ,
! ( V_15 -> V_46 & V_154 ) ) ||
F_176 ( V_27 , V_268 ,
! ! ( V_15 -> V_46 & V_158 ) ) ||
F_176 ( V_27 , V_269 ,
! ! ( V_15 -> V_46 & V_94 ) ) )
goto V_271;
return 0 ;
V_271:
return - V_272 ;
}
struct V_74 * F_180 ( struct V_85 * V_85 , const char * V_273 ,
T_2 V_274 , T_11 V_137 )
{
struct V_237 * V_238 [ V_275 + 1 ] ;
struct V_74 * V_59 ;
F_181 ( V_276 ) ;
int V_44 ;
memset ( V_238 , 0 , sizeof( V_238 ) ) ;
V_59 = F_182 ( V_85 , V_273 , V_274 ,
& V_277 , V_238 ) ;
if ( F_75 ( V_59 ) )
return V_59 ;
V_44 = F_158 ( V_85 , V_59 , & V_256 ,
0 , 0 , 0 , 0 , F_48 ( V_137 ) , true ,
V_94 ) ;
if ( V_44 ) {
V_224 ( V_59 ) ;
return F_56 ( V_44 ) ;
}
V_44 = F_139 ( V_59 , V_209 , false ) ;
if ( V_44 )
goto V_44;
V_44 = F_183 ( V_59 , NULL ) ;
if ( V_44 < 0 )
goto V_44;
return V_59 ;
V_44:
F_168 ( V_59 , & V_276 ) ;
F_184 ( & V_276 ) ;
return F_56 ( V_44 ) ;
}
static int F_185 ( struct V_278 * V_279 ,
unsigned long V_280 , void * V_281 )
{
struct V_74 * V_59 = F_186 ( V_281 ) ;
if ( V_280 == V_282 )
F_144 ( V_59 ) ;
return V_283 ;
}
static T_12 int F_187 ( struct V_85 * V_85 )
{
struct V_119 * V_120 = F_73 ( V_85 , V_121 ) ;
F_188 ( & V_120 -> V_254 ) ;
F_188 ( & V_120 -> V_133 ) ;
return 0 ;
}
static void T_13 F_189 ( struct V_85 * V_85 )
{
struct V_119 * V_120 = F_73 ( V_85 , V_121 ) ;
struct V_11 * V_15 , * V_110 ;
struct V_74 * V_59 , * V_284 ;
F_181 ( V_132 ) ;
F_190 () ;
F_191 (net, dev, aux)
if ( V_59 -> V_285 == & V_277 )
F_169 ( V_59 , & V_132 ) ;
F_192 (geneve, next, &gn->geneve_list, next) {
if ( ! F_51 ( F_52 ( V_15 -> V_59 ) , V_85 ) )
F_169 ( V_15 -> V_59 , & V_132 ) ;
}
F_184 ( & V_132 ) ;
F_193 () ;
}
static int T_14 F_194 ( void )
{
int V_286 ;
V_286 = F_195 ( & V_287 ) ;
if ( V_286 )
goto V_288;
V_286 = F_196 ( & V_289 ) ;
if ( V_286 )
goto V_290;
V_286 = F_197 ( & V_277 ) ;
if ( V_286 )
goto V_291;
return 0 ;
V_291:
F_198 ( & V_289 ) ;
V_290:
F_199 ( & V_287 ) ;
V_288:
return V_286 ;
}
static void T_15 F_200 ( void )
{
F_201 ( & V_277 ) ;
F_198 ( & V_289 ) ;
F_199 ( & V_287 ) ;
}
