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
V_101 = F_68 ( V_107 -> V_114 . V_115 , V_99 , V_27 ) ;
V_108 = 0 ;
V_113:
F_69 () ;
V_109:
F_63 ( V_27 ) -> V_108 |= V_108 ;
return V_101 ;
}
static int F_70 ( struct V_8 * V_9 , struct V_26 * V_27 ,
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
V_107 = F_71 ( type ) ;
if ( V_107 )
V_44 = V_107 -> V_114 . V_118 ( V_27 , V_116 + V_104 ) ;
F_69 () ;
F_72 ( V_27 , V_116 + V_104 ) ;
return V_44 ;
}
static struct V_6 * F_73 ( struct V_85 * V_85 , T_7 V_88 ,
bool V_87 , T_8 V_46 )
{
struct V_119 * V_120 = F_74 ( V_85 , V_121 ) ;
struct V_6 * V_7 ;
struct V_86 * V_8 ;
struct V_122 V_123 ;
int V_124 ;
V_7 = F_75 ( sizeof( * V_7 ) , V_77 ) ;
if ( ! V_7 )
return F_56 ( - V_75 ) ;
V_8 = F_53 ( V_85 , V_87 , V_88 , V_46 ) ;
if ( F_76 ( V_8 ) ) {
F_77 ( V_7 ) ;
return F_78 ( V_8 ) ;
}
V_7 -> V_8 = V_8 ;
V_7 -> V_125 = 1 ;
for ( V_124 = 0 ; V_124 < V_126 ; ++ V_124 )
F_79 ( & V_7 -> V_17 [ V_124 ] ) ;
F_80 ( V_7 -> V_8 , V_127 ) ;
memset ( & V_123 , 0 , sizeof( V_123 ) ) ;
V_123 . V_128 = V_7 ;
V_123 . V_129 = 1 ;
V_123 . V_115 = F_58 ;
V_123 . V_118 = F_70 ;
V_123 . V_130 = F_46 ;
V_123 . V_131 = NULL ;
F_81 ( V_85 , V_8 , & V_123 ) ;
F_82 ( & V_7 -> V_132 , & V_120 -> V_133 ) ;
return V_7 ;
}
static void F_83 ( struct V_6 * V_7 )
{
if ( ! V_7 || -- V_7 -> V_125 )
return;
F_84 ( & V_7 -> V_132 ) ;
F_85 ( V_7 -> V_8 , V_127 ) ;
F_86 ( V_7 -> V_8 ) ;
F_87 ( V_7 , V_134 ) ;
}
static void F_88 ( struct V_11 * V_15 )
{
struct V_6 * V_135 = F_89 ( V_15 -> V_136 ) ;
#if F_13 ( V_29 )
struct V_6 * V_137 = F_89 ( V_15 -> V_138 ) ;
F_90 ( V_15 -> V_138 , NULL ) ;
#endif
F_90 ( V_15 -> V_136 , NULL ) ;
F_91 () ;
F_83 ( V_135 ) ;
#if F_13 ( V_29 )
F_83 ( V_137 ) ;
#endif
}
static struct V_6 * F_92 ( struct V_119 * V_120 ,
T_5 V_91 ,
T_7 V_139 )
{
struct V_6 * V_7 ;
F_93 (gs, &gn->sock_list, list) {
if ( F_94 ( V_7 -> V_8 -> V_9 ) -> V_140 == V_139 &&
F_5 ( V_7 ) == V_91 ) {
return V_7 ;
}
}
return NULL ;
}
static int F_95 ( struct V_11 * V_15 , bool V_87 )
{
struct V_85 * V_85 = V_15 -> V_85 ;
struct V_119 * V_120 = F_74 ( V_85 , V_121 ) ;
struct V_6 * V_7 ;
T_1 V_16 ;
V_7 = F_92 ( V_120 , V_87 ? V_36 : V_31 , V_15 -> V_139 ) ;
if ( V_7 ) {
V_7 -> V_125 ++ ;
goto V_109;
}
V_7 = F_73 ( V_85 , V_15 -> V_139 , V_87 , V_15 -> V_46 ) ;
if ( F_76 ( V_7 ) )
return F_96 ( V_7 ) ;
V_109:
V_7 -> V_34 = V_15 -> V_34 ;
V_7 -> V_46 = V_15 -> V_46 ;
#if F_13 ( V_29 )
if ( V_87 )
F_90 ( V_15 -> V_138 , V_7 ) ;
else
#endif
F_90 ( V_15 -> V_136 , V_7 ) ;
V_16 = F_1 ( V_15 -> V_1 ) ;
F_97 ( & V_15 -> V_141 , & V_7 -> V_17 [ V_16 ] ) ;
return 0 ;
}
static int F_98 ( struct V_74 * V_59 )
{
struct V_11 * V_15 = F_38 ( V_59 ) ;
bool V_87 = V_15 -> V_18 . V_142 . V_143 == V_36 ;
bool V_144 = V_15 -> V_34 ;
int V_145 = 0 ;
#if F_13 ( V_29 )
if ( V_87 || V_144 )
V_145 = F_95 ( V_15 , true ) ;
#endif
if ( ! V_145 && ( ! V_87 || V_144 ) )
V_145 = F_95 ( V_15 , false ) ;
if ( V_145 < 0 )
F_88 ( V_15 ) ;
return V_145 ;
}
static int F_99 ( struct V_74 * V_59 )
{
struct V_11 * V_15 = F_38 ( V_59 ) ;
if ( ! F_100 ( & V_15 -> V_141 ) )
F_101 ( & V_15 -> V_141 ) ;
F_88 ( V_15 ) ;
return 0 ;
}
static void F_102 ( struct V_25 * V_78 ,
T_7 V_146 , T_2 V_1 [ 3 ] ,
T_2 V_147 , T_2 * V_57 )
{
V_78 -> V_81 = V_82 ;
V_78 -> V_53 = V_147 / 4 ;
V_78 -> V_49 = ! ! ( V_146 & V_50 ) ;
V_78 -> V_51 = ! ! ( V_146 & V_52 ) ;
V_78 -> V_148 = 0 ;
memcpy ( V_78 -> V_1 , V_1 , 3 ) ;
V_78 -> V_83 = F_48 ( V_84 ) ;
V_78 -> V_149 = 0 ;
memcpy ( V_78 -> V_57 , V_57 , V_147 ) ;
}
static int F_103 ( struct V_150 * V_151 , struct V_26 * V_27 ,
T_7 V_146 , T_2 V_1 [ 3 ] , T_2 V_53 , T_2 * V_152 ,
T_8 V_46 , bool V_153 )
{
struct V_25 * V_39 ;
int V_154 ;
int V_44 ;
bool V_155 = ! ( V_46 & V_156 ) ;
F_104 ( V_27 , V_153 ) ;
V_154 = F_105 ( V_151 -> V_61 . V_59 ) + V_151 -> V_61 . V_157
+ V_80 + V_53 + sizeof( struct V_32 ) ;
V_44 = F_106 ( V_27 , V_154 ) ;
if ( F_30 ( V_44 ) )
goto V_158;
V_44 = F_107 ( V_27 , V_155 ) ;
if ( V_44 )
goto V_158;
V_39 = (struct V_25 * ) F_108 ( V_27 , sizeof( * V_39 ) + V_53 ) ;
F_102 ( V_39 , V_146 , V_1 , V_53 , V_152 ) ;
F_109 ( V_27 , F_48 ( V_84 ) ) ;
return 0 ;
V_158:
F_110 ( V_151 ) ;
return V_44 ;
}
static int F_111 ( struct V_159 * V_61 , struct V_26 * V_27 ,
T_7 V_146 , T_2 V_1 [ 3 ] , T_2 V_53 , T_2 * V_152 ,
T_8 V_46 , bool V_153 )
{
struct V_25 * V_39 ;
int V_154 ;
int V_44 ;
bool V_155 = ! ( V_46 & V_160 ) ;
F_104 ( V_27 , V_153 ) ;
V_154 = F_105 ( V_61 -> V_59 ) + V_61 -> V_157
+ V_80 + V_53 + sizeof( struct V_37 ) ;
V_44 = F_106 ( V_27 , V_154 ) ;
if ( F_30 ( V_44 ) )
goto V_161;
V_44 = F_107 ( V_27 , V_155 ) ;
if ( V_44 )
goto V_161;
V_39 = (struct V_25 * ) F_108 ( V_27 , sizeof( * V_39 ) + V_53 ) ;
F_102 ( V_39 , V_146 , V_1 , V_53 , V_152 ) ;
F_109 ( V_27 , F_48 ( V_84 ) ) ;
return 0 ;
V_161:
F_112 ( V_61 ) ;
return V_44 ;
}
static struct V_150 * F_113 ( struct V_26 * V_27 ,
struct V_74 * V_59 ,
struct V_162 * V_163 ,
struct V_164 * V_165 )
{
bool V_166 = F_114 ( V_27 , V_165 ) ;
struct V_11 * V_15 = F_38 ( V_59 ) ;
struct V_76 * V_76 ;
struct V_150 * V_151 = NULL ;
T_4 V_65 ;
if ( ! F_115 ( V_15 -> V_136 ) )
return F_56 ( - V_167 ) ;
memset ( V_163 , 0 , sizeof( * V_163 ) ) ;
V_163 -> V_168 = V_27 -> V_169 ;
V_163 -> V_170 = V_171 ;
if ( V_165 ) {
V_163 -> V_172 = V_165 -> V_173 . V_55 . V_174 . V_61 ;
V_163 -> V_35 = V_165 -> V_173 . V_55 . V_174 . V_175 ;
V_163 -> V_176 = F_116 ( V_165 -> V_173 . V_65 ) ;
V_76 = & V_165 -> V_76 ;
} else {
V_65 = V_15 -> V_65 ;
if ( V_65 == 1 ) {
const struct V_32 * V_177 = F_14 ( V_27 ) ;
V_65 = F_117 ( V_177 , V_27 ) ;
V_166 = false ;
}
V_163 -> V_176 = F_116 ( V_65 ) ;
V_163 -> V_172 = V_15 -> V_18 . sin . V_19 . V_20 ;
V_76 = & V_15 -> V_76 ;
}
if ( V_166 ) {
V_151 = F_118 ( V_76 , & V_163 -> V_35 ) ;
if ( V_151 )
return V_151 ;
}
V_151 = F_119 ( V_15 -> V_85 , V_163 ) ;
if ( F_76 ( V_151 ) ) {
F_120 ( V_59 , L_4 , & V_163 -> V_172 ) ;
return F_56 ( - V_178 ) ;
}
if ( V_151 -> V_61 . V_59 == V_59 ) {
F_120 ( V_59 , L_5 , & V_163 -> V_172 ) ;
F_110 ( V_151 ) ;
return F_56 ( - V_179 ) ;
}
if ( V_166 )
F_121 ( V_76 , & V_151 -> V_61 , V_163 -> V_35 ) ;
return V_151 ;
}
static struct V_159 * F_122 ( struct V_26 * V_27 ,
struct V_74 * V_59 ,
struct V_180 * V_181 ,
struct V_164 * V_165 )
{
bool V_166 = F_114 ( V_27 , V_165 ) ;
struct V_11 * V_15 = F_38 ( V_59 ) ;
struct V_159 * V_61 = NULL ;
struct V_76 * V_76 ;
struct V_6 * V_137 ;
T_4 V_182 ;
V_137 = F_115 ( V_15 -> V_138 ) ;
if ( ! V_137 )
return F_56 ( - V_167 ) ;
memset ( V_181 , 0 , sizeof( * V_181 ) ) ;
V_181 -> V_183 = V_27 -> V_169 ;
V_181 -> V_184 = V_171 ;
if ( V_165 ) {
V_181 -> V_172 = V_165 -> V_173 . V_55 . V_87 . V_61 ;
V_181 -> V_35 = V_165 -> V_173 . V_55 . V_87 . V_175 ;
V_181 -> V_185 = F_123 ( F_116 ( V_165 -> V_173 . V_65 ) ,
V_165 -> V_173 . V_186 ) ;
V_76 = & V_165 -> V_76 ;
} else {
V_182 = V_15 -> V_65 ;
if ( V_182 == 1 ) {
const struct V_32 * V_177 = F_14 ( V_27 ) ;
V_182 = F_117 ( V_177 , V_27 ) ;
V_166 = false ;
}
V_181 -> V_185 = F_123 ( F_116 ( V_182 ) ,
V_15 -> V_186 ) ;
V_181 -> V_172 = V_15 -> V_18 . V_23 . V_24 ;
V_76 = & V_15 -> V_76 ;
}
if ( V_166 ) {
V_61 = F_124 ( V_76 , & V_181 -> V_35 ) ;
if ( V_61 )
return V_61 ;
}
if ( V_187 -> V_188 ( V_15 -> V_85 , V_137 -> V_8 -> V_9 , & V_61 , V_181 ) ) {
F_120 ( V_59 , L_6 , & V_181 -> V_172 ) ;
return F_56 ( - V_178 ) ;
}
if ( V_61 -> V_59 == V_59 ) {
F_120 ( V_59 , L_7 , & V_181 -> V_172 ) ;
F_112 ( V_61 ) ;
return F_56 ( - V_179 ) ;
}
if ( V_166 )
F_125 ( V_76 , V_61 , & V_181 -> V_35 ) ;
return V_61 ;
}
static void F_126 ( T_3 V_189 , T_4 * V_1 )
{
#ifdef F_4
V_1 [ 0 ] = ( V_4 T_4 ) ( V_189 >> 16 ) ;
V_1 [ 1 ] = ( V_4 T_4 ) ( V_189 >> 8 ) ;
V_1 [ 2 ] = ( V_4 T_4 ) V_189 ;
#else
V_1 [ 0 ] = ( V_4 T_4 ) ( ( V_4 V_5 ) V_189 >> 40 ) ;
V_1 [ 1 ] = ( V_4 T_4 ) ( ( V_4 V_5 ) V_189 >> 48 ) ;
V_1 [ 2 ] = ( V_4 T_4 ) ( ( V_4 V_5 ) V_189 >> 56 ) ;
#endif
}
static T_9 F_127 ( struct V_26 * V_27 , struct V_74 * V_59 ,
struct V_164 * V_165 )
{
struct V_11 * V_15 = F_38 ( V_59 ) ;
struct V_6 * V_135 ;
struct V_150 * V_151 = NULL ;
int V_44 = - V_190 ;
struct V_162 V_163 ;
T_4 V_65 , V_191 ;
T_7 V_192 ;
T_7 V_193 ;
bool V_153 = ! F_51 ( V_15 -> V_85 , F_52 ( V_15 -> V_59 ) ) ;
T_8 V_46 = V_15 -> V_46 ;
V_135 = F_115 ( V_15 -> V_136 ) ;
if ( ! V_135 )
goto V_194;
if ( V_15 -> V_34 ) {
if ( F_30 ( ! V_165 || ! ( V_165 -> V_195 & V_196 ) ) ) {
F_120 ( V_59 , L_8 ) ;
goto V_194;
}
if ( V_165 && F_128 ( V_165 ) != V_31 )
goto V_194;
}
V_151 = F_113 ( V_27 , V_59 , & V_163 , V_165 ) ;
if ( F_76 ( V_151 ) ) {
V_44 = F_96 ( V_151 ) ;
goto V_194;
}
V_192 = F_129 ( V_15 -> V_85 , V_27 , 1 , V_197 , true ) ;
F_20 ( V_27 ) ;
if ( V_165 ) {
const struct V_198 * V_173 = & V_165 -> V_173 ;
T_2 * V_199 = NULL ;
T_2 V_1 [ 3 ] ;
F_126 ( V_173 -> V_189 , V_1 ) ;
if ( V_165 -> V_147 )
V_199 = F_130 ( V_165 ) ;
if ( V_173 -> V_146 & V_200 )
V_46 &= ~ V_156 ;
else
V_46 |= V_156 ;
V_44 = F_103 ( V_151 , V_27 , V_173 -> V_146 , V_1 ,
V_165 -> V_147 , V_199 , V_46 , V_153 ) ;
if ( F_30 ( V_44 ) )
goto V_194;
V_65 = F_131 ( V_173 -> V_65 , F_14 ( V_27 ) , V_27 ) ;
V_191 = V_173 -> V_191 ;
V_193 = V_173 -> V_146 & V_201 ? F_48 ( V_202 ) : 0 ;
} else {
V_44 = F_103 ( V_151 , V_27 , 0 , V_15 -> V_1 ,
0 , NULL , V_46 , V_153 ) ;
if ( F_30 ( V_44 ) )
goto V_194;
V_65 = F_131 ( V_163 . V_176 , F_14 ( V_27 ) , V_27 ) ;
V_191 = V_15 -> V_191 ;
if ( ! V_191 && F_132 ( F_133 ( V_163 . V_172 ) ) )
V_191 = 1 ;
V_191 = V_191 ? : F_134 ( & V_151 -> V_61 ) ;
V_193 = 0 ;
}
F_135 ( V_151 , V_135 -> V_8 -> V_9 , V_27 , V_163 . V_35 , V_163 . V_172 ,
V_65 , V_191 , V_193 , V_192 , V_15 -> V_139 ,
! F_51 ( V_15 -> V_85 , F_52 ( V_15 -> V_59 ) ) ,
! ! ( V_46 & V_156 ) ) ;
return V_203 ;
V_194:
F_136 ( V_27 ) ;
if ( V_44 == - V_179 )
V_59 -> V_43 . V_204 ++ ;
else if ( V_44 == - V_178 )
V_59 -> V_43 . V_205 ++ ;
V_59 -> V_43 . V_206 ++ ;
return V_203 ;
}
static T_9 F_137 ( struct V_26 * V_27 , struct V_74 * V_59 ,
struct V_164 * V_165 )
{
struct V_11 * V_15 = F_38 ( V_59 ) ;
struct V_159 * V_61 = NULL ;
struct V_6 * V_137 ;
int V_44 = - V_190 ;
struct V_180 V_181 ;
T_4 V_182 , V_191 ;
T_7 V_192 ;
T_6 V_186 ;
bool V_153 = ! F_51 ( V_15 -> V_85 , F_52 ( V_15 -> V_59 ) ) ;
T_8 V_46 = V_15 -> V_46 ;
V_137 = F_115 ( V_15 -> V_138 ) ;
if ( ! V_137 )
goto V_194;
if ( V_15 -> V_34 ) {
if ( F_30 ( ! V_165 || ! ( V_165 -> V_195 & V_196 ) ) ) {
F_120 ( V_59 , L_8 ) ;
goto V_194;
}
}
V_61 = F_122 ( V_27 , V_59 , & V_181 , V_165 ) ;
if ( F_76 ( V_61 ) ) {
V_44 = F_96 ( V_61 ) ;
goto V_194;
}
V_192 = F_129 ( V_15 -> V_85 , V_27 , 1 , V_197 , true ) ;
F_20 ( V_27 ) ;
if ( V_165 ) {
const struct V_198 * V_173 = & V_165 -> V_173 ;
T_2 * V_199 = NULL ;
T_2 V_1 [ 3 ] ;
F_126 ( V_173 -> V_189 , V_1 ) ;
if ( V_165 -> V_147 )
V_199 = F_130 ( V_165 ) ;
if ( V_173 -> V_146 & V_200 )
V_46 &= ~ V_160 ;
else
V_46 |= V_160 ;
V_44 = F_111 ( V_61 , V_27 , V_173 -> V_146 , V_1 ,
V_165 -> V_147 , V_199 ,
V_46 , V_153 ) ;
if ( F_30 ( V_44 ) )
goto V_194;
V_182 = F_131 ( V_173 -> V_65 , F_14 ( V_27 ) , V_27 ) ;
V_191 = V_173 -> V_191 ;
V_186 = V_165 -> V_173 . V_186 ;
} else {
V_44 = F_111 ( V_61 , V_27 , 0 , V_15 -> V_1 ,
0 , NULL , V_46 , V_153 ) ;
if ( F_30 ( V_44 ) )
goto V_194;
V_182 = F_131 ( F_138 ( V_181 . V_185 ) ,
F_14 ( V_27 ) , V_27 ) ;
V_191 = V_15 -> V_191 ;
if ( ! V_191 && F_139 ( & V_181 . V_172 ) )
V_191 = 1 ;
V_191 = V_191 ? : F_140 ( V_61 ) ;
V_186 = V_15 -> V_186 ;
}
F_141 ( V_61 , V_137 -> V_8 -> V_9 , V_27 , V_59 ,
& V_181 . V_35 , & V_181 . V_172 , V_182 , V_191 , V_186 ,
V_192 , V_15 -> V_139 ,
! ! ( V_46 & V_160 ) ) ;
return V_203 ;
V_194:
F_136 ( V_27 ) ;
if ( V_44 == - V_179 )
V_59 -> V_43 . V_204 ++ ;
else if ( V_44 == - V_178 )
V_59 -> V_43 . V_205 ++ ;
V_59 -> V_43 . V_206 ++ ;
return V_203 ;
}
static T_9 F_142 ( struct V_26 * V_27 , struct V_74 * V_59 )
{
struct V_11 * V_15 = F_38 ( V_59 ) ;
struct V_164 * V_165 = NULL ;
if ( V_15 -> V_34 )
V_165 = F_143 ( V_27 ) ;
#if F_13 ( V_29 )
if ( ( V_165 && F_128 ( V_165 ) == V_36 ) ||
( ! V_165 && V_15 -> V_18 . V_142 . V_143 == V_36 ) )
return F_137 ( V_27 , V_59 , V_165 ) ;
#endif
return F_127 ( V_27 , V_59 , V_165 ) ;
}
static int F_144 ( struct V_74 * V_59 , int V_207 , bool V_208 )
{
struct V_11 * V_15 = F_38 ( V_59 ) ;
int V_209 = V_210 - V_80 - V_59 -> V_211 ;
if ( V_15 -> V_18 . V_142 . V_143 == V_36 )
V_209 -= sizeof( struct V_37 ) ;
else
V_209 -= sizeof( struct V_32 ) ;
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
static int F_145 ( struct V_74 * V_59 , int V_207 )
{
return F_144 ( V_59 , V_207 , true ) ;
}
static int F_146 ( struct V_74 * V_59 , struct V_26 * V_27 )
{
struct V_164 * V_165 = F_143 ( V_27 ) ;
struct V_11 * V_15 = F_38 ( V_59 ) ;
struct V_150 * V_151 ;
struct V_162 V_163 ;
#if F_13 ( V_29 )
struct V_159 * V_61 ;
struct V_180 V_181 ;
#endif
if ( F_128 ( V_165 ) == V_31 ) {
V_151 = F_113 ( V_27 , V_59 , & V_163 , V_165 ) ;
if ( F_76 ( V_151 ) )
return F_96 ( V_151 ) ;
F_110 ( V_151 ) ;
V_165 -> V_173 . V_55 . V_174 . V_175 = V_163 . V_35 ;
#if F_13 ( V_29 )
} else if ( F_128 ( V_165 ) == V_36 ) {
V_61 = F_122 ( V_27 , V_59 , & V_181 , V_165 ) ;
if ( F_76 ( V_61 ) )
return F_96 ( V_61 ) ;
F_112 ( V_61 ) ;
V_165 -> V_173 . V_55 . V_87 . V_175 = V_181 . V_35 ;
#endif
} else {
return - V_190 ;
}
V_165 -> V_173 . V_213 = F_129 ( V_15 -> V_85 , V_27 ,
1 , V_197 , true ) ;
V_165 -> V_173 . V_214 = V_15 -> V_139 ;
return 0 ;
}
static void F_147 ( struct V_74 * V_59 ,
struct V_215 * V_216 )
{
F_148 ( V_216 -> V_217 , V_218 , sizeof( V_216 -> V_217 ) ) ;
F_148 ( V_216 -> V_219 , L_9 , sizeof( V_216 -> V_219 ) ) ;
}
static void F_149 ( struct V_74 * V_59 )
{
struct V_85 * V_85 = F_52 ( V_59 ) ;
struct V_119 * V_120 = F_74 ( V_85 , V_121 ) ;
struct V_6 * V_7 ;
F_64 () ;
F_150 (gs, &gn->sock_list, list)
F_151 ( V_59 , V_7 -> V_8 ,
V_127 ) ;
F_69 () ;
}
static void F_152 ( struct V_74 * V_59 )
{
F_153 ( V_59 ) ;
V_59 -> V_220 = & V_221 ;
V_59 -> V_222 = & V_223 ;
V_59 -> V_224 = V_225 ;
F_154 ( V_59 , & V_226 ) ;
V_59 -> V_227 |= V_228 ;
V_59 -> V_227 |= V_229 | V_230 ;
V_59 -> V_227 |= V_231 ;
V_59 -> V_227 |= V_232 ;
V_59 -> V_233 |= V_229 | V_230 | V_231 ;
V_59 -> V_233 |= V_232 ;
F_155 ( V_59 ) ;
V_59 -> V_234 &= ~ V_235 ;
V_59 -> V_234 |= V_236 | V_237 ;
F_156 ( V_59 ) ;
}
static int F_157 ( struct V_238 * V_239 [] , struct V_238 * V_112 [] )
{
if ( V_239 [ V_240 ] ) {
if ( F_158 ( V_239 [ V_240 ] ) != V_241 )
return - V_190 ;
if ( ! F_159 ( F_160 ( V_239 [ V_240 ] ) ) )
return - V_242 ;
}
if ( ! V_112 )
return - V_190 ;
if ( V_112 [ V_243 ] ) {
T_1 V_1 = F_161 ( V_112 [ V_243 ] ) ;
if ( V_1 >= V_244 )
return - V_245 ;
}
return 0 ;
}
static struct V_11 * F_162 ( struct V_119 * V_120 ,
T_7 V_139 ,
union V_246 * V_18 ,
T_2 V_1 [] ,
bool * V_247 ,
bool * V_248 )
{
struct V_11 * V_15 , * V_249 ;
* V_247 = false ;
* V_248 = false ;
V_249 = NULL ;
F_93 (geneve, &gn->geneve_list, next) {
if ( V_15 -> V_139 == V_139 ) {
* V_248 = V_15 -> V_34 ;
* V_247 = true ;
}
if ( ! memcmp ( V_1 , V_15 -> V_1 , sizeof( V_15 -> V_1 ) ) &&
! memcmp ( V_18 , & V_15 -> V_18 , sizeof( V_15 -> V_18 ) ) &&
V_139 == V_15 -> V_139 )
V_249 = V_15 ;
}
return V_249 ;
}
static int F_163 ( struct V_85 * V_85 , struct V_74 * V_59 ,
union V_246 * V_18 ,
T_1 V_1 , T_4 V_191 , T_4 V_65 , T_6 V_186 ,
T_7 V_139 , bool V_144 , T_8 V_46 )
{
struct V_119 * V_120 = F_74 ( V_85 , V_121 ) ;
struct V_11 * V_249 , * V_15 = F_38 ( V_59 ) ;
bool V_248 , V_247 ;
int V_44 , V_250 ;
if ( ! V_18 )
return - V_190 ;
if ( V_144 &&
( V_18 -> V_142 . V_143 != V_251 || V_1 || V_65 || V_191 || V_186 ) )
return - V_190 ;
V_15 -> V_85 = V_85 ;
V_15 -> V_59 = V_59 ;
V_15 -> V_1 [ 0 ] = ( V_1 & 0x00ff0000 ) >> 16 ;
V_15 -> V_1 [ 1 ] = ( V_1 & 0x0000ff00 ) >> 8 ;
V_15 -> V_1 [ 2 ] = V_1 & 0x000000ff ;
if ( ( V_18 -> V_142 . V_143 == V_31 &&
F_132 ( F_133 ( V_18 -> sin . V_19 . V_20 ) ) ) ||
( V_18 -> V_142 . V_143 == V_36 &&
F_139 ( & V_18 -> V_23 . V_24 ) ) )
return - V_190 ;
if ( V_186 && V_18 -> V_142 . V_143 != V_36 )
return - V_190 ;
V_15 -> V_18 = * V_18 ;
V_15 -> V_191 = V_191 ;
V_15 -> V_65 = V_65 ;
V_15 -> V_186 = V_186 ;
V_15 -> V_139 = V_139 ;
V_15 -> V_34 = V_144 ;
V_15 -> V_46 = V_46 ;
V_249 = F_162 ( V_120 , V_139 , V_18 , V_15 -> V_1 ,
& V_247 , & V_248 ) ;
if ( V_249 )
return - V_252 ;
V_250 = V_80 + V_60 ;
if ( V_18 -> V_142 . V_143 == V_31 )
V_250 += sizeof( struct V_32 ) ;
else
V_250 += sizeof( struct V_37 ) ;
V_59 -> V_253 = V_250 + V_60 ;
if ( V_144 ) {
if ( V_247 )
return - V_254 ;
} else {
if ( V_248 )
return - V_254 ;
}
F_164 ( & V_15 -> V_76 ) ;
V_44 = F_165 ( V_59 ) ;
if ( V_44 )
return V_44 ;
F_82 ( & V_15 -> V_110 , & V_120 -> V_255 ) ;
return 0 ;
}
static int F_166 ( struct V_85 * V_85 , struct V_74 * V_59 ,
struct V_238 * V_239 [] , struct V_238 * V_112 [] )
{
T_7 V_139 = F_48 ( V_256 ) ;
T_4 V_191 = 0 , V_65 = 0 ;
bool V_144 = false ;
union V_246 V_18 = V_257 ;
T_6 V_186 = 0 ;
T_1 V_1 = 0 ;
T_8 V_46 = 0 ;
if ( V_112 [ V_258 ] && V_112 [ V_259 ] )
return - V_190 ;
if ( V_112 [ V_258 ] ) {
V_18 . V_142 . V_143 = V_31 ;
V_18 . sin . V_19 . V_20 =
F_167 ( V_112 [ V_258 ] ) ;
}
if ( V_112 [ V_259 ] ) {
if ( ! F_13 ( V_29 ) )
return - V_260 ;
V_18 . V_142 . V_143 = V_36 ;
V_18 . V_23 . V_24 =
F_168 ( V_112 [ V_259 ] ) ;
if ( F_169 ( & V_18 . V_23 . V_24 ) &
V_261 ) {
F_120 ( V_59 , L_10 ) ;
return - V_190 ;
}
}
if ( V_112 [ V_243 ] )
V_1 = F_161 ( V_112 [ V_243 ] ) ;
if ( V_112 [ V_262 ] )
V_191 = F_170 ( V_112 [ V_262 ] ) ;
if ( V_112 [ V_263 ] )
V_65 = F_170 ( V_112 [ V_263 ] ) ;
if ( V_112 [ V_264 ] )
V_186 = F_171 ( V_112 [ V_264 ] ) &
V_265 ;
if ( V_112 [ V_266 ] )
V_139 = F_172 ( V_112 [ V_266 ] ) ;
if ( V_112 [ V_267 ] )
V_144 = true ;
if ( V_112 [ V_268 ] &&
! F_170 ( V_112 [ V_268 ] ) )
V_46 |= V_156 ;
if ( V_112 [ V_269 ] &&
F_170 ( V_112 [ V_269 ] ) )
V_46 |= V_160 ;
if ( V_112 [ V_270 ] &&
F_170 ( V_112 [ V_270 ] ) )
V_46 |= V_94 ;
return F_163 ( V_85 , V_59 , & V_18 , V_1 , V_191 , V_65 , V_186 ,
V_139 , V_144 , V_46 ) ;
}
static void F_173 ( struct V_74 * V_59 , struct V_271 * V_99 )
{
struct V_11 * V_15 = F_38 ( V_59 ) ;
F_84 ( & V_15 -> V_110 ) ;
F_174 ( V_59 , V_99 ) ;
}
static T_10 F_175 ( const struct V_74 * V_59 )
{
return F_176 ( sizeof( T_1 ) ) +
F_176 ( sizeof( struct V_21 ) ) +
F_176 ( sizeof( T_4 ) ) +
F_176 ( sizeof( T_4 ) ) +
F_176 ( sizeof( T_6 ) ) +
F_176 ( sizeof( T_7 ) ) +
F_176 ( 0 ) +
F_176 ( sizeof( T_4 ) ) +
F_176 ( sizeof( T_4 ) ) +
F_176 ( sizeof( T_4 ) ) +
0 ;
}
static int F_177 ( struct V_26 * V_27 , const struct V_74 * V_59 )
{
struct V_11 * V_15 = F_38 ( V_59 ) ;
T_1 V_1 ;
V_1 = ( V_15 -> V_1 [ 0 ] << 16 ) | ( V_15 -> V_1 [ 1 ] << 8 ) | V_15 -> V_1 [ 2 ] ;
if ( F_178 ( V_27 , V_243 , V_1 ) )
goto V_272;
if ( V_15 -> V_18 . V_142 . V_143 == V_31 ) {
if ( F_179 ( V_27 , V_258 ,
V_15 -> V_18 . sin . V_19 . V_20 ) )
goto V_272;
#if F_13 ( V_29 )
} else {
if ( F_180 ( V_27 , V_259 ,
& V_15 -> V_18 . V_23 . V_24 ) )
goto V_272;
#endif
}
if ( F_181 ( V_27 , V_262 , V_15 -> V_191 ) ||
F_181 ( V_27 , V_263 , V_15 -> V_65 ) ||
F_182 ( V_27 , V_264 , V_15 -> V_186 ) )
goto V_272;
if ( F_183 ( V_27 , V_266 , V_15 -> V_139 ) )
goto V_272;
if ( V_15 -> V_34 ) {
if ( F_184 ( V_27 , V_267 ) )
goto V_272;
}
if ( F_181 ( V_27 , V_268 ,
! ( V_15 -> V_46 & V_156 ) ) ||
F_181 ( V_27 , V_269 ,
! ! ( V_15 -> V_46 & V_160 ) ) ||
F_181 ( V_27 , V_270 ,
! ! ( V_15 -> V_46 & V_94 ) ) )
goto V_272;
return 0 ;
V_272:
return - V_273 ;
}
struct V_74 * F_185 ( struct V_85 * V_85 , const char * V_274 ,
T_2 V_275 , T_11 V_139 )
{
struct V_238 * V_239 [ V_276 + 1 ] ;
struct V_74 * V_59 ;
F_186 ( V_277 ) ;
int V_44 ;
memset ( V_239 , 0 , sizeof( V_239 ) ) ;
V_59 = F_187 ( V_85 , V_274 , V_275 ,
& V_278 , V_239 ) ;
if ( F_76 ( V_59 ) )
return V_59 ;
V_44 = F_163 ( V_85 , V_59 , & V_257 ,
0 , 0 , 0 , 0 , F_48 ( V_139 ) , true ,
V_94 ) ;
if ( V_44 ) {
V_225 ( V_59 ) ;
return F_56 ( V_44 ) ;
}
V_44 = F_144 ( V_59 , V_210 , false ) ;
if ( V_44 )
goto V_44;
V_44 = F_188 ( V_59 , NULL ) ;
if ( V_44 < 0 )
goto V_44;
return V_59 ;
V_44:
F_173 ( V_59 , & V_277 ) ;
F_189 ( & V_277 ) ;
return F_56 ( V_44 ) ;
}
static int F_190 ( struct V_279 * V_280 ,
unsigned long V_281 , void * V_282 )
{
struct V_74 * V_59 = F_191 ( V_282 ) ;
if ( V_281 == V_283 )
F_149 ( V_59 ) ;
return V_284 ;
}
static T_12 int F_192 ( struct V_85 * V_85 )
{
struct V_119 * V_120 = F_74 ( V_85 , V_121 ) ;
F_193 ( & V_120 -> V_255 ) ;
F_193 ( & V_120 -> V_133 ) ;
return 0 ;
}
static void T_13 F_194 ( struct V_85 * V_85 )
{
struct V_119 * V_120 = F_74 ( V_85 , V_121 ) ;
struct V_11 * V_15 , * V_110 ;
struct V_74 * V_59 , * V_285 ;
F_186 ( V_132 ) ;
F_195 () ;
F_196 (net, dev, aux)
if ( V_59 -> V_286 == & V_278 )
F_174 ( V_59 , & V_132 ) ;
F_197 (geneve, next, &gn->geneve_list, next) {
if ( ! F_51 ( F_52 ( V_15 -> V_59 ) , V_85 ) )
F_174 ( V_15 -> V_59 , & V_132 ) ;
}
F_189 ( & V_132 ) ;
F_198 () ;
}
static int T_14 F_199 ( void )
{
int V_287 ;
V_287 = F_200 ( & V_288 ) ;
if ( V_287 )
goto V_289;
V_287 = F_201 ( & V_290 ) ;
if ( V_287 )
goto V_291;
V_287 = F_202 ( & V_278 ) ;
if ( V_287 )
goto V_292;
return 0 ;
V_292:
F_203 ( & V_290 ) ;
V_291:
F_204 ( & V_288 ) ;
V_289:
return V_287 ;
}
static void T_15 F_205 ( void )
{
F_206 ( & V_278 ) ;
F_203 ( & V_290 ) ;
F_204 ( & V_288 ) ;
}
