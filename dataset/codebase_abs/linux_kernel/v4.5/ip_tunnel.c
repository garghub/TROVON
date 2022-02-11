static unsigned int F_1 ( T_1 V_1 , T_1 V_2 )
{
return F_2 ( ( V_3 V_4 ) V_1 ^ ( V_3 V_4 ) V_2 ,
V_5 ) ;
}
static void F_3 ( struct V_6 * V_7 ,
struct V_8 * V_9 , T_1 V_10 )
{
struct V_8 * V_11 ;
F_4 ( V_9 ) ;
V_11 = F_5 ( ( V_3 struct V_8 * * ) & V_7 -> V_9 , V_9 ) ;
F_6 ( V_11 ) ;
V_7 -> V_10 = V_10 ;
}
static T_2 void F_7 ( struct V_12 * V_13 ,
struct V_8 * V_9 , T_1 V_10 )
{
F_3 ( F_8 ( V_13 -> V_14 ) , V_9 , V_10 ) ;
}
static void F_9 ( struct V_12 * V_13 )
{
F_7 ( V_13 , NULL , 0 ) ;
}
void F_10 ( struct V_12 * V_13 )
{
int V_15 ;
F_11 (i)
F_3 ( F_12 ( V_13 -> V_14 , V_15 ) , NULL , 0 ) ;
}
static struct V_16 * F_13 ( struct V_12 * V_13 ,
V_4 V_17 , T_1 * V_10 )
{
struct V_6 * V_7 ;
struct V_8 * V_9 ;
F_14 () ;
V_7 = F_8 ( V_13 -> V_14 ) ;
V_9 = F_15 ( V_7 -> V_9 ) ;
if ( V_9 && ! F_16 ( & V_9 -> V_18 ) )
V_9 = NULL ;
if ( V_9 ) {
if ( ! V_9 -> V_19 || V_9 -> V_20 -> V_21 ( V_9 , V_17 ) ) {
* V_10 = V_7 -> V_10 ;
} else {
F_9 ( V_13 ) ;
F_6 ( V_9 ) ;
V_9 = NULL ;
}
}
F_17 () ;
return (struct V_16 * ) V_9 ;
}
static bool F_18 ( const struct V_22 * V_23 ,
T_3 V_24 , T_1 V_1 )
{
if ( V_23 -> V_25 & V_26 ) {
if ( V_24 & V_26 )
return V_1 == V_23 -> V_27 ;
else
return false ;
} else
return ! ( V_24 & V_26 ) ;
}
struct V_12 * F_19 ( struct V_28 * V_29 ,
int V_30 , T_3 V_24 ,
T_1 V_2 , T_1 V_31 ,
T_1 V_1 )
{
unsigned int V_32 ;
struct V_12 * V_13 , * V_33 = NULL ;
struct V_34 * V_35 ;
V_32 = F_1 ( V_1 , V_2 ) ;
V_35 = & V_29 -> V_36 [ V_32 ] ;
F_20 (t, head, hash_node) {
if ( V_31 != V_13 -> V_37 . V_38 . V_10 ||
V_2 != V_13 -> V_37 . V_38 . V_39 ||
! ( V_13 -> V_40 -> V_24 & V_41 ) )
continue;
if ( ! F_18 ( & V_13 -> V_37 , V_24 , V_1 ) )
continue;
if ( V_13 -> V_37 . V_30 == V_30 )
return V_13 ;
else
V_33 = V_13 ;
}
F_20 (t, head, hash_node) {
if ( V_2 != V_13 -> V_37 . V_38 . V_39 ||
V_13 -> V_37 . V_38 . V_10 != 0 ||
! ( V_13 -> V_40 -> V_24 & V_41 ) )
continue;
if ( ! F_18 ( & V_13 -> V_37 , V_24 , V_1 ) )
continue;
if ( V_13 -> V_37 . V_30 == V_30 )
return V_13 ;
else if ( ! V_33 )
V_33 = V_13 ;
}
V_32 = F_1 ( V_1 , 0 ) ;
V_35 = & V_29 -> V_36 [ V_32 ] ;
F_20 (t, head, hash_node) {
if ( ( V_31 != V_13 -> V_37 . V_38 . V_10 || V_13 -> V_37 . V_38 . V_39 != 0 ) &&
( V_31 != V_13 -> V_37 . V_38 . V_39 || ! F_21 ( V_31 ) ) )
continue;
if ( ! ( V_13 -> V_40 -> V_24 & V_41 ) )
continue;
if ( ! F_18 ( & V_13 -> V_37 , V_24 , V_1 ) )
continue;
if ( V_13 -> V_37 . V_30 == V_30 )
return V_13 ;
else if ( ! V_33 )
V_33 = V_13 ;
}
if ( V_24 & V_42 )
goto V_43;
F_20 (t, head, hash_node) {
if ( V_13 -> V_37 . V_27 != V_1 ||
V_13 -> V_37 . V_38 . V_10 != 0 ||
V_13 -> V_37 . V_38 . V_39 != 0 ||
! ( V_13 -> V_40 -> V_24 & V_41 ) )
continue;
if ( V_13 -> V_37 . V_30 == V_30 )
return V_13 ;
else if ( ! V_33 )
V_33 = V_13 ;
}
V_43:
if ( V_33 )
return V_33 ;
V_13 = F_15 ( V_29 -> V_44 ) ;
if ( V_13 )
return V_13 ;
if ( V_29 -> V_45 && V_29 -> V_45 -> V_24 & V_41 )
return F_22 ( V_29 -> V_45 ) ;
return NULL ;
}
static struct V_34 * F_23 ( struct V_28 * V_29 ,
struct V_22 * V_37 )
{
unsigned int V_46 ;
T_1 V_2 ;
T_1 V_27 = V_37 -> V_27 ;
if ( V_37 -> V_38 . V_39 && ! F_21 ( V_37 -> V_38 . V_39 ) )
V_2 = V_37 -> V_38 . V_39 ;
else
V_2 = 0 ;
if ( ! ( V_37 -> V_25 & V_26 ) && ( V_37 -> V_25 & V_47 ) )
V_27 = 0 ;
V_46 = F_1 ( V_27 , V_2 ) ;
return & V_29 -> V_36 [ V_46 ] ;
}
static void F_24 ( struct V_28 * V_29 , struct V_12 * V_13 )
{
struct V_34 * V_35 = F_23 ( V_29 , & V_13 -> V_37 ) ;
if ( V_13 -> V_48 )
F_25 ( V_29 -> V_44 , V_13 ) ;
F_26 ( & V_13 -> V_49 , V_35 ) ;
}
static void F_27 ( struct V_28 * V_29 , struct V_12 * V_13 )
{
if ( V_13 -> V_48 )
F_25 ( V_29 -> V_44 , NULL ) ;
F_28 ( & V_13 -> V_49 ) ;
}
static struct V_12 * F_29 ( struct V_28 * V_29 ,
struct V_22 * V_37 ,
int type )
{
T_1 V_2 = V_37 -> V_38 . V_39 ;
T_1 V_31 = V_37 -> V_38 . V_10 ;
T_1 V_1 = V_37 -> V_27 ;
T_3 V_24 = V_37 -> V_25 ;
int V_30 = V_37 -> V_30 ;
struct V_12 * V_13 = NULL ;
struct V_34 * V_35 = F_23 ( V_29 , V_37 ) ;
F_20 (t, head, hash_node) {
if ( V_31 == V_13 -> V_37 . V_38 . V_10 &&
V_2 == V_13 -> V_37 . V_38 . V_39 &&
V_30 == V_13 -> V_37 . V_30 &&
type == V_13 -> V_40 -> type &&
F_18 ( & V_13 -> V_37 , V_24 , V_1 ) )
break;
}
return V_13 ;
}
static struct V_50 * F_30 ( struct V_51 * V_51 ,
const struct V_52 * V_20 ,
struct V_22 * V_37 )
{
int V_53 ;
struct V_12 * V_54 ;
struct V_50 * V_40 ;
char V_55 [ V_56 ] ;
if ( V_37 -> V_55 [ 0 ] )
F_31 ( V_55 , V_37 -> V_55 , V_56 ) ;
else {
if ( strlen ( V_20 -> V_57 ) > ( V_56 - 3 ) ) {
V_53 = - V_58 ;
goto V_59;
}
F_31 ( V_55 , V_20 -> V_57 , V_56 ) ;
strncat ( V_55 , L_1 , 2 ) ;
}
F_32 () ;
V_40 = F_33 ( V_20 -> V_60 , V_55 , V_61 , V_20 -> V_62 ) ;
if ( ! V_40 ) {
V_53 = - V_63 ;
goto V_59;
}
F_34 ( V_40 , V_51 ) ;
V_40 -> V_52 = V_20 ;
V_54 = F_22 ( V_40 ) ;
V_54 -> V_37 = * V_37 ;
V_54 -> V_51 = V_51 ;
V_53 = F_35 ( V_40 ) ;
if ( V_53 )
goto V_64;
return V_40 ;
V_64:
F_36 ( V_40 ) ;
V_59:
return F_37 ( V_53 ) ;
}
static inline void F_38 ( struct V_65 * V_66 ,
int V_67 ,
T_1 V_39 , T_1 V_10 ,
T_1 V_1 , T_4 V_68 , int V_69 )
{
memset ( V_66 , 0 , sizeof( * V_66 ) ) ;
V_66 -> V_70 = V_69 ;
V_66 -> V_39 = V_39 ;
V_66 -> V_10 = V_10 ;
V_66 -> V_71 = V_68 ;
V_66 -> V_72 = V_67 ;
V_66 -> V_73 = V_1 ;
}
static int F_39 ( struct V_50 * V_40 )
{
struct V_50 * V_74 = NULL ;
struct V_12 * V_54 = F_22 ( V_40 ) ;
const struct V_75 * V_38 ;
int V_76 = V_77 ;
int V_78 = V_79 ;
int V_80 = V_54 -> V_76 + sizeof( struct V_75 ) ;
V_38 = & V_54 -> V_37 . V_38 ;
if ( V_38 -> V_39 ) {
struct V_65 V_66 ;
struct V_16 * V_81 ;
F_38 ( & V_66 , V_38 -> V_82 , V_38 -> V_39 ,
V_38 -> V_10 , V_54 -> V_37 . V_83 ,
F_40 ( V_38 -> V_68 ) , V_54 -> V_37 . V_30 ) ;
V_81 = F_41 ( V_54 -> V_51 , & V_66 ) ;
if ( ! F_42 ( V_81 ) ) {
V_74 = V_81 -> V_9 . V_40 ;
F_7 ( V_54 , & V_81 -> V_9 , V_66 . V_10 ) ;
F_43 ( V_81 ) ;
}
if ( V_40 -> type != V_84 )
V_40 -> V_24 |= V_85 ;
}
if ( ! V_74 && V_54 -> V_37 . V_30 )
V_74 = F_44 ( V_54 -> V_51 , V_54 -> V_37 . V_30 ) ;
if ( V_74 ) {
V_76 = V_74 -> V_86 + V_74 -> V_87 ;
V_78 = V_74 -> V_78 ;
}
V_40 -> V_87 = V_80 + V_76 ;
V_78 -= ( V_40 -> V_86 + V_80 ) ;
if ( V_78 < 68 )
V_78 = 68 ;
return V_78 ;
}
static struct V_12 * F_45 ( struct V_51 * V_51 ,
struct V_28 * V_29 ,
struct V_22 * V_37 )
{
struct V_12 * V_88 ;
struct V_50 * V_40 ;
F_46 ( ! V_29 -> V_45 ) ;
V_40 = F_30 ( V_51 , V_29 -> V_45 -> V_52 , V_37 ) ;
if ( F_42 ( V_40 ) )
return F_47 ( V_40 ) ;
V_40 -> V_78 = F_39 ( V_40 ) ;
V_88 = F_22 ( V_40 ) ;
F_24 ( V_29 , V_88 ) ;
return V_88 ;
}
int F_48 ( struct V_12 * V_54 , struct V_89 * V_90 ,
const struct V_91 * V_92 , struct V_93 * V_94 ,
bool V_95 )
{
struct V_96 * V_97 ;
const struct V_75 * V_38 = F_49 ( V_90 ) ;
int V_53 ;
#ifdef F_50
if ( F_21 ( V_38 -> V_39 ) ) {
V_54 -> V_40 -> V_98 . V_99 ++ ;
V_90 -> V_100 = V_101 ;
}
#endif
if ( ( ! ( V_92 -> V_24 & V_102 ) && ( V_54 -> V_37 . V_25 & V_102 ) ) ||
( ( V_92 -> V_24 & V_102 ) && ! ( V_54 -> V_37 . V_25 & V_102 ) ) ) {
V_54 -> V_40 -> V_98 . V_103 ++ ;
V_54 -> V_40 -> V_98 . V_104 ++ ;
goto V_105;
}
if ( V_54 -> V_37 . V_25 & V_106 ) {
if ( ! ( V_92 -> V_24 & V_106 ) ||
( V_54 -> V_107 && ( V_108 ) ( F_51 ( V_92 -> V_109 ) - V_54 -> V_107 ) < 0 ) ) {
V_54 -> V_40 -> V_98 . V_110 ++ ;
V_54 -> V_40 -> V_98 . V_104 ++ ;
goto V_105;
}
V_54 -> V_107 = F_51 ( V_92 -> V_109 ) + 1 ;
}
F_52 ( V_90 ) ;
V_53 = F_53 ( V_38 , V_90 ) ;
if ( F_54 ( V_53 ) ) {
if ( V_95 )
F_55 ( L_2 ,
& V_38 -> V_10 , V_38 -> V_68 ) ;
if ( V_53 > 1 ) {
++ V_54 -> V_40 -> V_98 . V_111 ;
++ V_54 -> V_40 -> V_98 . V_104 ;
goto V_105;
}
}
V_97 = F_56 ( V_54 -> V_40 -> V_97 ) ;
F_57 ( & V_97 -> V_112 ) ;
V_97 -> V_113 ++ ;
V_97 -> V_114 += V_90 -> V_115 ;
F_58 ( & V_97 -> V_112 ) ;
F_59 ( V_90 , ! F_60 ( V_54 -> V_51 , F_61 ( V_54 -> V_40 ) ) ) ;
if ( V_54 -> V_40 -> type == V_84 ) {
V_90 -> V_82 = F_62 ( V_90 , V_54 -> V_40 ) ;
F_63 ( V_90 , F_64 ( V_90 ) , V_116 ) ;
} else {
V_90 -> V_40 = V_54 -> V_40 ;
}
if ( V_94 )
F_65 ( V_90 , (struct V_8 * ) V_94 ) ;
F_66 ( & V_54 -> V_117 , V_90 ) ;
return 0 ;
V_105:
F_67 ( V_90 ) ;
return 0 ;
}
static int F_68 ( struct V_118 * V_119 )
{
const struct V_120 * V_20 ;
int V_76 = - V_121 ;
if ( V_119 -> type == V_122 )
return 0 ;
if ( V_119 -> type >= V_123 )
return - V_121 ;
F_14 () ;
V_20 = F_15 ( V_124 [ V_119 -> type ] ) ;
if ( F_69 ( V_20 && V_20 -> V_125 ) )
V_76 = V_20 -> V_125 ( V_119 ) ;
F_17 () ;
return V_76 ;
}
int F_70 ( const struct V_120 * V_20 ,
unsigned int V_126 )
{
if ( V_126 >= V_123 )
return - V_127 ;
return ! F_71 ( ( const struct V_120 * * )
& V_124 [ V_126 ] ,
NULL , V_20 ) ? 0 : - 1 ;
}
int F_72 ( const struct V_120 * V_20 ,
unsigned int V_126 )
{
int V_128 ;
if ( V_126 >= V_123 )
return - V_127 ;
V_128 = ( F_71 ( ( const struct V_120 * * )
& V_124 [ V_126 ] ,
V_20 , NULL ) == V_20 ) ? 0 : - 1 ;
F_73 () ;
return V_128 ;
}
int F_74 ( struct V_12 * V_13 ,
struct V_118 * V_129 )
{
int V_76 ;
memset ( & V_13 -> V_130 , 0 , sizeof( V_13 -> V_130 ) ) ;
V_76 = F_68 ( V_129 ) ;
if ( V_76 < 0 )
return V_76 ;
V_13 -> V_130 . type = V_129 -> type ;
V_13 -> V_130 . V_131 = V_129 -> V_131 ;
V_13 -> V_130 . V_132 = V_129 -> V_132 ;
V_13 -> V_130 . V_24 = V_129 -> V_24 ;
V_13 -> V_125 = V_76 ;
V_13 -> V_76 = V_13 -> V_125 + V_13 -> V_133 ;
return 0 ;
}
int V_118 ( struct V_89 * V_90 , struct V_12 * V_13 ,
T_5 * V_82 , struct V_65 * V_66 )
{
const struct V_120 * V_20 ;
int V_128 = - V_121 ;
if ( V_13 -> V_130 . type == V_122 )
return 0 ;
if ( V_13 -> V_130 . type >= V_123 )
return - V_121 ;
F_14 () ;
V_20 = F_15 ( V_124 [ V_13 -> V_130 . type ] ) ;
if ( F_69 ( V_20 && V_20 -> V_134 ) )
V_128 = V_20 -> V_134 ( V_90 , & V_13 -> V_130 , V_82 , V_66 ) ;
F_17 () ;
return V_128 ;
}
static int F_75 ( struct V_50 * V_40 , struct V_89 * V_90 ,
struct V_16 * V_81 , T_3 V_135 ,
const struct V_75 * V_136 )
{
struct V_12 * V_54 = F_22 ( V_40 ) ;
int V_137 = V_90 -> V_115 - V_54 -> V_76 - V_40 -> V_86 ;
int V_78 ;
if ( V_135 )
V_78 = F_76 ( & V_81 -> V_9 ) - V_40 -> V_86
- sizeof( struct V_75 ) - V_54 -> V_76 ;
else
V_78 = F_77 ( V_90 ) ? F_76 ( F_77 ( V_90 ) ) : V_40 -> V_78 ;
if ( F_77 ( V_90 ) )
F_77 ( V_90 ) -> V_20 -> V_138 ( F_77 ( V_90 ) , NULL , V_90 , V_78 ) ;
if ( V_90 -> V_82 == F_78 ( V_139 ) ) {
if ( ! F_79 ( V_90 ) &&
( V_136 -> V_140 & F_78 ( V_141 ) ) &&
V_78 < V_137 ) {
memset ( F_80 ( V_90 ) , 0 , sizeof( * F_80 ( V_90 ) ) ) ;
F_81 ( V_90 , V_142 , V_143 , F_82 ( V_78 ) ) ;
return - V_58 ;
}
}
#if F_83 ( V_144 )
else if ( V_90 -> V_82 == F_78 ( V_145 ) ) {
struct V_146 * V_147 = (struct V_146 * ) F_77 ( V_90 ) ;
if ( V_147 && V_78 < F_76 ( F_77 ( V_90 ) ) &&
V_78 >= V_148 ) {
if ( ( V_54 -> V_37 . V_38 . V_39 &&
! F_21 ( V_54 -> V_37 . V_38 . V_39 ) ) ||
V_147 -> V_149 . V_150 == 128 ) {
V_147 -> V_151 |= V_152 ;
F_84 ( F_77 ( V_90 ) , V_153 , V_78 ) ;
}
}
if ( ! F_79 ( V_90 ) && V_78 >= V_148 &&
V_78 < V_137 ) {
F_85 ( V_90 , V_154 , 0 , V_78 ) ;
return - V_58 ;
}
}
#endif
return 0 ;
}
void F_86 ( struct V_89 * V_90 , struct V_50 * V_40 ,
const struct V_75 * V_155 , T_5 V_82 )
{
struct V_12 * V_54 = F_22 ( V_40 ) ;
const struct V_75 * V_136 ;
struct V_65 V_66 ;
T_5 V_68 , V_156 ;
T_3 V_135 ;
struct V_16 * V_81 ;
unsigned int V_157 ;
T_1 V_9 ;
bool V_158 ;
V_136 = ( const struct V_75 * ) F_87 ( V_90 ) ;
V_158 = ( V_54 -> V_37 . V_38 . V_39 != 0 ) ;
memset ( & ( F_80 ( V_90 ) -> V_159 ) , 0 , sizeof( F_80 ( V_90 ) -> V_159 ) ) ;
V_9 = V_155 -> V_39 ;
if ( V_9 == 0 ) {
if ( ! F_77 ( V_90 ) ) {
V_40 -> V_98 . V_160 ++ ;
goto V_161;
}
if ( V_90 -> V_82 == F_78 ( V_139 ) ) {
V_81 = F_88 ( V_90 ) ;
V_9 = F_89 ( V_81 , V_136 -> V_39 ) ;
}
#if F_83 ( V_144 )
else if ( V_90 -> V_82 == F_78 ( V_145 ) ) {
const struct V_162 * V_163 ;
struct V_164 * V_165 ;
bool V_166 ;
int V_167 ;
V_165 = F_90 ( F_77 ( V_90 ) ,
& F_91 ( V_90 ) -> V_39 ) ;
if ( ! V_165 )
goto V_161;
V_163 = ( const struct V_162 * ) & V_165 -> V_168 ;
V_167 = F_92 ( V_163 ) ;
if ( V_167 == V_169 ) {
V_163 = & F_91 ( V_90 ) -> V_39 ;
V_167 = F_92 ( V_163 ) ;
}
if ( ( V_167 & V_170 ) == 0 )
V_166 = true ;
else {
V_166 = false ;
V_9 = V_163 -> V_171 [ 3 ] ;
}
F_93 ( V_165 ) ;
if ( V_166 )
goto V_172;
}
#endif
else
goto V_161;
V_158 = false ;
}
V_68 = V_155 -> V_68 ;
if ( V_68 & 0x1 ) {
V_68 &= ~ 0x1 ;
if ( V_90 -> V_82 == F_78 ( V_139 ) ) {
V_68 = V_136 -> V_68 ;
V_158 = false ;
} else if ( V_90 -> V_82 == F_78 ( V_145 ) ) {
V_68 = F_94 ( ( const struct V_173 * ) V_136 ) ;
V_158 = false ;
}
}
F_38 ( & V_66 , V_82 , V_9 , V_155 -> V_10 ,
V_54 -> V_37 . V_83 , F_40 ( V_68 ) , V_54 -> V_37 . V_30 ) ;
if ( V_118 ( V_90 , V_54 , & V_82 , & V_66 ) < 0 )
goto V_161;
V_81 = V_158 ? F_13 ( V_54 , 0 , & V_66 . V_10 ) : NULL ;
if ( ! V_81 ) {
V_81 = F_41 ( V_54 -> V_51 , & V_66 ) ;
if ( F_42 ( V_81 ) ) {
V_40 -> V_98 . V_174 ++ ;
goto V_161;
}
if ( V_158 )
F_7 ( V_54 , & V_81 -> V_9 , V_66 . V_10 ) ;
}
if ( V_81 -> V_9 . V_40 == V_40 ) {
F_43 ( V_81 ) ;
V_40 -> V_98 . V_175 ++ ;
goto V_161;
}
if ( F_75 ( V_40 , V_90 , V_81 , V_155 -> V_140 , V_136 ) ) {
F_43 ( V_81 ) ;
goto V_161;
}
if ( V_54 -> V_176 > 0 ) {
if ( F_95 ( V_177 ,
V_54 -> V_178 + V_179 ) ) {
V_54 -> V_176 -- ;
F_96 ( V_90 ) ;
} else
V_54 -> V_176 = 0 ;
}
V_68 = F_97 ( V_68 , V_136 , V_90 ) ;
V_156 = V_155 -> V_156 ;
if ( V_156 == 0 ) {
if ( V_90 -> V_82 == F_78 ( V_139 ) )
V_156 = V_136 -> V_156 ;
#if F_83 ( V_144 )
else if ( V_90 -> V_82 == F_78 ( V_145 ) )
V_156 = ( ( const struct V_173 * ) V_136 ) -> V_180 ;
#endif
else
V_156 = F_98 ( & V_81 -> V_9 ) ;
}
V_135 = V_155 -> V_140 ;
if ( V_90 -> V_82 == F_78 ( V_139 ) )
V_135 |= ( V_136 -> V_140 & F_78 ( V_141 ) ) ;
V_157 = F_99 ( V_81 -> V_9 . V_40 ) + sizeof( struct V_75 )
+ V_81 -> V_9 . V_181 + F_68 ( & V_54 -> V_130 ) ;
if ( V_157 > V_40 -> V_87 )
V_40 -> V_87 = V_157 ;
if ( F_100 ( V_90 , V_40 -> V_87 ) ) {
F_43 ( V_81 ) ;
V_40 -> V_98 . V_182 ++ ;
F_67 ( V_90 ) ;
return;
}
F_101 ( NULL , V_81 , V_90 , V_66 . V_10 , V_66 . V_39 , V_82 , V_68 , V_156 ,
V_135 , ! F_60 ( V_54 -> V_51 , F_61 ( V_40 ) ) ) ;
return;
#if F_83 ( V_144 )
V_172:
F_96 ( V_90 ) ;
#endif
V_161:
V_40 -> V_98 . V_183 ++ ;
F_67 ( V_90 ) ;
}
static void F_102 ( struct V_28 * V_29 ,
struct V_12 * V_13 ,
struct V_50 * V_40 ,
struct V_22 * V_23 ,
bool V_184 )
{
F_27 ( V_29 , V_13 ) ;
V_13 -> V_37 . V_38 . V_10 = V_23 -> V_38 . V_10 ;
V_13 -> V_37 . V_38 . V_39 = V_23 -> V_38 . V_39 ;
V_13 -> V_37 . V_27 = V_23 -> V_27 ;
V_13 -> V_37 . V_83 = V_23 -> V_83 ;
if ( V_40 -> type != V_84 ) {
memcpy ( V_40 -> V_185 , & V_23 -> V_38 . V_10 , 4 ) ;
memcpy ( V_40 -> V_186 , & V_23 -> V_38 . V_39 , 4 ) ;
}
F_24 ( V_29 , V_13 ) ;
V_13 -> V_37 . V_38 . V_156 = V_23 -> V_38 . V_156 ;
V_13 -> V_37 . V_38 . V_68 = V_23 -> V_38 . V_68 ;
V_13 -> V_37 . V_38 . V_140 = V_23 -> V_38 . V_140 ;
if ( V_13 -> V_37 . V_30 != V_23 -> V_30 ) {
int V_78 ;
V_13 -> V_37 . V_30 = V_23 -> V_30 ;
V_78 = F_39 ( V_40 ) ;
if ( V_184 )
V_40 -> V_78 = V_78 ;
}
F_10 ( V_13 ) ;
F_103 ( V_40 ) ;
}
int F_104 ( struct V_50 * V_40 , struct V_22 * V_23 , int V_187 )
{
int V_53 = 0 ;
struct V_12 * V_13 = F_22 ( V_40 ) ;
struct V_51 * V_51 = V_13 -> V_51 ;
struct V_28 * V_29 = F_105 ( V_51 , V_13 -> V_188 ) ;
F_46 ( ! V_29 -> V_45 ) ;
switch ( V_187 ) {
case V_189 :
if ( V_40 == V_29 -> V_45 ) {
V_13 = F_29 ( V_29 , V_23 , V_29 -> V_45 -> type ) ;
if ( ! V_13 )
V_13 = F_22 ( V_40 ) ;
}
memcpy ( V_23 , & V_13 -> V_37 , sizeof( * V_23 ) ) ;
break;
case V_190 :
case V_191 :
V_53 = - V_192 ;
if ( ! F_106 ( V_51 -> V_193 , V_194 ) )
goto V_195;
if ( V_23 -> V_38 . V_156 )
V_23 -> V_38 . V_140 |= F_78 ( V_141 ) ;
if ( ! ( V_23 -> V_25 & V_47 ) ) {
if ( ! ( V_23 -> V_25 & V_26 ) )
V_23 -> V_27 = 0 ;
if ( ! ( V_23 -> V_196 & V_26 ) )
V_23 -> V_83 = 0 ;
}
V_13 = F_29 ( V_29 , V_23 , V_29 -> V_45 -> type ) ;
if ( V_187 == V_190 ) {
if ( ! V_13 ) {
V_13 = F_45 ( V_51 , V_29 , V_23 ) ;
V_53 = F_107 ( V_13 ) ;
break;
}
V_53 = - V_197 ;
break;
}
if ( V_40 != V_29 -> V_45 && V_187 == V_191 ) {
if ( V_13 ) {
if ( V_13 -> V_40 != V_40 ) {
V_53 = - V_197 ;
break;
}
} else {
unsigned int V_198 = 0 ;
if ( F_21 ( V_23 -> V_38 . V_39 ) )
V_198 = V_199 ;
else if ( V_23 -> V_38 . V_39 )
V_198 = V_85 ;
if ( ( V_40 -> V_24 ^ V_198 ) & ( V_85 | V_199 ) ) {
V_53 = - V_121 ;
break;
}
V_13 = F_22 ( V_40 ) ;
}
}
if ( V_13 ) {
V_53 = 0 ;
F_102 ( V_29 , V_13 , V_40 , V_23 , true ) ;
} else {
V_53 = - V_200 ;
}
break;
case V_201 :
V_53 = - V_192 ;
if ( ! F_106 ( V_51 -> V_193 , V_194 ) )
goto V_195;
if ( V_40 == V_29 -> V_45 ) {
V_53 = - V_200 ;
V_13 = F_29 ( V_29 , V_23 , V_29 -> V_45 -> type ) ;
if ( ! V_13 )
goto V_195;
V_53 = - V_192 ;
if ( V_13 == F_22 ( V_29 -> V_45 ) )
goto V_195;
V_40 = V_13 -> V_40 ;
}
F_108 ( V_40 ) ;
V_53 = 0 ;
break;
default:
V_53 = - V_121 ;
}
V_195:
return V_53 ;
}
int F_109 ( struct V_50 * V_40 , int V_202 , bool V_203 )
{
struct V_12 * V_54 = F_22 ( V_40 ) ;
int V_80 = V_54 -> V_76 + sizeof( struct V_75 ) ;
int V_204 = 0xFFF8 - V_40 -> V_86 - V_80 ;
if ( V_202 < 68 )
return - V_121 ;
if ( V_202 > V_204 ) {
if ( V_203 )
return - V_121 ;
V_202 = V_204 ;
}
V_40 -> V_78 = V_202 ;
return 0 ;
}
int F_110 ( struct V_50 * V_40 , int V_202 )
{
return F_109 ( V_40 , V_202 , true ) ;
}
static void F_111 ( struct V_50 * V_40 )
{
struct V_12 * V_54 = F_22 ( V_40 ) ;
F_112 ( & V_54 -> V_117 ) ;
F_113 ( V_54 -> V_14 ) ;
F_113 ( V_40 -> V_97 ) ;
F_36 ( V_40 ) ;
}
void F_114 ( struct V_50 * V_40 , struct V_205 * V_35 )
{
struct V_12 * V_54 = F_22 ( V_40 ) ;
struct V_28 * V_29 ;
V_29 = F_105 ( V_54 -> V_51 , V_54 -> V_188 ) ;
if ( V_29 -> V_45 != V_40 ) {
F_27 ( V_29 , F_22 ( V_40 ) ) ;
F_115 ( V_40 , V_35 ) ;
}
}
struct V_51 * F_116 ( const struct V_50 * V_40 )
{
struct V_12 * V_54 = F_22 ( V_40 ) ;
return V_54 -> V_51 ;
}
int F_117 ( const struct V_50 * V_40 )
{
struct V_12 * V_54 = F_22 ( V_40 ) ;
return V_54 -> V_37 . V_30 ;
}
int F_118 ( struct V_51 * V_51 , int V_188 ,
struct V_52 * V_20 , char * V_206 )
{
struct V_28 * V_29 = F_105 ( V_51 , V_188 ) ;
struct V_22 V_37 ;
unsigned int V_15 ;
for ( V_15 = 0 ; V_15 < V_207 ; V_15 ++ )
F_119 ( & V_29 -> V_36 [ V_15 ] ) ;
if ( ! V_20 ) {
V_29 -> V_45 = NULL ;
return 0 ;
}
memset ( & V_37 , 0 , sizeof( V_37 ) ) ;
if ( V_206 )
F_31 ( V_37 . V_55 , V_206 , V_56 ) ;
F_120 () ;
V_29 -> V_45 = F_30 ( V_51 , V_20 , & V_37 ) ;
if ( ! F_42 ( V_29 -> V_45 ) ) {
V_29 -> V_45 -> V_208 |= V_209 ;
V_29 -> V_45 -> V_78 = F_39 ( V_29 -> V_45 ) ;
F_24 ( V_29 , F_22 ( V_29 -> V_45 ) ) ;
}
F_121 () ;
return F_107 ( V_29 -> V_45 ) ;
}
static void F_122 ( struct V_28 * V_29 , struct V_205 * V_35 ,
struct V_52 * V_20 )
{
struct V_51 * V_51 = F_61 ( V_29 -> V_45 ) ;
struct V_50 * V_40 , * V_210 ;
int V_46 ;
F_123 (net, dev, aux)
if ( V_40 -> V_52 == V_20 )
F_115 ( V_40 , V_35 ) ;
for ( V_46 = 0 ; V_46 < V_207 ; V_46 ++ ) {
struct V_12 * V_13 ;
struct V_211 * V_212 ;
struct V_34 * V_213 = & V_29 -> V_36 [ V_46 ] ;
F_124 (t, n, thead, hash_node)
if ( ! F_60 ( F_61 ( V_13 -> V_40 ) , V_51 ) )
F_115 ( V_13 -> V_40 , V_35 ) ;
}
}
void F_125 ( struct V_28 * V_29 , struct V_52 * V_20 )
{
F_126 ( V_214 ) ;
F_120 () ;
F_122 ( V_29 , & V_214 , V_20 ) ;
F_127 ( & V_214 ) ;
F_121 () ;
}
int F_128 ( struct V_50 * V_40 , struct V_215 * V_216 [] ,
struct V_22 * V_23 )
{
struct V_12 * V_88 ;
struct V_51 * V_51 = F_61 ( V_40 ) ;
struct V_28 * V_29 ;
int V_78 ;
int V_53 ;
V_88 = F_22 ( V_40 ) ;
V_29 = F_105 ( V_51 , V_88 -> V_188 ) ;
if ( V_88 -> V_48 ) {
if ( F_129 ( V_29 -> V_44 ) )
return - V_197 ;
} else {
if ( F_29 ( V_29 , V_23 , V_40 -> type ) )
return - V_197 ;
}
V_88 -> V_51 = V_51 ;
V_88 -> V_37 = * V_23 ;
V_53 = F_35 ( V_40 ) ;
if ( V_53 )
goto V_217;
if ( V_40 -> type == V_84 && ! V_216 [ V_218 ] )
F_130 ( V_40 ) ;
V_78 = F_39 ( V_40 ) ;
if ( ! V_216 [ V_219 ] )
V_40 -> V_78 = V_78 ;
F_24 ( V_29 , V_88 ) ;
V_217:
return V_53 ;
}
int F_131 ( struct V_50 * V_40 , struct V_215 * V_216 [] ,
struct V_22 * V_23 )
{
struct V_12 * V_13 ;
struct V_12 * V_54 = F_22 ( V_40 ) ;
struct V_51 * V_51 = V_54 -> V_51 ;
struct V_28 * V_29 = F_105 ( V_51 , V_54 -> V_188 ) ;
if ( V_40 == V_29 -> V_45 )
return - V_121 ;
V_13 = F_29 ( V_29 , V_23 , V_40 -> type ) ;
if ( V_13 ) {
if ( V_13 -> V_40 != V_40 )
return - V_197 ;
} else {
V_13 = V_54 ;
if ( V_40 -> type != V_84 ) {
unsigned int V_198 = 0 ;
if ( F_21 ( V_23 -> V_38 . V_39 ) )
V_198 = V_199 ;
else if ( V_23 -> V_38 . V_39 )
V_198 = V_85 ;
if ( ( V_40 -> V_24 ^ V_198 ) &
( V_85 | V_199 ) )
return - V_121 ;
}
}
F_102 ( V_29 , V_13 , V_40 , V_23 , ! V_216 [ V_219 ] ) ;
return 0 ;
}
int F_132 ( struct V_50 * V_40 )
{
struct V_12 * V_54 = F_22 ( V_40 ) ;
struct V_75 * V_38 = & V_54 -> V_37 . V_38 ;
int V_53 ;
V_40 -> V_220 = F_111 ;
V_40 -> V_97 = F_133 ( struct V_96 ) ;
if ( ! V_40 -> V_97 )
return - V_63 ;
V_54 -> V_14 = F_134 ( struct V_6 ) ;
if ( ! V_54 -> V_14 ) {
F_113 ( V_40 -> V_97 ) ;
return - V_63 ;
}
V_53 = F_135 ( & V_54 -> V_117 , V_40 ) ;
if ( V_53 ) {
F_113 ( V_54 -> V_14 ) ;
F_113 ( V_40 -> V_97 ) ;
return V_53 ;
}
V_54 -> V_40 = V_40 ;
V_54 -> V_51 = F_61 ( V_40 ) ;
strcpy ( V_54 -> V_37 . V_55 , V_40 -> V_55 ) ;
V_38 -> V_221 = 4 ;
V_38 -> V_222 = 5 ;
if ( V_54 -> V_48 ) {
V_40 -> V_208 |= V_209 ;
F_136 ( V_40 ) ;
}
return 0 ;
}
void F_137 ( struct V_50 * V_40 )
{
struct V_12 * V_54 = F_22 ( V_40 ) ;
struct V_51 * V_51 = V_54 -> V_51 ;
struct V_28 * V_29 ;
V_29 = F_105 ( V_51 , V_54 -> V_188 ) ;
if ( V_29 -> V_45 != V_40 )
F_27 ( V_29 , F_22 ( V_40 ) ) ;
F_10 ( V_54 ) ;
}
void F_138 ( struct V_50 * V_40 , int V_223 )
{
struct V_12 * V_54 = F_22 ( V_40 ) ;
V_54 -> V_188 = V_223 ;
}
