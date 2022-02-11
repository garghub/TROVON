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
V_63 -> V_59 = V_59 ;
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
V_90 = F_27 ( V_63 -> V_59 , & V_75 ,
V_63 -> V_49 . V_50 . V_91 ,
V_50 -> V_52 , V_50 -> V_51 ,
V_63 -> V_49 . V_92 ,
F_30 ( V_50 -> V_77 ) ,
V_63 -> V_49 . V_41 ) ;
if ( ! F_31 ( V_90 ) ) {
V_83 = V_90 -> V_93 . V_10 ;
F_32 ( V_90 ) ;
}
if ( V_10 -> type != V_94 )
V_10 -> V_36 |= V_95 ;
}
if ( ! V_83 && V_63 -> V_49 . V_41 )
V_83 = F_33 ( V_63 -> V_59 , V_63 -> V_49 . V_41 ) ;
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
static struct V_40 * F_34 ( struct V_59 * V_59 ,
struct V_1 * V_2 ,
struct V_34 * V_49 )
{
struct V_40 * V_99 , * V_100 ;
struct V_9 * V_10 ;
F_35 ( ! V_2 -> V_56 ) ;
V_100 = F_12 ( V_2 -> V_56 ) ;
V_10 = F_19 ( V_59 , V_2 -> V_56 -> V_60 , V_49 ) ;
if ( F_31 ( V_10 ) )
return NULL ;
V_10 -> V_87 = F_29 ( V_10 ) ;
V_99 = F_12 ( V_10 ) ;
F_14 ( V_2 , V_99 ) ;
return V_99 ;
}
int F_36 ( struct V_40 * V_63 , struct V_101 * V_102 ,
const struct V_103 * V_104 , bool V_105 )
{
struct V_13 * V_14 ;
const struct V_84 * V_50 = F_37 ( V_102 ) ;
int V_62 ;
#ifdef F_38
if ( F_11 ( V_50 -> V_52 ) ) {
if ( F_39 ( F_40 ( V_102 ) ) )
goto V_106;
V_63 -> V_10 -> V_22 . V_21 ++ ;
V_102 -> V_107 = V_108 ;
}
#endif
if ( ( ! ( V_104 -> V_36 & V_109 ) && ( V_63 -> V_49 . V_37 & V_109 ) ) ||
( ( V_104 -> V_36 & V_109 ) && ! ( V_63 -> V_49 . V_37 & V_109 ) ) ) {
V_63 -> V_10 -> V_22 . V_23 ++ ;
V_63 -> V_10 -> V_22 . V_27 ++ ;
goto V_106;
}
if ( V_63 -> V_49 . V_37 & V_110 ) {
if ( ! ( V_104 -> V_36 & V_110 ) ||
( V_63 -> V_111 && ( V_112 ) ( F_41 ( V_104 -> V_113 ) - V_63 -> V_111 ) < 0 ) ) {
V_63 -> V_10 -> V_22 . V_24 ++ ;
V_63 -> V_10 -> V_22 . V_27 ++ ;
goto V_106;
}
V_63 -> V_111 = F_41 ( V_104 -> V_113 ) + 1 ;
}
V_62 = F_42 ( V_50 , V_102 ) ;
if ( F_43 ( V_62 ) ) {
if ( V_105 )
F_44 ( L_2 ,
& V_50 -> V_51 , V_50 -> V_77 ) ;
if ( V_62 > 1 ) {
++ V_63 -> V_10 -> V_22 . V_26 ;
++ V_63 -> V_10 -> V_22 . V_27 ;
goto V_106;
}
}
V_14 = F_45 ( V_63 -> V_10 -> V_14 ) ;
F_46 ( & V_14 -> V_20 ) ;
V_14 -> V_15 ++ ;
V_14 -> V_16 += V_102 -> V_114 ;
F_47 ( & V_14 -> V_20 ) ;
F_48 ( V_102 , ! F_49 ( V_63 -> V_59 , F_50 ( V_63 -> V_10 ) ) ) ;
if ( V_63 -> V_10 -> type == V_94 ) {
V_102 -> V_91 = F_51 ( V_102 , V_63 -> V_10 ) ;
F_52 ( V_102 , F_53 ( V_102 ) , V_115 ) ;
} else {
V_102 -> V_10 = V_63 -> V_10 ;
}
F_54 ( & V_63 -> V_116 , V_102 ) ;
return 0 ;
V_106:
F_55 ( V_102 ) ;
return 0 ;
}
static int F_56 ( struct V_9 * V_10 , struct V_101 * V_102 ,
struct V_73 * V_90 , T_3 V_117 )
{
struct V_40 * V_63 = F_12 ( V_10 ) ;
int V_118 = V_102 -> V_114 - V_63 -> V_85 - V_10 -> V_96 ;
int V_87 ;
if ( V_117 )
V_87 = F_57 ( & V_90 -> V_93 ) - V_10 -> V_96
- sizeof( struct V_84 ) - V_63 -> V_85 ;
else
V_87 = F_58 ( V_102 ) ? F_57 ( F_58 ( V_102 ) ) : V_10 -> V_87 ;
if ( F_58 ( V_102 ) )
F_58 ( V_102 ) -> V_61 -> V_119 ( F_58 ( V_102 ) , NULL , V_102 , V_87 ) ;
if ( V_102 -> V_91 == F_59 ( V_120 ) ) {
if ( ! F_60 ( V_102 ) &&
( V_117 & F_59 ( V_121 ) ) && V_87 < V_118 ) {
memset ( F_61 ( V_102 ) , 0 , sizeof( * F_61 ( V_102 ) ) ) ;
F_62 ( V_102 , V_122 , V_123 , F_63 ( V_87 ) ) ;
return - V_67 ;
}
}
#if F_64 ( V_124 )
else if ( V_102 -> V_91 == F_59 ( V_125 ) ) {
struct V_126 * V_127 = (struct V_126 * ) F_58 ( V_102 ) ;
if ( V_127 && V_87 < F_57 ( F_58 ( V_102 ) ) &&
V_87 >= V_128 ) {
if ( ( V_63 -> V_49 . V_50 . V_52 &&
! F_11 ( V_63 -> V_49 . V_50 . V_52 ) ) ||
V_127 -> V_129 . V_130 == 128 ) {
V_127 -> V_131 |= V_132 ;
F_65 ( F_58 ( V_102 ) , V_133 , V_87 ) ;
}
}
if ( ! F_60 ( V_102 ) && V_87 >= V_128 &&
V_87 < V_118 ) {
F_66 ( V_102 , V_134 , 0 , V_87 ) ;
return - V_67 ;
}
}
#endif
return 0 ;
}
void F_67 ( struct V_101 * V_102 , struct V_9 * V_10 ,
const struct V_84 * V_135 , const T_5 V_91 )
{
struct V_40 * V_63 = F_12 ( V_10 ) ;
const struct V_84 * V_136 ;
struct V_74 V_75 ;
T_5 V_77 , V_137 ;
T_3 V_117 ;
struct V_73 * V_90 ;
unsigned int V_138 ;
T_1 V_93 ;
int V_62 ;
V_136 = ( const struct V_84 * ) F_68 ( V_102 ) ;
V_93 = V_135 -> V_52 ;
if ( V_93 == 0 ) {
if ( F_58 ( V_102 ) == NULL ) {
V_10 -> V_22 . V_28 ++ ;
goto V_139;
}
if ( V_102 -> V_91 == F_59 ( V_120 ) ) {
V_90 = F_40 ( V_102 ) ;
V_93 = F_69 ( V_90 , V_136 -> V_52 ) ;
}
#if F_64 ( V_124 )
else if ( V_102 -> V_91 == F_59 ( V_125 ) ) {
const struct V_140 * V_141 ;
struct V_142 * V_143 ;
bool V_144 ;
int V_145 ;
V_143 = F_70 ( F_58 ( V_102 ) ,
& F_71 ( V_102 ) -> V_52 ) ;
if ( V_143 == NULL )
goto V_139;
V_141 = ( const struct V_140 * ) & V_143 -> V_146 ;
V_145 = F_72 ( V_141 ) ;
if ( V_145 == V_147 ) {
V_141 = & F_71 ( V_102 ) -> V_52 ;
V_145 = F_72 ( V_141 ) ;
}
if ( ( V_145 & V_148 ) == 0 )
V_144 = true ;
else {
V_144 = false ;
V_93 = V_141 -> V_149 [ 3 ] ;
}
F_73 ( V_143 ) ;
if ( V_144 )
goto V_150;
}
#endif
else
goto V_139;
}
V_77 = V_135 -> V_77 ;
if ( V_77 & 0x1 ) {
V_77 &= ~ 0x1 ;
if ( V_102 -> V_91 == F_59 ( V_120 ) )
V_77 = V_136 -> V_77 ;
else if ( V_102 -> V_91 == F_59 ( V_125 ) )
V_77 = F_74 ( ( const struct V_151 * ) V_136 ) ;
}
V_90 = F_27 ( V_63 -> V_59 , & V_75 ,
V_91 ,
V_93 , V_135 -> V_51 ,
V_63 -> V_49 . V_92 ,
F_30 ( V_77 ) ,
V_63 -> V_49 . V_41 ) ;
if ( F_31 ( V_90 ) ) {
V_10 -> V_22 . V_29 ++ ;
goto V_139;
}
if ( V_90 -> V_93 . V_10 == V_10 ) {
F_32 ( V_90 ) ;
V_10 -> V_22 . V_33 ++ ;
goto V_139;
}
if ( F_56 ( V_10 , V_102 , V_90 , V_135 -> V_152 ) ) {
F_32 ( V_90 ) ;
goto V_139;
}
if ( V_63 -> V_153 > 0 ) {
if ( F_75 ( V_154 ,
V_63 -> V_155 + V_156 ) ) {
V_63 -> V_153 -- ;
F_76 ( V_102 ) ;
} else
V_63 -> V_153 = 0 ;
}
V_77 = F_77 ( V_77 , V_136 , V_102 ) ;
V_137 = V_135 -> V_137 ;
if ( V_137 == 0 ) {
if ( V_102 -> V_91 == F_59 ( V_120 ) )
V_137 = V_136 -> V_137 ;
#if F_64 ( V_124 )
else if ( V_102 -> V_91 == F_59 ( V_125 ) )
V_137 = ( ( const struct V_151 * ) V_136 ) -> V_157 ;
#endif
else
V_137 = F_78 ( & V_90 -> V_93 ) ;
}
V_117 = V_135 -> V_152 ;
if ( V_102 -> V_91 == F_59 ( V_120 ) )
V_117 |= ( V_136 -> V_152 & F_59 ( V_121 ) ) ;
V_138 = F_79 ( V_90 -> V_93 . V_10 ) + sizeof( struct V_84 )
+ V_90 -> V_93 . V_158 ;
if ( V_138 > V_10 -> V_97 )
V_10 -> V_97 = V_138 ;
if ( F_80 ( V_102 , V_10 -> V_97 ) ) {
V_10 -> V_22 . V_30 ++ ;
F_81 ( V_102 ) ;
return;
}
V_62 = F_82 ( V_90 , V_102 , V_75 . V_51 , V_75 . V_52 , V_91 ,
V_77 , V_137 , V_117 , ! F_49 ( V_63 -> V_59 , F_50 ( V_10 ) ) ) ;
F_83 ( V_62 , & V_10 -> V_22 , V_10 -> V_14 ) ;
return;
#if F_64 ( V_124 )
V_150:
F_76 ( V_102 ) ;
#endif
V_139:
V_10 -> V_22 . V_32 ++ ;
F_81 ( V_102 ) ;
}
static void F_84 ( struct V_1 * V_2 ,
struct V_40 * V_44 ,
struct V_9 * V_10 ,
struct V_34 * V_35 ,
bool V_159 )
{
F_16 ( V_44 ) ;
V_44 -> V_49 . V_50 . V_51 = V_35 -> V_50 . V_51 ;
V_44 -> V_49 . V_50 . V_52 = V_35 -> V_50 . V_52 ;
V_44 -> V_49 . V_39 = V_35 -> V_39 ;
V_44 -> V_49 . V_92 = V_35 -> V_92 ;
if ( V_10 -> type != V_94 ) {
memcpy ( V_10 -> V_160 , & V_35 -> V_50 . V_51 , 4 ) ;
memcpy ( V_10 -> V_161 , & V_35 -> V_50 . V_52 , 4 ) ;
}
F_14 ( V_2 , V_44 ) ;
V_44 -> V_49 . V_50 . V_137 = V_35 -> V_50 . V_137 ;
V_44 -> V_49 . V_50 . V_77 = V_35 -> V_50 . V_77 ;
V_44 -> V_49 . V_50 . V_152 = V_35 -> V_50 . V_152 ;
if ( V_44 -> V_49 . V_41 != V_35 -> V_41 ) {
int V_87 ;
V_44 -> V_49 . V_41 = V_35 -> V_41 ;
V_87 = F_29 ( V_10 ) ;
if ( V_159 )
V_10 -> V_87 = V_87 ;
}
F_85 ( V_10 ) ;
}
int F_86 ( struct V_9 * V_10 , struct V_34 * V_35 , int V_162 )
{
int V_62 = 0 ;
struct V_40 * V_44 ;
struct V_59 * V_59 = F_50 ( V_10 ) ;
struct V_40 * V_63 = F_12 ( V_10 ) ;
struct V_1 * V_2 = F_87 ( V_59 , V_63 -> V_163 ) ;
F_35 ( ! V_2 -> V_56 ) ;
switch ( V_162 ) {
case V_164 :
V_44 = NULL ;
if ( V_10 == V_2 -> V_56 )
V_44 = F_18 ( V_2 , V_35 , V_2 -> V_56 -> type ) ;
if ( V_44 == NULL )
V_44 = F_12 ( V_10 ) ;
memcpy ( V_35 , & V_44 -> V_49 , sizeof( * V_35 ) ) ;
break;
case V_165 :
case V_166 :
V_62 = - V_167 ;
if ( ! F_88 ( V_59 -> V_168 , V_169 ) )
goto V_170;
if ( V_35 -> V_50 . V_137 )
V_35 -> V_50 . V_152 |= F_59 ( V_121 ) ;
if ( ! ( V_35 -> V_37 & V_38 ) )
V_35 -> V_39 = 0 ;
if ( ! ( V_35 -> V_171 & V_38 ) )
V_35 -> V_92 = 0 ;
V_44 = F_18 ( V_2 , V_35 , V_2 -> V_56 -> type ) ;
if ( ! V_44 && ( V_162 == V_165 ) )
V_44 = F_34 ( V_59 , V_2 , V_35 ) ;
if ( V_10 != V_2 -> V_56 && V_162 == V_166 ) {
if ( V_44 != NULL ) {
if ( V_44 -> V_10 != V_10 ) {
V_62 = - V_172 ;
break;
}
} else {
unsigned int V_173 = 0 ;
if ( F_11 ( V_35 -> V_50 . V_52 ) )
V_173 = V_174 ;
else if ( V_35 -> V_50 . V_52 )
V_173 = V_95 ;
if ( ( V_10 -> V_36 ^ V_173 ) & ( V_95 | V_174 ) ) {
V_62 = - V_175 ;
break;
}
V_44 = F_12 ( V_10 ) ;
}
}
if ( V_44 ) {
V_62 = 0 ;
F_84 ( V_2 , V_44 , V_10 , V_35 , true ) ;
} else
V_62 = ( V_162 == V_165 ? - V_176 : - V_177 ) ;
break;
case V_178 :
V_62 = - V_167 ;
if ( ! F_88 ( V_59 -> V_168 , V_169 ) )
goto V_170;
if ( V_10 == V_2 -> V_56 ) {
V_62 = - V_177 ;
V_44 = F_18 ( V_2 , V_35 , V_2 -> V_56 -> type ) ;
if ( V_44 == NULL )
goto V_170;
V_62 = - V_167 ;
if ( V_44 == F_12 ( V_2 -> V_56 ) )
goto V_170;
V_10 = V_44 -> V_10 ;
}
F_89 ( V_10 ) ;
V_62 = 0 ;
break;
default:
V_62 = - V_175 ;
}
V_170:
return V_62 ;
}
int F_90 ( struct V_9 * V_10 , int V_179 )
{
struct V_40 * V_63 = F_12 ( V_10 ) ;
int V_89 = V_63 -> V_85 + sizeof( struct V_84 ) ;
if ( V_179 < 68 ||
V_179 > 0xFFF8 - V_10 -> V_96 - V_89 )
return - V_175 ;
V_10 -> V_87 = V_179 ;
return 0 ;
}
static void F_91 ( struct V_9 * V_10 )
{
struct V_40 * V_63 = F_12 ( V_10 ) ;
F_92 ( & V_63 -> V_116 ) ;
F_93 ( V_10 -> V_14 ) ;
F_25 ( V_10 ) ;
}
void F_94 ( struct V_9 * V_10 , struct V_180 * V_47 )
{
struct V_40 * V_63 = F_12 ( V_10 ) ;
struct V_1 * V_2 ;
V_2 = F_87 ( V_63 -> V_59 , V_63 -> V_163 ) ;
if ( V_2 -> V_56 != V_10 ) {
F_16 ( F_12 ( V_10 ) ) ;
F_95 ( V_10 , V_47 ) ;
}
}
int F_96 ( struct V_59 * V_59 , int V_163 ,
struct V_60 * V_61 , char * V_181 )
{
struct V_1 * V_2 = F_87 ( V_59 , V_163 ) ;
struct V_34 V_49 ;
unsigned int V_12 ;
for ( V_12 = 0 ; V_12 < V_182 ; V_12 ++ )
F_97 ( & V_2 -> V_48 [ V_12 ] ) ;
if ( ! V_61 ) {
V_2 -> V_56 = NULL ;
return 0 ;
}
memset ( & V_49 , 0 , sizeof( V_49 ) ) ;
if ( V_181 )
F_20 ( V_49 . V_64 , V_181 , V_65 ) ;
F_98 () ;
V_2 -> V_56 = F_19 ( V_59 , V_61 , & V_49 ) ;
if ( ! F_31 ( V_2 -> V_56 ) ) {
V_2 -> V_56 -> V_183 |= V_184 ;
F_14 ( V_2 , F_12 ( V_2 -> V_56 ) ) ;
}
F_99 () ;
return F_100 ( V_2 -> V_56 ) ;
}
static void F_101 ( struct V_1 * V_2 , struct V_180 * V_47 ,
struct V_60 * V_61 )
{
struct V_59 * V_59 = F_50 ( V_2 -> V_56 ) ;
struct V_9 * V_10 , * V_185 ;
int V_57 ;
F_102 (net, dev, aux)
if ( V_10 -> V_60 == V_61 )
F_95 ( V_10 , V_47 ) ;
for ( V_57 = 0 ; V_57 < V_182 ; V_57 ++ ) {
struct V_40 * V_44 ;
struct V_186 * V_187 ;
struct V_46 * V_188 = & V_2 -> V_48 [ V_57 ] ;
F_103 (t, n, thead, hash_node)
if ( ! F_49 ( F_50 ( V_44 -> V_10 ) , V_59 ) )
F_95 ( V_44 -> V_10 , V_47 ) ;
}
}
void F_104 ( struct V_1 * V_2 , struct V_60 * V_61 )
{
F_105 ( V_189 ) ;
F_98 () ;
F_101 ( V_2 , & V_189 , V_61 ) ;
F_106 ( & V_189 ) ;
F_99 () ;
}
int F_107 ( struct V_9 * V_10 , struct V_190 * V_191 [] ,
struct V_34 * V_35 )
{
struct V_40 * V_99 ;
struct V_59 * V_59 = F_50 ( V_10 ) ;
struct V_1 * V_2 ;
int V_87 ;
int V_62 ;
V_99 = F_12 ( V_10 ) ;
V_2 = F_87 ( V_59 , V_99 -> V_163 ) ;
if ( F_18 ( V_2 , V_35 , V_10 -> type ) )
return - V_172 ;
V_99 -> V_59 = V_59 ;
V_99 -> V_49 = * V_35 ;
V_62 = F_24 ( V_10 ) ;
if ( V_62 )
goto V_192;
if ( V_10 -> type == V_94 && ! V_191 [ V_193 ] )
F_108 ( V_10 ) ;
V_87 = F_29 ( V_10 ) ;
if ( ! V_191 [ V_194 ] )
V_10 -> V_87 = V_87 ;
F_14 ( V_2 , V_99 ) ;
V_192:
return V_62 ;
}
int F_109 ( struct V_9 * V_10 , struct V_190 * V_191 [] ,
struct V_34 * V_35 )
{
struct V_40 * V_44 ;
struct V_40 * V_63 = F_12 ( V_10 ) ;
struct V_59 * V_59 = V_63 -> V_59 ;
struct V_1 * V_2 = F_87 ( V_59 , V_63 -> V_163 ) ;
if ( V_10 == V_2 -> V_56 )
return - V_175 ;
V_44 = F_18 ( V_2 , V_35 , V_10 -> type ) ;
if ( V_44 ) {
if ( V_44 -> V_10 != V_10 )
return - V_172 ;
} else {
V_44 = V_63 ;
if ( V_10 -> type != V_94 ) {
unsigned int V_173 = 0 ;
if ( F_11 ( V_35 -> V_50 . V_52 ) )
V_173 = V_174 ;
else if ( V_35 -> V_50 . V_52 )
V_173 = V_95 ;
if ( ( V_10 -> V_36 ^ V_173 ) &
( V_95 | V_174 ) )
return - V_175 ;
}
}
F_84 ( V_2 , V_44 , V_10 , V_35 , ! V_191 [ V_194 ] ) ;
return 0 ;
}
int F_110 ( struct V_9 * V_10 )
{
struct V_40 * V_63 = F_12 ( V_10 ) ;
struct V_84 * V_50 = & V_63 -> V_49 . V_50 ;
int V_12 , V_62 ;
V_10 -> V_195 = F_91 ;
V_10 -> V_14 = F_111 ( struct V_13 ) ;
if ( ! V_10 -> V_14 )
return - V_71 ;
F_4 (i) {
struct V_13 * V_196 ;
V_196 = F_5 ( V_10 -> V_14 , V_12 ) ;
F_112 ( & V_196 -> V_20 ) ;
}
V_62 = F_113 ( & V_63 -> V_116 , V_10 ) ;
if ( V_62 ) {
F_93 ( V_10 -> V_14 ) ;
return V_62 ;
}
V_63 -> V_10 = V_10 ;
V_63 -> V_59 = F_50 ( V_10 ) ;
strcpy ( V_63 -> V_49 . V_64 , V_10 -> V_64 ) ;
V_50 -> V_197 = 4 ;
V_50 -> V_198 = 5 ;
return 0 ;
}
void F_114 ( struct V_9 * V_10 )
{
struct V_40 * V_63 = F_12 ( V_10 ) ;
struct V_59 * V_59 = V_63 -> V_59 ;
struct V_1 * V_2 ;
V_2 = F_87 ( V_59 , V_63 -> V_163 ) ;
if ( V_2 -> V_56 != V_10 )
F_16 ( F_12 ( V_10 ) ) ;
}
void F_115 ( struct V_9 * V_10 , int V_199 )
{
struct V_40 * V_63 = F_12 ( V_10 ) ;
V_63 -> V_163 = V_199 ;
}
