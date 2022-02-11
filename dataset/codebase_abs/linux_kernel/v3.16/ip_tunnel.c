static unsigned int F_1 ( T_1 V_1 , T_1 V_2 )
{
return F_2 ( ( V_3 V_4 ) V_1 ^ ( V_3 V_4 ) V_2 ,
V_5 ) ;
}
static void F_3 ( struct V_6 * V_7 ,
struct V_8 * V_9 )
{
struct V_8 * V_10 ;
F_4 ( V_9 ) ;
V_10 = F_5 ( ( V_3 struct V_8 * * ) & V_7 -> V_9 , V_9 ) ;
F_6 ( V_10 ) ;
}
static void F_7 ( struct V_11 * V_12 , struct V_8 * V_9 )
{
F_3 ( F_8 ( V_12 -> V_13 ) , V_9 ) ;
}
static void F_9 ( struct V_11 * V_12 )
{
F_7 ( V_12 , NULL ) ;
}
void F_10 ( struct V_11 * V_12 )
{
int V_14 ;
F_11 (i)
F_3 ( F_12 ( V_12 -> V_13 , V_14 ) , NULL ) ;
}
static struct V_15 * F_13 ( struct V_11 * V_12 , V_4 V_16 )
{
struct V_8 * V_9 ;
F_14 () ;
V_9 = F_15 ( F_8 ( V_12 -> V_13 ) -> V_9 ) ;
if ( V_9 && ! F_16 ( & V_9 -> V_17 ) )
V_9 = NULL ;
if ( V_9 ) {
if ( V_9 -> V_18 && V_9 -> V_19 -> V_20 ( V_9 , V_16 ) == NULL ) {
F_9 ( V_12 ) ;
F_6 ( V_9 ) ;
V_9 = NULL ;
}
}
F_17 () ;
return (struct V_15 * ) V_9 ;
}
static bool F_18 ( const struct V_21 * V_22 ,
T_2 V_23 , T_1 V_1 )
{
if ( V_22 -> V_24 & V_25 ) {
if ( V_23 & V_25 )
return V_1 == V_22 -> V_26 ;
else
return false ;
} else
return ! ( V_23 & V_25 ) ;
}
struct V_11 * F_19 ( struct V_27 * V_28 ,
int V_29 , T_2 V_23 ,
T_1 V_2 , T_1 V_30 ,
T_1 V_1 )
{
unsigned int V_31 ;
struct V_11 * V_12 , * V_32 = NULL ;
struct V_33 * V_34 ;
V_31 = F_1 ( V_1 , V_2 ) ;
V_34 = & V_28 -> V_35 [ V_31 ] ;
F_20 (t, head, hash_node) {
if ( V_30 != V_12 -> V_36 . V_37 . V_38 ||
V_2 != V_12 -> V_36 . V_37 . V_39 ||
! ( V_12 -> V_40 -> V_23 & V_41 ) )
continue;
if ( ! F_18 ( & V_12 -> V_36 , V_23 , V_1 ) )
continue;
if ( V_12 -> V_36 . V_29 == V_29 )
return V_12 ;
else
V_32 = V_12 ;
}
F_20 (t, head, hash_node) {
if ( V_2 != V_12 -> V_36 . V_37 . V_39 ||
V_12 -> V_36 . V_37 . V_38 != 0 ||
! ( V_12 -> V_40 -> V_23 & V_41 ) )
continue;
if ( ! F_18 ( & V_12 -> V_36 , V_23 , V_1 ) )
continue;
if ( V_12 -> V_36 . V_29 == V_29 )
return V_12 ;
else if ( ! V_32 )
V_32 = V_12 ;
}
V_31 = F_1 ( V_1 , 0 ) ;
V_34 = & V_28 -> V_35 [ V_31 ] ;
F_20 (t, head, hash_node) {
if ( ( V_30 != V_12 -> V_36 . V_37 . V_38 || V_12 -> V_36 . V_37 . V_39 != 0 ) &&
( V_30 != V_12 -> V_36 . V_37 . V_39 || ! F_21 ( V_30 ) ) )
continue;
if ( ! ( V_12 -> V_40 -> V_23 & V_41 ) )
continue;
if ( ! F_18 ( & V_12 -> V_36 , V_23 , V_1 ) )
continue;
if ( V_12 -> V_36 . V_29 == V_29 )
return V_12 ;
else if ( ! V_32 )
V_32 = V_12 ;
}
if ( V_23 & V_42 )
goto V_43;
F_20 (t, head, hash_node) {
if ( V_12 -> V_36 . V_26 != V_1 ||
V_12 -> V_36 . V_37 . V_38 != 0 ||
V_12 -> V_36 . V_37 . V_39 != 0 ||
! ( V_12 -> V_40 -> V_23 & V_41 ) )
continue;
if ( V_12 -> V_36 . V_29 == V_29 )
return V_12 ;
else if ( ! V_32 )
V_32 = V_12 ;
}
V_43:
if ( V_32 )
return V_32 ;
if ( V_28 -> V_44 && V_28 -> V_44 -> V_23 & V_41 )
return F_22 ( V_28 -> V_44 ) ;
return NULL ;
}
static struct V_33 * F_23 ( struct V_27 * V_28 ,
struct V_21 * V_36 )
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
static void F_24 ( struct V_27 * V_28 , struct V_11 * V_12 )
{
struct V_33 * V_34 = F_23 ( V_28 , & V_12 -> V_36 ) ;
F_25 ( & V_12 -> V_47 , V_34 ) ;
}
static void F_26 ( struct V_11 * V_12 )
{
F_27 ( & V_12 -> V_47 ) ;
}
static struct V_11 * F_28 ( struct V_27 * V_28 ,
struct V_21 * V_36 ,
int type )
{
T_1 V_2 = V_36 -> V_37 . V_39 ;
T_1 V_30 = V_36 -> V_37 . V_38 ;
T_1 V_1 = V_36 -> V_26 ;
T_2 V_23 = V_36 -> V_24 ;
int V_29 = V_36 -> V_29 ;
struct V_11 * V_12 = NULL ;
struct V_33 * V_34 = F_23 ( V_28 , V_36 ) ;
F_20 (t, head, hash_node) {
if ( V_30 == V_12 -> V_36 . V_37 . V_38 &&
V_2 == V_12 -> V_36 . V_37 . V_39 &&
V_29 == V_12 -> V_36 . V_29 &&
type == V_12 -> V_40 -> type &&
F_18 ( & V_12 -> V_36 , V_23 , V_1 ) )
break;
}
return V_12 ;
}
static struct V_48 * F_29 ( struct V_49 * V_49 ,
const struct V_50 * V_19 ,
struct V_21 * V_36 )
{
int V_51 ;
struct V_11 * V_52 ;
struct V_48 * V_40 ;
char V_53 [ V_54 ] ;
if ( V_36 -> V_53 [ 0 ] )
F_30 ( V_53 , V_36 -> V_53 , V_54 ) ;
else {
if ( strlen ( V_19 -> V_55 ) > ( V_54 - 3 ) ) {
V_51 = - V_56 ;
goto V_57;
}
F_30 ( V_53 , V_19 -> V_55 , V_54 ) ;
strncat ( V_53 , L_1 , 2 ) ;
}
F_31 () ;
V_40 = F_32 ( V_19 -> V_58 , V_53 , V_19 -> V_59 ) ;
if ( ! V_40 ) {
V_51 = - V_60 ;
goto V_57;
}
F_33 ( V_40 , V_49 ) ;
V_40 -> V_50 = V_19 ;
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
struct V_11 * V_52 = F_22 ( V_40 ) ;
const struct V_72 * V_37 ;
int V_73 = V_74 ;
int V_75 = V_76 ;
int V_77 = V_52 -> V_73 + sizeof( struct V_72 ) ;
V_37 = & V_52 -> V_36 . V_37 ;
if ( V_37 -> V_39 ) {
struct V_62 V_63 ;
struct V_15 * V_78 ;
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
V_40 -> V_23 |= V_82 ;
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
static struct V_11 * F_44 ( struct V_49 * V_49 ,
struct V_27 * V_28 ,
struct V_21 * V_36 )
{
struct V_11 * V_86 ;
struct V_48 * V_40 ;
F_45 ( ! V_28 -> V_44 ) ;
V_40 = F_29 ( V_49 , V_28 -> V_44 -> V_50 , V_36 ) ;
if ( F_41 ( V_40 ) )
return F_46 ( V_40 ) ;
V_40 -> V_75 = F_38 ( V_40 ) ;
V_86 = F_22 ( V_40 ) ;
F_24 ( V_28 , V_86 ) ;
return V_86 ;
}
int F_47 ( struct V_11 * V_52 , struct V_87 * V_88 ,
const struct V_89 * V_90 , bool V_91 )
{
struct V_92 * V_93 ;
const struct V_72 * V_37 = F_48 ( V_88 ) ;
int V_51 ;
#ifdef F_49
if ( F_21 ( V_37 -> V_39 ) ) {
V_52 -> V_40 -> V_94 . V_95 ++ ;
V_88 -> V_96 = V_97 ;
}
#endif
if ( ( ! ( V_90 -> V_23 & V_98 ) && ( V_52 -> V_36 . V_24 & V_98 ) ) ||
( ( V_90 -> V_23 & V_98 ) && ! ( V_52 -> V_36 . V_24 & V_98 ) ) ) {
V_52 -> V_40 -> V_94 . V_99 ++ ;
V_52 -> V_40 -> V_94 . V_100 ++ ;
goto V_101;
}
if ( V_52 -> V_36 . V_24 & V_102 ) {
if ( ! ( V_90 -> V_23 & V_102 ) ||
( V_52 -> V_103 && ( V_104 ) ( F_50 ( V_90 -> V_105 ) - V_52 -> V_103 ) < 0 ) ) {
V_52 -> V_40 -> V_94 . V_106 ++ ;
V_52 -> V_40 -> V_94 . V_100 ++ ;
goto V_101;
}
V_52 -> V_103 = F_50 ( V_90 -> V_105 ) + 1 ;
}
F_51 ( V_88 ) ;
V_51 = F_52 ( V_37 , V_88 ) ;
if ( F_53 ( V_51 ) ) {
if ( V_91 )
F_54 ( L_2 ,
& V_37 -> V_38 , V_37 -> V_65 ) ;
if ( V_51 > 1 ) {
++ V_52 -> V_40 -> V_94 . V_107 ;
++ V_52 -> V_40 -> V_94 . V_100 ;
goto V_101;
}
}
V_93 = F_8 ( V_52 -> V_40 -> V_93 ) ;
F_55 ( & V_93 -> V_108 ) ;
V_93 -> V_109 ++ ;
V_93 -> V_110 += V_88 -> V_111 ;
F_56 ( & V_93 -> V_108 ) ;
F_57 ( V_88 , ! F_58 ( V_52 -> V_49 , F_59 ( V_52 -> V_40 ) ) ) ;
if ( V_52 -> V_40 -> type == V_81 ) {
V_88 -> V_79 = F_60 ( V_88 , V_52 -> V_40 ) ;
F_61 ( V_88 , F_62 ( V_88 ) , V_112 ) ;
} else {
V_88 -> V_40 = V_52 -> V_40 ;
}
F_63 ( & V_52 -> V_113 , V_88 ) ;
return 0 ;
V_101:
F_64 ( V_88 ) ;
return 0 ;
}
static int F_65 ( struct V_48 * V_40 , struct V_87 * V_88 ,
struct V_15 * V_78 , T_2 V_114 )
{
struct V_11 * V_52 = F_22 ( V_40 ) ;
int V_115 = V_88 -> V_111 - V_52 -> V_73 - V_40 -> V_83 ;
int V_75 ;
if ( V_114 )
V_75 = F_66 ( & V_78 -> V_9 ) - V_40 -> V_83
- sizeof( struct V_72 ) - V_52 -> V_73 ;
else
V_75 = F_67 ( V_88 ) ? F_66 ( F_67 ( V_88 ) ) : V_40 -> V_75 ;
if ( F_67 ( V_88 ) )
F_67 ( V_88 ) -> V_19 -> V_116 ( F_67 ( V_88 ) , NULL , V_88 , V_75 ) ;
if ( V_88 -> V_79 == F_68 ( V_117 ) ) {
if ( ! F_69 ( V_88 ) &&
( V_114 & F_68 ( V_118 ) ) && V_75 < V_115 ) {
memset ( F_70 ( V_88 ) , 0 , sizeof( * F_70 ( V_88 ) ) ) ;
F_71 ( V_88 , V_119 , V_120 , F_72 ( V_75 ) ) ;
return - V_56 ;
}
}
#if F_73 ( V_121 )
else if ( V_88 -> V_79 == F_68 ( V_122 ) ) {
struct V_123 * V_124 = (struct V_123 * ) F_67 ( V_88 ) ;
if ( V_124 && V_75 < F_66 ( F_67 ( V_88 ) ) &&
V_75 >= V_125 ) {
if ( ( V_52 -> V_36 . V_37 . V_39 &&
! F_21 ( V_52 -> V_36 . V_37 . V_39 ) ) ||
V_124 -> V_126 . V_127 == 128 ) {
V_124 -> V_128 |= V_129 ;
F_74 ( F_67 ( V_88 ) , V_130 , V_75 ) ;
}
}
if ( ! F_69 ( V_88 ) && V_75 >= V_125 &&
V_75 < V_115 ) {
F_75 ( V_88 , V_131 , 0 , V_75 ) ;
return - V_56 ;
}
}
#endif
return 0 ;
}
void F_76 ( struct V_87 * V_88 , struct V_48 * V_40 ,
const struct V_72 * V_132 , const T_4 V_79 )
{
struct V_11 * V_52 = F_22 ( V_40 ) ;
const struct V_72 * V_133 ;
struct V_62 V_63 ;
T_4 V_65 , V_134 ;
T_2 V_114 ;
struct V_15 * V_78 ;
unsigned int V_135 ;
T_1 V_9 ;
int V_51 ;
bool V_136 ;
V_133 = ( const struct V_72 * ) F_77 ( V_88 ) ;
V_136 = ( V_52 -> V_36 . V_37 . V_39 != 0 ) ;
V_9 = V_132 -> V_39 ;
if ( V_9 == 0 ) {
if ( F_67 ( V_88 ) == NULL ) {
V_40 -> V_94 . V_137 ++ ;
goto V_138;
}
if ( V_88 -> V_79 == F_68 ( V_117 ) ) {
V_78 = F_78 ( V_88 ) ;
V_9 = F_79 ( V_78 , V_133 -> V_39 ) ;
}
#if F_73 ( V_121 )
else if ( V_88 -> V_79 == F_68 ( V_122 ) ) {
const struct V_139 * V_140 ;
struct V_141 * V_142 ;
bool V_143 ;
int V_144 ;
V_142 = F_80 ( F_67 ( V_88 ) ,
& F_81 ( V_88 ) -> V_39 ) ;
if ( V_142 == NULL )
goto V_138;
V_140 = ( const struct V_139 * ) & V_142 -> V_145 ;
V_144 = F_82 ( V_140 ) ;
if ( V_144 == V_146 ) {
V_140 = & F_81 ( V_88 ) -> V_39 ;
V_144 = F_82 ( V_140 ) ;
}
if ( ( V_144 & V_147 ) == 0 )
V_143 = true ;
else {
V_143 = false ;
V_9 = V_140 -> V_148 [ 3 ] ;
}
F_83 ( V_142 ) ;
if ( V_143 )
goto V_149;
}
#endif
else
goto V_138;
V_136 = false ;
}
V_65 = V_132 -> V_65 ;
if ( V_65 & 0x1 ) {
V_65 &= ~ 0x1 ;
if ( V_88 -> V_79 == F_68 ( V_117 ) ) {
V_65 = V_133 -> V_65 ;
V_136 = false ;
} else if ( V_88 -> V_79 == F_68 ( V_122 ) ) {
V_65 = F_84 ( ( const struct V_150 * ) V_133 ) ;
V_136 = false ;
}
}
F_37 ( & V_63 , V_79 , V_9 , V_132 -> V_38 ,
V_52 -> V_36 . V_80 , F_39 ( V_65 ) , V_52 -> V_36 . V_29 ) ;
V_78 = V_136 ? F_13 ( V_52 , 0 ) : NULL ;
if ( ! V_78 ) {
V_78 = F_40 ( V_52 -> V_49 , & V_63 ) ;
if ( F_41 ( V_78 ) ) {
V_40 -> V_94 . V_151 ++ ;
goto V_138;
}
if ( V_136 )
F_7 ( V_52 , & V_78 -> V_9 ) ;
}
if ( V_78 -> V_9 . V_40 == V_40 ) {
F_42 ( V_78 ) ;
V_40 -> V_94 . V_152 ++ ;
goto V_138;
}
if ( F_65 ( V_40 , V_88 , V_78 , V_132 -> V_153 ) ) {
F_42 ( V_78 ) ;
goto V_138;
}
if ( V_52 -> V_154 > 0 ) {
if ( F_85 ( V_155 ,
V_52 -> V_156 + V_157 ) ) {
V_52 -> V_154 -- ;
memset ( F_70 ( V_88 ) , 0 , sizeof( * F_70 ( V_88 ) ) ) ;
F_86 ( V_88 ) ;
} else
V_52 -> V_154 = 0 ;
}
V_65 = F_87 ( V_65 , V_133 , V_88 ) ;
V_134 = V_132 -> V_134 ;
if ( V_134 == 0 ) {
if ( V_88 -> V_79 == F_68 ( V_117 ) )
V_134 = V_133 -> V_134 ;
#if F_73 ( V_121 )
else if ( V_88 -> V_79 == F_68 ( V_122 ) )
V_134 = ( ( const struct V_150 * ) V_133 ) -> V_158 ;
#endif
else
V_134 = F_88 ( & V_78 -> V_9 ) ;
}
V_114 = V_132 -> V_153 ;
if ( V_88 -> V_79 == F_68 ( V_117 ) )
V_114 |= ( V_133 -> V_153 & F_68 ( V_118 ) ) ;
V_135 = F_89 ( V_78 -> V_9 . V_40 ) + sizeof( struct V_72 )
+ V_78 -> V_9 . V_159 ;
if ( V_135 > V_40 -> V_84 )
V_40 -> V_84 = V_135 ;
if ( F_90 ( V_88 , V_40 -> V_84 ) ) {
F_42 ( V_78 ) ;
V_40 -> V_94 . V_160 ++ ;
F_64 ( V_88 ) ;
return;
}
V_51 = F_91 ( V_88 -> V_161 , V_78 , V_88 , V_63 . V_38 , V_63 . V_39 , V_79 ,
V_65 , V_134 , V_114 , ! F_58 ( V_52 -> V_49 , F_59 ( V_40 ) ) ) ;
F_92 ( V_51 , & V_40 -> V_94 , V_40 -> V_93 ) ;
return;
#if F_73 ( V_121 )
V_149:
F_86 ( V_88 ) ;
#endif
V_138:
V_40 -> V_94 . V_162 ++ ;
F_64 ( V_88 ) ;
}
static void F_93 ( struct V_27 * V_28 ,
struct V_11 * V_12 ,
struct V_48 * V_40 ,
struct V_21 * V_22 ,
bool V_163 )
{
F_26 ( V_12 ) ;
V_12 -> V_36 . V_37 . V_38 = V_22 -> V_37 . V_38 ;
V_12 -> V_36 . V_37 . V_39 = V_22 -> V_37 . V_39 ;
V_12 -> V_36 . V_26 = V_22 -> V_26 ;
V_12 -> V_36 . V_80 = V_22 -> V_80 ;
if ( V_40 -> type != V_81 ) {
memcpy ( V_40 -> V_164 , & V_22 -> V_37 . V_38 , 4 ) ;
memcpy ( V_40 -> V_165 , & V_22 -> V_37 . V_39 , 4 ) ;
}
F_24 ( V_28 , V_12 ) ;
V_12 -> V_36 . V_37 . V_134 = V_22 -> V_37 . V_134 ;
V_12 -> V_36 . V_37 . V_65 = V_22 -> V_37 . V_65 ;
V_12 -> V_36 . V_37 . V_153 = V_22 -> V_37 . V_153 ;
if ( V_12 -> V_36 . V_29 != V_22 -> V_29 ) {
int V_75 ;
V_12 -> V_36 . V_29 = V_22 -> V_29 ;
V_75 = F_38 ( V_40 ) ;
if ( V_163 )
V_40 -> V_75 = V_75 ;
}
F_10 ( V_12 ) ;
F_94 ( V_40 ) ;
}
int F_95 ( struct V_48 * V_40 , struct V_21 * V_22 , int V_166 )
{
int V_51 = 0 ;
struct V_11 * V_12 = F_22 ( V_40 ) ;
struct V_49 * V_49 = V_12 -> V_49 ;
struct V_27 * V_28 = F_96 ( V_49 , V_12 -> V_167 ) ;
F_45 ( ! V_28 -> V_44 ) ;
switch ( V_166 ) {
case V_168 :
if ( V_40 == V_28 -> V_44 ) {
V_12 = F_28 ( V_28 , V_22 , V_28 -> V_44 -> type ) ;
if ( V_12 == NULL )
V_12 = F_22 ( V_40 ) ;
}
memcpy ( V_22 , & V_12 -> V_36 , sizeof( * V_22 ) ) ;
break;
case V_169 :
case V_170 :
V_51 = - V_171 ;
if ( ! F_97 ( V_49 -> V_172 , V_173 ) )
goto V_174;
if ( V_22 -> V_37 . V_134 )
V_22 -> V_37 . V_153 |= F_68 ( V_118 ) ;
if ( ! ( V_22 -> V_24 & V_46 ) ) {
if ( ! ( V_22 -> V_24 & V_25 ) )
V_22 -> V_26 = 0 ;
if ( ! ( V_22 -> V_175 & V_25 ) )
V_22 -> V_80 = 0 ;
}
V_12 = F_28 ( V_28 , V_22 , V_28 -> V_44 -> type ) ;
if ( ! V_12 && ( V_166 == V_169 ) ) {
V_12 = F_44 ( V_49 , V_28 , V_22 ) ;
V_51 = F_98 ( V_12 ) ;
break;
}
if ( V_40 != V_28 -> V_44 && V_166 == V_170 ) {
if ( V_12 != NULL ) {
if ( V_12 -> V_40 != V_40 ) {
V_51 = - V_176 ;
break;
}
} else {
unsigned int V_177 = 0 ;
if ( F_21 ( V_22 -> V_37 . V_39 ) )
V_177 = V_178 ;
else if ( V_22 -> V_37 . V_39 )
V_177 = V_82 ;
if ( ( V_40 -> V_23 ^ V_177 ) & ( V_82 | V_178 ) ) {
V_51 = - V_179 ;
break;
}
V_12 = F_22 ( V_40 ) ;
}
}
if ( V_12 ) {
V_51 = 0 ;
F_93 ( V_28 , V_12 , V_40 , V_22 , true ) ;
} else {
V_51 = - V_180 ;
}
break;
case V_181 :
V_51 = - V_171 ;
if ( ! F_97 ( V_49 -> V_172 , V_173 ) )
goto V_174;
if ( V_40 == V_28 -> V_44 ) {
V_51 = - V_180 ;
V_12 = F_28 ( V_28 , V_22 , V_28 -> V_44 -> type ) ;
if ( V_12 == NULL )
goto V_174;
V_51 = - V_171 ;
if ( V_12 == F_22 ( V_28 -> V_44 ) )
goto V_174;
V_40 = V_12 -> V_40 ;
}
F_99 ( V_40 ) ;
V_51 = 0 ;
break;
default:
V_51 = - V_179 ;
}
V_174:
return V_51 ;
}
int F_100 ( struct V_48 * V_40 , int V_182 )
{
struct V_11 * V_52 = F_22 ( V_40 ) ;
int V_77 = V_52 -> V_73 + sizeof( struct V_72 ) ;
if ( V_182 < 68 ||
V_182 > 0xFFF8 - V_40 -> V_83 - V_77 )
return - V_179 ;
V_40 -> V_75 = V_182 ;
return 0 ;
}
static void F_101 ( struct V_48 * V_40 )
{
struct V_11 * V_52 = F_22 ( V_40 ) ;
F_102 ( & V_52 -> V_113 ) ;
F_103 ( V_52 -> V_13 ) ;
F_103 ( V_40 -> V_93 ) ;
F_35 ( V_40 ) ;
}
void F_104 ( struct V_48 * V_40 , struct V_183 * V_34 )
{
struct V_11 * V_52 = F_22 ( V_40 ) ;
struct V_27 * V_28 ;
V_28 = F_96 ( V_52 -> V_49 , V_52 -> V_167 ) ;
if ( V_28 -> V_44 != V_40 ) {
F_26 ( F_22 ( V_40 ) ) ;
F_105 ( V_40 , V_34 ) ;
}
}
int F_106 ( struct V_49 * V_49 , int V_167 ,
struct V_50 * V_19 , char * V_184 )
{
struct V_27 * V_28 = F_96 ( V_49 , V_167 ) ;
struct V_21 V_36 ;
unsigned int V_14 ;
for ( V_14 = 0 ; V_14 < V_185 ; V_14 ++ )
F_107 ( & V_28 -> V_35 [ V_14 ] ) ;
if ( ! V_19 ) {
V_28 -> V_44 = NULL ;
return 0 ;
}
memset ( & V_36 , 0 , sizeof( V_36 ) ) ;
if ( V_184 )
F_30 ( V_36 . V_53 , V_184 , V_54 ) ;
F_108 () ;
V_28 -> V_44 = F_29 ( V_49 , V_19 , & V_36 ) ;
if ( ! F_41 ( V_28 -> V_44 ) ) {
V_28 -> V_44 -> V_186 |= V_187 ;
V_28 -> V_44 -> V_75 = F_38 ( V_28 -> V_44 ) ;
F_24 ( V_28 , F_22 ( V_28 -> V_44 ) ) ;
}
F_109 () ;
return F_98 ( V_28 -> V_44 ) ;
}
static void F_110 ( struct V_27 * V_28 , struct V_183 * V_34 ,
struct V_50 * V_19 )
{
struct V_49 * V_49 = F_59 ( V_28 -> V_44 ) ;
struct V_48 * V_40 , * V_188 ;
int V_45 ;
F_111 (net, dev, aux)
if ( V_40 -> V_50 == V_19 )
F_105 ( V_40 , V_34 ) ;
for ( V_45 = 0 ; V_45 < V_185 ; V_45 ++ ) {
struct V_11 * V_12 ;
struct V_189 * V_190 ;
struct V_33 * V_191 = & V_28 -> V_35 [ V_45 ] ;
F_112 (t, n, thead, hash_node)
if ( ! F_58 ( F_59 ( V_12 -> V_40 ) , V_49 ) )
F_105 ( V_12 -> V_40 , V_34 ) ;
}
}
void F_113 ( struct V_27 * V_28 , struct V_50 * V_19 )
{
F_114 ( V_192 ) ;
F_108 () ;
F_110 ( V_28 , & V_192 , V_19 ) ;
F_115 ( & V_192 ) ;
F_109 () ;
}
int F_116 ( struct V_48 * V_40 , struct V_193 * V_194 [] ,
struct V_21 * V_22 )
{
struct V_11 * V_86 ;
struct V_49 * V_49 = F_59 ( V_40 ) ;
struct V_27 * V_28 ;
int V_75 ;
int V_51 ;
V_86 = F_22 ( V_40 ) ;
V_28 = F_96 ( V_49 , V_86 -> V_167 ) ;
if ( F_28 ( V_28 , V_22 , V_40 -> type ) )
return - V_176 ;
V_86 -> V_49 = V_49 ;
V_86 -> V_36 = * V_22 ;
V_51 = F_34 ( V_40 ) ;
if ( V_51 )
goto V_195;
if ( V_40 -> type == V_81 && ! V_194 [ V_196 ] )
F_117 ( V_40 ) ;
V_75 = F_38 ( V_40 ) ;
if ( ! V_194 [ V_197 ] )
V_40 -> V_75 = V_75 ;
F_24 ( V_28 , V_86 ) ;
V_195:
return V_51 ;
}
int F_118 ( struct V_48 * V_40 , struct V_193 * V_194 [] ,
struct V_21 * V_22 )
{
struct V_11 * V_12 ;
struct V_11 * V_52 = F_22 ( V_40 ) ;
struct V_49 * V_49 = V_52 -> V_49 ;
struct V_27 * V_28 = F_96 ( V_49 , V_52 -> V_167 ) ;
if ( V_40 == V_28 -> V_44 )
return - V_179 ;
V_12 = F_28 ( V_28 , V_22 , V_40 -> type ) ;
if ( V_12 ) {
if ( V_12 -> V_40 != V_40 )
return - V_176 ;
} else {
V_12 = V_52 ;
if ( V_40 -> type != V_81 ) {
unsigned int V_177 = 0 ;
if ( F_21 ( V_22 -> V_37 . V_39 ) )
V_177 = V_178 ;
else if ( V_22 -> V_37 . V_39 )
V_177 = V_82 ;
if ( ( V_40 -> V_23 ^ V_177 ) &
( V_82 | V_178 ) )
return - V_179 ;
}
}
F_93 ( V_28 , V_12 , V_40 , V_22 , ! V_194 [ V_197 ] ) ;
return 0 ;
}
int F_119 ( struct V_48 * V_40 )
{
struct V_11 * V_52 = F_22 ( V_40 ) ;
struct V_72 * V_37 = & V_52 -> V_36 . V_37 ;
int V_51 ;
V_40 -> V_198 = F_101 ;
V_40 -> V_93 = F_120 ( struct V_92 ) ;
if ( ! V_40 -> V_93 )
return - V_60 ;
V_52 -> V_13 = F_121 ( struct V_6 ) ;
if ( ! V_52 -> V_13 ) {
F_103 ( V_40 -> V_93 ) ;
return - V_60 ;
}
V_51 = F_122 ( & V_52 -> V_113 , V_40 ) ;
if ( V_51 ) {
F_103 ( V_52 -> V_13 ) ;
F_103 ( V_40 -> V_93 ) ;
return V_51 ;
}
V_52 -> V_40 = V_40 ;
V_52 -> V_49 = F_59 ( V_40 ) ;
strcpy ( V_52 -> V_36 . V_53 , V_40 -> V_53 ) ;
V_37 -> V_199 = 4 ;
V_37 -> V_200 = 5 ;
return 0 ;
}
void F_123 ( struct V_48 * V_40 )
{
struct V_11 * V_52 = F_22 ( V_40 ) ;
struct V_49 * V_49 = V_52 -> V_49 ;
struct V_27 * V_28 ;
V_28 = F_96 ( V_49 , V_52 -> V_167 ) ;
if ( V_28 -> V_44 != V_40 )
F_26 ( F_22 ( V_40 ) ) ;
F_10 ( V_52 ) ;
}
void F_124 ( struct V_48 * V_40 , int V_201 )
{
struct V_11 * V_52 = F_22 ( V_40 ) ;
V_52 -> V_167 = V_201 ;
}
