static unsigned int F_1 ( T_1 V_1 , T_1 V_2 )
{
return F_2 ( ( V_3 V_4 ) V_1 ^ ( V_3 V_4 ) V_2 ,
V_5 ) ;
}
static bool F_3 ( const struct V_6 * V_7 ,
T_2 V_8 , T_1 V_1 )
{
if ( V_7 -> V_9 & V_10 ) {
if ( V_8 & V_10 )
return V_1 == V_7 -> V_11 ;
else
return false ;
} else
return ! ( V_8 & V_10 ) ;
}
struct V_12 * F_4 ( struct V_13 * V_14 ,
int V_15 , T_2 V_8 ,
T_1 V_2 , T_1 V_16 ,
T_1 V_1 )
{
unsigned int V_17 ;
struct V_12 * V_18 , * V_19 = NULL ;
struct V_20 * V_21 ;
V_17 = F_1 ( V_1 , V_2 ) ;
V_21 = & V_14 -> V_22 [ V_17 ] ;
F_5 (t, head, hash_node) {
if ( V_16 != V_18 -> V_23 . V_24 . V_25 ||
V_2 != V_18 -> V_23 . V_24 . V_26 ||
! ( V_18 -> V_27 -> V_8 & V_28 ) )
continue;
if ( ! F_3 ( & V_18 -> V_23 , V_8 , V_1 ) )
continue;
if ( V_18 -> V_23 . V_15 == V_15 )
return V_18 ;
else
V_19 = V_18 ;
}
F_5 (t, head, hash_node) {
if ( V_2 != V_18 -> V_23 . V_24 . V_26 ||
V_18 -> V_23 . V_24 . V_25 != 0 ||
! ( V_18 -> V_27 -> V_8 & V_28 ) )
continue;
if ( ! F_3 ( & V_18 -> V_23 , V_8 , V_1 ) )
continue;
if ( V_18 -> V_23 . V_15 == V_15 )
return V_18 ;
else if ( ! V_19 )
V_19 = V_18 ;
}
V_17 = F_1 ( V_1 , 0 ) ;
V_21 = & V_14 -> V_22 [ V_17 ] ;
F_5 (t, head, hash_node) {
if ( ( V_16 != V_18 -> V_23 . V_24 . V_25 || V_18 -> V_23 . V_24 . V_26 != 0 ) &&
( V_16 != V_18 -> V_23 . V_24 . V_26 || ! F_6 ( V_16 ) ) )
continue;
if ( ! ( V_18 -> V_27 -> V_8 & V_28 ) )
continue;
if ( ! F_3 ( & V_18 -> V_23 , V_8 , V_1 ) )
continue;
if ( V_18 -> V_23 . V_15 == V_15 )
return V_18 ;
else if ( ! V_19 )
V_19 = V_18 ;
}
if ( V_8 & V_29 )
goto V_30;
F_5 (t, head, hash_node) {
if ( V_18 -> V_23 . V_11 != V_1 ||
V_18 -> V_23 . V_24 . V_25 != 0 ||
V_18 -> V_23 . V_24 . V_26 != 0 ||
! ( V_18 -> V_27 -> V_8 & V_28 ) )
continue;
if ( V_18 -> V_23 . V_15 == V_15 )
return V_18 ;
else if ( ! V_19 )
V_19 = V_18 ;
}
V_30:
if ( V_19 )
return V_19 ;
V_18 = F_7 ( V_14 -> V_31 ) ;
if ( V_18 )
return V_18 ;
if ( V_14 -> V_32 && V_14 -> V_32 -> V_8 & V_28 )
return F_8 ( V_14 -> V_32 ) ;
return NULL ;
}
static struct V_20 * F_9 ( struct V_13 * V_14 ,
struct V_6 * V_23 )
{
unsigned int V_33 ;
T_1 V_2 ;
T_1 V_11 = V_23 -> V_11 ;
if ( V_23 -> V_24 . V_26 && ! F_6 ( V_23 -> V_24 . V_26 ) )
V_2 = V_23 -> V_24 . V_26 ;
else
V_2 = 0 ;
if ( ! ( V_23 -> V_9 & V_10 ) && ( V_23 -> V_9 & V_34 ) )
V_11 = 0 ;
V_33 = F_1 ( V_11 , V_2 ) ;
return & V_14 -> V_22 [ V_33 ] ;
}
static void F_10 ( struct V_13 * V_14 , struct V_12 * V_18 )
{
struct V_20 * V_21 = F_9 ( V_14 , & V_18 -> V_23 ) ;
if ( V_18 -> V_35 )
F_11 ( V_14 -> V_31 , V_18 ) ;
F_12 ( & V_18 -> V_36 , V_21 ) ;
}
static void F_13 ( struct V_13 * V_14 , struct V_12 * V_18 )
{
if ( V_18 -> V_35 )
F_11 ( V_14 -> V_31 , NULL ) ;
F_14 ( & V_18 -> V_36 ) ;
}
static struct V_12 * F_15 ( struct V_13 * V_14 ,
struct V_6 * V_23 ,
int type )
{
T_1 V_2 = V_23 -> V_24 . V_26 ;
T_1 V_16 = V_23 -> V_24 . V_25 ;
T_1 V_1 = V_23 -> V_11 ;
T_2 V_8 = V_23 -> V_9 ;
int V_15 = V_23 -> V_15 ;
struct V_12 * V_18 = NULL ;
struct V_20 * V_21 = F_9 ( V_14 , V_23 ) ;
F_5 (t, head, hash_node) {
if ( V_16 == V_18 -> V_23 . V_24 . V_25 &&
V_2 == V_18 -> V_23 . V_24 . V_26 &&
V_15 == V_18 -> V_23 . V_15 &&
type == V_18 -> V_27 -> type &&
F_3 ( & V_18 -> V_23 , V_8 , V_1 ) )
break;
}
return V_18 ;
}
static struct V_37 * F_16 ( struct V_38 * V_38 ,
const struct V_39 * V_40 ,
struct V_6 * V_23 )
{
int V_41 ;
struct V_12 * V_42 ;
struct V_37 * V_27 ;
char V_43 [ V_44 ] ;
if ( V_23 -> V_43 [ 0 ] )
F_17 ( V_43 , V_23 -> V_43 , V_44 ) ;
else {
if ( strlen ( V_40 -> V_45 ) > ( V_44 - 3 ) ) {
V_41 = - V_46 ;
goto V_47;
}
F_17 ( V_43 , V_40 -> V_45 , V_44 ) ;
strncat ( V_43 , L_1 , 2 ) ;
}
F_18 () ;
V_27 = F_19 ( V_40 -> V_48 , V_43 , V_49 , V_40 -> V_50 ) ;
if ( ! V_27 ) {
V_41 = - V_51 ;
goto V_47;
}
F_20 ( V_27 , V_38 ) ;
V_27 -> V_39 = V_40 ;
V_42 = F_8 ( V_27 ) ;
V_42 -> V_23 = * V_23 ;
V_42 -> V_38 = V_38 ;
V_41 = F_21 ( V_27 ) ;
if ( V_41 )
goto V_52;
return V_27 ;
V_52:
F_22 ( V_27 ) ;
V_47:
return F_23 ( V_41 ) ;
}
static inline void F_24 ( struct V_53 * V_54 ,
int V_55 ,
T_1 V_26 , T_1 V_25 ,
T_1 V_1 , T_3 V_56 , int V_57 )
{
memset ( V_54 , 0 , sizeof( * V_54 ) ) ;
V_54 -> V_58 = V_57 ;
V_54 -> V_26 = V_26 ;
V_54 -> V_25 = V_25 ;
V_54 -> V_59 = V_56 ;
V_54 -> V_60 = V_55 ;
V_54 -> V_61 = V_1 ;
}
static int F_25 ( struct V_37 * V_27 )
{
struct V_37 * V_62 = NULL ;
struct V_12 * V_42 = F_8 ( V_27 ) ;
const struct V_63 * V_24 ;
int V_64 = V_65 ;
int V_66 = V_67 ;
int V_68 = V_42 -> V_64 + sizeof( struct V_63 ) ;
V_24 = & V_42 -> V_23 . V_24 ;
if ( V_24 -> V_26 ) {
struct V_53 V_54 ;
struct V_69 * V_70 ;
F_24 ( & V_54 , V_24 -> V_71 , V_24 -> V_26 ,
V_24 -> V_25 , V_42 -> V_23 . V_72 ,
F_26 ( V_24 -> V_56 ) , V_42 -> V_23 . V_15 ) ;
V_70 = F_27 ( V_42 -> V_38 , & V_54 ) ;
if ( ! F_28 ( V_70 ) ) {
V_62 = V_70 -> V_73 . V_27 ;
F_29 ( V_70 ) ;
}
if ( V_27 -> type != V_74 )
V_27 -> V_8 |= V_75 ;
F_30 ( & V_42 -> V_76 ) ;
}
if ( ! V_62 && V_42 -> V_23 . V_15 )
V_62 = F_31 ( V_42 -> V_38 , V_42 -> V_23 . V_15 ) ;
if ( V_62 ) {
V_64 = V_62 -> V_77 + V_62 -> V_78 ;
V_66 = V_62 -> V_66 ;
}
V_27 -> V_78 = V_68 + V_64 ;
V_66 -= ( V_27 -> V_77 + V_68 ) ;
if ( V_66 < 68 )
V_66 = 68 ;
return V_66 ;
}
static struct V_12 * F_32 ( struct V_38 * V_38 ,
struct V_13 * V_14 ,
struct V_6 * V_23 )
{
struct V_12 * V_79 ;
struct V_37 * V_27 ;
F_33 ( ! V_14 -> V_32 ) ;
V_27 = F_16 ( V_38 , V_14 -> V_32 -> V_39 , V_23 ) ;
if ( F_28 ( V_27 ) )
return F_34 ( V_27 ) ;
V_27 -> V_66 = F_25 ( V_27 ) ;
V_79 = F_8 ( V_27 ) ;
F_10 ( V_14 , V_79 ) ;
return V_79 ;
}
int F_35 ( struct V_12 * V_42 , struct V_80 * V_81 ,
const struct V_82 * V_83 , struct V_84 * V_85 ,
bool V_86 )
{
struct V_87 * V_88 ;
const struct V_63 * V_24 = F_36 ( V_81 ) ;
int V_41 ;
#ifdef F_37
if ( F_6 ( V_24 -> V_26 ) ) {
V_42 -> V_27 -> V_89 . V_90 ++ ;
V_81 -> V_91 = V_92 ;
}
#endif
if ( ( ! ( V_83 -> V_8 & V_93 ) && ( V_42 -> V_23 . V_9 & V_93 ) ) ||
( ( V_83 -> V_8 & V_93 ) && ! ( V_42 -> V_23 . V_9 & V_93 ) ) ) {
V_42 -> V_27 -> V_89 . V_94 ++ ;
V_42 -> V_27 -> V_89 . V_95 ++ ;
goto V_96;
}
if ( V_42 -> V_23 . V_9 & V_97 ) {
if ( ! ( V_83 -> V_8 & V_97 ) ||
( V_42 -> V_98 && ( V_99 ) ( F_38 ( V_83 -> V_100 ) - V_42 -> V_98 ) < 0 ) ) {
V_42 -> V_27 -> V_89 . V_101 ++ ;
V_42 -> V_27 -> V_89 . V_95 ++ ;
goto V_96;
}
V_42 -> V_98 = F_38 ( V_83 -> V_100 ) + 1 ;
}
F_39 ( V_81 ) ;
V_41 = F_40 ( V_24 , V_81 ) ;
if ( F_41 ( V_41 ) ) {
if ( V_86 )
F_42 ( L_2 ,
& V_24 -> V_25 , V_24 -> V_56 ) ;
if ( V_41 > 1 ) {
++ V_42 -> V_27 -> V_89 . V_102 ;
++ V_42 -> V_27 -> V_89 . V_95 ;
goto V_96;
}
}
V_88 = F_43 ( V_42 -> V_27 -> V_88 ) ;
F_44 ( & V_88 -> V_103 ) ;
V_88 -> V_104 ++ ;
V_88 -> V_105 += V_81 -> V_106 ;
F_45 ( & V_88 -> V_103 ) ;
F_46 ( V_81 , ! F_47 ( V_42 -> V_38 , F_48 ( V_42 -> V_27 ) ) ) ;
if ( V_42 -> V_27 -> type == V_74 ) {
V_81 -> V_71 = F_49 ( V_81 , V_42 -> V_27 ) ;
F_50 ( V_81 , F_51 ( V_81 ) , V_107 ) ;
} else {
V_81 -> V_27 = V_42 -> V_27 ;
}
if ( V_85 )
F_52 ( V_81 , (struct V_108 * ) V_85 ) ;
F_53 ( & V_42 -> V_109 , V_81 ) ;
return 0 ;
V_96:
F_54 ( V_81 ) ;
return 0 ;
}
static int F_55 ( struct V_110 * V_111 )
{
const struct V_112 * V_40 ;
int V_64 = - V_113 ;
if ( V_111 -> type == V_114 )
return 0 ;
if ( V_111 -> type >= V_115 )
return - V_113 ;
F_56 () ;
V_40 = F_7 ( V_116 [ V_111 -> type ] ) ;
if ( F_57 ( V_40 && V_40 -> V_117 ) )
V_64 = V_40 -> V_117 ( V_111 ) ;
F_58 () ;
return V_64 ;
}
int F_59 ( const struct V_112 * V_40 ,
unsigned int V_118 )
{
if ( V_118 >= V_115 )
return - V_119 ;
return ! F_60 ( ( const struct V_112 * * )
& V_116 [ V_118 ] ,
NULL , V_40 ) ? 0 : - 1 ;
}
int F_61 ( const struct V_112 * V_40 ,
unsigned int V_118 )
{
int V_120 ;
if ( V_118 >= V_115 )
return - V_119 ;
V_120 = ( F_60 ( ( const struct V_112 * * )
& V_116 [ V_118 ] ,
V_40 , NULL ) == V_40 ) ? 0 : - 1 ;
F_62 () ;
return V_120 ;
}
int F_63 ( struct V_12 * V_18 ,
struct V_110 * V_121 )
{
int V_64 ;
memset ( & V_18 -> V_122 , 0 , sizeof( V_18 -> V_122 ) ) ;
V_64 = F_55 ( V_121 ) ;
if ( V_64 < 0 )
return V_64 ;
V_18 -> V_122 . type = V_121 -> type ;
V_18 -> V_122 . V_123 = V_121 -> V_123 ;
V_18 -> V_122 . V_124 = V_121 -> V_124 ;
V_18 -> V_122 . V_8 = V_121 -> V_8 ;
V_18 -> V_117 = V_64 ;
V_18 -> V_64 = V_18 -> V_117 + V_18 -> V_125 ;
return 0 ;
}
int V_110 ( struct V_80 * V_81 , struct V_12 * V_18 ,
T_4 * V_71 , struct V_53 * V_54 )
{
const struct V_112 * V_40 ;
int V_120 = - V_113 ;
if ( V_18 -> V_122 . type == V_114 )
return 0 ;
if ( V_18 -> V_122 . type >= V_115 )
return - V_113 ;
F_56 () ;
V_40 = F_7 ( V_116 [ V_18 -> V_122 . type ] ) ;
if ( F_57 ( V_40 && V_40 -> V_126 ) )
V_120 = V_40 -> V_126 ( V_81 , & V_18 -> V_122 , V_71 , V_54 ) ;
F_58 () ;
return V_120 ;
}
static int F_64 ( struct V_37 * V_27 , struct V_80 * V_81 ,
struct V_69 * V_70 , T_2 V_127 ,
const struct V_63 * V_128 )
{
struct V_12 * V_42 = F_8 ( V_27 ) ;
int V_129 = V_81 -> V_106 - V_42 -> V_64 - V_27 -> V_77 ;
int V_66 ;
if ( V_127 )
V_66 = F_65 ( & V_70 -> V_73 ) - V_27 -> V_77
- sizeof( struct V_63 ) - V_42 -> V_64 ;
else
V_66 = F_66 ( V_81 ) ? F_65 ( F_66 ( V_81 ) ) : V_27 -> V_66 ;
if ( F_66 ( V_81 ) )
F_66 ( V_81 ) -> V_40 -> V_130 ( F_66 ( V_81 ) , NULL , V_81 , V_66 ) ;
if ( V_81 -> V_71 == F_67 ( V_131 ) ) {
if ( ! F_68 ( V_81 ) &&
( V_128 -> V_132 & F_67 ( V_133 ) ) &&
V_66 < V_129 ) {
memset ( F_69 ( V_81 ) , 0 , sizeof( * F_69 ( V_81 ) ) ) ;
F_70 ( V_81 , V_134 , V_135 , F_71 ( V_66 ) ) ;
return - V_46 ;
}
}
#if F_72 ( V_136 )
else if ( V_81 -> V_71 == F_67 ( V_137 ) ) {
struct V_138 * V_139 = (struct V_138 * ) F_66 ( V_81 ) ;
if ( V_139 && V_66 < F_65 ( F_66 ( V_81 ) ) &&
V_66 >= V_140 ) {
if ( ( V_42 -> V_23 . V_24 . V_26 &&
! F_6 ( V_42 -> V_23 . V_24 . V_26 ) ) ||
V_139 -> V_141 . V_142 == 128 ) {
V_139 -> V_143 |= V_144 ;
F_73 ( F_66 ( V_81 ) , V_145 , V_66 ) ;
}
}
if ( ! F_68 ( V_81 ) && V_66 >= V_140 &&
V_66 < V_129 ) {
F_74 ( V_81 , V_146 , 0 , V_66 ) ;
return - V_46 ;
}
}
#endif
return 0 ;
}
void F_75 ( struct V_80 * V_81 , struct V_37 * V_27 ,
const struct V_63 * V_147 , T_4 V_71 )
{
struct V_12 * V_42 = F_8 ( V_27 ) ;
const struct V_63 * V_128 ;
struct V_53 V_54 ;
T_4 V_56 , V_148 ;
T_2 V_127 ;
struct V_69 * V_70 ;
unsigned int V_149 ;
T_1 V_73 ;
bool V_150 ;
V_128 = ( const struct V_63 * ) F_76 ( V_81 ) ;
V_150 = ( V_42 -> V_23 . V_24 . V_26 != 0 ) ;
memset ( & ( F_69 ( V_81 ) -> V_151 ) , 0 , sizeof( F_69 ( V_81 ) -> V_151 ) ) ;
V_73 = V_147 -> V_26 ;
if ( V_73 == 0 ) {
if ( ! F_66 ( V_81 ) ) {
V_27 -> V_89 . V_152 ++ ;
goto V_153;
}
if ( V_81 -> V_71 == F_67 ( V_131 ) ) {
V_70 = F_77 ( V_81 ) ;
V_73 = F_78 ( V_70 , V_128 -> V_26 ) ;
}
#if F_72 ( V_136 )
else if ( V_81 -> V_71 == F_67 ( V_137 ) ) {
const struct V_154 * V_155 ;
struct V_156 * V_157 ;
bool V_158 ;
int V_159 ;
V_157 = F_79 ( F_66 ( V_81 ) ,
& F_80 ( V_81 ) -> V_26 ) ;
if ( ! V_157 )
goto V_153;
V_155 = ( const struct V_154 * ) & V_157 -> V_160 ;
V_159 = F_81 ( V_155 ) ;
if ( V_159 == V_161 ) {
V_155 = & F_80 ( V_81 ) -> V_26 ;
V_159 = F_81 ( V_155 ) ;
}
if ( ( V_159 & V_162 ) == 0 )
V_158 = true ;
else {
V_158 = false ;
V_73 = V_155 -> V_163 [ 3 ] ;
}
F_82 ( V_157 ) ;
if ( V_158 )
goto V_164;
}
#endif
else
goto V_153;
V_150 = false ;
}
V_56 = V_147 -> V_56 ;
if ( V_56 & 0x1 ) {
V_56 &= ~ 0x1 ;
if ( V_81 -> V_71 == F_67 ( V_131 ) ) {
V_56 = V_128 -> V_56 ;
V_150 = false ;
} else if ( V_81 -> V_71 == F_67 ( V_137 ) ) {
V_56 = F_83 ( ( const struct V_165 * ) V_128 ) ;
V_150 = false ;
}
}
F_24 ( & V_54 , V_71 , V_73 , V_147 -> V_25 ,
V_42 -> V_23 . V_72 , F_26 ( V_56 ) , V_42 -> V_23 . V_15 ) ;
if ( V_110 ( V_81 , V_42 , & V_71 , & V_54 ) < 0 )
goto V_153;
V_70 = V_150 ? F_84 ( & V_42 -> V_76 , & V_54 . V_25 ) :
NULL ;
if ( ! V_70 ) {
V_70 = F_27 ( V_42 -> V_38 , & V_54 ) ;
if ( F_28 ( V_70 ) ) {
V_27 -> V_89 . V_166 ++ ;
goto V_153;
}
if ( V_150 )
F_85 ( & V_42 -> V_76 , & V_70 -> V_73 ,
V_54 . V_25 ) ;
}
if ( V_70 -> V_73 . V_27 == V_27 ) {
F_29 ( V_70 ) ;
V_27 -> V_89 . V_167 ++ ;
goto V_153;
}
if ( F_64 ( V_27 , V_81 , V_70 , V_147 -> V_132 , V_128 ) ) {
F_29 ( V_70 ) ;
goto V_153;
}
if ( V_42 -> V_168 > 0 ) {
if ( F_86 ( V_169 ,
V_42 -> V_170 + V_171 ) ) {
V_42 -> V_168 -- ;
F_87 ( V_81 ) ;
} else
V_42 -> V_168 = 0 ;
}
V_56 = F_88 ( V_56 , V_128 , V_81 ) ;
V_148 = V_147 -> V_148 ;
if ( V_148 == 0 ) {
if ( V_81 -> V_71 == F_67 ( V_131 ) )
V_148 = V_128 -> V_148 ;
#if F_72 ( V_136 )
else if ( V_81 -> V_71 == F_67 ( V_137 ) )
V_148 = ( ( const struct V_165 * ) V_128 ) -> V_172 ;
#endif
else
V_148 = F_89 ( & V_70 -> V_73 ) ;
}
V_127 = V_147 -> V_132 ;
if ( V_81 -> V_71 == F_67 ( V_131 ) )
V_127 |= ( V_128 -> V_132 & F_67 ( V_133 ) ) ;
V_149 = F_90 ( V_70 -> V_73 . V_27 ) + sizeof( struct V_63 )
+ V_70 -> V_73 . V_173 + F_55 ( & V_42 -> V_122 ) ;
if ( V_149 > V_27 -> V_78 )
V_27 -> V_78 = V_149 ;
if ( F_91 ( V_81 , V_27 -> V_78 ) ) {
F_29 ( V_70 ) ;
V_27 -> V_89 . V_174 ++ ;
F_54 ( V_81 ) ;
return;
}
F_92 ( NULL , V_70 , V_81 , V_54 . V_25 , V_54 . V_26 , V_71 , V_56 , V_148 ,
V_127 , ! F_47 ( V_42 -> V_38 , F_48 ( V_27 ) ) ) ;
return;
#if F_72 ( V_136 )
V_164:
F_87 ( V_81 ) ;
#endif
V_153:
V_27 -> V_89 . V_175 ++ ;
F_54 ( V_81 ) ;
}
static void F_93 ( struct V_13 * V_14 ,
struct V_12 * V_18 ,
struct V_37 * V_27 ,
struct V_6 * V_7 ,
bool V_176 )
{
F_13 ( V_14 , V_18 ) ;
V_18 -> V_23 . V_24 . V_25 = V_7 -> V_24 . V_25 ;
V_18 -> V_23 . V_24 . V_26 = V_7 -> V_24 . V_26 ;
V_18 -> V_23 . V_11 = V_7 -> V_11 ;
V_18 -> V_23 . V_72 = V_7 -> V_72 ;
if ( V_27 -> type != V_74 ) {
memcpy ( V_27 -> V_177 , & V_7 -> V_24 . V_25 , 4 ) ;
memcpy ( V_27 -> V_178 , & V_7 -> V_24 . V_26 , 4 ) ;
}
F_10 ( V_14 , V_18 ) ;
V_18 -> V_23 . V_24 . V_148 = V_7 -> V_24 . V_148 ;
V_18 -> V_23 . V_24 . V_56 = V_7 -> V_24 . V_56 ;
V_18 -> V_23 . V_24 . V_132 = V_7 -> V_24 . V_132 ;
if ( V_18 -> V_23 . V_15 != V_7 -> V_15 ) {
int V_66 ;
V_18 -> V_23 . V_15 = V_7 -> V_15 ;
V_66 = F_25 ( V_27 ) ;
if ( V_176 )
V_27 -> V_66 = V_66 ;
}
F_30 ( & V_18 -> V_76 ) ;
F_94 ( V_27 ) ;
}
int F_95 ( struct V_37 * V_27 , struct V_6 * V_7 , int V_179 )
{
int V_41 = 0 ;
struct V_12 * V_18 = F_8 ( V_27 ) ;
struct V_38 * V_38 = V_18 -> V_38 ;
struct V_13 * V_14 = F_96 ( V_38 , V_18 -> V_180 ) ;
F_33 ( ! V_14 -> V_32 ) ;
switch ( V_179 ) {
case V_181 :
if ( V_27 == V_14 -> V_32 ) {
V_18 = F_15 ( V_14 , V_7 , V_14 -> V_32 -> type ) ;
if ( ! V_18 )
V_18 = F_8 ( V_27 ) ;
}
memcpy ( V_7 , & V_18 -> V_23 , sizeof( * V_7 ) ) ;
break;
case V_182 :
case V_183 :
V_41 = - V_184 ;
if ( ! F_97 ( V_38 -> V_185 , V_186 ) )
goto V_187;
if ( V_7 -> V_24 . V_148 )
V_7 -> V_24 . V_132 |= F_67 ( V_133 ) ;
if ( ! ( V_7 -> V_9 & V_34 ) ) {
if ( ! ( V_7 -> V_9 & V_10 ) )
V_7 -> V_11 = 0 ;
if ( ! ( V_7 -> V_188 & V_10 ) )
V_7 -> V_72 = 0 ;
}
V_18 = F_15 ( V_14 , V_7 , V_14 -> V_32 -> type ) ;
if ( V_179 == V_182 ) {
if ( ! V_18 ) {
V_18 = F_32 ( V_38 , V_14 , V_7 ) ;
V_41 = F_98 ( V_18 ) ;
break;
}
V_41 = - V_189 ;
break;
}
if ( V_27 != V_14 -> V_32 && V_179 == V_183 ) {
if ( V_18 ) {
if ( V_18 -> V_27 != V_27 ) {
V_41 = - V_189 ;
break;
}
} else {
unsigned int V_190 = 0 ;
if ( F_6 ( V_7 -> V_24 . V_26 ) )
V_190 = V_191 ;
else if ( V_7 -> V_24 . V_26 )
V_190 = V_75 ;
if ( ( V_27 -> V_8 ^ V_190 ) & ( V_75 | V_191 ) ) {
V_41 = - V_113 ;
break;
}
V_18 = F_8 ( V_27 ) ;
}
}
if ( V_18 ) {
V_41 = 0 ;
F_93 ( V_14 , V_18 , V_27 , V_7 , true ) ;
} else {
V_41 = - V_192 ;
}
break;
case V_193 :
V_41 = - V_184 ;
if ( ! F_97 ( V_38 -> V_185 , V_186 ) )
goto V_187;
if ( V_27 == V_14 -> V_32 ) {
V_41 = - V_192 ;
V_18 = F_15 ( V_14 , V_7 , V_14 -> V_32 -> type ) ;
if ( ! V_18 )
goto V_187;
V_41 = - V_184 ;
if ( V_18 == F_8 ( V_14 -> V_32 ) )
goto V_187;
V_27 = V_18 -> V_27 ;
}
F_99 ( V_27 ) ;
V_41 = 0 ;
break;
default:
V_41 = - V_113 ;
}
V_187:
return V_41 ;
}
int F_100 ( struct V_37 * V_27 , int V_194 , bool V_195 )
{
struct V_12 * V_42 = F_8 ( V_27 ) ;
int V_68 = V_42 -> V_64 + sizeof( struct V_63 ) ;
int V_196 = 0xFFF8 - V_27 -> V_77 - V_68 ;
if ( V_194 < 68 )
return - V_113 ;
if ( V_194 > V_196 ) {
if ( V_195 )
return - V_113 ;
V_194 = V_196 ;
}
V_27 -> V_66 = V_194 ;
return 0 ;
}
int F_101 ( struct V_37 * V_27 , int V_194 )
{
return F_100 ( V_27 , V_194 , true ) ;
}
static void F_102 ( struct V_37 * V_27 )
{
struct V_12 * V_42 = F_8 ( V_27 ) ;
F_103 ( & V_42 -> V_109 ) ;
F_104 ( & V_42 -> V_76 ) ;
F_105 ( V_27 -> V_88 ) ;
F_22 ( V_27 ) ;
}
void F_106 ( struct V_37 * V_27 , struct V_197 * V_21 )
{
struct V_12 * V_42 = F_8 ( V_27 ) ;
struct V_13 * V_14 ;
V_14 = F_96 ( V_42 -> V_38 , V_42 -> V_180 ) ;
if ( V_14 -> V_32 != V_27 ) {
F_13 ( V_14 , F_8 ( V_27 ) ) ;
F_107 ( V_27 , V_21 ) ;
}
}
struct V_38 * F_108 ( const struct V_37 * V_27 )
{
struct V_12 * V_42 = F_8 ( V_27 ) ;
return V_42 -> V_38 ;
}
int F_109 ( const struct V_37 * V_27 )
{
struct V_12 * V_42 = F_8 ( V_27 ) ;
return V_42 -> V_23 . V_15 ;
}
int F_110 ( struct V_38 * V_38 , int V_180 ,
struct V_39 * V_40 , char * V_198 )
{
struct V_13 * V_14 = F_96 ( V_38 , V_180 ) ;
struct V_6 V_23 ;
unsigned int V_199 ;
for ( V_199 = 0 ; V_199 < V_200 ; V_199 ++ )
F_111 ( & V_14 -> V_22 [ V_199 ] ) ;
if ( ! V_40 ) {
V_14 -> V_32 = NULL ;
return 0 ;
}
memset ( & V_23 , 0 , sizeof( V_23 ) ) ;
if ( V_198 )
F_17 ( V_23 . V_43 , V_198 , V_44 ) ;
F_112 () ;
V_14 -> V_32 = F_16 ( V_38 , V_40 , & V_23 ) ;
if ( ! F_28 ( V_14 -> V_32 ) ) {
V_14 -> V_32 -> V_201 |= V_202 ;
V_14 -> V_32 -> V_66 = F_25 ( V_14 -> V_32 ) ;
F_10 ( V_14 , F_8 ( V_14 -> V_32 ) ) ;
}
F_113 () ;
return F_98 ( V_14 -> V_32 ) ;
}
static void F_114 ( struct V_13 * V_14 , struct V_197 * V_21 ,
struct V_39 * V_40 )
{
struct V_38 * V_38 = F_48 ( V_14 -> V_32 ) ;
struct V_37 * V_27 , * V_203 ;
int V_33 ;
F_115 (net, dev, aux)
if ( V_27 -> V_39 == V_40 )
F_107 ( V_27 , V_21 ) ;
for ( V_33 = 0 ; V_33 < V_200 ; V_33 ++ ) {
struct V_12 * V_18 ;
struct V_204 * V_205 ;
struct V_20 * V_206 = & V_14 -> V_22 [ V_33 ] ;
F_116 (t, n, thead, hash_node)
if ( ! F_47 ( F_48 ( V_18 -> V_27 ) , V_38 ) )
F_107 ( V_18 -> V_27 , V_21 ) ;
}
}
void F_117 ( struct V_13 * V_14 , struct V_39 * V_40 )
{
F_118 ( V_207 ) ;
F_112 () ;
F_114 ( V_14 , & V_207 , V_40 ) ;
F_119 ( & V_207 ) ;
F_113 () ;
}
int F_120 ( struct V_37 * V_27 , struct V_208 * V_209 [] ,
struct V_6 * V_7 )
{
struct V_12 * V_79 ;
struct V_38 * V_38 = F_48 ( V_27 ) ;
struct V_13 * V_14 ;
int V_66 ;
int V_41 ;
V_79 = F_8 ( V_27 ) ;
V_14 = F_96 ( V_38 , V_79 -> V_180 ) ;
if ( V_79 -> V_35 ) {
if ( F_121 ( V_14 -> V_31 ) )
return - V_189 ;
} else {
if ( F_15 ( V_14 , V_7 , V_27 -> type ) )
return - V_189 ;
}
V_79 -> V_38 = V_38 ;
V_79 -> V_23 = * V_7 ;
V_41 = F_21 ( V_27 ) ;
if ( V_41 )
goto V_210;
if ( V_27 -> type == V_74 && ! V_209 [ V_211 ] )
F_122 ( V_27 ) ;
V_66 = F_25 ( V_27 ) ;
if ( ! V_209 [ V_212 ] )
V_27 -> V_66 = V_66 ;
F_10 ( V_14 , V_79 ) ;
V_210:
return V_41 ;
}
int F_123 ( struct V_37 * V_27 , struct V_208 * V_209 [] ,
struct V_6 * V_7 )
{
struct V_12 * V_18 ;
struct V_12 * V_42 = F_8 ( V_27 ) ;
struct V_38 * V_38 = V_42 -> V_38 ;
struct V_13 * V_14 = F_96 ( V_38 , V_42 -> V_180 ) ;
if ( V_27 == V_14 -> V_32 )
return - V_113 ;
V_18 = F_15 ( V_14 , V_7 , V_27 -> type ) ;
if ( V_18 ) {
if ( V_18 -> V_27 != V_27 )
return - V_189 ;
} else {
V_18 = V_42 ;
if ( V_27 -> type != V_74 ) {
unsigned int V_190 = 0 ;
if ( F_6 ( V_7 -> V_24 . V_26 ) )
V_190 = V_191 ;
else if ( V_7 -> V_24 . V_26 )
V_190 = V_75 ;
if ( ( V_27 -> V_8 ^ V_190 ) &
( V_75 | V_191 ) )
return - V_113 ;
}
}
F_93 ( V_14 , V_18 , V_27 , V_7 , ! V_209 [ V_212 ] ) ;
return 0 ;
}
int F_124 ( struct V_37 * V_27 )
{
struct V_12 * V_42 = F_8 ( V_27 ) ;
struct V_63 * V_24 = & V_42 -> V_23 . V_24 ;
int V_41 ;
V_27 -> V_213 = F_102 ;
V_27 -> V_88 = F_125 ( struct V_87 ) ;
if ( ! V_27 -> V_88 )
return - V_51 ;
V_41 = F_126 ( & V_42 -> V_76 , V_214 ) ;
if ( V_41 ) {
F_105 ( V_27 -> V_88 ) ;
return V_41 ;
}
V_41 = F_127 ( & V_42 -> V_109 , V_27 ) ;
if ( V_41 ) {
F_104 ( & V_42 -> V_76 ) ;
F_105 ( V_27 -> V_88 ) ;
return V_41 ;
}
V_42 -> V_27 = V_27 ;
V_42 -> V_38 = F_48 ( V_27 ) ;
strcpy ( V_42 -> V_23 . V_43 , V_27 -> V_43 ) ;
V_24 -> V_215 = 4 ;
V_24 -> V_216 = 5 ;
if ( V_42 -> V_35 ) {
V_27 -> V_201 |= V_202 ;
F_128 ( V_27 ) ;
}
return 0 ;
}
void F_129 ( struct V_37 * V_27 )
{
struct V_12 * V_42 = F_8 ( V_27 ) ;
struct V_38 * V_38 = V_42 -> V_38 ;
struct V_13 * V_14 ;
V_14 = F_96 ( V_38 , V_42 -> V_180 ) ;
if ( V_14 -> V_32 != V_27 )
F_13 ( V_14 , F_8 ( V_27 ) ) ;
F_30 ( & V_42 -> V_76 ) ;
}
void F_130 ( struct V_37 * V_27 , int V_217 )
{
struct V_12 * V_42 = F_8 ( V_27 ) ;
V_42 -> V_180 = V_217 ;
}
