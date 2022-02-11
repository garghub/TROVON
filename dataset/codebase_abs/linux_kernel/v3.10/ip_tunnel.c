static unsigned int F_1 ( struct V_1 * V_2 ,
T_1 V_3 , T_1 V_4 )
{
return F_2 ( ( V_5 V_6 ) V_3 ^ ( V_5 V_6 ) V_4 ,
V_7 ) ;
}
struct V_8 * F_3 ( struct V_9 * V_10 ,
struct V_8 * V_11 )
{
int V_12 ;
F_4 (i) {
const struct V_13 * V_14 = F_5 ( V_10 -> V_14 , V_12 ) ;
T_2 V_15 , V_16 , V_17 , V_18 ;
unsigned int V_19 ;
do {
V_19 = F_6 ( & V_14 -> V_20 ) ;
V_15 = V_14 -> V_15 ;
V_17 = V_14 -> V_17 ;
V_16 = V_14 -> V_16 ;
V_18 = V_14 -> V_18 ;
} while ( F_7 ( & V_14 -> V_20 , V_19 ) );
V_11 -> V_15 += V_15 ;
V_11 -> V_17 += V_17 ;
V_11 -> V_16 += V_16 ;
V_11 -> V_18 += V_18 ;
}
V_11 -> V_21 = V_10 -> V_22 . V_21 ;
V_11 -> V_23 = V_10 -> V_22 . V_23 ;
V_11 -> V_24 = V_10 -> V_22 . V_24 ;
V_11 -> V_25 = V_10 -> V_22 . V_25 ;
V_11 -> V_26 = V_10 -> V_22 . V_26 ;
V_11 -> V_27 = V_10 -> V_22 . V_27 ;
V_11 -> V_28 = V_10 -> V_22 . V_28 ;
V_11 -> V_29 = V_10 -> V_22 . V_29 ;
V_11 -> V_30 = V_10 -> V_22 . V_30 ;
V_11 -> V_31 = V_10 -> V_22 . V_31 ;
V_11 -> V_32 = V_10 -> V_22 . V_32 ;
V_11 -> V_33 = V_10 -> V_22 . V_33 ;
return V_11 ;
}
static bool F_8 ( const struct V_34 * V_35 ,
T_3 V_36 , T_1 V_3 )
{
if ( V_35 -> V_37 & V_38 ) {
if ( V_36 & V_38 )
return V_3 == V_35 -> V_39 ;
else
return false ;
} else
return ! ( V_36 & V_38 ) ;
}
struct V_40 * F_9 ( struct V_1 * V_2 ,
int V_41 , T_3 V_36 ,
T_1 V_4 , T_1 V_42 ,
T_1 V_3 )
{
unsigned int V_43 ;
struct V_40 * V_44 , * V_45 = NULL ;
struct V_46 * V_47 ;
V_43 = F_1 ( V_2 , V_3 , V_4 ) ;
V_47 = & V_2 -> V_48 [ V_43 ] ;
F_10 (t, head, hash_node) {
if ( V_42 != V_44 -> V_49 . V_50 . V_51 ||
V_4 != V_44 -> V_49 . V_50 . V_52 ||
! ( V_44 -> V_10 -> V_36 & V_53 ) )
continue;
if ( ! F_8 ( & V_44 -> V_49 , V_36 , V_3 ) )
continue;
if ( V_44 -> V_49 . V_41 == V_41 )
return V_44 ;
else
V_45 = V_44 ;
}
F_10 (t, head, hash_node) {
if ( V_4 != V_44 -> V_49 . V_50 . V_52 ||
! ( V_44 -> V_10 -> V_36 & V_53 ) )
continue;
if ( ! F_8 ( & V_44 -> V_49 , V_36 , V_3 ) )
continue;
if ( V_44 -> V_49 . V_41 == V_41 )
return V_44 ;
else if ( ! V_45 )
V_45 = V_44 ;
}
V_43 = F_1 ( V_2 , V_3 , 0 ) ;
V_47 = & V_2 -> V_48 [ V_43 ] ;
F_10 (t, head, hash_node) {
if ( ( V_42 != V_44 -> V_49 . V_50 . V_51 &&
( V_42 != V_44 -> V_49 . V_50 . V_52 ||
! F_11 ( V_42 ) ) ) ||
! ( V_44 -> V_10 -> V_36 & V_53 ) )
continue;
if ( ! F_8 ( & V_44 -> V_49 , V_36 , V_3 ) )
continue;
if ( V_44 -> V_49 . V_41 == V_41 )
return V_44 ;
else if ( ! V_45 )
V_45 = V_44 ;
}
if ( V_36 & V_54 )
goto V_55;
F_10 (t, head, hash_node) {
if ( V_44 -> V_49 . V_39 != V_3 ||
! ( V_44 -> V_10 -> V_36 & V_53 ) )
continue;
if ( V_44 -> V_49 . V_41 == V_41 )
return V_44 ;
else if ( ! V_45 )
V_45 = V_44 ;
}
V_55:
if ( V_45 )
return V_45 ;
if ( V_2 -> V_56 && V_2 -> V_56 -> V_36 & V_53 )
return F_12 ( V_2 -> V_56 ) ;
return NULL ;
}
static struct V_46 * F_13 ( struct V_1 * V_2 ,
struct V_34 * V_49 )
{
unsigned int V_57 ;
T_1 V_4 ;
if ( V_49 -> V_50 . V_52 && ! F_11 ( V_49 -> V_50 . V_52 ) )
V_4 = V_49 -> V_50 . V_52 ;
else
V_4 = 0 ;
V_57 = F_1 ( V_2 , V_49 -> V_39 , V_4 ) ;
return & V_2 -> V_48 [ V_57 ] ;
}
static void F_14 ( struct V_1 * V_2 , struct V_40 * V_44 )
{
struct V_46 * V_47 = F_13 ( V_2 , & V_44 -> V_49 ) ;
F_15 ( & V_44 -> V_58 , V_47 ) ;
}
static void F_16 ( struct V_40 * V_44 )
{
F_17 ( & V_44 -> V_58 ) ;
}
static struct V_40 * F_18 ( struct V_1 * V_2 ,
struct V_34 * V_49 ,
int type )
{
T_1 V_4 = V_49 -> V_50 . V_52 ;
T_1 V_42 = V_49 -> V_50 . V_51 ;
T_1 V_3 = V_49 -> V_39 ;
int V_41 = V_49 -> V_41 ;
struct V_40 * V_44 = NULL ;
struct V_46 * V_47 = F_13 ( V_2 , V_49 ) ;
F_10 (t, head, hash_node) {
if ( V_42 == V_44 -> V_49 . V_50 . V_51 &&
V_4 == V_44 -> V_49 . V_50 . V_52 &&
V_3 == V_44 -> V_49 . V_39 &&
V_41 == V_44 -> V_49 . V_41 &&
type == V_44 -> V_10 -> type )
break;
}
return V_44 ;
}
static struct V_9 * F_19 ( struct V_59 * V_59 ,
const struct V_60 * V_61 ,
struct V_34 * V_49 )
{
int V_62 ;
struct V_40 * V_63 ;
struct V_9 * V_10 ;
char V_64 [ V_65 ] ;
if ( V_49 -> V_64 [ 0 ] )
F_20 ( V_64 , V_49 -> V_64 , V_65 ) ;
else {
if ( strlen ( V_61 -> V_66 ) > ( V_65 - 3 ) ) {
V_62 = - V_67 ;
goto V_68;
}
F_20 ( V_64 , V_61 -> V_66 , V_65 ) ;
strncat ( V_64 , L_1 , 2 ) ;
}
F_21 () ;
V_10 = F_22 ( V_61 -> V_69 , V_64 , V_61 -> V_70 ) ;
if ( ! V_10 ) {
V_62 = - V_71 ;
goto V_68;
}
F_23 ( V_10 , V_59 ) ;
V_10 -> V_60 = V_61 ;
V_63 = F_12 ( V_10 ) ;
V_63 -> V_49 = * V_49 ;
V_62 = F_24 ( V_10 ) ;
if ( V_62 )
goto V_72;
return V_10 ;
V_72:
F_25 ( V_10 ) ;
V_68:
return F_26 ( V_62 ) ;
}
static inline struct V_73 * F_27 ( struct V_59 * V_59 ,
struct V_74 * V_75 ,
int V_76 ,
T_1 V_52 , T_1 V_51 ,
T_1 V_3 , T_4 V_77 , int V_78 )
{
memset ( V_75 , 0 , sizeof( * V_75 ) ) ;
V_75 -> V_79 = V_78 ;
V_75 -> V_52 = V_52 ;
V_75 -> V_51 = V_51 ;
V_75 -> V_80 = V_77 ;
V_75 -> V_81 = V_76 ;
V_75 -> V_82 = V_3 ;
return F_28 ( V_59 , V_75 ) ;
}
static int F_29 ( struct V_9 * V_10 )
{
struct V_9 * V_83 = NULL ;
struct V_40 * V_63 = F_12 ( V_10 ) ;
const struct V_84 * V_50 ;
int V_85 = V_86 ;
int V_87 = V_88 ;
int V_89 = V_63 -> V_85 + sizeof( struct V_84 ) ;
V_50 = & V_63 -> V_49 . V_50 ;
if ( V_50 -> V_52 ) {
struct V_74 V_75 ;
struct V_73 * V_90 ;
V_90 = F_27 ( F_30 ( V_10 ) , & V_75 ,
V_63 -> V_49 . V_50 . V_91 ,
V_50 -> V_52 , V_50 -> V_51 ,
V_63 -> V_49 . V_92 ,
F_31 ( V_50 -> V_77 ) ,
V_63 -> V_49 . V_41 ) ;
if ( ! F_32 ( V_90 ) ) {
V_83 = V_90 -> V_93 . V_10 ;
F_33 ( V_90 ) ;
}
if ( V_10 -> type != V_94 )
V_10 -> V_36 |= V_95 ;
}
if ( ! V_83 && V_63 -> V_49 . V_41 )
V_83 = F_34 ( F_30 ( V_10 ) , V_63 -> V_49 . V_41 ) ;
if ( V_83 ) {
V_85 = V_83 -> V_96 + V_83 -> V_97 ;
V_87 = V_83 -> V_87 ;
}
V_10 -> V_98 = V_63 -> V_49 . V_41 ;
V_10 -> V_97 = V_89 + V_85 ;
V_87 -= ( V_10 -> V_96 + V_89 ) ;
if ( V_87 < 68 )
V_87 = 68 ;
return V_87 ;
}
static struct V_40 * F_35 ( struct V_59 * V_59 ,
struct V_1 * V_2 ,
struct V_34 * V_49 )
{
struct V_40 * V_99 , * V_100 ;
struct V_9 * V_10 ;
F_36 ( ! V_2 -> V_56 ) ;
V_100 = F_12 ( V_2 -> V_56 ) ;
V_10 = F_19 ( V_59 , V_2 -> V_56 -> V_60 , V_49 ) ;
if ( F_32 ( V_10 ) )
return NULL ;
V_10 -> V_87 = F_29 ( V_10 ) ;
V_99 = F_12 ( V_10 ) ;
F_14 ( V_2 , V_99 ) ;
return V_99 ;
}
int F_37 ( struct V_40 * V_63 , struct V_101 * V_102 ,
const struct V_103 * V_104 , bool V_105 )
{
struct V_13 * V_14 ;
const struct V_84 * V_50 = F_38 ( V_102 ) ;
int V_62 ;
F_39 ( V_102 ) ;
V_102 -> V_91 = V_104 -> V_76 ;
V_102 -> V_106 = V_102 -> V_107 ;
F_40 ( V_102 , V_63 -> V_85 ) ;
F_41 ( V_102 , F_42 ( V_102 ) , V_63 -> V_85 ) ;
#ifdef F_43
if ( F_11 ( V_50 -> V_52 ) ) {
if ( F_44 ( F_45 ( V_102 ) ) )
goto V_108;
V_63 -> V_10 -> V_22 . V_21 ++ ;
V_102 -> V_109 = V_110 ;
}
#endif
if ( ( ! ( V_104 -> V_36 & V_111 ) && ( V_63 -> V_49 . V_37 & V_111 ) ) ||
( ( V_104 -> V_36 & V_111 ) && ! ( V_63 -> V_49 . V_37 & V_111 ) ) ) {
V_63 -> V_10 -> V_22 . V_23 ++ ;
V_63 -> V_10 -> V_22 . V_27 ++ ;
goto V_108;
}
if ( V_63 -> V_49 . V_37 & V_112 ) {
if ( ! ( V_104 -> V_36 & V_112 ) ||
( V_63 -> V_113 && ( V_114 ) ( F_46 ( V_104 -> V_115 ) - V_63 -> V_113 ) < 0 ) ) {
V_63 -> V_10 -> V_22 . V_24 ++ ;
V_63 -> V_10 -> V_22 . V_27 ++ ;
goto V_108;
}
V_63 -> V_113 = F_46 ( V_104 -> V_115 ) + 1 ;
}
if ( V_63 -> V_10 -> type == V_94 ) {
if ( ! F_47 ( V_102 , V_116 ) ) {
V_63 -> V_10 -> V_22 . V_25 ++ ;
V_63 -> V_10 -> V_22 . V_27 ++ ;
goto V_108;
}
V_50 = F_38 ( V_102 ) ;
V_102 -> V_91 = F_48 ( V_102 , V_63 -> V_10 ) ;
F_41 ( V_102 , F_49 ( V_102 ) , V_116 ) ;
}
V_102 -> V_109 = V_117 ;
F_50 ( V_102 , V_63 -> V_10 ) ;
F_51 ( V_102 ) ;
V_62 = F_52 ( V_50 , V_102 ) ;
if ( F_53 ( V_62 ) ) {
if ( V_105 )
F_54 ( L_2 ,
& V_50 -> V_51 , V_50 -> V_77 ) ;
if ( V_62 > 1 ) {
++ V_63 -> V_10 -> V_22 . V_26 ;
++ V_63 -> V_10 -> V_22 . V_27 ;
goto V_108;
}
}
V_14 = F_55 ( V_63 -> V_10 -> V_14 ) ;
F_56 ( & V_14 -> V_20 ) ;
V_14 -> V_15 ++ ;
V_14 -> V_16 += V_102 -> V_118 ;
F_57 ( & V_14 -> V_20 ) ;
F_58 ( & V_63 -> V_119 , V_102 ) ;
return 0 ;
V_108:
F_59 ( V_102 ) ;
return 0 ;
}
void F_60 ( struct V_101 * V_102 , struct V_9 * V_10 ,
const struct V_84 * V_120 )
{
struct V_40 * V_63 = F_12 ( V_10 ) ;
const struct V_84 * V_121 ;
struct V_84 * V_50 ;
struct V_74 V_75 ;
T_5 V_77 , V_122 ;
T_3 V_123 ;
struct V_73 * V_90 ;
struct V_9 * V_83 ;
unsigned int V_124 ;
T_1 V_93 ;
int V_87 ;
V_121 = ( const struct V_84 * ) F_61 ( V_102 ) ;
memset ( F_62 ( V_102 ) , 0 , sizeof( * F_62 ( V_102 ) ) ) ;
V_93 = V_120 -> V_52 ;
if ( V_93 == 0 ) {
if ( F_63 ( V_102 ) == NULL ) {
V_10 -> V_22 . V_28 ++ ;
goto V_125;
}
if ( V_102 -> V_91 == F_64 ( V_126 ) ) {
V_90 = F_45 ( V_102 ) ;
V_93 = F_65 ( V_90 , V_121 -> V_52 ) ;
}
#if F_66 ( V_127 )
else if ( V_102 -> V_91 == F_64 ( V_128 ) ) {
const struct V_129 * V_130 ;
struct V_131 * V_132 ;
bool V_133 ;
int V_134 ;
V_132 = F_67 ( F_63 ( V_102 ) ,
& F_68 ( V_102 ) -> V_52 ) ;
if ( V_132 == NULL )
goto V_125;
V_130 = ( const struct V_129 * ) & V_132 -> V_135 ;
V_134 = F_69 ( V_130 ) ;
if ( V_134 == V_136 ) {
V_130 = & F_68 ( V_102 ) -> V_52 ;
V_134 = F_69 ( V_130 ) ;
}
if ( ( V_134 & V_137 ) == 0 )
V_133 = true ;
else {
V_133 = false ;
V_93 = V_130 -> V_138 [ 3 ] ;
}
F_70 ( V_132 ) ;
if ( V_133 )
goto V_139;
}
#endif
else
goto V_125;
}
V_77 = V_120 -> V_77 ;
if ( V_77 & 0x1 ) {
V_77 &= ~ 0x1 ;
if ( V_102 -> V_91 == F_64 ( V_126 ) )
V_77 = V_121 -> V_77 ;
else if ( V_102 -> V_91 == F_64 ( V_128 ) )
V_77 = F_71 ( ( const struct V_140 * ) V_121 ) ;
}
V_90 = F_27 ( F_30 ( V_10 ) , & V_75 ,
V_63 -> V_49 . V_50 . V_91 ,
V_93 , V_120 -> V_51 ,
V_63 -> V_49 . V_92 ,
F_31 ( V_77 ) ,
V_63 -> V_49 . V_41 ) ;
if ( F_32 ( V_90 ) ) {
V_10 -> V_22 . V_29 ++ ;
goto V_125;
}
V_83 = V_90 -> V_93 . V_10 ;
if ( V_83 == V_10 ) {
F_33 ( V_90 ) ;
V_10 -> V_22 . V_33 ++ ;
goto V_125;
}
V_123 = V_120 -> V_141 ;
if ( V_123 )
V_87 = F_72 ( & V_90 -> V_93 ) - V_10 -> V_96
- sizeof( struct V_84 ) ;
else
V_87 = F_63 ( V_102 ) ? F_72 ( F_63 ( V_102 ) ) : V_10 -> V_87 ;
if ( F_63 ( V_102 ) )
F_63 ( V_102 ) -> V_61 -> V_142 ( F_63 ( V_102 ) , NULL , V_102 , V_87 ) ;
if ( V_102 -> V_91 == F_64 ( V_126 ) ) {
V_123 |= ( V_121 -> V_141 & F_64 ( V_143 ) ) ;
if ( ! F_73 ( V_102 ) &&
( V_121 -> V_141 & F_64 ( V_143 ) ) &&
V_87 < F_74 ( V_121 -> V_144 ) ) {
F_75 ( V_102 , V_145 , V_146 , F_76 ( V_87 ) ) ;
F_33 ( V_90 ) ;
goto V_125;
}
}
#if F_66 ( V_127 )
else if ( V_102 -> V_91 == F_64 ( V_128 ) ) {
struct V_147 * V_148 = (struct V_147 * ) F_63 ( V_102 ) ;
if ( V_148 && V_87 < F_72 ( F_63 ( V_102 ) ) &&
V_87 >= V_149 ) {
if ( ( V_63 -> V_49 . V_50 . V_52 &&
! F_11 ( V_63 -> V_49 . V_50 . V_52 ) ) ||
V_148 -> V_150 . V_151 == 128 ) {
V_148 -> V_152 |= V_153 ;
F_77 ( F_63 ( V_102 ) , V_154 , V_87 ) ;
}
}
if ( ! F_73 ( V_102 ) && V_87 >= V_149 &&
V_87 < V_102 -> V_118 ) {
F_78 ( V_102 , V_155 , 0 , V_87 ) ;
F_33 ( V_90 ) ;
goto V_125;
}
}
#endif
if ( V_63 -> V_156 > 0 ) {
if ( F_79 ( V_157 ,
V_63 -> V_158 + V_159 ) ) {
V_63 -> V_156 -- ;
F_80 ( V_102 ) ;
} else
V_63 -> V_156 = 0 ;
}
V_122 = V_120 -> V_122 ;
if ( V_122 == 0 ) {
if ( V_102 -> V_91 == F_64 ( V_126 ) )
V_122 = V_121 -> V_122 ;
#if F_66 ( V_127 )
else if ( V_102 -> V_91 == F_64 ( V_128 ) )
V_122 = ( ( const struct V_140 * ) V_121 ) -> V_160 ;
#endif
else
V_122 = F_81 ( & V_90 -> V_93 ) ;
}
V_124 = F_82 ( V_83 ) + sizeof( struct V_84 )
+ V_90 -> V_93 . V_161 ;
if ( V_124 > V_10 -> V_97 ) {
V_10 -> V_97 = V_124 ;
if ( F_83 ( V_102 , V_10 -> V_97 ) ) {
V_10 -> V_22 . V_30 ++ ;
F_84 ( V_102 ) ;
return;
}
}
F_85 ( V_102 ) ;
F_86 ( V_102 , & V_90 -> V_93 ) ;
F_87 ( V_102 , sizeof( struct V_84 ) ) ;
F_51 ( V_102 ) ;
V_50 = F_38 ( V_102 ) ;
V_121 = ( const struct V_84 * ) F_61 ( V_102 ) ;
V_50 -> V_162 = 4 ;
V_50 -> V_163 = sizeof( struct V_84 ) >> 2 ;
V_50 -> V_141 = V_123 ;
V_50 -> V_91 = V_120 -> V_91 ;
V_50 -> V_77 = F_88 ( V_77 , V_121 , V_102 ) ;
V_50 -> V_52 = V_75 . V_52 ;
V_50 -> V_51 = V_75 . V_51 ;
V_50 -> V_122 = V_122 ;
F_89 ( V_102 , V_121 , & V_90 -> V_93 ) ;
F_90 ( V_102 , V_10 ) ;
return;
#if F_66 ( V_127 )
V_139:
F_80 ( V_102 ) ;
#endif
V_125:
V_10 -> V_22 . V_32 ++ ;
F_84 ( V_102 ) ;
}
static void F_91 ( struct V_1 * V_2 ,
struct V_40 * V_44 ,
struct V_9 * V_10 ,
struct V_34 * V_35 ,
bool V_164 )
{
F_16 ( V_44 ) ;
V_44 -> V_49 . V_50 . V_51 = V_35 -> V_50 . V_51 ;
V_44 -> V_49 . V_50 . V_52 = V_35 -> V_50 . V_52 ;
V_44 -> V_49 . V_39 = V_35 -> V_39 ;
V_44 -> V_49 . V_92 = V_35 -> V_92 ;
if ( V_10 -> type != V_94 ) {
memcpy ( V_10 -> V_165 , & V_35 -> V_50 . V_51 , 4 ) ;
memcpy ( V_10 -> V_166 , & V_35 -> V_50 . V_52 , 4 ) ;
}
F_14 ( V_2 , V_44 ) ;
V_44 -> V_49 . V_50 . V_122 = V_35 -> V_50 . V_122 ;
V_44 -> V_49 . V_50 . V_77 = V_35 -> V_50 . V_77 ;
V_44 -> V_49 . V_50 . V_141 = V_35 -> V_50 . V_141 ;
if ( V_44 -> V_49 . V_41 != V_35 -> V_41 ) {
int V_87 ;
V_44 -> V_49 . V_41 = V_35 -> V_41 ;
V_87 = F_29 ( V_10 ) ;
if ( V_164 )
V_10 -> V_87 = V_87 ;
}
F_92 ( V_10 ) ;
}
int F_93 ( struct V_9 * V_10 , struct V_34 * V_35 , int V_167 )
{
int V_62 = 0 ;
struct V_40 * V_44 ;
struct V_59 * V_59 = F_30 ( V_10 ) ;
struct V_40 * V_63 = F_12 ( V_10 ) ;
struct V_1 * V_2 = F_94 ( V_59 , V_63 -> V_168 ) ;
F_36 ( ! V_2 -> V_56 ) ;
switch ( V_167 ) {
case V_169 :
V_44 = NULL ;
if ( V_10 == V_2 -> V_56 )
V_44 = F_18 ( V_2 , V_35 , V_2 -> V_56 -> type ) ;
if ( V_44 == NULL )
V_44 = F_12 ( V_10 ) ;
memcpy ( V_35 , & V_44 -> V_49 , sizeof( * V_35 ) ) ;
break;
case V_170 :
case V_171 :
V_62 = - V_172 ;
if ( ! F_95 ( V_59 -> V_173 , V_174 ) )
goto V_175;
if ( V_35 -> V_50 . V_122 )
V_35 -> V_50 . V_141 |= F_64 ( V_143 ) ;
if ( ! ( V_35 -> V_37 & V_38 ) )
V_35 -> V_39 = 0 ;
if ( ! ( V_35 -> V_176 & V_38 ) )
V_35 -> V_92 = 0 ;
V_44 = F_18 ( V_2 , V_35 , V_2 -> V_56 -> type ) ;
if ( ! V_44 && ( V_167 == V_170 ) )
V_44 = F_35 ( V_59 , V_2 , V_35 ) ;
if ( V_10 != V_2 -> V_56 && V_167 == V_171 ) {
if ( V_44 != NULL ) {
if ( V_44 -> V_10 != V_10 ) {
V_62 = - V_177 ;
break;
}
} else {
unsigned int V_178 = 0 ;
if ( F_11 ( V_35 -> V_50 . V_52 ) )
V_178 = V_179 ;
else if ( V_35 -> V_50 . V_52 )
V_178 = V_95 ;
if ( ( V_10 -> V_36 ^ V_178 ) & ( V_95 | V_179 ) ) {
V_62 = - V_180 ;
break;
}
V_44 = F_12 ( V_10 ) ;
}
}
if ( V_44 ) {
V_62 = 0 ;
F_91 ( V_2 , V_44 , V_10 , V_35 , true ) ;
} else
V_62 = ( V_167 == V_170 ? - V_181 : - V_182 ) ;
break;
case V_183 :
V_62 = - V_172 ;
if ( ! F_95 ( V_59 -> V_173 , V_174 ) )
goto V_175;
if ( V_10 == V_2 -> V_56 ) {
V_62 = - V_182 ;
V_44 = F_18 ( V_2 , V_35 , V_2 -> V_56 -> type ) ;
if ( V_44 == NULL )
goto V_175;
V_62 = - V_172 ;
if ( V_44 == F_12 ( V_2 -> V_56 ) )
goto V_175;
V_10 = V_44 -> V_10 ;
}
F_96 ( V_10 ) ;
V_62 = 0 ;
break;
default:
V_62 = - V_180 ;
}
V_175:
return V_62 ;
}
int F_97 ( struct V_9 * V_10 , int V_184 )
{
struct V_40 * V_63 = F_12 ( V_10 ) ;
int V_89 = V_63 -> V_85 + sizeof( struct V_84 ) ;
if ( V_184 < 68 ||
V_184 > 0xFFF8 - V_10 -> V_96 - V_89 )
return - V_180 ;
V_10 -> V_87 = V_184 ;
return 0 ;
}
static void F_98 ( struct V_9 * V_10 )
{
struct V_40 * V_63 = F_12 ( V_10 ) ;
F_99 ( & V_63 -> V_119 ) ;
F_100 ( V_10 -> V_14 ) ;
F_25 ( V_10 ) ;
}
void F_101 ( struct V_9 * V_10 , struct V_185 * V_47 )
{
struct V_59 * V_59 = F_30 ( V_10 ) ;
struct V_40 * V_63 = F_12 ( V_10 ) ;
struct V_1 * V_2 ;
V_2 = F_94 ( V_59 , V_63 -> V_168 ) ;
if ( V_2 -> V_56 != V_10 ) {
F_16 ( F_12 ( V_10 ) ) ;
F_102 ( V_10 , V_47 ) ;
}
}
int F_103 ( struct V_59 * V_59 , int V_168 ,
struct V_60 * V_61 , char * V_186 )
{
struct V_1 * V_2 = F_94 ( V_59 , V_168 ) ;
struct V_34 V_49 ;
V_2 -> V_48 = F_104 ( V_187 * sizeof( struct V_46 ) , V_188 ) ;
if ( ! V_2 -> V_48 )
return - V_71 ;
if ( ! V_61 ) {
V_2 -> V_56 = NULL ;
return 0 ;
}
memset ( & V_49 , 0 , sizeof( V_49 ) ) ;
if ( V_186 )
F_20 ( V_49 . V_64 , V_186 , V_65 ) ;
F_105 () ;
V_2 -> V_56 = F_19 ( V_59 , V_61 , & V_49 ) ;
F_106 () ;
if ( F_32 ( V_2 -> V_56 ) ) {
F_107 ( V_2 -> V_48 ) ;
return F_108 ( V_2 -> V_56 ) ;
}
return 0 ;
}
static void F_109 ( struct V_1 * V_2 , struct V_185 * V_47 )
{
int V_57 ;
for ( V_57 = 0 ; V_57 < V_187 ; V_57 ++ ) {
struct V_40 * V_44 ;
struct V_189 * V_190 ;
struct V_46 * V_191 = & V_2 -> V_48 [ V_57 ] ;
F_110 (t, n, thead, hash_node)
F_102 ( V_44 -> V_10 , V_47 ) ;
}
if ( V_2 -> V_56 )
F_102 ( V_2 -> V_56 , V_47 ) ;
}
void F_111 ( struct V_1 * V_2 )
{
F_112 ( V_192 ) ;
F_105 () ;
F_109 ( V_2 , & V_192 ) ;
F_113 ( & V_192 ) ;
F_106 () ;
F_107 ( V_2 -> V_48 ) ;
}
int F_114 ( struct V_9 * V_10 , struct V_193 * V_194 [] ,
struct V_34 * V_35 )
{
struct V_40 * V_99 ;
struct V_59 * V_59 = F_30 ( V_10 ) ;
struct V_1 * V_2 ;
int V_87 ;
int V_62 ;
V_99 = F_12 ( V_10 ) ;
V_2 = F_94 ( V_59 , V_99 -> V_168 ) ;
if ( F_18 ( V_2 , V_35 , V_10 -> type ) )
return - V_177 ;
V_99 -> V_49 = * V_35 ;
V_62 = F_24 ( V_10 ) ;
if ( V_62 )
goto V_195;
if ( V_10 -> type == V_94 && ! V_194 [ V_196 ] )
F_115 ( V_10 ) ;
V_87 = F_29 ( V_10 ) ;
if ( ! V_194 [ V_197 ] )
V_10 -> V_87 = V_87 ;
F_14 ( V_2 , V_99 ) ;
V_195:
return V_62 ;
}
int F_116 ( struct V_9 * V_10 , struct V_193 * V_194 [] ,
struct V_34 * V_35 )
{
struct V_40 * V_44 , * V_99 ;
struct V_59 * V_59 = F_30 ( V_10 ) ;
struct V_40 * V_63 = F_12 ( V_10 ) ;
struct V_1 * V_2 = F_94 ( V_59 , V_63 -> V_168 ) ;
if ( V_10 == V_2 -> V_56 )
return - V_180 ;
V_99 = F_12 ( V_10 ) ;
V_44 = F_18 ( V_2 , V_35 , V_10 -> type ) ;
if ( V_44 ) {
if ( V_44 -> V_10 != V_10 )
return - V_177 ;
} else {
V_44 = V_99 ;
if ( V_10 -> type != V_94 ) {
unsigned int V_178 = 0 ;
if ( F_11 ( V_35 -> V_50 . V_52 ) )
V_178 = V_179 ;
else if ( V_35 -> V_50 . V_52 )
V_178 = V_95 ;
if ( ( V_10 -> V_36 ^ V_178 ) &
( V_95 | V_179 ) )
return - V_180 ;
}
}
F_91 ( V_2 , V_44 , V_10 , V_35 , ! V_194 [ V_197 ] ) ;
return 0 ;
}
int F_117 ( struct V_9 * V_10 )
{
struct V_40 * V_63 = F_12 ( V_10 ) ;
struct V_84 * V_50 = & V_63 -> V_49 . V_50 ;
int V_62 ;
V_10 -> V_198 = F_98 ;
V_10 -> V_14 = F_118 ( struct V_13 ) ;
if ( ! V_10 -> V_14 )
return - V_71 ;
V_62 = F_119 ( & V_63 -> V_119 , V_10 ) ;
if ( V_62 ) {
F_100 ( V_10 -> V_14 ) ;
return V_62 ;
}
V_63 -> V_10 = V_10 ;
strcpy ( V_63 -> V_49 . V_64 , V_10 -> V_64 ) ;
V_50 -> V_162 = 4 ;
V_50 -> V_163 = 5 ;
return 0 ;
}
void F_120 ( struct V_9 * V_10 )
{
struct V_59 * V_59 = F_30 ( V_10 ) ;
struct V_40 * V_63 = F_12 ( V_10 ) ;
struct V_1 * V_2 ;
V_2 = F_94 ( V_59 , V_63 -> V_168 ) ;
if ( V_2 -> V_56 != V_10 )
F_16 ( F_12 ( V_10 ) ) ;
}
void F_121 ( struct V_9 * V_10 , int V_199 )
{
struct V_40 * V_63 = F_12 ( V_10 ) ;
V_63 -> V_168 = V_199 ;
}
