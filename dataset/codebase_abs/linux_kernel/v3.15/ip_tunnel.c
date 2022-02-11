static unsigned int F_1 ( T_1 V_1 , T_1 V_2 )
{
return F_2 ( ( V_3 V_4 ) V_1 ^ ( V_3 V_4 ) V_2 ,
V_5 ) ;
}
static void F_3 ( struct V_6 * V_7 ,
struct V_8 * V_9 )
{
struct V_8 * V_10 ;
if ( V_9 ) {
if ( V_9 -> V_11 & V_12 )
V_9 = NULL ;
else
F_4 ( V_9 ) ;
}
V_10 = F_5 ( ( V_3 struct V_8 * * ) & V_7 -> V_9 , V_9 ) ;
F_6 ( V_10 ) ;
}
static void F_7 ( struct V_13 * V_14 , struct V_8 * V_9 )
{
F_3 ( F_8 ( V_14 -> V_15 ) , V_9 ) ;
}
static void F_9 ( struct V_13 * V_14 )
{
F_7 ( V_14 , NULL ) ;
}
void F_10 ( struct V_13 * V_14 )
{
int V_16 ;
F_11 (i)
F_3 ( F_12 ( V_14 -> V_15 , V_16 ) , NULL ) ;
}
static struct V_17 * F_13 ( struct V_13 * V_14 , V_4 V_18 )
{
struct V_8 * V_9 ;
F_14 () ;
V_9 = F_15 ( F_8 ( V_14 -> V_15 ) -> V_9 ) ;
if ( V_9 ) {
if ( V_9 -> V_19 && V_9 -> V_20 -> V_21 ( V_9 , V_18 ) == NULL ) {
F_16 () ;
F_9 ( V_14 ) ;
return NULL ;
}
F_17 ( V_9 ) ;
}
F_16 () ;
return (struct V_17 * ) V_9 ;
}
static bool F_18 ( const struct V_22 * V_23 ,
T_2 V_11 , T_1 V_1 )
{
if ( V_23 -> V_24 & V_25 ) {
if ( V_11 & V_25 )
return V_1 == V_23 -> V_26 ;
else
return false ;
} else
return ! ( V_11 & V_25 ) ;
}
struct V_13 * F_19 ( struct V_27 * V_28 ,
int V_29 , T_2 V_11 ,
T_1 V_2 , T_1 V_30 ,
T_1 V_1 )
{
unsigned int V_31 ;
struct V_13 * V_14 , * V_32 = NULL ;
struct V_33 * V_34 ;
V_31 = F_1 ( V_1 , V_2 ) ;
V_34 = & V_28 -> V_35 [ V_31 ] ;
F_20 (t, head, hash_node) {
if ( V_30 != V_14 -> V_36 . V_37 . V_38 ||
V_2 != V_14 -> V_36 . V_37 . V_39 ||
! ( V_14 -> V_40 -> V_11 & V_41 ) )
continue;
if ( ! F_18 ( & V_14 -> V_36 , V_11 , V_1 ) )
continue;
if ( V_14 -> V_36 . V_29 == V_29 )
return V_14 ;
else
V_32 = V_14 ;
}
F_20 (t, head, hash_node) {
if ( V_2 != V_14 -> V_36 . V_37 . V_39 ||
! ( V_14 -> V_40 -> V_11 & V_41 ) )
continue;
if ( ! F_18 ( & V_14 -> V_36 , V_11 , V_1 ) )
continue;
if ( V_14 -> V_36 . V_29 == V_29 )
return V_14 ;
else if ( ! V_32 )
V_32 = V_14 ;
}
V_31 = F_1 ( V_1 , 0 ) ;
V_34 = & V_28 -> V_35 [ V_31 ] ;
F_20 (t, head, hash_node) {
if ( ( V_30 != V_14 -> V_36 . V_37 . V_38 &&
( V_30 != V_14 -> V_36 . V_37 . V_39 ||
! F_21 ( V_30 ) ) ) ||
! ( V_14 -> V_40 -> V_11 & V_41 ) )
continue;
if ( ! F_18 ( & V_14 -> V_36 , V_11 , V_1 ) )
continue;
if ( V_14 -> V_36 . V_29 == V_29 )
return V_14 ;
else if ( ! V_32 )
V_32 = V_14 ;
}
if ( V_11 & V_42 )
goto V_43;
F_20 (t, head, hash_node) {
if ( V_14 -> V_36 . V_26 != V_1 ||
! ( V_14 -> V_40 -> V_11 & V_41 ) )
continue;
if ( V_14 -> V_36 . V_29 == V_29 )
return V_14 ;
else if ( ! V_32 )
V_32 = V_14 ;
}
V_43:
if ( V_32 )
return V_32 ;
if ( V_28 -> V_44 && V_28 -> V_44 -> V_11 & V_41 )
return F_22 ( V_28 -> V_44 ) ;
return NULL ;
}
static struct V_33 * F_23 ( struct V_27 * V_28 ,
struct V_22 * V_36 )
{
unsigned int V_45 ;
T_1 V_2 ;
T_1 V_26 = V_36 -> V_26 ;
if ( V_36 -> V_37 . V_39 && ! F_21 ( V_36 -> V_37 . V_39 ) )
V_2 = V_36 -> V_37 . V_39 ;
else
V_2 = 0 ;
if ( ! ( V_36 -> V_24 & V_25 ) && ( V_36 -> V_24 & V_46 ) )
V_26 = 0 ;
V_45 = F_1 ( V_26 , V_2 ) ;
return & V_28 -> V_35 [ V_45 ] ;
}
static void F_24 ( struct V_27 * V_28 , struct V_13 * V_14 )
{
struct V_33 * V_34 = F_23 ( V_28 , & V_14 -> V_36 ) ;
F_25 ( & V_14 -> V_47 , V_34 ) ;
}
static void F_26 ( struct V_13 * V_14 )
{
F_27 ( & V_14 -> V_47 ) ;
}
static struct V_13 * F_28 ( struct V_27 * V_28 ,
struct V_22 * V_36 ,
int type )
{
T_1 V_2 = V_36 -> V_37 . V_39 ;
T_1 V_30 = V_36 -> V_37 . V_38 ;
T_1 V_1 = V_36 -> V_26 ;
int V_29 = V_36 -> V_29 ;
struct V_13 * V_14 = NULL ;
struct V_33 * V_34 = F_23 ( V_28 , V_36 ) ;
F_20 (t, head, hash_node) {
if ( V_30 == V_14 -> V_36 . V_37 . V_38 &&
V_2 == V_14 -> V_36 . V_37 . V_39 &&
V_1 == V_14 -> V_36 . V_26 &&
V_29 == V_14 -> V_36 . V_29 &&
type == V_14 -> V_40 -> type )
break;
}
return V_14 ;
}
static struct V_48 * F_29 ( struct V_49 * V_49 ,
const struct V_50 * V_20 ,
struct V_22 * V_36 )
{
int V_51 ;
struct V_13 * V_52 ;
struct V_48 * V_40 ;
char V_53 [ V_54 ] ;
if ( V_36 -> V_53 [ 0 ] )
F_30 ( V_53 , V_36 -> V_53 , V_54 ) ;
else {
if ( strlen ( V_20 -> V_55 ) > ( V_54 - 3 ) ) {
V_51 = - V_56 ;
goto V_57;
}
F_30 ( V_53 , V_20 -> V_55 , V_54 ) ;
strncat ( V_53 , L_1 , 2 ) ;
}
F_31 () ;
V_40 = F_32 ( V_20 -> V_58 , V_53 , V_20 -> V_59 ) ;
if ( ! V_40 ) {
V_51 = - V_60 ;
goto V_57;
}
F_33 ( V_40 , V_49 ) ;
V_40 -> V_50 = V_20 ;
V_52 = F_22 ( V_40 ) ;
V_52 -> V_36 = * V_36 ;
V_52 -> V_49 = V_49 ;
V_51 = F_34 ( V_40 ) ;
if ( V_51 )
goto V_61;
return V_40 ;
V_61:
F_35 ( V_40 ) ;
V_57:
return F_36 ( V_51 ) ;
}
static inline void F_37 ( struct V_62 * V_63 ,
int V_64 ,
T_1 V_39 , T_1 V_38 ,
T_1 V_1 , T_3 V_65 , int V_66 )
{
memset ( V_63 , 0 , sizeof( * V_63 ) ) ;
V_63 -> V_67 = V_66 ;
V_63 -> V_39 = V_39 ;
V_63 -> V_38 = V_38 ;
V_63 -> V_68 = V_65 ;
V_63 -> V_69 = V_64 ;
V_63 -> V_70 = V_1 ;
}
static int F_38 ( struct V_48 * V_40 )
{
struct V_48 * V_71 = NULL ;
struct V_13 * V_52 = F_22 ( V_40 ) ;
const struct V_72 * V_37 ;
int V_73 = V_74 ;
int V_75 = V_76 ;
int V_77 = V_52 -> V_73 + sizeof( struct V_72 ) ;
V_37 = & V_52 -> V_36 . V_37 ;
if ( V_37 -> V_39 ) {
struct V_62 V_63 ;
struct V_17 * V_78 ;
F_37 ( & V_63 , V_37 -> V_79 , V_37 -> V_39 ,
V_37 -> V_38 , V_52 -> V_36 . V_80 ,
F_39 ( V_37 -> V_65 ) , V_52 -> V_36 . V_29 ) ;
V_78 = F_40 ( V_52 -> V_49 , & V_63 ) ;
if ( ! F_41 ( V_78 ) ) {
V_71 = V_78 -> V_9 . V_40 ;
F_7 ( V_52 , & V_78 -> V_9 ) ;
F_42 ( V_78 ) ;
}
if ( V_40 -> type != V_81 )
V_40 -> V_11 |= V_82 ;
}
if ( ! V_71 && V_52 -> V_36 . V_29 )
V_71 = F_43 ( V_52 -> V_49 , V_52 -> V_36 . V_29 ) ;
if ( V_71 ) {
V_73 = V_71 -> V_83 + V_71 -> V_84 ;
V_75 = V_71 -> V_75 ;
}
V_40 -> V_85 = V_52 -> V_36 . V_29 ;
V_40 -> V_84 = V_77 + V_73 ;
V_75 -= ( V_40 -> V_83 + V_77 ) ;
if ( V_75 < 68 )
V_75 = 68 ;
return V_75 ;
}
static struct V_13 * F_44 ( struct V_49 * V_49 ,
struct V_27 * V_28 ,
struct V_22 * V_36 )
{
struct V_13 * V_86 , * V_87 ;
struct V_48 * V_40 ;
F_45 ( ! V_28 -> V_44 ) ;
V_87 = F_22 ( V_28 -> V_44 ) ;
V_40 = F_29 ( V_49 , V_28 -> V_44 -> V_50 , V_36 ) ;
if ( F_41 ( V_40 ) )
return F_46 ( V_40 ) ;
V_40 -> V_75 = F_38 ( V_40 ) ;
V_86 = F_22 ( V_40 ) ;
F_24 ( V_28 , V_86 ) ;
return V_86 ;
}
int F_47 ( struct V_13 * V_52 , struct V_88 * V_89 ,
const struct V_90 * V_91 , bool V_92 )
{
struct V_93 * V_94 ;
const struct V_72 * V_37 = F_48 ( V_89 ) ;
int V_51 ;
#ifdef F_49
if ( F_21 ( V_37 -> V_39 ) ) {
V_52 -> V_40 -> V_95 . V_96 ++ ;
V_89 -> V_97 = V_98 ;
}
#endif
if ( ( ! ( V_91 -> V_11 & V_99 ) && ( V_52 -> V_36 . V_24 & V_99 ) ) ||
( ( V_91 -> V_11 & V_99 ) && ! ( V_52 -> V_36 . V_24 & V_99 ) ) ) {
V_52 -> V_40 -> V_95 . V_100 ++ ;
V_52 -> V_40 -> V_95 . V_101 ++ ;
goto V_102;
}
if ( V_52 -> V_36 . V_24 & V_103 ) {
if ( ! ( V_91 -> V_11 & V_103 ) ||
( V_52 -> V_104 && ( V_105 ) ( F_50 ( V_91 -> V_106 ) - V_52 -> V_104 ) < 0 ) ) {
V_52 -> V_40 -> V_95 . V_107 ++ ;
V_52 -> V_40 -> V_95 . V_101 ++ ;
goto V_102;
}
V_52 -> V_104 = F_50 ( V_91 -> V_106 ) + 1 ;
}
F_51 ( V_89 ) ;
V_51 = F_52 ( V_37 , V_89 ) ;
if ( F_53 ( V_51 ) ) {
if ( V_92 )
F_54 ( L_2 ,
& V_37 -> V_38 , V_37 -> V_65 ) ;
if ( V_51 > 1 ) {
++ V_52 -> V_40 -> V_95 . V_108 ;
++ V_52 -> V_40 -> V_95 . V_101 ;
goto V_102;
}
}
V_94 = F_8 ( V_52 -> V_40 -> V_94 ) ;
F_55 ( & V_94 -> V_109 ) ;
V_94 -> V_110 ++ ;
V_94 -> V_111 += V_89 -> V_112 ;
F_56 ( & V_94 -> V_109 ) ;
F_57 ( V_89 , ! F_58 ( V_52 -> V_49 , F_59 ( V_52 -> V_40 ) ) ) ;
if ( V_52 -> V_40 -> type == V_81 ) {
V_89 -> V_79 = F_60 ( V_89 , V_52 -> V_40 ) ;
F_61 ( V_89 , F_62 ( V_89 ) , V_113 ) ;
} else {
V_89 -> V_40 = V_52 -> V_40 ;
}
F_63 ( & V_52 -> V_114 , V_89 ) ;
return 0 ;
V_102:
F_64 ( V_89 ) ;
return 0 ;
}
static int F_65 ( struct V_48 * V_40 , struct V_88 * V_89 ,
struct V_17 * V_78 , T_2 V_115 )
{
struct V_13 * V_52 = F_22 ( V_40 ) ;
int V_116 = V_89 -> V_112 - V_52 -> V_73 - V_40 -> V_83 ;
int V_75 ;
if ( V_115 )
V_75 = F_66 ( & V_78 -> V_9 ) - V_40 -> V_83
- sizeof( struct V_72 ) - V_52 -> V_73 ;
else
V_75 = F_67 ( V_89 ) ? F_66 ( F_67 ( V_89 ) ) : V_40 -> V_75 ;
if ( F_67 ( V_89 ) )
F_67 ( V_89 ) -> V_20 -> V_117 ( F_67 ( V_89 ) , NULL , V_89 , V_75 ) ;
if ( V_89 -> V_79 == F_68 ( V_118 ) ) {
if ( ! F_69 ( V_89 ) &&
( V_115 & F_68 ( V_119 ) ) && V_75 < V_116 ) {
memset ( F_70 ( V_89 ) , 0 , sizeof( * F_70 ( V_89 ) ) ) ;
F_71 ( V_89 , V_120 , V_121 , F_72 ( V_75 ) ) ;
return - V_56 ;
}
}
#if F_73 ( V_122 )
else if ( V_89 -> V_79 == F_68 ( V_123 ) ) {
struct V_124 * V_125 = (struct V_124 * ) F_67 ( V_89 ) ;
if ( V_125 && V_75 < F_66 ( F_67 ( V_89 ) ) &&
V_75 >= V_126 ) {
if ( ( V_52 -> V_36 . V_37 . V_39 &&
! F_21 ( V_52 -> V_36 . V_37 . V_39 ) ) ||
V_125 -> V_127 . V_128 == 128 ) {
V_125 -> V_129 |= V_130 ;
F_74 ( F_67 ( V_89 ) , V_131 , V_75 ) ;
}
}
if ( ! F_69 ( V_89 ) && V_75 >= V_126 &&
V_75 < V_116 ) {
F_75 ( V_89 , V_132 , 0 , V_75 ) ;
return - V_56 ;
}
}
#endif
return 0 ;
}
void F_76 ( struct V_88 * V_89 , struct V_48 * V_40 ,
const struct V_72 * V_133 , const T_4 V_79 )
{
struct V_13 * V_52 = F_22 ( V_40 ) ;
const struct V_72 * V_134 ;
struct V_62 V_63 ;
T_4 V_65 , V_135 ;
T_2 V_115 ;
struct V_17 * V_78 ;
unsigned int V_136 ;
T_1 V_9 ;
int V_51 ;
bool V_137 ;
V_134 = ( const struct V_72 * ) F_77 ( V_89 ) ;
V_137 = ( V_52 -> V_36 . V_37 . V_39 != 0 ) ;
V_9 = V_133 -> V_39 ;
if ( V_9 == 0 ) {
if ( F_67 ( V_89 ) == NULL ) {
V_40 -> V_95 . V_138 ++ ;
goto V_139;
}
if ( V_89 -> V_79 == F_68 ( V_118 ) ) {
V_78 = F_78 ( V_89 ) ;
V_9 = F_79 ( V_78 , V_134 -> V_39 ) ;
}
#if F_73 ( V_122 )
else if ( V_89 -> V_79 == F_68 ( V_123 ) ) {
const struct V_140 * V_141 ;
struct V_142 * V_143 ;
bool V_144 ;
int V_145 ;
V_143 = F_80 ( F_67 ( V_89 ) ,
& F_81 ( V_89 ) -> V_39 ) ;
if ( V_143 == NULL )
goto V_139;
V_141 = ( const struct V_140 * ) & V_143 -> V_146 ;
V_145 = F_82 ( V_141 ) ;
if ( V_145 == V_147 ) {
V_141 = & F_81 ( V_89 ) -> V_39 ;
V_145 = F_82 ( V_141 ) ;
}
if ( ( V_145 & V_148 ) == 0 )
V_144 = true ;
else {
V_144 = false ;
V_9 = V_141 -> V_149 [ 3 ] ;
}
F_83 ( V_143 ) ;
if ( V_144 )
goto V_150;
}
#endif
else
goto V_139;
V_137 = false ;
}
V_65 = V_133 -> V_65 ;
if ( V_65 & 0x1 ) {
V_65 &= ~ 0x1 ;
if ( V_89 -> V_79 == F_68 ( V_118 ) ) {
V_65 = V_134 -> V_65 ;
V_137 = false ;
} else if ( V_89 -> V_79 == F_68 ( V_123 ) ) {
V_65 = F_84 ( ( const struct V_151 * ) V_134 ) ;
V_137 = false ;
}
}
F_37 ( & V_63 , V_79 , V_9 , V_133 -> V_38 ,
V_52 -> V_36 . V_80 , F_39 ( V_65 ) , V_52 -> V_36 . V_29 ) ;
V_78 = V_137 ? F_13 ( V_52 , 0 ) : NULL ;
if ( ! V_78 ) {
V_78 = F_40 ( V_52 -> V_49 , & V_63 ) ;
if ( F_41 ( V_78 ) ) {
V_40 -> V_95 . V_152 ++ ;
goto V_139;
}
if ( V_137 )
F_7 ( V_52 , & V_78 -> V_9 ) ;
}
if ( V_78 -> V_9 . V_40 == V_40 ) {
F_42 ( V_78 ) ;
V_40 -> V_95 . V_153 ++ ;
goto V_139;
}
if ( F_65 ( V_40 , V_89 , V_78 , V_133 -> V_154 ) ) {
F_42 ( V_78 ) ;
goto V_139;
}
if ( V_52 -> V_155 > 0 ) {
if ( F_85 ( V_156 ,
V_52 -> V_157 + V_158 ) ) {
V_52 -> V_155 -- ;
memset ( F_70 ( V_89 ) , 0 , sizeof( * F_70 ( V_89 ) ) ) ;
F_86 ( V_89 ) ;
} else
V_52 -> V_155 = 0 ;
}
V_65 = F_87 ( V_65 , V_134 , V_89 ) ;
V_135 = V_133 -> V_135 ;
if ( V_135 == 0 ) {
if ( V_89 -> V_79 == F_68 ( V_118 ) )
V_135 = V_134 -> V_135 ;
#if F_73 ( V_122 )
else if ( V_89 -> V_79 == F_68 ( V_123 ) )
V_135 = ( ( const struct V_151 * ) V_134 ) -> V_159 ;
#endif
else
V_135 = F_88 ( & V_78 -> V_9 ) ;
}
V_115 = V_133 -> V_154 ;
if ( V_89 -> V_79 == F_68 ( V_118 ) )
V_115 |= ( V_134 -> V_154 & F_68 ( V_119 ) ) ;
V_136 = F_89 ( V_78 -> V_9 . V_40 ) + sizeof( struct V_72 )
+ V_78 -> V_9 . V_160 ;
if ( V_136 > V_40 -> V_84 )
V_40 -> V_84 = V_136 ;
if ( F_90 ( V_89 , V_40 -> V_84 ) ) {
V_40 -> V_95 . V_161 ++ ;
F_64 ( V_89 ) ;
return;
}
V_51 = F_91 ( V_89 -> V_162 , V_78 , V_89 , V_63 . V_38 , V_63 . V_39 , V_79 ,
V_65 , V_135 , V_115 , ! F_58 ( V_52 -> V_49 , F_59 ( V_40 ) ) ) ;
F_92 ( V_51 , & V_40 -> V_95 , V_40 -> V_94 ) ;
return;
#if F_73 ( V_122 )
V_150:
F_86 ( V_89 ) ;
#endif
V_139:
V_40 -> V_95 . V_163 ++ ;
F_64 ( V_89 ) ;
}
static void F_93 ( struct V_27 * V_28 ,
struct V_13 * V_14 ,
struct V_48 * V_40 ,
struct V_22 * V_23 ,
bool V_164 )
{
F_26 ( V_14 ) ;
V_14 -> V_36 . V_37 . V_38 = V_23 -> V_37 . V_38 ;
V_14 -> V_36 . V_37 . V_39 = V_23 -> V_37 . V_39 ;
V_14 -> V_36 . V_26 = V_23 -> V_26 ;
V_14 -> V_36 . V_80 = V_23 -> V_80 ;
if ( V_40 -> type != V_81 ) {
memcpy ( V_40 -> V_165 , & V_23 -> V_37 . V_38 , 4 ) ;
memcpy ( V_40 -> V_166 , & V_23 -> V_37 . V_39 , 4 ) ;
}
F_24 ( V_28 , V_14 ) ;
V_14 -> V_36 . V_37 . V_135 = V_23 -> V_37 . V_135 ;
V_14 -> V_36 . V_37 . V_65 = V_23 -> V_37 . V_65 ;
V_14 -> V_36 . V_37 . V_154 = V_23 -> V_37 . V_154 ;
if ( V_14 -> V_36 . V_29 != V_23 -> V_29 ) {
int V_75 ;
V_14 -> V_36 . V_29 = V_23 -> V_29 ;
V_75 = F_38 ( V_40 ) ;
if ( V_164 )
V_40 -> V_75 = V_75 ;
}
F_10 ( V_14 ) ;
F_94 ( V_40 ) ;
}
int F_95 ( struct V_48 * V_40 , struct V_22 * V_23 , int V_167 )
{
int V_51 = 0 ;
struct V_13 * V_14 = F_22 ( V_40 ) ;
struct V_49 * V_49 = V_14 -> V_49 ;
struct V_27 * V_28 = F_96 ( V_49 , V_14 -> V_168 ) ;
F_45 ( ! V_28 -> V_44 ) ;
switch ( V_167 ) {
case V_169 :
if ( V_40 == V_28 -> V_44 ) {
V_14 = F_28 ( V_28 , V_23 , V_28 -> V_44 -> type ) ;
if ( V_14 == NULL )
V_14 = F_22 ( V_40 ) ;
}
memcpy ( V_23 , & V_14 -> V_36 , sizeof( * V_23 ) ) ;
break;
case V_170 :
case V_171 :
V_51 = - V_172 ;
if ( ! F_97 ( V_49 -> V_173 , V_174 ) )
goto V_175;
if ( V_23 -> V_37 . V_135 )
V_23 -> V_37 . V_154 |= F_68 ( V_119 ) ;
if ( ! ( V_23 -> V_24 & V_25 ) )
V_23 -> V_26 = 0 ;
if ( ! ( V_23 -> V_176 & V_25 ) )
V_23 -> V_80 = 0 ;
V_14 = F_28 ( V_28 , V_23 , V_28 -> V_44 -> type ) ;
if ( ! V_14 && ( V_167 == V_170 ) ) {
V_14 = F_44 ( V_49 , V_28 , V_23 ) ;
if ( F_41 ( V_14 ) ) {
V_51 = F_98 ( V_14 ) ;
break;
}
}
if ( V_40 != V_28 -> V_44 && V_167 == V_171 ) {
if ( V_14 != NULL ) {
if ( V_14 -> V_40 != V_40 ) {
V_51 = - V_177 ;
break;
}
} else {
unsigned int V_178 = 0 ;
if ( F_21 ( V_23 -> V_37 . V_39 ) )
V_178 = V_179 ;
else if ( V_23 -> V_37 . V_39 )
V_178 = V_82 ;
if ( ( V_40 -> V_11 ^ V_178 ) & ( V_82 | V_179 ) ) {
V_51 = - V_180 ;
break;
}
V_14 = F_22 ( V_40 ) ;
}
}
if ( V_14 ) {
V_51 = 0 ;
F_93 ( V_28 , V_14 , V_40 , V_23 , true ) ;
} else {
V_51 = - V_181 ;
}
break;
case V_182 :
V_51 = - V_172 ;
if ( ! F_97 ( V_49 -> V_173 , V_174 ) )
goto V_175;
if ( V_40 == V_28 -> V_44 ) {
V_51 = - V_181 ;
V_14 = F_28 ( V_28 , V_23 , V_28 -> V_44 -> type ) ;
if ( V_14 == NULL )
goto V_175;
V_51 = - V_172 ;
if ( V_14 == F_22 ( V_28 -> V_44 ) )
goto V_175;
V_40 = V_14 -> V_40 ;
}
F_99 ( V_40 ) ;
V_51 = 0 ;
break;
default:
V_51 = - V_180 ;
}
V_175:
return V_51 ;
}
int F_100 ( struct V_48 * V_40 , int V_183 )
{
struct V_13 * V_52 = F_22 ( V_40 ) ;
int V_77 = V_52 -> V_73 + sizeof( struct V_72 ) ;
if ( V_183 < 68 ||
V_183 > 0xFFF8 - V_40 -> V_83 - V_77 )
return - V_180 ;
V_40 -> V_75 = V_183 ;
return 0 ;
}
static void F_101 ( struct V_48 * V_40 )
{
struct V_13 * V_52 = F_22 ( V_40 ) ;
F_102 ( & V_52 -> V_114 ) ;
F_103 ( V_52 -> V_15 ) ;
F_103 ( V_40 -> V_94 ) ;
F_35 ( V_40 ) ;
}
void F_104 ( struct V_48 * V_40 , struct V_184 * V_34 )
{
struct V_13 * V_52 = F_22 ( V_40 ) ;
struct V_27 * V_28 ;
V_28 = F_96 ( V_52 -> V_49 , V_52 -> V_168 ) ;
if ( V_28 -> V_44 != V_40 ) {
F_26 ( F_22 ( V_40 ) ) ;
F_105 ( V_40 , V_34 ) ;
}
}
int F_106 ( struct V_49 * V_49 , int V_168 ,
struct V_50 * V_20 , char * V_185 )
{
struct V_27 * V_28 = F_96 ( V_49 , V_168 ) ;
struct V_22 V_36 ;
unsigned int V_16 ;
for ( V_16 = 0 ; V_16 < V_186 ; V_16 ++ )
F_107 ( & V_28 -> V_35 [ V_16 ] ) ;
if ( ! V_20 ) {
V_28 -> V_44 = NULL ;
return 0 ;
}
memset ( & V_36 , 0 , sizeof( V_36 ) ) ;
if ( V_185 )
F_30 ( V_36 . V_53 , V_185 , V_54 ) ;
F_108 () ;
V_28 -> V_44 = F_29 ( V_49 , V_20 , & V_36 ) ;
if ( ! F_41 ( V_28 -> V_44 ) ) {
V_28 -> V_44 -> V_187 |= V_188 ;
V_28 -> V_44 -> V_75 = F_38 ( V_28 -> V_44 ) ;
F_24 ( V_28 , F_22 ( V_28 -> V_44 ) ) ;
}
F_109 () ;
return F_110 ( V_28 -> V_44 ) ;
}
static void F_111 ( struct V_27 * V_28 , struct V_184 * V_34 ,
struct V_50 * V_20 )
{
struct V_49 * V_49 = F_59 ( V_28 -> V_44 ) ;
struct V_48 * V_40 , * V_189 ;
int V_45 ;
F_112 (net, dev, aux)
if ( V_40 -> V_50 == V_20 )
F_105 ( V_40 , V_34 ) ;
for ( V_45 = 0 ; V_45 < V_186 ; V_45 ++ ) {
struct V_13 * V_14 ;
struct V_190 * V_191 ;
struct V_33 * V_192 = & V_28 -> V_35 [ V_45 ] ;
F_113 (t, n, thead, hash_node)
if ( ! F_58 ( F_59 ( V_14 -> V_40 ) , V_49 ) )
F_105 ( V_14 -> V_40 , V_34 ) ;
}
}
void F_114 ( struct V_27 * V_28 , struct V_50 * V_20 )
{
F_115 ( V_193 ) ;
F_108 () ;
F_111 ( V_28 , & V_193 , V_20 ) ;
F_116 ( & V_193 ) ;
F_109 () ;
}
int F_117 ( struct V_48 * V_40 , struct V_194 * V_195 [] ,
struct V_22 * V_23 )
{
struct V_13 * V_86 ;
struct V_49 * V_49 = F_59 ( V_40 ) ;
struct V_27 * V_28 ;
int V_75 ;
int V_51 ;
V_86 = F_22 ( V_40 ) ;
V_28 = F_96 ( V_49 , V_86 -> V_168 ) ;
if ( F_28 ( V_28 , V_23 , V_40 -> type ) )
return - V_177 ;
V_86 -> V_49 = V_49 ;
V_86 -> V_36 = * V_23 ;
V_51 = F_34 ( V_40 ) ;
if ( V_51 )
goto V_196;
if ( V_40 -> type == V_81 && ! V_195 [ V_197 ] )
F_118 ( V_40 ) ;
V_75 = F_38 ( V_40 ) ;
if ( ! V_195 [ V_198 ] )
V_40 -> V_75 = V_75 ;
F_24 ( V_28 , V_86 ) ;
V_196:
return V_51 ;
}
int F_119 ( struct V_48 * V_40 , struct V_194 * V_195 [] ,
struct V_22 * V_23 )
{
struct V_13 * V_14 ;
struct V_13 * V_52 = F_22 ( V_40 ) ;
struct V_49 * V_49 = V_52 -> V_49 ;
struct V_27 * V_28 = F_96 ( V_49 , V_52 -> V_168 ) ;
if ( V_40 == V_28 -> V_44 )
return - V_180 ;
V_14 = F_28 ( V_28 , V_23 , V_40 -> type ) ;
if ( V_14 ) {
if ( V_14 -> V_40 != V_40 )
return - V_177 ;
} else {
V_14 = V_52 ;
if ( V_40 -> type != V_81 ) {
unsigned int V_178 = 0 ;
if ( F_21 ( V_23 -> V_37 . V_39 ) )
V_178 = V_179 ;
else if ( V_23 -> V_37 . V_39 )
V_178 = V_82 ;
if ( ( V_40 -> V_11 ^ V_178 ) &
( V_82 | V_179 ) )
return - V_180 ;
}
}
F_93 ( V_28 , V_14 , V_40 , V_23 , ! V_195 [ V_198 ] ) ;
return 0 ;
}
int F_120 ( struct V_48 * V_40 )
{
struct V_13 * V_52 = F_22 ( V_40 ) ;
struct V_72 * V_37 = & V_52 -> V_36 . V_37 ;
int V_51 ;
V_40 -> V_199 = F_101 ;
V_40 -> V_94 = F_121 ( struct V_93 ) ;
if ( ! V_40 -> V_94 )
return - V_60 ;
V_52 -> V_15 = F_122 ( struct V_6 ) ;
if ( ! V_52 -> V_15 ) {
F_103 ( V_40 -> V_94 ) ;
return - V_60 ;
}
V_51 = F_123 ( & V_52 -> V_114 , V_40 ) ;
if ( V_51 ) {
F_103 ( V_52 -> V_15 ) ;
F_103 ( V_40 -> V_94 ) ;
return V_51 ;
}
V_52 -> V_40 = V_40 ;
V_52 -> V_49 = F_59 ( V_40 ) ;
strcpy ( V_52 -> V_36 . V_53 , V_40 -> V_53 ) ;
V_37 -> V_200 = 4 ;
V_37 -> V_201 = 5 ;
return 0 ;
}
void F_124 ( struct V_48 * V_40 )
{
struct V_13 * V_52 = F_22 ( V_40 ) ;
struct V_49 * V_49 = V_52 -> V_49 ;
struct V_27 * V_28 ;
V_28 = F_96 ( V_49 , V_52 -> V_168 ) ;
if ( V_28 -> V_44 != V_40 )
F_26 ( F_22 ( V_40 ) ) ;
F_10 ( V_52 ) ;
}
void F_125 ( struct V_48 * V_40 , int V_202 )
{
struct V_13 * V_52 = F_22 ( V_40 ) ;
V_52 -> V_168 = V_202 ;
}
