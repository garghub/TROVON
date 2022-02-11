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
if ( V_36 -> V_37 . V_39 && ! F_21 ( V_36 -> V_37 . V_39 ) )
V_2 = V_36 -> V_37 . V_39 ;
else
V_2 = 0 ;
V_45 = F_1 ( V_36 -> V_26 , V_2 ) ;
return & V_28 -> V_35 [ V_45 ] ;
}
static void F_24 ( struct V_27 * V_28 , struct V_13 * V_14 )
{
struct V_33 * V_34 = F_23 ( V_28 , & V_14 -> V_36 ) ;
F_25 ( & V_14 -> V_46 , V_34 ) ;
}
static void F_26 ( struct V_13 * V_14 )
{
F_27 ( & V_14 -> V_46 ) ;
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
static struct V_47 * F_29 ( struct V_48 * V_48 ,
const struct V_49 * V_20 ,
struct V_22 * V_36 )
{
int V_50 ;
struct V_13 * V_51 ;
struct V_47 * V_40 ;
char V_52 [ V_53 ] ;
if ( V_36 -> V_52 [ 0 ] )
F_30 ( V_52 , V_36 -> V_52 , V_53 ) ;
else {
if ( strlen ( V_20 -> V_54 ) > ( V_53 - 3 ) ) {
V_50 = - V_55 ;
goto V_56;
}
F_30 ( V_52 , V_20 -> V_54 , V_53 ) ;
strncat ( V_52 , L_1 , 2 ) ;
}
F_31 () ;
V_40 = F_32 ( V_20 -> V_57 , V_52 , V_20 -> V_58 ) ;
if ( ! V_40 ) {
V_50 = - V_59 ;
goto V_56;
}
F_33 ( V_40 , V_48 ) ;
V_40 -> V_49 = V_20 ;
V_51 = F_22 ( V_40 ) ;
V_51 -> V_36 = * V_36 ;
V_51 -> V_48 = V_48 ;
V_50 = F_34 ( V_40 ) ;
if ( V_50 )
goto V_60;
return V_40 ;
V_60:
F_35 ( V_40 ) ;
V_56:
return F_36 ( V_50 ) ;
}
static inline void F_37 ( struct V_61 * V_62 ,
int V_63 ,
T_1 V_39 , T_1 V_38 ,
T_1 V_1 , T_3 V_64 , int V_65 )
{
memset ( V_62 , 0 , sizeof( * V_62 ) ) ;
V_62 -> V_66 = V_65 ;
V_62 -> V_39 = V_39 ;
V_62 -> V_38 = V_38 ;
V_62 -> V_67 = V_64 ;
V_62 -> V_68 = V_63 ;
V_62 -> V_69 = V_1 ;
}
static int F_38 ( struct V_47 * V_40 )
{
struct V_47 * V_70 = NULL ;
struct V_13 * V_51 = F_22 ( V_40 ) ;
const struct V_71 * V_37 ;
int V_72 = V_73 ;
int V_74 = V_75 ;
int V_76 = V_51 -> V_72 + sizeof( struct V_71 ) ;
V_37 = & V_51 -> V_36 . V_37 ;
if ( V_37 -> V_39 ) {
struct V_61 V_62 ;
struct V_17 * V_77 ;
F_37 ( & V_62 , V_37 -> V_78 , V_37 -> V_39 ,
V_37 -> V_38 , V_51 -> V_36 . V_79 ,
F_39 ( V_37 -> V_64 ) , V_51 -> V_36 . V_29 ) ;
V_77 = F_40 ( V_51 -> V_48 , & V_62 ) ;
if ( ! F_41 ( V_77 ) ) {
V_70 = V_77 -> V_9 . V_40 ;
F_7 ( V_51 , & V_77 -> V_9 ) ;
F_42 ( V_77 ) ;
}
if ( V_40 -> type != V_80 )
V_40 -> V_11 |= V_81 ;
}
if ( ! V_70 && V_51 -> V_36 . V_29 )
V_70 = F_43 ( V_51 -> V_48 , V_51 -> V_36 . V_29 ) ;
if ( V_70 ) {
V_72 = V_70 -> V_82 + V_70 -> V_83 ;
V_74 = V_70 -> V_74 ;
}
V_40 -> V_84 = V_51 -> V_36 . V_29 ;
V_40 -> V_83 = V_76 + V_72 ;
V_74 -= ( V_40 -> V_82 + V_76 ) ;
if ( V_74 < 68 )
V_74 = 68 ;
return V_74 ;
}
static struct V_13 * F_44 ( struct V_48 * V_48 ,
struct V_27 * V_28 ,
struct V_22 * V_36 )
{
struct V_13 * V_85 , * V_86 ;
struct V_47 * V_40 ;
F_45 ( ! V_28 -> V_44 ) ;
V_86 = F_22 ( V_28 -> V_44 ) ;
V_40 = F_29 ( V_48 , V_28 -> V_44 -> V_49 , V_36 ) ;
if ( F_41 ( V_40 ) )
return NULL ;
V_40 -> V_74 = F_38 ( V_40 ) ;
V_85 = F_22 ( V_40 ) ;
F_24 ( V_28 , V_85 ) ;
return V_85 ;
}
int F_46 ( struct V_13 * V_51 , struct V_87 * V_88 ,
const struct V_89 * V_90 , bool V_91 )
{
struct V_92 * V_93 ;
const struct V_71 * V_37 = F_47 ( V_88 ) ;
int V_50 ;
#ifdef F_48
if ( F_21 ( V_37 -> V_39 ) ) {
V_51 -> V_40 -> V_94 . V_95 ++ ;
V_88 -> V_96 = V_97 ;
}
#endif
if ( ( ! ( V_90 -> V_11 & V_98 ) && ( V_51 -> V_36 . V_24 & V_98 ) ) ||
( ( V_90 -> V_11 & V_98 ) && ! ( V_51 -> V_36 . V_24 & V_98 ) ) ) {
V_51 -> V_40 -> V_94 . V_99 ++ ;
V_51 -> V_40 -> V_94 . V_100 ++ ;
goto V_101;
}
if ( V_51 -> V_36 . V_24 & V_102 ) {
if ( ! ( V_90 -> V_11 & V_102 ) ||
( V_51 -> V_103 && ( V_104 ) ( F_49 ( V_90 -> V_105 ) - V_51 -> V_103 ) < 0 ) ) {
V_51 -> V_40 -> V_94 . V_106 ++ ;
V_51 -> V_40 -> V_94 . V_100 ++ ;
goto V_101;
}
V_51 -> V_103 = F_49 ( V_90 -> V_105 ) + 1 ;
}
V_50 = F_50 ( V_37 , V_88 ) ;
if ( F_51 ( V_50 ) ) {
if ( V_91 )
F_52 ( L_2 ,
& V_37 -> V_38 , V_37 -> V_64 ) ;
if ( V_50 > 1 ) {
++ V_51 -> V_40 -> V_94 . V_107 ;
++ V_51 -> V_40 -> V_94 . V_100 ;
goto V_101;
}
}
V_93 = F_8 ( V_51 -> V_40 -> V_93 ) ;
F_53 ( & V_93 -> V_108 ) ;
V_93 -> V_109 ++ ;
V_93 -> V_110 += V_88 -> V_111 ;
F_54 ( & V_93 -> V_108 ) ;
F_55 ( V_88 , ! F_56 ( V_51 -> V_48 , F_57 ( V_51 -> V_40 ) ) ) ;
if ( V_51 -> V_40 -> type == V_80 ) {
V_88 -> V_78 = F_58 ( V_88 , V_51 -> V_40 ) ;
F_59 ( V_88 , F_60 ( V_88 ) , V_112 ) ;
} else {
V_88 -> V_40 = V_51 -> V_40 ;
}
F_61 ( & V_51 -> V_113 , V_88 ) ;
return 0 ;
V_101:
F_62 ( V_88 ) ;
return 0 ;
}
static int F_63 ( struct V_47 * V_40 , struct V_87 * V_88 ,
struct V_17 * V_77 , T_2 V_114 )
{
struct V_13 * V_51 = F_22 ( V_40 ) ;
int V_115 = V_88 -> V_111 - V_51 -> V_72 - V_40 -> V_82 ;
int V_74 ;
if ( V_114 )
V_74 = F_64 ( & V_77 -> V_9 ) - V_40 -> V_82
- sizeof( struct V_71 ) - V_51 -> V_72 ;
else
V_74 = F_65 ( V_88 ) ? F_64 ( F_65 ( V_88 ) ) : V_40 -> V_74 ;
if ( F_65 ( V_88 ) )
F_65 ( V_88 ) -> V_20 -> V_116 ( F_65 ( V_88 ) , NULL , V_88 , V_74 ) ;
if ( V_88 -> V_78 == F_66 ( V_117 ) ) {
if ( ! F_67 ( V_88 ) &&
( V_114 & F_66 ( V_118 ) ) && V_74 < V_115 ) {
memset ( F_68 ( V_88 ) , 0 , sizeof( * F_68 ( V_88 ) ) ) ;
F_69 ( V_88 , V_119 , V_120 , F_70 ( V_74 ) ) ;
return - V_55 ;
}
}
#if F_71 ( V_121 )
else if ( V_88 -> V_78 == F_66 ( V_122 ) ) {
struct V_123 * V_124 = (struct V_123 * ) F_65 ( V_88 ) ;
if ( V_124 && V_74 < F_64 ( F_65 ( V_88 ) ) &&
V_74 >= V_125 ) {
if ( ( V_51 -> V_36 . V_37 . V_39 &&
! F_21 ( V_51 -> V_36 . V_37 . V_39 ) ) ||
V_124 -> V_126 . V_127 == 128 ) {
V_124 -> V_128 |= V_129 ;
F_72 ( F_65 ( V_88 ) , V_130 , V_74 ) ;
}
}
if ( ! F_67 ( V_88 ) && V_74 >= V_125 &&
V_74 < V_115 ) {
F_73 ( V_88 , V_131 , 0 , V_74 ) ;
return - V_55 ;
}
}
#endif
return 0 ;
}
void F_74 ( struct V_87 * V_88 , struct V_47 * V_40 ,
const struct V_71 * V_132 , const T_4 V_78 )
{
struct V_13 * V_51 = F_22 ( V_40 ) ;
const struct V_71 * V_133 ;
struct V_61 V_62 ;
T_4 V_64 , V_134 ;
T_2 V_114 ;
struct V_17 * V_77 ;
unsigned int V_135 ;
T_1 V_9 ;
int V_50 ;
bool V_136 = true ;
V_133 = ( const struct V_71 * ) F_75 ( V_88 ) ;
V_9 = V_132 -> V_39 ;
if ( V_9 == 0 ) {
if ( F_65 ( V_88 ) == NULL ) {
V_40 -> V_94 . V_137 ++ ;
goto V_138;
}
if ( V_88 -> V_78 == F_66 ( V_117 ) ) {
V_77 = F_76 ( V_88 ) ;
V_9 = F_77 ( V_77 , V_133 -> V_39 ) ;
}
#if F_71 ( V_121 )
else if ( V_88 -> V_78 == F_66 ( V_122 ) ) {
const struct V_139 * V_140 ;
struct V_141 * V_142 ;
bool V_143 ;
int V_144 ;
V_142 = F_78 ( F_65 ( V_88 ) ,
& F_79 ( V_88 ) -> V_39 ) ;
if ( V_142 == NULL )
goto V_138;
V_140 = ( const struct V_139 * ) & V_142 -> V_145 ;
V_144 = F_80 ( V_140 ) ;
if ( V_144 == V_146 ) {
V_140 = & F_79 ( V_88 ) -> V_39 ;
V_144 = F_80 ( V_140 ) ;
}
if ( ( V_144 & V_147 ) == 0 )
V_143 = true ;
else {
V_143 = false ;
V_9 = V_140 -> V_148 [ 3 ] ;
}
F_81 ( V_142 ) ;
if ( V_143 )
goto V_149;
}
#endif
else
goto V_138;
V_136 = false ;
}
V_64 = V_132 -> V_64 ;
if ( V_64 & 0x1 ) {
V_64 &= ~ 0x1 ;
if ( V_88 -> V_78 == F_66 ( V_117 ) ) {
V_64 = V_133 -> V_64 ;
V_136 = false ;
} else if ( V_88 -> V_78 == F_66 ( V_122 ) ) {
V_64 = F_82 ( ( const struct V_150 * ) V_133 ) ;
V_136 = false ;
}
}
F_37 ( & V_62 , V_78 , V_9 , V_132 -> V_38 ,
V_51 -> V_36 . V_79 , F_39 ( V_64 ) , V_51 -> V_36 . V_29 ) ;
V_77 = V_136 ? F_13 ( V_51 , 0 ) : NULL ;
if ( ! V_77 ) {
V_77 = F_40 ( V_51 -> V_48 , & V_62 ) ;
if ( F_41 ( V_77 ) ) {
V_40 -> V_94 . V_151 ++ ;
goto V_138;
}
if ( V_136 )
F_7 ( V_51 , & V_77 -> V_9 ) ;
}
if ( V_77 -> V_9 . V_40 == V_40 ) {
F_42 ( V_77 ) ;
V_40 -> V_94 . V_152 ++ ;
goto V_138;
}
if ( F_63 ( V_40 , V_88 , V_77 , V_132 -> V_153 ) ) {
F_42 ( V_77 ) ;
goto V_138;
}
if ( V_51 -> V_154 > 0 ) {
if ( F_83 ( V_155 ,
V_51 -> V_156 + V_157 ) ) {
V_51 -> V_154 -- ;
memset ( F_68 ( V_88 ) , 0 , sizeof( * F_68 ( V_88 ) ) ) ;
F_84 ( V_88 ) ;
} else
V_51 -> V_154 = 0 ;
}
V_64 = F_85 ( V_64 , V_133 , V_88 ) ;
V_134 = V_132 -> V_134 ;
if ( V_134 == 0 ) {
if ( V_88 -> V_78 == F_66 ( V_117 ) )
V_134 = V_133 -> V_134 ;
#if F_71 ( V_121 )
else if ( V_88 -> V_78 == F_66 ( V_122 ) )
V_134 = ( ( const struct V_150 * ) V_133 ) -> V_158 ;
#endif
else
V_134 = F_86 ( & V_77 -> V_9 ) ;
}
V_114 = V_132 -> V_153 ;
if ( V_88 -> V_78 == F_66 ( V_117 ) )
V_114 |= ( V_133 -> V_153 & F_66 ( V_118 ) ) ;
V_135 = F_87 ( V_77 -> V_9 . V_40 ) + sizeof( struct V_71 )
+ V_77 -> V_9 . V_159 ;
if ( V_135 > V_40 -> V_83 )
V_40 -> V_83 = V_135 ;
if ( F_88 ( V_88 , V_40 -> V_83 ) ) {
V_40 -> V_94 . V_160 ++ ;
F_62 ( V_88 ) ;
return;
}
V_50 = F_89 ( V_77 , V_88 , V_62 . V_38 , V_62 . V_39 , V_78 ,
V_64 , V_134 , V_114 , ! F_56 ( V_51 -> V_48 , F_57 ( V_40 ) ) ) ;
F_90 ( V_50 , & V_40 -> V_94 , V_40 -> V_93 ) ;
return;
#if F_71 ( V_121 )
V_149:
F_84 ( V_88 ) ;
#endif
V_138:
V_40 -> V_94 . V_161 ++ ;
F_62 ( V_88 ) ;
}
static void F_91 ( struct V_27 * V_28 ,
struct V_13 * V_14 ,
struct V_47 * V_40 ,
struct V_22 * V_23 ,
bool V_162 )
{
F_26 ( V_14 ) ;
V_14 -> V_36 . V_37 . V_38 = V_23 -> V_37 . V_38 ;
V_14 -> V_36 . V_37 . V_39 = V_23 -> V_37 . V_39 ;
V_14 -> V_36 . V_26 = V_23 -> V_26 ;
V_14 -> V_36 . V_79 = V_23 -> V_79 ;
if ( V_40 -> type != V_80 ) {
memcpy ( V_40 -> V_163 , & V_23 -> V_37 . V_38 , 4 ) ;
memcpy ( V_40 -> V_164 , & V_23 -> V_37 . V_39 , 4 ) ;
}
F_24 ( V_28 , V_14 ) ;
V_14 -> V_36 . V_37 . V_134 = V_23 -> V_37 . V_134 ;
V_14 -> V_36 . V_37 . V_64 = V_23 -> V_37 . V_64 ;
V_14 -> V_36 . V_37 . V_153 = V_23 -> V_37 . V_153 ;
if ( V_14 -> V_36 . V_29 != V_23 -> V_29 ) {
int V_74 ;
V_14 -> V_36 . V_29 = V_23 -> V_29 ;
V_74 = F_38 ( V_40 ) ;
if ( V_162 )
V_40 -> V_74 = V_74 ;
}
F_10 ( V_14 ) ;
F_92 ( V_40 ) ;
}
int F_93 ( struct V_47 * V_40 , struct V_22 * V_23 , int V_165 )
{
int V_50 = 0 ;
struct V_13 * V_14 ;
struct V_48 * V_48 = F_57 ( V_40 ) ;
struct V_13 * V_51 = F_22 ( V_40 ) ;
struct V_27 * V_28 = F_94 ( V_48 , V_51 -> V_166 ) ;
F_45 ( ! V_28 -> V_44 ) ;
switch ( V_165 ) {
case V_167 :
V_14 = NULL ;
if ( V_40 == V_28 -> V_44 )
V_14 = F_28 ( V_28 , V_23 , V_28 -> V_44 -> type ) ;
if ( V_14 == NULL )
V_14 = F_22 ( V_40 ) ;
memcpy ( V_23 , & V_14 -> V_36 , sizeof( * V_23 ) ) ;
break;
case V_168 :
case V_169 :
V_50 = - V_170 ;
if ( ! F_95 ( V_48 -> V_171 , V_172 ) )
goto V_173;
if ( V_23 -> V_37 . V_134 )
V_23 -> V_37 . V_153 |= F_66 ( V_118 ) ;
if ( ! ( V_23 -> V_24 & V_25 ) )
V_23 -> V_26 = 0 ;
if ( ! ( V_23 -> V_174 & V_25 ) )
V_23 -> V_79 = 0 ;
V_14 = F_28 ( V_28 , V_23 , V_28 -> V_44 -> type ) ;
if ( ! V_14 && ( V_165 == V_168 ) )
V_14 = F_44 ( V_48 , V_28 , V_23 ) ;
if ( V_40 != V_28 -> V_44 && V_165 == V_169 ) {
if ( V_14 != NULL ) {
if ( V_14 -> V_40 != V_40 ) {
V_50 = - V_175 ;
break;
}
} else {
unsigned int V_176 = 0 ;
if ( F_21 ( V_23 -> V_37 . V_39 ) )
V_176 = V_177 ;
else if ( V_23 -> V_37 . V_39 )
V_176 = V_81 ;
if ( ( V_40 -> V_11 ^ V_176 ) & ( V_81 | V_177 ) ) {
V_50 = - V_178 ;
break;
}
V_14 = F_22 ( V_40 ) ;
}
}
if ( V_14 ) {
V_50 = 0 ;
F_91 ( V_28 , V_14 , V_40 , V_23 , true ) ;
} else
V_50 = ( V_165 == V_168 ? - V_179 : - V_180 ) ;
break;
case V_181 :
V_50 = - V_170 ;
if ( ! F_95 ( V_48 -> V_171 , V_172 ) )
goto V_173;
if ( V_40 == V_28 -> V_44 ) {
V_50 = - V_180 ;
V_14 = F_28 ( V_28 , V_23 , V_28 -> V_44 -> type ) ;
if ( V_14 == NULL )
goto V_173;
V_50 = - V_170 ;
if ( V_14 == F_22 ( V_28 -> V_44 ) )
goto V_173;
V_40 = V_14 -> V_40 ;
}
F_96 ( V_40 ) ;
V_50 = 0 ;
break;
default:
V_50 = - V_178 ;
}
V_173:
return V_50 ;
}
int F_97 ( struct V_47 * V_40 , int V_182 )
{
struct V_13 * V_51 = F_22 ( V_40 ) ;
int V_76 = V_51 -> V_72 + sizeof( struct V_71 ) ;
if ( V_182 < 68 ||
V_182 > 0xFFF8 - V_40 -> V_82 - V_76 )
return - V_178 ;
V_40 -> V_74 = V_182 ;
return 0 ;
}
static void F_98 ( struct V_47 * V_40 )
{
struct V_13 * V_51 = F_22 ( V_40 ) ;
F_99 ( & V_51 -> V_113 ) ;
F_100 ( V_51 -> V_15 ) ;
F_100 ( V_40 -> V_93 ) ;
F_35 ( V_40 ) ;
}
void F_101 ( struct V_47 * V_40 , struct V_183 * V_34 )
{
struct V_13 * V_51 = F_22 ( V_40 ) ;
struct V_27 * V_28 ;
V_28 = F_94 ( V_51 -> V_48 , V_51 -> V_166 ) ;
if ( V_28 -> V_44 != V_40 ) {
F_26 ( F_22 ( V_40 ) ) ;
F_102 ( V_40 , V_34 ) ;
}
}
int F_103 ( struct V_48 * V_48 , int V_166 ,
struct V_49 * V_20 , char * V_184 )
{
struct V_27 * V_28 = F_94 ( V_48 , V_166 ) ;
struct V_22 V_36 ;
unsigned int V_16 ;
for ( V_16 = 0 ; V_16 < V_185 ; V_16 ++ )
F_104 ( & V_28 -> V_35 [ V_16 ] ) ;
if ( ! V_20 ) {
V_28 -> V_44 = NULL ;
return 0 ;
}
memset ( & V_36 , 0 , sizeof( V_36 ) ) ;
if ( V_184 )
F_30 ( V_36 . V_52 , V_184 , V_53 ) ;
F_105 () ;
V_28 -> V_44 = F_29 ( V_48 , V_20 , & V_36 ) ;
if ( ! F_41 ( V_28 -> V_44 ) ) {
V_28 -> V_44 -> V_186 |= V_187 ;
F_24 ( V_28 , F_22 ( V_28 -> V_44 ) ) ;
}
F_106 () ;
return F_107 ( V_28 -> V_44 ) ;
}
static void F_108 ( struct V_27 * V_28 , struct V_183 * V_34 ,
struct V_49 * V_20 )
{
struct V_48 * V_48 = F_57 ( V_28 -> V_44 ) ;
struct V_47 * V_40 , * V_188 ;
int V_45 ;
F_109 (net, dev, aux)
if ( V_40 -> V_49 == V_20 )
F_102 ( V_40 , V_34 ) ;
for ( V_45 = 0 ; V_45 < V_185 ; V_45 ++ ) {
struct V_13 * V_14 ;
struct V_189 * V_190 ;
struct V_33 * V_191 = & V_28 -> V_35 [ V_45 ] ;
F_110 (t, n, thead, hash_node)
if ( ! F_56 ( F_57 ( V_14 -> V_40 ) , V_48 ) )
F_102 ( V_14 -> V_40 , V_34 ) ;
}
}
void F_111 ( struct V_27 * V_28 , struct V_49 * V_20 )
{
F_112 ( V_192 ) ;
F_105 () ;
F_108 ( V_28 , & V_192 , V_20 ) ;
F_113 ( & V_192 ) ;
F_106 () ;
}
int F_114 ( struct V_47 * V_40 , struct V_193 * V_194 [] ,
struct V_22 * V_23 )
{
struct V_13 * V_85 ;
struct V_48 * V_48 = F_57 ( V_40 ) ;
struct V_27 * V_28 ;
int V_74 ;
int V_50 ;
V_85 = F_22 ( V_40 ) ;
V_28 = F_94 ( V_48 , V_85 -> V_166 ) ;
if ( F_28 ( V_28 , V_23 , V_40 -> type ) )
return - V_175 ;
V_85 -> V_48 = V_48 ;
V_85 -> V_36 = * V_23 ;
V_50 = F_34 ( V_40 ) ;
if ( V_50 )
goto V_195;
if ( V_40 -> type == V_80 && ! V_194 [ V_196 ] )
F_115 ( V_40 ) ;
V_74 = F_38 ( V_40 ) ;
if ( ! V_194 [ V_197 ] )
V_40 -> V_74 = V_74 ;
F_24 ( V_28 , V_85 ) ;
V_195:
return V_50 ;
}
int F_116 ( struct V_47 * V_40 , struct V_193 * V_194 [] ,
struct V_22 * V_23 )
{
struct V_13 * V_14 ;
struct V_13 * V_51 = F_22 ( V_40 ) ;
struct V_48 * V_48 = V_51 -> V_48 ;
struct V_27 * V_28 = F_94 ( V_48 , V_51 -> V_166 ) ;
if ( V_40 == V_28 -> V_44 )
return - V_178 ;
V_14 = F_28 ( V_28 , V_23 , V_40 -> type ) ;
if ( V_14 ) {
if ( V_14 -> V_40 != V_40 )
return - V_175 ;
} else {
V_14 = V_51 ;
if ( V_40 -> type != V_80 ) {
unsigned int V_176 = 0 ;
if ( F_21 ( V_23 -> V_37 . V_39 ) )
V_176 = V_177 ;
else if ( V_23 -> V_37 . V_39 )
V_176 = V_81 ;
if ( ( V_40 -> V_11 ^ V_176 ) &
( V_81 | V_177 ) )
return - V_178 ;
}
}
F_91 ( V_28 , V_14 , V_40 , V_23 , ! V_194 [ V_197 ] ) ;
return 0 ;
}
int F_117 ( struct V_47 * V_40 )
{
struct V_13 * V_51 = F_22 ( V_40 ) ;
struct V_71 * V_37 = & V_51 -> V_36 . V_37 ;
int V_16 , V_50 ;
V_40 -> V_198 = F_98 ;
V_40 -> V_93 = F_118 ( struct V_92 ) ;
if ( ! V_40 -> V_93 )
return - V_59 ;
F_11 (i) {
struct V_92 * V_199 ;
V_199 = F_12 ( V_40 -> V_93 , V_16 ) ;
F_119 ( & V_199 -> V_108 ) ;
}
V_51 -> V_15 = F_118 ( struct V_6 ) ;
if ( ! V_51 -> V_15 ) {
F_100 ( V_40 -> V_93 ) ;
return - V_59 ;
}
V_50 = F_120 ( & V_51 -> V_113 , V_40 ) ;
if ( V_50 ) {
F_100 ( V_51 -> V_15 ) ;
F_100 ( V_40 -> V_93 ) ;
return V_50 ;
}
V_51 -> V_40 = V_40 ;
V_51 -> V_48 = F_57 ( V_40 ) ;
strcpy ( V_51 -> V_36 . V_52 , V_40 -> V_52 ) ;
V_37 -> V_200 = 4 ;
V_37 -> V_201 = 5 ;
return 0 ;
}
void F_121 ( struct V_47 * V_40 )
{
struct V_13 * V_51 = F_22 ( V_40 ) ;
struct V_48 * V_48 = V_51 -> V_48 ;
struct V_27 * V_28 ;
V_28 = F_94 ( V_48 , V_51 -> V_166 ) ;
if ( V_28 -> V_44 != V_40 )
F_26 ( F_22 ( V_40 ) ) ;
F_10 ( V_51 ) ;
}
void F_122 ( struct V_47 * V_40 , int V_202 )
{
struct V_13 * V_51 = F_22 ( V_40 ) ;
V_51 -> V_166 = V_202 ;
}
