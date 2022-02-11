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
if ( V_29 -> V_44 && V_29 -> V_44 -> V_24 & V_41 )
return F_22 ( V_29 -> V_44 ) ;
return NULL ;
}
static struct V_34 * F_23 ( struct V_28 * V_29 ,
struct V_22 * V_37 )
{
unsigned int V_45 ;
T_1 V_2 ;
T_1 V_27 = V_37 -> V_27 ;
if ( V_37 -> V_38 . V_39 && ! F_21 ( V_37 -> V_38 . V_39 ) )
V_2 = V_37 -> V_38 . V_39 ;
else
V_2 = 0 ;
if ( ! ( V_37 -> V_25 & V_26 ) && ( V_37 -> V_25 & V_46 ) )
V_27 = 0 ;
V_45 = F_1 ( V_27 , V_2 ) ;
return & V_29 -> V_36 [ V_45 ] ;
}
static void F_24 ( struct V_28 * V_29 , struct V_12 * V_13 )
{
struct V_34 * V_35 = F_23 ( V_29 , & V_13 -> V_37 ) ;
F_25 ( & V_13 -> V_47 , V_35 ) ;
}
static void F_26 ( struct V_12 * V_13 )
{
F_27 ( & V_13 -> V_47 ) ;
}
static struct V_12 * F_28 ( struct V_28 * V_29 ,
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
static struct V_48 * F_29 ( struct V_49 * V_49 ,
const struct V_50 * V_20 ,
struct V_22 * V_37 )
{
int V_51 ;
struct V_12 * V_52 ;
struct V_48 * V_40 ;
char V_53 [ V_54 ] ;
if ( V_37 -> V_53 [ 0 ] )
F_30 ( V_53 , V_37 -> V_53 , V_54 ) ;
else {
if ( strlen ( V_20 -> V_55 ) > ( V_54 - 3 ) ) {
V_51 = - V_56 ;
goto V_57;
}
F_30 ( V_53 , V_20 -> V_55 , V_54 ) ;
strncat ( V_53 , L_1 , 2 ) ;
}
F_31 () ;
V_40 = F_32 ( V_20 -> V_58 , V_53 , V_59 , V_20 -> V_60 ) ;
if ( ! V_40 ) {
V_51 = - V_61 ;
goto V_57;
}
F_33 ( V_40 , V_49 ) ;
V_40 -> V_50 = V_20 ;
V_52 = F_22 ( V_40 ) ;
V_52 -> V_37 = * V_37 ;
V_52 -> V_49 = V_49 ;
V_51 = F_34 ( V_40 ) ;
if ( V_51 )
goto V_62;
return V_40 ;
V_62:
F_35 ( V_40 ) ;
V_57:
return F_36 ( V_51 ) ;
}
static inline void F_37 ( struct V_63 * V_64 ,
int V_65 ,
T_1 V_39 , T_1 V_10 ,
T_1 V_1 , T_4 V_66 , int V_67 )
{
memset ( V_64 , 0 , sizeof( * V_64 ) ) ;
V_64 -> V_68 = V_67 ;
V_64 -> V_39 = V_39 ;
V_64 -> V_10 = V_10 ;
V_64 -> V_69 = V_66 ;
V_64 -> V_70 = V_65 ;
V_64 -> V_71 = V_1 ;
}
static int F_38 ( struct V_48 * V_40 )
{
struct V_48 * V_72 = NULL ;
struct V_12 * V_52 = F_22 ( V_40 ) ;
const struct V_73 * V_38 ;
int V_74 = V_75 ;
int V_76 = V_77 ;
int V_78 = V_52 -> V_74 + sizeof( struct V_73 ) ;
V_38 = & V_52 -> V_37 . V_38 ;
if ( V_38 -> V_39 ) {
struct V_63 V_64 ;
struct V_16 * V_79 ;
F_37 ( & V_64 , V_38 -> V_80 , V_38 -> V_39 ,
V_38 -> V_10 , V_52 -> V_37 . V_81 ,
F_39 ( V_38 -> V_66 ) , V_52 -> V_37 . V_30 ) ;
V_79 = F_40 ( V_52 -> V_49 , & V_64 ) ;
if ( ! F_41 ( V_79 ) ) {
V_72 = V_79 -> V_9 . V_40 ;
F_7 ( V_52 , & V_79 -> V_9 , V_64 . V_10 ) ;
F_42 ( V_79 ) ;
}
if ( V_40 -> type != V_82 )
V_40 -> V_24 |= V_83 ;
}
if ( ! V_72 && V_52 -> V_37 . V_30 )
V_72 = F_43 ( V_52 -> V_49 , V_52 -> V_37 . V_30 ) ;
if ( V_72 ) {
V_74 = V_72 -> V_84 + V_72 -> V_85 ;
V_76 = V_72 -> V_76 ;
}
V_40 -> V_86 = V_52 -> V_37 . V_30 ;
V_40 -> V_85 = V_78 + V_74 ;
V_76 -= ( V_40 -> V_84 + V_78 ) ;
if ( V_76 < 68 )
V_76 = 68 ;
return V_76 ;
}
static struct V_12 * F_44 ( struct V_49 * V_49 ,
struct V_28 * V_29 ,
struct V_22 * V_37 )
{
struct V_12 * V_87 ;
struct V_48 * V_40 ;
F_45 ( ! V_29 -> V_44 ) ;
V_40 = F_29 ( V_49 , V_29 -> V_44 -> V_50 , V_37 ) ;
if ( F_41 ( V_40 ) )
return F_46 ( V_40 ) ;
V_40 -> V_76 = F_38 ( V_40 ) ;
V_87 = F_22 ( V_40 ) ;
F_24 ( V_29 , V_87 ) ;
return V_87 ;
}
int F_47 ( struct V_12 * V_52 , struct V_88 * V_89 ,
const struct V_90 * V_91 , bool V_92 )
{
struct V_93 * V_94 ;
const struct V_73 * V_38 = F_48 ( V_89 ) ;
int V_51 ;
#ifdef F_49
if ( F_21 ( V_38 -> V_39 ) ) {
V_52 -> V_40 -> V_95 . V_96 ++ ;
V_89 -> V_97 = V_98 ;
}
#endif
if ( ( ! ( V_91 -> V_24 & V_99 ) && ( V_52 -> V_37 . V_25 & V_99 ) ) ||
( ( V_91 -> V_24 & V_99 ) && ! ( V_52 -> V_37 . V_25 & V_99 ) ) ) {
V_52 -> V_40 -> V_95 . V_100 ++ ;
V_52 -> V_40 -> V_95 . V_101 ++ ;
goto V_102;
}
if ( V_52 -> V_37 . V_25 & V_103 ) {
if ( ! ( V_91 -> V_24 & V_103 ) ||
( V_52 -> V_104 && ( V_105 ) ( F_50 ( V_91 -> V_106 ) - V_52 -> V_104 ) < 0 ) ) {
V_52 -> V_40 -> V_95 . V_107 ++ ;
V_52 -> V_40 -> V_95 . V_101 ++ ;
goto V_102;
}
V_52 -> V_104 = F_50 ( V_91 -> V_106 ) + 1 ;
}
F_51 ( V_89 ) ;
V_51 = F_52 ( V_38 , V_89 ) ;
if ( F_53 ( V_51 ) ) {
if ( V_92 )
F_54 ( L_2 ,
& V_38 -> V_10 , V_38 -> V_66 ) ;
if ( V_51 > 1 ) {
++ V_52 -> V_40 -> V_95 . V_108 ;
++ V_52 -> V_40 -> V_95 . V_101 ;
goto V_102;
}
}
V_94 = F_55 ( V_52 -> V_40 -> V_94 ) ;
F_56 ( & V_94 -> V_109 ) ;
V_94 -> V_110 ++ ;
V_94 -> V_111 += V_89 -> V_112 ;
F_57 ( & V_94 -> V_109 ) ;
F_58 ( V_89 , ! F_59 ( V_52 -> V_49 , F_60 ( V_52 -> V_40 ) ) ) ;
if ( V_52 -> V_40 -> type == V_82 ) {
V_89 -> V_80 = F_61 ( V_89 , V_52 -> V_40 ) ;
F_62 ( V_89 , F_63 ( V_89 ) , V_113 ) ;
} else {
V_89 -> V_40 = V_52 -> V_40 ;
}
F_64 ( & V_52 -> V_114 , V_89 ) ;
return 0 ;
V_102:
F_65 ( V_89 ) ;
return 0 ;
}
static int F_66 ( struct V_115 * V_116 )
{
const struct V_117 * V_20 ;
int V_74 = - V_118 ;
if ( V_116 -> type == V_119 )
return 0 ;
if ( V_116 -> type >= V_120 )
return - V_118 ;
F_14 () ;
V_20 = F_15 ( V_121 [ V_116 -> type ] ) ;
if ( F_67 ( V_20 && V_20 -> V_122 ) )
V_74 = V_20 -> V_122 ( V_116 ) ;
F_17 () ;
return V_74 ;
}
int F_68 ( const struct V_117 * V_20 ,
unsigned int V_123 )
{
if ( V_123 >= V_120 )
return - V_124 ;
return ! F_69 ( ( const struct V_117 * * )
& V_121 [ V_123 ] ,
NULL , V_20 ) ? 0 : - 1 ;
}
int F_70 ( const struct V_117 * V_20 ,
unsigned int V_123 )
{
int V_125 ;
if ( V_123 >= V_120 )
return - V_124 ;
V_125 = ( F_69 ( ( const struct V_117 * * )
& V_121 [ V_123 ] ,
V_20 , NULL ) == V_20 ) ? 0 : - 1 ;
F_71 () ;
return V_125 ;
}
int F_72 ( struct V_12 * V_13 ,
struct V_115 * V_126 )
{
int V_74 ;
memset ( & V_13 -> V_127 , 0 , sizeof( V_13 -> V_127 ) ) ;
V_74 = F_66 ( V_126 ) ;
if ( V_74 < 0 )
return V_74 ;
V_13 -> V_127 . type = V_126 -> type ;
V_13 -> V_127 . V_128 = V_126 -> V_128 ;
V_13 -> V_127 . V_129 = V_126 -> V_129 ;
V_13 -> V_127 . V_24 = V_126 -> V_24 ;
V_13 -> V_122 = V_74 ;
V_13 -> V_74 = V_13 -> V_122 + V_13 -> V_130 ;
return 0 ;
}
int V_115 ( struct V_88 * V_89 , struct V_12 * V_13 ,
T_5 * V_80 , struct V_63 * V_64 )
{
const struct V_117 * V_20 ;
int V_125 = - V_118 ;
if ( V_13 -> V_127 . type == V_119 )
return 0 ;
if ( V_13 -> V_127 . type >= V_120 )
return - V_118 ;
F_14 () ;
V_20 = F_15 ( V_121 [ V_13 -> V_127 . type ] ) ;
if ( F_67 ( V_20 && V_20 -> V_131 ) )
V_125 = V_20 -> V_131 ( V_89 , & V_13 -> V_127 , V_80 , V_64 ) ;
F_17 () ;
return V_125 ;
}
static int F_73 ( struct V_48 * V_40 , struct V_88 * V_89 ,
struct V_16 * V_79 , T_3 V_132 )
{
struct V_12 * V_52 = F_22 ( V_40 ) ;
int V_133 = V_89 -> V_112 - V_52 -> V_74 - V_40 -> V_84 ;
int V_76 ;
if ( V_132 )
V_76 = F_74 ( & V_79 -> V_9 ) - V_40 -> V_84
- sizeof( struct V_73 ) - V_52 -> V_74 ;
else
V_76 = F_75 ( V_89 ) ? F_74 ( F_75 ( V_89 ) ) : V_40 -> V_76 ;
if ( F_75 ( V_89 ) )
F_75 ( V_89 ) -> V_20 -> V_134 ( F_75 ( V_89 ) , NULL , V_89 , V_76 ) ;
if ( V_89 -> V_80 == F_76 ( V_135 ) ) {
if ( ! F_77 ( V_89 ) &&
( V_132 & F_76 ( V_136 ) ) && V_76 < V_133 ) {
memset ( F_78 ( V_89 ) , 0 , sizeof( * F_78 ( V_89 ) ) ) ;
F_79 ( V_89 , V_137 , V_138 , F_80 ( V_76 ) ) ;
return - V_56 ;
}
}
#if F_81 ( V_139 )
else if ( V_89 -> V_80 == F_76 ( V_140 ) ) {
struct V_141 * V_142 = (struct V_141 * ) F_75 ( V_89 ) ;
if ( V_142 && V_76 < F_74 ( F_75 ( V_89 ) ) &&
V_76 >= V_143 ) {
if ( ( V_52 -> V_37 . V_38 . V_39 &&
! F_21 ( V_52 -> V_37 . V_38 . V_39 ) ) ||
V_142 -> V_144 . V_145 == 128 ) {
V_142 -> V_146 |= V_147 ;
F_82 ( F_75 ( V_89 ) , V_148 , V_76 ) ;
}
}
if ( ! F_77 ( V_89 ) && V_76 >= V_143 &&
V_76 < V_133 ) {
F_83 ( V_89 , V_149 , 0 , V_76 ) ;
return - V_56 ;
}
}
#endif
return 0 ;
}
void F_84 ( struct V_88 * V_89 , struct V_48 * V_40 ,
const struct V_73 * V_150 , T_5 V_80 )
{
struct V_12 * V_52 = F_22 ( V_40 ) ;
const struct V_73 * V_151 ;
struct V_63 V_64 ;
T_5 V_66 , V_152 ;
T_3 V_132 ;
struct V_16 * V_79 ;
unsigned int V_153 ;
T_1 V_9 ;
int V_51 ;
bool V_154 ;
V_151 = ( const struct V_73 * ) F_85 ( V_89 ) ;
V_154 = ( V_52 -> V_37 . V_38 . V_39 != 0 ) ;
V_9 = V_150 -> V_39 ;
if ( V_9 == 0 ) {
if ( F_75 ( V_89 ) == NULL ) {
V_40 -> V_95 . V_155 ++ ;
goto V_156;
}
if ( V_89 -> V_80 == F_76 ( V_135 ) ) {
V_79 = F_86 ( V_89 ) ;
V_9 = F_87 ( V_79 , V_151 -> V_39 ) ;
}
#if F_81 ( V_139 )
else if ( V_89 -> V_80 == F_76 ( V_140 ) ) {
const struct V_157 * V_158 ;
struct V_159 * V_160 ;
bool V_161 ;
int V_162 ;
V_160 = F_88 ( F_75 ( V_89 ) ,
& F_89 ( V_89 ) -> V_39 ) ;
if ( V_160 == NULL )
goto V_156;
V_158 = ( const struct V_157 * ) & V_160 -> V_163 ;
V_162 = F_90 ( V_158 ) ;
if ( V_162 == V_164 ) {
V_158 = & F_89 ( V_89 ) -> V_39 ;
V_162 = F_90 ( V_158 ) ;
}
if ( ( V_162 & V_165 ) == 0 )
V_161 = true ;
else {
V_161 = false ;
V_9 = V_158 -> V_166 [ 3 ] ;
}
F_91 ( V_160 ) ;
if ( V_161 )
goto V_167;
}
#endif
else
goto V_156;
V_154 = false ;
}
V_66 = V_150 -> V_66 ;
if ( V_66 & 0x1 ) {
V_66 &= ~ 0x1 ;
if ( V_89 -> V_80 == F_76 ( V_135 ) ) {
V_66 = V_151 -> V_66 ;
V_154 = false ;
} else if ( V_89 -> V_80 == F_76 ( V_140 ) ) {
V_66 = F_92 ( ( const struct V_168 * ) V_151 ) ;
V_154 = false ;
}
}
F_37 ( & V_64 , V_80 , V_9 , V_150 -> V_10 ,
V_52 -> V_37 . V_81 , F_39 ( V_66 ) , V_52 -> V_37 . V_30 ) ;
if ( V_115 ( V_89 , V_52 , & V_80 , & V_64 ) < 0 )
goto V_156;
V_79 = V_154 ? F_13 ( V_52 , 0 , & V_64 . V_10 ) : NULL ;
if ( ! V_79 ) {
V_79 = F_40 ( V_52 -> V_49 , & V_64 ) ;
if ( F_41 ( V_79 ) ) {
V_40 -> V_95 . V_169 ++ ;
goto V_156;
}
if ( V_154 )
F_7 ( V_52 , & V_79 -> V_9 , V_64 . V_10 ) ;
}
if ( V_79 -> V_9 . V_40 == V_40 ) {
F_42 ( V_79 ) ;
V_40 -> V_95 . V_170 ++ ;
goto V_156;
}
if ( F_73 ( V_40 , V_89 , V_79 , V_150 -> V_171 ) ) {
F_42 ( V_79 ) ;
goto V_156;
}
if ( V_52 -> V_172 > 0 ) {
if ( F_93 ( V_173 ,
V_52 -> V_174 + V_175 ) ) {
V_52 -> V_172 -- ;
memset ( F_78 ( V_89 ) , 0 , sizeof( * F_78 ( V_89 ) ) ) ;
F_94 ( V_89 ) ;
} else
V_52 -> V_172 = 0 ;
}
V_66 = F_95 ( V_66 , V_151 , V_89 ) ;
V_152 = V_150 -> V_152 ;
if ( V_152 == 0 ) {
if ( V_89 -> V_80 == F_76 ( V_135 ) )
V_152 = V_151 -> V_152 ;
#if F_81 ( V_139 )
else if ( V_89 -> V_80 == F_76 ( V_140 ) )
V_152 = ( ( const struct V_168 * ) V_151 ) -> V_176 ;
#endif
else
V_152 = F_96 ( & V_79 -> V_9 ) ;
}
V_132 = V_150 -> V_171 ;
if ( V_89 -> V_80 == F_76 ( V_135 ) )
V_132 |= ( V_151 -> V_171 & F_76 ( V_136 ) ) ;
V_153 = F_97 ( V_79 -> V_9 . V_40 ) + sizeof( struct V_73 )
+ V_79 -> V_9 . V_177 + F_66 ( & V_52 -> V_127 ) ;
if ( V_153 > V_40 -> V_85 )
V_40 -> V_85 = V_153 ;
if ( F_98 ( V_89 , V_40 -> V_85 ) ) {
F_42 ( V_79 ) ;
V_40 -> V_95 . V_178 ++ ;
F_65 ( V_89 ) ;
return;
}
V_51 = F_99 ( V_89 -> V_179 , V_79 , V_89 , V_64 . V_10 , V_64 . V_39 , V_80 ,
V_66 , V_152 , V_132 , ! F_59 ( V_52 -> V_49 , F_60 ( V_40 ) ) ) ;
F_100 ( V_51 , & V_40 -> V_95 , V_40 -> V_94 ) ;
return;
#if F_81 ( V_139 )
V_167:
F_94 ( V_89 ) ;
#endif
V_156:
V_40 -> V_95 . V_180 ++ ;
F_65 ( V_89 ) ;
}
static void F_101 ( struct V_28 * V_29 ,
struct V_12 * V_13 ,
struct V_48 * V_40 ,
struct V_22 * V_23 ,
bool V_181 )
{
F_26 ( V_13 ) ;
V_13 -> V_37 . V_38 . V_10 = V_23 -> V_38 . V_10 ;
V_13 -> V_37 . V_38 . V_39 = V_23 -> V_38 . V_39 ;
V_13 -> V_37 . V_27 = V_23 -> V_27 ;
V_13 -> V_37 . V_81 = V_23 -> V_81 ;
if ( V_40 -> type != V_82 ) {
memcpy ( V_40 -> V_182 , & V_23 -> V_38 . V_10 , 4 ) ;
memcpy ( V_40 -> V_183 , & V_23 -> V_38 . V_39 , 4 ) ;
}
F_24 ( V_29 , V_13 ) ;
V_13 -> V_37 . V_38 . V_152 = V_23 -> V_38 . V_152 ;
V_13 -> V_37 . V_38 . V_66 = V_23 -> V_38 . V_66 ;
V_13 -> V_37 . V_38 . V_171 = V_23 -> V_38 . V_171 ;
if ( V_13 -> V_37 . V_30 != V_23 -> V_30 ) {
int V_76 ;
V_13 -> V_37 . V_30 = V_23 -> V_30 ;
V_76 = F_38 ( V_40 ) ;
if ( V_181 )
V_40 -> V_76 = V_76 ;
}
F_10 ( V_13 ) ;
F_102 ( V_40 ) ;
}
int F_103 ( struct V_48 * V_40 , struct V_22 * V_23 , int V_184 )
{
int V_51 = 0 ;
struct V_12 * V_13 = F_22 ( V_40 ) ;
struct V_49 * V_49 = V_13 -> V_49 ;
struct V_28 * V_29 = F_104 ( V_49 , V_13 -> V_185 ) ;
F_45 ( ! V_29 -> V_44 ) ;
switch ( V_184 ) {
case V_186 :
if ( V_40 == V_29 -> V_44 ) {
V_13 = F_28 ( V_29 , V_23 , V_29 -> V_44 -> type ) ;
if ( V_13 == NULL )
V_13 = F_22 ( V_40 ) ;
}
memcpy ( V_23 , & V_13 -> V_37 , sizeof( * V_23 ) ) ;
break;
case V_187 :
case V_188 :
V_51 = - V_189 ;
if ( ! F_105 ( V_49 -> V_190 , V_191 ) )
goto V_192;
if ( V_23 -> V_38 . V_152 )
V_23 -> V_38 . V_171 |= F_76 ( V_136 ) ;
if ( ! ( V_23 -> V_25 & V_46 ) ) {
if ( ! ( V_23 -> V_25 & V_26 ) )
V_23 -> V_27 = 0 ;
if ( ! ( V_23 -> V_193 & V_26 ) )
V_23 -> V_81 = 0 ;
}
V_13 = F_28 ( V_29 , V_23 , V_29 -> V_44 -> type ) ;
if ( V_184 == V_187 ) {
if ( ! V_13 ) {
V_13 = F_44 ( V_49 , V_29 , V_23 ) ;
V_51 = F_106 ( V_13 ) ;
break;
}
V_51 = - V_194 ;
break;
}
if ( V_40 != V_29 -> V_44 && V_184 == V_188 ) {
if ( V_13 != NULL ) {
if ( V_13 -> V_40 != V_40 ) {
V_51 = - V_194 ;
break;
}
} else {
unsigned int V_195 = 0 ;
if ( F_21 ( V_23 -> V_38 . V_39 ) )
V_195 = V_196 ;
else if ( V_23 -> V_38 . V_39 )
V_195 = V_83 ;
if ( ( V_40 -> V_24 ^ V_195 ) & ( V_83 | V_196 ) ) {
V_51 = - V_118 ;
break;
}
V_13 = F_22 ( V_40 ) ;
}
}
if ( V_13 ) {
V_51 = 0 ;
F_101 ( V_29 , V_13 , V_40 , V_23 , true ) ;
} else {
V_51 = - V_197 ;
}
break;
case V_198 :
V_51 = - V_189 ;
if ( ! F_105 ( V_49 -> V_190 , V_191 ) )
goto V_192;
if ( V_40 == V_29 -> V_44 ) {
V_51 = - V_197 ;
V_13 = F_28 ( V_29 , V_23 , V_29 -> V_44 -> type ) ;
if ( V_13 == NULL )
goto V_192;
V_51 = - V_189 ;
if ( V_13 == F_22 ( V_29 -> V_44 ) )
goto V_192;
V_40 = V_13 -> V_40 ;
}
F_107 ( V_40 ) ;
V_51 = 0 ;
break;
default:
V_51 = - V_118 ;
}
V_192:
return V_51 ;
}
int F_108 ( struct V_48 * V_40 , int V_199 )
{
struct V_12 * V_52 = F_22 ( V_40 ) ;
int V_78 = V_52 -> V_74 + sizeof( struct V_73 ) ;
if ( V_199 < 68 ||
V_199 > 0xFFF8 - V_40 -> V_84 - V_78 )
return - V_118 ;
V_40 -> V_76 = V_199 ;
return 0 ;
}
static void F_109 ( struct V_48 * V_40 )
{
struct V_12 * V_52 = F_22 ( V_40 ) ;
F_110 ( & V_52 -> V_114 ) ;
F_111 ( V_52 -> V_14 ) ;
F_111 ( V_40 -> V_94 ) ;
F_35 ( V_40 ) ;
}
void F_112 ( struct V_48 * V_40 , struct V_200 * V_35 )
{
struct V_12 * V_52 = F_22 ( V_40 ) ;
struct V_28 * V_29 ;
V_29 = F_104 ( V_52 -> V_49 , V_52 -> V_185 ) ;
if ( V_29 -> V_44 != V_40 ) {
F_26 ( F_22 ( V_40 ) ) ;
F_113 ( V_40 , V_35 ) ;
}
}
int F_114 ( struct V_49 * V_49 , int V_185 ,
struct V_50 * V_20 , char * V_201 )
{
struct V_28 * V_29 = F_104 ( V_49 , V_185 ) ;
struct V_22 V_37 ;
unsigned int V_15 ;
for ( V_15 = 0 ; V_15 < V_202 ; V_15 ++ )
F_115 ( & V_29 -> V_36 [ V_15 ] ) ;
if ( ! V_20 ) {
V_29 -> V_44 = NULL ;
return 0 ;
}
memset ( & V_37 , 0 , sizeof( V_37 ) ) ;
if ( V_201 )
F_30 ( V_37 . V_53 , V_201 , V_54 ) ;
F_116 () ;
V_29 -> V_44 = F_29 ( V_49 , V_20 , & V_37 ) ;
if ( ! F_41 ( V_29 -> V_44 ) ) {
V_29 -> V_44 -> V_203 |= V_204 ;
V_29 -> V_44 -> V_76 = F_38 ( V_29 -> V_44 ) ;
F_24 ( V_29 , F_22 ( V_29 -> V_44 ) ) ;
}
F_117 () ;
return F_106 ( V_29 -> V_44 ) ;
}
static void F_118 ( struct V_28 * V_29 , struct V_200 * V_35 ,
struct V_50 * V_20 )
{
struct V_49 * V_49 = F_60 ( V_29 -> V_44 ) ;
struct V_48 * V_40 , * V_205 ;
int V_45 ;
F_119 (net, dev, aux)
if ( V_40 -> V_50 == V_20 )
F_113 ( V_40 , V_35 ) ;
for ( V_45 = 0 ; V_45 < V_202 ; V_45 ++ ) {
struct V_12 * V_13 ;
struct V_206 * V_207 ;
struct V_34 * V_208 = & V_29 -> V_36 [ V_45 ] ;
F_120 (t, n, thead, hash_node)
if ( ! F_59 ( F_60 ( V_13 -> V_40 ) , V_49 ) )
F_113 ( V_13 -> V_40 , V_35 ) ;
}
}
void F_121 ( struct V_28 * V_29 , struct V_50 * V_20 )
{
F_122 ( V_209 ) ;
F_116 () ;
F_118 ( V_29 , & V_209 , V_20 ) ;
F_123 ( & V_209 ) ;
F_117 () ;
}
int F_124 ( struct V_48 * V_40 , struct V_210 * V_211 [] ,
struct V_22 * V_23 )
{
struct V_12 * V_87 ;
struct V_49 * V_49 = F_60 ( V_40 ) ;
struct V_28 * V_29 ;
int V_76 ;
int V_51 ;
V_87 = F_22 ( V_40 ) ;
V_29 = F_104 ( V_49 , V_87 -> V_185 ) ;
if ( F_28 ( V_29 , V_23 , V_40 -> type ) )
return - V_194 ;
V_87 -> V_49 = V_49 ;
V_87 -> V_37 = * V_23 ;
V_51 = F_34 ( V_40 ) ;
if ( V_51 )
goto V_212;
if ( V_40 -> type == V_82 && ! V_211 [ V_213 ] )
F_125 ( V_40 ) ;
V_76 = F_38 ( V_40 ) ;
if ( ! V_211 [ V_214 ] )
V_40 -> V_76 = V_76 ;
F_24 ( V_29 , V_87 ) ;
V_212:
return V_51 ;
}
int F_126 ( struct V_48 * V_40 , struct V_210 * V_211 [] ,
struct V_22 * V_23 )
{
struct V_12 * V_13 ;
struct V_12 * V_52 = F_22 ( V_40 ) ;
struct V_49 * V_49 = V_52 -> V_49 ;
struct V_28 * V_29 = F_104 ( V_49 , V_52 -> V_185 ) ;
if ( V_40 == V_29 -> V_44 )
return - V_118 ;
V_13 = F_28 ( V_29 , V_23 , V_40 -> type ) ;
if ( V_13 ) {
if ( V_13 -> V_40 != V_40 )
return - V_194 ;
} else {
V_13 = V_52 ;
if ( V_40 -> type != V_82 ) {
unsigned int V_195 = 0 ;
if ( F_21 ( V_23 -> V_38 . V_39 ) )
V_195 = V_196 ;
else if ( V_23 -> V_38 . V_39 )
V_195 = V_83 ;
if ( ( V_40 -> V_24 ^ V_195 ) &
( V_83 | V_196 ) )
return - V_118 ;
}
}
F_101 ( V_29 , V_13 , V_40 , V_23 , ! V_211 [ V_214 ] ) ;
return 0 ;
}
int F_127 ( struct V_48 * V_40 )
{
struct V_12 * V_52 = F_22 ( V_40 ) ;
struct V_73 * V_38 = & V_52 -> V_37 . V_38 ;
int V_51 ;
V_40 -> V_215 = F_109 ;
V_40 -> V_94 = F_128 ( struct V_93 ) ;
if ( ! V_40 -> V_94 )
return - V_61 ;
V_52 -> V_14 = F_129 ( struct V_6 ) ;
if ( ! V_52 -> V_14 ) {
F_111 ( V_40 -> V_94 ) ;
return - V_61 ;
}
V_51 = F_130 ( & V_52 -> V_114 , V_40 ) ;
if ( V_51 ) {
F_111 ( V_52 -> V_14 ) ;
F_111 ( V_40 -> V_94 ) ;
return V_51 ;
}
V_52 -> V_40 = V_40 ;
V_52 -> V_49 = F_60 ( V_40 ) ;
strcpy ( V_52 -> V_37 . V_53 , V_40 -> V_53 ) ;
V_38 -> V_216 = 4 ;
V_38 -> V_217 = 5 ;
return 0 ;
}
void F_131 ( struct V_48 * V_40 )
{
struct V_12 * V_52 = F_22 ( V_40 ) ;
struct V_49 * V_49 = V_52 -> V_49 ;
struct V_28 * V_29 ;
V_29 = F_104 ( V_49 , V_52 -> V_185 ) ;
if ( V_29 -> V_44 != V_40 )
F_26 ( F_22 ( V_40 ) ) ;
F_10 ( V_52 ) ;
}
void F_132 ( struct V_48 * V_40 , int V_218 )
{
struct V_12 * V_52 = F_22 ( V_40 ) ;
V_52 -> V_185 = V_218 ;
}
