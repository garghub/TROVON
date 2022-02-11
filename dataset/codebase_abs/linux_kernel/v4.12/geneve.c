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
#ifdef F_4
return ( V_1 [ 0 ] == V_6 [ 2 ] ) &&
( V_1 [ 1 ] == V_6 [ 1 ] ) &&
( V_1 [ 2 ] == V_6 [ 0 ] ) ;
#else
return ! memcmp ( V_1 , & V_6 [ 5 ] , 3 ) ;
#endif
}
static T_5 F_7 ( struct V_7 * V_8 )
{
return V_8 -> V_9 -> V_10 -> V_11 ;
}
static struct V_12 * F_8 ( struct V_7 * V_8 ,
T_6 V_13 , T_2 V_1 [] )
{
struct V_14 * V_15 ;
struct V_12 * V_16 ;
T_1 V_17 ;
V_17 = F_1 ( V_1 ) ;
V_15 = & V_8 -> V_18 [ V_17 ] ;
F_9 (geneve, vni_list_head, hlist) {
if ( F_6 ( ( T_2 * ) & V_16 -> V_19 . V_20 . V_6 , V_1 ) &&
V_13 == V_16 -> V_19 . V_20 . V_21 . V_22 . V_23 )
return V_16 ;
}
return NULL ;
}
static struct V_12 * F_10 ( struct V_7 * V_8 ,
struct V_24 V_25 , T_2 V_1 [] )
{
struct V_14 * V_15 ;
struct V_12 * V_16 ;
T_1 V_17 ;
V_17 = F_1 ( V_1 ) ;
V_15 = & V_8 -> V_18 [ V_17 ] ;
F_9 (geneve, vni_list_head, hlist) {
if ( F_6 ( ( T_2 * ) & V_16 -> V_19 . V_20 . V_6 , V_1 ) &&
F_11 ( & V_25 , & V_16 -> V_19 . V_20 . V_21 . V_26 . V_23 ) )
return V_16 ;
}
return NULL ;
}
static inline struct V_27 * F_12 ( const struct V_28 * V_29 )
{
return (struct V_27 * ) ( F_13 ( V_29 ) + 1 ) ;
}
static struct V_12 * F_14 ( struct V_7 * V_8 ,
struct V_28 * V_29 )
{
static T_2 V_30 [ 3 ] ;
T_2 * V_1 ;
if ( F_7 ( V_8 ) == V_31 ) {
struct V_32 * V_33 ;
T_6 V_13 ;
V_33 = F_15 ( V_29 ) ;
if ( V_8 -> V_34 ) {
V_1 = V_30 ;
V_13 = 0 ;
} else {
V_1 = F_12 ( V_29 ) -> V_1 ;
V_13 = V_33 -> V_35 ;
}
return F_8 ( V_8 , V_13 , V_1 ) ;
#if F_16 ( V_36 )
} else if ( F_7 ( V_8 ) == V_37 ) {
static struct V_24 V_38 ;
struct V_39 * V_40 ;
struct V_24 V_25 ;
V_40 = F_17 ( V_29 ) ;
if ( V_8 -> V_34 ) {
V_1 = V_30 ;
V_25 = V_38 ;
} else {
V_1 = F_12 ( V_29 ) -> V_1 ;
V_25 = V_40 -> V_35 ;
}
return F_10 ( V_8 , V_25 , V_1 ) ;
#endif
}
return NULL ;
}
static void F_18 ( struct V_12 * V_16 , struct V_7 * V_8 ,
struct V_28 * V_29 )
{
struct V_27 * V_41 = F_12 ( V_29 ) ;
struct V_42 * V_43 = NULL ;
struct V_44 * V_45 ;
int V_46 = 0 ;
void * V_47 ;
if ( F_19 () || V_8 -> V_34 ) {
T_7 V_48 ;
V_48 = V_49 | V_50 |
( V_41 -> V_51 ? V_52 : 0 ) |
( V_41 -> V_53 ? V_54 : 0 ) ;
V_43 = F_20 ( V_29 , F_7 ( V_8 ) , V_48 ,
F_3 ( V_41 -> V_1 ) ,
V_41 -> V_55 * 4 ) ;
if ( ! V_43 )
goto V_56;
F_21 ( & V_43 -> V_21 . V_57 ,
V_41 -> V_58 , V_41 -> V_55 * 4 ) ;
} else {
if ( V_41 -> V_53 )
goto V_56;
}
F_22 ( V_29 ) ;
V_29 -> V_59 = F_23 ( V_29 , V_16 -> V_60 ) ;
F_24 ( V_29 , F_25 ( V_29 ) , V_61 ) ;
if ( V_43 )
F_26 ( V_29 , & V_43 -> V_23 ) ;
if ( F_27 ( F_25 ( V_29 ) -> V_62 , V_16 -> V_60 -> V_63 ) )
goto V_56;
V_47 = F_28 ( V_29 ) ;
F_29 ( V_29 ) ;
if ( F_7 ( V_8 ) == V_31 )
V_46 = F_30 ( V_47 , V_29 ) ;
#if F_16 ( V_36 )
else
V_46 = F_31 ( V_47 , V_29 ) ;
#endif
if ( F_32 ( V_46 ) ) {
if ( V_64 ) {
if ( F_7 ( V_8 ) == V_31 )
F_33 ( L_1
L_2 ,
& ( (struct V_32 * ) V_47 ) -> V_35 ,
( (struct V_32 * ) V_47 ) -> V_65 ) ;
#if F_16 ( V_36 )
else
F_33 ( L_3 ,
& ( (struct V_39 * ) V_47 ) -> V_35 ) ;
#endif
}
if ( V_46 > 1 ) {
++ V_16 -> V_60 -> V_45 . V_66 ;
++ V_16 -> V_60 -> V_45 . V_67 ;
goto V_56;
}
}
V_45 = F_34 ( V_16 -> V_60 -> V_68 ) ;
F_35 ( & V_45 -> V_69 ) ;
V_45 -> V_70 ++ ;
V_45 -> V_71 += V_29 -> V_72 ;
F_36 ( & V_45 -> V_69 ) ;
F_37 ( & V_16 -> V_73 , V_29 ) ;
return;
V_56:
F_38 ( V_29 ) ;
}
static int F_39 ( struct V_74 * V_60 )
{
struct V_12 * V_16 = F_40 ( V_60 ) ;
int V_46 ;
V_60 -> V_68 = F_41 ( struct V_44 ) ;
if ( ! V_60 -> V_68 )
return - V_75 ;
V_46 = F_42 ( & V_16 -> V_73 , V_60 ) ;
if ( V_46 ) {
F_43 ( V_60 -> V_68 ) ;
return V_46 ;
}
V_46 = F_44 ( & V_16 -> V_19 . V_76 , V_77 ) ;
if ( V_46 ) {
F_43 ( V_60 -> V_68 ) ;
F_45 ( & V_16 -> V_73 ) ;
return V_46 ;
}
return 0 ;
}
static void F_46 ( struct V_74 * V_60 )
{
struct V_12 * V_16 = F_40 ( V_60 ) ;
F_47 ( & V_16 -> V_19 . V_76 ) ;
F_45 ( & V_16 -> V_73 ) ;
F_43 ( V_60 -> V_68 ) ;
}
static int F_48 ( struct V_9 * V_10 , struct V_28 * V_29 )
{
struct V_27 * V_78 ;
struct V_12 * V_16 ;
struct V_7 * V_8 ;
int V_79 ;
if ( F_32 ( ! F_49 ( V_29 , V_80 ) ) )
goto V_56;
V_78 = F_12 ( V_29 ) ;
if ( F_32 ( V_78 -> V_81 != V_82 ) )
goto V_56;
if ( F_32 ( V_78 -> V_83 != F_50 ( V_84 ) ) )
goto V_56;
V_8 = F_51 ( V_10 ) ;
if ( ! V_8 )
goto V_56;
V_16 = F_14 ( V_8 , V_29 ) ;
if ( ! V_16 )
goto V_56;
V_79 = V_78 -> V_55 * 4 ;
if ( F_52 ( V_29 , V_80 + V_79 ,
F_50 ( V_84 ) ,
! F_53 ( V_16 -> V_85 , F_54 ( V_16 -> V_60 ) ) ) )
goto V_56;
F_18 ( V_16 , V_8 , V_29 ) ;
return 0 ;
V_56:
F_38 ( V_29 ) ;
return 0 ;
}
static struct V_86 * F_55 ( struct V_85 * V_85 , bool V_26 ,
T_7 V_87 , bool V_88 )
{
struct V_86 * V_9 ;
struct V_89 V_90 ;
int V_46 ;
memset ( & V_90 , 0 , sizeof( V_90 ) ) ;
if ( V_26 ) {
V_90 . V_91 = V_37 ;
V_90 . V_92 = 1 ;
V_90 . V_93 = V_88 ;
} else {
V_90 . V_91 = V_31 ;
V_90 . V_94 . V_95 = F_56 ( V_96 ) ;
}
V_90 . V_97 = V_87 ;
V_46 = F_57 ( V_85 , & V_90 , & V_9 ) ;
if ( V_46 < 0 )
return F_58 ( V_46 ) ;
return V_9 ;
}
static int F_59 ( struct V_27 * V_98 )
{
return sizeof( * V_98 ) + V_98 -> V_55 * 4 ;
}
static struct V_28 * * F_60 ( struct V_9 * V_10 ,
struct V_28 * * V_99 ,
struct V_28 * V_29 )
{
struct V_28 * V_100 , * * V_101 = NULL ;
struct V_27 * V_98 , * V_102 ;
unsigned int V_103 , V_104 , V_105 ;
const struct V_106 * V_107 ;
T_7 type ;
int V_108 = 1 ;
V_105 = F_61 ( V_29 ) ;
V_103 = V_105 + sizeof( * V_98 ) ;
V_98 = F_62 ( V_29 , V_105 ) ;
if ( F_63 ( V_29 , V_103 ) ) {
V_98 = F_64 ( V_29 , V_103 , V_105 ) ;
if ( F_32 ( ! V_98 ) )
goto V_109;
}
if ( V_98 -> V_81 != V_82 || V_98 -> V_51 )
goto V_109;
V_104 = F_59 ( V_98 ) ;
V_103 = V_105 + V_104 ;
if ( F_63 ( V_29 , V_103 ) ) {
V_98 = F_64 ( V_29 , V_103 , V_105 ) ;
if ( F_32 ( ! V_98 ) )
goto V_109;
}
for ( V_100 = * V_99 ; V_100 ; V_100 = V_100 -> V_110 ) {
if ( ! F_65 ( V_100 ) -> V_111 )
continue;
V_102 = (struct V_27 * ) ( V_100 -> V_112 + V_105 ) ;
if ( V_98 -> V_55 != V_102 -> V_55 ||
memcmp ( V_98 , V_102 , V_104 ) ) {
F_65 ( V_100 ) -> V_111 = 0 ;
continue;
}
}
type = V_98 -> V_83 ;
F_66 () ;
V_107 = F_67 ( type ) ;
if ( ! V_107 )
goto V_113;
F_68 ( V_29 , V_104 ) ;
F_69 ( V_29 , V_98 , V_104 ) ;
V_101 = F_70 ( V_107 -> V_114 . V_115 , V_99 , V_29 ) ;
V_108 = 0 ;
V_113:
F_71 () ;
V_109:
F_65 ( V_29 ) -> V_108 |= V_108 ;
return V_101 ;
}
static int F_72 ( struct V_9 * V_10 , struct V_28 * V_29 ,
int V_116 )
{
struct V_27 * V_98 ;
struct V_106 * V_107 ;
T_7 type ;
int V_104 ;
int V_46 = - V_117 ;
V_98 = (struct V_27 * ) ( V_29 -> V_112 + V_116 ) ;
V_104 = F_59 ( V_98 ) ;
type = V_98 -> V_83 ;
F_66 () ;
V_107 = F_73 ( type ) ;
if ( V_107 )
V_46 = V_107 -> V_114 . V_118 ( V_29 , V_116 + V_104 ) ;
F_71 () ;
F_74 ( V_29 , V_116 + V_104 ) ;
return V_46 ;
}
static struct V_7 * F_75 ( struct V_85 * V_85 , T_7 V_87 ,
bool V_26 , bool V_88 )
{
struct V_119 * V_120 = F_76 ( V_85 , V_121 ) ;
struct V_7 * V_8 ;
struct V_86 * V_9 ;
struct V_122 V_123 ;
int V_124 ;
V_8 = F_77 ( sizeof( * V_8 ) , V_77 ) ;
if ( ! V_8 )
return F_58 ( - V_75 ) ;
V_9 = F_55 ( V_85 , V_26 , V_87 , V_88 ) ;
if ( F_78 ( V_9 ) ) {
F_79 ( V_8 ) ;
return F_80 ( V_9 ) ;
}
V_8 -> V_9 = V_9 ;
V_8 -> V_125 = 1 ;
for ( V_124 = 0 ; V_124 < V_126 ; ++ V_124 )
F_81 ( & V_8 -> V_18 [ V_124 ] ) ;
F_82 ( V_8 -> V_9 , V_127 ) ;
memset ( & V_123 , 0 , sizeof( V_123 ) ) ;
V_123 . V_128 = V_8 ;
V_123 . V_129 = 1 ;
V_123 . V_115 = F_60 ;
V_123 . V_118 = F_72 ;
V_123 . V_130 = F_48 ;
V_123 . V_131 = NULL ;
F_83 ( V_85 , V_9 , & V_123 ) ;
F_84 ( & V_8 -> V_132 , & V_120 -> V_133 ) ;
return V_8 ;
}
static void F_85 ( struct V_7 * V_8 )
{
if ( ! V_8 || -- V_8 -> V_125 )
return;
F_86 ( & V_8 -> V_132 ) ;
F_87 ( V_8 -> V_9 , V_127 ) ;
F_88 ( V_8 -> V_9 ) ;
F_89 ( V_8 , V_134 ) ;
}
static void F_90 ( struct V_12 * V_16 )
{
struct V_7 * V_135 = F_91 ( V_16 -> V_136 ) ;
#if F_16 ( V_36 )
struct V_7 * V_137 = F_91 ( V_16 -> V_138 ) ;
F_92 ( V_16 -> V_138 , NULL ) ;
#endif
F_92 ( V_16 -> V_136 , NULL ) ;
F_93 () ;
F_85 ( V_135 ) ;
#if F_16 ( V_36 )
F_85 ( V_137 ) ;
#endif
}
static struct V_7 * F_94 ( struct V_119 * V_120 ,
T_5 V_91 ,
T_7 V_139 )
{
struct V_7 * V_8 ;
F_95 (gs, &gn->sock_list, list) {
if ( F_96 ( V_8 -> V_9 -> V_10 ) -> V_140 == V_139 &&
F_7 ( V_8 ) == V_91 ) {
return V_8 ;
}
}
return NULL ;
}
static int F_97 ( struct V_12 * V_16 , bool V_26 )
{
struct V_85 * V_85 = V_16 -> V_85 ;
struct V_119 * V_120 = F_76 ( V_85 , V_121 ) ;
struct V_7 * V_8 ;
T_4 V_1 [ 3 ] ;
T_1 V_17 ;
V_8 = F_94 ( V_120 , V_26 ? V_37 : V_31 , V_16 -> V_19 . V_20 . V_141 ) ;
if ( V_8 ) {
V_8 -> V_125 ++ ;
goto V_109;
}
V_8 = F_75 ( V_85 , V_16 -> V_19 . V_20 . V_141 , V_26 ,
V_16 -> V_93 ) ;
if ( F_78 ( V_8 ) )
return F_98 ( V_8 ) ;
V_109:
V_8 -> V_34 = V_16 -> V_34 ;
#if F_16 ( V_36 )
if ( V_26 )
F_92 ( V_16 -> V_138 , V_8 ) ;
else
#endif
F_92 ( V_16 -> V_136 , V_8 ) ;
F_5 ( V_16 -> V_19 . V_20 . V_6 , V_1 ) ;
V_17 = F_1 ( V_1 ) ;
F_99 ( & V_16 -> V_142 , & V_8 -> V_18 [ V_17 ] ) ;
return 0 ;
}
static int F_100 ( struct V_74 * V_60 )
{
struct V_12 * V_16 = F_40 ( V_60 ) ;
bool V_26 = ! ! ( V_16 -> V_19 . V_143 & V_144 ) ;
bool V_145 = V_16 -> V_34 ;
int V_146 = 0 ;
#if F_16 ( V_36 )
if ( V_26 || V_145 )
V_146 = F_97 ( V_16 , true ) ;
#endif
if ( ! V_146 && ( ! V_26 || V_145 ) )
V_146 = F_97 ( V_16 , false ) ;
if ( V_146 < 0 )
F_90 ( V_16 ) ;
return V_146 ;
}
static int F_101 ( struct V_74 * V_60 )
{
struct V_12 * V_16 = F_40 ( V_60 ) ;
if ( ! F_102 ( & V_16 -> V_142 ) )
F_103 ( & V_16 -> V_142 ) ;
F_90 ( V_16 ) ;
return 0 ;
}
static void F_104 ( struct V_27 * V_78 ,
const struct V_147 * V_19 )
{
V_78 -> V_81 = V_82 ;
V_78 -> V_55 = V_19 -> V_148 / 4 ;
V_78 -> V_51 = ! ! ( V_19 -> V_20 . V_149 & V_52 ) ;
V_78 -> V_53 = ! ! ( V_19 -> V_20 . V_149 & V_54 ) ;
V_78 -> V_150 = 0 ;
F_5 ( V_19 -> V_20 . V_6 , V_78 -> V_1 ) ;
V_78 -> V_83 = F_50 ( V_84 ) ;
V_78 -> V_151 = 0 ;
F_105 ( V_78 -> V_58 , V_19 ) ;
}
static int F_106 ( struct V_152 * V_23 , struct V_28 * V_29 ,
const struct V_147 * V_19 ,
bool V_153 , int V_154 )
{
bool V_155 = ! ! ( V_19 -> V_20 . V_149 & V_156 ) ;
struct V_27 * V_41 ;
int V_157 ;
int V_46 ;
F_22 ( V_29 ) ;
F_107 ( V_29 , V_153 ) ;
V_157 = F_108 ( V_23 -> V_60 ) + V_23 -> V_158 +
V_80 + V_19 -> V_148 + V_154 ;
V_46 = F_109 ( V_29 , V_157 ) ;
if ( F_32 ( V_46 ) )
goto V_159;
V_46 = F_110 ( V_29 , V_155 ) ;
if ( V_46 )
goto V_159;
V_41 = (struct V_27 * ) F_111 ( V_29 , sizeof( * V_41 ) +
V_19 -> V_148 ) ;
F_104 ( V_41 , V_19 ) ;
F_112 ( V_29 , F_50 ( V_84 ) ) ;
return 0 ;
V_159:
F_113 ( V_23 ) ;
return V_46 ;
}
static struct V_160 * F_114 ( struct V_28 * V_29 ,
struct V_74 * V_60 ,
struct V_161 * V_162 ,
const struct V_147 * V_19 )
{
bool V_163 = F_115 ( V_29 , V_19 ) ;
struct V_12 * V_16 = F_40 ( V_60 ) ;
struct V_76 * V_76 ;
struct V_160 * V_164 = NULL ;
T_4 V_65 ;
if ( ! F_116 ( V_16 -> V_136 ) )
return F_58 ( - V_165 ) ;
memset ( V_162 , 0 , sizeof( * V_162 ) ) ;
V_162 -> V_166 = V_29 -> V_167 ;
V_162 -> V_168 = V_169 ;
V_162 -> V_170 = V_19 -> V_20 . V_21 . V_22 . V_23 ;
V_162 -> V_35 = V_19 -> V_20 . V_21 . V_22 . V_171 ;
V_65 = V_19 -> V_20 . V_65 ;
if ( ( V_65 == 1 ) && ! V_16 -> V_34 ) {
V_65 = F_117 ( F_15 ( V_29 ) , V_29 ) ;
V_163 = false ;
}
V_162 -> V_172 = F_118 ( V_65 ) ;
V_76 = (struct V_76 * ) & V_19 -> V_76 ;
if ( V_163 ) {
V_164 = F_119 ( V_76 , & V_162 -> V_35 ) ;
if ( V_164 )
return V_164 ;
}
V_164 = F_120 ( V_16 -> V_85 , V_162 ) ;
if ( F_78 ( V_164 ) ) {
F_121 ( V_60 , L_4 , & V_162 -> V_170 ) ;
return F_58 ( - V_173 ) ;
}
if ( V_164 -> V_23 . V_60 == V_60 ) {
F_121 ( V_60 , L_5 , & V_162 -> V_170 ) ;
F_122 ( V_164 ) ;
return F_58 ( - V_174 ) ;
}
if ( V_163 )
F_123 ( V_76 , & V_164 -> V_23 , V_162 -> V_35 ) ;
return V_164 ;
}
static struct V_152 * F_124 ( struct V_28 * V_29 ,
struct V_74 * V_60 ,
struct V_175 * V_176 ,
const struct V_147 * V_19 )
{
bool V_163 = F_115 ( V_29 , V_19 ) ;
struct V_12 * V_16 = F_40 ( V_60 ) ;
struct V_152 * V_23 = NULL ;
struct V_76 * V_76 ;
struct V_7 * V_137 ;
T_4 V_177 ;
V_137 = F_116 ( V_16 -> V_138 ) ;
if ( ! V_137 )
return F_58 ( - V_165 ) ;
memset ( V_176 , 0 , sizeof( * V_176 ) ) ;
V_176 -> V_178 = V_29 -> V_167 ;
V_176 -> V_179 = V_169 ;
V_176 -> V_170 = V_19 -> V_20 . V_21 . V_26 . V_23 ;
V_176 -> V_35 = V_19 -> V_20 . V_21 . V_26 . V_171 ;
V_177 = V_19 -> V_20 . V_65 ;
if ( ( V_177 == 1 ) && ! V_16 -> V_34 ) {
V_177 = F_117 ( F_15 ( V_29 ) , V_29 ) ;
V_163 = false ;
}
V_176 -> V_180 = F_125 ( F_118 ( V_177 ) ,
V_19 -> V_20 . V_181 ) ;
V_76 = (struct V_76 * ) & V_19 -> V_76 ;
if ( V_163 ) {
V_23 = F_126 ( V_76 , & V_176 -> V_35 ) ;
if ( V_23 )
return V_23 ;
}
if ( V_182 -> V_183 ( V_16 -> V_85 , V_137 -> V_9 -> V_10 , & V_23 , V_176 ) ) {
F_121 ( V_60 , L_6 , & V_176 -> V_170 ) ;
return F_58 ( - V_173 ) ;
}
if ( V_23 -> V_60 == V_60 ) {
F_121 ( V_60 , L_7 , & V_176 -> V_170 ) ;
F_113 ( V_23 ) ;
return F_58 ( - V_174 ) ;
}
if ( V_163 )
F_127 ( V_76 , V_23 , & V_176 -> V_35 ) ;
return V_23 ;
}
static int F_128 ( struct V_28 * V_29 , struct V_74 * V_60 ,
struct V_12 * V_16 ,
const struct V_147 * V_19 )
{
bool V_153 = ! F_53 ( V_16 -> V_85 , F_54 ( V_16 -> V_60 ) ) ;
struct V_7 * V_135 = F_116 ( V_16 -> V_136 ) ;
const struct V_184 * V_20 = & V_19 -> V_20 ;
struct V_160 * V_164 ;
struct V_161 V_162 ;
T_4 V_65 , V_185 ;
T_7 V_186 ;
T_7 V_187 ;
int V_46 ;
V_164 = F_114 ( V_29 , V_60 , & V_162 , V_19 ) ;
if ( F_78 ( V_164 ) )
return F_98 ( V_164 ) ;
V_186 = F_129 ( V_16 -> V_85 , V_29 , 1 , V_188 , true ) ;
if ( V_16 -> V_34 ) {
V_65 = F_130 ( V_20 -> V_65 , F_15 ( V_29 ) , V_29 ) ;
V_185 = V_20 -> V_185 ;
} else {
V_65 = F_130 ( V_162 . V_172 , F_15 ( V_29 ) , V_29 ) ;
V_185 = V_20 -> V_185 ? : F_131 ( & V_164 -> V_23 ) ;
}
V_187 = V_20 -> V_149 & V_189 ? F_50 ( V_190 ) : 0 ;
V_46 = F_106 ( & V_164 -> V_23 , V_29 , V_19 , V_153 , sizeof( struct V_32 ) ) ;
if ( F_32 ( V_46 ) )
return V_46 ;
F_132 ( V_164 , V_135 -> V_9 -> V_10 , V_29 , V_162 . V_35 , V_162 . V_170 ,
V_65 , V_185 , V_187 , V_186 , V_16 -> V_19 . V_20 . V_141 ,
! F_53 ( V_16 -> V_85 , F_54 ( V_16 -> V_60 ) ) ,
! ( V_19 -> V_20 . V_149 & V_156 ) ) ;
return 0 ;
}
static int F_133 ( struct V_28 * V_29 , struct V_74 * V_60 ,
struct V_12 * V_16 ,
const struct V_147 * V_19 )
{
bool V_153 = ! F_53 ( V_16 -> V_85 , F_54 ( V_16 -> V_60 ) ) ;
struct V_7 * V_137 = F_116 ( V_16 -> V_138 ) ;
const struct V_184 * V_20 = & V_19 -> V_20 ;
struct V_152 * V_23 = NULL ;
struct V_175 V_176 ;
T_4 V_177 , V_185 ;
T_7 V_186 ;
int V_46 ;
V_23 = F_124 ( V_29 , V_60 , & V_176 , V_19 ) ;
if ( F_78 ( V_23 ) )
return F_98 ( V_23 ) ;
V_186 = F_129 ( V_16 -> V_85 , V_29 , 1 , V_188 , true ) ;
if ( V_16 -> V_34 ) {
V_177 = F_130 ( V_20 -> V_65 , F_15 ( V_29 ) , V_29 ) ;
V_185 = V_20 -> V_185 ;
} else {
V_177 = F_130 ( F_134 ( V_176 . V_180 ) ,
F_15 ( V_29 ) , V_29 ) ;
V_185 = V_20 -> V_185 ? : F_135 ( V_23 ) ;
}
V_46 = F_106 ( V_23 , V_29 , V_19 , V_153 , sizeof( struct V_39 ) ) ;
if ( F_32 ( V_46 ) )
return V_46 ;
F_136 ( V_23 , V_137 -> V_9 -> V_10 , V_29 , V_60 ,
& V_176 . V_35 , & V_176 . V_170 , V_177 , V_185 ,
V_19 -> V_20 . V_181 , V_186 , V_16 -> V_19 . V_20 . V_141 ,
! ( V_19 -> V_20 . V_149 & V_156 ) ) ;
return 0 ;
}
static T_8 F_137 ( struct V_28 * V_29 , struct V_74 * V_60 )
{
struct V_12 * V_16 = F_40 ( V_60 ) ;
struct V_147 * V_19 = NULL ;
int V_46 ;
if ( V_16 -> V_34 ) {
V_19 = F_138 ( V_29 ) ;
if ( F_32 ( ! V_19 || ! ( V_19 -> V_143 & V_191 ) ) ) {
V_46 = - V_192 ;
F_121 ( V_60 , L_8 ) ;
goto V_193;
}
} else {
V_19 = & V_16 -> V_19 ;
}
F_66 () ;
#if F_16 ( V_36 )
if ( V_19 -> V_143 & V_144 )
V_46 = F_133 ( V_29 , V_60 , V_16 , V_19 ) ;
else
#endif
V_46 = F_128 ( V_29 , V_60 , V_16 , V_19 ) ;
F_71 () ;
if ( F_139 ( ! V_46 ) )
return V_194 ;
V_193:
F_140 ( V_29 ) ;
if ( V_46 == - V_174 )
V_60 -> V_45 . V_195 ++ ;
else if ( V_46 == - V_173 )
V_60 -> V_45 . V_196 ++ ;
V_60 -> V_45 . V_197 ++ ;
return V_194 ;
}
static int F_141 ( struct V_74 * V_60 , int V_198 )
{
if ( V_198 > V_60 -> V_199 )
V_198 = V_60 -> V_199 ;
V_60 -> V_200 = V_198 ;
return 0 ;
}
static int F_142 ( struct V_74 * V_60 , struct V_28 * V_29 )
{
struct V_147 * V_19 = F_138 ( V_29 ) ;
struct V_12 * V_16 = F_40 ( V_60 ) ;
if ( F_143 ( V_19 ) == V_31 ) {
struct V_160 * V_164 ;
struct V_161 V_162 ;
V_164 = F_114 ( V_29 , V_60 , & V_162 , V_19 ) ;
if ( F_78 ( V_164 ) )
return F_98 ( V_164 ) ;
F_122 ( V_164 ) ;
V_19 -> V_20 . V_21 . V_22 . V_171 = V_162 . V_35 ;
#if F_16 ( V_36 )
} else if ( F_143 ( V_19 ) == V_37 ) {
struct V_152 * V_23 ;
struct V_175 V_176 ;
V_23 = F_124 ( V_29 , V_60 , & V_176 , V_19 ) ;
if ( F_78 ( V_23 ) )
return F_98 ( V_23 ) ;
F_113 ( V_23 ) ;
V_19 -> V_20 . V_21 . V_26 . V_171 = V_176 . V_35 ;
#endif
} else {
return - V_192 ;
}
V_19 -> V_20 . V_201 = F_129 ( V_16 -> V_85 , V_29 ,
1 , V_188 , true ) ;
V_19 -> V_20 . V_141 = V_16 -> V_19 . V_20 . V_141 ;
return 0 ;
}
static void F_144 ( struct V_74 * V_60 ,
struct V_202 * V_203 )
{
F_145 ( V_203 -> V_204 , V_205 , sizeof( V_203 -> V_204 ) ) ;
F_145 ( V_203 -> V_206 , L_9 , sizeof( V_203 -> V_206 ) ) ;
}
static void F_146 ( struct V_74 * V_60 )
{
struct V_85 * V_85 = F_54 ( V_60 ) ;
struct V_119 * V_120 = F_76 ( V_85 , V_121 ) ;
struct V_7 * V_8 ;
F_66 () ;
F_147 (gs, &gn->sock_list, list)
F_148 ( V_60 , V_8 -> V_9 ,
V_127 ) ;
F_71 () ;
}
static void F_149 ( struct V_74 * V_60 )
{
F_150 ( V_60 ) ;
V_60 -> V_207 = & V_208 ;
V_60 -> V_209 = & V_210 ;
V_60 -> V_211 = true ;
F_151 ( V_60 , & V_212 ) ;
V_60 -> V_213 |= V_214 ;
V_60 -> V_213 |= V_215 | V_216 ;
V_60 -> V_213 |= V_217 ;
V_60 -> V_213 |= V_218 ;
V_60 -> V_219 |= V_215 | V_216 | V_217 ;
V_60 -> V_219 |= V_218 ;
V_60 -> V_220 = V_221 ;
V_60 -> V_199 = V_222 - V_80 - V_60 -> V_223 ;
F_152 ( V_60 ) ;
V_60 -> V_224 &= ~ V_225 ;
V_60 -> V_224 |= V_226 | V_227 ;
F_153 ( V_60 ) ;
}
static int F_154 ( struct V_228 * V_229 [] , struct V_228 * V_112 [] )
{
if ( V_229 [ V_230 ] ) {
if ( F_155 ( V_229 [ V_230 ] ) != V_231 )
return - V_192 ;
if ( ! F_156 ( F_157 ( V_229 [ V_230 ] ) ) )
return - V_232 ;
}
if ( ! V_112 )
return - V_192 ;
if ( V_112 [ V_233 ] ) {
T_1 V_1 = F_158 ( V_112 [ V_233 ] ) ;
if ( V_1 >= V_234 )
return - V_235 ;
}
return 0 ;
}
static struct V_12 * F_159 ( struct V_119 * V_120 ,
const struct V_147 * V_19 ,
bool * V_236 ,
bool * V_237 )
{
struct V_12 * V_16 , * V_238 = NULL ;
* V_236 = false ;
* V_237 = false ;
F_95 (geneve, &gn->geneve_list, next) {
if ( V_19 -> V_20 . V_141 == V_16 -> V_19 . V_20 . V_141 ) {
* V_237 = V_16 -> V_34 ;
* V_236 = true ;
}
if ( V_19 -> V_20 . V_6 == V_16 -> V_19 . V_20 . V_6 &&
V_19 -> V_20 . V_141 == V_16 -> V_19 . V_20 . V_141 &&
! memcmp ( & V_19 -> V_20 . V_21 , & V_16 -> V_19 . V_20 . V_21 , sizeof( V_19 -> V_20 . V_21 ) ) )
V_238 = V_16 ;
}
return V_238 ;
}
static bool F_160 ( const T_2 * V_239 , T_9 V_240 )
{
int V_241 ;
for ( V_241 = 0 ; V_241 < V_240 ; V_241 ++ )
if ( V_239 [ V_241 ] )
return false ;
return true ;
}
static bool F_161 ( const struct V_147 * V_19 )
{
if ( V_19 -> V_20 . V_6 || V_19 -> V_20 . V_149 || V_19 -> V_20 . V_65 ||
V_19 -> V_20 . V_185 || V_19 -> V_20 . V_181 || V_19 -> V_20 . V_201 ||
! F_160 ( ( const T_2 * ) & V_19 -> V_20 . V_21 , sizeof( V_19 -> V_20 . V_21 ) ) )
return false ;
else
return true ;
}
static int F_162 ( struct V_85 * V_85 , struct V_74 * V_60 ,
const struct V_147 * V_19 ,
bool V_145 , bool V_88 )
{
struct V_119 * V_120 = F_76 ( V_85 , V_121 ) ;
struct V_12 * V_238 , * V_16 = F_40 ( V_60 ) ;
bool V_237 , V_236 ;
int V_46 , V_242 ;
if ( V_145 && ! F_161 ( V_19 ) )
return - V_192 ;
V_16 -> V_85 = V_85 ;
V_16 -> V_60 = V_60 ;
V_238 = F_159 ( V_120 , V_19 , & V_236 , & V_237 ) ;
if ( V_238 )
return - V_243 ;
V_242 = V_80 + V_61 ;
if ( ! V_145 && F_143 ( V_19 ) == V_31 ) {
V_242 += sizeof( struct V_32 ) ;
V_60 -> V_199 -= sizeof( struct V_32 ) ;
} else {
V_242 += sizeof( struct V_39 ) ;
V_60 -> V_199 -= sizeof( struct V_39 ) ;
}
V_60 -> V_244 = V_242 + V_61 ;
if ( V_145 ) {
if ( V_236 )
return - V_245 ;
} else {
if ( V_237 )
return - V_245 ;
}
F_163 ( & V_16 -> V_19 . V_76 ) ;
V_16 -> V_19 = * V_19 ;
V_16 -> V_34 = V_145 ;
V_16 -> V_93 = V_88 ;
V_46 = F_164 ( V_60 ) ;
if ( V_46 )
return V_46 ;
F_84 ( & V_16 -> V_110 , & V_120 -> V_246 ) ;
return 0 ;
}
static void F_165 ( struct V_147 * V_19 , T_10 V_139 )
{
memset ( V_19 , 0 , sizeof( * V_19 ) ) ;
V_19 -> V_20 . V_141 = F_50 ( V_139 ) ;
}
static int F_166 ( struct V_85 * V_85 , struct V_74 * V_60 ,
struct V_228 * V_229 [] , struct V_228 * V_112 [] )
{
bool V_93 = false ;
struct V_147 V_19 ;
bool V_145 = false ;
F_165 ( & V_19 , V_247 ) ;
if ( V_112 [ V_248 ] && V_112 [ V_249 ] )
return - V_192 ;
if ( V_112 [ V_248 ] ) {
V_19 . V_20 . V_21 . V_22 . V_23 =
F_167 ( V_112 [ V_248 ] ) ;
if ( F_168 ( F_169 ( V_19 . V_20 . V_21 . V_22 . V_23 ) ) ) {
F_121 ( V_60 , L_10 ) ;
return - V_192 ;
}
}
if ( V_112 [ V_249 ] ) {
#if F_16 ( V_36 )
V_19 . V_143 = V_144 ;
V_19 . V_20 . V_21 . V_26 . V_23 =
F_170 ( V_112 [ V_249 ] ) ;
if ( F_171 ( & V_19 . V_20 . V_21 . V_26 . V_23 ) &
V_250 ) {
F_121 ( V_60 , L_11 ) ;
return - V_192 ;
}
if ( F_172 ( & V_19 . V_20 . V_21 . V_26 . V_23 ) ) {
F_121 ( V_60 , L_10 ) ;
return - V_192 ;
}
V_19 . V_20 . V_149 |= V_156 ;
V_93 = true ;
#else
return - V_251 ;
#endif
}
if ( V_112 [ V_233 ] ) {
T_1 V_1 ;
T_4 V_252 [ 3 ] ;
V_1 = F_158 ( V_112 [ V_233 ] ) ;
V_252 [ 0 ] = ( V_1 & 0x00ff0000 ) >> 16 ;
V_252 [ 1 ] = ( V_1 & 0x0000ff00 ) >> 8 ;
V_252 [ 2 ] = V_1 & 0x000000ff ;
V_19 . V_20 . V_6 = F_3 ( V_252 ) ;
}
if ( V_112 [ V_253 ] )
V_19 . V_20 . V_185 = F_173 ( V_112 [ V_253 ] ) ;
if ( V_112 [ V_254 ] )
V_19 . V_20 . V_65 = F_173 ( V_112 [ V_254 ] ) ;
if ( V_112 [ V_255 ] ) {
V_19 . V_20 . V_181 = F_174 ( V_112 [ V_255 ] ) &
V_256 ;
if ( V_19 . V_20 . V_181 && ( ! ( V_19 . V_143 & V_144 ) ) )
return - V_192 ;
}
if ( V_112 [ V_257 ] )
V_19 . V_20 . V_141 = F_175 ( V_112 [ V_257 ] ) ;
if ( V_112 [ V_258 ] )
V_145 = true ;
if ( V_112 [ V_259 ] &&
F_173 ( V_112 [ V_259 ] ) )
V_19 . V_20 . V_149 |= V_156 ;
if ( V_112 [ V_260 ] &&
F_173 ( V_112 [ V_260 ] ) )
V_19 . V_20 . V_149 &= ~ V_156 ;
if ( V_112 [ V_261 ] &&
F_173 ( V_112 [ V_261 ] ) )
V_93 = false ;
return F_162 ( V_85 , V_60 , & V_19 , V_145 , V_93 ) ;
}
static void F_176 ( struct V_74 * V_60 , struct V_262 * V_99 )
{
struct V_12 * V_16 = F_40 ( V_60 ) ;
F_86 ( & V_16 -> V_110 ) ;
F_177 ( V_60 , V_99 ) ;
}
static T_9 F_178 ( const struct V_74 * V_60 )
{
return F_179 ( sizeof( T_1 ) ) +
F_179 ( sizeof( struct V_24 ) ) +
F_179 ( sizeof( T_4 ) ) +
F_179 ( sizeof( T_4 ) ) +
F_179 ( sizeof( T_6 ) ) +
F_179 ( sizeof( T_7 ) ) +
F_179 ( 0 ) +
F_179 ( sizeof( T_4 ) ) +
F_179 ( sizeof( T_4 ) ) +
F_179 ( sizeof( T_4 ) ) +
0 ;
}
static int F_180 ( struct V_28 * V_29 , const struct V_74 * V_60 )
{
struct V_12 * V_16 = F_40 ( V_60 ) ;
struct V_147 * V_19 = & V_16 -> V_19 ;
T_4 V_263 [ 3 ] ;
T_1 V_1 ;
F_5 ( V_19 -> V_20 . V_6 , V_263 ) ;
V_1 = ( V_263 [ 0 ] << 16 ) | ( V_263 [ 1 ] << 8 ) | V_263 [ 2 ] ;
if ( F_181 ( V_29 , V_233 , V_1 ) )
goto V_264;
if ( F_91 ( V_16 -> V_136 ) ) {
if ( F_182 ( V_29 , V_248 ,
V_19 -> V_20 . V_21 . V_22 . V_23 ) )
goto V_264;
if ( F_183 ( V_29 , V_259 ,
! ! ( V_19 -> V_20 . V_149 & V_156 ) ) )
goto V_264;
}
#if F_16 ( V_36 )
if ( F_91 ( V_16 -> V_138 ) ) {
if ( F_184 ( V_29 , V_249 ,
& V_19 -> V_20 . V_21 . V_26 . V_23 ) )
goto V_264;
if ( F_183 ( V_29 , V_260 ,
! ( V_19 -> V_20 . V_149 & V_156 ) ) )
goto V_264;
if ( F_183 ( V_29 , V_261 ,
! V_16 -> V_93 ) )
goto V_264;
}
#endif
if ( F_183 ( V_29 , V_253 , V_19 -> V_20 . V_185 ) ||
F_183 ( V_29 , V_254 , V_19 -> V_20 . V_65 ) ||
F_185 ( V_29 , V_255 , V_19 -> V_20 . V_181 ) )
goto V_264;
if ( F_186 ( V_29 , V_257 , V_19 -> V_20 . V_141 ) )
goto V_264;
if ( V_16 -> V_34 ) {
if ( F_187 ( V_29 , V_258 ) )
goto V_264;
}
return 0 ;
V_264:
return - V_265 ;
}
struct V_74 * F_188 ( struct V_85 * V_85 , const char * V_266 ,
T_2 V_267 , T_11 V_139 )
{
struct V_228 * V_229 [ V_268 + 1 ] ;
struct V_147 V_19 ;
struct V_74 * V_60 ;
F_189 ( V_269 ) ;
int V_46 ;
memset ( V_229 , 0 , sizeof( V_229 ) ) ;
V_60 = F_190 ( V_85 , V_266 , V_267 ,
& V_270 , V_229 ) ;
if ( F_78 ( V_60 ) )
return V_60 ;
F_165 ( & V_19 , V_139 ) ;
V_46 = F_162 ( V_85 , V_60 , & V_19 , true , true ) ;
if ( V_46 ) {
F_191 ( V_60 ) ;
return F_58 ( V_46 ) ;
}
V_46 = F_141 ( V_60 , V_222 ) ;
if ( V_46 )
goto V_46;
V_46 = F_192 ( V_60 , NULL ) ;
if ( V_46 < 0 )
goto V_46;
return V_60 ;
V_46:
F_176 ( V_60 , & V_269 ) ;
F_193 ( & V_269 ) ;
return F_58 ( V_46 ) ;
}
static int F_194 ( struct V_271 * V_272 ,
unsigned long V_273 , void * V_274 )
{
struct V_74 * V_60 = F_195 ( V_274 ) ;
if ( V_273 == V_275 )
F_146 ( V_60 ) ;
return V_276 ;
}
static T_12 int F_196 ( struct V_85 * V_85 )
{
struct V_119 * V_120 = F_76 ( V_85 , V_121 ) ;
F_197 ( & V_120 -> V_246 ) ;
F_197 ( & V_120 -> V_133 ) ;
return 0 ;
}
static void T_13 F_198 ( struct V_85 * V_85 )
{
struct V_119 * V_120 = F_76 ( V_85 , V_121 ) ;
struct V_12 * V_16 , * V_110 ;
struct V_74 * V_60 , * V_277 ;
F_189 ( V_132 ) ;
F_199 () ;
F_200 (net, dev, aux)
if ( V_60 -> V_278 == & V_270 )
F_177 ( V_60 , & V_132 ) ;
F_201 (geneve, next, &gn->geneve_list, next) {
if ( ! F_53 ( F_54 ( V_16 -> V_60 ) , V_85 ) )
F_177 ( V_16 -> V_60 , & V_132 ) ;
}
F_193 ( & V_132 ) ;
F_202 () ;
}
static int T_14 F_203 ( void )
{
int V_279 ;
V_279 = F_204 ( & V_280 ) ;
if ( V_279 )
goto V_281;
V_279 = F_205 ( & V_282 ) ;
if ( V_279 )
goto V_283;
V_279 = F_206 ( & V_270 ) ;
if ( V_279 )
goto V_284;
return 0 ;
V_284:
F_207 ( & V_282 ) ;
V_283:
F_208 ( & V_280 ) ;
V_281:
return V_279 ;
}
static void T_15 F_209 ( void )
{
F_210 ( & V_270 ) ;
F_207 ( & V_282 ) ;
F_208 ( & V_280 ) ;
}
